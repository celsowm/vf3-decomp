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
int vf3_away_batch6_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05305cu: goto P_0c05305c;
case 0x0c05305eu: goto P_0c05305e;
case 0x0c053060u: goto P_0c053060;
case 0x0c053062u: goto P_0c053062;
case 0x0c053064u: goto P_0c053064;
case 0x0c053066u: goto P_0c053066;
case 0x0c053068u: goto P_0c053068;
case 0x0c05306au: goto P_0c05306a;
case 0x0c05306cu: goto P_0c05306c;
case 0x0c05306eu: goto P_0c05306e;
case 0x0c053070u: goto P_0c053070;
case 0x0c053072u: goto P_0c053072;
case 0x0c053074u: goto P_0c053074;
case 0x0c053076u: goto P_0c053076;
case 0x0c053078u: goto P_0c053078;
case 0x0c05307au: goto P_0c05307a;
case 0x0c05307cu: goto P_0c05307c;
case 0x0c05307eu: goto P_0c05307e;
case 0x0c053080u: goto P_0c053080;
case 0x0c053082u: goto P_0c053082;
case 0x0c053084u: goto P_0c053084;
case 0x0c053086u: goto P_0c053086;
case 0x0c053088u: goto P_0c053088;
case 0x0c05308au: goto P_0c05308a;
case 0x0c05308cu: goto P_0c05308c;
case 0x0c05308eu: goto P_0c05308e;
case 0x0c053090u: goto P_0c053090;
case 0x0c053092u: goto P_0c053092;
case 0x0c053094u: goto P_0c053094;
case 0x0c053096u: goto P_0c053096;
case 0x0c053098u: goto P_0c053098;
case 0x0c05309au: goto P_0c05309a;
case 0x0c05309cu: goto P_0c05309c;
case 0x0c05309eu: goto P_0c05309e;
case 0x0c0530a0u: goto P_0c0530a0;
case 0x0c0530a2u: goto P_0c0530a2;
case 0x0c0530a4u: goto P_0c0530a4;
case 0x0c0530a6u: goto P_0c0530a6;
case 0x0c0530a8u: goto P_0c0530a8;
case 0x0c0530aau: goto P_0c0530aa;
case 0x0c0530acu: goto P_0c0530ac;
case 0x0c0530aeu: goto P_0c0530ae;
case 0x0c0530b0u: goto P_0c0530b0;
case 0x0c0530b2u: goto P_0c0530b2;
case 0x0c0530b4u: goto P_0c0530b4;
case 0x0c0530b6u: goto P_0c0530b6;
case 0x0c0530b8u: goto P_0c0530b8;
case 0x0c0530bau: goto P_0c0530ba;
case 0x0c0530bcu: goto P_0c0530bc;
case 0x0c0530beu: goto P_0c0530be;
case 0x0c0530c0u: goto P_0c0530c0;
case 0x0c0530c2u: goto P_0c0530c2;
case 0x0c0530c4u: goto P_0c0530c4;
case 0x0c0530c6u: goto P_0c0530c6;
case 0x0c0530c8u: goto P_0c0530c8;
case 0x0c0530cau: goto P_0c0530ca;
case 0x0c0530ccu: goto P_0c0530cc;
case 0x0c0530ceu: goto P_0c0530ce;
case 0x0c0530d0u: goto P_0c0530d0;
case 0x0c0530d2u: goto P_0c0530d2;
case 0x0c0530d4u: goto P_0c0530d4;
case 0x0c0530d6u: goto P_0c0530d6;
case 0x0c0530d8u: goto P_0c0530d8;
case 0x0c0530dau: goto P_0c0530da;
case 0x0c0530dcu: goto P_0c0530dc;
case 0x0c0530deu: goto P_0c0530de;
case 0x0c0530e0u: goto P_0c0530e0;
case 0x0c0530e2u: goto P_0c0530e2;
case 0x0c0530e4u: goto P_0c0530e4;
case 0x0c0530e6u: goto P_0c0530e6;
case 0x0c0530e8u: goto P_0c0530e8;
case 0x0c0530eau: goto P_0c0530ea;
case 0x0c0530ecu: goto P_0c0530ec;
case 0x0c0530eeu: goto P_0c0530ee;
case 0x0c0530f0u: goto P_0c0530f0;
case 0x0c0530f2u: goto P_0c0530f2;
case 0x0c0530f4u: goto P_0c0530f4;
case 0x0c0530f6u: goto P_0c0530f6;
case 0x0c0530f8u: goto P_0c0530f8;
case 0x0c0530fau: goto P_0c0530fa;
case 0x0c0530fcu: goto P_0c0530fc;
case 0x0c0530feu: goto P_0c0530fe;
case 0x0c053100u: goto P_0c053100;
case 0x0c053102u: goto P_0c053102;
case 0x0c053104u: goto P_0c053104;
case 0x0c053106u: goto P_0c053106;
case 0x0c053108u: goto P_0c053108;
case 0x0c05310au: goto P_0c05310a;
case 0x0c05310cu: goto P_0c05310c;
case 0x0c05310eu: goto P_0c05310e;
case 0x0c053110u: goto P_0c053110;
case 0x0c053112u: goto P_0c053112;
case 0x0c053114u: goto P_0c053114;
case 0x0c053116u: goto P_0c053116;
case 0x0c053118u: goto P_0c053118;
case 0x0c05311au: goto P_0c05311a;
case 0x0c05311cu: goto P_0c05311c;
case 0x0c05311eu: goto P_0c05311e;
case 0x0c053120u: goto P_0c053120;
case 0x0c053122u: goto P_0c053122;
case 0x0c053124u: goto P_0c053124;
case 0x0c053126u: goto P_0c053126;
case 0x0c053128u: goto P_0c053128;
case 0x0c05312au: goto P_0c05312a;
case 0x0c05312cu: goto P_0c05312c;
case 0x0c05312eu: goto P_0c05312e;
case 0x0c053130u: goto P_0c053130;
case 0x0c053132u: goto P_0c053132;
case 0x0c053134u: goto P_0c053134;
case 0x0c053136u: goto P_0c053136;
case 0x0c053138u: goto P_0c053138;
case 0x0c05313au: goto P_0c05313a;
case 0x0c05313cu: goto P_0c05313c;
case 0x0c05313eu: goto P_0c05313e;
case 0x0c053140u: goto P_0c053140;
case 0x0c053142u: goto P_0c053142;
case 0x0c053144u: goto P_0c053144;
case 0x0c053146u: goto P_0c053146;
case 0x0c053148u: goto P_0c053148;
case 0x0c05314au: goto P_0c05314a;
case 0x0c05314cu: goto P_0c05314c;
case 0x0c05314eu: goto P_0c05314e;
case 0x0c053150u: goto P_0c053150;
case 0x0c053152u: goto P_0c053152;
case 0x0c053154u: goto P_0c053154;
case 0x0c053156u: goto P_0c053156;
case 0x0c053158u: goto P_0c053158;
case 0x0c05315au: goto P_0c05315a;
case 0x0c05315cu: goto P_0c05315c;
case 0x0c05315eu: goto P_0c05315e;
case 0x0c053160u: goto P_0c053160;
case 0x0c053174u: goto P_0c053174;
case 0x0c053176u: goto P_0c053176;
case 0x0c053178u: goto P_0c053178;
case 0x0c05317au: goto P_0c05317a;
case 0x0c05317cu: goto P_0c05317c;
case 0x0c05317eu: goto P_0c05317e;
case 0x0c053180u: goto P_0c053180;
case 0x0c053182u: goto P_0c053182;
case 0x0c053184u: goto P_0c053184;
case 0x0c053186u: goto P_0c053186;
case 0x0c053188u: goto P_0c053188;
case 0x0c05318au: goto P_0c05318a;
case 0x0c05318cu: goto P_0c05318c;
case 0x0c05318eu: goto P_0c05318e;
case 0x0c053190u: goto P_0c053190;
case 0x0c053192u: goto P_0c053192;
case 0x0c053194u: goto P_0c053194;
case 0x0c053196u: goto P_0c053196;
case 0x0c053198u: goto P_0c053198;
case 0x0c05319au: goto P_0c05319a;
case 0x0c05319cu: goto P_0c05319c;
case 0x0c05319eu: goto P_0c05319e;
case 0x0c0531a0u: goto P_0c0531a0;
case 0x0c0531a2u: goto P_0c0531a2;
case 0x0c0531a4u: goto P_0c0531a4;
case 0x0c0531a6u: goto P_0c0531a6;
case 0x0c0531a8u: goto P_0c0531a8;
case 0x0c0531aau: goto P_0c0531aa;
case 0x0c0531acu: goto P_0c0531ac;
case 0x0c0531aeu: goto P_0c0531ae;
case 0x0c0531b0u: goto P_0c0531b0;
case 0x0c0531b2u: goto P_0c0531b2;
case 0x0c0531b4u: goto P_0c0531b4;
case 0x0c0531b6u: goto P_0c0531b6;
case 0x0c0531b8u: goto P_0c0531b8;
case 0x0c0531bau: goto P_0c0531ba;
case 0x0c0531bcu: goto P_0c0531bc;
case 0x0c0531beu: goto P_0c0531be;
case 0x0c0531c0u: goto P_0c0531c0;
case 0x0c0531c2u: goto P_0c0531c2;
case 0x0c0531c4u: goto P_0c0531c4;
case 0x0c0531c6u: goto P_0c0531c6;
case 0x0c0531c8u: goto P_0c0531c8;
case 0x0c0531cau: goto P_0c0531ca;
case 0x0c0531ccu: goto P_0c0531cc;
case 0x0c0531ceu: goto P_0c0531ce;
case 0x0c0531d0u: goto P_0c0531d0;
case 0x0c0531d2u: goto P_0c0531d2;
case 0x0c0531d4u: goto P_0c0531d4;
case 0x0c0531d6u: goto P_0c0531d6;
case 0x0c0531d8u: goto P_0c0531d8;
case 0x0c0531dau: goto P_0c0531da;
case 0x0c0531dcu: goto P_0c0531dc;
case 0x0c0531deu: goto P_0c0531de;
case 0x0c0531e0u: goto P_0c0531e0;
case 0x0c0531e2u: goto P_0c0531e2;
case 0x0c0531e4u: goto P_0c0531e4;
case 0x0c0531e6u: goto P_0c0531e6;
case 0x0c0531e8u: goto P_0c0531e8;
case 0x0c0531eau: goto P_0c0531ea;
case 0x0c0531ecu: goto P_0c0531ec;
case 0x0c0531eeu: goto P_0c0531ee;
case 0x0c0531f0u: goto P_0c0531f0;
case 0x0c0531f2u: goto P_0c0531f2;
case 0x0c0531f4u: goto P_0c0531f4;
case 0x0c0531f6u: goto P_0c0531f6;
case 0x0c0531f8u: goto P_0c0531f8;
case 0x0c0531fau: goto P_0c0531fa;
case 0x0c0531fcu: goto P_0c0531fc;
case 0x0c0531feu: goto P_0c0531fe;
case 0x0c053200u: goto P_0c053200;
case 0x0c053202u: goto P_0c053202;
case 0x0c053204u: goto P_0c053204;
case 0x0c053206u: goto P_0c053206;
case 0x0c053208u: goto P_0c053208;
case 0x0c05320au: goto P_0c05320a;
case 0x0c05320cu: goto P_0c05320c;
case 0x0c05320eu: goto P_0c05320e;
case 0x0c053210u: goto P_0c053210;
case 0x0c053212u: goto P_0c053212;
case 0x0c053214u: goto P_0c053214;
case 0x0c053216u: goto P_0c053216;
case 0x0c053218u: goto P_0c053218;
case 0x0c05321au: goto P_0c05321a;
case 0x0c05321cu: goto P_0c05321c;
case 0x0c05321eu: goto P_0c05321e;
case 0x0c053220u: goto P_0c053220;
case 0x0c053222u: goto P_0c053222;
case 0x0c053224u: goto P_0c053224;
case 0x0c053226u: goto P_0c053226;
case 0x0c053228u: goto P_0c053228;
case 0x0c05322au: goto P_0c05322a;
case 0x0c05322cu: goto P_0c05322c;
case 0x0c05322eu: goto P_0c05322e;
case 0x0c053230u: goto P_0c053230;
case 0x0c053232u: goto P_0c053232;
case 0x0c053234u: goto P_0c053234;
case 0x0c053236u: goto P_0c053236;
case 0x0c053238u: goto P_0c053238;
case 0x0c05323au: goto P_0c05323a;
case 0x0c05323cu: goto P_0c05323c;
case 0x0c05323eu: goto P_0c05323e;
case 0x0c053240u: goto P_0c053240;
case 0x0c053242u: goto P_0c053242;
case 0x0c053244u: goto P_0c053244;
case 0x0c053246u: goto P_0c053246;
case 0x0c053248u: goto P_0c053248;
case 0x0c05324au: goto P_0c05324a;
case 0x0c05324cu: goto P_0c05324c;
case 0x0c05324eu: goto P_0c05324e;
case 0x0c053250u: goto P_0c053250;
case 0x0c053252u: goto P_0c053252;
case 0x0c053254u: goto P_0c053254;
case 0x0c053256u: goto P_0c053256;
case 0x0c053258u: goto P_0c053258;
case 0x0c05325au: goto P_0c05325a;
case 0x0c05325cu: goto P_0c05325c;
case 0x0c05325eu: goto P_0c05325e;
case 0x0c053260u: goto P_0c053260;
case 0x0c053262u: goto P_0c053262;
case 0x0c053264u: goto P_0c053264;
case 0x0c053266u: goto P_0c053266;
case 0x0c053268u: goto P_0c053268;
case 0x0c05326au: goto P_0c05326a;
case 0x0c05326cu: goto P_0c05326c;
case 0x0c05326eu: goto P_0c05326e;
case 0x0c053270u: goto P_0c053270;
case 0x0c053272u: goto P_0c053272;
case 0x0c053274u: goto P_0c053274;
case 0x0c053276u: goto P_0c053276;
case 0x0c053278u: goto P_0c053278;
case 0x0c05327au: goto P_0c05327a;
case 0x0c05327cu: goto P_0c05327c;
case 0x0c05327eu: goto P_0c05327e;
case 0x0c053280u: goto P_0c053280;
case 0x0c053282u: goto P_0c053282;
case 0x0c053284u: goto P_0c053284;
case 0x0c053286u: goto P_0c053286;
case 0x0c053288u: goto P_0c053288;
case 0x0c05328au: goto P_0c05328a;
case 0x0c05328cu: goto P_0c05328c;
case 0x0c05328eu: goto P_0c05328e;
case 0x0c053290u: goto P_0c053290;
case 0x0c053292u: goto P_0c053292;
case 0x0c053294u: goto P_0c053294;
case 0x0c053296u: goto P_0c053296;
case 0x0c053298u: goto P_0c053298;
case 0x0c05329au: goto P_0c05329a;
case 0x0c05329cu: goto P_0c05329c;
case 0x0c05329eu: goto P_0c05329e;
case 0x0c0532a0u: goto P_0c0532a0;
case 0x0c0532a2u: goto P_0c0532a2;
case 0x0c0532a4u: goto P_0c0532a4;
case 0x0c0532a6u: goto P_0c0532a6;
case 0x0c0532a8u: goto P_0c0532a8;
case 0x0c0532aau: goto P_0c0532aa;
case 0x0c0532acu: goto P_0c0532ac;
case 0x0c0532aeu: goto P_0c0532ae;
case 0x0c0532b0u: goto P_0c0532b0;
case 0x0c0532b2u: goto P_0c0532b2;
case 0x0c0532b4u: goto P_0c0532b4;
case 0x0c0532b6u: goto P_0c0532b6;
case 0x0c0532b8u: goto P_0c0532b8;
case 0x0c0532bau: goto P_0c0532ba;
case 0x0c0532bcu: goto P_0c0532bc;
case 0x0c0532beu: goto P_0c0532be;
case 0x0c0532c0u: goto P_0c0532c0;
case 0x0c0532c2u: goto P_0c0532c2;
case 0x0c0532c4u: goto P_0c0532c4;
case 0x0c0532c6u: goto P_0c0532c6;
case 0x0c0532c8u: goto P_0c0532c8;
case 0x0c0532cau: goto P_0c0532ca;
case 0x0c0532ccu: goto P_0c0532cc;
case 0x0c0532ceu: goto P_0c0532ce;
case 0x0c0532d0u: goto P_0c0532d0;
case 0x0c0532d2u: goto P_0c0532d2;
case 0x0c0532d4u: goto P_0c0532d4;
case 0x0c0532d6u: goto P_0c0532d6;
case 0x0c0532d8u: goto P_0c0532d8;
case 0x0c0532dau: goto P_0c0532da;
case 0x0c0532dcu: goto P_0c0532dc;
case 0x0c0532deu: goto P_0c0532de;
case 0x0c0532e0u: goto P_0c0532e0;
case 0x0c0532e2u: goto P_0c0532e2;
case 0x0c0532e4u: goto P_0c0532e4;
case 0x0c0532e6u: goto P_0c0532e6;
case 0x0c0532e8u: goto P_0c0532e8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05305c: /* original 2fe6, guest PC 0x0c05305c */
if(!s->budget--) { s->failed_pc=0x0c05305cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05305e;
P_0c05305e: /* original e308, guest PC 0x0c05305e */
if(!s->budget--) { s->failed_pc=0x0c05305eu; return 0; }
r[3]=0x00000008u;
goto P_0c053060;
P_0c053060: /* original 2fd6, guest PC 0x0c053060 */
if(!s->budget--) { s->failed_pc=0x0c053060u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053062;
P_0c053062: /* original e000, guest PC 0x0c053062 */
if(!s->budget--) { s->failed_pc=0x0c053062u; return 0; }
r[0]=0x00000000u;
goto P_0c053064;
P_0c053064: /* original 2fc6, guest PC 0x0c053064 */
if(!s->budget--) { s->failed_pc=0x0c053064u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053066;
P_0c053066: /* original 6e33, guest PC 0x0c053066 */
if(!s->budget--) { s->failed_pc=0x0c053066u; return 0; }
r[14]=r[3];
goto P_0c053068;
P_0c053068: /* original 2fb6, guest PC 0x0c053068 */
if(!s->budget--) { s->failed_pc=0x0c053068u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05306a;
P_0c05306a: /* original 6d03, guest PC 0x0c05306a */
if(!s->budget--) { s->failed_pc=0x0c05306au; return 0; }
r[13]=r[0];
goto P_0c05306c;
P_0c05306c: /* original 2fa6, guest PC 0x0c05306c */
if(!s->budget--) { s->failed_pc=0x0c05306cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05306e;
P_0c05306e: /* original 6a63, guest PC 0x0c05306e */
if(!s->budget--) { s->failed_pc=0x0c05306eu; return 0; }
r[10]=r[6];
goto P_0c053070;
P_0c053070: /* original 2f96, guest PC 0x0c053070 */
if(!s->budget--) { s->failed_pc=0x0c053070u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053072;
P_0c053072: /* original 6953, guest PC 0x0c053072 */
if(!s->budget--) { s->failed_pc=0x0c053072u; return 0; }
r[9]=r[5];
goto P_0c053074;
P_0c053074: /* original 2f86, guest PC 0x0c053074 */
if(!s->budget--) { s->failed_pc=0x0c053074u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053076;
P_0c053076: /* original 6843, guest PC 0x0c053076 */
if(!s->budget--) { s->failed_pc=0x0c053076u; return 0; }
r[8]=r[4];
goto P_0c053078;
P_0c053078: /* original 4f22, guest PC 0x0c053078 */
if(!s->budget--) { s->failed_pc=0x0c053078u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05307a;
P_0c05307a: /* original 7fcc, guest PC 0x0c05307a */
if(!s->budget--) { s->failed_pc=0x0c05307au; return 0; }
r[15]+=0xffffffccu;
goto P_0c05307c;
P_0c05307c: /* original 1f32, guest PC 0x0c05307c */
if(!s->budget--) { s->failed_pc=0x0c05307cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05307e;
P_0c05307e: /* original 6bf3, guest PC 0x0c05307e */
if(!s->budget--) { s->failed_pc=0x0c05307eu; return 0; }
r[11]=r[15];
goto P_0c053080;
P_0c053080: /* original 81f8, guest PC 0x0c053080 */
if(!s->budget--) { s->failed_pc=0x0c053080u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c053082;
P_0c053082: /* original 7b54, guest PC 0x0c053082 */
if(!s->budget--) { s->failed_pc=0x0c053082u; return 0; }
r[11]+=0x00000054u;
goto P_0c053084;
P_0c053084: /* original 63b3, guest PC 0x0c053084 */
if(!s->budget--) { s->failed_pc=0x0c053084u; return 0; }
r[3]=r[11];
goto P_0c053086;
P_0c053086: /* original 7307, guest PC 0x0c053086 */
if(!s->budget--) { s->failed_pc=0x0c053086u; return 0; }
r[3]+=0x00000007u;
goto P_0c053088;
P_0c053088: /* original 1f31, guest PC 0x0c053088 */
if(!s->budget--) { s->failed_pc=0x0c053088u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c05308a;
P_0c05308a: /* original 6030, guest PC 0x0c05308a */
if(!s->budget--) { s->failed_pc=0x0c05308au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c05308c;
P_0c05308c: /* original 600c, guest PC 0x0c05308c */
if(!s->budget--) { s->failed_pc=0x0c05308cu; return 0; }
r[0]=r[0]&255u;
goto P_0c05308e;
P_0c05308e: /* original c87f, guest PC 0x0c05308e */
if(!s->budget--) { s->failed_pc=0x0c05308eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&127u)==0)!=0);
goto P_0c053090;
P_0c053090: /* original 8f1f, guest PC 0x0c053090 */
if(!s->budget--) { s->failed_pc=0x0c053090u; return 0; }
cond=r[17]&1u;
r[12]=r[7];
if(!cond) { goto P_0c0530d2; }
goto P_0c053094;
P_0c053092: /* original 6c73, guest PC 0x0c053092 */
if(!s->budget--) { s->failed_pc=0x0c053092u; return 0; }
r[12]=r[7];
goto P_0c053094;
P_0c053094: /* original d134, guest PC 0x0c053094 */
if(!s->budget--) { s->failed_pc=0x0c053094u; return 0; }
r[1]=read(ram,0x0c053168u,4);
goto P_0c053096;
P_0c053096: /* original e507, guest PC 0x0c053096 */
if(!s->budget--) { s->failed_pc=0x0c053096u; return 0; }
r[5]=0x00000007u;
goto P_0c053098;
P_0c053098: /* original 410b, guest PC 0x0c053098 */
if(!s->budget--) { s->failed_pc=0x0c053098u; return 0; }
target=r[1];
r[16]=code_base|0x0c05309cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05309cu) { target=s->pc; goto dispatch; }
goto P_0c05309c;
P_0c05309a: /* original 64b3, guest PC 0x0c05309a */
if(!s->budget--) { s->failed_pc=0x0c05309au; return 0; }
r[4]=r[11];
goto P_0c05309c;
P_0c05309c: /* original 2008, guest PC 0x0c05309c */
if(!s->budget--) { s->failed_pc=0x0c05309cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05309e;
P_0c05309e: /* original 8d18, guest PC 0x0c05309e */
if(!s->budget--) { s->failed_pc=0x0c05309eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0530d2; }
goto P_0c0530a2;
P_0c0530a0: /* original 0009, guest PC 0x0c0530a0 */
if(!s->budget--) { s->failed_pc=0x0c0530a0u; return 0; }
goto P_0c0530a2;
P_0c0530a2: /* original e500, guest PC 0x0c0530a2 */
if(!s->budget--) { s->failed_pc=0x0c0530a2u; return 0; }
r[5]=0x00000000u;
goto P_0c0530a4;
P_0c0530a4: /* original e400, guest PC 0x0c0530a4 */
if(!s->budget--) { s->failed_pc=0x0c0530a4u; return 0; }
r[4]=0x00000000u;
goto P_0c0530a6;
P_0c0530a6: /* original a003, guest PC 0x0c0530a6 */
if(!s->budget--) { s->failed_pc=0x0c0530a6u; return 0; }
r[4]+=r[9];
goto P_0c0530b0;
P_0c0530a8: /* original 349c, guest PC 0x0c0530a8 */
if(!s->budget--) { s->failed_pc=0x0c0530a8u; return 0; }
r[4]+=r[9];
goto P_0c0530aa;
P_0c0530aa: /* original 7501, guest PC 0x0c0530aa */
if(!s->budget--) { s->failed_pc=0x0c0530aau; return 0; }
r[5]+=0x00000001u;
goto P_0c0530ac;
P_0c0530ac: /* original 24d0, guest PC 0x0c0530ac */
if(!s->budget--) { s->failed_pc=0x0c0530acu; return 0; }
write(ram,r[4],r[13],1);
goto P_0c0530ae;
P_0c0530ae: /* original 7401, guest PC 0x0c0530ae */
if(!s->budget--) { s->failed_pc=0x0c0530aeu; return 0; }
r[4]+=0x00000001u;
goto P_0c0530b0;
P_0c0530b0: /* original 35e3, guest PC 0x0c0530b0 */
if(!s->budget--) { s->failed_pc=0x0c0530b0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[14])!=0);
goto P_0c0530b2;
P_0c0530b2: /* original 8ffa, guest PC 0x0c0530b2 */
if(!s->budget--) { s->failed_pc=0x0c0530b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0530aa; }
goto P_0c0530b6;
P_0c0530b4: /* original 0009, guest PC 0x0c0530b4 */
if(!s->budget--) { s->failed_pc=0x0c0530b4u; return 0; }
goto P_0c0530b6;
P_0c0530b6: /* original 2ad2, guest PC 0x0c0530b6 */
if(!s->budget--) { s->failed_pc=0x0c0530b6u; return 0; }
write(ram,r[10],r[13],4);
goto P_0c0530b8;
P_0c0530b8: /* original 50f1, guest PC 0x0c0530b8 */
if(!s->budget--) { s->failed_pc=0x0c0530b8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0530ba;
P_0c0530ba: /* original 6000, guest PC 0x0c0530ba */
if(!s->budget--) { s->failed_pc=0x0c0530bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[0],1);
r[0]=tmp;
goto P_0c0530bc;
P_0c0530bc: /* original 600c, guest PC 0x0c0530bc */
if(!s->budget--) { s->failed_pc=0x0c0530bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0530be;
P_0c0530be: /* original c880, guest PC 0x0c0530be */
if(!s->budget--) { s->failed_pc=0x0c0530beu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0530c0;
P_0c0530c0: /* original 8d03, guest PC 0x0c0530c0 */
if(!s->budget--) { s->failed_pc=0x0c0530c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0530ca; }
goto P_0c0530c4;
P_0c0530c2: /* original 0009, guest PC 0x0c0530c2 */
if(!s->budget--) { s->failed_pc=0x0c0530c2u; return 0; }
goto P_0c0530c4;
P_0c0530c4: /* original e2ff, guest PC 0x0c0530c4 */
if(!s->budget--) { s->failed_pc=0x0c0530c4u; return 0; }
r[2]=0xffffffffu;
goto P_0c0530c6;
P_0c0530c6: /* original a105, guest PC 0x0c0530c6 */
if(!s->budget--) { s->failed_pc=0x0c0530c6u; return 0; }
write(ram,r[12],r[2],1);
goto P_0c0532d4;
P_0c0530c8: /* original 2c20, guest PC 0x0c0530c8 */
if(!s->budget--) { s->failed_pc=0x0c0530c8u; return 0; }
write(ram,r[12],r[2],1);
goto P_0c0530ca;
P_0c0530ca: /* original e101, guest PC 0x0c0530ca */
if(!s->budget--) { s->failed_pc=0x0c0530cau; return 0; }
r[1]=0x00000001u;
goto P_0c0530cc;
P_0c0530cc: /* original 2c10, guest PC 0x0c0530cc */
if(!s->budget--) { s->failed_pc=0x0c0530ccu; return 0; }
write(ram,r[12],r[1],1);
goto P_0c0530ce;
P_0c0530ce: /* original a101, guest PC 0x0c0530ce */
if(!s->budget--) { s->failed_pc=0x0c0530ceu; return 0; }
goto P_0c0532d4;
P_0c0530d0: /* original 0009, guest PC 0x0c0530d0 */
if(!s->budget--) { s->failed_pc=0x0c0530d0u; return 0; }
goto P_0c0530d2;
P_0c0530d2: /* original e058, guest PC 0x0c0530d2 */
if(!s->budget--) { s->failed_pc=0x0c0530d2u; return 0; }
r[0]=0x00000058u;
goto P_0c0530d4;
P_0c0530d4: /* original 03fe, guest PC 0x0c0530d4 */
if(!s->budget--) { s->failed_pc=0x0c0530d4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0530d6;
P_0c0530d6: /* original e058, guest PC 0x0c0530d6 */
if(!s->budget--) { s->failed_pc=0x0c0530d6u; return 0; }
r[0]=0x00000058u;
goto P_0c0530d8;
P_0c0530d8: /* original 2f36, guest PC 0x0c0530d8 */
if(!s->budget--) { s->failed_pc=0x0c0530d8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0530da;
P_0c0530da: /* original 03fe, guest PC 0x0c0530da */
if(!s->budget--) { s->failed_pc=0x0c0530dau; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0530dc;
P_0c0530dc: /* original 2f36, guest PC 0x0c0530dc */
if(!s->budget--) { s->failed_pc=0x0c0530dcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0530de;
P_0c0530de: /* original 66f3, guest PC 0x0c0530de */
if(!s->budget--) { s->failed_pc=0x0c0530deu; return 0; }
r[6]=r[15];
goto P_0c0530e0;
P_0c0530e0: /* original d322, guest PC 0x0c0530e0 */
if(!s->budget--) { s->failed_pc=0x0c0530e0u; return 0; }
r[3]=read(ram,0x0c05316cu,4);
goto P_0c0530e2;
P_0c0530e2: /* original 65f3, guest PC 0x0c0530e2 */
if(!s->budget--) { s->failed_pc=0x0c0530e2u; return 0; }
r[5]=r[15];
goto P_0c0530e4;
P_0c0530e4: /* original 7634, guest PC 0x0c0530e4 */
if(!s->budget--) { s->failed_pc=0x0c0530e4u; return 0; }
r[6]+=0x00000034u;
goto P_0c0530e6;
P_0c0530e6: /* original 7508, guest PC 0x0c0530e6 */
if(!s->budget--) { s->failed_pc=0x0c0530e6u; return 0; }
r[5]+=0x00000008u;
goto P_0c0530e8;
P_0c0530e8: /* original 430b, guest PC 0x0c0530e8 */
if(!s->budget--) { s->failed_pc=0x0c0530e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0530ecu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0530ecu) { target=s->pc; goto dispatch; }
goto P_0c0530ec;
P_0c0530ea: /* original 64c3, guest PC 0x0c0530ea */
if(!s->budget--) { s->failed_pc=0x0c0530eau; return 0; }
r[4]=r[12];
goto P_0c0530ec;
P_0c0530ec: /* original 60c0, guest PC 0x0c0530ec */
if(!s->budget--) { s->failed_pc=0x0c0530ecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[0]=tmp;
goto P_0c0530ee;
P_0c0530ee: /* original 88ff, guest PC 0x0c0530ee */
if(!s->budget--) { s->failed_pc=0x0c0530eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0530f0;
P_0c0530f0: /* original 8f05, guest PC 0x0c0530f0 */
if(!s->budget--) { s->failed_pc=0x0c0530f0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000008u;
if(!cond) { goto P_0c0530fe; }
goto P_0c0530f4;
P_0c0530f2: /* original 7f08, guest PC 0x0c0530f2 */
if(!s->budget--) { s->failed_pc=0x0c0530f2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0530f4;
P_0c0530f4: /* original 63f3, guest PC 0x0c0530f4 */
if(!s->budget--) { s->failed_pc=0x0c0530f4u; return 0; }
r[3]=r[15];
goto P_0c0530f6;
P_0c0530f6: /* original 7354, guest PC 0x0c0530f6 */
if(!s->budget--) { s->failed_pc=0x0c0530f6u; return 0; }
r[3]+=0x00000054u;
goto P_0c0530f8;
P_0c0530f8: /* original 8437, guest PC 0x0c0530f8 */
if(!s->budget--) { s->failed_pc=0x0c0530f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+7,1);
goto P_0c0530fa;
P_0c0530fa: /* original c97f, guest PC 0x0c0530fa */
if(!s->budget--) { s->failed_pc=0x0c0530fau; return 0; }
r[0]&=127u;
goto P_0c0530fc;
P_0c0530fc: /* original 8037, guest PC 0x0c0530fc */
if(!s->budget--) { s->failed_pc=0x0c0530fcu; return 0; }
write(ram,r[3]+7,r[0],1);
goto P_0c0530fe;
P_0c0530fe: /* original 63f1, guest PC 0x0c0530fe */
if(!s->budget--) { s->failed_pc=0x0c0530feu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c053100;
P_0c053100: /* original 922f, guest PC 0x0c053100 */
if(!s->budget--) { s->failed_pc=0x0c053100u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c053162u,2);
goto P_0c053102;
P_0c053102: /* original 3320, guest PC 0x0c053102 */
if(!s->budget--) { s->failed_pc=0x0c053102u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c053104;
P_0c053104: /* original 8f1a, guest PC 0x0c053104 */
if(!s->budget--) { s->failed_pc=0x0c053104u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05313c; }
goto P_0c053108;
P_0c053106: /* original 0009, guest PC 0x0c053106 */
if(!s->budget--) { s->failed_pc=0x0c053106u; return 0; }
goto P_0c053108;
P_0c053108: /* original 84b6, guest PC 0x0c053108 */
if(!s->budget--) { s->failed_pc=0x0c053108u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+6,1);
goto P_0c05310a;
P_0c05310a: /* original 600c, guest PC 0x0c05310a */
if(!s->budget--) { s->failed_pc=0x0c05310au; return 0; }
r[0]=r[0]&255u;
goto P_0c05310c;
P_0c05310c: /* original 932a, guest PC 0x0c05310c */
if(!s->budget--) { s->failed_pc=0x0c05310cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c053164u,2);
goto P_0c05310e;
P_0c05310e: /* original 3030, guest PC 0x0c05310e */
if(!s->budget--) { s->failed_pc=0x0c05310eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c053110;
P_0c053110: /* original 8f12, guest PC 0x0c053110 */
if(!s->budget--) { s->failed_pc=0x0c053110u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053138; }
goto P_0c053114;
P_0c053112: /* original 0009, guest PC 0x0c053112 */
if(!s->budget--) { s->failed_pc=0x0c053112u; return 0; }
goto P_0c053114;
P_0c053114: /* original d114, guest PC 0x0c053114 */
if(!s->budget--) { s->failed_pc=0x0c053114u; return 0; }
r[1]=read(ram,0x0c053168u,4);
goto P_0c053116;
P_0c053116: /* original e506, guest PC 0x0c053116 */
if(!s->budget--) { s->failed_pc=0x0c053116u; return 0; }
r[5]=0x00000006u;
goto P_0c053118;
P_0c053118: /* original 410b, guest PC 0x0c053118 */
if(!s->budget--) { s->failed_pc=0x0c053118u; return 0; }
target=r[1];
r[16]=code_base|0x0c05311cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05311cu) { target=s->pc; goto dispatch; }
goto P_0c05311c;
P_0c05311a: /* original 64b3, guest PC 0x0c05311a */
if(!s->budget--) { s->failed_pc=0x0c05311au; return 0; }
r[4]=r[11];
goto P_0c05311c;
P_0c05311c: /* original 2008, guest PC 0x0c05311c */
if(!s->budget--) { s->failed_pc=0x0c05311cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c05311e;
P_0c05311e: /* original 8d0b, guest PC 0x0c05311e */
if(!s->budget--) { s->failed_pc=0x0c05311eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053138; }
goto P_0c053122;
P_0c053120: /* original 0009, guest PC 0x0c053120 */
if(!s->budget--) { s->failed_pc=0x0c053120u; return 0; }
goto P_0c053122;
P_0c053122: /* original 60c0, guest PC 0x0c053122 */
if(!s->budget--) { s->failed_pc=0x0c053122u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[0]=tmp;
goto P_0c053124;
P_0c053124: /* original 8801, guest PC 0x0c053124 */
if(!s->budget--) { s->failed_pc=0x0c053124u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c053126;
P_0c053126: /* original 8f02, guest PC 0x0c053126 */
if(!s->budget--) { s->failed_pc=0x0c053126u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05312e; }
goto P_0c05312a;
P_0c053128: /* original 0009, guest PC 0x0c053128 */
if(!s->budget--) { s->failed_pc=0x0c053128u; return 0; }
goto P_0c05312a;
P_0c05312a: /* original a0d4, guest PC 0x0c05312a */
if(!s->budget--) { s->failed_pc=0x0c05312au; return 0; }
r[0]=0x00000001u;
goto P_0c0532d6;
P_0c05312c: /* original e001, guest PC 0x0c05312c */
if(!s->budget--) { s->failed_pc=0x0c05312cu; return 0; }
r[0]=0x00000001u;
goto P_0c05312e;
P_0c05312e: /* original 88ff, guest PC 0x0c05312e */
if(!s->budget--) { s->failed_pc=0x0c05312eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c053130;
P_0c053130: /* original 8f04, guest PC 0x0c053130 */
if(!s->budget--) { s->failed_pc=0x0c053130u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05313c; }
goto P_0c053134;
P_0c053132: /* original 0009, guest PC 0x0c053132 */
if(!s->budget--) { s->failed_pc=0x0c053132u; return 0; }
goto P_0c053134;
P_0c053134: /* original a0cf, guest PC 0x0c053134 */
if(!s->budget--) { s->failed_pc=0x0c053134u; return 0; }
r[0]=0xffffffffu;
goto P_0c0532d6;
P_0c053136: /* original e0ff, guest PC 0x0c053136 */
if(!s->budget--) { s->failed_pc=0x0c053136u; return 0; }
r[0]=0xffffffffu;
goto P_0c053138;
P_0c053138: /* original a0cd, guest PC 0x0c053138 */
if(!s->budget--) { s->failed_pc=0x0c053138u; return 0; }
r[0]=0x00000002u;
goto P_0c0532d6;
P_0c05313a: /* original e002, guest PC 0x0c05313a */
if(!s->budget--) { s->failed_pc=0x0c05313au; return 0; }
r[0]=0x00000002u;
goto P_0c05313c;
P_0c05313c: /* original 9313, guest PC 0x0c05313c */
if(!s->budget--) { s->failed_pc=0x0c05313cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c053166u,2);
goto P_0c05313e;
P_0c05313e: /* original 62f1, guest PC 0x0c05313e */
if(!s->budget--) { s->failed_pc=0x0c05313eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c053140;
P_0c053140: /* original 3238, guest PC 0x0c053140 */
if(!s->budget--) { s->failed_pc=0x0c053140u; return 0; }
r[2]-=r[3];
goto P_0c053142;
P_0c053142: /* original 2f21, guest PC 0x0c053142 */
if(!s->budget--) { s->failed_pc=0x0c053142u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c053144;
P_0c053144: /* original 622f, guest PC 0x0c053144 */
if(!s->budget--) { s->failed_pc=0x0c053144u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c053146;
P_0c053146: /* original 4211, guest PC 0x0c053146 */
if(!s->budget--) { s->failed_pc=0x0c053146u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c053148;
P_0c053148: /* original 8f14, guest PC 0x0c053148 */
if(!s->budget--) { s->failed_pc=0x0c053148u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053174; }
goto P_0c05314c;
P_0c05314a: /* original 0009, guest PC 0x0c05314a */
if(!s->budget--) { s->failed_pc=0x0c05314au; return 0; }
goto P_0c05314c;
P_0c05314c: /* original d208, guest PC 0x0c05314c */
if(!s->budget--) { s->failed_pc=0x0c05314cu; return 0; }
r[2]=read(ram,0x0c053170u,4);
goto P_0c05314e;
P_0c05314e: /* original e058, guest PC 0x0c05314e */
if(!s->budget--) { s->failed_pc=0x0c05314eu; return 0; }
r[0]=0x00000058u;
goto P_0c053150;
P_0c053150: /* original 01fe, guest PC 0x0c053150 */
if(!s->budget--) { s->failed_pc=0x0c053150u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c053152;
P_0c053152: /* original e058, guest PC 0x0c053152 */
if(!s->budget--) { s->failed_pc=0x0c053152u; return 0; }
r[0]=0x00000058u;
goto P_0c053154;
P_0c053154: /* original 2f16, guest PC 0x0c053154 */
if(!s->budget--) { s->failed_pc=0x0c053154u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053156;
P_0c053156: /* original 01fe, guest PC 0x0c053156 */
if(!s->budget--) { s->failed_pc=0x0c053156u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c053158;
P_0c053158: /* original 420b, guest PC 0x0c053158 */
if(!s->budget--) { s->failed_pc=0x0c053158u; return 0; }
target=r[2];
r[16]=code_base|0x0c05315cu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05315cu) { target=s->pc; goto dispatch; }
goto P_0c05315c;
P_0c05315a: /* original 2f16, guest PC 0x0c05315a */
if(!s->budget--) { s->failed_pc=0x0c05315au; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05315c;
P_0c05315c: /* original 7f08, guest PC 0x0c05315c */
if(!s->budget--) { s->failed_pc=0x0c05315cu; return 0; }
r[15]+=0x00000008u;
goto P_0c05315e;
P_0c05315e: /* original a014, guest PC 0x0c05315e */
if(!s->budget--) { s->failed_pc=0x0c05315eu; return 0; }
r[4]=r[0];
goto P_0c05318a;
P_0c053160: /* original 6403, guest PC 0x0c053160 */
if(!s->budget--) { s->failed_pc=0x0c053160u; return 0; }
r[4]=r[0];
if(!vf3_matrix_family(0x0c053162u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053162u; return 0; } return 1;
P_0c053174: /* original d15d, guest PC 0x0c053174 */
if(!s->budget--) { s->failed_pc=0x0c053174u; return 0; }
r[1]=read(ram,0x0c0532ecu,4);
goto P_0c053176;
P_0c053176: /* original e058, guest PC 0x0c053176 */
if(!s->budget--) { s->failed_pc=0x0c053176u; return 0; }
r[0]=0x00000058u;
goto P_0c053178;
P_0c053178: /* original 02fe, guest PC 0x0c053178 */
if(!s->budget--) { s->failed_pc=0x0c053178u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c05317a;
P_0c05317a: /* original e058, guest PC 0x0c05317a */
if(!s->budget--) { s->failed_pc=0x0c05317au; return 0; }
r[0]=0x00000058u;
goto P_0c05317c;
P_0c05317c: /* original 2f26, guest PC 0x0c05317c */
if(!s->budget--) { s->failed_pc=0x0c05317cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05317e;
P_0c05317e: /* original 02fe, guest PC 0x0c05317e */
if(!s->budget--) { s->failed_pc=0x0c05317eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c053180;
P_0c053180: /* original 410b, guest PC 0x0c053180 */
if(!s->budget--) { s->failed_pc=0x0c053180u; return 0; }
target=r[1];
r[16]=code_base|0x0c053184u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053184u) { target=s->pc; goto dispatch; }
goto P_0c053184;
P_0c053182: /* original 2f26, guest PC 0x0c053182 */
if(!s->budget--) { s->failed_pc=0x0c053182u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053184;
P_0c053184: /* original 7f08, guest PC 0x0c053184 */
if(!s->budget--) { s->failed_pc=0x0c053184u; return 0; }
r[15]+=0x00000008u;
goto P_0c053186;
P_0c053186: /* original 6403, guest PC 0x0c053186 */
if(!s->budget--) { s->failed_pc=0x0c053186u; return 0; }
r[4]=r[0];
goto P_0c053188;
P_0c053188: /* original 74ff, guest PC 0x0c053188 */
if(!s->budget--) { s->failed_pc=0x0c053188u; return 0; }
r[4]+=0xffffffffu;
goto P_0c05318a;
P_0c05318a: /* original e033, guest PC 0x0c05318a */
if(!s->budget--) { s->failed_pc=0x0c05318au; return 0; }
r[0]=0x00000033u;
goto P_0c05318c;
P_0c05318c: /* original d358, guest PC 0x0c05318c */
if(!s->budget--) { s->failed_pc=0x0c05318cu; return 0; }
r[3]=read(ram,0x0c0532f0u,4);
goto P_0c05318e;
P_0c05318e: /* original 3488, guest PC 0x0c05318e */
if(!s->budget--) { s->failed_pc=0x0c05318eu; return 0; }
r[4]-=r[8];
goto P_0c053190;
P_0c053190: /* original 0fd4, guest PC 0x0c053190 */
if(!s->budget--) { s->failed_pc=0x0c053190u; return 0; }
write(ram,r[15]+r[0],r[13],1);
goto P_0c053192;
P_0c053192: /* original 6cf3, guest PC 0x0c053192 */
if(!s->budget--) { s->failed_pc=0x0c053192u; return 0; }
r[12]=r[15];
goto P_0c053194;
P_0c053194: /* original 7401, guest PC 0x0c053194 */
if(!s->budget--) { s->failed_pc=0x0c053194u; return 0; }
r[4]+=0x00000001u;
goto P_0c053196;
P_0c053196: /* original 7c24, guest PC 0x0c053196 */
if(!s->budget--) { s->failed_pc=0x0c053196u; return 0; }
r[12]+=0x00000024u;
goto P_0c053198;
P_0c053198: /* original 2a42, guest PC 0x0c053198 */
if(!s->budget--) { s->failed_pc=0x0c053198u; return 0; }
write(ram,r[10],r[4],4);
goto P_0c05319a;
P_0c05319a: /* original 65c3, guest PC 0x0c05319a */
if(!s->budget--) { s->failed_pc=0x0c05319au; return 0; }
r[5]=r[12];
goto P_0c05319c;
P_0c05319c: /* original 430b, guest PC 0x0c05319c */
if(!s->budget--) { s->failed_pc=0x0c05319cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0531a0u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0531a0u) { target=s->pc; goto dispatch; }
goto P_0c0531a0;
P_0c05319e: /* original 6483, guest PC 0x0c05319e */
if(!s->budget--) { s->failed_pc=0x0c05319eu; return 0; }
r[4]=r[8];
goto P_0c0531a0;
P_0c0531a0: /* original d254, guest PC 0x0c0531a0 */
if(!s->budget--) { s->failed_pc=0x0c0531a0u; return 0; }
r[2]=read(ram,0x0c0532f4u,4);
goto P_0c0531a2;
P_0c0531a2: /* original 6183, guest PC 0x0c0531a2 */
if(!s->budget--) { s->failed_pc=0x0c0531a2u; return 0; }
r[1]=r[8];
goto P_0c0531a4;
P_0c0531a4: /* original 420b, guest PC 0x0c0531a4 */
if(!s->budget--) { s->failed_pc=0x0c0531a4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0531a8u;
r[0]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0531a8u) { target=s->pc; goto dispatch; }
goto P_0c0531a8;
P_0c0531a6: /* original 50f2, guest PC 0x0c0531a6 */
if(!s->budget--) { s->failed_pc=0x0c0531a6u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0531a8;
P_0c0531a8: /* original 6b03, guest PC 0x0c0531a8 */
if(!s->budget--) { s->failed_pc=0x0c0531a8u; return 0; }
r[11]=r[0];
goto P_0c0531aa;
P_0c0531aa: /* original 65e3, guest PC 0x0c0531aa */
if(!s->budget--) { s->failed_pc=0x0c0531aau; return 0; }
r[5]=r[14];
goto P_0c0531ac;
P_0c0531ac: /* original 35b8, guest PC 0x0c0531ac */
if(!s->budget--) { s->failed_pc=0x0c0531acu; return 0; }
r[5]-=r[11];
goto P_0c0531ae;
P_0c0531ae: /* original 4515, guest PC 0x0c0531ae */
if(!s->budget--) { s->failed_pc=0x0c0531aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c0531b0;
P_0c0531b0: /* original 8f0a, guest PC 0x0c0531b0 */
if(!s->budget--) { s->failed_pc=0x0c0531b0u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c0531c8; }
goto P_0c0531b4;
P_0c0531b2: /* original e400, guest PC 0x0c0531b2 */
if(!s->budget--) { s->failed_pc=0x0c0531b2u; return 0; }
r[4]=0x00000000u;
goto P_0c0531b4;
P_0c0531b4: /* original 6043, guest PC 0x0c0531b4 */
if(!s->budget--) { s->failed_pc=0x0c0531b4u; return 0; }
r[0]=r[4];
goto P_0c0531b6;
P_0c0531b6: /* original 0009, guest PC 0x0c0531b6 */
if(!s->budget--) { s->failed_pc=0x0c0531b6u; return 0; }
goto P_0c0531b8;
P_0c0531b8: /* original 6343, guest PC 0x0c0531b8 */
if(!s->budget--) { s->failed_pc=0x0c0531b8u; return 0; }
r[3]=r[4];
goto P_0c0531ba;
P_0c0531ba: /* original 33bc, guest PC 0x0c0531ba */
if(!s->budget--) { s->failed_pc=0x0c0531bau; return 0; }
r[3]+=r[11];
goto P_0c0531bc;
P_0c0531bc: /* original 33cc, guest PC 0x0c0531bc */
if(!s->budget--) { s->failed_pc=0x0c0531bcu; return 0; }
r[3]+=r[12];
goto P_0c0531be;
P_0c0531be: /* original 7401, guest PC 0x0c0531be */
if(!s->budget--) { s->failed_pc=0x0c0531beu; return 0; }
r[4]+=0x00000001u;
goto P_0c0531c0;
P_0c0531c0: /* original 6330, guest PC 0x0c0531c0 */
if(!s->budget--) { s->failed_pc=0x0c0531c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c0531c2;
P_0c0531c2: /* original 3453, guest PC 0x0c0531c2 */
if(!s->budget--) { s->failed_pc=0x0c0531c2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c0531c4;
P_0c0531c4: /* original 8ff6, guest PC 0x0c0531c4 */
if(!s->budget--) { s->failed_pc=0x0c0531c4u; return 0; }
cond=r[17]&1u;
write(ram,r[12]+r[0],r[3],1);
if(!cond) { goto P_0c0531b4; }
goto P_0c0531c8;
P_0c0531c6: /* original 0c34, guest PC 0x0c0531c6 */
if(!s->budget--) { s->failed_pc=0x0c0531c6u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c0531c8;
P_0c0531c8: /* original 6543, guest PC 0x0c0531c8 */
if(!s->budget--) { s->failed_pc=0x0c0531c8u; return 0; }
r[5]=r[4];
goto P_0c0531ca;
P_0c0531ca: /* original 34e3, guest PC 0x0c0531ca */
if(!s->budget--) { s->failed_pc=0x0c0531cau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c0531cc;
P_0c0531cc: /* original 8d05, guest PC 0x0c0531cc */
if(!s->budget--) { s->failed_pc=0x0c0531ccu; return 0; }
cond=r[17]&1u;
r[5]+=r[12];
if(cond) { goto P_0c0531da; }
goto P_0c0531d0;
P_0c0531ce: /* original 35cc, guest PC 0x0c0531ce */
if(!s->budget--) { s->failed_pc=0x0c0531ceu; return 0; }
r[5]+=r[12];
goto P_0c0531d0;
P_0c0531d0: /* original 25d0, guest PC 0x0c0531d0 */
if(!s->budget--) { s->failed_pc=0x0c0531d0u; return 0; }
write(ram,r[5],r[13],1);
goto P_0c0531d2;
P_0c0531d2: /* original 7401, guest PC 0x0c0531d2 */
if(!s->budget--) { s->failed_pc=0x0c0531d2u; return 0; }
r[4]+=0x00000001u;
goto P_0c0531d4;
P_0c0531d4: /* original 34e3, guest PC 0x0c0531d4 */
if(!s->budget--) { s->failed_pc=0x0c0531d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c0531d6;
P_0c0531d6: /* original 8ffb, guest PC 0x0c0531d6 */
if(!s->budget--) { s->failed_pc=0x0c0531d6u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c0531d0; }
goto P_0c0531da;
P_0c0531d8: /* original 7501, guest PC 0x0c0531d8 */
if(!s->budget--) { s->failed_pc=0x0c0531d8u; return 0; }
r[5]+=0x00000001u;
goto P_0c0531da;
P_0c0531da: /* original 4b08, guest PC 0x0c0531da */
if(!s->budget--) { s->failed_pc=0x0c0531dau; return 0; }
r[11]<<=2;
goto P_0c0531dc;
P_0c0531dc: /* original d346, guest PC 0x0c0531dc */
if(!s->budget--) { s->failed_pc=0x0c0531dcu; return 0; }
r[3]=read(ram,0x0c0532f8u,4);
goto P_0c0531de;
P_0c0531de: /* original 6683, guest PC 0x0c0531de */
if(!s->budget--) { s->failed_pc=0x0c0531deu; return 0; }
r[6]=r[8];
goto P_0c0531e0;
P_0c0531e0: /* original 4b00, guest PC 0x0c0531e0 */
if(!s->budget--) { s->failed_pc=0x0c0531e0u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c0531e2;
P_0c0531e2: /* original 36b8, guest PC 0x0c0531e2 */
if(!s->budget--) { s->failed_pc=0x0c0531e2u; return 0; }
r[6]-=r[11];
goto P_0c0531e4;
P_0c0531e4: /* original e508, guest PC 0x0c0531e4 */
if(!s->budget--) { s->failed_pc=0x0c0531e4u; return 0; }
r[5]=0x00000008u;
goto P_0c0531e6;
P_0c0531e6: /* original 430b, guest PC 0x0c0531e6 */
if(!s->budget--) { s->failed_pc=0x0c0531e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0531eau;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0531eau) { target=s->pc; goto dispatch; }
goto P_0c0531ea;
P_0c0531e8: /* original 64c3, guest PC 0x0c0531e8 */
if(!s->budget--) { s->failed_pc=0x0c0531e8u; return 0; }
r[4]=r[12];
goto P_0c0531ea;
P_0c0531ea: /* original 6bf3, guest PC 0x0c0531ea */
if(!s->budget--) { s->failed_pc=0x0c0531eau; return 0; }
r[11]=r[15];
goto P_0c0531ec;
P_0c0531ec: /* original d340, guest PC 0x0c0531ec */
if(!s->budget--) { s->failed_pc=0x0c0531ecu; return 0; }
r[3]=read(ram,0x0c0532f0u,4);
goto P_0c0531ee;
P_0c0531ee: /* original 6483, guest PC 0x0c0531ee */
if(!s->budget--) { s->failed_pc=0x0c0531eeu; return 0; }
r[4]=r[8];
goto P_0c0531f0;
P_0c0531f0: /* original 7b1c, guest PC 0x0c0531f0 */
if(!s->budget--) { s->failed_pc=0x0c0531f0u; return 0; }
r[11]+=0x0000001cu;
goto P_0c0531f2;
P_0c0531f2: /* original 65b3, guest PC 0x0c0531f2 */
if(!s->budget--) { s->failed_pc=0x0c0531f2u; return 0; }
r[5]=r[11];
goto P_0c0531f4;
P_0c0531f4: /* original 74ff, guest PC 0x0c0531f4 */
if(!s->budget--) { s->failed_pc=0x0c0531f4u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0531f6;
P_0c0531f6: /* original 430b, guest PC 0x0c0531f6 */
if(!s->budget--) { s->failed_pc=0x0c0531f6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0531fau;
write(ram,r[15]+12,r[4],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0531fau) { target=s->pc; goto dispatch; }
goto P_0c0531fa;
P_0c0531f8: /* original 1f43, guest PC 0x0c0531f8 */
if(!s->budget--) { s->failed_pc=0x0c0531f8u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c0531fa;
P_0c0531fa: /* original 51f3, guest PC 0x0c0531fa */
if(!s->budget--) { s->failed_pc=0x0c0531fau; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0531fc;
P_0c0531fc: /* original d23d, guest PC 0x0c0531fc */
if(!s->budget--) { s->failed_pc=0x0c0531fcu; return 0; }
r[2]=read(ram,0x0c0532f4u,4);
goto P_0c0531fe;
P_0c0531fe: /* original 420b, guest PC 0x0c0531fe */
if(!s->budget--) { s->failed_pc=0x0c0531feu; return 0; }
target=r[2];
r[16]=code_base|0x0c053202u;
r[0]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053202u) { target=s->pc; goto dispatch; }
goto P_0c053202;
P_0c053200: /* original 50f2, guest PC 0x0c053200 */
if(!s->budget--) { s->failed_pc=0x0c053200u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c053202;
P_0c053202: /* original 65e3, guest PC 0x0c053202 */
if(!s->budget--) { s->failed_pc=0x0c053202u; return 0; }
r[5]=r[14];
goto P_0c053204;
P_0c053204: /* original 1f01, guest PC 0x0c053204 */
if(!s->budget--) { s->failed_pc=0x0c053204u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c053206;
P_0c053206: /* original 3508, guest PC 0x0c053206 */
if(!s->budget--) { s->failed_pc=0x0c053206u; return 0; }
r[5]-=r[0];
goto P_0c053208;
P_0c053208: /* original 4515, guest PC 0x0c053208 */
if(!s->budget--) { s->failed_pc=0x0c053208u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c05320a;
P_0c05320a: /* original 8f0a, guest PC 0x0c05320a */
if(!s->budget--) { s->failed_pc=0x0c05320au; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(!cond) { goto P_0c053222; }
goto P_0c05320e;
P_0c05320c: /* original e400, guest PC 0x0c05320c */
if(!s->budget--) { s->failed_pc=0x0c05320cu; return 0; }
r[4]=0x00000000u;
goto P_0c05320e;
P_0c05320e: /* original 6043, guest PC 0x0c05320e */
if(!s->budget--) { s->failed_pc=0x0c05320eu; return 0; }
r[0]=r[4];
goto P_0c053210;
P_0c053210: /* original 0009, guest PC 0x0c053210 */
if(!s->budget--) { s->failed_pc=0x0c053210u; return 0; }
goto P_0c053212;
P_0c053212: /* original 7401, guest PC 0x0c053212 */
if(!s->budget--) { s->failed_pc=0x0c053212u; return 0; }
r[4]+=0x00000001u;
goto P_0c053214;
P_0c053214: /* original 53f1, guest PC 0x0c053214 */
if(!s->budget--) { s->failed_pc=0x0c053214u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053216;
P_0c053216: /* original 3453, guest PC 0x0c053216 */
if(!s->budget--) { s->failed_pc=0x0c053216u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c053218;
P_0c053218: /* original 330c, guest PC 0x0c053218 */
if(!s->budget--) { s->failed_pc=0x0c053218u; return 0; }
r[3]+=r[0];
goto P_0c05321a;
P_0c05321a: /* original 33bc, guest PC 0x0c05321a */
if(!s->budget--) { s->failed_pc=0x0c05321au; return 0; }
r[3]+=r[11];
goto P_0c05321c;
P_0c05321c: /* original 6330, guest PC 0x0c05321c */
if(!s->budget--) { s->failed_pc=0x0c05321cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c05321e;
P_0c05321e: /* original 8ff6, guest PC 0x0c05321e */
if(!s->budget--) { s->failed_pc=0x0c05321eu; return 0; }
cond=r[17]&1u;
write(ram,r[11]+r[0],r[3],1);
if(!cond) { goto P_0c05320e; }
goto P_0c053222;
P_0c053220: /* original 0b34, guest PC 0x0c053220 */
if(!s->budget--) { s->failed_pc=0x0c053220u; return 0; }
write(ram,r[11]+r[0],r[3],1);
goto P_0c053222;
P_0c053222: /* original 6543, guest PC 0x0c053222 */
if(!s->budget--) { s->failed_pc=0x0c053222u; return 0; }
r[5]=r[4];
goto P_0c053224;
P_0c053224: /* original 34e3, guest PC 0x0c053224 */
if(!s->budget--) { s->failed_pc=0x0c053224u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c053226;
P_0c053226: /* original 8d05, guest PC 0x0c053226 */
if(!s->budget--) { s->failed_pc=0x0c053226u; return 0; }
cond=r[17]&1u;
r[5]+=r[11];
if(cond) { goto P_0c053234; }
goto P_0c05322a;
P_0c053228: /* original 35bc, guest PC 0x0c053228 */
if(!s->budget--) { s->failed_pc=0x0c053228u; return 0; }
r[5]+=r[11];
goto P_0c05322a;
P_0c05322a: /* original 7401, guest PC 0x0c05322a */
if(!s->budget--) { s->failed_pc=0x0c05322au; return 0; }
r[4]+=0x00000001u;
goto P_0c05322c;
P_0c05322c: /* original 25d0, guest PC 0x0c05322c */
if(!s->budget--) { s->failed_pc=0x0c05322cu; return 0; }
write(ram,r[5],r[13],1);
goto P_0c05322e;
P_0c05322e: /* original 34e3, guest PC 0x0c05322e */
if(!s->budget--) { s->failed_pc=0x0c05322eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[14])!=0);
goto P_0c053230;
P_0c053230: /* original 8ffb, guest PC 0x0c053230 */
if(!s->budget--) { s->failed_pc=0x0c053230u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c05322a; }
goto P_0c053234;
P_0c053232: /* original 7501, guest PC 0x0c053232 */
if(!s->budget--) { s->failed_pc=0x0c053232u; return 0; }
r[5]+=0x00000001u;
goto P_0c053234;
P_0c053234: /* original 53f1, guest PC 0x0c053234 */
if(!s->budget--) { s->failed_pc=0x0c053234u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053236;
P_0c053236: /* original e508, guest PC 0x0c053236 */
if(!s->budget--) { s->failed_pc=0x0c053236u; return 0; }
r[5]=0x00000008u;
goto P_0c053238;
P_0c053238: /* original 4308, guest PC 0x0c053238 */
if(!s->budget--) { s->failed_pc=0x0c053238u; return 0; }
r[3]<<=2;
goto P_0c05323a;
P_0c05323a: /* original 4300, guest PC 0x0c05323a */
if(!s->budget--) { s->failed_pc=0x0c05323au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c05323c;
P_0c05323c: /* original 3838, guest PC 0x0c05323c */
if(!s->budget--) { s->failed_pc=0x0c05323cu; return 0; }
r[8]-=r[3];
goto P_0c05323e;
P_0c05323e: /* original 6683, guest PC 0x0c05323e */
if(!s->budget--) { s->failed_pc=0x0c05323eu; return 0; }
r[6]=r[8];
goto P_0c053240;
P_0c053240: /* original d32d, guest PC 0x0c053240 */
if(!s->budget--) { s->failed_pc=0x0c053240u; return 0; }
r[3]=read(ram,0x0c0532f8u,4);
goto P_0c053242;
P_0c053242: /* original 76ff, guest PC 0x0c053242 */
if(!s->budget--) { s->failed_pc=0x0c053242u; return 0; }
r[6]+=0xffffffffu;
goto P_0c053244;
P_0c053244: /* original 430b, guest PC 0x0c053244 */
if(!s->budget--) { s->failed_pc=0x0c053244u; return 0; }
target=r[3];
r[16]=code_base|0x0c053248u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053248u) { target=s->pc; goto dispatch; }
goto P_0c053248;
P_0c053246: /* original 64b3, guest PC 0x0c053246 */
if(!s->budget--) { s->failed_pc=0x0c053246u; return 0; }
r[4]=r[11];
goto P_0c053248;
P_0c053248: /* original 66a2, guest PC 0x0c053248 */
if(!s->budget--) { s->failed_pc=0x0c053248u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c05324a;
P_0c05324a: /* original 65f3, guest PC 0x0c05324a */
if(!s->budget--) { s->failed_pc=0x0c05324au; return 0; }
r[5]=r[15];
goto P_0c05324c;
P_0c05324c: /* original d32b, guest PC 0x0c05324c */
if(!s->budget--) { s->failed_pc=0x0c05324cu; return 0; }
r[3]=read(ram,0x0c0532fcu,4);
goto P_0c05324e;
P_0c05324e: /* original 6793, guest PC 0x0c05324e */
if(!s->budget--) { s->failed_pc=0x0c05324eu; return 0; }
r[7]=r[9];
goto P_0c053250;
P_0c053250: /* original 752c, guest PC 0x0c053250 */
if(!s->budget--) { s->failed_pc=0x0c053250u; return 0; }
r[5]+=0x0000002cu;
goto P_0c053252;
P_0c053252: /* original 430b, guest PC 0x0c053252 */
if(!s->budget--) { s->failed_pc=0x0c053252u; return 0; }
target=r[3];
r[16]=code_base|0x0c053256u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053256u) { target=s->pc; goto dispatch; }
goto P_0c053256;
P_0c053254: /* original 64f1, guest PC 0x0c053254 */
if(!s->budget--) { s->failed_pc=0x0c053254u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c053256;
P_0c053256: /* original 6ef3, guest PC 0x0c053256 */
if(!s->budget--) { s->failed_pc=0x0c053256u; return 0; }
r[14]=r[15];
goto P_0c053258;
P_0c053258: /* original dd29, guest PC 0x0c053258 */
if(!s->budget--) { s->failed_pc=0x0c053258u; return 0; }
r[13]=read(ram,0x0c053300u,4);
goto P_0c05325a;
P_0c05325a: /* original e608, guest PC 0x0c05325a */
if(!s->budget--) { s->failed_pc=0x0c05325au; return 0; }
r[6]=0x00000008u;
goto P_0c05325c;
P_0c05325c: /* original 7e14, guest PC 0x0c05325c */
if(!s->budget--) { s->failed_pc=0x0c05325cu; return 0; }
r[14]+=0x00000014u;
goto P_0c05325e;
P_0c05325e: /* original 6593, guest PC 0x0c05325e */
if(!s->budget--) { s->failed_pc=0x0c05325eu; return 0; }
r[5]=r[9];
goto P_0c053260;
P_0c053260: /* original 4d0b, guest PC 0x0c053260 */
if(!s->budget--) { s->failed_pc=0x0c053260u; return 0; }
target=r[13];
r[16]=code_base|0x0c053264u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053264u) { target=s->pc; goto dispatch; }
goto P_0c053264;
P_0c053262: /* original 64e3, guest PC 0x0c053262 */
if(!s->budget--) { s->failed_pc=0x0c053262u; return 0; }
r[4]=r[14];
goto P_0c053264;
P_0c053264: /* original d827, guest PC 0x0c053264 */
if(!s->budget--) { s->failed_pc=0x0c053264u; return 0; }
r[8]=read(ram,0x0c053304u,4);
goto P_0c053266;
P_0c053266: /* original e608, guest PC 0x0c053266 */
if(!s->budget--) { s->failed_pc=0x0c053266u; return 0; }
r[6]=0x00000008u;
goto P_0c053268;
P_0c053268: /* original 65c3, guest PC 0x0c053268 */
if(!s->budget--) { s->failed_pc=0x0c053268u; return 0; }
r[5]=r[12];
goto P_0c05326a;
P_0c05326a: /* original 480b, guest PC 0x0c05326a */
if(!s->budget--) { s->failed_pc=0x0c05326au; return 0; }
target=r[8];
r[16]=code_base|0x0c05326eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05326eu) { target=s->pc; goto dispatch; }
goto P_0c05326e;
P_0c05326c: /* original 64e3, guest PC 0x0c05326c */
if(!s->budget--) { s->failed_pc=0x0c05326cu; return 0; }
r[4]=r[14];
goto P_0c05326e;
P_0c05326e: /* original 4015, guest PC 0x0c05326e */
if(!s->budget--) { s->failed_pc=0x0c05326eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c053270;
P_0c053270: /* original 8f06, guest PC 0x0c053270 */
if(!s->budget--) { s->failed_pc=0x0c053270u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053280; }
goto P_0c053274;
P_0c053272: /* original 0009, guest PC 0x0c053272 */
if(!s->budget--) { s->failed_pc=0x0c053272u; return 0; }
goto P_0c053274;
P_0c053274: /* original e001, guest PC 0x0c053274 */
if(!s->budget--) { s->failed_pc=0x0c053274u; return 0; }
r[0]=0x00000001u;
goto P_0c053276;
P_0c053276: /* original 81f8, guest PC 0x0c053276 */
if(!s->budget--) { s->failed_pc=0x0c053276u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c053278;
P_0c053278: /* original 63a2, guest PC 0x0c053278 */
if(!s->budget--) { s->failed_pc=0x0c053278u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c05327a;
P_0c05327a: /* original 7301, guest PC 0x0c05327a */
if(!s->budget--) { s->failed_pc=0x0c05327au; return 0; }
r[3]+=0x00000001u;
goto P_0c05327c;
P_0c05327c: /* original afe4, guest PC 0x0c05327c */
if(!s->budget--) { s->failed_pc=0x0c05327cu; return 0; }
write(ram,r[10],r[3],4);
goto P_0c053248;
P_0c05327e: /* original 2a32, guest PC 0x0c05327e */
if(!s->budget--) { s->failed_pc=0x0c05327eu; return 0; }
write(ram,r[10],r[3],4);
goto P_0c053280;
P_0c053280: /* original e608, guest PC 0x0c053280 */
if(!s->budget--) { s->failed_pc=0x0c053280u; return 0; }
r[6]=0x00000008u;
goto P_0c053282;
P_0c053282: /* original 6593, guest PC 0x0c053282 */
if(!s->budget--) { s->failed_pc=0x0c053282u; return 0; }
r[5]=r[9];
goto P_0c053284;
P_0c053284: /* original 4d0b, guest PC 0x0c053284 */
if(!s->budget--) { s->failed_pc=0x0c053284u; return 0; }
target=r[13];
r[16]=code_base|0x0c053288u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053288u) { target=s->pc; goto dispatch; }
goto P_0c053288;
P_0c053286: /* original 64e3, guest PC 0x0c053286 */
if(!s->budget--) { s->failed_pc=0x0c053286u; return 0; }
r[4]=r[14];
goto P_0c053288;
P_0c053288: /* original e608, guest PC 0x0c053288 */
if(!s->budget--) { s->failed_pc=0x0c053288u; return 0; }
r[6]=0x00000008u;
goto P_0c05328a;
P_0c05328a: /* original 65c3, guest PC 0x0c05328a */
if(!s->budget--) { s->failed_pc=0x0c05328au; return 0; }
r[5]=r[12];
goto P_0c05328c;
P_0c05328c: /* original 480b, guest PC 0x0c05328c */
if(!s->budget--) { s->failed_pc=0x0c05328cu; return 0; }
target=r[8];
r[16]=code_base|0x0c053290u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053290u) { target=s->pc; goto dispatch; }
goto P_0c053290;
P_0c05328e: /* original 64e3, guest PC 0x0c05328e */
if(!s->budget--) { s->failed_pc=0x0c05328eu; return 0; }
r[4]=r[14];
goto P_0c053290;
P_0c053290: /* original 2008, guest PC 0x0c053290 */
if(!s->budget--) { s->failed_pc=0x0c053290u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053292;
P_0c053292: /* original 8f0c, guest PC 0x0c053292 */
if(!s->budget--) { s->failed_pc=0x0c053292u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0532ae; }
goto P_0c053296;
P_0c053294: /* original 0009, guest PC 0x0c053294 */
if(!s->budget--) { s->failed_pc=0x0c053294u; return 0; }
goto P_0c053296;
P_0c053296: /* original 6793, guest PC 0x0c053296 */
if(!s->budget--) { s->failed_pc=0x0c053296u; return 0; }
r[7]=r[9];
goto P_0c053298;
P_0c053298: /* original d318, guest PC 0x0c053298 */
if(!s->budget--) { s->failed_pc=0x0c053298u; return 0; }
r[3]=read(ram,0x0c0532fcu,4);
goto P_0c05329a;
P_0c05329a: /* original 65f3, guest PC 0x0c05329a */
if(!s->budget--) { s->failed_pc=0x0c05329au; return 0; }
r[5]=r[15];
goto P_0c05329c;
P_0c05329c: /* original 62a2, guest PC 0x0c05329c */
if(!s->budget--) { s->failed_pc=0x0c05329cu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c05329e;
P_0c05329e: /* original 752c, guest PC 0x0c05329e */
if(!s->budget--) { s->failed_pc=0x0c05329eu; return 0; }
r[5]+=0x0000002cu;
goto P_0c0532a0;
P_0c0532a0: /* original 7201, guest PC 0x0c0532a0 */
if(!s->budget--) { s->failed_pc=0x0c0532a0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0532a2;
P_0c0532a2: /* original 6623, guest PC 0x0c0532a2 */
if(!s->budget--) { s->failed_pc=0x0c0532a2u; return 0; }
r[6]=r[2];
goto P_0c0532a4;
P_0c0532a4: /* original 2a22, guest PC 0x0c0532a4 */
if(!s->budget--) { s->failed_pc=0x0c0532a4u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c0532a6;
P_0c0532a6: /* original 430b, guest PC 0x0c0532a6 */
if(!s->budget--) { s->failed_pc=0x0c0532a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0532aau;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0532aau) { target=s->pc; goto dispatch; }
goto P_0c0532aa;
P_0c0532a8: /* original 64f1, guest PC 0x0c0532a8 */
if(!s->budget--) { s->failed_pc=0x0c0532a8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c0532aa;
P_0c0532aa: /* original a013, guest PC 0x0c0532aa */
if(!s->budget--) { s->failed_pc=0x0c0532aau; return 0; }
goto P_0c0532d4;
P_0c0532ac: /* original 0009, guest PC 0x0c0532ac */
if(!s->budget--) { s->failed_pc=0x0c0532acu; return 0; }
goto P_0c0532ae;
P_0c0532ae: /* original e608, guest PC 0x0c0532ae */
if(!s->budget--) { s->failed_pc=0x0c0532aeu; return 0; }
r[6]=0x00000008u;
goto P_0c0532b0;
P_0c0532b0: /* original 6593, guest PC 0x0c0532b0 */
if(!s->budget--) { s->failed_pc=0x0c0532b0u; return 0; }
r[5]=r[9];
goto P_0c0532b2;
P_0c0532b2: /* original 4d0b, guest PC 0x0c0532b2 */
if(!s->budget--) { s->failed_pc=0x0c0532b2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0532b6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0532b6u) { target=s->pc; goto dispatch; }
goto P_0c0532b6;
P_0c0532b4: /* original 64e3, guest PC 0x0c0532b4 */
if(!s->budget--) { s->failed_pc=0x0c0532b4u; return 0; }
r[4]=r[14];
goto P_0c0532b6;
P_0c0532b6: /* original e608, guest PC 0x0c0532b6 */
if(!s->budget--) { s->failed_pc=0x0c0532b6u; return 0; }
r[6]=0x00000008u;
goto P_0c0532b8;
P_0c0532b8: /* original 65b3, guest PC 0x0c0532b8 */
if(!s->budget--) { s->failed_pc=0x0c0532b8u; return 0; }
r[5]=r[11];
goto P_0c0532ba;
P_0c0532ba: /* original 480b, guest PC 0x0c0532ba */
if(!s->budget--) { s->failed_pc=0x0c0532bau; return 0; }
target=r[8];
r[16]=code_base|0x0c0532beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0532beu) { target=s->pc; goto dispatch; }
goto P_0c0532be;
P_0c0532bc: /* original 64e3, guest PC 0x0c0532bc */
if(!s->budget--) { s->failed_pc=0x0c0532bcu; return 0; }
r[4]=r[14];
goto P_0c0532be;
P_0c0532be: /* original 4011, guest PC 0x0c0532be */
if(!s->budget--) { s->failed_pc=0x0c0532beu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c0532c0;
P_0c0532c0: /* original 8d08, guest PC 0x0c0532c0 */
if(!s->budget--) { s->failed_pc=0x0c0532c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0532d4; }
goto P_0c0532c4;
P_0c0532c2: /* original 0009, guest PC 0x0c0532c2 */
if(!s->budget--) { s->failed_pc=0x0c0532c2u; return 0; }
goto P_0c0532c4;
P_0c0532c4: /* original 85f8, guest PC 0x0c0532c4 */
if(!s->budget--) { s->failed_pc=0x0c0532c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c0532c6;
P_0c0532c6: /* original 2008, guest PC 0x0c0532c6 */
if(!s->budget--) { s->failed_pc=0x0c0532c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0532c8;
P_0c0532c8: /* original 8f04, guest PC 0x0c0532c8 */
if(!s->budget--) { s->failed_pc=0x0c0532c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0532d4; }
goto P_0c0532cc;
P_0c0532ca: /* original 0009, guest PC 0x0c0532ca */
if(!s->budget--) { s->failed_pc=0x0c0532cau; return 0; }
goto P_0c0532cc;
P_0c0532cc: /* original 62a2, guest PC 0x0c0532cc */
if(!s->budget--) { s->failed_pc=0x0c0532ccu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c0532ce;
P_0c0532ce: /* original 72ff, guest PC 0x0c0532ce */
if(!s->budget--) { s->failed_pc=0x0c0532ceu; return 0; }
r[2]+=0xffffffffu;
goto P_0c0532d0;
P_0c0532d0: /* original afba, guest PC 0x0c0532d0 */
if(!s->budget--) { s->failed_pc=0x0c0532d0u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c053248;
P_0c0532d2: /* original 2a22, guest PC 0x0c0532d2 */
if(!s->budget--) { s->failed_pc=0x0c0532d2u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c0532d4;
P_0c0532d4: /* original e000, guest PC 0x0c0532d4 */
if(!s->budget--) { s->failed_pc=0x0c0532d4u; return 0; }
r[0]=0x00000000u;
goto P_0c0532d6;
P_0c0532d6: /* original 7f34, guest PC 0x0c0532d6 */
if(!s->budget--) { s->failed_pc=0x0c0532d6u; return 0; }
r[15]+=0x00000034u;
goto P_0c0532d8;
P_0c0532d8: /* original 4f26, guest PC 0x0c0532d8 */
if(!s->budget--) { s->failed_pc=0x0c0532d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0532da;
P_0c0532da: /* original 68f6, guest PC 0x0c0532da */
if(!s->budget--) { s->failed_pc=0x0c0532dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0532dc;
P_0c0532dc: /* original 69f6, guest PC 0x0c0532dc */
if(!s->budget--) { s->failed_pc=0x0c0532dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0532de;
P_0c0532de: /* original 6af6, guest PC 0x0c0532de */
if(!s->budget--) { s->failed_pc=0x0c0532deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0532e0;
P_0c0532e0: /* original 6bf6, guest PC 0x0c0532e0 */
if(!s->budget--) { s->failed_pc=0x0c0532e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0532e2;
P_0c0532e2: /* original 6cf6, guest PC 0x0c0532e2 */
if(!s->budget--) { s->failed_pc=0x0c0532e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0532e4;
P_0c0532e4: /* original 6df6, guest PC 0x0c0532e4 */
if(!s->budget--) { s->failed_pc=0x0c0532e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0532e6;
P_0c0532e6: /* original 000b, guest PC 0x0c0532e6 */
if(!s->budget--) { s->failed_pc=0x0c0532e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0532e8: /* original 6ef6, guest PC 0x0c0532e8 */
if(!s->budget--) { s->failed_pc=0x0c0532e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0532eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0532eau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
