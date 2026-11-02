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
int vf3_away_batch166_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2d48u: goto P_0c0a2d48;
case 0x0c0a2d4au: goto P_0c0a2d4a;
case 0x0c0a2d4cu: goto P_0c0a2d4c;
case 0x0c0a2d4eu: goto P_0c0a2d4e;
case 0x0c0a2d50u: goto P_0c0a2d50;
case 0x0c0a2d52u: goto P_0c0a2d52;
case 0x0c0a2d54u: goto P_0c0a2d54;
case 0x0c0a2d56u: goto P_0c0a2d56;
case 0x0c0a2d58u: goto P_0c0a2d58;
case 0x0c0a2d5au: goto P_0c0a2d5a;
case 0x0c0a2d5cu: goto P_0c0a2d5c;
case 0x0c0a2d5eu: goto P_0c0a2d5e;
case 0x0c0a2d60u: goto P_0c0a2d60;
case 0x0c0a2d62u: goto P_0c0a2d62;
case 0x0c0a2d64u: goto P_0c0a2d64;
case 0x0c0a2d66u: goto P_0c0a2d66;
case 0x0c0a2d68u: goto P_0c0a2d68;
case 0x0c0a2d6au: goto P_0c0a2d6a;
case 0x0c0a2d6cu: goto P_0c0a2d6c;
case 0x0c0a2d6eu: goto P_0c0a2d6e;
case 0x0c0a2d70u: goto P_0c0a2d70;
case 0x0c0a2d72u: goto P_0c0a2d72;
case 0x0c0a2d74u: goto P_0c0a2d74;
case 0x0c0a2d76u: goto P_0c0a2d76;
case 0x0c0a2d78u: goto P_0c0a2d78;
case 0x0c0a2d7au: goto P_0c0a2d7a;
case 0x0c0a2d7cu: goto P_0c0a2d7c;
case 0x0c0a2d7eu: goto P_0c0a2d7e;
case 0x0c0a2d80u: goto P_0c0a2d80;
case 0x0c0a2d82u: goto P_0c0a2d82;
case 0x0c0a2d84u: goto P_0c0a2d84;
case 0x0c0a2d86u: goto P_0c0a2d86;
case 0x0c0a2d88u: goto P_0c0a2d88;
case 0x0c0a2d8au: goto P_0c0a2d8a;
case 0x0c0a2d8cu: goto P_0c0a2d8c;
case 0x0c0a2d8eu: goto P_0c0a2d8e;
case 0x0c0a2d90u: goto P_0c0a2d90;
case 0x0c0a2d92u: goto P_0c0a2d92;
case 0x0c0a2d94u: goto P_0c0a2d94;
case 0x0c0a2d96u: goto P_0c0a2d96;
case 0x0c0a2d98u: goto P_0c0a2d98;
case 0x0c0a2d9au: goto P_0c0a2d9a;
case 0x0c0a2d9cu: goto P_0c0a2d9c;
case 0x0c0a2d9eu: goto P_0c0a2d9e;
case 0x0c0a2da0u: goto P_0c0a2da0;
case 0x0c0a2da2u: goto P_0c0a2da2;
case 0x0c0a2da4u: goto P_0c0a2da4;
case 0x0c0a2da6u: goto P_0c0a2da6;
case 0x0c0a2da8u: goto P_0c0a2da8;
case 0x0c0a2daau: goto P_0c0a2daa;
case 0x0c0a2dacu: goto P_0c0a2dac;
case 0x0c0a2daeu: goto P_0c0a2dae;
case 0x0c0a2db0u: goto P_0c0a2db0;
case 0x0c0a2db2u: goto P_0c0a2db2;
case 0x0c0a2db4u: goto P_0c0a2db4;
case 0x0c0a2db6u: goto P_0c0a2db6;
case 0x0c0a2db8u: goto P_0c0a2db8;
case 0x0c0a2dbau: goto P_0c0a2dba;
case 0x0c0a2dbcu: goto P_0c0a2dbc;
case 0x0c0a2dbeu: goto P_0c0a2dbe;
case 0x0c0a2dc0u: goto P_0c0a2dc0;
case 0x0c0a2dc2u: goto P_0c0a2dc2;
case 0x0c0a2dc4u: goto P_0c0a2dc4;
case 0x0c0a2dc6u: goto P_0c0a2dc6;
case 0x0c0a2dc8u: goto P_0c0a2dc8;
case 0x0c0a2dcau: goto P_0c0a2dca;
case 0x0c0a2dccu: goto P_0c0a2dcc;
case 0x0c0a2dceu: goto P_0c0a2dce;
case 0x0c0a2dd0u: goto P_0c0a2dd0;
case 0x0c0a2dd2u: goto P_0c0a2dd2;
case 0x0c0a2dd4u: goto P_0c0a2dd4;
case 0x0c0a2dd6u: goto P_0c0a2dd6;
case 0x0c0a2dd8u: goto P_0c0a2dd8;
case 0x0c0a2ddau: goto P_0c0a2dda;
case 0x0c0a2ddcu: goto P_0c0a2ddc;
case 0x0c0a2ddeu: goto P_0c0a2dde;
case 0x0c0a2de0u: goto P_0c0a2de0;
case 0x0c0a2de2u: goto P_0c0a2de2;
case 0x0c0a2de4u: goto P_0c0a2de4;
case 0x0c0a2de6u: goto P_0c0a2de6;
case 0x0c0a2de8u: goto P_0c0a2de8;
case 0x0c0a2deau: goto P_0c0a2dea;
case 0x0c0a2decu: goto P_0c0a2dec;
case 0x0c0a2deeu: goto P_0c0a2dee;
case 0x0c0a2df0u: goto P_0c0a2df0;
case 0x0c0a2df2u: goto P_0c0a2df2;
case 0x0c0a2df4u: goto P_0c0a2df4;
case 0x0c0a2df6u: goto P_0c0a2df6;
case 0x0c0a7908u: goto P_0c0a7908;
case 0x0c0a790au: goto P_0c0a790a;
case 0x0c0a790cu: goto P_0c0a790c;
case 0x0c0a790eu: goto P_0c0a790e;
case 0x0c0a7910u: goto P_0c0a7910;
case 0x0c0a7912u: goto P_0c0a7912;
case 0x0c0a7914u: goto P_0c0a7914;
case 0x0c0a7916u: goto P_0c0a7916;
case 0x0c0a7918u: goto P_0c0a7918;
case 0x0c0a791au: goto P_0c0a791a;
case 0x0c0a791cu: goto P_0c0a791c;
case 0x0c0a791eu: goto P_0c0a791e;
case 0x0c0a7920u: goto P_0c0a7920;
case 0x0c0a7922u: goto P_0c0a7922;
case 0x0c0a7924u: goto P_0c0a7924;
case 0x0c0a7926u: goto P_0c0a7926;
case 0x0c0a7928u: goto P_0c0a7928;
case 0x0c0a792au: goto P_0c0a792a;
case 0x0c0a792cu: goto P_0c0a792c;
case 0x0c0a792eu: goto P_0c0a792e;
case 0x0c0a7930u: goto P_0c0a7930;
case 0x0c0a7932u: goto P_0c0a7932;
case 0x0c0a7934u: goto P_0c0a7934;
case 0x0c0a7936u: goto P_0c0a7936;
case 0x0c0a7938u: goto P_0c0a7938;
case 0x0c0a793au: goto P_0c0a793a;
case 0x0c0a793cu: goto P_0c0a793c;
case 0x0c0a793eu: goto P_0c0a793e;
case 0x0c0a7940u: goto P_0c0a7940;
case 0x0c0a7942u: goto P_0c0a7942;
case 0x0c0a7944u: goto P_0c0a7944;
case 0x0c0a7946u: goto P_0c0a7946;
case 0x0c0a7948u: goto P_0c0a7948;
case 0x0c0a794au: goto P_0c0a794a;
case 0x0c0a7978u: goto P_0c0a7978;
case 0x0c0a797au: goto P_0c0a797a;
case 0x0c0a797cu: goto P_0c0a797c;
case 0x0c0a797eu: goto P_0c0a797e;
case 0x0c0a7980u: goto P_0c0a7980;
case 0x0c0a7982u: goto P_0c0a7982;
case 0x0c0a7984u: goto P_0c0a7984;
case 0x0c0a7986u: goto P_0c0a7986;
case 0x0c0a7988u: goto P_0c0a7988;
case 0x0c0a798au: goto P_0c0a798a;
case 0x0c0a798cu: goto P_0c0a798c;
case 0x0c0a798eu: goto P_0c0a798e;
case 0x0c0a7990u: goto P_0c0a7990;
case 0x0c0a7992u: goto P_0c0a7992;
case 0x0c0a7994u: goto P_0c0a7994;
case 0x0c0a7996u: goto P_0c0a7996;
case 0x0c0a7998u: goto P_0c0a7998;
case 0x0c0a799au: goto P_0c0a799a;
case 0x0c0a799cu: goto P_0c0a799c;
case 0x0c0a799eu: goto P_0c0a799e;
case 0x0c0a79a0u: goto P_0c0a79a0;
case 0x0c0a79a2u: goto P_0c0a79a2;
case 0x0c0a79a4u: goto P_0c0a79a4;
case 0x0c0a79a6u: goto P_0c0a79a6;
case 0x0c0a79a8u: goto P_0c0a79a8;
case 0x0c0a79aau: goto P_0c0a79aa;
case 0x0c0a79acu: goto P_0c0a79ac;
case 0x0c0a79aeu: goto P_0c0a79ae;
case 0x0c0a79b0u: goto P_0c0a79b0;
case 0x0c0a79b2u: goto P_0c0a79b2;
case 0x0c0a79b4u: goto P_0c0a79b4;
case 0x0c0a79b6u: goto P_0c0a79b6;
case 0x0c0a79b8u: goto P_0c0a79b8;
case 0x0c0a79bau: goto P_0c0a79ba;
case 0x0c0a79bcu: goto P_0c0a79bc;
case 0x0c0a79beu: goto P_0c0a79be;
case 0x0c0a79c0u: goto P_0c0a79c0;
case 0x0c0a79c2u: goto P_0c0a79c2;
case 0x0c0a79c4u: goto P_0c0a79c4;
case 0x0c0a79c6u: goto P_0c0a79c6;
case 0x0c0a79c8u: goto P_0c0a79c8;
case 0x0c0a79cau: goto P_0c0a79ca;
case 0x0c0a79ccu: goto P_0c0a79cc;
case 0x0c0a79ceu: goto P_0c0a79ce;
case 0x0c0a79d0u: goto P_0c0a79d0;
case 0x0c0a79d2u: goto P_0c0a79d2;
case 0x0c0a79d4u: goto P_0c0a79d4;
case 0x0c0a79d6u: goto P_0c0a79d6;
case 0x0c0a79d8u: goto P_0c0a79d8;
case 0x0c0a79dau: goto P_0c0a79da;
case 0x0c0a79dcu: goto P_0c0a79dc;
case 0x0c0a79deu: goto P_0c0a79de;
case 0x0c0a79e0u: goto P_0c0a79e0;
case 0x0c0a79e2u: goto P_0c0a79e2;
case 0x0c0a79e4u: goto P_0c0a79e4;
case 0x0c0a79e6u: goto P_0c0a79e6;
case 0x0c0a79e8u: goto P_0c0a79e8;
case 0x0c0a79eau: goto P_0c0a79ea;
case 0x0c0a79ecu: goto P_0c0a79ec;
case 0x0c0a79eeu: goto P_0c0a79ee;
case 0x0c0a79f0u: goto P_0c0a79f0;
case 0x0c0a79f2u: goto P_0c0a79f2;
case 0x0c0a79f4u: goto P_0c0a79f4;
case 0x0c0a79f6u: goto P_0c0a79f6;
case 0x0c0a79f8u: goto P_0c0a79f8;
case 0x0c0a79fau: goto P_0c0a79fa;
case 0x0c0a79fcu: goto P_0c0a79fc;
case 0x0c0a79feu: goto P_0c0a79fe;
case 0x0c0a7a00u: goto P_0c0a7a00;
case 0x0c0a7a02u: goto P_0c0a7a02;
case 0x0c0a7a04u: goto P_0c0a7a04;
case 0x0c0a7a06u: goto P_0c0a7a06;
case 0x0c0a7a08u: goto P_0c0a7a08;
case 0x0c0a7a0au: goto P_0c0a7a0a;
case 0x0c0a7f14u: goto P_0c0a7f14;
case 0x0c0a7f16u: goto P_0c0a7f16;
case 0x0c0a7f18u: goto P_0c0a7f18;
case 0x0c0a7f1au: goto P_0c0a7f1a;
case 0x0c0a7f1cu: goto P_0c0a7f1c;
case 0x0c0a7f1eu: goto P_0c0a7f1e;
case 0x0c0a7f20u: goto P_0c0a7f20;
case 0x0c0a7f22u: goto P_0c0a7f22;
case 0x0c0a7f24u: goto P_0c0a7f24;
case 0x0c0a7f26u: goto P_0c0a7f26;
case 0x0c0a7f28u: goto P_0c0a7f28;
case 0x0c0a7f2au: goto P_0c0a7f2a;
case 0x0c0a7f2cu: goto P_0c0a7f2c;
case 0x0c0a7f2eu: goto P_0c0a7f2e;
case 0x0c0a7f30u: goto P_0c0a7f30;
case 0x0c0a7f32u: goto P_0c0a7f32;
case 0x0c0a7f34u: goto P_0c0a7f34;
case 0x0c0a7f36u: goto P_0c0a7f36;
case 0x0c0a7f38u: goto P_0c0a7f38;
case 0x0c0a7f3au: goto P_0c0a7f3a;
case 0x0c0a7f3cu: goto P_0c0a7f3c;
case 0x0c0a7f3eu: goto P_0c0a7f3e;
case 0x0c0a7f40u: goto P_0c0a7f40;
case 0x0c0a7f42u: goto P_0c0a7f42;
case 0x0c0a7f44u: goto P_0c0a7f44;
case 0x0c0a7f46u: goto P_0c0a7f46;
case 0x0c0a7f48u: goto P_0c0a7f48;
case 0x0c0a7f4au: goto P_0c0a7f4a;
case 0x0c0a7f4cu: goto P_0c0a7f4c;
case 0x0c0a7f4eu: goto P_0c0a7f4e;
case 0x0c0a7f50u: goto P_0c0a7f50;
case 0x0c0a7f52u: goto P_0c0a7f52;
case 0x0c0a7f54u: goto P_0c0a7f54;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2d48: /* original 2fe6, guest PC 0x0c0a2d48 */
if(!s->budget--) { s->failed_pc=0x0c0a2d48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4a;
P_0c0a2d4a: /* original 6e43, guest PC 0x0c0a2d4a */
if(!s->budget--) { s->failed_pc=0x0c0a2d4au; return 0; }
r[14]=r[4];
goto P_0c0a2d4c;
P_0c0a2d4c: /* original 2fd6, guest PC 0x0c0a2d4c */
if(!s->budget--) { s->failed_pc=0x0c0a2d4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4e;
P_0c0a2d4e: /* original 6d53, guest PC 0x0c0a2d4e */
if(!s->budget--) { s->failed_pc=0x0c0a2d4eu; return 0; }
r[13]=r[5];
goto P_0c0a2d50;
P_0c0a2d50: /* original 4f22, guest PC 0x0c0a2d50 */
if(!s->budget--) { s->failed_pc=0x0c0a2d50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2d52;
P_0c0a2d52: /* original 53e1, guest PC 0x0c0a2d52 */
if(!s->budget--) { s->failed_pc=0x0c0a2d52u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d54;
P_0c0a2d54: /* original 2338, guest PC 0x0c0a2d54 */
if(!s->budget--) { s->failed_pc=0x0c0a2d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d56;
P_0c0a2d56: /* original 8933, guest PC 0x0c0a2d56 */
if(!s->budget--) { s->failed_pc=0x0c0a2d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d58;
P_0c0a2d58: /* original 53e1, guest PC 0x0c0a2d58 */
if(!s->budget--) { s->failed_pc=0x0c0a2d58u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d5a;
P_0c0a2d5a: /* original 33d2, guest PC 0x0c0a2d5a */
if(!s->budget--) { s->failed_pc=0x0c0a2d5au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d5c;
P_0c0a2d5c: /* original 8930, guest PC 0x0c0a2d5c */
if(!s->budget--) { s->failed_pc=0x0c0a2d5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d5e;
P_0c0a2d5e: /* original 51e1, guest PC 0x0c0a2d5e */
if(!s->budget--) { s->failed_pc=0x0c0a2d5eu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2d60;
P_0c0a2d60: /* original 31dc, guest PC 0x0c0a2d60 */
if(!s->budget--) { s->failed_pc=0x0c0a2d60u; return 0; }
r[1]+=r[13];
goto P_0c0a2d62;
P_0c0a2d62: /* original 6313, guest PC 0x0c0a2d62 */
if(!s->budget--) { s->failed_pc=0x0c0a2d62u; return 0; }
r[3]=r[1];
goto P_0c0a2d64;
P_0c0a2d64: /* original 1e11, guest PC 0x0c0a2d64 */
if(!s->budget--) { s->failed_pc=0x0c0a2d64u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2d66;
P_0c0a2d66: /* original 5231, guest PC 0x0c0a2d66 */
if(!s->budget--) { s->failed_pc=0x0c0a2d66u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2d68;
P_0c0a2d68: /* original 2228, guest PC 0x0c0a2d68 */
if(!s->budget--) { s->failed_pc=0x0c0a2d68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d6a;
P_0c0a2d6a: /* original 8907, guest PC 0x0c0a2d6a */
if(!s->budget--) { s->failed_pc=0x0c0a2d6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d6c;
P_0c0a2d6c: /* original 52e1, guest PC 0x0c0a2d6c */
if(!s->budget--) { s->failed_pc=0x0c0a2d6cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d6e;
P_0c0a2d6e: /* original 5321, guest PC 0x0c0a2d6e */
if(!s->budget--) { s->failed_pc=0x0c0a2d6eu; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0a2d70;
P_0c0a2d70: /* original 33d2, guest PC 0x0c0a2d70 */
if(!s->budget--) { s->failed_pc=0x0c0a2d70u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d72;
P_0c0a2d72: /* original 8903, guest PC 0x0c0a2d72 */
if(!s->budget--) { s->failed_pc=0x0c0a2d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d74;
P_0c0a2d74: /* original 54e1, guest PC 0x0c0a2d74 */
if(!s->budget--) { s->failed_pc=0x0c0a2d74u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d76;
P_0c0a2d76: /* original 5341, guest PC 0x0c0a2d76 */
if(!s->budget--) { s->failed_pc=0x0c0a2d76u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2d78;
P_0c0a2d78: /* original 33dc, guest PC 0x0c0a2d78 */
if(!s->budget--) { s->failed_pc=0x0c0a2d78u; return 0; }
r[3]+=r[13];
goto P_0c0a2d7a;
P_0c0a2d7a: /* original 1431, guest PC 0x0c0a2d7a */
if(!s->budget--) { s->failed_pc=0x0c0a2d7au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d7c;
P_0c0a2d7c: /* original 52e1, guest PC 0x0c0a2d7c */
if(!s->budget--) { s->failed_pc=0x0c0a2d7cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d7e;
P_0c0a2d7e: /* original 5323, guest PC 0x0c0a2d7e */
if(!s->budget--) { s->failed_pc=0x0c0a2d7eu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0a2d80;
P_0c0a2d80: /* original 2338, guest PC 0x0c0a2d80 */
if(!s->budget--) { s->failed_pc=0x0c0a2d80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d82;
P_0c0a2d82: /* original 8907, guest PC 0x0c0a2d82 */
if(!s->budget--) { s->failed_pc=0x0c0a2d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d84;
P_0c0a2d84: /* original 53e1, guest PC 0x0c0a2d84 */
if(!s->budget--) { s->failed_pc=0x0c0a2d84u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d86;
P_0c0a2d86: /* original 5233, guest PC 0x0c0a2d86 */
if(!s->budget--) { s->failed_pc=0x0c0a2d86u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c0a2d88;
P_0c0a2d88: /* original 32d2, guest PC 0x0c0a2d88 */
if(!s->budget--) { s->failed_pc=0x0c0a2d88u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[13])!=0);
goto P_0c0a2d8a;
P_0c0a2d8a: /* original 8903, guest PC 0x0c0a2d8a */
if(!s->budget--) { s->failed_pc=0x0c0a2d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d8c;
P_0c0a2d8c: /* original 54e1, guest PC 0x0c0a2d8c */
if(!s->budget--) { s->failed_pc=0x0c0a2d8cu; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d8e;
P_0c0a2d8e: /* original 5243, guest PC 0x0c0a2d8e */
if(!s->budget--) { s->failed_pc=0x0c0a2d8eu; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0a2d90;
P_0c0a2d90: /* original 32dc, guest PC 0x0c0a2d90 */
if(!s->budget--) { s->failed_pc=0x0c0a2d90u; return 0; }
r[2]+=r[13];
goto P_0c0a2d92;
P_0c0a2d92: /* original 1423, guest PC 0x0c0a2d92 */
if(!s->budget--) { s->failed_pc=0x0c0a2d92u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0a2d94;
P_0c0a2d94: /* original c718, guest PC 0x0c0a2d94 */
if(!s->budget--) { s->failed_pc=0x0c0a2d94u; return 0; }
r[0]=code_base|0x000a2df8u;
goto P_0c0a2d96;
P_0c0a2d96: /* original 53e1, guest PC 0x0c0a2d96 */
if(!s->budget--) { s->failed_pc=0x0c0a2d96u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d98;
P_0c0a2d98: /* original f408, guest PC 0x0c0a2d98 */
if(!s->budget--) { s->failed_pc=0x0c0a2d98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a2d9a;
P_0c0a2d9a: /* original e010, guest PC 0x0c0a2d9a */
if(!s->budget--) { s->failed_pc=0x0c0a2d9au; return 0; }
r[0]=0x00000010u;
goto P_0c0a2d9c;
P_0c0a2d9c: /* original f336, guest PC 0x0c0a2d9c */
if(!s->budget--) { s->failed_pc=0x0c0a2d9cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2d9e;
P_0c0a2d9e: /* original f342, guest PC 0x0c0a2d9e */
if(!s->budget--) { s->failed_pc=0x0c0a2d9eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2da0;
P_0c0a2da0: /* original f337, guest PC 0x0c0a2da0 */
if(!s->budget--) { s->failed_pc=0x0c0a2da0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2da2;
P_0c0a2da2: /* original e014, guest PC 0x0c0a2da2 */
if(!s->budget--) { s->failed_pc=0x0c0a2da2u; return 0; }
r[0]=0x00000014u;
goto P_0c0a2da4;
P_0c0a2da4: /* original 53e1, guest PC 0x0c0a2da4 */
if(!s->budget--) { s->failed_pc=0x0c0a2da4u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2da6;
P_0c0a2da6: /* original f336, guest PC 0x0c0a2da6 */
if(!s->budget--) { s->failed_pc=0x0c0a2da6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2da8;
P_0c0a2da8: /* original f342, guest PC 0x0c0a2da8 */
if(!s->budget--) { s->failed_pc=0x0c0a2da8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2daa;
P_0c0a2daa: /* original f337, guest PC 0x0c0a2daa */
if(!s->budget--) { s->failed_pc=0x0c0a2daau; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dac;
P_0c0a2dac: /* original e018, guest PC 0x0c0a2dac */
if(!s->budget--) { s->failed_pc=0x0c0a2dacu; return 0; }
r[0]=0x00000018u;
goto P_0c0a2dae;
P_0c0a2dae: /* original 53e1, guest PC 0x0c0a2dae */
if(!s->budget--) { s->failed_pc=0x0c0a2daeu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2db0;
P_0c0a2db0: /* original f336, guest PC 0x0c0a2db0 */
if(!s->budget--) { s->failed_pc=0x0c0a2db0u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2db2;
P_0c0a2db2: /* original f342, guest PC 0x0c0a2db2 */
if(!s->budget--) { s->failed_pc=0x0c0a2db2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2db4;
P_0c0a2db4: /* original f337, guest PC 0x0c0a2db4 */
if(!s->budget--) { s->failed_pc=0x0c0a2db4u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2db6;
P_0c0a2db6: /* original e01c, guest PC 0x0c0a2db6 */
if(!s->budget--) { s->failed_pc=0x0c0a2db6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a2db8;
P_0c0a2db8: /* original 53e1, guest PC 0x0c0a2db8 */
if(!s->budget--) { s->failed_pc=0x0c0a2db8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2dba;
P_0c0a2dba: /* original f336, guest PC 0x0c0a2dba */
if(!s->budget--) { s->failed_pc=0x0c0a2dbau; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2dbc;
P_0c0a2dbc: /* original f342, guest PC 0x0c0a2dbc */
if(!s->budget--) { s->failed_pc=0x0c0a2dbcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2dbe;
P_0c0a2dbe: /* original f337, guest PC 0x0c0a2dbe */
if(!s->budget--) { s->failed_pc=0x0c0a2dbeu; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dc0;
P_0c0a2dc0: /* original 53eb, guest PC 0x0c0a2dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc0u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc2;
P_0c0a2dc2: /* original 2338, guest PC 0x0c0a2dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2dc4;
P_0c0a2dc4: /* original 8908, guest PC 0x0c0a2dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dc6;
P_0c0a2dc6: /* original 53eb, guest PC 0x0c0a2dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc6u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc8;
P_0c0a2dc8: /* original 33d2, guest PC 0x0c0a2dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2dca;
P_0c0a2dca: /* original 8905, guest PC 0x0c0a2dca */
if(!s->budget--) { s->failed_pc=0x0c0a2dcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dcc;
P_0c0a2dcc: /* original 51eb, guest PC 0x0c0a2dcc */
if(!s->budget--) { s->failed_pc=0x0c0a2dccu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c0a2dce;
P_0c0a2dce: /* original 65d3, guest PC 0x0c0a2dce */
if(!s->budget--) { s->failed_pc=0x0c0a2dceu; return 0; }
r[5]=r[13];
goto P_0c0a2dd0;
P_0c0a2dd0: /* original 31dc, guest PC 0x0c0a2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd0u; return 0; }
r[1]+=r[13];
goto P_0c0a2dd2;
P_0c0a2dd2: /* original 1e1b, guest PC 0x0c0a2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd2u; return 0; }
write(ram,r[14]+44,r[1],4);
goto P_0c0a2dd4;
P_0c0a2dd4: /* original bfb8, guest PC 0x0c0a2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd4u; return 0; }
target=code_base|0x0c0a2d48u; r[16]=code_base|0x0c0a2dd8u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2dd8u) { target=s->pc; goto dispatch; }
goto P_0c0a2dd8;
P_0c0a2dd6: /* original 6413, guest PC 0x0c0a2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd6u; return 0; }
r[4]=r[1];
goto P_0c0a2dd8;
P_0c0a2dd8: /* original 52ec, guest PC 0x0c0a2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd8u; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c0a2dda;
P_0c0a2dda: /* original 2228, guest PC 0x0c0a2dda */
if(!s->budget--) { s->failed_pc=0x0c0a2ddau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2ddc;
P_0c0a2ddc: /* original 8908, guest PC 0x0c0a2ddc */
if(!s->budget--) { s->failed_pc=0x0c0a2ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2dde;
P_0c0a2dde: /* original 53ec, guest PC 0x0c0a2dde */
if(!s->budget--) { s->failed_pc=0x0c0a2ddeu; return 0; }
r[3]=read(ram,r[14]+48,4);
goto P_0c0a2de0;
P_0c0a2de0: /* original 33d2, guest PC 0x0c0a2de0 */
if(!s->budget--) { s->failed_pc=0x0c0a2de0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2de2;
P_0c0a2de2: /* original 8905, guest PC 0x0c0a2de2 */
if(!s->budget--) { s->failed_pc=0x0c0a2de2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2de4;
P_0c0a2de4: /* original 51ec, guest PC 0x0c0a2de4 */
if(!s->budget--) { s->failed_pc=0x0c0a2de4u; return 0; }
r[1]=read(ram,r[14]+48,4);
goto P_0c0a2de6;
P_0c0a2de6: /* original 64d3, guest PC 0x0c0a2de6 */
if(!s->budget--) { s->failed_pc=0x0c0a2de6u; return 0; }
r[4]=r[13];
goto P_0c0a2de8;
P_0c0a2de8: /* original 31dc, guest PC 0x0c0a2de8 */
if(!s->budget--) { s->failed_pc=0x0c0a2de8u; return 0; }
r[1]+=r[13];
goto P_0c0a2dea;
P_0c0a2dea: /* original 1e1c, guest PC 0x0c0a2dea */
if(!s->budget--) { s->failed_pc=0x0c0a2deau; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c0a2dec;
P_0c0a2dec: /* original afb1, guest PC 0x0c0a2dec */
if(!s->budget--) { s->failed_pc=0x0c0a2decu; return 0; }
r[14]=r[1];
goto P_0c0a2d52;
P_0c0a2dee: /* original 6e13, guest PC 0x0c0a2dee */
if(!s->budget--) { s->failed_pc=0x0c0a2deeu; return 0; }
r[14]=r[1];
goto P_0c0a2df0;
P_0c0a2df0: /* original 4f26, guest PC 0x0c0a2df0 */
if(!s->budget--) { s->failed_pc=0x0c0a2df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2df2;
P_0c0a2df2: /* original 6df6, guest PC 0x0c0a2df2 */
if(!s->budget--) { s->failed_pc=0x0c0a2df2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2df4;
P_0c0a2df4: /* original 000b, guest PC 0x0c0a2df4 */
if(!s->budget--) { s->failed_pc=0x0c0a2df4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2df6: /* original 6ef6, guest PC 0x0c0a2df6 */
if(!s->budget--) { s->failed_pc=0x0c0a2df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2df8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2df8u; return 0; } return 1;
P_0c0a7908: /* original 2fe6, guest PC 0x0c0a7908 */
if(!s->budget--) { s->failed_pc=0x0c0a7908u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790a;
P_0c0a790a: /* original c71a, guest PC 0x0c0a790a */
if(!s->budget--) { s->failed_pc=0x0c0a790au; return 0; }
r[0]=code_base|0x000a7974u;
goto P_0c0a790c;
P_0c0a790c: /* original 2fd6, guest PC 0x0c0a790c */
if(!s->budget--) { s->failed_pc=0x0c0a790cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a790e;
P_0c0a790e: /* original 2fc6, guest PC 0x0c0a790e */
if(!s->budget--) { s->failed_pc=0x0c0a790eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7910;
P_0c0a7910: /* original 2fb6, guest PC 0x0c0a7910 */
if(!s->budget--) { s->failed_pc=0x0c0a7910u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7912;
P_0c0a7912: /* original fffb, guest PC 0x0c0a7912 */
if(!s->budget--) { s->failed_pc=0x0c0a7912u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7914;
P_0c0a7914: /* original ffeb, guest PC 0x0c0a7914 */
if(!s->budget--) { s->failed_pc=0x0c0a7914u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0a7916;
P_0c0a7916: /* original ffdb, guest PC 0x0c0a7916 */
if(!s->budget--) { s->failed_pc=0x0c0a7916u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0a7918;
P_0c0a7918: /* original ffcb, guest PC 0x0c0a7918 */
if(!s->budget--) { s->failed_pc=0x0c0a7918u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0a791a;
P_0c0a791a: /* original 4f22, guest PC 0x0c0a791a */
if(!s->budget--) { s->failed_pc=0x0c0a791au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a791c;
P_0c0a791c: /* original ff5c, guest PC 0x0c0a791c */
if(!s->budget--) { s->failed_pc=0x0c0a791cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a791e;
P_0c0a791e: /* original f508, guest PC 0x0c0a791e */
if(!s->budget--) { s->failed_pc=0x0c0a791eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0a7920;
P_0c0a7920: /* original e004, guest PC 0x0c0a7920 */
if(!s->budget--) { s->failed_pc=0x0c0a7920u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7922;
P_0c0a7922: /* original 7fd8, guest PC 0x0c0a7922 */
if(!s->budget--) { s->failed_pc=0x0c0a7922u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0a7924;
P_0c0a7924: /* original fd5c, guest PC 0x0c0a7924 */
if(!s->budget--) { s->failed_pc=0x0c0a7924u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7926;
P_0c0a7926: /* original 65f3, guest PC 0x0c0a7926 */
if(!s->budget--) { s->failed_pc=0x0c0a7926u; return 0; }
r[5]=r[15];
goto P_0c0a7928;
P_0c0a7928: /* original ff57, guest PC 0x0c0a7928 */
if(!s->budget--) { s->failed_pc=0x0c0a7928u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a792a;
P_0c0a792a: /* original 7508, guest PC 0x0c0a792a */
if(!s->budget--) { s->failed_pc=0x0c0a792au; return 0; }
r[5]+=0x00000008u;
goto P_0c0a792c;
P_0c0a792c: /* original f59d, guest PC 0x0c0a792c */
if(!s->budget--) { s->failed_pc=0x0c0a792cu; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a792e;
P_0c0a792e: /* original f455, guest PC 0x0c0a792e */
if(!s->budget--) { s->failed_pc=0x0c0a792eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7930;
P_0c0a7930: /* original 6b53, guest PC 0x0c0a7930 */
if(!s->budget--) { s->failed_pc=0x0c0a7930u; return 0; }
r[11]=r[5];
goto P_0c0a7932;
P_0c0a7932: /* original 8f01, guest PC 0x0c0a7932 */
if(!s->budget--) { s->failed_pc=0x0c0a7932u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,12,13);
if(!cond) { goto P_0c0a7938; }
goto P_0c0a7936;
P_0c0a7934: /* original fcdc, guest PC 0x0c0a7934 */
if(!s->budget--) { s->failed_pc=0x0c0a7934u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0a7936;
P_0c0a7936: /* original f45c, guest PC 0x0c0a7936 */
if(!s->budget--) { s->failed_pc=0x0c0a7936u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7938;
P_0c0a7938: /* original ff55, guest PC 0x0c0a7938 */
if(!s->budget--) { s->failed_pc=0x0c0a7938u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[5]))!=0);
goto P_0c0a793a;
P_0c0a793a: /* original 8b00, guest PC 0x0c0a793a */
if(!s->budget--) { s->failed_pc=0x0c0a793au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a793e; }
goto P_0c0a793c;
P_0c0a793c: /* original ff5c, guest PC 0x0c0a793c */
if(!s->budget--) { s->failed_pc=0x0c0a793cu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a793e;
P_0c0a793e: /* original 2448, guest PC 0x0c0a793e */
if(!s->budget--) { s->failed_pc=0x0c0a793eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a7940;
P_0c0a7940: /* original 8b1a, guest PC 0x0c0a7940 */
if(!s->budget--) { s->failed_pc=0x0c0a7940u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7978; }
goto P_0c0a7942;
P_0c0a7942: /* original e004, guest PC 0x0c0a7942 */
if(!s->budget--) { s->failed_pc=0x0c0a7942u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7944;
P_0c0a7944: /* original fc5c, guest PC 0x0c0a7944 */
if(!s->budget--) { s->failed_pc=0x0c0a7944u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7946;
P_0c0a7946: /* original ff57, guest PC 0x0c0a7946 */
if(!s->budget--) { s->failed_pc=0x0c0a7946u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a7948;
P_0c0a7948: /* original a023, guest PC 0x0c0a7948 */
if(!s->budget--) { s->failed_pc=0x0c0a7948u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c0a7992;
P_0c0a794a: /* original fdcc, guest PC 0x0c0a794a */
if(!s->budget--) { s->failed_pc=0x0c0a794au; return 0; }
vf3_matrix_move(s,13,12);
if(!vf3_matrix_family(0x0c0a794cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a794cu; return 0; } return 1;
P_0c0a7978: /* original e201, guest PC 0x0c0a7978 */
if(!s->budget--) { s->failed_pc=0x0c0a7978u; return 0; }
r[2]=0x00000001u;
goto P_0c0a797a;
P_0c0a797a: /* original 2248, guest PC 0x0c0a797a */
if(!s->budget--) { s->failed_pc=0x0c0a797au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a797c;
P_0c0a797c: /* original 8d01, guest PC 0x0c0a797c */
if(!s->budget--) { s->failed_pc=0x0c0a797cu; return 0; }
cond=r[17]&1u;
r[2]=0x00000002u;
if(cond) { goto P_0c0a7982; }
goto P_0c0a7980;
P_0c0a797e: /* original e202, guest PC 0x0c0a797e */
if(!s->budget--) { s->failed_pc=0x0c0a797eu; return 0; }
r[2]=0x00000002u;
goto P_0c0a7980;
P_0c0a7980: /* original fc5c, guest PC 0x0c0a7980 */
if(!s->budget--) { s->failed_pc=0x0c0a7980u; return 0; }
vf3_matrix_move(s,12,5);
goto P_0c0a7982;
P_0c0a7982: /* original 2248, guest PC 0x0c0a7982 */
if(!s->budget--) { s->failed_pc=0x0c0a7982u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0a7984;
P_0c0a7984: /* original 8901, guest PC 0x0c0a7984 */
if(!s->budget--) { s->failed_pc=0x0c0a7984u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a798a; }
goto P_0c0a7986;
P_0c0a7986: /* original e004, guest PC 0x0c0a7986 */
if(!s->budget--) { s->failed_pc=0x0c0a7986u; return 0; }
r[0]=0x00000004u;
goto P_0c0a7988;
P_0c0a7988: /* original ff57, guest PC 0x0c0a7988 */
if(!s->budget--) { s->failed_pc=0x0c0a7988u; return 0; }
vf3_matrix_store(s,ram,5,r[15]+r[0]);
goto P_0c0a798a;
P_0c0a798a: /* original e304, guest PC 0x0c0a798a */
if(!s->budget--) { s->failed_pc=0x0c0a798au; return 0; }
r[3]=0x00000004u;
goto P_0c0a798c;
P_0c0a798c: /* original 2438, guest PC 0x0c0a798c */
if(!s->budget--) { s->failed_pc=0x0c0a798cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0a798e;
P_0c0a798e: /* original 8900, guest PC 0x0c0a798e */
if(!s->budget--) { s->failed_pc=0x0c0a798eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7992; }
goto P_0c0a7990;
P_0c0a7990: /* original fd5c, guest PC 0x0c0a7990 */
if(!s->budget--) { s->failed_pc=0x0c0a7990u; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0a7992;
P_0c0a7992: /* original 6353, guest PC 0x0c0a7992 */
if(!s->budget--) { s->failed_pc=0x0c0a7992u; return 0; }
r[3]=r[5];
goto P_0c0a7994;
P_0c0a7994: /* original 6d33, guest PC 0x0c0a7994 */
if(!s->budget--) { s->failed_pc=0x0c0a7994u; return 0; }
r[13]=r[3];
goto P_0c0a7996;
P_0c0a7996: /* original 6e33, guest PC 0x0c0a7996 */
if(!s->budget--) { s->failed_pc=0x0c0a7996u; return 0; }
r[14]=r[3];
goto P_0c0a7998;
P_0c0a7998: /* original 6c33, guest PC 0x0c0a7998 */
if(!s->budget--) { s->failed_pc=0x0c0a7998u; return 0; }
r[12]=r[3];
goto P_0c0a799a;
P_0c0a799a: /* original 7c0c, guest PC 0x0c0a799a */
if(!s->budget--) { s->failed_pc=0x0c0a799au; return 0; }
r[12]+=0x0000000cu;
goto P_0c0a799c;
P_0c0a799c: /* original fe4c, guest PC 0x0c0a799c */
if(!s->budget--) { s->failed_pc=0x0c0a799cu; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c0a799e;
P_0c0a799e: /* original 2f32, guest PC 0x0c0a799e */
if(!s->budget--) { s->failed_pc=0x0c0a799eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a79a0;
P_0c0a79a0: /* original 7e08, guest PC 0x0c0a79a0 */
if(!s->budget--) { s->failed_pc=0x0c0a79a0u; return 0; }
r[14]+=0x00000008u;
goto P_0c0a79a2;
P_0c0a79a2: /* original f38d, guest PC 0x0c0a79a2 */
if(!s->budget--) { s->failed_pc=0x0c0a79a2u; return 0; }
fr[3]=0;
goto P_0c0a79a4;
P_0c0a79a4: /* original 7d04, guest PC 0x0c0a79a4 */
if(!s->budget--) { s->failed_pc=0x0c0a79a4u; return 0; }
r[13]+=0x00000004u;
goto P_0c0a79a6;
P_0c0a79a6: /* original f33a, guest PC 0x0c0a79a6 */
if(!s->budget--) { s->failed_pc=0x0c0a79a6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79a8;
P_0c0a79a8: /* original fdea, guest PC 0x0c0a79a8 */
if(!s->budget--) { s->failed_pc=0x0c0a79a8u; return 0; }
vf3_matrix_store(s,ram,14,r[13]);
goto P_0c0a79aa;
P_0c0a79aa: /* original feea, guest PC 0x0c0a79aa */
if(!s->budget--) { s->failed_pc=0x0c0a79aau; return 0; }
vf3_matrix_store(s,ram,14,r[14]);
goto P_0c0a79ac;
P_0c0a79ac: /* original fcea, guest PC 0x0c0a79ac */
if(!s->budget--) { s->failed_pc=0x0c0a79acu; return 0; }
vf3_matrix_store(s,ram,14,r[12]);
goto P_0c0a79ae;
P_0c0a79ae: /* original d33f, guest PC 0x0c0a79ae */
if(!s->budget--) { s->failed_pc=0x0c0a79aeu; return 0; }
r[3]=read(ram,0x0c0a7aacu,4);
goto P_0c0a79b0;
P_0c0a79b0: /* original 430b, guest PC 0x0c0a79b0 */
if(!s->budget--) { s->failed_pc=0x0c0a79b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79b4u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79b4u) { target=s->pc; goto dispatch; }
goto P_0c0a79b4;
P_0c0a79b2: /* original 64b3, guest PC 0x0c0a79b2 */
if(!s->budget--) { s->failed_pc=0x0c0a79b2u; return 0; }
r[4]=r[11];
goto P_0c0a79b4;
P_0c0a79b4: /* original d23e, guest PC 0x0c0a79b4 */
if(!s->budget--) { s->failed_pc=0x0c0a79b4u; return 0; }
r[2]=read(ram,0x0c0a7ab0u,4);
goto P_0c0a79b6;
P_0c0a79b6: /* original 420b, guest PC 0x0c0a79b6 */
if(!s->budget--) { s->failed_pc=0x0c0a79b6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79bau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79bau) { target=s->pc; goto dispatch; }
goto P_0c0a79ba;
P_0c0a79b8: /* original f4ec, guest PC 0x0c0a79b8 */
if(!s->budget--) { s->failed_pc=0x0c0a79b8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0a79ba;
P_0c0a79ba: /* original 63f2, guest PC 0x0c0a79ba */
if(!s->budget--) { s->failed_pc=0x0c0a79bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a79bc;
P_0c0a79bc: /* original e004, guest PC 0x0c0a79bc */
if(!s->budget--) { s->failed_pc=0x0c0a79bcu; return 0; }
r[0]=0x00000004u;
goto P_0c0a79be;
P_0c0a79be: /* original f38d, guest PC 0x0c0a79be */
if(!s->budget--) { s->failed_pc=0x0c0a79beu; return 0; }
fr[3]=0;
goto P_0c0a79c0;
P_0c0a79c0: /* original 65b3, guest PC 0x0c0a79c0 */
if(!s->budget--) { s->failed_pc=0x0c0a79c0u; return 0; }
r[5]=r[11];
goto P_0c0a79c2;
P_0c0a79c2: /* original f33a, guest PC 0x0c0a79c2 */
if(!s->budget--) { s->failed_pc=0x0c0a79c2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0a79c4;
P_0c0a79c4: /* original f2fc, guest PC 0x0c0a79c4 */
if(!s->budget--) { s->failed_pc=0x0c0a79c4u; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79c6;
P_0c0a79c6: /* original f2d2, guest PC 0x0c0a79c6 */
if(!s->budget--) { s->failed_pc=0x0c0a79c6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[13],r[18],'*');
goto P_0c0a79c8;
P_0c0a79c8: /* original fd2a, guest PC 0x0c0a79c8 */
if(!s->budget--) { s->failed_pc=0x0c0a79c8u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c0a79ca;
P_0c0a79ca: /* original f3f6, guest PC 0x0c0a79ca */
if(!s->budget--) { s->failed_pc=0x0c0a79cau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a79cc;
P_0c0a79cc: /* original f2fc, guest PC 0x0c0a79cc */
if(!s->budget--) { s->failed_pc=0x0c0a79ccu; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c0a79ce;
P_0c0a79ce: /* original ffc2, guest PC 0x0c0a79ce */
if(!s->budget--) { s->failed_pc=0x0c0a79ceu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[12],r[18],'*');
goto P_0c0a79d0;
P_0c0a79d0: /* original f232, guest PC 0x0c0a79d0 */
if(!s->budget--) { s->failed_pc=0x0c0a79d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a79d2;
P_0c0a79d2: /* original fe2a, guest PC 0x0c0a79d2 */
if(!s->budget--) { s->failed_pc=0x0c0a79d2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]);
goto P_0c0a79d4;
P_0c0a79d4: /* original fcfa, guest PC 0x0c0a79d4 */
if(!s->budget--) { s->failed_pc=0x0c0a79d4u; return 0; }
vf3_matrix_store(s,ram,15,r[12]);
goto P_0c0a79d6;
P_0c0a79d6: /* original d337, guest PC 0x0c0a79d6 */
if(!s->budget--) { s->failed_pc=0x0c0a79d6u; return 0; }
r[3]=read(ram,0x0c0a7ab4u,4);
goto P_0c0a79d8;
P_0c0a79d8: /* original 430b, guest PC 0x0c0a79d8 */
if(!s->budget--) { s->failed_pc=0x0c0a79d8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79dcu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79dcu) { target=s->pc; goto dispatch; }
goto P_0c0a79dc;
P_0c0a79da: /* original e400, guest PC 0x0c0a79da */
if(!s->budget--) { s->failed_pc=0x0c0a79dau; return 0; }
r[4]=0x00000000u;
goto P_0c0a79dc;
P_0c0a79dc: /* original d236, guest PC 0x0c0a79dc */
if(!s->budget--) { s->failed_pc=0x0c0a79dcu; return 0; }
r[2]=read(ram,0x0c0a7ab8u,4);
goto P_0c0a79de;
P_0c0a79de: /* original f5e8, guest PC 0x0c0a79de */
if(!s->budget--) { s->failed_pc=0x0c0a79deu; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c0a79e0;
P_0c0a79e0: /* original f6c8, guest PC 0x0c0a79e0 */
if(!s->budget--) { s->failed_pc=0x0c0a79e0u; return 0; }
vf3_matrix_load(s,ram,6,r[12]);
goto P_0c0a79e2;
P_0c0a79e2: /* original 420b, guest PC 0x0c0a79e2 */
if(!s->budget--) { s->failed_pc=0x0c0a79e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79e6u;
vf3_matrix_load(s,ram,4,r[13]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79e6u) { target=s->pc; goto dispatch; }
goto P_0c0a79e6;
P_0c0a79e4: /* original f4d8, guest PC 0x0c0a79e4 */
if(!s->budget--) { s->failed_pc=0x0c0a79e4u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c0a79e6;
P_0c0a79e6: /* original d335, guest PC 0x0c0a79e6 */
if(!s->budget--) { s->failed_pc=0x0c0a79e6u; return 0; }
r[3]=read(ram,0x0c0a7abcu,4);
goto P_0c0a79e8;
P_0c0a79e8: /* original e502, guest PC 0x0c0a79e8 */
if(!s->budget--) { s->failed_pc=0x0c0a79e8u; return 0; }
r[5]=0x00000002u;
goto P_0c0a79ea;
P_0c0a79ea: /* original 430b, guest PC 0x0c0a79ea */
if(!s->budget--) { s->failed_pc=0x0c0a79eau; return 0; }
target=r[3];
r[16]=code_base|0x0c0a79eeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79eeu) { target=s->pc; goto dispatch; }
goto P_0c0a79ee;
P_0c0a79ec: /* original e400, guest PC 0x0c0a79ec */
if(!s->budget--) { s->failed_pc=0x0c0a79ecu; return 0; }
r[4]=0x00000000u;
goto P_0c0a79ee;
P_0c0a79ee: /* original d234, guest PC 0x0c0a79ee */
if(!s->budget--) { s->failed_pc=0x0c0a79eeu; return 0; }
r[2]=read(ram,0x0c0a7ac0u,4);
goto P_0c0a79f0;
P_0c0a79f0: /* original e501, guest PC 0x0c0a79f0 */
if(!s->budget--) { s->failed_pc=0x0c0a79f0u; return 0; }
r[5]=0x00000001u;
goto P_0c0a79f2;
P_0c0a79f2: /* original 420b, guest PC 0x0c0a79f2 */
if(!s->budget--) { s->failed_pc=0x0c0a79f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a79f6u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a79f6u) { target=s->pc; goto dispatch; }
goto P_0c0a79f6;
P_0c0a79f4: /* original e400, guest PC 0x0c0a79f4 */
if(!s->budget--) { s->failed_pc=0x0c0a79f4u; return 0; }
r[4]=0x00000000u;
goto P_0c0a79f6;
P_0c0a79f6: /* original 7f28, guest PC 0x0c0a79f6 */
if(!s->budget--) { s->failed_pc=0x0c0a79f6u; return 0; }
r[15]+=0x00000028u;
goto P_0c0a79f8;
P_0c0a79f8: /* original 4f26, guest PC 0x0c0a79f8 */
if(!s->budget--) { s->failed_pc=0x0c0a79f8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a79fa;
P_0c0a79fa: /* original fcf9, guest PC 0x0c0a79fa */
if(!s->budget--) { s->failed_pc=0x0c0a79fau; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fc;
P_0c0a79fc: /* original fdf9, guest PC 0x0c0a79fc */
if(!s->budget--) { s->failed_pc=0x0c0a79fcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a79fe;
P_0c0a79fe: /* original fef9, guest PC 0x0c0a79fe */
if(!s->budget--) { s->failed_pc=0x0c0a79feu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a00;
P_0c0a7a00: /* original fff9, guest PC 0x0c0a7a00 */
if(!s->budget--) { s->failed_pc=0x0c0a7a00u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7a02;
P_0c0a7a02: /* original 6bf6, guest PC 0x0c0a7a02 */
if(!s->budget--) { s->failed_pc=0x0c0a7a02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a7a04;
P_0c0a7a04: /* original 6cf6, guest PC 0x0c0a7a04 */
if(!s->budget--) { s->failed_pc=0x0c0a7a04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a7a06;
P_0c0a7a06: /* original 6df6, guest PC 0x0c0a7a06 */
if(!s->budget--) { s->failed_pc=0x0c0a7a06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7a08;
P_0c0a7a08: /* original 000b, guest PC 0x0c0a7a08 */
if(!s->budget--) { s->failed_pc=0x0c0a7a08u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7a0a: /* original 6ef6, guest PC 0x0c0a7a0a */
if(!s->budget--) { s->failed_pc=0x0c0a7a0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7a0cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7a0cu; return 0; } return 1;
P_0c0a7f14: /* original 2fe6, guest PC 0x0c0a7f14 */
if(!s->budget--) { s->failed_pc=0x0c0a7f14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f16;
P_0c0a7f16: /* original d324, guest PC 0x0c0a7f16 */
if(!s->budget--) { s->failed_pc=0x0c0a7f16u; return 0; }
r[3]=read(ram,0x0c0a7fa8u,4);
goto P_0c0a7f18;
P_0c0a7f18: /* original 4f12, guest PC 0x0c0a7f18 */
if(!s->budget--) { s->failed_pc=0x0c0a7f18u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0a7f1a;
P_0c0a7f1a: /* original 6632, guest PC 0x0c0a7f1a */
if(!s->budget--) { s->failed_pc=0x0c0a7f1au; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0a7f1c;
P_0c0a7f1c: /* original 856d, guest PC 0x0c0a7f1c */
if(!s->budget--) { s->failed_pc=0x0c0a7f1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+26,2);
goto P_0c0a7f1e;
P_0c0a7f1e: /* original 670d, guest PC 0x0c0a7f1e */
if(!s->budget--) { s->failed_pc=0x0c0a7f1eu; return 0; }
r[7]=r[0]&65535u;
goto P_0c0a7f20;
P_0c0a7f20: /* original a012, guest PC 0x0c0a7f20 */
if(!s->budget--) { s->failed_pc=0x0c0a7f20u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f48;
P_0c0a7f22: /* original ee1f, guest PC 0x0c0a7f22 */
if(!s->budget--) { s->failed_pc=0x0c0a7f22u; return 0; }
r[14]=0x0000001fu;
goto P_0c0a7f24;
P_0c0a7f24: /* original 856b, guest PC 0x0c0a7f24 */
if(!s->budget--) { s->failed_pc=0x0c0a7f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+22,2);
goto P_0c0a7f26;
P_0c0a7f26: /* original 600d, guest PC 0x0c0a7f26 */
if(!s->budget--) { s->failed_pc=0x0c0a7f26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a7f28;
P_0c0a7f28: /* original 3500, guest PC 0x0c0a7f28 */
if(!s->budget--) { s->failed_pc=0x0c0a7f28u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[0])!=0);
goto P_0c0a7f2a;
P_0c0a7f2a: /* original 8910, guest PC 0x0c0a7f2a */
if(!s->budget--) { s->failed_pc=0x0c0a7f2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a7f4e; }
goto P_0c0a7f2c;
P_0c0a7f2c: /* original e334, guest PC 0x0c0a7f2c */
if(!s->budget--) { s->failed_pc=0x0c0a7f2cu; return 0; }
r[3]=0x00000034u;
goto P_0c0a7f2e;
P_0c0a7f2e: /* original 6263, guest PC 0x0c0a7f2e */
if(!s->budget--) { s->failed_pc=0x0c0a7f2eu; return 0; }
r[2]=r[6];
goto P_0c0a7f30;
P_0c0a7f30: /* original 253f, guest PC 0x0c0a7f30 */
if(!s->budget--) { s->failed_pc=0x0c0a7f30u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[5]*(int32_t)(int16_t)r[3]);
goto P_0c0a7f32;
P_0c0a7f32: /* original 721c, guest PC 0x0c0a7f32 */
if(!s->budget--) { s->failed_pc=0x0c0a7f32u; return 0; }
r[2]+=0x0000001cu;
goto P_0c0a7f34;
P_0c0a7f34: /* original e030, guest PC 0x0c0a7f34 */
if(!s->budget--) { s->failed_pc=0x0c0a7f34u; return 0; }
r[0]=0x00000030u;
goto P_0c0a7f36;
P_0c0a7f36: /* original 051a, guest PC 0x0c0a7f36 */
if(!s->budget--) { s->failed_pc=0x0c0a7f36u; return 0; }
r[5]=r[19];
goto P_0c0a7f38;
P_0c0a7f38: /* original 655f, guest PC 0x0c0a7f38 */
if(!s->budget--) { s->failed_pc=0x0c0a7f38u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c0a7f3a;
P_0c0a7f3a: /* original 352c, guest PC 0x0c0a7f3a */
if(!s->budget--) { s->failed_pc=0x0c0a7f3au; return 0; }
r[5]+=r[2];
goto P_0c0a7f3c;
P_0c0a7f3c: /* original 015d, guest PC 0x0c0a7f3c */
if(!s->budget--) { s->failed_pc=0x0c0a7f3cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0a7f3e;
P_0c0a7f3e: /* original 3140, guest PC 0x0c0a7f3e */
if(!s->budget--) { s->failed_pc=0x0c0a7f3eu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[4])!=0);
goto P_0c0a7f40;
P_0c0a7f40: /* original 8b01, guest PC 0x0c0a7f40 */
if(!s->budget--) { s->failed_pc=0x0c0a7f40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7f46; }
goto P_0c0a7f42;
P_0c0a7f42: /* original a005, guest PC 0x0c0a7f42 */
if(!s->budget--) { s->failed_pc=0x0c0a7f42u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f50;
P_0c0a7f44: /* original e001, guest PC 0x0c0a7f44 */
if(!s->budget--) { s->failed_pc=0x0c0a7f44u; return 0; }
r[0]=0x00000001u;
goto P_0c0a7f46;
P_0c0a7f46: /* original 77ff, guest PC 0x0c0a7f46 */
if(!s->budget--) { s->failed_pc=0x0c0a7f46u; return 0; }
r[7]+=0xffffffffu;
goto P_0c0a7f48;
P_0c0a7f48: /* original 6573, guest PC 0x0c0a7f48 */
if(!s->budget--) { s->failed_pc=0x0c0a7f48u; return 0; }
r[5]=r[7];
goto P_0c0a7f4a;
P_0c0a7f4a: /* original afeb, guest PC 0x0c0a7f4a */
if(!s->budget--) { s->failed_pc=0x0c0a7f4au; return 0; }
r[5]&=r[14];
goto P_0c0a7f24;
P_0c0a7f4c: /* original 25e9, guest PC 0x0c0a7f4c */
if(!s->budget--) { s->failed_pc=0x0c0a7f4cu; return 0; }
r[5]&=r[14];
goto P_0c0a7f4e;
P_0c0a7f4e: /* original e000, guest PC 0x0c0a7f4e */
if(!s->budget--) { s->failed_pc=0x0c0a7f4eu; return 0; }
r[0]=0x00000000u;
goto P_0c0a7f50;
P_0c0a7f50: /* original 4f16, guest PC 0x0c0a7f50 */
if(!s->budget--) { s->failed_pc=0x0c0a7f50u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7f52;
P_0c0a7f52: /* original 000b, guest PC 0x0c0a7f52 */
if(!s->budget--) { s->failed_pc=0x0c0a7f52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a7f54: /* original 6ef6, guest PC 0x0c0a7f54 */
if(!s->budget--) { s->failed_pc=0x0c0a7f54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7f56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7f56u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
