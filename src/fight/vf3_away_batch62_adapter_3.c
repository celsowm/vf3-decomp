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
int vf3_away_batch62_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08d8d8u: goto P_0c08d8d8;
case 0x0c08d8dau: goto P_0c08d8da;
case 0x0c08d8dcu: goto P_0c08d8dc;
case 0x0c08d8deu: goto P_0c08d8de;
case 0x0c08d8e0u: goto P_0c08d8e0;
case 0x0c08d8e2u: goto P_0c08d8e2;
case 0x0c08d8e4u: goto P_0c08d8e4;
case 0x0c08d8e6u: goto P_0c08d8e6;
case 0x0c08d8e8u: goto P_0c08d8e8;
case 0x0c08d8eau: goto P_0c08d8ea;
case 0x0c08d8ecu: goto P_0c08d8ec;
case 0x0c08d8eeu: goto P_0c08d8ee;
case 0x0c08d8f0u: goto P_0c08d8f0;
case 0x0c08d8f2u: goto P_0c08d8f2;
case 0x0c08d8f4u: goto P_0c08d8f4;
case 0x0c08d8f6u: goto P_0c08d8f6;
case 0x0c08d8f8u: goto P_0c08d8f8;
case 0x0c08d8fau: goto P_0c08d8fa;
case 0x0c08d8fcu: goto P_0c08d8fc;
case 0x0c08d8feu: goto P_0c08d8fe;
case 0x0c08d900u: goto P_0c08d900;
case 0x0c08d902u: goto P_0c08d902;
case 0x0c08d904u: goto P_0c08d904;
case 0x0c08d906u: goto P_0c08d906;
case 0x0c08d908u: goto P_0c08d908;
case 0x0c08d90au: goto P_0c08d90a;
case 0x0c08d90cu: goto P_0c08d90c;
case 0x0c08d90eu: goto P_0c08d90e;
case 0x0c08d910u: goto P_0c08d910;
case 0x0c08d912u: goto P_0c08d912;
case 0x0c08d914u: goto P_0c08d914;
case 0x0c08d916u: goto P_0c08d916;
case 0x0c08d918u: goto P_0c08d918;
case 0x0c08d91au: goto P_0c08d91a;
case 0x0c08d91cu: goto P_0c08d91c;
case 0x0c08d91eu: goto P_0c08d91e;
case 0x0c08d920u: goto P_0c08d920;
case 0x0c08d922u: goto P_0c08d922;
case 0x0c08d924u: goto P_0c08d924;
case 0x0c08d926u: goto P_0c08d926;
case 0x0c08d928u: goto P_0c08d928;
case 0x0c08d92au: goto P_0c08d92a;
case 0x0c08d92cu: goto P_0c08d92c;
case 0x0c08d92eu: goto P_0c08d92e;
case 0x0c08d930u: goto P_0c08d930;
case 0x0c08d932u: goto P_0c08d932;
case 0x0c08d934u: goto P_0c08d934;
case 0x0c08d936u: goto P_0c08d936;
case 0x0c08d938u: goto P_0c08d938;
case 0x0c08d93au: goto P_0c08d93a;
case 0x0c08d93cu: goto P_0c08d93c;
case 0x0c08d93eu: goto P_0c08d93e;
case 0x0c08d940u: goto P_0c08d940;
case 0x0c08d942u: goto P_0c08d942;
case 0x0c08d944u: goto P_0c08d944;
case 0x0c08d946u: goto P_0c08d946;
case 0x0c08d948u: goto P_0c08d948;
case 0x0c08d94au: goto P_0c08d94a;
case 0x0c08d94cu: goto P_0c08d94c;
case 0x0c08d94eu: goto P_0c08d94e;
case 0x0c08d950u: goto P_0c08d950;
case 0x0c08d952u: goto P_0c08d952;
case 0x0c08d954u: goto P_0c08d954;
case 0x0c08d956u: goto P_0c08d956;
case 0x0c08d990u: goto P_0c08d990;
case 0x0c08d992u: goto P_0c08d992;
case 0x0c08d994u: goto P_0c08d994;
case 0x0c08d996u: goto P_0c08d996;
case 0x0c08d998u: goto P_0c08d998;
case 0x0c08d99au: goto P_0c08d99a;
case 0x0c08d99cu: goto P_0c08d99c;
case 0x0c08d99eu: goto P_0c08d99e;
case 0x0c08d9a0u: goto P_0c08d9a0;
case 0x0c08d9a2u: goto P_0c08d9a2;
case 0x0c08d9a4u: goto P_0c08d9a4;
case 0x0c08d9a6u: goto P_0c08d9a6;
case 0x0c08d9a8u: goto P_0c08d9a8;
case 0x0c08d9aau: goto P_0c08d9aa;
case 0x0c08d9acu: goto P_0c08d9ac;
case 0x0c08d9aeu: goto P_0c08d9ae;
case 0x0c08d9b0u: goto P_0c08d9b0;
case 0x0c08d9b2u: goto P_0c08d9b2;
case 0x0c08d9b4u: goto P_0c08d9b4;
case 0x0c08d9b6u: goto P_0c08d9b6;
case 0x0c08d9b8u: goto P_0c08d9b8;
case 0x0c08d9bau: goto P_0c08d9ba;
case 0x0c08d9bcu: goto P_0c08d9bc;
case 0x0c08d9beu: goto P_0c08d9be;
case 0x0c08d9c0u: goto P_0c08d9c0;
case 0x0c08d9c2u: goto P_0c08d9c2;
case 0x0c08d9c4u: goto P_0c08d9c4;
case 0x0c08d9c6u: goto P_0c08d9c6;
case 0x0c08d9c8u: goto P_0c08d9c8;
case 0x0c08d9cau: goto P_0c08d9ca;
case 0x0c08d9ccu: goto P_0c08d9cc;
case 0x0c08d9ceu: goto P_0c08d9ce;
case 0x0c08d9d0u: goto P_0c08d9d0;
case 0x0c08d9d2u: goto P_0c08d9d2;
case 0x0c08d9d4u: goto P_0c08d9d4;
case 0x0c08d9d6u: goto P_0c08d9d6;
case 0x0c08d9d8u: goto P_0c08d9d8;
case 0x0c08d9dau: goto P_0c08d9da;
case 0x0c08d9dcu: goto P_0c08d9dc;
case 0x0c08d9deu: goto P_0c08d9de;
case 0x0c08d9e0u: goto P_0c08d9e0;
case 0x0c08d9e2u: goto P_0c08d9e2;
case 0x0c08d9e4u: goto P_0c08d9e4;
case 0x0c08d9e6u: goto P_0c08d9e6;
case 0x0c08d9e8u: goto P_0c08d9e8;
case 0x0c08d9eau: goto P_0c08d9ea;
case 0x0c08d9ecu: goto P_0c08d9ec;
case 0x0c08d9eeu: goto P_0c08d9ee;
case 0x0c08d9f0u: goto P_0c08d9f0;
case 0x0c08d9f2u: goto P_0c08d9f2;
case 0x0c08d9f4u: goto P_0c08d9f4;
case 0x0c08d9f6u: goto P_0c08d9f6;
case 0x0c08d9f8u: goto P_0c08d9f8;
case 0x0c08d9fau: goto P_0c08d9fa;
case 0x0c08d9fcu: goto P_0c08d9fc;
case 0x0c08d9feu: goto P_0c08d9fe;
case 0x0c08da00u: goto P_0c08da00;
case 0x0c08da02u: goto P_0c08da02;
case 0x0c08da04u: goto P_0c08da04;
case 0x0c08da06u: goto P_0c08da06;
case 0x0c08da08u: goto P_0c08da08;
case 0x0c08da0au: goto P_0c08da0a;
case 0x0c08da0cu: goto P_0c08da0c;
case 0x0c08da0eu: goto P_0c08da0e;
case 0x0c08da10u: goto P_0c08da10;
case 0x0c08da12u: goto P_0c08da12;
case 0x0c08da14u: goto P_0c08da14;
case 0x0c08da16u: goto P_0c08da16;
case 0x0c08da18u: goto P_0c08da18;
case 0x0c08da1au: goto P_0c08da1a;
case 0x0c08da1cu: goto P_0c08da1c;
case 0x0c08da1eu: goto P_0c08da1e;
case 0x0c08da20u: goto P_0c08da20;
case 0x0c08da22u: goto P_0c08da22;
case 0x0c08da24u: goto P_0c08da24;
case 0x0c08da26u: goto P_0c08da26;
case 0x0c08da28u: goto P_0c08da28;
case 0x0c08da2au: goto P_0c08da2a;
case 0x0c08da2cu: goto P_0c08da2c;
case 0x0c08da2eu: goto P_0c08da2e;
case 0x0c08da30u: goto P_0c08da30;
case 0x0c08da32u: goto P_0c08da32;
case 0x0c08da34u: goto P_0c08da34;
case 0x0c08da36u: goto P_0c08da36;
case 0x0c08da38u: goto P_0c08da38;
case 0x0c08da3au: goto P_0c08da3a;
case 0x0c08da3cu: goto P_0c08da3c;
case 0x0c08da3eu: goto P_0c08da3e;
case 0x0c08da40u: goto P_0c08da40;
case 0x0c08da42u: goto P_0c08da42;
case 0x0c08da44u: goto P_0c08da44;
case 0x0c08da46u: goto P_0c08da46;
case 0x0c08da48u: goto P_0c08da48;
case 0x0c08da4au: goto P_0c08da4a;
case 0x0c08da4cu: goto P_0c08da4c;
case 0x0c08da4eu: goto P_0c08da4e;
case 0x0c08da50u: goto P_0c08da50;
case 0x0c08da52u: goto P_0c08da52;
case 0x0c08da54u: goto P_0c08da54;
case 0x0c08da56u: goto P_0c08da56;
case 0x0c08da58u: goto P_0c08da58;
case 0x0c08da5au: goto P_0c08da5a;
case 0x0c08da5cu: goto P_0c08da5c;
case 0x0c08da5eu: goto P_0c08da5e;
case 0x0c08da60u: goto P_0c08da60;
case 0x0c08da62u: goto P_0c08da62;
case 0x0c08da64u: goto P_0c08da64;
case 0x0c08da66u: goto P_0c08da66;
case 0x0c08da68u: goto P_0c08da68;
case 0x0c08da6au: goto P_0c08da6a;
case 0x0c08da6cu: goto P_0c08da6c;
case 0x0c08da6eu: goto P_0c08da6e;
case 0x0c08da70u: goto P_0c08da70;
case 0x0c08da72u: goto P_0c08da72;
case 0x0c08da74u: goto P_0c08da74;
case 0x0c08da76u: goto P_0c08da76;
case 0x0c08da78u: goto P_0c08da78;
case 0x0c08da7au: goto P_0c08da7a;
case 0x0c08da7cu: goto P_0c08da7c;
case 0x0c08da7eu: goto P_0c08da7e;
case 0x0c08da80u: goto P_0c08da80;
case 0x0c08da82u: goto P_0c08da82;
case 0x0c08da84u: goto P_0c08da84;
case 0x0c08da86u: goto P_0c08da86;
case 0x0c08da88u: goto P_0c08da88;
case 0x0c08da8au: goto P_0c08da8a;
case 0x0c08da8cu: goto P_0c08da8c;
case 0x0c08da8eu: goto P_0c08da8e;
case 0x0c08da90u: goto P_0c08da90;
case 0x0c08da92u: goto P_0c08da92;
case 0x0c08da94u: goto P_0c08da94;
case 0x0c08da96u: goto P_0c08da96;
case 0x0c08da98u: goto P_0c08da98;
case 0x0c08da9au: goto P_0c08da9a;
case 0x0c08da9cu: goto P_0c08da9c;
case 0x0c08da9eu: goto P_0c08da9e;
case 0x0c08daa0u: goto P_0c08daa0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08d8d8: /* original 2fe6, guest PC 0x0c08d8d8 */
if(!s->budget--) { s->failed_pc=0x0c08d8d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d8da;
P_0c08d8da: /* original 6e43, guest PC 0x0c08d8da */
if(!s->budget--) { s->failed_pc=0x0c08d8dau; return 0; }
r[14]=r[4];
goto P_0c08d8dc;
P_0c08d8dc: /* original 2fd6, guest PC 0x0c08d8dc */
if(!s->budget--) { s->failed_pc=0x0c08d8dcu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d8de;
P_0c08d8de: /* original 6d53, guest PC 0x0c08d8de */
if(!s->budget--) { s->failed_pc=0x0c08d8deu; return 0; }
r[13]=r[5];
goto P_0c08d8e0;
P_0c08d8e0: /* original 4f22, guest PC 0x0c08d8e0 */
if(!s->budget--) { s->failed_pc=0x0c08d8e0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d8e2;
P_0c08d8e2: /* original d323, guest PC 0x0c08d8e2 */
if(!s->budget--) { s->failed_pc=0x0c08d8e2u; return 0; }
r[3]=read(ram,0x0c08d970u,4);
goto P_0c08d8e4;
P_0c08d8e4: /* original 7ffc, guest PC 0x0c08d8e4 */
if(!s->budget--) { s->failed_pc=0x0c08d8e4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c08d8e6;
P_0c08d8e6: /* original 430b, guest PC 0x0c08d8e6 */
if(!s->budget--) { s->failed_pc=0x0c08d8e6u; return 0; }
target=r[3];
r[16]=code_base|0x0c08d8eau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d8eau) { target=s->pc; goto dispatch; }
goto P_0c08d8ea;
P_0c08d8e8: /* original e400, guest PC 0x0c08d8e8 */
if(!s->budget--) { s->failed_pc=0x0c08d8e8u; return 0; }
r[4]=0x00000000u;
goto P_0c08d8ea;
P_0c08d8ea: /* original d222, guest PC 0x0c08d8ea */
if(!s->budget--) { s->failed_pc=0x0c08d8eau; return 0; }
r[2]=read(ram,0x0c08d974u,4);
goto P_0c08d8ec;
P_0c08d8ec: /* original 9434, guest PC 0x0c08d8ec */
if(!s->budget--) { s->failed_pc=0x0c08d8ecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d958u,2);
goto P_0c08d8ee;
P_0c08d8ee: /* original 420b, guest PC 0x0c08d8ee */
if(!s->budget--) { s->failed_pc=0x0c08d8eeu; return 0; }
target=r[2];
r[16]=code_base|0x0c08d8f2u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d8f2u) { target=s->pc; goto dispatch; }
goto P_0c08d8f2;
P_0c08d8f0: /* original 34ec, guest PC 0x0c08d8f0 */
if(!s->budget--) { s->failed_pc=0x0c08d8f0u; return 0; }
r[4]+=r[14];
goto P_0c08d8f2;
P_0c08d8f2: /* original d122, guest PC 0x0c08d8f2 */
if(!s->budget--) { s->failed_pc=0x0c08d8f2u; return 0; }
r[1]=read(ram,0x0c08d97cu,4);
goto P_0c08d8f4;
P_0c08d8f4: /* original d320, guest PC 0x0c08d8f4 */
if(!s->budget--) { s->failed_pc=0x0c08d8f4u; return 0; }
r[3]=read(ram,0x0c08d978u,4);
goto P_0c08d8f6;
P_0c08d8f6: /* original 6212, guest PC 0x0c08d8f6 */
if(!s->budget--) { s->failed_pc=0x0c08d8f6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c08d8f8;
P_0c08d8f8: /* original 2238, guest PC 0x0c08d8f8 */
if(!s->budget--) { s->failed_pc=0x0c08d8f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08d8fa;
P_0c08d8fa: /* original 8b19, guest PC 0x0c08d8fa */
if(!s->budget--) { s->failed_pc=0x0c08d8fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d930; }
goto P_0c08d8fc;
P_0c08d8fc: /* original d418, guest PC 0x0c08d8fc */
if(!s->budget--) { s->failed_pc=0x0c08d8fcu; return 0; }
r[4]=read(ram,0x0c08d960u,4);
goto P_0c08d8fe;
P_0c08d8fe: /* original d320, guest PC 0x0c08d8fe */
if(!s->budget--) { s->failed_pc=0x0c08d8feu; return 0; }
r[3]=read(ram,0x0c08d980u,4);
goto P_0c08d900;
P_0c08d900: /* original 6542, guest PC 0x0c08d900 */
if(!s->budget--) { s->failed_pc=0x0c08d900u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c08d902;
P_0c08d902: /* original 8449, guest PC 0x0c08d902 */
if(!s->budget--) { s->failed_pc=0x0c08d902u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c08d904;
P_0c08d904: /* original 2358, guest PC 0x0c08d904 */
if(!s->budget--) { s->failed_pc=0x0c08d904u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c08d906;
P_0c08d906: /* original 8d06, guest PC 0x0c08d906 */
if(!s->budget--) { s->failed_pc=0x0c08d906u; return 0; }
cond=r[17]&1u;
r[6]=r[0]&255u;
if(cond) { goto P_0c08d916; }
goto P_0c08d90a;
P_0c08d908: /* original 660c, guest PC 0x0c08d908 */
if(!s->budget--) { s->failed_pc=0x0c08d908u; return 0; }
r[6]=r[0]&255u;
goto P_0c08d90a;
P_0c08d90a: /* original d31e, guest PC 0x0c08d90a */
if(!s->budget--) { s->failed_pc=0x0c08d90au; return 0; }
r[3]=read(ram,0x0c08d984u,4);
goto P_0c08d90c;
P_0c08d90c: /* original 5441, guest PC 0x0c08d90c */
if(!s->budget--) { s->failed_pc=0x0c08d90cu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c08d90e;
P_0c08d90e: /* original 2438, guest PC 0x0c08d90e */
if(!s->budget--) { s->failed_pc=0x0c08d90eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d910;
P_0c08d910: /* original 8b13, guest PC 0x0c08d910 */
if(!s->budget--) { s->failed_pc=0x0c08d910u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d93a; }
goto P_0c08d912;
P_0c08d912: /* original a044, guest PC 0x0c08d912 */
if(!s->budget--) { s->failed_pc=0x0c08d912u; return 0; }
goto P_0c08d99e;
P_0c08d914: /* original 0009, guest PC 0x0c08d914 */
if(!s->budget--) { s->failed_pc=0x0c08d914u; return 0; }
goto P_0c08d916;
P_0c08d916: /* original d71c, guest PC 0x0c08d916 */
if(!s->budget--) { s->failed_pc=0x0c08d916u; return 0; }
r[7]=read(ram,0x0c08d988u,4);
goto P_0c08d918;
P_0c08d918: /* original 2578, guest PC 0x0c08d918 */
if(!s->budget--) { s->failed_pc=0x0c08d918u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[7])==0)!=0);
goto P_0c08d91a;
P_0c08d91a: /* original 8939, guest PC 0x0c08d91a */
if(!s->budget--) { s->failed_pc=0x0c08d91au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d990; }
goto P_0c08d91c;
P_0c08d91c: /* original 6063, guest PC 0x0c08d91c */
if(!s->budget--) { s->failed_pc=0x0c08d91cu; return 0; }
r[0]=r[6];
goto P_0c08d91e;
P_0c08d91e: /* original 880e, guest PC 0x0c08d91e */
if(!s->budget--) { s->failed_pc=0x0c08d91eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c08d920;
P_0c08d920: /* original 8b04, guest PC 0x0c08d920 */
if(!s->budget--) { s->failed_pc=0x0c08d920u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d92c; }
goto P_0c08d922;
P_0c08d922: /* original 65d3, guest PC 0x0c08d922 */
if(!s->budget--) { s->failed_pc=0x0c08d922u; return 0; }
r[5]=r[13];
goto P_0c08d924;
P_0c08d924: /* original b04d, guest PC 0x0c08d924 */
if(!s->budget--) { s->failed_pc=0x0c08d924u; return 0; }
target=code_base|0x0c08d9c2u; r[16]=code_base|0x0c08d928u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d928u) { target=s->pc; goto dispatch; }
goto P_0c08d928;
P_0c08d926: /* original 64e3, guest PC 0x0c08d926 */
if(!s->budget--) { s->failed_pc=0x0c08d926u; return 0; }
r[4]=r[14];
goto P_0c08d928;
P_0c08d928: /* original a044, guest PC 0x0c08d928 */
if(!s->budget--) { s->failed_pc=0x0c08d928u; return 0; }
goto P_0c08d9b4;
P_0c08d92a: /* original 0009, guest PC 0x0c08d92a */
if(!s->budget--) { s->failed_pc=0x0c08d92au; return 0; }
goto P_0c08d92c;
P_0c08d92c: /* original 880f, guest PC 0x0c08d92c */
if(!s->budget--) { s->failed_pc=0x0c08d92cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c08d92e;
P_0c08d92e: /* original 8b04, guest PC 0x0c08d92e */
if(!s->budget--) { s->failed_pc=0x0c08d92eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d93a; }
goto P_0c08d930;
P_0c08d930: /* original 65d3, guest PC 0x0c08d930 */
if(!s->budget--) { s->failed_pc=0x0c08d930u; return 0; }
r[5]=r[13];
goto P_0c08d932;
P_0c08d932: /* original b0b6, guest PC 0x0c08d932 */
if(!s->budget--) { s->failed_pc=0x0c08d932u; return 0; }
target=code_base|0x0c08daa2u; r[16]=code_base|0x0c08d936u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d936u) { target=s->pc; goto dispatch; }
goto P_0c08d936;
P_0c08d934: /* original 64e3, guest PC 0x0c08d934 */
if(!s->budget--) { s->failed_pc=0x0c08d934u; return 0; }
r[4]=r[14];
goto P_0c08d936;
P_0c08d936: /* original a03d, guest PC 0x0c08d936 */
if(!s->budget--) { s->failed_pc=0x0c08d936u; return 0; }
goto P_0c08d9b4;
P_0c08d938: /* original 0009, guest PC 0x0c08d938 */
if(!s->budget--) { s->failed_pc=0x0c08d938u; return 0; }
goto P_0c08d93a;
P_0c08d93a: /* original e048, guest PC 0x0c08d93a */
if(!s->budget--) { s->failed_pc=0x0c08d93au; return 0; }
r[0]=0x00000048u;
goto P_0c08d93c;
P_0c08d93c: /* original d313, guest PC 0x0c08d93c */
if(!s->budget--) { s->failed_pc=0x0c08d93cu; return 0; }
r[3]=read(ram,0x0c08d98cu,4);
goto P_0c08d93e;
P_0c08d93e: /* original 04ee, guest PC 0x0c08d93e */
if(!s->budget--) { s->failed_pc=0x0c08d93eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08d940;
P_0c08d940: /* original 2438, guest PC 0x0c08d940 */
if(!s->budget--) { s->failed_pc=0x0c08d940u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d942;
P_0c08d942: /* original 8904, guest PC 0x0c08d942 */
if(!s->budget--) { s->failed_pc=0x0c08d942u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d94e; }
goto P_0c08d944;
P_0c08d944: /* original 65d3, guest PC 0x0c08d944 */
if(!s->budget--) { s->failed_pc=0x0c08d944u; return 0; }
r[5]=r[13];
goto P_0c08d946;
P_0c08d946: /* original b055, guest PC 0x0c08d946 */
if(!s->budget--) { s->failed_pc=0x0c08d946u; return 0; }
target=code_base|0x0c08d9f4u; r[16]=code_base|0x0c08d94au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d94au) { target=s->pc; goto dispatch; }
goto P_0c08d94a;
P_0c08d948: /* original 64e3, guest PC 0x0c08d948 */
if(!s->budget--) { s->failed_pc=0x0c08d948u; return 0; }
r[4]=r[14];
goto P_0c08d94a;
P_0c08d94a: /* original a033, guest PC 0x0c08d94a */
if(!s->budget--) { s->failed_pc=0x0c08d94au; return 0; }
goto P_0c08d9b4;
P_0c08d94c: /* original 0009, guest PC 0x0c08d94c */
if(!s->budget--) { s->failed_pc=0x0c08d94cu; return 0; }
goto P_0c08d94e;
P_0c08d94e: /* original 65d3, guest PC 0x0c08d94e */
if(!s->budget--) { s->failed_pc=0x0c08d94eu; return 0; }
r[5]=r[13];
goto P_0c08d950;
P_0c08d950: /* original b0d0, guest PC 0x0c08d950 */
if(!s->budget--) { s->failed_pc=0x0c08d950u; return 0; }
target=code_base|0x0c08daf4u; r[16]=code_base|0x0c08d954u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d954u) { target=s->pc; goto dispatch; }
goto P_0c08d954;
P_0c08d952: /* original 64e3, guest PC 0x0c08d952 */
if(!s->budget--) { s->failed_pc=0x0c08d952u; return 0; }
r[4]=r[14];
goto P_0c08d954;
P_0c08d954: /* original a02e, guest PC 0x0c08d954 */
if(!s->budget--) { s->failed_pc=0x0c08d954u; return 0; }
goto P_0c08d9b4;
P_0c08d956: /* original 0009, guest PC 0x0c08d956 */
if(!s->budget--) { s->failed_pc=0x0c08d956u; return 0; }
if(!vf3_matrix_family(0x0c08d958u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d958u; return 0; } return 1;
P_0c08d990: /* original d355, guest PC 0x0c08d990 */
if(!s->budget--) { s->failed_pc=0x0c08d990u; return 0; }
r[3]=read(ram,0x0c08dae8u,4);
goto P_0c08d992;
P_0c08d992: /* original 6442, guest PC 0x0c08d992 */
if(!s->budget--) { s->failed_pc=0x0c08d992u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c08d994;
P_0c08d994: /* original 2438, guest PC 0x0c08d994 */
if(!s->budget--) { s->failed_pc=0x0c08d994u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d996;
P_0c08d996: /* original 8902, guest PC 0x0c08d996 */
if(!s->budget--) { s->failed_pc=0x0c08d996u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d99e; }
goto P_0c08d998;
P_0c08d998: /* original 909f, guest PC 0x0c08d998 */
if(!s->budget--) { s->failed_pc=0x0c08d998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadau,2);
goto P_0c08d99a;
P_0c08d99a: /* original e200, guest PC 0x0c08d99a */
if(!s->budget--) { s->failed_pc=0x0c08d99au; return 0; }
r[2]=0x00000000u;
goto P_0c08d99c;
P_0c08d99c: /* original 0e24, guest PC 0x0c08d99c */
if(!s->budget--) { s->failed_pc=0x0c08d99cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08d99e;
P_0c08d99e: /* original 909c, guest PC 0x0c08d99e */
if(!s->budget--) { s->failed_pc=0x0c08d99eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadau,2);
goto P_0c08d9a0;
P_0c08d9a0: /* original 65d3, guest PC 0x0c08d9a0 */
if(!s->budget--) { s->failed_pc=0x0c08d9a0u; return 0; }
r[5]=r[13];
goto P_0c08d9a2;
P_0c08d9a2: /* original 03ec, guest PC 0x0c08d9a2 */
if(!s->budget--) { s->failed_pc=0x0c08d9a2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08d9a4;
P_0c08d9a4: /* original d051, guest PC 0x0c08d9a4 */
if(!s->budget--) { s->failed_pc=0x0c08d9a4u; return 0; }
r[0]=read(ram,0x0c08daecu,4);
goto P_0c08d9a6;
P_0c08d9a6: /* original 633c, guest PC 0x0c08d9a6 */
if(!s->budget--) { s->failed_pc=0x0c08d9a6u; return 0; }
r[3]=r[3]&255u;
goto P_0c08d9a8;
P_0c08d9a8: /* original 4308, guest PC 0x0c08d9a8 */
if(!s->budget--) { s->failed_pc=0x0c08d9a8u; return 0; }
r[3]<<=2;
goto P_0c08d9aa;
P_0c08d9aa: /* original 023e, guest PC 0x0c08d9aa */
if(!s->budget--) { s->failed_pc=0x0c08d9aau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c08d9ac;
P_0c08d9ac: /* original 6323, guest PC 0x0c08d9ac */
if(!s->budget--) { s->failed_pc=0x0c08d9acu; return 0; }
r[3]=r[2];
goto P_0c08d9ae;
P_0c08d9ae: /* original 2f22, guest PC 0x0c08d9ae */
if(!s->budget--) { s->failed_pc=0x0c08d9aeu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08d9b0;
P_0c08d9b0: /* original 430b, guest PC 0x0c08d9b0 */
if(!s->budget--) { s->failed_pc=0x0c08d9b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c08d9b4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d9b4u) { target=s->pc; goto dispatch; }
goto P_0c08d9b4;
P_0c08d9b2: /* original 64e3, guest PC 0x0c08d9b2 */
if(!s->budget--) { s->failed_pc=0x0c08d9b2u; return 0; }
r[4]=r[14];
goto P_0c08d9b4;
P_0c08d9b4: /* original 7f04, guest PC 0x0c08d9b4 */
if(!s->budget--) { s->failed_pc=0x0c08d9b4u; return 0; }
r[15]+=0x00000004u;
goto P_0c08d9b6;
P_0c08d9b6: /* original d34e, guest PC 0x0c08d9b6 */
if(!s->budget--) { s->failed_pc=0x0c08d9b6u; return 0; }
r[3]=read(ram,0x0c08daf0u,4);
goto P_0c08d9b8;
P_0c08d9b8: /* original 4f26, guest PC 0x0c08d9b8 */
if(!s->budget--) { s->failed_pc=0x0c08d9b8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d9ba;
P_0c08d9ba: /* original e401, guest PC 0x0c08d9ba */
if(!s->budget--) { s->failed_pc=0x0c08d9bau; return 0; }
r[4]=0x00000001u;
goto P_0c08d9bc;
P_0c08d9bc: /* original 6df6, guest PC 0x0c08d9bc */
if(!s->budget--) { s->failed_pc=0x0c08d9bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d9be;
P_0c08d9be: /* original 432b, guest PC 0x0c08d9be */
if(!s->budget--) { s->failed_pc=0x0c08d9beu; return 0; }
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
P_0c08d9c0: /* original 6ef6, guest PC 0x0c08d9c0 */
if(!s->budget--) { s->failed_pc=0x0c08d9c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d9c2;
P_0c08d9c2: /* original 2fe6, guest PC 0x0c08d9c2 */
if(!s->budget--) { s->failed_pc=0x0c08d9c2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9c4;
P_0c08d9c4: /* original ee00, guest PC 0x0c08d9c4 */
if(!s->budget--) { s->failed_pc=0x0c08d9c4u; return 0; }
r[14]=0x00000000u;
goto P_0c08d9c6;
P_0c08d9c6: /* original 9089, guest PC 0x0c08d9c6 */
if(!s->budget--) { s->failed_pc=0x0c08d9c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadcu,2);
goto P_0c08d9c8;
P_0c08d9c8: /* original e301, guest PC 0x0c08d9c8 */
if(!s->budget--) { s->failed_pc=0x0c08d9c8u; return 0; }
r[3]=0x00000001u;
goto P_0c08d9ca;
P_0c08d9ca: /* original 4f22, guest PC 0x0c08d9ca */
if(!s->budget--) { s->failed_pc=0x0c08d9cau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d9cc;
P_0c08d9cc: /* original 04e5, guest PC 0x0c08d9cc */
if(!s->budget--) { s->failed_pc=0x0c08d9ccu; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c08d9ce;
P_0c08d9ce: /* original 7002, guest PC 0x0c08d9ce */
if(!s->budget--) { s->failed_pc=0x0c08d9ceu; return 0; }
r[0]+=0x00000002u;
goto P_0c08d9d0;
P_0c08d9d0: /* original 04e5, guest PC 0x0c08d9d0 */
if(!s->budget--) { s->failed_pc=0x0c08d9d0u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c08d9d2;
P_0c08d9d2: /* original 7002, guest PC 0x0c08d9d2 */
if(!s->budget--) { s->failed_pc=0x0c08d9d2u; return 0; }
r[0]+=0x00000002u;
goto P_0c08d9d4;
P_0c08d9d4: /* original 04e5, guest PC 0x0c08d9d4 */
if(!s->budget--) { s->failed_pc=0x0c08d9d4u; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c08d9d6;
P_0c08d9d6: /* original 70fb, guest PC 0x0c08d9d6 */
if(!s->budget--) { s->failed_pc=0x0c08d9d6u; return 0; }
r[0]+=0xfffffffbu;
goto P_0c08d9d8;
P_0c08d9d8: /* original 04e4, guest PC 0x0c08d9d8 */
if(!s->budget--) { s->failed_pc=0x0c08d9d8u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c08d9da;
P_0c08d9da: /* original 70ff, guest PC 0x0c08d9da */
if(!s->budget--) { s->failed_pc=0x0c08d9dau; return 0; }
r[0]+=0xffffffffu;
goto P_0c08d9dc;
P_0c08d9dc: /* original 67e3, guest PC 0x0c08d9dc */
if(!s->budget--) { s->failed_pc=0x0c08d9dcu; return 0; }
r[7]=r[14];
goto P_0c08d9de;
P_0c08d9de: /* original 66e3, guest PC 0x0c08d9de */
if(!s->budget--) { s->failed_pc=0x0c08d9deu; return 0; }
r[6]=r[14];
goto P_0c08d9e0;
P_0c08d9e0: /* original 0434, guest PC 0x0c08d9e0 */
if(!s->budget--) { s->failed_pc=0x0c08d9e0u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c08d9e2;
P_0c08d9e2: /* original 2fe6, guest PC 0x0c08d9e2 */
if(!s->budget--) { s->failed_pc=0x0c08d9e2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9e4;
P_0c08d9e4: /* original 2fe6, guest PC 0x0c08d9e4 */
if(!s->budget--) { s->failed_pc=0x0c08d9e4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9e6;
P_0c08d9e6: /* original 2fe6, guest PC 0x0c08d9e6 */
if(!s->budget--) { s->failed_pc=0x0c08d9e6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9e8;
P_0c08d9e8: /* original b27d, guest PC 0x0c08d9e8 */
if(!s->budget--) { s->failed_pc=0x0c08d9e8u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08d9ecu;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d9ecu) { target=s->pc; goto dispatch; }
goto P_0c08d9ec;
P_0c08d9ea: /* original 65e3, guest PC 0x0c08d9ea */
if(!s->budget--) { s->failed_pc=0x0c08d9eau; return 0; }
r[5]=r[14];
goto P_0c08d9ec;
P_0c08d9ec: /* original 7f0c, guest PC 0x0c08d9ec */
if(!s->budget--) { s->failed_pc=0x0c08d9ecu; return 0; }
r[15]+=0x0000000cu;
goto P_0c08d9ee;
P_0c08d9ee: /* original 4f26, guest PC 0x0c08d9ee */
if(!s->budget--) { s->failed_pc=0x0c08d9eeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d9f0;
P_0c08d9f0: /* original 000b, guest PC 0x0c08d9f0 */
if(!s->budget--) { s->failed_pc=0x0c08d9f0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d9f2: /* original 6ef6, guest PC 0x0c08d9f2 */
if(!s->budget--) { s->failed_pc=0x0c08d9f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d9f4;
P_0c08d9f4: /* original 2fe6, guest PC 0x0c08d9f4 */
if(!s->budget--) { s->failed_pc=0x0c08d9f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d9f6;
P_0c08d9f6: /* original ee00, guest PC 0x0c08d9f6 */
if(!s->budget--) { s->failed_pc=0x0c08d9f6u; return 0; }
r[14]=0x00000000u;
goto P_0c08d9f8;
P_0c08d9f8: /* original 4f22, guest PC 0x0c08d9f8 */
if(!s->budget--) { s->failed_pc=0x0c08d9f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d9fa;
P_0c08d9fa: /* original 65e3, guest PC 0x0c08d9fa */
if(!s->budget--) { s->failed_pc=0x0c08d9fau; return 0; }
r[5]=r[14];
goto P_0c08d9fc;
P_0c08d9fc: /* original 7fec, guest PC 0x0c08d9fc */
if(!s->budget--) { s->failed_pc=0x0c08d9fcu; return 0; }
r[15]+=0xffffffecu;
goto P_0c08d9fe;
P_0c08d9fe: /* original 63f3, guest PC 0x0c08d9fe */
if(!s->budget--) { s->failed_pc=0x0c08d9feu; return 0; }
r[3]=r[15];
goto P_0c08da00;
P_0c08da00: /* original 730c, guest PC 0x0c08da00 */
if(!s->budget--) { s->failed_pc=0x0c08da00u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08da02;
P_0c08da02: /* original 1f44, guest PC 0x0c08da02 */
if(!s->budget--) { s->failed_pc=0x0c08da02u; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c08da04;
P_0c08da04: /* original 2f36, guest PC 0x0c08da04 */
if(!s->budget--) { s->failed_pc=0x0c08da04u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da06;
P_0c08da06: /* original 62f3, guest PC 0x0c08da06 */
if(!s->budget--) { s->failed_pc=0x0c08da06u; return 0; }
r[2]=r[15];
goto P_0c08da08;
P_0c08da08: /* original 720c, guest PC 0x0c08da08 */
if(!s->budget--) { s->failed_pc=0x0c08da08u; return 0; }
r[2]+=0x0000000cu;
goto P_0c08da0a;
P_0c08da0a: /* original 2f26, guest PC 0x0c08da0a */
if(!s->budget--) { s->failed_pc=0x0c08da0au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da0c;
P_0c08da0c: /* original 66f3, guest PC 0x0c08da0c */
if(!s->budget--) { s->failed_pc=0x0c08da0cu; return 0; }
r[6]=r[15];
goto P_0c08da0e;
P_0c08da0e: /* original 67f3, guest PC 0x0c08da0e */
if(!s->budget--) { s->failed_pc=0x0c08da0eu; return 0; }
r[7]=r[15];
goto P_0c08da10;
P_0c08da10: /* original 7608, guest PC 0x0c08da10 */
if(!s->budget--) { s->failed_pc=0x0c08da10u; return 0; }
r[6]+=0x00000008u;
goto P_0c08da12;
P_0c08da12: /* original 770c, guest PC 0x0c08da12 */
if(!s->budget--) { s->failed_pc=0x0c08da12u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08da14;
P_0c08da14: /* original b14c, guest PC 0x0c08da14 */
if(!s->budget--) { s->failed_pc=0x0c08da14u; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08da18u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da18u) { target=s->pc; goto dispatch; }
goto P_0c08da18;
P_0c08da16: /* original 64e3, guest PC 0x0c08da16 */
if(!s->budget--) { s->failed_pc=0x0c08da16u; return 0; }
r[4]=r[14];
goto P_0c08da18;
P_0c08da18: /* original 62f3, guest PC 0x0c08da18 */
if(!s->budget--) { s->failed_pc=0x0c08da18u; return 0; }
r[2]=r[15];
goto P_0c08da1a;
P_0c08da1a: /* original 7214, guest PC 0x0c08da1a */
if(!s->budget--) { s->failed_pc=0x0c08da1au; return 0; }
r[2]+=0x00000014u;
goto P_0c08da1c;
P_0c08da1c: /* original 2f26, guest PC 0x0c08da1c */
if(!s->budget--) { s->failed_pc=0x0c08da1cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da1e;
P_0c08da1e: /* original 66f3, guest PC 0x0c08da1e */
if(!s->budget--) { s->failed_pc=0x0c08da1eu; return 0; }
r[6]=r[15];
goto P_0c08da20;
P_0c08da20: /* original 65f3, guest PC 0x0c08da20 */
if(!s->budget--) { s->failed_pc=0x0c08da20u; return 0; }
r[5]=r[15];
goto P_0c08da22;
P_0c08da22: /* original 67f3, guest PC 0x0c08da22 */
if(!s->budget--) { s->failed_pc=0x0c08da22u; return 0; }
r[7]=r[15];
goto P_0c08da24;
P_0c08da24: /* original 750c, guest PC 0x0c08da24 */
if(!s->budget--) { s->failed_pc=0x0c08da24u; return 0; }
r[5]+=0x0000000cu;
goto P_0c08da26;
P_0c08da26: /* original 7714, guest PC 0x0c08da26 */
if(!s->budget--) { s->failed_pc=0x0c08da26u; return 0; }
r[7]+=0x00000014u;
goto P_0c08da28;
P_0c08da28: /* original 7610, guest PC 0x0c08da28 */
if(!s->budget--) { s->failed_pc=0x0c08da28u; return 0; }
r[6]+=0x00000010u;
goto P_0c08da2a;
P_0c08da2a: /* original b174, guest PC 0x0c08da2a */
if(!s->budget--) { s->failed_pc=0x0c08da2au; return 0; }
target=code_base|0x0c08dd16u; r[16]=code_base|0x0c08da2eu;
r[4]=read(ram,r[15]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da2eu) { target=s->pc; goto dispatch; }
goto P_0c08da2e;
P_0c08da2c: /* original 54f7, guest PC 0x0c08da2c */
if(!s->budget--) { s->failed_pc=0x0c08da2cu; return 0; }
r[4]=read(ram,r[15]+28,4);
goto P_0c08da2e;
P_0c08da2e: /* original 52f6, guest PC 0x0c08da2e */
if(!s->budget--) { s->failed_pc=0x0c08da2eu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08da30;
P_0c08da30: /* original 65e3, guest PC 0x0c08da30 */
if(!s->budget--) { s->failed_pc=0x0c08da30u; return 0; }
r[5]=r[14];
goto P_0c08da32;
P_0c08da32: /* original 66e3, guest PC 0x0c08da32 */
if(!s->budget--) { s->failed_pc=0x0c08da32u; return 0; }
r[6]=r[14];
goto P_0c08da34;
P_0c08da34: /* original 2f26, guest PC 0x0c08da34 */
if(!s->budget--) { s->failed_pc=0x0c08da34u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da36;
P_0c08da36: /* original 53f6, guest PC 0x0c08da36 */
if(!s->budget--) { s->failed_pc=0x0c08da36u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08da38;
P_0c08da38: /* original 2f36, guest PC 0x0c08da38 */
if(!s->budget--) { s->failed_pc=0x0c08da38u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da3a;
P_0c08da3a: /* original 52f6, guest PC 0x0c08da3a */
if(!s->budget--) { s->failed_pc=0x0c08da3au; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08da3c;
P_0c08da3c: /* original 2f26, guest PC 0x0c08da3c */
if(!s->budget--) { s->failed_pc=0x0c08da3cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da3e;
P_0c08da3e: /* original 57f6, guest PC 0x0c08da3e */
if(!s->budget--) { s->failed_pc=0x0c08da3eu; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c08da40;
P_0c08da40: /* original b251, guest PC 0x0c08da40 */
if(!s->budget--) { s->failed_pc=0x0c08da40u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08da44u;
r[4]=read(ram,r[15]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da44u) { target=s->pc; goto dispatch; }
goto P_0c08da44;
P_0c08da42: /* original 54fa, guest PC 0x0c08da42 */
if(!s->budget--) { s->failed_pc=0x0c08da42u; return 0; }
r[4]=read(ram,r[15]+40,4);
goto P_0c08da44;
P_0c08da44: /* original 7f2c, guest PC 0x0c08da44 */
if(!s->budget--) { s->failed_pc=0x0c08da44u; return 0; }
r[15]+=0x0000002cu;
goto P_0c08da46;
P_0c08da46: /* original 4f26, guest PC 0x0c08da46 */
if(!s->budget--) { s->failed_pc=0x0c08da46u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08da48;
P_0c08da48: /* original 000b, guest PC 0x0c08da48 */
if(!s->budget--) { s->failed_pc=0x0c08da48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08da4a: /* original 6ef6, guest PC 0x0c08da4a */
if(!s->budget--) { s->failed_pc=0x0c08da4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08da4c;
P_0c08da4c: /* original 2fe6, guest PC 0x0c08da4c */
if(!s->budget--) { s->failed_pc=0x0c08da4cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da4e;
P_0c08da4e: /* original 6e43, guest PC 0x0c08da4e */
if(!s->budget--) { s->failed_pc=0x0c08da4eu; return 0; }
r[14]=r[4];
goto P_0c08da50;
P_0c08da50: /* original 2fd6, guest PC 0x0c08da50 */
if(!s->budget--) { s->failed_pc=0x0c08da50u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da52;
P_0c08da52: /* original e301, guest PC 0x0c08da52 */
if(!s->budget--) { s->failed_pc=0x0c08da52u; return 0; }
r[3]=0x00000001u;
goto P_0c08da54;
P_0c08da54: /* original 2fc6, guest PC 0x0c08da54 */
if(!s->budget--) { s->failed_pc=0x0c08da54u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da56;
P_0c08da56: /* original 9042, guest PC 0x0c08da56 */
if(!s->budget--) { s->failed_pc=0x0c08da56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadeu,2);
goto P_0c08da58;
P_0c08da58: /* original 4f22, guest PC 0x0c08da58 */
if(!s->budget--) { s->failed_pc=0x0c08da58u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08da5a;
P_0c08da5a: /* original 0ced, guest PC 0x0c08da5a */
if(!s->budget--) { s->failed_pc=0x0c08da5au; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08da5c;
P_0c08da5c: /* original 7002, guest PC 0x0c08da5c */
if(!s->budget--) { s->failed_pc=0x0c08da5cu; return 0; }
r[0]+=0x00000002u;
goto P_0c08da5e;
P_0c08da5e: /* original 0ded, guest PC 0x0c08da5e */
if(!s->budget--) { s->failed_pc=0x0c08da5eu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08da60;
P_0c08da60: /* original 70f6, guest PC 0x0c08da60 */
if(!s->budget--) { s->failed_pc=0x0c08da60u; return 0; }
r[0]+=0xfffffff6u;
goto P_0c08da62;
P_0c08da62: /* original 7ff0, guest PC 0x0c08da62 */
if(!s->budget--) { s->failed_pc=0x0c08da62u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08da64;
P_0c08da64: /* original 0e34, guest PC 0x0c08da64 */
if(!s->budget--) { s->failed_pc=0x0c08da64u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08da66;
P_0c08da66: /* original 62f3, guest PC 0x0c08da66 */
if(!s->budget--) { s->failed_pc=0x0c08da66u; return 0; }
r[2]=r[15];
goto P_0c08da68;
P_0c08da68: /* original 720c, guest PC 0x0c08da68 */
if(!s->budget--) { s->failed_pc=0x0c08da68u; return 0; }
r[2]+=0x0000000cu;
goto P_0c08da6a;
P_0c08da6a: /* original 2f26, guest PC 0x0c08da6a */
if(!s->budget--) { s->failed_pc=0x0c08da6au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da6c;
P_0c08da6c: /* original 65d3, guest PC 0x0c08da6c */
if(!s->budget--) { s->failed_pc=0x0c08da6cu; return 0; }
r[5]=r[13];
goto P_0c08da6e;
P_0c08da6e: /* original 63f3, guest PC 0x0c08da6e */
if(!s->budget--) { s->failed_pc=0x0c08da6eu; return 0; }
r[3]=r[15];
goto P_0c08da70;
P_0c08da70: /* original 730c, guest PC 0x0c08da70 */
if(!s->budget--) { s->failed_pc=0x0c08da70u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08da72;
P_0c08da72: /* original 2f36, guest PC 0x0c08da72 */
if(!s->budget--) { s->failed_pc=0x0c08da72u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da74;
P_0c08da74: /* original 66f3, guest PC 0x0c08da74 */
if(!s->budget--) { s->failed_pc=0x0c08da74u; return 0; }
r[6]=r[15];
goto P_0c08da76;
P_0c08da76: /* original 67f3, guest PC 0x0c08da76 */
if(!s->budget--) { s->failed_pc=0x0c08da76u; return 0; }
r[7]=r[15];
goto P_0c08da78;
P_0c08da78: /* original 7608, guest PC 0x0c08da78 */
if(!s->budget--) { s->failed_pc=0x0c08da78u; return 0; }
r[6]+=0x00000008u;
goto P_0c08da7a;
P_0c08da7a: /* original 770c, guest PC 0x0c08da7a */
if(!s->budget--) { s->failed_pc=0x0c08da7au; return 0; }
r[7]+=0x0000000cu;
goto P_0c08da7c;
P_0c08da7c: /* original b118, guest PC 0x0c08da7c */
if(!s->budget--) { s->failed_pc=0x0c08da7cu; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08da80u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da80u) { target=s->pc; goto dispatch; }
goto P_0c08da80;
P_0c08da7e: /* original 64c3, guest PC 0x0c08da7e */
if(!s->budget--) { s->failed_pc=0x0c08da7eu; return 0; }
r[4]=r[12];
goto P_0c08da80;
P_0c08da80: /* original 53f5, guest PC 0x0c08da80 */
if(!s->budget--) { s->failed_pc=0x0c08da80u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08da82;
P_0c08da82: /* original 65c3, guest PC 0x0c08da82 */
if(!s->budget--) { s->failed_pc=0x0c08da82u; return 0; }
r[5]=r[12];
goto P_0c08da84;
P_0c08da84: /* original 66d3, guest PC 0x0c08da84 */
if(!s->budget--) { s->failed_pc=0x0c08da84u; return 0; }
r[6]=r[13];
goto P_0c08da86;
P_0c08da86: /* original 2f36, guest PC 0x0c08da86 */
if(!s->budget--) { s->failed_pc=0x0c08da86u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da88;
P_0c08da88: /* original 52f5, guest PC 0x0c08da88 */
if(!s->budget--) { s->failed_pc=0x0c08da88u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08da8a;
P_0c08da8a: /* original 2f26, guest PC 0x0c08da8a */
if(!s->budget--) { s->failed_pc=0x0c08da8au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da8c;
P_0c08da8c: /* original 53f5, guest PC 0x0c08da8c */
if(!s->budget--) { s->failed_pc=0x0c08da8cu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08da8e;
P_0c08da8e: /* original 2f36, guest PC 0x0c08da8e */
if(!s->budget--) { s->failed_pc=0x0c08da8eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08da90;
P_0c08da90: /* original 57f5, guest PC 0x0c08da90 */
if(!s->budget--) { s->failed_pc=0x0c08da90u; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08da92;
P_0c08da92: /* original b228, guest PC 0x0c08da92 */
if(!s->budget--) { s->failed_pc=0x0c08da92u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08da96u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08da96u) { target=s->pc; goto dispatch; }
goto P_0c08da96;
P_0c08da94: /* original 64e3, guest PC 0x0c08da94 */
if(!s->budget--) { s->failed_pc=0x0c08da94u; return 0; }
r[4]=r[14];
goto P_0c08da96;
P_0c08da96: /* original 7f24, guest PC 0x0c08da96 */
if(!s->budget--) { s->failed_pc=0x0c08da96u; return 0; }
r[15]+=0x00000024u;
goto P_0c08da98;
P_0c08da98: /* original 4f26, guest PC 0x0c08da98 */
if(!s->budget--) { s->failed_pc=0x0c08da98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08da9a;
P_0c08da9a: /* original 6cf6, guest PC 0x0c08da9a */
if(!s->budget--) { s->failed_pc=0x0c08da9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08da9c;
P_0c08da9c: /* original 6df6, guest PC 0x0c08da9c */
if(!s->budget--) { s->failed_pc=0x0c08da9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08da9e;
P_0c08da9e: /* original 000b, guest PC 0x0c08da9e */
if(!s->budget--) { s->failed_pc=0x0c08da9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08daa0: /* original 6ef6, guest PC 0x0c08daa0 */
if(!s->budget--) { s->failed_pc=0x0c08daa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08daa2u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
