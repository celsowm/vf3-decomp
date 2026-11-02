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
int vf3_away_batch13_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c085580u: goto P_0c085580;
case 0x0c085582u: goto P_0c085582;
case 0x0c085584u: goto P_0c085584;
case 0x0c085586u: goto P_0c085586;
case 0x0c085588u: goto P_0c085588;
case 0x0c08558au: goto P_0c08558a;
case 0x0c08558cu: goto P_0c08558c;
case 0x0c08558eu: goto P_0c08558e;
case 0x0c085590u: goto P_0c085590;
case 0x0c085592u: goto P_0c085592;
case 0x0c085594u: goto P_0c085594;
case 0x0c085596u: goto P_0c085596;
case 0x0c085598u: goto P_0c085598;
case 0x0c08559au: goto P_0c08559a;
case 0x0c08559cu: goto P_0c08559c;
case 0x0c08559eu: goto P_0c08559e;
case 0x0c0855a0u: goto P_0c0855a0;
case 0x0c0855a2u: goto P_0c0855a2;
case 0x0c0855a4u: goto P_0c0855a4;
case 0x0c0855a6u: goto P_0c0855a6;
case 0x0c0855a8u: goto P_0c0855a8;
case 0x0c0855aau: goto P_0c0855aa;
case 0x0c0855acu: goto P_0c0855ac;
case 0x0c0855aeu: goto P_0c0855ae;
case 0x0c0855b0u: goto P_0c0855b0;
case 0x0c0855b2u: goto P_0c0855b2;
case 0x0c0855b4u: goto P_0c0855b4;
case 0x0c0855b6u: goto P_0c0855b6;
case 0x0c0855b8u: goto P_0c0855b8;
case 0x0c0855bau: goto P_0c0855ba;
case 0x0c0855bcu: goto P_0c0855bc;
case 0x0c0855beu: goto P_0c0855be;
case 0x0c0855c0u: goto P_0c0855c0;
case 0x0c0855c2u: goto P_0c0855c2;
case 0x0c0855c4u: goto P_0c0855c4;
case 0x0c0855c6u: goto P_0c0855c6;
case 0x0c0855c8u: goto P_0c0855c8;
case 0x0c0855cau: goto P_0c0855ca;
case 0x0c0855ccu: goto P_0c0855cc;
case 0x0c0855ceu: goto P_0c0855ce;
case 0x0c0855d0u: goto P_0c0855d0;
case 0x0c0855d2u: goto P_0c0855d2;
case 0x0c0855d4u: goto P_0c0855d4;
case 0x0c0855d6u: goto P_0c0855d6;
case 0x0c0855d8u: goto P_0c0855d8;
case 0x0c0855dau: goto P_0c0855da;
case 0x0c0855dcu: goto P_0c0855dc;
case 0x0c0855deu: goto P_0c0855de;
case 0x0c0855e0u: goto P_0c0855e0;
case 0x0c0855e2u: goto P_0c0855e2;
case 0x0c0855e4u: goto P_0c0855e4;
case 0x0c0855e6u: goto P_0c0855e6;
case 0x0c0855e8u: goto P_0c0855e8;
case 0x0c0855eau: goto P_0c0855ea;
case 0x0c0855ecu: goto P_0c0855ec;
case 0x0c0855eeu: goto P_0c0855ee;
case 0x0c0855f0u: goto P_0c0855f0;
case 0x0c0855f2u: goto P_0c0855f2;
case 0x0c0855f4u: goto P_0c0855f4;
case 0x0c0855f6u: goto P_0c0855f6;
case 0x0c0855f8u: goto P_0c0855f8;
case 0x0c0855fau: goto P_0c0855fa;
case 0x0c0855fcu: goto P_0c0855fc;
case 0x0c0855feu: goto P_0c0855fe;
case 0x0c085600u: goto P_0c085600;
case 0x0c085602u: goto P_0c085602;
case 0x0c085604u: goto P_0c085604;
case 0x0c085606u: goto P_0c085606;
case 0x0c085608u: goto P_0c085608;
case 0x0c08560au: goto P_0c08560a;
case 0x0c08560cu: goto P_0c08560c;
case 0x0c08560eu: goto P_0c08560e;
case 0x0c085610u: goto P_0c085610;
case 0x0c085612u: goto P_0c085612;
case 0x0c085614u: goto P_0c085614;
case 0x0c085616u: goto P_0c085616;
case 0x0c085618u: goto P_0c085618;
case 0x0c08561au: goto P_0c08561a;
case 0x0c08561cu: goto P_0c08561c;
case 0x0c08561eu: goto P_0c08561e;
case 0x0c085620u: goto P_0c085620;
case 0x0c085622u: goto P_0c085622;
case 0x0c085624u: goto P_0c085624;
case 0x0c085626u: goto P_0c085626;
case 0x0c085628u: goto P_0c085628;
case 0x0c08562au: goto P_0c08562a;
case 0x0c08562cu: goto P_0c08562c;
case 0x0c08562eu: goto P_0c08562e;
case 0x0c085630u: goto P_0c085630;
case 0x0c085632u: goto P_0c085632;
case 0x0c085634u: goto P_0c085634;
case 0x0c085654u: goto P_0c085654;
case 0x0c085656u: goto P_0c085656;
case 0x0c085658u: goto P_0c085658;
case 0x0c08565au: goto P_0c08565a;
case 0x0c08565cu: goto P_0c08565c;
case 0x0c08565eu: goto P_0c08565e;
case 0x0c085660u: goto P_0c085660;
case 0x0c085662u: goto P_0c085662;
case 0x0c085664u: goto P_0c085664;
case 0x0c085666u: goto P_0c085666;
case 0x0c085668u: goto P_0c085668;
case 0x0c08566au: goto P_0c08566a;
case 0x0c08566cu: goto P_0c08566c;
case 0x0c08566eu: goto P_0c08566e;
case 0x0c085670u: goto P_0c085670;
case 0x0c085672u: goto P_0c085672;
case 0x0c085674u: goto P_0c085674;
case 0x0c085676u: goto P_0c085676;
case 0x0c085678u: goto P_0c085678;
case 0x0c08567au: goto P_0c08567a;
case 0x0c08567cu: goto P_0c08567c;
case 0x0c08567eu: goto P_0c08567e;
case 0x0c085680u: goto P_0c085680;
case 0x0c085682u: goto P_0c085682;
case 0x0c085684u: goto P_0c085684;
case 0x0c085686u: goto P_0c085686;
case 0x0c085688u: goto P_0c085688;
case 0x0c08568au: goto P_0c08568a;
case 0x0c08568cu: goto P_0c08568c;
case 0x0c08568eu: goto P_0c08568e;
case 0x0c085690u: goto P_0c085690;
case 0x0c085692u: goto P_0c085692;
case 0x0c085694u: goto P_0c085694;
case 0x0c085696u: goto P_0c085696;
case 0x0c085698u: goto P_0c085698;
case 0x0c08569au: goto P_0c08569a;
case 0x0c08569cu: goto P_0c08569c;
case 0x0c08569eu: goto P_0c08569e;
case 0x0c0856a0u: goto P_0c0856a0;
case 0x0c0856a2u: goto P_0c0856a2;
case 0x0c0856a4u: goto P_0c0856a4;
case 0x0c0856a6u: goto P_0c0856a6;
case 0x0c0856a8u: goto P_0c0856a8;
case 0x0c0856aau: goto P_0c0856aa;
case 0x0c0856acu: goto P_0c0856ac;
case 0x0c0856aeu: goto P_0c0856ae;
case 0x0c0856b0u: goto P_0c0856b0;
case 0x0c0856b2u: goto P_0c0856b2;
case 0x0c0856b4u: goto P_0c0856b4;
case 0x0c0856b6u: goto P_0c0856b6;
case 0x0c0856b8u: goto P_0c0856b8;
case 0x0c0856bau: goto P_0c0856ba;
case 0x0c0856bcu: goto P_0c0856bc;
case 0x0c0856beu: goto P_0c0856be;
case 0x0c0856c0u: goto P_0c0856c0;
case 0x0c0856c2u: goto P_0c0856c2;
case 0x0c0856c4u: goto P_0c0856c4;
case 0x0c0856c6u: goto P_0c0856c6;
case 0x0c0856c8u: goto P_0c0856c8;
case 0x0c0856cau: goto P_0c0856ca;
case 0x0c0856ccu: goto P_0c0856cc;
case 0x0c0856ceu: goto P_0c0856ce;
case 0x0c0856d0u: goto P_0c0856d0;
case 0x0c0856d2u: goto P_0c0856d2;
case 0x0c0856d4u: goto P_0c0856d4;
case 0x0c0856d6u: goto P_0c0856d6;
case 0x0c0856d8u: goto P_0c0856d8;
case 0x0c0856dau: goto P_0c0856da;
case 0x0c0856dcu: goto P_0c0856dc;
case 0x0c0856deu: goto P_0c0856de;
case 0x0c0856e0u: goto P_0c0856e0;
case 0x0c0856e2u: goto P_0c0856e2;
case 0x0c0856e4u: goto P_0c0856e4;
case 0x0c0856e6u: goto P_0c0856e6;
case 0x0c0856e8u: goto P_0c0856e8;
case 0x0c0856eau: goto P_0c0856ea;
case 0x0c0856ecu: goto P_0c0856ec;
case 0x0c0856eeu: goto P_0c0856ee;
case 0x0c0856f0u: goto P_0c0856f0;
case 0x0c0856f2u: goto P_0c0856f2;
case 0x0c0856f4u: goto P_0c0856f4;
case 0x0c0856f6u: goto P_0c0856f6;
case 0x0c0856f8u: goto P_0c0856f8;
case 0x0c0856fau: goto P_0c0856fa;
case 0x0c0856fcu: goto P_0c0856fc;
case 0x0c0856feu: goto P_0c0856fe;
case 0x0c085700u: goto P_0c085700;
case 0x0c085702u: goto P_0c085702;
case 0x0c085704u: goto P_0c085704;
case 0x0c085706u: goto P_0c085706;
case 0x0c085708u: goto P_0c085708;
case 0x0c08570au: goto P_0c08570a;
case 0x0c08570cu: goto P_0c08570c;
case 0x0c08570eu: goto P_0c08570e;
case 0x0c085710u: goto P_0c085710;
case 0x0c085712u: goto P_0c085712;
case 0x0c085714u: goto P_0c085714;
case 0x0c085716u: goto P_0c085716;
case 0x0c085718u: goto P_0c085718;
case 0x0c08571au: goto P_0c08571a;
case 0x0c08571cu: goto P_0c08571c;
case 0x0c08571eu: goto P_0c08571e;
case 0x0c085720u: goto P_0c085720;
case 0x0c085722u: goto P_0c085722;
case 0x0c085724u: goto P_0c085724;
case 0x0c085726u: goto P_0c085726;
case 0x0c085728u: goto P_0c085728;
case 0x0c08572au: goto P_0c08572a;
case 0x0c08572cu: goto P_0c08572c;
case 0x0c08572eu: goto P_0c08572e;
case 0x0c085730u: goto P_0c085730;
case 0x0c085732u: goto P_0c085732;
case 0x0c085734u: goto P_0c085734;
case 0x0c085736u: goto P_0c085736;
case 0x0c085738u: goto P_0c085738;
case 0x0c08573au: goto P_0c08573a;
case 0x0c08573cu: goto P_0c08573c;
case 0x0c08573eu: goto P_0c08573e;
case 0x0c085740u: goto P_0c085740;
case 0x0c085742u: goto P_0c085742;
case 0x0c085744u: goto P_0c085744;
case 0x0c085746u: goto P_0c085746;
case 0x0c085748u: goto P_0c085748;
case 0x0c08574au: goto P_0c08574a;
case 0x0c08574cu: goto P_0c08574c;
case 0x0c08574eu: goto P_0c08574e;
case 0x0c085750u: goto P_0c085750;
case 0x0c085752u: goto P_0c085752;
case 0x0c085754u: goto P_0c085754;
case 0x0c085756u: goto P_0c085756;
case 0x0c085758u: goto P_0c085758;
case 0x0c08575au: goto P_0c08575a;
case 0x0c08575cu: goto P_0c08575c;
case 0x0c08575eu: goto P_0c08575e;
case 0x0c085760u: goto P_0c085760;
case 0x0c085762u: goto P_0c085762;
case 0x0c085764u: goto P_0c085764;
case 0x0c085766u: goto P_0c085766;
case 0x0c085768u: goto P_0c085768;
case 0x0c08576au: goto P_0c08576a;
case 0x0c08576cu: goto P_0c08576c;
case 0x0c08576eu: goto P_0c08576e;
case 0x0c085770u: goto P_0c085770;
case 0x0c085772u: goto P_0c085772;
case 0x0c085774u: goto P_0c085774;
case 0x0c085776u: goto P_0c085776;
case 0x0c085778u: goto P_0c085778;
case 0x0c08577au: goto P_0c08577a;
case 0x0c08577cu: goto P_0c08577c;
case 0x0c08577eu: goto P_0c08577e;
case 0x0c085780u: goto P_0c085780;
case 0x0c085782u: goto P_0c085782;
case 0x0c085784u: goto P_0c085784;
case 0x0c085786u: goto P_0c085786;
case 0x0c085788u: goto P_0c085788;
case 0x0c08578au: goto P_0c08578a;
case 0x0c08578cu: goto P_0c08578c;
case 0x0c08578eu: goto P_0c08578e;
case 0x0c085790u: goto P_0c085790;
case 0x0c085792u: goto P_0c085792;
case 0x0c085794u: goto P_0c085794;
case 0x0c085796u: goto P_0c085796;
case 0x0c085798u: goto P_0c085798;
case 0x0c08579au: goto P_0c08579a;
case 0x0c08579cu: goto P_0c08579c;
case 0x0c08579eu: goto P_0c08579e;
case 0x0c0857a0u: goto P_0c0857a0;
case 0x0c0857a2u: goto P_0c0857a2;
case 0x0c0857dcu: goto P_0c0857dc;
case 0x0c0857deu: goto P_0c0857de;
case 0x0c0857e0u: goto P_0c0857e0;
case 0x0c0857e2u: goto P_0c0857e2;
case 0x0c0857e4u: goto P_0c0857e4;
case 0x0c0857e6u: goto P_0c0857e6;
case 0x0c0857e8u: goto P_0c0857e8;
case 0x0c0857eau: goto P_0c0857ea;
case 0x0c0857ecu: goto P_0c0857ec;
case 0x0c0857eeu: goto P_0c0857ee;
case 0x0c0857f0u: goto P_0c0857f0;
case 0x0c0857f2u: goto P_0c0857f2;
case 0x0c0857f4u: goto P_0c0857f4;
case 0x0c0857f6u: goto P_0c0857f6;
case 0x0c0857f8u: goto P_0c0857f8;
case 0x0c0857fau: goto P_0c0857fa;
case 0x0c0857fcu: goto P_0c0857fc;
case 0x0c0857feu: goto P_0c0857fe;
case 0x0c085800u: goto P_0c085800;
case 0x0c085802u: goto P_0c085802;
case 0x0c085804u: goto P_0c085804;
case 0x0c085806u: goto P_0c085806;
case 0x0c085808u: goto P_0c085808;
case 0x0c08580au: goto P_0c08580a;
case 0x0c08580cu: goto P_0c08580c;
case 0x0c08580eu: goto P_0c08580e;
case 0x0c085810u: goto P_0c085810;
case 0x0c085812u: goto P_0c085812;
case 0x0c085814u: goto P_0c085814;
case 0x0c085816u: goto P_0c085816;
case 0x0c085818u: goto P_0c085818;
case 0x0c08581au: goto P_0c08581a;
case 0x0c08581cu: goto P_0c08581c;
case 0x0c08581eu: goto P_0c08581e;
case 0x0c085820u: goto P_0c085820;
case 0x0c085822u: goto P_0c085822;
case 0x0c085824u: goto P_0c085824;
case 0x0c085826u: goto P_0c085826;
case 0x0c085828u: goto P_0c085828;
case 0x0c08582au: goto P_0c08582a;
case 0x0c08582cu: goto P_0c08582c;
case 0x0c08582eu: goto P_0c08582e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c085580: /* original 2fe6, guest PC 0x0c085580 */
if(!s->budget--) { s->failed_pc=0x0c085580u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085582;
P_0c085582: /* original 6543, guest PC 0x0c085582 */
if(!s->budget--) { s->failed_pc=0x0c085582u; return 0; }
r[5]=r[4];
goto P_0c085584;
P_0c085584: /* original 2fd6, guest PC 0x0c085584 */
if(!s->budget--) { s->failed_pc=0x0c085584u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085586;
P_0c085586: /* original 2fc6, guest PC 0x0c085586 */
if(!s->budget--) { s->failed_pc=0x0c085586u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085588;
P_0c085588: /* original 2fb6, guest PC 0x0c085588 */
if(!s->budget--) { s->failed_pc=0x0c085588u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08558a;
P_0c08558a: /* original 2fa6, guest PC 0x0c08558a */
if(!s->budget--) { s->failed_pc=0x0c08558au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08558c;
P_0c08558c: /* original 2f96, guest PC 0x0c08558c */
if(!s->budget--) { s->failed_pc=0x0c08558cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08558e;
P_0c08558e: /* original 2f86, guest PC 0x0c08558e */
if(!s->budget--) { s->failed_pc=0x0c08558eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085590;
P_0c085590: /* original fffb, guest PC 0x0c085590 */
if(!s->budget--) { s->failed_pc=0x0c085590u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085592;
P_0c085592: /* original ffeb, guest PC 0x0c085592 */
if(!s->budget--) { s->failed_pc=0x0c085592u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c085594;
P_0c085594: /* original ffdb, guest PC 0x0c085594 */
if(!s->budget--) { s->failed_pc=0x0c085594u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c085596;
P_0c085596: /* original ffcb, guest PC 0x0c085596 */
if(!s->budget--) { s->failed_pc=0x0c085596u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c085598;
P_0c085598: /* original d327, guest PC 0x0c085598 */
if(!s->budget--) { s->failed_pc=0x0c085598u; return 0; }
r[3]=read(ram,0x0c085638u,4);
goto P_0c08559a;
P_0c08559a: /* original 4f22, guest PC 0x0c08559a */
if(!s->budget--) { s->failed_pc=0x0c08559au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08559c;
P_0c08559c: /* original 6430, guest PC 0x0c08559c */
if(!s->budget--) { s->failed_pc=0x0c08559cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[4]=tmp;
goto P_0c08559e;
P_0c08559e: /* original 604c, guest PC 0x0c08559e */
if(!s->budget--) { s->failed_pc=0x0c08559eu; return 0; }
r[0]=r[4]&255u;
goto P_0c0855a0;
P_0c0855a0: /* original 8809, guest PC 0x0c0855a0 */
if(!s->budget--) { s->failed_pc=0x0c0855a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0855a2;
P_0c0855a2: /* original 8d06, guest PC 0x0c0855a2 */
if(!s->budget--) { s->failed_pc=0x0c0855a2u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0855b2; }
goto P_0c0855a6;
P_0c0855a4: /* original 6403, guest PC 0x0c0855a4 */
if(!s->budget--) { s->failed_pc=0x0c0855a4u; return 0; }
r[4]=r[0];
goto P_0c0855a6;
P_0c0855a6: /* original 6043, guest PC 0x0c0855a6 */
if(!s->budget--) { s->failed_pc=0x0c0855a6u; return 0; }
r[0]=r[4];
goto P_0c0855a8;
P_0c0855a8: /* original 880d, guest PC 0x0c0855a8 */
if(!s->budget--) { s->failed_pc=0x0c0855a8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0855aa;
P_0c0855aa: /* original 8902, guest PC 0x0c0855aa */
if(!s->budget--) { s->failed_pc=0x0c0855aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0855b2; }
goto P_0c0855ac;
P_0c0855ac: /* original 6043, guest PC 0x0c0855ac */
if(!s->budget--) { s->failed_pc=0x0c0855acu; return 0; }
r[0]=r[4];
goto P_0c0855ae;
P_0c0855ae: /* original 880f, guest PC 0x0c0855ae */
if(!s->budget--) { s->failed_pc=0x0c0855aeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0855b0;
P_0c0855b0: /* original 8b34, guest PC 0x0c0855b0 */
if(!s->budget--) { s->failed_pc=0x0c0855b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08561c; }
goto P_0c0855b2;
P_0c0855b2: /* original d322, guest PC 0x0c0855b2 */
if(!s->budget--) { s->failed_pc=0x0c0855b2u; return 0; }
r[3]=read(ram,0x0c08563cu,4);
goto P_0c0855b4;
P_0c0855b4: /* original 6e53, guest PC 0x0c0855b4 */
if(!s->budget--) { s->failed_pc=0x0c0855b4u; return 0; }
r[14]=r[5];
goto P_0c0855b6;
P_0c0855b6: /* original 430b, guest PC 0x0c0855b6 */
if(!s->budget--) { s->failed_pc=0x0c0855b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0855bau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0855bau) { target=s->pc; goto dispatch; }
goto P_0c0855ba;
P_0c0855b8: /* original e400, guest PC 0x0c0855b8 */
if(!s->budget--) { s->failed_pc=0x0c0855b8u; return 0; }
r[4]=0x00000000u;
goto P_0c0855ba;
P_0c0855ba: /* original da23, guest PC 0x0c0855ba */
if(!s->budget--) { s->failed_pc=0x0c0855bau; return 0; }
r[10]=read(ram,0x0c085648u,4);
goto P_0c0855bc;
P_0c0855bc: /* original ec0d, guest PC 0x0c0855bc */
if(!s->budget--) { s->failed_pc=0x0c0855bcu; return 0; }
r[12]=0x0000000du;
goto P_0c0855be;
P_0c0855be: /* original d921, guest PC 0x0c0855be */
if(!s->budget--) { s->failed_pc=0x0c0855beu; return 0; }
r[9]=read(ram,0x0c085644u,4);
goto P_0c0855c0;
P_0c0855c0: /* original d81f, guest PC 0x0c0855c0 */
if(!s->budget--) { s->failed_pc=0x0c0855c0u; return 0; }
r[8]=read(ram,0x0c085640u,4);
goto P_0c0855c2;
P_0c0855c2: /* original ff9d, guest PC 0x0c0855c2 */
if(!s->budget--) { s->failed_pc=0x0c0855c2u; return 0; }
fr[15]=0x3f800000u;
goto P_0c0855c4;
P_0c0855c4: /* original 85e7, guest PC 0x0c0855c4 */
if(!s->budget--) { s->failed_pc=0x0c0855c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0855c6;
P_0c0855c6: /* original 6403, guest PC 0x0c0855c6 */
if(!s->budget--) { s->failed_pc=0x0c0855c6u; return 0; }
r[4]=r[0];
goto P_0c0855c8;
P_0c0855c8: /* original 6d4f, guest PC 0x0c0855c8 */
if(!s->budget--) { s->failed_pc=0x0c0855c8u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0855ca;
P_0c0855ca: /* original 60d3, guest PC 0x0c0855ca */
if(!s->budget--) { s->failed_pc=0x0c0855cau; return 0; }
r[0]=r[13];
goto P_0c0855cc;
P_0c0855cc: /* original 88ff, guest PC 0x0c0855cc */
if(!s->budget--) { s->failed_pc=0x0c0855ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0855ce;
P_0c0855ce: /* original 8913, guest PC 0x0c0855ce */
if(!s->budget--) { s->failed_pc=0x0c0855ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0855f8; }
goto P_0c0855d0;
P_0c0855d0: /* original e004, guest PC 0x0c0855d0 */
if(!s->budget--) { s->failed_pc=0x0c0855d0u; return 0; }
r[0]=0x00000004u;
goto P_0c0855d2;
P_0c0855d2: /* original fce8, guest PC 0x0c0855d2 */
if(!s->budget--) { s->failed_pc=0x0c0855d2u; return 0; }
vf3_matrix_load(s,ram,12,r[14]);
goto P_0c0855d4;
P_0c0855d4: /* original fde6, guest PC 0x0c0855d4 */
if(!s->budget--) { s->failed_pc=0x0c0855d4u; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c0855d6;
P_0c0855d6: /* original e008, guest PC 0x0c0855d6 */
if(!s->budget--) { s->failed_pc=0x0c0855d6u; return 0; }
r[0]=0x00000008u;
goto P_0c0855d8;
P_0c0855d8: /* original f3e6, guest PC 0x0c0855d8 */
if(!s->budget--) { s->failed_pc=0x0c0855d8u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0855da;
P_0c0855da: /* original 85e9, guest PC 0x0c0855da */
if(!s->budget--) { s->failed_pc=0x0c0855dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+18,2);
goto P_0c0855dc;
P_0c0855dc: /* original f3f2, guest PC 0x0c0855dc */
if(!s->budget--) { s->failed_pc=0x0c0855dcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c0855de;
P_0c0855de: /* original fe3c, guest PC 0x0c0855de */
if(!s->budget--) { s->failed_pc=0x0c0855deu; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c0855e0;
P_0c0855e0: /* original fe4d, guest PC 0x0c0855e0 */
if(!s->budget--) { s->failed_pc=0x0c0855e0u; return 0; }
fr[14]^=0x80000000u;
goto P_0c0855e2;
P_0c0855e2: /* original 490b, guest PC 0x0c0855e2 */
if(!s->budget--) { s->failed_pc=0x0c0855e2u; return 0; }
target=r[9];
r[16]=code_base|0x0c0855e6u;
r[11]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0855e6u) { target=s->pc; goto dispatch; }
goto P_0c0855e6;
P_0c0855e4: /* original 6b03, guest PC 0x0c0855e4 */
if(!s->budget--) { s->failed_pc=0x0c0855e4u; return 0; }
r[11]=r[0];
goto P_0c0855e6;
P_0c0855e6: /* original f5dc, guest PC 0x0c0855e6 */
if(!s->budget--) { s->failed_pc=0x0c0855e6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c0855e8;
P_0c0855e8: /* original f6ec, guest PC 0x0c0855e8 */
if(!s->budget--) { s->failed_pc=0x0c0855e8u; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0855ea;
P_0c0855ea: /* original 480b, guest PC 0x0c0855ea */
if(!s->budget--) { s->failed_pc=0x0c0855eau; return 0; }
target=r[8];
r[16]=code_base|0x0c0855eeu;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0855eeu) { target=s->pc; goto dispatch; }
goto P_0c0855ee;
P_0c0855ec: /* original f4cc, guest PC 0x0c0855ec */
if(!s->budget--) { s->failed_pc=0x0c0855ecu; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c0855ee;
P_0c0855ee: /* original d317, guest PC 0x0c0855ee */
if(!s->budget--) { s->failed_pc=0x0c0855eeu; return 0; }
r[3]=read(ram,0x0c08564cu,4);
goto P_0c0855f0;
P_0c0855f0: /* original 430b, guest PC 0x0c0855f0 */
if(!s->budget--) { s->failed_pc=0x0c0855f0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0855f4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0855f4u) { target=s->pc; goto dispatch; }
goto P_0c0855f4;
P_0c0855f2: /* original 64b3, guest PC 0x0c0855f2 */
if(!s->budget--) { s->failed_pc=0x0c0855f2u; return 0; }
r[4]=r[11];
goto P_0c0855f4;
P_0c0855f4: /* original 4a0b, guest PC 0x0c0855f4 */
if(!s->budget--) { s->failed_pc=0x0c0855f4u; return 0; }
target=r[10];
r[16]=code_base|0x0c0855f8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0855f8u) { target=s->pc; goto dispatch; }
goto P_0c0855f8;
P_0c0855f6: /* original 64d3, guest PC 0x0c0855f6 */
if(!s->budget--) { s->failed_pc=0x0c0855f6u; return 0; }
r[4]=r[13];
goto P_0c0855f8;
P_0c0855f8: /* original 4c10, guest PC 0x0c0855f8 */
if(!s->budget--) { s->failed_pc=0x0c0855f8u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c0855fa;
P_0c0855fa: /* original 8fe3, guest PC 0x0c0855fa */
if(!s->budget--) { s->failed_pc=0x0c0855fau; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c0855c4; }
goto P_0c0855fe;
P_0c0855fc: /* original 7e18, guest PC 0x0c0855fc */
if(!s->budget--) { s->failed_pc=0x0c0855fcu; return 0; }
r[14]+=0x00000018u;
goto P_0c0855fe;
P_0c0855fe: /* original 4f26, guest PC 0x0c0855fe */
if(!s->budget--) { s->failed_pc=0x0c0855feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085600;
P_0c085600: /* original d313, guest PC 0x0c085600 */
if(!s->budget--) { s->failed_pc=0x0c085600u; return 0; }
r[3]=read(ram,0x0c085650u,4);
goto P_0c085602;
P_0c085602: /* original e401, guest PC 0x0c085602 */
if(!s->budget--) { s->failed_pc=0x0c085602u; return 0; }
r[4]=0x00000001u;
goto P_0c085604;
P_0c085604: /* original fcf9, guest PC 0x0c085604 */
if(!s->budget--) { s->failed_pc=0x0c085604u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085606;
P_0c085606: /* original fdf9, guest PC 0x0c085606 */
if(!s->budget--) { s->failed_pc=0x0c085606u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085608;
P_0c085608: /* original fef9, guest PC 0x0c085608 */
if(!s->budget--) { s->failed_pc=0x0c085608u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08560a;
P_0c08560a: /* original fff9, guest PC 0x0c08560a */
if(!s->budget--) { s->failed_pc=0x0c08560au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08560c;
P_0c08560c: /* original 68f6, guest PC 0x0c08560c */
if(!s->budget--) { s->failed_pc=0x0c08560cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c08560e;
P_0c08560e: /* original 69f6, guest PC 0x0c08560e */
if(!s->budget--) { s->failed_pc=0x0c08560eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c085610;
P_0c085610: /* original 6af6, guest PC 0x0c085610 */
if(!s->budget--) { s->failed_pc=0x0c085610u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085612;
P_0c085612: /* original 6bf6, guest PC 0x0c085612 */
if(!s->budget--) { s->failed_pc=0x0c085612u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085614;
P_0c085614: /* original 6cf6, guest PC 0x0c085614 */
if(!s->budget--) { s->failed_pc=0x0c085614u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085616;
P_0c085616: /* original 6df6, guest PC 0x0c085616 */
if(!s->budget--) { s->failed_pc=0x0c085616u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085618;
P_0c085618: /* original 432b, guest PC 0x0c085618 */
if(!s->budget--) { s->failed_pc=0x0c085618u; return 0; }
target=r[3];
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
P_0c08561a: /* original 6ef6, guest PC 0x0c08561a */
if(!s->budget--) { s->failed_pc=0x0c08561au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08561c;
P_0c08561c: /* original 4f26, guest PC 0x0c08561c */
if(!s->budget--) { s->failed_pc=0x0c08561cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08561e;
P_0c08561e: /* original fcf9, guest PC 0x0c08561e */
if(!s->budget--) { s->failed_pc=0x0c08561eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085620;
P_0c085620: /* original fdf9, guest PC 0x0c085620 */
if(!s->budget--) { s->failed_pc=0x0c085620u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085622;
P_0c085622: /* original fef9, guest PC 0x0c085622 */
if(!s->budget--) { s->failed_pc=0x0c085622u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085624;
P_0c085624: /* original fff9, guest PC 0x0c085624 */
if(!s->budget--) { s->failed_pc=0x0c085624u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085626;
P_0c085626: /* original 68f6, guest PC 0x0c085626 */
if(!s->budget--) { s->failed_pc=0x0c085626u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085628;
P_0c085628: /* original 69f6, guest PC 0x0c085628 */
if(!s->budget--) { s->failed_pc=0x0c085628u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c08562a;
P_0c08562a: /* original 6af6, guest PC 0x0c08562a */
if(!s->budget--) { s->failed_pc=0x0c08562au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c08562c;
P_0c08562c: /* original 6bf6, guest PC 0x0c08562c */
if(!s->budget--) { s->failed_pc=0x0c08562cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08562e;
P_0c08562e: /* original 6cf6, guest PC 0x0c08562e */
if(!s->budget--) { s->failed_pc=0x0c08562eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085630;
P_0c085630: /* original 6df6, guest PC 0x0c085630 */
if(!s->budget--) { s->failed_pc=0x0c085630u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085632;
P_0c085632: /* original 000b, guest PC 0x0c085632 */
if(!s->budget--) { s->failed_pc=0x0c085632u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085634: /* original 6ef6, guest PC 0x0c085634 */
if(!s->budget--) { s->failed_pc=0x0c085634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085636u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085636u; return 0; } return 1;
P_0c085654: /* original 2fe6, guest PC 0x0c085654 */
if(!s->budget--) { s->failed_pc=0x0c085654u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085656;
P_0c085656: /* original c758, guest PC 0x0c085656 */
if(!s->budget--) { s->failed_pc=0x0c085656u; return 0; }
r[0]=code_base|0x000857b8u;
goto P_0c085658;
P_0c085658: /* original 2fd6, guest PC 0x0c085658 */
if(!s->budget--) { s->failed_pc=0x0c085658u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08565a;
P_0c08565a: /* original 2fc6, guest PC 0x0c08565a */
if(!s->budget--) { s->failed_pc=0x0c08565au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08565c;
P_0c08565c: /* original 2fb6, guest PC 0x0c08565c */
if(!s->budget--) { s->failed_pc=0x0c08565cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08565e;
P_0c08565e: /* original 2fa6, guest PC 0x0c08565e */
if(!s->budget--) { s->failed_pc=0x0c08565eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085660;
P_0c085660: /* original 2f96, guest PC 0x0c085660 */
if(!s->budget--) { s->failed_pc=0x0c085660u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085662;
P_0c085662: /* original 2f86, guest PC 0x0c085662 */
if(!s->budget--) { s->failed_pc=0x0c085662u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085664;
P_0c085664: /* original fffb, guest PC 0x0c085664 */
if(!s->budget--) { s->failed_pc=0x0c085664u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c085666;
P_0c085666: /* original 4f22, guest PC 0x0c085666 */
if(!s->budget--) { s->failed_pc=0x0c085666u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085668;
P_0c085668: /* original d352, guest PC 0x0c085668 */
if(!s->budget--) { s->failed_pc=0x0c085668u; return 0; }
r[3]=read(ram,0x0c0857b4u,4);
goto P_0c08566a;
P_0c08566a: /* original 7ff4, guest PC 0x0c08566a */
if(!s->budget--) { s->failed_pc=0x0c08566au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08566c;
P_0c08566c: /* original 1f32, guest PC 0x0c08566c */
if(!s->budget--) { s->failed_pc=0x0c08566cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08566e;
P_0c08566e: /* original d154, guest PC 0x0c08566e */
if(!s->budget--) { s->failed_pc=0x0c08566eu; return 0; }
r[1]=read(ram,0x0c0857c0u,4);
goto P_0c085670;
P_0c085670: /* original d352, guest PC 0x0c085670 */
if(!s->budget--) { s->failed_pc=0x0c085670u; return 0; }
r[3]=read(ram,0x0c0857bcu,4);
goto P_0c085672;
P_0c085672: /* original 6212, guest PC 0x0c085672 */
if(!s->budget--) { s->failed_pc=0x0c085672u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c085674;
P_0c085674: /* original ff08, guest PC 0x0c085674 */
if(!s->budget--) { s->failed_pc=0x0c085674u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c085676;
P_0c085676: /* original 2238, guest PC 0x0c085676 */
if(!s->budget--) { s->failed_pc=0x0c085676u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c085678;
P_0c085678: /* original 8d02, guest PC 0x0c085678 */
if(!s->budget--) { s->failed_pc=0x0c085678u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c085680; }
goto P_0c08567c;
P_0c08567a: /* original 6e43, guest PC 0x0c08567a */
if(!s->budget--) { s->failed_pc=0x0c08567au; return 0; }
r[14]=r[4];
goto P_0c08567c;
P_0c08567c: /* original a0cd, guest PC 0x0c08567c */
if(!s->budget--) { s->failed_pc=0x0c08567cu; return 0; }
goto P_0c08581a;
P_0c08567e: /* original 0009, guest PC 0x0c08567e */
if(!s->budget--) { s->failed_pc=0x0c08567eu; return 0; }
goto P_0c085680;
P_0c085680: /* original 9090, guest PC 0x0c085680 */
if(!s->budget--) { s->failed_pc=0x0c085680u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a4u,2);
goto P_0c085682;
P_0c085682: /* original 9390, guest PC 0x0c085682 */
if(!s->budget--) { s->failed_pc=0x0c085682u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a6u,2);
goto P_0c085684;
P_0c085684: /* original 0bed, guest PC 0x0c085684 */
if(!s->budget--) { s->failed_pc=0x0c085684u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085686;
P_0c085686: /* original 70fe, guest PC 0x0c085686 */
if(!s->budget--) { s->failed_pc=0x0c085686u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c085688;
P_0c085688: /* original 928e, guest PC 0x0c085688 */
if(!s->budget--) { s->failed_pc=0x0c085688u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a8u,2);
goto P_0c08568a;
P_0c08568a: /* original 0ced, guest PC 0x0c08568a */
if(!s->budget--) { s->failed_pc=0x0c08568au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08568c;
P_0c08568c: /* original 7004, guest PC 0x0c08568c */
if(!s->budget--) { s->failed_pc=0x0c08568cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08568e;
P_0c08568e: /* original 0aed, guest PC 0x0c08568e */
if(!s->budget--) { s->failed_pc=0x0c08568eu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085690;
P_0c085690: /* original 3b3c, guest PC 0x0c085690 */
if(!s->budget--) { s->failed_pc=0x0c085690u; return 0; }
r[11]+=r[3];
goto P_0c085692;
P_0c085692: /* original 3c2c, guest PC 0x0c085692 */
if(!s->budget--) { s->failed_pc=0x0c085692u; return 0; }
r[12]+=r[2];
goto P_0c085694;
P_0c085694: /* original 9189, guest PC 0x0c085694 */
if(!s->budget--) { s->failed_pc=0x0c085694u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aau,2);
goto P_0c085696;
P_0c085696: /* original e0ff, guest PC 0x0c085696 */
if(!s->budget--) { s->failed_pc=0x0c085696u; return 0; }
r[0]=0xffffffffu;
goto P_0c085698;
P_0c085698: /* original 63cf, guest PC 0x0c085698 */
if(!s->budget--) { s->failed_pc=0x0c085698u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c08569a;
P_0c08569a: /* original 3303, guest PC 0x0c08569a */
if(!s->budget--) { s->failed_pc=0x0c08569au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[0])!=0);
goto P_0c08569c;
P_0c08569c: /* original 8f0f, guest PC 0x0c08569c */
if(!s->budget--) { s->failed_pc=0x0c08569cu; return 0; }
cond=r[17]&1u;
r[10]+=r[1];
if(!cond) { goto P_0c0856be; }
goto P_0c0856a0;
P_0c08569e: /* original 3a1c, guest PC 0x0c08569e */
if(!s->budget--) { s->failed_pc=0x0c08569eu; return 0; }
r[10]+=r[1];
goto P_0c0856a0;
P_0c0856a0: /* original d348, guest PC 0x0c0856a0 */
if(!s->budget--) { s->failed_pc=0x0c0856a0u; return 0; }
r[3]=read(ram,0x0c0857c4u,4);
goto P_0c0856a2;
P_0c0856a2: /* original 430b, guest PC 0x0c0856a2 */
if(!s->budget--) { s->failed_pc=0x0c0856a2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0856a6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0856a6u) { target=s->pc; goto dispatch; }
goto P_0c0856a6;
P_0c0856a4: /* original 0009, guest PC 0x0c0856a4 */
if(!s->budget--) { s->failed_pc=0x0c0856a4u; return 0; }
goto P_0c0856a6;
P_0c0856a6: /* original e2e2, guest PC 0x0c0856a6 */
if(!s->budget--) { s->failed_pc=0x0c0856a6u; return 0; }
r[2]=0xffffffe2u;
goto P_0c0856a8;
P_0c0856a8: /* original 6303, guest PC 0x0c0856a8 */
if(!s->budget--) { s->failed_pc=0x0c0856a8u; return 0; }
r[3]=r[0];
goto P_0c0856aa;
P_0c0856aa: /* original 432c, guest PC 0x0c0856aa */
if(!s->budget--) { s->failed_pc=0x0c0856aau; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[3]>>((-r[2])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[2]&31u);
goto P_0c0856ac;
P_0c0856ac: /* original d446, guest PC 0x0c0856ac */
if(!s->budget--) { s->failed_pc=0x0c0856acu; return 0; }
r[4]=read(ram,0x0c0857c8u,4);
goto P_0c0856ae;
P_0c0856ae: /* original 4008, guest PC 0x0c0856ae */
if(!s->budget--) { s->failed_pc=0x0c0856aeu; return 0; }
r[0]<<=2;
goto P_0c0856b0;
P_0c0856b0: /* original e50c, guest PC 0x0c0856b0 */
if(!s->budget--) { s->failed_pc=0x0c0856b0u; return 0; }
r[5]=0x0000000cu;
goto P_0c0856b2;
P_0c0856b2: /* original 203b, guest PC 0x0c0856b2 */
if(!s->budget--) { s->failed_pc=0x0c0856b2u; return 0; }
r[0]|=r[3];
goto P_0c0856b4;
P_0c0856b4: /* original 2509, guest PC 0x0c0856b4 */
if(!s->budget--) { s->failed_pc=0x0c0856b4u; return 0; }
r[5]&=r[0];
goto P_0c0856b6;
P_0c0856b6: /* original 6053, guest PC 0x0c0856b6 */
if(!s->budget--) { s->failed_pc=0x0c0856b6u; return 0; }
r[0]=r[5];
goto P_0c0856b8;
P_0c0856b8: /* original f446, guest PC 0x0c0856b8 */
if(!s->budget--) { s->failed_pc=0x0c0856b8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0856ba;
P_0c0856ba: /* original 9077, guest PC 0x0c0856ba */
if(!s->budget--) { s->failed_pc=0x0c0856bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857acu,2);
goto P_0c0856bc;
P_0c0856bc: /* original fe47, guest PC 0x0c0856bc */
if(!s->budget--) { s->failed_pc=0x0c0856bcu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0856be;
P_0c0856be: /* original 9071, guest PC 0x0c0856be */
if(!s->budget--) { s->failed_pc=0x0c0856beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857a4u,2);
goto P_0c0856c0;
P_0c0856c0: /* original 0eb5, guest PC 0x0c0856c0 */
if(!s->budget--) { s->failed_pc=0x0c0856c0u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0856c2;
P_0c0856c2: /* original 70fe, guest PC 0x0c0856c2 */
if(!s->budget--) { s->failed_pc=0x0c0856c2u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0856c4;
P_0c0856c4: /* original 0ec5, guest PC 0x0c0856c4 */
if(!s->budget--) { s->failed_pc=0x0c0856c4u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0856c6;
P_0c0856c6: /* original 7004, guest PC 0x0c0856c6 */
if(!s->budget--) { s->failed_pc=0x0c0856c6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0856c8;
P_0c0856c8: /* original 0ea5, guest PC 0x0c0856c8 */
if(!s->budget--) { s->failed_pc=0x0c0856c8u; return 0; }
write(ram,r[14]+r[0],r[10],2);
goto P_0c0856ca;
P_0c0856ca: /* original e004, guest PC 0x0c0856ca */
if(!s->budget--) { s->failed_pc=0x0c0856cau; return 0; }
r[0]=0x00000004u;
goto P_0c0856cc;
P_0c0856cc: /* original d83f, guest PC 0x0c0856cc */
if(!s->budget--) { s->failed_pc=0x0c0856ccu; return 0; }
r[8]=read(ram,0x0c0857ccu,4);
goto P_0c0856ce;
P_0c0856ce: /* original d341, guest PC 0x0c0856ce */
if(!s->budget--) { s->failed_pc=0x0c0856ceu; return 0; }
r[3]=read(ram,0x0c0857d4u,4);
goto P_0c0856d0;
P_0c0856d0: /* original 6483, guest PC 0x0c0856d0 */
if(!s->budget--) { s->failed_pc=0x0c0856d0u; return 0; }
r[4]=r[8];
goto P_0c0856d2;
P_0c0856d2: /* original f546, guest PC 0x0c0856d2 */
if(!s->budget--) { s->failed_pc=0x0c0856d2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0856d4;
P_0c0856d4: /* original 6432, guest PC 0x0c0856d4 */
if(!s->budget--) { s->failed_pc=0x0c0856d4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0856d6;
P_0c0856d6: /* original e061, guest PC 0x0c0856d6 */
if(!s->budget--) { s->failed_pc=0x0c0856d6u; return 0; }
r[0]=0x00000061u;
goto P_0c0856d8;
P_0c0856d8: /* original f488, guest PC 0x0c0856d8 */
if(!s->budget--) { s->failed_pc=0x0c0856d8u; return 0; }
vf3_matrix_load(s,ram,4,r[8]);
goto P_0c0856da;
P_0c0856da: /* original 054c, guest PC 0x0c0856da */
if(!s->budget--) { s->failed_pc=0x0c0856dau; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0856dc;
P_0c0856dc: /* original dd3c, guest PC 0x0c0856dc */
if(!s->budget--) { s->failed_pc=0x0c0856dcu; return 0; }
r[13]=read(ram,0x0c0857d0u,4);
goto P_0c0856de;
P_0c0856de: /* original 605c, guest PC 0x0c0856de */
if(!s->budget--) { s->failed_pc=0x0c0856deu; return 0; }
r[0]=r[5]&255u;
goto P_0c0856e0;
P_0c0856e0: /* original 8809, guest PC 0x0c0856e0 */
if(!s->budget--) { s->failed_pc=0x0c0856e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0856e2;
P_0c0856e2: /* original 8d1c, guest PC 0x0c0856e2 */
if(!s->budget--) { s->failed_pc=0x0c0856e2u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c08571e; }
goto P_0c0856e6;
P_0c0856e4: /* original 6503, guest PC 0x0c0856e4 */
if(!s->budget--) { s->failed_pc=0x0c0856e4u; return 0; }
r[5]=r[0];
goto P_0c0856e6;
P_0c0856e6: /* original 6053, guest PC 0x0c0856e6 */
if(!s->budget--) { s->failed_pc=0x0c0856e6u; return 0; }
r[0]=r[5];
goto P_0c0856e8;
P_0c0856e8: /* original 8804, guest PC 0x0c0856e8 */
if(!s->budget--) { s->failed_pc=0x0c0856e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0856ea;
P_0c0856ea: /* original 8918, guest PC 0x0c0856ea */
if(!s->budget--) { s->failed_pc=0x0c0856eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08571e; }
goto P_0c0856ec;
P_0c0856ec: /* original 6053, guest PC 0x0c0856ec */
if(!s->budget--) { s->failed_pc=0x0c0856ecu; return 0; }
r[0]=r[5];
goto P_0c0856ee;
P_0c0856ee: /* original 880b, guest PC 0x0c0856ee */
if(!s->budget--) { s->failed_pc=0x0c0856eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0856f0;
P_0c0856f0: /* original 8915, guest PC 0x0c0856f0 */
if(!s->budget--) { s->failed_pc=0x0c0856f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08571e; }
goto P_0c0856f2;
P_0c0856f2: /* original 905c, guest PC 0x0c0856f2 */
if(!s->budget--) { s->failed_pc=0x0c0856f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c0856f4;
P_0c0856f4: /* original 66a3, guest PC 0x0c0856f4 */
if(!s->budget--) { s->failed_pc=0x0c0856f4u; return 0; }
r[6]=r[10];
goto P_0c0856f6;
P_0c0856f6: /* original 65c3, guest PC 0x0c0856f6 */
if(!s->budget--) { s->failed_pc=0x0c0856f6u; return 0; }
r[5]=r[12];
goto P_0c0856f8;
P_0c0856f8: /* original f346, guest PC 0x0c0856f8 */
if(!s->budget--) { s->failed_pc=0x0c0856f8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0856fa;
P_0c0856fa: /* original e004, guest PC 0x0c0856fa */
if(!s->budget--) { s->failed_pc=0x0c0856fau; return 0; }
r[0]=0x00000004u;
goto P_0c0856fc;
P_0c0856fc: /* original ff37, guest PC 0x0c0856fc */
if(!s->budget--) { s->failed_pc=0x0c0856fcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0856fe;
P_0c0856fe: /* original 9057, guest PC 0x0c0856fe */
if(!s->budget--) { s->failed_pc=0x0c0856feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857b0u,2);
goto P_0c085700;
P_0c085700: /* original f346, guest PC 0x0c085700 */
if(!s->budget--) { s->failed_pc=0x0c085700u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c085702;
P_0c085702: /* original f34d, guest PC 0x0c085702 */
if(!s->budget--) { s->failed_pc=0x0c085702u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085704;
P_0c085704: /* original ff3a, guest PC 0x0c085704 */
if(!s->budget--) { s->failed_pc=0x0c085704u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c085706;
P_0c085706: /* original 2fe6, guest PC 0x0c085706 */
if(!s->budget--) { s->failed_pc=0x0c085706u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085708;
P_0c085708: /* original 2fd6, guest PC 0x0c085708 */
if(!s->budget--) { s->failed_pc=0x0c085708u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08570a;
P_0c08570a: /* original 63f3, guest PC 0x0c08570a */
if(!s->budget--) { s->failed_pc=0x0c08570au; return 0; }
r[3]=r[15];
goto P_0c08570c;
P_0c08570c: /* original 7308, guest PC 0x0c08570c */
if(!s->budget--) { s->failed_pc=0x0c08570cu; return 0; }
r[3]+=0x00000008u;
goto P_0c08570e;
P_0c08570e: /* original 2f36, guest PC 0x0c08570e */
if(!s->budget--) { s->failed_pc=0x0c08570eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085710;
P_0c085710: /* original 67f3, guest PC 0x0c085710 */
if(!s->budget--) { s->failed_pc=0x0c085710u; return 0; }
r[7]=r[15];
goto P_0c085712;
P_0c085712: /* original f6fc, guest PC 0x0c085712 */
if(!s->budget--) { s->failed_pc=0x0c085712u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c085714;
P_0c085714: /* original 7710, guest PC 0x0c085714 */
if(!s->budget--) { s->failed_pc=0x0c085714u; return 0; }
r[7]+=0x00000010u;
goto P_0c085716;
P_0c085716: /* original b08b, guest PC 0x0c085716 */
if(!s->budget--) { s->failed_pc=0x0c085716u; return 0; }
target=code_base|0x0c085830u; r[16]=code_base|0x0c08571au;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08571au) { target=s->pc; goto dispatch; }
goto P_0c08571a;
P_0c085718: /* original 64b3, guest PC 0x0c085718 */
if(!s->budget--) { s->failed_pc=0x0c085718u; return 0; }
r[4]=r[11];
goto P_0c08571a;
P_0c08571a: /* original 7d10, guest PC 0x0c08571a */
if(!s->budget--) { s->failed_pc=0x0c08571au; return 0; }
r[13]+=0x00000010u;
goto P_0c08571c;
P_0c08571c: /* original 7f0c, guest PC 0x0c08571c */
if(!s->budget--) { s->failed_pc=0x0c08571cu; return 0; }
r[15]+=0x0000000cu;
goto P_0c08571e;
P_0c08571e: /* original d32e, guest PC 0x0c08571e */
if(!s->budget--) { s->failed_pc=0x0c08571eu; return 0; }
r[3]=read(ram,0x0c0857d8u,4);
goto P_0c085720;
P_0c085720: /* original 6483, guest PC 0x0c085720 */
if(!s->budget--) { s->failed_pc=0x0c085720u; return 0; }
r[4]=r[8];
goto P_0c085722;
P_0c085722: /* original 7408, guest PC 0x0c085722 */
if(!s->budget--) { s->failed_pc=0x0c085722u; return 0; }
r[4]+=0x00000008u;
goto P_0c085724;
P_0c085724: /* original e004, guest PC 0x0c085724 */
if(!s->budget--) { s->failed_pc=0x0c085724u; return 0; }
r[0]=0x00000004u;
goto P_0c085726;
P_0c085726: /* original 6932, guest PC 0x0c085726 */
if(!s->budget--) { s->failed_pc=0x0c085726u; return 0; }
tmp=read(ram,r[3],4);
r[9]=tmp;
goto P_0c085728;
P_0c085728: /* original f546, guest PC 0x0c085728 */
if(!s->budget--) { s->failed_pc=0x0c085728u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c08572a;
P_0c08572a: /* original e061, guest PC 0x0c08572a */
if(!s->budget--) { s->failed_pc=0x0c08572au; return 0; }
r[0]=0x00000061u;
goto P_0c08572c;
P_0c08572c: /* original f448, guest PC 0x0c08572c */
if(!s->budget--) { s->failed_pc=0x0c08572cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c08572e;
P_0c08572e: /* original 049c, guest PC 0x0c08572e */
if(!s->budget--) { s->failed_pc=0x0c08572eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c085730;
P_0c085730: /* original 604c, guest PC 0x0c085730 */
if(!s->budget--) { s->failed_pc=0x0c085730u; return 0; }
r[0]=r[4]&255u;
goto P_0c085732;
P_0c085732: /* original 8809, guest PC 0x0c085732 */
if(!s->budget--) { s->failed_pc=0x0c085732u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c085734;
P_0c085734: /* original 8d1c, guest PC 0x0c085734 */
if(!s->budget--) { s->failed_pc=0x0c085734u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c085770; }
goto P_0c085738;
P_0c085736: /* original 6403, guest PC 0x0c085736 */
if(!s->budget--) { s->failed_pc=0x0c085736u; return 0; }
r[4]=r[0];
goto P_0c085738;
P_0c085738: /* original 6043, guest PC 0x0c085738 */
if(!s->budget--) { s->failed_pc=0x0c085738u; return 0; }
r[0]=r[4];
goto P_0c08573a;
P_0c08573a: /* original 8804, guest PC 0x0c08573a */
if(!s->budget--) { s->failed_pc=0x0c08573au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c08573c;
P_0c08573c: /* original 8918, guest PC 0x0c08573c */
if(!s->budget--) { s->failed_pc=0x0c08573cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085770; }
goto P_0c08573e;
P_0c08573e: /* original 6043, guest PC 0x0c08573e */
if(!s->budget--) { s->failed_pc=0x0c08573eu; return 0; }
r[0]=r[4];
goto P_0c085740;
P_0c085740: /* original 880b, guest PC 0x0c085740 */
if(!s->budget--) { s->failed_pc=0x0c085740u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c085742;
P_0c085742: /* original 8915, guest PC 0x0c085742 */
if(!s->budget--) { s->failed_pc=0x0c085742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c085770; }
goto P_0c085744;
P_0c085744: /* original 9033, guest PC 0x0c085744 */
if(!s->budget--) { s->failed_pc=0x0c085744u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c085746;
P_0c085746: /* original 66a3, guest PC 0x0c085746 */
if(!s->budget--) { s->failed_pc=0x0c085746u; return 0; }
r[6]=r[10];
goto P_0c085748;
P_0c085748: /* original 65c3, guest PC 0x0c085748 */
if(!s->budget--) { s->failed_pc=0x0c085748u; return 0; }
r[5]=r[12];
goto P_0c08574a;
P_0c08574a: /* original f396, guest PC 0x0c08574a */
if(!s->budget--) { s->failed_pc=0x0c08574au; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c08574c;
P_0c08574c: /* original e004, guest PC 0x0c08574c */
if(!s->budget--) { s->failed_pc=0x0c08574cu; return 0; }
r[0]=0x00000004u;
goto P_0c08574e;
P_0c08574e: /* original ff37, guest PC 0x0c08574e */
if(!s->budget--) { s->failed_pc=0x0c08574eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c085750;
P_0c085750: /* original 902e, guest PC 0x0c085750 */
if(!s->budget--) { s->failed_pc=0x0c085750u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857b0u,2);
goto P_0c085752;
P_0c085752: /* original f396, guest PC 0x0c085752 */
if(!s->budget--) { s->failed_pc=0x0c085752u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c085754;
P_0c085754: /* original f34d, guest PC 0x0c085754 */
if(!s->budget--) { s->failed_pc=0x0c085754u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085756;
P_0c085756: /* original ff3a, guest PC 0x0c085756 */
if(!s->budget--) { s->failed_pc=0x0c085756u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c085758;
P_0c085758: /* original 2fe6, guest PC 0x0c085758 */
if(!s->budget--) { s->failed_pc=0x0c085758u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08575a;
P_0c08575a: /* original 2fd6, guest PC 0x0c08575a */
if(!s->budget--) { s->failed_pc=0x0c08575au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08575c;
P_0c08575c: /* original 63f3, guest PC 0x0c08575c */
if(!s->budget--) { s->failed_pc=0x0c08575cu; return 0; }
r[3]=r[15];
goto P_0c08575e;
P_0c08575e: /* original 7308, guest PC 0x0c08575e */
if(!s->budget--) { s->failed_pc=0x0c08575eu; return 0; }
r[3]+=0x00000008u;
goto P_0c085760;
P_0c085760: /* original 2f36, guest PC 0x0c085760 */
if(!s->budget--) { s->failed_pc=0x0c085760u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085762;
P_0c085762: /* original 67f3, guest PC 0x0c085762 */
if(!s->budget--) { s->failed_pc=0x0c085762u; return 0; }
r[7]=r[15];
goto P_0c085764;
P_0c085764: /* original f6fc, guest PC 0x0c085764 */
if(!s->budget--) { s->failed_pc=0x0c085764u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c085766;
P_0c085766: /* original 7710, guest PC 0x0c085766 */
if(!s->budget--) { s->failed_pc=0x0c085766u; return 0; }
r[7]+=0x00000010u;
goto P_0c085768;
P_0c085768: /* original b062, guest PC 0x0c085768 */
if(!s->budget--) { s->failed_pc=0x0c085768u; return 0; }
target=code_base|0x0c085830u; r[16]=code_base|0x0c08576cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08576cu) { target=s->pc; goto dispatch; }
goto P_0c08576c;
P_0c08576a: /* original 64b3, guest PC 0x0c08576a */
if(!s->budget--) { s->failed_pc=0x0c08576au; return 0; }
r[4]=r[11];
goto P_0c08576c;
P_0c08576c: /* original 7d10, guest PC 0x0c08576c */
if(!s->budget--) { s->failed_pc=0x0c08576cu; return 0; }
r[13]+=0x00000010u;
goto P_0c08576e;
P_0c08576e: /* original 7f0c, guest PC 0x0c08576e */
if(!s->budget--) { s->failed_pc=0x0c08576eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c085770;
P_0c085770: /* original 901d, guest PC 0x0c085770 */
if(!s->budget--) { s->failed_pc=0x0c085770u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c085772;
P_0c085772: /* original 66ab, guest PC 0x0c085772 */
if(!s->budget--) { s->failed_pc=0x0c085772u; return 0; }
r[6]=0u-r[10];
goto P_0c085774;
P_0c085774: /* original 64bb, guest PC 0x0c085774 */
if(!s->budget--) { s->failed_pc=0x0c085774u; return 0; }
r[4]=0u-r[11];
goto P_0c085776;
P_0c085776: /* original f396, guest PC 0x0c085776 */
if(!s->budget--) { s->failed_pc=0x0c085776u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c085778;
P_0c085778: /* original e004, guest PC 0x0c085778 */
if(!s->budget--) { s->failed_pc=0x0c085778u; return 0; }
r[0]=0x00000004u;
goto P_0c08577a;
P_0c08577a: /* original 65cb, guest PC 0x0c08577a */
if(!s->budget--) { s->failed_pc=0x0c08577au; return 0; }
r[5]=0u-r[12];
goto P_0c08577c;
P_0c08577c: /* original ff37, guest PC 0x0c08577c */
if(!s->budget--) { s->failed_pc=0x0c08577cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08577e;
P_0c08577e: /* original 9017, guest PC 0x0c08577e */
if(!s->budget--) { s->failed_pc=0x0c08577eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857b0u,2);
goto P_0c085780;
P_0c085780: /* original f396, guest PC 0x0c085780 */
if(!s->budget--) { s->failed_pc=0x0c085780u; return 0; }
vf3_matrix_load(s,ram,3,r[9]+r[0]);
goto P_0c085782;
P_0c085782: /* original f34d, guest PC 0x0c085782 */
if(!s->budget--) { s->failed_pc=0x0c085782u; return 0; }
fr[3]^=0x80000000u;
goto P_0c085784;
P_0c085784: /* original ff3a, guest PC 0x0c085784 */
if(!s->budget--) { s->failed_pc=0x0c085784u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c085786;
P_0c085786: /* original d313, guest PC 0x0c085786 */
if(!s->budget--) { s->failed_pc=0x0c085786u; return 0; }
r[3]=read(ram,0x0c0857d4u,4);
goto P_0c085788;
P_0c085788: /* original 9011, guest PC 0x0c085788 */
if(!s->budget--) { s->failed_pc=0x0c085788u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0857aeu,2);
goto P_0c08578a;
P_0c08578a: /* original 6732, guest PC 0x0c08578a */
if(!s->budget--) { s->failed_pc=0x0c08578au; return 0; }
tmp=read(ram,r[3],4);
r[7]=tmp;
goto P_0c08578c;
P_0c08578c: /* original f576, guest PC 0x0c08578c */
if(!s->budget--) { s->failed_pc=0x0c08578cu; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c08578e;
P_0c08578e: /* original 7008, guest PC 0x0c08578e */
if(!s->budget--) { s->failed_pc=0x0c08578eu; return 0; }
r[0]+=0x00000008u;
goto P_0c085790;
P_0c085790: /* original f476, guest PC 0x0c085790 */
if(!s->budget--) { s->failed_pc=0x0c085790u; return 0; }
vf3_matrix_load(s,ram,4,r[7]+r[0]);
goto P_0c085792;
P_0c085792: /* original e004, guest PC 0x0c085792 */
if(!s->budget--) { s->failed_pc=0x0c085792u; return 0; }
r[0]=0x00000004u;
goto P_0c085794;
P_0c085794: /* original f3f6, guest PC 0x0c085794 */
if(!s->budget--) { s->failed_pc=0x0c085794u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c085796;
P_0c085796: /* original e004, guest PC 0x0c085796 */
if(!s->budget--) { s->failed_pc=0x0c085796u; return 0; }
r[0]=0x00000004u;
goto P_0c085798;
P_0c085798: /* original f44d, guest PC 0x0c085798 */
if(!s->budget--) { s->failed_pc=0x0c085798u; return 0; }
fr[4]^=0x80000000u;
goto P_0c08579a;
P_0c08579a: /* original f350, guest PC 0x0c08579a */
if(!s->budget--) { s->failed_pc=0x0c08579au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c08579c;
P_0c08579c: /* original ff37, guest PC 0x0c08579c */
if(!s->budget--) { s->failed_pc=0x0c08579cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08579e;
P_0c08579e: /* original f2f8, guest PC 0x0c08579e */
if(!s->budget--) { s->failed_pc=0x0c08579eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0857a0;
P_0c0857a0: /* original a01c, guest PC 0x0c0857a0 */
if(!s->budget--) { s->failed_pc=0x0c0857a0u; return 0; }
goto P_0c0857dc;
P_0c0857a2: /* original 0009, guest PC 0x0c0857a2 */
if(!s->budget--) { s->failed_pc=0x0c0857a2u; return 0; }
if(!vf3_matrix_family(0x0c0857a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0857a4u; return 0; } return 1;
P_0c0857dc: /* original f240, guest PC 0x0c0857dc */
if(!s->budget--) { s->failed_pc=0x0c0857dcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c0857de;
P_0c0857de: /* original c73f, guest PC 0x0c0857de */
if(!s->budget--) { s->failed_pc=0x0c0857deu; return 0; }
r[0]=code_base|0x000858dcu;
goto P_0c0857e0;
P_0c0857e0: /* original 6783, guest PC 0x0c0857e0 */
if(!s->budget--) { s->failed_pc=0x0c0857e0u; return 0; }
r[7]=r[8];
goto P_0c0857e2;
P_0c0857e2: /* original 7710, guest PC 0x0c0857e2 */
if(!s->budget--) { s->failed_pc=0x0c0857e2u; return 0; }
r[7]+=0x00000010u;
goto P_0c0857e4;
P_0c0857e4: /* original ff2a, guest PC 0x0c0857e4 */
if(!s->budget--) { s->failed_pc=0x0c0857e4u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0857e6;
P_0c0857e6: /* original f408, guest PC 0x0c0857e6 */
if(!s->budget--) { s->failed_pc=0x0c0857e6u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0857e8;
P_0c0857e8: /* original e004, guest PC 0x0c0857e8 */
if(!s->budget--) { s->failed_pc=0x0c0857e8u; return 0; }
r[0]=0x00000004u;
goto P_0c0857ea;
P_0c0857ea: /* original f242, guest PC 0x0c0857ea */
if(!s->budget--) { s->failed_pc=0x0c0857eau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c0857ec;
P_0c0857ec: /* original f342, guest PC 0x0c0857ec */
if(!s->budget--) { s->failed_pc=0x0c0857ecu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0857ee;
P_0c0857ee: /* original ff37, guest PC 0x0c0857ee */
if(!s->budget--) { s->failed_pc=0x0c0857eeu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0857f0;
P_0c0857f0: /* original e004, guest PC 0x0c0857f0 */
if(!s->budget--) { s->failed_pc=0x0c0857f0u; return 0; }
r[0]=0x00000004u;
goto P_0c0857f2;
P_0c0857f2: /* original ff2a, guest PC 0x0c0857f2 */
if(!s->budget--) { s->failed_pc=0x0c0857f2u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0857f4;
P_0c0857f4: /* original f576, guest PC 0x0c0857f4 */
if(!s->budget--) { s->failed_pc=0x0c0857f4u; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c0857f6;
P_0c0857f6: /* original f478, guest PC 0x0c0857f6 */
if(!s->budget--) { s->failed_pc=0x0c0857f6u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c0857f8;
P_0c0857f8: /* original 2fe6, guest PC 0x0c0857f8 */
if(!s->budget--) { s->failed_pc=0x0c0857f8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0857fa;
P_0c0857fa: /* original 2fd6, guest PC 0x0c0857fa */
if(!s->budget--) { s->failed_pc=0x0c0857fau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0857fc;
P_0c0857fc: /* original 62f3, guest PC 0x0c0857fc */
if(!s->budget--) { s->failed_pc=0x0c0857fcu; return 0; }
r[2]=r[15];
goto P_0c0857fe;
P_0c0857fe: /* original 7208, guest PC 0x0c0857fe */
if(!s->budget--) { s->failed_pc=0x0c0857feu; return 0; }
r[2]+=0x00000008u;
goto P_0c085800;
P_0c085800: /* original 2f26, guest PC 0x0c085800 */
if(!s->budget--) { s->failed_pc=0x0c085800u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085802;
P_0c085802: /* original 67f3, guest PC 0x0c085802 */
if(!s->budget--) { s->failed_pc=0x0c085802u; return 0; }
r[7]=r[15];
goto P_0c085804;
P_0c085804: /* original f6fc, guest PC 0x0c085804 */
if(!s->budget--) { s->failed_pc=0x0c085804u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c085806;
P_0c085806: /* original b013, guest PC 0x0c085806 */
if(!s->budget--) { s->failed_pc=0x0c085806u; return 0; }
target=code_base|0x0c085830u; r[16]=code_base|0x0c08580au;
r[7]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08580au) { target=s->pc; goto dispatch; }
goto P_0c08580a;
P_0c085808: /* original 7710, guest PC 0x0c085808 */
if(!s->budget--) { s->failed_pc=0x0c085808u; return 0; }
r[7]+=0x00000010u;
goto P_0c08580a;
P_0c08580a: /* original e3ff, guest PC 0x0c08580a */
if(!s->budget--) { s->failed_pc=0x0c08580au; return 0; }
r[3]=0xffffffffu;
goto P_0c08580c;
P_0c08580c: /* original 7d10, guest PC 0x0c08580c */
if(!s->budget--) { s->failed_pc=0x0c08580cu; return 0; }
r[13]+=0x00000010u;
goto P_0c08580e;
P_0c08580e: /* original 2d32, guest PC 0x0c08580e */
if(!s->budget--) { s->failed_pc=0x0c08580eu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c085810;
P_0c085810: /* original 7f0c, guest PC 0x0c085810 */
if(!s->budget--) { s->failed_pc=0x0c085810u; return 0; }
r[15]+=0x0000000cu;
goto P_0c085812;
P_0c085812: /* original b069, guest PC 0x0c085812 */
if(!s->budget--) { s->failed_pc=0x0c085812u; return 0; }
target=code_base|0x0c0858e8u; r[16]=code_base|0x0c085816u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085816u) { target=s->pc; goto dispatch; }
goto P_0c085816;
P_0c085814: /* original 64e3, guest PC 0x0c085814 */
if(!s->budget--) { s->failed_pc=0x0c085814u; return 0; }
r[4]=r[14];
goto P_0c085816;
P_0c085816: /* original b0f9, guest PC 0x0c085816 */
if(!s->budget--) { s->failed_pc=0x0c085816u; return 0; }
target=code_base|0x0c085a0cu; r[16]=code_base|0x0c08581au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08581au) { target=s->pc; goto dispatch; }
goto P_0c08581a;
P_0c085818: /* original 0009, guest PC 0x0c085818 */
if(!s->budget--) { s->failed_pc=0x0c085818u; return 0; }
goto P_0c08581a;
P_0c08581a: /* original 7f0c, guest PC 0x0c08581a */
if(!s->budget--) { s->failed_pc=0x0c08581au; return 0; }
r[15]+=0x0000000cu;
goto P_0c08581c;
P_0c08581c: /* original 4f26, guest PC 0x0c08581c */
if(!s->budget--) { s->failed_pc=0x0c08581cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08581e;
P_0c08581e: /* original fff9, guest PC 0x0c08581e */
if(!s->budget--) { s->failed_pc=0x0c08581eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c085820;
P_0c085820: /* original 68f6, guest PC 0x0c085820 */
if(!s->budget--) { s->failed_pc=0x0c085820u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085822;
P_0c085822: /* original 69f6, guest PC 0x0c085822 */
if(!s->budget--) { s->failed_pc=0x0c085822u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c085824;
P_0c085824: /* original 6af6, guest PC 0x0c085824 */
if(!s->budget--) { s->failed_pc=0x0c085824u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085826;
P_0c085826: /* original 6bf6, guest PC 0x0c085826 */
if(!s->budget--) { s->failed_pc=0x0c085826u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085828;
P_0c085828: /* original 6cf6, guest PC 0x0c085828 */
if(!s->budget--) { s->failed_pc=0x0c085828u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08582a;
P_0c08582a: /* original 6df6, guest PC 0x0c08582a */
if(!s->budget--) { s->failed_pc=0x0c08582au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08582c;
P_0c08582c: /* original 000b, guest PC 0x0c08582c */
if(!s->budget--) { s->failed_pc=0x0c08582cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08582e: /* original 6ef6, guest PC 0x0c08582e */
if(!s->budget--) { s->failed_pc=0x0c08582eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c085830u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
