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
int vf3_away_batch4_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04f88cu: goto P_0c04f88c;
case 0x0c04f88eu: goto P_0c04f88e;
case 0x0c04f890u: goto P_0c04f890;
case 0x0c04f892u: goto P_0c04f892;
case 0x0c04f894u: goto P_0c04f894;
case 0x0c04f896u: goto P_0c04f896;
case 0x0c04f898u: goto P_0c04f898;
case 0x0c04f89au: goto P_0c04f89a;
case 0x0c04f89cu: goto P_0c04f89c;
case 0x0c04f89eu: goto P_0c04f89e;
case 0x0c04f8a0u: goto P_0c04f8a0;
case 0x0c04f8a2u: goto P_0c04f8a2;
case 0x0c04f8a4u: goto P_0c04f8a4;
case 0x0c04f8bcu: goto P_0c04f8bc;
case 0x0c04f8beu: goto P_0c04f8be;
case 0x0c04f8c0u: goto P_0c04f8c0;
case 0x0c04f8c2u: goto P_0c04f8c2;
case 0x0c04f8c4u: goto P_0c04f8c4;
case 0x0c04f8c6u: goto P_0c04f8c6;
case 0x0c04f8c8u: goto P_0c04f8c8;
case 0x0c04f8cau: goto P_0c04f8ca;
case 0x0c04f8ccu: goto P_0c04f8cc;
case 0x0c04f8ceu: goto P_0c04f8ce;
case 0x0c04f8d0u: goto P_0c04f8d0;
case 0x0c04f8d2u: goto P_0c04f8d2;
case 0x0c04f8d4u: goto P_0c04f8d4;
case 0x0c04f8d6u: goto P_0c04f8d6;
case 0x0c04f8d8u: goto P_0c04f8d8;
case 0x0c04f8dau: goto P_0c04f8da;
case 0x0c04f8dcu: goto P_0c04f8dc;
case 0x0c04f8deu: goto P_0c04f8de;
case 0x0c04f8e0u: goto P_0c04f8e0;
case 0x0c04f8e2u: goto P_0c04f8e2;
case 0x0c04f8e4u: goto P_0c04f8e4;
case 0x0c04f8e6u: goto P_0c04f8e6;
case 0x0c04f8e8u: goto P_0c04f8e8;
case 0x0c04f8eau: goto P_0c04f8ea;
case 0x0c04f8ecu: goto P_0c04f8ec;
case 0x0c04f8eeu: goto P_0c04f8ee;
case 0x0c04f8f0u: goto P_0c04f8f0;
case 0x0c04f8f2u: goto P_0c04f8f2;
case 0x0c04f8f4u: goto P_0c04f8f4;
case 0x0c04f8f6u: goto P_0c04f8f6;
case 0x0c04f8f8u: goto P_0c04f8f8;
case 0x0c04f8fau: goto P_0c04f8fa;
case 0x0c04f8fcu: goto P_0c04f8fc;
case 0x0c04f8feu: goto P_0c04f8fe;
case 0x0c04f900u: goto P_0c04f900;
case 0x0c04f902u: goto P_0c04f902;
case 0x0c04f904u: goto P_0c04f904;
case 0x0c04f906u: goto P_0c04f906;
case 0x0c04f908u: goto P_0c04f908;
case 0x0c04f90au: goto P_0c04f90a;
case 0x0c04f90cu: goto P_0c04f90c;
case 0x0c04f90eu: goto P_0c04f90e;
case 0x0c04f910u: goto P_0c04f910;
case 0x0c04f912u: goto P_0c04f912;
case 0x0c04f914u: goto P_0c04f914;
case 0x0c04f916u: goto P_0c04f916;
case 0x0c04f918u: goto P_0c04f918;
case 0x0c04f91au: goto P_0c04f91a;
case 0x0c04f91cu: goto P_0c04f91c;
case 0x0c04f91eu: goto P_0c04f91e;
case 0x0c04f920u: goto P_0c04f920;
case 0x0c04f922u: goto P_0c04f922;
case 0x0c04f924u: goto P_0c04f924;
case 0x0c04f926u: goto P_0c04f926;
case 0x0c04f928u: goto P_0c04f928;
case 0x0c04f92au: goto P_0c04f92a;
case 0x0c04f92cu: goto P_0c04f92c;
case 0x0c04f92eu: goto P_0c04f92e;
case 0x0c04f930u: goto P_0c04f930;
case 0x0c04f932u: goto P_0c04f932;
case 0x0c04f934u: goto P_0c04f934;
case 0x0c04f936u: goto P_0c04f936;
case 0x0c04f938u: goto P_0c04f938;
case 0x0c04f93au: goto P_0c04f93a;
case 0x0c04f93cu: goto P_0c04f93c;
case 0x0c04f93eu: goto P_0c04f93e;
case 0x0c04f940u: goto P_0c04f940;
case 0x0c04f942u: goto P_0c04f942;
case 0x0c04f944u: goto P_0c04f944;
case 0x0c04f946u: goto P_0c04f946;
case 0x0c04f948u: goto P_0c04f948;
case 0x0c04f94au: goto P_0c04f94a;
case 0x0c04f94cu: goto P_0c04f94c;
case 0x0c04f94eu: goto P_0c04f94e;
case 0x0c04f950u: goto P_0c04f950;
case 0x0c04f952u: goto P_0c04f952;
case 0x0c04f954u: goto P_0c04f954;
case 0x0c04f956u: goto P_0c04f956;
case 0x0c04f958u: goto P_0c04f958;
case 0x0c04f95au: goto P_0c04f95a;
case 0x0c04f95cu: goto P_0c04f95c;
case 0x0c04f95eu: goto P_0c04f95e;
case 0x0c04f960u: goto P_0c04f960;
case 0x0c04f962u: goto P_0c04f962;
case 0x0c04f964u: goto P_0c04f964;
case 0x0c04f966u: goto P_0c04f966;
case 0x0c04f968u: goto P_0c04f968;
case 0x0c04f96au: goto P_0c04f96a;
case 0x0c04f96cu: goto P_0c04f96c;
case 0x0c04f96eu: goto P_0c04f96e;
case 0x0c04f970u: goto P_0c04f970;
case 0x0c04f972u: goto P_0c04f972;
case 0x0c04f974u: goto P_0c04f974;
case 0x0c04f976u: goto P_0c04f976;
case 0x0c04f978u: goto P_0c04f978;
case 0x0c04f97au: goto P_0c04f97a;
case 0x0c04f97cu: goto P_0c04f97c;
case 0x0c04f97eu: goto P_0c04f97e;
case 0x0c04f980u: goto P_0c04f980;
case 0x0c04f982u: goto P_0c04f982;
case 0x0c04f984u: goto P_0c04f984;
case 0x0c04f986u: goto P_0c04f986;
case 0x0c04f988u: goto P_0c04f988;
case 0x0c04f98au: goto P_0c04f98a;
case 0x0c04f98cu: goto P_0c04f98c;
case 0x0c04f98eu: goto P_0c04f98e;
case 0x0c04f990u: goto P_0c04f990;
case 0x0c04f992u: goto P_0c04f992;
case 0x0c04f994u: goto P_0c04f994;
case 0x0c04f996u: goto P_0c04f996;
case 0x0c04f998u: goto P_0c04f998;
case 0x0c04f99au: goto P_0c04f99a;
case 0x0c04f99cu: goto P_0c04f99c;
case 0x0c04f99eu: goto P_0c04f99e;
case 0x0c04f9a0u: goto P_0c04f9a0;
case 0x0c04f9a2u: goto P_0c04f9a2;
case 0x0c04f9a4u: goto P_0c04f9a4;
case 0x0c04f9a6u: goto P_0c04f9a6;
case 0x0c04f9a8u: goto P_0c04f9a8;
case 0x0c04f9aau: goto P_0c04f9aa;
case 0x0c04f9acu: goto P_0c04f9ac;
case 0x0c04f9aeu: goto P_0c04f9ae;
case 0x0c04f9b0u: goto P_0c04f9b0;
case 0x0c04f9b2u: goto P_0c04f9b2;
case 0x0c04f9b4u: goto P_0c04f9b4;
case 0x0c04f9b6u: goto P_0c04f9b6;
case 0x0c04f9b8u: goto P_0c04f9b8;
case 0x0c04f9bau: goto P_0c04f9ba;
case 0x0c04f9bcu: goto P_0c04f9bc;
case 0x0c04f9beu: goto P_0c04f9be;
case 0x0c04f9c0u: goto P_0c04f9c0;
case 0x0c04f9c2u: goto P_0c04f9c2;
case 0x0c04f9c4u: goto P_0c04f9c4;
case 0x0c04f9c6u: goto P_0c04f9c6;
case 0x0c04f9c8u: goto P_0c04f9c8;
case 0x0c04f9cau: goto P_0c04f9ca;
case 0x0c04f9ccu: goto P_0c04f9cc;
case 0x0c04f9ceu: goto P_0c04f9ce;
case 0x0c04f9d0u: goto P_0c04f9d0;
case 0x0c04f9d2u: goto P_0c04f9d2;
case 0x0c04f9d4u: goto P_0c04f9d4;
case 0x0c04f9d6u: goto P_0c04f9d6;
case 0x0c04f9f0u: goto P_0c04f9f0;
case 0x0c04f9f2u: goto P_0c04f9f2;
case 0x0c04f9f4u: goto P_0c04f9f4;
case 0x0c04f9f6u: goto P_0c04f9f6;
case 0x0c04f9f8u: goto P_0c04f9f8;
case 0x0c04f9fau: goto P_0c04f9fa;
case 0x0c04f9fcu: goto P_0c04f9fc;
case 0x0c04f9feu: goto P_0c04f9fe;
case 0x0c04fa00u: goto P_0c04fa00;
case 0x0c04fa02u: goto P_0c04fa02;
case 0x0c04fa04u: goto P_0c04fa04;
case 0x0c04fa06u: goto P_0c04fa06;
case 0x0c04fa08u: goto P_0c04fa08;
case 0x0c04fa0au: goto P_0c04fa0a;
case 0x0c04fa0cu: goto P_0c04fa0c;
case 0x0c04fa0eu: goto P_0c04fa0e;
case 0x0c04fa10u: goto P_0c04fa10;
case 0x0c04fa12u: goto P_0c04fa12;
case 0x0c04fa14u: goto P_0c04fa14;
case 0x0c04fa16u: goto P_0c04fa16;
case 0x0c04fa18u: goto P_0c04fa18;
case 0x0c04fa1au: goto P_0c04fa1a;
case 0x0c04fa1cu: goto P_0c04fa1c;
case 0x0c04fa1eu: goto P_0c04fa1e;
case 0x0c04fa20u: goto P_0c04fa20;
case 0x0c04fa22u: goto P_0c04fa22;
case 0x0c04fa24u: goto P_0c04fa24;
case 0x0c04fa26u: goto P_0c04fa26;
case 0x0c04fa28u: goto P_0c04fa28;
case 0x0c04fa2au: goto P_0c04fa2a;
case 0x0c04fa2cu: goto P_0c04fa2c;
case 0x0c04fa2eu: goto P_0c04fa2e;
case 0x0c04fa30u: goto P_0c04fa30;
case 0x0c04fa32u: goto P_0c04fa32;
case 0x0c04fa34u: goto P_0c04fa34;
case 0x0c04fa36u: goto P_0c04fa36;
case 0x0c04fa7cu: goto P_0c04fa7c;
case 0x0c04fa7eu: goto P_0c04fa7e;
case 0x0c04fa80u: goto P_0c04fa80;
case 0x0c04fa82u: goto P_0c04fa82;
case 0x0c04fa84u: goto P_0c04fa84;
case 0x0c04fa86u: goto P_0c04fa86;
case 0x0c04fa88u: goto P_0c04fa88;
case 0x0c04fa8au: goto P_0c04fa8a;
case 0x0c04fa8cu: goto P_0c04fa8c;
case 0x0c04fa8eu: goto P_0c04fa8e;
case 0x0c04fa90u: goto P_0c04fa90;
case 0x0c04fa92u: goto P_0c04fa92;
case 0x0c04fa94u: goto P_0c04fa94;
case 0x0c04fa96u: goto P_0c04fa96;
case 0x0c04fa98u: goto P_0c04fa98;
case 0x0c04fa9au: goto P_0c04fa9a;
case 0x0c04fa9cu: goto P_0c04fa9c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04f88c: /* original e600, guest PC 0x0c04f88c */
if(!s->budget--) { s->failed_pc=0x0c04f88cu; return 0; }
r[6]=0x00000000u;
goto P_0c04f88e;
P_0c04f88e: /* original e70c, guest PC 0x0c04f88e */
if(!s->budget--) { s->failed_pc=0x0c04f88eu; return 0; }
r[7]=0x0000000cu;
goto P_0c04f890;
P_0c04f890: /* original 6563, guest PC 0x0c04f890 */
if(!s->budget--) { s->failed_pc=0x0c04f890u; return 0; }
r[5]=r[6];
goto P_0c04f892;
P_0c04f892: /* original 6340, guest PC 0x0c04f892 */
if(!s->budget--) { s->failed_pc=0x0c04f892u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f894;
P_0c04f894: /* original 2338, guest PC 0x0c04f894 */
if(!s->budget--) { s->failed_pc=0x0c04f894u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c04f896;
P_0c04f896: /* original 8904, guest PC 0x0c04f896 */
if(!s->budget--) { s->failed_pc=0x0c04f896u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8a2; }
goto P_0c04f898;
P_0c04f898: /* original 7601, guest PC 0x0c04f898 */
if(!s->budget--) { s->failed_pc=0x0c04f898u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f89a;
P_0c04f89a: /* original 3673, guest PC 0x0c04f89a */
if(!s->budget--) { s->failed_pc=0x0c04f89au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f89c;
P_0c04f89c: /* original 7501, guest PC 0x0c04f89c */
if(!s->budget--) { s->failed_pc=0x0c04f89cu; return 0; }
r[5]+=0x00000001u;
goto P_0c04f89e;
P_0c04f89e: /* original 8ff8, guest PC 0x0c04f89e */
if(!s->budget--) { s->failed_pc=0x0c04f89eu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f892; }
goto P_0c04f8a2;
P_0c04f8a0: /* original 7401, guest PC 0x0c04f8a0 */
if(!s->budget--) { s->failed_pc=0x0c04f8a0u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8a2;
P_0c04f8a2: /* original 000b, guest PC 0x0c04f8a2 */
if(!s->budget--) { s->failed_pc=0x0c04f8a2u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c04f8a4: /* original 6053, guest PC 0x0c04f8a4 */
if(!s->budget--) { s->failed_pc=0x0c04f8a4u; return 0; }
r[0]=r[5];
if(!vf3_matrix_family(0x0c04f8a6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f8a6u; return 0; } return 1;
P_0c04f8bc: /* original 2fe6, guest PC 0x0c04f8bc */
if(!s->budget--) { s->failed_pc=0x0c04f8bcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f8be;
P_0c04f8be: /* original 4f22, guest PC 0x0c04f8be */
if(!s->budget--) { s->failed_pc=0x0c04f8beu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f8c0;
P_0c04f8c0: /* original 7ff8, guest PC 0x0c04f8c0 */
if(!s->budget--) { s->failed_pc=0x0c04f8c0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c04f8c2;
P_0c04f8c2: /* original 2f42, guest PC 0x0c04f8c2 */
if(!s->budget--) { s->failed_pc=0x0c04f8c2u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c04f8c4;
P_0c04f8c4: /* original 1f51, guest PC 0x0c04f8c4 */
if(!s->budget--) { s->failed_pc=0x0c04f8c4u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c04f8c6;
P_0c04f8c6: /* original bfe1, guest PC 0x0c04f8c6 */
if(!s->budget--) { s->failed_pc=0x0c04f8c6u; return 0; }
target=code_base|0x0c04f88cu; r[16]=code_base|0x0c04f8cau;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f8cau) { target=s->pc; goto dispatch; }
goto P_0c04f8ca;
P_0c04f8c8: /* original 64f2, guest PC 0x0c04f8c8 */
if(!s->budget--) { s->failed_pc=0x0c04f8c8u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c04f8ca;
P_0c04f8ca: /* original 6e03, guest PC 0x0c04f8ca */
if(!s->budget--) { s->failed_pc=0x0c04f8cau; return 0; }
r[14]=r[0];
goto P_0c04f8cc;
P_0c04f8cc: /* original bfde, guest PC 0x0c04f8cc */
if(!s->budget--) { s->failed_pc=0x0c04f8ccu; return 0; }
target=code_base|0x0c04f88cu; r[16]=code_base|0x0c04f8d0u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f8d0u) { target=s->pc; goto dispatch; }
goto P_0c04f8d0;
P_0c04f8ce: /* original 54f1, guest PC 0x0c04f8ce */
if(!s->budget--) { s->failed_pc=0x0c04f8ceu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d0;
P_0c04f8d0: /* original 6403, guest PC 0x0c04f8d0 */
if(!s->budget--) { s->failed_pc=0x0c04f8d0u; return 0; }
r[4]=r[0];
goto P_0c04f8d2;
P_0c04f8d2: /* original 3e40, guest PC 0x0c04f8d2 */
if(!s->budget--) { s->failed_pc=0x0c04f8d2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[4])!=0);
goto P_0c04f8d4;
P_0c04f8d4: /* original 8b08, guest PC 0x0c04f8d4 */
if(!s->budget--) { s->failed_pc=0x0c04f8d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f8e8; }
goto P_0c04f8d6;
P_0c04f8d6: /* original 54f1, guest PC 0x0c04f8d6 */
if(!s->budget--) { s->failed_pc=0x0c04f8d6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c04f8d8;
P_0c04f8d8: /* original 4e15, guest PC 0x0c04f8d8 */
if(!s->budget--) { s->failed_pc=0x0c04f8d8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>0)!=0);
goto P_0c04f8da;
P_0c04f8da: /* original e600, guest PC 0x0c04f8da */
if(!s->budget--) { s->failed_pc=0x0c04f8dau; return 0; }
r[6]=0x00000000u;
goto P_0c04f8dc;
P_0c04f8dc: /* original 8f0e, guest PC 0x0c04f8dc */
if(!s->budget--) { s->failed_pc=0x0c04f8dcu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[15],4);
r[5]=tmp;
if(!cond) { goto P_0c04f8fc; }
goto P_0c04f8e0;
P_0c04f8de: /* original 65f2, guest PC 0x0c04f8de */
if(!s->budget--) { s->failed_pc=0x0c04f8deu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f8e0;
P_0c04f8e0: /* original 6340, guest PC 0x0c04f8e0 */
if(!s->budget--) { s->failed_pc=0x0c04f8e0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[3]=tmp;
goto P_0c04f8e2;
P_0c04f8e2: /* original 6250, guest PC 0x0c04f8e2 */
if(!s->budget--) { s->failed_pc=0x0c04f8e2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c04f8e4;
P_0c04f8e4: /* original 3230, guest PC 0x0c04f8e4 */
if(!s->budget--) { s->failed_pc=0x0c04f8e4u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c04f8e6;
P_0c04f8e6: /* original 8904, guest PC 0x0c04f8e6 */
if(!s->budget--) { s->failed_pc=0x0c04f8e6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f8f2; }
goto P_0c04f8e8;
P_0c04f8e8: /* original 7f08, guest PC 0x0c04f8e8 */
if(!s->budget--) { s->failed_pc=0x0c04f8e8u; return 0; }
r[15]+=0x00000008u;
goto P_0c04f8ea;
P_0c04f8ea: /* original 4f26, guest PC 0x0c04f8ea */
if(!s->budget--) { s->failed_pc=0x0c04f8eau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f8ec;
P_0c04f8ec: /* original e000, guest PC 0x0c04f8ec */
if(!s->budget--) { s->failed_pc=0x0c04f8ecu; return 0; }
r[0]=0x00000000u;
goto P_0c04f8ee;
P_0c04f8ee: /* original 000b, guest PC 0x0c04f8ee */
if(!s->budget--) { s->failed_pc=0x0c04f8eeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f8f0: /* original 6ef6, guest PC 0x0c04f8f0 */
if(!s->budget--) { s->failed_pc=0x0c04f8f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f8f2;
P_0c04f8f2: /* original 7601, guest PC 0x0c04f8f2 */
if(!s->budget--) { s->failed_pc=0x0c04f8f2u; return 0; }
r[6]+=0x00000001u;
goto P_0c04f8f4;
P_0c04f8f4: /* original 36e3, guest PC 0x0c04f8f4 */
if(!s->budget--) { s->failed_pc=0x0c04f8f4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[14])!=0);
goto P_0c04f8f6;
P_0c04f8f6: /* original 7401, guest PC 0x0c04f8f6 */
if(!s->budget--) { s->failed_pc=0x0c04f8f6u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f8f8;
P_0c04f8f8: /* original 8ff2, guest PC 0x0c04f8f8 */
if(!s->budget--) { s->failed_pc=0x0c04f8f8u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c04f8e0; }
goto P_0c04f8fc;
P_0c04f8fa: /* original 7501, guest PC 0x0c04f8fa */
if(!s->budget--) { s->failed_pc=0x0c04f8fau; return 0; }
r[5]+=0x00000001u;
goto P_0c04f8fc;
P_0c04f8fc: /* original e001, guest PC 0x0c04f8fc */
if(!s->budget--) { s->failed_pc=0x0c04f8fcu; return 0; }
r[0]=0x00000001u;
goto P_0c04f8fe;
P_0c04f8fe: /* original 7f08, guest PC 0x0c04f8fe */
if(!s->budget--) { s->failed_pc=0x0c04f8feu; return 0; }
r[15]+=0x00000008u;
goto P_0c04f900;
P_0c04f900: /* original 4f26, guest PC 0x0c04f900 */
if(!s->budget--) { s->failed_pc=0x0c04f900u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f902;
P_0c04f902: /* original 000b, guest PC 0x0c04f902 */
if(!s->budget--) { s->failed_pc=0x0c04f902u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f904: /* original 6ef6, guest PC 0x0c04f904 */
if(!s->budget--) { s->failed_pc=0x0c04f904u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f906;
P_0c04f906: /* original 2fe6, guest PC 0x0c04f906 */
if(!s->budget--) { s->failed_pc=0x0c04f906u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f908;
P_0c04f908: /* original 6e53, guest PC 0x0c04f908 */
if(!s->budget--) { s->failed_pc=0x0c04f908u; return 0; }
r[14]=r[5];
goto P_0c04f90a;
P_0c04f90a: /* original 2fd6, guest PC 0x0c04f90a */
if(!s->budget--) { s->failed_pc=0x0c04f90au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f90c;
P_0c04f90c: /* original 6d43, guest PC 0x0c04f90c */
if(!s->budget--) { s->failed_pc=0x0c04f90cu; return 0; }
r[13]=r[4];
goto P_0c04f90e;
P_0c04f90e: /* original 2fc6, guest PC 0x0c04f90e */
if(!s->budget--) { s->failed_pc=0x0c04f90eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f910;
P_0c04f910: /* original e500, guest PC 0x0c04f910 */
if(!s->budget--) { s->failed_pc=0x0c04f910u; return 0; }
r[5]=0x00000000u;
goto P_0c04f912;
P_0c04f912: /* original 4f22, guest PC 0x0c04f912 */
if(!s->budget--) { s->failed_pc=0x0c04f912u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f914;
P_0c04f914: /* original 63d0, guest PC 0x0c04f914 */
if(!s->budget--) { s->failed_pc=0x0c04f914u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[3]=tmp;
goto P_0c04f916;
P_0c04f916: /* original 35dc, guest PC 0x0c04f916 */
if(!s->budget--) { s->failed_pc=0x0c04f916u; return 0; }
r[5]+=r[13];
goto P_0c04f918;
P_0c04f918: /* original 64e3, guest PC 0x0c04f918 */
if(!s->budget--) { s->failed_pc=0x0c04f918u; return 0; }
r[4]=r[14];
goto P_0c04f91a;
P_0c04f91a: /* original ec00, guest PC 0x0c04f91a */
if(!s->budget--) { s->failed_pc=0x0c04f91au; return 0; }
r[12]=0x00000000u;
goto P_0c04f91c;
P_0c04f91c: /* original 7ffc, guest PC 0x0c04f91c */
if(!s->budget--) { s->failed_pc=0x0c04f91cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f91e;
P_0c04f91e: /* original 66c3, guest PC 0x0c04f91e */
if(!s->budget--) { s->failed_pc=0x0c04f91eu; return 0; }
r[6]=r[12];
goto P_0c04f920;
P_0c04f920: /* original 633c, guest PC 0x0c04f920 */
if(!s->budget--) { s->failed_pc=0x0c04f920u; return 0; }
r[3]=r[3]&255u;
goto P_0c04f922;
P_0c04f922: /* original e70c, guest PC 0x0c04f922 */
if(!s->budget--) { s->failed_pc=0x0c04f922u; return 0; }
r[7]=0x0000000cu;
goto P_0c04f924;
P_0c04f924: /* original 1e31, guest PC 0x0c04f924 */
if(!s->budget--) { s->failed_pc=0x0c04f924u; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c04f926;
P_0c04f926: /* original 2f52, guest PC 0x0c04f926 */
if(!s->budget--) { s->failed_pc=0x0c04f926u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c04f928;
P_0c04f928: /* original 7410, guest PC 0x0c04f928 */
if(!s->budget--) { s->failed_pc=0x0c04f928u; return 0; }
r[4]+=0x00000010u;
goto P_0c04f92a;
P_0c04f92a: /* original 7504, guest PC 0x0c04f92a */
if(!s->budget--) { s->failed_pc=0x0c04f92au; return 0; }
r[5]+=0x00000004u;
goto P_0c04f92c;
P_0c04f92c: /* original 6354, guest PC 0x0c04f92c */
if(!s->budget--) { s->failed_pc=0x0c04f92cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04f92e;
P_0c04f92e: /* original 7601, guest PC 0x0c04f92e */
if(!s->budget--) { s->failed_pc=0x0c04f92eu; return 0; }
r[6]+=0x00000001u;
goto P_0c04f930;
P_0c04f930: /* original 3673, guest PC 0x0c04f930 */
if(!s->budget--) { s->failed_pc=0x0c04f930u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f932;
P_0c04f932: /* original 2430, guest PC 0x0c04f932 */
if(!s->budget--) { s->failed_pc=0x0c04f932u; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04f934;
P_0c04f934: /* original 8ffa, guest PC 0x0c04f934 */
if(!s->budget--) { s->failed_pc=0x0c04f934u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f92c; }
goto P_0c04f938;
P_0c04f936: /* original 7401, guest PC 0x0c04f936 */
if(!s->budget--) { s->failed_pc=0x0c04f936u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f938;
P_0c04f938: /* original e01c, guest PC 0x0c04f938 */
if(!s->budget--) { s->failed_pc=0x0c04f938u; return 0; }
r[0]=0x0000001cu;
goto P_0c04f93a;
P_0c04f93a: /* original 64e3, guest PC 0x0c04f93a */
if(!s->budget--) { s->failed_pc=0x0c04f93au; return 0; }
r[4]=r[14];
goto P_0c04f93c;
P_0c04f93c: /* original e708, guest PC 0x0c04f93c */
if(!s->budget--) { s->failed_pc=0x0c04f93cu; return 0; }
r[7]=0x00000008u;
goto P_0c04f93e;
P_0c04f93e: /* original 0ec4, guest PC 0x0c04f93e */
if(!s->budget--) { s->failed_pc=0x0c04f93eu; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c04f940;
P_0c04f940: /* original 65f2, guest PC 0x0c04f940 */
if(!s->budget--) { s->failed_pc=0x0c04f940u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f942;
P_0c04f942: /* original 7420, guest PC 0x0c04f942 */
if(!s->budget--) { s->failed_pc=0x0c04f942u; return 0; }
r[4]+=0x00000020u;
goto P_0c04f944;
P_0c04f944: /* original 66c3, guest PC 0x0c04f944 */
if(!s->budget--) { s->failed_pc=0x0c04f944u; return 0; }
r[6]=r[12];
goto P_0c04f946;
P_0c04f946: /* original 7510, guest PC 0x0c04f946 */
if(!s->budget--) { s->failed_pc=0x0c04f946u; return 0; }
r[5]+=0x00000010u;
goto P_0c04f948;
P_0c04f948: /* original 6354, guest PC 0x0c04f948 */
if(!s->budget--) { s->failed_pc=0x0c04f948u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[5]+=1;
r[3]=tmp;
goto P_0c04f94a;
P_0c04f94a: /* original 7601, guest PC 0x0c04f94a */
if(!s->budget--) { s->failed_pc=0x0c04f94au; return 0; }
r[6]+=0x00000001u;
goto P_0c04f94c;
P_0c04f94c: /* original 3673, guest PC 0x0c04f94c */
if(!s->budget--) { s->failed_pc=0x0c04f94cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c04f94e;
P_0c04f94e: /* original 2430, guest PC 0x0c04f94e */
if(!s->budget--) { s->failed_pc=0x0c04f94eu; return 0; }
write(ram,r[4],r[3],1);
goto P_0c04f950;
P_0c04f950: /* original 8ffa, guest PC 0x0c04f950 */
if(!s->budget--) { s->failed_pc=0x0c04f950u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(!cond) { goto P_0c04f948; }
goto P_0c04f954;
P_0c04f952: /* original 7401, guest PC 0x0c04f952 */
if(!s->budget--) { s->failed_pc=0x0c04f952u; return 0; }
r[4]+=0x00000001u;
goto P_0c04f954;
P_0c04f954: /* original dc21, guest PC 0x0c04f954 */
if(!s->budget--) { s->failed_pc=0x0c04f954u; return 0; }
r[12]=read(ram,0x0c04f9dcu,4);
goto P_0c04f956;
P_0c04f956: /* original e502, guest PC 0x0c04f956 */
if(!s->budget--) { s->failed_pc=0x0c04f956u; return 0; }
r[5]=0x00000002u;
goto P_0c04f958;
P_0c04f958: /* original 63c2, guest PC 0x0c04f958 */
if(!s->budget--) { s->failed_pc=0x0c04f958u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f95a;
P_0c04f95a: /* original 5233, guest PC 0x0c04f95a */
if(!s->budget--) { s->failed_pc=0x0c04f95au; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f95c;
P_0c04f95c: /* original 420b, guest PC 0x0c04f95c */
if(!s->budget--) { s->failed_pc=0x0c04f95cu; return 0; }
target=r[2];
r[16]=code_base|0x0c04f960u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f960u) { target=s->pc; goto dispatch; }
goto P_0c04f960;
P_0c04f95e: /* original 64d3, guest PC 0x0c04f95e */
if(!s->budget--) { s->failed_pc=0x0c04f95eu; return 0; }
r[4]=r[13];
goto P_0c04f960;
P_0c04f960: /* original 600d, guest PC 0x0c04f960 */
if(!s->budget--) { s->failed_pc=0x0c04f960u; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f962;
P_0c04f962: /* original e518, guest PC 0x0c04f962 */
if(!s->budget--) { s->failed_pc=0x0c04f962u; return 0; }
r[5]=0x00000018u;
goto P_0c04f964;
P_0c04f964: /* original 1e03, guest PC 0x0c04f964 */
if(!s->budget--) { s->failed_pc=0x0c04f964u; return 0; }
write(ram,r[14]+12,r[0],4);
goto P_0c04f966;
P_0c04f966: /* original 63c2, guest PC 0x0c04f966 */
if(!s->budget--) { s->failed_pc=0x0c04f966u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c04f968;
P_0c04f968: /* original 5233, guest PC 0x0c04f968 */
if(!s->budget--) { s->failed_pc=0x0c04f968u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c04f96a;
P_0c04f96a: /* original 420b, guest PC 0x0c04f96a */
if(!s->budget--) { s->failed_pc=0x0c04f96au; return 0; }
target=r[2];
r[16]=code_base|0x0c04f96eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f96eu) { target=s->pc; goto dispatch; }
goto P_0c04f96e;
P_0c04f96c: /* original 64d3, guest PC 0x0c04f96c */
if(!s->budget--) { s->failed_pc=0x0c04f96cu; return 0; }
r[4]=r[13];
goto P_0c04f96e;
P_0c04f96e: /* original 600d, guest PC 0x0c04f96e */
if(!s->budget--) { s->failed_pc=0x0c04f96eu; return 0; }
r[0]=r[0]&65535u;
goto P_0c04f970;
P_0c04f970: /* original 1e0a, guest PC 0x0c04f970 */
if(!s->budget--) { s->failed_pc=0x0c04f970u; return 0; }
write(ram,r[14]+40,r[0],4);
goto P_0c04f972;
P_0c04f972: /* original e51a, guest PC 0x0c04f972 */
if(!s->budget--) { s->failed_pc=0x0c04f972u; return 0; }
r[5]=0x0000001au;
goto P_0c04f974;
P_0c04f974: /* original 84d1, guest PC 0x0c04f974 */
if(!s->budget--) { s->failed_pc=0x0c04f974u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+1,1);
goto P_0c04f976;
P_0c04f976: /* original 80ea, guest PC 0x0c04f976 */
if(!s->budget--) { s->failed_pc=0x0c04f976u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c04f978;
P_0c04f978: /* original 60c2, guest PC 0x0c04f978 */
if(!s->budget--) { s->failed_pc=0x0c04f978u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c04f97a;
P_0c04f97a: /* original 5003, guest PC 0x0c04f97a */
if(!s->budget--) { s->failed_pc=0x0c04f97au; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c04f97c;
P_0c04f97c: /* original 400b, guest PC 0x0c04f97c */
if(!s->budget--) { s->failed_pc=0x0c04f97cu; return 0; }
target=r[0];
r[16]=code_base|0x0c04f980u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f980u) { target=s->pc; goto dispatch; }
goto P_0c04f980;
P_0c04f97e: /* original 64d3, guest PC 0x0c04f97e */
if(!s->budget--) { s->failed_pc=0x0c04f97eu; return 0; }
r[4]=r[13];
goto P_0c04f980;
P_0c04f980: /* original 7f04, guest PC 0x0c04f980 */
if(!s->budget--) { s->failed_pc=0x0c04f980u; return 0; }
r[15]+=0x00000004u;
goto P_0c04f982;
P_0c04f982: /* original 81e4, guest PC 0x0c04f982 */
if(!s->budget--) { s->failed_pc=0x0c04f982u; return 0; }
write(ram,r[14]+8,r[0],2);
goto P_0c04f984;
P_0c04f984: /* original 4f26, guest PC 0x0c04f984 */
if(!s->budget--) { s->failed_pc=0x0c04f984u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04f986;
P_0c04f986: /* original 6cf6, guest PC 0x0c04f986 */
if(!s->budget--) { s->failed_pc=0x0c04f986u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04f988;
P_0c04f988: /* original 6df6, guest PC 0x0c04f988 */
if(!s->budget--) { s->failed_pc=0x0c04f988u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04f98a;
P_0c04f98a: /* original 000b, guest PC 0x0c04f98a */
if(!s->budget--) { s->failed_pc=0x0c04f98au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04f98c: /* original 6ef6, guest PC 0x0c04f98c */
if(!s->budget--) { s->failed_pc=0x0c04f98cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04f98e;
P_0c04f98e: /* original 2fe6, guest PC 0x0c04f98e */
if(!s->budget--) { s->failed_pc=0x0c04f98eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f990;
P_0c04f990: /* original 2fd6, guest PC 0x0c04f990 */
if(!s->budget--) { s->failed_pc=0x0c04f990u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f992;
P_0c04f992: /* original 2fc6, guest PC 0x0c04f992 */
if(!s->budget--) { s->failed_pc=0x0c04f992u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f994;
P_0c04f994: /* original 2fb6, guest PC 0x0c04f994 */
if(!s->budget--) { s->failed_pc=0x0c04f994u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f996;
P_0c04f996: /* original 6b53, guest PC 0x0c04f996 */
if(!s->budget--) { s->failed_pc=0x0c04f996u; return 0; }
r[11]=r[5];
goto P_0c04f998;
P_0c04f998: /* original 2fa6, guest PC 0x0c04f998 */
if(!s->budget--) { s->failed_pc=0x0c04f998u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f99a;
P_0c04f99a: /* original 4f22, guest PC 0x0c04f99a */
if(!s->budget--) { s->failed_pc=0x0c04f99au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04f99c;
P_0c04f99c: /* original 4f12, guest PC 0x0c04f99c */
if(!s->budget--) { s->failed_pc=0x0c04f99cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04f99e;
P_0c04f99e: /* original 7ffc, guest PC 0x0c04f99e */
if(!s->budget--) { s->failed_pc=0x0c04f99eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04f9a0;
P_0c04f9a0: /* original 2f62, guest PC 0x0c04f9a0 */
if(!s->budget--) { s->failed_pc=0x0c04f9a0u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c04f9a2;
P_0c04f9a2: /* original 9c19, guest PC 0x0c04f9a2 */
if(!s->budget--) { s->failed_pc=0x0c04f9a2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9d8u,2);
goto P_0c04f9a4;
P_0c04f9a4: /* original d30e, guest PC 0x0c04f9a4 */
if(!s->budget--) { s->failed_pc=0x0c04f9a4u; return 0; }
r[3]=read(ram,0x0c04f9e0u,4);
goto P_0c04f9a6;
P_0c04f9a6: /* original 24cf, guest PC 0x0c04f9a6 */
if(!s->budget--) { s->failed_pc=0x0c04f9a6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[12]);
goto P_0c04f9a8;
P_0c04f9a8: /* original 2fb6, guest PC 0x0c04f9a8 */
if(!s->budget--) { s->failed_pc=0x0c04f9a8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f9aa;
P_0c04f9aa: /* original d10f, guest PC 0x0c04f9aa */
if(!s->budget--) { s->failed_pc=0x0c04f9aau; return 0; }
r[1]=read(ram,0x0c04f9e8u,4);
goto P_0c04f9ac;
P_0c04f9ac: /* original d20d, guest PC 0x0c04f9ac */
if(!s->budget--) { s->failed_pc=0x0c04f9acu; return 0; }
r[2]=read(ram,0x0c04f9e4u,4);
goto P_0c04f9ae;
P_0c04f9ae: /* original 0c1a, guest PC 0x0c04f9ae */
if(!s->budget--) { s->failed_pc=0x0c04f9aeu; return 0; }
r[12]=r[19];
goto P_0c04f9b0;
P_0c04f9b0: /* original 6ccf, guest PC 0x0c04f9b0 */
if(!s->budget--) { s->failed_pc=0x0c04f9b0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c04f9b2;
P_0c04f9b2: /* original 3c3c, guest PC 0x0c04f9b2 */
if(!s->budget--) { s->failed_pc=0x0c04f9b2u; return 0; }
r[12]+=r[3];
goto P_0c04f9b4;
P_0c04f9b4: /* original 410b, guest PC 0x0c04f9b4 */
if(!s->budget--) { s->failed_pc=0x0c04f9b4u; return 0; }
target=r[1];
r[16]=code_base|0x0c04f9b8u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f9b8u) { target=s->pc; goto dispatch; }
goto P_0c04f9b8;
P_0c04f9b6: /* original 2f26, guest PC 0x0c04f9b6 */
if(!s->budget--) { s->failed_pc=0x0c04f9b6u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04f9b8;
P_0c04f9b8: /* original da0c, guest PC 0x0c04f9b8 */
if(!s->budget--) { s->failed_pc=0x0c04f9b8u; return 0; }
r[10]=read(ram,0x0c04f9ecu,4);
goto P_0c04f9ba;
P_0c04f9ba: /* original 7f08, guest PC 0x0c04f9ba */
if(!s->budget--) { s->failed_pc=0x0c04f9bau; return 0; }
r[15]+=0x00000008u;
goto P_0c04f9bc;
P_0c04f9bc: /* original 5eca, guest PC 0x0c04f9bc */
if(!s->budget--) { s->failed_pc=0x0c04f9bcu; return 0; }
r[14]=read(ram,r[12]+40,4);
goto P_0c04f9be;
P_0c04f9be: /* original a028, guest PC 0x0c04f9be */
if(!s->budget--) { s->failed_pc=0x0c04f9beu; return 0; }
r[13]=0x00000000u;
goto P_0c04fa12;
P_0c04f9c0: /* original ed00, guest PC 0x0c04f9c0 */
if(!s->budget--) { s->failed_pc=0x0c04f9c0u; return 0; }
r[13]=0x00000000u;
goto P_0c04f9c2;
P_0c04f9c2: /* original 64e0, guest PC 0x0c04f9c2 */
if(!s->budget--) { s->failed_pc=0x0c04f9c2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c04f9c4;
P_0c04f9c4: /* original 604c, guest PC 0x0c04f9c4 */
if(!s->budget--) { s->failed_pc=0x0c04f9c4u; return 0; }
r[0]=r[4]&255u;
goto P_0c04f9c6;
P_0c04f9c6: /* original 8800, guest PC 0x0c04f9c6 */
if(!s->budget--) { s->failed_pc=0x0c04f9c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04f9c8;
P_0c04f9c8: /* original 8921, guest PC 0x0c04f9c8 */
if(!s->budget--) { s->failed_pc=0x0c04f9c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9ca;
P_0c04f9ca: /* original 8833, guest PC 0x0c04f9ca */
if(!s->budget--) { s->failed_pc=0x0c04f9cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000033u)!=0);
goto P_0c04f9cc;
P_0c04f9cc: /* original 8910, guest PC 0x0c04f9cc */
if(!s->budget--) { s->failed_pc=0x0c04f9ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9ce;
P_0c04f9ce: /* original 9104, guest PC 0x0c04f9ce */
if(!s->budget--) { s->failed_pc=0x0c04f9ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04f9dau,2);
goto P_0c04f9d0;
P_0c04f9d0: /* original 3010, guest PC 0x0c04f9d0 */
if(!s->budget--) { s->failed_pc=0x0c04f9d0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04f9d2;
P_0c04f9d2: /* original 890d, guest PC 0x0c04f9d2 */
if(!s->budget--) { s->failed_pc=0x0c04f9d2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04f9f0; }
goto P_0c04f9d4;
P_0c04f9d4: /* original a01b, guest PC 0x0c04f9d4 */
if(!s->budget--) { s->failed_pc=0x0c04f9d4u; return 0; }
goto P_0c04fa0e;
P_0c04f9d6: /* original 0009, guest PC 0x0c04f9d6 */
if(!s->budget--) { s->failed_pc=0x0c04f9d6u; return 0; }
if(!vf3_matrix_family(0x0c04f9d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04f9d8u; return 0; } return 1;
P_0c04f9f0: /* original 65e3, guest PC 0x0c04f9f0 */
if(!s->budget--) { s->failed_pc=0x0c04f9f0u; return 0; }
r[5]=r[14];
goto P_0c04f9f2;
P_0c04f9f2: /* original 7504, guest PC 0x0c04f9f2 */
if(!s->budget--) { s->failed_pc=0x0c04f9f2u; return 0; }
r[5]+=0x00000004u;
goto P_0c04f9f4;
P_0c04f9f4: /* original bf62, guest PC 0x0c04f9f4 */
if(!s->budget--) { s->failed_pc=0x0c04f9f4u; return 0; }
target=code_base|0x0c04f8bcu; r[16]=code_base|0x0c04f9f8u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04f9f8u) { target=s->pc; goto dispatch; }
goto P_0c04f9f8;
P_0c04f9f6: /* original 64b3, guest PC 0x0c04f9f6 */
if(!s->budget--) { s->failed_pc=0x0c04f9f6u; return 0; }
r[4]=r[11];
goto P_0c04f9f8;
P_0c04f9f8: /* original 2008, guest PC 0x0c04f9f8 */
if(!s->budget--) { s->failed_pc=0x0c04f9f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04f9fa;
P_0c04f9fa: /* original 8908, guest PC 0x0c04f9fa */
if(!s->budget--) { s->failed_pc=0x0c04f9fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04fa0e; }
goto P_0c04f9fc;
P_0c04f9fc: /* original 65f2, guest PC 0x0c04f9fc */
if(!s->budget--) { s->failed_pc=0x0c04f9fcu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04f9fe;
P_0c04f9fe: /* original bf82, guest PC 0x0c04f9fe */
if(!s->budget--) { s->failed_pc=0x0c04f9feu; return 0; }
target=code_base|0x0c04f906u; r[16]=code_base|0x0c04fa02u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa02u) { target=s->pc; goto dispatch; }
goto P_0c04fa02;
P_0c04fa00: /* original 64e3, guest PC 0x0c04fa00 */
if(!s->budget--) { s->failed_pc=0x0c04fa00u; return 0; }
r[4]=r[14];
goto P_0c04fa02;
P_0c04fa02: /* original d239, guest PC 0x0c04fa02 */
if(!s->budget--) { s->failed_pc=0x0c04fa02u; return 0; }
r[2]=read(ram,0x0c04fae8u,4);
goto P_0c04fa04;
P_0c04fa04: /* original 420b, guest PC 0x0c04fa04 */
if(!s->budget--) { s->failed_pc=0x0c04fa04u; return 0; }
target=r[2];
r[16]=code_base|0x0c04fa08u;
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa08u) { target=s->pc; goto dispatch; }
goto P_0c04fa08;
P_0c04fa06: /* original 2fa6, guest PC 0x0c04fa06 */
if(!s->budget--) { s->failed_pc=0x0c04fa06u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa08;
P_0c04fa08: /* original 7f04, guest PC 0x0c04fa08 */
if(!s->budget--) { s->failed_pc=0x0c04fa08u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa0a;
P_0c04fa0a: /* original a00c, guest PC 0x0c04fa0a */
if(!s->budget--) { s->failed_pc=0x0c04fa0au; return 0; }
r[0]=r[13];
goto P_0c04fa26;
P_0c04fa0c: /* original 60d3, guest PC 0x0c04fa0c */
if(!s->budget--) { s->failed_pc=0x0c04fa0cu; return 0; }
r[0]=r[13];
goto P_0c04fa0e;
P_0c04fa0e: /* original 7e20, guest PC 0x0c04fa0e */
if(!s->budget--) { s->failed_pc=0x0c04fa0eu; return 0; }
r[14]+=0x00000020u;
goto P_0c04fa10;
P_0c04fa10: /* original 7d01, guest PC 0x0c04fa10 */
if(!s->budget--) { s->failed_pc=0x0c04fa10u; return 0; }
r[13]+=0x00000001u;
goto P_0c04fa12;
P_0c04fa12: /* original 52c7, guest PC 0x0c04fa12 */
if(!s->budget--) { s->failed_pc=0x0c04fa12u; return 0; }
r[2]=read(ram,r[12]+28,4);
goto P_0c04fa14;
P_0c04fa14: /* original 532c, guest PC 0x0c04fa14 */
if(!s->budget--) { s->failed_pc=0x0c04fa14u; return 0; }
r[3]=read(ram,r[2]+48,4);
goto P_0c04fa16;
P_0c04fa16: /* original 3d33, guest PC 0x0c04fa16 */
if(!s->budget--) { s->failed_pc=0x0c04fa16u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[3])!=0);
goto P_0c04fa18;
P_0c04fa18: /* original 8bd3, guest PC 0x0c04fa18 */
if(!s->budget--) { s->failed_pc=0x0c04fa18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04f9c2; }
goto P_0c04fa1a;
P_0c04fa1a: /* original d333, guest PC 0x0c04fa1a */
if(!s->budget--) { s->failed_pc=0x0c04fa1au; return 0; }
r[3]=read(ram,0x0c04fae8u,4);
goto P_0c04fa1c;
P_0c04fa1c: /* original d133, guest PC 0x0c04fa1c */
if(!s->budget--) { s->failed_pc=0x0c04fa1cu; return 0; }
r[1]=read(ram,0x0c04faecu,4);
goto P_0c04fa1e;
P_0c04fa1e: /* original 430b, guest PC 0x0c04fa1e */
if(!s->budget--) { s->failed_pc=0x0c04fa1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04fa22u;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04fa22u) { target=s->pc; goto dispatch; }
goto P_0c04fa22;
P_0c04fa20: /* original 2f16, guest PC 0x0c04fa20 */
if(!s->budget--) { s->failed_pc=0x0c04fa20u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04fa22;
P_0c04fa22: /* original e0ff, guest PC 0x0c04fa22 */
if(!s->budget--) { s->failed_pc=0x0c04fa22u; return 0; }
r[0]=0xffffffffu;
goto P_0c04fa24;
P_0c04fa24: /* original 7f04, guest PC 0x0c04fa24 */
if(!s->budget--) { s->failed_pc=0x0c04fa24u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa26;
P_0c04fa26: /* original 7f04, guest PC 0x0c04fa26 */
if(!s->budget--) { s->failed_pc=0x0c04fa26u; return 0; }
r[15]+=0x00000004u;
goto P_0c04fa28;
P_0c04fa28: /* original 4f16, guest PC 0x0c04fa28 */
if(!s->budget--) { s->failed_pc=0x0c04fa28u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2a;
P_0c04fa2a: /* original 4f26, guest PC 0x0c04fa2a */
if(!s->budget--) { s->failed_pc=0x0c04fa2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04fa2c;
P_0c04fa2c: /* original 6af6, guest PC 0x0c04fa2c */
if(!s->budget--) { s->failed_pc=0x0c04fa2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04fa2e;
P_0c04fa2e: /* original 6bf6, guest PC 0x0c04fa2e */
if(!s->budget--) { s->failed_pc=0x0c04fa2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04fa30;
P_0c04fa30: /* original 6cf6, guest PC 0x0c04fa30 */
if(!s->budget--) { s->failed_pc=0x0c04fa30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04fa32;
P_0c04fa32: /* original 6df6, guest PC 0x0c04fa32 */
if(!s->budget--) { s->failed_pc=0x0c04fa32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04fa34;
P_0c04fa34: /* original 000b, guest PC 0x0c04fa34 */
if(!s->budget--) { s->failed_pc=0x0c04fa34u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04fa36: /* original 6ef6, guest PC 0x0c04fa36 */
if(!s->budget--) { s->failed_pc=0x0c04fa36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04fa38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04fa38u; return 0; } return 1;
P_0c04fa7c: /* original 9632, guest PC 0x0c04fa7c */
if(!s->budget--) { s->failed_pc=0x0c04fa7cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04fae4u,2);
goto P_0c04fa7e;
P_0c04fa7e: /* original 4f12, guest PC 0x0c04fa7e */
if(!s->budget--) { s->failed_pc=0x0c04fa7eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04fa80;
P_0c04fa80: /* original 246f, guest PC 0x0c04fa80 */
if(!s->budget--) { s->failed_pc=0x0c04fa80u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[6]);
goto P_0c04fa82;
P_0c04fa82: /* original d31b, guest PC 0x0c04fa82 */
if(!s->budget--) { s->failed_pc=0x0c04fa82u; return 0; }
r[3]=read(ram,0x0c04faf0u,4);
goto P_0c04fa84;
P_0c04fa84: /* original 061a, guest PC 0x0c04fa84 */
if(!s->budget--) { s->failed_pc=0x0c04fa84u; return 0; }
r[6]=r[19];
goto P_0c04fa86;
P_0c04fa86: /* original 666f, guest PC 0x0c04fa86 */
if(!s->budget--) { s->failed_pc=0x0c04fa86u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c04fa88;
P_0c04fa88: /* original 363c, guest PC 0x0c04fa88 */
if(!s->budget--) { s->failed_pc=0x0c04fa88u; return 0; }
r[6]+=r[3];
goto P_0c04fa8a;
P_0c04fa8a: /* original 556a, guest PC 0x0c04fa8a */
if(!s->budget--) { s->failed_pc=0x0c04fa8au; return 0; }
r[5]=read(ram,r[6]+40,4);
goto P_0c04fa8c;
P_0c04fa8c: /* original a009, guest PC 0x0c04fa8c */
if(!s->budget--) { s->failed_pc=0x0c04fa8cu; return 0; }
r[4]=0x00000000u;
return vf3_matrix_family(0x0c04faa2u,s,ram);
P_0c04fa8e: /* original e400, guest PC 0x0c04fa8e */
if(!s->budget--) { s->failed_pc=0x0c04fa8eu; return 0; }
r[4]=0x00000000u;
goto P_0c04fa90;
P_0c04fa90: /* original 6750, guest PC 0x0c04fa90 */
if(!s->budget--) { s->failed_pc=0x0c04fa90u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[7]=tmp;
goto P_0c04fa92;
P_0c04fa92: /* original 677c, guest PC 0x0c04fa92 */
if(!s->budget--) { s->failed_pc=0x0c04fa92u; return 0; }
r[7]=r[7]&255u;
goto P_0c04fa94;
P_0c04fa94: /* original 2778, guest PC 0x0c04fa94 */
if(!s->budget--) { s->failed_pc=0x0c04fa94u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c04fa96;
P_0c04fa96: /* original 8b02, guest PC 0x0c04fa96 */
if(!s->budget--) { s->failed_pc=0x0c04fa96u; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c04fa9eu,s,ram); }
goto P_0c04fa98;
P_0c04fa98: /* original 6043, guest PC 0x0c04fa98 */
if(!s->budget--) { s->failed_pc=0x0c04fa98u; return 0; }
r[0]=r[4];
goto P_0c04fa9a;
P_0c04fa9a: /* original 000b, guest PC 0x0c04fa9a */
if(!s->budget--) { s->failed_pc=0x0c04fa9au; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c04fa9c: /* original 4f16, guest PC 0x0c04fa9c */
if(!s->budget--) { s->failed_pc=0x0c04fa9cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c04fa9eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
