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
int vf3_away_batch6_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05051au: goto P_0c05051a;
case 0x0c05051cu: goto P_0c05051c;
case 0x0c05051eu: goto P_0c05051e;
case 0x0c050520u: goto P_0c050520;
case 0x0c050522u: goto P_0c050522;
case 0x0c050524u: goto P_0c050524;
case 0x0c050526u: goto P_0c050526;
case 0x0c050528u: goto P_0c050528;
case 0x0c05052au: goto P_0c05052a;
case 0x0c05052cu: goto P_0c05052c;
case 0x0c05052eu: goto P_0c05052e;
case 0x0c050530u: goto P_0c050530;
case 0x0c050532u: goto P_0c050532;
case 0x0c050534u: goto P_0c050534;
case 0x0c050536u: goto P_0c050536;
case 0x0c050538u: goto P_0c050538;
case 0x0c05053au: goto P_0c05053a;
case 0x0c05053cu: goto P_0c05053c;
case 0x0c05053eu: goto P_0c05053e;
case 0x0c050540u: goto P_0c050540;
case 0x0c050542u: goto P_0c050542;
case 0x0c050544u: goto P_0c050544;
case 0x0c050546u: goto P_0c050546;
case 0x0c050568u: goto P_0c050568;
case 0x0c05056au: goto P_0c05056a;
case 0x0c05056cu: goto P_0c05056c;
case 0x0c05056eu: goto P_0c05056e;
case 0x0c050570u: goto P_0c050570;
case 0x0c050572u: goto P_0c050572;
case 0x0c050574u: goto P_0c050574;
case 0x0c050576u: goto P_0c050576;
case 0x0c050578u: goto P_0c050578;
case 0x0c05057au: goto P_0c05057a;
case 0x0c05057cu: goto P_0c05057c;
case 0x0c05057eu: goto P_0c05057e;
case 0x0c050580u: goto P_0c050580;
case 0x0c050582u: goto P_0c050582;
case 0x0c050584u: goto P_0c050584;
case 0x0c050586u: goto P_0c050586;
case 0x0c050588u: goto P_0c050588;
case 0x0c05058au: goto P_0c05058a;
case 0x0c05058cu: goto P_0c05058c;
case 0x0c05058eu: goto P_0c05058e;
case 0x0c050590u: goto P_0c050590;
case 0x0c050592u: goto P_0c050592;
case 0x0c050594u: goto P_0c050594;
case 0x0c050596u: goto P_0c050596;
case 0x0c050598u: goto P_0c050598;
case 0x0c05059au: goto P_0c05059a;
case 0x0c05059cu: goto P_0c05059c;
case 0x0c05059eu: goto P_0c05059e;
case 0x0c0505a0u: goto P_0c0505a0;
case 0x0c0505a2u: goto P_0c0505a2;
case 0x0c0505a4u: goto P_0c0505a4;
case 0x0c0505a6u: goto P_0c0505a6;
case 0x0c0505a8u: goto P_0c0505a8;
case 0x0c0505aau: goto P_0c0505aa;
case 0x0c0505acu: goto P_0c0505ac;
case 0x0c0505aeu: goto P_0c0505ae;
case 0x0c0505b0u: goto P_0c0505b0;
case 0x0c0505b2u: goto P_0c0505b2;
case 0x0c0505b4u: goto P_0c0505b4;
case 0x0c0505b6u: goto P_0c0505b6;
case 0x0c0505b8u: goto P_0c0505b8;
case 0x0c0505bau: goto P_0c0505ba;
case 0x0c0505bcu: goto P_0c0505bc;
case 0x0c0505beu: goto P_0c0505be;
case 0x0c0505c0u: goto P_0c0505c0;
case 0x0c0505c2u: goto P_0c0505c2;
case 0x0c0505c4u: goto P_0c0505c4;
case 0x0c0505c6u: goto P_0c0505c6;
case 0x0c0505c8u: goto P_0c0505c8;
case 0x0c0505cau: goto P_0c0505ca;
case 0x0c0505ccu: goto P_0c0505cc;
case 0x0c0505ceu: goto P_0c0505ce;
case 0x0c0505d0u: goto P_0c0505d0;
case 0x0c0505d2u: goto P_0c0505d2;
case 0x0c0505d4u: goto P_0c0505d4;
case 0x0c0505d6u: goto P_0c0505d6;
case 0x0c0505d8u: goto P_0c0505d8;
case 0x0c0505dau: goto P_0c0505da;
case 0x0c0505dcu: goto P_0c0505dc;
case 0x0c0505deu: goto P_0c0505de;
case 0x0c0505e0u: goto P_0c0505e0;
case 0x0c0505e2u: goto P_0c0505e2;
case 0x0c0505e4u: goto P_0c0505e4;
case 0x0c0505e6u: goto P_0c0505e6;
case 0x0c0505e8u: goto P_0c0505e8;
case 0x0c0505eau: goto P_0c0505ea;
case 0x0c0505ecu: goto P_0c0505ec;
case 0x0c0505eeu: goto P_0c0505ee;
case 0x0c0505f0u: goto P_0c0505f0;
case 0x0c0505f2u: goto P_0c0505f2;
case 0x0c0505f4u: goto P_0c0505f4;
case 0x0c0505f6u: goto P_0c0505f6;
case 0x0c0505f8u: goto P_0c0505f8;
case 0x0c0505fau: goto P_0c0505fa;
case 0x0c0505fcu: goto P_0c0505fc;
case 0x0c0505feu: goto P_0c0505fe;
case 0x0c050600u: goto P_0c050600;
case 0x0c050602u: goto P_0c050602;
case 0x0c050604u: goto P_0c050604;
case 0x0c050606u: goto P_0c050606;
case 0x0c050608u: goto P_0c050608;
case 0x0c05060au: goto P_0c05060a;
case 0x0c05060cu: goto P_0c05060c;
case 0x0c05060eu: goto P_0c05060e;
case 0x0c050610u: goto P_0c050610;
case 0x0c050612u: goto P_0c050612;
case 0x0c050614u: goto P_0c050614;
case 0x0c050616u: goto P_0c050616;
case 0x0c050618u: goto P_0c050618;
case 0x0c05061au: goto P_0c05061a;
case 0x0c05061cu: goto P_0c05061c;
case 0x0c05061eu: goto P_0c05061e;
case 0x0c050620u: goto P_0c050620;
case 0x0c050622u: goto P_0c050622;
case 0x0c050624u: goto P_0c050624;
case 0x0c050626u: goto P_0c050626;
case 0x0c050628u: goto P_0c050628;
case 0x0c05064cu: goto P_0c05064c;
case 0x0c05064eu: goto P_0c05064e;
case 0x0c050650u: goto P_0c050650;
case 0x0c050652u: goto P_0c050652;
case 0x0c050654u: goto P_0c050654;
case 0x0c050656u: goto P_0c050656;
case 0x0c050658u: goto P_0c050658;
case 0x0c05065au: goto P_0c05065a;
case 0x0c05065cu: goto P_0c05065c;
case 0x0c05065eu: goto P_0c05065e;
case 0x0c050660u: goto P_0c050660;
case 0x0c050662u: goto P_0c050662;
case 0x0c050664u: goto P_0c050664;
case 0x0c050666u: goto P_0c050666;
case 0x0c050668u: goto P_0c050668;
case 0x0c05066au: goto P_0c05066a;
case 0x0c05066cu: goto P_0c05066c;
case 0x0c05066eu: goto P_0c05066e;
case 0x0c050670u: goto P_0c050670;
case 0x0c050672u: goto P_0c050672;
case 0x0c050674u: goto P_0c050674;
case 0x0c050676u: goto P_0c050676;
case 0x0c050678u: goto P_0c050678;
case 0x0c05067au: goto P_0c05067a;
case 0x0c05067cu: goto P_0c05067c;
case 0x0c05067eu: goto P_0c05067e;
case 0x0c050680u: goto P_0c050680;
case 0x0c050682u: goto P_0c050682;
case 0x0c050684u: goto P_0c050684;
case 0x0c050686u: goto P_0c050686;
case 0x0c050688u: goto P_0c050688;
case 0x0c05068au: goto P_0c05068a;
case 0x0c05068cu: goto P_0c05068c;
case 0x0c05068eu: goto P_0c05068e;
case 0x0c050690u: goto P_0c050690;
case 0x0c050692u: goto P_0c050692;
case 0x0c050694u: goto P_0c050694;
case 0x0c050696u: goto P_0c050696;
case 0x0c050698u: goto P_0c050698;
case 0x0c05069au: goto P_0c05069a;
case 0x0c05069cu: goto P_0c05069c;
case 0x0c05069eu: goto P_0c05069e;
case 0x0c0506a0u: goto P_0c0506a0;
case 0x0c0506a2u: goto P_0c0506a2;
case 0x0c0506a4u: goto P_0c0506a4;
case 0x0c0506a6u: goto P_0c0506a6;
case 0x0c0506a8u: goto P_0c0506a8;
case 0x0c0506aau: goto P_0c0506aa;
case 0x0c0506acu: goto P_0c0506ac;
case 0x0c0506aeu: goto P_0c0506ae;
case 0x0c0506b0u: goto P_0c0506b0;
case 0x0c0506b2u: goto P_0c0506b2;
case 0x0c0506b4u: goto P_0c0506b4;
case 0x0c0506b6u: goto P_0c0506b6;
case 0x0c0506b8u: goto P_0c0506b8;
case 0x0c0506bau: goto P_0c0506ba;
case 0x0c0506bcu: goto P_0c0506bc;
case 0x0c0506beu: goto P_0c0506be;
case 0x0c0506c0u: goto P_0c0506c0;
case 0x0c0506c2u: goto P_0c0506c2;
case 0x0c0506c4u: goto P_0c0506c4;
case 0x0c0506c6u: goto P_0c0506c6;
case 0x0c0506c8u: goto P_0c0506c8;
case 0x0c0506e4u: goto P_0c0506e4;
case 0x0c0506e6u: goto P_0c0506e6;
case 0x0c0506e8u: goto P_0c0506e8;
case 0x0c0506eau: goto P_0c0506ea;
case 0x0c0506ecu: goto P_0c0506ec;
case 0x0c0506eeu: goto P_0c0506ee;
case 0x0c0506f0u: goto P_0c0506f0;
case 0x0c0506f2u: goto P_0c0506f2;
case 0x0c0506f4u: goto P_0c0506f4;
case 0x0c0506f6u: goto P_0c0506f6;
case 0x0c0506f8u: goto P_0c0506f8;
case 0x0c0506fau: goto P_0c0506fa;
case 0x0c0506fcu: goto P_0c0506fc;
case 0x0c0506feu: goto P_0c0506fe;
case 0x0c050700u: goto P_0c050700;
case 0x0c050702u: goto P_0c050702;
case 0x0c050704u: goto P_0c050704;
case 0x0c050706u: goto P_0c050706;
case 0x0c050708u: goto P_0c050708;
case 0x0c05070au: goto P_0c05070a;
case 0x0c05070cu: goto P_0c05070c;
case 0x0c05070eu: goto P_0c05070e;
case 0x0c050710u: goto P_0c050710;
case 0x0c050712u: goto P_0c050712;
case 0x0c050714u: goto P_0c050714;
case 0x0c050716u: goto P_0c050716;
case 0x0c050718u: goto P_0c050718;
case 0x0c05071au: goto P_0c05071a;
case 0x0c05071cu: goto P_0c05071c;
case 0x0c05071eu: goto P_0c05071e;
case 0x0c050720u: goto P_0c050720;
case 0x0c050722u: goto P_0c050722;
case 0x0c050724u: goto P_0c050724;
case 0x0c050726u: goto P_0c050726;
case 0x0c050728u: goto P_0c050728;
case 0x0c05072au: goto P_0c05072a;
case 0x0c05072cu: goto P_0c05072c;
case 0x0c05072eu: goto P_0c05072e;
case 0x0c050730u: goto P_0c050730;
case 0x0c050732u: goto P_0c050732;
case 0x0c050734u: goto P_0c050734;
case 0x0c050736u: goto P_0c050736;
case 0x0c050738u: goto P_0c050738;
case 0x0c05073au: goto P_0c05073a;
case 0x0c05073cu: goto P_0c05073c;
case 0x0c05073eu: goto P_0c05073e;
case 0x0c050740u: goto P_0c050740;
case 0x0c050742u: goto P_0c050742;
case 0x0c050744u: goto P_0c050744;
case 0x0c050746u: goto P_0c050746;
case 0x0c050748u: goto P_0c050748;
case 0x0c05074au: goto P_0c05074a;
case 0x0c05074cu: goto P_0c05074c;
case 0x0c05074eu: goto P_0c05074e;
case 0x0c050750u: goto P_0c050750;
case 0x0c050752u: goto P_0c050752;
case 0x0c050754u: goto P_0c050754;
case 0x0c050756u: goto P_0c050756;
case 0x0c050758u: goto P_0c050758;
case 0x0c05075au: goto P_0c05075a;
case 0x0c05075cu: goto P_0c05075c;
case 0x0c05075eu: goto P_0c05075e;
case 0x0c050760u: goto P_0c050760;
case 0x0c050762u: goto P_0c050762;
case 0x0c050764u: goto P_0c050764;
case 0x0c050766u: goto P_0c050766;
case 0x0c050768u: goto P_0c050768;
case 0x0c05076au: goto P_0c05076a;
case 0x0c05076cu: goto P_0c05076c;
case 0x0c05076eu: goto P_0c05076e;
case 0x0c050770u: goto P_0c050770;
case 0x0c050772u: goto P_0c050772;
case 0x0c050774u: goto P_0c050774;
case 0x0c050776u: goto P_0c050776;
case 0x0c050778u: goto P_0c050778;
case 0x0c05077au: goto P_0c05077a;
case 0x0c05077cu: goto P_0c05077c;
case 0x0c05077eu: goto P_0c05077e;
case 0x0c050780u: goto P_0c050780;
case 0x0c050782u: goto P_0c050782;
case 0x0c050784u: goto P_0c050784;
case 0x0c050786u: goto P_0c050786;
case 0x0c050788u: goto P_0c050788;
case 0x0c05078au: goto P_0c05078a;
case 0x0c05078cu: goto P_0c05078c;
case 0x0c05078eu: goto P_0c05078e;
case 0x0c050790u: goto P_0c050790;
case 0x0c050792u: goto P_0c050792;
case 0x0c050794u: goto P_0c050794;
case 0x0c050796u: goto P_0c050796;
case 0x0c050798u: goto P_0c050798;
case 0x0c05079au: goto P_0c05079a;
case 0x0c05079cu: goto P_0c05079c;
case 0x0c05079eu: goto P_0c05079e;
case 0x0c0507a0u: goto P_0c0507a0;
case 0x0c0507a2u: goto P_0c0507a2;
case 0x0c0507a4u: goto P_0c0507a4;
case 0x0c0507a6u: goto P_0c0507a6;
case 0x0c0507a8u: goto P_0c0507a8;
case 0x0c0507aau: goto P_0c0507aa;
case 0x0c0507acu: goto P_0c0507ac;
case 0x0c0507aeu: goto P_0c0507ae;
case 0x0c0507b0u: goto P_0c0507b0;
case 0x0c0507b2u: goto P_0c0507b2;
case 0x0c0507b4u: goto P_0c0507b4;
case 0x0c0507b6u: goto P_0c0507b6;
case 0x0c0507b8u: goto P_0c0507b8;
case 0x0c0507bau: goto P_0c0507ba;
case 0x0c0507bcu: goto P_0c0507bc;
case 0x0c0507beu: goto P_0c0507be;
case 0x0c0507c0u: goto P_0c0507c0;
case 0x0c0507c2u: goto P_0c0507c2;
case 0x0c0507c4u: goto P_0c0507c4;
case 0x0c0507c6u: goto P_0c0507c6;
case 0x0c0507c8u: goto P_0c0507c8;
case 0x0c0507cau: goto P_0c0507ca;
case 0x0c0507ccu: goto P_0c0507cc;
case 0x0c0507ceu: goto P_0c0507ce;
case 0x0c0507d0u: goto P_0c0507d0;
case 0x0c0507d2u: goto P_0c0507d2;
case 0x0c0507d4u: goto P_0c0507d4;
case 0x0c0507d6u: goto P_0c0507d6;
case 0x0c0507d8u: goto P_0c0507d8;
case 0x0c0507dau: goto P_0c0507da;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05051a: /* original 2fe6, guest PC 0x0c05051a */
if(!s->budget--) { s->failed_pc=0x0c05051au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05051c;
P_0c05051c: /* original 2fd6, guest PC 0x0c05051c */
if(!s->budget--) { s->failed_pc=0x0c05051cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05051e;
P_0c05051e: /* original 6d73, guest PC 0x0c05051e */
if(!s->budget--) { s->failed_pc=0x0c05051eu; return 0; }
r[13]=r[7];
goto P_0c050520;
P_0c050520: /* original 2fc6, guest PC 0x0c050520 */
if(!s->budget--) { s->failed_pc=0x0c050520u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050522;
P_0c050522: /* original 2dd8, guest PC 0x0c050522 */
if(!s->budget--) { s->failed_pc=0x0c050522u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c050524;
P_0c050524: /* original 2fb6, guest PC 0x0c050524 */
if(!s->budget--) { s->failed_pc=0x0c050524u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050526;
P_0c050526: /* original 6b43, guest PC 0x0c050526 */
if(!s->budget--) { s->failed_pc=0x0c050526u; return 0; }
r[11]=r[4];
goto P_0c050528;
P_0c050528: /* original 2fa6, guest PC 0x0c050528 */
if(!s->budget--) { s->failed_pc=0x0c050528u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05052a;
P_0c05052a: /* original 4f22, guest PC 0x0c05052a */
if(!s->budget--) { s->failed_pc=0x0c05052au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05052c;
P_0c05052c: /* original 4f12, guest PC 0x0c05052c */
if(!s->budget--) { s->failed_pc=0x0c05052cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c05052e;
P_0c05052e: /* original 7ff4, guest PC 0x0c05052e */
if(!s->budget--) { s->failed_pc=0x0c05052eu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c050530;
P_0c050530: /* original 1f51, guest PC 0x0c050530 */
if(!s->budget--) { s->failed_pc=0x0c050530u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c050532;
P_0c050532: /* original 8f1a, guest PC 0x0c050532 */
if(!s->budget--) { s->failed_pc=0x0c050532u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[6],4);
if(!cond) { goto P_0c05056a; }
goto P_0c050536;
P_0c050534: /* original 1f62, guest PC 0x0c050534 */
if(!s->budget--) { s->failed_pc=0x0c050534u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c050536;
P_0c050536: /* original d30b, guest PC 0x0c050536 */
if(!s->budget--) { s->failed_pc=0x0c050536u; return 0; }
r[3]=read(ram,0x0c050564u,4);
goto P_0c050538;
P_0c050538: /* original 55f1, guest PC 0x0c050538 */
if(!s->budget--) { s->failed_pc=0x0c050538u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c05053a;
P_0c05053a: /* original 430b, guest PC 0x0c05053a */
if(!s->budget--) { s->failed_pc=0x0c05053au; return 0; }
target=r[3];
r[16]=code_base|0x0c05053eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05053eu) { target=s->pc; goto dispatch; }
goto P_0c05053e;
P_0c05053c: /* original 64b3, guest PC 0x0c05053c */
if(!s->budget--) { s->failed_pc=0x0c05053cu; return 0; }
r[4]=r[11];
goto P_0c05053e;
P_0c05053e: /* original 6403, guest PC 0x0c05053e */
if(!s->budget--) { s->failed_pc=0x0c05053eu; return 0; }
r[4]=r[0];
goto P_0c050540;
P_0c050540: /* original 4411, guest PC 0x0c050540 */
if(!s->budget--) { s->failed_pc=0x0c050540u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c050542;
P_0c050542: /* original 8911, guest PC 0x0c050542 */
if(!s->budget--) { s->failed_pc=0x0c050542u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c050568; }
goto P_0c050544;
P_0c050544: /* original a039, guest PC 0x0c050544 */
if(!s->budget--) { s->failed_pc=0x0c050544u; return 0; }
r[0]=r[4];
goto P_0c0505ba;
P_0c050546: /* original 6043, guest PC 0x0c050546 */
if(!s->budget--) { s->failed_pc=0x0c050546u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c050548u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c050548u; return 0; } return 1;
P_0c050568: /* original 6d43, guest PC 0x0c050568 */
if(!s->budget--) { s->failed_pc=0x0c050568u; return 0; }
r[13]=r[4];
goto P_0c05056a;
P_0c05056a: /* original d331, guest PC 0x0c05056a */
if(!s->budget--) { s->failed_pc=0x0c05056au; return 0; }
r[3]=read(ram,0x0c050630u,4);
goto P_0c05056c;
P_0c05056c: /* original 66f3, guest PC 0x0c05056c */
if(!s->budget--) { s->failed_pc=0x0c05056cu; return 0; }
r[6]=r[15];
goto P_0c05056e;
P_0c05056e: /* original 55f1, guest PC 0x0c05056e */
if(!s->budget--) { s->failed_pc=0x0c05056eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c050570;
P_0c050570: /* original 430b, guest PC 0x0c050570 */
if(!s->budget--) { s->failed_pc=0x0c050570u; return 0; }
target=r[3];
r[16]=code_base|0x0c050574u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050574u) { target=s->pc; goto dispatch; }
goto P_0c050574;
P_0c050572: /* original 64b3, guest PC 0x0c050572 */
if(!s->budget--) { s->failed_pc=0x0c050572u; return 0; }
r[4]=r[11];
goto P_0c050574;
P_0c050574: /* original 6e03, guest PC 0x0c050574 */
if(!s->budget--) { s->failed_pc=0x0c050574u; return 0; }
r[14]=r[0];
goto P_0c050576;
P_0c050576: /* original 4e11, guest PC 0x0c050576 */
if(!s->budget--) { s->failed_pc=0x0c050576u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050578;
P_0c050578: /* original 8b1e, guest PC 0x0c050578 */
if(!s->budget--) { s->failed_pc=0x0c050578u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0505b8; }
goto P_0c05057a;
P_0c05057a: /* original 9456, guest PC 0x0c05057a */
if(!s->budget--) { s->failed_pc=0x0c05057au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05062au,2);
goto P_0c05057c;
P_0c05057c: /* original e201, guest PC 0x0c05057c */
if(!s->budget--) { s->failed_pc=0x0c05057cu; return 0; }
r[2]=0x00000001u;
goto P_0c05057e;
P_0c05057e: /* original d32d, guest PC 0x0c05057e */
if(!s->budget--) { s->failed_pc=0x0c05057eu; return 0; }
r[3]=read(ram,0x0c050634u,4);
goto P_0c050580;
P_0c050580: /* original 2b4f, guest PC 0x0c050580 */
if(!s->budget--) { s->failed_pc=0x0c050580u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[11]*(int32_t)(int16_t)r[4]);
goto P_0c050582;
P_0c050582: /* original eb00, guest PC 0x0c050582 */
if(!s->budget--) { s->failed_pc=0x0c050582u; return 0; }
r[11]=0x00000000u;
goto P_0c050584;
P_0c050584: /* original 5cf2, guest PC 0x0c050584 */
if(!s->budget--) { s->failed_pc=0x0c050584u; return 0; }
r[12]=read(ram,r[15]+8,4);
goto P_0c050586;
P_0c050586: /* original 61b3, guest PC 0x0c050586 */
if(!s->budget--) { s->failed_pc=0x0c050586u; return 0; }
r[1]=r[11];
goto P_0c050588;
P_0c050588: /* original 31d2, guest PC 0x0c050588 */
if(!s->budget--) { s->failed_pc=0x0c050588u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[13])!=0);
goto P_0c05058a;
P_0c05058a: /* original 041a, guest PC 0x0c05058a */
if(!s->budget--) { s->failed_pc=0x0c05058au; return 0; }
r[4]=r[19];
goto P_0c05058c;
P_0c05058c: /* original 644f, guest PC 0x0c05058c */
if(!s->budget--) { s->failed_pc=0x0c05058cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c05058e;
P_0c05058e: /* original 343c, guest PC 0x0c05058e */
if(!s->budget--) { s->failed_pc=0x0c05058eu; return 0; }
r[4]+=r[3];
goto P_0c050590;
P_0c050590: /* original 142c, guest PC 0x0c050590 */
if(!s->budget--) { s->failed_pc=0x0c050590u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c050592;
P_0c050592: /* original 8d0c, guest PC 0x0c050592 */
if(!s->budget--) { s->failed_pc=0x0c050592u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+52,r[13],4);
if(cond) { goto P_0c0505ae; }
goto P_0c050596;
P_0c050594: /* original 14dd, guest PC 0x0c050594 */
if(!s->budget--) { s->failed_pc=0x0c050594u; return 0; }
write(ram,r[4]+52,r[13],4);
goto P_0c050596;
P_0c050596: /* original 9a49, guest PC 0x0c050596 */
if(!s->budget--) { s->failed_pc=0x0c050596u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05062cu,2);
goto P_0c050598;
P_0c050598: /* original d327, guest PC 0x0c050598 */
if(!s->budget--) { s->failed_pc=0x0c050598u; return 0; }
r[3]=read(ram,0x0c050638u,4);
goto P_0c05059a;
P_0c05059a: /* original 65c3, guest PC 0x0c05059a */
if(!s->budget--) { s->failed_pc=0x0c05059au; return 0; }
r[5]=r[12];
goto P_0c05059c;
P_0c05059c: /* original 430b, guest PC 0x0c05059c */
if(!s->budget--) { s->failed_pc=0x0c05059cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0505a0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0505a0u) { target=s->pc; goto dispatch; }
goto P_0c0505a0;
P_0c05059e: /* original 64f2, guest PC 0x0c05059e */
if(!s->budget--) { s->failed_pc=0x0c05059eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0505a0;
P_0c0505a0: /* original 6e03, guest PC 0x0c0505a0 */
if(!s->budget--) { s->failed_pc=0x0c0505a0u; return 0; }
r[14]=r[0];
goto P_0c0505a2;
P_0c0505a2: /* original 4e11, guest PC 0x0c0505a2 */
if(!s->budget--) { s->failed_pc=0x0c0505a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0505a4;
P_0c0505a4: /* original 8b04, guest PC 0x0c0505a4 */
if(!s->budget--) { s->failed_pc=0x0c0505a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0505b0; }
goto P_0c0505a6;
P_0c0505a6: /* original 7b01, guest PC 0x0c0505a6 */
if(!s->budget--) { s->failed_pc=0x0c0505a6u; return 0; }
r[11]+=0x00000001u;
goto P_0c0505a8;
P_0c0505a8: /* original 3bd2, guest PC 0x0c0505a8 */
if(!s->budget--) { s->failed_pc=0x0c0505a8u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[13])!=0);
goto P_0c0505aa;
P_0c0505aa: /* original 8ff5, guest PC 0x0c0505aa */
if(!s->budget--) { s->failed_pc=0x0c0505aau; return 0; }
cond=r[17]&1u;
r[12]+=r[10];
if(!cond) { goto P_0c050598; }
goto P_0c0505ae;
P_0c0505ac: /* original 3cac, guest PC 0x0c0505ac */
if(!s->budget--) { s->failed_pc=0x0c0505acu; return 0; }
r[12]+=r[10];
goto P_0c0505ae;
P_0c0505ae: /* original ee00, guest PC 0x0c0505ae */
if(!s->budget--) { s->failed_pc=0x0c0505aeu; return 0; }
r[14]=0x00000000u;
goto P_0c0505b0;
P_0c0505b0: /* original d322, guest PC 0x0c0505b0 */
if(!s->budget--) { s->failed_pc=0x0c0505b0u; return 0; }
r[3]=read(ram,0x0c05063cu,4);
goto P_0c0505b2;
P_0c0505b2: /* original e500, guest PC 0x0c0505b2 */
if(!s->budget--) { s->failed_pc=0x0c0505b2u; return 0; }
r[5]=0x00000000u;
goto P_0c0505b4;
P_0c0505b4: /* original 430b, guest PC 0x0c0505b4 */
if(!s->budget--) { s->failed_pc=0x0c0505b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0505b8u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0505b8u) { target=s->pc; goto dispatch; }
goto P_0c0505b8;
P_0c0505b6: /* original 64f2, guest PC 0x0c0505b6 */
if(!s->budget--) { s->failed_pc=0x0c0505b6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0505b8;
P_0c0505b8: /* original 60e3, guest PC 0x0c0505b8 */
if(!s->budget--) { s->failed_pc=0x0c0505b8u; return 0; }
r[0]=r[14];
goto P_0c0505ba;
P_0c0505ba: /* original 7f0c, guest PC 0x0c0505ba */
if(!s->budget--) { s->failed_pc=0x0c0505bau; return 0; }
r[15]+=0x0000000cu;
goto P_0c0505bc;
P_0c0505bc: /* original 4f16, guest PC 0x0c0505bc */
if(!s->budget--) { s->failed_pc=0x0c0505bcu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0505be;
P_0c0505be: /* original 4f26, guest PC 0x0c0505be */
if(!s->budget--) { s->failed_pc=0x0c0505beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0505c0;
P_0c0505c0: /* original 6af6, guest PC 0x0c0505c0 */
if(!s->budget--) { s->failed_pc=0x0c0505c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0505c2;
P_0c0505c2: /* original 6bf6, guest PC 0x0c0505c2 */
if(!s->budget--) { s->failed_pc=0x0c0505c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0505c4;
P_0c0505c4: /* original 6cf6, guest PC 0x0c0505c4 */
if(!s->budget--) { s->failed_pc=0x0c0505c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0505c6;
P_0c0505c6: /* original 6df6, guest PC 0x0c0505c6 */
if(!s->budget--) { s->failed_pc=0x0c0505c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0505c8;
P_0c0505c8: /* original 000b, guest PC 0x0c0505c8 */
if(!s->budget--) { s->failed_pc=0x0c0505c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0505ca: /* original 6ef6, guest PC 0x0c0505ca */
if(!s->budget--) { s->failed_pc=0x0c0505cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0505cc;
P_0c0505cc: /* original 2fe6, guest PC 0x0c0505cc */
if(!s->budget--) { s->failed_pc=0x0c0505ccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0505ce;
P_0c0505ce: /* original 2fd6, guest PC 0x0c0505ce */
if(!s->budget--) { s->failed_pc=0x0c0505ceu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0505d0;
P_0c0505d0: /* original 6d73, guest PC 0x0c0505d0 */
if(!s->budget--) { s->failed_pc=0x0c0505d0u; return 0; }
r[13]=r[7];
goto P_0c0505d2;
P_0c0505d2: /* original 2fc6, guest PC 0x0c0505d2 */
if(!s->budget--) { s->failed_pc=0x0c0505d2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0505d4;
P_0c0505d4: /* original 6c43, guest PC 0x0c0505d4 */
if(!s->budget--) { s->failed_pc=0x0c0505d4u; return 0; }
r[12]=r[4];
goto P_0c0505d6;
P_0c0505d6: /* original 2fb6, guest PC 0x0c0505d6 */
if(!s->budget--) { s->failed_pc=0x0c0505d6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0505d8;
P_0c0505d8: /* original 6b53, guest PC 0x0c0505d8 */
if(!s->budget--) { s->failed_pc=0x0c0505d8u; return 0; }
r[11]=r[5];
goto P_0c0505da;
P_0c0505da: /* original 2fa6, guest PC 0x0c0505da */
if(!s->budget--) { s->failed_pc=0x0c0505dau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0505dc;
P_0c0505dc: /* original e500, guest PC 0x0c0505dc */
if(!s->budget--) { s->failed_pc=0x0c0505dcu; return 0; }
r[5]=0x00000000u;
goto P_0c0505de;
P_0c0505de: /* original 4f22, guest PC 0x0c0505de */
if(!s->budget--) { s->failed_pc=0x0c0505deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0505e0;
P_0c0505e0: /* original 4f12, guest PC 0x0c0505e0 */
if(!s->budget--) { s->failed_pc=0x0c0505e0u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0505e2;
P_0c0505e2: /* original 7ff8, guest PC 0x0c0505e2 */
if(!s->budget--) { s->failed_pc=0x0c0505e2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0505e4;
P_0c0505e4: /* original 1f61, guest PC 0x0c0505e4 */
if(!s->budget--) { s->failed_pc=0x0c0505e4u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c0505e6;
P_0c0505e6: /* original 5afa, guest PC 0x0c0505e6 */
if(!s->budget--) { s->failed_pc=0x0c0505e6u; return 0; }
r[10]=read(ram,r[15]+40,4);
goto P_0c0505e8;
P_0c0505e8: /* original d315, guest PC 0x0c0505e8 */
if(!s->budget--) { s->failed_pc=0x0c0505e8u; return 0; }
r[3]=read(ram,0x0c050640u,4);
goto P_0c0505ea;
P_0c0505ea: /* original 430b, guest PC 0x0c0505ea */
if(!s->budget--) { s->failed_pc=0x0c0505eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0505eeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0505eeu) { target=s->pc; goto dispatch; }
goto P_0c0505ee;
P_0c0505ec: /* original 64c3, guest PC 0x0c0505ec */
if(!s->budget--) { s->failed_pc=0x0c0505ecu; return 0; }
r[4]=r[12];
goto P_0c0505ee;
P_0c0505ee: /* original d215, guest PC 0x0c0505ee */
if(!s->budget--) { s->failed_pc=0x0c0505eeu; return 0; }
r[2]=read(ram,0x0c050644u,4);
goto P_0c0505f0;
P_0c0505f0: /* original 65b3, guest PC 0x0c0505f0 */
if(!s->budget--) { s->failed_pc=0x0c0505f0u; return 0; }
r[5]=r[11];
goto P_0c0505f2;
P_0c0505f2: /* original 6e03, guest PC 0x0c0505f2 */
if(!s->budget--) { s->failed_pc=0x0c0505f2u; return 0; }
r[14]=r[0];
goto P_0c0505f4;
P_0c0505f4: /* original 420b, guest PC 0x0c0505f4 */
if(!s->budget--) { s->failed_pc=0x0c0505f4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0505f8u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0505f8u) { target=s->pc; goto dispatch; }
goto P_0c0505f8;
P_0c0505f6: /* original 64c3, guest PC 0x0c0505f6 */
if(!s->budget--) { s->failed_pc=0x0c0505f6u; return 0; }
r[4]=r[12];
goto P_0c0505f8;
P_0c0505f8: /* original 6403, guest PC 0x0c0505f8 */
if(!s->budget--) { s->failed_pc=0x0c0505f8u; return 0; }
r[4]=r[0];
goto P_0c0505fa;
P_0c0505fa: /* original 4415, guest PC 0x0c0505fa */
if(!s->budget--) { s->failed_pc=0x0c0505fau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0505fc;
P_0c0505fc: /* original 8b00, guest PC 0x0c0505fc */
if(!s->budget--) { s->failed_pc=0x0c0505fcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c050600; }
goto P_0c0505fe;
P_0c0505fe: /* original 3e4c, guest PC 0x0c0505fe */
if(!s->budget--) { s->failed_pc=0x0c0505feu; return 0; }
r[14]+=r[4];
goto P_0c050600;
P_0c050600: /* original 4e11, guest PC 0x0c050600 */
if(!s->budget--) { s->failed_pc=0x0c050600u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050602;
P_0c050602: /* original 8b58, guest PC 0x0c050602 */
if(!s->budget--) { s->failed_pc=0x0c050602u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0506b6; }
goto P_0c050604;
P_0c050604: /* original 3ed2, guest PC 0x0c050604 */
if(!s->budget--) { s->failed_pc=0x0c050604u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[13])!=0);
goto P_0c050606;
P_0c050606: /* original 8902, guest PC 0x0c050606 */
if(!s->budget--) { s->failed_pc=0x0c050606u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05060e; }
goto P_0c050608;
P_0c050608: /* original 9011, guest PC 0x0c050608 */
if(!s->budget--) { s->failed_pc=0x0c050608u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05062eu,2);
goto P_0c05060a;
P_0c05060a: /* original a055, guest PC 0x0c05060a */
if(!s->budget--) { s->failed_pc=0x0c05060au; return 0; }
goto P_0c0506b8;
P_0c05060c: /* original 0009, guest PC 0x0c05060c */
if(!s->budget--) { s->failed_pc=0x0c05060cu; return 0; }
goto P_0c05060e;
P_0c05060e: /* original d40e, guest PC 0x0c05060e */
if(!s->budget--) { s->failed_pc=0x0c05060eu; return 0; }
r[4]=read(ram,0x0c050648u,4);
goto P_0c050610;
P_0c050610: /* original 24a9, guest PC 0x0c050610 */
if(!s->budget--) { s->failed_pc=0x0c050610u; return 0; }
r[4]&=r[10];
goto P_0c050612;
P_0c050612: /* original 2448, guest PC 0x0c050612 */
if(!s->budget--) { s->failed_pc=0x0c050612u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c050614;
P_0c050614: /* original 891a, guest PC 0x0c050614 */
if(!s->budget--) { s->failed_pc=0x0c050614u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05064c; }
goto P_0c050616;
P_0c050616: /* original 2fa6, guest PC 0x0c050616 */
if(!s->budget--) { s->failed_pc=0x0c050616u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050618;
P_0c050618: /* original 65b3, guest PC 0x0c050618 */
if(!s->budget--) { s->failed_pc=0x0c050618u; return 0; }
r[5]=r[11];
goto P_0c05061a;
P_0c05061a: /* original 53fa, guest PC 0x0c05061a */
if(!s->budget--) { s->failed_pc=0x0c05061au; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c05061c;
P_0c05061c: /* original 67d3, guest PC 0x0c05061c */
if(!s->budget--) { s->failed_pc=0x0c05061cu; return 0; }
r[7]=r[13];
goto P_0c05061e;
P_0c05061e: /* original 2f36, guest PC 0x0c05061e */
if(!s->budget--) { s->failed_pc=0x0c05061eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c050620;
P_0c050620: /* original 56f3, guest PC 0x0c050620 */
if(!s->budget--) { s->failed_pc=0x0c050620u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c050622;
P_0c050622: /* original b05f, guest PC 0x0c050622 */
if(!s->budget--) { s->failed_pc=0x0c050622u; return 0; }
target=code_base|0x0c0506e4u; r[16]=code_base|0x0c050626u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050626u) { target=s->pc; goto dispatch; }
goto P_0c050626;
P_0c050624: /* original 64c3, guest PC 0x0c050624 */
if(!s->budget--) { s->failed_pc=0x0c050624u; return 0; }
r[4]=r[12];
goto P_0c050626;
P_0c050626: /* original a047, guest PC 0x0c050626 */
if(!s->budget--) { s->failed_pc=0x0c050626u; return 0; }
r[15]+=0x00000008u;
goto P_0c0506b8;
P_0c050628: /* original 7f08, guest PC 0x0c050628 */
if(!s->budget--) { s->failed_pc=0x0c050628u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c05062au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05062au; return 0; } return 1;
P_0c05064c: /* original d320, guest PC 0x0c05064c */
if(!s->budget--) { s->failed_pc=0x0c05064cu; return 0; }
r[3]=read(ram,0x0c0506d0u,4);
goto P_0c05064e;
P_0c05064e: /* original 67f3, guest PC 0x0c05064e */
if(!s->budget--) { s->failed_pc=0x0c05064eu; return 0; }
r[7]=r[15];
goto P_0c050650;
P_0c050650: /* original 56f9, guest PC 0x0c050650 */
if(!s->budget--) { s->failed_pc=0x0c050650u; return 0; }
r[6]=read(ram,r[15]+36,4);
goto P_0c050652;
P_0c050652: /* original 65b3, guest PC 0x0c050652 */
if(!s->budget--) { s->failed_pc=0x0c050652u; return 0; }
r[5]=r[11];
goto P_0c050654;
P_0c050654: /* original 430b, guest PC 0x0c050654 */
if(!s->budget--) { s->failed_pc=0x0c050654u; return 0; }
target=r[3];
r[16]=code_base|0x0c050658u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050658u) { target=s->pc; goto dispatch; }
goto P_0c050658;
P_0c050656: /* original 64c3, guest PC 0x0c050656 */
if(!s->budget--) { s->failed_pc=0x0c050656u; return 0; }
r[4]=r[12];
goto P_0c050658;
P_0c050658: /* original 6e03, guest PC 0x0c050658 */
if(!s->budget--) { s->failed_pc=0x0c050658u; return 0; }
r[14]=r[0];
goto P_0c05065a;
P_0c05065a: /* original 4e11, guest PC 0x0c05065a */
if(!s->budget--) { s->failed_pc=0x0c05065au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c05065c;
P_0c05065c: /* original 8b2b, guest PC 0x0c05065c */
if(!s->budget--) { s->failed_pc=0x0c05065cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0506b6; }
goto P_0c05065e;
P_0c05065e: /* original 62f2, guest PC 0x0c05065e */
if(!s->budget--) { s->failed_pc=0x0c05065eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c050660;
P_0c050660: /* original 60a3, guest PC 0x0c050660 */
if(!s->budget--) { s->failed_pc=0x0c050660u; return 0; }
r[0]=r[10];
goto P_0c050662;
P_0c050662: /* original 8021, guest PC 0x0c050662 */
if(!s->budget--) { s->failed_pc=0x0c050662u; return 0; }
write(ram,r[2]+1,r[0],1);
goto P_0c050664;
P_0c050664: /* original e201, guest PC 0x0c050664 */
if(!s->budget--) { s->failed_pc=0x0c050664u; return 0; }
r[2]=0x00000001u;
goto P_0c050666;
P_0c050666: /* original 9430, guest PC 0x0c050666 */
if(!s->budget--) { s->failed_pc=0x0c050666u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0506cau,2);
goto P_0c050668;
P_0c050668: /* original d31a, guest PC 0x0c050668 */
if(!s->budget--) { s->failed_pc=0x0c050668u; return 0; }
r[3]=read(ram,0x0c0506d4u,4);
goto P_0c05066a;
P_0c05066a: /* original 2c4f, guest PC 0x0c05066a */
if(!s->budget--) { s->failed_pc=0x0c05066au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[12]*(int32_t)(int16_t)r[4]);
goto P_0c05066c;
P_0c05066c: /* original ec00, guest PC 0x0c05066c */
if(!s->budget--) { s->failed_pc=0x0c05066cu; return 0; }
r[12]=0x00000000u;
goto P_0c05066e;
P_0c05066e: /* original 5bf1, guest PC 0x0c05066e */
if(!s->budget--) { s->failed_pc=0x0c05066eu; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c050670;
P_0c050670: /* original 041a, guest PC 0x0c050670 */
if(!s->budget--) { s->failed_pc=0x0c050670u; return 0; }
r[4]=r[19];
goto P_0c050672;
P_0c050672: /* original 644f, guest PC 0x0c050672 */
if(!s->budget--) { s->failed_pc=0x0c050672u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c050674;
P_0c050674: /* original 343c, guest PC 0x0c050674 */
if(!s->budget--) { s->failed_pc=0x0c050674u; return 0; }
r[4]+=r[3];
goto P_0c050676;
P_0c050676: /* original 142c, guest PC 0x0c050676 */
if(!s->budget--) { s->failed_pc=0x0c050676u; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c050678;
P_0c050678: /* original 5141, guest PC 0x0c050678 */
if(!s->budget--) { s->failed_pc=0x0c050678u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c05067a;
P_0c05067a: /* original d017, guest PC 0x0c05067a */
if(!s->budget--) { s->failed_pc=0x0c05067au; return 0; }
r[0]=read(ram,0x0c0506d8u,4);
goto P_0c05067c;
P_0c05067c: /* original 6213, guest PC 0x0c05067c */
if(!s->budget--) { s->failed_pc=0x0c05067cu; return 0; }
r[2]=r[1];
goto P_0c05067e;
P_0c05067e: /* original 4108, guest PC 0x0c05067e */
if(!s->budget--) { s->failed_pc=0x0c05067eu; return 0; }
r[1]<<=2;
goto P_0c050680;
P_0c050680: /* original 312c, guest PC 0x0c050680 */
if(!s->budget--) { s->failed_pc=0x0c050680u; return 0; }
r[1]+=r[2];
goto P_0c050682;
P_0c050682: /* original 62c3, guest PC 0x0c050682 */
if(!s->budget--) { s->failed_pc=0x0c050682u; return 0; }
r[2]=r[12];
goto P_0c050684;
P_0c050684: /* original 4108, guest PC 0x0c050684 */
if(!s->budget--) { s->failed_pc=0x0c050684u; return 0; }
r[1]<<=2;
goto P_0c050686;
P_0c050686: /* original 32d2, guest PC 0x0c050686 */
if(!s->budget--) { s->failed_pc=0x0c050686u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[13])!=0);
goto P_0c050688;
P_0c050688: /* original 4108, guest PC 0x0c050688 */
if(!s->budget--) { s->failed_pc=0x0c050688u; return 0; }
r[1]<<=2;
goto P_0c05068a;
P_0c05068a: /* original 611f, guest PC 0x0c05068a */
if(!s->budget--) { s->failed_pc=0x0c05068au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c05068c;
P_0c05068c: /* original 001e, guest PC 0x0c05068c */
if(!s->budget--) { s->failed_pc=0x0c05068cu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c05068e;
P_0c05068e: /* original 30dc, guest PC 0x0c05068e */
if(!s->budget--) { s->failed_pc=0x0c05068eu; return 0; }
r[0]+=r[13];
goto P_0c050690;
P_0c050690: /* original 8d0c, guest PC 0x0c050690 */
if(!s->budget--) { s->failed_pc=0x0c050690u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+52,r[0],4);
if(cond) { goto P_0c0506ac; }
goto P_0c050694;
P_0c050692: /* original 140d, guest PC 0x0c050692 */
if(!s->budget--) { s->failed_pc=0x0c050692u; return 0; }
write(ram,r[4]+52,r[0],4);
goto P_0c050694;
P_0c050694: /* original 9a1a, guest PC 0x0c050694 */
if(!s->budget--) { s->failed_pc=0x0c050694u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0506ccu,2);
goto P_0c050696;
P_0c050696: /* original d311, guest PC 0x0c050696 */
if(!s->budget--) { s->failed_pc=0x0c050696u; return 0; }
r[3]=read(ram,0x0c0506dcu,4);
goto P_0c050698;
P_0c050698: /* original 65b3, guest PC 0x0c050698 */
if(!s->budget--) { s->failed_pc=0x0c050698u; return 0; }
r[5]=r[11];
goto P_0c05069a;
P_0c05069a: /* original 430b, guest PC 0x0c05069a */
if(!s->budget--) { s->failed_pc=0x0c05069au; return 0; }
target=r[3];
r[16]=code_base|0x0c05069eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05069eu) { target=s->pc; goto dispatch; }
goto P_0c05069e;
P_0c05069c: /* original 64f2, guest PC 0x0c05069c */
if(!s->budget--) { s->failed_pc=0x0c05069cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05069e;
P_0c05069e: /* original 6e03, guest PC 0x0c05069e */
if(!s->budget--) { s->failed_pc=0x0c05069eu; return 0; }
r[14]=r[0];
goto P_0c0506a0;
P_0c0506a0: /* original 4e11, guest PC 0x0c0506a0 */
if(!s->budget--) { s->failed_pc=0x0c0506a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0506a2;
P_0c0506a2: /* original 8b04, guest PC 0x0c0506a2 */
if(!s->budget--) { s->failed_pc=0x0c0506a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0506ae; }
goto P_0c0506a4;
P_0c0506a4: /* original 7c01, guest PC 0x0c0506a4 */
if(!s->budget--) { s->failed_pc=0x0c0506a4u; return 0; }
r[12]+=0x00000001u;
goto P_0c0506a6;
P_0c0506a6: /* original 3cd2, guest PC 0x0c0506a6 */
if(!s->budget--) { s->failed_pc=0x0c0506a6u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>=r[13])!=0);
goto P_0c0506a8;
P_0c0506a8: /* original 8ff5, guest PC 0x0c0506a8 */
if(!s->budget--) { s->failed_pc=0x0c0506a8u; return 0; }
cond=r[17]&1u;
r[11]+=r[10];
if(!cond) { goto P_0c050696; }
goto P_0c0506ac;
P_0c0506aa: /* original 3bac, guest PC 0x0c0506aa */
if(!s->budget--) { s->failed_pc=0x0c0506aau; return 0; }
r[11]+=r[10];
goto P_0c0506ac;
P_0c0506ac: /* original ee00, guest PC 0x0c0506ac */
if(!s->budget--) { s->failed_pc=0x0c0506acu; return 0; }
r[14]=0x00000000u;
goto P_0c0506ae;
P_0c0506ae: /* original d30c, guest PC 0x0c0506ae */
if(!s->budget--) { s->failed_pc=0x0c0506aeu; return 0; }
r[3]=read(ram,0x0c0506e0u,4);
goto P_0c0506b0;
P_0c0506b0: /* original e500, guest PC 0x0c0506b0 */
if(!s->budget--) { s->failed_pc=0x0c0506b0u; return 0; }
r[5]=0x00000000u;
goto P_0c0506b2;
P_0c0506b2: /* original 430b, guest PC 0x0c0506b2 */
if(!s->budget--) { s->failed_pc=0x0c0506b2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0506b6u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0506b6u) { target=s->pc; goto dispatch; }
goto P_0c0506b6;
P_0c0506b4: /* original 64f2, guest PC 0x0c0506b4 */
if(!s->budget--) { s->failed_pc=0x0c0506b4u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0506b6;
P_0c0506b6: /* original 60e3, guest PC 0x0c0506b6 */
if(!s->budget--) { s->failed_pc=0x0c0506b6u; return 0; }
r[0]=r[14];
goto P_0c0506b8;
P_0c0506b8: /* original 7f08, guest PC 0x0c0506b8 */
if(!s->budget--) { s->failed_pc=0x0c0506b8u; return 0; }
r[15]+=0x00000008u;
goto P_0c0506ba;
P_0c0506ba: /* original 4f16, guest PC 0x0c0506ba */
if(!s->budget--) { s->failed_pc=0x0c0506bau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0506bc;
P_0c0506bc: /* original 4f26, guest PC 0x0c0506bc */
if(!s->budget--) { s->failed_pc=0x0c0506bcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0506be;
P_0c0506be: /* original 6af6, guest PC 0x0c0506be */
if(!s->budget--) { s->failed_pc=0x0c0506beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0506c0;
P_0c0506c0: /* original 6bf6, guest PC 0x0c0506c0 */
if(!s->budget--) { s->failed_pc=0x0c0506c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0506c2;
P_0c0506c2: /* original 6cf6, guest PC 0x0c0506c2 */
if(!s->budget--) { s->failed_pc=0x0c0506c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0506c4;
P_0c0506c4: /* original 6df6, guest PC 0x0c0506c4 */
if(!s->budget--) { s->failed_pc=0x0c0506c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0506c6;
P_0c0506c6: /* original 000b, guest PC 0x0c0506c6 */
if(!s->budget--) { s->failed_pc=0x0c0506c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0506c8: /* original 6ef6, guest PC 0x0c0506c8 */
if(!s->budget--) { s->failed_pc=0x0c0506c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0506cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0506cau; return 0; } return 1;
P_0c0506e4: /* original 2fe6, guest PC 0x0c0506e4 */
if(!s->budget--) { s->failed_pc=0x0c0506e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506e6;
P_0c0506e6: /* original 2fd6, guest PC 0x0c0506e6 */
if(!s->budget--) { s->failed_pc=0x0c0506e6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506e8;
P_0c0506e8: /* original 2fc6, guest PC 0x0c0506e8 */
if(!s->budget--) { s->failed_pc=0x0c0506e8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506ea;
P_0c0506ea: /* original 6c73, guest PC 0x0c0506ea */
if(!s->budget--) { s->failed_pc=0x0c0506eau; return 0; }
r[12]=r[7];
goto P_0c0506ec;
P_0c0506ec: /* original 2fb6, guest PC 0x0c0506ec */
if(!s->budget--) { s->failed_pc=0x0c0506ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506ee;
P_0c0506ee: /* original 2fa6, guest PC 0x0c0506ee */
if(!s->budget--) { s->failed_pc=0x0c0506eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506f0;
P_0c0506f0: /* original 2f96, guest PC 0x0c0506f0 */
if(!s->budget--) { s->failed_pc=0x0c0506f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506f2;
P_0c0506f2: /* original 6943, guest PC 0x0c0506f2 */
if(!s->budget--) { s->failed_pc=0x0c0506f2u; return 0; }
r[9]=r[4];
goto P_0c0506f4;
P_0c0506f4: /* original 2f86, guest PC 0x0c0506f4 */
if(!s->budget--) { s->failed_pc=0x0c0506f4u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0506f6;
P_0c0506f6: /* original 4f22, guest PC 0x0c0506f6 */
if(!s->budget--) { s->failed_pc=0x0c0506f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0506f8;
P_0c0506f8: /* original 4f12, guest PC 0x0c0506f8 */
if(!s->budget--) { s->failed_pc=0x0c0506f8u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0506fa;
P_0c0506fa: /* original 7ff4, guest PC 0x0c0506fa */
if(!s->budget--) { s->failed_pc=0x0c0506fau; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0506fc;
P_0c0506fc: /* original 1f51, guest PC 0x0c0506fc */
if(!s->budget--) { s->failed_pc=0x0c0506fcu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0506fe;
P_0c0506fe: /* original 67f3, guest PC 0x0c0506fe */
if(!s->budget--) { s->failed_pc=0x0c0506feu; return 0; }
r[7]=r[15];
goto P_0c050700;
P_0c050700: /* original 1f62, guest PC 0x0c050700 */
if(!s->budget--) { s->failed_pc=0x0c050700u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c050702;
P_0c050702: /* original 56fc, guest PC 0x0c050702 */
if(!s->budget--) { s->failed_pc=0x0c050702u; return 0; }
r[6]=read(ram,r[15]+48,4);
goto P_0c050704;
P_0c050704: /* original 55f1, guest PC 0x0c050704 */
if(!s->budget--) { s->failed_pc=0x0c050704u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c050706;
P_0c050706: /* original d342, guest PC 0x0c050706 */
if(!s->budget--) { s->failed_pc=0x0c050706u; return 0; }
r[3]=read(ram,0x0c050810u,4);
goto P_0c050708;
P_0c050708: /* original 430b, guest PC 0x0c050708 */
if(!s->budget--) { s->failed_pc=0x0c050708u; return 0; }
target=r[3];
r[16]=code_base|0x0c05070cu;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05070cu) { target=s->pc; goto dispatch; }
goto P_0c05070c;
P_0c05070a: /* original 6493, guest PC 0x0c05070a */
if(!s->budget--) { s->failed_pc=0x0c05070au; return 0; }
r[4]=r[9];
goto P_0c05070c;
P_0c05070c: /* original 6e03, guest PC 0x0c05070c */
if(!s->budget--) { s->failed_pc=0x0c05070cu; return 0; }
r[14]=r[0];
goto P_0c05070e;
P_0c05070e: /* original 4e11, guest PC 0x0c05070e */
if(!s->budget--) { s->failed_pc=0x0c05070eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c050710;
P_0c050710: /* original 8b58, guest PC 0x0c050710 */
if(!s->budget--) { s->failed_pc=0x0c050710u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0507c4; }
goto P_0c050712;
P_0c050712: /* original 63f2, guest PC 0x0c050712 */
if(!s->budget--) { s->failed_pc=0x0c050712u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c050714;
P_0c050714: /* original e201, guest PC 0x0c050714 */
if(!s->budget--) { s->failed_pc=0x0c050714u; return 0; }
r[2]=0x00000001u;
goto P_0c050716;
P_0c050716: /* original 50fd, guest PC 0x0c050716 */
if(!s->budget--) { s->failed_pc=0x0c050716u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c050718;
P_0c050718: /* original 61c3, guest PC 0x0c050718 */
if(!s->budget--) { s->failed_pc=0x0c050718u; return 0; }
r[1]=r[12];
goto P_0c05071a;
P_0c05071a: /* original 4100, guest PC 0x0c05071a */
if(!s->budget--) { s->failed_pc=0x0c05071au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c05071c;
P_0c05071c: /* original 8031, guest PC 0x0c05071c */
if(!s->budget--) { s->failed_pc=0x0c05071cu; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c05071e;
P_0c05071e: /* original ea00, guest PC 0x0c05071e */
if(!s->budget--) { s->failed_pc=0x0c05071eu; return 0; }
r[10]=0x00000000u;
goto P_0c050720;
P_0c050720: /* original 9472, guest PC 0x0c050720 */
if(!s->budget--) { s->failed_pc=0x0c050720u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c050808u,2);
goto P_0c050722;
P_0c050722: /* original d33c, guest PC 0x0c050722 */
if(!s->budget--) { s->failed_pc=0x0c050722u; return 0; }
r[3]=read(ram,0x0c050814u,4);
goto P_0c050724;
P_0c050724: /* original 294f, guest PC 0x0c050724 */
if(!s->budget--) { s->failed_pc=0x0c050724u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[4]);
goto P_0c050726;
P_0c050726: /* original 5bf2, guest PC 0x0c050726 */
if(!s->budget--) { s->failed_pc=0x0c050726u; return 0; }
r[11]=read(ram,r[15]+8,4);
goto P_0c050728;
P_0c050728: /* original 041a, guest PC 0x0c050728 */
if(!s->budget--) { s->failed_pc=0x0c050728u; return 0; }
r[4]=r[19];
goto P_0c05072a;
P_0c05072a: /* original 644f, guest PC 0x0c05072a */
if(!s->budget--) { s->failed_pc=0x0c05072au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c05072c;
P_0c05072c: /* original 343c, guest PC 0x0c05072c */
if(!s->budget--) { s->failed_pc=0x0c05072cu; return 0; }
r[4]+=r[3];
goto P_0c05072e;
P_0c05072e: /* original 142c, guest PC 0x0c05072e */
if(!s->budget--) { s->failed_pc=0x0c05072eu; return 0; }
write(ram,r[4]+48,r[2],4);
goto P_0c050730;
P_0c050730: /* original 5241, guest PC 0x0c050730 */
if(!s->budget--) { s->failed_pc=0x0c050730u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c050732;
P_0c050732: /* original 9d6a, guest PC 0x0c050732 */
if(!s->budget--) { s->failed_pc=0x0c050732u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05080au,2);
goto P_0c050734;
P_0c050734: /* original 6023, guest PC 0x0c050734 */
if(!s->budget--) { s->failed_pc=0x0c050734u; return 0; }
r[0]=r[2];
goto P_0c050736;
P_0c050736: /* original 4208, guest PC 0x0c050736 */
if(!s->budget--) { s->failed_pc=0x0c050736u; return 0; }
r[2]<<=2;
goto P_0c050738;
P_0c050738: /* original 320c, guest PC 0x0c050738 */
if(!s->budget--) { s->failed_pc=0x0c050738u; return 0; }
r[2]+=r[0];
goto P_0c05073a;
P_0c05073a: /* original d037, guest PC 0x0c05073a */
if(!s->budget--) { s->failed_pc=0x0c05073au; return 0; }
r[0]=read(ram,0x0c050818u,4);
goto P_0c05073c;
P_0c05073c: /* original 4208, guest PC 0x0c05073c */
if(!s->budget--) { s->failed_pc=0x0c05073cu; return 0; }
r[2]<<=2;
goto P_0c05073e;
P_0c05073e: /* original 4208, guest PC 0x0c05073e */
if(!s->budget--) { s->failed_pc=0x0c05073eu; return 0; }
r[2]<<=2;
goto P_0c050740;
P_0c050740: /* original 622f, guest PC 0x0c050740 */
if(!s->budget--) { s->failed_pc=0x0c050740u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c050742;
P_0c050742: /* original 022e, guest PC 0x0c050742 */
if(!s->budget--) { s->failed_pc=0x0c050742u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c050744;
P_0c050744: /* original 312c, guest PC 0x0c050744 */
if(!s->budget--) { s->failed_pc=0x0c050744u; return 0; }
r[1]+=r[2];
goto P_0c050746;
P_0c050746: /* original 62a3, guest PC 0x0c050746 */
if(!s->budget--) { s->failed_pc=0x0c050746u; return 0; }
r[2]=r[10];
goto P_0c050748;
P_0c050748: /* original 32c2, guest PC 0x0c050748 */
if(!s->budget--) { s->failed_pc=0x0c050748u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[12])!=0);
goto P_0c05074a;
P_0c05074a: /* original 8d0b, guest PC 0x0c05074a */
if(!s->budget--) { s->failed_pc=0x0c05074au; return 0; }
cond=r[17]&1u;
write(ram,r[4]+52,r[1],4);
if(cond) { goto P_0c050764; }
goto P_0c05074e;
P_0c05074c: /* original 141d, guest PC 0x0c05074c */
if(!s->budget--) { s->failed_pc=0x0c05074cu; return 0; }
write(ram,r[4]+52,r[1],4);
goto P_0c05074e;
P_0c05074e: /* original d333, guest PC 0x0c05074e */
if(!s->budget--) { s->failed_pc=0x0c05074eu; return 0; }
r[3]=read(ram,0x0c05081cu,4);
goto P_0c050750;
P_0c050750: /* original 65b3, guest PC 0x0c050750 */
if(!s->budget--) { s->failed_pc=0x0c050750u; return 0; }
r[5]=r[11];
goto P_0c050752;
P_0c050752: /* original 430b, guest PC 0x0c050752 */
if(!s->budget--) { s->failed_pc=0x0c050752u; return 0; }
target=r[3];
r[16]=code_base|0x0c050756u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050756u) { target=s->pc; goto dispatch; }
goto P_0c050756;
P_0c050754: /* original 64f2, guest PC 0x0c050754 */
if(!s->budget--) { s->failed_pc=0x0c050754u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c050756;
P_0c050756: /* original 6e03, guest PC 0x0c050756 */
if(!s->budget--) { s->failed_pc=0x0c050756u; return 0; }
r[14]=r[0];
goto P_0c050758;
P_0c050758: /* original 4e11, guest PC 0x0c050758 */
if(!s->budget--) { s->failed_pc=0x0c050758u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c05075a;
P_0c05075a: /* original 8b2f, guest PC 0x0c05075a */
if(!s->budget--) { s->failed_pc=0x0c05075au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0507bc; }
goto P_0c05075c;
P_0c05075c: /* original 7a01, guest PC 0x0c05075c */
if(!s->budget--) { s->failed_pc=0x0c05075cu; return 0; }
r[10]+=0x00000001u;
goto P_0c05075e;
P_0c05075e: /* original 3ac2, guest PC 0x0c05075e */
if(!s->budget--) { s->failed_pc=0x0c05075eu; return 0; }
r[17]=(r[17]&~1u)|((r[10]>=r[12])!=0);
goto P_0c050760;
P_0c050760: /* original 8ff5, guest PC 0x0c050760 */
if(!s->budget--) { s->failed_pc=0x0c050760u; return 0; }
cond=r[17]&1u;
r[11]+=r[13];
if(!cond) { goto P_0c05074e; }
goto P_0c050764;
P_0c050762: /* original 3bdc, guest PC 0x0c050762 */
if(!s->budget--) { s->failed_pc=0x0c050762u; return 0; }
r[11]+=r[13];
goto P_0c050764;
P_0c050764: /* original d32e, guest PC 0x0c050764 */
if(!s->budget--) { s->failed_pc=0x0c050764u; return 0; }
r[3]=read(ram,0x0c050820u,4);
goto P_0c050766;
P_0c050766: /* original e500, guest PC 0x0c050766 */
if(!s->budget--) { s->failed_pc=0x0c050766u; return 0; }
r[5]=0x00000000u;
goto P_0c050768;
P_0c050768: /* original 430b, guest PC 0x0c050768 */
if(!s->budget--) { s->failed_pc=0x0c050768u; return 0; }
target=r[3];
r[16]=code_base|0x0c05076cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05076cu) { target=s->pc; goto dispatch; }
goto P_0c05076c;
P_0c05076a: /* original 64f2, guest PC 0x0c05076a */
if(!s->budget--) { s->failed_pc=0x0c05076au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05076c;
P_0c05076c: /* original d32d, guest PC 0x0c05076c */
if(!s->budget--) { s->failed_pc=0x0c05076cu; return 0; }
r[3]=read(ram,0x0c050824u,4);
goto P_0c05076e;
P_0c05076e: /* original 66f3, guest PC 0x0c05076e */
if(!s->budget--) { s->failed_pc=0x0c05076eu; return 0; }
r[6]=r[15];
goto P_0c050770;
P_0c050770: /* original 55f1, guest PC 0x0c050770 */
if(!s->budget--) { s->failed_pc=0x0c050770u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c050772;
P_0c050772: /* original 430b, guest PC 0x0c050772 */
if(!s->budget--) { s->failed_pc=0x0c050772u; return 0; }
target=r[3];
r[16]=code_base|0x0c050776u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c050776u) { target=s->pc; goto dispatch; }
goto P_0c050776;
P_0c050774: /* original 6493, guest PC 0x0c050774 */
if(!s->budget--) { s->failed_pc=0x0c050774u; return 0; }
r[4]=r[9];
goto P_0c050776;
P_0c050776: /* original 6e03, guest PC 0x0c050776 */
if(!s->budget--) { s->failed_pc=0x0c050776u; return 0; }
r[14]=r[0];
goto P_0c050778;
P_0c050778: /* original 4e11, guest PC 0x0c050778 */
if(!s->budget--) { s->failed_pc=0x0c050778u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c05077a;
P_0c05077a: /* original 8b23, guest PC 0x0c05077a */
if(!s->budget--) { s->failed_pc=0x0c05077au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0507c4; }
goto P_0c05077c;
P_0c05077c: /* original 6893, guest PC 0x0c05077c */
if(!s->budget--) { s->failed_pc=0x0c05077cu; return 0; }
r[8]=r[9];
goto P_0c05077e;
P_0c05077e: /* original 4818, guest PC 0x0c05077e */
if(!s->budget--) { s->failed_pc=0x0c05077eu; return 0; }
r[8]<<=8;
goto P_0c050780;
P_0c050780: /* original eb00, guest PC 0x0c050780 */
if(!s->budget--) { s->failed_pc=0x0c050780u; return 0; }
r[11]=0x00000000u;
goto P_0c050782;
P_0c050782: /* original d329, guest PC 0x0c050782 */
if(!s->budget--) { s->failed_pc=0x0c050782u; return 0; }
r[3]=read(ram,0x0c050828u,4);
goto P_0c050784;
P_0c050784: /* original 62b3, guest PC 0x0c050784 */
if(!s->budget--) { s->failed_pc=0x0c050784u; return 0; }
r[2]=r[11];
goto P_0c050786;
P_0c050786: /* original 5af2, guest PC 0x0c050786 */
if(!s->budget--) { s->failed_pc=0x0c050786u; return 0; }
r[10]=read(ram,r[15]+8,4);
goto P_0c050788;
P_0c050788: /* original 4808, guest PC 0x0c050788 */
if(!s->budget--) { s->failed_pc=0x0c050788u; return 0; }
r[8]<<=2;
goto P_0c05078a;
P_0c05078a: /* original 4800, guest PC 0x0c05078a */
if(!s->budget--) { s->failed_pc=0x0c05078au; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c05078c;
P_0c05078c: /* original 32c2, guest PC 0x0c05078c */
if(!s->budget--) { s->failed_pc=0x0c05078cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[12])!=0);
goto P_0c05078e;
P_0c05078e: /* original 8d14, guest PC 0x0c05078e */
if(!s->budget--) { s->failed_pc=0x0c05078eu; return 0; }
cond=r[17]&1u;
r[8]+=r[3];
if(cond) { goto P_0c0507ba; }
goto P_0c050792;
P_0c050790: /* original 383c, guest PC 0x0c050790 */
if(!s->budget--) { s->failed_pc=0x0c050790u; return 0; }
r[8]+=r[3];
goto P_0c050792;
P_0c050792: /* original 993b, guest PC 0x0c050792 */
if(!s->budget--) { s->failed_pc=0x0c050792u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05080cu,2);
goto P_0c050794;
P_0c050794: /* original d325, guest PC 0x0c050794 */
if(!s->budget--) { s->failed_pc=0x0c050794u; return 0; }
r[3]=read(ram,0x0c05082cu,4);
goto P_0c050796;
P_0c050796: /* original 6583, guest PC 0x0c050796 */
if(!s->budget--) { s->failed_pc=0x0c050796u; return 0; }
r[5]=r[8];
goto P_0c050798;
P_0c050798: /* original 430b, guest PC 0x0c050798 */
if(!s->budget--) { s->failed_pc=0x0c050798u; return 0; }
target=r[3];
r[16]=code_base|0x0c05079cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05079cu) { target=s->pc; goto dispatch; }
goto P_0c05079c;
P_0c05079a: /* original 64f2, guest PC 0x0c05079a */
if(!s->budget--) { s->failed_pc=0x0c05079au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05079c;
P_0c05079c: /* original 6e03, guest PC 0x0c05079c */
if(!s->budget--) { s->failed_pc=0x0c05079cu; return 0; }
r[14]=r[0];
goto P_0c05079e;
P_0c05079e: /* original 4e11, guest PC 0x0c05079e */
if(!s->budget--) { s->failed_pc=0x0c05079eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c0507a0;
P_0c0507a0: /* original 8b0c, guest PC 0x0c0507a0 */
if(!s->budget--) { s->failed_pc=0x0c0507a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0507bc; }
goto P_0c0507a2;
P_0c0507a2: /* original d223, guest PC 0x0c0507a2 */
if(!s->budget--) { s->failed_pc=0x0c0507a2u; return 0; }
r[2]=read(ram,0x0c050830u,4);
goto P_0c0507a4;
P_0c0507a4: /* original 65a3, guest PC 0x0c0507a4 */
if(!s->budget--) { s->failed_pc=0x0c0507a4u; return 0; }
r[5]=r[10];
goto P_0c0507a6;
P_0c0507a6: /* original 420b, guest PC 0x0c0507a6 */
if(!s->budget--) { s->failed_pc=0x0c0507a6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0507aau;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0507aau) { target=s->pc; goto dispatch; }
goto P_0c0507aa;
P_0c0507a8: /* original 6483, guest PC 0x0c0507a8 */
if(!s->budget--) { s->failed_pc=0x0c0507a8u; return 0; }
r[4]=r[8];
goto P_0c0507aa;
P_0c0507aa: /* original 2008, guest PC 0x0c0507aa */
if(!s->budget--) { s->failed_pc=0x0c0507aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0507ac;
P_0c0507ac: /* original 8901, guest PC 0x0c0507ac */
if(!s->budget--) { s->failed_pc=0x0c0507acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0507b2; }
goto P_0c0507ae;
P_0c0507ae: /* original a005, guest PC 0x0c0507ae */
if(!s->budget--) { s->failed_pc=0x0c0507aeu; return 0; }
r[14]=r[9];
goto P_0c0507bc;
P_0c0507b0: /* original 6e93, guest PC 0x0c0507b0 */
if(!s->budget--) { s->failed_pc=0x0c0507b0u; return 0; }
r[14]=r[9];
goto P_0c0507b2;
P_0c0507b2: /* original 7b01, guest PC 0x0c0507b2 */
if(!s->budget--) { s->failed_pc=0x0c0507b2u; return 0; }
r[11]+=0x00000001u;
goto P_0c0507b4;
P_0c0507b4: /* original 3bc2, guest PC 0x0c0507b4 */
if(!s->budget--) { s->failed_pc=0x0c0507b4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>=r[12])!=0);
goto P_0c0507b6;
P_0c0507b6: /* original 8fed, guest PC 0x0c0507b6 */
if(!s->budget--) { s->failed_pc=0x0c0507b6u; return 0; }
cond=r[17]&1u;
r[10]+=r[13];
if(!cond) { goto P_0c050794; }
goto P_0c0507ba;
P_0c0507b8: /* original 3adc, guest PC 0x0c0507b8 */
if(!s->budget--) { s->failed_pc=0x0c0507b8u; return 0; }
r[10]+=r[13];
goto P_0c0507ba;
P_0c0507ba: /* original ee00, guest PC 0x0c0507ba */
if(!s->budget--) { s->failed_pc=0x0c0507bau; return 0; }
r[14]=0x00000000u;
goto P_0c0507bc;
P_0c0507bc: /* original d318, guest PC 0x0c0507bc */
if(!s->budget--) { s->failed_pc=0x0c0507bcu; return 0; }
r[3]=read(ram,0x0c050820u,4);
goto P_0c0507be;
P_0c0507be: /* original e500, guest PC 0x0c0507be */
if(!s->budget--) { s->failed_pc=0x0c0507beu; return 0; }
r[5]=0x00000000u;
goto P_0c0507c0;
P_0c0507c0: /* original 430b, guest PC 0x0c0507c0 */
if(!s->budget--) { s->failed_pc=0x0c0507c0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0507c4u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0507c4u) { target=s->pc; goto dispatch; }
goto P_0c0507c4;
P_0c0507c2: /* original 64f2, guest PC 0x0c0507c2 */
if(!s->budget--) { s->failed_pc=0x0c0507c2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0507c4;
P_0c0507c4: /* original 7f0c, guest PC 0x0c0507c4 */
if(!s->budget--) { s->failed_pc=0x0c0507c4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0507c6;
P_0c0507c6: /* original 60e3, guest PC 0x0c0507c6 */
if(!s->budget--) { s->failed_pc=0x0c0507c6u; return 0; }
r[0]=r[14];
goto P_0c0507c8;
P_0c0507c8: /* original 4f16, guest PC 0x0c0507c8 */
if(!s->budget--) { s->failed_pc=0x0c0507c8u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0507ca;
P_0c0507ca: /* original 4f26, guest PC 0x0c0507ca */
if(!s->budget--) { s->failed_pc=0x0c0507cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0507cc;
P_0c0507cc: /* original 68f6, guest PC 0x0c0507cc */
if(!s->budget--) { s->failed_pc=0x0c0507ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0507ce;
P_0c0507ce: /* original 69f6, guest PC 0x0c0507ce */
if(!s->budget--) { s->failed_pc=0x0c0507ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0507d0;
P_0c0507d0: /* original 6af6, guest PC 0x0c0507d0 */
if(!s->budget--) { s->failed_pc=0x0c0507d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0507d2;
P_0c0507d2: /* original 6bf6, guest PC 0x0c0507d2 */
if(!s->budget--) { s->failed_pc=0x0c0507d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0507d4;
P_0c0507d4: /* original 6cf6, guest PC 0x0c0507d4 */
if(!s->budget--) { s->failed_pc=0x0c0507d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0507d6;
P_0c0507d6: /* original 6df6, guest PC 0x0c0507d6 */
if(!s->budget--) { s->failed_pc=0x0c0507d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0507d8;
P_0c0507d8: /* original 000b, guest PC 0x0c0507d8 */
if(!s->budget--) { s->failed_pc=0x0c0507d8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0507da: /* original 6ef6, guest PC 0x0c0507da */
if(!s->budget--) { s->failed_pc=0x0c0507dau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0507dcu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
