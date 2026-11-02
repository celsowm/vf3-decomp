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
int vf3_away_batch6_adapter_27(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05500cu: goto P_0c05500c;
case 0x0c05500eu: goto P_0c05500e;
case 0x0c055020u: goto P_0c055020;
case 0x0c055022u: goto P_0c055022;
case 0x0c055024u: goto P_0c055024;
case 0x0c055026u: goto P_0c055026;
case 0x0c055028u: goto P_0c055028;
case 0x0c05502au: goto P_0c05502a;
case 0x0c05502cu: goto P_0c05502c;
case 0x0c05502eu: goto P_0c05502e;
case 0x0c055030u: goto P_0c055030;
case 0x0c055032u: goto P_0c055032;
case 0x0c055034u: goto P_0c055034;
case 0x0c055036u: goto P_0c055036;
case 0x0c055038u: goto P_0c055038;
case 0x0c05503au: goto P_0c05503a;
case 0x0c05503cu: goto P_0c05503c;
case 0x0c05503eu: goto P_0c05503e;
case 0x0c055040u: goto P_0c055040;
case 0x0c055042u: goto P_0c055042;
case 0x0c055044u: goto P_0c055044;
case 0x0c055046u: goto P_0c055046;
case 0x0c055048u: goto P_0c055048;
case 0x0c05504au: goto P_0c05504a;
case 0x0c05504cu: goto P_0c05504c;
case 0x0c05504eu: goto P_0c05504e;
case 0x0c055050u: goto P_0c055050;
case 0x0c055052u: goto P_0c055052;
case 0x0c055054u: goto P_0c055054;
case 0x0c055056u: goto P_0c055056;
case 0x0c055058u: goto P_0c055058;
case 0x0c05505au: goto P_0c05505a;
case 0x0c05505cu: goto P_0c05505c;
case 0x0c05505eu: goto P_0c05505e;
case 0x0c055060u: goto P_0c055060;
case 0x0c055062u: goto P_0c055062;
case 0x0c055064u: goto P_0c055064;
case 0x0c055066u: goto P_0c055066;
case 0x0c055068u: goto P_0c055068;
case 0x0c05506au: goto P_0c05506a;
case 0x0c05506cu: goto P_0c05506c;
case 0x0c05506eu: goto P_0c05506e;
case 0x0c055074u: goto P_0c055074;
case 0x0c055076u: goto P_0c055076;
case 0x0c055078u: goto P_0c055078;
case 0x0c05507au: goto P_0c05507a;
case 0x0c05507cu: goto P_0c05507c;
case 0x0c05507eu: goto P_0c05507e;
case 0x0c055080u: goto P_0c055080;
case 0x0c055082u: goto P_0c055082;
case 0x0c055084u: goto P_0c055084;
case 0x0c055086u: goto P_0c055086;
case 0x0c055088u: goto P_0c055088;
case 0x0c05508au: goto P_0c05508a;
case 0x0c05508cu: goto P_0c05508c;
case 0x0c05508eu: goto P_0c05508e;
case 0x0c055090u: goto P_0c055090;
case 0x0c055092u: goto P_0c055092;
case 0x0c055094u: goto P_0c055094;
case 0x0c055096u: goto P_0c055096;
case 0x0c055098u: goto P_0c055098;
case 0x0c05509au: goto P_0c05509a;
case 0x0c05509cu: goto P_0c05509c;
case 0x0c05509eu: goto P_0c05509e;
case 0x0c0550a0u: goto P_0c0550a0;
case 0x0c0550a2u: goto P_0c0550a2;
case 0x0c0550a4u: goto P_0c0550a4;
case 0x0c0550a6u: goto P_0c0550a6;
case 0x0c0550a8u: goto P_0c0550a8;
case 0x0c0550aau: goto P_0c0550aa;
case 0x0c0550acu: goto P_0c0550ac;
case 0x0c0550aeu: goto P_0c0550ae;
case 0x0c0550b0u: goto P_0c0550b0;
case 0x0c0550b2u: goto P_0c0550b2;
case 0x0c0550b4u: goto P_0c0550b4;
case 0x0c0550b6u: goto P_0c0550b6;
case 0x0c0550b8u: goto P_0c0550b8;
case 0x0c0550bau: goto P_0c0550ba;
case 0x0c0550bcu: goto P_0c0550bc;
case 0x0c0550beu: goto P_0c0550be;
case 0x0c0550c0u: goto P_0c0550c0;
case 0x0c0550c2u: goto P_0c0550c2;
case 0x0c0550c4u: goto P_0c0550c4;
case 0x0c0550c6u: goto P_0c0550c6;
case 0x0c0550c8u: goto P_0c0550c8;
case 0x0c0550cau: goto P_0c0550ca;
case 0x0c0550ccu: goto P_0c0550cc;
case 0x0c0550ceu: goto P_0c0550ce;
case 0x0c0550d0u: goto P_0c0550d0;
case 0x0c0550d2u: goto P_0c0550d2;
case 0x0c0550d4u: goto P_0c0550d4;
case 0x0c0550d6u: goto P_0c0550d6;
case 0x0c0550d8u: goto P_0c0550d8;
case 0x0c0550dau: goto P_0c0550da;
case 0x0c0550dcu: goto P_0c0550dc;
case 0x0c0550deu: goto P_0c0550de;
case 0x0c0550e0u: goto P_0c0550e0;
case 0x0c0550e2u: goto P_0c0550e2;
case 0x0c0550e4u: goto P_0c0550e4;
case 0x0c0550e6u: goto P_0c0550e6;
case 0x0c0550e8u: goto P_0c0550e8;
case 0x0c0550eau: goto P_0c0550ea;
case 0x0c0550ecu: goto P_0c0550ec;
case 0x0c0550eeu: goto P_0c0550ee;
case 0x0c0550f0u: goto P_0c0550f0;
case 0x0c0550f2u: goto P_0c0550f2;
case 0x0c0550f4u: goto P_0c0550f4;
case 0x0c0550f6u: goto P_0c0550f6;
case 0x0c0550f8u: goto P_0c0550f8;
case 0x0c0550fau: goto P_0c0550fa;
case 0x0c0550fcu: goto P_0c0550fc;
case 0x0c0550feu: goto P_0c0550fe;
case 0x0c055100u: goto P_0c055100;
case 0x0c055102u: goto P_0c055102;
case 0x0c055104u: goto P_0c055104;
case 0x0c055106u: goto P_0c055106;
case 0x0c055108u: goto P_0c055108;
case 0x0c05510au: goto P_0c05510a;
case 0x0c05510cu: goto P_0c05510c;
case 0x0c05510eu: goto P_0c05510e;
case 0x0c055110u: goto P_0c055110;
case 0x0c055112u: goto P_0c055112;
case 0x0c05511cu: goto P_0c05511c;
case 0x0c05511eu: goto P_0c05511e;
case 0x0c055120u: goto P_0c055120;
case 0x0c055122u: goto P_0c055122;
case 0x0c055124u: goto P_0c055124;
case 0x0c055126u: goto P_0c055126;
case 0x0c055128u: goto P_0c055128;
case 0x0c05512au: goto P_0c05512a;
case 0x0c05512cu: goto P_0c05512c;
case 0x0c05512eu: goto P_0c05512e;
case 0x0c055130u: goto P_0c055130;
case 0x0c055132u: goto P_0c055132;
case 0x0c055134u: goto P_0c055134;
case 0x0c055136u: goto P_0c055136;
case 0x0c055138u: goto P_0c055138;
case 0x0c05513au: goto P_0c05513a;
case 0x0c05513cu: goto P_0c05513c;
case 0x0c05513eu: goto P_0c05513e;
case 0x0c055140u: goto P_0c055140;
case 0x0c055142u: goto P_0c055142;
case 0x0c055144u: goto P_0c055144;
case 0x0c055146u: goto P_0c055146;
case 0x0c055148u: goto P_0c055148;
case 0x0c05514au: goto P_0c05514a;
case 0x0c05514cu: goto P_0c05514c;
case 0x0c05514eu: goto P_0c05514e;
case 0x0c055150u: goto P_0c055150;
case 0x0c055152u: goto P_0c055152;
case 0x0c055154u: goto P_0c055154;
case 0x0c055156u: goto P_0c055156;
case 0x0c055158u: goto P_0c055158;
case 0x0c05515au: goto P_0c05515a;
case 0x0c05515cu: goto P_0c05515c;
case 0x0c05515eu: goto P_0c05515e;
case 0x0c055160u: goto P_0c055160;
case 0x0c055162u: goto P_0c055162;
case 0x0c055164u: goto P_0c055164;
case 0x0c055166u: goto P_0c055166;
case 0x0c055168u: goto P_0c055168;
case 0x0c05516au: goto P_0c05516a;
case 0x0c05516cu: goto P_0c05516c;
case 0x0c05516eu: goto P_0c05516e;
case 0x0c055170u: goto P_0c055170;
case 0x0c055172u: goto P_0c055172;
case 0x0c055174u: goto P_0c055174;
case 0x0c055176u: goto P_0c055176;
case 0x0c055178u: goto P_0c055178;
case 0x0c05517au: goto P_0c05517a;
case 0x0c05517cu: goto P_0c05517c;
case 0x0c05517eu: goto P_0c05517e;
case 0x0c055180u: goto P_0c055180;
case 0x0c055182u: goto P_0c055182;
case 0x0c055184u: goto P_0c055184;
case 0x0c055186u: goto P_0c055186;
case 0x0c055188u: goto P_0c055188;
case 0x0c05518au: goto P_0c05518a;
case 0x0c05518cu: goto P_0c05518c;
case 0x0c05518eu: goto P_0c05518e;
case 0x0c055190u: goto P_0c055190;
case 0x0c055192u: goto P_0c055192;
case 0x0c055194u: goto P_0c055194;
case 0x0c055196u: goto P_0c055196;
case 0x0c055198u: goto P_0c055198;
case 0x0c05519au: goto P_0c05519a;
case 0x0c05519cu: goto P_0c05519c;
case 0x0c05519eu: goto P_0c05519e;
case 0x0c0551a0u: goto P_0c0551a0;
case 0x0c0551a2u: goto P_0c0551a2;
case 0x0c0551a4u: goto P_0c0551a4;
case 0x0c0551a6u: goto P_0c0551a6;
case 0x0c0551a8u: goto P_0c0551a8;
case 0x0c0551aau: goto P_0c0551aa;
case 0x0c0551acu: goto P_0c0551ac;
case 0x0c0551aeu: goto P_0c0551ae;
case 0x0c0551b0u: goto P_0c0551b0;
case 0x0c0551b2u: goto P_0c0551b2;
case 0x0c0551b4u: goto P_0c0551b4;
case 0x0c0551b6u: goto P_0c0551b6;
case 0x0c0551b8u: goto P_0c0551b8;
case 0x0c0551bau: goto P_0c0551ba;
case 0x0c0551bcu: goto P_0c0551bc;
case 0x0c0551beu: goto P_0c0551be;
case 0x0c0551c0u: goto P_0c0551c0;
case 0x0c0551c2u: goto P_0c0551c2;
case 0x0c0551c4u: goto P_0c0551c4;
case 0x0c0551c6u: goto P_0c0551c6;
case 0x0c0551c8u: goto P_0c0551c8;
case 0x0c0551cau: goto P_0c0551ca;
case 0x0c0551ccu: goto P_0c0551cc;
case 0x0c0551ceu: goto P_0c0551ce;
case 0x0c0551d0u: goto P_0c0551d0;
case 0x0c0551d2u: goto P_0c0551d2;
case 0x0c0551d4u: goto P_0c0551d4;
case 0x0c0551d6u: goto P_0c0551d6;
case 0x0c0551d8u: goto P_0c0551d8;
case 0x0c0551dau: goto P_0c0551da;
case 0x0c0551dcu: goto P_0c0551dc;
case 0x0c0551deu: goto P_0c0551de;
case 0x0c0551e0u: goto P_0c0551e0;
case 0x0c0551e2u: goto P_0c0551e2;
case 0x0c0551e4u: goto P_0c0551e4;
case 0x0c0551e6u: goto P_0c0551e6;
case 0x0c0551e8u: goto P_0c0551e8;
case 0x0c0551eau: goto P_0c0551ea;
case 0x0c0551ecu: goto P_0c0551ec;
case 0x0c0551eeu: goto P_0c0551ee;
case 0x0c0551f0u: goto P_0c0551f0;
case 0x0c0551f2u: goto P_0c0551f2;
case 0x0c0551f4u: goto P_0c0551f4;
case 0x0c0551f6u: goto P_0c0551f6;
case 0x0c0551f8u: goto P_0c0551f8;
case 0x0c0551fau: goto P_0c0551fa;
case 0x0c0551fcu: goto P_0c0551fc;
case 0x0c0551feu: goto P_0c0551fe;
case 0x0c055200u: goto P_0c055200;
case 0x0c055202u: goto P_0c055202;
case 0x0c055204u: goto P_0c055204;
case 0x0c055206u: goto P_0c055206;
case 0x0c055208u: goto P_0c055208;
case 0x0c05520au: goto P_0c05520a;
case 0x0c05520cu: goto P_0c05520c;
case 0x0c05520eu: goto P_0c05520e;
case 0x0c055210u: goto P_0c055210;
case 0x0c055212u: goto P_0c055212;
case 0x0c055214u: goto P_0c055214;
case 0x0c055216u: goto P_0c055216;
case 0x0c055218u: goto P_0c055218;
case 0x0c05521au: goto P_0c05521a;
case 0x0c05521cu: goto P_0c05521c;
case 0x0c05521eu: goto P_0c05521e;
case 0x0c055220u: goto P_0c055220;
case 0x0c055222u: goto P_0c055222;
case 0x0c055224u: goto P_0c055224;
case 0x0c055226u: goto P_0c055226;
case 0x0c055228u: goto P_0c055228;
case 0x0c05522au: goto P_0c05522a;
case 0x0c05522cu: goto P_0c05522c;
case 0x0c05522eu: goto P_0c05522e;
case 0x0c055230u: goto P_0c055230;
case 0x0c055232u: goto P_0c055232;
case 0x0c055234u: goto P_0c055234;
case 0x0c055236u: goto P_0c055236;
case 0x0c055238u: goto P_0c055238;
case 0x0c05523au: goto P_0c05523a;
case 0x0c05523cu: goto P_0c05523c;
case 0x0c05523eu: goto P_0c05523e;
case 0x0c055240u: goto P_0c055240;
case 0x0c055242u: goto P_0c055242;
case 0x0c055244u: goto P_0c055244;
case 0x0c055246u: goto P_0c055246;
case 0x0c055248u: goto P_0c055248;
case 0x0c05524au: goto P_0c05524a;
case 0x0c05524cu: goto P_0c05524c;
case 0x0c05524eu: goto P_0c05524e;
case 0x0c055250u: goto P_0c055250;
case 0x0c055252u: goto P_0c055252;
case 0x0c055254u: goto P_0c055254;
case 0x0c055256u: goto P_0c055256;
case 0x0c055258u: goto P_0c055258;
case 0x0c05525au: goto P_0c05525a;
case 0x0c05525cu: goto P_0c05525c;
case 0x0c05525eu: goto P_0c05525e;
case 0x0c055260u: goto P_0c055260;
case 0x0c055262u: goto P_0c055262;
case 0x0c055264u: goto P_0c055264;
case 0x0c055266u: goto P_0c055266;
case 0x0c055268u: goto P_0c055268;
case 0x0c05526au: goto P_0c05526a;
case 0x0c05526cu: goto P_0c05526c;
case 0x0c05526eu: goto P_0c05526e;
case 0x0c055270u: goto P_0c055270;
case 0x0c055272u: goto P_0c055272;
case 0x0c055274u: goto P_0c055274;
case 0x0c055276u: goto P_0c055276;
case 0x0c055278u: goto P_0c055278;
case 0x0c05527au: goto P_0c05527a;
case 0x0c05527cu: goto P_0c05527c;
case 0x0c05527eu: goto P_0c05527e;
case 0x0c055280u: goto P_0c055280;
case 0x0c055282u: goto P_0c055282;
case 0x0c055284u: goto P_0c055284;
case 0x0c055286u: goto P_0c055286;
case 0x0c055288u: goto P_0c055288;
case 0x0c05528au: goto P_0c05528a;
case 0x0c05528cu: goto P_0c05528c;
case 0x0c05528eu: goto P_0c05528e;
case 0x0c055290u: goto P_0c055290;
case 0x0c055292u: goto P_0c055292;
case 0x0c055294u: goto P_0c055294;
case 0x0c055296u: goto P_0c055296;
case 0x0c055298u: goto P_0c055298;
case 0x0c05529au: goto P_0c05529a;
case 0x0c05529cu: goto P_0c05529c;
case 0x0c05529eu: goto P_0c05529e;
case 0x0c0552a0u: goto P_0c0552a0;
case 0x0c0552a2u: goto P_0c0552a2;
case 0x0c0552a4u: goto P_0c0552a4;
case 0x0c0552a6u: goto P_0c0552a6;
case 0x0c0552a8u: goto P_0c0552a8;
case 0x0c0552aau: goto P_0c0552aa;
case 0x0c0552acu: goto P_0c0552ac;
case 0x0c0552aeu: goto P_0c0552ae;
case 0x0c0552b0u: goto P_0c0552b0;
case 0x0c0552b2u: goto P_0c0552b2;
case 0x0c0552b4u: goto P_0c0552b4;
case 0x0c0552b6u: goto P_0c0552b6;
case 0x0c0552b8u: goto P_0c0552b8;
case 0x0c0552bau: goto P_0c0552ba;
case 0x0c0552bcu: goto P_0c0552bc;
case 0x0c0552beu: goto P_0c0552be;
case 0x0c0552c0u: goto P_0c0552c0;
case 0x0c0552c2u: goto P_0c0552c2;
case 0x0c0552c4u: goto P_0c0552c4;
case 0x0c0552c6u: goto P_0c0552c6;
case 0x0c0552c8u: goto P_0c0552c8;
case 0x0c0552cau: goto P_0c0552ca;
case 0x0c0552ccu: goto P_0c0552cc;
case 0x0c0552ceu: goto P_0c0552ce;
case 0x0c0552d0u: goto P_0c0552d0;
case 0x0c0552d2u: goto P_0c0552d2;
case 0x0c0552d4u: goto P_0c0552d4;
case 0x0c0552d6u: goto P_0c0552d6;
case 0x0c0552d8u: goto P_0c0552d8;
case 0x0c0552dau: goto P_0c0552da;
case 0x0c0552dcu: goto P_0c0552dc;
case 0x0c0552deu: goto P_0c0552de;
case 0x0c0552e0u: goto P_0c0552e0;
case 0x0c0552e2u: goto P_0c0552e2;
case 0x0c0552e4u: goto P_0c0552e4;
case 0x0c0552e6u: goto P_0c0552e6;
case 0x0c0552e8u: goto P_0c0552e8;
case 0x0c0552eau: goto P_0c0552ea;
case 0x0c0552ecu: goto P_0c0552ec;
case 0x0c0552eeu: goto P_0c0552ee;
case 0x0c0552f0u: goto P_0c0552f0;
case 0x0c0552f2u: goto P_0c0552f2;
case 0x0c0552f4u: goto P_0c0552f4;
case 0x0c0552f6u: goto P_0c0552f6;
case 0x0c0552f8u: goto P_0c0552f8;
case 0x0c0552fau: goto P_0c0552fa;
case 0x0c0552fcu: goto P_0c0552fc;
case 0x0c0552feu: goto P_0c0552fe;
case 0x0c055300u: goto P_0c055300;
case 0x0c055302u: goto P_0c055302;
case 0x0c055304u: goto P_0c055304;
case 0x0c055306u: goto P_0c055306;
case 0x0c055308u: goto P_0c055308;
case 0x0c05530au: goto P_0c05530a;
case 0x0c05530cu: goto P_0c05530c;
case 0x0c05530eu: goto P_0c05530e;
case 0x0c055310u: goto P_0c055310;
case 0x0c055312u: goto P_0c055312;
case 0x0c055314u: goto P_0c055314;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05500c: /* original aff7, guest PC 0x0c05500c */
if(!s->budget--) { s->failed_pc=0x0c05500cu; return 0; }
r[0]=0x00000000u;
return vf3_matrix_family(0x0c054ffeu,s,ram);
P_0c05500e: /* original e000, guest PC 0x0c05500e */
if(!s->budget--) { s->failed_pc=0x0c05500eu; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c055010u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055010u; return 0; } return 1;
P_0c055020: /* original 2f16, guest PC 0x0c055020 */
if(!s->budget--) { s->failed_pc=0x0c055020u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055022;
P_0c055022: /* original 2f26, guest PC 0x0c055022 */
if(!s->budget--) { s->failed_pc=0x0c055022u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055024;
P_0c055024: /* original 2f36, guest PC 0x0c055024 */
if(!s->budget--) { s->failed_pc=0x0c055024u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055026;
P_0c055026: /* original 2008, guest PC 0x0c055026 */
if(!s->budget--) { s->failed_pc=0x0c055026u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c055028;
P_0c055028: /* original 8d1f, guest PC 0x0c055028 */
if(!s->budget--) { s->failed_pc=0x0c055028u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05506a; }
goto P_0c05502c;
P_0c05502a: /* original 0009, guest PC 0x0c05502a */
if(!s->budget--) { s->failed_pc=0x0c05502au; return 0; }
goto P_0c05502c;
P_0c05502c: /* original e300, guest PC 0x0c05502c */
if(!s->budget--) { s->failed_pc=0x0c05502cu; return 0; }
r[3]=0x00000000u;
goto P_0c05502e;
P_0c05502e: /* original 4011, guest PC 0x0c05502e */
if(!s->budget--) { s->failed_pc=0x0c05502eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c055030;
P_0c055030: /* original 8901, guest PC 0x0c055030 */
if(!s->budget--) { s->failed_pc=0x0c055030u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055036; }
goto P_0c055032;
P_0c055032: /* original e301, guest PC 0x0c055032 */
if(!s->budget--) { s->failed_pc=0x0c055032u; return 0; }
r[3]=0x00000001u;
goto P_0c055034;
P_0c055034: /* original 600b, guest PC 0x0c055034 */
if(!s->budget--) { s->failed_pc=0x0c055034u; return 0; }
r[0]=0u-r[0];
goto P_0c055036;
P_0c055036: /* original d10e, guest PC 0x0c055036 */
if(!s->budget--) { s->failed_pc=0x0c055036u; return 0; }
r[1]=read(ram,0x0c055070u,4);
goto P_0c055038;
P_0c055038: /* original 4000, guest PC 0x0c055038 */
if(!s->budget--) { s->failed_pc=0x0c055038u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c05503a;
P_0c05503a: /* original 8ffd, guest PC 0x0c05503a */
if(!s->budget--) { s->failed_pc=0x0c05503au; return 0; }
cond=r[17]&1u;
r[1]+=0xffffffffu;
if(!cond) { goto P_0c055038; }
goto P_0c05503e;
P_0c05503c: /* original 71ff, guest PC 0x0c05503c */
if(!s->budget--) { s->failed_pc=0x0c05503cu; return 0; }
r[1]+=0xffffffffu;
goto P_0c05503e;
P_0c05503e: /* original 6203, guest PC 0x0c05503e */
if(!s->budget--) { s->failed_pc=0x0c05503eu; return 0; }
r[2]=r[0];
goto P_0c055040;
P_0c055040: /* original 4228, guest PC 0x0c055040 */
if(!s->budget--) { s->failed_pc=0x0c055040u; return 0; }
r[2]<<=16;
goto P_0c055042;
P_0c055042: /* original 4208, guest PC 0x0c055042 */
if(!s->budget--) { s->failed_pc=0x0c055042u; return 0; }
r[2]<<=2;
goto P_0c055044;
P_0c055044: /* original 4208, guest PC 0x0c055044 */
if(!s->budget--) { s->failed_pc=0x0c055044u; return 0; }
r[2]<<=2;
goto P_0c055046;
P_0c055046: /* original 4019, guest PC 0x0c055046 */
if(!s->budget--) { s->failed_pc=0x0c055046u; return 0; }
r[0]>>=8;
goto P_0c055048;
P_0c055048: /* original 4009, guest PC 0x0c055048 */
if(!s->budget--) { s->failed_pc=0x0c055048u; return 0; }
r[0]>>=2;
goto P_0c05504a;
P_0c05504a: /* original 4009, guest PC 0x0c05504a */
if(!s->budget--) { s->failed_pc=0x0c05504au; return 0; }
r[0]>>=2;
goto P_0c05504c;
P_0c05504c: /* original 4128, guest PC 0x0c05504c */
if(!s->budget--) { s->failed_pc=0x0c05504cu; return 0; }
r[1]<<=16;
goto P_0c05504e;
P_0c05504e: /* original 4108, guest PC 0x0c05504e */
if(!s->budget--) { s->failed_pc=0x0c05504eu; return 0; }
r[1]<<=2;
goto P_0c055050;
P_0c055050: /* original 4108, guest PC 0x0c055050 */
if(!s->budget--) { s->failed_pc=0x0c055050u; return 0; }
r[1]<<=2;
goto P_0c055052;
P_0c055052: /* original 201b, guest PC 0x0c055052 */
if(!s->budget--) { s->failed_pc=0x0c055052u; return 0; }
r[0]|=r[1];
goto P_0c055054;
P_0c055054: /* original 4000, guest PC 0x0c055054 */
if(!s->budget--) { s->failed_pc=0x0c055054u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c055056;
P_0c055056: /* original 4301, guest PC 0x0c055056 */
if(!s->budget--) { s->failed_pc=0x0c055056u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]>>=1;
goto P_0c055058;
P_0c055058: /* original 4025, guest PC 0x0c055058 */
if(!s->budget--) { s->failed_pc=0x0c055058u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c05505a;
P_0c05505a: /* original 51f3, guest PC 0x0c05505a */
if(!s->budget--) { s->failed_pc=0x0c05505au; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c05505c;
P_0c05505c: /* original 2122, guest PC 0x0c05505c */
if(!s->budget--) { s->failed_pc=0x0c05505cu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c05505e;
P_0c05505e: /* original 1101, guest PC 0x0c05505e */
if(!s->budget--) { s->failed_pc=0x0c05505eu; return 0; }
write(ram,r[1]+4,r[0],4);
goto P_0c055060;
P_0c055060: /* original 63f6, guest PC 0x0c055060 */
if(!s->budget--) { s->failed_pc=0x0c055060u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c055062;
P_0c055062: /* original 62f6, guest PC 0x0c055062 */
if(!s->budget--) { s->failed_pc=0x0c055062u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c055064;
P_0c055064: /* original 61f6, guest PC 0x0c055064 */
if(!s->budget--) { s->failed_pc=0x0c055064u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c055066;
P_0c055066: /* original 000b, guest PC 0x0c055066 */
if(!s->budget--) { s->failed_pc=0x0c055066u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c055068: /* original 7f04, guest PC 0x0c055068 */
if(!s->budget--) { s->failed_pc=0x0c055068u; return 0; }
r[15]+=0x00000004u;
goto P_0c05506a;
P_0c05506a: /* original e200, guest PC 0x0c05506a */
if(!s->budget--) { s->failed_pc=0x0c05506au; return 0; }
r[2]=0x00000000u;
goto P_0c05506c;
P_0c05506c: /* original aff5, guest PC 0x0c05506c */
if(!s->budget--) { s->failed_pc=0x0c05506cu; return 0; }
r[0]=0x00000000u;
goto P_0c05505a;
P_0c05506e: /* original e000, guest PC 0x0c05506e */
if(!s->budget--) { s->failed_pc=0x0c05506eu; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c055070u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055070u; return 0; } return 1;
P_0c055074: /* original 2f46, guest PC 0x0c055074 */
if(!s->budget--) { s->failed_pc=0x0c055074u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055076;
P_0c055076: /* original 2f56, guest PC 0x0c055076 */
if(!s->budget--) { s->failed_pc=0x0c055076u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055078;
P_0c055078: /* original 2f66, guest PC 0x0c055078 */
if(!s->budget--) { s->failed_pc=0x0c055078u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05507a;
P_0c05507a: /* original 2f76, guest PC 0x0c05507a */
if(!s->budget--) { s->failed_pc=0x0c05507au; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05507c;
P_0c05507c: /* original 55f6, guest PC 0x0c05507c */
if(!s->budget--) { s->failed_pc=0x0c05507cu; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c05507e;
P_0c05507e: /* original 54f7, guest PC 0x0c05507e */
if(!s->budget--) { s->failed_pc=0x0c05507eu; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c055080;
P_0c055080: /* original 57f4, guest PC 0x0c055080 */
if(!s->budget--) { s->failed_pc=0x0c055080u; return 0; }
r[7]=read(ram,r[15]+16,4);
goto P_0c055082;
P_0c055082: /* original 56f5, guest PC 0x0c055082 */
if(!s->budget--) { s->failed_pc=0x0c055082u; return 0; }
r[6]=read(ram,r[15]+20,4);
goto P_0c055084;
P_0c055084: /* original 2f86, guest PC 0x0c055084 */
if(!s->budget--) { s->failed_pc=0x0c055084u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055086;
P_0c055086: /* original 2f96, guest PC 0x0c055086 */
if(!s->budget--) { s->failed_pc=0x0c055086u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c055088;
P_0c055088: /* original 2fa6, guest PC 0x0c055088 */
if(!s->budget--) { s->failed_pc=0x0c055088u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05508a;
P_0c05508a: /* original 2fb6, guest PC 0x0c05508a */
if(!s->budget--) { s->failed_pc=0x0c05508au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05508c;
P_0c05508c: /* original d021, guest PC 0x0c05508c */
if(!s->budget--) { s->failed_pc=0x0c05508cu; return 0; }
r[0]=read(ram,0x0c055114u,4);
goto P_0c05508e;
P_0c05508e: /* original 6a43, guest PC 0x0c05508e */
if(!s->budget--) { s->failed_pc=0x0c05508eu; return 0; }
r[10]=r[4];
goto P_0c055090;
P_0c055090: /* original 6b63, guest PC 0x0c055090 */
if(!s->budget--) { s->failed_pc=0x0c055090u; return 0; }
r[11]=r[6];
goto P_0c055092;
P_0c055092: /* original 6843, guest PC 0x0c055092 */
if(!s->budget--) { s->failed_pc=0x0c055092u; return 0; }
r[8]=r[4];
goto P_0c055094;
P_0c055094: /* original 2809, guest PC 0x0c055094 */
if(!s->budget--) { s->failed_pc=0x0c055094u; return 0; }
r[8]&=r[0];
goto P_0c055096;
P_0c055096: /* original 6963, guest PC 0x0c055096 */
if(!s->budget--) { s->failed_pc=0x0c055096u; return 0; }
r[9]=r[6];
goto P_0c055098;
P_0c055098: /* original 2909, guest PC 0x0c055098 */
if(!s->budget--) { s->failed_pc=0x0c055098u; return 0; }
r[9]&=r[0];
goto P_0c05509a;
P_0c05509a: /* original d01f, guest PC 0x0c05509a */
if(!s->budget--) { s->failed_pc=0x0c05509au; return 0; }
r[0]=read(ram,0x0c055118u,4);
goto P_0c05509c;
P_0c05509c: /* original 2409, guest PC 0x0c05509c */
if(!s->budget--) { s->failed_pc=0x0c05509cu; return 0; }
r[4]&=r[0];
goto P_0c05509e;
P_0c05509e: /* original 2609, guest PC 0x0c05509e */
if(!s->budget--) { s->failed_pc=0x0c05509eu; return 0; }
r[6]&=r[0];
goto P_0c0550a0;
P_0c0550a0: /* original d01c, guest PC 0x0c0550a0 */
if(!s->budget--) { s->failed_pc=0x0c0550a0u; return 0; }
r[0]=read(ram,0x0c055114u,4);
goto P_0c0550a2;
P_0c0550a2: /* original 3800, guest PC 0x0c0550a2 */
if(!s->budget--) { s->failed_pc=0x0c0550a2u; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[0])!=0);
goto P_0c0550a4;
P_0c0550a4: /* original 891c, guest PC 0x0c0550a4 */
if(!s->budget--) { s->failed_pc=0x0c0550a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0550e0; }
goto P_0c0550a6;
P_0c0550a6: /* original 3900, guest PC 0x0c0550a6 */
if(!s->budget--) { s->failed_pc=0x0c0550a6u; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[0])!=0);
goto P_0c0550a8;
P_0c0550a8: /* original 8920, guest PC 0x0c0550a8 */
if(!s->budget--) { s->failed_pc=0x0c0550a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0550ec; }
goto P_0c0550aa;
P_0c0550aa: /* original 2888, guest PC 0x0c0550aa */
if(!s->budget--) { s->failed_pc=0x0c0550aau; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c0550ac;
P_0c0550ac: /* original 8924, guest PC 0x0c0550ac */
if(!s->budget--) { s->failed_pc=0x0c0550acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0550f8; }
goto P_0c0550ae;
P_0c0550ae: /* original 2ba7, guest PC 0x0c0550ae */
if(!s->budget--) { s->failed_pc=0x0c0550aeu; return 0; }
r[17]=(r[17]&~0x301u)|((r[11]>>31)<<8)|((r[10]>>31)<<9)|(((r[11]^r[10])>>31)&1u);
goto P_0c0550b0;
P_0c0550b0: /* original 890a, guest PC 0x0c0550b0 */
if(!s->budget--) { s->failed_pc=0x0c0550b0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0550c8; }
goto P_0c0550b2;
P_0c0550b2: /* original 4a11, guest PC 0x0c0550b2 */
if(!s->budget--) { s->failed_pc=0x0c0550b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=0)!=0);
goto P_0c0550b4;
P_0c0550b4: /* original 8b04, guest PC 0x0c0550b4 */
if(!s->budget--) { s->failed_pc=0x0c0550b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0550c0; }
goto P_0c0550b6;
P_0c0550b6: /* original 0008, guest PC 0x0c0550b6 */
if(!s->budget--) { s->failed_pc=0x0c0550b6u; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c0550b8;
P_0c0550b8: /* original 357a, guest PC 0x0c0550b8 */
if(!s->budget--) { s->failed_pc=0x0c0550b8u; return 0; }
wide=(uint64_t)r[5]-r[7]-(r[17]&1u); r[5]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0550ba;
P_0c0550ba: /* original 3aba, guest PC 0x0c0550ba */
if(!s->budget--) { s->failed_pc=0x0c0550bau; return 0; }
wide=(uint64_t)r[10]-r[11]-(r[17]&1u); r[10]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0550bc;
P_0c0550bc: /* original a006, guest PC 0x0c0550bc */
if(!s->budget--) { s->failed_pc=0x0c0550bcu; return 0; }
r[0]=r[17]&1u;
goto P_0c0550cc;
P_0c0550be: /* original 0029, guest PC 0x0c0550be */
if(!s->budget--) { s->failed_pc=0x0c0550beu; return 0; }
r[0]=r[17]&1u;
goto P_0c0550c0;
P_0c0550c0: /* original 375a, guest PC 0x0c0550c0 */
if(!s->budget--) { s->failed_pc=0x0c0550c0u; return 0; }
wide=(uint64_t)r[7]-r[5]-(r[17]&1u); r[7]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0550c2;
P_0c0550c2: /* original 3baa, guest PC 0x0c0550c2 */
if(!s->budget--) { s->failed_pc=0x0c0550c2u; return 0; }
wide=(uint64_t)r[11]-r[10]-(r[17]&1u); r[11]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0550c4;
P_0c0550c4: /* original a002, guest PC 0x0c0550c4 */
if(!s->budget--) { s->failed_pc=0x0c0550c4u; return 0; }
r[0]=r[17]&1u;
goto P_0c0550cc;
P_0c0550c6: /* original 0029, guest PC 0x0c0550c6 */
if(!s->budget--) { s->failed_pc=0x0c0550c6u; return 0; }
r[0]=r[17]&1u;
goto P_0c0550c8;
P_0c0550c8: /* original 4b11, guest PC 0x0c0550c8 */
if(!s->budget--) { s->failed_pc=0x0c0550c8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=0)!=0);
goto P_0c0550ca;
P_0c0550ca: /* original 0029, guest PC 0x0c0550ca */
if(!s->budget--) { s->failed_pc=0x0c0550cau; return 0; }
r[0]=r[17]&1u;
goto P_0c0550cc;
P_0c0550cc: /* original 6bf6, guest PC 0x0c0550cc */
if(!s->budget--) { s->failed_pc=0x0c0550ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0550ce;
P_0c0550ce: /* original 6af6, guest PC 0x0c0550ce */
if(!s->budget--) { s->failed_pc=0x0c0550ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0550d0;
P_0c0550d0: /* original 69f6, guest PC 0x0c0550d0 */
if(!s->budget--) { s->failed_pc=0x0c0550d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0550d2;
P_0c0550d2: /* original 68f6, guest PC 0x0c0550d2 */
if(!s->budget--) { s->failed_pc=0x0c0550d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0550d4;
P_0c0550d4: /* original 67f6, guest PC 0x0c0550d4 */
if(!s->budget--) { s->failed_pc=0x0c0550d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c0550d6;
P_0c0550d6: /* original 66f6, guest PC 0x0c0550d6 */
if(!s->budget--) { s->failed_pc=0x0c0550d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c0550d8;
P_0c0550d8: /* original 65f6, guest PC 0x0c0550d8 */
if(!s->budget--) { s->failed_pc=0x0c0550d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c0550da;
P_0c0550da: /* original 64f6, guest PC 0x0c0550da */
if(!s->budget--) { s->failed_pc=0x0c0550dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c0550dc;
P_0c0550dc: /* original 000b, guest PC 0x0c0550dc */
if(!s->budget--) { s->failed_pc=0x0c0550dcu; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c0550de: /* original 7f10, guest PC 0x0c0550de */
if(!s->budget--) { s->failed_pc=0x0c0550deu; return 0; }
r[15]+=0x00000010u;
goto P_0c0550e0;
P_0c0550e0: /* original 2448, guest PC 0x0c0550e0 */
if(!s->budget--) { s->failed_pc=0x0c0550e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0550e2;
P_0c0550e2: /* original 8b15, guest PC 0x0c0550e2 */
if(!s->budget--) { s->failed_pc=0x0c0550e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055110; }
goto P_0c0550e4;
P_0c0550e4: /* original 2558, guest PC 0x0c0550e4 */
if(!s->budget--) { s->failed_pc=0x0c0550e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0550e6;
P_0c0550e6: /* original 8b13, guest PC 0x0c0550e6 */
if(!s->budget--) { s->failed_pc=0x0c0550e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055110; }
goto P_0c0550e8;
P_0c0550e8: /* original afdd, guest PC 0x0c0550e8 */
if(!s->budget--) { s->failed_pc=0x0c0550e8u; return 0; }
goto P_0c0550a6;
P_0c0550ea: /* original 0009, guest PC 0x0c0550ea */
if(!s->budget--) { s->failed_pc=0x0c0550eau; return 0; }
goto P_0c0550ec;
P_0c0550ec: /* original 2668, guest PC 0x0c0550ec */
if(!s->budget--) { s->failed_pc=0x0c0550ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0550ee;
P_0c0550ee: /* original 8b0f, guest PC 0x0c0550ee */
if(!s->budget--) { s->failed_pc=0x0c0550eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055110; }
goto P_0c0550f0;
P_0c0550f0: /* original 2778, guest PC 0x0c0550f0 */
if(!s->budget--) { s->failed_pc=0x0c0550f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0550f2;
P_0c0550f2: /* original 8b0d, guest PC 0x0c0550f2 */
if(!s->budget--) { s->failed_pc=0x0c0550f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055110; }
goto P_0c0550f4;
P_0c0550f4: /* original afd9, guest PC 0x0c0550f4 */
if(!s->budget--) { s->failed_pc=0x0c0550f4u; return 0; }
goto P_0c0550aa;
P_0c0550f6: /* original 0009, guest PC 0x0c0550f6 */
if(!s->budget--) { s->failed_pc=0x0c0550f6u; return 0; }
goto P_0c0550f8;
P_0c0550f8: /* original 2998, guest PC 0x0c0550f8 */
if(!s->budget--) { s->failed_pc=0x0c0550f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0550fa;
P_0c0550fa: /* original 8bd8, guest PC 0x0c0550fa */
if(!s->budget--) { s->failed_pc=0x0c0550fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0550ae; }
goto P_0c0550fc;
P_0c0550fc: /* original 2448, guest PC 0x0c0550fc */
if(!s->budget--) { s->failed_pc=0x0c0550fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0550fe;
P_0c0550fe: /* original 8bd6, guest PC 0x0c0550fe */
if(!s->budget--) { s->failed_pc=0x0c0550feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0550ae; }
goto P_0c055100;
P_0c055100: /* original 2558, guest PC 0x0c055100 */
if(!s->budget--) { s->failed_pc=0x0c055100u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c055102;
P_0c055102: /* original 8bd4, guest PC 0x0c055102 */
if(!s->budget--) { s->failed_pc=0x0c055102u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0550ae; }
goto P_0c055104;
P_0c055104: /* original 2668, guest PC 0x0c055104 */
if(!s->budget--) { s->failed_pc=0x0c055104u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c055106;
P_0c055106: /* original 8bd2, guest PC 0x0c055106 */
if(!s->budget--) { s->failed_pc=0x0c055106u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0550ae; }
goto P_0c055108;
P_0c055108: /* original 2778, guest PC 0x0c055108 */
if(!s->budget--) { s->failed_pc=0x0c055108u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05510a;
P_0c05510a: /* original 8bd0, guest PC 0x0c05510a */
if(!s->budget--) { s->failed_pc=0x0c05510au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0550ae; }
goto P_0c05510c;
P_0c05510c: /* original afde, guest PC 0x0c05510c */
if(!s->budget--) { s->failed_pc=0x0c05510cu; return 0; }
r[0]=0x00000000u;
goto P_0c0550cc;
P_0c05510e: /* original e000, guest PC 0x0c05510e */
if(!s->budget--) { s->failed_pc=0x0c05510eu; return 0; }
r[0]=0x00000000u;
goto P_0c055110;
P_0c055110: /* original afdc, guest PC 0x0c055110 */
if(!s->budget--) { s->failed_pc=0x0c055110u; return 0; }
r[0]=0x00000000u;
goto P_0c0550cc;
P_0c055112: /* original e000, guest PC 0x0c055112 */
if(!s->budget--) { s->failed_pc=0x0c055112u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c055114u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055114u; return 0; } return 1;
P_0c05511c: /* original 2448, guest PC 0x0c05511c */
if(!s->budget--) { s->failed_pc=0x0c05511cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05511e;
P_0c05511e: /* original 8b4a, guest PC 0x0c05511e */
if(!s->budget--) { s->failed_pc=0x0c05511eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551b6; }
goto P_0c055120;
P_0c055120: /* original 2558, guest PC 0x0c055120 */
if(!s->budget--) { s->failed_pc=0x0c055120u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c055122;
P_0c055122: /* original 8b48, guest PC 0x0c055122 */
if(!s->budget--) { s->failed_pc=0x0c055122u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551b6; }
goto P_0c055124;
P_0c055124: /* original 3930, guest PC 0x0c055124 */
if(!s->budget--) { s->failed_pc=0x0c055124u; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[3])!=0);
goto P_0c055126;
P_0c055126: /* original 8907, guest PC 0x0c055126 */
if(!s->budget--) { s->failed_pc=0x0c055126u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055138; }
goto P_0c055128;
P_0c055128: /* original 2998, guest PC 0x0c055128 */
if(!s->budget--) { s->failed_pc=0x0c055128u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c05512a;
P_0c05512a: /* original 8b40, guest PC 0x0c05512a */
if(!s->budget--) { s->failed_pc=0x0c05512au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551ae; }
goto P_0c05512c;
P_0c05512c: /* original 2668, guest PC 0x0c05512c */
if(!s->budget--) { s->failed_pc=0x0c05512cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05512e;
P_0c05512e: /* original 8b3e, guest PC 0x0c05512e */
if(!s->budget--) { s->failed_pc=0x0c05512eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551ae; }
goto P_0c055130;
P_0c055130: /* original 2778, guest PC 0x0c055130 */
if(!s->budget--) { s->failed_pc=0x0c055130u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c055132;
P_0c055132: /* original 8b3c, guest PC 0x0c055132 */
if(!s->budget--) { s->failed_pc=0x0c055132u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551ae; }
goto P_0c055134;
P_0c055134: /* original a03f, guest PC 0x0c055134 */
if(!s->budget--) { s->failed_pc=0x0c055134u; return 0; }
goto P_0c0551b6;
P_0c055136: /* original 0009, guest PC 0x0c055136 */
if(!s->budget--) { s->failed_pc=0x0c055136u; return 0; }
goto P_0c055138;
P_0c055138: /* original 2668, guest PC 0x0c055138 */
if(!s->budget--) { s->failed_pc=0x0c055138u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05513a;
P_0c05513a: /* original 8b3c, guest PC 0x0c05513a */
if(!s->budget--) { s->failed_pc=0x0c05513au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551b6; }
goto P_0c05513c;
P_0c05513c: /* original 2778, guest PC 0x0c05513c */
if(!s->budget--) { s->failed_pc=0x0c05513cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05513e;
P_0c05513e: /* original 8b3a, guest PC 0x0c05513e */
if(!s->budget--) { s->failed_pc=0x0c05513eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551b6; }
goto P_0c055140;
P_0c055140: /* original a035, guest PC 0x0c055140 */
if(!s->budget--) { s->failed_pc=0x0c055140u; return 0; }
goto P_0c0551ae;
P_0c055142: /* original 0009, guest PC 0x0c055142 */
if(!s->budget--) { s->failed_pc=0x0c055142u; return 0; }
goto P_0c055144;
P_0c055144: /* original 2668, guest PC 0x0c055144 */
if(!s->budget--) { s->failed_pc=0x0c055144u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c055146;
P_0c055146: /* original 8b36, guest PC 0x0c055146 */
if(!s->budget--) { s->failed_pc=0x0c055146u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551b6; }
goto P_0c055148;
P_0c055148: /* original 2778, guest PC 0x0c055148 */
if(!s->budget--) { s->failed_pc=0x0c055148u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05514a;
P_0c05514a: /* original 8b34, guest PC 0x0c05514a */
if(!s->budget--) { s->failed_pc=0x0c05514au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551b6; }
goto P_0c05514c;
P_0c05514c: /* original 2888, guest PC 0x0c05514c */
if(!s->budget--) { s->failed_pc=0x0c05514cu; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c05514e;
P_0c05514e: /* original 8b2e, guest PC 0x0c05514e */
if(!s->budget--) { s->failed_pc=0x0c05514eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551ae; }
goto P_0c055150;
P_0c055150: /* original 2448, guest PC 0x0c055150 */
if(!s->budget--) { s->failed_pc=0x0c055150u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c055152;
P_0c055152: /* original 8b2c, guest PC 0x0c055152 */
if(!s->budget--) { s->failed_pc=0x0c055152u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551ae; }
goto P_0c055154;
P_0c055154: /* original 2558, guest PC 0x0c055154 */
if(!s->budget--) { s->failed_pc=0x0c055154u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c055156;
P_0c055156: /* original 8b2a, guest PC 0x0c055156 */
if(!s->budget--) { s->failed_pc=0x0c055156u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0551ae; }
goto P_0c055158;
P_0c055158: /* original a02d, guest PC 0x0c055158 */
if(!s->budget--) { s->failed_pc=0x0c055158u; return 0; }
goto P_0c0551b6;
P_0c05515a: /* original 0009, guest PC 0x0c05515a */
if(!s->budget--) { s->failed_pc=0x0c05515au; return 0; }
goto P_0c05515c;
P_0c05515c: /* original 2448, guest PC 0x0c05515c */
if(!s->budget--) { s->failed_pc=0x0c05515cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05515e;
P_0c05515e: /* original 8b03, guest PC 0x0c05515e */
if(!s->budget--) { s->failed_pc=0x0c05515eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055168; }
goto P_0c055160;
P_0c055160: /* original 2558, guest PC 0x0c055160 */
if(!s->budget--) { s->failed_pc=0x0c055160u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c055162;
P_0c055162: /* original 8b01, guest PC 0x0c055162 */
if(!s->budget--) { s->failed_pc=0x0c055162u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055168; }
goto P_0c055164;
P_0c055164: /* original a01e, guest PC 0x0c055164 */
if(!s->budget--) { s->failed_pc=0x0c055164u; return 0; }
goto P_0c0551a4;
P_0c055166: /* original 0009, guest PC 0x0c055166 */
if(!s->budget--) { s->failed_pc=0x0c055166u; return 0; }
goto P_0c055168;
P_0c055168: /* original d06d, guest PC 0x0c055168 */
if(!s->budget--) { s->failed_pc=0x0c055168u; return 0; }
r[0]=read(ram,0x0c055320u,4);
goto P_0c05516a;
P_0c05516a: /* original 4500, guest PC 0x0c05516a */
if(!s->budget--) { s->failed_pc=0x0c05516au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c05516c;
P_0c05516c: /* original 4424, guest PC 0x0c05516c */
if(!s->budget--) { s->failed_pc=0x0c05516cu; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c05516e;
P_0c05516e: /* original 3403, guest PC 0x0c05516e */
if(!s->budget--) { s->failed_pc=0x0c05516eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c055170;
P_0c055170: /* original 8904, guest PC 0x0c055170 */
if(!s->budget--) { s->failed_pc=0x0c055170u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05517c; }
goto P_0c055172;
P_0c055172: /* original 4500, guest PC 0x0c055172 */
if(!s->budget--) { s->failed_pc=0x0c055172u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c055174;
P_0c055174: /* original 4424, guest PC 0x0c055174 */
if(!s->budget--) { s->failed_pc=0x0c055174u; return 0; }
tmp=r[4]>>31; r[4]=(r[4]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055176;
P_0c055176: /* original 3403, guest PC 0x0c055176 */
if(!s->budget--) { s->failed_pc=0x0c055176u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c055178;
P_0c055178: /* original 8ffb, guest PC 0x0c055178 */
if(!s->budget--) { s->failed_pc=0x0c055178u; return 0; }
cond=r[17]&1u;
r[8]+=0xffffffffu;
if(!cond) { goto P_0c055172; }
goto P_0c05517c;
P_0c05517a: /* original 78ff, guest PC 0x0c05517a */
if(!s->budget--) { s->failed_pc=0x0c05517au; return 0; }
r[8]+=0xffffffffu;
goto P_0c05517c;
P_0c05517c: /* original a04b, guest PC 0x0c05517c */
if(!s->budget--) { s->failed_pc=0x0c05517cu; return 0; }
goto P_0c055216;
P_0c05517e: /* original 0009, guest PC 0x0c05517e */
if(!s->budget--) { s->failed_pc=0x0c05517eu; return 0; }
goto P_0c055180;
P_0c055180: /* original 2668, guest PC 0x0c055180 */
if(!s->budget--) { s->failed_pc=0x0c055180u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c055182;
P_0c055182: /* original 8b03, guest PC 0x0c055182 */
if(!s->budget--) { s->failed_pc=0x0c055182u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05518c; }
goto P_0c055184;
P_0c055184: /* original 2778, guest PC 0x0c055184 */
if(!s->budget--) { s->failed_pc=0x0c055184u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c055186;
P_0c055186: /* original 8b01, guest PC 0x0c055186 */
if(!s->budget--) { s->failed_pc=0x0c055186u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05518c; }
goto P_0c055188;
P_0c055188: /* original a00c, guest PC 0x0c055188 */
if(!s->budget--) { s->failed_pc=0x0c055188u; return 0; }
goto P_0c0551a4;
P_0c05518a: /* original 0009, guest PC 0x0c05518a */
if(!s->budget--) { s->failed_pc=0x0c05518au; return 0; }
goto P_0c05518c;
P_0c05518c: /* original d064, guest PC 0x0c05518c */
if(!s->budget--) { s->failed_pc=0x0c05518cu; return 0; }
r[0]=read(ram,0x0c055320u,4);
goto P_0c05518e;
P_0c05518e: /* original 4700, guest PC 0x0c05518e */
if(!s->budget--) { s->failed_pc=0x0c05518eu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c055190;
P_0c055190: /* original 4624, guest PC 0x0c055190 */
if(!s->budget--) { s->failed_pc=0x0c055190u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055192;
P_0c055192: /* original 3603, guest PC 0x0c055192 */
if(!s->budget--) { s->failed_pc=0x0c055192u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[0])!=0);
goto P_0c055194;
P_0c055194: /* original 8904, guest PC 0x0c055194 */
if(!s->budget--) { s->failed_pc=0x0c055194u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0551a0; }
goto P_0c055196;
P_0c055196: /* original 4700, guest PC 0x0c055196 */
if(!s->budget--) { s->failed_pc=0x0c055196u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c055198;
P_0c055198: /* original 4624, guest PC 0x0c055198 */
if(!s->budget--) { s->failed_pc=0x0c055198u; return 0; }
tmp=r[6]>>31; r[6]=(r[6]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c05519a;
P_0c05519a: /* original 3603, guest PC 0x0c05519a */
if(!s->budget--) { s->failed_pc=0x0c05519au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[0])!=0);
goto P_0c05519c;
P_0c05519c: /* original 8ffb, guest PC 0x0c05519c */
if(!s->budget--) { s->failed_pc=0x0c05519cu; return 0; }
cond=r[17]&1u;
r[9]+=0xffffffffu;
if(!cond) { goto P_0c055196; }
goto P_0c0551a0;
P_0c05519e: /* original 79ff, guest PC 0x0c05519e */
if(!s->budget--) { s->failed_pc=0x0c05519eu; return 0; }
r[9]+=0xffffffffu;
goto P_0c0551a0;
P_0c0551a0: /* original a03b, guest PC 0x0c0551a0 */
if(!s->budget--) { s->failed_pc=0x0c0551a0u; return 0; }
goto P_0c05521a;
P_0c0551a2: /* original 0009, guest PC 0x0c0551a2 */
if(!s->budget--) { s->failed_pc=0x0c0551a2u; return 0; }
goto P_0c0551a4;
P_0c0551a4: /* original 4a00, guest PC 0x0c0551a4 */
if(!s->budget--) { s->failed_pc=0x0c0551a4u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c0551a6;
P_0c0551a6: /* original 0129, guest PC 0x0c0551a6 */
if(!s->budget--) { s->failed_pc=0x0c0551a6u; return 0; }
r[1]=r[17]&1u;
goto P_0c0551a8;
P_0c0551a8: /* original e000, guest PC 0x0c0551a8 */
if(!s->budget--) { s->failed_pc=0x0c0551a8u; return 0; }
r[0]=0x00000000u;
goto P_0c0551aa;
P_0c0551aa: /* original a09e, guest PC 0x0c0551aa */
if(!s->budget--) { s->failed_pc=0x0c0551aau; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1u)!=0);
r[1]=(r[1]>>1)|(r[1]<<31);
goto P_0c0552ea;
P_0c0551ac: /* original 4105, guest PC 0x0c0551ac */
if(!s->budget--) { s->failed_pc=0x0c0551acu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1u)!=0);
r[1]=(r[1]>>1)|(r[1]<<31);
goto P_0c0551ae;
P_0c0551ae: /* original d85a, guest PC 0x0c0551ae */
if(!s->budget--) { s->failed_pc=0x0c0551aeu; return 0; }
r[8]=read(ram,0x0c055318u,4);
goto P_0c0551b0;
P_0c0551b0: /* original e100, guest PC 0x0c0551b0 */
if(!s->budget--) { s->failed_pc=0x0c0551b0u; return 0; }
r[1]=0x00000000u;
goto P_0c0551b2;
P_0c0551b2: /* original a08b, guest PC 0x0c0551b2 */
if(!s->budget--) { s->failed_pc=0x0c0551b2u; return 0; }
r[0]=0x00000000u;
goto P_0c0552cc;
P_0c0551b4: /* original e000, guest PC 0x0c0551b4 */
if(!s->budget--) { s->failed_pc=0x0c0551b4u; return 0; }
r[0]=0x00000000u;
goto P_0c0551b6;
P_0c0551b6: /* original ea00, guest PC 0x0c0551b6 */
if(!s->budget--) { s->failed_pc=0x0c0551b6u; return 0; }
r[10]=0x00000000u;
goto P_0c0551b8;
P_0c0551b8: /* original d857, guest PC 0x0c0551b8 */
if(!s->budget--) { s->failed_pc=0x0c0551b8u; return 0; }
r[8]=read(ram,0x0c055318u,4);
goto P_0c0551ba;
P_0c0551ba: /* original e100, guest PC 0x0c0551ba */
if(!s->budget--) { s->failed_pc=0x0c0551bau; return 0; }
r[1]=0x00000000u;
goto P_0c0551bc;
P_0c0551bc: /* original a086, guest PC 0x0c0551bc */
if(!s->budget--) { s->failed_pc=0x0c0551bcu; return 0; }
r[0]=0x00000008u;
goto P_0c0552cc;
P_0c0551be: /* original e008, guest PC 0x0c0551be */
if(!s->budget--) { s->failed_pc=0x0c0551beu; return 0; }
r[0]=0x00000008u;
goto P_0c0551c0;
P_0c0551c0: /* original 2f06, guest PC 0x0c0551c0 */
if(!s->budget--) { s->failed_pc=0x0c0551c0u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551c2;
P_0c0551c2: /* original 2f16, guest PC 0x0c0551c2 */
if(!s->budget--) { s->failed_pc=0x0c0551c2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551c4;
P_0c0551c4: /* original 2f46, guest PC 0x0c0551c4 */
if(!s->budget--) { s->failed_pc=0x0c0551c4u; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551c6;
P_0c0551c6: /* original 2f56, guest PC 0x0c0551c6 */
if(!s->budget--) { s->failed_pc=0x0c0551c6u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551c8;
P_0c0551c8: /* original 2f66, guest PC 0x0c0551c8 */
if(!s->budget--) { s->failed_pc=0x0c0551c8u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551ca;
P_0c0551ca: /* original 2f76, guest PC 0x0c0551ca */
if(!s->budget--) { s->failed_pc=0x0c0551cau; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551cc;
P_0c0551cc: /* original 55f7, guest PC 0x0c0551cc */
if(!s->budget--) { s->failed_pc=0x0c0551ccu; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c0551ce;
P_0c0551ce: /* original 54f8, guest PC 0x0c0551ce */
if(!s->budget--) { s->failed_pc=0x0c0551ceu; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c0551d0;
P_0c0551d0: /* original 57f9, guest PC 0x0c0551d0 */
if(!s->budget--) { s->failed_pc=0x0c0551d0u; return 0; }
r[7]=read(ram,r[15]+36,4);
goto P_0c0551d2;
P_0c0551d2: /* original 56fa, guest PC 0x0c0551d2 */
if(!s->budget--) { s->failed_pc=0x0c0551d2u; return 0; }
r[6]=read(ram,r[15]+40,4);
goto P_0c0551d4;
P_0c0551d4: /* original 2f26, guest PC 0x0c0551d4 */
if(!s->budget--) { s->failed_pc=0x0c0551d4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551d6;
P_0c0551d6: /* original 2f36, guest PC 0x0c0551d6 */
if(!s->budget--) { s->failed_pc=0x0c0551d6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551d8;
P_0c0551d8: /* original 2f86, guest PC 0x0c0551d8 */
if(!s->budget--) { s->failed_pc=0x0c0551d8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551da;
P_0c0551da: /* original 2f96, guest PC 0x0c0551da */
if(!s->budget--) { s->failed_pc=0x0c0551dau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551dc;
P_0c0551dc: /* original 2fa6, guest PC 0x0c0551dc */
if(!s->budget--) { s->failed_pc=0x0c0551dcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551de;
P_0c0551de: /* original 2fb6, guest PC 0x0c0551de */
if(!s->budget--) { s->failed_pc=0x0c0551deu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551e0;
P_0c0551e0: /* original 2fc6, guest PC 0x0c0551e0 */
if(!s->budget--) { s->failed_pc=0x0c0551e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551e2;
P_0c0551e2: /* original 2fd6, guest PC 0x0c0551e2 */
if(!s->budget--) { s->failed_pc=0x0c0551e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551e4;
P_0c0551e4: /* original 2fe6, guest PC 0x0c0551e4 */
if(!s->budget--) { s->failed_pc=0x0c0551e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0551e6;
P_0c0551e6: /* original 4f12, guest PC 0x0c0551e6 */
if(!s->budget--) { s->failed_pc=0x0c0551e6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0551e8;
P_0c0551e8: /* original 4f02, guest PC 0x0c0551e8 */
if(!s->budget--) { s->failed_pc=0x0c0551e8u; return 0; }
r[15]-=4; write(ram,r[15],r[20],4);
goto P_0c0551ea;
P_0c0551ea: /* original d34b, guest PC 0x0c0551ea */
if(!s->budget--) { s->failed_pc=0x0c0551eau; return 0; }
r[3]=read(ram,0x0c055318u,4);
goto P_0c0551ec;
P_0c0551ec: /* original d04b, guest PC 0x0c0551ec */
if(!s->budget--) { s->failed_pc=0x0c0551ecu; return 0; }
r[0]=read(ram,0x0c05531cu,4);
goto P_0c0551ee;
P_0c0551ee: /* original 6a43, guest PC 0x0c0551ee */
if(!s->budget--) { s->failed_pc=0x0c0551eeu; return 0; }
r[10]=r[4];
goto P_0c0551f0;
P_0c0551f0: /* original 2a6a, guest PC 0x0c0551f0 */
if(!s->budget--) { s->failed_pc=0x0c0551f0u; return 0; }
r[10]^=r[6];
goto P_0c0551f2;
P_0c0551f2: /* original 6843, guest PC 0x0c0551f2 */
if(!s->budget--) { s->failed_pc=0x0c0551f2u; return 0; }
r[8]=r[4];
goto P_0c0551f4;
P_0c0551f4: /* original 4829, guest PC 0x0c0551f4 */
if(!s->budget--) { s->failed_pc=0x0c0551f4u; return 0; }
r[8]>>=16;
goto P_0c0551f6;
P_0c0551f6: /* original 4809, guest PC 0x0c0551f6 */
if(!s->budget--) { s->failed_pc=0x0c0551f6u; return 0; }
r[8]>>=2;
goto P_0c0551f8;
P_0c0551f8: /* original 4809, guest PC 0x0c0551f8 */
if(!s->budget--) { s->failed_pc=0x0c0551f8u; return 0; }
r[8]>>=2;
goto P_0c0551fa;
P_0c0551fa: /* original 2839, guest PC 0x0c0551fa */
if(!s->budget--) { s->failed_pc=0x0c0551fau; return 0; }
r[8]&=r[3];
goto P_0c0551fc;
P_0c0551fc: /* original 6963, guest PC 0x0c0551fc */
if(!s->budget--) { s->failed_pc=0x0c0551fcu; return 0; }
r[9]=r[6];
goto P_0c0551fe;
P_0c0551fe: /* original 4929, guest PC 0x0c0551fe */
if(!s->budget--) { s->failed_pc=0x0c0551feu; return 0; }
r[9]>>=16;
goto P_0c055200;
P_0c055200: /* original 4909, guest PC 0x0c055200 */
if(!s->budget--) { s->failed_pc=0x0c055200u; return 0; }
r[9]>>=2;
goto P_0c055202;
P_0c055202: /* original 4909, guest PC 0x0c055202 */
if(!s->budget--) { s->failed_pc=0x0c055202u; return 0; }
r[9]>>=2;
goto P_0c055204;
P_0c055204: /* original 2939, guest PC 0x0c055204 */
if(!s->budget--) { s->failed_pc=0x0c055204u; return 0; }
r[9]&=r[3];
goto P_0c055206;
P_0c055206: /* original 2409, guest PC 0x0c055206 */
if(!s->budget--) { s->failed_pc=0x0c055206u; return 0; }
r[4]&=r[0];
goto P_0c055208;
P_0c055208: /* original 2609, guest PC 0x0c055208 */
if(!s->budget--) { s->failed_pc=0x0c055208u; return 0; }
r[6]&=r[0];
goto P_0c05520a;
P_0c05520a: /* original 3830, guest PC 0x0c05520a */
if(!s->budget--) { s->failed_pc=0x0c05520au; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[3])!=0);
goto P_0c05520c;
P_0c05520c: /* original 8986, guest PC 0x0c05520c */
if(!s->budget--) { s->failed_pc=0x0c05520cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05511c; }
goto P_0c05520e;
P_0c05520e: /* original 3930, guest PC 0x0c05520e */
if(!s->budget--) { s->failed_pc=0x0c05520eu; return 0; }
r[17]=(r[17]&~1u)|((r[9]==r[3])!=0);
goto P_0c055210;
P_0c055210: /* original 8998, guest PC 0x0c055210 */
if(!s->budget--) { s->failed_pc=0x0c055210u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055144; }
goto P_0c055212;
P_0c055212: /* original 2888, guest PC 0x0c055212 */
if(!s->budget--) { s->failed_pc=0x0c055212u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[8])==0)!=0);
goto P_0c055214;
P_0c055214: /* original 89a2, guest PC 0x0c055214 */
if(!s->budget--) { s->failed_pc=0x0c055214u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05515c; }
goto P_0c055216;
P_0c055216: /* original 2998, guest PC 0x0c055216 */
if(!s->budget--) { s->failed_pc=0x0c055216u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c055218;
P_0c055218: /* original 89b2, guest PC 0x0c055218 */
if(!s->budget--) { s->failed_pc=0x0c055218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055180; }
goto P_0c05521a;
P_0c05521a: /* original d243, guest PC 0x0c05521a */
if(!s->budget--) { s->failed_pc=0x0c05521au; return 0; }
r[2]=read(ram,0x0c055328u,4);
goto P_0c05521c;
P_0c05521c: /* original 389c, guest PC 0x0c05521c */
if(!s->budget--) { s->failed_pc=0x0c05521cu; return 0; }
r[8]+=r[9];
goto P_0c05521e;
P_0c05521e: /* original 3828, guest PC 0x0c05521e */
if(!s->budget--) { s->failed_pc=0x0c05521eu; return 0; }
r[8]-=r[2];
goto P_0c055220;
P_0c055220: /* original 3833, guest PC 0x0c055220 */
if(!s->budget--) { s->failed_pc=0x0c055220u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[3])!=0);
goto P_0c055222;
P_0c055222: /* original 89c4, guest PC 0x0c055222 */
if(!s->budget--) { s->failed_pc=0x0c055222u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0551ae; }
goto P_0c055224;
P_0c055224: /* original e3cb, guest PC 0x0c055224 */
if(!s->budget--) { s->failed_pc=0x0c055224u; return 0; }
r[3]=0xffffffcbu;
goto P_0c055226;
P_0c055226: /* original 3387, guest PC 0x0c055226 */
if(!s->budget--) { s->failed_pc=0x0c055226u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[8])!=0);
goto P_0c055228;
P_0c055228: /* original 89bc, guest PC 0x0c055228 */
if(!s->budget--) { s->failed_pc=0x0c055228u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0551a4; }
goto P_0c05522a;
P_0c05522a: /* original d03d, guest PC 0x0c05522a */
if(!s->budget--) { s->failed_pc=0x0c05522au; return 0; }
r[0]=read(ram,0x0c055320u,4);
goto P_0c05522c;
P_0c05522c: /* original 240b, guest PC 0x0c05522c */
if(!s->budget--) { s->failed_pc=0x0c05522cu; return 0; }
r[4]|=r[0];
goto P_0c05522e;
P_0c05522e: /* original 260b, guest PC 0x0c05522e */
if(!s->budget--) { s->failed_pc=0x0c05522eu; return 0; }
r[6]|=r[0];
goto P_0c055230;
P_0c055230: /* original 3755, guest PC 0x0c055230 */
if(!s->budget--) { s->failed_pc=0x0c055230u; return 0; }
wide=(uint64_t)r[7]*r[5]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c055232;
P_0c055232: /* original 020a, guest PC 0x0c055232 */
if(!s->budget--) { s->failed_pc=0x0c055232u; return 0; }
r[2]=r[20];
goto P_0c055234;
P_0c055234: /* original 031a, guest PC 0x0c055234 */
if(!s->budget--) { s->failed_pc=0x0c055234u; return 0; }
r[3]=r[19];
goto P_0c055236;
P_0c055236: /* original 3645, guest PC 0x0c055236 */
if(!s->budget--) { s->failed_pc=0x0c055236u; return 0; }
wide=(uint64_t)r[6]*r[4]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c055238;
P_0c055238: /* original 090a, guest PC 0x0c055238 */
if(!s->budget--) { s->failed_pc=0x0c055238u; return 0; }
r[9]=r[20];
goto P_0c05523a;
P_0c05523a: /* original 011a, guest PC 0x0c05523a */
if(!s->budget--) { s->failed_pc=0x0c05523au; return 0; }
r[1]=r[19];
goto P_0c05523c;
P_0c05523c: /* original 3745, guest PC 0x0c05523c */
if(!s->budget--) { s->failed_pc=0x0c05523cu; return 0; }
wide=(uint64_t)r[7]*r[4]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c05523e;
P_0c05523e: /* original 040a, guest PC 0x0c05523e */
if(!s->budget--) { s->failed_pc=0x0c05523eu; return 0; }
r[4]=r[20];
goto P_0c055240;
P_0c055240: /* original 071a, guest PC 0x0c055240 */
if(!s->budget--) { s->failed_pc=0x0c055240u; return 0; }
r[7]=r[19];
goto P_0c055242;
P_0c055242: /* original 3655, guest PC 0x0c055242 */
if(!s->budget--) { s->failed_pc=0x0c055242u; return 0; }
wide=(uint64_t)r[6]*r[5]; r[19]=(uint32_t)wide; r[20]=(uint32_t)(wide>>32);
goto P_0c055244;
P_0c055244: /* original 060a, guest PC 0x0c055244 */
if(!s->budget--) { s->failed_pc=0x0c055244u; return 0; }
r[6]=r[20];
goto P_0c055246;
P_0c055246: /* original 001a, guest PC 0x0c055246 */
if(!s->budget--) { s->failed_pc=0x0c055246u; return 0; }
r[0]=r[19];
goto P_0c055248;
P_0c055248: /* original 0008, guest PC 0x0c055248 */
if(!s->budget--) { s->failed_pc=0x0c055248u; return 0; }
r[17]=(r[17]&~1u)|((0)!=0);
goto P_0c05524a;
P_0c05524a: /* original 372e, guest PC 0x0c05524a */
if(!s->budget--) { s->failed_pc=0x0c05524au; return 0; }
wide=(uint64_t)r[7]+r[2]+(r[17]&1u); r[7]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c05524c;
P_0c05524c: /* original 364e, guest PC 0x0c05524c */
if(!s->budget--) { s->failed_pc=0x0c05524cu; return 0; }
wide=(uint64_t)r[6]+r[4]+(r[17]&1u); r[6]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c05524e;
P_0c05524e: /* original e200, guest PC 0x0c05524e */
if(!s->budget--) { s->failed_pc=0x0c05524eu; return 0; }
r[2]=0x00000000u;
goto P_0c055250;
P_0c055250: /* original 307e, guest PC 0x0c055250 */
if(!s->budget--) { s->failed_pc=0x0c055250u; return 0; }
wide=(uint64_t)r[0]+r[7]+(r[17]&1u); r[0]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c055252;
P_0c055252: /* original 316e, guest PC 0x0c055252 */
if(!s->budget--) { s->failed_pc=0x0c055252u; return 0; }
wide=(uint64_t)r[1]+r[6]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c055254;
P_0c055254: /* original 392e, guest PC 0x0c055254 */
if(!s->budget--) { s->failed_pc=0x0c055254u; return 0; }
wide=(uint64_t)r[9]+r[2]+(r[17]&1u); r[9]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c055256;
P_0c055256: /* original 2338, guest PC 0x0c055256 */
if(!s->budget--) { s->failed_pc=0x0c055256u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c055258;
P_0c055258: /* original 8900, guest PC 0x0c055258 */
if(!s->budget--) { s->failed_pc=0x0c055258u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05525c; }
goto P_0c05525a;
P_0c05525a: /* original cb01, guest PC 0x0c05525a */
if(!s->budget--) { s->failed_pc=0x0c05525au; return 0; }
r[0]|=1u;
goto P_0c05525c;
P_0c05525c: /* original 230d, guest PC 0x0c05525c */
if(!s->budget--) { s->failed_pc=0x0c05525cu; return 0; }
r[3]=(r[3]>>16)|(r[0]<<16);
goto P_0c05525e;
P_0c05525e: /* original 201d, guest PC 0x0c05525e */
if(!s->budget--) { s->failed_pc=0x0c05525eu; return 0; }
r[0]=(r[0]>>16)|(r[1]<<16);
goto P_0c055260;
P_0c055260: /* original 219d, guest PC 0x0c055260 */
if(!s->budget--) { s->failed_pc=0x0c055260u; return 0; }
r[1]=(r[1]>>16)|(r[9]<<16);
goto P_0c055262;
P_0c055262: /* original 4101, guest PC 0x0c055262 */
if(!s->budget--) { s->failed_pc=0x0c055262u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c055264;
P_0c055264: /* original 4025, guest PC 0x0c055264 */
if(!s->budget--) { s->failed_pc=0x0c055264u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055266;
P_0c055266: /* original 4325, guest PC 0x0c055266 */
if(!s->budget--) { s->failed_pc=0x0c055266u; return 0; }
tmp=r[3]&1u; r[3]=(r[3]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055268;
P_0c055268: /* original d52e, guest PC 0x0c055268 */
if(!s->budget--) { s->failed_pc=0x0c055268u; return 0; }
r[5]=read(ram,0x0c055324u,4);
goto P_0c05526a;
P_0c05526a: /* original 2518, guest PC 0x0c05526a */
if(!s->budget--) { s->failed_pc=0x0c05526au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[1])==0)!=0);
goto P_0c05526c;
P_0c05526c: /* original 8908, guest PC 0x0c05526c */
if(!s->budget--) { s->failed_pc=0x0c05526cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055280; }
goto P_0c05526e;
P_0c05526e: /* original 4101, guest PC 0x0c05526e */
if(!s->budget--) { s->failed_pc=0x0c05526eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c055270;
P_0c055270: /* original 4025, guest PC 0x0c055270 */
if(!s->budget--) { s->failed_pc=0x0c055270u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055272;
P_0c055272: /* original 4325, guest PC 0x0c055272 */
if(!s->budget--) { s->failed_pc=0x0c055272u; return 0; }
tmp=r[3]&1u; r[3]=(r[3]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055274;
P_0c055274: /* original 7801, guest PC 0x0c055274 */
if(!s->budget--) { s->failed_pc=0x0c055274u; return 0; }
r[8]+=0x00000001u;
goto P_0c055276;
P_0c055276: /* original d428, guest PC 0x0c055276 */
if(!s->budget--) { s->failed_pc=0x0c055276u; return 0; }
r[4]=read(ram,0x0c055318u,4);
goto P_0c055278;
P_0c055278: /* original 3840, guest PC 0x0c055278 */
if(!s->budget--) { s->failed_pc=0x0c055278u; return 0; }
r[17]=(r[17]&~1u)|((r[8]==r[4])!=0);
goto P_0c05527a;
P_0c05527a: /* original 8b01, guest PC 0x0c05527a */
if(!s->budget--) { s->failed_pc=0x0c05527au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c055280; }
goto P_0c05527c;
P_0c05527c: /* original af97, guest PC 0x0c05527c */
if(!s->budget--) { s->failed_pc=0x0c05527cu; return 0; }
goto P_0c0551ae;
P_0c05527e: /* original 0009, guest PC 0x0c05527e */
if(!s->budget--) { s->failed_pc=0x0c05527eu; return 0; }
goto P_0c055280;
P_0c055280: /* original 2338, guest PC 0x0c055280 */
if(!s->budget--) { s->failed_pc=0x0c055280u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c055282;
P_0c055282: /* original 8900, guest PC 0x0c055282 */
if(!s->budget--) { s->failed_pc=0x0c055282u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c055286; }
goto P_0c055284;
P_0c055284: /* original cb01, guest PC 0x0c055284 */
if(!s->budget--) { s->failed_pc=0x0c055284u; return 0; }
r[0]|=1u;
goto P_0c055286;
P_0c055286: /* original 4815, guest PC 0x0c055286 */
if(!s->budget--) { s->failed_pc=0x0c055286u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c055288;
P_0c055288: /* original 8914, guest PC 0x0c055288 */
if(!s->budget--) { s->failed_pc=0x0c055288u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552b4; }
goto P_0c05528a;
P_0c05528a: /* original 688b, guest PC 0x0c05528a */
if(!s->budget--) { s->failed_pc=0x0c05528au; return 0; }
r[8]=0u-r[8];
goto P_0c05528c;
P_0c05528c: /* original 7801, guest PC 0x0c05528c */
if(!s->budget--) { s->failed_pc=0x0c05528cu; return 0; }
r[8]+=0x00000001u;
goto P_0c05528e;
P_0c05528e: /* original 4101, guest PC 0x0c05528e */
if(!s->budget--) { s->failed_pc=0x0c05528eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c055290;
P_0c055290: /* original 4025, guest PC 0x0c055290 */
if(!s->budget--) { s->failed_pc=0x0c055290u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c055292;
P_0c055292: /* original 0329, guest PC 0x0c055292 */
if(!s->budget--) { s->failed_pc=0x0c055292u; return 0; }
r[3]=r[17]&1u;
goto P_0c055294;
P_0c055294: /* original 4810, guest PC 0x0c055294 */
if(!s->budget--) { s->failed_pc=0x0c055294u; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c055296;
P_0c055296: /* original 8ffa, guest PC 0x0c055296 */
if(!s->budget--) { s->failed_pc=0x0c055296u; return 0; }
cond=r[17]&1u;
r[0]|=r[3];
if(!cond) { goto P_0c05528e; }
goto P_0c05529a;
P_0c055298: /* original 203b, guest PC 0x0c055298 */
if(!s->budget--) { s->failed_pc=0x0c055298u; return 0; }
r[0]|=r[3];
goto P_0c05529a;
P_0c05529a: /* original c804, guest PC 0x0c05529a */
if(!s->budget--) { s->failed_pc=0x0c05529au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c05529c;
P_0c05529c: /* original 8908, guest PC 0x0c05529c */
if(!s->budget--) { s->failed_pc=0x0c05529cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552b0; }
goto P_0c05529e;
P_0c05529e: /* original c80b, guest PC 0x0c05529e */
if(!s->budget--) { s->failed_pc=0x0c05529eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&11u)==0)!=0);
goto P_0c0552a0;
P_0c0552a0: /* original 8906, guest PC 0x0c0552a0 */
if(!s->budget--) { s->failed_pc=0x0c0552a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552b0; }
goto P_0c0552a2;
P_0c0552a2: /* original d522, guest PC 0x0c0552a2 */
if(!s->budget--) { s->failed_pc=0x0c0552a2u; return 0; }
r[5]=read(ram,0x0c05532cu,4);
goto P_0c0552a4;
P_0c0552a4: /* original e408, guest PC 0x0c0552a4 */
if(!s->budget--) { s->failed_pc=0x0c0552a4u; return 0; }
r[4]=0x00000008u;
goto P_0c0552a6;
P_0c0552a6: /* original 304e, guest PC 0x0c0552a6 */
if(!s->budget--) { s->failed_pc=0x0c0552a6u; return 0; }
wide=(uint64_t)r[0]+r[4]+(r[17]&1u); r[0]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0552a8;
P_0c0552a8: /* original 312e, guest PC 0x0c0552a8 */
if(!s->budget--) { s->failed_pc=0x0c0552a8u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0552aa;
P_0c0552aa: /* original 3517, guest PC 0x0c0552aa */
if(!s->budget--) { s->failed_pc=0x0c0552aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[1])!=0);
goto P_0c0552ac;
P_0c0552ac: /* original 8900, guest PC 0x0c0552ac */
if(!s->budget--) { s->failed_pc=0x0c0552acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552b0; }
goto P_0c0552ae;
P_0c0552ae: /* original 7801, guest PC 0x0c0552ae */
if(!s->budget--) { s->failed_pc=0x0c0552aeu; return 0; }
r[8]+=0x00000001u;
goto P_0c0552b0;
P_0c0552b0: /* original a00c, guest PC 0x0c0552b0 */
if(!s->budget--) { s->failed_pc=0x0c0552b0u; return 0; }
goto P_0c0552cc;
P_0c0552b2: /* original 0009, guest PC 0x0c0552b2 */
if(!s->budget--) { s->failed_pc=0x0c0552b2u; return 0; }
goto P_0c0552b4;
P_0c0552b4: /* original c804, guest PC 0x0c0552b4 */
if(!s->budget--) { s->failed_pc=0x0c0552b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0552b6;
P_0c0552b6: /* original 8909, guest PC 0x0c0552b6 */
if(!s->budget--) { s->failed_pc=0x0c0552b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552cc; }
goto P_0c0552b8;
P_0c0552b8: /* original c80b, guest PC 0x0c0552b8 */
if(!s->budget--) { s->failed_pc=0x0c0552b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&11u)==0)!=0);
goto P_0c0552ba;
P_0c0552ba: /* original 8907, guest PC 0x0c0552ba */
if(!s->budget--) { s->failed_pc=0x0c0552bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552cc; }
goto P_0c0552bc;
P_0c0552bc: /* original e408, guest PC 0x0c0552bc */
if(!s->budget--) { s->failed_pc=0x0c0552bcu; return 0; }
r[4]=0x00000008u;
goto P_0c0552be;
P_0c0552be: /* original 304e, guest PC 0x0c0552be */
if(!s->budget--) { s->failed_pc=0x0c0552beu; return 0; }
wide=(uint64_t)r[0]+r[4]+(r[17]&1u); r[0]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0552c0;
P_0c0552c0: /* original 312e, guest PC 0x0c0552c0 */
if(!s->budget--) { s->failed_pc=0x0c0552c0u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c0552c2;
P_0c0552c2: /* original 3517, guest PC 0x0c0552c2 */
if(!s->budget--) { s->failed_pc=0x0c0552c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[1])!=0);
goto P_0c0552c4;
P_0c0552c4: /* original 8902, guest PC 0x0c0552c4 */
if(!s->budget--) { s->failed_pc=0x0c0552c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0552cc; }
goto P_0c0552c6;
P_0c0552c6: /* original 4101, guest PC 0x0c0552c6 */
if(!s->budget--) { s->failed_pc=0x0c0552c6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c0552c8;
P_0c0552c8: /* original 4025, guest PC 0x0c0552c8 */
if(!s->budget--) { s->failed_pc=0x0c0552c8u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c0552ca;
P_0c0552ca: /* original 7801, guest PC 0x0c0552ca */
if(!s->budget--) { s->failed_pc=0x0c0552cau; return 0; }
r[8]+=0x00000001u;
goto P_0c0552cc;
P_0c0552cc: /* original 4101, guest PC 0x0c0552cc */
if(!s->budget--) { s->failed_pc=0x0c0552ccu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c0552ce;
P_0c0552ce: /* original 4025, guest PC 0x0c0552ce */
if(!s->budget--) { s->failed_pc=0x0c0552ceu; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c0552d0;
P_0c0552d0: /* original 4101, guest PC 0x0c0552d0 */
if(!s->budget--) { s->failed_pc=0x0c0552d0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c0552d2;
P_0c0552d2: /* original 4025, guest PC 0x0c0552d2 */
if(!s->budget--) { s->failed_pc=0x0c0552d2u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c0552d4;
P_0c0552d4: /* original 4101, guest PC 0x0c0552d4 */
if(!s->budget--) { s->failed_pc=0x0c0552d4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c0552d6;
P_0c0552d6: /* original 4025, guest PC 0x0c0552d6 */
if(!s->budget--) { s->failed_pc=0x0c0552d6u; return 0; }
tmp=r[0]&1u; r[0]=(r[0]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c0552d8;
P_0c0552d8: /* original d210, guest PC 0x0c0552d8 */
if(!s->budget--) { s->failed_pc=0x0c0552d8u; return 0; }
r[2]=read(ram,0x0c05531cu,4);
goto P_0c0552da;
P_0c0552da: /* original 2129, guest PC 0x0c0552da */
if(!s->budget--) { s->failed_pc=0x0c0552dau; return 0; }
r[1]&=r[2];
goto P_0c0552dc;
P_0c0552dc: /* original 4828, guest PC 0x0c0552dc */
if(!s->budget--) { s->failed_pc=0x0c0552dcu; return 0; }
r[8]<<=16;
goto P_0c0552de;
P_0c0552de: /* original 4808, guest PC 0x0c0552de */
if(!s->budget--) { s->failed_pc=0x0c0552deu; return 0; }
r[8]<<=2;
goto P_0c0552e0;
P_0c0552e0: /* original 4808, guest PC 0x0c0552e0 */
if(!s->budget--) { s->failed_pc=0x0c0552e0u; return 0; }
r[8]<<=2;
goto P_0c0552e2;
P_0c0552e2: /* original 218b, guest PC 0x0c0552e2 */
if(!s->budget--) { s->failed_pc=0x0c0552e2u; return 0; }
r[1]|=r[8];
goto P_0c0552e4;
P_0c0552e4: /* original 4100, guest PC 0x0c0552e4 */
if(!s->budget--) { s->failed_pc=0x0c0552e4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0552e6;
P_0c0552e6: /* original 4a00, guest PC 0x0c0552e6 */
if(!s->budget--) { s->failed_pc=0x0c0552e6u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c0552e8;
P_0c0552e8: /* original 4125, guest PC 0x0c0552e8 */
if(!s->budget--) { s->failed_pc=0x0c0552e8u; return 0; }
tmp=r[1]&1u; r[1]=(r[1]>>1)|((r[17]&1u)<<31);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c0552ea;
P_0c0552ea: /* original 4f06, guest PC 0x0c0552ea */
if(!s->budget--) { s->failed_pc=0x0c0552eau; return 0; }
r[20]=read(ram,r[15],4); r[15]+=4;
goto P_0c0552ec;
P_0c0552ec: /* original 4f16, guest PC 0x0c0552ec */
if(!s->budget--) { s->failed_pc=0x0c0552ecu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0552ee;
P_0c0552ee: /* original 6ef6, guest PC 0x0c0552ee */
if(!s->budget--) { s->failed_pc=0x0c0552eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0552f0;
P_0c0552f0: /* original 6df6, guest PC 0x0c0552f0 */
if(!s->budget--) { s->failed_pc=0x0c0552f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0552f2;
P_0c0552f2: /* original 6cf6, guest PC 0x0c0552f2 */
if(!s->budget--) { s->failed_pc=0x0c0552f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0552f4;
P_0c0552f4: /* original 6bf6, guest PC 0x0c0552f4 */
if(!s->budget--) { s->failed_pc=0x0c0552f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0552f6;
P_0c0552f6: /* original 6af6, guest PC 0x0c0552f6 */
if(!s->budget--) { s->failed_pc=0x0c0552f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0552f8;
P_0c0552f8: /* original 69f6, guest PC 0x0c0552f8 */
if(!s->budget--) { s->failed_pc=0x0c0552f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0552fa;
P_0c0552fa: /* original 68f6, guest PC 0x0c0552fa */
if(!s->budget--) { s->failed_pc=0x0c0552fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0552fc;
P_0c0552fc: /* original 63f6, guest PC 0x0c0552fc */
if(!s->budget--) { s->failed_pc=0x0c0552fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c0552fe;
P_0c0552fe: /* original 62f6, guest PC 0x0c0552fe */
if(!s->budget--) { s->failed_pc=0x0c0552feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c055300;
P_0c055300: /* original 56f6, guest PC 0x0c055300 */
if(!s->budget--) { s->failed_pc=0x0c055300u; return 0; }
r[6]=read(ram,r[15]+24,4);
goto P_0c055302;
P_0c055302: /* original 2602, guest PC 0x0c055302 */
if(!s->budget--) { s->failed_pc=0x0c055302u; return 0; }
write(ram,r[6],r[0],4);
goto P_0c055304;
P_0c055304: /* original 1611, guest PC 0x0c055304 */
if(!s->budget--) { s->failed_pc=0x0c055304u; return 0; }
write(ram,r[6]+4,r[1],4);
goto P_0c055306;
P_0c055306: /* original 67f6, guest PC 0x0c055306 */
if(!s->budget--) { s->failed_pc=0x0c055306u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[7]=tmp;
goto P_0c055308;
P_0c055308: /* original 66f6, guest PC 0x0c055308 */
if(!s->budget--) { s->failed_pc=0x0c055308u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[6]=tmp;
goto P_0c05530a;
P_0c05530a: /* original 65f6, guest PC 0x0c05530a */
if(!s->budget--) { s->failed_pc=0x0c05530au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c05530c;
P_0c05530c: /* original 64f6, guest PC 0x0c05530c */
if(!s->budget--) { s->failed_pc=0x0c05530cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c05530e;
P_0c05530e: /* original 61f6, guest PC 0x0c05530e */
if(!s->budget--) { s->failed_pc=0x0c05530eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c055310;
P_0c055310: /* original 60f6, guest PC 0x0c055310 */
if(!s->budget--) { s->failed_pc=0x0c055310u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[0]=tmp;
goto P_0c055312;
P_0c055312: /* original 000b, guest PC 0x0c055312 */
if(!s->budget--) { s->failed_pc=0x0c055312u; return 0; }
target=r[16];
r[15]+=0x00000014u;
s->pc=target; return ram->oob==0;
P_0c055314: /* original 7f14, guest PC 0x0c055314 */
if(!s->budget--) { s->failed_pc=0x0c055314u; return 0; }
r[15]+=0x00000014u;
if(!vf3_matrix_family(0x0c055316u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c055316u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
