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
int vf3_away_batch1_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c043814u: goto P_0c043814;
case 0x0c043816u: goto P_0c043816;
case 0x0c043818u: goto P_0c043818;
case 0x0c04381au: goto P_0c04381a;
case 0x0c04381cu: goto P_0c04381c;
case 0x0c04381eu: goto P_0c04381e;
case 0x0c043820u: goto P_0c043820;
case 0x0c043822u: goto P_0c043822;
case 0x0c043824u: goto P_0c043824;
case 0x0c043826u: goto P_0c043826;
case 0x0c043828u: goto P_0c043828;
case 0x0c04382au: goto P_0c04382a;
case 0x0c04382cu: goto P_0c04382c;
case 0x0c04382eu: goto P_0c04382e;
case 0x0c043830u: goto P_0c043830;
case 0x0c043832u: goto P_0c043832;
case 0x0c043834u: goto P_0c043834;
case 0x0c043836u: goto P_0c043836;
case 0x0c043838u: goto P_0c043838;
case 0x0c04383au: goto P_0c04383a;
case 0x0c04383cu: goto P_0c04383c;
case 0x0c04383eu: goto P_0c04383e;
case 0x0c043840u: goto P_0c043840;
case 0x0c043842u: goto P_0c043842;
case 0x0c043844u: goto P_0c043844;
case 0x0c043846u: goto P_0c043846;
case 0x0c043848u: goto P_0c043848;
case 0x0c04384au: goto P_0c04384a;
case 0x0c04384cu: goto P_0c04384c;
case 0x0c04384eu: goto P_0c04384e;
case 0x0c043850u: goto P_0c043850;
case 0x0c043852u: goto P_0c043852;
case 0x0c043854u: goto P_0c043854;
case 0x0c043856u: goto P_0c043856;
case 0x0c043858u: goto P_0c043858;
case 0x0c04385au: goto P_0c04385a;
case 0x0c04385cu: goto P_0c04385c;
case 0x0c04385eu: goto P_0c04385e;
case 0x0c043860u: goto P_0c043860;
case 0x0c043862u: goto P_0c043862;
case 0x0c043864u: goto P_0c043864;
case 0x0c043866u: goto P_0c043866;
case 0x0c043868u: goto P_0c043868;
case 0x0c04386au: goto P_0c04386a;
case 0x0c04386cu: goto P_0c04386c;
case 0x0c04386eu: goto P_0c04386e;
case 0x0c043870u: goto P_0c043870;
case 0x0c043872u: goto P_0c043872;
case 0x0c043874u: goto P_0c043874;
case 0x0c043876u: goto P_0c043876;
case 0x0c043878u: goto P_0c043878;
case 0x0c04387au: goto P_0c04387a;
case 0x0c04387cu: goto P_0c04387c;
case 0x0c04387eu: goto P_0c04387e;
case 0x0c043880u: goto P_0c043880;
case 0x0c043882u: goto P_0c043882;
case 0x0c043884u: goto P_0c043884;
case 0x0c043886u: goto P_0c043886;
case 0x0c043888u: goto P_0c043888;
case 0x0c04388au: goto P_0c04388a;
case 0x0c04388cu: goto P_0c04388c;
case 0x0c04388eu: goto P_0c04388e;
case 0x0c043890u: goto P_0c043890;
case 0x0c043892u: goto P_0c043892;
case 0x0c043894u: goto P_0c043894;
case 0x0c043896u: goto P_0c043896;
case 0x0c043898u: goto P_0c043898;
case 0x0c04389au: goto P_0c04389a;
case 0x0c04389cu: goto P_0c04389c;
case 0x0c04389eu: goto P_0c04389e;
case 0x0c0438a0u: goto P_0c0438a0;
case 0x0c0438a2u: goto P_0c0438a2;
case 0x0c0438a4u: goto P_0c0438a4;
case 0x0c0438a6u: goto P_0c0438a6;
case 0x0c0438a8u: goto P_0c0438a8;
case 0x0c0438aau: goto P_0c0438aa;
case 0x0c0438acu: goto P_0c0438ac;
case 0x0c0438aeu: goto P_0c0438ae;
case 0x0c0438b0u: goto P_0c0438b0;
case 0x0c0438b2u: goto P_0c0438b2;
case 0x0c0438b4u: goto P_0c0438b4;
case 0x0c0438b6u: goto P_0c0438b6;
case 0x0c0438b8u: goto P_0c0438b8;
case 0x0c0438bau: goto P_0c0438ba;
case 0x0c0438bcu: goto P_0c0438bc;
case 0x0c0438beu: goto P_0c0438be;
case 0x0c0438c0u: goto P_0c0438c0;
case 0x0c0438c2u: goto P_0c0438c2;
case 0x0c0438c4u: goto P_0c0438c4;
case 0x0c0438c6u: goto P_0c0438c6;
case 0x0c0438c8u: goto P_0c0438c8;
case 0x0c0438cau: goto P_0c0438ca;
case 0x0c0438ccu: goto P_0c0438cc;
case 0x0c0438ceu: goto P_0c0438ce;
case 0x0c0438d0u: goto P_0c0438d0;
case 0x0c0438d2u: goto P_0c0438d2;
case 0x0c0438d4u: goto P_0c0438d4;
case 0x0c0438d6u: goto P_0c0438d6;
case 0x0c0438d8u: goto P_0c0438d8;
case 0x0c0438dau: goto P_0c0438da;
case 0x0c0438dcu: goto P_0c0438dc;
case 0x0c0438deu: goto P_0c0438de;
case 0x0c0438e0u: goto P_0c0438e0;
case 0x0c0438e2u: goto P_0c0438e2;
case 0x0c0438e4u: goto P_0c0438e4;
case 0x0c0438e6u: goto P_0c0438e6;
case 0x0c0438e8u: goto P_0c0438e8;
case 0x0c0438eau: goto P_0c0438ea;
case 0x0c0438ecu: goto P_0c0438ec;
case 0x0c0438eeu: goto P_0c0438ee;
case 0x0c0438f0u: goto P_0c0438f0;
case 0x0c0438f2u: goto P_0c0438f2;
case 0x0c0438f4u: goto P_0c0438f4;
case 0x0c0438f6u: goto P_0c0438f6;
case 0x0c0438f8u: goto P_0c0438f8;
case 0x0c0438fau: goto P_0c0438fa;
case 0x0c0438fcu: goto P_0c0438fc;
case 0x0c0438feu: goto P_0c0438fe;
case 0x0c043900u: goto P_0c043900;
case 0x0c043902u: goto P_0c043902;
case 0x0c043904u: goto P_0c043904;
case 0x0c043906u: goto P_0c043906;
case 0x0c043908u: goto P_0c043908;
case 0x0c04390au: goto P_0c04390a;
case 0x0c04390cu: goto P_0c04390c;
case 0x0c04390eu: goto P_0c04390e;
case 0x0c043910u: goto P_0c043910;
case 0x0c043912u: goto P_0c043912;
case 0x0c043914u: goto P_0c043914;
case 0x0c043916u: goto P_0c043916;
case 0x0c043918u: goto P_0c043918;
case 0x0c04391au: goto P_0c04391a;
case 0x0c04391cu: goto P_0c04391c;
default: return vf3_matrix_family(target,s,ram);
}
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
if(!vf3_matrix_family(0x0c04379cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04379cu; return 0; } return 1;
P_0c043814: /* original 2fe6, guest PC 0x0c043814 */
if(!s->budget--) { s->failed_pc=0x0c043814u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043816;
P_0c043816: /* original 2fd6, guest PC 0x0c043816 */
if(!s->budget--) { s->failed_pc=0x0c043816u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043818;
P_0c043818: /* original 2fc6, guest PC 0x0c043818 */
if(!s->budget--) { s->failed_pc=0x0c043818u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04381a;
P_0c04381a: /* original 6c73, guest PC 0x0c04381a */
if(!s->budget--) { s->failed_pc=0x0c04381au; return 0; }
r[12]=r[7];
goto P_0c04381c;
P_0c04381c: /* original 2fb6, guest PC 0x0c04381c */
if(!s->budget--) { s->failed_pc=0x0c04381cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04381e;
P_0c04381e: /* original 7c01, guest PC 0x0c04381e */
if(!s->budget--) { s->failed_pc=0x0c04381eu; return 0; }
r[12]+=0x00000001u;
goto P_0c043820;
P_0c043820: /* original 2fa6, guest PC 0x0c043820 */
if(!s->budget--) { s->failed_pc=0x0c043820u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043822;
P_0c043822: /* original 2f96, guest PC 0x0c043822 */
if(!s->budget--) { s->failed_pc=0x0c043822u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043824;
P_0c043824: /* original 6943, guest PC 0x0c043824 */
if(!s->budget--) { s->failed_pc=0x0c043824u; return 0; }
r[9]=r[4];
goto P_0c043826;
P_0c043826: /* original 2f86, guest PC 0x0c043826 */
if(!s->budget--) { s->failed_pc=0x0c043826u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c043828;
P_0c043828: /* original e401, guest PC 0x0c043828 */
if(!s->budget--) { s->failed_pc=0x0c043828u; return 0; }
r[4]=0x00000001u;
goto P_0c04382a;
P_0c04382a: /* original 4f22, guest PC 0x0c04382a */
if(!s->budget--) { s->failed_pc=0x0c04382au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04382c;
P_0c04382c: /* original 6b43, guest PC 0x0c04382c */
if(!s->budget--) { s->failed_pc=0x0c04382cu; return 0; }
r[11]=r[4];
goto P_0c04382e;
P_0c04382e: /* original 6e93, guest PC 0x0c04382e */
if(!s->budget--) { s->failed_pc=0x0c04382eu; return 0; }
r[14]=r[9];
goto P_0c043830;
P_0c043830: /* original 7fe8, guest PC 0x0c043830 */
if(!s->budget--) { s->failed_pc=0x0c043830u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c043832;
P_0c043832: /* original 1f52, guest PC 0x0c043832 */
if(!s->budget--) { s->failed_pc=0x0c043832u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c043834;
P_0c043834: /* original 1f64, guest PC 0x0c043834 */
if(!s->budget--) { s->failed_pc=0x0c043834u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c043836;
P_0c043836: /* original 1f45, guest PC 0x0c043836 */
if(!s->budget--) { s->failed_pc=0x0c043836u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c043838;
P_0c043838: /* original e400, guest PC 0x0c043838 */
if(!s->budget--) { s->failed_pc=0x0c043838u; return 0; }
r[4]=0x00000000u;
goto P_0c04383a;
P_0c04383a: /* original 6a43, guest PC 0x0c04383a */
if(!s->budget--) { s->failed_pc=0x0c04383au; return 0; }
r[10]=r[4];
goto P_0c04383c;
P_0c04383c: /* original 1f43, guest PC 0x0c04383c */
if(!s->budget--) { s->failed_pc=0x0c04383cu; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c04383e;
P_0c04383e: /* original 986e, guest PC 0x0c04383e */
if(!s->budget--) { s->failed_pc=0x0c04383eu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04391eu,2);
goto P_0c043840;
P_0c043840: /* original 3e8c, guest PC 0x0c043840 */
if(!s->budget--) { s->failed_pc=0x0c043840u; return 0; }
r[14]+=r[8];
goto P_0c043842;
P_0c043842: /* original 2fe2, guest PC 0x0c043842 */
if(!s->budget--) { s->failed_pc=0x0c043842u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c043844;
P_0c043844: /* original 63f2, guest PC 0x0c043844 */
if(!s->budget--) { s->failed_pc=0x0c043844u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c043846;
P_0c043846: /* original 3e32, guest PC 0x0c043846 */
if(!s->budget--) { s->failed_pc=0x0c043846u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c043848;
P_0c043848: /* original 8d0d, guest PC 0x0c043848 */
if(!s->budget--) { s->failed_pc=0x0c043848u; return 0; }
cond=r[17]&1u;
r[13]=r[14];
if(cond) { goto P_0c043866; }
goto P_0c04384c;
P_0c04384a: /* original 6de3, guest PC 0x0c04384a */
if(!s->budget--) { s->failed_pc=0x0c04384au; return 0; }
r[13]=r[14];
goto P_0c04384c;
P_0c04384c: /* original 61d0, guest PC 0x0c04384c */
if(!s->budget--) { s->failed_pc=0x0c04384cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c04384e;
P_0c04384e: /* original d334, guest PC 0x0c04384e */
if(!s->budget--) { s->failed_pc=0x0c04384eu; return 0; }
r[3]=read(ram,0x0c043920u,4);
goto P_0c043850;
P_0c043850: /* original 611c, guest PC 0x0c043850 */
if(!s->budget--) { s->failed_pc=0x0c043850u; return 0; }
r[1]=r[1]&255u;
goto P_0c043852;
P_0c043852: /* original 430b, guest PC 0x0c043852 */
if(!s->budget--) { s->failed_pc=0x0c043852u; return 0; }
target=r[3];
r[16]=code_base|0x0c043856u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043856u) { target=s->pc; goto dispatch; }
goto P_0c043856;
P_0c043854: /* original e002, guest PC 0x0c043854 */
if(!s->budget--) { s->failed_pc=0x0c043854u; return 0; }
r[0]=0x00000002u;
goto P_0c043856;
P_0c043856: /* original 61d0, guest PC 0x0c043856 */
if(!s->budget--) { s->failed_pc=0x0c043856u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[1]=tmp;
goto P_0c043858;
P_0c043858: /* original 62f2, guest PC 0x0c043858 */
if(!s->budget--) { s->failed_pc=0x0c043858u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04385a;
P_0c04385a: /* original 611c, guest PC 0x0c04385a */
if(!s->budget--) { s->failed_pc=0x0c04385au; return 0; }
r[1]=r[1]&255u;
goto P_0c04385c;
P_0c04385c: /* original 310c, guest PC 0x0c04385c */
if(!s->budget--) { s->failed_pc=0x0c04385cu; return 0; }
r[1]+=r[0];
goto P_0c04385e;
P_0c04385e: /* original 7108, guest PC 0x0c04385e */
if(!s->budget--) { s->failed_pc=0x0c04385eu; return 0; }
r[1]+=0x00000008u;
goto P_0c043860;
P_0c043860: /* original 31ec, guest PC 0x0c043860 */
if(!s->budget--) { s->failed_pc=0x0c043860u; return 0; }
r[1]+=r[14];
goto P_0c043862;
P_0c043862: /* original 3122, guest PC 0x0c043862 */
if(!s->budget--) { s->failed_pc=0x0c043862u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c043864;
P_0c043864: /* original 8b13, guest PC 0x0c043864 */
if(!s->budget--) { s->failed_pc=0x0c043864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04388e; }
goto P_0c043866;
P_0c043866: /* original 6693, guest PC 0x0c043866 */
if(!s->budget--) { s->failed_pc=0x0c043866u; return 0; }
r[6]=r[9];
goto P_0c043868;
P_0c043868: /* original 36e8, guest PC 0x0c043868 */
if(!s->budget--) { s->failed_pc=0x0c043868u; return 0; }
r[6]-=r[14];
goto P_0c04386a;
P_0c04386a: /* original 6d93, guest PC 0x0c04386a */
if(!s->budget--) { s->failed_pc=0x0c04386au; return 0; }
r[13]=r[9];
goto P_0c04386c;
P_0c04386c: /* original 368c, guest PC 0x0c04386c */
if(!s->budget--) { s->failed_pc=0x0c04386cu; return 0; }
r[6]+=r[8];
goto P_0c04386e;
P_0c04386e: /* original 3d68, guest PC 0x0c04386e */
if(!s->budget--) { s->failed_pc=0x0c04386eu; return 0; }
r[13]-=r[6];
goto P_0c043870;
P_0c043870: /* original 65d3, guest PC 0x0c043870 */
if(!s->budget--) { s->failed_pc=0x0c043870u; return 0; }
r[5]=r[13];
goto P_0c043872;
P_0c043872: /* original be45, guest PC 0x0c043872 */
if(!s->budget--) { s->failed_pc=0x0c043872u; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c043876u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043876u) { target=s->pc; goto dispatch; }
goto P_0c043876;
P_0c043874: /* original 64e3, guest PC 0x0c043874 */
if(!s->budget--) { s->failed_pc=0x0c043874u; return 0; }
r[4]=r[14];
goto P_0c043876;
P_0c043876: /* original d32b, guest PC 0x0c043876 */
if(!s->budget--) { s->failed_pc=0x0c043876u; return 0; }
r[3]=read(ram,0x0c043924u,4);
goto P_0c043878;
P_0c043878: /* original e501, guest PC 0x0c043878 */
if(!s->budget--) { s->failed_pc=0x0c043878u; return 0; }
r[5]=0x00000001u;
goto P_0c04387a;
P_0c04387a: /* original 6693, guest PC 0x0c04387a */
if(!s->budget--) { s->failed_pc=0x0c04387au; return 0; }
r[6]=r[9];
goto P_0c04387c;
P_0c04387c: /* original 430b, guest PC 0x0c04387c */
if(!s->budget--) { s->failed_pc=0x0c04387cu; return 0; }
target=r[3];
r[16]=code_base|0x0c043880u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c043880u) { target=s->pc; goto dispatch; }
goto P_0c043880;
P_0c04387e: /* original 54f2, guest PC 0x0c04387e */
if(!s->budget--) { s->failed_pc=0x0c04387eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c043880;
P_0c043880: /* original 6403, guest PC 0x0c043880 */
if(!s->budget--) { s->failed_pc=0x0c043880u; return 0; }
r[4]=r[0];
goto P_0c043882;
P_0c043882: /* original 2448, guest PC 0x0c043882 */
if(!s->budget--) { s->failed_pc=0x0c043882u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c043884;
P_0c043884: /* original 8b40, guest PC 0x0c043884 */
if(!s->budget--) { s->failed_pc=0x0c043884u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c043908; }
goto P_0c043886;
P_0c043886: /* original 53f2, guest PC 0x0c043886 */
if(!s->budget--) { s->failed_pc=0x0c043886u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c043888;
P_0c043888: /* original 6ed3, guest PC 0x0c043888 */
if(!s->budget--) { s->failed_pc=0x0c043888u; return 0; }
r[14]=r[13];
goto P_0c04388a;
P_0c04388a: /* original 7301, guest PC 0x0c04388a */
if(!s->budget--) { s->failed_pc=0x0c04388au; return 0; }
r[3]+=0x00000001u;
goto P_0c04388c;
P_0c04388c: /* original 1f32, guest PC 0x0c04388c */
if(!s->budget--) { s->failed_pc=0x0c04388cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c04388e;
P_0c04388e: /* original 65f3, guest PC 0x0c04388e */
if(!s->budget--) { s->failed_pc=0x0c04388eu; return 0; }
r[5]=r[15];
goto P_0c043890;
P_0c043890: /* original 64d3, guest PC 0x0c043890 */
if(!s->budget--) { s->failed_pc=0x0c043890u; return 0; }
r[4]=r[13];
goto P_0c043892;
P_0c043892: /* original 7504, guest PC 0x0c043892 */
if(!s->budget--) { s->failed_pc=0x0c043892u; return 0; }
r[5]+=0x00000004u;
goto P_0c043894;
P_0c043894: /* original e602, guest PC 0x0c043894 */
if(!s->budget--) { s->failed_pc=0x0c043894u; return 0; }
r[6]=0x00000002u;
goto P_0c043896;
P_0c043896: /* original be33, guest PC 0x0c043896 */
if(!s->budget--) { s->failed_pc=0x0c043896u; return 0; }
target=code_base|0x0c043500u; r[16]=code_base|0x0c04389au;
r[4]+=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04389au) { target=s->pc; goto dispatch; }
goto P_0c04389a;
P_0c043898: /* original 7406, guest PC 0x0c043898 */
if(!s->budget--) { s->failed_pc=0x0c043898u; return 0; }
r[4]+=0x00000006u;
goto P_0c04389a;
P_0c04389a: /* original 85f2, guest PC 0x0c04389a */
if(!s->budget--) { s->failed_pc=0x0c04389au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c04389c;
P_0c04389c: /* original 53f5, guest PC 0x0c04389c */
if(!s->budget--) { s->failed_pc=0x0c04389cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c04389e;
P_0c04389e: /* original 600d, guest PC 0x0c04389e */
if(!s->budget--) { s->failed_pc=0x0c04389eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0438a0;
P_0c0438a0: /* original 3030, guest PC 0x0c0438a0 */
if(!s->budget--) { s->failed_pc=0x0c0438a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0438a2;
P_0c0438a2: /* original 8b20, guest PC 0x0c0438a2 */
if(!s->budget--) { s->failed_pc=0x0c0438a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0438e6; }
goto P_0c0438a4;
P_0c0438a4: /* original 60b3, guest PC 0x0c0438a4 */
if(!s->budget--) { s->failed_pc=0x0c0438a4u; return 0; }
r[0]=r[11];
goto P_0c0438a6;
P_0c0438a6: /* original 8801, guest PC 0x0c0438a6 */
if(!s->budget--) { s->failed_pc=0x0c0438a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0438a8;
P_0c0438a8: /* original 890a, guest PC 0x0c0438a8 */
if(!s->budget--) { s->failed_pc=0x0c0438a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0438c0; }
goto P_0c0438aa;
P_0c0438aa: /* original 62d0, guest PC 0x0c0438aa */
if(!s->budget--) { s->failed_pc=0x0c0438aau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[2]=tmp;
goto P_0c0438ac;
P_0c0438ac: /* original 622c, guest PC 0x0c0438ac */
if(!s->budget--) { s->failed_pc=0x0c0438acu; return 0; }
r[2]=r[2]&255u;
goto P_0c0438ae;
P_0c0438ae: /* original 32a0, guest PC 0x0c0438ae */
if(!s->budget--) { s->failed_pc=0x0c0438aeu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[10])!=0);
goto P_0c0438b0;
P_0c0438b0: /* original 8b19, guest PC 0x0c0438b0 */
if(!s->budget--) { s->failed_pc=0x0c0438b0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0438e6; }
goto P_0c0438b2;
P_0c0438b2: /* original 64d3, guest PC 0x0c0438b2 */
if(!s->budget--) { s->failed_pc=0x0c0438b2u; return 0; }
r[4]=r[13];
goto P_0c0438b4;
P_0c0438b4: /* original 65c3, guest PC 0x0c0438b4 */
if(!s->budget--) { s->failed_pc=0x0c0438b4u; return 0; }
r[5]=r[12];
goto P_0c0438b6;
P_0c0438b6: /* original 66a3, guest PC 0x0c0438b6 */
if(!s->budget--) { s->failed_pc=0x0c0438b6u; return 0; }
r[6]=r[10];
goto P_0c0438b8;
P_0c0438b8: /* original be2e, guest PC 0x0c0438b8 */
if(!s->budget--) { s->failed_pc=0x0c0438b8u; return 0; }
target=code_base|0x0c043518u; r[16]=code_base|0x0c0438bcu;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438bcu) { target=s->pc; goto dispatch; }
goto P_0c0438bc;
P_0c0438ba: /* original 7408, guest PC 0x0c0438ba */
if(!s->budget--) { s->failed_pc=0x0c0438bau; return 0; }
r[4]+=0x00000008u;
goto P_0c0438bc;
P_0c0438bc: /* original 2008, guest PC 0x0c0438bc */
if(!s->budget--) { s->failed_pc=0x0c0438bcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0438be;
P_0c0438be: /* original 8912, guest PC 0x0c0438be */
if(!s->budget--) { s->failed_pc=0x0c0438beu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0438e6; }
goto P_0c0438c0;
P_0c0438c0: /* original 3cac, guest PC 0x0c0438c0 */
if(!s->budget--) { s->failed_pc=0x0c0438c0u; return 0; }
r[12]+=r[10];
goto P_0c0438c2;
P_0c0438c2: /* original 1fb5, guest PC 0x0c0438c2 */
if(!s->budget--) { s->failed_pc=0x0c0438c2u; return 0; }
write(ram,r[15]+20,r[11],4);
goto P_0c0438c4;
P_0c0438c4: /* original 63c0, guest PC 0x0c0438c4 */
if(!s->budget--) { s->failed_pc=0x0c0438c4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c0438c6;
P_0c0438c6: /* original 2338, guest PC 0x0c0438c6 */
if(!s->budget--) { s->failed_pc=0x0c0438c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0438c8;
P_0c0438c8: /* original 8b05, guest PC 0x0c0438c8 */
if(!s->budget--) { s->failed_pc=0x0c0438c8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0438d6; }
goto P_0c0438ca;
P_0c0438ca: /* original d317, guest PC 0x0c0438ca */
if(!s->budget--) { s->failed_pc=0x0c0438cau; return 0; }
r[3]=read(ram,0x0c043928u,4);
goto P_0c0438cc;
P_0c0438cc: /* original 64d3, guest PC 0x0c0438cc */
if(!s->budget--) { s->failed_pc=0x0c0438ccu; return 0; }
r[4]=r[13];
goto P_0c0438ce;
P_0c0438ce: /* original 430b, guest PC 0x0c0438ce */
if(!s->budget--) { s->failed_pc=0x0c0438ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0438d2u;
r[4]+=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438d2u) { target=s->pc; goto dispatch; }
goto P_0c0438d2;
P_0c0438d0: /* original 7402, guest PC 0x0c0438d0 */
if(!s->budget--) { s->failed_pc=0x0c0438d0u; return 0; }
r[4]+=0x00000002u;
goto P_0c0438d2;
P_0c0438d2: /* original a01a, guest PC 0x0c0438d2 */
if(!s->budget--) { s->failed_pc=0x0c0438d2u; return 0; }
goto P_0c04390a;
P_0c0438d4: /* original 0009, guest PC 0x0c0438d4 */
if(!s->budget--) { s->failed_pc=0x0c0438d4u; return 0; }
goto P_0c0438d6;
P_0c0438d6: /* original 60b3, guest PC 0x0c0438d6 */
if(!s->budget--) { s->failed_pc=0x0c0438d6u; return 0; }
r[0]=r[11];
goto P_0c0438d8;
P_0c0438d8: /* original 8801, guest PC 0x0c0438d8 */
if(!s->budget--) { s->failed_pc=0x0c0438d8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0438da;
P_0c0438da: /* original 8900, guest PC 0x0c0438da */
if(!s->budget--) { s->failed_pc=0x0c0438dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0438de; }
goto P_0c0438dc;
P_0c0438dc: /* original 7c01, guest PC 0x0c0438dc */
if(!s->budget--) { s->failed_pc=0x0c0438dcu; return 0; }
r[12]+=0x00000001u;
goto P_0c0438de;
P_0c0438de: /* original d513, guest PC 0x0c0438de */
if(!s->budget--) { s->failed_pc=0x0c0438deu; return 0; }
r[5]=read(ram,0x0c04392cu,4);
goto P_0c0438e0;
P_0c0438e0: /* original be7b, guest PC 0x0c0438e0 */
if(!s->budget--) { s->failed_pc=0x0c0438e0u; return 0; }
target=code_base|0x0c0435dau; r[16]=code_base|0x0c0438e4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438e4u) { target=s->pc; goto dispatch; }
goto P_0c0438e4;
P_0c0438e2: /* original 64c3, guest PC 0x0c0438e2 */
if(!s->budget--) { s->failed_pc=0x0c0438e2u; return 0; }
r[4]=r[12];
goto P_0c0438e4;
P_0c0438e4: /* original 6a03, guest PC 0x0c0438e4 */
if(!s->budget--) { s->failed_pc=0x0c0438e4u; return 0; }
r[10]=r[0];
goto P_0c0438e6;
P_0c0438e6: /* original 65d0, guest PC 0x0c0438e6 */
if(!s->budget--) { s->failed_pc=0x0c0438e6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[5]=tmp;
goto P_0c0438e8;
P_0c0438e8: /* original 7b01, guest PC 0x0c0438e8 */
if(!s->budget--) { s->failed_pc=0x0c0438e8u; return 0; }
r[11]+=0x00000001u;
goto P_0c0438ea;
P_0c0438ea: /* original d20d, guest PC 0x0c0438ea */
if(!s->budget--) { s->failed_pc=0x0c0438eau; return 0; }
r[2]=read(ram,0x0c043920u,4);
goto P_0c0438ec;
P_0c0438ec: /* original 655c, guest PC 0x0c0438ec */
if(!s->budget--) { s->failed_pc=0x0c0438ecu; return 0; }
r[5]=r[5]&255u;
goto P_0c0438ee;
P_0c0438ee: /* original 6153, guest PC 0x0c0438ee */
if(!s->budget--) { s->failed_pc=0x0c0438eeu; return 0; }
r[1]=r[5];
goto P_0c0438f0;
P_0c0438f0: /* original 420b, guest PC 0x0c0438f0 */
if(!s->budget--) { s->failed_pc=0x0c0438f0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0438f4u;
r[0]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0438f4u) { target=s->pc; goto dispatch; }
goto P_0c0438f4;
P_0c0438f2: /* original e002, guest PC 0x0c0438f2 */
if(!s->budget--) { s->failed_pc=0x0c0438f2u; return 0; }
r[0]=0x00000002u;
goto P_0c0438f4;
P_0c0438f4: /* original 6453, guest PC 0x0c0438f4 */
if(!s->budget--) { s->failed_pc=0x0c0438f4u; return 0; }
r[4]=r[5];
goto P_0c0438f6;
P_0c0438f6: /* original 53f3, guest PC 0x0c0438f6 */
if(!s->budget--) { s->failed_pc=0x0c0438f6u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0438f8;
P_0c0438f8: /* original 340c, guest PC 0x0c0438f8 */
if(!s->budget--) { s->failed_pc=0x0c0438f8u; return 0; }
r[4]+=r[0];
goto P_0c0438fa;
P_0c0438fa: /* original 7408, guest PC 0x0c0438fa */
if(!s->budget--) { s->failed_pc=0x0c0438fau; return 0; }
r[4]+=0x00000008u;
goto P_0c0438fc;
P_0c0438fc: /* original 334c, guest PC 0x0c0438fc */
if(!s->budget--) { s->failed_pc=0x0c0438fcu; return 0; }
r[3]+=r[4];
goto P_0c0438fe;
P_0c0438fe: /* original 1f33, guest PC 0x0c0438fe */
if(!s->budget--) { s->failed_pc=0x0c0438feu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c043900;
P_0c043900: /* original 52f4, guest PC 0x0c043900 */
if(!s->budget--) { s->failed_pc=0x0c043900u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c043902;
P_0c043902: /* original 3323, guest PC 0x0c043902 */
if(!s->budget--) { s->failed_pc=0x0c043902u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c043904;
P_0c043904: /* original 8f9e, guest PC 0x0c043904 */
if(!s->budget--) { s->failed_pc=0x0c043904u; return 0; }
cond=r[17]&1u;
r[14]+=r[4];
if(!cond) { goto P_0c043844; }
goto P_0c043908;
P_0c043906: /* original 3e4c, guest PC 0x0c043906 */
if(!s->budget--) { s->failed_pc=0x0c043906u; return 0; }
r[14]+=r[4];
goto P_0c043908;
P_0c043908: /* original e000, guest PC 0x0c043908 */
if(!s->budget--) { s->failed_pc=0x0c043908u; return 0; }
r[0]=0x00000000u;
goto P_0c04390a;
P_0c04390a: /* original 7f18, guest PC 0x0c04390a */
if(!s->budget--) { s->failed_pc=0x0c04390au; return 0; }
r[15]+=0x00000018u;
goto P_0c04390c;
P_0c04390c: /* original 4f26, guest PC 0x0c04390c */
if(!s->budget--) { s->failed_pc=0x0c04390cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04390e;
P_0c04390e: /* original 68f6, guest PC 0x0c04390e */
if(!s->budget--) { s->failed_pc=0x0c04390eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c043910;
P_0c043910: /* original 69f6, guest PC 0x0c043910 */
if(!s->budget--) { s->failed_pc=0x0c043910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c043912;
P_0c043912: /* original 6af6, guest PC 0x0c043912 */
if(!s->budget--) { s->failed_pc=0x0c043912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c043914;
P_0c043914: /* original 6bf6, guest PC 0x0c043914 */
if(!s->budget--) { s->failed_pc=0x0c043914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c043916;
P_0c043916: /* original 6cf6, guest PC 0x0c043916 */
if(!s->budget--) { s->failed_pc=0x0c043916u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c043918;
P_0c043918: /* original 6df6, guest PC 0x0c043918 */
if(!s->budget--) { s->failed_pc=0x0c043918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04391a;
P_0c04391a: /* original 000b, guest PC 0x0c04391a */
if(!s->budget--) { s->failed_pc=0x0c04391au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04391c: /* original 6ef6, guest PC 0x0c04391c */
if(!s->budget--) { s->failed_pc=0x0c04391cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04391eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04391eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
