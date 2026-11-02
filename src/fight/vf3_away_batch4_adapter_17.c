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
int vf3_away_batch4_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04d62cu: goto P_0c04d62c;
case 0x0c04d62eu: goto P_0c04d62e;
case 0x0c04d630u: goto P_0c04d630;
case 0x0c04d632u: goto P_0c04d632;
case 0x0c04d634u: goto P_0c04d634;
case 0x0c04d636u: goto P_0c04d636;
case 0x0c04d638u: goto P_0c04d638;
case 0x0c04d63au: goto P_0c04d63a;
case 0x0c04d63cu: goto P_0c04d63c;
case 0x0c04d63eu: goto P_0c04d63e;
case 0x0c04d640u: goto P_0c04d640;
case 0x0c04d642u: goto P_0c04d642;
case 0x0c04d644u: goto P_0c04d644;
case 0x0c04d646u: goto P_0c04d646;
case 0x0c04d648u: goto P_0c04d648;
case 0x0c04d64au: goto P_0c04d64a;
case 0x0c04d64cu: goto P_0c04d64c;
case 0x0c04d64eu: goto P_0c04d64e;
case 0x0c04d650u: goto P_0c04d650;
case 0x0c04d652u: goto P_0c04d652;
case 0x0c04d654u: goto P_0c04d654;
case 0x0c04d656u: goto P_0c04d656;
case 0x0c04d658u: goto P_0c04d658;
case 0x0c04d65au: goto P_0c04d65a;
case 0x0c04d65cu: goto P_0c04d65c;
case 0x0c04d65eu: goto P_0c04d65e;
case 0x0c04d660u: goto P_0c04d660;
case 0x0c04d662u: goto P_0c04d662;
case 0x0c04d664u: goto P_0c04d664;
case 0x0c04d666u: goto P_0c04d666;
case 0x0c04d668u: goto P_0c04d668;
case 0x0c04d66au: goto P_0c04d66a;
case 0x0c04d66cu: goto P_0c04d66c;
case 0x0c04d66eu: goto P_0c04d66e;
case 0x0c04d670u: goto P_0c04d670;
case 0x0c04d672u: goto P_0c04d672;
case 0x0c04d674u: goto P_0c04d674;
case 0x0c04d698u: goto P_0c04d698;
case 0x0c04d69au: goto P_0c04d69a;
case 0x0c04d69cu: goto P_0c04d69c;
case 0x0c04d69eu: goto P_0c04d69e;
case 0x0c04d6a0u: goto P_0c04d6a0;
case 0x0c04d6a2u: goto P_0c04d6a2;
case 0x0c04d6a4u: goto P_0c04d6a4;
case 0x0c04d6a6u: goto P_0c04d6a6;
case 0x0c04d6a8u: goto P_0c04d6a8;
case 0x0c04d6aau: goto P_0c04d6aa;
case 0x0c04d6acu: goto P_0c04d6ac;
case 0x0c04d6aeu: goto P_0c04d6ae;
case 0x0c04d6b0u: goto P_0c04d6b0;
case 0x0c04d6b2u: goto P_0c04d6b2;
case 0x0c04d6b4u: goto P_0c04d6b4;
case 0x0c04d6b6u: goto P_0c04d6b6;
case 0x0c04d6b8u: goto P_0c04d6b8;
case 0x0c04d6bau: goto P_0c04d6ba;
case 0x0c04d6bcu: goto P_0c04d6bc;
case 0x0c04d6beu: goto P_0c04d6be;
case 0x0c04d6c0u: goto P_0c04d6c0;
case 0x0c04d6c2u: goto P_0c04d6c2;
case 0x0c04d6c4u: goto P_0c04d6c4;
case 0x0c04d6c6u: goto P_0c04d6c6;
case 0x0c04d6c8u: goto P_0c04d6c8;
case 0x0c04d6cau: goto P_0c04d6ca;
case 0x0c04d6ccu: goto P_0c04d6cc;
case 0x0c04d6ceu: goto P_0c04d6ce;
case 0x0c04d6d0u: goto P_0c04d6d0;
case 0x0c04d6d2u: goto P_0c04d6d2;
case 0x0c04d6d4u: goto P_0c04d6d4;
case 0x0c04d6d6u: goto P_0c04d6d6;
case 0x0c04d6d8u: goto P_0c04d6d8;
case 0x0c04d6dau: goto P_0c04d6da;
case 0x0c04d6dcu: goto P_0c04d6dc;
case 0x0c04d6deu: goto P_0c04d6de;
case 0x0c04d6e0u: goto P_0c04d6e0;
case 0x0c04d6e2u: goto P_0c04d6e2;
case 0x0c04d6e4u: goto P_0c04d6e4;
case 0x0c04d6e6u: goto P_0c04d6e6;
case 0x0c04d6e8u: goto P_0c04d6e8;
case 0x0c04d6eau: goto P_0c04d6ea;
case 0x0c04d6ecu: goto P_0c04d6ec;
case 0x0c04d6eeu: goto P_0c04d6ee;
case 0x0c04d6f0u: goto P_0c04d6f0;
case 0x0c04d6f2u: goto P_0c04d6f2;
case 0x0c04d6f4u: goto P_0c04d6f4;
case 0x0c04d6f6u: goto P_0c04d6f6;
case 0x0c04d6f8u: goto P_0c04d6f8;
case 0x0c04d6fau: goto P_0c04d6fa;
case 0x0c04d6fcu: goto P_0c04d6fc;
case 0x0c04d6feu: goto P_0c04d6fe;
case 0x0c04d700u: goto P_0c04d700;
case 0x0c04d702u: goto P_0c04d702;
case 0x0c04d704u: goto P_0c04d704;
case 0x0c04d706u: goto P_0c04d706;
case 0x0c04d708u: goto P_0c04d708;
case 0x0c04d70au: goto P_0c04d70a;
case 0x0c04d70cu: goto P_0c04d70c;
case 0x0c04d70eu: goto P_0c04d70e;
case 0x0c04d710u: goto P_0c04d710;
case 0x0c04d712u: goto P_0c04d712;
case 0x0c04d714u: goto P_0c04d714;
case 0x0c04d716u: goto P_0c04d716;
case 0x0c04d718u: goto P_0c04d718;
case 0x0c04d71au: goto P_0c04d71a;
case 0x0c04d71cu: goto P_0c04d71c;
case 0x0c04d71eu: goto P_0c04d71e;
case 0x0c04d720u: goto P_0c04d720;
case 0x0c04d800u: goto P_0c04d800;
case 0x0c04d802u: goto P_0c04d802;
case 0x0c04d804u: goto P_0c04d804;
case 0x0c04d806u: goto P_0c04d806;
case 0x0c04d808u: goto P_0c04d808;
case 0x0c04d80au: goto P_0c04d80a;
case 0x0c04d80cu: goto P_0c04d80c;
case 0x0c04d80eu: goto P_0c04d80e;
case 0x0c04d810u: goto P_0c04d810;
case 0x0c04d812u: goto P_0c04d812;
case 0x0c04d814u: goto P_0c04d814;
case 0x0c04d816u: goto P_0c04d816;
case 0x0c04d818u: goto P_0c04d818;
case 0x0c04d81au: goto P_0c04d81a;
case 0x0c04d81cu: goto P_0c04d81c;
case 0x0c04d81eu: goto P_0c04d81e;
case 0x0c04d820u: goto P_0c04d820;
case 0x0c04d822u: goto P_0c04d822;
case 0x0c04d824u: goto P_0c04d824;
case 0x0c04d826u: goto P_0c04d826;
case 0x0c04d828u: goto P_0c04d828;
case 0x0c04d82au: goto P_0c04d82a;
case 0x0c04d82cu: goto P_0c04d82c;
case 0x0c04d82eu: goto P_0c04d82e;
case 0x0c04d830u: goto P_0c04d830;
case 0x0c04d832u: goto P_0c04d832;
case 0x0c04d834u: goto P_0c04d834;
case 0x0c04d836u: goto P_0c04d836;
case 0x0c04d838u: goto P_0c04d838;
case 0x0c04d83au: goto P_0c04d83a;
case 0x0c04d83cu: goto P_0c04d83c;
case 0x0c04d83eu: goto P_0c04d83e;
case 0x0c04d840u: goto P_0c04d840;
case 0x0c04d842u: goto P_0c04d842;
case 0x0c04d844u: goto P_0c04d844;
case 0x0c04d846u: goto P_0c04d846;
case 0x0c04d848u: goto P_0c04d848;
case 0x0c04d84au: goto P_0c04d84a;
case 0x0c04d84cu: goto P_0c04d84c;
case 0x0c04d84eu: goto P_0c04d84e;
case 0x0c04d850u: goto P_0c04d850;
case 0x0c04d852u: goto P_0c04d852;
case 0x0c04d854u: goto P_0c04d854;
case 0x0c04d856u: goto P_0c04d856;
case 0x0c04d858u: goto P_0c04d858;
case 0x0c04d85au: goto P_0c04d85a;
case 0x0c04d85cu: goto P_0c04d85c;
case 0x0c04d85eu: goto P_0c04d85e;
case 0x0c04d860u: goto P_0c04d860;
case 0x0c04d862u: goto P_0c04d862;
case 0x0c04d864u: goto P_0c04d864;
case 0x0c04d866u: goto P_0c04d866;
case 0x0c04d868u: goto P_0c04d868;
case 0x0c04d86au: goto P_0c04d86a;
case 0x0c04d86cu: goto P_0c04d86c;
case 0x0c04d86eu: goto P_0c04d86e;
case 0x0c04d870u: goto P_0c04d870;
case 0x0c04d872u: goto P_0c04d872;
case 0x0c04d874u: goto P_0c04d874;
case 0x0c04d876u: goto P_0c04d876;
case 0x0c04d878u: goto P_0c04d878;
case 0x0c04d87au: goto P_0c04d87a;
case 0x0c04d8acu: goto P_0c04d8ac;
case 0x0c04d8aeu: goto P_0c04d8ae;
case 0x0c04d8b0u: goto P_0c04d8b0;
case 0x0c04d8b2u: goto P_0c04d8b2;
case 0x0c04d8b4u: goto P_0c04d8b4;
case 0x0c04d8b6u: goto P_0c04d8b6;
case 0x0c04d8b8u: goto P_0c04d8b8;
case 0x0c04d8bau: goto P_0c04d8ba;
case 0x0c04d8bcu: goto P_0c04d8bc;
case 0x0c04d8beu: goto P_0c04d8be;
case 0x0c04d8c0u: goto P_0c04d8c0;
case 0x0c04d8c2u: goto P_0c04d8c2;
case 0x0c04d8c4u: goto P_0c04d8c4;
case 0x0c04d8c6u: goto P_0c04d8c6;
case 0x0c04d8c8u: goto P_0c04d8c8;
case 0x0c04d8cau: goto P_0c04d8ca;
case 0x0c04d8ccu: goto P_0c04d8cc;
case 0x0c04d8ceu: goto P_0c04d8ce;
case 0x0c04d8d0u: goto P_0c04d8d0;
case 0x0c04d8d2u: goto P_0c04d8d2;
case 0x0c04d8d4u: goto P_0c04d8d4;
case 0x0c04d8d6u: goto P_0c04d8d6;
case 0x0c04d8d8u: goto P_0c04d8d8;
case 0x0c04d8dau: goto P_0c04d8da;
case 0x0c04d8dcu: goto P_0c04d8dc;
case 0x0c04d8deu: goto P_0c04d8de;
case 0x0c04d8e0u: goto P_0c04d8e0;
case 0x0c04d8e2u: goto P_0c04d8e2;
case 0x0c04d8e4u: goto P_0c04d8e4;
case 0x0c04d8e6u: goto P_0c04d8e6;
case 0x0c04d8e8u: goto P_0c04d8e8;
case 0x0c04d8eau: goto P_0c04d8ea;
case 0x0c04d8ecu: goto P_0c04d8ec;
case 0x0c04d8eeu: goto P_0c04d8ee;
case 0x0c04d8f0u: goto P_0c04d8f0;
case 0x0c04d8f2u: goto P_0c04d8f2;
case 0x0c04d8f4u: goto P_0c04d8f4;
case 0x0c04d8f6u: goto P_0c04d8f6;
case 0x0c04d8f8u: goto P_0c04d8f8;
case 0x0c04d8fau: goto P_0c04d8fa;
case 0x0c04d8fcu: goto P_0c04d8fc;
case 0x0c04d8feu: goto P_0c04d8fe;
case 0x0c04d900u: goto P_0c04d900;
case 0x0c04d902u: goto P_0c04d902;
case 0x0c04d904u: goto P_0c04d904;
case 0x0c04d906u: goto P_0c04d906;
case 0x0c04d908u: goto P_0c04d908;
case 0x0c04d90au: goto P_0c04d90a;
case 0x0c04d90cu: goto P_0c04d90c;
case 0x0c04d90eu: goto P_0c04d90e;
case 0x0c04d910u: goto P_0c04d910;
case 0x0c04d912u: goto P_0c04d912;
case 0x0c04d914u: goto P_0c04d914;
case 0x0c04d916u: goto P_0c04d916;
case 0x0c04d918u: goto P_0c04d918;
case 0x0c04d91au: goto P_0c04d91a;
case 0x0c04d91cu: goto P_0c04d91c;
case 0x0c04d91eu: goto P_0c04d91e;
case 0x0c04d920u: goto P_0c04d920;
case 0x0c04d922u: goto P_0c04d922;
case 0x0c04d924u: goto P_0c04d924;
case 0x0c04d926u: goto P_0c04d926;
case 0x0c04d928u: goto P_0c04d928;
case 0x0c04d92au: goto P_0c04d92a;
case 0x0c04d92cu: goto P_0c04d92c;
case 0x0c04d92eu: goto P_0c04d92e;
case 0x0c04d930u: goto P_0c04d930;
case 0x0c04d932u: goto P_0c04d932;
case 0x0c04d934u: goto P_0c04d934;
case 0x0c04d936u: goto P_0c04d936;
case 0x0c04d938u: goto P_0c04d938;
case 0x0c04d93au: goto P_0c04d93a;
case 0x0c04d93cu: goto P_0c04d93c;
case 0x0c04d93eu: goto P_0c04d93e;
case 0x0c04d940u: goto P_0c04d940;
case 0x0c04d942u: goto P_0c04d942;
case 0x0c04d944u: goto P_0c04d944;
case 0x0c04d946u: goto P_0c04d946;
case 0x0c04d948u: goto P_0c04d948;
case 0x0c04d94au: goto P_0c04d94a;
case 0x0c04d94cu: goto P_0c04d94c;
case 0x0c04d94eu: goto P_0c04d94e;
case 0x0c04d950u: goto P_0c04d950;
case 0x0c04d952u: goto P_0c04d952;
case 0x0c04d954u: goto P_0c04d954;
case 0x0c04d956u: goto P_0c04d956;
case 0x0c04d958u: goto P_0c04d958;
case 0x0c04d95au: goto P_0c04d95a;
case 0x0c04d95cu: goto P_0c04d95c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04d62c: /* original 2fe6, guest PC 0x0c04d62c */
if(!s->budget--) { s->failed_pc=0x0c04d62cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d62e;
P_0c04d62e: /* original 6e43, guest PC 0x0c04d62e */
if(!s->budget--) { s->failed_pc=0x0c04d62eu; return 0; }
r[14]=r[4];
goto P_0c04d630;
P_0c04d630: /* original 2fd6, guest PC 0x0c04d630 */
if(!s->budget--) { s->failed_pc=0x0c04d630u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d632;
P_0c04d632: /* original 2fc6, guest PC 0x0c04d632 */
if(!s->budget--) { s->failed_pc=0x0c04d632u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d634;
P_0c04d634: /* original 2fb6, guest PC 0x0c04d634 */
if(!s->budget--) { s->failed_pc=0x0c04d634u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d636;
P_0c04d636: /* original 2fa6, guest PC 0x0c04d636 */
if(!s->budget--) { s->failed_pc=0x0c04d636u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d638;
P_0c04d638: /* original 4f22, guest PC 0x0c04d638 */
if(!s->budget--) { s->failed_pc=0x0c04d638u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d63a;
P_0c04d63a: /* original 4f12, guest PC 0x0c04d63a */
if(!s->budget--) { s->failed_pc=0x0c04d63au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d63c;
P_0c04d63c: /* original 7ff8, guest PC 0x0c04d63c */
if(!s->budget--) { s->failed_pc=0x0c04d63cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04d63e;
P_0c04d63e: /* original 2f52, guest PC 0x0c04d63e */
if(!s->budget--) { s->failed_pc=0x0c04d63eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04d640;
P_0c04d640: /* original 9b1b, guest PC 0x0c04d640 */
if(!s->budget--) { s->failed_pc=0x0c04d640u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d67au,2);
goto P_0c04d642;
P_0c04d642: /* original 2ebf, guest PC 0x0c04d642 */
if(!s->budget--) { s->failed_pc=0x0c04d642u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[14]*(int32_t)(int16_t)r[11]);
goto P_0c04d644;
P_0c04d644: /* original 0b1a, guest PC 0x0c04d644 */
if(!s->budget--) { s->failed_pc=0x0c04d644u; return 0; }
r[11]=r[19];
goto P_0c04d646;
P_0c04d646: /* original 6bbf, guest PC 0x0c04d646 */
if(!s->budget--) { s->failed_pc=0x0c04d646u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c04d648;
P_0c04d648: /* original 1fb1, guest PC 0x0c04d648 */
if(!s->budget--) { s->failed_pc=0x0c04d648u; return 0; }
write(ram,r[15]+4,r[11],4);
goto P_0c04d64a;
P_0c04d64a: /* original 62f2, guest PC 0x0c04d64a */
if(!s->budget--) { s->failed_pc=0x0c04d64au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c04d64c;
P_0c04d64c: /* original d30c, guest PC 0x0c04d64c */
if(!s->budget--) { s->failed_pc=0x0c04d64cu; return 0; }
r[3]=read(ram,0x0c04d680u,4);
goto P_0c04d64e;
P_0c04d64e: /* original 2f26, guest PC 0x0c04d64e */
if(!s->budget--) { s->failed_pc=0x0c04d64eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d650;
P_0c04d650: /* original 3b3c, guest PC 0x0c04d650 */
if(!s->budget--) { s->failed_pc=0x0c04d650u; return 0; }
r[11]+=r[3];
goto P_0c04d652;
P_0c04d652: /* original 2fe6, guest PC 0x0c04d652 */
if(!s->budget--) { s->failed_pc=0x0c04d652u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d654;
P_0c04d654: /* original d20d, guest PC 0x0c04d654 */
if(!s->budget--) { s->failed_pc=0x0c04d654u; return 0; }
r[2]=read(ram,0x0c04d68cu,4);
goto P_0c04d656;
P_0c04d656: /* original d10e, guest PC 0x0c04d656 */
if(!s->budget--) { s->failed_pc=0x0c04d656u; return 0; }
r[1]=read(ram,0x0c04d690u,4);
goto P_0c04d658;
P_0c04d658: /* original 410b, guest PC 0x0c04d658 */
if(!s->budget--) { s->failed_pc=0x0c04d658u; return 0; }
target=r[1];
r[16]=code_base|0x0c04d65cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d65cu) { target=s->pc; goto dispatch; }
goto P_0c04d65c;
P_0c04d65a: /* original 2f26, guest PC 0x0c04d65a */
if(!s->budget--) { s->failed_pc=0x0c04d65au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d65c;
P_0c04d65c: /* original 84b2, guest PC 0x0c04d65c */
if(!s->budget--) { s->failed_pc=0x0c04d65cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+2,1);
goto P_0c04d65e;
P_0c04d65e: /* original 2008, guest PC 0x0c04d65e */
if(!s->budget--) { s->failed_pc=0x0c04d65eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d660;
P_0c04d660: /* original 8d25, guest PC 0x0c04d660 */
if(!s->budget--) { s->failed_pc=0x0c04d660u; return 0; }
cond=r[17]&1u;
r[15]+=0x0000000cu;
if(cond) { goto P_0c04d6ae; }
goto P_0c04d664;
P_0c04d662: /* original 7f0c, guest PC 0x0c04d662 */
if(!s->budget--) { s->failed_pc=0x0c04d662u; return 0; }
r[15]+=0x0000000cu;
goto P_0c04d664;
P_0c04d664: /* original d20b, guest PC 0x0c04d664 */
if(!s->budget--) { s->failed_pc=0x0c04d664u; return 0; }
r[2]=read(ram,0x0c04d694u,4);
goto P_0c04d666;
P_0c04d666: /* original 420b, guest PC 0x0c04d666 */
if(!s->budget--) { s->failed_pc=0x0c04d666u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d66au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d66au) { target=s->pc; goto dispatch; }
goto P_0c04d66a;
P_0c04d668: /* original 64e3, guest PC 0x0c04d668 */
if(!s->budget--) { s->failed_pc=0x0c04d668u; return 0; }
r[4]=r[14];
goto P_0c04d66a;
P_0c04d66a: /* original 2008, guest PC 0x0c04d66a */
if(!s->budget--) { s->failed_pc=0x0c04d66au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d66c;
P_0c04d66c: /* original 8b14, guest PC 0x0c04d66c */
if(!s->budget--) { s->failed_pc=0x0c04d66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d698; }
goto P_0c04d66e;
P_0c04d66e: /* original bc2e, guest PC 0x0c04d66e */
if(!s->budget--) { s->failed_pc=0x0c04d66eu; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d672u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d672u) { target=s->pc; goto dispatch; }
goto P_0c04d672;
P_0c04d670: /* original 64e3, guest PC 0x0c04d670 */
if(!s->budget--) { s->failed_pc=0x0c04d670u; return 0; }
r[4]=r[14];
goto P_0c04d672;
P_0c04d672: /* original a01c, guest PC 0x0c04d672 */
if(!s->budget--) { s->failed_pc=0x0c04d672u; return 0; }
goto P_0c04d6ae;
P_0c04d674: /* original 0009, guest PC 0x0c04d674 */
if(!s->budget--) { s->failed_pc=0x0c04d674u; return 0; }
if(!vf3_matrix_family(0x0c04d676u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d676u; return 0; } return 1;
P_0c04d698: /* original d334, guest PC 0x0c04d698 */
if(!s->budget--) { s->failed_pc=0x0c04d698u; return 0; }
r[3]=read(ram,0x0c04d76cu,4);
goto P_0c04d69a;
P_0c04d69a: /* original 430b, guest PC 0x0c04d69a */
if(!s->budget--) { s->failed_pc=0x0c04d69au; return 0; }
target=r[3];
r[16]=code_base|0x0c04d69eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d69eu) { target=s->pc; goto dispatch; }
goto P_0c04d69e;
P_0c04d69c: /* original 64e3, guest PC 0x0c04d69c */
if(!s->budget--) { s->failed_pc=0x0c04d69cu; return 0; }
r[4]=r[14];
goto P_0c04d69e;
P_0c04d69e: /* original 2008, guest PC 0x0c04d69e */
if(!s->budget--) { s->failed_pc=0x0c04d69eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d6a0;
P_0c04d6a0: /* original 8905, guest PC 0x0c04d6a0 */
if(!s->budget--) { s->failed_pc=0x0c04d6a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d6ae; }
goto P_0c04d6a2;
P_0c04d6a2: /* original 52f1, guest PC 0x0c04d6a2 */
if(!s->budget--) { s->failed_pc=0x0c04d6a2u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c04d6a4;
P_0c04d6a4: /* original d332, guest PC 0x0c04d6a4 */
if(!s->budget--) { s->failed_pc=0x0c04d6a4u; return 0; }
r[3]=read(ram,0x0c04d770u,4);
goto P_0c04d6a6;
P_0c04d6a6: /* original 323c, guest PC 0x0c04d6a6 */
if(!s->budget--) { s->failed_pc=0x0c04d6a6u; return 0; }
r[2]+=r[3];
goto P_0c04d6a8;
P_0c04d6a8: /* original 8428, guest PC 0x0c04d6a8 */
if(!s->budget--) { s->failed_pc=0x0c04d6a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+8,1);
goto P_0c04d6aa;
P_0c04d6aa: /* original 2008, guest PC 0x0c04d6aa */
if(!s->budget--) { s->failed_pc=0x0c04d6aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d6ac;
P_0c04d6ac: /* original 8b02, guest PC 0x0c04d6ac */
if(!s->budget--) { s->failed_pc=0x0c04d6acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6b4; }
goto P_0c04d6ae;
P_0c04d6ae: /* original 905a, guest PC 0x0c04d6ae */
if(!s->budget--) { s->failed_pc=0x0c04d6aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d766u,2);
goto P_0c04d6b0;
P_0c04d6b0: /* original a02e, guest PC 0x0c04d6b0 */
if(!s->budget--) { s->failed_pc=0x0c04d6b0u; return 0; }
goto P_0c04d710;
P_0c04d6b2: /* original 0009, guest PC 0x0c04d6b2 */
if(!s->budget--) { s->failed_pc=0x0c04d6b2u; return 0; }
goto P_0c04d6b4;
P_0c04d6b4: /* original d32f, guest PC 0x0c04d6b4 */
if(!s->budget--) { s->failed_pc=0x0c04d6b4u; return 0; }
r[3]=read(ram,0x0c04d774u,4);
goto P_0c04d6b6;
P_0c04d6b6: /* original 430b, guest PC 0x0c04d6b6 */
if(!s->budget--) { s->failed_pc=0x0c04d6b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d6bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d6bau) { target=s->pc; goto dispatch; }
goto P_0c04d6ba;
P_0c04d6b8: /* original 64e3, guest PC 0x0c04d6b8 */
if(!s->budget--) { s->failed_pc=0x0c04d6b8u; return 0; }
r[4]=r[14];
goto P_0c04d6ba;
P_0c04d6ba: /* original 4011, guest PC 0x0c04d6ba */
if(!s->budget--) { s->failed_pc=0x0c04d6bau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d6bc;
P_0c04d6bc: /* original 8902, guest PC 0x0c04d6bc */
if(!s->budget--) { s->failed_pc=0x0c04d6bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d6c4; }
goto P_0c04d6be;
P_0c04d6be: /* original 9053, guest PC 0x0c04d6be */
if(!s->budget--) { s->failed_pc=0x0c04d6beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d768u,2);
goto P_0c04d6c0;
P_0c04d6c0: /* original a026, guest PC 0x0c04d6c0 */
if(!s->budget--) { s->failed_pc=0x0c04d6c0u; return 0; }
goto P_0c04d710;
P_0c04d6c2: /* original 0009, guest PC 0x0c04d6c2 */
if(!s->budget--) { s->failed_pc=0x0c04d6c2u; return 0; }
goto P_0c04d6c4;
P_0c04d6c4: /* original 60f2, guest PC 0x0c04d6c4 */
if(!s->budget--) { s->failed_pc=0x0c04d6c4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c04d6c6;
P_0c04d6c6: /* original e400, guest PC 0x0c04d6c6 */
if(!s->budget--) { s->failed_pc=0x0c04d6c6u; return 0; }
r[4]=0x00000000u;
goto P_0c04d6c8;
P_0c04d6c8: /* original dd2b, guest PC 0x0c04d6c8 */
if(!s->budget--) { s->failed_pc=0x0c04d6c8u; return 0; }
r[13]=read(ram,0x0c04d778u,4);
goto P_0c04d6ca;
P_0c04d6ca: /* original 8801, guest PC 0x0c04d6ca */
if(!s->budget--) { s->failed_pc=0x0c04d6cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04d6cc;
P_0c04d6cc: /* original 8f10, guest PC 0x0c04d6cc */
if(!s->budget--) { s->failed_pc=0x0c04d6ccu; return 0; }
cond=r[17]&1u;
r[10]=r[4];
if(!cond) { goto P_0c04d6f0; }
goto P_0c04d6d0;
P_0c04d6ce: /* original 6a43, guest PC 0x0c04d6ce */
if(!s->budget--) { s->failed_pc=0x0c04d6ceu; return 0; }
r[10]=r[4];
goto P_0c04d6d0;
P_0c04d6d0: /* original a008, guest PC 0x0c04d6d0 */
if(!s->budget--) { s->failed_pc=0x0c04d6d0u; return 0; }
r[12]=r[4];
goto P_0c04d6e4;
P_0c04d6d2: /* original 6c43, guest PC 0x0c04d6d2 */
if(!s->budget--) { s->failed_pc=0x0c04d6d2u; return 0; }
r[12]=r[4];
goto P_0c04d6d4;
P_0c04d6d4: /* original d329, guest PC 0x0c04d6d4 */
if(!s->budget--) { s->failed_pc=0x0c04d6d4u; return 0; }
r[3]=read(ram,0x0c04d77cu,4);
goto P_0c04d6d6;
P_0c04d6d6: /* original 65c3, guest PC 0x0c04d6d6 */
if(!s->budget--) { s->failed_pc=0x0c04d6d6u; return 0; }
r[5]=r[12];
goto P_0c04d6d8;
P_0c04d6d8: /* original 430b, guest PC 0x0c04d6d8 */
if(!s->budget--) { s->failed_pc=0x0c04d6d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d6dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d6dcu) { target=s->pc; goto dispatch; }
goto P_0c04d6dc;
P_0c04d6da: /* original 64e3, guest PC 0x0c04d6da */
if(!s->budget--) { s->failed_pc=0x0c04d6dau; return 0; }
r[4]=r[14];
goto P_0c04d6dc;
P_0c04d6dc: /* original 600d, guest PC 0x0c04d6dc */
if(!s->budget--) { s->failed_pc=0x0c04d6dcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d6de;
P_0c04d6de: /* original 30d0, guest PC 0x0c04d6de */
if(!s->budget--) { s->failed_pc=0x0c04d6deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c04d6e0;
P_0c04d6e0: /* original 8b04, guest PC 0x0c04d6e0 */
if(!s->budget--) { s->failed_pc=0x0c04d6e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6ec; }
goto P_0c04d6e2;
P_0c04d6e2: /* original 7c01, guest PC 0x0c04d6e2 */
if(!s->budget--) { s->failed_pc=0x0c04d6e2u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d6e4;
P_0c04d6e4: /* original 52b7, guest PC 0x0c04d6e4 */
if(!s->budget--) { s->failed_pc=0x0c04d6e4u; return 0; }
r[2]=read(ram,r[11]+28,4);
goto P_0c04d6e6;
P_0c04d6e6: /* original 532e, guest PC 0x0c04d6e6 */
if(!s->budget--) { s->failed_pc=0x0c04d6e6u; return 0; }
r[3]=read(ram,r[2]+56,4);
goto P_0c04d6e8;
P_0c04d6e8: /* original 3c33, guest PC 0x0c04d6e8 */
if(!s->budget--) { s->failed_pc=0x0c04d6e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c04d6ea;
P_0c04d6ea: /* original 8bf3, guest PC 0x0c04d6ea */
if(!s->budget--) { s->failed_pc=0x0c04d6eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6d4; }
goto P_0c04d6ec;
P_0c04d6ec: /* original a00f, guest PC 0x0c04d6ec */
if(!s->budget--) { s->failed_pc=0x0c04d6ecu; return 0; }
r[10]=r[12];
goto P_0c04d70e;
P_0c04d6ee: /* original 6ac3, guest PC 0x0c04d6ee */
if(!s->budget--) { s->failed_pc=0x0c04d6eeu; return 0; }
r[10]=r[12];
goto P_0c04d6f0;
P_0c04d6f0: /* original a009, guest PC 0x0c04d6f0 */
if(!s->budget--) { s->failed_pc=0x0c04d6f0u; return 0; }
r[12]=r[4];
goto P_0c04d706;
P_0c04d6f2: /* original 6c43, guest PC 0x0c04d6f2 */
if(!s->budget--) { s->failed_pc=0x0c04d6f2u; return 0; }
r[12]=r[4];
goto P_0c04d6f4;
P_0c04d6f4: /* original d321, guest PC 0x0c04d6f4 */
if(!s->budget--) { s->failed_pc=0x0c04d6f4u; return 0; }
r[3]=read(ram,0x0c04d77cu,4);
goto P_0c04d6f6;
P_0c04d6f6: /* original 65c3, guest PC 0x0c04d6f6 */
if(!s->budget--) { s->failed_pc=0x0c04d6f6u; return 0; }
r[5]=r[12];
goto P_0c04d6f8;
P_0c04d6f8: /* original 430b, guest PC 0x0c04d6f8 */
if(!s->budget--) { s->failed_pc=0x0c04d6f8u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d6fcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d6fcu) { target=s->pc; goto dispatch; }
goto P_0c04d6fc;
P_0c04d6fa: /* original 64e3, guest PC 0x0c04d6fa */
if(!s->budget--) { s->failed_pc=0x0c04d6fau; return 0; }
r[4]=r[14];
goto P_0c04d6fc;
P_0c04d6fc: /* original 600d, guest PC 0x0c04d6fc */
if(!s->budget--) { s->failed_pc=0x0c04d6fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04d6fe;
P_0c04d6fe: /* original 30d0, guest PC 0x0c04d6fe */
if(!s->budget--) { s->failed_pc=0x0c04d6feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c04d700;
P_0c04d700: /* original 8f01, guest PC 0x0c04d700 */
if(!s->budget--) { s->failed_pc=0x0c04d700u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(!cond) { goto P_0c04d706; }
goto P_0c04d704;
P_0c04d702: /* original 7c01, guest PC 0x0c04d702 */
if(!s->budget--) { s->failed_pc=0x0c04d702u; return 0; }
r[12]+=0x00000001u;
goto P_0c04d704;
P_0c04d704: /* original 7a01, guest PC 0x0c04d704 */
if(!s->budget--) { s->failed_pc=0x0c04d704u; return 0; }
r[10]+=0x00000001u;
goto P_0c04d706;
P_0c04d706: /* original 53b7, guest PC 0x0c04d706 */
if(!s->budget--) { s->failed_pc=0x0c04d706u; return 0; }
r[3]=read(ram,r[11]+28,4);
goto P_0c04d708;
P_0c04d708: /* original 523c, guest PC 0x0c04d708 */
if(!s->budget--) { s->failed_pc=0x0c04d708u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c04d70a;
P_0c04d70a: /* original 3c23, guest PC 0x0c04d70a */
if(!s->budget--) { s->failed_pc=0x0c04d70au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[2])!=0);
goto P_0c04d70c;
P_0c04d70c: /* original 8bf2, guest PC 0x0c04d70c */
if(!s->budget--) { s->failed_pc=0x0c04d70cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d6f4; }
goto P_0c04d70e;
P_0c04d70e: /* original 60a3, guest PC 0x0c04d70e */
if(!s->budget--) { s->failed_pc=0x0c04d70eu; return 0; }
r[0]=r[10];
goto P_0c04d710;
P_0c04d710: /* original 7f08, guest PC 0x0c04d710 */
if(!s->budget--) { s->failed_pc=0x0c04d710u; return 0; }
r[15]+=0x00000008u;
goto P_0c04d712;
P_0c04d712: /* original 4f16, guest PC 0x0c04d712 */
if(!s->budget--) { s->failed_pc=0x0c04d712u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d714;
P_0c04d714: /* original 4f26, guest PC 0x0c04d714 */
if(!s->budget--) { s->failed_pc=0x0c04d714u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d716;
P_0c04d716: /* original 6af6, guest PC 0x0c04d716 */
if(!s->budget--) { s->failed_pc=0x0c04d716u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d718;
P_0c04d718: /* original 6bf6, guest PC 0x0c04d718 */
if(!s->budget--) { s->failed_pc=0x0c04d718u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d71a;
P_0c04d71a: /* original 6cf6, guest PC 0x0c04d71a */
if(!s->budget--) { s->failed_pc=0x0c04d71au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d71c;
P_0c04d71c: /* original 6df6, guest PC 0x0c04d71c */
if(!s->budget--) { s->failed_pc=0x0c04d71cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d71e;
P_0c04d71e: /* original 000b, guest PC 0x0c04d71e */
if(!s->budget--) { s->failed_pc=0x0c04d71eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d720: /* original 6ef6, guest PC 0x0c04d720 */
if(!s->budget--) { s->failed_pc=0x0c04d720u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04d722u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d722u; return 0; } return 1;
P_0c04d800: /* original 2fe6, guest PC 0x0c04d800 */
if(!s->budget--) { s->failed_pc=0x0c04d800u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d802;
P_0c04d802: /* original 2fd6, guest PC 0x0c04d802 */
if(!s->budget--) { s->failed_pc=0x0c04d802u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d804;
P_0c04d804: /* original 6d43, guest PC 0x0c04d804 */
if(!s->budget--) { s->failed_pc=0x0c04d804u; return 0; }
r[13]=r[4];
goto P_0c04d806;
P_0c04d806: /* original 2fc6, guest PC 0x0c04d806 */
if(!s->budget--) { s->failed_pc=0x0c04d806u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d808;
P_0c04d808: /* original 6c53, guest PC 0x0c04d808 */
if(!s->budget--) { s->failed_pc=0x0c04d808u; return 0; }
r[12]=r[5];
goto P_0c04d80a;
P_0c04d80a: /* original 2fb6, guest PC 0x0c04d80a */
if(!s->budget--) { s->failed_pc=0x0c04d80au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d80c;
P_0c04d80c: /* original 6b63, guest PC 0x0c04d80c */
if(!s->budget--) { s->failed_pc=0x0c04d80cu; return 0; }
r[11]=r[6];
goto P_0c04d80e;
P_0c04d80e: /* original 2fa6, guest PC 0x0c04d80e */
if(!s->budget--) { s->failed_pc=0x0c04d80eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d810;
P_0c04d810: /* original ea00, guest PC 0x0c04d810 */
if(!s->budget--) { s->failed_pc=0x0c04d810u; return 0; }
r[10]=0x00000000u;
goto P_0c04d812;
P_0c04d812: /* original 4f22, guest PC 0x0c04d812 */
if(!s->budget--) { s->failed_pc=0x0c04d812u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04d814;
P_0c04d814: /* original 2ba2, guest PC 0x0c04d814 */
if(!s->budget--) { s->failed_pc=0x0c04d814u; return 0; }
write(ram,r[11],r[10],4);
goto P_0c04d816;
P_0c04d816: /* original 4f12, guest PC 0x0c04d816 */
if(!s->budget--) { s->failed_pc=0x0c04d816u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04d818;
P_0c04d818: /* original 7fd4, guest PC 0x0c04d818 */
if(!s->budget--) { s->failed_pc=0x0c04d818u; return 0; }
r[15]+=0xffffffd4u;
goto P_0c04d81a;
P_0c04d81a: /* original 2fb6, guest PC 0x0c04d81a */
if(!s->budget--) { s->failed_pc=0x0c04d81au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d81c;
P_0c04d81c: /* original 2fc6, guest PC 0x0c04d81c */
if(!s->budget--) { s->failed_pc=0x0c04d81cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d81e;
P_0c04d81e: /* original 2fd6, guest PC 0x0c04d81e */
if(!s->budget--) { s->failed_pc=0x0c04d81eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d820;
P_0c04d820: /* original d21e, guest PC 0x0c04d820 */
if(!s->budget--) { s->failed_pc=0x0c04d820u; return 0; }
r[2]=read(ram,0x0c04d89cu,4);
goto P_0c04d822;
P_0c04d822: /* original d31d, guest PC 0x0c04d822 */
if(!s->budget--) { s->failed_pc=0x0c04d822u; return 0; }
r[3]=read(ram,0x0c04d898u,4);
goto P_0c04d824;
P_0c04d824: /* original 420b, guest PC 0x0c04d824 */
if(!s->budget--) { s->failed_pc=0x0c04d824u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d828u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d828u) { target=s->pc; goto dispatch; }
goto P_0c04d828;
P_0c04d826: /* original 2f36, guest PC 0x0c04d826 */
if(!s->budget--) { s->failed_pc=0x0c04d826u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d828;
P_0c04d828: /* original 912a, guest PC 0x0c04d828 */
if(!s->budget--) { s->failed_pc=0x0c04d828u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d880u,2);
goto P_0c04d82a;
P_0c04d82a: /* original d01d, guest PC 0x0c04d82a */
if(!s->budget--) { s->failed_pc=0x0c04d82au; return 0; }
r[0]=read(ram,0x0c04d8a0u,4);
goto P_0c04d82c;
P_0c04d82c: /* original 2d1f, guest PC 0x0c04d82c */
if(!s->budget--) { s->failed_pc=0x0c04d82cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[1]);
goto P_0c04d82e;
P_0c04d82e: /* original 011a, guest PC 0x0c04d82e */
if(!s->budget--) { s->failed_pc=0x0c04d82eu; return 0; }
r[1]=r[19];
goto P_0c04d830;
P_0c04d830: /* original 611f, guest PC 0x0c04d830 */
if(!s->budget--) { s->failed_pc=0x0c04d830u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)r[1];
goto P_0c04d832;
P_0c04d832: /* original 031c, guest PC 0x0c04d832 */
if(!s->budget--) { s->failed_pc=0x0c04d832u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c04d834;
P_0c04d834: /* original 2338, guest PC 0x0c04d834 */
if(!s->budget--) { s->failed_pc=0x0c04d834u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d836;
P_0c04d836: /* original 8d16, guest PC 0x0c04d836 */
if(!s->budget--) { s->failed_pc=0x0c04d836u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000010u;
if(cond) { goto P_0c04d866; }
goto P_0c04d83a;
P_0c04d838: /* original 7f10, guest PC 0x0c04d838 */
if(!s->budget--) { s->failed_pc=0x0c04d838u; return 0; }
r[15]+=0x00000010u;
goto P_0c04d83a;
P_0c04d83a: /* original d21a, guest PC 0x0c04d83a */
if(!s->budget--) { s->failed_pc=0x0c04d83au; return 0; }
r[2]=read(ram,0x0c04d8a4u,4);
goto P_0c04d83c;
P_0c04d83c: /* original 420b, guest PC 0x0c04d83c */
if(!s->budget--) { s->failed_pc=0x0c04d83cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d840u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d840u) { target=s->pc; goto dispatch; }
goto P_0c04d840;
P_0c04d83e: /* original 64d3, guest PC 0x0c04d83e */
if(!s->budget--) { s->failed_pc=0x0c04d83eu; return 0; }
r[4]=r[13];
goto P_0c04d840;
P_0c04d840: /* original 2008, guest PC 0x0c04d840 */
if(!s->budget--) { s->failed_pc=0x0c04d840u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d842;
P_0c04d842: /* original 8b03, guest PC 0x0c04d842 */
if(!s->budget--) { s->failed_pc=0x0c04d842u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d84c; }
goto P_0c04d844;
P_0c04d844: /* original bb43, guest PC 0x0c04d844 */
if(!s->budget--) { s->failed_pc=0x0c04d844u; return 0; }
target=code_base|0x0c04ceceu; r[16]=code_base|0x0c04d848u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d848u) { target=s->pc; goto dispatch; }
goto P_0c04d848;
P_0c04d846: /* original 64d3, guest PC 0x0c04d846 */
if(!s->budget--) { s->failed_pc=0x0c04d846u; return 0; }
r[4]=r[13];
goto P_0c04d848;
P_0c04d848: /* original a00d, guest PC 0x0c04d848 */
if(!s->budget--) { s->failed_pc=0x0c04d848u; return 0; }
goto P_0c04d866;
P_0c04d84a: /* original 0009, guest PC 0x0c04d84a */
if(!s->budget--) { s->failed_pc=0x0c04d84au; return 0; }
goto P_0c04d84c;
P_0c04d84c: /* original d30d, guest PC 0x0c04d84c */
if(!s->budget--) { s->failed_pc=0x0c04d84cu; return 0; }
r[3]=read(ram,0x0c04d884u,4);
goto P_0c04d84e;
P_0c04d84e: /* original 430b, guest PC 0x0c04d84e */
if(!s->budget--) { s->failed_pc=0x0c04d84eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d852u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d852u) { target=s->pc; goto dispatch; }
goto P_0c04d852;
P_0c04d850: /* original 64d3, guest PC 0x0c04d850 */
if(!s->budget--) { s->failed_pc=0x0c04d850u; return 0; }
r[4]=r[13];
goto P_0c04d852;
P_0c04d852: /* original 2008, guest PC 0x0c04d852 */
if(!s->budget--) { s->failed_pc=0x0c04d852u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04d854;
P_0c04d854: /* original 8907, guest PC 0x0c04d854 */
if(!s->budget--) { s->failed_pc=0x0c04d854u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d866; }
goto P_0c04d856;
P_0c04d856: /* original 9213, guest PC 0x0c04d856 */
if(!s->budget--) { s->failed_pc=0x0c04d856u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d880u,2);
goto P_0c04d858;
P_0c04d858: /* original d013, guest PC 0x0c04d858 */
if(!s->budget--) { s->failed_pc=0x0c04d858u; return 0; }
r[0]=read(ram,0x0c04d8a8u,4);
goto P_0c04d85a;
P_0c04d85a: /* original 2d2f, guest PC 0x0c04d85a */
if(!s->budget--) { s->failed_pc=0x0c04d85au; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[13]*(int32_t)(int16_t)r[2]);
goto P_0c04d85c;
P_0c04d85c: /* original 021a, guest PC 0x0c04d85c */
if(!s->budget--) { s->failed_pc=0x0c04d85cu; return 0; }
r[2]=r[19];
goto P_0c04d85e;
P_0c04d85e: /* original 622f, guest PC 0x0c04d85e */
if(!s->budget--) { s->failed_pc=0x0c04d85eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04d860;
P_0c04d860: /* original 032c, guest PC 0x0c04d860 */
if(!s->budget--) { s->failed_pc=0x0c04d860u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c04d862;
P_0c04d862: /* original 2338, guest PC 0x0c04d862 */
if(!s->budget--) { s->failed_pc=0x0c04d862u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04d864;
P_0c04d864: /* original 8b02, guest PC 0x0c04d864 */
if(!s->budget--) { s->failed_pc=0x0c04d864u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d86c; }
goto P_0c04d866;
P_0c04d866: /* original 9009, guest PC 0x0c04d866 */
if(!s->budget--) { s->failed_pc=0x0c04d866u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87cu,2);
goto P_0c04d868;
P_0c04d868: /* original a070, guest PC 0x0c04d868 */
if(!s->budget--) { s->failed_pc=0x0c04d868u; return 0; }
goto P_0c04d94c;
P_0c04d86a: /* original 0009, guest PC 0x0c04d86a */
if(!s->budget--) { s->failed_pc=0x0c04d86au; return 0; }
goto P_0c04d86c;
P_0c04d86c: /* original d307, guest PC 0x0c04d86c */
if(!s->budget--) { s->failed_pc=0x0c04d86cu; return 0; }
r[3]=read(ram,0x0c04d88cu,4);
goto P_0c04d86e;
P_0c04d86e: /* original 430b, guest PC 0x0c04d86e */
if(!s->budget--) { s->failed_pc=0x0c04d86eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d872u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d872u) { target=s->pc; goto dispatch; }
goto P_0c04d872;
P_0c04d870: /* original 64d3, guest PC 0x0c04d870 */
if(!s->budget--) { s->failed_pc=0x0c04d870u; return 0; }
r[4]=r[13];
goto P_0c04d872;
P_0c04d872: /* original 4011, guest PC 0x0c04d872 */
if(!s->budget--) { s->failed_pc=0x0c04d872u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d874;
P_0c04d874: /* original 891a, guest PC 0x0c04d874 */
if(!s->budget--) { s->failed_pc=0x0c04d874u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d8ac; }
goto P_0c04d876;
P_0c04d876: /* original 9002, guest PC 0x0c04d876 */
if(!s->budget--) { s->failed_pc=0x0c04d876u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d87eu,2);
goto P_0c04d878;
P_0c04d878: /* original a068, guest PC 0x0c04d878 */
if(!s->budget--) { s->failed_pc=0x0c04d878u; return 0; }
goto P_0c04d94c;
P_0c04d87a: /* original 0009, guest PC 0x0c04d87a */
if(!s->budget--) { s->failed_pc=0x0c04d87au; return 0; }
if(!vf3_matrix_family(0x0c04d87cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04d87cu; return 0; } return 1;
P_0c04d8ac: /* original d345, guest PC 0x0c04d8ac */
if(!s->budget--) { s->failed_pc=0x0c04d8acu; return 0; }
r[3]=read(ram,0x0c04d9c4u,4);
goto P_0c04d8ae;
P_0c04d8ae: /* original 65c3, guest PC 0x0c04d8ae */
if(!s->budget--) { s->failed_pc=0x0c04d8aeu; return 0; }
r[5]=r[12];
goto P_0c04d8b0;
P_0c04d8b0: /* original 430b, guest PC 0x0c04d8b0 */
if(!s->budget--) { s->failed_pc=0x0c04d8b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04d8b4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8b4u) { target=s->pc; goto dispatch; }
goto P_0c04d8b4;
P_0c04d8b2: /* original 64d3, guest PC 0x0c04d8b2 */
if(!s->budget--) { s->failed_pc=0x0c04d8b2u; return 0; }
r[4]=r[13];
goto P_0c04d8b4;
P_0c04d8b4: /* original 4011, guest PC 0x0c04d8b4 */
if(!s->budget--) { s->failed_pc=0x0c04d8b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8b6;
P_0c04d8b6: /* original 8b0e, guest PC 0x0c04d8b6 */
if(!s->budget--) { s->failed_pc=0x0c04d8b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d8d6; }
goto P_0c04d8b8;
P_0c04d8b8: /* original d243, guest PC 0x0c04d8b8 */
if(!s->budget--) { s->failed_pc=0x0c04d8b8u; return 0; }
r[2]=read(ram,0x0c04d9c8u,4);
goto P_0c04d8ba;
P_0c04d8ba: /* original 65c3, guest PC 0x0c04d8ba */
if(!s->budget--) { s->failed_pc=0x0c04d8bau; return 0; }
r[5]=r[12];
goto P_0c04d8bc;
P_0c04d8bc: /* original 420b, guest PC 0x0c04d8bc */
if(!s->budget--) { s->failed_pc=0x0c04d8bcu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d8c0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8c0u) { target=s->pc; goto dispatch; }
goto P_0c04d8c0;
P_0c04d8be: /* original 64d3, guest PC 0x0c04d8be */
if(!s->budget--) { s->failed_pc=0x0c04d8beu; return 0; }
r[4]=r[13];
goto P_0c04d8c0;
P_0c04d8c0: /* original 4011, guest PC 0x0c04d8c0 */
if(!s->budget--) { s->failed_pc=0x0c04d8c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8c2;
P_0c04d8c2: /* original 8902, guest PC 0x0c04d8c2 */
if(!s->budget--) { s->failed_pc=0x0c04d8c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04d8ca; }
goto P_0c04d8c4;
P_0c04d8c4: /* original 9079, guest PC 0x0c04d8c4 */
if(!s->budget--) { s->failed_pc=0x0c04d8c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9bau,2);
goto P_0c04d8c6;
P_0c04d8c6: /* original a041, guest PC 0x0c04d8c6 */
if(!s->budget--) { s->failed_pc=0x0c04d8c6u; return 0; }
goto P_0c04d94c;
P_0c04d8c8: /* original 0009, guest PC 0x0c04d8c8 */
if(!s->budget--) { s->failed_pc=0x0c04d8c8u; return 0; }
goto P_0c04d8ca;
P_0c04d8ca: /* original d240, guest PC 0x0c04d8ca */
if(!s->budget--) { s->failed_pc=0x0c04d8cau; return 0; }
r[2]=read(ram,0x0c04d9ccu,4);
goto P_0c04d8cc;
P_0c04d8cc: /* original 420b, guest PC 0x0c04d8cc */
if(!s->budget--) { s->failed_pc=0x0c04d8ccu; return 0; }
target=r[2];
r[16]=code_base|0x0c04d8d0u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8d0u) { target=s->pc; goto dispatch; }
goto P_0c04d8d0;
P_0c04d8ce: /* original 64d3, guest PC 0x0c04d8ce */
if(!s->budget--) { s->failed_pc=0x0c04d8ceu; return 0; }
r[4]=r[13];
goto P_0c04d8d0;
P_0c04d8d0: /* original 6e03, guest PC 0x0c04d8d0 */
if(!s->budget--) { s->failed_pc=0x0c04d8d0u; return 0; }
r[14]=r[0];
goto P_0c04d8d2;
P_0c04d8d2: /* original 2ee8, guest PC 0x0c04d8d2 */
if(!s->budget--) { s->failed_pc=0x0c04d8d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04d8d4;
P_0c04d8d4: /* original 8b02, guest PC 0x0c04d8d4 */
if(!s->budget--) { s->failed_pc=0x0c04d8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04d8dc; }
goto P_0c04d8d6;
P_0c04d8d6: /* original 9071, guest PC 0x0c04d8d6 */
if(!s->budget--) { s->failed_pc=0x0c04d8d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9bcu,2);
goto P_0c04d8d8;
P_0c04d8d8: /* original a038, guest PC 0x0c04d8d8 */
if(!s->budget--) { s->failed_pc=0x0c04d8d8u; return 0; }
goto P_0c04d94c;
P_0c04d8da: /* original 0009, guest PC 0x0c04d8da */
if(!s->budget--) { s->failed_pc=0x0c04d8dau; return 0; }
goto P_0c04d8dc;
P_0c04d8dc: /* original d23c, guest PC 0x0c04d8dc */
if(!s->budget--) { s->failed_pc=0x0c04d8dcu; return 0; }
r[2]=read(ram,0x0c04d9d0u,4);
goto P_0c04d8de;
P_0c04d8de: /* original 65c3, guest PC 0x0c04d8de */
if(!s->budget--) { s->failed_pc=0x0c04d8deu; return 0; }
r[5]=r[12];
goto P_0c04d8e0;
P_0c04d8e0: /* original 66f3, guest PC 0x0c04d8e0 */
if(!s->budget--) { s->failed_pc=0x0c04d8e0u; return 0; }
r[6]=r[15];
goto P_0c04d8e2;
P_0c04d8e2: /* original 420b, guest PC 0x0c04d8e2 */
if(!s->budget--) { s->failed_pc=0x0c04d8e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d8e6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8e6u) { target=s->pc; goto dispatch; }
goto P_0c04d8e6;
P_0c04d8e4: /* original 64d3, guest PC 0x0c04d8e4 */
if(!s->budget--) { s->failed_pc=0x0c04d8e4u; return 0; }
r[4]=r[13];
goto P_0c04d8e6;
P_0c04d8e6: /* original d33b, guest PC 0x0c04d8e6 */
if(!s->budget--) { s->failed_pc=0x0c04d8e6u; return 0; }
r[3]=read(ram,0x0c04d9d4u,4);
goto P_0c04d8e8;
P_0c04d8e8: /* original 4011, guest PC 0x0c04d8e8 */
if(!s->budget--) { s->failed_pc=0x0c04d8e8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04d8ea;
P_0c04d8ea: /* original 8d06, guest PC 0x0c04d8ea */
if(!s->budget--) { s->failed_pc=0x0c04d8eau; return 0; }
cond=r[17]&1u;
write(ram,r[3],r[0],4);
if(cond) { goto P_0c04d8fa; }
goto P_0c04d8ee;
P_0c04d8ec: /* original 2302, guest PC 0x0c04d8ec */
if(!s->budget--) { s->failed_pc=0x0c04d8ecu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c04d8ee;
P_0c04d8ee: /* original d13a, guest PC 0x0c04d8ee */
if(!s->budget--) { s->failed_pc=0x0c04d8eeu; return 0; }
r[1]=read(ram,0x0c04d9d8u,4);
goto P_0c04d8f0;
P_0c04d8f0: /* original 410b, guest PC 0x0c04d8f0 */
if(!s->budget--) { s->failed_pc=0x0c04d8f0u; return 0; }
target=r[1];
r[16]=code_base|0x0c04d8f4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d8f4u) { target=s->pc; goto dispatch; }
goto P_0c04d8f4;
P_0c04d8f2: /* original 64e3, guest PC 0x0c04d8f2 */
if(!s->budget--) { s->failed_pc=0x0c04d8f2u; return 0; }
r[4]=r[14];
goto P_0c04d8f4;
P_0c04d8f4: /* original 9063, guest PC 0x0c04d8f4 */
if(!s->budget--) { s->failed_pc=0x0c04d8f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04d9beu,2);
goto P_0c04d8f6;
P_0c04d8f6: /* original a029, guest PC 0x0c04d8f6 */
if(!s->budget--) { s->failed_pc=0x0c04d8f6u; return 0; }
goto P_0c04d94c;
P_0c04d8f8: /* original 0009, guest PC 0x0c04d8f8 */
if(!s->budget--) { s->failed_pc=0x0c04d8f8u; return 0; }
goto P_0c04d8fa;
P_0c04d8fa: /* original e040, guest PC 0x0c04d8fa */
if(!s->budget--) { s->failed_pc=0x0c04d8fau; return 0; }
r[0]=0x00000040u;
goto P_0c04d8fc;
P_0c04d8fc: /* original 1ea1, guest PC 0x0c04d8fc */
if(!s->budget--) { s->failed_pc=0x0c04d8fcu; return 0; }
write(ram,r[14]+4,r[10],4);
goto P_0c04d8fe;
P_0c04d8fe: /* original 53fa, guest PC 0x0c04d8fe */
if(!s->budget--) { s->failed_pc=0x0c04d8feu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c04d900;
P_0c04d900: /* original 1e3d, guest PC 0x0c04d900 */
if(!s->budget--) { s->failed_pc=0x0c04d900u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c04d902;
P_0c04d902: /* original 52f3, guest PC 0x0c04d902 */
if(!s->budget--) { s->failed_pc=0x0c04d902u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c04d904;
P_0c04d904: /* original 1e2e, guest PC 0x0c04d904 */
if(!s->budget--) { s->failed_pc=0x0c04d904u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c04d906;
P_0c04d906: /* original 6323, guest PC 0x0c04d906 */
if(!s->budget--) { s->failed_pc=0x0c04d906u; return 0; }
r[3]=r[2];
goto P_0c04d908;
P_0c04d908: /* original 0e26, guest PC 0x0c04d908 */
if(!s->budget--) { s->failed_pc=0x0c04d908u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c04d90a;
P_0c04d90a: /* original 1eda, guest PC 0x0c04d90a */
if(!s->budget--) { s->failed_pc=0x0c04d90au; return 0; }
write(ram,r[14]+40,r[13],4);
goto P_0c04d90c;
P_0c04d90c: /* original 85f4, guest PC 0x0c04d90c */
if(!s->budget--) { s->failed_pc=0x0c04d90cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c04d90e;
P_0c04d90e: /* original 81e1, guest PC 0x0c04d90e */
if(!s->budget--) { s->failed_pc=0x0c04d90eu; return 0; }
write(ram,r[14]+2,r[0],2);
goto P_0c04d910;
P_0c04d910: /* original 84fa, guest PC 0x0c04d910 */
if(!s->budget--) { s->failed_pc=0x0c04d910u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+10,1);
goto P_0c04d912;
P_0c04d912: /* original 80e1, guest PC 0x0c04d912 */
if(!s->budget--) { s->failed_pc=0x0c04d912u; return 0; }
write(ram,r[14]+1,r[0],1);
goto P_0c04d914;
P_0c04d914: /* original 53e1, guest PC 0x0c04d914 */
if(!s->budget--) { s->failed_pc=0x0c04d914u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c04d916;
P_0c04d916: /* original 2f36, guest PC 0x0c04d916 */
if(!s->budget--) { s->failed_pc=0x0c04d916u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d918;
P_0c04d918: /* original d331, guest PC 0x0c04d918 */
if(!s->budget--) { s->failed_pc=0x0c04d918u; return 0; }
r[3]=read(ram,0x0c04d9e0u,4);
goto P_0c04d91a;
P_0c04d91a: /* original d230, guest PC 0x0c04d91a */
if(!s->budget--) { s->failed_pc=0x0c04d91au; return 0; }
r[2]=read(ram,0x0c04d9dcu,4);
goto P_0c04d91c;
P_0c04d91c: /* original 430b, guest PC 0x0c04d91c */
if(!s->budget--) { s->failed_pc=0x0c04d91cu; return 0; }
target=r[3];
r[16]=code_base|0x0c04d920u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d920u) { target=s->pc; goto dispatch; }
goto P_0c04d920;
P_0c04d91e: /* original 2f26, guest PC 0x0c04d91e */
if(!s->budget--) { s->failed_pc=0x0c04d91eu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d920;
P_0c04d920: /* original 51ed, guest PC 0x0c04d920 */
if(!s->budget--) { s->failed_pc=0x0c04d920u; return 0; }
r[1]=read(ram,r[14]+52,4);
goto P_0c04d922;
P_0c04d922: /* original 2f16, guest PC 0x0c04d922 */
if(!s->budget--) { s->failed_pc=0x0c04d922u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d924;
P_0c04d924: /* original d32f, guest PC 0x0c04d924 */
if(!s->budget--) { s->failed_pc=0x0c04d924u; return 0; }
r[3]=read(ram,0x0c04d9e4u,4);
goto P_0c04d926;
P_0c04d926: /* original d22e, guest PC 0x0c04d926 */
if(!s->budget--) { s->failed_pc=0x0c04d926u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d928;
P_0c04d928: /* original 420b, guest PC 0x0c04d928 */
if(!s->budget--) { s->failed_pc=0x0c04d928u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d92cu;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d92cu) { target=s->pc; goto dispatch; }
goto P_0c04d92c;
P_0c04d92a: /* original 2f36, guest PC 0x0c04d92a */
if(!s->budget--) { s->failed_pc=0x0c04d92au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d92c;
P_0c04d92c: /* original 51ee, guest PC 0x0c04d92c */
if(!s->budget--) { s->failed_pc=0x0c04d92cu; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c04d92e;
P_0c04d92e: /* original 2f16, guest PC 0x0c04d92e */
if(!s->budget--) { s->failed_pc=0x0c04d92eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d930;
P_0c04d930: /* original d32d, guest PC 0x0c04d930 */
if(!s->budget--) { s->failed_pc=0x0c04d930u; return 0; }
r[3]=read(ram,0x0c04d9e8u,4);
goto P_0c04d932;
P_0c04d932: /* original d22b, guest PC 0x0c04d932 */
if(!s->budget--) { s->failed_pc=0x0c04d932u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d934;
P_0c04d934: /* original 420b, guest PC 0x0c04d934 */
if(!s->budget--) { s->failed_pc=0x0c04d934u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d938u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d938u) { target=s->pc; goto dispatch; }
goto P_0c04d938;
P_0c04d936: /* original 2f36, guest PC 0x0c04d936 */
if(!s->budget--) { s->failed_pc=0x0c04d936u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d938;
P_0c04d938: /* original e040, guest PC 0x0c04d938 */
if(!s->budget--) { s->failed_pc=0x0c04d938u; return 0; }
r[0]=0x00000040u;
goto P_0c04d93a;
P_0c04d93a: /* original 01ee, guest PC 0x0c04d93a */
if(!s->budget--) { s->failed_pc=0x0c04d93au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c04d93c;
P_0c04d93c: /* original 2f16, guest PC 0x0c04d93c */
if(!s->budget--) { s->failed_pc=0x0c04d93cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d93e;
P_0c04d93e: /* original d32b, guest PC 0x0c04d93e */
if(!s->budget--) { s->failed_pc=0x0c04d93eu; return 0; }
r[3]=read(ram,0x0c04d9ecu,4);
goto P_0c04d940;
P_0c04d940: /* original d227, guest PC 0x0c04d940 */
if(!s->budget--) { s->failed_pc=0x0c04d940u; return 0; }
r[2]=read(ram,0x0c04d9e0u,4);
goto P_0c04d942;
P_0c04d942: /* original 420b, guest PC 0x0c04d942 */
if(!s->budget--) { s->failed_pc=0x0c04d942u; return 0; }
target=r[2];
r[16]=code_base|0x0c04d946u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04d946u) { target=s->pc; goto dispatch; }
goto P_0c04d946;
P_0c04d944: /* original 2f36, guest PC 0x0c04d944 */
if(!s->budget--) { s->failed_pc=0x0c04d944u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04d946;
P_0c04d946: /* original 60a3, guest PC 0x0c04d946 */
if(!s->budget--) { s->failed_pc=0x0c04d946u; return 0; }
r[0]=r[10];
goto P_0c04d948;
P_0c04d948: /* original 2be2, guest PC 0x0c04d948 */
if(!s->budget--) { s->failed_pc=0x0c04d948u; return 0; }
write(ram,r[11],r[14],4);
goto P_0c04d94a;
P_0c04d94a: /* original 7f20, guest PC 0x0c04d94a */
if(!s->budget--) { s->failed_pc=0x0c04d94au; return 0; }
r[15]+=0x00000020u;
goto P_0c04d94c;
P_0c04d94c: /* original 7f2c, guest PC 0x0c04d94c */
if(!s->budget--) { s->failed_pc=0x0c04d94cu; return 0; }
r[15]+=0x0000002cu;
goto P_0c04d94e;
P_0c04d94e: /* original 4f16, guest PC 0x0c04d94e */
if(!s->budget--) { s->failed_pc=0x0c04d94eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d950;
P_0c04d950: /* original 4f26, guest PC 0x0c04d950 */
if(!s->budget--) { s->failed_pc=0x0c04d950u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04d952;
P_0c04d952: /* original 6af6, guest PC 0x0c04d952 */
if(!s->budget--) { s->failed_pc=0x0c04d952u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04d954;
P_0c04d954: /* original 6bf6, guest PC 0x0c04d954 */
if(!s->budget--) { s->failed_pc=0x0c04d954u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04d956;
P_0c04d956: /* original 6cf6, guest PC 0x0c04d956 */
if(!s->budget--) { s->failed_pc=0x0c04d956u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04d958;
P_0c04d958: /* original 6df6, guest PC 0x0c04d958 */
if(!s->budget--) { s->failed_pc=0x0c04d958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04d95a;
P_0c04d95a: /* original 000b, guest PC 0x0c04d95a */
if(!s->budget--) { s->failed_pc=0x0c04d95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04d95c: /* original 6ef6, guest PC 0x0c04d95c */
if(!s->budget--) { s->failed_pc=0x0c04d95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04d95eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
