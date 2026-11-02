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
int vf3_away_batch30_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06054cu: goto P_0c06054c;
case 0x0c06054eu: goto P_0c06054e;
case 0x0c060550u: goto P_0c060550;
case 0x0c060552u: goto P_0c060552;
case 0x0c060554u: goto P_0c060554;
case 0x0c060556u: goto P_0c060556;
case 0x0c060558u: goto P_0c060558;
case 0x0c06055au: goto P_0c06055a;
case 0x0c06055cu: goto P_0c06055c;
case 0x0c06055eu: goto P_0c06055e;
case 0x0c060560u: goto P_0c060560;
case 0x0c060562u: goto P_0c060562;
case 0x0c060564u: goto P_0c060564;
case 0x0c060566u: goto P_0c060566;
case 0x0c060568u: goto P_0c060568;
case 0x0c06056au: goto P_0c06056a;
case 0x0c06056cu: goto P_0c06056c;
case 0x0c06056eu: goto P_0c06056e;
case 0x0c060570u: goto P_0c060570;
case 0x0c060572u: goto P_0c060572;
case 0x0c060574u: goto P_0c060574;
case 0x0c060576u: goto P_0c060576;
case 0x0c060578u: goto P_0c060578;
case 0x0c06057au: goto P_0c06057a;
case 0x0c06057cu: goto P_0c06057c;
case 0x0c06057eu: goto P_0c06057e;
case 0x0c060580u: goto P_0c060580;
case 0x0c060582u: goto P_0c060582;
case 0x0c060584u: goto P_0c060584;
case 0x0c060586u: goto P_0c060586;
case 0x0c060588u: goto P_0c060588;
case 0x0c06058au: goto P_0c06058a;
case 0x0c06058cu: goto P_0c06058c;
case 0x0c06058eu: goto P_0c06058e;
case 0x0c060590u: goto P_0c060590;
case 0x0c060592u: goto P_0c060592;
case 0x0c060594u: goto P_0c060594;
case 0x0c060596u: goto P_0c060596;
case 0x0c060598u: goto P_0c060598;
case 0x0c06059au: goto P_0c06059a;
case 0x0c06059cu: goto P_0c06059c;
case 0x0c06059eu: goto P_0c06059e;
case 0x0c0605a0u: goto P_0c0605a0;
case 0x0c0605a2u: goto P_0c0605a2;
case 0x0c0605a4u: goto P_0c0605a4;
case 0x0c0605a6u: goto P_0c0605a6;
case 0x0c0605a8u: goto P_0c0605a8;
case 0x0c0605aau: goto P_0c0605aa;
case 0x0c0605acu: goto P_0c0605ac;
case 0x0c0605aeu: goto P_0c0605ae;
case 0x0c0605b0u: goto P_0c0605b0;
case 0x0c0605b2u: goto P_0c0605b2;
case 0x0c0605b4u: goto P_0c0605b4;
case 0x0c0605b6u: goto P_0c0605b6;
case 0x0c0605b8u: goto P_0c0605b8;
case 0x0c0605bau: goto P_0c0605ba;
case 0x0c0605bcu: goto P_0c0605bc;
case 0x0c0605beu: goto P_0c0605be;
case 0x0c0605c0u: goto P_0c0605c0;
case 0x0c0605c2u: goto P_0c0605c2;
case 0x0c0605c4u: goto P_0c0605c4;
case 0x0c0605c6u: goto P_0c0605c6;
case 0x0c0605c8u: goto P_0c0605c8;
case 0x0c0605cau: goto P_0c0605ca;
case 0x0c0605ccu: goto P_0c0605cc;
case 0x0c0605ceu: goto P_0c0605ce;
case 0x0c0605d0u: goto P_0c0605d0;
case 0x0c0605d2u: goto P_0c0605d2;
case 0x0c0605d4u: goto P_0c0605d4;
case 0x0c0605d6u: goto P_0c0605d6;
case 0x0c0605d8u: goto P_0c0605d8;
case 0x0c0605dau: goto P_0c0605da;
case 0x0c0605dcu: goto P_0c0605dc;
case 0x0c0605deu: goto P_0c0605de;
case 0x0c0605e0u: goto P_0c0605e0;
case 0x0c0605e2u: goto P_0c0605e2;
case 0x0c0605e4u: goto P_0c0605e4;
case 0x0c0605e6u: goto P_0c0605e6;
case 0x0c0605e8u: goto P_0c0605e8;
case 0x0c0605eau: goto P_0c0605ea;
case 0x0c0605ecu: goto P_0c0605ec;
case 0x0c0605eeu: goto P_0c0605ee;
case 0x0c0605f0u: goto P_0c0605f0;
case 0x0c0605f2u: goto P_0c0605f2;
case 0x0c0605f4u: goto P_0c0605f4;
case 0x0c0605f6u: goto P_0c0605f6;
case 0x0c0605f8u: goto P_0c0605f8;
case 0x0c0605fau: goto P_0c0605fa;
case 0x0c0605fcu: goto P_0c0605fc;
case 0x0c0605feu: goto P_0c0605fe;
case 0x0c060600u: goto P_0c060600;
case 0x0c060602u: goto P_0c060602;
case 0x0c060604u: goto P_0c060604;
case 0x0c060606u: goto P_0c060606;
case 0x0c060608u: goto P_0c060608;
case 0x0c06060au: goto P_0c06060a;
case 0x0c06060cu: goto P_0c06060c;
case 0x0c06060eu: goto P_0c06060e;
case 0x0c060610u: goto P_0c060610;
case 0x0c060612u: goto P_0c060612;
case 0x0c060614u: goto P_0c060614;
case 0x0c060616u: goto P_0c060616;
case 0x0c060618u: goto P_0c060618;
case 0x0c06061au: goto P_0c06061a;
case 0x0c06061cu: goto P_0c06061c;
case 0x0c06061eu: goto P_0c06061e;
case 0x0c060620u: goto P_0c060620;
case 0x0c060622u: goto P_0c060622;
case 0x0c060624u: goto P_0c060624;
case 0x0c060626u: goto P_0c060626;
case 0x0c060628u: goto P_0c060628;
case 0x0c06062au: goto P_0c06062a;
case 0x0c06062cu: goto P_0c06062c;
case 0x0c06062eu: goto P_0c06062e;
case 0x0c060630u: goto P_0c060630;
case 0x0c060632u: goto P_0c060632;
case 0x0c060634u: goto P_0c060634;
case 0x0c060636u: goto P_0c060636;
case 0x0c060638u: goto P_0c060638;
case 0x0c06063au: goto P_0c06063a;
case 0x0c06063cu: goto P_0c06063c;
case 0x0c06063eu: goto P_0c06063e;
case 0x0c060640u: goto P_0c060640;
case 0x0c060642u: goto P_0c060642;
case 0x0c060644u: goto P_0c060644;
case 0x0c060646u: goto P_0c060646;
case 0x0c060648u: goto P_0c060648;
case 0x0c06064au: goto P_0c06064a;
case 0x0c06064cu: goto P_0c06064c;
case 0x0c06064eu: goto P_0c06064e;
case 0x0c060650u: goto P_0c060650;
case 0x0c060652u: goto P_0c060652;
case 0x0c060654u: goto P_0c060654;
case 0x0c060656u: goto P_0c060656;
case 0x0c060658u: goto P_0c060658;
case 0x0c06065au: goto P_0c06065a;
case 0x0c06065cu: goto P_0c06065c;
case 0x0c06065eu: goto P_0c06065e;
case 0x0c060660u: goto P_0c060660;
case 0x0c060662u: goto P_0c060662;
case 0x0c060664u: goto P_0c060664;
case 0x0c060666u: goto P_0c060666;
case 0x0c060668u: goto P_0c060668;
case 0x0c06066au: goto P_0c06066a;
case 0x0c06066cu: goto P_0c06066c;
case 0x0c06066eu: goto P_0c06066e;
case 0x0c060670u: goto P_0c060670;
case 0x0c060672u: goto P_0c060672;
case 0x0c060674u: goto P_0c060674;
case 0x0c060676u: goto P_0c060676;
case 0x0c060678u: goto P_0c060678;
case 0x0c06067au: goto P_0c06067a;
case 0x0c06067cu: goto P_0c06067c;
case 0x0c06067eu: goto P_0c06067e;
case 0x0c060680u: goto P_0c060680;
case 0x0c060682u: goto P_0c060682;
case 0x0c060684u: goto P_0c060684;
case 0x0c060686u: goto P_0c060686;
case 0x0c060688u: goto P_0c060688;
case 0x0c06068au: goto P_0c06068a;
case 0x0c06068cu: goto P_0c06068c;
case 0x0c06068eu: goto P_0c06068e;
case 0x0c060690u: goto P_0c060690;
case 0x0c060692u: goto P_0c060692;
case 0x0c060694u: goto P_0c060694;
case 0x0c060696u: goto P_0c060696;
case 0x0c060698u: goto P_0c060698;
case 0x0c06069au: goto P_0c06069a;
case 0x0c06069cu: goto P_0c06069c;
case 0x0c06069eu: goto P_0c06069e;
case 0x0c0606a0u: goto P_0c0606a0;
case 0x0c0606a2u: goto P_0c0606a2;
case 0x0c0606a4u: goto P_0c0606a4;
case 0x0c0606a6u: goto P_0c0606a6;
case 0x0c0606a8u: goto P_0c0606a8;
case 0x0c0606aau: goto P_0c0606aa;
case 0x0c0606acu: goto P_0c0606ac;
case 0x0c0606aeu: goto P_0c0606ae;
case 0x0c0606b0u: goto P_0c0606b0;
case 0x0c0606b2u: goto P_0c0606b2;
case 0x0c0606b4u: goto P_0c0606b4;
case 0x0c0606b6u: goto P_0c0606b6;
case 0x0c0606b8u: goto P_0c0606b8;
case 0x0c0606bau: goto P_0c0606ba;
case 0x0c0606bcu: goto P_0c0606bc;
case 0x0c0606beu: goto P_0c0606be;
case 0x0c0606c0u: goto P_0c0606c0;
case 0x0c0606c2u: goto P_0c0606c2;
case 0x0c060710u: goto P_0c060710;
case 0x0c060712u: goto P_0c060712;
case 0x0c060714u: goto P_0c060714;
case 0x0c060716u: goto P_0c060716;
case 0x0c060718u: goto P_0c060718;
case 0x0c06071au: goto P_0c06071a;
case 0x0c06071cu: goto P_0c06071c;
case 0x0c06071eu: goto P_0c06071e;
case 0x0c060720u: goto P_0c060720;
case 0x0c060722u: goto P_0c060722;
case 0x0c060724u: goto P_0c060724;
case 0x0c060726u: goto P_0c060726;
case 0x0c060728u: goto P_0c060728;
case 0x0c06072au: goto P_0c06072a;
case 0x0c06072cu: goto P_0c06072c;
case 0x0c06072eu: goto P_0c06072e;
case 0x0c060730u: goto P_0c060730;
case 0x0c060732u: goto P_0c060732;
case 0x0c060734u: goto P_0c060734;
case 0x0c060736u: goto P_0c060736;
case 0x0c060738u: goto P_0c060738;
case 0x0c06073au: goto P_0c06073a;
case 0x0c06073cu: goto P_0c06073c;
case 0x0c06073eu: goto P_0c06073e;
case 0x0c060740u: goto P_0c060740;
case 0x0c060742u: goto P_0c060742;
case 0x0c060744u: goto P_0c060744;
case 0x0c060746u: goto P_0c060746;
case 0x0c060748u: goto P_0c060748;
case 0x0c06074au: goto P_0c06074a;
case 0x0c06074cu: goto P_0c06074c;
case 0x0c06074eu: goto P_0c06074e;
case 0x0c060750u: goto P_0c060750;
case 0x0c060752u: goto P_0c060752;
case 0x0c060754u: goto P_0c060754;
case 0x0c060756u: goto P_0c060756;
case 0x0c060758u: goto P_0c060758;
case 0x0c06075au: goto P_0c06075a;
case 0x0c06075cu: goto P_0c06075c;
case 0x0c06075eu: goto P_0c06075e;
case 0x0c060760u: goto P_0c060760;
case 0x0c060762u: goto P_0c060762;
case 0x0c060764u: goto P_0c060764;
case 0x0c060766u: goto P_0c060766;
case 0x0c060768u: goto P_0c060768;
case 0x0c06076au: goto P_0c06076a;
case 0x0c06076cu: goto P_0c06076c;
case 0x0c06076eu: goto P_0c06076e;
case 0x0c060770u: goto P_0c060770;
case 0x0c060772u: goto P_0c060772;
case 0x0c060774u: goto P_0c060774;
case 0x0c060776u: goto P_0c060776;
case 0x0c060778u: goto P_0c060778;
case 0x0c06077au: goto P_0c06077a;
case 0x0c06077cu: goto P_0c06077c;
case 0x0c06077eu: goto P_0c06077e;
case 0x0c060780u: goto P_0c060780;
case 0x0c060782u: goto P_0c060782;
case 0x0c060784u: goto P_0c060784;
case 0x0c060786u: goto P_0c060786;
case 0x0c060788u: goto P_0c060788;
case 0x0c06078au: goto P_0c06078a;
case 0x0c06078cu: goto P_0c06078c;
case 0x0c06078eu: goto P_0c06078e;
case 0x0c060790u: goto P_0c060790;
case 0x0c060792u: goto P_0c060792;
case 0x0c060794u: goto P_0c060794;
case 0x0c060796u: goto P_0c060796;
case 0x0c060798u: goto P_0c060798;
case 0x0c06079au: goto P_0c06079a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06054c: /* original 2fe6, guest PC 0x0c06054c */
if(!s->budget--) { s->failed_pc=0x0c06054cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06054e;
P_0c06054e: /* original 2fd6, guest PC 0x0c06054e */
if(!s->budget--) { s->failed_pc=0x0c06054eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060550;
P_0c060550: /* original 2fc6, guest PC 0x0c060550 */
if(!s->budget--) { s->failed_pc=0x0c060550u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c060552;
P_0c060552: /* original 4f22, guest PC 0x0c060552 */
if(!s->budget--) { s->failed_pc=0x0c060552u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c060554;
P_0c060554: /* original 90b6, guest PC 0x0c060554 */
if(!s->budget--) { s->failed_pc=0x0c060554u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606c4u,2);
goto P_0c060556;
P_0c060556: /* original 64f3, guest PC 0x0c060556 */
if(!s->budget--) { s->failed_pc=0x0c060556u; return 0; }
r[4]=r[15];
goto P_0c060558;
P_0c060558: /* original d25c, guest PC 0x0c060558 */
if(!s->budget--) { s->failed_pc=0x0c060558u; return 0; }
r[2]=read(ram,0x0c0606ccu,4);
goto P_0c06055a;
P_0c06055a: /* original 7410, guest PC 0x0c06055a */
if(!s->budget--) { s->failed_pc=0x0c06055au; return 0; }
r[4]+=0x00000010u;
goto P_0c06055c;
P_0c06055c: /* original 034e, guest PC 0x0c06055c */
if(!s->budget--) { s->failed_pc=0x0c06055cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06055e;
P_0c06055e: /* original 2232, guest PC 0x0c06055e */
if(!s->budget--) { s->failed_pc=0x0c06055eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c060560;
P_0c060560: /* original d35b, guest PC 0x0c060560 */
if(!s->budget--) { s->failed_pc=0x0c060560u; return 0; }
r[3]=read(ram,0x0c0606d0u,4);
goto P_0c060562;
P_0c060562: /* original 70f8, guest PC 0x0c060562 */
if(!s->budget--) { s->failed_pc=0x0c060562u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c060564;
P_0c060564: /* original 014e, guest PC 0x0c060564 */
if(!s->budget--) { s->failed_pc=0x0c060564u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c060566;
P_0c060566: /* original 2312, guest PC 0x0c060566 */
if(!s->budget--) { s->failed_pc=0x0c060566u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c060568;
P_0c060568: /* original d15a, guest PC 0x0c060568 */
if(!s->budget--) { s->failed_pc=0x0c060568u; return 0; }
r[1]=read(ram,0x0c0606d4u,4);
goto P_0c06056a;
P_0c06056a: /* original 7004, guest PC 0x0c06056a */
if(!s->budget--) { s->failed_pc=0x0c06056au; return 0; }
r[0]+=0x00000004u;
goto P_0c06056c;
P_0c06056c: /* original 024e, guest PC 0x0c06056c */
if(!s->budget--) { s->failed_pc=0x0c06056cu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06056e;
P_0c06056e: /* original 2122, guest PC 0x0c06056e */
if(!s->budget--) { s->failed_pc=0x0c06056eu; return 0; }
write(ram,r[1],r[2],4);
goto P_0c060570;
P_0c060570: /* original e054, guest PC 0x0c060570 */
if(!s->budget--) { s->failed_pc=0x0c060570u; return 0; }
r[0]=0x00000054u;
goto P_0c060572;
P_0c060572: /* original 034e, guest PC 0x0c060572 */
if(!s->budget--) { s->failed_pc=0x0c060572u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c060574;
P_0c060574: /* original 4300, guest PC 0x0c060574 */
if(!s->budget--) { s->failed_pc=0x0c060574u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c060576;
P_0c060576: /* original e050, guest PC 0x0c060576 */
if(!s->budget--) { s->failed_pc=0x0c060576u; return 0; }
r[0]=0x00000050u;
goto P_0c060578;
P_0c060578: /* original 024e, guest PC 0x0c060578 */
if(!s->budget--) { s->failed_pc=0x0c060578u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06057a;
P_0c06057a: /* original e05c, guest PC 0x0c06057a */
if(!s->budget--) { s->failed_pc=0x0c06057au; return 0; }
r[0]=0x0000005cu;
goto P_0c06057c;
P_0c06057c: /* original 232b, guest PC 0x0c06057c */
if(!s->budget--) { s->failed_pc=0x0c06057cu; return 0; }
r[3]|=r[2];
goto P_0c06057e;
P_0c06057e: /* original 024e, guest PC 0x0c06057e */
if(!s->budget--) { s->failed_pc=0x0c06057eu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060580;
P_0c060580: /* original 4208, guest PC 0x0c060580 */
if(!s->budget--) { s->failed_pc=0x0c060580u; return 0; }
r[2]<<=2;
goto P_0c060582;
P_0c060582: /* original 232b, guest PC 0x0c060582 */
if(!s->budget--) { s->failed_pc=0x0c060582u; return 0; }
r[3]|=r[2];
goto P_0c060584;
P_0c060584: /* original e068, guest PC 0x0c060584 */
if(!s->budget--) { s->failed_pc=0x0c060584u; return 0; }
r[0]=0x00000068u;
goto P_0c060586;
P_0c060586: /* original 024e, guest PC 0x0c060586 */
if(!s->budget--) { s->failed_pc=0x0c060586u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060588;
P_0c060588: /* original 4208, guest PC 0x0c060588 */
if(!s->budget--) { s->failed_pc=0x0c060588u; return 0; }
r[2]<<=2;
goto P_0c06058a;
P_0c06058a: /* original 4200, guest PC 0x0c06058a */
if(!s->budget--) { s->failed_pc=0x0c06058au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c06058c;
P_0c06058c: /* original 514b, guest PC 0x0c06058c */
if(!s->budget--) { s->failed_pc=0x0c06058cu; return 0; }
r[1]=read(ram,r[4]+44,4);
goto P_0c06058e;
P_0c06058e: /* original e060, guest PC 0x0c06058e */
if(!s->budget--) { s->failed_pc=0x0c06058eu; return 0; }
r[0]=0x00000060u;
goto P_0c060590;
P_0c060590: /* original 232b, guest PC 0x0c060590 */
if(!s->budget--) { s->failed_pc=0x0c060590u; return 0; }
r[3]|=r[2];
goto P_0c060592;
P_0c060592: /* original 524c, guest PC 0x0c060592 */
if(!s->budget--) { s->failed_pc=0x0c060592u; return 0; }
r[2]=read(ram,r[4]+48,4);
goto P_0c060594;
P_0c060594: /* original 4208, guest PC 0x0c060594 */
if(!s->budget--) { s->failed_pc=0x0c060594u; return 0; }
r[2]<<=2;
goto P_0c060596;
P_0c060596: /* original 4208, guest PC 0x0c060596 */
if(!s->budget--) { s->failed_pc=0x0c060596u; return 0; }
r[2]<<=2;
goto P_0c060598;
P_0c060598: /* original 232b, guest PC 0x0c060598 */
if(!s->budget--) { s->failed_pc=0x0c060598u; return 0; }
r[3]|=r[2];
goto P_0c06059a;
P_0c06059a: /* original 024e, guest PC 0x0c06059a */
if(!s->budget--) { s->failed_pc=0x0c06059au; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c06059c;
P_0c06059c: /* original 4208, guest PC 0x0c06059c */
if(!s->budget--) { s->failed_pc=0x0c06059cu; return 0; }
r[2]<<=2;
goto P_0c06059e;
P_0c06059e: /* original 4208, guest PC 0x0c06059e */
if(!s->budget--) { s->failed_pc=0x0c06059eu; return 0; }
r[2]<<=2;
goto P_0c0605a0;
P_0c0605a0: /* original 4200, guest PC 0x0c0605a0 */
if(!s->budget--) { s->failed_pc=0x0c0605a0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0605a2;
P_0c0605a2: /* original 232b, guest PC 0x0c0605a2 */
if(!s->budget--) { s->failed_pc=0x0c0605a2u; return 0; }
r[3]|=r[2];
goto P_0c0605a4;
P_0c0605a4: /* original 524a, guest PC 0x0c0605a4 */
if(!s->budget--) { s->failed_pc=0x0c0605a4u; return 0; }
r[2]=read(ram,r[4]+40,4);
goto P_0c0605a6;
P_0c0605a6: /* original e048, guest PC 0x0c0605a6 */
if(!s->budget--) { s->failed_pc=0x0c0605a6u; return 0; }
r[0]=0x00000048u;
goto P_0c0605a8;
P_0c0605a8: /* original 4208, guest PC 0x0c0605a8 */
if(!s->budget--) { s->failed_pc=0x0c0605a8u; return 0; }
r[2]<<=2;
goto P_0c0605aa;
P_0c0605aa: /* original 4208, guest PC 0x0c0605aa */
if(!s->budget--) { s->failed_pc=0x0c0605aau; return 0; }
r[2]<<=2;
goto P_0c0605ac;
P_0c0605ac: /* original 4208, guest PC 0x0c0605ac */
if(!s->budget--) { s->failed_pc=0x0c0605acu; return 0; }
r[2]<<=2;
goto P_0c0605ae;
P_0c0605ae: /* original 232b, guest PC 0x0c0605ae */
if(!s->budget--) { s->failed_pc=0x0c0605aeu; return 0; }
r[3]|=r[2];
goto P_0c0605b0;
P_0c0605b0: /* original e207, guest PC 0x0c0605b0 */
if(!s->budget--) { s->failed_pc=0x0c0605b0u; return 0; }
r[2]=0x00000007u;
goto P_0c0605b2;
P_0c0605b2: /* original 412c, guest PC 0x0c0605b2 */
if(!s->budget--) { s->failed_pc=0x0c0605b2u; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c0605b4;
P_0c0605b4: /* original 231b, guest PC 0x0c0605b4 */
if(!s->budget--) { s->failed_pc=0x0c0605b4u; return 0; }
r[3]|=r[1];
goto P_0c0605b6;
P_0c0605b6: /* original 014e, guest PC 0x0c0605b6 */
if(!s->budget--) { s->failed_pc=0x0c0605b6u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0605b8;
P_0c0605b8: /* original 4118, guest PC 0x0c0605b8 */
if(!s->budget--) { s->failed_pc=0x0c0605b8u; return 0; }
r[1]<<=8;
goto P_0c0605ba;
P_0c0605ba: /* original 231b, guest PC 0x0c0605ba */
if(!s->budget--) { s->failed_pc=0x0c0605bau; return 0; }
r[3]|=r[1];
goto P_0c0605bc;
P_0c0605bc: /* original e04c, guest PC 0x0c0605bc */
if(!s->budget--) { s->failed_pc=0x0c0605bcu; return 0; }
r[0]=0x0000004cu;
goto P_0c0605be;
P_0c0605be: /* original 014e, guest PC 0x0c0605be */
if(!s->budget--) { s->failed_pc=0x0c0605beu; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0605c0;
P_0c0605c0: /* original 4118, guest PC 0x0c0605c0 */
if(!s->budget--) { s->failed_pc=0x0c0605c0u; return 0; }
r[1]<<=8;
goto P_0c0605c2;
P_0c0605c2: /* original 4100, guest PC 0x0c0605c2 */
if(!s->budget--) { s->failed_pc=0x0c0605c2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0605c4;
P_0c0605c4: /* original 231b, guest PC 0x0c0605c4 */
if(!s->budget--) { s->failed_pc=0x0c0605c4u; return 0; }
r[3]|=r[1];
goto P_0c0605c6;
P_0c0605c6: /* original d144, guest PC 0x0c0605c6 */
if(!s->budget--) { s->failed_pc=0x0c0605c6u; return 0; }
r[1]=read(ram,0x0c0606d8u,4);
goto P_0c0605c8;
P_0c0605c8: /* original 2132, guest PC 0x0c0605c8 */
if(!s->budget--) { s->failed_pc=0x0c0605c8u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c0605ca;
P_0c0605ca: /* original 957c, guest PC 0x0c0605ca */
if(!s->budget--) { s->failed_pc=0x0c0605cau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606c6u,2);
goto P_0c0605cc;
P_0c0605cc: /* original 5341, guest PC 0x0c0605cc */
if(!s->budget--) { s->failed_pc=0x0c0605ccu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0605ce;
P_0c0605ce: /* original 2359, guest PC 0x0c0605ce */
if(!s->budget--) { s->failed_pc=0x0c0605ceu; return 0; }
r[3]&=r[5];
goto P_0c0605d0;
P_0c0605d0: /* original 6242, guest PC 0x0c0605d0 */
if(!s->budget--) { s->failed_pc=0x0c0605d0u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0605d2;
P_0c0605d2: /* original 2259, guest PC 0x0c0605d2 */
if(!s->budget--) { s->failed_pc=0x0c0605d2u; return 0; }
r[2]&=r[5];
goto P_0c0605d4;
P_0c0605d4: /* original 4228, guest PC 0x0c0605d4 */
if(!s->budget--) { s->failed_pc=0x0c0605d4u; return 0; }
r[2]<<=16;
goto P_0c0605d6;
P_0c0605d6: /* original 232b, guest PC 0x0c0605d6 */
if(!s->budget--) { s->failed_pc=0x0c0605d6u; return 0; }
r[3]|=r[2];
goto P_0c0605d8;
P_0c0605d8: /* original d240, guest PC 0x0c0605d8 */
if(!s->budget--) { s->failed_pc=0x0c0605d8u; return 0; }
r[2]=read(ram,0x0c0606dcu,4);
goto P_0c0605da;
P_0c0605da: /* original 2232, guest PC 0x0c0605da */
if(!s->budget--) { s->failed_pc=0x0c0605dau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c0605dc;
P_0c0605dc: /* original 5141, guest PC 0x0c0605dc */
if(!s->budget--) { s->failed_pc=0x0c0605dcu; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c0605de;
P_0c0605de: /* original 2159, guest PC 0x0c0605de */
if(!s->budget--) { s->failed_pc=0x0c0605deu; return 0; }
r[1]&=r[5];
goto P_0c0605e0;
P_0c0605e0: /* original d33f, guest PC 0x0c0605e0 */
if(!s->budget--) { s->failed_pc=0x0c0605e0u; return 0; }
r[3]=read(ram,0x0c0606e0u,4);
goto P_0c0605e2;
P_0c0605e2: /* original 4128, guest PC 0x0c0605e2 */
if(!s->budget--) { s->failed_pc=0x0c0605e2u; return 0; }
r[1]<<=16;
goto P_0c0605e4;
P_0c0605e4: /* original 2312, guest PC 0x0c0605e4 */
if(!s->budget--) { s->failed_pc=0x0c0605e4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0605e6;
P_0c0605e6: /* original 5042, guest PC 0x0c0605e6 */
if(!s->budget--) { s->failed_pc=0x0c0605e6u; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c0605e8;
P_0c0605e8: /* original 5145, guest PC 0x0c0605e8 */
if(!s->budget--) { s->failed_pc=0x0c0605e8u; return 0; }
r[1]=read(ram,r[4]+20,4);
goto P_0c0605ea;
P_0c0605ea: /* original 2059, guest PC 0x0c0605ea */
if(!s->budget--) { s->failed_pc=0x0c0605eau; return 0; }
r[0]&=r[5];
goto P_0c0605ec;
P_0c0605ec: /* original 2159, guest PC 0x0c0605ec */
if(!s->budget--) { s->failed_pc=0x0c0605ecu; return 0; }
r[1]&=r[5];
goto P_0c0605ee;
P_0c0605ee: /* original 4128, guest PC 0x0c0605ee */
if(!s->budget--) { s->failed_pc=0x0c0605eeu; return 0; }
r[1]<<=16;
goto P_0c0605f0;
P_0c0605f0: /* original 201b, guest PC 0x0c0605f0 */
if(!s->budget--) { s->failed_pc=0x0c0605f0u; return 0; }
r[0]|=r[1];
goto P_0c0605f2;
P_0c0605f2: /* original d13c, guest PC 0x0c0605f2 */
if(!s->budget--) { s->failed_pc=0x0c0605f2u; return 0; }
r[1]=read(ram,0x0c0606e4u,4);
goto P_0c0605f4;
P_0c0605f4: /* original 2102, guest PC 0x0c0605f4 */
if(!s->budget--) { s->failed_pc=0x0c0605f4u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0605f6;
P_0c0605f6: /* original 5244, guest PC 0x0c0605f6 */
if(!s->budget--) { s->failed_pc=0x0c0605f6u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c0605f8;
P_0c0605f8: /* original 5043, guest PC 0x0c0605f8 */
if(!s->budget--) { s->failed_pc=0x0c0605f8u; return 0; }
r[0]=read(ram,r[4]+12,4);
goto P_0c0605fa;
P_0c0605fa: /* original 2259, guest PC 0x0c0605fa */
if(!s->budget--) { s->failed_pc=0x0c0605fau; return 0; }
r[2]&=r[5];
goto P_0c0605fc;
P_0c0605fc: /* original 2059, guest PC 0x0c0605fc */
if(!s->budget--) { s->failed_pc=0x0c0605fcu; return 0; }
r[0]&=r[5];
goto P_0c0605fe;
P_0c0605fe: /* original 4028, guest PC 0x0c0605fe */
if(!s->budget--) { s->failed_pc=0x0c0605feu; return 0; }
r[0]<<=16;
goto P_0c060600;
P_0c060600: /* original 220b, guest PC 0x0c060600 */
if(!s->budget--) { s->failed_pc=0x0c060600u; return 0; }
r[2]|=r[0];
goto P_0c060602;
P_0c060602: /* original d039, guest PC 0x0c060602 */
if(!s->budget--) { s->failed_pc=0x0c060602u; return 0; }
r[0]=read(ram,0x0c0606e8u,4);
goto P_0c060604;
P_0c060604: /* original 2022, guest PC 0x0c060604 */
if(!s->budget--) { s->failed_pc=0x0c060604u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c060606;
P_0c060606: /* original e074, guest PC 0x0c060606 */
if(!s->budget--) { s->failed_pc=0x0c060606u; return 0; }
r[0]=0x00000074u;
goto P_0c060608;
P_0c060608: /* original 034e, guest PC 0x0c060608 */
if(!s->budget--) { s->failed_pc=0x0c060608u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c06060a;
P_0c06060a: /* original 2359, guest PC 0x0c06060a */
if(!s->budget--) { s->failed_pc=0x0c06060au; return 0; }
r[3]&=r[5];
goto P_0c06060c;
P_0c06060c: /* original e078, guest PC 0x0c06060c */
if(!s->budget--) { s->failed_pc=0x0c06060cu; return 0; }
r[0]=0x00000078u;
goto P_0c06060e;
P_0c06060e: /* original 024e, guest PC 0x0c06060e */
if(!s->budget--) { s->failed_pc=0x0c06060eu; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c060610;
P_0c060610: /* original 2259, guest PC 0x0c060610 */
if(!s->budget--) { s->failed_pc=0x0c060610u; return 0; }
r[2]&=r[5];
goto P_0c060612;
P_0c060612: /* original 4228, guest PC 0x0c060612 */
if(!s->budget--) { s->failed_pc=0x0c060612u; return 0; }
r[2]<<=16;
goto P_0c060614;
P_0c060614: /* original 232b, guest PC 0x0c060614 */
if(!s->budget--) { s->failed_pc=0x0c060614u; return 0; }
r[3]|=r[2];
goto P_0c060616;
P_0c060616: /* original d235, guest PC 0x0c060616 */
if(!s->budget--) { s->failed_pc=0x0c060616u; return 0; }
r[2]=read(ram,0x0c0606ecu,4);
goto P_0c060618;
P_0c060618: /* original 2232, guest PC 0x0c060618 */
if(!s->budget--) { s->failed_pc=0x0c060618u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06061a;
P_0c06061a: /* original e67f, guest PC 0x0c06061a */
if(!s->budget--) { s->failed_pc=0x0c06061au; return 0; }
r[6]=0x0000007fu;
goto P_0c06061c;
P_0c06061c: /* original 9d54, guest PC 0x0c06061c */
if(!s->budget--) { s->failed_pc=0x0c06061cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606c8u,2);
goto P_0c06061e;
P_0c06061e: /* original e216, guest PC 0x0c06061e */
if(!s->budget--) { s->failed_pc=0x0c06061eu; return 0; }
r[2]=0x00000016u;
goto P_0c060620;
P_0c060620: /* original 5346, guest PC 0x0c060620 */
if(!s->budget--) { s->failed_pc=0x0c060620u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c060622;
P_0c060622: /* original e50f, guest PC 0x0c060622 */
if(!s->budget--) { s->failed_pc=0x0c060622u; return 0; }
r[5]=0x0000000fu;
goto P_0c060624;
P_0c060624: /* original 5147, guest PC 0x0c060624 */
if(!s->budget--) { s->failed_pc=0x0c060624u; return 0; }
r[1]=read(ram,r[4]+28,4);
goto P_0c060626;
P_0c060626: /* original 2369, guest PC 0x0c060626 */
if(!s->budget--) { s->failed_pc=0x0c060626u; return 0; }
r[3]&=r[6];
goto P_0c060628;
P_0c060628: /* original 2159, guest PC 0x0c060628 */
if(!s->budget--) { s->failed_pc=0x0c060628u; return 0; }
r[1]&=r[5];
goto P_0c06062a;
P_0c06062a: /* original 4118, guest PC 0x0c06062a */
if(!s->budget--) { s->failed_pc=0x0c06062au; return 0; }
r[1]<<=8;
goto P_0c06062c;
P_0c06062c: /* original 231b, guest PC 0x0c06062c */
if(!s->budget--) { s->failed_pc=0x0c06062cu; return 0; }
r[3]|=r[1];
goto P_0c06062e;
P_0c06062e: /* original 5148, guest PC 0x0c06062e */
if(!s->budget--) { s->failed_pc=0x0c06062eu; return 0; }
r[1]=read(ram,r[4]+32,4);
goto P_0c060630;
P_0c060630: /* original 21d9, guest PC 0x0c060630 */
if(!s->budget--) { s->failed_pc=0x0c060630u; return 0; }
r[1]&=r[13];
goto P_0c060632;
P_0c060632: /* original 4118, guest PC 0x0c060632 */
if(!s->budget--) { s->failed_pc=0x0c060632u; return 0; }
r[1]<<=8;
goto P_0c060634;
P_0c060634: /* original 4108, guest PC 0x0c060634 */
if(!s->budget--) { s->failed_pc=0x0c060634u; return 0; }
r[1]<<=2;
goto P_0c060636;
P_0c060636: /* original 4108, guest PC 0x0c060636 */
if(!s->budget--) { s->failed_pc=0x0c060636u; return 0; }
r[1]<<=2;
goto P_0c060638;
P_0c060638: /* original 231b, guest PC 0x0c060638 */
if(!s->budget--) { s->failed_pc=0x0c060638u; return 0; }
r[3]|=r[1];
goto P_0c06063a;
P_0c06063a: /* original 5149, guest PC 0x0c06063a */
if(!s->budget--) { s->failed_pc=0x0c06063au; return 0; }
r[1]=read(ram,r[4]+36,4);
goto P_0c06063c;
P_0c06063c: /* original 2169, guest PC 0x0c06063c */
if(!s->budget--) { s->failed_pc=0x0c06063cu; return 0; }
r[1]&=r[6];
goto P_0c06063e;
P_0c06063e: /* original 412c, guest PC 0x0c06063e */
if(!s->budget--) { s->failed_pc=0x0c06063eu; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c060640;
P_0c060640: /* original 231b, guest PC 0x0c060640 */
if(!s->budget--) { s->failed_pc=0x0c060640u; return 0; }
r[3]|=r[1];
goto P_0c060642;
P_0c060642: /* original d12b, guest PC 0x0c060642 */
if(!s->budget--) { s->failed_pc=0x0c060642u; return 0; }
r[1]=read(ram,0x0c0606f0u,4);
goto P_0c060644;
P_0c060644: /* original 2132, guest PC 0x0c060644 */
if(!s->budget--) { s->failed_pc=0x0c060644u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c060646;
P_0c060646: /* original 504d, guest PC 0x0c060646 */
if(!s->budget--) { s->failed_pc=0x0c060646u; return 0; }
r[0]=read(ram,r[4]+52,4);
goto P_0c060648;
P_0c060648: /* original c901, guest PC 0x0c060648 */
if(!s->budget--) { s->failed_pc=0x0c060648u; return 0; }
r[0]&=1u;
goto P_0c06064a;
P_0c06064a: /* original 6303, guest PC 0x0c06064a */
if(!s->budget--) { s->failed_pc=0x0c06064au; return 0; }
r[3]=r[0];
goto P_0c06064c;
P_0c06064c: /* original d229, guest PC 0x0c06064c */
if(!s->budget--) { s->failed_pc=0x0c06064cu; return 0; }
r[2]=read(ram,0x0c0606f4u,4);
goto P_0c06064e;
P_0c06064e: /* original 504e, guest PC 0x0c06064e */
if(!s->budget--) { s->failed_pc=0x0c06064eu; return 0; }
r[0]=read(ram,r[4]+56,4);
goto P_0c060650;
P_0c060650: /* original c901, guest PC 0x0c060650 */
if(!s->budget--) { s->failed_pc=0x0c060650u; return 0; }
r[0]&=1u;
goto P_0c060652;
P_0c060652: /* original 4000, guest PC 0x0c060652 */
if(!s->budget--) { s->failed_pc=0x0c060652u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c060654;
P_0c060654: /* original 230b, guest PC 0x0c060654 */
if(!s->budget--) { s->failed_pc=0x0c060654u; return 0; }
r[3]|=r[0];
goto P_0c060656;
P_0c060656: /* original 504f, guest PC 0x0c060656 */
if(!s->budget--) { s->failed_pc=0x0c060656u; return 0; }
r[0]=read(ram,r[4]+60,4);
goto P_0c060658;
P_0c060658: /* original c901, guest PC 0x0c060658 */
if(!s->budget--) { s->failed_pc=0x0c060658u; return 0; }
r[0]&=1u;
goto P_0c06065a;
P_0c06065a: /* original 4008, guest PC 0x0c06065a */
if(!s->budget--) { s->failed_pc=0x0c06065au; return 0; }
r[0]<<=2;
goto P_0c06065c;
P_0c06065c: /* original 230b, guest PC 0x0c06065c */
if(!s->budget--) { s->failed_pc=0x0c06065cu; return 0; }
r[3]|=r[0];
goto P_0c06065e;
P_0c06065e: /* original e040, guest PC 0x0c06065e */
if(!s->budget--) { s->failed_pc=0x0c06065eu; return 0; }
r[0]=0x00000040u;
goto P_0c060660;
P_0c060660: /* original 004e, guest PC 0x0c060660 */
if(!s->budget--) { s->failed_pc=0x0c060660u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060662;
P_0c060662: /* original c901, guest PC 0x0c060662 */
if(!s->budget--) { s->failed_pc=0x0c060662u; return 0; }
r[0]&=1u;
goto P_0c060664;
P_0c060664: /* original 4008, guest PC 0x0c060664 */
if(!s->budget--) { s->failed_pc=0x0c060664u; return 0; }
r[0]<<=2;
goto P_0c060666;
P_0c060666: /* original 4000, guest PC 0x0c060666 */
if(!s->budget--) { s->failed_pc=0x0c060666u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c060668;
P_0c060668: /* original 230b, guest PC 0x0c060668 */
if(!s->budget--) { s->failed_pc=0x0c060668u; return 0; }
r[3]|=r[0];
goto P_0c06066a;
P_0c06066a: /* original e044, guest PC 0x0c06066a */
if(!s->budget--) { s->failed_pc=0x0c06066au; return 0; }
r[0]=0x00000044u;
goto P_0c06066c;
P_0c06066c: /* original 004e, guest PC 0x0c06066c */
if(!s->budget--) { s->failed_pc=0x0c06066cu; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c06066e;
P_0c06066e: /* original 2509, guest PC 0x0c06066e */
if(!s->budget--) { s->failed_pc=0x0c06066eu; return 0; }
r[5]&=r[0];
goto P_0c060670;
P_0c060670: /* original 4508, guest PC 0x0c060670 */
if(!s->budget--) { s->failed_pc=0x0c060670u; return 0; }
r[5]<<=2;
goto P_0c060672;
P_0c060672: /* original 4508, guest PC 0x0c060672 */
if(!s->budget--) { s->failed_pc=0x0c060672u; return 0; }
r[5]<<=2;
goto P_0c060674;
P_0c060674: /* original 235b, guest PC 0x0c060674 */
if(!s->budget--) { s->failed_pc=0x0c060674u; return 0; }
r[3]|=r[5];
goto P_0c060676;
P_0c060676: /* original e06c, guest PC 0x0c060676 */
if(!s->budget--) { s->failed_pc=0x0c060676u; return 0; }
r[0]=0x0000006cu;
goto P_0c060678;
P_0c060678: /* original 004e, guest PC 0x0c060678 */
if(!s->budget--) { s->failed_pc=0x0c060678u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c06067a;
P_0c06067a: /* original c901, guest PC 0x0c06067a */
if(!s->budget--) { s->failed_pc=0x0c06067au; return 0; }
r[0]&=1u;
goto P_0c06067c;
P_0c06067c: /* original 4018, guest PC 0x0c06067c */
if(!s->budget--) { s->failed_pc=0x0c06067cu; return 0; }
r[0]<<=8;
goto P_0c06067e;
P_0c06067e: /* original 230b, guest PC 0x0c06067e */
if(!s->budget--) { s->failed_pc=0x0c06067eu; return 0; }
r[3]|=r[0];
goto P_0c060680;
P_0c060680: /* original e070, guest PC 0x0c060680 */
if(!s->budget--) { s->failed_pc=0x0c060680u; return 0; }
r[0]=0x00000070u;
goto P_0c060682;
P_0c060682: /* original 004e, guest PC 0x0c060682 */
if(!s->budget--) { s->failed_pc=0x0c060682u; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c060684;
P_0c060684: /* original c93f, guest PC 0x0c060684 */
if(!s->budget--) { s->failed_pc=0x0c060684u; return 0; }
r[0]&=63u;
goto P_0c060686;
P_0c060686: /* original 4028, guest PC 0x0c060686 */
if(!s->budget--) { s->failed_pc=0x0c060686u; return 0; }
r[0]<<=16;
goto P_0c060688;
P_0c060688: /* original 230b, guest PC 0x0c060688 */
if(!s->budget--) { s->failed_pc=0x0c060688u; return 0; }
r[3]|=r[0];
goto P_0c06068a;
P_0c06068a: /* original 2232, guest PC 0x0c06068a */
if(!s->budget--) { s->failed_pc=0x0c06068au; return 0; }
write(ram,r[2],r[3],4);
goto P_0c06068c;
P_0c06068c: /* original d01a, guest PC 0x0c06068c */
if(!s->budget--) { s->failed_pc=0x0c06068cu; return 0; }
r[0]=read(ram,0x0c0606f8u,4);
goto P_0c06068e;
P_0c06068e: /* original 6302, guest PC 0x0c06068e */
if(!s->budget--) { s->failed_pc=0x0c06068eu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c060690;
P_0c060690: /* original d10e, guest PC 0x0c060690 */
if(!s->budget--) { s->failed_pc=0x0c060690u; return 0; }
r[1]=read(ram,0x0c0606ccu,4);
goto P_0c060692;
P_0c060692: /* original 6012, guest PC 0x0c060692 */
if(!s->budget--) { s->failed_pc=0x0c060692u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c060694;
P_0c060694: /* original 303c, guest PC 0x0c060694 */
if(!s->budget--) { s->failed_pc=0x0c060694u; return 0; }
r[0]+=r[3];
goto P_0c060696;
P_0c060696: /* original d319, guest PC 0x0c060696 */
if(!s->budget--) { s->failed_pc=0x0c060696u; return 0; }
r[3]=read(ram,0x0c0606fcu,4);
goto P_0c060698;
P_0c060698: /* original 2302, guest PC 0x0c060698 */
if(!s->budget--) { s->failed_pc=0x0c060698u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c06069a;
P_0c06069a: /* original d019, guest PC 0x0c06069a */
if(!s->budget--) { s->failed_pc=0x0c06069au; return 0; }
r[0]=read(ram,0x0c060700u,4);
goto P_0c06069c;
P_0c06069c: /* original 6202, guest PC 0x0c06069c */
if(!s->budget--) { s->failed_pc=0x0c06069cu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c06069e;
P_0c06069e: /* original d30c, guest PC 0x0c06069e */
if(!s->budget--) { s->failed_pc=0x0c06069eu; return 0; }
r[3]=read(ram,0x0c0606d0u,4);
goto P_0c0606a0;
P_0c0606a0: /* original 6032, guest PC 0x0c0606a0 */
if(!s->budget--) { s->failed_pc=0x0c0606a0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0606a2;
P_0c0606a2: /* original 302c, guest PC 0x0c0606a2 */
if(!s->budget--) { s->failed_pc=0x0c0606a2u; return 0; }
r[0]+=r[2];
goto P_0c0606a4;
P_0c0606a4: /* original 71fc, guest PC 0x0c0606a4 */
if(!s->budget--) { s->failed_pc=0x0c0606a4u; return 0; }
r[1]+=0xfffffffcu;
goto P_0c0606a6;
P_0c0606a6: /* original 6212, guest PC 0x0c0606a6 */
if(!s->budget--) { s->failed_pc=0x0c0606a6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0606a8;
P_0c0606a8: /* original 5131, guest PC 0x0c0606a8 */
if(!s->budget--) { s->failed_pc=0x0c0606a8u; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c0606aa;
P_0c0606aa: /* original 312c, guest PC 0x0c0606aa */
if(!s->budget--) { s->failed_pc=0x0c0606aau; return 0; }
r[1]+=r[2];
goto P_0c0606ac;
P_0c0606ac: /* original d215, guest PC 0x0c0606ac */
if(!s->budget--) { s->failed_pc=0x0c0606acu; return 0; }
r[2]=read(ram,0x0c060704u,4);
goto P_0c0606ae;
P_0c0606ae: /* original 4128, guest PC 0x0c0606ae */
if(!s->budget--) { s->failed_pc=0x0c0606aeu; return 0; }
r[1]<<=16;
goto P_0c0606b0;
P_0c0606b0: /* original 201b, guest PC 0x0c0606b0 */
if(!s->budget--) { s->failed_pc=0x0c0606b0u; return 0; }
r[0]|=r[1];
goto P_0c0606b2;
P_0c0606b2: /* original 2202, guest PC 0x0c0606b2 */
if(!s->budget--) { s->failed_pc=0x0c0606b2u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0606b4;
P_0c0606b4: /* original d114, guest PC 0x0c0606b4 */
if(!s->budget--) { s->failed_pc=0x0c0606b4u; return 0; }
r[1]=read(ram,0x0c060708u,4);
goto P_0c0606b6;
P_0c0606b6: /* original 6012, guest PC 0x0c0606b6 */
if(!s->budget--) { s->failed_pc=0x0c0606b6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0606b8;
P_0c0606b8: /* original c802, guest PC 0x0c0606b8 */
if(!s->budget--) { s->failed_pc=0x0c0606b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0606ba;
P_0c0606ba: /* original 8931, guest PC 0x0c0606ba */
if(!s->budget--) { s->failed_pc=0x0c0606bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c060720; }
goto P_0c0606bc;
P_0c0606bc: /* original dc13, guest PC 0x0c0606bc */
if(!s->budget--) { s->failed_pc=0x0c0606bcu; return 0; }
r[12]=read(ram,0x0c06070cu,4);
goto P_0c0606be;
P_0c0606be: /* original 9e04, guest PC 0x0c0606be */
if(!s->budget--) { s->failed_pc=0x0c0606beu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0606cau,2);
goto P_0c0606c0;
P_0c0606c0: /* original a026, guest PC 0x0c0606c0 */
if(!s->budget--) { s->failed_pc=0x0c0606c0u; return 0; }
r[4]=r[14];
goto P_0c060710;
P_0c0606c2: /* original 64e3, guest PC 0x0c0606c2 */
if(!s->budget--) { s->failed_pc=0x0c0606c2u; return 0; }
r[4]=r[14];
if(!vf3_matrix_family(0x0c0606c4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0606c4u; return 0; } return 1;
P_0c060710: /* original 4c0b, guest PC 0x0c060710 */
if(!s->budget--) { s->failed_pc=0x0c060710u; return 0; }
target=r[12];
r[16]=code_base|0x0c060714u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060714u) { target=s->pc; goto dispatch; }
goto P_0c060714;
P_0c060712: /* original 0009, guest PC 0x0c060712 */
if(!s->budget--) { s->failed_pc=0x0c060712u; return 0; }
goto P_0c060714;
P_0c060714: /* original 20d8, guest PC 0x0c060714 */
if(!s->budget--) { s->failed_pc=0x0c060714u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c060716;
P_0c060716: /* original 89d3, guest PC 0x0c060716 */
if(!s->budget--) { s->failed_pc=0x0c060716u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0606c0; }
goto P_0c060718;
P_0c060718: /* original 4c0b, guest PC 0x0c060718 */
if(!s->budget--) { s->failed_pc=0x0c060718u; return 0; }
target=r[12];
r[16]=code_base|0x0c06071cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06071cu) { target=s->pc; goto dispatch; }
goto P_0c06071c;
P_0c06071a: /* original 64e3, guest PC 0x0c06071a */
if(!s->budget--) { s->failed_pc=0x0c06071au; return 0; }
r[4]=r[14];
goto P_0c06071c;
P_0c06071c: /* original 20d8, guest PC 0x0c06071c */
if(!s->budget--) { s->failed_pc=0x0c06071cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c06071e;
P_0c06071e: /* original 8bfb, guest PC 0x0c06071e */
if(!s->budget--) { s->failed_pc=0x0c06071eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c060718; }
goto P_0c060720;
P_0c060720: /* original de44, guest PC 0x0c060720 */
if(!s->budget--) { s->failed_pc=0x0c060720u; return 0; }
r[14]=read(ram,0x0c060834u,4);
goto P_0c060722;
P_0c060722: /* original d245, guest PC 0x0c060722 */
if(!s->budget--) { s->failed_pc=0x0c060722u; return 0; }
r[2]=read(ram,0x0c060838u,4);
goto P_0c060724;
P_0c060724: /* original 6022, guest PC 0x0c060724 */
if(!s->budget--) { s->failed_pc=0x0c060724u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c060726;
P_0c060726: /* original cb08, guest PC 0x0c060726 */
if(!s->budget--) { s->failed_pc=0x0c060726u; return 0; }
r[0]|=8u;
goto P_0c060728;
P_0c060728: /* original 9470, guest PC 0x0c060728 */
if(!s->budget--) { s->failed_pc=0x0c060728u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06080cu,2);
goto P_0c06072a;
P_0c06072a: /* original 4e0b, guest PC 0x0c06072a */
if(!s->budget--) { s->failed_pc=0x0c06072au; return 0; }
target=r[14];
r[16]=code_base|0x0c06072eu;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06072eu) { target=s->pc; goto dispatch; }
goto P_0c06072e;
P_0c06072c: /* original 6503, guest PC 0x0c06072c */
if(!s->budget--) { s->failed_pc=0x0c06072cu; return 0; }
r[5]=r[0];
goto P_0c06072e;
P_0c06072e: /* original d343, guest PC 0x0c06072e */
if(!s->budget--) { s->failed_pc=0x0c06072eu; return 0; }
r[3]=read(ram,0x0c06083cu,4);
goto P_0c060730;
P_0c060730: /* original 6032, guest PC 0x0c060730 */
if(!s->budget--) { s->failed_pc=0x0c060730u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c060732;
P_0c060732: /* original c801, guest PC 0x0c060732 */
if(!s->budget--) { s->failed_pc=0x0c060732u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c060734;
P_0c060734: /* original 8d03, guest PC 0x0c060734 */
if(!s->budget--) { s->failed_pc=0x0c060734u; return 0; }
cond=r[17]&1u;
r[4]=0x00000044u;
if(cond) { goto P_0c06073e; }
goto P_0c060738;
P_0c060736: /* original e444, guest PC 0x0c060736 */
if(!s->budget--) { s->failed_pc=0x0c060736u; return 0; }
r[4]=0x00000044u;
goto P_0c060738;
P_0c060738: /* original d541, guest PC 0x0c060738 */
if(!s->budget--) { s->failed_pc=0x0c060738u; return 0; }
r[5]=read(ram,0x0c060840u,4);
goto P_0c06073a;
P_0c06073a: /* original a001, guest PC 0x0c06073a */
if(!s->budget--) { s->failed_pc=0x0c06073au; return 0; }
goto P_0c060740;
P_0c06073c: /* original 0009, guest PC 0x0c06073c */
if(!s->budget--) { s->failed_pc=0x0c06073cu; return 0; }
goto P_0c06073e;
P_0c06073e: /* original e500, guest PC 0x0c06073e */
if(!s->budget--) { s->failed_pc=0x0c06073eu; return 0; }
r[5]=0x00000000u;
goto P_0c060740;
P_0c060740: /* original 4e0b, guest PC 0x0c060740 */
if(!s->budget--) { s->failed_pc=0x0c060740u; return 0; }
target=r[14];
r[16]=code_base|0x0c060744u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060744u) { target=s->pc; goto dispatch; }
goto P_0c060744;
P_0c060742: /* original 0009, guest PC 0x0c060742 */
if(!s->budget--) { s->failed_pc=0x0c060742u; return 0; }
goto P_0c060744;
P_0c060744: /* original e500, guest PC 0x0c060744 */
if(!s->budget--) { s->failed_pc=0x0c060744u; return 0; }
r[5]=0x00000000u;
goto P_0c060746;
P_0c060746: /* original 4e0b, guest PC 0x0c060746 */
if(!s->budget--) { s->failed_pc=0x0c060746u; return 0; }
target=r[14];
r[16]=code_base|0x0c06074au;
r[4]=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06074au) { target=s->pc; goto dispatch; }
goto P_0c06074a;
P_0c060748: /* original e45c, guest PC 0x0c060748 */
if(!s->budget--) { s->failed_pc=0x0c060748u; return 0; }
r[4]=0x0000005cu;
goto P_0c06074a;
P_0c06074a: /* original d23e, guest PC 0x0c06074a */
if(!s->budget--) { s->failed_pc=0x0c06074au; return 0; }
r[2]=read(ram,0x0c060844u,4);
goto P_0c06074c;
P_0c06074c: /* original 945f, guest PC 0x0c06074c */
if(!s->budget--) { s->failed_pc=0x0c06074cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06080eu,2);
goto P_0c06074e;
P_0c06074e: /* original 4e0b, guest PC 0x0c06074e */
if(!s->budget--) { s->failed_pc=0x0c06074eu; return 0; }
target=r[14];
r[16]=code_base|0x0c060752u;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060752u) { target=s->pc; goto dispatch; }
goto P_0c060752;
P_0c060750: /* original 6522, guest PC 0x0c060750 */
if(!s->budget--) { s->failed_pc=0x0c060750u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060752;
P_0c060752: /* original d33d, guest PC 0x0c060752 */
if(!s->budget--) { s->failed_pc=0x0c060752u; return 0; }
r[3]=read(ram,0x0c060848u,4);
goto P_0c060754;
P_0c060754: /* original 945c, guest PC 0x0c060754 */
if(!s->budget--) { s->failed_pc=0x0c060754u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060810u,2);
goto P_0c060756;
P_0c060756: /* original 4e0b, guest PC 0x0c060756 */
if(!s->budget--) { s->failed_pc=0x0c060756u; return 0; }
target=r[14];
r[16]=code_base|0x0c06075au;
tmp=read(ram,r[3],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06075au) { target=s->pc; goto dispatch; }
goto P_0c06075a;
P_0c060758: /* original 6532, guest PC 0x0c060758 */
if(!s->budget--) { s->failed_pc=0x0c060758u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06075a;
P_0c06075a: /* original d23c, guest PC 0x0c06075a */
if(!s->budget--) { s->failed_pc=0x0c06075au; return 0; }
r[2]=read(ram,0x0c06084cu,4);
goto P_0c06075c;
P_0c06075c: /* original 9459, guest PC 0x0c06075c */
if(!s->budget--) { s->failed_pc=0x0c06075cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060812u,2);
goto P_0c06075e;
P_0c06075e: /* original 4e0b, guest PC 0x0c06075e */
if(!s->budget--) { s->failed_pc=0x0c06075eu; return 0; }
target=r[14];
r[16]=code_base|0x0c060762u;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060762u) { target=s->pc; goto dispatch; }
goto P_0c060762;
P_0c060760: /* original 6522, guest PC 0x0c060760 */
if(!s->budget--) { s->failed_pc=0x0c060760u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060762;
P_0c060762: /* original d33b, guest PC 0x0c060762 */
if(!s->budget--) { s->failed_pc=0x0c060762u; return 0; }
r[3]=read(ram,0x0c060850u,4);
goto P_0c060764;
P_0c060764: /* original 9456, guest PC 0x0c060764 */
if(!s->budget--) { s->failed_pc=0x0c060764u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060814u,2);
goto P_0c060766;
P_0c060766: /* original 4e0b, guest PC 0x0c060766 */
if(!s->budget--) { s->failed_pc=0x0c060766u; return 0; }
target=r[14];
r[16]=code_base|0x0c06076au;
tmp=read(ram,r[3],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06076au) { target=s->pc; goto dispatch; }
goto P_0c06076a;
P_0c060768: /* original 6532, guest PC 0x0c060768 */
if(!s->budget--) { s->failed_pc=0x0c060768u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06076a;
P_0c06076a: /* original d23a, guest PC 0x0c06076a */
if(!s->budget--) { s->failed_pc=0x0c06076au; return 0; }
r[2]=read(ram,0x0c060854u,4);
goto P_0c06076c;
P_0c06076c: /* original 9453, guest PC 0x0c06076c */
if(!s->budget--) { s->failed_pc=0x0c06076cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060816u,2);
goto P_0c06076e;
P_0c06076e: /* original 4e0b, guest PC 0x0c06076e */
if(!s->budget--) { s->failed_pc=0x0c06076eu; return 0; }
target=r[14];
r[16]=code_base|0x0c060772u;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060772u) { target=s->pc; goto dispatch; }
goto P_0c060772;
P_0c060770: /* original 6522, guest PC 0x0c060770 */
if(!s->budget--) { s->failed_pc=0x0c060770u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060772;
P_0c060772: /* original d339, guest PC 0x0c060772 */
if(!s->budget--) { s->failed_pc=0x0c060772u; return 0; }
r[3]=read(ram,0x0c060858u,4);
goto P_0c060774;
P_0c060774: /* original 9450, guest PC 0x0c060774 */
if(!s->budget--) { s->failed_pc=0x0c060774u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c060818u,2);
goto P_0c060776;
P_0c060776: /* original 4e0b, guest PC 0x0c060776 */
if(!s->budget--) { s->failed_pc=0x0c060776u; return 0; }
target=r[14];
r[16]=code_base|0x0c06077au;
tmp=read(ram,r[3],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06077au) { target=s->pc; goto dispatch; }
goto P_0c06077a;
P_0c060778: /* original 6532, guest PC 0x0c060778 */
if(!s->budget--) { s->failed_pc=0x0c060778u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06077a;
P_0c06077a: /* original d238, guest PC 0x0c06077a */
if(!s->budget--) { s->failed_pc=0x0c06077au; return 0; }
r[2]=read(ram,0x0c06085cu,4);
goto P_0c06077c;
P_0c06077c: /* original 944d, guest PC 0x0c06077c */
if(!s->budget--) { s->failed_pc=0x0c06077cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06081au,2);
goto P_0c06077e;
P_0c06077e: /* original 4e0b, guest PC 0x0c06077e */
if(!s->budget--) { s->failed_pc=0x0c06077eu; return 0; }
target=r[14];
r[16]=code_base|0x0c060782u;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060782u) { target=s->pc; goto dispatch; }
goto P_0c060782;
P_0c060780: /* original 6522, guest PC 0x0c060780 */
if(!s->budget--) { s->failed_pc=0x0c060780u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060782;
P_0c060782: /* original d337, guest PC 0x0c060782 */
if(!s->budget--) { s->failed_pc=0x0c060782u; return 0; }
r[3]=read(ram,0x0c060860u,4);
goto P_0c060784;
P_0c060784: /* original 944a, guest PC 0x0c060784 */
if(!s->budget--) { s->failed_pc=0x0c060784u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06081cu,2);
goto P_0c060786;
P_0c060786: /* original 4e0b, guest PC 0x0c060786 */
if(!s->budget--) { s->failed_pc=0x0c060786u; return 0; }
target=r[14];
r[16]=code_base|0x0c06078au;
tmp=read(ram,r[3],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06078au) { target=s->pc; goto dispatch; }
goto P_0c06078a;
P_0c060788: /* original 6532, guest PC 0x0c060788 */
if(!s->budget--) { s->failed_pc=0x0c060788u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c06078a;
P_0c06078a: /* original d236, guest PC 0x0c06078a */
if(!s->budget--) { s->failed_pc=0x0c06078au; return 0; }
r[2]=read(ram,0x0c060864u,4);
goto P_0c06078c;
P_0c06078c: /* original 9447, guest PC 0x0c06078c */
if(!s->budget--) { s->failed_pc=0x0c06078cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06081eu,2);
goto P_0c06078e;
P_0c06078e: /* original 4e0b, guest PC 0x0c06078e */
if(!s->budget--) { s->failed_pc=0x0c06078eu; return 0; }
target=r[14];
r[16]=code_base|0x0c060792u;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c060792u) { target=s->pc; goto dispatch; }
goto P_0c060792;
P_0c060790: /* original 6522, guest PC 0x0c060790 */
if(!s->budget--) { s->failed_pc=0x0c060790u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c060792;
P_0c060792: /* original 4f26, guest PC 0x0c060792 */
if(!s->budget--) { s->failed_pc=0x0c060792u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c060794;
P_0c060794: /* original 6cf6, guest PC 0x0c060794 */
if(!s->budget--) { s->failed_pc=0x0c060794u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c060796;
P_0c060796: /* original 6df6, guest PC 0x0c060796 */
if(!s->budget--) { s->failed_pc=0x0c060796u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c060798;
P_0c060798: /* original 000b, guest PC 0x0c060798 */
if(!s->budget--) { s->failed_pc=0x0c060798u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06079a: /* original 6ef6, guest PC 0x0c06079a */
if(!s->budget--) { s->failed_pc=0x0c06079au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06079cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06079cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
