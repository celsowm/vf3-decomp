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
int vf3_away_batch23_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b1cc4u: goto P_0c0b1cc4;
case 0x0c0b1cc6u: goto P_0c0b1cc6;
case 0x0c0b1cc8u: goto P_0c0b1cc8;
case 0x0c0b1ccau: goto P_0c0b1cca;
case 0x0c0b1cccu: goto P_0c0b1ccc;
case 0x0c0b1cceu: goto P_0c0b1cce;
case 0x0c0b1cd0u: goto P_0c0b1cd0;
case 0x0c0b1cd2u: goto P_0c0b1cd2;
case 0x0c0b1cd4u: goto P_0c0b1cd4;
case 0x0c0b1cd6u: goto P_0c0b1cd6;
case 0x0c0b1cd8u: goto P_0c0b1cd8;
case 0x0c0b1cdau: goto P_0c0b1cda;
case 0x0c0b1cdcu: goto P_0c0b1cdc;
case 0x0c0b1cdeu: goto P_0c0b1cde;
case 0x0c0b1ce0u: goto P_0c0b1ce0;
case 0x0c0b1ce2u: goto P_0c0b1ce2;
case 0x0c0b1ce4u: goto P_0c0b1ce4;
case 0x0c0b1ce6u: goto P_0c0b1ce6;
case 0x0c0b1ce8u: goto P_0c0b1ce8;
case 0x0c0b1d18u: goto P_0c0b1d18;
case 0x0c0b1d1au: goto P_0c0b1d1a;
case 0x0c0b1d1cu: goto P_0c0b1d1c;
case 0x0c0b1d1eu: goto P_0c0b1d1e;
case 0x0c0b1d20u: goto P_0c0b1d20;
case 0x0c0b1d22u: goto P_0c0b1d22;
case 0x0c0b1d24u: goto P_0c0b1d24;
case 0x0c0b1d26u: goto P_0c0b1d26;
case 0x0c0b1d28u: goto P_0c0b1d28;
case 0x0c0b1d2au: goto P_0c0b1d2a;
case 0x0c0b1d2cu: goto P_0c0b1d2c;
case 0x0c0b1d2eu: goto P_0c0b1d2e;
case 0x0c0b1d30u: goto P_0c0b1d30;
case 0x0c0b1d32u: goto P_0c0b1d32;
case 0x0c0b1d34u: goto P_0c0b1d34;
case 0x0c0b1d36u: goto P_0c0b1d36;
case 0x0c0b1d38u: goto P_0c0b1d38;
case 0x0c0b1d3au: goto P_0c0b1d3a;
case 0x0c0b1d3cu: goto P_0c0b1d3c;
case 0x0c0b1d3eu: goto P_0c0b1d3e;
case 0x0c0b1d40u: goto P_0c0b1d40;
case 0x0c0b1d42u: goto P_0c0b1d42;
case 0x0c0b1d44u: goto P_0c0b1d44;
case 0x0c0b1d46u: goto P_0c0b1d46;
case 0x0c0b1d48u: goto P_0c0b1d48;
case 0x0c0b1d4au: goto P_0c0b1d4a;
case 0x0c0b1d4cu: goto P_0c0b1d4c;
case 0x0c0b1d4eu: goto P_0c0b1d4e;
case 0x0c0b1d50u: goto P_0c0b1d50;
case 0x0c0b1d52u: goto P_0c0b1d52;
case 0x0c0b1d54u: goto P_0c0b1d54;
case 0x0c0b1d56u: goto P_0c0b1d56;
case 0x0c0b1d58u: goto P_0c0b1d58;
case 0x0c0b1d5au: goto P_0c0b1d5a;
case 0x0c0b1d5cu: goto P_0c0b1d5c;
case 0x0c0b1d5eu: goto P_0c0b1d5e;
case 0x0c0b1d60u: goto P_0c0b1d60;
case 0x0c0b1d62u: goto P_0c0b1d62;
case 0x0c0b1d64u: goto P_0c0b1d64;
case 0x0c0b1d66u: goto P_0c0b1d66;
case 0x0c0b1d68u: goto P_0c0b1d68;
case 0x0c0b1d6au: goto P_0c0b1d6a;
case 0x0c0b1d6cu: goto P_0c0b1d6c;
case 0x0c0b1d6eu: goto P_0c0b1d6e;
case 0x0c0b1d70u: goto P_0c0b1d70;
case 0x0c0b1d72u: goto P_0c0b1d72;
case 0x0c0b1d74u: goto P_0c0b1d74;
case 0x0c0b1d76u: goto P_0c0b1d76;
case 0x0c0b1d78u: goto P_0c0b1d78;
case 0x0c0b1d7au: goto P_0c0b1d7a;
case 0x0c0b1d7cu: goto P_0c0b1d7c;
case 0x0c0b1d7eu: goto P_0c0b1d7e;
case 0x0c0b1d80u: goto P_0c0b1d80;
case 0x0c0b1d82u: goto P_0c0b1d82;
case 0x0c0b1d84u: goto P_0c0b1d84;
case 0x0c0b1d86u: goto P_0c0b1d86;
case 0x0c0b1d88u: goto P_0c0b1d88;
case 0x0c0b1d8au: goto P_0c0b1d8a;
case 0x0c0b1d8cu: goto P_0c0b1d8c;
case 0x0c0b1d8eu: goto P_0c0b1d8e;
case 0x0c0b1d90u: goto P_0c0b1d90;
case 0x0c0b1d92u: goto P_0c0b1d92;
case 0x0c0b1d94u: goto P_0c0b1d94;
case 0x0c0b1d96u: goto P_0c0b1d96;
case 0x0c0b1d98u: goto P_0c0b1d98;
case 0x0c0b1d9au: goto P_0c0b1d9a;
case 0x0c0b1d9cu: goto P_0c0b1d9c;
case 0x0c0b1d9eu: goto P_0c0b1d9e;
case 0x0c0b1da0u: goto P_0c0b1da0;
case 0x0c0b1da2u: goto P_0c0b1da2;
case 0x0c0b1da4u: goto P_0c0b1da4;
case 0x0c0b1da6u: goto P_0c0b1da6;
case 0x0c0b1da8u: goto P_0c0b1da8;
case 0x0c0b1daau: goto P_0c0b1daa;
case 0x0c0b1dacu: goto P_0c0b1dac;
case 0x0c0b1daeu: goto P_0c0b1dae;
case 0x0c0b1db0u: goto P_0c0b1db0;
case 0x0c0b1db2u: goto P_0c0b1db2;
case 0x0c0b1db4u: goto P_0c0b1db4;
case 0x0c0b1db6u: goto P_0c0b1db6;
case 0x0c0b1db8u: goto P_0c0b1db8;
case 0x0c0b1dbau: goto P_0c0b1dba;
case 0x0c0b1dbcu: goto P_0c0b1dbc;
case 0x0c0b1dbeu: goto P_0c0b1dbe;
case 0x0c0b1dc0u: goto P_0c0b1dc0;
case 0x0c0b1dc2u: goto P_0c0b1dc2;
case 0x0c0b1dc4u: goto P_0c0b1dc4;
case 0x0c0b1dc6u: goto P_0c0b1dc6;
case 0x0c0b1dc8u: goto P_0c0b1dc8;
case 0x0c0b1dcau: goto P_0c0b1dca;
case 0x0c0b1dccu: goto P_0c0b1dcc;
case 0x0c0b1dceu: goto P_0c0b1dce;
case 0x0c0b1dd0u: goto P_0c0b1dd0;
case 0x0c0b1dd2u: goto P_0c0b1dd2;
case 0x0c0b1dd4u: goto P_0c0b1dd4;
case 0x0c0b1dd6u: goto P_0c0b1dd6;
case 0x0c0b1dd8u: goto P_0c0b1dd8;
case 0x0c0b1ddau: goto P_0c0b1dda;
case 0x0c0b1ddcu: goto P_0c0b1ddc;
case 0x0c0b1ddeu: goto P_0c0b1dde;
case 0x0c0b1de0u: goto P_0c0b1de0;
case 0x0c0b1de2u: goto P_0c0b1de2;
case 0x0c0b1de4u: goto P_0c0b1de4;
case 0x0c0b1de6u: goto P_0c0b1de6;
case 0x0c0b1de8u: goto P_0c0b1de8;
case 0x0c0b1deau: goto P_0c0b1dea;
case 0x0c0b1decu: goto P_0c0b1dec;
case 0x0c0b1deeu: goto P_0c0b1dee;
case 0x0c0b1df0u: goto P_0c0b1df0;
case 0x0c0b1df2u: goto P_0c0b1df2;
case 0x0c0b1df4u: goto P_0c0b1df4;
case 0x0c0b1df6u: goto P_0c0b1df6;
case 0x0c0b1df8u: goto P_0c0b1df8;
case 0x0c0b1dfau: goto P_0c0b1dfa;
case 0x0c0b1dfcu: goto P_0c0b1dfc;
case 0x0c0b1dfeu: goto P_0c0b1dfe;
case 0x0c0b1e00u: goto P_0c0b1e00;
case 0x0c0b1e02u: goto P_0c0b1e02;
case 0x0c0b1e04u: goto P_0c0b1e04;
case 0x0c0b1e06u: goto P_0c0b1e06;
case 0x0c0b1e08u: goto P_0c0b1e08;
case 0x0c0b1e0au: goto P_0c0b1e0a;
case 0x0c0b1e0cu: goto P_0c0b1e0c;
case 0x0c0b1e0eu: goto P_0c0b1e0e;
case 0x0c0b1e10u: goto P_0c0b1e10;
case 0x0c0b1e12u: goto P_0c0b1e12;
case 0x0c0b1e14u: goto P_0c0b1e14;
case 0x0c0b1e16u: goto P_0c0b1e16;
case 0x0c0b1e18u: goto P_0c0b1e18;
case 0x0c0b1e1au: goto P_0c0b1e1a;
case 0x0c0b1e1cu: goto P_0c0b1e1c;
case 0x0c0b1e1eu: goto P_0c0b1e1e;
case 0x0c0b1e20u: goto P_0c0b1e20;
case 0x0c0b1e22u: goto P_0c0b1e22;
case 0x0c0b1e24u: goto P_0c0b1e24;
case 0x0c0b1e26u: goto P_0c0b1e26;
case 0x0c0b1e28u: goto P_0c0b1e28;
case 0x0c0b1e64u: goto P_0c0b1e64;
case 0x0c0b1e66u: goto P_0c0b1e66;
case 0x0c0b1e68u: goto P_0c0b1e68;
case 0x0c0b1e6au: goto P_0c0b1e6a;
case 0x0c0b1e6cu: goto P_0c0b1e6c;
case 0x0c0b1e6eu: goto P_0c0b1e6e;
case 0x0c0b1e70u: goto P_0c0b1e70;
case 0x0c0b1e72u: goto P_0c0b1e72;
case 0x0c0b1e74u: goto P_0c0b1e74;
case 0x0c0b1e76u: goto P_0c0b1e76;
case 0x0c0b1e78u: goto P_0c0b1e78;
case 0x0c0b1e7au: goto P_0c0b1e7a;
case 0x0c0b1e7cu: goto P_0c0b1e7c;
case 0x0c0b1e7eu: goto P_0c0b1e7e;
case 0x0c0b1e80u: goto P_0c0b1e80;
case 0x0c0b1e82u: goto P_0c0b1e82;
case 0x0c0b1e84u: goto P_0c0b1e84;
case 0x0c0b1e86u: goto P_0c0b1e86;
case 0x0c0b1e88u: goto P_0c0b1e88;
case 0x0c0b1e8au: goto P_0c0b1e8a;
case 0x0c0b1e8cu: goto P_0c0b1e8c;
case 0x0c0b1e8eu: goto P_0c0b1e8e;
case 0x0c0b1e90u: goto P_0c0b1e90;
case 0x0c0b1e92u: goto P_0c0b1e92;
case 0x0c0b1e94u: goto P_0c0b1e94;
case 0x0c0b1e96u: goto P_0c0b1e96;
case 0x0c0b1e98u: goto P_0c0b1e98;
case 0x0c0b1e9au: goto P_0c0b1e9a;
case 0x0c0b1e9cu: goto P_0c0b1e9c;
case 0x0c0b1e9eu: goto P_0c0b1e9e;
case 0x0c0b1ea0u: goto P_0c0b1ea0;
case 0x0c0b1ea2u: goto P_0c0b1ea2;
case 0x0c0b1ea4u: goto P_0c0b1ea4;
case 0x0c0b1ea6u: goto P_0c0b1ea6;
case 0x0c0b1ea8u: goto P_0c0b1ea8;
case 0x0c0b1eaau: goto P_0c0b1eaa;
case 0x0c0b1eacu: goto P_0c0b1eac;
case 0x0c0b1eaeu: goto P_0c0b1eae;
case 0x0c0b1ec0u: goto P_0c0b1ec0;
case 0x0c0b1ec2u: goto P_0c0b1ec2;
case 0x0c0b1ec4u: goto P_0c0b1ec4;
case 0x0c0b1ec6u: goto P_0c0b1ec6;
case 0x0c0b1ec8u: goto P_0c0b1ec8;
case 0x0c0b1ecau: goto P_0c0b1eca;
case 0x0c0b1eccu: goto P_0c0b1ecc;
case 0x0c0b1eceu: goto P_0c0b1ece;
case 0x0c0b1ed0u: goto P_0c0b1ed0;
case 0x0c0b1ed2u: goto P_0c0b1ed2;
case 0x0c0b1ed4u: goto P_0c0b1ed4;
case 0x0c0b1ed6u: goto P_0c0b1ed6;
case 0x0c0b1ed8u: goto P_0c0b1ed8;
case 0x0c0b1edau: goto P_0c0b1eda;
case 0x0c0b1edcu: goto P_0c0b1edc;
case 0x0c0b1edeu: goto P_0c0b1ede;
case 0x0c0b1ee0u: goto P_0c0b1ee0;
case 0x0c0b1ee2u: goto P_0c0b1ee2;
case 0x0c0b1ee4u: goto P_0c0b1ee4;
case 0x0c0b1ee6u: goto P_0c0b1ee6;
case 0x0c0b1ee8u: goto P_0c0b1ee8;
case 0x0c0b1eeau: goto P_0c0b1eea;
case 0x0c0b1eecu: goto P_0c0b1eec;
case 0x0c0b1eeeu: goto P_0c0b1eee;
case 0x0c0b1ef0u: goto P_0c0b1ef0;
case 0x0c0b1ef2u: goto P_0c0b1ef2;
case 0x0c0b1ef4u: goto P_0c0b1ef4;
case 0x0c0b1ef6u: goto P_0c0b1ef6;
case 0x0c0b1ef8u: goto P_0c0b1ef8;
case 0x0c0b1efau: goto P_0c0b1efa;
case 0x0c0b1efcu: goto P_0c0b1efc;
case 0x0c0b1efeu: goto P_0c0b1efe;
case 0x0c0b1f00u: goto P_0c0b1f00;
case 0x0c0b1f02u: goto P_0c0b1f02;
case 0x0c0b1f04u: goto P_0c0b1f04;
case 0x0c0b1f06u: goto P_0c0b1f06;
case 0x0c0b1f08u: goto P_0c0b1f08;
case 0x0c0b1f0au: goto P_0c0b1f0a;
case 0x0c0b1f0cu: goto P_0c0b1f0c;
case 0x0c0b1f0eu: goto P_0c0b1f0e;
case 0x0c0b1f10u: goto P_0c0b1f10;
case 0x0c0b1f12u: goto P_0c0b1f12;
case 0x0c0b1f14u: goto P_0c0b1f14;
case 0x0c0b1f16u: goto P_0c0b1f16;
case 0x0c0b1f18u: goto P_0c0b1f18;
case 0x0c0b1f1au: goto P_0c0b1f1a;
case 0x0c0b1f1cu: goto P_0c0b1f1c;
case 0x0c0b1f1eu: goto P_0c0b1f1e;
case 0x0c0b1f20u: goto P_0c0b1f20;
case 0x0c0b1f22u: goto P_0c0b1f22;
case 0x0c0b1f24u: goto P_0c0b1f24;
case 0x0c0b1f26u: goto P_0c0b1f26;
case 0x0c0b1f28u: goto P_0c0b1f28;
case 0x0c0b1f2au: goto P_0c0b1f2a;
case 0x0c0b1f2cu: goto P_0c0b1f2c;
case 0x0c0b1f2eu: goto P_0c0b1f2e;
case 0x0c0b1f30u: goto P_0c0b1f30;
case 0x0c0b1f32u: goto P_0c0b1f32;
case 0x0c0b1f34u: goto P_0c0b1f34;
case 0x0c0b1f36u: goto P_0c0b1f36;
case 0x0c0b1f38u: goto P_0c0b1f38;
case 0x0c0b1f3au: goto P_0c0b1f3a;
case 0x0c0b1f3cu: goto P_0c0b1f3c;
case 0x0c0b1f3eu: goto P_0c0b1f3e;
case 0x0c0b1f40u: goto P_0c0b1f40;
case 0x0c0b1f42u: goto P_0c0b1f42;
case 0x0c0b1f44u: goto P_0c0b1f44;
case 0x0c0b1f46u: goto P_0c0b1f46;
case 0x0c0b1f48u: goto P_0c0b1f48;
case 0x0c0b1f4au: goto P_0c0b1f4a;
case 0x0c0b1f4cu: goto P_0c0b1f4c;
case 0x0c0b1f4eu: goto P_0c0b1f4e;
case 0x0c0b1f50u: goto P_0c0b1f50;
case 0x0c0b1f52u: goto P_0c0b1f52;
case 0x0c0b1f54u: goto P_0c0b1f54;
case 0x0c0b1f56u: goto P_0c0b1f56;
case 0x0c0b1f58u: goto P_0c0b1f58;
case 0x0c0b1f5au: goto P_0c0b1f5a;
case 0x0c0b1f5cu: goto P_0c0b1f5c;
case 0x0c0b1f5eu: goto P_0c0b1f5e;
case 0x0c0b1f60u: goto P_0c0b1f60;
case 0x0c0b1f62u: goto P_0c0b1f62;
case 0x0c0b1f64u: goto P_0c0b1f64;
case 0x0c0b1f66u: goto P_0c0b1f66;
case 0x0c0b1f68u: goto P_0c0b1f68;
case 0x0c0b1f6au: goto P_0c0b1f6a;
case 0x0c0b1f6cu: goto P_0c0b1f6c;
case 0x0c0b1f6eu: goto P_0c0b1f6e;
case 0x0c0b1f70u: goto P_0c0b1f70;
case 0x0c0b1f72u: goto P_0c0b1f72;
case 0x0c0b1f74u: goto P_0c0b1f74;
case 0x0c0b1f76u: goto P_0c0b1f76;
case 0x0c0b1f78u: goto P_0c0b1f78;
case 0x0c0b1f7au: goto P_0c0b1f7a;
case 0x0c0b1f7cu: goto P_0c0b1f7c;
case 0x0c0b1f7eu: goto P_0c0b1f7e;
case 0x0c0b1f80u: goto P_0c0b1f80;
case 0x0c0b1f82u: goto P_0c0b1f82;
case 0x0c0b1f84u: goto P_0c0b1f84;
case 0x0c0b1f86u: goto P_0c0b1f86;
case 0x0c0b1f88u: goto P_0c0b1f88;
case 0x0c0b1f8au: goto P_0c0b1f8a;
case 0x0c0b1f8cu: goto P_0c0b1f8c;
case 0x0c0b1f8eu: goto P_0c0b1f8e;
case 0x0c0b1f90u: goto P_0c0b1f90;
case 0x0c0b1f92u: goto P_0c0b1f92;
case 0x0c0b1f94u: goto P_0c0b1f94;
case 0x0c0b1f96u: goto P_0c0b1f96;
case 0x0c0b1f98u: goto P_0c0b1f98;
case 0x0c0b1f9au: goto P_0c0b1f9a;
case 0x0c0b1f9cu: goto P_0c0b1f9c;
case 0x0c0b1f9eu: goto P_0c0b1f9e;
case 0x0c0b1fa0u: goto P_0c0b1fa0;
case 0x0c0b1fa2u: goto P_0c0b1fa2;
case 0x0c0b1fa4u: goto P_0c0b1fa4;
case 0x0c0b1fa6u: goto P_0c0b1fa6;
case 0x0c0b1fa8u: goto P_0c0b1fa8;
case 0x0c0b1faau: goto P_0c0b1faa;
case 0x0c0b1facu: goto P_0c0b1fac;
case 0x0c0b1faeu: goto P_0c0b1fae;
case 0x0c0b1fb0u: goto P_0c0b1fb0;
case 0x0c0b1fb2u: goto P_0c0b1fb2;
case 0x0c0b1fb4u: goto P_0c0b1fb4;
case 0x0c0b1fb6u: goto P_0c0b1fb6;
case 0x0c0b1fb8u: goto P_0c0b1fb8;
case 0x0c0b1fbau: goto P_0c0b1fba;
case 0x0c0b1fbcu: goto P_0c0b1fbc;
case 0x0c0b1fbeu: goto P_0c0b1fbe;
case 0x0c0b1fc0u: goto P_0c0b1fc0;
case 0x0c0b1fc2u: goto P_0c0b1fc2;
case 0x0c0b1fc4u: goto P_0c0b1fc4;
case 0x0c0b1fc6u: goto P_0c0b1fc6;
case 0x0c0b1fc8u: goto P_0c0b1fc8;
case 0x0c0b1fcau: goto P_0c0b1fca;
case 0x0c0b1fccu: goto P_0c0b1fcc;
case 0x0c0b1fceu: goto P_0c0b1fce;
case 0x0c0b1fd0u: goto P_0c0b1fd0;
case 0x0c0b1fd2u: goto P_0c0b1fd2;
case 0x0c0b1fd4u: goto P_0c0b1fd4;
case 0x0c0b1fd6u: goto P_0c0b1fd6;
case 0x0c0b1fd8u: goto P_0c0b1fd8;
case 0x0c0b1fdau: goto P_0c0b1fda;
case 0x0c0b1fdcu: goto P_0c0b1fdc;
case 0x0c0b1fdeu: goto P_0c0b1fde;
case 0x0c0b1fe0u: goto P_0c0b1fe0;
case 0x0c0b1fe2u: goto P_0c0b1fe2;
case 0x0c0b1fe4u: goto P_0c0b1fe4;
case 0x0c0b1fe6u: goto P_0c0b1fe6;
case 0x0c0b1fe8u: goto P_0c0b1fe8;
case 0x0c0b1feau: goto P_0c0b1fea;
case 0x0c0b1fecu: goto P_0c0b1fec;
case 0x0c0b1feeu: goto P_0c0b1fee;
case 0x0c0b1ff0u: goto P_0c0b1ff0;
case 0x0c0b1ff2u: goto P_0c0b1ff2;
case 0x0c0b1ff4u: goto P_0c0b1ff4;
case 0x0c0b1ff6u: goto P_0c0b1ff6;
case 0x0c0b1ff8u: goto P_0c0b1ff8;
case 0x0c0b1ffau: goto P_0c0b1ffa;
case 0x0c0b1ffcu: goto P_0c0b1ffc;
case 0x0c0b1ffeu: goto P_0c0b1ffe;
case 0x0c0b2000u: goto P_0c0b2000;
case 0x0c0b2002u: goto P_0c0b2002;
case 0x0c0b2004u: goto P_0c0b2004;
case 0x0c0b2006u: goto P_0c0b2006;
case 0x0c0b2008u: goto P_0c0b2008;
case 0x0c0b200au: goto P_0c0b200a;
case 0x0c0b200cu: goto P_0c0b200c;
case 0x0c0b200eu: goto P_0c0b200e;
case 0x0c0b2010u: goto P_0c0b2010;
case 0x0c0b2012u: goto P_0c0b2012;
case 0x0c0b2014u: goto P_0c0b2014;
case 0x0c0b2016u: goto P_0c0b2016;
case 0x0c0b2018u: goto P_0c0b2018;
case 0x0c0b201au: goto P_0c0b201a;
case 0x0c0b201cu: goto P_0c0b201c;
case 0x0c0b201eu: goto P_0c0b201e;
case 0x0c0b2020u: goto P_0c0b2020;
case 0x0c0b2022u: goto P_0c0b2022;
case 0x0c0b2024u: goto P_0c0b2024;
case 0x0c0b2026u: goto P_0c0b2026;
case 0x0c0b2028u: goto P_0c0b2028;
case 0x0c0b202au: goto P_0c0b202a;
case 0x0c0b202cu: goto P_0c0b202c;
case 0x0c0b202eu: goto P_0c0b202e;
case 0x0c0b2030u: goto P_0c0b2030;
case 0x0c0b2032u: goto P_0c0b2032;
case 0x0c0b2034u: goto P_0c0b2034;
case 0x0c0b2036u: goto P_0c0b2036;
case 0x0c0b2038u: goto P_0c0b2038;
case 0x0c0b203au: goto P_0c0b203a;
case 0x0c0b203cu: goto P_0c0b203c;
case 0x0c0b203eu: goto P_0c0b203e;
case 0x0c0b2040u: goto P_0c0b2040;
case 0x0c0b2042u: goto P_0c0b2042;
case 0x0c0b2044u: goto P_0c0b2044;
case 0x0c0b2046u: goto P_0c0b2046;
case 0x0c0b2048u: goto P_0c0b2048;
case 0x0c0b204au: goto P_0c0b204a;
case 0x0c0b204cu: goto P_0c0b204c;
case 0x0c0b204eu: goto P_0c0b204e;
case 0x0c0b2050u: goto P_0c0b2050;
case 0x0c0b2052u: goto P_0c0b2052;
case 0x0c0b2054u: goto P_0c0b2054;
case 0x0c0b2056u: goto P_0c0b2056;
case 0x0c0b2058u: goto P_0c0b2058;
case 0x0c0b205au: goto P_0c0b205a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b1cc4: /* original 2fe6, guest PC 0x0c0b1cc4 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1cc6;
P_0c0b1cc6: /* original 6e43, guest PC 0x0c0b1cc6 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc6u; return 0; }
r[14]=r[4];
goto P_0c0b1cc8;
P_0c0b1cc8: /* original 2fd6, guest PC 0x0c0b1cc8 */
if(!s->budget--) { s->failed_pc=0x0c0b1cc8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1cca;
P_0c0b1cca: /* original 2fc6, guest PC 0x0c0b1cca */
if(!s->budget--) { s->failed_pc=0x0c0b1ccau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ccc;
P_0c0b1ccc: /* original 2fb6, guest PC 0x0c0b1ccc */
if(!s->budget--) { s->failed_pc=0x0c0b1cccu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1cce;
P_0c0b1cce: /* original 2fa6, guest PC 0x0c0b1cce */
if(!s->budget--) { s->failed_pc=0x0c0b1cceu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1cd0;
P_0c0b1cd0: /* original 2f96, guest PC 0x0c0b1cd0 */
if(!s->budget--) { s->failed_pc=0x0c0b1cd0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1cd2;
P_0c0b1cd2: /* original 2f86, guest PC 0x0c0b1cd2 */
if(!s->budget--) { s->failed_pc=0x0c0b1cd2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1cd4;
P_0c0b1cd4: /* original fffb, guest PC 0x0c0b1cd4 */
if(!s->budget--) { s->failed_pc=0x0c0b1cd4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0b1cd6;
P_0c0b1cd6: /* original ffeb, guest PC 0x0c0b1cd6 */
if(!s->budget--) { s->failed_pc=0x0c0b1cd6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0b1cd8;
P_0c0b1cd8: /* original 4f22, guest PC 0x0c0b1cd8 */
if(!s->budget--) { s->failed_pc=0x0c0b1cd8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1cda;
P_0c0b1cda: /* original 900b, guest PC 0x0c0b1cda */
if(!s->budget--) { s->failed_pc=0x0c0b1cdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cf4u,2);
goto P_0c0b1cdc;
P_0c0b1cdc: /* original 3f0c, guest PC 0x0c0b1cdc */
if(!s->budget--) { s->failed_pc=0x0c0b1cdcu; return 0; }
r[15]+=r[0];
goto P_0c0b1cde;
P_0c0b1cde: /* original 84e4, guest PC 0x0c0b1cde */
if(!s->budget--) { s->failed_pc=0x0c0b1cdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0b1ce0;
P_0c0b1ce0: /* original 2008, guest PC 0x0c0b1ce0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ce0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0b1ce2;
P_0c0b1ce2: /* original 8b19, guest PC 0x0c0b1ce2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ce2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1d18; }
goto P_0c0b1ce4;
P_0c0b1ce4: /* original 9807, guest PC 0x0c0b1ce4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ce4u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cf6u,2);
goto P_0c0b1ce6;
P_0c0b1ce6: /* original a018, guest PC 0x0c0b1ce6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ce6u; return 0; }
goto P_0c0b1d1a;
P_0c0b1ce8: /* original 0009, guest PC 0x0c0b1ce8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ce8u; return 0; }
if(!vf3_matrix_family(0x0c0b1ceau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1ceau; return 0; } return 1;
P_0c0b1d18: /* original 9887, guest PC 0x0c0b1d18 */
if(!s->budget--) { s->failed_pc=0x0c0b1d18u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e2au,2);
goto P_0c0b1d1a;
P_0c0b1d1a: /* original 65f3, guest PC 0x0c0b1d1a */
if(!s->budget--) { s->failed_pc=0x0c0b1d1au; return 0; }
r[5]=r[15];
goto P_0c0b1d1c;
P_0c0b1d1c: /* original 66f3, guest PC 0x0c0b1d1c */
if(!s->budget--) { s->failed_pc=0x0c0b1d1cu; return 0; }
r[6]=r[15];
goto P_0c0b1d1e;
P_0c0b1d1e: /* original 9385, guest PC 0x0c0b1d1e */
if(!s->budget--) { s->failed_pc=0x0c0b1d1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e2cu,2);
goto P_0c0b1d20;
P_0c0b1d20: /* original 760c, guest PC 0x0c0b1d20 */
if(!s->budget--) { s->failed_pc=0x0c0b1d20u; return 0; }
r[6]+=0x0000000cu;
goto P_0c0b1d22;
P_0c0b1d22: /* original e700, guest PC 0x0c0b1d22 */
if(!s->budget--) { s->failed_pc=0x0c0b1d22u; return 0; }
r[7]=0x00000000u;
goto P_0c0b1d24;
P_0c0b1d24: /* original 757c, guest PC 0x0c0b1d24 */
if(!s->budget--) { s->failed_pc=0x0c0b1d24u; return 0; }
r[5]+=0x0000007cu;
goto P_0c0b1d26;
P_0c0b1d26: /* original 6473, guest PC 0x0c0b1d26 */
if(!s->budget--) { s->failed_pc=0x0c0b1d26u; return 0; }
r[4]=r[7];
goto P_0c0b1d28;
P_0c0b1d28: /* original ed1c, guest PC 0x0c0b1d28 */
if(!s->budget--) { s->failed_pc=0x0c0b1d28u; return 0; }
r[13]=0x0000001cu;
goto P_0c0b1d2a;
P_0c0b1d2a: /* original 1f31, guest PC 0x0c0b1d2a */
if(!s->budget--) { s->failed_pc=0x0c0b1d2au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0b1d2c;
P_0c0b1d2c: /* original 1f52, guest PC 0x0c0b1d2c */
if(!s->budget--) { s->failed_pc=0x0c0b1d2cu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0b1d2e;
P_0c0b1d2e: /* original 2f62, guest PC 0x0c0b1d2e */
if(!s->budget--) { s->failed_pc=0x0c0b1d2eu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0b1d30;
P_0c0b1d30: /* original 9c7d, guest PC 0x0c0b1d30 */
if(!s->budget--) { s->failed_pc=0x0c0b1d30u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e2eu,2);
goto P_0c0b1d32;
P_0c0b1d32: /* original f49d, guest PC 0x0c0b1d32 */
if(!s->budget--) { s->failed_pc=0x0c0b1d32u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0b1d34;
P_0c0b1d34: /* original 3cec, guest PC 0x0c0b1d34 */
if(!s->budget--) { s->failed_pc=0x0c0b1d34u; return 0; }
r[12]+=r[14];
goto P_0c0b1d36;
P_0c0b1d36: /* original 907b, guest PC 0x0c0b1d36 */
if(!s->budget--) { s->failed_pc=0x0c0b1d36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e30u,2);
goto P_0c0b1d38;
P_0c0b1d38: /* original 03ee, guest PC 0x0c0b1d38 */
if(!s->budget--) { s->failed_pc=0x0c0b1d38u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0b1d3a;
P_0c0b1d3a: /* original 334c, guest PC 0x0c0b1d3a */
if(!s->budget--) { s->failed_pc=0x0c0b1d3au; return 0; }
r[3]+=r[4];
goto P_0c0b1d3c;
P_0c0b1d3c: /* original f338, guest PC 0x0c0b1d3c */
if(!s->budget--) { s->failed_pc=0x0c0b1d3cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0b1d3e;
P_0c0b1d3e: /* original f53a, guest PC 0x0c0b1d3e */
if(!s->budget--) { s->failed_pc=0x0c0b1d3eu; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c0b1d40;
P_0c0b1d40: /* original 03ee, guest PC 0x0c0b1d40 */
if(!s->budget--) { s->failed_pc=0x0c0b1d40u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0b1d42;
P_0c0b1d42: /* original e004, guest PC 0x0c0b1d42 */
if(!s->budget--) { s->failed_pc=0x0c0b1d42u; return 0; }
r[0]=0x00000004u;
goto P_0c0b1d44;
P_0c0b1d44: /* original 334c, guest PC 0x0c0b1d44 */
if(!s->budget--) { s->failed_pc=0x0c0b1d44u; return 0; }
r[3]+=r[4];
goto P_0c0b1d46;
P_0c0b1d46: /* original f336, guest PC 0x0c0b1d46 */
if(!s->budget--) { s->failed_pc=0x0c0b1d46u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0b1d48;
P_0c0b1d48: /* original f537, guest PC 0x0c0b1d48 */
if(!s->budget--) { s->failed_pc=0x0c0b1d48u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0b1d4a;
P_0c0b1d4a: /* original 9071, guest PC 0x0c0b1d4a */
if(!s->budget--) { s->failed_pc=0x0c0b1d4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e30u,2);
goto P_0c0b1d4c;
P_0c0b1d4c: /* original 03ee, guest PC 0x0c0b1d4c */
if(!s->budget--) { s->failed_pc=0x0c0b1d4cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0b1d4e;
P_0c0b1d4e: /* original e008, guest PC 0x0c0b1d4e */
if(!s->budget--) { s->failed_pc=0x0c0b1d4eu; return 0; }
r[0]=0x00000008u;
goto P_0c0b1d50;
P_0c0b1d50: /* original 334c, guest PC 0x0c0b1d50 */
if(!s->budget--) { s->failed_pc=0x0c0b1d50u; return 0; }
r[3]+=r[4];
goto P_0c0b1d52;
P_0c0b1d52: /* original f336, guest PC 0x0c0b1d52 */
if(!s->budget--) { s->failed_pc=0x0c0b1d52u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0b1d54;
P_0c0b1d54: /* original f537, guest PC 0x0c0b1d54 */
if(!s->budget--) { s->failed_pc=0x0c0b1d54u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0b1d56;
P_0c0b1d56: /* original f3c9, guest PC 0x0c0b1d56 */
if(!s->budget--) { s->failed_pc=0x0c0b1d56u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
r[12]+=(r[18]&0x100000u)?8:4;
goto P_0c0b1d58;
P_0c0b1d58: /* original f28d, guest PC 0x0c0b1d58 */
if(!s->budget--) { s->failed_pc=0x0c0b1d58u; return 0; }
fr[2]=0;
goto P_0c0b1d5a;
P_0c0b1d5a: /* original f324, guest PC 0x0c0b1d5a */
if(!s->budget--) { s->failed_pc=0x0c0b1d5au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])==as_float(fr[2]))!=0);
goto P_0c0b1d5c;
P_0c0b1d5c: /* original 8f01, guest PC 0x0c0b1d5c */
if(!s->budget--) { s->failed_pc=0x0c0b1d5cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[6]);
if(!cond) { goto P_0c0b1d62; }
goto P_0c0b1d60;
P_0c0b1d5e: /* original f63a, guest PC 0x0c0b1d5e */
if(!s->budget--) { s->failed_pc=0x0c0b1d5eu; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c0b1d60;
P_0c0b1d60: /* original f64a, guest PC 0x0c0b1d60 */
if(!s->budget--) { s->failed_pc=0x0c0b1d60u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0b1d62;
P_0c0b1d62: /* original 7701, guest PC 0x0c0b1d62 */
if(!s->budget--) { s->failed_pc=0x0c0b1d62u; return 0; }
r[7]+=0x00000001u;
goto P_0c0b1d64;
P_0c0b1d64: /* original 37d3, guest PC 0x0c0b1d64 */
if(!s->budget--) { s->failed_pc=0x0c0b1d64u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[13])!=0);
goto P_0c0b1d66;
P_0c0b1d66: /* original 750c, guest PC 0x0c0b1d66 */
if(!s->budget--) { s->failed_pc=0x0c0b1d66u; return 0; }
r[5]+=0x0000000cu;
goto P_0c0b1d68;
P_0c0b1d68: /* original 7604, guest PC 0x0c0b1d68 */
if(!s->budget--) { s->failed_pc=0x0c0b1d68u; return 0; }
r[6]+=0x00000004u;
goto P_0c0b1d6a;
P_0c0b1d6a: /* original 8fe4, guest PC 0x0c0b1d6a */
if(!s->budget--) { s->failed_pc=0x0c0b1d6au; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c0b1d36; }
goto P_0c0b1d6e;
P_0c0b1d6c: /* original 740c, guest PC 0x0c0b1d6c */
if(!s->budget--) { s->failed_pc=0x0c0b1d6cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c0b1d6e;
P_0c0b1d6e: /* original d333, guest PC 0x0c0b1d6e */
if(!s->budget--) { s->failed_pc=0x0c0b1d6eu; return 0; }
r[3]=read(ram,0x0c0b1e3cu,4);
goto P_0c0b1d70;
P_0c0b1d70: /* original 430b, guest PC 0x0c0b1d70 */
if(!s->budget--) { s->failed_pc=0x0c0b1d70u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1d74u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1d74u) { target=s->pc; goto dispatch; }
goto P_0c0b1d74;
P_0c0b1d72: /* original e400, guest PC 0x0c0b1d72 */
if(!s->budget--) { s->failed_pc=0x0c0b1d72u; return 0; }
r[4]=0x00000000u;
goto P_0c0b1d74;
P_0c0b1d74: /* original 935d, guest PC 0x0c0b1d74 */
if(!s->budget--) { s->failed_pc=0x0c0b1d74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e32u,2);
goto P_0c0b1d76;
P_0c0b1d76: /* original c733, guest PC 0x0c0b1d76 */
if(!s->budget--) { s->failed_pc=0x0c0b1d76u; return 0; }
r[0]=code_base|0x000b1e44u;
goto P_0c0b1d78;
P_0c0b1d78: /* original 5af2, guest PC 0x0c0b1d78 */
if(!s->budget--) { s->failed_pc=0x0c0b1d78u; return 0; }
r[10]=read(ram,r[15]+8,4);
goto P_0c0b1d7a;
P_0c0b1d7a: /* original eb00, guest PC 0x0c0b1d7a */
if(!s->budget--) { s->failed_pc=0x0c0b1d7au; return 0; }
r[11]=0x00000000u;
goto P_0c0b1d7c;
P_0c0b1d7c: /* original 33ec, guest PC 0x0c0b1d7c */
if(!s->budget--) { s->failed_pc=0x0c0b1d7cu; return 0; }
r[3]+=r[14];
goto P_0c0b1d7e;
P_0c0b1d7e: /* original 69f2, guest PC 0x0c0b1d7e */
if(!s->budget--) { s->failed_pc=0x0c0b1d7eu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0b1d80;
P_0c0b1d80: /* original 2f32, guest PC 0x0c0b1d80 */
if(!s->budget--) { s->failed_pc=0x0c0b1d80u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b1d82;
P_0c0b1d82: /* original de2f, guest PC 0x0c0b1d82 */
if(!s->budget--) { s->failed_pc=0x0c0b1d82u; return 0; }
r[14]=read(ram,0x0c0b1e40u,4);
goto P_0c0b1d84;
P_0c0b1d84: /* original ff08, guest PC 0x0c0b1d84 */
if(!s->budget--) { s->failed_pc=0x0c0b1d84u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0b1d86;
P_0c0b1d86: /* original 64f2, guest PC 0x0c0b1d86 */
if(!s->budget--) { s->failed_pc=0x0c0b1d86u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1d88;
P_0c0b1d88: /* original 7404, guest PC 0x0c0b1d88 */
if(!s->budget--) { s->failed_pc=0x0c0b1d88u; return 0; }
r[4]+=0x00000004u;
goto P_0c0b1d8a;
P_0c0b1d8a: /* original 2f42, guest PC 0x0c0b1d8a */
if(!s->budget--) { s->failed_pc=0x0c0b1d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0b1d8c;
P_0c0b1d8c: /* original 74fc, guest PC 0x0c0b1d8c */
if(!s->budget--) { s->failed_pc=0x0c0b1d8cu; return 0; }
r[4]+=0xfffffffcu;
goto P_0c0b1d8e;
P_0c0b1d8e: /* original 6442, guest PC 0x0c0b1d8e */
if(!s->budget--) { s->failed_pc=0x0c0b1d8eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0b1d90;
P_0c0b1d90: /* original 2448, guest PC 0x0c0b1d90 */
if(!s->budget--) { s->failed_pc=0x0c0b1d90u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0b1d92;
P_0c0b1d92: /* original 8901, guest PC 0x0c0b1d92 */
if(!s->budget--) { s->failed_pc=0x0c0b1d92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1d98; }
goto P_0c0b1d94;
P_0c0b1d94: /* original a001, guest PC 0x0c0b1d94 */
if(!s->budget--) { s->failed_pc=0x0c0b1d94u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c0b1d9a;
P_0c0b1d96: /* original 5cf1, guest PC 0x0c0b1d96 */
if(!s->budget--) { s->failed_pc=0x0c0b1d96u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c0b1d98;
P_0c0b1d98: /* original 6c83, guest PC 0x0c0b1d98 */
if(!s->budget--) { s->failed_pc=0x0c0b1d98u; return 0; }
r[12]=r[8];
goto P_0c0b1d9a;
P_0c0b1d9a: /* original d22b, guest PC 0x0c0b1d9a */
if(!s->budget--) { s->failed_pc=0x0c0b1d9au; return 0; }
r[2]=read(ram,0x0c0b1e48u,4);
goto P_0c0b1d9c;
P_0c0b1d9c: /* original 420b, guest PC 0x0c0b1d9c */
if(!s->budget--) { s->failed_pc=0x0c0b1d9cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1da0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1da0u) { target=s->pc; goto dispatch; }
goto P_0c0b1da0;
P_0c0b1d9e: /* original 0009, guest PC 0x0c0b1d9e */
if(!s->budget--) { s->failed_pc=0x0c0b1d9eu; return 0; }
goto P_0c0b1da0;
P_0c0b1da0: /* original d32a, guest PC 0x0c0b1da0 */
if(!s->budget--) { s->failed_pc=0x0c0b1da0u; return 0; }
r[3]=read(ram,0x0c0b1e4cu,4);
goto P_0c0b1da2;
P_0c0b1da2: /* original 430b, guest PC 0x0c0b1da2 */
if(!s->budget--) { s->failed_pc=0x0c0b1da2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1da6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1da6u) { target=s->pc; goto dispatch; }
goto P_0c0b1da6;
P_0c0b1da4: /* original 64a3, guest PC 0x0c0b1da4 */
if(!s->budget--) { s->failed_pc=0x0c0b1da4u; return 0; }
r[4]=r[10];
goto P_0c0b1da6;
P_0c0b1da6: /* original fe99, guest PC 0x0c0b1da6 */
if(!s->budget--) { s->failed_pc=0x0c0b1da6u; return 0; }
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c0b1da8;
P_0c0b1da8: /* original f5ec, guest PC 0x0c0b1da8 */
if(!s->budget--) { s->failed_pc=0x0c0b1da8u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0b1daa;
P_0c0b1daa: /* original f6ec, guest PC 0x0c0b1daa */
if(!s->budget--) { s->failed_pc=0x0c0b1daau; return 0; }
vf3_matrix_move(s,6,14);
goto P_0c0b1dac;
P_0c0b1dac: /* original 4e0b, guest PC 0x0c0b1dac */
if(!s->budget--) { s->failed_pc=0x0c0b1dacu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b1db0u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1db0u) { target=s->pc; goto dispatch; }
goto P_0c0b1db0;
P_0c0b1dae: /* original f4ec, guest PC 0x0c0b1dae */
if(!s->budget--) { s->failed_pc=0x0c0b1daeu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0b1db0;
P_0c0b1db0: /* original f5fc, guest PC 0x0c0b1db0 */
if(!s->budget--) { s->failed_pc=0x0c0b1db0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0b1db2;
P_0c0b1db2: /* original f6fc, guest PC 0x0c0b1db2 */
if(!s->budget--) { s->failed_pc=0x0c0b1db2u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0b1db4;
P_0c0b1db4: /* original 4e0b, guest PC 0x0c0b1db4 */
if(!s->budget--) { s->failed_pc=0x0c0b1db4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b1db8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1db8u) { target=s->pc; goto dispatch; }
goto P_0c0b1db8;
P_0c0b1db6: /* original f4fc, guest PC 0x0c0b1db6 */
if(!s->budget--) { s->failed_pc=0x0c0b1db6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1db8;
P_0c0b1db8: /* original d225, guest PC 0x0c0b1db8 */
if(!s->budget--) { s->failed_pc=0x0c0b1db8u; return 0; }
r[2]=read(ram,0x0c0b1e50u,4);
goto P_0c0b1dba;
P_0c0b1dba: /* original 420b, guest PC 0x0c0b1dba */
if(!s->budget--) { s->failed_pc=0x0c0b1dbau; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1dbeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1dbeu) { target=s->pc; goto dispatch; }
goto P_0c0b1dbe;
P_0c0b1dbc: /* original 64c3, guest PC 0x0c0b1dbc */
if(!s->budget--) { s->failed_pc=0x0c0b1dbcu; return 0; }
r[4]=r[12];
goto P_0c0b1dbe;
P_0c0b1dbe: /* original 7b01, guest PC 0x0c0b1dbe */
if(!s->budget--) { s->failed_pc=0x0c0b1dbeu; return 0; }
r[11]+=0x00000001u;
goto P_0c0b1dc0;
P_0c0b1dc0: /* original 3bd3, guest PC 0x0c0b1dc0 */
if(!s->budget--) { s->failed_pc=0x0c0b1dc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[13])!=0);
goto P_0c0b1dc2;
P_0c0b1dc2: /* original 8fe0, guest PC 0x0c0b1dc2 */
if(!s->budget--) { s->failed_pc=0x0c0b1dc2u; return 0; }
cond=r[17]&1u;
r[10]+=0x0000000cu;
if(!cond) { goto P_0c0b1d86; }
goto P_0c0b1dc6;
P_0c0b1dc4: /* original 7a0c, guest PC 0x0c0b1dc4 */
if(!s->budget--) { s->failed_pc=0x0c0b1dc4u; return 0; }
r[10]+=0x0000000cu;
goto P_0c0b1dc6;
P_0c0b1dc6: /* original d223, guest PC 0x0c0b1dc6 */
if(!s->budget--) { s->failed_pc=0x0c0b1dc6u; return 0; }
r[2]=read(ram,0x0c0b1e54u,4);
goto P_0c0b1dc8;
P_0c0b1dc8: /* original 420b, guest PC 0x0c0b1dc8 */
if(!s->budget--) { s->failed_pc=0x0c0b1dc8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1dccu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1dccu) { target=s->pc; goto dispatch; }
goto P_0c0b1dcc;
P_0c0b1dca: /* original e401, guest PC 0x0c0b1dca */
if(!s->budget--) { s->failed_pc=0x0c0b1dcau; return 0; }
r[4]=0x00000001u;
goto P_0c0b1dcc;
P_0c0b1dcc: /* original d322, guest PC 0x0c0b1dcc */
if(!s->budget--) { s->failed_pc=0x0c0b1dccu; return 0; }
r[3]=read(ram,0x0c0b1e58u,4);
goto P_0c0b1dce;
P_0c0b1dce: /* original 430b, guest PC 0x0c0b1dce */
if(!s->budget--) { s->failed_pc=0x0c0b1dceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1dd2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1dd2u) { target=s->pc; goto dispatch; }
goto P_0c0b1dd2;
P_0c0b1dd0: /* original 0009, guest PC 0x0c0b1dd0 */
if(!s->budget--) { s->failed_pc=0x0c0b1dd0u; return 0; }
goto P_0c0b1dd2;
P_0c0b1dd2: /* original 912f, guest PC 0x0c0b1dd2 */
if(!s->budget--) { s->failed_pc=0x0c0b1dd2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e34u,2);
goto P_0c0b1dd4;
P_0c0b1dd4: /* original 3f1c, guest PC 0x0c0b1dd4 */
if(!s->budget--) { s->failed_pc=0x0c0b1dd4u; return 0; }
r[15]+=r[1];
goto P_0c0b1dd6;
P_0c0b1dd6: /* original 4f26, guest PC 0x0c0b1dd6 */
if(!s->budget--) { s->failed_pc=0x0c0b1dd6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1dd8;
P_0c0b1dd8: /* original fef9, guest PC 0x0c0b1dd8 */
if(!s->budget--) { s->failed_pc=0x0c0b1dd8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0b1dda;
P_0c0b1dda: /* original fff9, guest PC 0x0c0b1dda */
if(!s->budget--) { s->failed_pc=0x0c0b1ddau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0b1ddc;
P_0c0b1ddc: /* original 68f6, guest PC 0x0c0b1ddc */
if(!s->budget--) { s->failed_pc=0x0c0b1ddcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0b1dde;
P_0c0b1dde: /* original 69f6, guest PC 0x0c0b1dde */
if(!s->budget--) { s->failed_pc=0x0c0b1ddeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b1de0;
P_0c0b1de0: /* original 6af6, guest PC 0x0c0b1de0 */
if(!s->budget--) { s->failed_pc=0x0c0b1de0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b1de2;
P_0c0b1de2: /* original 6bf6, guest PC 0x0c0b1de2 */
if(!s->budget--) { s->failed_pc=0x0c0b1de2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b1de4;
P_0c0b1de4: /* original 6cf6, guest PC 0x0c0b1de4 */
if(!s->budget--) { s->failed_pc=0x0c0b1de4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1de6;
P_0c0b1de6: /* original 6df6, guest PC 0x0c0b1de6 */
if(!s->budget--) { s->failed_pc=0x0c0b1de6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1de8;
P_0c0b1de8: /* original 000b, guest PC 0x0c0b1de8 */
if(!s->budget--) { s->failed_pc=0x0c0b1de8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1dea: /* original 6ef6, guest PC 0x0c0b1dea */
if(!s->budget--) { s->failed_pc=0x0c0b1deau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0b1dec;
P_0c0b1dec: /* original 2fe6, guest PC 0x0c0b1dec */
if(!s->budget--) { s->failed_pc=0x0c0b1decu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1dee;
P_0c0b1dee: /* original 6e43, guest PC 0x0c0b1dee */
if(!s->budget--) { s->failed_pc=0x0c0b1deeu; return 0; }
r[14]=r[4];
goto P_0c0b1df0;
P_0c0b1df0: /* original 2fd6, guest PC 0x0c0b1df0 */
if(!s->budget--) { s->failed_pc=0x0c0b1df0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1df2;
P_0c0b1df2: /* original e061, guest PC 0x0c0b1df2 */
if(!s->budget--) { s->failed_pc=0x0c0b1df2u; return 0; }
r[0]=0x00000061u;
goto P_0c0b1df4;
P_0c0b1df4: /* original 2fc6, guest PC 0x0c0b1df4 */
if(!s->budget--) { s->failed_pc=0x0c0b1df4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1df6;
P_0c0b1df6: /* original 2fb6, guest PC 0x0c0b1df6 */
if(!s->budget--) { s->failed_pc=0x0c0b1df6u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1df8;
P_0c0b1df8: /* original 2fa6, guest PC 0x0c0b1df8 */
if(!s->budget--) { s->failed_pc=0x0c0b1df8u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1dfa;
P_0c0b1dfa: /* original 2f96, guest PC 0x0c0b1dfa */
if(!s->budget--) { s->failed_pc=0x0c0b1dfau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1dfc;
P_0c0b1dfc: /* original 6943, guest PC 0x0c0b1dfc */
if(!s->budget--) { s->failed_pc=0x0c0b1dfcu; return 0; }
r[9]=r[4];
goto P_0c0b1dfe;
P_0c0b1dfe: /* original 2f86, guest PC 0x0c0b1dfe */
if(!s->budget--) { s->failed_pc=0x0c0b1dfeu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1e00;
P_0c0b1e00: /* original 796c, guest PC 0x0c0b1e00 */
if(!s->budget--) { s->failed_pc=0x0c0b1e00u; return 0; }
r[9]+=0x0000006cu;
goto P_0c0b1e02;
P_0c0b1e02: /* original 00ec, guest PC 0x0c0b1e02 */
if(!s->budget--) { s->failed_pc=0x0c0b1e02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b1e04;
P_0c0b1e04: /* original 9c17, guest PC 0x0c0b1e04 */
if(!s->budget--) { s->failed_pc=0x0c0b1e04u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e36u,2);
goto P_0c0b1e06;
P_0c0b1e06: /* original 600c, guest PC 0x0c0b1e06 */
if(!s->budget--) { s->failed_pc=0x0c0b1e06u; return 0; }
r[0]=r[0]&255u;
goto P_0c0b1e08;
P_0c0b1e08: /* original da14, guest PC 0x0c0b1e08 */
if(!s->budget--) { s->failed_pc=0x0c0b1e08u; return 0; }
r[10]=read(ram,0x0c0b1e5cu,4);
goto P_0c0b1e0a;
P_0c0b1e0a: /* original 4f22, guest PC 0x0c0b1e0a */
if(!s->budget--) { s->failed_pc=0x0c0b1e0au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1e0c;
P_0c0b1e0c: /* original 8809, guest PC 0x0c0b1e0c */
if(!s->budget--) { s->failed_pc=0x0c0b1e0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b1e0e;
P_0c0b1e0e: /* original 3cec, guest PC 0x0c0b1e0e */
if(!s->budget--) { s->failed_pc=0x0c0b1e0eu; return 0; }
r[12]+=r[14];
goto P_0c0b1e10;
P_0c0b1e10: /* original 0b29, guest PC 0x0c0b1e10 */
if(!s->budget--) { s->failed_pc=0x0c0b1e10u; return 0; }
r[11]=r[17]&1u;
goto P_0c0b1e12;
P_0c0b1e12: /* original a041, guest PC 0x0c0b1e12 */
if(!s->budget--) { s->failed_pc=0x0c0b1e12u; return 0; }
r[13]=0x00000000u;
goto P_0c0b1e98;
P_0c0b1e14: /* original ed00, guest PC 0x0c0b1e14 */
if(!s->budget--) { s->failed_pc=0x0c0b1e14u; return 0; }
r[13]=0x00000000u;
goto P_0c0b1e16;
P_0c0b1e16: /* original 60d3, guest PC 0x0c0b1e16 */
if(!s->budget--) { s->failed_pc=0x0c0b1e16u; return 0; }
r[0]=r[13];
goto P_0c0b1e18;
P_0c0b1e18: /* original d811, guest PC 0x0c0b1e18 */
if(!s->budget--) { s->failed_pc=0x0c0b1e18u; return 0; }
r[8]=read(ram,0x0c0b1e60u,4);
goto P_0c0b1e1a;
P_0c0b1e1a: /* original 8805, guest PC 0x0c0b1e1a */
if(!s->budget--) { s->failed_pc=0x0c0b1e1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b1e1c;
P_0c0b1e1c: /* original 8b22, guest PC 0x0c0b1e1c */
if(!s->budget--) { s->failed_pc=0x0c0b1e1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1e64; }
goto P_0c0b1e1e;
P_0c0b1e1e: /* original 2bb8, guest PC 0x0c0b1e1e */
if(!s->budget--) { s->failed_pc=0x0c0b1e1eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0b1e20;
P_0c0b1e20: /* original 8b36, guest PC 0x0c0b1e20 */
if(!s->budget--) { s->failed_pc=0x0c0b1e20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1e90; }
goto P_0c0b1e22;
P_0c0b1e22: /* original 9509, guest PC 0x0c0b1e22 */
if(!s->budget--) { s->failed_pc=0x0c0b1e22u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1e38u,2);
goto P_0c0b1e24;
P_0c0b1e24: /* original e701, guest PC 0x0c0b1e24 */
if(!s->budget--) { s->failed_pc=0x0c0b1e24u; return 0; }
r[7]=0x00000001u;
goto P_0c0b1e26;
P_0c0b1e26: /* original a024, guest PC 0x0c0b1e26 */
if(!s->budget--) { s->failed_pc=0x0c0b1e26u; return 0; }
r[6]=r[12];
goto P_0c0b1e72;
P_0c0b1e28: /* original 66c3, guest PC 0x0c0b1e28 */
if(!s->budget--) { s->failed_pc=0x0c0b1e28u; return 0; }
r[6]=r[12];
if(!vf3_matrix_family(0x0c0b1e2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1e2au; return 0; } return 1;
P_0c0b1e64: /* original 8809, guest PC 0x0c0b1e64 */
if(!s->budget--) { s->failed_pc=0x0c0b1e64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b1e66;
P_0c0b1e66: /* original 8b09, guest PC 0x0c0b1e66 */
if(!s->budget--) { s->failed_pc=0x0c0b1e66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1e7c; }
goto P_0c0b1e68;
P_0c0b1e68: /* original 2bb8, guest PC 0x0c0b1e68 */
if(!s->budget--) { s->failed_pc=0x0c0b1e68u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c0b1e6a;
P_0c0b1e6a: /* original 8b11, guest PC 0x0c0b1e6a */
if(!s->budget--) { s->failed_pc=0x0c0b1e6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1e90; }
goto P_0c0b1e6c;
P_0c0b1e6c: /* original 9520, guest PC 0x0c0b1e6c */
if(!s->budget--) { s->failed_pc=0x0c0b1e6cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1eb0u,2);
goto P_0c0b1e6e;
P_0c0b1e6e: /* original 66c3, guest PC 0x0c0b1e6e */
if(!s->budget--) { s->failed_pc=0x0c0b1e6eu; return 0; }
r[6]=r[12];
goto P_0c0b1e70;
P_0c0b1e70: /* original e700, guest PC 0x0c0b1e70 */
if(!s->budget--) { s->failed_pc=0x0c0b1e70u; return 0; }
r[7]=0x00000000u;
goto P_0c0b1e72;
P_0c0b1e72: /* original 35ec, guest PC 0x0c0b1e72 */
if(!s->budget--) { s->failed_pc=0x0c0b1e72u; return 0; }
r[5]+=r[14];
goto P_0c0b1e74;
P_0c0b1e74: /* original 480b, guest PC 0x0c0b1e74 */
if(!s->budget--) { s->failed_pc=0x0c0b1e74u; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1e78u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1e78u) { target=s->pc; goto dispatch; }
goto P_0c0b1e78;
P_0c0b1e76: /* original 64e3, guest PC 0x0c0b1e76 */
if(!s->budget--) { s->failed_pc=0x0c0b1e76u; return 0; }
r[4]=r[14];
goto P_0c0b1e78;
P_0c0b1e78: /* original a00a, guest PC 0x0c0b1e78 */
if(!s->budget--) { s->failed_pc=0x0c0b1e78u; return 0; }
goto P_0c0b1e90;
P_0c0b1e7a: /* original 0009, guest PC 0x0c0b1e7a */
if(!s->budget--) { s->failed_pc=0x0c0b1e7au; return 0; }
goto P_0c0b1e7c;
P_0c0b1e7c: /* original d80d, guest PC 0x0c0b1e7c */
if(!s->budget--) { s->failed_pc=0x0c0b1e7cu; return 0; }
r[8]=read(ram,0x0c0b1eb4u,4);
goto P_0c0b1e7e;
P_0c0b1e7e: /* original 480b, guest PC 0x0c0b1e7e */
if(!s->budget--) { s->failed_pc=0x0c0b1e7eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1e82u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1e82u) { target=s->pc; goto dispatch; }
goto P_0c0b1e82;
P_0c0b1e80: /* original 64c3, guest PC 0x0c0b1e80 */
if(!s->budget--) { s->failed_pc=0x0c0b1e80u; return 0; }
r[4]=r[12];
goto P_0c0b1e82;
P_0c0b1e82: /* original d80d, guest PC 0x0c0b1e82 */
if(!s->budget--) { s->failed_pc=0x0c0b1e82u; return 0; }
r[8]=read(ram,0x0c0b1eb8u,4);
goto P_0c0b1e84;
P_0c0b1e84: /* original e004, guest PC 0x0c0b1e84 */
if(!s->budget--) { s->failed_pc=0x0c0b1e84u; return 0; }
r[0]=0x00000004u;
goto P_0c0b1e86;
P_0c0b1e86: /* original 480b, guest PC 0x0c0b1e86 */
if(!s->budget--) { s->failed_pc=0x0c0b1e86u; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1e8au;
vf3_matrix_load(s,ram,4,r[10]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1e8au) { target=s->pc; goto dispatch; }
goto P_0c0b1e8a;
P_0c0b1e88: /* original f4a6, guest PC 0x0c0b1e88 */
if(!s->budget--) { s->failed_pc=0x0c0b1e88u; return 0; }
vf3_matrix_load(s,ram,4,r[10]+r[0]);
goto P_0c0b1e8a;
P_0c0b1e8a: /* original d80c, guest PC 0x0c0b1e8a */
if(!s->budget--) { s->failed_pc=0x0c0b1e8au; return 0; }
r[8]=read(ram,0x0c0b1ebcu,4);
goto P_0c0b1e8c;
P_0c0b1e8c: /* original 480b, guest PC 0x0c0b1e8c */
if(!s->budget--) { s->failed_pc=0x0c0b1e8cu; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1e90u;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1e90u) { target=s->pc; goto dispatch; }
goto P_0c0b1e90;
P_0c0b1e8e: /* original 6492, guest PC 0x0c0b1e8e */
if(!s->budget--) { s->failed_pc=0x0c0b1e8eu; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0b1e90;
P_0c0b1e90: /* original 7a0c, guest PC 0x0c0b1e90 */
if(!s->budget--) { s->failed_pc=0x0c0b1e90u; return 0; }
r[10]+=0x0000000cu;
goto P_0c0b1e92;
P_0c0b1e92: /* original 7d01, guest PC 0x0c0b1e92 */
if(!s->budget--) { s->failed_pc=0x0c0b1e92u; return 0; }
r[13]+=0x00000001u;
goto P_0c0b1e94;
P_0c0b1e94: /* original 7c40, guest PC 0x0c0b1e94 */
if(!s->budget--) { s->failed_pc=0x0c0b1e94u; return 0; }
r[12]+=0x00000040u;
goto P_0c0b1e96;
P_0c0b1e96: /* original 7904, guest PC 0x0c0b1e96 */
if(!s->budget--) { s->failed_pc=0x0c0b1e96u; return 0; }
r[9]+=0x00000004u;
goto P_0c0b1e98;
P_0c0b1e98: /* original e412, guest PC 0x0c0b1e98 */
if(!s->budget--) { s->failed_pc=0x0c0b1e98u; return 0; }
r[4]=0x00000012u;
goto P_0c0b1e9a;
P_0c0b1e9a: /* original 3d43, guest PC 0x0c0b1e9a */
if(!s->budget--) { s->failed_pc=0x0c0b1e9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[4])!=0);
goto P_0c0b1e9c;
P_0c0b1e9c: /* original 8bbb, guest PC 0x0c0b1e9c */
if(!s->budget--) { s->failed_pc=0x0c0b1e9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1e16; }
goto P_0c0b1e9e;
P_0c0b1e9e: /* original 4f26, guest PC 0x0c0b1e9e */
if(!s->budget--) { s->failed_pc=0x0c0b1e9eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1ea0;
P_0c0b1ea0: /* original 68f6, guest PC 0x0c0b1ea0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0b1ea2;
P_0c0b1ea2: /* original 69f6, guest PC 0x0c0b1ea2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b1ea4;
P_0c0b1ea4: /* original 6af6, guest PC 0x0c0b1ea4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b1ea6;
P_0c0b1ea6: /* original 6bf6, guest PC 0x0c0b1ea6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b1ea8;
P_0c0b1ea8: /* original 6cf6, guest PC 0x0c0b1ea8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1eaa;
P_0c0b1eaa: /* original 6df6, guest PC 0x0c0b1eaa */
if(!s->budget--) { s->failed_pc=0x0c0b1eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1eac;
P_0c0b1eac: /* original 000b, guest PC 0x0c0b1eac */
if(!s->budget--) { s->failed_pc=0x0c0b1eacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1eae: /* original 6ef6, guest PC 0x0c0b1eae */
if(!s->budget--) { s->failed_pc=0x0c0b1eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1eb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1eb0u; return 0; } return 1;
P_0c0b1ec0: /* original 2fe6, guest PC 0x0c0b1ec0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ec0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ec2;
P_0c0b1ec2: /* original 2668, guest PC 0x0c0b1ec2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ec2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0b1ec4;
P_0c0b1ec4: /* original 2fd6, guest PC 0x0c0b1ec4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ec4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ec6;
P_0c0b1ec6: /* original 2fc6, guest PC 0x0c0b1ec6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ec6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ec8;
P_0c0b1ec8: /* original 2fb6, guest PC 0x0c0b1ec8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ec8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1eca;
P_0c0b1eca: /* original 6b43, guest PC 0x0c0b1eca */
if(!s->budget--) { s->failed_pc=0x0c0b1ecau; return 0; }
r[11]=r[4];
goto P_0c0b1ecc;
P_0c0b1ecc: /* original 2fa6, guest PC 0x0c0b1ecc */
if(!s->budget--) { s->failed_pc=0x0c0b1eccu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ece;
P_0c0b1ece: /* original 2f96, guest PC 0x0c0b1ece */
if(!s->budget--) { s->failed_pc=0x0c0b1eceu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ed0;
P_0c0b1ed0: /* original 2f86, guest PC 0x0c0b1ed0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ed0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1ed2;
P_0c0b1ed2: /* original fffb, guest PC 0x0c0b1ed2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ed2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0b1ed4;
P_0c0b1ed4: /* original 4f22, guest PC 0x0c0b1ed4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ed4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1ed6;
P_0c0b1ed6: /* original 7ff8, guest PC 0x0c0b1ed6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ed6u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b1ed8;
P_0c0b1ed8: /* original 2f52, guest PC 0x0c0b1ed8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ed8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b1eda;
P_0c0b1eda: /* original 84b4, guest PC 0x0c0b1eda */
if(!s->budget--) { s->failed_pc=0x0c0b1edau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+4,1);
goto P_0c0b1edc;
P_0c0b1edc: /* original d162, guest PC 0x0c0b1edc */
if(!s->budget--) { s->failed_pc=0x0c0b1edcu; return 0; }
r[1]=read(ram,0x0c0b2068u,4);
goto P_0c0b1ede;
P_0c0b1ede: /* original 600c, guest PC 0x0c0b1ede */
if(!s->budget--) { s->failed_pc=0x0c0b1edeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0b1ee0;
P_0c0b1ee0: /* original 9ebc, guest PC 0x0c0b1ee0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ee0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b205cu,2);
goto P_0c0b1ee2;
P_0c0b1ee2: /* original 4008, guest PC 0x0c0b1ee2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ee2u; return 0; }
r[0]<<=2;
goto P_0c0b1ee4;
P_0c0b1ee4: /* original ff16, guest PC 0x0c0b1ee4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ee4u; return 0; }
vf3_matrix_load(s,ram,15,r[1]+r[0]);
goto P_0c0b1ee6;
P_0c0b1ee6: /* original 8f02, guest PC 0x0c0b1ee6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ee6u; return 0; }
cond=r[17]&1u;
r[14]+=r[11];
if(!cond) { goto P_0c0b1eee; }
goto P_0c0b1eea;
P_0c0b1ee8: /* original 3ebc, guest PC 0x0c0b1ee8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ee8u; return 0; }
r[14]+=r[11];
goto P_0c0b1eea;
P_0c0b1eea: /* original a0ac, guest PC 0x0c0b1eea */
if(!s->budget--) { s->failed_pc=0x0c0b1eeau; return 0; }
goto P_0c0b2046;
P_0c0b1eec: /* original 0009, guest PC 0x0c0b1eec */
if(!s->budget--) { s->failed_pc=0x0c0b1eecu; return 0; }
goto P_0c0b1eee;
P_0c0b1eee: /* original d35f, guest PC 0x0c0b1eee */
if(!s->budget--) { s->failed_pc=0x0c0b1eeeu; return 0; }
r[3]=read(ram,0x0c0b206cu,4);
goto P_0c0b1ef0;
P_0c0b1ef0: /* original 430b, guest PC 0x0c0b1ef0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ef0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1ef4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1ef4u) { target=s->pc; goto dispatch; }
goto P_0c0b1ef4;
P_0c0b1ef2: /* original 0009, guest PC 0x0c0b1ef2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ef2u; return 0; }
goto P_0c0b1ef4;
P_0c0b1ef4: /* original dd5e, guest PC 0x0c0b1ef4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ef4u; return 0; }
r[13]=read(ram,0x0c0b2070u,4);
goto P_0c0b1ef6;
P_0c0b1ef6: /* original 64e3, guest PC 0x0c0b1ef6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ef6u; return 0; }
r[4]=r[14];
goto P_0c0b1ef8;
P_0c0b1ef8: /* original 4d0b, guest PC 0x0c0b1ef8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ef8u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1efcu;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1efcu) { target=s->pc; goto dispatch; }
goto P_0c0b1efc;
P_0c0b1efa: /* original 7e40, guest PC 0x0c0b1efa */
if(!s->budget--) { s->failed_pc=0x0c0b1efau; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1efc;
P_0c0b1efc: /* original dc5d, guest PC 0x0c0b1efc */
if(!s->budget--) { s->failed_pc=0x0c0b1efcu; return 0; }
r[12]=read(ram,0x0c0b2074u,4);
goto P_0c0b1efe;
P_0c0b1efe: /* original f4fc, guest PC 0x0c0b1efe */
if(!s->budget--) { s->failed_pc=0x0c0b1efeu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f00;
P_0c0b1f00: /* original 4c0b, guest PC 0x0c0b1f00 */
if(!s->budget--) { s->failed_pc=0x0c0b1f00u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1f04u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f04u) { target=s->pc; goto dispatch; }
goto P_0c0b1f04;
P_0c0b1f02: /* original 64f2, guest PC 0x0c0b1f02 */
if(!s->budget--) { s->failed_pc=0x0c0b1f02u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1f04;
P_0c0b1f04: /* original d95c, guest PC 0x0c0b1f04 */
if(!s->budget--) { s->failed_pc=0x0c0b1f04u; return 0; }
r[9]=read(ram,0x0c0b2078u,4);
goto P_0c0b1f06;
P_0c0b1f06: /* original 490b, guest PC 0x0c0b1f06 */
if(!s->budget--) { s->failed_pc=0x0c0b1f06u; return 0; }
target=r[9];
r[16]=code_base|0x0c0b1f0au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f0au) { target=s->pc; goto dispatch; }
goto P_0c0b1f0a;
P_0c0b1f08: /* original 0009, guest PC 0x0c0b1f08 */
if(!s->budget--) { s->failed_pc=0x0c0b1f08u; return 0; }
goto P_0c0b1f0a;
P_0c0b1f0a: /* original 63f2, guest PC 0x0c0b1f0a */
if(!s->budget--) { s->failed_pc=0x0c0b1f0au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1f0c;
P_0c0b1f0c: /* original 64e3, guest PC 0x0c0b1f0c */
if(!s->budget--) { s->failed_pc=0x0c0b1f0cu; return 0; }
r[4]=r[14];
goto P_0c0b1f0e;
P_0c0b1f0e: /* original 523b, guest PC 0x0c0b1f0e */
if(!s->budget--) { s->failed_pc=0x0c0b1f0eu; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1f10;
P_0c0b1f10: /* original 1f21, guest PC 0x0c0b1f10 */
if(!s->budget--) { s->failed_pc=0x0c0b1f10u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b1f12;
P_0c0b1f12: /* original 4d0b, guest PC 0x0c0b1f12 */
if(!s->budget--) { s->failed_pc=0x0c0b1f12u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f16u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f16u) { target=s->pc; goto dispatch; }
goto P_0c0b1f16;
P_0c0b1f14: /* original 7e40, guest PC 0x0c0b1f14 */
if(!s->budget--) { s->failed_pc=0x0c0b1f14u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f16;
P_0c0b1f16: /* original da59, guest PC 0x0c0b1f16 */
if(!s->budget--) { s->failed_pc=0x0c0b1f16u; return 0; }
r[10]=read(ram,0x0c0b207cu,4);
goto P_0c0b1f18;
P_0c0b1f18: /* original e070, guest PC 0x0c0b1f18 */
if(!s->budget--) { s->failed_pc=0x0c0b1f18u; return 0; }
r[0]=0x00000070u;
goto P_0c0b1f1a;
P_0c0b1f1a: /* original f4fc, guest PC 0x0c0b1f1a */
if(!s->budget--) { s->failed_pc=0x0c0b1f1au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f1c;
P_0c0b1f1c: /* original 4a0b, guest PC 0x0c0b1f1c */
if(!s->budget--) { s->failed_pc=0x0c0b1f1cu; return 0; }
target=r[10];
r[16]=code_base|0x0c0b1f20u;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f20u) { target=s->pc; goto dispatch; }
goto P_0c0b1f20;
P_0c0b1f1e: /* original 04be, guest PC 0x0c0b1f1e */
if(!s->budget--) { s->failed_pc=0x0c0b1f1eu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0b1f20;
P_0c0b1f20: /* original d857, guest PC 0x0c0b1f20 */
if(!s->budget--) { s->failed_pc=0x0c0b1f20u; return 0; }
r[8]=read(ram,0x0c0b2080u,4);
goto P_0c0b1f22;
P_0c0b1f22: /* original 480b, guest PC 0x0c0b1f22 */
if(!s->budget--) { s->failed_pc=0x0c0b1f22u; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1f26u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f26u) { target=s->pc; goto dispatch; }
goto P_0c0b1f26;
P_0c0b1f24: /* original 0009, guest PC 0x0c0b1f24 */
if(!s->budget--) { s->failed_pc=0x0c0b1f24u; return 0; }
goto P_0c0b1f26;
P_0c0b1f26: /* original 490b, guest PC 0x0c0b1f26 */
if(!s->budget--) { s->failed_pc=0x0c0b1f26u; return 0; }
target=r[9];
r[16]=code_base|0x0c0b1f2au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f2au) { target=s->pc; goto dispatch; }
goto P_0c0b1f2a;
P_0c0b1f28: /* original 0009, guest PC 0x0c0b1f28 */
if(!s->budget--) { s->failed_pc=0x0c0b1f28u; return 0; }
goto P_0c0b1f2a;
P_0c0b1f2a: /* original 64e3, guest PC 0x0c0b1f2a */
if(!s->budget--) { s->failed_pc=0x0c0b1f2au; return 0; }
r[4]=r[14];
goto P_0c0b1f2c;
P_0c0b1f2c: /* original 4d0b, guest PC 0x0c0b1f2c */
if(!s->budget--) { s->failed_pc=0x0c0b1f2cu; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f30u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f30u) { target=s->pc; goto dispatch; }
goto P_0c0b1f30;
P_0c0b1f2e: /* original 7e40, guest PC 0x0c0b1f2e */
if(!s->budget--) { s->failed_pc=0x0c0b1f2eu; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f30;
P_0c0b1f30: /* original f4fc, guest PC 0x0c0b1f30 */
if(!s->budget--) { s->failed_pc=0x0c0b1f30u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f32;
P_0c0b1f32: /* original 4c0b, guest PC 0x0c0b1f32 */
if(!s->budget--) { s->failed_pc=0x0c0b1f32u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1f36u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f36u) { target=s->pc; goto dispatch; }
goto P_0c0b1f36;
P_0c0b1f34: /* original 54f1, guest PC 0x0c0b1f34 */
if(!s->budget--) { s->failed_pc=0x0c0b1f34u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0b1f36;
P_0c0b1f36: /* original 53f1, guest PC 0x0c0b1f36 */
if(!s->budget--) { s->failed_pc=0x0c0b1f36u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1f38;
P_0c0b1f38: /* original 64e3, guest PC 0x0c0b1f38 */
if(!s->budget--) { s->failed_pc=0x0c0b1f38u; return 0; }
r[4]=r[14];
goto P_0c0b1f3a;
P_0c0b1f3a: /* original 523c, guest PC 0x0c0b1f3a */
if(!s->budget--) { s->failed_pc=0x0c0b1f3au; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c0b1f3c;
P_0c0b1f3c: /* original 2f22, guest PC 0x0c0b1f3c */
if(!s->budget--) { s->failed_pc=0x0c0b1f3cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1f3e;
P_0c0b1f3e: /* original 53f1, guest PC 0x0c0b1f3e */
if(!s->budget--) { s->failed_pc=0x0c0b1f3eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1f40;
P_0c0b1f40: /* original 523b, guest PC 0x0c0b1f40 */
if(!s->budget--) { s->failed_pc=0x0c0b1f40u; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1f42;
P_0c0b1f42: /* original 1f21, guest PC 0x0c0b1f42 */
if(!s->budget--) { s->failed_pc=0x0c0b1f42u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b1f44;
P_0c0b1f44: /* original 4d0b, guest PC 0x0c0b1f44 */
if(!s->budget--) { s->failed_pc=0x0c0b1f44u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f48u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f48u) { target=s->pc; goto dispatch; }
goto P_0c0b1f48;
P_0c0b1f46: /* original 7e40, guest PC 0x0c0b1f46 */
if(!s->budget--) { s->failed_pc=0x0c0b1f46u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f48;
P_0c0b1f48: /* original f4fc, guest PC 0x0c0b1f48 */
if(!s->budget--) { s->failed_pc=0x0c0b1f48u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f4a;
P_0c0b1f4a: /* original 4c0b, guest PC 0x0c0b1f4a */
if(!s->budget--) { s->failed_pc=0x0c0b1f4au; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1f4eu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f4eu) { target=s->pc; goto dispatch; }
goto P_0c0b1f4e;
P_0c0b1f4c: /* original 54f1, guest PC 0x0c0b1f4c */
if(!s->budget--) { s->failed_pc=0x0c0b1f4cu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0b1f4e;
P_0c0b1f4e: /* original 53f1, guest PC 0x0c0b1f4e */
if(!s->budget--) { s->failed_pc=0x0c0b1f4eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1f50;
P_0c0b1f50: /* original 64e3, guest PC 0x0c0b1f50 */
if(!s->budget--) { s->failed_pc=0x0c0b1f50u; return 0; }
r[4]=r[14];
goto P_0c0b1f52;
P_0c0b1f52: /* original 523b, guest PC 0x0c0b1f52 */
if(!s->budget--) { s->failed_pc=0x0c0b1f52u; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1f54;
P_0c0b1f54: /* original 1f21, guest PC 0x0c0b1f54 */
if(!s->budget--) { s->failed_pc=0x0c0b1f54u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b1f56;
P_0c0b1f56: /* original 4d0b, guest PC 0x0c0b1f56 */
if(!s->budget--) { s->failed_pc=0x0c0b1f56u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f5au;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f5au) { target=s->pc; goto dispatch; }
goto P_0c0b1f5a;
P_0c0b1f58: /* original 7e40, guest PC 0x0c0b1f58 */
if(!s->budget--) { s->failed_pc=0x0c0b1f58u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f5a;
P_0c0b1f5a: /* original f4fc, guest PC 0x0c0b1f5a */
if(!s->budget--) { s->failed_pc=0x0c0b1f5au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f5c;
P_0c0b1f5c: /* original 4c0b, guest PC 0x0c0b1f5c */
if(!s->budget--) { s->failed_pc=0x0c0b1f5cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1f60u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f60u) { target=s->pc; goto dispatch; }
goto P_0c0b1f60;
P_0c0b1f5e: /* original 54f1, guest PC 0x0c0b1f5e */
if(!s->budget--) { s->failed_pc=0x0c0b1f5eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0b1f60;
P_0c0b1f60: /* original 64e3, guest PC 0x0c0b1f60 */
if(!s->budget--) { s->failed_pc=0x0c0b1f60u; return 0; }
r[4]=r[14];
goto P_0c0b1f62;
P_0c0b1f62: /* original 4d0b, guest PC 0x0c0b1f62 */
if(!s->budget--) { s->failed_pc=0x0c0b1f62u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f66u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f66u) { target=s->pc; goto dispatch; }
goto P_0c0b1f66;
P_0c0b1f64: /* original 7e40, guest PC 0x0c0b1f64 */
if(!s->budget--) { s->failed_pc=0x0c0b1f64u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f66;
P_0c0b1f66: /* original 907a, guest PC 0x0c0b1f66 */
if(!s->budget--) { s->failed_pc=0x0c0b1f66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b205eu,2);
goto P_0c0b1f68;
P_0c0b1f68: /* original f4fc, guest PC 0x0c0b1f68 */
if(!s->budget--) { s->failed_pc=0x0c0b1f68u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f6a;
P_0c0b1f6a: /* original 4a0b, guest PC 0x0c0b1f6a */
if(!s->budget--) { s->failed_pc=0x0c0b1f6au; return 0; }
target=r[10];
r[16]=code_base|0x0c0b1f6eu;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f6eu) { target=s->pc; goto dispatch; }
goto P_0c0b1f6e;
P_0c0b1f6c: /* original 04be, guest PC 0x0c0b1f6c */
if(!s->budget--) { s->failed_pc=0x0c0b1f6cu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0b1f6e;
P_0c0b1f6e: /* original 480b, guest PC 0x0c0b1f6e */
if(!s->budget--) { s->failed_pc=0x0c0b1f6eu; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1f72u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f72u) { target=s->pc; goto dispatch; }
goto P_0c0b1f72;
P_0c0b1f70: /* original 0009, guest PC 0x0c0b1f70 */
if(!s->budget--) { s->failed_pc=0x0c0b1f70u; return 0; }
goto P_0c0b1f72;
P_0c0b1f72: /* original 490b, guest PC 0x0c0b1f72 */
if(!s->budget--) { s->failed_pc=0x0c0b1f72u; return 0; }
target=r[9];
r[16]=code_base|0x0c0b1f76u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f76u) { target=s->pc; goto dispatch; }
goto P_0c0b1f76;
P_0c0b1f74: /* original 0009, guest PC 0x0c0b1f74 */
if(!s->budget--) { s->failed_pc=0x0c0b1f74u; return 0; }
goto P_0c0b1f76;
P_0c0b1f76: /* original 64e3, guest PC 0x0c0b1f76 */
if(!s->budget--) { s->failed_pc=0x0c0b1f76u; return 0; }
r[4]=r[14];
goto P_0c0b1f78;
P_0c0b1f78: /* original 4d0b, guest PC 0x0c0b1f78 */
if(!s->budget--) { s->failed_pc=0x0c0b1f78u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f7cu;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f7cu) { target=s->pc; goto dispatch; }
goto P_0c0b1f7c;
P_0c0b1f7a: /* original 7e40, guest PC 0x0c0b1f7a */
if(!s->budget--) { s->failed_pc=0x0c0b1f7au; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f7c;
P_0c0b1f7c: /* original f4fc, guest PC 0x0c0b1f7c */
if(!s->budget--) { s->failed_pc=0x0c0b1f7cu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f7e;
P_0c0b1f7e: /* original 4c0b, guest PC 0x0c0b1f7e */
if(!s->budget--) { s->failed_pc=0x0c0b1f7eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1f82u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f82u) { target=s->pc; goto dispatch; }
goto P_0c0b1f82;
P_0c0b1f80: /* original 64f2, guest PC 0x0c0b1f80 */
if(!s->budget--) { s->failed_pc=0x0c0b1f80u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1f82;
P_0c0b1f82: /* original 63f2, guest PC 0x0c0b1f82 */
if(!s->budget--) { s->failed_pc=0x0c0b1f82u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1f84;
P_0c0b1f84: /* original 64e3, guest PC 0x0c0b1f84 */
if(!s->budget--) { s->failed_pc=0x0c0b1f84u; return 0; }
r[4]=r[14];
goto P_0c0b1f86;
P_0c0b1f86: /* original 523c, guest PC 0x0c0b1f86 */
if(!s->budget--) { s->failed_pc=0x0c0b1f86u; return 0; }
r[2]=read(ram,r[3]+48,4);
goto P_0c0b1f88;
P_0c0b1f88: /* original 1f21, guest PC 0x0c0b1f88 */
if(!s->budget--) { s->failed_pc=0x0c0b1f88u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0b1f8a;
P_0c0b1f8a: /* original 63f2, guest PC 0x0c0b1f8a */
if(!s->budget--) { s->failed_pc=0x0c0b1f8au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1f8c;
P_0c0b1f8c: /* original 523b, guest PC 0x0c0b1f8c */
if(!s->budget--) { s->failed_pc=0x0c0b1f8cu; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1f8e;
P_0c0b1f8e: /* original 2f22, guest PC 0x0c0b1f8e */
if(!s->budget--) { s->failed_pc=0x0c0b1f8eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1f90;
P_0c0b1f90: /* original 4d0b, guest PC 0x0c0b1f90 */
if(!s->budget--) { s->failed_pc=0x0c0b1f90u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1f94u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f94u) { target=s->pc; goto dispatch; }
goto P_0c0b1f94;
P_0c0b1f92: /* original 7e40, guest PC 0x0c0b1f92 */
if(!s->budget--) { s->failed_pc=0x0c0b1f92u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1f94;
P_0c0b1f94: /* original f4fc, guest PC 0x0c0b1f94 */
if(!s->budget--) { s->failed_pc=0x0c0b1f94u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1f96;
P_0c0b1f96: /* original 4c0b, guest PC 0x0c0b1f96 */
if(!s->budget--) { s->failed_pc=0x0c0b1f96u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1f9au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1f9au) { target=s->pc; goto dispatch; }
goto P_0c0b1f9a;
P_0c0b1f98: /* original 64f2, guest PC 0x0c0b1f98 */
if(!s->budget--) { s->failed_pc=0x0c0b1f98u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1f9a;
P_0c0b1f9a: /* original 63f2, guest PC 0x0c0b1f9a */
if(!s->budget--) { s->failed_pc=0x0c0b1f9au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1f9c;
P_0c0b1f9c: /* original 64e3, guest PC 0x0c0b1f9c */
if(!s->budget--) { s->failed_pc=0x0c0b1f9cu; return 0; }
r[4]=r[14];
goto P_0c0b1f9e;
P_0c0b1f9e: /* original 523b, guest PC 0x0c0b1f9e */
if(!s->budget--) { s->failed_pc=0x0c0b1f9eu; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1fa0;
P_0c0b1fa0: /* original 2f22, guest PC 0x0c0b1fa0 */
if(!s->budget--) { s->failed_pc=0x0c0b1fa0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1fa2;
P_0c0b1fa2: /* original 4d0b, guest PC 0x0c0b1fa2 */
if(!s->budget--) { s->failed_pc=0x0c0b1fa2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1fa6u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fa6u) { target=s->pc; goto dispatch; }
goto P_0c0b1fa6;
P_0c0b1fa4: /* original 7e40, guest PC 0x0c0b1fa4 */
if(!s->budget--) { s->failed_pc=0x0c0b1fa4u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1fa6;
P_0c0b1fa6: /* original f4fc, guest PC 0x0c0b1fa6 */
if(!s->budget--) { s->failed_pc=0x0c0b1fa6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1fa8;
P_0c0b1fa8: /* original 4c0b, guest PC 0x0c0b1fa8 */
if(!s->budget--) { s->failed_pc=0x0c0b1fa8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1facu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1facu) { target=s->pc; goto dispatch; }
goto P_0c0b1fac;
P_0c0b1faa: /* original 64f2, guest PC 0x0c0b1faa */
if(!s->budget--) { s->failed_pc=0x0c0b1faau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1fac;
P_0c0b1fac: /* original 64e3, guest PC 0x0c0b1fac */
if(!s->budget--) { s->failed_pc=0x0c0b1facu; return 0; }
r[4]=r[14];
goto P_0c0b1fae;
P_0c0b1fae: /* original 4d0b, guest PC 0x0c0b1fae */
if(!s->budget--) { s->failed_pc=0x0c0b1faeu; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1fb2u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fb2u) { target=s->pc; goto dispatch; }
goto P_0c0b1fb2;
P_0c0b1fb0: /* original 7e40, guest PC 0x0c0b1fb0 */
if(!s->budget--) { s->failed_pc=0x0c0b1fb0u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1fb2;
P_0c0b1fb2: /* original 9055, guest PC 0x0c0b1fb2 */
if(!s->budget--) { s->failed_pc=0x0c0b1fb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2060u,2);
goto P_0c0b1fb4;
P_0c0b1fb4: /* original f4fc, guest PC 0x0c0b1fb4 */
if(!s->budget--) { s->failed_pc=0x0c0b1fb4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1fb6;
P_0c0b1fb6: /* original 4a0b, guest PC 0x0c0b1fb6 */
if(!s->budget--) { s->failed_pc=0x0c0b1fb6u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b1fbau;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fbau) { target=s->pc; goto dispatch; }
goto P_0c0b1fba;
P_0c0b1fb8: /* original 04be, guest PC 0x0c0b1fb8 */
if(!s->budget--) { s->failed_pc=0x0c0b1fb8u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0b1fba;
P_0c0b1fba: /* original 480b, guest PC 0x0c0b1fba */
if(!s->budget--) { s->failed_pc=0x0c0b1fbau; return 0; }
target=r[8];
r[16]=code_base|0x0c0b1fbeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fbeu) { target=s->pc; goto dispatch; }
goto P_0c0b1fbe;
P_0c0b1fbc: /* original 0009, guest PC 0x0c0b1fbc */
if(!s->budget--) { s->failed_pc=0x0c0b1fbcu; return 0; }
goto P_0c0b1fbe;
P_0c0b1fbe: /* original 64e3, guest PC 0x0c0b1fbe */
if(!s->budget--) { s->failed_pc=0x0c0b1fbeu; return 0; }
r[4]=r[14];
goto P_0c0b1fc0;
P_0c0b1fc0: /* original 4d0b, guest PC 0x0c0b1fc0 */
if(!s->budget--) { s->failed_pc=0x0c0b1fc0u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1fc4u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fc4u) { target=s->pc; goto dispatch; }
goto P_0c0b1fc4;
P_0c0b1fc2: /* original 7e40, guest PC 0x0c0b1fc2 */
if(!s->budget--) { s->failed_pc=0x0c0b1fc2u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1fc4;
P_0c0b1fc4: /* original f4fc, guest PC 0x0c0b1fc4 */
if(!s->budget--) { s->failed_pc=0x0c0b1fc4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1fc6;
P_0c0b1fc6: /* original 4c0b, guest PC 0x0c0b1fc6 */
if(!s->budget--) { s->failed_pc=0x0c0b1fc6u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1fcau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fcau) { target=s->pc; goto dispatch; }
goto P_0c0b1fca;
P_0c0b1fc8: /* original 54f1, guest PC 0x0c0b1fc8 */
if(!s->budget--) { s->failed_pc=0x0c0b1fc8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0b1fca;
P_0c0b1fca: /* original 53f1, guest PC 0x0c0b1fca */
if(!s->budget--) { s->failed_pc=0x0c0b1fcau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0b1fcc;
P_0c0b1fcc: /* original 64e3, guest PC 0x0c0b1fcc */
if(!s->budget--) { s->failed_pc=0x0c0b1fccu; return 0; }
r[4]=r[14];
goto P_0c0b1fce;
P_0c0b1fce: /* original 523b, guest PC 0x0c0b1fce */
if(!s->budget--) { s->failed_pc=0x0c0b1fceu; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1fd0;
P_0c0b1fd0: /* original 2f22, guest PC 0x0c0b1fd0 */
if(!s->budget--) { s->failed_pc=0x0c0b1fd0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1fd2;
P_0c0b1fd2: /* original 4d0b, guest PC 0x0c0b1fd2 */
if(!s->budget--) { s->failed_pc=0x0c0b1fd2u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1fd6u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fd6u) { target=s->pc; goto dispatch; }
goto P_0c0b1fd6;
P_0c0b1fd4: /* original 7e40, guest PC 0x0c0b1fd4 */
if(!s->budget--) { s->failed_pc=0x0c0b1fd4u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1fd6;
P_0c0b1fd6: /* original f4fc, guest PC 0x0c0b1fd6 */
if(!s->budget--) { s->failed_pc=0x0c0b1fd6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1fd8;
P_0c0b1fd8: /* original 4c0b, guest PC 0x0c0b1fd8 */
if(!s->budget--) { s->failed_pc=0x0c0b1fd8u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1fdcu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fdcu) { target=s->pc; goto dispatch; }
goto P_0c0b1fdc;
P_0c0b1fda: /* original 64f2, guest PC 0x0c0b1fda */
if(!s->budget--) { s->failed_pc=0x0c0b1fdau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1fdc;
P_0c0b1fdc: /* original 63f2, guest PC 0x0c0b1fdc */
if(!s->budget--) { s->failed_pc=0x0c0b1fdcu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1fde;
P_0c0b1fde: /* original 523b, guest PC 0x0c0b1fde */
if(!s->budget--) { s->failed_pc=0x0c0b1fdeu; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1fe0;
P_0c0b1fe0: /* original 490b, guest PC 0x0c0b1fe0 */
if(!s->budget--) { s->failed_pc=0x0c0b1fe0u; return 0; }
target=r[9];
r[16]=code_base|0x0c0b1fe4u;
write(ram,r[15],r[2],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1fe4u) { target=s->pc; goto dispatch; }
goto P_0c0b1fe4;
P_0c0b1fe2: /* original 2f22, guest PC 0x0c0b1fe2 */
if(!s->budget--) { s->failed_pc=0x0c0b1fe2u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1fe4;
P_0c0b1fe4: /* original 64e3, guest PC 0x0c0b1fe4 */
if(!s->budget--) { s->failed_pc=0x0c0b1fe4u; return 0; }
r[4]=r[14];
goto P_0c0b1fe6;
P_0c0b1fe6: /* original 4d0b, guest PC 0x0c0b1fe6 */
if(!s->budget--) { s->failed_pc=0x0c0b1fe6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b1feau;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1feau) { target=s->pc; goto dispatch; }
goto P_0c0b1fea;
P_0c0b1fe8: /* original 7e40, guest PC 0x0c0b1fe8 */
if(!s->budget--) { s->failed_pc=0x0c0b1fe8u; return 0; }
r[14]+=0x00000040u;
goto P_0c0b1fea;
P_0c0b1fea: /* original f4fc, guest PC 0x0c0b1fea */
if(!s->budget--) { s->failed_pc=0x0c0b1feau; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b1fec;
P_0c0b1fec: /* original 4c0b, guest PC 0x0c0b1fec */
if(!s->budget--) { s->failed_pc=0x0c0b1fecu; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1ff0u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1ff0u) { target=s->pc; goto dispatch; }
goto P_0c0b1ff0;
P_0c0b1fee: /* original 64f2, guest PC 0x0c0b1fee */
if(!s->budget--) { s->failed_pc=0x0c0b1feeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1ff0;
P_0c0b1ff0: /* original 63f2, guest PC 0x0c0b1ff0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ff0u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0b1ff2;
P_0c0b1ff2: /* original 64e3, guest PC 0x0c0b1ff2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ff2u; return 0; }
r[4]=r[14];
goto P_0c0b1ff4;
P_0c0b1ff4: /* original 69f2, guest PC 0x0c0b1ff4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ff4u; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0b1ff6;
P_0c0b1ff6: /* original 523b, guest PC 0x0c0b1ff6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ff6u; return 0; }
r[2]=read(ram,r[3]+44,4);
goto P_0c0b1ff8;
P_0c0b1ff8: /* original 599c, guest PC 0x0c0b1ff8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ff8u; return 0; }
r[9]=read(ram,r[9]+48,4);
goto P_0c0b1ffa;
P_0c0b1ffa: /* original 2f22, guest PC 0x0c0b1ffa */
if(!s->budget--) { s->failed_pc=0x0c0b1ffau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0b1ffc;
P_0c0b1ffc: /* original 4d0b, guest PC 0x0c0b1ffc */
if(!s->budget--) { s->failed_pc=0x0c0b1ffcu; return 0; }
target=r[13];
r[16]=code_base|0x0c0b2000u;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2000u) { target=s->pc; goto dispatch; }
goto P_0c0b2000;
P_0c0b1ffe: /* original 7e40, guest PC 0x0c0b1ffe */
if(!s->budget--) { s->failed_pc=0x0c0b1ffeu; return 0; }
r[14]+=0x00000040u;
goto P_0c0b2000;
P_0c0b2000: /* original f4fc, guest PC 0x0c0b2000 */
if(!s->budget--) { s->failed_pc=0x0c0b2000u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b2002;
P_0c0b2002: /* original 4c0b, guest PC 0x0c0b2002 */
if(!s->budget--) { s->failed_pc=0x0c0b2002u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b2006u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2006u) { target=s->pc; goto dispatch; }
goto P_0c0b2006;
P_0c0b2004: /* original 64f2, guest PC 0x0c0b2004 */
if(!s->budget--) { s->failed_pc=0x0c0b2004u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b2006;
P_0c0b2006: /* original 64e3, guest PC 0x0c0b2006 */
if(!s->budget--) { s->failed_pc=0x0c0b2006u; return 0; }
r[4]=r[14];
goto P_0c0b2008;
P_0c0b2008: /* original 4d0b, guest PC 0x0c0b2008 */
if(!s->budget--) { s->failed_pc=0x0c0b2008u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b200cu;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b200cu) { target=s->pc; goto dispatch; }
goto P_0c0b200c;
P_0c0b200a: /* original 7e40, guest PC 0x0c0b200a */
if(!s->budget--) { s->failed_pc=0x0c0b200au; return 0; }
r[14]+=0x00000040u;
goto P_0c0b200c;
P_0c0b200c: /* original 9029, guest PC 0x0c0b200c */
if(!s->budget--) { s->failed_pc=0x0c0b200cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2062u,2);
goto P_0c0b200e;
P_0c0b200e: /* original f4fc, guest PC 0x0c0b200e */
if(!s->budget--) { s->failed_pc=0x0c0b200eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b2010;
P_0c0b2010: /* original 4a0b, guest PC 0x0c0b2010 */
if(!s->budget--) { s->failed_pc=0x0c0b2010u; return 0; }
target=r[10];
r[16]=code_base|0x0c0b2014u;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2014u) { target=s->pc; goto dispatch; }
goto P_0c0b2014;
P_0c0b2012: /* original 04be, guest PC 0x0c0b2012 */
if(!s->budget--) { s->failed_pc=0x0c0b2012u; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0b2014;
P_0c0b2014: /* original 480b, guest PC 0x0c0b2014 */
if(!s->budget--) { s->failed_pc=0x0c0b2014u; return 0; }
target=r[8];
r[16]=code_base|0x0c0b2018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2018u) { target=s->pc; goto dispatch; }
goto P_0c0b2018;
P_0c0b2016: /* original 0009, guest PC 0x0c0b2016 */
if(!s->budget--) { s->failed_pc=0x0c0b2016u; return 0; }
goto P_0c0b2018;
P_0c0b2018: /* original 64e3, guest PC 0x0c0b2018 */
if(!s->budget--) { s->failed_pc=0x0c0b2018u; return 0; }
r[4]=r[14];
goto P_0c0b201a;
P_0c0b201a: /* original 4d0b, guest PC 0x0c0b201a */
if(!s->budget--) { s->failed_pc=0x0c0b201au; return 0; }
target=r[13];
r[16]=code_base|0x0c0b201eu;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b201eu) { target=s->pc; goto dispatch; }
goto P_0c0b201e;
P_0c0b201c: /* original 7e40, guest PC 0x0c0b201c */
if(!s->budget--) { s->failed_pc=0x0c0b201cu; return 0; }
r[14]+=0x00000040u;
goto P_0c0b201e;
P_0c0b201e: /* original f4fc, guest PC 0x0c0b201e */
if(!s->budget--) { s->failed_pc=0x0c0b201eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b2020;
P_0c0b2020: /* original 4c0b, guest PC 0x0c0b2020 */
if(!s->budget--) { s->failed_pc=0x0c0b2020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b2024u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2024u) { target=s->pc; goto dispatch; }
goto P_0c0b2024;
P_0c0b2022: /* original 6493, guest PC 0x0c0b2022 */
if(!s->budget--) { s->failed_pc=0x0c0b2022u; return 0; }
r[4]=r[9];
goto P_0c0b2024;
P_0c0b2024: /* original 539b, guest PC 0x0c0b2024 */
if(!s->budget--) { s->failed_pc=0x0c0b2024u; return 0; }
r[3]=read(ram,r[9]+44,4);
goto P_0c0b2026;
P_0c0b2026: /* original 64e3, guest PC 0x0c0b2026 */
if(!s->budget--) { s->failed_pc=0x0c0b2026u; return 0; }
r[4]=r[14];
goto P_0c0b2028;
P_0c0b2028: /* original 2f32, guest PC 0x0c0b2028 */
if(!s->budget--) { s->failed_pc=0x0c0b2028u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0b202a;
P_0c0b202a: /* original 4d0b, guest PC 0x0c0b202a */
if(!s->budget--) { s->failed_pc=0x0c0b202au; return 0; }
target=r[13];
r[16]=code_base|0x0c0b202eu;
r[14]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b202eu) { target=s->pc; goto dispatch; }
goto P_0c0b202e;
P_0c0b202c: /* original 7e40, guest PC 0x0c0b202c */
if(!s->budget--) { s->failed_pc=0x0c0b202cu; return 0; }
r[14]+=0x00000040u;
goto P_0c0b202e;
P_0c0b202e: /* original f4fc, guest PC 0x0c0b202e */
if(!s->budget--) { s->failed_pc=0x0c0b202eu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b2030;
P_0c0b2030: /* original 4c0b, guest PC 0x0c0b2030 */
if(!s->budget--) { s->failed_pc=0x0c0b2030u; return 0; }
target=r[12];
r[16]=code_base|0x0c0b2034u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2034u) { target=s->pc; goto dispatch; }
goto P_0c0b2034;
P_0c0b2032: /* original 64f2, guest PC 0x0c0b2032 */
if(!s->budget--) { s->failed_pc=0x0c0b2032u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b2034;
P_0c0b2034: /* original 4d0b, guest PC 0x0c0b2034 */
if(!s->budget--) { s->failed_pc=0x0c0b2034u; return 0; }
target=r[13];
r[16]=code_base|0x0c0b2038u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2038u) { target=s->pc; goto dispatch; }
goto P_0c0b2038;
P_0c0b2036: /* original 64e3, guest PC 0x0c0b2036 */
if(!s->budget--) { s->failed_pc=0x0c0b2036u; return 0; }
r[4]=r[14];
goto P_0c0b2038;
P_0c0b2038: /* original 9014, guest PC 0x0c0b2038 */
if(!s->budget--) { s->failed_pc=0x0c0b2038u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b2064u,2);
goto P_0c0b203a;
P_0c0b203a: /* original f4fc, guest PC 0x0c0b203a */
if(!s->budget--) { s->failed_pc=0x0c0b203au; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0b203c;
P_0c0b203c: /* original 4a0b, guest PC 0x0c0b203c */
if(!s->budget--) { s->failed_pc=0x0c0b203cu; return 0; }
target=r[10];
r[16]=code_base|0x0c0b2040u;
r[4]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2040u) { target=s->pc; goto dispatch; }
goto P_0c0b2040;
P_0c0b203e: /* original 04be, guest PC 0x0c0b203e */
if(!s->budget--) { s->failed_pc=0x0c0b203eu; return 0; }
r[4]=read(ram,r[11]+r[0],4);
goto P_0c0b2040;
P_0c0b2040: /* original d310, guest PC 0x0c0b2040 */
if(!s->budget--) { s->failed_pc=0x0c0b2040u; return 0; }
r[3]=read(ram,0x0c0b2084u,4);
goto P_0c0b2042;
P_0c0b2042: /* original 430b, guest PC 0x0c0b2042 */
if(!s->budget--) { s->failed_pc=0x0c0b2042u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b2046u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b2046u) { target=s->pc; goto dispatch; }
goto P_0c0b2046;
P_0c0b2044: /* original 0009, guest PC 0x0c0b2044 */
if(!s->budget--) { s->failed_pc=0x0c0b2044u; return 0; }
goto P_0c0b2046;
P_0c0b2046: /* original 7f08, guest PC 0x0c0b2046 */
if(!s->budget--) { s->failed_pc=0x0c0b2046u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b2048;
P_0c0b2048: /* original 4f26, guest PC 0x0c0b2048 */
if(!s->budget--) { s->failed_pc=0x0c0b2048u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b204a;
P_0c0b204a: /* original fff9, guest PC 0x0c0b204a */
if(!s->budget--) { s->failed_pc=0x0c0b204au; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0b204c;
P_0c0b204c: /* original 68f6, guest PC 0x0c0b204c */
if(!s->budget--) { s->failed_pc=0x0c0b204cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0b204e;
P_0c0b204e: /* original 69f6, guest PC 0x0c0b204e */
if(!s->budget--) { s->failed_pc=0x0c0b204eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b2050;
P_0c0b2050: /* original 6af6, guest PC 0x0c0b2050 */
if(!s->budget--) { s->failed_pc=0x0c0b2050u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b2052;
P_0c0b2052: /* original 6bf6, guest PC 0x0c0b2052 */
if(!s->budget--) { s->failed_pc=0x0c0b2052u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b2054;
P_0c0b2054: /* original 6cf6, guest PC 0x0c0b2054 */
if(!s->budget--) { s->failed_pc=0x0c0b2054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b2056;
P_0c0b2056: /* original 6df6, guest PC 0x0c0b2056 */
if(!s->budget--) { s->failed_pc=0x0c0b2056u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b2058;
P_0c0b2058: /* original 000b, guest PC 0x0c0b2058 */
if(!s->budget--) { s->failed_pc=0x0c0b2058u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b205a: /* original 6ef6, guest PC 0x0c0b205a */
if(!s->budget--) { s->failed_pc=0x0c0b205au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b205cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b205cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
