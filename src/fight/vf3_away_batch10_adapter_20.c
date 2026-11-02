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
int vf3_away_batch10_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06d770u: goto P_0c06d770;
case 0x0c06d772u: goto P_0c06d772;
case 0x0c06d774u: goto P_0c06d774;
case 0x0c06d776u: goto P_0c06d776;
case 0x0c06d778u: goto P_0c06d778;
case 0x0c06d77au: goto P_0c06d77a;
case 0x0c06d77cu: goto P_0c06d77c;
case 0x0c06d77eu: goto P_0c06d77e;
case 0x0c06d780u: goto P_0c06d780;
case 0x0c06d782u: goto P_0c06d782;
case 0x0c06d784u: goto P_0c06d784;
case 0x0c06d786u: goto P_0c06d786;
case 0x0c06d788u: goto P_0c06d788;
case 0x0c06d78au: goto P_0c06d78a;
case 0x0c06d78cu: goto P_0c06d78c;
case 0x0c06d78eu: goto P_0c06d78e;
case 0x0c06d790u: goto P_0c06d790;
case 0x0c06d838u: goto P_0c06d838;
case 0x0c06d83au: goto P_0c06d83a;
case 0x0c06d83cu: goto P_0c06d83c;
case 0x0c06d83eu: goto P_0c06d83e;
case 0x0c06d840u: goto P_0c06d840;
case 0x0c06d842u: goto P_0c06d842;
case 0x0c06d844u: goto P_0c06d844;
case 0x0c06d846u: goto P_0c06d846;
case 0x0c06d848u: goto P_0c06d848;
case 0x0c06d84au: goto P_0c06d84a;
case 0x0c06d84cu: goto P_0c06d84c;
case 0x0c06d84eu: goto P_0c06d84e;
case 0x0c06d850u: goto P_0c06d850;
case 0x0c06d852u: goto P_0c06d852;
case 0x0c06d854u: goto P_0c06d854;
case 0x0c06d856u: goto P_0c06d856;
case 0x0c06d858u: goto P_0c06d858;
case 0x0c06d85au: goto P_0c06d85a;
case 0x0c06d85cu: goto P_0c06d85c;
case 0x0c06d85eu: goto P_0c06d85e;
case 0x0c06d860u: goto P_0c06d860;
case 0x0c06d862u: goto P_0c06d862;
case 0x0c06d864u: goto P_0c06d864;
case 0x0c06d866u: goto P_0c06d866;
case 0x0c06d868u: goto P_0c06d868;
case 0x0c06d86au: goto P_0c06d86a;
case 0x0c06d86cu: goto P_0c06d86c;
case 0x0c06d86eu: goto P_0c06d86e;
case 0x0c06d870u: goto P_0c06d870;
case 0x0c06d872u: goto P_0c06d872;
case 0x0c06d874u: goto P_0c06d874;
case 0x0c06d876u: goto P_0c06d876;
case 0x0c06d878u: goto P_0c06d878;
case 0x0c06d87au: goto P_0c06d87a;
case 0x0c06d8b0u: goto P_0c06d8b0;
case 0x0c06d8b2u: goto P_0c06d8b2;
case 0x0c06d8b4u: goto P_0c06d8b4;
case 0x0c06d8b6u: goto P_0c06d8b6;
case 0x0c06d8b8u: goto P_0c06d8b8;
case 0x0c06d8bau: goto P_0c06d8ba;
case 0x0c06d8bcu: goto P_0c06d8bc;
case 0x0c06d8beu: goto P_0c06d8be;
case 0x0c06d8c0u: goto P_0c06d8c0;
case 0x0c06d8c2u: goto P_0c06d8c2;
case 0x0c06d8c4u: goto P_0c06d8c4;
case 0x0c06d8c6u: goto P_0c06d8c6;
case 0x0c06d8c8u: goto P_0c06d8c8;
case 0x0c06d8cau: goto P_0c06d8ca;
case 0x0c06d8ccu: goto P_0c06d8cc;
case 0x0c06d8ceu: goto P_0c06d8ce;
case 0x0c06d8d0u: goto P_0c06d8d0;
case 0x0c06d8d2u: goto P_0c06d8d2;
case 0x0c06d8d4u: goto P_0c06d8d4;
case 0x0c06d8d6u: goto P_0c06d8d6;
case 0x0c06d8d8u: goto P_0c06d8d8;
case 0x0c06d8dau: goto P_0c06d8da;
case 0x0c06d8dcu: goto P_0c06d8dc;
case 0x0c06d8deu: goto P_0c06d8de;
case 0x0c06d8e0u: goto P_0c06d8e0;
case 0x0c06d8e2u: goto P_0c06d8e2;
case 0x0c06d8e4u: goto P_0c06d8e4;
case 0x0c06d8e6u: goto P_0c06d8e6;
case 0x0c06d8e8u: goto P_0c06d8e8;
case 0x0c06d8eau: goto P_0c06d8ea;
case 0x0c06d8ecu: goto P_0c06d8ec;
case 0x0c06d8eeu: goto P_0c06d8ee;
case 0x0c06d8f0u: goto P_0c06d8f0;
case 0x0c06d8f2u: goto P_0c06d8f2;
case 0x0c06d8f4u: goto P_0c06d8f4;
case 0x0c06d8f6u: goto P_0c06d8f6;
case 0x0c06d8f8u: goto P_0c06d8f8;
case 0x0c06d8fau: goto P_0c06d8fa;
case 0x0c06d8fcu: goto P_0c06d8fc;
case 0x0c06d8feu: goto P_0c06d8fe;
case 0x0c06d900u: goto P_0c06d900;
case 0x0c06d902u: goto P_0c06d902;
case 0x0c06d904u: goto P_0c06d904;
case 0x0c06d906u: goto P_0c06d906;
case 0x0c06d908u: goto P_0c06d908;
case 0x0c06d90au: goto P_0c06d90a;
case 0x0c06d90cu: goto P_0c06d90c;
case 0x0c06d90eu: goto P_0c06d90e;
case 0x0c06d910u: goto P_0c06d910;
case 0x0c06d912u: goto P_0c06d912;
case 0x0c06d914u: goto P_0c06d914;
case 0x0c06d916u: goto P_0c06d916;
case 0x0c06d918u: goto P_0c06d918;
case 0x0c06d91au: goto P_0c06d91a;
case 0x0c06d91cu: goto P_0c06d91c;
case 0x0c06d91eu: goto P_0c06d91e;
case 0x0c06d920u: goto P_0c06d920;
case 0x0c06d922u: goto P_0c06d922;
case 0x0c06d924u: goto P_0c06d924;
case 0x0c06d926u: goto P_0c06d926;
case 0x0c06d928u: goto P_0c06d928;
case 0x0c06d92au: goto P_0c06d92a;
case 0x0c06d92cu: goto P_0c06d92c;
case 0x0c06d92eu: goto P_0c06d92e;
case 0x0c06d930u: goto P_0c06d930;
case 0x0c06d932u: goto P_0c06d932;
case 0x0c06d934u: goto P_0c06d934;
case 0x0c06d936u: goto P_0c06d936;
case 0x0c06d938u: goto P_0c06d938;
case 0x0c06d93au: goto P_0c06d93a;
case 0x0c06d93cu: goto P_0c06d93c;
case 0x0c06d93eu: goto P_0c06d93e;
case 0x0c06d940u: goto P_0c06d940;
case 0x0c06d942u: goto P_0c06d942;
case 0x0c06d944u: goto P_0c06d944;
case 0x0c06d946u: goto P_0c06d946;
case 0x0c06d948u: goto P_0c06d948;
case 0x0c06d94au: goto P_0c06d94a;
case 0x0c06d94cu: goto P_0c06d94c;
case 0x0c06d94eu: goto P_0c06d94e;
case 0x0c06d950u: goto P_0c06d950;
case 0x0c06d952u: goto P_0c06d952;
case 0x0c06d954u: goto P_0c06d954;
case 0x0c06d956u: goto P_0c06d956;
case 0x0c06d958u: goto P_0c06d958;
case 0x0c06d95au: goto P_0c06d95a;
case 0x0c06d95cu: goto P_0c06d95c;
case 0x0c06d95eu: goto P_0c06d95e;
case 0x0c06d960u: goto P_0c06d960;
case 0x0c06d962u: goto P_0c06d962;
case 0x0c06d964u: goto P_0c06d964;
case 0x0c06d966u: goto P_0c06d966;
case 0x0c06d968u: goto P_0c06d968;
case 0x0c06d96au: goto P_0c06d96a;
case 0x0c06d96cu: goto P_0c06d96c;
case 0x0c06d96eu: goto P_0c06d96e;
case 0x0c06d970u: goto P_0c06d970;
case 0x0c06d972u: goto P_0c06d972;
case 0x0c06d974u: goto P_0c06d974;
case 0x0c06d976u: goto P_0c06d976;
case 0x0c06d978u: goto P_0c06d978;
case 0x0c06d97au: goto P_0c06d97a;
case 0x0c06d97cu: goto P_0c06d97c;
case 0x0c06d97eu: goto P_0c06d97e;
case 0x0c06d980u: goto P_0c06d980;
case 0x0c06d982u: goto P_0c06d982;
case 0x0c06d984u: goto P_0c06d984;
case 0x0c06d986u: goto P_0c06d986;
case 0x0c06d988u: goto P_0c06d988;
case 0x0c06d98au: goto P_0c06d98a;
case 0x0c06d98cu: goto P_0c06d98c;
case 0x0c06d98eu: goto P_0c06d98e;
case 0x0c06d990u: goto P_0c06d990;
case 0x0c06d992u: goto P_0c06d992;
case 0x0c06d994u: goto P_0c06d994;
case 0x0c06d996u: goto P_0c06d996;
case 0x0c06d998u: goto P_0c06d998;
case 0x0c06d99au: goto P_0c06d99a;
case 0x0c06d99cu: goto P_0c06d99c;
case 0x0c06d99eu: goto P_0c06d99e;
case 0x0c06d9a0u: goto P_0c06d9a0;
case 0x0c06d9a2u: goto P_0c06d9a2;
case 0x0c06d9a4u: goto P_0c06d9a4;
case 0x0c06d9a6u: goto P_0c06d9a6;
case 0x0c06d9a8u: goto P_0c06d9a8;
case 0x0c06d9aau: goto P_0c06d9aa;
case 0x0c06d9acu: goto P_0c06d9ac;
case 0x0c06d9aeu: goto P_0c06d9ae;
case 0x0c06d9b0u: goto P_0c06d9b0;
case 0x0c06d9b2u: goto P_0c06d9b2;
case 0x0c06d9b4u: goto P_0c06d9b4;
case 0x0c06d9d4u: goto P_0c06d9d4;
case 0x0c06d9d6u: goto P_0c06d9d6;
case 0x0c06d9d8u: goto P_0c06d9d8;
case 0x0c06d9dau: goto P_0c06d9da;
case 0x0c06d9dcu: goto P_0c06d9dc;
case 0x0c06d9deu: goto P_0c06d9de;
case 0x0c06d9e0u: goto P_0c06d9e0;
case 0x0c06d9e2u: goto P_0c06d9e2;
case 0x0c06d9e4u: goto P_0c06d9e4;
case 0x0c06d9e6u: goto P_0c06d9e6;
case 0x0c06d9e8u: goto P_0c06d9e8;
case 0x0c06d9eau: goto P_0c06d9ea;
case 0x0c06d9ecu: goto P_0c06d9ec;
case 0x0c06d9eeu: goto P_0c06d9ee;
case 0x0c06d9f0u: goto P_0c06d9f0;
case 0x0c06d9f2u: goto P_0c06d9f2;
case 0x0c06d9f4u: goto P_0c06d9f4;
case 0x0c06d9f6u: goto P_0c06d9f6;
case 0x0c06d9f8u: goto P_0c06d9f8;
case 0x0c06d9fau: goto P_0c06d9fa;
case 0x0c06d9fcu: goto P_0c06d9fc;
case 0x0c06d9feu: goto P_0c06d9fe;
case 0x0c06da00u: goto P_0c06da00;
case 0x0c06da02u: goto P_0c06da02;
case 0x0c06da04u: goto P_0c06da04;
case 0x0c06da06u: goto P_0c06da06;
case 0x0c06da08u: goto P_0c06da08;
case 0x0c06da0au: goto P_0c06da0a;
case 0x0c06da0cu: goto P_0c06da0c;
case 0x0c06da0eu: goto P_0c06da0e;
case 0x0c06da10u: goto P_0c06da10;
case 0x0c06da12u: goto P_0c06da12;
case 0x0c06da14u: goto P_0c06da14;
case 0x0c06da16u: goto P_0c06da16;
case 0x0c06da18u: goto P_0c06da18;
case 0x0c06da1au: goto P_0c06da1a;
case 0x0c06da1cu: goto P_0c06da1c;
case 0x0c06da1eu: goto P_0c06da1e;
case 0x0c06da20u: goto P_0c06da20;
case 0x0c06da22u: goto P_0c06da22;
case 0x0c06da24u: goto P_0c06da24;
case 0x0c06da26u: goto P_0c06da26;
case 0x0c06da28u: goto P_0c06da28;
case 0x0c06da2au: goto P_0c06da2a;
case 0x0c06da2cu: goto P_0c06da2c;
case 0x0c06da2eu: goto P_0c06da2e;
case 0x0c06da30u: goto P_0c06da30;
case 0x0c06da32u: goto P_0c06da32;
case 0x0c06da34u: goto P_0c06da34;
case 0x0c06da36u: goto P_0c06da36;
case 0x0c06da38u: goto P_0c06da38;
case 0x0c06da3au: goto P_0c06da3a;
case 0x0c06da3cu: goto P_0c06da3c;
case 0x0c06da3eu: goto P_0c06da3e;
case 0x0c06da40u: goto P_0c06da40;
case 0x0c06da42u: goto P_0c06da42;
case 0x0c06da44u: goto P_0c06da44;
case 0x0c06da46u: goto P_0c06da46;
case 0x0c06da48u: goto P_0c06da48;
case 0x0c06da4au: goto P_0c06da4a;
case 0x0c06da4cu: goto P_0c06da4c;
case 0x0c06da4eu: goto P_0c06da4e;
case 0x0c06da50u: goto P_0c06da50;
case 0x0c06da52u: goto P_0c06da52;
case 0x0c06da54u: goto P_0c06da54;
case 0x0c06da56u: goto P_0c06da56;
case 0x0c06da58u: goto P_0c06da58;
case 0x0c06da5au: goto P_0c06da5a;
case 0x0c06da5cu: goto P_0c06da5c;
case 0x0c06da5eu: goto P_0c06da5e;
case 0x0c06da60u: goto P_0c06da60;
case 0x0c06da62u: goto P_0c06da62;
case 0x0c06da64u: goto P_0c06da64;
case 0x0c06da66u: goto P_0c06da66;
case 0x0c06da68u: goto P_0c06da68;
case 0x0c06da6au: goto P_0c06da6a;
case 0x0c06da6cu: goto P_0c06da6c;
case 0x0c06da6eu: goto P_0c06da6e;
case 0x0c06da70u: goto P_0c06da70;
case 0x0c06da72u: goto P_0c06da72;
case 0x0c06da74u: goto P_0c06da74;
case 0x0c06da76u: goto P_0c06da76;
case 0x0c06da78u: goto P_0c06da78;
case 0x0c06da7au: goto P_0c06da7a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06d770: /* original d34a, guest PC 0x0c06d770 */
if(!s->budget--) { s->failed_pc=0x0c06d770u; return 0; }
r[3]=read(ram,0x0c06d89cu,4);
goto P_0c06d772;
P_0c06d772: /* original 4f22, guest PC 0x0c06d772 */
if(!s->budget--) { s->failed_pc=0x0c06d772u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d774;
P_0c06d774: /* original 6030, guest PC 0x0c06d774 */
if(!s->budget--) { s->failed_pc=0x0c06d774u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c06d776;
P_0c06d776: /* original 600c, guest PC 0x0c06d776 */
if(!s->budget--) { s->failed_pc=0x0c06d776u; return 0; }
r[0]=r[0]&255u;
goto P_0c06d778;
P_0c06d778: /* original c90f, guest PC 0x0c06d778 */
if(!s->budget--) { s->failed_pc=0x0c06d778u; return 0; }
r[0]&=15u;
goto P_0c06d77a;
P_0c06d77a: /* original 7ffc, guest PC 0x0c06d77a */
if(!s->budget--) { s->failed_pc=0x0c06d77au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06d77c;
P_0c06d77c: /* original 2f02, guest PC 0x0c06d77c */
if(!s->budget--) { s->failed_pc=0x0c06d77cu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06d77e;
P_0c06d77e: /* original 4008, guest PC 0x0c06d77e */
if(!s->budget--) { s->failed_pc=0x0c06d77eu; return 0; }
r[0]<<=2;
goto P_0c06d780;
P_0c06d780: /* original d147, guest PC 0x0c06d780 */
if(!s->budget--) { s->failed_pc=0x0c06d780u; return 0; }
r[1]=read(ram,0x0c06d8a0u,4);
goto P_0c06d782;
P_0c06d782: /* original 021e, guest PC 0x0c06d782 */
if(!s->budget--) { s->failed_pc=0x0c06d782u; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c06d784;
P_0c06d784: /* original 420b, guest PC 0x0c06d784 */
if(!s->budget--) { s->failed_pc=0x0c06d784u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d788u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d788u) { target=s->pc; goto dispatch; }
goto P_0c06d788;
P_0c06d786: /* original 0009, guest PC 0x0c06d786 */
if(!s->budget--) { s->failed_pc=0x0c06d786u; return 0; }
goto P_0c06d788;
P_0c06d788: /* original 7f04, guest PC 0x0c06d788 */
if(!s->budget--) { s->failed_pc=0x0c06d788u; return 0; }
r[15]+=0x00000004u;
goto P_0c06d78a;
P_0c06d78a: /* original d446, guest PC 0x0c06d78a */
if(!s->budget--) { s->failed_pc=0x0c06d78au; return 0; }
r[4]=read(ram,0x0c06d8a4u,4);
goto P_0c06d78c;
P_0c06d78c: /* original 4f26, guest PC 0x0c06d78c */
if(!s->budget--) { s->failed_pc=0x0c06d78cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06d78e;
P_0c06d78e: /* original 000b, guest PC 0x0c06d78e */
if(!s->budget--) { s->failed_pc=0x0c06d78eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06d790: /* original 0009, guest PC 0x0c06d790 */
if(!s->budget--) { s->failed_pc=0x0c06d790u; return 0; }
if(!vf3_matrix_family(0x0c06d792u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d792u; return 0; } return 1;
P_0c06d838: /* original 2fe6, guest PC 0x0c06d838 */
if(!s->budget--) { s->failed_pc=0x0c06d838u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d83a;
P_0c06d83a: /* original 6e43, guest PC 0x0c06d83a */
if(!s->budget--) { s->failed_pc=0x0c06d83au; return 0; }
r[14]=r[4];
goto P_0c06d83c;
P_0c06d83c: /* original 9022, guest PC 0x0c06d83c */
if(!s->budget--) { s->failed_pc=0x0c06d83cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d884u,2);
goto P_0c06d83e;
P_0c06d83e: /* original f38d, guest PC 0x0c06d83e */
if(!s->budget--) { s->failed_pc=0x0c06d83eu; return 0; }
fr[3]=0;
goto P_0c06d840;
P_0c06d840: /* original f4e6, guest PC 0x0c06d840 */
if(!s->budget--) { s->failed_pc=0x0c06d840u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c06d842;
P_0c06d842: /* original f434, guest PC 0x0c06d842 */
if(!s->budget--) { s->failed_pc=0x0c06d842u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c06d844;
P_0c06d844: /* original 8918, guest PC 0x0c06d844 */
if(!s->budget--) { s->failed_pc=0x0c06d844u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d878; }
goto P_0c06d846;
P_0c06d846: /* original 921e, guest PC 0x0c06d846 */
if(!s->budget--) { s->failed_pc=0x0c06d846u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d886u,2);
goto P_0c06d848;
P_0c06d848: /* original 64e2, guest PC 0x0c06d848 */
if(!s->budget--) { s->failed_pc=0x0c06d848u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c06d84a;
P_0c06d84a: /* original 2428, guest PC 0x0c06d84a */
if(!s->budget--) { s->failed_pc=0x0c06d84au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c06d84c;
P_0c06d84c: /* original 8b14, guest PC 0x0c06d84c */
if(!s->budget--) { s->failed_pc=0x0c06d84cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d878; }
goto P_0c06d84e;
P_0c06d84e: /* original d117, guest PC 0x0c06d84e */
if(!s->budget--) { s->failed_pc=0x0c06d84eu; return 0; }
r[1]=read(ram,0x0c06d8acu,4);
goto P_0c06d850;
P_0c06d850: /* original 6410, guest PC 0x0c06d850 */
if(!s->budget--) { s->failed_pc=0x0c06d850u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[4]=tmp;
goto P_0c06d852;
P_0c06d852: /* original 604c, guest PC 0x0c06d852 */
if(!s->budget--) { s->failed_pc=0x0c06d852u; return 0; }
r[0]=r[4]&255u;
goto P_0c06d854;
P_0c06d854: /* original 8804, guest PC 0x0c06d854 */
if(!s->budget--) { s->failed_pc=0x0c06d854u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c06d856;
P_0c06d856: /* original 8d0f, guest PC 0x0c06d856 */
if(!s->budget--) { s->failed_pc=0x0c06d856u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c06d878; }
goto P_0c06d85a;
P_0c06d858: /* original 6403, guest PC 0x0c06d858 */
if(!s->budget--) { s->failed_pc=0x0c06d858u; return 0; }
r[4]=r[0];
goto P_0c06d85a;
P_0c06d85a: /* original 6043, guest PC 0x0c06d85a */
if(!s->budget--) { s->failed_pc=0x0c06d85au; return 0; }
r[0]=r[4];
goto P_0c06d85c;
P_0c06d85c: /* original 8805, guest PC 0x0c06d85c */
if(!s->budget--) { s->failed_pc=0x0c06d85cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c06d85e;
P_0c06d85e: /* original 890b, guest PC 0x0c06d85e */
if(!s->budget--) { s->failed_pc=0x0c06d85eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06d878; }
goto P_0c06d860;
P_0c06d860: /* original 9010, guest PC 0x0c06d860 */
if(!s->budget--) { s->failed_pc=0x0c06d860u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d884u,2);
goto P_0c06d862;
P_0c06d862: /* original f4e6, guest PC 0x0c06d862 */
if(!s->budget--) { s->failed_pc=0x0c06d862u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c06d864;
P_0c06d864: /* original 7004, guest PC 0x0c06d864 */
if(!s->budget--) { s->failed_pc=0x0c06d864u; return 0; }
r[0]+=0x00000004u;
goto P_0c06d866;
P_0c06d866: /* original f5e6, guest PC 0x0c06d866 */
if(!s->budget--) { s->failed_pc=0x0c06d866u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c06d868;
P_0c06d868: /* original 900e, guest PC 0x0c06d868 */
if(!s->budget--) { s->failed_pc=0x0c06d868u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d888u,2);
goto P_0c06d86a;
P_0c06d86a: /* original fe47, guest PC 0x0c06d86a */
if(!s->budget--) { s->failed_pc=0x0c06d86au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06d86c;
P_0c06d86c: /* original 950d, guest PC 0x0c06d86c */
if(!s->budget--) { s->failed_pc=0x0c06d86cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d88au,2);
goto P_0c06d86e;
P_0c06d86e: /* original 940d, guest PC 0x0c06d86e */
if(!s->budget--) { s->failed_pc=0x0c06d86eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d88cu,2);
goto P_0c06d870;
P_0c06d870: /* original 35ec, guest PC 0x0c06d870 */
if(!s->budget--) { s->failed_pc=0x0c06d870u; return 0; }
r[5]+=r[14];
goto P_0c06d872;
P_0c06d872: /* original 34ec, guest PC 0x0c06d872 */
if(!s->budget--) { s->failed_pc=0x0c06d872u; return 0; }
r[4]+=r[14];
goto P_0c06d874;
P_0c06d874: /* original a01c, guest PC 0x0c06d874 */
if(!s->budget--) { s->failed_pc=0x0c06d874u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06d8b0;
P_0c06d876: /* original 6ef6, guest PC 0x0c06d876 */
if(!s->budget--) { s->failed_pc=0x0c06d876u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06d878;
P_0c06d878: /* original 000b, guest PC 0x0c06d878 */
if(!s->budget--) { s->failed_pc=0x0c06d878u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06d87a: /* original 6ef6, guest PC 0x0c06d87a */
if(!s->budget--) { s->failed_pc=0x0c06d87au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06d87cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d87cu; return 0; } return 1;
P_0c06d8b0: /* original d142, guest PC 0x0c06d8b0 */
if(!s->budget--) { s->failed_pc=0x0c06d8b0u; return 0; }
r[1]=read(ram,0x0c06d9bcu,4);
goto P_0c06d8b2;
P_0c06d8b2: /* original c741, guest PC 0x0c06d8b2 */
if(!s->budget--) { s->failed_pc=0x0c06d8b2u; return 0; }
r[0]=code_base|0x0006d9b8u;
goto P_0c06d8b4;
P_0c06d8b4: /* original fb08, guest PC 0x0c06d8b4 */
if(!s->budget--) { s->failed_pc=0x0c06d8b4u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c06d8b6;
P_0c06d8b6: /* original e010, guest PC 0x0c06d8b6 */
if(!s->budget--) { s->failed_pc=0x0c06d8b6u; return 0; }
r[0]=0x00000010u;
goto P_0c06d8b8;
P_0c06d8b8: /* original 5718, guest PC 0x0c06d8b8 */
if(!s->budget--) { s->failed_pc=0x0c06d8b8u; return 0; }
r[7]=read(ram,r[1]+32,4);
goto P_0c06d8ba;
P_0c06d8ba: /* original 7ffc, guest PC 0x0c06d8ba */
if(!s->budget--) { s->failed_pc=0x0c06d8bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06d8bc;
P_0c06d8bc: /* original f65c, guest PC 0x0c06d8bc */
if(!s->budget--) { s->failed_pc=0x0c06d8bcu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c06d8be;
P_0c06d8be: /* original f576, guest PC 0x0c06d8be */
if(!s->budget--) { s->failed_pc=0x0c06d8beu; return 0; }
vf3_matrix_load(s,ram,5,r[7]+r[0]);
goto P_0c06d8c0;
P_0c06d8c0: /* original e014, guest PC 0x0c06d8c0 */
if(!s->budget--) { s->failed_pc=0x0c06d8c0u; return 0; }
r[0]=0x00000014u;
goto P_0c06d8c2;
P_0c06d8c2: /* original f176, guest PC 0x0c06d8c2 */
if(!s->budget--) { s->failed_pc=0x0c06d8c2u; return 0; }
vf3_matrix_load(s,ram,1,r[7]+r[0]);
goto P_0c06d8c4;
P_0c06d8c4: /* original e018, guest PC 0x0c06d8c4 */
if(!s->budget--) { s->failed_pc=0x0c06d8c4u; return 0; }
r[0]=0x00000018u;
goto P_0c06d8c6;
P_0c06d8c6: /* original fa76, guest PC 0x0c06d8c6 */
if(!s->budget--) { s->failed_pc=0x0c06d8c6u; return 0; }
vf3_matrix_load(s,ram,10,r[7]+r[0]);
goto P_0c06d8c8;
P_0c06d8c8: /* original 9075, guest PC 0x0c06d8c8 */
if(!s->budget--) { s->failed_pc=0x0c06d8c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d9b6u,2);
goto P_0c06d8ca;
P_0c06d8ca: /* original 5614, guest PC 0x0c06d8ca */
if(!s->budget--) { s->failed_pc=0x0c06d8cau; return 0; }
r[6]=read(ram,r[1]+16,4);
goto P_0c06d8cc;
P_0c06d8cc: /* original f84c, guest PC 0x0c06d8cc */
if(!s->budget--) { s->failed_pc=0x0c06d8ccu; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c06d8ce;
P_0c06d8ce: /* original f466, guest PC 0x0c06d8ce */
if(!s->budget--) { s->failed_pc=0x0c06d8ceu; return 0; }
vf3_matrix_load(s,ram,4,r[6]+r[0]);
goto P_0c06d8d0;
P_0c06d8d0: /* original 7004, guest PC 0x0c06d8d0 */
if(!s->budget--) { s->failed_pc=0x0c06d8d0u; return 0; }
r[0]+=0x00000004u;
goto P_0c06d8d2;
P_0c06d8d2: /* original f966, guest PC 0x0c06d8d2 */
if(!s->budget--) { s->failed_pc=0x0c06d8d2u; return 0; }
vf3_matrix_load(s,ram,9,r[6]+r[0]);
goto P_0c06d8d4;
P_0c06d8d4: /* original 7004, guest PC 0x0c06d8d4 */
if(!s->budget--) { s->failed_pc=0x0c06d8d4u; return 0; }
r[0]+=0x00000004u;
goto P_0c06d8d6;
P_0c06d8d6: /* original f451, guest PC 0x0c06d8d6 */
if(!s->budget--) { s->failed_pc=0x0c06d8d6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06d8d8;
P_0c06d8d8: /* original f766, guest PC 0x0c06d8d8 */
if(!s->budget--) { s->failed_pc=0x0c06d8d8u; return 0; }
vf3_matrix_load(s,ram,7,r[6]+r[0]);
goto P_0c06d8da;
P_0c06d8da: /* original f911, guest PC 0x0c06d8da */
if(!s->budget--) { s->failed_pc=0x0c06d8dau; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[1],r[18],'-');
goto P_0c06d8dc;
P_0c06d8dc: /* original 5115, guest PC 0x0c06d8dc */
if(!s->budget--) { s->failed_pc=0x0c06d8dcu; return 0; }
r[1]=read(ram,r[1]+20,4);
goto P_0c06d8de;
P_0c06d8de: /* original f7a1, guest PC 0x0c06d8de */
if(!s->budget--) { s->failed_pc=0x0c06d8deu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[10],r[18],'-');
goto P_0c06d8e0;
P_0c06d8e0: /* original f34c, guest PC 0x0c06d8e0 */
if(!s->budget--) { s->failed_pc=0x0c06d8e0u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d8e2;
P_0c06d8e2: /* original f432, guest PC 0x0c06d8e2 */
if(!s->budget--) { s->failed_pc=0x0c06d8e2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06d8e4;
P_0c06d8e4: /* original f09c, guest PC 0x0c06d8e4 */
if(!s->budget--) { s->failed_pc=0x0c06d8e4u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06d8e6;
P_0c06d8e6: /* original f24c, guest PC 0x0c06d8e6 */
if(!s->budget--) { s->failed_pc=0x0c06d8e6u; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c06d8e8;
P_0c06d8e8: /* original f29e, guest PC 0x0c06d8e8 */
if(!s->budget--) { s->failed_pc=0x0c06d8e8u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[9],fr[2],r[18]);
goto P_0c06d8ea;
P_0c06d8ea: /* original f07c, guest PC 0x0c06d8ea */
if(!s->budget--) { s->failed_pc=0x0c06d8eau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c06d8ec;
P_0c06d8ec: /* original f32c, guest PC 0x0c06d8ec */
if(!s->budget--) { s->failed_pc=0x0c06d8ecu; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c06d8ee;
P_0c06d8ee: /* original f37e, guest PC 0x0c06d8ee */
if(!s->budget--) { s->failed_pc=0x0c06d8eeu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c06d8f0;
P_0c06d8f0: /* original c733, guest PC 0x0c06d8f0 */
if(!s->budget--) { s->failed_pc=0x0c06d8f0u; return 0; }
r[0]=code_base|0x0006d9c0u;
goto P_0c06d8f2;
P_0c06d8f2: /* original f43c, guest PC 0x0c06d8f2 */
if(!s->budget--) { s->failed_pc=0x0c06d8f2u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06d8f4;
P_0c06d8f4: /* original f208, guest PC 0x0c06d8f4 */
if(!s->budget--) { s->failed_pc=0x0c06d8f4u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c06d8f6;
P_0c06d8f6: /* original f245, guest PC 0x0c06d8f6 */
if(!s->budget--) { s->failed_pc=0x0c06d8f6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c06d8f8;
P_0c06d8f8: /* original 8f02, guest PC 0x0c06d8f8 */
if(!s->budget--) { s->failed_pc=0x0c06d8f8u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,7,3);
if(!cond) { goto P_0c06d900; }
goto P_0c06d8fc;
P_0c06d8fa: /* original f73c, guest PC 0x0c06d8fa */
if(!s->budget--) { s->failed_pc=0x0c06d8fau; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c06d8fc;
P_0c06d8fc: /* original a001, guest PC 0x0c06d8fc */
if(!s->budget--) { s->failed_pc=0x0c06d8fcu; return 0; }
fr[4]=0;
goto P_0c06d902;
P_0c06d8fe: /* original f48d, guest PC 0x0c06d8fe */
if(!s->budget--) { s->failed_pc=0x0c06d8feu; return 0; }
fr[4]=0;
goto P_0c06d900;
P_0c06d900: /* original f47d, guest PC 0x0c06d900 */
if(!s->budget--) { s->failed_pc=0x0c06d900u; return 0; }
if(!vf3_fpu_fsrra(fr[4],r[18],&fr[4])) goto unsupported;
goto P_0c06d902;
P_0c06d902: /* original 9058, guest PC 0x0c06d902 */
if(!s->budget--) { s->failed_pc=0x0c06d902u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06d9b6u,2);
goto P_0c06d904;
P_0c06d904: /* original f37c, guest PC 0x0c06d904 */
if(!s->budget--) { s->failed_pc=0x0c06d904u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c06d906;
P_0c06d906: /* original f74c, guest PC 0x0c06d906 */
if(!s->budget--) { s->failed_pc=0x0c06d906u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06d908;
P_0c06d908: /* original f732, guest PC 0x0c06d908 */
if(!s->budget--) { s->failed_pc=0x0c06d908u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c06d90a;
P_0c06d90a: /* original f416, guest PC 0x0c06d90a */
if(!s->budget--) { s->failed_pc=0x0c06d90au; return 0; }
vf3_matrix_load(s,ram,4,r[1]+r[0]);
goto P_0c06d90c;
P_0c06d90c: /* original 7004, guest PC 0x0c06d90c */
if(!s->budget--) { s->failed_pc=0x0c06d90cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06d90e;
P_0c06d90e: /* original f916, guest PC 0x0c06d90e */
if(!s->budget--) { s->failed_pc=0x0c06d90eu; return 0; }
vf3_matrix_load(s,ram,9,r[1]+r[0]);
goto P_0c06d910;
P_0c06d910: /* original 7004, guest PC 0x0c06d910 */
if(!s->budget--) { s->failed_pc=0x0c06d910u; return 0; }
r[0]+=0x00000004u;
goto P_0c06d912;
P_0c06d912: /* original f316, guest PC 0x0c06d912 */
if(!s->budget--) { s->failed_pc=0x0c06d912u; return 0; }
vf3_matrix_load(s,ram,3,r[1]+r[0]);
goto P_0c06d914;
P_0c06d914: /* original c72a, guest PC 0x0c06d914 */
if(!s->budget--) { s->failed_pc=0x0c06d914u; return 0; }
r[0]=code_base|0x0006d9c0u;
goto P_0c06d916;
P_0c06d916: /* original ff3a, guest PC 0x0c06d916 */
if(!s->budget--) { s->failed_pc=0x0c06d916u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c06d918;
P_0c06d918: /* original f35c, guest PC 0x0c06d918 */
if(!s->budget--) { s->failed_pc=0x0c06d918u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06d91a;
P_0c06d91a: /* original f54c, guest PC 0x0c06d91a */
if(!s->budget--) { s->failed_pc=0x0c06d91au; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c06d91c;
P_0c06d91c: /* original f531, guest PC 0x0c06d91c */
if(!s->budget--) { s->failed_pc=0x0c06d91cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06d91e;
P_0c06d91e: /* original f49c, guest PC 0x0c06d91e */
if(!s->budget--) { s->failed_pc=0x0c06d91eu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c06d920;
P_0c06d920: /* original f411, guest PC 0x0c06d920 */
if(!s->budget--) { s->failed_pc=0x0c06d920u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'-');
goto P_0c06d922;
P_0c06d922: /* original f9f8, guest PC 0x0c06d922 */
if(!s->budget--) { s->failed_pc=0x0c06d922u; return 0; }
vf3_matrix_load(s,ram,9,r[15]);
goto P_0c06d924;
P_0c06d924: /* original f35c, guest PC 0x0c06d924 */
if(!s->budget--) { s->failed_pc=0x0c06d924u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06d926;
P_0c06d926: /* original f532, guest PC 0x0c06d926 */
if(!s->budget--) { s->failed_pc=0x0c06d926u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c06d928;
P_0c06d928: /* original f04c, guest PC 0x0c06d928 */
if(!s->budget--) { s->failed_pc=0x0c06d928u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c06d92a;
P_0c06d92a: /* original f9a1, guest PC 0x0c06d92a */
if(!s->budget--) { s->failed_pc=0x0c06d92au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[10],r[18],'-');
goto P_0c06d92c;
P_0c06d92c: /* original f25c, guest PC 0x0c06d92c */
if(!s->budget--) { s->failed_pc=0x0c06d92cu; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c06d92e;
P_0c06d92e: /* original f24e, guest PC 0x0c06d92e */
if(!s->budget--) { s->failed_pc=0x0c06d92eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[4],fr[2],r[18]);
goto P_0c06d930;
P_0c06d930: /* original f09c, guest PC 0x0c06d930 */
if(!s->budget--) { s->failed_pc=0x0c06d930u; return 0; }
vf3_matrix_move(s,0,9);
goto P_0c06d932;
P_0c06d932: /* original f32c, guest PC 0x0c06d932 */
if(!s->budget--) { s->failed_pc=0x0c06d932u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c06d934;
P_0c06d934: /* original f39e, guest PC 0x0c06d934 */
if(!s->budget--) { s->failed_pc=0x0c06d934u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c06d936;
P_0c06d936: /* original f208, guest PC 0x0c06d936 */
if(!s->budget--) { s->failed_pc=0x0c06d936u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c06d938;
P_0c06d938: /* original f53c, guest PC 0x0c06d938 */
if(!s->budget--) { s->failed_pc=0x0c06d938u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c06d93a;
P_0c06d93a: /* original f255, guest PC 0x0c06d93a */
if(!s->budget--) { s->failed_pc=0x0c06d93au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[5]))!=0);
goto P_0c06d93c;
P_0c06d93c: /* original 8f02, guest PC 0x0c06d93c */
if(!s->budget--) { s->failed_pc=0x0c06d93cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c06d944; }
goto P_0c06d940;
P_0c06d93e: /* original f43c, guest PC 0x0c06d93e */
if(!s->budget--) { s->failed_pc=0x0c06d93eu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06d940;
P_0c06d940: /* original a001, guest PC 0x0c06d940 */
if(!s->budget--) { s->failed_pc=0x0c06d940u; return 0; }
fr[5]=0;
goto P_0c06d946;
P_0c06d942: /* original f58d, guest PC 0x0c06d942 */
if(!s->budget--) { s->failed_pc=0x0c06d942u; return 0; }
fr[5]=0;
goto P_0c06d944;
P_0c06d944: /* original f57d, guest PC 0x0c06d944 */
if(!s->budget--) { s->failed_pc=0x0c06d944u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c06d946;
P_0c06d946: /* original f34c, guest PC 0x0c06d946 */
if(!s->budget--) { s->failed_pc=0x0c06d946u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d948;
P_0c06d948: /* original f45c, guest PC 0x0c06d948 */
if(!s->budget--) { s->failed_pc=0x0c06d948u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06d94a;
P_0c06d94a: /* original f432, guest PC 0x0c06d94a */
if(!s->budget--) { s->failed_pc=0x0c06d94au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06d94c;
P_0c06d94c: /* original f475, guest PC 0x0c06d94c */
if(!s->budget--) { s->failed_pc=0x0c06d94cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c06d94e;
P_0c06d94e: /* original 8b00, guest PC 0x0c06d94e */
if(!s->budget--) { s->failed_pc=0x0c06d94eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d952; }
goto P_0c06d950;
P_0c06d950: /* original f47c, guest PC 0x0c06d950 */
if(!s->budget--) { s->failed_pc=0x0c06d950u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c06d952;
P_0c06d952: /* original f34c, guest PC 0x0c06d952 */
if(!s->budget--) { s->failed_pc=0x0c06d952u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d954;
P_0c06d954: /* original c71b, guest PC 0x0c06d954 */
if(!s->budget--) { s->failed_pc=0x0c06d954u; return 0; }
r[0]=code_base|0x0006d9c4u;
goto P_0c06d956;
P_0c06d956: /* original f4bc, guest PC 0x0c06d956 */
if(!s->budget--) { s->failed_pc=0x0c06d956u; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c06d958;
P_0c06d958: /* original f432, guest PC 0x0c06d958 */
if(!s->budget--) { s->failed_pc=0x0c06d958u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c06d95a;
P_0c06d95a: /* original f36c, guest PC 0x0c06d95a */
if(!s->budget--) { s->failed_pc=0x0c06d95au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c06d95c;
P_0c06d95c: /* original f6bc, guest PC 0x0c06d95c */
if(!s->budget--) { s->failed_pc=0x0c06d95cu; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c06d95e;
P_0c06d95e: /* original f632, guest PC 0x0c06d95e */
if(!s->budget--) { s->failed_pc=0x0c06d95eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c06d960;
P_0c06d960: /* original f508, guest PC 0x0c06d960 */
if(!s->budget--) { s->failed_pc=0x0c06d960u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06d962;
P_0c06d962: /* original c715, guest PC 0x0c06d962 */
if(!s->budget--) { s->failed_pc=0x0c06d962u; return 0; }
r[0]=code_base|0x0006d9b8u;
goto P_0c06d964;
P_0c06d964: /* original f34c, guest PC 0x0c06d964 */
if(!s->budget--) { s->failed_pc=0x0c06d964u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c06d966;
P_0c06d966: /* original f45c, guest PC 0x0c06d966 */
if(!s->budget--) { s->failed_pc=0x0c06d966u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06d968;
P_0c06d968: /* original f430, guest PC 0x0c06d968 */
if(!s->budget--) { s->failed_pc=0x0c06d968u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c06d96a;
P_0c06d96a: /* original f908, guest PC 0x0c06d96a */
if(!s->budget--) { s->failed_pc=0x0c06d96au; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c06d96c;
P_0c06d96c: /* original c716, guest PC 0x0c06d96c */
if(!s->budget--) { s->failed_pc=0x0c06d96cu; return 0; }
r[0]=code_base|0x0006d9c8u;
goto P_0c06d96e;
P_0c06d96e: /* original f708, guest PC 0x0c06d96e */
if(!s->budget--) { s->failed_pc=0x0c06d96eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c06d970;
P_0c06d970: /* original f945, guest PC 0x0c06d970 */
if(!s->budget--) { s->failed_pc=0x0c06d970u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[4]))!=0);
goto P_0c06d972;
P_0c06d972: /* original 8d11, guest PC 0x0c06d972 */
if(!s->budget--) { s->failed_pc=0x0c06d972u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,7);
if(cond) { goto P_0c06d998; }
goto P_0c06d976;
P_0c06d974: /* original f57c, guest PC 0x0c06d974 */
if(!s->budget--) { s->failed_pc=0x0c06d974u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c06d976;
P_0c06d976: /* original c715, guest PC 0x0c06d976 */
if(!s->budget--) { s->failed_pc=0x0c06d976u; return 0; }
r[0]=code_base|0x0006d9ccu;
goto P_0c06d978;
P_0c06d978: /* original f508, guest PC 0x0c06d978 */
if(!s->budget--) { s->failed_pc=0x0c06d978u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06d97a;
P_0c06d97a: /* original f35c, guest PC 0x0c06d97a */
if(!s->budget--) { s->failed_pc=0x0c06d97au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06d97c;
P_0c06d97c: /* original f56c, guest PC 0x0c06d97c */
if(!s->budget--) { s->failed_pc=0x0c06d97cu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c06d97e;
P_0c06d97e: /* original f531, guest PC 0x0c06d97e */
if(!s->budget--) { s->failed_pc=0x0c06d97eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c06d980;
P_0c06d980: /* original f455, guest PC 0x0c06d980 */
if(!s->budget--) { s->failed_pc=0x0c06d980u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c06d982;
P_0c06d982: /* original 8b00, guest PC 0x0c06d982 */
if(!s->budget--) { s->failed_pc=0x0c06d982u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d986; }
goto P_0c06d984;
P_0c06d984: /* original f45c, guest PC 0x0c06d984 */
if(!s->budget--) { s->failed_pc=0x0c06d984u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06d986;
P_0c06d986: /* original c712, guest PC 0x0c06d986 */
if(!s->budget--) { s->failed_pc=0x0c06d986u; return 0; }
r[0]=code_base|0x0006d9d0u;
goto P_0c06d988;
P_0c06d988: /* original f508, guest PC 0x0c06d988 */
if(!s->budget--) { s->failed_pc=0x0c06d988u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06d98a;
P_0c06d98a: /* original f543, guest PC 0x0c06d98a */
if(!s->budget--) { s->failed_pc=0x0c06d98au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c06d98c;
P_0c06d98c: /* original f35c, guest PC 0x0c06d98c */
if(!s->budget--) { s->failed_pc=0x0c06d98cu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c06d98e;
P_0c06d98e: /* original f58c, guest PC 0x0c06d98e */
if(!s->budget--) { s->failed_pc=0x0c06d98eu; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c06d990;
P_0c06d990: /* original f530, guest PC 0x0c06d990 */
if(!s->budget--) { s->failed_pc=0x0c06d990u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c06d992;
P_0c06d992: /* original f755, guest PC 0x0c06d992 */
if(!s->budget--) { s->failed_pc=0x0c06d992u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c06d994;
P_0c06d994: /* original 8b00, guest PC 0x0c06d994 */
if(!s->budget--) { s->failed_pc=0x0c06d994u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06d998; }
goto P_0c06d996;
P_0c06d996: /* original f57c, guest PC 0x0c06d996 */
if(!s->budget--) { s->failed_pc=0x0c06d996u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c06d998;
P_0c06d998: /* original f76c, guest PC 0x0c06d998 */
if(!s->budget--) { s->failed_pc=0x0c06d998u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c06d99a;
P_0c06d99a: /* original f741, guest PC 0x0c06d99a */
if(!s->budget--) { s->failed_pc=0x0c06d99au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c06d99c;
P_0c06d99c: /* original f48c, guest PC 0x0c06d99c */
if(!s->budget--) { s->failed_pc=0x0c06d99cu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c06d99e;
P_0c06d99e: /* original f451, guest PC 0x0c06d99e */
if(!s->budget--) { s->failed_pc=0x0c06d99eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06d9a0;
P_0c06d9a0: /* original f473, guest PC 0x0c06d9a0 */
if(!s->budget--) { s->failed_pc=0x0c06d9a0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'/');
goto P_0c06d9a2;
P_0c06d9a2: /* original f642, guest PC 0x0c06d9a2 */
if(!s->budget--) { s->failed_pc=0x0c06d9a2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c06d9a4;
P_0c06d9a4: /* original f861, guest PC 0x0c06d9a4 */
if(!s->budget--) { s->failed_pc=0x0c06d9a4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c06d9a6;
P_0c06d9a6: /* original f83d, guest PC 0x0c06d9a6 */
if(!s->budget--) { s->failed_pc=0x0c06d9a6u; return 0; }
r[53]=truncate_float(fr[8]);
goto P_0c06d9a8;
P_0c06d9a8: /* original 065a, guest PC 0x0c06d9a8 */
if(!s->budget--) { s->failed_pc=0x0c06d9a8u; return 0; }
r[6]=r[53];
goto P_0c06d9aa;
P_0c06d9aa: /* original f44a, guest PC 0x0c06d9aa */
if(!s->budget--) { s->failed_pc=0x0c06d9aau; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c06d9ac;
P_0c06d9ac: /* original 465a, guest PC 0x0c06d9ac */
if(!s->budget--) { s->failed_pc=0x0c06d9acu; return 0; }
r[53]=r[6];
goto P_0c06d9ae;
P_0c06d9ae: /* original f32d, guest PC 0x0c06d9ae */
if(!s->budget--) { s->failed_pc=0x0c06d9aeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06d9b0;
P_0c06d9b0: /* original f53a, guest PC 0x0c06d9b0 */
if(!s->budget--) { s->failed_pc=0x0c06d9b0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c06d9b2;
P_0c06d9b2: /* original 000b, guest PC 0x0c06d9b2 */
if(!s->budget--) { s->failed_pc=0x0c06d9b2u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c06d9b4: /* original 7f04, guest PC 0x0c06d9b4 */
if(!s->budget--) { s->failed_pc=0x0c06d9b4u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c06d9b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06d9b6u; return 0; } return 1;
P_0c06d9d4: /* original 2fe6, guest PC 0x0c06d9d4 */
if(!s->budget--) { s->failed_pc=0x0c06d9d4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d9d6;
P_0c06d9d6: /* original 6e43, guest PC 0x0c06d9d6 */
if(!s->budget--) { s->failed_pc=0x0c06d9d6u; return 0; }
r[14]=r[4];
goto P_0c06d9d8;
P_0c06d9d8: /* original 2fd6, guest PC 0x0c06d9d8 */
if(!s->budget--) { s->failed_pc=0x0c06d9d8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d9da;
P_0c06d9da: /* original ed00, guest PC 0x0c06d9da */
if(!s->budget--) { s->failed_pc=0x0c06d9dau; return 0; }
r[13]=0x00000000u;
goto P_0c06d9dc;
P_0c06d9dc: /* original 2fc6, guest PC 0x0c06d9dc */
if(!s->budget--) { s->failed_pc=0x0c06d9dcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06d9de;
P_0c06d9de: /* original 6cd3, guest PC 0x0c06d9de */
if(!s->budget--) { s->failed_pc=0x0c06d9deu; return 0; }
r[12]=r[13];
goto P_0c06d9e0;
P_0c06d9e0: /* original 4f22, guest PC 0x0c06d9e0 */
if(!s->budget--) { s->failed_pc=0x0c06d9e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06d9e2;
P_0c06d9e2: /* original d42b, guest PC 0x0c06d9e2 */
if(!s->budget--) { s->failed_pc=0x0c06d9e2u; return 0; }
r[4]=read(ram,0x0c06da90u,4);
goto P_0c06d9e4;
P_0c06d9e4: /* original 67d3, guest PC 0x0c06d9e4 */
if(!s->budget--) { s->failed_pc=0x0c06d9e4u; return 0; }
r[7]=r[13];
goto P_0c06d9e6;
P_0c06d9e6: /* original d32b, guest PC 0x0c06d9e6 */
if(!s->budget--) { s->failed_pc=0x0c06d9e6u; return 0; }
r[3]=read(ram,0x0c06da94u,4);
goto P_0c06d9e8;
P_0c06d9e8: /* original 66d3, guest PC 0x0c06d9e8 */
if(!s->budget--) { s->failed_pc=0x0c06d9e8u; return 0; }
r[6]=r[13];
goto P_0c06d9ea;
P_0c06d9ea: /* original 430b, guest PC 0x0c06d9ea */
if(!s->budget--) { s->failed_pc=0x0c06d9eau; return 0; }
target=r[3];
r[16]=code_base|0x0c06d9eeu;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d9eeu) { target=s->pc; goto dispatch; }
goto P_0c06d9ee;
P_0c06d9ec: /* original 65d3, guest PC 0x0c06d9ec */
if(!s->budget--) { s->failed_pc=0x0c06d9ecu; return 0; }
r[5]=r[13];
goto P_0c06d9ee;
P_0c06d9ee: /* original d42a, guest PC 0x0c06d9ee */
if(!s->budget--) { s->failed_pc=0x0c06d9eeu; return 0; }
r[4]=read(ram,0x0c06da98u,4);
goto P_0c06d9f0;
P_0c06d9f0: /* original 67c3, guest PC 0x0c06d9f0 */
if(!s->budget--) { s->failed_pc=0x0c06d9f0u; return 0; }
r[7]=r[12];
goto P_0c06d9f2;
P_0c06d9f2: /* original d228, guest PC 0x0c06d9f2 */
if(!s->budget--) { s->failed_pc=0x0c06d9f2u; return 0; }
r[2]=read(ram,0x0c06da94u,4);
goto P_0c06d9f4;
P_0c06d9f4: /* original 66c3, guest PC 0x0c06d9f4 */
if(!s->budget--) { s->failed_pc=0x0c06d9f4u; return 0; }
r[6]=r[12];
goto P_0c06d9f6;
P_0c06d9f6: /* original 420b, guest PC 0x0c06d9f6 */
if(!s->budget--) { s->failed_pc=0x0c06d9f6u; return 0; }
target=r[2];
r[16]=code_base|0x0c06d9fau;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06d9fau) { target=s->pc; goto dispatch; }
goto P_0c06d9fa;
P_0c06d9f8: /* original 65c3, guest PC 0x0c06d9f8 */
if(!s->budget--) { s->failed_pc=0x0c06d9f8u; return 0; }
r[5]=r[12];
goto P_0c06d9fa;
P_0c06d9fa: /* original 9045, guest PC 0x0c06d9fa */
if(!s->budget--) { s->failed_pc=0x0c06d9fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06da88u,2);
goto P_0c06d9fc;
P_0c06d9fc: /* original f59d, guest PC 0x0c06d9fc */
if(!s->budget--) { s->failed_pc=0x0c06d9fcu; return 0; }
fr[5]=0x3f800000u;
goto P_0c06d9fe;
P_0c06d9fe: /* original f45c, guest PC 0x0c06d9fe */
if(!s->budget--) { s->failed_pc=0x0c06d9feu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c06da00;
P_0c06da00: /* original fe47, guest PC 0x0c06da00 */
if(!s->budget--) { s->failed_pc=0x0c06da00u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da02;
P_0c06da02: /* original 9042, guest PC 0x0c06da02 */
if(!s->budget--) { s->failed_pc=0x0c06da02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06da8au,2);
goto P_0c06da04;
P_0c06da04: /* original fe47, guest PC 0x0c06da04 */
if(!s->budget--) { s->failed_pc=0x0c06da04u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da06;
P_0c06da06: /* original 9041, guest PC 0x0c06da06 */
if(!s->budget--) { s->failed_pc=0x0c06da06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06da8cu,2);
goto P_0c06da08;
P_0c06da08: /* original fe47, guest PC 0x0c06da08 */
if(!s->budget--) { s->failed_pc=0x0c06da08u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da0a;
P_0c06da0a: /* original 7028, guest PC 0x0c06da0a */
if(!s->budget--) { s->failed_pc=0x0c06da0au; return 0; }
r[0]+=0x00000028u;
goto P_0c06da0c;
P_0c06da0c: /* original fe47, guest PC 0x0c06da0c */
if(!s->budget--) { s->failed_pc=0x0c06da0cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c06da0e;
P_0c06da0e: /* original 70dc, guest PC 0x0c06da0e */
if(!s->budget--) { s->failed_pc=0x0c06da0eu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c06da10;
P_0c06da10: /* original f48d, guest PC 0x0c06da10 */
if(!s->budget--) { s->failed_pc=0x0c06da10u; return 0; }
fr[4]=0;
goto P_0c06da12;
P_0c06da12: /* original f64c, guest PC 0x0c06da12 */
if(!s->budget--) { s->failed_pc=0x0c06da12u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c06da14;
P_0c06da14: /* original f74c, guest PC 0x0c06da14 */
if(!s->budget--) { s->failed_pc=0x0c06da14u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c06da16;
P_0c06da16: /* original fe67, guest PC 0x0c06da16 */
if(!s->budget--) { s->failed_pc=0x0c06da16u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da18;
P_0c06da18: /* original 7004, guest PC 0x0c06da18 */
if(!s->budget--) { s->failed_pc=0x0c06da18u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da1a;
P_0c06da1a: /* original fe67, guest PC 0x0c06da1a */
if(!s->budget--) { s->failed_pc=0x0c06da1au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da1c;
P_0c06da1c: /* original 7024, guest PC 0x0c06da1c */
if(!s->budget--) { s->failed_pc=0x0c06da1cu; return 0; }
r[0]+=0x00000024u;
goto P_0c06da1e;
P_0c06da1e: /* original fe67, guest PC 0x0c06da1e */
if(!s->budget--) { s->failed_pc=0x0c06da1eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da20;
P_0c06da20: /* original 7004, guest PC 0x0c06da20 */
if(!s->budget--) { s->failed_pc=0x0c06da20u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da22;
P_0c06da22: /* original fe67, guest PC 0x0c06da22 */
if(!s->budget--) { s->failed_pc=0x0c06da22u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da24;
P_0c06da24: /* original 70dc, guest PC 0x0c06da24 */
if(!s->budget--) { s->failed_pc=0x0c06da24u; return 0; }
r[0]+=0xffffffdcu;
goto P_0c06da26;
P_0c06da26: /* original 0ec4, guest PC 0x0c06da26 */
if(!s->budget--) { s->failed_pc=0x0c06da26u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da28;
P_0c06da28: /* original 7001, guest PC 0x0c06da28 */
if(!s->budget--) { s->failed_pc=0x0c06da28u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da2a;
P_0c06da2a: /* original 0ec4, guest PC 0x0c06da2a */
if(!s->budget--) { s->failed_pc=0x0c06da2au; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da2c;
P_0c06da2c: /* original 7001, guest PC 0x0c06da2c */
if(!s->budget--) { s->failed_pc=0x0c06da2cu; return 0; }
r[0]+=0x00000001u;
goto P_0c06da2e;
P_0c06da2e: /* original 0ec4, guest PC 0x0c06da2e */
if(!s->budget--) { s->failed_pc=0x0c06da2eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da30;
P_0c06da30: /* original 7026, guest PC 0x0c06da30 */
if(!s->budget--) { s->failed_pc=0x0c06da30u; return 0; }
r[0]+=0x00000026u;
goto P_0c06da32;
P_0c06da32: /* original 0ec4, guest PC 0x0c06da32 */
if(!s->budget--) { s->failed_pc=0x0c06da32u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da34;
P_0c06da34: /* original 7001, guest PC 0x0c06da34 */
if(!s->budget--) { s->failed_pc=0x0c06da34u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da36;
P_0c06da36: /* original 0ec4, guest PC 0x0c06da36 */
if(!s->budget--) { s->failed_pc=0x0c06da36u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da38;
P_0c06da38: /* original 7001, guest PC 0x0c06da38 */
if(!s->budget--) { s->failed_pc=0x0c06da38u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da3a;
P_0c06da3a: /* original 0ec4, guest PC 0x0c06da3a */
if(!s->budget--) { s->failed_pc=0x0c06da3au; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da3c;
P_0c06da3c: /* original 70da, guest PC 0x0c06da3c */
if(!s->budget--) { s->failed_pc=0x0c06da3cu; return 0; }
r[0]+=0xffffffdau;
goto P_0c06da3e;
P_0c06da3e: /* original 0ec4, guest PC 0x0c06da3e */
if(!s->budget--) { s->failed_pc=0x0c06da3eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da40;
P_0c06da40: /* original 7001, guest PC 0x0c06da40 */
if(!s->budget--) { s->failed_pc=0x0c06da40u; return 0; }
r[0]+=0x00000001u;
goto P_0c06da42;
P_0c06da42: /* original e401, guest PC 0x0c06da42 */
if(!s->budget--) { s->failed_pc=0x0c06da42u; return 0; }
r[4]=0x00000001u;
goto P_0c06da44;
P_0c06da44: /* original 0e44, guest PC 0x0c06da44 */
if(!s->budget--) { s->failed_pc=0x0c06da44u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da46;
P_0c06da46: /* original 0e44, guest PC 0x0c06da46 */
if(!s->budget--) { s->failed_pc=0x0c06da46u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da48;
P_0c06da48: /* original 7003, guest PC 0x0c06da48 */
if(!s->budget--) { s->failed_pc=0x0c06da48u; return 0; }
r[0]+=0x00000003u;
goto P_0c06da4a;
P_0c06da4a: /* original fe67, guest PC 0x0c06da4a */
if(!s->budget--) { s->failed_pc=0x0c06da4au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da4c;
P_0c06da4c: /* original 7004, guest PC 0x0c06da4c */
if(!s->budget--) { s->failed_pc=0x0c06da4cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06da4e;
P_0c06da4e: /* original fe67, guest PC 0x0c06da4e */
if(!s->budget--) { s->failed_pc=0x0c06da4eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da50;
P_0c06da50: /* original 7004, guest PC 0x0c06da50 */
if(!s->budget--) { s->failed_pc=0x0c06da50u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da52;
P_0c06da52: /* original fe67, guest PC 0x0c06da52 */
if(!s->budget--) { s->failed_pc=0x0c06da52u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da54;
P_0c06da54: /* original 7004, guest PC 0x0c06da54 */
if(!s->budget--) { s->failed_pc=0x0c06da54u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da56;
P_0c06da56: /* original fe57, guest PC 0x0c06da56 */
if(!s->budget--) { s->failed_pc=0x0c06da56u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06da58;
P_0c06da58: /* original 7018, guest PC 0x0c06da58 */
if(!s->budget--) { s->failed_pc=0x0c06da58u; return 0; }
r[0]+=0x00000018u;
goto P_0c06da5a;
P_0c06da5a: /* original 0ec4, guest PC 0x0c06da5a */
if(!s->budget--) { s->failed_pc=0x0c06da5au; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c06da5c;
P_0c06da5c: /* original 7001, guest PC 0x0c06da5c */
if(!s->budget--) { s->failed_pc=0x0c06da5cu; return 0; }
r[0]+=0x00000001u;
goto P_0c06da5e;
P_0c06da5e: /* original 0e44, guest PC 0x0c06da5e */
if(!s->budget--) { s->failed_pc=0x0c06da5eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da60;
P_0c06da60: /* original 0e44, guest PC 0x0c06da60 */
if(!s->budget--) { s->failed_pc=0x0c06da60u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06da62;
P_0c06da62: /* original 7003, guest PC 0x0c06da62 */
if(!s->budget--) { s->failed_pc=0x0c06da62u; return 0; }
r[0]+=0x00000003u;
goto P_0c06da64;
P_0c06da64: /* original 4f26, guest PC 0x0c06da64 */
if(!s->budget--) { s->failed_pc=0x0c06da64u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06da66;
P_0c06da66: /* original fe67, guest PC 0x0c06da66 */
if(!s->budget--) { s->failed_pc=0x0c06da66u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da68;
P_0c06da68: /* original 7004, guest PC 0x0c06da68 */
if(!s->budget--) { s->failed_pc=0x0c06da68u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da6a;
P_0c06da6a: /* original fe67, guest PC 0x0c06da6a */
if(!s->budget--) { s->failed_pc=0x0c06da6au; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da6c;
P_0c06da6c: /* original 7004, guest PC 0x0c06da6c */
if(!s->budget--) { s->failed_pc=0x0c06da6cu; return 0; }
r[0]+=0x00000004u;
goto P_0c06da6e;
P_0c06da6e: /* original fe67, guest PC 0x0c06da6e */
if(!s->budget--) { s->failed_pc=0x0c06da6eu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c06da70;
P_0c06da70: /* original 7004, guest PC 0x0c06da70 */
if(!s->budget--) { s->failed_pc=0x0c06da70u; return 0; }
r[0]+=0x00000004u;
goto P_0c06da72;
P_0c06da72: /* original fe57, guest PC 0x0c06da72 */
if(!s->budget--) { s->failed_pc=0x0c06da72u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c06da74;
P_0c06da74: /* original 6cf6, guest PC 0x0c06da74 */
if(!s->budget--) { s->failed_pc=0x0c06da74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06da76;
P_0c06da76: /* original 6df6, guest PC 0x0c06da76 */
if(!s->budget--) { s->failed_pc=0x0c06da76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06da78;
P_0c06da78: /* original 000b, guest PC 0x0c06da78 */
if(!s->budget--) { s->failed_pc=0x0c06da78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06da7a: /* original 6ef6, guest PC 0x0c06da7a */
if(!s->budget--) { s->failed_pc=0x0c06da7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06da7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06da7cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
