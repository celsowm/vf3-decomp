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
int vf3_away_batch43_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c07b6c4u: goto P_0c07b6c4;
case 0x0c07b6c6u: goto P_0c07b6c6;
case 0x0c07b6c8u: goto P_0c07b6c8;
case 0x0c07b6cau: goto P_0c07b6ca;
case 0x0c07b6ccu: goto P_0c07b6cc;
case 0x0c07b6ceu: goto P_0c07b6ce;
case 0x0c07b6d0u: goto P_0c07b6d0;
case 0x0c07b6d2u: goto P_0c07b6d2;
case 0x0c07b6d4u: goto P_0c07b6d4;
case 0x0c07b6d6u: goto P_0c07b6d6;
case 0x0c07b6d8u: goto P_0c07b6d8;
case 0x0c07b6dau: goto P_0c07b6da;
case 0x0c07b6dcu: goto P_0c07b6dc;
case 0x0c07b6deu: goto P_0c07b6de;
case 0x0c07b6e0u: goto P_0c07b6e0;
case 0x0c07b6e2u: goto P_0c07b6e2;
case 0x0c07b6e4u: goto P_0c07b6e4;
case 0x0c07b6e6u: goto P_0c07b6e6;
case 0x0c07b6e8u: goto P_0c07b6e8;
case 0x0c07b6eau: goto P_0c07b6ea;
case 0x0c07b6ecu: goto P_0c07b6ec;
case 0x0c07b6eeu: goto P_0c07b6ee;
case 0x0c07b6f0u: goto P_0c07b6f0;
case 0x0c07b6f2u: goto P_0c07b6f2;
case 0x0c07b6f4u: goto P_0c07b6f4;
case 0x0c07b6f6u: goto P_0c07b6f6;
case 0x0c07b6f8u: goto P_0c07b6f8;
case 0x0c07b6fau: goto P_0c07b6fa;
case 0x0c07b6fcu: goto P_0c07b6fc;
case 0x0c07b6feu: goto P_0c07b6fe;
case 0x0c07b700u: goto P_0c07b700;
case 0x0c07b702u: goto P_0c07b702;
case 0x0c07b704u: goto P_0c07b704;
case 0x0c07b706u: goto P_0c07b706;
case 0x0c07b708u: goto P_0c07b708;
case 0x0c07b70au: goto P_0c07b70a;
case 0x0c07b70cu: goto P_0c07b70c;
case 0x0c07b70eu: goto P_0c07b70e;
case 0x0c07b710u: goto P_0c07b710;
case 0x0c07b712u: goto P_0c07b712;
case 0x0c07b714u: goto P_0c07b714;
case 0x0c07b716u: goto P_0c07b716;
case 0x0c07b718u: goto P_0c07b718;
case 0x0c07b71au: goto P_0c07b71a;
case 0x0c07b870u: goto P_0c07b870;
case 0x0c07b872u: goto P_0c07b872;
case 0x0c07b874u: goto P_0c07b874;
case 0x0c07b876u: goto P_0c07b876;
case 0x0c07b878u: goto P_0c07b878;
case 0x0c07b87au: goto P_0c07b87a;
case 0x0c07b87cu: goto P_0c07b87c;
case 0x0c07b87eu: goto P_0c07b87e;
case 0x0c07b880u: goto P_0c07b880;
case 0x0c07b882u: goto P_0c07b882;
case 0x0c07b884u: goto P_0c07b884;
case 0x0c07b886u: goto P_0c07b886;
case 0x0c07b888u: goto P_0c07b888;
case 0x0c07b88au: goto P_0c07b88a;
case 0x0c07b88cu: goto P_0c07b88c;
case 0x0c07b88eu: goto P_0c07b88e;
case 0x0c07b890u: goto P_0c07b890;
case 0x0c07b892u: goto P_0c07b892;
case 0x0c07b894u: goto P_0c07b894;
case 0x0c07b896u: goto P_0c07b896;
case 0x0c07b898u: goto P_0c07b898;
case 0x0c07b89au: goto P_0c07b89a;
case 0x0c07b89cu: goto P_0c07b89c;
case 0x0c07b89eu: goto P_0c07b89e;
case 0x0c07b8a0u: goto P_0c07b8a0;
case 0x0c07b8a2u: goto P_0c07b8a2;
case 0x0c07b8a4u: goto P_0c07b8a4;
case 0x0c07b8a6u: goto P_0c07b8a6;
case 0x0c07b8a8u: goto P_0c07b8a8;
case 0x0c07b8aau: goto P_0c07b8aa;
case 0x0c07b8acu: goto P_0c07b8ac;
case 0x0c07b8aeu: goto P_0c07b8ae;
case 0x0c07b8b0u: goto P_0c07b8b0;
case 0x0c07b8b2u: goto P_0c07b8b2;
case 0x0c07b8b4u: goto P_0c07b8b4;
case 0x0c07b8b6u: goto P_0c07b8b6;
case 0x0c07b8b8u: goto P_0c07b8b8;
case 0x0c07b8bau: goto P_0c07b8ba;
case 0x0c07b8bcu: goto P_0c07b8bc;
case 0x0c07b8beu: goto P_0c07b8be;
case 0x0c07b8c0u: goto P_0c07b8c0;
case 0x0c07b8c2u: goto P_0c07b8c2;
case 0x0c07b8c4u: goto P_0c07b8c4;
case 0x0c07b8c6u: goto P_0c07b8c6;
case 0x0c07b8c8u: goto P_0c07b8c8;
case 0x0c07b8cau: goto P_0c07b8ca;
case 0x0c07b8ccu: goto P_0c07b8cc;
case 0x0c07b8ceu: goto P_0c07b8ce;
case 0x0c07b8d0u: goto P_0c07b8d0;
case 0x0c07b8d2u: goto P_0c07b8d2;
case 0x0c07b8d4u: goto P_0c07b8d4;
case 0x0c07b8d6u: goto P_0c07b8d6;
case 0x0c07b8d8u: goto P_0c07b8d8;
case 0x0c07b8dau: goto P_0c07b8da;
case 0x0c07b8dcu: goto P_0c07b8dc;
case 0x0c07b8deu: goto P_0c07b8de;
case 0x0c07b8e0u: goto P_0c07b8e0;
case 0x0c07b8e2u: goto P_0c07b8e2;
case 0x0c07b8e4u: goto P_0c07b8e4;
case 0x0c07b8e6u: goto P_0c07b8e6;
case 0x0c07b8e8u: goto P_0c07b8e8;
case 0x0c07b8eau: goto P_0c07b8ea;
case 0x0c07b8ecu: goto P_0c07b8ec;
case 0x0c07b8eeu: goto P_0c07b8ee;
case 0x0c07b8f0u: goto P_0c07b8f0;
case 0x0c07b8f2u: goto P_0c07b8f2;
case 0x0c07b8f4u: goto P_0c07b8f4;
case 0x0c07b8f6u: goto P_0c07b8f6;
case 0x0c07b8f8u: goto P_0c07b8f8;
case 0x0c07b8fau: goto P_0c07b8fa;
case 0x0c07b8fcu: goto P_0c07b8fc;
case 0x0c07b8feu: goto P_0c07b8fe;
case 0x0c07b900u: goto P_0c07b900;
case 0x0c07b902u: goto P_0c07b902;
case 0x0c07b904u: goto P_0c07b904;
case 0x0c07b906u: goto P_0c07b906;
case 0x0c07b908u: goto P_0c07b908;
case 0x0c07b90au: goto P_0c07b90a;
case 0x0c07b90cu: goto P_0c07b90c;
case 0x0c07b90eu: goto P_0c07b90e;
case 0x0c07b910u: goto P_0c07b910;
case 0x0c07b912u: goto P_0c07b912;
case 0x0c07b914u: goto P_0c07b914;
case 0x0c07b916u: goto P_0c07b916;
case 0x0c07b918u: goto P_0c07b918;
case 0x0c07b91au: goto P_0c07b91a;
case 0x0c07b91cu: goto P_0c07b91c;
case 0x0c07b91eu: goto P_0c07b91e;
case 0x0c07b920u: goto P_0c07b920;
case 0x0c07b922u: goto P_0c07b922;
case 0x0c07b924u: goto P_0c07b924;
case 0x0c07b926u: goto P_0c07b926;
case 0x0c07b928u: goto P_0c07b928;
case 0x0c07b92au: goto P_0c07b92a;
case 0x0c07b92cu: goto P_0c07b92c;
case 0x0c07b92eu: goto P_0c07b92e;
case 0x0c07b930u: goto P_0c07b930;
case 0x0c07b932u: goto P_0c07b932;
case 0x0c07b934u: goto P_0c07b934;
case 0x0c07b936u: goto P_0c07b936;
case 0x0c07b938u: goto P_0c07b938;
case 0x0c07b93au: goto P_0c07b93a;
case 0x0c07b93cu: goto P_0c07b93c;
case 0x0c07b93eu: goto P_0c07b93e;
case 0x0c07b940u: goto P_0c07b940;
case 0x0c07b942u: goto P_0c07b942;
case 0x0c07b944u: goto P_0c07b944;
case 0x0c07b946u: goto P_0c07b946;
case 0x0c07b948u: goto P_0c07b948;
case 0x0c07b94au: goto P_0c07b94a;
case 0x0c07b94cu: goto P_0c07b94c;
case 0x0c07b94eu: goto P_0c07b94e;
case 0x0c07b950u: goto P_0c07b950;
case 0x0c07b952u: goto P_0c07b952;
case 0x0c07b954u: goto P_0c07b954;
case 0x0c07b956u: goto P_0c07b956;
case 0x0c07b958u: goto P_0c07b958;
case 0x0c07b95au: goto P_0c07b95a;
case 0x0c07b95cu: goto P_0c07b95c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b606u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b622u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b62eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b648u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=code_base|0x0c07b64eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b658u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b66eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b66eu; return 0; } return 1;
P_0c07b6c4: /* original 4f22, guest PC 0x0c07b6c4 */
if(!s->budget--) { s->failed_pc=0x0c07b6c4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6c6;
P_0c07b6c6: /* original 7ffc, guest PC 0x0c07b6c6 */
if(!s->budget--) { s->failed_pc=0x0c07b6c6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b6c8;
P_0c07b6c8: /* original 2f72, guest PC 0x0c07b6c8 */
if(!s->budget--) { s->failed_pc=0x0c07b6c8u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c07b6ca;
P_0c07b6ca: /* original 53f2, guest PC 0x0c07b6ca */
if(!s->budget--) { s->failed_pc=0x0c07b6cau; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6cc;
P_0c07b6cc: /* original 2f36, guest PC 0x0c07b6cc */
if(!s->budget--) { s->failed_pc=0x0c07b6ccu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ce;
P_0c07b6ce: /* original 52f1, guest PC 0x0c07b6ce */
if(!s->budget--) { s->failed_pc=0x0c07b6ceu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07b6d0;
P_0c07b6d0: /* original 2f26, guest PC 0x0c07b6d0 */
if(!s->budget--) { s->failed_pc=0x0c07b6d0u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6d2;
P_0c07b6d2: /* original b004, guest PC 0x0c07b6d2 */
if(!s->budget--) { s->failed_pc=0x0c07b6d2u; return 0; }
target=code_base|0x0c07b6deu; r[16]=code_base|0x0c07b6d6u;
r[7]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6d6u) { target=s->pc; goto dispatch; }
goto P_0c07b6d6;
P_0c07b6d4: /* original e700, guest PC 0x0c07b6d4 */
if(!s->budget--) { s->failed_pc=0x0c07b6d4u; return 0; }
r[7]=0x00000000u;
goto P_0c07b6d6;
P_0c07b6d6: /* original 7f0c, guest PC 0x0c07b6d6 */
if(!s->budget--) { s->failed_pc=0x0c07b6d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c07b6d8;
P_0c07b6d8: /* original 4f26, guest PC 0x0c07b6d8 */
if(!s->budget--) { s->failed_pc=0x0c07b6d8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6da;
P_0c07b6da: /* original 000b, guest PC 0x0c07b6da */
if(!s->budget--) { s->failed_pc=0x0c07b6dau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6dc: /* original 0009, guest PC 0x0c07b6dc */
if(!s->budget--) { s->failed_pc=0x0c07b6dcu; return 0; }
goto P_0c07b6de;
P_0c07b6de: /* original 4f22, guest PC 0x0c07b6de */
if(!s->budget--) { s->failed_pc=0x0c07b6deu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6e0;
P_0c07b6e0: /* original 53f2, guest PC 0x0c07b6e0 */
if(!s->budget--) { s->failed_pc=0x0c07b6e0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07b6e2;
P_0c07b6e2: /* original 2f36, guest PC 0x0c07b6e2 */
if(!s->budget--) { s->failed_pc=0x0c07b6e2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6e4;
P_0c07b6e4: /* original d311, guest PC 0x0c07b6e4 */
if(!s->budget--) { s->failed_pc=0x0c07b6e4u; return 0; }
r[3]=read(ram,0x0c07b72cu,4);
goto P_0c07b6e6;
P_0c07b6e6: /* original 52f2, guest PC 0x0c07b6e6 */
if(!s->budget--) { s->failed_pc=0x0c07b6e6u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07b6e8;
P_0c07b6e8: /* original 430b, guest PC 0x0c07b6e8 */
if(!s->budget--) { s->failed_pc=0x0c07b6e8u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b6ecu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b6ecu) { target=s->pc; goto dispatch; }
goto P_0c07b6ec;
P_0c07b6ea: /* original 2f26, guest PC 0x0c07b6ea */
if(!s->budget--) { s->failed_pc=0x0c07b6eau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b6ec;
P_0c07b6ec: /* original 7f08, guest PC 0x0c07b6ec */
if(!s->budget--) { s->failed_pc=0x0c07b6ecu; return 0; }
r[15]+=0x00000008u;
goto P_0c07b6ee;
P_0c07b6ee: /* original 4f26, guest PC 0x0c07b6ee */
if(!s->budget--) { s->failed_pc=0x0c07b6eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b6f0;
P_0c07b6f0: /* original 000b, guest PC 0x0c07b6f0 */
if(!s->budget--) { s->failed_pc=0x0c07b6f0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b6f2: /* original 0009, guest PC 0x0c07b6f2 */
if(!s->budget--) { s->failed_pc=0x0c07b6f2u; return 0; }
goto P_0c07b6f4;
P_0c07b6f4: /* original 4f22, guest PC 0x0c07b6f4 */
if(!s->budget--) { s->failed_pc=0x0c07b6f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b6f6;
P_0c07b6f6: /* original 7ff4, guest PC 0x0c07b6f6 */
if(!s->budget--) { s->failed_pc=0x0c07b6f6u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c07b6f8;
P_0c07b6f8: /* original 2f42, guest PC 0x0c07b6f8 */
if(!s->budget--) { s->failed_pc=0x0c07b6f8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c07b6fa;
P_0c07b6fa: /* original 1f51, guest PC 0x0c07b6fa */
if(!s->budget--) { s->failed_pc=0x0c07b6fau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07b6fc;
P_0c07b6fc: /* original 1f72, guest PC 0x0c07b6fc */
if(!s->budget--) { s->failed_pc=0x0c07b6fcu; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c07b6fe;
P_0c07b6fe: /* original e700, guest PC 0x0c07b6fe */
if(!s->budget--) { s->failed_pc=0x0c07b6feu; return 0; }
r[7]=0x00000000u;
goto P_0c07b700;
P_0c07b700: /* original 53f4, guest PC 0x0c07b700 */
if(!s->budget--) { s->failed_pc=0x0c07b700u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c07b702;
P_0c07b702: /* original 2f36, guest PC 0x0c07b702 */
if(!s->budget--) { s->failed_pc=0x0c07b702u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b704;
P_0c07b704: /* original 52f3, guest PC 0x0c07b704 */
if(!s->budget--) { s->failed_pc=0x0c07b704u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07b706;
P_0c07b706: /* original 2f26, guest PC 0x0c07b706 */
if(!s->budget--) { s->failed_pc=0x0c07b706u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b708;
P_0c07b708: /* original 55f3, guest PC 0x0c07b708 */
if(!s->budget--) { s->failed_pc=0x0c07b708u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07b70a;
P_0c07b70a: /* original d309, guest PC 0x0c07b70a */
if(!s->budget--) { s->failed_pc=0x0c07b70au; return 0; }
r[3]=read(ram,0x0c07b730u,4);
goto P_0c07b70c;
P_0c07b70c: /* original d207, guest PC 0x0c07b70c */
if(!s->budget--) { s->failed_pc=0x0c07b70cu; return 0; }
r[2]=read(ram,0x0c07b72cu,4);
goto P_0c07b70e;
P_0c07b70e: /* original 253b, guest PC 0x0c07b70e */
if(!s->budget--) { s->failed_pc=0x0c07b70eu; return 0; }
r[5]|=r[3];
goto P_0c07b710;
P_0c07b710: /* original 420b, guest PC 0x0c07b710 */
if(!s->budget--) { s->failed_pc=0x0c07b710u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b714u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b714u) { target=s->pc; goto dispatch; }
goto P_0c07b714;
P_0c07b712: /* original 54f2, guest PC 0x0c07b712 */
if(!s->budget--) { s->failed_pc=0x0c07b712u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07b714;
P_0c07b714: /* original 7f14, guest PC 0x0c07b714 */
if(!s->budget--) { s->failed_pc=0x0c07b714u; return 0; }
r[15]+=0x00000014u;
goto P_0c07b716;
P_0c07b716: /* original 4f26, guest PC 0x0c07b716 */
if(!s->budget--) { s->failed_pc=0x0c07b716u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b718;
P_0c07b718: /* original 000b, guest PC 0x0c07b718 */
if(!s->budget--) { s->failed_pc=0x0c07b718u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07b71a: /* original 0009, guest PC 0x0c07b71a */
if(!s->budget--) { s->failed_pc=0x0c07b71au; return 0; }
if(!vf3_matrix_family(0x0c07b71cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b71cu; return 0; } return 1;
P_0c07b870: /* original 2fe6, guest PC 0x0c07b870 */
if(!s->budget--) { s->failed_pc=0x0c07b870u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b872;
P_0c07b872: /* original 2fd6, guest PC 0x0c07b872 */
if(!s->budget--) { s->failed_pc=0x0c07b872u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b874;
P_0c07b874: /* original 2fc6, guest PC 0x0c07b874 */
if(!s->budget--) { s->failed_pc=0x0c07b874u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b876;
P_0c07b876: /* original 2fb6, guest PC 0x0c07b876 */
if(!s->budget--) { s->failed_pc=0x0c07b876u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b878;
P_0c07b878: /* original 2fa6, guest PC 0x0c07b878 */
if(!s->budget--) { s->failed_pc=0x0c07b878u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b87a;
P_0c07b87a: /* original 2f96, guest PC 0x0c07b87a */
if(!s->budget--) { s->failed_pc=0x0c07b87au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b87c;
P_0c07b87c: /* original d538, guest PC 0x0c07b87c */
if(!s->budget--) { s->failed_pc=0x0c07b87cu; return 0; }
r[5]=read(ram,0x0c07b960u,4);
goto P_0c07b87e;
P_0c07b87e: /* original 9d6e, guest PC 0x0c07b87e */
if(!s->budget--) { s->failed_pc=0x0c07b87eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b95eu,2);
goto P_0c07b880;
P_0c07b880: /* original 845a, guest PC 0x0c07b880 */
if(!s->budget--) { s->failed_pc=0x0c07b880u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+10,1);
goto P_0c07b882;
P_0c07b882: /* original 4f22, guest PC 0x0c07b882 */
if(!s->budget--) { s->failed_pc=0x0c07b882u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b884;
P_0c07b884: /* original 600c, guest PC 0x0c07b884 */
if(!s->budget--) { s->failed_pc=0x0c07b884u; return 0; }
r[0]=r[0]&255u;
goto P_0c07b886;
P_0c07b886: /* original d437, guest PC 0x0c07b886 */
if(!s->budget--) { s->failed_pc=0x0c07b886u; return 0; }
r[4]=read(ram,0x0c07b964u,4);
goto P_0c07b888;
P_0c07b888: /* original 30d7, guest PC 0x0c07b888 */
if(!s->budget--) { s->failed_pc=0x0c07b888u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>(int32_t)r[13])!=0);
goto P_0c07b88a;
P_0c07b88a: /* original 8b07, guest PC 0x0c07b88a */
if(!s->budget--) { s->failed_pc=0x0c07b88au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b89c; }
goto P_0c07b88c;
P_0c07b88c: /* original d336, guest PC 0x0c07b88c */
if(!s->budget--) { s->failed_pc=0x0c07b88cu; return 0; }
r[3]=read(ram,0x0c07b968u,4);
goto P_0c07b88e;
P_0c07b88e: /* original 6230, guest PC 0x0c07b88e */
if(!s->budget--) { s->failed_pc=0x0c07b88eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c07b890;
P_0c07b890: /* original 622c, guest PC 0x0c07b890 */
if(!s->budget--) { s->failed_pc=0x0c07b890u; return 0; }
r[2]=r[2]&255u;
goto P_0c07b892;
P_0c07b892: /* original 32d3, guest PC 0x0c07b892 */
if(!s->budget--) { s->failed_pc=0x0c07b892u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[13])!=0);
goto P_0c07b894;
P_0c07b894: /* original 8902, guest PC 0x0c07b894 */
if(!s->budget--) { s->failed_pc=0x0c07b894u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b89c; }
goto P_0c07b896;
P_0c07b896: /* original 6042, guest PC 0x0c07b896 */
if(!s->budget--) { s->failed_pc=0x0c07b896u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c07b898;
P_0c07b898: /* original ca01, guest PC 0x0c07b898 */
if(!s->budget--) { s->failed_pc=0x0c07b898u; return 0; }
r[0]^=1u;
goto P_0c07b89a;
P_0c07b89a: /* original 2402, guest PC 0x0c07b89a */
if(!s->budget--) { s->failed_pc=0x0c07b89au; return 0; }
write(ram,r[4],r[0],4);
goto P_0c07b89c;
P_0c07b89c: /* original d332, guest PC 0x0c07b89c */
if(!s->budget--) { s->failed_pc=0x0c07b89cu; return 0; }
r[3]=read(ram,0x0c07b968u,4);
goto P_0c07b89e;
P_0c07b89e: /* original 845a, guest PC 0x0c07b89e */
if(!s->budget--) { s->failed_pc=0x0c07b89eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+10,1);
goto P_0c07b8a0;
P_0c07b8a0: /* original 2300, guest PC 0x0c07b8a0 */
if(!s->budget--) { s->failed_pc=0x0c07b8a0u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c07b8a2;
P_0c07b8a2: /* original 6242, guest PC 0x0c07b8a2 */
if(!s->budget--) { s->failed_pc=0x0c07b8a2u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c07b8a4;
P_0c07b8a4: /* original 2228, guest PC 0x0c07b8a4 */
if(!s->budget--) { s->failed_pc=0x0c07b8a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07b8a6;
P_0c07b8a6: /* original 8924, guest PC 0x0c07b8a6 */
if(!s->budget--) { s->failed_pc=0x0c07b8a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b8f2; }
goto P_0c07b8a8;
P_0c07b8a8: /* original d230, guest PC 0x0c07b8a8 */
if(!s->budget--) { s->failed_pc=0x0c07b8a8u; return 0; }
r[2]=read(ram,0x0c07b96cu,4);
goto P_0c07b8aa;
P_0c07b8aa: /* original d332, guest PC 0x0c07b8aa */
if(!s->budget--) { s->failed_pc=0x0c07b8aau; return 0; }
r[3]=read(ram,0x0c07b974u,4);
goto P_0c07b8ac;
P_0c07b8ac: /* original d130, guest PC 0x0c07b8ac */
if(!s->budget--) { s->failed_pc=0x0c07b8acu; return 0; }
r[1]=read(ram,0x0c07b970u,4);
goto P_0c07b8ae;
P_0c07b8ae: /* original 6522, guest PC 0x0c07b8ae */
if(!s->budget--) { s->failed_pc=0x0c07b8aeu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c07b8b0;
P_0c07b8b0: /* original 430b, guest PC 0x0c07b8b0 */
if(!s->budget--) { s->failed_pc=0x0c07b8b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b8b4u;
tmp=read(ram,r[1],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b8b4u) { target=s->pc; goto dispatch; }
goto P_0c07b8b4;
P_0c07b8b2: /* original 6412, guest PC 0x0c07b8b2 */
if(!s->budget--) { s->failed_pc=0x0c07b8b2u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c07b8b4;
P_0c07b8b4: /* original d22f, guest PC 0x0c07b8b4 */
if(!s->budget--) { s->failed_pc=0x0c07b8b4u; return 0; }
r[2]=read(ram,0x0c07b974u,4);
goto P_0c07b8b6;
P_0c07b8b6: /* original e506, guest PC 0x0c07b8b6 */
if(!s->budget--) { s->failed_pc=0x0c07b8b6u; return 0; }
r[5]=0x00000006u;
goto P_0c07b8b8;
P_0c07b8b8: /* original 420b, guest PC 0x0c07b8b8 */
if(!s->budget--) { s->failed_pc=0x0c07b8b8u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b8bcu;
r[4]=0x0000000bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b8bcu) { target=s->pc; goto dispatch; }
goto P_0c07b8bc;
P_0c07b8ba: /* original e40b, guest PC 0x0c07b8ba */
if(!s->budget--) { s->failed_pc=0x0c07b8bau; return 0; }
r[4]=0x0000000bu;
goto P_0c07b8bc;
P_0c07b8bc: /* original db30, guest PC 0x0c07b8bc */
if(!s->budget--) { s->failed_pc=0x0c07b8bcu; return 0; }
r[11]=read(ram,0x0c07b980u,4);
goto P_0c07b8be;
P_0c07b8be: /* original ee00, guest PC 0x0c07b8be */
if(!s->budget--) { s->failed_pc=0x0c07b8beu; return 0; }
r[14]=0x00000000u;
goto P_0c07b8c0;
P_0c07b8c0: /* original da2e, guest PC 0x0c07b8c0 */
if(!s->budget--) { s->failed_pc=0x0c07b8c0u; return 0; }
r[10]=read(ram,0x0c07b97cu,4);
goto P_0c07b8c2;
P_0c07b8c2: /* original d92d, guest PC 0x0c07b8c2 */
if(!s->budget--) { s->failed_pc=0x0c07b8c2u; return 0; }
r[9]=read(ram,0x0c07b978u,4);
goto P_0c07b8c4;
P_0c07b8c4: /* original 6ce3, guest PC 0x0c07b8c4 */
if(!s->budget--) { s->failed_pc=0x0c07b8c4u; return 0; }
r[12]=r[14];
goto P_0c07b8c6;
P_0c07b8c6: /* original 4c08, guest PC 0x0c07b8c6 */
if(!s->budget--) { s->failed_pc=0x0c07b8c6u; return 0; }
r[12]<<=2;
goto P_0c07b8c8;
P_0c07b8c8: /* original 4c08, guest PC 0x0c07b8c8 */
if(!s->budget--) { s->failed_pc=0x0c07b8c8u; return 0; }
r[12]<<=2;
goto P_0c07b8ca;
P_0c07b8ca: /* original 63e3, guest PC 0x0c07b8ca */
if(!s->budget--) { s->failed_pc=0x0c07b8cau; return 0; }
r[3]=r[14];
goto P_0c07b8cc;
P_0c07b8cc: /* original 4c08, guest PC 0x0c07b8cc */
if(!s->budget--) { s->failed_pc=0x0c07b8ccu; return 0; }
r[12]<<=2;
goto P_0c07b8ce;
P_0c07b8ce: /* original 3c3c, guest PC 0x0c07b8ce */
if(!s->budget--) { s->failed_pc=0x0c07b8ceu; return 0; }
r[12]+=r[3];
goto P_0c07b8d0;
P_0c07b8d0: /* original 4c00, guest PC 0x0c07b8d0 */
if(!s->budget--) { s->failed_pc=0x0c07b8d0u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c07b8d2;
P_0c07b8d2: /* original 6ccf, guest PC 0x0c07b8d2 */
if(!s->budget--) { s->failed_pc=0x0c07b8d2u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c07b8d4;
P_0c07b8d4: /* original 62c3, guest PC 0x0c07b8d4 */
if(!s->budget--) { s->failed_pc=0x0c07b8d4u; return 0; }
r[2]=r[12];
goto P_0c07b8d6;
P_0c07b8d6: /* original 32bc, guest PC 0x0c07b8d6 */
if(!s->budget--) { s->failed_pc=0x0c07b8d6u; return 0; }
r[2]+=r[11];
goto P_0c07b8d8;
P_0c07b8d8: /* original 6320, guest PC 0x0c07b8d8 */
if(!s->budget--) { s->failed_pc=0x0c07b8d8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[3]=tmp;
goto P_0c07b8da;
P_0c07b8da: /* original 2338, guest PC 0x0c07b8da */
if(!s->budget--) { s->failed_pc=0x0c07b8dau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07b8dc;
P_0c07b8dc: /* original 8906, guest PC 0x0c07b8dc */
if(!s->budget--) { s->failed_pc=0x0c07b8dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b8ec; }
goto P_0c07b8de;
P_0c07b8de: /* original 65e3, guest PC 0x0c07b8de */
if(!s->budget--) { s->failed_pc=0x0c07b8deu; return 0; }
r[5]=r[14];
goto P_0c07b8e0;
P_0c07b8e0: /* original 490b, guest PC 0x0c07b8e0 */
if(!s->budget--) { s->failed_pc=0x0c07b8e0u; return 0; }
target=r[9];
r[16]=code_base|0x0c07b8e4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b8e4u) { target=s->pc; goto dispatch; }
goto P_0c07b8e4;
P_0c07b8e2: /* original e400, guest PC 0x0c07b8e2 */
if(!s->budget--) { s->failed_pc=0x0c07b8e2u; return 0; }
r[4]=0x00000000u;
goto P_0c07b8e4;
P_0c07b8e4: /* original 64c3, guest PC 0x0c07b8e4 */
if(!s->budget--) { s->failed_pc=0x0c07b8e4u; return 0; }
r[4]=r[12];
goto P_0c07b8e6;
P_0c07b8e6: /* original 34bc, guest PC 0x0c07b8e6 */
if(!s->budget--) { s->failed_pc=0x0c07b8e6u; return 0; }
r[4]+=r[11];
goto P_0c07b8e8;
P_0c07b8e8: /* original 4a0b, guest PC 0x0c07b8e8 */
if(!s->budget--) { s->failed_pc=0x0c07b8e8u; return 0; }
target=r[10];
r[16]=code_base|0x0c07b8ecu;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b8ecu) { target=s->pc; goto dispatch; }
goto P_0c07b8ec;
P_0c07b8ea: /* original 7401, guest PC 0x0c07b8ea */
if(!s->budget--) { s->failed_pc=0x0c07b8eau; return 0; }
r[4]+=0x00000001u;
goto P_0c07b8ec;
P_0c07b8ec: /* original 7e01, guest PC 0x0c07b8ec */
if(!s->budget--) { s->failed_pc=0x0c07b8ecu; return 0; }
r[14]+=0x00000001u;
goto P_0c07b8ee;
P_0c07b8ee: /* original 3ed2, guest PC 0x0c07b8ee */
if(!s->budget--) { s->failed_pc=0x0c07b8eeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[13])!=0);
goto P_0c07b8f0;
P_0c07b8f0: /* original 8be8, guest PC 0x0c07b8f0 */
if(!s->budget--) { s->failed_pc=0x0c07b8f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b8c4; }
goto P_0c07b8f2;
P_0c07b8f2: /* original 4f26, guest PC 0x0c07b8f2 */
if(!s->budget--) { s->failed_pc=0x0c07b8f2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b8f4;
P_0c07b8f4: /* original 69f6, guest PC 0x0c07b8f4 */
if(!s->budget--) { s->failed_pc=0x0c07b8f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07b8f6;
P_0c07b8f6: /* original 6af6, guest PC 0x0c07b8f6 */
if(!s->budget--) { s->failed_pc=0x0c07b8f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b8f8;
P_0c07b8f8: /* original 6bf6, guest PC 0x0c07b8f8 */
if(!s->budget--) { s->failed_pc=0x0c07b8f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b8fa;
P_0c07b8fa: /* original 6cf6, guest PC 0x0c07b8fa */
if(!s->budget--) { s->failed_pc=0x0c07b8fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b8fc;
P_0c07b8fc: /* original 6df6, guest PC 0x0c07b8fc */
if(!s->budget--) { s->failed_pc=0x0c07b8fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b8fe;
P_0c07b8fe: /* original a000, guest PC 0x0c07b8fe */
if(!s->budget--) { s->failed_pc=0x0c07b8feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07b902;
P_0c07b900: /* original 6ef6, guest PC 0x0c07b900 */
if(!s->budget--) { s->failed_pc=0x0c07b900u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07b902;
P_0c07b902: /* original 2fc6, guest PC 0x0c07b902 */
if(!s->budget--) { s->failed_pc=0x0c07b902u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b904;
P_0c07b904: /* original ec20, guest PC 0x0c07b904 */
if(!s->budget--) { s->failed_pc=0x0c07b904u; return 0; }
r[12]=0x00000020u;
goto P_0c07b906;
P_0c07b906: /* original 2fb6, guest PC 0x0c07b906 */
if(!s->budget--) { s->failed_pc=0x0c07b906u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b908;
P_0c07b908: /* original 67c3, guest PC 0x0c07b908 */
if(!s->budget--) { s->failed_pc=0x0c07b908u; return 0; }
r[7]=r[12];
goto P_0c07b90a;
P_0c07b90a: /* original e400, guest PC 0x0c07b90a */
if(!s->budget--) { s->failed_pc=0x0c07b90au; return 0; }
r[4]=0x00000000u;
goto P_0c07b90c;
P_0c07b90c: /* original db1d, guest PC 0x0c07b90c */
if(!s->budget--) { s->failed_pc=0x0c07b90cu; return 0; }
r[11]=read(ram,0x0c07b984u,4);
goto P_0c07b90e;
P_0c07b90e: /* original d11c, guest PC 0x0c07b90e */
if(!s->budget--) { s->failed_pc=0x0c07b90eu; return 0; }
r[1]=read(ram,0x0c07b980u,4);
goto P_0c07b910;
P_0c07b910: /* original 6643, guest PC 0x0c07b910 */
if(!s->budget--) { s->failed_pc=0x0c07b910u; return 0; }
r[6]=r[4];
goto P_0c07b912;
P_0c07b912: /* original 7760, guest PC 0x0c07b912 */
if(!s->budget--) { s->failed_pc=0x0c07b912u; return 0; }
r[7]+=0x00000060u;
goto P_0c07b914;
P_0c07b914: /* original 6563, guest PC 0x0c07b914 */
if(!s->budget--) { s->failed_pc=0x0c07b914u; return 0; }
r[5]=r[6];
goto P_0c07b916;
P_0c07b916: /* original 4508, guest PC 0x0c07b916 */
if(!s->budget--) { s->failed_pc=0x0c07b916u; return 0; }
r[5]<<=2;
goto P_0c07b918;
P_0c07b918: /* original 4508, guest PC 0x0c07b918 */
if(!s->budget--) { s->failed_pc=0x0c07b918u; return 0; }
r[5]<<=2;
goto P_0c07b91a;
P_0c07b91a: /* original 6363, guest PC 0x0c07b91a */
if(!s->budget--) { s->failed_pc=0x0c07b91au; return 0; }
r[3]=r[6];
goto P_0c07b91c;
P_0c07b91c: /* original 4508, guest PC 0x0c07b91c */
if(!s->budget--) { s->failed_pc=0x0c07b91cu; return 0; }
r[5]<<=2;
goto P_0c07b91e;
P_0c07b91e: /* original 6043, guest PC 0x0c07b91e */
if(!s->budget--) { s->failed_pc=0x0c07b91eu; return 0; }
r[0]=r[4];
goto P_0c07b920;
P_0c07b920: /* original 353c, guest PC 0x0c07b920 */
if(!s->budget--) { s->failed_pc=0x0c07b920u; return 0; }
r[5]+=r[3];
goto P_0c07b922;
P_0c07b922: /* original 4500, guest PC 0x0c07b922 */
if(!s->budget--) { s->failed_pc=0x0c07b922u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b924;
P_0c07b924: /* original 655f, guest PC 0x0c07b924 */
if(!s->budget--) { s->failed_pc=0x0c07b924u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07b926;
P_0c07b926: /* original 351c, guest PC 0x0c07b926 */
if(!s->budget--) { s->failed_pc=0x0c07b926u; return 0; }
r[5]+=r[1];
goto P_0c07b928;
P_0c07b928: /* original 7501, guest PC 0x0c07b928 */
if(!s->budget--) { s->failed_pc=0x0c07b928u; return 0; }
r[5]+=0x00000001u;
goto P_0c07b92a;
P_0c07b92a: /* original 7001, guest PC 0x0c07b92a */
if(!s->budget--) { s->failed_pc=0x0c07b92au; return 0; }
r[0]+=0x00000001u;
goto P_0c07b92c;
P_0c07b92c: /* original 25c0, guest PC 0x0c07b92c */
if(!s->budget--) { s->failed_pc=0x0c07b92cu; return 0; }
write(ram,r[5],r[12],1);
goto P_0c07b92e;
P_0c07b92e: /* original 3073, guest PC 0x0c07b92e */
if(!s->budget--) { s->failed_pc=0x0c07b92eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[7])!=0);
goto P_0c07b930;
P_0c07b930: /* original 8ffb, guest PC 0x0c07b930 */
if(!s->budget--) { s->failed_pc=0x0c07b930u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000001u;
if(!cond) { goto P_0c07b92a; }
goto P_0c07b934;
P_0c07b932: /* original 7501, guest PC 0x0c07b932 */
if(!s->budget--) { s->failed_pc=0x0c07b932u; return 0; }
r[5]+=0x00000001u;
goto P_0c07b934;
P_0c07b934: /* original 6563, guest PC 0x0c07b934 */
if(!s->budget--) { s->failed_pc=0x0c07b934u; return 0; }
r[5]=r[6];
goto P_0c07b936;
P_0c07b936: /* original 4508, guest PC 0x0c07b936 */
if(!s->budget--) { s->failed_pc=0x0c07b936u; return 0; }
r[5]<<=2;
goto P_0c07b938;
P_0c07b938: /* original 4508, guest PC 0x0c07b938 */
if(!s->budget--) { s->failed_pc=0x0c07b938u; return 0; }
r[5]<<=2;
goto P_0c07b93a;
P_0c07b93a: /* original 6363, guest PC 0x0c07b93a */
if(!s->budget--) { s->failed_pc=0x0c07b93au; return 0; }
r[3]=r[6];
goto P_0c07b93c;
P_0c07b93c: /* original 4508, guest PC 0x0c07b93c */
if(!s->budget--) { s->failed_pc=0x0c07b93cu; return 0; }
r[5]<<=2;
goto P_0c07b93e;
P_0c07b93e: /* original 353c, guest PC 0x0c07b93e */
if(!s->budget--) { s->failed_pc=0x0c07b93eu; return 0; }
r[5]+=r[3];
goto P_0c07b940;
P_0c07b940: /* original 63b2, guest PC 0x0c07b940 */
if(!s->budget--) { s->failed_pc=0x0c07b940u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c07b942;
P_0c07b942: /* original 4500, guest PC 0x0c07b942 */
if(!s->budget--) { s->failed_pc=0x0c07b942u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07b944;
P_0c07b944: /* original 655f, guest PC 0x0c07b944 */
if(!s->budget--) { s->failed_pc=0x0c07b944u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c07b946;
P_0c07b946: /* original 351c, guest PC 0x0c07b946 */
if(!s->budget--) { s->failed_pc=0x0c07b946u; return 0; }
r[5]+=r[1];
goto P_0c07b948;
P_0c07b948: /* original 6253, guest PC 0x0c07b948 */
if(!s->budget--) { s->failed_pc=0x0c07b948u; return 0; }
r[2]=r[5];
goto P_0c07b94a;
P_0c07b94a: /* original 7201, guest PC 0x0c07b94a */
if(!s->budget--) { s->failed_pc=0x0c07b94au; return 0; }
r[2]+=0x00000001u;
goto P_0c07b94c;
P_0c07b94c: /* original 7601, guest PC 0x0c07b94c */
if(!s->budget--) { s->failed_pc=0x0c07b94cu; return 0; }
r[6]+=0x00000001u;
goto P_0c07b94e;
P_0c07b94e: /* original 323c, guest PC 0x0c07b94e */
if(!s->budget--) { s->failed_pc=0x0c07b94eu; return 0; }
r[2]+=r[3];
goto P_0c07b950;
P_0c07b950: /* original 3673, guest PC 0x0c07b950 */
if(!s->budget--) { s->failed_pc=0x0c07b950u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=(int32_t)r[7])!=0);
goto P_0c07b952;
P_0c07b952: /* original 2240, guest PC 0x0c07b952 */
if(!s->budget--) { s->failed_pc=0x0c07b952u; return 0; }
write(ram,r[2],r[4],1);
goto P_0c07b954;
P_0c07b954: /* original 8fde, guest PC 0x0c07b954 */
if(!s->budget--) { s->failed_pc=0x0c07b954u; return 0; }
cond=r[17]&1u;
write(ram,r[5],r[4],1);
if(!cond) { goto P_0c07b914; }
goto P_0c07b958;
P_0c07b956: /* original 2540, guest PC 0x0c07b956 */
if(!s->budget--) { s->failed_pc=0x0c07b956u; return 0; }
write(ram,r[5],r[4],1);
goto P_0c07b958;
P_0c07b958: /* original 6bf6, guest PC 0x0c07b958 */
if(!s->budget--) { s->failed_pc=0x0c07b958u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b95a;
P_0c07b95a: /* original 000b, guest PC 0x0c07b95a */
if(!s->budget--) { s->failed_pc=0x0c07b95au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b95c: /* original 6cf6, guest PC 0x0c07b95c */
if(!s->budget--) { s->failed_pc=0x0c07b95cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
if(!vf3_matrix_family(0x0c07b95eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b95eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
