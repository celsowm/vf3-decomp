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
int vf3_away_batch172_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ca8c0u: goto P_0c0ca8c0;
case 0x0c0ca8c2u: goto P_0c0ca8c2;
case 0x0c0ca8c4u: goto P_0c0ca8c4;
case 0x0c0ca8c6u: goto P_0c0ca8c6;
case 0x0c0ca8c8u: goto P_0c0ca8c8;
case 0x0c0ca8cau: goto P_0c0ca8ca;
case 0x0c0ca8ccu: goto P_0c0ca8cc;
case 0x0c0ca8ceu: goto P_0c0ca8ce;
case 0x0c0ca8d0u: goto P_0c0ca8d0;
case 0x0c0ca8d2u: goto P_0c0ca8d2;
case 0x0c0ca8d4u: goto P_0c0ca8d4;
case 0x0c0ca8d6u: goto P_0c0ca8d6;
case 0x0c0ca8d8u: goto P_0c0ca8d8;
case 0x0c0ca8dau: goto P_0c0ca8da;
case 0x0c0ca8dcu: goto P_0c0ca8dc;
case 0x0c0ca8deu: goto P_0c0ca8de;
case 0x0c0ca8e0u: goto P_0c0ca8e0;
case 0x0c0ca8e2u: goto P_0c0ca8e2;
case 0x0c0ca8e4u: goto P_0c0ca8e4;
case 0x0c0ca8e6u: goto P_0c0ca8e6;
case 0x0c0ca8e8u: goto P_0c0ca8e8;
case 0x0c0ca8eau: goto P_0c0ca8ea;
case 0x0c0ca8ecu: goto P_0c0ca8ec;
case 0x0c0ca8eeu: goto P_0c0ca8ee;
case 0x0c0ca8f0u: goto P_0c0ca8f0;
case 0x0c0ca8f2u: goto P_0c0ca8f2;
case 0x0c0ca8f4u: goto P_0c0ca8f4;
case 0x0c0ca8f6u: goto P_0c0ca8f6;
case 0x0c0ca8f8u: goto P_0c0ca8f8;
case 0x0c0ca8fau: goto P_0c0ca8fa;
case 0x0c0ca8fcu: goto P_0c0ca8fc;
case 0x0c0ca8feu: goto P_0c0ca8fe;
case 0x0c0ca900u: goto P_0c0ca900;
case 0x0c0ca902u: goto P_0c0ca902;
case 0x0c0ca904u: goto P_0c0ca904;
case 0x0c0ca918u: goto P_0c0ca918;
case 0x0c0ca91au: goto P_0c0ca91a;
case 0x0c0ca91cu: goto P_0c0ca91c;
case 0x0c0ca91eu: goto P_0c0ca91e;
case 0x0c0ca920u: goto P_0c0ca920;
case 0x0c0ca922u: goto P_0c0ca922;
case 0x0c0ca924u: goto P_0c0ca924;
case 0x0c0ca926u: goto P_0c0ca926;
case 0x0c0ca928u: goto P_0c0ca928;
case 0x0c0ca92au: goto P_0c0ca92a;
case 0x0c0ca92cu: goto P_0c0ca92c;
case 0x0c0ca92eu: goto P_0c0ca92e;
case 0x0c0ca930u: goto P_0c0ca930;
case 0x0c0ca932u: goto P_0c0ca932;
case 0x0c0ca934u: goto P_0c0ca934;
case 0x0c0ca936u: goto P_0c0ca936;
case 0x0c0ca938u: goto P_0c0ca938;
case 0x0c0ca93au: goto P_0c0ca93a;
case 0x0c0ca93cu: goto P_0c0ca93c;
case 0x0c0ca93eu: goto P_0c0ca93e;
case 0x0c0ca940u: goto P_0c0ca940;
case 0x0c0ca942u: goto P_0c0ca942;
case 0x0c0ca944u: goto P_0c0ca944;
case 0x0c0ca946u: goto P_0c0ca946;
case 0x0c0ca948u: goto P_0c0ca948;
case 0x0c0ca94au: goto P_0c0ca94a;
case 0x0c0ca94cu: goto P_0c0ca94c;
case 0x0c0ca94eu: goto P_0c0ca94e;
case 0x0c0ca950u: goto P_0c0ca950;
case 0x0c0ca952u: goto P_0c0ca952;
case 0x0c0ca954u: goto P_0c0ca954;
case 0x0c0ca956u: goto P_0c0ca956;
case 0x0c0ca958u: goto P_0c0ca958;
case 0x0c0ca95au: goto P_0c0ca95a;
case 0x0c0ca95cu: goto P_0c0ca95c;
case 0x0c0ca95eu: goto P_0c0ca95e;
case 0x0c0ca960u: goto P_0c0ca960;
case 0x0c0ca962u: goto P_0c0ca962;
case 0x0c0ca964u: goto P_0c0ca964;
case 0x0c0ca966u: goto P_0c0ca966;
case 0x0c0ca968u: goto P_0c0ca968;
case 0x0c0ca96au: goto P_0c0ca96a;
case 0x0c0ca96cu: goto P_0c0ca96c;
case 0x0c0ca96eu: goto P_0c0ca96e;
case 0x0c0ca970u: goto P_0c0ca970;
case 0x0c0ca972u: goto P_0c0ca972;
case 0x0c0ca974u: goto P_0c0ca974;
case 0x0c0ca976u: goto P_0c0ca976;
case 0x0c0ca978u: goto P_0c0ca978;
case 0x0c0ca97au: goto P_0c0ca97a;
case 0x0c0ca97cu: goto P_0c0ca97c;
case 0x0c0ca97eu: goto P_0c0ca97e;
case 0x0c0ca980u: goto P_0c0ca980;
case 0x0c0ca982u: goto P_0c0ca982;
case 0x0c0ca984u: goto P_0c0ca984;
case 0x0c0ca986u: goto P_0c0ca986;
case 0x0c0ca988u: goto P_0c0ca988;
case 0x0c0ca98au: goto P_0c0ca98a;
case 0x0c0ca98cu: goto P_0c0ca98c;
case 0x0c0ca98eu: goto P_0c0ca98e;
case 0x0c0ca990u: goto P_0c0ca990;
case 0x0c0ca992u: goto P_0c0ca992;
case 0x0c0ca994u: goto P_0c0ca994;
case 0x0c0ca996u: goto P_0c0ca996;
case 0x0c0ca998u: goto P_0c0ca998;
case 0x0c0ca99au: goto P_0c0ca99a;
case 0x0c0ca99cu: goto P_0c0ca99c;
case 0x0c0ca99eu: goto P_0c0ca99e;
case 0x0c0ca9a0u: goto P_0c0ca9a0;
case 0x0c0ca9a2u: goto P_0c0ca9a2;
case 0x0c0ca9a4u: goto P_0c0ca9a4;
case 0x0c0ca9a6u: goto P_0c0ca9a6;
case 0x0c0ca9a8u: goto P_0c0ca9a8;
case 0x0c0ca9aau: goto P_0c0ca9aa;
case 0x0c0ca9acu: goto P_0c0ca9ac;
case 0x0c0ca9aeu: goto P_0c0ca9ae;
case 0x0c0ca9b0u: goto P_0c0ca9b0;
case 0x0c0ca9b2u: goto P_0c0ca9b2;
case 0x0c0ca9b4u: goto P_0c0ca9b4;
case 0x0c0ca9b6u: goto P_0c0ca9b6;
case 0x0c0ca9b8u: goto P_0c0ca9b8;
case 0x0c0ca9bau: goto P_0c0ca9ba;
case 0x0c0ca9bcu: goto P_0c0ca9bc;
case 0x0c0ca9beu: goto P_0c0ca9be;
case 0x0c0ca9c0u: goto P_0c0ca9c0;
case 0x0c0ca9c2u: goto P_0c0ca9c2;
case 0x0c0ca9c4u: goto P_0c0ca9c4;
case 0x0c0ca9c6u: goto P_0c0ca9c6;
case 0x0c0ca9c8u: goto P_0c0ca9c8;
case 0x0c0ca9cau: goto P_0c0ca9ca;
case 0x0c0ca9ccu: goto P_0c0ca9cc;
case 0x0c0ca9ceu: goto P_0c0ca9ce;
case 0x0c0ca9d0u: goto P_0c0ca9d0;
case 0x0c0ca9d2u: goto P_0c0ca9d2;
case 0x0c0ca9d4u: goto P_0c0ca9d4;
case 0x0c0ca9d6u: goto P_0c0ca9d6;
case 0x0c0ca9d8u: goto P_0c0ca9d8;
case 0x0c0ca9dau: goto P_0c0ca9da;
case 0x0c0ca9dcu: goto P_0c0ca9dc;
case 0x0c0ca9deu: goto P_0c0ca9de;
case 0x0c0ca9e0u: goto P_0c0ca9e0;
case 0x0c0ca9e2u: goto P_0c0ca9e2;
case 0x0c0ca9e4u: goto P_0c0ca9e4;
case 0x0c0ca9e6u: goto P_0c0ca9e6;
case 0x0c0ca9e8u: goto P_0c0ca9e8;
case 0x0c0ca9eau: goto P_0c0ca9ea;
case 0x0c0ca9ecu: goto P_0c0ca9ec;
case 0x0c0ca9eeu: goto P_0c0ca9ee;
case 0x0c0ca9f0u: goto P_0c0ca9f0;
case 0x0c0ca9f2u: goto P_0c0ca9f2;
case 0x0c0ca9f4u: goto P_0c0ca9f4;
case 0x0c0ca9f6u: goto P_0c0ca9f6;
case 0x0c0ca9f8u: goto P_0c0ca9f8;
case 0x0c0ca9fau: goto P_0c0ca9fa;
case 0x0c0ca9fcu: goto P_0c0ca9fc;
case 0x0c0ca9feu: goto P_0c0ca9fe;
case 0x0c0caa00u: goto P_0c0caa00;
case 0x0c0caa02u: goto P_0c0caa02;
case 0x0c0caa04u: goto P_0c0caa04;
case 0x0c0caa06u: goto P_0c0caa06;
case 0x0c0caa08u: goto P_0c0caa08;
case 0x0c0caa0au: goto P_0c0caa0a;
case 0x0c0caa0cu: goto P_0c0caa0c;
case 0x0c0caa0eu: goto P_0c0caa0e;
case 0x0c0caa10u: goto P_0c0caa10;
case 0x0c0caa12u: goto P_0c0caa12;
case 0x0c0caa14u: goto P_0c0caa14;
case 0x0c0caa16u: goto P_0c0caa16;
case 0x0c0caa18u: goto P_0c0caa18;
case 0x0c0caa1au: goto P_0c0caa1a;
case 0x0c0caa1cu: goto P_0c0caa1c;
case 0x0c0caa1eu: goto P_0c0caa1e;
case 0x0c0caa20u: goto P_0c0caa20;
case 0x0c0caa22u: goto P_0c0caa22;
case 0x0c0caa24u: goto P_0c0caa24;
case 0x0c0caa26u: goto P_0c0caa26;
case 0x0c0caa28u: goto P_0c0caa28;
case 0x0c0caa2au: goto P_0c0caa2a;
case 0x0c0caa2cu: goto P_0c0caa2c;
case 0x0c0caa2eu: goto P_0c0caa2e;
case 0x0c0caa4cu: goto P_0c0caa4c;
case 0x0c0caa4eu: goto P_0c0caa4e;
case 0x0c0caa50u: goto P_0c0caa50;
case 0x0c0caa52u: goto P_0c0caa52;
case 0x0c0caa54u: goto P_0c0caa54;
case 0x0c0caa56u: goto P_0c0caa56;
case 0x0c0caa58u: goto P_0c0caa58;
case 0x0c0caa5au: goto P_0c0caa5a;
case 0x0c0caa5cu: goto P_0c0caa5c;
case 0x0c0caa5eu: goto P_0c0caa5e;
case 0x0c0caa60u: goto P_0c0caa60;
case 0x0c0caa62u: goto P_0c0caa62;
case 0x0c0caa64u: goto P_0c0caa64;
case 0x0c0caa66u: goto P_0c0caa66;
case 0x0c0caa68u: goto P_0c0caa68;
case 0x0c0caa6au: goto P_0c0caa6a;
case 0x0c0caa6cu: goto P_0c0caa6c;
case 0x0c0caa6eu: goto P_0c0caa6e;
case 0x0c0caa70u: goto P_0c0caa70;
case 0x0c0caa72u: goto P_0c0caa72;
case 0x0c0caa74u: goto P_0c0caa74;
case 0x0c0caa76u: goto P_0c0caa76;
case 0x0c0caa78u: goto P_0c0caa78;
case 0x0c0caa7au: goto P_0c0caa7a;
case 0x0c0caa7cu: goto P_0c0caa7c;
case 0x0c0caa7eu: goto P_0c0caa7e;
case 0x0c0caa80u: goto P_0c0caa80;
case 0x0c0caa82u: goto P_0c0caa82;
case 0x0c0caa84u: goto P_0c0caa84;
case 0x0c0caa86u: goto P_0c0caa86;
case 0x0c0caa88u: goto P_0c0caa88;
case 0x0c0caa8au: goto P_0c0caa8a;
case 0x0c0caa8cu: goto P_0c0caa8c;
case 0x0c0caa8eu: goto P_0c0caa8e;
case 0x0c0caa90u: goto P_0c0caa90;
case 0x0c0caa92u: goto P_0c0caa92;
case 0x0c0caa94u: goto P_0c0caa94;
case 0x0c0caa96u: goto P_0c0caa96;
case 0x0c0caa98u: goto P_0c0caa98;
case 0x0c0caa9au: goto P_0c0caa9a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0ca8c0: /* original 2fe6, guest PC 0x0c0ca8c0 */
if(!s->budget--) { s->failed_pc=0x0c0ca8c0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca8c2;
P_0c0ca8c2: /* original 2fd6, guest PC 0x0c0ca8c2 */
if(!s->budget--) { s->failed_pc=0x0c0ca8c2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca8c4;
P_0c0ca8c4: /* original 6d43, guest PC 0x0c0ca8c4 */
if(!s->budget--) { s->failed_pc=0x0c0ca8c4u; return 0; }
r[13]=r[4];
goto P_0c0ca8c6;
P_0c0ca8c6: /* original 2fc6, guest PC 0x0c0ca8c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca8c6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca8c8;
P_0c0ca8c8: /* original 2fb6, guest PC 0x0c0ca8c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca8c8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca8ca;
P_0c0ca8ca: /* original eb02, guest PC 0x0c0ca8ca */
if(!s->budget--) { s->failed_pc=0x0c0ca8cau; return 0; }
r[11]=0x00000002u;
goto P_0c0ca8cc;
P_0c0ca8cc: /* original 2fa6, guest PC 0x0c0ca8cc */
if(!s->budget--) { s->failed_pc=0x0c0ca8ccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca8ce;
P_0c0ca8ce: /* original 2f96, guest PC 0x0c0ca8ce */
if(!s->budget--) { s->failed_pc=0x0c0ca8ceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ca8d0;
P_0c0ca8d0: /* original fffb, guest PC 0x0c0ca8d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca8d0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca8d2;
P_0c0ca8d2: /* original ffeb, guest PC 0x0c0ca8d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca8d2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0ca8d4;
P_0c0ca8d4: /* original ffdb, guest PC 0x0c0ca8d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca8d4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0ca8d6;
P_0c0ca8d6: /* original ffcb, guest PC 0x0c0ca8d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca8d6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0ca8d8;
P_0c0ca8d8: /* original 9016, guest PC 0x0c0ca8d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca8d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca908u,2);
goto P_0c0ca8da;
P_0c0ca8da: /* original 4f22, guest PC 0x0c0ca8da */
if(!s->budget--) { s->failed_pc=0x0c0ca8dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca8dc;
P_0c0ca8dc: /* original 0add, guest PC 0x0c0ca8dc */
if(!s->budget--) { s->failed_pc=0x0c0ca8dcu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0ca8de;
P_0c0ca8de: /* original 9014, guest PC 0x0c0ca8de */
if(!s->budget--) { s->failed_pc=0x0c0ca8deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ca90au,2);
goto P_0c0ca8e0;
P_0c0ca8e0: /* original 7fe4, guest PC 0x0c0ca8e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca8e0u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c0ca8e2;
P_0c0ca8e2: /* original ffd6, guest PC 0x0c0ca8e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca8e2u; return 0; }
vf3_matrix_load(s,ram,15,r[13]+r[0]);
goto P_0c0ca8e4;
P_0c0ca8e4: /* original 7008, guest PC 0x0c0ca8e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca8e4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0ca8e6;
P_0c0ca8e6: /* original fcd6, guest PC 0x0c0ca8e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca8e6u; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c0ca8e8;
P_0c0ca8e8: /* original c708, guest PC 0x0c0ca8e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca8e8u; return 0; }
r[0]=code_base|0x000ca90cu;
goto P_0c0ca8ea;
P_0c0ca8ea: /* original f308, guest PC 0x0c0ca8ea */
if(!s->budget--) { s->failed_pc=0x0c0ca8eau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ca8ec;
P_0c0ca8ec: /* original e010, guest PC 0x0c0ca8ec */
if(!s->budget--) { s->failed_pc=0x0c0ca8ecu; return 0; }
r[0]=0x00000010u;
goto P_0c0ca8ee;
P_0c0ca8ee: /* original 69ab, guest PC 0x0c0ca8ee */
if(!s->budget--) { s->failed_pc=0x0c0ca8eeu; return 0; }
r[9]=0u-r[10];
goto P_0c0ca8f0;
P_0c0ca8f0: /* original fc4d, guest PC 0x0c0ca8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca8f0u; return 0; }
fr[12]^=0x80000000u;
goto P_0c0ca8f2;
P_0c0ca8f2: /* original ff37, guest PC 0x0c0ca8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca8f2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ca8f4;
P_0c0ca8f4: /* original c706, guest PC 0x0c0ca8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca8f4u; return 0; }
r[0]=code_base|0x000ca910u;
goto P_0c0ca8f6;
P_0c0ca8f6: /* original f308, guest PC 0x0c0ca8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca8f6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ca8f8;
P_0c0ca8f8: /* original e014, guest PC 0x0c0ca8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca8f8u; return 0; }
r[0]=0x00000014u;
goto P_0c0ca8fa;
P_0c0ca8fa: /* original ff37, guest PC 0x0c0ca8fa */
if(!s->budget--) { s->failed_pc=0x0c0ca8fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ca8fc;
P_0c0ca8fc: /* original c705, guest PC 0x0c0ca8fc */
if(!s->budget--) { s->failed_pc=0x0c0ca8fcu; return 0; }
r[0]=code_base|0x000ca914u;
goto P_0c0ca8fe;
P_0c0ca8fe: /* original f308, guest PC 0x0c0ca8fe */
if(!s->budget--) { s->failed_pc=0x0c0ca8feu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ca900;
P_0c0ca900: /* original e018, guest PC 0x0c0ca900 */
if(!s->budget--) { s->failed_pc=0x0c0ca900u; return 0; }
r[0]=0x00000018u;
goto P_0c0ca902;
P_0c0ca902: /* original a0b9, guest PC 0x0c0ca902 */
if(!s->budget--) { s->failed_pc=0x0c0ca902u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0caa78;
P_0c0ca904: /* original ff37, guest PC 0x0c0ca904 */
if(!s->budget--) { s->failed_pc=0x0c0ca904u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!vf3_matrix_family(0x0c0ca906u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca906u; return 0; } return 1;
P_0c0ca918: /* original dc47, guest PC 0x0c0ca918 */
if(!s->budget--) { s->failed_pc=0x0c0ca918u; return 0; }
r[12]=read(ram,0x0c0caa38u,4);
goto P_0c0ca91a;
P_0c0ca91a: /* original 6e9f, guest PC 0x0c0ca91a */
if(!s->budget--) { s->failed_pc=0x0c0ca91au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c0ca91c;
P_0c0ca91c: /* original 4c0b, guest PC 0x0c0ca91c */
if(!s->budget--) { s->failed_pc=0x0c0ca91cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0ca920u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca920u) { target=s->pc; goto dispatch; }
goto P_0c0ca920;
P_0c0ca91e: /* original 64e3, guest PC 0x0c0ca91e */
if(!s->budget--) { s->failed_pc=0x0c0ca91eu; return 0; }
r[4]=r[14];
goto P_0c0ca920;
P_0c0ca920: /* original ff0a, guest PC 0x0c0ca920 */
if(!s->budget--) { s->failed_pc=0x0c0ca920u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0ca922;
P_0c0ca922: /* original dc46, guest PC 0x0c0ca922 */
if(!s->budget--) { s->failed_pc=0x0c0ca922u; return 0; }
r[12]=read(ram,0x0c0caa3cu,4);
goto P_0c0ca924;
P_0c0ca924: /* original 4c0b, guest PC 0x0c0ca924 */
if(!s->budget--) { s->failed_pc=0x0c0ca924u; return 0; }
target=r[12];
r[16]=code_base|0x0c0ca928u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca928u) { target=s->pc; goto dispatch; }
goto P_0c0ca928;
P_0c0ca926: /* original 64e3, guest PC 0x0c0ca926 */
if(!s->budget--) { s->failed_pc=0x0c0ca926u; return 0; }
r[4]=r[14];
goto P_0c0ca928;
P_0c0ca928: /* original e004, guest PC 0x0c0ca928 */
if(!s->budget--) { s->failed_pc=0x0c0ca928u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca92a;
P_0c0ca92a: /* original ff07, guest PC 0x0c0ca92a */
if(!s->budget--) { s->failed_pc=0x0c0ca92au; return 0; }
vf3_matrix_store(s,ram,0,r[15]+r[0]);
goto P_0c0ca92c;
P_0c0ca92c: /* original e014, guest PC 0x0c0ca92c */
if(!s->budget--) { s->failed_pc=0x0c0ca92cu; return 0; }
r[0]=0x00000014u;
goto P_0c0ca92e;
P_0c0ca92e: /* original f3f8, guest PC 0x0c0ca92e */
if(!s->budget--) { s->failed_pc=0x0c0ca92eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ca930;
P_0c0ca930: /* original f4fc, guest PC 0x0c0ca930 */
if(!s->budget--) { s->failed_pc=0x0c0ca930u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ca932;
P_0c0ca932: /* original f430, guest PC 0x0c0ca932 */
if(!s->budget--) { s->failed_pc=0x0c0ca932u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ca934;
P_0c0ca934: /* original f30c, guest PC 0x0c0ca934 */
if(!s->budget--) { s->failed_pc=0x0c0ca934u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0ca936;
P_0c0ca936: /* original f2f6, guest PC 0x0c0ca936 */
if(!s->budget--) { s->failed_pc=0x0c0ca936u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ca938;
P_0c0ca938: /* original e008, guest PC 0x0c0ca938 */
if(!s->budget--) { s->failed_pc=0x0c0ca938u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca93a;
P_0c0ca93a: /* original f50c, guest PC 0x0c0ca93a */
if(!s->budget--) { s->failed_pc=0x0c0ca93au; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c0ca93c;
P_0c0ca93c: /* original f5cc, guest PC 0x0c0ca93c */
if(!s->budget--) { s->failed_pc=0x0c0ca93cu; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0ca93e;
P_0c0ca93e: /* original f530, guest PC 0x0c0ca93e */
if(!s->budget--) { s->failed_pc=0x0c0ca93eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0ca940;
P_0c0ca940: /* original f34c, guest PC 0x0c0ca940 */
if(!s->budget--) { s->failed_pc=0x0c0ca940u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ca942;
P_0c0ca942: /* original f4fc, guest PC 0x0c0ca942 */
if(!s->budget--) { s->failed_pc=0x0c0ca942u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0ca944;
P_0c0ca944: /* original f431, guest PC 0x0c0ca944 */
if(!s->budget--) { s->failed_pc=0x0c0ca944u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0ca946;
P_0c0ca946: /* original f35c, guest PC 0x0c0ca946 */
if(!s->budget--) { s->failed_pc=0x0c0ca946u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ca948;
P_0c0ca948: /* original f5cc, guest PC 0x0c0ca948 */
if(!s->budget--) { s->failed_pc=0x0c0ca948u; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c0ca94a;
P_0c0ca94a: /* original f531, guest PC 0x0c0ca94a */
if(!s->budget--) { s->failed_pc=0x0c0ca94au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0ca94c;
P_0c0ca94c: /* original ff27, guest PC 0x0c0ca94c */
if(!s->budget--) { s->failed_pc=0x0c0ca94cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0ca94e;
P_0c0ca94e: /* original e010, guest PC 0x0c0ca94e */
if(!s->budget--) { s->failed_pc=0x0c0ca94eu; return 0; }
r[0]=0x00000010u;
goto P_0c0ca950;
P_0c0ca950: /* original f3f6, guest PC 0x0c0ca950 */
if(!s->budget--) { s->failed_pc=0x0c0ca950u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca952;
P_0c0ca952: /* original f345, guest PC 0x0c0ca952 */
if(!s->budget--) { s->failed_pc=0x0c0ca952u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0ca954;
P_0c0ca954: /* original 8b0e, guest PC 0x0c0ca954 */
if(!s->budget--) { s->failed_pc=0x0c0ca954u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca974; }
goto P_0c0ca956;
P_0c0ca956: /* original e018, guest PC 0x0c0ca956 */
if(!s->budget--) { s->failed_pc=0x0c0ca956u; return 0; }
r[0]=0x00000018u;
goto P_0c0ca958;
P_0c0ca958: /* original f3f6, guest PC 0x0c0ca958 */
if(!s->budget--) { s->failed_pc=0x0c0ca958u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0ca95a;
P_0c0ca95a: /* original f435, guest PC 0x0c0ca95a */
if(!s->budget--) { s->failed_pc=0x0c0ca95au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0ca95c;
P_0c0ca95c: /* original 8b0a, guest PC 0x0c0ca95c */
if(!s->budget--) { s->failed_pc=0x0c0ca95cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca974; }
goto P_0c0ca95e;
P_0c0ca95e: /* original 66f3, guest PC 0x0c0ca95e */
if(!s->budget--) { s->failed_pc=0x0c0ca95eu; return 0; }
r[6]=r[15];
goto P_0c0ca960;
P_0c0ca960: /* original 65f3, guest PC 0x0c0ca960 */
if(!s->budget--) { s->failed_pc=0x0c0ca960u; return 0; }
r[5]=r[15];
goto P_0c0ca962;
P_0c0ca962: /* original 67f3, guest PC 0x0c0ca962 */
if(!s->budget--) { s->failed_pc=0x0c0ca962u; return 0; }
r[7]=r[15];
goto P_0c0ca964;
P_0c0ca964: /* original fffa, guest PC 0x0c0ca964 */
if(!s->budget--) { s->failed_pc=0x0c0ca964u; return 0; }
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0ca966;
P_0c0ca966: /* original 7504, guest PC 0x0c0ca966 */
if(!s->budget--) { s->failed_pc=0x0c0ca966u; return 0; }
r[5]+=0x00000004u;
goto P_0c0ca968;
P_0c0ca968: /* original 770c, guest PC 0x0c0ca968 */
if(!s->budget--) { s->failed_pc=0x0c0ca968u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ca96a;
P_0c0ca96a: /* original 7608, guest PC 0x0c0ca96a */
if(!s->budget--) { s->failed_pc=0x0c0ca96au; return 0; }
r[6]+=0x00000008u;
goto P_0c0ca96c;
P_0c0ca96c: /* original bf92, guest PC 0x0c0ca96c */
if(!s->budget--) { s->failed_pc=0x0c0ca96cu; return 0; }
target=code_base|0x0c0ca894u; r[16]=code_base|0x0c0ca970u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca970u) { target=s->pc; goto dispatch; }
goto P_0c0ca970;
P_0c0ca96e: /* original 64f3, guest PC 0x0c0ca96e */
if(!s->budget--) { s->failed_pc=0x0c0ca96eu; return 0; }
r[4]=r[15];
goto P_0c0ca970;
P_0c0ca970: /* original a010, guest PC 0x0c0ca970 */
if(!s->budget--) { s->failed_pc=0x0c0ca970u; return 0; }
goto P_0c0ca994;
P_0c0ca972: /* original 0009, guest PC 0x0c0ca972 */
if(!s->budget--) { s->failed_pc=0x0c0ca972u; return 0; }
goto P_0c0ca974;
P_0c0ca974: /* original f543, guest PC 0x0c0ca974 */
if(!s->budget--) { s->failed_pc=0x0c0ca974u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'/');
goto P_0c0ca976;
P_0c0ca976: /* original 67f3, guest PC 0x0c0ca976 */
if(!s->budget--) { s->failed_pc=0x0c0ca976u; return 0; }
r[7]=r[15];
goto P_0c0ca978;
P_0c0ca978: /* original 66f3, guest PC 0x0c0ca978 */
if(!s->budget--) { s->failed_pc=0x0c0ca978u; return 0; }
r[6]=r[15];
goto P_0c0ca97a;
P_0c0ca97a: /* original 65f3, guest PC 0x0c0ca97a */
if(!s->budget--) { s->failed_pc=0x0c0ca97au; return 0; }
r[5]=r[15];
goto P_0c0ca97c;
P_0c0ca97c: /* original e004, guest PC 0x0c0ca97c */
if(!s->budget--) { s->failed_pc=0x0c0ca97cu; return 0; }
r[0]=0x00000004u;
goto P_0c0ca97e;
P_0c0ca97e: /* original 7504, guest PC 0x0c0ca97e */
if(!s->budget--) { s->failed_pc=0x0c0ca97eu; return 0; }
r[5]+=0x00000004u;
goto P_0c0ca980;
P_0c0ca980: /* original 7608, guest PC 0x0c0ca980 */
if(!s->budget--) { s->failed_pc=0x0c0ca980u; return 0; }
r[6]+=0x00000008u;
goto P_0c0ca982;
P_0c0ca982: /* original 770c, guest PC 0x0c0ca982 */
if(!s->budget--) { s->failed_pc=0x0c0ca982u; return 0; }
r[7]+=0x0000000cu;
goto P_0c0ca984;
P_0c0ca984: /* original ff5a, guest PC 0x0c0ca984 */
if(!s->budget--) { s->failed_pc=0x0c0ca984u; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0ca986;
P_0c0ca986: /* original f45c, guest PC 0x0c0ca986 */
if(!s->budget--) { s->failed_pc=0x0c0ca986u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0ca988;
P_0c0ca988: /* original f4f2, guest PC 0x0c0ca988 */
if(!s->budget--) { s->failed_pc=0x0c0ca988u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c0ca98a;
P_0c0ca98a: /* original f3cc, guest PC 0x0c0ca98a */
if(!s->budget--) { s->failed_pc=0x0c0ca98au; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c0ca98c;
P_0c0ca98c: /* original f341, guest PC 0x0c0ca98c */
if(!s->budget--) { s->failed_pc=0x0c0ca98cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c0ca98e;
P_0c0ca98e: /* original ff37, guest PC 0x0c0ca98e */
if(!s->budget--) { s->failed_pc=0x0c0ca98eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0ca990;
P_0c0ca990: /* original bf52, guest PC 0x0c0ca990 */
if(!s->budget--) { s->failed_pc=0x0c0ca990u; return 0; }
target=code_base|0x0c0ca838u; r[16]=code_base|0x0c0ca994u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca994u) { target=s->pc; goto dispatch; }
goto P_0c0ca994;
P_0c0ca992: /* original 64f3, guest PC 0x0c0ca992 */
if(!s->budget--) { s->failed_pc=0x0c0ca992u; return 0; }
r[4]=r[15];
goto P_0c0ca994;
P_0c0ca994: /* original f4f8, guest PC 0x0c0ca994 */
if(!s->budget--) { s->failed_pc=0x0c0ca994u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0ca996;
P_0c0ca996: /* original e004, guest PC 0x0c0ca996 */
if(!s->budget--) { s->failed_pc=0x0c0ca996u; return 0; }
r[0]=0x00000004u;
goto P_0c0ca998;
P_0c0ca998: /* original f6fc, guest PC 0x0c0ca998 */
if(!s->budget--) { s->failed_pc=0x0c0ca998u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0ca99a;
P_0c0ca99a: /* original f641, guest PC 0x0c0ca99a */
if(!s->budget--) { s->failed_pc=0x0c0ca99au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c0ca99c;
P_0c0ca99c: /* original f5f6, guest PC 0x0c0ca99c */
if(!s->budget--) { s->failed_pc=0x0c0ca99cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0ca99e;
P_0c0ca99e: /* original f7cc, guest PC 0x0c0ca99e */
if(!s->budget--) { s->failed_pc=0x0c0ca99eu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c0ca9a0;
P_0c0ca9a0: /* original e008, guest PC 0x0c0ca9a0 */
if(!s->budget--) { s->failed_pc=0x0c0ca9a0u; return 0; }
r[0]=0x00000008u;
goto P_0c0ca9a2;
P_0c0ca9a2: /* original f751, guest PC 0x0c0ca9a2 */
if(!s->budget--) { s->failed_pc=0x0c0ca9a2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c0ca9a4;
P_0c0ca9a4: /* original fdf6, guest PC 0x0c0ca9a4 */
if(!s->budget--) { s->failed_pc=0x0c0ca9a4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c0ca9a6;
P_0c0ca9a6: /* original e00c, guest PC 0x0c0ca9a6 */
if(!s->budget--) { s->failed_pc=0x0c0ca9a6u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ca9a8;
P_0c0ca9a8: /* original f36c, guest PC 0x0c0ca9a8 */
if(!s->budget--) { s->failed_pc=0x0c0ca9a8u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c0ca9aa;
P_0c0ca9aa: /* original f362, guest PC 0x0c0ca9aa */
if(!s->budget--) { s->failed_pc=0x0c0ca9aau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0ca9ac;
P_0c0ca9ac: /* original fef6, guest PC 0x0c0ca9ac */
if(!s->budget--) { s->failed_pc=0x0c0ca9acu; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0ca9ae;
P_0c0ca9ae: /* original c724, guest PC 0x0c0ca9ae */
if(!s->budget--) { s->failed_pc=0x0c0ca9aeu; return 0; }
r[0]=code_base|0x000caa40u;
goto P_0c0ca9b0;
P_0c0ca9b0: /* original f07c, guest PC 0x0c0ca9b0 */
if(!s->budget--) { s->failed_pc=0x0c0ca9b0u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0ca9b2;
P_0c0ca9b2: /* original f37e, guest PC 0x0c0ca9b2 */
if(!s->budget--) { s->failed_pc=0x0c0ca9b2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c0ca9b4;
P_0c0ca9b4: /* original ff3a, guest PC 0x0c0ca9b4 */
if(!s->budget--) { s->failed_pc=0x0c0ca9b4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ca9b6;
P_0c0ca9b6: /* original f2f8, guest PC 0x0c0ca9b6 */
if(!s->budget--) { s->failed_pc=0x0c0ca9b6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0ca9b8;
P_0c0ca9b8: /* original f308, guest PC 0x0c0ca9b8 */
if(!s->budget--) { s->failed_pc=0x0c0ca9b8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ca9ba;
P_0c0ca9ba: /* original f325, guest PC 0x0c0ca9ba */
if(!s->budget--) { s->failed_pc=0x0c0ca9bau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0ca9bc;
P_0c0ca9bc: /* original 8f02, guest PC 0x0c0ca9bc */
if(!s->budget--) { s->failed_pc=0x0c0ca9bcu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,7,15);
if(!cond) { goto P_0c0ca9c4; }
goto P_0c0ca9c0;
P_0c0ca9be: /* original f7fc, guest PC 0x0c0ca9be */
if(!s->budget--) { s->failed_pc=0x0c0ca9beu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c0ca9c0;
P_0c0ca9c0: /* original a002, guest PC 0x0c0ca9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ca9c0u; return 0; }
fr[6]=0;
goto P_0c0ca9c8;
P_0c0ca9c2: /* original f68d, guest PC 0x0c0ca9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ca9c2u; return 0; }
fr[6]=0;
goto P_0c0ca9c4;
P_0c0ca9c4: /* original f26d, guest PC 0x0c0ca9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ca9c4u; return 0; }
fr[2]=vf3_fpu_sqrt(fr[2],r[18]);
goto P_0c0ca9c6;
P_0c0ca9c6: /* original f62c, guest PC 0x0c0ca9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ca9c6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c0ca9c8;
P_0c0ca9c8: /* original f7d1, guest PC 0x0c0ca9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ca9c8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[13],r[18],'-');
goto P_0c0ca9ca;
P_0c0ca9ca: /* original f8cc, guest PC 0x0c0ca9ca */
if(!s->budget--) { s->failed_pc=0x0c0ca9cau; return 0; }
vf3_matrix_move(s,8,12);
goto P_0c0ca9cc;
P_0c0ca9cc: /* original f8e1, guest PC 0x0c0ca9cc */
if(!s->budget--) { s->failed_pc=0x0c0ca9ccu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[14],r[18],'-');
goto P_0c0ca9ce;
P_0c0ca9ce: /* original c71c, guest PC 0x0c0ca9ce */
if(!s->budget--) { s->failed_pc=0x0c0ca9ceu; return 0; }
r[0]=code_base|0x000caa40u;
goto P_0c0ca9d0;
P_0c0ca9d0: /* original f37c, guest PC 0x0c0ca9d0 */
if(!s->budget--) { s->failed_pc=0x0c0ca9d0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0ca9d2;
P_0c0ca9d2: /* original f372, guest PC 0x0c0ca9d2 */
if(!s->budget--) { s->failed_pc=0x0c0ca9d2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0ca9d4;
P_0c0ca9d4: /* original f08c, guest PC 0x0c0ca9d4 */
if(!s->budget--) { s->failed_pc=0x0c0ca9d4u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c0ca9d6;
P_0c0ca9d6: /* original f38e, guest PC 0x0c0ca9d6 */
if(!s->budget--) { s->failed_pc=0x0c0ca9d6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c0ca9d8;
P_0c0ca9d8: /* original ff3a, guest PC 0x0c0ca9d8 */
if(!s->budget--) { s->failed_pc=0x0c0ca9d8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ca9da;
P_0c0ca9da: /* original f2f8, guest PC 0x0c0ca9da */
if(!s->budget--) { s->failed_pc=0x0c0ca9dau; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0ca9dc;
P_0c0ca9dc: /* original f308, guest PC 0x0c0ca9dc */
if(!s->budget--) { s->failed_pc=0x0c0ca9dcu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0ca9de;
P_0c0ca9de: /* original f325, guest PC 0x0c0ca9de */
if(!s->budget--) { s->failed_pc=0x0c0ca9deu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0ca9e0;
P_0c0ca9e0: /* original 8b01, guest PC 0x0c0ca9e0 */
if(!s->budget--) { s->failed_pc=0x0c0ca9e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca9e6; }
goto P_0c0ca9e2;
P_0c0ca9e2: /* original a002, guest PC 0x0c0ca9e2 */
if(!s->budget--) { s->failed_pc=0x0c0ca9e2u; return 0; }
fr[7]=0;
goto P_0c0ca9ea;
P_0c0ca9e4: /* original f78d, guest PC 0x0c0ca9e4 */
if(!s->budget--) { s->failed_pc=0x0c0ca9e4u; return 0; }
fr[7]=0;
goto P_0c0ca9e6;
P_0c0ca9e6: /* original f26d, guest PC 0x0c0ca9e6 */
if(!s->budget--) { s->failed_pc=0x0c0ca9e6u; return 0; }
fr[2]=vf3_fpu_sqrt(fr[2],r[18]);
goto P_0c0ca9e8;
P_0c0ca9e8: /* original f72c, guest PC 0x0c0ca9e8 */
if(!s->budget--) { s->failed_pc=0x0c0ca9e8u; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c0ca9ea;
P_0c0ca9ea: /* original de16, guest PC 0x0c0ca9ea */
if(!s->budget--) { s->failed_pc=0x0c0ca9eau; return 0; }
r[14]=read(ram,0x0c0caa44u,4);
goto P_0c0ca9ec;
P_0c0ca9ec: /* original 63a3, guest PC 0x0c0ca9ec */
if(!s->budget--) { s->failed_pc=0x0c0ca9ecu; return 0; }
r[3]=r[10];
goto P_0c0ca9ee;
P_0c0ca9ee: /* original 23e8, guest PC 0x0c0ca9ee */
if(!s->budget--) { s->failed_pc=0x0c0ca9eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c0ca9f0;
P_0c0ca9f0: /* original 8b08, guest PC 0x0c0ca9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ca9f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caa04; }
goto P_0c0ca9f2;
P_0c0ca9f2: /* original f86c, guest PC 0x0c0ca9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ca9f2u; return 0; }
vf3_matrix_move(s,8,6);
goto P_0c0ca9f4;
P_0c0ca9f4: /* original f67c, guest PC 0x0c0ca9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ca9f4u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c0ca9f6;
P_0c0ca9f6: /* original f78c, guest PC 0x0c0ca9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ca9f6u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c0ca9f8;
P_0c0ca9f8: /* original f84c, guest PC 0x0c0ca9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ca9f8u; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c0ca9fa;
P_0c0ca9fa: /* original f4dc, guest PC 0x0c0ca9fa */
if(!s->budget--) { s->failed_pc=0x0c0ca9fau; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0ca9fc;
P_0c0ca9fc: /* original fd8c, guest PC 0x0c0ca9fc */
if(!s->budget--) { s->failed_pc=0x0c0ca9fcu; return 0; }
vf3_matrix_move(s,13,8);
goto P_0c0ca9fe;
P_0c0ca9fe: /* original f85c, guest PC 0x0c0ca9fe */
if(!s->budget--) { s->failed_pc=0x0c0ca9feu; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0caa00;
P_0c0caa00: /* original f5ec, guest PC 0x0c0caa00 */
if(!s->budget--) { s->failed_pc=0x0c0caa00u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0caa02;
P_0c0caa02: /* original fe8c, guest PC 0x0c0caa02 */
if(!s->budget--) { s->failed_pc=0x0c0caa02u; return 0; }
vf3_matrix_move(s,14,8);
goto P_0c0caa04;
P_0c0caa04: /* original 60b3, guest PC 0x0c0caa04 */
if(!s->budget--) { s->failed_pc=0x0c0caa04u; return 0; }
r[0]=r[11];
goto P_0c0caa06;
P_0c0caa06: /* original dc10, guest PC 0x0c0caa06 */
if(!s->budget--) { s->failed_pc=0x0c0caa06u; return 0; }
r[12]=read(ram,0x0c0caa48u,4);
goto P_0c0caa08;
P_0c0caa08: /* original 8802, guest PC 0x0c0caa08 */
if(!s->budget--) { s->failed_pc=0x0c0caa08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0caa0a;
P_0c0caa0a: /* original 8b1f, guest PC 0x0c0caa0a */
if(!s->budget--) { s->failed_pc=0x0c0caa0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caa4c; }
goto P_0c0caa0c;
P_0c0caa0c: /* original 9010, guest PC 0x0c0caa0c */
if(!s->budget--) { s->failed_pc=0x0c0caa0cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caa30u,2);
goto P_0c0caa0e;
P_0c0caa0e: /* original fd67, guest PC 0x0c0caa0e */
if(!s->budget--) { s->failed_pc=0x0c0caa0eu; return 0; }
vf3_matrix_store(s,ram,6,r[13]+r[0]);
goto P_0c0caa10;
P_0c0caa10: /* original 7004, guest PC 0x0c0caa10 */
if(!s->budget--) { s->failed_pc=0x0c0caa10u; return 0; }
r[0]+=0x00000004u;
goto P_0c0caa12;
P_0c0caa12: /* original 4c0b, guest PC 0x0c0caa12 */
if(!s->budget--) { s->failed_pc=0x0c0caa12u; return 0; }
target=r[12];
r[16]=code_base|0x0c0caa16u;
vf3_matrix_store(s,ram,7,r[13]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0caa16u) { target=s->pc; goto dispatch; }
goto P_0c0caa16;
P_0c0caa14: /* original fd77, guest PC 0x0c0caa14 */
if(!s->budget--) { s->failed_pc=0x0c0caa14u; return 0; }
vf3_matrix_store(s,ram,7,r[13]+r[0]);
goto P_0c0caa16;
P_0c0caa16: /* original 640f, guest PC 0x0c0caa16 */
if(!s->budget--) { s->failed_pc=0x0c0caa16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0caa18;
P_0c0caa18: /* original 900b, guest PC 0x0c0caa18 */
if(!s->budget--) { s->failed_pc=0x0c0caa18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caa32u,2);
goto P_0c0caa1a;
P_0c0caa1a: /* original 644b, guest PC 0x0c0caa1a */
if(!s->budget--) { s->failed_pc=0x0c0caa1au; return 0; }
r[4]=0u-r[4];
goto P_0c0caa1c;
P_0c0caa1c: /* original 24ea, guest PC 0x0c0caa1c */
if(!s->budget--) { s->failed_pc=0x0c0caa1cu; return 0; }
r[4]^=r[14];
goto P_0c0caa1e;
P_0c0caa1e: /* original 0d45, guest PC 0x0c0caa1e */
if(!s->budget--) { s->failed_pc=0x0c0caa1eu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0caa20;
P_0c0caa20: /* original f5ec, guest PC 0x0c0caa20 */
if(!s->budget--) { s->failed_pc=0x0c0caa20u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0caa22;
P_0c0caa22: /* original 4c0b, guest PC 0x0c0caa22 */
if(!s->budget--) { s->failed_pc=0x0c0caa22u; return 0; }
target=r[12];
r[16]=code_base|0x0c0caa26u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0caa26u) { target=s->pc; goto dispatch; }
goto P_0c0caa26;
P_0c0caa24: /* original f4dc, guest PC 0x0c0caa24 */
if(!s->budget--) { s->failed_pc=0x0c0caa24u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0caa26;
P_0c0caa26: /* original 640f, guest PC 0x0c0caa26 */
if(!s->budget--) { s->failed_pc=0x0c0caa26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0caa28;
P_0c0caa28: /* original 9004, guest PC 0x0c0caa28 */
if(!s->budget--) { s->failed_pc=0x0c0caa28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0caa34u,2);
goto P_0c0caa2a;
P_0c0caa2a: /* original 644b, guest PC 0x0c0caa2a */
if(!s->budget--) { s->failed_pc=0x0c0caa2au; return 0; }
r[4]=0u-r[4];
goto P_0c0caa2c;
P_0c0caa2c: /* original a01f, guest PC 0x0c0caa2c */
if(!s->budget--) { s->failed_pc=0x0c0caa2cu; return 0; }
r[4]^=r[14];
goto P_0c0caa6e;
P_0c0caa2e: /* original 24ea, guest PC 0x0c0caa2e */
if(!s->budget--) { s->failed_pc=0x0c0caa2eu; return 0; }
r[4]^=r[14];
if(!vf3_matrix_family(0x0c0caa30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0caa30u; return 0; } return 1;
P_0c0caa4c: /* original 9061, guest PC 0x0c0caa4c */
if(!s->budget--) { s->failed_pc=0x0c0caa4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab12u,2);
goto P_0c0caa4e;
P_0c0caa4e: /* original fd67, guest PC 0x0c0caa4e */
if(!s->budget--) { s->failed_pc=0x0c0caa4eu; return 0; }
vf3_matrix_store(s,ram,6,r[13]+r[0]);
goto P_0c0caa50;
P_0c0caa50: /* original 70fc, guest PC 0x0c0caa50 */
if(!s->budget--) { s->failed_pc=0x0c0caa50u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0caa52;
P_0c0caa52: /* original 4c0b, guest PC 0x0c0caa52 */
if(!s->budget--) { s->failed_pc=0x0c0caa52u; return 0; }
target=r[12];
r[16]=code_base|0x0c0caa56u;
vf3_matrix_store(s,ram,7,r[13]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0caa56u) { target=s->pc; goto dispatch; }
goto P_0c0caa56;
P_0c0caa54: /* original fd77, guest PC 0x0c0caa54 */
if(!s->budget--) { s->failed_pc=0x0c0caa54u; return 0; }
vf3_matrix_store(s,ram,7,r[13]+r[0]);
goto P_0c0caa56;
P_0c0caa56: /* original 640f, guest PC 0x0c0caa56 */
if(!s->budget--) { s->failed_pc=0x0c0caa56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0caa58;
P_0c0caa58: /* original 905c, guest PC 0x0c0caa58 */
if(!s->budget--) { s->failed_pc=0x0c0caa58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab14u,2);
goto P_0c0caa5a;
P_0c0caa5a: /* original 644b, guest PC 0x0c0caa5a */
if(!s->budget--) { s->failed_pc=0x0c0caa5au; return 0; }
r[4]=0u-r[4];
goto P_0c0caa5c;
P_0c0caa5c: /* original 24ea, guest PC 0x0c0caa5c */
if(!s->budget--) { s->failed_pc=0x0c0caa5cu; return 0; }
r[4]^=r[14];
goto P_0c0caa5e;
P_0c0caa5e: /* original 0d45, guest PC 0x0c0caa5e */
if(!s->budget--) { s->failed_pc=0x0c0caa5eu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0caa60;
P_0c0caa60: /* original f5ec, guest PC 0x0c0caa60 */
if(!s->budget--) { s->failed_pc=0x0c0caa60u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0caa62;
P_0c0caa62: /* original 4c0b, guest PC 0x0c0caa62 */
if(!s->budget--) { s->failed_pc=0x0c0caa62u; return 0; }
target=r[12];
r[16]=code_base|0x0c0caa66u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0caa66u) { target=s->pc; goto dispatch; }
goto P_0c0caa66;
P_0c0caa64: /* original f4dc, guest PC 0x0c0caa64 */
if(!s->budget--) { s->failed_pc=0x0c0caa64u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c0caa66;
P_0c0caa66: /* original 640f, guest PC 0x0c0caa66 */
if(!s->budget--) { s->failed_pc=0x0c0caa66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0caa68;
P_0c0caa68: /* original 9055, guest PC 0x0c0caa68 */
if(!s->budget--) { s->failed_pc=0x0c0caa68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab16u,2);
goto P_0c0caa6a;
P_0c0caa6a: /* original 644b, guest PC 0x0c0caa6a */
if(!s->budget--) { s->failed_pc=0x0c0caa6au; return 0; }
r[4]=0u-r[4];
goto P_0c0caa6c;
P_0c0caa6c: /* original 24ea, guest PC 0x0c0caa6c */
if(!s->budget--) { s->failed_pc=0x0c0caa6cu; return 0; }
r[4]^=r[14];
goto P_0c0caa6e;
P_0c0caa6e: /* original 0d45, guest PC 0x0c0caa6e */
if(!s->budget--) { s->failed_pc=0x0c0caa6eu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c0caa70;
P_0c0caa70: /* original 7bff, guest PC 0x0c0caa70 */
if(!s->budget--) { s->failed_pc=0x0c0caa70u; return 0; }
r[11]+=0xffffffffu;
goto P_0c0caa72;
P_0c0caa72: /* original 9451, guest PC 0x0c0caa72 */
if(!s->budget--) { s->failed_pc=0x0c0caa72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cab18u,2);
goto P_0c0caa74;
P_0c0caa74: /* original 3a4c, guest PC 0x0c0caa74 */
if(!s->budget--) { s->failed_pc=0x0c0caa74u; return 0; }
r[10]+=r[4];
goto P_0c0caa76;
P_0c0caa76: /* original 394c, guest PC 0x0c0caa76 */
if(!s->budget--) { s->failed_pc=0x0c0caa76u; return 0; }
r[9]+=r[4];
goto P_0c0caa78;
P_0c0caa78: /* original e300, guest PC 0x0c0caa78 */
if(!s->budget--) { s->failed_pc=0x0c0caa78u; return 0; }
r[3]=0x00000000u;
goto P_0c0caa7a;
P_0c0caa7a: /* original 3b36, guest PC 0x0c0caa7a */
if(!s->budget--) { s->failed_pc=0x0c0caa7au; return 0; }
r[17]=(r[17]&~1u)|((r[11]>r[3])!=0);
goto P_0c0caa7c;
P_0c0caa7c: /* original 8b01, guest PC 0x0c0caa7c */
if(!s->budget--) { s->failed_pc=0x0c0caa7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0caa82; }
goto P_0c0caa7e;
P_0c0caa7e: /* original af4b, guest PC 0x0c0caa7e */
if(!s->budget--) { s->failed_pc=0x0c0caa7eu; return 0; }
goto P_0c0ca918;
P_0c0caa80: /* original 0009, guest PC 0x0c0caa80 */
if(!s->budget--) { s->failed_pc=0x0c0caa80u; return 0; }
goto P_0c0caa82;
P_0c0caa82: /* original 7f1c, guest PC 0x0c0caa82 */
if(!s->budget--) { s->failed_pc=0x0c0caa82u; return 0; }
r[15]+=0x0000001cu;
goto P_0c0caa84;
P_0c0caa84: /* original 4f26, guest PC 0x0c0caa84 */
if(!s->budget--) { s->failed_pc=0x0c0caa84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0caa86;
P_0c0caa86: /* original fcf9, guest PC 0x0c0caa86 */
if(!s->budget--) { s->failed_pc=0x0c0caa86u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caa88;
P_0c0caa88: /* original fdf9, guest PC 0x0c0caa88 */
if(!s->budget--) { s->failed_pc=0x0c0caa88u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caa8a;
P_0c0caa8a: /* original fef9, guest PC 0x0c0caa8a */
if(!s->budget--) { s->failed_pc=0x0c0caa8au; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caa8c;
P_0c0caa8c: /* original fff9, guest PC 0x0c0caa8c */
if(!s->budget--) { s->failed_pc=0x0c0caa8cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0caa8e;
P_0c0caa8e: /* original 69f6, guest PC 0x0c0caa8e */
if(!s->budget--) { s->failed_pc=0x0c0caa8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0caa90;
P_0c0caa90: /* original 6af6, guest PC 0x0c0caa90 */
if(!s->budget--) { s->failed_pc=0x0c0caa90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0caa92;
P_0c0caa92: /* original 6bf6, guest PC 0x0c0caa92 */
if(!s->budget--) { s->failed_pc=0x0c0caa92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0caa94;
P_0c0caa94: /* original 6cf6, guest PC 0x0c0caa94 */
if(!s->budget--) { s->failed_pc=0x0c0caa94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0caa96;
P_0c0caa96: /* original 6df6, guest PC 0x0c0caa96 */
if(!s->budget--) { s->failed_pc=0x0c0caa96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0caa98;
P_0c0caa98: /* original 000b, guest PC 0x0c0caa98 */
if(!s->budget--) { s->failed_pc=0x0c0caa98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0caa9a: /* original 6ef6, guest PC 0x0c0caa9a */
if(!s->budget--) { s->failed_pc=0x0c0caa9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0caa9cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0caa9cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
