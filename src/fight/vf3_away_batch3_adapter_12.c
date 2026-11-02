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
int vf3_away_batch3_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c043562u: goto P_0c043562;
case 0x0c043564u: goto P_0c043564;
case 0x0c043566u: goto P_0c043566;
case 0x0c043568u: goto P_0c043568;
case 0x0c04356au: goto P_0c04356a;
case 0x0c04356cu: goto P_0c04356c;
case 0x0c04356eu: goto P_0c04356e;
case 0x0c043570u: goto P_0c043570;
case 0x0c043572u: goto P_0c043572;
case 0x0c043574u: goto P_0c043574;
case 0x0c043576u: goto P_0c043576;
case 0x0c043578u: goto P_0c043578;
case 0x0c04357au: goto P_0c04357a;
case 0x0c04357cu: goto P_0c04357c;
case 0x0c04357eu: goto P_0c04357e;
case 0x0c043580u: goto P_0c043580;
case 0x0c043582u: goto P_0c043582;
case 0x0c043584u: goto P_0c043584;
case 0x0c043586u: goto P_0c043586;
case 0x0c043588u: goto P_0c043588;
case 0x0c04358au: goto P_0c04358a;
case 0x0c04358cu: goto P_0c04358c;
case 0x0c04358eu: goto P_0c04358e;
case 0x0c043590u: goto P_0c043590;
case 0x0c043592u: goto P_0c043592;
case 0x0c043594u: goto P_0c043594;
case 0x0c043596u: goto P_0c043596;
case 0x0c043598u: goto P_0c043598;
case 0x0c04359au: goto P_0c04359a;
case 0x0c04359cu: goto P_0c04359c;
case 0x0c04359eu: goto P_0c04359e;
case 0x0c0435a0u: goto P_0c0435a0;
case 0x0c0435a2u: goto P_0c0435a2;
case 0x0c0435a4u: goto P_0c0435a4;
case 0x0c0435a6u: goto P_0c0435a6;
case 0x0c0435a8u: goto P_0c0435a8;
case 0x0c0435aau: goto P_0c0435aa;
case 0x0c0435acu: goto P_0c0435ac;
case 0x0c0435aeu: goto P_0c0435ae;
case 0x0c0435b0u: goto P_0c0435b0;
case 0x0c0435b2u: goto P_0c0435b2;
case 0x0c0435b4u: goto P_0c0435b4;
case 0x0c0435b6u: goto P_0c0435b6;
case 0x0c0435b8u: goto P_0c0435b8;
case 0x0c0435bau: goto P_0c0435ba;
case 0x0c0435bcu: goto P_0c0435bc;
case 0x0c0435beu: goto P_0c0435be;
case 0x0c0435c0u: goto P_0c0435c0;
case 0x0c0435c2u: goto P_0c0435c2;
case 0x0c0435c4u: goto P_0c0435c4;
case 0x0c0435c6u: goto P_0c0435c6;
case 0x0c0435c8u: goto P_0c0435c8;
case 0x0c0435cau: goto P_0c0435ca;
case 0x0c0435ccu: goto P_0c0435cc;
case 0x0c0435ceu: goto P_0c0435ce;
case 0x0c0435d0u: goto P_0c0435d0;
case 0x0c0435d2u: goto P_0c0435d2;
case 0x0c0435d4u: goto P_0c0435d4;
case 0x0c0435d6u: goto P_0c0435d6;
case 0x0c0435d8u: goto P_0c0435d8;
case 0x0c0435dau: goto P_0c0435da;
case 0x0c0435dcu: goto P_0c0435dc;
case 0x0c0435deu: goto P_0c0435de;
case 0x0c0435e0u: goto P_0c0435e0;
case 0x0c0435e2u: goto P_0c0435e2;
case 0x0c0435e4u: goto P_0c0435e4;
case 0x0c0435e6u: goto P_0c0435e6;
case 0x0c0435e8u: goto P_0c0435e8;
case 0x0c0435eau: goto P_0c0435ea;
case 0x0c0435ecu: goto P_0c0435ec;
case 0x0c0435eeu: goto P_0c0435ee;
case 0x0c0435f0u: goto P_0c0435f0;
case 0x0c0435f2u: goto P_0c0435f2;
case 0x0c0435f4u: goto P_0c0435f4;
case 0x0c0435f6u: goto P_0c0435f6;
case 0x0c0435f8u: goto P_0c0435f8;
case 0x0c0435fau: goto P_0c0435fa;
case 0x0c0435fcu: goto P_0c0435fc;
case 0x0c0435feu: goto P_0c0435fe;
case 0x0c043600u: goto P_0c043600;
case 0x0c043602u: goto P_0c043602;
case 0x0c043604u: goto P_0c043604;
case 0x0c043606u: goto P_0c043606;
case 0x0c043608u: goto P_0c043608;
case 0x0c04360au: goto P_0c04360a;
case 0x0c04360cu: goto P_0c04360c;
case 0x0c04360eu: goto P_0c04360e;
case 0x0c043610u: goto P_0c043610;
case 0x0c043612u: goto P_0c043612;
case 0x0c043614u: goto P_0c043614;
case 0x0c043616u: goto P_0c043616;
case 0x0c043618u: goto P_0c043618;
case 0x0c04361au: goto P_0c04361a;
case 0x0c04361cu: goto P_0c04361c;
case 0x0c04361eu: goto P_0c04361e;
case 0x0c043620u: goto P_0c043620;
case 0x0c043622u: goto P_0c043622;
case 0x0c043624u: goto P_0c043624;
case 0x0c043626u: goto P_0c043626;
case 0x0c043628u: goto P_0c043628;
case 0x0c04362au: goto P_0c04362a;
case 0x0c04362cu: goto P_0c04362c;
case 0x0c04362eu: goto P_0c04362e;
case 0x0c043630u: goto P_0c043630;
case 0x0c043632u: goto P_0c043632;
case 0x0c043634u: goto P_0c043634;
case 0x0c043636u: goto P_0c043636;
case 0x0c043638u: goto P_0c043638;
case 0x0c04363au: goto P_0c04363a;
case 0x0c04363cu: goto P_0c04363c;
case 0x0c04363eu: goto P_0c04363e;
case 0x0c043640u: goto P_0c043640;
case 0x0c043642u: goto P_0c043642;
case 0x0c043644u: goto P_0c043644;
case 0x0c043646u: goto P_0c043646;
case 0x0c043648u: goto P_0c043648;
case 0x0c04364au: goto P_0c04364a;
case 0x0c04364cu: goto P_0c04364c;
case 0x0c04364eu: goto P_0c04364e;
case 0x0c043650u: goto P_0c043650;
case 0x0c043652u: goto P_0c043652;
case 0x0c043654u: goto P_0c043654;
case 0x0c043656u: goto P_0c043656;
case 0x0c043658u: goto P_0c043658;
case 0x0c04365au: goto P_0c04365a;
case 0x0c04365cu: goto P_0c04365c;
case 0x0c04365eu: goto P_0c04365e;
case 0x0c043660u: goto P_0c043660;
case 0x0c043662u: goto P_0c043662;
case 0x0c043664u: goto P_0c043664;
case 0x0c043666u: goto P_0c043666;
case 0x0c043668u: goto P_0c043668;
case 0x0c04366au: goto P_0c04366a;
case 0x0c04366cu: goto P_0c04366c;
case 0x0c04366eu: goto P_0c04366e;
case 0x0c043670u: goto P_0c043670;
case 0x0c043672u: goto P_0c043672;
case 0x0c043674u: goto P_0c043674;
case 0x0c043676u: goto P_0c043676;
case 0x0c043678u: goto P_0c043678;
case 0x0c04367au: goto P_0c04367a;
case 0x0c04367cu: goto P_0c04367c;
case 0x0c04367eu: goto P_0c04367e;
case 0x0c043680u: goto P_0c043680;
case 0x0c043682u: goto P_0c043682;
case 0x0c043684u: goto P_0c043684;
case 0x0c043686u: goto P_0c043686;
case 0x0c043688u: goto P_0c043688;
case 0x0c04368au: goto P_0c04368a;
case 0x0c04368cu: goto P_0c04368c;
case 0x0c04368eu: goto P_0c04368e;
case 0x0c043690u: goto P_0c043690;
case 0x0c043692u: goto P_0c043692;
case 0x0c043694u: goto P_0c043694;
case 0x0c043696u: goto P_0c043696;
case 0x0c043698u: goto P_0c043698;
case 0x0c04369au: goto P_0c04369a;
case 0x0c04369cu: goto P_0c04369c;
case 0x0c04369eu: goto P_0c04369e;
case 0x0c0436a0u: goto P_0c0436a0;
case 0x0c0436a2u: goto P_0c0436a2;
case 0x0c0436a4u: goto P_0c0436a4;
case 0x0c0436a6u: goto P_0c0436a6;
case 0x0c0436a8u: goto P_0c0436a8;
case 0x0c0436aau: goto P_0c0436aa;
case 0x0c0436acu: goto P_0c0436ac;
case 0x0c0436aeu: goto P_0c0436ae;
case 0x0c0436b0u: goto P_0c0436b0;
case 0x0c0436b2u: goto P_0c0436b2;
case 0x0c0436b4u: goto P_0c0436b4;
case 0x0c0436b6u: goto P_0c0436b6;
case 0x0c0436b8u: goto P_0c0436b8;
case 0x0c0436bau: goto P_0c0436ba;
case 0x0c0436bcu: goto P_0c0436bc;
case 0x0c0436beu: goto P_0c0436be;
case 0x0c0436c0u: goto P_0c0436c0;
case 0x0c0436c2u: goto P_0c0436c2;
case 0x0c0436c4u: goto P_0c0436c4;
case 0x0c0436c6u: goto P_0c0436c6;
case 0x0c0436c8u: goto P_0c0436c8;
case 0x0c0436cau: goto P_0c0436ca;
case 0x0c0436ccu: goto P_0c0436cc;
case 0x0c0436ceu: goto P_0c0436ce;
case 0x0c0436d0u: goto P_0c0436d0;
case 0x0c0436d2u: goto P_0c0436d2;
case 0x0c0436d4u: goto P_0c0436d4;
case 0x0c0436d6u: goto P_0c0436d6;
case 0x0c0436d8u: goto P_0c0436d8;
case 0x0c0436dau: goto P_0c0436da;
case 0x0c0436dcu: goto P_0c0436dc;
case 0x0c0436deu: goto P_0c0436de;
case 0x0c0436e0u: goto P_0c0436e0;
case 0x0c0436e2u: goto P_0c0436e2;
case 0x0c0436e4u: goto P_0c0436e4;
case 0x0c0436e6u: goto P_0c0436e6;
case 0x0c0436e8u: goto P_0c0436e8;
case 0x0c0436eau: goto P_0c0436ea;
case 0x0c0436ecu: goto P_0c0436ec;
case 0x0c0436eeu: goto P_0c0436ee;
case 0x0c0436f0u: goto P_0c0436f0;
case 0x0c0436f2u: goto P_0c0436f2;
case 0x0c0436f4u: goto P_0c0436f4;
case 0x0c0436f6u: goto P_0c0436f6;
case 0x0c0436f8u: goto P_0c0436f8;
case 0x0c0436fau: goto P_0c0436fa;
case 0x0c0436fcu: goto P_0c0436fc;
case 0x0c0436feu: goto P_0c0436fe;
case 0x0c043700u: goto P_0c043700;
case 0x0c043702u: goto P_0c043702;
case 0x0c043704u: goto P_0c043704;
case 0x0c043706u: goto P_0c043706;
case 0x0c043708u: goto P_0c043708;
case 0x0c04370au: goto P_0c04370a;
case 0x0c04370cu: goto P_0c04370c;
case 0x0c04370eu: goto P_0c04370e;
case 0x0c043710u: goto P_0c043710;
case 0x0c043712u: goto P_0c043712;
case 0x0c043714u: goto P_0c043714;
case 0x0c043716u: goto P_0c043716;
case 0x0c043718u: goto P_0c043718;
case 0x0c043724u: goto P_0c043724;
case 0x0c043726u: goto P_0c043726;
case 0x0c043728u: goto P_0c043728;
case 0x0c04372au: goto P_0c04372a;
case 0x0c04372cu: goto P_0c04372c;
case 0x0c04372eu: goto P_0c04372e;
case 0x0c043730u: goto P_0c043730;
case 0x0c043732u: goto P_0c043732;
case 0x0c043734u: goto P_0c043734;
case 0x0c043736u: goto P_0c043736;
case 0x0c043738u: goto P_0c043738;
case 0x0c04373au: goto P_0c04373a;
case 0x0c04373cu: goto P_0c04373c;
case 0x0c04373eu: goto P_0c04373e;
case 0x0c043740u: goto P_0c043740;
case 0x0c043742u: goto P_0c043742;
case 0x0c043744u: goto P_0c043744;
case 0x0c043746u: goto P_0c043746;
case 0x0c043748u: goto P_0c043748;
case 0x0c04374au: goto P_0c04374a;
case 0x0c04374cu: goto P_0c04374c;
case 0x0c04374eu: goto P_0c04374e;
case 0x0c043750u: goto P_0c043750;
case 0x0c043752u: goto P_0c043752;
case 0x0c043754u: goto P_0c043754;
case 0x0c043756u: goto P_0c043756;
case 0x0c043758u: goto P_0c043758;
case 0x0c04375au: goto P_0c04375a;
case 0x0c04375cu: goto P_0c04375c;
case 0x0c04375eu: goto P_0c04375e;
case 0x0c043760u: goto P_0c043760;
case 0x0c043762u: goto P_0c043762;
case 0x0c043764u: goto P_0c043764;
case 0x0c043766u: goto P_0c043766;
case 0x0c043768u: goto P_0c043768;
case 0x0c04376au: goto P_0c04376a;
case 0x0c04376cu: goto P_0c04376c;
case 0x0c04376eu: goto P_0c04376e;
case 0x0c043770u: goto P_0c043770;
case 0x0c043772u: goto P_0c043772;
case 0x0c043774u: goto P_0c043774;
case 0x0c043776u: goto P_0c043776;
case 0x0c043778u: goto P_0c043778;
case 0x0c04377au: goto P_0c04377a;
case 0x0c04377cu: goto P_0c04377c;
case 0x0c04377eu: goto P_0c04377e;
case 0x0c043780u: goto P_0c043780;
case 0x0c043782u: goto P_0c043782;
case 0x0c043784u: goto P_0c043784;
case 0x0c043786u: goto P_0c043786;
case 0x0c043788u: goto P_0c043788;
case 0x0c04378au: goto P_0c04378a;
case 0x0c04378cu: goto P_0c04378c;
case 0x0c04378eu: goto P_0c04378e;
case 0x0c043790u: goto P_0c043790;
case 0x0c043792u: goto P_0c043792;
case 0x0c043794u: goto P_0c043794;
case 0x0c043796u: goto P_0c043796;
case 0x0c043798u: goto P_0c043798;
case 0x0c04379au: goto P_0c04379a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c043562: /* original 76ff, guest PC 0x0c043562 */
if(!s->budget--) { s->failed_pc=0x0c043562u; return 0; }
r[6]+=0xffffffffu;
goto P_0c043564;
P_0c043564: /* original 4615, guest PC 0x0c043564 */
if(!s->budget--) { s->failed_pc=0x0c043564u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c043566;
P_0c043566: /* original 89da, guest PC 0x0c043566 */
if(!s->budget--) { s->failed_pc=0x0c043566u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c04351eu,s,ram); }
goto P_0c043568;
P_0c043568: /* original e001, guest PC 0x0c043568 */
if(!s->budget--) { s->failed_pc=0x0c043568u; return 0; }
r[0]=0x00000001u;
goto P_0c04356a;
P_0c04356a: /* original 000b, guest PC 0x0c04356a */
if(!s->budget--) { s->failed_pc=0x0c04356au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04356c: /* original 6ef6, guest PC 0x0c04356c */
if(!s->budget--) { s->failed_pc=0x0c04356cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04356e;
P_0c04356e: /* original 6340, guest PC 0x0c04356e */
if(!s->budget--) { s->failed_pc=0x0c04356eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c043570;
P_0c043570: /* original 2338, guest PC 0x0c043570 */
if(!s->budget--) { s->failed_pc=0x0c043570u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c043572;
P_0c043572: /* original 8906, guest PC 0x0c043572 */
if(!s->budget--) { s->failed_pc=0x0c043572u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043582; }
goto P_0c043574;
P_0c043574: /* original 6254, guest PC 0x0c043574 */
if(!s->budget--) { s->failed_pc=0x0c043574u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[2]=tmp;
goto P_0c043576;
P_0c043576: /* original 6344, guest PC 0x0c043576 */
if(!s->budget--) { s->failed_pc=0x0c043576u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[3]=tmp;
goto P_0c043578;
P_0c043578: /* original 3320, guest PC 0x0c043578 */
if(!s->budget--) { s->failed_pc=0x0c043578u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c04357a;
P_0c04357a: /* original 8b05, guest PC 0x0c04357a */
if(!s->budget--) { s->failed_pc=0x0c04357au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043588; }
goto P_0c04357c;
P_0c04357c: /* original 6240, guest PC 0x0c04357c */
if(!s->budget--) { s->failed_pc=0x0c04357cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c04357e;
P_0c04357e: /* original 2228, guest PC 0x0c04357e */
if(!s->budget--) { s->failed_pc=0x0c04357eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c043580;
P_0c043580: /* original 8bf8, guest PC 0x0c043580 */
if(!s->budget--) { s->failed_pc=0x0c043580u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043574; }
goto P_0c043582;
P_0c043582: /* original 6150, guest PC 0x0c043582 */
if(!s->budget--) { s->failed_pc=0x0c043582u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[1]=tmp;
goto P_0c043584;
P_0c043584: /* original 2118, guest PC 0x0c043584 */
if(!s->budget--) { s->failed_pc=0x0c043584u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c043586;
P_0c043586: /* original 8901, guest PC 0x0c043586 */
if(!s->budget--) { s->failed_pc=0x0c043586u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04358c; }
goto P_0c043588;
P_0c043588: /* original 000b, guest PC 0x0c043588 */
if(!s->budget--) { s->failed_pc=0x0c043588u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c04358a: /* original e000, guest PC 0x0c04358a */
if(!s->budget--) { s->failed_pc=0x0c04358au; return 0; }
r[0]=0x00000000u;
goto P_0c04358c;
P_0c04358c: /* original e001, guest PC 0x0c04358c */
if(!s->budget--) { s->failed_pc=0x0c04358cu; return 0; }
r[0]=0x00000001u;
goto P_0c04358e;
P_0c04358e: /* original 000b, guest PC 0x0c04358e */
if(!s->budget--) { s->failed_pc=0x0c04358eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043590: /* original 0009, guest PC 0x0c043590 */
if(!s->budget--) { s->failed_pc=0x0c043590u; return 0; }
goto P_0c043592;
P_0c043592: /* original a017, guest PC 0x0c043592 */
if(!s->budget--) { s->failed_pc=0x0c043592u; return 0; }
goto P_0c0435c4;
P_0c043594: /* original 0009, guest PC 0x0c043594 */
if(!s->budget--) { s->failed_pc=0x0c043594u; return 0; }
goto P_0c043596;
P_0c043596: /* original 6644, guest PC 0x0c043596 */
if(!s->budget--) { s->failed_pc=0x0c043596u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[6]=tmp;
goto P_0c043598;
P_0c043598: /* original e761, guest PC 0x0c043598 */
if(!s->budget--) { s->failed_pc=0x0c043598u; return 0; }
r[7]=0x00000061u;
goto P_0c04359a;
P_0c04359a: /* original 606e, guest PC 0x0c04359a */
if(!s->budget--) { s->failed_pc=0x0c04359au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c04359c;
P_0c04359c: /* original 3073, guest PC 0x0c04359c */
if(!s->budget--) { s->failed_pc=0x0c04359cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[7])!=0);
goto P_0c04359e;
P_0c04359e: /* original 8b03, guest PC 0x0c04359e */
if(!s->budget--) { s->failed_pc=0x0c04359eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0435a8; }
goto P_0c0435a0;
P_0c0435a0: /* original e27a, guest PC 0x0c0435a0 */
if(!s->budget--) { s->failed_pc=0x0c0435a0u; return 0; }
r[2]=0x0000007au;
goto P_0c0435a2;
P_0c0435a2: /* original 3027, guest PC 0x0c0435a2 */
if(!s->budget--) { s->failed_pc=0x0c0435a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c0435a4;
P_0c0435a4: /* original 8900, guest PC 0x0c0435a4 */
if(!s->budget--) { s->failed_pc=0x0c0435a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0435a8; }
goto P_0c0435a6;
P_0c0435a6: /* original 76e0, guest PC 0x0c0435a6 */
if(!s->budget--) { s->failed_pc=0x0c0435a6u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c0435a8;
P_0c0435a8: /* original 6163, guest PC 0x0c0435a8 */
if(!s->budget--) { s->failed_pc=0x0c0435a8u; return 0; }
r[1]=r[6];
goto P_0c0435aa;
P_0c0435aa: /* original 6654, guest PC 0x0c0435aa */
if(!s->budget--) { s->failed_pc=0x0c0435aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[6]=tmp;
goto P_0c0435ac;
P_0c0435ac: /* original 606e, guest PC 0x0c0435ac */
if(!s->budget--) { s->failed_pc=0x0c0435acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c0435ae;
P_0c0435ae: /* original 3073, guest PC 0x0c0435ae */
if(!s->budget--) { s->failed_pc=0x0c0435aeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[7])!=0);
goto P_0c0435b0;
P_0c0435b0: /* original 8b03, guest PC 0x0c0435b0 */
if(!s->budget--) { s->failed_pc=0x0c0435b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0435ba; }
goto P_0c0435b2;
P_0c0435b2: /* original e27a, guest PC 0x0c0435b2 */
if(!s->budget--) { s->failed_pc=0x0c0435b2u; return 0; }
r[2]=0x0000007au;
goto P_0c0435b4;
P_0c0435b4: /* original 3027, guest PC 0x0c0435b4 */
if(!s->budget--) { s->failed_pc=0x0c0435b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[2])!=0);
goto P_0c0435b6;
P_0c0435b6: /* original 8900, guest PC 0x0c0435b6 */
if(!s->budget--) { s->failed_pc=0x0c0435b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0435ba; }
goto P_0c0435b8;
P_0c0435b8: /* original 76e0, guest PC 0x0c0435b8 */
if(!s->budget--) { s->failed_pc=0x0c0435b8u; return 0; }
r[6]+=0xffffffe0u;
goto P_0c0435ba;
P_0c0435ba: /* original 6763, guest PC 0x0c0435ba */
if(!s->budget--) { s->failed_pc=0x0c0435bau; return 0; }
r[7]=r[6];
goto P_0c0435bc;
P_0c0435bc: /* original 677e, guest PC 0x0c0435bc */
if(!s->budget--) { s->failed_pc=0x0c0435bcu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[7];
goto P_0c0435be;
P_0c0435be: /* original 611e, guest PC 0x0c0435be */
if(!s->budget--) { s->failed_pc=0x0c0435beu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[1];
goto P_0c0435c0;
P_0c0435c0: /* original 3170, guest PC 0x0c0435c0 */
if(!s->budget--) { s->failed_pc=0x0c0435c0u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[7])!=0);
goto P_0c0435c2;
P_0c0435c2: /* original 8b05, guest PC 0x0c0435c2 */
if(!s->budget--) { s->failed_pc=0x0c0435c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0435d0; }
goto P_0c0435c4;
P_0c0435c4: /* original 6240, guest PC 0x0c0435c4 */
if(!s->budget--) { s->failed_pc=0x0c0435c4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[2]=tmp;
goto P_0c0435c6;
P_0c0435c6: /* original 2228, guest PC 0x0c0435c6 */
if(!s->budget--) { s->failed_pc=0x0c0435c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0435c8;
P_0c0435c8: /* original 8be5, guest PC 0x0c0435c8 */
if(!s->budget--) { s->failed_pc=0x0c0435c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043596; }
goto P_0c0435ca;
P_0c0435ca: /* original 6150, guest PC 0x0c0435ca */
if(!s->budget--) { s->failed_pc=0x0c0435cau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[1]=tmp;
goto P_0c0435cc;
P_0c0435cc: /* original 2118, guest PC 0x0c0435cc */
if(!s->budget--) { s->failed_pc=0x0c0435ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0435ce;
P_0c0435ce: /* original 8901, guest PC 0x0c0435ce */
if(!s->budget--) { s->failed_pc=0x0c0435ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0435d4; }
goto P_0c0435d0;
P_0c0435d0: /* original 000b, guest PC 0x0c0435d0 */
if(!s->budget--) { s->failed_pc=0x0c0435d0u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c0435d2: /* original e000, guest PC 0x0c0435d2 */
if(!s->budget--) { s->failed_pc=0x0c0435d2u; return 0; }
r[0]=0x00000000u;
goto P_0c0435d4;
P_0c0435d4: /* original e001, guest PC 0x0c0435d4 */
if(!s->budget--) { s->failed_pc=0x0c0435d4u; return 0; }
r[0]=0x00000001u;
goto P_0c0435d6;
P_0c0435d6: /* original 000b, guest PC 0x0c0435d6 */
if(!s->budget--) { s->failed_pc=0x0c0435d6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0435d8: /* original 0009, guest PC 0x0c0435d8 */
if(!s->budget--) { s->failed_pc=0x0c0435d8u; return 0; }
goto P_0c0435da;
P_0c0435da: /* original 6340, guest PC 0x0c0435da */
if(!s->budget--) { s->failed_pc=0x0c0435dau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0435dc;
P_0c0435dc: /* original 2338, guest PC 0x0c0435dc */
if(!s->budget--) { s->failed_pc=0x0c0435dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0435de;
P_0c0435de: /* original 8d11, guest PC 0x0c0435de */
if(!s->budget--) { s->failed_pc=0x0c0435deu; return 0; }
cond=r[17]&1u;
r[7]=0x00000000u;
if(cond) { goto P_0c043604; }
goto P_0c0435e2;
P_0c0435e0: /* original e700, guest PC 0x0c0435e0 */
if(!s->budget--) { s->failed_pc=0x0c0435e0u; return 0; }
r[7]=0x00000000u;
goto P_0c0435e2;
P_0c0435e2: /* original 6653, guest PC 0x0c0435e2 */
if(!s->budget--) { s->failed_pc=0x0c0435e2u; return 0; }
r[6]=r[5];
goto P_0c0435e4;
P_0c0435e4: /* original 6360, guest PC 0x0c0435e4 */
if(!s->budget--) { s->failed_pc=0x0c0435e4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0435e6;
P_0c0435e6: /* original 2338, guest PC 0x0c0435e6 */
if(!s->budget--) { s->failed_pc=0x0c0435e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0435e8;
P_0c0435e8: /* original 8907, guest PC 0x0c0435e8 */
if(!s->budget--) { s->failed_pc=0x0c0435e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0435fa; }
goto P_0c0435ea;
P_0c0435ea: /* original 6360, guest PC 0x0c0435ea */
if(!s->budget--) { s->failed_pc=0x0c0435eau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0435ec;
P_0c0435ec: /* original 6140, guest PC 0x0c0435ec */
if(!s->budget--) { s->failed_pc=0x0c0435ecu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c0435ee;
P_0c0435ee: /* original 3130, guest PC 0x0c0435ee */
if(!s->budget--) { s->failed_pc=0x0c0435eeu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c0435f0;
P_0c0435f0: /* original 8908, guest PC 0x0c0435f0 */
if(!s->budget--) { s->failed_pc=0x0c0435f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043604; }
goto P_0c0435f2;
P_0c0435f2: /* original 7601, guest PC 0x0c0435f2 */
if(!s->budget--) { s->failed_pc=0x0c0435f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c0435f4;
P_0c0435f4: /* original 6360, guest PC 0x0c0435f4 */
if(!s->budget--) { s->failed_pc=0x0c0435f4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0435f6;
P_0c0435f6: /* original 2338, guest PC 0x0c0435f6 */
if(!s->budget--) { s->failed_pc=0x0c0435f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0435f8;
P_0c0435f8: /* original 8bf7, guest PC 0x0c0435f8 */
if(!s->budget--) { s->failed_pc=0x0c0435f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0435ea; }
goto P_0c0435fa;
P_0c0435fa: /* original 7401, guest PC 0x0c0435fa */
if(!s->budget--) { s->failed_pc=0x0c0435fau; return 0; }
r[4]+=0x00000001u;
goto P_0c0435fc;
P_0c0435fc: /* original 6340, guest PC 0x0c0435fc */
if(!s->budget--) { s->failed_pc=0x0c0435fcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c0435fe;
P_0c0435fe: /* original 2338, guest PC 0x0c0435fe */
if(!s->budget--) { s->failed_pc=0x0c0435feu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c043600;
P_0c043600: /* original 8fef, guest PC 0x0c043600 */
if(!s->budget--) { s->failed_pc=0x0c043600u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c0435e2; }
goto P_0c043604;
P_0c043602: /* original 7701, guest PC 0x0c043602 */
if(!s->budget--) { s->failed_pc=0x0c043602u; return 0; }
r[7]+=0x00000001u;
goto P_0c043604;
P_0c043604: /* original 6073, guest PC 0x0c043604 */
if(!s->budget--) { s->failed_pc=0x0c043604u; return 0; }
r[0]=r[7];
goto P_0c043606;
P_0c043606: /* original 000b, guest PC 0x0c043606 */
if(!s->budget--) { s->failed_pc=0x0c043606u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c043608: /* original 0009, guest PC 0x0c043608 */
if(!s->budget--) { s->failed_pc=0x0c043608u; return 0; }
goto P_0c04360a;
P_0c04360a: /* original 9686, guest PC 0x0c04360a */
if(!s->budget--) { s->failed_pc=0x0c04360au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04371au,2);
goto P_0c04360c;
P_0c04360c: /* original a00b, guest PC 0x0c04360c */
if(!s->budget--) { s->failed_pc=0x0c04360cu; return 0; }
goto P_0c043626;
P_0c04360e: /* original 0009, guest PC 0x0c04360e */
if(!s->budget--) { s->failed_pc=0x0c04360eu; return 0; }
goto P_0c043610;
P_0c043610: /* original 6544, guest PC 0x0c043610 */
if(!s->budget--) { s->failed_pc=0x0c043610u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]+=1;
r[5]=tmp;
goto P_0c043612;
P_0c043612: /* original e061, guest PC 0x0c043612 */
if(!s->budget--) { s->failed_pc=0x0c043612u; return 0; }
r[0]=0x00000061u;
goto P_0c043614;
P_0c043614: /* original 675e, guest PC 0x0c043614 */
if(!s->budget--) { s->failed_pc=0x0c043614u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c043616;
P_0c043616: /* original 3703, guest PC 0x0c043616 */
if(!s->budget--) { s->failed_pc=0x0c043616u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c043618;
P_0c043618: /* original 8b03, guest PC 0x0c043618 */
if(!s->budget--) { s->failed_pc=0x0c043618u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043622; }
goto P_0c04361a;
P_0c04361a: /* original e27a, guest PC 0x0c04361a */
if(!s->budget--) { s->failed_pc=0x0c04361au; return 0; }
r[2]=0x0000007au;
goto P_0c04361c;
P_0c04361c: /* original 3727, guest PC 0x0c04361c */
if(!s->budget--) { s->failed_pc=0x0c04361cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[2])!=0);
goto P_0c04361e;
P_0c04361e: /* original 8900, guest PC 0x0c04361e */
if(!s->budget--) { s->failed_pc=0x0c04361eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043622; }
goto P_0c043620;
P_0c043620: /* original 75e0, guest PC 0x0c043620 */
if(!s->budget--) { s->failed_pc=0x0c043620u; return 0; }
r[5]+=0xffffffe0u;
goto P_0c043622;
P_0c043622: /* original 675c, guest PC 0x0c043622 */
if(!s->budget--) { s->failed_pc=0x0c043622u; return 0; }
r[7]=r[5]&255u;
goto P_0c043624;
P_0c043624: /* original 367c, guest PC 0x0c043624 */
if(!s->budget--) { s->failed_pc=0x0c043624u; return 0; }
r[6]+=r[7];
goto P_0c043626;
P_0c043626: /* original 6340, guest PC 0x0c043626 */
if(!s->budget--) { s->failed_pc=0x0c043626u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c043628;
P_0c043628: /* original 2338, guest PC 0x0c043628 */
if(!s->budget--) { s->failed_pc=0x0c043628u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04362a;
P_0c04362a: /* original 8bf1, guest PC 0x0c04362a */
if(!s->budget--) { s->failed_pc=0x0c04362au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043610; }
goto P_0c04362c;
P_0c04362c: /* original 4609, guest PC 0x0c04362c */
if(!s->budget--) { s->failed_pc=0x0c04362cu; return 0; }
r[6]>>=2;
goto P_0c04362e;
P_0c04362e: /* original 000b, guest PC 0x0c04362e */
if(!s->budget--) { s->failed_pc=0x0c04362eu; return 0; }
target=r[16];
r[0]=r[6]&255u;
s->pc=target; return ram->oob==0;
P_0c043630: /* original 606c, guest PC 0x0c043630 */
if(!s->budget--) { s->failed_pc=0x0c043630u; return 0; }
r[0]=r[6]&255u;
goto P_0c043632;
P_0c043632: /* original 2fe6, guest PC 0x0c043632 */
if(!s->budget--) { s->failed_pc=0x0c043632u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043634;
P_0c043634: /* original e222, guest PC 0x0c043634 */
if(!s->budget--) { s->failed_pc=0x0c043634u; return 0; }
r[2]=0x00000022u;
goto P_0c043636;
P_0c043636: /* original 2fd6, guest PC 0x0c043636 */
if(!s->budget--) { s->failed_pc=0x0c043636u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043638;
P_0c043638: /* original 6d43, guest PC 0x0c043638 */
if(!s->budget--) { s->failed_pc=0x0c043638u; return 0; }
r[13]=r[4];
goto P_0c04363a;
P_0c04363a: /* original 2fc6, guest PC 0x0c04363a */
if(!s->budget--) { s->failed_pc=0x0c04363au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04363c;
P_0c04363c: /* original 63d0, guest PC 0x0c04363c */
if(!s->budget--) { s->failed_pc=0x0c04363cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c04363e;
P_0c04363e: /* original 4f22, guest PC 0x0c04363e */
if(!s->budget--) { s->failed_pc=0x0c04363eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c043640;
P_0c043640: /* original 633c, guest PC 0x0c043640 */
if(!s->budget--) { s->failed_pc=0x0c043640u; return 0; }
r[3]=r[3]&255u;
goto P_0c043642;
P_0c043642: /* original 3323, guest PC 0x0c043642 */
if(!s->budget--) { s->failed_pc=0x0c043642u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c043644;
P_0c043644: /* original 8d02, guest PC 0x0c043644 */
if(!s->budget--) { s->failed_pc=0x0c043644u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c04364c; }
goto P_0c043648;
P_0c043646: /* original 6e53, guest PC 0x0c043646 */
if(!s->budget--) { s->failed_pc=0x0c043646u; return 0; }
r[14]=r[5];
goto P_0c043648;
P_0c043648: /* original a039, guest PC 0x0c043648 */
if(!s->budget--) { s->failed_pc=0x0c043648u; return 0; }
r[0]=0x00000000u;
goto P_0c0436be;
P_0c04364a: /* original e000, guest PC 0x0c04364a */
if(!s->budget--) { s->failed_pc=0x0c04364au; return 0; }
r[0]=0x00000000u;
goto P_0c04364c;
P_0c04364c: /* original 64d3, guest PC 0x0c04364c */
if(!s->budget--) { s->failed_pc=0x0c04364cu; return 0; }
r[4]=r[13];
goto P_0c04364e;
P_0c04364e: /* original 65e3, guest PC 0x0c04364e */
if(!s->budget--) { s->failed_pc=0x0c04364eu; return 0; }
r[5]=r[14];
goto P_0c043650;
P_0c043650: /* original e604, guest PC 0x0c043650 */
if(!s->budget--) { s->failed_pc=0x0c043650u; return 0; }
r[6]=0x00000004u;
goto P_0c043652;
P_0c043652: /* original bf55, guest PC 0x0c043652 */
if(!s->budget--) { s->failed_pc=0x0c043652u; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c043656u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043656u) { target=s->pc; goto dispatch; }
goto P_0c043656;
P_0c043654: /* original 7402, guest PC 0x0c043654 */
if(!s->budget--) { s->failed_pc=0x0c043654u; return 0; }
r[4]+=0x00000002u;
goto P_0c043656;
P_0c043656: /* original 65e3, guest PC 0x0c043656 */
if(!s->budget--) { s->failed_pc=0x0c043656u; return 0; }
r[5]=r[14];
goto P_0c043658;
P_0c043658: /* original 64d3, guest PC 0x0c043658 */
if(!s->budget--) { s->failed_pc=0x0c043658u; return 0; }
r[4]=r[13];
goto P_0c04365a;
P_0c04365a: /* original 7504, guest PC 0x0c04365a */
if(!s->budget--) { s->failed_pc=0x0c04365au; return 0; }
r[5]+=0x00000004u;
goto P_0c04365c;
P_0c04365c: /* original e604, guest PC 0x0c04365c */
if(!s->budget--) { s->failed_pc=0x0c04365cu; return 0; }
r[6]=0x00000004u;
goto P_0c04365e;
P_0c04365e: /* original bf4f, guest PC 0x0c04365e */
if(!s->budget--) { s->failed_pc=0x0c04365eu; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c043662u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043662u) { target=s->pc; goto dispatch; }
goto P_0c043662;
P_0c043660: /* original 740a, guest PC 0x0c043660 */
if(!s->budget--) { s->failed_pc=0x0c043660u; return 0; }
r[4]+=0x0000000au;
goto P_0c043662;
P_0c043662: /* original e019, guest PC 0x0c043662 */
if(!s->budget--) { s->failed_pc=0x0c043662u; return 0; }
r[0]=0x00000019u;
goto P_0c043664;
P_0c043664: /* original 00dc, guest PC 0x0c043664 */
if(!s->budget--) { s->failed_pc=0x0c043664u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c043666;
P_0c043666: /* original 80e8, guest PC 0x0c043666 */
if(!s->budget--) { s->failed_pc=0x0c043666u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c043668;
P_0c043668: /* original e020, guest PC 0x0c043668 */
if(!s->budget--) { s->failed_pc=0x0c043668u; return 0; }
r[0]=0x00000020u;
goto P_0c04366a;
P_0c04366a: /* original 0cdc, guest PC 0x0c04366a */
if(!s->budget--) { s->failed_pc=0x0c04366au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c04366c;
P_0c04366c: /* original 84e8, guest PC 0x0c04366c */
if(!s->budget--) { s->failed_pc=0x0c04366cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c04366e;
P_0c04366e: /* original 600c, guest PC 0x0c04366e */
if(!s->budget--) { s->failed_pc=0x0c04366eu; return 0; }
r[0]=r[0]&255u;
goto P_0c043670;
P_0c043670: /* original c802, guest PC 0x0c043670 */
if(!s->budget--) { s->failed_pc=0x0c043670u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c043672;
P_0c043672: /* original 8f01, guest PC 0x0c043672 */
if(!s->budget--) { s->failed_pc=0x0c043672u; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c043678; }
goto P_0c043676;
P_0c043674: /* original 6ccc, guest PC 0x0c043674 */
if(!s->budget--) { s->failed_pc=0x0c043674u; return 0; }
r[12]=r[12]&255u;
goto P_0c043676;
P_0c043676: /* original 7cfe, guest PC 0x0c043676 */
if(!s->budget--) { s->failed_pc=0x0c043676u; return 0; }
r[12]+=0xfffffffeu;
goto P_0c043678;
P_0c043678: /* original 65e3, guest PC 0x0c043678 */
if(!s->budget--) { s->failed_pc=0x0c043678u; return 0; }
r[5]=r[14];
goto P_0c04367a;
P_0c04367a: /* original 64d3, guest PC 0x0c04367a */
if(!s->budget--) { s->failed_pc=0x0c04367au; return 0; }
r[4]=r[13];
goto P_0c04367c;
P_0c04367c: /* original 750a, guest PC 0x0c04367c */
if(!s->budget--) { s->failed_pc=0x0c04367cu; return 0; }
r[5]+=0x0000000au;
goto P_0c04367e;
P_0c04367e: /* original 66c3, guest PC 0x0c04367e */
if(!s->budget--) { s->failed_pc=0x0c04367eu; return 0; }
r[6]=r[12];
goto P_0c043680;
P_0c043680: /* original bf3e, guest PC 0x0c043680 */
if(!s->budget--) { s->failed_pc=0x0c043680u; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c043684u;
r[4]+=0x00000021u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043684u) { target=s->pc; goto dispatch; }
goto P_0c043684;
P_0c043682: /* original 7421, guest PC 0x0c043682 */
if(!s->budget--) { s->failed_pc=0x0c043682u; return 0; }
r[4]+=0x00000021u;
goto P_0c043684;
P_0c043684: /* original 63e3, guest PC 0x0c043684 */
if(!s->budget--) { s->failed_pc=0x0c043684u; return 0; }
r[3]=r[14];
goto P_0c043686;
P_0c043686: /* original 730a, guest PC 0x0c043686 */
if(!s->budget--) { s->failed_pc=0x0c043686u; return 0; }
r[3]+=0x0000000au;
goto P_0c043688;
P_0c043688: /* original e400, guest PC 0x0c043688 */
if(!s->budget--) { s->failed_pc=0x0c043688u; return 0; }
r[4]=0x00000000u;
goto P_0c04368a;
P_0c04368a: /* original 3c3c, guest PC 0x0c04368a */
if(!s->budget--) { s->failed_pc=0x0c04368au; return 0; }
r[12]+=r[3];
goto P_0c04368c;
P_0c04368c: /* original 2c40, guest PC 0x0c04368c */
if(!s->budget--) { s->failed_pc=0x0c04368cu; return 0; }
write(ram,r[12],r[4],1);
goto P_0c04368e;
P_0c04368e: /* original 84e8, guest PC 0x0c04368e */
if(!s->budget--) { s->failed_pc=0x0c04368eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c043690;
P_0c043690: /* original 600c, guest PC 0x0c043690 */
if(!s->budget--) { s->failed_pc=0x0c043690u; return 0; }
r[0]=r[0]&255u;
goto P_0c043692;
P_0c043692: /* original c802, guest PC 0x0c043692 */
if(!s->budget--) { s->failed_pc=0x0c043692u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c043694;
P_0c043694: /* original 890d, guest PC 0x0c043694 */
if(!s->budget--) { s->failed_pc=0x0c043694u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0436b2; }
goto P_0c043696;
P_0c043696: /* original 84ea, guest PC 0x0c043696 */
if(!s->budget--) { s->failed_pc=0x0c043696u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c043698;
P_0c043698: /* original 2008, guest PC 0x0c043698 */
if(!s->budget--) { s->failed_pc=0x0c043698u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04369a;
P_0c04369a: /* original 8f03, guest PC 0x0c04369a */
if(!s->budget--) { s->failed_pc=0x0c04369au; return 0; }
cond=r[17]&1u;
r[5]=0x0000002eu;
if(!cond) { goto P_0c0436a4; }
goto P_0c04369e;
P_0c04369c: /* original e52e, guest PC 0x0c04369c */
if(!s->budget--) { s->failed_pc=0x0c04369cu; return 0; }
r[5]=0x0000002eu;
goto P_0c04369e;
P_0c04369e: /* original 6053, guest PC 0x0c04369e */
if(!s->budget--) { s->failed_pc=0x0c04369eu; return 0; }
r[0]=r[5];
goto P_0c0436a0;
P_0c0436a0: /* original a007, guest PC 0x0c0436a0 */
if(!s->budget--) { s->failed_pc=0x0c0436a0u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c0436b2;
P_0c0436a2: /* original 80ea, guest PC 0x0c0436a2 */
if(!s->budget--) { s->failed_pc=0x0c0436a2u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c0436a4;
P_0c0436a4: /* original 8801, guest PC 0x0c0436a4 */
if(!s->budget--) { s->failed_pc=0x0c0436a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0436a6;
P_0c0436a6: /* original 8b04, guest PC 0x0c0436a6 */
if(!s->budget--) { s->failed_pc=0x0c0436a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0436b2; }
goto P_0c0436a8;
P_0c0436a8: /* original 6053, guest PC 0x0c0436a8 */
if(!s->budget--) { s->failed_pc=0x0c0436a8u; return 0; }
r[0]=r[5];
goto P_0c0436aa;
P_0c0436aa: /* original 80ea, guest PC 0x0c0436aa */
if(!s->budget--) { s->failed_pc=0x0c0436aau; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c0436ac;
P_0c0436ac: /* original 80eb, guest PC 0x0c0436ac */
if(!s->budget--) { s->failed_pc=0x0c0436acu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c0436ae;
P_0c0436ae: /* original 6043, guest PC 0x0c0436ae */
if(!s->budget--) { s->failed_pc=0x0c0436aeu; return 0; }
r[0]=r[4];
goto P_0c0436b0;
P_0c0436b0: /* original 80ec, guest PC 0x0c0436b0 */
if(!s->budget--) { s->failed_pc=0x0c0436b0u; return 0; }
write(ram,r[14]+12,r[0],1);
goto P_0c0436b2;
P_0c0436b2: /* original 64e3, guest PC 0x0c0436b2 */
if(!s->budget--) { s->failed_pc=0x0c0436b2u; return 0; }
r[4]=r[14];
goto P_0c0436b4;
P_0c0436b4: /* original bfa9, guest PC 0x0c0436b4 */
if(!s->budget--) { s->failed_pc=0x0c0436b4u; return 0; }
target=code_base|0x0c04360au; r[16]=code_base|0x0c0436b8u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0436b8u) { target=s->pc; goto dispatch; }
goto P_0c0436b8;
P_0c0436b6: /* original 740a, guest PC 0x0c0436b6 */
if(!s->budget--) { s->failed_pc=0x0c0436b6u; return 0; }
r[4]+=0x0000000au;
goto P_0c0436b8;
P_0c0436b8: /* original 80e9, guest PC 0x0c0436b8 */
if(!s->budget--) { s->failed_pc=0x0c0436b8u; return 0; }
write(ram,r[14]+9,r[0],1);
goto P_0c0436ba;
P_0c0436ba: /* original 60d0, guest PC 0x0c0436ba */
if(!s->budget--) { s->failed_pc=0x0c0436bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[0]=tmp;
goto P_0c0436bc;
P_0c0436bc: /* original 600c, guest PC 0x0c0436bc */
if(!s->budget--) { s->failed_pc=0x0c0436bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0436be;
P_0c0436be: /* original 4f26, guest PC 0x0c0436be */
if(!s->budget--) { s->failed_pc=0x0c0436beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0436c0;
P_0c0436c0: /* original 6cf6, guest PC 0x0c0436c0 */
if(!s->budget--) { s->failed_pc=0x0c0436c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0436c2;
P_0c0436c2: /* original 6df6, guest PC 0x0c0436c2 */
if(!s->budget--) { s->failed_pc=0x0c0436c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0436c4;
P_0c0436c4: /* original 000b, guest PC 0x0c0436c4 */
if(!s->budget--) { s->failed_pc=0x0c0436c4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0436c6: /* original 6ef6, guest PC 0x0c0436c6 */
if(!s->budget--) { s->failed_pc=0x0c0436c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0436c8;
P_0c0436c8: /* original 2fe6, guest PC 0x0c0436c8 */
if(!s->budget--) { s->failed_pc=0x0c0436c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436ca;
P_0c0436ca: /* original 6353, guest PC 0x0c0436ca */
if(!s->budget--) { s->failed_pc=0x0c0436cau; return 0; }
r[3]=r[5];
goto P_0c0436cc;
P_0c0436cc: /* original 2fd6, guest PC 0x0c0436cc */
if(!s->budget--) { s->failed_pc=0x0c0436ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436ce;
P_0c0436ce: /* original 2fc6, guest PC 0x0c0436ce */
if(!s->budget--) { s->failed_pc=0x0c0436ceu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436d0;
P_0c0436d0: /* original 6c63, guest PC 0x0c0436d0 */
if(!s->budget--) { s->failed_pc=0x0c0436d0u; return 0; }
r[12]=r[6];
goto P_0c0436d2;
P_0c0436d2: /* original 2fb6, guest PC 0x0c0436d2 */
if(!s->budget--) { s->failed_pc=0x0c0436d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436d4;
P_0c0436d4: /* original 6b73, guest PC 0x0c0436d4 */
if(!s->budget--) { s->failed_pc=0x0c0436d4u; return 0; }
r[11]=r[7];
goto P_0c0436d6;
P_0c0436d6: /* original 2fa6, guest PC 0x0c0436d6 */
if(!s->budget--) { s->failed_pc=0x0c0436d6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436d8;
P_0c0436d8: /* original 6a63, guest PC 0x0c0436d8 */
if(!s->budget--) { s->failed_pc=0x0c0436d8u; return 0; }
r[10]=r[6];
goto P_0c0436da;
P_0c0436da: /* original 2f96, guest PC 0x0c0436da */
if(!s->budget--) { s->failed_pc=0x0c0436dau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436dc;
P_0c0436dc: /* original 2f86, guest PC 0x0c0436dc */
if(!s->budget--) { s->failed_pc=0x0c0436dcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0436de;
P_0c0436de: /* original 4f22, guest PC 0x0c0436de */
if(!s->budget--) { s->failed_pc=0x0c0436deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0436e0;
P_0c0436e0: /* original 7ff4, guest PC 0x0c0436e0 */
if(!s->budget--) { s->failed_pc=0x0c0436e0u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0436e2;
P_0c0436e2: /* original 1f41, guest PC 0x0c0436e2 */
if(!s->budget--) { s->failed_pc=0x0c0436e2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0436e4;
P_0c0436e4: /* original 2f52, guest PC 0x0c0436e4 */
if(!s->budget--) { s->failed_pc=0x0c0436e4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0436e6;
P_0c0436e6: /* original 52a2, guest PC 0x0c0436e6 */
if(!s->budget--) { s->failed_pc=0x0c0436e6u; return 0; }
r[2]=read(ram,r[10]+8,4);
goto P_0c0436e8;
P_0c0436e8: /* original 3230, guest PC 0x0c0436e8 */
if(!s->budget--) { s->failed_pc=0x0c0436e8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0436ea;
P_0c0436ea: /* original 8d4c, guest PC 0x0c0436ea */
if(!s->budget--) { s->failed_pc=0x0c0436eau; return 0; }
cond=r[17]&1u;
r[12]+=0x00000010u;
if(cond) { goto P_0c043786; }
goto P_0c0436ee;
P_0c0436ec: /* original 7c10, guest PC 0x0c0436ec */
if(!s->budget--) { s->failed_pc=0x0c0436ecu; return 0; }
r[12]+=0x00000010u;
goto P_0c0436ee;
P_0c0436ee: /* original 63f2, guest PC 0x0c0436ee */
if(!s->budget--) { s->failed_pc=0x0c0436eeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0436f0;
P_0c0436f0: /* original e800, guest PC 0x0c0436f0 */
if(!s->budget--) { s->failed_pc=0x0c0436f0u; return 0; }
r[8]=0x00000000u;
goto P_0c0436f2;
P_0c0436f2: /* original 4b15, guest PC 0x0c0436f2 */
if(!s->budget--) { s->failed_pc=0x0c0436f2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c0436f4;
P_0c0436f4: /* original 6e83, guest PC 0x0c0436f4 */
if(!s->budget--) { s->failed_pc=0x0c0436f4u; return 0; }
r[14]=r[8];
goto P_0c0436f6;
P_0c0436f6: /* original 1a32, guest PC 0x0c0436f6 */
if(!s->budget--) { s->failed_pc=0x0c0436f6u; return 0; }
write(ram,r[10]+8,r[3],4);
goto P_0c0436f8;
P_0c0436f8: /* original 9310, guest PC 0x0c0436f8 */
if(!s->budget--) { s->failed_pc=0x0c0436f8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04371cu,2);
goto P_0c0436fa;
P_0c0436fa: /* original 52f1, guest PC 0x0c0436fa */
if(!s->budget--) { s->failed_pc=0x0c0436fau; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0436fc;
P_0c0436fc: /* original 59a1, guest PC 0x0c0436fc */
if(!s->budget--) { s->failed_pc=0x0c0436fcu; return 0; }
r[9]=read(ram,r[10]+4,4);
goto P_0c0436fe;
P_0c0436fe: /* original 323c, guest PC 0x0c0436fe */
if(!s->budget--) { s->failed_pc=0x0c0436feu; return 0; }
r[2]+=r[3];
goto P_0c043700;
P_0c043700: /* original 8f30, guest PC 0x0c043700 */
if(!s->budget--) { s->failed_pc=0x0c043700u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(!cond) { goto P_0c043764; }
goto P_0c043704;
P_0c043702: /* original 1f22, guest PC 0x0c043702 */
if(!s->budget--) { s->failed_pc=0x0c043702u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c043704;
P_0c043704: /* original d306, guest PC 0x0c043704 */
if(!s->budget--) { s->failed_pc=0x0c043704u; return 0; }
r[3]=read(ram,0x0c043720u,4);
goto P_0c043706;
P_0c043706: /* original e501, guest PC 0x0c043706 */
if(!s->budget--) { s->failed_pc=0x0c043706u; return 0; }
r[5]=0x00000001u;
goto P_0c043708;
P_0c043708: /* original 56f1, guest PC 0x0c043708 */
if(!s->budget--) { s->failed_pc=0x0c043708u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c04370a;
P_0c04370a: /* original 430b, guest PC 0x0c04370a */
if(!s->budget--) { s->failed_pc=0x0c04370au; return 0; }
target=r[3];
r[16]=code_base|0x0c04370eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04370eu) { target=s->pc; goto dispatch; }
goto P_0c04370e;
P_0c04370c: /* original 64f2, guest PC 0x0c04370c */
if(!s->budget--) { s->failed_pc=0x0c04370cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04370e;
P_0c04370e: /* original 6403, guest PC 0x0c04370e */
if(!s->budget--) { s->failed_pc=0x0c04370eu; return 0; }
r[4]=r[0];
goto P_0c043710;
P_0c043710: /* original 2448, guest PC 0x0c043710 */
if(!s->budget--) { s->failed_pc=0x0c043710u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c043712;
P_0c043712: /* original 8907, guest PC 0x0c043712 */
if(!s->budget--) { s->failed_pc=0x0c043712u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043724; }
goto P_0c043714;
P_0c043714: /* original 1a82, guest PC 0x0c043714 */
if(!s->budget--) { s->failed_pc=0x0c043714u; return 0; }
write(ram,r[10]+8,r[8],4);
goto P_0c043716;
P_0c043716: /* original a037, guest PC 0x0c043716 */
if(!s->budget--) { s->failed_pc=0x0c043716u; return 0; }
r[0]=r[4];
goto P_0c043788;
P_0c043718: /* original 6043, guest PC 0x0c043718 */
if(!s->budget--) { s->failed_pc=0x0c043718u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04371au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04371au; return 0; } return 1;
P_0c043724: /* original 3e93, guest PC 0x0c043724 */
if(!s->budget--) { s->failed_pc=0x0c043724u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[9])!=0);
goto P_0c043726;
P_0c043726: /* original 8d1d, guest PC 0x0c043726 */
if(!s->budget--) { s->failed_pc=0x0c043726u; return 0; }
cond=r[17]&1u;
r[13]=read(ram,r[15]+4,4);
if(cond) { goto P_0c043764; }
goto P_0c04372a;
P_0c043728: /* original 5df1, guest PC 0x0c043728 */
if(!s->budget--) { s->failed_pc=0x0c043728u; return 0; }
r[13]=read(ram,r[15]+4,4);
goto P_0c04372a;
P_0c04372a: /* original 65c3, guest PC 0x0c04372a */
if(!s->budget--) { s->failed_pc=0x0c04372au; return 0; }
r[5]=r[12];
goto P_0c04372c;
P_0c04372c: /* original bf81, guest PC 0x0c04372c */
if(!s->budget--) { s->failed_pc=0x0c04372cu; return 0; }
target=code_base|0x0c043632u; r[16]=code_base|0x0c043730u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043730u) { target=s->pc; goto dispatch; }
goto P_0c043730;
P_0c04372e: /* original 64d3, guest PC 0x0c04372e */
if(!s->budget--) { s->failed_pc=0x0c04372eu; return 0; }
r[4]=r[13];
goto P_0c043730;
P_0c043730: /* original 2008, guest PC 0x0c043730 */
if(!s->budget--) { s->failed_pc=0x0c043730u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c043732;
P_0c043732: /* original 8d0e, guest PC 0x0c043732 */
if(!s->budget--) { s->failed_pc=0x0c043732u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c043752; }
goto P_0c043736;
P_0c043734: /* original 6403, guest PC 0x0c043734 */
if(!s->budget--) { s->failed_pc=0x0c043734u; return 0; }
r[4]=r[0];
goto P_0c043736;
P_0c043736: /* original 2ee8, guest PC 0x0c043736 */
if(!s->budget--) { s->failed_pc=0x0c043736u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c043738;
P_0c043738: /* original 8b03, guest PC 0x0c043738 */
if(!s->budget--) { s->failed_pc=0x0c043738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043742; }
goto P_0c04373a;
P_0c04373a: /* original 52c1, guest PC 0x0c04373a */
if(!s->budget--) { s->failed_pc=0x0c04373au; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c04373c;
P_0c04373c: /* original 32b0, guest PC 0x0c04373c */
if(!s->budget--) { s->failed_pc=0x0c04373cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c04373e;
P_0c04373e: /* original 8900, guest PC 0x0c04373e */
if(!s->budget--) { s->failed_pc=0x0c04373eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043742; }
goto P_0c043740;
P_0c043740: /* original 5bc1, guest PC 0x0c043740 */
if(!s->budget--) { s->failed_pc=0x0c043740u; return 0; }
r[11]=read(ram,r[12]+4,4);
goto P_0c043742;
P_0c043742: /* original 52f2, guest PC 0x0c043742 */
if(!s->budget--) { s->failed_pc=0x0c043742u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c043744;
P_0c043744: /* original 3d4c, guest PC 0x0c043744 */
if(!s->budget--) { s->failed_pc=0x0c043744u; return 0; }
r[13]+=r[4];
goto P_0c043746;
P_0c043746: /* original 7c2c, guest PC 0x0c043746 */
if(!s->budget--) { s->failed_pc=0x0c043746u; return 0; }
r[12]+=0x0000002cu;
goto P_0c043748;
P_0c043748: /* original 3d22, guest PC 0x0c043748 */
if(!s->budget--) { s->failed_pc=0x0c043748u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[2])!=0);
goto P_0c04374a;
P_0c04374a: /* original 8d02, guest PC 0x0c04374a */
if(!s->budget--) { s->failed_pc=0x0c04374au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(cond) { goto P_0c043752; }
goto P_0c04374e;
P_0c04374c: /* original 7e01, guest PC 0x0c04374c */
if(!s->budget--) { s->failed_pc=0x0c04374cu; return 0; }
r[14]+=0x00000001u;
goto P_0c04374e;
P_0c04374e: /* original 3e93, guest PC 0x0c04374e */
if(!s->budget--) { s->failed_pc=0x0c04374eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[9])!=0);
goto P_0c043750;
P_0c043750: /* original 8beb, guest PC 0x0c043750 */
if(!s->budget--) { s->failed_pc=0x0c043750u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04372a; }
goto P_0c043752;
P_0c043752: /* original 3e93, guest PC 0x0c043752 */
if(!s->budget--) { s->failed_pc=0x0c043752u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[9])!=0);
goto P_0c043754;
P_0c043754: /* original 8906, guest PC 0x0c043754 */
if(!s->budget--) { s->failed_pc=0x0c043754u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043764; }
goto P_0c043756;
P_0c043756: /* original 924e, guest PC 0x0c043756 */
if(!s->budget--) { s->failed_pc=0x0c043756u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0437f6u,2);
goto P_0c043758;
P_0c043758: /* original 63f2, guest PC 0x0c043758 */
if(!s->budget--) { s->failed_pc=0x0c043758u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c04375a;
P_0c04375a: /* original 3b28, guest PC 0x0c04375a */
if(!s->budget--) { s->failed_pc=0x0c04375au; return 0; }
r[11]-=r[2];
goto P_0c04375c;
P_0c04375c: /* original 4b15, guest PC 0x0c04375c */
if(!s->budget--) { s->failed_pc=0x0c04375cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c04375e;
P_0c04375e: /* original 7301, guest PC 0x0c04375e */
if(!s->budget--) { s->failed_pc=0x0c04375eu; return 0; }
r[3]+=0x00000001u;
goto P_0c043760;
P_0c043760: /* original 8dd0, guest PC 0x0c043760 */
if(!s->budget--) { s->failed_pc=0x0c043760u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c043704; }
goto P_0c043764;
P_0c043762: /* original 2f32, guest PC 0x0c043762 */
if(!s->budget--) { s->failed_pc=0x0c043762u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c043764;
P_0c043764: /* original 3e90, guest PC 0x0c043764 */
if(!s->budget--) { s->failed_pc=0x0c043764u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[9])!=0);
goto P_0c043766;
P_0c043766: /* original 8f0e, guest PC 0x0c043766 */
if(!s->budget--) { s->failed_pc=0x0c043766u; return 0; }
cond=r[17]&1u;
write(ram,r[10],r[14],4);
if(!cond) { goto P_0c043786; }
goto P_0c04376a;
P_0c043768: /* original 2ae2, guest PC 0x0c043768 */
if(!s->budget--) { s->failed_pc=0x0c043768u; return 0; }
write(ram,r[10],r[14],4);
goto P_0c04376a;
P_0c04376a: /* original 2bb8, guest PC 0x0c04376a */
if(!s->budget--) { s->failed_pc=0x0c04376au; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04376c;
P_0c04376c: /* original 890b, guest PC 0x0c04376c */
if(!s->budget--) { s->failed_pc=0x0c04376cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043786; }
goto P_0c04376e;
P_0c04376e: /* original 9342, guest PC 0x0c04376e */
if(!s->budget--) { s->failed_pc=0x0c04376eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0437f6u,2);
goto P_0c043770;
P_0c043770: /* original 3b30, guest PC 0x0c043770 */
if(!s->budget--) { s->failed_pc=0x0c043770u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c043772;
P_0c043772: /* original 8b05, guest PC 0x0c043772 */
if(!s->budget--) { s->failed_pc=0x0c043772u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043780; }
goto P_0c043774;
P_0c043774: /* original 53f2, guest PC 0x0c043774 */
if(!s->budget--) { s->failed_pc=0x0c043774u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c043776;
P_0c043776: /* original 3d32, guest PC 0x0c043776 */
if(!s->budget--) { s->failed_pc=0x0c043776u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>=r[3])!=0);
goto P_0c043778;
P_0c043778: /* original 8905, guest PC 0x0c043778 */
if(!s->budget--) { s->failed_pc=0x0c043778u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043786; }
goto P_0c04377a;
P_0c04377a: /* original 61d0, guest PC 0x0c04377a */
if(!s->budget--) { s->failed_pc=0x0c04377au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c04377c;
P_0c04377c: /* original 2118, guest PC 0x0c04377c */
if(!s->budget--) { s->failed_pc=0x0c04377cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04377e;
P_0c04377e: /* original 8902, guest PC 0x0c04377e */
if(!s->budget--) { s->failed_pc=0x0c04377eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c043786; }
goto P_0c043780;
P_0c043780: /* original 1a82, guest PC 0x0c043780 */
if(!s->budget--) { s->failed_pc=0x0c043780u; return 0; }
write(ram,r[10]+8,r[8],4);
goto P_0c043782;
P_0c043782: /* original a001, guest PC 0x0c043782 */
if(!s->budget--) { s->failed_pc=0x0c043782u; return 0; }
r[0]=0xfffffff4u;
goto P_0c043788;
P_0c043784: /* original e0f4, guest PC 0x0c043784 */
if(!s->budget--) { s->failed_pc=0x0c043784u; return 0; }
r[0]=0xfffffff4u;
goto P_0c043786;
P_0c043786: /* original e000, guest PC 0x0c043786 */
if(!s->budget--) { s->failed_pc=0x0c043786u; return 0; }
r[0]=0x00000000u;
goto P_0c043788;
P_0c043788: /* original 7f0c, guest PC 0x0c043788 */
if(!s->budget--) { s->failed_pc=0x0c043788u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04378a;
P_0c04378a: /* original 4f26, guest PC 0x0c04378a */
if(!s->budget--) { s->failed_pc=0x0c04378au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04378c;
P_0c04378c: /* original 68f6, guest PC 0x0c04378c */
if(!s->budget--) { s->failed_pc=0x0c04378cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04378e;
P_0c04378e: /* original 69f6, guest PC 0x0c04378e */
if(!s->budget--) { s->failed_pc=0x0c04378eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043790;
P_0c043790: /* original 6af6, guest PC 0x0c043790 */
if(!s->budget--) { s->failed_pc=0x0c043790u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c043792;
P_0c043792: /* original 6bf6, guest PC 0x0c043792 */
if(!s->budget--) { s->failed_pc=0x0c043792u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043794;
P_0c043794: /* original 6cf6, guest PC 0x0c043794 */
if(!s->budget--) { s->failed_pc=0x0c043794u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043796;
P_0c043796: /* original 6df6, guest PC 0x0c043796 */
if(!s->budget--) { s->failed_pc=0x0c043796u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c043798;
P_0c043798: /* original 000b, guest PC 0x0c043798 */
if(!s->budget--) { s->failed_pc=0x0c043798u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04379a: /* original 6ef6, guest PC 0x0c04379a */
if(!s->budget--) { s->failed_pc=0x0c04379au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04379cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
