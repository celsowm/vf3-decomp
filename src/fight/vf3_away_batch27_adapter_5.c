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
int vf3_away_batch27_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05b890u: goto P_0c05b890;
case 0x0c05b892u: goto P_0c05b892;
case 0x0c05b894u: goto P_0c05b894;
case 0x0c05b896u: goto P_0c05b896;
case 0x0c05b898u: goto P_0c05b898;
case 0x0c05b89au: goto P_0c05b89a;
case 0x0c05b89cu: goto P_0c05b89c;
case 0x0c05b89eu: goto P_0c05b89e;
case 0x0c05b8a0u: goto P_0c05b8a0;
case 0x0c05b8a2u: goto P_0c05b8a2;
case 0x0c05b8a4u: goto P_0c05b8a4;
case 0x0c05b8a6u: goto P_0c05b8a6;
case 0x0c05b8a8u: goto P_0c05b8a8;
case 0x0c05b8aau: goto P_0c05b8aa;
case 0x0c05b8acu: goto P_0c05b8ac;
case 0x0c05b8aeu: goto P_0c05b8ae;
case 0x0c05b8b0u: goto P_0c05b8b0;
case 0x0c05b8b2u: goto P_0c05b8b2;
case 0x0c05b8b4u: goto P_0c05b8b4;
case 0x0c05b8b6u: goto P_0c05b8b6;
case 0x0c05b8b8u: goto P_0c05b8b8;
case 0x0c05b8bau: goto P_0c05b8ba;
case 0x0c05b8bcu: goto P_0c05b8bc;
case 0x0c05b8beu: goto P_0c05b8be;
case 0x0c05b8c0u: goto P_0c05b8c0;
case 0x0c05b8c2u: goto P_0c05b8c2;
case 0x0c05b8c4u: goto P_0c05b8c4;
case 0x0c05b8c6u: goto P_0c05b8c6;
case 0x0c05b8c8u: goto P_0c05b8c8;
case 0x0c05b8cau: goto P_0c05b8ca;
case 0x0c05b8ccu: goto P_0c05b8cc;
case 0x0c05b8ceu: goto P_0c05b8ce;
case 0x0c05b8d0u: goto P_0c05b8d0;
case 0x0c05b8d2u: goto P_0c05b8d2;
case 0x0c05b8d4u: goto P_0c05b8d4;
case 0x0c05b8d6u: goto P_0c05b8d6;
case 0x0c05b8d8u: goto P_0c05b8d8;
case 0x0c05b8dau: goto P_0c05b8da;
case 0x0c05b8dcu: goto P_0c05b8dc;
case 0x0c05b8deu: goto P_0c05b8de;
case 0x0c05b8e0u: goto P_0c05b8e0;
case 0x0c05b8e2u: goto P_0c05b8e2;
case 0x0c05b8e4u: goto P_0c05b8e4;
case 0x0c05b8e6u: goto P_0c05b8e6;
case 0x0c05b8e8u: goto P_0c05b8e8;
case 0x0c05b8eau: goto P_0c05b8ea;
case 0x0c05b8ecu: goto P_0c05b8ec;
case 0x0c05b8eeu: goto P_0c05b8ee;
case 0x0c05b8f0u: goto P_0c05b8f0;
case 0x0c05b8f2u: goto P_0c05b8f2;
case 0x0c05b8f4u: goto P_0c05b8f4;
case 0x0c05b8f6u: goto P_0c05b8f6;
case 0x0c05b8f8u: goto P_0c05b8f8;
case 0x0c05b8fau: goto P_0c05b8fa;
case 0x0c05b8fcu: goto P_0c05b8fc;
case 0x0c05b8feu: goto P_0c05b8fe;
case 0x0c05b900u: goto P_0c05b900;
case 0x0c05b902u: goto P_0c05b902;
case 0x0c05b904u: goto P_0c05b904;
case 0x0c05b906u: goto P_0c05b906;
case 0x0c05b908u: goto P_0c05b908;
case 0x0c05b90au: goto P_0c05b90a;
case 0x0c05b90cu: goto P_0c05b90c;
case 0x0c05b90eu: goto P_0c05b90e;
case 0x0c05b910u: goto P_0c05b910;
case 0x0c05b912u: goto P_0c05b912;
case 0x0c05b914u: goto P_0c05b914;
case 0x0c05b916u: goto P_0c05b916;
case 0x0c05b918u: goto P_0c05b918;
case 0x0c05b91au: goto P_0c05b91a;
case 0x0c05b91cu: goto P_0c05b91c;
case 0x0c05b91eu: goto P_0c05b91e;
case 0x0c05b920u: goto P_0c05b920;
case 0x0c05b922u: goto P_0c05b922;
case 0x0c05b924u: goto P_0c05b924;
case 0x0c05b926u: goto P_0c05b926;
case 0x0c05b928u: goto P_0c05b928;
case 0x0c05b92au: goto P_0c05b92a;
case 0x0c05b92cu: goto P_0c05b92c;
case 0x0c05b92eu: goto P_0c05b92e;
case 0x0c05b930u: goto P_0c05b930;
case 0x0c05b932u: goto P_0c05b932;
case 0x0c05b934u: goto P_0c05b934;
case 0x0c05b936u: goto P_0c05b936;
case 0x0c05b938u: goto P_0c05b938;
case 0x0c05b93au: goto P_0c05b93a;
case 0x0c05b93cu: goto P_0c05b93c;
case 0x0c05b93eu: goto P_0c05b93e;
case 0x0c05b940u: goto P_0c05b940;
case 0x0c05b942u: goto P_0c05b942;
case 0x0c05b944u: goto P_0c05b944;
case 0x0c05b946u: goto P_0c05b946;
case 0x0c05b948u: goto P_0c05b948;
case 0x0c05b94au: goto P_0c05b94a;
case 0x0c05b94cu: goto P_0c05b94c;
case 0x0c05b94eu: goto P_0c05b94e;
case 0x0c05b950u: goto P_0c05b950;
case 0x0c05b952u: goto P_0c05b952;
case 0x0c05b954u: goto P_0c05b954;
case 0x0c05b956u: goto P_0c05b956;
case 0x0c05b958u: goto P_0c05b958;
case 0x0c05b95au: goto P_0c05b95a;
case 0x0c05b95cu: goto P_0c05b95c;
case 0x0c05b95eu: goto P_0c05b95e;
case 0x0c05b960u: goto P_0c05b960;
case 0x0c05b962u: goto P_0c05b962;
case 0x0c05b964u: goto P_0c05b964;
case 0x0c05b966u: goto P_0c05b966;
case 0x0c05b968u: goto P_0c05b968;
case 0x0c05b96au: goto P_0c05b96a;
case 0x0c05b96cu: goto P_0c05b96c;
case 0x0c05b96eu: goto P_0c05b96e;
case 0x0c05b970u: goto P_0c05b970;
case 0x0c05b972u: goto P_0c05b972;
case 0x0c05b974u: goto P_0c05b974;
case 0x0c05b976u: goto P_0c05b976;
case 0x0c05b978u: goto P_0c05b978;
case 0x0c05b97au: goto P_0c05b97a;
case 0x0c05b97cu: goto P_0c05b97c;
case 0x0c05b97eu: goto P_0c05b97e;
case 0x0c05b980u: goto P_0c05b980;
case 0x0c05b982u: goto P_0c05b982;
case 0x0c05b984u: goto P_0c05b984;
case 0x0c05b986u: goto P_0c05b986;
case 0x0c05b988u: goto P_0c05b988;
case 0x0c05b98au: goto P_0c05b98a;
case 0x0c05b98cu: goto P_0c05b98c;
case 0x0c05b98eu: goto P_0c05b98e;
case 0x0c05b990u: goto P_0c05b990;
case 0x0c05b992u: goto P_0c05b992;
case 0x0c05b994u: goto P_0c05b994;
case 0x0c05b996u: goto P_0c05b996;
case 0x0c05b998u: goto P_0c05b998;
case 0x0c05b99au: goto P_0c05b99a;
case 0x0c05b99cu: goto P_0c05b99c;
case 0x0c05b99eu: goto P_0c05b99e;
case 0x0c05b9a0u: goto P_0c05b9a0;
case 0x0c05b9a2u: goto P_0c05b9a2;
case 0x0c05b9a4u: goto P_0c05b9a4;
case 0x0c05b9a6u: goto P_0c05b9a6;
case 0x0c05b9a8u: goto P_0c05b9a8;
case 0x0c05b9aau: goto P_0c05b9aa;
case 0x0c05b9acu: goto P_0c05b9ac;
case 0x0c05b9aeu: goto P_0c05b9ae;
case 0x0c05b9b0u: goto P_0c05b9b0;
case 0x0c05b9b2u: goto P_0c05b9b2;
case 0x0c05b9b4u: goto P_0c05b9b4;
case 0x0c05b9b6u: goto P_0c05b9b6;
case 0x0c05b9b8u: goto P_0c05b9b8;
case 0x0c05b9bau: goto P_0c05b9ba;
case 0x0c05b9bcu: goto P_0c05b9bc;
case 0x0c05b9beu: goto P_0c05b9be;
case 0x0c05b9c0u: goto P_0c05b9c0;
case 0x0c05b9c2u: goto P_0c05b9c2;
case 0x0c05b9c4u: goto P_0c05b9c4;
case 0x0c05b9c6u: goto P_0c05b9c6;
case 0x0c05b9c8u: goto P_0c05b9c8;
case 0x0c05b9f4u: goto P_0c05b9f4;
case 0x0c05b9f6u: goto P_0c05b9f6;
case 0x0c05b9f8u: goto P_0c05b9f8;
case 0x0c05b9fau: goto P_0c05b9fa;
case 0x0c05b9fcu: goto P_0c05b9fc;
case 0x0c05b9feu: goto P_0c05b9fe;
case 0x0c05ba00u: goto P_0c05ba00;
case 0x0c05ba02u: goto P_0c05ba02;
case 0x0c05ba04u: goto P_0c05ba04;
case 0x0c05ba06u: goto P_0c05ba06;
case 0x0c05ba08u: goto P_0c05ba08;
case 0x0c05ba0au: goto P_0c05ba0a;
case 0x0c05ba0cu: goto P_0c05ba0c;
case 0x0c05ba0eu: goto P_0c05ba0e;
case 0x0c05ba10u: goto P_0c05ba10;
case 0x0c05ba12u: goto P_0c05ba12;
case 0x0c05ba14u: goto P_0c05ba14;
case 0x0c05ba16u: goto P_0c05ba16;
case 0x0c05ba18u: goto P_0c05ba18;
case 0x0c05ba1au: goto P_0c05ba1a;
case 0x0c05ba1cu: goto P_0c05ba1c;
case 0x0c05ba1eu: goto P_0c05ba1e;
case 0x0c05ba20u: goto P_0c05ba20;
case 0x0c05ba22u: goto P_0c05ba22;
case 0x0c05ba24u: goto P_0c05ba24;
case 0x0c05ba26u: goto P_0c05ba26;
case 0x0c05ba28u: goto P_0c05ba28;
case 0x0c05ba2au: goto P_0c05ba2a;
case 0x0c05ba2cu: goto P_0c05ba2c;
case 0x0c05ba2eu: goto P_0c05ba2e;
case 0x0c05ba30u: goto P_0c05ba30;
case 0x0c05ba32u: goto P_0c05ba32;
case 0x0c05ba34u: goto P_0c05ba34;
case 0x0c05ba36u: goto P_0c05ba36;
case 0x0c05ba38u: goto P_0c05ba38;
case 0x0c05ba3au: goto P_0c05ba3a;
case 0x0c05ba3cu: goto P_0c05ba3c;
case 0x0c05ba3eu: goto P_0c05ba3e;
case 0x0c05ba40u: goto P_0c05ba40;
case 0x0c05ba42u: goto P_0c05ba42;
case 0x0c05ba44u: goto P_0c05ba44;
case 0x0c05ba46u: goto P_0c05ba46;
case 0x0c05ba48u: goto P_0c05ba48;
case 0x0c05ba4au: goto P_0c05ba4a;
case 0x0c05ba4cu: goto P_0c05ba4c;
case 0x0c05ba4eu: goto P_0c05ba4e;
case 0x0c05ba50u: goto P_0c05ba50;
case 0x0c05ba52u: goto P_0c05ba52;
case 0x0c05ba54u: goto P_0c05ba54;
case 0x0c05ba56u: goto P_0c05ba56;
case 0x0c05ba58u: goto P_0c05ba58;
case 0x0c05ba5au: goto P_0c05ba5a;
case 0x0c05ba5cu: goto P_0c05ba5c;
case 0x0c05ba5eu: goto P_0c05ba5e;
case 0x0c05ba60u: goto P_0c05ba60;
case 0x0c05ba62u: goto P_0c05ba62;
case 0x0c05ba64u: goto P_0c05ba64;
case 0x0c05ba66u: goto P_0c05ba66;
case 0x0c05ba68u: goto P_0c05ba68;
case 0x0c05ba6au: goto P_0c05ba6a;
case 0x0c05ba6cu: goto P_0c05ba6c;
case 0x0c05ba6eu: goto P_0c05ba6e;
case 0x0c05ba70u: goto P_0c05ba70;
case 0x0c05ba72u: goto P_0c05ba72;
case 0x0c05ba74u: goto P_0c05ba74;
case 0x0c05ba76u: goto P_0c05ba76;
case 0x0c05ba78u: goto P_0c05ba78;
case 0x0c05ba7au: goto P_0c05ba7a;
case 0x0c05ba7cu: goto P_0c05ba7c;
case 0x0c05ba7eu: goto P_0c05ba7e;
case 0x0c05ba80u: goto P_0c05ba80;
case 0x0c05ba82u: goto P_0c05ba82;
case 0x0c05ba84u: goto P_0c05ba84;
case 0x0c05ba86u: goto P_0c05ba86;
case 0x0c05ba88u: goto P_0c05ba88;
case 0x0c05ba8au: goto P_0c05ba8a;
case 0x0c05ba8cu: goto P_0c05ba8c;
case 0x0c05ba8eu: goto P_0c05ba8e;
case 0x0c05ba90u: goto P_0c05ba90;
case 0x0c05ba92u: goto P_0c05ba92;
case 0x0c05ba94u: goto P_0c05ba94;
case 0x0c05ba96u: goto P_0c05ba96;
case 0x0c05ba98u: goto P_0c05ba98;
case 0x0c05ba9au: goto P_0c05ba9a;
case 0x0c05ba9cu: goto P_0c05ba9c;
case 0x0c05ba9eu: goto P_0c05ba9e;
case 0x0c05baa0u: goto P_0c05baa0;
case 0x0c05baa2u: goto P_0c05baa2;
case 0x0c05baa4u: goto P_0c05baa4;
case 0x0c05baa6u: goto P_0c05baa6;
case 0x0c05baa8u: goto P_0c05baa8;
case 0x0c05baaau: goto P_0c05baaa;
case 0x0c05baacu: goto P_0c05baac;
case 0x0c05baaeu: goto P_0c05baae;
case 0x0c05bab0u: goto P_0c05bab0;
case 0x0c05bab2u: goto P_0c05bab2;
case 0x0c05bab4u: goto P_0c05bab4;
case 0x0c05bab6u: goto P_0c05bab6;
case 0x0c05bab8u: goto P_0c05bab8;
case 0x0c05babau: goto P_0c05baba;
case 0x0c05babcu: goto P_0c05babc;
case 0x0c05babeu: goto P_0c05babe;
case 0x0c05bac0u: goto P_0c05bac0;
case 0x0c05bac2u: goto P_0c05bac2;
case 0x0c05bac4u: goto P_0c05bac4;
case 0x0c05bac6u: goto P_0c05bac6;
case 0x0c05bac8u: goto P_0c05bac8;
case 0x0c05bacau: goto P_0c05baca;
case 0x0c05baccu: goto P_0c05bacc;
case 0x0c05baceu: goto P_0c05bace;
case 0x0c05bad0u: goto P_0c05bad0;
case 0x0c05bad2u: goto P_0c05bad2;
case 0x0c05bad4u: goto P_0c05bad4;
case 0x0c05bad6u: goto P_0c05bad6;
case 0x0c05bad8u: goto P_0c05bad8;
case 0x0c05badau: goto P_0c05bada;
case 0x0c05badcu: goto P_0c05badc;
case 0x0c05badeu: goto P_0c05bade;
case 0x0c05bae0u: goto P_0c05bae0;
case 0x0c05bae2u: goto P_0c05bae2;
case 0x0c05bae4u: goto P_0c05bae4;
case 0x0c05bae6u: goto P_0c05bae6;
case 0x0c05bae8u: goto P_0c05bae8;
case 0x0c05baeau: goto P_0c05baea;
case 0x0c05baecu: goto P_0c05baec;
case 0x0c05baeeu: goto P_0c05baee;
case 0x0c05baf0u: goto P_0c05baf0;
case 0x0c05baf2u: goto P_0c05baf2;
case 0x0c05baf4u: goto P_0c05baf4;
case 0x0c05baf6u: goto P_0c05baf6;
case 0x0c05baf8u: goto P_0c05baf8;
case 0x0c05bafau: goto P_0c05bafa;
case 0x0c05bafcu: goto P_0c05bafc;
case 0x0c05bafeu: goto P_0c05bafe;
case 0x0c05bb00u: goto P_0c05bb00;
case 0x0c05bb02u: goto P_0c05bb02;
case 0x0c05bb04u: goto P_0c05bb04;
case 0x0c05bb06u: goto P_0c05bb06;
case 0x0c05bb08u: goto P_0c05bb08;
case 0x0c05bb0au: goto P_0c05bb0a;
case 0x0c05bb0cu: goto P_0c05bb0c;
case 0x0c05bb0eu: goto P_0c05bb0e;
case 0x0c05bb10u: goto P_0c05bb10;
case 0x0c05bb12u: goto P_0c05bb12;
case 0x0c05bb14u: goto P_0c05bb14;
case 0x0c05bb16u: goto P_0c05bb16;
case 0x0c05bb18u: goto P_0c05bb18;
case 0x0c05bb1au: goto P_0c05bb1a;
case 0x0c05bb1cu: goto P_0c05bb1c;
case 0x0c05bb1eu: goto P_0c05bb1e;
case 0x0c05bb20u: goto P_0c05bb20;
case 0x0c05bb22u: goto P_0c05bb22;
case 0x0c05bb24u: goto P_0c05bb24;
case 0x0c05bb26u: goto P_0c05bb26;
case 0x0c05bb28u: goto P_0c05bb28;
case 0x0c05bb2au: goto P_0c05bb2a;
case 0x0c05bb2cu: goto P_0c05bb2c;
case 0x0c05bb2eu: goto P_0c05bb2e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05b890: /* original 2fe6, guest PC 0x0c05b890 */
if(!s->budget--) { s->failed_pc=0x0c05b890u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05b892;
P_0c05b892: /* original 2fd6, guest PC 0x0c05b892 */
if(!s->budget--) { s->failed_pc=0x0c05b892u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05b894;
P_0c05b894: /* original d74e, guest PC 0x0c05b894 */
if(!s->budget--) { s->failed_pc=0x0c05b894u; return 0; }
r[7]=read(ram,0x0c05b9d0u,4);
goto P_0c05b896;
P_0c05b896: /* original d64f, guest PC 0x0c05b896 */
if(!s->budget--) { s->failed_pc=0x0c05b896u; return 0; }
r[6]=read(ram,0x0c05b9d4u,4);
goto P_0c05b898;
P_0c05b898: /* original de4f, guest PC 0x0c05b898 */
if(!s->budget--) { s->failed_pc=0x0c05b898u; return 0; }
r[14]=read(ram,0x0c05b9d8u,4);
goto P_0c05b89a;
P_0c05b89a: /* original 9096, guest PC 0x0c05b89a */
if(!s->budget--) { s->failed_pc=0x0c05b89au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b9cau,2);
goto P_0c05b89c;
P_0c05b89c: /* original 034e, guest PC 0x0c05b89c */
if(!s->budget--) { s->failed_pc=0x0c05b89cu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b89e;
P_0c05b89e: /* original 7004, guest PC 0x0c05b89e */
if(!s->budget--) { s->failed_pc=0x0c05b89eu; return 0; }
r[0]+=0x00000004u;
goto P_0c05b8a0;
P_0c05b8a0: /* original 2e32, guest PC 0x0c05b8a0 */
if(!s->budget--) { s->failed_pc=0x0c05b8a0u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c05b8a2;
P_0c05b8a2: /* original 024e, guest PC 0x0c05b8a2 */
if(!s->budget--) { s->failed_pc=0x0c05b8a2u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c05b8a4;
P_0c05b8a4: /* original 1e24, guest PC 0x0c05b8a4 */
if(!s->budget--) { s->failed_pc=0x0c05b8a4u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c05b8a6;
P_0c05b8a6: /* original 7004, guest PC 0x0c05b8a6 */
if(!s->budget--) { s->failed_pc=0x0c05b8a6u; return 0; }
r[0]+=0x00000004u;
goto P_0c05b8a8;
P_0c05b8a8: /* original 034e, guest PC 0x0c05b8a8 */
if(!s->budget--) { s->failed_pc=0x0c05b8a8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b8aa;
P_0c05b8aa: /* original 1e35, guest PC 0x0c05b8aa */
if(!s->budget--) { s->failed_pc=0x0c05b8aau; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c05b8ac;
P_0c05b8ac: /* original 60e2, guest PC 0x0c05b8ac */
if(!s->budget--) { s->failed_pc=0x0c05b8acu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05b8ae;
P_0c05b8ae: /* original 4029, guest PC 0x0c05b8ae */
if(!s->budget--) { s->failed_pc=0x0c05b8aeu; return 0; }
r[0]>>=16;
goto P_0c05b8b0;
P_0c05b8b0: /* original 4019, guest PC 0x0c05b8b0 */
if(!s->budget--) { s->failed_pc=0x0c05b8b0u; return 0; }
r[0]>>=8;
goto P_0c05b8b2;
P_0c05b8b2: /* original c807, guest PC 0x0c05b8b2 */
if(!s->budget--) { s->failed_pc=0x0c05b8b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&7u)==0)!=0);
goto P_0c05b8b4;
P_0c05b8b4: /* original 8b07, guest PC 0x0c05b8b4 */
if(!s->budget--) { s->failed_pc=0x0c05b8b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05b8c6; }
goto P_0c05b8b6;
P_0c05b8b6: /* original 65e3, guest PC 0x0c05b8b6 */
if(!s->budget--) { s->failed_pc=0x0c05b8b6u; return 0; }
r[5]=r[14];
goto P_0c05b8b8;
P_0c05b8b8: /* original d348, guest PC 0x0c05b8b8 */
if(!s->budget--) { s->failed_pc=0x0c05b8b8u; return 0; }
r[3]=read(ram,0x0c05b9dcu,4);
goto P_0c05b8ba;
P_0c05b8ba: /* original 7510, guest PC 0x0c05b8ba */
if(!s->budget--) { s->failed_pc=0x0c05b8bau; return 0; }
r[5]+=0x00000010u;
goto P_0c05b8bc;
P_0c05b8bc: /* original d148, guest PC 0x0c05b8bc */
if(!s->budget--) { s->failed_pc=0x0c05b8bcu; return 0; }
r[1]=read(ram,0x0c05b9e0u,4);
goto P_0c05b8be;
P_0c05b8be: /* original 5251, guest PC 0x0c05b8be */
if(!s->budget--) { s->failed_pc=0x0c05b8beu; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c05b8c0;
P_0c05b8c0: /* original 2239, guest PC 0x0c05b8c0 */
if(!s->budget--) { s->failed_pc=0x0c05b8c0u; return 0; }
r[2]&=r[3];
goto P_0c05b8c2;
P_0c05b8c2: /* original 221b, guest PC 0x0c05b8c2 */
if(!s->budget--) { s->failed_pc=0x0c05b8c2u; return 0; }
r[2]|=r[1];
goto P_0c05b8c4;
P_0c05b8c4: /* original 1521, guest PC 0x0c05b8c4 */
if(!s->budget--) { s->failed_pc=0x0c05b8c4u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c05b8c6;
P_0c05b8c6: /* original 9081, guest PC 0x0c05b8c6 */
if(!s->budget--) { s->failed_pc=0x0c05b8c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05b9ccu,2);
goto P_0c05b8c8;
P_0c05b8c8: /* original 034e, guest PC 0x0c05b8c8 */
if(!s->budget--) { s->failed_pc=0x0c05b8c8u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b8ca;
P_0c05b8ca: /* original e070, guest PC 0x0c05b8ca */
if(!s->budget--) { s->failed_pc=0x0c05b8cau; return 0; }
r[0]=0x00000070u;
goto P_0c05b8cc;
P_0c05b8cc: /* original 1e36, guest PC 0x0c05b8cc */
if(!s->budget--) { s->failed_pc=0x0c05b8ccu; return 0; }
write(ram,r[14]+24,r[3],4);
goto P_0c05b8ce;
P_0c05b8ce: /* original f346, guest PC 0x0c05b8ce */
if(!s->budget--) { s->failed_pc=0x0c05b8ceu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8d0;
P_0c05b8d0: /* original e020, guest PC 0x0c05b8d0 */
if(!s->budget--) { s->failed_pc=0x0c05b8d0u; return 0; }
r[0]=0x00000020u;
goto P_0c05b8d2;
P_0c05b8d2: /* original fe37, guest PC 0x0c05b8d2 */
if(!s->budget--) { s->failed_pc=0x0c05b8d2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8d4;
P_0c05b8d4: /* original e074, guest PC 0x0c05b8d4 */
if(!s->budget--) { s->failed_pc=0x0c05b8d4u; return 0; }
r[0]=0x00000074u;
goto P_0c05b8d6;
P_0c05b8d6: /* original f346, guest PC 0x0c05b8d6 */
if(!s->budget--) { s->failed_pc=0x0c05b8d6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8d8;
P_0c05b8d8: /* original e024, guest PC 0x0c05b8d8 */
if(!s->budget--) { s->failed_pc=0x0c05b8d8u; return 0; }
r[0]=0x00000024u;
goto P_0c05b8da;
P_0c05b8da: /* original fe37, guest PC 0x0c05b8da */
if(!s->budget--) { s->failed_pc=0x0c05b8dau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8dc;
P_0c05b8dc: /* original e078, guest PC 0x0c05b8dc */
if(!s->budget--) { s->failed_pc=0x0c05b8dcu; return 0; }
r[0]=0x00000078u;
goto P_0c05b8de;
P_0c05b8de: /* original f346, guest PC 0x0c05b8de */
if(!s->budget--) { s->failed_pc=0x0c05b8deu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8e0;
P_0c05b8e0: /* original e028, guest PC 0x0c05b8e0 */
if(!s->budget--) { s->failed_pc=0x0c05b8e0u; return 0; }
r[0]=0x00000028u;
goto P_0c05b8e2;
P_0c05b8e2: /* original fe37, guest PC 0x0c05b8e2 */
if(!s->budget--) { s->failed_pc=0x0c05b8e2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8e4;
P_0c05b8e4: /* original e07c, guest PC 0x0c05b8e4 */
if(!s->budget--) { s->failed_pc=0x0c05b8e4u; return 0; }
r[0]=0x0000007cu;
goto P_0c05b8e6;
P_0c05b8e6: /* original f346, guest PC 0x0c05b8e6 */
if(!s->budget--) { s->failed_pc=0x0c05b8e6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8e8;
P_0c05b8e8: /* original e02c, guest PC 0x0c05b8e8 */
if(!s->budget--) { s->failed_pc=0x0c05b8e8u; return 0; }
r[0]=0x0000002cu;
goto P_0c05b8ea;
P_0c05b8ea: /* original fe37, guest PC 0x0c05b8ea */
if(!s->budget--) { s->failed_pc=0x0c05b8eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8ec;
P_0c05b8ec: /* original 7054, guest PC 0x0c05b8ec */
if(!s->budget--) { s->failed_pc=0x0c05b8ecu; return 0; }
r[0]+=0x00000054u;
goto P_0c05b8ee;
P_0c05b8ee: /* original f346, guest PC 0x0c05b8ee */
if(!s->budget--) { s->failed_pc=0x0c05b8eeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8f0;
P_0c05b8f0: /* original e030, guest PC 0x0c05b8f0 */
if(!s->budget--) { s->failed_pc=0x0c05b8f0u; return 0; }
r[0]=0x00000030u;
goto P_0c05b8f2;
P_0c05b8f2: /* original fe37, guest PC 0x0c05b8f2 */
if(!s->budget--) { s->failed_pc=0x0c05b8f2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8f4;
P_0c05b8f4: /* original 7054, guest PC 0x0c05b8f4 */
if(!s->budget--) { s->failed_pc=0x0c05b8f4u; return 0; }
r[0]+=0x00000054u;
goto P_0c05b8f6;
P_0c05b8f6: /* original f346, guest PC 0x0c05b8f6 */
if(!s->budget--) { s->failed_pc=0x0c05b8f6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b8f8;
P_0c05b8f8: /* original e034, guest PC 0x0c05b8f8 */
if(!s->budget--) { s->failed_pc=0x0c05b8f8u; return 0; }
r[0]=0x00000034u;
goto P_0c05b8fa;
P_0c05b8fa: /* original fe37, guest PC 0x0c05b8fa */
if(!s->budget--) { s->failed_pc=0x0c05b8fau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b8fc;
P_0c05b8fc: /* original 7054, guest PC 0x0c05b8fc */
if(!s->budget--) { s->failed_pc=0x0c05b8fcu; return 0; }
r[0]+=0x00000054u;
goto P_0c05b8fe;
P_0c05b8fe: /* original f346, guest PC 0x0c05b8fe */
if(!s->budget--) { s->failed_pc=0x0c05b8feu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b900;
P_0c05b900: /* original e038, guest PC 0x0c05b900 */
if(!s->budget--) { s->failed_pc=0x0c05b900u; return 0; }
r[0]=0x00000038u;
goto P_0c05b902;
P_0c05b902: /* original fe37, guest PC 0x0c05b902 */
if(!s->budget--) { s->failed_pc=0x0c05b902u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b904;
P_0c05b904: /* original d537, guest PC 0x0c05b904 */
if(!s->budget--) { s->failed_pc=0x0c05b904u; return 0; }
r[5]=read(ram,0x0c05b9e4u,4);
goto P_0c05b906;
P_0c05b906: /* original e120, guest PC 0x0c05b906 */
if(!s->budget--) { s->failed_pc=0x0c05b906u; return 0; }
r[1]=0x00000020u;
goto P_0c05b908;
P_0c05b908: /* original d237, guest PC 0x0c05b908 */
if(!s->budget--) { s->failed_pc=0x0c05b908u; return 0; }
r[2]=read(ram,0x0c05b9e8u,4);
goto P_0c05b90a;
P_0c05b90a: /* original 7054, guest PC 0x0c05b90a */
if(!s->budget--) { s->failed_pc=0x0c05b90au; return 0; }
r[0]+=0x00000054u;
goto P_0c05b90c;
P_0c05b90c: /* original f346, guest PC 0x0c05b90c */
if(!s->budget--) { s->failed_pc=0x0c05b90cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c05b90e;
P_0c05b90e: /* original e03c, guest PC 0x0c05b90e */
if(!s->budget--) { s->failed_pc=0x0c05b90eu; return 0; }
r[0]=0x0000003cu;
goto P_0c05b910;
P_0c05b910: /* original fe37, guest PC 0x0c05b910 */
if(!s->budget--) { s->failed_pc=0x0c05b910u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c05b912;
P_0c05b912: /* original 7064, guest PC 0x0c05b912 */
if(!s->budget--) { s->failed_pc=0x0c05b912u; return 0; }
r[0]+=0x00000064u;
goto P_0c05b914;
P_0c05b914: /* original 034e, guest PC 0x0c05b914 */
if(!s->budget--) { s->failed_pc=0x0c05b914u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c05b916;
P_0c05b916: /* original e040, guest PC 0x0c05b916 */
if(!s->budget--) { s->failed_pc=0x0c05b916u; return 0; }
r[0]=0x00000040u;
goto P_0c05b918;
P_0c05b918: /* original 0e36, guest PC 0x0c05b918 */
if(!s->budget--) { s->failed_pc=0x0c05b918u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c05b91a;
P_0c05b91a: /* original 6473, guest PC 0x0c05b91a */
if(!s->budget--) { s->failed_pc=0x0c05b91au; return 0; }
r[4]=r[7];
goto P_0c05b91c;
P_0c05b91c: /* original 6de2, guest PC 0x0c05b91c */
if(!s->budget--) { s->failed_pc=0x0c05b91cu; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c05b91e;
P_0c05b91e: /* original d330, guest PC 0x0c05b91e */
if(!s->budget--) { s->failed_pc=0x0c05b91eu; return 0; }
r[3]=read(ram,0x0c05b9e0u,4);
goto P_0c05b920;
P_0c05b920: /* original 23d9, guest PC 0x0c05b920 */
if(!s->budget--) { s->failed_pc=0x0c05b920u; return 0; }
r[3]&=r[13];
goto P_0c05b922;
P_0c05b922: /* original 4329, guest PC 0x0c05b922 */
if(!s->budget--) { s->failed_pc=0x0c05b922u; return 0; }
r[3]>>=16;
goto P_0c05b924;
P_0c05b924: /* original 4319, guest PC 0x0c05b924 */
if(!s->budget--) { s->failed_pc=0x0c05b924u; return 0; }
r[3]>>=8;
goto P_0c05b926;
P_0c05b926: /* original 22d9, guest PC 0x0c05b926 */
if(!s->budget--) { s->failed_pc=0x0c05b926u; return 0; }
r[2]&=r[13];
goto P_0c05b928;
P_0c05b928: /* original 4229, guest PC 0x0c05b928 */
if(!s->budget--) { s->failed_pc=0x0c05b928u; return 0; }
r[2]>>=16;
goto P_0c05b92a;
P_0c05b92a: /* original 4209, guest PC 0x0c05b92a */
if(!s->budget--) { s->failed_pc=0x0c05b92au; return 0; }
r[2]>>=2;
goto P_0c05b92c;
P_0c05b92c: /* original 4209, guest PC 0x0c05b92c */
if(!s->budget--) { s->failed_pc=0x0c05b92cu; return 0; }
r[2]>>=2;
goto P_0c05b92e;
P_0c05b92e: /* original 232b, guest PC 0x0c05b92e */
if(!s->budget--) { s->failed_pc=0x0c05b92eu; return 0; }
r[3]|=r[2];
goto P_0c05b930;
P_0c05b930: /* original 20d9, guest PC 0x0c05b930 */
if(!s->budget--) { s->failed_pc=0x0c05b930u; return 0; }
r[0]&=r[13];
goto P_0c05b932;
P_0c05b932: /* original 4009, guest PC 0x0c05b932 */
if(!s->budget--) { s->failed_pc=0x0c05b932u; return 0; }
r[0]>>=2;
goto P_0c05b934;
P_0c05b934: /* original 4001, guest PC 0x0c05b934 */
if(!s->budget--) { s->failed_pc=0x0c05b934u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05b936;
P_0c05b936: /* original 230b, guest PC 0x0c05b936 */
if(!s->budget--) { s->failed_pc=0x0c05b936u; return 0; }
r[3]|=r[0];
goto P_0c05b938;
P_0c05b938: /* original 21d9, guest PC 0x0c05b938 */
if(!s->budget--) { s->failed_pc=0x0c05b938u; return 0; }
r[1]&=r[13];
goto P_0c05b93a;
P_0c05b93a: /* original 4109, guest PC 0x0c05b93a */
if(!s->budget--) { s->failed_pc=0x0c05b93au; return 0; }
r[1]>>=2;
goto P_0c05b93c;
P_0c05b93c: /* original 4101, guest PC 0x0c05b93c */
if(!s->budget--) { s->failed_pc=0x0c05b93cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c05b93e;
P_0c05b93e: /* original 231b, guest PC 0x0c05b93e */
if(!s->budget--) { s->failed_pc=0x0c05b93eu; return 0; }
r[3]|=r[1];
goto P_0c05b940;
P_0c05b940: /* original e210, guest PC 0x0c05b940 */
if(!s->budget--) { s->failed_pc=0x0c05b940u; return 0; }
r[2]=0x00000010u;
goto P_0c05b942;
P_0c05b942: /* original 22d9, guest PC 0x0c05b942 */
if(!s->budget--) { s->failed_pc=0x0c05b942u; return 0; }
r[2]&=r[13];
goto P_0c05b944;
P_0c05b944: /* original d029, guest PC 0x0c05b944 */
if(!s->budget--) { s->failed_pc=0x0c05b944u; return 0; }
r[0]=read(ram,0x0c05b9ecu,4);
goto P_0c05b946;
P_0c05b946: /* original 4209, guest PC 0x0c05b946 */
if(!s->budget--) { s->failed_pc=0x0c05b946u; return 0; }
r[2]>>=2;
goto P_0c05b948;
P_0c05b948: /* original 4201, guest PC 0x0c05b948 */
if(!s->budget--) { s->failed_pc=0x0c05b948u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]>>=1;
goto P_0c05b94a;
P_0c05b94a: /* original 232b, guest PC 0x0c05b94a */
if(!s->budget--) { s->failed_pc=0x0c05b94au; return 0; }
r[3]|=r[2];
goto P_0c05b94c;
P_0c05b94c: /* original e104, guest PC 0x0c05b94c */
if(!s->budget--) { s->failed_pc=0x0c05b94cu; return 0; }
r[1]=0x00000004u;
goto P_0c05b94e;
P_0c05b94e: /* original 21d9, guest PC 0x0c05b94e */
if(!s->budget--) { s->failed_pc=0x0c05b94eu; return 0; }
r[1]&=r[13];
goto P_0c05b950;
P_0c05b950: /* original 4109, guest PC 0x0c05b950 */
if(!s->budget--) { s->failed_pc=0x0c05b950u; return 0; }
r[1]>>=2;
goto P_0c05b952;
P_0c05b952: /* original 231b, guest PC 0x0c05b952 */
if(!s->budget--) { s->failed_pc=0x0c05b952u; return 0; }
r[3]|=r[1];
goto P_0c05b954;
P_0c05b954: /* original 4308, guest PC 0x0c05b954 */
if(!s->budget--) { s->failed_pc=0x0c05b954u; return 0; }
r[3]<<=2;
goto P_0c05b956;
P_0c05b956: /* original 023e, guest PC 0x0c05b956 */
if(!s->budget--) { s->failed_pc=0x0c05b956u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05b958;
P_0c05b958: /* original d325, guest PC 0x0c05b958 */
if(!s->budget--) { s->failed_pc=0x0c05b958u; return 0; }
r[3]=read(ram,0x0c05b9f0u,4);
goto P_0c05b95a;
P_0c05b95a: /* original 2522, guest PC 0x0c05b95a */
if(!s->budget--) { s->failed_pc=0x0c05b95au; return 0; }
write(ram,r[5],r[2],4);
goto P_0c05b95c;
P_0c05b95c: /* original 62e2, guest PC 0x0c05b95c */
if(!s->budget--) { s->failed_pc=0x0c05b95cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c05b95e;
P_0c05b95e: /* original 2422, guest PC 0x0c05b95e */
if(!s->budget--) { s->failed_pc=0x0c05b95eu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b960;
P_0c05b960: /* original 61e2, guest PC 0x0c05b960 */
if(!s->budget--) { s->failed_pc=0x0c05b960u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c05b962;
P_0c05b962: /* original 7404, guest PC 0x0c05b962 */
if(!s->budget--) { s->failed_pc=0x0c05b962u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b964;
P_0c05b964: /* original 2139, guest PC 0x0c05b964 */
if(!s->budget--) { s->failed_pc=0x0c05b964u; return 0; }
r[1]&=r[3];
goto P_0c05b966;
P_0c05b966: /* original 4129, guest PC 0x0c05b966 */
if(!s->budget--) { s->failed_pc=0x0c05b966u; return 0; }
r[1]>>=16;
goto P_0c05b968;
P_0c05b968: /* original 4119, guest PC 0x0c05b968 */
if(!s->budget--) { s->failed_pc=0x0c05b968u; return 0; }
r[1]>>=8;
goto P_0c05b96a;
P_0c05b96a: /* original 6013, guest PC 0x0c05b96a */
if(!s->budget--) { s->failed_pc=0x0c05b96au; return 0; }
r[0]=r[1];
goto P_0c05b96c;
P_0c05b96c: /* original 0009, guest PC 0x0c05b96c */
if(!s->budget--) { s->failed_pc=0x0c05b96cu; return 0; }
goto P_0c05b96e;
P_0c05b96e: /* original c801, guest PC 0x0c05b96e */
if(!s->budget--) { s->failed_pc=0x0c05b96eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c05b970;
P_0c05b970: /* original 8d02, guest PC 0x0c05b970 */
if(!s->budget--) { s->failed_pc=0x0c05b970u; return 0; }
cond=r[17]&1u;
write(ram,r[6],r[1],4);
if(cond) { goto P_0c05b978; }
goto P_0c05b974;
P_0c05b972: /* original 2612, guest PC 0x0c05b972 */
if(!s->budget--) { s->failed_pc=0x0c05b972u; return 0; }
write(ram,r[6],r[1],4);
goto P_0c05b974;
P_0c05b974: /* original a0cf, guest PC 0x0c05b974 */
if(!s->budget--) { s->failed_pc=0x0c05b974u; return 0; }
goto P_0c05bb16;
P_0c05b976: /* original 0009, guest PC 0x0c05b976 */
if(!s->budget--) { s->failed_pc=0x0c05b976u; return 0; }
goto P_0c05b978;
P_0c05b978: /* original 52e4, guest PC 0x0c05b978 */
if(!s->budget--) { s->failed_pc=0x0c05b978u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c05b97a;
P_0c05b97a: /* original 6de3, guest PC 0x0c05b97a */
if(!s->budget--) { s->failed_pc=0x0c05b97au; return 0; }
r[13]=r[14];
goto P_0c05b97c;
P_0c05b97c: /* original 2422, guest PC 0x0c05b97c */
if(!s->budget--) { s->failed_pc=0x0c05b97cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b97e;
P_0c05b97e: /* original 7d10, guest PC 0x0c05b97e */
if(!s->budget--) { s->failed_pc=0x0c05b97eu; return 0; }
r[13]+=0x00000010u;
goto P_0c05b980;
P_0c05b980: /* original 52e5, guest PC 0x0c05b980 */
if(!s->budget--) { s->failed_pc=0x0c05b980u; return 0; }
r[2]=read(ram,r[14]+20,4);
goto P_0c05b982;
P_0c05b982: /* original 7404, guest PC 0x0c05b982 */
if(!s->budget--) { s->failed_pc=0x0c05b982u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b984;
P_0c05b984: /* original 2422, guest PC 0x0c05b984 */
if(!s->budget--) { s->failed_pc=0x0c05b984u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b986;
P_0c05b986: /* original 7404, guest PC 0x0c05b986 */
if(!s->budget--) { s->failed_pc=0x0c05b986u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b988;
P_0c05b988: /* original 52e6, guest PC 0x0c05b988 */
if(!s->budget--) { s->failed_pc=0x0c05b988u; return 0; }
r[2]=read(ram,r[14]+24,4);
goto P_0c05b98a;
P_0c05b98a: /* original 2422, guest PC 0x0c05b98a */
if(!s->budget--) { s->failed_pc=0x0c05b98au; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05b98c;
P_0c05b98c: /* original 6052, guest PC 0x0c05b98c */
if(!s->budget--) { s->failed_pc=0x0c05b98cu; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c05b98e;
P_0c05b98e: /* original 8800, guest PC 0x0c05b98e */
if(!s->budget--) { s->failed_pc=0x0c05b98eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05b990;
P_0c05b990: /* original 8d0c, guest PC 0x0c05b990 */
if(!s->budget--) { s->failed_pc=0x0c05b990u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c05b9ac; }
goto P_0c05b994;
P_0c05b992: /* original 7404, guest PC 0x0c05b992 */
if(!s->budget--) { s->failed_pc=0x0c05b992u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b994;
P_0c05b994: /* original 8801, guest PC 0x0c05b994 */
if(!s->budget--) { s->failed_pc=0x0c05b994u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05b996;
P_0c05b996: /* original 890b, guest PC 0x0c05b996 */
if(!s->budget--) { s->failed_pc=0x0c05b996u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b9b0; }
goto P_0c05b998;
P_0c05b998: /* original 8802, guest PC 0x0c05b998 */
if(!s->budget--) { s->failed_pc=0x0c05b998u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05b99a;
P_0c05b99a: /* original 892b, guest PC 0x0c05b99a */
if(!s->budget--) { s->failed_pc=0x0c05b99au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05b9f4; }
goto P_0c05b99c;
P_0c05b99c: /* original 8803, guest PC 0x0c05b99c */
if(!s->budget--) { s->failed_pc=0x0c05b99cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05b99e;
P_0c05b99e: /* original 8946, guest PC 0x0c05b99e */
if(!s->budget--) { s->failed_pc=0x0c05b99eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ba2e; }
goto P_0c05b9a0;
P_0c05b9a0: /* original 8804, guest PC 0x0c05b9a0 */
if(!s->budget--) { s->failed_pc=0x0c05b9a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05b9a2;
P_0c05b9a2: /* original 894c, guest PC 0x0c05b9a2 */
if(!s->budget--) { s->failed_pc=0x0c05b9a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ba3e; }
goto P_0c05b9a4;
P_0c05b9a4: /* original 8810, guest PC 0x0c05b9a4 */
if(!s->budget--) { s->failed_pc=0x0c05b9a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05b9a6;
P_0c05b9a6: /* original 8977, guest PC 0x0c05b9a6 */
if(!s->budget--) { s->failed_pc=0x0c05b9a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05ba98; }
goto P_0c05b9a8;
P_0c05b9a8: /* original a0b9, guest PC 0x0c05b9a8 */
if(!s->budget--) { s->failed_pc=0x0c05b9a8u; return 0; }
goto P_0c05bb1e;
P_0c05b9aa: /* original 0009, guest PC 0x0c05b9aa */
if(!s->budget--) { s->failed_pc=0x0c05b9aau; return 0; }
goto P_0c05b9ac;
P_0c05b9ac: /* original a0b7, guest PC 0x0c05b9ac */
if(!s->budget--) { s->failed_pc=0x0c05b9acu; return 0; }
r[4]+=0x00000010u;
goto P_0c05bb1e;
P_0c05b9ae: /* original 7410, guest PC 0x0c05b9ae */
if(!s->budget--) { s->failed_pc=0x0c05b9aeu; return 0; }
r[4]+=0x00000010u;
goto P_0c05b9b0;
P_0c05b9b0: /* original 61d3, guest PC 0x0c05b9b0 */
if(!s->budget--) { s->failed_pc=0x0c05b9b0u; return 0; }
r[1]=r[13];
goto P_0c05b9b2;
P_0c05b9b2: /* original 5014, guest PC 0x0c05b9b2 */
if(!s->budget--) { s->failed_pc=0x0c05b9b2u; return 0; }
r[0]=read(ram,r[1]+16,4);
goto P_0c05b9b4;
P_0c05b9b4: /* original 2402, guest PC 0x0c05b9b4 */
if(!s->budget--) { s->failed_pc=0x0c05b9b4u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05b9b6;
P_0c05b9b6: /* original 7404, guest PC 0x0c05b9b6 */
if(!s->budget--) { s->failed_pc=0x0c05b9b6u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b9b8;
P_0c05b9b8: /* original 61e3, guest PC 0x0c05b9b8 */
if(!s->budget--) { s->failed_pc=0x0c05b9b8u; return 0; }
r[1]=r[14];
goto P_0c05b9ba;
P_0c05b9ba: /* original 5019, guest PC 0x0c05b9ba */
if(!s->budget--) { s->failed_pc=0x0c05b9bau; return 0; }
r[0]=read(ram,r[1]+36,4);
goto P_0c05b9bc;
P_0c05b9bc: /* original 2402, guest PC 0x0c05b9bc */
if(!s->budget--) { s->failed_pc=0x0c05b9bcu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05b9be;
P_0c05b9be: /* original 7404, guest PC 0x0c05b9be */
if(!s->budget--) { s->failed_pc=0x0c05b9beu; return 0; }
r[4]+=0x00000004u;
goto P_0c05b9c0;
P_0c05b9c0: /* original 501a, guest PC 0x0c05b9c0 */
if(!s->budget--) { s->failed_pc=0x0c05b9c0u; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c05b9c2;
P_0c05b9c2: /* original 2402, guest PC 0x0c05b9c2 */
if(!s->budget--) { s->failed_pc=0x0c05b9c2u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05b9c4;
P_0c05b9c4: /* original 7404, guest PC 0x0c05b9c4 */
if(!s->budget--) { s->failed_pc=0x0c05b9c4u; return 0; }
r[4]+=0x00000004u;
goto P_0c05b9c6;
P_0c05b9c6: /* original a02f, guest PC 0x0c05b9c6 */
if(!s->budget--) { s->failed_pc=0x0c05b9c6u; return 0; }
r[1]+=0x0000002cu;
goto P_0c05ba28;
P_0c05b9c8: /* original 712c, guest PC 0x0c05b9c8 */
if(!s->budget--) { s->failed_pc=0x0c05b9c8u; return 0; }
r[1]+=0x0000002cu;
if(!vf3_matrix_family(0x0c05b9cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05b9cau; return 0; } return 1;
P_0c05b9f4: /* original 7410, guest PC 0x0c05b9f4 */
if(!s->budget--) { s->failed_pc=0x0c05b9f4u; return 0; }
r[4]+=0x00000010u;
goto P_0c05b9f6;
P_0c05b9f6: /* original 62d3, guest PC 0x0c05b9f6 */
if(!s->budget--) { s->failed_pc=0x0c05b9f6u; return 0; }
r[2]=r[13];
goto P_0c05b9f8;
P_0c05b9f8: /* original 7210, guest PC 0x0c05b9f8 */
if(!s->budget--) { s->failed_pc=0x0c05b9f8u; return 0; }
r[2]+=0x00000010u;
goto P_0c05b9fa;
P_0c05b9fa: /* original 61e3, guest PC 0x0c05b9fa */
if(!s->budget--) { s->failed_pc=0x0c05b9fau; return 0; }
r[1]=r[14];
goto P_0c05b9fc;
P_0c05b9fc: /* original 6022, guest PC 0x0c05b9fc */
if(!s->budget--) { s->failed_pc=0x0c05b9fcu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05b9fe;
P_0c05b9fe: /* original 2402, guest PC 0x0c05b9fe */
if(!s->budget--) { s->failed_pc=0x0c05b9feu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba00;
P_0c05ba00: /* original 5019, guest PC 0x0c05ba00 */
if(!s->budget--) { s->failed_pc=0x0c05ba00u; return 0; }
r[0]=read(ram,r[1]+36,4);
goto P_0c05ba02;
P_0c05ba02: /* original 7404, guest PC 0x0c05ba02 */
if(!s->budget--) { s->failed_pc=0x0c05ba02u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba04;
P_0c05ba04: /* original 2402, guest PC 0x0c05ba04 */
if(!s->budget--) { s->failed_pc=0x0c05ba04u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba06;
P_0c05ba06: /* original 7404, guest PC 0x0c05ba06 */
if(!s->budget--) { s->failed_pc=0x0c05ba06u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba08;
P_0c05ba08: /* original 501a, guest PC 0x0c05ba08 */
if(!s->budget--) { s->failed_pc=0x0c05ba08u; return 0; }
r[0]=read(ram,r[1]+40,4);
goto P_0c05ba0a;
P_0c05ba0a: /* original 2402, guest PC 0x0c05ba0a */
if(!s->budget--) { s->failed_pc=0x0c05ba0au; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba0c;
P_0c05ba0c: /* original 501b, guest PC 0x0c05ba0c */
if(!s->budget--) { s->failed_pc=0x0c05ba0cu; return 0; }
r[0]=read(ram,r[1]+44,4);
goto P_0c05ba0e;
P_0c05ba0e: /* original 7404, guest PC 0x0c05ba0e */
if(!s->budget--) { s->failed_pc=0x0c05ba0eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba10;
P_0c05ba10: /* original 2402, guest PC 0x0c05ba10 */
if(!s->budget--) { s->failed_pc=0x0c05ba10u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba12;
P_0c05ba12: /* original 7404, guest PC 0x0c05ba12 */
if(!s->budget--) { s->failed_pc=0x0c05ba12u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba14;
P_0c05ba14: /* original 501c, guest PC 0x0c05ba14 */
if(!s->budget--) { s->failed_pc=0x0c05ba14u; return 0; }
r[0]=read(ram,r[1]+48,4);
goto P_0c05ba16;
P_0c05ba16: /* original 2402, guest PC 0x0c05ba16 */
if(!s->budget--) { s->failed_pc=0x0c05ba16u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba18;
P_0c05ba18: /* original 501d, guest PC 0x0c05ba18 */
if(!s->budget--) { s->failed_pc=0x0c05ba18u; return 0; }
r[0]=read(ram,r[1]+52,4);
goto P_0c05ba1a;
P_0c05ba1a: /* original 7404, guest PC 0x0c05ba1a */
if(!s->budget--) { s->failed_pc=0x0c05ba1au; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba1c;
P_0c05ba1c: /* original 2402, guest PC 0x0c05ba1c */
if(!s->budget--) { s->failed_pc=0x0c05ba1cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba1e;
P_0c05ba1e: /* original 7404, guest PC 0x0c05ba1e */
if(!s->budget--) { s->failed_pc=0x0c05ba1eu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba20;
P_0c05ba20: /* original 501e, guest PC 0x0c05ba20 */
if(!s->budget--) { s->failed_pc=0x0c05ba20u; return 0; }
r[0]=read(ram,r[1]+56,4);
goto P_0c05ba22;
P_0c05ba22: /* original 713c, guest PC 0x0c05ba22 */
if(!s->budget--) { s->failed_pc=0x0c05ba22u; return 0; }
r[1]+=0x0000003cu;
goto P_0c05ba24;
P_0c05ba24: /* original 2402, guest PC 0x0c05ba24 */
if(!s->budget--) { s->failed_pc=0x0c05ba24u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba26;
P_0c05ba26: /* original 7404, guest PC 0x0c05ba26 */
if(!s->budget--) { s->failed_pc=0x0c05ba26u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba28;
P_0c05ba28: /* original 6012, guest PC 0x0c05ba28 */
if(!s->budget--) { s->failed_pc=0x0c05ba28u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05ba2a;
P_0c05ba2a: /* original a033, guest PC 0x0c05ba2a */
if(!s->budget--) { s->failed_pc=0x0c05ba2au; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba94;
P_0c05ba2c: /* original 2402, guest PC 0x0c05ba2c */
if(!s->budget--) { s->failed_pc=0x0c05ba2cu; return 0; }
write(ram,r[4],r[0],4);
goto P_0c05ba2e;
P_0c05ba2e: /* original e044, guest PC 0x0c05ba2e */
if(!s->budget--) { s->failed_pc=0x0c05ba2eu; return 0; }
r[0]=0x00000044u;
goto P_0c05ba30;
P_0c05ba30: /* original 02ee, guest PC 0x0c05ba30 */
if(!s->budget--) { s->failed_pc=0x0c05ba30u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba32;
P_0c05ba32: /* original e048, guest PC 0x0c05ba32 */
if(!s->budget--) { s->failed_pc=0x0c05ba32u; return 0; }
r[0]=0x00000048u;
goto P_0c05ba34;
P_0c05ba34: /* original 2422, guest PC 0x0c05ba34 */
if(!s->budget--) { s->failed_pc=0x0c05ba34u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba36;
P_0c05ba36: /* original 7404, guest PC 0x0c05ba36 */
if(!s->budget--) { s->failed_pc=0x0c05ba36u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba38;
P_0c05ba38: /* original 02ee, guest PC 0x0c05ba38 */
if(!s->budget--) { s->failed_pc=0x0c05ba38u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba3a;
P_0c05ba3a: /* original a06a, guest PC 0x0c05ba3a */
if(!s->budget--) { s->failed_pc=0x0c05ba3au; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05bb12;
P_0c05ba3c: /* original 2422, guest PC 0x0c05ba3c */
if(!s->budget--) { s->failed_pc=0x0c05ba3cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba3e;
P_0c05ba3e: /* original e044, guest PC 0x0c05ba3e */
if(!s->budget--) { s->failed_pc=0x0c05ba3eu; return 0; }
r[0]=0x00000044u;
goto P_0c05ba40;
P_0c05ba40: /* original 02ee, guest PC 0x0c05ba40 */
if(!s->budget--) { s->failed_pc=0x0c05ba40u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba42;
P_0c05ba42: /* original 61e3, guest PC 0x0c05ba42 */
if(!s->budget--) { s->failed_pc=0x0c05ba42u; return 0; }
r[1]=r[14];
goto P_0c05ba44;
P_0c05ba44: /* original 2422, guest PC 0x0c05ba44 */
if(!s->budget--) { s->failed_pc=0x0c05ba44u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba46;
P_0c05ba46: /* original e048, guest PC 0x0c05ba46 */
if(!s->budget--) { s->failed_pc=0x0c05ba46u; return 0; }
r[0]=0x00000048u;
goto P_0c05ba48;
P_0c05ba48: /* original 02ee, guest PC 0x0c05ba48 */
if(!s->budget--) { s->failed_pc=0x0c05ba48u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05ba4a;
P_0c05ba4a: /* original 7404, guest PC 0x0c05ba4a */
if(!s->budget--) { s->failed_pc=0x0c05ba4au; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba4c;
P_0c05ba4c: /* original 2422, guest PC 0x0c05ba4c */
if(!s->budget--) { s->failed_pc=0x0c05ba4cu; return 0; }
write(ram,r[4],r[2],4);
goto P_0c05ba4e;
P_0c05ba4e: /* original 740c, guest PC 0x0c05ba4e */
if(!s->budget--) { s->failed_pc=0x0c05ba4eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c05ba50;
P_0c05ba50: /* original 5118, guest PC 0x0c05ba50 */
if(!s->budget--) { s->failed_pc=0x0c05ba50u; return 0; }
r[1]=read(ram,r[1]+32,4);
goto P_0c05ba52;
P_0c05ba52: /* original 2412, guest PC 0x0c05ba52 */
if(!s->budget--) { s->failed_pc=0x0c05ba52u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba54;
P_0c05ba54: /* original 7404, guest PC 0x0c05ba54 */
if(!s->budget--) { s->failed_pc=0x0c05ba54u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba56;
P_0c05ba56: /* original 61e3, guest PC 0x0c05ba56 */
if(!s->budget--) { s->failed_pc=0x0c05ba56u; return 0; }
r[1]=r[14];
goto P_0c05ba58;
P_0c05ba58: /* original 5119, guest PC 0x0c05ba58 */
if(!s->budget--) { s->failed_pc=0x0c05ba58u; return 0; }
r[1]=read(ram,r[1]+36,4);
goto P_0c05ba5a;
P_0c05ba5a: /* original 2412, guest PC 0x0c05ba5a */
if(!s->budget--) { s->failed_pc=0x0c05ba5au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba5c;
P_0c05ba5c: /* original 7404, guest PC 0x0c05ba5c */
if(!s->budget--) { s->failed_pc=0x0c05ba5cu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba5e;
P_0c05ba5e: /* original 61e3, guest PC 0x0c05ba5e */
if(!s->budget--) { s->failed_pc=0x0c05ba5eu; return 0; }
r[1]=r[14];
goto P_0c05ba60;
P_0c05ba60: /* original 511a, guest PC 0x0c05ba60 */
if(!s->budget--) { s->failed_pc=0x0c05ba60u; return 0; }
r[1]=read(ram,r[1]+40,4);
goto P_0c05ba62;
P_0c05ba62: /* original 2412, guest PC 0x0c05ba62 */
if(!s->budget--) { s->failed_pc=0x0c05ba62u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba64;
P_0c05ba64: /* original 7404, guest PC 0x0c05ba64 */
if(!s->budget--) { s->failed_pc=0x0c05ba64u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba66;
P_0c05ba66: /* original 61e3, guest PC 0x0c05ba66 */
if(!s->budget--) { s->failed_pc=0x0c05ba66u; return 0; }
r[1]=r[14];
goto P_0c05ba68;
P_0c05ba68: /* original 511b, guest PC 0x0c05ba68 */
if(!s->budget--) { s->failed_pc=0x0c05ba68u; return 0; }
r[1]=read(ram,r[1]+44,4);
goto P_0c05ba6a;
P_0c05ba6a: /* original 2412, guest PC 0x0c05ba6a */
if(!s->budget--) { s->failed_pc=0x0c05ba6au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba6c;
P_0c05ba6c: /* original 7404, guest PC 0x0c05ba6c */
if(!s->budget--) { s->failed_pc=0x0c05ba6cu; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba6e;
P_0c05ba6e: /* original 61e3, guest PC 0x0c05ba6e */
if(!s->budget--) { s->failed_pc=0x0c05ba6eu; return 0; }
r[1]=r[14];
goto P_0c05ba70;
P_0c05ba70: /* original 7150, guest PC 0x0c05ba70 */
if(!s->budget--) { s->failed_pc=0x0c05ba70u; return 0; }
r[1]+=0x00000050u;
goto P_0c05ba72;
P_0c05ba72: /* original 6112, guest PC 0x0c05ba72 */
if(!s->budget--) { s->failed_pc=0x0c05ba72u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba74;
P_0c05ba74: /* original 2412, guest PC 0x0c05ba74 */
if(!s->budget--) { s->failed_pc=0x0c05ba74u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba76;
P_0c05ba76: /* original 7404, guest PC 0x0c05ba76 */
if(!s->budget--) { s->failed_pc=0x0c05ba76u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba78;
P_0c05ba78: /* original 61e3, guest PC 0x0c05ba78 */
if(!s->budget--) { s->failed_pc=0x0c05ba78u; return 0; }
r[1]=r[14];
goto P_0c05ba7a;
P_0c05ba7a: /* original 7154, guest PC 0x0c05ba7a */
if(!s->budget--) { s->failed_pc=0x0c05ba7au; return 0; }
r[1]+=0x00000054u;
goto P_0c05ba7c;
P_0c05ba7c: /* original 6112, guest PC 0x0c05ba7c */
if(!s->budget--) { s->failed_pc=0x0c05ba7cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba7e;
P_0c05ba7e: /* original 2412, guest PC 0x0c05ba7e */
if(!s->budget--) { s->failed_pc=0x0c05ba7eu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba80;
P_0c05ba80: /* original 7404, guest PC 0x0c05ba80 */
if(!s->budget--) { s->failed_pc=0x0c05ba80u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba82;
P_0c05ba82: /* original 61e3, guest PC 0x0c05ba82 */
if(!s->budget--) { s->failed_pc=0x0c05ba82u; return 0; }
r[1]=r[14];
goto P_0c05ba84;
P_0c05ba84: /* original 7158, guest PC 0x0c05ba84 */
if(!s->budget--) { s->failed_pc=0x0c05ba84u; return 0; }
r[1]+=0x00000058u;
goto P_0c05ba86;
P_0c05ba86: /* original 6112, guest PC 0x0c05ba86 */
if(!s->budget--) { s->failed_pc=0x0c05ba86u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba88;
P_0c05ba88: /* original 2412, guest PC 0x0c05ba88 */
if(!s->budget--) { s->failed_pc=0x0c05ba88u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba8a;
P_0c05ba8a: /* original 7404, guest PC 0x0c05ba8a */
if(!s->budget--) { s->failed_pc=0x0c05ba8au; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba8c;
P_0c05ba8c: /* original 61e3, guest PC 0x0c05ba8c */
if(!s->budget--) { s->failed_pc=0x0c05ba8cu; return 0; }
r[1]=r[14];
goto P_0c05ba8e;
P_0c05ba8e: /* original 715c, guest PC 0x0c05ba8e */
if(!s->budget--) { s->failed_pc=0x0c05ba8eu; return 0; }
r[1]+=0x0000005cu;
goto P_0c05ba90;
P_0c05ba90: /* original 6112, guest PC 0x0c05ba90 */
if(!s->budget--) { s->failed_pc=0x0c05ba90u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05ba92;
P_0c05ba92: /* original 2412, guest PC 0x0c05ba92 */
if(!s->budget--) { s->failed_pc=0x0c05ba92u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05ba94;
P_0c05ba94: /* original a043, guest PC 0x0c05ba94 */
if(!s->budget--) { s->failed_pc=0x0c05ba94u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bb1e;
P_0c05ba96: /* original 7404, guest PC 0x0c05ba96 */
if(!s->budget--) { s->failed_pc=0x0c05ba96u; return 0; }
r[4]+=0x00000004u;
goto P_0c05ba98;
P_0c05ba98: /* original c725, guest PC 0x0c05ba98 */
if(!s->budget--) { s->failed_pc=0x0c05ba98u; return 0; }
r[0]=code_base|0x0005bb30u;
goto P_0c05ba9a;
P_0c05ba9a: /* original f408, guest PC 0x0c05ba9a */
if(!s->budget--) { s->failed_pc=0x0c05ba9au; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c05ba9c;
P_0c05ba9c: /* original e010, guest PC 0x0c05ba9c */
if(!s->budget--) { s->failed_pc=0x0c05ba9cu; return 0; }
r[0]=0x00000010u;
goto P_0c05ba9e;
P_0c05ba9e: /* original f3d6, guest PC 0x0c05ba9e */
if(!s->budget--) { s->failed_pc=0x0c05ba9eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05baa0;
P_0c05baa0: /* original f342, guest PC 0x0c05baa0 */
if(!s->budget--) { s->failed_pc=0x0c05baa0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05baa2;
P_0c05baa2: /* original e014, guest PC 0x0c05baa2 */
if(!s->budget--) { s->failed_pc=0x0c05baa2u; return 0; }
r[0]=0x00000014u;
goto P_0c05baa4;
P_0c05baa4: /* original f33d, guest PC 0x0c05baa4 */
if(!s->budget--) { s->failed_pc=0x0c05baa4u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05baa6;
P_0c05baa6: /* original 015a, guest PC 0x0c05baa6 */
if(!s->budget--) { s->failed_pc=0x0c05baa6u; return 0; }
r[1]=r[53];
goto P_0c05baa8;
P_0c05baa8: /* original f3d6, guest PC 0x0c05baa8 */
if(!s->budget--) { s->failed_pc=0x0c05baa8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05baaa;
P_0c05baaa: /* original 4128, guest PC 0x0c05baaa */
if(!s->budget--) { s->failed_pc=0x0c05baaau; return 0; }
r[1]<<=16;
goto P_0c05baac;
P_0c05baac: /* original 4118, guest PC 0x0c05baac */
if(!s->budget--) { s->failed_pc=0x0c05baacu; return 0; }
r[1]<<=8;
goto P_0c05baae;
P_0c05baae: /* original f342, guest PC 0x0c05baae */
if(!s->budget--) { s->failed_pc=0x0c05baaeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bab0;
P_0c05bab0: /* original f33d, guest PC 0x0c05bab0 */
if(!s->budget--) { s->failed_pc=0x0c05bab0u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bab2;
P_0c05bab2: /* original 005a, guest PC 0x0c05bab2 */
if(!s->budget--) { s->failed_pc=0x0c05bab2u; return 0; }
r[0]=r[53];
goto P_0c05bab4;
P_0c05bab4: /* original 4028, guest PC 0x0c05bab4 */
if(!s->budget--) { s->failed_pc=0x0c05bab4u; return 0; }
r[0]<<=16;
goto P_0c05bab6;
P_0c05bab6: /* original 210b, guest PC 0x0c05bab6 */
if(!s->budget--) { s->failed_pc=0x0c05bab6u; return 0; }
r[1]|=r[0];
goto P_0c05bab8;
P_0c05bab8: /* original e018, guest PC 0x0c05bab8 */
if(!s->budget--) { s->failed_pc=0x0c05bab8u; return 0; }
r[0]=0x00000018u;
goto P_0c05baba;
P_0c05baba: /* original f3d6, guest PC 0x0c05baba */
if(!s->budget--) { s->failed_pc=0x0c05babau; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05babc;
P_0c05babc: /* original f342, guest PC 0x0c05babc */
if(!s->budget--) { s->failed_pc=0x0c05babcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05babe;
P_0c05babe: /* original f33d, guest PC 0x0c05babe */
if(!s->budget--) { s->failed_pc=0x0c05babeu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bac0;
P_0c05bac0: /* original 005a, guest PC 0x0c05bac0 */
if(!s->budget--) { s->failed_pc=0x0c05bac0u; return 0; }
r[0]=r[53];
goto P_0c05bac2;
P_0c05bac2: /* original 4018, guest PC 0x0c05bac2 */
if(!s->budget--) { s->failed_pc=0x0c05bac2u; return 0; }
r[0]<<=8;
goto P_0c05bac4;
P_0c05bac4: /* original 210b, guest PC 0x0c05bac4 */
if(!s->budget--) { s->failed_pc=0x0c05bac4u; return 0; }
r[1]|=r[0];
goto P_0c05bac6;
P_0c05bac6: /* original e01c, guest PC 0x0c05bac6 */
if(!s->budget--) { s->failed_pc=0x0c05bac6u; return 0; }
r[0]=0x0000001cu;
goto P_0c05bac8;
P_0c05bac8: /* original f3d6, guest PC 0x0c05bac8 */
if(!s->budget--) { s->failed_pc=0x0c05bac8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c05baca;
P_0c05baca: /* original f342, guest PC 0x0c05baca */
if(!s->budget--) { s->failed_pc=0x0c05bacau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bacc;
P_0c05bacc: /* original f33d, guest PC 0x0c05bacc */
if(!s->budget--) { s->failed_pc=0x0c05baccu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bace;
P_0c05bace: /* original 005a, guest PC 0x0c05bace */
if(!s->budget--) { s->failed_pc=0x0c05baceu; return 0; }
r[0]=r[53];
goto P_0c05bad0;
P_0c05bad0: /* original 210b, guest PC 0x0c05bad0 */
if(!s->budget--) { s->failed_pc=0x0c05bad0u; return 0; }
r[1]|=r[0];
goto P_0c05bad2;
P_0c05bad2: /* original 2412, guest PC 0x0c05bad2 */
if(!s->budget--) { s->failed_pc=0x0c05bad2u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bad4;
P_0c05bad4: /* original 7404, guest PC 0x0c05bad4 */
if(!s->budget--) { s->failed_pc=0x0c05bad4u; return 0; }
r[4]+=0x00000004u;
goto P_0c05bad6;
P_0c05bad6: /* original 65e3, guest PC 0x0c05bad6 */
if(!s->budget--) { s->failed_pc=0x0c05bad6u; return 0; }
r[5]=r[14];
goto P_0c05bad8;
P_0c05bad8: /* original 7510, guest PC 0x0c05bad8 */
if(!s->budget--) { s->failed_pc=0x0c05bad8u; return 0; }
r[5]+=0x00000010u;
goto P_0c05bada;
P_0c05bada: /* original e020, guest PC 0x0c05bada */
if(!s->budget--) { s->failed_pc=0x0c05badau; return 0; }
r[0]=0x00000020u;
goto P_0c05badc;
P_0c05badc: /* original f356, guest PC 0x0c05badc */
if(!s->budget--) { s->failed_pc=0x0c05badcu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bade;
P_0c05bade: /* original e024, guest PC 0x0c05bade */
if(!s->budget--) { s->failed_pc=0x0c05badeu; return 0; }
r[0]=0x00000024u;
goto P_0c05bae0;
P_0c05bae0: /* original f342, guest PC 0x0c05bae0 */
if(!s->budget--) { s->failed_pc=0x0c05bae0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bae2;
P_0c05bae2: /* original f33d, guest PC 0x0c05bae2 */
if(!s->budget--) { s->failed_pc=0x0c05bae2u; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bae4;
P_0c05bae4: /* original f356, guest PC 0x0c05bae4 */
if(!s->budget--) { s->failed_pc=0x0c05bae4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bae6;
P_0c05bae6: /* original 015a, guest PC 0x0c05bae6 */
if(!s->budget--) { s->failed_pc=0x0c05bae6u; return 0; }
r[1]=r[53];
goto P_0c05bae8;
P_0c05bae8: /* original 4128, guest PC 0x0c05bae8 */
if(!s->budget--) { s->failed_pc=0x0c05bae8u; return 0; }
r[1]<<=16;
goto P_0c05baea;
P_0c05baea: /* original 4118, guest PC 0x0c05baea */
if(!s->budget--) { s->failed_pc=0x0c05baeau; return 0; }
r[1]<<=8;
goto P_0c05baec;
P_0c05baec: /* original f342, guest PC 0x0c05baec */
if(!s->budget--) { s->failed_pc=0x0c05baecu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05baee;
P_0c05baee: /* original f33d, guest PC 0x0c05baee */
if(!s->budget--) { s->failed_pc=0x0c05baeeu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05baf0;
P_0c05baf0: /* original 005a, guest PC 0x0c05baf0 */
if(!s->budget--) { s->failed_pc=0x0c05baf0u; return 0; }
r[0]=r[53];
goto P_0c05baf2;
P_0c05baf2: /* original 4028, guest PC 0x0c05baf2 */
if(!s->budget--) { s->failed_pc=0x0c05baf2u; return 0; }
r[0]<<=16;
goto P_0c05baf4;
P_0c05baf4: /* original 210b, guest PC 0x0c05baf4 */
if(!s->budget--) { s->failed_pc=0x0c05baf4u; return 0; }
r[1]|=r[0];
goto P_0c05baf6;
P_0c05baf6: /* original e028, guest PC 0x0c05baf6 */
if(!s->budget--) { s->failed_pc=0x0c05baf6u; return 0; }
r[0]=0x00000028u;
goto P_0c05baf8;
P_0c05baf8: /* original f356, guest PC 0x0c05baf8 */
if(!s->budget--) { s->failed_pc=0x0c05baf8u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bafa;
P_0c05bafa: /* original f342, guest PC 0x0c05bafa */
if(!s->budget--) { s->failed_pc=0x0c05bafau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bafc;
P_0c05bafc: /* original f33d, guest PC 0x0c05bafc */
if(!s->budget--) { s->failed_pc=0x0c05bafcu; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bafe;
P_0c05bafe: /* original 005a, guest PC 0x0c05bafe */
if(!s->budget--) { s->failed_pc=0x0c05bafeu; return 0; }
r[0]=r[53];
goto P_0c05bb00;
P_0c05bb00: /* original 4018, guest PC 0x0c05bb00 */
if(!s->budget--) { s->failed_pc=0x0c05bb00u; return 0; }
r[0]<<=8;
goto P_0c05bb02;
P_0c05bb02: /* original 210b, guest PC 0x0c05bb02 */
if(!s->budget--) { s->failed_pc=0x0c05bb02u; return 0; }
r[1]|=r[0];
goto P_0c05bb04;
P_0c05bb04: /* original e02c, guest PC 0x0c05bb04 */
if(!s->budget--) { s->failed_pc=0x0c05bb04u; return 0; }
r[0]=0x0000002cu;
goto P_0c05bb06;
P_0c05bb06: /* original f356, guest PC 0x0c05bb06 */
if(!s->budget--) { s->failed_pc=0x0c05bb06u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c05bb08;
P_0c05bb08: /* original f342, guest PC 0x0c05bb08 */
if(!s->budget--) { s->failed_pc=0x0c05bb08u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c05bb0a;
P_0c05bb0a: /* original f33d, guest PC 0x0c05bb0a */
if(!s->budget--) { s->failed_pc=0x0c05bb0au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c05bb0c;
P_0c05bb0c: /* original 005a, guest PC 0x0c05bb0c */
if(!s->budget--) { s->failed_pc=0x0c05bb0cu; return 0; }
r[0]=r[53];
goto P_0c05bb0e;
P_0c05bb0e: /* original 210b, guest PC 0x0c05bb0e */
if(!s->budget--) { s->failed_pc=0x0c05bb0eu; return 0; }
r[1]|=r[0];
goto P_0c05bb10;
P_0c05bb10: /* original 2412, guest PC 0x0c05bb10 */
if(!s->budget--) { s->failed_pc=0x0c05bb10u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bb12;
P_0c05bb12: /* original a004, guest PC 0x0c05bb12 */
if(!s->budget--) { s->failed_pc=0x0c05bb12u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bb1e;
P_0c05bb14: /* original 740c, guest PC 0x0c05bb14 */
if(!s->budget--) { s->failed_pc=0x0c05bb14u; return 0; }
r[4]+=0x0000000cu;
goto P_0c05bb16;
P_0c05bb16: /* original e040, guest PC 0x0c05bb16 */
if(!s->budget--) { s->failed_pc=0x0c05bb16u; return 0; }
r[0]=0x00000040u;
goto P_0c05bb18;
P_0c05bb18: /* original 01ee, guest PC 0x0c05bb18 */
if(!s->budget--) { s->failed_pc=0x0c05bb18u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c05bb1a;
P_0c05bb1a: /* original 2412, guest PC 0x0c05bb1a */
if(!s->budget--) { s->failed_pc=0x0c05bb1au; return 0; }
write(ram,r[4],r[1],4);
goto P_0c05bb1c;
P_0c05bb1c: /* original 741c, guest PC 0x0c05bb1c */
if(!s->budget--) { s->failed_pc=0x0c05bb1cu; return 0; }
r[4]+=0x0000001cu;
goto P_0c05bb1e;
P_0c05bb1e: /* original 3478, guest PC 0x0c05bb1e */
if(!s->budget--) { s->failed_pc=0x0c05bb1eu; return 0; }
r[4]-=r[7];
goto P_0c05bb20;
P_0c05bb20: /* original d504, guest PC 0x0c05bb20 */
if(!s->budget--) { s->failed_pc=0x0c05bb20u; return 0; }
r[5]=read(ram,0x0c05bb34u,4);
goto P_0c05bb22;
P_0c05bb22: /* original e000, guest PC 0x0c05bb22 */
if(!s->budget--) { s->failed_pc=0x0c05bb22u; return 0; }
r[0]=0x00000000u;
goto P_0c05bb24;
P_0c05bb24: /* original 6362, guest PC 0x0c05bb24 */
if(!s->budget--) { s->failed_pc=0x0c05bb24u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c05bb26;
P_0c05bb26: /* original 2532, guest PC 0x0c05bb26 */
if(!s->budget--) { s->failed_pc=0x0c05bb26u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c05bb28;
P_0c05bb28: /* original 1541, guest PC 0x0c05bb28 */
if(!s->budget--) { s->failed_pc=0x0c05bb28u; return 0; }
write(ram,r[5]+4,r[4],4);
goto P_0c05bb2a;
P_0c05bb2a: /* original 6df6, guest PC 0x0c05bb2a */
if(!s->budget--) { s->failed_pc=0x0c05bb2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05bb2c;
P_0c05bb2c: /* original 000b, guest PC 0x0c05bb2c */
if(!s->budget--) { s->failed_pc=0x0c05bb2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05bb2e: /* original 6ef6, guest PC 0x0c05bb2e */
if(!s->budget--) { s->failed_pc=0x0c05bb2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05bb30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05bb30u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
