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
int vf3_away_batch94_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0bb662u: goto P_0c0bb662;
case 0x0c0bb664u: goto P_0c0bb664;
case 0x0c0bb666u: goto P_0c0bb666;
case 0x0c0bb668u: goto P_0c0bb668;
case 0x0c0bb66au: goto P_0c0bb66a;
case 0x0c0bb66cu: goto P_0c0bb66c;
case 0x0c0bb66eu: goto P_0c0bb66e;
case 0x0c0bb670u: goto P_0c0bb670;
case 0x0c0bb672u: goto P_0c0bb672;
case 0x0c0bb674u: goto P_0c0bb674;
case 0x0c0bb676u: goto P_0c0bb676;
case 0x0c0bb678u: goto P_0c0bb678;
case 0x0c0bb67au: goto P_0c0bb67a;
case 0x0c0bb67cu: goto P_0c0bb67c;
case 0x0c0bb67eu: goto P_0c0bb67e;
case 0x0c0bb680u: goto P_0c0bb680;
case 0x0c0bb682u: goto P_0c0bb682;
case 0x0c0bb684u: goto P_0c0bb684;
case 0x0c0bb686u: goto P_0c0bb686;
case 0x0c0bb688u: goto P_0c0bb688;
case 0x0c0bb68au: goto P_0c0bb68a;
case 0x0c0bb68cu: goto P_0c0bb68c;
case 0x0c0bb68eu: goto P_0c0bb68e;
case 0x0c0bb690u: goto P_0c0bb690;
case 0x0c0bb692u: goto P_0c0bb692;
case 0x0c0bb694u: goto P_0c0bb694;
case 0x0c0bb696u: goto P_0c0bb696;
case 0x0c0bb698u: goto P_0c0bb698;
case 0x0c0bb69au: goto P_0c0bb69a;
case 0x0c0bb69cu: goto P_0c0bb69c;
case 0x0c0bb69eu: goto P_0c0bb69e;
case 0x0c0bb6a0u: goto P_0c0bb6a0;
case 0x0c0bb6a2u: goto P_0c0bb6a2;
case 0x0c0bb6a4u: goto P_0c0bb6a4;
case 0x0c0bb6a6u: goto P_0c0bb6a6;
case 0x0c0bb6a8u: goto P_0c0bb6a8;
case 0x0c0bb6aau: goto P_0c0bb6aa;
case 0x0c0bb6acu: goto P_0c0bb6ac;
case 0x0c0bb6aeu: goto P_0c0bb6ae;
case 0x0c0bb6b0u: goto P_0c0bb6b0;
case 0x0c0bb6b2u: goto P_0c0bb6b2;
case 0x0c0bb6b4u: goto P_0c0bb6b4;
case 0x0c0bb6b6u: goto P_0c0bb6b6;
case 0x0c0bb6b8u: goto P_0c0bb6b8;
case 0x0c0bb6bau: goto P_0c0bb6ba;
case 0x0c0bb6bcu: goto P_0c0bb6bc;
case 0x0c0bb6beu: goto P_0c0bb6be;
case 0x0c0bb6c0u: goto P_0c0bb6c0;
case 0x0c0bb6c2u: goto P_0c0bb6c2;
case 0x0c0bb6c4u: goto P_0c0bb6c4;
case 0x0c0bb6c6u: goto P_0c0bb6c6;
case 0x0c0bb6c8u: goto P_0c0bb6c8;
case 0x0c0bb6cau: goto P_0c0bb6ca;
case 0x0c0bb6ccu: goto P_0c0bb6cc;
case 0x0c0bb6ceu: goto P_0c0bb6ce;
case 0x0c0bb6d0u: goto P_0c0bb6d0;
case 0x0c0bb6d2u: goto P_0c0bb6d2;
case 0x0c0bb6d4u: goto P_0c0bb6d4;
case 0x0c0bb6d6u: goto P_0c0bb6d6;
case 0x0c0bb6d8u: goto P_0c0bb6d8;
case 0x0c0bb6dau: goto P_0c0bb6da;
case 0x0c0bb6dcu: goto P_0c0bb6dc;
case 0x0c0bb6deu: goto P_0c0bb6de;
case 0x0c0bb6e0u: goto P_0c0bb6e0;
case 0x0c0bb6e2u: goto P_0c0bb6e2;
case 0x0c0bb6e4u: goto P_0c0bb6e4;
case 0x0c0bb6e6u: goto P_0c0bb6e6;
case 0x0c0bb6e8u: goto P_0c0bb6e8;
case 0x0c0bb6eau: goto P_0c0bb6ea;
case 0x0c0bb6ecu: goto P_0c0bb6ec;
case 0x0c0bb6eeu: goto P_0c0bb6ee;
case 0x0c0bb6f0u: goto P_0c0bb6f0;
case 0x0c0bb6f2u: goto P_0c0bb6f2;
case 0x0c0bb6f4u: goto P_0c0bb6f4;
case 0x0c0bb6f6u: goto P_0c0bb6f6;
case 0x0c0bb6f8u: goto P_0c0bb6f8;
case 0x0c0bb6fau: goto P_0c0bb6fa;
case 0x0c0bb6fcu: goto P_0c0bb6fc;
case 0x0c0bb6feu: goto P_0c0bb6fe;
case 0x0c0bb700u: goto P_0c0bb700;
case 0x0c0bb702u: goto P_0c0bb702;
case 0x0c0bb704u: goto P_0c0bb704;
case 0x0c0bb706u: goto P_0c0bb706;
case 0x0c0bb708u: goto P_0c0bb708;
case 0x0c0bb70au: goto P_0c0bb70a;
case 0x0c0bb70cu: goto P_0c0bb70c;
case 0x0c0bb70eu: goto P_0c0bb70e;
case 0x0c0bb710u: goto P_0c0bb710;
case 0x0c0bb712u: goto P_0c0bb712;
case 0x0c0bb714u: goto P_0c0bb714;
case 0x0c0bb716u: goto P_0c0bb716;
case 0x0c0bb718u: goto P_0c0bb718;
case 0x0c0bb71au: goto P_0c0bb71a;
case 0x0c0bb71cu: goto P_0c0bb71c;
case 0x0c0bb71eu: goto P_0c0bb71e;
case 0x0c0bb720u: goto P_0c0bb720;
case 0x0c0bb722u: goto P_0c0bb722;
case 0x0c0bb724u: goto P_0c0bb724;
case 0x0c0bb726u: goto P_0c0bb726;
case 0x0c0bb728u: goto P_0c0bb728;
case 0x0c0bb72au: goto P_0c0bb72a;
case 0x0c0bb72cu: goto P_0c0bb72c;
case 0x0c0bb72eu: goto P_0c0bb72e;
case 0x0c0bb730u: goto P_0c0bb730;
case 0x0c0bb732u: goto P_0c0bb732;
case 0x0c0bb734u: goto P_0c0bb734;
case 0x0c0bb736u: goto P_0c0bb736;
case 0x0c0bb738u: goto P_0c0bb738;
case 0x0c0bb73au: goto P_0c0bb73a;
case 0x0c0bb73cu: goto P_0c0bb73c;
case 0x0c0bb73eu: goto P_0c0bb73e;
case 0x0c0bb740u: goto P_0c0bb740;
case 0x0c0bb742u: goto P_0c0bb742;
case 0x0c0bb744u: goto P_0c0bb744;
case 0x0c0bb746u: goto P_0c0bb746;
case 0x0c0bb748u: goto P_0c0bb748;
case 0x0c0bb74au: goto P_0c0bb74a;
case 0x0c0bb74cu: goto P_0c0bb74c;
case 0x0c0bb74eu: goto P_0c0bb74e;
case 0x0c0bb750u: goto P_0c0bb750;
case 0x0c0bb752u: goto P_0c0bb752;
case 0x0c0bb754u: goto P_0c0bb754;
case 0x0c0bb756u: goto P_0c0bb756;
case 0x0c0bb758u: goto P_0c0bb758;
case 0x0c0bb75au: goto P_0c0bb75a;
case 0x0c0bb75cu: goto P_0c0bb75c;
case 0x0c0bb75eu: goto P_0c0bb75e;
case 0x0c0bb760u: goto P_0c0bb760;
case 0x0c0bb762u: goto P_0c0bb762;
case 0x0c0bb764u: goto P_0c0bb764;
case 0x0c0bb766u: goto P_0c0bb766;
case 0x0c0bb768u: goto P_0c0bb768;
case 0x0c0bb76au: goto P_0c0bb76a;
case 0x0c0bb76cu: goto P_0c0bb76c;
case 0x0c0bb76eu: goto P_0c0bb76e;
case 0x0c0bb770u: goto P_0c0bb770;
case 0x0c0bb772u: goto P_0c0bb772;
case 0x0c0bb774u: goto P_0c0bb774;
case 0x0c0bb776u: goto P_0c0bb776;
case 0x0c0bb778u: goto P_0c0bb778;
case 0x0c0bb77au: goto P_0c0bb77a;
case 0x0c0bb77cu: goto P_0c0bb77c;
case 0x0c0bb77eu: goto P_0c0bb77e;
case 0x0c0bb780u: goto P_0c0bb780;
case 0x0c0bb782u: goto P_0c0bb782;
case 0x0c0bb784u: goto P_0c0bb784;
case 0x0c0bb786u: goto P_0c0bb786;
case 0x0c0bb788u: goto P_0c0bb788;
case 0x0c0bb78au: goto P_0c0bb78a;
case 0x0c0bb78cu: goto P_0c0bb78c;
case 0x0c0bb78eu: goto P_0c0bb78e;
case 0x0c0bb790u: goto P_0c0bb790;
case 0x0c0bb792u: goto P_0c0bb792;
case 0x0c0bb794u: goto P_0c0bb794;
case 0x0c0bb796u: goto P_0c0bb796;
case 0x0c0bb798u: goto P_0c0bb798;
case 0x0c0bb79au: goto P_0c0bb79a;
case 0x0c0bb79cu: goto P_0c0bb79c;
case 0x0c0bb79eu: goto P_0c0bb79e;
case 0x0c0bb7a0u: goto P_0c0bb7a0;
case 0x0c0bb7a2u: goto P_0c0bb7a2;
case 0x0c0bb7a4u: goto P_0c0bb7a4;
case 0x0c0bb7a6u: goto P_0c0bb7a6;
case 0x0c0bb7a8u: goto P_0c0bb7a8;
case 0x0c0bb7aau: goto P_0c0bb7aa;
case 0x0c0bb7acu: goto P_0c0bb7ac;
case 0x0c0bb7aeu: goto P_0c0bb7ae;
case 0x0c0bb7b0u: goto P_0c0bb7b0;
case 0x0c0bb7b2u: goto P_0c0bb7b2;
case 0x0c0bb7b4u: goto P_0c0bb7b4;
case 0x0c0bb7b6u: goto P_0c0bb7b6;
case 0x0c0bb7b8u: goto P_0c0bb7b8;
case 0x0c0bb7bau: goto P_0c0bb7ba;
case 0x0c0bb7bcu: goto P_0c0bb7bc;
case 0x0c0bb7beu: goto P_0c0bb7be;
case 0x0c0bb7c0u: goto P_0c0bb7c0;
case 0x0c0bb7c2u: goto P_0c0bb7c2;
case 0x0c0bb7c4u: goto P_0c0bb7c4;
case 0x0c0bb834u: goto P_0c0bb834;
case 0x0c0bb836u: goto P_0c0bb836;
case 0x0c0bb838u: goto P_0c0bb838;
case 0x0c0bb83au: goto P_0c0bb83a;
case 0x0c0bb83cu: goto P_0c0bb83c;
case 0x0c0bb83eu: goto P_0c0bb83e;
case 0x0c0bb840u: goto P_0c0bb840;
case 0x0c0bb842u: goto P_0c0bb842;
case 0x0c0bb844u: goto P_0c0bb844;
case 0x0c0bb846u: goto P_0c0bb846;
case 0x0c0bb848u: goto P_0c0bb848;
case 0x0c0bb84au: goto P_0c0bb84a;
case 0x0c0bb84cu: goto P_0c0bb84c;
case 0x0c0bb84eu: goto P_0c0bb84e;
case 0x0c0bb850u: goto P_0c0bb850;
case 0x0c0bb852u: goto P_0c0bb852;
case 0x0c0bb854u: goto P_0c0bb854;
case 0x0c0bb856u: goto P_0c0bb856;
case 0x0c0bb858u: goto P_0c0bb858;
case 0x0c0bb85au: goto P_0c0bb85a;
case 0x0c0bb85cu: goto P_0c0bb85c;
case 0x0c0bb85eu: goto P_0c0bb85e;
case 0x0c0bb860u: goto P_0c0bb860;
case 0x0c0bb862u: goto P_0c0bb862;
case 0x0c0bb864u: goto P_0c0bb864;
case 0x0c0bb866u: goto P_0c0bb866;
case 0x0c0bb868u: goto P_0c0bb868;
case 0x0c0bb86au: goto P_0c0bb86a;
case 0x0c0bb86cu: goto P_0c0bb86c;
case 0x0c0bb86eu: goto P_0c0bb86e;
case 0x0c0bb870u: goto P_0c0bb870;
case 0x0c0bb872u: goto P_0c0bb872;
case 0x0c0bb874u: goto P_0c0bb874;
case 0x0c0bb876u: goto P_0c0bb876;
case 0x0c0bb878u: goto P_0c0bb878;
case 0x0c0bb87au: goto P_0c0bb87a;
case 0x0c0bb87cu: goto P_0c0bb87c;
case 0x0c0bb87eu: goto P_0c0bb87e;
case 0x0c0bb880u: goto P_0c0bb880;
case 0x0c0bb882u: goto P_0c0bb882;
case 0x0c0bb884u: goto P_0c0bb884;
case 0x0c0bb886u: goto P_0c0bb886;
case 0x0c0bb888u: goto P_0c0bb888;
case 0x0c0bb88au: goto P_0c0bb88a;
case 0x0c0bb88cu: goto P_0c0bb88c;
case 0x0c0bb88eu: goto P_0c0bb88e;
case 0x0c0bb890u: goto P_0c0bb890;
case 0x0c0bb892u: goto P_0c0bb892;
case 0x0c0bb894u: goto P_0c0bb894;
case 0x0c0bb896u: goto P_0c0bb896;
case 0x0c0bb898u: goto P_0c0bb898;
case 0x0c0bb89au: goto P_0c0bb89a;
case 0x0c0bb89cu: goto P_0c0bb89c;
case 0x0c0bb89eu: goto P_0c0bb89e;
case 0x0c0bb8a0u: goto P_0c0bb8a0;
case 0x0c0bb8a2u: goto P_0c0bb8a2;
case 0x0c0bb8a4u: goto P_0c0bb8a4;
case 0x0c0bb8a6u: goto P_0c0bb8a6;
case 0x0c0bb8a8u: goto P_0c0bb8a8;
case 0x0c0bb8aau: goto P_0c0bb8aa;
case 0x0c0bb8acu: goto P_0c0bb8ac;
case 0x0c0bb8aeu: goto P_0c0bb8ae;
case 0x0c0bb8b0u: goto P_0c0bb8b0;
case 0x0c0bb8b2u: goto P_0c0bb8b2;
case 0x0c0bb8b4u: goto P_0c0bb8b4;
case 0x0c0bb8b6u: goto P_0c0bb8b6;
case 0x0c0bb8b8u: goto P_0c0bb8b8;
case 0x0c0bb8bau: goto P_0c0bb8ba;
case 0x0c0bb8bcu: goto P_0c0bb8bc;
case 0x0c0bb8beu: goto P_0c0bb8be;
case 0x0c0bb8c0u: goto P_0c0bb8c0;
case 0x0c0bb8c2u: goto P_0c0bb8c2;
case 0x0c0bb8c4u: goto P_0c0bb8c4;
case 0x0c0bb8c6u: goto P_0c0bb8c6;
case 0x0c0bb8c8u: goto P_0c0bb8c8;
case 0x0c0bb8cau: goto P_0c0bb8ca;
case 0x0c0bb8ccu: goto P_0c0bb8cc;
case 0x0c0bb8ceu: goto P_0c0bb8ce;
case 0x0c0bb8d0u: goto P_0c0bb8d0;
case 0x0c0bb8d2u: goto P_0c0bb8d2;
case 0x0c0bb8d4u: goto P_0c0bb8d4;
case 0x0c0bb8d6u: goto P_0c0bb8d6;
case 0x0c0bb8d8u: goto P_0c0bb8d8;
case 0x0c0bb8dau: goto P_0c0bb8da;
case 0x0c0bb8dcu: goto P_0c0bb8dc;
case 0x0c0bb8deu: goto P_0c0bb8de;
case 0x0c0bb8e0u: goto P_0c0bb8e0;
case 0x0c0bb8e2u: goto P_0c0bb8e2;
case 0x0c0bb8e4u: goto P_0c0bb8e4;
case 0x0c0bb8e6u: goto P_0c0bb8e6;
case 0x0c0bb8e8u: goto P_0c0bb8e8;
case 0x0c0bb8eau: goto P_0c0bb8ea;
case 0x0c0bb8ecu: goto P_0c0bb8ec;
case 0x0c0bb8eeu: goto P_0c0bb8ee;
case 0x0c0bb8f0u: goto P_0c0bb8f0;
case 0x0c0bb8f2u: goto P_0c0bb8f2;
case 0x0c0bb8f4u: goto P_0c0bb8f4;
case 0x0c0bb8f6u: goto P_0c0bb8f6;
case 0x0c0bb8f8u: goto P_0c0bb8f8;
case 0x0c0bb8fau: goto P_0c0bb8fa;
case 0x0c0bb8fcu: goto P_0c0bb8fc;
case 0x0c0bb8feu: goto P_0c0bb8fe;
case 0x0c0bb900u: goto P_0c0bb900;
case 0x0c0bb902u: goto P_0c0bb902;
case 0x0c0bb904u: goto P_0c0bb904;
case 0x0c0bb906u: goto P_0c0bb906;
case 0x0c0bb908u: goto P_0c0bb908;
case 0x0c0bb90au: goto P_0c0bb90a;
case 0x0c0bb90cu: goto P_0c0bb90c;
case 0x0c0bb90eu: goto P_0c0bb90e;
case 0x0c0bb910u: goto P_0c0bb910;
case 0x0c0bb912u: goto P_0c0bb912;
case 0x0c0bb914u: goto P_0c0bb914;
case 0x0c0bb916u: goto P_0c0bb916;
case 0x0c0bb918u: goto P_0c0bb918;
case 0x0c0bb91au: goto P_0c0bb91a;
case 0x0c0bb91cu: goto P_0c0bb91c;
case 0x0c0bb91eu: goto P_0c0bb91e;
case 0x0c0bb920u: goto P_0c0bb920;
case 0x0c0bb922u: goto P_0c0bb922;
case 0x0c0bb924u: goto P_0c0bb924;
case 0x0c0bb926u: goto P_0c0bb926;
case 0x0c0bb928u: goto P_0c0bb928;
case 0x0c0bb92au: goto P_0c0bb92a;
case 0x0c0bb92cu: goto P_0c0bb92c;
case 0x0c0bb92eu: goto P_0c0bb92e;
case 0x0c0bb930u: goto P_0c0bb930;
case 0x0c0bb932u: goto P_0c0bb932;
case 0x0c0bb934u: goto P_0c0bb934;
case 0x0c0bb936u: goto P_0c0bb936;
case 0x0c0bb938u: goto P_0c0bb938;
case 0x0c0bb93au: goto P_0c0bb93a;
case 0x0c0bb93cu: goto P_0c0bb93c;
case 0x0c0bb93eu: goto P_0c0bb93e;
case 0x0c0bb940u: goto P_0c0bb940;
case 0x0c0bb942u: goto P_0c0bb942;
case 0x0c0bb944u: goto P_0c0bb944;
case 0x0c0bb946u: goto P_0c0bb946;
case 0x0c0bb948u: goto P_0c0bb948;
case 0x0c0bb94au: goto P_0c0bb94a;
case 0x0c0bb94cu: goto P_0c0bb94c;
case 0x0c0bb94eu: goto P_0c0bb94e;
case 0x0c0bb950u: goto P_0c0bb950;
case 0x0c0bb952u: goto P_0c0bb952;
case 0x0c0bb954u: goto P_0c0bb954;
case 0x0c0bb956u: goto P_0c0bb956;
case 0x0c0bb958u: goto P_0c0bb958;
case 0x0c0bb95au: goto P_0c0bb95a;
case 0x0c0bb95cu: goto P_0c0bb95c;
case 0x0c0bb95eu: goto P_0c0bb95e;
case 0x0c0bb960u: goto P_0c0bb960;
case 0x0c0bb962u: goto P_0c0bb962;
case 0x0c0bb964u: goto P_0c0bb964;
case 0x0c0bb966u: goto P_0c0bb966;
case 0x0c0bb968u: goto P_0c0bb968;
case 0x0c0bb96au: goto P_0c0bb96a;
case 0x0c0bb96cu: goto P_0c0bb96c;
case 0x0c0bb96eu: goto P_0c0bb96e;
case 0x0c0bb970u: goto P_0c0bb970;
case 0x0c0bb972u: goto P_0c0bb972;
case 0x0c0bb974u: goto P_0c0bb974;
case 0x0c0bb976u: goto P_0c0bb976;
case 0x0c0bb978u: goto P_0c0bb978;
case 0x0c0bb97au: goto P_0c0bb97a;
case 0x0c0bb97cu: goto P_0c0bb97c;
case 0x0c0bb97eu: goto P_0c0bb97e;
case 0x0c0bb980u: goto P_0c0bb980;
case 0x0c0bb982u: goto P_0c0bb982;
case 0x0c0bb984u: goto P_0c0bb984;
case 0x0c0bb986u: goto P_0c0bb986;
case 0x0c0bb988u: goto P_0c0bb988;
case 0x0c0bb98au: goto P_0c0bb98a;
case 0x0c0bb98cu: goto P_0c0bb98c;
case 0x0c0bba06u: goto P_0c0bba06;
case 0x0c0bba08u: goto P_0c0bba08;
case 0x0c0bba0au: goto P_0c0bba0a;
case 0x0c0bba0cu: goto P_0c0bba0c;
case 0x0c0bba0eu: goto P_0c0bba0e;
case 0x0c0bba10u: goto P_0c0bba10;
case 0x0c0bba12u: goto P_0c0bba12;
case 0x0c0bba14u: goto P_0c0bba14;
case 0x0c0bba16u: goto P_0c0bba16;
case 0x0c0bba18u: goto P_0c0bba18;
case 0x0c0bba1au: goto P_0c0bba1a;
case 0x0c0bba1cu: goto P_0c0bba1c;
case 0x0c0bba1eu: goto P_0c0bba1e;
case 0x0c0bba20u: goto P_0c0bba20;
case 0x0c0bba22u: goto P_0c0bba22;
case 0x0c0bba24u: goto P_0c0bba24;
case 0x0c0bba26u: goto P_0c0bba26;
case 0x0c0bba28u: goto P_0c0bba28;
case 0x0c0bba2au: goto P_0c0bba2a;
case 0x0c0bba2cu: goto P_0c0bba2c;
case 0x0c0bba2eu: goto P_0c0bba2e;
case 0x0c0bba30u: goto P_0c0bba30;
case 0x0c0bba32u: goto P_0c0bba32;
case 0x0c0bba34u: goto P_0c0bba34;
case 0x0c0bba36u: goto P_0c0bba36;
case 0x0c0bba38u: goto P_0c0bba38;
case 0x0c0bba3au: goto P_0c0bba3a;
case 0x0c0bba3cu: goto P_0c0bba3c;
case 0x0c0bba3eu: goto P_0c0bba3e;
case 0x0c0bba40u: goto P_0c0bba40;
case 0x0c0bba42u: goto P_0c0bba42;
case 0x0c0bba44u: goto P_0c0bba44;
case 0x0c0bba46u: goto P_0c0bba46;
case 0x0c0bba48u: goto P_0c0bba48;
case 0x0c0bba4au: goto P_0c0bba4a;
case 0x0c0bba4cu: goto P_0c0bba4c;
case 0x0c0bba4eu: goto P_0c0bba4e;
case 0x0c0bba50u: goto P_0c0bba50;
case 0x0c0bba52u: goto P_0c0bba52;
case 0x0c0bba54u: goto P_0c0bba54;
case 0x0c0bba56u: goto P_0c0bba56;
case 0x0c0bba58u: goto P_0c0bba58;
case 0x0c0bba5au: goto P_0c0bba5a;
case 0x0c0bba5cu: goto P_0c0bba5c;
case 0x0c0bba5eu: goto P_0c0bba5e;
case 0x0c0bba60u: goto P_0c0bba60;
case 0x0c0bba62u: goto P_0c0bba62;
case 0x0c0bba64u: goto P_0c0bba64;
case 0x0c0bba66u: goto P_0c0bba66;
case 0x0c0bba68u: goto P_0c0bba68;
case 0x0c0bba6au: goto P_0c0bba6a;
case 0x0c0bba6cu: goto P_0c0bba6c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0bb662: /* original 2fe6, guest PC 0x0c0bb662 */
if(!s->budget--) { s->failed_pc=0x0c0bb662u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bb664;
P_0c0bb664: /* original 2fd6, guest PC 0x0c0bb664 */
if(!s->budget--) { s->failed_pc=0x0c0bb664u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bb666;
P_0c0bb666: /* original 2fc6, guest PC 0x0c0bb666 */
if(!s->budget--) { s->failed_pc=0x0c0bb666u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bb668;
P_0c0bb668: /* original 2fb6, guest PC 0x0c0bb668 */
if(!s->budget--) { s->failed_pc=0x0c0bb668u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bb66a;
P_0c0bb66a: /* original 2fa6, guest PC 0x0c0bb66a */
if(!s->budget--) { s->failed_pc=0x0c0bb66au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bb66c;
P_0c0bb66c: /* original 2f96, guest PC 0x0c0bb66c */
if(!s->budget--) { s->failed_pc=0x0c0bb66cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0bb66e;
P_0c0bb66e: /* original 4f22, guest PC 0x0c0bb66e */
if(!s->budget--) { s->failed_pc=0x0c0bb66eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0bb670;
P_0c0bb670: /* original 5d44, guest PC 0x0c0bb670 */
if(!s->budget--) { s->failed_pc=0x0c0bb670u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0bb672;
P_0c0bb672: /* original 94a8, guest PC 0x0c0bb672 */
if(!s->budget--) { s->failed_pc=0x0c0bb672u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7c6u,2);
goto P_0c0bb674;
P_0c0bb674: /* original de6e, guest PC 0x0c0bb674 */
if(!s->budget--) { s->failed_pc=0x0c0bb674u; return 0; }
r[14]=read(ram,0x0c0bb830u,4);
goto P_0c0bb676;
P_0c0bb676: /* original 7ff8, guest PC 0x0c0bb676 */
if(!s->budget--) { s->failed_pc=0x0c0bb676u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0bb678;
P_0c0bb678: /* original 4e0b, guest PC 0x0c0bb678 */
if(!s->budget--) { s->failed_pc=0x0c0bb678u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb67cu;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb67cu) { target=s->pc; goto dispatch; }
goto P_0c0bb67c;
P_0c0bb67a: /* original 65d2, guest PC 0x0c0bb67a */
if(!s->budget--) { s->failed_pc=0x0c0bb67au; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0bb67c;
P_0c0bb67c: /* original 94a4, guest PC 0x0c0bb67c */
if(!s->budget--) { s->failed_pc=0x0c0bb67cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7c8u,2);
goto P_0c0bb67e;
P_0c0bb67e: /* original 4e0b, guest PC 0x0c0bb67e */
if(!s->budget--) { s->failed_pc=0x0c0bb67eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb682u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb682u) { target=s->pc; goto dispatch; }
goto P_0c0bb682;
P_0c0bb680: /* original 55d1, guest PC 0x0c0bb680 */
if(!s->budget--) { s->failed_pc=0x0c0bb680u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0bb682;
P_0c0bb682: /* original 94a2, guest PC 0x0c0bb682 */
if(!s->budget--) { s->failed_pc=0x0c0bb682u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7cau,2);
goto P_0c0bb684;
P_0c0bb684: /* original 4e0b, guest PC 0x0c0bb684 */
if(!s->budget--) { s->failed_pc=0x0c0bb684u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb688u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb688u) { target=s->pc; goto dispatch; }
goto P_0c0bb688;
P_0c0bb686: /* original 55d2, guest PC 0x0c0bb686 */
if(!s->budget--) { s->failed_pc=0x0c0bb686u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0bb688;
P_0c0bb688: /* original 94a0, guest PC 0x0c0bb688 */
if(!s->budget--) { s->failed_pc=0x0c0bb688u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7ccu,2);
goto P_0c0bb68a;
P_0c0bb68a: /* original 4e0b, guest PC 0x0c0bb68a */
if(!s->budget--) { s->failed_pc=0x0c0bb68au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb68eu;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb68eu) { target=s->pc; goto dispatch; }
goto P_0c0bb68e;
P_0c0bb68c: /* original 55d3, guest PC 0x0c0bb68c */
if(!s->budget--) { s->failed_pc=0x0c0bb68cu; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0bb68e;
P_0c0bb68e: /* original 949e, guest PC 0x0c0bb68e */
if(!s->budget--) { s->failed_pc=0x0c0bb68eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7ceu,2);
goto P_0c0bb690;
P_0c0bb690: /* original 4e0b, guest PC 0x0c0bb690 */
if(!s->budget--) { s->failed_pc=0x0c0bb690u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb694u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb694u) { target=s->pc; goto dispatch; }
goto P_0c0bb694;
P_0c0bb692: /* original 55d4, guest PC 0x0c0bb692 */
if(!s->budget--) { s->failed_pc=0x0c0bb692u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0bb694;
P_0c0bb694: /* original 949c, guest PC 0x0c0bb694 */
if(!s->budget--) { s->failed_pc=0x0c0bb694u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7d0u,2);
goto P_0c0bb696;
P_0c0bb696: /* original 4e0b, guest PC 0x0c0bb696 */
if(!s->budget--) { s->failed_pc=0x0c0bb696u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb69au;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb69au) { target=s->pc; goto dispatch; }
goto P_0c0bb69a;
P_0c0bb698: /* original 55d5, guest PC 0x0c0bb698 */
if(!s->budget--) { s->failed_pc=0x0c0bb698u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0bb69a;
P_0c0bb69a: /* original 949a, guest PC 0x0c0bb69a */
if(!s->budget--) { s->failed_pc=0x0c0bb69au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7d2u,2);
goto P_0c0bb69c;
P_0c0bb69c: /* original 4e0b, guest PC 0x0c0bb69c */
if(!s->budget--) { s->failed_pc=0x0c0bb69cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6a0u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6a0u) { target=s->pc; goto dispatch; }
goto P_0c0bb6a0;
P_0c0bb69e: /* original 55d6, guest PC 0x0c0bb69e */
if(!s->budget--) { s->failed_pc=0x0c0bb69eu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0bb6a0;
P_0c0bb6a0: /* original 9498, guest PC 0x0c0bb6a0 */
if(!s->budget--) { s->failed_pc=0x0c0bb6a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7d4u,2);
goto P_0c0bb6a2;
P_0c0bb6a2: /* original 4e0b, guest PC 0x0c0bb6a2 */
if(!s->budget--) { s->failed_pc=0x0c0bb6a2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6a6u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6a6u) { target=s->pc; goto dispatch; }
goto P_0c0bb6a6;
P_0c0bb6a4: /* original 55d7, guest PC 0x0c0bb6a4 */
if(!s->budget--) { s->failed_pc=0x0c0bb6a4u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0bb6a6;
P_0c0bb6a6: /* original 9496, guest PC 0x0c0bb6a6 */
if(!s->budget--) { s->failed_pc=0x0c0bb6a6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7d6u,2);
goto P_0c0bb6a8;
P_0c0bb6a8: /* original 4e0b, guest PC 0x0c0bb6a8 */
if(!s->budget--) { s->failed_pc=0x0c0bb6a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6acu;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6acu) { target=s->pc; goto dispatch; }
goto P_0c0bb6ac;
P_0c0bb6aa: /* original 55d8, guest PC 0x0c0bb6aa */
if(!s->budget--) { s->failed_pc=0x0c0bb6aau; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0bb6ac;
P_0c0bb6ac: /* original 9494, guest PC 0x0c0bb6ac */
if(!s->budget--) { s->failed_pc=0x0c0bb6acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7d8u,2);
goto P_0c0bb6ae;
P_0c0bb6ae: /* original 4e0b, guest PC 0x0c0bb6ae */
if(!s->budget--) { s->failed_pc=0x0c0bb6aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6b2u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6b2u) { target=s->pc; goto dispatch; }
goto P_0c0bb6b2;
P_0c0bb6b0: /* original 55d9, guest PC 0x0c0bb6b0 */
if(!s->budget--) { s->failed_pc=0x0c0bb6b0u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0bb6b2;
P_0c0bb6b2: /* original 9492, guest PC 0x0c0bb6b2 */
if(!s->budget--) { s->failed_pc=0x0c0bb6b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7dau,2);
goto P_0c0bb6b4;
P_0c0bb6b4: /* original 4e0b, guest PC 0x0c0bb6b4 */
if(!s->budget--) { s->failed_pc=0x0c0bb6b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6b8u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6b8u) { target=s->pc; goto dispatch; }
goto P_0c0bb6b8;
P_0c0bb6b6: /* original 55da, guest PC 0x0c0bb6b6 */
if(!s->budget--) { s->failed_pc=0x0c0bb6b6u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0bb6b8;
P_0c0bb6b8: /* original 9490, guest PC 0x0c0bb6b8 */
if(!s->budget--) { s->failed_pc=0x0c0bb6b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7dcu,2);
goto P_0c0bb6ba;
P_0c0bb6ba: /* original 4e0b, guest PC 0x0c0bb6ba */
if(!s->budget--) { s->failed_pc=0x0c0bb6bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6beu;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6beu) { target=s->pc; goto dispatch; }
goto P_0c0bb6be;
P_0c0bb6bc: /* original 55db, guest PC 0x0c0bb6bc */
if(!s->budget--) { s->failed_pc=0x0c0bb6bcu; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0bb6be;
P_0c0bb6be: /* original 948e, guest PC 0x0c0bb6be */
if(!s->budget--) { s->failed_pc=0x0c0bb6beu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7deu,2);
goto P_0c0bb6c0;
P_0c0bb6c0: /* original 4e0b, guest PC 0x0c0bb6c0 */
if(!s->budget--) { s->failed_pc=0x0c0bb6c0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6c4u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6c4u) { target=s->pc; goto dispatch; }
goto P_0c0bb6c4;
P_0c0bb6c2: /* original 55dc, guest PC 0x0c0bb6c2 */
if(!s->budget--) { s->failed_pc=0x0c0bb6c2u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0bb6c4;
P_0c0bb6c4: /* original 948c, guest PC 0x0c0bb6c4 */
if(!s->budget--) { s->failed_pc=0x0c0bb6c4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7e0u,2);
goto P_0c0bb6c6;
P_0c0bb6c6: /* original 4e0b, guest PC 0x0c0bb6c6 */
if(!s->budget--) { s->failed_pc=0x0c0bb6c6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6cau;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6cau) { target=s->pc; goto dispatch; }
goto P_0c0bb6ca;
P_0c0bb6c8: /* original 55dd, guest PC 0x0c0bb6c8 */
if(!s->budget--) { s->failed_pc=0x0c0bb6c8u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0bb6ca;
P_0c0bb6ca: /* original 948a, guest PC 0x0c0bb6ca */
if(!s->budget--) { s->failed_pc=0x0c0bb6cau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7e2u,2);
goto P_0c0bb6cc;
P_0c0bb6cc: /* original 4e0b, guest PC 0x0c0bb6cc */
if(!s->budget--) { s->failed_pc=0x0c0bb6ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6d0u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6d0u) { target=s->pc; goto dispatch; }
goto P_0c0bb6d0;
P_0c0bb6ce: /* original 55de, guest PC 0x0c0bb6ce */
if(!s->budget--) { s->failed_pc=0x0c0bb6ceu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0bb6d0;
P_0c0bb6d0: /* original 9488, guest PC 0x0c0bb6d0 */
if(!s->budget--) { s->failed_pc=0x0c0bb6d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7e4u,2);
goto P_0c0bb6d2;
P_0c0bb6d2: /* original 4e0b, guest PC 0x0c0bb6d2 */
if(!s->budget--) { s->failed_pc=0x0c0bb6d2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6d6u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6d6u) { target=s->pc; goto dispatch; }
goto P_0c0bb6d6;
P_0c0bb6d4: /* original 55df, guest PC 0x0c0bb6d4 */
if(!s->budget--) { s->failed_pc=0x0c0bb6d4u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0bb6d6;
P_0c0bb6d6: /* original 9486, guest PC 0x0c0bb6d6 */
if(!s->budget--) { s->failed_pc=0x0c0bb6d6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7e6u,2);
goto P_0c0bb6d8;
P_0c0bb6d8: /* original e040, guest PC 0x0c0bb6d8 */
if(!s->budget--) { s->failed_pc=0x0c0bb6d8u; return 0; }
r[0]=0x00000040u;
goto P_0c0bb6da;
P_0c0bb6da: /* original 4e0b, guest PC 0x0c0bb6da */
if(!s->budget--) { s->failed_pc=0x0c0bb6dau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6deu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6deu) { target=s->pc; goto dispatch; }
goto P_0c0bb6de;
P_0c0bb6dc: /* original 05de, guest PC 0x0c0bb6dc */
if(!s->budget--) { s->failed_pc=0x0c0bb6dcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb6de;
P_0c0bb6de: /* original 9483, guest PC 0x0c0bb6de */
if(!s->budget--) { s->failed_pc=0x0c0bb6deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7e8u,2);
goto P_0c0bb6e0;
P_0c0bb6e0: /* original e044, guest PC 0x0c0bb6e0 */
if(!s->budget--) { s->failed_pc=0x0c0bb6e0u; return 0; }
r[0]=0x00000044u;
goto P_0c0bb6e2;
P_0c0bb6e2: /* original 4e0b, guest PC 0x0c0bb6e2 */
if(!s->budget--) { s->failed_pc=0x0c0bb6e2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6e6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6e6u) { target=s->pc; goto dispatch; }
goto P_0c0bb6e6;
P_0c0bb6e4: /* original 05de, guest PC 0x0c0bb6e4 */
if(!s->budget--) { s->failed_pc=0x0c0bb6e4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb6e6;
P_0c0bb6e6: /* original 9480, guest PC 0x0c0bb6e6 */
if(!s->budget--) { s->failed_pc=0x0c0bb6e6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7eau,2);
goto P_0c0bb6e8;
P_0c0bb6e8: /* original e048, guest PC 0x0c0bb6e8 */
if(!s->budget--) { s->failed_pc=0x0c0bb6e8u; return 0; }
r[0]=0x00000048u;
goto P_0c0bb6ea;
P_0c0bb6ea: /* original 4e0b, guest PC 0x0c0bb6ea */
if(!s->budget--) { s->failed_pc=0x0c0bb6eau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6eeu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6eeu) { target=s->pc; goto dispatch; }
goto P_0c0bb6ee;
P_0c0bb6ec: /* original 05de, guest PC 0x0c0bb6ec */
if(!s->budget--) { s->failed_pc=0x0c0bb6ecu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb6ee;
P_0c0bb6ee: /* original 947d, guest PC 0x0c0bb6ee */
if(!s->budget--) { s->failed_pc=0x0c0bb6eeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7ecu,2);
goto P_0c0bb6f0;
P_0c0bb6f0: /* original e04c, guest PC 0x0c0bb6f0 */
if(!s->budget--) { s->failed_pc=0x0c0bb6f0u; return 0; }
r[0]=0x0000004cu;
goto P_0c0bb6f2;
P_0c0bb6f2: /* original 4e0b, guest PC 0x0c0bb6f2 */
if(!s->budget--) { s->failed_pc=0x0c0bb6f2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6f6u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6f6u) { target=s->pc; goto dispatch; }
goto P_0c0bb6f6;
P_0c0bb6f4: /* original 05de, guest PC 0x0c0bb6f4 */
if(!s->budget--) { s->failed_pc=0x0c0bb6f4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb6f6;
P_0c0bb6f6: /* original 947a, guest PC 0x0c0bb6f6 */
if(!s->budget--) { s->failed_pc=0x0c0bb6f6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7eeu,2);
goto P_0c0bb6f8;
P_0c0bb6f8: /* original e050, guest PC 0x0c0bb6f8 */
if(!s->budget--) { s->failed_pc=0x0c0bb6f8u; return 0; }
r[0]=0x00000050u;
goto P_0c0bb6fa;
P_0c0bb6fa: /* original 4e0b, guest PC 0x0c0bb6fa */
if(!s->budget--) { s->failed_pc=0x0c0bb6fau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb6feu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb6feu) { target=s->pc; goto dispatch; }
goto P_0c0bb6fe;
P_0c0bb6fc: /* original 05de, guest PC 0x0c0bb6fc */
if(!s->budget--) { s->failed_pc=0x0c0bb6fcu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb6fe;
P_0c0bb6fe: /* original 9477, guest PC 0x0c0bb6fe */
if(!s->budget--) { s->failed_pc=0x0c0bb6feu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7f0u,2);
goto P_0c0bb700;
P_0c0bb700: /* original e054, guest PC 0x0c0bb700 */
if(!s->budget--) { s->failed_pc=0x0c0bb700u; return 0; }
r[0]=0x00000054u;
goto P_0c0bb702;
P_0c0bb702: /* original 4e0b, guest PC 0x0c0bb702 */
if(!s->budget--) { s->failed_pc=0x0c0bb702u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb706u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb706u) { target=s->pc; goto dispatch; }
goto P_0c0bb706;
P_0c0bb704: /* original 05de, guest PC 0x0c0bb704 */
if(!s->budget--) { s->failed_pc=0x0c0bb704u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb706;
P_0c0bb706: /* original 9474, guest PC 0x0c0bb706 */
if(!s->budget--) { s->failed_pc=0x0c0bb706u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7f2u,2);
goto P_0c0bb708;
P_0c0bb708: /* original e058, guest PC 0x0c0bb708 */
if(!s->budget--) { s->failed_pc=0x0c0bb708u; return 0; }
r[0]=0x00000058u;
goto P_0c0bb70a;
P_0c0bb70a: /* original 4e0b, guest PC 0x0c0bb70a */
if(!s->budget--) { s->failed_pc=0x0c0bb70au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb70eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb70eu) { target=s->pc; goto dispatch; }
goto P_0c0bb70e;
P_0c0bb70c: /* original 05de, guest PC 0x0c0bb70c */
if(!s->budget--) { s->failed_pc=0x0c0bb70cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb70e;
P_0c0bb70e: /* original 9471, guest PC 0x0c0bb70e */
if(!s->budget--) { s->failed_pc=0x0c0bb70eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7f4u,2);
goto P_0c0bb710;
P_0c0bb710: /* original e05c, guest PC 0x0c0bb710 */
if(!s->budget--) { s->failed_pc=0x0c0bb710u; return 0; }
r[0]=0x0000005cu;
goto P_0c0bb712;
P_0c0bb712: /* original 4e0b, guest PC 0x0c0bb712 */
if(!s->budget--) { s->failed_pc=0x0c0bb712u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb716u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb716u) { target=s->pc; goto dispatch; }
goto P_0c0bb716;
P_0c0bb714: /* original 05de, guest PC 0x0c0bb714 */
if(!s->budget--) { s->failed_pc=0x0c0bb714u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb716;
P_0c0bb716: /* original 946e, guest PC 0x0c0bb716 */
if(!s->budget--) { s->failed_pc=0x0c0bb716u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7f6u,2);
goto P_0c0bb718;
P_0c0bb718: /* original e060, guest PC 0x0c0bb718 */
if(!s->budget--) { s->failed_pc=0x0c0bb718u; return 0; }
r[0]=0x00000060u;
goto P_0c0bb71a;
P_0c0bb71a: /* original 4e0b, guest PC 0x0c0bb71a */
if(!s->budget--) { s->failed_pc=0x0c0bb71au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb71eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb71eu) { target=s->pc; goto dispatch; }
goto P_0c0bb71e;
P_0c0bb71c: /* original 05de, guest PC 0x0c0bb71c */
if(!s->budget--) { s->failed_pc=0x0c0bb71cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb71e;
P_0c0bb71e: /* original 946b, guest PC 0x0c0bb71e */
if(!s->budget--) { s->failed_pc=0x0c0bb71eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7f8u,2);
goto P_0c0bb720;
P_0c0bb720: /* original e064, guest PC 0x0c0bb720 */
if(!s->budget--) { s->failed_pc=0x0c0bb720u; return 0; }
r[0]=0x00000064u;
goto P_0c0bb722;
P_0c0bb722: /* original 4e0b, guest PC 0x0c0bb722 */
if(!s->budget--) { s->failed_pc=0x0c0bb722u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb726u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb726u) { target=s->pc; goto dispatch; }
goto P_0c0bb726;
P_0c0bb724: /* original 05de, guest PC 0x0c0bb724 */
if(!s->budget--) { s->failed_pc=0x0c0bb724u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb726;
P_0c0bb726: /* original 9468, guest PC 0x0c0bb726 */
if(!s->budget--) { s->failed_pc=0x0c0bb726u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7fau,2);
goto P_0c0bb728;
P_0c0bb728: /* original e068, guest PC 0x0c0bb728 */
if(!s->budget--) { s->failed_pc=0x0c0bb728u; return 0; }
r[0]=0x00000068u;
goto P_0c0bb72a;
P_0c0bb72a: /* original 4e0b, guest PC 0x0c0bb72a */
if(!s->budget--) { s->failed_pc=0x0c0bb72au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb72eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb72eu) { target=s->pc; goto dispatch; }
goto P_0c0bb72e;
P_0c0bb72c: /* original 05de, guest PC 0x0c0bb72c */
if(!s->budget--) { s->failed_pc=0x0c0bb72cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb72e;
P_0c0bb72e: /* original 9465, guest PC 0x0c0bb72e */
if(!s->budget--) { s->failed_pc=0x0c0bb72eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7fcu,2);
goto P_0c0bb730;
P_0c0bb730: /* original e06c, guest PC 0x0c0bb730 */
if(!s->budget--) { s->failed_pc=0x0c0bb730u; return 0; }
r[0]=0x0000006cu;
goto P_0c0bb732;
P_0c0bb732: /* original 4e0b, guest PC 0x0c0bb732 */
if(!s->budget--) { s->failed_pc=0x0c0bb732u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb736u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb736u) { target=s->pc; goto dispatch; }
goto P_0c0bb736;
P_0c0bb734: /* original 05de, guest PC 0x0c0bb734 */
if(!s->budget--) { s->failed_pc=0x0c0bb734u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb736;
P_0c0bb736: /* original 9462, guest PC 0x0c0bb736 */
if(!s->budget--) { s->failed_pc=0x0c0bb736u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb7feu,2);
goto P_0c0bb738;
P_0c0bb738: /* original e070, guest PC 0x0c0bb738 */
if(!s->budget--) { s->failed_pc=0x0c0bb738u; return 0; }
r[0]=0x00000070u;
goto P_0c0bb73a;
P_0c0bb73a: /* original 4e0b, guest PC 0x0c0bb73a */
if(!s->budget--) { s->failed_pc=0x0c0bb73au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb73eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb73eu) { target=s->pc; goto dispatch; }
goto P_0c0bb73e;
P_0c0bb73c: /* original 05de, guest PC 0x0c0bb73c */
if(!s->budget--) { s->failed_pc=0x0c0bb73cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb73e;
P_0c0bb73e: /* original 945f, guest PC 0x0c0bb73e */
if(!s->budget--) { s->failed_pc=0x0c0bb73eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb800u,2);
goto P_0c0bb740;
P_0c0bb740: /* original e074, guest PC 0x0c0bb740 */
if(!s->budget--) { s->failed_pc=0x0c0bb740u; return 0; }
r[0]=0x00000074u;
goto P_0c0bb742;
P_0c0bb742: /* original 4e0b, guest PC 0x0c0bb742 */
if(!s->budget--) { s->failed_pc=0x0c0bb742u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb746u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb746u) { target=s->pc; goto dispatch; }
goto P_0c0bb746;
P_0c0bb744: /* original 05de, guest PC 0x0c0bb744 */
if(!s->budget--) { s->failed_pc=0x0c0bb744u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb746;
P_0c0bb746: /* original 945c, guest PC 0x0c0bb746 */
if(!s->budget--) { s->failed_pc=0x0c0bb746u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb802u,2);
goto P_0c0bb748;
P_0c0bb748: /* original e078, guest PC 0x0c0bb748 */
if(!s->budget--) { s->failed_pc=0x0c0bb748u; return 0; }
r[0]=0x00000078u;
goto P_0c0bb74a;
P_0c0bb74a: /* original 4e0b, guest PC 0x0c0bb74a */
if(!s->budget--) { s->failed_pc=0x0c0bb74au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb74eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb74eu) { target=s->pc; goto dispatch; }
goto P_0c0bb74e;
P_0c0bb74c: /* original 05de, guest PC 0x0c0bb74c */
if(!s->budget--) { s->failed_pc=0x0c0bb74cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb74e;
P_0c0bb74e: /* original 9459, guest PC 0x0c0bb74e */
if(!s->budget--) { s->failed_pc=0x0c0bb74eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb804u,2);
goto P_0c0bb750;
P_0c0bb750: /* original e07c, guest PC 0x0c0bb750 */
if(!s->budget--) { s->failed_pc=0x0c0bb750u; return 0; }
r[0]=0x0000007cu;
goto P_0c0bb752;
P_0c0bb752: /* original 4e0b, guest PC 0x0c0bb752 */
if(!s->budget--) { s->failed_pc=0x0c0bb752u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb756u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb756u) { target=s->pc; goto dispatch; }
goto P_0c0bb756;
P_0c0bb754: /* original 05de, guest PC 0x0c0bb754 */
if(!s->budget--) { s->failed_pc=0x0c0bb754u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb756;
P_0c0bb756: /* original 9457, guest PC 0x0c0bb756 */
if(!s->budget--) { s->failed_pc=0x0c0bb756u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb808u,2);
goto P_0c0bb758;
P_0c0bb758: /* original 9055, guest PC 0x0c0bb758 */
if(!s->budget--) { s->failed_pc=0x0c0bb758u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb806u,2);
goto P_0c0bb75a;
P_0c0bb75a: /* original 4e0b, guest PC 0x0c0bb75a */
if(!s->budget--) { s->failed_pc=0x0c0bb75au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb75eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb75eu) { target=s->pc; goto dispatch; }
goto P_0c0bb75e;
P_0c0bb75c: /* original 05de, guest PC 0x0c0bb75c */
if(!s->budget--) { s->failed_pc=0x0c0bb75cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb75e;
P_0c0bb75e: /* original 9554, guest PC 0x0c0bb75e */
if(!s->budget--) { s->failed_pc=0x0c0bb75eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb80au,2);
goto P_0c0bb760;
P_0c0bb760: /* original 35dc, guest PC 0x0c0bb760 */
if(!s->budget--) { s->failed_pc=0x0c0bb760u; return 0; }
r[5]+=r[13];
goto P_0c0bb762;
P_0c0bb762: /* original 2f52, guest PC 0x0c0bb762 */
if(!s->budget--) { s->failed_pc=0x0c0bb762u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb764;
P_0c0bb764: /* original 9452, guest PC 0x0c0bb764 */
if(!s->budget--) { s->failed_pc=0x0c0bb764u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb80cu,2);
goto P_0c0bb766;
P_0c0bb766: /* original 4e0b, guest PC 0x0c0bb766 */
if(!s->budget--) { s->failed_pc=0x0c0bb766u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb76au;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb76au) { target=s->pc; goto dispatch; }
goto P_0c0bb76a;
P_0c0bb768: /* original 6552, guest PC 0x0c0bb768 */
if(!s->budget--) { s->failed_pc=0x0c0bb768u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb76a;
P_0c0bb76a: /* original 9550, guest PC 0x0c0bb76a */
if(!s->budget--) { s->failed_pc=0x0c0bb76au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb80eu,2);
goto P_0c0bb76c;
P_0c0bb76c: /* original 35dc, guest PC 0x0c0bb76c */
if(!s->budget--) { s->failed_pc=0x0c0bb76cu; return 0; }
r[5]+=r[13];
goto P_0c0bb76e;
P_0c0bb76e: /* original 1f51, guest PC 0x0c0bb76e */
if(!s->budget--) { s->failed_pc=0x0c0bb76eu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0bb770;
P_0c0bb770: /* original 944e, guest PC 0x0c0bb770 */
if(!s->budget--) { s->failed_pc=0x0c0bb770u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb810u,2);
goto P_0c0bb772;
P_0c0bb772: /* original 4e0b, guest PC 0x0c0bb772 */
if(!s->budget--) { s->failed_pc=0x0c0bb772u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb776u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb776u) { target=s->pc; goto dispatch; }
goto P_0c0bb776;
P_0c0bb774: /* original 6552, guest PC 0x0c0bb774 */
if(!s->budget--) { s->failed_pc=0x0c0bb774u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb776;
P_0c0bb776: /* original 944d, guest PC 0x0c0bb776 */
if(!s->budget--) { s->failed_pc=0x0c0bb776u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb814u,2);
goto P_0c0bb778;
P_0c0bb778: /* original 904b, guest PC 0x0c0bb778 */
if(!s->budget--) { s->failed_pc=0x0c0bb778u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb812u,2);
goto P_0c0bb77a;
P_0c0bb77a: /* original 4e0b, guest PC 0x0c0bb77a */
if(!s->budget--) { s->failed_pc=0x0c0bb77au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb77eu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb77eu) { target=s->pc; goto dispatch; }
goto P_0c0bb77e;
P_0c0bb77c: /* original 05de, guest PC 0x0c0bb77c */
if(!s->budget--) { s->failed_pc=0x0c0bb77cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb77e;
P_0c0bb77e: /* original 944b, guest PC 0x0c0bb77e */
if(!s->budget--) { s->failed_pc=0x0c0bb77eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb818u,2);
goto P_0c0bb780;
P_0c0bb780: /* original 9049, guest PC 0x0c0bb780 */
if(!s->budget--) { s->failed_pc=0x0c0bb780u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb816u,2);
goto P_0c0bb782;
P_0c0bb782: /* original 4e0b, guest PC 0x0c0bb782 */
if(!s->budget--) { s->failed_pc=0x0c0bb782u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb786u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb786u) { target=s->pc; goto dispatch; }
goto P_0c0bb786;
P_0c0bb784: /* original 05de, guest PC 0x0c0bb784 */
if(!s->budget--) { s->failed_pc=0x0c0bb784u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb786;
P_0c0bb786: /* original 9948, guest PC 0x0c0bb786 */
if(!s->budget--) { s->failed_pc=0x0c0bb786u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb81au,2);
goto P_0c0bb788;
P_0c0bb788: /* original 9448, guest PC 0x0c0bb788 */
if(!s->budget--) { s->failed_pc=0x0c0bb788u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb81cu,2);
goto P_0c0bb78a;
P_0c0bb78a: /* original 39dc, guest PC 0x0c0bb78a */
if(!s->budget--) { s->failed_pc=0x0c0bb78au; return 0; }
r[9]+=r[13];
goto P_0c0bb78c;
P_0c0bb78c: /* original 4e0b, guest PC 0x0c0bb78c */
if(!s->budget--) { s->failed_pc=0x0c0bb78cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb790u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb790u) { target=s->pc; goto dispatch; }
goto P_0c0bb790;
P_0c0bb78e: /* original 6592, guest PC 0x0c0bb78e */
if(!s->budget--) { s->failed_pc=0x0c0bb78eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb790;
P_0c0bb790: /* original 9445, guest PC 0x0c0bb790 */
if(!s->budget--) { s->failed_pc=0x0c0bb790u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb81eu,2);
goto P_0c0bb792;
P_0c0bb792: /* original 4e0b, guest PC 0x0c0bb792 */
if(!s->budget--) { s->failed_pc=0x0c0bb792u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb796u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb796u) { target=s->pc; goto dispatch; }
goto P_0c0bb796;
P_0c0bb794: /* original 6592, guest PC 0x0c0bb794 */
if(!s->budget--) { s->failed_pc=0x0c0bb794u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb796;
P_0c0bb796: /* original 9443, guest PC 0x0c0bb796 */
if(!s->budget--) { s->failed_pc=0x0c0bb796u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb820u,2);
goto P_0c0bb798;
P_0c0bb798: /* original 4e0b, guest PC 0x0c0bb798 */
if(!s->budget--) { s->failed_pc=0x0c0bb798u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb79cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb79cu) { target=s->pc; goto dispatch; }
goto P_0c0bb79c;
P_0c0bb79a: /* original 6592, guest PC 0x0c0bb79a */
if(!s->budget--) { s->failed_pc=0x0c0bb79au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb79c;
P_0c0bb79c: /* original 9441, guest PC 0x0c0bb79c */
if(!s->budget--) { s->failed_pc=0x0c0bb79cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb822u,2);
goto P_0c0bb79e;
P_0c0bb79e: /* original 4e0b, guest PC 0x0c0bb79e */
if(!s->budget--) { s->failed_pc=0x0c0bb79eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb7a2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb7a2u) { target=s->pc; goto dispatch; }
goto P_0c0bb7a2;
P_0c0bb7a0: /* original 6592, guest PC 0x0c0bb7a0 */
if(!s->budget--) { s->failed_pc=0x0c0bb7a0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb7a2;
P_0c0bb7a2: /* original 9c3f, guest PC 0x0c0bb7a2 */
if(!s->budget--) { s->failed_pc=0x0c0bb7a2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb824u,2);
goto P_0c0bb7a4;
P_0c0bb7a4: /* original 943f, guest PC 0x0c0bb7a4 */
if(!s->budget--) { s->failed_pc=0x0c0bb7a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb826u,2);
goto P_0c0bb7a6;
P_0c0bb7a6: /* original 3cdc, guest PC 0x0c0bb7a6 */
if(!s->budget--) { s->failed_pc=0x0c0bb7a6u; return 0; }
r[12]+=r[13];
goto P_0c0bb7a8;
P_0c0bb7a8: /* original 4e0b, guest PC 0x0c0bb7a8 */
if(!s->budget--) { s->failed_pc=0x0c0bb7a8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb7acu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb7acu) { target=s->pc; goto dispatch; }
goto P_0c0bb7ac;
P_0c0bb7aa: /* original 65c2, guest PC 0x0c0bb7aa */
if(!s->budget--) { s->failed_pc=0x0c0bb7aau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb7ac;
P_0c0bb7ac: /* original 943c, guest PC 0x0c0bb7ac */
if(!s->budget--) { s->failed_pc=0x0c0bb7acu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb828u,2);
goto P_0c0bb7ae;
P_0c0bb7ae: /* original 4e0b, guest PC 0x0c0bb7ae */
if(!s->budget--) { s->failed_pc=0x0c0bb7aeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb7b2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb7b2u) { target=s->pc; goto dispatch; }
goto P_0c0bb7b2;
P_0c0bb7b0: /* original 65c2, guest PC 0x0c0bb7b0 */
if(!s->budget--) { s->failed_pc=0x0c0bb7b0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb7b2;
P_0c0bb7b2: /* original 943a, guest PC 0x0c0bb7b2 */
if(!s->budget--) { s->failed_pc=0x0c0bb7b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb82au,2);
goto P_0c0bb7b4;
P_0c0bb7b4: /* original 4e0b, guest PC 0x0c0bb7b4 */
if(!s->budget--) { s->failed_pc=0x0c0bb7b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb7b8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb7b8u) { target=s->pc; goto dispatch; }
goto P_0c0bb7b8;
P_0c0bb7b6: /* original 65c2, guest PC 0x0c0bb7b6 */
if(!s->budget--) { s->failed_pc=0x0c0bb7b6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb7b8;
P_0c0bb7b8: /* original 9438, guest PC 0x0c0bb7b8 */
if(!s->budget--) { s->failed_pc=0x0c0bb7b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb82cu,2);
goto P_0c0bb7ba;
P_0c0bb7ba: /* original 4e0b, guest PC 0x0c0bb7ba */
if(!s->budget--) { s->failed_pc=0x0c0bb7bau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb7beu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb7beu) { target=s->pc; goto dispatch; }
goto P_0c0bb7be;
P_0c0bb7bc: /* original 65c2, guest PC 0x0c0bb7bc */
if(!s->budget--) { s->failed_pc=0x0c0bb7bcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb7be;
P_0c0bb7be: /* original 9b36, guest PC 0x0c0bb7be */
if(!s->budget--) { s->failed_pc=0x0c0bb7beu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb82eu,2);
goto P_0c0bb7c0;
P_0c0bb7c0: /* original 3bdc, guest PC 0x0c0bb7c0 */
if(!s->budget--) { s->failed_pc=0x0c0bb7c0u; return 0; }
r[11]+=r[13];
goto P_0c0bb7c2;
P_0c0bb7c2: /* original a037, guest PC 0x0c0bb7c2 */
if(!s->budget--) { s->failed_pc=0x0c0bb7c2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb834;
P_0c0bb7c4: /* original 65b2, guest PC 0x0c0bb7c4 */
if(!s->budget--) { s->failed_pc=0x0c0bb7c4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0bb7c6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bb7c6u; return 0; } return 1;
P_0c0bb834: /* original 94ab, guest PC 0x0c0bb834 */
if(!s->budget--) { s->failed_pc=0x0c0bb834u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb98eu,2);
goto P_0c0bb836;
P_0c0bb836: /* original 4e0b, guest PC 0x0c0bb836 */
if(!s->budget--) { s->failed_pc=0x0c0bb836u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb83au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb83au) { target=s->pc; goto dispatch; }
goto P_0c0bb83a;
P_0c0bb838: /* original 0009, guest PC 0x0c0bb838 */
if(!s->budget--) { s->failed_pc=0x0c0bb838u; return 0; }
goto P_0c0bb83a;
P_0c0bb83a: /* original 94a9, guest PC 0x0c0bb83a */
if(!s->budget--) { s->failed_pc=0x0c0bb83au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb990u,2);
goto P_0c0bb83c;
P_0c0bb83c: /* original 4e0b, guest PC 0x0c0bb83c */
if(!s->budget--) { s->failed_pc=0x0c0bb83cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb840u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb840u) { target=s->pc; goto dispatch; }
goto P_0c0bb840;
P_0c0bb83e: /* original 65b2, guest PC 0x0c0bb83e */
if(!s->budget--) { s->failed_pc=0x0c0bb83eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb840;
P_0c0bb840: /* original 94a7, guest PC 0x0c0bb840 */
if(!s->budget--) { s->failed_pc=0x0c0bb840u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb992u,2);
goto P_0c0bb842;
P_0c0bb842: /* original 4e0b, guest PC 0x0c0bb842 */
if(!s->budget--) { s->failed_pc=0x0c0bb842u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb846u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb846u) { target=s->pc; goto dispatch; }
goto P_0c0bb846;
P_0c0bb844: /* original 65b2, guest PC 0x0c0bb844 */
if(!s->budget--) { s->failed_pc=0x0c0bb844u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb846;
P_0c0bb846: /* original 94a5, guest PC 0x0c0bb846 */
if(!s->budget--) { s->failed_pc=0x0c0bb846u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb994u,2);
goto P_0c0bb848;
P_0c0bb848: /* original 4e0b, guest PC 0x0c0bb848 */
if(!s->budget--) { s->failed_pc=0x0c0bb848u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb84cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb84cu) { target=s->pc; goto dispatch; }
goto P_0c0bb84c;
P_0c0bb84a: /* original 65b2, guest PC 0x0c0bb84a */
if(!s->budget--) { s->failed_pc=0x0c0bb84au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb84c;
P_0c0bb84c: /* original 9aa3, guest PC 0x0c0bb84c */
if(!s->budget--) { s->failed_pc=0x0c0bb84cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb996u,2);
goto P_0c0bb84e;
P_0c0bb84e: /* original 94a3, guest PC 0x0c0bb84e */
if(!s->budget--) { s->failed_pc=0x0c0bb84eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb998u,2);
goto P_0c0bb850;
P_0c0bb850: /* original 3adc, guest PC 0x0c0bb850 */
if(!s->budget--) { s->failed_pc=0x0c0bb850u; return 0; }
r[10]+=r[13];
goto P_0c0bb852;
P_0c0bb852: /* original 4e0b, guest PC 0x0c0bb852 */
if(!s->budget--) { s->failed_pc=0x0c0bb852u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb856u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb856u) { target=s->pc; goto dispatch; }
goto P_0c0bb856;
P_0c0bb854: /* original 65a2, guest PC 0x0c0bb854 */
if(!s->budget--) { s->failed_pc=0x0c0bb854u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb856;
P_0c0bb856: /* original 94a0, guest PC 0x0c0bb856 */
if(!s->budget--) { s->failed_pc=0x0c0bb856u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb99au,2);
goto P_0c0bb858;
P_0c0bb858: /* original 4e0b, guest PC 0x0c0bb858 */
if(!s->budget--) { s->failed_pc=0x0c0bb858u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb85cu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb85cu) { target=s->pc; goto dispatch; }
goto P_0c0bb85c;
P_0c0bb85a: /* original 65a2, guest PC 0x0c0bb85a */
if(!s->budget--) { s->failed_pc=0x0c0bb85au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb85c;
P_0c0bb85c: /* original 949e, guest PC 0x0c0bb85c */
if(!s->budget--) { s->failed_pc=0x0c0bb85cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb99cu,2);
goto P_0c0bb85e;
P_0c0bb85e: /* original 4e0b, guest PC 0x0c0bb85e */
if(!s->budget--) { s->failed_pc=0x0c0bb85eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb862u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb862u) { target=s->pc; goto dispatch; }
goto P_0c0bb862;
P_0c0bb860: /* original 65a2, guest PC 0x0c0bb860 */
if(!s->budget--) { s->failed_pc=0x0c0bb860u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb862;
P_0c0bb862: /* original 949c, guest PC 0x0c0bb862 */
if(!s->budget--) { s->failed_pc=0x0c0bb862u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb99eu,2);
goto P_0c0bb864;
P_0c0bb864: /* original 4e0b, guest PC 0x0c0bb864 */
if(!s->budget--) { s->failed_pc=0x0c0bb864u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb868u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb868u) { target=s->pc; goto dispatch; }
goto P_0c0bb868;
P_0c0bb866: /* original 65a2, guest PC 0x0c0bb866 */
if(!s->budget--) { s->failed_pc=0x0c0bb866u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb868;
P_0c0bb868: /* original 949a, guest PC 0x0c0bb868 */
if(!s->budget--) { s->failed_pc=0x0c0bb868u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9a0u,2);
goto P_0c0bb86a;
P_0c0bb86a: /* original 65f2, guest PC 0x0c0bb86a */
if(!s->budget--) { s->failed_pc=0x0c0bb86au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb86c;
P_0c0bb86c: /* original 4e0b, guest PC 0x0c0bb86c */
if(!s->budget--) { s->failed_pc=0x0c0bb86cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb870u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb870u) { target=s->pc; goto dispatch; }
goto P_0c0bb870;
P_0c0bb86e: /* original 6552, guest PC 0x0c0bb86e */
if(!s->budget--) { s->failed_pc=0x0c0bb86eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb870;
P_0c0bb870: /* original 9497, guest PC 0x0c0bb870 */
if(!s->budget--) { s->failed_pc=0x0c0bb870u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9a2u,2);
goto P_0c0bb872;
P_0c0bb872: /* original 55f1, guest PC 0x0c0bb872 */
if(!s->budget--) { s->failed_pc=0x0c0bb872u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0bb874;
P_0c0bb874: /* original 4e0b, guest PC 0x0c0bb874 */
if(!s->budget--) { s->failed_pc=0x0c0bb874u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb878u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb878u) { target=s->pc; goto dispatch; }
goto P_0c0bb878;
P_0c0bb876: /* original 6552, guest PC 0x0c0bb876 */
if(!s->budget--) { s->failed_pc=0x0c0bb876u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb878;
P_0c0bb878: /* original 9494, guest PC 0x0c0bb878 */
if(!s->budget--) { s->failed_pc=0x0c0bb878u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9a4u,2);
goto P_0c0bb87a;
P_0c0bb87a: /* original 4e0b, guest PC 0x0c0bb87a */
if(!s->budget--) { s->failed_pc=0x0c0bb87au; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb87eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb87eu) { target=s->pc; goto dispatch; }
goto P_0c0bb87e;
P_0c0bb87c: /* original 6592, guest PC 0x0c0bb87c */
if(!s->budget--) { s->failed_pc=0x0c0bb87cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb87e;
P_0c0bb87e: /* original 9492, guest PC 0x0c0bb87e */
if(!s->budget--) { s->failed_pc=0x0c0bb87eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9a6u,2);
goto P_0c0bb880;
P_0c0bb880: /* original 4e0b, guest PC 0x0c0bb880 */
if(!s->budget--) { s->failed_pc=0x0c0bb880u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb884u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb884u) { target=s->pc; goto dispatch; }
goto P_0c0bb884;
P_0c0bb882: /* original 6592, guest PC 0x0c0bb882 */
if(!s->budget--) { s->failed_pc=0x0c0bb882u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb884;
P_0c0bb884: /* original 9490, guest PC 0x0c0bb884 */
if(!s->budget--) { s->failed_pc=0x0c0bb884u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9a8u,2);
goto P_0c0bb886;
P_0c0bb886: /* original 4e0b, guest PC 0x0c0bb886 */
if(!s->budget--) { s->failed_pc=0x0c0bb886u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb88au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb88au) { target=s->pc; goto dispatch; }
goto P_0c0bb88a;
P_0c0bb888: /* original 6592, guest PC 0x0c0bb888 */
if(!s->budget--) { s->failed_pc=0x0c0bb888u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb88a;
P_0c0bb88a: /* original 948e, guest PC 0x0c0bb88a */
if(!s->budget--) { s->failed_pc=0x0c0bb88au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9aau,2);
goto P_0c0bb88c;
P_0c0bb88c: /* original 4e0b, guest PC 0x0c0bb88c */
if(!s->budget--) { s->failed_pc=0x0c0bb88cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb890u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb890u) { target=s->pc; goto dispatch; }
goto P_0c0bb890;
P_0c0bb88e: /* original 6592, guest PC 0x0c0bb88e */
if(!s->budget--) { s->failed_pc=0x0c0bb88eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0bb890;
P_0c0bb890: /* original 948c, guest PC 0x0c0bb890 */
if(!s->budget--) { s->failed_pc=0x0c0bb890u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9acu,2);
goto P_0c0bb892;
P_0c0bb892: /* original 4e0b, guest PC 0x0c0bb892 */
if(!s->budget--) { s->failed_pc=0x0c0bb892u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb896u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb896u) { target=s->pc; goto dispatch; }
goto P_0c0bb896;
P_0c0bb894: /* original 65c2, guest PC 0x0c0bb894 */
if(!s->budget--) { s->failed_pc=0x0c0bb894u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb896;
P_0c0bb896: /* original 948a, guest PC 0x0c0bb896 */
if(!s->budget--) { s->failed_pc=0x0c0bb896u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9aeu,2);
goto P_0c0bb898;
P_0c0bb898: /* original 4e0b, guest PC 0x0c0bb898 */
if(!s->budget--) { s->failed_pc=0x0c0bb898u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb89cu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb89cu) { target=s->pc; goto dispatch; }
goto P_0c0bb89c;
P_0c0bb89a: /* original 65c2, guest PC 0x0c0bb89a */
if(!s->budget--) { s->failed_pc=0x0c0bb89au; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb89c;
P_0c0bb89c: /* original 9488, guest PC 0x0c0bb89c */
if(!s->budget--) { s->failed_pc=0x0c0bb89cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9b0u,2);
goto P_0c0bb89e;
P_0c0bb89e: /* original 4e0b, guest PC 0x0c0bb89e */
if(!s->budget--) { s->failed_pc=0x0c0bb89eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8a2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8a2u) { target=s->pc; goto dispatch; }
goto P_0c0bb8a2;
P_0c0bb8a0: /* original 65c2, guest PC 0x0c0bb8a0 */
if(!s->budget--) { s->failed_pc=0x0c0bb8a0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb8a2;
P_0c0bb8a2: /* original 9486, guest PC 0x0c0bb8a2 */
if(!s->budget--) { s->failed_pc=0x0c0bb8a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9b2u,2);
goto P_0c0bb8a4;
P_0c0bb8a4: /* original 4e0b, guest PC 0x0c0bb8a4 */
if(!s->budget--) { s->failed_pc=0x0c0bb8a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8a8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8a8u) { target=s->pc; goto dispatch; }
goto P_0c0bb8a8;
P_0c0bb8a6: /* original 65c2, guest PC 0x0c0bb8a6 */
if(!s->budget--) { s->failed_pc=0x0c0bb8a6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0bb8a8;
P_0c0bb8a8: /* original 9484, guest PC 0x0c0bb8a8 */
if(!s->budget--) { s->failed_pc=0x0c0bb8a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9b4u,2);
goto P_0c0bb8aa;
P_0c0bb8aa: /* original 4e0b, guest PC 0x0c0bb8aa */
if(!s->budget--) { s->failed_pc=0x0c0bb8aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8aeu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8aeu) { target=s->pc; goto dispatch; }
goto P_0c0bb8ae;
P_0c0bb8ac: /* original 65b2, guest PC 0x0c0bb8ac */
if(!s->budget--) { s->failed_pc=0x0c0bb8acu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb8ae;
P_0c0bb8ae: /* original 9482, guest PC 0x0c0bb8ae */
if(!s->budget--) { s->failed_pc=0x0c0bb8aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9b6u,2);
goto P_0c0bb8b0;
P_0c0bb8b0: /* original 4e0b, guest PC 0x0c0bb8b0 */
if(!s->budget--) { s->failed_pc=0x0c0bb8b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8b4u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8b4u) { target=s->pc; goto dispatch; }
goto P_0c0bb8b4;
P_0c0bb8b2: /* original 65b2, guest PC 0x0c0bb8b2 */
if(!s->budget--) { s->failed_pc=0x0c0bb8b2u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb8b4;
P_0c0bb8b4: /* original 9480, guest PC 0x0c0bb8b4 */
if(!s->budget--) { s->failed_pc=0x0c0bb8b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9b8u,2);
goto P_0c0bb8b6;
P_0c0bb8b6: /* original 4e0b, guest PC 0x0c0bb8b6 */
if(!s->budget--) { s->failed_pc=0x0c0bb8b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8bau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8bau) { target=s->pc; goto dispatch; }
goto P_0c0bb8ba;
P_0c0bb8b8: /* original 65b2, guest PC 0x0c0bb8b8 */
if(!s->budget--) { s->failed_pc=0x0c0bb8b8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb8ba;
P_0c0bb8ba: /* original 947e, guest PC 0x0c0bb8ba */
if(!s->budget--) { s->failed_pc=0x0c0bb8bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9bau,2);
goto P_0c0bb8bc;
P_0c0bb8bc: /* original 4e0b, guest PC 0x0c0bb8bc */
if(!s->budget--) { s->failed_pc=0x0c0bb8bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8c0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8c0u) { target=s->pc; goto dispatch; }
goto P_0c0bb8c0;
P_0c0bb8be: /* original 65b2, guest PC 0x0c0bb8be */
if(!s->budget--) { s->failed_pc=0x0c0bb8beu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0bb8c0;
P_0c0bb8c0: /* original 947c, guest PC 0x0c0bb8c0 */
if(!s->budget--) { s->failed_pc=0x0c0bb8c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9bcu,2);
goto P_0c0bb8c2;
P_0c0bb8c2: /* original 4e0b, guest PC 0x0c0bb8c2 */
if(!s->budget--) { s->failed_pc=0x0c0bb8c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8c6u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8c6u) { target=s->pc; goto dispatch; }
goto P_0c0bb8c6;
P_0c0bb8c4: /* original 65a2, guest PC 0x0c0bb8c4 */
if(!s->budget--) { s->failed_pc=0x0c0bb8c4u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb8c6;
P_0c0bb8c6: /* original 947a, guest PC 0x0c0bb8c6 */
if(!s->budget--) { s->failed_pc=0x0c0bb8c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9beu,2);
goto P_0c0bb8c8;
P_0c0bb8c8: /* original 4e0b, guest PC 0x0c0bb8c8 */
if(!s->budget--) { s->failed_pc=0x0c0bb8c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8ccu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8ccu) { target=s->pc; goto dispatch; }
goto P_0c0bb8cc;
P_0c0bb8ca: /* original 65a2, guest PC 0x0c0bb8ca */
if(!s->budget--) { s->failed_pc=0x0c0bb8cau; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb8cc;
P_0c0bb8cc: /* original 9478, guest PC 0x0c0bb8cc */
if(!s->budget--) { s->failed_pc=0x0c0bb8ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9c0u,2);
goto P_0c0bb8ce;
P_0c0bb8ce: /* original 4e0b, guest PC 0x0c0bb8ce */
if(!s->budget--) { s->failed_pc=0x0c0bb8ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8d2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8d2u) { target=s->pc; goto dispatch; }
goto P_0c0bb8d2;
P_0c0bb8d0: /* original 65a2, guest PC 0x0c0bb8d0 */
if(!s->budget--) { s->failed_pc=0x0c0bb8d0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb8d2;
P_0c0bb8d2: /* original 9476, guest PC 0x0c0bb8d2 */
if(!s->budget--) { s->failed_pc=0x0c0bb8d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9c2u,2);
goto P_0c0bb8d4;
P_0c0bb8d4: /* original 4e0b, guest PC 0x0c0bb8d4 */
if(!s->budget--) { s->failed_pc=0x0c0bb8d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8d8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8d8u) { target=s->pc; goto dispatch; }
goto P_0c0bb8d8;
P_0c0bb8d6: /* original 65a2, guest PC 0x0c0bb8d6 */
if(!s->budget--) { s->failed_pc=0x0c0bb8d6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0bb8d8;
P_0c0bb8d8: /* original 9574, guest PC 0x0c0bb8d8 */
if(!s->budget--) { s->failed_pc=0x0c0bb8d8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9c4u,2);
goto P_0c0bb8da;
P_0c0bb8da: /* original 35dc, guest PC 0x0c0bb8da */
if(!s->budget--) { s->failed_pc=0x0c0bb8dau; return 0; }
r[5]+=r[13];
goto P_0c0bb8dc;
P_0c0bb8dc: /* original 2f52, guest PC 0x0c0bb8dc */
if(!s->budget--) { s->failed_pc=0x0c0bb8dcu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb8de;
P_0c0bb8de: /* original 9472, guest PC 0x0c0bb8de */
if(!s->budget--) { s->failed_pc=0x0c0bb8deu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9c6u,2);
goto P_0c0bb8e0;
P_0c0bb8e0: /* original 4e0b, guest PC 0x0c0bb8e0 */
if(!s->budget--) { s->failed_pc=0x0c0bb8e0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8e4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8e4u) { target=s->pc; goto dispatch; }
goto P_0c0bb8e4;
P_0c0bb8e2: /* original 6552, guest PC 0x0c0bb8e2 */
if(!s->budget--) { s->failed_pc=0x0c0bb8e2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb8e4;
P_0c0bb8e4: /* original 9470, guest PC 0x0c0bb8e4 */
if(!s->budget--) { s->failed_pc=0x0c0bb8e4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9c8u,2);
goto P_0c0bb8e6;
P_0c0bb8e6: /* original 65f2, guest PC 0x0c0bb8e6 */
if(!s->budget--) { s->failed_pc=0x0c0bb8e6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb8e8;
P_0c0bb8e8: /* original 4e0b, guest PC 0x0c0bb8e8 */
if(!s->budget--) { s->failed_pc=0x0c0bb8e8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8ecu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8ecu) { target=s->pc; goto dispatch; }
goto P_0c0bb8ec;
P_0c0bb8ea: /* original 6552, guest PC 0x0c0bb8ea */
if(!s->budget--) { s->failed_pc=0x0c0bb8eau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb8ec;
P_0c0bb8ec: /* original 956d, guest PC 0x0c0bb8ec */
if(!s->budget--) { s->failed_pc=0x0c0bb8ecu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9cau,2);
goto P_0c0bb8ee;
P_0c0bb8ee: /* original 35dc, guest PC 0x0c0bb8ee */
if(!s->budget--) { s->failed_pc=0x0c0bb8eeu; return 0; }
r[5]+=r[13];
goto P_0c0bb8f0;
P_0c0bb8f0: /* original 2f52, guest PC 0x0c0bb8f0 */
if(!s->budget--) { s->failed_pc=0x0c0bb8f0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb8f2;
P_0c0bb8f2: /* original 946b, guest PC 0x0c0bb8f2 */
if(!s->budget--) { s->failed_pc=0x0c0bb8f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9ccu,2);
goto P_0c0bb8f4;
P_0c0bb8f4: /* original 4e0b, guest PC 0x0c0bb8f4 */
if(!s->budget--) { s->failed_pc=0x0c0bb8f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb8f8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb8f8u) { target=s->pc; goto dispatch; }
goto P_0c0bb8f8;
P_0c0bb8f6: /* original 6552, guest PC 0x0c0bb8f6 */
if(!s->budget--) { s->failed_pc=0x0c0bb8f6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb8f8;
P_0c0bb8f8: /* original 9469, guest PC 0x0c0bb8f8 */
if(!s->budget--) { s->failed_pc=0x0c0bb8f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9ceu,2);
goto P_0c0bb8fa;
P_0c0bb8fa: /* original 65f2, guest PC 0x0c0bb8fa */
if(!s->budget--) { s->failed_pc=0x0c0bb8fau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb8fc;
P_0c0bb8fc: /* original 4e0b, guest PC 0x0c0bb8fc */
if(!s->budget--) { s->failed_pc=0x0c0bb8fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb900u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb900u) { target=s->pc; goto dispatch; }
goto P_0c0bb900;
P_0c0bb8fe: /* original 6552, guest PC 0x0c0bb8fe */
if(!s->budget--) { s->failed_pc=0x0c0bb8feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb900;
P_0c0bb900: /* original 9467, guest PC 0x0c0bb900 */
if(!s->budget--) { s->failed_pc=0x0c0bb900u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9d2u,2);
goto P_0c0bb902;
P_0c0bb902: /* original 9065, guest PC 0x0c0bb902 */
if(!s->budget--) { s->failed_pc=0x0c0bb902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9d0u,2);
goto P_0c0bb904;
P_0c0bb904: /* original 4e0b, guest PC 0x0c0bb904 */
if(!s->budget--) { s->failed_pc=0x0c0bb904u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb908u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb908u) { target=s->pc; goto dispatch; }
goto P_0c0bb908;
P_0c0bb906: /* original 05de, guest PC 0x0c0bb906 */
if(!s->budget--) { s->failed_pc=0x0c0bb906u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb908;
P_0c0bb908: /* original 9564, guest PC 0x0c0bb908 */
if(!s->budget--) { s->failed_pc=0x0c0bb908u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9d4u,2);
goto P_0c0bb90a;
P_0c0bb90a: /* original 35dc, guest PC 0x0c0bb90a */
if(!s->budget--) { s->failed_pc=0x0c0bb90au; return 0; }
r[5]+=r[13];
goto P_0c0bb90c;
P_0c0bb90c: /* original 2f52, guest PC 0x0c0bb90c */
if(!s->budget--) { s->failed_pc=0x0c0bb90cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb90e;
P_0c0bb90e: /* original 9462, guest PC 0x0c0bb90e */
if(!s->budget--) { s->failed_pc=0x0c0bb90eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9d6u,2);
goto P_0c0bb910;
P_0c0bb910: /* original 4e0b, guest PC 0x0c0bb910 */
if(!s->budget--) { s->failed_pc=0x0c0bb910u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb914u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb914u) { target=s->pc; goto dispatch; }
goto P_0c0bb914;
P_0c0bb912: /* original 6552, guest PC 0x0c0bb912 */
if(!s->budget--) { s->failed_pc=0x0c0bb912u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb914;
P_0c0bb914: /* original 9460, guest PC 0x0c0bb914 */
if(!s->budget--) { s->failed_pc=0x0c0bb914u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9d8u,2);
goto P_0c0bb916;
P_0c0bb916: /* original 65f2, guest PC 0x0c0bb916 */
if(!s->budget--) { s->failed_pc=0x0c0bb916u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb918;
P_0c0bb918: /* original 4e0b, guest PC 0x0c0bb918 */
if(!s->budget--) { s->failed_pc=0x0c0bb918u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb91cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb91cu) { target=s->pc; goto dispatch; }
goto P_0c0bb91c;
P_0c0bb91a: /* original 6552, guest PC 0x0c0bb91a */
if(!s->budget--) { s->failed_pc=0x0c0bb91au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb91c;
P_0c0bb91c: /* original 945e, guest PC 0x0c0bb91c */
if(!s->budget--) { s->failed_pc=0x0c0bb91cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9dcu,2);
goto P_0c0bb91e;
P_0c0bb91e: /* original 905c, guest PC 0x0c0bb91e */
if(!s->budget--) { s->failed_pc=0x0c0bb91eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9dau,2);
goto P_0c0bb920;
P_0c0bb920: /* original 4e0b, guest PC 0x0c0bb920 */
if(!s->budget--) { s->failed_pc=0x0c0bb920u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb924u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb924u) { target=s->pc; goto dispatch; }
goto P_0c0bb924;
P_0c0bb922: /* original 05de, guest PC 0x0c0bb922 */
if(!s->budget--) { s->failed_pc=0x0c0bb922u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb924;
P_0c0bb924: /* original 955b, guest PC 0x0c0bb924 */
if(!s->budget--) { s->failed_pc=0x0c0bb924u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9deu,2);
goto P_0c0bb926;
P_0c0bb926: /* original 35dc, guest PC 0x0c0bb926 */
if(!s->budget--) { s->failed_pc=0x0c0bb926u; return 0; }
r[5]+=r[13];
goto P_0c0bb928;
P_0c0bb928: /* original 2f52, guest PC 0x0c0bb928 */
if(!s->budget--) { s->failed_pc=0x0c0bb928u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb92a;
P_0c0bb92a: /* original 9459, guest PC 0x0c0bb92a */
if(!s->budget--) { s->failed_pc=0x0c0bb92au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9e0u,2);
goto P_0c0bb92c;
P_0c0bb92c: /* original 4e0b, guest PC 0x0c0bb92c */
if(!s->budget--) { s->failed_pc=0x0c0bb92cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb930u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb930u) { target=s->pc; goto dispatch; }
goto P_0c0bb930;
P_0c0bb92e: /* original 6552, guest PC 0x0c0bb92e */
if(!s->budget--) { s->failed_pc=0x0c0bb92eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb930;
P_0c0bb930: /* original 9457, guest PC 0x0c0bb930 */
if(!s->budget--) { s->failed_pc=0x0c0bb930u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9e2u,2);
goto P_0c0bb932;
P_0c0bb932: /* original 65f2, guest PC 0x0c0bb932 */
if(!s->budget--) { s->failed_pc=0x0c0bb932u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb934;
P_0c0bb934: /* original 4e0b, guest PC 0x0c0bb934 */
if(!s->budget--) { s->failed_pc=0x0c0bb934u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb938u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb938u) { target=s->pc; goto dispatch; }
goto P_0c0bb938;
P_0c0bb936: /* original 6552, guest PC 0x0c0bb936 */
if(!s->budget--) { s->failed_pc=0x0c0bb936u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb938;
P_0c0bb938: /* original 9455, guest PC 0x0c0bb938 */
if(!s->budget--) { s->failed_pc=0x0c0bb938u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9e6u,2);
goto P_0c0bb93a;
P_0c0bb93a: /* original 9053, guest PC 0x0c0bb93a */
if(!s->budget--) { s->failed_pc=0x0c0bb93au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9e4u,2);
goto P_0c0bb93c;
P_0c0bb93c: /* original 4e0b, guest PC 0x0c0bb93c */
if(!s->budget--) { s->failed_pc=0x0c0bb93cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb940u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb940u) { target=s->pc; goto dispatch; }
goto P_0c0bb940;
P_0c0bb93e: /* original 05de, guest PC 0x0c0bb93e */
if(!s->budget--) { s->failed_pc=0x0c0bb93eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb940;
P_0c0bb940: /* original 9552, guest PC 0x0c0bb940 */
if(!s->budget--) { s->failed_pc=0x0c0bb940u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9e8u,2);
goto P_0c0bb942;
P_0c0bb942: /* original 35dc, guest PC 0x0c0bb942 */
if(!s->budget--) { s->failed_pc=0x0c0bb942u; return 0; }
r[5]+=r[13];
goto P_0c0bb944;
P_0c0bb944: /* original 2f52, guest PC 0x0c0bb944 */
if(!s->budget--) { s->failed_pc=0x0c0bb944u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb946;
P_0c0bb946: /* original 9450, guest PC 0x0c0bb946 */
if(!s->budget--) { s->failed_pc=0x0c0bb946u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9eau,2);
goto P_0c0bb948;
P_0c0bb948: /* original 4e0b, guest PC 0x0c0bb948 */
if(!s->budget--) { s->failed_pc=0x0c0bb948u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb94cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb94cu) { target=s->pc; goto dispatch; }
goto P_0c0bb94c;
P_0c0bb94a: /* original 6552, guest PC 0x0c0bb94a */
if(!s->budget--) { s->failed_pc=0x0c0bb94au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb94c;
P_0c0bb94c: /* original 944e, guest PC 0x0c0bb94c */
if(!s->budget--) { s->failed_pc=0x0c0bb94cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9ecu,2);
goto P_0c0bb94e;
P_0c0bb94e: /* original 65f2, guest PC 0x0c0bb94e */
if(!s->budget--) { s->failed_pc=0x0c0bb94eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb950;
P_0c0bb950: /* original 4e0b, guest PC 0x0c0bb950 */
if(!s->budget--) { s->failed_pc=0x0c0bb950u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb954u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb954u) { target=s->pc; goto dispatch; }
goto P_0c0bb954;
P_0c0bb952: /* original 6552, guest PC 0x0c0bb952 */
if(!s->budget--) { s->failed_pc=0x0c0bb952u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb954;
P_0c0bb954: /* original 954b, guest PC 0x0c0bb954 */
if(!s->budget--) { s->failed_pc=0x0c0bb954u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9eeu,2);
goto P_0c0bb956;
P_0c0bb956: /* original 35dc, guest PC 0x0c0bb956 */
if(!s->budget--) { s->failed_pc=0x0c0bb956u; return 0; }
r[5]+=r[13];
goto P_0c0bb958;
P_0c0bb958: /* original 2f52, guest PC 0x0c0bb958 */
if(!s->budget--) { s->failed_pc=0x0c0bb958u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0bb95a;
P_0c0bb95a: /* original 9449, guest PC 0x0c0bb95a */
if(!s->budget--) { s->failed_pc=0x0c0bb95au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9f0u,2);
goto P_0c0bb95c;
P_0c0bb95c: /* original 4e0b, guest PC 0x0c0bb95c */
if(!s->budget--) { s->failed_pc=0x0c0bb95cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb960u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb960u) { target=s->pc; goto dispatch; }
goto P_0c0bb960;
P_0c0bb95e: /* original 6552, guest PC 0x0c0bb95e */
if(!s->budget--) { s->failed_pc=0x0c0bb95eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb960;
P_0c0bb960: /* original 9447, guest PC 0x0c0bb960 */
if(!s->budget--) { s->failed_pc=0x0c0bb960u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9f2u,2);
goto P_0c0bb962;
P_0c0bb962: /* original 65f2, guest PC 0x0c0bb962 */
if(!s->budget--) { s->failed_pc=0x0c0bb962u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0bb964;
P_0c0bb964: /* original 4e0b, guest PC 0x0c0bb964 */
if(!s->budget--) { s->failed_pc=0x0c0bb964u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb968u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb968u) { target=s->pc; goto dispatch; }
goto P_0c0bb968;
P_0c0bb966: /* original 6552, guest PC 0x0c0bb966 */
if(!s->budget--) { s->failed_pc=0x0c0bb966u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0bb968;
P_0c0bb968: /* original 9445, guest PC 0x0c0bb968 */
if(!s->budget--) { s->failed_pc=0x0c0bb968u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9f6u,2);
goto P_0c0bb96a;
P_0c0bb96a: /* original 9043, guest PC 0x0c0bb96a */
if(!s->budget--) { s->failed_pc=0x0c0bb96au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9f4u,2);
goto P_0c0bb96c;
P_0c0bb96c: /* original 4e0b, guest PC 0x0c0bb96c */
if(!s->budget--) { s->failed_pc=0x0c0bb96cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb970u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb970u) { target=s->pc; goto dispatch; }
goto P_0c0bb970;
P_0c0bb96e: /* original 05de, guest PC 0x0c0bb96e */
if(!s->budget--) { s->failed_pc=0x0c0bb96eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb970;
P_0c0bb970: /* original 9443, guest PC 0x0c0bb970 */
if(!s->budget--) { s->failed_pc=0x0c0bb970u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9fau,2);
goto P_0c0bb972;
P_0c0bb972: /* original 9041, guest PC 0x0c0bb972 */
if(!s->budget--) { s->failed_pc=0x0c0bb972u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9f8u,2);
goto P_0c0bb974;
P_0c0bb974: /* original 4e0b, guest PC 0x0c0bb974 */
if(!s->budget--) { s->failed_pc=0x0c0bb974u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb978u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb978u) { target=s->pc; goto dispatch; }
goto P_0c0bb978;
P_0c0bb976: /* original 05de, guest PC 0x0c0bb976 */
if(!s->budget--) { s->failed_pc=0x0c0bb976u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb978;
P_0c0bb978: /* original 9441, guest PC 0x0c0bb978 */
if(!s->budget--) { s->failed_pc=0x0c0bb978u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9feu,2);
goto P_0c0bb97a;
P_0c0bb97a: /* original 903f, guest PC 0x0c0bb97a */
if(!s->budget--) { s->failed_pc=0x0c0bb97au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bb9fcu,2);
goto P_0c0bb97c;
P_0c0bb97c: /* original 4e0b, guest PC 0x0c0bb97c */
if(!s->budget--) { s->failed_pc=0x0c0bb97cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb980u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb980u) { target=s->pc; goto dispatch; }
goto P_0c0bb980;
P_0c0bb97e: /* original 05de, guest PC 0x0c0bb97e */
if(!s->budget--) { s->failed_pc=0x0c0bb97eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb980;
P_0c0bb980: /* original 943f, guest PC 0x0c0bb980 */
if(!s->budget--) { s->failed_pc=0x0c0bb980u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba02u,2);
goto P_0c0bb982;
P_0c0bb982: /* original 903d, guest PC 0x0c0bb982 */
if(!s->budget--) { s->failed_pc=0x0c0bb982u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba00u,2);
goto P_0c0bb984;
P_0c0bb984: /* original 4e0b, guest PC 0x0c0bb984 */
if(!s->budget--) { s->failed_pc=0x0c0bb984u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bb988u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bb988u) { target=s->pc; goto dispatch; }
goto P_0c0bb988;
P_0c0bb986: /* original 05de, guest PC 0x0c0bb986 */
if(!s->budget--) { s->failed_pc=0x0c0bb986u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bb988;
P_0c0bb988: /* original 903c, guest PC 0x0c0bb988 */
if(!s->budget--) { s->failed_pc=0x0c0bb988u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba04u,2);
goto P_0c0bb98a;
P_0c0bb98a: /* original a03c, guest PC 0x0c0bb98a */
if(!s->budget--) { s->failed_pc=0x0c0bb98au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba06;
P_0c0bb98c: /* original 05de, guest PC 0x0c0bb98c */
if(!s->budget--) { s->failed_pc=0x0c0bb98cu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0bb98eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bb98eu; return 0; } return 1;
P_0c0bba06: /* original 9432, guest PC 0x0c0bba06 */
if(!s->budget--) { s->failed_pc=0x0c0bba06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba6eu,2);
goto P_0c0bba08;
P_0c0bba08: /* original 4e0b, guest PC 0x0c0bba08 */
if(!s->budget--) { s->failed_pc=0x0c0bba08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba0cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba0cu) { target=s->pc; goto dispatch; }
goto P_0c0bba0c;
P_0c0bba0a: /* original 0009, guest PC 0x0c0bba0a */
if(!s->budget--) { s->failed_pc=0x0c0bba0au; return 0; }
goto P_0c0bba0c;
P_0c0bba0c: /* original 9431, guest PC 0x0c0bba0c */
if(!s->budget--) { s->failed_pc=0x0c0bba0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba72u,2);
goto P_0c0bba0e;
P_0c0bba0e: /* original 902f, guest PC 0x0c0bba0e */
if(!s->budget--) { s->failed_pc=0x0c0bba0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba70u,2);
goto P_0c0bba10;
P_0c0bba10: /* original 4e0b, guest PC 0x0c0bba10 */
if(!s->budget--) { s->failed_pc=0x0c0bba10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba14u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba14u) { target=s->pc; goto dispatch; }
goto P_0c0bba14;
P_0c0bba12: /* original 05de, guest PC 0x0c0bba12 */
if(!s->budget--) { s->failed_pc=0x0c0bba12u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba14;
P_0c0bba14: /* original 942f, guest PC 0x0c0bba14 */
if(!s->budget--) { s->failed_pc=0x0c0bba14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba76u,2);
goto P_0c0bba16;
P_0c0bba16: /* original 902d, guest PC 0x0c0bba16 */
if(!s->budget--) { s->failed_pc=0x0c0bba16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba74u,2);
goto P_0c0bba18;
P_0c0bba18: /* original 4e0b, guest PC 0x0c0bba18 */
if(!s->budget--) { s->failed_pc=0x0c0bba18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba1cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba1cu) { target=s->pc; goto dispatch; }
goto P_0c0bba1c;
P_0c0bba1a: /* original 05de, guest PC 0x0c0bba1a */
if(!s->budget--) { s->failed_pc=0x0c0bba1au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba1c;
P_0c0bba1c: /* original 942d, guest PC 0x0c0bba1c */
if(!s->budget--) { s->failed_pc=0x0c0bba1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba7au,2);
goto P_0c0bba1e;
P_0c0bba1e: /* original 902b, guest PC 0x0c0bba1e */
if(!s->budget--) { s->failed_pc=0x0c0bba1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba78u,2);
goto P_0c0bba20;
P_0c0bba20: /* original 4e0b, guest PC 0x0c0bba20 */
if(!s->budget--) { s->failed_pc=0x0c0bba20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba24u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba24u) { target=s->pc; goto dispatch; }
goto P_0c0bba24;
P_0c0bba22: /* original 05de, guest PC 0x0c0bba22 */
if(!s->budget--) { s->failed_pc=0x0c0bba22u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba24;
P_0c0bba24: /* original 942b, guest PC 0x0c0bba24 */
if(!s->budget--) { s->failed_pc=0x0c0bba24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba7eu,2);
goto P_0c0bba26;
P_0c0bba26: /* original 9029, guest PC 0x0c0bba26 */
if(!s->budget--) { s->failed_pc=0x0c0bba26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba7cu,2);
goto P_0c0bba28;
P_0c0bba28: /* original 4e0b, guest PC 0x0c0bba28 */
if(!s->budget--) { s->failed_pc=0x0c0bba28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba2cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba2cu) { target=s->pc; goto dispatch; }
goto P_0c0bba2c;
P_0c0bba2a: /* original 05de, guest PC 0x0c0bba2a */
if(!s->budget--) { s->failed_pc=0x0c0bba2au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba2c;
P_0c0bba2c: /* original 9429, guest PC 0x0c0bba2c */
if(!s->budget--) { s->failed_pc=0x0c0bba2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba82u,2);
goto P_0c0bba2e;
P_0c0bba2e: /* original 9027, guest PC 0x0c0bba2e */
if(!s->budget--) { s->failed_pc=0x0c0bba2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba80u,2);
goto P_0c0bba30;
P_0c0bba30: /* original 4e0b, guest PC 0x0c0bba30 */
if(!s->budget--) { s->failed_pc=0x0c0bba30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba34u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba34u) { target=s->pc; goto dispatch; }
goto P_0c0bba34;
P_0c0bba32: /* original 05de, guest PC 0x0c0bba32 */
if(!s->budget--) { s->failed_pc=0x0c0bba32u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba34;
P_0c0bba34: /* original 9427, guest PC 0x0c0bba34 */
if(!s->budget--) { s->failed_pc=0x0c0bba34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba86u,2);
goto P_0c0bba36;
P_0c0bba36: /* original 9025, guest PC 0x0c0bba36 */
if(!s->budget--) { s->failed_pc=0x0c0bba36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba84u,2);
goto P_0c0bba38;
P_0c0bba38: /* original 4e0b, guest PC 0x0c0bba38 */
if(!s->budget--) { s->failed_pc=0x0c0bba38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba3cu) { target=s->pc; goto dispatch; }
goto P_0c0bba3c;
P_0c0bba3a: /* original 05de, guest PC 0x0c0bba3a */
if(!s->budget--) { s->failed_pc=0x0c0bba3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba3c;
P_0c0bba3c: /* original 9425, guest PC 0x0c0bba3c */
if(!s->budget--) { s->failed_pc=0x0c0bba3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba8au,2);
goto P_0c0bba3e;
P_0c0bba3e: /* original 9023, guest PC 0x0c0bba3e */
if(!s->budget--) { s->failed_pc=0x0c0bba3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba88u,2);
goto P_0c0bba40;
P_0c0bba40: /* original 4e0b, guest PC 0x0c0bba40 */
if(!s->budget--) { s->failed_pc=0x0c0bba40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba44u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba44u) { target=s->pc; goto dispatch; }
goto P_0c0bba44;
P_0c0bba42: /* original 05de, guest PC 0x0c0bba42 */
if(!s->budget--) { s->failed_pc=0x0c0bba42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba44;
P_0c0bba44: /* original 9423, guest PC 0x0c0bba44 */
if(!s->budget--) { s->failed_pc=0x0c0bba44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba8eu,2);
goto P_0c0bba46;
P_0c0bba46: /* original 9021, guest PC 0x0c0bba46 */
if(!s->budget--) { s->failed_pc=0x0c0bba46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba8cu,2);
goto P_0c0bba48;
P_0c0bba48: /* original 4e0b, guest PC 0x0c0bba48 */
if(!s->budget--) { s->failed_pc=0x0c0bba48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba4cu) { target=s->pc; goto dispatch; }
goto P_0c0bba4c;
P_0c0bba4a: /* original 05de, guest PC 0x0c0bba4a */
if(!s->budget--) { s->failed_pc=0x0c0bba4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba4c;
P_0c0bba4c: /* original 9421, guest PC 0x0c0bba4c */
if(!s->budget--) { s->failed_pc=0x0c0bba4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba92u,2);
goto P_0c0bba4e;
P_0c0bba4e: /* original 901f, guest PC 0x0c0bba4e */
if(!s->budget--) { s->failed_pc=0x0c0bba4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba90u,2);
goto P_0c0bba50;
P_0c0bba50: /* original 4e0b, guest PC 0x0c0bba50 */
if(!s->budget--) { s->failed_pc=0x0c0bba50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba54u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba54u) { target=s->pc; goto dispatch; }
goto P_0c0bba54;
P_0c0bba52: /* original 05de, guest PC 0x0c0bba52 */
if(!s->budget--) { s->failed_pc=0x0c0bba52u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba54;
P_0c0bba54: /* original 941f, guest PC 0x0c0bba54 */
if(!s->budget--) { s->failed_pc=0x0c0bba54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba96u,2);
goto P_0c0bba56;
P_0c0bba56: /* original 901d, guest PC 0x0c0bba56 */
if(!s->budget--) { s->failed_pc=0x0c0bba56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0bba94u,2);
goto P_0c0bba58;
P_0c0bba58: /* original 4e0b, guest PC 0x0c0bba58 */
if(!s->budget--) { s->failed_pc=0x0c0bba58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0bba5cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0bba5cu) { target=s->pc; goto dispatch; }
goto P_0c0bba5c;
P_0c0bba5a: /* original 05de, guest PC 0x0c0bba5a */
if(!s->budget--) { s->failed_pc=0x0c0bba5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0bba5c;
P_0c0bba5c: /* original 7f08, guest PC 0x0c0bba5c */
if(!s->budget--) { s->failed_pc=0x0c0bba5cu; return 0; }
r[15]+=0x00000008u;
goto P_0c0bba5e;
P_0c0bba5e: /* original 4f26, guest PC 0x0c0bba5e */
if(!s->budget--) { s->failed_pc=0x0c0bba5eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0bba60;
P_0c0bba60: /* original 69f6, guest PC 0x0c0bba60 */
if(!s->budget--) { s->failed_pc=0x0c0bba60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0bba62;
P_0c0bba62: /* original 6af6, guest PC 0x0c0bba62 */
if(!s->budget--) { s->failed_pc=0x0c0bba62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0bba64;
P_0c0bba64: /* original 6bf6, guest PC 0x0c0bba64 */
if(!s->budget--) { s->failed_pc=0x0c0bba64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0bba66;
P_0c0bba66: /* original 6cf6, guest PC 0x0c0bba66 */
if(!s->budget--) { s->failed_pc=0x0c0bba66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0bba68;
P_0c0bba68: /* original 6df6, guest PC 0x0c0bba68 */
if(!s->budget--) { s->failed_pc=0x0c0bba68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0bba6a;
P_0c0bba6a: /* original 000b, guest PC 0x0c0bba6a */
if(!s->budget--) { s->failed_pc=0x0c0bba6au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0bba6c: /* original 6ef6, guest PC 0x0c0bba6c */
if(!s->budget--) { s->failed_pc=0x0c0bba6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0bba6eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0bba6eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
