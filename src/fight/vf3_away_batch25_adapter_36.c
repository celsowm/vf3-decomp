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
int vf3_away_batch25_adapter_36(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c4d14u: goto P_0c0c4d14;
case 0x0c0c4d16u: goto P_0c0c4d16;
case 0x0c0c4d18u: goto P_0c0c4d18;
case 0x0c0c4d1au: goto P_0c0c4d1a;
case 0x0c0c4d1cu: goto P_0c0c4d1c;
case 0x0c0c4d1eu: goto P_0c0c4d1e;
case 0x0c0c4d20u: goto P_0c0c4d20;
case 0x0c0c4d22u: goto P_0c0c4d22;
case 0x0c0c4d24u: goto P_0c0c4d24;
case 0x0c0c4d26u: goto P_0c0c4d26;
case 0x0c0c4d28u: goto P_0c0c4d28;
case 0x0c0c4d2au: goto P_0c0c4d2a;
case 0x0c0c4d2cu: goto P_0c0c4d2c;
case 0x0c0c4d2eu: goto P_0c0c4d2e;
case 0x0c0c4d30u: goto P_0c0c4d30;
case 0x0c0c4d32u: goto P_0c0c4d32;
case 0x0c0c4d34u: goto P_0c0c4d34;
case 0x0c0c4d36u: goto P_0c0c4d36;
case 0x0c0c4d38u: goto P_0c0c4d38;
case 0x0c0c4d3au: goto P_0c0c4d3a;
case 0x0c0c4d3cu: goto P_0c0c4d3c;
case 0x0c0c4d3eu: goto P_0c0c4d3e;
case 0x0c0c4d40u: goto P_0c0c4d40;
case 0x0c0c4d42u: goto P_0c0c4d42;
case 0x0c0c4d44u: goto P_0c0c4d44;
case 0x0c0c4d46u: goto P_0c0c4d46;
case 0x0c0c4d48u: goto P_0c0c4d48;
case 0x0c0c4d4au: goto P_0c0c4d4a;
case 0x0c0c4d4cu: goto P_0c0c4d4c;
case 0x0c0c4d4eu: goto P_0c0c4d4e;
case 0x0c0c4d50u: goto P_0c0c4d50;
case 0x0c0c4d52u: goto P_0c0c4d52;
case 0x0c0c4d54u: goto P_0c0c4d54;
case 0x0c0c4d56u: goto P_0c0c4d56;
case 0x0c0c4d58u: goto P_0c0c4d58;
case 0x0c0c4d5au: goto P_0c0c4d5a;
case 0x0c0c4d5cu: goto P_0c0c4d5c;
case 0x0c0c4d5eu: goto P_0c0c4d5e;
case 0x0c0c4d60u: goto P_0c0c4d60;
case 0x0c0c4d62u: goto P_0c0c4d62;
case 0x0c0c4d64u: goto P_0c0c4d64;
case 0x0c0c4d66u: goto P_0c0c4d66;
case 0x0c0c4d68u: goto P_0c0c4d68;
case 0x0c0c4d6au: goto P_0c0c4d6a;
case 0x0c0c4d6cu: goto P_0c0c4d6c;
case 0x0c0c4d6eu: goto P_0c0c4d6e;
case 0x0c0c4d70u: goto P_0c0c4d70;
case 0x0c0c4d72u: goto P_0c0c4d72;
case 0x0c0c4d74u: goto P_0c0c4d74;
case 0x0c0c4d76u: goto P_0c0c4d76;
case 0x0c0c4d78u: goto P_0c0c4d78;
case 0x0c0c4d7au: goto P_0c0c4d7a;
case 0x0c0c4d7cu: goto P_0c0c4d7c;
case 0x0c0c4d7eu: goto P_0c0c4d7e;
case 0x0c0c4d80u: goto P_0c0c4d80;
case 0x0c0c4d82u: goto P_0c0c4d82;
case 0x0c0c4d84u: goto P_0c0c4d84;
case 0x0c0c4d86u: goto P_0c0c4d86;
case 0x0c0c4d88u: goto P_0c0c4d88;
case 0x0c0c4d8au: goto P_0c0c4d8a;
case 0x0c0c4d8cu: goto P_0c0c4d8c;
case 0x0c0c4d8eu: goto P_0c0c4d8e;
case 0x0c0c4d90u: goto P_0c0c4d90;
case 0x0c0c4d92u: goto P_0c0c4d92;
case 0x0c0c4d94u: goto P_0c0c4d94;
case 0x0c0c4d96u: goto P_0c0c4d96;
case 0x0c0c4d98u: goto P_0c0c4d98;
case 0x0c0c4d9au: goto P_0c0c4d9a;
case 0x0c0c4d9cu: goto P_0c0c4d9c;
case 0x0c0c4d9eu: goto P_0c0c4d9e;
case 0x0c0c4da0u: goto P_0c0c4da0;
case 0x0c0c4da2u: goto P_0c0c4da2;
case 0x0c0c4da4u: goto P_0c0c4da4;
case 0x0c0c4da6u: goto P_0c0c4da6;
case 0x0c0c4da8u: goto P_0c0c4da8;
case 0x0c0c4daau: goto P_0c0c4daa;
case 0x0c0c4dacu: goto P_0c0c4dac;
case 0x0c0c4daeu: goto P_0c0c4dae;
case 0x0c0c4db0u: goto P_0c0c4db0;
case 0x0c0c4db2u: goto P_0c0c4db2;
case 0x0c0c4db4u: goto P_0c0c4db4;
case 0x0c0c4db6u: goto P_0c0c4db6;
case 0x0c0c4db8u: goto P_0c0c4db8;
case 0x0c0c4dbau: goto P_0c0c4dba;
case 0x0c0c4dbcu: goto P_0c0c4dbc;
case 0x0c0c4dbeu: goto P_0c0c4dbe;
case 0x0c0c4dc0u: goto P_0c0c4dc0;
case 0x0c0c4dc2u: goto P_0c0c4dc2;
case 0x0c0c4dc4u: goto P_0c0c4dc4;
case 0x0c0c4dc6u: goto P_0c0c4dc6;
case 0x0c0c4dc8u: goto P_0c0c4dc8;
case 0x0c0c4dcau: goto P_0c0c4dca;
case 0x0c0c4dccu: goto P_0c0c4dcc;
case 0x0c0c4dceu: goto P_0c0c4dce;
case 0x0c0c4dd0u: goto P_0c0c4dd0;
case 0x0c0c4dd2u: goto P_0c0c4dd2;
case 0x0c0c4dd4u: goto P_0c0c4dd4;
case 0x0c0c4dd6u: goto P_0c0c4dd6;
case 0x0c0c4dd8u: goto P_0c0c4dd8;
case 0x0c0c4ddau: goto P_0c0c4dda;
case 0x0c0c4ddcu: goto P_0c0c4ddc;
case 0x0c0c4ddeu: goto P_0c0c4dde;
case 0x0c0c4de0u: goto P_0c0c4de0;
case 0x0c0c4de2u: goto P_0c0c4de2;
case 0x0c0c4de4u: goto P_0c0c4de4;
case 0x0c0c4de6u: goto P_0c0c4de6;
case 0x0c0c4de8u: goto P_0c0c4de8;
case 0x0c0c4deau: goto P_0c0c4dea;
case 0x0c0c4decu: goto P_0c0c4dec;
case 0x0c0c4deeu: goto P_0c0c4dee;
case 0x0c0c4df0u: goto P_0c0c4df0;
case 0x0c0c4df2u: goto P_0c0c4df2;
case 0x0c0c4df4u: goto P_0c0c4df4;
case 0x0c0c4df6u: goto P_0c0c4df6;
case 0x0c0c4df8u: goto P_0c0c4df8;
case 0x0c0c4dfau: goto P_0c0c4dfa;
case 0x0c0c4dfcu: goto P_0c0c4dfc;
case 0x0c0c4dfeu: goto P_0c0c4dfe;
case 0x0c0c4e00u: goto P_0c0c4e00;
case 0x0c0c4e02u: goto P_0c0c4e02;
case 0x0c0c4e04u: goto P_0c0c4e04;
case 0x0c0c4e06u: goto P_0c0c4e06;
case 0x0c0c4e08u: goto P_0c0c4e08;
case 0x0c0c4e0au: goto P_0c0c4e0a;
case 0x0c0c4e0cu: goto P_0c0c4e0c;
case 0x0c0c4e0eu: goto P_0c0c4e0e;
case 0x0c0c4e10u: goto P_0c0c4e10;
case 0x0c0c4e12u: goto P_0c0c4e12;
case 0x0c0c4e14u: goto P_0c0c4e14;
case 0x0c0c4e16u: goto P_0c0c4e16;
case 0x0c0c4e34u: goto P_0c0c4e34;
case 0x0c0c4e36u: goto P_0c0c4e36;
case 0x0c0c4e38u: goto P_0c0c4e38;
case 0x0c0c4e3au: goto P_0c0c4e3a;
case 0x0c0c4e3cu: goto P_0c0c4e3c;
case 0x0c0c4e3eu: goto P_0c0c4e3e;
case 0x0c0c4e40u: goto P_0c0c4e40;
case 0x0c0c4e42u: goto P_0c0c4e42;
case 0x0c0c4e44u: goto P_0c0c4e44;
case 0x0c0c4e46u: goto P_0c0c4e46;
case 0x0c0c4e48u: goto P_0c0c4e48;
case 0x0c0c4e4au: goto P_0c0c4e4a;
case 0x0c0c4e4cu: goto P_0c0c4e4c;
case 0x0c0c4e4eu: goto P_0c0c4e4e;
case 0x0c0c4e50u: goto P_0c0c4e50;
case 0x0c0c4e52u: goto P_0c0c4e52;
case 0x0c0c4e54u: goto P_0c0c4e54;
case 0x0c0c4e56u: goto P_0c0c4e56;
case 0x0c0c4e58u: goto P_0c0c4e58;
case 0x0c0c4e5au: goto P_0c0c4e5a;
case 0x0c0c4e5cu: goto P_0c0c4e5c;
case 0x0c0c4e5eu: goto P_0c0c4e5e;
case 0x0c0c4e60u: goto P_0c0c4e60;
case 0x0c0c4e62u: goto P_0c0c4e62;
case 0x0c0c4e64u: goto P_0c0c4e64;
case 0x0c0c4e66u: goto P_0c0c4e66;
case 0x0c0c4e68u: goto P_0c0c4e68;
case 0x0c0c4e6au: goto P_0c0c4e6a;
case 0x0c0c4e6cu: goto P_0c0c4e6c;
case 0x0c0c4e6eu: goto P_0c0c4e6e;
case 0x0c0c4e70u: goto P_0c0c4e70;
case 0x0c0c4e72u: goto P_0c0c4e72;
case 0x0c0c4e74u: goto P_0c0c4e74;
case 0x0c0c4e76u: goto P_0c0c4e76;
case 0x0c0c4e78u: goto P_0c0c4e78;
case 0x0c0c4e7au: goto P_0c0c4e7a;
case 0x0c0c4e7cu: goto P_0c0c4e7c;
case 0x0c0c4e7eu: goto P_0c0c4e7e;
case 0x0c0c4e80u: goto P_0c0c4e80;
case 0x0c0c4e82u: goto P_0c0c4e82;
case 0x0c0c4e84u: goto P_0c0c4e84;
case 0x0c0c4e86u: goto P_0c0c4e86;
case 0x0c0c4e88u: goto P_0c0c4e88;
case 0x0c0c4e8au: goto P_0c0c4e8a;
case 0x0c0c4e8cu: goto P_0c0c4e8c;
case 0x0c0c4e8eu: goto P_0c0c4e8e;
case 0x0c0c4e90u: goto P_0c0c4e90;
case 0x0c0c4e92u: goto P_0c0c4e92;
case 0x0c0c4e94u: goto P_0c0c4e94;
case 0x0c0c4e96u: goto P_0c0c4e96;
case 0x0c0c4e98u: goto P_0c0c4e98;
case 0x0c0c4e9au: goto P_0c0c4e9a;
case 0x0c0c4e9cu: goto P_0c0c4e9c;
case 0x0c0c4e9eu: goto P_0c0c4e9e;
case 0x0c0c4ea0u: goto P_0c0c4ea0;
case 0x0c0c4ea2u: goto P_0c0c4ea2;
case 0x0c0c4ea4u: goto P_0c0c4ea4;
case 0x0c0c4ea6u: goto P_0c0c4ea6;
case 0x0c0c4ea8u: goto P_0c0c4ea8;
case 0x0c0c4eaau: goto P_0c0c4eaa;
case 0x0c0c4eacu: goto P_0c0c4eac;
case 0x0c0c4eaeu: goto P_0c0c4eae;
case 0x0c0c4eb0u: goto P_0c0c4eb0;
case 0x0c0c4eb2u: goto P_0c0c4eb2;
case 0x0c0c4eb4u: goto P_0c0c4eb4;
case 0x0c0c4eb6u: goto P_0c0c4eb6;
case 0x0c0c4eb8u: goto P_0c0c4eb8;
case 0x0c0c4ebau: goto P_0c0c4eba;
case 0x0c0c4ebcu: goto P_0c0c4ebc;
case 0x0c0c4ebeu: goto P_0c0c4ebe;
case 0x0c0c4ec0u: goto P_0c0c4ec0;
case 0x0c0c4ec2u: goto P_0c0c4ec2;
case 0x0c0c4ec4u: goto P_0c0c4ec4;
case 0x0c0c4ec6u: goto P_0c0c4ec6;
case 0x0c0c4ec8u: goto P_0c0c4ec8;
case 0x0c0c4ecau: goto P_0c0c4eca;
case 0x0c0c4eccu: goto P_0c0c4ecc;
case 0x0c0c4eceu: goto P_0c0c4ece;
case 0x0c0c4ed0u: goto P_0c0c4ed0;
case 0x0c0c4ed2u: goto P_0c0c4ed2;
case 0x0c0c4ed4u: goto P_0c0c4ed4;
case 0x0c0c4ed6u: goto P_0c0c4ed6;
case 0x0c0c4ed8u: goto P_0c0c4ed8;
case 0x0c0c4edau: goto P_0c0c4eda;
case 0x0c0c4edcu: goto P_0c0c4edc;
case 0x0c0c4edeu: goto P_0c0c4ede;
case 0x0c0c4ee0u: goto P_0c0c4ee0;
case 0x0c0c4ee2u: goto P_0c0c4ee2;
case 0x0c0c4ee4u: goto P_0c0c4ee4;
case 0x0c0c4ee6u: goto P_0c0c4ee6;
case 0x0c0c4ee8u: goto P_0c0c4ee8;
case 0x0c0c4eeau: goto P_0c0c4eea;
case 0x0c0c4eecu: goto P_0c0c4eec;
case 0x0c0c4eeeu: goto P_0c0c4eee;
case 0x0c0c4ef0u: goto P_0c0c4ef0;
case 0x0c0c4ef2u: goto P_0c0c4ef2;
case 0x0c0c4ef4u: goto P_0c0c4ef4;
case 0x0c0c4ef6u: goto P_0c0c4ef6;
case 0x0c0c4ef8u: goto P_0c0c4ef8;
case 0x0c0c4efau: goto P_0c0c4efa;
case 0x0c0c4efcu: goto P_0c0c4efc;
case 0x0c0c4efeu: goto P_0c0c4efe;
case 0x0c0c4f00u: goto P_0c0c4f00;
case 0x0c0c4f02u: goto P_0c0c4f02;
case 0x0c0c4f04u: goto P_0c0c4f04;
case 0x0c0c4f06u: goto P_0c0c4f06;
case 0x0c0c4f08u: goto P_0c0c4f08;
case 0x0c0c4f0au: goto P_0c0c4f0a;
case 0x0c0c4f0cu: goto P_0c0c4f0c;
case 0x0c0c4f0eu: goto P_0c0c4f0e;
case 0x0c0c4f10u: goto P_0c0c4f10;
case 0x0c0c4f12u: goto P_0c0c4f12;
case 0x0c0c4f14u: goto P_0c0c4f14;
case 0x0c0c4f16u: goto P_0c0c4f16;
case 0x0c0c4f18u: goto P_0c0c4f18;
case 0x0c0c4f1au: goto P_0c0c4f1a;
case 0x0c0c4f1cu: goto P_0c0c4f1c;
case 0x0c0c4f1eu: goto P_0c0c4f1e;
case 0x0c0c4f20u: goto P_0c0c4f20;
case 0x0c0c4f22u: goto P_0c0c4f22;
case 0x0c0c4f24u: goto P_0c0c4f24;
case 0x0c0c4f26u: goto P_0c0c4f26;
case 0x0c0c4f28u: goto P_0c0c4f28;
case 0x0c0c4f2au: goto P_0c0c4f2a;
case 0x0c0c4f2cu: goto P_0c0c4f2c;
case 0x0c0c4f2eu: goto P_0c0c4f2e;
case 0x0c0c4f30u: goto P_0c0c4f30;
case 0x0c0c4f32u: goto P_0c0c4f32;
case 0x0c0c4f34u: goto P_0c0c4f34;
case 0x0c0c4f36u: goto P_0c0c4f36;
case 0x0c0c4f38u: goto P_0c0c4f38;
case 0x0c0c4f3au: goto P_0c0c4f3a;
case 0x0c0c4f3cu: goto P_0c0c4f3c;
case 0x0c0c4f3eu: goto P_0c0c4f3e;
case 0x0c0c4f40u: goto P_0c0c4f40;
case 0x0c0c4f80u: goto P_0c0c4f80;
case 0x0c0c4f82u: goto P_0c0c4f82;
case 0x0c0c4f84u: goto P_0c0c4f84;
case 0x0c0c4f86u: goto P_0c0c4f86;
case 0x0c0c4f88u: goto P_0c0c4f88;
case 0x0c0c4f8au: goto P_0c0c4f8a;
case 0x0c0c4f8cu: goto P_0c0c4f8c;
case 0x0c0c4f8eu: goto P_0c0c4f8e;
case 0x0c0c4f90u: goto P_0c0c4f90;
case 0x0c0c4f92u: goto P_0c0c4f92;
case 0x0c0c4f94u: goto P_0c0c4f94;
case 0x0c0c4f96u: goto P_0c0c4f96;
case 0x0c0c4f98u: goto P_0c0c4f98;
case 0x0c0c4f9au: goto P_0c0c4f9a;
case 0x0c0c4f9cu: goto P_0c0c4f9c;
case 0x0c0c4f9eu: goto P_0c0c4f9e;
case 0x0c0c4fa0u: goto P_0c0c4fa0;
case 0x0c0c4fa2u: goto P_0c0c4fa2;
case 0x0c0c4fa4u: goto P_0c0c4fa4;
case 0x0c0c4fa6u: goto P_0c0c4fa6;
case 0x0c0c4fa8u: goto P_0c0c4fa8;
case 0x0c0c4faau: goto P_0c0c4faa;
case 0x0c0c4facu: goto P_0c0c4fac;
case 0x0c0c4faeu: goto P_0c0c4fae;
case 0x0c0c4fb0u: goto P_0c0c4fb0;
case 0x0c0c4fb2u: goto P_0c0c4fb2;
case 0x0c0c4fb4u: goto P_0c0c4fb4;
case 0x0c0c4fb6u: goto P_0c0c4fb6;
case 0x0c0c4fb8u: goto P_0c0c4fb8;
case 0x0c0c4fbau: goto P_0c0c4fba;
case 0x0c0c4fbcu: goto P_0c0c4fbc;
case 0x0c0c4fbeu: goto P_0c0c4fbe;
case 0x0c0c4fc0u: goto P_0c0c4fc0;
case 0x0c0c4fc2u: goto P_0c0c4fc2;
case 0x0c0c4fc4u: goto P_0c0c4fc4;
case 0x0c0c4fc6u: goto P_0c0c4fc6;
case 0x0c0c4fc8u: goto P_0c0c4fc8;
case 0x0c0c4fcau: goto P_0c0c4fca;
case 0x0c0c4fccu: goto P_0c0c4fcc;
case 0x0c0c4fceu: goto P_0c0c4fce;
case 0x0c0c4fd0u: goto P_0c0c4fd0;
case 0x0c0c4fd2u: goto P_0c0c4fd2;
case 0x0c0c4fd4u: goto P_0c0c4fd4;
case 0x0c0c4fd6u: goto P_0c0c4fd6;
case 0x0c0c4fd8u: goto P_0c0c4fd8;
case 0x0c0c4fdau: goto P_0c0c4fda;
case 0x0c0c4fdcu: goto P_0c0c4fdc;
case 0x0c0c4fdeu: goto P_0c0c4fde;
case 0x0c0c4fe0u: goto P_0c0c4fe0;
case 0x0c0c4fe2u: goto P_0c0c4fe2;
case 0x0c0c4fe4u: goto P_0c0c4fe4;
case 0x0c0c4fe6u: goto P_0c0c4fe6;
case 0x0c0c4fe8u: goto P_0c0c4fe8;
case 0x0c0c4feau: goto P_0c0c4fea;
case 0x0c0c4fecu: goto P_0c0c4fec;
case 0x0c0c4feeu: goto P_0c0c4fee;
case 0x0c0c4ff0u: goto P_0c0c4ff0;
case 0x0c0c4ff2u: goto P_0c0c4ff2;
case 0x0c0c4ff4u: goto P_0c0c4ff4;
case 0x0c0c4ff6u: goto P_0c0c4ff6;
case 0x0c0c4ff8u: goto P_0c0c4ff8;
case 0x0c0c4ffau: goto P_0c0c4ffa;
case 0x0c0c4ffcu: goto P_0c0c4ffc;
case 0x0c0c4ffeu: goto P_0c0c4ffe;
case 0x0c0c5000u: goto P_0c0c5000;
case 0x0c0c5002u: goto P_0c0c5002;
case 0x0c0c5004u: goto P_0c0c5004;
case 0x0c0c5006u: goto P_0c0c5006;
case 0x0c0c5008u: goto P_0c0c5008;
case 0x0c0c500au: goto P_0c0c500a;
case 0x0c0c500cu: goto P_0c0c500c;
case 0x0c0c500eu: goto P_0c0c500e;
case 0x0c0c5010u: goto P_0c0c5010;
case 0x0c0c5012u: goto P_0c0c5012;
case 0x0c0c5014u: goto P_0c0c5014;
case 0x0c0c5016u: goto P_0c0c5016;
case 0x0c0c5018u: goto P_0c0c5018;
case 0x0c0c501au: goto P_0c0c501a;
case 0x0c0c501cu: goto P_0c0c501c;
case 0x0c0c501eu: goto P_0c0c501e;
case 0x0c0c5020u: goto P_0c0c5020;
case 0x0c0c5022u: goto P_0c0c5022;
case 0x0c0c5024u: goto P_0c0c5024;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c4d14: /* original 2fe6, guest PC 0x0c0c4d14 */
if(!s->budget--) { s->failed_pc=0x0c0c4d14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4d16;
P_0c0c4d16: /* original 6e53, guest PC 0x0c0c4d16 */
if(!s->budget--) { s->failed_pc=0x0c0c4d16u; return 0; }
r[14]=r[5];
goto P_0c0c4d18;
P_0c0c4d18: /* original e060, guest PC 0x0c0c4d18 */
if(!s->budget--) { s->failed_pc=0x0c0c4d18u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d1a;
P_0c0c4d1a: /* original 2fd6, guest PC 0x0c0c4d1a */
if(!s->budget--) { s->failed_pc=0x0c0c4d1au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4d1c;
P_0c0c4d1c: /* original 06ec, guest PC 0x0c0c4d1c */
if(!s->budget--) { s->failed_pc=0x0c0c4d1cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d1e;
P_0c0c4d1e: /* original d040, guest PC 0x0c0c4d1e */
if(!s->budget--) { s->failed_pc=0x0c0c4d1eu; return 0; }
r[0]=read(ram,0x0c0c4e20u,4);
goto P_0c0c4d20;
P_0c0c4d20: /* original 666c, guest PC 0x0c0c4d20 */
if(!s->budget--) { s->failed_pc=0x0c0c4d20u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c4d22;
P_0c0c4d22: /* original d73e, guest PC 0x0c0c4d22 */
if(!s->budget--) { s->failed_pc=0x0c0c4d22u; return 0; }
r[7]=read(ram,0x0c0c4e1cu,4);
goto P_0c0c4d24;
P_0c0c4d24: /* original 4608, guest PC 0x0c0c4d24 */
if(!s->budget--) { s->failed_pc=0x0c0c4d24u; return 0; }
r[6]<<=2;
goto P_0c0c4d26;
P_0c0c4d26: /* original 066e, guest PC 0x0c0c4d26 */
if(!s->budget--) { s->failed_pc=0x0c0c4d26u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c0c4d28;
P_0c0c4d28: /* original e052, guest PC 0x0c0c4d28 */
if(!s->budget--) { s->failed_pc=0x0c0c4d28u; return 0; }
r[0]=0x00000052u;
goto P_0c0c4d2a;
P_0c0c4d2a: /* original 054c, guest PC 0x0c0c4d2a */
if(!s->budget--) { s->failed_pc=0x0c0c4d2au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d2c;
P_0c0c4d2c: /* original 4f22, guest PC 0x0c0c4d2c */
if(!s->budget--) { s->failed_pc=0x0c0c4d2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4d2e;
P_0c0c4d2e: /* original 6053, guest PC 0x0c0c4d2e */
if(!s->budget--) { s->failed_pc=0x0c0c4d2eu; return 0; }
r[0]=r[5];
goto P_0c0c4d30;
P_0c0c4d30: /* original 4001, guest PC 0x0c0c4d30 */
if(!s->budget--) { s->failed_pc=0x0c0c4d30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c4d32;
P_0c0c4d32: /* original 4000, guest PC 0x0c0c4d32 */
if(!s->budget--) { s->failed_pc=0x0c0c4d32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4d34;
P_0c0c4d34: /* original 006d, guest PC 0x0c0c4d34 */
if(!s->budget--) { s->failed_pc=0x0c0c4d34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c4d36;
P_0c0c4d36: /* original 88ff, guest PC 0x0c0c4d36 */
if(!s->budget--) { s->failed_pc=0x0c0c4d36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4d38;
P_0c0c4d38: /* original 8d05, guest PC 0x0c0c4d38 */
if(!s->budget--) { s->failed_pc=0x0c0c4d38u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c0c4d46; }
goto P_0c0c4d3c;
P_0c0c4d3a: /* original 6d03, guest PC 0x0c0c4d3a */
if(!s->budget--) { s->failed_pc=0x0c0c4d3au; return 0; }
r[13]=r[0];
goto P_0c0c4d3c;
P_0c0c4d3c: /* original e052, guest PC 0x0c0c4d3c */
if(!s->budget--) { s->failed_pc=0x0c0c4d3cu; return 0; }
r[0]=0x00000052u;
goto P_0c0c4d3e;
P_0c0c4d3e: /* original 7502, guest PC 0x0c0c4d3e */
if(!s->budget--) { s->failed_pc=0x0c0c4d3eu; return 0; }
r[5]+=0x00000002u;
goto P_0c0c4d40;
P_0c0c4d40: /* original 0454, guest PC 0x0c0c4d40 */
if(!s->budget--) { s->failed_pc=0x0c0c4d40u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4d42;
P_0c0c4d42: /* original a02c, guest PC 0x0c0c4d42 */
if(!s->budget--) { s->failed_pc=0x0c0c4d42u; return 0; }
r[4]=r[13];
goto P_0c0c4d9e;
P_0c0c4d44: /* original 64d3, guest PC 0x0c0c4d44 */
if(!s->budget--) { s->failed_pc=0x0c0c4d44u; return 0; }
r[4]=r[13];
goto P_0c0c4d46;
P_0c0c4d46: /* original e050, guest PC 0x0c0c4d46 */
if(!s->budget--) { s->failed_pc=0x0c0c4d46u; return 0; }
r[0]=0x00000050u;
goto P_0c0c4d48;
P_0c0c4d48: /* original 064c, guest PC 0x0c0c4d48 */
if(!s->budget--) { s->failed_pc=0x0c0c4d48u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d4a;
P_0c0c4d4a: /* original 636c, guest PC 0x0c0c4d4a */
if(!s->budget--) { s->failed_pc=0x0c0c4d4au; return 0; }
r[3]=r[6]&255u;
goto P_0c0c4d4c;
P_0c0c4d4c: /* original 2338, guest PC 0x0c0c4d4c */
if(!s->budget--) { s->failed_pc=0x0c0c4d4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4d4e;
P_0c0c4d4e: /* original 8b1a, guest PC 0x0c0c4d4e */
if(!s->budget--) { s->failed_pc=0x0c0c4d4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4d86; }
goto P_0c0c4d50;
P_0c0c4d50: /* original e060, guest PC 0x0c0c4d50 */
if(!s->budget--) { s->failed_pc=0x0c0c4d50u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d52;
P_0c0c4d52: /* original 05ec, guest PC 0x0c0c4d52 */
if(!s->budget--) { s->failed_pc=0x0c0c4d52u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d54;
P_0c0c4d54: /* original 605c, guest PC 0x0c0c4d54 */
if(!s->budget--) { s->failed_pc=0x0c0c4d54u; return 0; }
r[0]=r[5]&255u;
goto P_0c0c4d56;
P_0c0c4d56: /* original 8803, guest PC 0x0c0c4d56 */
if(!s->budget--) { s->failed_pc=0x0c0c4d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c4d58;
P_0c0c4d58: /* original 8d16, guest PC 0x0c0c4d58 */
if(!s->budget--) { s->failed_pc=0x0c0c4d58u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d5c;
P_0c0c4d5a: /* original 6503, guest PC 0x0c0c4d5a */
if(!s->budget--) { s->failed_pc=0x0c0c4d5au; return 0; }
r[5]=r[0];
goto P_0c0c4d5c;
P_0c0c4d5c: /* original 6053, guest PC 0x0c0c4d5c */
if(!s->budget--) { s->failed_pc=0x0c0c4d5cu; return 0; }
r[0]=r[5];
goto P_0c0c4d5e;
P_0c0c4d5e: /* original 8810, guest PC 0x0c0c4d5e */
if(!s->budget--) { s->failed_pc=0x0c0c4d5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0c4d60;
P_0c0c4d60: /* original 8912, guest PC 0x0c0c4d60 */
if(!s->budget--) { s->failed_pc=0x0c0c4d60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d62;
P_0c0c4d62: /* original 6053, guest PC 0x0c0c4d62 */
if(!s->budget--) { s->failed_pc=0x0c0c4d62u; return 0; }
r[0]=r[5];
goto P_0c0c4d64;
P_0c0c4d64: /* original 8807, guest PC 0x0c0c4d64 */
if(!s->budget--) { s->failed_pc=0x0c0c4d64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c4d66;
P_0c0c4d66: /* original 890f, guest PC 0x0c0c4d66 */
if(!s->budget--) { s->failed_pc=0x0c0c4d66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d68;
P_0c0c4d68: /* original 6053, guest PC 0x0c0c4d68 */
if(!s->budget--) { s->failed_pc=0x0c0c4d68u; return 0; }
r[0]=r[5];
goto P_0c0c4d6a;
P_0c0c4d6a: /* original 8814, guest PC 0x0c0c4d6a */
if(!s->budget--) { s->failed_pc=0x0c0c4d6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c0c4d6c;
P_0c0c4d6c: /* original 890c, guest PC 0x0c0c4d6c */
if(!s->budget--) { s->failed_pc=0x0c0c4d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d6e;
P_0c0c4d6e: /* original e057, guest PC 0x0c0c4d6e */
if(!s->budget--) { s->failed_pc=0x0c0c4d6eu; return 0; }
r[0]=0x00000057u;
goto P_0c0c4d70;
P_0c0c4d70: /* original 024c, guest PC 0x0c0c4d70 */
if(!s->budget--) { s->failed_pc=0x0c0c4d70u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d72;
P_0c0c4d72: /* original 2228, guest PC 0x0c0c4d72 */
if(!s->budget--) { s->failed_pc=0x0c0c4d72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4d74;
P_0c0c4d74: /* original 8f07, guest PC 0x0c0c4d74 */
if(!s->budget--) { s->failed_pc=0x0c0c4d74u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c0c4d86; }
goto P_0c0c4d78;
P_0c0c4d76: /* original e601, guest PC 0x0c0c4d76 */
if(!s->budget--) { s->failed_pc=0x0c0c4d76u; return 0; }
r[6]=0x00000001u;
goto P_0c0c4d78;
P_0c0c4d78: /* original 904e, guest PC 0x0c0c4d78 */
if(!s->budget--) { s->failed_pc=0x0c0c4d78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4e18u,2);
goto P_0c0c4d7a;
P_0c0c4d7a: /* original 655b, guest PC 0x0c0c4d7a */
if(!s->budget--) { s->failed_pc=0x0c0c4d7au; return 0; }
r[5]=0u-r[5];
goto P_0c0c4d7c;
P_0c0c4d7c: /* original d329, guest PC 0x0c0c4d7c */
if(!s->budget--) { s->failed_pc=0x0c0c4d7cu; return 0; }
r[3]=read(ram,0x0c0c4e24u,4);
goto P_0c0c4d7e;
P_0c0c4d7e: /* original 0d7e, guest PC 0x0c0c4d7e */
if(!s->budget--) { s->failed_pc=0x0c0c4d7eu; return 0; }
r[13]=read(ram,r[7]+r[0],4);
goto P_0c0c4d80;
P_0c0c4d80: /* original 435d, guest PC 0x0c0c4d80 */
if(!s->budget--) { s->failed_pc=0x0c0c4d80u; return 0; }
r[3]=(r[5]&0x80000000u)?((r[5]&31u)?r[3]>>((-r[5])&31u):0):r[3]<<(r[5]&31u);
goto P_0c0c4d82;
P_0c0c4d82: /* original 2d3b, guest PC 0x0c0c4d82 */
if(!s->budget--) { s->failed_pc=0x0c0c4d82u; return 0; }
r[13]|=r[3];
goto P_0c0c4d84;
P_0c0c4d84: /* original 07d6, guest PC 0x0c0c4d84 */
if(!s->budget--) { s->failed_pc=0x0c0c4d84u; return 0; }
write(ram,r[7]+r[0],r[13],4);
goto P_0c0c4d86;
P_0c0c4d86: /* original 76ff, guest PC 0x0c0c4d86 */
if(!s->budget--) { s->failed_pc=0x0c0c4d86u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0c4d88;
P_0c0c4d88: /* original 9047, guest PC 0x0c0c4d88 */
if(!s->budget--) { s->failed_pc=0x0c0c4d88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4e1au,2);
goto P_0c0c4d8a;
P_0c0c4d8a: /* original e303, guest PC 0x0c0c4d8a */
if(!s->budget--) { s->failed_pc=0x0c0c4d8au; return 0; }
r[3]=0x00000003u;
goto P_0c0c4d8c;
P_0c0c4d8c: /* original 0e34, guest PC 0x0c0c4d8c */
if(!s->budget--) { s->failed_pc=0x0c0c4d8cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4d8e;
P_0c0c4d8e: /* original e050, guest PC 0x0c0c4d8e */
if(!s->budget--) { s->failed_pc=0x0c0c4d8eu; return 0; }
r[0]=0x00000050u;
goto P_0c0c4d90;
P_0c0c4d90: /* original 0464, guest PC 0x0c0c4d90 */
if(!s->budget--) { s->failed_pc=0x0c0c4d90u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c4d92;
P_0c0c4d92: /* original e060, guest PC 0x0c0c4d92 */
if(!s->budget--) { s->failed_pc=0x0c0c4d92u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d94;
P_0c0c4d94: /* original 04ec, guest PC 0x0c0c4d94 */
if(!s->budget--) { s->failed_pc=0x0c0c4d94u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d96;
P_0c0c4d96: /* original d024, guest PC 0x0c0c4d96 */
if(!s->budget--) { s->failed_pc=0x0c0c4d96u; return 0; }
r[0]=read(ram,0x0c0c4e28u,4);
goto P_0c0c4d98;
P_0c0c4d98: /* original 644c, guest PC 0x0c0c4d98 */
if(!s->budget--) { s->failed_pc=0x0c0c4d98u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c4d9a;
P_0c0c4d9a: /* original 4400, guest PC 0x0c0c4d9a */
if(!s->budget--) { s->failed_pc=0x0c0c4d9au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c4d9c;
P_0c0c4d9c: /* original 044d, guest PC 0x0c0c4d9c */
if(!s->budget--) { s->failed_pc=0x0c0c4d9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c4d9e;
P_0c0c4d9e: /* original d323, guest PC 0x0c0c4d9e */
if(!s->budget--) { s->failed_pc=0x0c0c4d9eu; return 0; }
r[3]=read(ram,0x0c0c4e2cu,4);
goto P_0c0c4da0;
P_0c0c4da0: /* original 430b, guest PC 0x0c0c4da0 */
if(!s->budget--) { s->failed_pc=0x0c0c4da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4da4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4da4u) { target=s->pc; goto dispatch; }
goto P_0c0c4da4;
P_0c0c4da2: /* original 0009, guest PC 0x0c0c4da2 */
if(!s->budget--) { s->failed_pc=0x0c0c4da2u; return 0; }
goto P_0c0c4da4;
P_0c0c4da4: /* original 4f26, guest PC 0x0c0c4da4 */
if(!s->budget--) { s->failed_pc=0x0c0c4da4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4da6;
P_0c0c4da6: /* original 6df6, guest PC 0x0c0c4da6 */
if(!s->budget--) { s->failed_pc=0x0c0c4da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4da8;
P_0c0c4da8: /* original 000b, guest PC 0x0c0c4da8 */
if(!s->budget--) { s->failed_pc=0x0c0c4da8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4daa: /* original 6ef6, guest PC 0x0c0c4daa */
if(!s->budget--) { s->failed_pc=0x0c0c4daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c4dac;
P_0c0c4dac: /* original 2fe6, guest PC 0x0c0c4dac */
if(!s->budget--) { s->failed_pc=0x0c0c4dacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4dae;
P_0c0c4dae: /* original e060, guest PC 0x0c0c4dae */
if(!s->budget--) { s->failed_pc=0x0c0c4daeu; return 0; }
r[0]=0x00000060u;
goto P_0c0c4db0;
P_0c0c4db0: /* original 2fd6, guest PC 0x0c0c4db0 */
if(!s->budget--) { s->failed_pc=0x0c0c4db0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4db2;
P_0c0c4db2: /* original 6e43, guest PC 0x0c0c4db2 */
if(!s->budget--) { s->failed_pc=0x0c0c4db2u; return 0; }
r[14]=r[4];
goto P_0c0c4db4;
P_0c0c4db4: /* original 0d5c, guest PC 0x0c0c4db4 */
if(!s->budget--) { s->failed_pc=0x0c0c4db4u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c4db6;
P_0c0c4db6: /* original d01a, guest PC 0x0c0c4db6 */
if(!s->budget--) { s->failed_pc=0x0c0c4db6u; return 0; }
r[0]=read(ram,0x0c0c4e20u,4);
goto P_0c0c4db8;
P_0c0c4db8: /* original 6ddc, guest PC 0x0c0c4db8 */
if(!s->budget--) { s->failed_pc=0x0c0c4db8u; return 0; }
r[13]=r[13]&255u;
goto P_0c0c4dba;
P_0c0c4dba: /* original 4d08, guest PC 0x0c0c4dba */
if(!s->budget--) { s->failed_pc=0x0c0c4dbau; return 0; }
r[13]<<=2;
goto P_0c0c4dbc;
P_0c0c4dbc: /* original 0dde, guest PC 0x0c0c4dbc */
if(!s->budget--) { s->failed_pc=0x0c0c4dbcu; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0c4dbe;
P_0c0c4dbe: /* original 60e2, guest PC 0x0c0c4dbe */
if(!s->budget--) { s->failed_pc=0x0c0c4dbeu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c4dc0;
P_0c0c4dc0: /* original 4f22, guest PC 0x0c0c4dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4dc2;
P_0c0c4dc2: /* original c80a, guest PC 0x0c0c4dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&10u)==0)!=0);
goto P_0c0c4dc4;
P_0c0c4dc4: /* original 8b1f, guest PC 0x0c0c4dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e06; }
goto P_0c0c4dc6;
P_0c0c4dc6: /* original e051, guest PC 0x0c0c4dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc6u; return 0; }
r[0]=0x00000051u;
goto P_0c0c4dc8;
P_0c0c4dc8: /* original 04ec, guest PC 0x0c0c4dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dca;
P_0c0c4dca: /* original 634c, guest PC 0x0c0c4dca */
if(!s->budget--) { s->failed_pc=0x0c0c4dcau; return 0; }
r[3]=r[4]&255u;
goto P_0c0c4dcc;
P_0c0c4dcc: /* original 2338, guest PC 0x0c0c4dcc */
if(!s->budget--) { s->failed_pc=0x0c0c4dccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4dce;
P_0c0c4dce: /* original 8b1a, guest PC 0x0c0c4dce */
if(!s->budget--) { s->failed_pc=0x0c0c4dceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e06; }
goto P_0c0c4dd0;
P_0c0c4dd0: /* original e052, guest PC 0x0c0c4dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd0u; return 0; }
r[0]=0x00000052u;
goto P_0c0c4dd2;
P_0c0c4dd2: /* original 03ec, guest PC 0x0c0c4dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dd4;
P_0c0c4dd4: /* original 04ec, guest PC 0x0c0c4dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dd6;
P_0c0c4dd6: /* original 7302, guest PC 0x0c0c4dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd6u; return 0; }
r[3]+=0x00000002u;
goto P_0c0c4dd8;
P_0c0c4dd8: /* original 4401, guest PC 0x0c0c4dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0c4dda;
P_0c0c4dda: /* original 0e34, guest PC 0x0c0c4dda */
if(!s->budget--) { s->failed_pc=0x0c0c4ddau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4ddc;
P_0c0c4ddc: /* original 6043, guest PC 0x0c0c4ddc */
if(!s->budget--) { s->failed_pc=0x0c0c4ddcu; return 0; }
r[0]=r[4];
goto P_0c0c4dde;
P_0c0c4dde: /* original 4000, guest PC 0x0c0c4dde */
if(!s->budget--) { s->failed_pc=0x0c0c4ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4de0;
P_0c0c4de0: /* original 03dd, guest PC 0x0c0c4de0 */
if(!s->budget--) { s->failed_pc=0x0c0c4de0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0c4de2;
P_0c0c4de2: /* original 643f, guest PC 0x0c0c4de2 */
if(!s->budget--) { s->failed_pc=0x0c0c4de2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0c4de4;
P_0c0c4de4: /* original 6043, guest PC 0x0c0c4de4 */
if(!s->budget--) { s->failed_pc=0x0c0c4de4u; return 0; }
r[0]=r[4];
goto P_0c0c4de6;
P_0c0c4de6: /* original 88ff, guest PC 0x0c0c4de6 */
if(!s->budget--) { s->failed_pc=0x0c0c4de6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4de8;
P_0c0c4de8: /* original 8b11, guest PC 0x0c0c4de8 */
if(!s->budget--) { s->failed_pc=0x0c0c4de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e0e; }
goto P_0c0c4dea;
P_0c0c4dea: /* original d311, guest PC 0x0c0c4dea */
if(!s->budget--) { s->failed_pc=0x0c0c4deau; return 0; }
r[3]=read(ram,0x0c0c4e30u,4);
goto P_0c0c4dec;
P_0c0c4dec: /* original e052, guest PC 0x0c0c4dec */
if(!s->budget--) { s->failed_pc=0x0c0c4decu; return 0; }
r[0]=0x00000052u;
goto P_0c0c4dee;
P_0c0c4dee: /* original e200, guest PC 0x0c0c4dee */
if(!s->budget--) { s->failed_pc=0x0c0c4deeu; return 0; }
r[2]=0x00000000u;
goto P_0c0c4df0;
P_0c0c4df0: /* original 430b, guest PC 0x0c0c4df0 */
if(!s->budget--) { s->failed_pc=0x0c0c4df0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4df4u;
write(ram,r[14]+r[0],r[2],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4df4u) { target=s->pc; goto dispatch; }
goto P_0c0c4df4;
P_0c0c4df2: /* original 0e24, guest PC 0x0c0c4df2 */
if(!s->budget--) { s->failed_pc=0x0c0c4df2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c4df4;
P_0c0c4df4: /* original e47f, guest PC 0x0c0c4df4 */
if(!s->budget--) { s->failed_pc=0x0c0c4df4u; return 0; }
r[4]=0x0000007fu;
goto P_0c0c4df6;
P_0c0c4df6: /* original 6503, guest PC 0x0c0c4df6 */
if(!s->budget--) { s->failed_pc=0x0c0c4df6u; return 0; }
r[5]=r[0];
goto P_0c0c4df8;
P_0c0c4df8: /* original 2459, guest PC 0x0c0c4df8 */
if(!s->budget--) { s->failed_pc=0x0c0c4df8u; return 0; }
r[4]&=r[5];
goto P_0c0c4dfa;
P_0c0c4dfa: /* original e320, guest PC 0x0c0c4dfa */
if(!s->budget--) { s->failed_pc=0x0c0c4dfau; return 0; }
r[3]=0x00000020u;
goto P_0c0c4dfc;
P_0c0c4dfc: /* original 624c, guest PC 0x0c0c4dfc */
if(!s->budget--) { s->failed_pc=0x0c0c4dfcu; return 0; }
r[2]=r[4]&255u;
goto P_0c0c4dfe;
P_0c0c4dfe: /* original 3237, guest PC 0x0c0c4dfe */
if(!s->budget--) { s->failed_pc=0x0c0c4dfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0c4e00;
P_0c0c4e00: /* original 8901, guest PC 0x0c0c4e00 */
if(!s->budget--) { s->failed_pc=0x0c0c4e00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4e06; }
goto P_0c0c4e02;
P_0c0c4e02: /* original 6453, guest PC 0x0c0c4e02 */
if(!s->budget--) { s->failed_pc=0x0c0c4e02u; return 0; }
r[4]=r[5];
goto P_0c0c4e04;
P_0c0c4e04: /* original 7420, guest PC 0x0c0c4e04 */
if(!s->budget--) { s->failed_pc=0x0c0c4e04u; return 0; }
r[4]+=0x00000020u;
goto P_0c0c4e06;
P_0c0c4e06: /* original e051, guest PC 0x0c0c4e06 */
if(!s->budget--) { s->failed_pc=0x0c0c4e06u; return 0; }
r[0]=0x00000051u;
goto P_0c0c4e08;
P_0c0c4e08: /* original 74ff, guest PC 0x0c0c4e08 */
if(!s->budget--) { s->failed_pc=0x0c0c4e08u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c4e0a;
P_0c0c4e0a: /* original 0e44, guest PC 0x0c0c4e0a */
if(!s->budget--) { s->failed_pc=0x0c0c4e0au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c4e0c;
P_0c0c4e0c: /* original 64d1, guest PC 0x0c0c4e0c */
if(!s->budget--) { s->failed_pc=0x0c0c4e0cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c0c4e0e;
P_0c0c4e0e: /* original 4f26, guest PC 0x0c0c4e0e */
if(!s->budget--) { s->failed_pc=0x0c0c4e0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e10;
P_0c0c4e10: /* original d306, guest PC 0x0c0c4e10 */
if(!s->budget--) { s->failed_pc=0x0c0c4e10u; return 0; }
r[3]=read(ram,0x0c0c4e2cu,4);
goto P_0c0c4e12;
P_0c0c4e12: /* original 6df6, guest PC 0x0c0c4e12 */
if(!s->budget--) { s->failed_pc=0x0c0c4e12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4e14;
P_0c0c4e14: /* original 432b, guest PC 0x0c0c4e14 */
if(!s->budget--) { s->failed_pc=0x0c0c4e14u; return 0; }
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
P_0c0c4e16: /* original 6ef6, guest PC 0x0c0c4e16 */
if(!s->budget--) { s->failed_pc=0x0c0c4e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c4e18u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4e18u; return 0; } return 1;
P_0c0c4e34: /* original 2fe6, guest PC 0x0c0c4e34 */
if(!s->budget--) { s->failed_pc=0x0c0c4e34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e36;
P_0c0c4e36: /* original 2fd6, guest PC 0x0c0c4e36 */
if(!s->budget--) { s->failed_pc=0x0c0c4e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e38;
P_0c0c4e38: /* original ed00, guest PC 0x0c0c4e38 */
if(!s->budget--) { s->failed_pc=0x0c0c4e38u; return 0; }
r[13]=0x00000000u;
goto P_0c0c4e3a;
P_0c0c4e3a: /* original 2fc6, guest PC 0x0c0c4e3a */
if(!s->budget--) { s->failed_pc=0x0c0c4e3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e3c;
P_0c0c4e3c: /* original 6ed3, guest PC 0x0c0c4e3c */
if(!s->budget--) { s->failed_pc=0x0c0c4e3cu; return 0; }
r[14]=r[13];
goto P_0c0c4e3e;
P_0c0c4e3e: /* original 2fb6, guest PC 0x0c0c4e3e */
if(!s->budget--) { s->failed_pc=0x0c0c4e3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e40;
P_0c0c4e40: /* original 2fa6, guest PC 0x0c0c4e40 */
if(!s->budget--) { s->failed_pc=0x0c0c4e40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e42;
P_0c0c4e42: /* original 2f96, guest PC 0x0c0c4e42 */
if(!s->budget--) { s->failed_pc=0x0c0c4e42u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e44;
P_0c0c4e44: /* original 2f86, guest PC 0x0c0c4e44 */
if(!s->budget--) { s->failed_pc=0x0c0c4e44u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e46;
P_0c0c4e46: /* original fffb, guest PC 0x0c0c4e46 */
if(!s->budget--) { s->failed_pc=0x0c0c4e46u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c4e48;
P_0c0c4e48: /* original ffeb, guest PC 0x0c0c4e48 */
if(!s->budget--) { s->failed_pc=0x0c0c4e48u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c4e4a;
P_0c0c4e4a: /* original 4f22, guest PC 0x0c0c4e4a */
if(!s->budget--) { s->failed_pc=0x0c0c4e4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4e4c;
P_0c0c4e4c: /* original 7ff8, guest PC 0x0c0c4e4c */
if(!s->budget--) { s->failed_pc=0x0c0c4e4cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c4e4e;
P_0c0c4e4e: /* original 2f42, guest PC 0x0c0c4e4e */
if(!s->budget--) { s->failed_pc=0x0c0c4e4eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c4e50;
P_0c0c4e50: /* original 9078, guest PC 0x0c0c4e50 */
if(!s->budget--) { s->failed_pc=0x0c0c4e50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f44u,2);
goto P_0c0c4e52;
P_0c0c4e52: /* original 9876, guest PC 0x0c0c4e52 */
if(!s->budget--) { s->failed_pc=0x0c0c4e52u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f42u,2);
goto P_0c0c4e54;
P_0c0c4e54: /* original 81f2, guest PC 0x0c0c4e54 */
if(!s->budget--) { s->failed_pc=0x0c0c4e54u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c4e56;
P_0c0c4e56: /* original c740, guest PC 0x0c0c4e56 */
if(!s->budget--) { s->failed_pc=0x0c0c4e56u; return 0; }
r[0]=code_base|0x000c4f58u;
goto P_0c0c4e58;
P_0c0c4e58: /* original fe08, guest PC 0x0c0c4e58 */
if(!s->budget--) { s->failed_pc=0x0c0c4e58u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c4e5a;
P_0c0c4e5a: /* original c740, guest PC 0x0c0c4e5a */
if(!s->budget--) { s->failed_pc=0x0c0c4e5au; return 0; }
r[0]=code_base|0x000c4f5cu;
goto P_0c0c4e5c;
P_0c0c4e5c: /* original 69f2, guest PC 0x0c0c4e5c */
if(!s->budget--) { s->failed_pc=0x0c0c4e5cu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0c4e5e;
P_0c0c4e5e: /* original 9b72, guest PC 0x0c0c4e5e */
if(!s->budget--) { s->failed_pc=0x0c0c4e5eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f46u,2);
goto P_0c0c4e60;
P_0c0c4e60: /* original dc3f, guest PC 0x0c0c4e60 */
if(!s->budget--) { s->failed_pc=0x0c0c4e60u; return 0; }
r[12]=read(ram,0x0c0c4f60u,4);
goto P_0c0c4e62;
P_0c0c4e62: /* original 7904, guest PC 0x0c0c4e62 */
if(!s->budget--) { s->failed_pc=0x0c0c4e62u; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e64;
P_0c0c4e64: /* original ff08, guest PC 0x0c0c4e64 */
if(!s->budget--) { s->failed_pc=0x0c0c4e64u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c4e66;
P_0c0c4e66: /* original 85f2, guest PC 0x0c0c4e66 */
if(!s->budget--) { s->failed_pc=0x0c0c4e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c4e68;
P_0c0c4e68: /* original 3d8c, guest PC 0x0c0c4e68 */
if(!s->budget--) { s->failed_pc=0x0c0c4e68u; return 0; }
r[13]+=r[8];
goto P_0c0c4e6a;
P_0c0c4e6a: /* original 3e0c, guest PC 0x0c0c4e6a */
if(!s->budget--) { s->failed_pc=0x0c0c4e6au; return 0; }
r[14]+=r[0];
goto P_0c0c4e6c;
P_0c0c4e6c: /* original 4c0b, guest PC 0x0c0c4e6c */
if(!s->budget--) { s->failed_pc=0x0c0c4e6cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e70u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e70u) { target=s->pc; goto dispatch; }
goto P_0c0c4e70;
P_0c0c4e6e: /* original 64ef, guest PC 0x0c0c4e6e */
if(!s->budget--) { s->failed_pc=0x0c0c4e6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c4e70;
P_0c0c4e70: /* original f4fc, guest PC 0x0c0c4e70 */
if(!s->budget--) { s->failed_pc=0x0c0c4e70u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c4e72;
P_0c0c4e72: /* original 6add, guest PC 0x0c0c4e72 */
if(!s->budget--) { s->failed_pc=0x0c0c4e72u; return 0; }
r[10]=r[13]&65535u;
goto P_0c0c4e74;
P_0c0c4e74: /* original f30c, guest PC 0x0c0c4e74 */
if(!s->budget--) { s->failed_pc=0x0c0c4e74u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e76;
P_0c0c4e76: /* original f432, guest PC 0x0c0c4e76 */
if(!s->budget--) { s->failed_pc=0x0c0c4e76u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e78;
P_0c0c4e78: /* original f43d, guest PC 0x0c0c4e78 */
if(!s->budget--) { s->failed_pc=0x0c0c4e78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c4e7a;
P_0c0c4e7a: /* original 045a, guest PC 0x0c0c4e7a */
if(!s->budget--) { s->failed_pc=0x0c0c4e7au; return 0; }
r[4]=r[53];
goto P_0c0c4e7c;
P_0c0c4e7c: /* original 3a4c, guest PC 0x0c0c4e7c */
if(!s->budget--) { s->failed_pc=0x0c0c4e7cu; return 0; }
r[10]+=r[4];
goto P_0c0c4e7e;
P_0c0c4e7e: /* original 4c0b, guest PC 0x0c0c4e7e */
if(!s->budget--) { s->failed_pc=0x0c0c4e7eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e82u;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e82u) { target=s->pc; goto dispatch; }
goto P_0c0c4e82;
P_0c0c4e80: /* original 64af, guest PC 0x0c0c4e80 */
if(!s->budget--) { s->failed_pc=0x0c0c4e80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c4e82;
P_0c0c4e82: /* original f4ec, guest PC 0x0c0c4e82 */
if(!s->budget--) { s->failed_pc=0x0c0c4e82u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c4e84;
P_0c0c4e84: /* original 4b10, guest PC 0x0c0c4e84 */
if(!s->budget--) { s->failed_pc=0x0c0c4e84u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0c4e86;
P_0c0c4e86: /* original f30c, guest PC 0x0c0c4e86 */
if(!s->budget--) { s->failed_pc=0x0c0c4e86u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e88;
P_0c0c4e88: /* original f432, guest PC 0x0c0c4e88 */
if(!s->budget--) { s->failed_pc=0x0c0c4e88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e8a;
P_0c0c4e8a: /* original 7904, guest PC 0x0c0c4e8a */
if(!s->budget--) { s->failed_pc=0x0c0c4e8au; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e8c;
P_0c0c4e8c: /* original 8feb, guest PC 0x0c0c4e8c */
if(!s->budget--) { s->failed_pc=0x0c0c4e8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[9]);
if(!cond) { goto P_0c0c4e66; }
goto P_0c0c4e90;
P_0c0c4e8e: /* original f94a, guest PC 0x0c0c4e8e */
if(!s->budget--) { s->failed_pc=0x0c0c4e8eu; return 0; }
vf3_matrix_store(s,ram,4,r[9]);
goto P_0c0c4e90;
P_0c0c4e90: /* original 62f2, guest PC 0x0c0c4e90 */
if(!s->budget--) { s->failed_pc=0x0c0c4e90u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c4e92;
P_0c0c4e92: /* original 7f08, guest PC 0x0c0c4e92 */
if(!s->budget--) { s->failed_pc=0x0c0c4e92u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c4e94;
P_0c0c4e94: /* original 4f26, guest PC 0x0c0c4e94 */
if(!s->budget--) { s->failed_pc=0x0c0c4e94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e96;
P_0c0c4e96: /* original 9057, guest PC 0x0c0c4e96 */
if(!s->budget--) { s->failed_pc=0x0c0c4e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f48u,2);
goto P_0c0c4e98;
P_0c0c4e98: /* original e300, guest PC 0x0c0c4e98 */
if(!s->budget--) { s->failed_pc=0x0c0c4e98u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4e9a;
P_0c0c4e9a: /* original 0236, guest PC 0x0c0c4e9a */
if(!s->budget--) { s->failed_pc=0x0c0c4e9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c4e9c;
P_0c0c4e9c: /* original fef9, guest PC 0x0c0c4e9c */
if(!s->budget--) { s->failed_pc=0x0c0c4e9cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4e9e;
P_0c0c4e9e: /* original fff9, guest PC 0x0c0c4e9e */
if(!s->budget--) { s->failed_pc=0x0c0c4e9eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4ea0;
P_0c0c4ea0: /* original 68f6, guest PC 0x0c0c4ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c4ea2;
P_0c0c4ea2: /* original 69f6, guest PC 0x0c0c4ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c4ea4;
P_0c0c4ea4: /* original 6af6, guest PC 0x0c0c4ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4ea6;
P_0c0c4ea6: /* original 6bf6, guest PC 0x0c0c4ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4ea8;
P_0c0c4ea8: /* original 6cf6, guest PC 0x0c0c4ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4eaa;
P_0c0c4eaa: /* original 6df6, guest PC 0x0c0c4eaa */
if(!s->budget--) { s->failed_pc=0x0c0c4eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4eac;
P_0c0c4eac: /* original 000b, guest PC 0x0c0c4eac */
if(!s->budget--) { s->failed_pc=0x0c0c4eacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4eae: /* original 6ef6, guest PC 0x0c0c4eae */
if(!s->budget--) { s->failed_pc=0x0c0c4eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c4eb0;
P_0c0c4eb0: /* original 2fe6, guest PC 0x0c0c4eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4eb2;
P_0c0c4eb2: /* original 2fd6, guest PC 0x0c0c4eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4eb4;
P_0c0c4eb4: /* original 2fc6, guest PC 0x0c0c4eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4eb6;
P_0c0c4eb6: /* original 2fb6, guest PC 0x0c0c4eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4eb8;
P_0c0c4eb8: /* original 2fa6, guest PC 0x0c0c4eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c4eb8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4eba;
P_0c0c4eba: /* original 4f22, guest PC 0x0c0c4eba */
if(!s->budget--) { s->failed_pc=0x0c0c4ebau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4ebc;
P_0c0c4ebc: /* original 4f12, guest PC 0x0c0c4ebc */
if(!s->budget--) { s->failed_pc=0x0c0c4ebcu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c4ebe;
P_0c0c4ebe: /* original 7ff4, guest PC 0x0c0c4ebe */
if(!s->budget--) { s->failed_pc=0x0c0c4ebeu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c4ec0;
P_0c0c4ec0: /* original 1f41, guest PC 0x0c0c4ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0c4ec2;
P_0c0c4ec2: /* original db28, guest PC 0x0c0c4ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec2u; return 0; }
r[11]=read(ram,0x0c0c4f64u,4);
goto P_0c0c4ec4;
P_0c0c4ec4: /* original d728, guest PC 0x0c0c4ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec4u; return 0; }
r[7]=read(ram,0x0c0c4f68u,4);
goto P_0c0c4ec6;
P_0c0c4ec6: /* original 64b2, guest PC 0x0c0c4ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec6u; return 0; }
tmp=read(ram,r[11],4);
r[4]=tmp;
goto P_0c0c4ec8;
P_0c0c4ec8: /* original 84b9, guest PC 0x0c0c4ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+9,1);
goto P_0c0c4eca;
P_0c0c4eca: /* original 6343, guest PC 0x0c0c4eca */
if(!s->budget--) { s->failed_pc=0x0c0c4ecau; return 0; }
r[3]=r[4];
goto P_0c0c4ecc;
P_0c0c4ecc: /* original 2379, guest PC 0x0c0c4ecc */
if(!s->budget--) { s->failed_pc=0x0c0c4eccu; return 0; }
r[3]&=r[7];
goto P_0c0c4ece;
P_0c0c4ece: /* original 2338, guest PC 0x0c0c4ece */
if(!s->budget--) { s->failed_pc=0x0c0c4eceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4ed0;
P_0c0c4ed0: /* original 2f32, guest PC 0x0c0c4ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c4ed2;
P_0c0c4ed2: /* original 660c, guest PC 0x0c0c4ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed2u; return 0; }
r[6]=r[0]&255u;
goto P_0c0c4ed4;
P_0c0c4ed4: /* original 8d05, guest PC 0x0c0c4ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed4u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[11]+4,4);
if(cond) { goto P_0c0c4ee2; }
goto P_0c0c4ed8;
P_0c0c4ed6: /* original 55b1, guest PC 0x0c0c4ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed6u; return 0; }
r[5]=read(ram,r[11]+4,4);
goto P_0c0c4ed8;
P_0c0c4ed8: /* original d324, guest PC 0x0c0c4ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ed8u; return 0; }
r[3]=read(ram,0x0c0c4f6cu,4);
goto P_0c0c4eda;
P_0c0c4eda: /* original 2358, guest PC 0x0c0c4eda */
if(!s->budget--) { s->failed_pc=0x0c0c4edau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c4edc;
P_0c0c4edc: /* original 8901, guest PC 0x0c0c4edc */
if(!s->budget--) { s->failed_pc=0x0c0c4edcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4ee2; }
goto P_0c0c4ede;
P_0c0c4ede: /* original a099, guest PC 0x0c0c4ede */
if(!s->budget--) { s->failed_pc=0x0c0c4edeu; return 0; }
goto P_0c0c5014;
P_0c0c4ee0: /* original 0009, guest PC 0x0c0c4ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee0u; return 0; }
goto P_0c0c4ee2;
P_0c0c4ee2: /* original 9232, guest PC 0x0c0c4ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4au,2);
goto P_0c0c4ee4;
P_0c0c4ee4: /* original 2249, guest PC 0x0c0c4ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee4u; return 0; }
r[2]&=r[4];
goto P_0c0c4ee6;
P_0c0c4ee6: /* original 2228, guest PC 0x0c0c4ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4ee8;
P_0c0c4ee8: /* original 8d02, guest PC 0x0c0c4ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ee8u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[2],4);
if(cond) { goto P_0c0c4ef0; }
goto P_0c0c4eec;
P_0c0c4eea: /* original 2f22, guest PC 0x0c0c4eea */
if(!s->budget--) { s->failed_pc=0x0c0c4eeau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4eec;
P_0c0c4eec: /* original a092, guest PC 0x0c0c4eec */
if(!s->budget--) { s->failed_pc=0x0c0c4eecu; return 0; }
goto P_0c0c5014;
P_0c0c4eee: /* original 0009, guest PC 0x0c0c4eee */
if(!s->budget--) { s->failed_pc=0x0c0c4eeeu; return 0; }
goto P_0c0c4ef0;
P_0c0c4ef0: /* original e320, guest PC 0x0c0c4ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef0u; return 0; }
r[3]=0x00000020u;
goto P_0c0c4ef2;
P_0c0c4ef2: /* original 3637, guest PC 0x0c0c4ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0c4ef4;
P_0c0c4ef4: /* original 8b01, guest PC 0x0c0c4ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4efa; }
goto P_0c0c4ef6;
P_0c0c4ef6: /* original a08d, guest PC 0x0c0c4ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef6u; return 0; }
goto P_0c0c5014;
P_0c0c4ef8: /* original 0009, guest PC 0x0c0c4ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ef8u; return 0; }
goto P_0c0c4efa;
P_0c0c4efa: /* original d21d, guest PC 0x0c0c4efa */
if(!s->budget--) { s->failed_pc=0x0c0c4efau; return 0; }
r[2]=read(ram,0x0c0c4f70u,4);
goto P_0c0c4efc;
P_0c0c4efc: /* original 2248, guest PC 0x0c0c4efc */
if(!s->budget--) { s->failed_pc=0x0c0c4efcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c0c4efe;
P_0c0c4efe: /* original 8b01, guest PC 0x0c0c4efe */
if(!s->budget--) { s->failed_pc=0x0c0c4efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4f04; }
goto P_0c0c4f00;
P_0c0c4f00: /* original a088, guest PC 0x0c0c4f00 */
if(!s->budget--) { s->failed_pc=0x0c0c4f00u; return 0; }
goto P_0c0c5014;
P_0c0c4f02: /* original 0009, guest PC 0x0c0c4f02 */
if(!s->budget--) { s->failed_pc=0x0c0c4f02u; return 0; }
goto P_0c0c4f04;
P_0c0c4f04: /* original d31b, guest PC 0x0c0c4f04 */
if(!s->budget--) { s->failed_pc=0x0c0c4f04u; return 0; }
r[3]=read(ram,0x0c0c4f74u,4);
goto P_0c0c4f06;
P_0c0c4f06: /* original 2438, guest PC 0x0c0c4f06 */
if(!s->budget--) { s->failed_pc=0x0c0c4f06u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4f08;
P_0c0c4f08: /* original 8903, guest PC 0x0c0c4f08 */
if(!s->budget--) { s->failed_pc=0x0c0c4f08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4f12; }
goto P_0c0c4f0a;
P_0c0c4f0a: /* original 2578, guest PC 0x0c0c4f0a */
if(!s->budget--) { s->failed_pc=0x0c0c4f0au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[7])==0)!=0);
goto P_0c0c4f0c;
P_0c0c4f0c: /* original 8901, guest PC 0x0c0c4f0c */
if(!s->budget--) { s->failed_pc=0x0c0c4f0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4f12; }
goto P_0c0c4f0e;
P_0c0c4f0e: /* original a081, guest PC 0x0c0c4f0e */
if(!s->budget--) { s->failed_pc=0x0c0c4f0eu; return 0; }
goto P_0c0c5014;
P_0c0c4f10: /* original 0009, guest PC 0x0c0c4f10 */
if(!s->budget--) { s->failed_pc=0x0c0c4f10u; return 0; }
goto P_0c0c4f12;
P_0c0c4f12: /* original 901b, guest PC 0x0c0c4f12 */
if(!s->budget--) { s->failed_pc=0x0c0c4f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4cu,2);
goto P_0c0c4f14;
P_0c0c4f14: /* original da18, guest PC 0x0c0c4f14 */
if(!s->budget--) { s->failed_pc=0x0c0c4f14u; return 0; }
r[10]=read(ram,0x0c0c4f78u,4);
goto P_0c0c4f16;
P_0c0c4f16: /* original 00ad, guest PC 0x0c0c4f16 */
if(!s->budget--) { s->failed_pc=0x0c0c4f16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4f18;
P_0c0c4f18: /* original 88ff, guest PC 0x0c0c4f18 */
if(!s->budget--) { s->failed_pc=0x0c0c4f18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4f1a;
P_0c0c4f1a: /* original 8d7b, guest PC 0x0c0c4f1a */
if(!s->budget--) { s->failed_pc=0x0c0c4f1au; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(cond) { goto P_0c0c5014; }
goto P_0c0c4f1e;
P_0c0c4f1c: /* original 6c03, guest PC 0x0c0c4f1c */
if(!s->budget--) { s->failed_pc=0x0c0c4f1cu; return 0; }
r[12]=r[0];
goto P_0c0c4f1e;
P_0c0c4f1e: /* original d317, guest PC 0x0c0c4f1e */
if(!s->budget--) { s->failed_pc=0x0c0c4f1eu; return 0; }
r[3]=read(ram,0x0c0c4f7cu,4);
goto P_0c0c4f20;
P_0c0c4f20: /* original 6432, guest PC 0x0c0c4f20 */
if(!s->budget--) { s->failed_pc=0x0c0c4f20u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c4f22;
P_0c0c4f22: /* original 854f, guest PC 0x0c0c4f22 */
if(!s->budget--) { s->failed_pc=0x0c0c4f22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+30,2);
goto P_0c0c4f24;
P_0c0c4f24: /* original 6503, guest PC 0x0c0c4f24 */
if(!s->budget--) { s->failed_pc=0x0c0c4f24u; return 0; }
r[5]=r[0];
goto P_0c0c4f26;
P_0c0c4f26: /* original 854e, guest PC 0x0c0c4f26 */
if(!s->budget--) { s->failed_pc=0x0c0c4f26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+28,2);
goto P_0c0c4f28;
P_0c0c4f28: /* original 81f4, guest PC 0x0c0c4f28 */
if(!s->budget--) { s->failed_pc=0x0c0c4f28u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c0c4f2a;
P_0c0c4f2a: /* original 9010, guest PC 0x0c0c4f2a */
if(!s->budget--) { s->failed_pc=0x0c0c4f2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f4eu,2);
goto P_0c0c4f2c;
P_0c0c4f2c: /* original 9211, guest PC 0x0c0c4f2c */
if(!s->budget--) { s->failed_pc=0x0c0c4f2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f52u,2);
goto P_0c0c4f2e;
P_0c0c4f2e: /* original 064d, guest PC 0x0c0c4f2e */
if(!s->budget--) { s->failed_pc=0x0c0c4f2eu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c4f30;
P_0c0c4f30: /* original 900e, guest PC 0x0c0c4f30 */
if(!s->budget--) { s->failed_pc=0x0c0c4f30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f50u,2);
goto P_0c0c4f32;
P_0c0c4f32: /* original 3c20, guest PC 0x0c0c4f32 */
if(!s->budget--) { s->failed_pc=0x0c0c4f32u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c0c4f34;
P_0c0c4f34: /* original 04ad, guest PC 0x0c0c4f34 */
if(!s->budget--) { s->failed_pc=0x0c0c4f34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4f36;
P_0c0c4f36: /* original 354c, guest PC 0x0c0c4f36 */
if(!s->budget--) { s->failed_pc=0x0c0c4f36u; return 0; }
r[5]+=r[4];
goto P_0c0c4f38;
P_0c0c4f38: /* original 8f22, guest PC 0x0c0c4f38 */
if(!s->budget--) { s->failed_pc=0x0c0c4f38u; return 0; }
cond=r[17]&1u;
r[5]=0u-r[5];
if(!cond) { goto P_0c0c4f80; }
goto P_0c0c4f3c;
P_0c0c4f3a: /* original 655b, guest PC 0x0c0c4f3a */
if(!s->budget--) { s->failed_pc=0x0c0c4f3au; return 0; }
r[5]=0u-r[5];
goto P_0c0c4f3c;
P_0c0c4f3c: /* original 940a, guest PC 0x0c0c4f3c */
if(!s->budget--) { s->failed_pc=0x0c0c4f3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f54u,2);
goto P_0c0c4f3e;
P_0c0c4f3e: /* original a020, guest PC 0x0c0c4f3e */
if(!s->budget--) { s->failed_pc=0x0c0c4f3eu; return 0; }
goto P_0c0c4f82;
P_0c0c4f40: /* original 0009, guest PC 0x0c0c4f40 */
if(!s->budget--) { s->failed_pc=0x0c0c4f40u; return 0; }
if(!vf3_matrix_family(0x0c0c4f42u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4f42u; return 0; } return 1;
P_0c0c4f80: /* original 9451, guest PC 0x0c0c4f80 */
if(!s->budget--) { s->failed_pc=0x0c0c4f80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5026u,2);
goto P_0c0c4f82;
P_0c0c4f82: /* original 6d5d, guest PC 0x0c0c4f82 */
if(!s->budget--) { s->failed_pc=0x0c0c4f82u; return 0; }
r[13]=r[5]&65535u;
goto P_0c0c4f84;
P_0c0c4f84: /* original 9351, guest PC 0x0c0c4f84 */
if(!s->budget--) { s->failed_pc=0x0c0c4f84u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502au,2);
goto P_0c0c4f86;
P_0c0c4f86: /* original 0d47, guest PC 0x0c0c4f86 */
if(!s->budget--) { s->failed_pc=0x0c0c4f86u; return 0; }
r[19]=r[13]*r[4];
goto P_0c0c4f88;
P_0c0c4f88: /* original 944e, guest PC 0x0c0c4f88 */
if(!s->budget--) { s->failed_pc=0x0c0c4f88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5028u,2);
goto P_0c0c4f8a;
P_0c0c4f8a: /* original 3637, guest PC 0x0c0c4f8a */
if(!s->budget--) { s->failed_pc=0x0c0c4f8au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[3])!=0);
goto P_0c0c4f8c;
P_0c0c4f8c: /* original 8f01, guest PC 0x0c0c4f8c */
if(!s->budget--) { s->failed_pc=0x0c0c4f8cu; return 0; }
cond=r[17]&1u;
r[13]=r[19];
if(!cond) { goto P_0c0c4f92; }
goto P_0c0c4f90;
P_0c0c4f8e: /* original 0d1a, guest PC 0x0c0c4f8e */
if(!s->budget--) { s->failed_pc=0x0c0c4f8eu; return 0; }
r[13]=r[19];
goto P_0c0c4f90;
P_0c0c4f90: /* original 944c, guest PC 0x0c0c4f90 */
if(!s->budget--) { s->failed_pc=0x0c0c4f90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502cu,2);
goto P_0c0c4f92;
P_0c0c4f92: /* original d328, guest PC 0x0c0c4f92 */
if(!s->budget--) { s->failed_pc=0x0c0c4f92u; return 0; }
r[3]=read(ram,0x0c0c5034u,4);
goto P_0c0c4f94;
P_0c0c4f94: /* original 61d3, guest PC 0x0c0c4f94 */
if(!s->budget--) { s->failed_pc=0x0c0c4f94u; return 0; }
r[1]=r[13];
goto P_0c0c4f96;
P_0c0c4f96: /* original 430b, guest PC 0x0c0c4f96 */
if(!s->budget--) { s->failed_pc=0x0c0c4f96u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4f9au;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4f9au) { target=s->pc; goto dispatch; }
goto P_0c0c4f9a;
P_0c0c4f98: /* original 6043, guest PC 0x0c0c4f98 */
if(!s->budget--) { s->failed_pc=0x0c0c4f98u; return 0; }
r[0]=r[4];
goto P_0c0c4f9a;
P_0c0c4f9a: /* original 4621, guest PC 0x0c0c4f9a */
if(!s->budget--) { s->failed_pc=0x0c0c4f9au; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]=(uint32_t)((int32_t)r[6]>>1);
goto P_0c0c4f9c;
P_0c0c4f9c: /* original 6d03, guest PC 0x0c0c4f9c */
if(!s->budget--) { s->failed_pc=0x0c0c4f9cu; return 0; }
r[13]=r[0];
goto P_0c0c4f9e;
P_0c0c4f9e: /* original 2f62, guest PC 0x0c0c4f9e */
if(!s->budget--) { s->failed_pc=0x0c0c4f9eu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0c4fa0;
P_0c0c4fa0: /* original d325, guest PC 0x0c0c4fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa0u; return 0; }
r[3]=read(ram,0x0c0c5038u,4);
goto P_0c0c4fa2;
P_0c0c4fa2: /* original 430b, guest PC 0x0c0c4fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4fa6u;
r[4]=(uint32_t)(int32_t)(int16_t)r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c4fa6;
P_0c0c4fa4: /* original 646f, guest PC 0x0c0c4fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[6];
goto P_0c0c4fa6;
P_0c0c4fa6: /* original c725, guest PC 0x0c0c4fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa6u; return 0; }
r[0]=code_base|0x000c503cu;
goto P_0c0c4fa8;
P_0c0c4fa8: /* original d325, guest PC 0x0c0c4fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fa8u; return 0; }
r[3]=read(ram,0x0c0c5040u,4);
goto P_0c0c4faa;
P_0c0c4faa: /* original f508, guest PC 0x0c0c4faa */
if(!s->budget--) { s->failed_pc=0x0c0c4faau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c4fac;
P_0c0c4fac: /* original f40c, guest PC 0x0c0c4fac */
if(!s->budget--) { s->failed_pc=0x0c0c4facu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c4fae;
P_0c0c4fae: /* original 430b, guest PC 0x0c0c4fae */
if(!s->budget--) { s->failed_pc=0x0c0c4faeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4fb2u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4fb2u) { target=s->pc; goto dispatch; }
goto P_0c0c4fb2;
P_0c0c4fb0: /* original f452, guest PC 0x0c0c4fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0c4fb2;
P_0c0c4fb2: /* original 640f, guest PC 0x0c0c4fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c0c4fb4;
P_0c0c4fb4: /* original 85f4, guest PC 0x0c0c4fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0c4fb6;
P_0c0c4fb6: /* original d21f, guest PC 0x0c0c4fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb6u; return 0; }
r[2]=read(ram,0x0c0c5034u,4);
goto P_0c0c4fb8;
P_0c0c4fb8: /* original 6303, guest PC 0x0c0c4fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fb8u; return 0; }
r[3]=r[0];
goto P_0c0c4fba;
P_0c0c4fba: /* original 4000, guest PC 0x0c0c4fba */
if(!s->budget--) { s->failed_pc=0x0c0c4fbau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4fbc;
P_0c0c4fbc: /* original 303c, guest PC 0x0c0c4fbc */
if(!s->budget--) { s->failed_pc=0x0c0c4fbcu; return 0; }
r[0]+=r[3];
goto P_0c0c4fbe;
P_0c0c4fbe: /* original 4008, guest PC 0x0c0c4fbe */
if(!s->budget--) { s->failed_pc=0x0c0c4fbeu; return 0; }
r[0]<<=2;
goto P_0c0c4fc0;
P_0c0c4fc0: /* original 4008, guest PC 0x0c0c4fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc0u; return 0; }
r[0]<<=2;
goto P_0c0c4fc2;
P_0c0c4fc2: /* original 4008, guest PC 0x0c0c4fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc2u; return 0; }
r[0]<<=2;
goto P_0c0c4fc4;
P_0c0c4fc4: /* original 6103, guest PC 0x0c0c4fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc4u; return 0; }
r[1]=r[0];
goto P_0c0c4fc6;
P_0c0c4fc6: /* original 420b, guest PC 0x0c0c4fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c4fcau;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4fcau) { target=s->pc; goto dispatch; }
goto P_0c0c4fca;
P_0c0c4fc8: /* original 6043, guest PC 0x0c0c4fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fc8u; return 0; }
r[0]=r[4];
goto P_0c0c4fca;
P_0c0c4fca: /* original 6e03, guest PC 0x0c0c4fca */
if(!s->budget--) { s->failed_pc=0x0c0c4fcau; return 0; }
r[14]=r[0];
goto P_0c0c4fcc;
P_0c0c4fcc: /* original 902f, guest PC 0x0c0c4fcc */
if(!s->budget--) { s->failed_pc=0x0c0c4fccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c502eu,2);
goto P_0c0c4fce;
P_0c0c4fce: /* original 65d3, guest PC 0x0c0c4fce */
if(!s->budget--) { s->failed_pc=0x0c0c4fceu; return 0; }
r[5]=r[13];
goto P_0c0c4fd0;
P_0c0c4fd0: /* original 67c3, guest PC 0x0c0c4fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd0u; return 0; }
r[7]=r[12];
goto P_0c0c4fd2;
P_0c0c4fd2: /* original 04ad, guest PC 0x0c0c4fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c0c4fd4;
P_0c0c4fd4: /* original da1b, guest PC 0x0c0c4fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd4u; return 0; }
r[10]=read(ram,0x0c0c5044u,4);
goto P_0c0c4fd6;
P_0c0c4fd6: /* original 3e48, guest PC 0x0c0c4fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd6u; return 0; }
r[14]-=r[4];
goto P_0c0c4fd8;
P_0c0c4fd8: /* original 66e3, guest PC 0x0c0c4fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fd8u; return 0; }
r[6]=r[14];
goto P_0c0c4fda;
P_0c0c4fda: /* original 2fa6, guest PC 0x0c0c4fda */
if(!s->budget--) { s->failed_pc=0x0c0c4fdau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4fdc;
P_0c0c4fdc: /* original b034, guest PC 0x0c0c4fdc */
if(!s->budget--) { s->failed_pc=0x0c0c4fdcu; return 0; }
target=code_base|0x0c0c5048u; r[16]=code_base|0x0c0c4fe0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4fe0u) { target=s->pc; goto dispatch; }
goto P_0c0c4fe0;
P_0c0c4fde: /* original 54f2, guest PC 0x0c0c4fde */
if(!s->budget--) { s->failed_pc=0x0c0c4fdeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c4fe0;
P_0c0c4fe0: /* original e01c, guest PC 0x0c0c4fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe0u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c4fe2;
P_0c0c4fe2: /* original 62e3, guest PC 0x0c0c4fe2 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe2u; return 0; }
r[2]=r[14];
goto P_0c0c4fe4;
P_0c0c4fe4: /* original e40f, guest PC 0x0c0c4fe4 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe4u; return 0; }
r[4]=0x0000000fu;
goto P_0c0c4fe6;
P_0c0c4fe6: /* original e507, guest PC 0x0c0c4fe6 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe6u; return 0; }
r[5]=0x00000007u;
goto P_0c0c4fe8;
P_0c0c4fe8: /* original 2259, guest PC 0x0c0c4fe8 */
if(!s->budget--) { s->failed_pc=0x0c0c4fe8u; return 0; }
r[2]&=r[5];
goto P_0c0c4fea;
P_0c0c4fea: /* original 7f04, guest PC 0x0c0c4fea */
if(!s->budget--) { s->failed_pc=0x0c0c4feau; return 0; }
r[15]+=0x00000004u;
goto P_0c0c4fec;
P_0c0c4fec: /* original 2f22, guest PC 0x0c0c4fec */
if(!s->budget--) { s->failed_pc=0x0c0c4fecu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4fee;
P_0c0c4fee: /* original 00bc, guest PC 0x0c0c4fee */
if(!s->budget--) { s->failed_pc=0x0c0c4feeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c4ff0;
P_0c0c4ff0: /* original 600c, guest PC 0x0c0c4ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c4ff2;
P_0c0c4ff2: /* original 2409, guest PC 0x0c0c4ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff2u; return 0; }
r[4]&=r[0];
goto P_0c0c4ff4;
P_0c0c4ff4: /* original 6043, guest PC 0x0c0c4ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff4u; return 0; }
r[0]=r[4];
goto P_0c0c4ff6;
P_0c0c4ff6: /* original 880d, guest PC 0x0c0c4ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c4ff8;
P_0c0c4ff8: /* original 8b06, guest PC 0x0c0c4ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ff8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5008; }
goto P_0c0c4ffa;
P_0c0c4ffa: /* original 65d3, guest PC 0x0c0c4ffa */
if(!s->budget--) { s->failed_pc=0x0c0c4ffau; return 0; }
r[5]=r[13];
goto P_0c0c4ffc;
P_0c0c4ffc: /* original 66e3, guest PC 0x0c0c4ffc */
if(!s->budget--) { s->failed_pc=0x0c0c4ffcu; return 0; }
r[6]=r[14];
goto P_0c0c4ffe;
P_0c0c4ffe: /* original b539, guest PC 0x0c0c4ffe */
if(!s->budget--) { s->failed_pc=0x0c0c4ffeu; return 0; }
target=code_base|0x0c0c5a74u; r[16]=code_base|0x0c0c5002u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5002u) { target=s->pc; goto dispatch; }
goto P_0c0c5002;
P_0c0c5000: /* original 54f1, guest PC 0x0c0c5000 */
if(!s->budget--) { s->failed_pc=0x0c0c5000u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5002;
P_0c0c5002: /* original 9415, guest PC 0x0c0c5002 */
if(!s->budget--) { s->failed_pc=0x0c0c5002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5030u,2);
goto P_0c0c5004;
P_0c0c5004: /* original a002, guest PC 0x0c0c5004 */
if(!s->budget--) { s->failed_pc=0x0c0c5004u; return 0; }
goto P_0c0c500c;
P_0c0c5006: /* original 0009, guest PC 0x0c0c5006 */
if(!s->budget--) { s->failed_pc=0x0c0c5006u; return 0; }
goto P_0c0c5008;
P_0c0c5008: /* original 64d3, guest PC 0x0c0c5008 */
if(!s->budget--) { s->failed_pc=0x0c0c5008u; return 0; }
r[4]=r[13];
goto P_0c0c500a;
P_0c0c500a: /* original 2459, guest PC 0x0c0c500a */
if(!s->budget--) { s->failed_pc=0x0c0c500au; return 0; }
r[4]&=r[5];
goto P_0c0c500c;
P_0c0c500c: /* original 6043, guest PC 0x0c0c500c */
if(!s->budget--) { s->failed_pc=0x0c0c500cu; return 0; }
r[0]=r[4];
goto P_0c0c500e;
P_0c0c500e: /* original 81aa, guest PC 0x0c0c500e */
if(!s->budget--) { s->failed_pc=0x0c0c500eu; return 0; }
write(ram,r[10]+20,r[0],2);
goto P_0c0c5010;
P_0c0c5010: /* original 60f2, guest PC 0x0c0c5010 */
if(!s->budget--) { s->failed_pc=0x0c0c5010u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c5012;
P_0c0c5012: /* original 81ab, guest PC 0x0c0c5012 */
if(!s->budget--) { s->failed_pc=0x0c0c5012u; return 0; }
write(ram,r[10]+22,r[0],2);
goto P_0c0c5014;
P_0c0c5014: /* original 7f0c, guest PC 0x0c0c5014 */
if(!s->budget--) { s->failed_pc=0x0c0c5014u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c5016;
P_0c0c5016: /* original 4f16, guest PC 0x0c0c5016 */
if(!s->budget--) { s->failed_pc=0x0c0c5016u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5018;
P_0c0c5018: /* original 4f26, guest PC 0x0c0c5018 */
if(!s->budget--) { s->failed_pc=0x0c0c5018u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c501a;
P_0c0c501a: /* original 6af6, guest PC 0x0c0c501a */
if(!s->budget--) { s->failed_pc=0x0c0c501au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c501c;
P_0c0c501c: /* original 6bf6, guest PC 0x0c0c501c */
if(!s->budget--) { s->failed_pc=0x0c0c501cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c501e;
P_0c0c501e: /* original 6cf6, guest PC 0x0c0c501e */
if(!s->budget--) { s->failed_pc=0x0c0c501eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5020;
P_0c0c5020: /* original 6df6, guest PC 0x0c0c5020 */
if(!s->budget--) { s->failed_pc=0x0c0c5020u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5022;
P_0c0c5022: /* original 000b, guest PC 0x0c0c5022 */
if(!s->budget--) { s->failed_pc=0x0c0c5022u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5024: /* original 6ef6, guest PC 0x0c0c5024 */
if(!s->budget--) { s->failed_pc=0x0c0c5024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5026u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5026u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
