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
int vf3_away_batch237_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c0bf4u: goto P_0c0c0bf4;
case 0x0c0c0bf6u: goto P_0c0c0bf6;
case 0x0c0c0bf8u: goto P_0c0c0bf8;
case 0x0c0c0bfau: goto P_0c0c0bfa;
case 0x0c0c0bfcu: goto P_0c0c0bfc;
case 0x0c0c0bfeu: goto P_0c0c0bfe;
case 0x0c0c0c00u: goto P_0c0c0c00;
case 0x0c0c0c02u: goto P_0c0c0c02;
case 0x0c0c0c04u: goto P_0c0c0c04;
case 0x0c0c0c06u: goto P_0c0c0c06;
case 0x0c0c0c08u: goto P_0c0c0c08;
case 0x0c0c0c0au: goto P_0c0c0c0a;
case 0x0c0c0c0cu: goto P_0c0c0c0c;
case 0x0c0c0c0eu: goto P_0c0c0c0e;
case 0x0c0c0c10u: goto P_0c0c0c10;
case 0x0c0c0c12u: goto P_0c0c0c12;
case 0x0c0c0c14u: goto P_0c0c0c14;
case 0x0c0c0c16u: goto P_0c0c0c16;
case 0x0c0c0c18u: goto P_0c0c0c18;
case 0x0c0c0c1au: goto P_0c0c0c1a;
case 0x0c0c0c1cu: goto P_0c0c0c1c;
case 0x0c0c0c1eu: goto P_0c0c0c1e;
case 0x0c0c0c20u: goto P_0c0c0c20;
case 0x0c0c0c22u: goto P_0c0c0c22;
case 0x0c0c0c24u: goto P_0c0c0c24;
case 0x0c0c0c26u: goto P_0c0c0c26;
case 0x0c0c0c28u: goto P_0c0c0c28;
case 0x0c0c0c2au: goto P_0c0c0c2a;
case 0x0c0c0c2cu: goto P_0c0c0c2c;
case 0x0c0c0c2eu: goto P_0c0c0c2e;
case 0x0c0c0c30u: goto P_0c0c0c30;
case 0x0c0c0c32u: goto P_0c0c0c32;
case 0x0c0c0c34u: goto P_0c0c0c34;
case 0x0c0c0c36u: goto P_0c0c0c36;
case 0x0c0c0c38u: goto P_0c0c0c38;
case 0x0c0c0c3au: goto P_0c0c0c3a;
case 0x0c0c0c3cu: goto P_0c0c0c3c;
case 0x0c0c0c3eu: goto P_0c0c0c3e;
case 0x0c0c0c40u: goto P_0c0c0c40;
case 0x0c0c0c42u: goto P_0c0c0c42;
case 0x0c0c0c44u: goto P_0c0c0c44;
case 0x0c0c0c46u: goto P_0c0c0c46;
case 0x0c0c0c48u: goto P_0c0c0c48;
case 0x0c0c0c4au: goto P_0c0c0c4a;
case 0x0c0c0c4cu: goto P_0c0c0c4c;
case 0x0c0c0c4eu: goto P_0c0c0c4e;
case 0x0c0c0c50u: goto P_0c0c0c50;
case 0x0c0c0c52u: goto P_0c0c0c52;
case 0x0c0c0c54u: goto P_0c0c0c54;
case 0x0c0c0c56u: goto P_0c0c0c56;
case 0x0c0c0c58u: goto P_0c0c0c58;
case 0x0c0c0c5au: goto P_0c0c0c5a;
case 0x0c0c0c5cu: goto P_0c0c0c5c;
case 0x0c0c0c5eu: goto P_0c0c0c5e;
case 0x0c0c0c60u: goto P_0c0c0c60;
case 0x0c0c0c62u: goto P_0c0c0c62;
case 0x0c0c0c64u: goto P_0c0c0c64;
case 0x0c0c0c66u: goto P_0c0c0c66;
case 0x0c0c0c68u: goto P_0c0c0c68;
case 0x0c0c0c6au: goto P_0c0c0c6a;
case 0x0c0c0c6cu: goto P_0c0c0c6c;
case 0x0c0c0c6eu: goto P_0c0c0c6e;
case 0x0c0c0c70u: goto P_0c0c0c70;
case 0x0c0c0c72u: goto P_0c0c0c72;
case 0x0c0c0c74u: goto P_0c0c0c74;
case 0x0c0c0c76u: goto P_0c0c0c76;
case 0x0c0c0c78u: goto P_0c0c0c78;
case 0x0c0c0c7au: goto P_0c0c0c7a;
case 0x0c0c0c7cu: goto P_0c0c0c7c;
case 0x0c0c0c7eu: goto P_0c0c0c7e;
case 0x0c0c0c80u: goto P_0c0c0c80;
case 0x0c0c0c82u: goto P_0c0c0c82;
case 0x0c0c0c84u: goto P_0c0c0c84;
case 0x0c0c0c86u: goto P_0c0c0c86;
case 0x0c0c0c88u: goto P_0c0c0c88;
case 0x0c0c0c8au: goto P_0c0c0c8a;
case 0x0c0c0c8cu: goto P_0c0c0c8c;
case 0x0c0c0c8eu: goto P_0c0c0c8e;
case 0x0c0c0c90u: goto P_0c0c0c90;
case 0x0c0c0c92u: goto P_0c0c0c92;
case 0x0c0c0c94u: goto P_0c0c0c94;
case 0x0c0c0c96u: goto P_0c0c0c96;
case 0x0c0c0c98u: goto P_0c0c0c98;
case 0x0c0c0c9au: goto P_0c0c0c9a;
case 0x0c0c0c9cu: goto P_0c0c0c9c;
case 0x0c0c0c9eu: goto P_0c0c0c9e;
case 0x0c0c0ca0u: goto P_0c0c0ca0;
case 0x0c0c0ca2u: goto P_0c0c0ca2;
case 0x0c0c0ca4u: goto P_0c0c0ca4;
case 0x0c0c0ca6u: goto P_0c0c0ca6;
case 0x0c0c0ca8u: goto P_0c0c0ca8;
case 0x0c0c0caau: goto P_0c0c0caa;
case 0x0c0c0cacu: goto P_0c0c0cac;
case 0x0c0c0caeu: goto P_0c0c0cae;
case 0x0c0c0cb0u: goto P_0c0c0cb0;
case 0x0c0c0cb2u: goto P_0c0c0cb2;
case 0x0c0c0cb4u: goto P_0c0c0cb4;
case 0x0c0c0cb6u: goto P_0c0c0cb6;
case 0x0c0c0cb8u: goto P_0c0c0cb8;
case 0x0c0c0cbau: goto P_0c0c0cba;
case 0x0c0c0cbcu: goto P_0c0c0cbc;
case 0x0c0c0cbeu: goto P_0c0c0cbe;
case 0x0c0c0cc0u: goto P_0c0c0cc0;
case 0x0c0c0cc2u: goto P_0c0c0cc2;
case 0x0c0c0cc4u: goto P_0c0c0cc4;
case 0x0c0c0cc6u: goto P_0c0c0cc6;
case 0x0c0c0cc8u: goto P_0c0c0cc8;
case 0x0c0c0ccau: goto P_0c0c0cca;
case 0x0c0c0cccu: goto P_0c0c0ccc;
case 0x0c0c0ce8u: goto P_0c0c0ce8;
case 0x0c0c0ceau: goto P_0c0c0cea;
case 0x0c0c0cecu: goto P_0c0c0cec;
case 0x0c0c0ceeu: goto P_0c0c0cee;
case 0x0c0c0cf0u: goto P_0c0c0cf0;
case 0x0c0c0cf2u: goto P_0c0c0cf2;
case 0x0c0c0cf4u: goto P_0c0c0cf4;
case 0x0c0c0cf6u: goto P_0c0c0cf6;
case 0x0c0c0cf8u: goto P_0c0c0cf8;
case 0x0c0c0cfau: goto P_0c0c0cfa;
case 0x0c0c0cfcu: goto P_0c0c0cfc;
case 0x0c0c0cfeu: goto P_0c0c0cfe;
case 0x0c0c0d00u: goto P_0c0c0d00;
case 0x0c0c0d02u: goto P_0c0c0d02;
case 0x0c0c0d04u: goto P_0c0c0d04;
case 0x0c0c0d06u: goto P_0c0c0d06;
case 0x0c0c0d08u: goto P_0c0c0d08;
case 0x0c0c0d0au: goto P_0c0c0d0a;
case 0x0c0c0d0cu: goto P_0c0c0d0c;
case 0x0c0c0d0eu: goto P_0c0c0d0e;
case 0x0c0c0d10u: goto P_0c0c0d10;
case 0x0c0c0d12u: goto P_0c0c0d12;
case 0x0c0c0d14u: goto P_0c0c0d14;
case 0x0c0c0d16u: goto P_0c0c0d16;
case 0x0c0c0d18u: goto P_0c0c0d18;
case 0x0c0c0d1au: goto P_0c0c0d1a;
case 0x0c0c0d1cu: goto P_0c0c0d1c;
case 0x0c0c0d1eu: goto P_0c0c0d1e;
case 0x0c0c0d20u: goto P_0c0c0d20;
case 0x0c0c0d22u: goto P_0c0c0d22;
case 0x0c0c0d24u: goto P_0c0c0d24;
case 0x0c0c0d26u: goto P_0c0c0d26;
case 0x0c0c0d28u: goto P_0c0c0d28;
case 0x0c0c0d2au: goto P_0c0c0d2a;
case 0x0c0c0d2cu: goto P_0c0c0d2c;
case 0x0c0c0d2eu: goto P_0c0c0d2e;
case 0x0c0c0d30u: goto P_0c0c0d30;
case 0x0c0c0d32u: goto P_0c0c0d32;
case 0x0c0c0d34u: goto P_0c0c0d34;
case 0x0c0c0d36u: goto P_0c0c0d36;
case 0x0c0c0d38u: goto P_0c0c0d38;
case 0x0c0c0d3au: goto P_0c0c0d3a;
case 0x0c0c0d3cu: goto P_0c0c0d3c;
case 0x0c0c0d3eu: goto P_0c0c0d3e;
case 0x0c0c0d40u: goto P_0c0c0d40;
case 0x0c0c0d42u: goto P_0c0c0d42;
case 0x0c0c0d44u: goto P_0c0c0d44;
case 0x0c0c0d46u: goto P_0c0c0d46;
case 0x0c0c0d48u: goto P_0c0c0d48;
case 0x0c0c0d4au: goto P_0c0c0d4a;
case 0x0c0c0d4cu: goto P_0c0c0d4c;
case 0x0c0c0d4eu: goto P_0c0c0d4e;
case 0x0c0c0d50u: goto P_0c0c0d50;
case 0x0c0c0d52u: goto P_0c0c0d52;
case 0x0c0c0d54u: goto P_0c0c0d54;
case 0x0c0c0d56u: goto P_0c0c0d56;
case 0x0c0c0d58u: goto P_0c0c0d58;
case 0x0c0c0d5au: goto P_0c0c0d5a;
case 0x0c0c0d5cu: goto P_0c0c0d5c;
case 0x0c0c0d5eu: goto P_0c0c0d5e;
case 0x0c0c0d60u: goto P_0c0c0d60;
case 0x0c0c0d62u: goto P_0c0c0d62;
case 0x0c0c0d64u: goto P_0c0c0d64;
case 0x0c0c0d66u: goto P_0c0c0d66;
case 0x0c0c0d68u: goto P_0c0c0d68;
case 0x0c0c0d6au: goto P_0c0c0d6a;
case 0x0c0c0d6cu: goto P_0c0c0d6c;
case 0x0c0c0d6eu: goto P_0c0c0d6e;
case 0x0c0c0d70u: goto P_0c0c0d70;
case 0x0c0c0d72u: goto P_0c0c0d72;
case 0x0c0c0d74u: goto P_0c0c0d74;
case 0x0c0c0d76u: goto P_0c0c0d76;
case 0x0c0c0d78u: goto P_0c0c0d78;
case 0x0c0c0d7au: goto P_0c0c0d7a;
case 0x0c0c0d7cu: goto P_0c0c0d7c;
case 0x0c0c0d7eu: goto P_0c0c0d7e;
case 0x0c0c0d80u: goto P_0c0c0d80;
case 0x0c0c0d82u: goto P_0c0c0d82;
case 0x0c0c0d84u: goto P_0c0c0d84;
case 0x0c0c0d86u: goto P_0c0c0d86;
case 0x0c0c0d88u: goto P_0c0c0d88;
case 0x0c0c0d8au: goto P_0c0c0d8a;
case 0x0c0c0d8cu: goto P_0c0c0d8c;
case 0x0c0c0d8eu: goto P_0c0c0d8e;
case 0x0c0c0d90u: goto P_0c0c0d90;
case 0x0c0c0d92u: goto P_0c0c0d92;
case 0x0c0c0d94u: goto P_0c0c0d94;
case 0x0c0c0d96u: goto P_0c0c0d96;
case 0x0c0c0d98u: goto P_0c0c0d98;
case 0x0c0c0d9au: goto P_0c0c0d9a;
case 0x0c0c0d9cu: goto P_0c0c0d9c;
case 0x0c0c0d9eu: goto P_0c0c0d9e;
case 0x0c0c0da0u: goto P_0c0c0da0;
case 0x0c0c0da2u: goto P_0c0c0da2;
case 0x0c0c0da4u: goto P_0c0c0da4;
case 0x0c0c0da6u: goto P_0c0c0da6;
case 0x0c0c0da8u: goto P_0c0c0da8;
case 0x0c0c0daau: goto P_0c0c0daa;
case 0x0c0c0dacu: goto P_0c0c0dac;
case 0x0c0c0daeu: goto P_0c0c0dae;
case 0x0c0c0db0u: goto P_0c0c0db0;
case 0x0c0c0db2u: goto P_0c0c0db2;
case 0x0c0c0db4u: goto P_0c0c0db4;
case 0x0c0c0db6u: goto P_0c0c0db6;
case 0x0c0c0db8u: goto P_0c0c0db8;
case 0x0c0c0dbau: goto P_0c0c0dba;
case 0x0c0c0dbcu: goto P_0c0c0dbc;
case 0x0c0c0dbeu: goto P_0c0c0dbe;
case 0x0c0c0dc0u: goto P_0c0c0dc0;
case 0x0c0c0dc2u: goto P_0c0c0dc2;
case 0x0c0c0dc4u: goto P_0c0c0dc4;
case 0x0c0c0dc6u: goto P_0c0c0dc6;
case 0x0c0c0dc8u: goto P_0c0c0dc8;
case 0x0c0c0dcau: goto P_0c0c0dca;
case 0x0c0c0dccu: goto P_0c0c0dcc;
case 0x0c0c0dceu: goto P_0c0c0dce;
case 0x0c0c0dd0u: goto P_0c0c0dd0;
case 0x0c0c0dd2u: goto P_0c0c0dd2;
case 0x0c0c0dd4u: goto P_0c0c0dd4;
case 0x0c0c0dd6u: goto P_0c0c0dd6;
case 0x0c0c0dd8u: goto P_0c0c0dd8;
case 0x0c0c0ddau: goto P_0c0c0dda;
case 0x0c0c0ddcu: goto P_0c0c0ddc;
case 0x0c0c0ddeu: goto P_0c0c0dde;
case 0x0c0c0de0u: goto P_0c0c0de0;
case 0x0c0c0de2u: goto P_0c0c0de2;
case 0x0c0c0de4u: goto P_0c0c0de4;
case 0x0c0c0de6u: goto P_0c0c0de6;
case 0x0c0c0de8u: goto P_0c0c0de8;
case 0x0c0c0deau: goto P_0c0c0dea;
case 0x0c0c0decu: goto P_0c0c0dec;
case 0x0c0c0deeu: goto P_0c0c0dee;
case 0x0c0c0df0u: goto P_0c0c0df0;
case 0x0c0c0df2u: goto P_0c0c0df2;
case 0x0c0c0df4u: goto P_0c0c0df4;
case 0x0c0c0df6u: goto P_0c0c0df6;
case 0x0c0c0df8u: goto P_0c0c0df8;
case 0x0c0c0dfau: goto P_0c0c0dfa;
case 0x0c0c0dfcu: goto P_0c0c0dfc;
case 0x0c0c0dfeu: goto P_0c0c0dfe;
case 0x0c0c0e00u: goto P_0c0c0e00;
case 0x0c0c0e02u: goto P_0c0c0e02;
case 0x0c0c0e04u: goto P_0c0c0e04;
case 0x0c0c0e06u: goto P_0c0c0e06;
case 0x0c0c0e08u: goto P_0c0c0e08;
case 0x0c0c0e0au: goto P_0c0c0e0a;
case 0x0c0c0e0cu: goto P_0c0c0e0c;
case 0x0c0c0e0eu: goto P_0c0c0e0e;
case 0x0c0c0e10u: goto P_0c0c0e10;
case 0x0c0c0e12u: goto P_0c0c0e12;
case 0x0c0c0e14u: goto P_0c0c0e14;
case 0x0c0c0e16u: goto P_0c0c0e16;
case 0x0c0c0e18u: goto P_0c0c0e18;
case 0x0c0c0e1au: goto P_0c0c0e1a;
case 0x0c0c0e1cu: goto P_0c0c0e1c;
case 0x0c0c0e1eu: goto P_0c0c0e1e;
case 0x0c0c0e20u: goto P_0c0c0e20;
case 0x0c0c0e22u: goto P_0c0c0e22;
case 0x0c0c0e24u: goto P_0c0c0e24;
case 0x0c0c0e26u: goto P_0c0c0e26;
case 0x0c0c0e28u: goto P_0c0c0e28;
case 0x0c0c0e2au: goto P_0c0c0e2a;
case 0x0c0c0e2cu: goto P_0c0c0e2c;
case 0x0c0c0e2eu: goto P_0c0c0e2e;
case 0x0c0c0e30u: goto P_0c0c0e30;
case 0x0c0c0e32u: goto P_0c0c0e32;
case 0x0c0c0e34u: goto P_0c0c0e34;
case 0x0c0c0e36u: goto P_0c0c0e36;
case 0x0c0c0e38u: goto P_0c0c0e38;
case 0x0c0c0e3au: goto P_0c0c0e3a;
case 0x0c0c0e3cu: goto P_0c0c0e3c;
case 0x0c0c0e3eu: goto P_0c0c0e3e;
case 0x0c0c0e54u: goto P_0c0c0e54;
case 0x0c0c0e56u: goto P_0c0c0e56;
case 0x0c0c0e58u: goto P_0c0c0e58;
case 0x0c0c0e5au: goto P_0c0c0e5a;
case 0x0c0c0e5cu: goto P_0c0c0e5c;
case 0x0c0c0e5eu: goto P_0c0c0e5e;
case 0x0c0c0e60u: goto P_0c0c0e60;
case 0x0c0c0e62u: goto P_0c0c0e62;
case 0x0c0c0e64u: goto P_0c0c0e64;
case 0x0c0c0e66u: goto P_0c0c0e66;
case 0x0c0c0e68u: goto P_0c0c0e68;
case 0x0c0c0e6au: goto P_0c0c0e6a;
case 0x0c0c0e6cu: goto P_0c0c0e6c;
case 0x0c0c0e6eu: goto P_0c0c0e6e;
case 0x0c0c0e70u: goto P_0c0c0e70;
case 0x0c0c0e72u: goto P_0c0c0e72;
case 0x0c0c0e74u: goto P_0c0c0e74;
case 0x0c0c0e76u: goto P_0c0c0e76;
case 0x0c0c0e78u: goto P_0c0c0e78;
case 0x0c0c0e7au: goto P_0c0c0e7a;
case 0x0c0c0e7cu: goto P_0c0c0e7c;
case 0x0c0c0e7eu: goto P_0c0c0e7e;
case 0x0c0c0e80u: goto P_0c0c0e80;
case 0x0c0c0e82u: goto P_0c0c0e82;
case 0x0c0c0e84u: goto P_0c0c0e84;
case 0x0c0c0e86u: goto P_0c0c0e86;
case 0x0c0c0e88u: goto P_0c0c0e88;
case 0x0c0c0e8au: goto P_0c0c0e8a;
case 0x0c0c0e8cu: goto P_0c0c0e8c;
case 0x0c0c0e8eu: goto P_0c0c0e8e;
case 0x0c0c0e90u: goto P_0c0c0e90;
case 0x0c0c0e92u: goto P_0c0c0e92;
case 0x0c0c0e94u: goto P_0c0c0e94;
case 0x0c0c0e96u: goto P_0c0c0e96;
case 0x0c0c0e98u: goto P_0c0c0e98;
case 0x0c0c0e9au: goto P_0c0c0e9a;
case 0x0c0c0e9cu: goto P_0c0c0e9c;
case 0x0c0c0e9eu: goto P_0c0c0e9e;
case 0x0c0c0ea0u: goto P_0c0c0ea0;
case 0x0c0c0ea2u: goto P_0c0c0ea2;
case 0x0c0c0ea4u: goto P_0c0c0ea4;
case 0x0c0c0ea6u: goto P_0c0c0ea6;
case 0x0c0c0ea8u: goto P_0c0c0ea8;
case 0x0c0c0eaau: goto P_0c0c0eaa;
case 0x0c0c0eacu: goto P_0c0c0eac;
case 0x0c0c0eaeu: goto P_0c0c0eae;
case 0x0c0c0eb0u: goto P_0c0c0eb0;
case 0x0c0c0eb2u: goto P_0c0c0eb2;
case 0x0c0c0eb4u: goto P_0c0c0eb4;
case 0x0c0c0eb6u: goto P_0c0c0eb6;
case 0x0c0c0eb8u: goto P_0c0c0eb8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c0bf4: /* original 2fe6, guest PC 0x0c0c0bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c0bf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0bf6;
P_0c0c0bf6: /* original 6e43, guest PC 0x0c0c0bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c0bf6u; return 0; }
r[14]=r[4];
goto P_0c0c0bf8;
P_0c0c0bf8: /* original 2fd6, guest PC 0x0c0c0bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c0bf8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0bfa;
P_0c0c0bfa: /* original 6d73, guest PC 0x0c0c0bfa */
if(!s->budget--) { s->failed_pc=0x0c0c0bfau; return 0; }
r[13]=r[7];
goto P_0c0c0bfc;
P_0c0c0bfc: /* original 2fc6, guest PC 0x0c0c0bfc */
if(!s->budget--) { s->failed_pc=0x0c0c0bfcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0bfe;
P_0c0c0bfe: /* original 2fb6, guest PC 0x0c0c0bfe */
if(!s->budget--) { s->failed_pc=0x0c0c0bfeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0c00;
P_0c0c0c00: /* original 2fa6, guest PC 0x0c0c0c00 */
if(!s->budget--) { s->failed_pc=0x0c0c0c00u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c0c02;
P_0c0c0c02: /* original d434, guest PC 0x0c0c0c02 */
if(!s->budget--) { s->failed_pc=0x0c0c0c02u; return 0; }
r[4]=read(ram,0x0c0c0cd4u,4);
goto P_0c0c0c04;
P_0c0c0c04: /* original 4f22, guest PC 0x0c0c0c04 */
if(!s->budget--) { s->failed_pc=0x0c0c0c04u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c0c06;
P_0c0c0c06: /* original d334, guest PC 0x0c0c0c06 */
if(!s->budget--) { s->failed_pc=0x0c0c0c06u; return 0; }
r[3]=read(ram,0x0c0c0cd8u,4);
goto P_0c0c0c08;
P_0c0c0c08: /* original 6742, guest PC 0x0c0c0c08 */
if(!s->budget--) { s->failed_pc=0x0c0c0c08u; return 0; }
tmp=read(ram,r[4],4);
r[7]=tmp;
goto P_0c0c0c0a;
P_0c0c0c0a: /* original 7fec, guest PC 0x0c0c0c0a */
if(!s->budget--) { s->failed_pc=0x0c0c0c0au; return 0; }
r[15]+=0xffffffecu;
goto P_0c0c0c0c;
P_0c0c0c0c: /* original 2738, guest PC 0x0c0c0c0c */
if(!s->budget--) { s->failed_pc=0x0c0c0c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0c0c0e;
P_0c0c0c0e: /* original 8b01, guest PC 0x0c0c0c0e */
if(!s->budget--) { s->failed_pc=0x0c0c0c0eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0c14; }
goto P_0c0c0c10;
P_0c0c0c10: /* original a14b, guest PC 0x0c0c0c10 */
if(!s->budget--) { s->failed_pc=0x0c0c0c10u; return 0; }
goto P_0c0c0eaa;
P_0c0c0c12: /* original 0009, guest PC 0x0c0c0c12 */
if(!s->budget--) { s->failed_pc=0x0c0c0c12u; return 0; }
goto P_0c0c0c14;
P_0c0c0c14: /* original 5241, guest PC 0x0c0c0c14 */
if(!s->budget--) { s->failed_pc=0x0c0c0c14u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c0c0c16;
P_0c0c0c16: /* original d331, guest PC 0x0c0c0c16 */
if(!s->budget--) { s->failed_pc=0x0c0c0c16u; return 0; }
r[3]=read(ram,0x0c0c0cdcu,4);
goto P_0c0c0c18;
P_0c0c0c18: /* original 2238, guest PC 0x0c0c0c18 */
if(!s->budget--) { s->failed_pc=0x0c0c0c18u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0c1a;
P_0c0c0c1a: /* original 8b01, guest PC 0x0c0c0c1a */
if(!s->budget--) { s->failed_pc=0x0c0c0c1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0c20; }
goto P_0c0c0c1c;
P_0c0c0c1c: /* original a145, guest PC 0x0c0c0c1c */
if(!s->budget--) { s->failed_pc=0x0c0c0c1cu; return 0; }
goto P_0c0c0eaa;
P_0c0c0c1e: /* original 0009, guest PC 0x0c0c0c1e */
if(!s->budget--) { s->failed_pc=0x0c0c0c1eu; return 0; }
goto P_0c0c0c20;
P_0c0c0c20: /* original 53d3, guest PC 0x0c0c0c20 */
if(!s->budget--) { s->failed_pc=0x0c0c0c20u; return 0; }
r[3]=read(ram,r[13]+12,4);
goto P_0c0c0c22;
P_0c0c0c22: /* original 9b54, guest PC 0x0c0c0c22 */
if(!s->budget--) { s->failed_pc=0x0c0c0c22u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0cceu,2);
goto P_0c0c0c24;
P_0c0c0c24: /* original 23b8, guest PC 0x0c0c0c24 */
if(!s->budget--) { s->failed_pc=0x0c0c0c24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c0c0c26;
P_0c0c0c26: /* original 8d02, guest PC 0x0c0c0c26 */
if(!s->budget--) { s->failed_pc=0x0c0c0c26u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c0c0c2e; }
goto P_0c0c0c2a;
P_0c0c0c28: /* original ec00, guest PC 0x0c0c0c28 */
if(!s->budget--) { s->failed_pc=0x0c0c0c28u; return 0; }
r[12]=0x00000000u;
goto P_0c0c0c2a;
P_0c0c0c2a: /* original a12e, guest PC 0x0c0c0c2a */
if(!s->budget--) { s->failed_pc=0x0c0c0c2au; return 0; }
goto P_0c0c0e8a;
P_0c0c0c2c: /* original 0009, guest PC 0x0c0c0c2c */
if(!s->budget--) { s->failed_pc=0x0c0c0c2cu; return 0; }
goto P_0c0c0c2e;
P_0c0c0c2e: /* original d32d, guest PC 0x0c0c0c2e */
if(!s->budget--) { s->failed_pc=0x0c0c0c2eu; return 0; }
r[3]=read(ram,0x0c0c0ce4u,4);
goto P_0c0c0c30;
P_0c0c0c30: /* original 52d3, guest PC 0x0c0c0c30 */
if(!s->budget--) { s->failed_pc=0x0c0c0c30u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0c0c32;
P_0c0c0c32: /* original da2b, guest PC 0x0c0c0c32 */
if(!s->budget--) { s->failed_pc=0x0c0c0c32u; return 0; }
r[10]=read(ram,0x0c0c0ce0u,4);
goto P_0c0c0c34;
P_0c0c0c34: /* original 944c, guest PC 0x0c0c0c34 */
if(!s->budget--) { s->failed_pc=0x0c0c0c34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0cd0u,2);
goto P_0c0c0c36;
P_0c0c0c36: /* original 2238, guest PC 0x0c0c0c36 */
if(!s->budget--) { s->failed_pc=0x0c0c0c36u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c0c38;
P_0c0c0c38: /* original 8d02, guest PC 0x0c0c0c38 */
if(!s->budget--) { s->failed_pc=0x0c0c0c38u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0c0c40; }
goto P_0c0c0c3c;
P_0c0c0c3a: /* original e701, guest PC 0x0c0c0c3a */
if(!s->budget--) { s->failed_pc=0x0c0c0c3au; return 0; }
r[7]=0x00000001u;
goto P_0c0c0c3c;
P_0c0c0c3c: /* original a10a, guest PC 0x0c0c0c3c */
if(!s->budget--) { s->failed_pc=0x0c0c0c3cu; return 0; }
goto P_0c0c0e54;
P_0c0c0c3e: /* original 0009, guest PC 0x0c0c0c3e */
if(!s->budget--) { s->failed_pc=0x0c0c0c3eu; return 0; }
goto P_0c0c0c40;
P_0c0c0c40: /* original 51d3, guest PC 0x0c0c0c40 */
if(!s->budget--) { s->failed_pc=0x0c0c0c40u; return 0; }
r[1]=read(ram,r[13]+12,4);
goto P_0c0c0c42;
P_0c0c0c42: /* original 21a8, guest PC 0x0c0c0c42 */
if(!s->budget--) { s->failed_pc=0x0c0c0c42u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c0c0c44;
P_0c0c0c44: /* original 8901, guest PC 0x0c0c0c44 */
if(!s->budget--) { s->failed_pc=0x0c0c0c44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0c4a; }
goto P_0c0c0c46;
P_0c0c0c46: /* original a0f8, guest PC 0x0c0c0c46 */
if(!s->budget--) { s->failed_pc=0x0c0c0c46u; return 0; }
goto P_0c0c0e3a;
P_0c0c0c48: /* original 0009, guest PC 0x0c0c0c48 */
if(!s->budget--) { s->failed_pc=0x0c0c0c48u; return 0; }
goto P_0c0c0c4a;
P_0c0c0c4a: /* original 50d3, guest PC 0x0c0c0c4a */
if(!s->budget--) { s->failed_pc=0x0c0c0c4au; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c0c0c4c;
P_0c0c0c4c: /* original c816, guest PC 0x0c0c0c4c */
if(!s->budget--) { s->failed_pc=0x0c0c0c4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&22u)==0)!=0);
goto P_0c0c0c4e;
P_0c0c0c4e: /* original 8b01, guest PC 0x0c0c0c4e */
if(!s->budget--) { s->failed_pc=0x0c0c0c4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0c54; }
goto P_0c0c0c50;
P_0c0c0c50: /* original a12b, guest PC 0x0c0c0c50 */
if(!s->budget--) { s->failed_pc=0x0c0c0c50u; return 0; }
goto P_0c0c0eaa;
P_0c0c0c52: /* original 0009, guest PC 0x0c0c0c52 */
if(!s->budget--) { s->failed_pc=0x0c0c0c52u; return 0; }
goto P_0c0c0c54;
P_0c0c0c54: /* original 53d7, guest PC 0x0c0c0c54 */
if(!s->budget--) { s->failed_pc=0x0c0c0c54u; return 0; }
r[3]=read(ram,r[13]+28,4);
goto P_0c0c0c56;
P_0c0c0c56: /* original 923c, guest PC 0x0c0c0c56 */
if(!s->budget--) { s->failed_pc=0x0c0c0c56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0cd2u,2);
goto P_0c0c0c58;
P_0c0c0c58: /* original 3320, guest PC 0x0c0c0c58 */
if(!s->budget--) { s->failed_pc=0x0c0c0c58u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c0c5a;
P_0c0c0c5a: /* original 8b01, guest PC 0x0c0c0c5a */
if(!s->budget--) { s->failed_pc=0x0c0c0c5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0c60; }
goto P_0c0c0c5c;
P_0c0c0c5c: /* original a0e2, guest PC 0x0c0c0c5c */
if(!s->budget--) { s->failed_pc=0x0c0c0c5cu; return 0; }
goto P_0c0c0e24;
P_0c0c0c5e: /* original 0009, guest PC 0x0c0c0c5e */
if(!s->budget--) { s->failed_pc=0x0c0c0c5eu; return 0; }
goto P_0c0c0c60;
P_0c0c0c60: /* original 50d3, guest PC 0x0c0c0c60 */
if(!s->budget--) { s->failed_pc=0x0c0c0c60u; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c0c0c62;
P_0c0c0c62: /* original c814, guest PC 0x0c0c0c62 */
if(!s->budget--) { s->failed_pc=0x0c0c0c62u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&20u)==0)!=0);
goto P_0c0c0c64;
P_0c0c0c64: /* original 8b40, guest PC 0x0c0c0c64 */
if(!s->budget--) { s->failed_pc=0x0c0c0c64u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0ce8; }
goto P_0c0c0c66;
P_0c0c0c66: /* original 55d5, guest PC 0x0c0c0c66 */
if(!s->budget--) { s->failed_pc=0x0c0c0c66u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0c0c68;
P_0c0c0c68: /* original 63e3, guest PC 0x0c0c0c68 */
if(!s->budget--) { s->failed_pc=0x0c0c0c68u; return 0; }
r[3]=r[14];
goto P_0c0c0c6a;
P_0c0c0c6a: /* original 732c, guest PC 0x0c0c0c6a */
if(!s->budget--) { s->failed_pc=0x0c0c0c6au; return 0; }
r[3]+=0x0000002cu;
goto P_0c0c0c6c;
P_0c0c0c6c: /* original 4508, guest PC 0x0c0c0c6c */
if(!s->budget--) { s->failed_pc=0x0c0c0c6cu; return 0; }
r[5]<<=2;
goto P_0c0c0c6e;
P_0c0c0c6e: /* original 353c, guest PC 0x0c0c0c6e */
if(!s->budget--) { s->failed_pc=0x0c0c0c6eu; return 0; }
r[5]+=r[3];
goto P_0c0c0c70;
P_0c0c0c70: /* original 6552, guest PC 0x0c0c0c70 */
if(!s->budget--) { s->failed_pc=0x0c0c0c70u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0c0c72;
P_0c0c0c72: /* original 2558, guest PC 0x0c0c0c72 */
if(!s->budget--) { s->failed_pc=0x0c0c0c72u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c0c74;
P_0c0c0c74: /* original 8910, guest PC 0x0c0c0c74 */
if(!s->budget--) { s->failed_pc=0x0c0c0c74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0c98; }
goto P_0c0c0c76;
P_0c0c0c76: /* original 52da, guest PC 0x0c0c0c76 */
if(!s->budget--) { s->failed_pc=0x0c0c0c76u; return 0; }
r[2]=read(ram,r[13]+40,4);
goto P_0c0c0c78;
P_0c0c0c78: /* original 2a28, guest PC 0x0c0c0c78 */
if(!s->budget--) { s->failed_pc=0x0c0c0c78u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0c0c7a;
P_0c0c0c7a: /* original 8d01, guest PC 0x0c0c0c7a */
if(!s->budget--) { s->failed_pc=0x0c0c0c7au; return 0; }
cond=r[17]&1u;
r[0]=0x00000061u;
if(cond) { goto P_0c0c0c80; }
goto P_0c0c0c7e;
P_0c0c0c7c: /* original e061, guest PC 0x0c0c0c7c */
if(!s->budget--) { s->failed_pc=0x0c0c0c7cu; return 0; }
r[0]=0x00000061u;
goto P_0c0c0c7e;
P_0c0c0c7e: /* original 64b3, guest PC 0x0c0c0c7e */
if(!s->budget--) { s->failed_pc=0x0c0c0c7eu; return 0; }
r[4]=r[11];
goto P_0c0c0c80;
P_0c0c0c80: /* original 056c, guest PC 0x0c0c0c80 */
if(!s->budget--) { s->failed_pc=0x0c0c0c80u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c0c82;
P_0c0c0c82: /* original e31f, guest PC 0x0c0c0c82 */
if(!s->budget--) { s->failed_pc=0x0c0c0c82u; return 0; }
r[3]=0x0000001fu;
goto P_0c0c0c84;
P_0c0c0c84: /* original 52d5, guest PC 0x0c0c0c84 */
if(!s->budget--) { s->failed_pc=0x0c0c0c84u; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0c0c86;
P_0c0c0c86: /* original 655c, guest PC 0x0c0c0c86 */
if(!s->budget--) { s->failed_pc=0x0c0c0c86u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c0c88;
P_0c0c0c88: /* original 3358, guest PC 0x0c0c0c88 */
if(!s->budget--) { s->failed_pc=0x0c0c0c88u; return 0; }
r[3]-=r[5];
goto P_0c0c0c8a;
P_0c0c0c8a: /* original 473c, guest PC 0x0c0c0c8a */
if(!s->budget--) { s->failed_pc=0x0c0c0c8au; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[7]>>((-r[3])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[3]&31u);
goto P_0c0c0c8c;
P_0c0c0c8c: /* original 63e3, guest PC 0x0c0c0c8c */
if(!s->budget--) { s->failed_pc=0x0c0c0c8cu; return 0; }
r[3]=r[14];
goto P_0c0c0c8e;
P_0c0c0c8e: /* original 732c, guest PC 0x0c0c0c8e */
if(!s->budget--) { s->failed_pc=0x0c0c0c8eu; return 0; }
r[3]+=0x0000002cu;
goto P_0c0c0c90;
P_0c0c0c90: /* original 4208, guest PC 0x0c0c0c90 */
if(!s->budget--) { s->failed_pc=0x0c0c0c90u; return 0; }
r[2]<<=2;
goto P_0c0c0c92;
P_0c0c0c92: /* original 323c, guest PC 0x0c0c0c92 */
if(!s->budget--) { s->failed_pc=0x0c0c0c92u; return 0; }
r[2]+=r[3];
goto P_0c0c0c94;
P_0c0c0c94: /* original 247b, guest PC 0x0c0c0c94 */
if(!s->budget--) { s->failed_pc=0x0c0c0c94u; return 0; }
r[4]|=r[7];
goto P_0c0c0c96;
P_0c0c0c96: /* original 2242, guest PC 0x0c0c0c96 */
if(!s->budget--) { s->failed_pc=0x0c0c0c96u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c0c0c98;
P_0c0c0c98: /* original 53d6, guest PC 0x0c0c0c98 */
if(!s->budget--) { s->failed_pc=0x0c0c0c98u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c0c9a;
P_0c0c0c9a: /* original e044, guest PC 0x0c0c0c9a */
if(!s->budget--) { s->failed_pc=0x0c0c0c9au; return 0; }
r[0]=0x00000044u;
goto P_0c0c0c9c;
P_0c0c0c9c: /* original 04ed, guest PC 0x0c0c0c9c */
if(!s->budget--) { s->failed_pc=0x0c0c0c9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c0c9e;
P_0c0c0c9e: /* original 0e35, guest PC 0x0c0c0c9e */
if(!s->budget--) { s->failed_pc=0x0c0c0c9eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c0ca0;
P_0c0c0ca0: /* original e048, guest PC 0x0c0c0ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ca0u; return 0; }
r[0]=0x00000048u;
goto P_0c0c0ca2;
P_0c0c0ca2: /* original 52d6, guest PC 0x0c0c0ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ca2u; return 0; }
r[2]=read(ram,r[13]+24,4);
goto P_0c0c0ca4;
P_0c0c0ca4: /* original 0e25, guest PC 0x0c0c0ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ca4u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0c0ca6;
P_0c0c0ca6: /* original 53d5, guest PC 0x0c0c0ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ca6u; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0c0ca8;
P_0c0c0ca8: /* original 2338, guest PC 0x0c0c0ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c0caa;
P_0c0c0caa: /* original 8b01, guest PC 0x0c0c0caa */
if(!s->budget--) { s->failed_pc=0x0c0c0caau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0cb0; }
goto P_0c0c0cac;
P_0c0c0cac: /* original a0fd, guest PC 0x0c0c0cac */
if(!s->budget--) { s->failed_pc=0x0c0c0cacu; return 0; }
goto P_0c0c0eaa;
P_0c0c0cae: /* original 0009, guest PC 0x0c0c0cae */
if(!s->budget--) { s->failed_pc=0x0c0c0caeu; return 0; }
goto P_0c0c0cb0;
P_0c0c0cb0: /* original 53d6, guest PC 0x0c0c0cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c0cb0u; return 0; }
r[3]=read(ram,r[13]+24,4);
goto P_0c0c0cb2;
P_0c0c0cb2: /* original 3343, guest PC 0x0c0c0cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c0cb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[4])!=0);
goto P_0c0c0cb4;
P_0c0c0cb4: /* original 8901, guest PC 0x0c0c0cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c0cb4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0cba; }
goto P_0c0c0cb6;
P_0c0c0cb6: /* original a0e8, guest PC 0x0c0c0cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c0cb6u; return 0; }
goto P_0c0c0e8a;
P_0c0c0cb8: /* original 0009, guest PC 0x0c0c0cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c0cb8u; return 0; }
goto P_0c0c0cba;
P_0c0c0cba: /* original 53d5, guest PC 0x0c0c0cba */
if(!s->budget--) { s->failed_pc=0x0c0c0cbau; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0c0cbc;
P_0c0c0cbc: /* original 65e3, guest PC 0x0c0c0cbc */
if(!s->budget--) { s->failed_pc=0x0c0c0cbcu; return 0; }
r[5]=r[14];
goto P_0c0c0cbe;
P_0c0c0cbe: /* original 52d6, guest PC 0x0c0c0cbe */
if(!s->budget--) { s->failed_pc=0x0c0c0cbeu; return 0; }
r[2]=read(ram,r[13]+24,4);
goto P_0c0c0cc0;
P_0c0c0cc0: /* original 7520, guest PC 0x0c0c0cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c0cc0u; return 0; }
r[5]+=0x00000020u;
goto P_0c0c0cc2;
P_0c0c0cc2: /* original 4300, guest PC 0x0c0c0cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c0cc2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c0cc4;
P_0c0c0cc4: /* original 3248, guest PC 0x0c0c0cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c0cc4u; return 0; }
r[2]-=r[4];
goto P_0c0c0cc6;
P_0c0c0cc6: /* original 353c, guest PC 0x0c0c0cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c0cc6u; return 0; }
r[5]+=r[3];
goto P_0c0c0cc8;
P_0c0c0cc8: /* original 6423, guest PC 0x0c0c0cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c0cc8u; return 0; }
r[4]=r[2];
goto P_0c0c0cca;
P_0c0c0cca: /* original a0ee, guest PC 0x0c0c0cca */
if(!s->budget--) { s->failed_pc=0x0c0c0ccau; return 0; }
write(ram,r[5],r[4],2);
goto P_0c0c0eaa;
P_0c0c0ccc: /* original 2541, guest PC 0x0c0c0ccc */
if(!s->budget--) { s->failed_pc=0x0c0c0cccu; return 0; }
write(ram,r[5],r[4],2);
if(!vf3_matrix_family(0x0c0c0cceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0cceu; return 0; } return 1;
P_0c0c0ce8: /* original 62e3, guest PC 0x0c0c0ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ce8u; return 0; }
r[2]=r[14];
goto P_0c0c0cea;
P_0c0c0cea: /* original 53d5, guest PC 0x0c0c0cea */
if(!s->budget--) { s->failed_pc=0x0c0c0ceau; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0c0cec;
P_0c0c0cec: /* original 7210, guest PC 0x0c0c0cec */
if(!s->budget--) { s->failed_pc=0x0c0c0cecu; return 0; }
r[2]+=0x00000010u;
goto P_0c0c0cee;
P_0c0c0cee: /* original 51d7, guest PC 0x0c0c0cee */
if(!s->budget--) { s->failed_pc=0x0c0c0ceeu; return 0; }
r[1]=read(ram,r[13]+28,4);
goto P_0c0c0cf0;
P_0c0c0cf0: /* original 323c, guest PC 0x0c0c0cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c0cf0u; return 0; }
r[2]+=r[3];
goto P_0c0c0cf2;
P_0c0c0cf2: /* original 2210, guest PC 0x0c0c0cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c0cf2u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c0c0cf4;
P_0c0c0cf4: /* original 93a4, guest PC 0x0c0c0cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c0cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e40u,2);
goto P_0c0c0cf6;
P_0c0c0cf6: /* original 90a4, guest PC 0x0c0c0cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c0cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e42u,2);
goto P_0c0c0cf8;
P_0c0c0cf8: /* original 0534, guest PC 0x0c0c0cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c0cf8u; return 0; }
write(ram,r[5]+r[0],r[3],1);
goto P_0c0c0cfa;
P_0c0c0cfa: /* original e046, guest PC 0x0c0c0cfa */
if(!s->budget--) { s->failed_pc=0x0c0c0cfau; return 0; }
r[0]=0x00000046u;
goto P_0c0c0cfc;
P_0c0c0cfc: /* original 55d6, guest PC 0x0c0c0cfc */
if(!s->budget--) { s->failed_pc=0x0c0c0cfcu; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0c0cfe;
P_0c0c0cfe: /* original 7501, guest PC 0x0c0c0cfe */
if(!s->budget--) { s->failed_pc=0x0c0c0cfeu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c0d00;
P_0c0c0d00: /* original 0e55, guest PC 0x0c0c0d00 */
if(!s->budget--) { s->failed_pc=0x0c0c0d00u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0c0d02;
P_0c0c0d02: /* original e040, guest PC 0x0c0c0d02 */
if(!s->budget--) { s->failed_pc=0x0c0c0d02u; return 0; }
r[0]=0x00000040u;
goto P_0c0c0d04;
P_0c0c0d04: /* original 939e, guest PC 0x0c0c0d04 */
if(!s->budget--) { s->failed_pc=0x0c0c0d04u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e44u,2);
goto P_0c0c0d06;
P_0c0c0d06: /* original 65c3, guest PC 0x0c0c0d06 */
if(!s->budget--) { s->failed_pc=0x0c0c0d06u; return 0; }
r[5]=r[12];
goto P_0c0c0d08;
P_0c0c0d08: /* original 52d3, guest PC 0x0c0c0d08 */
if(!s->budget--) { s->failed_pc=0x0c0c0d08u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0c0d0a;
P_0c0c0d0a: /* original 223b, guest PC 0x0c0c0d0a */
if(!s->budget--) { s->failed_pc=0x0c0c0d0au; return 0; }
r[2]|=r[3];
goto P_0c0c0d0c;
P_0c0c0d0c: /* original 1d23, guest PC 0x0c0c0d0c */
if(!s->budget--) { s->failed_pc=0x0c0c0d0cu; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0c0d0e;
P_0c0c0d0e: /* original e20f, guest PC 0x0c0c0d0e */
if(!s->budget--) { s->failed_pc=0x0c0c0d0eu; return 0; }
r[2]=0x0000000fu;
goto P_0c0c0d10;
P_0c0c0d10: /* original 06ee, guest PC 0x0c0c0d10 */
if(!s->budget--) { s->failed_pc=0x0c0c0d10u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0c0d12;
P_0c0c0d12: /* original e3cf, guest PC 0x0c0c0d12 */
if(!s->budget--) { s->failed_pc=0x0c0c0d12u; return 0; }
r[3]=0xffffffcfu;
goto P_0c0c0d14;
P_0c0c0d14: /* original 0ec6, guest PC 0x0c0c0d14 */
if(!s->budget--) { s->failed_pc=0x0c0c0d14u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0c0d16;
P_0c0c0d16: /* original 2269, guest PC 0x0c0c0d16 */
if(!s->budget--) { s->failed_pc=0x0c0c0d16u; return 0; }
r[2]&=r[6];
goto P_0c0c0d18;
P_0c0c0d18: /* original 9195, guest PC 0x0c0c0d18 */
if(!s->budget--) { s->failed_pc=0x0c0c0d18u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e46u,2);
goto P_0c0c0d1a;
P_0c0c0d1a: /* original 252b, guest PC 0x0c0c0d1a */
if(!s->budget--) { s->failed_pc=0x0c0c0d1au; return 0; }
r[5]|=r[2];
goto P_0c0c0d1c;
P_0c0c0d1c: /* original e260, guest PC 0x0c0c0d1c */
if(!s->budget--) { s->failed_pc=0x0c0c0d1cu; return 0; }
r[2]=0x00000060u;
goto P_0c0c0d1e;
P_0c0c0d1e: /* original 2269, guest PC 0x0c0c0d1e */
if(!s->budget--) { s->failed_pc=0x0c0c0d1eu; return 0; }
r[2]&=r[6];
goto P_0c0c0d20;
P_0c0c0d20: /* original 4221, guest PC 0x0c0c0d20 */
if(!s->budget--) { s->failed_pc=0x0c0c0d20u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c0d22;
P_0c0c0d22: /* original 2539, guest PC 0x0c0c0d22 */
if(!s->budget--) { s->failed_pc=0x0c0c0d22u; return 0; }
r[5]&=r[3];
goto P_0c0c0d24;
P_0c0c0d24: /* original 252b, guest PC 0x0c0c0d24 */
if(!s->budget--) { s->failed_pc=0x0c0c0d24u; return 0; }
r[5]|=r[2];
goto P_0c0c0d26;
P_0c0c0d26: /* original 2519, guest PC 0x0c0c0d26 */
if(!s->budget--) { s->failed_pc=0x0c0c0d26u; return 0; }
r[5]&=r[1];
goto P_0c0c0d28;
P_0c0c0d28: /* original 928e, guest PC 0x0c0c0d28 */
if(!s->budget--) { s->failed_pc=0x0c0c0d28u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e48u,2);
goto P_0c0c0d2a;
P_0c0c0d2a: /* original 938e, guest PC 0x0c0c0d2a */
if(!s->budget--) { s->failed_pc=0x0c0c0d2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e4au,2);
goto P_0c0c0d2c;
P_0c0c0d2c: /* original 2269, guest PC 0x0c0c0d2c */
if(!s->budget--) { s->failed_pc=0x0c0c0d2cu; return 0; }
r[2]&=r[6];
goto P_0c0c0d2e;
P_0c0c0d2e: /* original 4221, guest PC 0x0c0c0d2e */
if(!s->budget--) { s->failed_pc=0x0c0c0d2eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c0d30;
P_0c0c0d30: /* original 4221, guest PC 0x0c0c0d30 */
if(!s->budget--) { s->failed_pc=0x0c0c0d30u; return 0; }
r[17]=(r[17]&~1u)|((r[2]&1)!=0);
r[2]=(uint32_t)((int32_t)r[2]>>1);
goto P_0c0c0d32;
P_0c0c0d32: /* original 2648, guest PC 0x0c0c0d32 */
if(!s->budget--) { s->failed_pc=0x0c0c0d32u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[4])==0)!=0);
goto P_0c0c0d34;
P_0c0c0d34: /* original 252b, guest PC 0x0c0c0d34 */
if(!s->budget--) { s->failed_pc=0x0c0c0d34u; return 0; }
r[5]|=r[2];
goto P_0c0c0d36;
P_0c0c0d36: /* original 8d02, guest PC 0x0c0c0d36 */
if(!s->budget--) { s->failed_pc=0x0c0c0d36u; return 0; }
cond=r[17]&1u;
r[5]&=r[3];
if(cond) { goto P_0c0c0d3e; }
goto P_0c0c0d3a;
P_0c0c0d38: /* original 2539, guest PC 0x0c0c0d38 */
if(!s->budget--) { s->failed_pc=0x0c0c0d38u; return 0; }
r[5]&=r[3];
goto P_0c0c0d3a;
P_0c0c0d3a: /* original 9087, guest PC 0x0c0c0d3a */
if(!s->budget--) { s->failed_pc=0x0c0c0d3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e4cu,2);
goto P_0c0c0d3c;
P_0c0c0d3c: /* original 250b, guest PC 0x0c0c0d3c */
if(!s->budget--) { s->failed_pc=0x0c0c0d3cu; return 0; }
r[5]|=r[0];
goto P_0c0c0d3e;
P_0c0c0d3e: /* original 53d5, guest PC 0x0c0c0d3e */
if(!s->budget--) { s->failed_pc=0x0c0c0d3eu; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0c0d40;
P_0c0c0d40: /* original 62e3, guest PC 0x0c0c0d40 */
if(!s->budget--) { s->failed_pc=0x0c0c0d40u; return 0; }
r[2]=r[14];
goto P_0c0c0d42;
P_0c0c0d42: /* original 7216, guest PC 0x0c0c0d42 */
if(!s->budget--) { s->failed_pc=0x0c0c0d42u; return 0; }
r[2]+=0x00000016u;
goto P_0c0c0d44;
P_0c0c0d44: /* original 4300, guest PC 0x0c0c0d44 */
if(!s->budget--) { s->failed_pc=0x0c0c0d44u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0c0d46;
P_0c0c0d46: /* original 332c, guest PC 0x0c0c0d46 */
if(!s->budget--) { s->failed_pc=0x0c0c0d46u; return 0; }
r[3]+=r[2];
goto P_0c0c0d48;
P_0c0c0d48: /* original 2351, guest PC 0x0c0c0d48 */
if(!s->budget--) { s->failed_pc=0x0c0c0d48u; return 0; }
write(ram,r[3],r[5],2);
goto P_0c0c0d4a;
P_0c0c0d4a: /* original 53d5, guest PC 0x0c0c0d4a */
if(!s->budget--) { s->failed_pc=0x0c0c0d4au; return 0; }
r[3]=read(ram,r[13]+20,4);
goto P_0c0c0d4c;
P_0c0c0d4c: /* original 3373, guest PC 0x0c0c0d4c */
if(!s->budget--) { s->failed_pc=0x0c0c0d4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[7])!=0);
goto P_0c0c0d4e;
P_0c0c0d4e: /* original 8b0b, guest PC 0x0c0c0d4e */
if(!s->budget--) { s->failed_pc=0x0c0c0d4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0d68; }
goto P_0c0c0d50;
P_0c0c0d50: /* original 50d3, guest PC 0x0c0c0d50 */
if(!s->budget--) { s->failed_pc=0x0c0c0d50u; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c0c0d52;
P_0c0c0d52: /* original 65d3, guest PC 0x0c0c0d52 */
if(!s->budget--) { s->failed_pc=0x0c0c0d52u; return 0; }
r[5]=r[13];
goto P_0c0c0d54;
P_0c0c0d54: /* original cb80, guest PC 0x0c0c0d54 */
if(!s->budget--) { s->failed_pc=0x0c0c0d54u; return 0; }
r[0]|=128u;
goto P_0c0c0d56;
P_0c0c0d56: /* original 1d03, guest PC 0x0c0c0d56 */
if(!s->budget--) { s->failed_pc=0x0c0c0d56u; return 0; }
write(ram,r[13]+12,r[0],4);
goto P_0c0c0d58;
P_0c0c0d58: /* original b0af, guest PC 0x0c0c0d58 */
if(!s->budget--) { s->failed_pc=0x0c0c0d58u; return 0; }
target=code_base|0x0c0c0ebau; r[16]=code_base|0x0c0c0d5cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0d5cu) { target=s->pc; goto dispatch; }
goto P_0c0c0d5c;
P_0c0c0d5a: /* original 64e3, guest PC 0x0c0c0d5a */
if(!s->budget--) { s->failed_pc=0x0c0c0d5au; return 0; }
r[4]=r[14];
goto P_0c0c0d5c;
P_0c0c0d5c: /* original 6403, guest PC 0x0c0c0d5c */
if(!s->budget--) { s->failed_pc=0x0c0c0d5cu; return 0; }
r[4]=r[0];
goto P_0c0c0d5e;
P_0c0c0d5e: /* original 2448, guest PC 0x0c0c0d5e */
if(!s->budget--) { s->failed_pc=0x0c0c0d5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c0d60;
P_0c0c0d60: /* original 8b02, guest PC 0x0c0c0d60 */
if(!s->budget--) { s->failed_pc=0x0c0c0d60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c0d68; }
goto P_0c0c0d62;
P_0c0c0d62: /* original 65d3, guest PC 0x0c0c0d62 */
if(!s->budget--) { s->failed_pc=0x0c0c0d62u; return 0; }
r[5]=r[13];
goto P_0c0c0d64;
P_0c0c0d64: /* original b0fc, guest PC 0x0c0c0d64 */
if(!s->budget--) { s->failed_pc=0x0c0c0d64u; return 0; }
target=code_base|0x0c0c0f60u; r[16]=code_base|0x0c0c0d68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c0d68u) { target=s->pc; goto dispatch; }
goto P_0c0c0d68;
P_0c0c0d66: /* original 64e3, guest PC 0x0c0c0d66 */
if(!s->budget--) { s->failed_pc=0x0c0c0d66u; return 0; }
r[4]=r[14];
goto P_0c0c0d68;
P_0c0c0d68: /* original 55d5, guest PC 0x0c0c0d68 */
if(!s->budget--) { s->failed_pc=0x0c0c0d68u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0c0d6a;
P_0c0c0d6a: /* original e404, guest PC 0x0c0c0d6a */
if(!s->budget--) { s->failed_pc=0x0c0c0d6au; return 0; }
r[4]=0x00000004u;
goto P_0c0c0d6c;
P_0c0c0d6c: /* original 6253, guest PC 0x0c0c0d6c */
if(!s->budget--) { s->failed_pc=0x0c0c0d6cu; return 0; }
r[2]=r[5];
goto P_0c0c0d6e;
P_0c0c0d6e: /* original 3543, guest PC 0x0c0c0d6e */
if(!s->budget--) { s->failed_pc=0x0c0c0d6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[4])!=0);
goto P_0c0c0d70;
P_0c0c0d70: /* original 7201, guest PC 0x0c0c0d70 */
if(!s->budget--) { s->failed_pc=0x0c0c0d70u; return 0; }
r[2]+=0x00000001u;
goto P_0c0c0d72;
P_0c0c0d72: /* original 8d02, guest PC 0x0c0c0d72 */
if(!s->budget--) { s->failed_pc=0x0c0c0d72u; return 0; }
cond=r[17]&1u;
write(ram,r[13]+20,r[2],4);
if(cond) { goto P_0c0c0d7a; }
goto P_0c0c0d76;
P_0c0c0d74: /* original 1d25, guest PC 0x0c0c0d74 */
if(!s->budget--) { s->failed_pc=0x0c0c0d74u; return 0; }
write(ram,r[13]+20,r[2],4);
goto P_0c0c0d76;
P_0c0c0d76: /* original a098, guest PC 0x0c0c0d76 */
if(!s->budget--) { s->failed_pc=0x0c0c0d76u; return 0; }
goto P_0c0c0eaa;
P_0c0c0d78: /* original 0009, guest PC 0x0c0c0d78 */
if(!s->budget--) { s->failed_pc=0x0c0c0d78u; return 0; }
goto P_0c0c0d7a;
P_0c0c0d7a: /* original 85eb, guest PC 0x0c0c0d7a */
if(!s->budget--) { s->failed_pc=0x0c0c0d7au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+22,2);
goto P_0c0c0d7c;
P_0c0c0d7c: /* original 9367, guest PC 0x0c0c0d7c */
if(!s->budget--) { s->failed_pc=0x0c0c0d7cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e4eu,2);
goto P_0c0c0d7e;
P_0c0c0d7e: /* original 6503, guest PC 0x0c0c0d7e */
if(!s->budget--) { s->failed_pc=0x0c0c0d7eu; return 0; }
r[5]=r[0];
goto P_0c0c0d80;
P_0c0c0d80: /* original 2538, guest PC 0x0c0c0d80 */
if(!s->budget--) { s->failed_pc=0x0c0c0d80u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c0d82;
P_0c0c0d82: /* original 8901, guest PC 0x0c0c0d82 */
if(!s->budget--) { s->failed_pc=0x0c0c0d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0d88; }
goto P_0c0c0d84;
P_0c0c0d84: /* original a081, guest PC 0x0c0c0d84 */
if(!s->budget--) { s->failed_pc=0x0c0c0d84u; return 0; }
goto P_0c0c0e8a;
P_0c0c0d86: /* original 0009, guest PC 0x0c0c0d86 */
if(!s->budget--) { s->failed_pc=0x0c0c0d86u; return 0; }
goto P_0c0c0d88;
P_0c0c0d88: /* original 1d45, guest PC 0x0c0c0d88 */
if(!s->budget--) { s->failed_pc=0x0c0c0d88u; return 0; }
write(ram,r[13]+20,r[4],4);
goto P_0c0c0d8a;
P_0c0c0d8a: /* original 64e3, guest PC 0x0c0c0d8a */
if(!s->budget--) { s->failed_pc=0x0c0c0d8au; return 0; }
r[4]=r[14];
goto P_0c0c0d8c;
P_0c0c0d8c: /* original 7410, guest PC 0x0c0c0d8c */
if(!s->budget--) { s->failed_pc=0x0c0c0d8cu; return 0; }
r[4]+=0x00000010u;
goto P_0c0c0d8e;
P_0c0c0d8e: /* original 65e3, guest PC 0x0c0c0d8e */
if(!s->budget--) { s->failed_pc=0x0c0c0d8eu; return 0; }
r[5]=r[14];
goto P_0c0c0d90;
P_0c0c0d90: /* original 8441, guest PC 0x0c0c0d90 */
if(!s->budget--) { s->failed_pc=0x0c0c0d90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0c0d92;
P_0c0c0d92: /* original 7516, guest PC 0x0c0c0d92 */
if(!s->budget--) { s->failed_pc=0x0c0c0d92u; return 0; }
r[5]+=0x00000016u;
goto P_0c0c0d94;
P_0c0c0d94: /* original 6603, guest PC 0x0c0c0d94 */
if(!s->budget--) { s->failed_pc=0x0c0c0d94u; return 0; }
r[6]=r[0];
goto P_0c0c0d96;
P_0c0c0d96: /* original 8442, guest PC 0x0c0c0d96 */
if(!s->budget--) { s->failed_pc=0x0c0c0d96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0c0d98;
P_0c0c0d98: /* original 1f03, guest PC 0x0c0c0d98 */
if(!s->budget--) { s->failed_pc=0x0c0c0d98u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c0c0d9a;
P_0c0c0d9a: /* original 8443, guest PC 0x0c0c0d9a */
if(!s->budget--) { s->failed_pc=0x0c0c0d9au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0c0d9c;
P_0c0c0d9c: /* original 1f04, guest PC 0x0c0c0d9c */
if(!s->budget--) { s->failed_pc=0x0c0c0d9cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c0c0d9e;
P_0c0c0d9e: /* original 8444, guest PC 0x0c0c0d9e */
if(!s->budget--) { s->failed_pc=0x0c0c0d9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0c0da0;
P_0c0c0da0: /* original 1f01, guest PC 0x0c0c0da0 */
if(!s->budget--) { s->failed_pc=0x0c0c0da0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c0da2;
P_0c0c0da2: /* original 8551, guest PC 0x0c0c0da2 */
if(!s->budget--) { s->failed_pc=0x0c0c0da2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c0c0da4;
P_0c0c0da4: /* original 1f02, guest PC 0x0c0c0da4 */
if(!s->budget--) { s->failed_pc=0x0c0c0da4u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0c0da6;
P_0c0c0da6: /* original 8552, guest PC 0x0c0c0da6 */
if(!s->budget--) { s->failed_pc=0x0c0c0da6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+4,2);
goto P_0c0c0da8;
P_0c0c0da8: /* original 2f02, guest PC 0x0c0c0da8 */
if(!s->budget--) { s->failed_pc=0x0c0c0da8u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0c0daa;
P_0c0c0daa: /* original 8553, guest PC 0x0c0c0daa */
if(!s->budget--) { s->failed_pc=0x0c0c0daau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+6,2);
goto P_0c0c0dac;
P_0c0c0dac: /* original 6703, guest PC 0x0c0c0dac */
if(!s->budget--) { s->failed_pc=0x0c0c0dacu; return 0; }
r[7]=r[0];
goto P_0c0c0dae;
P_0c0c0dae: /* original 8554, guest PC 0x0c0c0dae */
if(!s->budget--) { s->failed_pc=0x0c0c0daeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+8,2);
goto P_0c0c0db0;
P_0c0c0db0: /* original 2460, guest PC 0x0c0c0db0 */
if(!s->budget--) { s->failed_pc=0x0c0c0db0u; return 0; }
write(ram,r[4],r[6],1);
goto P_0c0c0db2;
P_0c0c0db2: /* original 53f3, guest PC 0x0c0c0db2 */
if(!s->budget--) { s->failed_pc=0x0c0c0db2u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0c0db4;
P_0c0c0db4: /* original 6503, guest PC 0x0c0c0db4 */
if(!s->budget--) { s->failed_pc=0x0c0c0db4u; return 0; }
r[5]=r[0];
goto P_0c0c0db6;
P_0c0c0db6: /* original e011, guest PC 0x0c0c0db6 */
if(!s->budget--) { s->failed_pc=0x0c0c0db6u; return 0; }
r[0]=0x00000011u;
goto P_0c0c0db8;
P_0c0c0db8: /* original 0e34, guest PC 0x0c0c0db8 */
if(!s->budget--) { s->failed_pc=0x0c0c0db8u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c0dba;
P_0c0c0dba: /* original e012, guest PC 0x0c0c0dba */
if(!s->budget--) { s->failed_pc=0x0c0c0dbau; return 0; }
r[0]=0x00000012u;
goto P_0c0c0dbc;
P_0c0c0dbc: /* original 52f4, guest PC 0x0c0c0dbc */
if(!s->budget--) { s->failed_pc=0x0c0c0dbcu; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c0c0dbe;
P_0c0c0dbe: /* original 0e24, guest PC 0x0c0c0dbe */
if(!s->budget--) { s->failed_pc=0x0c0c0dbeu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c0dc0;
P_0c0c0dc0: /* original e013, guest PC 0x0c0c0dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c0dc0u; return 0; }
r[0]=0x00000013u;
goto P_0c0c0dc2;
P_0c0c0dc2: /* original 53f1, guest PC 0x0c0c0dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c0dc2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c0dc4;
P_0c0c0dc4: /* original 0e34, guest PC 0x0c0c0dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c0dc4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c0dc6;
P_0c0c0dc6: /* original 85f4, guest PC 0x0c0c0dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c0dc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c0c0dc8;
P_0c0c0dc8: /* original 81eb, guest PC 0x0c0c0dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c0dc8u; return 0; }
write(ram,r[14]+22,r[0],2);
goto P_0c0c0dca;
P_0c0c0dca: /* original 64e3, guest PC 0x0c0c0dca */
if(!s->budget--) { s->failed_pc=0x0c0c0dcau; return 0; }
r[4]=r[14];
goto P_0c0c0dcc;
P_0c0c0dcc: /* original 60f2, guest PC 0x0c0c0dcc */
if(!s->budget--) { s->failed_pc=0x0c0c0dccu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c0dce;
P_0c0c0dce: /* original 742c, guest PC 0x0c0c0dce */
if(!s->budget--) { s->failed_pc=0x0c0c0dceu; return 0; }
r[4]+=0x0000002cu;
goto P_0c0c0dd0;
P_0c0c0dd0: /* original 81ec, guest PC 0x0c0c0dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c0dd0u; return 0; }
write(ram,r[14]+24,r[0],2);
goto P_0c0c0dd2;
P_0c0c0dd2: /* original 6073, guest PC 0x0c0c0dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c0dd2u; return 0; }
r[0]=r[7];
goto P_0c0c0dd4;
P_0c0c0dd4: /* original 81ed, guest PC 0x0c0c0dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c0dd4u; return 0; }
write(ram,r[14]+26,r[0],2);
goto P_0c0c0dd6;
P_0c0c0dd6: /* original 6053, guest PC 0x0c0c0dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c0dd6u; return 0; }
r[0]=r[5];
goto P_0c0c0dd8;
P_0c0c0dd8: /* original 81ee, guest PC 0x0c0c0dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c0dd8u; return 0; }
write(ram,r[14]+28,r[0],2);
goto P_0c0c0dda;
P_0c0c0dda: /* original e024, guest PC 0x0c0c0dda */
if(!s->budget--) { s->failed_pc=0x0c0c0ddau; return 0; }
r[0]=0x00000024u;
goto P_0c0c0ddc;
P_0c0c0ddc: /* original 03ed, guest PC 0x0c0c0ddc */
if(!s->budget--) { s->failed_pc=0x0c0c0ddcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c0dde;
P_0c0c0dde: /* original e026, guest PC 0x0c0c0dde */
if(!s->budget--) { s->failed_pc=0x0c0c0ddeu; return 0; }
r[0]=0x00000026u;
goto P_0c0c0de0;
P_0c0c0de0: /* original 2f32, guest PC 0x0c0c0de0 */
if(!s->budget--) { s->failed_pc=0x0c0c0de0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c0de2;
P_0c0c0de2: /* original 02ed, guest PC 0x0c0c0de2 */
if(!s->budget--) { s->failed_pc=0x0c0c0de2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c0de4;
P_0c0c0de4: /* original e028, guest PC 0x0c0c0de4 */
if(!s->budget--) { s->failed_pc=0x0c0c0de4u; return 0; }
r[0]=0x00000028u;
goto P_0c0c0de6;
P_0c0c0de6: /* original 1f22, guest PC 0x0c0c0de6 */
if(!s->budget--) { s->failed_pc=0x0c0c0de6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0c0de8;
P_0c0c0de8: /* original 03ed, guest PC 0x0c0c0de8 */
if(!s->budget--) { s->failed_pc=0x0c0c0de8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c0dea;
P_0c0c0dea: /* original e022, guest PC 0x0c0c0dea */
if(!s->budget--) { s->failed_pc=0x0c0c0deau; return 0; }
r[0]=0x00000022u;
goto P_0c0c0dec;
P_0c0c0dec: /* original 1f31, guest PC 0x0c0c0dec */
if(!s->budget--) { s->failed_pc=0x0c0c0decu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c0dee;
P_0c0c0dee: /* original 63f2, guest PC 0x0c0c0dee */
if(!s->budget--) { s->failed_pc=0x0c0c0deeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c0df0;
P_0c0c0df0: /* original 5643, guest PC 0x0c0c0df0 */
if(!s->budget--) { s->failed_pc=0x0c0c0df0u; return 0; }
r[6]=read(ram,r[4]+12,4);
goto P_0c0c0df2;
P_0c0c0df2: /* original 5742, guest PC 0x0c0c0df2 */
if(!s->budget--) { s->failed_pc=0x0c0c0df2u; return 0; }
r[7]=read(ram,r[4]+8,4);
goto P_0c0c0df4;
P_0c0c0df4: /* original 5541, guest PC 0x0c0c0df4 */
if(!s->budget--) { s->failed_pc=0x0c0c0df4u; return 0; }
r[5]=read(ram,r[4]+4,4);
goto P_0c0c0df6;
P_0c0c0df6: /* original 5444, guest PC 0x0c0c0df6 */
if(!s->budget--) { s->failed_pc=0x0c0c0df6u; return 0; }
r[4]=read(ram,r[4]+16,4);
goto P_0c0c0df8;
P_0c0c0df8: /* original 0e35, guest PC 0x0c0c0df8 */
if(!s->budget--) { s->failed_pc=0x0c0c0df8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c0dfa;
P_0c0c0dfa: /* original e024, guest PC 0x0c0c0dfa */
if(!s->budget--) { s->failed_pc=0x0c0c0dfau; return 0; }
r[0]=0x00000024u;
goto P_0c0c0dfc;
P_0c0c0dfc: /* original 52f2, guest PC 0x0c0c0dfc */
if(!s->budget--) { s->failed_pc=0x0c0c0dfcu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c0dfe;
P_0c0c0dfe: /* original 0e25, guest PC 0x0c0c0dfe */
if(!s->budget--) { s->failed_pc=0x0c0c0dfeu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0c0e00;
P_0c0c0e00: /* original e026, guest PC 0x0c0c0e00 */
if(!s->budget--) { s->failed_pc=0x0c0c0e00u; return 0; }
r[0]=0x00000026u;
goto P_0c0c0e02;
P_0c0c0e02: /* original 53f1, guest PC 0x0c0c0e02 */
if(!s->budget--) { s->failed_pc=0x0c0c0e02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c0e04;
P_0c0c0e04: /* original 0e35, guest PC 0x0c0c0e04 */
if(!s->budget--) { s->failed_pc=0x0c0c0e04u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0c0e06;
P_0c0c0e06: /* original 1e5b, guest PC 0x0c0c0e06 */
if(!s->budget--) { s->failed_pc=0x0c0c0e06u; return 0; }
write(ram,r[14]+44,r[5],4);
goto P_0c0c0e08;
P_0c0c0e08: /* original e3ff, guest PC 0x0c0c0e08 */
if(!s->budget--) { s->failed_pc=0x0c0c0e08u; return 0; }
r[3]=0xffffffffu;
goto P_0c0c0e0a;
P_0c0c0e0a: /* original 1e7c, guest PC 0x0c0c0e0a */
if(!s->budget--) { s->failed_pc=0x0c0c0e0au; return 0; }
write(ram,r[14]+48,r[7],4);
goto P_0c0c0e0c;
P_0c0c0e0c: /* original e014, guest PC 0x0c0c0e0c */
if(!s->budget--) { s->failed_pc=0x0c0c0e0cu; return 0; }
r[0]=0x00000014u;
goto P_0c0c0e0e;
P_0c0c0e0e: /* original 1e6d, guest PC 0x0c0c0e0e */
if(!s->budget--) { s->failed_pc=0x0c0c0e0eu; return 0; }
write(ram,r[14]+52,r[6],4);
goto P_0c0c0e10;
P_0c0c0e10: /* original 1e4e, guest PC 0x0c0c0e10 */
if(!s->budget--) { s->failed_pc=0x0c0c0e10u; return 0; }
write(ram,r[14]+56,r[4],4);
goto P_0c0c0e12;
P_0c0c0e12: /* original 0e34, guest PC 0x0c0c0e12 */
if(!s->budget--) { s->failed_pc=0x0c0c0e12u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c0e14;
P_0c0c0e14: /* original 60c3, guest PC 0x0c0c0e14 */
if(!s->budget--) { s->failed_pc=0x0c0c0e14u; return 0; }
r[0]=r[12];
goto P_0c0c0e16;
P_0c0c0e16: /* original 81ef, guest PC 0x0c0c0e16 */
if(!s->budget--) { s->failed_pc=0x0c0c0e16u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0c0e18;
P_0c0c0e18: /* original e028, guest PC 0x0c0c0e18 */
if(!s->budget--) { s->failed_pc=0x0c0c0e18u; return 0; }
r[0]=0x00000028u;
goto P_0c0c0e1a;
P_0c0c0e1a: /* original 0ec5, guest PC 0x0c0c0e1a */
if(!s->budget--) { s->failed_pc=0x0c0c0e1au; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0c0e1c;
P_0c0c0e1c: /* original e02a, guest PC 0x0c0c0e1c */
if(!s->budget--) { s->failed_pc=0x0c0c0e1cu; return 0; }
r[0]=0x0000002au;
goto P_0c0c0e1e;
P_0c0c0e1e: /* original 0ec5, guest PC 0x0c0c0e1e */
if(!s->budget--) { s->failed_pc=0x0c0c0e1eu; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c0c0e20;
P_0c0c0e20: /* original a043, guest PC 0x0c0c0e20 */
if(!s->budget--) { s->failed_pc=0x0c0c0e20u; return 0; }
write(ram,r[14]+60,r[12],4);
goto P_0c0c0eaa;
P_0c0c0e22: /* original 1ecf, guest PC 0x0c0c0e22 */
if(!s->budget--) { s->failed_pc=0x0c0c0e22u; return 0; }
write(ram,r[14]+60,r[12],4);
goto P_0c0c0e24;
P_0c0c0e24: /* original 50d3, guest PC 0x0c0c0e24 */
if(!s->budget--) { s->failed_pc=0x0c0c0e24u; return 0; }
r[0]=read(ram,r[13]+12,4);
goto P_0c0c0e26;
P_0c0c0e26: /* original c802, guest PC 0x0c0c0e26 */
if(!s->budget--) { s->failed_pc=0x0c0c0e26u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0c0e28;
P_0c0c0e28: /* original 893f, guest PC 0x0c0c0e28 */
if(!s->budget--) { s->failed_pc=0x0c0c0e28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0eaa; }
goto P_0c0c0e2a;
P_0c0c0e2a: /* original 52d5, guest PC 0x0c0c0e2a */
if(!s->budget--) { s->failed_pc=0x0c0c0e2au; return 0; }
r[2]=read(ram,r[13]+20,4);
goto P_0c0c0e2c;
P_0c0c0e2c: /* original 2228, guest PC 0x0c0c0e2c */
if(!s->budget--) { s->failed_pc=0x0c0c0e2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c0e2e;
P_0c0c0e2e: /* original 893c, guest PC 0x0c0c0e2e */
if(!s->budget--) { s->failed_pc=0x0c0c0e2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c0eaa; }
goto P_0c0c0e30;
P_0c0c0e30: /* original 52d3, guest PC 0x0c0c0e30 */
if(!s->budget--) { s->failed_pc=0x0c0c0e30u; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0c0e32;
P_0c0c0e32: /* original 9307, guest PC 0x0c0c0e32 */
if(!s->budget--) { s->failed_pc=0x0c0c0e32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0e44u,2);
goto P_0c0c0e34;
P_0c0c0e34: /* original 223b, guest PC 0x0c0c0e34 */
if(!s->budget--) { s->failed_pc=0x0c0c0e34u; return 0; }
r[2]|=r[3];
goto P_0c0c0e36;
P_0c0c0e36: /* original a038, guest PC 0x0c0c0e36 */
if(!s->budget--) { s->failed_pc=0x0c0c0e36u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0c0eaa;
P_0c0c0e38: /* original 1d23, guest PC 0x0c0c0e38 */
if(!s->budget--) { s->failed_pc=0x0c0c0e38u; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0c0e3a;
P_0c0c0e3a: /* original dc05, guest PC 0x0c0c0e3a */
if(!s->budget--) { s->failed_pc=0x0c0c0e3au; return 0; }
r[12]=read(ram,0x0c0c0e50u,4);
goto P_0c0c0e3c;
P_0c0c0e3c: /* original a00f, guest PC 0x0c0c0e3c */
if(!s->budget--) { s->failed_pc=0x0c0c0e3cu; return 0; }
goto P_0c0c0e5e;
P_0c0c0e3e: /* original 0009, guest PC 0x0c0c0e3e */
if(!s->budget--) { s->failed_pc=0x0c0c0e3eu; return 0; }
if(!vf3_matrix_family(0x0c0c0e40u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c0e40u; return 0; } return 1;
P_0c0c0e54: /* original 52da, guest PC 0x0c0c0e54 */
if(!s->budget--) { s->failed_pc=0x0c0c0e54u; return 0; }
r[2]=read(ram,r[13]+40,4);
goto P_0c0c0e56;
P_0c0c0e56: /* original 2a28, guest PC 0x0c0c0e56 */
if(!s->budget--) { s->failed_pc=0x0c0c0e56u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0c0e58;
P_0c0c0e58: /* original 8d01, guest PC 0x0c0c0e58 */
if(!s->budget--) { s->failed_pc=0x0c0c0e58u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(cond) { goto P_0c0c0e5e; }
goto P_0c0c0e5c;
P_0c0c0e5a: /* original 6c43, guest PC 0x0c0c0e5a */
if(!s->budget--) { s->failed_pc=0x0c0c0e5au; return 0; }
r[12]=r[4];
goto P_0c0c0e5c;
P_0c0c0e5c: /* original 6cb3, guest PC 0x0c0c0e5c */
if(!s->budget--) { s->failed_pc=0x0c0c0e5cu; return 0; }
r[12]=r[11];
goto P_0c0c0e5e;
P_0c0c0e5e: /* original 54d5, guest PC 0x0c0c0e5e */
if(!s->budget--) { s->failed_pc=0x0c0c0e5eu; return 0; }
r[4]=read(ram,r[13]+20,4);
goto P_0c0c0e60;
P_0c0c0e60: /* original e061, guest PC 0x0c0c0e60 */
if(!s->budget--) { s->failed_pc=0x0c0c0e60u; return 0; }
r[0]=0x00000061u;
goto P_0c0c0e62;
P_0c0c0e62: /* original 63e3, guest PC 0x0c0c0e62 */
if(!s->budget--) { s->failed_pc=0x0c0c0e62u; return 0; }
r[3]=r[14];
goto P_0c0c0e64;
P_0c0c0e64: /* original 732c, guest PC 0x0c0c0e64 */
if(!s->budget--) { s->failed_pc=0x0c0c0e64u; return 0; }
r[3]+=0x0000002cu;
goto P_0c0c0e66;
P_0c0c0e66: /* original 4408, guest PC 0x0c0c0e66 */
if(!s->budget--) { s->failed_pc=0x0c0c0e66u; return 0; }
r[4]<<=2;
goto P_0c0c0e68;
P_0c0c0e68: /* original 343c, guest PC 0x0c0c0e68 */
if(!s->budget--) { s->failed_pc=0x0c0c0e68u; return 0; }
r[4]+=r[3];
goto P_0c0c0e6a;
P_0c0c0e6a: /* original e31f, guest PC 0x0c0c0e6a */
if(!s->budget--) { s->failed_pc=0x0c0c0e6au; return 0; }
r[3]=0x0000001fu;
goto P_0c0c0e6c;
P_0c0c0e6c: /* original 2f42, guest PC 0x0c0c0e6c */
if(!s->budget--) { s->failed_pc=0x0c0c0e6cu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c0e6e;
P_0c0c0e6e: /* original 056c, guest PC 0x0c0c0e6e */
if(!s->budget--) { s->failed_pc=0x0c0c0e6eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c0c0e70;
P_0c0c0e70: /* original d239, guest PC 0x0c0c0e70 */
if(!s->budget--) { s->failed_pc=0x0c0c0e70u; return 0; }
r[2]=read(ram,0x0c0c0f58u,4);
goto P_0c0c0e72;
P_0c0c0e72: /* original 655c, guest PC 0x0c0c0e72 */
if(!s->budget--) { s->failed_pc=0x0c0c0e72u; return 0; }
r[5]=r[5]&255u;
goto P_0c0c0e74;
P_0c0c0e74: /* original 6442, guest PC 0x0c0c0e74 */
if(!s->budget--) { s->failed_pc=0x0c0c0e74u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c0e76;
P_0c0c0e76: /* original 3358, guest PC 0x0c0c0e76 */
if(!s->budget--) { s->failed_pc=0x0c0c0e76u; return 0; }
r[3]-=r[5];
goto P_0c0c0e78;
P_0c0c0e78: /* original 473c, guest PC 0x0c0c0e78 */
if(!s->budget--) { s->failed_pc=0x0c0c0e78u; return 0; }
r[7]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[7]>>((-r[3])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[3]&31u);
goto P_0c0c0e7a;
P_0c0c0e7a: /* original 63f2, guest PC 0x0c0c0e7a */
if(!s->budget--) { s->failed_pc=0x0c0c0e7au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c0e7c;
P_0c0c0e7c: /* original 2c7b, guest PC 0x0c0c0e7c */
if(!s->budget--) { s->failed_pc=0x0c0c0e7cu; return 0; }
r[12]|=r[7];
goto P_0c0c0e7e;
P_0c0c0e7e: /* original 4c28, guest PC 0x0c0c0e7e */
if(!s->budget--) { s->failed_pc=0x0c0c0e7eu; return 0; }
r[12]<<=16;
goto P_0c0c0e80;
P_0c0c0e80: /* original 644d, guest PC 0x0c0c0e80 */
if(!s->budget--) { s->failed_pc=0x0c0c0e80u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0c0e82;
P_0c0c0e82: /* original 2c29, guest PC 0x0c0c0e82 */
if(!s->budget--) { s->failed_pc=0x0c0c0e82u; return 0; }
r[12]&=r[2];
goto P_0c0c0e84;
P_0c0c0e84: /* original 24cb, guest PC 0x0c0c0e84 */
if(!s->budget--) { s->failed_pc=0x0c0c0e84u; return 0; }
r[4]|=r[12];
goto P_0c0c0e86;
P_0c0c0e86: /* original a010, guest PC 0x0c0c0e86 */
if(!s->budget--) { s->failed_pc=0x0c0c0e86u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0c0eaa;
P_0c0c0e88: /* original 2342, guest PC 0x0c0c0e88 */
if(!s->budget--) { s->failed_pc=0x0c0c0e88u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c0c0e8a;
P_0c0c0e8a: /* original 7f14, guest PC 0x0c0c0e8a */
if(!s->budget--) { s->failed_pc=0x0c0c0e8au; return 0; }
r[15]+=0x00000014u;
goto P_0c0c0e8c;
P_0c0c0e8c: /* original 52d3, guest PC 0x0c0c0e8c */
if(!s->budget--) { s->failed_pc=0x0c0c0e8cu; return 0; }
r[2]=read(ram,r[13]+12,4);
goto P_0c0c0e8e;
P_0c0c0e8e: /* original 4f26, guest PC 0x0c0c0e8e */
if(!s->budget--) { s->failed_pc=0x0c0c0e8eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0e90;
P_0c0c0e90: /* original e040, guest PC 0x0c0c0e90 */
if(!s->budget--) { s->failed_pc=0x0c0c0e90u; return 0; }
r[0]=0x00000040u;
goto P_0c0c0e92;
P_0c0c0e92: /* original 935f, guest PC 0x0c0c0e92 */
if(!s->budget--) { s->failed_pc=0x0c0c0e92u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c0f54u,2);
goto P_0c0c0e94;
P_0c0c0e94: /* original 65d3, guest PC 0x0c0c0e94 */
if(!s->budget--) { s->failed_pc=0x0c0c0e94u; return 0; }
r[5]=r[13];
goto P_0c0c0e96;
P_0c0c0e96: /* original 64e3, guest PC 0x0c0c0e96 */
if(!s->budget--) { s->failed_pc=0x0c0c0e96u; return 0; }
r[4]=r[14];
goto P_0c0c0e98;
P_0c0c0e98: /* original 2239, guest PC 0x0c0c0e98 */
if(!s->budget--) { s->failed_pc=0x0c0c0e98u; return 0; }
r[2]&=r[3];
goto P_0c0c0e9a;
P_0c0c0e9a: /* original 1d23, guest PC 0x0c0c0e9a */
if(!s->budget--) { s->failed_pc=0x0c0c0e9au; return 0; }
write(ram,r[13]+12,r[2],4);
goto P_0c0c0e9c;
P_0c0c0e9c: /* original 0ec6, guest PC 0x0c0c0e9c */
if(!s->budget--) { s->failed_pc=0x0c0c0e9cu; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0c0e9e;
P_0c0c0e9e: /* original 6af6, guest PC 0x0c0c0e9e */
if(!s->budget--) { s->failed_pc=0x0c0c0e9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c0ea0;
P_0c0c0ea0: /* original 6bf6, guest PC 0x0c0c0ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c0ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c0ea2;
P_0c0c0ea2: /* original 6cf6, guest PC 0x0c0c0ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c0ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c0ea4;
P_0c0c0ea4: /* original 6df6, guest PC 0x0c0c0ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c0ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c0ea6;
P_0c0c0ea6: /* original a0c9, guest PC 0x0c0c0ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c0ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c103cu,s,ram);
P_0c0c0ea8: /* original 6ef6, guest PC 0x0c0c0ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c0ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c0eaa;
P_0c0c0eaa: /* original 7f14, guest PC 0x0c0c0eaa */
if(!s->budget--) { s->failed_pc=0x0c0c0eaau; return 0; }
r[15]+=0x00000014u;
goto P_0c0c0eac;
P_0c0c0eac: /* original 4f26, guest PC 0x0c0c0eac */
if(!s->budget--) { s->failed_pc=0x0c0c0eacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c0eae;
P_0c0c0eae: /* original 6af6, guest PC 0x0c0c0eae */
if(!s->budget--) { s->failed_pc=0x0c0c0eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c0eb0;
P_0c0c0eb0: /* original 6bf6, guest PC 0x0c0c0eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c0eb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c0eb2;
P_0c0c0eb2: /* original 6cf6, guest PC 0x0c0c0eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c0eb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c0eb4;
P_0c0c0eb4: /* original 6df6, guest PC 0x0c0c0eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c0eb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c0eb6;
P_0c0c0eb6: /* original 000b, guest PC 0x0c0c0eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c0eb6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c0eb8: /* original 6ef6, guest PC 0x0c0c0eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c0eb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c0ebau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
