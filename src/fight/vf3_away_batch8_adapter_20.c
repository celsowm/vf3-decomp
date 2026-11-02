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
int vf3_away_batch8_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c065078u: goto P_0c065078;
case 0x0c06507au: goto P_0c06507a;
case 0x0c06507cu: goto P_0c06507c;
case 0x0c06507eu: goto P_0c06507e;
case 0x0c065080u: goto P_0c065080;
case 0x0c065082u: goto P_0c065082;
case 0x0c065084u: goto P_0c065084;
case 0x0c065086u: goto P_0c065086;
case 0x0c065088u: goto P_0c065088;
case 0x0c06508au: goto P_0c06508a;
case 0x0c06508cu: goto P_0c06508c;
case 0x0c06508eu: goto P_0c06508e;
case 0x0c065090u: goto P_0c065090;
case 0x0c065092u: goto P_0c065092;
case 0x0c065094u: goto P_0c065094;
case 0x0c065096u: goto P_0c065096;
case 0x0c065098u: goto P_0c065098;
case 0x0c06509au: goto P_0c06509a;
case 0x0c06509cu: goto P_0c06509c;
case 0x0c06509eu: goto P_0c06509e;
case 0x0c0650a0u: goto P_0c0650a0;
case 0x0c0650a2u: goto P_0c0650a2;
case 0x0c0650a4u: goto P_0c0650a4;
case 0x0c0650a6u: goto P_0c0650a6;
case 0x0c0650a8u: goto P_0c0650a8;
case 0x0c0650aau: goto P_0c0650aa;
case 0x0c0650acu: goto P_0c0650ac;
case 0x0c0650aeu: goto P_0c0650ae;
case 0x0c0650b0u: goto P_0c0650b0;
case 0x0c0650b2u: goto P_0c0650b2;
case 0x0c0650b4u: goto P_0c0650b4;
case 0x0c0650b6u: goto P_0c0650b6;
case 0x0c0650b8u: goto P_0c0650b8;
case 0x0c0650bau: goto P_0c0650ba;
case 0x0c0650bcu: goto P_0c0650bc;
case 0x0c0650beu: goto P_0c0650be;
case 0x0c0650c0u: goto P_0c0650c0;
case 0x0c0650c2u: goto P_0c0650c2;
case 0x0c0650c4u: goto P_0c0650c4;
case 0x0c0650c6u: goto P_0c0650c6;
case 0x0c0650c8u: goto P_0c0650c8;
case 0x0c0650cau: goto P_0c0650ca;
case 0x0c0650ccu: goto P_0c0650cc;
case 0x0c0650ceu: goto P_0c0650ce;
case 0x0c0650d0u: goto P_0c0650d0;
case 0x0c0650d2u: goto P_0c0650d2;
case 0x0c0650d4u: goto P_0c0650d4;
case 0x0c0650d6u: goto P_0c0650d6;
case 0x0c0650d8u: goto P_0c0650d8;
case 0x0c0650dau: goto P_0c0650da;
case 0x0c0650dcu: goto P_0c0650dc;
case 0x0c0650deu: goto P_0c0650de;
case 0x0c0650e0u: goto P_0c0650e0;
case 0x0c0650e2u: goto P_0c0650e2;
case 0x0c0650e4u: goto P_0c0650e4;
case 0x0c0650e6u: goto P_0c0650e6;
case 0x0c0650e8u: goto P_0c0650e8;
case 0x0c0650eau: goto P_0c0650ea;
case 0x0c0650ecu: goto P_0c0650ec;
case 0x0c0650eeu: goto P_0c0650ee;
case 0x0c0650f0u: goto P_0c0650f0;
case 0x0c0650f2u: goto P_0c0650f2;
case 0x0c0650f4u: goto P_0c0650f4;
case 0x0c0650f6u: goto P_0c0650f6;
case 0x0c0650f8u: goto P_0c0650f8;
case 0x0c0650fau: goto P_0c0650fa;
case 0x0c0650fcu: goto P_0c0650fc;
case 0x0c0650feu: goto P_0c0650fe;
case 0x0c065100u: goto P_0c065100;
case 0x0c065102u: goto P_0c065102;
case 0x0c065104u: goto P_0c065104;
case 0x0c065106u: goto P_0c065106;
case 0x0c065108u: goto P_0c065108;
case 0x0c06510au: goto P_0c06510a;
case 0x0c06510cu: goto P_0c06510c;
case 0x0c06510eu: goto P_0c06510e;
case 0x0c065110u: goto P_0c065110;
case 0x0c065112u: goto P_0c065112;
case 0x0c065114u: goto P_0c065114;
case 0x0c065116u: goto P_0c065116;
case 0x0c065118u: goto P_0c065118;
case 0x0c06511au: goto P_0c06511a;
case 0x0c06511cu: goto P_0c06511c;
case 0x0c06511eu: goto P_0c06511e;
case 0x0c065120u: goto P_0c065120;
case 0x0c065122u: goto P_0c065122;
case 0x0c065124u: goto P_0c065124;
case 0x0c065126u: goto P_0c065126;
case 0x0c065128u: goto P_0c065128;
case 0x0c06512au: goto P_0c06512a;
case 0x0c06512cu: goto P_0c06512c;
case 0x0c06512eu: goto P_0c06512e;
case 0x0c065130u: goto P_0c065130;
case 0x0c065132u: goto P_0c065132;
case 0x0c065134u: goto P_0c065134;
case 0x0c065136u: goto P_0c065136;
case 0x0c065138u: goto P_0c065138;
case 0x0c06513au: goto P_0c06513a;
case 0x0c06513cu: goto P_0c06513c;
case 0x0c06513eu: goto P_0c06513e;
case 0x0c065140u: goto P_0c065140;
case 0x0c065142u: goto P_0c065142;
case 0x0c065144u: goto P_0c065144;
case 0x0c065146u: goto P_0c065146;
case 0x0c065148u: goto P_0c065148;
case 0x0c06514au: goto P_0c06514a;
case 0x0c06514cu: goto P_0c06514c;
case 0x0c06514eu: goto P_0c06514e;
case 0x0c065150u: goto P_0c065150;
case 0x0c065152u: goto P_0c065152;
case 0x0c065154u: goto P_0c065154;
case 0x0c065156u: goto P_0c065156;
case 0x0c065158u: goto P_0c065158;
case 0x0c06515au: goto P_0c06515a;
case 0x0c06515cu: goto P_0c06515c;
case 0x0c06515eu: goto P_0c06515e;
case 0x0c065160u: goto P_0c065160;
case 0x0c065162u: goto P_0c065162;
case 0x0c065164u: goto P_0c065164;
case 0x0c065166u: goto P_0c065166;
case 0x0c065168u: goto P_0c065168;
case 0x0c06516au: goto P_0c06516a;
case 0x0c06516cu: goto P_0c06516c;
case 0x0c06516eu: goto P_0c06516e;
case 0x0c065170u: goto P_0c065170;
case 0x0c065172u: goto P_0c065172;
case 0x0c065174u: goto P_0c065174;
case 0x0c065176u: goto P_0c065176;
case 0x0c065178u: goto P_0c065178;
case 0x0c06517au: goto P_0c06517a;
case 0x0c06517cu: goto P_0c06517c;
case 0x0c06517eu: goto P_0c06517e;
case 0x0c065180u: goto P_0c065180;
case 0x0c065182u: goto P_0c065182;
case 0x0c065184u: goto P_0c065184;
case 0x0c065186u: goto P_0c065186;
case 0x0c065188u: goto P_0c065188;
case 0x0c06518au: goto P_0c06518a;
case 0x0c06518cu: goto P_0c06518c;
case 0x0c06518eu: goto P_0c06518e;
case 0x0c065190u: goto P_0c065190;
case 0x0c065192u: goto P_0c065192;
case 0x0c065194u: goto P_0c065194;
case 0x0c065196u: goto P_0c065196;
case 0x0c065198u: goto P_0c065198;
case 0x0c06519au: goto P_0c06519a;
case 0x0c06519cu: goto P_0c06519c;
case 0x0c06519eu: goto P_0c06519e;
case 0x0c0651a0u: goto P_0c0651a0;
case 0x0c0651a2u: goto P_0c0651a2;
case 0x0c0651a4u: goto P_0c0651a4;
case 0x0c0651a6u: goto P_0c0651a6;
case 0x0c0651a8u: goto P_0c0651a8;
case 0x0c0651aau: goto P_0c0651aa;
case 0x0c0651acu: goto P_0c0651ac;
case 0x0c0651aeu: goto P_0c0651ae;
case 0x0c0651b0u: goto P_0c0651b0;
case 0x0c0651b2u: goto P_0c0651b2;
case 0x0c0651b4u: goto P_0c0651b4;
case 0x0c0651b6u: goto P_0c0651b6;
case 0x0c0651b8u: goto P_0c0651b8;
case 0x0c0651bau: goto P_0c0651ba;
case 0x0c0651bcu: goto P_0c0651bc;
case 0x0c0651beu: goto P_0c0651be;
case 0x0c0651c0u: goto P_0c0651c0;
case 0x0c0651c2u: goto P_0c0651c2;
case 0x0c0651c4u: goto P_0c0651c4;
case 0x0c0651c6u: goto P_0c0651c6;
case 0x0c0651c8u: goto P_0c0651c8;
case 0x0c0651cau: goto P_0c0651ca;
case 0x0c0651ccu: goto P_0c0651cc;
case 0x0c0651ceu: goto P_0c0651ce;
case 0x0c0651d0u: goto P_0c0651d0;
case 0x0c0651d2u: goto P_0c0651d2;
case 0x0c0651d4u: goto P_0c0651d4;
case 0x0c0651d6u: goto P_0c0651d6;
case 0x0c0651d8u: goto P_0c0651d8;
case 0x0c0651dau: goto P_0c0651da;
case 0x0c0651dcu: goto P_0c0651dc;
case 0x0c0651deu: goto P_0c0651de;
case 0x0c0651e0u: goto P_0c0651e0;
case 0x0c0651e2u: goto P_0c0651e2;
case 0x0c0651e4u: goto P_0c0651e4;
case 0x0c0651e6u: goto P_0c0651e6;
case 0x0c0651e8u: goto P_0c0651e8;
case 0x0c0651eau: goto P_0c0651ea;
case 0x0c0651ecu: goto P_0c0651ec;
case 0x0c0651eeu: goto P_0c0651ee;
case 0x0c0651f0u: goto P_0c0651f0;
case 0x0c0651f2u: goto P_0c0651f2;
case 0x0c0651f4u: goto P_0c0651f4;
case 0x0c0651f6u: goto P_0c0651f6;
case 0x0c0651f8u: goto P_0c0651f8;
case 0x0c0651fau: goto P_0c0651fa;
case 0x0c0651fcu: goto P_0c0651fc;
case 0x0c0651feu: goto P_0c0651fe;
case 0x0c065200u: goto P_0c065200;
case 0x0c065202u: goto P_0c065202;
case 0x0c065204u: goto P_0c065204;
case 0x0c065206u: goto P_0c065206;
case 0x0c065208u: goto P_0c065208;
case 0x0c06520au: goto P_0c06520a;
case 0x0c06520cu: goto P_0c06520c;
case 0x0c06520eu: goto P_0c06520e;
case 0x0c065210u: goto P_0c065210;
case 0x0c065212u: goto P_0c065212;
case 0x0c065214u: goto P_0c065214;
case 0x0c065216u: goto P_0c065216;
case 0x0c065218u: goto P_0c065218;
case 0x0c06521au: goto P_0c06521a;
case 0x0c06521cu: goto P_0c06521c;
case 0x0c06521eu: goto P_0c06521e;
case 0x0c065220u: goto P_0c065220;
case 0x0c065222u: goto P_0c065222;
case 0x0c065224u: goto P_0c065224;
case 0x0c065226u: goto P_0c065226;
case 0x0c065228u: goto P_0c065228;
case 0x0c06522au: goto P_0c06522a;
case 0x0c06522cu: goto P_0c06522c;
case 0x0c06522eu: goto P_0c06522e;
case 0x0c065230u: goto P_0c065230;
case 0x0c065232u: goto P_0c065232;
case 0x0c065234u: goto P_0c065234;
case 0x0c065236u: goto P_0c065236;
case 0x0c065238u: goto P_0c065238;
case 0x0c06523au: goto P_0c06523a;
case 0x0c06523cu: goto P_0c06523c;
case 0x0c06523eu: goto P_0c06523e;
case 0x0c065240u: goto P_0c065240;
case 0x0c065242u: goto P_0c065242;
case 0x0c065244u: goto P_0c065244;
case 0x0c065246u: goto P_0c065246;
case 0x0c065248u: goto P_0c065248;
case 0x0c06524au: goto P_0c06524a;
case 0x0c06524cu: goto P_0c06524c;
case 0x0c06524eu: goto P_0c06524e;
case 0x0c065250u: goto P_0c065250;
case 0x0c065252u: goto P_0c065252;
case 0x0c065254u: goto P_0c065254;
case 0x0c065256u: goto P_0c065256;
case 0x0c065258u: goto P_0c065258;
case 0x0c06525au: goto P_0c06525a;
case 0x0c06525cu: goto P_0c06525c;
case 0x0c06525eu: goto P_0c06525e;
case 0x0c065260u: goto P_0c065260;
case 0x0c065262u: goto P_0c065262;
case 0x0c065264u: goto P_0c065264;
case 0x0c065266u: goto P_0c065266;
case 0x0c065268u: goto P_0c065268;
case 0x0c06526au: goto P_0c06526a;
case 0x0c06526cu: goto P_0c06526c;
case 0x0c06526eu: goto P_0c06526e;
case 0x0c065270u: goto P_0c065270;
case 0x0c065272u: goto P_0c065272;
case 0x0c065274u: goto P_0c065274;
case 0x0c065276u: goto P_0c065276;
case 0x0c065278u: goto P_0c065278;
case 0x0c06527au: goto P_0c06527a;
case 0x0c06527cu: goto P_0c06527c;
case 0x0c06527eu: goto P_0c06527e;
case 0x0c065280u: goto P_0c065280;
case 0x0c065282u: goto P_0c065282;
case 0x0c065284u: goto P_0c065284;
case 0x0c065286u: goto P_0c065286;
case 0x0c065288u: goto P_0c065288;
case 0x0c06528au: goto P_0c06528a;
case 0x0c06528cu: goto P_0c06528c;
case 0x0c06528eu: goto P_0c06528e;
case 0x0c065290u: goto P_0c065290;
case 0x0c065292u: goto P_0c065292;
case 0x0c065294u: goto P_0c065294;
case 0x0c065296u: goto P_0c065296;
case 0x0c065298u: goto P_0c065298;
case 0x0c06529au: goto P_0c06529a;
case 0x0c06529cu: goto P_0c06529c;
case 0x0c06529eu: goto P_0c06529e;
case 0x0c0652a0u: goto P_0c0652a0;
case 0x0c0652a2u: goto P_0c0652a2;
case 0x0c0652a4u: goto P_0c0652a4;
case 0x0c0652a6u: goto P_0c0652a6;
case 0x0c0652a8u: goto P_0c0652a8;
case 0x0c0652aau: goto P_0c0652aa;
case 0x0c0652acu: goto P_0c0652ac;
case 0x0c0652aeu: goto P_0c0652ae;
case 0x0c0652b0u: goto P_0c0652b0;
case 0x0c0652b2u: goto P_0c0652b2;
case 0x0c0652b4u: goto P_0c0652b4;
case 0x0c0652b6u: goto P_0c0652b6;
case 0x0c0652b8u: goto P_0c0652b8;
case 0x0c0652bau: goto P_0c0652ba;
case 0x0c0652bcu: goto P_0c0652bc;
case 0x0c0652beu: goto P_0c0652be;
case 0x0c0652c0u: goto P_0c0652c0;
case 0x0c0652c2u: goto P_0c0652c2;
case 0x0c0652c4u: goto P_0c0652c4;
case 0x0c0652c6u: goto P_0c0652c6;
case 0x0c0652c8u: goto P_0c0652c8;
case 0x0c0652cau: goto P_0c0652ca;
case 0x0c0652ccu: goto P_0c0652cc;
case 0x0c0652ceu: goto P_0c0652ce;
case 0x0c0652d0u: goto P_0c0652d0;
case 0x0c0652d2u: goto P_0c0652d2;
case 0x0c0652d4u: goto P_0c0652d4;
case 0x0c0652d6u: goto P_0c0652d6;
case 0x0c0652d8u: goto P_0c0652d8;
case 0x0c0652dau: goto P_0c0652da;
case 0x0c0652dcu: goto P_0c0652dc;
case 0x0c0652deu: goto P_0c0652de;
case 0x0c0652e0u: goto P_0c0652e0;
case 0x0c0652e2u: goto P_0c0652e2;
case 0x0c0652e4u: goto P_0c0652e4;
case 0x0c0652e6u: goto P_0c0652e6;
case 0x0c0652e8u: goto P_0c0652e8;
case 0x0c0652eau: goto P_0c0652ea;
case 0x0c0652ecu: goto P_0c0652ec;
case 0x0c0652eeu: goto P_0c0652ee;
case 0x0c0652f0u: goto P_0c0652f0;
case 0x0c0652f2u: goto P_0c0652f2;
case 0x0c0652f4u: goto P_0c0652f4;
case 0x0c0652f6u: goto P_0c0652f6;
case 0x0c0652f8u: goto P_0c0652f8;
case 0x0c0652fau: goto P_0c0652fa;
case 0x0c0652fcu: goto P_0c0652fc;
case 0x0c0652feu: goto P_0c0652fe;
case 0x0c065300u: goto P_0c065300;
case 0x0c065302u: goto P_0c065302;
case 0x0c065304u: goto P_0c065304;
case 0x0c065306u: goto P_0c065306;
case 0x0c065308u: goto P_0c065308;
case 0x0c06530au: goto P_0c06530a;
case 0x0c06530cu: goto P_0c06530c;
case 0x0c06530eu: goto P_0c06530e;
case 0x0c065310u: goto P_0c065310;
case 0x0c065312u: goto P_0c065312;
case 0x0c065314u: goto P_0c065314;
case 0x0c065316u: goto P_0c065316;
case 0x0c065318u: goto P_0c065318;
case 0x0c06531au: goto P_0c06531a;
case 0x0c06531cu: goto P_0c06531c;
case 0x0c06531eu: goto P_0c06531e;
case 0x0c065320u: goto P_0c065320;
case 0x0c065322u: goto P_0c065322;
case 0x0c065324u: goto P_0c065324;
case 0x0c065326u: goto P_0c065326;
case 0x0c065328u: goto P_0c065328;
case 0x0c06532au: goto P_0c06532a;
case 0x0c06532cu: goto P_0c06532c;
case 0x0c06532eu: goto P_0c06532e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c065078: /* original 2fe6, guest PC 0x0c065078 */
if(!s->budget--) { s->failed_pc=0x0c065078u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06507a;
P_0c06507a: /* original 2fd6, guest PC 0x0c06507a */
if(!s->budget--) { s->failed_pc=0x0c06507au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06507c;
P_0c06507c: /* original 2fc6, guest PC 0x0c06507c */
if(!s->budget--) { s->failed_pc=0x0c06507cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06507e;
P_0c06507e: /* original ec00, guest PC 0x0c06507e */
if(!s->budget--) { s->failed_pc=0x0c06507eu; return 0; }
r[12]=0x00000000u;
goto P_0c065080;
P_0c065080: /* original 2fb6, guest PC 0x0c065080 */
if(!s->budget--) { s->failed_pc=0x0c065080u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065082;
P_0c065082: /* original 2fa6, guest PC 0x0c065082 */
if(!s->budget--) { s->failed_pc=0x0c065082u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065084;
P_0c065084: /* original 2f96, guest PC 0x0c065084 */
if(!s->budget--) { s->failed_pc=0x0c065084u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065086;
P_0c065086: /* original fffb, guest PC 0x0c065086 */
if(!s->budget--) { s->failed_pc=0x0c065086u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c065088;
P_0c065088: /* original 4f22, guest PC 0x0c065088 */
if(!s->budget--) { s->failed_pc=0x0c065088u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06508a;
P_0c06508a: /* original 7ff4, guest PC 0x0c06508a */
if(!s->budget--) { s->failed_pc=0x0c06508au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06508c;
P_0c06508c: /* original 6342, guest PC 0x0c06508c */
if(!s->budget--) { s->failed_pc=0x0c06508cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c06508e;
P_0c06508e: /* original 65f3, guest PC 0x0c06508e */
if(!s->budget--) { s->failed_pc=0x0c06508eu; return 0; }
r[5]=r[15];
goto P_0c065090;
P_0c065090: /* original 6e53, guest PC 0x0c065090 */
if(!s->budget--) { s->failed_pc=0x0c065090u; return 0; }
r[14]=r[5];
goto P_0c065092;
P_0c065092: /* original 6be3, guest PC 0x0c065092 */
if(!s->budget--) { s->failed_pc=0x0c065092u; return 0; }
r[11]=r[14];
goto P_0c065094;
P_0c065094: /* original 2e32, guest PC 0x0c065094 */
if(!s->budget--) { s->failed_pc=0x0c065094u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c065096;
P_0c065096: /* original 6ae3, guest PC 0x0c065096 */
if(!s->budget--) { s->failed_pc=0x0c065096u; return 0; }
r[10]=r[14];
goto P_0c065098;
P_0c065098: /* original 5241, guest PC 0x0c065098 */
if(!s->budget--) { s->failed_pc=0x0c065098u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06509a;
P_0c06509a: /* original 7b04, guest PC 0x0c06509a */
if(!s->budget--) { s->failed_pc=0x0c06509au; return 0; }
r[11]+=0x00000004u;
goto P_0c06509c;
P_0c06509c: /* original 2b22, guest PC 0x0c06509c */
if(!s->budget--) { s->failed_pc=0x0c06509cu; return 0; }
write(ram,r[11],r[2],4);
goto P_0c06509e;
P_0c06509e: /* original 7a08, guest PC 0x0c06509e */
if(!s->budget--) { s->failed_pc=0x0c06509eu; return 0; }
r[10]+=0x00000008u;
goto P_0c0650a0;
P_0c0650a0: /* original 5342, guest PC 0x0c0650a0 */
if(!s->budget--) { s->failed_pc=0x0c0650a0u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0650a2;
P_0c0650a2: /* original 2a32, guest PC 0x0c0650a2 */
if(!s->budget--) { s->failed_pc=0x0c0650a2u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c0650a4;
P_0c0650a4: /* original d2a2, guest PC 0x0c0650a4 */
if(!s->budget--) { s->failed_pc=0x0c0650a4u; return 0; }
r[2]=read(ram,0x0c065330u,4);
goto P_0c0650a6;
P_0c0650a6: /* original 6d22, guest PC 0x0c0650a6 */
if(!s->budget--) { s->failed_pc=0x0c0650a6u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0650a8;
P_0c0650a8: /* original d3a2, guest PC 0x0c0650a8 */
if(!s->budget--) { s->failed_pc=0x0c0650a8u; return 0; }
r[3]=read(ram,0x0c065334u,4);
goto P_0c0650aa;
P_0c0650aa: /* original 6532, guest PC 0x0c0650aa */
if(!s->budget--) { s->failed_pc=0x0c0650aau; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c0650ac;
P_0c0650ac: /* original d1a2, guest PC 0x0c0650ac */
if(!s->budget--) { s->failed_pc=0x0c0650acu; return 0; }
r[1]=read(ram,0x0c065338u,4);
goto P_0c0650ae;
P_0c0650ae: /* original 6412, guest PC 0x0c0650ae */
if(!s->budget--) { s->failed_pc=0x0c0650aeu; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0650b0;
P_0c0650b0: /* original d0a2, guest PC 0x0c0650b0 */
if(!s->budget--) { s->failed_pc=0x0c0650b0u; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c0650b2;
P_0c0650b2: /* original 62c3, guest PC 0x0c0650b2 */
if(!s->budget--) { s->failed_pc=0x0c0650b2u; return 0; }
r[2]=r[12];
goto P_0c0650b4;
P_0c0650b4: /* original 7c01, guest PC 0x0c0650b4 */
if(!s->budget--) { s->failed_pc=0x0c0650b4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0650b6;
P_0c0650b6: /* original 4208, guest PC 0x0c0650b6 */
if(!s->budget--) { s->failed_pc=0x0c0650b6u; return 0; }
r[2]<<=2;
goto P_0c0650b8;
P_0c0650b8: /* original 02d6, guest PC 0x0c0650b8 */
if(!s->budget--) { s->failed_pc=0x0c0650b8u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c0650ba;
P_0c0650ba: /* original 63c3, guest PC 0x0c0650ba */
if(!s->budget--) { s->failed_pc=0x0c0650bau; return 0; }
r[3]=r[12];
goto P_0c0650bc;
P_0c0650bc: /* original 7c01, guest PC 0x0c0650bc */
if(!s->budget--) { s->failed_pc=0x0c0650bcu; return 0; }
r[12]+=0x00000001u;
goto P_0c0650be;
P_0c0650be: /* original 4308, guest PC 0x0c0650be */
if(!s->budget--) { s->failed_pc=0x0c0650beu; return 0; }
r[3]<<=2;
goto P_0c0650c0;
P_0c0650c0: /* original 0356, guest PC 0x0c0650c0 */
if(!s->budget--) { s->failed_pc=0x0c0650c0u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c0650c2;
P_0c0650c2: /* original 62c3, guest PC 0x0c0650c2 */
if(!s->budget--) { s->failed_pc=0x0c0650c2u; return 0; }
r[2]=r[12];
goto P_0c0650c4;
P_0c0650c4: /* original 7c01, guest PC 0x0c0650c4 */
if(!s->budget--) { s->failed_pc=0x0c0650c4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0650c6;
P_0c0650c6: /* original 4208, guest PC 0x0c0650c6 */
if(!s->budget--) { s->failed_pc=0x0c0650c6u; return 0; }
r[2]<<=2;
goto P_0c0650c8;
P_0c0650c8: /* original 0246, guest PC 0x0c0650c8 */
if(!s->budget--) { s->failed_pc=0x0c0650c8u; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c0650ca;
P_0c0650ca: /* original 63c3, guest PC 0x0c0650ca */
if(!s->budget--) { s->failed_pc=0x0c0650cau; return 0; }
r[3]=r[12];
goto P_0c0650cc;
P_0c0650cc: /* original 62e2, guest PC 0x0c0650cc */
if(!s->budget--) { s->failed_pc=0x0c0650ccu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0650ce;
P_0c0650ce: /* original 7c01, guest PC 0x0c0650ce */
if(!s->budget--) { s->failed_pc=0x0c0650ceu; return 0; }
r[12]+=0x00000001u;
goto P_0c0650d0;
P_0c0650d0: /* original 5221, guest PC 0x0c0650d0 */
if(!s->budget--) { s->failed_pc=0x0c0650d0u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c0650d2;
P_0c0650d2: /* original 4308, guest PC 0x0c0650d2 */
if(!s->budget--) { s->failed_pc=0x0c0650d2u; return 0; }
r[3]<<=2;
goto P_0c0650d4;
P_0c0650d4: /* original 0326, guest PC 0x0c0650d4 */
if(!s->budget--) { s->failed_pc=0x0c0650d4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0650d6;
P_0c0650d6: /* original 63c3, guest PC 0x0c0650d6 */
if(!s->budget--) { s->failed_pc=0x0c0650d6u; return 0; }
r[3]=r[12];
goto P_0c0650d8;
P_0c0650d8: /* original 62e2, guest PC 0x0c0650d8 */
if(!s->budget--) { s->failed_pc=0x0c0650d8u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0650da;
P_0c0650da: /* original 7c01, guest PC 0x0c0650da */
if(!s->budget--) { s->failed_pc=0x0c0650dau; return 0; }
r[12]+=0x00000001u;
goto P_0c0650dc;
P_0c0650dc: /* original 5222, guest PC 0x0c0650dc */
if(!s->budget--) { s->failed_pc=0x0c0650dcu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c0650de;
P_0c0650de: /* original 4308, guest PC 0x0c0650de */
if(!s->budget--) { s->failed_pc=0x0c0650deu; return 0; }
r[3]<<=2;
goto P_0c0650e0;
P_0c0650e0: /* original 0326, guest PC 0x0c0650e0 */
if(!s->budget--) { s->failed_pc=0x0c0650e0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0650e2;
P_0c0650e2: /* original 63c3, guest PC 0x0c0650e2 */
if(!s->budget--) { s->failed_pc=0x0c0650e2u; return 0; }
r[3]=r[12];
goto P_0c0650e4;
P_0c0650e4: /* original 62e2, guest PC 0x0c0650e4 */
if(!s->budget--) { s->failed_pc=0x0c0650e4u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0650e6;
P_0c0650e6: /* original 7c01, guest PC 0x0c0650e6 */
if(!s->budget--) { s->failed_pc=0x0c0650e6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0650e8;
P_0c0650e8: /* original 5223, guest PC 0x0c0650e8 */
if(!s->budget--) { s->failed_pc=0x0c0650e8u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c0650ea;
P_0c0650ea: /* original 4308, guest PC 0x0c0650ea */
if(!s->budget--) { s->failed_pc=0x0c0650eau; return 0; }
r[3]<<=2;
goto P_0c0650ec;
P_0c0650ec: /* original 0326, guest PC 0x0c0650ec */
if(!s->budget--) { s->failed_pc=0x0c0650ecu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0650ee;
P_0c0650ee: /* original 65c3, guest PC 0x0c0650ee */
if(!s->budget--) { s->failed_pc=0x0c0650eeu; return 0; }
r[5]=r[12];
goto P_0c0650f0;
P_0c0650f0: /* original 66e2, guest PC 0x0c0650f0 */
if(!s->budget--) { s->failed_pc=0x0c0650f0u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0650f2;
P_0c0650f2: /* original 5664, guest PC 0x0c0650f2 */
if(!s->budget--) { s->failed_pc=0x0c0650f2u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0650f4;
P_0c0650f4: /* original ba26, guest PC 0x0c0650f4 */
if(!s->budget--) { s->failed_pc=0x0c0650f4u; return 0; }
target=code_base|0x0c064544u; r[16]=code_base|0x0c0650f8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0650f8u) { target=s->pc; goto dispatch; }
goto P_0c0650f8;
P_0c0650f6: /* original 64d3, guest PC 0x0c0650f6 */
if(!s->budget--) { s->failed_pc=0x0c0650f6u; return 0; }
r[4]=r[13];
goto P_0c0650f8;
P_0c0650f8: /* original 64e2, guest PC 0x0c0650f8 */
if(!s->budget--) { s->failed_pc=0x0c0650f8u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0650fa;
P_0c0650fa: /* original e120, guest PC 0x0c0650fa */
if(!s->budget--) { s->failed_pc=0x0c0650fau; return 0; }
r[1]=0x00000020u;
goto P_0c0650fc;
P_0c0650fc: /* original 6903, guest PC 0x0c0650fc */
if(!s->budget--) { s->failed_pc=0x0c0650fcu; return 0; }
r[9]=r[0];
goto P_0c0650fe;
P_0c0650fe: /* original 6393, guest PC 0x0c0650fe */
if(!s->budget--) { s->failed_pc=0x0c0650feu; return 0; }
r[3]=r[9];
goto P_0c065100;
P_0c065100: /* original c78f, guest PC 0x0c065100 */
if(!s->budget--) { s->failed_pc=0x0c065100u; return 0; }
r[0]=code_base|0x00065340u;
goto P_0c065102;
P_0c065102: /* original 314c, guest PC 0x0c065102 */
if(!s->budget--) { s->failed_pc=0x0c065102u; return 0; }
r[1]+=r[4];
goto P_0c065104;
P_0c065104: /* original ff08, guest PC 0x0c065104 */
if(!s->budget--) { s->failed_pc=0x0c065104u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c065106;
P_0c065106: /* original 7901, guest PC 0x0c065106 */
if(!s->budget--) { s->failed_pc=0x0c065106u; return 0; }
r[9]+=0x00000001u;
goto P_0c065108;
P_0c065108: /* original f318, guest PC 0x0c065108 */
if(!s->budget--) { s->failed_pc=0x0c065108u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06510a;
P_0c06510a: /* original 4308, guest PC 0x0c06510a */
if(!s->budget--) { s->failed_pc=0x0c06510au; return 0; }
r[3]<<=2;
goto P_0c06510c;
P_0c06510c: /* original d08b, guest PC 0x0c06510c */
if(!s->budget--) { s->failed_pc=0x0c06510cu; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06510e;
P_0c06510e: /* original f3f2, guest PC 0x0c06510e */
if(!s->budget--) { s->failed_pc=0x0c06510eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065110;
P_0c065110: /* original f33d, guest PC 0x0c065110 */
if(!s->budget--) { s->failed_pc=0x0c065110u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065112;
P_0c065112: /* original e124, guest PC 0x0c065112 */
if(!s->budget--) { s->failed_pc=0x0c065112u; return 0; }
r[1]=0x00000024u;
goto P_0c065114;
P_0c065114: /* original 025a, guest PC 0x0c065114 */
if(!s->budget--) { s->failed_pc=0x0c065114u; return 0; }
r[2]=r[53];
goto P_0c065116;
P_0c065116: /* original 4228, guest PC 0x0c065116 */
if(!s->budget--) { s->failed_pc=0x0c065116u; return 0; }
r[2]<<=16;
goto P_0c065118;
P_0c065118: /* original 4218, guest PC 0x0c065118 */
if(!s->budget--) { s->failed_pc=0x0c065118u; return 0; }
r[2]<<=8;
goto P_0c06511a;
P_0c06511a: /* original 314c, guest PC 0x0c06511a */
if(!s->budget--) { s->failed_pc=0x0c06511au; return 0; }
r[1]+=r[4];
goto P_0c06511c;
P_0c06511c: /* original f318, guest PC 0x0c06511c */
if(!s->budget--) { s->failed_pc=0x0c06511cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06511e;
P_0c06511e: /* original f3f2, guest PC 0x0c06511e */
if(!s->budget--) { s->failed_pc=0x0c06511eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065120;
P_0c065120: /* original f33d, guest PC 0x0c065120 */
if(!s->budget--) { s->failed_pc=0x0c065120u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065122;
P_0c065122: /* original 015a, guest PC 0x0c065122 */
if(!s->budget--) { s->failed_pc=0x0c065122u; return 0; }
r[1]=r[53];
goto P_0c065124;
P_0c065124: /* original 4128, guest PC 0x0c065124 */
if(!s->budget--) { s->failed_pc=0x0c065124u; return 0; }
r[1]<<=16;
goto P_0c065126;
P_0c065126: /* original 221b, guest PC 0x0c065126 */
if(!s->budget--) { s->failed_pc=0x0c065126u; return 0; }
r[2]|=r[1];
goto P_0c065128;
P_0c065128: /* original e128, guest PC 0x0c065128 */
if(!s->budget--) { s->failed_pc=0x0c065128u; return 0; }
r[1]=0x00000028u;
goto P_0c06512a;
P_0c06512a: /* original 314c, guest PC 0x0c06512a */
if(!s->budget--) { s->failed_pc=0x0c06512au; return 0; }
r[1]+=r[4];
goto P_0c06512c;
P_0c06512c: /* original f318, guest PC 0x0c06512c */
if(!s->budget--) { s->failed_pc=0x0c06512cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06512e;
P_0c06512e: /* original f3f2, guest PC 0x0c06512e */
if(!s->budget--) { s->failed_pc=0x0c06512eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065130;
P_0c065130: /* original f33d, guest PC 0x0c065130 */
if(!s->budget--) { s->failed_pc=0x0c065130u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065132;
P_0c065132: /* original 015a, guest PC 0x0c065132 */
if(!s->budget--) { s->failed_pc=0x0c065132u; return 0; }
r[1]=r[53];
goto P_0c065134;
P_0c065134: /* original 4118, guest PC 0x0c065134 */
if(!s->budget--) { s->failed_pc=0x0c065134u; return 0; }
r[1]<<=8;
goto P_0c065136;
P_0c065136: /* original 221b, guest PC 0x0c065136 */
if(!s->budget--) { s->failed_pc=0x0c065136u; return 0; }
r[2]|=r[1];
goto P_0c065138;
P_0c065138: /* original e12c, guest PC 0x0c065138 */
if(!s->budget--) { s->failed_pc=0x0c065138u; return 0; }
r[1]=0x0000002cu;
goto P_0c06513a;
P_0c06513a: /* original 314c, guest PC 0x0c06513a */
if(!s->budget--) { s->failed_pc=0x0c06513au; return 0; }
r[1]+=r[4];
goto P_0c06513c;
P_0c06513c: /* original f318, guest PC 0x0c06513c */
if(!s->budget--) { s->failed_pc=0x0c06513cu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06513e;
P_0c06513e: /* original f3f2, guest PC 0x0c06513e */
if(!s->budget--) { s->failed_pc=0x0c06513eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065140;
P_0c065140: /* original f33d, guest PC 0x0c065140 */
if(!s->budget--) { s->failed_pc=0x0c065140u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065142;
P_0c065142: /* original 015a, guest PC 0x0c065142 */
if(!s->budget--) { s->failed_pc=0x0c065142u; return 0; }
r[1]=r[53];
goto P_0c065144;
P_0c065144: /* original 221b, guest PC 0x0c065144 */
if(!s->budget--) { s->failed_pc=0x0c065144u; return 0; }
r[2]|=r[1];
goto P_0c065146;
P_0c065146: /* original 0326, guest PC 0x0c065146 */
if(!s->budget--) { s->failed_pc=0x0c065146u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065148;
P_0c065148: /* original 6ce2, guest PC 0x0c065148 */
if(!s->budget--) { s->failed_pc=0x0c065148u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c06514a;
P_0c06514a: /* original e030, guest PC 0x0c06514a */
if(!s->budget--) { s->failed_pc=0x0c06514au; return 0; }
r[0]=0x00000030u;
goto P_0c06514c;
P_0c06514c: /* original f3c6, guest PC 0x0c06514c */
if(!s->budget--) { s->failed_pc=0x0c06514cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06514e;
P_0c06514e: /* original e034, guest PC 0x0c06514e */
if(!s->budget--) { s->failed_pc=0x0c06514eu; return 0; }
r[0]=0x00000034u;
goto P_0c065150;
P_0c065150: /* original f3f2, guest PC 0x0c065150 */
if(!s->budget--) { s->failed_pc=0x0c065150u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065152;
P_0c065152: /* original f33d, guest PC 0x0c065152 */
if(!s->budget--) { s->failed_pc=0x0c065152u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065154;
P_0c065154: /* original f3c6, guest PC 0x0c065154 */
if(!s->budget--) { s->failed_pc=0x0c065154u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065156;
P_0c065156: /* original 065a, guest PC 0x0c065156 */
if(!s->budget--) { s->failed_pc=0x0c065156u; return 0; }
r[6]=r[53];
goto P_0c065158;
P_0c065158: /* original 4628, guest PC 0x0c065158 */
if(!s->budget--) { s->failed_pc=0x0c065158u; return 0; }
r[6]<<=16;
goto P_0c06515a;
P_0c06515a: /* original 4618, guest PC 0x0c06515a */
if(!s->budget--) { s->failed_pc=0x0c06515au; return 0; }
r[6]<<=8;
goto P_0c06515c;
P_0c06515c: /* original f3f2, guest PC 0x0c06515c */
if(!s->budget--) { s->failed_pc=0x0c06515cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06515e;
P_0c06515e: /* original e038, guest PC 0x0c06515e */
if(!s->budget--) { s->failed_pc=0x0c06515eu; return 0; }
r[0]=0x00000038u;
goto P_0c065160;
P_0c065160: /* original f33d, guest PC 0x0c065160 */
if(!s->budget--) { s->failed_pc=0x0c065160u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065162;
P_0c065162: /* original 035a, guest PC 0x0c065162 */
if(!s->budget--) { s->failed_pc=0x0c065162u; return 0; }
r[3]=r[53];
goto P_0c065164;
P_0c065164: /* original f3c6, guest PC 0x0c065164 */
if(!s->budget--) { s->failed_pc=0x0c065164u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065166;
P_0c065166: /* original 4328, guest PC 0x0c065166 */
if(!s->budget--) { s->failed_pc=0x0c065166u; return 0; }
r[3]<<=16;
goto P_0c065168;
P_0c065168: /* original 263b, guest PC 0x0c065168 */
if(!s->budget--) { s->failed_pc=0x0c065168u; return 0; }
r[6]|=r[3];
goto P_0c06516a;
P_0c06516a: /* original f3f2, guest PC 0x0c06516a */
if(!s->budget--) { s->failed_pc=0x0c06516au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06516c;
P_0c06516c: /* original f33d, guest PC 0x0c06516c */
if(!s->budget--) { s->failed_pc=0x0c06516cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06516e;
P_0c06516e: /* original e03c, guest PC 0x0c06516e */
if(!s->budget--) { s->failed_pc=0x0c06516eu; return 0; }
r[0]=0x0000003cu;
goto P_0c065170;
P_0c065170: /* original f3c6, guest PC 0x0c065170 */
if(!s->budget--) { s->failed_pc=0x0c065170u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065172;
P_0c065172: /* original 035a, guest PC 0x0c065172 */
if(!s->budget--) { s->failed_pc=0x0c065172u; return 0; }
r[3]=r[53];
goto P_0c065174;
P_0c065174: /* original 4318, guest PC 0x0c065174 */
if(!s->budget--) { s->failed_pc=0x0c065174u; return 0; }
r[3]<<=8;
goto P_0c065176;
P_0c065176: /* original 263b, guest PC 0x0c065176 */
if(!s->budget--) { s->failed_pc=0x0c065176u; return 0; }
r[6]|=r[3];
goto P_0c065178;
P_0c065178: /* original f3f2, guest PC 0x0c065178 */
if(!s->budget--) { s->failed_pc=0x0c065178u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06517a;
P_0c06517a: /* original 6593, guest PC 0x0c06517a */
if(!s->budget--) { s->failed_pc=0x0c06517au; return 0; }
r[5]=r[9];
goto P_0c06517c;
P_0c06517c: /* original f33d, guest PC 0x0c06517c */
if(!s->budget--) { s->failed_pc=0x0c06517cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06517e;
P_0c06517e: /* original 035a, guest PC 0x0c06517e */
if(!s->budget--) { s->failed_pc=0x0c06517eu; return 0; }
r[3]=r[53];
goto P_0c065180;
P_0c065180: /* original 263b, guest PC 0x0c065180 */
if(!s->budget--) { s->failed_pc=0x0c065180u; return 0; }
r[6]|=r[3];
goto P_0c065182;
P_0c065182: /* original b9d5, guest PC 0x0c065182 */
if(!s->budget--) { s->failed_pc=0x0c065182u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c065186u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065186u) { target=s->pc; goto dispatch; }
goto P_0c065186;
P_0c065184: /* original 64d3, guest PC 0x0c065184 */
if(!s->budget--) { s->failed_pc=0x0c065184u; return 0; }
r[4]=r[13];
goto P_0c065186;
P_0c065186: /* original 6c03, guest PC 0x0c065186 */
if(!s->budget--) { s->failed_pc=0x0c065186u; return 0; }
r[12]=r[0];
goto P_0c065188;
P_0c065188: /* original 61b2, guest PC 0x0c065188 */
if(!s->budget--) { s->failed_pc=0x0c065188u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06518a;
P_0c06518a: /* original 63c3, guest PC 0x0c06518a */
if(!s->budget--) { s->failed_pc=0x0c06518au; return 0; }
r[3]=r[12];
goto P_0c06518c;
P_0c06518c: /* original d06b, guest PC 0x0c06518c */
if(!s->budget--) { s->failed_pc=0x0c06518cu; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06518e;
P_0c06518e: /* original 7c01, guest PC 0x0c06518e */
if(!s->budget--) { s->failed_pc=0x0c06518eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065190;
P_0c065190: /* original 5211, guest PC 0x0c065190 */
if(!s->budget--) { s->failed_pc=0x0c065190u; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c065192;
P_0c065192: /* original 4308, guest PC 0x0c065192 */
if(!s->budget--) { s->failed_pc=0x0c065192u; return 0; }
r[3]<<=2;
goto P_0c065194;
P_0c065194: /* original 0326, guest PC 0x0c065194 */
if(!s->budget--) { s->failed_pc=0x0c065194u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065196;
P_0c065196: /* original 63c3, guest PC 0x0c065196 */
if(!s->budget--) { s->failed_pc=0x0c065196u; return 0; }
r[3]=r[12];
goto P_0c065198;
P_0c065198: /* original 61b2, guest PC 0x0c065198 */
if(!s->budget--) { s->failed_pc=0x0c065198u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c06519a;
P_0c06519a: /* original 7c01, guest PC 0x0c06519a */
if(!s->budget--) { s->failed_pc=0x0c06519au; return 0; }
r[12]+=0x00000001u;
goto P_0c06519c;
P_0c06519c: /* original 5212, guest PC 0x0c06519c */
if(!s->budget--) { s->failed_pc=0x0c06519cu; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c06519e;
P_0c06519e: /* original 4308, guest PC 0x0c06519e */
if(!s->budget--) { s->failed_pc=0x0c06519eu; return 0; }
r[3]<<=2;
goto P_0c0651a0;
P_0c0651a0: /* original 0326, guest PC 0x0c0651a0 */
if(!s->budget--) { s->failed_pc=0x0c0651a0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0651a2;
P_0c0651a2: /* original 63c3, guest PC 0x0c0651a2 */
if(!s->budget--) { s->failed_pc=0x0c0651a2u; return 0; }
r[3]=r[12];
goto P_0c0651a4;
P_0c0651a4: /* original 61b2, guest PC 0x0c0651a4 */
if(!s->budget--) { s->failed_pc=0x0c0651a4u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c0651a6;
P_0c0651a6: /* original 7c01, guest PC 0x0c0651a6 */
if(!s->budget--) { s->failed_pc=0x0c0651a6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0651a8;
P_0c0651a8: /* original 5213, guest PC 0x0c0651a8 */
if(!s->budget--) { s->failed_pc=0x0c0651a8u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c0651aa;
P_0c0651aa: /* original 4308, guest PC 0x0c0651aa */
if(!s->budget--) { s->failed_pc=0x0c0651aau; return 0; }
r[3]<<=2;
goto P_0c0651ac;
P_0c0651ac: /* original 0326, guest PC 0x0c0651ac */
if(!s->budget--) { s->failed_pc=0x0c0651acu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0651ae;
P_0c0651ae: /* original 65c3, guest PC 0x0c0651ae */
if(!s->budget--) { s->failed_pc=0x0c0651aeu; return 0; }
r[5]=r[12];
goto P_0c0651b0;
P_0c0651b0: /* original 66e2, guest PC 0x0c0651b0 */
if(!s->budget--) { s->failed_pc=0x0c0651b0u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c0651b2;
P_0c0651b2: /* original 5664, guest PC 0x0c0651b2 */
if(!s->budget--) { s->failed_pc=0x0c0651b2u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0651b4;
P_0c0651b4: /* original b9c6, guest PC 0x0c0651b4 */
if(!s->budget--) { s->failed_pc=0x0c0651b4u; return 0; }
target=code_base|0x0c064544u; r[16]=code_base|0x0c0651b8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0651b8u) { target=s->pc; goto dispatch; }
goto P_0c0651b8;
P_0c0651b6: /* original 64d3, guest PC 0x0c0651b6 */
if(!s->budget--) { s->failed_pc=0x0c0651b6u; return 0; }
r[4]=r[13];
goto P_0c0651b8;
P_0c0651b8: /* original 64b2, guest PC 0x0c0651b8 */
if(!s->budget--) { s->failed_pc=0x0c0651b8u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0651ba;
P_0c0651ba: /* original e120, guest PC 0x0c0651ba */
if(!s->budget--) { s->failed_pc=0x0c0651bau; return 0; }
r[1]=0x00000020u;
goto P_0c0651bc;
P_0c0651bc: /* original 6903, guest PC 0x0c0651bc */
if(!s->budget--) { s->failed_pc=0x0c0651bcu; return 0; }
r[9]=r[0];
goto P_0c0651be;
P_0c0651be: /* original 6293, guest PC 0x0c0651be */
if(!s->budget--) { s->failed_pc=0x0c0651beu; return 0; }
r[2]=r[9];
goto P_0c0651c0;
P_0c0651c0: /* original d05e, guest PC 0x0c0651c0 */
if(!s->budget--) { s->failed_pc=0x0c0651c0u; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c0651c2;
P_0c0651c2: /* original 314c, guest PC 0x0c0651c2 */
if(!s->budget--) { s->failed_pc=0x0c0651c2u; return 0; }
r[1]+=r[4];
goto P_0c0651c4;
P_0c0651c4: /* original f318, guest PC 0x0c0651c4 */
if(!s->budget--) { s->failed_pc=0x0c0651c4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651c6;
P_0c0651c6: /* original 7901, guest PC 0x0c0651c6 */
if(!s->budget--) { s->failed_pc=0x0c0651c6u; return 0; }
r[9]+=0x00000001u;
goto P_0c0651c8;
P_0c0651c8: /* original 4208, guest PC 0x0c0651c8 */
if(!s->budget--) { s->failed_pc=0x0c0651c8u; return 0; }
r[2]<<=2;
goto P_0c0651ca;
P_0c0651ca: /* original f3f2, guest PC 0x0c0651ca */
if(!s->budget--) { s->failed_pc=0x0c0651cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651cc;
P_0c0651cc: /* original f33d, guest PC 0x0c0651cc */
if(!s->budget--) { s->failed_pc=0x0c0651ccu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651ce;
P_0c0651ce: /* original e124, guest PC 0x0c0651ce */
if(!s->budget--) { s->failed_pc=0x0c0651ceu; return 0; }
r[1]=0x00000024u;
goto P_0c0651d0;
P_0c0651d0: /* original 035a, guest PC 0x0c0651d0 */
if(!s->budget--) { s->failed_pc=0x0c0651d0u; return 0; }
r[3]=r[53];
goto P_0c0651d2;
P_0c0651d2: /* original 4328, guest PC 0x0c0651d2 */
if(!s->budget--) { s->failed_pc=0x0c0651d2u; return 0; }
r[3]<<=16;
goto P_0c0651d4;
P_0c0651d4: /* original 4318, guest PC 0x0c0651d4 */
if(!s->budget--) { s->failed_pc=0x0c0651d4u; return 0; }
r[3]<<=8;
goto P_0c0651d6;
P_0c0651d6: /* original 314c, guest PC 0x0c0651d6 */
if(!s->budget--) { s->failed_pc=0x0c0651d6u; return 0; }
r[1]+=r[4];
goto P_0c0651d8;
P_0c0651d8: /* original f318, guest PC 0x0c0651d8 */
if(!s->budget--) { s->failed_pc=0x0c0651d8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651da;
P_0c0651da: /* original f3f2, guest PC 0x0c0651da */
if(!s->budget--) { s->failed_pc=0x0c0651dau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651dc;
P_0c0651dc: /* original f33d, guest PC 0x0c0651dc */
if(!s->budget--) { s->failed_pc=0x0c0651dcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651de;
P_0c0651de: /* original 015a, guest PC 0x0c0651de */
if(!s->budget--) { s->failed_pc=0x0c0651deu; return 0; }
r[1]=r[53];
goto P_0c0651e0;
P_0c0651e0: /* original 4128, guest PC 0x0c0651e0 */
if(!s->budget--) { s->failed_pc=0x0c0651e0u; return 0; }
r[1]<<=16;
goto P_0c0651e2;
P_0c0651e2: /* original 231b, guest PC 0x0c0651e2 */
if(!s->budget--) { s->failed_pc=0x0c0651e2u; return 0; }
r[3]|=r[1];
goto P_0c0651e4;
P_0c0651e4: /* original e128, guest PC 0x0c0651e4 */
if(!s->budget--) { s->failed_pc=0x0c0651e4u; return 0; }
r[1]=0x00000028u;
goto P_0c0651e6;
P_0c0651e6: /* original 314c, guest PC 0x0c0651e6 */
if(!s->budget--) { s->failed_pc=0x0c0651e6u; return 0; }
r[1]+=r[4];
goto P_0c0651e8;
P_0c0651e8: /* original f318, guest PC 0x0c0651e8 */
if(!s->budget--) { s->failed_pc=0x0c0651e8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651ea;
P_0c0651ea: /* original f3f2, guest PC 0x0c0651ea */
if(!s->budget--) { s->failed_pc=0x0c0651eau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651ec;
P_0c0651ec: /* original f33d, guest PC 0x0c0651ec */
if(!s->budget--) { s->failed_pc=0x0c0651ecu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651ee;
P_0c0651ee: /* original 015a, guest PC 0x0c0651ee */
if(!s->budget--) { s->failed_pc=0x0c0651eeu; return 0; }
r[1]=r[53];
goto P_0c0651f0;
P_0c0651f0: /* original 4118, guest PC 0x0c0651f0 */
if(!s->budget--) { s->failed_pc=0x0c0651f0u; return 0; }
r[1]<<=8;
goto P_0c0651f2;
P_0c0651f2: /* original 231b, guest PC 0x0c0651f2 */
if(!s->budget--) { s->failed_pc=0x0c0651f2u; return 0; }
r[3]|=r[1];
goto P_0c0651f4;
P_0c0651f4: /* original e12c, guest PC 0x0c0651f4 */
if(!s->budget--) { s->failed_pc=0x0c0651f4u; return 0; }
r[1]=0x0000002cu;
goto P_0c0651f6;
P_0c0651f6: /* original 314c, guest PC 0x0c0651f6 */
if(!s->budget--) { s->failed_pc=0x0c0651f6u; return 0; }
r[1]+=r[4];
goto P_0c0651f8;
P_0c0651f8: /* original f318, guest PC 0x0c0651f8 */
if(!s->budget--) { s->failed_pc=0x0c0651f8u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0651fa;
P_0c0651fa: /* original f3f2, guest PC 0x0c0651fa */
if(!s->budget--) { s->failed_pc=0x0c0651fau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0651fc;
P_0c0651fc: /* original f33d, guest PC 0x0c0651fc */
if(!s->budget--) { s->failed_pc=0x0c0651fcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0651fe;
P_0c0651fe: /* original 015a, guest PC 0x0c0651fe */
if(!s->budget--) { s->failed_pc=0x0c0651feu; return 0; }
r[1]=r[53];
goto P_0c065200;
P_0c065200: /* original 231b, guest PC 0x0c065200 */
if(!s->budget--) { s->failed_pc=0x0c065200u; return 0; }
r[3]|=r[1];
goto P_0c065202;
P_0c065202: /* original 0236, guest PC 0x0c065202 */
if(!s->budget--) { s->failed_pc=0x0c065202u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065204;
P_0c065204: /* original 6cb2, guest PC 0x0c065204 */
if(!s->budget--) { s->failed_pc=0x0c065204u; return 0; }
tmp=read(ram,r[11],4);
r[12]=tmp;
goto P_0c065206;
P_0c065206: /* original e030, guest PC 0x0c065206 */
if(!s->budget--) { s->failed_pc=0x0c065206u; return 0; }
r[0]=0x00000030u;
goto P_0c065208;
P_0c065208: /* original f3c6, guest PC 0x0c065208 */
if(!s->budget--) { s->failed_pc=0x0c065208u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06520a;
P_0c06520a: /* original e034, guest PC 0x0c06520a */
if(!s->budget--) { s->failed_pc=0x0c06520au; return 0; }
r[0]=0x00000034u;
goto P_0c06520c;
P_0c06520c: /* original f3f2, guest PC 0x0c06520c */
if(!s->budget--) { s->failed_pc=0x0c06520cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06520e;
P_0c06520e: /* original f33d, guest PC 0x0c06520e */
if(!s->budget--) { s->failed_pc=0x0c06520eu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065210;
P_0c065210: /* original f3c6, guest PC 0x0c065210 */
if(!s->budget--) { s->failed_pc=0x0c065210u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065212;
P_0c065212: /* original 065a, guest PC 0x0c065212 */
if(!s->budget--) { s->failed_pc=0x0c065212u; return 0; }
r[6]=r[53];
goto P_0c065214;
P_0c065214: /* original 4628, guest PC 0x0c065214 */
if(!s->budget--) { s->failed_pc=0x0c065214u; return 0; }
r[6]<<=16;
goto P_0c065216;
P_0c065216: /* original 4618, guest PC 0x0c065216 */
if(!s->budget--) { s->failed_pc=0x0c065216u; return 0; }
r[6]<<=8;
goto P_0c065218;
P_0c065218: /* original f3f2, guest PC 0x0c065218 */
if(!s->budget--) { s->failed_pc=0x0c065218u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06521a;
P_0c06521a: /* original e038, guest PC 0x0c06521a */
if(!s->budget--) { s->failed_pc=0x0c06521au; return 0; }
r[0]=0x00000038u;
goto P_0c06521c;
P_0c06521c: /* original f33d, guest PC 0x0c06521c */
if(!s->budget--) { s->failed_pc=0x0c06521cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06521e;
P_0c06521e: /* original 035a, guest PC 0x0c06521e */
if(!s->budget--) { s->failed_pc=0x0c06521eu; return 0; }
r[3]=r[53];
goto P_0c065220;
P_0c065220: /* original f3c6, guest PC 0x0c065220 */
if(!s->budget--) { s->failed_pc=0x0c065220u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c065222;
P_0c065222: /* original 4328, guest PC 0x0c065222 */
if(!s->budget--) { s->failed_pc=0x0c065222u; return 0; }
r[3]<<=16;
goto P_0c065224;
P_0c065224: /* original 263b, guest PC 0x0c065224 */
if(!s->budget--) { s->failed_pc=0x0c065224u; return 0; }
r[6]|=r[3];
goto P_0c065226;
P_0c065226: /* original f3f2, guest PC 0x0c065226 */
if(!s->budget--) { s->failed_pc=0x0c065226u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065228;
P_0c065228: /* original f33d, guest PC 0x0c065228 */
if(!s->budget--) { s->failed_pc=0x0c065228u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06522a;
P_0c06522a: /* original e03c, guest PC 0x0c06522a */
if(!s->budget--) { s->failed_pc=0x0c06522au; return 0; }
r[0]=0x0000003cu;
goto P_0c06522c;
P_0c06522c: /* original f3c6, guest PC 0x0c06522c */
if(!s->budget--) { s->failed_pc=0x0c06522cu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06522e;
P_0c06522e: /* original 035a, guest PC 0x0c06522e */
if(!s->budget--) { s->failed_pc=0x0c06522eu; return 0; }
r[3]=r[53];
goto P_0c065230;
P_0c065230: /* original 4318, guest PC 0x0c065230 */
if(!s->budget--) { s->failed_pc=0x0c065230u; return 0; }
r[3]<<=8;
goto P_0c065232;
P_0c065232: /* original 263b, guest PC 0x0c065232 */
if(!s->budget--) { s->failed_pc=0x0c065232u; return 0; }
r[6]|=r[3];
goto P_0c065234;
P_0c065234: /* original f3f2, guest PC 0x0c065234 */
if(!s->budget--) { s->failed_pc=0x0c065234u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065236;
P_0c065236: /* original f33d, guest PC 0x0c065236 */
if(!s->budget--) { s->failed_pc=0x0c065236u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c065238;
P_0c065238: /* original 035a, guest PC 0x0c065238 */
if(!s->budget--) { s->failed_pc=0x0c065238u; return 0; }
r[3]=r[53];
goto P_0c06523a;
P_0c06523a: /* original 263b, guest PC 0x0c06523a */
if(!s->budget--) { s->failed_pc=0x0c06523au; return 0; }
r[6]|=r[3];
goto P_0c06523c;
P_0c06523c: /* original 6593, guest PC 0x0c06523c */
if(!s->budget--) { s->failed_pc=0x0c06523cu; return 0; }
r[5]=r[9];
goto P_0c06523e;
P_0c06523e: /* original b977, guest PC 0x0c06523e */
if(!s->budget--) { s->failed_pc=0x0c06523eu; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c065242u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065242u) { target=s->pc; goto dispatch; }
goto P_0c065242;
P_0c065240: /* original 64d3, guest PC 0x0c065240 */
if(!s->budget--) { s->failed_pc=0x0c065240u; return 0; }
r[4]=r[13];
goto P_0c065242;
P_0c065242: /* original 6c03, guest PC 0x0c065242 */
if(!s->budget--) { s->failed_pc=0x0c065242u; return 0; }
r[12]=r[0];
goto P_0c065244;
P_0c065244: /* original 61a2, guest PC 0x0c065244 */
if(!s->budget--) { s->failed_pc=0x0c065244u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065246;
P_0c065246: /* original 63c3, guest PC 0x0c065246 */
if(!s->budget--) { s->failed_pc=0x0c065246u; return 0; }
r[3]=r[12];
goto P_0c065248;
P_0c065248: /* original d03c, guest PC 0x0c065248 */
if(!s->budget--) { s->failed_pc=0x0c065248u; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06524a;
P_0c06524a: /* original 7c01, guest PC 0x0c06524a */
if(!s->budget--) { s->failed_pc=0x0c06524au; return 0; }
r[12]+=0x00000001u;
goto P_0c06524c;
P_0c06524c: /* original 5211, guest PC 0x0c06524c */
if(!s->budget--) { s->failed_pc=0x0c06524cu; return 0; }
r[2]=read(ram,r[1]+4,4);
goto P_0c06524e;
P_0c06524e: /* original 4308, guest PC 0x0c06524e */
if(!s->budget--) { s->failed_pc=0x0c06524eu; return 0; }
r[3]<<=2;
goto P_0c065250;
P_0c065250: /* original 0326, guest PC 0x0c065250 */
if(!s->budget--) { s->failed_pc=0x0c065250u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065252;
P_0c065252: /* original 63c3, guest PC 0x0c065252 */
if(!s->budget--) { s->failed_pc=0x0c065252u; return 0; }
r[3]=r[12];
goto P_0c065254;
P_0c065254: /* original 61a2, guest PC 0x0c065254 */
if(!s->budget--) { s->failed_pc=0x0c065254u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065256;
P_0c065256: /* original 7c01, guest PC 0x0c065256 */
if(!s->budget--) { s->failed_pc=0x0c065256u; return 0; }
r[12]+=0x00000001u;
goto P_0c065258;
P_0c065258: /* original 5212, guest PC 0x0c065258 */
if(!s->budget--) { s->failed_pc=0x0c065258u; return 0; }
r[2]=read(ram,r[1]+8,4);
goto P_0c06525a;
P_0c06525a: /* original 4308, guest PC 0x0c06525a */
if(!s->budget--) { s->failed_pc=0x0c06525au; return 0; }
r[3]<<=2;
goto P_0c06525c;
P_0c06525c: /* original 0326, guest PC 0x0c06525c */
if(!s->budget--) { s->failed_pc=0x0c06525cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06525e;
P_0c06525e: /* original 63c3, guest PC 0x0c06525e */
if(!s->budget--) { s->failed_pc=0x0c06525eu; return 0; }
r[3]=r[12];
goto P_0c065260;
P_0c065260: /* original 61a2, guest PC 0x0c065260 */
if(!s->budget--) { s->failed_pc=0x0c065260u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065262;
P_0c065262: /* original 7c01, guest PC 0x0c065262 */
if(!s->budget--) { s->failed_pc=0x0c065262u; return 0; }
r[12]+=0x00000001u;
goto P_0c065264;
P_0c065264: /* original 5213, guest PC 0x0c065264 */
if(!s->budget--) { s->failed_pc=0x0c065264u; return 0; }
r[2]=read(ram,r[1]+12,4);
goto P_0c065266;
P_0c065266: /* original 4308, guest PC 0x0c065266 */
if(!s->budget--) { s->failed_pc=0x0c065266u; return 0; }
r[3]<<=2;
goto P_0c065268;
P_0c065268: /* original 0326, guest PC 0x0c065268 */
if(!s->budget--) { s->failed_pc=0x0c065268u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06526a;
P_0c06526a: /* original 65c3, guest PC 0x0c06526a */
if(!s->budget--) { s->failed_pc=0x0c06526au; return 0; }
r[5]=r[12];
goto P_0c06526c;
P_0c06526c: /* original 66e2, guest PC 0x0c06526c */
if(!s->budget--) { s->failed_pc=0x0c06526cu; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c06526e;
P_0c06526e: /* original 5664, guest PC 0x0c06526e */
if(!s->budget--) { s->failed_pc=0x0c06526eu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065270;
P_0c065270: /* original b968, guest PC 0x0c065270 */
if(!s->budget--) { s->failed_pc=0x0c065270u; return 0; }
target=code_base|0x0c064544u; r[16]=code_base|0x0c065274u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065274u) { target=s->pc; goto dispatch; }
goto P_0c065274;
P_0c065272: /* original 64d3, guest PC 0x0c065272 */
if(!s->budget--) { s->failed_pc=0x0c065272u; return 0; }
r[4]=r[13];
goto P_0c065274;
P_0c065274: /* original 64a2, guest PC 0x0c065274 */
if(!s->budget--) { s->failed_pc=0x0c065274u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c065276;
P_0c065276: /* original e120, guest PC 0x0c065276 */
if(!s->budget--) { s->failed_pc=0x0c065276u; return 0; }
r[1]=0x00000020u;
goto P_0c065278;
P_0c065278: /* original 6c03, guest PC 0x0c065278 */
if(!s->budget--) { s->failed_pc=0x0c065278u; return 0; }
r[12]=r[0];
goto P_0c06527a;
P_0c06527a: /* original 62c3, guest PC 0x0c06527a */
if(!s->budget--) { s->failed_pc=0x0c06527au; return 0; }
r[2]=r[12];
goto P_0c06527c;
P_0c06527c: /* original d02f, guest PC 0x0c06527c */
if(!s->budget--) { s->failed_pc=0x0c06527cu; return 0; }
r[0]=read(ram,0x0c06533cu,4);
goto P_0c06527e;
P_0c06527e: /* original 314c, guest PC 0x0c06527e */
if(!s->budget--) { s->failed_pc=0x0c06527eu; return 0; }
r[1]+=r[4];
goto P_0c065280;
P_0c065280: /* original f318, guest PC 0x0c065280 */
if(!s->budget--) { s->failed_pc=0x0c065280u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065282;
P_0c065282: /* original 7c01, guest PC 0x0c065282 */
if(!s->budget--) { s->failed_pc=0x0c065282u; return 0; }
r[12]+=0x00000001u;
goto P_0c065284;
P_0c065284: /* original 4208, guest PC 0x0c065284 */
if(!s->budget--) { s->failed_pc=0x0c065284u; return 0; }
r[2]<<=2;
goto P_0c065286;
P_0c065286: /* original f3f2, guest PC 0x0c065286 */
if(!s->budget--) { s->failed_pc=0x0c065286u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065288;
P_0c065288: /* original f33d, guest PC 0x0c065288 */
if(!s->budget--) { s->failed_pc=0x0c065288u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06528a;
P_0c06528a: /* original e124, guest PC 0x0c06528a */
if(!s->budget--) { s->failed_pc=0x0c06528au; return 0; }
r[1]=0x00000024u;
goto P_0c06528c;
P_0c06528c: /* original 035a, guest PC 0x0c06528c */
if(!s->budget--) { s->failed_pc=0x0c06528cu; return 0; }
r[3]=r[53];
goto P_0c06528e;
P_0c06528e: /* original 4328, guest PC 0x0c06528e */
if(!s->budget--) { s->failed_pc=0x0c06528eu; return 0; }
r[3]<<=16;
goto P_0c065290;
P_0c065290: /* original 4318, guest PC 0x0c065290 */
if(!s->budget--) { s->failed_pc=0x0c065290u; return 0; }
r[3]<<=8;
goto P_0c065292;
P_0c065292: /* original 314c, guest PC 0x0c065292 */
if(!s->budget--) { s->failed_pc=0x0c065292u; return 0; }
r[1]+=r[4];
goto P_0c065294;
P_0c065294: /* original f318, guest PC 0x0c065294 */
if(!s->budget--) { s->failed_pc=0x0c065294u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c065296;
P_0c065296: /* original f3f2, guest PC 0x0c065296 */
if(!s->budget--) { s->failed_pc=0x0c065296u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c065298;
P_0c065298: /* original f33d, guest PC 0x0c065298 */
if(!s->budget--) { s->failed_pc=0x0c065298u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06529a;
P_0c06529a: /* original 015a, guest PC 0x0c06529a */
if(!s->budget--) { s->failed_pc=0x0c06529au; return 0; }
r[1]=r[53];
goto P_0c06529c;
P_0c06529c: /* original 4128, guest PC 0x0c06529c */
if(!s->budget--) { s->failed_pc=0x0c06529cu; return 0; }
r[1]<<=16;
goto P_0c06529e;
P_0c06529e: /* original 231b, guest PC 0x0c06529e */
if(!s->budget--) { s->failed_pc=0x0c06529eu; return 0; }
r[3]|=r[1];
goto P_0c0652a0;
P_0c0652a0: /* original e128, guest PC 0x0c0652a0 */
if(!s->budget--) { s->failed_pc=0x0c0652a0u; return 0; }
r[1]=0x00000028u;
goto P_0c0652a2;
P_0c0652a2: /* original 314c, guest PC 0x0c0652a2 */
if(!s->budget--) { s->failed_pc=0x0c0652a2u; return 0; }
r[1]+=r[4];
goto P_0c0652a4;
P_0c0652a4: /* original f318, guest PC 0x0c0652a4 */
if(!s->budget--) { s->failed_pc=0x0c0652a4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0652a6;
P_0c0652a6: /* original f3f2, guest PC 0x0c0652a6 */
if(!s->budget--) { s->failed_pc=0x0c0652a6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652a8;
P_0c0652a8: /* original f33d, guest PC 0x0c0652a8 */
if(!s->budget--) { s->failed_pc=0x0c0652a8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652aa;
P_0c0652aa: /* original 015a, guest PC 0x0c0652aa */
if(!s->budget--) { s->failed_pc=0x0c0652aau; return 0; }
r[1]=r[53];
goto P_0c0652ac;
P_0c0652ac: /* original 4118, guest PC 0x0c0652ac */
if(!s->budget--) { s->failed_pc=0x0c0652acu; return 0; }
r[1]<<=8;
goto P_0c0652ae;
P_0c0652ae: /* original 231b, guest PC 0x0c0652ae */
if(!s->budget--) { s->failed_pc=0x0c0652aeu; return 0; }
r[3]|=r[1];
goto P_0c0652b0;
P_0c0652b0: /* original e12c, guest PC 0x0c0652b0 */
if(!s->budget--) { s->failed_pc=0x0c0652b0u; return 0; }
r[1]=0x0000002cu;
goto P_0c0652b2;
P_0c0652b2: /* original 314c, guest PC 0x0c0652b2 */
if(!s->budget--) { s->failed_pc=0x0c0652b2u; return 0; }
r[1]+=r[4];
goto P_0c0652b4;
P_0c0652b4: /* original f318, guest PC 0x0c0652b4 */
if(!s->budget--) { s->failed_pc=0x0c0652b4u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0652b6;
P_0c0652b6: /* original f3f2, guest PC 0x0c0652b6 */
if(!s->budget--) { s->failed_pc=0x0c0652b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652b8;
P_0c0652b8: /* original f33d, guest PC 0x0c0652b8 */
if(!s->budget--) { s->failed_pc=0x0c0652b8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652ba;
P_0c0652ba: /* original 015a, guest PC 0x0c0652ba */
if(!s->budget--) { s->failed_pc=0x0c0652bau; return 0; }
r[1]=r[53];
goto P_0c0652bc;
P_0c0652bc: /* original 231b, guest PC 0x0c0652bc */
if(!s->budget--) { s->failed_pc=0x0c0652bcu; return 0; }
r[3]|=r[1];
goto P_0c0652be;
P_0c0652be: /* original 0236, guest PC 0x0c0652be */
if(!s->budget--) { s->failed_pc=0x0c0652beu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0652c0;
P_0c0652c0: /* original 6ba2, guest PC 0x0c0652c0 */
if(!s->budget--) { s->failed_pc=0x0c0652c0u; return 0; }
tmp=read(ram,r[10],4);
r[11]=tmp;
goto P_0c0652c2;
P_0c0652c2: /* original e030, guest PC 0x0c0652c2 */
if(!s->budget--) { s->failed_pc=0x0c0652c2u; return 0; }
r[0]=0x00000030u;
goto P_0c0652c4;
P_0c0652c4: /* original f3b6, guest PC 0x0c0652c4 */
if(!s->budget--) { s->failed_pc=0x0c0652c4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652c6;
P_0c0652c6: /* original e034, guest PC 0x0c0652c6 */
if(!s->budget--) { s->failed_pc=0x0c0652c6u; return 0; }
r[0]=0x00000034u;
goto P_0c0652c8;
P_0c0652c8: /* original f3f2, guest PC 0x0c0652c8 */
if(!s->budget--) { s->failed_pc=0x0c0652c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652ca;
P_0c0652ca: /* original f33d, guest PC 0x0c0652ca */
if(!s->budget--) { s->failed_pc=0x0c0652cau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652cc;
P_0c0652cc: /* original f3b6, guest PC 0x0c0652cc */
if(!s->budget--) { s->failed_pc=0x0c0652ccu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652ce;
P_0c0652ce: /* original 065a, guest PC 0x0c0652ce */
if(!s->budget--) { s->failed_pc=0x0c0652ceu; return 0; }
r[6]=r[53];
goto P_0c0652d0;
P_0c0652d0: /* original 4628, guest PC 0x0c0652d0 */
if(!s->budget--) { s->failed_pc=0x0c0652d0u; return 0; }
r[6]<<=16;
goto P_0c0652d2;
P_0c0652d2: /* original 4618, guest PC 0x0c0652d2 */
if(!s->budget--) { s->failed_pc=0x0c0652d2u; return 0; }
r[6]<<=8;
goto P_0c0652d4;
P_0c0652d4: /* original f3f2, guest PC 0x0c0652d4 */
if(!s->budget--) { s->failed_pc=0x0c0652d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652d6;
P_0c0652d6: /* original e038, guest PC 0x0c0652d6 */
if(!s->budget--) { s->failed_pc=0x0c0652d6u; return 0; }
r[0]=0x00000038u;
goto P_0c0652d8;
P_0c0652d8: /* original f33d, guest PC 0x0c0652d8 */
if(!s->budget--) { s->failed_pc=0x0c0652d8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652da;
P_0c0652da: /* original 035a, guest PC 0x0c0652da */
if(!s->budget--) { s->failed_pc=0x0c0652dau; return 0; }
r[3]=r[53];
goto P_0c0652dc;
P_0c0652dc: /* original f3b6, guest PC 0x0c0652dc */
if(!s->budget--) { s->failed_pc=0x0c0652dcu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652de;
P_0c0652de: /* original 4328, guest PC 0x0c0652de */
if(!s->budget--) { s->failed_pc=0x0c0652deu; return 0; }
r[3]<<=16;
goto P_0c0652e0;
P_0c0652e0: /* original 263b, guest PC 0x0c0652e0 */
if(!s->budget--) { s->failed_pc=0x0c0652e0u; return 0; }
r[6]|=r[3];
goto P_0c0652e2;
P_0c0652e2: /* original f3f2, guest PC 0x0c0652e2 */
if(!s->budget--) { s->failed_pc=0x0c0652e2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652e4;
P_0c0652e4: /* original f33d, guest PC 0x0c0652e4 */
if(!s->budget--) { s->failed_pc=0x0c0652e4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652e6;
P_0c0652e6: /* original e03c, guest PC 0x0c0652e6 */
if(!s->budget--) { s->failed_pc=0x0c0652e6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0652e8;
P_0c0652e8: /* original f3b6, guest PC 0x0c0652e8 */
if(!s->budget--) { s->failed_pc=0x0c0652e8u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0652ea;
P_0c0652ea: /* original 035a, guest PC 0x0c0652ea */
if(!s->budget--) { s->failed_pc=0x0c0652eau; return 0; }
r[3]=r[53];
goto P_0c0652ec;
P_0c0652ec: /* original 4318, guest PC 0x0c0652ec */
if(!s->budget--) { s->failed_pc=0x0c0652ecu; return 0; }
r[3]<<=8;
goto P_0c0652ee;
P_0c0652ee: /* original 263b, guest PC 0x0c0652ee */
if(!s->budget--) { s->failed_pc=0x0c0652eeu; return 0; }
r[6]|=r[3];
goto P_0c0652f0;
P_0c0652f0: /* original f3f2, guest PC 0x0c0652f0 */
if(!s->budget--) { s->failed_pc=0x0c0652f0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0652f2;
P_0c0652f2: /* original f33d, guest PC 0x0c0652f2 */
if(!s->budget--) { s->failed_pc=0x0c0652f2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0652f4;
P_0c0652f4: /* original 035a, guest PC 0x0c0652f4 */
if(!s->budget--) { s->failed_pc=0x0c0652f4u; return 0; }
r[3]=r[53];
goto P_0c0652f6;
P_0c0652f6: /* original 263b, guest PC 0x0c0652f6 */
if(!s->budget--) { s->failed_pc=0x0c0652f6u; return 0; }
r[6]|=r[3];
goto P_0c0652f8;
P_0c0652f8: /* original 65c3, guest PC 0x0c0652f8 */
if(!s->budget--) { s->failed_pc=0x0c0652f8u; return 0; }
r[5]=r[12];
goto P_0c0652fa;
P_0c0652fa: /* original b919, guest PC 0x0c0652fa */
if(!s->budget--) { s->failed_pc=0x0c0652fau; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c0652feu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0652feu) { target=s->pc; goto dispatch; }
goto P_0c0652fe;
P_0c0652fc: /* original 64d3, guest PC 0x0c0652fc */
if(!s->budget--) { s->failed_pc=0x0c0652fcu; return 0; }
r[4]=r[13];
goto P_0c0652fe;
P_0c0652fe: /* original 6403, guest PC 0x0c0652fe */
if(!s->budget--) { s->failed_pc=0x0c0652feu; return 0; }
r[4]=r[0];
goto P_0c065300;
P_0c065300: /* original d310, guest PC 0x0c065300 */
if(!s->budget--) { s->failed_pc=0x0c065300u; return 0; }
r[3]=read(ram,0x0c065344u,4);
goto P_0c065302;
P_0c065302: /* original 4408, guest PC 0x0c065302 */
if(!s->budget--) { s->failed_pc=0x0c065302u; return 0; }
r[4]<<=2;
goto P_0c065304;
P_0c065304: /* original 2342, guest PC 0x0c065304 */
if(!s->budget--) { s->failed_pc=0x0c065304u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c065306;
P_0c065306: /* original b904, guest PC 0x0c065306 */
if(!s->budget--) { s->failed_pc=0x0c065306u; return 0; }
target=code_base|0x0c064512u; r[16]=code_base|0x0c06530au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06530au) { target=s->pc; goto dispatch; }
goto P_0c06530a;
P_0c065308: /* original 64d3, guest PC 0x0c065308 */
if(!s->budget--) { s->failed_pc=0x0c065308u; return 0; }
r[4]=r[13];
goto P_0c06530a;
P_0c06530a: /* original 6403, guest PC 0x0c06530a */
if(!s->budget--) { s->failed_pc=0x0c06530au; return 0; }
r[4]=r[0];
goto P_0c06530c;
P_0c06530c: /* original e500, guest PC 0x0c06530c */
if(!s->budget--) { s->failed_pc=0x0c06530cu; return 0; }
r[5]=0x00000000u;
goto P_0c06530e;
P_0c06530e: /* original b8eb, guest PC 0x0c06530e */
if(!s->budget--) { s->failed_pc=0x0c06530eu; return 0; }
target=code_base|0x0c0644e8u; r[16]=code_base|0x0c065312u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065312u) { target=s->pc; goto dispatch; }
goto P_0c065312;
P_0c065310: /* original 6653, guest PC 0x0c065310 */
if(!s->budget--) { s->failed_pc=0x0c065310u; return 0; }
r[6]=r[5];
goto P_0c065312;
P_0c065312: /* original 63e2, guest PC 0x0c065312 */
if(!s->budget--) { s->failed_pc=0x0c065312u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c065314;
P_0c065314: /* original d10c, guest PC 0x0c065314 */
if(!s->budget--) { s->failed_pc=0x0c065314u; return 0; }
r[1]=read(ram,0x0c065348u,4);
goto P_0c065316;
P_0c065316: /* original 5233, guest PC 0x0c065316 */
if(!s->budget--) { s->failed_pc=0x0c065316u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c065318;
P_0c065318: /* original 2122, guest PC 0x0c065318 */
if(!s->budget--) { s->failed_pc=0x0c065318u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c06531a;
P_0c06531a: /* original e000, guest PC 0x0c06531a */
if(!s->budget--) { s->failed_pc=0x0c06531au; return 0; }
r[0]=0x00000000u;
goto P_0c06531c;
P_0c06531c: /* original 7f0c, guest PC 0x0c06531c */
if(!s->budget--) { s->failed_pc=0x0c06531cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c06531e;
P_0c06531e: /* original 4f26, guest PC 0x0c06531e */
if(!s->budget--) { s->failed_pc=0x0c06531eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065320;
P_0c065320: /* original fff9, guest PC 0x0c065320 */
if(!s->budget--) { s->failed_pc=0x0c065320u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c065322;
P_0c065322: /* original 69f6, guest PC 0x0c065322 */
if(!s->budget--) { s->failed_pc=0x0c065322u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c065324;
P_0c065324: /* original 6af6, guest PC 0x0c065324 */
if(!s->budget--) { s->failed_pc=0x0c065324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065326;
P_0c065326: /* original 6bf6, guest PC 0x0c065326 */
if(!s->budget--) { s->failed_pc=0x0c065326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065328;
P_0c065328: /* original 6cf6, guest PC 0x0c065328 */
if(!s->budget--) { s->failed_pc=0x0c065328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06532a;
P_0c06532a: /* original 6df6, guest PC 0x0c06532a */
if(!s->budget--) { s->failed_pc=0x0c06532au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06532c;
P_0c06532c: /* original 000b, guest PC 0x0c06532c */
if(!s->budget--) { s->failed_pc=0x0c06532cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06532e: /* original 6ef6, guest PC 0x0c06532e */
if(!s->budget--) { s->failed_pc=0x0c06532eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c065330u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c065330u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
