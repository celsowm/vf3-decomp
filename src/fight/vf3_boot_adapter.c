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
int vf3_boot_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c004000u: goto P_0c004000;
case 0x0c004002u: goto P_0c004002;
case 0x0c004004u: goto P_0c004004;
case 0x0c004006u: goto P_0c004006;
case 0x0c004008u: goto P_0c004008;
case 0x0c00400au: goto P_0c00400a;
case 0x0c00400cu: goto P_0c00400c;
case 0x0c00400eu: goto P_0c00400e;
case 0x0c004010u: goto P_0c004010;
case 0x0c004012u: goto P_0c004012;
case 0x0c004014u: goto P_0c004014;
case 0x0c004016u: goto P_0c004016;
case 0x0c004018u: goto P_0c004018;
case 0x0c00401au: goto P_0c00401a;
case 0x0c00401cu: goto P_0c00401c;
case 0x0c00401eu: goto P_0c00401e;
case 0x0c004020u: goto P_0c004020;
case 0x0c004022u: goto P_0c004022;
case 0x0c004024u: goto P_0c004024;
case 0x0c004026u: goto P_0c004026;
case 0x0c004028u: goto P_0c004028;
case 0x0c00402au: goto P_0c00402a;
case 0x0c00402cu: goto P_0c00402c;
case 0x0c00402eu: goto P_0c00402e;
case 0x0c004030u: goto P_0c004030;
case 0x0c004032u: goto P_0c004032;
case 0x0c004070u: goto P_0c004070;
case 0x0c004072u: goto P_0c004072;
case 0x0c004074u: goto P_0c004074;
case 0x0c004076u: goto P_0c004076;
case 0x0c004078u: goto P_0c004078;
case 0x0c00407au: goto P_0c00407a;
case 0x0c00407cu: goto P_0c00407c;
case 0x0c00407eu: goto P_0c00407e;
case 0x0c004080u: goto P_0c004080;
case 0x0c004082u: goto P_0c004082;
case 0x0c004084u: goto P_0c004084;
case 0x0c004086u: goto P_0c004086;
case 0x0c004088u: goto P_0c004088;
case 0x0c00408au: goto P_0c00408a;
case 0x0c00408cu: goto P_0c00408c;
case 0x0c00408eu: goto P_0c00408e;
case 0x0c004090u: goto P_0c004090;
case 0x0c004092u: goto P_0c004092;
case 0x0c004094u: goto P_0c004094;
case 0x0c004096u: goto P_0c004096;
case 0x0c004098u: goto P_0c004098;
case 0x0c00409au: goto P_0c00409a;
case 0x0c00409cu: goto P_0c00409c;
case 0x0c00409eu: goto P_0c00409e;
case 0x0c0040a0u: goto P_0c0040a0;
case 0x0c0040a2u: goto P_0c0040a2;
case 0x0c0040a4u: goto P_0c0040a4;
case 0x0c0040a6u: goto P_0c0040a6;
case 0x0c0040a8u: goto P_0c0040a8;
case 0x0c0040aau: goto P_0c0040aa;
case 0x0c0040acu: goto P_0c0040ac;
case 0x0c0040aeu: goto P_0c0040ae;
case 0x0c0040b0u: goto P_0c0040b0;
case 0x0c0040b2u: goto P_0c0040b2;
case 0x0c0040b4u: goto P_0c0040b4;
case 0x0c0040b6u: goto P_0c0040b6;
case 0x0c0040b8u: goto P_0c0040b8;
case 0x0c0040bau: goto P_0c0040ba;
case 0x0c0040bcu: goto P_0c0040bc;
case 0x0c0040beu: goto P_0c0040be;
case 0x0c0040c0u: goto P_0c0040c0;
case 0x0c0040c2u: goto P_0c0040c2;
case 0x0c0040c4u: goto P_0c0040c4;
case 0x0c0040c6u: goto P_0c0040c6;
case 0x0c0040c8u: goto P_0c0040c8;
case 0x0c0040cau: goto P_0c0040ca;
case 0x0c0040ccu: goto P_0c0040cc;
case 0x0c0040ceu: goto P_0c0040ce;
case 0x0c0040d0u: goto P_0c0040d0;
case 0x0c0040d2u: goto P_0c0040d2;
case 0x0c0040d4u: goto P_0c0040d4;
case 0x0c0040d6u: goto P_0c0040d6;
case 0x0c0040d8u: goto P_0c0040d8;
case 0x0c0040dau: goto P_0c0040da;
case 0x0c0040dcu: goto P_0c0040dc;
case 0x0c0040deu: goto P_0c0040de;
case 0x0c0040e0u: goto P_0c0040e0;
case 0x0c0040e2u: goto P_0c0040e2;
case 0x0c0040e4u: goto P_0c0040e4;
case 0x0c0040e6u: goto P_0c0040e6;
case 0x0c004138u: goto P_0c004138;
case 0x0c00413au: goto P_0c00413a;
case 0x0c00413cu: goto P_0c00413c;
case 0x0c00413eu: goto P_0c00413e;
case 0x0c004140u: goto P_0c004140;
case 0x0c004142u: goto P_0c004142;
case 0x0c004144u: goto P_0c004144;
case 0x0c004146u: goto P_0c004146;
case 0x0c004148u: goto P_0c004148;
case 0x0c00414au: goto P_0c00414a;
case 0x0c00414cu: goto P_0c00414c;
case 0x0c00414eu: goto P_0c00414e;
case 0x0c004150u: goto P_0c004150;
case 0x0c004152u: goto P_0c004152;
case 0x0c004154u: goto P_0c004154;
case 0x0c004156u: goto P_0c004156;
case 0x0c004158u: goto P_0c004158;
case 0x0c00415au: goto P_0c00415a;
case 0x0c00415cu: goto P_0c00415c;
case 0x0c00415eu: goto P_0c00415e;
case 0x0c004160u: goto P_0c004160;
case 0x0c004162u: goto P_0c004162;
case 0x0c004164u: goto P_0c004164;
case 0x0c004166u: goto P_0c004166;
case 0x0c004168u: goto P_0c004168;
case 0x0c00416au: goto P_0c00416a;
case 0x0c00416cu: goto P_0c00416c;
case 0x0c00416eu: goto P_0c00416e;
case 0x0c004170u: goto P_0c004170;
case 0x0c004172u: goto P_0c004172;
case 0x0c004174u: goto P_0c004174;
case 0x0c004176u: goto P_0c004176;
case 0x0c004178u: goto P_0c004178;
case 0x0c00417au: goto P_0c00417a;
case 0x0c00417cu: goto P_0c00417c;
case 0x0c00417eu: goto P_0c00417e;
case 0x0c004180u: goto P_0c004180;
case 0x0c004182u: goto P_0c004182;
case 0x0c004184u: goto P_0c004184;
case 0x0c004186u: goto P_0c004186;
case 0x0c004188u: goto P_0c004188;
case 0x0c00418au: goto P_0c00418a;
case 0x0c00418cu: goto P_0c00418c;
case 0x0c00418eu: goto P_0c00418e;
case 0x0c004190u: goto P_0c004190;
case 0x0c004192u: goto P_0c004192;
case 0x0c004194u: goto P_0c004194;
case 0x0c004196u: goto P_0c004196;
case 0x0c004198u: goto P_0c004198;
case 0x0c00419au: goto P_0c00419a;
case 0x0c00419cu: goto P_0c00419c;
case 0x0c00419eu: goto P_0c00419e;
case 0x0c0041a0u: goto P_0c0041a0;
case 0x0c0041a2u: goto P_0c0041a2;
case 0x0c0041a4u: goto P_0c0041a4;
case 0x0c0041a6u: goto P_0c0041a6;
case 0x0c0041a8u: goto P_0c0041a8;
case 0x0c0041aau: goto P_0c0041aa;
case 0x0c0041acu: goto P_0c0041ac;
case 0x0c0041aeu: goto P_0c0041ae;
case 0x0c0041b0u: goto P_0c0041b0;
case 0x0c0041b2u: goto P_0c0041b2;
case 0x0c0041b4u: goto P_0c0041b4;
case 0x0c0041b6u: goto P_0c0041b6;
case 0x0c0041b8u: goto P_0c0041b8;
case 0x0c0041bau: goto P_0c0041ba;
case 0x0c0041bcu: goto P_0c0041bc;
case 0x0c0041beu: goto P_0c0041be;
case 0x0c0041c0u: goto P_0c0041c0;
case 0x0c0041c2u: goto P_0c0041c2;
case 0x0c0041c4u: goto P_0c0041c4;
case 0x0c0041c6u: goto P_0c0041c6;
case 0x0c0041c8u: goto P_0c0041c8;
case 0x0c0041cau: goto P_0c0041ca;
case 0x0c0041ccu: goto P_0c0041cc;
case 0x0c0041ceu: goto P_0c0041ce;
case 0x0c0041d0u: goto P_0c0041d0;
case 0x0c0041d2u: goto P_0c0041d2;
case 0x0c0041d4u: goto P_0c0041d4;
case 0x0c0041d6u: goto P_0c0041d6;
case 0x0c0041d8u: goto P_0c0041d8;
case 0x0c0041dau: goto P_0c0041da;
case 0x0c0041dcu: goto P_0c0041dc;
case 0x0c0041deu: goto P_0c0041de;
case 0x0c0041e0u: goto P_0c0041e0;
case 0x0c0041e2u: goto P_0c0041e2;
case 0x0c0041e4u: goto P_0c0041e4;
case 0x0c0041e6u: goto P_0c0041e6;
case 0x0c0041e8u: goto P_0c0041e8;
case 0x0c0041eau: goto P_0c0041ea;
case 0x0c0041ecu: goto P_0c0041ec;
case 0x0c0041eeu: goto P_0c0041ee;
case 0x0c0041f0u: goto P_0c0041f0;
case 0x0c0041f2u: goto P_0c0041f2;
case 0x0c0041f4u: goto P_0c0041f4;
case 0x0c0041f6u: goto P_0c0041f6;
case 0x0c0041f8u: goto P_0c0041f8;
case 0x0c0041fau: goto P_0c0041fa;
case 0x0c0041fcu: goto P_0c0041fc;
case 0x0c0041feu: goto P_0c0041fe;
case 0x0c004200u: goto P_0c004200;
case 0x0c004202u: goto P_0c004202;
case 0x0c004204u: goto P_0c004204;
case 0x0c004206u: goto P_0c004206;
case 0x0c004208u: goto P_0c004208;
case 0x0c00420au: goto P_0c00420a;
case 0x0c00420cu: goto P_0c00420c;
case 0x0c00420eu: goto P_0c00420e;
case 0x0c004210u: goto P_0c004210;
case 0x0c004212u: goto P_0c004212;
case 0x0c004214u: goto P_0c004214;
case 0x0c004216u: goto P_0c004216;
case 0x0c004218u: goto P_0c004218;
case 0x0c00421au: goto P_0c00421a;
case 0x0c00421cu: goto P_0c00421c;
case 0x0c00421eu: goto P_0c00421e;
case 0x0c004220u: goto P_0c004220;
case 0x0c004222u: goto P_0c004222;
case 0x0c004224u: goto P_0c004224;
case 0x0c004226u: goto P_0c004226;
case 0x0c004228u: goto P_0c004228;
case 0x0c00422au: goto P_0c00422a;
case 0x0c004268u: goto P_0c004268;
case 0x0c00426au: goto P_0c00426a;
case 0x0c00426cu: goto P_0c00426c;
case 0x0c00426eu: goto P_0c00426e;
case 0x0c004270u: goto P_0c004270;
case 0x0c004272u: goto P_0c004272;
case 0x0c004274u: goto P_0c004274;
case 0x0c004276u: goto P_0c004276;
case 0x0c004278u: goto P_0c004278;
case 0x0c00427au: goto P_0c00427a;
case 0x0c00427cu: goto P_0c00427c;
case 0x0c00427eu: goto P_0c00427e;
case 0x0c004280u: goto P_0c004280;
case 0x0c004282u: goto P_0c004282;
case 0x0c004284u: goto P_0c004284;
case 0x0c004286u: goto P_0c004286;
case 0x0c004288u: goto P_0c004288;
case 0x0c00428au: goto P_0c00428a;
case 0x0c00428cu: goto P_0c00428c;
case 0x0c00428eu: goto P_0c00428e;
case 0x0c004290u: goto P_0c004290;
case 0x0c004292u: goto P_0c004292;
case 0x0c004294u: goto P_0c004294;
case 0x0c004296u: goto P_0c004296;
case 0x0c004298u: goto P_0c004298;
case 0x0c00429au: goto P_0c00429a;
case 0x0c00429cu: goto P_0c00429c;
case 0x0c00429eu: goto P_0c00429e;
case 0x0c0042a0u: goto P_0c0042a0;
case 0x0c0042a2u: goto P_0c0042a2;
case 0x0c0042a4u: goto P_0c0042a4;
case 0x0c0042a6u: goto P_0c0042a6;
case 0x0c0042a8u: goto P_0c0042a8;
case 0x0c0044d4u: goto P_0c0044d4;
case 0x0c0044d6u: goto P_0c0044d6;
case 0x0c0044d8u: goto P_0c0044d8;
case 0x0c0044dau: goto P_0c0044da;
case 0x0c0044dcu: goto P_0c0044dc;
case 0x0c0044deu: goto P_0c0044de;
case 0x0c0044e0u: goto P_0c0044e0;
case 0x0c0044e2u: goto P_0c0044e2;
case 0x0c0044e4u: goto P_0c0044e4;
case 0x0c0044e6u: goto P_0c0044e6;
case 0x0c0044e8u: goto P_0c0044e8;
case 0x0c0044eau: goto P_0c0044ea;
case 0x0c0044ecu: goto P_0c0044ec;
case 0x0c0044eeu: goto P_0c0044ee;
case 0x0c0044f0u: goto P_0c0044f0;
case 0x0c0044f2u: goto P_0c0044f2;
case 0x0c0044f4u: goto P_0c0044f4;
case 0x0c0044f6u: goto P_0c0044f6;
case 0x0c0044f8u: goto P_0c0044f8;
case 0x0c0044fau: goto P_0c0044fa;
case 0x0c0044fcu: goto P_0c0044fc;
case 0x0c0044feu: goto P_0c0044fe;
case 0x0c004500u: goto P_0c004500;
case 0x0c004502u: goto P_0c004502;
case 0x0c004504u: goto P_0c004504;
case 0x0c004506u: goto P_0c004506;
case 0x0c004508u: goto P_0c004508;
case 0x0c00450au: goto P_0c00450a;
case 0x0c00450cu: goto P_0c00450c;
case 0x0c00450eu: goto P_0c00450e;
case 0x0c004510u: goto P_0c004510;
case 0x0c004512u: goto P_0c004512;
case 0x0c004514u: goto P_0c004514;
case 0x0c004516u: goto P_0c004516;
case 0x0c004518u: goto P_0c004518;
case 0x0c00451au: goto P_0c00451a;
case 0x0c00451cu: goto P_0c00451c;
case 0x0c00451eu: goto P_0c00451e;
case 0x0c004520u: goto P_0c004520;
case 0x0c004522u: goto P_0c004522;
case 0x0c004524u: goto P_0c004524;
case 0x0c004526u: goto P_0c004526;
case 0x0c004528u: goto P_0c004528;
case 0x0c00452au: goto P_0c00452a;
case 0x0c00452cu: goto P_0c00452c;
case 0x0c00452eu: goto P_0c00452e;
case 0x0c004530u: goto P_0c004530;
case 0x0c004532u: goto P_0c004532;
case 0x0c004534u: goto P_0c004534;
case 0x0c004536u: goto P_0c004536;
case 0x0c004538u: goto P_0c004538;
case 0x0c00453au: goto P_0c00453a;
case 0x0c00453cu: goto P_0c00453c;
case 0x0c00453eu: goto P_0c00453e;
case 0x0c004540u: goto P_0c004540;
case 0x0c004542u: goto P_0c004542;
case 0x0c004544u: goto P_0c004544;
case 0x0c004546u: goto P_0c004546;
case 0x0c004548u: goto P_0c004548;
case 0x0c00454au: goto P_0c00454a;
case 0x0c00454cu: goto P_0c00454c;
case 0x0c00454eu: goto P_0c00454e;
case 0x0c004550u: goto P_0c004550;
case 0x0c004552u: goto P_0c004552;
case 0x0c004554u: goto P_0c004554;
case 0x0c004556u: goto P_0c004556;
case 0x0c004558u: goto P_0c004558;
case 0x0c00455au: goto P_0c00455a;
case 0x0c00455cu: goto P_0c00455c;
case 0x0c00455eu: goto P_0c00455e;
case 0x0c004560u: goto P_0c004560;
case 0x0c004562u: goto P_0c004562;
case 0x0c004564u: goto P_0c004564;
case 0x0c004566u: goto P_0c004566;
case 0x0c004568u: goto P_0c004568;
case 0x0c00456au: goto P_0c00456a;
case 0x0c00456cu: goto P_0c00456c;
case 0x0c00456eu: goto P_0c00456e;
case 0x0c004570u: goto P_0c004570;
case 0x0c004572u: goto P_0c004572;
case 0x0c004574u: goto P_0c004574;
case 0x0c004576u: goto P_0c004576;
case 0x0c004578u: goto P_0c004578;
case 0x0c00457au: goto P_0c00457a;
case 0x0c00457cu: goto P_0c00457c;
case 0x0c00457eu: goto P_0c00457e;
case 0x0c004580u: goto P_0c004580;
case 0x0c00479au: goto P_0c00479a;
case 0x0c00479cu: goto P_0c00479c;
case 0x0c00479eu: goto P_0c00479e;
case 0x0c0047a0u: goto P_0c0047a0;
case 0x0c0047a2u: goto P_0c0047a2;
case 0x0c0047a4u: goto P_0c0047a4;
case 0x0c0047a6u: goto P_0c0047a6;
case 0x0c0047a8u: goto P_0c0047a8;
case 0x0c0047aau: goto P_0c0047aa;
case 0x0c0047acu: goto P_0c0047ac;
case 0x0c0047aeu: goto P_0c0047ae;
case 0x0c0047b0u: goto P_0c0047b0;
case 0x0c0047b2u: goto P_0c0047b2;
case 0x0c0047b4u: goto P_0c0047b4;
case 0x0c0047b6u: goto P_0c0047b6;
case 0x0c0047b8u: goto P_0c0047b8;
case 0x0c0047bau: goto P_0c0047ba;
case 0x0c0047bcu: goto P_0c0047bc;
case 0x0c0047beu: goto P_0c0047be;
case 0x0c0047c0u: goto P_0c0047c0;
case 0x0c0047c2u: goto P_0c0047c2;
case 0x0c0047c4u: goto P_0c0047c4;
case 0x0c0047c6u: goto P_0c0047c6;
case 0x0c0047c8u: goto P_0c0047c8;
case 0x0c0047cau: goto P_0c0047ca;
case 0x0c0047ccu: goto P_0c0047cc;
case 0x0c0047ceu: goto P_0c0047ce;
case 0x0c0047d0u: goto P_0c0047d0;
case 0x0c0047d2u: goto P_0c0047d2;
case 0x0c0047d4u: goto P_0c0047d4;
case 0x0c0047d6u: goto P_0c0047d6;
case 0x0c0047d8u: goto P_0c0047d8;
case 0x0c0047dau: goto P_0c0047da;
case 0x0c0047dcu: goto P_0c0047dc;
case 0x0c0047deu: goto P_0c0047de;
case 0x0c0047e0u: goto P_0c0047e0;
case 0x0c0047e2u: goto P_0c0047e2;
case 0x0c0047e4u: goto P_0c0047e4;
case 0x0c0047e6u: goto P_0c0047e6;
case 0x0c0047e8u: goto P_0c0047e8;
case 0x0c0048f6u: goto P_0c0048f6;
case 0x0c0048f8u: goto P_0c0048f8;
case 0x0c0048fau: goto P_0c0048fa;
case 0x0c0048fcu: goto P_0c0048fc;
case 0x0c0048feu: goto P_0c0048fe;
case 0x0c004900u: goto P_0c004900;
case 0x0c004902u: goto P_0c004902;
case 0x0c004904u: goto P_0c004904;
case 0x0c004906u: goto P_0c004906;
case 0x0c004908u: goto P_0c004908;
case 0x0c00490au: goto P_0c00490a;
case 0x0c00490cu: goto P_0c00490c;
case 0x0c00490eu: goto P_0c00490e;
case 0x0c004910u: goto P_0c004910;
case 0x0c004912u: goto P_0c004912;
case 0x0c004914u: goto P_0c004914;
case 0x0c004916u: goto P_0c004916;
case 0x0c004918u: goto P_0c004918;
case 0x0c00491au: goto P_0c00491a;
case 0x0c00491cu: goto P_0c00491c;
case 0x0c00491eu: goto P_0c00491e;
case 0x0c004920u: goto P_0c004920;
case 0x0c004922u: goto P_0c004922;
case 0x0c004924u: goto P_0c004924;
case 0x0c004926u: goto P_0c004926;
case 0x0c004928u: goto P_0c004928;
case 0x0c00492au: goto P_0c00492a;
case 0x0c00492cu: goto P_0c00492c;
case 0x0c00492eu: goto P_0c00492e;
case 0x0c004930u: goto P_0c004930;
case 0x0c004932u: goto P_0c004932;
case 0x0c004934u: goto P_0c004934;
case 0x0c004936u: goto P_0c004936;
case 0x0c004938u: goto P_0c004938;
case 0x0c004988u: goto P_0c004988;
case 0x0c00498au: goto P_0c00498a;
case 0x0c00498cu: goto P_0c00498c;
case 0x0c00498eu: goto P_0c00498e;
case 0x0c004990u: goto P_0c004990;
case 0x0c004992u: goto P_0c004992;
case 0x0c004994u: goto P_0c004994;
case 0x0c004996u: goto P_0c004996;
case 0x0c004998u: goto P_0c004998;
case 0x0c00499au: goto P_0c00499a;
case 0x0c00499cu: goto P_0c00499c;
case 0x0c00499eu: goto P_0c00499e;
case 0x0c0049a0u: goto P_0c0049a0;
case 0x0c0049a2u: goto P_0c0049a2;
case 0x0c0049a4u: goto P_0c0049a4;
case 0x0c0049a6u: goto P_0c0049a6;
case 0x0c0049a8u: goto P_0c0049a8;
case 0x0c0049aau: goto P_0c0049aa;
case 0x0c0049acu: goto P_0c0049ac;
case 0x0c0049aeu: goto P_0c0049ae;
case 0x0c0049b0u: goto P_0c0049b0;
case 0x0c0049b2u: goto P_0c0049b2;
case 0x0c0049b4u: goto P_0c0049b4;
case 0x0c0049b6u: goto P_0c0049b6;
case 0x0c0049b8u: goto P_0c0049b8;
case 0x0c0049bau: goto P_0c0049ba;
case 0x0c0049bcu: goto P_0c0049bc;
case 0x0c0049beu: goto P_0c0049be;
case 0x0c0049c0u: goto P_0c0049c0;
case 0x0c0049c2u: goto P_0c0049c2;
case 0x0c0049c4u: goto P_0c0049c4;
case 0x0c0049c6u: goto P_0c0049c6;
case 0x0c0049c8u: goto P_0c0049c8;
case 0x0c0049cau: goto P_0c0049ca;
case 0x0c0049ccu: goto P_0c0049cc;
case 0x0c0049ceu: goto P_0c0049ce;
case 0x0c0049d0u: goto P_0c0049d0;
case 0x0c0049d2u: goto P_0c0049d2;
case 0x0c0049d4u: goto P_0c0049d4;
case 0x0c0049d6u: goto P_0c0049d6;
case 0x0c0049d8u: goto P_0c0049d8;
case 0x0c0049dau: goto P_0c0049da;
case 0x0c0049dcu: goto P_0c0049dc;
case 0x0c0049deu: goto P_0c0049de;
case 0x0c0049e0u: goto P_0c0049e0;
case 0x0c0049e2u: goto P_0c0049e2;
case 0x0c0049e4u: goto P_0c0049e4;
case 0x0c0049e6u: goto P_0c0049e6;
case 0x0c0049e8u: goto P_0c0049e8;
case 0x0c0049eau: goto P_0c0049ea;
case 0x0c0049ecu: goto P_0c0049ec;
case 0x0c0049eeu: goto P_0c0049ee;
case 0x0c0049f0u: goto P_0c0049f0;
case 0x0c0049f2u: goto P_0c0049f2;
case 0x0c0049f4u: goto P_0c0049f4;
case 0x0c0049f6u: goto P_0c0049f6;
case 0x0c0049f8u: goto P_0c0049f8;
case 0x0c0049fau: goto P_0c0049fa;
case 0x0c0049fcu: goto P_0c0049fc;
case 0x0c0049feu: goto P_0c0049fe;
case 0x0c004a00u: goto P_0c004a00;
case 0x0c004a02u: goto P_0c004a02;
case 0x0c004a04u: goto P_0c004a04;
case 0x0c004a06u: goto P_0c004a06;
case 0x0c004a08u: goto P_0c004a08;
case 0x0c004a0au: goto P_0c004a0a;
case 0x0c004a0cu: goto P_0c004a0c;
case 0x0c004a0eu: goto P_0c004a0e;
case 0x0c004a10u: goto P_0c004a10;
case 0x0c004a12u: goto P_0c004a12;
case 0x0c004a14u: goto P_0c004a14;
case 0x0c004a16u: goto P_0c004a16;
case 0x0c004a18u: goto P_0c004a18;
case 0x0c004a1au: goto P_0c004a1a;
case 0x0c004a1cu: goto P_0c004a1c;
case 0x0c004a1eu: goto P_0c004a1e;
case 0x0c004a20u: goto P_0c004a20;
case 0x0c004a22u: goto P_0c004a22;
case 0x0c004a24u: goto P_0c004a24;
case 0x0c004a26u: goto P_0c004a26;
case 0x0c004a28u: goto P_0c004a28;
case 0x0c004a2au: goto P_0c004a2a;
case 0x0c004a2cu: goto P_0c004a2c;
case 0x0c004a2eu: goto P_0c004a2e;
case 0x0c004a30u: goto P_0c004a30;
case 0x0c004a32u: goto P_0c004a32;
case 0x0c004a34u: goto P_0c004a34;
case 0x0c004a36u: goto P_0c004a36;
case 0x0c004a38u: goto P_0c004a38;
case 0x0c004a3au: goto P_0c004a3a;
case 0x0c004a3cu: goto P_0c004a3c;
case 0x0c004a3eu: goto P_0c004a3e;
case 0x0c004a40u: goto P_0c004a40;
case 0x0c004a42u: goto P_0c004a42;
case 0x0c004a44u: goto P_0c004a44;
case 0x0c004a46u: goto P_0c004a46;
case 0x0c004a48u: goto P_0c004a48;
case 0x0c004a4au: goto P_0c004a4a;
case 0x0c004a4cu: goto P_0c004a4c;
case 0x0c004a4eu: goto P_0c004a4e;
case 0x0c004a50u: goto P_0c004a50;
case 0x0c004a52u: goto P_0c004a52;
case 0x0c004a54u: goto P_0c004a54;
case 0x0c004a56u: goto P_0c004a56;
case 0x0c004a58u: goto P_0c004a58;
case 0x0c004a5au: goto P_0c004a5a;
case 0x0c004a5cu: goto P_0c004a5c;
case 0x0c004a5eu: goto P_0c004a5e;
case 0x0c004a60u: goto P_0c004a60;
case 0x0c004a62u: goto P_0c004a62;
case 0x0c004a64u: goto P_0c004a64;
case 0x0c004a66u: goto P_0c004a66;
case 0x0c004a68u: goto P_0c004a68;
case 0x0c004a6au: goto P_0c004a6a;
case 0x0c004a6cu: goto P_0c004a6c;
case 0x0c004a6eu: goto P_0c004a6e;
case 0x0c004a70u: goto P_0c004a70;
case 0x0c004a72u: goto P_0c004a72;
case 0x0c004a74u: goto P_0c004a74;
case 0x0c004a76u: goto P_0c004a76;
case 0x0c004a78u: goto P_0c004a78;
case 0x0c004a7au: goto P_0c004a7a;
case 0x0c004a7cu: goto P_0c004a7c;
case 0x0c004a7eu: goto P_0c004a7e;
case 0x0c004a80u: goto P_0c004a80;
case 0x0c004a82u: goto P_0c004a82;
case 0x0c004a84u: goto P_0c004a84;
case 0x0c004a86u: goto P_0c004a86;
case 0x0c004a88u: goto P_0c004a88;
case 0x0c004a8au: goto P_0c004a8a;
case 0x0c004a8cu: goto P_0c004a8c;
case 0x0c004a8eu: goto P_0c004a8e;
case 0x0c004a90u: goto P_0c004a90;
case 0x0c004a92u: goto P_0c004a92;
case 0x0c004a94u: goto P_0c004a94;
case 0x0c004b18u: goto P_0c004b18;
case 0x0c004b1au: goto P_0c004b1a;
case 0x0c004b1cu: goto P_0c004b1c;
case 0x0c004b1eu: goto P_0c004b1e;
case 0x0c004b20u: goto P_0c004b20;
case 0x0c004b22u: goto P_0c004b22;
case 0x0c004b24u: goto P_0c004b24;
case 0x0c004b26u: goto P_0c004b26;
case 0x0c004b28u: goto P_0c004b28;
case 0x0c004b2au: goto P_0c004b2a;
case 0x0c004b2cu: goto P_0c004b2c;
case 0x0c004b2eu: goto P_0c004b2e;
case 0x0c004b30u: goto P_0c004b30;
case 0x0c004b32u: goto P_0c004b32;
case 0x0c004b34u: goto P_0c004b34;
case 0x0c004b36u: goto P_0c004b36;
case 0x0c004b38u: goto P_0c004b38;
case 0x0c004b3au: goto P_0c004b3a;
case 0x0c004b3cu: goto P_0c004b3c;
case 0x0c004b3eu: goto P_0c004b3e;
case 0x0c004b40u: goto P_0c004b40;
case 0x0c004b42u: goto P_0c004b42;
case 0x0c004b44u: goto P_0c004b44;
case 0x0c004b46u: goto P_0c004b46;
case 0x0c004b48u: goto P_0c004b48;
case 0x0c004b4au: goto P_0c004b4a;
case 0x0c004b4cu: goto P_0c004b4c;
case 0x0c004b4eu: goto P_0c004b4e;
case 0x0c004b50u: goto P_0c004b50;
case 0x0c004b52u: goto P_0c004b52;
case 0x0c004b54u: goto P_0c004b54;
case 0x0c004b56u: goto P_0c004b56;
case 0x0c004b58u: goto P_0c004b58;
case 0x0c004b5au: goto P_0c004b5a;
case 0x0c004b5cu: goto P_0c004b5c;
case 0x0c004b5eu: goto P_0c004b5e;
case 0x0c004b60u: goto P_0c004b60;
case 0x0c004b62u: goto P_0c004b62;
case 0x0c004b64u: goto P_0c004b64;
case 0x0c004b66u: goto P_0c004b66;
case 0x0c004b68u: goto P_0c004b68;
case 0x0c004b6au: goto P_0c004b6a;
case 0x0c004b6cu: goto P_0c004b6c;
case 0x0c004b6eu: goto P_0c004b6e;
case 0x0c004b70u: goto P_0c004b70;
case 0x0c004b72u: goto P_0c004b72;
case 0x0c004b74u: goto P_0c004b74;
case 0x0c004b76u: goto P_0c004b76;
case 0x0c004b78u: goto P_0c004b78;
case 0x0c004b7au: goto P_0c004b7a;
case 0x0c004b7cu: goto P_0c004b7c;
case 0x0c004b7eu: goto P_0c004b7e;
case 0x0c004b80u: goto P_0c004b80;
case 0x0c004b82u: goto P_0c004b82;
case 0x0c004b84u: goto P_0c004b84;
case 0x0c004b86u: goto P_0c004b86;
case 0x0c004b88u: goto P_0c004b88;
case 0x0c004b8au: goto P_0c004b8a;
case 0x0c004b8cu: goto P_0c004b8c;
case 0x0c004b8eu: goto P_0c004b8e;
case 0x0c004b90u: goto P_0c004b90;
case 0x0c004b92u: goto P_0c004b92;
case 0x0c004b94u: goto P_0c004b94;
case 0x0c004b96u: goto P_0c004b96;
case 0x0c004b98u: goto P_0c004b98;
case 0x0c004b9au: goto P_0c004b9a;
case 0x0c004b9cu: goto P_0c004b9c;
case 0x0c004b9eu: goto P_0c004b9e;
case 0x0c004ba0u: goto P_0c004ba0;
case 0x0c004ba2u: goto P_0c004ba2;
case 0x0c004ba4u: goto P_0c004ba4;
case 0x0c004ba6u: goto P_0c004ba6;
case 0x0c004ba8u: goto P_0c004ba8;
case 0x0c004baau: goto P_0c004baa;
case 0x0c004bacu: goto P_0c004bac;
case 0x0c004baeu: goto P_0c004bae;
case 0x0c004bb0u: goto P_0c004bb0;
case 0x0c004bb2u: goto P_0c004bb2;
case 0x0c004bb4u: goto P_0c004bb4;
case 0x0c004bb6u: goto P_0c004bb6;
case 0x0c004bb8u: goto P_0c004bb8;
case 0x0c004bbau: goto P_0c004bba;
case 0x0c004bbcu: goto P_0c004bbc;
case 0x0c004bbeu: goto P_0c004bbe;
case 0x0c004bc0u: goto P_0c004bc0;
case 0x0c004bc2u: goto P_0c004bc2;
case 0x0c004bc4u: goto P_0c004bc4;
case 0x0c004bc6u: goto P_0c004bc6;
case 0x0c004bc8u: goto P_0c004bc8;
case 0x0c004bcau: goto P_0c004bca;
case 0x0c004bccu: goto P_0c004bcc;
case 0x0c004bceu: goto P_0c004bce;
case 0x0c004bd0u: goto P_0c004bd0;
case 0x0c004bd2u: goto P_0c004bd2;
case 0x0c004bd4u: goto P_0c004bd4;
case 0x0c004bd6u: goto P_0c004bd6;
case 0x0c004bd8u: goto P_0c004bd8;
case 0x0c004bdau: goto P_0c004bda;
case 0x0c004bdcu: goto P_0c004bdc;
case 0x0c004bdeu: goto P_0c004bde;
case 0x0c004be0u: goto P_0c004be0;
case 0x0c004be2u: goto P_0c004be2;
case 0x0c004be4u: goto P_0c004be4;
case 0x0c004e3cu: goto P_0c004e3c;
case 0x0c004e3eu: goto P_0c004e3e;
case 0x0c004e40u: goto P_0c004e40;
case 0x0c004e42u: goto P_0c004e42;
case 0x0c004e44u: goto P_0c004e44;
case 0x0c004e46u: goto P_0c004e46;
case 0x0c004e48u: goto P_0c004e48;
case 0x0c004e4au: goto P_0c004e4a;
case 0x0c004e4cu: goto P_0c004e4c;
case 0x0c004e4eu: goto P_0c004e4e;
case 0x0c004e50u: goto P_0c004e50;
case 0x0c004e52u: goto P_0c004e52;
case 0x0c004e54u: goto P_0c004e54;
case 0x0c004e56u: goto P_0c004e56;
case 0x0c004e58u: goto P_0c004e58;
case 0x0c004e5au: goto P_0c004e5a;
case 0x0c004e5cu: goto P_0c004e5c;
case 0x0c004e5eu: goto P_0c004e5e;
case 0x0c004e60u: goto P_0c004e60;
case 0x0c004e62u: goto P_0c004e62;
case 0x0c004e64u: goto P_0c004e64;
case 0x0c004e66u: goto P_0c004e66;
case 0x0c004e68u: goto P_0c004e68;
case 0x0c004e6au: goto P_0c004e6a;
case 0x0c004e6cu: goto P_0c004e6c;
case 0x0c004e6eu: goto P_0c004e6e;
case 0x0c004e70u: goto P_0c004e70;
case 0x0c004e72u: goto P_0c004e72;
case 0x0c004e74u: goto P_0c004e74;
case 0x0c004e76u: goto P_0c004e76;
case 0x0c004e78u: goto P_0c004e78;
case 0x0c004e7au: goto P_0c004e7a;
case 0x0c004e7cu: goto P_0c004e7c;
case 0x0c004e7eu: goto P_0c004e7e;
case 0x0c004e80u: goto P_0c004e80;
case 0x0c004e82u: goto P_0c004e82;
case 0x0c004e84u: goto P_0c004e84;
case 0x0c004e86u: goto P_0c004e86;
case 0x0c004e88u: goto P_0c004e88;
case 0x0c004e8au: goto P_0c004e8a;
case 0x0c004e8cu: goto P_0c004e8c;
case 0x0c004e8eu: goto P_0c004e8e;
case 0x0c004e90u: goto P_0c004e90;
case 0x0c004e92u: goto P_0c004e92;
case 0x0c004e94u: goto P_0c004e94;
case 0x0c004e96u: goto P_0c004e96;
case 0x0c004e98u: goto P_0c004e98;
case 0x0c004e9au: goto P_0c004e9a;
case 0x0c004e9cu: goto P_0c004e9c;
case 0x0c004e9eu: goto P_0c004e9e;
case 0x0c004ea0u: goto P_0c004ea0;
case 0x0c004ea2u: goto P_0c004ea2;
case 0x0c004ea4u: goto P_0c004ea4;
case 0x0c004ea6u: goto P_0c004ea6;
case 0x0c004ea8u: goto P_0c004ea8;
case 0x0c004eaau: goto P_0c004eaa;
case 0x0c004eacu: goto P_0c004eac;
case 0x0c004eaeu: goto P_0c004eae;
case 0x0c004eb0u: goto P_0c004eb0;
case 0x0c004eb2u: goto P_0c004eb2;
case 0x0c004eb4u: goto P_0c004eb4;
case 0x0c004eb6u: goto P_0c004eb6;
case 0x0c004eb8u: goto P_0c004eb8;
case 0x0c004ebau: goto P_0c004eba;
case 0x0c004ebcu: goto P_0c004ebc;
case 0x0c004ebeu: goto P_0c004ebe;
case 0x0c004ec0u: goto P_0c004ec0;
case 0x0c004ec2u: goto P_0c004ec2;
case 0x0c004ec4u: goto P_0c004ec4;
case 0x0c004ec6u: goto P_0c004ec6;
case 0x0c004ec8u: goto P_0c004ec8;
case 0x0c004ecau: goto P_0c004eca;
case 0x0c004eccu: goto P_0c004ecc;
case 0x0c004eceu: goto P_0c004ece;
case 0x0c004ed0u: goto P_0c004ed0;
case 0x0c004ed2u: goto P_0c004ed2;
case 0x0c004ed4u: goto P_0c004ed4;
case 0x0c004ed6u: goto P_0c004ed6;
case 0x0c004ed8u: goto P_0c004ed8;
case 0x0c004edau: goto P_0c004eda;
case 0x0c004edcu: goto P_0c004edc;
case 0x0c004edeu: goto P_0c004ede;
case 0x0c004ee0u: goto P_0c004ee0;
case 0x0c004ee2u: goto P_0c004ee2;
case 0x0c004ee4u: goto P_0c004ee4;
case 0x0c004ee6u: goto P_0c004ee6;
case 0x0c004ee8u: goto P_0c004ee8;
case 0x0c004eeau: goto P_0c004eea;
case 0x0c004eecu: goto P_0c004eec;
case 0x0c004eeeu: goto P_0c004eee;
case 0x0c004ef0u: goto P_0c004ef0;
case 0x0c004ef2u: goto P_0c004ef2;
case 0x0c004ef4u: goto P_0c004ef4;
case 0x0c004ef6u: goto P_0c004ef6;
case 0x0c004ef8u: goto P_0c004ef8;
case 0x0c004efau: goto P_0c004efa;
case 0x0c004efcu: goto P_0c004efc;
case 0x0c004efeu: goto P_0c004efe;
case 0x0c004f00u: goto P_0c004f00;
case 0x0c004f02u: goto P_0c004f02;
case 0x0c004f04u: goto P_0c004f04;
case 0x0c004f06u: goto P_0c004f06;
case 0x0c004f08u: goto P_0c004f08;
case 0x0c004f0au: goto P_0c004f0a;
case 0x0c004f0cu: goto P_0c004f0c;
case 0x0c004f0eu: goto P_0c004f0e;
case 0x0c004f10u: goto P_0c004f10;
case 0x0c004f12u: goto P_0c004f12;
case 0x0c004f14u: goto P_0c004f14;
case 0x0c004f16u: goto P_0c004f16;
case 0x0c004f18u: goto P_0c004f18;
case 0x0c004f1au: goto P_0c004f1a;
case 0x0c004f1cu: goto P_0c004f1c;
case 0x0c004f1eu: goto P_0c004f1e;
case 0x0c004f20u: goto P_0c004f20;
case 0x0c004f22u: goto P_0c004f22;
case 0x0c004f24u: goto P_0c004f24;
case 0x0c004f26u: goto P_0c004f26;
case 0x0c004f28u: goto P_0c004f28;
case 0x0c004f2au: goto P_0c004f2a;
case 0x0c004f2cu: goto P_0c004f2c;
case 0x0c004f2eu: goto P_0c004f2e;
case 0x0c004f30u: goto P_0c004f30;
case 0x0c004f32u: goto P_0c004f32;
case 0x0c004f34u: goto P_0c004f34;
case 0x0c004f36u: goto P_0c004f36;
case 0x0c004f38u: goto P_0c004f38;
case 0x0c004f3au: goto P_0c004f3a;
case 0x0c004f3cu: goto P_0c004f3c;
case 0x0c004f3eu: goto P_0c004f3e;
case 0x0c004f40u: goto P_0c004f40;
case 0x0c004f42u: goto P_0c004f42;
case 0x0c00502au: goto P_0c00502a;
case 0x0c00502cu: goto P_0c00502c;
case 0x0c00502eu: goto P_0c00502e;
case 0x0c005030u: goto P_0c005030;
case 0x0c005032u: goto P_0c005032;
case 0x0c005034u: goto P_0c005034;
case 0x0c005036u: goto P_0c005036;
case 0x0c005038u: goto P_0c005038;
case 0x0c00503au: goto P_0c00503a;
case 0x0c00503cu: goto P_0c00503c;
case 0x0c00503eu: goto P_0c00503e;
case 0x0c005040u: goto P_0c005040;
case 0x0c005042u: goto P_0c005042;
case 0x0c005044u: goto P_0c005044;
case 0x0c005046u: goto P_0c005046;
case 0x0c005048u: goto P_0c005048;
case 0x0c00504au: goto P_0c00504a;
case 0x0c00504cu: goto P_0c00504c;
case 0x0c00504eu: goto P_0c00504e;
case 0x0c005050u: goto P_0c005050;
case 0x0c005052u: goto P_0c005052;
case 0x0c005054u: goto P_0c005054;
case 0x0c005056u: goto P_0c005056;
case 0x0c005058u: goto P_0c005058;
case 0x0c00505au: goto P_0c00505a;
case 0x0c00505cu: goto P_0c00505c;
case 0x0c00505eu: goto P_0c00505e;
case 0x0c005060u: goto P_0c005060;
case 0x0c005062u: goto P_0c005062;
case 0x0c005064u: goto P_0c005064;
case 0x0c005066u: goto P_0c005066;
case 0x0c005068u: goto P_0c005068;
case 0x0c00506au: goto P_0c00506a;
case 0x0c00506cu: goto P_0c00506c;
case 0x0c00506eu: goto P_0c00506e;
case 0x0c005070u: goto P_0c005070;
case 0x0c005072u: goto P_0c005072;
case 0x0c005074u: goto P_0c005074;
case 0x0c005076u: goto P_0c005076;
case 0x0c005078u: goto P_0c005078;
case 0x0c00507au: goto P_0c00507a;
case 0x0c00507cu: goto P_0c00507c;
case 0x0c0057f8u: goto P_0c0057f8;
case 0x0c0057fau: goto P_0c0057fa;
case 0x0c0057fcu: goto P_0c0057fc;
case 0x0c0057feu: goto P_0c0057fe;
case 0x0c005800u: goto P_0c005800;
case 0x0c005802u: goto P_0c005802;
case 0x0c005804u: goto P_0c005804;
case 0x0c005806u: goto P_0c005806;
case 0x0c005808u: goto P_0c005808;
case 0x0c00580au: goto P_0c00580a;
case 0x0c00580cu: goto P_0c00580c;
case 0x0c00580eu: goto P_0c00580e;
case 0x0c005810u: goto P_0c005810;
case 0x0c005812u: goto P_0c005812;
case 0x0c005814u: goto P_0c005814;
case 0x0c005816u: goto P_0c005816;
case 0x0c005818u: goto P_0c005818;
case 0x0c00581au: goto P_0c00581a;
case 0x0c00581cu: goto P_0c00581c;
case 0x0c00581eu: goto P_0c00581e;
case 0x0c005820u: goto P_0c005820;
case 0x0c005822u: goto P_0c005822;
case 0x0c005824u: goto P_0c005824;
case 0x0c005826u: goto P_0c005826;
case 0x0c005828u: goto P_0c005828;
case 0x0c00582au: goto P_0c00582a;
case 0x0c00582cu: goto P_0c00582c;
case 0x0c00582eu: goto P_0c00582e;
case 0x0c005830u: goto P_0c005830;
case 0x0c005832u: goto P_0c005832;
case 0x0c005834u: goto P_0c005834;
case 0x0c005836u: goto P_0c005836;
case 0x0c005838u: goto P_0c005838;
case 0x0c005880u: goto P_0c005880;
case 0x0c005882u: goto P_0c005882;
case 0x0c005884u: goto P_0c005884;
case 0x0c005886u: goto P_0c005886;
case 0x0c005888u: goto P_0c005888;
case 0x0c00588au: goto P_0c00588a;
case 0x0c00588cu: goto P_0c00588c;
case 0x0c00588eu: goto P_0c00588e;
case 0x0c005890u: goto P_0c005890;
case 0x0c005892u: goto P_0c005892;
case 0x0c005894u: goto P_0c005894;
case 0x0c005896u: goto P_0c005896;
case 0x0c005898u: goto P_0c005898;
case 0x0c00589au: goto P_0c00589a;
case 0x0c00589cu: goto P_0c00589c;
case 0x0c00589eu: goto P_0c00589e;
case 0x0c0058a0u: goto P_0c0058a0;
case 0x0c0058a2u: goto P_0c0058a2;
case 0x0c005990u: goto P_0c005990;
case 0x0c005992u: goto P_0c005992;
case 0x0c005994u: goto P_0c005994;
case 0x0c005996u: goto P_0c005996;
case 0x0c005998u: goto P_0c005998;
case 0x0c00599au: goto P_0c00599a;
case 0x0c00599cu: goto P_0c00599c;
case 0x0c00599eu: goto P_0c00599e;
case 0x0c0059a0u: goto P_0c0059a0;
case 0x0c0059a2u: goto P_0c0059a2;
case 0x0c0059a4u: goto P_0c0059a4;
case 0x0c0059a6u: goto P_0c0059a6;
case 0x0c0059a8u: goto P_0c0059a8;
case 0x0c0059aau: goto P_0c0059aa;
case 0x0c0059acu: goto P_0c0059ac;
case 0x0c0059aeu: goto P_0c0059ae;
case 0x0c0059b0u: goto P_0c0059b0;
case 0x0c0059b2u: goto P_0c0059b2;
case 0x0c0059b4u: goto P_0c0059b4;
case 0x0c0059b6u: goto P_0c0059b6;
case 0x0c0059b8u: goto P_0c0059b8;
case 0x0c0059bau: goto P_0c0059ba;
case 0x0c0059bcu: goto P_0c0059bc;
case 0x0c0059beu: goto P_0c0059be;
case 0x0c0059c0u: goto P_0c0059c0;
case 0x0c0059c2u: goto P_0c0059c2;
case 0x0c0059c4u: goto P_0c0059c4;
case 0x0c0059c6u: goto P_0c0059c6;
case 0x0c0059c8u: goto P_0c0059c8;
case 0x0c0059cau: goto P_0c0059ca;
case 0x0c0059ccu: goto P_0c0059cc;
case 0x0c0059ceu: goto P_0c0059ce;
case 0x0c0059d0u: goto P_0c0059d0;
case 0x0c0059d2u: goto P_0c0059d2;
case 0x0c0059d4u: goto P_0c0059d4;
case 0x0c0059d6u: goto P_0c0059d6;
case 0x0c0059d8u: goto P_0c0059d8;
case 0x0c0059dau: goto P_0c0059da;
case 0x0c0059dcu: goto P_0c0059dc;
case 0x0c0059deu: goto P_0c0059de;
case 0x0c0059e0u: goto P_0c0059e0;
case 0x0c0059e2u: goto P_0c0059e2;
case 0x0c0059e4u: goto P_0c0059e4;
case 0x0c0059e6u: goto P_0c0059e6;
case 0x0c0059e8u: goto P_0c0059e8;
case 0x0c0059eau: goto P_0c0059ea;
case 0x0c0059ecu: goto P_0c0059ec;
case 0x0c0059eeu: goto P_0c0059ee;
case 0x0c0059f0u: goto P_0c0059f0;
case 0x0c0059f2u: goto P_0c0059f2;
case 0x0c0059f4u: goto P_0c0059f4;
case 0x0c0059f6u: goto P_0c0059f6;
case 0x0c0059f8u: goto P_0c0059f8;
case 0x0c0059fau: goto P_0c0059fa;
case 0x0c0059fcu: goto P_0c0059fc;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c004000: /* original d00c, guest PC 0x0c010100 */
if(!s->budget--) { s->failed_pc=0x0c004000u; return 0; }
r[0]=read(ram,0x0c004034u,4);
goto P_0c004002;
P_0c004002: /* original d10d, guest PC 0x0c010102 */
if(!s->budget--) { s->failed_pc=0x0c004002u; return 0; }
r[1]=read(ram,0x0c004038u,4);
goto P_0c004004;
P_0c004004: /* original 2102, guest PC 0x0c010104 */
if(!s->budget--) { s->failed_pc=0x0c004004u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c004006;
P_0c004006: /* original d00d, guest PC 0x0c010106 */
if(!s->budget--) { s->failed_pc=0x0c004006u; return 0; }
r[0]=read(ram,0x0c00403cu,4);
goto P_0c004008;
P_0c004008: /* original d10d, guest PC 0x0c010108 */
if(!s->budget--) { s->failed_pc=0x0c004008u; return 0; }
r[1]=read(ram,0x0c004040u,4);
goto P_0c00400a;
P_0c00400a: /* original 2102, guest PC 0x0c01010a */
if(!s->budget--) { s->failed_pc=0x0c00400au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c00400c;
P_0c00400c: /* original df0d, guest PC 0x0c01010c */
if(!s->budget--) { s->failed_pc=0x0c00400cu; return 0; }
r[15]=read(ram,0x0c004044u,4);
goto P_0c00400e;
P_0c00400e: /* original d00e, guest PC 0x0c01010e */
if(!s->budget--) { s->failed_pc=0x0c00400eu; return 0; }
r[0]=read(ram,0x0c004048u,4);
goto P_0c004010;
P_0c004010: /* original 402e, guest PC 0x0c010110 */
if(!s->budget--) { s->failed_pc=0x0c004010u; return 0; }
goto P_0c004012;
P_0c004012: /* original 0002, guest PC 0x0c010112 */
if(!s->budget--) { s->failed_pc=0x0c004012u; return 0; }
r[0]=r[17];
goto P_0c004014;
P_0c004014: /* original d10d, guest PC 0x0c010114 */
if(!s->budget--) { s->failed_pc=0x0c004014u; return 0; }
r[1]=read(ram,0x0c00404cu,4);
goto P_0c004016;
P_0c004016: /* original 2019, guest PC 0x0c010116 */
if(!s->budget--) { s->failed_pc=0x0c004016u; return 0; }
r[0]&=r[1];
goto P_0c004018;
P_0c004018: /* original 403e, guest PC 0x0c010118 */
if(!s->budget--) { s->failed_pc=0x0c004018u; return 0; }
goto P_0c00401a;
P_0c00401a: /* original 006a, guest PC 0x0c01011a */
if(!s->budget--) { s->failed_pc=0x0c00401au; return 0; }
r[0]=r[18];
goto P_0c00401c;
P_0c00401c: /* original d10c, guest PC 0x0c01011c */
if(!s->budget--) { s->failed_pc=0x0c00401cu; return 0; }
r[1]=read(ram,0x0c004050u,4);
goto P_0c00401e;
P_0c00401e: /* original 201b, guest PC 0x0c01011e */
if(!s->budget--) { s->failed_pc=0x0c00401eu; return 0; }
r[0]|=r[1];
goto P_0c004020;
P_0c004020: /* original 406a, guest PC 0x0c010120 */
if(!s->budget--) { s->failed_pc=0x0c004020u; return 0; }
r[18]=r[0];
goto P_0c004022;
P_0c004022: /* original 0009, guest PC 0x0c010122 */
if(!s->budget--) { s->failed_pc=0x0c004022u; return 0; }
goto P_0c004024;
P_0c004024: /* original d232, guest PC 0x0c010124 */
if(!s->budget--) { s->failed_pc=0x0c004024u; return 0; }
r[2]=read(ram,0x0c0040f0u,4);
goto P_0c004026;
P_0c004026: /* original c700, guest PC 0x0c010126 */
if(!s->budget--) { s->failed_pc=0x0c004026u; return 0; }
r[0]=code_base|0x00004028u;
goto P_0c004028;
P_0c004028: /* original d332, guest PC 0x0c010128 */
if(!s->budget--) { s->failed_pc=0x0c004028u; return 0; }
r[3]=read(ram,0x0c0040f4u,4);
goto P_0c00402a;
P_0c00402a: /* original 320c, guest PC 0x0c01012a */
if(!s->budget--) { s->failed_pc=0x0c00402au; return 0; }
r[2]+=r[0];
goto P_0c00402c;
P_0c00402c: /* original 6123, guest PC 0x0c01012c */
if(!s->budget--) { s->failed_pc=0x0c00402cu; return 0; }
r[1]=r[2];
goto P_0c00402e;
P_0c00402e: /* original 213b, guest PC 0x0c01012e */
if(!s->budget--) { s->failed_pc=0x0c00402eu; return 0; }
r[1]|=r[3];
goto P_0c004030;
P_0c004030: /* original 412b, guest PC 0x0c010130 */
if(!s->budget--) { s->failed_pc=0x0c004030u; return 0; }
target=r[1];
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
P_0c004032: /* original 0009, guest PC 0x0c010132 */
if(!s->budget--) { s->failed_pc=0x0c004032u; return 0; }
if(!vf3_matrix_family(0x0c004034u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c004034u; return 0; } return 1;
P_0c004070: /* original 7fec, guest PC 0x0c010170 */
if(!s->budget--) { s->failed_pc=0x0c004070u; return 0; }
r[15]+=0xffffffecu;
goto P_0c004072;
P_0c004072: /* original d323, guest PC 0x0c010172 */
if(!s->budget--) { s->failed_pc=0x0c004072u; return 0; }
r[3]=read(ram,0x0c004100u,4);
goto P_0c004074;
P_0c004074: /* original c700, guest PC 0x0c010174 */
if(!s->budget--) { s->failed_pc=0x0c004074u; return 0; }
r[0]=code_base|0x00004078u;
goto P_0c004076;
P_0c004076: /* original de1f, guest PC 0x0c010176 */
if(!s->budget--) { s->failed_pc=0x0c004076u; return 0; }
r[14]=read(ram,0x0c0040f4u,4);
goto P_0c004078;
P_0c004078: /* original 330c, guest PC 0x0c010178 */
if(!s->budget--) { s->failed_pc=0x0c004078u; return 0; }
r[3]+=r[0];
goto P_0c00407a;
P_0c00407a: /* original 6233, guest PC 0x0c01017a */
if(!s->budget--) { s->failed_pc=0x0c00407au; return 0; }
r[2]=r[3];
goto P_0c00407c;
P_0c00407c: /* original 22eb, guest PC 0x0c01017c */
if(!s->budget--) { s->failed_pc=0x0c00407cu; return 0; }
r[2]|=r[14];
goto P_0c00407e;
P_0c00407e: /* original 420b, guest PC 0x0c01017e */
if(!s->budget--) { s->failed_pc=0x0c00407eu; return 0; }
target=r[2];
r[16]=code_base|0x0c004082u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004082u) { target=s->pc; goto dispatch; }
goto P_0c004082;
P_0c004080: /* original 0009, guest PC 0x0c010180 */
if(!s->budget--) { s->failed_pc=0x0c004080u; return 0; }
goto P_0c004082;
P_0c004082: /* original d320, guest PC 0x0c010182 */
if(!s->budget--) { s->failed_pc=0x0c004082u; return 0; }
r[3]=read(ram,0x0c004104u,4);
goto P_0c004084;
P_0c004084: /* original c700, guest PC 0x0c010184 */
if(!s->budget--) { s->failed_pc=0x0c004084u; return 0; }
r[0]=code_base|0x00004088u;
goto P_0c004086;
P_0c004086: /* original 330c, guest PC 0x0c010186 */
if(!s->budget--) { s->failed_pc=0x0c004086u; return 0; }
r[3]+=r[0];
goto P_0c004088;
P_0c004088: /* original 6233, guest PC 0x0c010188 */
if(!s->budget--) { s->failed_pc=0x0c004088u; return 0; }
r[2]=r[3];
goto P_0c00408a;
P_0c00408a: /* original 22eb, guest PC 0x0c01018a */
if(!s->budget--) { s->failed_pc=0x0c00408au; return 0; }
r[2]|=r[14];
goto P_0c00408c;
P_0c00408c: /* original 420b, guest PC 0x0c01018c */
if(!s->budget--) { s->failed_pc=0x0c00408cu; return 0; }
target=r[2];
r[16]=code_base|0x0c004090u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004090u) { target=s->pc; goto dispatch; }
goto P_0c004090;
P_0c00408e: /* original 0009, guest PC 0x0c01018e */
if(!s->budget--) { s->failed_pc=0x0c00408eu; return 0; }
goto P_0c004090;
P_0c004090: /* original d31d, guest PC 0x0c010190 */
if(!s->budget--) { s->failed_pc=0x0c004090u; return 0; }
r[3]=read(ram,0x0c004108u,4);
goto P_0c004092;
P_0c004092: /* original c700, guest PC 0x0c010192 */
if(!s->budget--) { s->failed_pc=0x0c004092u; return 0; }
r[0]=code_base|0x00004094u;
goto P_0c004094;
P_0c004094: /* original 330c, guest PC 0x0c010194 */
if(!s->budget--) { s->failed_pc=0x0c004094u; return 0; }
r[3]+=r[0];
goto P_0c004096;
P_0c004096: /* original 6233, guest PC 0x0c010196 */
if(!s->budget--) { s->failed_pc=0x0c004096u; return 0; }
r[2]=r[3];
goto P_0c004098;
P_0c004098: /* original 22eb, guest PC 0x0c010198 */
if(!s->budget--) { s->failed_pc=0x0c004098u; return 0; }
r[2]|=r[14];
goto P_0c00409a;
P_0c00409a: /* original 420b, guest PC 0x0c01019a */
if(!s->budget--) { s->failed_pc=0x0c00409au; return 0; }
target=r[2];
r[16]=code_base|0x0c00409eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c00409eu) { target=s->pc; goto dispatch; }
goto P_0c00409e;
P_0c00409c: /* original 0009, guest PC 0x0c01019c */
if(!s->budget--) { s->failed_pc=0x0c00409cu; return 0; }
goto P_0c00409e;
P_0c00409e: /* original d11b, guest PC 0x0c01019e */
if(!s->budget--) { s->failed_pc=0x0c00409eu; return 0; }
r[1]=read(ram,0x0c00410cu,4);
goto P_0c0040a0;
P_0c0040a0: /* original e302, guest PC 0x0c0101a0 */
if(!s->budget--) { s->failed_pc=0x0c0040a0u; return 0; }
r[3]=0x00000002u;
goto P_0c0040a2;
P_0c0040a2: /* original 2132, guest PC 0x0c0101a2 */
if(!s->budget--) { s->failed_pc=0x0c0040a2u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0040a4;
P_0c0040a4: /* original d41a, guest PC 0x0c0101a4 */
if(!s->budget--) { s->failed_pc=0x0c0040a4u; return 0; }
r[4]=read(ram,0x0c004110u,4);
goto P_0c0040a6;
P_0c0040a6: /* original d21b, guest PC 0x0c0101a6 */
if(!s->budget--) { s->failed_pc=0x0c0040a6u; return 0; }
r[2]=read(ram,0x0c004114u,4);
goto P_0c0040a8;
P_0c0040a8: /* original 6321, guest PC 0x0c0101a8 */
if(!s->budget--) { s->failed_pc=0x0c0040a8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[3]=tmp;
goto P_0c0040aa;
P_0c0040aa: /* original 901d, guest PC 0x0c0101aa */
if(!s->budget--) { s->failed_pc=0x0c0040aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0040e8u,2);
goto P_0c0040ac;
P_0c0040ac: /* original 3300, guest PC 0x0c0101ac */
if(!s->budget--) { s->failed_pc=0x0c0040acu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c0040ae;
P_0c0040ae: /* original 8b02, guest PC 0x0c0101ae */
if(!s->budget--) { s->failed_pc=0x0c0040aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0040b6; }
goto P_0c0040b0;
P_0c0040b0: /* original 911b, guest PC 0x0c0101b0 */
if(!s->budget--) { s->failed_pc=0x0c0040b0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0040eau,2);
goto P_0c0040b2;
P_0c0040b2: /* original a004, guest PC 0x0c0101b2 */
if(!s->budget--) { s->failed_pc=0x0c0040b2u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c0040be;
P_0c0040b4: /* original 2412, guest PC 0x0c0101b4 */
if(!s->budget--) { s->failed_pc=0x0c0040b4u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c0040b6;
P_0c0040b6: /* original d118, guest PC 0x0c0101b6 */
if(!s->budget--) { s->failed_pc=0x0c0040b6u; return 0; }
r[1]=read(ram,0x0c004118u,4);
goto P_0c0040b8;
P_0c0040b8: /* original 6310, guest PC 0x0c0101b8 */
if(!s->budget--) { s->failed_pc=0x0c0040b8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[3]=tmp;
goto P_0c0040ba;
P_0c0040ba: /* original 633c, guest PC 0x0c0101ba */
if(!s->budget--) { s->failed_pc=0x0c0040bau; return 0; }
r[3]=r[3]&255u;
goto P_0c0040bc;
P_0c0040bc: /* original 2432, guest PC 0x0c0101bc */
if(!s->budget--) { s->failed_pc=0x0c0040bcu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0040be;
P_0c0040be: /* original d217, guest PC 0x0c0101be */
if(!s->budget--) { s->failed_pc=0x0c0040beu; return 0; }
r[2]=read(ram,0x0c00411cu,4);
goto P_0c0040c0;
P_0c0040c0: /* original c700, guest PC 0x0c0101c0 */
if(!s->budget--) { s->failed_pc=0x0c0040c0u; return 0; }
r[0]=code_base|0x000040c4u;
goto P_0c0040c2;
P_0c0040c2: /* original 320c, guest PC 0x0c0101c2 */
if(!s->budget--) { s->failed_pc=0x0c0040c2u; return 0; }
r[2]+=r[0];
goto P_0c0040c4;
P_0c0040c4: /* original d316, guest PC 0x0c0101c4 */
if(!s->budget--) { s->failed_pc=0x0c0040c4u; return 0; }
r[3]=read(ram,0x0c004120u,4);
goto P_0c0040c6;
P_0c0040c6: /* original 6123, guest PC 0x0c0101c6 */
if(!s->budget--) { s->failed_pc=0x0c0040c6u; return 0; }
r[1]=r[2];
goto P_0c0040c8;
P_0c0040c8: /* original d216, guest PC 0x0c0101c8 */
if(!s->budget--) { s->failed_pc=0x0c0040c8u; return 0; }
r[2]=read(ram,0x0c004124u,4);
goto P_0c0040ca;
P_0c0040ca: /* original c702, guest PC 0x0c0101ca */
if(!s->budget--) { s->failed_pc=0x0c0040cau; return 0; }
r[0]=code_base|0x000040d4u;
goto P_0c0040cc;
P_0c0040cc: /* original 313c, guest PC 0x0c0101cc */
if(!s->budget--) { s->failed_pc=0x0c0040ccu; return 0; }
r[1]+=r[3];
goto P_0c0040ce;
P_0c0040ce: /* original 2212, guest PC 0x0c0101ce */
if(!s->budget--) { s->failed_pc=0x0c0040ceu; return 0; }
write(ram,r[2],r[1],4);
goto P_0c0040d0;
P_0c0040d0: /* original d315, guest PC 0x0c0101d0 */
if(!s->budget--) { s->failed_pc=0x0c0040d0u; return 0; }
r[3]=read(ram,0x0c004128u,4);
goto P_0c0040d2;
P_0c0040d2: /* original 330c, guest PC 0x0c0101d2 */
if(!s->budget--) { s->failed_pc=0x0c0040d2u; return 0; }
r[3]+=r[0];
goto P_0c0040d4;
P_0c0040d4: /* original d015, guest PC 0x0c0101d4 */
if(!s->budget--) { s->failed_pc=0x0c0040d4u; return 0; }
r[0]=read(ram,0x0c00412cu,4);
goto P_0c0040d6;
P_0c0040d6: /* original ea00, guest PC 0x0c0101d6 */
if(!s->budget--) { s->failed_pc=0x0c0040d6u; return 0; }
r[10]=0x00000000u;
goto P_0c0040d8;
P_0c0040d8: /* original d215, guest PC 0x0c0101d8 */
if(!s->budget--) { s->failed_pc=0x0c0040d8u; return 0; }
r[2]=read(ram,0x0c004130u,4);
goto P_0c0040da;
P_0c0040da: /* original e903, guest PC 0x0c0101da */
if(!s->budget--) { s->failed_pc=0x0c0040dau; return 0; }
r[9]=0x00000003u;
goto P_0c0040dc;
P_0c0040dc: /* original 330c, guest PC 0x0c0101dc */
if(!s->budget--) { s->failed_pc=0x0c0040dcu; return 0; }
r[3]+=r[0];
goto P_0c0040de;
P_0c0040de: /* original 2232, guest PC 0x0c0101de */
if(!s->budget--) { s->failed_pc=0x0c0040deu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0040e0;
P_0c0040e0: /* original dc14, guest PC 0x0c0101e0 */
if(!s->budget--) { s->failed_pc=0x0c0040e0u; return 0; }
r[12]=read(ram,0x0c004134u,4);
goto P_0c0040e2;
P_0c0040e2: /* original 9d03, guest PC 0x0c0101e2 */
if(!s->budget--) { s->failed_pc=0x0c0040e2u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0040ecu,2);
goto P_0c0040e4;
P_0c0040e4: /* original a03d, guest PC 0x0c0101e4 */
if(!s->budget--) { s->failed_pc=0x0c0040e4u; return 0; }
r[11]=r[10];
goto P_0c004162;
P_0c0040e6: /* original 6ba3, guest PC 0x0c0101e6 */
if(!s->budget--) { s->failed_pc=0x0c0040e6u; return 0; }
r[11]=r[10];
if(!vf3_matrix_family(0x0c0040e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0040e8u; return 0; } return 1;
P_0c004138: /* original d33c, guest PC 0x0c010238 */
if(!s->budget--) { s->failed_pc=0x0c004138u; return 0; }
r[3]=read(ram,0x0c00422cu,4);
goto P_0c00413a;
P_0c00413a: /* original c700, guest PC 0x0c01023a */
if(!s->budget--) { s->failed_pc=0x0c00413au; return 0; }
r[0]=code_base|0x0000413cu;
goto P_0c00413c;
P_0c00413c: /* original 330c, guest PC 0x0c01023c */
if(!s->budget--) { s->failed_pc=0x0c00413cu; return 0; }
r[3]+=r[0];
goto P_0c00413e;
P_0c00413e: /* original 6233, guest PC 0x0c01023e */
if(!s->budget--) { s->failed_pc=0x0c00413eu; return 0; }
r[2]=r[3];
goto P_0c004140;
P_0c004140: /* original 22eb, guest PC 0x0c010240 */
if(!s->budget--) { s->failed_pc=0x0c004140u; return 0; }
r[2]|=r[14];
goto P_0c004142;
P_0c004142: /* original 420b, guest PC 0x0c010242 */
if(!s->budget--) { s->failed_pc=0x0c004142u; return 0; }
target=r[2];
r[16]=code_base|0x0c004146u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004146u) { target=s->pc; goto dispatch; }
goto P_0c004146;
P_0c004144: /* original 64d3, guest PC 0x0c010244 */
if(!s->budget--) { s->failed_pc=0x0c004144u; return 0; }
r[4]=r[13];
goto P_0c004146;
P_0c004146: /* original 64c3, guest PC 0x0c010246 */
if(!s->budget--) { s->failed_pc=0x0c004146u; return 0; }
r[4]=r[12];
goto P_0c004148;
P_0c004148: /* original 4410, guest PC 0x0c010248 */
if(!s->budget--) { s->failed_pc=0x0c004148u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c00414a;
P_0c00414a: /* original 8bfd, guest PC 0x0c01024a */
if(!s->budget--) { s->failed_pc=0x0c00414au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004148; }
goto P_0c00414c;
P_0c00414c: /* original d238, guest PC 0x0c01024c */
if(!s->budget--) { s->failed_pc=0x0c00414cu; return 0; }
r[2]=read(ram,0x0c004230u,4);
goto P_0c00414e;
P_0c00414e: /* original c700, guest PC 0x0c01024e */
if(!s->budget--) { s->failed_pc=0x0c00414eu; return 0; }
r[0]=code_base|0x00004150u;
goto P_0c004150;
P_0c004150: /* original 320c, guest PC 0x0c010250 */
if(!s->budget--) { s->failed_pc=0x0c004150u; return 0; }
r[2]+=r[0];
goto P_0c004152;
P_0c004152: /* original 6323, guest PC 0x0c010252 */
if(!s->budget--) { s->failed_pc=0x0c004152u; return 0; }
r[3]=r[2];
goto P_0c004154;
P_0c004154: /* original 23eb, guest PC 0x0c010254 */
if(!s->budget--) { s->failed_pc=0x0c004154u; return 0; }
r[3]|=r[14];
goto P_0c004156;
P_0c004156: /* original 430b, guest PC 0x0c010256 */
if(!s->budget--) { s->failed_pc=0x0c004156u; return 0; }
target=r[3];
r[16]=code_base|0x0c00415au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c00415au) { target=s->pc; goto dispatch; }
goto P_0c00415a;
P_0c004158: /* original e400, guest PC 0x0c010258 */
if(!s->budget--) { s->failed_pc=0x0c004158u; return 0; }
r[4]=0x00000000u;
goto P_0c00415a;
P_0c00415a: /* original 64c3, guest PC 0x0c01025a */
if(!s->budget--) { s->failed_pc=0x0c00415au; return 0; }
r[4]=r[12];
goto P_0c00415c;
P_0c00415c: /* original 4410, guest PC 0x0c01025c */
if(!s->budget--) { s->failed_pc=0x0c00415cu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c00415e;
P_0c00415e: /* original 8bfd, guest PC 0x0c01025e */
if(!s->budget--) { s->failed_pc=0x0c00415eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c00415c; }
goto P_0c004160;
P_0c004160: /* original 7b01, guest PC 0x0c010260 */
if(!s->budget--) { s->failed_pc=0x0c004160u; return 0; }
r[11]+=0x00000001u;
goto P_0c004162;
P_0c004162: /* original 3b93, guest PC 0x0c010262 */
if(!s->budget--) { s->failed_pc=0x0c004162u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[9])!=0);
goto P_0c004164;
P_0c004164: /* original 8be8, guest PC 0x0c010264 */
if(!s->budget--) { s->failed_pc=0x0c004164u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004138; }
goto P_0c004166;
P_0c004166: /* original d233, guest PC 0x0c010266 */
if(!s->budget--) { s->failed_pc=0x0c004166u; return 0; }
r[2]=read(ram,0x0c004234u,4);
goto P_0c004168;
P_0c004168: /* original c700, guest PC 0x0c010268 */
if(!s->budget--) { s->failed_pc=0x0c004168u; return 0; }
r[0]=code_base|0x0000416cu;
goto P_0c00416a;
P_0c00416a: /* original 320c, guest PC 0x0c01026a */
if(!s->budget--) { s->failed_pc=0x0c00416au; return 0; }
r[2]+=r[0];
goto P_0c00416c;
P_0c00416c: /* original 6323, guest PC 0x0c01026c */
if(!s->budget--) { s->failed_pc=0x0c00416cu; return 0; }
r[3]=r[2];
goto P_0c00416e;
P_0c00416e: /* original 23eb, guest PC 0x0c01026e */
if(!s->budget--) { s->failed_pc=0x0c00416eu; return 0; }
r[3]|=r[14];
goto P_0c004170;
P_0c004170: /* original 430b, guest PC 0x0c010270 */
if(!s->budget--) { s->failed_pc=0x0c004170u; return 0; }
target=r[3];
r[16]=code_base|0x0c004174u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004174u) { target=s->pc; goto dispatch; }
goto P_0c004174;
P_0c004172: /* original 0009, guest PC 0x0c010272 */
if(!s->budget--) { s->failed_pc=0x0c004172u; return 0; }
goto P_0c004174;
P_0c004174: /* original d230, guest PC 0x0c010274 */
if(!s->budget--) { s->failed_pc=0x0c004174u; return 0; }
r[2]=read(ram,0x0c004238u,4);
goto P_0c004176;
P_0c004176: /* original ec01, guest PC 0x0c010276 */
if(!s->budget--) { s->failed_pc=0x0c004176u; return 0; }
r[12]=0x00000001u;
goto P_0c004178;
P_0c004178: /* original 22c0, guest PC 0x0c010278 */
if(!s->budget--) { s->failed_pc=0x0c004178u; return 0; }
write(ram,r[2],r[12],1);
goto P_0c00417a;
P_0c00417a: /* original db30, guest PC 0x0c01027a */
if(!s->budget--) { s->failed_pc=0x0c00417au; return 0; }
r[11]=read(ram,0x0c00423cu,4);
goto P_0c00417c;
P_0c00417c: /* original d830, guest PC 0x0c01027c */
if(!s->budget--) { s->failed_pc=0x0c00417cu; return 0; }
r[8]=read(ram,0x0c004240u,4);
goto P_0c00417e;
P_0c00417e: /* original 2ba2, guest PC 0x0c01027e */
if(!s->budget--) { s->failed_pc=0x0c00417eu; return 0; }
write(ram,r[11],r[10],4);
goto P_0c004180;
P_0c004180: /* original 2fa2, guest PC 0x0c010280 */
if(!s->budget--) { s->failed_pc=0x0c004180u; return 0; }
write(ram,r[15],r[10],4);
goto P_0c004182;
P_0c004182: /* original d230, guest PC 0x0c010282 */
if(!s->budget--) { s->failed_pc=0x0c004182u; return 0; }
r[2]=read(ram,0x0c004244u,4);
goto P_0c004184;
P_0c004184: /* original c700, guest PC 0x0c010284 */
if(!s->budget--) { s->failed_pc=0x0c004184u; return 0; }
r[0]=code_base|0x00004188u;
goto P_0c004186;
P_0c004186: /* original 320c, guest PC 0x0c010286 */
if(!s->budget--) { s->failed_pc=0x0c004186u; return 0; }
r[2]+=r[0];
goto P_0c004188;
P_0c004188: /* original 6323, guest PC 0x0c010288 */
if(!s->budget--) { s->failed_pc=0x0c004188u; return 0; }
r[3]=r[2];
goto P_0c00418a;
P_0c00418a: /* original 23eb, guest PC 0x0c01028a */
if(!s->budget--) { s->failed_pc=0x0c00418au; return 0; }
r[3]|=r[14];
goto P_0c00418c;
P_0c00418c: /* original 430b, guest PC 0x0c01028c */
if(!s->budget--) { s->failed_pc=0x0c00418cu; return 0; }
target=r[3];
r[16]=code_base|0x0c004190u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004190u) { target=s->pc; goto dispatch; }
goto P_0c004190;
P_0c00418e: /* original 0009, guest PC 0x0c01028e */
if(!s->budget--) { s->failed_pc=0x0c00418eu; return 0; }
goto P_0c004190;
P_0c004190: /* original d32d, guest PC 0x0c010290 */
if(!s->budget--) { s->failed_pc=0x0c004190u; return 0; }
r[3]=read(ram,0x0c004248u,4);
goto P_0c004192;
P_0c004192: /* original c702, guest PC 0x0c010292 */
if(!s->budget--) { s->failed_pc=0x0c004192u; return 0; }
r[0]=code_base|0x0000419cu;
goto P_0c004194;
P_0c004194: /* original 6af2, guest PC 0x0c010294 */
if(!s->budget--) { s->failed_pc=0x0c004194u; return 0; }
tmp=read(ram,r[15],4);
r[10]=tmp;
goto P_0c004196;
P_0c004196: /* original 69d3, guest PC 0x0c010296 */
if(!s->budget--) { s->failed_pc=0x0c004196u; return 0; }
r[9]=r[13];
goto P_0c004198;
P_0c004198: /* original 330c, guest PC 0x0c010298 */
if(!s->budget--) { s->failed_pc=0x0c004198u; return 0; }
r[3]+=r[0];
goto P_0c00419a;
P_0c00419a: /* original 2ac9, guest PC 0x0c01029a */
if(!s->budget--) { s->failed_pc=0x0c00419au; return 0; }
r[10]&=r[12];
goto P_0c00419c;
P_0c00419c: /* original 6233, guest PC 0x0c01029c */
if(!s->budget--) { s->failed_pc=0x0c00419cu; return 0; }
r[2]=r[3];
goto P_0c00419e;
P_0c00419e: /* original 22eb, guest PC 0x0c01029e */
if(!s->budget--) { s->failed_pc=0x0c00419eu; return 0; }
r[2]|=r[14];
goto P_0c0041a0;
P_0c0041a0: /* original 420b, guest PC 0x0c0102a0 */
if(!s->budget--) { s->failed_pc=0x0c0041a0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0041a4u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0041a4u) { target=s->pc; goto dispatch; }
goto P_0c0041a4;
P_0c0041a2: /* original 64a3, guest PC 0x0c0102a2 */
if(!s->budget--) { s->failed_pc=0x0c0041a2u; return 0; }
r[4]=r[10];
goto P_0c0041a4;
P_0c0041a4: /* original 2008, guest PC 0x0c0102a4 */
if(!s->budget--) { s->failed_pc=0x0c0041a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0041a6;
P_0c0041a6: /* original 8908, guest PC 0x0c0102a6 */
if(!s->budget--) { s->failed_pc=0x0c0041a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0041ba; }
goto P_0c0041a8;
P_0c0041a8: /* original d928, guest PC 0x0c0102a8 */
if(!s->budget--) { s->failed_pc=0x0c0041a8u; return 0; }
r[9]=read(ram,0x0c00424cu,4);
goto P_0c0041aa;
P_0c0041aa: /* original c700, guest PC 0x0c0102aa */
if(!s->budget--) { s->failed_pc=0x0c0041aau; return 0; }
r[0]=code_base|0x000041acu;
goto P_0c0041ac;
P_0c0041ac: /* original 65f3, guest PC 0x0c0102ac */
if(!s->budget--) { s->failed_pc=0x0c0041acu; return 0; }
r[5]=r[15];
goto P_0c0041ae;
P_0c0041ae: /* original 390c, guest PC 0x0c0102ae */
if(!s->budget--) { s->failed_pc=0x0c0041aeu; return 0; }
r[9]+=r[0];
goto P_0c0041b0;
P_0c0041b0: /* original 7504, guest PC 0x0c0102b0 */
if(!s->budget--) { s->failed_pc=0x0c0041b0u; return 0; }
r[5]+=0x00000004u;
goto P_0c0041b2;
P_0c0041b2: /* original 29eb, guest PC 0x0c0102b2 */
if(!s->budget--) { s->failed_pc=0x0c0041b2u; return 0; }
r[9]|=r[14];
goto P_0c0041b4;
P_0c0041b4: /* original 490b, guest PC 0x0c0102b4 */
if(!s->budget--) { s->failed_pc=0x0c0041b4u; return 0; }
target=r[9];
r[16]=code_base|0x0c0041b8u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0041b8u) { target=s->pc; goto dispatch; }
goto P_0c0041b8;
P_0c0041b6: /* original 64a3, guest PC 0x0c0102b6 */
if(!s->budget--) { s->failed_pc=0x0c0041b6u; return 0; }
r[4]=r[10];
goto P_0c0041b8;
P_0c0041b8: /* original 6903, guest PC 0x0c0102b8 */
if(!s->budget--) { s->failed_pc=0x0c0041b8u; return 0; }
r[9]=r[0];
goto P_0c0041ba;
P_0c0041ba: /* original 39d0, guest PC 0x0c0102ba */
if(!s->budget--) { s->failed_pc=0x0c0041bau; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[13])!=0);
goto P_0c0041bc;
P_0c0041bc: /* original 8908, guest PC 0x0c0102bc */
if(!s->budget--) { s->failed_pc=0x0c0041bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0041d0; }
goto P_0c0041be;
P_0c0041be: /* original d224, guest PC 0x0c0102be */
if(!s->budget--) { s->failed_pc=0x0c0041beu; return 0; }
r[2]=read(ram,0x0c004250u,4);
goto P_0c0041c0;
P_0c0041c0: /* original c700, guest PC 0x0c0102c0 */
if(!s->budget--) { s->failed_pc=0x0c0041c0u; return 0; }
r[0]=code_base|0x000041c4u;
goto P_0c0041c2;
P_0c0041c2: /* original 320c, guest PC 0x0c0102c2 */
if(!s->budget--) { s->failed_pc=0x0c0041c2u; return 0; }
r[2]+=r[0];
goto P_0c0041c4;
P_0c0041c4: /* original 65f3, guest PC 0x0c0102c4 */
if(!s->budget--) { s->failed_pc=0x0c0041c4u; return 0; }
r[5]=r[15];
goto P_0c0041c6;
P_0c0041c6: /* original 6323, guest PC 0x0c0102c6 */
if(!s->budget--) { s->failed_pc=0x0c0041c6u; return 0; }
r[3]=r[2];
goto P_0c0041c8;
P_0c0041c8: /* original 7504, guest PC 0x0c0102c8 */
if(!s->budget--) { s->failed_pc=0x0c0041c8u; return 0; }
r[5]+=0x00000004u;
goto P_0c0041ca;
P_0c0041ca: /* original 23eb, guest PC 0x0c0102ca */
if(!s->budget--) { s->failed_pc=0x0c0041cau; return 0; }
r[3]|=r[14];
goto P_0c0041cc;
P_0c0041cc: /* original 430b, guest PC 0x0c0102cc */
if(!s->budget--) { s->failed_pc=0x0c0041ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0041d0u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0041d0u) { target=s->pc; goto dispatch; }
goto P_0c0041d0;
P_0c0041ce: /* original 6493, guest PC 0x0c0102ce */
if(!s->budget--) { s->failed_pc=0x0c0041ceu; return 0; }
r[4]=r[9];
goto P_0c0041d0;
P_0c0041d0: /* original 62b2, guest PC 0x0c0102d0 */
if(!s->budget--) { s->failed_pc=0x0c0041d0u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c0041d2;
P_0c0041d2: /* original 2228, guest PC 0x0c0102d2 */
if(!s->budget--) { s->failed_pc=0x0c0041d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0041d4;
P_0c0041d4: /* original 8b26, guest PC 0x0c0102d4 */
if(!s->budget--) { s->failed_pc=0x0c0041d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004224; }
goto P_0c0041d6;
P_0c0041d6: /* original d31f, guest PC 0x0c0102d6 */
if(!s->budget--) { s->failed_pc=0x0c0041d6u; return 0; }
r[3]=read(ram,0x0c004254u,4);
goto P_0c0041d8;
P_0c0041d8: /* original 6032, guest PC 0x0c0102d8 */
if(!s->budget--) { s->failed_pc=0x0c0041d8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0041da;
P_0c0041da: /* original c880, guest PC 0x0c0102da */
if(!s->budget--) { s->failed_pc=0x0c0041dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0041dc;
P_0c0041dc: /* original 8922, guest PC 0x0c0102dc */
if(!s->budget--) { s->failed_pc=0x0c0041dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c004224; }
goto P_0c0041de;
P_0c0041de: /* original 6182, guest PC 0x0c0102de */
if(!s->budget--) { s->failed_pc=0x0c0041deu; return 0; }
tmp=read(ram,r[8],4);
r[1]=tmp;
goto P_0c0041e0;
P_0c0041e0: /* original 2118, guest PC 0x0c0102e0 */
if(!s->budget--) { s->failed_pc=0x0c0041e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0041e2;
P_0c0041e2: /* original 8906, guest PC 0x0c0102e2 */
if(!s->budget--) { s->failed_pc=0x0c0041e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0041f2; }
goto P_0c0041e4;
P_0c0041e4: /* original d21c, guest PC 0x0c0102e4 */
if(!s->budget--) { s->failed_pc=0x0c0041e4u; return 0; }
r[2]=read(ram,0x0c004258u,4);
goto P_0c0041e6;
P_0c0041e6: /* original c700, guest PC 0x0c0102e6 */
if(!s->budget--) { s->failed_pc=0x0c0041e6u; return 0; }
r[0]=code_base|0x000041e8u;
goto P_0c0041e8;
P_0c0041e8: /* original 320c, guest PC 0x0c0102e8 */
if(!s->budget--) { s->failed_pc=0x0c0041e8u; return 0; }
r[2]+=r[0];
goto P_0c0041ea;
P_0c0041ea: /* original 6323, guest PC 0x0c0102ea */
if(!s->budget--) { s->failed_pc=0x0c0041eau; return 0; }
r[3]=r[2];
goto P_0c0041ec;
P_0c0041ec: /* original 23eb, guest PC 0x0c0102ec */
if(!s->budget--) { s->failed_pc=0x0c0041ecu; return 0; }
r[3]|=r[14];
goto P_0c0041ee;
P_0c0041ee: /* original 430b, guest PC 0x0c0102ee */
if(!s->budget--) { s->failed_pc=0x0c0041eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0041f2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0041f2u) { target=s->pc; goto dispatch; }
goto P_0c0041f2;
P_0c0041f0: /* original 0009, guest PC 0x0c0102f0 */
if(!s->budget--) { s->failed_pc=0x0c0041f0u; return 0; }
goto P_0c0041f2;
P_0c0041f2: /* original d21a, guest PC 0x0c0102f2 */
if(!s->budget--) { s->failed_pc=0x0c0041f2u; return 0; }
r[2]=read(ram,0x0c00425cu,4);
goto P_0c0041f4;
P_0c0041f4: /* original c700, guest PC 0x0c0102f4 */
if(!s->budget--) { s->failed_pc=0x0c0041f4u; return 0; }
r[0]=code_base|0x000041f8u;
goto P_0c0041f6;
P_0c0041f6: /* original 320c, guest PC 0x0c0102f6 */
if(!s->budget--) { s->failed_pc=0x0c0041f6u; return 0; }
r[2]+=r[0];
goto P_0c0041f8;
P_0c0041f8: /* original 6323, guest PC 0x0c0102f8 */
if(!s->budget--) { s->failed_pc=0x0c0041f8u; return 0; }
r[3]=r[2];
goto P_0c0041fa;
P_0c0041fa: /* original 23eb, guest PC 0x0c0102fa */
if(!s->budget--) { s->failed_pc=0x0c0041fau; return 0; }
r[3]|=r[14];
goto P_0c0041fc;
P_0c0041fc: /* original 430b, guest PC 0x0c0102fc */
if(!s->budget--) { s->failed_pc=0x0c0041fcu; return 0; }
target=r[3];
r[16]=code_base|0x0c004200u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004200u) { target=s->pc; goto dispatch; }
goto P_0c004200;
P_0c0041fe: /* original 64d3, guest PC 0x0c0102fe */
if(!s->budget--) { s->failed_pc=0x0c0041feu; return 0; }
r[4]=r[13];
goto P_0c004200;
P_0c004200: /* original d217, guest PC 0x0c010300 */
if(!s->budget--) { s->failed_pc=0x0c004200u; return 0; }
r[2]=read(ram,0x0c004260u,4);
goto P_0c004202;
P_0c004202: /* original c700, guest PC 0x0c010302 */
if(!s->budget--) { s->failed_pc=0x0c004202u; return 0; }
r[0]=code_base|0x00004204u;
goto P_0c004204;
P_0c004204: /* original 320c, guest PC 0x0c010304 */
if(!s->budget--) { s->failed_pc=0x0c004204u; return 0; }
r[2]+=r[0];
goto P_0c004206;
P_0c004206: /* original 6323, guest PC 0x0c010306 */
if(!s->budget--) { s->failed_pc=0x0c004206u; return 0; }
r[3]=r[2];
goto P_0c004208;
P_0c004208: /* original 23eb, guest PC 0x0c010308 */
if(!s->budget--) { s->failed_pc=0x0c004208u; return 0; }
r[3]|=r[14];
goto P_0c00420a;
P_0c00420a: /* original 430b, guest PC 0x0c01030a */
if(!s->budget--) { s->failed_pc=0x0c00420au; return 0; }
target=r[3];
r[16]=code_base|0x0c00420eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c00420eu) { target=s->pc; goto dispatch; }
goto P_0c00420e;
P_0c00420c: /* original 0009, guest PC 0x0c01030c */
if(!s->budget--) { s->failed_pc=0x0c00420cu; return 0; }
goto P_0c00420e;
P_0c00420e: /* original 6282, guest PC 0x0c01030e */
if(!s->budget--) { s->failed_pc=0x0c00420eu; return 0; }
tmp=read(ram,r[8],4);
r[2]=tmp;
goto P_0c004210;
P_0c004210: /* original 2228, guest PC 0x0c010310 */
if(!s->budget--) { s->failed_pc=0x0c004210u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c004212;
P_0c004212: /* original 8906, guest PC 0x0c010312 */
if(!s->budget--) { s->failed_pc=0x0c004212u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c004222; }
goto P_0c004214;
P_0c004214: /* original d213, guest PC 0x0c010314 */
if(!s->budget--) { s->failed_pc=0x0c004214u; return 0; }
r[2]=read(ram,0x0c004264u,4);
goto P_0c004216;
P_0c004216: /* original c700, guest PC 0x0c010316 */
if(!s->budget--) { s->failed_pc=0x0c004216u; return 0; }
r[0]=code_base|0x00004218u;
goto P_0c004218;
P_0c004218: /* original 320c, guest PC 0x0c010318 */
if(!s->budget--) { s->failed_pc=0x0c004218u; return 0; }
r[2]+=r[0];
goto P_0c00421a;
P_0c00421a: /* original 6323, guest PC 0x0c01031a */
if(!s->budget--) { s->failed_pc=0x0c00421au; return 0; }
r[3]=r[2];
goto P_0c00421c;
P_0c00421c: /* original 23eb, guest PC 0x0c01031c */
if(!s->budget--) { s->failed_pc=0x0c00421cu; return 0; }
r[3]|=r[14];
goto P_0c00421e;
P_0c00421e: /* original 430b, guest PC 0x0c01031e */
if(!s->budget--) { s->failed_pc=0x0c00421eu; return 0; }
target=r[3];
r[16]=code_base|0x0c004222u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004222u) { target=s->pc; goto dispatch; }
goto P_0c004222;
P_0c004220: /* original 0009, guest PC 0x0c010320 */
if(!s->budget--) { s->failed_pc=0x0c004220u; return 0; }
goto P_0c004222;
P_0c004222: /* original 2bc2, guest PC 0x0c010322 */
if(!s->budget--) { s->failed_pc=0x0c004222u; return 0; }
write(ram,r[11],r[12],4);
goto P_0c004224;
P_0c004224: /* original 62f2, guest PC 0x0c010324 */
if(!s->budget--) { s->failed_pc=0x0c004224u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c004226;
P_0c004226: /* original 7201, guest PC 0x0c010326 */
if(!s->budget--) { s->failed_pc=0x0c004226u; return 0; }
r[2]+=0x00000001u;
goto P_0c004228;
P_0c004228: /* original afab, guest PC 0x0c010328 */
if(!s->budget--) { s->failed_pc=0x0c004228u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c004182;
P_0c00422a: /* original 2f22, guest PC 0x0c01032a */
if(!s->budget--) { s->failed_pc=0x0c00422au; return 0; }
write(ram,r[15],r[2],4);
if(!vf3_matrix_family(0x0c00422cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c00422cu; return 0; } return 1;
P_0c004268: /* original d33b, guest PC 0x0c010368 */
if(!s->budget--) { s->failed_pc=0x0c004268u; return 0; }
r[3]=read(ram,0x0c004358u,4);
goto P_0c00426a;
P_0c00426a: /* original 9271, guest PC 0x0c01036a */
if(!s->budget--) { s->failed_pc=0x0c00426au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004350u,2);
goto P_0c00426c;
P_0c00426c: /* original 6432, guest PC 0x0c01036c */
if(!s->budget--) { s->failed_pc=0x0c00426cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c00426e;
P_0c00426e: /* original d53b, guest PC 0x0c01036e */
if(!s->budget--) { s->failed_pc=0x0c00426eu; return 0; }
r[5]=read(ram,0x0c00435cu,4);
goto P_0c004270;
P_0c004270: /* original 3420, guest PC 0x0c010370 */
if(!s->budget--) { s->failed_pc=0x0c004270u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c004272;
P_0c004272: /* original 8b04, guest PC 0x0c010372 */
if(!s->budget--) { s->failed_pc=0x0c004272u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c00427e; }
goto P_0c004274;
P_0c004274: /* original 6052, guest PC 0x0c010374 */
if(!s->budget--) { s->failed_pc=0x0c004274u; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c004276;
P_0c004276: /* original 4021, guest PC 0x0c010376 */
if(!s->budget--) { s->failed_pc=0x0c004276u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c004278;
P_0c004278: /* original 4021, guest PC 0x0c010378 */
if(!s->budget--) { s->failed_pc=0x0c004278u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c00427a;
P_0c00427a: /* original 4028, guest PC 0x0c01037a */
if(!s->budget--) { s->failed_pc=0x0c00427au; return 0; }
r[0]<<=16;
goto P_0c00427c;
P_0c00427c: /* original 240b, guest PC 0x0c01037c */
if(!s->budget--) { s->failed_pc=0x0c00427cu; return 0; }
r[4]|=r[0];
goto P_0c00427e;
P_0c00427e: /* original 9368, guest PC 0x0c01037e */
if(!s->budget--) { s->failed_pc=0x0c00427eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004352u,2);
goto P_0c004280;
P_0c004280: /* original 3430, guest PC 0x0c010380 */
if(!s->budget--) { s->failed_pc=0x0c004280u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c004282;
P_0c004282: /* original 8b04, guest PC 0x0c010382 */
if(!s->budget--) { s->failed_pc=0x0c004282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c00428e; }
goto P_0c004284;
P_0c004284: /* original d236, guest PC 0x0c010384 */
if(!s->budget--) { s->failed_pc=0x0c004284u; return 0; }
r[2]=read(ram,0x0c004360u,4);
goto P_0c004286;
P_0c004286: /* original e1fd, guest PC 0x0c010386 */
if(!s->budget--) { s->failed_pc=0x0c004286u; return 0; }
r[1]=0xfffffffdu;
goto P_0c004288;
P_0c004288: /* original 6022, guest PC 0x0c010388 */
if(!s->budget--) { s->failed_pc=0x0c004288u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c00428a;
P_0c00428a: /* original 2019, guest PC 0x0c01038a */
if(!s->budget--) { s->failed_pc=0x0c00428au; return 0; }
r[0]&=r[1];
goto P_0c00428c;
P_0c00428c: /* original 2202, guest PC 0x0c01038c */
if(!s->budget--) { s->failed_pc=0x0c00428cu; return 0; }
write(ram,r[2],r[0],4);
goto P_0c00428e;
P_0c00428e: /* original d635, guest PC 0x0c01038e */
if(!s->budget--) { s->failed_pc=0x0c00428eu; return 0; }
r[6]=read(ram,0x0c004364u,4);
goto P_0c004290;
P_0c004290: /* original 2448, guest PC 0x0c010390 */
if(!s->budget--) { s->failed_pc=0x0c004290u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c004292;
P_0c004292: /* original 8b00, guest PC 0x0c010392 */
if(!s->budget--) { s->failed_pc=0x0c004292u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004296; }
goto P_0c004294;
P_0c004294: /* original 6462, guest PC 0x0c010394 */
if(!s->budget--) { s->failed_pc=0x0c004294u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c004296;
P_0c004296: /* original d334, guest PC 0x0c010396 */
if(!s->budget--) { s->failed_pc=0x0c004296u; return 0; }
r[3]=read(ram,0x0c004368u,4);
goto P_0c004298;
P_0c004298: /* original e07c, guest PC 0x0c010398 */
if(!s->budget--) { s->failed_pc=0x0c004298u; return 0; }
r[0]=0x0000007cu;
goto P_0c00429a;
P_0c00429a: /* original 6232, guest PC 0x0c01039a */
if(!s->budget--) { s->failed_pc=0x0c00429au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c00429c;
P_0c00429c: /* original 0246, guest PC 0x0c01039c */
if(!s->budget--) { s->failed_pc=0x0c00429cu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c00429e;
P_0c00429e: /* original e400, guest PC 0x0c01039e */
if(!s->budget--) { s->failed_pc=0x0c00429eu; return 0; }
r[4]=0x00000000u;
goto P_0c0042a0;
P_0c0042a0: /* original 2642, guest PC 0x0c0103a0 */
if(!s->budget--) { s->failed_pc=0x0c0042a0u; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0042a2;
P_0c0042a2: /* original d232, guest PC 0x0c0103a2 */
if(!s->budget--) { s->failed_pc=0x0c0042a2u; return 0; }
r[2]=read(ram,0x0c00436cu,4);
goto P_0c0042a4;
P_0c0042a4: /* original 2242, guest PC 0x0c0103a4 */
if(!s->budget--) { s->failed_pc=0x0c0042a4u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0042a6;
P_0c0042a6: /* original 000b, guest PC 0x0c0103a6 */
if(!s->budget--) { s->failed_pc=0x0c0042a6u; return 0; }
target=r[16];
write(ram,r[5],r[4],4);
s->pc=target; return ram->oob==0;
P_0c0042a8: /* original 2542, guest PC 0x0c0103a8 */
if(!s->budget--) { s->failed_pc=0x0c0042a8u; return 0; }
write(ram,r[5],r[4],4);
if(!vf3_matrix_family(0x0c0042aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0042aau; return 0; } return 1;
P_0c0044d4: /* original 2fe6, guest PC 0x0c0105d4 */
if(!s->budget--) { s->failed_pc=0x0c0044d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0044d6;
P_0c0044d6: /* original d43b, guest PC 0x0c0105d6 */
if(!s->budget--) { s->failed_pc=0x0c0044d6u; return 0; }
r[4]=read(ram,0x0c0045c4u,4);
goto P_0c0044d8;
P_0c0044d8: /* original 9272, guest PC 0x0c0105d8 */
if(!s->budget--) { s->failed_pc=0x0c0044d8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0045c0u,2);
goto P_0c0044da;
P_0c0044da: /* original 6342, guest PC 0x0c0105da */
if(!s->budget--) { s->failed_pc=0x0c0044dau; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0044dc;
P_0c0044dc: /* original 2328, guest PC 0x0c0105dc */
if(!s->budget--) { s->failed_pc=0x0c0044dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c0044de;
P_0c0044de: /* original 7301, guest PC 0x0c0105de */
if(!s->budget--) { s->failed_pc=0x0c0044deu; return 0; }
r[3]+=0x00000001u;
goto P_0c0044e0;
P_0c0044e0: /* original 8f24, guest PC 0x0c0105e0 */
if(!s->budget--) { s->failed_pc=0x0c0044e0u; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[3],4);
if(!cond) { goto P_0c00452c; }
goto P_0c0044e4;
P_0c0044e2: /* original 2432, guest PC 0x0c0105e2 */
if(!s->budget--) { s->failed_pc=0x0c0044e2u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0044e4;
P_0c0044e4: /* original d438, guest PC 0x0c0105e4 */
if(!s->budget--) { s->failed_pc=0x0c0044e4u; return 0; }
r[4]=read(ram,0x0c0045c8u,4);
goto P_0c0044e6;
P_0c0044e6: /* original de39, guest PC 0x0c0105e6 */
if(!s->budget--) { s->failed_pc=0x0c0044e6u; return 0; }
r[14]=read(ram,0x0c0045ccu,4);
goto P_0c0044e8;
P_0c0044e8: /* original 6342, guest PC 0x0c0105e8 */
if(!s->budget--) { s->failed_pc=0x0c0044e8u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0044ea;
P_0c0044ea: /* original 2338, guest PC 0x0c0105ea */
if(!s->budget--) { s->failed_pc=0x0c0044eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0044ec;
P_0c0044ec: /* original 8b03, guest PC 0x0c0105ec */
if(!s->budget--) { s->failed_pc=0x0c0044ecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0044f6; }
goto P_0c0044ee;
P_0c0044ee: /* original 63e0, guest PC 0x0c0105ee */
if(!s->budget--) { s->failed_pc=0x0c0044eeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c0044f0;
P_0c0044f0: /* original 4300, guest PC 0x0c0105f0 */
if(!s->budget--) { s->failed_pc=0x0c0044f0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0044f2;
P_0c0044f2: /* original a004, guest PC 0x0c0105f2 */
if(!s->budget--) { s->failed_pc=0x0c0044f2u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c0044fe;
P_0c0044f4: /* original 2e30, guest PC 0x0c0105f4 */
if(!s->budget--) { s->failed_pc=0x0c0044f4u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c0044f6;
P_0c0044f6: /* original 60e0, guest PC 0x0c0105f6 */
if(!s->budget--) { s->failed_pc=0x0c0044f6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c0044f8;
P_0c0044f8: /* original 600c, guest PC 0x0c0105f8 */
if(!s->budget--) { s->failed_pc=0x0c0044f8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0044fa;
P_0c0044fa: /* original 4001, guest PC 0x0c0105fa */
if(!s->budget--) { s->failed_pc=0x0c0044fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0044fc;
P_0c0044fc: /* original 2e00, guest PC 0x0c0105fc */
if(!s->budget--) { s->failed_pc=0x0c0044fcu; return 0; }
write(ram,r[14],r[0],1);
goto P_0c0044fe;
P_0c0044fe: /* original 63e0, guest PC 0x0c0105fe */
if(!s->budget--) { s->failed_pc=0x0c0044feu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c004500;
P_0c004500: /* original 2338, guest PC 0x0c010600 */
if(!s->budget--) { s->failed_pc=0x0c004500u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c004502;
P_0c004502: /* original 8b09, guest PC 0x0c010602 */
if(!s->budget--) { s->failed_pc=0x0c004502u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004518; }
goto P_0c004504;
P_0c004504: /* original 6242, guest PC 0x0c010604 */
if(!s->budget--) { s->failed_pc=0x0c004504u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c004506;
P_0c004506: /* original 2228, guest PC 0x0c010606 */
if(!s->budget--) { s->failed_pc=0x0c004506u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c004508;
P_0c004508: /* original 8901, guest PC 0x0c010608 */
if(!s->budget--) { s->failed_pc=0x0c004508u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c00450e; }
goto P_0c00450a;
P_0c00450a: /* original a001, guest PC 0x0c01060a */
if(!s->budget--) { s->failed_pc=0x0c00450au; return 0; }
r[3]=0x00000001u;
goto P_0c004510;
P_0c00450c: /* original e301, guest PC 0x0c01060c */
if(!s->budget--) { s->failed_pc=0x0c00450cu; return 0; }
r[3]=0x00000001u;
goto P_0c00450e;
P_0c00450e: /* original 9358, guest PC 0x0c01060e */
if(!s->budget--) { s->failed_pc=0x0c00450eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0045c2u,2);
goto P_0c004510;
P_0c004510: /* original 2e30, guest PC 0x0c010610 */
if(!s->budget--) { s->failed_pc=0x0c004510u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c004512;
P_0c004512: /* original 6142, guest PC 0x0c010612 */
if(!s->budget--) { s->failed_pc=0x0c004512u; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c004514;
P_0c004514: /* original 6117, guest PC 0x0c010614 */
if(!s->budget--) { s->failed_pc=0x0c004514u; return 0; }
r[1]=~r[1];
goto P_0c004516;
P_0c004516: /* original 2412, guest PC 0x0c010616 */
if(!s->budget--) { s->failed_pc=0x0c004516u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c004518;
P_0c004518: /* original d32d, guest PC 0x0c010618 */
if(!s->budget--) { s->failed_pc=0x0c004518u; return 0; }
r[3]=read(ram,0x0c0045d0u,4);
goto P_0c00451a;
P_0c00451a: /* original c700, guest PC 0x0c01061a */
if(!s->budget--) { s->failed_pc=0x0c00451au; return 0; }
r[0]=code_base|0x0000451cu;
goto P_0c00451c;
P_0c00451c: /* original 64e0, guest PC 0x0c01061c */
if(!s->budget--) { s->failed_pc=0x0c00451cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c00451e;
P_0c00451e: /* original 330c, guest PC 0x0c01061e */
if(!s->budget--) { s->failed_pc=0x0c00451eu; return 0; }
r[3]+=r[0];
goto P_0c004520;
P_0c004520: /* original d22c, guest PC 0x0c010620 */
if(!s->budget--) { s->failed_pc=0x0c004520u; return 0; }
r[2]=read(ram,0x0c0045d4u,4);
goto P_0c004522;
P_0c004522: /* original 6133, guest PC 0x0c010622 */
if(!s->budget--) { s->failed_pc=0x0c004522u; return 0; }
r[1]=r[3];
goto P_0c004524;
P_0c004524: /* original 644c, guest PC 0x0c010624 */
if(!s->budget--) { s->failed_pc=0x0c004524u; return 0; }
r[4]=r[4]&255u;
goto P_0c004526;
P_0c004526: /* original 212b, guest PC 0x0c010626 */
if(!s->budget--) { s->failed_pc=0x0c004526u; return 0; }
r[1]|=r[2];
goto P_0c004528;
P_0c004528: /* original 412b, guest PC 0x0c010628 */
if(!s->budget--) { s->failed_pc=0x0c004528u; return 0; }
target=r[1];
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
P_0c00452a: /* original 6ef6, guest PC 0x0c01062a */
if(!s->budget--) { s->failed_pc=0x0c00452au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c00452c;
P_0c00452c: /* original 000b, guest PC 0x0c01062c */
if(!s->budget--) { s->failed_pc=0x0c00452cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c00452e: /* original 6ef6, guest PC 0x0c01062e */
if(!s->budget--) { s->failed_pc=0x0c00452eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c004530;
P_0c004530: /* original 4f22, guest PC 0x0c010630 */
if(!s->budget--) { s->failed_pc=0x0c004530u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c004532;
P_0c004532: /* original d329, guest PC 0x0c010632 */
if(!s->budget--) { s->failed_pc=0x0c004532u; return 0; }
r[3]=read(ram,0x0c0045d8u,4);
goto P_0c004534;
P_0c004534: /* original e400, guest PC 0x0c010634 */
if(!s->budget--) { s->failed_pc=0x0c004534u; return 0; }
r[4]=0x00000000u;
goto P_0c004536;
P_0c004536: /* original 2342, guest PC 0x0c010636 */
if(!s->budget--) { s->failed_pc=0x0c004536u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c004538;
P_0c004538: /* original d228, guest PC 0x0c010638 */
if(!s->budget--) { s->failed_pc=0x0c004538u; return 0; }
r[2]=read(ram,0x0c0045dcu,4);
goto P_0c00453a;
P_0c00453a: /* original 2242, guest PC 0x0c01063a */
if(!s->budget--) { s->failed_pc=0x0c00453au; return 0; }
write(ram,r[2],r[4],4);
goto P_0c00453c;
P_0c00453c: /* original d128, guest PC 0x0c01063c */
if(!s->budget--) { s->failed_pc=0x0c00453cu; return 0; }
r[1]=read(ram,0x0c0045e0u,4);
goto P_0c00453e;
P_0c00453e: /* original 6012, guest PC 0x0c01063e */
if(!s->budget--) { s->failed_pc=0x0c00453eu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c004540;
P_0c004540: /* original c907, guest PC 0x0c010640 */
if(!s->budget--) { s->failed_pc=0x0c004540u; return 0; }
r[0]&=7u;
goto P_0c004542;
P_0c004542: /* original 8807, guest PC 0x0c010642 */
if(!s->budget--) { s->failed_pc=0x0c004542u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c004544;
P_0c004544: /* original 8d0c, guest PC 0x0c010644 */
if(!s->budget--) { s->failed_pc=0x0c004544u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c004560; }
goto P_0c004548;
P_0c004546: /* original 6403, guest PC 0x0c010646 */
if(!s->budget--) { s->failed_pc=0x0c004546u; return 0; }
r[4]=r[0];
goto P_0c004548;
P_0c004548: /* original d326, guest PC 0x0c010648 */
if(!s->budget--) { s->failed_pc=0x0c004548u; return 0; }
r[3]=read(ram,0x0c0045e4u,4);
goto P_0c00454a;
P_0c00454a: /* original c700, guest PC 0x0c01064a */
if(!s->budget--) { s->failed_pc=0x0c00454au; return 0; }
r[0]=code_base|0x0000454cu;
goto P_0c00454c;
P_0c00454c: /* original 330c, guest PC 0x0c01064c */
if(!s->budget--) { s->failed_pc=0x0c00454cu; return 0; }
r[3]+=r[0];
goto P_0c00454e;
P_0c00454e: /* original d021, guest PC 0x0c01064e */
if(!s->budget--) { s->failed_pc=0x0c00454eu; return 0; }
r[0]=read(ram,0x0c0045d4u,4);
goto P_0c004550;
P_0c004550: /* original 230b, guest PC 0x0c010650 */
if(!s->budget--) { s->failed_pc=0x0c004550u; return 0; }
r[3]|=r[0];
goto P_0c004552;
P_0c004552: /* original 430b, guest PC 0x0c010652 */
if(!s->budget--) { s->failed_pc=0x0c004552u; return 0; }
target=r[3];
r[16]=code_base|0x0c004556u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004556u) { target=s->pc; goto dispatch; }
goto P_0c004556;
P_0c004554: /* original 0009, guest PC 0x0c010654 */
if(!s->budget--) { s->failed_pc=0x0c004554u; return 0; }
goto P_0c004556;
P_0c004556: /* original 2008, guest PC 0x0c010656 */
if(!s->budget--) { s->failed_pc=0x0c004556u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c004558;
P_0c004558: /* original 8b02, guest PC 0x0c010658 */
if(!s->budget--) { s->failed_pc=0x0c004558u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004560; }
goto P_0c00455a;
P_0c00455a: /* original d21f, guest PC 0x0c01065a */
if(!s->budget--) { s->failed_pc=0x0c00455au; return 0; }
r[2]=read(ram,0x0c0045d8u,4);
goto P_0c00455c;
P_0c00455c: /* original e301, guest PC 0x0c01065c */
if(!s->budget--) { s->failed_pc=0x0c00455cu; return 0; }
r[3]=0x00000001u;
goto P_0c00455e;
P_0c00455e: /* original 2232, guest PC 0x0c01065e */
if(!s->budget--) { s->failed_pc=0x0c00455eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c004560;
P_0c004560: /* original d121, guest PC 0x0c010660 */
if(!s->budget--) { s->failed_pc=0x0c004560u; return 0; }
r[1]=read(ram,0x0c0045e8u,4);
goto P_0c004562;
P_0c004562: /* original c700, guest PC 0x0c010662 */
if(!s->budget--) { s->failed_pc=0x0c004562u; return 0; }
r[0]=code_base|0x00004564u;
goto P_0c004564;
P_0c004564: /* original d31b, guest PC 0x0c010664 */
if(!s->budget--) { s->failed_pc=0x0c004564u; return 0; }
r[3]=read(ram,0x0c0045d4u,4);
goto P_0c004566;
P_0c004566: /* original 310c, guest PC 0x0c010666 */
if(!s->budget--) { s->failed_pc=0x0c004566u; return 0; }
r[1]+=r[0];
goto P_0c004568;
P_0c004568: /* original d520, guest PC 0x0c010668 */
if(!s->budget--) { s->failed_pc=0x0c004568u; return 0; }
r[5]=read(ram,0x0c0045ecu,4);
goto P_0c00456a;
P_0c00456a: /* original 6213, guest PC 0x0c01066a */
if(!s->budget--) { s->failed_pc=0x0c00456au; return 0; }
r[2]=r[1];
goto P_0c00456c;
P_0c00456c: /* original 223b, guest PC 0x0c01066c */
if(!s->budget--) { s->failed_pc=0x0c00456cu; return 0; }
r[2]|=r[3];
goto P_0c00456e;
P_0c00456e: /* original 420b, guest PC 0x0c01066e */
if(!s->budget--) { s->failed_pc=0x0c00456eu; return 0; }
target=r[2];
r[16]=code_base|0x0c004572u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004572u) { target=s->pc; goto dispatch; }
goto P_0c004572;
P_0c004570: /* original e400, guest PC 0x0c010670 */
if(!s->budget--) { s->failed_pc=0x0c004570u; return 0; }
r[4]=0x00000000u;
goto P_0c004572;
P_0c004572: /* original 2008, guest PC 0x0c010672 */
if(!s->budget--) { s->failed_pc=0x0c004572u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c004574;
P_0c004574: /* original 8b02, guest PC 0x0c010674 */
if(!s->budget--) { s->failed_pc=0x0c004574u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c00457c; }
goto P_0c004576;
P_0c004576: /* original d319, guest PC 0x0c010676 */
if(!s->budget--) { s->failed_pc=0x0c004576u; return 0; }
r[3]=read(ram,0x0c0045dcu,4);
goto P_0c004578;
P_0c004578: /* original e201, guest PC 0x0c010678 */
if(!s->budget--) { s->failed_pc=0x0c004578u; return 0; }
r[2]=0x00000001u;
goto P_0c00457a;
P_0c00457a: /* original 2322, guest PC 0x0c01067a */
if(!s->budget--) { s->failed_pc=0x0c00457au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c00457c;
P_0c00457c: /* original 4f26, guest PC 0x0c01067c */
if(!s->budget--) { s->failed_pc=0x0c00457cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c00457e;
P_0c00457e: /* original 000b, guest PC 0x0c01067e */
if(!s->budget--) { s->failed_pc=0x0c00457eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c004580: /* original 0009, guest PC 0x0c010680 */
if(!s->budget--) { s->failed_pc=0x0c004580u; return 0; }
if(!vf3_matrix_family(0x0c004582u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c004582u; return 0; } return 1;
P_0c00479a: /* original 4f22, guest PC 0x0c01089a */
if(!s->budget--) { s->failed_pc=0x0c00479au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c00479c;
P_0c00479c: /* original 7ffc, guest PC 0x0c01089c */
if(!s->budget--) { s->failed_pc=0x0c00479cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c00479e;
P_0c00479e: /* original d222, guest PC 0x0c01089e */
if(!s->budget--) { s->failed_pc=0x0c00479eu; return 0; }
r[2]=read(ram,0x0c004828u,4);
goto P_0c0047a0;
P_0c0047a0: /* original 2f42, guest PC 0x0c0108a0 */
if(!s->budget--) { s->failed_pc=0x0c0047a0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0047a2;
P_0c0047a2: /* original 6322, guest PC 0x0c0108a2 */
if(!s->budget--) { s->failed_pc=0x0c0047a2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0047a4;
P_0c0047a4: /* original 2338, guest PC 0x0c0108a4 */
if(!s->budget--) { s->failed_pc=0x0c0047a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0047a6;
P_0c0047a6: /* original 8d0c, guest PC 0x0c0108a6 */
if(!s->budget--) { s->failed_pc=0x0c0047a6u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c0047c2; }
goto P_0c0047aa;
P_0c0047a8: /* original e400, guest PC 0x0c0108a8 */
if(!s->budget--) { s->failed_pc=0x0c0047a8u; return 0; }
r[4]=0x00000000u;
goto P_0c0047aa;
P_0c0047aa: /* original 63f2, guest PC 0x0c0108aa */
if(!s->budget--) { s->failed_pc=0x0c0047aau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0047ac;
P_0c0047ac: /* original 2338, guest PC 0x0c0108ac */
if(!s->budget--) { s->failed_pc=0x0c0047acu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0047ae;
P_0c0047ae: /* original 8b08, guest PC 0x0c0108ae */
if(!s->budget--) { s->failed_pc=0x0c0047aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0047c2; }
goto P_0c0047b0;
P_0c0047b0: /* original d31e, guest PC 0x0c0108b0 */
if(!s->budget--) { s->failed_pc=0x0c0047b0u; return 0; }
r[3]=read(ram,0x0c00482cu,4);
goto P_0c0047b2;
P_0c0047b2: /* original c700, guest PC 0x0c0108b2 */
if(!s->budget--) { s->failed_pc=0x0c0047b2u; return 0; }
r[0]=code_base|0x000047b4u;
goto P_0c0047b4;
P_0c0047b4: /* original d215, guest PC 0x0c0108b4 */
if(!s->budget--) { s->failed_pc=0x0c0047b4u; return 0; }
r[2]=read(ram,0x0c00480cu,4);
goto P_0c0047b6;
P_0c0047b6: /* original 330c, guest PC 0x0c0108b6 */
if(!s->budget--) { s->failed_pc=0x0c0047b6u; return 0; }
r[3]+=r[0];
goto P_0c0047b8;
P_0c0047b8: /* original 6133, guest PC 0x0c0108b8 */
if(!s->budget--) { s->failed_pc=0x0c0047b8u; return 0; }
r[1]=r[3];
goto P_0c0047ba;
P_0c0047ba: /* original 212b, guest PC 0x0c0108ba */
if(!s->budget--) { s->failed_pc=0x0c0047bau; return 0; }
r[1]|=r[2];
goto P_0c0047bc;
P_0c0047bc: /* original 410b, guest PC 0x0c0108bc */
if(!s->budget--) { s->failed_pc=0x0c0047bcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0047c0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0047c0u) { target=s->pc; goto dispatch; }
goto P_0c0047c0;
P_0c0047be: /* original 0009, guest PC 0x0c0108be */
if(!s->budget--) { s->failed_pc=0x0c0047beu; return 0; }
goto P_0c0047c0;
P_0c0047c0: /* original 6403, guest PC 0x0c0108c0 */
if(!s->budget--) { s->failed_pc=0x0c0047c0u; return 0; }
r[4]=r[0];
goto P_0c0047c2;
P_0c0047c2: /* original d21b, guest PC 0x0c0108c2 */
if(!s->budget--) { s->failed_pc=0x0c0047c2u; return 0; }
r[2]=read(ram,0x0c004830u,4);
goto P_0c0047c4;
P_0c0047c4: /* original 6322, guest PC 0x0c0108c4 */
if(!s->budget--) { s->failed_pc=0x0c0047c4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0047c6;
P_0c0047c6: /* original 2338, guest PC 0x0c0108c6 */
if(!s->budget--) { s->failed_pc=0x0c0047c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0047c8;
P_0c0047c8: /* original 890b, guest PC 0x0c0108c8 */
if(!s->budget--) { s->failed_pc=0x0c0047c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0047e2; }
goto P_0c0047ca;
P_0c0047ca: /* original 60f2, guest PC 0x0c0108ca */
if(!s->budget--) { s->failed_pc=0x0c0047cau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0047cc;
P_0c0047cc: /* original 8801, guest PC 0x0c0108cc */
if(!s->budget--) { s->failed_pc=0x0c0047ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0047ce;
P_0c0047ce: /* original 8b08, guest PC 0x0c0108ce */
if(!s->budget--) { s->failed_pc=0x0c0047ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0047e2; }
goto P_0c0047d0;
P_0c0047d0: /* original d218, guest PC 0x0c0108d0 */
if(!s->budget--) { s->failed_pc=0x0c0047d0u; return 0; }
r[2]=read(ram,0x0c004834u,4);
goto P_0c0047d2;
P_0c0047d2: /* original c700, guest PC 0x0c0108d2 */
if(!s->budget--) { s->failed_pc=0x0c0047d2u; return 0; }
r[0]=code_base|0x000047d4u;
goto P_0c0047d4;
P_0c0047d4: /* original d30d, guest PC 0x0c0108d4 */
if(!s->budget--) { s->failed_pc=0x0c0047d4u; return 0; }
r[3]=read(ram,0x0c00480cu,4);
goto P_0c0047d6;
P_0c0047d6: /* original 320c, guest PC 0x0c0108d6 */
if(!s->budget--) { s->failed_pc=0x0c0047d6u; return 0; }
r[2]+=r[0];
goto P_0c0047d8;
P_0c0047d8: /* original 6123, guest PC 0x0c0108d8 */
if(!s->budget--) { s->failed_pc=0x0c0047d8u; return 0; }
r[1]=r[2];
goto P_0c0047da;
P_0c0047da: /* original 213b, guest PC 0x0c0108da */
if(!s->budget--) { s->failed_pc=0x0c0047dau; return 0; }
r[1]|=r[3];
goto P_0c0047dc;
P_0c0047dc: /* original 410b, guest PC 0x0c0108dc */
if(!s->budget--) { s->failed_pc=0x0c0047dcu; return 0; }
target=r[1];
r[16]=code_base|0x0c0047e0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0047e0u) { target=s->pc; goto dispatch; }
goto P_0c0047e0;
P_0c0047de: /* original 0009, guest PC 0x0c0108de */
if(!s->budget--) { s->failed_pc=0x0c0047deu; return 0; }
goto P_0c0047e0;
P_0c0047e0: /* original 6403, guest PC 0x0c0108e0 */
if(!s->budget--) { s->failed_pc=0x0c0047e0u; return 0; }
r[4]=r[0];
goto P_0c0047e2;
P_0c0047e2: /* original 7f04, guest PC 0x0c0108e2 */
if(!s->budget--) { s->failed_pc=0x0c0047e2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0047e4;
P_0c0047e4: /* original 4f26, guest PC 0x0c0108e4 */
if(!s->budget--) { s->failed_pc=0x0c0047e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0047e6;
P_0c0047e6: /* original 000b, guest PC 0x0c0108e6 */
if(!s->budget--) { s->failed_pc=0x0c0047e6u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0047e8: /* original 6043, guest PC 0x0c0108e8 */
if(!s->budget--) { s->failed_pc=0x0c0047e8u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c0047eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0047eau; return 0; } return 1;
P_0c0048f6: /* original 4615, guest PC 0x0c0109f6 */
if(!s->budget--) { s->failed_pc=0x0c0048f6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0048f8;
P_0c0048f8: /* original 6753, guest PC 0x0c0109f8 */
if(!s->budget--) { s->failed_pc=0x0c0048f8u; return 0; }
r[7]=r[5];
goto P_0c0048fa;
P_0c0048fa: /* original 6043, guest PC 0x0c0109fa */
if(!s->budget--) { s->failed_pc=0x0c0048fau; return 0; }
r[0]=r[4];
goto P_0c0048fc;
P_0c0048fc: /* original 8f06, guest PC 0x0c0109fc */
if(!s->budget--) { s->failed_pc=0x0c0048fcu; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c00490c; }
goto P_0c004900;
P_0c0048fe: /* original e400, guest PC 0x0c0109fe */
if(!s->budget--) { s->failed_pc=0x0c0048feu; return 0; }
r[4]=0x00000000u;
goto P_0c004900;
P_0c004900: /* original 6376, guest PC 0x0c010a00 */
if(!s->budget--) { s->failed_pc=0x0c004900u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c004902;
P_0c004902: /* original 7401, guest PC 0x0c010a02 */
if(!s->budget--) { s->failed_pc=0x0c004902u; return 0; }
r[4]+=0x00000001u;
goto P_0c004904;
P_0c004904: /* original 3463, guest PC 0x0c010a04 */
if(!s->budget--) { s->failed_pc=0x0c004904u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c004906;
P_0c004906: /* original 2032, guest PC 0x0c010a06 */
if(!s->budget--) { s->failed_pc=0x0c004906u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c004908;
P_0c004908: /* original 8ffa, guest PC 0x0c010a08 */
if(!s->budget--) { s->failed_pc=0x0c004908u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000004u;
if(!cond) { goto P_0c004900; }
goto P_0c00490c;
P_0c00490a: /* original 7004, guest PC 0x0c010a0a */
if(!s->budget--) { s->failed_pc=0x0c00490au; return 0; }
r[0]+=0x00000004u;
goto P_0c00490c;
P_0c00490c: /* original 000b, guest PC 0x0c010a0c */
if(!s->budget--) { s->failed_pc=0x0c00490cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c00490e: /* original 0009, guest PC 0x0c010a0e */
if(!s->budget--) { s->failed_pc=0x0c00490eu; return 0; }
goto P_0c004910;
P_0c004910: /* original 4615, guest PC 0x0c010a10 */
if(!s->budget--) { s->failed_pc=0x0c004910u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c004912;
P_0c004912: /* original 6743, guest PC 0x0c010a12 */
if(!s->budget--) { s->failed_pc=0x0c004912u; return 0; }
r[7]=r[4];
goto P_0c004914;
P_0c004914: /* original 8f05, guest PC 0x0c010a14 */
if(!s->budget--) { s->failed_pc=0x0c004914u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c004922; }
goto P_0c004918;
P_0c004916: /* original e400, guest PC 0x0c010a16 */
if(!s->budget--) { s->failed_pc=0x0c004916u; return 0; }
r[4]=0x00000000u;
goto P_0c004918;
P_0c004918: /* original 7401, guest PC 0x0c010a18 */
if(!s->budget--) { s->failed_pc=0x0c004918u; return 0; }
r[4]+=0x00000001u;
goto P_0c00491a;
P_0c00491a: /* original 2752, guest PC 0x0c010a1a */
if(!s->budget--) { s->failed_pc=0x0c00491au; return 0; }
write(ram,r[7],r[5],4);
goto P_0c00491c;
P_0c00491c: /* original 3463, guest PC 0x0c010a1c */
if(!s->budget--) { s->failed_pc=0x0c00491cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c00491e;
P_0c00491e: /* original 8ffb, guest PC 0x0c010a1e */
if(!s->budget--) { s->failed_pc=0x0c00491eu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c004918; }
goto P_0c004922;
P_0c004920: /* original 7704, guest PC 0x0c010a20 */
if(!s->budget--) { s->failed_pc=0x0c004920u; return 0; }
r[7]+=0x00000004u;
goto P_0c004922;
P_0c004922: /* original 000b, guest PC 0x0c010a22 */
if(!s->budget--) { s->failed_pc=0x0c004922u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c004924: /* original 0009, guest PC 0x0c010a24 */
if(!s->budget--) { s->failed_pc=0x0c004924u; return 0; }
goto P_0c004926;
P_0c004926: /* original d113, guest PC 0x0c010a26 */
if(!s->budget--) { s->failed_pc=0x0c004926u; return 0; }
r[1]=read(ram,0x0c004974u,4);
goto P_0c004928;
P_0c004928: /* original 9312, guest PC 0x0c010a28 */
if(!s->budget--) { s->failed_pc=0x0c004928u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004950u,2);
goto P_0c00492a;
P_0c00492a: /* original 6212, guest PC 0x0c010a2a */
if(!s->budget--) { s->failed_pc=0x0c00492au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c00492c;
P_0c00492c: /* original 3230, guest PC 0x0c010a2c */
if(!s->budget--) { s->failed_pc=0x0c00492cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c00492e;
P_0c00492e: /* original 8902, guest PC 0x0c010a2e */
if(!s->budget--) { s->failed_pc=0x0c00492eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c004936; }
goto P_0c004930;
P_0c004930: /* original d311, guest PC 0x0c010a30 */
if(!s->budget--) { s->failed_pc=0x0c004930u; return 0; }
r[3]=read(ram,0x0c004978u,4);
goto P_0c004932;
P_0c004932: /* original 6447, guest PC 0x0c010a32 */
if(!s->budget--) { s->failed_pc=0x0c004932u; return 0; }
r[4]=~r[4];
goto P_0c004934;
P_0c004934: /* original 2340, guest PC 0x0c010a34 */
if(!s->budget--) { s->failed_pc=0x0c004934u; return 0; }
write(ram,r[3],r[4],1);
goto P_0c004936;
P_0c004936: /* original 000b, guest PC 0x0c010a36 */
if(!s->budget--) { s->failed_pc=0x0c004936u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c004938: /* original 0009, guest PC 0x0c010a38 */
if(!s->budget--) { s->failed_pc=0x0c004938u; return 0; }
if(!vf3_matrix_family(0x0c00493au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c00493au; return 0; } return 1;
P_0c004988: /* original d344, guest PC 0x0c010a88 */
if(!s->budget--) { s->failed_pc=0x0c004988u; return 0; }
r[3]=read(ram,0x0c004a9cu,4);
goto P_0c00498a;
P_0c00498a: /* original e400, guest PC 0x0c010a8a */
if(!s->budget--) { s->failed_pc=0x0c00498au; return 0; }
r[4]=0x00000000u;
goto P_0c00498c;
P_0c00498c: /* original 2342, guest PC 0x0c010a8c */
if(!s->budget--) { s->failed_pc=0x0c00498cu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c00498e;
P_0c00498e: /* original d244, guest PC 0x0c010a8e */
if(!s->budget--) { s->failed_pc=0x0c00498eu; return 0; }
r[2]=read(ram,0x0c004aa0u,4);
goto P_0c004990;
P_0c004990: /* original 2242, guest PC 0x0c010a90 */
if(!s->budget--) { s->failed_pc=0x0c004990u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c004992;
P_0c004992: /* original d144, guest PC 0x0c010a92 */
if(!s->budget--) { s->failed_pc=0x0c004992u; return 0; }
r[1]=read(ram,0x0c004aa4u,4);
goto P_0c004994;
P_0c004994: /* original 000b, guest PC 0x0c010a94 */
if(!s->budget--) { s->failed_pc=0x0c004994u; return 0; }
target=r[16];
write(ram,r[1],r[4],4);
s->pc=target; return ram->oob==0;
P_0c004996: /* original 2142, guest PC 0x0c010a96 */
if(!s->budget--) { s->failed_pc=0x0c004996u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c004998;
P_0c004998: /* original 2fe6, guest PC 0x0c010a98 */
if(!s->budget--) { s->failed_pc=0x0c004998u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c00499a;
P_0c00499a: /* original c702, guest PC 0x0c010a9a */
if(!s->budget--) { s->failed_pc=0x0c00499au; return 0; }
r[0]=code_base|0x000049a4u;
goto P_0c00499c;
P_0c00499c: /* original 2fd6, guest PC 0x0c010a9c */
if(!s->budget--) { s->failed_pc=0x0c00499cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c00499e;
P_0c00499e: /* original 4f22, guest PC 0x0c010a9e */
if(!s->budget--) { s->failed_pc=0x0c00499eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0049a0;
P_0c0049a0: /* original d342, guest PC 0x0c010aa0 */
if(!s->budget--) { s->failed_pc=0x0c0049a0u; return 0; }
r[3]=read(ram,0x0c004aacu,4);
goto P_0c0049a2;
P_0c0049a2: /* original de41, guest PC 0x0c010aa2 */
if(!s->budget--) { s->failed_pc=0x0c0049a2u; return 0; }
r[14]=read(ram,0x0c004aa8u,4);
goto P_0c0049a4;
P_0c0049a4: /* original 330c, guest PC 0x0c010aa4 */
if(!s->budget--) { s->failed_pc=0x0c0049a4u; return 0; }
r[3]+=r[0];
goto P_0c0049a6;
P_0c0049a6: /* original 9676, guest PC 0x0c010aa6 */
if(!s->budget--) { s->failed_pc=0x0c0049a6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004a96u,2);
goto P_0c0049a8;
P_0c0049a8: /* original d441, guest PC 0x0c010aa8 */
if(!s->budget--) { s->failed_pc=0x0c0049a8u; return 0; }
r[4]=read(ram,0x0c004ab0u,4);
goto P_0c0049aa;
P_0c0049aa: /* original 6233, guest PC 0x0c010aaa */
if(!s->budget--) { s->failed_pc=0x0c0049aau; return 0; }
r[2]=r[3];
goto P_0c0049ac;
P_0c0049ac: /* original 22eb, guest PC 0x0c010aac */
if(!s->budget--) { s->failed_pc=0x0c0049acu; return 0; }
r[2]|=r[14];
goto P_0c0049ae;
P_0c0049ae: /* original 420b, guest PC 0x0c010aae */
if(!s->budget--) { s->failed_pc=0x0c0049aeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0049b2u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0049b2u) { target=s->pc; goto dispatch; }
goto P_0c0049b2;
P_0c0049b0: /* original e500, guest PC 0x0c010ab0 */
if(!s->budget--) { s->failed_pc=0x0c0049b0u; return 0; }
r[5]=0x00000000u;
goto P_0c0049b2;
P_0c0049b2: /* original d340, guest PC 0x0c010ab2 */
if(!s->budget--) { s->failed_pc=0x0c0049b2u; return 0; }
r[3]=read(ram,0x0c004ab4u,4);
goto P_0c0049b4;
P_0c0049b4: /* original c700, guest PC 0x0c010ab4 */
if(!s->budget--) { s->failed_pc=0x0c0049b4u; return 0; }
r[0]=code_base|0x000049b8u;
goto P_0c0049b6;
P_0c0049b6: /* original 330c, guest PC 0x0c010ab6 */
if(!s->budget--) { s->failed_pc=0x0c0049b6u; return 0; }
r[3]+=r[0];
goto P_0c0049b8;
P_0c0049b8: /* original 966e, guest PC 0x0c010ab8 */
if(!s->budget--) { s->failed_pc=0x0c0049b8u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004a98u,2);
goto P_0c0049ba;
P_0c0049ba: /* original 6233, guest PC 0x0c010aba */
if(!s->budget--) { s->failed_pc=0x0c0049bau; return 0; }
r[2]=r[3];
goto P_0c0049bc;
P_0c0049bc: /* original d43e, guest PC 0x0c010abc */
if(!s->budget--) { s->failed_pc=0x0c0049bcu; return 0; }
r[4]=read(ram,0x0c004ab8u,4);
goto P_0c0049be;
P_0c0049be: /* original 22eb, guest PC 0x0c010abe */
if(!s->budget--) { s->failed_pc=0x0c0049beu; return 0; }
r[2]|=r[14];
goto P_0c0049c0;
P_0c0049c0: /* original 420b, guest PC 0x0c010ac0 */
if(!s->budget--) { s->failed_pc=0x0c0049c0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0049c4u;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0049c4u) { target=s->pc; goto dispatch; }
goto P_0c0049c4;
P_0c0049c2: /* original e500, guest PC 0x0c010ac2 */
if(!s->budget--) { s->failed_pc=0x0c0049c2u; return 0; }
r[5]=0x00000000u;
goto P_0c0049c4;
P_0c0049c4: /* original d33e, guest PC 0x0c010ac4 */
if(!s->budget--) { s->failed_pc=0x0c0049c4u; return 0; }
r[3]=read(ram,0x0c004ac0u,4);
goto P_0c0049c6;
P_0c0049c6: /* original c701, guest PC 0x0c010ac6 */
if(!s->budget--) { s->failed_pc=0x0c0049c6u; return 0; }
r[0]=code_base|0x000049ccu;
goto P_0c0049c8;
P_0c0049c8: /* original dd3c, guest PC 0x0c010ac8 */
if(!s->budget--) { s->failed_pc=0x0c0049c8u; return 0; }
r[13]=read(ram,0x0c004abcu,4);
goto P_0c0049ca;
P_0c0049ca: /* original 330c, guest PC 0x0c010aca */
if(!s->budget--) { s->failed_pc=0x0c0049cau; return 0; }
r[3]+=r[0];
goto P_0c0049cc;
P_0c0049cc: /* original d53d, guest PC 0x0c010acc */
if(!s->budget--) { s->failed_pc=0x0c0049ccu; return 0; }
r[5]=read(ram,0x0c004ac4u,4);
goto P_0c0049ce;
P_0c0049ce: /* original c702, guest PC 0x0c010ace */
if(!s->budget--) { s->failed_pc=0x0c0049ceu; return 0; }
r[0]=code_base|0x000049d8u;
goto P_0c0049d0;
P_0c0049d0: /* original 6233, guest PC 0x0c010ad0 */
if(!s->budget--) { s->failed_pc=0x0c0049d0u; return 0; }
r[2]=r[3];
goto P_0c0049d2;
P_0c0049d2: /* original 22eb, guest PC 0x0c010ad2 */
if(!s->budget--) { s->failed_pc=0x0c0049d2u; return 0; }
r[2]|=r[14];
goto P_0c0049d4;
P_0c0049d4: /* original 350c, guest PC 0x0c010ad4 */
if(!s->budget--) { s->failed_pc=0x0c0049d4u; return 0; }
r[5]+=r[0];
goto P_0c0049d6;
P_0c0049d6: /* original e608, guest PC 0x0c010ad6 */
if(!s->budget--) { s->failed_pc=0x0c0049d6u; return 0; }
r[6]=0x00000008u;
goto P_0c0049d8;
P_0c0049d8: /* original 420b, guest PC 0x0c010ad8 */
if(!s->budget--) { s->failed_pc=0x0c0049d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0049dcu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0049dcu) { target=s->pc; goto dispatch; }
goto P_0c0049dc;
P_0c0049da: /* original 64d3, guest PC 0x0c010ada */
if(!s->budget--) { s->failed_pc=0x0c0049dau; return 0; }
r[4]=r[13];
goto P_0c0049dc;
P_0c0049dc: /* original d33a, guest PC 0x0c010adc */
if(!s->budget--) { s->failed_pc=0x0c0049dcu; return 0; }
r[3]=read(ram,0x0c004ac8u,4);
goto P_0c0049de;
P_0c0049de: /* original c700, guest PC 0x0c010ade */
if(!s->budget--) { s->failed_pc=0x0c0049deu; return 0; }
r[0]=code_base|0x000049e0u;
goto P_0c0049e0;
P_0c0049e0: /* original d23a, guest PC 0x0c010ae0 */
if(!s->budget--) { s->failed_pc=0x0c0049e0u; return 0; }
r[2]=read(ram,0x0c004accu,4);
goto P_0c0049e2;
P_0c0049e2: /* original 330c, guest PC 0x0c010ae2 */
if(!s->budget--) { s->failed_pc=0x0c0049e2u; return 0; }
r[3]+=r[0];
goto P_0c0049e4;
P_0c0049e4: /* original c700, guest PC 0x0c010ae4 */
if(!s->budget--) { s->failed_pc=0x0c0049e4u; return 0; }
r[0]=code_base|0x000049e8u;
goto P_0c0049e6;
P_0c0049e6: /* original 320c, guest PC 0x0c010ae6 */
if(!s->budget--) { s->failed_pc=0x0c0049e6u; return 0; }
r[2]+=r[0];
goto P_0c0049e8;
P_0c0049e8: /* original 3328, guest PC 0x0c010ae8 */
if(!s->budget--) { s->failed_pc=0x0c0049e8u; return 0; }
r[3]-=r[2];
goto P_0c0049ea;
P_0c0049ea: /* original d239, guest PC 0x0c010aea */
if(!s->budget--) { s->failed_pc=0x0c0049eau; return 0; }
r[2]=read(ram,0x0c004ad0u,4);
goto P_0c0049ec;
P_0c0049ec: /* original 33dc, guest PC 0x0c010aec */
if(!s->budget--) { s->failed_pc=0x0c0049ecu; return 0; }
r[3]+=r[13];
goto P_0c0049ee;
P_0c0049ee: /* original 2322, guest PC 0x0c010aee */
if(!s->budget--) { s->failed_pc=0x0c0049eeu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c0049f0;
P_0c0049f0: /* original c700, guest PC 0x0c010af0 */
if(!s->budget--) { s->failed_pc=0x0c0049f0u; return 0; }
r[0]=code_base|0x000049f4u;
goto P_0c0049f2;
P_0c0049f2: /* original d338, guest PC 0x0c010af2 */
if(!s->budget--) { s->failed_pc=0x0c0049f2u; return 0; }
r[3]=read(ram,0x0c004ad4u,4);
goto P_0c0049f4;
P_0c0049f4: /* original d238, guest PC 0x0c010af4 */
if(!s->budget--) { s->failed_pc=0x0c0049f4u; return 0; }
r[2]=read(ram,0x0c004ad8u,4);
goto P_0c0049f6;
P_0c0049f6: /* original 330c, guest PC 0x0c010af6 */
if(!s->budget--) { s->failed_pc=0x0c0049f6u; return 0; }
r[3]+=r[0];
goto P_0c0049f8;
P_0c0049f8: /* original c700, guest PC 0x0c010af8 */
if(!s->budget--) { s->failed_pc=0x0c0049f8u; return 0; }
r[0]=code_base|0x000049fcu;
goto P_0c0049fa;
P_0c0049fa: /* original 23d2, guest PC 0x0c010afa */
if(!s->budget--) { s->failed_pc=0x0c0049fau; return 0; }
write(ram,r[3],r[13],4);
goto P_0c0049fc;
P_0c0049fc: /* original d337, guest PC 0x0c010afc */
if(!s->budget--) { s->failed_pc=0x0c0049fcu; return 0; }
r[3]=read(ram,0x0c004adcu,4);
goto P_0c0049fe;
P_0c0049fe: /* original 320c, guest PC 0x0c010afe */
if(!s->budget--) { s->failed_pc=0x0c0049feu; return 0; }
r[2]+=r[0];
goto P_0c004a00;
P_0c004a00: /* original c701, guest PC 0x0c010b00 */
if(!s->budget--) { s->failed_pc=0x0c004a00u; return 0; }
r[0]=code_base|0x00004a08u;
goto P_0c004a02;
P_0c004a02: /* original 2232, guest PC 0x0c010b02 */
if(!s->budget--) { s->failed_pc=0x0c004a02u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c004a04;
P_0c004a04: /* original d236, guest PC 0x0c010b04 */
if(!s->budget--) { s->failed_pc=0x0c004a04u; return 0; }
r[2]=read(ram,0x0c004ae0u,4);
goto P_0c004a06;
P_0c004a06: /* original 320c, guest PC 0x0c010b06 */
if(!s->budget--) { s->failed_pc=0x0c004a06u; return 0; }
r[2]+=r[0];
goto P_0c004a08;
P_0c004a08: /* original dd36, guest PC 0x0c010b08 */
if(!s->budget--) { s->failed_pc=0x0c004a08u; return 0; }
r[13]=read(ram,0x0c004ae4u,4);
goto P_0c004a0a;
P_0c004a0a: /* original c702, guest PC 0x0c010b0a */
if(!s->budget--) { s->failed_pc=0x0c004a0au; return 0; }
r[0]=code_base|0x00004a14u;
goto P_0c004a0c;
P_0c004a0c: /* original 6323, guest PC 0x0c010b0c */
if(!s->budget--) { s->failed_pc=0x0c004a0cu; return 0; }
r[3]=r[2];
goto P_0c004a0e;
P_0c004a0e: /* original 23eb, guest PC 0x0c010b0e */
if(!s->budget--) { s->failed_pc=0x0c004a0eu; return 0; }
r[3]|=r[14];
goto P_0c004a10;
P_0c004a10: /* original 3d0c, guest PC 0x0c010b10 */
if(!s->budget--) { s->failed_pc=0x0c004a10u; return 0; }
r[13]+=r[0];
goto P_0c004a12;
P_0c004a12: /* original e608, guest PC 0x0c010b12 */
if(!s->budget--) { s->failed_pc=0x0c004a12u; return 0; }
r[6]=0x00000008u;
goto P_0c004a14;
P_0c004a14: /* original d434, guest PC 0x0c010b14 */
if(!s->budget--) { s->failed_pc=0x0c004a14u; return 0; }
r[4]=read(ram,0x0c004ae8u,4);
goto P_0c004a16;
P_0c004a16: /* original 430b, guest PC 0x0c010b16 */
if(!s->budget--) { s->failed_pc=0x0c004a16u; return 0; }
target=r[3];
r[16]=code_base|0x0c004a1au;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004a1au) { target=s->pc; goto dispatch; }
goto P_0c004a1a;
P_0c004a18: /* original 65d3, guest PC 0x0c010b18 */
if(!s->budget--) { s->failed_pc=0x0c004a18u; return 0; }
r[5]=r[13];
goto P_0c004a1a;
P_0c004a1a: /* original d234, guest PC 0x0c010b1a */
if(!s->budget--) { s->failed_pc=0x0c004a1au; return 0; }
r[2]=read(ram,0x0c004aecu,4);
goto P_0c004a1c;
P_0c004a1c: /* original c700, guest PC 0x0c010b1c */
if(!s->budget--) { s->failed_pc=0x0c004a1cu; return 0; }
r[0]=code_base|0x00004a20u;
goto P_0c004a1e;
P_0c004a1e: /* original 320c, guest PC 0x0c010b1e */
if(!s->budget--) { s->failed_pc=0x0c004a1eu; return 0; }
r[2]+=r[0];
goto P_0c004a20;
P_0c004a20: /* original d433, guest PC 0x0c010b20 */
if(!s->budget--) { s->failed_pc=0x0c004a20u; return 0; }
r[4]=read(ram,0x0c004af0u,4);
goto P_0c004a22;
P_0c004a22: /* original 6323, guest PC 0x0c010b22 */
if(!s->budget--) { s->failed_pc=0x0c004a22u; return 0; }
r[3]=r[2];
goto P_0c004a24;
P_0c004a24: /* original e608, guest PC 0x0c010b24 */
if(!s->budget--) { s->failed_pc=0x0c004a24u; return 0; }
r[6]=0x00000008u;
goto P_0c004a26;
P_0c004a26: /* original 23eb, guest PC 0x0c010b26 */
if(!s->budget--) { s->failed_pc=0x0c004a26u; return 0; }
r[3]|=r[14];
goto P_0c004a28;
P_0c004a28: /* original 430b, guest PC 0x0c010b28 */
if(!s->budget--) { s->failed_pc=0x0c004a28u; return 0; }
target=r[3];
r[16]=code_base|0x0c004a2cu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004a2cu) { target=s->pc; goto dispatch; }
goto P_0c004a2c;
P_0c004a2a: /* original 65d3, guest PC 0x0c010b2a */
if(!s->budget--) { s->failed_pc=0x0c004a2au; return 0; }
r[5]=r[13];
goto P_0c004a2c;
P_0c004a2c: /* original d231, guest PC 0x0c010b2c */
if(!s->budget--) { s->failed_pc=0x0c004a2cu; return 0; }
r[2]=read(ram,0x0c004af4u,4);
goto P_0c004a2e;
P_0c004a2e: /* original c700, guest PC 0x0c010b2e */
if(!s->budget--) { s->failed_pc=0x0c004a2eu; return 0; }
r[0]=code_base|0x00004a30u;
goto P_0c004a30;
P_0c004a30: /* original 320c, guest PC 0x0c010b30 */
if(!s->budget--) { s->failed_pc=0x0c004a30u; return 0; }
r[2]+=r[0];
goto P_0c004a32;
P_0c004a32: /* original d431, guest PC 0x0c010b32 */
if(!s->budget--) { s->failed_pc=0x0c004a32u; return 0; }
r[4]=read(ram,0x0c004af8u,4);
goto P_0c004a34;
P_0c004a34: /* original 6323, guest PC 0x0c010b34 */
if(!s->budget--) { s->failed_pc=0x0c004a34u; return 0; }
r[3]=r[2];
goto P_0c004a36;
P_0c004a36: /* original e608, guest PC 0x0c010b36 */
if(!s->budget--) { s->failed_pc=0x0c004a36u; return 0; }
r[6]=0x00000008u;
goto P_0c004a38;
P_0c004a38: /* original 2e3b, guest PC 0x0c010b38 */
if(!s->budget--) { s->failed_pc=0x0c004a38u; return 0; }
r[14]|=r[3];
goto P_0c004a3a;
P_0c004a3a: /* original 4e0b, guest PC 0x0c010b3a */
if(!s->budget--) { s->failed_pc=0x0c004a3au; return 0; }
target=r[14];
r[16]=code_base|0x0c004a3eu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004a3eu) { target=s->pc; goto dispatch; }
goto P_0c004a3e;
P_0c004a3c: /* original 65d3, guest PC 0x0c010b3c */
if(!s->budget--) { s->failed_pc=0x0c004a3cu; return 0; }
r[5]=r[13];
goto P_0c004a3e;
P_0c004a3e: /* original d62f, guest PC 0x0c010b3e */
if(!s->budget--) { s->failed_pc=0x0c004a3eu; return 0; }
r[6]=read(ram,0x0c004afcu,4);
goto P_0c004a40;
P_0c004a40: /* original c700, guest PC 0x0c010b40 */
if(!s->budget--) { s->failed_pc=0x0c004a40u; return 0; }
r[0]=code_base|0x00004a44u;
goto P_0c004a42;
P_0c004a42: /* original 360c, guest PC 0x0c010b42 */
if(!s->budget--) { s->failed_pc=0x0c004a42u; return 0; }
r[6]+=r[0];
goto P_0c004a44;
P_0c004a44: /* original d42f, guest PC 0x0c010b44 */
if(!s->budget--) { s->failed_pc=0x0c004a44u; return 0; }
r[4]=read(ram,0x0c004b04u,4);
goto P_0c004a46;
P_0c004a46: /* original c701, guest PC 0x0c010b46 */
if(!s->budget--) { s->failed_pc=0x0c004a46u; return 0; }
r[0]=code_base|0x00004a4cu;
goto P_0c004a48;
P_0c004a48: /* original d52d, guest PC 0x0c010b48 */
if(!s->budget--) { s->failed_pc=0x0c004a48u; return 0; }
r[5]=read(ram,0x0c004b00u,4);
goto P_0c004a4a;
P_0c004a4a: /* original 340c, guest PC 0x0c010b4a */
if(!s->budget--) { s->failed_pc=0x0c004a4au; return 0; }
r[4]+=r[0];
goto P_0c004a4c;
P_0c004a4c: /* original d32e, guest PC 0x0c010b4c */
if(!s->budget--) { s->failed_pc=0x0c004a4cu; return 0; }
r[3]=read(ram,0x0c004b08u,4);
goto P_0c004a4e;
P_0c004a4e: /* original c700, guest PC 0x0c010b4e */
if(!s->budget--) { s->failed_pc=0x0c004a4eu; return 0; }
r[0]=code_base|0x00004a50u;
goto P_0c004a50;
P_0c004a50: /* original 330c, guest PC 0x0c010b50 */
if(!s->budget--) { s->failed_pc=0x0c004a50u; return 0; }
r[3]+=r[0];
goto P_0c004a52;
P_0c004a52: /* original d225, guest PC 0x0c010b52 */
if(!s->budget--) { s->failed_pc=0x0c004a52u; return 0; }
r[2]=read(ram,0x0c004ae8u,4);
goto P_0c004a54;
P_0c004a54: /* original 3438, guest PC 0x0c010b54 */
if(!s->budget--) { s->failed_pc=0x0c004a54u; return 0; }
r[4]-=r[3];
goto P_0c004a56;
P_0c004a56: /* original 6363, guest PC 0x0c010b56 */
if(!s->budget--) { s->failed_pc=0x0c004a56u; return 0; }
r[3]=r[6];
goto P_0c004a58;
P_0c004a58: /* original 2359, guest PC 0x0c010b58 */
if(!s->budget--) { s->failed_pc=0x0c004a58u; return 0; }
r[3]&=r[5];
goto P_0c004a5a;
P_0c004a5a: /* original 324c, guest PC 0x0c010b5a */
if(!s->budget--) { s->failed_pc=0x0c004a5au; return 0; }
r[2]+=r[4];
goto P_0c004a5c;
P_0c004a5c: /* original 2232, guest PC 0x0c010b5c */
if(!s->budget--) { s->failed_pc=0x0c004a5cu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c004a5e;
P_0c004a5e: /* original 2659, guest PC 0x0c010b5e */
if(!s->budget--) { s->failed_pc=0x0c004a5eu; return 0; }
r[6]&=r[5];
goto P_0c004a60;
P_0c004a60: /* original d223, guest PC 0x0c010b60 */
if(!s->budget--) { s->failed_pc=0x0c004a60u; return 0; }
r[2]=read(ram,0x0c004af0u,4);
goto P_0c004a62;
P_0c004a62: /* original c703, guest PC 0x0c010b62 */
if(!s->budget--) { s->failed_pc=0x0c004a62u; return 0; }
r[0]=code_base|0x00004a70u;
goto P_0c004a64;
P_0c004a64: /* original 324c, guest PC 0x0c010b64 */
if(!s->budget--) { s->failed_pc=0x0c004a64u; return 0; }
r[2]+=r[4];
goto P_0c004a66;
P_0c004a66: /* original 2262, guest PC 0x0c010b66 */
if(!s->budget--) { s->failed_pc=0x0c004a66u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c004a68;
P_0c004a68: /* original d228, guest PC 0x0c010b68 */
if(!s->budget--) { s->failed_pc=0x0c004a68u; return 0; }
r[2]=read(ram,0x0c004b0cu,4);
goto P_0c004a6a;
P_0c004a6a: /* original d323, guest PC 0x0c010b6a */
if(!s->budget--) { s->failed_pc=0x0c004a6au; return 0; }
r[3]=read(ram,0x0c004af8u,4);
goto P_0c004a6c;
P_0c004a6c: /* original 320c, guest PC 0x0c010b6c */
if(!s->budget--) { s->failed_pc=0x0c004a6cu; return 0; }
r[2]+=r[0];
goto P_0c004a6e;
P_0c004a6e: /* original 343c, guest PC 0x0c010b6e */
if(!s->budget--) { s->failed_pc=0x0c004a6eu; return 0; }
r[4]+=r[3];
goto P_0c004a70;
P_0c004a70: /* original 6123, guest PC 0x0c010b70 */
if(!s->budget--) { s->failed_pc=0x0c004a70u; return 0; }
r[1]=r[2];
goto P_0c004a72;
P_0c004a72: /* original 2519, guest PC 0x0c010b72 */
if(!s->budget--) { s->failed_pc=0x0c004a72u; return 0; }
r[5]&=r[1];
goto P_0c004a74;
P_0c004a74: /* original 2452, guest PC 0x0c010b74 */
if(!s->budget--) { s->failed_pc=0x0c004a74u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c004a76;
P_0c004a76: /* original e642, guest PC 0x0c010b76 */
if(!s->budget--) { s->failed_pc=0x0c004a76u; return 0; }
r[6]=0x00000042u;
goto P_0c004a78;
P_0c004a78: /* original d425, guest PC 0x0c010b78 */
if(!s->budget--) { s->failed_pc=0x0c004a78u; return 0; }
r[4]=read(ram,0x0c004b10u,4);
goto P_0c004a7a;
P_0c004a7a: /* original e500, guest PC 0x0c010b7a */
if(!s->budget--) { s->failed_pc=0x0c004a7au; return 0; }
r[5]=0x00000000u;
goto P_0c004a7c;
P_0c004a7c: /* original d325, guest PC 0x0c010b7c */
if(!s->budget--) { s->failed_pc=0x0c004a7cu; return 0; }
r[3]=read(ram,0x0c004b14u,4);
goto P_0c004a7e;
P_0c004a7e: /* original c700, guest PC 0x0c010b7e */
if(!s->budget--) { s->failed_pc=0x0c004a7eu; return 0; }
r[0]=code_base|0x00004a80u;
goto P_0c004a80;
P_0c004a80: /* original 7501, guest PC 0x0c010b80 */
if(!s->budget--) { s->failed_pc=0x0c004a80u; return 0; }
r[5]+=0x00000001u;
goto P_0c004a82;
P_0c004a82: /* original 330c, guest PC 0x0c010b82 */
if(!s->budget--) { s->failed_pc=0x0c004a82u; return 0; }
r[3]+=r[0];
goto P_0c004a84;
P_0c004a84: /* original 3563, guest PC 0x0c010b84 */
if(!s->budget--) { s->failed_pc=0x0c004a84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c004a86;
P_0c004a86: /* original 6233, guest PC 0x0c010b86 */
if(!s->budget--) { s->failed_pc=0x0c004a86u; return 0; }
r[2]=r[3];
goto P_0c004a88;
P_0c004a88: /* original 2432, guest PC 0x0c010b88 */
if(!s->budget--) { s->failed_pc=0x0c004a88u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c004a8a;
P_0c004a8a: /* original 8ff7, guest PC 0x0c010b8a */
if(!s->budget--) { s->failed_pc=0x0c004a8au; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c004a7c; }
goto P_0c004a8e;
P_0c004a8c: /* original 7404, guest PC 0x0c010b8c */
if(!s->budget--) { s->failed_pc=0x0c004a8cu; return 0; }
r[4]+=0x00000004u;
goto P_0c004a8e;
P_0c004a8e: /* original 4f26, guest PC 0x0c010b8e */
if(!s->budget--) { s->failed_pc=0x0c004a8eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c004a90;
P_0c004a90: /* original 6df6, guest PC 0x0c010b90 */
if(!s->budget--) { s->failed_pc=0x0c004a90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c004a92;
P_0c004a92: /* original 000b, guest PC 0x0c010b92 */
if(!s->budget--) { s->failed_pc=0x0c004a92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c004a94: /* original 6ef6, guest PC 0x0c010b94 */
if(!s->budget--) { s->failed_pc=0x0c004a94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c004a96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c004a96u; return 0; } return 1;
P_0c004b18: /* original 2fe6, guest PC 0x0c010c18 */
if(!s->budget--) { s->failed_pc=0x0c004b18u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b1a;
P_0c004b1a: /* original e642, guest PC 0x0c010c1a */
if(!s->budget--) { s->failed_pc=0x0c004b1au; return 0; }
r[6]=0x00000042u;
goto P_0c004b1c;
P_0c004b1c: /* original 2fd6, guest PC 0x0c010c1c */
if(!s->budget--) { s->failed_pc=0x0c004b1cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b1e;
P_0c004b1e: /* original 2fc6, guest PC 0x0c010c1e */
if(!s->budget--) { s->failed_pc=0x0c004b1eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b20;
P_0c004b20: /* original ec00, guest PC 0x0c010c20 */
if(!s->budget--) { s->failed_pc=0x0c004b20u; return 0; }
r[12]=0x00000000u;
goto P_0c004b22;
P_0c004b22: /* original 2fb6, guest PC 0x0c010c22 */
if(!s->budget--) { s->failed_pc=0x0c004b22u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b24;
P_0c004b24: /* original 64c3, guest PC 0x0c010c24 */
if(!s->budget--) { s->failed_pc=0x0c004b24u; return 0; }
r[4]=r[12];
goto P_0c004b26;
P_0c004b26: /* original 2fa6, guest PC 0x0c010c26 */
if(!s->budget--) { s->failed_pc=0x0c004b26u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b28;
P_0c004b28: /* original 65c3, guest PC 0x0c010c28 */
if(!s->budget--) { s->failed_pc=0x0c004b28u; return 0; }
r[5]=r[12];
goto P_0c004b2a;
P_0c004b2a: /* original 2f96, guest PC 0x0c010c2a */
if(!s->budget--) { s->failed_pc=0x0c004b2au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b2c;
P_0c004b2c: /* original 2f86, guest PC 0x0c010c2c */
if(!s->budget--) { s->failed_pc=0x0c004b2cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004b2e;
P_0c004b2e: /* original 4f22, guest PC 0x0c010c2e */
if(!s->budget--) { s->failed_pc=0x0c004b2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c004b30;
P_0c004b30: /* original de2e, guest PC 0x0c010c30 */
if(!s->budget--) { s->failed_pc=0x0c004b30u; return 0; }
r[14]=read(ram,0x0c004becu,4);
goto P_0c004b32;
P_0c004b32: /* original 63e3, guest PC 0x0c010c32 */
if(!s->budget--) { s->failed_pc=0x0c004b32u; return 0; }
r[3]=r[14];
goto P_0c004b34;
P_0c004b34: /* original 7501, guest PC 0x0c010c34 */
if(!s->budget--) { s->failed_pc=0x0c004b34u; return 0; }
r[5]+=0x00000001u;
goto P_0c004b36;
P_0c004b36: /* original 334c, guest PC 0x0c010c36 */
if(!s->budget--) { s->failed_pc=0x0c004b36u; return 0; }
r[3]+=r[4];
goto P_0c004b38;
P_0c004b38: /* original 3563, guest PC 0x0c010c38 */
if(!s->budget--) { s->failed_pc=0x0c004b38u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c004b3a;
P_0c004b3a: /* original 23c2, guest PC 0x0c010c3a */
if(!s->budget--) { s->failed_pc=0x0c004b3au; return 0; }
write(ram,r[3],r[12],4);
goto P_0c004b3c;
P_0c004b3c: /* original 8ff9, guest PC 0x0c010c3c */
if(!s->budget--) { s->failed_pc=0x0c004b3cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c004b32; }
goto P_0c004b40;
P_0c004b3e: /* original 7404, guest PC 0x0c010c3e */
if(!s->budget--) { s->failed_pc=0x0c004b3eu; return 0; }
r[4]+=0x00000004u;
goto P_0c004b40;
P_0c004b40: /* original d32b, guest PC 0x0c010c40 */
if(!s->budget--) { s->failed_pc=0x0c004b40u; return 0; }
r[3]=read(ram,0x0c004bf0u,4);
goto P_0c004b42;
P_0c004b42: /* original e070, guest PC 0x0c010c42 */
if(!s->budget--) { s->failed_pc=0x0c004b42u; return 0; }
r[0]=0x00000070u;
goto P_0c004b44;
P_0c004b44: /* original d22b, guest PC 0x0c010c44 */
if(!s->budget--) { s->failed_pc=0x0c004b44u; return 0; }
r[2]=read(ram,0x0c004bf4u,4);
goto P_0c004b46;
P_0c004b46: /* original eb08, guest PC 0x0c010c46 */
if(!s->budget--) { s->failed_pc=0x0c004b46u; return 0; }
r[11]=0x00000008u;
goto P_0c004b48;
P_0c004b48: /* original 0e36, guest PC 0x0c010c48 */
if(!s->budget--) { s->failed_pc=0x0c004b48u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c004b4a;
P_0c004b4a: /* original e074, guest PC 0x0c010c4a */
if(!s->budget--) { s->failed_pc=0x0c004b4au; return 0; }
r[0]=0x00000074u;
goto P_0c004b4c;
P_0c004b4c: /* original d32a, guest PC 0x0c010c4c */
if(!s->budget--) { s->failed_pc=0x0c004b4cu; return 0; }
r[3]=read(ram,0x0c004bf8u,4);
goto P_0c004b4e;
P_0c004b4e: /* original e801, guest PC 0x0c010c4e */
if(!s->budget--) { s->failed_pc=0x0c004b4eu; return 0; }
r[8]=0x00000001u;
goto P_0c004b50;
P_0c004b50: /* original 9d49, guest PC 0x0c010c50 */
if(!s->budget--) { s->failed_pc=0x0c004b50u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004be6u,2);
goto P_0c004b52;
P_0c004b52: /* original 0e26, guest PC 0x0c010c52 */
if(!s->budget--) { s->failed_pc=0x0c004b52u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c004b54;
P_0c004b54: /* original 7050, guest PC 0x0c010c54 */
if(!s->budget--) { s->failed_pc=0x0c004b54u; return 0; }
r[0]+=0x00000050u;
goto P_0c004b56;
P_0c004b56: /* original d929, guest PC 0x0c010c56 */
if(!s->budget--) { s->failed_pc=0x0c004b56u; return 0; }
r[9]=read(ram,0x0c004bfcu,4);
goto P_0c004b58;
P_0c004b58: /* original 6ad3, guest PC 0x0c010c58 */
if(!s->budget--) { s->failed_pc=0x0c004b58u; return 0; }
r[10]=r[13];
goto P_0c004b5a;
P_0c004b5a: /* original 0e36, guest PC 0x0c010c5a */
if(!s->budget--) { s->failed_pc=0x0c004b5au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c004b5c;
P_0c004b5c: /* original d228, guest PC 0x0c010c5c */
if(!s->budget--) { s->failed_pc=0x0c004b5cu; return 0; }
r[2]=read(ram,0x0c004c00u,4);
goto P_0c004b5e;
P_0c004b5e: /* original c700, guest PC 0x0c010c5e */
if(!s->budget--) { s->failed_pc=0x0c004b5eu; return 0; }
r[0]=code_base|0x00004b60u;
goto P_0c004b60;
P_0c004b60: /* original d522, guest PC 0x0c010c60 */
if(!s->budget--) { s->failed_pc=0x0c004b60u; return 0; }
r[5]=read(ram,0x0c004becu,4);
goto P_0c004b62;
P_0c004b62: /* original 320c, guest PC 0x0c010c62 */
if(!s->budget--) { s->failed_pc=0x0c004b62u; return 0; }
r[2]+=r[0];
goto P_0c004b64;
P_0c004b64: /* original 9640, guest PC 0x0c010c64 */
if(!s->budget--) { s->failed_pc=0x0c004b64u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004be8u,2);
goto P_0c004b66;
P_0c004b66: /* original 6323, guest PC 0x0c010c66 */
if(!s->budget--) { s->failed_pc=0x0c004b66u; return 0; }
r[3]=r[2];
goto P_0c004b68;
P_0c004b68: /* original 6453, guest PC 0x0c010c68 */
if(!s->budget--) { s->failed_pc=0x0c004b68u; return 0; }
r[4]=r[5];
goto P_0c004b6a;
P_0c004b6a: /* original 239b, guest PC 0x0c010c6a */
if(!s->budget--) { s->failed_pc=0x0c004b6au; return 0; }
r[3]|=r[9];
goto P_0c004b6c;
P_0c004b6c: /* original 430b, guest PC 0x0c010c6c */
if(!s->budget--) { s->failed_pc=0x0c004b6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c004b70u;
r[4]+=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004b70u) { target=s->pc; goto dispatch; }
goto P_0c004b70;
P_0c004b6e: /* original 34ac, guest PC 0x0c010c6e */
if(!s->budget--) { s->failed_pc=0x0c004b6eu; return 0; }
r[4]+=r[10];
goto P_0c004b70;
P_0c004b70: /* original 7801, guest PC 0x0c010c70 */
if(!s->budget--) { s->failed_pc=0x0c004b70u; return 0; }
r[8]+=0x00000001u;
goto P_0c004b72;
P_0c004b72: /* original 38b3, guest PC 0x0c010c72 */
if(!s->budget--) { s->failed_pc=0x0c004b72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[11])!=0);
goto P_0c004b74;
P_0c004b74: /* original 8ff2, guest PC 0x0c010c74 */
if(!s->budget--) { s->failed_pc=0x0c004b74u; return 0; }
cond=r[17]&1u;
r[10]+=r[13];
if(!cond) { goto P_0c004b5c; }
goto P_0c004b78;
P_0c004b76: /* original 3adc, guest PC 0x0c010c76 */
if(!s->budget--) { s->failed_pc=0x0c004b76u; return 0; }
r[10]+=r[13];
goto P_0c004b78;
P_0c004b78: /* original d822, guest PC 0x0c010c78 */
if(!s->budget--) { s->failed_pc=0x0c004b78u; return 0; }
r[8]=read(ram,0x0c004c04u,4);
goto P_0c004b7a;
P_0c004b7a: /* original 64c3, guest PC 0x0c010c7a */
if(!s->budget--) { s->failed_pc=0x0c004b7au; return 0; }
r[4]=r[12];
goto P_0c004b7c;
P_0c004b7c: /* original 9535, guest PC 0x0c010c7c */
if(!s->budget--) { s->failed_pc=0x0c004b7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004beau,2);
goto P_0c004b7e;
P_0c004b7e: /* original 6ac3, guest PC 0x0c010c7e */
if(!s->budget--) { s->failed_pc=0x0c004b7eu; return 0; }
r[10]=r[12];
goto P_0c004b80;
P_0c004b80: /* original 66c3, guest PC 0x0c010c80 */
if(!s->budget--) { s->failed_pc=0x0c004b80u; return 0; }
r[6]=r[12];
goto P_0c004b82;
P_0c004b82: /* original 67d3, guest PC 0x0c010c82 */
if(!s->budget--) { s->failed_pc=0x0c004b82u; return 0; }
r[7]=r[13];
goto P_0c004b84;
P_0c004b84: /* original d219, guest PC 0x0c010c84 */
if(!s->budget--) { s->failed_pc=0x0c004b84u; return 0; }
r[2]=read(ram,0x0c004becu,4);
goto P_0c004b86;
P_0c004b86: /* original 63e3, guest PC 0x0c010c86 */
if(!s->budget--) { s->failed_pc=0x0c004b86u; return 0; }
r[3]=r[14];
goto P_0c004b88;
P_0c004b88: /* original 733c, guest PC 0x0c010c88 */
if(!s->budget--) { s->failed_pc=0x0c004b88u; return 0; }
r[3]+=0x0000003cu;
goto P_0c004b8a;
P_0c004b8a: /* original 60e3, guest PC 0x0c010c8a */
if(!s->budget--) { s->failed_pc=0x0c004b8au; return 0; }
r[0]=r[14];
goto P_0c004b8c;
P_0c004b8c: /* original 327c, guest PC 0x0c010c8c */
if(!s->budget--) { s->failed_pc=0x0c004b8cu; return 0; }
r[2]+=r[7];
goto P_0c004b8e;
P_0c004b8e: /* original 334c, guest PC 0x0c010c8e */
if(!s->budget--) { s->failed_pc=0x0c004b8eu; return 0; }
r[3]+=r[4];
goto P_0c004b90;
P_0c004b90: /* original 2322, guest PC 0x0c010c90 */
if(!s->budget--) { s->failed_pc=0x0c004b90u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c004b92;
P_0c004b92: /* original 7078, guest PC 0x0c010c92 */
if(!s->budget--) { s->failed_pc=0x0c004b92u; return 0; }
r[0]+=0x00000078u;
goto P_0c004b94;
P_0c004b94: /* original d315, guest PC 0x0c010c94 */
if(!s->budget--) { s->failed_pc=0x0c004b94u; return 0; }
r[3]=read(ram,0x0c004becu,4);
goto P_0c004b96;
P_0c004b96: /* original 7a01, guest PC 0x0c010c96 */
if(!s->budget--) { s->failed_pc=0x0c004b96u; return 0; }
r[10]+=0x00000001u;
goto P_0c004b98;
P_0c004b98: /* original 37dc, guest PC 0x0c010c98 */
if(!s->budget--) { s->failed_pc=0x0c004b98u; return 0; }
r[7]+=r[13];
goto P_0c004b9a;
P_0c004b9a: /* original 3ab3, guest PC 0x0c010c9a */
if(!s->budget--) { s->failed_pc=0x0c004b9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[11])!=0);
goto P_0c004b9c;
P_0c004b9c: /* original 334c, guest PC 0x0c010c9c */
if(!s->budget--) { s->failed_pc=0x0c004b9cu; return 0; }
r[3]+=r[4];
goto P_0c004b9e;
P_0c004b9e: /* original 335c, guest PC 0x0c010c9e */
if(!s->budget--) { s->failed_pc=0x0c004b9eu; return 0; }
r[3]+=r[5];
goto P_0c004ba0;
P_0c004ba0: /* original 0436, guest PC 0x0c010ca0 */
if(!s->budget--) { s->failed_pc=0x0c004ba0u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c004ba2;
P_0c004ba2: /* original d212, guest PC 0x0c010ca2 */
if(!s->budget--) { s->failed_pc=0x0c004ba2u; return 0; }
r[2]=read(ram,0x0c004becu,4);
goto P_0c004ba4;
P_0c004ba4: /* original d318, guest PC 0x0c010ca4 */
if(!s->budget--) { s->failed_pc=0x0c004ba4u; return 0; }
r[3]=read(ram,0x0c004c08u,4);
goto P_0c004ba6;
P_0c004ba6: /* original 324c, guest PC 0x0c010ca6 */
if(!s->budget--) { s->failed_pc=0x0c004ba6u; return 0; }
r[2]+=r[4];
goto P_0c004ba8;
P_0c004ba8: /* original 236b, guest PC 0x0c010ca8 */
if(!s->budget--) { s->failed_pc=0x0c004ba8u; return 0; }
r[3]|=r[6];
goto P_0c004baa;
P_0c004baa: /* original 325c, guest PC 0x0c010caa */
if(!s->budget--) { s->failed_pc=0x0c004baau; return 0; }
r[2]+=r[5];
goto P_0c004bac;
P_0c004bac: /* original 2232, guest PC 0x0c010cac */
if(!s->budget--) { s->failed_pc=0x0c004bacu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c004bae;
P_0c004bae: /* original 368c, guest PC 0x0c010cae */
if(!s->budget--) { s->failed_pc=0x0c004baeu; return 0; }
r[6]+=r[8];
goto P_0c004bb0;
P_0c004bb0: /* original 8fe8, guest PC 0x0c010cb0 */
if(!s->budget--) { s->failed_pc=0x0c004bb0u; return 0; }
cond=r[17]&1u;
r[4]+=r[13];
if(!cond) { goto P_0c004b84; }
goto P_0c004bb4;
P_0c004bb2: /* original 34dc, guest PC 0x0c010cb2 */
if(!s->budget--) { s->failed_pc=0x0c004bb2u; return 0; }
r[4]+=r[13];
goto P_0c004bb4;
P_0c004bb4: /* original d315, guest PC 0x0c010cb4 */
if(!s->budget--) { s->failed_pc=0x0c004bb4u; return 0; }
r[3]=read(ram,0x0c004c0cu,4);
goto P_0c004bb6;
P_0c004bb6: /* original c705, guest PC 0x0c010cb6 */
if(!s->budget--) { s->failed_pc=0x0c004bb6u; return 0; }
r[0]=code_base|0x00004bccu;
goto P_0c004bb8;
P_0c004bb8: /* original d115, guest PC 0x0c010cb8 */
if(!s->budget--) { s->failed_pc=0x0c004bb8u; return 0; }
r[1]=read(ram,0x0c004c10u,4);
goto P_0c004bba;
P_0c004bba: /* original 1e3f, guest PC 0x0c010cba */
if(!s->budget--) { s->failed_pc=0x0c004bbau; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c004bbc;
P_0c004bbc: /* original d315, guest PC 0x0c010cbc */
if(!s->budget--) { s->failed_pc=0x0c004bbcu; return 0; }
r[3]=read(ram,0x0c004c14u,4);
goto P_0c004bbe;
P_0c004bbe: /* original d20b, guest PC 0x0c010cbe */
if(!s->budget--) { s->failed_pc=0x0c004bbeu; return 0; }
r[2]=read(ram,0x0c004becu,4);
goto P_0c004bc0;
P_0c004bc0: /* original 2122, guest PC 0x0c010cc0 */
if(!s->budget--) { s->failed_pc=0x0c004bc0u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c004bc2;
P_0c004bc2: /* original 23c2, guest PC 0x0c010cc2 */
if(!s->budget--) { s->failed_pc=0x0c004bc2u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c004bc4;
P_0c004bc4: /* original d315, guest PC 0x0c010cc4 */
if(!s->budget--) { s->failed_pc=0x0c004bc4u; return 0; }
r[3]=read(ram,0x0c004c1cu,4);
goto P_0c004bc6;
P_0c004bc6: /* original d114, guest PC 0x0c010cc6 */
if(!s->budget--) { s->failed_pc=0x0c004bc6u; return 0; }
r[1]=read(ram,0x0c004c18u,4);
goto P_0c004bc8;
P_0c004bc8: /* original 330c, guest PC 0x0c010cc8 */
if(!s->budget--) { s->failed_pc=0x0c004bc8u; return 0; }
r[3]+=r[0];
goto P_0c004bca;
P_0c004bca: /* original 2122, guest PC 0x0c010cca */
if(!s->budget--) { s->failed_pc=0x0c004bcau; return 0; }
write(ram,r[1],r[2],4);
goto P_0c004bcc;
P_0c004bcc: /* original 6233, guest PC 0x0c010ccc */
if(!s->budget--) { s->failed_pc=0x0c004bccu; return 0; }
r[2]=r[3];
goto P_0c004bce;
P_0c004bce: /* original 292b, guest PC 0x0c010cce */
if(!s->budget--) { s->failed_pc=0x0c004bceu; return 0; }
r[9]|=r[2];
goto P_0c004bd0;
P_0c004bd0: /* original 490b, guest PC 0x0c010cd0 */
if(!s->budget--) { s->failed_pc=0x0c004bd0u; return 0; }
target=r[9];
r[16]=code_base|0x0c004bd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004bd4u) { target=s->pc; goto dispatch; }
goto P_0c004bd4;
P_0c004bd2: /* original 0009, guest PC 0x0c010cd2 */
if(!s->budget--) { s->failed_pc=0x0c004bd2u; return 0; }
goto P_0c004bd4;
P_0c004bd4: /* original 4f26, guest PC 0x0c010cd4 */
if(!s->budget--) { s->failed_pc=0x0c004bd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c004bd6;
P_0c004bd6: /* original 68f6, guest PC 0x0c010cd6 */
if(!s->budget--) { s->failed_pc=0x0c004bd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c004bd8;
P_0c004bd8: /* original 69f6, guest PC 0x0c010cd8 */
if(!s->budget--) { s->failed_pc=0x0c004bd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c004bda;
P_0c004bda: /* original 6af6, guest PC 0x0c010cda */
if(!s->budget--) { s->failed_pc=0x0c004bdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c004bdc;
P_0c004bdc: /* original 6bf6, guest PC 0x0c010cdc */
if(!s->budget--) { s->failed_pc=0x0c004bdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c004bde;
P_0c004bde: /* original 6cf6, guest PC 0x0c010cde */
if(!s->budget--) { s->failed_pc=0x0c004bdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c004be0;
P_0c004be0: /* original 6df6, guest PC 0x0c010ce0 */
if(!s->budget--) { s->failed_pc=0x0c004be0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c004be2;
P_0c004be2: /* original 000b, guest PC 0x0c010ce2 */
if(!s->budget--) { s->failed_pc=0x0c004be2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c004be4: /* original 6ef6, guest PC 0x0c010ce4 */
if(!s->budget--) { s->failed_pc=0x0c004be4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c004be6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c004be6u; return 0; } return 1;
P_0c004e3c: /* original 2fe6, guest PC 0x0c010f3c */
if(!s->budget--) { s->failed_pc=0x0c004e3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004e3e;
P_0c004e3e: /* original 2fd6, guest PC 0x0c010f3e */
if(!s->budget--) { s->failed_pc=0x0c004e3eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c004e40;
P_0c004e40: /* original d741, guest PC 0x0c010f40 */
if(!s->budget--) { s->failed_pc=0x0c004e40u; return 0; }
r[7]=read(ram,0x0c004f48u,4);
goto P_0c004e42;
P_0c004e42: /* original 4f22, guest PC 0x0c010f42 */
if(!s->budget--) { s->failed_pc=0x0c004e42u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c004e44;
P_0c004e44: /* original 6072, guest PC 0x0c010f44 */
if(!s->budget--) { s->failed_pc=0x0c004e44u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c004e46;
P_0c004e46: /* original d542, guest PC 0x0c010f46 */
if(!s->budget--) { s->failed_pc=0x0c004e46u; return 0; }
r[5]=read(ram,0x0c004f50u,4);
goto P_0c004e48;
P_0c004e48: /* original dd40, guest PC 0x0c010f48 */
if(!s->budget--) { s->failed_pc=0x0c004e48u; return 0; }
r[13]=read(ram,0x0c004f4cu,4);
goto P_0c004e4a;
P_0c004e4a: /* original 8801, guest PC 0x0c010f4a */
if(!s->budget--) { s->failed_pc=0x0c004e4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c004e4c;
P_0c004e4c: /* original 8903, guest PC 0x0c010f4c */
if(!s->budget--) { s->failed_pc=0x0c004e4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c004e56; }
goto P_0c004e4e;
P_0c004e4e: /* original 8802, guest PC 0x0c010f4e */
if(!s->budget--) { s->failed_pc=0x0c004e4eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c004e50;
P_0c004e50: /* original 890a, guest PC 0x0c010f50 */
if(!s->budget--) { s->failed_pc=0x0c004e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c004e68; }
goto P_0c004e52;
P_0c004e52: /* original a011, guest PC 0x0c010f52 */
if(!s->budget--) { s->failed_pc=0x0c004e52u; return 0; }
goto P_0c004e78;
P_0c004e54: /* original 0009, guest PC 0x0c010f54 */
if(!s->budget--) { s->failed_pc=0x0c004e54u; return 0; }
goto P_0c004e56;
P_0c004e56: /* original d33f, guest PC 0x0c010f56 */
if(!s->budget--) { s->failed_pc=0x0c004e56u; return 0; }
r[3]=read(ram,0x0c004f54u,4);
goto P_0c004e58;
P_0c004e58: /* original d240, guest PC 0x0c010f58 */
if(!s->budget--) { s->failed_pc=0x0c004e58u; return 0; }
r[2]=read(ram,0x0c004f5cu,4);
goto P_0c004e5a;
P_0c004e5a: /* original d63f, guest PC 0x0c010f5a */
if(!s->budget--) { s->failed_pc=0x0c004e5au; return 0; }
r[6]=read(ram,0x0c004f58u,4);
goto P_0c004e5c;
P_0c004e5c: /* original 2d32, guest PC 0x0c010f5c */
if(!s->budget--) { s->failed_pc=0x0c004e5cu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c004e5e;
P_0c004e5e: /* original d340, guest PC 0x0c010f5e */
if(!s->budget--) { s->failed_pc=0x0c004e5eu; return 0; }
r[3]=read(ram,0x0c004f60u,4);
goto P_0c004e60;
P_0c004e60: /* original 2262, guest PC 0x0c010f60 */
if(!s->budget--) { s->failed_pc=0x0c004e60u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c004e62;
P_0c004e62: /* original 2562, guest PC 0x0c010f62 */
if(!s->budget--) { s->failed_pc=0x0c004e62u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c004e64;
P_0c004e64: /* original a008, guest PC 0x0c010f64 */
if(!s->budget--) { s->failed_pc=0x0c004e64u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c004e78;
P_0c004e66: /* original 2362, guest PC 0x0c010f66 */
if(!s->budget--) { s->failed_pc=0x0c004e66u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c004e68;
P_0c004e68: /* original d23e, guest PC 0x0c010f68 */
if(!s->budget--) { s->failed_pc=0x0c004e68u; return 0; }
r[2]=read(ram,0x0c004f64u,4);
goto P_0c004e6a;
P_0c004e6a: /* original d33c, guest PC 0x0c010f6a */
if(!s->budget--) { s->failed_pc=0x0c004e6au; return 0; }
r[3]=read(ram,0x0c004f5cu,4);
goto P_0c004e6c;
P_0c004e6c: /* original 2d22, guest PC 0x0c010f6c */
if(!s->budget--) { s->failed_pc=0x0c004e6cu; return 0; }
write(ram,r[13],r[2],4);
goto P_0c004e6e;
P_0c004e6e: /* original d23c, guest PC 0x0c010f6e */
if(!s->budget--) { s->failed_pc=0x0c004e6eu; return 0; }
r[2]=read(ram,0x0c004f60u,4);
goto P_0c004e70;
P_0c004e70: /* original d63d, guest PC 0x0c010f70 */
if(!s->budget--) { s->failed_pc=0x0c004e70u; return 0; }
r[6]=read(ram,0x0c004f68u,4);
goto P_0c004e72;
P_0c004e72: /* original 2362, guest PC 0x0c010f72 */
if(!s->budget--) { s->failed_pc=0x0c004e72u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c004e74;
P_0c004e74: /* original 2562, guest PC 0x0c010f74 */
if(!s->budget--) { s->failed_pc=0x0c004e74u; return 0; }
write(ram,r[5],r[6],4);
goto P_0c004e76;
P_0c004e76: /* original 2262, guest PC 0x0c010f76 */
if(!s->budget--) { s->failed_pc=0x0c004e76u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c004e78;
P_0c004e78: /* original 6072, guest PC 0x0c010f78 */
if(!s->budget--) { s->failed_pc=0x0c004e78u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c004e7a;
P_0c004e7a: /* original 8801, guest PC 0x0c010f7a */
if(!s->budget--) { s->failed_pc=0x0c004e7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c004e7c;
P_0c004e7c: /* original 8b0c, guest PC 0x0c010f7c */
if(!s->budget--) { s->failed_pc=0x0c004e7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c004e98; }
goto P_0c004e7e;
P_0c004e7e: /* original d23b, guest PC 0x0c010f7e */
if(!s->budget--) { s->failed_pc=0x0c004e7eu; return 0; }
r[2]=read(ram,0x0c004f6cu,4);
goto P_0c004e80;
P_0c004e80: /* original 9660, guest PC 0x0c010f80 */
if(!s->budget--) { s->failed_pc=0x0c004e80u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c004f44u,2);
goto P_0c004e82;
P_0c004e82: /* original 2262, guest PC 0x0c010f82 */
if(!s->budget--) { s->failed_pc=0x0c004e82u; return 0; }
write(ram,r[2],r[6],4);
goto P_0c004e84;
P_0c004e84: /* original d33a, guest PC 0x0c010f84 */
if(!s->budget--) { s->failed_pc=0x0c004e84u; return 0; }
r[3]=read(ram,0x0c004f70u,4);
goto P_0c004e86;
P_0c004e86: /* original 2362, guest PC 0x0c010f86 */
if(!s->budget--) { s->failed_pc=0x0c004e86u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c004e88;
P_0c004e88: /* original d03a, guest PC 0x0c010f88 */
if(!s->budget--) { s->failed_pc=0x0c004e88u; return 0; }
r[0]=read(ram,0x0c004f74u,4);
goto P_0c004e8a;
P_0c004e8a: /* original e105, guest PC 0x0c010f8a */
if(!s->budget--) { s->failed_pc=0x0c004e8au; return 0; }
r[1]=0x00000005u;
goto P_0c004e8c;
P_0c004e8c: /* original 2012, guest PC 0x0c010f8c */
if(!s->budget--) { s->failed_pc=0x0c004e8cu; return 0; }
write(ram,r[0],r[1],4);
goto P_0c004e8e;
P_0c004e8e: /* original d73a, guest PC 0x0c010f8e */
if(!s->budget--) { s->failed_pc=0x0c004e8eu; return 0; }
r[7]=read(ram,0x0c004f78u,4);
goto P_0c004e90;
P_0c004e90: /* original 6672, guest PC 0x0c010f90 */
if(!s->budget--) { s->failed_pc=0x0c004e90u; return 0; }
tmp=read(ram,r[7],4);
r[6]=tmp;
goto P_0c004e92;
P_0c004e92: /* original e208, guest PC 0x0c010f92 */
if(!s->budget--) { s->failed_pc=0x0c004e92u; return 0; }
r[2]=0x00000008u;
goto P_0c004e94;
P_0c004e94: /* original 262b, guest PC 0x0c010f94 */
if(!s->budget--) { s->failed_pc=0x0c004e94u; return 0; }
r[6]|=r[2];
goto P_0c004e96;
P_0c004e96: /* original 2762, guest PC 0x0c010f96 */
if(!s->budget--) { s->failed_pc=0x0c004e96u; return 0; }
write(ram,r[7],r[6],4);
goto P_0c004e98;
P_0c004e98: /* original 63d2, guest PC 0x0c010f98 */
if(!s->budget--) { s->failed_pc=0x0c004e98u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c004e9a;
P_0c004e9a: /* original e03c, guest PC 0x0c010f9a */
if(!s->budget--) { s->failed_pc=0x0c004e9au; return 0; }
r[0]=0x0000003cu;
goto P_0c004e9c;
P_0c004e9c: /* original e2c0, guest PC 0x0c010f9c */
if(!s->budget--) { s->failed_pc=0x0c004e9cu; return 0; }
r[2]=0xffffffc0u;
goto P_0c004e9e;
P_0c004e9e: /* original 0324, guest PC 0x0c010f9e */
if(!s->budget--) { s->failed_pc=0x0c004e9eu; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c004ea0;
P_0c004ea0: /* original 6352, guest PC 0x0c010fa0 */
if(!s->budget--) { s->failed_pc=0x0c004ea0u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ea2;
P_0c004ea2: /* original e20b, guest PC 0x0c010fa2 */
if(!s->budget--) { s->failed_pc=0x0c004ea2u; return 0; }
r[2]=0x0000000bu;
goto P_0c004ea4;
P_0c004ea4: /* original 2320, guest PC 0x0c010fa4 */
if(!s->budget--) { s->failed_pc=0x0c004ea4u; return 0; }
write(ram,r[3],r[2],1);
goto P_0c004ea6;
P_0c004ea6: /* original 6352, guest PC 0x0c010fa6 */
if(!s->budget--) { s->failed_pc=0x0c004ea6u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ea8;
P_0c004ea8: /* original 6043, guest PC 0x0c010fa8 */
if(!s->budget--) { s->failed_pc=0x0c004ea8u; return 0; }
r[0]=r[4];
goto P_0c004eaa;
P_0c004eaa: /* original 8034, guest PC 0x0c010faa */
if(!s->budget--) { s->failed_pc=0x0c004eaau; return 0; }
write(ram,r[3]+4,r[0],1);
goto P_0c004eac;
P_0c004eac: /* original 6352, guest PC 0x0c010fac */
if(!s->budget--) { s->failed_pc=0x0c004eacu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004eae;
P_0c004eae: /* original e443, guest PC 0x0c010fae */
if(!s->budget--) { s->failed_pc=0x0c004eaeu; return 0; }
r[4]=0x00000043u;
goto P_0c004eb0;
P_0c004eb0: /* original 6043, guest PC 0x0c010fb0 */
if(!s->budget--) { s->failed_pc=0x0c004eb0u; return 0; }
r[0]=r[4];
goto P_0c004eb2;
P_0c004eb2: /* original 8038, guest PC 0x0c010fb2 */
if(!s->budget--) { s->failed_pc=0x0c004eb2u; return 0; }
write(ram,r[3]+8,r[0],1);
goto P_0c004eb4;
P_0c004eb4: /* original 6352, guest PC 0x0c010fb4 */
if(!s->budget--) { s->failed_pc=0x0c004eb4u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004eb6;
P_0c004eb6: /* original ee00, guest PC 0x0c010fb6 */
if(!s->budget--) { s->failed_pc=0x0c004eb6u; return 0; }
r[14]=0x00000000u;
goto P_0c004eb8;
P_0c004eb8: /* original 60e3, guest PC 0x0c010fb8 */
if(!s->budget--) { s->failed_pc=0x0c004eb8u; return 0; }
r[0]=r[14];
goto P_0c004eba;
P_0c004eba: /* original 803c, guest PC 0x0c010fba */
if(!s->budget--) { s->failed_pc=0x0c004ebau; return 0; }
write(ram,r[3]+12,r[0],1);
goto P_0c004ebc;
P_0c004ebc: /* original 6352, guest PC 0x0c010fbc */
if(!s->budget--) { s->failed_pc=0x0c004ebcu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ebe;
P_0c004ebe: /* original e010, guest PC 0x0c010fbe */
if(!s->budget--) { s->failed_pc=0x0c004ebeu; return 0; }
r[0]=0x00000010u;
goto P_0c004ec0;
P_0c004ec0: /* original 03e4, guest PC 0x0c010fc0 */
if(!s->budget--) { s->failed_pc=0x0c004ec0u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004ec2;
P_0c004ec2: /* original 6352, guest PC 0x0c010fc2 */
if(!s->budget--) { s->failed_pc=0x0c004ec2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ec4;
P_0c004ec4: /* original e014, guest PC 0x0c010fc4 */
if(!s->budget--) { s->failed_pc=0x0c004ec4u; return 0; }
r[0]=0x00000014u;
goto P_0c004ec6;
P_0c004ec6: /* original 03e4, guest PC 0x0c010fc6 */
if(!s->budget--) { s->failed_pc=0x0c004ec6u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004ec8;
P_0c004ec8: /* original 6352, guest PC 0x0c010fc8 */
if(!s->budget--) { s->failed_pc=0x0c004ec8u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004eca;
P_0c004eca: /* original e018, guest PC 0x0c010fca */
if(!s->budget--) { s->failed_pc=0x0c004ecau; return 0; }
r[0]=0x00000018u;
goto P_0c004ecc;
P_0c004ecc: /* original 03e4, guest PC 0x0c010fcc */
if(!s->budget--) { s->failed_pc=0x0c004eccu; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004ece;
P_0c004ece: /* original 6352, guest PC 0x0c010fce */
if(!s->budget--) { s->failed_pc=0x0c004eceu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ed0;
P_0c004ed0: /* original e01c, guest PC 0x0c010fd0 */
if(!s->budget--) { s->failed_pc=0x0c004ed0u; return 0; }
r[0]=0x0000001cu;
goto P_0c004ed2;
P_0c004ed2: /* original e201, guest PC 0x0c010fd2 */
if(!s->budget--) { s->failed_pc=0x0c004ed2u; return 0; }
r[2]=0x00000001u;
goto P_0c004ed4;
P_0c004ed4: /* original 0324, guest PC 0x0c010fd4 */
if(!s->budget--) { s->failed_pc=0x0c004ed4u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c004ed6;
P_0c004ed6: /* original 6352, guest PC 0x0c010fd6 */
if(!s->budget--) { s->failed_pc=0x0c004ed6u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ed8;
P_0c004ed8: /* original e020, guest PC 0x0c010fd8 */
if(!s->budget--) { s->failed_pc=0x0c004ed8u; return 0; }
r[0]=0x00000020u;
goto P_0c004eda;
P_0c004eda: /* original e240, guest PC 0x0c010fda */
if(!s->budget--) { s->failed_pc=0x0c004edau; return 0; }
r[2]=0x00000040u;
goto P_0c004edc;
P_0c004edc: /* original 0324, guest PC 0x0c010fdc */
if(!s->budget--) { s->failed_pc=0x0c004edcu; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c004ede;
P_0c004ede: /* original 6352, guest PC 0x0c010fde */
if(!s->budget--) { s->failed_pc=0x0c004edeu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ee0;
P_0c004ee0: /* original e024, guest PC 0x0c010fe0 */
if(!s->budget--) { s->failed_pc=0x0c004ee0u; return 0; }
r[0]=0x00000024u;
goto P_0c004ee2;
P_0c004ee2: /* original 03e4, guest PC 0x0c010fe2 */
if(!s->budget--) { s->failed_pc=0x0c004ee2u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004ee4;
P_0c004ee4: /* original 6352, guest PC 0x0c010fe4 */
if(!s->budget--) { s->failed_pc=0x0c004ee4u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ee6;
P_0c004ee6: /* original e028, guest PC 0x0c010fe6 */
if(!s->budget--) { s->failed_pc=0x0c004ee6u; return 0; }
r[0]=0x00000028u;
goto P_0c004ee8;
P_0c004ee8: /* original e233, guest PC 0x0c010fe8 */
if(!s->budget--) { s->failed_pc=0x0c004ee8u; return 0; }
r[2]=0x00000033u;
goto P_0c004eea;
P_0c004eea: /* original 0324, guest PC 0x0c010fea */
if(!s->budget--) { s->failed_pc=0x0c004eeau; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c004eec;
P_0c004eec: /* original 6352, guest PC 0x0c010fec */
if(!s->budget--) { s->failed_pc=0x0c004eecu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004eee;
P_0c004eee: /* original e02c, guest PC 0x0c010fee */
if(!s->budget--) { s->failed_pc=0x0c004eeeu; return 0; }
r[0]=0x0000002cu;
goto P_0c004ef0;
P_0c004ef0: /* original 03e4, guest PC 0x0c010ff0 */
if(!s->budget--) { s->failed_pc=0x0c004ef0u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004ef2;
P_0c004ef2: /* original 6352, guest PC 0x0c010ff2 */
if(!s->budget--) { s->failed_pc=0x0c004ef2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004ef4;
P_0c004ef4: /* original e030, guest PC 0x0c010ff4 */
if(!s->budget--) { s->failed_pc=0x0c004ef4u; return 0; }
r[0]=0x00000030u;
goto P_0c004ef6;
P_0c004ef6: /* original e204, guest PC 0x0c010ff6 */
if(!s->budget--) { s->failed_pc=0x0c004ef6u; return 0; }
r[2]=0x00000004u;
goto P_0c004ef8;
P_0c004ef8: /* original 0324, guest PC 0x0c010ff8 */
if(!s->budget--) { s->failed_pc=0x0c004ef8u; return 0; }
write(ram,r[3]+r[0],r[2],1);
goto P_0c004efa;
P_0c004efa: /* original 6352, guest PC 0x0c010ffa */
if(!s->budget--) { s->failed_pc=0x0c004efau; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004efc;
P_0c004efc: /* original e034, guest PC 0x0c010ffc */
if(!s->budget--) { s->failed_pc=0x0c004efcu; return 0; }
r[0]=0x00000034u;
goto P_0c004efe;
P_0c004efe: /* original 03e4, guest PC 0x0c010ffe */
if(!s->budget--) { s->failed_pc=0x0c004efeu; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004f00;
P_0c004f00: /* original 6352, guest PC 0x0c011000 */
if(!s->budget--) { s->failed_pc=0x0c004f00u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c004f02;
P_0c004f02: /* original e03c, guest PC 0x0c011002 */
if(!s->budget--) { s->failed_pc=0x0c004f02u; return 0; }
r[0]=0x0000003cu;
goto P_0c004f04;
P_0c004f04: /* original 03e4, guest PC 0x0c011004 */
if(!s->budget--) { s->failed_pc=0x0c004f04u; return 0; }
write(ram,r[3]+r[0],r[14],1);
goto P_0c004f06;
P_0c004f06: /* original 63d2, guest PC 0x0c011006 */
if(!s->budget--) { s->failed_pc=0x0c004f06u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c004f08;
P_0c004f08: /* original e014, guest PC 0x0c011008 */
if(!s->budget--) { s->failed_pc=0x0c004f08u; return 0; }
r[0]=0x00000014u;
goto P_0c004f0a;
P_0c004f0a: /* original 0344, guest PC 0x0c01100a */
if(!s->budget--) { s->failed_pc=0x0c004f0au; return 0; }
write(ram,r[3]+r[0],r[4],1);
goto P_0c004f0c;
P_0c004f0c: /* original d31b, guest PC 0x0c01100c */
if(!s->budget--) { s->failed_pc=0x0c004f0cu; return 0; }
r[3]=read(ram,0x0c004f7cu,4);
goto P_0c004f0e;
P_0c004f0e: /* original c700, guest PC 0x0c01100e */
if(!s->budget--) { s->failed_pc=0x0c004f0eu; return 0; }
r[0]=code_base|0x00004f10u;
goto P_0c004f10;
P_0c004f10: /* original d21b, guest PC 0x0c011010 */
if(!s->budget--) { s->failed_pc=0x0c004f10u; return 0; }
r[2]=read(ram,0x0c004f80u,4);
goto P_0c004f12;
P_0c004f12: /* original 330c, guest PC 0x0c011012 */
if(!s->budget--) { s->failed_pc=0x0c004f12u; return 0; }
r[3]+=r[0];
goto P_0c004f14;
P_0c004f14: /* original 6133, guest PC 0x0c011014 */
if(!s->budget--) { s->failed_pc=0x0c004f14u; return 0; }
r[1]=r[3];
goto P_0c004f16;
P_0c004f16: /* original 212b, guest PC 0x0c011016 */
if(!s->budget--) { s->failed_pc=0x0c004f16u; return 0; }
r[1]|=r[2];
goto P_0c004f18;
P_0c004f18: /* original 410b, guest PC 0x0c011018 */
if(!s->budget--) { s->failed_pc=0x0c004f18u; return 0; }
target=r[1];
r[16]=code_base|0x0c004f1cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004f1cu) { target=s->pc; goto dispatch; }
goto P_0c004f1c;
P_0c004f1a: /* original 0009, guest PC 0x0c01101a */
if(!s->budget--) { s->failed_pc=0x0c004f1au; return 0; }
goto P_0c004f1c;
P_0c004f1c: /* original 2008, guest PC 0x0c01101c */
if(!s->budget--) { s->failed_pc=0x0c004f1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c004f1e;
P_0c004f1e: /* original 8901, guest PC 0x0c01101e */
if(!s->budget--) { s->failed_pc=0x0c004f1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c004f24; }
goto P_0c004f20;
P_0c004f20: /* original a00c, guest PC 0x0c011020 */
if(!s->budget--) { s->failed_pc=0x0c004f20u; return 0; }
r[0]=0x00000001u;
goto P_0c004f3c;
P_0c004f22: /* original e001, guest PC 0x0c011022 */
if(!s->budget--) { s->failed_pc=0x0c004f22u; return 0; }
r[0]=0x00000001u;
goto P_0c004f24;
P_0c004f24: /* original 62d2, guest PC 0x0c011024 */
if(!s->budget--) { s->failed_pc=0x0c004f24u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c004f26;
P_0c004f26: /* original e03c, guest PC 0x0c011026 */
if(!s->budget--) { s->failed_pc=0x0c004f26u; return 0; }
r[0]=0x0000003cu;
goto P_0c004f28;
P_0c004f28: /* original 02e4, guest PC 0x0c011028 */
if(!s->budget--) { s->failed_pc=0x0c004f28u; return 0; }
write(ram,r[2]+r[0],r[14],1);
goto P_0c004f2a;
P_0c004f2a: /* original d316, guest PC 0x0c01102a */
if(!s->budget--) { s->failed_pc=0x0c004f2au; return 0; }
r[3]=read(ram,0x0c004f84u,4);
goto P_0c004f2c;
P_0c004f2c: /* original c700, guest PC 0x0c01102c */
if(!s->budget--) { s->failed_pc=0x0c004f2cu; return 0; }
r[0]=code_base|0x00004f30u;
goto P_0c004f2e;
P_0c004f2e: /* original 330c, guest PC 0x0c01102e */
if(!s->budget--) { s->failed_pc=0x0c004f2eu; return 0; }
r[3]+=r[0];
goto P_0c004f30;
P_0c004f30: /* original d213, guest PC 0x0c011030 */
if(!s->budget--) { s->failed_pc=0x0c004f30u; return 0; }
r[2]=read(ram,0x0c004f80u,4);
goto P_0c004f32;
P_0c004f32: /* original 6133, guest PC 0x0c011032 */
if(!s->budget--) { s->failed_pc=0x0c004f32u; return 0; }
r[1]=r[3];
goto P_0c004f34;
P_0c004f34: /* original 212b, guest PC 0x0c011034 */
if(!s->budget--) { s->failed_pc=0x0c004f34u; return 0; }
r[1]|=r[2];
goto P_0c004f36;
P_0c004f36: /* original 410b, guest PC 0x0c011036 */
if(!s->budget--) { s->failed_pc=0x0c004f36u; return 0; }
target=r[1];
r[16]=code_base|0x0c004f3au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c004f3au) { target=s->pc; goto dispatch; }
goto P_0c004f3a;
P_0c004f38: /* original 0009, guest PC 0x0c011038 */
if(!s->budget--) { s->failed_pc=0x0c004f38u; return 0; }
goto P_0c004f3a;
P_0c004f3a: /* original e000, guest PC 0x0c01103a */
if(!s->budget--) { s->failed_pc=0x0c004f3au; return 0; }
r[0]=0x00000000u;
goto P_0c004f3c;
P_0c004f3c: /* original 4f26, guest PC 0x0c01103c */
if(!s->budget--) { s->failed_pc=0x0c004f3cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c004f3e;
P_0c004f3e: /* original 6df6, guest PC 0x0c01103e */
if(!s->budget--) { s->failed_pc=0x0c004f3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c004f40;
P_0c004f40: /* original 000b, guest PC 0x0c011040 */
if(!s->budget--) { s->failed_pc=0x0c004f40u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c004f42: /* original 6ef6, guest PC 0x0c011042 */
if(!s->budget--) { s->failed_pc=0x0c004f42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c004f44u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c004f44u; return 0; } return 1;
P_0c00502a: /* original d327, guest PC 0x0c01112a */
if(!s->budget--) { s->failed_pc=0x0c00502au; return 0; }
r[3]=read(ram,0x0c0050c8u,4);
goto P_0c00502c;
P_0c00502c: /* original 4f22, guest PC 0x0c01112c */
if(!s->budget--) { s->failed_pc=0x0c00502cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c00502e;
P_0c00502e: /* original 6432, guest PC 0x0c01112e */
if(!s->budget--) { s->failed_pc=0x0c00502eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c005030;
P_0c005030: /* original 9647, guest PC 0x0c011130 */
if(!s->budget--) { s->failed_pc=0x0c005030u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0050c2u,2);
goto P_0c005032;
P_0c005032: /* original 8448, guest PC 0x0c011132 */
if(!s->budget--) { s->failed_pc=0x0c005032u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c005034;
P_0c005034: /* original 2068, guest PC 0x0c011134 */
if(!s->budget--) { s->failed_pc=0x0c005034u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[6])==0)!=0);
goto P_0c005036;
P_0c005036: /* original 890a, guest PC 0x0c011136 */
if(!s->budget--) { s->failed_pc=0x0c005036u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c00504e; }
goto P_0c005038;
P_0c005038: /* original e010, guest PC 0x0c011138 */
if(!s->budget--) { s->failed_pc=0x0c005038u; return 0; }
r[0]=0x00000010u;
goto P_0c00503a;
P_0c00503a: /* original 054c, guest PC 0x0c01113a */
if(!s->budget--) { s->failed_pc=0x0c00503au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c00503c;
P_0c00503c: /* original 605c, guest PC 0x0c01113c */
if(!s->budget--) { s->failed_pc=0x0c00503cu; return 0; }
r[0]=r[5]&255u;
goto P_0c00503e;
P_0c00503e: /* original e314, guest PC 0x0c01113e */
if(!s->budget--) { s->failed_pc=0x0c00503eu; return 0; }
r[3]=0x00000014u;
goto P_0c005040;
P_0c005040: /* original 3060, guest PC 0x0c011140 */
if(!s->budget--) { s->failed_pc=0x0c005040u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[6])!=0);
goto P_0c005042;
P_0c005042: /* original 334c, guest PC 0x0c011142 */
if(!s->budget--) { s->failed_pc=0x0c005042u; return 0; }
r[3]+=r[4];
goto P_0c005044;
P_0c005044: /* original 8d06, guest PC 0x0c011144 */
if(!s->budget--) { s->failed_pc=0x0c005044u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
if(cond) { goto P_0c005054; }
goto P_0c005048;
P_0c005046: /* original 6330, guest PC 0x0c011146 */
if(!s->budget--) { s->failed_pc=0x0c005046u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c005048;
P_0c005048: /* original 933c, guest PC 0x0c011148 */
if(!s->budget--) { s->failed_pc=0x0c005048u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0050c4u,2);
goto P_0c00504a;
P_0c00504a: /* original 3030, guest PC 0x0c01114a */
if(!s->budget--) { s->failed_pc=0x0c00504au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c00504c;
P_0c00504c: /* original 8902, guest PC 0x0c01114c */
if(!s->budget--) { s->failed_pc=0x0c00504cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c005054; }
goto P_0c00504e;
P_0c00504e: /* original 4f26, guest PC 0x0c01114e */
if(!s->budget--) { s->failed_pc=0x0c00504eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c005050;
P_0c005050: /* original 000b, guest PC 0x0c011150 */
if(!s->budget--) { s->failed_pc=0x0c005050u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c005052: /* original e000, guest PC 0x0c011152 */
if(!s->budget--) { s->failed_pc=0x0c005052u; return 0; }
r[0]=0x00000000u;
goto P_0c005054;
P_0c005054: /* original 9336, guest PC 0x0c011154 */
if(!s->budget--) { s->failed_pc=0x0c005054u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0050c4u,2);
goto P_0c005056;
P_0c005056: /* original 3030, guest PC 0x0c011156 */
if(!s->budget--) { s->failed_pc=0x0c005056u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c005058;
P_0c005058: /* original 8b0d, guest PC 0x0c011158 */
if(!s->budget--) { s->failed_pc=0x0c005058u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c005076; }
goto P_0c00505a;
P_0c00505a: /* original e014, guest PC 0x0c01115a */
if(!s->budget--) { s->failed_pc=0x0c00505au; return 0; }
r[0]=0x00000014u;
goto P_0c00505c;
P_0c00505c: /* original e139, guest PC 0x0c01115c */
if(!s->budget--) { s->failed_pc=0x0c00505cu; return 0; }
r[1]=0x00000039u;
goto P_0c00505e;
P_0c00505e: /* original 0414, guest PC 0x0c01115e */
if(!s->budget--) { s->failed_pc=0x0c00505eu; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c005060;
P_0c005060: /* original d21e, guest PC 0x0c011160 */
if(!s->budget--) { s->failed_pc=0x0c005060u; return 0; }
r[2]=read(ram,0x0c0050dcu,4);
goto P_0c005062;
P_0c005062: /* original c700, guest PC 0x0c011162 */
if(!s->budget--) { s->failed_pc=0x0c005062u; return 0; }
r[0]=code_base|0x00005064u;
goto P_0c005064;
P_0c005064: /* original d11b, guest PC 0x0c011164 */
if(!s->budget--) { s->failed_pc=0x0c005064u; return 0; }
r[1]=read(ram,0x0c0050d4u,4);
goto P_0c005066;
P_0c005066: /* original 320c, guest PC 0x0c011166 */
if(!s->budget--) { s->failed_pc=0x0c005066u; return 0; }
r[2]+=r[0];
goto P_0c005068;
P_0c005068: /* original 6023, guest PC 0x0c011168 */
if(!s->budget--) { s->failed_pc=0x0c005068u; return 0; }
r[0]=r[2];
goto P_0c00506a;
P_0c00506a: /* original 201b, guest PC 0x0c01116a */
if(!s->budget--) { s->failed_pc=0x0c00506au; return 0; }
r[0]|=r[1];
goto P_0c00506c;
P_0c00506c: /* original 400b, guest PC 0x0c01116c */
if(!s->budget--) { s->failed_pc=0x0c00506cu; return 0; }
target=r[0];
r[16]=code_base|0x0c005070u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c005070u) { target=s->pc; goto dispatch; }
goto P_0c005070;
P_0c00506e: /* original 0009, guest PC 0x0c01116e */
if(!s->budget--) { s->failed_pc=0x0c00506eu; return 0; }
goto P_0c005070;
P_0c005070: /* original d21b, guest PC 0x0c011170 */
if(!s->budget--) { s->failed_pc=0x0c005070u; return 0; }
r[2]=read(ram,0x0c0050e0u,4);
goto P_0c005072;
P_0c005072: /* original 6322, guest PC 0x0c011172 */
if(!s->budget--) { s->failed_pc=0x0c005072u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c005074;
P_0c005074: /* original 6130, guest PC 0x0c011174 */
if(!s->budget--) { s->failed_pc=0x0c005074u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[1]=tmp;
goto P_0c005076;
P_0c005076: /* original e001, guest PC 0x0c011176 */
if(!s->budget--) { s->failed_pc=0x0c005076u; return 0; }
r[0]=0x00000001u;
goto P_0c005078;
P_0c005078: /* original 4f26, guest PC 0x0c011178 */
if(!s->budget--) { s->failed_pc=0x0c005078u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c00507a;
P_0c00507a: /* original 000b, guest PC 0x0c01117a */
if(!s->budget--) { s->failed_pc=0x0c00507au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c00507c: /* original 0009, guest PC 0x0c01117c */
if(!s->budget--) { s->failed_pc=0x0c00507cu; return 0; }
if(!vf3_matrix_family(0x0c00507eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c00507eu; return 0; } return 1;
P_0c0057f8: /* original d320, guest PC 0x0c0118f8 */
if(!s->budget--) { s->failed_pc=0x0c0057f8u; return 0; }
r[3]=read(ram,0x0c00587cu,4);
goto P_0c0057fa;
P_0c0057fa: /* original e400, guest PC 0x0c0118fa */
if(!s->budget--) { s->failed_pc=0x0c0057fau; return 0; }
r[4]=0x00000000u;
goto P_0c0057fc;
P_0c0057fc: /* original 963c, guest PC 0x0c0118fc */
if(!s->budget--) { s->failed_pc=0x0c0057fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c005878u,2);
goto P_0c0057fe;
P_0c0057fe: /* original 6532, guest PC 0x0c0118fe */
if(!s->budget--) { s->failed_pc=0x0c0057feu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c005800;
P_0c005800: /* original 9739, guest PC 0x0c011900 */
if(!s->budget--) { s->failed_pc=0x0c005800u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c005876u,2);
goto P_0c005802;
P_0c005802: /* original 8458, guest PC 0x0c011902 */
if(!s->budget--) { s->failed_pc=0x0c005802u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+8,1);
goto P_0c005804;
P_0c005804: /* original 2078, guest PC 0x0c011904 */
if(!s->budget--) { s->failed_pc=0x0c005804u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[7])==0)!=0);
goto P_0c005806;
P_0c005806: /* original 8b02, guest PC 0x0c011906 */
if(!s->budget--) { s->failed_pc=0x0c005806u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c00580e; }
goto P_0c005808;
P_0c005808: /* original 7401, guest PC 0x0c011908 */
if(!s->budget--) { s->failed_pc=0x0c005808u; return 0; }
r[4]+=0x00000001u;
goto P_0c00580a;
P_0c00580a: /* original 3463, guest PC 0x0c01190a */
if(!s->budget--) { s->failed_pc=0x0c00580au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c00580c;
P_0c00580c: /* original 8bf9, guest PC 0x0c01190c */
if(!s->budget--) { s->failed_pc=0x0c00580cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c005802; }
goto P_0c00580e;
P_0c00580e: /* original 3460, guest PC 0x0c01190e */
if(!s->budget--) { s->failed_pc=0x0c00580eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[6])!=0);
goto P_0c005810;
P_0c005810: /* original 8910, guest PC 0x0c011910 */
if(!s->budget--) { s->failed_pc=0x0c005810u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c005834; }
goto P_0c005812;
P_0c005812: /* original e010, guest PC 0x0c011912 */
if(!s->budget--) { s->failed_pc=0x0c005812u; return 0; }
r[0]=0x00000010u;
goto P_0c005814;
P_0c005814: /* original 065c, guest PC 0x0c011914 */
if(!s->budget--) { s->failed_pc=0x0c005814u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c005816;
P_0c005816: /* original 646e, guest PC 0x0c011916 */
if(!s->budget--) { s->failed_pc=0x0c005816u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c005818;
P_0c005818: /* original 6043, guest PC 0x0c011918 */
if(!s->budget--) { s->failed_pc=0x0c005818u; return 0; }
r[0]=r[4];
goto P_0c00581a;
P_0c00581a: /* original e314, guest PC 0x0c01191a */
if(!s->budget--) { s->failed_pc=0x0c00581au; return 0; }
r[3]=0x00000014u;
goto P_0c00581c;
P_0c00581c: /* original 8860, guest PC 0x0c01191c */
if(!s->budget--) { s->failed_pc=0x0c00581cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000060u)!=0);
goto P_0c00581e;
P_0c00581e: /* original 335c, guest PC 0x0c01191e */
if(!s->budget--) { s->failed_pc=0x0c00581eu; return 0; }
r[3]+=r[5];
goto P_0c005820;
P_0c005820: /* original 8d06, guest PC 0x0c011920 */
if(!s->budget--) { s->failed_pc=0x0c005820u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
if(cond) { goto P_0c005830; }
goto P_0c005824;
P_0c005822: /* original 6330, guest PC 0x0c011922 */
if(!s->budget--) { s->failed_pc=0x0c005822u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c005824;
P_0c005824: /* original 6043, guest PC 0x0c011924 */
if(!s->budget--) { s->failed_pc=0x0c005824u; return 0; }
r[0]=r[4];
goto P_0c005826;
P_0c005826: /* original 8861, guest PC 0x0c011926 */
if(!s->budget--) { s->failed_pc=0x0c005826u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000061u)!=0);
goto P_0c005828;
P_0c005828: /* original 8902, guest PC 0x0c011928 */
if(!s->budget--) { s->failed_pc=0x0c005828u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c005830; }
goto P_0c00582a;
P_0c00582a: /* original 6043, guest PC 0x0c01192a */
if(!s->budget--) { s->failed_pc=0x0c00582au; return 0; }
r[0]=r[4];
goto P_0c00582c;
P_0c00582c: /* original 8862, guest PC 0x0c01192c */
if(!s->budget--) { s->failed_pc=0x0c00582cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000062u)!=0);
goto P_0c00582e;
P_0c00582e: /* original 8b01, guest PC 0x0c01192e */
if(!s->budget--) { s->failed_pc=0x0c00582eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c005834; }
goto P_0c005830;
P_0c005830: /* original 000b, guest PC 0x0c011930 */
if(!s->budget--) { s->failed_pc=0x0c005830u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c005832: /* original e000, guest PC 0x0c011932 */
if(!s->budget--) { s->failed_pc=0x0c005832u; return 0; }
r[0]=0x00000000u;
goto P_0c005834;
P_0c005834: /* original e001, guest PC 0x0c011934 */
if(!s->budget--) { s->failed_pc=0x0c005834u; return 0; }
r[0]=0x00000001u;
goto P_0c005836;
P_0c005836: /* original 000b, guest PC 0x0c011936 */
if(!s->budget--) { s->failed_pc=0x0c005836u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c005838: /* original 0009, guest PC 0x0c011938 */
if(!s->budget--) { s->failed_pc=0x0c005838u; return 0; }
if(!vf3_matrix_family(0x0c00583au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c00583au; return 0; } return 1;
P_0c005880: /* original d33c, guest PC 0x0c011980 */
if(!s->budget--) { s->failed_pc=0x0c005880u; return 0; }
r[3]=read(ram,0x0c005974u,4);
goto P_0c005882;
P_0c005882: /* original c701, guest PC 0x0c011982 */
if(!s->budget--) { s->failed_pc=0x0c005882u; return 0; }
r[0]=code_base|0x00005888u;
goto P_0c005884;
P_0c005884: /* original 4f22, guest PC 0x0c011984 */
if(!s->budget--) { s->failed_pc=0x0c005884u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c005886;
P_0c005886: /* original 330c, guest PC 0x0c011986 */
if(!s->budget--) { s->failed_pc=0x0c005886u; return 0; }
r[3]+=r[0];
goto P_0c005888;
P_0c005888: /* original d23b, guest PC 0x0c011988 */
if(!s->budget--) { s->failed_pc=0x0c005888u; return 0; }
r[2]=read(ram,0x0c005978u,4);
goto P_0c00588a;
P_0c00588a: /* original 6033, guest PC 0x0c01198a */
if(!s->budget--) { s->failed_pc=0x0c00588au; return 0; }
r[0]=r[3];
goto P_0c00588c;
P_0c00588c: /* original 202b, guest PC 0x0c01198c */
if(!s->budget--) { s->failed_pc=0x0c00588cu; return 0; }
r[0]|=r[2];
goto P_0c00588e;
P_0c00588e: /* original 400b, guest PC 0x0c01198e */
if(!s->budget--) { s->failed_pc=0x0c00588eu; return 0; }
target=r[0];
r[16]=code_base|0x0c005892u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c005892u) { target=s->pc; goto dispatch; }
goto P_0c005892;
P_0c005890: /* original 0009, guest PC 0x0c011990 */
if(!s->budget--) { s->failed_pc=0x0c005890u; return 0; }
goto P_0c005892;
P_0c005892: /* original 2008, guest PC 0x0c011992 */
if(!s->budget--) { s->failed_pc=0x0c005892u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c005894;
P_0c005894: /* original 8902, guest PC 0x0c011994 */
if(!s->budget--) { s->failed_pc=0x0c005894u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c00589c; }
goto P_0c005896;
P_0c005896: /* original 4f26, guest PC 0x0c011996 */
if(!s->budget--) { s->failed_pc=0x0c005896u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c005898;
P_0c005898: /* original 000b, guest PC 0x0c011998 */
if(!s->budget--) { s->failed_pc=0x0c005898u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c00589a: /* original e001, guest PC 0x0c01199a */
if(!s->budget--) { s->failed_pc=0x0c00589au; return 0; }
r[0]=0x00000001u;
goto P_0c00589c;
P_0c00589c: /* original e000, guest PC 0x0c01199c */
if(!s->budget--) { s->failed_pc=0x0c00589cu; return 0; }
r[0]=0x00000000u;
goto P_0c00589e;
P_0c00589e: /* original 4f26, guest PC 0x0c01199e */
if(!s->budget--) { s->failed_pc=0x0c00589eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0058a0;
P_0c0058a0: /* original 000b, guest PC 0x0c0119a0 */
if(!s->budget--) { s->failed_pc=0x0c0058a0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0058a2: /* original 0009, guest PC 0x0c0119a2 */
if(!s->budget--) { s->failed_pc=0x0c0058a2u; return 0; }
if(!vf3_matrix_family(0x0c0058a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0058a4u; return 0; } return 1;
P_0c005990: /* original 7ffc, guest PC 0x0c011a90 */
if(!s->budget--) { s->failed_pc=0x0c005990u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c005992;
P_0c005992: /* original d72d, guest PC 0x0c011a92 */
if(!s->budget--) { s->failed_pc=0x0c005992u; return 0; }
r[7]=read(ram,0x0c005a48u,4);
goto P_0c005994;
P_0c005994: /* original 6053, guest PC 0x0c011a94 */
if(!s->budget--) { s->failed_pc=0x0c005994u; return 0; }
r[0]=r[5];
goto P_0c005996;
P_0c005996: /* original e600, guest PC 0x0c011a96 */
if(!s->budget--) { s->failed_pc=0x0c005996u; return 0; }
r[6]=0x00000000u;
goto P_0c005998;
P_0c005998: /* original 8873, guest PC 0x0c011a98 */
if(!s->budget--) { s->failed_pc=0x0c005998u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000073u)!=0);
goto P_0c00599a;
P_0c00599a: /* original e306, guest PC 0x0c011a9a */
if(!s->budget--) { s->failed_pc=0x0c00599au; return 0; }
r[3]=0x00000006u;
goto P_0c00599c;
P_0c00599c: /* original 2761, guest PC 0x0c011a9c */
if(!s->budget--) { s->failed_pc=0x0c00599cu; return 0; }
write(ram,r[7],r[6],2);
goto P_0c00599e;
P_0c00599e: /* original d22b, guest PC 0x0c011a9e */
if(!s->budget--) { s->failed_pc=0x0c00599eu; return 0; }
r[2]=read(ram,0x0c005a4cu,4);
goto P_0c0059a0;
P_0c0059a0: /* original 2231, guest PC 0x0c011aa0 */
if(!s->budget--) { s->failed_pc=0x0c0059a0u; return 0; }
write(ram,r[2],r[3],2);
goto P_0c0059a2;
P_0c0059a2: /* original d12b, guest PC 0x0c011aa2 */
if(!s->budget--) { s->failed_pc=0x0c0059a2u; return 0; }
r[1]=read(ram,0x0c005a50u,4);
goto P_0c0059a4;
P_0c0059a4: /* original 2161, guest PC 0x0c011aa4 */
if(!s->budget--) { s->failed_pc=0x0c0059a4u; return 0; }
write(ram,r[1],r[6],2);
goto P_0c0059a6;
P_0c0059a6: /* original d42b, guest PC 0x0c011aa6 */
if(!s->budget--) { s->failed_pc=0x0c0059a6u; return 0; }
r[4]=read(ram,0x0c005a54u,4);
goto P_0c0059a8;
P_0c0059a8: /* original 890d, guest PC 0x0c011aa8 */
if(!s->budget--) { s->failed_pc=0x0c0059a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0059c6; }
goto P_0c0059aa;
P_0c0059aa: /* original 914c, guest PC 0x0c011aaa */
if(!s->budget--) { s->failed_pc=0x0c0059aau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c005a46u,2);
goto P_0c0059ac;
P_0c0059ac: /* original 3010, guest PC 0x0c011aac */
if(!s->budget--) { s->failed_pc=0x0c0059acu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0059ae;
P_0c0059ae: /* original 8907, guest PC 0x0c011aae */
if(!s->budget--) { s->failed_pc=0x0c0059aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0059c0; }
goto P_0c0059b0;
P_0c0059b0: /* original d129, guest PC 0x0c011ab0 */
if(!s->budget--) { s->failed_pc=0x0c0059b0u; return 0; }
r[1]=read(ram,0x0c005a58u,4);
goto P_0c0059b2;
P_0c0059b2: /* original 3010, guest PC 0x0c011ab2 */
if(!s->budget--) { s->failed_pc=0x0c0059b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0059b4;
P_0c0059b4: /* original 8904, guest PC 0x0c011ab4 */
if(!s->budget--) { s->failed_pc=0x0c0059b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0059c0; }
goto P_0c0059b6;
P_0c0059b6: /* original d129, guest PC 0x0c011ab6 */
if(!s->budget--) { s->failed_pc=0x0c0059b6u; return 0; }
r[1]=read(ram,0x0c005a5cu,4);
goto P_0c0059b8;
P_0c0059b8: /* original 3010, guest PC 0x0c011ab8 */
if(!s->budget--) { s->failed_pc=0x0c0059b8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c0059ba;
P_0c0059ba: /* original 8904, guest PC 0x0c011aba */
if(!s->budget--) { s->failed_pc=0x0c0059bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0059c6; }
goto P_0c0059bc;
P_0c0059bc: /* original a005, guest PC 0x0c011abc */
if(!s->budget--) { s->failed_pc=0x0c0059bcu; return 0; }
goto P_0c0059ca;
P_0c0059be: /* original 0009, guest PC 0x0c011abe */
if(!s->budget--) { s->failed_pc=0x0c0059beu; return 0; }
goto P_0c0059c0;
P_0c0059c0: /* original e328, guest PC 0x0c011ac0 */
if(!s->budget--) { s->failed_pc=0x0c0059c0u; return 0; }
r[3]=0x00000028u;
goto P_0c0059c2;
P_0c0059c2: /* original a002, guest PC 0x0c011ac2 */
if(!s->budget--) { s->failed_pc=0x0c0059c2u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0059ca;
P_0c0059c4: /* original 2430, guest PC 0x0c011ac4 */
if(!s->budget--) { s->failed_pc=0x0c0059c4u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c0059c6;
P_0c0059c6: /* original e20d, guest PC 0x0c011ac6 */
if(!s->budget--) { s->failed_pc=0x0c0059c6u; return 0; }
r[2]=0x0000000du;
goto P_0c0059c8;
P_0c0059c8: /* original 2420, guest PC 0x0c011ac8 */
if(!s->budget--) { s->failed_pc=0x0c0059c8u; return 0; }
write(ram,r[4],r[2],1);
goto P_0c0059ca;
P_0c0059ca: /* original d425, guest PC 0x0c011aca */
if(!s->budget--) { s->failed_pc=0x0c0059cau; return 0; }
r[4]=read(ram,0x0c005a60u,4);
goto P_0c0059cc;
P_0c0059cc: /* original a003, guest PC 0x0c011acc */
if(!s->budget--) { s->failed_pc=0x0c0059ccu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0059d6;
P_0c0059ce: /* original 2f62, guest PC 0x0c011ace */
if(!s->budget--) { s->failed_pc=0x0c0059ceu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0059d0;
P_0c0059d0: /* original 62f2, guest PC 0x0c011ad0 */
if(!s->budget--) { s->failed_pc=0x0c0059d0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0059d2;
P_0c0059d2: /* original 7201, guest PC 0x0c011ad2 */
if(!s->budget--) { s->failed_pc=0x0c0059d2u; return 0; }
r[2]+=0x00000001u;
goto P_0c0059d4;
P_0c0059d4: /* original 2f22, guest PC 0x0c011ad4 */
if(!s->budget--) { s->failed_pc=0x0c0059d4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0059d6;
P_0c0059d6: /* original 63f2, guest PC 0x0c011ad6 */
if(!s->budget--) { s->failed_pc=0x0c0059d6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0059d8;
P_0c0059d8: /* original 3343, guest PC 0x0c011ad8 */
if(!s->budget--) { s->failed_pc=0x0c0059d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c0059da;
P_0c0059da: /* original 8bf9, guest PC 0x0c011ada */
if(!s->budget--) { s->failed_pc=0x0c0059dau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0059d0; }
goto P_0c0059dc;
P_0c0059dc: /* original d11b, guest PC 0x0c011adc */
if(!s->budget--) { s->failed_pc=0x0c0059dcu; return 0; }
r[1]=read(ram,0x0c005a4cu,4);
goto P_0c0059de;
P_0c0059de: /* original e330, guest PC 0x0c011ade */
if(!s->budget--) { s->failed_pc=0x0c0059deu; return 0; }
r[3]=0x00000030u;
goto P_0c0059e0;
P_0c0059e0: /* original e000, guest PC 0x0c011ae0 */
if(!s->budget--) { s->failed_pc=0x0c0059e0u; return 0; }
r[0]=0x00000000u;
goto P_0c0059e2;
P_0c0059e2: /* original 2161, guest PC 0x0c011ae2 */
if(!s->budget--) { s->failed_pc=0x0c0059e2u; return 0; }
write(ram,r[1],r[6],2);
goto P_0c0059e4;
P_0c0059e4: /* original 2731, guest PC 0x0c011ae4 */
if(!s->budget--) { s->failed_pc=0x0c0059e4u; return 0; }
write(ram,r[7],r[3],2);
goto P_0c0059e6;
P_0c0059e6: /* original 000b, guest PC 0x0c011ae6 */
if(!s->budget--) { s->failed_pc=0x0c0059e6u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c0059e8: /* original 7f04, guest PC 0x0c011ae8 */
if(!s->budget--) { s->failed_pc=0x0c0059e8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0059ea;
P_0c0059ea: /* original d31e, guest PC 0x0c011aea */
if(!s->budget--) { s->failed_pc=0x0c0059eau; return 0; }
r[3]=read(ram,0x0c005a64u,4);
goto P_0c0059ec;
P_0c0059ec: /* original 6031, guest PC 0x0c011aec */
if(!s->budget--) { s->failed_pc=0x0c0059ecu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[0]=tmp;
goto P_0c0059ee;
P_0c0059ee: /* original 600d, guest PC 0x0c011aee */
if(!s->budget--) { s->failed_pc=0x0c0059eeu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0059f0;
P_0c0059f0: /* original c902, guest PC 0x0c011af0 */
if(!s->budget--) { s->failed_pc=0x0c0059f0u; return 0; }
r[0]&=2u;
goto P_0c0059f2;
P_0c0059f2: /* original 8802, guest PC 0x0c011af2 */
if(!s->budget--) { s->failed_pc=0x0c0059f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0059f4;
P_0c0059f4: /* original 8f01, guest PC 0x0c011af4 */
if(!s->budget--) { s->failed_pc=0x0c0059f4u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c0059fa; }
goto P_0c0059f8;
P_0c0059f6: /* original e400, guest PC 0x0c011af6 */
if(!s->budget--) { s->failed_pc=0x0c0059f6u; return 0; }
r[4]=0x00000000u;
goto P_0c0059f8;
P_0c0059f8: /* original e401, guest PC 0x0c011af8 */
if(!s->budget--) { s->failed_pc=0x0c0059f8u; return 0; }
r[4]=0x00000001u;
goto P_0c0059fa;
P_0c0059fa: /* original 000b, guest PC 0x0c011afa */
if(!s->budget--) { s->failed_pc=0x0c0059fau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0059fc: /* original 6043, guest PC 0x0c011afc */
if(!s->budget--) { s->failed_pc=0x0c0059fcu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c0059feu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0059feu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c004000u,
0x0c004002u,
0x0c004004u,
0x0c004006u,
0x0c004008u,
0x0c00400au,
0x0c00400cu,
0x0c00400eu,
0x0c004010u,
0x0c004012u,
0x0c004014u,
0x0c004016u,
0x0c004018u,
0x0c00401au,
0x0c00401cu,
0x0c00401eu,
0x0c004020u,
0x0c004022u,
0x0c004024u,
0x0c004026u,
0x0c004028u,
0x0c00402au,
0x0c00402cu,
0x0c00402eu,
0x0c004030u,
0x0c004032u,
0x0c004070u,
0x0c004072u,
0x0c004074u,
0x0c004076u,
0x0c004078u,
0x0c00407au,
0x0c00407cu,
0x0c00407eu,
0x0c004080u,
0x0c004082u,
0x0c004084u,
0x0c004086u,
0x0c004088u,
0x0c00408au,
0x0c00408cu,
0x0c00408eu,
0x0c004090u,
0x0c004092u,
0x0c004094u,
0x0c004096u,
0x0c004098u,
0x0c00409au,
0x0c00409cu,
0x0c00409eu,
0x0c0040a0u,
0x0c0040a2u,
0x0c0040a4u,
0x0c0040a6u,
0x0c0040a8u,
0x0c0040aau,
0x0c0040acu,
0x0c0040aeu,
0x0c0040b0u,
0x0c0040b2u,
0x0c0040b4u,
0x0c0040b6u,
0x0c0040b8u,
0x0c0040bau,
0x0c0040bcu,
0x0c0040beu,
0x0c0040c0u,
0x0c0040c2u,
0x0c0040c4u,
0x0c0040c6u,
0x0c0040c8u,
0x0c0040cau,
0x0c0040ccu,
0x0c0040ceu,
0x0c0040d0u,
0x0c0040d2u,
0x0c0040d4u,
0x0c0040d6u,
0x0c0040d8u,
0x0c0040dau,
0x0c0040dcu,
0x0c0040deu,
0x0c0040e0u,
0x0c0040e2u,
0x0c0040e4u,
0x0c0040e6u,
0x0c004138u,
0x0c00413au,
0x0c00413cu,
0x0c00413eu,
0x0c004140u,
0x0c004142u,
0x0c004144u,
0x0c004146u,
0x0c004148u,
0x0c00414au,
0x0c00414cu,
0x0c00414eu,
0x0c004150u,
0x0c004152u,
0x0c004154u,
0x0c004156u,
0x0c004158u,
0x0c00415au,
0x0c00415cu,
0x0c00415eu,
0x0c004160u,
0x0c004162u,
0x0c004164u,
0x0c004166u,
0x0c004168u,
0x0c00416au,
0x0c00416cu,
0x0c00416eu,
0x0c004170u,
0x0c004172u,
0x0c004174u,
0x0c004176u,
0x0c004178u,
0x0c00417au,
0x0c00417cu,
0x0c00417eu,
0x0c004180u,
0x0c004182u,
0x0c004184u,
0x0c004186u,
0x0c004188u,
0x0c00418au,
0x0c00418cu,
0x0c00418eu,
0x0c004190u,
0x0c004192u,
0x0c004194u,
0x0c004196u,
0x0c004198u,
0x0c00419au,
0x0c00419cu,
0x0c00419eu,
0x0c0041a0u,
0x0c0041a2u,
0x0c0041a4u,
0x0c0041a6u,
0x0c0041a8u,
0x0c0041aau,
0x0c0041acu,
0x0c0041aeu,
0x0c0041b0u,
0x0c0041b2u,
0x0c0041b4u,
0x0c0041b6u,
0x0c0041b8u,
0x0c0041bau,
0x0c0041bcu,
0x0c0041beu,
0x0c0041c0u,
0x0c0041c2u,
0x0c0041c4u,
0x0c0041c6u,
0x0c0041c8u,
0x0c0041cau,
0x0c0041ccu,
0x0c0041ceu,
0x0c0041d0u,
0x0c0041d2u,
0x0c0041d4u,
0x0c0041d6u,
0x0c0041d8u,
0x0c0041dau,
0x0c0041dcu,
0x0c0041deu,
0x0c0041e0u,
0x0c0041e2u,
0x0c0041e4u,
0x0c0041e6u,
0x0c0041e8u,
0x0c0041eau,
0x0c0041ecu,
0x0c0041eeu,
0x0c0041f0u,
0x0c0041f2u,
0x0c0041f4u,
0x0c0041f6u,
0x0c0041f8u,
0x0c0041fau,
0x0c0041fcu,
0x0c0041feu,
0x0c004200u,
0x0c004202u,
0x0c004204u,
0x0c004206u,
0x0c004208u,
0x0c00420au,
0x0c00420cu,
0x0c00420eu,
0x0c004210u,
0x0c004212u,
0x0c004214u,
0x0c004216u,
0x0c004218u,
0x0c00421au,
0x0c00421cu,
0x0c00421eu,
0x0c004220u,
0x0c004222u,
0x0c004224u,
0x0c004226u,
0x0c004228u,
0x0c00422au,
0x0c004268u,
0x0c00426au,
0x0c00426cu,
0x0c00426eu,
0x0c004270u,
0x0c004272u,
0x0c004274u,
0x0c004276u,
0x0c004278u,
0x0c00427au,
0x0c00427cu,
0x0c00427eu,
0x0c004280u,
0x0c004282u,
0x0c004284u,
0x0c004286u,
0x0c004288u,
0x0c00428au,
0x0c00428cu,
0x0c00428eu,
0x0c004290u,
0x0c004292u,
0x0c004294u,
0x0c004296u,
0x0c004298u,
0x0c00429au,
0x0c00429cu,
0x0c00429eu,
0x0c0042a0u,
0x0c0042a2u,
0x0c0042a4u,
0x0c0042a6u,
0x0c0042a8u,
0x0c0044d4u,
0x0c0044d6u,
0x0c0044d8u,
0x0c0044dau,
0x0c0044dcu,
0x0c0044deu,
0x0c0044e0u,
0x0c0044e2u,
0x0c0044e4u,
0x0c0044e6u,
0x0c0044e8u,
0x0c0044eau,
0x0c0044ecu,
0x0c0044eeu,
0x0c0044f0u,
0x0c0044f2u,
0x0c0044f4u,
0x0c0044f6u,
0x0c0044f8u,
0x0c0044fau,
0x0c0044fcu,
0x0c0044feu,
0x0c004500u,
0x0c004502u,
0x0c004504u,
0x0c004506u,
0x0c004508u,
0x0c00450au,
0x0c00450cu,
0x0c00450eu,
0x0c004510u,
0x0c004512u,
0x0c004514u,
0x0c004516u,
0x0c004518u,
0x0c00451au,
0x0c00451cu,
0x0c00451eu,
0x0c004520u,
0x0c004522u,
0x0c004524u,
0x0c004526u,
0x0c004528u,
0x0c00452au,
0x0c00452cu,
0x0c00452eu,
0x0c004530u,
0x0c004532u,
0x0c004534u,
0x0c004536u,
0x0c004538u,
0x0c00453au,
0x0c00453cu,
0x0c00453eu,
0x0c004540u,
0x0c004542u,
0x0c004544u,
0x0c004546u,
0x0c004548u,
0x0c00454au,
0x0c00454cu,
0x0c00454eu,
0x0c004550u,
0x0c004552u,
0x0c004554u,
0x0c004556u,
0x0c004558u,
0x0c00455au,
0x0c00455cu,
0x0c00455eu,
0x0c004560u,
0x0c004562u,
0x0c004564u,
0x0c004566u,
0x0c004568u,
0x0c00456au,
0x0c00456cu,
0x0c00456eu,
0x0c004570u,
0x0c004572u,
0x0c004574u,
0x0c004576u,
0x0c004578u,
0x0c00457au,
0x0c00457cu,
0x0c00457eu,
0x0c004580u,
0x0c00479au,
0x0c00479cu,
0x0c00479eu,
0x0c0047a0u,
0x0c0047a2u,
0x0c0047a4u,
0x0c0047a6u,
0x0c0047a8u,
0x0c0047aau,
0x0c0047acu,
0x0c0047aeu,
0x0c0047b0u,
0x0c0047b2u,
0x0c0047b4u,
0x0c0047b6u,
0x0c0047b8u,
0x0c0047bau,
0x0c0047bcu,
0x0c0047beu,
0x0c0047c0u,
0x0c0047c2u,
0x0c0047c4u,
0x0c0047c6u,
0x0c0047c8u,
0x0c0047cau,
0x0c0047ccu,
0x0c0047ceu,
0x0c0047d0u,
0x0c0047d2u,
0x0c0047d4u,
0x0c0047d6u,
0x0c0047d8u,
0x0c0047dau,
0x0c0047dcu,
0x0c0047deu,
0x0c0047e0u,
0x0c0047e2u,
0x0c0047e4u,
0x0c0047e6u,
0x0c0047e8u,
0x0c0048f6u,
0x0c0048f8u,
0x0c0048fau,
0x0c0048fcu,
0x0c0048feu,
0x0c004900u,
0x0c004902u,
0x0c004904u,
0x0c004906u,
0x0c004908u,
0x0c00490au,
0x0c00490cu,
0x0c00490eu,
0x0c004910u,
0x0c004912u,
0x0c004914u,
0x0c004916u,
0x0c004918u,
0x0c00491au,
0x0c00491cu,
0x0c00491eu,
0x0c004920u,
0x0c004922u,
0x0c004924u,
0x0c004926u,
0x0c004928u,
0x0c00492au,
0x0c00492cu,
0x0c00492eu,
0x0c004930u,
0x0c004932u,
0x0c004934u,
0x0c004936u,
0x0c004938u,
0x0c004988u,
0x0c00498au,
0x0c00498cu,
0x0c00498eu,
0x0c004990u,
0x0c004992u,
0x0c004994u,
0x0c004996u,
0x0c004998u,
0x0c00499au,
0x0c00499cu,
0x0c00499eu,
0x0c0049a0u,
0x0c0049a2u,
0x0c0049a4u,
0x0c0049a6u,
0x0c0049a8u,
0x0c0049aau,
0x0c0049acu,
0x0c0049aeu,
0x0c0049b0u,
0x0c0049b2u,
0x0c0049b4u,
0x0c0049b6u,
0x0c0049b8u,
0x0c0049bau,
0x0c0049bcu,
0x0c0049beu,
0x0c0049c0u,
0x0c0049c2u,
0x0c0049c4u,
0x0c0049c6u,
0x0c0049c8u,
0x0c0049cau,
0x0c0049ccu,
0x0c0049ceu,
0x0c0049d0u,
0x0c0049d2u,
0x0c0049d4u,
0x0c0049d6u,
0x0c0049d8u,
0x0c0049dau,
0x0c0049dcu,
0x0c0049deu,
0x0c0049e0u,
0x0c0049e2u,
0x0c0049e4u,
0x0c0049e6u,
0x0c0049e8u,
0x0c0049eau,
0x0c0049ecu,
0x0c0049eeu,
0x0c0049f0u,
0x0c0049f2u,
0x0c0049f4u,
0x0c0049f6u,
0x0c0049f8u,
0x0c0049fau,
0x0c0049fcu,
0x0c0049feu,
0x0c004a00u,
0x0c004a02u,
0x0c004a04u,
0x0c004a06u,
0x0c004a08u,
0x0c004a0au,
0x0c004a0cu,
0x0c004a0eu,
0x0c004a10u,
0x0c004a12u,
0x0c004a14u,
0x0c004a16u,
0x0c004a18u,
0x0c004a1au,
0x0c004a1cu,
0x0c004a1eu,
0x0c004a20u,
0x0c004a22u,
0x0c004a24u,
0x0c004a26u,
0x0c004a28u,
0x0c004a2au,
0x0c004a2cu,
0x0c004a2eu,
0x0c004a30u,
0x0c004a32u,
0x0c004a34u,
0x0c004a36u,
0x0c004a38u,
0x0c004a3au,
0x0c004a3cu,
0x0c004a3eu,
0x0c004a40u,
0x0c004a42u,
0x0c004a44u,
0x0c004a46u,
0x0c004a48u,
0x0c004a4au,
0x0c004a4cu,
0x0c004a4eu,
0x0c004a50u,
0x0c004a52u,
0x0c004a54u,
0x0c004a56u,
0x0c004a58u,
0x0c004a5au,
0x0c004a5cu,
0x0c004a5eu,
0x0c004a60u,
0x0c004a62u,
0x0c004a64u,
0x0c004a66u,
0x0c004a68u,
0x0c004a6au,
0x0c004a6cu,
0x0c004a6eu,
0x0c004a70u,
0x0c004a72u,
0x0c004a74u,
0x0c004a76u,
0x0c004a78u,
0x0c004a7au,
0x0c004a7cu,
0x0c004a7eu,
0x0c004a80u,
0x0c004a82u,
0x0c004a84u,
0x0c004a86u,
0x0c004a88u,
0x0c004a8au,
0x0c004a8cu,
0x0c004a8eu,
0x0c004a90u,
0x0c004a92u,
0x0c004a94u,
0x0c004b18u,
0x0c004b1au,
0x0c004b1cu,
0x0c004b1eu,
0x0c004b20u,
0x0c004b22u,
0x0c004b24u,
0x0c004b26u,
0x0c004b28u,
0x0c004b2au,
0x0c004b2cu,
0x0c004b2eu,
0x0c004b30u,
0x0c004b32u,
0x0c004b34u,
0x0c004b36u,
0x0c004b38u,
0x0c004b3au,
0x0c004b3cu,
0x0c004b3eu,
0x0c004b40u,
0x0c004b42u,
0x0c004b44u,
0x0c004b46u,
0x0c004b48u,
0x0c004b4au,
0x0c004b4cu,
0x0c004b4eu,
0x0c004b50u,
0x0c004b52u,
0x0c004b54u,
0x0c004b56u,
0x0c004b58u,
0x0c004b5au,
0x0c004b5cu,
0x0c004b5eu,
0x0c004b60u,
0x0c004b62u,
0x0c004b64u,
0x0c004b66u,
0x0c004b68u,
0x0c004b6au,
0x0c004b6cu,
0x0c004b6eu,
0x0c004b70u,
0x0c004b72u,
0x0c004b74u,
0x0c004b76u,
0x0c004b78u,
0x0c004b7au,
0x0c004b7cu,
0x0c004b7eu,
0x0c004b80u,
0x0c004b82u,
0x0c004b84u,
0x0c004b86u,
0x0c004b88u,
0x0c004b8au,
0x0c004b8cu,
0x0c004b8eu,
0x0c004b90u,
0x0c004b92u,
0x0c004b94u,
0x0c004b96u,
0x0c004b98u,
0x0c004b9au,
0x0c004b9cu,
0x0c004b9eu,
0x0c004ba0u,
0x0c004ba2u,
0x0c004ba4u,
0x0c004ba6u,
0x0c004ba8u,
0x0c004baau,
0x0c004bacu,
0x0c004baeu,
0x0c004bb0u,
0x0c004bb2u,
0x0c004bb4u,
0x0c004bb6u,
0x0c004bb8u,
0x0c004bbau,
0x0c004bbcu,
0x0c004bbeu,
0x0c004bc0u,
0x0c004bc2u,
0x0c004bc4u,
0x0c004bc6u,
0x0c004bc8u,
0x0c004bcau,
0x0c004bccu,
0x0c004bceu,
0x0c004bd0u,
0x0c004bd2u,
0x0c004bd4u,
0x0c004bd6u,
0x0c004bd8u,
0x0c004bdau,
0x0c004bdcu,
0x0c004bdeu,
0x0c004be0u,
0x0c004be2u,
0x0c004be4u,
0x0c004e3cu,
0x0c004e3eu,
0x0c004e40u,
0x0c004e42u,
0x0c004e44u,
0x0c004e46u,
0x0c004e48u,
0x0c004e4au,
0x0c004e4cu,
0x0c004e4eu,
0x0c004e50u,
0x0c004e52u,
0x0c004e54u,
0x0c004e56u,
0x0c004e58u,
0x0c004e5au,
0x0c004e5cu,
0x0c004e5eu,
0x0c004e60u,
0x0c004e62u,
0x0c004e64u,
0x0c004e66u,
0x0c004e68u,
0x0c004e6au,
0x0c004e6cu,
0x0c004e6eu,
0x0c004e70u,
0x0c004e72u,
0x0c004e74u,
0x0c004e76u,
0x0c004e78u,
0x0c004e7au,
0x0c004e7cu,
0x0c004e7eu,
0x0c004e80u,
0x0c004e82u,
0x0c004e84u,
0x0c004e86u,
0x0c004e88u,
0x0c004e8au,
0x0c004e8cu,
0x0c004e8eu,
0x0c004e90u,
0x0c004e92u,
0x0c004e94u,
0x0c004e96u,
0x0c004e98u,
0x0c004e9au,
0x0c004e9cu,
0x0c004e9eu,
0x0c004ea0u,
0x0c004ea2u,
0x0c004ea4u,
0x0c004ea6u,
0x0c004ea8u,
0x0c004eaau,
0x0c004eacu,
0x0c004eaeu,
0x0c004eb0u,
0x0c004eb2u,
0x0c004eb4u,
0x0c004eb6u,
0x0c004eb8u,
0x0c004ebau,
0x0c004ebcu,
0x0c004ebeu,
0x0c004ec0u,
0x0c004ec2u,
0x0c004ec4u,
0x0c004ec6u,
0x0c004ec8u,
0x0c004ecau,
0x0c004eccu,
0x0c004eceu,
0x0c004ed0u,
0x0c004ed2u,
0x0c004ed4u,
0x0c004ed6u,
0x0c004ed8u,
0x0c004edau,
0x0c004edcu,
0x0c004edeu,
0x0c004ee0u,
0x0c004ee2u,
0x0c004ee4u,
0x0c004ee6u,
0x0c004ee8u,
0x0c004eeau,
0x0c004eecu,
0x0c004eeeu,
0x0c004ef0u,
0x0c004ef2u,
0x0c004ef4u,
0x0c004ef6u,
0x0c004ef8u,
0x0c004efau,
0x0c004efcu,
0x0c004efeu,
0x0c004f00u,
0x0c004f02u,
0x0c004f04u,
0x0c004f06u,
0x0c004f08u,
0x0c004f0au,
0x0c004f0cu,
0x0c004f0eu,
0x0c004f10u,
0x0c004f12u,
0x0c004f14u,
0x0c004f16u,
0x0c004f18u,
0x0c004f1au,
0x0c004f1cu,
0x0c004f1eu,
0x0c004f20u,
0x0c004f22u,
0x0c004f24u,
0x0c004f26u,
0x0c004f28u,
0x0c004f2au,
0x0c004f2cu,
0x0c004f2eu,
0x0c004f30u,
0x0c004f32u,
0x0c004f34u,
0x0c004f36u,
0x0c004f38u,
0x0c004f3au,
0x0c004f3cu,
0x0c004f3eu,
0x0c004f40u,
0x0c004f42u,
0x0c00502au,
0x0c00502cu,
0x0c00502eu,
0x0c005030u,
0x0c005032u,
0x0c005034u,
0x0c005036u,
0x0c005038u,
0x0c00503au,
0x0c00503cu,
0x0c00503eu,
0x0c005040u,
0x0c005042u,
0x0c005044u,
0x0c005046u,
0x0c005048u,
0x0c00504au,
0x0c00504cu,
0x0c00504eu,
0x0c005050u,
0x0c005052u,
0x0c005054u,
0x0c005056u,
0x0c005058u,
0x0c00505au,
0x0c00505cu,
0x0c00505eu,
0x0c005060u,
0x0c005062u,
0x0c005064u,
0x0c005066u,
0x0c005068u,
0x0c00506au,
0x0c00506cu,
0x0c00506eu,
0x0c005070u,
0x0c005072u,
0x0c005074u,
0x0c005076u,
0x0c005078u,
0x0c00507au,
0x0c00507cu,
0x0c0057f8u,
0x0c0057fau,
0x0c0057fcu,
0x0c0057feu,
0x0c005800u,
0x0c005802u,
0x0c005804u,
0x0c005806u,
0x0c005808u,
0x0c00580au,
0x0c00580cu,
0x0c00580eu,
0x0c005810u,
0x0c005812u,
0x0c005814u,
0x0c005816u,
0x0c005818u,
0x0c00581au,
0x0c00581cu,
0x0c00581eu,
0x0c005820u,
0x0c005822u,
0x0c005824u,
0x0c005826u,
0x0c005828u,
0x0c00582au,
0x0c00582cu,
0x0c00582eu,
0x0c005830u,
0x0c005832u,
0x0c005834u,
0x0c005836u,
0x0c005838u,
0x0c005880u,
0x0c005882u,
0x0c005884u,
0x0c005886u,
0x0c005888u,
0x0c00588au,
0x0c00588cu,
0x0c00588eu,
0x0c005890u,
0x0c005892u,
0x0c005894u,
0x0c005896u,
0x0c005898u,
0x0c00589au,
0x0c00589cu,
0x0c00589eu,
0x0c0058a0u,
0x0c0058a2u,
0x0c005990u,
0x0c005992u,
0x0c005994u,
0x0c005996u,
0x0c005998u,
0x0c00599au,
0x0c00599cu,
0x0c00599eu,
0x0c0059a0u,
0x0c0059a2u,
0x0c0059a4u,
0x0c0059a6u,
0x0c0059a8u,
0x0c0059aau,
0x0c0059acu,
0x0c0059aeu,
0x0c0059b0u,
0x0c0059b2u,
0x0c0059b4u,
0x0c0059b6u,
0x0c0059b8u,
0x0c0059bau,
0x0c0059bcu,
0x0c0059beu,
0x0c0059c0u,
0x0c0059c2u,
0x0c0059c4u,
0x0c0059c6u,
0x0c0059c8u,
0x0c0059cau,
0x0c0059ccu,
0x0c0059ceu,
0x0c0059d0u,
0x0c0059d2u,
0x0c0059d4u,
0x0c0059d6u,
0x0c0059d8u,
0x0c0059dau,
0x0c0059dcu,
0x0c0059deu,
0x0c0059e0u,
0x0c0059e2u,
0x0c0059e4u,
0x0c0059e6u,
0x0c0059e8u,
0x0c0059eau,
0x0c0059ecu,
0x0c0059eeu,
0x0c0059f0u,
0x0c0059f2u,
0x0c0059f4u,
0x0c0059f6u,
0x0c0059f8u,
0x0c0059fau,
0x0c0059fcu
};
static const uint32_t claim_pcs[]={
0x0c004000u,
0x0c004002u,
0x0c004004u,
0x0c004006u,
0x0c004008u,
0x0c00400au,
0x0c00400cu,
0x0c00400eu,
0x0c004010u,
0x0c004012u,
0x0c004014u,
0x0c004016u,
0x0c004018u,
0x0c00401au,
0x0c00401cu,
0x0c00401eu,
0x0c004020u,
0x0c004022u,
0x0c004024u,
0x0c004026u,
0x0c004028u,
0x0c00402au,
0x0c00402cu,
0x0c00402eu,
0x0c004030u,
0x0c004032u,
0x0c004070u,
0x0c004072u,
0x0c004074u,
0x0c004076u,
0x0c004078u,
0x0c00407au,
0x0c00407cu,
0x0c00407eu,
0x0c004080u,
0x0c004082u,
0x0c004084u,
0x0c004086u,
0x0c004088u,
0x0c00408au,
0x0c00408cu,
0x0c00408eu,
0x0c004090u,
0x0c004092u,
0x0c004094u,
0x0c004096u,
0x0c004098u,
0x0c00409au,
0x0c00409cu,
0x0c00409eu,
0x0c0040a0u,
0x0c0040a2u,
0x0c0040a4u,
0x0c0040a6u,
0x0c0040a8u,
0x0c0040aau,
0x0c0040acu,
0x0c0040aeu,
0x0c0040b0u,
0x0c0040b2u,
0x0c0040b4u,
0x0c0040b6u,
0x0c0040b8u,
0x0c0040bau,
0x0c0040bcu,
0x0c0040beu,
0x0c0040c0u,
0x0c0040c2u,
0x0c0040c4u,
0x0c0040c6u,
0x0c0040c8u,
0x0c0040cau,
0x0c0040ccu,
0x0c0040ceu,
0x0c0040d0u,
0x0c0040d2u,
0x0c0040d4u,
0x0c0040d6u,
0x0c0040d8u,
0x0c0040dau,
0x0c0040dcu,
0x0c0040deu,
0x0c0040e0u,
0x0c0040e2u,
0x0c0040e4u,
0x0c0040e6u,
0x0c004138u,
0x0c00413au,
0x0c00413cu,
0x0c00413eu,
0x0c004140u,
0x0c004142u,
0x0c004144u,
0x0c004146u,
0x0c004148u,
0x0c00414au,
0x0c00414cu,
0x0c00414eu,
0x0c004150u,
0x0c004152u,
0x0c004154u,
0x0c004156u,
0x0c004158u,
0x0c00415au,
0x0c00415cu,
0x0c00415eu,
0x0c004160u,
0x0c004162u,
0x0c004164u,
0x0c004166u,
0x0c004168u,
0x0c00416au,
0x0c00416cu,
0x0c00416eu,
0x0c004170u,
0x0c004172u,
0x0c004174u,
0x0c004176u,
0x0c004178u,
0x0c00417au,
0x0c00417cu,
0x0c00417eu,
0x0c004180u,
0x0c004182u,
0x0c004184u,
0x0c004186u,
0x0c004188u,
0x0c00418au,
0x0c00418cu,
0x0c00418eu,
0x0c004190u,
0x0c004192u,
0x0c004194u,
0x0c004196u,
0x0c004198u,
0x0c00419au,
0x0c00419cu,
0x0c00419eu,
0x0c0041a0u,
0x0c0041a2u,
0x0c0041a4u,
0x0c0041a6u,
0x0c0041a8u,
0x0c0041aau,
0x0c0041acu,
0x0c0041aeu,
0x0c0041b0u,
0x0c0041b2u,
0x0c0041b4u,
0x0c0041b6u,
0x0c0041b8u,
0x0c0041bau,
0x0c0041bcu,
0x0c0041beu,
0x0c0041c0u,
0x0c0041c2u,
0x0c0041c4u,
0x0c0041c6u,
0x0c0041c8u,
0x0c0041cau,
0x0c0041ccu,
0x0c0041ceu,
0x0c0041d0u,
0x0c0041d2u,
0x0c0041d4u,
0x0c0041d6u,
0x0c0041d8u,
0x0c0041dau,
0x0c0041dcu,
0x0c0041deu,
0x0c0041e0u,
0x0c0041e2u,
0x0c0041e4u,
0x0c0041e6u,
0x0c0041e8u,
0x0c0041eau,
0x0c0041ecu,
0x0c0041eeu,
0x0c0041f0u,
0x0c0041f2u,
0x0c0041f4u,
0x0c0041f6u,
0x0c0041f8u,
0x0c0041fau,
0x0c0041fcu,
0x0c0041feu,
0x0c004200u,
0x0c004202u,
0x0c004204u,
0x0c004206u,
0x0c004208u,
0x0c00420au,
0x0c00420cu,
0x0c00420eu,
0x0c004210u,
0x0c004212u,
0x0c004214u,
0x0c004216u,
0x0c004218u,
0x0c00421au,
0x0c00421cu,
0x0c00421eu,
0x0c004220u,
0x0c004222u,
0x0c004224u,
0x0c004226u,
0x0c004228u,
0x0c00422au,
0x0c004268u,
0x0c00426au,
0x0c00426cu,
0x0c00426eu,
0x0c004270u,
0x0c004272u,
0x0c004274u,
0x0c004276u,
0x0c004278u,
0x0c00427au,
0x0c00427cu,
0x0c00427eu,
0x0c004280u,
0x0c004282u,
0x0c004284u,
0x0c004286u,
0x0c004288u,
0x0c00428au,
0x0c00428cu,
0x0c00428eu,
0x0c004290u,
0x0c004292u,
0x0c004294u,
0x0c004296u,
0x0c004298u,
0x0c00429au,
0x0c00429cu,
0x0c00429eu,
0x0c0042a0u,
0x0c0042a2u,
0x0c0042a4u,
0x0c0042a6u,
0x0c0042a8u,
0x0c0044d4u,
0x0c0044d6u,
0x0c0044d8u,
0x0c0044dau,
0x0c0044dcu,
0x0c0044deu,
0x0c0044e0u,
0x0c0044e2u,
0x0c0044e4u,
0x0c0044e6u,
0x0c0044e8u,
0x0c0044eau,
0x0c0044ecu,
0x0c0044eeu,
0x0c0044f0u,
0x0c0044f2u,
0x0c0044f4u,
0x0c0044f6u,
0x0c0044f8u,
0x0c0044fau,
0x0c0044fcu,
0x0c0044feu,
0x0c004500u,
0x0c004502u,
0x0c004504u,
0x0c004506u,
0x0c004508u,
0x0c00450au,
0x0c00450cu,
0x0c00450eu,
0x0c004510u,
0x0c004512u,
0x0c004514u,
0x0c004516u,
0x0c004518u,
0x0c00451au,
0x0c00451cu,
0x0c00451eu,
0x0c004520u,
0x0c004522u,
0x0c004524u,
0x0c004526u,
0x0c004528u,
0x0c00452au,
0x0c00452cu,
0x0c00452eu,
0x0c004530u,
0x0c004532u,
0x0c004534u,
0x0c004536u,
0x0c004538u,
0x0c00453au,
0x0c00453cu,
0x0c00453eu,
0x0c004540u,
0x0c004542u,
0x0c004544u,
0x0c004546u,
0x0c004548u,
0x0c00454au,
0x0c00454cu,
0x0c00454eu,
0x0c004550u,
0x0c004552u,
0x0c004554u,
0x0c004556u,
0x0c004558u,
0x0c00455au,
0x0c00455cu,
0x0c00455eu,
0x0c004560u,
0x0c004562u,
0x0c004564u,
0x0c004566u,
0x0c004568u,
0x0c00456au,
0x0c00456cu,
0x0c00456eu,
0x0c004570u,
0x0c004572u,
0x0c004574u,
0x0c004576u,
0x0c004578u,
0x0c00457au,
0x0c00457cu,
0x0c00457eu,
0x0c004580u,
0x0c00479au,
0x0c00479cu,
0x0c00479eu,
0x0c0047a0u,
0x0c0047a2u,
0x0c0047a4u,
0x0c0047a6u,
0x0c0047a8u,
0x0c0047aau,
0x0c0047acu,
0x0c0047aeu,
0x0c0047b0u,
0x0c0047b2u,
0x0c0047b4u,
0x0c0047b6u,
0x0c0047b8u,
0x0c0047bau,
0x0c0047bcu,
0x0c0047beu,
0x0c0047c0u,
0x0c0047c2u,
0x0c0047c4u,
0x0c0047c6u,
0x0c0047c8u,
0x0c0047cau,
0x0c0047ccu,
0x0c0047ceu,
0x0c0047d0u,
0x0c0047d2u,
0x0c0047d4u,
0x0c0047d6u,
0x0c0047d8u,
0x0c0047dau,
0x0c0047dcu,
0x0c0047deu,
0x0c0047e0u,
0x0c0047e2u,
0x0c0047e4u,
0x0c0047e6u,
0x0c0047e8u,
0x0c0048f6u,
0x0c0048f8u,
0x0c0048fau,
0x0c0048fcu,
0x0c0048feu,
0x0c004900u,
0x0c004902u,
0x0c004904u,
0x0c004906u,
0x0c004908u,
0x0c00490au,
0x0c00490cu,
0x0c00490eu,
0x0c004910u,
0x0c004912u,
0x0c004914u,
0x0c004916u,
0x0c004918u,
0x0c00491au,
0x0c00491cu,
0x0c00491eu,
0x0c004920u,
0x0c004922u,
0x0c004924u,
0x0c004926u,
0x0c004928u,
0x0c00492au,
0x0c00492cu,
0x0c00492eu,
0x0c004930u,
0x0c004932u,
0x0c004934u,
0x0c004936u,
0x0c004938u,
0x0c004988u,
0x0c00498au,
0x0c00498cu,
0x0c00498eu,
0x0c004990u,
0x0c004992u,
0x0c004994u,
0x0c004996u,
0x0c004998u,
0x0c00499au,
0x0c00499cu,
0x0c00499eu,
0x0c0049a0u,
0x0c0049a2u,
0x0c0049a4u,
0x0c0049a6u,
0x0c0049a8u,
0x0c0049aau,
0x0c0049acu,
0x0c0049aeu,
0x0c0049b0u,
0x0c0049b2u,
0x0c0049b4u,
0x0c0049b6u,
0x0c0049b8u,
0x0c0049bau,
0x0c0049bcu,
0x0c0049beu,
0x0c0049c0u,
0x0c0049c2u,
0x0c0049c4u,
0x0c0049c6u,
0x0c0049c8u,
0x0c0049cau,
0x0c0049ccu,
0x0c0049ceu,
0x0c0049d0u,
0x0c0049d2u,
0x0c0049d4u,
0x0c0049d6u,
0x0c0049d8u,
0x0c0049dau,
0x0c0049dcu,
0x0c0049deu,
0x0c0049e0u,
0x0c0049e2u,
0x0c0049e4u,
0x0c0049e6u,
0x0c0049e8u,
0x0c0049eau,
0x0c0049ecu,
0x0c0049eeu,
0x0c0049f0u,
0x0c0049f2u,
0x0c0049f4u,
0x0c0049f6u,
0x0c0049f8u,
0x0c0049fau,
0x0c0049fcu,
0x0c0049feu,
0x0c004a00u,
0x0c004a02u,
0x0c004a04u,
0x0c004a06u,
0x0c004a08u,
0x0c004a0au,
0x0c004a0cu,
0x0c004a0eu,
0x0c004a10u,
0x0c004a12u,
0x0c004a14u,
0x0c004a16u,
0x0c004a18u,
0x0c004a1au,
0x0c004a1cu,
0x0c004a1eu,
0x0c004a20u,
0x0c004a22u,
0x0c004a24u,
0x0c004a26u,
0x0c004a28u,
0x0c004a2au,
0x0c004a2cu,
0x0c004a2eu,
0x0c004a30u,
0x0c004a32u,
0x0c004a34u,
0x0c004a36u,
0x0c004a38u,
0x0c004a3au,
0x0c004a3cu,
0x0c004a3eu,
0x0c004a40u,
0x0c004a42u,
0x0c004a44u,
0x0c004a46u,
0x0c004a48u,
0x0c004a4au,
0x0c004a4cu,
0x0c004a4eu,
0x0c004a50u,
0x0c004a52u,
0x0c004a54u,
0x0c004a56u,
0x0c004a58u,
0x0c004a5au,
0x0c004a5cu,
0x0c004a5eu,
0x0c004a60u,
0x0c004a62u,
0x0c004a64u,
0x0c004a66u,
0x0c004a68u,
0x0c004a6au,
0x0c004a6cu,
0x0c004a6eu,
0x0c004a70u,
0x0c004a72u,
0x0c004a74u,
0x0c004a76u,
0x0c004a78u,
0x0c004a7au,
0x0c004a7cu,
0x0c004a7eu,
0x0c004a80u,
0x0c004a82u,
0x0c004a84u,
0x0c004a86u,
0x0c004a88u,
0x0c004a8au,
0x0c004a8cu,
0x0c004a8eu,
0x0c004a90u,
0x0c004a92u,
0x0c004a94u,
0x0c004b18u,
0x0c004b1au,
0x0c004b1cu,
0x0c004b1eu,
0x0c004b20u,
0x0c004b22u,
0x0c004b24u,
0x0c004b26u,
0x0c004b28u,
0x0c004b2au,
0x0c004b2cu,
0x0c004b2eu,
0x0c004b30u,
0x0c004b32u,
0x0c004b34u,
0x0c004b36u,
0x0c004b38u,
0x0c004b3au,
0x0c004b3cu,
0x0c004b3eu,
0x0c004b40u,
0x0c004b42u,
0x0c004b44u,
0x0c004b46u,
0x0c004b48u,
0x0c004b4au,
0x0c004b4cu,
0x0c004b4eu,
0x0c004b50u,
0x0c004b52u,
0x0c004b54u,
0x0c004b56u,
0x0c004b58u,
0x0c004b5au,
0x0c004b5cu,
0x0c004b5eu,
0x0c004b60u,
0x0c004b62u,
0x0c004b64u,
0x0c004b66u,
0x0c004b68u,
0x0c004b6au,
0x0c004b6cu,
0x0c004b6eu,
0x0c004b70u,
0x0c004b72u,
0x0c004b74u,
0x0c004b76u,
0x0c004b78u,
0x0c004b7au,
0x0c004b7cu,
0x0c004b7eu,
0x0c004b80u,
0x0c004b82u,
0x0c004b84u,
0x0c004b86u,
0x0c004b88u,
0x0c004b8au,
0x0c004b8cu,
0x0c004b8eu,
0x0c004b90u,
0x0c004b92u,
0x0c004b94u,
0x0c004b96u,
0x0c004b98u,
0x0c004b9au,
0x0c004b9cu,
0x0c004b9eu,
0x0c004ba0u,
0x0c004ba2u,
0x0c004ba4u,
0x0c004ba6u,
0x0c004ba8u,
0x0c004baau,
0x0c004bacu,
0x0c004baeu,
0x0c004bb0u,
0x0c004bb2u,
0x0c004bb4u,
0x0c004bb6u,
0x0c004bb8u,
0x0c004bbau,
0x0c004bbcu,
0x0c004bbeu,
0x0c004bc0u,
0x0c004bc2u,
0x0c004bc4u,
0x0c004bc6u,
0x0c004bc8u,
0x0c004bcau,
0x0c004bccu,
0x0c004bceu,
0x0c004bd0u,
0x0c004bd2u,
0x0c004bd4u,
0x0c004bd6u,
0x0c004bd8u,
0x0c004bdau,
0x0c004bdcu,
0x0c004bdeu,
0x0c004be0u,
0x0c004be2u,
0x0c004be4u,
0x0c004e3cu,
0x0c004e3eu,
0x0c004e40u,
0x0c004e42u,
0x0c004e44u,
0x0c004e46u,
0x0c004e48u,
0x0c004e4au,
0x0c004e4cu,
0x0c004e4eu,
0x0c004e50u,
0x0c004e52u,
0x0c004e54u,
0x0c004e56u,
0x0c004e58u,
0x0c004e5au,
0x0c004e5cu,
0x0c004e5eu,
0x0c004e60u,
0x0c004e62u,
0x0c004e64u,
0x0c004e66u,
0x0c004e68u,
0x0c004e6au,
0x0c004e6cu,
0x0c004e6eu,
0x0c004e70u,
0x0c004e72u,
0x0c004e74u,
0x0c004e76u,
0x0c004e78u,
0x0c004e7au,
0x0c004e7cu,
0x0c004e7eu,
0x0c004e80u,
0x0c004e82u,
0x0c004e84u,
0x0c004e86u,
0x0c004e88u,
0x0c004e8au,
0x0c004e8cu,
0x0c004e8eu,
0x0c004e90u,
0x0c004e92u,
0x0c004e94u,
0x0c004e96u,
0x0c004e98u,
0x0c004e9au,
0x0c004e9cu,
0x0c004e9eu,
0x0c004ea0u,
0x0c004ea2u,
0x0c004ea4u,
0x0c004ea6u,
0x0c004ea8u,
0x0c004eaau,
0x0c004eacu,
0x0c004eaeu,
0x0c004eb0u,
0x0c004eb2u,
0x0c004eb4u,
0x0c004eb6u,
0x0c004eb8u,
0x0c004ebau,
0x0c004ebcu,
0x0c004ebeu,
0x0c004ec0u,
0x0c004ec2u,
0x0c004ec4u,
0x0c004ec6u,
0x0c004ec8u,
0x0c004ecau,
0x0c004eccu,
0x0c004eceu,
0x0c004ed0u,
0x0c004ed2u,
0x0c004ed4u,
0x0c004ed6u,
0x0c004ed8u,
0x0c004edau,
0x0c004edcu,
0x0c004edeu,
0x0c004ee0u,
0x0c004ee2u,
0x0c004ee4u,
0x0c004ee6u,
0x0c004ee8u,
0x0c004eeau,
0x0c004eecu,
0x0c004eeeu,
0x0c004ef0u,
0x0c004ef2u,
0x0c004ef4u,
0x0c004ef6u,
0x0c004ef8u,
0x0c004efau,
0x0c004efcu,
0x0c004efeu,
0x0c004f00u,
0x0c004f02u,
0x0c004f04u,
0x0c004f06u,
0x0c004f08u,
0x0c004f0au,
0x0c004f0cu,
0x0c004f0eu,
0x0c004f10u,
0x0c004f12u,
0x0c004f14u,
0x0c004f16u,
0x0c004f18u,
0x0c004f1au,
0x0c004f1cu,
0x0c004f1eu,
0x0c004f20u,
0x0c004f22u,
0x0c004f24u,
0x0c004f26u,
0x0c004f28u,
0x0c004f2au,
0x0c004f2cu,
0x0c004f2eu,
0x0c004f30u,
0x0c004f32u,
0x0c004f34u,
0x0c004f36u,
0x0c004f38u,
0x0c004f3au,
0x0c004f3cu,
0x0c004f3eu,
0x0c004f40u,
0x0c004f42u,
0x0c00502au,
0x0c00502cu,
0x0c00502eu,
0x0c005030u,
0x0c005032u,
0x0c005034u,
0x0c005036u,
0x0c005038u,
0x0c00503au,
0x0c00503cu,
0x0c00503eu,
0x0c005040u,
0x0c005042u,
0x0c005044u,
0x0c005046u,
0x0c005048u,
0x0c00504au,
0x0c00504cu,
0x0c00504eu,
0x0c005050u,
0x0c005052u,
0x0c005054u,
0x0c005056u,
0x0c005058u,
0x0c00505au,
0x0c00505cu,
0x0c00505eu,
0x0c005060u,
0x0c005062u,
0x0c005064u,
0x0c005066u,
0x0c005068u,
0x0c00506au,
0x0c00506cu,
0x0c00506eu,
0x0c005070u,
0x0c005072u,
0x0c005074u,
0x0c005076u,
0x0c005078u,
0x0c00507au,
0x0c00507cu,
0x0c0057f8u,
0x0c0057fau,
0x0c0057fcu,
0x0c0057feu,
0x0c005800u,
0x0c005802u,
0x0c005804u,
0x0c005806u,
0x0c005808u,
0x0c00580au,
0x0c00580cu,
0x0c00580eu,
0x0c005810u,
0x0c005812u,
0x0c005814u,
0x0c005816u,
0x0c005818u,
0x0c00581au,
0x0c00581cu,
0x0c00581eu,
0x0c005820u,
0x0c005822u,
0x0c005824u,
0x0c005826u,
0x0c005828u,
0x0c00582au,
0x0c00582cu,
0x0c00582eu,
0x0c005830u,
0x0c005832u,
0x0c005834u,
0x0c005836u,
0x0c005838u,
0x0c005880u,
0x0c005882u,
0x0c005884u,
0x0c005886u,
0x0c005888u,
0x0c00588au,
0x0c00588cu,
0x0c00588eu,
0x0c005890u,
0x0c005892u,
0x0c005894u,
0x0c005896u,
0x0c005898u,
0x0c00589au,
0x0c00589cu,
0x0c00589eu,
0x0c0058a0u,
0x0c0058a2u,
0x0c005990u,
0x0c005992u,
0x0c005994u,
0x0c005996u,
0x0c005998u,
0x0c00599au,
0x0c00599cu,
0x0c00599eu,
0x0c0059a0u,
0x0c0059a2u,
0x0c0059a4u,
0x0c0059a6u,
0x0c0059a8u,
0x0c0059aau,
0x0c0059acu,
0x0c0059aeu,
0x0c0059b0u,
0x0c0059b2u,
0x0c0059b4u,
0x0c0059b6u,
0x0c0059b8u,
0x0c0059bau,
0x0c0059bcu,
0x0c0059beu,
0x0c0059c0u,
0x0c0059c2u,
0x0c0059c4u,
0x0c0059c6u,
0x0c0059c8u,
0x0c0059cau,
0x0c0059ccu,
0x0c0059ceu,
0x0c0059d0u,
0x0c0059d2u,
0x0c0059d4u,
0x0c0059d6u,
0x0c0059d8u,
0x0c0059dau,
0x0c0059dcu,
0x0c0059deu,
0x0c0059e0u,
0x0c0059e2u,
0x0c0059e4u,
0x0c0059e6u,
0x0c0059e8u,
0x0c0059eau,
0x0c0059ecu,
0x0c0059eeu,
0x0c0059f0u,
0x0c0059f2u,
0x0c0059f4u,
0x0c0059f6u,
0x0c0059f8u,
0x0c0059fau,
0x0c0059fcu
};
int vf3_boot_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
