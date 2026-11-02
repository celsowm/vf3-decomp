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
int vf3_away_batch191_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a0d32u: goto P_0c0a0d32;
case 0x0c0a0d34u: goto P_0c0a0d34;
case 0x0c0a0d36u: goto P_0c0a0d36;
case 0x0c0a0d38u: goto P_0c0a0d38;
case 0x0c0a0d3au: goto P_0c0a0d3a;
case 0x0c0a0d3cu: goto P_0c0a0d3c;
case 0x0c0a0d3eu: goto P_0c0a0d3e;
case 0x0c0a0d40u: goto P_0c0a0d40;
case 0x0c0a0d42u: goto P_0c0a0d42;
case 0x0c0a0d44u: goto P_0c0a0d44;
case 0x0c0a0d46u: goto P_0c0a0d46;
case 0x0c0a0d48u: goto P_0c0a0d48;
case 0x0c0a0d4au: goto P_0c0a0d4a;
case 0x0c0a0d4cu: goto P_0c0a0d4c;
case 0x0c0a0d4eu: goto P_0c0a0d4e;
case 0x0c0a0d50u: goto P_0c0a0d50;
case 0x0c0a0d52u: goto P_0c0a0d52;
case 0x0c0a0d54u: goto P_0c0a0d54;
case 0x0c0a0d56u: goto P_0c0a0d56;
case 0x0c0a0d58u: goto P_0c0a0d58;
case 0x0c0a0d5au: goto P_0c0a0d5a;
case 0x0c0a0d5cu: goto P_0c0a0d5c;
case 0x0c0a0d5eu: goto P_0c0a0d5e;
case 0x0c0a0d60u: goto P_0c0a0d60;
case 0x0c0a0d62u: goto P_0c0a0d62;
case 0x0c0a0d64u: goto P_0c0a0d64;
case 0x0c0a0d66u: goto P_0c0a0d66;
case 0x0c0a0d68u: goto P_0c0a0d68;
case 0x0c0a0d6au: goto P_0c0a0d6a;
case 0x0c0a0d6cu: goto P_0c0a0d6c;
case 0x0c0a0d6eu: goto P_0c0a0d6e;
case 0x0c0a0d70u: goto P_0c0a0d70;
case 0x0c0a0d72u: goto P_0c0a0d72;
case 0x0c0a0d74u: goto P_0c0a0d74;
case 0x0c0a0da4u: goto P_0c0a0da4;
case 0x0c0a0da6u: goto P_0c0a0da6;
case 0x0c0a0da8u: goto P_0c0a0da8;
case 0x0c0a0daau: goto P_0c0a0daa;
case 0x0c0a0dacu: goto P_0c0a0dac;
case 0x0c0a0daeu: goto P_0c0a0dae;
case 0x0c0a0db0u: goto P_0c0a0db0;
case 0x0c0a0db2u: goto P_0c0a0db2;
case 0x0c0a0db4u: goto P_0c0a0db4;
case 0x0c0a0db6u: goto P_0c0a0db6;
case 0x0c0a0db8u: goto P_0c0a0db8;
case 0x0c0a0dbau: goto P_0c0a0dba;
case 0x0c0a0dbcu: goto P_0c0a0dbc;
case 0x0c0a0dbeu: goto P_0c0a0dbe;
case 0x0c0a0dc0u: goto P_0c0a0dc0;
case 0x0c0a0dc2u: goto P_0c0a0dc2;
case 0x0c0a0dc4u: goto P_0c0a0dc4;
case 0x0c0a0dc6u: goto P_0c0a0dc6;
case 0x0c0a0dc8u: goto P_0c0a0dc8;
case 0x0c0a0dcau: goto P_0c0a0dca;
case 0x0c0a0dccu: goto P_0c0a0dcc;
case 0x0c0a0dceu: goto P_0c0a0dce;
case 0x0c0a0dd0u: goto P_0c0a0dd0;
case 0x0c0a0dd2u: goto P_0c0a0dd2;
case 0x0c0a0dd4u: goto P_0c0a0dd4;
case 0x0c0a0dd6u: goto P_0c0a0dd6;
case 0x0c0a0dd8u: goto P_0c0a0dd8;
case 0x0c0a0ddau: goto P_0c0a0dda;
case 0x0c0a0ddcu: goto P_0c0a0ddc;
case 0x0c0a0ddeu: goto P_0c0a0dde;
case 0x0c0a0de0u: goto P_0c0a0de0;
case 0x0c0a0de2u: goto P_0c0a0de2;
case 0x0c0a0de4u: goto P_0c0a0de4;
case 0x0c0a0de6u: goto P_0c0a0de6;
case 0x0c0a0de8u: goto P_0c0a0de8;
case 0x0c0a0deau: goto P_0c0a0dea;
case 0x0c0a0decu: goto P_0c0a0dec;
case 0x0c0a0deeu: goto P_0c0a0dee;
case 0x0c0a0df0u: goto P_0c0a0df0;
case 0x0c0a0df2u: goto P_0c0a0df2;
case 0x0c0a0df4u: goto P_0c0a0df4;
case 0x0c0a0df6u: goto P_0c0a0df6;
case 0x0c0a0df8u: goto P_0c0a0df8;
case 0x0c0a0dfau: goto P_0c0a0dfa;
case 0x0c0a0dfcu: goto P_0c0a0dfc;
case 0x0c0a0dfeu: goto P_0c0a0dfe;
case 0x0c0a0e00u: goto P_0c0a0e00;
case 0x0c0a0e02u: goto P_0c0a0e02;
case 0x0c0a0e04u: goto P_0c0a0e04;
case 0x0c0a0e06u: goto P_0c0a0e06;
case 0x0c0a0e08u: goto P_0c0a0e08;
case 0x0c0a0e0au: goto P_0c0a0e0a;
case 0x0c0a0e0cu: goto P_0c0a0e0c;
case 0x0c0a0e0eu: goto P_0c0a0e0e;
case 0x0c0a0e10u: goto P_0c0a0e10;
case 0x0c0a0e12u: goto P_0c0a0e12;
case 0x0c0a0e14u: goto P_0c0a0e14;
case 0x0c0a0e16u: goto P_0c0a0e16;
case 0x0c0a0e18u: goto P_0c0a0e18;
case 0x0c0a0e1au: goto P_0c0a0e1a;
case 0x0c0a0e1cu: goto P_0c0a0e1c;
case 0x0c0a0e1eu: goto P_0c0a0e1e;
case 0x0c0a0e20u: goto P_0c0a0e20;
case 0x0c0a0e22u: goto P_0c0a0e22;
case 0x0c0a0e24u: goto P_0c0a0e24;
case 0x0c0a0e26u: goto P_0c0a0e26;
case 0x0c0a0e28u: goto P_0c0a0e28;
case 0x0c0a0e2au: goto P_0c0a0e2a;
case 0x0c0a0e2cu: goto P_0c0a0e2c;
case 0x0c0a0e2eu: goto P_0c0a0e2e;
case 0x0c0a0e30u: goto P_0c0a0e30;
case 0x0c0a0e32u: goto P_0c0a0e32;
case 0x0c0a0e34u: goto P_0c0a0e34;
case 0x0c0a0e36u: goto P_0c0a0e36;
case 0x0c0a0e38u: goto P_0c0a0e38;
case 0x0c0a0e3au: goto P_0c0a0e3a;
case 0x0c0a0e3cu: goto P_0c0a0e3c;
case 0x0c0a0e3eu: goto P_0c0a0e3e;
case 0x0c0a0e40u: goto P_0c0a0e40;
case 0x0c0a0e42u: goto P_0c0a0e42;
case 0x0c0a0e44u: goto P_0c0a0e44;
case 0x0c0a0e46u: goto P_0c0a0e46;
case 0x0c0a0e48u: goto P_0c0a0e48;
case 0x0c0a0e4au: goto P_0c0a0e4a;
case 0x0c0a0e4cu: goto P_0c0a0e4c;
case 0x0c0a0e4eu: goto P_0c0a0e4e;
case 0x0c0a0e50u: goto P_0c0a0e50;
case 0x0c0a0e52u: goto P_0c0a0e52;
case 0x0c0a0e54u: goto P_0c0a0e54;
case 0x0c0a0e56u: goto P_0c0a0e56;
case 0x0c0a0e58u: goto P_0c0a0e58;
case 0x0c0a0e5au: goto P_0c0a0e5a;
case 0x0c0a0e5cu: goto P_0c0a0e5c;
case 0x0c0a0e5eu: goto P_0c0a0e5e;
case 0x0c0a0e60u: goto P_0c0a0e60;
case 0x0c0a0e62u: goto P_0c0a0e62;
case 0x0c0a0e64u: goto P_0c0a0e64;
case 0x0c0a0e66u: goto P_0c0a0e66;
case 0x0c0a0e68u: goto P_0c0a0e68;
case 0x0c0a0e6au: goto P_0c0a0e6a;
case 0x0c0a0e6cu: goto P_0c0a0e6c;
case 0x0c0a0e6eu: goto P_0c0a0e6e;
case 0x0c0a0e70u: goto P_0c0a0e70;
case 0x0c0a0e72u: goto P_0c0a0e72;
case 0x0c0a0e74u: goto P_0c0a0e74;
case 0x0c0a0e76u: goto P_0c0a0e76;
case 0x0c0a0e78u: goto P_0c0a0e78;
case 0x0c0a0e7au: goto P_0c0a0e7a;
case 0x0c0a0e7cu: goto P_0c0a0e7c;
case 0x0c0a0e7eu: goto P_0c0a0e7e;
case 0x0c0a0e80u: goto P_0c0a0e80;
case 0x0c0a0e82u: goto P_0c0a0e82;
case 0x0c0a0e84u: goto P_0c0a0e84;
case 0x0c0a0e86u: goto P_0c0a0e86;
case 0x0c0a0e88u: goto P_0c0a0e88;
case 0x0c0a0e8au: goto P_0c0a0e8a;
case 0x0c0a0e8cu: goto P_0c0a0e8c;
case 0x0c0a0e8eu: goto P_0c0a0e8e;
case 0x0c0a0e90u: goto P_0c0a0e90;
case 0x0c0a0e92u: goto P_0c0a0e92;
case 0x0c0a0e94u: goto P_0c0a0e94;
case 0x0c0a0e96u: goto P_0c0a0e96;
case 0x0c0a0e98u: goto P_0c0a0e98;
case 0x0c0a0e9au: goto P_0c0a0e9a;
case 0x0c0a0e9cu: goto P_0c0a0e9c;
case 0x0c0a0e9eu: goto P_0c0a0e9e;
case 0x0c0a0ea0u: goto P_0c0a0ea0;
case 0x0c0a0ea2u: goto P_0c0a0ea2;
case 0x0c0a0ea4u: goto P_0c0a0ea4;
case 0x0c0a0ea6u: goto P_0c0a0ea6;
case 0x0c0a0ea8u: goto P_0c0a0ea8;
case 0x0c0a0eaau: goto P_0c0a0eaa;
case 0x0c0a0eacu: goto P_0c0a0eac;
case 0x0c0a0eaeu: goto P_0c0a0eae;
case 0x0c0a0eb0u: goto P_0c0a0eb0;
case 0x0c0a0eb2u: goto P_0c0a0eb2;
case 0x0c0a0eb4u: goto P_0c0a0eb4;
case 0x0c0a0eb6u: goto P_0c0a0eb6;
case 0x0c0a0eb8u: goto P_0c0a0eb8;
case 0x0c0a0ebau: goto P_0c0a0eba;
case 0x0c0a0ebcu: goto P_0c0a0ebc;
case 0x0c0a0ebeu: goto P_0c0a0ebe;
case 0x0c0a0ec0u: goto P_0c0a0ec0;
case 0x0c0a0ec2u: goto P_0c0a0ec2;
case 0x0c0a0ec4u: goto P_0c0a0ec4;
case 0x0c0a0ec6u: goto P_0c0a0ec6;
case 0x0c0a0ec8u: goto P_0c0a0ec8;
case 0x0c0a0ecau: goto P_0c0a0eca;
case 0x0c0a0eccu: goto P_0c0a0ecc;
case 0x0c0a0eceu: goto P_0c0a0ece;
case 0x0c0a0ed0u: goto P_0c0a0ed0;
case 0x0c0a0ed2u: goto P_0c0a0ed2;
case 0x0c0a0ed4u: goto P_0c0a0ed4;
case 0x0c0a0ed6u: goto P_0c0a0ed6;
case 0x0c0a0ed8u: goto P_0c0a0ed8;
case 0x0c0a0edau: goto P_0c0a0eda;
case 0x0c0a0edcu: goto P_0c0a0edc;
case 0x0c0a0edeu: goto P_0c0a0ede;
case 0x0c0a0ee0u: goto P_0c0a0ee0;
case 0x0c0a0ee2u: goto P_0c0a0ee2;
case 0x0c0a0ee4u: goto P_0c0a0ee4;
case 0x0c0a0ee6u: goto P_0c0a0ee6;
case 0x0c0a0ee8u: goto P_0c0a0ee8;
case 0x0c0a0eeau: goto P_0c0a0eea;
case 0x0c0a0eecu: goto P_0c0a0eec;
case 0x0c0a0eeeu: goto P_0c0a0eee;
case 0x0c0a0ef0u: goto P_0c0a0ef0;
case 0x0c0a0ef2u: goto P_0c0a0ef2;
case 0x0c0a0ef4u: goto P_0c0a0ef4;
case 0x0c0a0ef6u: goto P_0c0a0ef6;
case 0x0c0a0ef8u: goto P_0c0a0ef8;
case 0x0c0a0efau: goto P_0c0a0efa;
case 0x0c0a0efcu: goto P_0c0a0efc;
case 0x0c0a0efeu: goto P_0c0a0efe;
case 0x0c0a0f00u: goto P_0c0a0f00;
case 0x0c0a0f02u: goto P_0c0a0f02;
case 0x0c0a0f04u: goto P_0c0a0f04;
case 0x0c0a0f06u: goto P_0c0a0f06;
case 0x0c0a0f08u: goto P_0c0a0f08;
case 0x0c0a0f0au: goto P_0c0a0f0a;
case 0x0c0a0f0cu: goto P_0c0a0f0c;
case 0x0c0a0f0eu: goto P_0c0a0f0e;
case 0x0c0a0f10u: goto P_0c0a0f10;
case 0x0c0a0f12u: goto P_0c0a0f12;
case 0x0c0a0f14u: goto P_0c0a0f14;
case 0x0c0a0f16u: goto P_0c0a0f16;
case 0x0c0a0f18u: goto P_0c0a0f18;
case 0x0c0a0f1au: goto P_0c0a0f1a;
case 0x0c0a0f1cu: goto P_0c0a0f1c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a0d32: /* original d119, guest PC 0x0c0a0d32 */
if(!s->budget--) { s->failed_pc=0x0c0a0d32u; return 0; }
r[1]=read(ram,0x0c0a0d98u,4);
goto P_0c0a0d34;
P_0c0a0d34: /* original 7fd8, guest PC 0x0c0a0d34 */
if(!s->budget--) { s->failed_pc=0x0c0a0d34u; return 0; }
r[15]+=0xffffffd8u;
goto P_0c0a0d36;
P_0c0a0d36: /* original d317, guest PC 0x0c0a0d36 */
if(!s->budget--) { s->failed_pc=0x0c0a0d36u; return 0; }
r[3]=read(ram,0x0c0a0d94u,4);
goto P_0c0a0d38;
P_0c0a0d38: /* original 6212, guest PC 0x0c0a0d38 */
if(!s->budget--) { s->failed_pc=0x0c0a0d38u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0a0d3a;
P_0c0a0d3a: /* original d415, guest PC 0x0c0a0d3a */
if(!s->budget--) { s->failed_pc=0x0c0a0d3au; return 0; }
r[4]=read(ram,0x0c0a0d90u,4);
goto P_0c0a0d3c;
P_0c0a0d3c: /* original 2238, guest PC 0x0c0a0d3c */
if(!s->budget--) { s->failed_pc=0x0c0a0d3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a0d3e;
P_0c0a0d3e: /* original 8901, guest PC 0x0c0a0d3e */
if(!s->budget--) { s->failed_pc=0x0c0a0d3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0d44; }
goto P_0c0a0d40;
P_0c0a0d40: /* original a0eb, guest PC 0x0c0a0d40 */
if(!s->budget--) { s->failed_pc=0x0c0a0d40u; return 0; }
goto P_0c0a0f1a;
P_0c0a0d42: /* original 0009, guest PC 0x0c0a0d42 */
if(!s->budget--) { s->failed_pc=0x0c0a0d42u; return 0; }
goto P_0c0a0d44;
P_0c0a0d44: /* original 901d, guest PC 0x0c0a0d44 */
if(!s->budget--) { s->failed_pc=0x0c0a0d44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d82u,2);
goto P_0c0a0d46;
P_0c0a0d46: /* original 054d, guest PC 0x0c0a0d46 */
if(!s->budget--) { s->failed_pc=0x0c0a0d46u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0a0d48;
P_0c0a0d48: /* original 4515, guest PC 0x0c0a0d48 */
if(!s->budget--) { s->failed_pc=0x0c0a0d48u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c0a0d4a;
P_0c0a0d4a: /* original 8901, guest PC 0x0c0a0d4a */
if(!s->budget--) { s->failed_pc=0x0c0a0d4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a0d50; }
goto P_0c0a0d4c;
P_0c0a0d4c: /* original a0e5, guest PC 0x0c0a0d4c */
if(!s->budget--) { s->failed_pc=0x0c0a0d4cu; return 0; }
goto P_0c0a0f1a;
P_0c0a0d4e: /* original 0009, guest PC 0x0c0a0d4e */
if(!s->budget--) { s->failed_pc=0x0c0a0d4eu; return 0; }
goto P_0c0a0d50;
P_0c0a0d50: /* original c712, guest PC 0x0c0a0d50 */
if(!s->budget--) { s->failed_pc=0x0c0a0d50u; return 0; }
r[0]=code_base|0x000a0d9cu;
goto P_0c0a0d52;
P_0c0a0d52: /* original f408, guest PC 0x0c0a0d52 */
if(!s->budget--) { s->failed_pc=0x0c0a0d52u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a0d54;
P_0c0a0d54: /* original 75ff, guest PC 0x0c0a0d54 */
if(!s->budget--) { s->failed_pc=0x0c0a0d54u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a0d56;
P_0c0a0d56: /* original 9014, guest PC 0x0c0a0d56 */
if(!s->budget--) { s->failed_pc=0x0c0a0d56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d82u,2);
goto P_0c0a0d58;
P_0c0a0d58: /* original 455a, guest PC 0x0c0a0d58 */
if(!s->budget--) { s->failed_pc=0x0c0a0d58u; return 0; }
r[53]=r[5];
goto P_0c0a0d5a;
P_0c0a0d5a: /* original 0455, guest PC 0x0c0a0d5a */
if(!s->budget--) { s->failed_pc=0x0c0a0d5au; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0a0d5c;
P_0c0a0d5c: /* original e044, guest PC 0x0c0a0d5c */
if(!s->budget--) { s->failed_pc=0x0c0a0d5cu; return 0; }
r[0]=0x00000044u;
goto P_0c0a0d5e;
P_0c0a0d5e: /* original d510, guest PC 0x0c0a0d5e */
if(!s->budget--) { s->failed_pc=0x0c0a0d5eu; return 0; }
r[5]=read(ram,0x0c0a0da0u,4);
goto P_0c0a0d60;
P_0c0a0d60: /* original f32d, guest PC 0x0c0a0d60 */
if(!s->budget--) { s->failed_pc=0x0c0a0d60u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a0d62;
P_0c0a0d62: /* original 065e, guest PC 0x0c0a0d62 */
if(!s->budget--) { s->failed_pc=0x0c0a0d62u; return 0; }
r[6]=read(ram,r[5]+r[0],4);
goto P_0c0a0d64;
P_0c0a0d64: /* original 900e, guest PC 0x0c0a0d64 */
if(!s->budget--) { s->failed_pc=0x0c0a0d64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d84u,2);
goto P_0c0a0d66;
P_0c0a0d66: /* original 076e, guest PC 0x0c0a0d66 */
if(!s->budget--) { s->failed_pc=0x0c0a0d66u; return 0; }
r[7]=read(ram,r[6]+r[0],4);
goto P_0c0a0d68;
P_0c0a0d68: /* original 900d, guest PC 0x0c0a0d68 */
if(!s->budget--) { s->failed_pc=0x0c0a0d68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0d86u,2);
goto P_0c0a0d6a;
P_0c0a0d6a: /* original 034c, guest PC 0x0c0a0d6a */
if(!s->budget--) { s->failed_pc=0x0c0a0d6au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0a0d6c;
P_0c0a0d6c: /* original 2338, guest PC 0x0c0a0d6c */
if(!s->budget--) { s->failed_pc=0x0c0a0d6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a0d6e;
P_0c0a0d6e: /* original 8f19, guest PC 0x0c0a0d6e */
if(!s->budget--) { s->failed_pc=0x0c0a0d6eu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,3);
if(!cond) { goto P_0c0a0da4; }
goto P_0c0a0d72;
P_0c0a0d70: /* original f53c, guest PC 0x0c0a0d70 */
if(!s->budget--) { s->failed_pc=0x0c0a0d70u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0a0d72;
P_0c0a0d72: /* original a018, guest PC 0x0c0a0d72 */
if(!s->budget--) { s->failed_pc=0x0c0a0d72u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0a0da6;
P_0c0a0d74: /* original 5454, guest PC 0x0c0a0d74 */
if(!s->budget--) { s->failed_pc=0x0c0a0d74u; return 0; }
r[4]=read(ram,r[5]+16,4);
if(!vf3_matrix_family(0x0c0a0d76u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0d76u; return 0; } return 1;
P_0c0a0da4: /* original 5455, guest PC 0x0c0a0da4 */
if(!s->budget--) { s->failed_pc=0x0c0a0da4u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0a0da6;
P_0c0a0da6: /* original 92ba, guest PC 0x0c0a0da6 */
if(!s->budget--) { s->failed_pc=0x0c0a0da6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0f1eu,2);
goto P_0c0a0da8;
P_0c0a0da8: /* original e112, guest PC 0x0c0a0da8 */
if(!s->budget--) { s->failed_pc=0x0c0a0da8u; return 0; }
r[1]=0x00000012u;
goto P_0c0a0daa;
P_0c0a0daa: /* original d65e, guest PC 0x0c0a0daa */
if(!s->budget--) { s->failed_pc=0x0c0a0daau; return 0; }
r[6]=read(ram,0x0c0a0f24u,4);
goto P_0c0a0dac;
P_0c0a0dac: /* original 342c, guest PC 0x0c0a0dac */
if(!s->budget--) { s->failed_pc=0x0c0a0dacu; return 0; }
r[4]+=r[2];
goto P_0c0a0dae;
P_0c0a0dae: /* original 8468, guest PC 0x0c0a0dae */
if(!s->budget--) { s->failed_pc=0x0c0a0daeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0a0db0;
P_0c0a0db0: /* original 8801, guest PC 0x0c0a0db0 */
if(!s->budget--) { s->failed_pc=0x0c0a0db0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0a0db2;
P_0c0a0db2: /* original 8d02, guest PC 0x0c0a0db2 */
if(!s->budget--) { s->failed_pc=0x0c0a0db2u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000000cu;
if(cond) { goto P_0c0a0dba; }
goto P_0c0a0db6;
P_0c0a0db4: /* original 760c, guest PC 0x0c0a0db4 */
if(!s->budget--) { s->failed_pc=0x0c0a0db4u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0a0db6;
P_0c0a0db6: /* original a0ab, guest PC 0x0c0a0db6 */
if(!s->budget--) { s->failed_pc=0x0c0a0db6u; return 0; }
goto P_0c0a0f10;
P_0c0a0db8: /* original 0009, guest PC 0x0c0a0db8 */
if(!s->budget--) { s->failed_pc=0x0c0a0db8u; return 0; }
goto P_0c0a0dba;
P_0c0a0dba: /* original 95b1, guest PC 0x0c0a0dba */
if(!s->budget--) { s->failed_pc=0x0c0a0dbau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0f20u,2);
goto P_0c0a0dbc;
P_0c0a0dbc: /* original e010, guest PC 0x0c0a0dbc */
if(!s->budget--) { s->failed_pc=0x0c0a0dbcu; return 0; }
r[0]=0x00000010u;
goto P_0c0a0dbe;
P_0c0a0dbe: /* original 357c, guest PC 0x0c0a0dbe */
if(!s->budget--) { s->failed_pc=0x0c0a0dbeu; return 0; }
r[5]+=r[7];
goto P_0c0a0dc0;
P_0c0a0dc0: /* original f856, guest PC 0x0c0a0dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a0dc0u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c0a0dc2;
P_0c0a0dc2: /* original e014, guest PC 0x0c0a0dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a0dc2u; return 0; }
r[0]=0x00000014u;
goto P_0c0a0dc4;
P_0c0a0dc4: /* original f756, guest PC 0x0c0a0dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a0dc4u; return 0; }
vf3_matrix_load(s,ram,7,r[5]+r[0]);
goto P_0c0a0dc6;
P_0c0a0dc6: /* original e018, guest PC 0x0c0a0dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a0dc6u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0dc8;
P_0c0a0dc8: /* original f656, guest PC 0x0c0a0dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a0dc8u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c0a0dca;
P_0c0a0dca: /* original e020, guest PC 0x0c0a0dca */
if(!s->budget--) { s->failed_pc=0x0c0a0dcau; return 0; }
r[0]=0x00000020u;
goto P_0c0a0dcc;
P_0c0a0dcc: /* original f356, guest PC 0x0c0a0dcc */
if(!s->budget--) { s->failed_pc=0x0c0a0dccu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a0dce;
P_0c0a0dce: /* original e00c, guest PC 0x0c0a0dce */
if(!s->budget--) { s->failed_pc=0x0c0a0dceu; return 0; }
r[0]=0x0000000cu;
goto P_0c0a0dd0;
P_0c0a0dd0: /* original ff37, guest PC 0x0c0a0dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a0dd0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0dd2;
P_0c0a0dd2: /* original e024, guest PC 0x0c0a0dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a0dd2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a0dd4;
P_0c0a0dd4: /* original f356, guest PC 0x0c0a0dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a0dd4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a0dd6;
P_0c0a0dd6: /* original e010, guest PC 0x0c0a0dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a0dd6u; return 0; }
r[0]=0x00000010u;
goto P_0c0a0dd8;
P_0c0a0dd8: /* original ff37, guest PC 0x0c0a0dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a0dd8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0dda;
P_0c0a0dda: /* original e028, guest PC 0x0c0a0dda */
if(!s->budget--) { s->failed_pc=0x0c0a0ddau; return 0; }
r[0]=0x00000028u;
goto P_0c0a0ddc;
P_0c0a0ddc: /* original f356, guest PC 0x0c0a0ddc */
if(!s->budget--) { s->failed_pc=0x0c0a0ddcu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a0dde;
P_0c0a0dde: /* original e014, guest PC 0x0c0a0dde */
if(!s->budget--) { s->failed_pc=0x0c0a0ddeu; return 0; }
r[0]=0x00000014u;
goto P_0c0a0de0;
P_0c0a0de0: /* original ff37, guest PC 0x0c0a0de0 */
if(!s->budget--) { s->failed_pc=0x0c0a0de0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0de2;
P_0c0a0de2: /* original e030, guest PC 0x0c0a0de2 */
if(!s->budget--) { s->failed_pc=0x0c0a0de2u; return 0; }
r[0]=0x00000030u;
goto P_0c0a0de4;
P_0c0a0de4: /* original f356, guest PC 0x0c0a0de4 */
if(!s->budget--) { s->failed_pc=0x0c0a0de4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a0de6;
P_0c0a0de6: /* original e018, guest PC 0x0c0a0de6 */
if(!s->budget--) { s->failed_pc=0x0c0a0de6u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0de8;
P_0c0a0de8: /* original ff37, guest PC 0x0c0a0de8 */
if(!s->budget--) { s->failed_pc=0x0c0a0de8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0dea;
P_0c0a0dea: /* original e034, guest PC 0x0c0a0dea */
if(!s->budget--) { s->failed_pc=0x0c0a0deau; return 0; }
r[0]=0x00000034u;
goto P_0c0a0dec;
P_0c0a0dec: /* original f356, guest PC 0x0c0a0dec */
if(!s->budget--) { s->failed_pc=0x0c0a0decu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a0dee;
P_0c0a0dee: /* original e020, guest PC 0x0c0a0dee */
if(!s->budget--) { s->failed_pc=0x0c0a0deeu; return 0; }
r[0]=0x00000020u;
goto P_0c0a0df0;
P_0c0a0df0: /* original ff37, guest PC 0x0c0a0df0 */
if(!s->budget--) { s->failed_pc=0x0c0a0df0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0df2;
P_0c0a0df2: /* original e038, guest PC 0x0c0a0df2 */
if(!s->budget--) { s->failed_pc=0x0c0a0df2u; return 0; }
r[0]=0x00000038u;
goto P_0c0a0df4;
P_0c0a0df4: /* original f356, guest PC 0x0c0a0df4 */
if(!s->budget--) { s->failed_pc=0x0c0a0df4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0a0df6;
P_0c0a0df6: /* original e024, guest PC 0x0c0a0df6 */
if(!s->budget--) { s->failed_pc=0x0c0a0df6u; return 0; }
r[0]=0x00000024u;
goto P_0c0a0df8;
P_0c0a0df8: /* original ff37, guest PC 0x0c0a0df8 */
if(!s->budget--) { s->failed_pc=0x0c0a0df8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0dfa;
P_0c0a0dfa: /* original e040, guest PC 0x0c0a0dfa */
if(!s->budget--) { s->failed_pc=0x0c0a0dfau; return 0; }
r[0]=0x00000040u;
goto P_0c0a0dfc;
P_0c0a0dfc: /* original f348, guest PC 0x0c0a0dfc */
if(!s->budget--) { s->failed_pc=0x0c0a0dfcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0a0dfe;
P_0c0a0dfe: /* original fb56, guest PC 0x0c0a0dfe */
if(!s->budget--) { s->failed_pc=0x0c0a0dfeu; return 0; }
vf3_matrix_load(s,ram,11,r[5]+r[0]);
goto P_0c0a0e00;
P_0c0a0e00: /* original e044, guest PC 0x0c0a0e00 */
if(!s->budget--) { s->failed_pc=0x0c0a0e00u; return 0; }
r[0]=0x00000044u;
goto P_0c0a0e02;
P_0c0a0e02: /* original fa56, guest PC 0x0c0a0e02 */
if(!s->budget--) { s->failed_pc=0x0c0a0e02u; return 0; }
vf3_matrix_load(s,ram,10,r[5]+r[0]);
goto P_0c0a0e04;
P_0c0a0e04: /* original e048, guest PC 0x0c0a0e04 */
if(!s->budget--) { s->failed_pc=0x0c0a0e04u; return 0; }
r[0]=0x00000048u;
goto P_0c0a0e06;
P_0c0a0e06: /* original f831, guest PC 0x0c0a0e06 */
if(!s->budget--) { s->failed_pc=0x0c0a0e06u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0a0e08;
P_0c0a0e08: /* original f956, guest PC 0x0c0a0e08 */
if(!s->budget--) { s->failed_pc=0x0c0a0e08u; return 0; }
vf3_matrix_load(s,ram,9,r[5]+r[0]);
goto P_0c0a0e0a;
P_0c0a0e0a: /* original e008, guest PC 0x0c0a0e0a */
if(!s->budget--) { s->failed_pc=0x0c0a0e0au; return 0; }
r[0]=0x00000008u;
goto P_0c0a0e0c;
P_0c0a0e0c: /* original ff37, guest PC 0x0c0a0e0c */
if(!s->budget--) { s->failed_pc=0x0c0a0e0cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0e0e;
P_0c0a0e0e: /* original e004, guest PC 0x0c0a0e0e */
if(!s->budget--) { s->failed_pc=0x0c0a0e0eu; return 0; }
r[0]=0x00000004u;
goto P_0c0a0e10;
P_0c0a0e10: /* original f346, guest PC 0x0c0a0e10 */
if(!s->budget--) { s->failed_pc=0x0c0a0e10u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e12;
P_0c0a0e12: /* original e008, guest PC 0x0c0a0e12 */
if(!s->budget--) { s->failed_pc=0x0c0a0e12u; return 0; }
r[0]=0x00000008u;
goto P_0c0a0e14;
P_0c0a0e14: /* original f842, guest PC 0x0c0a0e14 */
if(!s->budget--) { s->failed_pc=0x0c0a0e14u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c0a0e16;
P_0c0a0e16: /* original f731, guest PC 0x0c0a0e16 */
if(!s->budget--) { s->failed_pc=0x0c0a0e16u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0a0e18;
P_0c0a0e18: /* original f346, guest PC 0x0c0a0e18 */
if(!s->budget--) { s->failed_pc=0x0c0a0e18u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e1a;
P_0c0a0e1a: /* original e008, guest PC 0x0c0a0e1a */
if(!s->budget--) { s->failed_pc=0x0c0a0e1au; return 0; }
r[0]=0x00000008u;
goto P_0c0a0e1c;
P_0c0a0e1c: /* original f631, guest PC 0x0c0a0e1c */
if(!s->budget--) { s->failed_pc=0x0c0a0e1cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a0e1e;
P_0c0a0e1e: /* original f3f6, guest PC 0x0c0a0e1e */
if(!s->budget--) { s->failed_pc=0x0c0a0e1eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0e20;
P_0c0a0e20: /* original f852, guest PC 0x0c0a0e20 */
if(!s->budget--) { s->failed_pc=0x0c0a0e20u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0a0e22;
P_0c0a0e22: /* original e004, guest PC 0x0c0a0e22 */
if(!s->budget--) { s->failed_pc=0x0c0a0e22u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0e24;
P_0c0a0e24: /* original f742, guest PC 0x0c0a0e24 */
if(!s->budget--) { s->failed_pc=0x0c0a0e24u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a0e26;
P_0c0a0e26: /* original f642, guest PC 0x0c0a0e26 */
if(!s->budget--) { s->failed_pc=0x0c0a0e26u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a0e28;
P_0c0a0e28: /* original f380, guest PC 0x0c0a0e28 */
if(!s->budget--) { s->failed_pc=0x0c0a0e28u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'+');
goto P_0c0a0e2a;
P_0c0a0e2a: /* original f752, guest PC 0x0c0a0e2a */
if(!s->budget--) { s->failed_pc=0x0c0a0e2au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a0e2c;
P_0c0a0e2c: /* original f652, guest PC 0x0c0a0e2c */
if(!s->budget--) { s->failed_pc=0x0c0a0e2cu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a0e2e;
P_0c0a0e2e: /* original f43a, guest PC 0x0c0a0e2e */
if(!s->budget--) { s->failed_pc=0x0c0a0e2eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c0a0e30;
P_0c0a0e30: /* original f346, guest PC 0x0c0a0e30 */
if(!s->budget--) { s->failed_pc=0x0c0a0e30u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e32;
P_0c0a0e32: /* original f370, guest PC 0x0c0a0e32 */
if(!s->budget--) { s->failed_pc=0x0c0a0e32u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0a0e34;
P_0c0a0e34: /* original f437, guest PC 0x0c0a0e34 */
if(!s->budget--) { s->failed_pc=0x0c0a0e34u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0e36;
P_0c0a0e36: /* original e008, guest PC 0x0c0a0e36 */
if(!s->budget--) { s->failed_pc=0x0c0a0e36u; return 0; }
r[0]=0x00000008u;
goto P_0c0a0e38;
P_0c0a0e38: /* original f346, guest PC 0x0c0a0e38 */
if(!s->budget--) { s->failed_pc=0x0c0a0e38u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e3a;
P_0c0a0e3a: /* original f360, guest PC 0x0c0a0e3a */
if(!s->budget--) { s->failed_pc=0x0c0a0e3au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c0a0e3c;
P_0c0a0e3c: /* original f437, guest PC 0x0c0a0e3c */
if(!s->budget--) { s->failed_pc=0x0c0a0e3cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0e3e;
P_0c0a0e3e: /* original e010, guest PC 0x0c0a0e3e */
if(!s->budget--) { s->failed_pc=0x0c0a0e3eu; return 0; }
r[0]=0x00000010u;
goto P_0c0a0e40;
P_0c0a0e40: /* original f346, guest PC 0x0c0a0e40 */
if(!s->budget--) { s->failed_pc=0x0c0a0e40u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e42;
P_0c0a0e42: /* original e01c, guest PC 0x0c0a0e42 */
if(!s->budget--) { s->failed_pc=0x0c0a0e42u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0e44;
P_0c0a0e44: /* original ff37, guest PC 0x0c0a0e44 */
if(!s->budget--) { s->failed_pc=0x0c0a0e44u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0e46;
P_0c0a0e46: /* original e00c, guest PC 0x0c0a0e46 */
if(!s->budget--) { s->failed_pc=0x0c0a0e46u; return 0; }
r[0]=0x0000000cu;
goto P_0c0a0e48;
P_0c0a0e48: /* original f7f6, guest PC 0x0c0a0e48 */
if(!s->budget--) { s->failed_pc=0x0c0a0e48u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0a0e4a;
P_0c0a0e4a: /* original e014, guest PC 0x0c0a0e4a */
if(!s->budget--) { s->failed_pc=0x0c0a0e4au; return 0; }
r[0]=0x00000014u;
goto P_0c0a0e4c;
P_0c0a0e4c: /* original f731, guest PC 0x0c0a0e4c */
if(!s->budget--) { s->failed_pc=0x0c0a0e4cu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0a0e4e;
P_0c0a0e4e: /* original f346, guest PC 0x0c0a0e4e */
if(!s->budget--) { s->failed_pc=0x0c0a0e4eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e50;
P_0c0a0e50: /* original e010, guest PC 0x0c0a0e50 */
if(!s->budget--) { s->failed_pc=0x0c0a0e50u; return 0; }
r[0]=0x00000010u;
goto P_0c0a0e52;
P_0c0a0e52: /* original f6f6, guest PC 0x0c0a0e52 */
if(!s->budget--) { s->failed_pc=0x0c0a0e52u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a0e54;
P_0c0a0e54: /* original e018, guest PC 0x0c0a0e54 */
if(!s->budget--) { s->failed_pc=0x0c0a0e54u; return 0; }
r[0]=0x00000018u;
goto P_0c0a0e56;
P_0c0a0e56: /* original f631, guest PC 0x0c0a0e56 */
if(!s->budget--) { s->failed_pc=0x0c0a0e56u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a0e58;
P_0c0a0e58: /* original f346, guest PC 0x0c0a0e58 */
if(!s->budget--) { s->failed_pc=0x0c0a0e58u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e5a;
P_0c0a0e5a: /* original f742, guest PC 0x0c0a0e5a */
if(!s->budget--) { s->failed_pc=0x0c0a0e5au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a0e5c;
P_0c0a0e5c: /* original e014, guest PC 0x0c0a0e5c */
if(!s->budget--) { s->failed_pc=0x0c0a0e5cu; return 0; }
r[0]=0x00000014u;
goto P_0c0a0e5e;
P_0c0a0e5e: /* original f8f6, guest PC 0x0c0a0e5e */
if(!s->budget--) { s->failed_pc=0x0c0a0e5eu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0a0e60;
P_0c0a0e60: /* original e01c, guest PC 0x0c0a0e60 */
if(!s->budget--) { s->failed_pc=0x0c0a0e60u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a0e62;
P_0c0a0e62: /* original f831, guest PC 0x0c0a0e62 */
if(!s->budget--) { s->failed_pc=0x0c0a0e62u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0a0e64;
P_0c0a0e64: /* original f3f6, guest PC 0x0c0a0e64 */
if(!s->budget--) { s->failed_pc=0x0c0a0e64u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0e66;
P_0c0a0e66: /* original f752, guest PC 0x0c0a0e66 */
if(!s->budget--) { s->failed_pc=0x0c0a0e66u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a0e68;
P_0c0a0e68: /* original e010, guest PC 0x0c0a0e68 */
if(!s->budget--) { s->failed_pc=0x0c0a0e68u; return 0; }
r[0]=0x00000010u;
goto P_0c0a0e6a;
P_0c0a0e6a: /* original f642, guest PC 0x0c0a0e6a */
if(!s->budget--) { s->failed_pc=0x0c0a0e6au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a0e6c;
P_0c0a0e6c: /* original f842, guest PC 0x0c0a0e6c */
if(!s->budget--) { s->failed_pc=0x0c0a0e6cu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c0a0e6e;
P_0c0a0e6e: /* original f370, guest PC 0x0c0a0e6e */
if(!s->budget--) { s->failed_pc=0x0c0a0e6eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0a0e70;
P_0c0a0e70: /* original f652, guest PC 0x0c0a0e70 */
if(!s->budget--) { s->failed_pc=0x0c0a0e70u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a0e72;
P_0c0a0e72: /* original f852, guest PC 0x0c0a0e72 */
if(!s->budget--) { s->failed_pc=0x0c0a0e72u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0a0e74;
P_0c0a0e74: /* original f437, guest PC 0x0c0a0e74 */
if(!s->budget--) { s->failed_pc=0x0c0a0e74u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0e76;
P_0c0a0e76: /* original e014, guest PC 0x0c0a0e76 */
if(!s->budget--) { s->failed_pc=0x0c0a0e76u; return 0; }
r[0]=0x00000014u;
goto P_0c0a0e78;
P_0c0a0e78: /* original f346, guest PC 0x0c0a0e78 */
if(!s->budget--) { s->failed_pc=0x0c0a0e78u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e7a;
P_0c0a0e7a: /* original f360, guest PC 0x0c0a0e7a */
if(!s->budget--) { s->failed_pc=0x0c0a0e7au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c0a0e7c;
P_0c0a0e7c: /* original f437, guest PC 0x0c0a0e7c */
if(!s->budget--) { s->failed_pc=0x0c0a0e7cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0e7e;
P_0c0a0e7e: /* original e018, guest PC 0x0c0a0e7e */
if(!s->budget--) { s->failed_pc=0x0c0a0e7eu; return 0; }
r[0]=0x00000018u;
goto P_0c0a0e80;
P_0c0a0e80: /* original f346, guest PC 0x0c0a0e80 */
if(!s->budget--) { s->failed_pc=0x0c0a0e80u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e82;
P_0c0a0e82: /* original f380, guest PC 0x0c0a0e82 */
if(!s->budget--) { s->failed_pc=0x0c0a0e82u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'+');
goto P_0c0a0e84;
P_0c0a0e84: /* original f437, guest PC 0x0c0a0e84 */
if(!s->budget--) { s->failed_pc=0x0c0a0e84u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0e86;
P_0c0a0e86: /* original e020, guest PC 0x0c0a0e86 */
if(!s->budget--) { s->failed_pc=0x0c0a0e86u; return 0; }
r[0]=0x00000020u;
goto P_0c0a0e88;
P_0c0a0e88: /* original f346, guest PC 0x0c0a0e88 */
if(!s->budget--) { s->failed_pc=0x0c0a0e88u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e8a;
P_0c0a0e8a: /* original e004, guest PC 0x0c0a0e8a */
if(!s->budget--) { s->failed_pc=0x0c0a0e8au; return 0; }
r[0]=0x00000004u;
goto P_0c0a0e8c;
P_0c0a0e8c: /* original ff37, guest PC 0x0c0a0e8c */
if(!s->budget--) { s->failed_pc=0x0c0a0e8cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0a0e8e;
P_0c0a0e8e: /* original e018, guest PC 0x0c0a0e8e */
if(!s->budget--) { s->failed_pc=0x0c0a0e8eu; return 0; }
r[0]=0x00000018u;
goto P_0c0a0e90;
P_0c0a0e90: /* original f7f6, guest PC 0x0c0a0e90 */
if(!s->budget--) { s->failed_pc=0x0c0a0e90u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0a0e92;
P_0c0a0e92: /* original e024, guest PC 0x0c0a0e92 */
if(!s->budget--) { s->failed_pc=0x0c0a0e92u; return 0; }
r[0]=0x00000024u;
goto P_0c0a0e94;
P_0c0a0e94: /* original f731, guest PC 0x0c0a0e94 */
if(!s->budget--) { s->failed_pc=0x0c0a0e94u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0a0e96;
P_0c0a0e96: /* original f346, guest PC 0x0c0a0e96 */
if(!s->budget--) { s->failed_pc=0x0c0a0e96u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0e98;
P_0c0a0e98: /* original e020, guest PC 0x0c0a0e98 */
if(!s->budget--) { s->failed_pc=0x0c0a0e98u; return 0; }
r[0]=0x00000020u;
goto P_0c0a0e9a;
P_0c0a0e9a: /* original f6f6, guest PC 0x0c0a0e9a */
if(!s->budget--) { s->failed_pc=0x0c0a0e9au; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0a0e9c;
P_0c0a0e9c: /* original e028, guest PC 0x0c0a0e9c */
if(!s->budget--) { s->failed_pc=0x0c0a0e9cu; return 0; }
r[0]=0x00000028u;
goto P_0c0a0e9e;
P_0c0a0e9e: /* original f631, guest PC 0x0c0a0e9e */
if(!s->budget--) { s->failed_pc=0x0c0a0e9eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a0ea0;
P_0c0a0ea0: /* original f346, guest PC 0x0c0a0ea0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ea0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0ea2;
P_0c0a0ea2: /* original e024, guest PC 0x0c0a0ea2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ea2u; return 0; }
r[0]=0x00000024u;
goto P_0c0a0ea4;
P_0c0a0ea4: /* original f742, guest PC 0x0c0a0ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ea4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a0ea6;
P_0c0a0ea6: /* original f8f6, guest PC 0x0c0a0ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ea6u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0a0ea8;
P_0c0a0ea8: /* original e004, guest PC 0x0c0a0ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ea8u; return 0; }
r[0]=0x00000004u;
goto P_0c0a0eaa;
P_0c0a0eaa: /* original f831, guest PC 0x0c0a0eaa */
if(!s->budget--) { s->failed_pc=0x0c0a0eaau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0a0eac;
P_0c0a0eac: /* original f3f6, guest PC 0x0c0a0eac */
if(!s->budget--) { s->failed_pc=0x0c0a0eacu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0a0eae;
P_0c0a0eae: /* original f752, guest PC 0x0c0a0eae */
if(!s->budget--) { s->failed_pc=0x0c0a0eaeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a0eb0;
P_0c0a0eb0: /* original f642, guest PC 0x0c0a0eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a0eb0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a0eb2;
P_0c0a0eb2: /* original f842, guest PC 0x0c0a0eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a0eb2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c0a0eb4;
P_0c0a0eb4: /* original f370, guest PC 0x0c0a0eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a0eb4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0a0eb6;
P_0c0a0eb6: /* original f652, guest PC 0x0c0a0eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a0eb6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a0eb8;
P_0c0a0eb8: /* original f852, guest PC 0x0c0a0eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a0eb8u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0a0eba;
P_0c0a0eba: /* original e020, guest PC 0x0c0a0eba */
if(!s->budget--) { s->failed_pc=0x0c0a0ebau; return 0; }
r[0]=0x00000020u;
goto P_0c0a0ebc;
P_0c0a0ebc: /* original f437, guest PC 0x0c0a0ebc */
if(!s->budget--) { s->failed_pc=0x0c0a0ebcu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0ebe;
P_0c0a0ebe: /* original e024, guest PC 0x0c0a0ebe */
if(!s->budget--) { s->failed_pc=0x0c0a0ebeu; return 0; }
r[0]=0x00000024u;
goto P_0c0a0ec0;
P_0c0a0ec0: /* original f346, guest PC 0x0c0a0ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ec0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0ec2;
P_0c0a0ec2: /* original f360, guest PC 0x0c0a0ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ec2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c0a0ec4;
P_0c0a0ec4: /* original f437, guest PC 0x0c0a0ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ec4u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0ec6;
P_0c0a0ec6: /* original e028, guest PC 0x0c0a0ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ec6u; return 0; }
r[0]=0x00000028u;
goto P_0c0a0ec8;
P_0c0a0ec8: /* original f346, guest PC 0x0c0a0ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ec8u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0eca;
P_0c0a0eca: /* original f380, guest PC 0x0c0a0eca */
if(!s->budget--) { s->failed_pc=0x0c0a0ecau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'+');
goto P_0c0a0ecc;
P_0c0a0ecc: /* original f437, guest PC 0x0c0a0ecc */
if(!s->budget--) { s->failed_pc=0x0c0a0eccu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0ece;
P_0c0a0ece: /* original e030, guest PC 0x0c0a0ece */
if(!s->budget--) { s->failed_pc=0x0c0a0eceu; return 0; }
r[0]=0x00000030u;
goto P_0c0a0ed0;
P_0c0a0ed0: /* original f346, guest PC 0x0c0a0ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ed0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0ed2;
P_0c0a0ed2: /* original e034, guest PC 0x0c0a0ed2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ed2u; return 0; }
r[0]=0x00000034u;
goto P_0c0a0ed4;
P_0c0a0ed4: /* original ff3a, guest PC 0x0c0a0ed4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ed4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0a0ed6;
P_0c0a0ed6: /* original f6bc, guest PC 0x0c0a0ed6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ed6u; return 0; }
vf3_matrix_move(s,6,11);
goto P_0c0a0ed8;
P_0c0a0ed8: /* original f631, guest PC 0x0c0a0ed8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ed8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0a0eda;
P_0c0a0eda: /* original f346, guest PC 0x0c0a0eda */
if(!s->budget--) { s->failed_pc=0x0c0a0edau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0edc;
P_0c0a0edc: /* original e038, guest PC 0x0c0a0edc */
if(!s->budget--) { s->failed_pc=0x0c0a0edcu; return 0; }
r[0]=0x00000038u;
goto P_0c0a0ede;
P_0c0a0ede: /* original f8ac, guest PC 0x0c0a0ede */
if(!s->budget--) { s->failed_pc=0x0c0a0edeu; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c0a0ee0;
P_0c0a0ee0: /* original f831, guest PC 0x0c0a0ee0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ee0u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c0a0ee2;
P_0c0a0ee2: /* original f346, guest PC 0x0c0a0ee2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ee2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0ee4;
P_0c0a0ee4: /* original f79c, guest PC 0x0c0a0ee4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ee4u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c0a0ee6;
P_0c0a0ee6: /* original f642, guest PC 0x0c0a0ee6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ee6u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0a0ee8;
P_0c0a0ee8: /* original f731, guest PC 0x0c0a0ee8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ee8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c0a0eea;
P_0c0a0eea: /* original f3f8, guest PC 0x0c0a0eea */
if(!s->budget--) { s->failed_pc=0x0c0a0eeau; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0a0eec;
P_0c0a0eec: /* original e030, guest PC 0x0c0a0eec */
if(!s->budget--) { s->failed_pc=0x0c0a0eecu; return 0; }
r[0]=0x00000030u;
goto P_0c0a0eee;
P_0c0a0eee: /* original f842, guest PC 0x0c0a0eee */
if(!s->budget--) { s->failed_pc=0x0c0a0eeeu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[4],r[18],'*');
goto P_0c0a0ef0;
P_0c0a0ef0: /* original f652, guest PC 0x0c0a0ef0 */
if(!s->budget--) { s->failed_pc=0x0c0a0ef0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c0a0ef2;
P_0c0a0ef2: /* original f742, guest PC 0x0c0a0ef2 */
if(!s->budget--) { s->failed_pc=0x0c0a0ef2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0a0ef4;
P_0c0a0ef4: /* original f852, guest PC 0x0c0a0ef4 */
if(!s->budget--) { s->failed_pc=0x0c0a0ef4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0a0ef6;
P_0c0a0ef6: /* original f360, guest PC 0x0c0a0ef6 */
if(!s->budget--) { s->failed_pc=0x0c0a0ef6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c0a0ef8;
P_0c0a0ef8: /* original f752, guest PC 0x0c0a0ef8 */
if(!s->budget--) { s->failed_pc=0x0c0a0ef8u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'*');
goto P_0c0a0efa;
P_0c0a0efa: /* original f437, guest PC 0x0c0a0efa */
if(!s->budget--) { s->failed_pc=0x0c0a0efau; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0efc;
P_0c0a0efc: /* original e034, guest PC 0x0c0a0efc */
if(!s->budget--) { s->failed_pc=0x0c0a0efcu; return 0; }
r[0]=0x00000034u;
goto P_0c0a0efe;
P_0c0a0efe: /* original f346, guest PC 0x0c0a0efe */
if(!s->budget--) { s->failed_pc=0x0c0a0efeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0f00;
P_0c0a0f00: /* original f380, guest PC 0x0c0a0f00 */
if(!s->budget--) { s->failed_pc=0x0c0a0f00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'+');
goto P_0c0a0f02;
P_0c0a0f02: /* original f437, guest PC 0x0c0a0f02 */
if(!s->budget--) { s->failed_pc=0x0c0a0f02u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0f04;
P_0c0a0f04: /* original e038, guest PC 0x0c0a0f04 */
if(!s->budget--) { s->failed_pc=0x0c0a0f04u; return 0; }
r[0]=0x00000038u;
goto P_0c0a0f06;
P_0c0a0f06: /* original f346, guest PC 0x0c0a0f06 */
if(!s->budget--) { s->failed_pc=0x0c0a0f06u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0a0f08;
P_0c0a0f08: /* original f370, guest PC 0x0c0a0f08 */
if(!s->budget--) { s->failed_pc=0x0c0a0f08u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'+');
goto P_0c0a0f0a;
P_0c0a0f0a: /* original f437, guest PC 0x0c0a0f0a */
if(!s->budget--) { s->failed_pc=0x0c0a0f0au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0a0f0c;
P_0c0a0f0c: /* original 9309, guest PC 0x0c0a0f0c */
if(!s->budget--) { s->failed_pc=0x0c0a0f0cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a0f22u,2);
goto P_0c0a0f0e;
P_0c0a0f0e: /* original 373c, guest PC 0x0c0a0f0e */
if(!s->budget--) { s->failed_pc=0x0c0a0f0eu; return 0; }
r[7]+=r[3];
goto P_0c0a0f10;
P_0c0a0f10: /* original 4110, guest PC 0x0c0a0f10 */
if(!s->budget--) { s->failed_pc=0x0c0a0f10u; return 0; }
--r[1];
r[17]=(r[17]&~1u)|((r[1]==0)!=0);
goto P_0c0a0f12;
P_0c0a0f12: /* original 8d02, guest PC 0x0c0a0f12 */
if(!s->budget--) { s->failed_pc=0x0c0a0f12u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000040u;
if(cond) { goto P_0c0a0f1a; }
goto P_0c0a0f16;
P_0c0a0f14: /* original 7440, guest PC 0x0c0a0f14 */
if(!s->budget--) { s->failed_pc=0x0c0a0f14u; return 0; }
r[4]+=0x00000040u;
goto P_0c0a0f16;
P_0c0a0f16: /* original af4a, guest PC 0x0c0a0f16 */
if(!s->budget--) { s->failed_pc=0x0c0a0f16u; return 0; }
goto P_0c0a0dae;
P_0c0a0f18: /* original 0009, guest PC 0x0c0a0f18 */
if(!s->budget--) { s->failed_pc=0x0c0a0f18u; return 0; }
goto P_0c0a0f1a;
P_0c0a0f1a: /* original 000b, guest PC 0x0c0a0f1a */
if(!s->budget--) { s->failed_pc=0x0c0a0f1au; return 0; }
target=r[16];
r[15]+=0x00000028u;
s->pc=target; return ram->oob==0;
P_0c0a0f1c: /* original 7f28, guest PC 0x0c0a0f1c */
if(!s->budget--) { s->failed_pc=0x0c0a0f1cu; return 0; }
r[15]+=0x00000028u;
if(!vf3_matrix_family(0x0c0a0f1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a0f1eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
