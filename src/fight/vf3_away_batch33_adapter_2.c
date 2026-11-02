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
int vf3_away_batch33_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06603cu: goto P_0c06603c;
case 0x0c06603eu: goto P_0c06603e;
case 0x0c066040u: goto P_0c066040;
case 0x0c066042u: goto P_0c066042;
case 0x0c066044u: goto P_0c066044;
case 0x0c066046u: goto P_0c066046;
case 0x0c066048u: goto P_0c066048;
case 0x0c06604au: goto P_0c06604a;
case 0x0c06604cu: goto P_0c06604c;
case 0x0c06604eu: goto P_0c06604e;
case 0x0c066050u: goto P_0c066050;
case 0x0c066052u: goto P_0c066052;
case 0x0c066054u: goto P_0c066054;
case 0x0c066056u: goto P_0c066056;
case 0x0c066058u: goto P_0c066058;
case 0x0c06605au: goto P_0c06605a;
case 0x0c06605cu: goto P_0c06605c;
case 0x0c06605eu: goto P_0c06605e;
case 0x0c066060u: goto P_0c066060;
case 0x0c066062u: goto P_0c066062;
case 0x0c066064u: goto P_0c066064;
case 0x0c066066u: goto P_0c066066;
case 0x0c066068u: goto P_0c066068;
case 0x0c06606au: goto P_0c06606a;
case 0x0c06606cu: goto P_0c06606c;
case 0x0c06606eu: goto P_0c06606e;
case 0x0c066070u: goto P_0c066070;
case 0x0c066072u: goto P_0c066072;
case 0x0c066074u: goto P_0c066074;
case 0x0c066076u: goto P_0c066076;
case 0x0c066078u: goto P_0c066078;
case 0x0c06607au: goto P_0c06607a;
case 0x0c06607cu: goto P_0c06607c;
case 0x0c06607eu: goto P_0c06607e;
case 0x0c066080u: goto P_0c066080;
case 0x0c066082u: goto P_0c066082;
case 0x0c066084u: goto P_0c066084;
case 0x0c066086u: goto P_0c066086;
case 0x0c066088u: goto P_0c066088;
case 0x0c06608au: goto P_0c06608a;
case 0x0c06608cu: goto P_0c06608c;
case 0x0c06608eu: goto P_0c06608e;
case 0x0c066090u: goto P_0c066090;
case 0x0c066092u: goto P_0c066092;
case 0x0c066094u: goto P_0c066094;
case 0x0c066096u: goto P_0c066096;
case 0x0c066098u: goto P_0c066098;
case 0x0c06609au: goto P_0c06609a;
case 0x0c06609cu: goto P_0c06609c;
case 0x0c06609eu: goto P_0c06609e;
case 0x0c0660a0u: goto P_0c0660a0;
case 0x0c0660a2u: goto P_0c0660a2;
case 0x0c0660a4u: goto P_0c0660a4;
case 0x0c0660a6u: goto P_0c0660a6;
case 0x0c0660a8u: goto P_0c0660a8;
case 0x0c0660aau: goto P_0c0660aa;
case 0x0c0660acu: goto P_0c0660ac;
case 0x0c0660aeu: goto P_0c0660ae;
case 0x0c0660b0u: goto P_0c0660b0;
case 0x0c0660b2u: goto P_0c0660b2;
case 0x0c0660b4u: goto P_0c0660b4;
case 0x0c0660b6u: goto P_0c0660b6;
case 0x0c0660b8u: goto P_0c0660b8;
case 0x0c0660bau: goto P_0c0660ba;
case 0x0c0660bcu: goto P_0c0660bc;
case 0x0c0660beu: goto P_0c0660be;
case 0x0c0660c0u: goto P_0c0660c0;
case 0x0c0660c2u: goto P_0c0660c2;
case 0x0c0660c4u: goto P_0c0660c4;
case 0x0c0660c6u: goto P_0c0660c6;
case 0x0c0660c8u: goto P_0c0660c8;
case 0x0c0660cau: goto P_0c0660ca;
case 0x0c0660ccu: goto P_0c0660cc;
case 0x0c0660ceu: goto P_0c0660ce;
case 0x0c0660d0u: goto P_0c0660d0;
case 0x0c0660d2u: goto P_0c0660d2;
case 0x0c0660d4u: goto P_0c0660d4;
case 0x0c0660d6u: goto P_0c0660d6;
case 0x0c0660d8u: goto P_0c0660d8;
case 0x0c0660dau: goto P_0c0660da;
case 0x0c0660dcu: goto P_0c0660dc;
case 0x0c0660deu: goto P_0c0660de;
case 0x0c0660e0u: goto P_0c0660e0;
case 0x0c0660e2u: goto P_0c0660e2;
case 0x0c0660e4u: goto P_0c0660e4;
case 0x0c0660e6u: goto P_0c0660e6;
case 0x0c0660e8u: goto P_0c0660e8;
case 0x0c0660eau: goto P_0c0660ea;
case 0x0c0660ecu: goto P_0c0660ec;
case 0x0c0660eeu: goto P_0c0660ee;
case 0x0c0660f0u: goto P_0c0660f0;
case 0x0c0660f2u: goto P_0c0660f2;
case 0x0c0660f4u: goto P_0c0660f4;
case 0x0c0660f6u: goto P_0c0660f6;
case 0x0c0660f8u: goto P_0c0660f8;
case 0x0c0660fau: goto P_0c0660fa;
case 0x0c0660fcu: goto P_0c0660fc;
case 0x0c0660feu: goto P_0c0660fe;
case 0x0c066100u: goto P_0c066100;
case 0x0c066102u: goto P_0c066102;
case 0x0c066104u: goto P_0c066104;
case 0x0c066106u: goto P_0c066106;
case 0x0c066108u: goto P_0c066108;
case 0x0c06610au: goto P_0c06610a;
case 0x0c06610cu: goto P_0c06610c;
case 0x0c06610eu: goto P_0c06610e;
case 0x0c066110u: goto P_0c066110;
case 0x0c066112u: goto P_0c066112;
case 0x0c066114u: goto P_0c066114;
case 0x0c066116u: goto P_0c066116;
case 0x0c066118u: goto P_0c066118;
case 0x0c06611au: goto P_0c06611a;
case 0x0c06611cu: goto P_0c06611c;
case 0x0c06611eu: goto P_0c06611e;
case 0x0c066120u: goto P_0c066120;
case 0x0c066122u: goto P_0c066122;
case 0x0c066124u: goto P_0c066124;
case 0x0c066126u: goto P_0c066126;
case 0x0c066128u: goto P_0c066128;
case 0x0c06612au: goto P_0c06612a;
case 0x0c06612cu: goto P_0c06612c;
case 0x0c06612eu: goto P_0c06612e;
case 0x0c066130u: goto P_0c066130;
case 0x0c066132u: goto P_0c066132;
case 0x0c066134u: goto P_0c066134;
case 0x0c066136u: goto P_0c066136;
case 0x0c066138u: goto P_0c066138;
case 0x0c06613au: goto P_0c06613a;
case 0x0c06613cu: goto P_0c06613c;
case 0x0c06613eu: goto P_0c06613e;
case 0x0c066140u: goto P_0c066140;
case 0x0c066142u: goto P_0c066142;
case 0x0c066144u: goto P_0c066144;
case 0x0c066146u: goto P_0c066146;
case 0x0c066148u: goto P_0c066148;
case 0x0c06614au: goto P_0c06614a;
case 0x0c06614cu: goto P_0c06614c;
case 0x0c06614eu: goto P_0c06614e;
case 0x0c066150u: goto P_0c066150;
case 0x0c066152u: goto P_0c066152;
case 0x0c066154u: goto P_0c066154;
case 0x0c066156u: goto P_0c066156;
case 0x0c066158u: goto P_0c066158;
case 0x0c06615au: goto P_0c06615a;
case 0x0c06615cu: goto P_0c06615c;
case 0x0c06615eu: goto P_0c06615e;
case 0x0c066160u: goto P_0c066160;
case 0x0c066162u: goto P_0c066162;
case 0x0c066164u: goto P_0c066164;
case 0x0c066166u: goto P_0c066166;
case 0x0c066168u: goto P_0c066168;
case 0x0c06616au: goto P_0c06616a;
case 0x0c06616cu: goto P_0c06616c;
case 0x0c06616eu: goto P_0c06616e;
case 0x0c066170u: goto P_0c066170;
case 0x0c066172u: goto P_0c066172;
case 0x0c066174u: goto P_0c066174;
case 0x0c066176u: goto P_0c066176;
case 0x0c066178u: goto P_0c066178;
case 0x0c06617au: goto P_0c06617a;
case 0x0c06617cu: goto P_0c06617c;
case 0x0c06617eu: goto P_0c06617e;
case 0x0c066180u: goto P_0c066180;
case 0x0c066182u: goto P_0c066182;
case 0x0c066184u: goto P_0c066184;
case 0x0c066186u: goto P_0c066186;
case 0x0c066188u: goto P_0c066188;
case 0x0c06618au: goto P_0c06618a;
case 0x0c06618cu: goto P_0c06618c;
case 0x0c06618eu: goto P_0c06618e;
case 0x0c066190u: goto P_0c066190;
case 0x0c066192u: goto P_0c066192;
case 0x0c066194u: goto P_0c066194;
case 0x0c066196u: goto P_0c066196;
case 0x0c066198u: goto P_0c066198;
case 0x0c06619au: goto P_0c06619a;
case 0x0c06619cu: goto P_0c06619c;
case 0x0c06619eu: goto P_0c06619e;
case 0x0c0661a0u: goto P_0c0661a0;
case 0x0c0661a2u: goto P_0c0661a2;
case 0x0c0661a4u: goto P_0c0661a4;
case 0x0c0661a6u: goto P_0c0661a6;
case 0x0c0661a8u: goto P_0c0661a8;
case 0x0c0661aau: goto P_0c0661aa;
case 0x0c0661acu: goto P_0c0661ac;
case 0x0c0661aeu: goto P_0c0661ae;
case 0x0c0661b0u: goto P_0c0661b0;
case 0x0c0661b2u: goto P_0c0661b2;
case 0x0c0661b4u: goto P_0c0661b4;
case 0x0c0661b6u: goto P_0c0661b6;
case 0x0c0661b8u: goto P_0c0661b8;
case 0x0c0661bau: goto P_0c0661ba;
case 0x0c0661bcu: goto P_0c0661bc;
case 0x0c0661beu: goto P_0c0661be;
case 0x0c0661c0u: goto P_0c0661c0;
case 0x0c0661c2u: goto P_0c0661c2;
case 0x0c0661c4u: goto P_0c0661c4;
case 0x0c0661c6u: goto P_0c0661c6;
case 0x0c0661c8u: goto P_0c0661c8;
case 0x0c0661cau: goto P_0c0661ca;
case 0x0c0661ccu: goto P_0c0661cc;
case 0x0c0661ceu: goto P_0c0661ce;
case 0x0c0661d0u: goto P_0c0661d0;
case 0x0c0661d2u: goto P_0c0661d2;
case 0x0c0661d4u: goto P_0c0661d4;
case 0x0c0661d6u: goto P_0c0661d6;
case 0x0c0661d8u: goto P_0c0661d8;
case 0x0c0661dau: goto P_0c0661da;
case 0x0c0661dcu: goto P_0c0661dc;
case 0x0c0661deu: goto P_0c0661de;
case 0x0c0661e0u: goto P_0c0661e0;
case 0x0c0661e2u: goto P_0c0661e2;
case 0x0c0661e4u: goto P_0c0661e4;
case 0x0c0661e6u: goto P_0c0661e6;
case 0x0c0661e8u: goto P_0c0661e8;
case 0x0c0661eau: goto P_0c0661ea;
case 0x0c0661ecu: goto P_0c0661ec;
case 0x0c0661eeu: goto P_0c0661ee;
case 0x0c0661f0u: goto P_0c0661f0;
case 0x0c0661f2u: goto P_0c0661f2;
case 0x0c0661f4u: goto P_0c0661f4;
case 0x0c0661f6u: goto P_0c0661f6;
case 0x0c0661f8u: goto P_0c0661f8;
case 0x0c0661fau: goto P_0c0661fa;
case 0x0c0661fcu: goto P_0c0661fc;
case 0x0c0661feu: goto P_0c0661fe;
case 0x0c066200u: goto P_0c066200;
case 0x0c066202u: goto P_0c066202;
case 0x0c066204u: goto P_0c066204;
case 0x0c066206u: goto P_0c066206;
case 0x0c066208u: goto P_0c066208;
case 0x0c06620au: goto P_0c06620a;
case 0x0c06620cu: goto P_0c06620c;
case 0x0c06620eu: goto P_0c06620e;
case 0x0c066210u: goto P_0c066210;
case 0x0c066212u: goto P_0c066212;
case 0x0c066214u: goto P_0c066214;
case 0x0c066216u: goto P_0c066216;
case 0x0c066218u: goto P_0c066218;
case 0x0c06621au: goto P_0c06621a;
case 0x0c06621cu: goto P_0c06621c;
case 0x0c06621eu: goto P_0c06621e;
case 0x0c066220u: goto P_0c066220;
case 0x0c066222u: goto P_0c066222;
case 0x0c066224u: goto P_0c066224;
case 0x0c066226u: goto P_0c066226;
case 0x0c066228u: goto P_0c066228;
case 0x0c06622au: goto P_0c06622a;
case 0x0c06622cu: goto P_0c06622c;
case 0x0c06622eu: goto P_0c06622e;
case 0x0c066230u: goto P_0c066230;
case 0x0c066232u: goto P_0c066232;
case 0x0c066234u: goto P_0c066234;
case 0x0c066236u: goto P_0c066236;
case 0x0c066238u: goto P_0c066238;
case 0x0c06623au: goto P_0c06623a;
case 0x0c06623cu: goto P_0c06623c;
case 0x0c06623eu: goto P_0c06623e;
case 0x0c066240u: goto P_0c066240;
case 0x0c066242u: goto P_0c066242;
case 0x0c066244u: goto P_0c066244;
case 0x0c066246u: goto P_0c066246;
case 0x0c066248u: goto P_0c066248;
case 0x0c06624au: goto P_0c06624a;
case 0x0c06624cu: goto P_0c06624c;
case 0x0c06624eu: goto P_0c06624e;
case 0x0c066250u: goto P_0c066250;
case 0x0c066252u: goto P_0c066252;
case 0x0c066254u: goto P_0c066254;
case 0x0c066256u: goto P_0c066256;
case 0x0c066258u: goto P_0c066258;
case 0x0c06625au: goto P_0c06625a;
case 0x0c06625cu: goto P_0c06625c;
case 0x0c06625eu: goto P_0c06625e;
case 0x0c066260u: goto P_0c066260;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06603c: /* original 2fe6, guest PC 0x0c06603c */
if(!s->budget--) { s->failed_pc=0x0c06603cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06603e;
P_0c06603e: /* original 2fd6, guest PC 0x0c06603e */
if(!s->budget--) { s->failed_pc=0x0c06603eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066040;
P_0c066040: /* original 2fc6, guest PC 0x0c066040 */
if(!s->budget--) { s->failed_pc=0x0c066040u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066042;
P_0c066042: /* original 2fb6, guest PC 0x0c066042 */
if(!s->budget--) { s->failed_pc=0x0c066042u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066044;
P_0c066044: /* original 2fa6, guest PC 0x0c066044 */
if(!s->budget--) { s->failed_pc=0x0c066044u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066046;
P_0c066046: /* original eb00, guest PC 0x0c066046 */
if(!s->budget--) { s->failed_pc=0x0c066046u; return 0; }
r[11]=0x00000000u;
goto P_0c066048;
P_0c066048: /* original 2f96, guest PC 0x0c066048 */
if(!s->budget--) { s->failed_pc=0x0c066048u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06604a;
P_0c06604a: /* original fffb, guest PC 0x0c06604a */
if(!s->budget--) { s->failed_pc=0x0c06604au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06604c;
P_0c06604c: /* original 4f22, guest PC 0x0c06604c */
if(!s->budget--) { s->failed_pc=0x0c06604cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06604e;
P_0c06604e: /* original 7ff4, guest PC 0x0c06604e */
if(!s->budget--) { s->failed_pc=0x0c06604eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c066050;
P_0c066050: /* original 6342, guest PC 0x0c066050 */
if(!s->budget--) { s->failed_pc=0x0c066050u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c066052;
P_0c066052: /* original 65f3, guest PC 0x0c066052 */
if(!s->budget--) { s->failed_pc=0x0c066052u; return 0; }
r[5]=r[15];
goto P_0c066054;
P_0c066054: /* original 6d53, guest PC 0x0c066054 */
if(!s->budget--) { s->failed_pc=0x0c066054u; return 0; }
r[13]=r[5];
goto P_0c066056;
P_0c066056: /* original 6cd3, guest PC 0x0c066056 */
if(!s->budget--) { s->failed_pc=0x0c066056u; return 0; }
r[12]=r[13];
goto P_0c066058;
P_0c066058: /* original 2d32, guest PC 0x0c066058 */
if(!s->budget--) { s->failed_pc=0x0c066058u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c06605a;
P_0c06605a: /* original 6ad3, guest PC 0x0c06605a */
if(!s->budget--) { s->failed_pc=0x0c06605au; return 0; }
r[10]=r[13];
goto P_0c06605c;
P_0c06605c: /* original 5241, guest PC 0x0c06605c */
if(!s->budget--) { s->failed_pc=0x0c06605cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c06605e;
P_0c06605e: /* original 7c04, guest PC 0x0c06605e */
if(!s->budget--) { s->failed_pc=0x0c06605eu; return 0; }
r[12]+=0x00000004u;
goto P_0c066060;
P_0c066060: /* original 2c22, guest PC 0x0c066060 */
if(!s->budget--) { s->failed_pc=0x0c066060u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c066062;
P_0c066062: /* original 7a08, guest PC 0x0c066062 */
if(!s->budget--) { s->failed_pc=0x0c066062u; return 0; }
r[10]+=0x00000008u;
goto P_0c066064;
P_0c066064: /* original 5342, guest PC 0x0c066064 */
if(!s->budget--) { s->failed_pc=0x0c066064u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c066066;
P_0c066066: /* original 2a32, guest PC 0x0c066066 */
if(!s->budget--) { s->failed_pc=0x0c066066u; return 0; }
write(ram,r[10],r[3],4);
goto P_0c066068;
P_0c066068: /* original d281, guest PC 0x0c066068 */
if(!s->budget--) { s->failed_pc=0x0c066068u; return 0; }
r[2]=read(ram,0x0c066270u,4);
goto P_0c06606a;
P_0c06606a: /* original 6e22, guest PC 0x0c06606a */
if(!s->budget--) { s->failed_pc=0x0c06606au; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c06606c;
P_0c06606c: /* original d381, guest PC 0x0c06606c */
if(!s->budget--) { s->failed_pc=0x0c06606cu; return 0; }
r[3]=read(ram,0x0c066274u,4);
goto P_0c06606e;
P_0c06606e: /* original 6532, guest PC 0x0c06606e */
if(!s->budget--) { s->failed_pc=0x0c06606eu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c066070;
P_0c066070: /* original d181, guest PC 0x0c066070 */
if(!s->budget--) { s->failed_pc=0x0c066070u; return 0; }
r[1]=read(ram,0x0c066278u,4);
goto P_0c066072;
P_0c066072: /* original 6412, guest PC 0x0c066072 */
if(!s->budget--) { s->failed_pc=0x0c066072u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c066074;
P_0c066074: /* original d081, guest PC 0x0c066074 */
if(!s->budget--) { s->failed_pc=0x0c066074u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c066076;
P_0c066076: /* original 62b3, guest PC 0x0c066076 */
if(!s->budget--) { s->failed_pc=0x0c066076u; return 0; }
r[2]=r[11];
goto P_0c066078;
P_0c066078: /* original 7b01, guest PC 0x0c066078 */
if(!s->budget--) { s->failed_pc=0x0c066078u; return 0; }
r[11]+=0x00000001u;
goto P_0c06607a;
P_0c06607a: /* original 4208, guest PC 0x0c06607a */
if(!s->budget--) { s->failed_pc=0x0c06607au; return 0; }
r[2]<<=2;
goto P_0c06607c;
P_0c06607c: /* original 02e6, guest PC 0x0c06607c */
if(!s->budget--) { s->failed_pc=0x0c06607cu; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c06607e;
P_0c06607e: /* original 63b3, guest PC 0x0c06607e */
if(!s->budget--) { s->failed_pc=0x0c06607eu; return 0; }
r[3]=r[11];
goto P_0c066080;
P_0c066080: /* original 7b01, guest PC 0x0c066080 */
if(!s->budget--) { s->failed_pc=0x0c066080u; return 0; }
r[11]+=0x00000001u;
goto P_0c066082;
P_0c066082: /* original 4308, guest PC 0x0c066082 */
if(!s->budget--) { s->failed_pc=0x0c066082u; return 0; }
r[3]<<=2;
goto P_0c066084;
P_0c066084: /* original 0356, guest PC 0x0c066084 */
if(!s->budget--) { s->failed_pc=0x0c066084u; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c066086;
P_0c066086: /* original 62b3, guest PC 0x0c066086 */
if(!s->budget--) { s->failed_pc=0x0c066086u; return 0; }
r[2]=r[11];
goto P_0c066088;
P_0c066088: /* original 7b01, guest PC 0x0c066088 */
if(!s->budget--) { s->failed_pc=0x0c066088u; return 0; }
r[11]+=0x00000001u;
goto P_0c06608a;
P_0c06608a: /* original 4208, guest PC 0x0c06608a */
if(!s->budget--) { s->failed_pc=0x0c06608au; return 0; }
r[2]<<=2;
goto P_0c06608c;
P_0c06608c: /* original 0246, guest PC 0x0c06608c */
if(!s->budget--) { s->failed_pc=0x0c06608cu; return 0; }
write(ram,r[2]+r[0],r[4],4);
goto P_0c06608e;
P_0c06608e: /* original 63b3, guest PC 0x0c06608e */
if(!s->budget--) { s->failed_pc=0x0c06608eu; return 0; }
r[3]=r[11];
goto P_0c066090;
P_0c066090: /* original 62d2, guest PC 0x0c066090 */
if(!s->budget--) { s->failed_pc=0x0c066090u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c066092;
P_0c066092: /* original 7b01, guest PC 0x0c066092 */
if(!s->budget--) { s->failed_pc=0x0c066092u; return 0; }
r[11]+=0x00000001u;
goto P_0c066094;
P_0c066094: /* original 5221, guest PC 0x0c066094 */
if(!s->budget--) { s->failed_pc=0x0c066094u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c066096;
P_0c066096: /* original 4308, guest PC 0x0c066096 */
if(!s->budget--) { s->failed_pc=0x0c066096u; return 0; }
r[3]<<=2;
goto P_0c066098;
P_0c066098: /* original 0326, guest PC 0x0c066098 */
if(!s->budget--) { s->failed_pc=0x0c066098u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c06609a;
P_0c06609a: /* original 63b3, guest PC 0x0c06609a */
if(!s->budget--) { s->failed_pc=0x0c06609au; return 0; }
r[3]=r[11];
goto P_0c06609c;
P_0c06609c: /* original 62d2, guest PC 0x0c06609c */
if(!s->budget--) { s->failed_pc=0x0c06609cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c06609e;
P_0c06609e: /* original 7b01, guest PC 0x0c06609e */
if(!s->budget--) { s->failed_pc=0x0c06609eu; return 0; }
r[11]+=0x00000001u;
goto P_0c0660a0;
P_0c0660a0: /* original 5222, guest PC 0x0c0660a0 */
if(!s->budget--) { s->failed_pc=0x0c0660a0u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c0660a2;
P_0c0660a2: /* original 4308, guest PC 0x0c0660a2 */
if(!s->budget--) { s->failed_pc=0x0c0660a2u; return 0; }
r[3]<<=2;
goto P_0c0660a4;
P_0c0660a4: /* original 0326, guest PC 0x0c0660a4 */
if(!s->budget--) { s->failed_pc=0x0c0660a4u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0660a6;
P_0c0660a6: /* original 63b3, guest PC 0x0c0660a6 */
if(!s->budget--) { s->failed_pc=0x0c0660a6u; return 0; }
r[3]=r[11];
goto P_0c0660a8;
P_0c0660a8: /* original 62d2, guest PC 0x0c0660a8 */
if(!s->budget--) { s->failed_pc=0x0c0660a8u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0660aa;
P_0c0660aa: /* original 7b01, guest PC 0x0c0660aa */
if(!s->budget--) { s->failed_pc=0x0c0660aau; return 0; }
r[11]+=0x00000001u;
goto P_0c0660ac;
P_0c0660ac: /* original 5223, guest PC 0x0c0660ac */
if(!s->budget--) { s->failed_pc=0x0c0660acu; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c0660ae;
P_0c0660ae: /* original 4308, guest PC 0x0c0660ae */
if(!s->budget--) { s->failed_pc=0x0c0660aeu; return 0; }
r[3]<<=2;
goto P_0c0660b0;
P_0c0660b0: /* original 0326, guest PC 0x0c0660b0 */
if(!s->budget--) { s->failed_pc=0x0c0660b0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0660b2;
P_0c0660b2: /* original 65b3, guest PC 0x0c0660b2 */
if(!s->budget--) { s->failed_pc=0x0c0660b2u; return 0; }
r[5]=r[11];
goto P_0c0660b4;
P_0c0660b4: /* original d372, guest PC 0x0c0660b4 */
if(!s->budget--) { s->failed_pc=0x0c0660b4u; return 0; }
r[3]=read(ram,0x0c066280u,4);
goto P_0c0660b6;
P_0c0660b6: /* original 66d2, guest PC 0x0c0660b6 */
if(!s->budget--) { s->failed_pc=0x0c0660b6u; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c0660b8;
P_0c0660b8: /* original 5664, guest PC 0x0c0660b8 */
if(!s->budget--) { s->failed_pc=0x0c0660b8u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0660ba;
P_0c0660ba: /* original 430b, guest PC 0x0c0660ba */
if(!s->budget--) { s->failed_pc=0x0c0660bau; return 0; }
target=r[3];
r[16]=code_base|0x0c0660beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0660beu) { target=s->pc; goto dispatch; }
goto P_0c0660be;
P_0c0660bc: /* original 64e3, guest PC 0x0c0660bc */
if(!s->budget--) { s->failed_pc=0x0c0660bcu; return 0; }
r[4]=r[14];
goto P_0c0660be;
P_0c0660be: /* original 6903, guest PC 0x0c0660be */
if(!s->budget--) { s->failed_pc=0x0c0660beu; return 0; }
r[9]=r[0];
goto P_0c0660c0;
P_0c0660c0: /* original 64d2, guest PC 0x0c0660c0 */
if(!s->budget--) { s->failed_pc=0x0c0660c0u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0660c2;
P_0c0660c2: /* original e118, guest PC 0x0c0660c2 */
if(!s->budget--) { s->failed_pc=0x0c0660c2u; return 0; }
r[1]=0x00000018u;
goto P_0c0660c4;
P_0c0660c4: /* original c76f, guest PC 0x0c0660c4 */
if(!s->budget--) { s->failed_pc=0x0c0660c4u; return 0; }
r[0]=code_base|0x00066284u;
goto P_0c0660c6;
P_0c0660c6: /* original 6393, guest PC 0x0c0660c6 */
if(!s->budget--) { s->failed_pc=0x0c0660c6u; return 0; }
r[3]=r[9];
goto P_0c0660c8;
P_0c0660c8: /* original ff08, guest PC 0x0c0660c8 */
if(!s->budget--) { s->failed_pc=0x0c0660c8u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0660ca;
P_0c0660ca: /* original 314c, guest PC 0x0c0660ca */
if(!s->budget--) { s->failed_pc=0x0c0660cau; return 0; }
r[1]+=r[4];
goto P_0c0660cc;
P_0c0660cc: /* original d06b, guest PC 0x0c0660cc */
if(!s->budget--) { s->failed_pc=0x0c0660ccu; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c0660ce;
P_0c0660ce: /* original 7901, guest PC 0x0c0660ce */
if(!s->budget--) { s->failed_pc=0x0c0660ceu; return 0; }
r[9]+=0x00000001u;
goto P_0c0660d0;
P_0c0660d0: /* original f318, guest PC 0x0c0660d0 */
if(!s->budget--) { s->failed_pc=0x0c0660d0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0660d2;
P_0c0660d2: /* original 4308, guest PC 0x0c0660d2 */
if(!s->budget--) { s->failed_pc=0x0c0660d2u; return 0; }
r[3]<<=2;
goto P_0c0660d4;
P_0c0660d4: /* original f3f2, guest PC 0x0c0660d4 */
if(!s->budget--) { s->failed_pc=0x0c0660d4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0660d6;
P_0c0660d6: /* original f33d, guest PC 0x0c0660d6 */
if(!s->budget--) { s->failed_pc=0x0c0660d6u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0660d8;
P_0c0660d8: /* original 045a, guest PC 0x0c0660d8 */
if(!s->budget--) { s->failed_pc=0x0c0660d8u; return 0; }
r[4]=r[53];
goto P_0c0660da;
P_0c0660da: /* original 6243, guest PC 0x0c0660da */
if(!s->budget--) { s->failed_pc=0x0c0660dau; return 0; }
r[2]=r[4];
goto P_0c0660dc;
P_0c0660dc: /* original 4228, guest PC 0x0c0660dc */
if(!s->budget--) { s->failed_pc=0x0c0660dcu; return 0; }
r[2]<<=16;
goto P_0c0660de;
P_0c0660de: /* original 4218, guest PC 0x0c0660de */
if(!s->budget--) { s->failed_pc=0x0c0660deu; return 0; }
r[2]<<=8;
goto P_0c0660e0;
P_0c0660e0: /* original 6143, guest PC 0x0c0660e0 */
if(!s->budget--) { s->failed_pc=0x0c0660e0u; return 0; }
r[1]=r[4];
goto P_0c0660e2;
P_0c0660e2: /* original 4128, guest PC 0x0c0660e2 */
if(!s->budget--) { s->failed_pc=0x0c0660e2u; return 0; }
r[1]<<=16;
goto P_0c0660e4;
P_0c0660e4: /* original 221b, guest PC 0x0c0660e4 */
if(!s->budget--) { s->failed_pc=0x0c0660e4u; return 0; }
r[2]|=r[1];
goto P_0c0660e6;
P_0c0660e6: /* original 6143, guest PC 0x0c0660e6 */
if(!s->budget--) { s->failed_pc=0x0c0660e6u; return 0; }
r[1]=r[4];
goto P_0c0660e8;
P_0c0660e8: /* original 4118, guest PC 0x0c0660e8 */
if(!s->budget--) { s->failed_pc=0x0c0660e8u; return 0; }
r[1]<<=8;
goto P_0c0660ea;
P_0c0660ea: /* original 221b, guest PC 0x0c0660ea */
if(!s->budget--) { s->failed_pc=0x0c0660eau; return 0; }
r[2]|=r[1];
goto P_0c0660ec;
P_0c0660ec: /* original 224b, guest PC 0x0c0660ec */
if(!s->budget--) { s->failed_pc=0x0c0660ecu; return 0; }
r[2]|=r[4];
goto P_0c0660ee;
P_0c0660ee: /* original 0326, guest PC 0x0c0660ee */
if(!s->budget--) { s->failed_pc=0x0c0660eeu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c0660f0;
P_0c0660f0: /* original 6bd2, guest PC 0x0c0660f0 */
if(!s->budget--) { s->failed_pc=0x0c0660f0u; return 0; }
tmp=read(ram,r[13],4);
r[11]=tmp;
goto P_0c0660f2;
P_0c0660f2: /* original e01c, guest PC 0x0c0660f2 */
if(!s->budget--) { s->failed_pc=0x0c0660f2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0660f4;
P_0c0660f4: /* original f3b6, guest PC 0x0c0660f4 */
if(!s->budget--) { s->failed_pc=0x0c0660f4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c0660f6;
P_0c0660f6: /* original f3f2, guest PC 0x0c0660f6 */
if(!s->budget--) { s->failed_pc=0x0c0660f6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0660f8;
P_0c0660f8: /* original f33d, guest PC 0x0c0660f8 */
if(!s->budget--) { s->failed_pc=0x0c0660f8u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0660fa;
P_0c0660fa: /* original 0b5a, guest PC 0x0c0660fa */
if(!s->budget--) { s->failed_pc=0x0c0660fau; return 0; }
r[11]=r[53];
goto P_0c0660fc;
P_0c0660fc: /* original 66b3, guest PC 0x0c0660fc */
if(!s->budget--) { s->failed_pc=0x0c0660fcu; return 0; }
r[6]=r[11];
goto P_0c0660fe;
P_0c0660fe: /* original 4628, guest PC 0x0c0660fe */
if(!s->budget--) { s->failed_pc=0x0c0660feu; return 0; }
r[6]<<=16;
goto P_0c066100;
P_0c066100: /* original 4618, guest PC 0x0c066100 */
if(!s->budget--) { s->failed_pc=0x0c066100u; return 0; }
r[6]<<=8;
goto P_0c066102;
P_0c066102: /* original 63b3, guest PC 0x0c066102 */
if(!s->budget--) { s->failed_pc=0x0c066102u; return 0; }
r[3]=r[11];
goto P_0c066104;
P_0c066104: /* original 4328, guest PC 0x0c066104 */
if(!s->budget--) { s->failed_pc=0x0c066104u; return 0; }
r[3]<<=16;
goto P_0c066106;
P_0c066106: /* original 263b, guest PC 0x0c066106 */
if(!s->budget--) { s->failed_pc=0x0c066106u; return 0; }
r[6]|=r[3];
goto P_0c066108;
P_0c066108: /* original d35f, guest PC 0x0c066108 */
if(!s->budget--) { s->failed_pc=0x0c066108u; return 0; }
r[3]=read(ram,0x0c066288u,4);
goto P_0c06610a;
P_0c06610a: /* original 62b3, guest PC 0x0c06610a */
if(!s->budget--) { s->failed_pc=0x0c06610au; return 0; }
r[2]=r[11];
goto P_0c06610c;
P_0c06610c: /* original 4218, guest PC 0x0c06610c */
if(!s->budget--) { s->failed_pc=0x0c06610cu; return 0; }
r[2]<<=8;
goto P_0c06610e;
P_0c06610e: /* original 262b, guest PC 0x0c06610e */
if(!s->budget--) { s->failed_pc=0x0c06610eu; return 0; }
r[6]|=r[2];
goto P_0c066110;
P_0c066110: /* original 26bb, guest PC 0x0c066110 */
if(!s->budget--) { s->failed_pc=0x0c066110u; return 0; }
r[6]|=r[11];
goto P_0c066112;
P_0c066112: /* original 6593, guest PC 0x0c066112 */
if(!s->budget--) { s->failed_pc=0x0c066112u; return 0; }
r[5]=r[9];
goto P_0c066114;
P_0c066114: /* original 430b, guest PC 0x0c066114 */
if(!s->budget--) { s->failed_pc=0x0c066114u; return 0; }
target=r[3];
r[16]=code_base|0x0c066118u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066118u) { target=s->pc; goto dispatch; }
goto P_0c066118;
P_0c066116: /* original 64e3, guest PC 0x0c066116 */
if(!s->budget--) { s->failed_pc=0x0c066116u; return 0; }
r[4]=r[14];
goto P_0c066118;
P_0c066118: /* original 61c2, guest PC 0x0c066118 */
if(!s->budget--) { s->failed_pc=0x0c066118u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c06611a;
P_0c06611a: /* original 6b03, guest PC 0x0c06611a */
if(!s->budget--) { s->failed_pc=0x0c06611au; return 0; }
r[11]=r[0];
goto P_0c06611c;
P_0c06611c: /* original 5311, guest PC 0x0c06611c */
if(!s->budget--) { s->failed_pc=0x0c06611cu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c06611e;
P_0c06611e: /* original 62b3, guest PC 0x0c06611e */
if(!s->budget--) { s->failed_pc=0x0c06611eu; return 0; }
r[2]=r[11];
goto P_0c066120;
P_0c066120: /* original d056, guest PC 0x0c066120 */
if(!s->budget--) { s->failed_pc=0x0c066120u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c066122;
P_0c066122: /* original 7b01, guest PC 0x0c066122 */
if(!s->budget--) { s->failed_pc=0x0c066122u; return 0; }
r[11]+=0x00000001u;
goto P_0c066124;
P_0c066124: /* original 4208, guest PC 0x0c066124 */
if(!s->budget--) { s->failed_pc=0x0c066124u; return 0; }
r[2]<<=2;
goto P_0c066126;
P_0c066126: /* original 0236, guest PC 0x0c066126 */
if(!s->budget--) { s->failed_pc=0x0c066126u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066128;
P_0c066128: /* original 61c2, guest PC 0x0c066128 */
if(!s->budget--) { s->failed_pc=0x0c066128u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c06612a;
P_0c06612a: /* original 62b3, guest PC 0x0c06612a */
if(!s->budget--) { s->failed_pc=0x0c06612au; return 0; }
r[2]=r[11];
goto P_0c06612c;
P_0c06612c: /* original 5312, guest PC 0x0c06612c */
if(!s->budget--) { s->failed_pc=0x0c06612cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c06612e;
P_0c06612e: /* original 7b01, guest PC 0x0c06612e */
if(!s->budget--) { s->failed_pc=0x0c06612eu; return 0; }
r[11]+=0x00000001u;
goto P_0c066130;
P_0c066130: /* original 4208, guest PC 0x0c066130 */
if(!s->budget--) { s->failed_pc=0x0c066130u; return 0; }
r[2]<<=2;
goto P_0c066132;
P_0c066132: /* original 0236, guest PC 0x0c066132 */
if(!s->budget--) { s->failed_pc=0x0c066132u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066134;
P_0c066134: /* original 61c2, guest PC 0x0c066134 */
if(!s->budget--) { s->failed_pc=0x0c066134u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c066136;
P_0c066136: /* original 62b3, guest PC 0x0c066136 */
if(!s->budget--) { s->failed_pc=0x0c066136u; return 0; }
r[2]=r[11];
goto P_0c066138;
P_0c066138: /* original 5313, guest PC 0x0c066138 */
if(!s->budget--) { s->failed_pc=0x0c066138u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c06613a;
P_0c06613a: /* original 7b01, guest PC 0x0c06613a */
if(!s->budget--) { s->failed_pc=0x0c06613au; return 0; }
r[11]+=0x00000001u;
goto P_0c06613c;
P_0c06613c: /* original 4208, guest PC 0x0c06613c */
if(!s->budget--) { s->failed_pc=0x0c06613cu; return 0; }
r[2]<<=2;
goto P_0c06613e;
P_0c06613e: /* original 0236, guest PC 0x0c06613e */
if(!s->budget--) { s->failed_pc=0x0c06613eu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066140;
P_0c066140: /* original 66c2, guest PC 0x0c066140 */
if(!s->budget--) { s->failed_pc=0x0c066140u; return 0; }
tmp=read(ram,r[12],4);
r[6]=tmp;
goto P_0c066142;
P_0c066142: /* original 65b3, guest PC 0x0c066142 */
if(!s->budget--) { s->failed_pc=0x0c066142u; return 0; }
r[5]=r[11];
goto P_0c066144;
P_0c066144: /* original d34e, guest PC 0x0c066144 */
if(!s->budget--) { s->failed_pc=0x0c066144u; return 0; }
r[3]=read(ram,0x0c066280u,4);
goto P_0c066146;
P_0c066146: /* original 5664, guest PC 0x0c066146 */
if(!s->budget--) { s->failed_pc=0x0c066146u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c066148;
P_0c066148: /* original 430b, guest PC 0x0c066148 */
if(!s->budget--) { s->failed_pc=0x0c066148u; return 0; }
target=r[3];
r[16]=code_base|0x0c06614cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06614cu) { target=s->pc; goto dispatch; }
goto P_0c06614c;
P_0c06614a: /* original 64e3, guest PC 0x0c06614a */
if(!s->budget--) { s->failed_pc=0x0c06614au; return 0; }
r[4]=r[14];
goto P_0c06614c;
P_0c06614c: /* original 64c2, guest PC 0x0c06614c */
if(!s->budget--) { s->failed_pc=0x0c06614cu; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c06614e;
P_0c06614e: /* original e118, guest PC 0x0c06614e */
if(!s->budget--) { s->failed_pc=0x0c06614eu; return 0; }
r[1]=0x00000018u;
goto P_0c066150;
P_0c066150: /* original 6903, guest PC 0x0c066150 */
if(!s->budget--) { s->failed_pc=0x0c066150u; return 0; }
r[9]=r[0];
goto P_0c066152;
P_0c066152: /* original 6293, guest PC 0x0c066152 */
if(!s->budget--) { s->failed_pc=0x0c066152u; return 0; }
r[2]=r[9];
goto P_0c066154;
P_0c066154: /* original d049, guest PC 0x0c066154 */
if(!s->budget--) { s->failed_pc=0x0c066154u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c066156;
P_0c066156: /* original 314c, guest PC 0x0c066156 */
if(!s->budget--) { s->failed_pc=0x0c066156u; return 0; }
r[1]+=r[4];
goto P_0c066158;
P_0c066158: /* original f318, guest PC 0x0c066158 */
if(!s->budget--) { s->failed_pc=0x0c066158u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c06615a;
P_0c06615a: /* original 7901, guest PC 0x0c06615a */
if(!s->budget--) { s->failed_pc=0x0c06615au; return 0; }
r[9]+=0x00000001u;
goto P_0c06615c;
P_0c06615c: /* original 4208, guest PC 0x0c06615c */
if(!s->budget--) { s->failed_pc=0x0c06615cu; return 0; }
r[2]<<=2;
goto P_0c06615e;
P_0c06615e: /* original f3f2, guest PC 0x0c06615e */
if(!s->budget--) { s->failed_pc=0x0c06615eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c066160;
P_0c066160: /* original f33d, guest PC 0x0c066160 */
if(!s->budget--) { s->failed_pc=0x0c066160u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c066162;
P_0c066162: /* original 045a, guest PC 0x0c066162 */
if(!s->budget--) { s->failed_pc=0x0c066162u; return 0; }
r[4]=r[53];
goto P_0c066164;
P_0c066164: /* original 6343, guest PC 0x0c066164 */
if(!s->budget--) { s->failed_pc=0x0c066164u; return 0; }
r[3]=r[4];
goto P_0c066166;
P_0c066166: /* original 4328, guest PC 0x0c066166 */
if(!s->budget--) { s->failed_pc=0x0c066166u; return 0; }
r[3]<<=16;
goto P_0c066168;
P_0c066168: /* original 4318, guest PC 0x0c066168 */
if(!s->budget--) { s->failed_pc=0x0c066168u; return 0; }
r[3]<<=8;
goto P_0c06616a;
P_0c06616a: /* original 6143, guest PC 0x0c06616a */
if(!s->budget--) { s->failed_pc=0x0c06616au; return 0; }
r[1]=r[4];
goto P_0c06616c;
P_0c06616c: /* original 4128, guest PC 0x0c06616c */
if(!s->budget--) { s->failed_pc=0x0c06616cu; return 0; }
r[1]<<=16;
goto P_0c06616e;
P_0c06616e: /* original 231b, guest PC 0x0c06616e */
if(!s->budget--) { s->failed_pc=0x0c06616eu; return 0; }
r[3]|=r[1];
goto P_0c066170;
P_0c066170: /* original 6143, guest PC 0x0c066170 */
if(!s->budget--) { s->failed_pc=0x0c066170u; return 0; }
r[1]=r[4];
goto P_0c066172;
P_0c066172: /* original 4118, guest PC 0x0c066172 */
if(!s->budget--) { s->failed_pc=0x0c066172u; return 0; }
r[1]<<=8;
goto P_0c066174;
P_0c066174: /* original 231b, guest PC 0x0c066174 */
if(!s->budget--) { s->failed_pc=0x0c066174u; return 0; }
r[3]|=r[1];
goto P_0c066176;
P_0c066176: /* original 234b, guest PC 0x0c066176 */
if(!s->budget--) { s->failed_pc=0x0c066176u; return 0; }
r[3]|=r[4];
goto P_0c066178;
P_0c066178: /* original 0236, guest PC 0x0c066178 */
if(!s->budget--) { s->failed_pc=0x0c066178u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c06617a;
P_0c06617a: /* original e01c, guest PC 0x0c06617a */
if(!s->budget--) { s->failed_pc=0x0c06617au; return 0; }
r[0]=0x0000001cu;
goto P_0c06617c;
P_0c06617c: /* original 6bc2, guest PC 0x0c06617c */
if(!s->budget--) { s->failed_pc=0x0c06617cu; return 0; }
tmp=read(ram,r[12],4);
r[11]=tmp;
goto P_0c06617e;
P_0c06617e: /* original f3b6, guest PC 0x0c06617e */
if(!s->budget--) { s->failed_pc=0x0c06617eu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c066180;
P_0c066180: /* original f3f2, guest PC 0x0c066180 */
if(!s->budget--) { s->failed_pc=0x0c066180u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c066182;
P_0c066182: /* original f33d, guest PC 0x0c066182 */
if(!s->budget--) { s->failed_pc=0x0c066182u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c066184;
P_0c066184: /* original 0b5a, guest PC 0x0c066184 */
if(!s->budget--) { s->failed_pc=0x0c066184u; return 0; }
r[11]=r[53];
goto P_0c066186;
P_0c066186: /* original 66b3, guest PC 0x0c066186 */
if(!s->budget--) { s->failed_pc=0x0c066186u; return 0; }
r[6]=r[11];
goto P_0c066188;
P_0c066188: /* original 4628, guest PC 0x0c066188 */
if(!s->budget--) { s->failed_pc=0x0c066188u; return 0; }
r[6]<<=16;
goto P_0c06618a;
P_0c06618a: /* original 4618, guest PC 0x0c06618a */
if(!s->budget--) { s->failed_pc=0x0c06618au; return 0; }
r[6]<<=8;
goto P_0c06618c;
P_0c06618c: /* original 63b3, guest PC 0x0c06618c */
if(!s->budget--) { s->failed_pc=0x0c06618cu; return 0; }
r[3]=r[11];
goto P_0c06618e;
P_0c06618e: /* original 4328, guest PC 0x0c06618e */
if(!s->budget--) { s->failed_pc=0x0c06618eu; return 0; }
r[3]<<=16;
goto P_0c066190;
P_0c066190: /* original 263b, guest PC 0x0c066190 */
if(!s->budget--) { s->failed_pc=0x0c066190u; return 0; }
r[6]|=r[3];
goto P_0c066192;
P_0c066192: /* original 62b3, guest PC 0x0c066192 */
if(!s->budget--) { s->failed_pc=0x0c066192u; return 0; }
r[2]=r[11];
goto P_0c066194;
P_0c066194: /* original d33c, guest PC 0x0c066194 */
if(!s->budget--) { s->failed_pc=0x0c066194u; return 0; }
r[3]=read(ram,0x0c066288u,4);
goto P_0c066196;
P_0c066196: /* original 6593, guest PC 0x0c066196 */
if(!s->budget--) { s->failed_pc=0x0c066196u; return 0; }
r[5]=r[9];
goto P_0c066198;
P_0c066198: /* original 4218, guest PC 0x0c066198 */
if(!s->budget--) { s->failed_pc=0x0c066198u; return 0; }
r[2]<<=8;
goto P_0c06619a;
P_0c06619a: /* original 262b, guest PC 0x0c06619a */
if(!s->budget--) { s->failed_pc=0x0c06619au; return 0; }
r[6]|=r[2];
goto P_0c06619c;
P_0c06619c: /* original 26bb, guest PC 0x0c06619c */
if(!s->budget--) { s->failed_pc=0x0c06619cu; return 0; }
r[6]|=r[11];
goto P_0c06619e;
P_0c06619e: /* original 430b, guest PC 0x0c06619e */
if(!s->budget--) { s->failed_pc=0x0c06619eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0661a2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0661a2u) { target=s->pc; goto dispatch; }
goto P_0c0661a2;
P_0c0661a0: /* original 64e3, guest PC 0x0c0661a0 */
if(!s->budget--) { s->failed_pc=0x0c0661a0u; return 0; }
r[4]=r[14];
goto P_0c0661a2;
P_0c0661a2: /* original 6c03, guest PC 0x0c0661a2 */
if(!s->budget--) { s->failed_pc=0x0c0661a2u; return 0; }
r[12]=r[0];
goto P_0c0661a4;
P_0c0661a4: /* original 61a2, guest PC 0x0c0661a4 */
if(!s->budget--) { s->failed_pc=0x0c0661a4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0661a6;
P_0c0661a6: /* original 62c3, guest PC 0x0c0661a6 */
if(!s->budget--) { s->failed_pc=0x0c0661a6u; return 0; }
r[2]=r[12];
goto P_0c0661a8;
P_0c0661a8: /* original d034, guest PC 0x0c0661a8 */
if(!s->budget--) { s->failed_pc=0x0c0661a8u; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c0661aa;
P_0c0661aa: /* original 7c01, guest PC 0x0c0661aa */
if(!s->budget--) { s->failed_pc=0x0c0661aau; return 0; }
r[12]+=0x00000001u;
goto P_0c0661ac;
P_0c0661ac: /* original 5311, guest PC 0x0c0661ac */
if(!s->budget--) { s->failed_pc=0x0c0661acu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0661ae;
P_0c0661ae: /* original 4208, guest PC 0x0c0661ae */
if(!s->budget--) { s->failed_pc=0x0c0661aeu; return 0; }
r[2]<<=2;
goto P_0c0661b0;
P_0c0661b0: /* original 0236, guest PC 0x0c0661b0 */
if(!s->budget--) { s->failed_pc=0x0c0661b0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0661b2;
P_0c0661b2: /* original 62c3, guest PC 0x0c0661b2 */
if(!s->budget--) { s->failed_pc=0x0c0661b2u; return 0; }
r[2]=r[12];
goto P_0c0661b4;
P_0c0661b4: /* original 61a2, guest PC 0x0c0661b4 */
if(!s->budget--) { s->failed_pc=0x0c0661b4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0661b6;
P_0c0661b6: /* original 7c01, guest PC 0x0c0661b6 */
if(!s->budget--) { s->failed_pc=0x0c0661b6u; return 0; }
r[12]+=0x00000001u;
goto P_0c0661b8;
P_0c0661b8: /* original 5312, guest PC 0x0c0661b8 */
if(!s->budget--) { s->failed_pc=0x0c0661b8u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c0661ba;
P_0c0661ba: /* original 4208, guest PC 0x0c0661ba */
if(!s->budget--) { s->failed_pc=0x0c0661bau; return 0; }
r[2]<<=2;
goto P_0c0661bc;
P_0c0661bc: /* original 0236, guest PC 0x0c0661bc */
if(!s->budget--) { s->failed_pc=0x0c0661bcu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0661be;
P_0c0661be: /* original 62c3, guest PC 0x0c0661be */
if(!s->budget--) { s->failed_pc=0x0c0661beu; return 0; }
r[2]=r[12];
goto P_0c0661c0;
P_0c0661c0: /* original 61a2, guest PC 0x0c0661c0 */
if(!s->budget--) { s->failed_pc=0x0c0661c0u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c0661c2;
P_0c0661c2: /* original 7c01, guest PC 0x0c0661c2 */
if(!s->budget--) { s->failed_pc=0x0c0661c2u; return 0; }
r[12]+=0x00000001u;
goto P_0c0661c4;
P_0c0661c4: /* original 5313, guest PC 0x0c0661c4 */
if(!s->budget--) { s->failed_pc=0x0c0661c4u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c0661c6;
P_0c0661c6: /* original 4208, guest PC 0x0c0661c6 */
if(!s->budget--) { s->failed_pc=0x0c0661c6u; return 0; }
r[2]<<=2;
goto P_0c0661c8;
P_0c0661c8: /* original 0236, guest PC 0x0c0661c8 */
if(!s->budget--) { s->failed_pc=0x0c0661c8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0661ca;
P_0c0661ca: /* original 65c3, guest PC 0x0c0661ca */
if(!s->budget--) { s->failed_pc=0x0c0661cau; return 0; }
r[5]=r[12];
goto P_0c0661cc;
P_0c0661cc: /* original d32c, guest PC 0x0c0661cc */
if(!s->budget--) { s->failed_pc=0x0c0661ccu; return 0; }
r[3]=read(ram,0x0c066280u,4);
goto P_0c0661ce;
P_0c0661ce: /* original 66a2, guest PC 0x0c0661ce */
if(!s->budget--) { s->failed_pc=0x0c0661ceu; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c0661d0;
P_0c0661d0: /* original 5664, guest PC 0x0c0661d0 */
if(!s->budget--) { s->failed_pc=0x0c0661d0u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c0661d2;
P_0c0661d2: /* original 430b, guest PC 0x0c0661d2 */
if(!s->budget--) { s->failed_pc=0x0c0661d2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0661d6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0661d6u) { target=s->pc; goto dispatch; }
goto P_0c0661d6;
P_0c0661d4: /* original 64e3, guest PC 0x0c0661d4 */
if(!s->budget--) { s->failed_pc=0x0c0661d4u; return 0; }
r[4]=r[14];
goto P_0c0661d6;
P_0c0661d6: /* original 6b03, guest PC 0x0c0661d6 */
if(!s->budget--) { s->failed_pc=0x0c0661d6u; return 0; }
r[11]=r[0];
goto P_0c0661d8;
P_0c0661d8: /* original 64a2, guest PC 0x0c0661d8 */
if(!s->budget--) { s->failed_pc=0x0c0661d8u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0661da;
P_0c0661da: /* original e118, guest PC 0x0c0661da */
if(!s->budget--) { s->failed_pc=0x0c0661dau; return 0; }
r[1]=0x00000018u;
goto P_0c0661dc;
P_0c0661dc: /* original d027, guest PC 0x0c0661dc */
if(!s->budget--) { s->failed_pc=0x0c0661dcu; return 0; }
r[0]=read(ram,0x0c06627cu,4);
goto P_0c0661de;
P_0c0661de: /* original 62b3, guest PC 0x0c0661de */
if(!s->budget--) { s->failed_pc=0x0c0661deu; return 0; }
r[2]=r[11];
goto P_0c0661e0;
P_0c0661e0: /* original 7b01, guest PC 0x0c0661e0 */
if(!s->budget--) { s->failed_pc=0x0c0661e0u; return 0; }
r[11]+=0x00000001u;
goto P_0c0661e2;
P_0c0661e2: /* original 4208, guest PC 0x0c0661e2 */
if(!s->budget--) { s->failed_pc=0x0c0661e2u; return 0; }
r[2]<<=2;
goto P_0c0661e4;
P_0c0661e4: /* original 314c, guest PC 0x0c0661e4 */
if(!s->budget--) { s->failed_pc=0x0c0661e4u; return 0; }
r[1]+=r[4];
goto P_0c0661e6;
P_0c0661e6: /* original f318, guest PC 0x0c0661e6 */
if(!s->budget--) { s->failed_pc=0x0c0661e6u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0661e8;
P_0c0661e8: /* original f3f2, guest PC 0x0c0661e8 */
if(!s->budget--) { s->failed_pc=0x0c0661e8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0661ea;
P_0c0661ea: /* original f33d, guest PC 0x0c0661ea */
if(!s->budget--) { s->failed_pc=0x0c0661eau; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0661ec;
P_0c0661ec: /* original 045a, guest PC 0x0c0661ec */
if(!s->budget--) { s->failed_pc=0x0c0661ecu; return 0; }
r[4]=r[53];
goto P_0c0661ee;
P_0c0661ee: /* original 6343, guest PC 0x0c0661ee */
if(!s->budget--) { s->failed_pc=0x0c0661eeu; return 0; }
r[3]=r[4];
goto P_0c0661f0;
P_0c0661f0: /* original 4328, guest PC 0x0c0661f0 */
if(!s->budget--) { s->failed_pc=0x0c0661f0u; return 0; }
r[3]<<=16;
goto P_0c0661f2;
P_0c0661f2: /* original 4318, guest PC 0x0c0661f2 */
if(!s->budget--) { s->failed_pc=0x0c0661f2u; return 0; }
r[3]<<=8;
goto P_0c0661f4;
P_0c0661f4: /* original 6143, guest PC 0x0c0661f4 */
if(!s->budget--) { s->failed_pc=0x0c0661f4u; return 0; }
r[1]=r[4];
goto P_0c0661f6;
P_0c0661f6: /* original 4128, guest PC 0x0c0661f6 */
if(!s->budget--) { s->failed_pc=0x0c0661f6u; return 0; }
r[1]<<=16;
goto P_0c0661f8;
P_0c0661f8: /* original 231b, guest PC 0x0c0661f8 */
if(!s->budget--) { s->failed_pc=0x0c0661f8u; return 0; }
r[3]|=r[1];
goto P_0c0661fa;
P_0c0661fa: /* original 6143, guest PC 0x0c0661fa */
if(!s->budget--) { s->failed_pc=0x0c0661fau; return 0; }
r[1]=r[4];
goto P_0c0661fc;
P_0c0661fc: /* original 4118, guest PC 0x0c0661fc */
if(!s->budget--) { s->failed_pc=0x0c0661fcu; return 0; }
r[1]<<=8;
goto P_0c0661fe;
P_0c0661fe: /* original 231b, guest PC 0x0c0661fe */
if(!s->budget--) { s->failed_pc=0x0c0661feu; return 0; }
r[3]|=r[1];
goto P_0c066200;
P_0c066200: /* original 234b, guest PC 0x0c066200 */
if(!s->budget--) { s->failed_pc=0x0c066200u; return 0; }
r[3]|=r[4];
goto P_0c066202;
P_0c066202: /* original 0236, guest PC 0x0c066202 */
if(!s->budget--) { s->failed_pc=0x0c066202u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c066204;
P_0c066204: /* original 6ca2, guest PC 0x0c066204 */
if(!s->budget--) { s->failed_pc=0x0c066204u; return 0; }
tmp=read(ram,r[10],4);
r[12]=tmp;
goto P_0c066206;
P_0c066206: /* original e01c, guest PC 0x0c066206 */
if(!s->budget--) { s->failed_pc=0x0c066206u; return 0; }
r[0]=0x0000001cu;
goto P_0c066208;
P_0c066208: /* original f3c6, guest PC 0x0c066208 */
if(!s->budget--) { s->failed_pc=0x0c066208u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c06620a;
P_0c06620a: /* original f3f2, guest PC 0x0c06620a */
if(!s->budget--) { s->failed_pc=0x0c06620au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c06620c;
P_0c06620c: /* original f33d, guest PC 0x0c06620c */
if(!s->budget--) { s->failed_pc=0x0c06620cu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c06620e;
P_0c06620e: /* original 0c5a, guest PC 0x0c06620e */
if(!s->budget--) { s->failed_pc=0x0c06620eu; return 0; }
r[12]=r[53];
goto P_0c066210;
P_0c066210: /* original 66c3, guest PC 0x0c066210 */
if(!s->budget--) { s->failed_pc=0x0c066210u; return 0; }
r[6]=r[12];
goto P_0c066212;
P_0c066212: /* original 4628, guest PC 0x0c066212 */
if(!s->budget--) { s->failed_pc=0x0c066212u; return 0; }
r[6]<<=16;
goto P_0c066214;
P_0c066214: /* original 4618, guest PC 0x0c066214 */
if(!s->budget--) { s->failed_pc=0x0c066214u; return 0; }
r[6]<<=8;
goto P_0c066216;
P_0c066216: /* original 63c3, guest PC 0x0c066216 */
if(!s->budget--) { s->failed_pc=0x0c066216u; return 0; }
r[3]=r[12];
goto P_0c066218;
P_0c066218: /* original 4328, guest PC 0x0c066218 */
if(!s->budget--) { s->failed_pc=0x0c066218u; return 0; }
r[3]<<=16;
goto P_0c06621a;
P_0c06621a: /* original 263b, guest PC 0x0c06621a */
if(!s->budget--) { s->failed_pc=0x0c06621au; return 0; }
r[6]|=r[3];
goto P_0c06621c;
P_0c06621c: /* original d31a, guest PC 0x0c06621c */
if(!s->budget--) { s->failed_pc=0x0c06621cu; return 0; }
r[3]=read(ram,0x0c066288u,4);
goto P_0c06621e;
P_0c06621e: /* original 62c3, guest PC 0x0c06621e */
if(!s->budget--) { s->failed_pc=0x0c06621eu; return 0; }
r[2]=r[12];
goto P_0c066220;
P_0c066220: /* original 4218, guest PC 0x0c066220 */
if(!s->budget--) { s->failed_pc=0x0c066220u; return 0; }
r[2]<<=8;
goto P_0c066222;
P_0c066222: /* original 262b, guest PC 0x0c066222 */
if(!s->budget--) { s->failed_pc=0x0c066222u; return 0; }
r[6]|=r[2];
goto P_0c066224;
P_0c066224: /* original 26cb, guest PC 0x0c066224 */
if(!s->budget--) { s->failed_pc=0x0c066224u; return 0; }
r[6]|=r[12];
goto P_0c066226;
P_0c066226: /* original 65b3, guest PC 0x0c066226 */
if(!s->budget--) { s->failed_pc=0x0c066226u; return 0; }
r[5]=r[11];
goto P_0c066228;
P_0c066228: /* original 430b, guest PC 0x0c066228 */
if(!s->budget--) { s->failed_pc=0x0c066228u; return 0; }
target=r[3];
r[16]=code_base|0x0c06622cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06622cu) { target=s->pc; goto dispatch; }
goto P_0c06622c;
P_0c06622a: /* original 64e3, guest PC 0x0c06622a */
if(!s->budget--) { s->failed_pc=0x0c06622au; return 0; }
r[4]=r[14];
goto P_0c06622c;
P_0c06622c: /* original d217, guest PC 0x0c06622c */
if(!s->budget--) { s->failed_pc=0x0c06622cu; return 0; }
r[2]=read(ram,0x0c06628cu,4);
goto P_0c06622e;
P_0c06622e: /* original 6403, guest PC 0x0c06622e */
if(!s->budget--) { s->failed_pc=0x0c06622eu; return 0; }
r[4]=r[0];
goto P_0c066230;
P_0c066230: /* original 4408, guest PC 0x0c066230 */
if(!s->budget--) { s->failed_pc=0x0c066230u; return 0; }
r[4]<<=2;
goto P_0c066232;
P_0c066232: /* original 2242, guest PC 0x0c066232 */
if(!s->budget--) { s->failed_pc=0x0c066232u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c066234;
P_0c066234: /* original d316, guest PC 0x0c066234 */
if(!s->budget--) { s->failed_pc=0x0c066234u; return 0; }
r[3]=read(ram,0x0c066290u,4);
goto P_0c066236;
P_0c066236: /* original 430b, guest PC 0x0c066236 */
if(!s->budget--) { s->failed_pc=0x0c066236u; return 0; }
target=r[3];
r[16]=code_base|0x0c06623au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06623au) { target=s->pc; goto dispatch; }
goto P_0c06623a;
P_0c066238: /* original 64e3, guest PC 0x0c066238 */
if(!s->budget--) { s->failed_pc=0x0c066238u; return 0; }
r[4]=r[14];
goto P_0c06623a;
P_0c06623a: /* original 6403, guest PC 0x0c06623a */
if(!s->budget--) { s->failed_pc=0x0c06623au; return 0; }
r[4]=r[0];
goto P_0c06623c;
P_0c06623c: /* original d215, guest PC 0x0c06623c */
if(!s->budget--) { s->failed_pc=0x0c06623cu; return 0; }
r[2]=read(ram,0x0c066294u,4);
goto P_0c06623e;
P_0c06623e: /* original e500, guest PC 0x0c06623e */
if(!s->budget--) { s->failed_pc=0x0c06623eu; return 0; }
r[5]=0x00000000u;
goto P_0c066240;
P_0c066240: /* original 420b, guest PC 0x0c066240 */
if(!s->budget--) { s->failed_pc=0x0c066240u; return 0; }
target=r[2];
r[16]=code_base|0x0c066244u;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066244u) { target=s->pc; goto dispatch; }
goto P_0c066244;
P_0c066242: /* original 6653, guest PC 0x0c066242 */
if(!s->budget--) { s->failed_pc=0x0c066242u; return 0; }
r[6]=r[5];
goto P_0c066244;
P_0c066244: /* original 62d2, guest PC 0x0c066244 */
if(!s->budget--) { s->failed_pc=0x0c066244u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c066246;
P_0c066246: /* original 5323, guest PC 0x0c066246 */
if(!s->budget--) { s->failed_pc=0x0c066246u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c066248;
P_0c066248: /* original d113, guest PC 0x0c066248 */
if(!s->budget--) { s->failed_pc=0x0c066248u; return 0; }
r[1]=read(ram,0x0c066298u,4);
goto P_0c06624a;
P_0c06624a: /* original 2132, guest PC 0x0c06624a */
if(!s->budget--) { s->failed_pc=0x0c06624au; return 0; }
write(ram,r[1],r[3],4);
goto P_0c06624c;
P_0c06624c: /* original e000, guest PC 0x0c06624c */
if(!s->budget--) { s->failed_pc=0x0c06624cu; return 0; }
r[0]=0x00000000u;
goto P_0c06624e;
P_0c06624e: /* original 7f0c, guest PC 0x0c06624e */
if(!s->budget--) { s->failed_pc=0x0c06624eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c066250;
P_0c066250: /* original 4f26, guest PC 0x0c066250 */
if(!s->budget--) { s->failed_pc=0x0c066250u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066252;
P_0c066252: /* original fff9, guest PC 0x0c066252 */
if(!s->budget--) { s->failed_pc=0x0c066252u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c066254;
P_0c066254: /* original 69f6, guest PC 0x0c066254 */
if(!s->budget--) { s->failed_pc=0x0c066254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066256;
P_0c066256: /* original 6af6, guest PC 0x0c066256 */
if(!s->budget--) { s->failed_pc=0x0c066256u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066258;
P_0c066258: /* original 6bf6, guest PC 0x0c066258 */
if(!s->budget--) { s->failed_pc=0x0c066258u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06625a;
P_0c06625a: /* original 6cf6, guest PC 0x0c06625a */
if(!s->budget--) { s->failed_pc=0x0c06625au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06625c;
P_0c06625c: /* original 6df6, guest PC 0x0c06625c */
if(!s->budget--) { s->failed_pc=0x0c06625cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06625e;
P_0c06625e: /* original 000b, guest PC 0x0c06625e */
if(!s->budget--) { s->failed_pc=0x0c06625eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066260: /* original 6ef6, guest PC 0x0c066260 */
if(!s->budget--) { s->failed_pc=0x0c066260u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c066262u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066262u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
