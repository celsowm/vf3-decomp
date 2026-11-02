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
int vf3_away_batch6_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c054848u: goto P_0c054848;
case 0x0c05484au: goto P_0c05484a;
case 0x0c05484cu: goto P_0c05484c;
case 0x0c05484eu: goto P_0c05484e;
case 0x0c054850u: goto P_0c054850;
case 0x0c054852u: goto P_0c054852;
case 0x0c054854u: goto P_0c054854;
case 0x0c054856u: goto P_0c054856;
case 0x0c054858u: goto P_0c054858;
case 0x0c05485au: goto P_0c05485a;
case 0x0c05485cu: goto P_0c05485c;
case 0x0c05485eu: goto P_0c05485e;
case 0x0c054860u: goto P_0c054860;
case 0x0c054862u: goto P_0c054862;
case 0x0c054864u: goto P_0c054864;
case 0x0c054866u: goto P_0c054866;
case 0x0c054868u: goto P_0c054868;
case 0x0c05486au: goto P_0c05486a;
case 0x0c05486cu: goto P_0c05486c;
case 0x0c05486eu: goto P_0c05486e;
case 0x0c054870u: goto P_0c054870;
case 0x0c054872u: goto P_0c054872;
case 0x0c054874u: goto P_0c054874;
case 0x0c054876u: goto P_0c054876;
case 0x0c054878u: goto P_0c054878;
case 0x0c05487au: goto P_0c05487a;
case 0x0c05487cu: goto P_0c05487c;
case 0x0c05487eu: goto P_0c05487e;
case 0x0c054880u: goto P_0c054880;
case 0x0c054882u: goto P_0c054882;
case 0x0c054884u: goto P_0c054884;
case 0x0c054886u: goto P_0c054886;
case 0x0c054888u: goto P_0c054888;
case 0x0c05488au: goto P_0c05488a;
case 0x0c05488cu: goto P_0c05488c;
case 0x0c05488eu: goto P_0c05488e;
case 0x0c054890u: goto P_0c054890;
case 0x0c054892u: goto P_0c054892;
case 0x0c054894u: goto P_0c054894;
case 0x0c054898u: goto P_0c054898;
case 0x0c05489au: goto P_0c05489a;
case 0x0c05489cu: goto P_0c05489c;
case 0x0c05489eu: goto P_0c05489e;
case 0x0c0548a0u: goto P_0c0548a0;
case 0x0c0548a2u: goto P_0c0548a2;
case 0x0c0548a4u: goto P_0c0548a4;
case 0x0c0548a6u: goto P_0c0548a6;
case 0x0c0548a8u: goto P_0c0548a8;
case 0x0c0548aau: goto P_0c0548aa;
case 0x0c0548acu: goto P_0c0548ac;
case 0x0c0548aeu: goto P_0c0548ae;
case 0x0c0548b0u: goto P_0c0548b0;
case 0x0c0548b2u: goto P_0c0548b2;
case 0x0c0548b4u: goto P_0c0548b4;
case 0x0c0548b6u: goto P_0c0548b6;
case 0x0c0548b8u: goto P_0c0548b8;
case 0x0c0548bau: goto P_0c0548ba;
case 0x0c0548bcu: goto P_0c0548bc;
case 0x0c0548beu: goto P_0c0548be;
case 0x0c0548c0u: goto P_0c0548c0;
case 0x0c0548c2u: goto P_0c0548c2;
case 0x0c0548c4u: goto P_0c0548c4;
case 0x0c0548c6u: goto P_0c0548c6;
case 0x0c0548c8u: goto P_0c0548c8;
case 0x0c0548cau: goto P_0c0548ca;
case 0x0c0548ccu: goto P_0c0548cc;
case 0x0c0548ceu: goto P_0c0548ce;
case 0x0c0548d0u: goto P_0c0548d0;
case 0x0c0548d2u: goto P_0c0548d2;
case 0x0c0548d4u: goto P_0c0548d4;
case 0x0c0548d6u: goto P_0c0548d6;
case 0x0c0548d8u: goto P_0c0548d8;
case 0x0c0548dau: goto P_0c0548da;
case 0x0c0548dcu: goto P_0c0548dc;
case 0x0c0548deu: goto P_0c0548de;
case 0x0c0548e0u: goto P_0c0548e0;
case 0x0c0548e2u: goto P_0c0548e2;
case 0x0c0548e4u: goto P_0c0548e4;
case 0x0c0548e6u: goto P_0c0548e6;
case 0x0c0548e8u: goto P_0c0548e8;
case 0x0c0548eau: goto P_0c0548ea;
case 0x0c0548ecu: goto P_0c0548ec;
case 0x0c0548eeu: goto P_0c0548ee;
case 0x0c0548f0u: goto P_0c0548f0;
case 0x0c0548f2u: goto P_0c0548f2;
case 0x0c0548f4u: goto P_0c0548f4;
case 0x0c0548f6u: goto P_0c0548f6;
case 0x0c054908u: goto P_0c054908;
case 0x0c05490au: goto P_0c05490a;
case 0x0c05490cu: goto P_0c05490c;
case 0x0c05490eu: goto P_0c05490e;
case 0x0c054910u: goto P_0c054910;
case 0x0c054912u: goto P_0c054912;
case 0x0c054914u: goto P_0c054914;
case 0x0c054916u: goto P_0c054916;
case 0x0c054918u: goto P_0c054918;
case 0x0c05491au: goto P_0c05491a;
case 0x0c05491cu: goto P_0c05491c;
case 0x0c05491eu: goto P_0c05491e;
case 0x0c054920u: goto P_0c054920;
case 0x0c054922u: goto P_0c054922;
case 0x0c054924u: goto P_0c054924;
case 0x0c054926u: goto P_0c054926;
case 0x0c054928u: goto P_0c054928;
case 0x0c05492cu: goto P_0c05492c;
case 0x0c05492eu: goto P_0c05492e;
case 0x0c054930u: goto P_0c054930;
case 0x0c054932u: goto P_0c054932;
case 0x0c054934u: goto P_0c054934;
case 0x0c054936u: goto P_0c054936;
case 0x0c054938u: goto P_0c054938;
case 0x0c05493au: goto P_0c05493a;
case 0x0c05493cu: goto P_0c05493c;
case 0x0c05493eu: goto P_0c05493e;
case 0x0c054940u: goto P_0c054940;
case 0x0c054942u: goto P_0c054942;
case 0x0c054944u: goto P_0c054944;
case 0x0c054946u: goto P_0c054946;
case 0x0c054948u: goto P_0c054948;
case 0x0c05494au: goto P_0c05494a;
case 0x0c05494cu: goto P_0c05494c;
case 0x0c05494eu: goto P_0c05494e;
case 0x0c054950u: goto P_0c054950;
case 0x0c054952u: goto P_0c054952;
case 0x0c054954u: goto P_0c054954;
case 0x0c054956u: goto P_0c054956;
case 0x0c054958u: goto P_0c054958;
case 0x0c05495au: goto P_0c05495a;
case 0x0c05495cu: goto P_0c05495c;
case 0x0c05495eu: goto P_0c05495e;
case 0x0c054960u: goto P_0c054960;
case 0x0c054962u: goto P_0c054962;
case 0x0c054964u: goto P_0c054964;
case 0x0c054966u: goto P_0c054966;
case 0x0c054968u: goto P_0c054968;
case 0x0c05496au: goto P_0c05496a;
case 0x0c05496cu: goto P_0c05496c;
case 0x0c05496eu: goto P_0c05496e;
case 0x0c054970u: goto P_0c054970;
case 0x0c054972u: goto P_0c054972;
case 0x0c054974u: goto P_0c054974;
case 0x0c054976u: goto P_0c054976;
case 0x0c054978u: goto P_0c054978;
case 0x0c05497au: goto P_0c05497a;
case 0x0c05497cu: goto P_0c05497c;
case 0x0c05497eu: goto P_0c05497e;
case 0x0c054980u: goto P_0c054980;
case 0x0c054982u: goto P_0c054982;
case 0x0c054984u: goto P_0c054984;
case 0x0c054986u: goto P_0c054986;
case 0x0c054988u: goto P_0c054988;
case 0x0c05498au: goto P_0c05498a;
case 0x0c05498cu: goto P_0c05498c;
case 0x0c05498eu: goto P_0c05498e;
case 0x0c054990u: goto P_0c054990;
case 0x0c054992u: goto P_0c054992;
case 0x0c054994u: goto P_0c054994;
case 0x0c054996u: goto P_0c054996;
case 0x0c054998u: goto P_0c054998;
case 0x0c05499au: goto P_0c05499a;
case 0x0c05499cu: goto P_0c05499c;
case 0x0c05499eu: goto P_0c05499e;
case 0x0c0549a0u: goto P_0c0549a0;
case 0x0c0549a2u: goto P_0c0549a2;
case 0x0c0549a4u: goto P_0c0549a4;
case 0x0c0549a6u: goto P_0c0549a6;
case 0x0c0549a8u: goto P_0c0549a8;
case 0x0c0549aau: goto P_0c0549aa;
case 0x0c0549acu: goto P_0c0549ac;
case 0x0c0549aeu: goto P_0c0549ae;
case 0x0c0549b0u: goto P_0c0549b0;
case 0x0c0549b2u: goto P_0c0549b2;
case 0x0c0549b4u: goto P_0c0549b4;
case 0x0c0549b6u: goto P_0c0549b6;
case 0x0c0549b8u: goto P_0c0549b8;
case 0x0c0549bau: goto P_0c0549ba;
case 0x0c0549bcu: goto P_0c0549bc;
case 0x0c0549beu: goto P_0c0549be;
case 0x0c0549c0u: goto P_0c0549c0;
case 0x0c0549c2u: goto P_0c0549c2;
case 0x0c0549c4u: goto P_0c0549c4;
case 0x0c0549c6u: goto P_0c0549c6;
case 0x0c0549c8u: goto P_0c0549c8;
case 0x0c0549cau: goto P_0c0549ca;
case 0x0c0549ccu: goto P_0c0549cc;
case 0x0c0549ceu: goto P_0c0549ce;
case 0x0c0549d0u: goto P_0c0549d0;
case 0x0c0549d2u: goto P_0c0549d2;
case 0x0c0549d4u: goto P_0c0549d4;
case 0x0c0549d6u: goto P_0c0549d6;
case 0x0c0549d8u: goto P_0c0549d8;
case 0x0c0549dau: goto P_0c0549da;
case 0x0c0549dcu: goto P_0c0549dc;
case 0x0c0549deu: goto P_0c0549de;
case 0x0c0549e0u: goto P_0c0549e0;
case 0x0c0549e2u: goto P_0c0549e2;
case 0x0c0549e4u: goto P_0c0549e4;
case 0x0c0549e6u: goto P_0c0549e6;
case 0x0c0549e8u: goto P_0c0549e8;
case 0x0c0549eau: goto P_0c0549ea;
case 0x0c0549ecu: goto P_0c0549ec;
case 0x0c0549eeu: goto P_0c0549ee;
case 0x0c0549f0u: goto P_0c0549f0;
case 0x0c0549f2u: goto P_0c0549f2;
case 0x0c0549f4u: goto P_0c0549f4;
case 0x0c0549f6u: goto P_0c0549f6;
case 0x0c0549f8u: goto P_0c0549f8;
case 0x0c0549fau: goto P_0c0549fa;
case 0x0c0549fcu: goto P_0c0549fc;
case 0x0c0549feu: goto P_0c0549fe;
case 0x0c054a00u: goto P_0c054a00;
case 0x0c054a02u: goto P_0c054a02;
case 0x0c054a04u: goto P_0c054a04;
case 0x0c054a06u: goto P_0c054a06;
case 0x0c054a08u: goto P_0c054a08;
case 0x0c054a0au: goto P_0c054a0a;
case 0x0c054a0cu: goto P_0c054a0c;
case 0x0c054a0eu: goto P_0c054a0e;
case 0x0c054a10u: goto P_0c054a10;
case 0x0c054a12u: goto P_0c054a12;
case 0x0c054a14u: goto P_0c054a14;
case 0x0c054a16u: goto P_0c054a16;
case 0x0c054a18u: goto P_0c054a18;
case 0x0c054a1au: goto P_0c054a1a;
case 0x0c054a1cu: goto P_0c054a1c;
case 0x0c054a1eu: goto P_0c054a1e;
case 0x0c054a20u: goto P_0c054a20;
case 0x0c054a22u: goto P_0c054a22;
case 0x0c054a24u: goto P_0c054a24;
case 0x0c054a26u: goto P_0c054a26;
case 0x0c054a28u: goto P_0c054a28;
case 0x0c054a2au: goto P_0c054a2a;
case 0x0c054a2cu: goto P_0c054a2c;
case 0x0c054a2eu: goto P_0c054a2e;
case 0x0c054a30u: goto P_0c054a30;
case 0x0c054a32u: goto P_0c054a32;
case 0x0c054a34u: goto P_0c054a34;
case 0x0c054a36u: goto P_0c054a36;
case 0x0c054a38u: goto P_0c054a38;
case 0x0c054a3au: goto P_0c054a3a;
case 0x0c054a3cu: goto P_0c054a3c;
case 0x0c054a3eu: goto P_0c054a3e;
case 0x0c054a40u: goto P_0c054a40;
case 0x0c054a42u: goto P_0c054a42;
case 0x0c054a44u: goto P_0c054a44;
case 0x0c054a46u: goto P_0c054a46;
case 0x0c054a48u: goto P_0c054a48;
case 0x0c054a4au: goto P_0c054a4a;
case 0x0c054a4cu: goto P_0c054a4c;
case 0x0c054a4eu: goto P_0c054a4e;
case 0x0c054a50u: goto P_0c054a50;
case 0x0c054a52u: goto P_0c054a52;
case 0x0c054a54u: goto P_0c054a54;
case 0x0c054a56u: goto P_0c054a56;
case 0x0c054a58u: goto P_0c054a58;
case 0x0c054a5au: goto P_0c054a5a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c054848: /* original 2fd6, guest PC 0x0c054848 */
if(!s->budget--) { s->failed_pc=0x0c054848u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05484a;
P_0c05484a: /* original e700, guest PC 0x0c05484a */
if(!s->budget--) { s->failed_pc=0x0c05484au; return 0; }
r[7]=0x00000000u;
goto P_0c05484c;
P_0c05484c: /* original 9d23, guest PC 0x0c05484c */
if(!s->budget--) { s->failed_pc=0x0c05484cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054896u,2);
goto P_0c05484e;
P_0c05484e: /* original 7ffc, guest PC 0x0c05484e */
if(!s->budget--) { s->failed_pc=0x0c05484eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c054850;
P_0c054850: /* original 75ff, guest PC 0x0c054850 */
if(!s->budget--) { s->failed_pc=0x0c054850u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054852;
P_0c054852: /* original 6653, guest PC 0x0c054852 */
if(!s->budget--) { s->failed_pc=0x0c054852u; return 0; }
r[6]=r[5];
goto P_0c054854;
P_0c054854: /* original 364c, guest PC 0x0c054854 */
if(!s->budget--) { s->failed_pc=0x0c054854u; return 0; }
r[6]+=r[4];
goto P_0c054856;
P_0c054856: /* original 4511, guest PC 0x0c054856 */
if(!s->budget--) { s->failed_pc=0x0c054856u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c054858;
P_0c054858: /* original 2f62, guest PC 0x0c054858 */
if(!s->budget--) { s->failed_pc=0x0c054858u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c05485a;
P_0c05485a: /* original 8f11, guest PC 0x0c05485a */
if(!s->budget--) { s->failed_pc=0x0c05485au; return 0; }
cond=r[17]&1u;
r[4]=r[6];
if(!cond) { goto P_0c054880; }
goto P_0c05485e;
P_0c05485c: /* original 6463, guest PC 0x0c05485c */
if(!s->budget--) { s->failed_pc=0x0c05485cu; return 0; }
r[4]=r[6];
goto P_0c05485e;
P_0c05485e: /* original 6140, guest PC 0x0c05485e */
if(!s->budget--) { s->failed_pc=0x0c05485eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c054860;
P_0c054860: /* original 6340, guest PC 0x0c054860 */
if(!s->budget--) { s->failed_pc=0x0c054860u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c054862;
P_0c054862: /* original 611c, guest PC 0x0c054862 */
if(!s->budget--) { s->failed_pc=0x0c054862u; return 0; }
r[1]=r[1]&255u;
goto P_0c054864;
P_0c054864: /* original 21d9, guest PC 0x0c054864 */
if(!s->budget--) { s->failed_pc=0x0c054864u; return 0; }
r[1]&=r[13];
goto P_0c054866;
P_0c054866: /* original 4300, guest PC 0x0c054866 */
if(!s->budget--) { s->failed_pc=0x0c054866u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c054868;
P_0c054868: /* original 2778, guest PC 0x0c054868 */
if(!s->budget--) { s->failed_pc=0x0c054868u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c05486a;
P_0c05486a: /* original 8d03, guest PC 0x0c05486a */
if(!s->budget--) { s->failed_pc=0x0c05486au; return 0; }
cond=r[17]&1u;
write(ram,r[4],r[3],1);
if(cond) { goto P_0c054874; }
goto P_0c05486e;
P_0c05486c: /* original 2430, guest PC 0x0c05486c */
if(!s->budget--) { s->failed_pc=0x0c05486cu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c05486e;
P_0c05486e: /* original 6060, guest PC 0x0c05486e */
if(!s->budget--) { s->failed_pc=0x0c05486eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[0]=tmp;
goto P_0c054870;
P_0c054870: /* original cb01, guest PC 0x0c054870 */
if(!s->budget--) { s->failed_pc=0x0c054870u; return 0; }
r[0]|=1u;
goto P_0c054872;
P_0c054872: /* original 2600, guest PC 0x0c054872 */
if(!s->budget--) { s->failed_pc=0x0c054872u; return 0; }
write(ram,r[6],r[0],1);
goto P_0c054874;
P_0c054874: /* original 6713, guest PC 0x0c054874 */
if(!s->budget--) { s->failed_pc=0x0c054874u; return 0; }
r[7]=r[1];
goto P_0c054876;
P_0c054876: /* original 75ff, guest PC 0x0c054876 */
if(!s->budget--) { s->failed_pc=0x0c054876u; return 0; }
r[5]+=0xffffffffu;
goto P_0c054878;
P_0c054878: /* original 76ff, guest PC 0x0c054878 */
if(!s->budget--) { s->failed_pc=0x0c054878u; return 0; }
r[6]+=0xffffffffu;
goto P_0c05487a;
P_0c05487a: /* original 4511, guest PC 0x0c05487a */
if(!s->budget--) { s->failed_pc=0x0c05487au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c05487c;
P_0c05487c: /* original 8def, guest PC 0x0c05487c */
if(!s->budget--) { s->failed_pc=0x0c05487cu; return 0; }
cond=r[17]&1u;
r[4]+=0xffffffffu;
if(cond) { goto P_0c05485e; }
goto P_0c054880;
P_0c05487e: /* original 74ff, guest PC 0x0c05487e */
if(!s->budget--) { s->failed_pc=0x0c05487eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c054880;
P_0c054880: /* original 2778, guest PC 0x0c054880 */
if(!s->budget--) { s->failed_pc=0x0c054880u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c054882;
P_0c054882: /* original 8d04, guest PC 0x0c054882 */
if(!s->budget--) { s->failed_pc=0x0c054882u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05488e; }
goto P_0c054886;
P_0c054884: /* original 0009, guest PC 0x0c054884 */
if(!s->budget--) { s->failed_pc=0x0c054884u; return 0; }
goto P_0c054886;
P_0c054886: /* original e001, guest PC 0x0c054886 */
if(!s->budget--) { s->failed_pc=0x0c054886u; return 0; }
r[0]=0x00000001u;
goto P_0c054888;
P_0c054888: /* original 7f04, guest PC 0x0c054888 */
if(!s->budget--) { s->failed_pc=0x0c054888u; return 0; }
r[15]+=0x00000004u;
goto P_0c05488a;
P_0c05488a: /* original 000b, guest PC 0x0c05488a */
if(!s->budget--) { s->failed_pc=0x0c05488au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c05488c: /* original 6df6, guest PC 0x0c05488c */
if(!s->budget--) { s->failed_pc=0x0c05488cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05488e;
P_0c05488e: /* original e000, guest PC 0x0c05488e */
if(!s->budget--) { s->failed_pc=0x0c05488eu; return 0; }
r[0]=0x00000000u;
goto P_0c054890;
P_0c054890: /* original 7f04, guest PC 0x0c054890 */
if(!s->budget--) { s->failed_pc=0x0c054890u; return 0; }
r[15]+=0x00000004u;
goto P_0c054892;
P_0c054892: /* original 000b, guest PC 0x0c054892 */
if(!s->budget--) { s->failed_pc=0x0c054892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c054894: /* original 6df6, guest PC 0x0c054894 */
if(!s->budget--) { s->failed_pc=0x0c054894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
if(!vf3_matrix_family(0x0c054896u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054896u; return 0; } return 1;
P_0c054898: /* original 2fe6, guest PC 0x0c054898 */
if(!s->budget--) { s->failed_pc=0x0c054898u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05489a;
P_0c05489a: /* original 2fd6, guest PC 0x0c05489a */
if(!s->budget--) { s->failed_pc=0x0c05489au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05489c;
P_0c05489c: /* original 4f22, guest PC 0x0c05489c */
if(!s->budget--) { s->failed_pc=0x0c05489cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05489e;
P_0c05489e: /* original 6d43, guest PC 0x0c05489e */
if(!s->budget--) { s->failed_pc=0x0c05489eu; return 0; }
r[13]=r[4];
goto P_0c0548a0;
P_0c0548a0: /* original 7fe8, guest PC 0x0c0548a0 */
if(!s->budget--) { s->failed_pc=0x0c0548a0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0548a2;
P_0c0548a2: /* original 6ef3, guest PC 0x0c0548a2 */
if(!s->budget--) { s->failed_pc=0x0c0548a2u; return 0; }
r[14]=r[15];
goto P_0c0548a4;
P_0c0548a4: /* original 2f52, guest PC 0x0c0548a4 */
if(!s->budget--) { s->failed_pc=0x0c0548a4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0548a6;
P_0c0548a6: /* original 7e08, guest PC 0x0c0548a6 */
if(!s->budget--) { s->failed_pc=0x0c0548a6u; return 0; }
r[14]+=0x00000008u;
goto P_0c0548a8;
P_0c0548a8: /* original 1f71, guest PC 0x0c0548a8 */
if(!s->budget--) { s->failed_pc=0x0c0548a8u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0548aa;
P_0c0548aa: /* original 63d1, guest PC 0x0c0548aa */
if(!s->budget--) { s->failed_pc=0x0c0548aau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[3]=tmp;
goto P_0c0548ac;
P_0c0548ac: /* original 363c, guest PC 0x0c0548ac */
if(!s->budget--) { s->failed_pc=0x0c0548acu; return 0; }
r[6]+=r[3];
goto P_0c0548ae;
P_0c0548ae: /* original 2d61, guest PC 0x0c0548ae */
if(!s->budget--) { s->failed_pc=0x0c0548aeu; return 0; }
write(ram,r[13],r[6],2);
goto P_0c0548b0;
P_0c0548b0: /* original 55f1, guest PC 0x0c0548b0 */
if(!s->budget--) { s->failed_pc=0x0c0548b0u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0548b2;
P_0c0548b2: /* original 66e3, guest PC 0x0c0548b2 */
if(!s->budget--) { s->failed_pc=0x0c0548b2u; return 0; }
r[6]=r[14];
goto P_0c0548b4;
P_0c0548b4: /* original d310, guest PC 0x0c0548b4 */
if(!s->budget--) { s->failed_pc=0x0c0548b4u; return 0; }
r[3]=read(ram,0x0c0548f8u,4);
goto P_0c0548b6;
P_0c0548b6: /* original 430b, guest PC 0x0c0548b6 */
if(!s->budget--) { s->failed_pc=0x0c0548b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0548bau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0548bau) { target=s->pc; goto dispatch; }
goto P_0c0548ba;
P_0c0548b8: /* original 64f2, guest PC 0x0c0548b8 */
if(!s->budget--) { s->failed_pc=0x0c0548b8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0548ba;
P_0c0548ba: /* original 60e0, guest PC 0x0c0548ba */
if(!s->budget--) { s->failed_pc=0x0c0548bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c0548bc;
P_0c0548bc: /* original 600c, guest PC 0x0c0548bc */
if(!s->budget--) { s->failed_pc=0x0c0548bcu; return 0; }
r[0]=r[0]&255u;
goto P_0c0548be;
P_0c0548be: /* original c880, guest PC 0x0c0548be */
if(!s->budget--) { s->failed_pc=0x0c0548beu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0548c0;
P_0c0548c0: /* original 8d04, guest PC 0x0c0548c0 */
if(!s->budget--) { s->failed_pc=0x0c0548c0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0548cc; }
goto P_0c0548c4;
P_0c0548c2: /* original 0009, guest PC 0x0c0548c2 */
if(!s->budget--) { s->failed_pc=0x0c0548c2u; return 0; }
goto P_0c0548c4;
P_0c0548c4: /* original 62d1, guest PC 0x0c0548c4 */
if(!s->budget--) { s->failed_pc=0x0c0548c4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[2]=tmp;
goto P_0c0548c6;
P_0c0548c6: /* original 7201, guest PC 0x0c0548c6 */
if(!s->budget--) { s->failed_pc=0x0c0548c6u; return 0; }
r[2]+=0x00000001u;
goto P_0c0548c8;
P_0c0548c8: /* original a004, guest PC 0x0c0548c8 */
if(!s->budget--) { s->failed_pc=0x0c0548c8u; return 0; }
write(ram,r[13],r[2],2);
goto P_0c0548d4;
P_0c0548ca: /* original 2d21, guest PC 0x0c0548ca */
if(!s->budget--) { s->failed_pc=0x0c0548cau; return 0; }
write(ram,r[13],r[2],2);
goto P_0c0548cc;
P_0c0548cc: /* original d20b, guest PC 0x0c0548cc */
if(!s->budget--) { s->failed_pc=0x0c0548ccu; return 0; }
r[2]=read(ram,0x0c0548fcu,4);
goto P_0c0548ce;
P_0c0548ce: /* original e510, guest PC 0x0c0548ce */
if(!s->budget--) { s->failed_pc=0x0c0548ceu; return 0; }
r[5]=0x00000010u;
goto P_0c0548d0;
P_0c0548d0: /* original 420b, guest PC 0x0c0548d0 */
if(!s->budget--) { s->failed_pc=0x0c0548d0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0548d4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0548d4u) { target=s->pc; goto dispatch; }
goto P_0c0548d4;
P_0c0548d2: /* original 64e3, guest PC 0x0c0548d2 */
if(!s->budget--) { s->failed_pc=0x0c0548d2u; return 0; }
r[4]=r[14];
goto P_0c0548d4;
P_0c0548d4: /* original d30a, guest PC 0x0c0548d4 */
if(!s->budget--) { s->failed_pc=0x0c0548d4u; return 0; }
r[3]=read(ram,0x0c054900u,4);
goto P_0c0548d6;
P_0c0548d6: /* original e642, guest PC 0x0c0548d6 */
if(!s->budget--) { s->failed_pc=0x0c0548d6u; return 0; }
r[6]=0x00000042u;
goto P_0c0548d8;
P_0c0548d8: /* original e510, guest PC 0x0c0548d8 */
if(!s->budget--) { s->failed_pc=0x0c0548d8u; return 0; }
r[5]=0x00000010u;
goto P_0c0548da;
P_0c0548da: /* original 430b, guest PC 0x0c0548da */
if(!s->budget--) { s->failed_pc=0x0c0548dau; return 0; }
target=r[3];
r[16]=code_base|0x0c0548deu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0548deu) { target=s->pc; goto dispatch; }
goto P_0c0548de;
P_0c0548dc: /* original 64e3, guest PC 0x0c0548dc */
if(!s->budget--) { s->failed_pc=0x0c0548dcu; return 0; }
r[4]=r[14];
goto P_0c0548de;
P_0c0548de: /* original e609, guest PC 0x0c0548de */
if(!s->budget--) { s->failed_pc=0x0c0548deu; return 0; }
r[6]=0x00000009u;
goto P_0c0548e0;
P_0c0548e0: /* original d308, guest PC 0x0c0548e0 */
if(!s->budget--) { s->failed_pc=0x0c0548e0u; return 0; }
r[3]=read(ram,0x0c054904u,4);
goto P_0c0548e2;
P_0c0548e2: /* original 65e3, guest PC 0x0c0548e2 */
if(!s->budget--) { s->failed_pc=0x0c0548e2u; return 0; }
r[5]=r[14];
goto P_0c0548e4;
P_0c0548e4: /* original 84e8, guest PC 0x0c0548e4 */
if(!s->budget--) { s->failed_pc=0x0c0548e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c0548e6;
P_0c0548e6: /* original c9e0, guest PC 0x0c0548e6 */
if(!s->budget--) { s->failed_pc=0x0c0548e6u; return 0; }
r[0]&=224u;
goto P_0c0548e8;
P_0c0548e8: /* original 80e8, guest PC 0x0c0548e8 */
if(!s->budget--) { s->failed_pc=0x0c0548e8u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c0548ea;
P_0c0548ea: /* original 430b, guest PC 0x0c0548ea */
if(!s->budget--) { s->failed_pc=0x0c0548eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0548eeu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0548eeu) { target=s->pc; goto dispatch; }
goto P_0c0548ee;
P_0c0548ec: /* original 64f2, guest PC 0x0c0548ec */
if(!s->budget--) { s->failed_pc=0x0c0548ecu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0548ee;
P_0c0548ee: /* original 7f18, guest PC 0x0c0548ee */
if(!s->budget--) { s->failed_pc=0x0c0548eeu; return 0; }
r[15]+=0x00000018u;
goto P_0c0548f0;
P_0c0548f0: /* original 4f26, guest PC 0x0c0548f0 */
if(!s->budget--) { s->failed_pc=0x0c0548f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0548f2;
P_0c0548f2: /* original 6df6, guest PC 0x0c0548f2 */
if(!s->budget--) { s->failed_pc=0x0c0548f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0548f4;
P_0c0548f4: /* original 000b, guest PC 0x0c0548f4 */
if(!s->budget--) { s->failed_pc=0x0c0548f4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0548f6: /* original 6ef6, guest PC 0x0c0548f6 */
if(!s->budget--) { s->failed_pc=0x0c0548f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0548f8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0548f8u; return 0; } return 1;
P_0c054908: /* original e100, guest PC 0x0c054908 */
if(!s->budget--) { s->failed_pc=0x0c054908u; return 0; }
r[1]=0x00000000u;
goto P_0c05490a;
P_0c05490a: /* original e618, guest PC 0x0c05490a */
if(!s->budget--) { s->failed_pc=0x0c05490au; return 0; }
r[6]=0x00000018u;
goto P_0c05490c;
P_0c05490c: /* original e004, guest PC 0x0c05490c */
if(!s->budget--) { s->failed_pc=0x0c05490cu; return 0; }
r[0]=0x00000004u;
goto P_0c05490e;
P_0c05490e: /* original e700, guest PC 0x0c05490e */
if(!s->budget--) { s->failed_pc=0x0c05490eu; return 0; }
r[7]=0x00000000u;
goto P_0c054910;
P_0c054910: /* original 374c, guest PC 0x0c054910 */
if(!s->budget--) { s->failed_pc=0x0c054910u; return 0; }
r[7]+=r[4];
goto P_0c054912;
P_0c054912: /* original 636b, guest PC 0x0c054912 */
if(!s->budget--) { s->failed_pc=0x0c054912u; return 0; }
r[3]=0u-r[6];
goto P_0c054914;
P_0c054914: /* original 6252, guest PC 0x0c054914 */
if(!s->budget--) { s->failed_pc=0x0c054914u; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c054916;
P_0c054916: /* original 0009, guest PC 0x0c054916 */
if(!s->budget--) { s->failed_pc=0x0c054916u; return 0; }
goto P_0c054918;
P_0c054918: /* original 423d, guest PC 0x0c054918 */
if(!s->budget--) { s->failed_pc=0x0c054918u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c05491a;
P_0c05491a: /* original 7101, guest PC 0x0c05491a */
if(!s->budget--) { s->failed_pc=0x0c05491au; return 0; }
r[1]+=0x00000001u;
goto P_0c05491c;
P_0c05491c: /* original 2720, guest PC 0x0c05491c */
if(!s->budget--) { s->failed_pc=0x0c05491cu; return 0; }
write(ram,r[7],r[2],1);
goto P_0c05491e;
P_0c05491e: /* original 76f8, guest PC 0x0c05491e */
if(!s->budget--) { s->failed_pc=0x0c05491eu; return 0; }
r[6]+=0xfffffff8u;
goto P_0c054920;
P_0c054920: /* original 3103, guest PC 0x0c054920 */
if(!s->budget--) { s->failed_pc=0x0c054920u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[0])!=0);
goto P_0c054922;
P_0c054922: /* original 8ff6, guest PC 0x0c054922 */
if(!s->budget--) { s->failed_pc=0x0c054922u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c054912; }
goto P_0c054926;
P_0c054924: /* original 7701, guest PC 0x0c054924 */
if(!s->budget--) { s->failed_pc=0x0c054924u; return 0; }
r[7]+=0x00000001u;
goto P_0c054926;
P_0c054926: /* original 000b, guest PC 0x0c054926 */
if(!s->budget--) { s->failed_pc=0x0c054926u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c054928: /* original 0009, guest PC 0x0c054928 */
if(!s->budget--) { s->failed_pc=0x0c054928u; return 0; }
if(!vf3_matrix_family(0x0c05492au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05492au; return 0; } return 1;
P_0c05492c: /* original 2fe6, guest PC 0x0c05492c */
if(!s->budget--) { s->failed_pc=0x0c05492cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05492e;
P_0c05492e: /* original 4411, guest PC 0x0c05492e */
if(!s->budget--) { s->failed_pc=0x0c05492eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c054930;
P_0c054930: /* original 2fd6, guest PC 0x0c054930 */
if(!s->budget--) { s->failed_pc=0x0c054930u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054932;
P_0c054932: /* original 2fc6, guest PC 0x0c054932 */
if(!s->budget--) { s->failed_pc=0x0c054932u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054934;
P_0c054934: /* original 2fb6, guest PC 0x0c054934 */
if(!s->budget--) { s->failed_pc=0x0c054934u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054936;
P_0c054936: /* original 2fa6, guest PC 0x0c054936 */
if(!s->budget--) { s->failed_pc=0x0c054936u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054938;
P_0c054938: /* original 2f96, guest PC 0x0c054938 */
if(!s->budget--) { s->failed_pc=0x0c054938u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05493a;
P_0c05493a: /* original 2f86, guest PC 0x0c05493a */
if(!s->budget--) { s->failed_pc=0x0c05493au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05493c;
P_0c05493c: /* original 4f22, guest PC 0x0c05493c */
if(!s->budget--) { s->failed_pc=0x0c05493cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05493e;
P_0c05493e: /* original 7fdc, guest PC 0x0c05493e */
if(!s->budget--) { s->failed_pc=0x0c05493eu; return 0; }
r[15]+=0xffffffdcu;
goto P_0c054940;
P_0c054940: /* original 1f52, guest PC 0x0c054940 */
if(!s->budget--) { s->failed_pc=0x0c054940u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c054942;
P_0c054942: /* original 8f02, guest PC 0x0c054942 */
if(!s->budget--) { s->failed_pc=0x0c054942u; return 0; }
cond=r[17]&1u;
r[8]=r[6];
if(!cond) { goto P_0c05494a; }
goto P_0c054946;
P_0c054944: /* original 6863, guest PC 0x0c054944 */
if(!s->budget--) { s->failed_pc=0x0c054944u; return 0; }
r[8]=r[6];
goto P_0c054946;
P_0c054946: /* original a002, guest PC 0x0c054946 */
if(!s->budget--) { s->failed_pc=0x0c054946u; return 0; }
r[13]=0x00000000u;
goto P_0c05494e;
P_0c054948: /* original ed00, guest PC 0x0c054948 */
if(!s->budget--) { s->failed_pc=0x0c054948u; return 0; }
r[13]=0x00000000u;
goto P_0c05494a;
P_0c05494a: /* original ed01, guest PC 0x0c05494a */
if(!s->budget--) { s->failed_pc=0x0c05494au; return 0; }
r[13]=0x00000001u;
goto P_0c05494c;
P_0c05494c: /* original 644b, guest PC 0x0c05494c */
if(!s->budget--) { s->failed_pc=0x0c05494cu; return 0; }
r[4]=0u-r[4];
goto P_0c05494e;
P_0c05494e: /* original e51b, guest PC 0x0c05494e */
if(!s->budget--) { s->failed_pc=0x0c05494eu; return 0; }
r[5]=0x0000001bu;
goto P_0c054950;
P_0c054950: /* original d342, guest PC 0x0c054950 */
if(!s->budget--) { s->failed_pc=0x0c054950u; return 0; }
r[3]=read(ram,0x0c054a5cu,4);
goto P_0c054952;
P_0c054952: /* original 6143, guest PC 0x0c054952 */
if(!s->budget--) { s->failed_pc=0x0c054952u; return 0; }
r[1]=r[4];
goto P_0c054954;
P_0c054954: /* original 430b, guest PC 0x0c054954 */
if(!s->budget--) { s->failed_pc=0x0c054954u; return 0; }
target=r[3];
r[16]=code_base|0x0c054958u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054958u) { target=s->pc; goto dispatch; }
goto P_0c054958;
P_0c054956: /* original 6053, guest PC 0x0c054956 */
if(!s->budget--) { s->failed_pc=0x0c054956u; return 0; }
r[0]=r[5];
goto P_0c054958;
P_0c054958: /* original d241, guest PC 0x0c054958 */
if(!s->budget--) { s->failed_pc=0x0c054958u; return 0; }
r[2]=read(ram,0x0c054a60u,4);
goto P_0c05495a;
P_0c05495a: /* original 6a03, guest PC 0x0c05495a */
if(!s->budget--) { s->failed_pc=0x0c05495au; return 0; }
r[10]=r[0];
goto P_0c05495c;
P_0c05495c: /* original 6143, guest PC 0x0c05495c */
if(!s->budget--) { s->failed_pc=0x0c05495cu; return 0; }
r[1]=r[4];
goto P_0c05495e;
P_0c05495e: /* original 420b, guest PC 0x0c05495e */
if(!s->budget--) { s->failed_pc=0x0c05495eu; return 0; }
target=r[2];
r[16]=code_base|0x0c054962u;
r[0]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054962u) { target=s->pc; goto dispatch; }
goto P_0c054962;
P_0c054960: /* original 6053, guest PC 0x0c054960 */
if(!s->budget--) { s->failed_pc=0x0c054960u; return 0; }
r[0]=r[5];
goto P_0c054962;
P_0c054962: /* original 6b03, guest PC 0x0c054962 */
if(!s->budget--) { s->failed_pc=0x0c054962u; return 0; }
r[11]=r[0];
goto P_0c054964;
P_0c054964: /* original 6ef3, guest PC 0x0c054964 */
if(!s->budget--) { s->failed_pc=0x0c054964u; return 0; }
r[14]=r[15];
goto P_0c054966;
P_0c054966: /* original 60d3, guest PC 0x0c054966 */
if(!s->budget--) { s->failed_pc=0x0c054966u; return 0; }
r[0]=r[13];
goto P_0c054968;
P_0c054968: /* original 0009, guest PC 0x0c054968 */
if(!s->budget--) { s->failed_pc=0x0c054968u; return 0; }
goto P_0c05496a;
P_0c05496a: /* original 8801, guest PC 0x0c05496a */
if(!s->budget--) { s->failed_pc=0x0c05496au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05496c;
P_0c05496c: /* original 8f11, guest PC 0x0c05496c */
if(!s->budget--) { s->failed_pc=0x0c05496cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000018u;
if(!cond) { goto P_0c054992; }
goto P_0c054970;
P_0c05496e: /* original 7e18, guest PC 0x0c05496e */
if(!s->budget--) { s->failed_pc=0x0c05496eu; return 0; }
r[14]+=0x00000018u;
goto P_0c054970;
P_0c054970: /* original 2bb8, guest PC 0x0c054970 */
if(!s->budget--) { s->failed_pc=0x0c054970u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c054972;
P_0c054972: /* original 8d0e, guest PC 0x0c054972 */
if(!s->budget--) { s->failed_pc=0x0c054972u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054992; }
goto P_0c054976;
P_0c054974: /* original 0009, guest PC 0x0c054974 */
if(!s->budget--) { s->failed_pc=0x0c054974u; return 0; }
goto P_0c054976;
P_0c054976: /* original 6353, guest PC 0x0c054976 */
if(!s->budget--) { s->failed_pc=0x0c054976u; return 0; }
r[3]=r[5];
goto P_0c054978;
P_0c054978: /* original d23a, guest PC 0x0c054978 */
if(!s->budget--) { s->failed_pc=0x0c054978u; return 0; }
r[2]=read(ram,0x0c054a64u,4);
goto P_0c05497a;
P_0c05497a: /* original e608, guest PC 0x0c05497a */
if(!s->budget--) { s->failed_pc=0x0c05497au; return 0; }
r[6]=0x00000008u;
goto P_0c05497c;
P_0c05497c: /* original d53a, guest PC 0x0c05497c */
if(!s->budget--) { s->failed_pc=0x0c05497cu; return 0; }
r[5]=read(ram,0x0c054a68u,4);
goto P_0c05497e;
P_0c05497e: /* original 33b8, guest PC 0x0c05497e */
if(!s->budget--) { s->failed_pc=0x0c05497eu; return 0; }
r[3]-=r[11];
goto P_0c054980;
P_0c054980: /* original 6b33, guest PC 0x0c054980 */
if(!s->budget--) { s->failed_pc=0x0c054980u; return 0; }
r[11]=r[3];
goto P_0c054982;
P_0c054982: /* original 6321, guest PC 0x0c054982 */
if(!s->budget--) { s->failed_pc=0x0c054982u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[3]=tmp;
goto P_0c054984;
P_0c054984: /* original 2f31, guest PC 0x0c054984 */
if(!s->budget--) { s->failed_pc=0x0c054984u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c054986;
P_0c054986: /* original d339, guest PC 0x0c054986 */
if(!s->budget--) { s->failed_pc=0x0c054986u; return 0; }
r[3]=read(ram,0x0c054a6cu,4);
goto P_0c054988;
P_0c054988: /* original 430b, guest PC 0x0c054988 */
if(!s->budget--) { s->failed_pc=0x0c054988u; return 0; }
target=r[3];
r[16]=code_base|0x0c05498cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05498cu) { target=s->pc; goto dispatch; }
goto P_0c05498c;
P_0c05498a: /* original 64e3, guest PC 0x0c05498a */
if(!s->budget--) { s->failed_pc=0x0c05498au; return 0; }
r[4]=r[14];
goto P_0c05498c;
P_0c05498c: /* original e000, guest PC 0x0c05498c */
if(!s->budget--) { s->failed_pc=0x0c05498cu; return 0; }
r[0]=0x00000000u;
goto P_0c05498e;
P_0c05498e: /* original a00a, guest PC 0x0c05498e */
if(!s->budget--) { s->failed_pc=0x0c05498eu; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c0549a6;
P_0c054990: /* original 80e8, guest PC 0x0c054990 */
if(!s->budget--) { s->failed_pc=0x0c054990u; return 0; }
write(ram,r[14]+8,r[0],1);
goto P_0c054992;
P_0c054992: /* original e609, guest PC 0x0c054992 */
if(!s->budget--) { s->failed_pc=0x0c054992u; return 0; }
r[6]=0x00000009u;
goto P_0c054994;
P_0c054994: /* original d236, guest PC 0x0c054994 */
if(!s->budget--) { s->failed_pc=0x0c054994u; return 0; }
r[2]=read(ram,0x0c054a70u,4);
goto P_0c054996;
P_0c054996: /* original e500, guest PC 0x0c054996 */
if(!s->budget--) { s->failed_pc=0x0c054996u; return 0; }
r[5]=0x00000000u;
goto P_0c054998;
P_0c054998: /* original 420b, guest PC 0x0c054998 */
if(!s->budget--) { s->failed_pc=0x0c054998u; return 0; }
target=r[2];
r[16]=code_base|0x0c05499cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05499cu) { target=s->pc; goto dispatch; }
goto P_0c05499c;
P_0c05499a: /* original 64e3, guest PC 0x0c05499a */
if(!s->budget--) { s->failed_pc=0x0c05499au; return 0; }
r[4]=r[14];
goto P_0c05499c;
P_0c05499c: /* original 60e0, guest PC 0x0c05499c */
if(!s->budget--) { s->failed_pc=0x0c05499cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c05499e;
P_0c05499e: /* original e300, guest PC 0x0c05499e */
if(!s->budget--) { s->failed_pc=0x0c05499eu; return 0; }
r[3]=0x00000000u;
goto P_0c0549a0;
P_0c0549a0: /* original cb80, guest PC 0x0c0549a0 */
if(!s->budget--) { s->failed_pc=0x0c0549a0u; return 0; }
r[0]|=128u;
goto P_0c0549a2;
P_0c0549a2: /* original 2e00, guest PC 0x0c0549a2 */
if(!s->budget--) { s->failed_pc=0x0c0549a2u; return 0; }
write(ram,r[14],r[0],1);
goto P_0c0549a4;
P_0c0549a4: /* original 2f31, guest PC 0x0c0549a4 */
if(!s->budget--) { s->failed_pc=0x0c0549a4u; return 0; }
write(ram,r[15],r[3],2);
goto P_0c0549a6;
P_0c0549a6: /* original e900, guest PC 0x0c0549a6 */
if(!s->budget--) { s->failed_pc=0x0c0549a6u; return 0; }
r[9]=0x00000000u;
goto P_0c0549a8;
P_0c0549a8: /* original d332, guest PC 0x0c0549a8 */
if(!s->budget--) { s->failed_pc=0x0c0549a8u; return 0; }
r[3]=read(ram,0x0c054a74u,4);
goto P_0c0549aa;
P_0c0549aa: /* original 61e3, guest PC 0x0c0549aa */
if(!s->budget--) { s->failed_pc=0x0c0549aau; return 0; }
r[1]=r[14];
goto P_0c0549ac;
P_0c0549ac: /* original d232, guest PC 0x0c0549ac */
if(!s->budget--) { s->failed_pc=0x0c0549acu; return 0; }
r[2]=read(ram,0x0c054a78u,4);
goto P_0c0549ae;
P_0c0549ae: /* original 6cd3, guest PC 0x0c0549ae */
if(!s->budget--) { s->failed_pc=0x0c0549aeu; return 0; }
r[12]=r[13];
goto P_0c0549b0;
P_0c0549b0: /* original 1f11, guest PC 0x0c0549b0 */
if(!s->budget--) { s->failed_pc=0x0c0549b0u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0549b2;
P_0c0549b2: /* original 4c08, guest PC 0x0c0549b2 */
if(!s->budget--) { s->failed_pc=0x0c0549b2u; return 0; }
r[12]<<=2;
goto P_0c0549b4;
P_0c0549b4: /* original 4c08, guest PC 0x0c0549b4 */
if(!s->budget--) { s->failed_pc=0x0c0549b4u; return 0; }
r[12]<<=2;
goto P_0c0549b6;
P_0c0549b6: /* original 3c3c, guest PC 0x0c0549b6 */
if(!s->budget--) { s->failed_pc=0x0c0549b6u; return 0; }
r[12]+=r[3];
goto P_0c0549b8;
P_0c0549b8: /* original 4d08, guest PC 0x0c0549b8 */
if(!s->budget--) { s->failed_pc=0x0c0549b8u; return 0; }
r[13]<<=2;
goto P_0c0549ba;
P_0c0549ba: /* original 4d08, guest PC 0x0c0549ba */
if(!s->budget--) { s->failed_pc=0x0c0549bau; return 0; }
r[13]<<=2;
goto P_0c0549bc;
P_0c0549bc: /* original 4d08, guest PC 0x0c0549bc */
if(!s->budget--) { s->failed_pc=0x0c0549bcu; return 0; }
r[13]<<=2;
goto P_0c0549be;
P_0c0549be: /* original 3d2c, guest PC 0x0c0549be */
if(!s->budget--) { s->failed_pc=0x0c0549beu; return 0; }
r[13]+=r[2];
goto P_0c0549c0;
P_0c0549c0: /* original e301, guest PC 0x0c0549c0 */
if(!s->budget--) { s->failed_pc=0x0c0549c0u; return 0; }
r[3]=0x00000001u;
goto P_0c0549c2;
P_0c0549c2: /* original 23a8, guest PC 0x0c0549c2 */
if(!s->budget--) { s->failed_pc=0x0c0549c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0549c4;
P_0c0549c4: /* original 8d14, guest PC 0x0c0549c4 */
if(!s->budget--) { s->failed_pc=0x0c0549c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0549f0; }
goto P_0c0549c8;
P_0c0549c6: /* original 0009, guest PC 0x0c0549c6 */
if(!s->budget--) { s->failed_pc=0x0c0549c6u; return 0; }
goto P_0c0549c8;
P_0c0549c8: /* original 66c1, guest PC 0x0c0549c8 */
if(!s->budget--) { s->failed_pc=0x0c0549c8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[6]=tmp;
goto P_0c0549ca;
P_0c0549ca: /* original 65e3, guest PC 0x0c0549ca */
if(!s->budget--) { s->failed_pc=0x0c0549cau; return 0; }
r[5]=r[14];
goto P_0c0549cc;
P_0c0549cc: /* original d32b, guest PC 0x0c0549cc */
if(!s->budget--) { s->failed_pc=0x0c0549ccu; return 0; }
r[3]=read(ram,0x0c054a7cu,4);
goto P_0c0549ce;
P_0c0549ce: /* original 67d3, guest PC 0x0c0549ce */
if(!s->budget--) { s->failed_pc=0x0c0549ceu; return 0; }
r[7]=r[13];
goto P_0c0549d0;
P_0c0549d0: /* original 430b, guest PC 0x0c0549d0 */
if(!s->budget--) { s->failed_pc=0x0c0549d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0549d4u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0549d4u) { target=s->pc; goto dispatch; }
goto P_0c0549d4;
P_0c0549d2: /* original 64f3, guest PC 0x0c0549d2 */
if(!s->budget--) { s->failed_pc=0x0c0549d2u; return 0; }
r[4]=r[15];
goto P_0c0549d4;
P_0c0549d4: /* original d22a, guest PC 0x0c0549d4 */
if(!s->budget--) { s->failed_pc=0x0c0549d4u; return 0; }
r[2]=read(ram,0x0c054a80u,4);
goto P_0c0549d6;
P_0c0549d6: /* original e540, guest PC 0x0c0549d6 */
if(!s->budget--) { s->failed_pc=0x0c0549d6u; return 0; }
r[5]=0x00000040u;
goto P_0c0549d8;
P_0c0549d8: /* original 420b, guest PC 0x0c0549d8 */
if(!s->budget--) { s->failed_pc=0x0c0549d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0549dcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0549dcu) { target=s->pc; goto dispatch; }
goto P_0c0549dc;
P_0c0549da: /* original 64e3, guest PC 0x0c0549da */
if(!s->budget--) { s->failed_pc=0x0c0549dau; return 0; }
r[4]=r[14];
goto P_0c0549dc;
P_0c0549dc: /* original 2008, guest PC 0x0c0549dc */
if(!s->budget--) { s->failed_pc=0x0c0549dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0549de;
P_0c0549de: /* original 8d07, guest PC 0x0c0549de */
if(!s->budget--) { s->failed_pc=0x0c0549deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0549f0; }
goto P_0c0549e2;
P_0c0549e0: /* original 0009, guest PC 0x0c0549e0 */
if(!s->budget--) { s->failed_pc=0x0c0549e0u; return 0; }
goto P_0c0549e2;
P_0c0549e2: /* original 62f1, guest PC 0x0c0549e2 */
if(!s->budget--) { s->failed_pc=0x0c0549e2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c0549e4;
P_0c0549e4: /* original 7201, guest PC 0x0c0549e4 */
if(!s->budget--) { s->failed_pc=0x0c0549e4u; return 0; }
r[2]+=0x00000001u;
goto P_0c0549e6;
P_0c0549e6: /* original 2f21, guest PC 0x0c0549e6 */
if(!s->budget--) { s->failed_pc=0x0c0549e6u; return 0; }
write(ram,r[15],r[2],2);
goto P_0c0549e8;
P_0c0549e8: /* original 53f1, guest PC 0x0c0549e8 */
if(!s->budget--) { s->failed_pc=0x0c0549e8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0549ea;
P_0c0549ea: /* original 6030, guest PC 0x0c0549ea */
if(!s->budget--) { s->failed_pc=0x0c0549eau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0549ec;
P_0c0549ec: /* original cb80, guest PC 0x0c0549ec */
if(!s->budget--) { s->failed_pc=0x0c0549ecu; return 0; }
r[0]|=128u;
goto P_0c0549ee;
P_0c0549ee: /* original 2300, guest PC 0x0c0549ee */
if(!s->budget--) { s->failed_pc=0x0c0549eeu; return 0; }
write(ram,r[3],r[0],1);
goto P_0c0549f0;
P_0c0549f0: /* original 4a21, guest PC 0x0c0549f0 */
if(!s->budget--) { s->failed_pc=0x0c0549f0u; return 0; }
r[17]=(r[17]&~1u)|((r[10]&1)!=0);
r[10]=(uint32_t)((int32_t)r[10]>>1);
goto P_0c0549f2;
P_0c0549f2: /* original 7901, guest PC 0x0c0549f2 */
if(!s->budget--) { s->failed_pc=0x0c0549f2u; return 0; }
r[9]+=0x00000001u;
goto P_0c0549f4;
P_0c0549f4: /* original 7c02, guest PC 0x0c0549f4 */
if(!s->budget--) { s->failed_pc=0x0c0549f4u; return 0; }
r[12]+=0x00000002u;
goto P_0c0549f6;
P_0c0549f6: /* original e308, guest PC 0x0c0549f6 */
if(!s->budget--) { s->failed_pc=0x0c0549f6u; return 0; }
r[3]=0x00000008u;
goto P_0c0549f8;
P_0c0549f8: /* original 3933, guest PC 0x0c0549f8 */
if(!s->budget--) { s->failed_pc=0x0c0549f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[3])!=0);
goto P_0c0549fa;
P_0c0549fa: /* original 8fe1, guest PC 0x0c0549fa */
if(!s->budget--) { s->failed_pc=0x0c0549fau; return 0; }
cond=r[17]&1u;
r[13]+=0x00000008u;
if(!cond) { goto P_0c0549c0; }
goto P_0c0549fe;
P_0c0549fc: /* original 7d08, guest PC 0x0c0549fc */
if(!s->budget--) { s->failed_pc=0x0c0549fcu; return 0; }
r[13]+=0x00000008u;
goto P_0c0549fe;
P_0c0549fe: /* original 2bb8, guest PC 0x0c0549fe */
if(!s->budget--) { s->failed_pc=0x0c0549feu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c054a00;
P_0c054a00: /* original 8d1a, guest PC 0x0c054a00 */
if(!s->budget--) { s->failed_pc=0x0c054a00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054a38; }
goto P_0c054a04;
P_0c054a02: /* original 0009, guest PC 0x0c054a02 */
if(!s->budget--) { s->failed_pc=0x0c054a02u; return 0; }
goto P_0c054a04;
P_0c054a04: /* original 55f2, guest PC 0x0c054a04 */
if(!s->budget--) { s->failed_pc=0x0c054a04u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c054a06;
P_0c054a06: /* original 6683, guest PC 0x0c054a06 */
if(!s->budget--) { s->failed_pc=0x0c054a06u; return 0; }
r[6]=r[8];
goto P_0c054a08;
P_0c054a08: /* original d31e, guest PC 0x0c054a08 */
if(!s->budget--) { s->failed_pc=0x0c054a08u; return 0; }
r[3]=read(ram,0x0c054a84u,4);
goto P_0c054a0a;
P_0c054a0a: /* original 430b, guest PC 0x0c054a0a */
if(!s->budget--) { s->failed_pc=0x0c054a0au; return 0; }
target=r[3];
r[16]=code_base|0x0c054a0eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054a0eu) { target=s->pc; goto dispatch; }
goto P_0c054a0e;
P_0c054a0c: /* original 64b3, guest PC 0x0c054a0c */
if(!s->budget--) { s->failed_pc=0x0c054a0cu; return 0; }
r[4]=r[11];
goto P_0c054a0e;
P_0c054a0e: /* original 6783, guest PC 0x0c054a0e */
if(!s->budget--) { s->failed_pc=0x0c054a0eu; return 0; }
r[7]=r[8];
goto P_0c054a10;
P_0c054a10: /* original 56f2, guest PC 0x0c054a10 */
if(!s->budget--) { s->failed_pc=0x0c054a10u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c054a12;
P_0c054a12: /* original 65e3, guest PC 0x0c054a12 */
if(!s->budget--) { s->failed_pc=0x0c054a12u; return 0; }
r[5]=r[14];
goto P_0c054a14;
P_0c054a14: /* original d319, guest PC 0x0c054a14 */
if(!s->budget--) { s->failed_pc=0x0c054a14u; return 0; }
r[3]=read(ram,0x0c054a7cu,4);
goto P_0c054a16;
P_0c054a16: /* original 6661, guest PC 0x0c054a16 */
if(!s->budget--) { s->failed_pc=0x0c054a16u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[6]=tmp;
goto P_0c054a18;
P_0c054a18: /* original 430b, guest PC 0x0c054a18 */
if(!s->budget--) { s->failed_pc=0x0c054a18u; return 0; }
target=r[3];
r[16]=code_base|0x0c054a1cu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054a1cu) { target=s->pc; goto dispatch; }
goto P_0c054a1c;
P_0c054a1a: /* original 64f3, guest PC 0x0c054a1a */
if(!s->budget--) { s->failed_pc=0x0c054a1au; return 0; }
r[4]=r[15];
goto P_0c054a1c;
P_0c054a1c: /* original d218, guest PC 0x0c054a1c */
if(!s->budget--) { s->failed_pc=0x0c054a1cu; return 0; }
r[2]=read(ram,0x0c054a80u,4);
goto P_0c054a1e;
P_0c054a1e: /* original e540, guest PC 0x0c054a1e */
if(!s->budget--) { s->failed_pc=0x0c054a1eu; return 0; }
r[5]=0x00000040u;
goto P_0c054a20;
P_0c054a20: /* original 420b, guest PC 0x0c054a20 */
if(!s->budget--) { s->failed_pc=0x0c054a20u; return 0; }
target=r[2];
r[16]=code_base|0x0c054a24u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054a24u) { target=s->pc; goto dispatch; }
goto P_0c054a24;
P_0c054a22: /* original 64e3, guest PC 0x0c054a22 */
if(!s->budget--) { s->failed_pc=0x0c054a22u; return 0; }
r[4]=r[14];
goto P_0c054a24;
P_0c054a24: /* original 8801, guest PC 0x0c054a24 */
if(!s->budget--) { s->failed_pc=0x0c054a24u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c054a26;
P_0c054a26: /* original 8f07, guest PC 0x0c054a26 */
if(!s->budget--) { s->failed_pc=0x0c054a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054a38; }
goto P_0c054a2a;
P_0c054a28: /* original 0009, guest PC 0x0c054a28 */
if(!s->budget--) { s->failed_pc=0x0c054a28u; return 0; }
goto P_0c054a2a;
P_0c054a2a: /* original 62f1, guest PC 0x0c054a2a */
if(!s->budget--) { s->failed_pc=0x0c054a2au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c054a2c;
P_0c054a2c: /* original 7201, guest PC 0x0c054a2c */
if(!s->budget--) { s->failed_pc=0x0c054a2cu; return 0; }
r[2]+=0x00000001u;
goto P_0c054a2e;
P_0c054a2e: /* original 2f21, guest PC 0x0c054a2e */
if(!s->budget--) { s->failed_pc=0x0c054a2eu; return 0; }
write(ram,r[15],r[2],2);
goto P_0c054a30;
P_0c054a30: /* original 53f1, guest PC 0x0c054a30 */
if(!s->budget--) { s->failed_pc=0x0c054a30u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c054a32;
P_0c054a32: /* original 6030, guest PC 0x0c054a32 */
if(!s->budget--) { s->failed_pc=0x0c054a32u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c054a34;
P_0c054a34: /* original cb80, guest PC 0x0c054a34 */
if(!s->budget--) { s->failed_pc=0x0c054a34u; return 0; }
r[0]|=128u;
goto P_0c054a36;
P_0c054a36: /* original 2300, guest PC 0x0c054a36 */
if(!s->budget--) { s->failed_pc=0x0c054a36u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c054a38;
P_0c054a38: /* original 53f2, guest PC 0x0c054a38 */
if(!s->budget--) { s->failed_pc=0x0c054a38u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c054a3a;
P_0c054a3a: /* original e608, guest PC 0x0c054a3a */
if(!s->budget--) { s->failed_pc=0x0c054a3au; return 0; }
r[6]=0x00000008u;
goto P_0c054a3c;
P_0c054a3c: /* original 62f1, guest PC 0x0c054a3c */
if(!s->budget--) { s->failed_pc=0x0c054a3cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[2]=tmp;
goto P_0c054a3e;
P_0c054a3e: /* original 65e3, guest PC 0x0c054a3e */
if(!s->budget--) { s->failed_pc=0x0c054a3eu; return 0; }
r[5]=r[14];
goto P_0c054a40;
P_0c054a40: /* original 2321, guest PC 0x0c054a40 */
if(!s->budget--) { s->failed_pc=0x0c054a40u; return 0; }
write(ram,r[3],r[2],2);
goto P_0c054a42;
P_0c054a42: /* original d30a, guest PC 0x0c054a42 */
if(!s->budget--) { s->failed_pc=0x0c054a42u; return 0; }
r[3]=read(ram,0x0c054a6cu,4);
goto P_0c054a44;
P_0c054a44: /* original 430b, guest PC 0x0c054a44 */
if(!s->budget--) { s->failed_pc=0x0c054a44u; return 0; }
target=r[3];
r[16]=code_base|0x0c054a48u;
r[4]=r[8];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054a48u) { target=s->pc; goto dispatch; }
goto P_0c054a48;
P_0c054a46: /* original 6483, guest PC 0x0c054a46 */
if(!s->budget--) { s->failed_pc=0x0c054a46u; return 0; }
r[4]=r[8];
goto P_0c054a48;
P_0c054a48: /* original 7f24, guest PC 0x0c054a48 */
if(!s->budget--) { s->failed_pc=0x0c054a48u; return 0; }
r[15]+=0x00000024u;
goto P_0c054a4a;
P_0c054a4a: /* original 4f26, guest PC 0x0c054a4a */
if(!s->budget--) { s->failed_pc=0x0c054a4au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054a4c;
P_0c054a4c: /* original 68f6, guest PC 0x0c054a4c */
if(!s->budget--) { s->failed_pc=0x0c054a4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c054a4e;
P_0c054a4e: /* original 69f6, guest PC 0x0c054a4e */
if(!s->budget--) { s->failed_pc=0x0c054a4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c054a50;
P_0c054a50: /* original 6af6, guest PC 0x0c054a50 */
if(!s->budget--) { s->failed_pc=0x0c054a50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c054a52;
P_0c054a52: /* original 6bf6, guest PC 0x0c054a52 */
if(!s->budget--) { s->failed_pc=0x0c054a52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c054a54;
P_0c054a54: /* original 6cf6, guest PC 0x0c054a54 */
if(!s->budget--) { s->failed_pc=0x0c054a54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c054a56;
P_0c054a56: /* original 6df6, guest PC 0x0c054a56 */
if(!s->budget--) { s->failed_pc=0x0c054a56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c054a58;
P_0c054a58: /* original 000b, guest PC 0x0c054a58 */
if(!s->budget--) { s->failed_pc=0x0c054a58u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054a5a: /* original 6ef6, guest PC 0x0c054a5a */
if(!s->budget--) { s->failed_pc=0x0c054a5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054a5cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054a5cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
