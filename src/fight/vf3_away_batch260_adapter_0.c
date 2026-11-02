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
int vf3_away_batch260_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0cc5e6u: goto P_0c0cc5e6;
case 0x0c0cc5e8u: goto P_0c0cc5e8;
case 0x0c0cc5eau: goto P_0c0cc5ea;
case 0x0c0cc5ecu: goto P_0c0cc5ec;
case 0x0c0cc5eeu: goto P_0c0cc5ee;
case 0x0c0cc5f0u: goto P_0c0cc5f0;
case 0x0c0cc5f2u: goto P_0c0cc5f2;
case 0x0c0cc5f4u: goto P_0c0cc5f4;
case 0x0c0cc5f6u: goto P_0c0cc5f6;
case 0x0c0cc5f8u: goto P_0c0cc5f8;
case 0x0c0cc5fau: goto P_0c0cc5fa;
case 0x0c0cc5fcu: goto P_0c0cc5fc;
case 0x0c0cc5feu: goto P_0c0cc5fe;
case 0x0c0cc600u: goto P_0c0cc600;
case 0x0c0cc602u: goto P_0c0cc602;
case 0x0c0cc604u: goto P_0c0cc604;
case 0x0c0cc606u: goto P_0c0cc606;
case 0x0c0cc608u: goto P_0c0cc608;
case 0x0c0cc60au: goto P_0c0cc60a;
case 0x0c0cc60cu: goto P_0c0cc60c;
case 0x0c0cc60eu: goto P_0c0cc60e;
case 0x0c0cc610u: goto P_0c0cc610;
case 0x0c0cc612u: goto P_0c0cc612;
case 0x0c0cc614u: goto P_0c0cc614;
case 0x0c0cc616u: goto P_0c0cc616;
case 0x0c0cc618u: goto P_0c0cc618;
case 0x0c0cc61au: goto P_0c0cc61a;
case 0x0c0cc61cu: goto P_0c0cc61c;
case 0x0c0cc61eu: goto P_0c0cc61e;
case 0x0c0cc620u: goto P_0c0cc620;
case 0x0c0cc622u: goto P_0c0cc622;
case 0x0c0cc624u: goto P_0c0cc624;
case 0x0c0cc626u: goto P_0c0cc626;
case 0x0c0cc628u: goto P_0c0cc628;
case 0x0c0cc62au: goto P_0c0cc62a;
case 0x0c0cc62cu: goto P_0c0cc62c;
case 0x0c0cc62eu: goto P_0c0cc62e;
case 0x0c0cc630u: goto P_0c0cc630;
case 0x0c0cc632u: goto P_0c0cc632;
case 0x0c0cc634u: goto P_0c0cc634;
case 0x0c0cc636u: goto P_0c0cc636;
case 0x0c0cc638u: goto P_0c0cc638;
case 0x0c0cc63au: goto P_0c0cc63a;
case 0x0c0cc63cu: goto P_0c0cc63c;
case 0x0c0cc63eu: goto P_0c0cc63e;
case 0x0c0cc640u: goto P_0c0cc640;
case 0x0c0cc642u: goto P_0c0cc642;
case 0x0c0cc644u: goto P_0c0cc644;
case 0x0c0cc646u: goto P_0c0cc646;
case 0x0c0cc648u: goto P_0c0cc648;
case 0x0c0cc64au: goto P_0c0cc64a;
case 0x0c0cc64cu: goto P_0c0cc64c;
case 0x0c0cc67cu: goto P_0c0cc67c;
case 0x0c0cc67eu: goto P_0c0cc67e;
case 0x0c0cc680u: goto P_0c0cc680;
case 0x0c0cc682u: goto P_0c0cc682;
case 0x0c0cc684u: goto P_0c0cc684;
case 0x0c0cc686u: goto P_0c0cc686;
case 0x0c0cc688u: goto P_0c0cc688;
case 0x0c0cc68au: goto P_0c0cc68a;
case 0x0c0cc68cu: goto P_0c0cc68c;
case 0x0c0cc68eu: goto P_0c0cc68e;
case 0x0c0cc690u: goto P_0c0cc690;
case 0x0c0cc692u: goto P_0c0cc692;
case 0x0c0cc694u: goto P_0c0cc694;
case 0x0c0cc696u: goto P_0c0cc696;
case 0x0c0cc698u: goto P_0c0cc698;
case 0x0c0cc69au: goto P_0c0cc69a;
case 0x0c0cc69cu: goto P_0c0cc69c;
case 0x0c0cc69eu: goto P_0c0cc69e;
case 0x0c0cc6a0u: goto P_0c0cc6a0;
case 0x0c0cc6a2u: goto P_0c0cc6a2;
case 0x0c0cc6a4u: goto P_0c0cc6a4;
case 0x0c0cc6a6u: goto P_0c0cc6a6;
case 0x0c0cc6a8u: goto P_0c0cc6a8;
case 0x0c0cc6aau: goto P_0c0cc6aa;
case 0x0c0cc6acu: goto P_0c0cc6ac;
case 0x0c0cc6aeu: goto P_0c0cc6ae;
case 0x0c0cc6b0u: goto P_0c0cc6b0;
case 0x0c0cc6b2u: goto P_0c0cc6b2;
case 0x0c0cc6b4u: goto P_0c0cc6b4;
case 0x0c0cc6b6u: goto P_0c0cc6b6;
case 0x0c0cc6b8u: goto P_0c0cc6b8;
case 0x0c0cc6bau: goto P_0c0cc6ba;
case 0x0c0cc6bcu: goto P_0c0cc6bc;
case 0x0c0cc6beu: goto P_0c0cc6be;
case 0x0c0cc6c0u: goto P_0c0cc6c0;
case 0x0c0cc6c2u: goto P_0c0cc6c2;
case 0x0c0cc6c4u: goto P_0c0cc6c4;
case 0x0c0cc6c6u: goto P_0c0cc6c6;
case 0x0c0cc6c8u: goto P_0c0cc6c8;
case 0x0c0cc6cau: goto P_0c0cc6ca;
case 0x0c0cc6ccu: goto P_0c0cc6cc;
case 0x0c0cc6ceu: goto P_0c0cc6ce;
case 0x0c0cc6d0u: goto P_0c0cc6d0;
case 0x0c0cc6d2u: goto P_0c0cc6d2;
case 0x0c0cc6d4u: goto P_0c0cc6d4;
case 0x0c0cc6d6u: goto P_0c0cc6d6;
case 0x0c0cc6d8u: goto P_0c0cc6d8;
case 0x0c0cc6dau: goto P_0c0cc6da;
case 0x0c0cc6dcu: goto P_0c0cc6dc;
case 0x0c0cc6deu: goto P_0c0cc6de;
case 0x0c0cc6e0u: goto P_0c0cc6e0;
case 0x0c0cc6e2u: goto P_0c0cc6e2;
case 0x0c0cc6e4u: goto P_0c0cc6e4;
case 0x0c0cc6e6u: goto P_0c0cc6e6;
case 0x0c0cc6e8u: goto P_0c0cc6e8;
case 0x0c0cc6eau: goto P_0c0cc6ea;
case 0x0c0cc6ecu: goto P_0c0cc6ec;
case 0x0c0cc6eeu: goto P_0c0cc6ee;
case 0x0c0cc6f0u: goto P_0c0cc6f0;
case 0x0c0cc6f2u: goto P_0c0cc6f2;
case 0x0c0cc6f4u: goto P_0c0cc6f4;
case 0x0c0cc6f6u: goto P_0c0cc6f6;
case 0x0c0cc6f8u: goto P_0c0cc6f8;
case 0x0c0cc6fau: goto P_0c0cc6fa;
case 0x0c0cc6fcu: goto P_0c0cc6fc;
case 0x0c0cc6feu: goto P_0c0cc6fe;
case 0x0c0cc700u: goto P_0c0cc700;
case 0x0c0cc702u: goto P_0c0cc702;
case 0x0c0cc704u: goto P_0c0cc704;
case 0x0c0cc706u: goto P_0c0cc706;
case 0x0c0cc708u: goto P_0c0cc708;
case 0x0c0cc70au: goto P_0c0cc70a;
case 0x0c0cc70cu: goto P_0c0cc70c;
case 0x0c0cc70eu: goto P_0c0cc70e;
case 0x0c0cc710u: goto P_0c0cc710;
case 0x0c0cc712u: goto P_0c0cc712;
case 0x0c0cc714u: goto P_0c0cc714;
case 0x0c0cc716u: goto P_0c0cc716;
case 0x0c0cc718u: goto P_0c0cc718;
case 0x0c0cc71au: goto P_0c0cc71a;
case 0x0c0cc71cu: goto P_0c0cc71c;
case 0x0c0cc71eu: goto P_0c0cc71e;
case 0x0c0cc720u: goto P_0c0cc720;
case 0x0c0cc722u: goto P_0c0cc722;
case 0x0c0cc724u: goto P_0c0cc724;
case 0x0c0cc726u: goto P_0c0cc726;
case 0x0c0cc728u: goto P_0c0cc728;
case 0x0c0cc72au: goto P_0c0cc72a;
case 0x0c0cc72cu: goto P_0c0cc72c;
case 0x0c0cc72eu: goto P_0c0cc72e;
case 0x0c0cc730u: goto P_0c0cc730;
case 0x0c0cc732u: goto P_0c0cc732;
case 0x0c0cc734u: goto P_0c0cc734;
case 0x0c0cc736u: goto P_0c0cc736;
case 0x0c0cc738u: goto P_0c0cc738;
case 0x0c0cc73au: goto P_0c0cc73a;
case 0x0c0cc73cu: goto P_0c0cc73c;
case 0x0c0cc73eu: goto P_0c0cc73e;
case 0x0c0cc740u: goto P_0c0cc740;
case 0x0c0cc742u: goto P_0c0cc742;
case 0x0c0cc744u: goto P_0c0cc744;
case 0x0c0cc746u: goto P_0c0cc746;
case 0x0c0cc748u: goto P_0c0cc748;
case 0x0c0cc74au: goto P_0c0cc74a;
case 0x0c0cc74cu: goto P_0c0cc74c;
case 0x0c0cc74eu: goto P_0c0cc74e;
case 0x0c0cc750u: goto P_0c0cc750;
case 0x0c0cc752u: goto P_0c0cc752;
case 0x0c0cc754u: goto P_0c0cc754;
case 0x0c0cc756u: goto P_0c0cc756;
case 0x0c0cc758u: goto P_0c0cc758;
case 0x0c0cc75au: goto P_0c0cc75a;
case 0x0c0cc75cu: goto P_0c0cc75c;
case 0x0c0cc75eu: goto P_0c0cc75e;
case 0x0c0cc760u: goto P_0c0cc760;
case 0x0c0cc762u: goto P_0c0cc762;
case 0x0c0cc764u: goto P_0c0cc764;
case 0x0c0cc766u: goto P_0c0cc766;
case 0x0c0cc768u: goto P_0c0cc768;
case 0x0c0cc76au: goto P_0c0cc76a;
case 0x0c0cc76cu: goto P_0c0cc76c;
case 0x0c0cc76eu: goto P_0c0cc76e;
case 0x0c0cc770u: goto P_0c0cc770;
case 0x0c0cc772u: goto P_0c0cc772;
case 0x0c0cc774u: goto P_0c0cc774;
case 0x0c0cc776u: goto P_0c0cc776;
case 0x0c0cc778u: goto P_0c0cc778;
case 0x0c0cc77au: goto P_0c0cc77a;
case 0x0c0cc77cu: goto P_0c0cc77c;
case 0x0c0cc7b4u: goto P_0c0cc7b4;
case 0x0c0cc7b6u: goto P_0c0cc7b6;
case 0x0c0cc7b8u: goto P_0c0cc7b8;
case 0x0c0cc7bau: goto P_0c0cc7ba;
case 0x0c0cc7bcu: goto P_0c0cc7bc;
case 0x0c0cc7beu: goto P_0c0cc7be;
case 0x0c0cc7c0u: goto P_0c0cc7c0;
case 0x0c0cc7c2u: goto P_0c0cc7c2;
case 0x0c0cc7c4u: goto P_0c0cc7c4;
case 0x0c0cc7c6u: goto P_0c0cc7c6;
case 0x0c0cc7c8u: goto P_0c0cc7c8;
case 0x0c0cc7cau: goto P_0c0cc7ca;
case 0x0c0cc7ccu: goto P_0c0cc7cc;
case 0x0c0cc7ceu: goto P_0c0cc7ce;
case 0x0c0cc7d0u: goto P_0c0cc7d0;
case 0x0c0cc7d2u: goto P_0c0cc7d2;
case 0x0c0cc7d4u: goto P_0c0cc7d4;
case 0x0c0cc7d6u: goto P_0c0cc7d6;
case 0x0c0cc7d8u: goto P_0c0cc7d8;
case 0x0c0cc7dau: goto P_0c0cc7da;
case 0x0c0cc7dcu: goto P_0c0cc7dc;
case 0x0c0cc7deu: goto P_0c0cc7de;
case 0x0c0cc7e0u: goto P_0c0cc7e0;
case 0x0c0cc7e2u: goto P_0c0cc7e2;
case 0x0c0cc7e4u: goto P_0c0cc7e4;
case 0x0c0cc7e6u: goto P_0c0cc7e6;
case 0x0c0cc7e8u: goto P_0c0cc7e8;
case 0x0c0cc7eau: goto P_0c0cc7ea;
case 0x0c0cc7ecu: goto P_0c0cc7ec;
case 0x0c0cc7eeu: goto P_0c0cc7ee;
case 0x0c0cc7f0u: goto P_0c0cc7f0;
case 0x0c0cc7f2u: goto P_0c0cc7f2;
case 0x0c0cc7f4u: goto P_0c0cc7f4;
case 0x0c0cc7f6u: goto P_0c0cc7f6;
case 0x0c0cc7f8u: goto P_0c0cc7f8;
case 0x0c0cc7fau: goto P_0c0cc7fa;
case 0x0c0cc7fcu: goto P_0c0cc7fc;
case 0x0c0cc7feu: goto P_0c0cc7fe;
case 0x0c0cc800u: goto P_0c0cc800;
case 0x0c0cc802u: goto P_0c0cc802;
case 0x0c0cc804u: goto P_0c0cc804;
case 0x0c0cc806u: goto P_0c0cc806;
case 0x0c0cc808u: goto P_0c0cc808;
case 0x0c0cc80au: goto P_0c0cc80a;
case 0x0c0cc80cu: goto P_0c0cc80c;
case 0x0c0cc80eu: goto P_0c0cc80e;
case 0x0c0cc810u: goto P_0c0cc810;
case 0x0c0cc812u: goto P_0c0cc812;
case 0x0c0cc814u: goto P_0c0cc814;
case 0x0c0cc816u: goto P_0c0cc816;
case 0x0c0cc818u: goto P_0c0cc818;
case 0x0c0cc81au: goto P_0c0cc81a;
case 0x0c0cc81cu: goto P_0c0cc81c;
case 0x0c0cc81eu: goto P_0c0cc81e;
case 0x0c0cc820u: goto P_0c0cc820;
case 0x0c0cc822u: goto P_0c0cc822;
case 0x0c0cc824u: goto P_0c0cc824;
case 0x0c0cc826u: goto P_0c0cc826;
case 0x0c0cc828u: goto P_0c0cc828;
case 0x0c0cc82au: goto P_0c0cc82a;
case 0x0c0cc82cu: goto P_0c0cc82c;
case 0x0c0cc82eu: goto P_0c0cc82e;
case 0x0c0cc830u: goto P_0c0cc830;
case 0x0c0cc832u: goto P_0c0cc832;
case 0x0c0cc834u: goto P_0c0cc834;
case 0x0c0cc836u: goto P_0c0cc836;
case 0x0c0cc838u: goto P_0c0cc838;
case 0x0c0cc83au: goto P_0c0cc83a;
case 0x0c0cc83cu: goto P_0c0cc83c;
case 0x0c0cc83eu: goto P_0c0cc83e;
case 0x0c0cc840u: goto P_0c0cc840;
case 0x0c0cc842u: goto P_0c0cc842;
case 0x0c0cc844u: goto P_0c0cc844;
case 0x0c0cc846u: goto P_0c0cc846;
case 0x0c0cc848u: goto P_0c0cc848;
case 0x0c0cc84au: goto P_0c0cc84a;
case 0x0c0cc84cu: goto P_0c0cc84c;
case 0x0c0cc84eu: goto P_0c0cc84e;
case 0x0c0cc850u: goto P_0c0cc850;
case 0x0c0cc852u: goto P_0c0cc852;
case 0x0c0cc854u: goto P_0c0cc854;
case 0x0c0cc856u: goto P_0c0cc856;
case 0x0c0cc858u: goto P_0c0cc858;
case 0x0c0cc85au: goto P_0c0cc85a;
case 0x0c0cc85cu: goto P_0c0cc85c;
case 0x0c0cc85eu: goto P_0c0cc85e;
case 0x0c0cc860u: goto P_0c0cc860;
case 0x0c0cc862u: goto P_0c0cc862;
case 0x0c0cc864u: goto P_0c0cc864;
case 0x0c0cc866u: goto P_0c0cc866;
case 0x0c0cc868u: goto P_0c0cc868;
case 0x0c0cc86au: goto P_0c0cc86a;
case 0x0c0cc86cu: goto P_0c0cc86c;
case 0x0c0cc86eu: goto P_0c0cc86e;
case 0x0c0cc870u: goto P_0c0cc870;
case 0x0c0cc872u: goto P_0c0cc872;
case 0x0c0cc874u: goto P_0c0cc874;
case 0x0c0cc876u: goto P_0c0cc876;
case 0x0c0cc878u: goto P_0c0cc878;
case 0x0c0cc87au: goto P_0c0cc87a;
case 0x0c0cc87cu: goto P_0c0cc87c;
case 0x0c0cc87eu: goto P_0c0cc87e;
case 0x0c0cc880u: goto P_0c0cc880;
case 0x0c0cc882u: goto P_0c0cc882;
case 0x0c0cc884u: goto P_0c0cc884;
case 0x0c0cc886u: goto P_0c0cc886;
case 0x0c0cc888u: goto P_0c0cc888;
case 0x0c0cc88au: goto P_0c0cc88a;
case 0x0c0cc88cu: goto P_0c0cc88c;
case 0x0c0cc88eu: goto P_0c0cc88e;
case 0x0c0cc890u: goto P_0c0cc890;
case 0x0c0cc892u: goto P_0c0cc892;
case 0x0c0cc894u: goto P_0c0cc894;
case 0x0c0cc896u: goto P_0c0cc896;
case 0x0c0cc898u: goto P_0c0cc898;
case 0x0c0cc89au: goto P_0c0cc89a;
case 0x0c0cc8f0u: goto P_0c0cc8f0;
case 0x0c0cc8f2u: goto P_0c0cc8f2;
case 0x0c0cc8f4u: goto P_0c0cc8f4;
case 0x0c0cc8f6u: goto P_0c0cc8f6;
case 0x0c0cc8f8u: goto P_0c0cc8f8;
case 0x0c0cc8fau: goto P_0c0cc8fa;
case 0x0c0cc8fcu: goto P_0c0cc8fc;
case 0x0c0cc8feu: goto P_0c0cc8fe;
case 0x0c0cc900u: goto P_0c0cc900;
case 0x0c0cc902u: goto P_0c0cc902;
case 0x0c0cc904u: goto P_0c0cc904;
case 0x0c0cc906u: goto P_0c0cc906;
case 0x0c0cc908u: goto P_0c0cc908;
case 0x0c0cc90au: goto P_0c0cc90a;
case 0x0c0cc90cu: goto P_0c0cc90c;
case 0x0c0cc90eu: goto P_0c0cc90e;
case 0x0c0cc910u: goto P_0c0cc910;
case 0x0c0cc912u: goto P_0c0cc912;
case 0x0c0cc914u: goto P_0c0cc914;
case 0x0c0cc916u: goto P_0c0cc916;
case 0x0c0cc918u: goto P_0c0cc918;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0cc5e6: /* original 2fe6, guest PC 0x0c0cc5e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5e8;
P_0c0cc5e8: /* original 2fd6, guest PC 0x0c0cc5e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5e8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ea;
P_0c0cc5ea: /* original 2fc6, guest PC 0x0c0cc5ea */
if(!s->budget--) { s->failed_pc=0x0c0cc5eau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ec;
P_0c0cc5ec: /* original 2fb6, guest PC 0x0c0cc5ec */
if(!s->budget--) { s->failed_pc=0x0c0cc5ecu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5ee;
P_0c0cc5ee: /* original 2fa6, guest PC 0x0c0cc5ee */
if(!s->budget--) { s->failed_pc=0x0c0cc5eeu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5f0;
P_0c0cc5f0: /* original 2f96, guest PC 0x0c0cc5f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc5f2;
P_0c0cc5f2: /* original d11f, guest PC 0x0c0cc5f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f2u; return 0; }
r[1]=read(ram,0x0c0cc670u,4);
goto P_0c0cc5f4;
P_0c0cc5f4: /* original 4f22, guest PC 0x0c0cc5f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc5f6;
P_0c0cc5f6: /* original 6212, guest PC 0x0c0cc5f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0cc5f8;
P_0c0cc5f8: /* original d31c, guest PC 0x0c0cc5f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc5f8u; return 0; }
r[3]=read(ram,0x0c0cc66cu,4);
goto P_0c0cc5fa;
P_0c0cc5fa: /* original 2238, guest PC 0x0c0cc5fa */
if(!s->budget--) { s->failed_pc=0x0c0cc5fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc5fc;
P_0c0cc5fc: /* original 8f1f, guest PC 0x0c0cc5fc */
if(!s->budget--) { s->failed_pc=0x0c0cc5fcu; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(!cond) { goto P_0c0cc63e; }
goto P_0c0cc600;
P_0c0cc5fe: /* original 6e43, guest PC 0x0c0cc5fe */
if(!s->budget--) { s->failed_pc=0x0c0cc5feu; return 0; }
r[14]=r[4];
goto P_0c0cc600;
P_0c0cc600: /* original 902b, guest PC 0x0c0cc600 */
if(!s->budget--) { s->failed_pc=0x0c0cc600u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc65au,2);
goto P_0c0cc602;
P_0c0cc602: /* original ec00, guest PC 0x0c0cc602 */
if(!s->budget--) { s->failed_pc=0x0c0cc602u; return 0; }
r[12]=0x00000000u;
goto P_0c0cc604;
P_0c0cc604: /* original d91b, guest PC 0x0c0cc604 */
if(!s->budget--) { s->failed_pc=0x0c0cc604u; return 0; }
r[9]=read(ram,0x0c0cc674u,4);
goto P_0c0cc606;
P_0c0cc606: /* original dd1c, guest PC 0x0c0cc606 */
if(!s->budget--) { s->failed_pc=0x0c0cc606u; return 0; }
r[13]=read(ram,0x0c0cc678u,4);
goto P_0c0cc608;
P_0c0cc608: /* original 0bee, guest PC 0x0c0cc608 */
if(!s->budget--) { s->failed_pc=0x0c0cc608u; return 0; }
r[11]=read(ram,r[14]+r[0],4);
goto P_0c0cc60a;
P_0c0cc60a: /* original a006, guest PC 0x0c0cc60a */
if(!s->budget--) { s->failed_pc=0x0c0cc60au; return 0; }
r[10]=0x00000008u;
goto P_0c0cc61a;
P_0c0cc60c: /* original ea08, guest PC 0x0c0cc60c */
if(!s->budget--) { s->failed_pc=0x0c0cc60cu; return 0; }
r[10]=0x00000008u;
goto P_0c0cc60e;
P_0c0cc60e: /* original 65d5, guest PC 0x0c0cc60e */
if(!s->budget--) { s->failed_pc=0x0c0cc60eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[5]=tmp;
goto P_0c0cc610;
P_0c0cc610: /* original 35ec, guest PC 0x0c0cc610 */
if(!s->budget--) { s->failed_pc=0x0c0cc610u; return 0; }
r[5]+=r[14];
goto P_0c0cc612;
P_0c0cc612: /* original 490b, guest PC 0x0c0cc612 */
if(!s->budget--) { s->failed_pc=0x0c0cc612u; return 0; }
target=r[9];
r[16]=code_base|0x0c0cc616u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc616u) { target=s->pc; goto dispatch; }
goto P_0c0cc616;
P_0c0cc614: /* original 64b3, guest PC 0x0c0cc614 */
if(!s->budget--) { s->failed_pc=0x0c0cc614u; return 0; }
r[4]=r[11];
goto P_0c0cc616;
P_0c0cc616: /* original 7c01, guest PC 0x0c0cc616 */
if(!s->budget--) { s->failed_pc=0x0c0cc616u; return 0; }
r[12]+=0x00000001u;
goto P_0c0cc618;
P_0c0cc618: /* original 7b40, guest PC 0x0c0cc618 */
if(!s->budget--) { s->failed_pc=0x0c0cc618u; return 0; }
r[11]+=0x00000040u;
goto P_0c0cc61a;
P_0c0cc61a: /* original 3ca3, guest PC 0x0c0cc61a */
if(!s->budget--) { s->failed_pc=0x0c0cc61au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[10])!=0);
goto P_0c0cc61c;
P_0c0cc61c: /* original 8bf7, guest PC 0x0c0cc61c */
if(!s->budget--) { s->failed_pc=0x0c0cc61cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc60e; }
goto P_0c0cc61e;
P_0c0cc61e: /* original 9016, guest PC 0x0c0cc61e */
if(!s->budget--) { s->failed_pc=0x0c0cc61eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc64eu,2);
goto P_0c0cc620;
P_0c0cc620: /* original 04ee, guest PC 0x0c0cc620 */
if(!s->budget--) { s->failed_pc=0x0c0cc620u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0cc622;
P_0c0cc622: /* original 7004, guest PC 0x0c0cc622 */
if(!s->budget--) { s->failed_pc=0x0c0cc622u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc624;
P_0c0cc624: /* original 07ee, guest PC 0x0c0cc624 */
if(!s->budget--) { s->failed_pc=0x0c0cc624u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0cc626;
P_0c0cc626: /* original 7004, guest PC 0x0c0cc626 */
if(!s->budget--) { s->failed_pc=0x0c0cc626u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc628;
P_0c0cc628: /* original 05ee, guest PC 0x0c0cc628 */
if(!s->budget--) { s->failed_pc=0x0c0cc628u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0cc62a;
P_0c0cc62a: /* original 7004, guest PC 0x0c0cc62a */
if(!s->budget--) { s->failed_pc=0x0c0cc62au; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc62c;
P_0c0cc62c: /* original 06ee, guest PC 0x0c0cc62c */
if(!s->budget--) { s->failed_pc=0x0c0cc62cu; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0cc62e;
P_0c0cc62e: /* original 70f8, guest PC 0x0c0cc62e */
if(!s->budget--) { s->failed_pc=0x0c0cc62eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cc630;
P_0c0cc630: /* original 0e46, guest PC 0x0c0cc630 */
if(!s->budget--) { s->failed_pc=0x0c0cc630u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0cc632;
P_0c0cc632: /* original 7004, guest PC 0x0c0cc632 */
if(!s->budget--) { s->failed_pc=0x0c0cc632u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc634;
P_0c0cc634: /* original 0e76, guest PC 0x0c0cc634 */
if(!s->budget--) { s->failed_pc=0x0c0cc634u; return 0; }
write(ram,r[14]+r[0],r[7],4);
goto P_0c0cc636;
P_0c0cc636: /* original 7004, guest PC 0x0c0cc636 */
if(!s->budget--) { s->failed_pc=0x0c0cc636u; return 0; }
r[0]+=0x00000004u;
goto P_0c0cc638;
P_0c0cc638: /* original 0e56, guest PC 0x0c0cc638 */
if(!s->budget--) { s->failed_pc=0x0c0cc638u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0cc63a;
P_0c0cc63a: /* original 70f4, guest PC 0x0c0cc63a */
if(!s->budget--) { s->failed_pc=0x0c0cc63au; return 0; }
r[0]+=0xfffffff4u;
goto P_0c0cc63c;
P_0c0cc63c: /* original 0e66, guest PC 0x0c0cc63c */
if(!s->budget--) { s->failed_pc=0x0c0cc63cu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c0cc63e;
P_0c0cc63e: /* original 4f26, guest PC 0x0c0cc63e */
if(!s->budget--) { s->failed_pc=0x0c0cc63eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc640;
P_0c0cc640: /* original 69f6, guest PC 0x0c0cc640 */
if(!s->budget--) { s->failed_pc=0x0c0cc640u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc642;
P_0c0cc642: /* original 6af6, guest PC 0x0c0cc642 */
if(!s->budget--) { s->failed_pc=0x0c0cc642u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc644;
P_0c0cc644: /* original 6bf6, guest PC 0x0c0cc644 */
if(!s->budget--) { s->failed_pc=0x0c0cc644u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc646;
P_0c0cc646: /* original 6cf6, guest PC 0x0c0cc646 */
if(!s->budget--) { s->failed_pc=0x0c0cc646u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc648;
P_0c0cc648: /* original 6df6, guest PC 0x0c0cc648 */
if(!s->budget--) { s->failed_pc=0x0c0cc648u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc64a;
P_0c0cc64a: /* original 000b, guest PC 0x0c0cc64a */
if(!s->budget--) { s->failed_pc=0x0c0cc64au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc64c: /* original 6ef6, guest PC 0x0c0cc64c */
if(!s->budget--) { s->failed_pc=0x0c0cc64cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0cc64eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc64eu; return 0; } return 1;
P_0c0cc67c: /* original 2fe6, guest PC 0x0c0cc67c */
if(!s->budget--) { s->failed_pc=0x0c0cc67cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc67e;
P_0c0cc67e: /* original c744, guest PC 0x0c0cc67e */
if(!s->budget--) { s->failed_pc=0x0c0cc67eu; return 0; }
r[0]=code_base|0x000cc790u;
goto P_0c0cc680;
P_0c0cc680: /* original 2fd6, guest PC 0x0c0cc680 */
if(!s->budget--) { s->failed_pc=0x0c0cc680u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc682;
P_0c0cc682: /* original 6e53, guest PC 0x0c0cc682 */
if(!s->budget--) { s->failed_pc=0x0c0cc682u; return 0; }
r[14]=r[5];
goto P_0c0cc684;
P_0c0cc684: /* original 2fc6, guest PC 0x0c0cc684 */
if(!s->budget--) { s->failed_pc=0x0c0cc684u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc686;
P_0c0cc686: /* original 2fb6, guest PC 0x0c0cc686 */
if(!s->budget--) { s->failed_pc=0x0c0cc686u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc688;
P_0c0cc688: /* original 2fa6, guest PC 0x0c0cc688 */
if(!s->budget--) { s->failed_pc=0x0c0cc688u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc68a;
P_0c0cc68a: /* original 2f96, guest PC 0x0c0cc68a */
if(!s->budget--) { s->failed_pc=0x0c0cc68au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc68c;
P_0c0cc68c: /* original 2f86, guest PC 0x0c0cc68c */
if(!s->budget--) { s->failed_pc=0x0c0cc68cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cc68e;
P_0c0cc68e: /* original fffb, guest PC 0x0c0cc68e */
if(!s->budget--) { s->failed_pc=0x0c0cc68eu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cc690;
P_0c0cc690: /* original dc3d, guest PC 0x0c0cc690 */
if(!s->budget--) { s->failed_pc=0x0c0cc690u; return 0; }
r[12]=read(ram,0x0c0cc788u,4);
goto P_0c0cc692;
P_0c0cc692: /* original 4f22, guest PC 0x0c0cc692 */
if(!s->budget--) { s->failed_pc=0x0c0cc692u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cc694;
P_0c0cc694: /* original 53c1, guest PC 0x0c0cc694 */
if(!s->budget--) { s->failed_pc=0x0c0cc694u; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0cc696;
P_0c0cc696: /* original 67c2, guest PC 0x0c0cc696 */
if(!s->budget--) { s->failed_pc=0x0c0cc696u; return 0; }
tmp=read(ram,r[12],4);
r[7]=tmp;
goto P_0c0cc698;
P_0c0cc698: /* original 7ffc, guest PC 0x0c0cc698 */
if(!s->budget--) { s->failed_pc=0x0c0cc698u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0cc69a;
P_0c0cc69a: /* original d63c, guest PC 0x0c0cc69a */
if(!s->budget--) { s->failed_pc=0x0c0cc69au; return 0; }
r[6]=read(ram,0x0c0cc78cu,4);
goto P_0c0cc69c;
P_0c0cc69c: /* original 65e2, guest PC 0x0c0cc69c */
if(!s->budget--) { s->failed_pc=0x0c0cc69cu; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0cc69e;
P_0c0cc69e: /* original ff08, guest PC 0x0c0cc69e */
if(!s->budget--) { s->failed_pc=0x0c0cc69eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0cc6a0;
P_0c0cc6a0: /* original 2f32, guest PC 0x0c0cc6a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0cc6a2;
P_0c0cc6a2: /* original 6373, guest PC 0x0c0cc6a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a2u; return 0; }
r[3]=r[7];
goto P_0c0cc6a4;
P_0c0cc6a4: /* original db3b, guest PC 0x0c0cc6a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a4u; return 0; }
r[11]=read(ram,0x0c0cc794u,4);
goto P_0c0cc6a6;
P_0c0cc6a6: /* original 23b8, guest PC 0x0c0cc6a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0cc6a8;
P_0c0cc6a8: /* original 8b14, guest PC 0x0c0cc6a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6d4; }
goto P_0c0cc6aa;
P_0c0cc6aa: /* original d23b, guest PC 0x0c0cc6aa */
if(!s->budget--) { s->failed_pc=0x0c0cc6aau; return 0; }
r[2]=read(ram,0x0c0cc798u,4);
goto P_0c0cc6ac;
P_0c0cc6ac: /* original 2728, guest PC 0x0c0cc6ac */
if(!s->budget--) { s->failed_pc=0x0c0cc6acu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0cc6ae;
P_0c0cc6ae: /* original 8902, guest PC 0x0c0cc6ae */
if(!s->budget--) { s->failed_pc=0x0c0cc6aeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc6b6; }
goto P_0c0cc6b0;
P_0c0cc6b0: /* original 63f2, guest PC 0x0c0cc6b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0cc6b2;
P_0c0cc6b2: /* original 23b8, guest PC 0x0c0cc6b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0cc6b4;
P_0c0cc6b4: /* original 8b0e, guest PC 0x0c0cc6b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6d4; }
goto P_0c0cc6b6;
P_0c0cc6b6: /* original e201, guest PC 0x0c0cc6b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b6u; return 0; }
r[2]=0x00000001u;
goto P_0c0cc6b8;
P_0c0cc6b8: /* original 2258, guest PC 0x0c0cc6b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0cc6ba;
P_0c0cc6ba: /* original 8b01, guest PC 0x0c0cc6ba */
if(!s->budget--) { s->failed_pc=0x0c0cc6bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6c0; }
goto P_0c0cc6bc;
P_0c0cc6bc: /* original a122, guest PC 0x0c0cc6bc */
if(!s->budget--) { s->failed_pc=0x0c0cc6bcu; return 0; }
goto P_0c0cc904;
P_0c0cc6be: /* original 0009, guest PC 0x0c0cc6be */
if(!s->budget--) { s->failed_pc=0x0c0cc6beu; return 0; }
goto P_0c0cc6c0;
P_0c0cc6c0: /* original d136, guest PC 0x0c0cc6c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c0u; return 0; }
r[1]=read(ram,0x0c0cc79cu,4);
goto P_0c0cc6c2;
P_0c0cc6c2: /* original 2158, guest PC 0x0c0cc6c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c0cc6c4;
P_0c0cc6c4: /* original 8b01, guest PC 0x0c0cc6c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6ca; }
goto P_0c0cc6c6;
P_0c0cc6c6: /* original a11d, guest PC 0x0c0cc6c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c6u; return 0; }
goto P_0c0cc904;
P_0c0cc6c8: /* original 0009, guest PC 0x0c0cc6c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6c8u; return 0; }
goto P_0c0cc6ca;
P_0c0cc6ca: /* original e202, guest PC 0x0c0cc6ca */
if(!s->budget--) { s->failed_pc=0x0c0cc6cau; return 0; }
r[2]=0x00000002u;
goto P_0c0cc6cc;
P_0c0cc6cc: /* original 2528, guest PC 0x0c0cc6cc */
if(!s->budget--) { s->failed_pc=0x0c0cc6ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0cc6ce;
P_0c0cc6ce: /* original 8901, guest PC 0x0c0cc6ce */
if(!s->budget--) { s->failed_pc=0x0c0cc6ceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc6d4; }
goto P_0c0cc6d0;
P_0c0cc6d0: /* original a118, guest PC 0x0c0cc6d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d0u; return 0; }
goto P_0c0cc904;
P_0c0cc6d2: /* original 0009, guest PC 0x0c0cc6d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d2u; return 0; }
goto P_0c0cc6d4;
P_0c0cc6d4: /* original e01c, guest PC 0x0c0cc6d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc6d6;
P_0c0cc6d6: /* original 05cc, guest PC 0x0c0cc6d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0cc6d8;
P_0c0cc6d8: /* original e30f, guest PC 0x0c0cc6d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6d8u; return 0; }
r[3]=0x0000000fu;
goto P_0c0cc6da;
P_0c0cc6da: /* original 9050, guest PC 0x0c0cc6da */
if(!s->budget--) { s->failed_pc=0x0c0cc6dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc77eu,2);
goto P_0c0cc6dc;
P_0c0cc6dc: /* original 655c, guest PC 0x0c0cc6dc */
if(!s->budget--) { s->failed_pc=0x0c0cc6dcu; return 0; }
r[5]=r[5]&255u;
goto P_0c0cc6de;
P_0c0cc6de: /* original 044c, guest PC 0x0c0cc6de */
if(!s->budget--) { s->failed_pc=0x0c0cc6deu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0cc6e0;
P_0c0cc6e0: /* original 6043, guest PC 0x0c0cc6e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e0u; return 0; }
r[0]=r[4];
goto P_0c0cc6e2;
P_0c0cc6e2: /* original 8817, guest PC 0x0c0cc6e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0cc6e4;
P_0c0cc6e4: /* original 8f02, guest PC 0x0c0cc6e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e4u; return 0; }
cond=r[17]&1u;
r[5]&=r[3];
if(!cond) { goto P_0c0cc6ec; }
goto P_0c0cc6e8;
P_0c0cc6e6: /* original 2539, guest PC 0x0c0cc6e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e6u; return 0; }
r[5]&=r[3];
goto P_0c0cc6e8;
P_0c0cc6e8: /* original a10c, guest PC 0x0c0cc6e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6e8u; return 0; }
goto P_0c0cc904;
P_0c0cc6ea: /* original 0009, guest PC 0x0c0cc6ea */
if(!s->budget--) { s->failed_pc=0x0c0cc6eau; return 0; }
goto P_0c0cc6ec;
P_0c0cc6ec: /* original 6043, guest PC 0x0c0cc6ec */
if(!s->budget--) { s->failed_pc=0x0c0cc6ecu; return 0; }
r[0]=r[4];
goto P_0c0cc6ee;
P_0c0cc6ee: /* original 8807, guest PC 0x0c0cc6ee */
if(!s->budget--) { s->failed_pc=0x0c0cc6eeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0cc6f0;
P_0c0cc6f0: /* original 8b01, guest PC 0x0c0cc6f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc6f6; }
goto P_0c0cc6f2;
P_0c0cc6f2: /* original a107, guest PC 0x0c0cc6f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f2u; return 0; }
goto P_0c0cc904;
P_0c0cc6f4: /* original 0009, guest PC 0x0c0cc6f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f4u; return 0; }
goto P_0c0cc6f6;
P_0c0cc6f6: /* original 6053, guest PC 0x0c0cc6f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f6u; return 0; }
r[0]=r[5];
goto P_0c0cc6f8;
P_0c0cc6f8: /* original 8807, guest PC 0x0c0cc6f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc6f8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0cc6fa;
P_0c0cc6fa: /* original 8b01, guest PC 0x0c0cc6fa */
if(!s->budget--) { s->failed_pc=0x0c0cc6fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc700; }
goto P_0c0cc6fc;
P_0c0cc6fc: /* original a102, guest PC 0x0c0cc6fc */
if(!s->budget--) { s->failed_pc=0x0c0cc6fcu; return 0; }
goto P_0c0cc904;
P_0c0cc6fe: /* original 0009, guest PC 0x0c0cc6fe */
if(!s->budget--) { s->failed_pc=0x0c0cc6feu; return 0; }
goto P_0c0cc700;
P_0c0cc700: /* original 6053, guest PC 0x0c0cc700 */
if(!s->budget--) { s->failed_pc=0x0c0cc700u; return 0; }
r[0]=r[5];
goto P_0c0cc702;
P_0c0cc702: /* original 8806, guest PC 0x0c0cc702 */
if(!s->budget--) { s->failed_pc=0x0c0cc702u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0cc704;
P_0c0cc704: /* original 8b01, guest PC 0x0c0cc704 */
if(!s->budget--) { s->failed_pc=0x0c0cc704u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc70a; }
goto P_0c0cc706;
P_0c0cc706: /* original a0fd, guest PC 0x0c0cc706 */
if(!s->budget--) { s->failed_pc=0x0c0cc706u; return 0; }
goto P_0c0cc904;
P_0c0cc708: /* original 0009, guest PC 0x0c0cc708 */
if(!s->budget--) { s->failed_pc=0x0c0cc708u; return 0; }
goto P_0c0cc70a;
P_0c0cc70a: /* original 6053, guest PC 0x0c0cc70a */
if(!s->budget--) { s->failed_pc=0x0c0cc70au; return 0; }
r[0]=r[5];
goto P_0c0cc70c;
P_0c0cc70c: /* original 880e, guest PC 0x0c0cc70c */
if(!s->budget--) { s->failed_pc=0x0c0cc70cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0cc70e;
P_0c0cc70e: /* original 8b01, guest PC 0x0c0cc70e */
if(!s->budget--) { s->failed_pc=0x0c0cc70eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc714; }
goto P_0c0cc710;
P_0c0cc710: /* original a0f8, guest PC 0x0c0cc710 */
if(!s->budget--) { s->failed_pc=0x0c0cc710u; return 0; }
goto P_0c0cc904;
P_0c0cc712: /* original 0009, guest PC 0x0c0cc712 */
if(!s->budget--) { s->failed_pc=0x0c0cc712u; return 0; }
goto P_0c0cc714;
P_0c0cc714: /* original 63c2, guest PC 0x0c0cc714 */
if(!s->budget--) { s->failed_pc=0x0c0cc714u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0cc716;
P_0c0cc716: /* original 23b8, guest PC 0x0c0cc716 */
if(!s->budget--) { s->failed_pc=0x0c0cc716u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0cc718;
P_0c0cc718: /* original 8906, guest PC 0x0c0cc718 */
if(!s->budget--) { s->failed_pc=0x0c0cc718u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc728; }
goto P_0c0cc71a;
P_0c0cc71a: /* original e061, guest PC 0x0c0cc71a */
if(!s->budget--) { s->failed_pc=0x0c0cc71au; return 0; }
r[0]=0x00000061u;
goto P_0c0cc71c;
P_0c0cc71c: /* original 00ec, guest PC 0x0c0cc71c */
if(!s->budget--) { s->failed_pc=0x0c0cc71cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc71e;
P_0c0cc71e: /* original 600c, guest PC 0x0c0cc71e */
if(!s->budget--) { s->failed_pc=0x0c0cc71eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc720;
P_0c0cc720: /* original 880c, guest PC 0x0c0cc720 */
if(!s->budget--) { s->failed_pc=0x0c0cc720u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0cc722;
P_0c0cc722: /* original 8b01, guest PC 0x0c0cc722 */
if(!s->budget--) { s->failed_pc=0x0c0cc722u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc728; }
goto P_0c0cc724;
P_0c0cc724: /* original a0ee, guest PC 0x0c0cc724 */
if(!s->budget--) { s->failed_pc=0x0c0cc724u; return 0; }
goto P_0c0cc904;
P_0c0cc726: /* original 0009, guest PC 0x0c0cc726 */
if(!s->budget--) { s->failed_pc=0x0c0cc726u; return 0; }
goto P_0c0cc728;
P_0c0cc728: /* original 902a, guest PC 0x0c0cc728 */
if(!s->budget--) { s->failed_pc=0x0c0cc728u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc780u,2);
goto P_0c0cc72a;
P_0c0cc72a: /* original 026c, guest PC 0x0c0cc72a */
if(!s->budget--) { s->failed_pc=0x0c0cc72au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0cc72c;
P_0c0cc72c: /* original 2228, guest PC 0x0c0cc72c */
if(!s->budget--) { s->failed_pc=0x0c0cc72cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0cc72e;
P_0c0cc72e: /* original 8903, guest PC 0x0c0cc72e */
if(!s->budget--) { s->failed_pc=0x0c0cc72eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc738; }
goto P_0c0cc730;
P_0c0cc730: /* original 036c, guest PC 0x0c0cc730 */
if(!s->budget--) { s->failed_pc=0x0c0cc730u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0cc732;
P_0c0cc732: /* original 73ff, guest PC 0x0c0cc732 */
if(!s->budget--) { s->failed_pc=0x0c0cc732u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0cc734;
P_0c0cc734: /* original a0e6, guest PC 0x0c0cc734 */
if(!s->budget--) { s->failed_pc=0x0c0cc734u; return 0; }
write(ram,r[6]+r[0],r[3],1);
goto P_0c0cc904;
P_0c0cc736: /* original 0634, guest PC 0x0c0cc736 */
if(!s->budget--) { s->failed_pc=0x0c0cc736u; return 0; }
write(ram,r[6]+r[0],r[3],1);
goto P_0c0cc738;
P_0c0cc738: /* original d219, guest PC 0x0c0cc738 */
if(!s->budget--) { s->failed_pc=0x0c0cc738u; return 0; }
r[2]=read(ram,0x0c0cc7a0u,4);
goto P_0c0cc73a;
P_0c0cc73a: /* original 420b, guest PC 0x0c0cc73a */
if(!s->budget--) { s->failed_pc=0x0c0cc73au; return 0; }
target=r[2];
r[16]=code_base|0x0c0cc73eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc73eu) { target=s->pc; goto dispatch; }
goto P_0c0cc73e;
P_0c0cc73c: /* original e400, guest PC 0x0c0cc73c */
if(!s->budget--) { s->failed_pc=0x0c0cc73cu; return 0; }
r[4]=0x00000000u;
goto P_0c0cc73e;
P_0c0cc73e: /* original 63c2, guest PC 0x0c0cc73e */
if(!s->budget--) { s->failed_pc=0x0c0cc73eu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0cc740;
P_0c0cc740: /* original d518, guest PC 0x0c0cc740 */
if(!s->budget--) { s->failed_pc=0x0c0cc740u; return 0; }
r[5]=read(ram,0x0c0cc7a4u,4);
goto P_0c0cc742;
P_0c0cc742: /* original 2b38, guest PC 0x0c0cc742 */
if(!s->budget--) { s->failed_pc=0x0c0cc742u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[3])==0)!=0);
goto P_0c0cc744;
P_0c0cc744: /* original 8d0c, guest PC 0x0c0cc744 */
if(!s->budget--) { s->failed_pc=0x0c0cc744u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0cc760; }
goto P_0c0cc748;
P_0c0cc746: /* original ed00, guest PC 0x0c0cc746 */
if(!s->budget--) { s->failed_pc=0x0c0cc746u; return 0; }
r[13]=0x00000000u;
goto P_0c0cc748;
P_0c0cc748: /* original c717, guest PC 0x0c0cc748 */
if(!s->budget--) { s->failed_pc=0x0c0cc748u; return 0; }
r[0]=code_base|0x000cc7a8u;
goto P_0c0cc74a;
P_0c0cc74a: /* original d318, guest PC 0x0c0cc74a */
if(!s->budget--) { s->failed_pc=0x0c0cc74au; return 0; }
r[3]=read(ram,0x0c0cc7acu,4);
goto P_0c0cc74c;
P_0c0cc74c: /* original ff08, guest PC 0x0c0cc74c */
if(!s->budget--) { s->failed_pc=0x0c0cc74cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0cc74e;
P_0c0cc74e: /* original e048, guest PC 0x0c0cc74e */
if(!s->budget--) { s->failed_pc=0x0c0cc74eu; return 0; }
r[0]=0x00000048u;
goto P_0c0cc750;
P_0c0cc750: /* original 02ee, guest PC 0x0c0cc750 */
if(!s->budget--) { s->failed_pc=0x0c0cc750u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cc752;
P_0c0cc752: /* original 2238, guest PC 0x0c0cc752 */
if(!s->budget--) { s->failed_pc=0x0c0cc752u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc754;
P_0c0cc754: /* original 8901, guest PC 0x0c0cc754 */
if(!s->budget--) { s->failed_pc=0x0c0cc754u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc75a; }
goto P_0c0cc756;
P_0c0cc756: /* original a09c, guest PC 0x0c0cc756 */
if(!s->budget--) { s->failed_pc=0x0c0cc756u; return 0; }
goto P_0c0cc892;
P_0c0cc758: /* original 0009, guest PC 0x0c0cc758 */
if(!s->budget--) { s->failed_pc=0x0c0cc758u; return 0; }
goto P_0c0cc75a;
P_0c0cc75a: /* original 9012, guest PC 0x0c0cc75a */
if(!s->budget--) { s->failed_pc=0x0c0cc75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc782u,2);
goto P_0c0cc75c;
P_0c0cc75c: /* original a03b, guest PC 0x0c0cc75c */
if(!s->budget--) { s->failed_pc=0x0c0cc75cu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0cc7d6;
P_0c0cc75e: /* original 045e, guest PC 0x0c0cc75e */
if(!s->budget--) { s->failed_pc=0x0c0cc75eu; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0cc760;
P_0c0cc760: /* original e04c, guest PC 0x0c0cc760 */
if(!s->budget--) { s->failed_pc=0x0c0cc760u; return 0; }
r[0]=0x0000004cu;
goto P_0c0cc762;
P_0c0cc762: /* original 00ee, guest PC 0x0c0cc762 */
if(!s->budget--) { s->failed_pc=0x0c0cc762u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0cc764;
P_0c0cc764: /* original c880, guest PC 0x0c0cc764 */
if(!s->budget--) { s->failed_pc=0x0c0cc764u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0cc766;
P_0c0cc766: /* original 8b01, guest PC 0x0c0cc766 */
if(!s->budget--) { s->failed_pc=0x0c0cc766u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc76c; }
goto P_0c0cc768;
P_0c0cc768: /* original a093, guest PC 0x0c0cc768 */
if(!s->budget--) { s->failed_pc=0x0c0cc768u; return 0; }
goto P_0c0cc892;
P_0c0cc76a: /* original 0009, guest PC 0x0c0cc76a */
if(!s->budget--) { s->failed_pc=0x0c0cc76au; return 0; }
goto P_0c0cc76c;
P_0c0cc76c: /* original 900a, guest PC 0x0c0cc76c */
if(!s->budget--) { s->failed_pc=0x0c0cc76cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc784u,2);
goto P_0c0cc76e;
P_0c0cc76e: /* original d310, guest PC 0x0c0cc76e */
if(!s->budget--) { s->failed_pc=0x0c0cc76eu; return 0; }
r[3]=read(ram,0x0c0cc7b0u,4);
goto P_0c0cc770;
P_0c0cc770: /* original 02ee, guest PC 0x0c0cc770 */
if(!s->budget--) { s->failed_pc=0x0c0cc770u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cc772;
P_0c0cc772: /* original 2238, guest PC 0x0c0cc772 */
if(!s->budget--) { s->failed_pc=0x0c0cc772u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cc774;
P_0c0cc774: /* original 891e, guest PC 0x0c0cc774 */
if(!s->budget--) { s->failed_pc=0x0c0cc774u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7b4; }
goto P_0c0cc776;
P_0c0cc776: /* original 9006, guest PC 0x0c0cc776 */
if(!s->budget--) { s->failed_pc=0x0c0cc776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc786u,2);
goto P_0c0cc778;
P_0c0cc778: /* original 04ec, guest PC 0x0c0cc778 */
if(!s->budget--) { s->failed_pc=0x0c0cc778u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc77a;
P_0c0cc77a: /* original a020, guest PC 0x0c0cc77a */
if(!s->budget--) { s->failed_pc=0x0c0cc77au; return 0; }
r[4]=r[4]&255u;
goto P_0c0cc7be;
P_0c0cc77c: /* original 644c, guest PC 0x0c0cc77c */
if(!s->budget--) { s->failed_pc=0x0c0cc77cu; return 0; }
r[4]=r[4]&255u;
if(!vf3_matrix_family(0x0c0cc77eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc77eu; return 0; } return 1;
P_0c0cc7b4: /* original 9072, guest PC 0x0c0cc7b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc89cu,2);
goto P_0c0cc7b6;
P_0c0cc7b6: /* original 04ec, guest PC 0x0c0cc7b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7b6u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc7b8;
P_0c0cc7b8: /* original 644c, guest PC 0x0c0cc7b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7b8u; return 0; }
r[4]=r[4]&255u;
goto P_0c0cc7ba;
P_0c0cc7ba: /* original 2448, guest PC 0x0c0cc7ba */
if(!s->budget--) { s->failed_pc=0x0c0cc7bau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0cc7bc;
P_0c0cc7bc: /* original 8969, guest PC 0x0c0cc7bc */
if(!s->budget--) { s->failed_pc=0x0c0cc7bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc892; }
goto P_0c0cc7be;
P_0c0cc7be: /* original 6043, guest PC 0x0c0cc7be */
if(!s->budget--) { s->failed_pc=0x0c0cc7beu; return 0; }
r[0]=r[4];
goto P_0c0cc7c0;
P_0c0cc7c0: /* original 4008, guest PC 0x0c0cc7c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c0u; return 0; }
r[0]<<=2;
goto P_0c0cc7c2;
P_0c0cc7c2: /* original d339, guest PC 0x0c0cc7c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c2u; return 0; }
r[3]=read(ram,0x0c0cc8a8u,4);
goto P_0c0cc7c4;
P_0c0cc7c4: /* original 045e, guest PC 0x0c0cc7c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c4u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c0cc7c6;
P_0c0cc7c6: /* original 2348, guest PC 0x0c0cc7c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7c8;
P_0c0cc7c8: /* original 8900, guest PC 0x0c0cc7c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7cc; }
goto P_0c0cc7ca;
P_0c0cc7ca: /* original dd38, guest PC 0x0c0cc7ca */
if(!s->budget--) { s->failed_pc=0x0c0cc7cau; return 0; }
r[13]=read(ram,0x0c0cc8acu,4);
goto P_0c0cc7cc;
P_0c0cc7cc: /* original d338, guest PC 0x0c0cc7cc */
if(!s->budget--) { s->failed_pc=0x0c0cc7ccu; return 0; }
r[3]=read(ram,0x0c0cc8b0u,4);
goto P_0c0cc7ce;
P_0c0cc7ce: /* original 2348, guest PC 0x0c0cc7ce */
if(!s->budget--) { s->failed_pc=0x0c0cc7ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7d0;
P_0c0cc7d0: /* original 8901, guest PC 0x0c0cc7d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7d6; }
goto P_0c0cc7d2;
P_0c0cc7d2: /* original d138, guest PC 0x0c0cc7d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d2u; return 0; }
r[1]=read(ram,0x0c0cc8b4u,4);
goto P_0c0cc7d4;
P_0c0cc7d4: /* original 2d1b, guest PC 0x0c0cc7d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d4u; return 0; }
r[13]|=r[1];
goto P_0c0cc7d6;
P_0c0cc7d6: /* original d338, guest PC 0x0c0cc7d6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d6u; return 0; }
r[3]=read(ram,0x0c0cc8b8u,4);
goto P_0c0cc7d8;
P_0c0cc7d8: /* original 2348, guest PC 0x0c0cc7d8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7da;
P_0c0cc7da: /* original 8901, guest PC 0x0c0cc7da */
if(!s->budget--) { s->failed_pc=0x0c0cc7dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7e0; }
goto P_0c0cc7dc;
P_0c0cc7dc: /* original d137, guest PC 0x0c0cc7dc */
if(!s->budget--) { s->failed_pc=0x0c0cc7dcu; return 0; }
r[1]=read(ram,0x0c0cc8bcu,4);
goto P_0c0cc7de;
P_0c0cc7de: /* original 2d1b, guest PC 0x0c0cc7de */
if(!s->budget--) { s->failed_pc=0x0c0cc7deu; return 0; }
r[13]|=r[1];
goto P_0c0cc7e0;
P_0c0cc7e0: /* original d337, guest PC 0x0c0cc7e0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e0u; return 0; }
r[3]=read(ram,0x0c0cc8c0u,4);
goto P_0c0cc7e2;
P_0c0cc7e2: /* original 2348, guest PC 0x0c0cc7e2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7e4;
P_0c0cc7e4: /* original 8901, guest PC 0x0c0cc7e4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7ea; }
goto P_0c0cc7e6;
P_0c0cc7e6: /* original d137, guest PC 0x0c0cc7e6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e6u; return 0; }
r[1]=read(ram,0x0c0cc8c4u,4);
goto P_0c0cc7e8;
P_0c0cc7e8: /* original 2d1b, guest PC 0x0c0cc7e8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7e8u; return 0; }
r[13]|=r[1];
goto P_0c0cc7ea;
P_0c0cc7ea: /* original d337, guest PC 0x0c0cc7ea */
if(!s->budget--) { s->failed_pc=0x0c0cc7eau; return 0; }
r[3]=read(ram,0x0c0cc8c8u,4);
goto P_0c0cc7ec;
P_0c0cc7ec: /* original 2348, guest PC 0x0c0cc7ec */
if(!s->budget--) { s->failed_pc=0x0c0cc7ecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c0cc7ee;
P_0c0cc7ee: /* original 8901, guest PC 0x0c0cc7ee */
if(!s->budget--) { s->failed_pc=0x0c0cc7eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc7f4; }
goto P_0c0cc7f0;
P_0c0cc7f0: /* original d136, guest PC 0x0c0cc7f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f0u; return 0; }
r[1]=read(ram,0x0c0cc8ccu,4);
goto P_0c0cc7f2;
P_0c0cc7f2: /* original 2d1b, guest PC 0x0c0cc7f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f2u; return 0; }
r[13]|=r[1];
goto P_0c0cc7f4;
P_0c0cc7f4: /* original 9353, guest PC 0x0c0cc7f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc89eu,2);
goto P_0c0cc7f6;
P_0c0cc7f6: /* original 2438, guest PC 0x0c0cc7f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0cc7f8;
P_0c0cc7f8: /* original 8d02, guest PC 0x0c0cc7f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc7f8u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
if(cond) { goto P_0c0cc800; }
goto P_0c0cc7fc;
P_0c0cc7fa: /* original 84e4, guest PC 0x0c0cc7fa */
if(!s->budget--) { s->failed_pc=0x0c0cc7fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0cc7fc;
P_0c0cc7fc: /* original d134, guest PC 0x0c0cc7fc */
if(!s->budget--) { s->failed_pc=0x0c0cc7fcu; return 0; }
r[1]=read(ram,0x0c0cc8d0u,4);
goto P_0c0cc7fe;
P_0c0cc7fe: /* original 2d1b, guest PC 0x0c0cc7fe */
if(!s->budget--) { s->failed_pc=0x0c0cc7feu; return 0; }
r[13]|=r[1];
goto P_0c0cc800;
P_0c0cc800: /* original 600c, guest PC 0x0c0cc800 */
if(!s->budget--) { s->failed_pc=0x0c0cc800u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc802;
P_0c0cc802: /* original 924e, guest PC 0x0c0cc802 */
if(!s->budget--) { s->failed_pc=0x0c0cc802u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc8a2u,2);
goto P_0c0cc804;
P_0c0cc804: /* original 6303, guest PC 0x0c0cc804 */
if(!s->budget--) { s->failed_pc=0x0c0cc804u; return 0; }
r[3]=r[0];
goto P_0c0cc806;
P_0c0cc806: /* original 4008, guest PC 0x0c0cc806 */
if(!s->budget--) { s->failed_pc=0x0c0cc806u; return 0; }
r[0]<<=2;
goto P_0c0cc808;
P_0c0cc808: /* original 4008, guest PC 0x0c0cc808 */
if(!s->budget--) { s->failed_pc=0x0c0cc808u; return 0; }
r[0]<<=2;
goto P_0c0cc80a;
P_0c0cc80a: /* original 9849, guest PC 0x0c0cc80a */
if(!s->budget--) { s->failed_pc=0x0c0cc80au; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc8a0u,2);
goto P_0c0cc80c;
P_0c0cc80c: /* original 4000, guest PC 0x0c0cc80c */
if(!s->budget--) { s->failed_pc=0x0c0cc80cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0cc80e;
P_0c0cc80e: /* original 303c, guest PC 0x0c0cc80e */
if(!s->budget--) { s->failed_pc=0x0c0cc80eu; return 0; }
r[0]+=r[3];
goto P_0c0cc810;
P_0c0cc810: /* original d330, guest PC 0x0c0cc810 */
if(!s->budget--) { s->failed_pc=0x0c0cc810u; return 0; }
r[3]=read(ram,0x0c0cc8d4u,4);
goto P_0c0cc812;
P_0c0cc812: /* original 4008, guest PC 0x0c0cc812 */
if(!s->budget--) { s->failed_pc=0x0c0cc812u; return 0; }
r[0]<<=2;
goto P_0c0cc814;
P_0c0cc814: /* original 4008, guest PC 0x0c0cc814 */
if(!s->budget--) { s->failed_pc=0x0c0cc814u; return 0; }
r[0]<<=2;
goto P_0c0cc816;
P_0c0cc816: /* original 4008, guest PC 0x0c0cc816 */
if(!s->budget--) { s->failed_pc=0x0c0cc816u; return 0; }
r[0]<<=2;
goto P_0c0cc818;
P_0c0cc818: /* original 6a0f, guest PC 0x0c0cc818 */
if(!s->budget--) { s->failed_pc=0x0c0cc818u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0cc81a;
P_0c0cc81a: /* original e061, guest PC 0x0c0cc81a */
if(!s->budget--) { s->failed_pc=0x0c0cc81au; return 0; }
r[0]=0x00000061u;
goto P_0c0cc81c;
P_0c0cc81c: /* original 00ec, guest PC 0x0c0cc81c */
if(!s->budget--) { s->failed_pc=0x0c0cc81cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc81e;
P_0c0cc81e: /* original 3a3c, guest PC 0x0c0cc81e */
if(!s->budget--) { s->failed_pc=0x0c0cc81eu; return 0; }
r[10]+=r[3];
goto P_0c0cc820;
P_0c0cc820: /* original 3a2c, guest PC 0x0c0cc820 */
if(!s->budget--) { s->failed_pc=0x0c0cc820u; return 0; }
r[10]+=r[2];
goto P_0c0cc822;
P_0c0cc822: /* original 600c, guest PC 0x0c0cc822 */
if(!s->budget--) { s->failed_pc=0x0c0cc822u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc824;
P_0c0cc824: /* original 880c, guest PC 0x0c0cc824 */
if(!s->budget--) { s->failed_pc=0x0c0cc824u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0cc826;
P_0c0cc826: /* original 38ec, guest PC 0x0c0cc826 */
if(!s->budget--) { s->failed_pc=0x0c0cc826u; return 0; }
r[8]+=r[14];
goto P_0c0cc828;
P_0c0cc828: /* original 8f01, guest PC 0x0c0cc828 */
if(!s->budget--) { s->failed_pc=0x0c0cc828u; return 0; }
cond=r[17]&1u;
r[11]=0x00000004u;
if(!cond) { goto P_0c0cc82e; }
goto P_0c0cc82c;
P_0c0cc82a: /* original eb04, guest PC 0x0c0cc82a */
if(!s->budget--) { s->failed_pc=0x0c0cc82au; return 0; }
r[11]=0x00000004u;
goto P_0c0cc82c;
P_0c0cc82c: /* original eb02, guest PC 0x0c0cc82c */
if(!s->budget--) { s->failed_pc=0x0c0cc82cu; return 0; }
r[11]=0x00000002u;
goto P_0c0cc82e;
P_0c0cc82e: /* original e061, guest PC 0x0c0cc82e */
if(!s->budget--) { s->failed_pc=0x0c0cc82eu; return 0; }
r[0]=0x00000061u;
goto P_0c0cc830;
P_0c0cc830: /* original 00ec, guest PC 0x0c0cc830 */
if(!s->budget--) { s->failed_pc=0x0c0cc830u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0cc832;
P_0c0cc832: /* original 600c, guest PC 0x0c0cc832 */
if(!s->budget--) { s->failed_pc=0x0c0cc832u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc834;
P_0c0cc834: /* original 8809, guest PC 0x0c0cc834 */
if(!s->budget--) { s->failed_pc=0x0c0cc834u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cc836;
P_0c0cc836: /* original 8b07, guest PC 0x0c0cc836 */
if(!s->budget--) { s->failed_pc=0x0c0cc836u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc848; }
goto P_0c0cc838;
P_0c0cc838: /* original 84e4, guest PC 0x0c0cc838 */
if(!s->budget--) { s->failed_pc=0x0c0cc838u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0cc83a;
P_0c0cc83a: /* original 9333, guest PC 0x0c0cc83a */
if(!s->budget--) { s->failed_pc=0x0c0cc83au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cc8a4u,2);
goto P_0c0cc83c;
P_0c0cc83c: /* original 600c, guest PC 0x0c0cc83c */
if(!s->budget--) { s->failed_pc=0x0c0cc83cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0cc83e;
P_0c0cc83e: /* original 33cc, guest PC 0x0c0cc83e */
if(!s->budget--) { s->failed_pc=0x0c0cc83eu; return 0; }
r[3]+=r[12];
goto P_0c0cc840;
P_0c0cc840: /* original 4008, guest PC 0x0c0cc840 */
if(!s->budget--) { s->failed_pc=0x0c0cc840u; return 0; }
r[0]<<=2;
goto P_0c0cc842;
P_0c0cc842: /* original 303c, guest PC 0x0c0cc842 */
if(!s->budget--) { s->failed_pc=0x0c0cc842u; return 0; }
r[0]+=r[3];
goto P_0c0cc844;
P_0c0cc844: /* original f308, guest PC 0x0c0cc844 */
if(!s->budget--) { s->failed_pc=0x0c0cc844u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc846;
P_0c0cc846: /* original ff32, guest PC 0x0c0cc846 */
if(!s->budget--) { s->failed_pc=0x0c0cc846u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0cc848;
P_0c0cc848: /* original 6986, guest PC 0x0c0cc848 */
if(!s->budget--) { s->failed_pc=0x0c0cc848u; return 0; }
tmp=read(ram,r[8],4);
r[8]+=4;
r[9]=tmp;
goto P_0c0cc84a;
P_0c0cc84a: /* original ee08, guest PC 0x0c0cc84a */
if(!s->budget--) { s->failed_pc=0x0c0cc84au; return 0; }
r[14]=0x00000008u;
goto P_0c0cc84c;
P_0c0cc84c: /* original e308, guest PC 0x0c0cc84c */
if(!s->budget--) { s->failed_pc=0x0c0cc84cu; return 0; }
r[3]=0x00000008u;
goto P_0c0cc84e;
P_0c0cc84e: /* original d022, guest PC 0x0c0cc84e */
if(!s->budget--) { s->failed_pc=0x0c0cc84eu; return 0; }
r[0]=read(ram,0x0c0cc8d8u,4);
goto P_0c0cc850;
P_0c0cc850: /* original 33e8, guest PC 0x0c0cc850 */
if(!s->budget--) { s->failed_pc=0x0c0cc850u; return 0; }
r[3]-=r[14];
goto P_0c0cc852;
P_0c0cc852: /* original 4308, guest PC 0x0c0cc852 */
if(!s->budget--) { s->failed_pc=0x0c0cc852u; return 0; }
r[3]<<=2;
goto P_0c0cc854;
P_0c0cc854: /* original 023e, guest PC 0x0c0cc854 */
if(!s->budget--) { s->failed_pc=0x0c0cc854u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0cc856;
P_0c0cc856: /* original 22d8, guest PC 0x0c0cc856 */
if(!s->budget--) { s->failed_pc=0x0c0cc856u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0cc858;
P_0c0cc858: /* original 8912, guest PC 0x0c0cc858 */
if(!s->budget--) { s->failed_pc=0x0c0cc858u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc880; }
goto P_0c0cc85a;
P_0c0cc85a: /* original 64a1, guest PC 0x0c0cc85a */
if(!s->budget--) { s->failed_pc=0x0c0cc85au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[10],2);
r[4]=tmp;
goto P_0c0cc85c;
P_0c0cc85c: /* original 6c4f, guest PC 0x0c0cc85c */
if(!s->budget--) { s->failed_pc=0x0c0cc85cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0cc85e;
P_0c0cc85e: /* original 60c3, guest PC 0x0c0cc85e */
if(!s->budget--) { s->failed_pc=0x0c0cc85eu; return 0; }
r[0]=r[12];
goto P_0c0cc860;
P_0c0cc860: /* original 88ff, guest PC 0x0c0cc860 */
if(!s->budget--) { s->failed_pc=0x0c0cc860u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0cc862;
P_0c0cc862: /* original 890d, guest PC 0x0c0cc862 */
if(!s->budget--) { s->failed_pc=0x0c0cc862u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc880; }
goto P_0c0cc864;
P_0c0cc864: /* original d31d, guest PC 0x0c0cc864 */
if(!s->budget--) { s->failed_pc=0x0c0cc864u; return 0; }
r[3]=read(ram,0x0c0cc8dcu,4);
goto P_0c0cc866;
P_0c0cc866: /* original 430b, guest PC 0x0c0cc866 */
if(!s->budget--) { s->failed_pc=0x0c0cc866u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cc86au;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc86au) { target=s->pc; goto dispatch; }
goto P_0c0cc86a;
P_0c0cc868: /* original 6493, guest PC 0x0c0cc868 */
if(!s->budget--) { s->failed_pc=0x0c0cc868u; return 0; }
r[4]=r[9];
goto P_0c0cc86a;
P_0c0cc86a: /* original e205, guest PC 0x0c0cc86a */
if(!s->budget--) { s->failed_pc=0x0c0cc86au; return 0; }
r[2]=0x00000005u;
goto P_0c0cc86c;
P_0c0cc86c: /* original 3e23, guest PC 0x0c0cc86c */
if(!s->budget--) { s->failed_pc=0x0c0cc86cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[2])!=0);
goto P_0c0cc86e;
P_0c0cc86e: /* original 8903, guest PC 0x0c0cc86e */
if(!s->budget--) { s->failed_pc=0x0c0cc86eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc878; }
goto P_0c0cc870;
P_0c0cc870: /* original d11c, guest PC 0x0c0cc870 */
if(!s->budget--) { s->failed_pc=0x0c0cc870u; return 0; }
r[1]=read(ram,0x0c0cc8e4u,4);
goto P_0c0cc872;
P_0c0cc872: /* original d41b, guest PC 0x0c0cc872 */
if(!s->budget--) { s->failed_pc=0x0c0cc872u; return 0; }
r[4]=read(ram,0x0c0cc8e0u,4);
goto P_0c0cc874;
P_0c0cc874: /* original 410b, guest PC 0x0c0cc874 */
if(!s->budget--) { s->failed_pc=0x0c0cc874u; return 0; }
target=r[1];
r[16]=code_base|0x0c0cc878u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc878u) { target=s->pc; goto dispatch; }
goto P_0c0cc878;
P_0c0cc876: /* original 0009, guest PC 0x0c0cc876 */
if(!s->budget--) { s->failed_pc=0x0c0cc876u; return 0; }
goto P_0c0cc878;
P_0c0cc878: /* original d31b, guest PC 0x0c0cc878 */
if(!s->budget--) { s->failed_pc=0x0c0cc878u; return 0; }
r[3]=read(ram,0x0c0cc8e8u,4);
goto P_0c0cc87a;
P_0c0cc87a: /* original f4fc, guest PC 0x0c0cc87a */
if(!s->budget--) { s->failed_pc=0x0c0cc87au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cc87c;
P_0c0cc87c: /* original 430b, guest PC 0x0c0cc87c */
if(!s->budget--) { s->failed_pc=0x0c0cc87cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0cc880u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cc880u) { target=s->pc; goto dispatch; }
goto P_0c0cc880;
P_0c0cc87e: /* original 64c3, guest PC 0x0c0cc87e */
if(!s->budget--) { s->failed_pc=0x0c0cc87eu; return 0; }
r[4]=r[12];
goto P_0c0cc880;
P_0c0cc880: /* original 4e10, guest PC 0x0c0cc880 */
if(!s->budget--) { s->failed_pc=0x0c0cc880u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c0cc882;
P_0c0cc882: /* original 7940, guest PC 0x0c0cc882 */
if(!s->budget--) { s->failed_pc=0x0c0cc882u; return 0; }
r[9]+=0x00000040u;
goto P_0c0cc884;
P_0c0cc884: /* original 8fe2, guest PC 0x0c0cc884 */
if(!s->budget--) { s->failed_pc=0x0c0cc884u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000002u;
if(!cond) { goto P_0c0cc84c; }
goto P_0c0cc888;
P_0c0cc886: /* original 7a02, guest PC 0x0c0cc886 */
if(!s->budget--) { s->failed_pc=0x0c0cc886u; return 0; }
r[10]+=0x00000002u;
goto P_0c0cc888;
P_0c0cc888: /* original c718, guest PC 0x0c0cc888 */
if(!s->budget--) { s->failed_pc=0x0c0cc888u; return 0; }
r[0]=code_base|0x000cc8ecu;
goto P_0c0cc88a;
P_0c0cc88a: /* original f308, guest PC 0x0c0cc88a */
if(!s->budget--) { s->failed_pc=0x0c0cc88au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cc88c;
P_0c0cc88c: /* original 4b10, guest PC 0x0c0cc88c */
if(!s->budget--) { s->failed_pc=0x0c0cc88cu; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0cc88e;
P_0c0cc88e: /* original 8fdb, guest PC 0x0c0cc88e */
if(!s->budget--) { s->failed_pc=0x0c0cc88eu; return 0; }
cond=r[17]&1u;
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
if(!cond) { goto P_0c0cc848; }
goto P_0c0cc892;
P_0c0cc890: /* original ff32, guest PC 0x0c0cc890 */
if(!s->budget--) { s->failed_pc=0x0c0cc890u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c0cc892;
P_0c0cc892: /* original 7f04, guest PC 0x0c0cc892 */
if(!s->budget--) { s->failed_pc=0x0c0cc892u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc894;
P_0c0cc894: /* original 4f26, guest PC 0x0c0cc894 */
if(!s->budget--) { s->failed_pc=0x0c0cc894u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc896;
P_0c0cc896: /* original e401, guest PC 0x0c0cc896 */
if(!s->budget--) { s->failed_pc=0x0c0cc896u; return 0; }
r[4]=0x00000001u;
goto P_0c0cc898;
P_0c0cc898: /* original a02a, guest PC 0x0c0cc898 */
if(!s->budget--) { s->failed_pc=0x0c0cc898u; return 0; }
goto P_0c0cc8f0;
P_0c0cc89a: /* original 0009, guest PC 0x0c0cc89a */
if(!s->budget--) { s->failed_pc=0x0c0cc89au; return 0; }
if(!vf3_matrix_family(0x0c0cc89cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc89cu; return 0; } return 1;
P_0c0cc8f0: /* original fff9, guest PC 0x0c0cc8f0 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc8f2;
P_0c0cc8f2: /* original d30a, guest PC 0x0c0cc8f2 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f2u; return 0; }
r[3]=read(ram,0x0c0cc91cu,4);
goto P_0c0cc8f4;
P_0c0cc8f4: /* original 68f6, guest PC 0x0c0cc8f4 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cc8f6;
P_0c0cc8f6: /* original 69f6, guest PC 0x0c0cc8f6 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc8f8;
P_0c0cc8f8: /* original 6af6, guest PC 0x0c0cc8f8 */
if(!s->budget--) { s->failed_pc=0x0c0cc8f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc8fa;
P_0c0cc8fa: /* original 6bf6, guest PC 0x0c0cc8fa */
if(!s->budget--) { s->failed_pc=0x0c0cc8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc8fc;
P_0c0cc8fc: /* original 6cf6, guest PC 0x0c0cc8fc */
if(!s->budget--) { s->failed_pc=0x0c0cc8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc8fe;
P_0c0cc8fe: /* original 6df6, guest PC 0x0c0cc8fe */
if(!s->budget--) { s->failed_pc=0x0c0cc8feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc900;
P_0c0cc900: /* original 432b, guest PC 0x0c0cc900 */
if(!s->budget--) { s->failed_pc=0x0c0cc900u; return 0; }
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
P_0c0cc902: /* original 6ef6, guest PC 0x0c0cc902 */
if(!s->budget--) { s->failed_pc=0x0c0cc902u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cc904;
P_0c0cc904: /* original 7f04, guest PC 0x0c0cc904 */
if(!s->budget--) { s->failed_pc=0x0c0cc904u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cc906;
P_0c0cc906: /* original 4f26, guest PC 0x0c0cc906 */
if(!s->budget--) { s->failed_pc=0x0c0cc906u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc908;
P_0c0cc908: /* original fff9, guest PC 0x0c0cc908 */
if(!s->budget--) { s->failed_pc=0x0c0cc908u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cc90a;
P_0c0cc90a: /* original 68f6, guest PC 0x0c0cc90a */
if(!s->budget--) { s->failed_pc=0x0c0cc90au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cc90c;
P_0c0cc90c: /* original 69f6, guest PC 0x0c0cc90c */
if(!s->budget--) { s->failed_pc=0x0c0cc90cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cc90e;
P_0c0cc90e: /* original 6af6, guest PC 0x0c0cc90e */
if(!s->budget--) { s->failed_pc=0x0c0cc90eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cc910;
P_0c0cc910: /* original 6bf6, guest PC 0x0c0cc910 */
if(!s->budget--) { s->failed_pc=0x0c0cc910u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cc912;
P_0c0cc912: /* original 6cf6, guest PC 0x0c0cc912 */
if(!s->budget--) { s->failed_pc=0x0c0cc912u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cc914;
P_0c0cc914: /* original 6df6, guest PC 0x0c0cc914 */
if(!s->budget--) { s->failed_pc=0x0c0cc914u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cc916;
P_0c0cc916: /* original 000b, guest PC 0x0c0cc916 */
if(!s->budget--) { s->failed_pc=0x0c0cc916u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc918: /* original 6ef6, guest PC 0x0c0cc918 */
if(!s->budget--) { s->failed_pc=0x0c0cc918u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0cc91au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cc91au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
