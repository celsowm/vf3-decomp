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
int vf3_away_batch8_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05d5a8u: goto P_0c05d5a8;
case 0x0c05d5aau: goto P_0c05d5aa;
case 0x0c05d5acu: goto P_0c05d5ac;
case 0x0c05d5aeu: goto P_0c05d5ae;
case 0x0c05d5b0u: goto P_0c05d5b0;
case 0x0c05d5b2u: goto P_0c05d5b2;
case 0x0c05d5b4u: goto P_0c05d5b4;
case 0x0c05d5b6u: goto P_0c05d5b6;
case 0x0c05d5b8u: goto P_0c05d5b8;
case 0x0c05d5bau: goto P_0c05d5ba;
case 0x0c05d5bcu: goto P_0c05d5bc;
case 0x0c05d5beu: goto P_0c05d5be;
case 0x0c05d5c0u: goto P_0c05d5c0;
case 0x0c05d5c2u: goto P_0c05d5c2;
case 0x0c05d5c4u: goto P_0c05d5c4;
case 0x0c05d5c6u: goto P_0c05d5c6;
case 0x0c05d5c8u: goto P_0c05d5c8;
case 0x0c05d5cau: goto P_0c05d5ca;
case 0x0c05d5ccu: goto P_0c05d5cc;
case 0x0c05d5ceu: goto P_0c05d5ce;
case 0x0c05d5d0u: goto P_0c05d5d0;
case 0x0c05d5d2u: goto P_0c05d5d2;
case 0x0c05d5d4u: goto P_0c05d5d4;
case 0x0c05d5d6u: goto P_0c05d5d6;
case 0x0c05d5d8u: goto P_0c05d5d8;
case 0x0c05d5dau: goto P_0c05d5da;
case 0x0c05d5dcu: goto P_0c05d5dc;
case 0x0c05d5deu: goto P_0c05d5de;
case 0x0c05d5e0u: goto P_0c05d5e0;
case 0x0c05d5e2u: goto P_0c05d5e2;
case 0x0c05d5e4u: goto P_0c05d5e4;
case 0x0c05d5e6u: goto P_0c05d5e6;
case 0x0c05d5e8u: goto P_0c05d5e8;
case 0x0c05d5eau: goto P_0c05d5ea;
case 0x0c05d5ecu: goto P_0c05d5ec;
case 0x0c05d5eeu: goto P_0c05d5ee;
case 0x0c05d5f0u: goto P_0c05d5f0;
case 0x0c05d5f2u: goto P_0c05d5f2;
case 0x0c05d5f4u: goto P_0c05d5f4;
case 0x0c05d5f6u: goto P_0c05d5f6;
case 0x0c05d5f8u: goto P_0c05d5f8;
case 0x0c05d5fau: goto P_0c05d5fa;
case 0x0c05d5fcu: goto P_0c05d5fc;
case 0x0c05d5feu: goto P_0c05d5fe;
case 0x0c05d600u: goto P_0c05d600;
case 0x0c05d602u: goto P_0c05d602;
case 0x0c05d604u: goto P_0c05d604;
case 0x0c05d606u: goto P_0c05d606;
case 0x0c05d608u: goto P_0c05d608;
case 0x0c05d60au: goto P_0c05d60a;
case 0x0c05d60cu: goto P_0c05d60c;
case 0x0c05d60eu: goto P_0c05d60e;
case 0x0c05d610u: goto P_0c05d610;
case 0x0c05d612u: goto P_0c05d612;
case 0x0c05d614u: goto P_0c05d614;
case 0x0c05d616u: goto P_0c05d616;
case 0x0c05d618u: goto P_0c05d618;
case 0x0c05d61au: goto P_0c05d61a;
case 0x0c05d61cu: goto P_0c05d61c;
case 0x0c05d61eu: goto P_0c05d61e;
case 0x0c05d620u: goto P_0c05d620;
case 0x0c05d622u: goto P_0c05d622;
case 0x0c05d624u: goto P_0c05d624;
case 0x0c05d626u: goto P_0c05d626;
case 0x0c05d628u: goto P_0c05d628;
case 0x0c05d62au: goto P_0c05d62a;
case 0x0c05d62cu: goto P_0c05d62c;
case 0x0c05d62eu: goto P_0c05d62e;
case 0x0c05d630u: goto P_0c05d630;
case 0x0c05d632u: goto P_0c05d632;
case 0x0c05d634u: goto P_0c05d634;
case 0x0c05d636u: goto P_0c05d636;
case 0x0c05d638u: goto P_0c05d638;
case 0x0c05d63au: goto P_0c05d63a;
case 0x0c05d63cu: goto P_0c05d63c;
case 0x0c05d63eu: goto P_0c05d63e;
case 0x0c05d640u: goto P_0c05d640;
case 0x0c05d642u: goto P_0c05d642;
case 0x0c05d644u: goto P_0c05d644;
case 0x0c05d646u: goto P_0c05d646;
case 0x0c05d648u: goto P_0c05d648;
case 0x0c05d64au: goto P_0c05d64a;
case 0x0c05d64cu: goto P_0c05d64c;
case 0x0c05d8e0u: goto P_0c05d8e0;
case 0x0c05d8e2u: goto P_0c05d8e2;
case 0x0c05d8e4u: goto P_0c05d8e4;
case 0x0c05d8e6u: goto P_0c05d8e6;
case 0x0c05d8e8u: goto P_0c05d8e8;
case 0x0c05d8eau: goto P_0c05d8ea;
case 0x0c05d8ecu: goto P_0c05d8ec;
case 0x0c05d8eeu: goto P_0c05d8ee;
case 0x0c05d8f0u: goto P_0c05d8f0;
case 0x0c05d8f2u: goto P_0c05d8f2;
case 0x0c05d8f4u: goto P_0c05d8f4;
case 0x0c05d8f6u: goto P_0c05d8f6;
case 0x0c05d8f8u: goto P_0c05d8f8;
case 0x0c05d8fau: goto P_0c05d8fa;
case 0x0c05d8fcu: goto P_0c05d8fc;
case 0x0c05d8feu: goto P_0c05d8fe;
case 0x0c05d900u: goto P_0c05d900;
case 0x0c05d902u: goto P_0c05d902;
case 0x0c05d904u: goto P_0c05d904;
case 0x0c05d906u: goto P_0c05d906;
case 0x0c05d908u: goto P_0c05d908;
case 0x0c05d90au: goto P_0c05d90a;
case 0x0c05d90cu: goto P_0c05d90c;
case 0x0c05d90eu: goto P_0c05d90e;
case 0x0c05d910u: goto P_0c05d910;
case 0x0c05d912u: goto P_0c05d912;
case 0x0c05d914u: goto P_0c05d914;
case 0x0c05d916u: goto P_0c05d916;
case 0x0c05d918u: goto P_0c05d918;
case 0x0c05d91au: goto P_0c05d91a;
case 0x0c05d91cu: goto P_0c05d91c;
case 0x0c05d91eu: goto P_0c05d91e;
case 0x0c05d920u: goto P_0c05d920;
case 0x0c05d922u: goto P_0c05d922;
case 0x0c05d924u: goto P_0c05d924;
case 0x0c05d926u: goto P_0c05d926;
case 0x0c05d928u: goto P_0c05d928;
case 0x0c05d92au: goto P_0c05d92a;
case 0x0c05d92cu: goto P_0c05d92c;
case 0x0c05d92eu: goto P_0c05d92e;
case 0x0c05d930u: goto P_0c05d930;
case 0x0c05d932u: goto P_0c05d932;
case 0x0c05d934u: goto P_0c05d934;
case 0x0c05d936u: goto P_0c05d936;
case 0x0c05d938u: goto P_0c05d938;
case 0x0c05d93au: goto P_0c05d93a;
case 0x0c05d93cu: goto P_0c05d93c;
case 0x0c05d93eu: goto P_0c05d93e;
case 0x0c05d940u: goto P_0c05d940;
case 0x0c05d942u: goto P_0c05d942;
case 0x0c05d94cu: goto P_0c05d94c;
case 0x0c05d94eu: goto P_0c05d94e;
case 0x0c05d950u: goto P_0c05d950;
case 0x0c05d952u: goto P_0c05d952;
case 0x0c05d954u: goto P_0c05d954;
case 0x0c05d956u: goto P_0c05d956;
case 0x0c05d958u: goto P_0c05d958;
case 0x0c05d95au: goto P_0c05d95a;
case 0x0c05d95cu: goto P_0c05d95c;
case 0x0c05d95eu: goto P_0c05d95e;
case 0x0c05d960u: goto P_0c05d960;
case 0x0c05d962u: goto P_0c05d962;
case 0x0c05d964u: goto P_0c05d964;
case 0x0c05d966u: goto P_0c05d966;
case 0x0c05d968u: goto P_0c05d968;
case 0x0c05d96au: goto P_0c05d96a;
case 0x0c05d96cu: goto P_0c05d96c;
case 0x0c05d96eu: goto P_0c05d96e;
case 0x0c05d970u: goto P_0c05d970;
case 0x0c05d972u: goto P_0c05d972;
case 0x0c05d974u: goto P_0c05d974;
case 0x0c05d976u: goto P_0c05d976;
case 0x0c05d978u: goto P_0c05d978;
case 0x0c05d97au: goto P_0c05d97a;
case 0x0c05d97cu: goto P_0c05d97c;
case 0x0c05d97eu: goto P_0c05d97e;
case 0x0c05d980u: goto P_0c05d980;
case 0x0c05d982u: goto P_0c05d982;
case 0x0c05d984u: goto P_0c05d984;
case 0x0c05d986u: goto P_0c05d986;
case 0x0c05d988u: goto P_0c05d988;
case 0x0c05d98au: goto P_0c05d98a;
case 0x0c05d98cu: goto P_0c05d98c;
case 0x0c05d98eu: goto P_0c05d98e;
case 0x0c05d990u: goto P_0c05d990;
case 0x0c05d992u: goto P_0c05d992;
case 0x0c05d994u: goto P_0c05d994;
case 0x0c05d996u: goto P_0c05d996;
case 0x0c05d998u: goto P_0c05d998;
case 0x0c05d99au: goto P_0c05d99a;
case 0x0c05d99cu: goto P_0c05d99c;
case 0x0c05d99eu: goto P_0c05d99e;
case 0x0c05d9a0u: goto P_0c05d9a0;
case 0x0c05d9a2u: goto P_0c05d9a2;
case 0x0c05d9a4u: goto P_0c05d9a4;
case 0x0c05d9a6u: goto P_0c05d9a6;
case 0x0c05d9a8u: goto P_0c05d9a8;
case 0x0c05d9aau: goto P_0c05d9aa;
case 0x0c05d9acu: goto P_0c05d9ac;
case 0x0c05d9aeu: goto P_0c05d9ae;
case 0x0c05d9b0u: goto P_0c05d9b0;
case 0x0c05d9b2u: goto P_0c05d9b2;
case 0x0c05d9b4u: goto P_0c05d9b4;
case 0x0c05d9b6u: goto P_0c05d9b6;
case 0x0c05d9b8u: goto P_0c05d9b8;
case 0x0c05d9bau: goto P_0c05d9ba;
case 0x0c05d9bcu: goto P_0c05d9bc;
case 0x0c05d9beu: goto P_0c05d9be;
case 0x0c05d9c0u: goto P_0c05d9c0;
case 0x0c05d9c2u: goto P_0c05d9c2;
case 0x0c05d9c4u: goto P_0c05d9c4;
case 0x0c05d9c6u: goto P_0c05d9c6;
case 0x0c05d9c8u: goto P_0c05d9c8;
case 0x0c05d9cau: goto P_0c05d9ca;
case 0x0c05d9ccu: goto P_0c05d9cc;
case 0x0c05d9ceu: goto P_0c05d9ce;
case 0x0c05d9d0u: goto P_0c05d9d0;
case 0x0c05d9d2u: goto P_0c05d9d2;
case 0x0c05d9d4u: goto P_0c05d9d4;
case 0x0c05d9d6u: goto P_0c05d9d6;
case 0x0c05d9d8u: goto P_0c05d9d8;
case 0x0c05d9dau: goto P_0c05d9da;
case 0x0c05d9dcu: goto P_0c05d9dc;
case 0x0c05d9deu: goto P_0c05d9de;
case 0x0c05d9e0u: goto P_0c05d9e0;
case 0x0c05d9e2u: goto P_0c05d9e2;
case 0x0c05d9e4u: goto P_0c05d9e4;
case 0x0c05d9e6u: goto P_0c05d9e6;
case 0x0c05d9e8u: goto P_0c05d9e8;
case 0x0c05d9eau: goto P_0c05d9ea;
case 0x0c05d9ecu: goto P_0c05d9ec;
case 0x0c05d9eeu: goto P_0c05d9ee;
case 0x0c05d9f0u: goto P_0c05d9f0;
case 0x0c05d9f2u: goto P_0c05d9f2;
case 0x0c05d9f4u: goto P_0c05d9f4;
case 0x0c05d9f6u: goto P_0c05d9f6;
case 0x0c05d9f8u: goto P_0c05d9f8;
case 0x0c05d9fau: goto P_0c05d9fa;
case 0x0c05d9fcu: goto P_0c05d9fc;
case 0x0c05d9feu: goto P_0c05d9fe;
case 0x0c05da00u: goto P_0c05da00;
case 0x0c05da02u: goto P_0c05da02;
case 0x0c05da04u: goto P_0c05da04;
case 0x0c05da06u: goto P_0c05da06;
case 0x0c05da08u: goto P_0c05da08;
case 0x0c05da0au: goto P_0c05da0a;
case 0x0c05da0cu: goto P_0c05da0c;
case 0x0c05da0eu: goto P_0c05da0e;
case 0x0c05da10u: goto P_0c05da10;
case 0x0c05da12u: goto P_0c05da12;
case 0x0c05da14u: goto P_0c05da14;
case 0x0c05da16u: goto P_0c05da16;
case 0x0c05da18u: goto P_0c05da18;
case 0x0c05da1au: goto P_0c05da1a;
case 0x0c05da1cu: goto P_0c05da1c;
case 0x0c05da1eu: goto P_0c05da1e;
case 0x0c05da20u: goto P_0c05da20;
case 0x0c05da22u: goto P_0c05da22;
case 0x0c05da24u: goto P_0c05da24;
case 0x0c05da26u: goto P_0c05da26;
case 0x0c05da28u: goto P_0c05da28;
case 0x0c05da2au: goto P_0c05da2a;
case 0x0c05da2cu: goto P_0c05da2c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05d5a8: /* original 4f22, guest PC 0x0c05d5a8 */
if(!s->budget--) { s->failed_pc=0x0c05d5a8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05d5aa;
P_0c05d5aa: /* original 7fe4, guest PC 0x0c05d5aa */
if(!s->budget--) { s->failed_pc=0x0c05d5aau; return 0; }
r[15]+=0xffffffe4u;
goto P_0c05d5ac;
P_0c05d5ac: /* original d234, guest PC 0x0c05d5ac */
if(!s->budget--) { s->failed_pc=0x0c05d5acu; return 0; }
r[2]=read(ram,0x0c05d680u,4);
goto P_0c05d5ae;
P_0c05d5ae: /* original 65f3, guest PC 0x0c05d5ae */
if(!s->budget--) { s->failed_pc=0x0c05d5aeu; return 0; }
r[5]=r[15];
goto P_0c05d5b0;
P_0c05d5b0: /* original d328, guest PC 0x0c05d5b0 */
if(!s->budget--) { s->failed_pc=0x0c05d5b0u; return 0; }
r[3]=read(ram,0x0c05d654u,4);
goto P_0c05d5b2;
P_0c05d5b2: /* original 61f3, guest PC 0x0c05d5b2 */
if(!s->budget--) { s->failed_pc=0x0c05d5b2u; return 0; }
r[1]=r[15];
goto P_0c05d5b4;
P_0c05d5b4: /* original 750c, guest PC 0x0c05d5b4 */
if(!s->budget--) { s->failed_pc=0x0c05d5b4u; return 0; }
r[5]+=0x0000000cu;
goto P_0c05d5b6;
P_0c05d5b6: /* original 710c, guest PC 0x0c05d5b6 */
if(!s->budget--) { s->failed_pc=0x0c05d5b6u; return 0; }
r[1]+=0x0000000cu;
goto P_0c05d5b8;
P_0c05d5b8: /* original 430b, guest PC 0x0c05d5b8 */
if(!s->budget--) { s->failed_pc=0x0c05d5b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c05d5bcu;
r[0]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d5bcu) { target=s->pc; goto dispatch; }
goto P_0c05d5bc;
P_0c05d5ba: /* original e010, guest PC 0x0c05d5ba */
if(!s->budget--) { s->failed_pc=0x0c05d5bau; return 0; }
r[0]=0x00000010u;
goto P_0c05d5bc;
P_0c05d5bc: /* original e603, guest PC 0x0c05d5bc */
if(!s->budget--) { s->failed_pc=0x0c05d5bcu; return 0; }
r[6]=0x00000003u;
goto P_0c05d5be;
P_0c05d5be: /* original 6143, guest PC 0x0c05d5be */
if(!s->budget--) { s->failed_pc=0x0c05d5beu; return 0; }
r[1]=r[4];
goto P_0c05d5c0;
P_0c05d5c0: /* original 4129, guest PC 0x0c05d5c0 */
if(!s->budget--) { s->failed_pc=0x0c05d5c0u; return 0; }
r[1]>>=16;
goto P_0c05d5c2;
P_0c05d5c2: /* original 4101, guest PC 0x0c05d5c2 */
if(!s->budget--) { s->failed_pc=0x0c05d5c2u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05d5c4;
P_0c05d5c4: /* original 2169, guest PC 0x0c05d5c4 */
if(!s->budget--) { s->failed_pc=0x0c05d5c4u; return 0; }
r[1]&=r[6];
goto P_0c05d5c6;
P_0c05d5c6: /* original 6743, guest PC 0x0c05d5c6 */
if(!s->budget--) { s->failed_pc=0x0c05d5c6u; return 0; }
r[7]=r[4];
goto P_0c05d5c8;
P_0c05d5c8: /* original 1f11, guest PC 0x0c05d5c8 */
if(!s->budget--) { s->failed_pc=0x0c05d5c8u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c05d5ca;
P_0c05d5ca: /* original 6343, guest PC 0x0c05d5ca */
if(!s->budget--) { s->failed_pc=0x0c05d5cau; return 0; }
r[3]=r[4];
goto P_0c05d5cc;
P_0c05d5cc: /* original 4729, guest PC 0x0c05d5cc */
if(!s->budget--) { s->failed_pc=0x0c05d5ccu; return 0; }
r[7]>>=16;
goto P_0c05d5ce;
P_0c05d5ce: /* original 4709, guest PC 0x0c05d5ce */
if(!s->budget--) { s->failed_pc=0x0c05d5ceu; return 0; }
r[7]>>=2;
goto P_0c05d5d0;
P_0c05d5d0: /* original 4701, guest PC 0x0c05d5d0 */
if(!s->budget--) { s->failed_pc=0x0c05d5d0u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]>>=1;
goto P_0c05d5d2;
P_0c05d5d2: /* original 2769, guest PC 0x0c05d5d2 */
if(!s->budget--) { s->failed_pc=0x0c05d5d2u; return 0; }
r[7]&=r[6];
goto P_0c05d5d4;
P_0c05d5d4: /* original e0eb, guest PC 0x0c05d5d4 */
if(!s->budget--) { s->failed_pc=0x0c05d5d4u; return 0; }
r[0]=0xffffffebu;
goto P_0c05d5d6;
P_0c05d5d6: /* original 430d, guest PC 0x0c05d5d6 */
if(!s->budget--) { s->failed_pc=0x0c05d5d6u; return 0; }
r[3]=(r[0]&0x80000000u)?((r[0]&31u)?r[3]>>((-r[0])&31u):0):r[3]<<(r[0]&31u);
goto P_0c05d5d8;
P_0c05d5d8: /* original 2369, guest PC 0x0c05d5d8 */
if(!s->budget--) { s->failed_pc=0x0c05d5d8u; return 0; }
r[3]&=r[6];
goto P_0c05d5da;
P_0c05d5da: /* original 6243, guest PC 0x0c05d5da */
if(!s->budget--) { s->failed_pc=0x0c05d5dau; return 0; }
r[2]=r[4];
goto P_0c05d5dc;
P_0c05d5dc: /* original 2f32, guest PC 0x0c05d5dc */
if(!s->budget--) { s->failed_pc=0x0c05d5dcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05d5de;
P_0c05d5de: /* original e0e9, guest PC 0x0c05d5de */
if(!s->budget--) { s->failed_pc=0x0c05d5deu; return 0; }
r[0]=0xffffffe9u;
goto P_0c05d5e0;
P_0c05d5e0: /* original 420d, guest PC 0x0c05d5e0 */
if(!s->budget--) { s->failed_pc=0x0c05d5e0u; return 0; }
r[2]=(r[0]&0x80000000u)?((r[0]&31u)?r[2]>>((-r[0])&31u):0):r[2]<<(r[0]&31u);
goto P_0c05d5e2;
P_0c05d5e2: /* original 2269, guest PC 0x0c05d5e2 */
if(!s->budget--) { s->failed_pc=0x0c05d5e2u; return 0; }
r[2]&=r[6];
goto P_0c05d5e4;
P_0c05d5e4: /* original d027, guest PC 0x0c05d5e4 */
if(!s->budget--) { s->failed_pc=0x0c05d5e4u; return 0; }
r[0]=read(ram,0x0c05d684u,4);
goto P_0c05d5e6;
P_0c05d5e6: /* original 4429, guest PC 0x0c05d5e6 */
if(!s->budget--) { s->failed_pc=0x0c05d5e6u; return 0; }
r[4]>>=16;
goto P_0c05d5e8;
P_0c05d5e8: /* original 1f22, guest PC 0x0c05d5e8 */
if(!s->budget--) { s->failed_pc=0x0c05d5e8u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c05d5ea;
P_0c05d5ea: /* original 4419, guest PC 0x0c05d5ea */
if(!s->budget--) { s->failed_pc=0x0c05d5eau; return 0; }
r[4]>>=8;
goto P_0c05d5ec;
P_0c05d5ec: /* original 4401, guest PC 0x0c05d5ec */
if(!s->budget--) { s->failed_pc=0x0c05d5ecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05d5ee;
P_0c05d5ee: /* original 2649, guest PC 0x0c05d5ee */
if(!s->budget--) { s->failed_pc=0x0c05d5eeu; return 0; }
r[6]&=r[4];
goto P_0c05d5f0;
P_0c05d5f0: /* original 6102, guest PC 0x0c05d5f0 */
if(!s->budget--) { s->failed_pc=0x0c05d5f0u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05d5f2;
P_0c05d5f2: /* original d325, guest PC 0x0c05d5f2 */
if(!s->budget--) { s->failed_pc=0x0c05d5f2u; return 0; }
r[3]=read(ram,0x0c05d688u,4);
goto P_0c05d5f4;
P_0c05d5f4: /* original 6032, guest PC 0x0c05d5f4 */
if(!s->budget--) { s->failed_pc=0x0c05d5f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05d5f6;
P_0c05d5f6: /* original 0017, guest PC 0x0c05d5f6 */
if(!s->budget--) { s->failed_pc=0x0c05d5f6u; return 0; }
r[19]=r[0]*r[1];
goto P_0c05d5f8;
P_0c05d5f8: /* original d124, guest PC 0x0c05d5f8 */
if(!s->budget--) { s->failed_pc=0x0c05d5f8u; return 0; }
r[1]=read(ram,0x0c05d68cu,4);
goto P_0c05d5fa;
P_0c05d5fa: /* original 6012, guest PC 0x0c05d5fa */
if(!s->budget--) { s->failed_pc=0x0c05d5fau; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d5fc;
P_0c05d5fc: /* original c820, guest PC 0x0c05d5fc */
if(!s->budget--) { s->failed_pc=0x0c05d5fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05d5fe;
P_0c05d5fe: /* original 8d07, guest PC 0x0c05d5fe */
if(!s->budget--) { s->failed_pc=0x0c05d5feu; return 0; }
cond=r[17]&1u;
r[4]=r[19];
if(cond) { goto P_0c05d610; }
goto P_0c05d602;
P_0c05d600: /* original 041a, guest PC 0x0c05d600 */
if(!s->budget--) { s->failed_pc=0x0c05d600u; return 0; }
r[4]=r[19];
goto P_0c05d602;
P_0c05d602: /* original d023, guest PC 0x0c05d602 */
if(!s->budget--) { s->failed_pc=0x0c05d602u; return 0; }
r[0]=read(ram,0x0c05d690u,4);
goto P_0c05d604;
P_0c05d604: /* original 6202, guest PC 0x0c05d604 */
if(!s->budget--) { s->failed_pc=0x0c05d604u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05d606;
P_0c05d606: /* original 2228, guest PC 0x0c05d606 */
if(!s->budget--) { s->failed_pc=0x0c05d606u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c05d608;
P_0c05d608: /* original 8901, guest PC 0x0c05d608 */
if(!s->budget--) { s->failed_pc=0x0c05d608u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d60e; }
goto P_0c05d60a;
P_0c05d60a: /* original a001, guest PC 0x0c05d60a */
if(!s->budget--) { s->failed_pc=0x0c05d60au; return 0; }
r[4]<<=2;
goto P_0c05d610;
P_0c05d60c: /* original 4408, guest PC 0x0c05d60c */
if(!s->budget--) { s->failed_pc=0x0c05d60cu; return 0; }
r[4]<<=2;
goto P_0c05d60e;
P_0c05d60e: /* original 344c, guest PC 0x0c05d60e */
if(!s->budget--) { s->failed_pc=0x0c05d60eu; return 0; }
r[4]+=r[4];
goto P_0c05d610;
P_0c05d610: /* original 50f1, guest PC 0x0c05d610 */
if(!s->budget--) { s->failed_pc=0x0c05d610u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05d612;
P_0c05d612: /* original 4008, guest PC 0x0c05d612 */
if(!s->budget--) { s->failed_pc=0x0c05d612u; return 0; }
r[0]<<=2;
goto P_0c05d614;
P_0c05d614: /* original 035e, guest PC 0x0c05d614 */
if(!s->budget--) { s->failed_pc=0x0c05d614u; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c05d616;
P_0c05d616: /* original 6073, guest PC 0x0c05d616 */
if(!s->budget--) { s->failed_pc=0x0c05d616u; return 0; }
r[0]=r[7];
goto P_0c05d618;
P_0c05d618: /* original 0009, guest PC 0x0c05d618 */
if(!s->budget--) { s->failed_pc=0x0c05d618u; return 0; }
goto P_0c05d61a;
P_0c05d61a: /* original 4008, guest PC 0x0c05d61a */
if(!s->budget--) { s->failed_pc=0x0c05d61au; return 0; }
r[0]<<=2;
goto P_0c05d61c;
P_0c05d61c: /* original 025e, guest PC 0x0c05d61c */
if(!s->budget--) { s->failed_pc=0x0c05d61cu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d61e;
P_0c05d61e: /* original 332c, guest PC 0x0c05d61e */
if(!s->budget--) { s->failed_pc=0x0c05d61eu; return 0; }
r[3]+=r[2];
goto P_0c05d620;
P_0c05d620: /* original 60f2, guest PC 0x0c05d620 */
if(!s->budget--) { s->failed_pc=0x0c05d620u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05d622;
P_0c05d622: /* original 4008, guest PC 0x0c05d622 */
if(!s->budget--) { s->failed_pc=0x0c05d622u; return 0; }
r[0]<<=2;
goto P_0c05d624;
P_0c05d624: /* original 025e, guest PC 0x0c05d624 */
if(!s->budget--) { s->failed_pc=0x0c05d624u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d626;
P_0c05d626: /* original 332c, guest PC 0x0c05d626 */
if(!s->budget--) { s->failed_pc=0x0c05d626u; return 0; }
r[3]+=r[2];
goto P_0c05d628;
P_0c05d628: /* original 50f2, guest PC 0x0c05d628 */
if(!s->budget--) { s->failed_pc=0x0c05d628u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c05d62a;
P_0c05d62a: /* original 4008, guest PC 0x0c05d62a */
if(!s->budget--) { s->failed_pc=0x0c05d62au; return 0; }
r[0]<<=2;
goto P_0c05d62c;
P_0c05d62c: /* original 025e, guest PC 0x0c05d62c */
if(!s->budget--) { s->failed_pc=0x0c05d62cu; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d62e;
P_0c05d62e: /* original 332c, guest PC 0x0c05d62e */
if(!s->budget--) { s->failed_pc=0x0c05d62eu; return 0; }
r[3]+=r[2];
goto P_0c05d630;
P_0c05d630: /* original 6063, guest PC 0x0c05d630 */
if(!s->budget--) { s->failed_pc=0x0c05d630u; return 0; }
r[0]=r[6];
goto P_0c05d632;
P_0c05d632: /* original 0009, guest PC 0x0c05d632 */
if(!s->budget--) { s->failed_pc=0x0c05d632u; return 0; }
goto P_0c05d634;
P_0c05d634: /* original d117, guest PC 0x0c05d634 */
if(!s->budget--) { s->failed_pc=0x0c05d634u; return 0; }
r[1]=read(ram,0x0c05d694u,4);
goto P_0c05d636;
P_0c05d636: /* original 4008, guest PC 0x0c05d636 */
if(!s->budget--) { s->failed_pc=0x0c05d636u; return 0; }
r[0]<<=2;
goto P_0c05d638;
P_0c05d638: /* original 025e, guest PC 0x0c05d638 */
if(!s->budget--) { s->failed_pc=0x0c05d638u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c05d63a;
P_0c05d63a: /* original 332c, guest PC 0x0c05d63a */
if(!s->budget--) { s->failed_pc=0x0c05d63au; return 0; }
r[3]+=r[2];
goto P_0c05d63c;
P_0c05d63c: /* original 4308, guest PC 0x0c05d63c */
if(!s->budget--) { s->failed_pc=0x0c05d63cu; return 0; }
r[3]<<=2;
goto P_0c05d63e;
P_0c05d63e: /* original 7318, guest PC 0x0c05d63e */
if(!s->budget--) { s->failed_pc=0x0c05d63eu; return 0; }
r[3]+=0x00000018u;
goto P_0c05d640;
P_0c05d640: /* original 0347, guest PC 0x0c05d640 */
if(!s->budget--) { s->failed_pc=0x0c05d640u; return 0; }
r[19]=r[3]*r[4];
goto P_0c05d642;
P_0c05d642: /* original 031a, guest PC 0x0c05d642 */
if(!s->budget--) { s->failed_pc=0x0c05d642u; return 0; }
r[3]=r[19];
goto P_0c05d644;
P_0c05d644: /* original 2132, guest PC 0x0c05d644 */
if(!s->budget--) { s->failed_pc=0x0c05d644u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05d646;
P_0c05d646: /* original 7f1c, guest PC 0x0c05d646 */
if(!s->budget--) { s->failed_pc=0x0c05d646u; return 0; }
r[15]+=0x0000001cu;
goto P_0c05d648;
P_0c05d648: /* original 4f26, guest PC 0x0c05d648 */
if(!s->budget--) { s->failed_pc=0x0c05d648u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05d64a;
P_0c05d64a: /* original 000b, guest PC 0x0c05d64a */
if(!s->budget--) { s->failed_pc=0x0c05d64au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05d64c: /* original 0009, guest PC 0x0c05d64c */
if(!s->budget--) { s->failed_pc=0x0c05d64cu; return 0; }
if(!vf3_matrix_family(0x0c05d64eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05d64eu; return 0; } return 1;
P_0c05d8e0: /* original 2fe6, guest PC 0x0c05d8e0 */
if(!s->budget--) { s->failed_pc=0x0c05d8e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8e2;
P_0c05d8e2: /* original 2fd6, guest PC 0x0c05d8e2 */
if(!s->budget--) { s->failed_pc=0x0c05d8e2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8e4;
P_0c05d8e4: /* original 2fc6, guest PC 0x0c05d8e4 */
if(!s->budget--) { s->failed_pc=0x0c05d8e4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8e6;
P_0c05d8e6: /* original 2fb6, guest PC 0x0c05d8e6 */
if(!s->budget--) { s->failed_pc=0x0c05d8e6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8e8;
P_0c05d8e8: /* original 2fa6, guest PC 0x0c05d8e8 */
if(!s->budget--) { s->failed_pc=0x0c05d8e8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8ea;
P_0c05d8ea: /* original 2f96, guest PC 0x0c05d8ea */
if(!s->budget--) { s->failed_pc=0x0c05d8eau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8ec;
P_0c05d8ec: /* original 2f86, guest PC 0x0c05d8ec */
if(!s->budget--) { s->failed_pc=0x0c05d8ecu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d8ee;
P_0c05d8ee: /* original 4f22, guest PC 0x0c05d8ee */
if(!s->budget--) { s->failed_pc=0x0c05d8eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05d8f0;
P_0c05d8f0: /* original de14, guest PC 0x0c05d8f0 */
if(!s->budget--) { s->failed_pc=0x0c05d8f0u; return 0; }
r[14]=read(ram,0x0c05d944u,4);
goto P_0c05d8f2;
P_0c05d8f2: /* original 7ffc, guest PC 0x0c05d8f2 */
if(!s->budget--) { s->failed_pc=0x0c05d8f2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c05d8f4;
P_0c05d8f4: /* original 2f42, guest PC 0x0c05d8f4 */
if(!s->budget--) { s->failed_pc=0x0c05d8f4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05d8f6;
P_0c05d8f6: /* original 6043, guest PC 0x0c05d8f6 */
if(!s->budget--) { s->failed_pc=0x0c05d8f6u; return 0; }
r[0]=r[4];
goto P_0c05d8f8;
P_0c05d8f8: /* original 0009, guest PC 0x0c05d8f8 */
if(!s->budget--) { s->failed_pc=0x0c05d8f8u; return 0; }
goto P_0c05d8fa;
P_0c05d8fa: /* original 8801, guest PC 0x0c05d8fa */
if(!s->budget--) { s->failed_pc=0x0c05d8fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d8fc;
P_0c05d8fc: /* original 8f0e, guest PC 0x0c05d8fc */
if(!s->budget--) { s->failed_pc=0x0c05d8fcu; return 0; }
cond=r[17]&1u;
r[10]=0x00000002u;
if(!cond) { goto P_0c05d91c; }
goto P_0c05d900;
P_0c05d8fe: /* original ea02, guest PC 0x0c05d8fe */
if(!s->budget--) { s->failed_pc=0x0c05d8feu; return 0; }
r[10]=0x00000002u;
goto P_0c05d900;
P_0c05d900: /* original 52e4, guest PC 0x0c05d900 */
if(!s->budget--) { s->failed_pc=0x0c05d900u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c05d902;
P_0c05d902: /* original 2f26, guest PC 0x0c05d902 */
if(!s->budget--) { s->failed_pc=0x0c05d902u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d904;
P_0c05d904: /* original 57e3, guest PC 0x0c05d904 */
if(!s->budget--) { s->failed_pc=0x0c05d904u; return 0; }
r[7]=read(ram,r[14]+12,4);
goto P_0c05d906;
P_0c05d906: /* original 56e2, guest PC 0x0c05d906 */
if(!s->budget--) { s->failed_pc=0x0c05d906u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c05d908;
P_0c05d908: /* original 55e1, guest PC 0x0c05d908 */
if(!s->budget--) { s->failed_pc=0x0c05d908u; return 0; }
r[5]=read(ram,r[14]+4,4);
goto P_0c05d90a;
P_0c05d90a: /* original d30f, guest PC 0x0c05d90a */
if(!s->budget--) { s->failed_pc=0x0c05d90au; return 0; }
r[3]=read(ram,0x0c05d948u,4);
goto P_0c05d90c;
P_0c05d90c: /* original 430b, guest PC 0x0c05d90c */
if(!s->budget--) { s->failed_pc=0x0c05d90cu; return 0; }
target=r[3];
r[16]=code_base|0x0c05d910u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d910u) { target=s->pc; goto dispatch; }
goto P_0c05d910;
P_0c05d90e: /* original 64e2, guest PC 0x0c05d90e */
if(!s->budget--) { s->failed_pc=0x0c05d90eu; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c05d910;
P_0c05d910: /* original 6d03, guest PC 0x0c05d910 */
if(!s->budget--) { s->failed_pc=0x0c05d910u; return 0; }
r[13]=r[0];
goto P_0c05d912;
P_0c05d912: /* original 2dd8, guest PC 0x0c05d912 */
if(!s->budget--) { s->failed_pc=0x0c05d912u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05d914;
P_0c05d914: /* original 8d02, guest PC 0x0c05d914 */
if(!s->budget--) { s->failed_pc=0x0c05d914u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c05d91c; }
goto P_0c05d918;
P_0c05d916: /* original 7f04, guest PC 0x0c05d916 */
if(!s->budget--) { s->failed_pc=0x0c05d916u; return 0; }
r[15]+=0x00000004u;
goto P_0c05d918;
P_0c05d918: /* original a07d, guest PC 0x0c05d918 */
if(!s->budget--) { s->failed_pc=0x0c05d918u; return 0; }
goto P_0c05da16;
P_0c05d91a: /* original 0009, guest PC 0x0c05d91a */
if(!s->budget--) { s->failed_pc=0x0c05d91au; return 0; }
goto P_0c05d91c;
P_0c05d91c: /* original 60f2, guest PC 0x0c05d91c */
if(!s->budget--) { s->failed_pc=0x0c05d91cu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05d91e;
P_0c05d91e: /* original 8802, guest PC 0x0c05d91e */
if(!s->budget--) { s->failed_pc=0x0c05d91eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05d920;
P_0c05d920: /* original 8b06, guest PC 0x0c05d920 */
if(!s->budget--) { s->failed_pc=0x0c05d920u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05d930; }
goto P_0c05d922;
P_0c05d922: /* original e058, guest PC 0x0c05d922 */
if(!s->budget--) { s->failed_pc=0x0c05d922u; return 0; }
r[0]=0x00000058u;
goto P_0c05d924;
P_0c05d924: /* original 05ee, guest PC 0x0c05d924 */
if(!s->budget--) { s->failed_pc=0x0c05d924u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c05d926;
P_0c05d926: /* original b813, guest PC 0x0c05d926 */
if(!s->budget--) { s->failed_pc=0x0c05d926u; return 0; }
target=code_base|0x0c05c950u; r[16]=code_base|0x0c05d92au;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d92au) { target=s->pc; goto dispatch; }
goto P_0c05d92a;
P_0c05d928: /* original 64e2, guest PC 0x0c05d928 */
if(!s->budget--) { s->failed_pc=0x0c05d928u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c05d92a;
P_0c05d92a: /* original 6d03, guest PC 0x0c05d92a */
if(!s->budget--) { s->failed_pc=0x0c05d92au; return 0; }
r[13]=r[0];
goto P_0c05d92c;
P_0c05d92c: /* original 2dd8, guest PC 0x0c05d92c */
if(!s->budget--) { s->failed_pc=0x0c05d92cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05d92e;
P_0c05d92e: /* original 8b72, guest PC 0x0c05d92e */
if(!s->budget--) { s->failed_pc=0x0c05d92eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05da16; }
goto P_0c05d930;
P_0c05d930: /* original 64e3, guest PC 0x0c05d930 */
if(!s->budget--) { s->failed_pc=0x0c05d930u; return 0; }
r[4]=r[14];
goto P_0c05d932;
P_0c05d932: /* original 741c, guest PC 0x0c05d932 */
if(!s->budget--) { s->failed_pc=0x0c05d932u; return 0; }
r[4]+=0x0000001cu;
goto P_0c05d934;
P_0c05d934: /* original 5244, guest PC 0x0c05d934 */
if(!s->budget--) { s->failed_pc=0x0c05d934u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c05d936;
P_0c05d936: /* original 6342, guest PC 0x0c05d936 */
if(!s->budget--) { s->failed_pc=0x0c05d936u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c05d938;
P_0c05d938: /* original 3320, guest PC 0x0c05d938 */
if(!s->budget--) { s->failed_pc=0x0c05d938u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c05d93a;
P_0c05d93a: /* original 8f01, guest PC 0x0c05d93a */
if(!s->budget--) { s->failed_pc=0x0c05d93au; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c05d940; }
goto P_0c05d93e;
P_0c05d93c: /* original e900, guest PC 0x0c05d93c */
if(!s->budget--) { s->failed_pc=0x0c05d93cu; return 0; }
r[9]=0x00000000u;
goto P_0c05d93e;
P_0c05d93e: /* original ea01, guest PC 0x0c05d93e */
if(!s->budget--) { s->failed_pc=0x0c05d93eu; return 0; }
r[10]=0x00000001u;
goto P_0c05d940;
P_0c05d940: /* original a015, guest PC 0x0c05d940 */
if(!s->budget--) { s->failed_pc=0x0c05d940u; return 0; }
r[12]=r[9];
goto P_0c05d96e;
P_0c05d942: /* original 6c93, guest PC 0x0c05d942 */
if(!s->budget--) { s->failed_pc=0x0c05d942u; return 0; }
r[12]=r[9];
if(!vf3_matrix_family(0x0c05d944u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05d944u; return 0; } return 1;
P_0c05d94c: /* original d841, guest PC 0x0c05d94c */
if(!s->budget--) { s->failed_pc=0x0c05d94cu; return 0; }
r[8]=read(ram,0x0c05da54u,4);
goto P_0c05d94e;
P_0c05d94e: /* original 6de3, guest PC 0x0c05d94e */
if(!s->budget--) { s->failed_pc=0x0c05d94eu; return 0; }
r[13]=r[14];
goto P_0c05d950;
P_0c05d950: /* original 7d1c, guest PC 0x0c05d950 */
if(!s->budget--) { s->failed_pc=0x0c05d950u; return 0; }
r[13]+=0x0000001cu;
goto P_0c05d952;
P_0c05d952: /* original 3dcc, guest PC 0x0c05d952 */
if(!s->budget--) { s->failed_pc=0x0c05d952u; return 0; }
r[13]+=r[12];
goto P_0c05d954;
P_0c05d954: /* original 52d3, guest PC 0x0c05d954 */
if(!s->budget--) { s->failed_pc=0x0c05d954u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c05d956;
P_0c05d956: /* original 67b3, guest PC 0x0c05d956 */
if(!s->budget--) { s->failed_pc=0x0c05d956u; return 0; }
r[7]=r[11];
goto P_0c05d958;
P_0c05d958: /* original 2f26, guest PC 0x0c05d958 */
if(!s->budget--) { s->failed_pc=0x0c05d958u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05d95a;
P_0c05d95a: /* original 56d2, guest PC 0x0c05d95a */
if(!s->budget--) { s->failed_pc=0x0c05d95au; return 0; }
r[6]=read(ram,r[13]+8,4);
goto P_0c05d95c;
P_0c05d95c: /* original 55d1, guest PC 0x0c05d95c */
if(!s->budget--) { s->failed_pc=0x0c05d95cu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c05d95e;
P_0c05d95e: /* original 480b, guest PC 0x0c05d95e */
if(!s->budget--) { s->failed_pc=0x0c05d95eu; return 0; }
target=r[8];
r[16]=code_base|0x0c05d962u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d962u) { target=s->pc; goto dispatch; }
goto P_0c05d962;
P_0c05d960: /* original 64d2, guest PC 0x0c05d960 */
if(!s->budget--) { s->failed_pc=0x0c05d960u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c05d962;
P_0c05d962: /* original 6d03, guest PC 0x0c05d962 */
if(!s->budget--) { s->failed_pc=0x0c05d962u; return 0; }
r[13]=r[0];
goto P_0c05d964;
P_0c05d964: /* original 2dd8, guest PC 0x0c05d964 */
if(!s->budget--) { s->failed_pc=0x0c05d964u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05d966;
P_0c05d966: /* original 8f56, guest PC 0x0c05d966 */
if(!s->budget--) { s->failed_pc=0x0c05d966u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(!cond) { goto P_0c05da16; }
goto P_0c05d96a;
P_0c05d968: /* original 7f04, guest PC 0x0c05d968 */
if(!s->budget--) { s->failed_pc=0x0c05d968u; return 0; }
r[15]+=0x00000004u;
goto P_0c05d96a;
P_0c05d96a: /* original 7901, guest PC 0x0c05d96a */
if(!s->budget--) { s->failed_pc=0x0c05d96au; return 0; }
r[9]+=0x00000001u;
goto P_0c05d96c;
P_0c05d96c: /* original 7c10, guest PC 0x0c05d96c */
if(!s->budget--) { s->failed_pc=0x0c05d96cu; return 0; }
r[12]+=0x00000010u;
goto P_0c05d96e;
P_0c05d96e: /* original 39a2, guest PC 0x0c05d96e */
if(!s->budget--) { s->failed_pc=0x0c05d96eu; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[10])!=0);
goto P_0c05d970;
P_0c05d970: /* original 8fec, guest PC 0x0c05d970 */
if(!s->budget--) { s->failed_pc=0x0c05d970u; return 0; }
cond=r[17]&1u;
r[11]=read(ram,r[14]+24,4);
if(!cond) { goto P_0c05d94c; }
goto P_0c05d974;
P_0c05d972: /* original 5be6, guest PC 0x0c05d972 */
if(!s->budget--) { s->failed_pc=0x0c05d972u; return 0; }
r[11]=read(ram,r[14]+24,4);
goto P_0c05d974;
P_0c05d974: /* original d338, guest PC 0x0c05d974 */
if(!s->budget--) { s->failed_pc=0x0c05d974u; return 0; }
r[3]=read(ram,0x0c05da58u,4);
goto P_0c05d976;
P_0c05d976: /* original e044, guest PC 0x0c05d976 */
if(!s->budget--) { s->failed_pc=0x0c05d976u; return 0; }
r[0]=0x00000044u;
goto P_0c05d978;
P_0c05d978: /* original 07ee, guest PC 0x0c05d978 */
if(!s->budget--) { s->failed_pc=0x0c05d978u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c05d97a;
P_0c05d97a: /* original 66b3, guest PC 0x0c05d97a */
if(!s->budget--) { s->failed_pc=0x0c05d97au; return 0; }
r[6]=r[11];
goto P_0c05d97c;
P_0c05d97c: /* original e040, guest PC 0x0c05d97c */
if(!s->budget--) { s->failed_pc=0x0c05d97cu; return 0; }
r[0]=0x00000040u;
goto P_0c05d97e;
P_0c05d97e: /* original 05ee, guest PC 0x0c05d97e */
if(!s->budget--) { s->failed_pc=0x0c05d97eu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c05d980;
P_0c05d980: /* original 430b, guest PC 0x0c05d980 */
if(!s->budget--) { s->failed_pc=0x0c05d980u; return 0; }
target=r[3];
r[16]=code_base|0x0c05d984u;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d984u) { target=s->pc; goto dispatch; }
goto P_0c05d984;
P_0c05d982: /* original 54ef, guest PC 0x0c05d982 */
if(!s->budget--) { s->failed_pc=0x0c05d982u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c05d984;
P_0c05d984: /* original 6d03, guest PC 0x0c05d984 */
if(!s->budget--) { s->failed_pc=0x0c05d984u; return 0; }
r[13]=r[0];
goto P_0c05d986;
P_0c05d986: /* original 2dd8, guest PC 0x0c05d986 */
if(!s->budget--) { s->failed_pc=0x0c05d986u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c05d988;
P_0c05d988: /* original 8b45, guest PC 0x0c05d988 */
if(!s->budget--) { s->failed_pc=0x0c05d988u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05da16; }
goto P_0c05d98a;
P_0c05d98a: /* original d234, guest PC 0x0c05d98a */
if(!s->budget--) { s->failed_pc=0x0c05d98au; return 0; }
r[2]=read(ram,0x0c05da5cu,4);
goto P_0c05d98c;
P_0c05d98c: /* original 6022, guest PC 0x0c05d98c */
if(!s->budget--) { s->failed_pc=0x0c05d98cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05d98e;
P_0c05d98e: /* original 8801, guest PC 0x0c05d98e */
if(!s->budget--) { s->failed_pc=0x0c05d98eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d990;
P_0c05d990: /* original 8903, guest PC 0x0c05d990 */
if(!s->budget--) { s->failed_pc=0x0c05d990u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05d99a; }
goto P_0c05d992;
P_0c05d992: /* original d133, guest PC 0x0c05d992 */
if(!s->budget--) { s->failed_pc=0x0c05d992u; return 0; }
r[1]=read(ram,0x0c05da60u,4);
goto P_0c05d994;
P_0c05d994: /* original 6012, guest PC 0x0c05d994 */
if(!s->budget--) { s->failed_pc=0x0c05d994u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05d996;
P_0c05d996: /* original 8801, guest PC 0x0c05d996 */
if(!s->budget--) { s->failed_pc=0x0c05d996u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05d998;
P_0c05d998: /* original 8b3d, guest PC 0x0c05d998 */
if(!s->budget--) { s->failed_pc=0x0c05d998u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05da16; }
goto P_0c05d99a;
P_0c05d99a: /* original d332, guest PC 0x0c05d99a */
if(!s->budget--) { s->failed_pc=0x0c05d99au; return 0; }
r[3]=read(ram,0x0c05da64u,4);
goto P_0c05d99c;
P_0c05d99c: /* original 6232, guest PC 0x0c05d99c */
if(!s->budget--) { s->failed_pc=0x0c05d99cu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05d99e;
P_0c05d99e: /* original d032, guest PC 0x0c05d99e */
if(!s->budget--) { s->failed_pc=0x0c05d99eu; return 0; }
r[0]=read(ram,0x0c05da68u,4);
goto P_0c05d9a0;
P_0c05d9a0: /* original 2022, guest PC 0x0c05d9a0 */
if(!s->budget--) { s->failed_pc=0x0c05d9a0u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c05d9a2;
P_0c05d9a2: /* original 70e8, guest PC 0x0c05d9a2 */
if(!s->budget--) { s->failed_pc=0x0c05d9a2u; return 0; }
r[0]+=0xffffffe8u;
goto P_0c05d9a4;
P_0c05d9a4: /* original 6233, guest PC 0x0c05d9a4 */
if(!s->budget--) { s->failed_pc=0x0c05d9a4u; return 0; }
r[2]=r[3];
goto P_0c05d9a6;
P_0c05d9a6: /* original e300, guest PC 0x0c05d9a6 */
if(!s->budget--) { s->failed_pc=0x0c05d9a6u; return 0; }
r[3]=0x00000000u;
goto P_0c05d9a8;
P_0c05d9a8: /* original 6122, guest PC 0x0c05d9a8 */
if(!s->budget--) { s->failed_pc=0x0c05d9a8u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05d9aa;
P_0c05d9aa: /* original 4108, guest PC 0x0c05d9aa */
if(!s->budget--) { s->failed_pc=0x0c05d9aau; return 0; }
r[1]<<=2;
goto P_0c05d9ac;
P_0c05d9ac: /* original 0136, guest PC 0x0c05d9ac */
if(!s->budget--) { s->failed_pc=0x0c05d9acu; return 0; }
write(ram,r[1]+r[0],r[3],4);
goto P_0c05d9ae;
P_0c05d9ae: /* original e401, guest PC 0x0c05d9ae */
if(!s->budget--) { s->failed_pc=0x0c05d9aeu; return 0; }
r[4]=0x00000001u;
goto P_0c05d9b0;
P_0c05d9b0: /* original d12e, guest PC 0x0c05d9b0 */
if(!s->budget--) { s->failed_pc=0x0c05d9b0u; return 0; }
r[1]=read(ram,0x0c05da6cu,4);
goto P_0c05d9b2;
P_0c05d9b2: /* original 2142, guest PC 0x0c05d9b2 */
if(!s->budget--) { s->failed_pc=0x0c05d9b2u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05d9b4;
P_0c05d9b4: /* original 6322, guest PC 0x0c05d9b4 */
if(!s->budget--) { s->failed_pc=0x0c05d9b4u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05d9b6;
P_0c05d9b6: /* original 2439, guest PC 0x0c05d9b6 */
if(!s->budget--) { s->failed_pc=0x0c05d9b6u; return 0; }
r[4]&=r[3];
goto P_0c05d9b8;
P_0c05d9b8: /* original 2f42, guest PC 0x0c05d9b8 */
if(!s->budget--) { s->failed_pc=0x0c05d9b8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05d9ba;
P_0c05d9ba: /* original e501, guest PC 0x0c05d9ba */
if(!s->budget--) { s->failed_pc=0x0c05d9bau; return 0; }
r[5]=0x00000001u;
goto P_0c05d9bc;
P_0c05d9bc: /* original de2c, guest PC 0x0c05d9bc */
if(!s->budget--) { s->failed_pc=0x0c05d9bcu; return 0; }
r[14]=read(ram,0x0c05da70u,4);
goto P_0c05d9be;
P_0c05d9be: /* original 4e0b, guest PC 0x0c05d9be */
if(!s->budget--) { s->failed_pc=0x0c05d9beu; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9c2u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9c2u) { target=s->pc; goto dispatch; }
goto P_0c05d9c2;
P_0c05d9c0: /* original e408, guest PC 0x0c05d9c0 */
if(!s->budget--) { s->failed_pc=0x0c05d9c0u; return 0; }
r[4]=0x00000008u;
goto P_0c05d9c2;
P_0c05d9c2: /* original e500, guest PC 0x0c05d9c2 */
if(!s->budget--) { s->failed_pc=0x0c05d9c2u; return 0; }
r[5]=0x00000000u;
goto P_0c05d9c4;
P_0c05d9c4: /* original 4e0b, guest PC 0x0c05d9c4 */
if(!s->budget--) { s->failed_pc=0x0c05d9c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9c8u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9c8u) { target=s->pc; goto dispatch; }
goto P_0c05d9c8;
P_0c05d9c6: /* original e408, guest PC 0x0c05d9c6 */
if(!s->budget--) { s->failed_pc=0x0c05d9c6u; return 0; }
r[4]=0x00000008u;
goto P_0c05d9c8;
P_0c05d9c8: /* original 6cf2, guest PC 0x0c05d9c8 */
if(!s->budget--) { s->failed_pc=0x0c05d9c8u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c05d9ca;
P_0c05d9ca: /* original 4c08, guest PC 0x0c05d9ca */
if(!s->budget--) { s->failed_pc=0x0c05d9cau; return 0; }
r[12]<<=2;
goto P_0c05d9cc;
P_0c05d9cc: /* original d029, guest PC 0x0c05d9cc */
if(!s->budget--) { s->failed_pc=0x0c05d9ccu; return 0; }
r[0]=read(ram,0x0c05da74u,4);
goto P_0c05d9ce;
P_0c05d9ce: /* original 4c08, guest PC 0x0c05d9ce */
if(!s->budget--) { s->failed_pc=0x0c05d9ceu; return 0; }
r[12]<<=2;
goto P_0c05d9d0;
P_0c05d9d0: /* original 943a, guest PC 0x0c05d9d0 */
if(!s->budget--) { s->failed_pc=0x0c05d9d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da48u,2);
goto P_0c05d9d2;
P_0c05d9d2: /* original 4c00, guest PC 0x0c05d9d2 */
if(!s->budget--) { s->failed_pc=0x0c05d9d2u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c05d9d4;
P_0c05d9d4: /* original 4e0b, guest PC 0x0c05d9d4 */
if(!s->budget--) { s->failed_pc=0x0c05d9d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9d8u;
r[5]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9d8u) { target=s->pc; goto dispatch; }
goto P_0c05d9d8;
P_0c05d9d6: /* original 05ce, guest PC 0x0c05d9d6 */
if(!s->budget--) { s->failed_pc=0x0c05d9d6u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c05d9d8;
P_0c05d9d8: /* original d027, guest PC 0x0c05d9d8 */
if(!s->budget--) { s->failed_pc=0x0c05d9d8u; return 0; }
r[0]=read(ram,0x0c05da78u,4);
goto P_0c05d9da;
P_0c05d9da: /* original 9436, guest PC 0x0c05d9da */
if(!s->budget--) { s->failed_pc=0x0c05d9dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da4au,2);
goto P_0c05d9dc;
P_0c05d9dc: /* original 4e0b, guest PC 0x0c05d9dc */
if(!s->budget--) { s->failed_pc=0x0c05d9dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9e0u;
r[5]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9e0u) { target=s->pc; goto dispatch; }
goto P_0c05d9e0;
P_0c05d9de: /* original 05ce, guest PC 0x0c05d9de */
if(!s->budget--) { s->failed_pc=0x0c05d9deu; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c05d9e0;
P_0c05d9e0: /* original d026, guest PC 0x0c05d9e0 */
if(!s->budget--) { s->failed_pc=0x0c05d9e0u; return 0; }
r[0]=read(ram,0x0c05da7cu,4);
goto P_0c05d9e2;
P_0c05d9e2: /* original 9433, guest PC 0x0c05d9e2 */
if(!s->budget--) { s->failed_pc=0x0c05d9e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da4cu,2);
goto P_0c05d9e4;
P_0c05d9e4: /* original 4e0b, guest PC 0x0c05d9e4 */
if(!s->budget--) { s->failed_pc=0x0c05d9e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9e8u;
r[5]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9e8u) { target=s->pc; goto dispatch; }
goto P_0c05d9e8;
P_0c05d9e6: /* original 05ce, guest PC 0x0c05d9e6 */
if(!s->budget--) { s->failed_pc=0x0c05d9e6u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c05d9e8;
P_0c05d9e8: /* original d025, guest PC 0x0c05d9e8 */
if(!s->budget--) { s->failed_pc=0x0c05d9e8u; return 0; }
r[0]=read(ram,0x0c05da80u,4);
goto P_0c05d9ea;
P_0c05d9ea: /* original 9430, guest PC 0x0c05d9ea */
if(!s->budget--) { s->failed_pc=0x0c05d9eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da4eu,2);
goto P_0c05d9ec;
P_0c05d9ec: /* original 4e0b, guest PC 0x0c05d9ec */
if(!s->budget--) { s->failed_pc=0x0c05d9ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9f0u;
r[5]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9f0u) { target=s->pc; goto dispatch; }
goto P_0c05d9f0;
P_0c05d9ee: /* original 05ce, guest PC 0x0c05d9ee */
if(!s->budget--) { s->failed_pc=0x0c05d9eeu; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c05d9f0;
P_0c05d9f0: /* original d024, guest PC 0x0c05d9f0 */
if(!s->budget--) { s->failed_pc=0x0c05d9f0u; return 0; }
r[0]=read(ram,0x0c05da84u,4);
goto P_0c05d9f2;
P_0c05d9f2: /* original 942d, guest PC 0x0c05d9f2 */
if(!s->budget--) { s->failed_pc=0x0c05d9f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da50u,2);
goto P_0c05d9f4;
P_0c05d9f4: /* original 4e0b, guest PC 0x0c05d9f4 */
if(!s->budget--) { s->failed_pc=0x0c05d9f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c05d9f8u;
r[5]=read(ram,r[12]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05d9f8u) { target=s->pc; goto dispatch; }
goto P_0c05d9f8;
P_0c05d9f6: /* original 05ce, guest PC 0x0c05d9f6 */
if(!s->budget--) { s->failed_pc=0x0c05d9f6u; return 0; }
r[5]=read(ram,r[12]+r[0],4);
goto P_0c05d9f8;
P_0c05d9f8: /* original d523, guest PC 0x0c05d9f8 */
if(!s->budget--) { s->failed_pc=0x0c05d9f8u; return 0; }
r[5]=read(ram,0x0c05da88u,4);
goto P_0c05d9fa;
P_0c05d9fa: /* original 942a, guest PC 0x0c05d9fa */
if(!s->budget--) { s->failed_pc=0x0c05d9fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da52u,2);
goto P_0c05d9fc;
P_0c05d9fc: /* original 4e0b, guest PC 0x0c05d9fc */
if(!s->budget--) { s->failed_pc=0x0c05d9fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c05da00u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05da00u) { target=s->pc; goto dispatch; }
goto P_0c05da00;
P_0c05d9fe: /* original 0009, guest PC 0x0c05d9fe */
if(!s->budget--) { s->failed_pc=0x0c05d9feu; return 0; }
goto P_0c05da00;
P_0c05da00: /* original 9427, guest PC 0x0c05da00 */
if(!s->budget--) { s->failed_pc=0x0c05da00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05da52u,2);
goto P_0c05da02;
P_0c05da02: /* original d322, guest PC 0x0c05da02 */
if(!s->budget--) { s->failed_pc=0x0c05da02u; return 0; }
r[3]=read(ram,0x0c05da8cu,4);
goto P_0c05da04;
P_0c05da04: /* original 430b, guest PC 0x0c05da04 */
if(!s->budget--) { s->failed_pc=0x0c05da04u; return 0; }
target=r[3];
r[16]=code_base|0x0c05da08u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05da08u) { target=s->pc; goto dispatch; }
goto P_0c05da08;
P_0c05da06: /* original 0009, guest PC 0x0c05da06 */
if(!s->budget--) { s->failed_pc=0x0c05da06u; return 0; }
goto P_0c05da08;
P_0c05da08: /* original d321, guest PC 0x0c05da08 */
if(!s->budget--) { s->failed_pc=0x0c05da08u; return 0; }
r[3]=read(ram,0x0c05da90u,4);
goto P_0c05da0a;
P_0c05da0a: /* original e200, guest PC 0x0c05da0a */
if(!s->budget--) { s->failed_pc=0x0c05da0au; return 0; }
r[2]=0x00000000u;
goto P_0c05da0c;
P_0c05da0c: /* original 2322, guest PC 0x0c05da0c */
if(!s->budget--) { s->failed_pc=0x0c05da0cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05da0e;
P_0c05da0e: /* original d021, guest PC 0x0c05da0e */
if(!s->budget--) { s->failed_pc=0x0c05da0eu; return 0; }
r[0]=read(ram,0x0c05da94u,4);
goto P_0c05da10;
P_0c05da10: /* original 6102, guest PC 0x0c05da10 */
if(!s->budget--) { s->failed_pc=0x0c05da10u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05da12;
P_0c05da12: /* original d221, guest PC 0x0c05da12 */
if(!s->budget--) { s->failed_pc=0x0c05da12u; return 0; }
r[2]=read(ram,0x0c05da98u,4);
goto P_0c05da14;
P_0c05da14: /* original 2212, guest PC 0x0c05da14 */
if(!s->budget--) { s->failed_pc=0x0c05da14u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c05da16;
P_0c05da16: /* original 60d3, guest PC 0x0c05da16 */
if(!s->budget--) { s->failed_pc=0x0c05da16u; return 0; }
r[0]=r[13];
goto P_0c05da18;
P_0c05da18: /* original 0009, guest PC 0x0c05da18 */
if(!s->budget--) { s->failed_pc=0x0c05da18u; return 0; }
goto P_0c05da1a;
P_0c05da1a: /* original 7f04, guest PC 0x0c05da1a */
if(!s->budget--) { s->failed_pc=0x0c05da1au; return 0; }
r[15]+=0x00000004u;
goto P_0c05da1c;
P_0c05da1c: /* original 4f26, guest PC 0x0c05da1c */
if(!s->budget--) { s->failed_pc=0x0c05da1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05da1e;
P_0c05da1e: /* original 68f6, guest PC 0x0c05da1e */
if(!s->budget--) { s->failed_pc=0x0c05da1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05da20;
P_0c05da20: /* original 69f6, guest PC 0x0c05da20 */
if(!s->budget--) { s->failed_pc=0x0c05da20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05da22;
P_0c05da22: /* original 6af6, guest PC 0x0c05da22 */
if(!s->budget--) { s->failed_pc=0x0c05da22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05da24;
P_0c05da24: /* original 6bf6, guest PC 0x0c05da24 */
if(!s->budget--) { s->failed_pc=0x0c05da24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05da26;
P_0c05da26: /* original 6cf6, guest PC 0x0c05da26 */
if(!s->budget--) { s->failed_pc=0x0c05da26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05da28;
P_0c05da28: /* original 6df6, guest PC 0x0c05da28 */
if(!s->budget--) { s->failed_pc=0x0c05da28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05da2a;
P_0c05da2a: /* original 000b, guest PC 0x0c05da2a */
if(!s->budget--) { s->failed_pc=0x0c05da2au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05da2c: /* original 6ef6, guest PC 0x0c05da2c */
if(!s->budget--) { s->failed_pc=0x0c05da2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c05da2eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
