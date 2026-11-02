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
int vf3_away_batch63_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c069624u: goto P_0c069624;
case 0x0c069626u: goto P_0c069626;
case 0x0c069628u: goto P_0c069628;
case 0x0c06962au: goto P_0c06962a;
case 0x0c06962cu: goto P_0c06962c;
case 0x0c06962eu: goto P_0c06962e;
case 0x0c069630u: goto P_0c069630;
case 0x0c069632u: goto P_0c069632;
case 0x0c069634u: goto P_0c069634;
case 0x0c069636u: goto P_0c069636;
case 0x0c069638u: goto P_0c069638;
case 0x0c06963au: goto P_0c06963a;
case 0x0c06963cu: goto P_0c06963c;
case 0x0c06963eu: goto P_0c06963e;
case 0x0c069640u: goto P_0c069640;
case 0x0c069642u: goto P_0c069642;
case 0x0c069644u: goto P_0c069644;
case 0x0c069646u: goto P_0c069646;
case 0x0c069648u: goto P_0c069648;
case 0x0c06964au: goto P_0c06964a;
case 0x0c06964cu: goto P_0c06964c;
case 0x0c06964eu: goto P_0c06964e;
case 0x0c069650u: goto P_0c069650;
case 0x0c069652u: goto P_0c069652;
case 0x0c069654u: goto P_0c069654;
case 0x0c069656u: goto P_0c069656;
case 0x0c069658u: goto P_0c069658;
case 0x0c06965au: goto P_0c06965a;
case 0x0c06965cu: goto P_0c06965c;
case 0x0c06965eu: goto P_0c06965e;
case 0x0c069660u: goto P_0c069660;
case 0x0c069662u: goto P_0c069662;
case 0x0c069664u: goto P_0c069664;
case 0x0c069666u: goto P_0c069666;
case 0x0c069668u: goto P_0c069668;
case 0x0c06966au: goto P_0c06966a;
case 0x0c06966cu: goto P_0c06966c;
case 0x0c06966eu: goto P_0c06966e;
case 0x0c069670u: goto P_0c069670;
case 0x0c069672u: goto P_0c069672;
case 0x0c069674u: goto P_0c069674;
case 0x0c069676u: goto P_0c069676;
case 0x0c069678u: goto P_0c069678;
case 0x0c06967au: goto P_0c06967a;
case 0x0c06967cu: goto P_0c06967c;
case 0x0c06967eu: goto P_0c06967e;
case 0x0c069680u: goto P_0c069680;
case 0x0c069682u: goto P_0c069682;
case 0x0c069684u: goto P_0c069684;
case 0x0c069686u: goto P_0c069686;
case 0x0c069688u: goto P_0c069688;
case 0x0c06968au: goto P_0c06968a;
case 0x0c06968cu: goto P_0c06968c;
case 0x0c06968eu: goto P_0c06968e;
case 0x0c069690u: goto P_0c069690;
case 0x0c069692u: goto P_0c069692;
case 0x0c069694u: goto P_0c069694;
case 0x0c069696u: goto P_0c069696;
case 0x0c069698u: goto P_0c069698;
case 0x0c06969au: goto P_0c06969a;
case 0x0c06969cu: goto P_0c06969c;
case 0x0c06df8eu: goto P_0c06df8e;
case 0x0c06df90u: goto P_0c06df90;
case 0x0c06df92u: goto P_0c06df92;
case 0x0c06df94u: goto P_0c06df94;
case 0x0c06df96u: goto P_0c06df96;
case 0x0c06df98u: goto P_0c06df98;
case 0x0c06df9au: goto P_0c06df9a;
case 0x0c06df9cu: goto P_0c06df9c;
case 0x0c06df9eu: goto P_0c06df9e;
case 0x0c06dfa0u: goto P_0c06dfa0;
case 0x0c06dfa2u: goto P_0c06dfa2;
case 0x0c06dfa4u: goto P_0c06dfa4;
case 0x0c06dfa6u: goto P_0c06dfa6;
case 0x0c06dfa8u: goto P_0c06dfa8;
case 0x0c06dfaau: goto P_0c06dfaa;
case 0x0c06dfacu: goto P_0c06dfac;
case 0x0c06dfaeu: goto P_0c06dfae;
case 0x0c06dfb0u: goto P_0c06dfb0;
case 0x0c06dfb2u: goto P_0c06dfb2;
case 0x0c06dfb4u: goto P_0c06dfb4;
case 0x0c06dfb6u: goto P_0c06dfb6;
case 0x0c06dfb8u: goto P_0c06dfb8;
case 0x0c06dfbau: goto P_0c06dfba;
case 0x0c06dfbcu: goto P_0c06dfbc;
case 0x0c06dfbeu: goto P_0c06dfbe;
case 0x0c06dfc0u: goto P_0c06dfc0;
case 0x0c06e056u: goto P_0c06e056;
case 0x0c06e058u: goto P_0c06e058;
case 0x0c06e05au: goto P_0c06e05a;
case 0x0c06e05cu: goto P_0c06e05c;
case 0x0c06e05eu: goto P_0c06e05e;
case 0x0c06e060u: goto P_0c06e060;
case 0x0c06e062u: goto P_0c06e062;
case 0x0c06e064u: goto P_0c06e064;
case 0x0c06e066u: goto P_0c06e066;
case 0x0c06e068u: goto P_0c06e068;
case 0x0c06e06au: goto P_0c06e06a;
case 0x0c06e06cu: goto P_0c06e06c;
case 0x0c06e06eu: goto P_0c06e06e;
case 0x0c06e070u: goto P_0c06e070;
case 0x0c06e072u: goto P_0c06e072;
case 0x0c06e074u: goto P_0c06e074;
case 0x0c06e076u: goto P_0c06e076;
case 0x0c06e078u: goto P_0c06e078;
case 0x0c06e07au: goto P_0c06e07a;
case 0x0c06e07cu: goto P_0c06e07c;
case 0x0c06e07eu: goto P_0c06e07e;
case 0x0c06e080u: goto P_0c06e080;
case 0x0c06e082u: goto P_0c06e082;
case 0x0c06e084u: goto P_0c06e084;
case 0x0c06e086u: goto P_0c06e086;
case 0x0c06e088u: goto P_0c06e088;
case 0x0c06e08au: goto P_0c06e08a;
case 0x0c06e08cu: goto P_0c06e08c;
case 0x0c06e08eu: goto P_0c06e08e;
case 0x0c06e090u: goto P_0c06e090;
case 0x0c06e092u: goto P_0c06e092;
case 0x0c06e094u: goto P_0c06e094;
case 0x0c06e096u: goto P_0c06e096;
case 0x0c06e098u: goto P_0c06e098;
case 0x0c06e09au: goto P_0c06e09a;
case 0x0c06e09cu: goto P_0c06e09c;
case 0x0c06e09eu: goto P_0c06e09e;
case 0x0c06e0a0u: goto P_0c06e0a0;
case 0x0c06e0a2u: goto P_0c06e0a2;
case 0x0c06e0a4u: goto P_0c06e0a4;
case 0x0c06e0a6u: goto P_0c06e0a6;
case 0x0c06e0a8u: goto P_0c06e0a8;
case 0x0c06e0b8u: goto P_0c06e0b8;
case 0x0c06e0bau: goto P_0c06e0ba;
case 0x0c06e0bcu: goto P_0c06e0bc;
case 0x0c06e0beu: goto P_0c06e0be;
case 0x0c06e0c0u: goto P_0c06e0c0;
case 0x0c06e0c2u: goto P_0c06e0c2;
case 0x0c06e0c4u: goto P_0c06e0c4;
case 0x0c06e0c6u: goto P_0c06e0c6;
case 0x0c06e0c8u: goto P_0c06e0c8;
case 0x0c06e0cau: goto P_0c06e0ca;
case 0x0c06e0ccu: goto P_0c06e0cc;
case 0x0c06e0ceu: goto P_0c06e0ce;
case 0x0c06e0d0u: goto P_0c06e0d0;
case 0x0c06e0d2u: goto P_0c06e0d2;
case 0x0c06e0d4u: goto P_0c06e0d4;
case 0x0c06e0d6u: goto P_0c06e0d6;
case 0x0c06e0d8u: goto P_0c06e0d8;
case 0x0c06e0dau: goto P_0c06e0da;
case 0x0c06e0dcu: goto P_0c06e0dc;
case 0x0c06e0deu: goto P_0c06e0de;
case 0x0c06e0e0u: goto P_0c06e0e0;
case 0x0c06e0e2u: goto P_0c06e0e2;
case 0x0c06e0e4u: goto P_0c06e0e4;
case 0x0c06e0e6u: goto P_0c06e0e6;
case 0x0c06e0e8u: goto P_0c06e0e8;
case 0x0c06e0eau: goto P_0c06e0ea;
case 0x0c06e0ecu: goto P_0c06e0ec;
case 0x0c06e0eeu: goto P_0c06e0ee;
case 0x0c06e0f0u: goto P_0c06e0f0;
case 0x0c06e0f2u: goto P_0c06e0f2;
case 0x0c06e0f4u: goto P_0c06e0f4;
case 0x0c06e0f6u: goto P_0c06e0f6;
case 0x0c06e0f8u: goto P_0c06e0f8;
case 0x0c06e0fau: goto P_0c06e0fa;
case 0x0c06e0fcu: goto P_0c06e0fc;
case 0x0c06e0feu: goto P_0c06e0fe;
case 0x0c06e100u: goto P_0c06e100;
case 0x0c06e102u: goto P_0c06e102;
case 0x0c06e104u: goto P_0c06e104;
case 0x0c06e106u: goto P_0c06e106;
case 0x0c06e108u: goto P_0c06e108;
case 0x0c06e10au: goto P_0c06e10a;
case 0x0c06e10cu: goto P_0c06e10c;
case 0x0c06e10eu: goto P_0c06e10e;
case 0x0c06e110u: goto P_0c06e110;
case 0x0c06e112u: goto P_0c06e112;
case 0x0c06e114u: goto P_0c06e114;
case 0x0c06e116u: goto P_0c06e116;
case 0x0c06e118u: goto P_0c06e118;
case 0x0c06e11au: goto P_0c06e11a;
case 0x0c06e11cu: goto P_0c06e11c;
case 0x0c06e11eu: goto P_0c06e11e;
case 0x0c06e120u: goto P_0c06e120;
case 0x0c06e122u: goto P_0c06e122;
case 0x0c06e124u: goto P_0c06e124;
case 0x0c06e126u: goto P_0c06e126;
case 0x0c06e128u: goto P_0c06e128;
case 0x0c06e12au: goto P_0c06e12a;
case 0x0c06e12cu: goto P_0c06e12c;
case 0x0c06e12eu: goto P_0c06e12e;
case 0x0c06e130u: goto P_0c06e130;
case 0x0c06e132u: goto P_0c06e132;
case 0x0c06e134u: goto P_0c06e134;
case 0x0c06e136u: goto P_0c06e136;
case 0x0c06e138u: goto P_0c06e138;
case 0x0c06e13au: goto P_0c06e13a;
case 0x0c06e13cu: goto P_0c06e13c;
case 0x0c06e13eu: goto P_0c06e13e;
case 0x0c06e140u: goto P_0c06e140;
case 0x0c06e142u: goto P_0c06e142;
case 0x0c06e144u: goto P_0c06e144;
case 0x0c06e146u: goto P_0c06e146;
case 0x0c06e148u: goto P_0c06e148;
case 0x0c06e14au: goto P_0c06e14a;
case 0x0c06e14cu: goto P_0c06e14c;
case 0x0c06e14eu: goto P_0c06e14e;
case 0x0c06e150u: goto P_0c06e150;
case 0x0c06e152u: goto P_0c06e152;
case 0x0c06e154u: goto P_0c06e154;
case 0x0c06e156u: goto P_0c06e156;
case 0x0c06e158u: goto P_0c06e158;
case 0x0c06e15au: goto P_0c06e15a;
case 0x0c06e15cu: goto P_0c06e15c;
case 0x0c06e15eu: goto P_0c06e15e;
case 0x0c06e160u: goto P_0c06e160;
case 0x0c06e162u: goto P_0c06e162;
case 0x0c06e164u: goto P_0c06e164;
case 0x0c06e166u: goto P_0c06e166;
case 0x0c06e168u: goto P_0c06e168;
case 0x0c06e16au: goto P_0c06e16a;
case 0x0c06e16cu: goto P_0c06e16c;
case 0x0c06e16eu: goto P_0c06e16e;
case 0x0c06e170u: goto P_0c06e170;
case 0x0c06e172u: goto P_0c06e172;
case 0x0c06e174u: goto P_0c06e174;
case 0x0c06e176u: goto P_0c06e176;
case 0x0c06e178u: goto P_0c06e178;
case 0x0c06e17au: goto P_0c06e17a;
case 0x0c06e17cu: goto P_0c06e17c;
case 0x0c06e17eu: goto P_0c06e17e;
case 0x0c06e180u: goto P_0c06e180;
case 0x0c06e182u: goto P_0c06e182;
case 0x0c06e184u: goto P_0c06e184;
case 0x0c06e186u: goto P_0c06e186;
case 0x0c06e188u: goto P_0c06e188;
case 0x0c06e18au: goto P_0c06e18a;
case 0x0c06e18cu: goto P_0c06e18c;
case 0x0c06e18eu: goto P_0c06e18e;
case 0x0c06e190u: goto P_0c06e190;
case 0x0c06e192u: goto P_0c06e192;
case 0x0c06e194u: goto P_0c06e194;
case 0x0c06e196u: goto P_0c06e196;
case 0x0c06e198u: goto P_0c06e198;
case 0x0c06e19au: goto P_0c06e19a;
case 0x0c06e19cu: goto P_0c06e19c;
case 0x0c06e19eu: goto P_0c06e19e;
case 0x0c06e1a0u: goto P_0c06e1a0;
case 0x0c06e1a2u: goto P_0c06e1a2;
case 0x0c06e1a4u: goto P_0c06e1a4;
case 0x0c06e1a6u: goto P_0c06e1a6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c069624: /* original f38d, guest PC 0x0c069624 */
if(!s->budget--) { s->failed_pc=0x0c069624u; return 0; }
fr[3]=0;
goto P_0c069626;
P_0c069626: /* original f534, guest PC 0x0c069626 */
if(!s->budget--) { s->failed_pc=0x0c069626u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])==as_float(fr[3]))!=0);
goto P_0c069628;
P_0c069628: /* original 8b03, guest PC 0x0c069628 */
if(!s->budget--) { s->failed_pc=0x0c069628u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962a;
P_0c06962a: /* original f434, guest PC 0x0c06962a */
if(!s->budget--) { s->failed_pc=0x0c06962au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06962c;
P_0c06962c: /* original 8b01, guest PC 0x0c06962c */
if(!s->budget--) { s->failed_pc=0x0c06962cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069632; }
goto P_0c06962e;
P_0c06962e: /* original 000b, guest PC 0x0c06962e */
if(!s->budget--) { s->failed_pc=0x0c06962eu; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c069630: /* original e000, guest PC 0x0c069630 */
if(!s->budget--) { s->failed_pc=0x0c069630u; return 0; }
r[0]=0x00000000u;
goto P_0c069632;
P_0c069632: /* original f38d, guest PC 0x0c069632 */
if(!s->budget--) { s->failed_pc=0x0c069632u; return 0; }
fr[3]=0;
goto P_0c069634;
P_0c069634: /* original f355, guest PC 0x0c069634 */
if(!s->budget--) { s->failed_pc=0x0c069634u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c069636;
P_0c069636: /* original 8f03, guest PC 0x0c069636 */
if(!s->budget--) { s->failed_pc=0x0c069636u; return 0; }
cond=r[17]&1u;
fr[3]=0;
if(!cond) { goto P_0c069640; }
goto P_0c06963a;
P_0c069638: /* original f38d, guest PC 0x0c069638 */
if(!s->budget--) { s->failed_pc=0x0c069638u; return 0; }
fr[3]=0;
goto P_0c06963a;
P_0c06963a: /* original f65c, guest PC 0x0c06963a */
if(!s->budget--) { s->failed_pc=0x0c06963au; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06963c;
P_0c06963c: /* original a001, guest PC 0x0c06963c */
if(!s->budget--) { s->failed_pc=0x0c06963cu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069642;
P_0c06963e: /* original f64d, guest PC 0x0c06963e */
if(!s->budget--) { s->failed_pc=0x0c06963eu; return 0; }
fr[6]^=0x80000000u;
goto P_0c069640;
P_0c069640: /* original f65c, guest PC 0x0c069640 */
if(!s->budget--) { s->failed_pc=0x0c069640u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c069642;
P_0c069642: /* original f345, guest PC 0x0c069642 */
if(!s->budget--) { s->failed_pc=0x0c069642u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069644;
P_0c069644: /* original 8b02, guest PC 0x0c069644 */
if(!s->budget--) { s->failed_pc=0x0c069644u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06964c; }
goto P_0c069646;
P_0c069646: /* original f74c, guest PC 0x0c069646 */
if(!s->budget--) { s->failed_pc=0x0c069646u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c069648;
P_0c069648: /* original a001, guest PC 0x0c069648 */
if(!s->budget--) { s->failed_pc=0x0c069648u; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964e;
P_0c06964a: /* original f74d, guest PC 0x0c06964a */
if(!s->budget--) { s->failed_pc=0x0c06964au; return 0; }
fr[7]^=0x80000000u;
goto P_0c06964c;
P_0c06964c: /* original f74c, guest PC 0x0c06964c */
if(!s->budget--) { s->failed_pc=0x0c06964cu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06964e;
P_0c06964e: /* original f675, guest PC 0x0c06964e */
if(!s->budget--) { s->failed_pc=0x0c06964eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c069650;
P_0c069650: /* original 8b02, guest PC 0x0c069650 */
if(!s->budget--) { s->failed_pc=0x0c069650u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069658; }
goto P_0c069652;
P_0c069652: /* original f87c, guest PC 0x0c069652 */
if(!s->budget--) { s->failed_pc=0x0c069652u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c069654;
P_0c069654: /* original a002, guest PC 0x0c069654 */
if(!s->budget--) { s->failed_pc=0x0c069654u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c06965c;
P_0c069656: /* original f863, guest PC 0x0c069656 */
if(!s->budget--) { s->failed_pc=0x0c069656u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c069658;
P_0c069658: /* original f86c, guest PC 0x0c069658 */
if(!s->budget--) { s->failed_pc=0x0c069658u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c06965a;
P_0c06965a: /* original f873, guest PC 0x0c06965a */
if(!s->budget--) { s->failed_pc=0x0c06965au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'/');
goto P_0c06965c;
P_0c06965c: /* original c711, guest PC 0x0c06965c */
if(!s->budget--) { s->failed_pc=0x0c06965cu; return 0; }
r[0]=code_base|0x000696a4u;
goto P_0c06965e;
P_0c06965e: /* original f28c, guest PC 0x0c06965e */
if(!s->budget--) { s->failed_pc=0x0c06965eu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c069660;
P_0c069660: /* original f308, guest PC 0x0c069660 */
if(!s->budget--) { s->failed_pc=0x0c069660u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c069662;
P_0c069662: /* original d011, guest PC 0x0c069662 */
if(!s->budget--) { s->failed_pc=0x0c069662u; return 0; }
r[0]=read(ram,0x0c0696a8u,4);
goto P_0c069664;
P_0c069664: /* original f232, guest PC 0x0c069664 */
if(!s->budget--) { s->failed_pc=0x0c069664u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c069666;
P_0c069666: /* original f23d, guest PC 0x0c069666 */
if(!s->budget--) { s->failed_pc=0x0c069666u; return 0; }
r[53]=truncate_float(fr[2]);
goto P_0c069668;
P_0c069668: /* original 045a, guest PC 0x0c069668 */
if(!s->budget--) { s->failed_pc=0x0c069668u; return 0; }
r[4]=r[53];
goto P_0c06966a;
P_0c06966a: /* original 4400, guest PC 0x0c06966a */
if(!s->budget--) { s->failed_pc=0x0c06966au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06966c;
P_0c06966c: /* original f765, guest PC 0x0c06966c */
if(!s->budget--) { s->failed_pc=0x0c06966cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c06966e;
P_0c06966e: /* original 8f03, guest PC 0x0c06966e */
if(!s->budget--) { s->failed_pc=0x0c06966eu; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!cond) { goto P_0c069678; }
goto P_0c069672;
P_0c069670: /* original 044d, guest PC 0x0c069670 */
if(!s->budget--) { s->failed_pc=0x0c069670u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c069672;
P_0c069672: /* original 9214, guest PC 0x0c069672 */
if(!s->budget--) { s->failed_pc=0x0c069672u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06969eu,2);
goto P_0c069674;
P_0c069674: /* original 3248, guest PC 0x0c069674 */
if(!s->budget--) { s->failed_pc=0x0c069674u; return 0; }
r[2]-=r[4];
goto P_0c069676;
P_0c069676: /* original 6423, guest PC 0x0c069676 */
if(!s->budget--) { s->failed_pc=0x0c069676u; return 0; }
r[4]=r[2];
goto P_0c069678;
P_0c069678: /* original f38d, guest PC 0x0c069678 */
if(!s->budget--) { s->failed_pc=0x0c069678u; return 0; }
fr[3]=0;
goto P_0c06967a;
P_0c06967a: /* original f355, guest PC 0x0c06967a */
if(!s->budget--) { s->failed_pc=0x0c06967au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c06967c;
P_0c06967c: /* original 8904, guest PC 0x0c06967c */
if(!s->budget--) { s->failed_pc=0x0c06967cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069688; }
goto P_0c06967e;
P_0c06967e: /* original f38d, guest PC 0x0c06967e */
if(!s->budget--) { s->failed_pc=0x0c06967eu; return 0; }
fr[3]=0;
goto P_0c069680;
P_0c069680: /* original f345, guest PC 0x0c069680 */
if(!s->budget--) { s->failed_pc=0x0c069680u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c069682;
P_0c069682: /* original 8b09, guest PC 0x0c069682 */
if(!s->budget--) { s->failed_pc=0x0c069682u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c069698; }
goto P_0c069684;
P_0c069684: /* original a008, guest PC 0x0c069684 */
if(!s->budget--) { s->failed_pc=0x0c069684u; return 0; }
r[4]=0u-r[4];
goto P_0c069698;
P_0c069686: /* original 644b, guest PC 0x0c069686 */
if(!s->budget--) { s->failed_pc=0x0c069686u; return 0; }
r[4]=0u-r[4];
goto P_0c069688;
P_0c069688: /* original f345, guest PC 0x0c069688 */
if(!s->budget--) { s->failed_pc=0x0c069688u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c06968a;
P_0c06968a: /* original 8903, guest PC 0x0c06968a */
if(!s->budget--) { s->failed_pc=0x0c06968au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c069694; }
goto P_0c06968c;
P_0c06968c: /* original d207, guest PC 0x0c06968c */
if(!s->budget--) { s->failed_pc=0x0c06968cu; return 0; }
r[2]=read(ram,0x0c0696acu,4);
goto P_0c06968e;
P_0c06968e: /* original 3248, guest PC 0x0c06968e */
if(!s->budget--) { s->failed_pc=0x0c06968eu; return 0; }
r[2]-=r[4];
goto P_0c069690;
P_0c069690: /* original a002, guest PC 0x0c069690 */
if(!s->budget--) { s->failed_pc=0x0c069690u; return 0; }
r[4]=r[2];
goto P_0c069698;
P_0c069692: /* original 6423, guest PC 0x0c069692 */
if(!s->budget--) { s->failed_pc=0x0c069692u; return 0; }
r[4]=r[2];
goto P_0c069694;
P_0c069694: /* original 9104, guest PC 0x0c069694 */
if(!s->budget--) { s->failed_pc=0x0c069694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0696a0u,2);
goto P_0c069696;
P_0c069696: /* original 341c, guest PC 0x0c069696 */
if(!s->budget--) { s->failed_pc=0x0c069696u; return 0; }
r[4]+=r[1];
goto P_0c069698;
P_0c069698: /* original 6043, guest PC 0x0c069698 */
if(!s->budget--) { s->failed_pc=0x0c069698u; return 0; }
r[0]=r[4];
goto P_0c06969a;
P_0c06969a: /* original 000b, guest PC 0x0c06969a */
if(!s->budget--) { s->failed_pc=0x0c06969au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06969c: /* original 0009, guest PC 0x0c06969c */
if(!s->budget--) { s->failed_pc=0x0c06969cu; return 0; }
if(!vf3_matrix_family(0x0c06969eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06969eu; return 0; } return 1;
P_0c06df8e: /* original 4f22, guest PC 0x0c06df8e */
if(!s->budget--) { s->failed_pc=0x0c06df8eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06df90;
P_0c06df90: /* original 7fec, guest PC 0x0c06df90 */
if(!s->budget--) { s->failed_pc=0x0c06df90u; return 0; }
r[15]+=0xffffffecu;
goto P_0c06df92;
P_0c06df92: /* original 1f41, guest PC 0x0c06df92 */
if(!s->budget--) { s->failed_pc=0x0c06df92u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06df94;
P_0c06df94: /* original 1f52, guest PC 0x0c06df94 */
if(!s->budget--) { s->failed_pc=0x0c06df94u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c06df96;
P_0c06df96: /* original 1f63, guest PC 0x0c06df96 */
if(!s->budget--) { s->failed_pc=0x0c06df96u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c06df98;
P_0c06df98: /* original e600, guest PC 0x0c06df98 */
if(!s->budget--) { s->failed_pc=0x0c06df98u; return 0; }
r[6]=0x00000000u;
goto P_0c06df9a;
P_0c06df9a: /* original 2f72, guest PC 0x0c06df9a */
if(!s->budget--) { s->failed_pc=0x0c06df9au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c06df9c;
P_0c06df9c: /* original 6563, guest PC 0x0c06df9c */
if(!s->budget--) { s->failed_pc=0x0c06df9cu; return 0; }
r[5]=r[6];
goto P_0c06df9e;
P_0c06df9e: /* original d20b, guest PC 0x0c06df9e */
if(!s->budget--) { s->failed_pc=0x0c06df9eu; return 0; }
r[2]=read(ram,0x0c06dfccu,4);
goto P_0c06dfa0;
P_0c06dfa0: /* original 6322, guest PC 0x0c06dfa0 */
if(!s->budget--) { s->failed_pc=0x0c06dfa0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c06dfa2;
P_0c06dfa2: /* original 1f34, guest PC 0x0c06dfa2 */
if(!s->budget--) { s->failed_pc=0x0c06dfa2u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c06dfa4;
P_0c06dfa4: /* original 51f6, guest PC 0x0c06dfa4 */
if(!s->budget--) { s->failed_pc=0x0c06dfa4u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c06dfa6;
P_0c06dfa6: /* original 2f16, guest PC 0x0c06dfa6 */
if(!s->budget--) { s->failed_pc=0x0c06dfa6u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dfa8;
P_0c06dfa8: /* original 53f1, guest PC 0x0c06dfa8 */
if(!s->budget--) { s->failed_pc=0x0c06dfa8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06dfaa;
P_0c06dfaa: /* original 2f36, guest PC 0x0c06dfaa */
if(!s->budget--) { s->failed_pc=0x0c06dfaau; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dfac;
P_0c06dfac: /* original 51f5, guest PC 0x0c06dfac */
if(!s->budget--) { s->failed_pc=0x0c06dfacu; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c06dfae;
P_0c06dfae: /* original 2f16, guest PC 0x0c06dfae */
if(!s->budget--) { s->failed_pc=0x0c06dfaeu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dfb0;
P_0c06dfb0: /* original 53f5, guest PC 0x0c06dfb0 */
if(!s->budget--) { s->failed_pc=0x0c06dfb0u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06dfb2;
P_0c06dfb2: /* original 2f36, guest PC 0x0c06dfb2 */
if(!s->budget--) { s->failed_pc=0x0c06dfb2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06dfb4;
P_0c06dfb4: /* original 57f5, guest PC 0x0c06dfb4 */
if(!s->budget--) { s->failed_pc=0x0c06dfb4u; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c06dfb6;
P_0c06dfb6: /* original b04e, guest PC 0x0c06dfb6 */
if(!s->budget--) { s->failed_pc=0x0c06dfb6u; return 0; }
target=code_base|0x0c06e056u; r[16]=code_base|0x0c06dfbau;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06dfbau) { target=s->pc; goto dispatch; }
goto P_0c06dfba;
P_0c06dfb8: /* original 54f8, guest PC 0x0c06dfb8 */
if(!s->budget--) { s->failed_pc=0x0c06dfb8u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c06dfba;
P_0c06dfba: /* original 7f24, guest PC 0x0c06dfba */
if(!s->budget--) { s->failed_pc=0x0c06dfbau; return 0; }
r[15]+=0x00000024u;
goto P_0c06dfbc;
P_0c06dfbc: /* original 4f26, guest PC 0x0c06dfbc */
if(!s->budget--) { s->failed_pc=0x0c06dfbcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06dfbe;
P_0c06dfbe: /* original 000b, guest PC 0x0c06dfbe */
if(!s->budget--) { s->failed_pc=0x0c06dfbeu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06dfc0: /* original 0009, guest PC 0x0c06dfc0 */
if(!s->budget--) { s->failed_pc=0x0c06dfc0u; return 0; }
if(!vf3_matrix_family(0x0c06dfc2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06dfc2u; return 0; } return 1;
P_0c06e056: /* original 2fe6, guest PC 0x0c06e056 */
if(!s->budget--) { s->failed_pc=0x0c06e056u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e058;
P_0c06e058: /* original e004, guest PC 0x0c06e058 */
if(!s->budget--) { s->failed_pc=0x0c06e058u; return 0; }
r[0]=0x00000004u;
goto P_0c06e05a;
P_0c06e05a: /* original 2fd6, guest PC 0x0c06e05a */
if(!s->budget--) { s->failed_pc=0x0c06e05au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06e05c;
P_0c06e05c: /* original 6e53, guest PC 0x0c06e05c */
if(!s->budget--) { s->failed_pc=0x0c06e05cu; return 0; }
r[14]=r[5];
goto P_0c06e05e;
P_0c06e05e: /* original fffb, guest PC 0x0c06e05e */
if(!s->budget--) { s->failed_pc=0x0c06e05eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06e060;
P_0c06e060: /* original ffeb, guest PC 0x0c06e060 */
if(!s->budget--) { s->failed_pc=0x0c06e060u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06e062;
P_0c06e062: /* original ffdb, guest PC 0x0c06e062 */
if(!s->budget--) { s->failed_pc=0x0c06e062u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06e064;
P_0c06e064: /* original ffcb, guest PC 0x0c06e064 */
if(!s->budget--) { s->failed_pc=0x0c06e064u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06e066;
P_0c06e066: /* original 4f22, guest PC 0x0c06e066 */
if(!s->budget--) { s->failed_pc=0x0c06e066u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06e068;
P_0c06e068: /* original 7fe8, guest PC 0x0c06e068 */
if(!s->budget--) { s->failed_pc=0x0c06e068u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c06e06a;
P_0c06e06a: /* original 1f75, guest PC 0x0c06e06a */
if(!s->budget--) { s->failed_pc=0x0c06e06au; return 0; }
write(ram,r[15]+20,r[7],4);
goto P_0c06e06c;
P_0c06e06c: /* original ff4a, guest PC 0x0c06e06c */
if(!s->budget--) { s->failed_pc=0x0c06e06cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c06e06e;
P_0c06e06e: /* original ff57, guest PC 0x0c06e06e */
if(!s->budget--) { s->failed_pc=0x0c06e06eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c06e070;
P_0c06e070: /* original e008, guest PC 0x0c06e070 */
if(!s->budget--) { s->failed_pc=0x0c06e070u; return 0; }
r[0]=0x00000008u;
goto P_0c06e072;
P_0c06e072: /* original ff67, guest PC 0x0c06e072 */
if(!s->budget--) { s->failed_pc=0x0c06e072u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c06e074;
P_0c06e074: /* original e00c, guest PC 0x0c06e074 */
if(!s->budget--) { s->failed_pc=0x0c06e074u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e076;
P_0c06e076: /* original ff77, guest PC 0x0c06e076 */
if(!s->budget--) { s->failed_pc=0x0c06e076u; return 0; }
vf3_matrix_store(s,ram,7,r[15]+r[0]);
goto P_0c06e078;
P_0c06e078: /* original e004, guest PC 0x0c06e078 */
if(!s->budget--) { s->failed_pc=0x0c06e078u; return 0; }
r[0]=0x00000004u;
goto P_0c06e07a;
P_0c06e07a: /* original f9f6, guest PC 0x0c06e07a */
if(!s->budget--) { s->failed_pc=0x0c06e07au; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c06e07c;
P_0c06e07c: /* original e008, guest PC 0x0c06e07c */
if(!s->budget--) { s->failed_pc=0x0c06e07cu; return 0; }
r[0]=0x00000008u;
goto P_0c06e07e;
P_0c06e07e: /* original f8f6, guest PC 0x0c06e07e */
if(!s->budget--) { s->failed_pc=0x0c06e07eu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c06e080;
P_0c06e080: /* original e008, guest PC 0x0c06e080 */
if(!s->budget--) { s->failed_pc=0x0c06e080u; return 0; }
r[0]=0x00000008u;
goto P_0c06e082;
P_0c06e082: /* original f1f6, guest PC 0x0c06e082 */
if(!s->budget--) { s->failed_pc=0x0c06e082u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c06e084;
P_0c06e084: /* original e004, guest PC 0x0c06e084 */
if(!s->budget--) { s->failed_pc=0x0c06e084u; return 0; }
r[0]=0x00000004u;
goto P_0c06e086;
P_0c06e086: /* original f5f6, guest PC 0x0c06e086 */
if(!s->budget--) { s->failed_pc=0x0c06e086u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c06e088;
P_0c06e088: /* original f2f8, guest PC 0x0c06e088 */
if(!s->budget--) { s->failed_pc=0x0c06e088u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c06e08a;
P_0c06e08a: /* original f512, guest PC 0x0c06e08a */
if(!s->budget--) { s->failed_pc=0x0c06e08au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'*');
goto P_0c06e08c;
P_0c06e08c: /* original f37c, guest PC 0x0c06e08c */
if(!s->budget--) { s->failed_pc=0x0c06e08cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06e08e;
P_0c06e08e: /* original f821, guest PC 0x0c06e08e */
if(!s->budget--) { s->failed_pc=0x0c06e08eu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c06e090;
P_0c06e090: /* original f232, guest PC 0x0c06e090 */
if(!s->budget--) { s->failed_pc=0x0c06e090u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c06e092;
P_0c06e092: /* original f931, guest PC 0x0c06e092 */
if(!s->budget--) { s->failed_pc=0x0c06e092u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[3],r[18],'-');
goto P_0c06e094;
P_0c06e094: /* original f35c, guest PC 0x0c06e094 */
if(!s->budget--) { s->failed_pc=0x0c06e094u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06e096;
P_0c06e096: /* original 9008, guest PC 0x0c06e096 */
if(!s->budget--) { s->failed_pc=0x0c06e096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06e0aau,2);
goto P_0c06e098;
P_0c06e098: /* original f52c, guest PC 0x0c06e098 */
if(!s->budget--) { s->failed_pc=0x0c06e098u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c06e09a;
P_0c06e09a: /* original f531, guest PC 0x0c06e09a */
if(!s->budget--) { s->failed_pc=0x0c06e09au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06e09c;
P_0c06e09c: /* original 044e, guest PC 0x0c06e09c */
if(!s->budget--) { s->failed_pc=0x0c06e09cu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c06e09e;
P_0c06e09e: /* original dd05, guest PC 0x0c06e09e */
if(!s->budget--) { s->failed_pc=0x0c06e09eu; return 0; }
r[13]=read(ram,0x0c06e0b4u,4);
goto P_0c06e0a0;
P_0c06e0a0: /* original 6546, guest PC 0x0c06e0a0 */
if(!s->budget--) { s->failed_pc=0x0c06e0a0u; return 0; }
tmp=read(ram,r[4],4);
r[4]+=4;
r[5]=tmp;
goto P_0c06e0a2;
P_0c06e0a2: /* original ff49, guest PC 0x0c06e0a2 */
if(!s->budget--) { s->failed_pc=0x0c06e0a2u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e0a4;
P_0c06e0a4: /* original fe49, guest PC 0x0c06e0a4 */
if(!s->budget--) { s->failed_pc=0x0c06e0a4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e0a6;
P_0c06e0a6: /* original a068, guest PC 0x0c06e0a6 */
if(!s->budget--) { s->failed_pc=0x0c06e0a6u; return 0; }
r[7]=0x00000001u;
goto P_0c06e17a;
P_0c06e0a8: /* original e701, guest PC 0x0c06e0a8 */
if(!s->budget--) { s->failed_pc=0x0c06e0a8u; return 0; }
r[7]=0x00000001u;
if(!vf3_matrix_family(0x0c06e0aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e0aau; return 0; } return 1;
P_0c06e0b8: /* original fdfc, guest PC 0x0c06e0b8 */
if(!s->budget--) { s->failed_pc=0x0c06e0b8u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c06e0ba;
P_0c06e0ba: /* original e004, guest PC 0x0c06e0ba */
if(!s->budget--) { s->failed_pc=0x0c06e0bau; return 0; }
r[0]=0x00000004u;
goto P_0c06e0bc;
P_0c06e0bc: /* original ff49, guest PC 0x0c06e0bc */
if(!s->budget--) { s->failed_pc=0x0c06e0bcu; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e0be;
P_0c06e0be: /* original fcec, guest PC 0x0c06e0be */
if(!s->budget--) { s->failed_pc=0x0c06e0beu; return 0; }
vf3_matrix_move(s,12,14);
goto P_0c06e0c0;
P_0c06e0c0: /* original f4fc, guest PC 0x0c06e0c0 */
if(!s->budget--) { s->failed_pc=0x0c06e0c0u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c06e0c2;
P_0c06e0c2: /* original f4c2, guest PC 0x0c06e0c2 */
if(!s->budget--) { s->failed_pc=0x0c06e0c2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'*');
goto P_0c06e0c4;
P_0c06e0c4: /* original fe49, guest PC 0x0c06e0c4 */
if(!s->budget--) { s->failed_pc=0x0c06e0c4u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c06e0c6;
P_0c06e0c6: /* original f3dc, guest PC 0x0c06e0c6 */
if(!s->budget--) { s->failed_pc=0x0c06e0c6u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c06e0c8;
P_0c06e0c8: /* original f3e2, guest PC 0x0c06e0c8 */
if(!s->budget--) { s->failed_pc=0x0c06e0c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[14],r[18],'*');
goto P_0c06e0ca;
P_0c06e0ca: /* original f6cc, guest PC 0x0c06e0ca */
if(!s->budget--) { s->failed_pc=0x0c06e0cau; return 0; }
vf3_matrix_move(s,6,12);
goto P_0c06e0cc;
P_0c06e0cc: /* original f24c, guest PC 0x0c06e0cc */
if(!s->budget--) { s->failed_pc=0x0c06e0ccu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06e0ce;
P_0c06e0ce: /* original f6e1, guest PC 0x0c06e0ce */
if(!s->budget--) { s->failed_pc=0x0c06e0ceu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'-');
goto P_0c06e0d0;
P_0c06e0d0: /* original f7fc, guest PC 0x0c06e0d0 */
if(!s->budget--) { s->failed_pc=0x0c06e0d0u; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c06e0d2;
P_0c06e0d2: /* original f7d1, guest PC 0x0c06e0d2 */
if(!s->budget--) { s->failed_pc=0x0c06e0d2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[13],r[18],'-');
goto P_0c06e0d4;
P_0c06e0d4: /* original f43c, guest PC 0x0c06e0d4 */
if(!s->budget--) { s->failed_pc=0x0c06e0d4u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06e0d6;
P_0c06e0d6: /* original f421, guest PC 0x0c06e0d6 */
if(!s->budget--) { s->failed_pc=0x0c06e0d6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'-');
goto P_0c06e0d8;
P_0c06e0d8: /* original f3f8, guest PC 0x0c06e0d8 */
if(!s->budget--) { s->failed_pc=0x0c06e0d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c06e0da;
P_0c06e0da: /* original f06c, guest PC 0x0c06e0da */
if(!s->budget--) { s->failed_pc=0x0c06e0dau; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c06e0dc;
P_0c06e0dc: /* original f2f6, guest PC 0x0c06e0dc */
if(!s->budget--) { s->failed_pc=0x0c06e0dcu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e0de;
P_0c06e0de: /* original e008, guest PC 0x0c06e0de */
if(!s->budget--) { s->failed_pc=0x0c06e0deu; return 0; }
r[0]=0x00000008u;
goto P_0c06e0e0;
P_0c06e0e0: /* original fa4c, guest PC 0x0c06e0e0 */
if(!s->budget--) { s->failed_pc=0x0c06e0e0u; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c06e0e2;
P_0c06e0e2: /* original fa3e, guest PC 0x0c06e0e2 */
if(!s->budget--) { s->failed_pc=0x0c06e0e2u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[3],fr[10],r[18]);
goto P_0c06e0e4;
P_0c06e0e4: /* original f07c, guest PC 0x0c06e0e4 */
if(!s->budget--) { s->failed_pc=0x0c06e0e4u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e0e6;
P_0c06e0e6: /* original f3ac, guest PC 0x0c06e0e6 */
if(!s->budget--) { s->failed_pc=0x0c06e0e6u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c06e0e8;
P_0c06e0e8: /* original f32e, guest PC 0x0c06e0e8 */
if(!s->budget--) { s->failed_pc=0x0c06e0e8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c06e0ea;
P_0c06e0ea: /* original f06c, guest PC 0x0c06e0ea */
if(!s->budget--) { s->failed_pc=0x0c06e0eau; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c06e0ec;
P_0c06e0ec: /* original fa4c, guest PC 0x0c06e0ec */
if(!s->budget--) { s->failed_pc=0x0c06e0ecu; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c06e0ee;
P_0c06e0ee: /* original fb3c, guest PC 0x0c06e0ee */
if(!s->budget--) { s->failed_pc=0x0c06e0eeu; return 0; }
vf3_matrix_move(s,11,3);
goto P_0c06e0f0;
P_0c06e0f0: /* original f3f6, guest PC 0x0c06e0f0 */
if(!s->budget--) { s->failed_pc=0x0c06e0f0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e0f2;
P_0c06e0f2: /* original e00c, guest PC 0x0c06e0f2 */
if(!s->budget--) { s->failed_pc=0x0c06e0f2u; return 0; }
r[0]=0x0000000cu;
goto P_0c06e0f4;
P_0c06e0f4: /* original fa3e, guest PC 0x0c06e0f4 */
if(!s->budget--) { s->failed_pc=0x0c06e0f4u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[3],fr[10],r[18]);
goto P_0c06e0f6;
P_0c06e0f6: /* original f3ac, guest PC 0x0c06e0f6 */
if(!s->budget--) { s->failed_pc=0x0c06e0f6u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c06e0f8;
P_0c06e0f8: /* original f2f6, guest PC 0x0c06e0f8 */
if(!s->budget--) { s->failed_pc=0x0c06e0f8u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c06e0fa;
P_0c06e0fa: /* original f07c, guest PC 0x0c06e0fa */
if(!s->budget--) { s->failed_pc=0x0c06e0fau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06e0fc;
P_0c06e0fc: /* original f32e, guest PC 0x0c06e0fc */
if(!s->budget--) { s->failed_pc=0x0c06e0fcu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c06e0fe;
P_0c06e0fe: /* original fa3c, guest PC 0x0c06e0fe */
if(!s->budget--) { s->failed_pc=0x0c06e0feu; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c06e100;
P_0c06e100: /* original fba2, guest PC 0x0c06e100 */
if(!s->budget--) { s->failed_pc=0x0c06e100u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'*');
goto P_0c06e102;
P_0c06e102: /* original f38d, guest PC 0x0c06e102 */
if(!s->budget--) { s->failed_pc=0x0c06e102u; return 0; }
fr[3]=0;
goto P_0c06e104;
P_0c06e104: /* original fb35, guest PC 0x0c06e104 */
if(!s->budget--) { s->failed_pc=0x0c06e104u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
goto P_0c06e106;
P_0c06e106: /* original 8937, guest PC 0x0c06e106 */
if(!s->budget--) { s->failed_pc=0x0c06e106u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e178; }
goto P_0c06e108;
P_0c06e108: /* original f09c, guest PC 0x0c06e108 */
if(!s->budget--) { s->failed_pc=0x0c06e108u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06e10a;
P_0c06e10a: /* original fa5c, guest PC 0x0c06e10a */
if(!s->budget--) { s->failed_pc=0x0c06e10au; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e10c;
P_0c06e10c: /* original fade, guest PC 0x0c06e10c */
if(!s->budget--) { s->failed_pc=0x0c06e10cu; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[13],fr[10],r[18]);
goto P_0c06e10e;
P_0c06e10e: /* original f08c, guest PC 0x0c06e10e */
if(!s->budget--) { s->failed_pc=0x0c06e10eu; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c06e110;
P_0c06e110: /* original f3ac, guest PC 0x0c06e110 */
if(!s->budget--) { s->failed_pc=0x0c06e110u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c06e112;
P_0c06e112: /* original f3ce, guest PC 0x0c06e112 */
if(!s->budget--) { s->failed_pc=0x0c06e112u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[12],fr[3],r[18]);
goto P_0c06e114;
P_0c06e114: /* original f09c, guest PC 0x0c06e114 */
if(!s->budget--) { s->failed_pc=0x0c06e114u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06e116;
P_0c06e116: /* original fa5c, guest PC 0x0c06e116 */
if(!s->budget--) { s->failed_pc=0x0c06e116u; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e118;
P_0c06e118: /* original fafe, guest PC 0x0c06e118 */
if(!s->budget--) { s->failed_pc=0x0c06e118u; return 0; }
fr[10]=vf3_fpu_mac(fr[0],fr[15],fr[10],r[18]);
goto P_0c06e11a;
P_0c06e11a: /* original f08c, guest PC 0x0c06e11a */
if(!s->budget--) { s->failed_pc=0x0c06e11au; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c06e11c;
P_0c06e11c: /* original fb3c, guest PC 0x0c06e11c */
if(!s->budget--) { s->failed_pc=0x0c06e11cu; return 0; }
vf3_matrix_move(s,11,3);
goto P_0c06e11e;
P_0c06e11e: /* original f38d, guest PC 0x0c06e11e */
if(!s->budget--) { s->failed_pc=0x0c06e11eu; return 0; }
fr[3]=0;
goto P_0c06e120;
P_0c06e120: /* original f2ac, guest PC 0x0c06e120 */
if(!s->budget--) { s->failed_pc=0x0c06e120u; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c06e122;
P_0c06e122: /* original f2ee, guest PC 0x0c06e122 */
if(!s->budget--) { s->failed_pc=0x0c06e122u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[14],fr[2],r[18]);
goto P_0c06e124;
P_0c06e124: /* original fa2c, guest PC 0x0c06e124 */
if(!s->budget--) { s->failed_pc=0x0c06e124u; return 0; }
vf3_matrix_move(s,10,2);
goto P_0c06e126;
P_0c06e126: /* original fba2, guest PC 0x0c06e126 */
if(!s->budget--) { s->failed_pc=0x0c06e126u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[10],r[18],'*');
goto P_0c06e128;
P_0c06e128: /* original fb35, guest PC 0x0c06e128 */
if(!s->budget--) { s->failed_pc=0x0c06e128u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[3]))!=0);
goto P_0c06e12a;
P_0c06e12a: /* original 8925, guest PC 0x0c06e12a */
if(!s->budget--) { s->failed_pc=0x0c06e12au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06e178; }
goto P_0c06e12c;
P_0c06e12c: /* original fa5c, guest PC 0x0c06e12c */
if(!s->budget--) { s->failed_pc=0x0c06e12cu; return 0; }
vf3_matrix_move(s,10,5);
goto P_0c06e12e;
P_0c06e12e: /* original fa72, guest PC 0x0c06e12e */
if(!s->budget--) { s->failed_pc=0x0c06e12eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[7],r[18],'*');
goto P_0c06e130;
P_0c06e130: /* original f38c, guest PC 0x0c06e130 */
if(!s->budget--) { s->failed_pc=0x0c06e130u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c06e132;
P_0c06e132: /* original f342, guest PC 0x0c06e132 */
if(!s->budget--) { s->failed_pc=0x0c06e132u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c06e134;
P_0c06e134: /* original f862, guest PC 0x0c06e134 */
if(!s->budget--) { s->failed_pc=0x0c06e134u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'*');
goto P_0c06e136;
P_0c06e136: /* original e010, guest PC 0x0c06e136 */
if(!s->budget--) { s->failed_pc=0x0c06e136u; return 0; }
r[0]=0x00000010u;
goto P_0c06e138;
P_0c06e138: /* original f562, guest PC 0x0c06e138 */
if(!s->budget--) { s->failed_pc=0x0c06e138u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c06e13a;
P_0c06e13a: /* original 6e73, guest PC 0x0c06e13a */
if(!s->budget--) { s->failed_pc=0x0c06e13au; return 0; }
r[14]=r[7];
goto P_0c06e13c;
P_0c06e13c: /* original f2ac, guest PC 0x0c06e13c */
if(!s->budget--) { s->failed_pc=0x0c06e13cu; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c06e13e;
P_0c06e13e: /* original fa3c, guest PC 0x0c06e13e */
if(!s->budget--) { s->failed_pc=0x0c06e13eu; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c06e140;
P_0c06e140: /* original fa21, guest PC 0x0c06e140 */
if(!s->budget--) { s->failed_pc=0x0c06e140u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[2],r[18],'-');
goto P_0c06e142;
P_0c06e142: /* original ff87, guest PC 0x0c06e142 */
if(!s->budget--) { s->failed_pc=0x0c06e142u; return 0; }
vf3_matrix_store(s,ram,8,r[15]+r[0]);
goto P_0c06e144;
P_0c06e144: /* original e010, guest PC 0x0c06e144 */
if(!s->budget--) { s->failed_pc=0x0c06e144u; return 0; }
r[0]=0x00000010u;
goto P_0c06e146;
P_0c06e146: /* original fb9c, guest PC 0x0c06e146 */
if(!s->budget--) { s->failed_pc=0x0c06e146u; return 0; }
vf3_matrix_move(s,11,9);
goto P_0c06e148;
P_0c06e148: /* original fb72, guest PC 0x0c06e148 */
if(!s->budget--) { s->failed_pc=0x0c06e148u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[7],r[18],'*');
goto P_0c06e14a;
P_0c06e14a: /* original f942, guest PC 0x0c06e14a */
if(!s->budget--) { s->failed_pc=0x0c06e14au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'*');
goto P_0c06e14c;
P_0c06e14c: /* original f38c, guest PC 0x0c06e14c */
if(!s->budget--) { s->failed_pc=0x0c06e14cu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c06e14e;
P_0c06e14e: /* original f8bc, guest PC 0x0c06e14e */
if(!s->budget--) { s->failed_pc=0x0c06e14eu; return 0; }
vf3_matrix_move(s,8,11);
goto P_0c06e150;
P_0c06e150: /* original f831, guest PC 0x0c06e150 */
if(!s->budget--) { s->failed_pc=0x0c06e150u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c06e152;
P_0c06e152: /* original fa83, guest PC 0x0c06e152 */
if(!s->budget--) { s->failed_pc=0x0c06e152u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[8],r[18],'/');
goto P_0c06e154;
P_0c06e154: /* original ffaa, guest PC 0x0c06e154 */
if(!s->budget--) { s->failed_pc=0x0c06e154u; return 0; }
vf3_matrix_store(s,ram,10,r[15]);
goto P_0c06e156;
P_0c06e156: /* original f35c, guest PC 0x0c06e156 */
if(!s->budget--) { s->failed_pc=0x0c06e156u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06e158;
P_0c06e158: /* original f59c, guest PC 0x0c06e158 */
if(!s->budget--) { s->failed_pc=0x0c06e158u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c06e15a;
P_0c06e15a: /* original f531, guest PC 0x0c06e15a */
if(!s->budget--) { s->failed_pc=0x0c06e15au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06e15c;
P_0c06e15c: /* original f3bc, guest PC 0x0c06e15c */
if(!s->budget--) { s->failed_pc=0x0c06e15cu; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c06e15e;
P_0c06e15e: /* original f4bc, guest PC 0x0c06e15e */
if(!s->budget--) { s->failed_pc=0x0c06e15eu; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c06e160;
P_0c06e160: /* original f4f6, guest PC 0x0c06e160 */
if(!s->budget--) { s->failed_pc=0x0c06e160u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c06e162;
P_0c06e162: /* original e004, guest PC 0x0c06e162 */
if(!s->budget--) { s->failed_pc=0x0c06e162u; return 0; }
r[0]=0x00000004u;
goto P_0c06e164;
P_0c06e164: /* original f431, guest PC 0x0c06e164 */
if(!s->budget--) { s->failed_pc=0x0c06e164u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c06e166;
P_0c06e166: /* original f543, guest PC 0x0c06e166 */
if(!s->budget--) { s->failed_pc=0x0c06e166u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c06e168;
P_0c06e168: /* original ff57, guest PC 0x0c06e168 */
if(!s->budget--) { s->failed_pc=0x0c06e168u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c06e16a;
P_0c06e16a: /* original f5ec, guest PC 0x0c06e16a */
if(!s->budget--) { s->failed_pc=0x0c06e16au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c06e16c;
P_0c06e16c: /* original f5c1, guest PC 0x0c06e16c */
if(!s->budget--) { s->failed_pc=0x0c06e16cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[12],r[18],'-');
goto P_0c06e16e;
P_0c06e16e: /* original f4dc, guest PC 0x0c06e16e */
if(!s->budget--) { s->failed_pc=0x0c06e16eu; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06e170;
P_0c06e170: /* original 4d0b, guest PC 0x0c06e170 */
if(!s->budget--) { s->failed_pc=0x0c06e170u; return 0; }
target=r[13];
r[16]=code_base|0x0c06e174u;
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06e174u) { target=s->pc; goto dispatch; }
goto P_0c06e174;
P_0c06e172: /* original f4f1, guest PC 0x0c06e172 */
if(!s->budget--) { s->failed_pc=0x0c06e172u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'-');
goto P_0c06e174;
P_0c06e174: /* original a003, guest PC 0x0c06e174 */
if(!s->budget--) { s->failed_pc=0x0c06e174u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c06e17e;
P_0c06e176: /* original 660f, guest PC 0x0c06e176 */
if(!s->budget--) { s->failed_pc=0x0c06e176u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c06e178;
P_0c06e178: /* original 75ff, guest PC 0x0c06e178 */
if(!s->budget--) { s->failed_pc=0x0c06e178u; return 0; }
r[5]+=0xffffffffu;
goto P_0c06e17a;
P_0c06e17a: /* original 2558, guest PC 0x0c06e17a */
if(!s->budget--) { s->failed_pc=0x0c06e17au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06e17c;
P_0c06e17c: /* original 8b9c, guest PC 0x0c06e17c */
if(!s->budget--) { s->failed_pc=0x0c06e17cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06e0b8; }
goto P_0c06e17e;
P_0c06e17e: /* original 53ff, guest PC 0x0c06e17e */
if(!s->budget--) { s->failed_pc=0x0c06e17eu; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c06e180;
P_0c06e180: /* original e040, guest PC 0x0c06e180 */
if(!s->budget--) { s->failed_pc=0x0c06e180u; return 0; }
r[0]=0x00000040u;
goto P_0c06e182;
P_0c06e182: /* original 23e2, guest PC 0x0c06e182 */
if(!s->budget--) { s->failed_pc=0x0c06e182u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c06e184;
P_0c06e184: /* original 03fe, guest PC 0x0c06e184 */
if(!s->budget--) { s->failed_pc=0x0c06e184u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c06e186;
P_0c06e186: /* original e004, guest PC 0x0c06e186 */
if(!s->budget--) { s->failed_pc=0x0c06e186u; return 0; }
r[0]=0x00000004u;
goto P_0c06e188;
P_0c06e188: /* original 2362, guest PC 0x0c06e188 */
if(!s->budget--) { s->failed_pc=0x0c06e188u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c06e18a;
P_0c06e18a: /* original f3f8, guest PC 0x0c06e18a */
if(!s->budget--) { s->failed_pc=0x0c06e18au; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c06e18c;
P_0c06e18c: /* original 53f5, guest PC 0x0c06e18c */
if(!s->budget--) { s->failed_pc=0x0c06e18cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c06e18e;
P_0c06e18e: /* original f33a, guest PC 0x0c06e18e */
if(!s->budget--) { s->failed_pc=0x0c06e18eu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c06e190;
P_0c06e190: /* original f3f6, guest PC 0x0c06e190 */
if(!s->budget--) { s->failed_pc=0x0c06e190u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c06e192;
P_0c06e192: /* original 53fe, guest PC 0x0c06e192 */
if(!s->budget--) { s->failed_pc=0x0c06e192u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c06e194;
P_0c06e194: /* original 7f18, guest PC 0x0c06e194 */
if(!s->budget--) { s->failed_pc=0x0c06e194u; return 0; }
r[15]+=0x00000018u;
goto P_0c06e196;
P_0c06e196: /* original 4f26, guest PC 0x0c06e196 */
if(!s->budget--) { s->failed_pc=0x0c06e196u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06e198;
P_0c06e198: /* original f33a, guest PC 0x0c06e198 */
if(!s->budget--) { s->failed_pc=0x0c06e198u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c06e19a;
P_0c06e19a: /* original fcf9, guest PC 0x0c06e19a */
if(!s->budget--) { s->failed_pc=0x0c06e19au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e19c;
P_0c06e19c: /* original fdf9, guest PC 0x0c06e19c */
if(!s->budget--) { s->failed_pc=0x0c06e19cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e19e;
P_0c06e19e: /* original fef9, guest PC 0x0c06e19e */
if(!s->budget--) { s->failed_pc=0x0c06e19eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e1a0;
P_0c06e1a0: /* original fff9, guest PC 0x0c06e1a0 */
if(!s->budget--) { s->failed_pc=0x0c06e1a0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06e1a2;
P_0c06e1a2: /* original 6df6, guest PC 0x0c06e1a2 */
if(!s->budget--) { s->failed_pc=0x0c06e1a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06e1a4;
P_0c06e1a4: /* original 000b, guest PC 0x0c06e1a4 */
if(!s->budget--) { s->failed_pc=0x0c06e1a4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06e1a6: /* original 6ef6, guest PC 0x0c06e1a6 */
if(!s->budget--) { s->failed_pc=0x0c06e1a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06e1a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06e1a8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
