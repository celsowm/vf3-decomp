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
int vf3_away_batch85_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0ad5a0u: goto P_0c0ad5a0;
case 0x0c0ad5a2u: goto P_0c0ad5a2;
case 0x0c0ad5a4u: goto P_0c0ad5a4;
case 0x0c0ad5a6u: goto P_0c0ad5a6;
case 0x0c0ad5a8u: goto P_0c0ad5a8;
case 0x0c0ad5aau: goto P_0c0ad5aa;
case 0x0c0ad5acu: goto P_0c0ad5ac;
case 0x0c0ad5aeu: goto P_0c0ad5ae;
case 0x0c0ad5b0u: goto P_0c0ad5b0;
case 0x0c0ad5b2u: goto P_0c0ad5b2;
case 0x0c0ad5b4u: goto P_0c0ad5b4;
case 0x0c0ad5b6u: goto P_0c0ad5b6;
case 0x0c0ad5b8u: goto P_0c0ad5b8;
case 0x0c0ad5bau: goto P_0c0ad5ba;
case 0x0c0ad5bcu: goto P_0c0ad5bc;
case 0x0c0ad5beu: goto P_0c0ad5be;
case 0x0c0ad5c0u: goto P_0c0ad5c0;
case 0x0c0ad5c2u: goto P_0c0ad5c2;
case 0x0c0ad5c4u: goto P_0c0ad5c4;
case 0x0c0ad5c6u: goto P_0c0ad5c6;
case 0x0c0ad5c8u: goto P_0c0ad5c8;
case 0x0c0ad5cau: goto P_0c0ad5ca;
case 0x0c0ad5ccu: goto P_0c0ad5cc;
case 0x0c0ad5ceu: goto P_0c0ad5ce;
case 0x0c0ad5d0u: goto P_0c0ad5d0;
case 0x0c0ad5d2u: goto P_0c0ad5d2;
case 0x0c0ad5d4u: goto P_0c0ad5d4;
case 0x0c0ad5d6u: goto P_0c0ad5d6;
case 0x0c0ad5d8u: goto P_0c0ad5d8;
case 0x0c0ad5dau: goto P_0c0ad5da;
case 0x0c0ad5dcu: goto P_0c0ad5dc;
case 0x0c0ad5deu: goto P_0c0ad5de;
case 0x0c0ad5e0u: goto P_0c0ad5e0;
case 0x0c0ad5e2u: goto P_0c0ad5e2;
case 0x0c0ad5e4u: goto P_0c0ad5e4;
case 0x0c0ad5e6u: goto P_0c0ad5e6;
case 0x0c0ad5e8u: goto P_0c0ad5e8;
case 0x0c0ad5eau: goto P_0c0ad5ea;
case 0x0c0ad5ecu: goto P_0c0ad5ec;
case 0x0c0ad5eeu: goto P_0c0ad5ee;
case 0x0c0ad5f0u: goto P_0c0ad5f0;
case 0x0c0ad5f2u: goto P_0c0ad5f2;
case 0x0c0ad5f4u: goto P_0c0ad5f4;
case 0x0c0ad5f6u: goto P_0c0ad5f6;
case 0x0c0ad5f8u: goto P_0c0ad5f8;
case 0x0c0ad5fau: goto P_0c0ad5fa;
case 0x0c0ad5fcu: goto P_0c0ad5fc;
case 0x0c0ad5feu: goto P_0c0ad5fe;
case 0x0c0ad600u: goto P_0c0ad600;
case 0x0c0ad602u: goto P_0c0ad602;
case 0x0c0ad604u: goto P_0c0ad604;
case 0x0c0ad606u: goto P_0c0ad606;
case 0x0c0ad608u: goto P_0c0ad608;
case 0x0c0ad60au: goto P_0c0ad60a;
case 0x0c0ad60cu: goto P_0c0ad60c;
case 0x0c0ad60eu: goto P_0c0ad60e;
case 0x0c0ad610u: goto P_0c0ad610;
case 0x0c0ad612u: goto P_0c0ad612;
case 0x0c0ad614u: goto P_0c0ad614;
case 0x0c0ad616u: goto P_0c0ad616;
case 0x0c0ad618u: goto P_0c0ad618;
case 0x0c0ad61au: goto P_0c0ad61a;
case 0x0c0ad61cu: goto P_0c0ad61c;
case 0x0c0ad61eu: goto P_0c0ad61e;
case 0x0c0ad620u: goto P_0c0ad620;
case 0x0c0ad622u: goto P_0c0ad622;
case 0x0c0ad624u: goto P_0c0ad624;
case 0x0c0ad626u: goto P_0c0ad626;
case 0x0c0ad628u: goto P_0c0ad628;
case 0x0c0ad62au: goto P_0c0ad62a;
case 0x0c0ad62cu: goto P_0c0ad62c;
case 0x0c0ad62eu: goto P_0c0ad62e;
case 0x0c0ad630u: goto P_0c0ad630;
case 0x0c0ad632u: goto P_0c0ad632;
case 0x0c0ad634u: goto P_0c0ad634;
case 0x0c0ad636u: goto P_0c0ad636;
case 0x0c0ad638u: goto P_0c0ad638;
case 0x0c0ad63au: goto P_0c0ad63a;
case 0x0c0ad63cu: goto P_0c0ad63c;
case 0x0c0ad63eu: goto P_0c0ad63e;
case 0x0c0ad640u: goto P_0c0ad640;
case 0x0c0ad642u: goto P_0c0ad642;
case 0x0c0ad644u: goto P_0c0ad644;
case 0x0c0ad646u: goto P_0c0ad646;
case 0x0c0ad648u: goto P_0c0ad648;
case 0x0c0ad64au: goto P_0c0ad64a;
case 0x0c0ad64cu: goto P_0c0ad64c;
case 0x0c0ad64eu: goto P_0c0ad64e;
case 0x0c0ad650u: goto P_0c0ad650;
case 0x0c0ad652u: goto P_0c0ad652;
case 0x0c0ad654u: goto P_0c0ad654;
case 0x0c0ad656u: goto P_0c0ad656;
case 0x0c0ad658u: goto P_0c0ad658;
case 0x0c0ad65au: goto P_0c0ad65a;
case 0x0c0ad65cu: goto P_0c0ad65c;
case 0x0c0ad65eu: goto P_0c0ad65e;
case 0x0c0ad660u: goto P_0c0ad660;
case 0x0c0ad662u: goto P_0c0ad662;
case 0x0c0ad664u: goto P_0c0ad664;
case 0x0c0ad666u: goto P_0c0ad666;
case 0x0c0ad668u: goto P_0c0ad668;
case 0x0c0ad66au: goto P_0c0ad66a;
case 0x0c0ad66cu: goto P_0c0ad66c;
case 0x0c0ad66eu: goto P_0c0ad66e;
case 0x0c0ad670u: goto P_0c0ad670;
case 0x0c0ad672u: goto P_0c0ad672;
case 0x0c0ad674u: goto P_0c0ad674;
case 0x0c0ad676u: goto P_0c0ad676;
case 0x0c0ad678u: goto P_0c0ad678;
case 0x0c0ad67au: goto P_0c0ad67a;
case 0x0c0ad67cu: goto P_0c0ad67c;
case 0x0c0ad67eu: goto P_0c0ad67e;
case 0x0c0ad680u: goto P_0c0ad680;
case 0x0c0ad682u: goto P_0c0ad682;
case 0x0c0ad684u: goto P_0c0ad684;
case 0x0c0ad686u: goto P_0c0ad686;
case 0x0c0ad688u: goto P_0c0ad688;
case 0x0c0ad68au: goto P_0c0ad68a;
case 0x0c0ad68cu: goto P_0c0ad68c;
case 0x0c0ad68eu: goto P_0c0ad68e;
case 0x0c0ad690u: goto P_0c0ad690;
case 0x0c0ad692u: goto P_0c0ad692;
case 0x0c0ad694u: goto P_0c0ad694;
case 0x0c0ad696u: goto P_0c0ad696;
case 0x0c0ad698u: goto P_0c0ad698;
case 0x0c0ad69au: goto P_0c0ad69a;
case 0x0c0ad69cu: goto P_0c0ad69c;
case 0x0c0ad69eu: goto P_0c0ad69e;
case 0x0c0ad6a0u: goto P_0c0ad6a0;
case 0x0c0ad6a2u: goto P_0c0ad6a2;
case 0x0c0ad6a4u: goto P_0c0ad6a4;
case 0x0c0ad6a6u: goto P_0c0ad6a6;
case 0x0c0ad6a8u: goto P_0c0ad6a8;
case 0x0c0ad6aau: goto P_0c0ad6aa;
case 0x0c0ad6acu: goto P_0c0ad6ac;
case 0x0c0ad6aeu: goto P_0c0ad6ae;
case 0x0c0ad6b0u: goto P_0c0ad6b0;
case 0x0c0ad6b2u: goto P_0c0ad6b2;
case 0x0c0ad6b4u: goto P_0c0ad6b4;
case 0x0c0ad6b6u: goto P_0c0ad6b6;
case 0x0c0ad6b8u: goto P_0c0ad6b8;
case 0x0c0ad6bau: goto P_0c0ad6ba;
case 0x0c0ad6bcu: goto P_0c0ad6bc;
case 0x0c0ad6beu: goto P_0c0ad6be;
case 0x0c0ad6c0u: goto P_0c0ad6c0;
case 0x0c0ad6c2u: goto P_0c0ad6c2;
case 0x0c0ad6c4u: goto P_0c0ad6c4;
case 0x0c0ad6c6u: goto P_0c0ad6c6;
case 0x0c0ad6c8u: goto P_0c0ad6c8;
case 0x0c0ad6cau: goto P_0c0ad6ca;
case 0x0c0ad6ccu: goto P_0c0ad6cc;
case 0x0c0ad6ceu: goto P_0c0ad6ce;
case 0x0c0ad6d0u: goto P_0c0ad6d0;
case 0x0c0ad6d2u: goto P_0c0ad6d2;
case 0x0c0ad6d4u: goto P_0c0ad6d4;
case 0x0c0ad6d6u: goto P_0c0ad6d6;
case 0x0c0ad6d8u: goto P_0c0ad6d8;
case 0x0c0ad6dau: goto P_0c0ad6da;
case 0x0c0ad6dcu: goto P_0c0ad6dc;
case 0x0c0ad6deu: goto P_0c0ad6de;
case 0x0c0ad6e0u: goto P_0c0ad6e0;
case 0x0c0ad6e2u: goto P_0c0ad6e2;
case 0x0c0ad6e4u: goto P_0c0ad6e4;
case 0x0c0ad6e6u: goto P_0c0ad6e6;
case 0x0c0ad6e8u: goto P_0c0ad6e8;
case 0x0c0ad6eau: goto P_0c0ad6ea;
case 0x0c0ad6ecu: goto P_0c0ad6ec;
case 0x0c0ad72cu: goto P_0c0ad72c;
case 0x0c0ad72eu: goto P_0c0ad72e;
case 0x0c0ad730u: goto P_0c0ad730;
case 0x0c0ad732u: goto P_0c0ad732;
case 0x0c0ad734u: goto P_0c0ad734;
case 0x0c0ad736u: goto P_0c0ad736;
case 0x0c0ad738u: goto P_0c0ad738;
case 0x0c0ad73au: goto P_0c0ad73a;
case 0x0c0ad73cu: goto P_0c0ad73c;
case 0x0c0ad73eu: goto P_0c0ad73e;
case 0x0c0ad740u: goto P_0c0ad740;
case 0x0c0ad742u: goto P_0c0ad742;
case 0x0c0ad744u: goto P_0c0ad744;
case 0x0c0ad746u: goto P_0c0ad746;
case 0x0c0ad748u: goto P_0c0ad748;
case 0x0c0ad74au: goto P_0c0ad74a;
case 0x0c0ad74cu: goto P_0c0ad74c;
case 0x0c0ad74eu: goto P_0c0ad74e;
case 0x0c0ad750u: goto P_0c0ad750;
case 0x0c0ad752u: goto P_0c0ad752;
case 0x0c0ad754u: goto P_0c0ad754;
case 0x0c0ad756u: goto P_0c0ad756;
case 0x0c0ad758u: goto P_0c0ad758;
case 0x0c0ad75au: goto P_0c0ad75a;
case 0x0c0ad75cu: goto P_0c0ad75c;
case 0x0c0ad75eu: goto P_0c0ad75e;
case 0x0c0ad760u: goto P_0c0ad760;
case 0x0c0ad762u: goto P_0c0ad762;
case 0x0c0ad764u: goto P_0c0ad764;
case 0x0c0ad766u: goto P_0c0ad766;
case 0x0c0ad768u: goto P_0c0ad768;
case 0x0c0ad76au: goto P_0c0ad76a;
case 0x0c0ad76cu: goto P_0c0ad76c;
case 0x0c0ad76eu: goto P_0c0ad76e;
case 0x0c0ad770u: goto P_0c0ad770;
case 0x0c0ad772u: goto P_0c0ad772;
case 0x0c0ad774u: goto P_0c0ad774;
case 0x0c0ad776u: goto P_0c0ad776;
case 0x0c0ad778u: goto P_0c0ad778;
case 0x0c0ad77au: goto P_0c0ad77a;
case 0x0c0ad77cu: goto P_0c0ad77c;
case 0x0c0ad77eu: goto P_0c0ad77e;
case 0x0c0ad780u: goto P_0c0ad780;
case 0x0c0ad782u: goto P_0c0ad782;
case 0x0c0ad784u: goto P_0c0ad784;
case 0x0c0ad786u: goto P_0c0ad786;
case 0x0c0ad788u: goto P_0c0ad788;
case 0x0c0ad78au: goto P_0c0ad78a;
case 0x0c0ad78cu: goto P_0c0ad78c;
case 0x0c0ad78eu: goto P_0c0ad78e;
case 0x0c0ad790u: goto P_0c0ad790;
case 0x0c0ad792u: goto P_0c0ad792;
case 0x0c0ad794u: goto P_0c0ad794;
case 0x0c0ad796u: goto P_0c0ad796;
case 0x0c0ad798u: goto P_0c0ad798;
case 0x0c0ad79au: goto P_0c0ad79a;
case 0x0c0ad79cu: goto P_0c0ad79c;
case 0x0c0ad79eu: goto P_0c0ad79e;
case 0x0c0ad7a0u: goto P_0c0ad7a0;
case 0x0c0ad7a2u: goto P_0c0ad7a2;
case 0x0c0ad7a4u: goto P_0c0ad7a4;
case 0x0c0ad7a6u: goto P_0c0ad7a6;
case 0x0c0ad7a8u: goto P_0c0ad7a8;
case 0x0c0ad7aau: goto P_0c0ad7aa;
case 0x0c0ad7acu: goto P_0c0ad7ac;
case 0x0c0ad7aeu: goto P_0c0ad7ae;
case 0x0c0ad7b0u: goto P_0c0ad7b0;
case 0x0c0ad7b2u: goto P_0c0ad7b2;
case 0x0c0ad7b4u: goto P_0c0ad7b4;
case 0x0c0ad7b6u: goto P_0c0ad7b6;
case 0x0c0ad7b8u: goto P_0c0ad7b8;
case 0x0c0ad7bau: goto P_0c0ad7ba;
case 0x0c0ad7bcu: goto P_0c0ad7bc;
case 0x0c0ad7beu: goto P_0c0ad7be;
case 0x0c0ad7c0u: goto P_0c0ad7c0;
case 0x0c0ad7c2u: goto P_0c0ad7c2;
case 0x0c0ad7c4u: goto P_0c0ad7c4;
case 0x0c0ad7c6u: goto P_0c0ad7c6;
case 0x0c0ad7c8u: goto P_0c0ad7c8;
case 0x0c0ad7cau: goto P_0c0ad7ca;
case 0x0c0ad7ccu: goto P_0c0ad7cc;
case 0x0c0ad7ceu: goto P_0c0ad7ce;
case 0x0c0ad7d0u: goto P_0c0ad7d0;
case 0x0c0ad7d2u: goto P_0c0ad7d2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ad58au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad58au; return 0; } return 1;
P_0c0ad5a0: /* original 2fe6, guest PC 0x0c0ad5a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad5a0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad5a2;
P_0c0ad5a2: /* original 2fd6, guest PC 0x0c0ad5a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad5a2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad5a4;
P_0c0ad5a4: /* original 2fc6, guest PC 0x0c0ad5a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad5a4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad5a6;
P_0c0ad5a6: /* original 2fb6, guest PC 0x0c0ad5a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad5a6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ad5a8;
P_0c0ad5a8: /* original 90a1, guest PC 0x0c0ad5a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad5a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6eeu,2);
goto P_0c0ad5aa;
P_0c0ad5aa: /* original 4f22, guest PC 0x0c0ad5aa */
if(!s->budget--) { s->failed_pc=0x0c0ad5aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad5ac;
P_0c0ad5ac: /* original 0466, guest PC 0x0c0ad5ac */
if(!s->budget--) { s->failed_pc=0x0c0ad5acu; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c0ad5ae;
P_0c0ad5ae: /* original 7004, guest PC 0x0c0ad5ae */
if(!s->budget--) { s->failed_pc=0x0c0ad5aeu; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad5b0;
P_0c0ad5b0: /* original 0466, guest PC 0x0c0ad5b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad5b0u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c0ad5b2;
P_0c0ad5b2: /* original d358, guest PC 0x0c0ad5b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad5b2u; return 0; }
r[3]=read(ram,0x0c0ad714u,4);
goto P_0c0ad5b4;
P_0c0ad5b4: /* original 7ff8, guest PC 0x0c0ad5b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad5b4u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ad5b6;
P_0c0ad5b6: /* original 6242, guest PC 0x0c0ad5b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad5b6u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ad5b8;
P_0c0ad5b8: /* original 2238, guest PC 0x0c0ad5b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad5b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ad5ba;
P_0c0ad5ba: /* original 890e, guest PC 0x0c0ad5ba */
if(!s->budget--) { s->failed_pc=0x0c0ad5bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad5da; }
goto P_0c0ad5bc;
P_0c0ad5bc: /* original 9098, guest PC 0x0c0ad5bc */
if(!s->budget--) { s->failed_pc=0x0c0ad5bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6f0u,2);
goto P_0c0ad5be;
P_0c0ad5be: /* original 024d, guest PC 0x0c0ad5be */
if(!s->budget--) { s->failed_pc=0x0c0ad5beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad5c0;
P_0c0ad5c0: /* original 622b, guest PC 0x0c0ad5c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad5c0u; return 0; }
r[2]=0u-r[2];
goto P_0c0ad5c2;
P_0c0ad5c2: /* original 0425, guest PC 0x0c0ad5c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad5c2u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad5c4;
P_0c0ad5c4: /* original 70fe, guest PC 0x0c0ad5c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad5c4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0ad5c6;
P_0c0ad5c6: /* original 014d, guest PC 0x0c0ad5c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad5c6u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad5c8;
P_0c0ad5c8: /* original 611b, guest PC 0x0c0ad5c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad5c8u; return 0; }
r[1]=0u-r[1];
goto P_0c0ad5ca;
P_0c0ad5ca: /* original 0415, guest PC 0x0c0ad5ca */
if(!s->budget--) { s->failed_pc=0x0c0ad5cau; return 0; }
write(ram,r[4]+r[0],r[1],2);
goto P_0c0ad5cc;
P_0c0ad5cc: /* original 7024, guest PC 0x0c0ad5cc */
if(!s->budget--) { s->failed_pc=0x0c0ad5ccu; return 0; }
r[0]+=0x00000024u;
goto P_0c0ad5ce;
P_0c0ad5ce: /* original 024c, guest PC 0x0c0ad5ce */
if(!s->budget--) { s->failed_pc=0x0c0ad5ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad5d0;
P_0c0ad5d0: /* original d051, guest PC 0x0c0ad5d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad5d0u; return 0; }
r[0]=read(ram,0x0c0ad718u,4);
goto P_0c0ad5d2;
P_0c0ad5d2: /* original 622c, guest PC 0x0c0ad5d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad5d2u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ad5d4;
P_0c0ad5d4: /* original 012c, guest PC 0x0c0ad5d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad5d4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0ad5d6;
P_0c0ad5d6: /* original 908c, guest PC 0x0c0ad5d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad5d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6f2u,2);
goto P_0c0ad5d8;
P_0c0ad5d8: /* original 0414, guest PC 0x0c0ad5d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad5d8u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0ad5da;
P_0c0ad5da: /* original 908b, guest PC 0x0c0ad5da */
if(!s->budget--) { s->failed_pc=0x0c0ad5dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6f4u,2);
goto P_0c0ad5dc;
P_0c0ad5dc: /* original d34f, guest PC 0x0c0ad5dc */
if(!s->budget--) { s->failed_pc=0x0c0ad5dcu; return 0; }
r[3]=read(ram,0x0c0ad71cu,4);
goto P_0c0ad5de;
P_0c0ad5de: /* original 064e, guest PC 0x0c0ad5de */
if(!s->budget--) { s->failed_pc=0x0c0ad5deu; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c0ad5e0;
P_0c0ad5e0: /* original 2638, guest PC 0x0c0ad5e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad5e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0ad5e2;
P_0c0ad5e2: /* original 8b01, guest PC 0x0c0ad5e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad5e8; }
goto P_0c0ad5e4;
P_0c0ad5e4: /* original a0ec, guest PC 0x0c0ad5e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad5e4u; return 0; }
goto P_0c0ad7c0;
P_0c0ad5e6: /* original 0009, guest PC 0x0c0ad5e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad5e6u; return 0; }
goto P_0c0ad5e8;
P_0c0ad5e8: /* original 9085, guest PC 0x0c0ad5e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad5e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6f6u,2);
goto P_0c0ad5ea;
P_0c0ad5ea: /* original 024d, guest PC 0x0c0ad5ea */
if(!s->budget--) { s->failed_pc=0x0c0ad5eau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad5ec;
P_0c0ad5ec: /* original 622d, guest PC 0x0c0ad5ec */
if(!s->budget--) { s->failed_pc=0x0c0ad5ecu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0ad5ee;
P_0c0ad5ee: /* original 2f22, guest PC 0x0c0ad5ee */
if(!s->budget--) { s->failed_pc=0x0c0ad5eeu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad5f0;
P_0c0ad5f0: /* original 9082, guest PC 0x0c0ad5f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad5f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6f8u,2);
goto P_0c0ad5f2;
P_0c0ad5f2: /* original 034d, guest PC 0x0c0ad5f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad5f2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad5f4;
P_0c0ad5f4: /* original 633d, guest PC 0x0c0ad5f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad5f4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0ad5f6;
P_0c0ad5f6: /* original 1f31, guest PC 0x0c0ad5f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad5f6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0ad5f8;
P_0c0ad5f8: /* original 907f, guest PC 0x0c0ad5f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad5f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6fau,2);
goto P_0c0ad5fa;
P_0c0ad5fa: /* original 62f2, guest PC 0x0c0ad5fa */
if(!s->budget--) { s->failed_pc=0x0c0ad5fau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ad5fc;
P_0c0ad5fc: /* original 064d, guest PC 0x0c0ad5fc */
if(!s->budget--) { s->failed_pc=0x0c0ad5fcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad5fe;
P_0c0ad5fe: /* original 907d, guest PC 0x0c0ad5fe */
if(!s->budget--) { s->failed_pc=0x0c0ad5feu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6fcu,2);
goto P_0c0ad600;
P_0c0ad600: /* original 666d, guest PC 0x0c0ad600 */
if(!s->budget--) { s->failed_pc=0x0c0ad600u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0ad602;
P_0c0ad602: /* original 074c, guest PC 0x0c0ad602 */
if(!s->budget--) { s->failed_pc=0x0c0ad602u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad604;
P_0c0ad604: /* original 6b63, guest PC 0x0c0ad604 */
if(!s->budget--) { s->failed_pc=0x0c0ad604u; return 0; }
r[11]=r[6];
goto P_0c0ad606;
P_0c0ad606: /* original 907a, guest PC 0x0c0ad606 */
if(!s->budget--) { s->failed_pc=0x0c0ad606u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6feu,2);
goto P_0c0ad608;
P_0c0ad608: /* original 6d63, guest PC 0x0c0ad608 */
if(!s->budget--) { s->failed_pc=0x0c0ad608u; return 0; }
r[13]=r[6];
goto P_0c0ad60a;
P_0c0ad60a: /* original 3d38, guest PC 0x0c0ad60a */
if(!s->budget--) { s->failed_pc=0x0c0ad60au; return 0; }
r[13]-=r[3];
goto P_0c0ad60c;
P_0c0ad60c: /* original 064c, guest PC 0x0c0ad60c */
if(!s->budget--) { s->failed_pc=0x0c0ad60cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad60e;
P_0c0ad60e: /* original 677c, guest PC 0x0c0ad60e */
if(!s->budget--) { s->failed_pc=0x0c0ad60eu; return 0; }
r[7]=r[7]&255u;
goto P_0c0ad610;
P_0c0ad610: /* original 7d01, guest PC 0x0c0ad610 */
if(!s->budget--) { s->failed_pc=0x0c0ad610u; return 0; }
r[13]+=0x00000001u;
goto P_0c0ad612;
P_0c0ad612: /* original 666c, guest PC 0x0c0ad612 */
if(!s->budget--) { s->failed_pc=0x0c0ad612u; return 0; }
r[6]=r[6]&255u;
goto P_0c0ad614;
P_0c0ad614: /* original 2668, guest PC 0x0c0ad614 */
if(!s->budget--) { s->failed_pc=0x0c0ad614u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0ad616;
P_0c0ad616: /* original 8f0b, guest PC 0x0c0ad616 */
if(!s->budget--) { s->failed_pc=0x0c0ad616u; return 0; }
cond=r[17]&1u;
r[11]-=r[2];
if(!cond) { goto P_0c0ad630; }
goto P_0c0ad61a;
P_0c0ad618: /* original 3b28, guest PC 0x0c0ad618 */
if(!s->budget--) { s->failed_pc=0x0c0ad618u; return 0; }
r[11]-=r[2];
goto P_0c0ad61a;
P_0c0ad61a: /* original d241, guest PC 0x0c0ad61a */
if(!s->budget--) { s->failed_pc=0x0c0ad61au; return 0; }
r[2]=read(ram,0x0c0ad720u,4);
goto P_0c0ad61c;
P_0c0ad61c: /* original 6173, guest PC 0x0c0ad61c */
if(!s->budget--) { s->failed_pc=0x0c0ad61cu; return 0; }
r[1]=r[7];
goto P_0c0ad61e;
P_0c0ad61e: /* original 420b, guest PC 0x0c0ad61e */
if(!s->budget--) { s->failed_pc=0x0c0ad61eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad622u;
r[0]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad622u) { target=s->pc; goto dispatch; }
goto P_0c0ad622;
P_0c0ad620: /* original e003, guest PC 0x0c0ad620 */
if(!s->budget--) { s->failed_pc=0x0c0ad620u; return 0; }
r[0]=0x00000003u;
goto P_0c0ad622;
P_0c0ad622: /* original 6603, guest PC 0x0c0ad622 */
if(!s->budget--) { s->failed_pc=0x0c0ad622u; return 0; }
r[6]=r[0];
goto P_0c0ad624;
P_0c0ad624: /* original 4600, guest PC 0x0c0ad624 */
if(!s->budget--) { s->failed_pc=0x0c0ad624u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c0ad626;
P_0c0ad626: /* original e318, guest PC 0x0c0ad626 */
if(!s->budget--) { s->failed_pc=0x0c0ad626u; return 0; }
r[3]=0x00000018u;
goto P_0c0ad628;
P_0c0ad628: /* original 7606, guest PC 0x0c0ad628 */
if(!s->budget--) { s->failed_pc=0x0c0ad628u; return 0; }
r[6]+=0x00000006u;
goto P_0c0ad62a;
P_0c0ad62a: /* original 3636, guest PC 0x0c0ad62a */
if(!s->budget--) { s->failed_pc=0x0c0ad62au; return 0; }
r[17]=(r[17]&~1u)|((r[6]>r[3])!=0);
goto P_0c0ad62c;
P_0c0ad62c: /* original 8b00, guest PC 0x0c0ad62c */
if(!s->budget--) { s->failed_pc=0x0c0ad62cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad630; }
goto P_0c0ad62e;
P_0c0ad62e: /* original 6633, guest PC 0x0c0ad62e */
if(!s->budget--) { s->failed_pc=0x0c0ad62eu; return 0; }
r[6]=r[3];
goto P_0c0ad630;
P_0c0ad630: /* original 9066, guest PC 0x0c0ad630 */
if(!s->budget--) { s->failed_pc=0x0c0ad630u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad700u,2);
goto P_0c0ad632;
P_0c0ad632: /* original 0e4c, guest PC 0x0c0ad632 */
if(!s->budget--) { s->failed_pc=0x0c0ad632u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad634;
P_0c0ad634: /* original 6eec, guest PC 0x0c0ad634 */
if(!s->budget--) { s->failed_pc=0x0c0ad634u; return 0; }
r[14]=r[14]&255u;
goto P_0c0ad636;
P_0c0ad636: /* original 2ee8, guest PC 0x0c0ad636 */
if(!s->budget--) { s->failed_pc=0x0c0ad636u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0ad638;
P_0c0ad638: /* original 8b07, guest PC 0x0c0ad638 */
if(!s->budget--) { s->failed_pc=0x0c0ad638u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad64a; }
goto P_0c0ad63a;
P_0c0ad63a: /* original d239, guest PC 0x0c0ad63a */
if(!s->budget--) { s->failed_pc=0x0c0ad63au; return 0; }
r[2]=read(ram,0x0c0ad720u,4);
goto P_0c0ad63c;
P_0c0ad63c: /* original 6e73, guest PC 0x0c0ad63c */
if(!s->budget--) { s->failed_pc=0x0c0ad63cu; return 0; }
r[14]=r[7];
goto P_0c0ad63e;
P_0c0ad63e: /* original e005, guest PC 0x0c0ad63e */
if(!s->budget--) { s->failed_pc=0x0c0ad63eu; return 0; }
r[0]=0x00000005u;
goto P_0c0ad640;
P_0c0ad640: /* original 4e08, guest PC 0x0c0ad640 */
if(!s->budget--) { s->failed_pc=0x0c0ad640u; return 0; }
r[14]<<=2;
goto P_0c0ad642;
P_0c0ad642: /* original 420b, guest PC 0x0c0ad642 */
if(!s->budget--) { s->failed_pc=0x0c0ad642u; return 0; }
target=r[2];
r[16]=code_base|0x0c0ad646u;
r[1]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad646u) { target=s->pc; goto dispatch; }
goto P_0c0ad646;
P_0c0ad644: /* original 61e3, guest PC 0x0c0ad644 */
if(!s->budget--) { s->failed_pc=0x0c0ad644u; return 0; }
r[1]=r[14];
goto P_0c0ad646;
P_0c0ad646: /* original 6e03, guest PC 0x0c0ad646 */
if(!s->budget--) { s->failed_pc=0x0c0ad646u; return 0; }
r[14]=r[0];
goto P_0c0ad648;
P_0c0ad648: /* original 7e06, guest PC 0x0c0ad648 */
if(!s->budget--) { s->failed_pc=0x0c0ad648u; return 0; }
r[14]+=0x00000006u;
goto P_0c0ad64a;
P_0c0ad64a: /* original 905a, guest PC 0x0c0ad64a */
if(!s->budget--) { s->failed_pc=0x0c0ad64au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad702u,2);
goto P_0c0ad64c;
P_0c0ad64c: /* original 0c4c, guest PC 0x0c0ad64c */
if(!s->budget--) { s->failed_pc=0x0c0ad64cu; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad64e;
P_0c0ad64e: /* original 6ccc, guest PC 0x0c0ad64e */
if(!s->budget--) { s->failed_pc=0x0c0ad64eu; return 0; }
r[12]=r[12]&255u;
goto P_0c0ad650;
P_0c0ad650: /* original 2cc8, guest PC 0x0c0ad650 */
if(!s->budget--) { s->failed_pc=0x0c0ad650u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0ad652;
P_0c0ad652: /* original 8b0b, guest PC 0x0c0ad652 */
if(!s->budget--) { s->failed_pc=0x0c0ad652u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad66c; }
goto P_0c0ad654;
P_0c0ad654: /* original 6273, guest PC 0x0c0ad654 */
if(!s->budget--) { s->failed_pc=0x0c0ad654u; return 0; }
r[2]=r[7];
goto P_0c0ad656;
P_0c0ad656: /* original 4201, guest PC 0x0c0ad656 */
if(!s->budget--) { s->failed_pc=0x0c0ad656u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c0ad658;
P_0c0ad658: /* original 372c, guest PC 0x0c0ad658 */
if(!s->budget--) { s->failed_pc=0x0c0ad658u; return 0; }
r[7]+=r[2];
goto P_0c0ad65a;
P_0c0ad65a: /* original 2f22, guest PC 0x0c0ad65a */
if(!s->budget--) { s->failed_pc=0x0c0ad65au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad65c;
P_0c0ad65c: /* original 6c73, guest PC 0x0c0ad65c */
if(!s->budget--) { s->failed_pc=0x0c0ad65cu; return 0; }
r[12]=r[7];
goto P_0c0ad65e;
P_0c0ad65e: /* original d330, guest PC 0x0c0ad65e */
if(!s->budget--) { s->failed_pc=0x0c0ad65eu; return 0; }
r[3]=read(ram,0x0c0ad720u,4);
goto P_0c0ad660;
P_0c0ad660: /* original e005, guest PC 0x0c0ad660 */
if(!s->budget--) { s->failed_pc=0x0c0ad660u; return 0; }
r[0]=0x00000005u;
goto P_0c0ad662;
P_0c0ad662: /* original 4c08, guest PC 0x0c0ad662 */
if(!s->budget--) { s->failed_pc=0x0c0ad662u; return 0; }
r[12]<<=2;
goto P_0c0ad664;
P_0c0ad664: /* original 430b, guest PC 0x0c0ad664 */
if(!s->budget--) { s->failed_pc=0x0c0ad664u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ad668u;
r[1]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ad668u) { target=s->pc; goto dispatch; }
goto P_0c0ad668;
P_0c0ad666: /* original 61c3, guest PC 0x0c0ad666 */
if(!s->budget--) { s->failed_pc=0x0c0ad666u; return 0; }
r[1]=r[12];
goto P_0c0ad668;
P_0c0ad668: /* original 6c03, guest PC 0x0c0ad668 */
if(!s->budget--) { s->failed_pc=0x0c0ad668u; return 0; }
r[12]=r[0];
goto P_0c0ad66a;
P_0c0ad66a: /* original 7c06, guest PC 0x0c0ad66a */
if(!s->budget--) { s->failed_pc=0x0c0ad66au; return 0; }
r[12]+=0x00000006u;
goto P_0c0ad66c;
P_0c0ad66c: /* original 904a, guest PC 0x0c0ad66c */
if(!s->budget--) { s->failed_pc=0x0c0ad66cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad704u,2);
goto P_0c0ad66e;
P_0c0ad66e: /* original 63d3, guest PC 0x0c0ad66e */
if(!s->budget--) { s->failed_pc=0x0c0ad66eu; return 0; }
r[3]=r[13];
goto P_0c0ad670;
P_0c0ad670: /* original 3368, guest PC 0x0c0ad670 */
if(!s->budget--) { s->failed_pc=0x0c0ad670u; return 0; }
r[3]-=r[6];
goto P_0c0ad672;
P_0c0ad672: /* original 62b3, guest PC 0x0c0ad672 */
if(!s->budget--) { s->failed_pc=0x0c0ad672u; return 0; }
r[2]=r[11];
goto P_0c0ad674;
P_0c0ad674: /* original 0464, guest PC 0x0c0ad674 */
if(!s->budget--) { s->failed_pc=0x0c0ad674u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0ad676;
P_0c0ad676: /* original 70fc, guest PC 0x0c0ad676 */
if(!s->budget--) { s->failed_pc=0x0c0ad676u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad678;
P_0c0ad678: /* original 0435, guest PC 0x0c0ad678 */
if(!s->budget--) { s->failed_pc=0x0c0ad678u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad67a;
P_0c0ad67a: /* original 7002, guest PC 0x0c0ad67a */
if(!s->budget--) { s->failed_pc=0x0c0ad67au; return 0; }
r[0]+=0x00000002u;
goto P_0c0ad67c;
P_0c0ad67c: /* original 3268, guest PC 0x0c0ad67c */
if(!s->budget--) { s->failed_pc=0x0c0ad67cu; return 0; }
r[2]-=r[6];
goto P_0c0ad67e;
P_0c0ad67e: /* original 63d3, guest PC 0x0c0ad67e */
if(!s->budget--) { s->failed_pc=0x0c0ad67eu; return 0; }
r[3]=r[13];
goto P_0c0ad680;
P_0c0ad680: /* original 0425, guest PC 0x0c0ad680 */
if(!s->budget--) { s->failed_pc=0x0c0ad680u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad682;
P_0c0ad682: /* original 33e8, guest PC 0x0c0ad682 */
if(!s->budget--) { s->failed_pc=0x0c0ad682u; return 0; }
r[3]-=r[14];
goto P_0c0ad684;
P_0c0ad684: /* original 903f, guest PC 0x0c0ad684 */
if(!s->budget--) { s->failed_pc=0x0c0ad684u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad706u,2);
goto P_0c0ad686;
P_0c0ad686: /* original 62b3, guest PC 0x0c0ad686 */
if(!s->budget--) { s->failed_pc=0x0c0ad686u; return 0; }
r[2]=r[11];
goto P_0c0ad688;
P_0c0ad688: /* original 32e8, guest PC 0x0c0ad688 */
if(!s->budget--) { s->failed_pc=0x0c0ad688u; return 0; }
r[2]-=r[14];
goto P_0c0ad68a;
P_0c0ad68a: /* original 04e4, guest PC 0x0c0ad68a */
if(!s->budget--) { s->failed_pc=0x0c0ad68au; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0ad68c;
P_0c0ad68c: /* original 70fc, guest PC 0x0c0ad68c */
if(!s->budget--) { s->failed_pc=0x0c0ad68cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad68e;
P_0c0ad68e: /* original 0435, guest PC 0x0c0ad68e */
if(!s->budget--) { s->failed_pc=0x0c0ad68eu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad690;
P_0c0ad690: /* original 7002, guest PC 0x0c0ad690 */
if(!s->budget--) { s->failed_pc=0x0c0ad690u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ad692;
P_0c0ad692: /* original 0425, guest PC 0x0c0ad692 */
if(!s->budget--) { s->failed_pc=0x0c0ad692u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad694;
P_0c0ad694: /* original 3dc8, guest PC 0x0c0ad694 */
if(!s->budget--) { s->failed_pc=0x0c0ad694u; return 0; }
r[13]-=r[12];
goto P_0c0ad696;
P_0c0ad696: /* original 9037, guest PC 0x0c0ad696 */
if(!s->budget--) { s->failed_pc=0x0c0ad696u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad708u,2);
goto P_0c0ad698;
P_0c0ad698: /* original 3bc8, guest PC 0x0c0ad698 */
if(!s->budget--) { s->failed_pc=0x0c0ad698u; return 0; }
r[11]-=r[12];
goto P_0c0ad69a;
P_0c0ad69a: /* original 04c4, guest PC 0x0c0ad69a */
if(!s->budget--) { s->failed_pc=0x0c0ad69au; return 0; }
write(ram,r[4]+r[0],r[12],1);
goto P_0c0ad69c;
P_0c0ad69c: /* original 70fc, guest PC 0x0c0ad69c */
if(!s->budget--) { s->failed_pc=0x0c0ad69cu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0ad69e;
P_0c0ad69e: /* original 04d5, guest PC 0x0c0ad69e */
if(!s->budget--) { s->failed_pc=0x0c0ad69eu; return 0; }
write(ram,r[4]+r[0],r[13],2);
goto P_0c0ad6a0;
P_0c0ad6a0: /* original 7002, guest PC 0x0c0ad6a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad6a0u; return 0; }
r[0]+=0x00000002u;
goto P_0c0ad6a2;
P_0c0ad6a2: /* original 04b5, guest PC 0x0c0ad6a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad6a2u; return 0; }
write(ram,r[4]+r[0],r[11],2);
goto P_0c0ad6a4;
P_0c0ad6a4: /* original 9027, guest PC 0x0c0ad6a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad6a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad6f6u,2);
goto P_0c0ad6a6;
P_0c0ad6a6: /* original 064d, guest PC 0x0c0ad6a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad6a6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad6a8;
P_0c0ad6a8: /* original 7004, guest PC 0x0c0ad6a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad6a8u; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad6aa;
P_0c0ad6aa: /* original 666d, guest PC 0x0c0ad6aa */
if(!s->budget--) { s->failed_pc=0x0c0ad6aau; return 0; }
r[6]=r[6]&65535u;
goto P_0c0ad6ac;
P_0c0ad6ac: /* original 074d, guest PC 0x0c0ad6ac */
if(!s->budget--) { s->failed_pc=0x0c0ad6acu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad6ae;
P_0c0ad6ae: /* original 902c, guest PC 0x0c0ad6ae */
if(!s->budget--) { s->failed_pc=0x0c0ad6aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad70au,2);
goto P_0c0ad6b0;
P_0c0ad6b0: /* original d31c, guest PC 0x0c0ad6b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad6b0u; return 0; }
r[3]=read(ram,0x0c0ad724u,4);
goto P_0c0ad6b2;
P_0c0ad6b2: /* original 025e, guest PC 0x0c0ad6b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad6b2u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0ad6b4;
P_0c0ad6b4: /* original 2238, guest PC 0x0c0ad6b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad6b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ad6b6;
P_0c0ad6b6: /* original 8d02, guest PC 0x0c0ad6b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad6b6u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&65535u;
if(cond) { goto P_0c0ad6be; }
goto P_0c0ad6ba;
P_0c0ad6b8: /* original 677d, guest PC 0x0c0ad6b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad6b8u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0ad6ba;
P_0c0ad6ba: /* original a081, guest PC 0x0c0ad6ba */
if(!s->budget--) { s->failed_pc=0x0c0ad6bau; return 0; }
goto P_0c0ad7c0;
P_0c0ad6bc: /* original 0009, guest PC 0x0c0ad6bc */
if(!s->budget--) { s->failed_pc=0x0c0ad6bcu; return 0; }
goto P_0c0ad6be;
P_0c0ad6be: /* original 9025, guest PC 0x0c0ad6be */
if(!s->budget--) { s->failed_pc=0x0c0ad6beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad70cu,2);
goto P_0c0ad6c0;
P_0c0ad6c0: /* original 014c, guest PC 0x0c0ad6c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad6c0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad6c2;
P_0c0ad6c2: /* original 70bb, guest PC 0x0c0ad6c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad6c2u; return 0; }
r[0]+=0xffffffbbu;
goto P_0c0ad6c4;
P_0c0ad6c4: /* original 0414, guest PC 0x0c0ad6c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad6c4u; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0ad6c6;
P_0c0ad6c6: /* original 705e, guest PC 0x0c0ad6c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad6c6u; return 0; }
r[0]+=0x0000005eu;
goto P_0c0ad6c8;
P_0c0ad6c8: /* original f346, guest PC 0x0c0ad6c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad6c8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0ad6ca;
P_0c0ad6ca: /* original 7004, guest PC 0x0c0ad6ca */
if(!s->budget--) { s->failed_pc=0x0c0ad6cau; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad6cc;
P_0c0ad6cc: /* original f437, guest PC 0x0c0ad6cc */
if(!s->budget--) { s->failed_pc=0x0c0ad6ccu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0ad6ce;
P_0c0ad6ce: /* original 901e, guest PC 0x0c0ad6ce */
if(!s->budget--) { s->failed_pc=0x0c0ad6ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad70eu,2);
goto P_0c0ad6d0;
P_0c0ad6d0: /* original 034d, guest PC 0x0c0ad6d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad6d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad6d2;
P_0c0ad6d2: /* original 901d, guest PC 0x0c0ad6d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad6d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad710u,2);
goto P_0c0ad6d4;
P_0c0ad6d4: /* original 024d, guest PC 0x0c0ad6d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad6d4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ad6d6;
P_0c0ad6d6: /* original 70fe, guest PC 0x0c0ad6d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad6d6u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c0ad6d8;
P_0c0ad6d8: /* original 3238, guest PC 0x0c0ad6d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad6d8u; return 0; }
r[2]-=r[3];
goto P_0c0ad6da;
P_0c0ad6da: /* original 0425, guest PC 0x0c0ad6da */
if(!s->budget--) { s->failed_pc=0x0c0ad6dau; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad6dc;
P_0c0ad6dc: /* original 9019, guest PC 0x0c0ad6dc */
if(!s->budget--) { s->failed_pc=0x0c0ad6dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad712u,2);
goto P_0c0ad6de;
P_0c0ad6de: /* original 0e4c, guest PC 0x0c0ad6de */
if(!s->budget--) { s->failed_pc=0x0c0ad6deu; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad6e0;
P_0c0ad6e0: /* original d011, guest PC 0x0c0ad6e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad6e0u; return 0; }
r[0]=read(ram,0x0c0ad728u,4);
goto P_0c0ad6e2;
P_0c0ad6e2: /* original 6eec, guest PC 0x0c0ad6e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad6e2u; return 0; }
r[14]=r[14]&255u;
goto P_0c0ad6e4;
P_0c0ad6e4: /* original 0eec, guest PC 0x0c0ad6e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad6e4u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ad6e6;
P_0c0ad6e6: /* original 9011, guest PC 0x0c0ad6e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad6e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad70cu,2);
goto P_0c0ad6e8;
P_0c0ad6e8: /* original 2ee8, guest PC 0x0c0ad6e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad6e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0ad6ea;
P_0c0ad6ea: /* original a01f, guest PC 0x0c0ad6ea */
if(!s->budget--) { s->failed_pc=0x0c0ad6eau; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0ad72c;
P_0c0ad6ec: /* original 04e4, guest PC 0x0c0ad6ec */
if(!s->budget--) { s->failed_pc=0x0c0ad6ecu; return 0; }
write(ram,r[4]+r[0],r[14],1);
if(!vf3_matrix_family(0x0c0ad6eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad6eeu; return 0; } return 1;
P_0c0ad72c: /* original 8d48, guest PC 0x0c0ad72c */
if(!s->budget--) { s->failed_pc=0x0c0ad72cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ad7c0; }
goto P_0c0ad730;
P_0c0ad72e: /* original 0009, guest PC 0x0c0ad72e */
if(!s->budget--) { s->failed_pc=0x0c0ad72eu; return 0; }
goto P_0c0ad730;
P_0c0ad730: /* original 4618, guest PC 0x0c0ad730 */
if(!s->budget--) { s->failed_pc=0x0c0ad730u; return 0; }
r[6]<<=8;
goto P_0c0ad732;
P_0c0ad732: /* original 9088, guest PC 0x0c0ad732 */
if(!s->budget--) { s->failed_pc=0x0c0ad732u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad846u,2);
goto P_0c0ad734;
P_0c0ad734: /* original 465a, guest PC 0x0c0ad734 */
if(!s->budget--) { s->failed_pc=0x0c0ad734u; return 0; }
r[53]=r[6];
goto P_0c0ad736;
P_0c0ad736: /* original 4718, guest PC 0x0c0ad736 */
if(!s->budget--) { s->failed_pc=0x0c0ad736u; return 0; }
r[7]<<=8;
goto P_0c0ad738;
P_0c0ad738: /* original 3768, guest PC 0x0c0ad738 */
if(!s->budget--) { s->failed_pc=0x0c0ad738u; return 0; }
r[7]-=r[6];
goto P_0c0ad73a;
P_0c0ad73a: /* original f746, guest PC 0x0c0ad73a */
if(!s->budget--) { s->failed_pc=0x0c0ad73au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0ad73c;
P_0c0ad73c: /* original f456, guest PC 0x0c0ad73c */
if(!s->budget--) { s->failed_pc=0x0c0ad73cu; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c0ad73e;
P_0c0ad73e: /* original f32d, guest PC 0x0c0ad73e */
if(!s->budget--) { s->failed_pc=0x0c0ad73eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ad740;
P_0c0ad740: /* original 475a, guest PC 0x0c0ad740 */
if(!s->budget--) { s->failed_pc=0x0c0ad740u; return 0; }
r[53]=r[7];
goto P_0c0ad742;
P_0c0ad742: /* original f22d, guest PC 0x0c0ad742 */
if(!s->budget--) { s->failed_pc=0x0c0ad742u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c0ad744;
P_0c0ad744: /* original f63c, guest PC 0x0c0ad744 */
if(!s->budget--) { s->failed_pc=0x0c0ad744u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0ad746;
P_0c0ad746: /* original f38d, guest PC 0x0c0ad746 */
if(!s->budget--) { s->failed_pc=0x0c0ad746u; return 0; }
fr[3]=0;
goto P_0c0ad748;
P_0c0ad748: /* original f325, guest PC 0x0c0ad748 */
if(!s->budget--) { s->failed_pc=0x0c0ad748u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0ad74a;
P_0c0ad74a: /* original 8f03, guest PC 0x0c0ad74a */
if(!s->budget--) { s->failed_pc=0x0c0ad74au; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,2);
if(!cond) { goto P_0c0ad754; }
goto P_0c0ad74e;
P_0c0ad74c: /* original f52c, guest PC 0x0c0ad74c */
if(!s->budget--) { s->failed_pc=0x0c0ad74cu; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0ad74e;
P_0c0ad74e: /* original c742, guest PC 0x0c0ad74e */
if(!s->budget--) { s->failed_pc=0x0c0ad74eu; return 0; }
r[0]=code_base|0x000ad858u;
goto P_0c0ad750;
P_0c0ad750: /* original f308, guest PC 0x0c0ad750 */
if(!s->budget--) { s->failed_pc=0x0c0ad750u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ad752;
P_0c0ad752: /* original f530, guest PC 0x0c0ad752 */
if(!s->budget--) { s->failed_pc=0x0c0ad752u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0ad754;
P_0c0ad754: /* original 9078, guest PC 0x0c0ad754 */
if(!s->budget--) { s->failed_pc=0x0c0ad754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad848u,2);
goto P_0c0ad756;
P_0c0ad756: /* original f471, guest PC 0x0c0ad756 */
if(!s->budget--) { s->failed_pc=0x0c0ad756u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c0ad758;
P_0c0ad758: /* original d340, guest PC 0x0c0ad758 */
if(!s->budget--) { s->failed_pc=0x0c0ad758u; return 0; }
r[3]=read(ram,0x0c0ad85cu,4);
goto P_0c0ad75a;
P_0c0ad75a: /* original 064c, guest PC 0x0c0ad75a */
if(!s->budget--) { s->failed_pc=0x0c0ad75au; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ad75c;
P_0c0ad75c: /* original 2f32, guest PC 0x0c0ad75c */
if(!s->budget--) { s->failed_pc=0x0c0ad75cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ad75e;
P_0c0ad75e: /* original 666c, guest PC 0x0c0ad75e */
if(!s->budget--) { s->failed_pc=0x0c0ad75eu; return 0; }
r[6]=r[6]&255u;
goto P_0c0ad760;
P_0c0ad760: /* original 6763, guest PC 0x0c0ad760 */
if(!s->budget--) { s->failed_pc=0x0c0ad760u; return 0; }
r[7]=r[6];
goto P_0c0ad762;
P_0c0ad762: /* original 4700, guest PC 0x0c0ad762 */
if(!s->budget--) { s->failed_pc=0x0c0ad762u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0ad764;
P_0c0ad764: /* original 6073, guest PC 0x0c0ad764 */
if(!s->budget--) { s->failed_pc=0x0c0ad764u; return 0; }
r[0]=r[7];
goto P_0c0ad766;
P_0c0ad766: /* original 4008, guest PC 0x0c0ad766 */
if(!s->budget--) { s->failed_pc=0x0c0ad766u; return 0; }
r[0]<<=2;
goto P_0c0ad768;
P_0c0ad768: /* original f736, guest PC 0x0c0ad768 */
if(!s->budget--) { s->failed_pc=0x0c0ad768u; return 0; }
vf3_matrix_load(s,ram,7,r[3]+r[0]);
goto P_0c0ad76a;
P_0c0ad76a: /* original 6033, guest PC 0x0c0ad76a */
if(!s->budget--) { s->failed_pc=0x0c0ad76au; return 0; }
r[0]=r[3];
goto P_0c0ad76c;
P_0c0ad76c: /* original e302, guest PC 0x0c0ad76c */
if(!s->budget--) { s->failed_pc=0x0c0ad76cu; return 0; }
r[3]=0x00000002u;
goto P_0c0ad76e;
P_0c0ad76e: /* original 7701, guest PC 0x0c0ad76e */
if(!s->budget--) { s->failed_pc=0x0c0ad76eu; return 0; }
r[7]+=0x00000001u;
goto P_0c0ad770;
P_0c0ad770: /* original 3633, guest PC 0x0c0ad770 */
if(!s->budget--) { s->failed_pc=0x0c0ad770u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[3])!=0);
goto P_0c0ad772;
P_0c0ad772: /* original 4708, guest PC 0x0c0ad772 */
if(!s->budget--) { s->failed_pc=0x0c0ad772u; return 0; }
r[7]<<=2;
goto P_0c0ad774;
P_0c0ad774: /* original 8d09, guest PC 0x0c0ad774 */
if(!s->budget--) { s->failed_pc=0x0c0ad774u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,8,r[7]+r[0]);
if(cond) { goto P_0c0ad78a; }
goto P_0c0ad778;
P_0c0ad776: /* original f876, guest PC 0x0c0ad776 */
if(!s->budget--) { s->failed_pc=0x0c0ad776u; return 0; }
vf3_matrix_load(s,ram,8,r[7]+r[0]);
goto P_0c0ad778;
P_0c0ad778: /* original e061, guest PC 0x0c0ad778 */
if(!s->budget--) { s->failed_pc=0x0c0ad778u; return 0; }
r[0]=0x00000061u;
goto P_0c0ad77a;
P_0c0ad77a: /* original 015c, guest PC 0x0c0ad77a */
if(!s->budget--) { s->failed_pc=0x0c0ad77au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0ad77c;
P_0c0ad77c: /* original d038, guest PC 0x0c0ad77c */
if(!s->budget--) { s->failed_pc=0x0c0ad77cu; return 0; }
r[0]=read(ram,0x0c0ad860u,4);
goto P_0c0ad77e;
P_0c0ad77e: /* original 611c, guest PC 0x0c0ad77e */
if(!s->budget--) { s->failed_pc=0x0c0ad77eu; return 0; }
r[1]=r[1]&255u;
goto P_0c0ad780;
P_0c0ad780: /* original 4100, guest PC 0x0c0ad780 */
if(!s->budget--) { s->failed_pc=0x0c0ad780u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c0ad782;
P_0c0ad782: /* original 316c, guest PC 0x0c0ad782 */
if(!s->budget--) { s->failed_pc=0x0c0ad782u; return 0; }
r[1]+=r[6];
goto P_0c0ad784;
P_0c0ad784: /* original 4108, guest PC 0x0c0ad784 */
if(!s->budget--) { s->failed_pc=0x0c0ad784u; return 0; }
r[1]<<=2;
goto P_0c0ad786;
P_0c0ad786: /* original f316, guest PC 0x0c0ad786 */
if(!s->budget--) { s->failed_pc=0x0c0ad786u; return 0; }
vf3_matrix_load(s,ram,3,r[1]+r[0]);
goto P_0c0ad788;
P_0c0ad788: /* original f430, guest PC 0x0c0ad788 */
if(!s->budget--) { s->failed_pc=0x0c0ad788u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ad78a;
P_0c0ad78a: /* original c736, guest PC 0x0c0ad78a */
if(!s->budget--) { s->failed_pc=0x0c0ad78au; return 0; }
r[0]=code_base|0x000ad864u;
goto P_0c0ad78c;
P_0c0ad78c: /* original f308, guest PC 0x0c0ad78c */
if(!s->budget--) { s->failed_pc=0x0c0ad78cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ad78e;
P_0c0ad78e: /* original e05c, guest PC 0x0c0ad78e */
if(!s->budget--) { s->failed_pc=0x0c0ad78eu; return 0; }
r[0]=0x0000005cu;
goto P_0c0ad790;
P_0c0ad790: /* original f246, guest PC 0x0c0ad790 */
if(!s->budget--) { s->failed_pc=0x0c0ad790u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0ad792;
P_0c0ad792: /* original f432, guest PC 0x0c0ad792 */
if(!s->budget--) { s->failed_pc=0x0c0ad792u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0ad794;
P_0c0ad794: /* original f423, guest PC 0x0c0ad794 */
if(!s->budget--) { s->failed_pc=0x0c0ad794u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0ad796;
P_0c0ad796: /* original f28d, guest PC 0x0c0ad796 */
if(!s->budget--) { s->failed_pc=0x0c0ad796u; return 0; }
fr[2]=0;
goto P_0c0ad798;
P_0c0ad798: /* original f94c, guest PC 0x0c0ad798 */
if(!s->budget--) { s->failed_pc=0x0c0ad798u; return 0; }
vf3_matrix_move(s,9,4);
goto P_0c0ad79a;
P_0c0ad79a: /* original f971, guest PC 0x0c0ad79a */
if(!s->budget--) { s->failed_pc=0x0c0ad79au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[7],r[18],'-');
goto P_0c0ad79c;
P_0c0ad79c: /* original f295, guest PC 0x0c0ad79c */
if(!s->budget--) { s->failed_pc=0x0c0ad79cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[9]))!=0);
goto P_0c0ad79e;
P_0c0ad79e: /* original 8b00, guest PC 0x0c0ad79e */
if(!s->budget--) { s->failed_pc=0x0c0ad79eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ad7a2; }
goto P_0c0ad7a0;
P_0c0ad7a0: /* original f47c, guest PC 0x0c0ad7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad7a0u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0ad7a2;
P_0c0ad7a2: /* original f74c, guest PC 0x0c0ad7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad7a2u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0ad7a4;
P_0c0ad7a4: /* original f781, guest PC 0x0c0ad7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad7a4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c0ad7a6;
P_0c0ad7a6: /* original f38d, guest PC 0x0c0ad7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad7a6u; return 0; }
fr[3]=0;
goto P_0c0ad7a8;
P_0c0ad7a8: /* original f375, guest PC 0x0c0ad7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad7a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c0ad7aa;
P_0c0ad7aa: /* original 8d01, guest PC 0x0c0ad7aa */
if(!s->budget--) { s->failed_pc=0x0c0ad7aau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,6);
if(cond) { goto P_0c0ad7b0; }
goto P_0c0ad7ae;
P_0c0ad7ac: /* original f36c, guest PC 0x0c0ad7ac */
if(!s->budget--) { s->failed_pc=0x0c0ad7acu; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0ad7ae;
P_0c0ad7ae: /* original f48c, guest PC 0x0c0ad7ae */
if(!s->budget--) { s->failed_pc=0x0c0ad7aeu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0ad7b0;
P_0c0ad7b0: /* original f64c, guest PC 0x0c0ad7b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad7b0u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c0ad7b2;
P_0c0ad7b2: /* original f633, guest PC 0x0c0ad7b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad7b2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c0ad7b4;
P_0c0ad7b4: /* original f453, guest PC 0x0c0ad7b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad7b4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c0ad7b6;
P_0c0ad7b6: /* original 9048, guest PC 0x0c0ad7b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad7b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad84au,2);
goto P_0c0ad7b8;
P_0c0ad7b8: /* original f467, guest PC 0x0c0ad7b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad7b8u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c0ad7ba;
P_0c0ad7ba: /* original 7004, guest PC 0x0c0ad7ba */
if(!s->budget--) { s->failed_pc=0x0c0ad7bau; return 0; }
r[0]+=0x00000004u;
goto P_0c0ad7bc;
P_0c0ad7bc: /* original a003, guest PC 0x0c0ad7bc */
if(!s->budget--) { s->failed_pc=0x0c0ad7bcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad7c6;
P_0c0ad7be: /* original f447, guest PC 0x0c0ad7be */
if(!s->budget--) { s->failed_pc=0x0c0ad7beu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad7c0;
P_0c0ad7c0: /* original 9044, guest PC 0x0c0ad7c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad7c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad84cu,2);
goto P_0c0ad7c2;
P_0c0ad7c2: /* original e200, guest PC 0x0c0ad7c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad7c2u; return 0; }
r[2]=0x00000000u;
goto P_0c0ad7c4;
P_0c0ad7c4: /* original 0424, guest PC 0x0c0ad7c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad7c4u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ad7c6;
P_0c0ad7c6: /* original 7f08, guest PC 0x0c0ad7c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad7c6u; return 0; }
r[15]+=0x00000008u;
goto P_0c0ad7c8;
P_0c0ad7c8: /* original 4f26, guest PC 0x0c0ad7c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad7c8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad7ca;
P_0c0ad7ca: /* original 6bf6, guest PC 0x0c0ad7ca */
if(!s->budget--) { s->failed_pc=0x0c0ad7cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ad7cc;
P_0c0ad7cc: /* original 6cf6, guest PC 0x0c0ad7cc */
if(!s->budget--) { s->failed_pc=0x0c0ad7ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad7ce;
P_0c0ad7ce: /* original 6df6, guest PC 0x0c0ad7ce */
if(!s->budget--) { s->failed_pc=0x0c0ad7ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad7d0;
P_0c0ad7d0: /* original 000b, guest PC 0x0c0ad7d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad7d0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad7d2: /* original 6ef6, guest PC 0x0c0ad7d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad7d2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ad7d4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ad7d4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
