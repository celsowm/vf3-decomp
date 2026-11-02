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
int vf3_away_batch50_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08466au: goto P_0c08466a;
case 0x0c08466cu: goto P_0c08466c;
case 0x0c08466eu: goto P_0c08466e;
case 0x0c084670u: goto P_0c084670;
case 0x0c084672u: goto P_0c084672;
case 0x0c084674u: goto P_0c084674;
case 0x0c084676u: goto P_0c084676;
case 0x0c084678u: goto P_0c084678;
case 0x0c08467au: goto P_0c08467a;
case 0x0c08467cu: goto P_0c08467c;
case 0x0c08467eu: goto P_0c08467e;
case 0x0c084680u: goto P_0c084680;
case 0x0c084682u: goto P_0c084682;
case 0x0c084684u: goto P_0c084684;
case 0x0c084686u: goto P_0c084686;
case 0x0c084688u: goto P_0c084688;
case 0x0c08468au: goto P_0c08468a;
case 0x0c08468cu: goto P_0c08468c;
case 0x0c08468eu: goto P_0c08468e;
case 0x0c084690u: goto P_0c084690;
case 0x0c084692u: goto P_0c084692;
case 0x0c084694u: goto P_0c084694;
case 0x0c084696u: goto P_0c084696;
case 0x0c084698u: goto P_0c084698;
case 0x0c08469au: goto P_0c08469a;
case 0x0c08469cu: goto P_0c08469c;
case 0x0c08469eu: goto P_0c08469e;
case 0x0c0846a0u: goto P_0c0846a0;
case 0x0c0846a2u: goto P_0c0846a2;
case 0x0c0846a4u: goto P_0c0846a4;
case 0x0c0846a6u: goto P_0c0846a6;
case 0x0c0846e0u: goto P_0c0846e0;
case 0x0c0846e2u: goto P_0c0846e2;
case 0x0c0846e4u: goto P_0c0846e4;
case 0x0c0846e6u: goto P_0c0846e6;
case 0x0c0846e8u: goto P_0c0846e8;
case 0x0c0846eau: goto P_0c0846ea;
case 0x0c0846ecu: goto P_0c0846ec;
case 0x0c0846eeu: goto P_0c0846ee;
case 0x0c0846f0u: goto P_0c0846f0;
case 0x0c0846f2u: goto P_0c0846f2;
case 0x0c0846f4u: goto P_0c0846f4;
case 0x0c0846f6u: goto P_0c0846f6;
case 0x0c0846f8u: goto P_0c0846f8;
case 0x0c0846fau: goto P_0c0846fa;
case 0x0c0846fcu: goto P_0c0846fc;
case 0x0c0846feu: goto P_0c0846fe;
case 0x0c084700u: goto P_0c084700;
case 0x0c084702u: goto P_0c084702;
case 0x0c084704u: goto P_0c084704;
case 0x0c084706u: goto P_0c084706;
case 0x0c084708u: goto P_0c084708;
case 0x0c08470au: goto P_0c08470a;
case 0x0c08470cu: goto P_0c08470c;
case 0x0c08470eu: goto P_0c08470e;
case 0x0c084710u: goto P_0c084710;
case 0x0c084712u: goto P_0c084712;
case 0x0c084714u: goto P_0c084714;
case 0x0c084716u: goto P_0c084716;
case 0x0c084718u: goto P_0c084718;
case 0x0c08471au: goto P_0c08471a;
case 0x0c08471cu: goto P_0c08471c;
case 0x0c08471eu: goto P_0c08471e;
case 0x0c084720u: goto P_0c084720;
case 0x0c084730u: goto P_0c084730;
case 0x0c084732u: goto P_0c084732;
case 0x0c084734u: goto P_0c084734;
case 0x0c084736u: goto P_0c084736;
case 0x0c084738u: goto P_0c084738;
case 0x0c08473au: goto P_0c08473a;
case 0x0c08473cu: goto P_0c08473c;
case 0x0c08473eu: goto P_0c08473e;
case 0x0c084740u: goto P_0c084740;
case 0x0c084742u: goto P_0c084742;
case 0x0c084744u: goto P_0c084744;
case 0x0c084746u: goto P_0c084746;
case 0x0c084748u: goto P_0c084748;
case 0x0c08474au: goto P_0c08474a;
case 0x0c08474cu: goto P_0c08474c;
case 0x0c08474eu: goto P_0c08474e;
case 0x0c084750u: goto P_0c084750;
case 0x0c084752u: goto P_0c084752;
case 0x0c084754u: goto P_0c084754;
case 0x0c084756u: goto P_0c084756;
case 0x0c084758u: goto P_0c084758;
case 0x0c08475au: goto P_0c08475a;
case 0x0c08475cu: goto P_0c08475c;
case 0x0c08475eu: goto P_0c08475e;
case 0x0c084760u: goto P_0c084760;
case 0x0c084762u: goto P_0c084762;
case 0x0c084764u: goto P_0c084764;
case 0x0c084766u: goto P_0c084766;
case 0x0c084768u: goto P_0c084768;
case 0x0c08476au: goto P_0c08476a;
case 0x0c08476cu: goto P_0c08476c;
case 0x0c08476eu: goto P_0c08476e;
case 0x0c084770u: goto P_0c084770;
case 0x0c084772u: goto P_0c084772;
case 0x0c084774u: goto P_0c084774;
case 0x0c084776u: goto P_0c084776;
case 0x0c084778u: goto P_0c084778;
case 0x0c08477au: goto P_0c08477a;
case 0x0c08477cu: goto P_0c08477c;
case 0x0c08477eu: goto P_0c08477e;
case 0x0c084780u: goto P_0c084780;
case 0x0c084782u: goto P_0c084782;
case 0x0c084784u: goto P_0c084784;
case 0x0c084786u: goto P_0c084786;
case 0x0c084788u: goto P_0c084788;
case 0x0c08478au: goto P_0c08478a;
case 0x0c08478cu: goto P_0c08478c;
case 0x0c08478eu: goto P_0c08478e;
case 0x0c084790u: goto P_0c084790;
case 0x0c084792u: goto P_0c084792;
case 0x0c084794u: goto P_0c084794;
case 0x0c084796u: goto P_0c084796;
case 0x0c084798u: goto P_0c084798;
case 0x0c08479au: goto P_0c08479a;
case 0x0c08479cu: goto P_0c08479c;
case 0x0c08479eu: goto P_0c08479e;
case 0x0c0847a0u: goto P_0c0847a0;
case 0x0c0847a2u: goto P_0c0847a2;
case 0x0c0847a4u: goto P_0c0847a4;
case 0x0c0847a6u: goto P_0c0847a6;
case 0x0c0847a8u: goto P_0c0847a8;
case 0x0c0847aau: goto P_0c0847aa;
case 0x0c0847acu: goto P_0c0847ac;
case 0x0c0847aeu: goto P_0c0847ae;
case 0x0c0847b0u: goto P_0c0847b0;
case 0x0c0847b2u: goto P_0c0847b2;
case 0x0c0847b4u: goto P_0c0847b4;
case 0x0c0847b6u: goto P_0c0847b6;
case 0x0c0847b8u: goto P_0c0847b8;
case 0x0c0847bau: goto P_0c0847ba;
case 0x0c0847bcu: goto P_0c0847bc;
case 0x0c0847beu: goto P_0c0847be;
case 0x0c0847c0u: goto P_0c0847c0;
case 0x0c0847c2u: goto P_0c0847c2;
case 0x0c0847c4u: goto P_0c0847c4;
case 0x0c0847c6u: goto P_0c0847c6;
case 0x0c0847c8u: goto P_0c0847c8;
case 0x0c0847cau: goto P_0c0847ca;
case 0x0c0847ccu: goto P_0c0847cc;
case 0x0c0847ceu: goto P_0c0847ce;
case 0x0c0847d0u: goto P_0c0847d0;
case 0x0c0847d2u: goto P_0c0847d2;
case 0x0c0847d4u: goto P_0c0847d4;
case 0x0c0847d6u: goto P_0c0847d6;
case 0x0c0847d8u: goto P_0c0847d8;
case 0x0c0847dau: goto P_0c0847da;
case 0x0c0847dcu: goto P_0c0847dc;
case 0x0c0847deu: goto P_0c0847de;
case 0x0c0847e0u: goto P_0c0847e0;
case 0x0c0847e2u: goto P_0c0847e2;
case 0x0c0847e4u: goto P_0c0847e4;
case 0x0c0847e6u: goto P_0c0847e6;
case 0x0c0847e8u: goto P_0c0847e8;
case 0x0c0847eau: goto P_0c0847ea;
case 0x0c0847ecu: goto P_0c0847ec;
case 0x0c0847eeu: goto P_0c0847ee;
case 0x0c0847f0u: goto P_0c0847f0;
case 0x0c0847f2u: goto P_0c0847f2;
case 0x0c0847f4u: goto P_0c0847f4;
case 0x0c0847f6u: goto P_0c0847f6;
case 0x0c0847f8u: goto P_0c0847f8;
case 0x0c0847fau: goto P_0c0847fa;
case 0x0c0847fcu: goto P_0c0847fc;
case 0x0c0847feu: goto P_0c0847fe;
case 0x0c084800u: goto P_0c084800;
case 0x0c084802u: goto P_0c084802;
case 0x0c084804u: goto P_0c084804;
case 0x0c084806u: goto P_0c084806;
case 0x0c084808u: goto P_0c084808;
case 0x0c08480au: goto P_0c08480a;
case 0x0c08480cu: goto P_0c08480c;
case 0x0c08480eu: goto P_0c08480e;
case 0x0c084810u: goto P_0c084810;
case 0x0c084812u: goto P_0c084812;
case 0x0c084814u: goto P_0c084814;
case 0x0c084816u: goto P_0c084816;
case 0x0c084818u: goto P_0c084818;
case 0x0c08481au: goto P_0c08481a;
case 0x0c08481cu: goto P_0c08481c;
case 0x0c08481eu: goto P_0c08481e;
case 0x0c084820u: goto P_0c084820;
case 0x0c084822u: goto P_0c084822;
case 0x0c084824u: goto P_0c084824;
case 0x0c084826u: goto P_0c084826;
case 0x0c084828u: goto P_0c084828;
case 0x0c08482au: goto P_0c08482a;
case 0x0c08482cu: goto P_0c08482c;
case 0x0c08482eu: goto P_0c08482e;
case 0x0c084830u: goto P_0c084830;
case 0x0c084832u: goto P_0c084832;
case 0x0c084834u: goto P_0c084834;
case 0x0c084836u: goto P_0c084836;
case 0x0c084838u: goto P_0c084838;
case 0x0c08483au: goto P_0c08483a;
case 0x0c08483cu: goto P_0c08483c;
case 0x0c08483eu: goto P_0c08483e;
case 0x0c084840u: goto P_0c084840;
case 0x0c084842u: goto P_0c084842;
case 0x0c084844u: goto P_0c084844;
case 0x0c084846u: goto P_0c084846;
case 0x0c084848u: goto P_0c084848;
case 0x0c08484au: goto P_0c08484a;
case 0x0c08484cu: goto P_0c08484c;
case 0x0c08484eu: goto P_0c08484e;
case 0x0c084850u: goto P_0c084850;
case 0x0c084852u: goto P_0c084852;
case 0x0c084854u: goto P_0c084854;
case 0x0c084856u: goto P_0c084856;
case 0x0c084858u: goto P_0c084858;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08466a: /* original 2fe6, guest PC 0x0c08466a */
if(!s->budget--) { s->failed_pc=0x0c08466au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08466c;
P_0c08466c: /* original 2fd6, guest PC 0x0c08466c */
if(!s->budget--) { s->failed_pc=0x0c08466cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08466e;
P_0c08466e: /* original 2fc6, guest PC 0x0c08466e */
if(!s->budget--) { s->failed_pc=0x0c08466eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084670;
P_0c084670: /* original 2fb6, guest PC 0x0c084670 */
if(!s->budget--) { s->failed_pc=0x0c084670u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084672;
P_0c084672: /* original 2fa6, guest PC 0x0c084672 */
if(!s->budget--) { s->failed_pc=0x0c084672u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084674;
P_0c084674: /* original 2f96, guest PC 0x0c084674 */
if(!s->budget--) { s->failed_pc=0x0c084674u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084676;
P_0c084676: /* original 2f86, guest PC 0x0c084676 */
if(!s->budget--) { s->failed_pc=0x0c084676u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c084678;
P_0c084678: /* original fffb, guest PC 0x0c084678 */
if(!s->budget--) { s->failed_pc=0x0c084678u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08467a;
P_0c08467a: /* original ffeb, guest PC 0x0c08467a */
if(!s->budget--) { s->failed_pc=0x0c08467au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08467c;
P_0c08467c: /* original ffdb, guest PC 0x0c08467c */
if(!s->budget--) { s->failed_pc=0x0c08467cu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08467e;
P_0c08467e: /* original ffcb, guest PC 0x0c08467e */
if(!s->budget--) { s->failed_pc=0x0c08467eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c084680;
P_0c084680: /* original d115, guest PC 0x0c084680 */
if(!s->budget--) { s->failed_pc=0x0c084680u; return 0; }
r[1]=read(ram,0x0c0846d8u,4);
goto P_0c084682;
P_0c084682: /* original 4f22, guest PC 0x0c084682 */
if(!s->budget--) { s->failed_pc=0x0c084682u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c084684;
P_0c084684: /* original d313, guest PC 0x0c084684 */
if(!s->budget--) { s->failed_pc=0x0c084684u; return 0; }
r[3]=read(ram,0x0c0846d4u,4);
goto P_0c084686;
P_0c084686: /* original 6212, guest PC 0x0c084686 */
if(!s->budget--) { s->failed_pc=0x0c084686u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c084688;
P_0c084688: /* original d911, guest PC 0x0c084688 */
if(!s->budget--) { s->failed_pc=0x0c084688u; return 0; }
r[9]=read(ram,0x0c0846d0u,4);
goto P_0c08468a;
P_0c08468a: /* original 7fdc, guest PC 0x0c08468a */
if(!s->budget--) { s->failed_pc=0x0c08468au; return 0; }
r[15]+=0xffffffdcu;
goto P_0c08468c;
P_0c08468c: /* original 2238, guest PC 0x0c08468c */
if(!s->budget--) { s->failed_pc=0x0c08468cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08468e;
P_0c08468e: /* original 8d02, guest PC 0x0c08468e */
if(!s->budget--) { s->failed_pc=0x0c08468eu; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(cond) { goto P_0c084696; }
goto P_0c084692;
P_0c084690: /* original 6b43, guest PC 0x0c084690 */
if(!s->budget--) { s->failed_pc=0x0c084690u; return 0; }
r[11]=r[4];
goto P_0c084692;
P_0c084692: /* original a0d4, guest PC 0x0c084692 */
if(!s->budget--) { s->failed_pc=0x0c084692u; return 0; }
goto P_0c08483e;
P_0c084694: /* original 0009, guest PC 0x0c084694 */
if(!s->budget--) { s->failed_pc=0x0c084694u; return 0; }
goto P_0c084696;
P_0c084696: /* original d811, guest PC 0x0c084696 */
if(!s->budget--) { s->failed_pc=0x0c084696u; return 0; }
r[8]=read(ram,0x0c0846dcu,4);
goto P_0c084698;
P_0c084698: /* original 64b3, guest PC 0x0c084698 */
if(!s->budget--) { s->failed_pc=0x0c084698u; return 0; }
r[4]=r[11];
goto P_0c08469a;
P_0c08469a: /* original 5d94, guest PC 0x0c08469a */
if(!s->budget--) { s->failed_pc=0x0c08469au; return 0; }
r[13]=read(ram,r[9]+16,4);
goto P_0c08469c;
P_0c08469c: /* original 6eb3, guest PC 0x0c08469c */
if(!s->budget--) { s->failed_pc=0x0c08469cu; return 0; }
r[14]=r[11];
goto P_0c08469e;
P_0c08469e: /* original 7418, guest PC 0x0c08469e */
if(!s->budget--) { s->failed_pc=0x0c08469eu; return 0; }
r[4]+=0x00000018u;
goto P_0c0846a0;
P_0c0846a0: /* original 7e10, guest PC 0x0c0846a0 */
if(!s->budget--) { s->failed_pc=0x0c0846a0u; return 0; }
r[14]+=0x00000010u;
goto P_0c0846a2;
P_0c0846a2: /* original ea02, guest PC 0x0c0846a2 */
if(!s->budget--) { s->failed_pc=0x0c0846a2u; return 0; }
r[10]=0x00000002u;
goto P_0c0846a4;
P_0c0846a4: /* original a0c6, guest PC 0x0c0846a4 */
if(!s->budget--) { s->failed_pc=0x0c0846a4u; return 0; }
r[12]=r[4];
goto P_0c084834;
P_0c0846a6: /* original 6c43, guest PC 0x0c0846a6 */
if(!s->budget--) { s->failed_pc=0x0c0846a6u; return 0; }
r[12]=r[4];
if(!vf3_matrix_family(0x0c0846a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0846a8u; return 0; } return 1;
P_0c0846e0: /* original 901f, guest PC 0x0c0846e0 */
if(!s->budget--) { s->failed_pc=0x0c0846e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084722u,2);
goto P_0c0846e2;
P_0c0846e2: /* original e504, guest PC 0x0c0846e2 */
if(!s->budget--) { s->failed_pc=0x0c0846e2u; return 0; }
r[5]=0x00000004u;
goto P_0c0846e4;
P_0c0846e4: /* original 04de, guest PC 0x0c0846e4 */
if(!s->budget--) { s->failed_pc=0x0c0846e4u; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0846e6;
P_0c0846e6: /* original 2458, guest PC 0x0c0846e6 */
if(!s->budget--) { s->failed_pc=0x0c0846e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[5])==0)!=0);
goto P_0c0846e8;
P_0c0846e8: /* original 8901, guest PC 0x0c0846e8 */
if(!s->budget--) { s->failed_pc=0x0c0846e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0846ee; }
goto P_0c0846ea;
P_0c0846ea: /* original a09c, guest PC 0x0c0846ea */
if(!s->budget--) { s->failed_pc=0x0c0846eau; return 0; }
goto P_0c084826;
P_0c0846ec: /* original 0009, guest PC 0x0c0846ec */
if(!s->budget--) { s->failed_pc=0x0c0846ecu; return 0; }
goto P_0c0846ee;
P_0c0846ee: /* original 62e2, guest PC 0x0c0846ee */
if(!s->budget--) { s->failed_pc=0x0c0846eeu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0846f0;
P_0c0846f0: /* original 2228, guest PC 0x0c0846f0 */
if(!s->budget--) { s->failed_pc=0x0c0846f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0846f2;
P_0c0846f2: /* original 8b04, guest PC 0x0c0846f2 */
if(!s->budget--) { s->failed_pc=0x0c0846f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0846fe; }
goto P_0c0846f4;
P_0c0846f4: /* original 64c3, guest PC 0x0c0846f4 */
if(!s->budget--) { s->failed_pc=0x0c0846f4u; return 0; }
r[4]=r[12];
goto P_0c0846f6;
P_0c0846f6: /* original be9d, guest PC 0x0c0846f6 */
if(!s->budget--) { s->failed_pc=0x0c0846f6u; return 0; }
target=code_base|0x0c084434u; r[16]=code_base|0x0c0846fau;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0846fau) { target=s->pc; goto dispatch; }
goto P_0c0846fa;
P_0c0846f8: /* original 65d3, guest PC 0x0c0846f8 */
if(!s->budget--) { s->failed_pc=0x0c0846f8u; return 0; }
r[5]=r[13];
goto P_0c0846fa;
P_0c0846fa: /* original e401, guest PC 0x0c0846fa */
if(!s->budget--) { s->failed_pc=0x0c0846fau; return 0; }
r[4]=0x00000001u;
goto P_0c0846fc;
P_0c0846fc: /* original 2e42, guest PC 0x0c0846fc */
if(!s->budget--) { s->failed_pc=0x0c0846fcu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0846fe;
P_0c0846fe: /* original 9011, guest PC 0x0c0846fe */
if(!s->budget--) { s->failed_pc=0x0c0846feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c084724u,2);
goto P_0c084700;
P_0c084700: /* original e50f, guest PC 0x0c084700 */
if(!s->budget--) { s->failed_pc=0x0c084700u; return 0; }
r[5]=0x0000000fu;
goto P_0c084702;
P_0c084702: /* original d40a, guest PC 0x0c084702 */
if(!s->budget--) { s->failed_pc=0x0c084702u; return 0; }
r[4]=read(ram,0x0c08472cu,4);
goto P_0c084704;
P_0c084704: /* original 6ec3, guest PC 0x0c084704 */
if(!s->budget--) { s->failed_pc=0x0c084704u; return 0; }
r[14]=r[12];
goto P_0c084706;
P_0c084706: /* original fed6, guest PC 0x0c084706 */
if(!s->budget--) { s->failed_pc=0x0c084706u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c084708;
P_0c084708: /* original c707, guest PC 0x0c084708 */
if(!s->budget--) { s->failed_pc=0x0c084708u; return 0; }
r[0]=code_base|0x00084728u;
goto P_0c08470a;
P_0c08470a: /* original f408, guest PC 0x0c08470a */
if(!s->budget--) { s->failed_pc=0x0c08470au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08470c;
P_0c08470c: /* original e01c, guest PC 0x0c08470c */
if(!s->budget--) { s->failed_pc=0x0c08470cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08470e;
P_0c08470e: /* original 044c, guest PC 0x0c08470e */
if(!s->budget--) { s->failed_pc=0x0c08470eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c084710;
P_0c084710: /* original ec0e, guest PC 0x0c084710 */
if(!s->budget--) { s->failed_pc=0x0c084710u; return 0; }
r[12]=0x0000000eu;
goto P_0c084712;
P_0c084712: /* original fe40, guest PC 0x0c084712 */
if(!s->budget--) { s->failed_pc=0x0c084712u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'+');
goto P_0c084714;
P_0c084714: /* original 644c, guest PC 0x0c084714 */
if(!s->budget--) { s->failed_pc=0x0c084714u; return 0; }
r[4]=r[4]&255u;
goto P_0c084716;
P_0c084716: /* original 2459, guest PC 0x0c084716 */
if(!s->budget--) { s->failed_pc=0x0c084716u; return 0; }
r[4]&=r[5];
goto P_0c084718;
P_0c084718: /* original 6583, guest PC 0x0c084718 */
if(!s->budget--) { s->failed_pc=0x0c084718u; return 0; }
r[5]=r[8];
goto P_0c08471a;
P_0c08471a: /* original 4408, guest PC 0x0c08471a */
if(!s->budget--) { s->failed_pc=0x0c08471au; return 0; }
r[4]<<=2;
goto P_0c08471c;
P_0c08471c: /* original 6043, guest PC 0x0c08471c */
if(!s->budget--) { s->failed_pc=0x0c08471cu; return 0; }
r[0]=r[4];
goto P_0c08471e;
P_0c08471e: /* original a07f, guest PC 0x0c08471e */
if(!s->budget--) { s->failed_pc=0x0c08471eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
goto P_0c084820;
P_0c084720: /* original ff56, guest PC 0x0c084720 */
if(!s->budget--) { s->failed_pc=0x0c084720u; return 0; }
vf3_matrix_load(s,ram,15,r[5]+r[0]);
if(!vf3_matrix_family(0x0c084722u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c084722u; return 0; } return 1;
P_0c084730: /* original f3e8, guest PC 0x0c084730 */
if(!s->budget--) { s->failed_pc=0x0c084730u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c084732;
P_0c084732: /* original e010, guest PC 0x0c084732 */
if(!s->budget--) { s->failed_pc=0x0c084732u; return 0; }
r[0]=0x00000010u;
goto P_0c084734;
P_0c084734: /* original ff37, guest PC 0x0c084734 */
if(!s->budget--) { s->failed_pc=0x0c084734u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084736;
P_0c084736: /* original e004, guest PC 0x0c084736 */
if(!s->budget--) { s->failed_pc=0x0c084736u; return 0; }
r[0]=0x00000004u;
goto P_0c084738;
P_0c084738: /* original f3e6, guest PC 0x0c084738 */
if(!s->budget--) { s->failed_pc=0x0c084738u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08473a;
P_0c08473a: /* original e008, guest PC 0x0c08473a */
if(!s->budget--) { s->failed_pc=0x0c08473au; return 0; }
r[0]=0x00000008u;
goto P_0c08473c;
P_0c08473c: /* original ff3a, guest PC 0x0c08473c */
if(!s->budget--) { s->failed_pc=0x0c08473cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c08473e;
P_0c08473e: /* original f3e6, guest PC 0x0c08473e */
if(!s->budget--) { s->failed_pc=0x0c08473eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084740;
P_0c084740: /* original e00c, guest PC 0x0c084740 */
if(!s->budget--) { s->failed_pc=0x0c084740u; return 0; }
r[0]=0x0000000cu;
goto P_0c084742;
P_0c084742: /* original ff37, guest PC 0x0c084742 */
if(!s->budget--) { s->failed_pc=0x0c084742u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084744;
P_0c084744: /* original e020, guest PC 0x0c084744 */
if(!s->budget--) { s->failed_pc=0x0c084744u; return 0; }
r[0]=0x00000020u;
goto P_0c084746;
P_0c084746: /* original 00ed, guest PC 0x0c084746 */
if(!s->budget--) { s->failed_pc=0x0c084746u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084748;
P_0c084748: /* original 81f4, guest PC 0x0c084748 */
if(!s->budget--) { s->failed_pc=0x0c084748u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c08474a;
P_0c08474a: /* original e022, guest PC 0x0c08474a */
if(!s->budget--) { s->failed_pc=0x0c08474au; return 0; }
r[0]=0x00000022u;
goto P_0c08474c;
P_0c08474c: /* original 00ed, guest PC 0x0c08474c */
if(!s->budget--) { s->failed_pc=0x0c08474cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08474e;
P_0c08474e: /* original 81f2, guest PC 0x0c08474e */
if(!s->budget--) { s->failed_pc=0x0c08474eu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c084750;
P_0c084750: /* original e024, guest PC 0x0c084750 */
if(!s->budget--) { s->failed_pc=0x0c084750u; return 0; }
r[0]=0x00000024u;
goto P_0c084752;
P_0c084752: /* original 05ed, guest PC 0x0c084752 */
if(!s->budget--) { s->failed_pc=0x0c084752u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084754;
P_0c084754: /* original e026, guest PC 0x0c084754 */
if(!s->budget--) { s->failed_pc=0x0c084754u; return 0; }
r[0]=0x00000026u;
goto P_0c084756;
P_0c084756: /* original 04ed, guest PC 0x0c084756 */
if(!s->budget--) { s->failed_pc=0x0c084756u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c084758;
P_0c084758: /* original e018, guest PC 0x0c084758 */
if(!s->budget--) { s->failed_pc=0x0c084758u; return 0; }
r[0]=0x00000018u;
goto P_0c08475a;
P_0c08475a: /* original f5e6, guest PC 0x0c08475a */
if(!s->budget--) { s->failed_pc=0x0c08475au; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08475c;
P_0c08475c: /* original e01c, guest PC 0x0c08475c */
if(!s->budget--) { s->failed_pc=0x0c08475cu; return 0; }
r[0]=0x0000001cu;
goto P_0c08475e;
P_0c08475e: /* original f4e6, guest PC 0x0c08475e */
if(!s->budget--) { s->failed_pc=0x0c08475eu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c084760;
P_0c084760: /* original e00c, guest PC 0x0c084760 */
if(!s->budget--) { s->failed_pc=0x0c084760u; return 0; }
r[0]=0x0000000cu;
goto P_0c084762;
P_0c084762: /* original fde6, guest PC 0x0c084762 */
if(!s->budget--) { s->failed_pc=0x0c084762u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c084764;
P_0c084764: /* original e010, guest PC 0x0c084764 */
if(!s->budget--) { s->failed_pc=0x0c084764u; return 0; }
r[0]=0x00000010u;
goto P_0c084766;
P_0c084766: /* original f3e6, guest PC 0x0c084766 */
if(!s->budget--) { s->failed_pc=0x0c084766u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c084768;
P_0c084768: /* original e014, guest PC 0x0c084768 */
if(!s->budget--) { s->failed_pc=0x0c084768u; return 0; }
r[0]=0x00000014u;
goto P_0c08476a;
P_0c08476a: /* original ff37, guest PC 0x0c08476a */
if(!s->budget--) { s->failed_pc=0x0c08476au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08476c;
P_0c08476c: /* original e014, guest PC 0x0c08476c */
if(!s->budget--) { s->failed_pc=0x0c08476cu; return 0; }
r[0]=0x00000014u;
goto P_0c08476e;
P_0c08476e: /* original fce6, guest PC 0x0c08476e */
if(!s->budget--) { s->failed_pc=0x0c08476eu; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c084770;
P_0c084770: /* original 85f4, guest PC 0x0c084770 */
if(!s->budget--) { s->failed_pc=0x0c084770u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c084772;
P_0c084772: /* original 305c, guest PC 0x0c084772 */
if(!s->budget--) { s->failed_pc=0x0c084772u; return 0; }
r[0]+=r[5];
goto P_0c084774;
P_0c084774: /* original 81f4, guest PC 0x0c084774 */
if(!s->budget--) { s->failed_pc=0x0c084774u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c084776;
P_0c084776: /* original 85f2, guest PC 0x0c084776 */
if(!s->budget--) { s->failed_pc=0x0c084776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c084778;
P_0c084778: /* original 304c, guest PC 0x0c084778 */
if(!s->budget--) { s->failed_pc=0x0c084778u; return 0; }
r[0]+=r[4];
goto P_0c08477a;
P_0c08477a: /* original 81f2, guest PC 0x0c08477a */
if(!s->budget--) { s->failed_pc=0x0c08477au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c08477c;
P_0c08477c: /* original e010, guest PC 0x0c08477c */
if(!s->budget--) { s->failed_pc=0x0c08477cu; return 0; }
r[0]=0x00000010u;
goto P_0c08477e;
P_0c08477e: /* original f3f6, guest PC 0x0c08477e */
if(!s->budget--) { s->failed_pc=0x0c08477eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084780;
P_0c084780: /* original e010, guest PC 0x0c084780 */
if(!s->budget--) { s->failed_pc=0x0c084780u; return 0; }
r[0]=0x00000010u;
goto P_0c084782;
P_0c084782: /* original f350, guest PC 0x0c084782 */
if(!s->budget--) { s->failed_pc=0x0c084782u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c084784;
P_0c084784: /* original ff37, guest PC 0x0c084784 */
if(!s->budget--) { s->failed_pc=0x0c084784u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c084786;
P_0c084786: /* original e00c, guest PC 0x0c084786 */
if(!s->budget--) { s->failed_pc=0x0c084786u; return 0; }
r[0]=0x0000000cu;
goto P_0c084788;
P_0c084788: /* original f2f6, guest PC 0x0c084788 */
if(!s->budget--) { s->failed_pc=0x0c084788u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08478a;
P_0c08478a: /* original e00c, guest PC 0x0c08478a */
if(!s->budget--) { s->failed_pc=0x0c08478au; return 0; }
r[0]=0x0000000cu;
goto P_0c08478c;
P_0c08478c: /* original f240, guest PC 0x0c08478c */
if(!s->budget--) { s->failed_pc=0x0c08478cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c08478e;
P_0c08478e: /* original ff27, guest PC 0x0c08478e */
if(!s->budget--) { s->failed_pc=0x0c08478eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c084790;
P_0c084790: /* original d332, guest PC 0x0c084790 */
if(!s->budget--) { s->failed_pc=0x0c084790u; return 0; }
r[3]=read(ram,0x0c08485cu,4);
goto P_0c084792;
P_0c084792: /* original 85f4, guest PC 0x0c084792 */
if(!s->budget--) { s->failed_pc=0x0c084792u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c084794;
P_0c084794: /* original 430b, guest PC 0x0c084794 */
if(!s->budget--) { s->failed_pc=0x0c084794u; return 0; }
target=r[3];
r[16]=code_base|0x0c084798u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c084798u) { target=s->pc; goto dispatch; }
goto P_0c084798;
P_0c084796: /* original 6403, guest PC 0x0c084796 */
if(!s->budget--) { s->failed_pc=0x0c084796u; return 0; }
r[4]=r[0];
goto P_0c084798;
P_0c084798: /* original fd02, guest PC 0x0c084798 */
if(!s->budget--) { s->failed_pc=0x0c084798u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[0],r[18],'*');
goto P_0c08479a;
P_0c08479a: /* original d331, guest PC 0x0c08479a */
if(!s->budget--) { s->failed_pc=0x0c08479au; return 0; }
r[3]=read(ram,0x0c084860u,4);
goto P_0c08479c;
P_0c08479c: /* original 85f2, guest PC 0x0c08479c */
if(!s->budget--) { s->failed_pc=0x0c08479cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08479e;
P_0c08479e: /* original 430b, guest PC 0x0c08479e */
if(!s->budget--) { s->failed_pc=0x0c08479eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0847a2u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0847a2u) { target=s->pc; goto dispatch; }
goto P_0c0847a2;
P_0c0847a0: /* original 6403, guest PC 0x0c0847a0 */
if(!s->budget--) { s->failed_pc=0x0c0847a0u; return 0; }
r[4]=r[0];
goto P_0c0847a2;
P_0c0847a2: /* original e014, guest PC 0x0c0847a2 */
if(!s->budget--) { s->failed_pc=0x0c0847a2u; return 0; }
r[0]=0x00000014u;
goto P_0c0847a4;
P_0c0847a4: /* original f4f6, guest PC 0x0c0847a4 */
if(!s->budget--) { s->failed_pc=0x0c0847a4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0847a6;
P_0c0847a6: /* original e010, guest PC 0x0c0847a6 */
if(!s->budget--) { s->failed_pc=0x0c0847a6u; return 0; }
r[0]=0x00000010u;
goto P_0c0847a8;
P_0c0847a8: /* original f3f6, guest PC 0x0c0847a8 */
if(!s->budget--) { s->failed_pc=0x0c0847a8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0847aa;
P_0c0847aa: /* original e010, guest PC 0x0c0847aa */
if(!s->budget--) { s->failed_pc=0x0c0847aau; return 0; }
r[0]=0x00000010u;
goto P_0c0847ac;
P_0c0847ac: /* original f402, guest PC 0x0c0847ac */
if(!s->budget--) { s->failed_pc=0x0c0847acu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[0],r[18],'*');
goto P_0c0847ae;
P_0c0847ae: /* original f3d0, guest PC 0x0c0847ae */
if(!s->budget--) { s->failed_pc=0x0c0847aeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'+');
goto P_0c0847b0;
P_0c0847b0: /* original ff37, guest PC 0x0c0847b0 */
if(!s->budget--) { s->failed_pc=0x0c0847b0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0847b2;
P_0c0847b2: /* original e00c, guest PC 0x0c0847b2 */
if(!s->budget--) { s->failed_pc=0x0c0847b2u; return 0; }
r[0]=0x0000000cu;
goto P_0c0847b4;
P_0c0847b4: /* original f2f8, guest PC 0x0c0847b4 */
if(!s->budget--) { s->failed_pc=0x0c0847b4u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0847b6;
P_0c0847b6: /* original f2c0, guest PC 0x0c0847b6 */
if(!s->budget--) { s->failed_pc=0x0c0847b6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[12],r[18],'+');
goto P_0c0847b8;
P_0c0847b8: /* original fe25, guest PC 0x0c0847b8 */
if(!s->budget--) { s->failed_pc=0x0c0847b8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[2]))!=0);
goto P_0c0847ba;
P_0c0847ba: /* original ff2a, guest PC 0x0c0847ba */
if(!s->budget--) { s->failed_pc=0x0c0847bau; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0847bc;
P_0c0847bc: /* original f1f6, guest PC 0x0c0847bc */
if(!s->budget--) { s->failed_pc=0x0c0847bcu; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0847be;
P_0c0847be: /* original e00c, guest PC 0x0c0847be */
if(!s->budget--) { s->failed_pc=0x0c0847beu; return 0; }
r[0]=0x0000000cu;
goto P_0c0847c0;
P_0c0847c0: /* original f140, guest PC 0x0c0847c0 */
if(!s->budget--) { s->failed_pc=0x0c0847c0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c0847c2;
P_0c0847c2: /* original 8f01, guest PC 0x0c0847c2 */
if(!s->budget--) { s->failed_pc=0x0c0847c2u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,1,r[15]+r[0]);
if(!cond) { goto P_0c0847c8; }
goto P_0c0847c6;
P_0c0847c4: /* original ff17, guest PC 0x0c0847c4 */
if(!s->budget--) { s->failed_pc=0x0c0847c4u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0847c6;
P_0c0847c6: /* original ffea, guest PC 0x0c0847c6 */
if(!s->budget--) { s->failed_pc=0x0c0847c6u; return 0; }
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0847c8;
P_0c0847c8: /* original f3f8, guest PC 0x0c0847c8 */
if(!s->budget--) { s->failed_pc=0x0c0847c8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0847ca;
P_0c0847ca: /* original ff35, guest PC 0x0c0847ca */
if(!s->budget--) { s->failed_pc=0x0c0847cau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0847cc;
P_0c0847cc: /* original 8900, guest PC 0x0c0847cc */
if(!s->budget--) { s->failed_pc=0x0c0847ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0847d0; }
goto P_0c0847ce;
P_0c0847ce: /* original fffa, guest PC 0x0c0847ce */
if(!s->budget--) { s->failed_pc=0x0c0847ceu; return 0; }
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0847d0;
P_0c0847d0: /* original f3f8, guest PC 0x0c0847d0 */
if(!s->budget--) { s->failed_pc=0x0c0847d0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0847d2;
P_0c0847d2: /* original f3f4, guest PC 0x0c0847d2 */
if(!s->budget--) { s->failed_pc=0x0c0847d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[15]))!=0);
goto P_0c0847d4;
P_0c0847d4: /* original 8b10, guest PC 0x0c0847d4 */
if(!s->budget--) { s->failed_pc=0x0c0847d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0847f8; }
goto P_0c0847d6;
P_0c0847d6: /* original 62f3, guest PC 0x0c0847d6 */
if(!s->budget--) { s->failed_pc=0x0c0847d6u; return 0; }
r[2]=r[15];
goto P_0c0847d8;
P_0c0847d8: /* original 7204, guest PC 0x0c0847d8 */
if(!s->budget--) { s->failed_pc=0x0c0847d8u; return 0; }
r[2]+=0x00000004u;
goto P_0c0847da;
P_0c0847da: /* original 2f26, guest PC 0x0c0847da */
if(!s->budget--) { s->failed_pc=0x0c0847dau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0847dc;
P_0c0847dc: /* original 65d3, guest PC 0x0c0847dc */
if(!s->budget--) { s->failed_pc=0x0c0847dcu; return 0; }
r[5]=r[13];
goto P_0c0847de;
P_0c0847de: /* original 63f3, guest PC 0x0c0847de */
if(!s->budget--) { s->failed_pc=0x0c0847deu; return 0; }
r[3]=r[15];
goto P_0c0847e0;
P_0c0847e0: /* original 730c, guest PC 0x0c0847e0 */
if(!s->budget--) { s->failed_pc=0x0c0847e0u; return 0; }
r[3]+=0x0000000cu;
goto P_0c0847e2;
P_0c0847e2: /* original 2f36, guest PC 0x0c0847e2 */
if(!s->budget--) { s->failed_pc=0x0c0847e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0847e4;
P_0c0847e4: /* original 62f3, guest PC 0x0c0847e4 */
if(!s->budget--) { s->failed_pc=0x0c0847e4u; return 0; }
r[2]=r[15];
goto P_0c0847e6;
P_0c0847e6: /* original 7214, guest PC 0x0c0847e6 */
if(!s->budget--) { s->failed_pc=0x0c0847e6u; return 0; }
r[2]+=0x00000014u;
goto P_0c0847e8;
P_0c0847e8: /* original 2f26, guest PC 0x0c0847e8 */
if(!s->budget--) { s->failed_pc=0x0c0847e8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0847ea;
P_0c0847ea: /* original 66f3, guest PC 0x0c0847ea */
if(!s->budget--) { s->failed_pc=0x0c0847eau; return 0; }
r[6]=r[15];
goto P_0c0847ec;
P_0c0847ec: /* original 67f3, guest PC 0x0c0847ec */
if(!s->budget--) { s->failed_pc=0x0c0847ecu; return 0; }
r[7]=r[15];
goto P_0c0847ee;
P_0c0847ee: /* original 761c, guest PC 0x0c0847ee */
if(!s->budget--) { s->failed_pc=0x0c0847eeu; return 0; }
r[6]+=0x0000001cu;
goto P_0c0847f0;
P_0c0847f0: /* original 770c, guest PC 0x0c0847f0 */
if(!s->budget--) { s->failed_pc=0x0c0847f0u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0847f2;
P_0c0847f2: /* original beb9, guest PC 0x0c0847f2 */
if(!s->budget--) { s->failed_pc=0x0c0847f2u; return 0; }
target=code_base|0x0c084568u; r[16]=code_base|0x0c0847f6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0847f6u) { target=s->pc; goto dispatch; }
goto P_0c0847f6;
P_0c0847f4: /* original 64e3, guest PC 0x0c0847f4 */
if(!s->budget--) { s->failed_pc=0x0c0847f4u; return 0; }
r[4]=r[14];
goto P_0c0847f6;
P_0c0847f6: /* original 7f0c, guest PC 0x0c0847f6 */
if(!s->budget--) { s->failed_pc=0x0c0847f6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0847f8;
P_0c0847f8: /* original e010, guest PC 0x0c0847f8 */
if(!s->budget--) { s->failed_pc=0x0c0847f8u; return 0; }
r[0]=0x00000010u;
goto P_0c0847fa;
P_0c0847fa: /* original f3f6, guest PC 0x0c0847fa */
if(!s->budget--) { s->failed_pc=0x0c0847fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0847fc;
P_0c0847fc: /* original e004, guest PC 0x0c0847fc */
if(!s->budget--) { s->failed_pc=0x0c0847fcu; return 0; }
r[0]=0x00000004u;
goto P_0c0847fe;
P_0c0847fe: /* original e120, guest PC 0x0c0847fe */
if(!s->budget--) { s->failed_pc=0x0c0847feu; return 0; }
r[1]=0x00000020u;
goto P_0c084800;
P_0c084800: /* original fe3a, guest PC 0x0c084800 */
if(!s->budget--) { s->failed_pc=0x0c084800u; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c084802;
P_0c084802: /* original 31ec, guest PC 0x0c084802 */
if(!s->budget--) { s->failed_pc=0x0c084802u; return 0; }
r[1]+=r[14];
goto P_0c084804;
P_0c084804: /* original f3f8, guest PC 0x0c084804 */
if(!s->budget--) { s->failed_pc=0x0c084804u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c084806;
P_0c084806: /* original e222, guest PC 0x0c084806 */
if(!s->budget--) { s->failed_pc=0x0c084806u; return 0; }
r[2]=0x00000022u;
goto P_0c084808;
P_0c084808: /* original 32ec, guest PC 0x0c084808 */
if(!s->budget--) { s->failed_pc=0x0c084808u; return 0; }
r[2]+=r[14];
goto P_0c08480a;
P_0c08480a: /* original fe37, guest PC 0x0c08480a */
if(!s->budget--) { s->failed_pc=0x0c08480au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c08480c;
P_0c08480c: /* original e00c, guest PC 0x0c08480c */
if(!s->budget--) { s->failed_pc=0x0c08480cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08480e;
P_0c08480e: /* original f3f6, guest PC 0x0c08480e */
if(!s->budget--) { s->failed_pc=0x0c08480eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c084810;
P_0c084810: /* original e008, guest PC 0x0c084810 */
if(!s->budget--) { s->failed_pc=0x0c084810u; return 0; }
r[0]=0x00000008u;
goto P_0c084812;
P_0c084812: /* original 7cff, guest PC 0x0c084812 */
if(!s->budget--) { s->failed_pc=0x0c084812u; return 0; }
r[12]+=0xffffffffu;
goto P_0c084814;
P_0c084814: /* original fe37, guest PC 0x0c084814 */
if(!s->budget--) { s->failed_pc=0x0c084814u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c084816;
P_0c084816: /* original 7e2c, guest PC 0x0c084816 */
if(!s->budget--) { s->failed_pc=0x0c084816u; return 0; }
r[14]+=0x0000002cu;
goto P_0c084818;
P_0c084818: /* original 85f4, guest PC 0x0c084818 */
if(!s->budget--) { s->failed_pc=0x0c084818u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c08481a;
P_0c08481a: /* original 2101, guest PC 0x0c08481a */
if(!s->budget--) { s->failed_pc=0x0c08481au; return 0; }
write(ram,r[1],r[0],2);
goto P_0c08481c;
P_0c08481c: /* original 85f2, guest PC 0x0c08481c */
if(!s->budget--) { s->failed_pc=0x0c08481cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08481e;
P_0c08481e: /* original 2201, guest PC 0x0c08481e */
if(!s->budget--) { s->failed_pc=0x0c08481eu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c084820;
P_0c084820: /* original 63cf, guest PC 0x0c084820 */
if(!s->budget--) { s->failed_pc=0x0c084820u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c084822;
P_0c084822: /* original 4315, guest PC 0x0c084822 */
if(!s->budget--) { s->failed_pc=0x0c084822u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c084824;
P_0c084824: /* original 8984, guest PC 0x0c084824 */
if(!s->budget--) { s->failed_pc=0x0c084824u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c084730; }
goto P_0c084826;
P_0c084826: /* original 9418, guest PC 0x0c084826 */
if(!s->budget--) { s->failed_pc=0x0c084826u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08485au,2);
goto P_0c084828;
P_0c084828: /* original 6eb3, guest PC 0x0c084828 */
if(!s->budget--) { s->failed_pc=0x0c084828u; return 0; }
r[14]=r[11];
goto P_0c08482a;
P_0c08482a: /* original 5d95, guest PC 0x0c08482a */
if(!s->budget--) { s->failed_pc=0x0c08482au; return 0; }
r[13]=read(ram,r[9]+20,4);
goto P_0c08482c;
P_0c08482c: /* original 7aff, guest PC 0x0c08482c */
if(!s->budget--) { s->failed_pc=0x0c08482cu; return 0; }
r[10]+=0xffffffffu;
goto P_0c08482e;
P_0c08482e: /* original 34bc, guest PC 0x0c08482e */
if(!s->budget--) { s->failed_pc=0x0c08482eu; return 0; }
r[4]+=r[11];
goto P_0c084830;
P_0c084830: /* original 7e14, guest PC 0x0c084830 */
if(!s->budget--) { s->failed_pc=0x0c084830u; return 0; }
r[14]+=0x00000014u;
goto P_0c084832;
P_0c084832: /* original 6c43, guest PC 0x0c084832 */
if(!s->budget--) { s->failed_pc=0x0c084832u; return 0; }
r[12]=r[4];
goto P_0c084834;
P_0c084834: /* original 63af, guest PC 0x0c084834 */
if(!s->budget--) { s->failed_pc=0x0c084834u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c084836;
P_0c084836: /* original 4315, guest PC 0x0c084836 */
if(!s->budget--) { s->failed_pc=0x0c084836u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c084838;
P_0c084838: /* original 8b01, guest PC 0x0c084838 */
if(!s->budget--) { s->failed_pc=0x0c084838u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08483e; }
goto P_0c08483a;
P_0c08483a: /* original af51, guest PC 0x0c08483a */
if(!s->budget--) { s->failed_pc=0x0c08483au; return 0; }
goto P_0c0846e0;
P_0c08483c: /* original 0009, guest PC 0x0c08483c */
if(!s->budget--) { s->failed_pc=0x0c08483cu; return 0; }
goto P_0c08483e;
P_0c08483e: /* original 7f24, guest PC 0x0c08483e */
if(!s->budget--) { s->failed_pc=0x0c08483eu; return 0; }
r[15]+=0x00000024u;
goto P_0c084840;
P_0c084840: /* original 4f26, guest PC 0x0c084840 */
if(!s->budget--) { s->failed_pc=0x0c084840u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c084842;
P_0c084842: /* original fcf9, guest PC 0x0c084842 */
if(!s->budget--) { s->failed_pc=0x0c084842u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084844;
P_0c084844: /* original fdf9, guest PC 0x0c084844 */
if(!s->budget--) { s->failed_pc=0x0c084844u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084846;
P_0c084846: /* original fef9, guest PC 0x0c084846 */
if(!s->budget--) { s->failed_pc=0x0c084846u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c084848;
P_0c084848: /* original fff9, guest PC 0x0c084848 */
if(!s->budget--) { s->failed_pc=0x0c084848u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08484a;
P_0c08484a: /* original 68f6, guest PC 0x0c08484a */
if(!s->budget--) { s->failed_pc=0x0c08484au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08484c;
P_0c08484c: /* original 69f6, guest PC 0x0c08484c */
if(!s->budget--) { s->failed_pc=0x0c08484cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08484e;
P_0c08484e: /* original 6af6, guest PC 0x0c08484e */
if(!s->budget--) { s->failed_pc=0x0c08484eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c084850;
P_0c084850: /* original 6bf6, guest PC 0x0c084850 */
if(!s->budget--) { s->failed_pc=0x0c084850u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c084852;
P_0c084852: /* original 6cf6, guest PC 0x0c084852 */
if(!s->budget--) { s->failed_pc=0x0c084852u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c084854;
P_0c084854: /* original 6df6, guest PC 0x0c084854 */
if(!s->budget--) { s->failed_pc=0x0c084854u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c084856;
P_0c084856: /* original 000b, guest PC 0x0c084856 */
if(!s->budget--) { s->failed_pc=0x0c084856u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c084858: /* original 6ef6, guest PC 0x0c084858 */
if(!s->budget--) { s->failed_pc=0x0c084858u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08485au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08485au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
