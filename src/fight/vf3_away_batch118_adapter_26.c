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
int vf3_away_batch118_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
case 0x0c0c5dbau: goto P_0c0c5dba;
case 0x0c0c5dbcu: goto P_0c0c5dbc;
case 0x0c0c5dbeu: goto P_0c0c5dbe;
case 0x0c0c5dc0u: goto P_0c0c5dc0;
case 0x0c0c5dc2u: goto P_0c0c5dc2;
case 0x0c0c5dc4u: goto P_0c0c5dc4;
case 0x0c0c5dc6u: goto P_0c0c5dc6;
case 0x0c0c5dc8u: goto P_0c0c5dc8;
case 0x0c0c5dcau: goto P_0c0c5dca;
case 0x0c0c5dccu: goto P_0c0c5dcc;
case 0x0c0c5dceu: goto P_0c0c5dce;
case 0x0c0c5dd0u: goto P_0c0c5dd0;
case 0x0c0c5dd2u: goto P_0c0c5dd2;
case 0x0c0c5dd4u: goto P_0c0c5dd4;
case 0x0c0c5dd6u: goto P_0c0c5dd6;
case 0x0c0c5dd8u: goto P_0c0c5dd8;
case 0x0c0c5ddau: goto P_0c0c5dda;
case 0x0c0c5ddcu: goto P_0c0c5ddc;
case 0x0c0c5ddeu: goto P_0c0c5dde;
case 0x0c0c5de0u: goto P_0c0c5de0;
case 0x0c0c5de2u: goto P_0c0c5de2;
case 0x0c0c5de4u: goto P_0c0c5de4;
case 0x0c0c5de6u: goto P_0c0c5de6;
case 0x0c0c5de8u: goto P_0c0c5de8;
case 0x0c0c5deau: goto P_0c0c5dea;
case 0x0c0c5decu: goto P_0c0c5dec;
case 0x0c0c5deeu: goto P_0c0c5dee;
case 0x0c0c5df0u: goto P_0c0c5df0;
case 0x0c0c5df2u: goto P_0c0c5df2;
case 0x0c0c5df4u: goto P_0c0c5df4;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c7de8u: goto P_0c0c7de8;
case 0x0c0c7deau: goto P_0c0c7dea;
case 0x0c0c7decu: goto P_0c0c7dec;
case 0x0c0c7deeu: goto P_0c0c7dee;
case 0x0c0c7df0u: goto P_0c0c7df0;
case 0x0c0c7df2u: goto P_0c0c7df2;
case 0x0c0c7df4u: goto P_0c0c7df4;
case 0x0c0c7df6u: goto P_0c0c7df6;
case 0x0c0c7df8u: goto P_0c0c7df8;
case 0x0c0c7dfau: goto P_0c0c7dfa;
case 0x0c0c7dfcu: goto P_0c0c7dfc;
case 0x0c0c7dfeu: goto P_0c0c7dfe;
case 0x0c0c7e00u: goto P_0c0c7e00;
case 0x0c0c7e02u: goto P_0c0c7e02;
case 0x0c0c7e04u: goto P_0c0c7e04;
case 0x0c0c7e06u: goto P_0c0c7e06;
case 0x0c0c7e08u: goto P_0c0c7e08;
case 0x0c0c7e0au: goto P_0c0c7e0a;
case 0x0c0c7e0cu: goto P_0c0c7e0c;
case 0x0c0c7e0eu: goto P_0c0c7e0e;
case 0x0c0c7e10u: goto P_0c0c7e10;
case 0x0c0c7e12u: goto P_0c0c7e12;
case 0x0c0c7e14u: goto P_0c0c7e14;
case 0x0c0c7e16u: goto P_0c0c7e16;
case 0x0c0c7e18u: goto P_0c0c7e18;
case 0x0c0c7e1au: goto P_0c0c7e1a;
case 0x0c0c7e1cu: goto P_0c0c7e1c;
case 0x0c0c7e1eu: goto P_0c0c7e1e;
case 0x0c0c7e20u: goto P_0c0c7e20;
case 0x0c0c7e22u: goto P_0c0c7e22;
case 0x0c0c7e24u: goto P_0c0c7e24;
case 0x0c0c7e26u: goto P_0c0c7e26;
case 0x0c0c7e28u: goto P_0c0c7e28;
case 0x0c0c7e2au: goto P_0c0c7e2a;
case 0x0c0c7e2cu: goto P_0c0c7e2c;
case 0x0c0c7e2eu: goto P_0c0c7e2e;
case 0x0c0c7e30u: goto P_0c0c7e30;
case 0x0c0c7e32u: goto P_0c0c7e32;
case 0x0c0c7e34u: goto P_0c0c7e34;
case 0x0c0c7e36u: goto P_0c0c7e36;
case 0x0c0c7e38u: goto P_0c0c7e38;
case 0x0c0c7e3au: goto P_0c0c7e3a;
case 0x0c0c7e3cu: goto P_0c0c7e3c;
case 0x0c0c7e3eu: goto P_0c0c7e3e;
case 0x0c0c7e40u: goto P_0c0c7e40;
case 0x0c0c7e42u: goto P_0c0c7e42;
case 0x0c0c7e44u: goto P_0c0c7e44;
case 0x0c0c7e46u: goto P_0c0c7e46;
case 0x0c0c7e48u: goto P_0c0c7e48;
case 0x0c0c7e4au: goto P_0c0c7e4a;
case 0x0c0c7e4cu: goto P_0c0c7e4c;
case 0x0c0c7e4eu: goto P_0c0c7e4e;
case 0x0c0c7e50u: goto P_0c0c7e50;
case 0x0c0c7e52u: goto P_0c0c7e52;
case 0x0c0c7e54u: goto P_0c0c7e54;
case 0x0c0c7e56u: goto P_0c0c7e56;
case 0x0c0c7e58u: goto P_0c0c7e58;
case 0x0c0c7e5au: goto P_0c0c7e5a;
case 0x0c0c7e5cu: goto P_0c0c7e5c;
case 0x0c0c7e5eu: goto P_0c0c7e5e;
case 0x0c0c7e60u: goto P_0c0c7e60;
case 0x0c0c7e62u: goto P_0c0c7e62;
case 0x0c0c7e64u: goto P_0c0c7e64;
case 0x0c0c7e66u: goto P_0c0c7e66;
case 0x0c0c7e68u: goto P_0c0c7e68;
case 0x0c0c7e6au: goto P_0c0c7e6a;
case 0x0c0c7e6cu: goto P_0c0c7e6c;
case 0x0c0c7e6eu: goto P_0c0c7e6e;
case 0x0c0c7e70u: goto P_0c0c7e70;
case 0x0c0c7e72u: goto P_0c0c7e72;
case 0x0c0c7e74u: goto P_0c0c7e74;
case 0x0c0c7e76u: goto P_0c0c7e76;
case 0x0c0c7e78u: goto P_0c0c7e78;
case 0x0c0c7e7au: goto P_0c0c7e7a;
case 0x0c0c7e7cu: goto P_0c0c7e7c;
case 0x0c0c7e7eu: goto P_0c0c7e7e;
case 0x0c0c7e80u: goto P_0c0c7e80;
case 0x0c0c7e82u: goto P_0c0c7e82;
case 0x0c0c7e84u: goto P_0c0c7e84;
case 0x0c0c7e86u: goto P_0c0c7e86;
case 0x0c0c7e88u: goto P_0c0c7e88;
case 0x0c0c7e8au: goto P_0c0c7e8a;
case 0x0c0c7e8cu: goto P_0c0c7e8c;
case 0x0c0c7e8eu: goto P_0c0c7e8e;
case 0x0c0c7e90u: goto P_0c0c7e90;
case 0x0c0c7e92u: goto P_0c0c7e92;
case 0x0c0c7e94u: goto P_0c0c7e94;
case 0x0c0c7e96u: goto P_0c0c7e96;
case 0x0c0c7e98u: goto P_0c0c7e98;
case 0x0c0c7e9au: goto P_0c0c7e9a;
case 0x0c0c7e9cu: goto P_0c0c7e9c;
case 0x0c0c7e9eu: goto P_0c0c7e9e;
case 0x0c0c7ea0u: goto P_0c0c7ea0;
case 0x0c0c7ea2u: goto P_0c0c7ea2;
case 0x0c0c7ea4u: goto P_0c0c7ea4;
case 0x0c0c7ea6u: goto P_0c0c7ea6;
case 0x0c0c7ea8u: goto P_0c0c7ea8;
case 0x0c0c7eaau: goto P_0c0c7eaa;
case 0x0c0c7eacu: goto P_0c0c7eac;
case 0x0c0c7eaeu: goto P_0c0c7eae;
case 0x0c0c7eb0u: goto P_0c0c7eb0;
case 0x0c0c7eb2u: goto P_0c0c7eb2;
case 0x0c0c7eb4u: goto P_0c0c7eb4;
case 0x0c0c7eb6u: goto P_0c0c7eb6;
case 0x0c0c7eb8u: goto P_0c0c7eb8;
case 0x0c0c7ebau: goto P_0c0c7eba;
case 0x0c0c7ebcu: goto P_0c0c7ebc;
case 0x0c0c7ebeu: goto P_0c0c7ebe;
case 0x0c0c7ec0u: goto P_0c0c7ec0;
case 0x0c0c7ec2u: goto P_0c0c7ec2;
case 0x0c0c7ec4u: goto P_0c0c7ec4;
case 0x0c0c7ec6u: goto P_0c0c7ec6;
case 0x0c0c7ec8u: goto P_0c0c7ec8;
case 0x0c0c7ecau: goto P_0c0c7eca;
case 0x0c0c7eccu: goto P_0c0c7ecc;
case 0x0c0c7eceu: goto P_0c0c7ece;
case 0x0c0c7ed0u: goto P_0c0c7ed0;
case 0x0c0c7ed2u: goto P_0c0c7ed2;
case 0x0c0c7ed4u: goto P_0c0c7ed4;
case 0x0c0c7ed6u: goto P_0c0c7ed6;
case 0x0c0c7ed8u: goto P_0c0c7ed8;
case 0x0c0c7edau: goto P_0c0c7eda;
case 0x0c0c7edcu: goto P_0c0c7edc;
case 0x0c0c7edeu: goto P_0c0c7ede;
case 0x0c0c7ee0u: goto P_0c0c7ee0;
case 0x0c0c7ee2u: goto P_0c0c7ee2;
case 0x0c0c7ee4u: goto P_0c0c7ee4;
case 0x0c0c7ee6u: goto P_0c0c7ee6;
case 0x0c0c7ee8u: goto P_0c0c7ee8;
case 0x0c0c7eeau: goto P_0c0c7eea;
case 0x0c0c7eecu: goto P_0c0c7eec;
case 0x0c0c7eeeu: goto P_0c0c7eee;
case 0x0c0c7ef0u: goto P_0c0c7ef0;
case 0x0c0c7ef2u: goto P_0c0c7ef2;
case 0x0c0c7ef4u: goto P_0c0c7ef4;
case 0x0c0c7ef6u: goto P_0c0c7ef6;
case 0x0c0c7ef8u: goto P_0c0c7ef8;
case 0x0c0c7efau: goto P_0c0c7efa;
case 0x0c0c7efcu: goto P_0c0c7efc;
case 0x0c0c7efeu: goto P_0c0c7efe;
case 0x0c0c7f00u: goto P_0c0c7f00;
case 0x0c0c7f02u: goto P_0c0c7f02;
case 0x0c0c7f44u: goto P_0c0c7f44;
case 0x0c0c7f46u: goto P_0c0c7f46;
case 0x0c0c7f48u: goto P_0c0c7f48;
case 0x0c0c7f4au: goto P_0c0c7f4a;
case 0x0c0c7f4cu: goto P_0c0c7f4c;
case 0x0c0c7f4eu: goto P_0c0c7f4e;
case 0x0c0c7f50u: goto P_0c0c7f50;
case 0x0c0c7f52u: goto P_0c0c7f52;
case 0x0c0c7f54u: goto P_0c0c7f54;
case 0x0c0c7f56u: goto P_0c0c7f56;
case 0x0c0c7f58u: goto P_0c0c7f58;
case 0x0c0c7f5au: goto P_0c0c7f5a;
case 0x0c0c7f5cu: goto P_0c0c7f5c;
case 0x0c0c7f5eu: goto P_0c0c7f5e;
case 0x0c0c7f60u: goto P_0c0c7f60;
case 0x0c0c7f62u: goto P_0c0c7f62;
case 0x0c0c7f64u: goto P_0c0c7f64;
case 0x0c0c7f66u: goto P_0c0c7f66;
case 0x0c0c7f68u: goto P_0c0c7f68;
case 0x0c0c7f6au: goto P_0c0c7f6a;
case 0x0c0c7f6cu: goto P_0c0c7f6c;
case 0x0c0c7f6eu: goto P_0c0c7f6e;
case 0x0c0c7f70u: goto P_0c0c7f70;
case 0x0c0c7f72u: goto P_0c0c7f72;
case 0x0c0c7f74u: goto P_0c0c7f74;
case 0x0c0c7f76u: goto P_0c0c7f76;
case 0x0c0c7f78u: goto P_0c0c7f78;
case 0x0c0c7f7au: goto P_0c0c7f7a;
case 0x0c0c7f7cu: goto P_0c0c7f7c;
case 0x0c0c7f7eu: goto P_0c0c7f7e;
case 0x0c0c7f80u: goto P_0c0c7f80;
case 0x0c0c7f82u: goto P_0c0c7f82;
case 0x0c0c7f84u: goto P_0c0c7f84;
case 0x0c0c7f86u: goto P_0c0c7f86;
case 0x0c0c7f88u: goto P_0c0c7f88;
case 0x0c0c7f8au: goto P_0c0c7f8a;
case 0x0c0c7f8cu: goto P_0c0c7f8c;
case 0x0c0c7f8eu: goto P_0c0c7f8e;
case 0x0c0c7f90u: goto P_0c0c7f90;
case 0x0c0c7f92u: goto P_0c0c7f92;
case 0x0c0c7f94u: goto P_0c0c7f94;
case 0x0c0c7f96u: goto P_0c0c7f96;
case 0x0c0c7f98u: goto P_0c0c7f98;
case 0x0c0c7f9au: goto P_0c0c7f9a;
case 0x0c0c7f9cu: goto P_0c0c7f9c;
case 0x0c0c7f9eu: goto P_0c0c7f9e;
case 0x0c0c7fa0u: goto P_0c0c7fa0;
case 0x0c0c7fa2u: goto P_0c0c7fa2;
case 0x0c0c7fa4u: goto P_0c0c7fa4;
case 0x0c0c7fa6u: goto P_0c0c7fa6;
case 0x0c0c7fa8u: goto P_0c0c7fa8;
case 0x0c0c7faau: goto P_0c0c7faa;
case 0x0c0c7facu: goto P_0c0c7fac;
case 0x0c0c7faeu: goto P_0c0c7fae;
case 0x0c0c7fb0u: goto P_0c0c7fb0;
case 0x0c0c7fb2u: goto P_0c0c7fb2;
case 0x0c0c7fb4u: goto P_0c0c7fb4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c5cb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5cb2u; return 0; } return 1;
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c5d86;
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5dba;
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
goto P_0c0c5dba;
P_0c0c5dba: /* original 2fe6, guest PC 0x0c0c5dba */
if(!s->budget--) { s->failed_pc=0x0c0c5dbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5dbc;
P_0c0c5dbc: /* original 4411, guest PC 0x0c0c5dbc */
if(!s->budget--) { s->failed_pc=0x0c0c5dbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c5dbe;
P_0c0c5dbe: /* original 4f22, guest PC 0x0c0c5dbe */
if(!s->budget--) { s->failed_pc=0x0c0c5dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5dc0;
P_0c0c5dc0: /* original d517, guest PC 0x0c0c5dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc0u; return 0; }
r[5]=read(ram,0x0c0c5e20u,4);
goto P_0c0c5dc2;
P_0c0c5dc2: /* original 8b15, guest PC 0x0c0c5dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dc4;
P_0c0c5dc4: /* original 921c, guest PC 0x0c0c5dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5e00u,2);
goto P_0c0c5dc6;
P_0c0c5dc6: /* original 3423, guest PC 0x0c0c5dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c5dc8;
P_0c0c5dc8: /* original 8912, guest PC 0x0c0c5dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5dca;
P_0c0c5dca: /* original d016, guest PC 0x0c0c5dca */
if(!s->budget--) { s->failed_pc=0x0c0c5dcau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dcc;
P_0c0c5dcc: /* original 4408, guest PC 0x0c0c5dcc */
if(!s->budget--) { s->failed_pc=0x0c0c5dccu; return 0; }
r[4]<<=2;
goto P_0c0c5dce;
P_0c0c5dce: /* original 6e43, guest PC 0x0c0c5dce */
if(!s->budget--) { s->failed_pc=0x0c0c5dceu; return 0; }
r[14]=r[4];
goto P_0c0c5dd0;
P_0c0c5dd0: /* original 03ee, guest PC 0x0c0c5dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c5dd2;
P_0c0c5dd2: /* original 4311, guest PC 0x0c0c5dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c5dd4;
P_0c0c5dd4: /* original 8b0c, guest PC 0x0c0c5dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dd6;
P_0c0c5dd6: /* original d414, guest PC 0x0c0c5dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd6u; return 0; }
r[4]=read(ram,0x0c0c5e28u,4);
goto P_0c0c5dd8;
P_0c0c5dd8: /* original 60e3, guest PC 0x0c0c5dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd8u; return 0; }
r[0]=r[14];
goto P_0c0c5dda;
P_0c0c5dda: /* original 6252, guest PC 0x0c0c5dda */
if(!s->budget--) { s->failed_pc=0x0c0c5ddau; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0c5ddc;
P_0c0c5ddc: /* original 034e, guest PC 0x0c0c5ddc */
if(!s->budget--) { s->failed_pc=0x0c0c5ddcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c5dde;
P_0c0c5dde: /* original 3320, guest PC 0x0c0c5dde */
if(!s->budget--) { s->failed_pc=0x0c0c5ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c5de0;
P_0c0c5de0: /* original 8906, guest PC 0x0c0c5de0 */
if(!s->budget--) { s->failed_pc=0x0c0c5de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5de2;
P_0c0c5de2: /* original 6352, guest PC 0x0c0c5de2 */
if(!s->budget--) { s->failed_pc=0x0c0c5de2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c5de4;
P_0c0c5de4: /* original 60e3, guest PC 0x0c0c5de4 */
if(!s->budget--) { s->failed_pc=0x0c0c5de4u; return 0; }
r[0]=r[14];
goto P_0c0c5de6;
P_0c0c5de6: /* original 0436, guest PC 0x0c0c5de6 */
if(!s->budget--) { s->failed_pc=0x0c0c5de6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0c5de8;
P_0c0c5de8: /* original d310, guest PC 0x0c0c5de8 */
if(!s->budget--) { s->failed_pc=0x0c0c5de8u; return 0; }
r[3]=read(ram,0x0c0c5e2cu,4);
goto P_0c0c5dea;
P_0c0c5dea: /* original d00e, guest PC 0x0c0c5dea */
if(!s->budget--) { s->failed_pc=0x0c0c5deau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dec;
P_0c0c5dec: /* original 430b, guest PC 0x0c0c5dec */
if(!s->budget--) { s->failed_pc=0x0c0c5decu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5df0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5df0u) { target=s->pc; goto dispatch; }
goto P_0c0c5df0;
P_0c0c5dee: /* original 04ee, guest PC 0x0c0c5dee */
if(!s->budget--) { s->failed_pc=0x0c0c5deeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c5df0;
P_0c0c5df0: /* original 4f26, guest PC 0x0c0c5df0 */
if(!s->budget--) { s->failed_pc=0x0c0c5df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5df2;
P_0c0c5df2: /* original 000b, guest PC 0x0c0c5df2 */
if(!s->budget--) { s->failed_pc=0x0c0c5df2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5df4: /* original 6ef6, guest PC 0x0c0c5df4 */
if(!s->budget--) { s->failed_pc=0x0c0c5df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5df6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5df6u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c7de8: /* original d54a, guest PC 0x0c0c7de8 */
if(!s->budget--) { s->failed_pc=0x0c0c7de8u; return 0; }
r[5]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7dea;
P_0c0c7dea: /* original e01c, guest PC 0x0c0c7dea */
if(!s->budget--) { s->failed_pc=0x0c0c7deau; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7dec;
P_0c0c7dec: /* original e30f, guest PC 0x0c0c7dec */
if(!s->budget--) { s->failed_pc=0x0c0c7decu; return 0; }
r[3]=0x0000000fu;
goto P_0c0c7dee;
P_0c0c7dee: /* original 9189, guest PC 0x0c0c7dee */
if(!s->budget--) { s->failed_pc=0x0c0c7deeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f04u,2);
goto P_0c0c7df0;
P_0c0c7df0: /* original 045c, guest PC 0x0c0c7df0 */
if(!s->budget--) { s->failed_pc=0x0c0c7df0u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c7df2;
P_0c0c7df2: /* original d049, guest PC 0x0c0c7df2 */
if(!s->budget--) { s->failed_pc=0x0c0c7df2u; return 0; }
r[0]=read(ram,0x0c0c7f18u,4);
goto P_0c0c7df4;
P_0c0c7df4: /* original 315c, guest PC 0x0c0c7df4 */
if(!s->budget--) { s->failed_pc=0x0c0c7df4u; return 0; }
r[1]+=r[5];
goto P_0c0c7df6;
P_0c0c7df6: /* original 644c, guest PC 0x0c0c7df6 */
if(!s->budget--) { s->failed_pc=0x0c0c7df6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7df8;
P_0c0c7df8: /* original 2439, guest PC 0x0c0c7df8 */
if(!s->budget--) { s->failed_pc=0x0c0c7df8u; return 0; }
r[4]&=r[3];
goto P_0c0c7dfa;
P_0c0c7dfa: /* original 024c, guest PC 0x0c0c7dfa */
if(!s->budget--) { s->failed_pc=0x0c0c7dfau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7dfc;
P_0c0c7dfc: /* original 000b, guest PC 0x0c0c7dfc */
if(!s->budget--) { s->failed_pc=0x0c0c7dfcu; return 0; }
target=r[16];
write(ram,r[1],r[2],1);
s->pc=target; return ram->oob==0;
P_0c0c7dfe: /* original 2120, guest PC 0x0c0c7dfe */
if(!s->budget--) { s->failed_pc=0x0c0c7dfeu; return 0; }
write(ram,r[1],r[2],1);
goto P_0c0c7e00;
P_0c0c7e00: /* original 7ff8, guest PC 0x0c0c7e00 */
if(!s->budget--) { s->failed_pc=0x0c0c7e00u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c7e02;
P_0c0c7e02: /* original 2f42, guest PC 0x0c0c7e02 */
if(!s->budget--) { s->failed_pc=0x0c0c7e02u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c7e04;
P_0c0c7e04: /* original 1f51, guest PC 0x0c0c7e04 */
if(!s->budget--) { s->failed_pc=0x0c0c7e04u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0c7e06;
P_0c0c7e06: /* original 63f2, guest PC 0x0c0c7e06 */
if(!s->budget--) { s->failed_pc=0x0c0c7e06u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c7e08;
P_0c0c7e08: /* original d544, guest PC 0x0c0c7e08 */
if(!s->budget--) { s->failed_pc=0x0c0c7e08u; return 0; }
r[5]=read(ram,0x0c0c7f1cu,4);
goto P_0c0c7e0a;
P_0c0c7e0a: /* original 2338, guest PC 0x0c0c7e0a */
if(!s->budget--) { s->failed_pc=0x0c0c7e0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7e0c;
P_0c0c7e0c: /* original 8b01, guest PC 0x0c0c7e0c */
if(!s->budget--) { s->failed_pc=0x0c0c7e0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7e12; }
goto P_0c0c7e0e;
P_0c0c7e0e: /* original a001, guest PC 0x0c0c7e0e */
if(!s->budget--) { s->failed_pc=0x0c0c7e0eu; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c7e14;
P_0c0c7e10: /* original 5454, guest PC 0x0c0c7e10 */
if(!s->budget--) { s->failed_pc=0x0c0c7e10u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c0c7e12;
P_0c0c7e12: /* original 5455, guest PC 0x0c0c7e12 */
if(!s->budget--) { s->failed_pc=0x0c0c7e12u; return 0; }
r[4]=read(ram,r[5]+20,4);
goto P_0c0c7e14;
P_0c0c7e14: /* original 65f2, guest PC 0x0c0c7e14 */
if(!s->budget--) { s->failed_pc=0x0c0c7e14u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0c7e16;
P_0c0c7e16: /* original 56f1, guest PC 0x0c0c7e16 */
if(!s->budget--) { s->failed_pc=0x0c0c7e16u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0c7e18;
P_0c0c7e18: /* original a000, guest PC 0x0c0c7e18 */
if(!s->budget--) { s->failed_pc=0x0c0c7e18u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7e1c;
P_0c0c7e1a: /* original 7f08, guest PC 0x0c0c7e1a */
if(!s->budget--) { s->failed_pc=0x0c0c7e1au; return 0; }
r[15]+=0x00000008u;
goto P_0c0c7e1c;
P_0c0c7e1c: /* original 2fe6, guest PC 0x0c0c7e1c */
if(!s->budget--) { s->failed_pc=0x0c0c7e1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e1e;
P_0c0c7e1e: /* original e00c, guest PC 0x0c0c7e1e */
if(!s->budget--) { s->failed_pc=0x0c0c7e1eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e20;
P_0c0c7e20: /* original 2fd6, guest PC 0x0c0c7e20 */
if(!s->budget--) { s->failed_pc=0x0c0c7e20u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e22;
P_0c0c7e22: /* original 6d53, guest PC 0x0c0c7e22 */
if(!s->budget--) { s->failed_pc=0x0c0c7e22u; return 0; }
r[13]=r[5];
goto P_0c0c7e24;
P_0c0c7e24: /* original 2fc6, guest PC 0x0c0c7e24 */
if(!s->budget--) { s->failed_pc=0x0c0c7e24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e26;
P_0c0c7e26: /* original 2fb6, guest PC 0x0c0c7e26 */
if(!s->budget--) { s->failed_pc=0x0c0c7e26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7e28;
P_0c0c7e28: /* original fffb, guest PC 0x0c0c7e28 */
if(!s->budget--) { s->failed_pc=0x0c0c7e28u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c7e2a;
P_0c0c7e2a: /* original 4f22, guest PC 0x0c0c7e2a */
if(!s->budget--) { s->failed_pc=0x0c0c7e2au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7e2c;
P_0c0c7e2c: /* original 7fec, guest PC 0x0c0c7e2c */
if(!s->budget--) { s->failed_pc=0x0c0c7e2cu; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c7e2e;
P_0c0c7e2e: /* original ff47, guest PC 0x0c0c7e2e */
if(!s->budget--) { s->failed_pc=0x0c0c7e2eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e30;
P_0c0c7e30: /* original e010, guest PC 0x0c0c7e30 */
if(!s->budget--) { s->failed_pc=0x0c0c7e30u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e32;
P_0c0c7e32: /* original ff67, guest PC 0x0c0c7e32 */
if(!s->budget--) { s->failed_pc=0x0c0c7e32u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c0c7e34;
P_0c0c7e34: /* original 1f62, guest PC 0x0c0c7e34 */
if(!s->budget--) { s->failed_pc=0x0c0c7e34u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0c7e36;
P_0c0c7e36: /* original dc37, guest PC 0x0c0c7e36 */
if(!s->budget--) { s->failed_pc=0x0c0c7e36u; return 0; }
r[12]=read(ram,0x0c0c7f14u,4);
goto P_0c0c7e38;
P_0c0c7e38: /* original bfd6, guest PC 0x0c0c7e38 */
if(!s->budget--) { s->failed_pc=0x0c0c7e38u; return 0; }
target=code_base|0x0c0c7de8u; r[16]=code_base|0x0c0c7e3cu;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e3cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e3c;
P_0c0c7e3a: /* original 6e43, guest PC 0x0c0c7e3a */
if(!s->budget--) { s->failed_pc=0x0c0c7e3au; return 0; }
r[14]=r[4];
goto P_0c0c7e3c;
P_0c0c7e3c: /* original 60d3, guest PC 0x0c0c7e3c */
if(!s->budget--) { s->failed_pc=0x0c0c7e3cu; return 0; }
r[0]=r[13];
goto P_0c0c7e3e;
P_0c0c7e3e: /* original 80e4, guest PC 0x0c0c7e3e */
if(!s->budget--) { s->failed_pc=0x0c0c7e3eu; return 0; }
write(ram,r[14]+4,r[0],1);
goto P_0c0c7e40;
P_0c0c7e40: /* original e01c, guest PC 0x0c0c7e40 */
if(!s->budget--) { s->failed_pc=0x0c0c7e40u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7e42;
P_0c0c7e42: /* original d337, guest PC 0x0c0c7e42 */
if(!s->budget--) { s->failed_pc=0x0c0c7e42u; return 0; }
r[3]=read(ram,0x0c0c7f20u,4);
goto P_0c0c7e44;
P_0c0c7e44: /* original 04cc, guest PC 0x0c0c7e44 */
if(!s->budget--) { s->failed_pc=0x0c0c7e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c7e46;
P_0c0c7e46: /* original e032, guest PC 0x0c0c7e46 */
if(!s->budget--) { s->failed_pc=0x0c0c7e46u; return 0; }
r[0]=0x00000032u;
goto P_0c0c7e48;
P_0c0c7e48: /* original 65f3, guest PC 0x0c0c7e48 */
if(!s->budget--) { s->failed_pc=0x0c0c7e48u; return 0; }
r[5]=r[15];
goto P_0c0c7e4a;
P_0c0c7e4a: /* original 7504, guest PC 0x0c0c7e4a */
if(!s->budget--) { s->failed_pc=0x0c0c7e4au; return 0; }
r[5]+=0x00000004u;
goto P_0c0c7e4c;
P_0c0c7e4c: /* original 644c, guest PC 0x0c0c7e4c */
if(!s->budget--) { s->failed_pc=0x0c0c7e4cu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7e4e;
P_0c0c7e4e: /* original 66f3, guest PC 0x0c0c7e4e */
if(!s->budget--) { s->failed_pc=0x0c0c7e4eu; return 0; }
r[6]=r[15];
goto P_0c0c7e50;
P_0c0c7e50: /* original 4408, guest PC 0x0c0c7e50 */
if(!s->budget--) { s->failed_pc=0x0c0c7e50u; return 0; }
r[4]<<=2;
goto P_0c0c7e52;
P_0c0c7e52: /* original 4408, guest PC 0x0c0c7e52 */
if(!s->budget--) { s->failed_pc=0x0c0c7e52u; return 0; }
r[4]<<=2;
goto P_0c0c7e54;
P_0c0c7e54: /* original 4408, guest PC 0x0c0c7e54 */
if(!s->budget--) { s->failed_pc=0x0c0c7e54u; return 0; }
r[4]<<=2;
goto P_0c0c7e56;
P_0c0c7e56: /* original 343c, guest PC 0x0c0c7e56 */
if(!s->budget--) { s->failed_pc=0x0c0c7e56u; return 0; }
r[4]+=r[3];
goto P_0c0c7e58;
P_0c0c7e58: /* original 0b4d, guest PC 0x0c0c7e58 */
if(!s->budget--) { s->failed_pc=0x0c0c7e58u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c7e5a;
P_0c0c7e5a: /* original e028, guest PC 0x0c0c7e5a */
if(!s->budget--) { s->failed_pc=0x0c0c7e5au; return 0; }
r[0]=0x00000028u;
goto P_0c0c7e5c;
P_0c0c7e5c: /* original f446, guest PC 0x0c0c7e5c */
if(!s->budget--) { s->failed_pc=0x0c0c7e5cu; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0c7e5e;
P_0c0c7e5e: /* original e00c, guest PC 0x0c0c7e5e */
if(!s->budget--) { s->failed_pc=0x0c0c7e5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c7e60;
P_0c0c7e60: /* original f34c, guest PC 0x0c0c7e60 */
if(!s->budget--) { s->failed_pc=0x0c0c7e60u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0c7e62;
P_0c0c7e62: /* original f4f6, guest PC 0x0c0c7e62 */
if(!s->budget--) { s->failed_pc=0x0c0c7e62u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e64;
P_0c0c7e64: /* original e010, guest PC 0x0c0c7e64 */
if(!s->budget--) { s->failed_pc=0x0c0c7e64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e66;
P_0c0c7e66: /* original f5f6, guest PC 0x0c0c7e66 */
if(!s->budget--) { s->failed_pc=0x0c0c7e66u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c7e68;
P_0c0c7e68: /* original e004, guest PC 0x0c0c7e68 */
if(!s->budget--) { s->failed_pc=0x0c0c7e68u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e6a;
P_0c0c7e6a: /* original f430, guest PC 0x0c0c7e6a */
if(!s->budget--) { s->failed_pc=0x0c0c7e6au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c7e6c;
P_0c0c7e6c: /* original ff47, guest PC 0x0c0c7e6c */
if(!s->budget--) { s->failed_pc=0x0c0c7e6cu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c7e6e;
P_0c0c7e6e: /* original ff5a, guest PC 0x0c0c7e6e */
if(!s->budget--) { s->failed_pc=0x0c0c7e6eu; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c0c7e70;
P_0c0c7e70: /* original d22c, guest PC 0x0c0c7e70 */
if(!s->budget--) { s->failed_pc=0x0c0c7e70u; return 0; }
r[2]=read(ram,0x0c0c7f24u,4);
goto P_0c0c7e72;
P_0c0c7e72: /* original 420b, guest PC 0x0c0c7e72 */
if(!s->budget--) { s->failed_pc=0x0c0c7e72u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7e76u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e76u) { target=s->pc; goto dispatch; }
goto P_0c0c7e76;
P_0c0c7e74: /* original 64b3, guest PC 0x0c0c7e74 */
if(!s->budget--) { s->failed_pc=0x0c0c7e74u; return 0; }
r[4]=r[11];
goto P_0c0c7e76;
P_0c0c7e76: /* original e004, guest PC 0x0c0c7e76 */
if(!s->budget--) { s->failed_pc=0x0c0c7e76u; return 0; }
r[0]=0x00000004u;
goto P_0c0c7e78;
P_0c0c7e78: /* original fff8, guest PC 0x0c0c7e78 */
if(!s->budget--) { s->failed_pc=0x0c0c7e78u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c7e7a;
P_0c0c7e7a: /* original f4f6, guest PC 0x0c0c7e7a */
if(!s->budget--) { s->failed_pc=0x0c0c7e7au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0c7e7c;
P_0c0c7e7c: /* original e010, guest PC 0x0c0c7e7c */
if(!s->budget--) { s->failed_pc=0x0c0c7e7cu; return 0; }
r[0]=0x00000010u;
goto P_0c0c7e7e;
P_0c0c7e7e: /* original 54f2, guest PC 0x0c0c7e7e */
if(!s->budget--) { s->failed_pc=0x0c0c7e7eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0c7e80;
P_0c0c7e80: /* original fe47, guest PC 0x0c0c7e80 */
if(!s->budget--) { s->failed_pc=0x0c0c7e80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e82;
P_0c0c7e82: /* original e018, guest PC 0x0c0c7e82 */
if(!s->budget--) { s->failed_pc=0x0c0c7e82u; return 0; }
r[0]=0x00000018u;
goto P_0c0c7e84;
P_0c0c7e84: /* original fef7, guest PC 0x0c0c7e84 */
if(!s->budget--) { s->failed_pc=0x0c0c7e84u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e86;
P_0c0c7e86: /* original 34bc, guest PC 0x0c0c7e86 */
if(!s->budget--) { s->failed_pc=0x0c0c7e86u; return 0; }
r[4]+=r[11];
goto P_0c0c7e88;
P_0c0c7e88: /* original 903d, guest PC 0x0c0c7e88 */
if(!s->budget--) { s->failed_pc=0x0c0c7e88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f06u,2);
goto P_0c0c7e8a;
P_0c0c7e8a: /* original fe47, guest PC 0x0c0c7e8a */
if(!s->budget--) { s->failed_pc=0x0c0c7e8au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7e8c;
P_0c0c7e8c: /* original 7008, guest PC 0x0c0c7e8c */
if(!s->budget--) { s->failed_pc=0x0c0c7e8cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c7e8e;
P_0c0c7e8e: /* original fef7, guest PC 0x0c0c7e8e */
if(!s->budget--) { s->failed_pc=0x0c0c7e8eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c0c7e90;
P_0c0c7e90: /* original 6043, guest PC 0x0c0c7e90 */
if(!s->budget--) { s->failed_pc=0x0c0c7e90u; return 0; }
r[0]=r[4];
goto P_0c0c7e92;
P_0c0c7e92: /* original 81ef, guest PC 0x0c0c7e92 */
if(!s->budget--) { s->failed_pc=0x0c0c7e92u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c7e94;
P_0c0c7e94: /* original d324, guest PC 0x0c0c7e94 */
if(!s->budget--) { s->failed_pc=0x0c0c7e94u; return 0; }
r[3]=read(ram,0x0c0c7f28u,4);
goto P_0c0c7e96;
P_0c0c7e96: /* original f5fc, guest PC 0x0c0c7e96 */
if(!s->budget--) { s->failed_pc=0x0c0c7e96u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0c7e98;
P_0c0c7e98: /* original 430b, guest PC 0x0c0c7e98 */
if(!s->budget--) { s->failed_pc=0x0c0c7e98u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7e9cu;
fr[5]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7e9cu) { target=s->pc; goto dispatch; }
goto P_0c0c7e9c;
P_0c0c7e9a: /* original f54d, guest PC 0x0c0c7e9a */
if(!s->budget--) { s->failed_pc=0x0c0c7e9au; return 0; }
fr[5]^=0x80000000u;
goto P_0c0c7e9c;
P_0c0c7e9c: /* original e014, guest PC 0x0c0c7e9c */
if(!s->budget--) { s->failed_pc=0x0c0c7e9cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c7e9e;
P_0c0c7e9e: /* original f40c, guest PC 0x0c0c7e9e */
if(!s->budget--) { s->failed_pc=0x0c0c7e9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c7ea0;
P_0c0c7ea0: /* original fe47, guest PC 0x0c0c7ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea2;
P_0c0c7ea2: /* original e30d, guest PC 0x0c0c7ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea2u; return 0; }
r[3]=0x0000000du;
goto P_0c0c7ea4;
P_0c0c7ea4: /* original 9030, guest PC 0x0c0c7ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f08u,2);
goto P_0c0c7ea6;
P_0c0c7ea6: /* original fe47, guest PC 0x0c0c7ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0c7ea8;
P_0c0c7ea8: /* original e060, guest PC 0x0c0c7ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ea8u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7eaa;
P_0c0c7eaa: /* original 04ec, guest PC 0x0c0c7eaa */
if(!s->budget--) { s->failed_pc=0x0c0c7eaau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7eac;
P_0c0c7eac: /* original 644c, guest PC 0x0c0c7eac */
if(!s->budget--) { s->failed_pc=0x0c0c7eacu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7eae;
P_0c0c7eae: /* original 3433, guest PC 0x0c0c7eae */
if(!s->budget--) { s->failed_pc=0x0c0c7eaeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c0c7eb0;
P_0c0c7eb0: /* original 8f01, guest PC 0x0c0c7eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb0u; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(!cond) { goto P_0c0c7eb6; }
goto P_0c0c7eb4;
P_0c0c7eb2: /* original e061, guest PC 0x0c0c7eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb2u; return 0; }
r[0]=0x00000061u;
goto P_0c0c7eb4;
P_0c0c7eb4: /* original 74f3, guest PC 0x0c0c7eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb4u; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c7eb6;
P_0c0c7eb6: /* original 634b, guest PC 0x0c0c7eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb6u; return 0; }
r[3]=0u-r[4];
goto P_0c0c7eb8;
P_0c0c7eb8: /* original 0e44, guest PC 0x0c0c7eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7eb8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7eba;
P_0c0c7eba: /* original d41c, guest PC 0x0c0c7eba */
if(!s->budget--) { s->failed_pc=0x0c0c7ebau; return 0; }
r[4]=read(ram,0x0c0c7f2cu,4);
goto P_0c0c7ebc;
P_0c0c7ebc: /* original 9025, guest PC 0x0c0c7ebc */
if(!s->budget--) { s->failed_pc=0x0c0c7ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0au,2);
goto P_0c0c7ebe;
P_0c0c7ebe: /* original 443d, guest PC 0x0c0c7ebe */
if(!s->budget--) { s->failed_pc=0x0c0c7ebeu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0c7ec0;
P_0c0c7ec0: /* original 0e46, guest PC 0x0c0c7ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ec2;
P_0c0c7ec2: /* original e400, guest PC 0x0c0c7ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec2u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7ec4;
P_0c0c7ec4: /* original e022, guest PC 0x0c0c7ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec4u; return 0; }
r[0]=0x00000022u;
goto P_0c0c7ec6;
P_0c0c7ec6: /* original d31a, guest PC 0x0c0c7ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec6u; return 0; }
r[3]=read(ram,0x0c0c7f30u,4);
goto P_0c0c7ec8;
P_0c0c7ec8: /* original 1e33, guest PC 0x0c0c7ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ec8u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0c7eca;
P_0c0c7eca: /* original 0e44, guest PC 0x0c0c7eca */
if(!s->budget--) { s->failed_pc=0x0c0c7ecau; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ecc;
P_0c0c7ecc: /* original 901e, guest PC 0x0c0c7ecc */
if(!s->budget--) { s->failed_pc=0x0c0c7eccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0cu,2);
goto P_0c0c7ece;
P_0c0c7ece: /* original 0e46, guest PC 0x0c0c7ece */
if(!s->budget--) { s->failed_pc=0x0c0c7eceu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed0;
P_0c0c7ed0: /* original 700c, guest PC 0x0c0c7ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed0u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7ed2;
P_0c0c7ed2: /* original 0e46, guest PC 0x0c0c7ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed2u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed4;
P_0c0c7ed4: /* original 901b, guest PC 0x0c0c7ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f0eu,2);
goto P_0c0c7ed6;
P_0c0c7ed6: /* original 0e46, guest PC 0x0c0c7ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed6u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7ed8;
P_0c0c7ed8: /* original 700c, guest PC 0x0c0c7ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ed8u; return 0; }
r[0]+=0x0000000cu;
goto P_0c0c7eda;
P_0c0c7eda: /* original 0e46, guest PC 0x0c0c7eda */
if(!s->budget--) { s->failed_pc=0x0c0c7edau; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0c7edc;
P_0c0c7edc: /* original 9018, guest PC 0x0c0c7edc */
if(!s->budget--) { s->failed_pc=0x0c0c7edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7f10u,2);
goto P_0c0c7ede;
P_0c0c7ede: /* original 0e44, guest PC 0x0c0c7ede */
if(!s->budget--) { s->failed_pc=0x0c0c7edeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c7ee0;
P_0c0c7ee0: /* original e401, guest PC 0x0c0c7ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee0u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7ee2;
P_0c0c7ee2: /* original 60e2, guest PC 0x0c0c7ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee2u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c7ee4;
P_0c0c7ee4: /* original d313, guest PC 0x0c0c7ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee4u; return 0; }
r[3]=read(ram,0x0c0c7f34u,4);
goto P_0c0c7ee6;
P_0c0c7ee6: /* original 2039, guest PC 0x0c0c7ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee6u; return 0; }
r[0]&=r[3];
goto P_0c0c7ee8;
P_0c0c7ee8: /* original 240b, guest PC 0x0c0c7ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ee8u; return 0; }
r[4]|=r[0];
goto P_0c0c7eea;
P_0c0c7eea: /* original 2e42, guest PC 0x0c0c7eea */
if(!s->budget--) { s->failed_pc=0x0c0c7eeau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0c7eec;
P_0c0c7eec: /* original d212, guest PC 0x0c0c7eec */
if(!s->budget--) { s->failed_pc=0x0c0c7eecu; return 0; }
r[2]=read(ram,0x0c0c7f38u,4);
goto P_0c0c7eee;
P_0c0c7eee: /* original 420b, guest PC 0x0c0c7eee */
if(!s->budget--) { s->failed_pc=0x0c0c7eeeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7ef2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ef2u) { target=s->pc; goto dispatch; }
goto P_0c0c7ef2;
P_0c0c7ef0: /* original 64e3, guest PC 0x0c0c7ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef0u; return 0; }
r[4]=r[14];
goto P_0c0c7ef2;
P_0c0c7ef2: /* original 62c2, guest PC 0x0c0c7ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef2u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c7ef4;
P_0c0c7ef4: /* original d311, guest PC 0x0c0c7ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef4u; return 0; }
r[3]=read(ram,0x0c0c7f3cu,4);
goto P_0c0c7ef6;
P_0c0c7ef6: /* original 2238, guest PC 0x0c0c7ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c7ef8;
P_0c0c7ef8: /* original 8924, guest PC 0x0c0c7ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ef8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f44; }
goto P_0c0c7efa;
P_0c0c7efa: /* original d211, guest PC 0x0c0c7efa */
if(!s->budget--) { s->failed_pc=0x0c0c7efau; return 0; }
r[2]=read(ram,0x0c0c7f40u,4);
goto P_0c0c7efc;
P_0c0c7efc: /* original 420b, guest PC 0x0c0c7efc */
if(!s->budget--) { s->failed_pc=0x0c0c7efcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f00u) { target=s->pc; goto dispatch; }
goto P_0c0c7f00;
P_0c0c7efe: /* original 64e3, guest PC 0x0c0c7efe */
if(!s->budget--) { s->failed_pc=0x0c0c7efeu; return 0; }
r[4]=r[14];
goto P_0c0c7f00;
P_0c0c7f00: /* original a02a, guest PC 0x0c0c7f00 */
if(!s->budget--) { s->failed_pc=0x0c0c7f00u; return 0; }
goto P_0c0c7f58;
P_0c0c7f02: /* original 0009, guest PC 0x0c0c7f02 */
if(!s->budget--) { s->failed_pc=0x0c0c7f02u; return 0; }
if(!vf3_matrix_family(0x0c0c7f04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7f04u; return 0; } return 1;
P_0c0c7f44: /* original e060, guest PC 0x0c0c7f44 */
if(!s->budget--) { s->failed_pc=0x0c0c7f44u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f46;
P_0c0c7f46: /* original d247, guest PC 0x0c0c7f46 */
if(!s->budget--) { s->failed_pc=0x0c0c7f46u; return 0; }
r[2]=read(ram,0x0c0c8064u,4);
goto P_0c0c7f48;
P_0c0c7f48: /* original 05ec, guest PC 0x0c0c7f48 */
if(!s->budget--) { s->failed_pc=0x0c0c7f48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f4a;
P_0c0c7f4a: /* original 84e4, guest PC 0x0c0c7f4a */
if(!s->budget--) { s->failed_pc=0x0c0c7f4au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7f4c;
P_0c0c7f4c: /* original 655c, guest PC 0x0c0c7f4c */
if(!s->budget--) { s->failed_pc=0x0c0c7f4cu; return 0; }
r[5]=r[5]&255u;
goto P_0c0c7f4e;
P_0c0c7f4e: /* original 420b, guest PC 0x0c0c7f4e */
if(!s->budget--) { s->failed_pc=0x0c0c7f4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f52u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f52u) { target=s->pc; goto dispatch; }
goto P_0c0c7f52;
P_0c0c7f50: /* original 640c, guest PC 0x0c0c7f50 */
if(!s->budget--) { s->failed_pc=0x0c0c7f50u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7f52;
P_0c0c7f52: /* original d345, guest PC 0x0c0c7f52 */
if(!s->budget--) { s->failed_pc=0x0c0c7f52u; return 0; }
r[3]=read(ram,0x0c0c8068u,4);
goto P_0c0c7f54;
P_0c0c7f54: /* original 430b, guest PC 0x0c0c7f54 */
if(!s->budget--) { s->failed_pc=0x0c0c7f54u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f58u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f58u) { target=s->pc; goto dispatch; }
goto P_0c0c7f58;
P_0c0c7f56: /* original 64e3, guest PC 0x0c0c7f56 */
if(!s->budget--) { s->failed_pc=0x0c0c7f56u; return 0; }
r[4]=r[14];
goto P_0c0c7f58;
P_0c0c7f58: /* original e060, guest PC 0x0c0c7f58 */
if(!s->budget--) { s->failed_pc=0x0c0c7f58u; return 0; }
r[0]=0x00000060u;
goto P_0c0c7f5a;
P_0c0c7f5a: /* original 02ec, guest PC 0x0c0c7f5a */
if(!s->budget--) { s->failed_pc=0x0c0c7f5au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7f5c;
P_0c0c7f5c: /* original 907e, guest PC 0x0c0c7f5c */
if(!s->budget--) { s->failed_pc=0x0c0c7f5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c805cu,2);
goto P_0c0c7f5e;
P_0c0c7f5e: /* original 0e24, guest PC 0x0c0c7f5e */
if(!s->budget--) { s->failed_pc=0x0c0c7f5eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c7f60;
P_0c0c7f60: /* original d342, guest PC 0x0c0c7f60 */
if(!s->budget--) { s->failed_pc=0x0c0c7f60u; return 0; }
r[3]=read(ram,0x0c0c806cu,4);
goto P_0c0c7f62;
P_0c0c7f62: /* original 61c2, guest PC 0x0c0c7f62 */
if(!s->budget--) { s->failed_pc=0x0c0c7f62u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c7f64;
P_0c0c7f64: /* original 2138, guest PC 0x0c0c7f64 */
if(!s->budget--) { s->failed_pc=0x0c0c7f64u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7f66;
P_0c0c7f66: /* original 8904, guest PC 0x0c0c7f66 */
if(!s->budget--) { s->failed_pc=0x0c0c7f66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7f72; }
goto P_0c0c7f68;
P_0c0c7f68: /* original d241, guest PC 0x0c0c7f68 */
if(!s->budget--) { s->failed_pc=0x0c0c7f68u; return 0; }
r[2]=read(ram,0x0c0c8070u,4);
goto P_0c0c7f6a;
P_0c0c7f6a: /* original 420b, guest PC 0x0c0c7f6a */
if(!s->budget--) { s->failed_pc=0x0c0c7f6au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f6eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f6eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f6e;
P_0c0c7f6c: /* original 0009, guest PC 0x0c0c7f6c */
if(!s->budget--) { s->failed_pc=0x0c0c7f6cu; return 0; }
goto P_0c0c7f6e;
P_0c0c7f6e: /* original a006, guest PC 0x0c0c7f6e */
if(!s->budget--) { s->failed_pc=0x0c0c7f6eu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f70: /* original 0009, guest PC 0x0c0c7f70 */
if(!s->budget--) { s->failed_pc=0x0c0c7f70u; return 0; }
goto P_0c0c7f72;
P_0c0c7f72: /* original 60d3, guest PC 0x0c0c7f72 */
if(!s->budget--) { s->failed_pc=0x0c0c7f72u; return 0; }
r[0]=r[13];
goto P_0c0c7f74;
P_0c0c7f74: /* original 8801, guest PC 0x0c0c7f74 */
if(!s->budget--) { s->failed_pc=0x0c0c7f74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c7f76;
P_0c0c7f76: /* original 8b02, guest PC 0x0c0c7f76 */
if(!s->budget--) { s->failed_pc=0x0c0c7f76u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f7e; }
goto P_0c0c7f78;
P_0c0c7f78: /* original d13e, guest PC 0x0c0c7f78 */
if(!s->budget--) { s->failed_pc=0x0c0c7f78u; return 0; }
r[1]=read(ram,0x0c0c8074u,4);
goto P_0c0c7f7a;
P_0c0c7f7a: /* original 410b, guest PC 0x0c0c7f7a */
if(!s->budget--) { s->failed_pc=0x0c0c7f7au; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7f7eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f7eu) { target=s->pc; goto dispatch; }
goto P_0c0c7f7e;
P_0c0c7f7c: /* original 0009, guest PC 0x0c0c7f7c */
if(!s->budget--) { s->failed_pc=0x0c0c7f7cu; return 0; }
goto P_0c0c7f7e;
P_0c0c7f7e: /* original d33e, guest PC 0x0c0c7f7e */
if(!s->budget--) { s->failed_pc=0x0c0c7f7eu; return 0; }
r[3]=read(ram,0x0c0c8078u,4);
goto P_0c0c7f80;
P_0c0c7f80: /* original 430b, guest PC 0x0c0c7f80 */
if(!s->budget--) { s->failed_pc=0x0c0c7f80u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f84u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f84u) { target=s->pc; goto dispatch; }
goto P_0c0c7f84;
P_0c0c7f82: /* original 64e3, guest PC 0x0c0c7f82 */
if(!s->budget--) { s->failed_pc=0x0c0c7f82u; return 0; }
r[4]=r[14];
goto P_0c0c7f84;
P_0c0c7f84: /* original d23d, guest PC 0x0c0c7f84 */
if(!s->budget--) { s->failed_pc=0x0c0c7f84u; return 0; }
r[2]=read(ram,0x0c0c807cu,4);
goto P_0c0c7f86;
P_0c0c7f86: /* original 420b, guest PC 0x0c0c7f86 */
if(!s->budget--) { s->failed_pc=0x0c0c7f86u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7f8au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f8au) { target=s->pc; goto dispatch; }
goto P_0c0c7f8a;
P_0c0c7f88: /* original 0009, guest PC 0x0c0c7f88 */
if(!s->budget--) { s->failed_pc=0x0c0c7f88u; return 0; }
goto P_0c0c7f8a;
P_0c0c7f8a: /* original 2dd8, guest PC 0x0c0c7f8a */
if(!s->budget--) { s->failed_pc=0x0c0c7f8au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0c7f8c;
P_0c0c7f8c: /* original 8b06, guest PC 0x0c0c7f8c */
if(!s->budget--) { s->failed_pc=0x0c0c7f8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7f9c; }
goto P_0c0c7f8e;
P_0c0c7f8e: /* original d33e, guest PC 0x0c0c7f8e */
if(!s->budget--) { s->failed_pc=0x0c0c7f8eu; return 0; }
r[3]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f90;
P_0c0c7f90: /* original d23c, guest PC 0x0c0c7f90 */
if(!s->budget--) { s->failed_pc=0x0c0c7f90u; return 0; }
r[2]=read(ram,0x0c0c8084u,4);
goto P_0c0c7f92;
P_0c0c7f92: /* original d53b, guest PC 0x0c0c7f92 */
if(!s->budget--) { s->failed_pc=0x0c0c7f92u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7f94;
P_0c0c7f94: /* original 430b, guest PC 0x0c0c7f94 */
if(!s->budget--) { s->failed_pc=0x0c0c7f94u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7f98u;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7f98u) { target=s->pc; goto dispatch; }
goto P_0c0c7f98;
P_0c0c7f96: /* original 6422, guest PC 0x0c0c7f96 */
if(!s->budget--) { s->failed_pc=0x0c0c7f96u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c7f98;
P_0c0c7f98: /* original a005, guest PC 0x0c0c7f98 */
if(!s->budget--) { s->failed_pc=0x0c0c7f98u; return 0; }
goto P_0c0c7fa6;
P_0c0c7f9a: /* original 0009, guest PC 0x0c0c7f9a */
if(!s->budget--) { s->failed_pc=0x0c0c7f9au; return 0; }
goto P_0c0c7f9c;
P_0c0c7f9c: /* original d23a, guest PC 0x0c0c7f9c */
if(!s->budget--) { s->failed_pc=0x0c0c7f9cu; return 0; }
r[2]=read(ram,0x0c0c8088u,4);
goto P_0c0c7f9e;
P_0c0c7f9e: /* original d33b, guest PC 0x0c0c7f9e */
if(!s->budget--) { s->failed_pc=0x0c0c7f9eu; return 0; }
r[3]=read(ram,0x0c0c808cu,4);
goto P_0c0c7fa0;
P_0c0c7fa0: /* original d537, guest PC 0x0c0c7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa0u; return 0; }
r[5]=read(ram,0x0c0c8080u,4);
goto P_0c0c7fa2;
P_0c0c7fa2: /* original 420b, guest PC 0x0c0c7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7fa6u;
tmp=read(ram,r[3],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7fa6u) { target=s->pc; goto dispatch; }
goto P_0c0c7fa6;
P_0c0c7fa4: /* original 6432, guest PC 0x0c0c7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c0c7fa6;
P_0c0c7fa6: /* original 7f14, guest PC 0x0c0c7fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa6u; return 0; }
r[15]+=0x00000014u;
goto P_0c0c7fa8;
P_0c0c7fa8: /* original 4f26, guest PC 0x0c0c7fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c7fa8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7faa;
P_0c0c7faa: /* original fff9, guest PC 0x0c0c7faa */
if(!s->budget--) { s->failed_pc=0x0c0c7faau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c7fac;
P_0c0c7fac: /* original 6bf6, guest PC 0x0c0c7fac */
if(!s->budget--) { s->failed_pc=0x0c0c7facu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7fae;
P_0c0c7fae: /* original 6cf6, guest PC 0x0c0c7fae */
if(!s->budget--) { s->failed_pc=0x0c0c7faeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7fb0;
P_0c0c7fb0: /* original 6df6, guest PC 0x0c0c7fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7fb2;
P_0c0c7fb2: /* original 000b, guest PC 0x0c0c7fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c7fb4: /* original 6ef6, guest PC 0x0c0c7fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7fb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7fb6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7fb6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
