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
int vf3_away_batch118_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09d838u: goto P_0c09d838;
case 0x0c09d83au: goto P_0c09d83a;
case 0x0c09d83cu: goto P_0c09d83c;
case 0x0c09d83eu: goto P_0c09d83e;
case 0x0c09d840u: goto P_0c09d840;
case 0x0c09d842u: goto P_0c09d842;
case 0x0c09d844u: goto P_0c09d844;
case 0x0c09d846u: goto P_0c09d846;
case 0x0c09d848u: goto P_0c09d848;
case 0x0c09d84au: goto P_0c09d84a;
case 0x0c09d84cu: goto P_0c09d84c;
case 0x0c09d84eu: goto P_0c09d84e;
case 0x0c09d850u: goto P_0c09d850;
case 0x0c09d852u: goto P_0c09d852;
case 0x0c09d854u: goto P_0c09d854;
case 0x0c09d856u: goto P_0c09d856;
case 0x0c09d858u: goto P_0c09d858;
case 0x0c09d85au: goto P_0c09d85a;
case 0x0c09d85cu: goto P_0c09d85c;
case 0x0c09d85eu: goto P_0c09d85e;
case 0x0c09d860u: goto P_0c09d860;
case 0x0c09d862u: goto P_0c09d862;
case 0x0c09d864u: goto P_0c09d864;
case 0x0c09d866u: goto P_0c09d866;
case 0x0c09d868u: goto P_0c09d868;
case 0x0c09d86au: goto P_0c09d86a;
case 0x0c09d86cu: goto P_0c09d86c;
case 0x0c09d86eu: goto P_0c09d86e;
case 0x0c09d870u: goto P_0c09d870;
case 0x0c09d872u: goto P_0c09d872;
case 0x0c09d874u: goto P_0c09d874;
case 0x0c09d876u: goto P_0c09d876;
case 0x0c09d878u: goto P_0c09d878;
case 0x0c09d87au: goto P_0c09d87a;
case 0x0c09d87cu: goto P_0c09d87c;
case 0x0c09d87eu: goto P_0c09d87e;
case 0x0c09d880u: goto P_0c09d880;
case 0x0c09d882u: goto P_0c09d882;
case 0x0c09d884u: goto P_0c09d884;
case 0x0c09d886u: goto P_0c09d886;
case 0x0c09d888u: goto P_0c09d888;
case 0x0c09d88au: goto P_0c09d88a;
case 0x0c09d88cu: goto P_0c09d88c;
case 0x0c09d88eu: goto P_0c09d88e;
case 0x0c09d890u: goto P_0c09d890;
case 0x0c09d892u: goto P_0c09d892;
case 0x0c09d894u: goto P_0c09d894;
case 0x0c09d896u: goto P_0c09d896;
case 0x0c09d898u: goto P_0c09d898;
case 0x0c09d89au: goto P_0c09d89a;
case 0x0c09d89cu: goto P_0c09d89c;
case 0x0c09d89eu: goto P_0c09d89e;
case 0x0c09d8a0u: goto P_0c09d8a0;
case 0x0c09d8a2u: goto P_0c09d8a2;
case 0x0c09d8a4u: goto P_0c09d8a4;
case 0x0c09d8a6u: goto P_0c09d8a6;
case 0x0c09d8a8u: goto P_0c09d8a8;
case 0x0c09d8aau: goto P_0c09d8aa;
case 0x0c09d8acu: goto P_0c09d8ac;
case 0x0c09d8aeu: goto P_0c09d8ae;
case 0x0c09d8b0u: goto P_0c09d8b0;
case 0x0c09d8b2u: goto P_0c09d8b2;
case 0x0c09d8b4u: goto P_0c09d8b4;
case 0x0c09d8b6u: goto P_0c09d8b6;
case 0x0c09d8b8u: goto P_0c09d8b8;
case 0x0c09d8bau: goto P_0c09d8ba;
case 0x0c09d8bcu: goto P_0c09d8bc;
case 0x0c09d8beu: goto P_0c09d8be;
case 0x0c09d8c0u: goto P_0c09d8c0;
case 0x0c09d8c2u: goto P_0c09d8c2;
case 0x0c09d8c4u: goto P_0c09d8c4;
case 0x0c09d8c6u: goto P_0c09d8c6;
case 0x0c09d8c8u: goto P_0c09d8c8;
case 0x0c09d8cau: goto P_0c09d8ca;
case 0x0c09d8ccu: goto P_0c09d8cc;
case 0x0c09d8ceu: goto P_0c09d8ce;
case 0x0c09d8d0u: goto P_0c09d8d0;
case 0x0c09d8d2u: goto P_0c09d8d2;
case 0x0c09d8d4u: goto P_0c09d8d4;
case 0x0c09d8d6u: goto P_0c09d8d6;
case 0x0c09d8d8u: goto P_0c09d8d8;
case 0x0c09d8dau: goto P_0c09d8da;
case 0x0c09d8dcu: goto P_0c09d8dc;
case 0x0c09d8deu: goto P_0c09d8de;
case 0x0c09d8e0u: goto P_0c09d8e0;
case 0x0c09d8e2u: goto P_0c09d8e2;
case 0x0c09d8e4u: goto P_0c09d8e4;
case 0x0c09d8e6u: goto P_0c09d8e6;
case 0x0c09d8e8u: goto P_0c09d8e8;
case 0x0c09d8eau: goto P_0c09d8ea;
case 0x0c09d8ecu: goto P_0c09d8ec;
case 0x0c09d8eeu: goto P_0c09d8ee;
case 0x0c09d8f0u: goto P_0c09d8f0;
case 0x0c09d8f2u: goto P_0c09d8f2;
case 0x0c09d8f4u: goto P_0c09d8f4;
case 0x0c09d8f6u: goto P_0c09d8f6;
case 0x0c09d8f8u: goto P_0c09d8f8;
case 0x0c09d8fau: goto P_0c09d8fa;
case 0x0c09d8fcu: goto P_0c09d8fc;
case 0x0c09d8feu: goto P_0c09d8fe;
case 0x0c09d900u: goto P_0c09d900;
case 0x0c09d902u: goto P_0c09d902;
case 0x0c09d904u: goto P_0c09d904;
case 0x0c09d906u: goto P_0c09d906;
case 0x0c09d908u: goto P_0c09d908;
case 0x0c09d90au: goto P_0c09d90a;
case 0x0c09d90cu: goto P_0c09d90c;
case 0x0c09d90eu: goto P_0c09d90e;
case 0x0c09d910u: goto P_0c09d910;
case 0x0c09d912u: goto P_0c09d912;
case 0x0c09d914u: goto P_0c09d914;
case 0x0c09d916u: goto P_0c09d916;
case 0x0c09d918u: goto P_0c09d918;
case 0x0c09d91au: goto P_0c09d91a;
case 0x0c09d91cu: goto P_0c09d91c;
case 0x0c09d91eu: goto P_0c09d91e;
case 0x0c09d920u: goto P_0c09d920;
case 0x0c09d922u: goto P_0c09d922;
case 0x0c09d924u: goto P_0c09d924;
case 0x0c09d926u: goto P_0c09d926;
case 0x0c09d928u: goto P_0c09d928;
case 0x0c09d92au: goto P_0c09d92a;
case 0x0c09d92cu: goto P_0c09d92c;
case 0x0c09d92eu: goto P_0c09d92e;
case 0x0c09d930u: goto P_0c09d930;
case 0x0c09d932u: goto P_0c09d932;
case 0x0c09d934u: goto P_0c09d934;
case 0x0c09d936u: goto P_0c09d936;
case 0x0c09d938u: goto P_0c09d938;
case 0x0c09d93au: goto P_0c09d93a;
case 0x0c09d93cu: goto P_0c09d93c;
case 0x0c09d93eu: goto P_0c09d93e;
case 0x0c09d940u: goto P_0c09d940;
case 0x0c09d942u: goto P_0c09d942;
case 0x0c09d944u: goto P_0c09d944;
case 0x0c09d946u: goto P_0c09d946;
case 0x0c09d948u: goto P_0c09d948;
case 0x0c09d94au: goto P_0c09d94a;
case 0x0c09d94cu: goto P_0c09d94c;
case 0x0c09d94eu: goto P_0c09d94e;
case 0x0c09d950u: goto P_0c09d950;
case 0x0c09d952u: goto P_0c09d952;
case 0x0c09d954u: goto P_0c09d954;
case 0x0c09d956u: goto P_0c09d956;
case 0x0c09d958u: goto P_0c09d958;
case 0x0c09d95au: goto P_0c09d95a;
case 0x0c09d95cu: goto P_0c09d95c;
case 0x0c09d95eu: goto P_0c09d95e;
case 0x0c09d960u: goto P_0c09d960;
case 0x0c09d962u: goto P_0c09d962;
case 0x0c09d964u: goto P_0c09d964;
case 0x0c09d966u: goto P_0c09d966;
case 0x0c09d968u: goto P_0c09d968;
case 0x0c09d96au: goto P_0c09d96a;
case 0x0c09d96cu: goto P_0c09d96c;
case 0x0c09d96eu: goto P_0c09d96e;
case 0x0c09d970u: goto P_0c09d970;
case 0x0c09d972u: goto P_0c09d972;
case 0x0c09d974u: goto P_0c09d974;
case 0x0c09d976u: goto P_0c09d976;
case 0x0c09d978u: goto P_0c09d978;
case 0x0c09d98cu: goto P_0c09d98c;
case 0x0c09d98eu: goto P_0c09d98e;
case 0x0c09d990u: goto P_0c09d990;
case 0x0c09d992u: goto P_0c09d992;
case 0x0c09d994u: goto P_0c09d994;
case 0x0c09d996u: goto P_0c09d996;
case 0x0c09d998u: goto P_0c09d998;
case 0x0c09d99au: goto P_0c09d99a;
case 0x0c09d99cu: goto P_0c09d99c;
case 0x0c09d99eu: goto P_0c09d99e;
case 0x0c09d9a0u: goto P_0c09d9a0;
case 0x0c09d9a2u: goto P_0c09d9a2;
case 0x0c09d9a4u: goto P_0c09d9a4;
case 0x0c09d9a6u: goto P_0c09d9a6;
case 0x0c09d9a8u: goto P_0c09d9a8;
case 0x0c09d9aau: goto P_0c09d9aa;
case 0x0c09d9acu: goto P_0c09d9ac;
case 0x0c09d9aeu: goto P_0c09d9ae;
case 0x0c09d9b0u: goto P_0c09d9b0;
case 0x0c09d9b2u: goto P_0c09d9b2;
case 0x0c09d9b4u: goto P_0c09d9b4;
case 0x0c09d9b6u: goto P_0c09d9b6;
case 0x0c09d9b8u: goto P_0c09d9b8;
case 0x0c09d9bau: goto P_0c09d9ba;
case 0x0c09d9bcu: goto P_0c09d9bc;
case 0x0c09d9beu: goto P_0c09d9be;
case 0x0c09d9c0u: goto P_0c09d9c0;
case 0x0c09d9c2u: goto P_0c09d9c2;
case 0x0c09d9c4u: goto P_0c09d9c4;
case 0x0c09d9c6u: goto P_0c09d9c6;
case 0x0c09d9c8u: goto P_0c09d9c8;
case 0x0c09d9cau: goto P_0c09d9ca;
case 0x0c09d9ccu: goto P_0c09d9cc;
case 0x0c09d9ceu: goto P_0c09d9ce;
case 0x0c09d9d0u: goto P_0c09d9d0;
case 0x0c09d9d2u: goto P_0c09d9d2;
case 0x0c09d9d4u: goto P_0c09d9d4;
case 0x0c09d9d6u: goto P_0c09d9d6;
case 0x0c09d9d8u: goto P_0c09d9d8;
case 0x0c09d9dau: goto P_0c09d9da;
case 0x0c09d9dcu: goto P_0c09d9dc;
case 0x0c09d9deu: goto P_0c09d9de;
case 0x0c09d9e0u: goto P_0c09d9e0;
case 0x0c09d9e2u: goto P_0c09d9e2;
case 0x0c09d9e4u: goto P_0c09d9e4;
case 0x0c09d9e6u: goto P_0c09d9e6;
case 0x0c09d9e8u: goto P_0c09d9e8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09d838: /* original 2fe6, guest PC 0x0c09d838 */
if(!s->budget--) { s->failed_pc=0x0c09d838u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d83a;
P_0c09d83a: /* original 2fd6, guest PC 0x0c09d83a */
if(!s->budget--) { s->failed_pc=0x0c09d83au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d83c;
P_0c09d83c: /* original 2fc6, guest PC 0x0c09d83c */
if(!s->budget--) { s->failed_pc=0x0c09d83cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d83e;
P_0c09d83e: /* original 2fb6, guest PC 0x0c09d83e */
if(!s->budget--) { s->failed_pc=0x0c09d83eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d840;
P_0c09d840: /* original 2f96, guest PC 0x0c09d840 */
if(!s->budget--) { s->failed_pc=0x0c09d840u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d842;
P_0c09d842: /* original 2f86, guest PC 0x0c09d842 */
if(!s->budget--) { s->failed_pc=0x0c09d842u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09d844;
P_0c09d844: /* original 4f22, guest PC 0x0c09d844 */
if(!s->budget--) { s->failed_pc=0x0c09d844u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09d846;
P_0c09d846: /* original 7fec, guest PC 0x0c09d846 */
if(!s->budget--) { s->failed_pc=0x0c09d846u; return 0; }
r[15]+=0xffffffecu;
goto P_0c09d848;
P_0c09d848: /* original 2f52, guest PC 0x0c09d848 */
if(!s->budget--) { s->failed_pc=0x0c09d848u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09d84a;
P_0c09d84a: /* original 9096, guest PC 0x0c09d84a */
if(!s->budget--) { s->failed_pc=0x0c09d84au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d97au,2);
goto P_0c09d84c;
P_0c09d84c: /* original 084e, guest PC 0x0c09d84c */
if(!s->budget--) { s->failed_pc=0x0c09d84cu; return 0; }
r[8]=read(ram,r[4]+r[0],4);
goto P_0c09d84e;
P_0c09d84e: /* original 6382, guest PC 0x0c09d84e */
if(!s->budget--) { s->failed_pc=0x0c09d84eu; return 0; }
tmp=read(ram,r[8],4);
r[3]=tmp;
goto P_0c09d850;
P_0c09d850: /* original 1f34, guest PC 0x0c09d850 */
if(!s->budget--) { s->failed_pc=0x0c09d850u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c09d852;
P_0c09d852: /* original 63f2, guest PC 0x0c09d852 */
if(!s->budget--) { s->failed_pc=0x0c09d852u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09d854;
P_0c09d854: /* original 5e82, guest PC 0x0c09d854 */
if(!s->budget--) { s->failed_pc=0x0c09d854u; return 0; }
r[14]=read(ram,r[8]+8,4);
goto P_0c09d856;
P_0c09d856: /* original 6232, guest PC 0x0c09d856 */
if(!s->budget--) { s->failed_pc=0x0c09d856u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09d858;
P_0c09d858: /* original 5c81, guest PC 0x0c09d858 */
if(!s->budget--) { s->failed_pc=0x0c09d858u; return 0; }
r[12]=read(ram,r[8]+4,4);
goto P_0c09d85a;
P_0c09d85a: /* original 1f21, guest PC 0x0c09d85a */
if(!s->budget--) { s->failed_pc=0x0c09d85au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c09d85c;
P_0c09d85c: /* original a0b1, guest PC 0x0c09d85c */
if(!s->budget--) { s->failed_pc=0x0c09d85cu; return 0; }
r[9]=0x00000000u;
goto P_0c09d9c2;
P_0c09d85e: /* original e900, guest PC 0x0c09d85e */
if(!s->budget--) { s->failed_pc=0x0c09d85eu; return 0; }
r[9]=0x00000000u;
goto P_0c09d860;
P_0c09d860: /* original 6583, guest PC 0x0c09d860 */
if(!s->budget--) { s->failed_pc=0x0c09d860u; return 0; }
r[5]=r[8];
goto P_0c09d862;
P_0c09d862: /* original 750c, guest PC 0x0c09d862 */
if(!s->budget--) { s->failed_pc=0x0c09d862u; return 0; }
r[5]+=0x0000000cu;
goto P_0c09d864;
P_0c09d864: /* original 359c, guest PC 0x0c09d864 */
if(!s->budget--) { s->failed_pc=0x0c09d864u; return 0; }
r[5]+=r[9];
goto P_0c09d866;
P_0c09d866: /* original 9789, guest PC 0x0c09d866 */
if(!s->budget--) { s->failed_pc=0x0c09d866u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d97cu,2);
goto P_0c09d868;
P_0c09d868: /* original 6550, guest PC 0x0c09d868 */
if(!s->budget--) { s->failed_pc=0x0c09d868u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09d86a;
P_0c09d86a: /* original 6053, guest PC 0x0c09d86a */
if(!s->budget--) { s->failed_pc=0x0c09d86au; return 0; }
r[0]=r[5];
goto P_0c09d86c;
P_0c09d86c: /* original 307c, guest PC 0x0c09d86c */
if(!s->budget--) { s->failed_pc=0x0c09d86cu; return 0; }
r[0]+=r[7];
goto P_0c09d86e;
P_0c09d86e: /* original 675c, guest PC 0x0c09d86e */
if(!s->budget--) { s->failed_pc=0x0c09d86eu; return 0; }
r[7]=r[5]&255u;
goto P_0c09d870;
P_0c09d870: /* original 80f8, guest PC 0x0c09d870 */
if(!s->budget--) { s->failed_pc=0x0c09d870u; return 0; }
write(ram,r[15]+8,r[0],1);
goto P_0c09d872;
P_0c09d872: /* original 6073, guest PC 0x0c09d872 */
if(!s->budget--) { s->failed_pc=0x0c09d872u; return 0; }
r[0]=r[7];
goto P_0c09d874;
P_0c09d874: /* original 8801, guest PC 0x0c09d874 */
if(!s->budget--) { s->failed_pc=0x0c09d874u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09d876;
P_0c09d876: /* original 8f02, guest PC 0x0c09d876 */
if(!s->budget--) { s->failed_pc=0x0c09d876u; return 0; }
cond=r[17]&1u;
fr[4]=0;
if(!cond) { goto P_0c09d87e; }
goto P_0c09d87a;
P_0c09d878: /* original f48d, guest PC 0x0c09d878 */
if(!s->budget--) { s->failed_pc=0x0c09d878u; return 0; }
fr[4]=0;
goto P_0c09d87a;
P_0c09d87a: /* original a09c, guest PC 0x0c09d87a */
if(!s->budget--) { s->failed_pc=0x0c09d87au; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c09d9b6;
P_0c09d87c: /* original f4e9, guest PC 0x0c09d87c */
if(!s->budget--) { s->failed_pc=0x0c09d87cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]);
r[14]+=(r[18]&0x100000u)?8:4;
goto P_0c09d87e;
P_0c09d87e: /* original e501, guest PC 0x0c09d87e */
if(!s->budget--) { s->failed_pc=0x0c09d87eu; return 0; }
r[5]=0x00000001u;
goto P_0c09d880;
P_0c09d880: /* original 3753, guest PC 0x0c09d880 */
if(!s->budget--) { s->failed_pc=0x0c09d880u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[5])!=0);
goto P_0c09d882;
P_0c09d882: /* original 8901, guest PC 0x0c09d882 */
if(!s->budget--) { s->failed_pc=0x0c09d882u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d888; }
goto P_0c09d884;
P_0c09d884: /* original a097, guest PC 0x0c09d884 */
if(!s->budget--) { s->failed_pc=0x0c09d884u; return 0; }
goto P_0c09d9b6;
P_0c09d886: /* original 0009, guest PC 0x0c09d886 */
if(!s->budget--) { s->failed_pc=0x0c09d886u; return 0; }
goto P_0c09d888;
P_0c09d888: /* original 55f4, guest PC 0x0c09d888 */
if(!s->budget--) { s->failed_pc=0x0c09d888u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c09d88a;
P_0c09d88a: /* original ed00, guest PC 0x0c09d88a */
if(!s->budget--) { s->failed_pc=0x0c09d88au; return 0; }
r[13]=0x00000000u;
goto P_0c09d88c;
P_0c09d88c: /* original 7501, guest PC 0x0c09d88c */
if(!s->budget--) { s->failed_pc=0x0c09d88cu; return 0; }
r[5]+=0x00000001u;
goto P_0c09d88e;
P_0c09d88e: /* original 1f54, guest PC 0x0c09d88e */
if(!s->budget--) { s->failed_pc=0x0c09d88eu; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c09d890;
P_0c09d890: /* original 9775, guest PC 0x0c09d890 */
if(!s->budget--) { s->failed_pc=0x0c09d890u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d97eu,2);
goto P_0c09d892;
P_0c09d892: /* original 6550, guest PC 0x0c09d892 */
if(!s->budget--) { s->failed_pc=0x0c09d892u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]=tmp;
goto P_0c09d894;
P_0c09d894: /* original 1f73, guest PC 0x0c09d894 */
if(!s->budget--) { s->failed_pc=0x0c09d894u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d896;
P_0c09d896: /* original 9073, guest PC 0x0c09d896 */
if(!s->budget--) { s->failed_pc=0x0c09d896u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d980u,2);
goto P_0c09d898;
P_0c09d898: /* original 655c, guest PC 0x0c09d898 */
if(!s->budget--) { s->failed_pc=0x0c09d898u; return 0; }
r[5]=r[5]&255u;
goto P_0c09d89a;
P_0c09d89a: /* original 2558, guest PC 0x0c09d89a */
if(!s->budget--) { s->failed_pc=0x0c09d89au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c09d89c;
P_0c09d89c: /* original 074d, guest PC 0x0c09d89c */
if(!s->budget--) { s->failed_pc=0x0c09d89cu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d89e;
P_0c09d89e: /* original 677d, guest PC 0x0c09d89e */
if(!s->budget--) { s->failed_pc=0x0c09d89eu; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d8a0;
P_0c09d8a0: /* original 8d29, guest PC 0x0c09d8a0 */
if(!s->budget--) { s->failed_pc=0x0c09d8a0u; return 0; }
cond=r[17]&1u;
r[7]<<=8;
if(cond) { goto P_0c09d8f6; }
goto P_0c09d8a4;
P_0c09d8a2: /* original 4718, guest PC 0x0c09d8a2 */
if(!s->budget--) { s->failed_pc=0x0c09d8a2u; return 0; }
r[7]<<=8;
goto P_0c09d8a4;
P_0c09d8a4: /* original 67d3, guest PC 0x0c09d8a4 */
if(!s->budget--) { s->failed_pc=0x0c09d8a4u; return 0; }
r[7]=r[13];
goto P_0c09d8a6;
P_0c09d8a6: /* original 4700, guest PC 0x0c09d8a6 */
if(!s->budget--) { s->failed_pc=0x0c09d8a6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c09d8a8;
P_0c09d8a8: /* original 37cc, guest PC 0x0c09d8a8 */
if(!s->budget--) { s->failed_pc=0x0c09d8a8u; return 0; }
r[7]+=r[12];
goto P_0c09d8aa;
P_0c09d8aa: /* original 35d7, guest PC 0x0c09d8aa */
if(!s->budget--) { s->failed_pc=0x0c09d8aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[13])!=0);
goto P_0c09d8ac;
P_0c09d8ac: /* original 6771, guest PC 0x0c09d8ac */
if(!s->budget--) { s->failed_pc=0x0c09d8acu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[7]=tmp;
goto P_0c09d8ae;
P_0c09d8ae: /* original 677d, guest PC 0x0c09d8ae */
if(!s->budget--) { s->failed_pc=0x0c09d8aeu; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d8b0;
P_0c09d8b0: /* original 8f1d, guest PC 0x0c09d8b0 */
if(!s->budget--) { s->failed_pc=0x0c09d8b0u; return 0; }
cond=r[17]&1u;
r[7]<<=8;
if(!cond) { goto P_0c09d8ee; }
goto P_0c09d8b4;
P_0c09d8b2: /* original 4718, guest PC 0x0c09d8b2 */
if(!s->budget--) { s->failed_pc=0x0c09d8b2u; return 0; }
r[7]<<=8;
goto P_0c09d8b4;
P_0c09d8b4: /* original 3767, guest PC 0x0c09d8b4 */
if(!s->budget--) { s->failed_pc=0x0c09d8b4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c09d8b6;
P_0c09d8b6: /* original 891e, guest PC 0x0c09d8b6 */
if(!s->budget--) { s->failed_pc=0x0c09d8b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d8f6; }
goto P_0c09d8b8;
P_0c09d8b8: /* original 3670, guest PC 0x0c09d8b8 */
if(!s->budget--) { s->failed_pc=0x0c09d8b8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c09d8ba;
P_0c09d8ba: /* original 8902, guest PC 0x0c09d8ba */
if(!s->budget--) { s->failed_pc=0x0c09d8bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d8c2; }
goto P_0c09d8bc;
P_0c09d8bc: /* original 7d01, guest PC 0x0c09d8bc */
if(!s->budget--) { s->failed_pc=0x0c09d8bcu; return 0; }
r[13]+=0x00000001u;
goto P_0c09d8be;
P_0c09d8be: /* original aff1, guest PC 0x0c09d8be */
if(!s->budget--) { s->failed_pc=0x0c09d8beu; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d8a4;
P_0c09d8c0: /* original 1f73, guest PC 0x0c09d8c0 */
if(!s->budget--) { s->failed_pc=0x0c09d8c0u; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c09d8c2;
P_0c09d8c2: /* original 84f8, guest PC 0x0c09d8c2 */
if(!s->budget--) { s->failed_pc=0x0c09d8c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c09d8c4;
P_0c09d8c4: /* original 6253, guest PC 0x0c09d8c4 */
if(!s->budget--) { s->failed_pc=0x0c09d8c4u; return 0; }
r[2]=r[5];
goto P_0c09d8c6;
P_0c09d8c6: /* original 4200, guest PC 0x0c09d8c6 */
if(!s->budget--) { s->failed_pc=0x0c09d8c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d8c8;
P_0c09d8c8: /* original 67d3, guest PC 0x0c09d8c8 */
if(!s->budget--) { s->failed_pc=0x0c09d8c8u; return 0; }
r[7]=r[13];
goto P_0c09d8ca;
P_0c09d8ca: /* original 2008, guest PC 0x0c09d8ca */
if(!s->budget--) { s->failed_pc=0x0c09d8cau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09d8cc;
P_0c09d8cc: /* original 3c2c, guest PC 0x0c09d8cc */
if(!s->budget--) { s->failed_pc=0x0c09d8ccu; return 0; }
r[12]+=r[2];
goto P_0c09d8ce;
P_0c09d8ce: /* original 8d07, guest PC 0x0c09d8ce */
if(!s->budget--) { s->failed_pc=0x0c09d8ceu; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(cond) { goto P_0c09d8e0; }
goto P_0c09d8d2;
P_0c09d8d0: /* original 7701, guest PC 0x0c09d8d0 */
if(!s->budget--) { s->failed_pc=0x0c09d8d0u; return 0; }
r[7]+=0x00000001u;
goto P_0c09d8d2;
P_0c09d8d2: /* original 6d53, guest PC 0x0c09d8d2 */
if(!s->budget--) { s->failed_pc=0x0c09d8d2u; return 0; }
r[13]=r[5];
goto P_0c09d8d4;
P_0c09d8d4: /* original 6b73, guest PC 0x0c09d8d4 */
if(!s->budget--) { s->failed_pc=0x0c09d8d4u; return 0; }
r[11]=r[7];
goto P_0c09d8d6;
P_0c09d8d6: /* original 3d5c, guest PC 0x0c09d8d6 */
if(!s->budget--) { s->failed_pc=0x0c09d8d6u; return 0; }
r[13]+=r[5];
goto P_0c09d8d8;
P_0c09d8d8: /* original 35dc, guest PC 0x0c09d8d8 */
if(!s->budget--) { s->failed_pc=0x0c09d8d8u; return 0; }
r[5]+=r[13];
goto P_0c09d8da;
P_0c09d8da: /* original 4b00, guest PC 0x0c09d8da */
if(!s->budget--) { s->failed_pc=0x0c09d8dau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c09d8dc;
P_0c09d8dc: /* original 7502, guest PC 0x0c09d8dc */
if(!s->budget--) { s->failed_pc=0x0c09d8dcu; return 0; }
r[5]+=0x00000002u;
goto P_0c09d8de;
P_0c09d8de: /* original 37bc, guest PC 0x0c09d8de */
if(!s->budget--) { s->failed_pc=0x0c09d8deu; return 0; }
r[7]+=r[11];
goto P_0c09d8e0;
P_0c09d8e0: /* original 4708, guest PC 0x0c09d8e0 */
if(!s->budget--) { s->failed_pc=0x0c09d8e0u; return 0; }
r[7]<<=2;
goto P_0c09d8e2;
P_0c09d8e2: /* original 37ec, guest PC 0x0c09d8e2 */
if(!s->budget--) { s->failed_pc=0x0c09d8e2u; return 0; }
r[7]+=r[14];
goto P_0c09d8e4;
P_0c09d8e4: /* original f478, guest PC 0x0c09d8e4 */
if(!s->budget--) { s->failed_pc=0x0c09d8e4u; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
goto P_0c09d8e6;
P_0c09d8e6: /* original 7502, guest PC 0x0c09d8e6 */
if(!s->budget--) { s->failed_pc=0x0c09d8e6u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d8e8;
P_0c09d8e8: /* original 4508, guest PC 0x0c09d8e8 */
if(!s->budget--) { s->failed_pc=0x0c09d8e8u; return 0; }
r[5]<<=2;
goto P_0c09d8ea;
P_0c09d8ea: /* original a064, guest PC 0x0c09d8ea */
if(!s->budget--) { s->failed_pc=0x0c09d8eau; return 0; }
r[14]+=r[5];
goto P_0c09d9b6;
P_0c09d8ec: /* original 3e5c, guest PC 0x0c09d8ec */
if(!s->budget--) { s->failed_pc=0x0c09d8ecu; return 0; }
r[14]+=r[5];
goto P_0c09d8ee;
P_0c09d8ee: /* original 9047, guest PC 0x0c09d8ee */
if(!s->budget--) { s->failed_pc=0x0c09d8eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d980u,2);
goto P_0c09d8f0;
P_0c09d8f0: /* original 074d, guest PC 0x0c09d8f0 */
if(!s->budget--) { s->failed_pc=0x0c09d8f0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09d8f2;
P_0c09d8f2: /* original 677d, guest PC 0x0c09d8f2 */
if(!s->budget--) { s->failed_pc=0x0c09d8f2u; return 0; }
r[7]=r[7]&65535u;
goto P_0c09d8f4;
P_0c09d8f4: /* original 4718, guest PC 0x0c09d8f4 */
if(!s->budget--) { s->failed_pc=0x0c09d8f4u; return 0; }
r[7]<<=8;
goto P_0c09d8f6;
P_0c09d8f6: /* original 84f8, guest PC 0x0c09d8f6 */
if(!s->budget--) { s->failed_pc=0x0c09d8f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+8,1);
goto P_0c09d8f8;
P_0c09d8f8: /* original 6b73, guest PC 0x0c09d8f8 */
if(!s->budget--) { s->failed_pc=0x0c09d8f8u; return 0; }
r[11]=r[7];
goto P_0c09d8fa;
P_0c09d8fa: /* original 53f3, guest PC 0x0c09d8fa */
if(!s->budget--) { s->failed_pc=0x0c09d8fau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c09d8fc;
P_0c09d8fc: /* original 6163, guest PC 0x0c09d8fc */
if(!s->budget--) { s->failed_pc=0x0c09d8fcu; return 0; }
r[1]=r[6];
goto P_0c09d8fe;
P_0c09d8fe: /* original 2008, guest PC 0x0c09d8fe */
if(!s->budget--) { s->failed_pc=0x0c09d8feu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09d900;
P_0c09d900: /* original 3b38, guest PC 0x0c09d900 */
if(!s->budget--) { s->failed_pc=0x0c09d900u; return 0; }
r[11]-=r[3];
goto P_0c09d902;
P_0c09d902: /* original 8d43, guest PC 0x0c09d902 */
if(!s->budget--) { s->failed_pc=0x0c09d902u; return 0; }
cond=r[17]&1u;
r[1]-=r[3];
if(cond) { goto P_0c09d98c; }
goto P_0c09d906;
P_0c09d904: /* original 3138, guest PC 0x0c09d904 */
if(!s->budget--) { s->failed_pc=0x0c09d904u; return 0; }
r[1]-=r[3];
goto P_0c09d906;
P_0c09d906: /* original 415a, guest PC 0x0c09d906 */
if(!s->budget--) { s->failed_pc=0x0c09d906u; return 0; }
r[53]=r[1];
goto P_0c09d908;
P_0c09d908: /* original 67d3, guest PC 0x0c09d908 */
if(!s->budget--) { s->failed_pc=0x0c09d908u; return 0; }
r[7]=r[13];
goto P_0c09d90a;
P_0c09d90a: /* original 4700, guest PC 0x0c09d90a */
if(!s->budget--) { s->failed_pc=0x0c09d90au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c09d90c;
P_0c09d90c: /* original 62d3, guest PC 0x0c09d90c */
if(!s->budget--) { s->failed_pc=0x0c09d90cu; return 0; }
r[2]=r[13];
goto P_0c09d90e;
P_0c09d90e: /* original 372c, guest PC 0x0c09d90e */
if(!s->budget--) { s->failed_pc=0x0c09d90eu; return 0; }
r[7]+=r[2];
goto P_0c09d910;
P_0c09d910: /* original f32d, guest PC 0x0c09d910 */
if(!s->budget--) { s->failed_pc=0x0c09d910u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d912;
P_0c09d912: /* original 4b5a, guest PC 0x0c09d912 */
if(!s->budget--) { s->failed_pc=0x0c09d912u; return 0; }
r[53]=r[11];
goto P_0c09d914;
P_0c09d914: /* original 4708, guest PC 0x0c09d914 */
if(!s->budget--) { s->failed_pc=0x0c09d914u; return 0; }
r[7]<<=2;
goto P_0c09d916;
P_0c09d916: /* original 37ec, guest PC 0x0c09d916 */
if(!s->budget--) { s->failed_pc=0x0c09d916u; return 0; }
r[7]+=r[14];
goto P_0c09d918;
P_0c09d918: /* original f22d, guest PC 0x0c09d918 */
if(!s->budget--) { s->failed_pc=0x0c09d918u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d91a;
P_0c09d91a: /* original e004, guest PC 0x0c09d91a */
if(!s->budget--) { s->failed_pc=0x0c09d91au; return 0; }
r[0]=0x00000004u;
goto P_0c09d91c;
P_0c09d91c: /* original f876, guest PC 0x0c09d91c */
if(!s->budget--) { s->failed_pc=0x0c09d91cu; return 0; }
vf3_matrix_load(s,ram,8,r[7]+r[0]);
goto P_0c09d91e;
P_0c09d91e: /* original e008, guest PC 0x0c09d91e */
if(!s->budget--) { s->failed_pc=0x0c09d91eu; return 0; }
r[0]=0x00000008u;
goto P_0c09d920;
P_0c09d920: /* original f53c, guest PC 0x0c09d920 */
if(!s->budget--) { s->failed_pc=0x0c09d920u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c09d922;
P_0c09d922: /* original f976, guest PC 0x0c09d922 */
if(!s->budget--) { s->failed_pc=0x0c09d922u; return 0; }
vf3_matrix_load(s,ram,9,r[7]+r[0]);
goto P_0c09d924;
P_0c09d924: /* original e00c, guest PC 0x0c09d924 */
if(!s->budget--) { s->failed_pc=0x0c09d924u; return 0; }
r[0]=0x0000000cu;
goto P_0c09d926;
P_0c09d926: /* original f176, guest PC 0x0c09d926 */
if(!s->budget--) { s->failed_pc=0x0c09d926u; return 0; }
vf3_matrix_load(s,ram,1,r[7]+r[0]);
goto P_0c09d928;
P_0c09d928: /* original c716, guest PC 0x0c09d928 */
if(!s->budget--) { s->failed_pc=0x0c09d928u; return 0; }
r[0]=code_base|0x0009d984u;
goto P_0c09d92a;
P_0c09d92a: /* original f523, guest PC 0x0c09d92a */
if(!s->budget--) { s->failed_pc=0x0c09d92au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'/');
goto P_0c09d92c;
P_0c09d92c: /* original f408, guest PC 0x0c09d92c */
if(!s->budget--) { s->failed_pc=0x0c09d92cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09d92e;
P_0c09d92e: /* original c716, guest PC 0x0c09d92e */
if(!s->budget--) { s->failed_pc=0x0c09d92eu; return 0; }
r[0]=code_base|0x0009d988u;
goto P_0c09d930;
P_0c09d930: /* original fa3c, guest PC 0x0c09d930 */
if(!s->budget--) { s->failed_pc=0x0c09d930u; return 0; }
vf3_matrix_move(s,10,3);
goto P_0c09d932;
P_0c09d932: /* original f942, guest PC 0x0c09d932 */
if(!s->budget--) { s->failed_pc=0x0c09d932u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'*');
goto P_0c09d934;
P_0c09d934: /* original f708, guest PC 0x0c09d934 */
if(!s->budget--) { s->failed_pc=0x0c09d934u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c09d936;
P_0c09d936: /* original f842, guest PC 0x0c09d936 */
if(!s->budget--) { s->failed_pc=0x0c09d936u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c09d938;
P_0c09d938: /* original fb78, guest PC 0x0c09d938 */
if(!s->budget--) { s->failed_pc=0x0c09d938u; return 0; }
vf3_matrix_load(s,ram,11,r[7]);
goto P_0c09d93a;
P_0c09d93a: /* original f49c, guest PC 0x0c09d93a */
if(!s->budget--) { s->failed_pc=0x0c09d93au; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c09d93c;
P_0c09d93c: /* original f08c, guest PC 0x0c09d93c */
if(!s->budget--) { s->failed_pc=0x0c09d93cu; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c09d93e;
P_0c09d93e: /* original f65c, guest PC 0x0c09d93e */
if(!s->budget--) { s->failed_pc=0x0c09d93eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c09d940;
P_0c09d940: /* original f452, guest PC 0x0c09d940 */
if(!s->budget--) { s->failed_pc=0x0c09d940u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09d942;
P_0c09d942: /* original f670, guest PC 0x0c09d942 */
if(!s->budget--) { s->failed_pc=0x0c09d942u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c09d944;
P_0c09d944: /* original f34c, guest PC 0x0c09d944 */
if(!s->budget--) { s->failed_pc=0x0c09d944u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09d946;
P_0c09d946: /* original f36e, guest PC 0x0c09d946 */
if(!s->budget--) { s->failed_pc=0x0c09d946u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c09d948;
P_0c09d948: /* original f0ac, guest PC 0x0c09d948 */
if(!s->budget--) { s->failed_pc=0x0c09d948u; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c09d94a;
P_0c09d94a: /* original f8bc, guest PC 0x0c09d94a */
if(!s->budget--) { s->failed_pc=0x0c09d94au; return 0; }
vf3_matrix_move(s,8,11);
goto P_0c09d94c;
P_0c09d94c: /* original 6253, guest PC 0x0c09d94c */
if(!s->budget--) { s->failed_pc=0x0c09d94cu; return 0; }
r[2]=r[5];
goto P_0c09d94e;
P_0c09d94e: /* original 4200, guest PC 0x0c09d94e */
if(!s->budget--) { s->failed_pc=0x0c09d94eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d950;
P_0c09d950: /* original 6153, guest PC 0x0c09d950 */
if(!s->budget--) { s->failed_pc=0x0c09d950u; return 0; }
r[1]=r[5];
goto P_0c09d952;
P_0c09d952: /* original 3c2c, guest PC 0x0c09d952 */
if(!s->budget--) { s->failed_pc=0x0c09d952u; return 0; }
r[12]+=r[2];
goto P_0c09d954;
P_0c09d954: /* original 6253, guest PC 0x0c09d954 */
if(!s->budget--) { s->failed_pc=0x0c09d954u; return 0; }
r[2]=r[5];
goto P_0c09d956;
P_0c09d956: /* original f43c, guest PC 0x0c09d956 */
if(!s->budget--) { s->failed_pc=0x0c09d956u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09d958;
P_0c09d958: /* original f462, guest PC 0x0c09d958 */
if(!s->budget--) { s->failed_pc=0x0c09d958u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09d95a;
P_0c09d95a: /* original 4100, guest PC 0x0c09d95a */
if(!s->budget--) { s->failed_pc=0x0c09d95au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c09d95c;
P_0c09d95c: /* original 312c, guest PC 0x0c09d95c */
if(!s->budget--) { s->failed_pc=0x0c09d95cu; return 0; }
r[1]+=r[2];
goto P_0c09d95e;
P_0c09d95e: /* original 6513, guest PC 0x0c09d95e */
if(!s->budget--) { s->failed_pc=0x0c09d95eu; return 0; }
r[5]=r[1];
goto P_0c09d960;
P_0c09d960: /* original f84e, guest PC 0x0c09d960 */
if(!s->budget--) { s->failed_pc=0x0c09d960u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[4],fr[8],r[18]);
goto P_0c09d962;
P_0c09d962: /* original f46c, guest PC 0x0c09d962 */
if(!s->budget--) { s->failed_pc=0x0c09d962u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c09d964;
P_0c09d964: /* original f460, guest PC 0x0c09d964 */
if(!s->budget--) { s->failed_pc=0x0c09d964u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c09d966;
P_0c09d966: /* original f6bc, guest PC 0x0c09d966 */
if(!s->budget--) { s->failed_pc=0x0c09d966u; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c09d968;
P_0c09d968: /* original f611, guest PC 0x0c09d968 */
if(!s->budget--) { s->failed_pc=0x0c09d968u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[1],r[18],'-');
goto P_0c09d96a;
P_0c09d96a: /* original f05c, guest PC 0x0c09d96a */
if(!s->budget--) { s->failed_pc=0x0c09d96au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09d96c;
P_0c09d96c: /* original f470, guest PC 0x0c09d96c */
if(!s->budget--) { s->failed_pc=0x0c09d96cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c09d96e;
P_0c09d96e: /* original f462, guest PC 0x0c09d96e */
if(!s->budget--) { s->failed_pc=0x0c09d96eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c09d970;
P_0c09d970: /* original f452, guest PC 0x0c09d970 */
if(!s->budget--) { s->failed_pc=0x0c09d970u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c09d972;
P_0c09d972: /* original f84e, guest PC 0x0c09d972 */
if(!s->budget--) { s->failed_pc=0x0c09d972u; return 0; }
fr[8]=vf3_fpu_mac(fr[0],fr[4],fr[8],r[18]);
goto P_0c09d974;
P_0c09d974: /* original f48c, guest PC 0x0c09d974 */
if(!s->budget--) { s->failed_pc=0x0c09d974u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c09d976;
P_0c09d976: /* original a01b, guest PC 0x0c09d976 */
if(!s->budget--) { s->failed_pc=0x0c09d976u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d9b0;
P_0c09d978: /* original 7502, guest PC 0x0c09d978 */
if(!s->budget--) { s->failed_pc=0x0c09d978u; return 0; }
r[5]+=0x00000002u;
if(!vf3_matrix_family(0x0c09d97au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d97au; return 0; } return 1;
P_0c09d98c: /* original 4b5a, guest PC 0x0c09d98c */
if(!s->budget--) { s->failed_pc=0x0c09d98cu; return 0; }
r[53]=r[11];
goto P_0c09d98e;
P_0c09d98e: /* original 67d3, guest PC 0x0c09d98e */
if(!s->budget--) { s->failed_pc=0x0c09d98eu; return 0; }
r[7]=r[13];
goto P_0c09d990;
P_0c09d990: /* original 4708, guest PC 0x0c09d990 */
if(!s->budget--) { s->failed_pc=0x0c09d990u; return 0; }
r[7]<<=2;
goto P_0c09d992;
P_0c09d992: /* original 6253, guest PC 0x0c09d992 */
if(!s->budget--) { s->failed_pc=0x0c09d992u; return 0; }
r[2]=r[5];
goto P_0c09d994;
P_0c09d994: /* original 37ec, guest PC 0x0c09d994 */
if(!s->budget--) { s->failed_pc=0x0c09d994u; return 0; }
r[7]+=r[14];
goto P_0c09d996;
P_0c09d996: /* original f32d, guest PC 0x0c09d996 */
if(!s->budget--) { s->failed_pc=0x0c09d996u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d998;
P_0c09d998: /* original 415a, guest PC 0x0c09d998 */
if(!s->budget--) { s->failed_pc=0x0c09d998u; return 0; }
r[53]=r[1];
goto P_0c09d99a;
P_0c09d99a: /* original f479, guest PC 0x0c09d99a */
if(!s->budget--) { s->failed_pc=0x0c09d99au; return 0; }
vf3_matrix_load(s,ram,4,r[7]);
r[7]+=(r[18]&0x100000u)?8:4;
goto P_0c09d99c;
P_0c09d99c: /* original 4200, guest PC 0x0c09d99c */
if(!s->budget--) { s->failed_pc=0x0c09d99cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09d99e;
P_0c09d99e: /* original 3c2c, guest PC 0x0c09d99e */
if(!s->budget--) { s->failed_pc=0x0c09d99eu; return 0; }
r[12]+=r[2];
goto P_0c09d9a0;
P_0c09d9a0: /* original f22d, guest PC 0x0c09d9a0 */
if(!s->budget--) { s->failed_pc=0x0c09d9a0u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c09d9a2;
P_0c09d9a2: /* original f578, guest PC 0x0c09d9a2 */
if(!s->budget--) { s->failed_pc=0x0c09d9a2u; return 0; }
vf3_matrix_load(s,ram,5,r[7]);
goto P_0c09d9a4;
P_0c09d9a4: /* original f541, guest PC 0x0c09d9a4 */
if(!s->budget--) { s->failed_pc=0x0c09d9a4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c09d9a6;
P_0c09d9a6: /* original f62c, guest PC 0x0c09d9a6 */
if(!s->budget--) { s->failed_pc=0x0c09d9a6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c09d9a8;
P_0c09d9a8: /* original f633, guest PC 0x0c09d9a8 */
if(!s->budget--) { s->failed_pc=0x0c09d9a8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'/');
goto P_0c09d9aa;
P_0c09d9aa: /* original f05c, guest PC 0x0c09d9aa */
if(!s->budget--) { s->failed_pc=0x0c09d9aau; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09d9ac;
P_0c09d9ac: /* original f72c, guest PC 0x0c09d9ac */
if(!s->budget--) { s->failed_pc=0x0c09d9acu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c09d9ae;
P_0c09d9ae: /* original f46e, guest PC 0x0c09d9ae */
if(!s->budget--) { s->failed_pc=0x0c09d9aeu; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c09d9b0;
P_0c09d9b0: /* original 7502, guest PC 0x0c09d9b0 */
if(!s->budget--) { s->failed_pc=0x0c09d9b0u; return 0; }
r[5]+=0x00000002u;
goto P_0c09d9b2;
P_0c09d9b2: /* original 4508, guest PC 0x0c09d9b2 */
if(!s->budget--) { s->failed_pc=0x0c09d9b2u; return 0; }
r[5]<<=2;
goto P_0c09d9b4;
P_0c09d9b4: /* original 3e5c, guest PC 0x0c09d9b4 */
if(!s->budget--) { s->failed_pc=0x0c09d9b4u; return 0; }
r[14]+=r[5];
goto P_0c09d9b6;
P_0c09d9b6: /* original 53f1, guest PC 0x0c09d9b6 */
if(!s->budget--) { s->failed_pc=0x0c09d9b6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d9b8;
P_0c09d9b8: /* original 7901, guest PC 0x0c09d9b8 */
if(!s->budget--) { s->failed_pc=0x0c09d9b8u; return 0; }
r[9]+=0x00000001u;
goto P_0c09d9ba;
P_0c09d9ba: /* original f34a, guest PC 0x0c09d9ba */
if(!s->budget--) { s->failed_pc=0x0c09d9bau; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c09d9bc;
P_0c09d9bc: /* original 53f1, guest PC 0x0c09d9bc */
if(!s->budget--) { s->failed_pc=0x0c09d9bcu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d9be;
P_0c09d9be: /* original 7304, guest PC 0x0c09d9be */
if(!s->budget--) { s->failed_pc=0x0c09d9beu; return 0; }
r[3]+=0x00000004u;
goto P_0c09d9c0;
P_0c09d9c0: /* original 1f31, guest PC 0x0c09d9c0 */
if(!s->budget--) { s->failed_pc=0x0c09d9c0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09d9c2;
P_0c09d9c2: /* original e53f, guest PC 0x0c09d9c2 */
if(!s->budget--) { s->failed_pc=0x0c09d9c2u; return 0; }
r[5]=0x0000003fu;
goto P_0c09d9c4;
P_0c09d9c4: /* original 3952, guest PC 0x0c09d9c4 */
if(!s->budget--) { s->failed_pc=0x0c09d9c4u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[5])!=0);
goto P_0c09d9c6;
P_0c09d9c6: /* original 8901, guest PC 0x0c09d9c6 */
if(!s->budget--) { s->failed_pc=0x0c09d9c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d9cc; }
goto P_0c09d9c8;
P_0c09d9c8: /* original af4a, guest PC 0x0c09d9c8 */
if(!s->budget--) { s->failed_pc=0x0c09d9c8u; return 0; }
goto P_0c09d860;
P_0c09d9ca: /* original 0009, guest PC 0x0c09d9ca */
if(!s->budget--) { s->failed_pc=0x0c09d9cau; return 0; }
goto P_0c09d9cc;
P_0c09d9cc: /* original 64f2, guest PC 0x0c09d9cc */
if(!s->budget--) { s->failed_pc=0x0c09d9ccu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09d9ce;
P_0c09d9ce: /* original bd1b, guest PC 0x0c09d9ce */
if(!s->budget--) { s->failed_pc=0x0c09d9ceu; return 0; }
target=code_base|0x0c09d408u; r[16]=code_base|0x0c09d9d2u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d9d2u) { target=s->pc; goto dispatch; }
goto P_0c09d9d2;
P_0c09d9d0: /* original 6442, guest PC 0x0c09d9d0 */
if(!s->budget--) { s->failed_pc=0x0c09d9d0u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c09d9d2;
P_0c09d9d2: /* original 53f1, guest PC 0x0c09d9d2 */
if(!s->budget--) { s->failed_pc=0x0c09d9d2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d9d4;
P_0c09d9d4: /* original 62f2, guest PC 0x0c09d9d4 */
if(!s->budget--) { s->failed_pc=0x0c09d9d4u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09d9d6;
P_0c09d9d6: /* original 7f14, guest PC 0x0c09d9d6 */
if(!s->budget--) { s->failed_pc=0x0c09d9d6u; return 0; }
r[15]+=0x00000014u;
goto P_0c09d9d8;
P_0c09d9d8: /* original 4f26, guest PC 0x0c09d9d8 */
if(!s->budget--) { s->failed_pc=0x0c09d9d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d9da;
P_0c09d9da: /* original 2232, guest PC 0x0c09d9da */
if(!s->budget--) { s->failed_pc=0x0c09d9dau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c09d9dc;
P_0c09d9dc: /* original 68f6, guest PC 0x0c09d9dc */
if(!s->budget--) { s->failed_pc=0x0c09d9dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09d9de;
P_0c09d9de: /* original 69f6, guest PC 0x0c09d9de */
if(!s->budget--) { s->failed_pc=0x0c09d9deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09d9e0;
P_0c09d9e0: /* original 6bf6, guest PC 0x0c09d9e0 */
if(!s->budget--) { s->failed_pc=0x0c09d9e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09d9e2;
P_0c09d9e2: /* original 6cf6, guest PC 0x0c09d9e2 */
if(!s->budget--) { s->failed_pc=0x0c09d9e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d9e4;
P_0c09d9e4: /* original 6df6, guest PC 0x0c09d9e4 */
if(!s->budget--) { s->failed_pc=0x0c09d9e4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d9e6;
P_0c09d9e6: /* original 000b, guest PC 0x0c09d9e6 */
if(!s->budget--) { s->failed_pc=0x0c09d9e6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d9e8: /* original 6ef6, guest PC 0x0c09d9e8 */
if(!s->budget--) { s->failed_pc=0x0c09d9e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09d9eau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d9eau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
