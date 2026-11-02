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
int vf3_away_batch134_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09f6d0u: goto P_0c09f6d0;
case 0x0c09f6d2u: goto P_0c09f6d2;
case 0x0c09f6d4u: goto P_0c09f6d4;
case 0x0c09f6d6u: goto P_0c09f6d6;
case 0x0c09f6d8u: goto P_0c09f6d8;
case 0x0c09f6dau: goto P_0c09f6da;
case 0x0c09f6dcu: goto P_0c09f6dc;
case 0x0c09f6deu: goto P_0c09f6de;
case 0x0c09f6e0u: goto P_0c09f6e0;
case 0x0c09f6e2u: goto P_0c09f6e2;
case 0x0c09f6e4u: goto P_0c09f6e4;
case 0x0c09f6e6u: goto P_0c09f6e6;
case 0x0c09f6e8u: goto P_0c09f6e8;
case 0x0c09f6eau: goto P_0c09f6ea;
case 0x0c09f6ecu: goto P_0c09f6ec;
case 0x0c09f6eeu: goto P_0c09f6ee;
case 0x0c09f6f0u: goto P_0c09f6f0;
case 0x0c09f6f2u: goto P_0c09f6f2;
case 0x0c09f6f4u: goto P_0c09f6f4;
case 0x0c09f6f6u: goto P_0c09f6f6;
case 0x0c09f6f8u: goto P_0c09f6f8;
case 0x0c09f6fau: goto P_0c09f6fa;
case 0x0c09f6fcu: goto P_0c09f6fc;
case 0x0c09f6feu: goto P_0c09f6fe;
case 0x0c09f700u: goto P_0c09f700;
case 0x0c09f702u: goto P_0c09f702;
case 0x0c09f704u: goto P_0c09f704;
case 0x0c09f706u: goto P_0c09f706;
case 0x0c09f708u: goto P_0c09f708;
case 0x0c09f70au: goto P_0c09f70a;
case 0x0c09f70cu: goto P_0c09f70c;
case 0x0c09f70eu: goto P_0c09f70e;
case 0x0c09f710u: goto P_0c09f710;
case 0x0c09f712u: goto P_0c09f712;
case 0x0c09f714u: goto P_0c09f714;
case 0x0c09f716u: goto P_0c09f716;
case 0x0c09f718u: goto P_0c09f718;
case 0x0c09f71au: goto P_0c09f71a;
case 0x0c09f71cu: goto P_0c09f71c;
case 0x0c09f71eu: goto P_0c09f71e;
case 0x0c09f720u: goto P_0c09f720;
case 0x0c09f722u: goto P_0c09f722;
case 0x0c09f724u: goto P_0c09f724;
case 0x0c09f726u: goto P_0c09f726;
case 0x0c09f728u: goto P_0c09f728;
case 0x0c09f72au: goto P_0c09f72a;
case 0x0c09f72cu: goto P_0c09f72c;
case 0x0c09f72eu: goto P_0c09f72e;
case 0x0c09f730u: goto P_0c09f730;
case 0x0c09f732u: goto P_0c09f732;
case 0x0c09f734u: goto P_0c09f734;
case 0x0c09f736u: goto P_0c09f736;
case 0x0c09f738u: goto P_0c09f738;
case 0x0c09f73au: goto P_0c09f73a;
case 0x0c09f73cu: goto P_0c09f73c;
case 0x0c09f73eu: goto P_0c09f73e;
case 0x0c09f740u: goto P_0c09f740;
case 0x0c09f742u: goto P_0c09f742;
case 0x0c09f744u: goto P_0c09f744;
case 0x0c09f746u: goto P_0c09f746;
case 0x0c09f748u: goto P_0c09f748;
case 0x0c09f74au: goto P_0c09f74a;
case 0x0c09f74cu: goto P_0c09f74c;
case 0x0c09f74eu: goto P_0c09f74e;
case 0x0c09f750u: goto P_0c09f750;
case 0x0c09f752u: goto P_0c09f752;
case 0x0c09f754u: goto P_0c09f754;
case 0x0c09f756u: goto P_0c09f756;
case 0x0c09f758u: goto P_0c09f758;
case 0x0c09f75au: goto P_0c09f75a;
case 0x0c09f75cu: goto P_0c09f75c;
case 0x0c09f75eu: goto P_0c09f75e;
case 0x0c09f760u: goto P_0c09f760;
case 0x0c09f762u: goto P_0c09f762;
case 0x0c09f764u: goto P_0c09f764;
case 0x0c09f766u: goto P_0c09f766;
case 0x0c09f768u: goto P_0c09f768;
case 0x0c09f76au: goto P_0c09f76a;
case 0x0c09f76cu: goto P_0c09f76c;
case 0x0c09f76eu: goto P_0c09f76e;
case 0x0c09f770u: goto P_0c09f770;
case 0x0c09f772u: goto P_0c09f772;
case 0x0c09f774u: goto P_0c09f774;
case 0x0c09f776u: goto P_0c09f776;
case 0x0c09f778u: goto P_0c09f778;
case 0x0c09f77au: goto P_0c09f77a;
case 0x0c09f77cu: goto P_0c09f77c;
case 0x0c09f77eu: goto P_0c09f77e;
case 0x0c09f780u: goto P_0c09f780;
case 0x0c09f782u: goto P_0c09f782;
case 0x0c09f784u: goto P_0c09f784;
case 0x0c09f786u: goto P_0c09f786;
case 0x0c09f788u: goto P_0c09f788;
case 0x0c09f78au: goto P_0c09f78a;
case 0x0c09f78cu: goto P_0c09f78c;
case 0x0c09f78eu: goto P_0c09f78e;
case 0x0c09f790u: goto P_0c09f790;
case 0x0c09f792u: goto P_0c09f792;
case 0x0c09f794u: goto P_0c09f794;
case 0x0c09f796u: goto P_0c09f796;
case 0x0c09f798u: goto P_0c09f798;
case 0x0c09f79au: goto P_0c09f79a;
case 0x0c09f79cu: goto P_0c09f79c;
case 0x0c09f79eu: goto P_0c09f79e;
case 0x0c09f7a0u: goto P_0c09f7a0;
case 0x0c09f7a2u: goto P_0c09f7a2;
case 0x0c09f7a4u: goto P_0c09f7a4;
case 0x0c09f7a6u: goto P_0c09f7a6;
case 0x0c09f7a8u: goto P_0c09f7a8;
case 0x0c09f7aau: goto P_0c09f7aa;
case 0x0c09f7acu: goto P_0c09f7ac;
case 0x0c09f7aeu: goto P_0c09f7ae;
case 0x0c09f7b0u: goto P_0c09f7b0;
case 0x0c09f7b2u: goto P_0c09f7b2;
case 0x0c09f7d4u: goto P_0c09f7d4;
case 0x0c09f7d6u: goto P_0c09f7d6;
case 0x0c09f7d8u: goto P_0c09f7d8;
case 0x0c09f7dau: goto P_0c09f7da;
case 0x0c09f7dcu: goto P_0c09f7dc;
case 0x0c09f7deu: goto P_0c09f7de;
case 0x0c09f7e0u: goto P_0c09f7e0;
case 0x0c09f7e2u: goto P_0c09f7e2;
case 0x0c09f7e4u: goto P_0c09f7e4;
case 0x0c09f7e6u: goto P_0c09f7e6;
case 0x0c09f7e8u: goto P_0c09f7e8;
case 0x0c09f7eau: goto P_0c09f7ea;
case 0x0c09f7ecu: goto P_0c09f7ec;
case 0x0c09f7eeu: goto P_0c09f7ee;
case 0x0c09f7f0u: goto P_0c09f7f0;
case 0x0c09f7f2u: goto P_0c09f7f2;
case 0x0c09f7f4u: goto P_0c09f7f4;
case 0x0c09f7f6u: goto P_0c09f7f6;
case 0x0c09f7f8u: goto P_0c09f7f8;
case 0x0c09f7fau: goto P_0c09f7fa;
case 0x0c09f7fcu: goto P_0c09f7fc;
case 0x0c09f7feu: goto P_0c09f7fe;
case 0x0c09f800u: goto P_0c09f800;
case 0x0c09f802u: goto P_0c09f802;
case 0x0c09f804u: goto P_0c09f804;
case 0x0c09f806u: goto P_0c09f806;
case 0x0c09f808u: goto P_0c09f808;
case 0x0c09f80au: goto P_0c09f80a;
case 0x0c09f80cu: goto P_0c09f80c;
case 0x0c09f80eu: goto P_0c09f80e;
case 0x0c09f810u: goto P_0c09f810;
case 0x0c09f812u: goto P_0c09f812;
case 0x0c09f814u: goto P_0c09f814;
case 0x0c09f816u: goto P_0c09f816;
case 0x0c09f818u: goto P_0c09f818;
case 0x0c09f83cu: goto P_0c09f83c;
case 0x0c09f83eu: goto P_0c09f83e;
case 0x0c09f840u: goto P_0c09f840;
case 0x0c09f842u: goto P_0c09f842;
case 0x0c09f844u: goto P_0c09f844;
case 0x0c09f846u: goto P_0c09f846;
case 0x0c09f848u: goto P_0c09f848;
case 0x0c09f84au: goto P_0c09f84a;
case 0x0c09f84cu: goto P_0c09f84c;
case 0x0c09f84eu: goto P_0c09f84e;
case 0x0c09f850u: goto P_0c09f850;
case 0x0c09f852u: goto P_0c09f852;
case 0x0c09f854u: goto P_0c09f854;
case 0x0c09f856u: goto P_0c09f856;
case 0x0c09f858u: goto P_0c09f858;
case 0x0c09f85au: goto P_0c09f85a;
case 0x0c09f85cu: goto P_0c09f85c;
case 0x0c09f85eu: goto P_0c09f85e;
case 0x0c09f860u: goto P_0c09f860;
case 0x0c09f862u: goto P_0c09f862;
case 0x0c09f864u: goto P_0c09f864;
case 0x0c09f866u: goto P_0c09f866;
case 0x0c09f868u: goto P_0c09f868;
case 0x0c09f86au: goto P_0c09f86a;
case 0x0c09f86cu: goto P_0c09f86c;
case 0x0c09f86eu: goto P_0c09f86e;
case 0x0c09f870u: goto P_0c09f870;
case 0x0c09f872u: goto P_0c09f872;
case 0x0c09f874u: goto P_0c09f874;
case 0x0c09f876u: goto P_0c09f876;
case 0x0c09f878u: goto P_0c09f878;
case 0x0c09f87au: goto P_0c09f87a;
case 0x0c09f87cu: goto P_0c09f87c;
case 0x0c09f87eu: goto P_0c09f87e;
case 0x0c09f880u: goto P_0c09f880;
case 0x0c09f882u: goto P_0c09f882;
case 0x0c09f884u: goto P_0c09f884;
case 0x0c09f886u: goto P_0c09f886;
case 0x0c09f888u: goto P_0c09f888;
case 0x0c09f88au: goto P_0c09f88a;
case 0x0c09f88cu: goto P_0c09f88c;
case 0x0c09f88eu: goto P_0c09f88e;
case 0x0c09f8d8u: goto P_0c09f8d8;
case 0x0c09f8dau: goto P_0c09f8da;
case 0x0c09f8dcu: goto P_0c09f8dc;
case 0x0c09f8deu: goto P_0c09f8de;
case 0x0c09f8e0u: goto P_0c09f8e0;
case 0x0c09f8e2u: goto P_0c09f8e2;
case 0x0c09f8e4u: goto P_0c09f8e4;
case 0x0c09f8e6u: goto P_0c09f8e6;
case 0x0c09f8e8u: goto P_0c09f8e8;
case 0x0c09f8eau: goto P_0c09f8ea;
case 0x0c09f8ecu: goto P_0c09f8ec;
case 0x0c09f8eeu: goto P_0c09f8ee;
case 0x0c09f8f0u: goto P_0c09f8f0;
case 0x0c09f8f2u: goto P_0c09f8f2;
case 0x0c09f8f4u: goto P_0c09f8f4;
case 0x0c09f8f6u: goto P_0c09f8f6;
case 0x0c09f8f8u: goto P_0c09f8f8;
case 0x0c09f8fau: goto P_0c09f8fa;
case 0x0c09f8fcu: goto P_0c09f8fc;
case 0x0c09f8feu: goto P_0c09f8fe;
case 0x0c09f900u: goto P_0c09f900;
case 0x0c09f902u: goto P_0c09f902;
case 0x0c09f904u: goto P_0c09f904;
case 0x0c09f906u: goto P_0c09f906;
case 0x0c09f908u: goto P_0c09f908;
case 0x0c09f90au: goto P_0c09f90a;
case 0x0c09f90cu: goto P_0c09f90c;
case 0x0c09f90eu: goto P_0c09f90e;
case 0x0c09f910u: goto P_0c09f910;
case 0x0c09f912u: goto P_0c09f912;
case 0x0c09f914u: goto P_0c09f914;
case 0x0c09f916u: goto P_0c09f916;
case 0x0c09f918u: goto P_0c09f918;
case 0x0c09f91au: goto P_0c09f91a;
case 0x0c09f91cu: goto P_0c09f91c;
case 0x0c09f91eu: goto P_0c09f91e;
case 0x0c09f920u: goto P_0c09f920;
case 0x0c09f922u: goto P_0c09f922;
case 0x0c09f924u: goto P_0c09f924;
case 0x0c09f926u: goto P_0c09f926;
case 0x0c09f928u: goto P_0c09f928;
case 0x0c09f92au: goto P_0c09f92a;
case 0x0c09f92cu: goto P_0c09f92c;
case 0x0c09f92eu: goto P_0c09f92e;
case 0x0c09f930u: goto P_0c09f930;
case 0x0c09f932u: goto P_0c09f932;
case 0x0c09f934u: goto P_0c09f934;
case 0x0c09f936u: goto P_0c09f936;
case 0x0c09f938u: goto P_0c09f938;
case 0x0c09f93au: goto P_0c09f93a;
case 0x0c09f93cu: goto P_0c09f93c;
case 0x0c09f93eu: goto P_0c09f93e;
case 0x0c09f940u: goto P_0c09f940;
case 0x0c09f942u: goto P_0c09f942;
case 0x0c09f944u: goto P_0c09f944;
case 0x0c09f946u: goto P_0c09f946;
case 0x0c09f948u: goto P_0c09f948;
case 0x0c09f94au: goto P_0c09f94a;
case 0x0c09f94cu: goto P_0c09f94c;
case 0x0c09f94eu: goto P_0c09f94e;
case 0x0c09f950u: goto P_0c09f950;
case 0x0c09f952u: goto P_0c09f952;
case 0x0c09f954u: goto P_0c09f954;
case 0x0c09f956u: goto P_0c09f956;
case 0x0c09f958u: goto P_0c09f958;
case 0x0c09f95au: goto P_0c09f95a;
case 0x0c09f95cu: goto P_0c09f95c;
case 0x0c09f95eu: goto P_0c09f95e;
case 0x0c09f960u: goto P_0c09f960;
case 0x0c09f962u: goto P_0c09f962;
case 0x0c09f964u: goto P_0c09f964;
case 0x0c09f966u: goto P_0c09f966;
case 0x0c09f968u: goto P_0c09f968;
case 0x0c09f96au: goto P_0c09f96a;
case 0x0c09f96cu: goto P_0c09f96c;
case 0x0c09f96eu: goto P_0c09f96e;
case 0x0c09f970u: goto P_0c09f970;
case 0x0c09f972u: goto P_0c09f972;
case 0x0c09f974u: goto P_0c09f974;
case 0x0c09f976u: goto P_0c09f976;
case 0x0c09f978u: goto P_0c09f978;
case 0x0c09f97au: goto P_0c09f97a;
case 0x0c09f97cu: goto P_0c09f97c;
case 0x0c09f97eu: goto P_0c09f97e;
case 0x0c09f980u: goto P_0c09f980;
case 0x0c09f982u: goto P_0c09f982;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09f6d0: /* original 2fe6, guest PC 0x0c09f6d0 */
if(!s->budget--) { s->failed_pc=0x0c09f6d0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d2;
P_0c09f6d2: /* original 2fd6, guest PC 0x0c09f6d2 */
if(!s->budget--) { s->failed_pc=0x0c09f6d2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d4;
P_0c09f6d4: /* original ed0e, guest PC 0x0c09f6d4 */
if(!s->budget--) { s->failed_pc=0x0c09f6d4u; return 0; }
r[13]=0x0000000eu;
goto P_0c09f6d6;
P_0c09f6d6: /* original 2fc6, guest PC 0x0c09f6d6 */
if(!s->budget--) { s->failed_pc=0x0c09f6d6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09f6d8;
P_0c09f6d8: /* original 9c6d, guest PC 0x0c09f6d8 */
if(!s->budget--) { s->failed_pc=0x0c09f6d8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b6u,2);
goto P_0c09f6da;
P_0c09f6da: /* original 9e6b, guest PC 0x0c09f6da */
if(!s->budget--) { s->failed_pc=0x0c09f6dau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f7b4u,2);
goto P_0c09f6dc;
P_0c09f6dc: /* original 4f22, guest PC 0x0c09f6dc */
if(!s->budget--) { s->failed_pc=0x0c09f6dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09f6de;
P_0c09f6de: /* original 3c4c, guest PC 0x0c09f6de */
if(!s->budget--) { s->failed_pc=0x0c09f6deu; return 0; }
r[12]+=r[4];
goto P_0c09f6e0;
P_0c09f6e0: /* original 3e4c, guest PC 0x0c09f6e0 */
if(!s->budget--) { s->failed_pc=0x0c09f6e0u; return 0; }
r[14]+=r[4];
goto P_0c09f6e2;
P_0c09f6e2: /* original 65c3, guest PC 0x0c09f6e2 */
if(!s->budget--) { s->failed_pc=0x0c09f6e2u; return 0; }
r[5]=r[12];
goto P_0c09f6e4;
P_0c09f6e4: /* original b00a, guest PC 0x0c09f6e4 */
if(!s->budget--) { s->failed_pc=0x0c09f6e4u; return 0; }
target=code_base|0x0c09f6fcu; r[16]=code_base|0x0c09f6e8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09f6e8u) { target=s->pc; goto dispatch; }
goto P_0c09f6e8;
P_0c09f6e6: /* original 64e3, guest PC 0x0c09f6e6 */
if(!s->budget--) { s->failed_pc=0x0c09f6e6u; return 0; }
r[4]=r[14];
goto P_0c09f6e8;
P_0c09f6e8: /* original 7dff, guest PC 0x0c09f6e8 */
if(!s->budget--) { s->failed_pc=0x0c09f6e8u; return 0; }
r[13]+=0xffffffffu;
goto P_0c09f6ea;
P_0c09f6ea: /* original 4d15, guest PC 0x0c09f6ea */
if(!s->budget--) { s->failed_pc=0x0c09f6eau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c09f6ec;
P_0c09f6ec: /* original 7e0c, guest PC 0x0c09f6ec */
if(!s->budget--) { s->failed_pc=0x0c09f6ecu; return 0; }
r[14]+=0x0000000cu;
goto P_0c09f6ee;
P_0c09f6ee: /* original 8df8, guest PC 0x0c09f6ee */
if(!s->budget--) { s->failed_pc=0x0c09f6eeu; return 0; }
cond=r[17]&1u;
r[12]+=0x0000000cu;
if(cond) { goto P_0c09f6e2; }
goto P_0c09f6f2;
P_0c09f6f0: /* original 7c0c, guest PC 0x0c09f6f0 */
if(!s->budget--) { s->failed_pc=0x0c09f6f0u; return 0; }
r[12]+=0x0000000cu;
goto P_0c09f6f2;
P_0c09f6f2: /* original 4f26, guest PC 0x0c09f6f2 */
if(!s->budget--) { s->failed_pc=0x0c09f6f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09f6f4;
P_0c09f6f4: /* original 6cf6, guest PC 0x0c09f6f4 */
if(!s->budget--) { s->failed_pc=0x0c09f6f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09f6f6;
P_0c09f6f6: /* original 6df6, guest PC 0x0c09f6f6 */
if(!s->budget--) { s->failed_pc=0x0c09f6f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09f6f8;
P_0c09f6f8: /* original 000b, guest PC 0x0c09f6f8 */
if(!s->budget--) { s->failed_pc=0x0c09f6f8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09f6fa: /* original 6ef6, guest PC 0x0c09f6fa */
if(!s->budget--) { s->failed_pc=0x0c09f6fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09f6fc;
P_0c09f6fc: /* original c72e, guest PC 0x0c09f6fc */
if(!s->budget--) { s->failed_pc=0x0c09f6fcu; return 0; }
r[0]=code_base|0x0009f7b8u;
goto P_0c09f6fe;
P_0c09f6fe: /* original ffdb, guest PC 0x0c09f6fe */
if(!s->budget--) { s->failed_pc=0x0c09f6feu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09f700;
P_0c09f700: /* original f908, guest PC 0x0c09f700 */
if(!s->budget--) { s->failed_pc=0x0c09f700u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c09f702;
P_0c09f702: /* original c72e, guest PC 0x0c09f702 */
if(!s->budget--) { s->failed_pc=0x0c09f702u; return 0; }
r[0]=code_base|0x0009f7bcu;
goto P_0c09f704;
P_0c09f704: /* original fa08, guest PC 0x0c09f704 */
if(!s->budget--) { s->failed_pc=0x0c09f704u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c09f706;
P_0c09f706: /* original c72e, guest PC 0x0c09f706 */
if(!s->budget--) { s->failed_pc=0x0c09f706u; return 0; }
r[0]=code_base|0x0009f7c0u;
goto P_0c09f708;
P_0c09f708: /* original fb08, guest PC 0x0c09f708 */
if(!s->budget--) { s->failed_pc=0x0c09f708u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c09f70a;
P_0c09f70a: /* original c72e, guest PC 0x0c09f70a */
if(!s->budget--) { s->failed_pc=0x0c09f70au; return 0; }
r[0]=code_base|0x0009f7c4u;
goto P_0c09f70c;
P_0c09f70c: /* original f808, guest PC 0x0c09f70c */
if(!s->budget--) { s->failed_pc=0x0c09f70cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c09f70e;
P_0c09f70e: /* original c72e, guest PC 0x0c09f70e */
if(!s->budget--) { s->failed_pc=0x0c09f70eu; return 0; }
r[0]=code_base|0x0009f7c8u;
goto P_0c09f710;
P_0c09f710: /* original f708, guest PC 0x0c09f710 */
if(!s->budget--) { s->failed_pc=0x0c09f710u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09f712;
P_0c09f712: /* original e004, guest PC 0x0c09f712 */
if(!s->budget--) { s->failed_pc=0x0c09f712u; return 0; }
r[0]=0x00000004u;
goto P_0c09f714;
P_0c09f714: /* original f348, guest PC 0x0c09f714 */
if(!s->budget--) { s->failed_pc=0x0c09f714u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09f716;
P_0c09f716: /* original 7ff4, guest PC 0x0c09f716 */
if(!s->budget--) { s->failed_pc=0x0c09f716u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c09f718;
P_0c09f718: /* original 6653, guest PC 0x0c09f718 */
if(!s->budget--) { s->failed_pc=0x0c09f718u; return 0; }
r[6]=r[5];
goto P_0c09f71a;
P_0c09f71a: /* original 7604, guest PC 0x0c09f71a */
if(!s->budget--) { s->failed_pc=0x0c09f71au; return 0; }
r[6]+=0x00000004u;
goto P_0c09f71c;
P_0c09f71c: /* original ff37, guest PC 0x0c09f71c */
if(!s->budget--) { s->failed_pc=0x0c09f71cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f71e;
P_0c09f71e: /* original e004, guest PC 0x0c09f71e */
if(!s->budget--) { s->failed_pc=0x0c09f71eu; return 0; }
r[0]=0x00000004u;
goto P_0c09f720;
P_0c09f720: /* original f346, guest PC 0x0c09f720 */
if(!s->budget--) { s->failed_pc=0x0c09f720u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f722;
P_0c09f722: /* original e008, guest PC 0x0c09f722 */
if(!s->budget--) { s->failed_pc=0x0c09f722u; return 0; }
r[0]=0x00000008u;
goto P_0c09f724;
P_0c09f724: /* original f558, guest PC 0x0c09f724 */
if(!s->budget--) { s->failed_pc=0x0c09f724u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
goto P_0c09f726;
P_0c09f726: /* original ff3a, guest PC 0x0c09f726 */
if(!s->budget--) { s->failed_pc=0x0c09f726u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c09f728;
P_0c09f728: /* original f346, guest PC 0x0c09f728 */
if(!s->budget--) { s->failed_pc=0x0c09f728u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f72a;
P_0c09f72a: /* original 6453, guest PC 0x0c09f72a */
if(!s->budget--) { s->failed_pc=0x0c09f72au; return 0; }
r[4]=r[5];
goto P_0c09f72c;
P_0c09f72c: /* original 7408, guest PC 0x0c09f72c */
if(!s->budget--) { s->failed_pc=0x0c09f72cu; return 0; }
r[4]+=0x00000008u;
goto P_0c09f72e;
P_0c09f72e: /* original f668, guest PC 0x0c09f72e */
if(!s->budget--) { s->failed_pc=0x0c09f72eu; return 0; }
vf3_matrix_load(s,ram,6,r[6]);
goto P_0c09f730;
P_0c09f730: /* original e008, guest PC 0x0c09f730 */
if(!s->budget--) { s->failed_pc=0x0c09f730u; return 0; }
r[0]=0x00000008u;
goto P_0c09f732;
P_0c09f732: /* original ff37, guest PC 0x0c09f732 */
if(!s->budget--) { s->failed_pc=0x0c09f732u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09f734;
P_0c09f734: /* original f448, guest PC 0x0c09f734 */
if(!s->budget--) { s->failed_pc=0x0c09f734u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c09f736;
P_0c09f736: /* original e004, guest PC 0x0c09f736 */
if(!s->budget--) { s->failed_pc=0x0c09f736u; return 0; }
r[0]=0x00000004u;
goto P_0c09f738;
P_0c09f738: /* original f28d, guest PC 0x0c09f738 */
if(!s->budget--) { s->failed_pc=0x0c09f738u; return 0; }
fr[2]=0;
goto P_0c09f73a;
P_0c09f73a: /* original f1f6, guest PC 0x0c09f73a */
if(!s->budget--) { s->failed_pc=0x0c09f73au; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c09f73c;
P_0c09f73c: /* original c723, guest PC 0x0c09f73c */
if(!s->budget--) { s->failed_pc=0x0c09f73cu; return 0; }
r[0]=code_base|0x0009f7ccu;
goto P_0c09f73e;
P_0c09f73e: /* original f151, guest PC 0x0c09f73e */
if(!s->budget--) { s->failed_pc=0x0c09f73eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[5],r[18],'-');
goto P_0c09f740;
P_0c09f740: /* original f01c, guest PC 0x0c09f740 */
if(!s->budget--) { s->failed_pc=0x0c09f740u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c09f742;
P_0c09f742: /* original f05d, guest PC 0x0c09f742 */
if(!s->budget--) { s->failed_pc=0x0c09f742u; return 0; }
fr[0]&=0x7fffffffu;
goto P_0c09f744;
P_0c09f744: /* original f705, guest PC 0x0c09f744 */
if(!s->budget--) { s->failed_pc=0x0c09f744u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[0]))!=0);
goto P_0c09f746;
P_0c09f746: /* original 8f17, guest PC 0x0c09f746 */
if(!s->budget--) { s->failed_pc=0x0c09f746u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,13,r[0]);
if(!cond) { goto P_0c09f778; }
goto P_0c09f74a;
P_0c09f748: /* original fd08, guest PC 0x0c09f748 */
if(!s->budget--) { s->failed_pc=0x0c09f748u; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c09f74a;
P_0c09f74a: /* original f805, guest PC 0x0c09f74a */
if(!s->budget--) { s->failed_pc=0x0c09f74au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c09f74c;
P_0c09f74c: /* original 8b08, guest PC 0x0c09f74c */
if(!s->budget--) { s->failed_pc=0x0c09f74cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f760; }
goto P_0c09f74e;
P_0c09f74e: /* original f905, guest PC 0x0c09f74e */
if(!s->budget--) { s->failed_pc=0x0c09f74eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[0]))!=0);
goto P_0c09f750;
P_0c09f750: /* original 8913, guest PC 0x0c09f750 */
if(!s->budget--) { s->failed_pc=0x0c09f750u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f77a; }
goto P_0c09f752;
P_0c09f752: /* original f38d, guest PC 0x0c09f752 */
if(!s->budget--) { s->failed_pc=0x0c09f752u; return 0; }
fr[3]=0;
goto P_0c09f754;
P_0c09f754: /* original f315, guest PC 0x0c09f754 */
if(!s->budget--) { s->failed_pc=0x0c09f754u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f756;
P_0c09f756: /* original 8901, guest PC 0x0c09f756 */
if(!s->budget--) { s->failed_pc=0x0c09f756u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f75c; }
goto P_0c09f758;
P_0c09f758: /* original a009, guest PC 0x0c09f758 */
if(!s->budget--) { s->failed_pc=0x0c09f758u; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f76e;
P_0c09f75a: /* original f1ac, guest PC 0x0c09f75a */
if(!s->budget--) { s->failed_pc=0x0c09f75au; return 0; }
vf3_matrix_move(s,1,10);
goto P_0c09f75c;
P_0c09f75c: /* original a007, guest PC 0x0c09f75c */
if(!s->budget--) { s->failed_pc=0x0c09f75cu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f76e;
P_0c09f75e: /* original f1dc, guest PC 0x0c09f75e */
if(!s->budget--) { s->failed_pc=0x0c09f75eu; return 0; }
vf3_matrix_move(s,1,13);
goto P_0c09f760;
P_0c09f760: /* original f38d, guest PC 0x0c09f760 */
if(!s->budget--) { s->failed_pc=0x0c09f760u; return 0; }
fr[3]=0;
goto P_0c09f762;
P_0c09f762: /* original f315, guest PC 0x0c09f762 */
if(!s->budget--) { s->failed_pc=0x0c09f762u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[1]))!=0);
goto P_0c09f764;
P_0c09f764: /* original 8901, guest PC 0x0c09f764 */
if(!s->budget--) { s->failed_pc=0x0c09f764u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f76a; }
goto P_0c09f766;
P_0c09f766: /* original a002, guest PC 0x0c09f766 */
if(!s->budget--) { s->failed_pc=0x0c09f766u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76e;
P_0c09f768: /* original f1bc, guest PC 0x0c09f768 */
if(!s->budget--) { s->failed_pc=0x0c09f768u; return 0; }
vf3_matrix_move(s,1,11);
goto P_0c09f76a;
P_0c09f76a: /* original c719, guest PC 0x0c09f76a */
if(!s->budget--) { s->failed_pc=0x0c09f76au; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f76c;
P_0c09f76c: /* original f108, guest PC 0x0c09f76c */
if(!s->budget--) { s->failed_pc=0x0c09f76cu; return 0; }
vf3_matrix_load(s,ram,1,r[0]);
goto P_0c09f76e;
P_0c09f76e: /* original f35c, guest PC 0x0c09f76e */
if(!s->budget--) { s->failed_pc=0x0c09f76eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09f770;
P_0c09f770: /* original f51c, guest PC 0x0c09f770 */
if(!s->budget--) { s->failed_pc=0x0c09f770u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c09f772;
P_0c09f772: /* original f530, guest PC 0x0c09f772 */
if(!s->budget--) { s->failed_pc=0x0c09f772u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c09f774;
P_0c09f774: /* original afdf, guest PC 0x0c09f774 */
if(!s->budget--) { s->failed_pc=0x0c09f774u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f736;
P_0c09f776: /* original f55a, guest PC 0x0c09f776 */
if(!s->budget--) { s->failed_pc=0x0c09f776u; return 0; }
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c09f778;
P_0c09f778: /* original f52a, guest PC 0x0c09f778 */
if(!s->budget--) { s->failed_pc=0x0c09f778u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c09f77a;
P_0c09f77a: /* original f5f8, guest PC 0x0c09f77a */
if(!s->budget--) { s->failed_pc=0x0c09f77au; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c09f77c;
P_0c09f77c: /* original f561, guest PC 0x0c09f77c */
if(!s->budget--) { s->failed_pc=0x0c09f77cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c09f77e;
P_0c09f77e: /* original f15c, guest PC 0x0c09f77e */
if(!s->budget--) { s->failed_pc=0x0c09f77eu; return 0; }
vf3_matrix_move(s,1,5);
goto P_0c09f780;
P_0c09f780: /* original f15d, guest PC 0x0c09f780 */
if(!s->budget--) { s->failed_pc=0x0c09f780u; return 0; }
fr[1]&=0x7fffffffu;
goto P_0c09f782;
P_0c09f782: /* original f715, guest PC 0x0c09f782 */
if(!s->budget--) { s->failed_pc=0x0c09f782u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[1]))!=0);
goto P_0c09f784;
P_0c09f784: /* original 8b26, guest PC 0x0c09f784 */
if(!s->budget--) { s->failed_pc=0x0c09f784u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7d4; }
goto P_0c09f786;
P_0c09f786: /* original f815, guest PC 0x0c09f786 */
if(!s->budget--) { s->failed_pc=0x0c09f786u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c09f788;
P_0c09f788: /* original 8b08, guest PC 0x0c09f788 */
if(!s->budget--) { s->failed_pc=0x0c09f788u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f79c; }
goto P_0c09f78a;
P_0c09f78a: /* original f915, guest PC 0x0c09f78a */
if(!s->budget--) { s->failed_pc=0x0c09f78au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[1]))!=0);
goto P_0c09f78c;
P_0c09f78c: /* original 8923, guest PC 0x0c09f78c */
if(!s->budget--) { s->failed_pc=0x0c09f78cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7d6; }
goto P_0c09f78e;
P_0c09f78e: /* original f38d, guest PC 0x0c09f78e */
if(!s->budget--) { s->failed_pc=0x0c09f78eu; return 0; }
fr[3]=0;
goto P_0c09f790;
P_0c09f790: /* original f355, guest PC 0x0c09f790 */
if(!s->budget--) { s->failed_pc=0x0c09f790u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f792;
P_0c09f792: /* original 8901, guest PC 0x0c09f792 */
if(!s->budget--) { s->failed_pc=0x0c09f792u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f798; }
goto P_0c09f794;
P_0c09f794: /* original a009, guest PC 0x0c09f794 */
if(!s->budget--) { s->failed_pc=0x0c09f794u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7aa;
P_0c09f796: /* original f5ac, guest PC 0x0c09f796 */
if(!s->budget--) { s->failed_pc=0x0c09f796u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f798;
P_0c09f798: /* original a007, guest PC 0x0c09f798 */
if(!s->budget--) { s->failed_pc=0x0c09f798u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7aa;
P_0c09f79a: /* original f5dc, guest PC 0x0c09f79a */
if(!s->budget--) { s->failed_pc=0x0c09f79au; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f79c;
P_0c09f79c: /* original f38d, guest PC 0x0c09f79c */
if(!s->budget--) { s->failed_pc=0x0c09f79cu; return 0; }
fr[3]=0;
goto P_0c09f79e;
P_0c09f79e: /* original f355, guest PC 0x0c09f79e */
if(!s->budget--) { s->failed_pc=0x0c09f79eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c09f7a0;
P_0c09f7a0: /* original 8901, guest PC 0x0c09f7a0 */
if(!s->budget--) { s->failed_pc=0x0c09f7a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7a6; }
goto P_0c09f7a2;
P_0c09f7a2: /* original a002, guest PC 0x0c09f7a2 */
if(!s->budget--) { s->failed_pc=0x0c09f7a2u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7aa;
P_0c09f7a4: /* original f5bc, guest PC 0x0c09f7a4 */
if(!s->budget--) { s->failed_pc=0x0c09f7a4u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f7a6;
P_0c09f7a6: /* original c70a, guest PC 0x0c09f7a6 */
if(!s->budget--) { s->failed_pc=0x0c09f7a6u; return 0; }
r[0]=code_base|0x0009f7d0u;
goto P_0c09f7a8;
P_0c09f7a8: /* original f508, guest PC 0x0c09f7a8 */
if(!s->budget--) { s->failed_pc=0x0c09f7a8u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f7aa;
P_0c09f7aa: /* original f36c, guest PC 0x0c09f7aa */
if(!s->budget--) { s->failed_pc=0x0c09f7aau; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c09f7ac;
P_0c09f7ac: /* original f65c, guest PC 0x0c09f7ac */
if(!s->budget--) { s->failed_pc=0x0c09f7acu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09f7ae;
P_0c09f7ae: /* original f630, guest PC 0x0c09f7ae */
if(!s->budget--) { s->failed_pc=0x0c09f7aeu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'+');
goto P_0c09f7b0;
P_0c09f7b0: /* original afe3, guest PC 0x0c09f7b0 */
if(!s->budget--) { s->failed_pc=0x0c09f7b0u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
goto P_0c09f77a;
P_0c09f7b2: /* original f66a, guest PC 0x0c09f7b2 */
if(!s->budget--) { s->failed_pc=0x0c09f7b2u; return 0; }
vf3_matrix_store(s,ram,6,r[6]);
if(!vf3_matrix_family(0x0c09f7b4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f7b4u; return 0; } return 1;
P_0c09f7d4: /* original f62a, guest PC 0x0c09f7d4 */
if(!s->budget--) { s->failed_pc=0x0c09f7d4u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c09f7d6;
P_0c09f7d6: /* original e008, guest PC 0x0c09f7d6 */
if(!s->budget--) { s->failed_pc=0x0c09f7d6u; return 0; }
r[0]=0x00000008u;
goto P_0c09f7d8;
P_0c09f7d8: /* original f6f6, guest PC 0x0c09f7d8 */
if(!s->budget--) { s->failed_pc=0x0c09f7d8u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c09f7da;
P_0c09f7da: /* original f641, guest PC 0x0c09f7da */
if(!s->budget--) { s->failed_pc=0x0c09f7dau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c09f7dc;
P_0c09f7dc: /* original f56c, guest PC 0x0c09f7dc */
if(!s->budget--) { s->failed_pc=0x0c09f7dcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09f7de;
P_0c09f7de: /* original f55d, guest PC 0x0c09f7de */
if(!s->budget--) { s->failed_pc=0x0c09f7deu; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c09f7e0;
P_0c09f7e0: /* original f755, guest PC 0x0c09f7e0 */
if(!s->budget--) { s->failed_pc=0x0c09f7e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c09f7e2;
P_0c09f7e2: /* original 8b16, guest PC 0x0c09f7e2 */
if(!s->budget--) { s->failed_pc=0x0c09f7e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f812; }
goto P_0c09f7e4;
P_0c09f7e4: /* original f855, guest PC 0x0c09f7e4 */
if(!s->budget--) { s->failed_pc=0x0c09f7e4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[5]))!=0);
goto P_0c09f7e6;
P_0c09f7e6: /* original 8b08, guest PC 0x0c09f7e6 */
if(!s->budget--) { s->failed_pc=0x0c09f7e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f7fa; }
goto P_0c09f7e8;
P_0c09f7e8: /* original f955, guest PC 0x0c09f7e8 */
if(!s->budget--) { s->failed_pc=0x0c09f7e8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[5]))!=0);
goto P_0c09f7ea;
P_0c09f7ea: /* original 8913, guest PC 0x0c09f7ea */
if(!s->budget--) { s->failed_pc=0x0c09f7eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f814; }
goto P_0c09f7ec;
P_0c09f7ec: /* original f38d, guest PC 0x0c09f7ec */
if(!s->budget--) { s->failed_pc=0x0c09f7ecu; return 0; }
fr[3]=0;
goto P_0c09f7ee;
P_0c09f7ee: /* original f365, guest PC 0x0c09f7ee */
if(!s->budget--) { s->failed_pc=0x0c09f7eeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7f0;
P_0c09f7f0: /* original 8901, guest PC 0x0c09f7f0 */
if(!s->budget--) { s->failed_pc=0x0c09f7f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f7f6; }
goto P_0c09f7f2;
P_0c09f7f2: /* original a009, guest PC 0x0c09f7f2 */
if(!s->budget--) { s->failed_pc=0x0c09f7f2u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f808;
P_0c09f7f4: /* original f5ac, guest PC 0x0c09f7f4 */
if(!s->budget--) { s->failed_pc=0x0c09f7f4u; return 0; }
vf3_matrix_move(s,5,10);
goto P_0c09f7f6;
P_0c09f7f6: /* original a007, guest PC 0x0c09f7f6 */
if(!s->budget--) { s->failed_pc=0x0c09f7f6u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f808;
P_0c09f7f8: /* original f5dc, guest PC 0x0c09f7f8 */
if(!s->budget--) { s->failed_pc=0x0c09f7f8u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c09f7fa;
P_0c09f7fa: /* original f38d, guest PC 0x0c09f7fa */
if(!s->budget--) { s->failed_pc=0x0c09f7fau; return 0; }
fr[3]=0;
goto P_0c09f7fc;
P_0c09f7fc: /* original f365, guest PC 0x0c09f7fc */
if(!s->budget--) { s->failed_pc=0x0c09f7fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[6]))!=0);
goto P_0c09f7fe;
P_0c09f7fe: /* original 8901, guest PC 0x0c09f7fe */
if(!s->budget--) { s->failed_pc=0x0c09f7feu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f804; }
goto P_0c09f800;
P_0c09f800: /* original a002, guest PC 0x0c09f800 */
if(!s->budget--) { s->failed_pc=0x0c09f800u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f808;
P_0c09f802: /* original f5bc, guest PC 0x0c09f802 */
if(!s->budget--) { s->failed_pc=0x0c09f802u; return 0; }
vf3_matrix_move(s,5,11);
goto P_0c09f804;
P_0c09f804: /* original c733, guest PC 0x0c09f804 */
if(!s->budget--) { s->failed_pc=0x0c09f804u; return 0; }
r[0]=code_base|0x0009f8d4u;
goto P_0c09f806;
P_0c09f806: /* original f508, guest PC 0x0c09f806 */
if(!s->budget--) { s->failed_pc=0x0c09f806u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09f808;
P_0c09f808: /* original f34c, guest PC 0x0c09f808 */
if(!s->budget--) { s->failed_pc=0x0c09f808u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09f80a;
P_0c09f80a: /* original f45c, guest PC 0x0c09f80a */
if(!s->budget--) { s->failed_pc=0x0c09f80au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c09f80c;
P_0c09f80c: /* original f430, guest PC 0x0c09f80c */
if(!s->budget--) { s->failed_pc=0x0c09f80cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c09f80e;
P_0c09f80e: /* original afe2, guest PC 0x0c09f80e */
if(!s->budget--) { s->failed_pc=0x0c09f80eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f7d6;
P_0c09f810: /* original f44a, guest PC 0x0c09f810 */
if(!s->budget--) { s->failed_pc=0x0c09f810u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c09f812;
P_0c09f812: /* original f42a, guest PC 0x0c09f812 */
if(!s->budget--) { s->failed_pc=0x0c09f812u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c09f814;
P_0c09f814: /* original 7f0c, guest PC 0x0c09f814 */
if(!s->budget--) { s->failed_pc=0x0c09f814u; return 0; }
r[15]+=0x0000000cu;
goto P_0c09f816;
P_0c09f816: /* original 000b, guest PC 0x0c09f816 */
if(!s->budget--) { s->failed_pc=0x0c09f816u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c09f818: /* original fdf9, guest PC 0x0c09f818 */
if(!s->budget--) { s->failed_pc=0x0c09f818u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
if(!vf3_matrix_family(0x0c09f81au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f81au; return 0; } return 1;
P_0c09f83c: /* original e607, guest PC 0x0c09f83c */
if(!s->budget--) { s->failed_pc=0x0c09f83cu; return 0; }
r[6]=0x00000007u;
goto P_0c09f83e;
P_0c09f83e: /* original 6543, guest PC 0x0c09f83e */
if(!s->budget--) { s->failed_pc=0x0c09f83eu; return 0; }
r[5]=r[4];
goto P_0c09f840;
P_0c09f840: /* original 6753, guest PC 0x0c09f840 */
if(!s->budget--) { s->failed_pc=0x0c09f840u; return 0; }
r[7]=r[5];
goto P_0c09f842;
P_0c09f842: /* original 7708, guest PC 0x0c09f842 */
if(!s->budget--) { s->failed_pc=0x0c09f842u; return 0; }
r[7]+=0x00000008u;
goto P_0c09f844;
P_0c09f844: /* original f878, guest PC 0x0c09f844 */
if(!s->budget--) { s->failed_pc=0x0c09f844u; return 0; }
vf3_matrix_load(s,ram,8,r[7]);
goto P_0c09f846;
P_0c09f846: /* original 4610, guest PC 0x0c09f846 */
if(!s->budget--) { s->failed_pc=0x0c09f846u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c09f848;
P_0c09f848: /* original f74c, guest PC 0x0c09f848 */
if(!s->budget--) { s->failed_pc=0x0c09f848u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c09f84a;
P_0c09f84a: /* original f958, guest PC 0x0c09f84a */
if(!s->budget--) { s->failed_pc=0x0c09f84au; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
goto P_0c09f84c;
P_0c09f84c: /* original f782, guest PC 0x0c09f84c */
if(!s->budget--) { s->failed_pc=0x0c09f84cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'*');
goto P_0c09f84e;
P_0c09f84e: /* original f25c, guest PC 0x0c09f84e */
if(!s->budget--) { s->failed_pc=0x0c09f84eu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c09f850;
P_0c09f850: /* original f38c, guest PC 0x0c09f850 */
if(!s->budget--) { s->failed_pc=0x0c09f850u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c09f852;
P_0c09f852: /* original f292, guest PC 0x0c09f852 */
if(!s->budget--) { s->failed_pc=0x0c09f852u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[9],r[18],'*');
goto P_0c09f854;
P_0c09f854: /* original f85c, guest PC 0x0c09f854 */
if(!s->budget--) { s->failed_pc=0x0c09f854u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c09f856;
P_0c09f856: /* original f832, guest PC 0x0c09f856 */
if(!s->budget--) { s->failed_pc=0x0c09f856u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'*');
goto P_0c09f858;
P_0c09f858: /* original f37c, guest PC 0x0c09f858 */
if(!s->budget--) { s->failed_pc=0x0c09f858u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c09f85a;
P_0c09f85a: /* original f09c, guest PC 0x0c09f85a */
if(!s->budget--) { s->failed_pc=0x0c09f85au; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c09f85c;
P_0c09f85c: /* original f72c, guest PC 0x0c09f85c */
if(!s->budget--) { s->failed_pc=0x0c09f85cu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c09f85e;
P_0c09f85e: /* original f731, guest PC 0x0c09f85e */
if(!s->budget--) { s->failed_pc=0x0c09f85eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c09f860;
P_0c09f860: /* original f28c, guest PC 0x0c09f860 */
if(!s->budget--) { s->failed_pc=0x0c09f860u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c09f862;
P_0c09f862: /* original f24e, guest PC 0x0c09f862 */
if(!s->budget--) { s->failed_pc=0x0c09f862u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c09f864;
P_0c09f864: /* original f82c, guest PC 0x0c09f864 */
if(!s->budget--) { s->failed_pc=0x0c09f864u; return 0; }
vf3_matrix_move(s,8,2);
goto P_0c09f866;
P_0c09f866: /* original f57a, guest PC 0x0c09f866 */
if(!s->budget--) { s->failed_pc=0x0c09f866u; return 0; }
vf3_matrix_store(s,ram,7,r[5]);
goto P_0c09f868;
P_0c09f868: /* original f78a, guest PC 0x0c09f868 */
if(!s->budget--) { s->failed_pc=0x0c09f868u; return 0; }
vf3_matrix_store(s,ram,8,r[7]);
goto P_0c09f86a;
P_0c09f86a: /* original 8fe9, guest PC 0x0c09f86a */
if(!s->budget--) { s->failed_pc=0x0c09f86au; return 0; }
cond=r[17]&1u;
r[5]+=0x0000000cu;
if(!cond) { goto P_0c09f840; }
goto P_0c09f86e;
P_0c09f86c: /* original 750c, guest PC 0x0c09f86c */
if(!s->budget--) { s->failed_pc=0x0c09f86cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c09f86e;
P_0c09f86e: /* original e058, guest PC 0x0c09f86e */
if(!s->budget--) { s->failed_pc=0x0c09f86eu; return 0; }
r[0]=0x00000058u;
goto P_0c09f870;
P_0c09f870: /* original f76c, guest PC 0x0c09f870 */
if(!s->budget--) { s->failed_pc=0x0c09f870u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c09f872;
P_0c09f872: /* original f446, guest PC 0x0c09f872 */
if(!s->budget--) { s->failed_pc=0x0c09f872u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c09f874;
P_0c09f874: /* original 902c, guest PC 0x0c09f874 */
if(!s->budget--) { s->failed_pc=0x0c09f874u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f8d0u,2);
goto P_0c09f876;
P_0c09f876: /* original f460, guest PC 0x0c09f876 */
if(!s->budget--) { s->failed_pc=0x0c09f876u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c09f878;
P_0c09f878: /* original f546, guest PC 0x0c09f878 */
if(!s->budget--) { s->failed_pc=0x0c09f878u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c09f87a;
P_0c09f87a: /* original 70e8, guest PC 0x0c09f87a */
if(!s->budget--) { s->failed_pc=0x0c09f87au; return 0; }
r[0]+=0xffffffe8u;
goto P_0c09f87c;
P_0c09f87c: /* original f346, guest PC 0x0c09f87c */
if(!s->budget--) { s->failed_pc=0x0c09f87cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09f87e;
P_0c09f87e: /* original e058, guest PC 0x0c09f87e */
if(!s->budget--) { s->failed_pc=0x0c09f87eu; return 0; }
r[0]=0x00000058u;
goto P_0c09f880;
P_0c09f880: /* original f560, guest PC 0x0c09f880 */
if(!s->budget--) { s->failed_pc=0x0c09f880u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c09f882;
P_0c09f882: /* original f447, guest PC 0x0c09f882 */
if(!s->budget--) { s->failed_pc=0x0c09f882u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c09f884;
P_0c09f884: /* original f730, guest PC 0x0c09f884 */
if(!s->budget--) { s->failed_pc=0x0c09f884u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'+');
goto P_0c09f886;
P_0c09f886: /* original 9023, guest PC 0x0c09f886 */
if(!s->budget--) { s->failed_pc=0x0c09f886u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f8d0u,2);
goto P_0c09f888;
P_0c09f888: /* original f457, guest PC 0x0c09f888 */
if(!s->budget--) { s->failed_pc=0x0c09f888u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c09f88a;
P_0c09f88a: /* original 70e8, guest PC 0x0c09f88a */
if(!s->budget--) { s->failed_pc=0x0c09f88au; return 0; }
r[0]+=0xffffffe8u;
goto P_0c09f88c;
P_0c09f88c: /* original 000b, guest PC 0x0c09f88c */
if(!s->budget--) { s->failed_pc=0x0c09f88cu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,7,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c09f88e: /* original f477, guest PC 0x0c09f88e */
if(!s->budget--) { s->failed_pc=0x0c09f88eu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
if(!vf3_matrix_family(0x0c09f890u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f890u; return 0; } return 1;
P_0c09f8d8: /* original 907d, guest PC 0x0c09f8d8 */
if(!s->budget--) { s->failed_pc=0x0c09f8d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9d6u,2);
goto P_0c09f8da;
P_0c09f8da: /* original 7ff0, guest PC 0x0c09f8da */
if(!s->budget--) { s->failed_pc=0x0c09f8dau; return 0; }
r[15]+=0xfffffff0u;
goto P_0c09f8dc;
P_0c09f8dc: /* original 034e, guest PC 0x0c09f8dc */
if(!s->budget--) { s->failed_pc=0x0c09f8dcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c09f8de;
P_0c09f8de: /* original 1f31, guest PC 0x0c09f8de */
if(!s->budget--) { s->failed_pc=0x0c09f8deu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09f8e0;
P_0c09f8e0: /* original 907a, guest PC 0x0c09f8e0 */
if(!s->budget--) { s->failed_pc=0x0c09f8e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f9d8u,2);
goto P_0c09f8e2;
P_0c09f8e2: /* original 074e, guest PC 0x0c09f8e2 */
if(!s->budget--) { s->failed_pc=0x0c09f8e2u; return 0; }
r[7]=read(ram,r[4]+r[0],4);
goto P_0c09f8e4;
P_0c09f8e4: /* original 70f9, guest PC 0x0c09f8e4 */
if(!s->budget--) { s->failed_pc=0x0c09f8e4u; return 0; }
r[0]+=0xfffffff9u;
goto P_0c09f8e6;
P_0c09f8e6: /* original 034c, guest PC 0x0c09f8e6 */
if(!s->budget--) { s->failed_pc=0x0c09f8e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f8e8;
P_0c09f8e8: /* original 633c, guest PC 0x0c09f8e8 */
if(!s->budget--) { s->failed_pc=0x0c09f8e8u; return 0; }
r[3]=r[3]&255u;
goto P_0c09f8ea;
P_0c09f8ea: /* original 2f32, guest PC 0x0c09f8ea */
if(!s->budget--) { s->failed_pc=0x0c09f8eau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09f8ec;
P_0c09f8ec: /* original d23c, guest PC 0x0c09f8ec */
if(!s->budget--) { s->failed_pc=0x0c09f8ecu; return 0; }
r[2]=read(ram,0x0c09f9e0u,4);
goto P_0c09f8ee;
P_0c09f8ee: /* original 51f1, guest PC 0x0c09f8ee */
if(!s->budget--) { s->failed_pc=0x0c09f8eeu; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c09f8f0;
P_0c09f8f0: /* original 2129, guest PC 0x0c09f8f0 */
if(!s->budget--) { s->failed_pc=0x0c09f8f0u; return 0; }
r[1]&=r[2];
goto P_0c09f8f2;
P_0c09f8f2: /* original 1f11, guest PC 0x0c09f8f2 */
if(!s->budget--) { s->failed_pc=0x0c09f8f2u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c09f8f4;
P_0c09f8f4: /* original 2279, guest PC 0x0c09f8f4 */
if(!s->budget--) { s->failed_pc=0x0c09f8f4u; return 0; }
r[2]&=r[7];
goto P_0c09f8f6;
P_0c09f8f6: /* original 1f22, guest PC 0x0c09f8f6 */
if(!s->budget--) { s->failed_pc=0x0c09f8f6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c09f8f8;
P_0c09f8f8: /* original 60f2, guest PC 0x0c09f8f8 */
if(!s->budget--) { s->failed_pc=0x0c09f8f8u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09f8fa;
P_0c09f8fa: /* original c980, guest PC 0x0c09f8fa */
if(!s->budget--) { s->failed_pc=0x0c09f8fau; return 0; }
r[0]&=128u;
goto P_0c09f8fc;
P_0c09f8fc: /* original 2f02, guest PC 0x0c09f8fc */
if(!s->budget--) { s->failed_pc=0x0c09f8fcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09f8fe;
P_0c09f8fe: /* original d339, guest PC 0x0c09f8fe */
if(!s->budget--) { s->failed_pc=0x0c09f8feu; return 0; }
r[3]=read(ram,0x0c09f9e4u,4);
goto P_0c09f900;
P_0c09f900: /* original 2379, guest PC 0x0c09f900 */
if(!s->budget--) { s->failed_pc=0x0c09f900u; return 0; }
r[3]&=r[7];
goto P_0c09f902;
P_0c09f902: /* original 1f33, guest PC 0x0c09f902 */
if(!s->budget--) { s->failed_pc=0x0c09f902u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c09f904;
P_0c09f904: /* original 51f2, guest PC 0x0c09f904 */
if(!s->budget--) { s->failed_pc=0x0c09f904u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c09f906;
P_0c09f906: /* original d238, guest PC 0x0c09f906 */
if(!s->budget--) { s->failed_pc=0x0c09f906u; return 0; }
r[2]=read(ram,0x0c09f9e8u,4);
goto P_0c09f908;
P_0c09f908: /* original 2118, guest PC 0x0c09f908 */
if(!s->budget--) { s->failed_pc=0x0c09f908u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c09f90a;
P_0c09f90a: /* original 8d39, guest PC 0x0c09f90a */
if(!s->budget--) { s->failed_pc=0x0c09f90au; return 0; }
cond=r[17]&1u;
r[7]&=r[2];
if(cond) { goto P_0c09f980; }
goto P_0c09f90e;
P_0c09f90c: /* original 2729, guest PC 0x0c09f90c */
if(!s->budget--) { s->failed_pc=0x0c09f90cu; return 0; }
r[7]&=r[2];
goto P_0c09f90e;
P_0c09f90e: /* original 53f1, guest PC 0x0c09f90e */
if(!s->budget--) { s->failed_pc=0x0c09f90eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09f910;
P_0c09f910: /* original 2338, guest PC 0x0c09f910 */
if(!s->budget--) { s->failed_pc=0x0c09f910u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f912;
P_0c09f912: /* original 8b35, guest PC 0x0c09f912 */
if(!s->budget--) { s->failed_pc=0x0c09f912u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f980; }
goto P_0c09f914;
P_0c09f914: /* original e061, guest PC 0x0c09f914 */
if(!s->budget--) { s->failed_pc=0x0c09f914u; return 0; }
r[0]=0x00000061u;
goto P_0c09f916;
P_0c09f916: /* original 53f3, guest PC 0x0c09f916 */
if(!s->budget--) { s->failed_pc=0x0c09f916u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c09f918;
P_0c09f918: /* original 044c, guest PC 0x0c09f918 */
if(!s->budget--) { s->failed_pc=0x0c09f918u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f91a;
P_0c09f91a: /* original 2338, guest PC 0x0c09f91a */
if(!s->budget--) { s->failed_pc=0x0c09f91au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09f91c;
P_0c09f91c: /* original 644c, guest PC 0x0c09f91c */
if(!s->budget--) { s->failed_pc=0x0c09f91cu; return 0; }
r[4]=r[4]&255u;
goto P_0c09f91e;
P_0c09f91e: /* original 8d01, guest PC 0x0c09f91e */
if(!s->budget--) { s->failed_pc=0x0c09f91eu; return 0; }
cond=r[17]&1u;
r[4]<<=2;
if(cond) { goto P_0c09f924; }
goto P_0c09f922;
P_0c09f920: /* original 4408, guest PC 0x0c09f920 */
if(!s->budget--) { s->failed_pc=0x0c09f920u; return 0; }
r[4]<<=2;
goto P_0c09f922;
P_0c09f922: /* original 7402, guest PC 0x0c09f922 */
if(!s->budget--) { s->failed_pc=0x0c09f922u; return 0; }
r[4]+=0x00000002u;
goto P_0c09f924;
P_0c09f924: /* original 2778, guest PC 0x0c09f924 */
if(!s->budget--) { s->failed_pc=0x0c09f924u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c09f926;
P_0c09f926: /* original 8900, guest PC 0x0c09f926 */
if(!s->budget--) { s->failed_pc=0x0c09f926u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09f92a; }
goto P_0c09f928;
P_0c09f928: /* original 7401, guest PC 0x0c09f928 */
if(!s->budget--) { s->failed_pc=0x0c09f928u; return 0; }
r[4]+=0x00000001u;
goto P_0c09f92a;
P_0c09f92a: /* original d030, guest PC 0x0c09f92a */
if(!s->budget--) { s->failed_pc=0x0c09f92au; return 0; }
r[0]=read(ram,0x0c09f9ecu,4);
goto P_0c09f92c;
P_0c09f92c: /* original 62f2, guest PC 0x0c09f92c */
if(!s->budget--) { s->failed_pc=0x0c09f92cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09f92e;
P_0c09f92e: /* original 034c, guest PC 0x0c09f92e */
if(!s->budget--) { s->failed_pc=0x0c09f92eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09f930;
P_0c09f930: /* original 2228, guest PC 0x0c09f930 */
if(!s->budget--) { s->failed_pc=0x0c09f930u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09f932;
P_0c09f932: /* original 633c, guest PC 0x0c09f932 */
if(!s->budget--) { s->failed_pc=0x0c09f932u; return 0; }
r[3]=r[3]&255u;
goto P_0c09f934;
P_0c09f934: /* original 8d02, guest PC 0x0c09f934 */
if(!s->budget--) { s->failed_pc=0x0c09f934u; return 0; }
cond=r[17]&1u;
r[4]=r[3];
if(cond) { goto P_0c09f93c; }
goto P_0c09f938;
P_0c09f936: /* original 6433, guest PC 0x0c09f936 */
if(!s->budget--) { s->failed_pc=0x0c09f936u; return 0; }
r[4]=r[3];
goto P_0c09f938;
P_0c09f938: /* original e101, guest PC 0x0c09f938 */
if(!s->budget--) { s->failed_pc=0x0c09f938u; return 0; }
r[1]=0x00000001u;
goto P_0c09f93a;
P_0c09f93a: /* original 241a, guest PC 0x0c09f93a */
if(!s->budget--) { s->failed_pc=0x0c09f93au; return 0; }
r[4]^=r[1];
goto P_0c09f93c;
P_0c09f93c: /* original 2448, guest PC 0x0c09f93c */
if(!s->budget--) { s->failed_pc=0x0c09f93cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c09f93e;
P_0c09f93e: /* original 8b07, guest PC 0x0c09f93e */
if(!s->budget--) { s->failed_pc=0x0c09f93eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09f950; }
goto P_0c09f940;
P_0c09f940: /* original e03c, guest PC 0x0c09f940 */
if(!s->budget--) { s->failed_pc=0x0c09f940u; return 0; }
r[0]=0x0000003cu;
goto P_0c09f942;
P_0c09f942: /* original f656, guest PC 0x0c09f942 */
if(!s->budget--) { s->failed_pc=0x0c09f942u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c09f944;
P_0c09f944: /* original e044, guest PC 0x0c09f944 */
if(!s->budget--) { s->failed_pc=0x0c09f944u; return 0; }
r[0]=0x00000044u;
goto P_0c09f946;
P_0c09f946: /* original f456, guest PC 0x0c09f946 */
if(!s->budget--) { s->failed_pc=0x0c09f946u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c09f948;
P_0c09f948: /* original e03c, guest PC 0x0c09f948 */
if(!s->budget--) { s->failed_pc=0x0c09f948u; return 0; }
r[0]=0x0000003cu;
goto P_0c09f94a;
P_0c09f94a: /* original f766, guest PC 0x0c09f94a */
if(!s->budget--) { s->failed_pc=0x0c09f94au; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c09f94c;
P_0c09f94c: /* original a007, guest PC 0x0c09f94c */
if(!s->budget--) { s->failed_pc=0x0c09f94cu; return 0; }
r[0]=0x00000044u;
goto P_0c09f95e;
P_0c09f94e: /* original e044, guest PC 0x0c09f94e */
if(!s->budget--) { s->failed_pc=0x0c09f94eu; return 0; }
r[0]=0x00000044u;
goto P_0c09f950;
P_0c09f950: /* original e048, guest PC 0x0c09f950 */
if(!s->budget--) { s->failed_pc=0x0c09f950u; return 0; }
r[0]=0x00000048u;
goto P_0c09f952;
P_0c09f952: /* original f656, guest PC 0x0c09f952 */
if(!s->budget--) { s->failed_pc=0x0c09f952u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c09f954;
P_0c09f954: /* original e050, guest PC 0x0c09f954 */
if(!s->budget--) { s->failed_pc=0x0c09f954u; return 0; }
r[0]=0x00000050u;
goto P_0c09f956;
P_0c09f956: /* original f456, guest PC 0x0c09f956 */
if(!s->budget--) { s->failed_pc=0x0c09f956u; return 0; }
vf3_matrix_load(s,ram,4,r[5]+r[0]);
goto P_0c09f958;
P_0c09f958: /* original e048, guest PC 0x0c09f958 */
if(!s->budget--) { s->failed_pc=0x0c09f958u; return 0; }
r[0]=0x00000048u;
goto P_0c09f95a;
P_0c09f95a: /* original f766, guest PC 0x0c09f95a */
if(!s->budget--) { s->failed_pc=0x0c09f95au; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c09f95c;
P_0c09f95c: /* original e050, guest PC 0x0c09f95c */
if(!s->budget--) { s->failed_pc=0x0c09f95cu; return 0; }
r[0]=0x00000050u;
goto P_0c09f95e;
P_0c09f95e: /* original f671, guest PC 0x0c09f95e */
if(!s->budget--) { s->failed_pc=0x0c09f95eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c09f960;
P_0c09f960: /* original f566, guest PC 0x0c09f960 */
if(!s->budget--) { s->failed_pc=0x0c09f960u; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c09f962;
P_0c09f962: /* original f74c, guest PC 0x0c09f962 */
if(!s->budget--) { s->failed_pc=0x0c09f962u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c09f964;
P_0c09f964: /* original 6463, guest PC 0x0c09f964 */
if(!s->budget--) { s->failed_pc=0x0c09f964u; return 0; }
r[4]=r[6];
goto P_0c09f966;
P_0c09f966: /* original f751, guest PC 0x0c09f966 */
if(!s->budget--) { s->failed_pc=0x0c09f966u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c09f968;
P_0c09f968: /* original e507, guest PC 0x0c09f968 */
if(!s->budget--) { s->failed_pc=0x0c09f968u; return 0; }
r[5]=0x00000007u;
goto P_0c09f96a;
P_0c09f96a: /* original 6643, guest PC 0x0c09f96a */
if(!s->budget--) { s->failed_pc=0x0c09f96au; return 0; }
r[6]=r[4];
goto P_0c09f96c;
P_0c09f96c: /* original 7608, guest PC 0x0c09f96c */
if(!s->budget--) { s->failed_pc=0x0c09f96cu; return 0; }
r[6]+=0x00000008u;
goto P_0c09f96e;
P_0c09f96e: /* original f468, guest PC 0x0c09f96e */
if(!s->budget--) { s->failed_pc=0x0c09f96eu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
goto P_0c09f970;
P_0c09f970: /* original 4510, guest PC 0x0c09f970 */
if(!s->budget--) { s->failed_pc=0x0c09f970u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09f972;
P_0c09f972: /* original f548, guest PC 0x0c09f972 */
if(!s->budget--) { s->failed_pc=0x0c09f972u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
goto P_0c09f974;
P_0c09f974: /* original f470, guest PC 0x0c09f974 */
if(!s->budget--) { s->failed_pc=0x0c09f974u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c09f976;
P_0c09f976: /* original f560, guest PC 0x0c09f976 */
if(!s->budget--) { s->failed_pc=0x0c09f976u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c09f978;
P_0c09f978: /* original f45a, guest PC 0x0c09f978 */
if(!s->budget--) { s->failed_pc=0x0c09f978u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c09f97a;
P_0c09f97a: /* original f64a, guest PC 0x0c09f97a */
if(!s->budget--) { s->failed_pc=0x0c09f97au; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c09f97c;
P_0c09f97c: /* original 8ff5, guest PC 0x0c09f97c */
if(!s->budget--) { s->failed_pc=0x0c09f97cu; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09f96a; }
goto P_0c09f980;
P_0c09f97e: /* original 740c, guest PC 0x0c09f97e */
if(!s->budget--) { s->failed_pc=0x0c09f97eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c09f980;
P_0c09f980: /* original 000b, guest PC 0x0c09f980 */
if(!s->budget--) { s->failed_pc=0x0c09f980u; return 0; }
target=r[16];
r[15]+=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c09f982: /* original 7f10, guest PC 0x0c09f982 */
if(!s->budget--) { s->failed_pc=0x0c09f982u; return 0; }
r[15]+=0x00000010u;
if(!vf3_matrix_family(0x0c09f984u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09f984u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
