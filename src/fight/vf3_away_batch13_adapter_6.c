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
int vf3_away_batch13_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c084050u: goto P_0c084050;
case 0x0c084052u: goto P_0c084052;
case 0x0c084054u: goto P_0c084054;
case 0x0c084056u: goto P_0c084056;
case 0x0c084058u: goto P_0c084058;
case 0x0c08405au: goto P_0c08405a;
case 0x0c08405cu: goto P_0c08405c;
case 0x0c08405eu: goto P_0c08405e;
case 0x0c084060u: goto P_0c084060;
case 0x0c084062u: goto P_0c084062;
case 0x0c084064u: goto P_0c084064;
case 0x0c084066u: goto P_0c084066;
case 0x0c084068u: goto P_0c084068;
case 0x0c08406au: goto P_0c08406a;
case 0x0c08406cu: goto P_0c08406c;
case 0x0c08406eu: goto P_0c08406e;
case 0x0c084070u: goto P_0c084070;
case 0x0c084072u: goto P_0c084072;
case 0x0c084074u: goto P_0c084074;
case 0x0c084076u: goto P_0c084076;
case 0x0c084078u: goto P_0c084078;
case 0x0c08407au: goto P_0c08407a;
case 0x0c08407cu: goto P_0c08407c;
case 0x0c08407eu: goto P_0c08407e;
case 0x0c084080u: goto P_0c084080;
case 0x0c084082u: goto P_0c084082;
case 0x0c084084u: goto P_0c084084;
case 0x0c084086u: goto P_0c084086;
case 0x0c084088u: goto P_0c084088;
case 0x0c08408au: goto P_0c08408a;
case 0x0c08408cu: goto P_0c08408c;
case 0x0c08408eu: goto P_0c08408e;
case 0x0c084090u: goto P_0c084090;
case 0x0c084092u: goto P_0c084092;
case 0x0c084094u: goto P_0c084094;
case 0x0c084096u: goto P_0c084096;
case 0x0c084098u: goto P_0c084098;
case 0x0c08409au: goto P_0c08409a;
case 0x0c08409cu: goto P_0c08409c;
case 0x0c08409eu: goto P_0c08409e;
case 0x0c0840a0u: goto P_0c0840a0;
case 0x0c0840a2u: goto P_0c0840a2;
case 0x0c0840a4u: goto P_0c0840a4;
case 0x0c0840a6u: goto P_0c0840a6;
case 0x0c0840a8u: goto P_0c0840a8;
case 0x0c0840aau: goto P_0c0840aa;
case 0x0c0840acu: goto P_0c0840ac;
case 0x0c0840aeu: goto P_0c0840ae;
case 0x0c0840b0u: goto P_0c0840b0;
case 0x0c0840b2u: goto P_0c0840b2;
case 0x0c0840b4u: goto P_0c0840b4;
case 0x0c0840b6u: goto P_0c0840b6;
case 0x0c0840b8u: goto P_0c0840b8;
case 0x0c0840bau: goto P_0c0840ba;
case 0x0c0840bcu: goto P_0c0840bc;
case 0x0c0840beu: goto P_0c0840be;
case 0x0c0840c0u: goto P_0c0840c0;
case 0x0c0840c2u: goto P_0c0840c2;
case 0x0c0840c4u: goto P_0c0840c4;
case 0x0c0840c6u: goto P_0c0840c6;
case 0x0c0840c8u: goto P_0c0840c8;
case 0x0c0840cau: goto P_0c0840ca;
case 0x0c0840ccu: goto P_0c0840cc;
case 0x0c0840ceu: goto P_0c0840ce;
case 0x0c0840d0u: goto P_0c0840d0;
case 0x0c0840d2u: goto P_0c0840d2;
case 0x0c0840d4u: goto P_0c0840d4;
case 0x0c0840d6u: goto P_0c0840d6;
case 0x0c0840d8u: goto P_0c0840d8;
case 0x0c0840dau: goto P_0c0840da;
case 0x0c0840dcu: goto P_0c0840dc;
case 0x0c0840deu: goto P_0c0840de;
case 0x0c0840e0u: goto P_0c0840e0;
case 0x0c0840e2u: goto P_0c0840e2;
case 0x0c0840e4u: goto P_0c0840e4;
case 0x0c0840e6u: goto P_0c0840e6;
case 0x0c0840e8u: goto P_0c0840e8;
case 0x0c0840eau: goto P_0c0840ea;
case 0x0c0840ecu: goto P_0c0840ec;
case 0x0c0840eeu: goto P_0c0840ee;
case 0x0c0840f0u: goto P_0c0840f0;
case 0x0c0840f2u: goto P_0c0840f2;
case 0x0c0840f4u: goto P_0c0840f4;
case 0x0c0840f6u: goto P_0c0840f6;
case 0x0c0840f8u: goto P_0c0840f8;
case 0x0c0840fau: goto P_0c0840fa;
case 0x0c0840fcu: goto P_0c0840fc;
case 0x0c0840feu: goto P_0c0840fe;
case 0x0c084100u: goto P_0c084100;
case 0x0c084102u: goto P_0c084102;
case 0x0c084104u: goto P_0c084104;
case 0x0c084106u: goto P_0c084106;
case 0x0c084108u: goto P_0c084108;
case 0x0c08410au: goto P_0c08410a;
case 0x0c08410cu: goto P_0c08410c;
case 0x0c08410eu: goto P_0c08410e;
case 0x0c084110u: goto P_0c084110;
case 0x0c084112u: goto P_0c084112;
case 0x0c084114u: goto P_0c084114;
case 0x0c084116u: goto P_0c084116;
case 0x0c084118u: goto P_0c084118;
case 0x0c08411au: goto P_0c08411a;
case 0x0c08411cu: goto P_0c08411c;
case 0x0c08411eu: goto P_0c08411e;
case 0x0c084120u: goto P_0c084120;
case 0x0c084122u: goto P_0c084122;
case 0x0c084124u: goto P_0c084124;
case 0x0c084126u: goto P_0c084126;
case 0x0c084128u: goto P_0c084128;
case 0x0c08412au: goto P_0c08412a;
case 0x0c08412cu: goto P_0c08412c;
case 0x0c08412eu: goto P_0c08412e;
case 0x0c084130u: goto P_0c084130;
case 0x0c084132u: goto P_0c084132;
case 0x0c084134u: goto P_0c084134;
case 0x0c084136u: goto P_0c084136;
case 0x0c084138u: goto P_0c084138;
case 0x0c08413au: goto P_0c08413a;
case 0x0c08413cu: goto P_0c08413c;
case 0x0c08413eu: goto P_0c08413e;
case 0x0c084140u: goto P_0c084140;
case 0x0c084142u: goto P_0c084142;
case 0x0c084144u: goto P_0c084144;
case 0x0c084146u: goto P_0c084146;
case 0x0c084148u: goto P_0c084148;
case 0x0c08414au: goto P_0c08414a;
case 0x0c08414cu: goto P_0c08414c;
case 0x0c08414eu: goto P_0c08414e;
case 0x0c084150u: goto P_0c084150;
case 0x0c084152u: goto P_0c084152;
case 0x0c084154u: goto P_0c084154;
case 0x0c084156u: goto P_0c084156;
case 0x0c084158u: goto P_0c084158;
case 0x0c08415au: goto P_0c08415a;
case 0x0c08415cu: goto P_0c08415c;
case 0x0c08415eu: goto P_0c08415e;
case 0x0c084160u: goto P_0c084160;
case 0x0c084162u: goto P_0c084162;
case 0x0c084164u: goto P_0c084164;
case 0x0c084166u: goto P_0c084166;
case 0x0c084168u: goto P_0c084168;
case 0x0c08416au: goto P_0c08416a;
case 0x0c08416cu: goto P_0c08416c;
case 0x0c08416eu: goto P_0c08416e;
case 0x0c084170u: goto P_0c084170;
case 0x0c084172u: goto P_0c084172;
case 0x0c084174u: goto P_0c084174;
case 0x0c084176u: goto P_0c084176;
case 0x0c084178u: goto P_0c084178;
case 0x0c08417au: goto P_0c08417a;
case 0x0c08417cu: goto P_0c08417c;
case 0x0c08417eu: goto P_0c08417e;
case 0x0c084180u: goto P_0c084180;
case 0x0c084182u: goto P_0c084182;
case 0x0c084184u: goto P_0c084184;
case 0x0c084186u: goto P_0c084186;
case 0x0c084188u: goto P_0c084188;
case 0x0c08418au: goto P_0c08418a;
case 0x0c08418cu: goto P_0c08418c;
case 0x0c0841dcu: goto P_0c0841dc;
case 0x0c0841deu: goto P_0c0841de;
case 0x0c0841e0u: goto P_0c0841e0;
case 0x0c0841e2u: goto P_0c0841e2;
case 0x0c0841e4u: goto P_0c0841e4;
case 0x0c0841e6u: goto P_0c0841e6;
case 0x0c0841e8u: goto P_0c0841e8;
case 0x0c0841eau: goto P_0c0841ea;
case 0x0c0841ecu: goto P_0c0841ec;
case 0x0c0841eeu: goto P_0c0841ee;
case 0x0c0841f0u: goto P_0c0841f0;
case 0x0c0841f2u: goto P_0c0841f2;
case 0x0c0841f4u: goto P_0c0841f4;
case 0x0c0841f6u: goto P_0c0841f6;
case 0x0c0841f8u: goto P_0c0841f8;
case 0x0c0841fau: goto P_0c0841fa;
case 0x0c0841fcu: goto P_0c0841fc;
case 0x0c0841feu: goto P_0c0841fe;
case 0x0c084200u: goto P_0c084200;
case 0x0c084202u: goto P_0c084202;
case 0x0c084204u: goto P_0c084204;
case 0x0c084206u: goto P_0c084206;
case 0x0c084208u: goto P_0c084208;
case 0x0c08420au: goto P_0c08420a;
case 0x0c08420cu: goto P_0c08420c;
case 0x0c08420eu: goto P_0c08420e;
case 0x0c084210u: goto P_0c084210;
case 0x0c084212u: goto P_0c084212;
case 0x0c084214u: goto P_0c084214;
case 0x0c084216u: goto P_0c084216;
case 0x0c084218u: goto P_0c084218;
case 0x0c08421au: goto P_0c08421a;
case 0x0c08421cu: goto P_0c08421c;
case 0x0c08421eu: goto P_0c08421e;
case 0x0c084220u: goto P_0c084220;
case 0x0c084222u: goto P_0c084222;
case 0x0c084224u: goto P_0c084224;
case 0x0c084226u: goto P_0c084226;
case 0x0c084228u: goto P_0c084228;
case 0x0c08422au: goto P_0c08422a;
case 0x0c08422cu: goto P_0c08422c;
case 0x0c08422eu: goto P_0c08422e;
case 0x0c084230u: goto P_0c084230;
case 0x0c084232u: goto P_0c084232;
case 0x0c084234u: goto P_0c084234;
case 0x0c084236u: goto P_0c084236;
case 0x0c084238u: goto P_0c084238;
case 0x0c08423au: goto P_0c08423a;
case 0x0c08423cu: goto P_0c08423c;
case 0x0c08423eu: goto P_0c08423e;
case 0x0c084240u: goto P_0c084240;
case 0x0c084242u: goto P_0c084242;
case 0x0c084244u: goto P_0c084244;
case 0x0c084246u: goto P_0c084246;
case 0x0c084248u: goto P_0c084248;
case 0x0c08424au: goto P_0c08424a;
case 0x0c08424cu: goto P_0c08424c;
case 0x0c08424eu: goto P_0c08424e;
case 0x0c084250u: goto P_0c084250;
case 0x0c084252u: goto P_0c084252;
case 0x0c084254u: goto P_0c084254;
case 0x0c084256u: goto P_0c084256;
case 0x0c084258u: goto P_0c084258;
case 0x0c08425au: goto P_0c08425a;
case 0x0c08425cu: goto P_0c08425c;
case 0x0c08425eu: goto P_0c08425e;
case 0x0c084260u: goto P_0c084260;
case 0x0c084262u: goto P_0c084262;
case 0x0c084264u: goto P_0c084264;
case 0x0c084266u: goto P_0c084266;
case 0x0c084268u: goto P_0c084268;
case 0x0c08426au: goto P_0c08426a;
case 0x0c08426cu: goto P_0c08426c;
case 0x0c08426eu: goto P_0c08426e;
case 0x0c084270u: goto P_0c084270;
case 0x0c084272u: goto P_0c084272;
case 0x0c084274u: goto P_0c084274;
case 0x0c084276u: goto P_0c084276;
case 0x0c084278u: goto P_0c084278;
case 0x0c08427au: goto P_0c08427a;
case 0x0c08427cu: goto P_0c08427c;
case 0x0c08427eu: goto P_0c08427e;
case 0x0c084280u: goto P_0c084280;
case 0x0c084282u: goto P_0c084282;
case 0x0c084284u: goto P_0c084284;
case 0x0c084286u: goto P_0c084286;
case 0x0c084288u: goto P_0c084288;
case 0x0c08428au: goto P_0c08428a;
case 0x0c08428cu: goto P_0c08428c;
case 0x0c08428eu: goto P_0c08428e;
case 0x0c084290u: goto P_0c084290;
case 0x0c084292u: goto P_0c084292;
case 0x0c084294u: goto P_0c084294;
case 0x0c084296u: goto P_0c084296;
case 0x0c084298u: goto P_0c084298;
case 0x0c08429au: goto P_0c08429a;
case 0x0c08429cu: goto P_0c08429c;
case 0x0c08429eu: goto P_0c08429e;
case 0x0c0842a0u: goto P_0c0842a0;
case 0x0c0842a2u: goto P_0c0842a2;
case 0x0c0842a4u: goto P_0c0842a4;
case 0x0c0842a6u: goto P_0c0842a6;
case 0x0c0842a8u: goto P_0c0842a8;
case 0x0c0842aau: goto P_0c0842aa;
case 0x0c0842acu: goto P_0c0842ac;
case 0x0c0842aeu: goto P_0c0842ae;
case 0x0c0842b0u: goto P_0c0842b0;
case 0x0c0842b2u: goto P_0c0842b2;
case 0x0c0842b4u: goto P_0c0842b4;
case 0x0c0842b6u: goto P_0c0842b6;
case 0x0c0842b8u: goto P_0c0842b8;
case 0x0c0842bau: goto P_0c0842ba;
case 0x0c0842bcu: goto P_0c0842bc;
case 0x0c0842beu: goto P_0c0842be;
case 0x0c0842c0u: goto P_0c0842c0;
case 0x0c0842c2u: goto P_0c0842c2;
case 0x0c0842c4u: goto P_0c0842c4;
case 0x0c0842c6u: goto P_0c0842c6;
case 0x0c0842c8u: goto P_0c0842c8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c084050: /* original 2fe6, guest PC 0x0c084050 */
if(!s->budget--) { s->failed_pc=0x0c084050u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084052;
P_0c084052: /* original 2fd6, guest PC 0x0c084052 */
if(!s->budget--) { s->failed_pc=0x0c084052u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084054;
P_0c084054: /* original 2fc6, guest PC 0x0c084054 */
if(!s->budget--) { s->failed_pc=0x0c084054u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084056;
P_0c084056: /* original 2fb6, guest PC 0x0c084056 */
if(!s->budget--) { s->failed_pc=0x0c084056u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084058;
P_0c084058: /* original 2fa6, guest PC 0x0c084058 */
if(!s->budget--) { s->failed_pc=0x0c084058u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08405a;
P_0c08405a: /* original 2f96, guest PC 0x0c08405a */
if(!s->budget--) { s->failed_pc=0x0c08405au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08405c;
P_0c08405c: /* original 2f86, guest PC 0x0c08405c */
if(!s->budget--) { s->failed_pc=0x0c08405cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08405e;
P_0c08405e: /* original fffb, guest PC 0x0c08405e */
if(!s->budget--) { s->failed_pc=0x0c08405eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084060;
P_0c084060: /* original ffeb, guest PC 0x0c084060 */
if(!s->budget--) { s->failed_pc=0x0c084060u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084062;
P_0c084062: /* original ffdb, guest PC 0x0c084062 */
if(!s->budget--) { s->failed_pc=0x0c084062u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084064;
P_0c084064: /* original ffcb, guest PC 0x0c084064 */
if(!s->budget--) { s->failed_pc=0x0c084064u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c084066;
P_0c084066: /* original 4f22, guest PC 0x0c084066 */
if(!s->budget--) { s->failed_pc=0x0c084066u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084068;
P_0c084068: /* original 9891, guest PC 0x0c084068 */
if(!s->budget--) { s->failed_pc=0x0c084068u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08418eu,2);
goto P_0c08406a;
P_0c08406a: /* original d34e, guest PC 0x0c08406a */
if(!s->budget--) { s->failed_pc=0x0c08406au; return 0; }
r[3]=read(ram,0x0c0841a4u,4);
goto P_0c08406c;
P_0c08406c: /* original 4f12, guest PC 0x0c08406c */
if(!s->budget--) { s->failed_pc=0x0c08406cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c08406e;
P_0c08406e: /* original d44c, guest PC 0x0c08406e */
if(!s->budget--) { s->failed_pc=0x0c08406eu; return 0; }
r[4]=read(ram,0x0c0841a0u,4);
goto P_0c084070;
P_0c084070: /* original 7ff4, guest PC 0x0c084070 */
if(!s->budget--) { s->failed_pc=0x0c084070u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c084072;
P_0c084072: /* original 1f31, guest PC 0x0c084072 */
if(!s->budget--) { s->failed_pc=0x0c084072u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c084074;
P_0c084074: /* original 384c, guest PC 0x0c084074 */
if(!s->budget--) { s->failed_pc=0x0c084074u; return 0; }
r[8]+=r[4];
goto P_0c084076;
P_0c084076: /* original d34e, guest PC 0x0c084076 */
if(!s->budget--) { s->failed_pc=0x0c084076u; return 0; }
r[3]=read(ram,0x0c0841b0u,4);
goto P_0c084078;
P_0c084078: /* original d44c, guest PC 0x0c084078 */
if(!s->budget--) { s->failed_pc=0x0c084078u; return 0; }
r[4]=read(ram,0x0c0841acu,4);
goto P_0c08407a;
P_0c08407a: /* original d24b, guest PC 0x0c08407a */
if(!s->budget--) { s->failed_pc=0x0c08407au; return 0; }
r[2]=read(ram,0x0c0841a8u,4);
goto P_0c08407c;
P_0c08407c: /* original 430b, guest PC 0x0c08407c */
if(!s->budget--) { s->failed_pc=0x0c08407cu; return 0; }
target=r[3];
r[16]=code_base|0x0c084080u;
write(ram,r[15],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084080u) { target=s->pc; goto dispatch; }
goto P_0c084080;
P_0c08407e: /* original 2f22, guest PC 0x0c08407e */
if(!s->budget--) { s->failed_pc=0x0c08407eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c084080;
P_0c084080: /* original d24b, guest PC 0x0c084080 */
if(!s->budget--) { s->failed_pc=0x0c084080u; return 0; }
r[2]=read(ram,0x0c0841b0u,4);
goto P_0c084082;
P_0c084082: /* original d44c, guest PC 0x0c084082 */
if(!s->budget--) { s->failed_pc=0x0c084082u; return 0; }
r[4]=read(ram,0x0c0841b4u,4);
goto P_0c084084;
P_0c084084: /* original 420b, guest PC 0x0c084084 */
if(!s->budget--) { s->failed_pc=0x0c084084u; return 0; }
target=r[2];
r[16]=code_base|0x0c084088u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084088u) { target=s->pc; goto dispatch; }
goto P_0c084088;
P_0c084086: /* original 0009, guest PC 0x0c084086 */
if(!s->budget--) { s->failed_pc=0x0c084086u; return 0; }
goto P_0c084088;
P_0c084088: /* original be6d, guest PC 0x0c084088 */
if(!s->budget--) { s->failed_pc=0x0c084088u; return 0; }
target=code_base|0x0c083d66u; r[16]=code_base|0x0c08408cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08408cu) { target=s->pc; goto dispatch; }
goto P_0c08408c;
P_0c08408a: /* original 64f2, guest PC 0x0c08408a */
if(!s->budget--) { s->failed_pc=0x0c08408au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c08408c;
P_0c08408c: /* original 9080, guest PC 0x0c08408c */
if(!s->budget--) { s->failed_pc=0x0c08408cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084190u,2);
goto P_0c08408e;
P_0c08408e: /* original e301, guest PC 0x0c08408e */
if(!s->budget--) { s->failed_pc=0x0c08408eu; return 0; }
r[3]=0x00000001u;
goto P_0c084090;
P_0c084090: /* original 5cf1, guest PC 0x0c084090 */
if(!s->budget--) { s->failed_pc=0x0c084090u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c084092;
P_0c084092: /* original de49, guest PC 0x0c084092 */
if(!s->budget--) { s->failed_pc=0x0c084092u; return 0; }
r[14]=read(ram,0x0c0841b8u,4);
goto P_0c084094;
P_0c084094: /* original 0cce, guest PC 0x0c084094 */
if(!s->budget--) { s->failed_pc=0x0c084094u; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c084096;
P_0c084096: /* original 2f36, guest PC 0x0c084096 */
if(!s->budget--) { s->failed_pc=0x0c084096u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084098;
P_0c084098: /* original 7cfc, guest PC 0x0c084098 */
if(!s->budget--) { s->failed_pc=0x0c084098u; return 0; }
r[12]+=0xfffffffcu;
goto P_0c08409a;
P_0c08409a: /* original 62c3, guest PC 0x0c08409a */
if(!s->budget--) { s->failed_pc=0x0c08409au; return 0; }
r[2]=r[12];
goto P_0c08409c;
P_0c08409c: /* original 4208, guest PC 0x0c08409c */
if(!s->budget--) { s->failed_pc=0x0c08409cu; return 0; }
r[2]<<=2;
goto P_0c08409e;
P_0c08409e: /* original 1f21, guest PC 0x0c08409e */
if(!s->budget--) { s->failed_pc=0x0c08409eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0840a0;
P_0c0840a0: /* original d046, guest PC 0x0c0840a0 */
if(!s->budget--) { s->failed_pc=0x0c0840a0u; return 0; }
r[0]=read(ram,0x0c0841bcu,4);
goto P_0c0840a2;
P_0c0840a2: /* original 9476, guest PC 0x0c0840a2 */
if(!s->budget--) { s->failed_pc=0x0c0840a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084192u,2);
goto P_0c0840a4;
P_0c0840a4: /* original 032e, guest PC 0x0c0840a4 */
if(!s->budget--) { s->failed_pc=0x0c0840a4u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c0840a6;
P_0c0840a6: /* original 4e0b, guest PC 0x0c0840a6 */
if(!s->budget--) { s->failed_pc=0x0c0840a6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0840aau;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0840aau) { target=s->pc; goto dispatch; }
goto P_0c0840aa;
P_0c0840a8: /* original 2f36, guest PC 0x0c0840a8 */
if(!s->budget--) { s->failed_pc=0x0c0840a8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0840aa;
P_0c0840aa: /* original 9273, guest PC 0x0c0840aa */
if(!s->budget--) { s->failed_pc=0x0c0840aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084194u,2);
goto P_0c0840ac;
P_0c0840ac: /* original 53f2, guest PC 0x0c0840ac */
if(!s->budget--) { s->failed_pc=0x0c0840acu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0840ae;
P_0c0840ae: /* original 328c, guest PC 0x0c0840ae */
if(!s->budget--) { s->failed_pc=0x0c0840aeu; return 0; }
r[2]+=r[8];
goto P_0c0840b0;
P_0c0840b0: /* original 323c, guest PC 0x0c0840b0 */
if(!s->budget--) { s->failed_pc=0x0c0840b0u; return 0; }
r[2]+=r[3];
goto P_0c0840b2;
P_0c0840b2: /* original 6122, guest PC 0x0c0840b2 */
if(!s->budget--) { s->failed_pc=0x0c0840b2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0840b4;
P_0c0840b4: /* original 2f16, guest PC 0x0c0840b4 */
if(!s->budget--) { s->failed_pc=0x0c0840b4u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0840b6;
P_0c0840b6: /* original d042, guest PC 0x0c0840b6 */
if(!s->budget--) { s->failed_pc=0x0c0840b6u; return 0; }
r[0]=read(ram,0x0c0841c0u,4);
goto P_0c0840b8;
P_0c0840b8: /* original 946d, guest PC 0x0c0840b8 */
if(!s->budget--) { s->failed_pc=0x0c0840b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084196u,2);
goto P_0c0840ba;
P_0c0840ba: /* original 4e0b, guest PC 0x0c0840ba */
if(!s->budget--) { s->failed_pc=0x0c0840bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0840beu;
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0840beu) { target=s->pc; goto dispatch; }
goto P_0c0840be;
P_0c0840bc: /* original 2f06, guest PC 0x0c0840bc */
if(!s->budget--) { s->failed_pc=0x0c0840bcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0840be;
P_0c0840be: /* original 63c3, guest PC 0x0c0840be */
if(!s->budget--) { s->failed_pc=0x0c0840beu; return 0; }
r[3]=r[12];
goto P_0c0840c0;
P_0c0840c0: /* original 7301, guest PC 0x0c0840c0 */
if(!s->budget--) { s->failed_pc=0x0c0840c0u; return 0; }
r[3]+=0x00000001u;
goto P_0c0840c2;
P_0c0840c2: /* original 2f36, guest PC 0x0c0840c2 */
if(!s->budget--) { s->failed_pc=0x0c0840c2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0840c4;
P_0c0840c4: /* original d23f, guest PC 0x0c0840c4 */
if(!s->budget--) { s->failed_pc=0x0c0840c4u; return 0; }
r[2]=read(ram,0x0c0841c4u,4);
goto P_0c0840c6;
P_0c0840c6: /* original 9467, guest PC 0x0c0840c6 */
if(!s->budget--) { s->failed_pc=0x0c0840c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084198u,2);
goto P_0c0840c8;
P_0c0840c8: /* original 4e0b, guest PC 0x0c0840c8 */
if(!s->budget--) { s->failed_pc=0x0c0840c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0840ccu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0840ccu) { target=s->pc; goto dispatch; }
goto P_0c0840cc;
P_0c0840ca: /* original 2f26, guest PC 0x0c0840ca */
if(!s->budget--) { s->failed_pc=0x0c0840cau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0840cc;
P_0c0840cc: /* original e30d, guest PC 0x0c0840cc */
if(!s->budget--) { s->failed_pc=0x0c0840ccu; return 0; }
r[3]=0x0000000du;
goto P_0c0840ce;
P_0c0840ce: /* original 0c37, guest PC 0x0c0840ce */
if(!s->budget--) { s->failed_pc=0x0c0840ceu; return 0; }
r[19]=r[12]*r[3];
goto P_0c0840d0;
P_0c0840d0: /* original c73d, guest PC 0x0c0840d0 */
if(!s->budget--) { s->failed_pc=0x0c0840d0u; return 0; }
r[0]=code_base|0x000841c8u;
goto P_0c0840d2;
P_0c0840d2: /* original e400, guest PC 0x0c0840d2 */
if(!s->budget--) { s->failed_pc=0x0c0840d2u; return 0; }
r[4]=0x00000000u;
goto P_0c0840d4;
P_0c0840d4: /* original 7f18, guest PC 0x0c0840d4 */
if(!s->budget--) { s->failed_pc=0x0c0840d4u; return 0; }
r[15]+=0x00000018u;
goto P_0c0840d6;
P_0c0840d6: /* original 6b43, guest PC 0x0c0840d6 */
if(!s->budget--) { s->failed_pc=0x0c0840d6u; return 0; }
r[11]=r[4];
goto P_0c0840d8;
P_0c0840d8: /* original 0c1a, guest PC 0x0c0840d8 */
if(!s->budget--) { s->failed_pc=0x0c0840d8u; return 0; }
r[12]=r[19];
goto P_0c0840da;
P_0c0840da: /* original ed81, guest PC 0x0c0840da */
if(!s->budget--) { s->failed_pc=0x0c0840dau; return 0; }
r[13]=0xffffff81u;
goto P_0c0840dc;
P_0c0840dc: /* original 2f42, guest PC 0x0c0840dc */
if(!s->budget--) { s->failed_pc=0x0c0840dcu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0840de;
P_0c0840de: /* original da37, guest PC 0x0c0840de */
if(!s->budget--) { s->failed_pc=0x0c0840deu; return 0; }
r[10]=read(ram,0x0c0841bcu,4);
goto P_0c0840e0;
P_0c0840e0: /* original fc08, guest PC 0x0c0840e0 */
if(!s->budget--) { s->failed_pc=0x0c0840e0u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c0840e2;
P_0c0840e2: /* original 69c3, guest PC 0x0c0840e2 */
if(!s->budget--) { s->failed_pc=0x0c0840e2u; return 0; }
r[9]=r[12];
goto P_0c0840e4;
P_0c0840e4: /* original 64b3, guest PC 0x0c0840e4 */
if(!s->budget--) { s->failed_pc=0x0c0840e4u; return 0; }
r[4]=r[11];
goto P_0c0840e6;
P_0c0840e6: /* original 7408, guest PC 0x0c0840e6 */
if(!s->budget--) { s->failed_pc=0x0c0840e6u; return 0; }
r[4]+=0x00000008u;
goto P_0c0840e8;
P_0c0840e8: /* original 6c43, guest PC 0x0c0840e8 */
if(!s->budget--) { s->failed_pc=0x0c0840e8u; return 0; }
r[12]=r[4];
goto P_0c0840ea;
P_0c0840ea: /* original e307, guest PC 0x0c0840ea */
if(!s->budget--) { s->failed_pc=0x0c0840eau; return 0; }
r[3]=0x00000007u;
goto P_0c0840ec;
P_0c0840ec: /* original 4c3c, guest PC 0x0c0840ec */
if(!s->budget--) { s->failed_pc=0x0c0840ecu; return 0; }
r[12]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[12]>>((-r[3])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[3]&31u);
goto P_0c0840ee;
P_0c0840ee: /* original 1f92, guest PC 0x0c0840ee */
if(!s->budget--) { s->failed_pc=0x0c0840eeu; return 0; }
write(ram,r[15]+8,r[9],4);
goto P_0c0840f0;
P_0c0840f0: /* original 60c3, guest PC 0x0c0840f0 */
if(!s->budget--) { s->failed_pc=0x0c0840f0u; return 0; }
r[0]=r[12];
goto P_0c0840f2;
P_0c0840f2: /* original 20d9, guest PC 0x0c0840f2 */
if(!s->budget--) { s->failed_pc=0x0c0840f2u; return 0; }
r[0]&=r[13];
goto P_0c0840f4;
P_0c0840f4: /* original cb12, guest PC 0x0c0840f4 */
if(!s->budget--) { s->failed_pc=0x0c0840f4u; return 0; }
r[0]|=18u;
goto P_0c0840f6;
P_0c0840f6: /* original e601, guest PC 0x0c0840f6 */
if(!s->budget--) { s->failed_pc=0x0c0840f6u; return 0; }
r[6]=0x00000001u;
goto P_0c0840f8;
P_0c0840f8: /* original 1f01, guest PC 0x0c0840f8 */
if(!s->budget--) { s->failed_pc=0x0c0840f8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0840fa;
P_0c0840fa: /* original 65a2, guest PC 0x0c0840fa */
if(!s->budget--) { s->failed_pc=0x0c0840fau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0840fc;
P_0c0840fc: /* original d233, guest PC 0x0c0840fc */
if(!s->budget--) { s->failed_pc=0x0c0840fcu; return 0; }
r[2]=read(ram,0x0c0841ccu,4);
goto P_0c0840fe;
P_0c0840fe: /* original 420b, guest PC 0x0c0840fe */
if(!s->budget--) { s->failed_pc=0x0c0840feu; return 0; }
target=r[2];
r[16]=code_base|0x0c084102u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084102u) { target=s->pc; goto dispatch; }
goto P_0c084102;
P_0c084100: /* original 6403, guest PC 0x0c084100 */
if(!s->budget--) { s->failed_pc=0x0c084100u; return 0; }
r[4]=r[0];
goto P_0c084102;
P_0c084102: /* original 54f2, guest PC 0x0c084102 */
if(!s->budget--) { s->failed_pc=0x0c084102u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c084104;
P_0c084104: /* original 4408, guest PC 0x0c084104 */
if(!s->budget--) { s->failed_pc=0x0c084104u; return 0; }
r[4]<<=2;
goto P_0c084106;
P_0c084106: /* original 1f41, guest PC 0x0c084106 */
if(!s->budget--) { s->failed_pc=0x0c084106u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c084108;
P_0c084108: /* original 9347, guest PC 0x0c084108 */
if(!s->budget--) { s->failed_pc=0x0c084108u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08419au,2);
goto P_0c08410a;
P_0c08410a: /* original d231, guest PC 0x0c08410a */
if(!s->budget--) { s->failed_pc=0x0c08410au; return 0; }
r[2]=read(ram,0x0c0841d0u,4);
goto P_0c08410c;
P_0c08410c: /* original 338c, guest PC 0x0c08410c */
if(!s->budget--) { s->failed_pc=0x0c08410cu; return 0; }
r[3]+=r[8];
goto P_0c08410e;
P_0c08410e: /* original 420b, guest PC 0x0c08410e */
if(!s->budget--) { s->failed_pc=0x0c08410eu; return 0; }
target=r[2];
r[16]=code_base|0x0c084112u;
r[4]+=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084112u) { target=s->pc; goto dispatch; }
goto P_0c084112;
P_0c084110: /* original 343c, guest PC 0x0c084110 */
if(!s->budget--) { s->failed_pc=0x0c084110u; return 0; }
r[4]+=r[3];
goto P_0c084112;
P_0c084112: /* original 9443, guest PC 0x0c084112 */
if(!s->budget--) { s->failed_pc=0x0c084112u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08419cu,2);
goto P_0c084114;
P_0c084114: /* original 53f1, guest PC 0x0c084114 */
if(!s->budget--) { s->failed_pc=0x0c084114u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c084116;
P_0c084116: /* original 348c, guest PC 0x0c084116 */
if(!s->budget--) { s->failed_pc=0x0c084116u; return 0; }
r[4]+=r[8];
goto P_0c084118;
P_0c084118: /* original 343c, guest PC 0x0c084118 */
if(!s->budget--) { s->failed_pc=0x0c084118u; return 0; }
r[4]+=r[3];
goto P_0c08411a;
P_0c08411a: /* original d32d, guest PC 0x0c08411a */
if(!s->budget--) { s->failed_pc=0x0c08411au; return 0; }
r[3]=read(ram,0x0c0841d0u,4);
goto P_0c08411c;
P_0c08411c: /* original 430b, guest PC 0x0c08411c */
if(!s->budget--) { s->failed_pc=0x0c08411cu; return 0; }
target=r[3];
r[16]=code_base|0x0c084120u;
vf3_matrix_move(s,15,0);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084120u) { target=s->pc; goto dispatch; }
goto P_0c084120;
P_0c08411e: /* original ff0c, guest PC 0x0c08411e */
if(!s->budget--) { s->failed_pc=0x0c08411eu; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c084120;
P_0c084120: /* original f38d, guest PC 0x0c084120 */
if(!s->budget--) { s->failed_pc=0x0c084120u; return 0; }
fr[3]=0;
goto P_0c084122;
P_0c084122: /* original f3f4, guest PC 0x0c084122 */
if(!s->budget--) { s->failed_pc=0x0c084122u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c084124;
P_0c084124: /* original fdfc, guest PC 0x0c084124 */
if(!s->budget--) { s->failed_pc=0x0c084124u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c084126;
P_0c084126: /* original 60c3, guest PC 0x0c084126 */
if(!s->budget--) { s->failed_pc=0x0c084126u; return 0; }
r[0]=r[12];
goto P_0c084128;
P_0c084128: /* original fe0c, guest PC 0x0c084128 */
if(!s->budget--) { s->failed_pc=0x0c084128u; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c08412a;
P_0c08412a: /* original fde1, guest PC 0x0c08412a */
if(!s->budget--) { s->failed_pc=0x0c08412au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[14],r[18],'-');
goto P_0c08412c;
P_0c08412c: /* original 20d9, guest PC 0x0c08412c */
if(!s->budget--) { s->failed_pc=0x0c08412cu; return 0; }
r[0]&=r[13];
goto P_0c08412e;
P_0c08412e: /* original ec2e, guest PC 0x0c08412e */
if(!s->budget--) { s->failed_pc=0x0c08412eu; return 0; }
r[12]=0x0000002eu;
goto P_0c084130;
P_0c084130: /* original 8f09, guest PC 0x0c084130 */
if(!s->budget--) { s->failed_pc=0x0c084130u; return 0; }
cond=r[17]&1u;
r[12]|=r[0];
if(!cond) { goto P_0c084146; }
goto P_0c084134;
P_0c084132: /* original 2c0b, guest PC 0x0c084132 */
if(!s->budget--) { s->failed_pc=0x0c084132u; return 0; }
r[12]|=r[0];
goto P_0c084134;
P_0c084134: /* original ffdb, guest PC 0x0c084134 */
if(!s->budget--) { s->failed_pc=0x0c084134u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c084136;
P_0c084136: /* original ffeb, guest PC 0x0c084136 */
if(!s->budget--) { s->failed_pc=0x0c084136u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084138;
P_0c084138: /* original fffb, guest PC 0x0c084138 */
if(!s->budget--) { s->failed_pc=0x0c084138u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08413a;
P_0c08413a: /* original d226, guest PC 0x0c08413a */
if(!s->budget--) { s->failed_pc=0x0c08413au; return 0; }
r[2]=read(ram,0x0c0841d4u,4);
goto P_0c08413c;
P_0c08413c: /* original 2f26, guest PC 0x0c08413c */
if(!s->budget--) { s->failed_pc=0x0c08413cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08413e;
P_0c08413e: /* original 4e0b, guest PC 0x0c08413e */
if(!s->budget--) { s->failed_pc=0x0c08413eu; return 0; }
target=r[14];
r[16]=code_base|0x0c084142u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084142u) { target=s->pc; goto dispatch; }
goto P_0c084142;
P_0c084140: /* original 64c3, guest PC 0x0c084140 */
if(!s->budget--) { s->failed_pc=0x0c084140u; return 0; }
r[4]=r[12];
goto P_0c084142;
P_0c084142: /* original a00c, guest PC 0x0c084142 */
if(!s->budget--) { s->failed_pc=0x0c084142u; return 0; }
r[15]+=0x00000010u;
goto P_0c08415e;
P_0c084144: /* original 7f10, guest PC 0x0c084144 */
if(!s->budget--) { s->failed_pc=0x0c084144u; return 0; }
r[15]+=0x00000010u;
goto P_0c084146;
P_0c084146: /* original f4ec, guest PC 0x0c084146 */
if(!s->budget--) { s->failed_pc=0x0c084146u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c084148;
P_0c084148: /* original f4f3, guest PC 0x0c084148 */
if(!s->budget--) { s->failed_pc=0x0c084148u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'/');
goto P_0c08414a;
P_0c08414a: /* original ffdb, guest PC 0x0c08414a */
if(!s->budget--) { s->failed_pc=0x0c08414au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08414c;
P_0c08414c: /* original ffeb, guest PC 0x0c08414c */
if(!s->budget--) { s->failed_pc=0x0c08414cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08414e;
P_0c08414e: /* original fffb, guest PC 0x0c08414e */
if(!s->budget--) { s->failed_pc=0x0c08414eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084150;
P_0c084150: /* original f4c2, guest PC 0x0c084150 */
if(!s->budget--) { s->failed_pc=0x0c084150u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'*');
goto P_0c084152;
P_0c084152: /* original ff4b, guest PC 0x0c084152 */
if(!s->budget--) { s->failed_pc=0x0c084152u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c084154;
P_0c084154: /* original d220, guest PC 0x0c084154 */
if(!s->budget--) { s->failed_pc=0x0c084154u; return 0; }
r[2]=read(ram,0x0c0841d8u,4);
goto P_0c084156;
P_0c084156: /* original 2f26, guest PC 0x0c084156 */
if(!s->budget--) { s->failed_pc=0x0c084156u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084158;
P_0c084158: /* original 4e0b, guest PC 0x0c084158 */
if(!s->budget--) { s->failed_pc=0x0c084158u; return 0; }
target=r[14];
r[16]=code_base|0x0c08415cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08415cu) { target=s->pc; goto dispatch; }
goto P_0c08415c;
P_0c08415a: /* original 64c3, guest PC 0x0c08415a */
if(!s->budget--) { s->failed_pc=0x0c08415au; return 0; }
r[4]=r[12];
goto P_0c08415c;
P_0c08415c: /* original 7f14, guest PC 0x0c08415c */
if(!s->budget--) { s->failed_pc=0x0c08415cu; return 0; }
r[15]+=0x00000014u;
goto P_0c08415e;
P_0c08415e: /* original 63f2, guest PC 0x0c08415e */
if(!s->budget--) { s->failed_pc=0x0c08415eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c084160;
P_0c084160: /* original e20d, guest PC 0x0c084160 */
if(!s->budget--) { s->failed_pc=0x0c084160u; return 0; }
r[2]=0x0000000du;
goto P_0c084162;
P_0c084162: /* original 7b03, guest PC 0x0c084162 */
if(!s->budget--) { s->failed_pc=0x0c084162u; return 0; }
r[11]+=0x00000003u;
goto P_0c084164;
P_0c084164: /* original 7301, guest PC 0x0c084164 */
if(!s->budget--) { s->failed_pc=0x0c084164u; return 0; }
r[3]+=0x00000001u;
goto P_0c084166;
P_0c084166: /* original 3323, guest PC 0x0c084166 */
if(!s->budget--) { s->failed_pc=0x0c084166u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c084168;
P_0c084168: /* original 2f32, guest PC 0x0c084168 */
if(!s->budget--) { s->failed_pc=0x0c084168u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08416a;
P_0c08416a: /* original 7a04, guest PC 0x0c08416a */
if(!s->budget--) { s->failed_pc=0x0c08416au; return 0; }
r[10]+=0x00000004u;
goto P_0c08416c;
P_0c08416c: /* original 8fba, guest PC 0x0c08416c */
if(!s->budget--) { s->failed_pc=0x0c08416cu; return 0; }
cond=r[17]&1u;
r[9]+=0x00000001u;
if(!cond) { goto P_0c0840e4; }
goto P_0c084170;
P_0c08416e: /* original 7901, guest PC 0x0c08416e */
if(!s->budget--) { s->failed_pc=0x0c08416eu; return 0; }
r[9]+=0x00000001u;
goto P_0c084170;
P_0c084170: /* original 7f0c, guest PC 0x0c084170 */
if(!s->budget--) { s->failed_pc=0x0c084170u; return 0; }
r[15]+=0x0000000cu;
goto P_0c084172;
P_0c084172: /* original 4f16, guest PC 0x0c084172 */
if(!s->budget--) { s->failed_pc=0x0c084172u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c084174;
P_0c084174: /* original 4f26, guest PC 0x0c084174 */
if(!s->budget--) { s->failed_pc=0x0c084174u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084176;
P_0c084176: /* original fcf9, guest PC 0x0c084176 */
if(!s->budget--) { s->failed_pc=0x0c084176u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084178;
P_0c084178: /* original fdf9, guest PC 0x0c084178 */
if(!s->budget--) { s->failed_pc=0x0c084178u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08417a;
P_0c08417a: /* original fef9, guest PC 0x0c08417a */
if(!s->budget--) { s->failed_pc=0x0c08417au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08417c;
P_0c08417c: /* original fff9, guest PC 0x0c08417c */
if(!s->budget--) { s->failed_pc=0x0c08417cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08417e;
P_0c08417e: /* original 68f6, guest PC 0x0c08417e */
if(!s->budget--) { s->failed_pc=0x0c08417eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c084180;
P_0c084180: /* original 69f6, guest PC 0x0c084180 */
if(!s->budget--) { s->failed_pc=0x0c084180u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c084182;
P_0c084182: /* original 6af6, guest PC 0x0c084182 */
if(!s->budget--) { s->failed_pc=0x0c084182u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084184;
P_0c084184: /* original 6bf6, guest PC 0x0c084184 */
if(!s->budget--) { s->failed_pc=0x0c084184u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084186;
P_0c084186: /* original 6cf6, guest PC 0x0c084186 */
if(!s->budget--) { s->failed_pc=0x0c084186u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084188;
P_0c084188: /* original 6df6, guest PC 0x0c084188 */
if(!s->budget--) { s->failed_pc=0x0c084188u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08418a;
P_0c08418a: /* original 000b, guest PC 0x0c08418a */
if(!s->budget--) { s->failed_pc=0x0c08418au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08418c: /* original 6ef6, guest PC 0x0c08418c */
if(!s->budget--) { s->failed_pc=0x0c08418cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08418eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08418eu; return 0; } return 1;
P_0c0841dc: /* original 2fe6, guest PC 0x0c0841dc */
if(!s->budget--) { s->failed_pc=0x0c0841dcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841de;
P_0c0841de: /* original 2fd6, guest PC 0x0c0841de */
if(!s->budget--) { s->failed_pc=0x0c0841deu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841e0;
P_0c0841e0: /* original 2fc6, guest PC 0x0c0841e0 */
if(!s->budget--) { s->failed_pc=0x0c0841e0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841e2;
P_0c0841e2: /* original 2fb6, guest PC 0x0c0841e2 */
if(!s->budget--) { s->failed_pc=0x0c0841e2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841e4;
P_0c0841e4: /* original 2fa6, guest PC 0x0c0841e4 */
if(!s->budget--) { s->failed_pc=0x0c0841e4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841e6;
P_0c0841e6: /* original 2f96, guest PC 0x0c0841e6 */
if(!s->budget--) { s->failed_pc=0x0c0841e6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841e8;
P_0c0841e8: /* original 2f86, guest PC 0x0c0841e8 */
if(!s->budget--) { s->failed_pc=0x0c0841e8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0841ea;
P_0c0841ea: /* original fffb, guest PC 0x0c0841ea */
if(!s->budget--) { s->failed_pc=0x0c0841eau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0841ec;
P_0c0841ec: /* original ffeb, guest PC 0x0c0841ec */
if(!s->budget--) { s->failed_pc=0x0c0841ecu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0841ee;
P_0c0841ee: /* original 4f22, guest PC 0x0c0841ee */
if(!s->budget--) { s->failed_pc=0x0c0841eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0841f0;
P_0c0841f0: /* original 9e6b, guest PC 0x0c0841f0 */
if(!s->budget--) { s->failed_pc=0x0c0841f0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0842cau,2);
goto P_0c0841f2;
P_0c0841f2: /* original d33a, guest PC 0x0c0841f2 */
if(!s->budget--) { s->failed_pc=0x0c0841f2u; return 0; }
r[3]=read(ram,0x0c0842dcu,4);
goto P_0c0841f4;
P_0c0841f4: /* original d438, guest PC 0x0c0841f4 */
if(!s->budget--) { s->failed_pc=0x0c0841f4u; return 0; }
r[4]=read(ram,0x0c0842d8u,4);
goto P_0c0841f6;
P_0c0841f6: /* original 7ffc, guest PC 0x0c0841f6 */
if(!s->budget--) { s->failed_pc=0x0c0841f6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0841f8;
P_0c0841f8: /* original 2f32, guest PC 0x0c0841f8 */
if(!s->budget--) { s->failed_pc=0x0c0841f8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0841fa;
P_0c0841fa: /* original 3e4c, guest PC 0x0c0841fa */
if(!s->budget--) { s->failed_pc=0x0c0841fau; return 0; }
r[14]+=r[4];
goto P_0c0841fc;
P_0c0841fc: /* original d339, guest PC 0x0c0841fc */
if(!s->budget--) { s->failed_pc=0x0c0841fcu; return 0; }
r[3]=read(ram,0x0c0842e4u,4);
goto P_0c0841fe;
P_0c0841fe: /* original d438, guest PC 0x0c0841fe */
if(!s->budget--) { s->failed_pc=0x0c0841feu; return 0; }
r[4]=read(ram,0x0c0842e0u,4);
goto P_0c084200;
P_0c084200: /* original 430b, guest PC 0x0c084200 */
if(!s->budget--) { s->failed_pc=0x0c084200u; return 0; }
target=r[3];
r[16]=code_base|0x0c084204u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084204u) { target=s->pc; goto dispatch; }
goto P_0c084204;
P_0c084202: /* original 0009, guest PC 0x0c084202 */
if(!s->budget--) { s->failed_pc=0x0c084202u; return 0; }
goto P_0c084204;
P_0c084204: /* original d237, guest PC 0x0c084204 */
if(!s->budget--) { s->failed_pc=0x0c084204u; return 0; }
r[2]=read(ram,0x0c0842e4u,4);
goto P_0c084206;
P_0c084206: /* original d438, guest PC 0x0c084206 */
if(!s->budget--) { s->failed_pc=0x0c084206u; return 0; }
r[4]=read(ram,0x0c0842e8u,4);
goto P_0c084208;
P_0c084208: /* original 420b, guest PC 0x0c084208 */
if(!s->budget--) { s->failed_pc=0x0c084208u; return 0; }
target=r[2];
r[16]=code_base|0x0c08420cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08420cu) { target=s->pc; goto dispatch; }
goto P_0c08420c;
P_0c08420a: /* original 0009, guest PC 0x0c08420a */
if(!s->budget--) { s->failed_pc=0x0c08420au; return 0; }
goto P_0c08420c;
P_0c08420c: /* original bdab, guest PC 0x0c08420c */
if(!s->budget--) { s->failed_pc=0x0c08420cu; return 0; }
target=code_base|0x0c083d66u; r[16]=code_base|0x0c084210u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084210u) { target=s->pc; goto dispatch; }
goto P_0c084210;
P_0c08420e: /* original 64f2, guest PC 0x0c08420e */
if(!s->budget--) { s->failed_pc=0x0c08420eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c084210;
P_0c084210: /* original d836, guest PC 0x0c084210 */
if(!s->budget--) { s->failed_pc=0x0c084210u; return 0; }
r[8]=read(ram,0x0c0842ecu,4);
goto P_0c084212;
P_0c084212: /* original e400, guest PC 0x0c084212 */
if(!s->budget--) { s->failed_pc=0x0c084212u; return 0; }
r[4]=0x00000000u;
goto P_0c084214;
P_0c084214: /* original 6c43, guest PC 0x0c084214 */
if(!s->budget--) { s->failed_pc=0x0c084214u; return 0; }
r[12]=r[4];
goto P_0c084216;
P_0c084216: /* original 6a43, guest PC 0x0c084216 */
if(!s->budget--) { s->failed_pc=0x0c084216u; return 0; }
r[10]=r[4];
goto P_0c084218;
P_0c084218: /* original ed81, guest PC 0x0c084218 */
if(!s->budget--) { s->failed_pc=0x0c084218u; return 0; }
r[13]=0xffffff81u;
goto P_0c08421a;
P_0c08421a: /* original 64c3, guest PC 0x0c08421a */
if(!s->budget--) { s->failed_pc=0x0c08421au; return 0; }
r[4]=r[12];
goto P_0c08421c;
P_0c08421c: /* original 4400, guest PC 0x0c08421c */
if(!s->budget--) { s->failed_pc=0x0c08421cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08421e;
P_0c08421e: /* original 63c3, guest PC 0x0c08421e */
if(!s->budget--) { s->failed_pc=0x0c08421eu; return 0; }
r[3]=r[12];
goto P_0c084220;
P_0c084220: /* original 343c, guest PC 0x0c084220 */
if(!s->budget--) { s->failed_pc=0x0c084220u; return 0; }
r[4]+=r[3];
goto P_0c084222;
P_0c084222: /* original 2f42, guest PC 0x0c084222 */
if(!s->budget--) { s->failed_pc=0x0c084222u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c084224;
P_0c084224: /* original e307, guest PC 0x0c084224 */
if(!s->budget--) { s->failed_pc=0x0c084224u; return 0; }
r[3]=0x00000007u;
goto P_0c084226;
P_0c084226: /* original 7408, guest PC 0x0c084226 */
if(!s->budget--) { s->failed_pc=0x0c084226u; return 0; }
r[4]+=0x00000008u;
goto P_0c084228;
P_0c084228: /* original 65c3, guest PC 0x0c084228 */
if(!s->budget--) { s->failed_pc=0x0c084228u; return 0; }
r[5]=r[12];
goto P_0c08422a;
P_0c08422a: /* original 443c, guest PC 0x0c08422a */
if(!s->budget--) { s->failed_pc=0x0c08422au; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c08422c;
P_0c08422c: /* original d231, guest PC 0x0c08422c */
if(!s->budget--) { s->failed_pc=0x0c08422cu; return 0; }
r[2]=read(ram,0x0c0842f4u,4);
goto P_0c08422e;
P_0c08422e: /* original 6043, guest PC 0x0c08422e */
if(!s->budget--) { s->failed_pc=0x0c08422eu; return 0; }
r[0]=r[4];
goto P_0c084230;
P_0c084230: /* original eb12, guest PC 0x0c084230 */
if(!s->budget--) { s->failed_pc=0x0c084230u; return 0; }
r[11]=0x00000012u;
goto P_0c084232;
P_0c084232: /* original 20d9, guest PC 0x0c084232 */
if(!s->budget--) { s->failed_pc=0x0c084232u; return 0; }
r[0]&=r[13];
goto P_0c084234;
P_0c084234: /* original 2b0b, guest PC 0x0c084234 */
if(!s->budget--) { s->failed_pc=0x0c084234u; return 0; }
r[11]|=r[0];
goto P_0c084236;
P_0c084236: /* original d02e, guest PC 0x0c084236 */
if(!s->budget--) { s->failed_pc=0x0c084236u; return 0; }
r[0]=read(ram,0x0c0842f0u,4);
goto P_0c084238;
P_0c084238: /* original 4508, guest PC 0x0c084238 */
if(!s->budget--) { s->failed_pc=0x0c084238u; return 0; }
r[5]<<=2;
goto P_0c08423a;
P_0c08423a: /* original 055e, guest PC 0x0c08423a */
if(!s->budget--) { s->failed_pc=0x0c08423au; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c08423c;
P_0c08423c: /* original e601, guest PC 0x0c08423c */
if(!s->budget--) { s->failed_pc=0x0c08423cu; return 0; }
r[6]=0x00000001u;
goto P_0c08423e;
P_0c08423e: /* original 420b, guest PC 0x0c08423e */
if(!s->budget--) { s->failed_pc=0x0c08423eu; return 0; }
target=r[2];
r[16]=code_base|0x0c084242u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084242u) { target=s->pc; goto dispatch; }
goto P_0c084242;
P_0c084240: /* original 64b3, guest PC 0x0c084240 */
if(!s->budget--) { s->failed_pc=0x0c084240u; return 0; }
r[4]=r[11];
goto P_0c084242;
P_0c084242: /* original 9443, guest PC 0x0c084242 */
if(!s->budget--) { s->failed_pc=0x0c084242u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0842ccu,2);
goto P_0c084244;
P_0c084244: /* original 6ba3, guest PC 0x0c084244 */
if(!s->budget--) { s->failed_pc=0x0c084244u; return 0; }
r[11]=r[10];
goto P_0c084246;
P_0c084246: /* original d32c, guest PC 0x0c084246 */
if(!s->budget--) { s->failed_pc=0x0c084246u; return 0; }
r[3]=read(ram,0x0c0842f8u,4);
goto P_0c084248;
P_0c084248: /* original 4b08, guest PC 0x0c084248 */
if(!s->budget--) { s->failed_pc=0x0c084248u; return 0; }
r[11]<<=2;
goto P_0c08424a;
P_0c08424a: /* original 34ec, guest PC 0x0c08424a */
if(!s->budget--) { s->failed_pc=0x0c08424au; return 0; }
r[4]+=r[14];
goto P_0c08424c;
P_0c08424c: /* original 430b, guest PC 0x0c08424c */
if(!s->budget--) { s->failed_pc=0x0c08424cu; return 0; }
target=r[3];
r[16]=code_base|0x0c084250u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084250u) { target=s->pc; goto dispatch; }
goto P_0c084250;
P_0c08424e: /* original 34bc, guest PC 0x0c08424e */
if(!s->budget--) { s->failed_pc=0x0c08424eu; return 0; }
r[4]+=r[11];
goto P_0c084250;
P_0c084250: /* original 943d, guest PC 0x0c084250 */
if(!s->budget--) { s->failed_pc=0x0c084250u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0842ceu,2);
goto P_0c084252;
P_0c084252: /* original d329, guest PC 0x0c084252 */
if(!s->budget--) { s->failed_pc=0x0c084252u; return 0; }
r[3]=read(ram,0x0c0842f8u,4);
goto P_0c084254;
P_0c084254: /* original 34ec, guest PC 0x0c084254 */
if(!s->budget--) { s->failed_pc=0x0c084254u; return 0; }
r[4]+=r[14];
goto P_0c084256;
P_0c084256: /* original ff0c, guest PC 0x0c084256 */
if(!s->budget--) { s->failed_pc=0x0c084256u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c084258;
P_0c084258: /* original 430b, guest PC 0x0c084258 */
if(!s->budget--) { s->failed_pc=0x0c084258u; return 0; }
target=r[3];
r[16]=code_base|0x0c08425cu;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08425cu) { target=s->pc; goto dispatch; }
goto P_0c08425c;
P_0c08425a: /* original 34bc, guest PC 0x0c08425a */
if(!s->budget--) { s->failed_pc=0x0c08425au; return 0; }
r[4]+=r[11];
goto P_0c08425c;
P_0c08425c: /* original 9438, guest PC 0x0c08425c */
if(!s->budget--) { s->failed_pc=0x0c08425cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0842d0u,2);
goto P_0c08425e;
P_0c08425e: /* original fe0c, guest PC 0x0c08425e */
if(!s->budget--) { s->failed_pc=0x0c08425eu; return 0; }
vf3_matrix_move(s,14,0);
goto P_0c084260;
P_0c084260: /* original 34ec, guest PC 0x0c084260 */
if(!s->budget--) { s->failed_pc=0x0c084260u; return 0; }
r[4]+=r[14];
goto P_0c084262;
P_0c084262: /* original 480b, guest PC 0x0c084262 */
if(!s->budget--) { s->failed_pc=0x0c084262u; return 0; }
target=r[8];
r[16]=code_base|0x0c084266u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084266u) { target=s->pc; goto dispatch; }
goto P_0c084266;
P_0c084264: /* original 34bc, guest PC 0x0c084264 */
if(!s->budget--) { s->failed_pc=0x0c084264u; return 0; }
r[4]+=r[11];
goto P_0c084266;
P_0c084266: /* original 9434, guest PC 0x0c084266 */
if(!s->budget--) { s->failed_pc=0x0c084266u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0842d2u,2);
goto P_0c084268;
P_0c084268: /* original 6903, guest PC 0x0c084268 */
if(!s->budget--) { s->failed_pc=0x0c084268u; return 0; }
r[9]=r[0];
goto P_0c08426a;
P_0c08426a: /* original 34ec, guest PC 0x0c08426a */
if(!s->budget--) { s->failed_pc=0x0c08426au; return 0; }
r[4]+=r[14];
goto P_0c08426c;
P_0c08426c: /* original 480b, guest PC 0x0c08426c */
if(!s->budget--) { s->failed_pc=0x0c08426cu; return 0; }
target=r[8];
r[16]=code_base|0x0c084270u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084270u) { target=s->pc; goto dispatch; }
goto P_0c084270;
P_0c08426e: /* original 34bc, guest PC 0x0c08426e */
if(!s->budget--) { s->failed_pc=0x0c08426eu; return 0; }
r[4]+=r[11];
goto P_0c084270;
P_0c084270: /* original 64f2, guest PC 0x0c084270 */
if(!s->budget--) { s->failed_pc=0x0c084270u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c084272;
P_0c084272: /* original e307, guest PC 0x0c084272 */
if(!s->budget--) { s->failed_pc=0x0c084272u; return 0; }
r[3]=0x00000007u;
goto P_0c084274;
P_0c084274: /* original 2f96, guest PC 0x0c084274 */
if(!s->budget--) { s->failed_pc=0x0c084274u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084276;
P_0c084276: /* original 6503, guest PC 0x0c084276 */
if(!s->budget--) { s->failed_pc=0x0c084276u; return 0; }
r[5]=r[0];
goto P_0c084278;
P_0c084278: /* original 7408, guest PC 0x0c084278 */
if(!s->budget--) { s->failed_pc=0x0c084278u; return 0; }
r[4]+=0x00000008u;
goto P_0c08427a;
P_0c08427a: /* original 2f56, guest PC 0x0c08427a */
if(!s->budget--) { s->failed_pc=0x0c08427au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08427c;
P_0c08427c: /* original 443c, guest PC 0x0c08427c */
if(!s->budget--) { s->failed_pc=0x0c08427cu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c08427e;
P_0c08427e: /* original ffeb, guest PC 0x0c08427e */
if(!s->budget--) { s->failed_pc=0x0c08427eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c084280;
P_0c084280: /* original 6043, guest PC 0x0c084280 */
if(!s->budget--) { s->failed_pc=0x0c084280u; return 0; }
r[0]=r[4];
goto P_0c084282;
P_0c084282: /* original fffb, guest PC 0x0c084282 */
if(!s->budget--) { s->failed_pc=0x0c084282u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c084284;
P_0c084284: /* original d21d, guest PC 0x0c084284 */
if(!s->budget--) { s->failed_pc=0x0c084284u; return 0; }
r[2]=read(ram,0x0c0842fcu,4);
goto P_0c084286;
P_0c084286: /* original 20d9, guest PC 0x0c084286 */
if(!s->budget--) { s->failed_pc=0x0c084286u; return 0; }
r[0]&=r[13];
goto P_0c084288;
P_0c084288: /* original eb22, guest PC 0x0c084288 */
if(!s->budget--) { s->failed_pc=0x0c084288u; return 0; }
r[11]=0x00000022u;
goto P_0c08428a;
P_0c08428a: /* original 2b0b, guest PC 0x0c08428a */
if(!s->budget--) { s->failed_pc=0x0c08428au; return 0; }
r[11]|=r[0];
goto P_0c08428c;
P_0c08428c: /* original 2f26, guest PC 0x0c08428c */
if(!s->budget--) { s->failed_pc=0x0c08428cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08428e;
P_0c08428e: /* original d11c, guest PC 0x0c08428e */
if(!s->budget--) { s->failed_pc=0x0c08428eu; return 0; }
r[1]=read(ram,0x0c084300u,4);
goto P_0c084290;
P_0c084290: /* original 410b, guest PC 0x0c084290 */
if(!s->budget--) { s->failed_pc=0x0c084290u; return 0; }
target=r[1];
r[16]=code_base|0x0c084294u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084294u) { target=s->pc; goto dispatch; }
goto P_0c084294;
P_0c084292: /* original 64b3, guest PC 0x0c084292 */
if(!s->budget--) { s->failed_pc=0x0c084292u; return 0; }
r[4]=r[11];
goto P_0c084294;
P_0c084294: /* original 931e, guest PC 0x0c084294 */
if(!s->budget--) { s->failed_pc=0x0c084294u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0842d4u,2);
goto P_0c084296;
P_0c084296: /* original 7f14, guest PC 0x0c084296 */
if(!s->budget--) { s->failed_pc=0x0c084296u; return 0; }
r[15]+=0x00000014u;
goto P_0c084298;
P_0c084298: /* original 3933, guest PC 0x0c084298 */
if(!s->budget--) { s->failed_pc=0x0c084298u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[3])!=0);
goto P_0c08429a;
P_0c08429a: /* original 8f05, guest PC 0x0c08429a */
if(!s->budget--) { s->failed_pc=0x0c08429au; return 0; }
cond=r[17]&1u;
r[11]=r[0];
if(!cond) { goto P_0c0842a8; }
goto P_0c08429e;
P_0c08429c: /* original 6b03, guest PC 0x0c08429c */
if(!s->budget--) { s->failed_pc=0x0c08429cu; return 0; }
r[11]=r[0];
goto P_0c08429e;
P_0c08429e: /* original d115, guest PC 0x0c08429e */
if(!s->budget--) { s->failed_pc=0x0c08429eu; return 0; }
r[1]=read(ram,0x0c0842f4u,4);
goto P_0c0842a0;
P_0c0842a0: /* original e601, guest PC 0x0c0842a0 */
if(!s->budget--) { s->failed_pc=0x0c0842a0u; return 0; }
r[6]=0x00000001u;
goto P_0c0842a2;
P_0c0842a2: /* original d518, guest PC 0x0c0842a2 */
if(!s->budget--) { s->failed_pc=0x0c0842a2u; return 0; }
r[5]=read(ram,0x0c084304u,4);
goto P_0c0842a4;
P_0c0842a4: /* original 410b, guest PC 0x0c0842a4 */
if(!s->budget--) { s->failed_pc=0x0c0842a4u; return 0; }
target=r[1];
r[16]=code_base|0x0c0842a8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0842a8u) { target=s->pc; goto dispatch; }
goto P_0c0842a8;
P_0c0842a6: /* original 64b3, guest PC 0x0c0842a6 */
if(!s->budget--) { s->failed_pc=0x0c0842a6u; return 0; }
r[4]=r[11];
goto P_0c0842a8;
P_0c0842a8: /* original e30d, guest PC 0x0c0842a8 */
if(!s->budget--) { s->failed_pc=0x0c0842a8u; return 0; }
r[3]=0x0000000du;
goto P_0c0842aa;
P_0c0842aa: /* original 7a01, guest PC 0x0c0842aa */
if(!s->budget--) { s->failed_pc=0x0c0842aau; return 0; }
r[10]+=0x00000001u;
goto P_0c0842ac;
P_0c0842ac: /* original 3a33, guest PC 0x0c0842ac */
if(!s->budget--) { s->failed_pc=0x0c0842acu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0842ae;
P_0c0842ae: /* original 8fb4, guest PC 0x0c0842ae */
if(!s->budget--) { s->failed_pc=0x0c0842aeu; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c08421a; }
goto P_0c0842b2;
P_0c0842b0: /* original 7c01, guest PC 0x0c0842b0 */
if(!s->budget--) { s->failed_pc=0x0c0842b0u; return 0; }
r[12]+=0x00000001u;
goto P_0c0842b2;
P_0c0842b2: /* original 7f04, guest PC 0x0c0842b2 */
if(!s->budget--) { s->failed_pc=0x0c0842b2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0842b4;
P_0c0842b4: /* original 4f26, guest PC 0x0c0842b4 */
if(!s->budget--) { s->failed_pc=0x0c0842b4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0842b6;
P_0c0842b6: /* original fef9, guest PC 0x0c0842b6 */
if(!s->budget--) { s->failed_pc=0x0c0842b6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0842b8;
P_0c0842b8: /* original fff9, guest PC 0x0c0842b8 */
if(!s->budget--) { s->failed_pc=0x0c0842b8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0842ba;
P_0c0842ba: /* original 68f6, guest PC 0x0c0842ba */
if(!s->budget--) { s->failed_pc=0x0c0842bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0842bc;
P_0c0842bc: /* original 69f6, guest PC 0x0c0842bc */
if(!s->budget--) { s->failed_pc=0x0c0842bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0842be;
P_0c0842be: /* original 6af6, guest PC 0x0c0842be */
if(!s->budget--) { s->failed_pc=0x0c0842beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0842c0;
P_0c0842c0: /* original 6bf6, guest PC 0x0c0842c0 */
if(!s->budget--) { s->failed_pc=0x0c0842c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0842c2;
P_0c0842c2: /* original 6cf6, guest PC 0x0c0842c2 */
if(!s->budget--) { s->failed_pc=0x0c0842c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0842c4;
P_0c0842c4: /* original 6df6, guest PC 0x0c0842c4 */
if(!s->budget--) { s->failed_pc=0x0c0842c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0842c6;
P_0c0842c6: /* original 000b, guest PC 0x0c0842c6 */
if(!s->budget--) { s->failed_pc=0x0c0842c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0842c8: /* original 6ef6, guest PC 0x0c0842c8 */
if(!s->budget--) { s->failed_pc=0x0c0842c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0842cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0842cau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
