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
int vf3_away_batch24_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b8caeu: goto P_0c0b8cae;
case 0x0c0b8cb0u: goto P_0c0b8cb0;
case 0x0c0b8cb2u: goto P_0c0b8cb2;
case 0x0c0b8cb4u: goto P_0c0b8cb4;
case 0x0c0b8cb6u: goto P_0c0b8cb6;
case 0x0c0b8cb8u: goto P_0c0b8cb8;
case 0x0c0b8cbau: goto P_0c0b8cba;
case 0x0c0b8cbcu: goto P_0c0b8cbc;
case 0x0c0b8cbeu: goto P_0c0b8cbe;
case 0x0c0b8cc0u: goto P_0c0b8cc0;
case 0x0c0b8cc2u: goto P_0c0b8cc2;
case 0x0c0b8cc4u: goto P_0c0b8cc4;
case 0x0c0b8cc6u: goto P_0c0b8cc6;
case 0x0c0b8cc8u: goto P_0c0b8cc8;
case 0x0c0b8ccau: goto P_0c0b8cca;
case 0x0c0b8cccu: goto P_0c0b8ccc;
case 0x0c0b8cceu: goto P_0c0b8cce;
case 0x0c0b8cd0u: goto P_0c0b8cd0;
case 0x0c0b8cd2u: goto P_0c0b8cd2;
case 0x0c0b8cd4u: goto P_0c0b8cd4;
case 0x0c0b8cd6u: goto P_0c0b8cd6;
case 0x0c0b8cd8u: goto P_0c0b8cd8;
case 0x0c0b8cdau: goto P_0c0b8cda;
case 0x0c0b8cdcu: goto P_0c0b8cdc;
case 0x0c0b8cdeu: goto P_0c0b8cde;
case 0x0c0b8ce0u: goto P_0c0b8ce0;
case 0x0c0b8ce2u: goto P_0c0b8ce2;
case 0x0c0b8ce4u: goto P_0c0b8ce4;
case 0x0c0b8ce6u: goto P_0c0b8ce6;
case 0x0c0b8ce8u: goto P_0c0b8ce8;
case 0x0c0b8ceau: goto P_0c0b8cea;
case 0x0c0b8cecu: goto P_0c0b8cec;
case 0x0c0b8ceeu: goto P_0c0b8cee;
case 0x0c0b8cf0u: goto P_0c0b8cf0;
case 0x0c0b8cf2u: goto P_0c0b8cf2;
case 0x0c0b8cf4u: goto P_0c0b8cf4;
case 0x0c0b8cf6u: goto P_0c0b8cf6;
case 0x0c0b8cf8u: goto P_0c0b8cf8;
case 0x0c0b8cfau: goto P_0c0b8cfa;
case 0x0c0b8cfcu: goto P_0c0b8cfc;
case 0x0c0b8cfeu: goto P_0c0b8cfe;
case 0x0c0b8d00u: goto P_0c0b8d00;
case 0x0c0b8d02u: goto P_0c0b8d02;
case 0x0c0b8d04u: goto P_0c0b8d04;
case 0x0c0b8d06u: goto P_0c0b8d06;
case 0x0c0b8d08u: goto P_0c0b8d08;
case 0x0c0b8d0au: goto P_0c0b8d0a;
case 0x0c0b8d0cu: goto P_0c0b8d0c;
case 0x0c0b8d0eu: goto P_0c0b8d0e;
case 0x0c0b8d10u: goto P_0c0b8d10;
case 0x0c0b8d12u: goto P_0c0b8d12;
case 0x0c0b8d14u: goto P_0c0b8d14;
case 0x0c0b8d16u: goto P_0c0b8d16;
case 0x0c0b8d18u: goto P_0c0b8d18;
case 0x0c0b8d1au: goto P_0c0b8d1a;
case 0x0c0b8d1cu: goto P_0c0b8d1c;
case 0x0c0b8d1eu: goto P_0c0b8d1e;
case 0x0c0b8d20u: goto P_0c0b8d20;
case 0x0c0b8d22u: goto P_0c0b8d22;
case 0x0c0b8d24u: goto P_0c0b8d24;
case 0x0c0b8d26u: goto P_0c0b8d26;
case 0x0c0b8d28u: goto P_0c0b8d28;
case 0x0c0b8d2au: goto P_0c0b8d2a;
case 0x0c0b8d2cu: goto P_0c0b8d2c;
case 0x0c0b8d2eu: goto P_0c0b8d2e;
case 0x0c0b8d30u: goto P_0c0b8d30;
case 0x0c0b8d32u: goto P_0c0b8d32;
case 0x0c0b8d34u: goto P_0c0b8d34;
case 0x0c0b8d36u: goto P_0c0b8d36;
case 0x0c0b8d38u: goto P_0c0b8d38;
case 0x0c0b8d3au: goto P_0c0b8d3a;
case 0x0c0b8d3cu: goto P_0c0b8d3c;
case 0x0c0b8d3eu: goto P_0c0b8d3e;
case 0x0c0b8d40u: goto P_0c0b8d40;
case 0x0c0b8d42u: goto P_0c0b8d42;
case 0x0c0b8d44u: goto P_0c0b8d44;
case 0x0c0b8d46u: goto P_0c0b8d46;
case 0x0c0b8d48u: goto P_0c0b8d48;
case 0x0c0b8d4au: goto P_0c0b8d4a;
case 0x0c0b8d4cu: goto P_0c0b8d4c;
case 0x0c0b8d4eu: goto P_0c0b8d4e;
case 0x0c0b8d50u: goto P_0c0b8d50;
case 0x0c0b8d52u: goto P_0c0b8d52;
case 0x0c0b8d54u: goto P_0c0b8d54;
case 0x0c0b8d56u: goto P_0c0b8d56;
case 0x0c0b8d58u: goto P_0c0b8d58;
case 0x0c0b8d5au: goto P_0c0b8d5a;
case 0x0c0b8d5cu: goto P_0c0b8d5c;
case 0x0c0b8d5eu: goto P_0c0b8d5e;
case 0x0c0b8d60u: goto P_0c0b8d60;
case 0x0c0b8d62u: goto P_0c0b8d62;
case 0x0c0b8d64u: goto P_0c0b8d64;
case 0x0c0b8d66u: goto P_0c0b8d66;
case 0x0c0b8d68u: goto P_0c0b8d68;
case 0x0c0b8d6au: goto P_0c0b8d6a;
case 0x0c0b8d6cu: goto P_0c0b8d6c;
case 0x0c0b8d6eu: goto P_0c0b8d6e;
case 0x0c0b8d70u: goto P_0c0b8d70;
case 0x0c0b8d72u: goto P_0c0b8d72;
case 0x0c0b8d74u: goto P_0c0b8d74;
case 0x0c0b8d76u: goto P_0c0b8d76;
case 0x0c0b8d78u: goto P_0c0b8d78;
case 0x0c0b8d7au: goto P_0c0b8d7a;
case 0x0c0b8d7cu: goto P_0c0b8d7c;
case 0x0c0b8d7eu: goto P_0c0b8d7e;
case 0x0c0b8d80u: goto P_0c0b8d80;
case 0x0c0b8d82u: goto P_0c0b8d82;
case 0x0c0b8d84u: goto P_0c0b8d84;
case 0x0c0b8d86u: goto P_0c0b8d86;
case 0x0c0b8d88u: goto P_0c0b8d88;
case 0x0c0b8d8au: goto P_0c0b8d8a;
case 0x0c0b8d8cu: goto P_0c0b8d8c;
case 0x0c0b8d8eu: goto P_0c0b8d8e;
case 0x0c0b8d90u: goto P_0c0b8d90;
case 0x0c0b8d92u: goto P_0c0b8d92;
case 0x0c0b8d94u: goto P_0c0b8d94;
case 0x0c0b8d96u: goto P_0c0b8d96;
case 0x0c0b8d98u: goto P_0c0b8d98;
case 0x0c0b8d9au: goto P_0c0b8d9a;
case 0x0c0b8d9cu: goto P_0c0b8d9c;
case 0x0c0b8d9eu: goto P_0c0b8d9e;
case 0x0c0b8da0u: goto P_0c0b8da0;
case 0x0c0b8da2u: goto P_0c0b8da2;
case 0x0c0b8da4u: goto P_0c0b8da4;
case 0x0c0b8da6u: goto P_0c0b8da6;
case 0x0c0b8da8u: goto P_0c0b8da8;
case 0x0c0b8daau: goto P_0c0b8daa;
case 0x0c0b8dacu: goto P_0c0b8dac;
case 0x0c0b8daeu: goto P_0c0b8dae;
case 0x0c0b8db0u: goto P_0c0b8db0;
case 0x0c0b8db2u: goto P_0c0b8db2;
case 0x0c0b8db4u: goto P_0c0b8db4;
case 0x0c0b8db6u: goto P_0c0b8db6;
case 0x0c0b8db8u: goto P_0c0b8db8;
case 0x0c0b8dbau: goto P_0c0b8dba;
case 0x0c0b8dbcu: goto P_0c0b8dbc;
case 0x0c0b8dbeu: goto P_0c0b8dbe;
case 0x0c0b8dc0u: goto P_0c0b8dc0;
case 0x0c0b8dc2u: goto P_0c0b8dc2;
case 0x0c0b8dc4u: goto P_0c0b8dc4;
case 0x0c0b8dc6u: goto P_0c0b8dc6;
case 0x0c0b8dc8u: goto P_0c0b8dc8;
case 0x0c0b8dcau: goto P_0c0b8dca;
case 0x0c0b8dccu: goto P_0c0b8dcc;
case 0x0c0b8dceu: goto P_0c0b8dce;
case 0x0c0b8dd0u: goto P_0c0b8dd0;
case 0x0c0b8dd2u: goto P_0c0b8dd2;
case 0x0c0b8dd4u: goto P_0c0b8dd4;
case 0x0c0b8dd6u: goto P_0c0b8dd6;
case 0x0c0b8dd8u: goto P_0c0b8dd8;
case 0x0c0b8ddau: goto P_0c0b8dda;
case 0x0c0b8ddcu: goto P_0c0b8ddc;
case 0x0c0b8ddeu: goto P_0c0b8dde;
case 0x0c0b8de0u: goto P_0c0b8de0;
case 0x0c0b8de2u: goto P_0c0b8de2;
case 0x0c0b8de4u: goto P_0c0b8de4;
case 0x0c0b8de6u: goto P_0c0b8de6;
case 0x0c0b8de8u: goto P_0c0b8de8;
case 0x0c0b8deau: goto P_0c0b8dea;
case 0x0c0b8decu: goto P_0c0b8dec;
case 0x0c0b8deeu: goto P_0c0b8dee;
case 0x0c0b8df0u: goto P_0c0b8df0;
case 0x0c0b8df2u: goto P_0c0b8df2;
case 0x0c0b8df4u: goto P_0c0b8df4;
case 0x0c0b8df6u: goto P_0c0b8df6;
case 0x0c0b8df8u: goto P_0c0b8df8;
case 0x0c0b8dfau: goto P_0c0b8dfa;
case 0x0c0b8dfcu: goto P_0c0b8dfc;
case 0x0c0b8dfeu: goto P_0c0b8dfe;
case 0x0c0b8e00u: goto P_0c0b8e00;
case 0x0c0b8e02u: goto P_0c0b8e02;
case 0x0c0b8e04u: goto P_0c0b8e04;
case 0x0c0b8e06u: goto P_0c0b8e06;
case 0x0c0b8e08u: goto P_0c0b8e08;
case 0x0c0b8e0au: goto P_0c0b8e0a;
case 0x0c0b8e0cu: goto P_0c0b8e0c;
case 0x0c0b8e0eu: goto P_0c0b8e0e;
case 0x0c0b8e10u: goto P_0c0b8e10;
case 0x0c0b8e12u: goto P_0c0b8e12;
case 0x0c0b8e14u: goto P_0c0b8e14;
case 0x0c0b8e16u: goto P_0c0b8e16;
case 0x0c0b8e18u: goto P_0c0b8e18;
case 0x0c0b8e80u: goto P_0c0b8e80;
case 0x0c0b8e82u: goto P_0c0b8e82;
case 0x0c0b8e84u: goto P_0c0b8e84;
case 0x0c0b8e86u: goto P_0c0b8e86;
case 0x0c0b8e88u: goto P_0c0b8e88;
case 0x0c0b8e8au: goto P_0c0b8e8a;
case 0x0c0b8e8cu: goto P_0c0b8e8c;
case 0x0c0b8e8eu: goto P_0c0b8e8e;
case 0x0c0b8e90u: goto P_0c0b8e90;
case 0x0c0b8e92u: goto P_0c0b8e92;
case 0x0c0b8e94u: goto P_0c0b8e94;
case 0x0c0b8e96u: goto P_0c0b8e96;
case 0x0c0b8e98u: goto P_0c0b8e98;
case 0x0c0b8e9au: goto P_0c0b8e9a;
case 0x0c0b8e9cu: goto P_0c0b8e9c;
case 0x0c0b8e9eu: goto P_0c0b8e9e;
case 0x0c0b8ea0u: goto P_0c0b8ea0;
case 0x0c0b8ea2u: goto P_0c0b8ea2;
case 0x0c0b8ea4u: goto P_0c0b8ea4;
case 0x0c0b8ea6u: goto P_0c0b8ea6;
case 0x0c0b8ea8u: goto P_0c0b8ea8;
case 0x0c0b8eaau: goto P_0c0b8eaa;
case 0x0c0b8eacu: goto P_0c0b8eac;
case 0x0c0b8eaeu: goto P_0c0b8eae;
case 0x0c0b8eb0u: goto P_0c0b8eb0;
case 0x0c0b8eb2u: goto P_0c0b8eb2;
case 0x0c0b8eb4u: goto P_0c0b8eb4;
case 0x0c0b8eb6u: goto P_0c0b8eb6;
case 0x0c0b8eb8u: goto P_0c0b8eb8;
case 0x0c0b8ebau: goto P_0c0b8eba;
case 0x0c0b8ebcu: goto P_0c0b8ebc;
case 0x0c0b8ebeu: goto P_0c0b8ebe;
case 0x0c0b8ec0u: goto P_0c0b8ec0;
case 0x0c0b8ec2u: goto P_0c0b8ec2;
case 0x0c0b8ec4u: goto P_0c0b8ec4;
case 0x0c0b8ec6u: goto P_0c0b8ec6;
case 0x0c0b8ec8u: goto P_0c0b8ec8;
case 0x0c0b8ecau: goto P_0c0b8eca;
case 0x0c0b8eccu: goto P_0c0b8ecc;
case 0x0c0b8eceu: goto P_0c0b8ece;
case 0x0c0b8ed0u: goto P_0c0b8ed0;
case 0x0c0b8ed2u: goto P_0c0b8ed2;
case 0x0c0b8ed4u: goto P_0c0b8ed4;
case 0x0c0b8ed6u: goto P_0c0b8ed6;
case 0x0c0b8ed8u: goto P_0c0b8ed8;
case 0x0c0b8edau: goto P_0c0b8eda;
case 0x0c0b8edcu: goto P_0c0b8edc;
case 0x0c0b8edeu: goto P_0c0b8ede;
case 0x0c0b8ee0u: goto P_0c0b8ee0;
case 0x0c0b8ee2u: goto P_0c0b8ee2;
case 0x0c0b8ee4u: goto P_0c0b8ee4;
case 0x0c0b8ee6u: goto P_0c0b8ee6;
case 0x0c0b8ee8u: goto P_0c0b8ee8;
case 0x0c0b8eeau: goto P_0c0b8eea;
case 0x0c0b8eecu: goto P_0c0b8eec;
case 0x0c0b8eeeu: goto P_0c0b8eee;
case 0x0c0b8ef0u: goto P_0c0b8ef0;
case 0x0c0b8ef2u: goto P_0c0b8ef2;
case 0x0c0b8ef4u: goto P_0c0b8ef4;
case 0x0c0b8ef6u: goto P_0c0b8ef6;
case 0x0c0b8ef8u: goto P_0c0b8ef8;
case 0x0c0b8efau: goto P_0c0b8efa;
case 0x0c0b8efcu: goto P_0c0b8efc;
case 0x0c0b8efeu: goto P_0c0b8efe;
case 0x0c0b8f00u: goto P_0c0b8f00;
case 0x0c0b8f02u: goto P_0c0b8f02;
case 0x0c0b8f04u: goto P_0c0b8f04;
case 0x0c0b8f06u: goto P_0c0b8f06;
case 0x0c0b8f08u: goto P_0c0b8f08;
case 0x0c0b8f0au: goto P_0c0b8f0a;
case 0x0c0b8f0cu: goto P_0c0b8f0c;
case 0x0c0b8f0eu: goto P_0c0b8f0e;
case 0x0c0b8f10u: goto P_0c0b8f10;
case 0x0c0b8f12u: goto P_0c0b8f12;
case 0x0c0b8f14u: goto P_0c0b8f14;
case 0x0c0b8f16u: goto P_0c0b8f16;
case 0x0c0b8f18u: goto P_0c0b8f18;
case 0x0c0b8f1au: goto P_0c0b8f1a;
case 0x0c0b8f1cu: goto P_0c0b8f1c;
case 0x0c0b8f1eu: goto P_0c0b8f1e;
case 0x0c0b8f20u: goto P_0c0b8f20;
case 0x0c0b8f22u: goto P_0c0b8f22;
case 0x0c0b8f24u: goto P_0c0b8f24;
case 0x0c0b8f26u: goto P_0c0b8f26;
case 0x0c0b8f28u: goto P_0c0b8f28;
case 0x0c0b8f2au: goto P_0c0b8f2a;
case 0x0c0b8f2cu: goto P_0c0b8f2c;
case 0x0c0b8f2eu: goto P_0c0b8f2e;
case 0x0c0b8f30u: goto P_0c0b8f30;
case 0x0c0b8f32u: goto P_0c0b8f32;
case 0x0c0b8f34u: goto P_0c0b8f34;
case 0x0c0b8f36u: goto P_0c0b8f36;
case 0x0c0b8f38u: goto P_0c0b8f38;
case 0x0c0b8f3au: goto P_0c0b8f3a;
case 0x0c0b8f3cu: goto P_0c0b8f3c;
case 0x0c0b8f3eu: goto P_0c0b8f3e;
case 0x0c0b8f40u: goto P_0c0b8f40;
case 0x0c0b8f42u: goto P_0c0b8f42;
case 0x0c0b8f44u: goto P_0c0b8f44;
case 0x0c0b8f46u: goto P_0c0b8f46;
case 0x0c0b8f48u: goto P_0c0b8f48;
case 0x0c0b8f4au: goto P_0c0b8f4a;
case 0x0c0b8f4cu: goto P_0c0b8f4c;
case 0x0c0b8f4eu: goto P_0c0b8f4e;
case 0x0c0b8f50u: goto P_0c0b8f50;
case 0x0c0b8f52u: goto P_0c0b8f52;
case 0x0c0b8f54u: goto P_0c0b8f54;
case 0x0c0b8f56u: goto P_0c0b8f56;
case 0x0c0b8f58u: goto P_0c0b8f58;
case 0x0c0b8f5au: goto P_0c0b8f5a;
case 0x0c0b8f5cu: goto P_0c0b8f5c;
case 0x0c0b8f5eu: goto P_0c0b8f5e;
case 0x0c0b8f60u: goto P_0c0b8f60;
case 0x0c0b8f62u: goto P_0c0b8f62;
case 0x0c0b8f64u: goto P_0c0b8f64;
case 0x0c0b8f66u: goto P_0c0b8f66;
case 0x0c0b8f68u: goto P_0c0b8f68;
case 0x0c0b8f6au: goto P_0c0b8f6a;
case 0x0c0b8f6cu: goto P_0c0b8f6c;
case 0x0c0b8f6eu: goto P_0c0b8f6e;
case 0x0c0b8f70u: goto P_0c0b8f70;
case 0x0c0b8f72u: goto P_0c0b8f72;
case 0x0c0b8f74u: goto P_0c0b8f74;
case 0x0c0b8f76u: goto P_0c0b8f76;
case 0x0c0b8f78u: goto P_0c0b8f78;
case 0x0c0b8f7au: goto P_0c0b8f7a;
case 0x0c0b8f7cu: goto P_0c0b8f7c;
case 0x0c0b8f7eu: goto P_0c0b8f7e;
case 0x0c0b8f80u: goto P_0c0b8f80;
case 0x0c0b8f82u: goto P_0c0b8f82;
case 0x0c0b8f84u: goto P_0c0b8f84;
case 0x0c0b8f86u: goto P_0c0b8f86;
case 0x0c0b8f88u: goto P_0c0b8f88;
case 0x0c0b8f8au: goto P_0c0b8f8a;
case 0x0c0b8f8cu: goto P_0c0b8f8c;
case 0x0c0b8f8eu: goto P_0c0b8f8e;
case 0x0c0b8f90u: goto P_0c0b8f90;
case 0x0c0b8f92u: goto P_0c0b8f92;
case 0x0c0b8f94u: goto P_0c0b8f94;
case 0x0c0b8f96u: goto P_0c0b8f96;
case 0x0c0b8f98u: goto P_0c0b8f98;
case 0x0c0b8f9au: goto P_0c0b8f9a;
case 0x0c0b8f9cu: goto P_0c0b8f9c;
case 0x0c0b8f9eu: goto P_0c0b8f9e;
case 0x0c0b8fa0u: goto P_0c0b8fa0;
case 0x0c0b8fa2u: goto P_0c0b8fa2;
case 0x0c0b8fa4u: goto P_0c0b8fa4;
case 0x0c0b8fa6u: goto P_0c0b8fa6;
case 0x0c0b8fa8u: goto P_0c0b8fa8;
case 0x0c0b8faau: goto P_0c0b8faa;
case 0x0c0b8facu: goto P_0c0b8fac;
case 0x0c0b8faeu: goto P_0c0b8fae;
case 0x0c0b8fb0u: goto P_0c0b8fb0;
case 0x0c0b8fb2u: goto P_0c0b8fb2;
case 0x0c0b8fb4u: goto P_0c0b8fb4;
case 0x0c0b8fb6u: goto P_0c0b8fb6;
case 0x0c0b8fb8u: goto P_0c0b8fb8;
case 0x0c0b8fbau: goto P_0c0b8fba;
case 0x0c0b8fbcu: goto P_0c0b8fbc;
case 0x0c0b8fbeu: goto P_0c0b8fbe;
case 0x0c0b8fc0u: goto P_0c0b8fc0;
case 0x0c0b8fc2u: goto P_0c0b8fc2;
case 0x0c0b8fc4u: goto P_0c0b8fc4;
case 0x0c0b8fc6u: goto P_0c0b8fc6;
case 0x0c0b8fc8u: goto P_0c0b8fc8;
case 0x0c0b8fcau: goto P_0c0b8fca;
case 0x0c0b8fccu: goto P_0c0b8fcc;
case 0x0c0b8fceu: goto P_0c0b8fce;
case 0x0c0b8fd0u: goto P_0c0b8fd0;
case 0x0c0b8fd2u: goto P_0c0b8fd2;
case 0x0c0b8fd4u: goto P_0c0b8fd4;
case 0x0c0b8fd6u: goto P_0c0b8fd6;
case 0x0c0b8fd8u: goto P_0c0b8fd8;
case 0x0c0b8fdau: goto P_0c0b8fda;
case 0x0c0b8fdcu: goto P_0c0b8fdc;
case 0x0c0b8fdeu: goto P_0c0b8fde;
case 0x0c0b8fe0u: goto P_0c0b8fe0;
case 0x0c0b8fe2u: goto P_0c0b8fe2;
case 0x0c0b8fe4u: goto P_0c0b8fe4;
case 0x0c0b8fe6u: goto P_0c0b8fe6;
case 0x0c0b8fe8u: goto P_0c0b8fe8;
case 0x0c0b8feau: goto P_0c0b8fea;
case 0x0c0b8fecu: goto P_0c0b8fec;
case 0x0c0b8feeu: goto P_0c0b8fee;
case 0x0c0b8ff0u: goto P_0c0b8ff0;
case 0x0c0b9052u: goto P_0c0b9052;
case 0x0c0b9054u: goto P_0c0b9054;
case 0x0c0b9056u: goto P_0c0b9056;
case 0x0c0b9058u: goto P_0c0b9058;
case 0x0c0b905au: goto P_0c0b905a;
case 0x0c0b905cu: goto P_0c0b905c;
case 0x0c0b905eu: goto P_0c0b905e;
case 0x0c0b9060u: goto P_0c0b9060;
case 0x0c0b9062u: goto P_0c0b9062;
case 0x0c0b9064u: goto P_0c0b9064;
case 0x0c0b9066u: goto P_0c0b9066;
case 0x0c0b9068u: goto P_0c0b9068;
case 0x0c0b906au: goto P_0c0b906a;
case 0x0c0b906cu: goto P_0c0b906c;
case 0x0c0b906eu: goto P_0c0b906e;
case 0x0c0b9070u: goto P_0c0b9070;
case 0x0c0b9072u: goto P_0c0b9072;
case 0x0c0b9074u: goto P_0c0b9074;
case 0x0c0b9076u: goto P_0c0b9076;
case 0x0c0b9078u: goto P_0c0b9078;
case 0x0c0b907au: goto P_0c0b907a;
case 0x0c0b907cu: goto P_0c0b907c;
case 0x0c0b907eu: goto P_0c0b907e;
case 0x0c0b9080u: goto P_0c0b9080;
case 0x0c0b9082u: goto P_0c0b9082;
case 0x0c0b9084u: goto P_0c0b9084;
case 0x0c0b9086u: goto P_0c0b9086;
case 0x0c0b9088u: goto P_0c0b9088;
case 0x0c0b908au: goto P_0c0b908a;
case 0x0c0b908cu: goto P_0c0b908c;
case 0x0c0b908eu: goto P_0c0b908e;
case 0x0c0b9090u: goto P_0c0b9090;
case 0x0c0b9092u: goto P_0c0b9092;
case 0x0c0b9094u: goto P_0c0b9094;
case 0x0c0b9096u: goto P_0c0b9096;
case 0x0c0b9098u: goto P_0c0b9098;
case 0x0c0b909au: goto P_0c0b909a;
case 0x0c0b909cu: goto P_0c0b909c;
case 0x0c0b909eu: goto P_0c0b909e;
case 0x0c0b90a0u: goto P_0c0b90a0;
case 0x0c0b90a2u: goto P_0c0b90a2;
case 0x0c0b90a4u: goto P_0c0b90a4;
case 0x0c0b90a6u: goto P_0c0b90a6;
case 0x0c0b90a8u: goto P_0c0b90a8;
case 0x0c0b90aau: goto P_0c0b90aa;
case 0x0c0b90acu: goto P_0c0b90ac;
case 0x0c0b90aeu: goto P_0c0b90ae;
case 0x0c0b90b0u: goto P_0c0b90b0;
case 0x0c0b90b2u: goto P_0c0b90b2;
case 0x0c0b90b4u: goto P_0c0b90b4;
case 0x0c0b90b6u: goto P_0c0b90b6;
case 0x0c0b90b8u: goto P_0c0b90b8;
case 0x0c0b90bau: goto P_0c0b90ba;
case 0x0c0b90bcu: goto P_0c0b90bc;
case 0x0c0b90beu: goto P_0c0b90be;
case 0x0c0b90c0u: goto P_0c0b90c0;
case 0x0c0b90c2u: goto P_0c0b90c2;
case 0x0c0b90c4u: goto P_0c0b90c4;
case 0x0c0b90c6u: goto P_0c0b90c6;
case 0x0c0b90c8u: goto P_0c0b90c8;
case 0x0c0b90cau: goto P_0c0b90ca;
case 0x0c0b90ccu: goto P_0c0b90cc;
case 0x0c0b90ceu: goto P_0c0b90ce;
case 0x0c0b90d0u: goto P_0c0b90d0;
case 0x0c0b90d2u: goto P_0c0b90d2;
case 0x0c0b90d4u: goto P_0c0b90d4;
case 0x0c0b90d6u: goto P_0c0b90d6;
case 0x0c0b90d8u: goto P_0c0b90d8;
case 0x0c0b90dau: goto P_0c0b90da;
case 0x0c0b90dcu: goto P_0c0b90dc;
case 0x0c0b90deu: goto P_0c0b90de;
case 0x0c0b90e0u: goto P_0c0b90e0;
case 0x0c0b90e2u: goto P_0c0b90e2;
case 0x0c0b90e4u: goto P_0c0b90e4;
case 0x0c0b90e6u: goto P_0c0b90e6;
case 0x0c0b90e8u: goto P_0c0b90e8;
case 0x0c0b90eau: goto P_0c0b90ea;
case 0x0c0b90ecu: goto P_0c0b90ec;
case 0x0c0b90eeu: goto P_0c0b90ee;
case 0x0c0b90f0u: goto P_0c0b90f0;
case 0x0c0b90f2u: goto P_0c0b90f2;
case 0x0c0b90f4u: goto P_0c0b90f4;
case 0x0c0b90f6u: goto P_0c0b90f6;
case 0x0c0b90f8u: goto P_0c0b90f8;
case 0x0c0b90fau: goto P_0c0b90fa;
case 0x0c0b90fcu: goto P_0c0b90fc;
case 0x0c0b90feu: goto P_0c0b90fe;
case 0x0c0b9100u: goto P_0c0b9100;
case 0x0c0b9102u: goto P_0c0b9102;
case 0x0c0b9104u: goto P_0c0b9104;
case 0x0c0b9106u: goto P_0c0b9106;
case 0x0c0b9108u: goto P_0c0b9108;
case 0x0c0b910au: goto P_0c0b910a;
case 0x0c0b910cu: goto P_0c0b910c;
case 0x0c0b910eu: goto P_0c0b910e;
case 0x0c0b9110u: goto P_0c0b9110;
case 0x0c0b9112u: goto P_0c0b9112;
case 0x0c0b9114u: goto P_0c0b9114;
case 0x0c0b9116u: goto P_0c0b9116;
case 0x0c0b9118u: goto P_0c0b9118;
case 0x0c0b911au: goto P_0c0b911a;
case 0x0c0b911cu: goto P_0c0b911c;
case 0x0c0b911eu: goto P_0c0b911e;
case 0x0c0b9120u: goto P_0c0b9120;
case 0x0c0b9122u: goto P_0c0b9122;
case 0x0c0b9124u: goto P_0c0b9124;
case 0x0c0b9126u: goto P_0c0b9126;
case 0x0c0b9128u: goto P_0c0b9128;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b8cae: /* original 2fe6, guest PC 0x0c0b8cae */
if(!s->budget--) { s->failed_pc=0x0c0b8caeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8cb0;
P_0c0b8cb0: /* original 2fd6, guest PC 0x0c0b8cb0 */
if(!s->budget--) { s->failed_pc=0x0c0b8cb0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8cb2;
P_0c0b8cb2: /* original 2fc6, guest PC 0x0c0b8cb2 */
if(!s->budget--) { s->failed_pc=0x0c0b8cb2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8cb4;
P_0c0b8cb4: /* original 2fb6, guest PC 0x0c0b8cb4 */
if(!s->budget--) { s->failed_pc=0x0c0b8cb4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8cb6;
P_0c0b8cb6: /* original 2fa6, guest PC 0x0c0b8cb6 */
if(!s->budget--) { s->failed_pc=0x0c0b8cb6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8cb8;
P_0c0b8cb8: /* original 2f96, guest PC 0x0c0b8cb8 */
if(!s->budget--) { s->failed_pc=0x0c0b8cb8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b8cba;
P_0c0b8cba: /* original 4f22, guest PC 0x0c0b8cba */
if(!s->budget--) { s->failed_pc=0x0c0b8cbau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b8cbc;
P_0c0b8cbc: /* original 5d44, guest PC 0x0c0b8cbc */
if(!s->budget--) { s->failed_pc=0x0c0b8cbcu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b8cbe;
P_0c0b8cbe: /* original 94ac, guest PC 0x0c0b8cbe */
if(!s->budget--) { s->failed_pc=0x0c0b8cbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e1au,2);
goto P_0c0b8cc0;
P_0c0b8cc0: /* original de6e, guest PC 0x0c0b8cc0 */
if(!s->budget--) { s->failed_pc=0x0c0b8cc0u; return 0; }
r[14]=read(ram,0x0c0b8e7cu,4);
goto P_0c0b8cc2;
P_0c0b8cc2: /* original 7ff8, guest PC 0x0c0b8cc2 */
if(!s->budget--) { s->failed_pc=0x0c0b8cc2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b8cc4;
P_0c0b8cc4: /* original 4e0b, guest PC 0x0c0b8cc4 */
if(!s->budget--) { s->failed_pc=0x0c0b8cc4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cc8u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cc8u) { target=s->pc; goto dispatch; }
goto P_0c0b8cc8;
P_0c0b8cc6: /* original 65d2, guest PC 0x0c0b8cc6 */
if(!s->budget--) { s->failed_pc=0x0c0b8cc6u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b8cc8;
P_0c0b8cc8: /* original 94a8, guest PC 0x0c0b8cc8 */
if(!s->budget--) { s->failed_pc=0x0c0b8cc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e1cu,2);
goto P_0c0b8cca;
P_0c0b8cca: /* original 4e0b, guest PC 0x0c0b8cca */
if(!s->budget--) { s->failed_pc=0x0c0b8ccau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cceu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cceu) { target=s->pc; goto dispatch; }
goto P_0c0b8cce;
P_0c0b8ccc: /* original 55d1, guest PC 0x0c0b8ccc */
if(!s->budget--) { s->failed_pc=0x0c0b8cccu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b8cce;
P_0c0b8cce: /* original 94a6, guest PC 0x0c0b8cce */
if(!s->budget--) { s->failed_pc=0x0c0b8cceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e1eu,2);
goto P_0c0b8cd0;
P_0c0b8cd0: /* original 4e0b, guest PC 0x0c0b8cd0 */
if(!s->budget--) { s->failed_pc=0x0c0b8cd0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cd4u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cd4u) { target=s->pc; goto dispatch; }
goto P_0c0b8cd4;
P_0c0b8cd2: /* original 55d2, guest PC 0x0c0b8cd2 */
if(!s->budget--) { s->failed_pc=0x0c0b8cd2u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b8cd4;
P_0c0b8cd4: /* original 94a4, guest PC 0x0c0b8cd4 */
if(!s->budget--) { s->failed_pc=0x0c0b8cd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e20u,2);
goto P_0c0b8cd6;
P_0c0b8cd6: /* original 4e0b, guest PC 0x0c0b8cd6 */
if(!s->budget--) { s->failed_pc=0x0c0b8cd6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cdau;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cdau) { target=s->pc; goto dispatch; }
goto P_0c0b8cda;
P_0c0b8cd8: /* original 55d3, guest PC 0x0c0b8cd8 */
if(!s->budget--) { s->failed_pc=0x0c0b8cd8u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b8cda;
P_0c0b8cda: /* original 94a2, guest PC 0x0c0b8cda */
if(!s->budget--) { s->failed_pc=0x0c0b8cdau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e22u,2);
goto P_0c0b8cdc;
P_0c0b8cdc: /* original 4e0b, guest PC 0x0c0b8cdc */
if(!s->budget--) { s->failed_pc=0x0c0b8cdcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ce0u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ce0u) { target=s->pc; goto dispatch; }
goto P_0c0b8ce0;
P_0c0b8cde: /* original 55d4, guest PC 0x0c0b8cde */
if(!s->budget--) { s->failed_pc=0x0c0b8cdeu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b8ce0;
P_0c0b8ce0: /* original 94a0, guest PC 0x0c0b8ce0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ce0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e24u,2);
goto P_0c0b8ce2;
P_0c0b8ce2: /* original 4e0b, guest PC 0x0c0b8ce2 */
if(!s->budget--) { s->failed_pc=0x0c0b8ce2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ce6u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ce6u) { target=s->pc; goto dispatch; }
goto P_0c0b8ce6;
P_0c0b8ce4: /* original 55d5, guest PC 0x0c0b8ce4 */
if(!s->budget--) { s->failed_pc=0x0c0b8ce4u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b8ce6;
P_0c0b8ce6: /* original 949e, guest PC 0x0c0b8ce6 */
if(!s->budget--) { s->failed_pc=0x0c0b8ce6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e26u,2);
goto P_0c0b8ce8;
P_0c0b8ce8: /* original 4e0b, guest PC 0x0c0b8ce8 */
if(!s->budget--) { s->failed_pc=0x0c0b8ce8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cecu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cecu) { target=s->pc; goto dispatch; }
goto P_0c0b8cec;
P_0c0b8cea: /* original 55d6, guest PC 0x0c0b8cea */
if(!s->budget--) { s->failed_pc=0x0c0b8ceau; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b8cec;
P_0c0b8cec: /* original 949c, guest PC 0x0c0b8cec */
if(!s->budget--) { s->failed_pc=0x0c0b8cecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e28u,2);
goto P_0c0b8cee;
P_0c0b8cee: /* original 4e0b, guest PC 0x0c0b8cee */
if(!s->budget--) { s->failed_pc=0x0c0b8ceeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cf2u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cf2u) { target=s->pc; goto dispatch; }
goto P_0c0b8cf2;
P_0c0b8cf0: /* original 55d7, guest PC 0x0c0b8cf0 */
if(!s->budget--) { s->failed_pc=0x0c0b8cf0u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b8cf2;
P_0c0b8cf2: /* original 949a, guest PC 0x0c0b8cf2 */
if(!s->budget--) { s->failed_pc=0x0c0b8cf2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e2au,2);
goto P_0c0b8cf4;
P_0c0b8cf4: /* original 4e0b, guest PC 0x0c0b8cf4 */
if(!s->budget--) { s->failed_pc=0x0c0b8cf4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cf8u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cf8u) { target=s->pc; goto dispatch; }
goto P_0c0b8cf8;
P_0c0b8cf6: /* original 55d8, guest PC 0x0c0b8cf6 */
if(!s->budget--) { s->failed_pc=0x0c0b8cf6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b8cf8;
P_0c0b8cf8: /* original 9498, guest PC 0x0c0b8cf8 */
if(!s->budget--) { s->failed_pc=0x0c0b8cf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e2cu,2);
goto P_0c0b8cfa;
P_0c0b8cfa: /* original 4e0b, guest PC 0x0c0b8cfa */
if(!s->budget--) { s->failed_pc=0x0c0b8cfau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8cfeu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8cfeu) { target=s->pc; goto dispatch; }
goto P_0c0b8cfe;
P_0c0b8cfc: /* original 55d9, guest PC 0x0c0b8cfc */
if(!s->budget--) { s->failed_pc=0x0c0b8cfcu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b8cfe;
P_0c0b8cfe: /* original 9496, guest PC 0x0c0b8cfe */
if(!s->budget--) { s->failed_pc=0x0c0b8cfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e2eu,2);
goto P_0c0b8d00;
P_0c0b8d00: /* original 4e0b, guest PC 0x0c0b8d00 */
if(!s->budget--) { s->failed_pc=0x0c0b8d00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d04u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d04u) { target=s->pc; goto dispatch; }
goto P_0c0b8d04;
P_0c0b8d02: /* original 55da, guest PC 0x0c0b8d02 */
if(!s->budget--) { s->failed_pc=0x0c0b8d02u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b8d04;
P_0c0b8d04: /* original 9494, guest PC 0x0c0b8d04 */
if(!s->budget--) { s->failed_pc=0x0c0b8d04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e30u,2);
goto P_0c0b8d06;
P_0c0b8d06: /* original 4e0b, guest PC 0x0c0b8d06 */
if(!s->budget--) { s->failed_pc=0x0c0b8d06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d0au;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d0au) { target=s->pc; goto dispatch; }
goto P_0c0b8d0a;
P_0c0b8d08: /* original 55db, guest PC 0x0c0b8d08 */
if(!s->budget--) { s->failed_pc=0x0c0b8d08u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b8d0a;
P_0c0b8d0a: /* original 9492, guest PC 0x0c0b8d0a */
if(!s->budget--) { s->failed_pc=0x0c0b8d0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e32u,2);
goto P_0c0b8d0c;
P_0c0b8d0c: /* original 4e0b, guest PC 0x0c0b8d0c */
if(!s->budget--) { s->failed_pc=0x0c0b8d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d10u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d10u) { target=s->pc; goto dispatch; }
goto P_0c0b8d10;
P_0c0b8d0e: /* original 55dc, guest PC 0x0c0b8d0e */
if(!s->budget--) { s->failed_pc=0x0c0b8d0eu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b8d10;
P_0c0b8d10: /* original 9490, guest PC 0x0c0b8d10 */
if(!s->budget--) { s->failed_pc=0x0c0b8d10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e34u,2);
goto P_0c0b8d12;
P_0c0b8d12: /* original 4e0b, guest PC 0x0c0b8d12 */
if(!s->budget--) { s->failed_pc=0x0c0b8d12u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d16u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d16u) { target=s->pc; goto dispatch; }
goto P_0c0b8d16;
P_0c0b8d14: /* original 55dd, guest PC 0x0c0b8d14 */
if(!s->budget--) { s->failed_pc=0x0c0b8d14u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b8d16;
P_0c0b8d16: /* original 948e, guest PC 0x0c0b8d16 */
if(!s->budget--) { s->failed_pc=0x0c0b8d16u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e36u,2);
goto P_0c0b8d18;
P_0c0b8d18: /* original 4e0b, guest PC 0x0c0b8d18 */
if(!s->budget--) { s->failed_pc=0x0c0b8d18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d1cu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d1cu) { target=s->pc; goto dispatch; }
goto P_0c0b8d1c;
P_0c0b8d1a: /* original 55de, guest PC 0x0c0b8d1a */
if(!s->budget--) { s->failed_pc=0x0c0b8d1au; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b8d1c;
P_0c0b8d1c: /* original 948c, guest PC 0x0c0b8d1c */
if(!s->budget--) { s->failed_pc=0x0c0b8d1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e38u,2);
goto P_0c0b8d1e;
P_0c0b8d1e: /* original 4e0b, guest PC 0x0c0b8d1e */
if(!s->budget--) { s->failed_pc=0x0c0b8d1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d22u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d22u) { target=s->pc; goto dispatch; }
goto P_0c0b8d22;
P_0c0b8d20: /* original 55df, guest PC 0x0c0b8d20 */
if(!s->budget--) { s->failed_pc=0x0c0b8d20u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b8d22;
P_0c0b8d22: /* original 948a, guest PC 0x0c0b8d22 */
if(!s->budget--) { s->failed_pc=0x0c0b8d22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e3au,2);
goto P_0c0b8d24;
P_0c0b8d24: /* original e040, guest PC 0x0c0b8d24 */
if(!s->budget--) { s->failed_pc=0x0c0b8d24u; return 0; }
r[0]=0x00000040u;
goto P_0c0b8d26;
P_0c0b8d26: /* original 4e0b, guest PC 0x0c0b8d26 */
if(!s->budget--) { s->failed_pc=0x0c0b8d26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d2au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d2au) { target=s->pc; goto dispatch; }
goto P_0c0b8d2a;
P_0c0b8d28: /* original 05de, guest PC 0x0c0b8d28 */
if(!s->budget--) { s->failed_pc=0x0c0b8d28u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d2a;
P_0c0b8d2a: /* original 9487, guest PC 0x0c0b8d2a */
if(!s->budget--) { s->failed_pc=0x0c0b8d2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e3cu,2);
goto P_0c0b8d2c;
P_0c0b8d2c: /* original e044, guest PC 0x0c0b8d2c */
if(!s->budget--) { s->failed_pc=0x0c0b8d2cu; return 0; }
r[0]=0x00000044u;
goto P_0c0b8d2e;
P_0c0b8d2e: /* original 4e0b, guest PC 0x0c0b8d2e */
if(!s->budget--) { s->failed_pc=0x0c0b8d2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d32u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d32u) { target=s->pc; goto dispatch; }
goto P_0c0b8d32;
P_0c0b8d30: /* original 05de, guest PC 0x0c0b8d30 */
if(!s->budget--) { s->failed_pc=0x0c0b8d30u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d32;
P_0c0b8d32: /* original 9484, guest PC 0x0c0b8d32 */
if(!s->budget--) { s->failed_pc=0x0c0b8d32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e3eu,2);
goto P_0c0b8d34;
P_0c0b8d34: /* original e048, guest PC 0x0c0b8d34 */
if(!s->budget--) { s->failed_pc=0x0c0b8d34u; return 0; }
r[0]=0x00000048u;
goto P_0c0b8d36;
P_0c0b8d36: /* original 4e0b, guest PC 0x0c0b8d36 */
if(!s->budget--) { s->failed_pc=0x0c0b8d36u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d3au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d3au) { target=s->pc; goto dispatch; }
goto P_0c0b8d3a;
P_0c0b8d38: /* original 05de, guest PC 0x0c0b8d38 */
if(!s->budget--) { s->failed_pc=0x0c0b8d38u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d3a;
P_0c0b8d3a: /* original 9481, guest PC 0x0c0b8d3a */
if(!s->budget--) { s->failed_pc=0x0c0b8d3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e40u,2);
goto P_0c0b8d3c;
P_0c0b8d3c: /* original e04c, guest PC 0x0c0b8d3c */
if(!s->budget--) { s->failed_pc=0x0c0b8d3cu; return 0; }
r[0]=0x0000004cu;
goto P_0c0b8d3e;
P_0c0b8d3e: /* original 4e0b, guest PC 0x0c0b8d3e */
if(!s->budget--) { s->failed_pc=0x0c0b8d3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d42u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d42u) { target=s->pc; goto dispatch; }
goto P_0c0b8d42;
P_0c0b8d40: /* original 05de, guest PC 0x0c0b8d40 */
if(!s->budget--) { s->failed_pc=0x0c0b8d40u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d42;
P_0c0b8d42: /* original 947e, guest PC 0x0c0b8d42 */
if(!s->budget--) { s->failed_pc=0x0c0b8d42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e42u,2);
goto P_0c0b8d44;
P_0c0b8d44: /* original e050, guest PC 0x0c0b8d44 */
if(!s->budget--) { s->failed_pc=0x0c0b8d44u; return 0; }
r[0]=0x00000050u;
goto P_0c0b8d46;
P_0c0b8d46: /* original 4e0b, guest PC 0x0c0b8d46 */
if(!s->budget--) { s->failed_pc=0x0c0b8d46u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d4au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d4au) { target=s->pc; goto dispatch; }
goto P_0c0b8d4a;
P_0c0b8d48: /* original 05de, guest PC 0x0c0b8d48 */
if(!s->budget--) { s->failed_pc=0x0c0b8d48u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d4a;
P_0c0b8d4a: /* original 947b, guest PC 0x0c0b8d4a */
if(!s->budget--) { s->failed_pc=0x0c0b8d4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e44u,2);
goto P_0c0b8d4c;
P_0c0b8d4c: /* original e054, guest PC 0x0c0b8d4c */
if(!s->budget--) { s->failed_pc=0x0c0b8d4cu; return 0; }
r[0]=0x00000054u;
goto P_0c0b8d4e;
P_0c0b8d4e: /* original 4e0b, guest PC 0x0c0b8d4e */
if(!s->budget--) { s->failed_pc=0x0c0b8d4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d52u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d52u) { target=s->pc; goto dispatch; }
goto P_0c0b8d52;
P_0c0b8d50: /* original 05de, guest PC 0x0c0b8d50 */
if(!s->budget--) { s->failed_pc=0x0c0b8d50u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d52;
P_0c0b8d52: /* original 9478, guest PC 0x0c0b8d52 */
if(!s->budget--) { s->failed_pc=0x0c0b8d52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e46u,2);
goto P_0c0b8d54;
P_0c0b8d54: /* original e058, guest PC 0x0c0b8d54 */
if(!s->budget--) { s->failed_pc=0x0c0b8d54u; return 0; }
r[0]=0x00000058u;
goto P_0c0b8d56;
P_0c0b8d56: /* original 4e0b, guest PC 0x0c0b8d56 */
if(!s->budget--) { s->failed_pc=0x0c0b8d56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d5au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d5au) { target=s->pc; goto dispatch; }
goto P_0c0b8d5a;
P_0c0b8d58: /* original 05de, guest PC 0x0c0b8d58 */
if(!s->budget--) { s->failed_pc=0x0c0b8d58u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d5a;
P_0c0b8d5a: /* original 9475, guest PC 0x0c0b8d5a */
if(!s->budget--) { s->failed_pc=0x0c0b8d5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e48u,2);
goto P_0c0b8d5c;
P_0c0b8d5c: /* original e05c, guest PC 0x0c0b8d5c */
if(!s->budget--) { s->failed_pc=0x0c0b8d5cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0b8d5e;
P_0c0b8d5e: /* original 4e0b, guest PC 0x0c0b8d5e */
if(!s->budget--) { s->failed_pc=0x0c0b8d5eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d62u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d62u) { target=s->pc; goto dispatch; }
goto P_0c0b8d62;
P_0c0b8d60: /* original 05de, guest PC 0x0c0b8d60 */
if(!s->budget--) { s->failed_pc=0x0c0b8d60u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d62;
P_0c0b8d62: /* original 9472, guest PC 0x0c0b8d62 */
if(!s->budget--) { s->failed_pc=0x0c0b8d62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e4au,2);
goto P_0c0b8d64;
P_0c0b8d64: /* original e060, guest PC 0x0c0b8d64 */
if(!s->budget--) { s->failed_pc=0x0c0b8d64u; return 0; }
r[0]=0x00000060u;
goto P_0c0b8d66;
P_0c0b8d66: /* original 4e0b, guest PC 0x0c0b8d66 */
if(!s->budget--) { s->failed_pc=0x0c0b8d66u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d6au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d6au) { target=s->pc; goto dispatch; }
goto P_0c0b8d6a;
P_0c0b8d68: /* original 05de, guest PC 0x0c0b8d68 */
if(!s->budget--) { s->failed_pc=0x0c0b8d68u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d6a;
P_0c0b8d6a: /* original 946f, guest PC 0x0c0b8d6a */
if(!s->budget--) { s->failed_pc=0x0c0b8d6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e4cu,2);
goto P_0c0b8d6c;
P_0c0b8d6c: /* original e064, guest PC 0x0c0b8d6c */
if(!s->budget--) { s->failed_pc=0x0c0b8d6cu; return 0; }
r[0]=0x00000064u;
goto P_0c0b8d6e;
P_0c0b8d6e: /* original 4e0b, guest PC 0x0c0b8d6e */
if(!s->budget--) { s->failed_pc=0x0c0b8d6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d72u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d72u) { target=s->pc; goto dispatch; }
goto P_0c0b8d72;
P_0c0b8d70: /* original 05de, guest PC 0x0c0b8d70 */
if(!s->budget--) { s->failed_pc=0x0c0b8d70u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d72;
P_0c0b8d72: /* original 946c, guest PC 0x0c0b8d72 */
if(!s->budget--) { s->failed_pc=0x0c0b8d72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e4eu,2);
goto P_0c0b8d74;
P_0c0b8d74: /* original e068, guest PC 0x0c0b8d74 */
if(!s->budget--) { s->failed_pc=0x0c0b8d74u; return 0; }
r[0]=0x00000068u;
goto P_0c0b8d76;
P_0c0b8d76: /* original 4e0b, guest PC 0x0c0b8d76 */
if(!s->budget--) { s->failed_pc=0x0c0b8d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d7au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d7au) { target=s->pc; goto dispatch; }
goto P_0c0b8d7a;
P_0c0b8d78: /* original 05de, guest PC 0x0c0b8d78 */
if(!s->budget--) { s->failed_pc=0x0c0b8d78u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d7a;
P_0c0b8d7a: /* original 9469, guest PC 0x0c0b8d7a */
if(!s->budget--) { s->failed_pc=0x0c0b8d7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e50u,2);
goto P_0c0b8d7c;
P_0c0b8d7c: /* original e06c, guest PC 0x0c0b8d7c */
if(!s->budget--) { s->failed_pc=0x0c0b8d7cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0b8d7e;
P_0c0b8d7e: /* original 4e0b, guest PC 0x0c0b8d7e */
if(!s->budget--) { s->failed_pc=0x0c0b8d7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d82u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d82u) { target=s->pc; goto dispatch; }
goto P_0c0b8d82;
P_0c0b8d80: /* original 05de, guest PC 0x0c0b8d80 */
if(!s->budget--) { s->failed_pc=0x0c0b8d80u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d82;
P_0c0b8d82: /* original 9466, guest PC 0x0c0b8d82 */
if(!s->budget--) { s->failed_pc=0x0c0b8d82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e52u,2);
goto P_0c0b8d84;
P_0c0b8d84: /* original e070, guest PC 0x0c0b8d84 */
if(!s->budget--) { s->failed_pc=0x0c0b8d84u; return 0; }
r[0]=0x00000070u;
goto P_0c0b8d86;
P_0c0b8d86: /* original 4e0b, guest PC 0x0c0b8d86 */
if(!s->budget--) { s->failed_pc=0x0c0b8d86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d8au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d8au) { target=s->pc; goto dispatch; }
goto P_0c0b8d8a;
P_0c0b8d88: /* original 05de, guest PC 0x0c0b8d88 */
if(!s->budget--) { s->failed_pc=0x0c0b8d88u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d8a;
P_0c0b8d8a: /* original 9463, guest PC 0x0c0b8d8a */
if(!s->budget--) { s->failed_pc=0x0c0b8d8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e54u,2);
goto P_0c0b8d8c;
P_0c0b8d8c: /* original e074, guest PC 0x0c0b8d8c */
if(!s->budget--) { s->failed_pc=0x0c0b8d8cu; return 0; }
r[0]=0x00000074u;
goto P_0c0b8d8e;
P_0c0b8d8e: /* original 4e0b, guest PC 0x0c0b8d8e */
if(!s->budget--) { s->failed_pc=0x0c0b8d8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d92u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d92u) { target=s->pc; goto dispatch; }
goto P_0c0b8d92;
P_0c0b8d90: /* original 05de, guest PC 0x0c0b8d90 */
if(!s->budget--) { s->failed_pc=0x0c0b8d90u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d92;
P_0c0b8d92: /* original 9460, guest PC 0x0c0b8d92 */
if(!s->budget--) { s->failed_pc=0x0c0b8d92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e56u,2);
goto P_0c0b8d94;
P_0c0b8d94: /* original e078, guest PC 0x0c0b8d94 */
if(!s->budget--) { s->failed_pc=0x0c0b8d94u; return 0; }
r[0]=0x00000078u;
goto P_0c0b8d96;
P_0c0b8d96: /* original 4e0b, guest PC 0x0c0b8d96 */
if(!s->budget--) { s->failed_pc=0x0c0b8d96u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8d9au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8d9au) { target=s->pc; goto dispatch; }
goto P_0c0b8d9a;
P_0c0b8d98: /* original 05de, guest PC 0x0c0b8d98 */
if(!s->budget--) { s->failed_pc=0x0c0b8d98u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8d9a;
P_0c0b8d9a: /* original 945d, guest PC 0x0c0b8d9a */
if(!s->budget--) { s->failed_pc=0x0c0b8d9au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e58u,2);
goto P_0c0b8d9c;
P_0c0b8d9c: /* original e07c, guest PC 0x0c0b8d9c */
if(!s->budget--) { s->failed_pc=0x0c0b8d9cu; return 0; }
r[0]=0x0000007cu;
goto P_0c0b8d9e;
P_0c0b8d9e: /* original 4e0b, guest PC 0x0c0b8d9e */
if(!s->budget--) { s->failed_pc=0x0c0b8d9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8da2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8da2u) { target=s->pc; goto dispatch; }
goto P_0c0b8da2;
P_0c0b8da0: /* original 05de, guest PC 0x0c0b8da0 */
if(!s->budget--) { s->failed_pc=0x0c0b8da0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8da2;
P_0c0b8da2: /* original 945b, guest PC 0x0c0b8da2 */
if(!s->budget--) { s->failed_pc=0x0c0b8da2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e5cu,2);
goto P_0c0b8da4;
P_0c0b8da4: /* original 9059, guest PC 0x0c0b8da4 */
if(!s->budget--) { s->failed_pc=0x0c0b8da4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e5au,2);
goto P_0c0b8da6;
P_0c0b8da6: /* original 4e0b, guest PC 0x0c0b8da6 */
if(!s->budget--) { s->failed_pc=0x0c0b8da6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8daau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8daau) { target=s->pc; goto dispatch; }
goto P_0c0b8daa;
P_0c0b8da8: /* original 05de, guest PC 0x0c0b8da8 */
if(!s->budget--) { s->failed_pc=0x0c0b8da8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8daa;
P_0c0b8daa: /* original 9558, guest PC 0x0c0b8daa */
if(!s->budget--) { s->failed_pc=0x0c0b8daau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e5eu,2);
goto P_0c0b8dac;
P_0c0b8dac: /* original 35dc, guest PC 0x0c0b8dac */
if(!s->budget--) { s->failed_pc=0x0c0b8dacu; return 0; }
r[5]+=r[13];
goto P_0c0b8dae;
P_0c0b8dae: /* original 2f52, guest PC 0x0c0b8dae */
if(!s->budget--) { s->failed_pc=0x0c0b8daeu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8db0;
P_0c0b8db0: /* original 9456, guest PC 0x0c0b8db0 */
if(!s->budget--) { s->failed_pc=0x0c0b8db0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e60u,2);
goto P_0c0b8db2;
P_0c0b8db2: /* original 4e0b, guest PC 0x0c0b8db2 */
if(!s->budget--) { s->failed_pc=0x0c0b8db2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8db6u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8db6u) { target=s->pc; goto dispatch; }
goto P_0c0b8db6;
P_0c0b8db4: /* original 6552, guest PC 0x0c0b8db4 */
if(!s->budget--) { s->failed_pc=0x0c0b8db4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8db6;
P_0c0b8db6: /* original 9554, guest PC 0x0c0b8db6 */
if(!s->budget--) { s->failed_pc=0x0c0b8db6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e62u,2);
goto P_0c0b8db8;
P_0c0b8db8: /* original 35dc, guest PC 0x0c0b8db8 */
if(!s->budget--) { s->failed_pc=0x0c0b8db8u; return 0; }
r[5]+=r[13];
goto P_0c0b8dba;
P_0c0b8dba: /* original 1f51, guest PC 0x0c0b8dba */
if(!s->budget--) { s->failed_pc=0x0c0b8dbau; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b8dbc;
P_0c0b8dbc: /* original 9452, guest PC 0x0c0b8dbc */
if(!s->budget--) { s->failed_pc=0x0c0b8dbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e64u,2);
goto P_0c0b8dbe;
P_0c0b8dbe: /* original 4e0b, guest PC 0x0c0b8dbe */
if(!s->budget--) { s->failed_pc=0x0c0b8dbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8dc2u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8dc2u) { target=s->pc; goto dispatch; }
goto P_0c0b8dc2;
P_0c0b8dc0: /* original 6552, guest PC 0x0c0b8dc0 */
if(!s->budget--) { s->failed_pc=0x0c0b8dc0u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8dc2;
P_0c0b8dc2: /* original 9050, guest PC 0x0c0b8dc2 */
if(!s->budget--) { s->failed_pc=0x0c0b8dc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e66u,2);
goto P_0c0b8dc4;
P_0c0b8dc4: /* original 05de, guest PC 0x0c0b8dc4 */
if(!s->budget--) { s->failed_pc=0x0c0b8dc4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8dc6;
P_0c0b8dc6: /* original 4e0b, guest PC 0x0c0b8dc6 */
if(!s->budget--) { s->failed_pc=0x0c0b8dc6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8dcau;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8dcau) { target=s->pc; goto dispatch; }
goto P_0c0b8dca;
P_0c0b8dc8: /* original e401, guest PC 0x0c0b8dc8 */
if(!s->budget--) { s->failed_pc=0x0c0b8dc8u; return 0; }
r[4]=0x00000001u;
goto P_0c0b8dca;
P_0c0b8dca: /* original 904d, guest PC 0x0c0b8dca */
if(!s->budget--) { s->failed_pc=0x0c0b8dcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e68u,2);
goto P_0c0b8dcc;
P_0c0b8dcc: /* original 05de, guest PC 0x0c0b8dcc */
if(!s->budget--) { s->failed_pc=0x0c0b8dccu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8dce;
P_0c0b8dce: /* original 4e0b, guest PC 0x0c0b8dce */
if(!s->budget--) { s->failed_pc=0x0c0b8dceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8dd2u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8dd2u) { target=s->pc; goto dispatch; }
goto P_0c0b8dd2;
P_0c0b8dd0: /* original e402, guest PC 0x0c0b8dd0 */
if(!s->budget--) { s->failed_pc=0x0c0b8dd0u; return 0; }
r[4]=0x00000002u;
goto P_0c0b8dd2;
P_0c0b8dd2: /* original 994a, guest PC 0x0c0b8dd2 */
if(!s->budget--) { s->failed_pc=0x0c0b8dd2u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e6au,2);
goto P_0c0b8dd4;
P_0c0b8dd4: /* original 39dc, guest PC 0x0c0b8dd4 */
if(!s->budget--) { s->failed_pc=0x0c0b8dd4u; return 0; }
r[9]+=r[13];
goto P_0c0b8dd6;
P_0c0b8dd6: /* original 6592, guest PC 0x0c0b8dd6 */
if(!s->budget--) { s->failed_pc=0x0c0b8dd6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8dd8;
P_0c0b8dd8: /* original 4e0b, guest PC 0x0c0b8dd8 */
if(!s->budget--) { s->failed_pc=0x0c0b8dd8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ddcu;
r[4]=0x00000079u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ddcu) { target=s->pc; goto dispatch; }
goto P_0c0b8ddc;
P_0c0b8dda: /* original e479, guest PC 0x0c0b8dda */
if(!s->budget--) { s->failed_pc=0x0c0b8ddau; return 0; }
r[4]=0x00000079u;
goto P_0c0b8ddc;
P_0c0b8ddc: /* original 6592, guest PC 0x0c0b8ddc */
if(!s->budget--) { s->failed_pc=0x0c0b8ddcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8dde;
P_0c0b8dde: /* original 4e0b, guest PC 0x0c0b8dde */
if(!s->budget--) { s->failed_pc=0x0c0b8ddeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8de2u;
r[4]=0x0000007au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8de2u) { target=s->pc; goto dispatch; }
goto P_0c0b8de2;
P_0c0b8de0: /* original e47a, guest PC 0x0c0b8de0 */
if(!s->budget--) { s->failed_pc=0x0c0b8de0u; return 0; }
r[4]=0x0000007au;
goto P_0c0b8de2;
P_0c0b8de2: /* original 6592, guest PC 0x0c0b8de2 */
if(!s->budget--) { s->failed_pc=0x0c0b8de2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8de4;
P_0c0b8de4: /* original 4e0b, guest PC 0x0c0b8de4 */
if(!s->budget--) { s->failed_pc=0x0c0b8de4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8de8u;
r[4]=0x0000007bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8de8u) { target=s->pc; goto dispatch; }
goto P_0c0b8de8;
P_0c0b8de6: /* original e47b, guest PC 0x0c0b8de6 */
if(!s->budget--) { s->failed_pc=0x0c0b8de6u; return 0; }
r[4]=0x0000007bu;
goto P_0c0b8de8;
P_0c0b8de8: /* original 6592, guest PC 0x0c0b8de8 */
if(!s->budget--) { s->failed_pc=0x0c0b8de8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8dea;
P_0c0b8dea: /* original 4e0b, guest PC 0x0c0b8dea */
if(!s->budget--) { s->failed_pc=0x0c0b8deau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8deeu;
r[4]=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8deeu) { target=s->pc; goto dispatch; }
goto P_0c0b8dee;
P_0c0b8dec: /* original e47c, guest PC 0x0c0b8dec */
if(!s->budget--) { s->failed_pc=0x0c0b8decu; return 0; }
r[4]=0x0000007cu;
goto P_0c0b8dee;
P_0c0b8dee: /* original 9c3d, guest PC 0x0c0b8dee */
if(!s->budget--) { s->failed_pc=0x0c0b8deeu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e6cu,2);
goto P_0c0b8df0;
P_0c0b8df0: /* original 943d, guest PC 0x0c0b8df0 */
if(!s->budget--) { s->failed_pc=0x0c0b8df0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e6eu,2);
goto P_0c0b8df2;
P_0c0b8df2: /* original 3cdc, guest PC 0x0c0b8df2 */
if(!s->budget--) { s->failed_pc=0x0c0b8df2u; return 0; }
r[12]+=r[13];
goto P_0c0b8df4;
P_0c0b8df4: /* original 4e0b, guest PC 0x0c0b8df4 */
if(!s->budget--) { s->failed_pc=0x0c0b8df4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8df8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8df8u) { target=s->pc; goto dispatch; }
goto P_0c0b8df8;
P_0c0b8df6: /* original 65c2, guest PC 0x0c0b8df6 */
if(!s->budget--) { s->failed_pc=0x0c0b8df6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8df8;
P_0c0b8df8: /* original 943a, guest PC 0x0c0b8df8 */
if(!s->budget--) { s->failed_pc=0x0c0b8df8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e70u,2);
goto P_0c0b8dfa;
P_0c0b8dfa: /* original 4e0b, guest PC 0x0c0b8dfa */
if(!s->budget--) { s->failed_pc=0x0c0b8dfau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8dfeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8dfeu) { target=s->pc; goto dispatch; }
goto P_0c0b8dfe;
P_0c0b8dfc: /* original 65c2, guest PC 0x0c0b8dfc */
if(!s->budget--) { s->failed_pc=0x0c0b8dfcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8dfe;
P_0c0b8dfe: /* original 9438, guest PC 0x0c0b8dfe */
if(!s->budget--) { s->failed_pc=0x0c0b8dfeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e72u,2);
goto P_0c0b8e00;
P_0c0b8e00: /* original 4e0b, guest PC 0x0c0b8e00 */
if(!s->budget--) { s->failed_pc=0x0c0b8e00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e04u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e04u) { target=s->pc; goto dispatch; }
goto P_0c0b8e04;
P_0c0b8e02: /* original 65c2, guest PC 0x0c0b8e02 */
if(!s->budget--) { s->failed_pc=0x0c0b8e02u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8e04;
P_0c0b8e04: /* original 9436, guest PC 0x0c0b8e04 */
if(!s->budget--) { s->failed_pc=0x0c0b8e04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e74u,2);
goto P_0c0b8e06;
P_0c0b8e06: /* original 4e0b, guest PC 0x0c0b8e06 */
if(!s->budget--) { s->failed_pc=0x0c0b8e06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e0au;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e0au) { target=s->pc; goto dispatch; }
goto P_0c0b8e0a;
P_0c0b8e08: /* original 65c2, guest PC 0x0c0b8e08 */
if(!s->budget--) { s->failed_pc=0x0c0b8e08u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8e0a;
P_0c0b8e0a: /* original 9b34, guest PC 0x0c0b8e0a */
if(!s->budget--) { s->failed_pc=0x0c0b8e0au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e76u,2);
goto P_0c0b8e0c;
P_0c0b8e0c: /* original 9427, guest PC 0x0c0b8e0c */
if(!s->budget--) { s->failed_pc=0x0c0b8e0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e5eu,2);
goto P_0c0b8e0e;
P_0c0b8e0e: /* original 3bdc, guest PC 0x0c0b8e0e */
if(!s->budget--) { s->failed_pc=0x0c0b8e0eu; return 0; }
r[11]+=r[13];
goto P_0c0b8e10;
P_0c0b8e10: /* original 4e0b, guest PC 0x0c0b8e10 */
if(!s->budget--) { s->failed_pc=0x0c0b8e10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e14u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e14u) { target=s->pc; goto dispatch; }
goto P_0c0b8e14;
P_0c0b8e12: /* original 65b2, guest PC 0x0c0b8e12 */
if(!s->budget--) { s->failed_pc=0x0c0b8e12u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8e14;
P_0c0b8e14: /* original 9430, guest PC 0x0c0b8e14 */
if(!s->budget--) { s->failed_pc=0x0c0b8e14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8e78u,2);
goto P_0c0b8e16;
P_0c0b8e16: /* original a033, guest PC 0x0c0b8e16 */
if(!s->budget--) { s->failed_pc=0x0c0b8e16u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8e80;
P_0c0b8e18: /* original 65b2, guest PC 0x0c0b8e18 */
if(!s->budget--) { s->failed_pc=0x0c0b8e18u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b8e1au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b8e1au; return 0; } return 1;
P_0c0b8e80: /* original 4e0b, guest PC 0x0c0b8e80 */
if(!s->budget--) { s->failed_pc=0x0c0b8e80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e84u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e84u) { target=s->pc; goto dispatch; }
goto P_0c0b8e84;
P_0c0b8e82: /* original 0009, guest PC 0x0c0b8e82 */
if(!s->budget--) { s->failed_pc=0x0c0b8e82u; return 0; }
goto P_0c0b8e84;
P_0c0b8e84: /* original 94b5, guest PC 0x0c0b8e84 */
if(!s->budget--) { s->failed_pc=0x0c0b8e84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ff2u,2);
goto P_0c0b8e86;
P_0c0b8e86: /* original 4e0b, guest PC 0x0c0b8e86 */
if(!s->budget--) { s->failed_pc=0x0c0b8e86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e8au;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e8au) { target=s->pc; goto dispatch; }
goto P_0c0b8e8a;
P_0c0b8e88: /* original 65b2, guest PC 0x0c0b8e88 */
if(!s->budget--) { s->failed_pc=0x0c0b8e88u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8e8a;
P_0c0b8e8a: /* original 94b3, guest PC 0x0c0b8e8a */
if(!s->budget--) { s->failed_pc=0x0c0b8e8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ff4u,2);
goto P_0c0b8e8c;
P_0c0b8e8c: /* original 4e0b, guest PC 0x0c0b8e8c */
if(!s->budget--) { s->failed_pc=0x0c0b8e8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e90u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e90u) { target=s->pc; goto dispatch; }
goto P_0c0b8e90;
P_0c0b8e8e: /* original 65b2, guest PC 0x0c0b8e8e */
if(!s->budget--) { s->failed_pc=0x0c0b8e8eu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8e90;
P_0c0b8e90: /* original 9ab1, guest PC 0x0c0b8e90 */
if(!s->budget--) { s->failed_pc=0x0c0b8e90u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ff6u,2);
goto P_0c0b8e92;
P_0c0b8e92: /* original 3adc, guest PC 0x0c0b8e92 */
if(!s->budget--) { s->failed_pc=0x0c0b8e92u; return 0; }
r[10]+=r[13];
goto P_0c0b8e94;
P_0c0b8e94: /* original 65a2, guest PC 0x0c0b8e94 */
if(!s->budget--) { s->failed_pc=0x0c0b8e94u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8e96;
P_0c0b8e96: /* original 4e0b, guest PC 0x0c0b8e96 */
if(!s->budget--) { s->failed_pc=0x0c0b8e96u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8e9au;
r[4]=0x0000000du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8e9au) { target=s->pc; goto dispatch; }
goto P_0c0b8e9a;
P_0c0b8e98: /* original e40d, guest PC 0x0c0b8e98 */
if(!s->budget--) { s->failed_pc=0x0c0b8e98u; return 0; }
r[4]=0x0000000du;
goto P_0c0b8e9a;
P_0c0b8e9a: /* original 65a2, guest PC 0x0c0b8e9a */
if(!s->budget--) { s->failed_pc=0x0c0b8e9au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8e9c;
P_0c0b8e9c: /* original 4e0b, guest PC 0x0c0b8e9c */
if(!s->budget--) { s->failed_pc=0x0c0b8e9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ea0u;
r[4]=0x0000000eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ea0u) { target=s->pc; goto dispatch; }
goto P_0c0b8ea0;
P_0c0b8e9e: /* original e40e, guest PC 0x0c0b8e9e */
if(!s->budget--) { s->failed_pc=0x0c0b8e9eu; return 0; }
r[4]=0x0000000eu;
goto P_0c0b8ea0;
P_0c0b8ea0: /* original 65a2, guest PC 0x0c0b8ea0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ea0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8ea2;
P_0c0b8ea2: /* original 4e0b, guest PC 0x0c0b8ea2 */
if(!s->budget--) { s->failed_pc=0x0c0b8ea2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ea6u;
r[4]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ea6u) { target=s->pc; goto dispatch; }
goto P_0c0b8ea6;
P_0c0b8ea4: /* original e40f, guest PC 0x0c0b8ea4 */
if(!s->budget--) { s->failed_pc=0x0c0b8ea4u; return 0; }
r[4]=0x0000000fu;
goto P_0c0b8ea6;
P_0c0b8ea6: /* original 65a2, guest PC 0x0c0b8ea6 */
if(!s->budget--) { s->failed_pc=0x0c0b8ea6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8ea8;
P_0c0b8ea8: /* original 4e0b, guest PC 0x0c0b8ea8 */
if(!s->budget--) { s->failed_pc=0x0c0b8ea8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8eacu;
r[4]=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8eacu) { target=s->pc; goto dispatch; }
goto P_0c0b8eac;
P_0c0b8eaa: /* original e410, guest PC 0x0c0b8eaa */
if(!s->budget--) { s->failed_pc=0x0c0b8eaau; return 0; }
r[4]=0x00000010u;
goto P_0c0b8eac;
P_0c0b8eac: /* original 94a3, guest PC 0x0c0b8eac */
if(!s->budget--) { s->failed_pc=0x0c0b8eacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ff6u,2);
goto P_0c0b8eae;
P_0c0b8eae: /* original 65f2, guest PC 0x0c0b8eae */
if(!s->budget--) { s->failed_pc=0x0c0b8eaeu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8eb0;
P_0c0b8eb0: /* original 4e0b, guest PC 0x0c0b8eb0 */
if(!s->budget--) { s->failed_pc=0x0c0b8eb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8eb4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8eb4u) { target=s->pc; goto dispatch; }
goto P_0c0b8eb4;
P_0c0b8eb2: /* original 6552, guest PC 0x0c0b8eb2 */
if(!s->budget--) { s->failed_pc=0x0c0b8eb2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8eb4;
P_0c0b8eb4: /* original 94a0, guest PC 0x0c0b8eb4 */
if(!s->budget--) { s->failed_pc=0x0c0b8eb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ff8u,2);
goto P_0c0b8eb6;
P_0c0b8eb6: /* original 55f1, guest PC 0x0c0b8eb6 */
if(!s->budget--) { s->failed_pc=0x0c0b8eb6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b8eb8;
P_0c0b8eb8: /* original 4e0b, guest PC 0x0c0b8eb8 */
if(!s->budget--) { s->failed_pc=0x0c0b8eb8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ebcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ebcu) { target=s->pc; goto dispatch; }
goto P_0c0b8ebc;
P_0c0b8eba: /* original 6552, guest PC 0x0c0b8eba */
if(!s->budget--) { s->failed_pc=0x0c0b8ebau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8ebc;
P_0c0b8ebc: /* original 6592, guest PC 0x0c0b8ebc */
if(!s->budget--) { s->failed_pc=0x0c0b8ebcu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8ebe;
P_0c0b8ebe: /* original 4e0b, guest PC 0x0c0b8ebe */
if(!s->budget--) { s->failed_pc=0x0c0b8ebeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ec2u;
r[4]=0x00000075u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ec2u) { target=s->pc; goto dispatch; }
goto P_0c0b8ec2;
P_0c0b8ec0: /* original e475, guest PC 0x0c0b8ec0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ec0u; return 0; }
r[4]=0x00000075u;
goto P_0c0b8ec2;
P_0c0b8ec2: /* original 6592, guest PC 0x0c0b8ec2 */
if(!s->budget--) { s->failed_pc=0x0c0b8ec2u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8ec4;
P_0c0b8ec4: /* original 4e0b, guest PC 0x0c0b8ec4 */
if(!s->budget--) { s->failed_pc=0x0c0b8ec4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ec8u;
r[4]=0x00000076u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ec8u) { target=s->pc; goto dispatch; }
goto P_0c0b8ec8;
P_0c0b8ec6: /* original e476, guest PC 0x0c0b8ec6 */
if(!s->budget--) { s->failed_pc=0x0c0b8ec6u; return 0; }
r[4]=0x00000076u;
goto P_0c0b8ec8;
P_0c0b8ec8: /* original 6592, guest PC 0x0c0b8ec8 */
if(!s->budget--) { s->failed_pc=0x0c0b8ec8u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8eca;
P_0c0b8eca: /* original 4e0b, guest PC 0x0c0b8eca */
if(!s->budget--) { s->failed_pc=0x0c0b8ecau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8eceu;
r[4]=0x00000077u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8eceu) { target=s->pc; goto dispatch; }
goto P_0c0b8ece;
P_0c0b8ecc: /* original e477, guest PC 0x0c0b8ecc */
if(!s->budget--) { s->failed_pc=0x0c0b8eccu; return 0; }
r[4]=0x00000077u;
goto P_0c0b8ece;
P_0c0b8ece: /* original 6592, guest PC 0x0c0b8ece */
if(!s->budget--) { s->failed_pc=0x0c0b8eceu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b8ed0;
P_0c0b8ed0: /* original 4e0b, guest PC 0x0c0b8ed0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ed0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ed4u;
r[4]=0x00000078u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ed4u) { target=s->pc; goto dispatch; }
goto P_0c0b8ed4;
P_0c0b8ed2: /* original e478, guest PC 0x0c0b8ed2 */
if(!s->budget--) { s->failed_pc=0x0c0b8ed2u; return 0; }
r[4]=0x00000078u;
goto P_0c0b8ed4;
P_0c0b8ed4: /* original 9491, guest PC 0x0c0b8ed4 */
if(!s->budget--) { s->failed_pc=0x0c0b8ed4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ffau,2);
goto P_0c0b8ed6;
P_0c0b8ed6: /* original 4e0b, guest PC 0x0c0b8ed6 */
if(!s->budget--) { s->failed_pc=0x0c0b8ed6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8edau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8edau) { target=s->pc; goto dispatch; }
goto P_0c0b8eda;
P_0c0b8ed8: /* original 65c2, guest PC 0x0c0b8ed8 */
if(!s->budget--) { s->failed_pc=0x0c0b8ed8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8eda;
P_0c0b8eda: /* original 948f, guest PC 0x0c0b8eda */
if(!s->budget--) { s->failed_pc=0x0c0b8edau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ffcu,2);
goto P_0c0b8edc;
P_0c0b8edc: /* original 4e0b, guest PC 0x0c0b8edc */
if(!s->budget--) { s->failed_pc=0x0c0b8edcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ee0u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ee0u) { target=s->pc; goto dispatch; }
goto P_0c0b8ee0;
P_0c0b8ede: /* original 65c2, guest PC 0x0c0b8ede */
if(!s->budget--) { s->failed_pc=0x0c0b8edeu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8ee0;
P_0c0b8ee0: /* original 948d, guest PC 0x0c0b8ee0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ee0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ffeu,2);
goto P_0c0b8ee2;
P_0c0b8ee2: /* original 4e0b, guest PC 0x0c0b8ee2 */
if(!s->budget--) { s->failed_pc=0x0c0b8ee2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ee6u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ee6u) { target=s->pc; goto dispatch; }
goto P_0c0b8ee6;
P_0c0b8ee4: /* original 65c2, guest PC 0x0c0b8ee4 */
if(!s->budget--) { s->failed_pc=0x0c0b8ee4u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8ee6;
P_0c0b8ee6: /* original 948b, guest PC 0x0c0b8ee6 */
if(!s->budget--) { s->failed_pc=0x0c0b8ee6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9000u,2);
goto P_0c0b8ee8;
P_0c0b8ee8: /* original 4e0b, guest PC 0x0c0b8ee8 */
if(!s->budget--) { s->failed_pc=0x0c0b8ee8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8eecu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8eecu) { target=s->pc; goto dispatch; }
goto P_0c0b8eec;
P_0c0b8eea: /* original 65c2, guest PC 0x0c0b8eea */
if(!s->budget--) { s->failed_pc=0x0c0b8eeau; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b8eec;
P_0c0b8eec: /* original 9489, guest PC 0x0c0b8eec */
if(!s->budget--) { s->failed_pc=0x0c0b8eecu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9002u,2);
goto P_0c0b8eee;
P_0c0b8eee: /* original 4e0b, guest PC 0x0c0b8eee */
if(!s->budget--) { s->failed_pc=0x0c0b8eeeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ef2u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ef2u) { target=s->pc; goto dispatch; }
goto P_0c0b8ef2;
P_0c0b8ef0: /* original 65b2, guest PC 0x0c0b8ef0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ef0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8ef2;
P_0c0b8ef2: /* original 9487, guest PC 0x0c0b8ef2 */
if(!s->budget--) { s->failed_pc=0x0c0b8ef2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9004u,2);
goto P_0c0b8ef4;
P_0c0b8ef4: /* original 4e0b, guest PC 0x0c0b8ef4 */
if(!s->budget--) { s->failed_pc=0x0c0b8ef4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8ef8u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8ef8u) { target=s->pc; goto dispatch; }
goto P_0c0b8ef8;
P_0c0b8ef6: /* original 65b2, guest PC 0x0c0b8ef6 */
if(!s->budget--) { s->failed_pc=0x0c0b8ef6u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8ef8;
P_0c0b8ef8: /* original 9485, guest PC 0x0c0b8ef8 */
if(!s->budget--) { s->failed_pc=0x0c0b8ef8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9006u,2);
goto P_0c0b8efa;
P_0c0b8efa: /* original 4e0b, guest PC 0x0c0b8efa */
if(!s->budget--) { s->failed_pc=0x0c0b8efau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8efeu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8efeu) { target=s->pc; goto dispatch; }
goto P_0c0b8efe;
P_0c0b8efc: /* original 65b2, guest PC 0x0c0b8efc */
if(!s->budget--) { s->failed_pc=0x0c0b8efcu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8efe;
P_0c0b8efe: /* original 9483, guest PC 0x0c0b8efe */
if(!s->budget--) { s->failed_pc=0x0c0b8efeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9008u,2);
goto P_0c0b8f00;
P_0c0b8f00: /* original 4e0b, guest PC 0x0c0b8f00 */
if(!s->budget--) { s->failed_pc=0x0c0b8f00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f04u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f04u) { target=s->pc; goto dispatch; }
goto P_0c0b8f04;
P_0c0b8f02: /* original 65b2, guest PC 0x0c0b8f02 */
if(!s->budget--) { s->failed_pc=0x0c0b8f02u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b8f04;
P_0c0b8f04: /* original 65a2, guest PC 0x0c0b8f04 */
if(!s->budget--) { s->failed_pc=0x0c0b8f04u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8f06;
P_0c0b8f06: /* original 4e0b, guest PC 0x0c0b8f06 */
if(!s->budget--) { s->failed_pc=0x0c0b8f06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f0au;
r[4]=0x00000009u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f0au) { target=s->pc; goto dispatch; }
goto P_0c0b8f0a;
P_0c0b8f08: /* original e409, guest PC 0x0c0b8f08 */
if(!s->budget--) { s->failed_pc=0x0c0b8f08u; return 0; }
r[4]=0x00000009u;
goto P_0c0b8f0a;
P_0c0b8f0a: /* original 65a2, guest PC 0x0c0b8f0a */
if(!s->budget--) { s->failed_pc=0x0c0b8f0au; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8f0c;
P_0c0b8f0c: /* original 4e0b, guest PC 0x0c0b8f0c */
if(!s->budget--) { s->failed_pc=0x0c0b8f0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f10u;
r[4]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f10u) { target=s->pc; goto dispatch; }
goto P_0c0b8f10;
P_0c0b8f0e: /* original e40a, guest PC 0x0c0b8f0e */
if(!s->budget--) { s->failed_pc=0x0c0b8f0eu; return 0; }
r[4]=0x0000000au;
goto P_0c0b8f10;
P_0c0b8f10: /* original 65a2, guest PC 0x0c0b8f10 */
if(!s->budget--) { s->failed_pc=0x0c0b8f10u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8f12;
P_0c0b8f12: /* original 4e0b, guest PC 0x0c0b8f12 */
if(!s->budget--) { s->failed_pc=0x0c0b8f12u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f16u;
r[4]=0x0000000bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f16u) { target=s->pc; goto dispatch; }
goto P_0c0b8f16;
P_0c0b8f14: /* original e40b, guest PC 0x0c0b8f14 */
if(!s->budget--) { s->failed_pc=0x0c0b8f14u; return 0; }
r[4]=0x0000000bu;
goto P_0c0b8f16;
P_0c0b8f16: /* original 65a2, guest PC 0x0c0b8f16 */
if(!s->budget--) { s->failed_pc=0x0c0b8f16u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b8f18;
P_0c0b8f18: /* original 4e0b, guest PC 0x0c0b8f18 */
if(!s->budget--) { s->failed_pc=0x0c0b8f18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f1cu;
r[4]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f1cu) { target=s->pc; goto dispatch; }
goto P_0c0b8f1c;
P_0c0b8f1a: /* original e40c, guest PC 0x0c0b8f1a */
if(!s->budget--) { s->failed_pc=0x0c0b8f1au; return 0; }
r[4]=0x0000000cu;
goto P_0c0b8f1c;
P_0c0b8f1c: /* original 9575, guest PC 0x0c0b8f1c */
if(!s->budget--) { s->failed_pc=0x0c0b8f1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b900au,2);
goto P_0c0b8f1e;
P_0c0b8f1e: /* original 35dc, guest PC 0x0c0b8f1e */
if(!s->budget--) { s->failed_pc=0x0c0b8f1eu; return 0; }
r[5]+=r[13];
goto P_0c0b8f20;
P_0c0b8f20: /* original 2f52, guest PC 0x0c0b8f20 */
if(!s->budget--) { s->failed_pc=0x0c0b8f20u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8f22;
P_0c0b8f22: /* original 9473, guest PC 0x0c0b8f22 */
if(!s->budget--) { s->failed_pc=0x0c0b8f22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b900cu,2);
goto P_0c0b8f24;
P_0c0b8f24: /* original 4e0b, guest PC 0x0c0b8f24 */
if(!s->budget--) { s->failed_pc=0x0c0b8f24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f28u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f28u) { target=s->pc; goto dispatch; }
goto P_0c0b8f28;
P_0c0b8f26: /* original 6552, guest PC 0x0c0b8f26 */
if(!s->budget--) { s->failed_pc=0x0c0b8f26u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f28;
P_0c0b8f28: /* original 9471, guest PC 0x0c0b8f28 */
if(!s->budget--) { s->failed_pc=0x0c0b8f28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b900eu,2);
goto P_0c0b8f2a;
P_0c0b8f2a: /* original 65f2, guest PC 0x0c0b8f2a */
if(!s->budget--) { s->failed_pc=0x0c0b8f2au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8f2c;
P_0c0b8f2c: /* original 4e0b, guest PC 0x0c0b8f2c */
if(!s->budget--) { s->failed_pc=0x0c0b8f2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f30u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f30u) { target=s->pc; goto dispatch; }
goto P_0c0b8f30;
P_0c0b8f2e: /* original 6552, guest PC 0x0c0b8f2e */
if(!s->budget--) { s->failed_pc=0x0c0b8f2eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f30;
P_0c0b8f30: /* original 956e, guest PC 0x0c0b8f30 */
if(!s->budget--) { s->failed_pc=0x0c0b8f30u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9010u,2);
goto P_0c0b8f32;
P_0c0b8f32: /* original 35dc, guest PC 0x0c0b8f32 */
if(!s->budget--) { s->failed_pc=0x0c0b8f32u; return 0; }
r[5]+=r[13];
goto P_0c0b8f34;
P_0c0b8f34: /* original 2f52, guest PC 0x0c0b8f34 */
if(!s->budget--) { s->failed_pc=0x0c0b8f34u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8f36;
P_0c0b8f36: /* original 946c, guest PC 0x0c0b8f36 */
if(!s->budget--) { s->failed_pc=0x0c0b8f36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9012u,2);
goto P_0c0b8f38;
P_0c0b8f38: /* original 4e0b, guest PC 0x0c0b8f38 */
if(!s->budget--) { s->failed_pc=0x0c0b8f38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f3cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f3cu) { target=s->pc; goto dispatch; }
goto P_0c0b8f3c;
P_0c0b8f3a: /* original 6552, guest PC 0x0c0b8f3a */
if(!s->budget--) { s->failed_pc=0x0c0b8f3au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f3c;
P_0c0b8f3c: /* original 946a, guest PC 0x0c0b8f3c */
if(!s->budget--) { s->failed_pc=0x0c0b8f3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9014u,2);
goto P_0c0b8f3e;
P_0c0b8f3e: /* original 65f2, guest PC 0x0c0b8f3e */
if(!s->budget--) { s->failed_pc=0x0c0b8f3eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8f40;
P_0c0b8f40: /* original 4e0b, guest PC 0x0c0b8f40 */
if(!s->budget--) { s->failed_pc=0x0c0b8f40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f44u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f44u) { target=s->pc; goto dispatch; }
goto P_0c0b8f44;
P_0c0b8f42: /* original 6552, guest PC 0x0c0b8f42 */
if(!s->budget--) { s->failed_pc=0x0c0b8f42u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f44;
P_0c0b8f44: /* original 9467, guest PC 0x0c0b8f44 */
if(!s->budget--) { s->failed_pc=0x0c0b8f44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9016u,2);
goto P_0c0b8f46;
P_0c0b8f46: /* original 9058, guest PC 0x0c0b8f46 */
if(!s->budget--) { s->failed_pc=0x0c0b8f46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b8ffau,2);
goto P_0c0b8f48;
P_0c0b8f48: /* original 4e0b, guest PC 0x0c0b8f48 */
if(!s->budget--) { s->failed_pc=0x0c0b8f48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f4cu) { target=s->pc; goto dispatch; }
goto P_0c0b8f4c;
P_0c0b8f4a: /* original 05de, guest PC 0x0c0b8f4a */
if(!s->budget--) { s->failed_pc=0x0c0b8f4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8f4c;
P_0c0b8f4c: /* original 9564, guest PC 0x0c0b8f4c */
if(!s->budget--) { s->failed_pc=0x0c0b8f4cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9018u,2);
goto P_0c0b8f4e;
P_0c0b8f4e: /* original 35dc, guest PC 0x0c0b8f4e */
if(!s->budget--) { s->failed_pc=0x0c0b8f4eu; return 0; }
r[5]+=r[13];
goto P_0c0b8f50;
P_0c0b8f50: /* original 2f52, guest PC 0x0c0b8f50 */
if(!s->budget--) { s->failed_pc=0x0c0b8f50u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8f52;
P_0c0b8f52: /* original 9462, guest PC 0x0c0b8f52 */
if(!s->budget--) { s->failed_pc=0x0c0b8f52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b901au,2);
goto P_0c0b8f54;
P_0c0b8f54: /* original 4e0b, guest PC 0x0c0b8f54 */
if(!s->budget--) { s->failed_pc=0x0c0b8f54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f58u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f58u) { target=s->pc; goto dispatch; }
goto P_0c0b8f58;
P_0c0b8f56: /* original 6552, guest PC 0x0c0b8f56 */
if(!s->budget--) { s->failed_pc=0x0c0b8f56u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f58;
P_0c0b8f58: /* original 9460, guest PC 0x0c0b8f58 */
if(!s->budget--) { s->failed_pc=0x0c0b8f58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b901cu,2);
goto P_0c0b8f5a;
P_0c0b8f5a: /* original 65f2, guest PC 0x0c0b8f5a */
if(!s->budget--) { s->failed_pc=0x0c0b8f5au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8f5c;
P_0c0b8f5c: /* original 4e0b, guest PC 0x0c0b8f5c */
if(!s->budget--) { s->failed_pc=0x0c0b8f5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f60u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f60u) { target=s->pc; goto dispatch; }
goto P_0c0b8f60;
P_0c0b8f5e: /* original 6552, guest PC 0x0c0b8f5e */
if(!s->budget--) { s->failed_pc=0x0c0b8f5eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f60;
P_0c0b8f60: /* original 945e, guest PC 0x0c0b8f60 */
if(!s->budget--) { s->failed_pc=0x0c0b8f60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9020u,2);
goto P_0c0b8f62;
P_0c0b8f62: /* original 905c, guest PC 0x0c0b8f62 */
if(!s->budget--) { s->failed_pc=0x0c0b8f62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b901eu,2);
goto P_0c0b8f64;
P_0c0b8f64: /* original 4e0b, guest PC 0x0c0b8f64 */
if(!s->budget--) { s->failed_pc=0x0c0b8f64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f68u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f68u) { target=s->pc; goto dispatch; }
goto P_0c0b8f68;
P_0c0b8f66: /* original 05de, guest PC 0x0c0b8f66 */
if(!s->budget--) { s->failed_pc=0x0c0b8f66u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8f68;
P_0c0b8f68: /* original 955b, guest PC 0x0c0b8f68 */
if(!s->budget--) { s->failed_pc=0x0c0b8f68u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9022u,2);
goto P_0c0b8f6a;
P_0c0b8f6a: /* original 35dc, guest PC 0x0c0b8f6a */
if(!s->budget--) { s->failed_pc=0x0c0b8f6au; return 0; }
r[5]+=r[13];
goto P_0c0b8f6c;
P_0c0b8f6c: /* original 2f52, guest PC 0x0c0b8f6c */
if(!s->budget--) { s->failed_pc=0x0c0b8f6cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8f6e;
P_0c0b8f6e: /* original 9459, guest PC 0x0c0b8f6e */
if(!s->budget--) { s->failed_pc=0x0c0b8f6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9024u,2);
goto P_0c0b8f70;
P_0c0b8f70: /* original 4e0b, guest PC 0x0c0b8f70 */
if(!s->budget--) { s->failed_pc=0x0c0b8f70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f74u) { target=s->pc; goto dispatch; }
goto P_0c0b8f74;
P_0c0b8f72: /* original 6552, guest PC 0x0c0b8f72 */
if(!s->budget--) { s->failed_pc=0x0c0b8f72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f74;
P_0c0b8f74: /* original 9457, guest PC 0x0c0b8f74 */
if(!s->budget--) { s->failed_pc=0x0c0b8f74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9026u,2);
goto P_0c0b8f76;
P_0c0b8f76: /* original 65f2, guest PC 0x0c0b8f76 */
if(!s->budget--) { s->failed_pc=0x0c0b8f76u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8f78;
P_0c0b8f78: /* original 4e0b, guest PC 0x0c0b8f78 */
if(!s->budget--) { s->failed_pc=0x0c0b8f78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f7cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f7cu) { target=s->pc; goto dispatch; }
goto P_0c0b8f7c;
P_0c0b8f7a: /* original 6552, guest PC 0x0c0b8f7a */
if(!s->budget--) { s->failed_pc=0x0c0b8f7au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f7c;
P_0c0b8f7c: /* original 9455, guest PC 0x0c0b8f7c */
if(!s->budget--) { s->failed_pc=0x0c0b8f7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b902au,2);
goto P_0c0b8f7e;
P_0c0b8f7e: /* original 9053, guest PC 0x0c0b8f7e */
if(!s->budget--) { s->failed_pc=0x0c0b8f7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9028u,2);
goto P_0c0b8f80;
P_0c0b8f80: /* original 4e0b, guest PC 0x0c0b8f80 */
if(!s->budget--) { s->failed_pc=0x0c0b8f80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f84u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f84u) { target=s->pc; goto dispatch; }
goto P_0c0b8f84;
P_0c0b8f82: /* original 05de, guest PC 0x0c0b8f82 */
if(!s->budget--) { s->failed_pc=0x0c0b8f82u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8f84;
P_0c0b8f84: /* original 9552, guest PC 0x0c0b8f84 */
if(!s->budget--) { s->failed_pc=0x0c0b8f84u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b902cu,2);
goto P_0c0b8f86;
P_0c0b8f86: /* original 35dc, guest PC 0x0c0b8f86 */
if(!s->budget--) { s->failed_pc=0x0c0b8f86u; return 0; }
r[5]+=r[13];
goto P_0c0b8f88;
P_0c0b8f88: /* original 2f52, guest PC 0x0c0b8f88 */
if(!s->budget--) { s->failed_pc=0x0c0b8f88u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8f8a;
P_0c0b8f8a: /* original 9450, guest PC 0x0c0b8f8a */
if(!s->budget--) { s->failed_pc=0x0c0b8f8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b902eu,2);
goto P_0c0b8f8c;
P_0c0b8f8c: /* original 4e0b, guest PC 0x0c0b8f8c */
if(!s->budget--) { s->failed_pc=0x0c0b8f8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f90u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f90u) { target=s->pc; goto dispatch; }
goto P_0c0b8f90;
P_0c0b8f8e: /* original 6552, guest PC 0x0c0b8f8e */
if(!s->budget--) { s->failed_pc=0x0c0b8f8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f90;
P_0c0b8f90: /* original 944e, guest PC 0x0c0b8f90 */
if(!s->budget--) { s->failed_pc=0x0c0b8f90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9030u,2);
goto P_0c0b8f92;
P_0c0b8f92: /* original 65f2, guest PC 0x0c0b8f92 */
if(!s->budget--) { s->failed_pc=0x0c0b8f92u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8f94;
P_0c0b8f94: /* original 4e0b, guest PC 0x0c0b8f94 */
if(!s->budget--) { s->failed_pc=0x0c0b8f94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8f98u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8f98u) { target=s->pc; goto dispatch; }
goto P_0c0b8f98;
P_0c0b8f96: /* original 6552, guest PC 0x0c0b8f96 */
if(!s->budget--) { s->failed_pc=0x0c0b8f96u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8f98;
P_0c0b8f98: /* original 954b, guest PC 0x0c0b8f98 */
if(!s->budget--) { s->failed_pc=0x0c0b8f98u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9032u,2);
goto P_0c0b8f9a;
P_0c0b8f9a: /* original 35dc, guest PC 0x0c0b8f9a */
if(!s->budget--) { s->failed_pc=0x0c0b8f9au; return 0; }
r[5]+=r[13];
goto P_0c0b8f9c;
P_0c0b8f9c: /* original 2f52, guest PC 0x0c0b8f9c */
if(!s->budget--) { s->failed_pc=0x0c0b8f9cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b8f9e;
P_0c0b8f9e: /* original 9449, guest PC 0x0c0b8f9e */
if(!s->budget--) { s->failed_pc=0x0c0b8f9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9034u,2);
goto P_0c0b8fa0;
P_0c0b8fa0: /* original 4e0b, guest PC 0x0c0b8fa0 */
if(!s->budget--) { s->failed_pc=0x0c0b8fa0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fa4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fa4u) { target=s->pc; goto dispatch; }
goto P_0c0b8fa4;
P_0c0b8fa2: /* original 6552, guest PC 0x0c0b8fa2 */
if(!s->budget--) { s->failed_pc=0x0c0b8fa2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8fa4;
P_0c0b8fa4: /* original 9447, guest PC 0x0c0b8fa4 */
if(!s->budget--) { s->failed_pc=0x0c0b8fa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9036u,2);
goto P_0c0b8fa6;
P_0c0b8fa6: /* original 65f2, guest PC 0x0c0b8fa6 */
if(!s->budget--) { s->failed_pc=0x0c0b8fa6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b8fa8;
P_0c0b8fa8: /* original 4e0b, guest PC 0x0c0b8fa8 */
if(!s->budget--) { s->failed_pc=0x0c0b8fa8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8facu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8facu) { target=s->pc; goto dispatch; }
goto P_0c0b8fac;
P_0c0b8faa: /* original 6552, guest PC 0x0c0b8faa */
if(!s->budget--) { s->failed_pc=0x0c0b8faau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b8fac;
P_0c0b8fac: /* original 9445, guest PC 0x0c0b8fac */
if(!s->budget--) { s->failed_pc=0x0c0b8facu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b903au,2);
goto P_0c0b8fae;
P_0c0b8fae: /* original 9043, guest PC 0x0c0b8fae */
if(!s->budget--) { s->failed_pc=0x0c0b8faeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9038u,2);
goto P_0c0b8fb0;
P_0c0b8fb0: /* original 4e0b, guest PC 0x0c0b8fb0 */
if(!s->budget--) { s->failed_pc=0x0c0b8fb0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fb4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fb4u) { target=s->pc; goto dispatch; }
goto P_0c0b8fb4;
P_0c0b8fb2: /* original 05de, guest PC 0x0c0b8fb2 */
if(!s->budget--) { s->failed_pc=0x0c0b8fb2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fb4;
P_0c0b8fb4: /* original 9443, guest PC 0x0c0b8fb4 */
if(!s->budget--) { s->failed_pc=0x0c0b8fb4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b903eu,2);
goto P_0c0b8fb6;
P_0c0b8fb6: /* original 9041, guest PC 0x0c0b8fb6 */
if(!s->budget--) { s->failed_pc=0x0c0b8fb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b903cu,2);
goto P_0c0b8fb8;
P_0c0b8fb8: /* original 4e0b, guest PC 0x0c0b8fb8 */
if(!s->budget--) { s->failed_pc=0x0c0b8fb8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fbcu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fbcu) { target=s->pc; goto dispatch; }
goto P_0c0b8fbc;
P_0c0b8fba: /* original 05de, guest PC 0x0c0b8fba */
if(!s->budget--) { s->failed_pc=0x0c0b8fbau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fbc;
P_0c0b8fbc: /* original 9040, guest PC 0x0c0b8fbc */
if(!s->budget--) { s->failed_pc=0x0c0b8fbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9040u,2);
goto P_0c0b8fbe;
P_0c0b8fbe: /* original 05de, guest PC 0x0c0b8fbe */
if(!s->budget--) { s->failed_pc=0x0c0b8fbeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fc0;
P_0c0b8fc0: /* original 4e0b, guest PC 0x0c0b8fc0 */
if(!s->budget--) { s->failed_pc=0x0c0b8fc0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fc4u;
r[4]=0x00000074u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fc4u) { target=s->pc; goto dispatch; }
goto P_0c0b8fc4;
P_0c0b8fc2: /* original e474, guest PC 0x0c0b8fc2 */
if(!s->budget--) { s->failed_pc=0x0c0b8fc2u; return 0; }
r[4]=0x00000074u;
goto P_0c0b8fc4;
P_0c0b8fc4: /* original 943e, guest PC 0x0c0b8fc4 */
if(!s->budget--) { s->failed_pc=0x0c0b8fc4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9044u,2);
goto P_0c0b8fc6;
P_0c0b8fc6: /* original 903c, guest PC 0x0c0b8fc6 */
if(!s->budget--) { s->failed_pc=0x0c0b8fc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9042u,2);
goto P_0c0b8fc8;
P_0c0b8fc8: /* original 4e0b, guest PC 0x0c0b8fc8 */
if(!s->budget--) { s->failed_pc=0x0c0b8fc8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fccu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fccu) { target=s->pc; goto dispatch; }
goto P_0c0b8fcc;
P_0c0b8fca: /* original 05de, guest PC 0x0c0b8fca */
if(!s->budget--) { s->failed_pc=0x0c0b8fcau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fcc;
P_0c0b8fcc: /* original 9431, guest PC 0x0c0b8fcc */
if(!s->budget--) { s->failed_pc=0x0c0b8fccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9032u,2);
goto P_0c0b8fce;
P_0c0b8fce: /* original 903a, guest PC 0x0c0b8fce */
if(!s->budget--) { s->failed_pc=0x0c0b8fceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9046u,2);
goto P_0c0b8fd0;
P_0c0b8fd0: /* original 4e0b, guest PC 0x0c0b8fd0 */
if(!s->budget--) { s->failed_pc=0x0c0b8fd0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fd4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fd4u) { target=s->pc; goto dispatch; }
goto P_0c0b8fd4;
P_0c0b8fd2: /* original 05de, guest PC 0x0c0b8fd2 */
if(!s->budget--) { s->failed_pc=0x0c0b8fd2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fd4;
P_0c0b8fd4: /* original 9038, guest PC 0x0c0b8fd4 */
if(!s->budget--) { s->failed_pc=0x0c0b8fd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9048u,2);
goto P_0c0b8fd6;
P_0c0b8fd6: /* original 05de, guest PC 0x0c0b8fd6 */
if(!s->budget--) { s->failed_pc=0x0c0b8fd6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fd8;
P_0c0b8fd8: /* original 4e0b, guest PC 0x0c0b8fd8 */
if(!s->budget--) { s->failed_pc=0x0c0b8fd8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fdcu;
r[4]=0x00000073u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fdcu) { target=s->pc; goto dispatch; }
goto P_0c0b8fdc;
P_0c0b8fda: /* original e473, guest PC 0x0c0b8fda */
if(!s->budget--) { s->failed_pc=0x0c0b8fdau; return 0; }
r[4]=0x00000073u;
goto P_0c0b8fdc;
P_0c0b8fdc: /* original 9436, guest PC 0x0c0b8fdc */
if(!s->budget--) { s->failed_pc=0x0c0b8fdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b904cu,2);
goto P_0c0b8fde;
P_0c0b8fde: /* original 9034, guest PC 0x0c0b8fde */
if(!s->budget--) { s->failed_pc=0x0c0b8fdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b904au,2);
goto P_0c0b8fe0;
P_0c0b8fe0: /* original 4e0b, guest PC 0x0c0b8fe0 */
if(!s->budget--) { s->failed_pc=0x0c0b8fe0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fe4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fe4u) { target=s->pc; goto dispatch; }
goto P_0c0b8fe4;
P_0c0b8fe2: /* original 05de, guest PC 0x0c0b8fe2 */
if(!s->budget--) { s->failed_pc=0x0c0b8fe2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fe4;
P_0c0b8fe4: /* original 9033, guest PC 0x0c0b8fe4 */
if(!s->budget--) { s->failed_pc=0x0c0b8fe4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b904eu,2);
goto P_0c0b8fe6;
P_0c0b8fe6: /* original 05de, guest PC 0x0c0b8fe6 */
if(!s->budget--) { s->failed_pc=0x0c0b8fe6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b8fe8;
P_0c0b8fe8: /* original 4e0b, guest PC 0x0c0b8fe8 */
if(!s->budget--) { s->failed_pc=0x0c0b8fe8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b8fecu;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b8fecu) { target=s->pc; goto dispatch; }
goto P_0c0b8fec;
P_0c0b8fea: /* original e406, guest PC 0x0c0b8fea */
if(!s->budget--) { s->failed_pc=0x0c0b8feau; return 0; }
r[4]=0x00000006u;
goto P_0c0b8fec;
P_0c0b8fec: /* original 9030, guest PC 0x0c0b8fec */
if(!s->budget--) { s->failed_pc=0x0c0b8fecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9050u,2);
goto P_0c0b8fee;
P_0c0b8fee: /* original a030, guest PC 0x0c0b8fee */
if(!s->budget--) { s->failed_pc=0x0c0b8feeu; return 0; }
goto P_0c0b9052;
P_0c0b8ff0: /* original 0009, guest PC 0x0c0b8ff0 */
if(!s->budget--) { s->failed_pc=0x0c0b8ff0u; return 0; }
if(!vf3_matrix_family(0x0c0b8ff2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b8ff2u; return 0; } return 1;
P_0c0b9052: /* original 05de, guest PC 0x0c0b9052 */
if(!s->budget--) { s->failed_pc=0x0c0b9052u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9054;
P_0c0b9054: /* original 4e0b, guest PC 0x0c0b9054 */
if(!s->budget--) { s->failed_pc=0x0c0b9054u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9058u;
r[4]=0x0000007du;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9058u) { target=s->pc; goto dispatch; }
goto P_0c0b9058;
P_0c0b9056: /* original e47d, guest PC 0x0c0b9056 */
if(!s->budget--) { s->failed_pc=0x0c0b9056u; return 0; }
r[4]=0x0000007du;
goto P_0c0b9058;
P_0c0b9058: /* original 9067, guest PC 0x0c0b9058 */
if(!s->budget--) { s->failed_pc=0x0c0b9058u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b912au,2);
goto P_0c0b905a;
P_0c0b905a: /* original 05de, guest PC 0x0c0b905a */
if(!s->budget--) { s->failed_pc=0x0c0b905au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b905c;
P_0c0b905c: /* original 4e0b, guest PC 0x0c0b905c */
if(!s->budget--) { s->failed_pc=0x0c0b905cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9060u;
r[4]=0x0000007fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9060u) { target=s->pc; goto dispatch; }
goto P_0c0b9060;
P_0c0b905e: /* original e47f, guest PC 0x0c0b905e */
if(!s->budget--) { s->failed_pc=0x0c0b905eu; return 0; }
r[4]=0x0000007fu;
goto P_0c0b9060;
P_0c0b9060: /* original 9064, guest PC 0x0c0b9060 */
if(!s->budget--) { s->failed_pc=0x0c0b9060u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b912cu,2);
goto P_0c0b9062;
P_0c0b9062: /* original 05de, guest PC 0x0c0b9062 */
if(!s->budget--) { s->failed_pc=0x0c0b9062u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9064;
P_0c0b9064: /* original 4e0b, guest PC 0x0c0b9064 */
if(!s->budget--) { s->failed_pc=0x0c0b9064u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9068u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9068u) { target=s->pc; goto dispatch; }
goto P_0c0b9068;
P_0c0b9066: /* original e408, guest PC 0x0c0b9066 */
if(!s->budget--) { s->failed_pc=0x0c0b9066u; return 0; }
r[4]=0x00000008u;
goto P_0c0b9068;
P_0c0b9068: /* original 9061, guest PC 0x0c0b9068 */
if(!s->budget--) { s->failed_pc=0x0c0b9068u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b912eu,2);
goto P_0c0b906a;
P_0c0b906a: /* original 05de, guest PC 0x0c0b906a */
if(!s->budget--) { s->failed_pc=0x0c0b906au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b906c;
P_0c0b906c: /* original 4e0b, guest PC 0x0c0b906c */
if(!s->budget--) { s->failed_pc=0x0c0b906cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9070u;
r[4]=0x0000007eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9070u) { target=s->pc; goto dispatch; }
goto P_0c0b9070;
P_0c0b906e: /* original e47e, guest PC 0x0c0b906e */
if(!s->budget--) { s->failed_pc=0x0c0b906eu; return 0; }
r[4]=0x0000007eu;
goto P_0c0b9070;
P_0c0b9070: /* original 905e, guest PC 0x0c0b9070 */
if(!s->budget--) { s->failed_pc=0x0c0b9070u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9130u,2);
goto P_0c0b9072;
P_0c0b9072: /* original 05de, guest PC 0x0c0b9072 */
if(!s->budget--) { s->failed_pc=0x0c0b9072u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9074;
P_0c0b9074: /* original 4e0b, guest PC 0x0c0b9074 */
if(!s->budget--) { s->failed_pc=0x0c0b9074u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9078u;
r[4]=0x00000007u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9078u) { target=s->pc; goto dispatch; }
goto P_0c0b9078;
P_0c0b9076: /* original e407, guest PC 0x0c0b9076 */
if(!s->budget--) { s->failed_pc=0x0c0b9076u; return 0; }
r[4]=0x00000007u;
goto P_0c0b9078;
P_0c0b9078: /* original 945c, guest PC 0x0c0b9078 */
if(!s->budget--) { s->failed_pc=0x0c0b9078u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9134u,2);
goto P_0c0b907a;
P_0c0b907a: /* original 905a, guest PC 0x0c0b907a */
if(!s->budget--) { s->failed_pc=0x0c0b907au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9132u,2);
goto P_0c0b907c;
P_0c0b907c: /* original 4e0b, guest PC 0x0c0b907c */
if(!s->budget--) { s->failed_pc=0x0c0b907cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9080u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9080u) { target=s->pc; goto dispatch; }
goto P_0c0b9080;
P_0c0b907e: /* original 05de, guest PC 0x0c0b907e */
if(!s->budget--) { s->failed_pc=0x0c0b907eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9080;
P_0c0b9080: /* original 945a, guest PC 0x0c0b9080 */
if(!s->budget--) { s->failed_pc=0x0c0b9080u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9138u,2);
goto P_0c0b9082;
P_0c0b9082: /* original 9058, guest PC 0x0c0b9082 */
if(!s->budget--) { s->failed_pc=0x0c0b9082u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9136u,2);
goto P_0c0b9084;
P_0c0b9084: /* original 4e0b, guest PC 0x0c0b9084 */
if(!s->budget--) { s->failed_pc=0x0c0b9084u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9088u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9088u) { target=s->pc; goto dispatch; }
goto P_0c0b9088;
P_0c0b9086: /* original 05de, guest PC 0x0c0b9086 */
if(!s->budget--) { s->failed_pc=0x0c0b9086u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9088;
P_0c0b9088: /* original 9458, guest PC 0x0c0b9088 */
if(!s->budget--) { s->failed_pc=0x0c0b9088u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b913cu,2);
goto P_0c0b908a;
P_0c0b908a: /* original 9056, guest PC 0x0c0b908a */
if(!s->budget--) { s->failed_pc=0x0c0b908au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b913au,2);
goto P_0c0b908c;
P_0c0b908c: /* original 4e0b, guest PC 0x0c0b908c */
if(!s->budget--) { s->failed_pc=0x0c0b908cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9090u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9090u) { target=s->pc; goto dispatch; }
goto P_0c0b9090;
P_0c0b908e: /* original 05de, guest PC 0x0c0b908e */
if(!s->budget--) { s->failed_pc=0x0c0b908eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9090;
P_0c0b9090: /* original 9456, guest PC 0x0c0b9090 */
if(!s->budget--) { s->failed_pc=0x0c0b9090u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9140u,2);
goto P_0c0b9092;
P_0c0b9092: /* original 9054, guest PC 0x0c0b9092 */
if(!s->budget--) { s->failed_pc=0x0c0b9092u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b913eu,2);
goto P_0c0b9094;
P_0c0b9094: /* original 4e0b, guest PC 0x0c0b9094 */
if(!s->budget--) { s->failed_pc=0x0c0b9094u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9098u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9098u) { target=s->pc; goto dispatch; }
goto P_0c0b9098;
P_0c0b9096: /* original 05de, guest PC 0x0c0b9096 */
if(!s->budget--) { s->failed_pc=0x0c0b9096u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9098;
P_0c0b9098: /* original 9454, guest PC 0x0c0b9098 */
if(!s->budget--) { s->failed_pc=0x0c0b9098u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9144u,2);
goto P_0c0b909a;
P_0c0b909a: /* original 9052, guest PC 0x0c0b909a */
if(!s->budget--) { s->failed_pc=0x0c0b909au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9142u,2);
goto P_0c0b909c;
P_0c0b909c: /* original 4e0b, guest PC 0x0c0b909c */
if(!s->budget--) { s->failed_pc=0x0c0b909cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90a0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90a0u) { target=s->pc; goto dispatch; }
goto P_0c0b90a0;
P_0c0b909e: /* original 05de, guest PC 0x0c0b909e */
if(!s->budget--) { s->failed_pc=0x0c0b909eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90a0;
P_0c0b90a0: /* original 9443, guest PC 0x0c0b90a0 */
if(!s->budget--) { s->failed_pc=0x0c0b90a0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b912au,2);
goto P_0c0b90a2;
P_0c0b90a2: /* original 9050, guest PC 0x0c0b90a2 */
if(!s->budget--) { s->failed_pc=0x0c0b90a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9146u,2);
goto P_0c0b90a4;
P_0c0b90a4: /* original 4e0b, guest PC 0x0c0b90a4 */
if(!s->budget--) { s->failed_pc=0x0c0b90a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90a8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90a8u) { target=s->pc; goto dispatch; }
goto P_0c0b90a8;
P_0c0b90a6: /* original 05de, guest PC 0x0c0b90a6 */
if(!s->budget--) { s->failed_pc=0x0c0b90a6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90a8;
P_0c0b90a8: /* original 944f, guest PC 0x0c0b90a8 */
if(!s->budget--) { s->failed_pc=0x0c0b90a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b914au,2);
goto P_0c0b90aa;
P_0c0b90aa: /* original 904d, guest PC 0x0c0b90aa */
if(!s->budget--) { s->failed_pc=0x0c0b90aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9148u,2);
goto P_0c0b90ac;
P_0c0b90ac: /* original 4e0b, guest PC 0x0c0b90ac */
if(!s->budget--) { s->failed_pc=0x0c0b90acu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90b0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90b0u) { target=s->pc; goto dispatch; }
goto P_0c0b90b0;
P_0c0b90ae: /* original 05de, guest PC 0x0c0b90ae */
if(!s->budget--) { s->failed_pc=0x0c0b90aeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90b0;
P_0c0b90b0: /* original 944d, guest PC 0x0c0b90b0 */
if(!s->budget--) { s->failed_pc=0x0c0b90b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b914eu,2);
goto P_0c0b90b2;
P_0c0b90b2: /* original 904b, guest PC 0x0c0b90b2 */
if(!s->budget--) { s->failed_pc=0x0c0b90b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b914cu,2);
goto P_0c0b90b4;
P_0c0b90b4: /* original 4e0b, guest PC 0x0c0b90b4 */
if(!s->budget--) { s->failed_pc=0x0c0b90b4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90b8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90b8u) { target=s->pc; goto dispatch; }
goto P_0c0b90b8;
P_0c0b90b6: /* original 05de, guest PC 0x0c0b90b6 */
if(!s->budget--) { s->failed_pc=0x0c0b90b6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90b8;
P_0c0b90b8: /* original 944b, guest PC 0x0c0b90b8 */
if(!s->budget--) { s->failed_pc=0x0c0b90b8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9152u,2);
goto P_0c0b90ba;
P_0c0b90ba: /* original 9049, guest PC 0x0c0b90ba */
if(!s->budget--) { s->failed_pc=0x0c0b90bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9150u,2);
goto P_0c0b90bc;
P_0c0b90bc: /* original 4e0b, guest PC 0x0c0b90bc */
if(!s->budget--) { s->failed_pc=0x0c0b90bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90c0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90c0u) { target=s->pc; goto dispatch; }
goto P_0c0b90c0;
P_0c0b90be: /* original 05de, guest PC 0x0c0b90be */
if(!s->budget--) { s->failed_pc=0x0c0b90beu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90c0;
P_0c0b90c0: /* original 9449, guest PC 0x0c0b90c0 */
if(!s->budget--) { s->failed_pc=0x0c0b90c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9156u,2);
goto P_0c0b90c2;
P_0c0b90c2: /* original 9047, guest PC 0x0c0b90c2 */
if(!s->budget--) { s->failed_pc=0x0c0b90c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9154u,2);
goto P_0c0b90c4;
P_0c0b90c4: /* original 4e0b, guest PC 0x0c0b90c4 */
if(!s->budget--) { s->failed_pc=0x0c0b90c4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90c8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90c8u) { target=s->pc; goto dispatch; }
goto P_0c0b90c8;
P_0c0b90c6: /* original 05de, guest PC 0x0c0b90c6 */
if(!s->budget--) { s->failed_pc=0x0c0b90c6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90c8;
P_0c0b90c8: /* original 9447, guest PC 0x0c0b90c8 */
if(!s->budget--) { s->failed_pc=0x0c0b90c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b915au,2);
goto P_0c0b90ca;
P_0c0b90ca: /* original 9045, guest PC 0x0c0b90ca */
if(!s->budget--) { s->failed_pc=0x0c0b90cau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9158u,2);
goto P_0c0b90cc;
P_0c0b90cc: /* original 4e0b, guest PC 0x0c0b90cc */
if(!s->budget--) { s->failed_pc=0x0c0b90ccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90d0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90d0u) { target=s->pc; goto dispatch; }
goto P_0c0b90d0;
P_0c0b90ce: /* original 05de, guest PC 0x0c0b90ce */
if(!s->budget--) { s->failed_pc=0x0c0b90ceu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90d0;
P_0c0b90d0: /* original 9445, guest PC 0x0c0b90d0 */
if(!s->budget--) { s->failed_pc=0x0c0b90d0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b915eu,2);
goto P_0c0b90d2;
P_0c0b90d2: /* original 9043, guest PC 0x0c0b90d2 */
if(!s->budget--) { s->failed_pc=0x0c0b90d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b915cu,2);
goto P_0c0b90d4;
P_0c0b90d4: /* original 4e0b, guest PC 0x0c0b90d4 */
if(!s->budget--) { s->failed_pc=0x0c0b90d4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90d8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90d8u) { target=s->pc; goto dispatch; }
goto P_0c0b90d8;
P_0c0b90d6: /* original 05de, guest PC 0x0c0b90d6 */
if(!s->budget--) { s->failed_pc=0x0c0b90d6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90d8;
P_0c0b90d8: /* original 9443, guest PC 0x0c0b90d8 */
if(!s->budget--) { s->failed_pc=0x0c0b90d8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9162u,2);
goto P_0c0b90da;
P_0c0b90da: /* original 9041, guest PC 0x0c0b90da */
if(!s->budget--) { s->failed_pc=0x0c0b90dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9160u,2);
goto P_0c0b90dc;
P_0c0b90dc: /* original 4e0b, guest PC 0x0c0b90dc */
if(!s->budget--) { s->failed_pc=0x0c0b90dcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90e0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90e0u) { target=s->pc; goto dispatch; }
goto P_0c0b90e0;
P_0c0b90de: /* original 05de, guest PC 0x0c0b90de */
if(!s->budget--) { s->failed_pc=0x0c0b90deu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90e0;
P_0c0b90e0: /* original 9441, guest PC 0x0c0b90e0 */
if(!s->budget--) { s->failed_pc=0x0c0b90e0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9166u,2);
goto P_0c0b90e2;
P_0c0b90e2: /* original 903f, guest PC 0x0c0b90e2 */
if(!s->budget--) { s->failed_pc=0x0c0b90e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9164u,2);
goto P_0c0b90e4;
P_0c0b90e4: /* original 4e0b, guest PC 0x0c0b90e4 */
if(!s->budget--) { s->failed_pc=0x0c0b90e4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90e8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90e8u) { target=s->pc; goto dispatch; }
goto P_0c0b90e8;
P_0c0b90e6: /* original 05de, guest PC 0x0c0b90e6 */
if(!s->budget--) { s->failed_pc=0x0c0b90e6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90e8;
P_0c0b90e8: /* original 943f, guest PC 0x0c0b90e8 */
if(!s->budget--) { s->failed_pc=0x0c0b90e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b916au,2);
goto P_0c0b90ea;
P_0c0b90ea: /* original 903d, guest PC 0x0c0b90ea */
if(!s->budget--) { s->failed_pc=0x0c0b90eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9168u,2);
goto P_0c0b90ec;
P_0c0b90ec: /* original 4e0b, guest PC 0x0c0b90ec */
if(!s->budget--) { s->failed_pc=0x0c0b90ecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90f0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90f0u) { target=s->pc; goto dispatch; }
goto P_0c0b90f0;
P_0c0b90ee: /* original 05de, guest PC 0x0c0b90ee */
if(!s->budget--) { s->failed_pc=0x0c0b90eeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90f0;
P_0c0b90f0: /* original 943d, guest PC 0x0c0b90f0 */
if(!s->budget--) { s->failed_pc=0x0c0b90f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b916eu,2);
goto P_0c0b90f2;
P_0c0b90f2: /* original 903b, guest PC 0x0c0b90f2 */
if(!s->budget--) { s->failed_pc=0x0c0b90f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b916cu,2);
goto P_0c0b90f4;
P_0c0b90f4: /* original 4e0b, guest PC 0x0c0b90f4 */
if(!s->budget--) { s->failed_pc=0x0c0b90f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b90f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b90f8u) { target=s->pc; goto dispatch; }
goto P_0c0b90f8;
P_0c0b90f6: /* original 05de, guest PC 0x0c0b90f6 */
if(!s->budget--) { s->failed_pc=0x0c0b90f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b90f8;
P_0c0b90f8: /* original 943b, guest PC 0x0c0b90f8 */
if(!s->budget--) { s->failed_pc=0x0c0b90f8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9172u,2);
goto P_0c0b90fa;
P_0c0b90fa: /* original 9039, guest PC 0x0c0b90fa */
if(!s->budget--) { s->failed_pc=0x0c0b90fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9170u,2);
goto P_0c0b90fc;
P_0c0b90fc: /* original 4e0b, guest PC 0x0c0b90fc */
if(!s->budget--) { s->failed_pc=0x0c0b90fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9100u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9100u) { target=s->pc; goto dispatch; }
goto P_0c0b9100;
P_0c0b90fe: /* original 05de, guest PC 0x0c0b90fe */
if(!s->budget--) { s->failed_pc=0x0c0b90feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9100;
P_0c0b9100: /* original 9439, guest PC 0x0c0b9100 */
if(!s->budget--) { s->failed_pc=0x0c0b9100u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9176u,2);
goto P_0c0b9102;
P_0c0b9102: /* original 9037, guest PC 0x0c0b9102 */
if(!s->budget--) { s->failed_pc=0x0c0b9102u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9174u,2);
goto P_0c0b9104;
P_0c0b9104: /* original 4e0b, guest PC 0x0c0b9104 */
if(!s->budget--) { s->failed_pc=0x0c0b9104u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9108u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9108u) { target=s->pc; goto dispatch; }
goto P_0c0b9108;
P_0c0b9106: /* original 05de, guest PC 0x0c0b9106 */
if(!s->budget--) { s->failed_pc=0x0c0b9106u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9108;
P_0c0b9108: /* original 9437, guest PC 0x0c0b9108 */
if(!s->budget--) { s->failed_pc=0x0c0b9108u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b917au,2);
goto P_0c0b910a;
P_0c0b910a: /* original 9035, guest PC 0x0c0b910a */
if(!s->budget--) { s->failed_pc=0x0c0b910au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b9178u,2);
goto P_0c0b910c;
P_0c0b910c: /* original 4e0b, guest PC 0x0c0b910c */
if(!s->budget--) { s->failed_pc=0x0c0b910cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9110u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9110u) { target=s->pc; goto dispatch; }
goto P_0c0b9110;
P_0c0b910e: /* original 05de, guest PC 0x0c0b910e */
if(!s->budget--) { s->failed_pc=0x0c0b910eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9110;
P_0c0b9110: /* original 9435, guest PC 0x0c0b9110 */
if(!s->budget--) { s->failed_pc=0x0c0b9110u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b917eu,2);
goto P_0c0b9112;
P_0c0b9112: /* original 9033, guest PC 0x0c0b9112 */
if(!s->budget--) { s->failed_pc=0x0c0b9112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b917cu,2);
goto P_0c0b9114;
P_0c0b9114: /* original 4e0b, guest PC 0x0c0b9114 */
if(!s->budget--) { s->failed_pc=0x0c0b9114u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b9118u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b9118u) { target=s->pc; goto dispatch; }
goto P_0c0b9118;
P_0c0b9116: /* original 05de, guest PC 0x0c0b9116 */
if(!s->budget--) { s->failed_pc=0x0c0b9116u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b9118;
P_0c0b9118: /* original 7f08, guest PC 0x0c0b9118 */
if(!s->budget--) { s->failed_pc=0x0c0b9118u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b911a;
P_0c0b911a: /* original 4f26, guest PC 0x0c0b911a */
if(!s->budget--) { s->failed_pc=0x0c0b911au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b911c;
P_0c0b911c: /* original 69f6, guest PC 0x0c0b911c */
if(!s->budget--) { s->failed_pc=0x0c0b911cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b911e;
P_0c0b911e: /* original 6af6, guest PC 0x0c0b911e */
if(!s->budget--) { s->failed_pc=0x0c0b911eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b9120;
P_0c0b9120: /* original 6bf6, guest PC 0x0c0b9120 */
if(!s->budget--) { s->failed_pc=0x0c0b9120u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b9122;
P_0c0b9122: /* original 6cf6, guest PC 0x0c0b9122 */
if(!s->budget--) { s->failed_pc=0x0c0b9122u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b9124;
P_0c0b9124: /* original 6df6, guest PC 0x0c0b9124 */
if(!s->budget--) { s->failed_pc=0x0c0b9124u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b9126;
P_0c0b9126: /* original 000b, guest PC 0x0c0b9126 */
if(!s->budget--) { s->failed_pc=0x0c0b9126u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b9128: /* original 6ef6, guest PC 0x0c0b9128 */
if(!s->budget--) { s->failed_pc=0x0c0b9128u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b912au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b912au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
