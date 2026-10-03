/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_fifth_leaf_extra_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c076ba6u: goto P_0c076ba6;
case 0x0c076ba8u: goto P_0c076ba8;
case 0x0c076baau: goto P_0c076baa;
case 0x0c076bacu: goto P_0c076bac;
case 0x0c076baeu: goto P_0c076bae;
case 0x0c076bb0u: goto P_0c076bb0;
case 0x0c076bb2u: goto P_0c076bb2;
case 0x0c076bb4u: goto P_0c076bb4;
case 0x0c076bb6u: goto P_0c076bb6;
case 0x0c076bb8u: goto P_0c076bb8;
case 0x0c076bbau: goto P_0c076bba;
case 0x0c076bbcu: goto P_0c076bbc;
case 0x0c076bbeu: goto P_0c076bbe;
case 0x0c076bc0u: goto P_0c076bc0;
case 0x0c076bc2u: goto P_0c076bc2;
case 0x0c076bc4u: goto P_0c076bc4;
case 0x0c076bc6u: goto P_0c076bc6;
case 0x0c076bc8u: goto P_0c076bc8;
case 0x0c076bcau: goto P_0c076bca;
case 0x0c076bccu: goto P_0c076bcc;
case 0x0c076bceu: goto P_0c076bce;
case 0x0c076bd0u: goto P_0c076bd0;
case 0x0c076bd2u: goto P_0c076bd2;
case 0x0c076bd4u: goto P_0c076bd4;
case 0x0c076bd6u: goto P_0c076bd6;
case 0x0c076bd8u: goto P_0c076bd8;
case 0x0c076bdau: goto P_0c076bda;
case 0x0c076bdcu: goto P_0c076bdc;
case 0x0c076bdeu: goto P_0c076bde;
case 0x0c076be0u: goto P_0c076be0;
case 0x0c076be2u: goto P_0c076be2;
case 0x0c076be4u: goto P_0c076be4;
case 0x0c076be6u: goto P_0c076be6;
case 0x0c076be8u: goto P_0c076be8;
case 0x0c076beau: goto P_0c076bea;
case 0x0c076becu: goto P_0c076bec;
case 0x0c076beeu: goto P_0c076bee;
case 0x0c076bf0u: goto P_0c076bf0;
case 0x0c076bf2u: goto P_0c076bf2;
case 0x0c076bf4u: goto P_0c076bf4;
case 0x0c076bf6u: goto P_0c076bf6;
case 0x0c076bf8u: goto P_0c076bf8;
case 0x0c076bfau: goto P_0c076bfa;
case 0x0c076bfcu: goto P_0c076bfc;
case 0x0c076bfeu: goto P_0c076bfe;
case 0x0c076c00u: goto P_0c076c00;
case 0x0c076c02u: goto P_0c076c02;
case 0x0c076c04u: goto P_0c076c04;
case 0x0c076c06u: goto P_0c076c06;
case 0x0c076c08u: goto P_0c076c08;
case 0x0c076c0au: goto P_0c076c0a;
case 0x0c076c0cu: goto P_0c076c0c;
case 0x0c076c0eu: goto P_0c076c0e;
case 0x0c076c10u: goto P_0c076c10;
case 0x0c076c12u: goto P_0c076c12;
case 0x0c076c14u: goto P_0c076c14;
case 0x0c076c16u: goto P_0c076c16;
case 0x0c076c18u: goto P_0c076c18;
case 0x0c076c1au: goto P_0c076c1a;
case 0x0c076c1cu: goto P_0c076c1c;
case 0x0c076c1eu: goto P_0c076c1e;
case 0x0c076c20u: goto P_0c076c20;
case 0x0c076c22u: goto P_0c076c22;
case 0x0c076c24u: goto P_0c076c24;
case 0x0c076c26u: goto P_0c076c26;
case 0x0c076c28u: goto P_0c076c28;
case 0x0c076c2au: goto P_0c076c2a;
case 0x0c076c2cu: goto P_0c076c2c;
case 0x0c076c2eu: goto P_0c076c2e;
case 0x0c076c30u: goto P_0c076c30;
case 0x0c076c32u: goto P_0c076c32;
case 0x0c076c34u: goto P_0c076c34;
case 0x0c076c36u: goto P_0c076c36;
case 0x0c076c38u: goto P_0c076c38;
case 0x0c076c3au: goto P_0c076c3a;
case 0x0c076c3cu: goto P_0c076c3c;
case 0x0c076c3eu: goto P_0c076c3e;
case 0x0c076c40u: goto P_0c076c40;
case 0x0c076c42u: goto P_0c076c42;
case 0x0c076c44u: goto P_0c076c44;
case 0x0c076c46u: goto P_0c076c46;
case 0x0c076c48u: goto P_0c076c48;
case 0x0c076c4au: goto P_0c076c4a;
case 0x0c076c4cu: goto P_0c076c4c;
case 0x0c076c4eu: goto P_0c076c4e;
case 0x0c076c50u: goto P_0c076c50;
case 0x0c076c52u: goto P_0c076c52;
case 0x0c076c54u: goto P_0c076c54;
case 0x0c076c56u: goto P_0c076c56;
case 0x0c076c58u: goto P_0c076c58;
case 0x0c076c5au: goto P_0c076c5a;
case 0x0c076c5cu: goto P_0c076c5c;
case 0x0c076c5eu: goto P_0c076c5e;
case 0x0c076c60u: goto P_0c076c60;
case 0x0c076c62u: goto P_0c076c62;
case 0x0c076c64u: goto P_0c076c64;
case 0x0c076c66u: goto P_0c076c66;
case 0x0c076c68u: goto P_0c076c68;
case 0x0c076c6au: goto P_0c076c6a;
case 0x0c076c6cu: goto P_0c076c6c;
case 0x0c076c6eu: goto P_0c076c6e;
case 0x0c076c70u: goto P_0c076c70;
case 0x0c076c72u: goto P_0c076c72;
case 0x0c076c74u: goto P_0c076c74;
case 0x0c076c76u: goto P_0c076c76;
case 0x0c076c78u: goto P_0c076c78;
case 0x0c076c7au: goto P_0c076c7a;
case 0x0c076c7cu: goto P_0c076c7c;
case 0x0c076c7eu: goto P_0c076c7e;
case 0x0c076c80u: goto P_0c076c80;
case 0x0c076c82u: goto P_0c076c82;
case 0x0c076c84u: goto P_0c076c84;
case 0x0c076c86u: goto P_0c076c86;
case 0x0c076c88u: goto P_0c076c88;
case 0x0c076c8au: goto P_0c076c8a;
case 0x0c076c8cu: goto P_0c076c8c;
case 0x0c076c8eu: goto P_0c076c8e;
case 0x0c076c90u: goto P_0c076c90;
case 0x0c076c92u: goto P_0c076c92;
case 0x0c076c94u: goto P_0c076c94;
case 0x0c076c96u: goto P_0c076c96;
case 0x0c076c98u: goto P_0c076c98;
case 0x0c076c9au: goto P_0c076c9a;
case 0x0c076c9cu: goto P_0c076c9c;
case 0x0c076c9eu: goto P_0c076c9e;
case 0x0c076cd8u: goto P_0c076cd8;
case 0x0c076cdau: goto P_0c076cda;
case 0x0c076cdcu: goto P_0c076cdc;
case 0x0c076cdeu: goto P_0c076cde;
case 0x0c076ce0u: goto P_0c076ce0;
case 0x0c076ce2u: goto P_0c076ce2;
case 0x0c076ce4u: goto P_0c076ce4;
case 0x0c076ce6u: goto P_0c076ce6;
case 0x0c076ce8u: goto P_0c076ce8;
case 0x0c076ceau: goto P_0c076cea;
case 0x0c076cecu: goto P_0c076cec;
case 0x0c076ceeu: goto P_0c076cee;
case 0x0c076cf0u: goto P_0c076cf0;
case 0x0c076cf2u: goto P_0c076cf2;
case 0x0c076cf4u: goto P_0c076cf4;
case 0x0c076cf6u: goto P_0c076cf6;
case 0x0c076cf8u: goto P_0c076cf8;
case 0x0c076cfau: goto P_0c076cfa;
case 0x0c076cfcu: goto P_0c076cfc;
case 0x0c076cfeu: goto P_0c076cfe;
case 0x0c076d00u: goto P_0c076d00;
case 0x0c076d02u: goto P_0c076d02;
case 0x0c076d04u: goto P_0c076d04;
case 0x0c076d06u: goto P_0c076d06;
case 0x0c076d08u: goto P_0c076d08;
case 0x0c076d0au: goto P_0c076d0a;
case 0x0c076d0cu: goto P_0c076d0c;
case 0x0c076d0eu: goto P_0c076d0e;
case 0x0c076d10u: goto P_0c076d10;
case 0x0c076d12u: goto P_0c076d12;
case 0x0c076d14u: goto P_0c076d14;
case 0x0c076d16u: goto P_0c076d16;
case 0x0c076d18u: goto P_0c076d18;
case 0x0c076d1au: goto P_0c076d1a;
case 0x0c076d1cu: goto P_0c076d1c;
case 0x0c076d1eu: goto P_0c076d1e;
case 0x0c076d20u: goto P_0c076d20;
case 0x0c076d22u: goto P_0c076d22;
case 0x0c076d24u: goto P_0c076d24;
case 0x0c076d26u: goto P_0c076d26;
case 0x0c076d28u: goto P_0c076d28;
case 0x0c076d2au: goto P_0c076d2a;
case 0x0c076d2cu: goto P_0c076d2c;
case 0x0c076d2eu: goto P_0c076d2e;
case 0x0c076d30u: goto P_0c076d30;
case 0x0c076d32u: goto P_0c076d32;
case 0x0c076d34u: goto P_0c076d34;
case 0x0c076d36u: goto P_0c076d36;
case 0x0c076d38u: goto P_0c076d38;
case 0x0c076d3au: goto P_0c076d3a;
case 0x0c076d3cu: goto P_0c076d3c;
case 0x0c076d3eu: goto P_0c076d3e;
case 0x0c076d40u: goto P_0c076d40;
case 0x0c076d42u: goto P_0c076d42;
case 0x0c076d44u: goto P_0c076d44;
case 0x0c076d46u: goto P_0c076d46;
case 0x0c076d48u: goto P_0c076d48;
case 0x0c076d4au: goto P_0c076d4a;
case 0x0c076d4cu: goto P_0c076d4c;
case 0x0c076d4eu: goto P_0c076d4e;
case 0x0c076d50u: goto P_0c076d50;
case 0x0c076d52u: goto P_0c076d52;
case 0x0c076d54u: goto P_0c076d54;
case 0x0c076d56u: goto P_0c076d56;
case 0x0c076d58u: goto P_0c076d58;
case 0x0c076d5au: goto P_0c076d5a;
case 0x0c076d5cu: goto P_0c076d5c;
case 0x0c076d5eu: goto P_0c076d5e;
case 0x0c076d60u: goto P_0c076d60;
case 0x0c076d62u: goto P_0c076d62;
case 0x0c076d64u: goto P_0c076d64;
case 0x0c076d66u: goto P_0c076d66;
case 0x0c076d68u: goto P_0c076d68;
case 0x0c076d6au: goto P_0c076d6a;
case 0x0c076d6cu: goto P_0c076d6c;
case 0x0c076d6eu: goto P_0c076d6e;
case 0x0c076d70u: goto P_0c076d70;
case 0x0c076d72u: goto P_0c076d72;
case 0x0c076d74u: goto P_0c076d74;
case 0x0c076d76u: goto P_0c076d76;
case 0x0c076d78u: goto P_0c076d78;
case 0x0c076d7au: goto P_0c076d7a;
case 0x0c076d7cu: goto P_0c076d7c;
case 0x0c076d7eu: goto P_0c076d7e;
case 0x0c076d80u: goto P_0c076d80;
case 0x0c076d82u: goto P_0c076d82;
case 0x0c076d84u: goto P_0c076d84;
case 0x0c076d86u: goto P_0c076d86;
case 0x0c076d88u: goto P_0c076d88;
case 0x0c076d8au: goto P_0c076d8a;
case 0x0c076d8cu: goto P_0c076d8c;
case 0x0c076d8eu: goto P_0c076d8e;
case 0x0c076d90u: goto P_0c076d90;
case 0x0c076d92u: goto P_0c076d92;
case 0x0c076d94u: goto P_0c076d94;
case 0x0c076d96u: goto P_0c076d96;
case 0x0c076d98u: goto P_0c076d98;
case 0x0c076d9au: goto P_0c076d9a;
case 0x0c076d9cu: goto P_0c076d9c;
case 0x0c076d9eu: goto P_0c076d9e;
case 0x0c076da0u: goto P_0c076da0;
case 0x0c076da2u: goto P_0c076da2;
case 0x0c076da4u: goto P_0c076da4;
case 0x0c076da6u: goto P_0c076da6;
case 0x0c076da8u: goto P_0c076da8;
case 0x0c076de0u: goto P_0c076de0;
case 0x0c076de2u: goto P_0c076de2;
case 0x0c076de4u: goto P_0c076de4;
case 0x0c076de6u: goto P_0c076de6;
case 0x0c076de8u: goto P_0c076de8;
case 0x0c076deau: goto P_0c076dea;
case 0x0c076decu: goto P_0c076dec;
case 0x0c076deeu: goto P_0c076dee;
case 0x0c076df0u: goto P_0c076df0;
case 0x0c076df2u: goto P_0c076df2;
case 0x0c076df4u: goto P_0c076df4;
case 0x0c076df6u: goto P_0c076df6;
case 0x0c076df8u: goto P_0c076df8;
case 0x0c076dfau: goto P_0c076dfa;
case 0x0c076dfcu: goto P_0c076dfc;
case 0x0c076dfeu: goto P_0c076dfe;
case 0x0c076e00u: goto P_0c076e00;
case 0x0c076e02u: goto P_0c076e02;
case 0x0c076e04u: goto P_0c076e04;
case 0x0c076e06u: goto P_0c076e06;
case 0x0c076e08u: goto P_0c076e08;
case 0x0c076e0au: goto P_0c076e0a;
case 0x0c076e0cu: goto P_0c076e0c;
case 0x0c076e0eu: goto P_0c076e0e;
case 0x0c076e10u: goto P_0c076e10;
case 0x0c076e12u: goto P_0c076e12;
case 0x0c076e14u: goto P_0c076e14;
case 0x0c076e16u: goto P_0c076e16;
case 0x0c076e18u: goto P_0c076e18;
case 0x0c076e1au: goto P_0c076e1a;
case 0x0c076e1cu: goto P_0c076e1c;
case 0x0c076e1eu: goto P_0c076e1e;
case 0x0c076e20u: goto P_0c076e20;
case 0x0c076e22u: goto P_0c076e22;
case 0x0c076e24u: goto P_0c076e24;
case 0x0c076e26u: goto P_0c076e26;
case 0x0c076e28u: goto P_0c076e28;
case 0x0c076e2au: goto P_0c076e2a;
case 0x0c076e2cu: goto P_0c076e2c;
case 0x0c076e2eu: goto P_0c076e2e;
case 0x0c076e30u: goto P_0c076e30;
case 0x0c076e32u: goto P_0c076e32;
case 0x0c076e34u: goto P_0c076e34;
case 0x0c076e36u: goto P_0c076e36;
case 0x0c076e38u: goto P_0c076e38;
case 0x0c076e3au: goto P_0c076e3a;
case 0x0c076e3cu: goto P_0c076e3c;
case 0x0c076e3eu: goto P_0c076e3e;
case 0x0c076e40u: goto P_0c076e40;
case 0x0c076e42u: goto P_0c076e42;
case 0x0c076e44u: goto P_0c076e44;
case 0x0c076e46u: goto P_0c076e46;
case 0x0c076e48u: goto P_0c076e48;
case 0x0c076e4au: goto P_0c076e4a;
case 0x0c076e4cu: goto P_0c076e4c;
case 0x0c076e4eu: goto P_0c076e4e;
case 0x0c076e50u: goto P_0c076e50;
case 0x0c076e52u: goto P_0c076e52;
case 0x0c076e54u: goto P_0c076e54;
case 0x0c076e56u: goto P_0c076e56;
case 0x0c076e58u: goto P_0c076e58;
case 0x0c076e5au: goto P_0c076e5a;
case 0x0c076e5cu: goto P_0c076e5c;
case 0x0c076e5eu: goto P_0c076e5e;
case 0x0c076e60u: goto P_0c076e60;
case 0x0c076e62u: goto P_0c076e62;
case 0x0c076e64u: goto P_0c076e64;
case 0x0c076e66u: goto P_0c076e66;
case 0x0c076e68u: goto P_0c076e68;
case 0x0c076e6au: goto P_0c076e6a;
case 0x0c076e6cu: goto P_0c076e6c;
case 0x0c076e6eu: goto P_0c076e6e;
case 0x0c076e70u: goto P_0c076e70;
case 0x0c076e72u: goto P_0c076e72;
case 0x0c076e74u: goto P_0c076e74;
case 0x0c076e76u: goto P_0c076e76;
case 0x0c076e78u: goto P_0c076e78;
case 0x0c076e7au: goto P_0c076e7a;
case 0x0c076e7cu: goto P_0c076e7c;
case 0x0c076e7eu: goto P_0c076e7e;
case 0x0c076e80u: goto P_0c076e80;
case 0x0c076e82u: goto P_0c076e82;
case 0x0c076e84u: goto P_0c076e84;
case 0x0c076e86u: goto P_0c076e86;
case 0x0c076e88u: goto P_0c076e88;
case 0x0c076e8au: goto P_0c076e8a;
case 0x0c076e8cu: goto P_0c076e8c;
case 0x0c076e8eu: goto P_0c076e8e;
case 0x0c076e90u: goto P_0c076e90;
case 0x0c076e92u: goto P_0c076e92;
case 0x0c076e94u: goto P_0c076e94;
case 0x0c076e96u: goto P_0c076e96;
case 0x0c076e98u: goto P_0c076e98;
case 0x0c076e9au: goto P_0c076e9a;
case 0x0c076e9cu: goto P_0c076e9c;
case 0x0c076e9eu: goto P_0c076e9e;
case 0x0c076ea0u: goto P_0c076ea0;
case 0x0c076ea2u: goto P_0c076ea2;
case 0x0c076ea4u: goto P_0c076ea4;
case 0x0c076ea6u: goto P_0c076ea6;
case 0x0c076ea8u: goto P_0c076ea8;
case 0x0c076eaau: goto P_0c076eaa;
case 0x0c076eacu: goto P_0c076eac;
case 0x0c076eaeu: goto P_0c076eae;
case 0x0c076eb0u: goto P_0c076eb0;
case 0x0c076eb2u: goto P_0c076eb2;
case 0x0c076eb4u: goto P_0c076eb4;
case 0x0c076eb6u: goto P_0c076eb6;
case 0x0c076eb8u: goto P_0c076eb8;
case 0x0c076ebau: goto P_0c076eba;
case 0x0c076ef4u: goto P_0c076ef4;
case 0x0c076ef6u: goto P_0c076ef6;
case 0x0c076ef8u: goto P_0c076ef8;
case 0x0c076efau: goto P_0c076efa;
case 0x0c076efcu: goto P_0c076efc;
case 0x0c076efeu: goto P_0c076efe;
case 0x0c076f00u: goto P_0c076f00;
case 0x0c076f02u: goto P_0c076f02;
case 0x0c076f04u: goto P_0c076f04;
case 0x0c076f06u: goto P_0c076f06;
case 0x0c076f08u: goto P_0c076f08;
case 0x0c076f0au: goto P_0c076f0a;
case 0x0c076f0cu: goto P_0c076f0c;
case 0x0c076f0eu: goto P_0c076f0e;
case 0x0c076f10u: goto P_0c076f10;
case 0x0c076f12u: goto P_0c076f12;
case 0x0c076f14u: goto P_0c076f14;
case 0x0c076f16u: goto P_0c076f16;
case 0x0c076f18u: goto P_0c076f18;
case 0x0c076f1au: goto P_0c076f1a;
case 0x0c076f1cu: goto P_0c076f1c;
case 0x0c076f1eu: goto P_0c076f1e;
case 0x0c076f20u: goto P_0c076f20;
case 0x0c076f22u: goto P_0c076f22;
case 0x0c076f24u: goto P_0c076f24;
case 0x0c076f26u: goto P_0c076f26;
case 0x0c076f28u: goto P_0c076f28;
case 0x0c076f2au: goto P_0c076f2a;
case 0x0c076f2cu: goto P_0c076f2c;
case 0x0c076f2eu: goto P_0c076f2e;
case 0x0c076f30u: goto P_0c076f30;
case 0x0c076f32u: goto P_0c076f32;
case 0x0c076f34u: goto P_0c076f34;
case 0x0c076f36u: goto P_0c076f36;
case 0x0c076f38u: goto P_0c076f38;
case 0x0c076f3au: goto P_0c076f3a;
case 0x0c076f3cu: goto P_0c076f3c;
case 0x0c076f3eu: goto P_0c076f3e;
case 0x0c076f40u: goto P_0c076f40;
case 0x0c076f42u: goto P_0c076f42;
case 0x0c076f44u: goto P_0c076f44;
case 0x0c076f46u: goto P_0c076f46;
case 0x0c076f48u: goto P_0c076f48;
case 0x0c076f4au: goto P_0c076f4a;
case 0x0c076f4cu: goto P_0c076f4c;
case 0x0c076f4eu: goto P_0c076f4e;
case 0x0c076f50u: goto P_0c076f50;
case 0x0c076f52u: goto P_0c076f52;
case 0x0c076f54u: goto P_0c076f54;
case 0x0c076f56u: goto P_0c076f56;
case 0x0c076f58u: goto P_0c076f58;
case 0x0c076f5au: goto P_0c076f5a;
case 0x0c076f5cu: goto P_0c076f5c;
case 0x0c076f5eu: goto P_0c076f5e;
case 0x0c076f60u: goto P_0c076f60;
case 0x0c076f62u: goto P_0c076f62;
case 0x0c076f64u: goto P_0c076f64;
case 0x0c076f66u: goto P_0c076f66;
case 0x0c076f68u: goto P_0c076f68;
case 0x0c076f6au: goto P_0c076f6a;
case 0x0c076f6cu: goto P_0c076f6c;
case 0x0c076f6eu: goto P_0c076f6e;
case 0x0c076f70u: goto P_0c076f70;
case 0x0c076f72u: goto P_0c076f72;
case 0x0c076f74u: goto P_0c076f74;
case 0x0c076f76u: goto P_0c076f76;
case 0x0c076f78u: goto P_0c076f78;
case 0x0c076f7au: goto P_0c076f7a;
case 0x0c076f7cu: goto P_0c076f7c;
case 0x0c076f7eu: goto P_0c076f7e;
case 0x0c076f80u: goto P_0c076f80;
case 0x0c076f82u: goto P_0c076f82;
case 0x0c076f84u: goto P_0c076f84;
case 0x0c076f86u: goto P_0c076f86;
case 0x0c076f88u: goto P_0c076f88;
case 0x0c076f8au: goto P_0c076f8a;
case 0x0c076f8cu: goto P_0c076f8c;
case 0x0c076f8eu: goto P_0c076f8e;
case 0x0c076f90u: goto P_0c076f90;
case 0x0c076f92u: goto P_0c076f92;
case 0x0c076f94u: goto P_0c076f94;
case 0x0c076f96u: goto P_0c076f96;
case 0x0c076f98u: goto P_0c076f98;
case 0x0c076f9au: goto P_0c076f9a;
case 0x0c076f9cu: goto P_0c076f9c;
case 0x0c076f9eu: goto P_0c076f9e;
case 0x0c076fa0u: goto P_0c076fa0;
case 0x0c076fa2u: goto P_0c076fa2;
case 0x0c076fa4u: goto P_0c076fa4;
case 0x0c076fa6u: goto P_0c076fa6;
case 0x0c076fa8u: goto P_0c076fa8;
case 0x0c076faau: goto P_0c076faa;
case 0x0c076facu: goto P_0c076fac;
case 0x0c076faeu: goto P_0c076fae;
case 0x0c076fb0u: goto P_0c076fb0;
case 0x0c076fb2u: goto P_0c076fb2;
case 0x0c076fb4u: goto P_0c076fb4;
case 0x0c076fb6u: goto P_0c076fb6;
case 0x0c076fb8u: goto P_0c076fb8;
case 0x0c076fbau: goto P_0c076fba;
case 0x0c076fbcu: goto P_0c076fbc;
case 0x0c076fbeu: goto P_0c076fbe;
case 0x0c076fc0u: goto P_0c076fc0;
case 0x0c076fc2u: goto P_0c076fc2;
case 0x0c076fc4u: goto P_0c076fc4;
case 0x0c076fc6u: goto P_0c076fc6;
case 0x0c076fc8u: goto P_0c076fc8;
case 0x0c076fcau: goto P_0c076fca;
case 0x0c076fccu: goto P_0c076fcc;
case 0x0c076fceu: goto P_0c076fce;
case 0x0c076fd0u: goto P_0c076fd0;
case 0x0c076fd2u: goto P_0c076fd2;
case 0x0c076fd4u: goto P_0c076fd4;
case 0x0c076fd6u: goto P_0c076fd6;
case 0x0c076fd8u: goto P_0c076fd8;
case 0x0c076fdau: goto P_0c076fda;
case 0x0c076fdcu: goto P_0c076fdc;
case 0x0c076fdeu: goto P_0c076fde;
case 0x0c076fe0u: goto P_0c076fe0;
case 0x0c076fe2u: goto P_0c076fe2;
case 0x0c076fe4u: goto P_0c076fe4;
case 0x0c076fe6u: goto P_0c076fe6;
case 0x0c076fe8u: goto P_0c076fe8;
case 0x0c076feau: goto P_0c076fea;
case 0x0c076fecu: goto P_0c076fec;
case 0x0c076feeu: goto P_0c076fee;
case 0x0c076ff0u: goto P_0c076ff0;
case 0x0c076ff2u: goto P_0c076ff2;
case 0x0c076ff4u: goto P_0c076ff4;
case 0x0c076ff6u: goto P_0c076ff6;
case 0x0c076ff8u: goto P_0c076ff8;
case 0x0c076ffau: goto P_0c076ffa;
case 0x0c076ffcu: goto P_0c076ffc;
case 0x0c076ffeu: goto P_0c076ffe;
case 0x0c077000u: goto P_0c077000;
case 0x0c077002u: goto P_0c077002;
case 0x0c077004u: goto P_0c077004;
case 0x0c077006u: goto P_0c077006;
case 0x0c077008u: goto P_0c077008;
case 0x0c07700au: goto P_0c07700a;
case 0x0c07700cu: goto P_0c07700c;
case 0x0c07700eu: goto P_0c07700e;
case 0x0c077010u: goto P_0c077010;
case 0x0c077012u: goto P_0c077012;
case 0x0c077014u: goto P_0c077014;
case 0x0c077016u: goto P_0c077016;
case 0x0c077018u: goto P_0c077018;
case 0x0c07701au: goto P_0c07701a;
case 0x0c07701cu: goto P_0c07701c;
case 0x0c07701eu: goto P_0c07701e;
case 0x0c077020u: goto P_0c077020;
case 0x0c077022u: goto P_0c077022;
case 0x0c077024u: goto P_0c077024;
case 0x0c077026u: goto P_0c077026;
case 0x0c077028u: goto P_0c077028;
case 0x0c07702au: goto P_0c07702a;
case 0x0c07702cu: goto P_0c07702c;
case 0x0c07702eu: goto P_0c07702e;
case 0x0c077030u: goto P_0c077030;
case 0x0c077032u: goto P_0c077032;
case 0x0c077034u: goto P_0c077034;
case 0x0c077036u: goto P_0c077036;
case 0x0c077038u: goto P_0c077038;
case 0x0c07703au: goto P_0c07703a;
case 0x0c07703cu: goto P_0c07703c;
case 0x0c07703eu: goto P_0c07703e;
case 0x0c077040u: goto P_0c077040;
case 0x0c077042u: goto P_0c077042;
case 0x0c077044u: goto P_0c077044;
case 0x0c077046u: goto P_0c077046;
case 0x0c077048u: goto P_0c077048;
case 0x0c07704au: goto P_0c07704a;
case 0x0c07704cu: goto P_0c07704c;
case 0x0c07704eu: goto P_0c07704e;
case 0x0c077050u: goto P_0c077050;
case 0x0c077052u: goto P_0c077052;
case 0x0c077054u: goto P_0c077054;
case 0x0c077056u: goto P_0c077056;
case 0x0c077058u: goto P_0c077058;
case 0x0c07705au: goto P_0c07705a;
case 0x0c07705cu: goto P_0c07705c;
case 0x0c07705eu: goto P_0c07705e;
case 0x0c077080u: goto P_0c077080;
case 0x0c077082u: goto P_0c077082;
case 0x0c077084u: goto P_0c077084;
case 0x0c077086u: goto P_0c077086;
case 0x0c077088u: goto P_0c077088;
case 0x0c07708au: goto P_0c07708a;
case 0x0c07708cu: goto P_0c07708c;
case 0x0c07708eu: goto P_0c07708e;
case 0x0c077090u: goto P_0c077090;
case 0x0c077092u: goto P_0c077092;
case 0x0c077094u: goto P_0c077094;
case 0x0c077096u: goto P_0c077096;
case 0x0c077098u: goto P_0c077098;
case 0x0c07709au: goto P_0c07709a;
case 0x0c07709cu: goto P_0c07709c;
case 0x0c07709eu: goto P_0c07709e;
case 0x0c0770a0u: goto P_0c0770a0;
case 0x0c0770a2u: goto P_0c0770a2;
case 0x0c0770a4u: goto P_0c0770a4;
case 0x0c0770a6u: goto P_0c0770a6;
case 0x0c0770a8u: goto P_0c0770a8;
case 0x0c0770aau: goto P_0c0770aa;
case 0x0c0770acu: goto P_0c0770ac;
case 0x0c0770aeu: goto P_0c0770ae;
case 0x0c0770b0u: goto P_0c0770b0;
case 0x0c0770b2u: goto P_0c0770b2;
case 0x0c0770b4u: goto P_0c0770b4;
case 0x0c0770b6u: goto P_0c0770b6;
case 0x0c0770b8u: goto P_0c0770b8;
case 0x0c0770bau: goto P_0c0770ba;
case 0x0c0770bcu: goto P_0c0770bc;
case 0x0c0770beu: goto P_0c0770be;
case 0x0c0770c0u: goto P_0c0770c0;
case 0x0c0770c2u: goto P_0c0770c2;
case 0x0c0770c4u: goto P_0c0770c4;
case 0x0c0770c6u: goto P_0c0770c6;
case 0x0c0770c8u: goto P_0c0770c8;
case 0x0c0770cau: goto P_0c0770ca;
case 0x0c0770ccu: goto P_0c0770cc;
case 0x0c0770ceu: goto P_0c0770ce;
case 0x0c0770d0u: goto P_0c0770d0;
case 0x0c0770d2u: goto P_0c0770d2;
case 0x0c0770d4u: goto P_0c0770d4;
case 0x0c0770d6u: goto P_0c0770d6;
case 0x0c0770d8u: goto P_0c0770d8;
case 0x0c0770dau: goto P_0c0770da;
case 0x0c0770dcu: goto P_0c0770dc;
case 0x0c0770deu: goto P_0c0770de;
case 0x0c0770e0u: goto P_0c0770e0;
case 0x0c0770e2u: goto P_0c0770e2;
case 0x0c0770e4u: goto P_0c0770e4;
case 0x0c0770e6u: goto P_0c0770e6;
case 0x0c0770e8u: goto P_0c0770e8;
case 0x0c0770eau: goto P_0c0770ea;
case 0x0c0770ecu: goto P_0c0770ec;
case 0x0c0770eeu: goto P_0c0770ee;
case 0x0c0770f0u: goto P_0c0770f0;
case 0x0c0770f2u: goto P_0c0770f2;
case 0x0c0770f4u: goto P_0c0770f4;
case 0x0c0770f6u: goto P_0c0770f6;
case 0x0c0770f8u: goto P_0c0770f8;
case 0x0c0770fau: goto P_0c0770fa;
case 0x0c0770fcu: goto P_0c0770fc;
case 0x0c0770feu: goto P_0c0770fe;
case 0x0c077100u: goto P_0c077100;
case 0x0c077102u: goto P_0c077102;
case 0x0c077104u: goto P_0c077104;
case 0x0c077106u: goto P_0c077106;
case 0x0c077108u: goto P_0c077108;
case 0x0c07710au: goto P_0c07710a;
case 0x0c07710cu: goto P_0c07710c;
case 0x0c07710eu: goto P_0c07710e;
case 0x0c077110u: goto P_0c077110;
case 0x0c077112u: goto P_0c077112;
case 0x0c077114u: goto P_0c077114;
case 0x0c077116u: goto P_0c077116;
case 0x0c077118u: goto P_0c077118;
case 0x0c07711au: goto P_0c07711a;
case 0x0c07711cu: goto P_0c07711c;
case 0x0c07711eu: goto P_0c07711e;
case 0x0c077120u: goto P_0c077120;
case 0x0c077122u: goto P_0c077122;
case 0x0c077124u: goto P_0c077124;
case 0x0c077126u: goto P_0c077126;
case 0x0c077128u: goto P_0c077128;
case 0x0c07712au: goto P_0c07712a;
case 0x0c07712cu: goto P_0c07712c;
case 0x0c07712eu: goto P_0c07712e;
case 0x0c077130u: goto P_0c077130;
case 0x0c077132u: goto P_0c077132;
case 0x0c077134u: goto P_0c077134;
case 0x0c077136u: goto P_0c077136;
case 0x0c077138u: goto P_0c077138;
case 0x0c07713au: goto P_0c07713a;
case 0x0c07713cu: goto P_0c07713c;
case 0x0c07713eu: goto P_0c07713e;
case 0x0c077140u: goto P_0c077140;
case 0x0c077142u: goto P_0c077142;
case 0x0c077144u: goto P_0c077144;
case 0x0c077146u: goto P_0c077146;
case 0x0c077148u: goto P_0c077148;
case 0x0c07714au: goto P_0c07714a;
case 0x0c07714cu: goto P_0c07714c;
case 0x0c07714eu: goto P_0c07714e;
case 0x0c077150u: goto P_0c077150;
case 0x0c077152u: goto P_0c077152;
case 0x0c077154u: goto P_0c077154;
case 0x0c077156u: goto P_0c077156;
case 0x0c077158u: goto P_0c077158;
case 0x0c07715au: goto P_0c07715a;
case 0x0c07715cu: goto P_0c07715c;
case 0x0c07715eu: goto P_0c07715e;
case 0x0c077160u: goto P_0c077160;
case 0x0c077162u: goto P_0c077162;
case 0x0c077164u: goto P_0c077164;
case 0x0c077166u: goto P_0c077166;
case 0x0c077168u: goto P_0c077168;
case 0x0c07716au: goto P_0c07716a;
case 0x0c07716cu: goto P_0c07716c;
case 0x0c07716eu: goto P_0c07716e;
case 0x0c077170u: goto P_0c077170;
case 0x0c077172u: goto P_0c077172;
case 0x0c077174u: goto P_0c077174;
case 0x0c077176u: goto P_0c077176;
case 0x0c077178u: goto P_0c077178;
case 0x0c07717au: goto P_0c07717a;
case 0x0c07717cu: goto P_0c07717c;
case 0x0c07717eu: goto P_0c07717e;
case 0x0c077180u: goto P_0c077180;
case 0x0c077182u: goto P_0c077182;
case 0x0c077184u: goto P_0c077184;
case 0x0c077186u: goto P_0c077186;
case 0x0c077188u: goto P_0c077188;
case 0x0c07718au: goto P_0c07718a;
case 0x0c07718cu: goto P_0c07718c;
case 0x0c07718eu: goto P_0c07718e;
case 0x0c077190u: goto P_0c077190;
case 0x0c0771acu: goto P_0c0771ac;
case 0x0c0771aeu: goto P_0c0771ae;
case 0x0c0771b0u: goto P_0c0771b0;
case 0x0c0771b2u: goto P_0c0771b2;
case 0x0c0771b4u: goto P_0c0771b4;
case 0x0c0771b6u: goto P_0c0771b6;
case 0x0c0771b8u: goto P_0c0771b8;
case 0x0c0771bau: goto P_0c0771ba;
case 0x0c0771bcu: goto P_0c0771bc;
case 0x0c0771beu: goto P_0c0771be;
case 0x0c0771c0u: goto P_0c0771c0;
case 0x0c0771c2u: goto P_0c0771c2;
case 0x0c0771c4u: goto P_0c0771c4;
case 0x0c0771c6u: goto P_0c0771c6;
case 0x0c0771c8u: goto P_0c0771c8;
case 0x0c0771cau: goto P_0c0771ca;
case 0x0c0771ccu: goto P_0c0771cc;
case 0x0c0771ceu: goto P_0c0771ce;
case 0x0c0771d0u: goto P_0c0771d0;
case 0x0c0771d2u: goto P_0c0771d2;
case 0x0c0771d4u: goto P_0c0771d4;
case 0x0c0771d6u: goto P_0c0771d6;
case 0x0c0771d8u: goto P_0c0771d8;
case 0x0c0771dau: goto P_0c0771da;
case 0x0c0771dcu: goto P_0c0771dc;
case 0x0c0771deu: goto P_0c0771de;
case 0x0c0771e0u: goto P_0c0771e0;
case 0x0c0771e2u: goto P_0c0771e2;
case 0x0c0771e4u: goto P_0c0771e4;
case 0x0c0771e6u: goto P_0c0771e6;
case 0x0c0771e8u: goto P_0c0771e8;
case 0x0c0771eau: goto P_0c0771ea;
case 0x0c0771ecu: goto P_0c0771ec;
case 0x0c0771eeu: goto P_0c0771ee;
case 0x0c0771f0u: goto P_0c0771f0;
case 0x0c0771f2u: goto P_0c0771f2;
case 0x0c0771f4u: goto P_0c0771f4;
case 0x0c0771f6u: goto P_0c0771f6;
case 0x0c0771f8u: goto P_0c0771f8;
case 0x0c0771fau: goto P_0c0771fa;
case 0x0c0771fcu: goto P_0c0771fc;
case 0x0c0771feu: goto P_0c0771fe;
case 0x0c077200u: goto P_0c077200;
case 0x0c077202u: goto P_0c077202;
case 0x0c077204u: goto P_0c077204;
case 0x0c077206u: goto P_0c077206;
case 0x0c077208u: goto P_0c077208;
case 0x0c07720au: goto P_0c07720a;
case 0x0c07720cu: goto P_0c07720c;
case 0x0c07720eu: goto P_0c07720e;
case 0x0c077210u: goto P_0c077210;
case 0x0c077212u: goto P_0c077212;
case 0x0c077214u: goto P_0c077214;
case 0x0c077216u: goto P_0c077216;
case 0x0c077218u: goto P_0c077218;
case 0x0c07721au: goto P_0c07721a;
case 0x0c07721cu: goto P_0c07721c;
case 0x0c07721eu: goto P_0c07721e;
case 0x0c077220u: goto P_0c077220;
case 0x0c077222u: goto P_0c077222;
case 0x0c077224u: goto P_0c077224;
case 0x0c077226u: goto P_0c077226;
case 0x0c077228u: goto P_0c077228;
case 0x0c07722au: goto P_0c07722a;
case 0x0c07722cu: goto P_0c07722c;
case 0x0c07722eu: goto P_0c07722e;
case 0x0c077230u: goto P_0c077230;
case 0x0c077232u: goto P_0c077232;
case 0x0c077234u: goto P_0c077234;
case 0x0c077236u: goto P_0c077236;
case 0x0c077238u: goto P_0c077238;
case 0x0c07723au: goto P_0c07723a;
case 0x0c07723cu: goto P_0c07723c;
case 0x0c07723eu: goto P_0c07723e;
case 0x0c077240u: goto P_0c077240;
case 0x0c077242u: goto P_0c077242;
case 0x0c077244u: goto P_0c077244;
case 0x0c077246u: goto P_0c077246;
case 0x0c077248u: goto P_0c077248;
case 0x0c07724au: goto P_0c07724a;
case 0x0c07724cu: goto P_0c07724c;
case 0x0c07724eu: goto P_0c07724e;
case 0x0c077250u: goto P_0c077250;
case 0x0c077252u: goto P_0c077252;
case 0x0c077254u: goto P_0c077254;
case 0x0c077256u: goto P_0c077256;
case 0x0c077258u: goto P_0c077258;
case 0x0c07725au: goto P_0c07725a;
case 0x0c07725cu: goto P_0c07725c;
case 0x0c07725eu: goto P_0c07725e;
case 0x0c077260u: goto P_0c077260;
case 0x0c077262u: goto P_0c077262;
case 0x0c077264u: goto P_0c077264;
case 0x0c077266u: goto P_0c077266;
case 0x0c077268u: goto P_0c077268;
case 0x0c07726au: goto P_0c07726a;
case 0x0c07726cu: goto P_0c07726c;
case 0x0c07726eu: goto P_0c07726e;
case 0x0c077270u: goto P_0c077270;
case 0x0c077272u: goto P_0c077272;
case 0x0c077274u: goto P_0c077274;
case 0x0c077276u: goto P_0c077276;
case 0x0c077278u: goto P_0c077278;
case 0x0c07727au: goto P_0c07727a;
case 0x0c07727cu: goto P_0c07727c;
case 0x0c07727eu: goto P_0c07727e;
case 0x0c077280u: goto P_0c077280;
case 0x0c077282u: goto P_0c077282;
case 0x0c077284u: goto P_0c077284;
case 0x0c077286u: goto P_0c077286;
case 0x0c077288u: goto P_0c077288;
case 0x0c07728au: goto P_0c07728a;
case 0x0c0772a0u: goto P_0c0772a0;
case 0x0c0772a2u: goto P_0c0772a2;
case 0x0c0772a4u: goto P_0c0772a4;
case 0x0c0772a6u: goto P_0c0772a6;
case 0x0c0772a8u: goto P_0c0772a8;
case 0x0c0772aau: goto P_0c0772aa;
case 0x0c0772acu: goto P_0c0772ac;
case 0x0c0772aeu: goto P_0c0772ae;
case 0x0c0772b0u: goto P_0c0772b0;
case 0x0c0772b2u: goto P_0c0772b2;
case 0x0c0772b4u: goto P_0c0772b4;
case 0x0c0772b6u: goto P_0c0772b6;
case 0x0c0772b8u: goto P_0c0772b8;
case 0x0c0772bau: goto P_0c0772ba;
case 0x0c0772bcu: goto P_0c0772bc;
case 0x0c0772beu: goto P_0c0772be;
case 0x0c0772c0u: goto P_0c0772c0;
case 0x0c0772c2u: goto P_0c0772c2;
case 0x0c0772c4u: goto P_0c0772c4;
case 0x0c0772c6u: goto P_0c0772c6;
case 0x0c0772c8u: goto P_0c0772c8;
case 0x0c0772cau: goto P_0c0772ca;
case 0x0c0772ccu: goto P_0c0772cc;
case 0x0c0772ceu: goto P_0c0772ce;
case 0x0c0772d0u: goto P_0c0772d0;
case 0x0c0772d2u: goto P_0c0772d2;
case 0x0c0772d4u: goto P_0c0772d4;
case 0x0c0772d6u: goto P_0c0772d6;
case 0x0c0772d8u: goto P_0c0772d8;
case 0x0c0772dau: goto P_0c0772da;
case 0x0c0772dcu: goto P_0c0772dc;
case 0x0c0772deu: goto P_0c0772de;
case 0x0c0772e0u: goto P_0c0772e0;
case 0x0c0772e2u: goto P_0c0772e2;
case 0x0c0772e4u: goto P_0c0772e4;
case 0x0c0772e6u: goto P_0c0772e6;
case 0x0c0772e8u: goto P_0c0772e8;
case 0x0c0772eau: goto P_0c0772ea;
case 0x0c0772ecu: goto P_0c0772ec;
case 0x0c0772eeu: goto P_0c0772ee;
case 0x0c0772f0u: goto P_0c0772f0;
case 0x0c0772f2u: goto P_0c0772f2;
case 0x0c0772f4u: goto P_0c0772f4;
case 0x0c0772f6u: goto P_0c0772f6;
case 0x0c0772f8u: goto P_0c0772f8;
case 0x0c0772fau: goto P_0c0772fa;
case 0x0c0772fcu: goto P_0c0772fc;
case 0x0c0772feu: goto P_0c0772fe;
case 0x0c077300u: goto P_0c077300;
case 0x0c077302u: goto P_0c077302;
case 0x0c077304u: goto P_0c077304;
case 0x0c077306u: goto P_0c077306;
case 0x0c077308u: goto P_0c077308;
case 0x0c07730au: goto P_0c07730a;
case 0x0c07730cu: goto P_0c07730c;
case 0x0c07730eu: goto P_0c07730e;
case 0x0c077310u: goto P_0c077310;
case 0x0c077312u: goto P_0c077312;
case 0x0c077314u: goto P_0c077314;
case 0x0c077316u: goto P_0c077316;
case 0x0c077318u: goto P_0c077318;
case 0x0c07731au: goto P_0c07731a;
case 0x0c07731cu: goto P_0c07731c;
case 0x0c07731eu: goto P_0c07731e;
case 0x0c077320u: goto P_0c077320;
case 0x0c077322u: goto P_0c077322;
case 0x0c077324u: goto P_0c077324;
case 0x0c077326u: goto P_0c077326;
case 0x0c077328u: goto P_0c077328;
case 0x0c07732au: goto P_0c07732a;
case 0x0c07732cu: goto P_0c07732c;
case 0x0c07732eu: goto P_0c07732e;
case 0x0c077330u: goto P_0c077330;
case 0x0c077332u: goto P_0c077332;
case 0x0c077334u: goto P_0c077334;
case 0x0c077336u: goto P_0c077336;
case 0x0c077338u: goto P_0c077338;
case 0x0c07733au: goto P_0c07733a;
case 0x0c07733cu: goto P_0c07733c;
case 0x0c07734cu: goto P_0c07734c;
case 0x0c07734eu: goto P_0c07734e;
case 0x0c077350u: goto P_0c077350;
case 0x0c077352u: goto P_0c077352;
case 0x0c077354u: goto P_0c077354;
case 0x0c077356u: goto P_0c077356;
case 0x0c077358u: goto P_0c077358;
case 0x0c07735au: goto P_0c07735a;
case 0x0c07735cu: goto P_0c07735c;
case 0x0c07735eu: goto P_0c07735e;
case 0x0c077360u: goto P_0c077360;
case 0x0c077362u: goto P_0c077362;
case 0x0c077364u: goto P_0c077364;
case 0x0c077366u: goto P_0c077366;
case 0x0c077368u: goto P_0c077368;
case 0x0c07736au: goto P_0c07736a;
case 0x0c07736cu: goto P_0c07736c;
case 0x0c07736eu: goto P_0c07736e;
case 0x0c077370u: goto P_0c077370;
case 0x0c077372u: goto P_0c077372;
case 0x0c077374u: goto P_0c077374;
case 0x0c077376u: goto P_0c077376;
case 0x0c077378u: goto P_0c077378;
case 0x0c07737au: goto P_0c07737a;
case 0x0c07737cu: goto P_0c07737c;
case 0x0c07737eu: goto P_0c07737e;
case 0x0c077380u: goto P_0c077380;
case 0x0c077382u: goto P_0c077382;
case 0x0c077384u: goto P_0c077384;
case 0x0c077386u: goto P_0c077386;
case 0x0c077388u: goto P_0c077388;
case 0x0c07738au: goto P_0c07738a;
case 0x0c07738cu: goto P_0c07738c;
case 0x0c07738eu: goto P_0c07738e;
case 0x0c077390u: goto P_0c077390;
case 0x0c077392u: goto P_0c077392;
case 0x0c077394u: goto P_0c077394;
case 0x0c077396u: goto P_0c077396;
case 0x0c077398u: goto P_0c077398;
case 0x0c07739au: goto P_0c07739a;
case 0x0c07739cu: goto P_0c07739c;
case 0x0c07739eu: goto P_0c07739e;
case 0x0c0773a0u: goto P_0c0773a0;
case 0x0c0773a2u: goto P_0c0773a2;
case 0x0c0773a4u: goto P_0c0773a4;
case 0x0c0773a6u: goto P_0c0773a6;
case 0x0c0773a8u: goto P_0c0773a8;
case 0x0c0773aau: goto P_0c0773aa;
case 0x0c0773acu: goto P_0c0773ac;
case 0x0c0773aeu: goto P_0c0773ae;
case 0x0c0773b0u: goto P_0c0773b0;
case 0x0c0773b2u: goto P_0c0773b2;
case 0x0c0773b4u: goto P_0c0773b4;
case 0x0c0773b6u: goto P_0c0773b6;
case 0x0c0773b8u: goto P_0c0773b8;
case 0x0c0773bau: goto P_0c0773ba;
case 0x0c0773bcu: goto P_0c0773bc;
case 0x0c0773beu: goto P_0c0773be;
case 0x0c0773c0u: goto P_0c0773c0;
case 0x0c0773c2u: goto P_0c0773c2;
case 0x0c0773c4u: goto P_0c0773c4;
case 0x0c0773c6u: goto P_0c0773c6;
case 0x0c0773c8u: goto P_0c0773c8;
case 0x0c0773cau: goto P_0c0773ca;
case 0x0c0773ccu: goto P_0c0773cc;
case 0x0c0773ceu: goto P_0c0773ce;
case 0x0c0773d0u: goto P_0c0773d0;
case 0x0c0773d2u: goto P_0c0773d2;
case 0x0c0773d4u: goto P_0c0773d4;
case 0x0c0773d6u: goto P_0c0773d6;
case 0x0c0773d8u: goto P_0c0773d8;
case 0x0c0773dau: goto P_0c0773da;
case 0x0c0773dcu: goto P_0c0773dc;
case 0x0c0773deu: goto P_0c0773de;
case 0x0c0773e0u: goto P_0c0773e0;
case 0x0c0773e2u: goto P_0c0773e2;
case 0x0c0773e4u: goto P_0c0773e4;
case 0x0c0773e6u: goto P_0c0773e6;
case 0x0c0773e8u: goto P_0c0773e8;
case 0x0c0773eau: goto P_0c0773ea;
case 0x0c0773ecu: goto P_0c0773ec;
case 0x0c0773eeu: goto P_0c0773ee;
case 0x0c0773f0u: goto P_0c0773f0;
case 0x0c0773f2u: goto P_0c0773f2;
case 0x0c0773f4u: goto P_0c0773f4;
case 0x0c0773f6u: goto P_0c0773f6;
case 0x0c0773f8u: goto P_0c0773f8;
case 0x0c0773fau: goto P_0c0773fa;
case 0x0c0773fcu: goto P_0c0773fc;
case 0x0c0773feu: goto P_0c0773fe;
case 0x0c077400u: goto P_0c077400;
case 0x0c077402u: goto P_0c077402;
case 0x0c077404u: goto P_0c077404;
case 0x0c077406u: goto P_0c077406;
case 0x0c077408u: goto P_0c077408;
case 0x0c07740au: goto P_0c07740a;
case 0x0c07740cu: goto P_0c07740c;
case 0x0c07740eu: goto P_0c07740e;
case 0x0c077410u: goto P_0c077410;
case 0x0c077412u: goto P_0c077412;
case 0x0c077414u: goto P_0c077414;
case 0x0c077416u: goto P_0c077416;
case 0x0c077418u: goto P_0c077418;
case 0x0c07741au: goto P_0c07741a;
case 0x0c07741cu: goto P_0c07741c;
case 0x0c07741eu: goto P_0c07741e;
case 0x0c077420u: goto P_0c077420;
case 0x0c077422u: goto P_0c077422;
case 0x0c077424u: goto P_0c077424;
case 0x0c077426u: goto P_0c077426;
case 0x0c077428u: goto P_0c077428;
case 0x0c07742au: goto P_0c07742a;
case 0x0c07742cu: goto P_0c07742c;
case 0x0c07742eu: goto P_0c07742e;
case 0x0c077430u: goto P_0c077430;
case 0x0c077432u: goto P_0c077432;
case 0x0c077434u: goto P_0c077434;
case 0x0c077436u: goto P_0c077436;
case 0x0c077438u: goto P_0c077438;
case 0x0c07743au: goto P_0c07743a;
case 0x0c07743cu: goto P_0c07743c;
case 0x0c07743eu: goto P_0c07743e;
case 0x0c077440u: goto P_0c077440;
case 0x0c077442u: goto P_0c077442;
case 0x0c077444u: goto P_0c077444;
case 0x0c077446u: goto P_0c077446;
case 0x0c077448u: goto P_0c077448;
case 0x0c07744au: goto P_0c07744a;
case 0x0c07744cu: goto P_0c07744c;
case 0x0c07746cu: goto P_0c07746c;
case 0x0c07746eu: goto P_0c07746e;
case 0x0c077470u: goto P_0c077470;
case 0x0c077472u: goto P_0c077472;
case 0x0c077474u: goto P_0c077474;
case 0x0c077476u: goto P_0c077476;
case 0x0c077478u: goto P_0c077478;
case 0x0c07747au: goto P_0c07747a;
case 0x0c07747cu: goto P_0c07747c;
case 0x0c07747eu: goto P_0c07747e;
case 0x0c077480u: goto P_0c077480;
case 0x0c077482u: goto P_0c077482;
case 0x0c077484u: goto P_0c077484;
case 0x0c077486u: goto P_0c077486;
case 0x0c077488u: goto P_0c077488;
case 0x0c07748au: goto P_0c07748a;
case 0x0c07748cu: goto P_0c07748c;
case 0x0c07748eu: goto P_0c07748e;
case 0x0c077490u: goto P_0c077490;
case 0x0c077492u: goto P_0c077492;
case 0x0c077494u: goto P_0c077494;
case 0x0c077496u: goto P_0c077496;
case 0x0c077498u: goto P_0c077498;
case 0x0c07749au: goto P_0c07749a;
case 0x0c07749cu: goto P_0c07749c;
case 0x0c07749eu: goto P_0c07749e;
case 0x0c0774a0u: goto P_0c0774a0;
case 0x0c0774a2u: goto P_0c0774a2;
case 0x0c0774a4u: goto P_0c0774a4;
case 0x0c0774a6u: goto P_0c0774a6;
case 0x0c0774a8u: goto P_0c0774a8;
case 0x0c0774aau: goto P_0c0774aa;
case 0x0c0774acu: goto P_0c0774ac;
case 0x0c0774aeu: goto P_0c0774ae;
case 0x0c0774b0u: goto P_0c0774b0;
case 0x0c0774b2u: goto P_0c0774b2;
case 0x0c0774b4u: goto P_0c0774b4;
case 0x0c0774b6u: goto P_0c0774b6;
case 0x0c0774b8u: goto P_0c0774b8;
case 0x0c0774bau: goto P_0c0774ba;
case 0x0c0774bcu: goto P_0c0774bc;
case 0x0c0774beu: goto P_0c0774be;
case 0x0c0774c0u: goto P_0c0774c0;
case 0x0c0774c2u: goto P_0c0774c2;
case 0x0c0774c4u: goto P_0c0774c4;
case 0x0c0774c6u: goto P_0c0774c6;
case 0x0c0774c8u: goto P_0c0774c8;
case 0x0c0774cau: goto P_0c0774ca;
case 0x0c0774ccu: goto P_0c0774cc;
case 0x0c0774ceu: goto P_0c0774ce;
case 0x0c0774d0u: goto P_0c0774d0;
case 0x0c0774d2u: goto P_0c0774d2;
case 0x0c0774d4u: goto P_0c0774d4;
case 0x0c0774d6u: goto P_0c0774d6;
case 0x0c0774d8u: goto P_0c0774d8;
case 0x0c0774dau: goto P_0c0774da;
case 0x0c0774dcu: goto P_0c0774dc;
case 0x0c0774deu: goto P_0c0774de;
case 0x0c0774e0u: goto P_0c0774e0;
case 0x0c0774e2u: goto P_0c0774e2;
case 0x0c0774e4u: goto P_0c0774e4;
case 0x0c0774e6u: goto P_0c0774e6;
case 0x0c0774e8u: goto P_0c0774e8;
case 0x0c0774eau: goto P_0c0774ea;
case 0x0c0774ecu: goto P_0c0774ec;
case 0x0c0774eeu: goto P_0c0774ee;
case 0x0c0774f0u: goto P_0c0774f0;
case 0x0c0774f2u: goto P_0c0774f2;
case 0x0c0774f4u: goto P_0c0774f4;
case 0x0c0774f6u: goto P_0c0774f6;
case 0x0c0774f8u: goto P_0c0774f8;
case 0x0c0774fau: goto P_0c0774fa;
case 0x0c0774fcu: goto P_0c0774fc;
case 0x0c0774feu: goto P_0c0774fe;
case 0x0c077500u: goto P_0c077500;
case 0x0c077502u: goto P_0c077502;
case 0x0c077504u: goto P_0c077504;
case 0x0c077506u: goto P_0c077506;
case 0x0c077508u: goto P_0c077508;
case 0x0c07750au: goto P_0c07750a;
case 0x0c07750cu: goto P_0c07750c;
case 0x0c07750eu: goto P_0c07750e;
case 0x0c077510u: goto P_0c077510;
case 0x0c077512u: goto P_0c077512;
case 0x0c077514u: goto P_0c077514;
case 0x0c077516u: goto P_0c077516;
case 0x0c077518u: goto P_0c077518;
case 0x0c07751au: goto P_0c07751a;
case 0x0c07751cu: goto P_0c07751c;
case 0x0c07751eu: goto P_0c07751e;
case 0x0c077520u: goto P_0c077520;
case 0x0c077522u: goto P_0c077522;
case 0x0c077524u: goto P_0c077524;
case 0x0c077526u: goto P_0c077526;
case 0x0c077528u: goto P_0c077528;
case 0x0c07752au: goto P_0c07752a;
case 0x0c07752cu: goto P_0c07752c;
case 0x0c07752eu: goto P_0c07752e;
case 0x0c077530u: goto P_0c077530;
case 0x0c077532u: goto P_0c077532;
case 0x0c077534u: goto P_0c077534;
case 0x0c077536u: goto P_0c077536;
case 0x0c077538u: goto P_0c077538;
case 0x0c07753au: goto P_0c07753a;
case 0x0c07753cu: goto P_0c07753c;
case 0x0c07753eu: goto P_0c07753e;
case 0x0c077540u: goto P_0c077540;
case 0x0c077542u: goto P_0c077542;
case 0x0c077544u: goto P_0c077544;
case 0x0c077546u: goto P_0c077546;
case 0x0c077548u: goto P_0c077548;
case 0x0c07754au: goto P_0c07754a;
case 0x0c07754cu: goto P_0c07754c;
case 0x0c07754eu: goto P_0c07754e;
case 0x0c077550u: goto P_0c077550;
case 0x0c077552u: goto P_0c077552;
case 0x0c077554u: goto P_0c077554;
case 0x0c077556u: goto P_0c077556;
case 0x0c077558u: goto P_0c077558;
case 0x0c07755au: goto P_0c07755a;
case 0x0c07755cu: goto P_0c07755c;
case 0x0c07755eu: goto P_0c07755e;
case 0x0c077560u: goto P_0c077560;
case 0x0c077562u: goto P_0c077562;
case 0x0c077564u: goto P_0c077564;
case 0x0c077566u: goto P_0c077566;
case 0x0c077568u: goto P_0c077568;
case 0x0c07756au: goto P_0c07756a;
case 0x0c077584u: goto P_0c077584;
case 0x0c077586u: goto P_0c077586;
case 0x0c077588u: goto P_0c077588;
case 0x0c07758au: goto P_0c07758a;
case 0x0c07758cu: goto P_0c07758c;
case 0x0c07758eu: goto P_0c07758e;
case 0x0c077590u: goto P_0c077590;
case 0x0c077592u: goto P_0c077592;
case 0x0c077594u: goto P_0c077594;
case 0x0c077596u: goto P_0c077596;
case 0x0c077598u: goto P_0c077598;
case 0x0c07759au: goto P_0c07759a;
case 0x0c07759cu: goto P_0c07759c;
case 0x0c07759eu: goto P_0c07759e;
case 0x0c0775a0u: goto P_0c0775a0;
case 0x0c0775a2u: goto P_0c0775a2;
case 0x0c0775a4u: goto P_0c0775a4;
case 0x0c0775a6u: goto P_0c0775a6;
case 0x0c0775a8u: goto P_0c0775a8;
case 0x0c0775aau: goto P_0c0775aa;
case 0x0c0775acu: goto P_0c0775ac;
case 0x0c0775aeu: goto P_0c0775ae;
case 0x0c0775b0u: goto P_0c0775b0;
case 0x0c0775b2u: goto P_0c0775b2;
case 0x0c0775b4u: goto P_0c0775b4;
case 0x0c0775b6u: goto P_0c0775b6;
case 0x0c0775b8u: goto P_0c0775b8;
case 0x0c0775bau: goto P_0c0775ba;
case 0x0c0775bcu: goto P_0c0775bc;
case 0x0c0775beu: goto P_0c0775be;
case 0x0c0775c0u: goto P_0c0775c0;
case 0x0c0775c2u: goto P_0c0775c2;
case 0x0c0775c4u: goto P_0c0775c4;
case 0x0c0775c6u: goto P_0c0775c6;
case 0x0c0775c8u: goto P_0c0775c8;
case 0x0c0775cau: goto P_0c0775ca;
case 0x0c0775ccu: goto P_0c0775cc;
case 0x0c0775ceu: goto P_0c0775ce;
case 0x0c0775d0u: goto P_0c0775d0;
case 0x0c0775d2u: goto P_0c0775d2;
case 0x0c0775d4u: goto P_0c0775d4;
case 0x0c0775d6u: goto P_0c0775d6;
case 0x0c0775d8u: goto P_0c0775d8;
case 0x0c0775dau: goto P_0c0775da;
case 0x0c0775dcu: goto P_0c0775dc;
case 0x0c0775deu: goto P_0c0775de;
case 0x0c0775e0u: goto P_0c0775e0;
case 0x0c0775e2u: goto P_0c0775e2;
case 0x0c0775e4u: goto P_0c0775e4;
case 0x0c0775e6u: goto P_0c0775e6;
case 0x0c0775e8u: goto P_0c0775e8;
case 0x0c0775eau: goto P_0c0775ea;
case 0x0c0775ecu: goto P_0c0775ec;
case 0x0c0775eeu: goto P_0c0775ee;
case 0x0c0775f0u: goto P_0c0775f0;
case 0x0c0775f2u: goto P_0c0775f2;
case 0x0c0775f4u: goto P_0c0775f4;
case 0x0c0775f6u: goto P_0c0775f6;
case 0x0c0775f8u: goto P_0c0775f8;
case 0x0c0775fau: goto P_0c0775fa;
case 0x0c0775fcu: goto P_0c0775fc;
case 0x0c077614u: goto P_0c077614;
case 0x0c077616u: goto P_0c077616;
case 0x0c077618u: goto P_0c077618;
case 0x0c07761au: goto P_0c07761a;
case 0x0c07761cu: goto P_0c07761c;
case 0x0c07761eu: goto P_0c07761e;
case 0x0c077620u: goto P_0c077620;
case 0x0c077622u: goto P_0c077622;
case 0x0c077624u: goto P_0c077624;
case 0x0c077626u: goto P_0c077626;
case 0x0c077628u: goto P_0c077628;
case 0x0c07762au: goto P_0c07762a;
case 0x0c07762cu: goto P_0c07762c;
case 0x0c07762eu: goto P_0c07762e;
case 0x0c077630u: goto P_0c077630;
case 0x0c077632u: goto P_0c077632;
case 0x0c077634u: goto P_0c077634;
case 0x0c077636u: goto P_0c077636;
case 0x0c077638u: goto P_0c077638;
case 0x0c07763au: goto P_0c07763a;
case 0x0c07763cu: goto P_0c07763c;
case 0x0c07763eu: goto P_0c07763e;
case 0x0c077640u: goto P_0c077640;
case 0x0c077642u: goto P_0c077642;
case 0x0c077644u: goto P_0c077644;
case 0x0c077646u: goto P_0c077646;
case 0x0c077648u: goto P_0c077648;
case 0x0c07764au: goto P_0c07764a;
case 0x0c07764cu: goto P_0c07764c;
case 0x0c07764eu: goto P_0c07764e;
case 0x0c077650u: goto P_0c077650;
case 0x0c077652u: goto P_0c077652;
case 0x0c077654u: goto P_0c077654;
case 0x0c077656u: goto P_0c077656;
case 0x0c077658u: goto P_0c077658;
case 0x0c07765au: goto P_0c07765a;
case 0x0c07765cu: goto P_0c07765c;
case 0x0c07765eu: goto P_0c07765e;
case 0x0c077660u: goto P_0c077660;
case 0x0c077662u: goto P_0c077662;
case 0x0c077664u: goto P_0c077664;
case 0x0c077666u: goto P_0c077666;
case 0x0c077668u: goto P_0c077668;
case 0x0c07766au: goto P_0c07766a;
case 0x0c07766cu: goto P_0c07766c;
case 0x0c07766eu: goto P_0c07766e;
case 0x0c077670u: goto P_0c077670;
case 0x0c077672u: goto P_0c077672;
case 0x0c077674u: goto P_0c077674;
case 0x0c077676u: goto P_0c077676;
case 0x0c077678u: goto P_0c077678;
case 0x0c07767au: goto P_0c07767a;
case 0x0c07767cu: goto P_0c07767c;
case 0x0c07767eu: goto P_0c07767e;
case 0x0c077680u: goto P_0c077680;
case 0x0c077682u: goto P_0c077682;
case 0x0c077684u: goto P_0c077684;
case 0x0c077686u: goto P_0c077686;
case 0x0c077688u: goto P_0c077688;
case 0x0c07768au: goto P_0c07768a;
case 0x0c07768cu: goto P_0c07768c;
case 0x0c07768eu: goto P_0c07768e;
case 0x0c077690u: goto P_0c077690;
case 0x0c077692u: goto P_0c077692;
case 0x0c077694u: goto P_0c077694;
case 0x0c077696u: goto P_0c077696;
case 0x0c077698u: goto P_0c077698;
case 0x0c07769au: goto P_0c07769a;
case 0x0c07769cu: goto P_0c07769c;
case 0x0c07769eu: goto P_0c07769e;
case 0x0c0776a0u: goto P_0c0776a0;
case 0x0c0776a2u: goto P_0c0776a2;
case 0x0c0776a4u: goto P_0c0776a4;
case 0x0c0776a6u: goto P_0c0776a6;
case 0x0c0776a8u: goto P_0c0776a8;
case 0x0c0776aau: goto P_0c0776aa;
case 0x0c0776acu: goto P_0c0776ac;
case 0x0c0776aeu: goto P_0c0776ae;
case 0x0c0776b0u: goto P_0c0776b0;
case 0x0c0776b2u: goto P_0c0776b2;
case 0x0c0776b4u: goto P_0c0776b4;
case 0x0c0776b6u: goto P_0c0776b6;
case 0x0c0776b8u: goto P_0c0776b8;
case 0x0c0776bau: goto P_0c0776ba;
case 0x0c0776bcu: goto P_0c0776bc;
case 0x0c0776beu: goto P_0c0776be;
case 0x0c0776c0u: goto P_0c0776c0;
case 0x0c0776c2u: goto P_0c0776c2;
case 0x0c0776c4u: goto P_0c0776c4;
case 0x0c0776c6u: goto P_0c0776c6;
case 0x0c0776c8u: goto P_0c0776c8;
case 0x0c0776cau: goto P_0c0776ca;
case 0x0c0776ccu: goto P_0c0776cc;
case 0x0c0776ceu: goto P_0c0776ce;
case 0x0c0776d0u: goto P_0c0776d0;
case 0x0c0776d2u: goto P_0c0776d2;
case 0x0c0776d4u: goto P_0c0776d4;
case 0x0c0776d6u: goto P_0c0776d6;
case 0x0c0776d8u: goto P_0c0776d8;
case 0x0c0776dau: goto P_0c0776da;
case 0x0c0776dcu: goto P_0c0776dc;
case 0x0c0776deu: goto P_0c0776de;
case 0x0c0776e0u: goto P_0c0776e0;
case 0x0c0776e2u: goto P_0c0776e2;
case 0x0c0776e4u: goto P_0c0776e4;
case 0x0c0776e6u: goto P_0c0776e6;
case 0x0c0776e8u: goto P_0c0776e8;
case 0x0c0776eau: goto P_0c0776ea;
case 0x0c0776ecu: goto P_0c0776ec;
case 0x0c0776eeu: goto P_0c0776ee;
case 0x0c0776f0u: goto P_0c0776f0;
case 0x0c0776f2u: goto P_0c0776f2;
case 0x0c0776f4u: goto P_0c0776f4;
case 0x0c0776f6u: goto P_0c0776f6;
case 0x0c0776f8u: goto P_0c0776f8;
case 0x0c0776fau: goto P_0c0776fa;
case 0x0c0776fcu: goto P_0c0776fc;
case 0x0c0776feu: goto P_0c0776fe;
case 0x0c077700u: goto P_0c077700;
case 0x0c077702u: goto P_0c077702;
case 0x0c077704u: goto P_0c077704;
case 0x0c077706u: goto P_0c077706;
case 0x0c077708u: goto P_0c077708;
case 0x0c07770au: goto P_0c07770a;
case 0x0c07770cu: goto P_0c07770c;
case 0x0c07770eu: goto P_0c07770e;
case 0x0c077710u: goto P_0c077710;
case 0x0c077712u: goto P_0c077712;
case 0x0c077714u: goto P_0c077714;
case 0x0c077716u: goto P_0c077716;
case 0x0c077718u: goto P_0c077718;
case 0x0c07771au: goto P_0c07771a;
case 0x0c07771cu: goto P_0c07771c;
case 0x0c07771eu: goto P_0c07771e;
case 0x0c077720u: goto P_0c077720;
case 0x0c077722u: goto P_0c077722;
case 0x0c077724u: goto P_0c077724;
case 0x0c077726u: goto P_0c077726;
case 0x0c077728u: goto P_0c077728;
case 0x0c07772au: goto P_0c07772a;
case 0x0c07772cu: goto P_0c07772c;
case 0x0c07772eu: goto P_0c07772e;
case 0x0c077730u: goto P_0c077730;
case 0x0c077732u: goto P_0c077732;
case 0x0c077734u: goto P_0c077734;
case 0x0c077736u: goto P_0c077736;
case 0x0c077738u: goto P_0c077738;
case 0x0c07773au: goto P_0c07773a;
case 0x0c07773cu: goto P_0c07773c;
case 0x0c07773eu: goto P_0c07773e;
case 0x0c077740u: goto P_0c077740;
case 0x0c077742u: goto P_0c077742;
case 0x0c077744u: goto P_0c077744;
case 0x0c077746u: goto P_0c077746;
case 0x0c077748u: goto P_0c077748;
case 0x0c07774au: goto P_0c07774a;
case 0x0c07774cu: goto P_0c07774c;
case 0x0c07774eu: goto P_0c07774e;
case 0x0c077750u: goto P_0c077750;
case 0x0c077752u: goto P_0c077752;
case 0x0c077754u: goto P_0c077754;
case 0x0c077756u: goto P_0c077756;
case 0x0c077758u: goto P_0c077758;
case 0x0c07775au: goto P_0c07775a;
case 0x0c07775cu: goto P_0c07775c;
case 0x0c07775eu: goto P_0c07775e;
case 0x0c077760u: goto P_0c077760;
case 0x0c077762u: goto P_0c077762;
case 0x0c077764u: goto P_0c077764;
case 0x0c077784u: goto P_0c077784;
case 0x0c077786u: goto P_0c077786;
case 0x0c077788u: goto P_0c077788;
case 0x0c07778au: goto P_0c07778a;
case 0x0c07778cu: goto P_0c07778c;
case 0x0c07778eu: goto P_0c07778e;
case 0x0c077790u: goto P_0c077790;
case 0x0c077792u: goto P_0c077792;
case 0x0c077794u: goto P_0c077794;
case 0x0c077796u: goto P_0c077796;
case 0x0c077798u: goto P_0c077798;
case 0x0c07779au: goto P_0c07779a;
case 0x0c07779cu: goto P_0c07779c;
case 0x0c07779eu: goto P_0c07779e;
case 0x0c0777a0u: goto P_0c0777a0;
case 0x0c0777a2u: goto P_0c0777a2;
case 0x0c0777a4u: goto P_0c0777a4;
case 0x0c0777a6u: goto P_0c0777a6;
case 0x0c0777a8u: goto P_0c0777a8;
case 0x0c0777aau: goto P_0c0777aa;
case 0x0c0777acu: goto P_0c0777ac;
case 0x0c0777aeu: goto P_0c0777ae;
case 0x0c0777b0u: goto P_0c0777b0;
case 0x0c0777b2u: goto P_0c0777b2;
case 0x0c0777b4u: goto P_0c0777b4;
case 0x0c0777b6u: goto P_0c0777b6;
case 0x0c0777b8u: goto P_0c0777b8;
case 0x0c0777bau: goto P_0c0777ba;
case 0x0c0777bcu: goto P_0c0777bc;
case 0x0c0777beu: goto P_0c0777be;
case 0x0c0777c0u: goto P_0c0777c0;
case 0x0c0777c2u: goto P_0c0777c2;
case 0x0c0777c4u: goto P_0c0777c4;
case 0x0c0777c6u: goto P_0c0777c6;
case 0x0c0777c8u: goto P_0c0777c8;
case 0x0c0777cau: goto P_0c0777ca;
case 0x0c0777ccu: goto P_0c0777cc;
case 0x0c0777ceu: goto P_0c0777ce;
case 0x0c0777d0u: goto P_0c0777d0;
case 0x0c0777d2u: goto P_0c0777d2;
case 0x0c0777d4u: goto P_0c0777d4;
case 0x0c0777d6u: goto P_0c0777d6;
case 0x0c0777d8u: goto P_0c0777d8;
case 0x0c0777dau: goto P_0c0777da;
case 0x0c0777dcu: goto P_0c0777dc;
case 0x0c0777deu: goto P_0c0777de;
case 0x0c0777e0u: goto P_0c0777e0;
case 0x0c0777e2u: goto P_0c0777e2;
case 0x0c0777e4u: goto P_0c0777e4;
case 0x0c0777e6u: goto P_0c0777e6;
case 0x0c0777e8u: goto P_0c0777e8;
case 0x0c0777eau: goto P_0c0777ea;
case 0x0c0777ecu: goto P_0c0777ec;
case 0x0c0777eeu: goto P_0c0777ee;
case 0x0c0777f0u: goto P_0c0777f0;
case 0x0c0777f2u: goto P_0c0777f2;
case 0x0c0777f4u: goto P_0c0777f4;
case 0x0c0777f6u: goto P_0c0777f6;
case 0x0c0777f8u: goto P_0c0777f8;
case 0x0c0777fau: goto P_0c0777fa;
case 0x0c0777fcu: goto P_0c0777fc;
case 0x0c0777feu: goto P_0c0777fe;
case 0x0c077800u: goto P_0c077800;
case 0x0c077802u: goto P_0c077802;
case 0x0c077804u: goto P_0c077804;
case 0x0c077806u: goto P_0c077806;
case 0x0c077808u: goto P_0c077808;
case 0x0c07780au: goto P_0c07780a;
case 0x0c07780cu: goto P_0c07780c;
case 0x0c07780eu: goto P_0c07780e;
case 0x0c077810u: goto P_0c077810;
case 0x0c077812u: goto P_0c077812;
case 0x0c077814u: goto P_0c077814;
case 0x0c077816u: goto P_0c077816;
case 0x0c077818u: goto P_0c077818;
case 0x0c07781au: goto P_0c07781a;
case 0x0c07781cu: goto P_0c07781c;
case 0x0c07781eu: goto P_0c07781e;
case 0x0c077820u: goto P_0c077820;
case 0x0c077822u: goto P_0c077822;
case 0x0c077824u: goto P_0c077824;
case 0x0c077826u: goto P_0c077826;
case 0x0c077828u: goto P_0c077828;
case 0x0c07782au: goto P_0c07782a;
case 0x0c07782cu: goto P_0c07782c;
case 0x0c07782eu: goto P_0c07782e;
case 0x0c077830u: goto P_0c077830;
case 0x0c077832u: goto P_0c077832;
case 0x0c077834u: goto P_0c077834;
case 0x0c077836u: goto P_0c077836;
case 0x0c077838u: goto P_0c077838;
case 0x0c07783au: goto P_0c07783a;
case 0x0c07783cu: goto P_0c07783c;
case 0x0c07783eu: goto P_0c07783e;
case 0x0c077840u: goto P_0c077840;
case 0x0c077842u: goto P_0c077842;
case 0x0c077844u: goto P_0c077844;
case 0x0c077846u: goto P_0c077846;
case 0x0c077848u: goto P_0c077848;
case 0x0c07784au: goto P_0c07784a;
case 0x0c07784cu: goto P_0c07784c;
case 0x0c07784eu: goto P_0c07784e;
case 0x0c077850u: goto P_0c077850;
case 0x0c077852u: goto P_0c077852;
case 0x0c077854u: goto P_0c077854;
case 0x0c077856u: goto P_0c077856;
case 0x0c077858u: goto P_0c077858;
case 0x0c07785au: goto P_0c07785a;
case 0x0c07785cu: goto P_0c07785c;
case 0x0c07785eu: goto P_0c07785e;
case 0x0c077860u: goto P_0c077860;
case 0x0c077862u: goto P_0c077862;
case 0x0c077864u: goto P_0c077864;
case 0x0c077866u: goto P_0c077866;
case 0x0c077868u: goto P_0c077868;
case 0x0c07786au: goto P_0c07786a;
case 0x0c07786cu: goto P_0c07786c;
case 0x0c07786eu: goto P_0c07786e;
case 0x0c077870u: goto P_0c077870;
case 0x0c077872u: goto P_0c077872;
case 0x0c077874u: goto P_0c077874;
case 0x0c077876u: goto P_0c077876;
case 0x0c077878u: goto P_0c077878;
case 0x0c07787au: goto P_0c07787a;
case 0x0c07787cu: goto P_0c07787c;
case 0x0c07787eu: goto P_0c07787e;
case 0x0c077880u: goto P_0c077880;
case 0x0c077882u: goto P_0c077882;
case 0x0c077884u: goto P_0c077884;
case 0x0c077886u: goto P_0c077886;
case 0x0c077888u: goto P_0c077888;
case 0x0c07788au: goto P_0c07788a;
case 0x0c0778a4u: goto P_0c0778a4;
case 0x0c0778a6u: goto P_0c0778a6;
case 0x0c0778a8u: goto P_0c0778a8;
case 0x0c0778aau: goto P_0c0778aa;
case 0x0c0778acu: goto P_0c0778ac;
case 0x0c0778aeu: goto P_0c0778ae;
case 0x0c0778b0u: goto P_0c0778b0;
case 0x0c0778b2u: goto P_0c0778b2;
case 0x0c0778b4u: goto P_0c0778b4;
case 0x0c0778b6u: goto P_0c0778b6;
case 0x0c0778b8u: goto P_0c0778b8;
case 0x0c0778bau: goto P_0c0778ba;
case 0x0c0778bcu: goto P_0c0778bc;
case 0x0c0778beu: goto P_0c0778be;
case 0x0c0778c0u: goto P_0c0778c0;
case 0x0c0778c2u: goto P_0c0778c2;
case 0x0c0778c4u: goto P_0c0778c4;
case 0x0c0778c6u: goto P_0c0778c6;
case 0x0c0778c8u: goto P_0c0778c8;
case 0x0c0778cau: goto P_0c0778ca;
case 0x0c0778ccu: goto P_0c0778cc;
case 0x0c0778ceu: goto P_0c0778ce;
case 0x0c0778d0u: goto P_0c0778d0;
case 0x0c0778d2u: goto P_0c0778d2;
case 0x0c0778d4u: goto P_0c0778d4;
case 0x0c0778d6u: goto P_0c0778d6;
case 0x0c0778d8u: goto P_0c0778d8;
case 0x0c0778dau: goto P_0c0778da;
case 0x0c0778dcu: goto P_0c0778dc;
case 0x0c0778deu: goto P_0c0778de;
case 0x0c0778e0u: goto P_0c0778e0;
case 0x0c0778e2u: goto P_0c0778e2;
case 0x0c0778e4u: goto P_0c0778e4;
case 0x0c0778e6u: goto P_0c0778e6;
case 0x0c0778e8u: goto P_0c0778e8;
case 0x0c0778eau: goto P_0c0778ea;
case 0x0c0778ecu: goto P_0c0778ec;
case 0x0c0778eeu: goto P_0c0778ee;
case 0x0c0778f0u: goto P_0c0778f0;
case 0x0c0778f2u: goto P_0c0778f2;
case 0x0c0778f4u: goto P_0c0778f4;
case 0x0c0778f6u: goto P_0c0778f6;
case 0x0c0778f8u: goto P_0c0778f8;
case 0x0c0778fau: goto P_0c0778fa;
case 0x0c0778fcu: goto P_0c0778fc;
case 0x0c0778feu: goto P_0c0778fe;
case 0x0c077900u: goto P_0c077900;
case 0x0c077902u: goto P_0c077902;
case 0x0c077904u: goto P_0c077904;
case 0x0c077906u: goto P_0c077906;
case 0x0c077908u: goto P_0c077908;
case 0x0c07790au: goto P_0c07790a;
case 0x0c07790cu: goto P_0c07790c;
case 0x0c07790eu: goto P_0c07790e;
case 0x0c077910u: goto P_0c077910;
case 0x0c077912u: goto P_0c077912;
case 0x0c077914u: goto P_0c077914;
case 0x0c077916u: goto P_0c077916;
case 0x0c077918u: goto P_0c077918;
case 0x0c07791au: goto P_0c07791a;
case 0x0c07791cu: goto P_0c07791c;
case 0x0c07791eu: goto P_0c07791e;
case 0x0c077920u: goto P_0c077920;
case 0x0c077922u: goto P_0c077922;
case 0x0c077924u: goto P_0c077924;
case 0x0c077926u: goto P_0c077926;
case 0x0c077928u: goto P_0c077928;
case 0x0c07792au: goto P_0c07792a;
case 0x0c07792cu: goto P_0c07792c;
case 0x0c07792eu: goto P_0c07792e;
case 0x0c077930u: goto P_0c077930;
case 0x0c077932u: goto P_0c077932;
case 0x0c077934u: goto P_0c077934;
case 0x0c077936u: goto P_0c077936;
case 0x0c077938u: goto P_0c077938;
case 0x0c07793au: goto P_0c07793a;
case 0x0c07793cu: goto P_0c07793c;
case 0x0c07793eu: goto P_0c07793e;
case 0x0c077940u: goto P_0c077940;
case 0x0c077942u: goto P_0c077942;
case 0x0c077944u: goto P_0c077944;
case 0x0c077946u: goto P_0c077946;
case 0x0c077948u: goto P_0c077948;
case 0x0c07794au: goto P_0c07794a;
case 0x0c07794cu: goto P_0c07794c;
case 0x0c07794eu: goto P_0c07794e;
case 0x0c077950u: goto P_0c077950;
case 0x0c077952u: goto P_0c077952;
case 0x0c077954u: goto P_0c077954;
case 0x0c077956u: goto P_0c077956;
case 0x0c077958u: goto P_0c077958;
case 0x0c07795au: goto P_0c07795a;
case 0x0c07795cu: goto P_0c07795c;
case 0x0c07795eu: goto P_0c07795e;
case 0x0c077960u: goto P_0c077960;
case 0x0c077962u: goto P_0c077962;
case 0x0c077964u: goto P_0c077964;
case 0x0c077966u: goto P_0c077966;
case 0x0c077968u: goto P_0c077968;
case 0x0c07796au: goto P_0c07796a;
case 0x0c07796cu: goto P_0c07796c;
case 0x0c07796eu: goto P_0c07796e;
case 0x0c077970u: goto P_0c077970;
case 0x0c077972u: goto P_0c077972;
case 0x0c077974u: goto P_0c077974;
case 0x0c077976u: goto P_0c077976;
case 0x0c077978u: goto P_0c077978;
case 0x0c07797au: goto P_0c07797a;
case 0x0c07797cu: goto P_0c07797c;
case 0x0c07797eu: goto P_0c07797e;
case 0x0c077980u: goto P_0c077980;
case 0x0c077998u: goto P_0c077998;
case 0x0c07799au: goto P_0c07799a;
case 0x0c07799cu: goto P_0c07799c;
case 0x0c07799eu: goto P_0c07799e;
case 0x0c0779a0u: goto P_0c0779a0;
case 0x0c0779a2u: goto P_0c0779a2;
case 0x0c0779a4u: goto P_0c0779a4;
case 0x0c0779a6u: goto P_0c0779a6;
case 0x0c0779a8u: goto P_0c0779a8;
case 0x0c0779aau: goto P_0c0779aa;
case 0x0c0779acu: goto P_0c0779ac;
case 0x0c0779aeu: goto P_0c0779ae;
case 0x0c0779b0u: goto P_0c0779b0;
case 0x0c0779b2u: goto P_0c0779b2;
case 0x0c0779b4u: goto P_0c0779b4;
case 0x0c0779b6u: goto P_0c0779b6;
case 0x0c0779b8u: goto P_0c0779b8;
case 0x0c0779bau: goto P_0c0779ba;
case 0x0c0779bcu: goto P_0c0779bc;
case 0x0c0779beu: goto P_0c0779be;
case 0x0c0779c0u: goto P_0c0779c0;
case 0x0c0779c2u: goto P_0c0779c2;
case 0x0c0779c4u: goto P_0c0779c4;
case 0x0c0779c6u: goto P_0c0779c6;
case 0x0c0779c8u: goto P_0c0779c8;
case 0x0c0779cau: goto P_0c0779ca;
case 0x0c0779ccu: goto P_0c0779cc;
case 0x0c0779ceu: goto P_0c0779ce;
case 0x0c0779d0u: goto P_0c0779d0;
case 0x0c0779d2u: goto P_0c0779d2;
case 0x0c0779d4u: goto P_0c0779d4;
case 0x0c0779d6u: goto P_0c0779d6;
case 0x0c0779d8u: goto P_0c0779d8;
case 0x0c0779dau: goto P_0c0779da;
case 0x0c0779dcu: goto P_0c0779dc;
case 0x0c0779deu: goto P_0c0779de;
case 0x0c0779e0u: goto P_0c0779e0;
case 0x0c0779e2u: goto P_0c0779e2;
case 0x0c0779e4u: goto P_0c0779e4;
case 0x0c0779e6u: goto P_0c0779e6;
case 0x0c0779e8u: goto P_0c0779e8;
case 0x0c0779eau: goto P_0c0779ea;
case 0x0c0779ecu: goto P_0c0779ec;
case 0x0c0779eeu: goto P_0c0779ee;
case 0x0c0779f0u: goto P_0c0779f0;
case 0x0c0779f2u: goto P_0c0779f2;
case 0x0c0779f4u: goto P_0c0779f4;
case 0x0c0779f6u: goto P_0c0779f6;
case 0x0c0779f8u: goto P_0c0779f8;
case 0x0c0779fau: goto P_0c0779fa;
case 0x0c0779fcu: goto P_0c0779fc;
case 0x0c0779feu: goto P_0c0779fe;
case 0x0c077a00u: goto P_0c077a00;
case 0x0c077a02u: goto P_0c077a02;
case 0x0c077a04u: goto P_0c077a04;
case 0x0c077a06u: goto P_0c077a06;
case 0x0c077a08u: goto P_0c077a08;
case 0x0c077a0au: goto P_0c077a0a;
case 0x0c077a0cu: goto P_0c077a0c;
case 0x0c077a0eu: goto P_0c077a0e;
case 0x0c077a10u: goto P_0c077a10;
case 0x0c077a12u: goto P_0c077a12;
case 0x0c077a14u: goto P_0c077a14;
case 0x0c077a16u: goto P_0c077a16;
case 0x0c077a18u: goto P_0c077a18;
case 0x0c077a1au: goto P_0c077a1a;
case 0x0c077a1cu: goto P_0c077a1c;
case 0x0c077a1eu: goto P_0c077a1e;
case 0x0c077a20u: goto P_0c077a20;
case 0x0c077a22u: goto P_0c077a22;
case 0x0c077a24u: goto P_0c077a24;
case 0x0c077a26u: goto P_0c077a26;
case 0x0c077a28u: goto P_0c077a28;
case 0x0c077a2au: goto P_0c077a2a;
case 0x0c077a2cu: goto P_0c077a2c;
case 0x0c077a2eu: goto P_0c077a2e;
case 0x0c077a30u: goto P_0c077a30;
case 0x0c077a32u: goto P_0c077a32;
case 0x0c077a34u: goto P_0c077a34;
case 0x0c077a36u: goto P_0c077a36;
case 0x0c077a38u: goto P_0c077a38;
case 0x0c077a3au: goto P_0c077a3a;
case 0x0c077a3cu: goto P_0c077a3c;
case 0x0c077a3eu: goto P_0c077a3e;
case 0x0c077a40u: goto P_0c077a40;
case 0x0c077a42u: goto P_0c077a42;
case 0x0c077a44u: goto P_0c077a44;
case 0x0c077a46u: goto P_0c077a46;
case 0x0c077a48u: goto P_0c077a48;
case 0x0c077a4au: goto P_0c077a4a;
case 0x0c077a4cu: goto P_0c077a4c;
case 0x0c077a4eu: goto P_0c077a4e;
case 0x0c077a50u: goto P_0c077a50;
case 0x0c077a52u: goto P_0c077a52;
case 0x0c077a54u: goto P_0c077a54;
case 0x0c077a56u: goto P_0c077a56;
case 0x0c077a58u: goto P_0c077a58;
case 0x0c077a5au: goto P_0c077a5a;
case 0x0c077a5cu: goto P_0c077a5c;
case 0x0c077a5eu: goto P_0c077a5e;
case 0x0c077a60u: goto P_0c077a60;
case 0x0c077a62u: goto P_0c077a62;
case 0x0c077a64u: goto P_0c077a64;
case 0x0c077a66u: goto P_0c077a66;
case 0x0c077a68u: goto P_0c077a68;
case 0x0c077a6au: goto P_0c077a6a;
case 0x0c077a6cu: goto P_0c077a6c;
case 0x0c077a6eu: goto P_0c077a6e;
case 0x0c077a70u: goto P_0c077a70;
case 0x0c077a72u: goto P_0c077a72;
case 0x0c077a74u: goto P_0c077a74;
case 0x0c077a76u: goto P_0c077a76;
case 0x0c077a78u: goto P_0c077a78;
case 0x0c077a7au: goto P_0c077a7a;
case 0x0c077a7cu: goto P_0c077a7c;
case 0x0c077a7eu: goto P_0c077a7e;
case 0x0c077a80u: goto P_0c077a80;
case 0x0c077a82u: goto P_0c077a82;
case 0x0c077a84u: goto P_0c077a84;
case 0x0c077a86u: goto P_0c077a86;
case 0x0c077a88u: goto P_0c077a88;
case 0x0c077a8au: goto P_0c077a8a;
case 0x0c077a8cu: goto P_0c077a8c;
case 0x0c077a8eu: goto P_0c077a8e;
case 0x0c077a90u: goto P_0c077a90;
case 0x0c077a92u: goto P_0c077a92;
case 0x0c077a94u: goto P_0c077a94;
case 0x0c077a96u: goto P_0c077a96;
case 0x0c077a98u: goto P_0c077a98;
case 0x0c077a9au: goto P_0c077a9a;
case 0x0c077a9cu: goto P_0c077a9c;
case 0x0c077a9eu: goto P_0c077a9e;
case 0x0c077aa0u: goto P_0c077aa0;
case 0x0c077aa2u: goto P_0c077aa2;
case 0x0c077aa4u: goto P_0c077aa4;
case 0x0c077aa6u: goto P_0c077aa6;
case 0x0c077aa8u: goto P_0c077aa8;
case 0x0c077aaau: goto P_0c077aaa;
case 0x0c077aacu: goto P_0c077aac;
case 0x0c077aaeu: goto P_0c077aae;
case 0x0c077ad0u: goto P_0c077ad0;
case 0x0c077ad2u: goto P_0c077ad2;
case 0x0c077ad4u: goto P_0c077ad4;
case 0x0c077ad6u: goto P_0c077ad6;
case 0x0c077ad8u: goto P_0c077ad8;
case 0x0c077adau: goto P_0c077ada;
case 0x0c077adcu: goto P_0c077adc;
case 0x0c077adeu: goto P_0c077ade;
case 0x0c077ae0u: goto P_0c077ae0;
case 0x0c077ae2u: goto P_0c077ae2;
case 0x0c077ae4u: goto P_0c077ae4;
case 0x0c077ae6u: goto P_0c077ae6;
case 0x0c077ae8u: goto P_0c077ae8;
case 0x0c077aeau: goto P_0c077aea;
case 0x0c077aecu: goto P_0c077aec;
case 0x0c077aeeu: goto P_0c077aee;
case 0x0c077af0u: goto P_0c077af0;
case 0x0c077af2u: goto P_0c077af2;
case 0x0c077af4u: goto P_0c077af4;
case 0x0c077af6u: goto P_0c077af6;
case 0x0c077af8u: goto P_0c077af8;
case 0x0c077afau: goto P_0c077afa;
case 0x0c077afcu: goto P_0c077afc;
case 0x0c077afeu: goto P_0c077afe;
case 0x0c077b00u: goto P_0c077b00;
case 0x0c077b02u: goto P_0c077b02;
case 0x0c077b04u: goto P_0c077b04;
case 0x0c077b06u: goto P_0c077b06;
case 0x0c077b08u: goto P_0c077b08;
case 0x0c077b0au: goto P_0c077b0a;
case 0x0c077b0cu: goto P_0c077b0c;
case 0x0c077b0eu: goto P_0c077b0e;
case 0x0c077b10u: goto P_0c077b10;
case 0x0c077b12u: goto P_0c077b12;
case 0x0c077b14u: goto P_0c077b14;
case 0x0c077b16u: goto P_0c077b16;
case 0x0c077b18u: goto P_0c077b18;
case 0x0c077b1au: goto P_0c077b1a;
case 0x0c077b1cu: goto P_0c077b1c;
case 0x0c077b1eu: goto P_0c077b1e;
case 0x0c077b20u: goto P_0c077b20;
case 0x0c077b22u: goto P_0c077b22;
case 0x0c077b24u: goto P_0c077b24;
case 0x0c077b26u: goto P_0c077b26;
case 0x0c077b28u: goto P_0c077b28;
case 0x0c077b2au: goto P_0c077b2a;
case 0x0c077b2cu: goto P_0c077b2c;
case 0x0c077b2eu: goto P_0c077b2e;
case 0x0c077b30u: goto P_0c077b30;
case 0x0c077b32u: goto P_0c077b32;
case 0x0c077b34u: goto P_0c077b34;
case 0x0c077b36u: goto P_0c077b36;
case 0x0c077b38u: goto P_0c077b38;
case 0x0c077b3au: goto P_0c077b3a;
case 0x0c077b3cu: goto P_0c077b3c;
case 0x0c077b3eu: goto P_0c077b3e;
case 0x0c077b40u: goto P_0c077b40;
case 0x0c077b42u: goto P_0c077b42;
case 0x0c077b44u: goto P_0c077b44;
case 0x0c077b46u: goto P_0c077b46;
case 0x0c077b48u: goto P_0c077b48;
case 0x0c077b4au: goto P_0c077b4a;
case 0x0c077b4cu: goto P_0c077b4c;
case 0x0c077b4eu: goto P_0c077b4e;
case 0x0c077b50u: goto P_0c077b50;
case 0x0c077b52u: goto P_0c077b52;
case 0x0c077b54u: goto P_0c077b54;
case 0x0c077b56u: goto P_0c077b56;
case 0x0c077b58u: goto P_0c077b58;
case 0x0c077b5au: goto P_0c077b5a;
case 0x0c077b5cu: goto P_0c077b5c;
case 0x0c077b5eu: goto P_0c077b5e;
case 0x0c077b60u: goto P_0c077b60;
case 0x0c077b62u: goto P_0c077b62;
case 0x0c077b64u: goto P_0c077b64;
case 0x0c077b66u: goto P_0c077b66;
case 0x0c077b68u: goto P_0c077b68;
case 0x0c077b6au: goto P_0c077b6a;
case 0x0c077b6cu: goto P_0c077b6c;
case 0x0c077b6eu: goto P_0c077b6e;
case 0x0c077b70u: goto P_0c077b70;
case 0x0c077b72u: goto P_0c077b72;
case 0x0c077b74u: goto P_0c077b74;
case 0x0c077b76u: goto P_0c077b76;
case 0x0c077b78u: goto P_0c077b78;
case 0x0c077b7au: goto P_0c077b7a;
case 0x0c077b7cu: goto P_0c077b7c;
case 0x0c077b7eu: goto P_0c077b7e;
case 0x0c077b80u: goto P_0c077b80;
case 0x0c077b82u: goto P_0c077b82;
case 0x0c077b84u: goto P_0c077b84;
case 0x0c077b86u: goto P_0c077b86;
case 0x0c077b88u: goto P_0c077b88;
case 0x0c077b8au: goto P_0c077b8a;
case 0x0c077b8cu: goto P_0c077b8c;
case 0x0c077b8eu: goto P_0c077b8e;
case 0x0c077b90u: goto P_0c077b90;
case 0x0c077b92u: goto P_0c077b92;
case 0x0c077b94u: goto P_0c077b94;
case 0x0c077b96u: goto P_0c077b96;
case 0x0c077b98u: goto P_0c077b98;
case 0x0c077b9au: goto P_0c077b9a;
case 0x0c077b9cu: goto P_0c077b9c;
case 0x0c077b9eu: goto P_0c077b9e;
case 0x0c077bbcu: goto P_0c077bbc;
case 0x0c077bbeu: goto P_0c077bbe;
case 0x0c077bc0u: goto P_0c077bc0;
case 0x0c077bc2u: goto P_0c077bc2;
case 0x0c077bc4u: goto P_0c077bc4;
case 0x0c077bc6u: goto P_0c077bc6;
case 0x0c077bc8u: goto P_0c077bc8;
case 0x0c077bcau: goto P_0c077bca;
case 0x0c077bccu: goto P_0c077bcc;
case 0x0c077bceu: goto P_0c077bce;
case 0x0c077bd0u: goto P_0c077bd0;
case 0x0c077bd2u: goto P_0c077bd2;
case 0x0c077bd4u: goto P_0c077bd4;
case 0x0c077bd6u: goto P_0c077bd6;
case 0x0c077bd8u: goto P_0c077bd8;
case 0x0c077bdau: goto P_0c077bda;
case 0x0c077bdcu: goto P_0c077bdc;
case 0x0c077bdeu: goto P_0c077bde;
case 0x0c077be0u: goto P_0c077be0;
case 0x0c077be2u: goto P_0c077be2;
case 0x0c077be4u: goto P_0c077be4;
case 0x0c077be6u: goto P_0c077be6;
case 0x0c077be8u: goto P_0c077be8;
case 0x0c077beau: goto P_0c077bea;
case 0x0c077becu: goto P_0c077bec;
case 0x0c077beeu: goto P_0c077bee;
case 0x0c077bf0u: goto P_0c077bf0;
case 0x0c077bf2u: goto P_0c077bf2;
case 0x0c077bf4u: goto P_0c077bf4;
case 0x0c077bf6u: goto P_0c077bf6;
case 0x0c077bf8u: goto P_0c077bf8;
case 0x0c077bfau: goto P_0c077bfa;
case 0x0c077bfcu: goto P_0c077bfc;
case 0x0c077bfeu: goto P_0c077bfe;
case 0x0c077c00u: goto P_0c077c00;
case 0x0c077c02u: goto P_0c077c02;
case 0x0c077c04u: goto P_0c077c04;
case 0x0c077c06u: goto P_0c077c06;
case 0x0c077c08u: goto P_0c077c08;
case 0x0c077c0au: goto P_0c077c0a;
case 0x0c077c0cu: goto P_0c077c0c;
case 0x0c077c0eu: goto P_0c077c0e;
case 0x0c077c10u: goto P_0c077c10;
case 0x0c077c12u: goto P_0c077c12;
case 0x0c077c14u: goto P_0c077c14;
case 0x0c077c16u: goto P_0c077c16;
case 0x0c077c18u: goto P_0c077c18;
case 0x0c077c1au: goto P_0c077c1a;
case 0x0c077c1cu: goto P_0c077c1c;
case 0x0c077c1eu: goto P_0c077c1e;
case 0x0c077c20u: goto P_0c077c20;
case 0x0c077c22u: goto P_0c077c22;
case 0x0c077c24u: goto P_0c077c24;
case 0x0c077c26u: goto P_0c077c26;
case 0x0c077c28u: goto P_0c077c28;
case 0x0c077c2au: goto P_0c077c2a;
case 0x0c077c2cu: goto P_0c077c2c;
case 0x0c077c2eu: goto P_0c077c2e;
case 0x0c077c30u: goto P_0c077c30;
case 0x0c077c32u: goto P_0c077c32;
case 0x0c077c34u: goto P_0c077c34;
case 0x0c077c36u: goto P_0c077c36;
case 0x0c077c38u: goto P_0c077c38;
case 0x0c077c3au: goto P_0c077c3a;
case 0x0c077c3cu: goto P_0c077c3c;
case 0x0c077c3eu: goto P_0c077c3e;
case 0x0c077c40u: goto P_0c077c40;
case 0x0c077c42u: goto P_0c077c42;
case 0x0c077c44u: goto P_0c077c44;
case 0x0c077c46u: goto P_0c077c46;
case 0x0c077c48u: goto P_0c077c48;
case 0x0c077c4au: goto P_0c077c4a;
case 0x0c077c4cu: goto P_0c077c4c;
case 0x0c077c4eu: goto P_0c077c4e;
case 0x0c077c50u: goto P_0c077c50;
case 0x0c077c52u: goto P_0c077c52;
case 0x0c077c54u: goto P_0c077c54;
case 0x0c077c56u: goto P_0c077c56;
case 0x0c077c58u: goto P_0c077c58;
case 0x0c077c5au: goto P_0c077c5a;
case 0x0c077c5cu: goto P_0c077c5c;
case 0x0c077c5eu: goto P_0c077c5e;
case 0x0c077c60u: goto P_0c077c60;
case 0x0c077c62u: goto P_0c077c62;
case 0x0c077c64u: goto P_0c077c64;
case 0x0c077c66u: goto P_0c077c66;
case 0x0c077c68u: goto P_0c077c68;
case 0x0c077c6au: goto P_0c077c6a;
case 0x0c077c6cu: goto P_0c077c6c;
case 0x0c077c6eu: goto P_0c077c6e;
case 0x0c077c70u: goto P_0c077c70;
case 0x0c077c72u: goto P_0c077c72;
case 0x0c077c74u: goto P_0c077c74;
case 0x0c077c76u: goto P_0c077c76;
case 0x0c077c78u: goto P_0c077c78;
case 0x0c077c7au: goto P_0c077c7a;
case 0x0c077c7cu: goto P_0c077c7c;
case 0x0c077c7eu: goto P_0c077c7e;
case 0x0c077c80u: goto P_0c077c80;
case 0x0c077c82u: goto P_0c077c82;
case 0x0c077c84u: goto P_0c077c84;
case 0x0c077c86u: goto P_0c077c86;
case 0x0c077c88u: goto P_0c077c88;
case 0x0c077c8au: goto P_0c077c8a;
case 0x0c077c8cu: goto P_0c077c8c;
case 0x0c077c8eu: goto P_0c077c8e;
case 0x0c077c90u: goto P_0c077c90;
case 0x0c077c92u: goto P_0c077c92;
case 0x0c077c94u: goto P_0c077c94;
case 0x0c077c96u: goto P_0c077c96;
case 0x0c077c98u: goto P_0c077c98;
case 0x0c077c9au: goto P_0c077c9a;
case 0x0c077c9cu: goto P_0c077c9c;
case 0x0c077c9eu: goto P_0c077c9e;
case 0x0c077ca0u: goto P_0c077ca0;
case 0x0c077ca2u: goto P_0c077ca2;
case 0x0c077ca4u: goto P_0c077ca4;
case 0x0c077ca6u: goto P_0c077ca6;
case 0x0c077ca8u: goto P_0c077ca8;
case 0x0c077caau: goto P_0c077caa;
case 0x0c077cacu: goto P_0c077cac;
case 0x0c077caeu: goto P_0c077cae;
case 0x0c077cb0u: goto P_0c077cb0;
case 0x0c077cb2u: goto P_0c077cb2;
case 0x0c077cb4u: goto P_0c077cb4;
case 0x0c077cb6u: goto P_0c077cb6;
case 0x0c077cb8u: goto P_0c077cb8;
case 0x0c077cbau: goto P_0c077cba;
case 0x0c077cbcu: goto P_0c077cbc;
case 0x0c077cbeu: goto P_0c077cbe;
case 0x0c077cc0u: goto P_0c077cc0;
case 0x0c077cc2u: goto P_0c077cc2;
case 0x0c077cc4u: goto P_0c077cc4;
case 0x0c077cc6u: goto P_0c077cc6;
case 0x0c077cc8u: goto P_0c077cc8;
case 0x0c077ccau: goto P_0c077cca;
case 0x0c077cccu: goto P_0c077ccc;
case 0x0c077cceu: goto P_0c077cce;
case 0x0c077cd0u: goto P_0c077cd0;
case 0x0c077cd2u: goto P_0c077cd2;
case 0x0c077cd4u: goto P_0c077cd4;
case 0x0c077cd6u: goto P_0c077cd6;
case 0x0c077cd8u: goto P_0c077cd8;
case 0x0c077cdau: goto P_0c077cda;
case 0x0c077cdcu: goto P_0c077cdc;
case 0x0c077cdeu: goto P_0c077cde;
case 0x0c077ce0u: goto P_0c077ce0;
case 0x0c077ce2u: goto P_0c077ce2;
case 0x0c077ce4u: goto P_0c077ce4;
case 0x0c077ce6u: goto P_0c077ce6;
case 0x0c077ce8u: goto P_0c077ce8;
case 0x0c077ceau: goto P_0c077cea;
case 0x0c077cecu: goto P_0c077cec;
case 0x0c077ceeu: goto P_0c077cee;
case 0x0c077cf0u: goto P_0c077cf0;
case 0x0c077cf2u: goto P_0c077cf2;
case 0x0c077cf4u: goto P_0c077cf4;
case 0x0c077d1cu: goto P_0c077d1c;
case 0x0c077d1eu: goto P_0c077d1e;
case 0x0c077d20u: goto P_0c077d20;
case 0x0c077d22u: goto P_0c077d22;
case 0x0c077d24u: goto P_0c077d24;
case 0x0c077d26u: goto P_0c077d26;
case 0x0c077d28u: goto P_0c077d28;
case 0x0c077d2au: goto P_0c077d2a;
case 0x0c077d2cu: goto P_0c077d2c;
case 0x0c077d2eu: goto P_0c077d2e;
case 0x0c077d30u: goto P_0c077d30;
case 0x0c077d32u: goto P_0c077d32;
case 0x0c077d34u: goto P_0c077d34;
case 0x0c077d36u: goto P_0c077d36;
case 0x0c077d38u: goto P_0c077d38;
case 0x0c077d3au: goto P_0c077d3a;
case 0x0c077d3cu: goto P_0c077d3c;
case 0x0c077d3eu: goto P_0c077d3e;
case 0x0c077d40u: goto P_0c077d40;
case 0x0c077d42u: goto P_0c077d42;
case 0x0c077d44u: goto P_0c077d44;
case 0x0c077d46u: goto P_0c077d46;
case 0x0c077d48u: goto P_0c077d48;
case 0x0c077d4au: goto P_0c077d4a;
case 0x0c077d4cu: goto P_0c077d4c;
case 0x0c077d4eu: goto P_0c077d4e;
case 0x0c077d50u: goto P_0c077d50;
case 0x0c077d52u: goto P_0c077d52;
case 0x0c077d54u: goto P_0c077d54;
case 0x0c077d56u: goto P_0c077d56;
case 0x0c077d58u: goto P_0c077d58;
case 0x0c077d5au: goto P_0c077d5a;
case 0x0c077d5cu: goto P_0c077d5c;
case 0x0c077d5eu: goto P_0c077d5e;
case 0x0c077d60u: goto P_0c077d60;
case 0x0c077d62u: goto P_0c077d62;
case 0x0c077d64u: goto P_0c077d64;
case 0x0c077d66u: goto P_0c077d66;
case 0x0c077d68u: goto P_0c077d68;
case 0x0c077d6au: goto P_0c077d6a;
case 0x0c077d6cu: goto P_0c077d6c;
case 0x0c077d6eu: goto P_0c077d6e;
case 0x0c077d70u: goto P_0c077d70;
case 0x0c077d72u: goto P_0c077d72;
case 0x0c077d74u: goto P_0c077d74;
case 0x0c077d76u: goto P_0c077d76;
case 0x0c077d78u: goto P_0c077d78;
case 0x0c077d7au: goto P_0c077d7a;
case 0x0c077d7cu: goto P_0c077d7c;
case 0x0c077d7eu: goto P_0c077d7e;
case 0x0c077d80u: goto P_0c077d80;
case 0x0c077d82u: goto P_0c077d82;
case 0x0c077d84u: goto P_0c077d84;
case 0x0c077d86u: goto P_0c077d86;
case 0x0c077d88u: goto P_0c077d88;
case 0x0c077d8au: goto P_0c077d8a;
case 0x0c077d8cu: goto P_0c077d8c;
case 0x0c077d8eu: goto P_0c077d8e;
case 0x0c077d90u: goto P_0c077d90;
case 0x0c077d92u: goto P_0c077d92;
case 0x0c077d94u: goto P_0c077d94;
case 0x0c077d96u: goto P_0c077d96;
case 0x0c077d98u: goto P_0c077d98;
case 0x0c077d9au: goto P_0c077d9a;
case 0x0c077d9cu: goto P_0c077d9c;
case 0x0c077d9eu: goto P_0c077d9e;
case 0x0c077da0u: goto P_0c077da0;
case 0x0c077da2u: goto P_0c077da2;
case 0x0c077da4u: goto P_0c077da4;
case 0x0c077da6u: goto P_0c077da6;
case 0x0c077da8u: goto P_0c077da8;
case 0x0c077daau: goto P_0c077daa;
case 0x0c077dacu: goto P_0c077dac;
case 0x0c077daeu: goto P_0c077dae;
case 0x0c077db0u: goto P_0c077db0;
case 0x0c077db2u: goto P_0c077db2;
case 0x0c077db4u: goto P_0c077db4;
case 0x0c077db6u: goto P_0c077db6;
case 0x0c077db8u: goto P_0c077db8;
case 0x0c077dbau: goto P_0c077dba;
case 0x0c077dbcu: goto P_0c077dbc;
case 0x0c077dbeu: goto P_0c077dbe;
case 0x0c077dc0u: goto P_0c077dc0;
case 0x0c077dc2u: goto P_0c077dc2;
case 0x0c077dc4u: goto P_0c077dc4;
case 0x0c077dc6u: goto P_0c077dc6;
case 0x0c077dc8u: goto P_0c077dc8;
case 0x0c077dcau: goto P_0c077dca;
case 0x0c077dccu: goto P_0c077dcc;
case 0x0c077dceu: goto P_0c077dce;
case 0x0c077dd0u: goto P_0c077dd0;
case 0x0c077dd2u: goto P_0c077dd2;
case 0x0c077dd4u: goto P_0c077dd4;
case 0x0c077dd6u: goto P_0c077dd6;
case 0x0c077dd8u: goto P_0c077dd8;
case 0x0c077ddau: goto P_0c077dda;
case 0x0c077e04u: goto P_0c077e04;
case 0x0c077e06u: goto P_0c077e06;
case 0x0c077e08u: goto P_0c077e08;
case 0x0c077e0au: goto P_0c077e0a;
case 0x0c077e0cu: goto P_0c077e0c;
case 0x0c077e0eu: goto P_0c077e0e;
case 0x0c077e10u: goto P_0c077e10;
case 0x0c077e12u: goto P_0c077e12;
case 0x0c077e14u: goto P_0c077e14;
case 0x0c077e16u: goto P_0c077e16;
case 0x0c077e18u: goto P_0c077e18;
case 0x0c077e1au: goto P_0c077e1a;
case 0x0c077e1cu: goto P_0c077e1c;
case 0x0c077e1eu: goto P_0c077e1e;
case 0x0c077e20u: goto P_0c077e20;
case 0x0c077e22u: goto P_0c077e22;
case 0x0c077e24u: goto P_0c077e24;
case 0x0c077e26u: goto P_0c077e26;
case 0x0c077e28u: goto P_0c077e28;
case 0x0c077e2au: goto P_0c077e2a;
case 0x0c077e2cu: goto P_0c077e2c;
case 0x0c077e2eu: goto P_0c077e2e;
case 0x0c077e30u: goto P_0c077e30;
case 0x0c077e32u: goto P_0c077e32;
case 0x0c077e34u: goto P_0c077e34;
case 0x0c077e36u: goto P_0c077e36;
case 0x0c077e38u: goto P_0c077e38;
case 0x0c077e3au: goto P_0c077e3a;
case 0x0c077e3cu: goto P_0c077e3c;
case 0x0c077e3eu: goto P_0c077e3e;
case 0x0c077e40u: goto P_0c077e40;
case 0x0c077e42u: goto P_0c077e42;
case 0x0c077e44u: goto P_0c077e44;
case 0x0c077e46u: goto P_0c077e46;
case 0x0c077e48u: goto P_0c077e48;
case 0x0c077e4au: goto P_0c077e4a;
case 0x0c077e4cu: goto P_0c077e4c;
case 0x0c077e4eu: goto P_0c077e4e;
case 0x0c077e50u: goto P_0c077e50;
case 0x0c077e52u: goto P_0c077e52;
case 0x0c077e54u: goto P_0c077e54;
case 0x0c077e56u: goto P_0c077e56;
case 0x0c077e58u: goto P_0c077e58;
case 0x0c077e5au: goto P_0c077e5a;
case 0x0c078044u: goto P_0c078044;
case 0x0c078046u: goto P_0c078046;
case 0x0c078048u: goto P_0c078048;
case 0x0c07804au: goto P_0c07804a;
case 0x0c07804cu: goto P_0c07804c;
case 0x0c07804eu: goto P_0c07804e;
case 0x0c078050u: goto P_0c078050;
case 0x0c078052u: goto P_0c078052;
case 0x0c078054u: goto P_0c078054;
case 0x0c078056u: goto P_0c078056;
case 0x0c078058u: goto P_0c078058;
case 0x0c07805au: goto P_0c07805a;
case 0x0c07805cu: goto P_0c07805c;
case 0x0c07805eu: goto P_0c07805e;
case 0x0c078060u: goto P_0c078060;
case 0x0c078062u: goto P_0c078062;
case 0x0c078064u: goto P_0c078064;
case 0x0c078066u: goto P_0c078066;
case 0x0c078068u: goto P_0c078068;
case 0x0c07806au: goto P_0c07806a;
case 0x0c07806cu: goto P_0c07806c;
case 0x0c07806eu: goto P_0c07806e;
case 0x0c078070u: goto P_0c078070;
case 0x0c078072u: goto P_0c078072;
case 0x0c078074u: goto P_0c078074;
case 0x0c078076u: goto P_0c078076;
case 0x0c078078u: goto P_0c078078;
case 0x0c07807au: goto P_0c07807a;
case 0x0c07807cu: goto P_0c07807c;
case 0x0c07807eu: goto P_0c07807e;
case 0x0c078080u: goto P_0c078080;
case 0x0c078082u: goto P_0c078082;
case 0x0c078084u: goto P_0c078084;
case 0x0c078086u: goto P_0c078086;
case 0x0c078088u: goto P_0c078088;
case 0x0c07808au: goto P_0c07808a;
case 0x0c07808cu: goto P_0c07808c;
case 0x0c07808eu: goto P_0c07808e;
case 0x0c078090u: goto P_0c078090;
case 0x0c078092u: goto P_0c078092;
case 0x0c078094u: goto P_0c078094;
case 0x0c078096u: goto P_0c078096;
case 0x0c078098u: goto P_0c078098;
case 0x0c07809au: goto P_0c07809a;
case 0x0c07809cu: goto P_0c07809c;
case 0x0c07809eu: goto P_0c07809e;
case 0x0c0780a0u: goto P_0c0780a0;
case 0x0c0780a2u: goto P_0c0780a2;
case 0x0c0780a4u: goto P_0c0780a4;
case 0x0c0780a6u: goto P_0c0780a6;
case 0x0c0780a8u: goto P_0c0780a8;
case 0x0c0780aau: goto P_0c0780aa;
case 0x0c0780acu: goto P_0c0780ac;
case 0x0c0780aeu: goto P_0c0780ae;
case 0x0c0780b0u: goto P_0c0780b0;
case 0x0c0780b2u: goto P_0c0780b2;
case 0x0c0780b4u: goto P_0c0780b4;
case 0x0c0780b6u: goto P_0c0780b6;
case 0x0c0780b8u: goto P_0c0780b8;
case 0x0c0780bau: goto P_0c0780ba;
case 0x0c0780bcu: goto P_0c0780bc;
case 0x0c0780beu: goto P_0c0780be;
case 0x0c0780c0u: goto P_0c0780c0;
case 0x0c0780c2u: goto P_0c0780c2;
case 0x0c0780c4u: goto P_0c0780c4;
case 0x0c0780c6u: goto P_0c0780c6;
case 0x0c0780c8u: goto P_0c0780c8;
case 0x0c0780cau: goto P_0c0780ca;
case 0x0c0780ccu: goto P_0c0780cc;
case 0x0c0780ceu: goto P_0c0780ce;
case 0x0c0780d0u: goto P_0c0780d0;
case 0x0c0780d2u: goto P_0c0780d2;
case 0x0c0780d4u: goto P_0c0780d4;
case 0x0c0780d6u: goto P_0c0780d6;
case 0x0c0780d8u: goto P_0c0780d8;
case 0x0c0780dau: goto P_0c0780da;
case 0x0c0780dcu: goto P_0c0780dc;
case 0x0c0780deu: goto P_0c0780de;
case 0x0c0780e0u: goto P_0c0780e0;
case 0x0c0780e2u: goto P_0c0780e2;
case 0x0c0780e4u: goto P_0c0780e4;
case 0x0c0780e6u: goto P_0c0780e6;
case 0x0c0780e8u: goto P_0c0780e8;
case 0x0c0780eau: goto P_0c0780ea;
case 0x0c0780ecu: goto P_0c0780ec;
case 0x0c0780eeu: goto P_0c0780ee;
case 0x0c0780f0u: goto P_0c0780f0;
case 0x0c0780f2u: goto P_0c0780f2;
case 0x0c0780f4u: goto P_0c0780f4;
case 0x0c0780f6u: goto P_0c0780f6;
case 0x0c0780f8u: goto P_0c0780f8;
case 0x0c0780fau: goto P_0c0780fa;
case 0x0c0780fcu: goto P_0c0780fc;
case 0x0c0780feu: goto P_0c0780fe;
case 0x0c078100u: goto P_0c078100;
case 0x0c078102u: goto P_0c078102;
case 0x0c078104u: goto P_0c078104;
case 0x0c078106u: goto P_0c078106;
case 0x0c078108u: goto P_0c078108;
case 0x0c07810au: goto P_0c07810a;
case 0x0c07810cu: goto P_0c07810c;
case 0x0c07810eu: goto P_0c07810e;
case 0x0c078170u: goto P_0c078170;
case 0x0c0781bau: goto P_0c0781ba;
case 0x0c0781bcu: goto P_0c0781bc;
case 0x0c0781beu: goto P_0c0781be;
case 0x0c0781c0u: goto P_0c0781c0;
case 0x0c07b9aeu: goto P_0c07b9ae;
case 0x0c07b9b0u: goto P_0c07b9b0;
case 0x0c07b9b2u: goto P_0c07b9b2;
case 0x0c07b9b4u: goto P_0c07b9b4;
case 0x0c07b9b6u: goto P_0c07b9b6;
case 0x0c07b9b8u: goto P_0c07b9b8;
case 0x0c07b9bau: goto P_0c07b9ba;
case 0x0c07b9bcu: goto P_0c07b9bc;
case 0x0c07b9beu: goto P_0c07b9be;
case 0x0c07b9c0u: goto P_0c07b9c0;
case 0x0c07b9c2u: goto P_0c07b9c2;
case 0x0c07b9c4u: goto P_0c07b9c4;
case 0x0c07b9c6u: goto P_0c07b9c6;
case 0x0c07b9c8u: goto P_0c07b9c8;
case 0x0c07b9cau: goto P_0c07b9ca;
case 0x0c07b9ccu: goto P_0c07b9cc;
case 0x0c07b9ceu: goto P_0c07b9ce;
case 0x0c07b9d0u: goto P_0c07b9d0;
case 0x0c07b9d2u: goto P_0c07b9d2;
case 0x0c07b9d4u: goto P_0c07b9d4;
case 0x0c07b9d6u: goto P_0c07b9d6;
case 0x0c07b9d8u: goto P_0c07b9d8;
case 0x0c07b9dau: goto P_0c07b9da;
case 0x0c07b9dcu: goto P_0c07b9dc;
case 0x0c07b9deu: goto P_0c07b9de;
case 0x0c07b9e0u: goto P_0c07b9e0;
case 0x0c07b9e2u: goto P_0c07b9e2;
case 0x0c07b9e4u: goto P_0c07b9e4;
case 0x0c07b9e6u: goto P_0c07b9e6;
case 0x0c07b9e8u: goto P_0c07b9e8;
case 0x0c07b9eau: goto P_0c07b9ea;
case 0x0c07b9ecu: goto P_0c07b9ec;
case 0x0c07b9eeu: goto P_0c07b9ee;
case 0x0c07b9f0u: goto P_0c07b9f0;
case 0x0c07b9f2u: goto P_0c07b9f2;
case 0x0c07b9f4u: goto P_0c07b9f4;
case 0x0c07b9f6u: goto P_0c07b9f6;
case 0x0c07b9f8u: goto P_0c07b9f8;
case 0x0c07b9fau: goto P_0c07b9fa;
case 0x0c07b9fcu: goto P_0c07b9fc;
case 0x0c07b9feu: goto P_0c07b9fe;
case 0x0c07ba00u: goto P_0c07ba00;
case 0x0c07ba02u: goto P_0c07ba02;
case 0x0c07ba04u: goto P_0c07ba04;
case 0x0c07ba06u: goto P_0c07ba06;
case 0x0c07ba08u: goto P_0c07ba08;
case 0x0c07c534u: goto P_0c07c534;
case 0x0c07c536u: goto P_0c07c536;
case 0x0c07c538u: goto P_0c07c538;
case 0x0c07c53au: goto P_0c07c53a;
case 0x0c07c53cu: goto P_0c07c53c;
case 0x0c07c53eu: goto P_0c07c53e;
case 0x0c07c600u: goto P_0c07c600;
case 0x0c07c602u: goto P_0c07c602;
case 0x0c07c604u: goto P_0c07c604;
case 0x0c07c606u: goto P_0c07c606;
case 0x0c07c608u: goto P_0c07c608;
case 0x0c07c60au: goto P_0c07c60a;
case 0x0c07c60cu: goto P_0c07c60c;
case 0x0c07c60eu: goto P_0c07c60e;
case 0x0c07c610u: goto P_0c07c610;
case 0x0c07c820u: goto P_0c07c820;
case 0x0c07c822u: goto P_0c07c822;
case 0x0c07c824u: goto P_0c07c824;
case 0x0c07c826u: goto P_0c07c826;
case 0x0c07c828u: goto P_0c07c828;
case 0x0c07c82au: goto P_0c07c82a;
case 0x0c07c82cu: goto P_0c07c82c;
case 0x0c07c82eu: goto P_0c07c82e;
case 0x0c07c830u: goto P_0c07c830;
case 0x0c07c832u: goto P_0c07c832;
case 0x0c07c834u: goto P_0c07c834;
case 0x0c07c836u: goto P_0c07c836;
case 0x0c07c838u: goto P_0c07c838;
case 0x0c07c83au: goto P_0c07c83a;
case 0x0c07c83cu: goto P_0c07c83c;
case 0x0c07c83eu: goto P_0c07c83e;
case 0x0c07c840u: goto P_0c07c840;
case 0x0c07c842u: goto P_0c07c842;
case 0x0c07c844u: goto P_0c07c844;
case 0x0c07c846u: goto P_0c07c846;
case 0x0c07c848u: goto P_0c07c848;
case 0x0c07c84au: goto P_0c07c84a;
case 0x0c07c84cu: goto P_0c07c84c;
case 0x0c07c84eu: goto P_0c07c84e;
case 0x0c07c850u: goto P_0c07c850;
case 0x0c07c852u: goto P_0c07c852;
case 0x0c07c854u: goto P_0c07c854;
case 0x0c07c856u: goto P_0c07c856;
case 0x0c07c858u: goto P_0c07c858;
case 0x0c07c85au: goto P_0c07c85a;
case 0x0c07c85cu: goto P_0c07c85c;
case 0x0c07c85eu: goto P_0c07c85e;
case 0x0c07c860u: goto P_0c07c860;
case 0x0c07c862u: goto P_0c07c862;
case 0x0c07c864u: goto P_0c07c864;
case 0x0c07c866u: goto P_0c07c866;
case 0x0c07c868u: goto P_0c07c868;
case 0x0c07c86au: goto P_0c07c86a;
case 0x0c07c99au: goto P_0c07c99a;
case 0x0c07c99cu: goto P_0c07c99c;
case 0x0c08049cu: goto P_0c08049c;
case 0x0c08049eu: goto P_0c08049e;
case 0x0c0804a0u: goto P_0c0804a0;
case 0x0c0804a2u: goto P_0c0804a2;
case 0x0c081184u: goto P_0c081184;
case 0x0c081186u: goto P_0c081186;
case 0x0c081188u: goto P_0c081188;
case 0x0c08118au: goto P_0c08118a;
case 0x0c08118cu: goto P_0c08118c;
case 0x0c08118eu: goto P_0c08118e;
case 0x0c081190u: goto P_0c081190;
case 0x0c081192u: goto P_0c081192;
case 0x0c0968d0u: goto P_0c0968d0;
case 0x0c0968d2u: goto P_0c0968d2;
case 0x0c0968d4u: goto P_0c0968d4;
case 0x0c0968d6u: goto P_0c0968d6;
case 0x0c0968d8u: goto P_0c0968d8;
case 0x0c0968dau: goto P_0c0968da;
case 0x0c0968dcu: goto P_0c0968dc;
case 0x0c0968deu: goto P_0c0968de;
case 0x0c0968e0u: goto P_0c0968e0;
case 0x0c0968e2u: goto P_0c0968e2;
case 0x0c0968e4u: goto P_0c0968e4;
case 0x0c0968e6u: goto P_0c0968e6;
case 0x0c0968e8u: goto P_0c0968e8;
case 0x0c0968eau: goto P_0c0968ea;
case 0x0c0968ecu: goto P_0c0968ec;
case 0x0c0968eeu: goto P_0c0968ee;
case 0x0c0968f0u: goto P_0c0968f0;
case 0x0c0968f2u: goto P_0c0968f2;
case 0x0c0968f4u: goto P_0c0968f4;
case 0x0c0968f6u: goto P_0c0968f6;
case 0x0c096d5eu: goto P_0c096d5e;
case 0x0c096d60u: goto P_0c096d60;
case 0x0c096d62u: goto P_0c096d62;
case 0x0c096d64u: goto P_0c096d64;
case 0x0c096d66u: goto P_0c096d66;
case 0x0c096d68u: goto P_0c096d68;
case 0x0c096d6au: goto P_0c096d6a;
case 0x0c096d6cu: goto P_0c096d6c;
case 0x0c096d6eu: goto P_0c096d6e;
case 0x0c096d70u: goto P_0c096d70;
case 0x0c096d72u: goto P_0c096d72;
case 0x0c096d74u: goto P_0c096d74;
case 0x0c096d76u: goto P_0c096d76;
case 0x0c096d78u: goto P_0c096d78;
case 0x0c096d7au: goto P_0c096d7a;
case 0x0c096d7cu: goto P_0c096d7c;
case 0x0c096d7eu: goto P_0c096d7e;
case 0x0c096d80u: goto P_0c096d80;
case 0x0c096d82u: goto P_0c096d82;
case 0x0c096d84u: goto P_0c096d84;
case 0x0c096d86u: goto P_0c096d86;
case 0x0c096d88u: goto P_0c096d88;
case 0x0c096d8au: goto P_0c096d8a;
case 0x0c096d8cu: goto P_0c096d8c;
case 0x0c096d8eu: goto P_0c096d8e;
case 0x0c096d90u: goto P_0c096d90;
case 0x0c096d92u: goto P_0c096d92;
case 0x0c096d94u: goto P_0c096d94;
case 0x0c096d96u: goto P_0c096d96;
case 0x0c096d98u: goto P_0c096d98;
case 0x0c096d9au: goto P_0c096d9a;
case 0x0c096d9cu: goto P_0c096d9c;
case 0x0c096d9eu: goto P_0c096d9e;
case 0x0c096da0u: goto P_0c096da0;
case 0x0c096da2u: goto P_0c096da2;
case 0x0c096da4u: goto P_0c096da4;
case 0x0c096da6u: goto P_0c096da6;
case 0x0c096da8u: goto P_0c096da8;
case 0x0c096daau: goto P_0c096daa;
case 0x0c096dacu: goto P_0c096dac;
case 0x0c096daeu: goto P_0c096dae;
case 0x0c096db0u: goto P_0c096db0;
case 0x0c096db2u: goto P_0c096db2;
case 0x0c096db4u: goto P_0c096db4;
case 0x0c096db6u: goto P_0c096db6;
case 0x0c096db8u: goto P_0c096db8;
case 0x0c096dbau: goto P_0c096dba;
case 0x0c096dbcu: goto P_0c096dbc;
case 0x0c096dbeu: goto P_0c096dbe;
case 0x0c097042u: goto P_0c097042;
case 0x0c097044u: goto P_0c097044;
case 0x0c097046u: goto P_0c097046;
case 0x0c097048u: goto P_0c097048;
case 0x0c09704au: goto P_0c09704a;
case 0x0c09704cu: goto P_0c09704c;
case 0x0c09704eu: goto P_0c09704e;
case 0x0c097050u: goto P_0c097050;
case 0x0c097052u: goto P_0c097052;
case 0x0c097054u: goto P_0c097054;
case 0x0c097056u: goto P_0c097056;
case 0x0c097058u: goto P_0c097058;
case 0x0c09705au: goto P_0c09705a;
case 0x0c09705cu: goto P_0c09705c;
case 0x0c0a7b36u: goto P_0c0a7b36;
case 0x0c0a7b38u: goto P_0c0a7b38;
case 0x0c0a7b3au: goto P_0c0a7b3a;
case 0x0c0a7b3cu: goto P_0c0a7b3c;
case 0x0c0a7b3eu: goto P_0c0a7b3e;
case 0x0c0a7b40u: goto P_0c0a7b40;
case 0x0c0a7b42u: goto P_0c0a7b42;
case 0x0c0a7b44u: goto P_0c0a7b44;
case 0x0c0a7b46u: goto P_0c0a7b46;
case 0x0c0a7b48u: goto P_0c0a7b48;
case 0x0c0a7b4au: goto P_0c0a7b4a;
case 0x0c0a7b4cu: goto P_0c0a7b4c;
case 0x0c0a7b4eu: goto P_0c0a7b4e;
case 0x0c0a7b50u: goto P_0c0a7b50;
default: return vf3_matrix_family(target,s,ram);
}
P_0c076ba6: /* original 4f22, guest PC 0x0c076ba6 */
if(!s->budget--) { s->failed_pc=0x0c076ba6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076ba8;
P_0c076ba8: /* original 5c44, guest PC 0x0c076ba8 */
if(!s->budget--) { s->failed_pc=0x0c076ba8u; return 0; }
r[12]=read(ram,r[4]+16,4);
goto P_0c076baa;
P_0c076baa: /* original 2238, guest PC 0x0c076baa */
if(!s->budget--) { s->failed_pc=0x0c076baau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076bac;
P_0c076bac: /* original 5d45, guest PC 0x0c076bac */
if(!s->budget--) { s->failed_pc=0x0c076bacu; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c076bae;
P_0c076bae: /* original 8f04, guest PC 0x0c076bae */
if(!s->budget--) { s->failed_pc=0x0c076baeu; return 0; }
cond=r[17]&1u;
r[11]=r[4];
if(!cond) { goto P_0c076bba; }
goto P_0c076bb2;
P_0c076bb0: /* original 6b43, guest PC 0x0c076bb0 */
if(!s->budget--) { s->failed_pc=0x0c076bb0u; return 0; }
r[11]=r[4];
goto P_0c076bb2;
P_0c076bb2: /* original 50ba, guest PC 0x0c076bb2 */
if(!s->budget--) { s->failed_pc=0x0c076bb2u; return 0; }
r[0]=read(ram,r[11]+40,4);
goto P_0c076bb4;
P_0c076bb4: /* original 6002, guest PC 0x0c076bb4 */
if(!s->budget--) { s->failed_pc=0x0c076bb4u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c076bb6;
P_0c076bb6: /* original c802, guest PC 0x0c076bb6 */
if(!s->budget--) { s->failed_pc=0x0c076bb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c076bb8;
P_0c076bb8: /* original 8904, guest PC 0x0c076bb8 */
if(!s->budget--) { s->failed_pc=0x0c076bb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076bc4; }
goto P_0c076bba;
P_0c076bba: /* original 9073, guest PC 0x0c076bba */
if(!s->budget--) { s->failed_pc=0x0c076bbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca4u,2);
goto P_0c076bbc;
P_0c076bbc: /* original 03ee, guest PC 0x0c076bbc */
if(!s->budget--) { s->failed_pc=0x0c076bbcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076bbe;
P_0c076bbe: /* original 9072, guest PC 0x0c076bbe */
if(!s->budget--) { s->failed_pc=0x0c076bbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca6u,2);
goto P_0c076bc0;
P_0c076bc0: /* original 4319, guest PC 0x0c076bc0 */
if(!s->budget--) { s->failed_pc=0x0c076bc0u; return 0; }
r[3]>>=8;
goto P_0c076bc2;
P_0c076bc2: /* original 0c34, guest PC 0x0c076bc2 */
if(!s->budget--) { s->failed_pc=0x0c076bc2u; return 0; }
write(ram,r[12]+r[0],r[3],1);
goto P_0c076bc4;
P_0c076bc4: /* original 65c3, guest PC 0x0c076bc4 */
if(!s->budget--) { s->failed_pc=0x0c076bc4u; return 0; }
r[5]=r[12];
goto P_0c076bc6;
P_0c076bc6: /* original 66d3, guest PC 0x0c076bc6 */
if(!s->budget--) { s->failed_pc=0x0c076bc6u; return 0; }
r[6]=r[13];
goto P_0c076bc8;
P_0c076bc8: /* original b017, guest PC 0x0c076bc8 */
if(!s->budget--) { s->failed_pc=0x0c076bc8u; return 0; }
target=0x0c076bfau; r[16]=0x0c076bccu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c076bccu) { target=s->pc; goto dispatch; }
goto P_0c076bcc;
P_0c076bca: /* original 64a3, guest PC 0x0c076bca */
if(!s->budget--) { s->failed_pc=0x0c076bcau; return 0; }
r[4]=r[10];
goto P_0c076bcc;
P_0c076bcc: /* original 62e2, guest PC 0x0c076bcc */
if(!s->budget--) { s->failed_pc=0x0c076bccu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c076bce;
P_0c076bce: /* original 9368, guest PC 0x0c076bce */
if(!s->budget--) { s->failed_pc=0x0c076bceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca2u,2);
goto P_0c076bd0;
P_0c076bd0: /* original 2238, guest PC 0x0c076bd0 */
if(!s->budget--) { s->failed_pc=0x0c076bd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076bd2;
P_0c076bd2: /* original 8f04, guest PC 0x0c076bd2 */
if(!s->budget--) { s->failed_pc=0x0c076bd2u; return 0; }
cond=r[17]&1u;
r[6]=r[12];
if(!cond) { goto P_0c076bde; }
goto P_0c076bd6;
P_0c076bd4: /* original 66c3, guest PC 0x0c076bd4 */
if(!s->budget--) { s->failed_pc=0x0c076bd4u; return 0; }
r[6]=r[12];
goto P_0c076bd6;
P_0c076bd6: /* original 50bb, guest PC 0x0c076bd6 */
if(!s->budget--) { s->failed_pc=0x0c076bd6u; return 0; }
r[0]=read(ram,r[11]+44,4);
goto P_0c076bd8;
P_0c076bd8: /* original 6002, guest PC 0x0c076bd8 */
if(!s->budget--) { s->failed_pc=0x0c076bd8u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c076bda;
P_0c076bda: /* original c802, guest PC 0x0c076bda */
if(!s->budget--) { s->failed_pc=0x0c076bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c076bdc;
P_0c076bdc: /* original 8904, guest PC 0x0c076bdc */
if(!s->budget--) { s->failed_pc=0x0c076bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076be8; }
goto P_0c076bde;
P_0c076bde: /* original 9061, guest PC 0x0c076bde */
if(!s->budget--) { s->failed_pc=0x0c076bdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca4u,2);
goto P_0c076be0;
P_0c076be0: /* original 03ee, guest PC 0x0c076be0 */
if(!s->budget--) { s->failed_pc=0x0c076be0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076be2;
P_0c076be2: /* original 9060, guest PC 0x0c076be2 */
if(!s->budget--) { s->failed_pc=0x0c076be2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca6u,2);
goto P_0c076be4;
P_0c076be4: /* original 4329, guest PC 0x0c076be4 */
if(!s->budget--) { s->failed_pc=0x0c076be4u; return 0; }
r[3]>>=16;
goto P_0c076be6;
P_0c076be6: /* original 0d34, guest PC 0x0c076be6 */
if(!s->budget--) { s->failed_pc=0x0c076be6u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c076be8;
P_0c076be8: /* original 4f26, guest PC 0x0c076be8 */
if(!s->budget--) { s->failed_pc=0x0c076be8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c076bea;
P_0c076bea: /* original 64a3, guest PC 0x0c076bea */
if(!s->budget--) { s->failed_pc=0x0c076beau; return 0; }
r[4]=r[10];
goto P_0c076bec;
P_0c076bec: /* original 65d3, guest PC 0x0c076bec */
if(!s->budget--) { s->failed_pc=0x0c076becu; return 0; }
r[5]=r[13];
goto P_0c076bee;
P_0c076bee: /* original 6af6, guest PC 0x0c076bee */
if(!s->budget--) { s->failed_pc=0x0c076beeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c076bf0;
P_0c076bf0: /* original 6bf6, guest PC 0x0c076bf0 */
if(!s->budget--) { s->failed_pc=0x0c076bf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c076bf2;
P_0c076bf2: /* original 6cf6, guest PC 0x0c076bf2 */
if(!s->budget--) { s->failed_pc=0x0c076bf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c076bf4;
P_0c076bf4: /* original 6df6, guest PC 0x0c076bf4 */
if(!s->budget--) { s->failed_pc=0x0c076bf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c076bf6;
P_0c076bf6: /* original a000, guest PC 0x0c076bf6 */
if(!s->budget--) { s->failed_pc=0x0c076bf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c076bfa;
P_0c076bf8: /* original 6ef6, guest PC 0x0c076bf8 */
if(!s->budget--) { s->failed_pc=0x0c076bf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c076bfa;
P_0c076bfa: /* original 2fe6, guest PC 0x0c076bfa */
if(!s->budget--) { s->failed_pc=0x0c076bfau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c076bfc;
P_0c076bfc: /* original 2fd6, guest PC 0x0c076bfc */
if(!s->budget--) { s->failed_pc=0x0c076bfcu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c076bfe;
P_0c076bfe: /* original 2fc6, guest PC 0x0c076bfe */
if(!s->budget--) { s->failed_pc=0x0c076bfeu; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c076c00;
P_0c076c00: /* original 4f22, guest PC 0x0c076c00 */
if(!s->budget--) { s->failed_pc=0x0c076c00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c076c02;
P_0c076c02: /* original 9051, guest PC 0x0c076c02 */
if(!s->budget--) { s->failed_pc=0x0c076c02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca8u,2);
goto P_0c076c04;
P_0c076c04: /* original 9351, guest PC 0x0c076c04 */
if(!s->budget--) { s->failed_pc=0x0c076c04u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caau,2);
goto P_0c076c06;
P_0c076c06: /* original 3f0c, guest PC 0x0c076c06 */
if(!s->budget--) { s->failed_pc=0x0c076c06u; return 0; }
r[15]+=r[0];
goto P_0c076c08;
P_0c076c08: /* original 33fc, guest PC 0x0c076c08 */
if(!s->budget--) { s->failed_pc=0x0c076c08u; return 0; }
r[3]+=r[15];
goto P_0c076c0a;
P_0c076c0a: /* original 2342, guest PC 0x0c076c0a */
if(!s->budget--) { s->failed_pc=0x0c076c0au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c076c0c;
P_0c076c0c: /* original 924e, guest PC 0x0c076c0c */
if(!s->budget--) { s->failed_pc=0x0c076c0cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cacu,2);
goto P_0c076c0e;
P_0c076c0e: /* original 32fc, guest PC 0x0c076c0e */
if(!s->budget--) { s->failed_pc=0x0c076c0eu; return 0; }
r[2]+=r[15];
goto P_0c076c10;
P_0c076c10: /* original 2252, guest PC 0x0c076c10 */
if(!s->budget--) { s->failed_pc=0x0c076c10u; return 0; }
write(ram,r[2],r[5],4);
goto P_0c076c12;
P_0c076c12: /* original 934c, guest PC 0x0c076c12 */
if(!s->budget--) { s->failed_pc=0x0c076c12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caeu,2);
goto P_0c076c14;
P_0c076c14: /* original 33fc, guest PC 0x0c076c14 */
if(!s->budget--) { s->failed_pc=0x0c076c14u; return 0; }
r[3]+=r[15];
goto P_0c076c16;
P_0c076c16: /* original 2362, guest PC 0x0c076c16 */
if(!s->budget--) { s->failed_pc=0x0c076c16u; return 0; }
write(ram,r[3],r[6],4);
goto P_0c076c18;
P_0c076c18: /* original 904a, guest PC 0x0c076c18 */
if(!s->budget--) { s->failed_pc=0x0c076c18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb0u,2);
goto P_0c076c1a;
P_0c076c1a: /* original d22d, guest PC 0x0c076c1a */
if(!s->budget--) { s->failed_pc=0x0c076c1au; return 0; }
r[2]=read(ram,0x0c076cd0u,4);
goto P_0c076c1c;
P_0c076c1c: /* original 0f26, guest PC 0x0c076c1c */
if(!s->budget--) { s->failed_pc=0x0c076c1cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076c1e;
P_0c076c1e: /* original 9045, guest PC 0x0c076c1e */
if(!s->budget--) { s->failed_pc=0x0c076c1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cacu,2);
goto P_0c076c20;
P_0c076c20: /* original 0efe, guest PC 0x0c076c20 */
if(!s->budget--) { s->failed_pc=0x0c076c20u; return 0; }
r[14]=read(ram,r[15]+r[0],4);
goto P_0c076c22;
P_0c076c22: /* original 9044, guest PC 0x0c076c22 */
if(!s->budget--) { s->failed_pc=0x0c076c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caeu,2);
goto P_0c076c24;
P_0c076c24: /* original 0dfe, guest PC 0x0c076c24 */
if(!s->budget--) { s->failed_pc=0x0c076c24u; return 0; }
r[13]=read(ram,r[15]+r[0],4);
goto P_0c076c26;
P_0c076c26: /* original 9040, guest PC 0x0c076c26 */
if(!s->budget--) { s->failed_pc=0x0c076c26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076caau,2);
goto P_0c076c28;
P_0c076c28: /* original 0cfe, guest PC 0x0c076c28 */
if(!s->budget--) { s->failed_pc=0x0c076c28u; return 0; }
r[12]=read(ram,r[15]+r[0],4);
goto P_0c076c2a;
P_0c076c2a: /* original 9039, guest PC 0x0c076c2a */
if(!s->budget--) { s->failed_pc=0x0c076c2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca0u,2);
goto P_0c076c2c;
P_0c076c2c: /* original 03ee, guest PC 0x0c076c2c */
if(!s->budget--) { s->failed_pc=0x0c076c2cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076c2e;
P_0c076c2e: /* original 9040, guest PC 0x0c076c2e */
if(!s->budget--) { s->failed_pc=0x0c076c2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb2u,2);
goto P_0c076c30;
P_0c076c30: /* original 0f36, guest PC 0x0c076c30 */
if(!s->budget--) { s->failed_pc=0x0c076c30u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076c32;
P_0c076c32: /* original 903f, guest PC 0x0c076c32 */
if(!s->budget--) { s->failed_pc=0x0c076c32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb4u,2);
goto P_0c076c34;
P_0c076c34: /* original 62e2, guest PC 0x0c076c34 */
if(!s->budget--) { s->failed_pc=0x0c076c34u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c076c36;
P_0c076c36: /* original 0f26, guest PC 0x0c076c36 */
if(!s->budget--) { s->failed_pc=0x0c076c36u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076c38;
P_0c076c38: /* original e048, guest PC 0x0c076c38 */
if(!s->budget--) { s->failed_pc=0x0c076c38u; return 0; }
r[0]=0x00000048u;
goto P_0c076c3a;
P_0c076c3a: /* original 03ee, guest PC 0x0c076c3a */
if(!s->budget--) { s->failed_pc=0x0c076c3au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076c3c;
P_0c076c3c: /* original 903b, guest PC 0x0c076c3c */
if(!s->budget--) { s->failed_pc=0x0c076c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb6u,2);
goto P_0c076c3e;
P_0c076c3e: /* original 0f36, guest PC 0x0c076c3e */
if(!s->budget--) { s->failed_pc=0x0c076c3eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076c40;
P_0c076c40: /* original e061, guest PC 0x0c076c40 */
if(!s->budget--) { s->failed_pc=0x0c076c40u; return 0; }
r[0]=0x00000061u;
goto P_0c076c42;
P_0c076c42: /* original 02ec, guest PC 0x0c076c42 */
if(!s->budget--) { s->failed_pc=0x0c076c42u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076c44;
P_0c076c44: /* original e07c, guest PC 0x0c076c44 */
if(!s->budget--) { s->failed_pc=0x0c076c44u; return 0; }
r[0]=0x0000007cu;
goto P_0c076c46;
P_0c076c46: /* original e300, guest PC 0x0c076c46 */
if(!s->budget--) { s->failed_pc=0x0c076c46u; return 0; }
r[3]=0x00000000u;
goto P_0c076c48;
P_0c076c48: /* original 622c, guest PC 0x0c076c48 */
if(!s->budget--) { s->failed_pc=0x0c076c48u; return 0; }
r[2]=r[2]&255u;
goto P_0c076c4a;
P_0c076c4a: /* original 6133, guest PC 0x0c076c4a */
if(!s->budget--) { s->failed_pc=0x0c076c4au; return 0; }
r[1]=r[3];
goto P_0c076c4c;
P_0c076c4c: /* original 0f26, guest PC 0x0c076c4c */
if(!s->budget--) { s->failed_pc=0x0c076c4cu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076c4e;
P_0c076c4e: /* original e078, guest PC 0x0c076c4e */
if(!s->budget--) { s->failed_pc=0x0c076c4eu; return 0; }
r[0]=0x00000078u;
goto P_0c076c50;
P_0c076c50: /* original 0f36, guest PC 0x0c076c50 */
if(!s->budget--) { s->failed_pc=0x0c076c50u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076c52;
P_0c076c52: /* original 1f1e, guest PC 0x0c076c52 */
if(!s->budget--) { s->failed_pc=0x0c076c52u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c076c54;
P_0c076c54: /* original 9027, guest PC 0x0c076c54 */
if(!s->budget--) { s->failed_pc=0x0c076c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca6u,2);
goto P_0c076c56;
P_0c076c56: /* original 03ec, guest PC 0x0c076c56 */
if(!s->budget--) { s->failed_pc=0x0c076c56u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076c58;
P_0c076c58: /* original 633c, guest PC 0x0c076c58 */
if(!s->budget--) { s->failed_pc=0x0c076c58u; return 0; }
r[3]=r[3]&255u;
goto P_0c076c5a;
P_0c076c5a: /* original 1f31, guest PC 0x0c076c5a */
if(!s->budget--) { s->failed_pc=0x0c076c5au; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c076c5c;
P_0c076c5c: /* original 9029, guest PC 0x0c076c5c */
if(!s->budget--) { s->failed_pc=0x0c076c5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb2u,2);
goto P_0c076c5e;
P_0c076c5e: /* original d21a, guest PC 0x0c076c5e */
if(!s->budget--) { s->failed_pc=0x0c076c5eu; return 0; }
r[2]=read(ram,0x0c076cc8u,4);
goto P_0c076c60;
P_0c076c60: /* original 01fe, guest PC 0x0c076c60 */
if(!s->budget--) { s->failed_pc=0x0c076c60u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076c62;
P_0c076c62: /* original 2128, guest PC 0x0c076c62 */
if(!s->budget--) { s->failed_pc=0x0c076c62u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076c64;
P_0c076c64: /* original 8938, guest PC 0x0c076c64 */
if(!s->budget--) { s->failed_pc=0x0c076c64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076cd8; }
goto P_0c076c66;
P_0c076c66: /* original 9024, guest PC 0x0c076c66 */
if(!s->budget--) { s->failed_pc=0x0c076c66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb2u,2);
goto P_0c076c68;
P_0c076c68: /* original e100, guest PC 0x0c076c68 */
if(!s->budget--) { s->failed_pc=0x0c076c68u; return 0; }
r[1]=0x00000000u;
goto P_0c076c6a;
P_0c076c6a: /* original 6313, guest PC 0x0c076c6a */
if(!s->budget--) { s->failed_pc=0x0c076c6au; return 0; }
r[3]=r[1];
goto P_0c076c6c;
P_0c076c6c: /* original 0f16, guest PC 0x0c076c6c */
if(!s->budget--) { s->failed_pc=0x0c076c6cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076c6e;
P_0c076c6e: /* original 9017, guest PC 0x0c076c6e */
if(!s->budget--) { s->failed_pc=0x0c076c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ca0u,2);
goto P_0c076c70;
P_0c076c70: /* original 0e16, guest PC 0x0c076c70 */
if(!s->budget--) { s->failed_pc=0x0c076c70u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c076c72;
P_0c076c72: /* original 7010, guest PC 0x0c076c72 */
if(!s->budget--) { s->failed_pc=0x0c076c72u; return 0; }
r[0]+=0x00000010u;
goto P_0c076c74;
P_0c076c74: /* original 0e36, guest PC 0x0c076c74 */
if(!s->budget--) { s->failed_pc=0x0c076c74u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c076c76;
P_0c076c76: /* original 70f8, guest PC 0x0c076c76 */
if(!s->budget--) { s->failed_pc=0x0c076c76u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c076c78;
P_0c076c78: /* original 0e35, guest PC 0x0c076c78 */
if(!s->budget--) { s->failed_pc=0x0c076c78u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c076c7a;
P_0c076c7a: /* original 700c, guest PC 0x0c076c7a */
if(!s->budget--) { s->failed_pc=0x0c076c7au; return 0; }
r[0]+=0x0000000cu;
goto P_0c076c7c;
P_0c076c7c: /* original 0e36, guest PC 0x0c076c7c */
if(!s->budget--) { s->failed_pc=0x0c076c7cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c076c7e;
P_0c076c7e: /* original 7014, guest PC 0x0c076c7e */
if(!s->budget--) { s->failed_pc=0x0c076c7eu; return 0; }
r[0]+=0x00000014u;
goto P_0c076c80;
P_0c076c80: /* original 0e34, guest PC 0x0c076c80 */
if(!s->budget--) { s->failed_pc=0x0c076c80u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c82;
P_0c076c82: /* original 7001, guest PC 0x0c076c82 */
if(!s->budget--) { s->failed_pc=0x0c076c82u; return 0; }
r[0]+=0x00000001u;
goto P_0c076c84;
P_0c076c84: /* original 0e34, guest PC 0x0c076c84 */
if(!s->budget--) { s->failed_pc=0x0c076c84u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c86;
P_0c076c86: /* original 9017, guest PC 0x0c076c86 */
if(!s->budget--) { s->failed_pc=0x0c076c86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cb8u,2);
goto P_0c076c88;
P_0c076c88: /* original 53f1, guest PC 0x0c076c88 */
if(!s->budget--) { s->failed_pc=0x0c076c88u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c076c8a;
P_0c076c8a: /* original 0e34, guest PC 0x0c076c8a */
if(!s->budget--) { s->failed_pc=0x0c076c8au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c8c;
P_0c076c8c: /* original e300, guest PC 0x0c076c8c */
if(!s->budget--) { s->failed_pc=0x0c076c8cu; return 0; }
r[3]=0x00000000u;
goto P_0c076c8e;
P_0c076c8e: /* original 9014, guest PC 0x0c076c8e */
if(!s->budget--) { s->failed_pc=0x0c076c8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076cbau,2);
goto P_0c076c90;
P_0c076c90: /* original 51f1, guest PC 0x0c076c90 */
if(!s->budget--) { s->failed_pc=0x0c076c90u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c076c92;
P_0c076c92: /* original 0e14, guest PC 0x0c076c92 */
if(!s->budget--) { s->failed_pc=0x0c076c92u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c076c94;
P_0c076c94: /* original 7081, guest PC 0x0c076c94 */
if(!s->budget--) { s->failed_pc=0x0c076c94u; return 0; }
r[0]+=0xffffff81u;
goto P_0c076c96;
P_0c076c96: /* original 6133, guest PC 0x0c076c96 */
if(!s->budget--) { s->failed_pc=0x0c076c96u; return 0; }
r[1]=r[3];
goto P_0c076c98;
P_0c076c98: /* original 0e34, guest PC 0x0c076c98 */
if(!s->budget--) { s->failed_pc=0x0c076c98u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c076c9a;
P_0c076c9a: /* original d30e, guest PC 0x0c076c9a */
if(!s->budget--) { s->failed_pc=0x0c076c9au; return 0; }
r[3]=read(ram,0x0c076cd4u,4);
goto P_0c076c9c;
P_0c076c9c: /* original 432b, guest PC 0x0c076c9c */
if(!s->budget--) { s->failed_pc=0x0c076c9cu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c076c9e: /* original 0009, guest PC 0x0c076c9e */
if(!s->budget--) { s->failed_pc=0x0c076c9eu; return 0; }
return vf3_matrix_family(0x0c076ca0u,s,ram);
P_0c076cd8: /* original 9067, guest PC 0x0c076cd8 */
if(!s->budget--) { s->failed_pc=0x0c076cd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076cda;
P_0c076cda: /* original d339, guest PC 0x0c076cda */
if(!s->budget--) { s->failed_pc=0x0c076cdau; return 0; }
r[3]=read(ram,0x0c076dc0u,4);
goto P_0c076cdc;
P_0c076cdc: /* original 02fe, guest PC 0x0c076cdc */
if(!s->budget--) { s->failed_pc=0x0c076cdcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076cde;
P_0c076cde: /* original 2238, guest PC 0x0c076cde */
if(!s->budget--) { s->failed_pc=0x0c076cdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076ce0;
P_0c076ce0: /* original 8904, guest PC 0x0c076ce0 */
if(!s->budget--) { s->failed_pc=0x0c076ce0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076cec; }
goto P_0c076ce2;
P_0c076ce2: /* original 9062, guest PC 0x0c076ce2 */
if(!s->budget--) { s->failed_pc=0x0c076ce2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076ce4;
P_0c076ce4: /* original d237, guest PC 0x0c076ce4 */
if(!s->budget--) { s->failed_pc=0x0c076ce4u; return 0; }
r[2]=read(ram,0x0c076dc4u,4);
goto P_0c076ce6;
P_0c076ce6: /* original 01fe, guest PC 0x0c076ce6 */
if(!s->budget--) { s->failed_pc=0x0c076ce6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076ce8;
P_0c076ce8: /* original a004, guest PC 0x0c076ce8 */
if(!s->budget--) { s->failed_pc=0x0c076ce8u; return 0; }
r[1]|=r[2];
goto P_0c076cf4;
P_0c076cea: /* original 212b, guest PC 0x0c076cea */
if(!s->budget--) { s->failed_pc=0x0c076ceau; return 0; }
r[1]|=r[2];
goto P_0c076cec;
P_0c076cec: /* original 905d, guest PC 0x0c076cec */
if(!s->budget--) { s->failed_pc=0x0c076cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076cee;
P_0c076cee: /* original d236, guest PC 0x0c076cee */
if(!s->budget--) { s->failed_pc=0x0c076ceeu; return 0; }
r[2]=read(ram,0x0c076dc8u,4);
goto P_0c076cf0;
P_0c076cf0: /* original 01fe, guest PC 0x0c076cf0 */
if(!s->budget--) { s->failed_pc=0x0c076cf0u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076cf2;
P_0c076cf2: /* original 2129, guest PC 0x0c076cf2 */
if(!s->budget--) { s->failed_pc=0x0c076cf2u; return 0; }
r[1]&=r[2];
goto P_0c076cf4;
P_0c076cf4: /* original d335, guest PC 0x0c076cf4 */
if(!s->budget--) { s->failed_pc=0x0c076cf4u; return 0; }
r[3]=read(ram,0x0c076dccu,4);
goto P_0c076cf6;
P_0c076cf6: /* original 6213, guest PC 0x0c076cf6 */
if(!s->budget--) { s->failed_pc=0x0c076cf6u; return 0; }
r[2]=r[1];
goto P_0c076cf8;
P_0c076cf8: /* original 9057, guest PC 0x0c076cf8 */
if(!s->budget--) { s->failed_pc=0x0c076cf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076cfa;
P_0c076cfa: /* original 2239, guest PC 0x0c076cfa */
if(!s->budget--) { s->failed_pc=0x0c076cfau; return 0; }
r[2]&=r[3];
goto P_0c076cfc;
P_0c076cfc: /* original 0f26, guest PC 0x0c076cfc */
if(!s->budget--) { s->failed_pc=0x0c076cfcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076cfe;
P_0c076cfe: /* original 9055, guest PC 0x0c076cfe */
if(!s->budget--) { s->failed_pc=0x0c076cfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dacu,2);
goto P_0c076d00;
P_0c076d00: /* original 01ee, guest PC 0x0c076d00 */
if(!s->budget--) { s->failed_pc=0x0c076d00u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c076d02;
P_0c076d02: /* original 2118, guest PC 0x0c076d02 */
if(!s->budget--) { s->failed_pc=0x0c076d02u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c076d04;
P_0c076d04: /* original 890a, guest PC 0x0c076d04 */
if(!s->budget--) { s->failed_pc=0x0c076d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076d1c; }
goto P_0c076d06;
P_0c076d06: /* original 9052, guest PC 0x0c076d06 */
if(!s->budget--) { s->failed_pc=0x0c076d06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daeu,2);
goto P_0c076d08;
P_0c076d08: /* original 01ed, guest PC 0x0c076d08 */
if(!s->budget--) { s->failed_pc=0x0c076d08u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d0a;
P_0c076d0a: /* original 2118, guest PC 0x0c076d0a */
if(!s->budget--) { s->failed_pc=0x0c076d0au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c076d0c;
P_0c076d0c: /* original 8903, guest PC 0x0c076d0c */
if(!s->budget--) { s->failed_pc=0x0c076d0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076d16; }
goto P_0c076d0e;
P_0c076d0e: /* original 03ed, guest PC 0x0c076d0e */
if(!s->budget--) { s->failed_pc=0x0c076d0eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d10;
P_0c076d10: /* original 73ff, guest PC 0x0c076d10 */
if(!s->budget--) { s->failed_pc=0x0c076d10u; return 0; }
r[3]+=0xffffffffu;
goto P_0c076d12;
P_0c076d12: /* original a003, guest PC 0x0c076d12 */
if(!s->budget--) { s->failed_pc=0x0c076d12u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c076d1c;
P_0c076d14: /* original 0e35, guest PC 0x0c076d14 */
if(!s->budget--) { s->failed_pc=0x0c076d14u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c076d16;
P_0c076d16: /* original 9049, guest PC 0x0c076d16 */
if(!s->budget--) { s->failed_pc=0x0c076d16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dacu,2);
goto P_0c076d18;
P_0c076d18: /* original e100, guest PC 0x0c076d18 */
if(!s->budget--) { s->failed_pc=0x0c076d18u; return 0; }
r[1]=0x00000000u;
goto P_0c076d1a;
P_0c076d1a: /* original 0e16, guest PC 0x0c076d1a */
if(!s->budget--) { s->failed_pc=0x0c076d1au; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c076d1c;
P_0c076d1c: /* original 9048, guest PC 0x0c076d1c */
if(!s->budget--) { s->failed_pc=0x0c076d1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db0u,2);
goto P_0c076d1e;
P_0c076d1e: /* original d32c, guest PC 0x0c076d1e */
if(!s->budget--) { s->failed_pc=0x0c076d1eu; return 0; }
r[3]=read(ram,0x0c076dd0u,4);
goto P_0c076d20;
P_0c076d20: /* original 02fe, guest PC 0x0c076d20 */
if(!s->budget--) { s->failed_pc=0x0c076d20u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076d22;
P_0c076d22: /* original 2238, guest PC 0x0c076d22 */
if(!s->budget--) { s->failed_pc=0x0c076d22u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d24;
P_0c076d24: /* original 890c, guest PC 0x0c076d24 */
if(!s->budget--) { s->failed_pc=0x0c076d24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076d40; }
goto P_0c076d26;
P_0c076d26: /* original 9044, guest PC 0x0c076d26 */
if(!s->budget--) { s->failed_pc=0x0c076d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db2u,2);
goto P_0c076d28;
P_0c076d28: /* original e200, guest PC 0x0c076d28 */
if(!s->budget--) { s->failed_pc=0x0c076d28u; return 0; }
r[2]=0x00000000u;
goto P_0c076d2a;
P_0c076d2a: /* original 6123, guest PC 0x0c076d2a */
if(!s->budget--) { s->failed_pc=0x0c076d2au; return 0; }
r[1]=r[2];
goto P_0c076d2c;
P_0c076d2c: /* original 0e26, guest PC 0x0c076d2c */
if(!s->budget--) { s->failed_pc=0x0c076d2cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c076d2e;
P_0c076d2e: /* original 70f8, guest PC 0x0c076d2e */
if(!s->budget--) { s->failed_pc=0x0c076d2eu; return 0; }
r[0]+=0xfffffff8u;
goto P_0c076d30;
P_0c076d30: /* original 0e15, guest PC 0x0c076d30 */
if(!s->budget--) { s->failed_pc=0x0c076d30u; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c076d32;
P_0c076d32: /* original 903a, guest PC 0x0c076d32 */
if(!s->budget--) { s->failed_pc=0x0c076d32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076d34;
P_0c076d34: /* original d222, guest PC 0x0c076d34 */
if(!s->budget--) { s->failed_pc=0x0c076d34u; return 0; }
r[2]=read(ram,0x0c076dc0u,4);
goto P_0c076d36;
P_0c076d36: /* original 01fe, guest PC 0x0c076d36 */
if(!s->budget--) { s->failed_pc=0x0c076d36u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076d38;
P_0c076d38: /* original 9037, guest PC 0x0c076d38 */
if(!s->budget--) { s->failed_pc=0x0c076d38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076daau,2);
goto P_0c076d3a;
P_0c076d3a: /* original 212b, guest PC 0x0c076d3a */
if(!s->budget--) { s->failed_pc=0x0c076d3au; return 0; }
r[1]|=r[2];
goto P_0c076d3c;
P_0c076d3c: /* original a092, guest PC 0x0c076d3c */
if(!s->budget--) { s->failed_pc=0x0c076d3cu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076e64;
P_0c076d3e: /* original 0f16, guest PC 0x0c076d3e */
if(!s->budget--) { s->failed_pc=0x0c076d3eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076d40;
P_0c076d40: /* original 9037, guest PC 0x0c076d40 */
if(!s->budget--) { s->failed_pc=0x0c076d40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db2u,2);
goto P_0c076d42;
P_0c076d42: /* original 03ee, guest PC 0x0c076d42 */
if(!s->budget--) { s->failed_pc=0x0c076d42u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076d44;
P_0c076d44: /* original e070, guest PC 0x0c076d44 */
if(!s->budget--) { s->failed_pc=0x0c076d44u; return 0; }
r[0]=0x00000070u;
goto P_0c076d46;
P_0c076d46: /* original 0f36, guest PC 0x0c076d46 */
if(!s->budget--) { s->failed_pc=0x0c076d46u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076d48;
P_0c076d48: /* original 9034, guest PC 0x0c076d48 */
if(!s->budget--) { s->failed_pc=0x0c076d48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db4u,2);
goto P_0c076d4a;
P_0c076d4a: /* original 02ed, guest PC 0x0c076d4a */
if(!s->budget--) { s->failed_pc=0x0c076d4au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d4c;
P_0c076d4c: /* original 4215, guest PC 0x0c076d4c */
if(!s->budget--) { s->failed_pc=0x0c076d4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c076d4e;
P_0c076d4e: /* original 8b04, guest PC 0x0c076d4e */
if(!s->budget--) { s->failed_pc=0x0c076d4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076d5a; }
goto P_0c076d50;
P_0c076d50: /* original 9031, guest PC 0x0c076d50 */
if(!s->budget--) { s->failed_pc=0x0c076d50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d52;
P_0c076d52: /* original d320, guest PC 0x0c076d52 */
if(!s->budget--) { s->failed_pc=0x0c076d52u; return 0; }
r[3]=read(ram,0x0c076dd4u,4);
goto P_0c076d54;
P_0c076d54: /* original 02fe, guest PC 0x0c076d54 */
if(!s->budget--) { s->failed_pc=0x0c076d54u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076d56;
P_0c076d56: /* original 2238, guest PC 0x0c076d56 */
if(!s->budget--) { s->failed_pc=0x0c076d56u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d58;
P_0c076d58: /* original 8b42, guest PC 0x0c076d58 */
if(!s->budget--) { s->failed_pc=0x0c076d58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076de0; }
goto P_0c076d5a;
P_0c076d5a: /* original 902c, guest PC 0x0c076d5a */
if(!s->budget--) { s->failed_pc=0x0c076d5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d5c;
P_0c076d5c: /* original d31e, guest PC 0x0c076d5c */
if(!s->budget--) { s->failed_pc=0x0c076d5cu; return 0; }
r[3]=read(ram,0x0c076dd8u,4);
goto P_0c076d5e;
P_0c076d5e: /* original 01fe, guest PC 0x0c076d5e */
if(!s->budget--) { s->failed_pc=0x0c076d5eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076d60;
P_0c076d60: /* original 2138, guest PC 0x0c076d60 */
if(!s->budget--) { s->failed_pc=0x0c076d60u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076d62;
P_0c076d62: /* original 8b01, guest PC 0x0c076d62 */
if(!s->budget--) { s->failed_pc=0x0c076d62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076d68; }
goto P_0c076d64;
P_0c076d64: /* original a076, guest PC 0x0c076d64 */
if(!s->budget--) { s->failed_pc=0x0c076d64u; return 0; }
goto P_0c076e54;
P_0c076d66: /* original 0009, guest PC 0x0c076d66 */
if(!s->budget--) { s->failed_pc=0x0c076d66u; return 0; }
goto P_0c076d68;
P_0c076d68: /* original 9025, guest PC 0x0c076d68 */
if(!s->budget--) { s->failed_pc=0x0c076d68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d6a;
P_0c076d6a: /* original d31c, guest PC 0x0c076d6a */
if(!s->budget--) { s->failed_pc=0x0c076d6au; return 0; }
r[3]=read(ram,0x0c076ddcu,4);
goto P_0c076d6c;
P_0c076d6c: /* original 02fe, guest PC 0x0c076d6c */
if(!s->budget--) { s->failed_pc=0x0c076d6cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076d6e;
P_0c076d6e: /* original 2238, guest PC 0x0c076d6e */
if(!s->budget--) { s->failed_pc=0x0c076d6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d70;
P_0c076d70: /* original 8b08, guest PC 0x0c076d70 */
if(!s->budget--) { s->failed_pc=0x0c076d70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076d84; }
goto P_0c076d72;
P_0c076d72: /* original 9020, guest PC 0x0c076d72 */
if(!s->budget--) { s->failed_pc=0x0c076d72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db6u,2);
goto P_0c076d74;
P_0c076d74: /* original d313, guest PC 0x0c076d74 */
if(!s->budget--) { s->failed_pc=0x0c076d74u; return 0; }
r[3]=read(ram,0x0c076dc4u,4);
goto P_0c076d76;
P_0c076d76: /* original 01fe, guest PC 0x0c076d76 */
if(!s->budget--) { s->failed_pc=0x0c076d76u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076d78;
P_0c076d78: /* original 2138, guest PC 0x0c076d78 */
if(!s->budget--) { s->failed_pc=0x0c076d78u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076d7a;
P_0c076d7a: /* original 8957, guest PC 0x0c076d7a */
if(!s->budget--) { s->failed_pc=0x0c076d7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e2c; }
goto P_0c076d7c;
P_0c076d7c: /* original 901a, guest PC 0x0c076d7c */
if(!s->budget--) { s->failed_pc=0x0c076d7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db4u,2);
goto P_0c076d7e;
P_0c076d7e: /* original 03ed, guest PC 0x0c076d7e */
if(!s->budget--) { s->failed_pc=0x0c076d7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076d80;
P_0c076d80: /* original 4315, guest PC 0x0c076d80 */
if(!s->budget--) { s->failed_pc=0x0c076d80u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c076d82;
P_0c076d82: /* original 8967, guest PC 0x0c076d82 */
if(!s->budget--) { s->failed_pc=0x0c076d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e54; }
goto P_0c076d84;
P_0c076d84: /* original 9018, guest PC 0x0c076d84 */
if(!s->budget--) { s->failed_pc=0x0c076d84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076db8u,2);
goto P_0c076d86;
P_0c076d86: /* original 03ee, guest PC 0x0c076d86 */
if(!s->budget--) { s->failed_pc=0x0c076d86u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076d88;
P_0c076d88: /* original 2338, guest PC 0x0c076d88 */
if(!s->budget--) { s->failed_pc=0x0c076d88u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c076d8a;
P_0c076d8a: /* original 8b4f, guest PC 0x0c076d8a */
if(!s->budget--) { s->failed_pc=0x0c076d8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076d8c;
P_0c076d8c: /* original 9015, guest PC 0x0c076d8c */
if(!s->budget--) { s->failed_pc=0x0c076d8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dbau,2);
goto P_0c076d8e;
P_0c076d8e: /* original 03ee, guest PC 0x0c076d8e */
if(!s->budget--) { s->failed_pc=0x0c076d8eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c076d90;
P_0c076d90: /* original 2338, guest PC 0x0c076d90 */
if(!s->budget--) { s->failed_pc=0x0c076d90u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c076d92;
P_0c076d92: /* original 8b4b, guest PC 0x0c076d92 */
if(!s->budget--) { s->failed_pc=0x0c076d92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076d94;
P_0c076d94: /* original e04c, guest PC 0x0c076d94 */
if(!s->budget--) { s->failed_pc=0x0c076d94u; return 0; }
r[0]=0x0000004cu;
goto P_0c076d96;
P_0c076d96: /* original 9311, guest PC 0x0c076d96 */
if(!s->budget--) { s->failed_pc=0x0c076d96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dbcu,2);
goto P_0c076d98;
P_0c076d98: /* original 02ee, guest PC 0x0c076d98 */
if(!s->budget--) { s->failed_pc=0x0c076d98u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c076d9a;
P_0c076d9a: /* original 2238, guest PC 0x0c076d9a */
if(!s->budget--) { s->failed_pc=0x0c076d9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076d9c;
P_0c076d9c: /* original 8b5a, guest PC 0x0c076d9c */
if(!s->budget--) { s->failed_pc=0x0c076d9cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e54; }
goto P_0c076d9e;
P_0c076d9e: /* original 01ee, guest PC 0x0c076d9e */
if(!s->budget--) { s->failed_pc=0x0c076d9eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c076da0;
P_0c076da0: /* original 930d, guest PC 0x0c076da0 */
if(!s->budget--) { s->failed_pc=0x0c076da0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076dbeu,2);
goto P_0c076da2;
P_0c076da2: /* original 2138, guest PC 0x0c076da2 */
if(!s->budget--) { s->failed_pc=0x0c076da2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076da4;
P_0c076da4: /* original 8b5e, guest PC 0x0c076da4 */
if(!s->budget--) { s->failed_pc=0x0c076da4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e64; }
goto P_0c076da6;
P_0c076da6: /* original a041, guest PC 0x0c076da6 */
if(!s->budget--) { s->failed_pc=0x0c076da6u; return 0; }
goto P_0c076e2c;
P_0c076da8: /* original 0009, guest PC 0x0c076da8 */
if(!s->budget--) { s->failed_pc=0x0c076da8u; return 0; }
return vf3_matrix_family(0x0c076daau,s,ram);
P_0c076de0: /* original 906c, guest PC 0x0c076de0 */
if(!s->budget--) { s->failed_pc=0x0c076de0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076de2;
P_0c076de2: /* original d339, guest PC 0x0c076de2 */
if(!s->budget--) { s->failed_pc=0x0c076de2u; return 0; }
r[3]=read(ram,0x0c076ec8u,4);
goto P_0c076de4;
P_0c076de4: /* original 02fe, guest PC 0x0c076de4 */
if(!s->budget--) { s->failed_pc=0x0c076de4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076de6;
P_0c076de6: /* original 2238, guest PC 0x0c076de6 */
if(!s->budget--) { s->failed_pc=0x0c076de6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076de8;
P_0c076de8: /* original 8b20, guest PC 0x0c076de8 */
if(!s->budget--) { s->failed_pc=0x0c076de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076dea;
P_0c076dea: /* original 9068, guest PC 0x0c076dea */
if(!s->budget--) { s->failed_pc=0x0c076deau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebeu,2);
goto P_0c076dec;
P_0c076dec: /* original e30d, guest PC 0x0c076dec */
if(!s->budget--) { s->failed_pc=0x0c076decu; return 0; }
r[3]=0x0000000du;
goto P_0c076dee;
P_0c076dee: /* original 01fe, guest PC 0x0c076dee */
if(!s->budget--) { s->failed_pc=0x0c076deeu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076df0;
P_0c076df0: /* original e06c, guest PC 0x0c076df0 */
if(!s->budget--) { s->failed_pc=0x0c076df0u; return 0; }
r[0]=0x0000006cu;
goto P_0c076df2;
P_0c076df2: /* original 413d, guest PC 0x0c076df2 */
if(!s->budget--) { s->failed_pc=0x0c076df2u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?r[1]>>((-r[3])&31u):0):r[1]<<(r[3]&31u);
goto P_0c076df4;
P_0c076df4: /* original 0f16, guest PC 0x0c076df4 */
if(!s->budget--) { s->failed_pc=0x0c076df4u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076df6;
P_0c076df6: /* original 9061, guest PC 0x0c076df6 */
if(!s->budget--) { s->failed_pc=0x0c076df6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076df8;
P_0c076df8: /* original 02fe, guest PC 0x0c076df8 */
if(!s->budget--) { s->failed_pc=0x0c076df8u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076dfa;
P_0c076dfa: /* original 6013, guest PC 0x0c076dfa */
if(!s->budget--) { s->failed_pc=0x0c076dfau; return 0; }
r[0]=r[1];
goto P_0c076dfc;
P_0c076dfc: /* original 202b, guest PC 0x0c076dfc */
if(!s->budget--) { s->failed_pc=0x0c076dfcu; return 0; }
r[0]|=r[2];
goto P_0c076dfe;
P_0c076dfe: /* original 62f3, guest PC 0x0c076dfe */
if(!s->budget--) { s->failed_pc=0x0c076dfeu; return 0; }
r[2]=r[15];
goto P_0c076e00;
P_0c076e00: /* original 726c, guest PC 0x0c076e00 */
if(!s->budget--) { s->failed_pc=0x0c076e00u; return 0; }
r[2]+=0x0000006cu;
goto P_0c076e02;
P_0c076e02: /* original 2202, guest PC 0x0c076e02 */
if(!s->budget--) { s->failed_pc=0x0c076e02u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c076e04;
P_0c076e04: /* original d131, guest PC 0x0c076e04 */
if(!s->budget--) { s->failed_pc=0x0c076e04u; return 0; }
r[1]=read(ram,0x0c076eccu,4);
goto P_0c076e06;
P_0c076e06: /* original 2018, guest PC 0x0c076e06 */
if(!s->budget--) { s->failed_pc=0x0c076e06u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c076e08;
P_0c076e08: /* original 8907, guest PC 0x0c076e08 */
if(!s->budget--) { s->failed_pc=0x0c076e08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e1a; }
goto P_0c076e0a;
P_0c076e0a: /* original e064, guest PC 0x0c076e0a */
if(!s->budget--) { s->failed_pc=0x0c076e0au; return 0; }
r[0]=0x00000064u;
goto P_0c076e0c;
P_0c076e0c: /* original 02ed, guest PC 0x0c076e0c */
if(!s->budget--) { s->failed_pc=0x0c076e0cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076e0e;
P_0c076e0e: /* original 2228, guest PC 0x0c076e0e */
if(!s->budget--) { s->failed_pc=0x0c076e0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076e10;
P_0c076e10: /* original 890c, guest PC 0x0c076e10 */
if(!s->budget--) { s->failed_pc=0x0c076e10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e2c; }
goto P_0c076e12;
P_0c076e12: /* original 51ee, guest PC 0x0c076e12 */
if(!s->budget--) { s->failed_pc=0x0c076e12u; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c076e14;
P_0c076e14: /* original d32e, guest PC 0x0c076e14 */
if(!s->budget--) { s->failed_pc=0x0c076e14u; return 0; }
r[3]=read(ram,0x0c076ed0u,4);
goto P_0c076e16;
P_0c076e16: /* original 2138, guest PC 0x0c076e16 */
if(!s->budget--) { s->failed_pc=0x0c076e16u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c076e18;
P_0c076e18: /* original 8908, guest PC 0x0c076e18 */
if(!s->budget--) { s->failed_pc=0x0c076e18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e2c; }
goto P_0c076e1a;
P_0c076e1a: /* original e04c, guest PC 0x0c076e1a */
if(!s->budget--) { s->failed_pc=0x0c076e1au; return 0; }
r[0]=0x0000004cu;
goto P_0c076e1c;
P_0c076e1c: /* original 9350, guest PC 0x0c076e1c */
if(!s->budget--) { s->failed_pc=0x0c076e1cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec0u,2);
goto P_0c076e1e;
P_0c076e1e: /* original 02ee, guest PC 0x0c076e1e */
if(!s->budget--) { s->failed_pc=0x0c076e1eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c076e20;
P_0c076e20: /* original 2238, guest PC 0x0c076e20 */
if(!s->budget--) { s->failed_pc=0x0c076e20u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076e22;
P_0c076e22: /* original 8b03, guest PC 0x0c076e22 */
if(!s->budget--) { s->failed_pc=0x0c076e22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e2c; }
goto P_0c076e24;
P_0c076e24: /* original e070, guest PC 0x0c076e24 */
if(!s->budget--) { s->failed_pc=0x0c076e24u; return 0; }
r[0]=0x00000070u;
goto P_0c076e26;
P_0c076e26: /* original 01fe, guest PC 0x0c076e26 */
if(!s->budget--) { s->failed_pc=0x0c076e26u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e28;
P_0c076e28: /* original 2118, guest PC 0x0c076e28 */
if(!s->budget--) { s->failed_pc=0x0c076e28u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c076e2a;
P_0c076e2a: /* original 891b, guest PC 0x0c076e2a */
if(!s->budget--) { s->failed_pc=0x0c076e2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e64; }
goto P_0c076e2c;
P_0c076e2c: /* original 9049, guest PC 0x0c076e2c */
if(!s->budget--) { s->failed_pc=0x0c076e2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec2u,2);
goto P_0c076e2e;
P_0c076e2e: /* original d329, guest PC 0x0c076e2e */
if(!s->budget--) { s->failed_pc=0x0c076e2eu; return 0; }
r[3]=read(ram,0x0c076ed4u,4);
goto P_0c076e30;
P_0c076e30: /* original 01fe, guest PC 0x0c076e30 */
if(!s->budget--) { s->failed_pc=0x0c076e30u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e32;
P_0c076e32: /* original 9046, guest PC 0x0c076e32 */
if(!s->budget--) { s->failed_pc=0x0c076e32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec2u,2);
goto P_0c076e34;
P_0c076e34: /* original 213b, guest PC 0x0c076e34 */
if(!s->budget--) { s->failed_pc=0x0c076e34u; return 0; }
r[1]|=r[3];
goto P_0c076e36;
P_0c076e36: /* original 0f16, guest PC 0x0c076e36 */
if(!s->budget--) { s->failed_pc=0x0c076e36u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076e38;
P_0c076e38: /* original e04c, guest PC 0x0c076e38 */
if(!s->budget--) { s->failed_pc=0x0c076e38u; return 0; }
r[0]=0x0000004cu;
goto P_0c076e3a;
P_0c076e3a: /* original 02ee, guest PC 0x0c076e3a */
if(!s->budget--) { s->failed_pc=0x0c076e3au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c076e3c;
P_0c076e3c: /* original e06c, guest PC 0x0c076e3c */
if(!s->budget--) { s->failed_pc=0x0c076e3cu; return 0; }
r[0]=0x0000006cu;
goto P_0c076e3e;
P_0c076e3e: /* original 0f26, guest PC 0x0c076e3e */
if(!s->budget--) { s->failed_pc=0x0c076e3eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076e40;
P_0c076e40: /* original e06c, guest PC 0x0c076e40 */
if(!s->budget--) { s->failed_pc=0x0c076e40u; return 0; }
r[0]=0x0000006cu;
goto P_0c076e42;
P_0c076e42: /* original 01fe, guest PC 0x0c076e42 */
if(!s->budget--) { s->failed_pc=0x0c076e42u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e44;
P_0c076e44: /* original d224, guest PC 0x0c076e44 */
if(!s->budget--) { s->failed_pc=0x0c076e44u; return 0; }
r[2]=read(ram,0x0c076ed8u,4);
goto P_0c076e46;
P_0c076e46: /* original 2128, guest PC 0x0c076e46 */
if(!s->budget--) { s->failed_pc=0x0c076e46u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076e48;
P_0c076e48: /* original 8b04, guest PC 0x0c076e48 */
if(!s->budget--) { s->failed_pc=0x0c076e48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076e54; }
goto P_0c076e4a;
P_0c076e4a: /* original e06c, guest PC 0x0c076e4a */
if(!s->budget--) { s->failed_pc=0x0c076e4au; return 0; }
r[0]=0x0000006cu;
goto P_0c076e4c;
P_0c076e4c: /* original d123, guest PC 0x0c076e4c */
if(!s->budget--) { s->failed_pc=0x0c076e4cu; return 0; }
r[1]=read(ram,0x0c076edcu,4);
goto P_0c076e4e;
P_0c076e4e: /* original 00fe, guest PC 0x0c076e4e */
if(!s->budget--) { s->failed_pc=0x0c076e4eu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076e50;
P_0c076e50: /* original 2018, guest PC 0x0c076e50 */
if(!s->budget--) { s->failed_pc=0x0c076e50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c076e52;
P_0c076e52: /* original 8959, guest PC 0x0c076e52 */
if(!s->budget--) { s->failed_pc=0x0c076e52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076f08; }
goto P_0c076e54;
P_0c076e54: /* original e070, guest PC 0x0c076e54 */
if(!s->budget--) { s->failed_pc=0x0c076e54u; return 0; }
r[0]=0x00000070u;
goto P_0c076e56;
P_0c076e56: /* original 02fe, guest PC 0x0c076e56 */
if(!s->budget--) { s->failed_pc=0x0c076e56u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076e58;
P_0c076e58: /* original 2228, guest PC 0x0c076e58 */
if(!s->budget--) { s->failed_pc=0x0c076e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076e5a;
P_0c076e5a: /* original 8903, guest PC 0x0c076e5a */
if(!s->budget--) { s->failed_pc=0x0c076e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e64; }
goto P_0c076e5c;
P_0c076e5c: /* original 9032, guest PC 0x0c076e5c */
if(!s->budget--) { s->failed_pc=0x0c076e5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ec4u,2);
goto P_0c076e5e;
P_0c076e5e: /* original 02ed, guest PC 0x0c076e5e */
if(!s->budget--) { s->failed_pc=0x0c076e5eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c076e60;
P_0c076e60: /* original 2228, guest PC 0x0c076e60 */
if(!s->budget--) { s->failed_pc=0x0c076e60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c076e62;
P_0c076e62: /* original 8b51, guest PC 0x0c076e62 */
if(!s->budget--) { s->failed_pc=0x0c076e62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076f08; }
goto P_0c076e64;
P_0c076e64: /* original e07c, guest PC 0x0c076e64 */
if(!s->budget--) { s->failed_pc=0x0c076e64u; return 0; }
r[0]=0x0000007cu;
goto P_0c076e66;
P_0c076e66: /* original 00fe, guest PC 0x0c076e66 */
if(!s->budget--) { s->failed_pc=0x0c076e66u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076e68;
P_0c076e68: /* original 8808, guest PC 0x0c076e68 */
if(!s->budget--) { s->failed_pc=0x0c076e68u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c076e6a;
P_0c076e6a: /* original 8b43, guest PC 0x0c076e6a */
if(!s->budget--) { s->failed_pc=0x0c076e6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e6c;
P_0c076e6c: /* original 9026, guest PC 0x0c076e6c */
if(!s->budget--) { s->failed_pc=0x0c076e6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e6e;
P_0c076e6e: /* original d31c, guest PC 0x0c076e6e */
if(!s->budget--) { s->failed_pc=0x0c076e6eu; return 0; }
r[3]=read(ram,0x0c076ee0u,4);
goto P_0c076e70;
P_0c076e70: /* original 02fe, guest PC 0x0c076e70 */
if(!s->budget--) { s->failed_pc=0x0c076e70u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076e72;
P_0c076e72: /* original 2238, guest PC 0x0c076e72 */
if(!s->budget--) { s->failed_pc=0x0c076e72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c076e74;
P_0c076e74: /* original 8b3e, guest PC 0x0c076e74 */
if(!s->budget--) { s->failed_pc=0x0c076e74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e76;
P_0c076e76: /* original 9021, guest PC 0x0c076e76 */
if(!s->budget--) { s->failed_pc=0x0c076e76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e78;
P_0c076e78: /* original d21a, guest PC 0x0c076e78 */
if(!s->budget--) { s->failed_pc=0x0c076e78u; return 0; }
r[2]=read(ram,0x0c076ee4u,4);
goto P_0c076e7a;
P_0c076e7a: /* original 01fe, guest PC 0x0c076e7a */
if(!s->budget--) { s->failed_pc=0x0c076e7au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076e7c;
P_0c076e7c: /* original 2128, guest PC 0x0c076e7c */
if(!s->budget--) { s->failed_pc=0x0c076e7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076e7e;
P_0c076e7e: /* original 8b39, guest PC 0x0c076e7e */
if(!s->budget--) { s->failed_pc=0x0c076e7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e80;
P_0c076e80: /* original 901c, guest PC 0x0c076e80 */
if(!s->budget--) { s->failed_pc=0x0c076e80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e82;
P_0c076e82: /* original d112, guest PC 0x0c076e82 */
if(!s->budget--) { s->failed_pc=0x0c076e82u; return 0; }
r[1]=read(ram,0x0c076eccu,4);
goto P_0c076e84;
P_0c076e84: /* original 00fe, guest PC 0x0c076e84 */
if(!s->budget--) { s->failed_pc=0x0c076e84u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076e86;
P_0c076e86: /* original 2018, guest PC 0x0c076e86 */
if(!s->budget--) { s->failed_pc=0x0c076e86u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c076e88;
P_0c076e88: /* original 8b34, guest PC 0x0c076e88 */
if(!s->budget--) { s->failed_pc=0x0c076e88u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076ef4; }
goto P_0c076e8a;
P_0c076e8a: /* original 9217, guest PC 0x0c076e8a */
if(!s->budget--) { s->failed_pc=0x0c076e8au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e8c;
P_0c076e8c: /* original 32fc, guest PC 0x0c076e8c */
if(!s->budget--) { s->failed_pc=0x0c076e8cu; return 0; }
r[2]+=r[15];
goto P_0c076e8e;
P_0c076e8e: /* original 6022, guest PC 0x0c076e8e */
if(!s->budget--) { s->failed_pc=0x0c076e8eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076e90;
P_0c076e90: /* original c840, guest PC 0x0c076e90 */
if(!s->budget--) { s->failed_pc=0x0c076e90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c076e92;
P_0c076e92: /* original 8902, guest PC 0x0c076e92 */
if(!s->budget--) { s->failed_pc=0x0c076e92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076e9a; }
goto P_0c076e94;
P_0c076e94: /* original d114, guest PC 0x0c076e94 */
if(!s->budget--) { s->failed_pc=0x0c076e94u; return 0; }
r[1]=read(ram,0x0c076ee8u,4);
goto P_0c076e96;
P_0c076e96: /* original a006, guest PC 0x0c076e96 */
if(!s->budget--) { s->failed_pc=0x0c076e96u; return 0; }
goto P_0c076ea6;
P_0c076e98: /* original 0009, guest PC 0x0c076e98 */
if(!s->budget--) { s->failed_pc=0x0c076e98u; return 0; }
goto P_0c076e9a;
P_0c076e9a: /* original 920f, guest PC 0x0c076e9a */
if(!s->budget--) { s->failed_pc=0x0c076e9au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c076ebcu,2);
goto P_0c076e9c;
P_0c076e9c: /* original 32fc, guest PC 0x0c076e9c */
if(!s->budget--) { s->failed_pc=0x0c076e9cu; return 0; }
r[2]+=r[15];
goto P_0c076e9e;
P_0c076e9e: /* original 6022, guest PC 0x0c076e9e */
if(!s->budget--) { s->failed_pc=0x0c076e9eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076ea0;
P_0c076ea0: /* original c820, guest PC 0x0c076ea0 */
if(!s->budget--) { s->failed_pc=0x0c076ea0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c076ea2;
P_0c076ea2: /* original 8903, guest PC 0x0c076ea2 */
if(!s->budget--) { s->failed_pc=0x0c076ea2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076eac; }
goto P_0c076ea4;
P_0c076ea4: /* original d111, guest PC 0x0c076ea4 */
if(!s->budget--) { s->failed_pc=0x0c076ea4u; return 0; }
r[1]=read(ram,0x0c076eecu,4);
goto P_0c076ea6;
P_0c076ea6: /* original e070, guest PC 0x0c076ea6 */
if(!s->budget--) { s->failed_pc=0x0c076ea6u; return 0; }
r[0]=0x00000070u;
goto P_0c076ea8;
P_0c076ea8: /* original a02b, guest PC 0x0c076ea8 */
if(!s->budget--) { s->failed_pc=0x0c076ea8u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076f02;
P_0c076eaa: /* original 0f16, guest PC 0x0c076eaa */
if(!s->budget--) { s->failed_pc=0x0c076eaau; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076eac;
P_0c076eac: /* original e07c, guest PC 0x0c076eac */
if(!s->budget--) { s->failed_pc=0x0c076eacu; return 0; }
r[0]=0x0000007cu;
goto P_0c076eae;
P_0c076eae: /* original 02fe, guest PC 0x0c076eae */
if(!s->budget--) { s->failed_pc=0x0c076eaeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076eb0;
P_0c076eb0: /* original d00f, guest PC 0x0c076eb0 */
if(!s->budget--) { s->failed_pc=0x0c076eb0u; return 0; }
r[0]=read(ram,0x0c076ef0u,4);
goto P_0c076eb2;
P_0c076eb2: /* original 4208, guest PC 0x0c076eb2 */
if(!s->budget--) { s->failed_pc=0x0c076eb2u; return 0; }
r[2]<<=2;
goto P_0c076eb4;
P_0c076eb4: /* original 032e, guest PC 0x0c076eb4 */
if(!s->budget--) { s->failed_pc=0x0c076eb4u; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c076eb6;
P_0c076eb6: /* original e070, guest PC 0x0c076eb6 */
if(!s->budget--) { s->failed_pc=0x0c076eb6u; return 0; }
r[0]=0x00000070u;
goto P_0c076eb8;
P_0c076eb8: /* original a023, guest PC 0x0c076eb8 */
if(!s->budget--) { s->failed_pc=0x0c076eb8u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076f02;
P_0c076eba: /* original 0f36, guest PC 0x0c076eba */
if(!s->budget--) { s->failed_pc=0x0c076ebau; return 0; }
write(ram,r[15]+r[0],r[3],4);
return vf3_matrix_family(0x0c076ebcu,s,ram);
P_0c076ef4: /* original e07c, guest PC 0x0c076ef4 */
if(!s->budget--) { s->failed_pc=0x0c076ef4u; return 0; }
r[0]=0x0000007cu;
goto P_0c076ef6;
P_0c076ef6: /* original 01fe, guest PC 0x0c076ef6 */
if(!s->budget--) { s->failed_pc=0x0c076ef6u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c076ef8;
P_0c076ef8: /* original d05e, guest PC 0x0c076ef8 */
if(!s->budget--) { s->failed_pc=0x0c076ef8u; return 0; }
r[0]=read(ram,0x0c077074u,4);
goto P_0c076efa;
P_0c076efa: /* original 4108, guest PC 0x0c076efa */
if(!s->budget--) { s->failed_pc=0x0c076efau; return 0; }
r[1]<<=2;
goto P_0c076efc;
P_0c076efc: /* original 031e, guest PC 0x0c076efc */
if(!s->budget--) { s->failed_pc=0x0c076efcu; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c076efe;
P_0c076efe: /* original e070, guest PC 0x0c076efe */
if(!s->budget--) { s->failed_pc=0x0c076efeu; return 0; }
r[0]=0x00000070u;
goto P_0c076f00;
P_0c076f00: /* original 0f36, guest PC 0x0c076f00 */
if(!s->budget--) { s->failed_pc=0x0c076f00u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076f02;
P_0c076f02: /* original 90ad, guest PC 0x0c076f02 */
if(!s->budget--) { s->failed_pc=0x0c076f02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077060u,2);
goto P_0c076f04;
P_0c076f04: /* original e200, guest PC 0x0c076f04 */
if(!s->budget--) { s->failed_pc=0x0c076f04u; return 0; }
r[2]=0x00000000u;
goto P_0c076f06;
P_0c076f06: /* original 0e26, guest PC 0x0c076f06 */
if(!s->budget--) { s->failed_pc=0x0c076f06u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c076f08;
P_0c076f08: /* original 90ab, guest PC 0x0c076f08 */
if(!s->budget--) { s->failed_pc=0x0c076f08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077062u,2);
goto P_0c076f0a;
P_0c076f0a: /* original 03ec, guest PC 0x0c076f0a */
if(!s->budget--) { s->failed_pc=0x0c076f0au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c076f0c;
P_0c076f0c: /* original 633c, guest PC 0x0c076f0c */
if(!s->budget--) { s->failed_pc=0x0c076f0cu; return 0; }
r[3]=r[3]&255u;
goto P_0c076f0e;
P_0c076f0e: /* original 1f38, guest PC 0x0c076f0e */
if(!s->budget--) { s->failed_pc=0x0c076f0eu; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c076f10;
P_0c076f10: /* original 4308, guest PC 0x0c076f10 */
if(!s->budget--) { s->failed_pc=0x0c076f10u; return 0; }
r[3]<<=2;
goto P_0c076f12;
P_0c076f12: /* original 92a7, guest PC 0x0c076f12 */
if(!s->budget--) { s->failed_pc=0x0c076f12u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077064u,2);
goto P_0c076f14;
P_0c076f14: /* original 2329, guest PC 0x0c076f14 */
if(!s->budget--) { s->failed_pc=0x0c076f14u; return 0; }
r[3]&=r[2];
goto P_0c076f16;
P_0c076f16: /* original 1f35, guest PC 0x0c076f16 */
if(!s->budget--) { s->failed_pc=0x0c076f16u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c076f18;
P_0c076f18: /* original 50f8, guest PC 0x0c076f18 */
if(!s->budget--) { s->failed_pc=0x0c076f18u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c076f1a;
P_0c076f1a: /* original 70ff, guest PC 0x0c076f1a */
if(!s->budget--) { s->failed_pc=0x0c076f1au; return 0; }
r[0]+=0xffffffffu;
goto P_0c076f1c;
P_0c076f1c: /* original 4008, guest PC 0x0c076f1c */
if(!s->budget--) { s->failed_pc=0x0c076f1cu; return 0; }
r[0]<<=2;
goto P_0c076f1e;
P_0c076f1e: /* original c9fc, guest PC 0x0c076f1e */
if(!s->budget--) { s->failed_pc=0x0c076f1eu; return 0; }
r[0]&=252u;
goto P_0c076f20;
P_0c076f20: /* original 6303, guest PC 0x0c076f20 */
if(!s->budget--) { s->failed_pc=0x0c076f20u; return 0; }
r[3]=r[0];
goto P_0c076f22;
P_0c076f22: /* original 2f02, guest PC 0x0c076f22 */
if(!s->budget--) { s->failed_pc=0x0c076f22u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c076f24;
P_0c076f24: /* original 929f, guest PC 0x0c076f24 */
if(!s->budget--) { s->failed_pc=0x0c076f24u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f26;
P_0c076f26: /* original e058, guest PC 0x0c076f26 */
if(!s->budget--) { s->failed_pc=0x0c076f26u; return 0; }
r[0]=0x00000058u;
goto P_0c076f28;
P_0c076f28: /* original 32ec, guest PC 0x0c076f28 */
if(!s->budget--) { s->failed_pc=0x0c076f28u; return 0; }
r[2]+=r[14];
goto P_0c076f2a;
P_0c076f2a: /* original 323c, guest PC 0x0c076f2a */
if(!s->budget--) { s->failed_pc=0x0c076f2au; return 0; }
r[2]+=r[3];
goto P_0c076f2c;
P_0c076f2c: /* original 6120, guest PC 0x0c076f2c */
if(!s->budget--) { s->failed_pc=0x0c076f2cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c076f2e;
P_0c076f2e: /* original 611c, guest PC 0x0c076f2e */
if(!s->budget--) { s->failed_pc=0x0c076f2eu; return 0; }
r[1]=r[1]&255u;
goto P_0c076f30;
P_0c076f30: /* original 0f16, guest PC 0x0c076f30 */
if(!s->budget--) { s->failed_pc=0x0c076f30u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c076f32;
P_0c076f32: /* original 61f3, guest PC 0x0c076f32 */
if(!s->budget--) { s->failed_pc=0x0c076f32u; return 0; }
r[1]=r[15];
goto P_0c076f34;
P_0c076f34: /* original 9297, guest PC 0x0c076f34 */
if(!s->budget--) { s->failed_pc=0x0c076f34u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f36;
P_0c076f36: /* original 7154, guest PC 0x0c076f36 */
if(!s->budget--) { s->failed_pc=0x0c076f36u; return 0; }
r[1]+=0x00000054u;
goto P_0c076f38;
P_0c076f38: /* original 63f2, guest PC 0x0c076f38 */
if(!s->budget--) { s->failed_pc=0x0c076f38u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c076f3a;
P_0c076f3a: /* original 32ec, guest PC 0x0c076f3a */
if(!s->budget--) { s->failed_pc=0x0c076f3au; return 0; }
r[2]+=r[14];
goto P_0c076f3c;
P_0c076f3c: /* original 323c, guest PC 0x0c076f3c */
if(!s->budget--) { s->failed_pc=0x0c076f3cu; return 0; }
r[2]+=r[3];
goto P_0c076f3e;
P_0c076f3e: /* original 8421, guest PC 0x0c076f3e */
if(!s->budget--) { s->failed_pc=0x0c076f3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+1,1);
goto P_0c076f40;
P_0c076f40: /* original 600c, guest PC 0x0c076f40 */
if(!s->budget--) { s->failed_pc=0x0c076f40u; return 0; }
r[0]=r[0]&255u;
goto P_0c076f42;
P_0c076f42: /* original 2102, guest PC 0x0c076f42 */
if(!s->budget--) { s->failed_pc=0x0c076f42u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c076f44;
P_0c076f44: /* original e058, guest PC 0x0c076f44 */
if(!s->budget--) { s->failed_pc=0x0c076f44u; return 0; }
r[0]=0x00000058u;
goto P_0c076f46;
P_0c076f46: /* original 02fe, guest PC 0x0c076f46 */
if(!s->budget--) { s->failed_pc=0x0c076f46u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076f48;
P_0c076f48: /* original 51f1, guest PC 0x0c076f48 */
if(!s->budget--) { s->failed_pc=0x0c076f48u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c076f4a;
P_0c076f4a: /* original 6227, guest PC 0x0c076f4a */
if(!s->budget--) { s->failed_pc=0x0c076f4au; return 0; }
r[2]=~r[2];
goto P_0c076f4c;
P_0c076f4c: /* original e050, guest PC 0x0c076f4c */
if(!s->budget--) { s->failed_pc=0x0c076f4cu; return 0; }
r[0]=0x00000050u;
goto P_0c076f4e;
P_0c076f4e: /* original 2219, guest PC 0x0c076f4e */
if(!s->budget--) { s->failed_pc=0x0c076f4eu; return 0; }
r[2]&=r[1];
goto P_0c076f50;
P_0c076f50: /* original 0f26, guest PC 0x0c076f50 */
if(!s->budget--) { s->failed_pc=0x0c076f50u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c076f52;
P_0c076f52: /* original e050, guest PC 0x0c076f52 */
if(!s->budget--) { s->failed_pc=0x0c076f52u; return 0; }
r[0]=0x00000050u;
goto P_0c076f54;
P_0c076f54: /* original 9187, guest PC 0x0c076f54 */
if(!s->budget--) { s->failed_pc=0x0c076f54u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f56;
P_0c076f56: /* original 53f5, guest PC 0x0c076f56 */
if(!s->budget--) { s->failed_pc=0x0c076f56u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076f58;
P_0c076f58: /* original 52f1, guest PC 0x0c076f58 */
if(!s->budget--) { s->failed_pc=0x0c076f58u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c076f5a;
P_0c076f5a: /* original 31ec, guest PC 0x0c076f5a */
if(!s->budget--) { s->failed_pc=0x0c076f5au; return 0; }
r[1]+=r[14];
goto P_0c076f5c;
P_0c076f5c: /* original 313c, guest PC 0x0c076f5c */
if(!s->budget--) { s->failed_pc=0x0c076f5cu; return 0; }
r[1]+=r[3];
goto P_0c076f5e;
P_0c076f5e: /* original 2120, guest PC 0x0c076f5e */
if(!s->budget--) { s->failed_pc=0x0c076f5eu; return 0; }
write(ram,r[1],r[2],1);
goto P_0c076f60;
P_0c076f60: /* original 9181, guest PC 0x0c076f60 */
if(!s->budget--) { s->failed_pc=0x0c076f60u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f62;
P_0c076f62: /* original 53f5, guest PC 0x0c076f62 */
if(!s->budget--) { s->failed_pc=0x0c076f62u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076f64;
P_0c076f64: /* original 00fc, guest PC 0x0c076f64 */
if(!s->budget--) { s->failed_pc=0x0c076f64u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c076f66;
P_0c076f66: /* original 31ec, guest PC 0x0c076f66 */
if(!s->budget--) { s->failed_pc=0x0c076f66u; return 0; }
r[1]+=r[14];
goto P_0c076f68;
P_0c076f68: /* original 313c, guest PC 0x0c076f68 */
if(!s->budget--) { s->failed_pc=0x0c076f68u; return 0; }
r[1]+=r[3];
goto P_0c076f6a;
P_0c076f6a: /* original 8012, guest PC 0x0c076f6a */
if(!s->budget--) { s->failed_pc=0x0c076f6au; return 0; }
write(ram,r[1]+2,r[0],1);
goto P_0c076f6c;
P_0c076f6c: /* original e058, guest PC 0x0c076f6c */
if(!s->budget--) { s->failed_pc=0x0c076f6cu; return 0; }
r[0]=0x00000058u;
goto P_0c076f6e;
P_0c076f6e: /* original 53f1, guest PC 0x0c076f6e */
if(!s->budget--) { s->failed_pc=0x0c076f6eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c076f70;
P_0c076f70: /* original 02fe, guest PC 0x0c076f70 */
if(!s->budget--) { s->failed_pc=0x0c076f70u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c076f72;
P_0c076f72: /* original 6337, guest PC 0x0c076f72 */
if(!s->budget--) { s->failed_pc=0x0c076f72u; return 0; }
r[3]=~r[3];
goto P_0c076f74;
P_0c076f74: /* original 2329, guest PC 0x0c076f74 */
if(!s->budget--) { s->failed_pc=0x0c076f74u; return 0; }
r[3]&=r[2];
goto P_0c076f76;
P_0c076f76: /* original 1f3f, guest PC 0x0c076f76 */
if(!s->budget--) { s->failed_pc=0x0c076f76u; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c076f78;
P_0c076f78: /* original 9275, guest PC 0x0c076f78 */
if(!s->budget--) { s->failed_pc=0x0c076f78u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076f7a;
P_0c076f7a: /* original 53f5, guest PC 0x0c076f7a */
if(!s->budget--) { s->failed_pc=0x0c076f7au; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076f7c;
P_0c076f7c: /* original 50ff, guest PC 0x0c076f7c */
if(!s->budget--) { s->failed_pc=0x0c076f7cu; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c076f7e;
P_0c076f7e: /* original 32ec, guest PC 0x0c076f7e */
if(!s->budget--) { s->failed_pc=0x0c076f7eu; return 0; }
r[2]+=r[14];
goto P_0c076f80;
P_0c076f80: /* original 323c, guest PC 0x0c076f80 */
if(!s->budget--) { s->failed_pc=0x0c076f80u; return 0; }
r[2]+=r[3];
goto P_0c076f82;
P_0c076f82: /* original 8023, guest PC 0x0c076f82 */
if(!s->budget--) { s->failed_pc=0x0c076f82u; return 0; }
write(ram,r[2]+3,r[0],1);
goto P_0c076f84;
P_0c076f84: /* original e04c, guest PC 0x0c076f84 */
if(!s->budget--) { s->failed_pc=0x0c076f84u; return 0; }
r[0]=0x0000004cu;
goto P_0c076f86;
P_0c076f86: /* original 53f1, guest PC 0x0c076f86 */
if(!s->budget--) { s->failed_pc=0x0c076f86u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c076f88;
P_0c076f88: /* original 0f36, guest PC 0x0c076f88 */
if(!s->budget--) { s->failed_pc=0x0c076f88u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076f8a;
P_0c076f8a: /* original 50f1, guest PC 0x0c076f8a */
if(!s->budget--) { s->failed_pc=0x0c076f8au; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c076f8c;
P_0c076f8c: /* original c8c0, guest PC 0x0c076f8c */
if(!s->budget--) { s->failed_pc=0x0c076f8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&192u)==0)!=0);
goto P_0c076f8e;
P_0c076f8e: /* original 8b09, guest PC 0x0c076f8e */
if(!s->budget--) { s->failed_pc=0x0c076f8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076fa4; }
goto P_0c076f90;
P_0c076f90: /* original 62f3, guest PC 0x0c076f90 */
if(!s->budget--) { s->failed_pc=0x0c076f90u; return 0; }
r[2]=r[15];
goto P_0c076f92;
P_0c076f92: /* original 61f3, guest PC 0x0c076f92 */
if(!s->budget--) { s->failed_pc=0x0c076f92u; return 0; }
r[1]=r[15];
goto P_0c076f94;
P_0c076f94: /* original 7254, guest PC 0x0c076f94 */
if(!s->budget--) { s->failed_pc=0x0c076f94u; return 0; }
r[2]+=0x00000054u;
goto P_0c076f96;
P_0c076f96: /* original 714c, guest PC 0x0c076f96 */
if(!s->budget--) { s->failed_pc=0x0c076f96u; return 0; }
r[1]+=0x0000004cu;
goto P_0c076f98;
P_0c076f98: /* original 6022, guest PC 0x0c076f98 */
if(!s->budget--) { s->failed_pc=0x0c076f98u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076f9a;
P_0c076f9a: /* original 6312, guest PC 0x0c076f9a */
if(!s->budget--) { s->failed_pc=0x0c076f9au; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c076f9c;
P_0c076f9c: /* original c9c0, guest PC 0x0c076f9c */
if(!s->budget--) { s->failed_pc=0x0c076f9cu; return 0; }
r[0]&=192u;
goto P_0c076f9e;
P_0c076f9e: /* original 230b, guest PC 0x0c076f9e */
if(!s->budget--) { s->failed_pc=0x0c076f9eu; return 0; }
r[3]|=r[0];
goto P_0c076fa0;
P_0c076fa0: /* original e04c, guest PC 0x0c076fa0 */
if(!s->budget--) { s->failed_pc=0x0c076fa0u; return 0; }
r[0]=0x0000004cu;
goto P_0c076fa2;
P_0c076fa2: /* original 0f36, guest PC 0x0c076fa2 */
if(!s->budget--) { s->failed_pc=0x0c076fa2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076fa4;
P_0c076fa4: /* original 62f3, guest PC 0x0c076fa4 */
if(!s->budget--) { s->failed_pc=0x0c076fa4u; return 0; }
r[2]=r[15];
goto P_0c076fa6;
P_0c076fa6: /* original 724c, guest PC 0x0c076fa6 */
if(!s->budget--) { s->failed_pc=0x0c076fa6u; return 0; }
r[2]+=0x0000004cu;
goto P_0c076fa8;
P_0c076fa8: /* original 6022, guest PC 0x0c076fa8 */
if(!s->budget--) { s->failed_pc=0x0c076fa8u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c076faa;
P_0c076faa: /* original c830, guest PC 0x0c076faa */
if(!s->budget--) { s->failed_pc=0x0c076faau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&48u)==0)!=0);
goto P_0c076fac;
P_0c076fac: /* original 8b09, guest PC 0x0c076fac */
if(!s->budget--) { s->failed_pc=0x0c076facu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c076fc2; }
goto P_0c076fae;
P_0c076fae: /* original 61f3, guest PC 0x0c076fae */
if(!s->budget--) { s->failed_pc=0x0c076faeu; return 0; }
r[1]=r[15];
goto P_0c076fb0;
P_0c076fb0: /* original 62f3, guest PC 0x0c076fb0 */
if(!s->budget--) { s->failed_pc=0x0c076fb0u; return 0; }
r[2]=r[15];
goto P_0c076fb2;
P_0c076fb2: /* original 7154, guest PC 0x0c076fb2 */
if(!s->budget--) { s->failed_pc=0x0c076fb2u; return 0; }
r[1]+=0x00000054u;
goto P_0c076fb4;
P_0c076fb4: /* original 724c, guest PC 0x0c076fb4 */
if(!s->budget--) { s->failed_pc=0x0c076fb4u; return 0; }
r[2]+=0x0000004cu;
goto P_0c076fb6;
P_0c076fb6: /* original 6012, guest PC 0x0c076fb6 */
if(!s->budget--) { s->failed_pc=0x0c076fb6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c076fb8;
P_0c076fb8: /* original 6322, guest PC 0x0c076fb8 */
if(!s->budget--) { s->failed_pc=0x0c076fb8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c076fba;
P_0c076fba: /* original c930, guest PC 0x0c076fba */
if(!s->budget--) { s->failed_pc=0x0c076fbau; return 0; }
r[0]&=48u;
goto P_0c076fbc;
P_0c076fbc: /* original 230b, guest PC 0x0c076fbc */
if(!s->budget--) { s->failed_pc=0x0c076fbcu; return 0; }
r[3]|=r[0];
goto P_0c076fbe;
P_0c076fbe: /* original e04c, guest PC 0x0c076fbe */
if(!s->budget--) { s->failed_pc=0x0c076fbeu; return 0; }
r[0]=0x0000004cu;
goto P_0c076fc0;
P_0c076fc0: /* original 0f36, guest PC 0x0c076fc0 */
if(!s->budget--) { s->failed_pc=0x0c076fc0u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c076fc2;
P_0c076fc2: /* original 9150, guest PC 0x0c076fc2 */
if(!s->budget--) { s->failed_pc=0x0c076fc2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077066u,2);
goto P_0c076fc4;
P_0c076fc4: /* original e04c, guest PC 0x0c076fc4 */
if(!s->budget--) { s->failed_pc=0x0c076fc4u; return 0; }
r[0]=0x0000004cu;
goto P_0c076fc6;
P_0c076fc6: /* original 53f5, guest PC 0x0c076fc6 */
if(!s->budget--) { s->failed_pc=0x0c076fc6u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c076fc8;
P_0c076fc8: /* original 00fc, guest PC 0x0c076fc8 */
if(!s->budget--) { s->failed_pc=0x0c076fc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c076fca;
P_0c076fca: /* original 31ec, guest PC 0x0c076fca */
if(!s->budget--) { s->failed_pc=0x0c076fcau; return 0; }
r[1]+=r[14];
goto P_0c076fcc;
P_0c076fcc: /* original 313c, guest PC 0x0c076fcc */
if(!s->budget--) { s->failed_pc=0x0c076fccu; return 0; }
r[1]+=r[3];
goto P_0c076fce;
P_0c076fce: /* original 8011, guest PC 0x0c076fce */
if(!s->budget--) { s->failed_pc=0x0c076fceu; return 0; }
write(ram,r[1]+1,r[0],1);
goto P_0c076fd0;
P_0c076fd0: /* original 904a, guest PC 0x0c076fd0 */
if(!s->budget--) { s->failed_pc=0x0c076fd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077068u,2);
goto P_0c076fd2;
P_0c076fd2: /* original d229, guest PC 0x0c076fd2 */
if(!s->budget--) { s->failed_pc=0x0c076fd2u; return 0; }
r[2]=read(ram,0x0c077078u,4);
goto P_0c076fd4;
P_0c076fd4: /* original 03fe, guest PC 0x0c076fd4 */
if(!s->budget--) { s->failed_pc=0x0c076fd4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c076fd6;
P_0c076fd6: /* original 5131, guest PC 0x0c076fd6 */
if(!s->budget--) { s->failed_pc=0x0c076fd6u; return 0; }
r[1]=read(ram,r[3]+4,4);
goto P_0c076fd8;
P_0c076fd8: /* original 2128, guest PC 0x0c076fd8 */
if(!s->budget--) { s->failed_pc=0x0c076fd8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c076fda;
P_0c076fda: /* original 890b, guest PC 0x0c076fda */
if(!s->budget--) { s->failed_pc=0x0c076fdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c076ff4; }
goto P_0c076fdc;
P_0c076fdc: /* original 50f1, guest PC 0x0c076fdc */
if(!s->budget--) { s->failed_pc=0x0c076fdcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c076fde;
P_0c076fde: /* original 61f3, guest PC 0x0c076fde */
if(!s->budget--) { s->failed_pc=0x0c076fdeu; return 0; }
r[1]=r[15];
goto P_0c076fe0;
P_0c076fe0: /* original 7150, guest PC 0x0c076fe0 */
if(!s->budget--) { s->failed_pc=0x0c076fe0u; return 0; }
r[1]+=0x00000050u;
goto P_0c076fe2;
P_0c076fe2: /* original c910, guest PC 0x0c076fe2 */
if(!s->budget--) { s->failed_pc=0x0c076fe2u; return 0; }
r[0]&=16u;
goto P_0c076fe4;
P_0c076fe4: /* original 1f01, guest PC 0x0c076fe4 */
if(!s->budget--) { s->failed_pc=0x0c076fe4u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c076fe6;
P_0c076fe6: /* original e050, guest PC 0x0c076fe6 */
if(!s->budget--) { s->failed_pc=0x0c076fe6u; return 0; }
r[0]=0x00000050u;
goto P_0c076fe8;
P_0c076fe8: /* original 00fe, guest PC 0x0c076fe8 */
if(!s->budget--) { s->failed_pc=0x0c076fe8u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c076fea;
P_0c076fea: /* original c910, guest PC 0x0c076fea */
if(!s->budget--) { s->failed_pc=0x0c076feau; return 0; }
r[0]&=16u;
goto P_0c076fec;
P_0c076fec: /* original 2102, guest PC 0x0c076fec */
if(!s->budget--) { s->failed_pc=0x0c076fecu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c076fee;
P_0c076fee: /* original 50ff, guest PC 0x0c076fee */
if(!s->budget--) { s->failed_pc=0x0c076feeu; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c076ff0;
P_0c076ff0: /* original c910, guest PC 0x0c076ff0 */
if(!s->budget--) { s->failed_pc=0x0c076ff0u; return 0; }
r[0]&=16u;
goto P_0c076ff2;
P_0c076ff2: /* original 1f0f, guest PC 0x0c076ff2 */
if(!s->budget--) { s->failed_pc=0x0c076ff2u; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c076ff4;
P_0c076ff4: /* original 52f8, guest PC 0x0c076ff4 */
if(!s->budget--) { s->failed_pc=0x0c076ff4u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c076ff6;
P_0c076ff6: /* original 7201, guest PC 0x0c076ff6 */
if(!s->budget--) { s->failed_pc=0x0c076ff6u; return 0; }
r[2]+=0x00000001u;
goto P_0c076ff8;
P_0c076ff8: /* original 6023, guest PC 0x0c076ff8 */
if(!s->budget--) { s->failed_pc=0x0c076ff8u; return 0; }
r[0]=r[2];
goto P_0c076ffa;
P_0c076ffa: /* original c93f, guest PC 0x0c076ffa */
if(!s->budget--) { s->failed_pc=0x0c076ffau; return 0; }
r[0]&=63u;
goto P_0c076ffc;
P_0c076ffc: /* original 6303, guest PC 0x0c076ffc */
if(!s->budget--) { s->failed_pc=0x0c076ffcu; return 0; }
r[3]=r[0];
goto P_0c076ffe;
P_0c076ffe: /* original 1f08, guest PC 0x0c076ffe */
if(!s->budget--) { s->failed_pc=0x0c076ffeu; return 0; }
write(ram,r[15]+32,r[0],4);
goto P_0c077000;
P_0c077000: /* original 902f, guest PC 0x0c077000 */
if(!s->budget--) { s->failed_pc=0x0c077000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077062u,2);
goto P_0c077002;
P_0c077002: /* original 0e34, guest PC 0x0c077002 */
if(!s->budget--) { s->failed_pc=0x0c077002u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077004;
P_0c077004: /* original e33f, guest PC 0x0c077004 */
if(!s->budget--) { s->failed_pc=0x0c077004u; return 0; }
r[3]=0x0000003fu;
goto P_0c077006;
P_0c077006: /* original 52f8, guest PC 0x0c077006 */
if(!s->budget--) { s->failed_pc=0x0c077006u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077008;
P_0c077008: /* original e058, guest PC 0x0c077008 */
if(!s->budget--) { s->failed_pc=0x0c077008u; return 0; }
r[0]=0x00000058u;
goto P_0c07700a;
P_0c07700a: /* original 7201, guest PC 0x0c07700a */
if(!s->budget--) { s->failed_pc=0x0c07700au; return 0; }
r[2]+=0x00000001u;
goto P_0c07700c;
P_0c07700c: /* original 2239, guest PC 0x0c07700c */
if(!s->budget--) { s->failed_pc=0x0c07700cu; return 0; }
r[2]&=r[3];
goto P_0c07700e;
P_0c07700e: /* original 0f26, guest PC 0x0c07700e */
if(!s->budget--) { s->failed_pc=0x0c07700eu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077010;
P_0c077010: /* original 902b, guest PC 0x0c077010 */
if(!s->budget--) { s->failed_pc=0x0c077010u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706au,2);
goto P_0c077012;
P_0c077012: /* original 52f8, guest PC 0x0c077012 */
if(!s->budget--) { s->failed_pc=0x0c077012u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077014;
P_0c077014: /* original 03ec, guest PC 0x0c077014 */
if(!s->budget--) { s->failed_pc=0x0c077014u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077016;
P_0c077016: /* original 633c, guest PC 0x0c077016 */
if(!s->budget--) { s->failed_pc=0x0c077016u; return 0; }
r[3]=r[3]&255u;
goto P_0c077018;
P_0c077018: /* original 3320, guest PC 0x0c077018 */
if(!s->budget--) { s->failed_pc=0x0c077018u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07701a;
P_0c07701a: /* original 8b03, guest PC 0x0c07701a */
if(!s->budget--) { s->failed_pc=0x0c07701au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077024; }
goto P_0c07701c;
P_0c07701c: /* original e058, guest PC 0x0c07701c */
if(!s->budget--) { s->failed_pc=0x0c07701cu; return 0; }
r[0]=0x00000058u;
goto P_0c07701e;
P_0c07701e: /* original 01fc, guest PC 0x0c07701e */
if(!s->budget--) { s->failed_pc=0x0c07701eu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077020;
P_0c077020: /* original 9023, guest PC 0x0c077020 */
if(!s->budget--) { s->failed_pc=0x0c077020u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706au,2);
goto P_0c077022;
P_0c077022: /* original 0e14, guest PC 0x0c077022 */
if(!s->budget--) { s->failed_pc=0x0c077022u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c077024;
P_0c077024: /* original 9022, guest PC 0x0c077024 */
if(!s->budget--) { s->failed_pc=0x0c077024u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706cu,2);
goto P_0c077026;
P_0c077026: /* original 52f8, guest PC 0x0c077026 */
if(!s->budget--) { s->failed_pc=0x0c077026u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077028;
P_0c077028: /* original 03ec, guest PC 0x0c077028 */
if(!s->budget--) { s->failed_pc=0x0c077028u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07702a;
P_0c07702a: /* original 633c, guest PC 0x0c07702a */
if(!s->budget--) { s->failed_pc=0x0c07702au; return 0; }
r[3]=r[3]&255u;
goto P_0c07702c;
P_0c07702c: /* original 3320, guest PC 0x0c07702c */
if(!s->budget--) { s->failed_pc=0x0c07702cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07702e;
P_0c07702e: /* original 8b03, guest PC 0x0c07702e */
if(!s->budget--) { s->failed_pc=0x0c07702eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077038; }
goto P_0c077030;
P_0c077030: /* original e058, guest PC 0x0c077030 */
if(!s->budget--) { s->failed_pc=0x0c077030u; return 0; }
r[0]=0x00000058u;
goto P_0c077032;
P_0c077032: /* original 01fc, guest PC 0x0c077032 */
if(!s->budget--) { s->failed_pc=0x0c077032u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077034;
P_0c077034: /* original 901a, guest PC 0x0c077034 */
if(!s->budget--) { s->failed_pc=0x0c077034u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706cu,2);
goto P_0c077036;
P_0c077036: /* original 0e14, guest PC 0x0c077036 */
if(!s->budget--) { s->failed_pc=0x0c077036u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c077038;
P_0c077038: /* original 9019, guest PC 0x0c077038 */
if(!s->budget--) { s->failed_pc=0x0c077038u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706eu,2);
goto P_0c07703a;
P_0c07703a: /* original 52f8, guest PC 0x0c07703a */
if(!s->budget--) { s->failed_pc=0x0c07703au; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c07703c;
P_0c07703c: /* original 03ec, guest PC 0x0c07703c */
if(!s->budget--) { s->failed_pc=0x0c07703cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07703e;
P_0c07703e: /* original 633c, guest PC 0x0c07703e */
if(!s->budget--) { s->failed_pc=0x0c07703eu; return 0; }
r[3]=r[3]&255u;
goto P_0c077040;
P_0c077040: /* original 3320, guest PC 0x0c077040 */
if(!s->budget--) { s->failed_pc=0x0c077040u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c077042;
P_0c077042: /* original 8b03, guest PC 0x0c077042 */
if(!s->budget--) { s->failed_pc=0x0c077042u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07704c; }
goto P_0c077044;
P_0c077044: /* original e058, guest PC 0x0c077044 */
if(!s->budget--) { s->failed_pc=0x0c077044u; return 0; }
r[0]=0x00000058u;
goto P_0c077046;
P_0c077046: /* original 01fc, guest PC 0x0c077046 */
if(!s->budget--) { s->failed_pc=0x0c077046u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077048;
P_0c077048: /* original 9011, guest PC 0x0c077048 */
if(!s->budget--) { s->failed_pc=0x0c077048u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07706eu,2);
goto P_0c07704a;
P_0c07704a: /* original 0e14, guest PC 0x0c07704a */
if(!s->budget--) { s->failed_pc=0x0c07704au; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c07704c;
P_0c07704c: /* original e050, guest PC 0x0c07704c */
if(!s->budget--) { s->failed_pc=0x0c07704cu; return 0; }
r[0]=0x00000050u;
goto P_0c07704e;
P_0c07704e: /* original 03ee, guest PC 0x0c07704e */
if(!s->budget--) { s->failed_pc=0x0c07704eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c077050;
P_0c077050: /* original e048, guest PC 0x0c077050 */
if(!s->budget--) { s->failed_pc=0x0c077050u; return 0; }
r[0]=0x00000048u;
goto P_0c077052;
P_0c077052: /* original 0f36, guest PC 0x0c077052 */
if(!s->budget--) { s->failed_pc=0x0c077052u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077054;
P_0c077054: /* original 900c, guest PC 0x0c077054 */
if(!s->budget--) { s->failed_pc=0x0c077054u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077070u,2);
goto P_0c077056;
P_0c077056: /* original d309, guest PC 0x0c077056 */
if(!s->budget--) { s->failed_pc=0x0c077056u; return 0; }
r[3]=read(ram,0x0c07707cu,4);
goto P_0c077058;
P_0c077058: /* original 02fe, guest PC 0x0c077058 */
if(!s->budget--) { s->failed_pc=0x0c077058u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07705a;
P_0c07705a: /* original 2238, guest PC 0x0c07705a */
if(!s->budget--) { s->failed_pc=0x0c07705au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07705c;
P_0c07705c: /* original a010, guest PC 0x0c07705c */
if(!s->budget--) { s->failed_pc=0x0c07705cu; return 0; }
goto P_0c077080;
P_0c07705e: /* original 0009, guest PC 0x0c07705e */
if(!s->budget--) { s->failed_pc=0x0c07705eu; return 0; }
return vf3_matrix_family(0x0c077060u,s,ram);
P_0c077080: /* original 8904, guest PC 0x0c077080 */
if(!s->budget--) { s->failed_pc=0x0c077080u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07708c; }
goto P_0c077082;
P_0c077082: /* original 9286, guest PC 0x0c077082 */
if(!s->budget--) { s->failed_pc=0x0c077082u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c077084;
P_0c077084: /* original e044, guest PC 0x0c077084 */
if(!s->budget--) { s->failed_pc=0x0c077084u; return 0; }
r[0]=0x00000044u;
goto P_0c077086;
P_0c077086: /* original 0f26, guest PC 0x0c077086 */
if(!s->budget--) { s->failed_pc=0x0c077086u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077088;
P_0c077088: /* original a004, guest PC 0x0c077088 */
if(!s->budget--) { s->failed_pc=0x0c077088u; return 0; }
r[1]=0x00000040u;
goto P_0c077094;
P_0c07708a: /* original e140, guest PC 0x0c07708a */
if(!s->budget--) { s->failed_pc=0x0c07708au; return 0; }
r[1]=0x00000040u;
goto P_0c07708c;
P_0c07708c: /* original e044, guest PC 0x0c07708c */
if(!s->budget--) { s->failed_pc=0x0c07708cu; return 0; }
r[0]=0x00000044u;
goto P_0c07708e;
P_0c07708e: /* original e240, guest PC 0x0c07708e */
if(!s->budget--) { s->failed_pc=0x0c07708eu; return 0; }
r[2]=0x00000040u;
goto P_0c077090;
P_0c077090: /* original 0f26, guest PC 0x0c077090 */
if(!s->budget--) { s->failed_pc=0x0c077090u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077092;
P_0c077092: /* original 917e, guest PC 0x0c077092 */
if(!s->budget--) { s->failed_pc=0x0c077092u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c077094;
P_0c077094: /* original e040, guest PC 0x0c077094 */
if(!s->budget--) { s->failed_pc=0x0c077094u; return 0; }
r[0]=0x00000040u;
goto P_0c077096;
P_0c077096: /* original 0f16, guest PC 0x0c077096 */
if(!s->budget--) { s->failed_pc=0x0c077096u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077098;
P_0c077098: /* original 907b, guest PC 0x0c077098 */
if(!s->budget--) { s->failed_pc=0x0c077098u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c07709a;
P_0c07709a: /* original d33f, guest PC 0x0c07709a */
if(!s->budget--) { s->failed_pc=0x0c07709au; return 0; }
r[3]=read(ram,0x0c077198u,4);
goto P_0c07709c;
P_0c07709c: /* original 02fe, guest PC 0x0c07709c */
if(!s->budget--) { s->failed_pc=0x0c07709cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07709e;
P_0c07709e: /* original 2238, guest PC 0x0c07709e */
if(!s->budget--) { s->failed_pc=0x0c07709eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0770a0;
P_0c0770a0: /* original 890b, guest PC 0x0c0770a0 */
if(!s->budget--) { s->failed_pc=0x0c0770a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0770ba; }
goto P_0c0770a2;
P_0c0770a2: /* original 9176, guest PC 0x0c0770a2 */
if(!s->budget--) { s->failed_pc=0x0c0770a2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077192u,2);
goto P_0c0770a4;
P_0c0770a4: /* original 31fc, guest PC 0x0c0770a4 */
if(!s->budget--) { s->failed_pc=0x0c0770a4u; return 0; }
r[1]+=r[15];
goto P_0c0770a6;
P_0c0770a6: /* original 6012, guest PC 0x0c0770a6 */
if(!s->budget--) { s->failed_pc=0x0c0770a6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0770a8;
P_0c0770a8: /* original c880, guest PC 0x0c0770a8 */
if(!s->budget--) { s->failed_pc=0x0c0770a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0770aa;
P_0c0770aa: /* original 8906, guest PC 0x0c0770aa */
if(!s->budget--) { s->failed_pc=0x0c0770aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0770ba; }
goto P_0c0770ac;
P_0c0770ac: /* original e050, guest PC 0x0c0770ac */
if(!s->budget--) { s->failed_pc=0x0c0770acu; return 0; }
r[0]=0x00000050u;
goto P_0c0770ae;
P_0c0770ae: /* original 02fe, guest PC 0x0c0770ae */
if(!s->budget--) { s->failed_pc=0x0c0770aeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0770b0;
P_0c0770b0: /* original 2228, guest PC 0x0c0770b0 */
if(!s->budget--) { s->failed_pc=0x0c0770b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0770b2;
P_0c0770b2: /* original 8902, guest PC 0x0c0770b2 */
if(!s->budget--) { s->failed_pc=0x0c0770b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0770ba; }
goto P_0c0770b4;
P_0c0770b4: /* original d339, guest PC 0x0c0770b4 */
if(!s->budget--) { s->failed_pc=0x0c0770b4u; return 0; }
r[3]=read(ram,0x0c07719cu,4);
goto P_0c0770b6;
P_0c0770b6: /* original a11e, guest PC 0x0c0770b6 */
if(!s->budget--) { s->failed_pc=0x0c0770b6u; return 0; }
goto P_0c0772f6;
P_0c0770b8: /* original 0009, guest PC 0x0c0770b8 */
if(!s->budget--) { s->failed_pc=0x0c0770b8u; return 0; }
goto P_0c0770ba;
P_0c0770ba: /* original 51f1, guest PC 0x0c0770ba */
if(!s->budget--) { s->failed_pc=0x0c0770bau; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c0770bc;
P_0c0770bc: /* original 65e3, guest PC 0x0c0770bc */
if(!s->budget--) { s->failed_pc=0x0c0770bcu; return 0; }
r[5]=r[14];
goto P_0c0770be;
P_0c0770be: /* original 66d3, guest PC 0x0c0770be */
if(!s->budget--) { s->failed_pc=0x0c0770beu; return 0; }
r[6]=r[13];
goto P_0c0770c0;
P_0c0770c0: /* original e700, guest PC 0x0c0770c0 */
if(!s->budget--) { s->failed_pc=0x0c0770c0u; return 0; }
r[7]=0x00000000u;
goto P_0c0770c2;
P_0c0770c2: /* original 2f16, guest PC 0x0c0770c2 */
if(!s->budget--) { s->failed_pc=0x0c0770c2u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0770c4;
P_0c0770c4: /* original 9066, guest PC 0x0c0770c4 */
if(!s->budget--) { s->failed_pc=0x0c0770c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077194u,2);
goto P_0c0770c6;
P_0c0770c6: /* original 03fe, guest PC 0x0c0770c6 */
if(!s->budget--) { s->failed_pc=0x0c0770c6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0770c8;
P_0c0770c8: /* original e058, guest PC 0x0c0770c8 */
if(!s->budget--) { s->failed_pc=0x0c0770c8u; return 0; }
r[0]=0x00000058u;
goto P_0c0770ca;
P_0c0770ca: /* original 2f36, guest PC 0x0c0770ca */
if(!s->budget--) { s->failed_pc=0x0c0770cau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0770cc;
P_0c0770cc: /* original 02fe, guest PC 0x0c0770cc */
if(!s->budget--) { s->failed_pc=0x0c0770ccu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0770ce;
P_0c0770ce: /* original 2f26, guest PC 0x0c0770ce */
if(!s->budget--) { s->failed_pc=0x0c0770ceu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0770d0;
P_0c0770d0: /* original d333, guest PC 0x0c0770d0 */
if(!s->budget--) { s->failed_pc=0x0c0770d0u; return 0; }
r[3]=read(ram,0x0c0771a0u,4);
goto P_0c0770d2;
P_0c0770d2: /* original 430b, guest PC 0x0c0770d2 */
if(!s->budget--) { s->failed_pc=0x0c0770d2u; return 0; }
target=r[3];
r[16]=0x0c0770d6u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0770d6u) { target=s->pc; goto dispatch; }
goto P_0c0770d6;
P_0c0770d4: /* original 64c3, guest PC 0x0c0770d4 */
if(!s->budget--) { s->failed_pc=0x0c0770d4u; return 0; }
r[4]=r[12];
goto P_0c0770d6;
P_0c0770d6: /* original 7f0c, guest PC 0x0c0770d6 */
if(!s->budget--) { s->failed_pc=0x0c0770d6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0770d8;
P_0c0770d8: /* original 63e3, guest PC 0x0c0770d8 */
if(!s->budget--) { s->failed_pc=0x0c0770d8u; return 0; }
r[3]=r[14];
goto P_0c0770da;
P_0c0770da: /* original 61f3, guest PC 0x0c0770da */
if(!s->budget--) { s->failed_pc=0x0c0770dau; return 0; }
r[1]=r[15];
goto P_0c0770dc;
P_0c0770dc: /* original 7150, guest PC 0x0c0770dc */
if(!s->budget--) { s->failed_pc=0x0c0770dcu; return 0; }
r[1]+=0x00000050u;
goto P_0c0770de;
P_0c0770de: /* original 7338, guest PC 0x0c0770de */
if(!s->budget--) { s->failed_pc=0x0c0770deu; return 0; }
r[3]+=0x00000038u;
goto P_0c0770e0;
P_0c0770e0: /* original 2102, guest PC 0x0c0770e0 */
if(!s->budget--) { s->failed_pc=0x0c0770e0u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0770e2;
P_0c0770e2: /* original 8433, guest PC 0x0c0770e2 */
if(!s->budget--) { s->failed_pc=0x0c0770e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c0770e4;
P_0c0770e4: /* original 61f3, guest PC 0x0c0770e4 */
if(!s->budget--) { s->failed_pc=0x0c0770e4u; return 0; }
r[1]=r[15];
goto P_0c0770e6;
P_0c0770e6: /* original 7168, guest PC 0x0c0770e6 */
if(!s->budget--) { s->failed_pc=0x0c0770e6u; return 0; }
r[1]+=0x00000068u;
goto P_0c0770e8;
P_0c0770e8: /* original 600c, guest PC 0x0c0770e8 */
if(!s->budget--) { s->failed_pc=0x0c0770e8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0770ea;
P_0c0770ea: /* original 2102, guest PC 0x0c0770ea */
if(!s->budget--) { s->failed_pc=0x0c0770eau; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0770ec;
P_0c0770ec: /* original 9053, guest PC 0x0c0770ec */
if(!s->budget--) { s->failed_pc=0x0c0770ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077196u,2);
goto P_0c0770ee;
P_0c0770ee: /* original 03ee, guest PC 0x0c0770ee */
if(!s->budget--) { s->failed_pc=0x0c0770eeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0770f0;
P_0c0770f0: /* original e064, guest PC 0x0c0770f0 */
if(!s->budget--) { s->failed_pc=0x0c0770f0u; return 0; }
r[0]=0x00000064u;
goto P_0c0770f2;
P_0c0770f2: /* original 0f36, guest PC 0x0c0770f2 */
if(!s->budget--) { s->failed_pc=0x0c0770f2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0770f4;
P_0c0770f4: /* original e062, guest PC 0x0c0770f4 */
if(!s->budget--) { s->failed_pc=0x0c0770f4u; return 0; }
r[0]=0x00000062u;
goto P_0c0770f6;
P_0c0770f6: /* original 02ec, guest PC 0x0c0770f6 */
if(!s->budget--) { s->failed_pc=0x0c0770f6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0770f8;
P_0c0770f8: /* original e060, guest PC 0x0c0770f8 */
if(!s->budget--) { s->failed_pc=0x0c0770f8u; return 0; }
r[0]=0x00000060u;
goto P_0c0770fa;
P_0c0770fa: /* original 622c, guest PC 0x0c0770fa */
if(!s->budget--) { s->failed_pc=0x0c0770fau; return 0; }
r[2]=r[2]&255u;
goto P_0c0770fc;
P_0c0770fc: /* original 0f26, guest PC 0x0c0770fc */
if(!s->budget--) { s->failed_pc=0x0c0770fcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0770fe;
P_0c0770fe: /* original e068, guest PC 0x0c0770fe */
if(!s->budget--) { s->failed_pc=0x0c0770feu; return 0; }
r[0]=0x00000068u;
goto P_0c077100;
P_0c077100: /* original 00fe, guest PC 0x0c077100 */
if(!s->budget--) { s->failed_pc=0x0c077100u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077102;
P_0c077102: /* original 880b, guest PC 0x0c077102 */
if(!s->budget--) { s->failed_pc=0x0c077102u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c077104;
P_0c077104: /* original 8901, guest PC 0x0c077104 */
if(!s->budget--) { s->failed_pc=0x0c077104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07710a; }
goto P_0c077106;
P_0c077106: /* original a0f8, guest PC 0x0c077106 */
if(!s->budget--) { s->failed_pc=0x0c077106u; return 0; }
goto P_0c0772fa;
P_0c077108: /* original 0009, guest PC 0x0c077108 */
if(!s->budget--) { s->failed_pc=0x0c077108u; return 0; }
goto P_0c07710a;
P_0c07710a: /* original e064, guest PC 0x0c07710a */
if(!s->budget--) { s->failed_pc=0x0c07710au; return 0; }
r[0]=0x00000064u;
goto P_0c07710c;
P_0c07710c: /* original 01fe, guest PC 0x0c07710c */
if(!s->budget--) { s->failed_pc=0x0c07710cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07710e;
P_0c07710e: /* original 2118, guest PC 0x0c07710e */
if(!s->budget--) { s->failed_pc=0x0c07710eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c077110;
P_0c077110: /* original 8901, guest PC 0x0c077110 */
if(!s->budget--) { s->failed_pc=0x0c077110u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077116; }
goto P_0c077112;
P_0c077112: /* original a0f2, guest PC 0x0c077112 */
if(!s->budget--) { s->failed_pc=0x0c077112u; return 0; }
goto P_0c0772fa;
P_0c077114: /* original 0009, guest PC 0x0c077114 */
if(!s->budget--) { s->failed_pc=0x0c077114u; return 0; }
goto P_0c077116;
P_0c077116: /* original e060, guest PC 0x0c077116 */
if(!s->budget--) { s->failed_pc=0x0c077116u; return 0; }
r[0]=0x00000060u;
goto P_0c077118;
P_0c077118: /* original 00fe, guest PC 0x0c077118 */
if(!s->budget--) { s->failed_pc=0x0c077118u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07711a;
P_0c07711a: /* original 8804, guest PC 0x0c07711a */
if(!s->budget--) { s->failed_pc=0x0c07711au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c07711c;
P_0c07711c: /* original 8b01, guest PC 0x0c07711c */
if(!s->budget--) { s->failed_pc=0x0c07711cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077122; }
goto P_0c07711e;
P_0c07711e: /* original a0bf, guest PC 0x0c07711e */
if(!s->budget--) { s->failed_pc=0x0c07711eu; return 0; }
goto P_0c0772a0;
P_0c077120: /* original 0009, guest PC 0x0c077120 */
if(!s->budget--) { s->failed_pc=0x0c077120u; return 0; }
goto P_0c077122;
P_0c077122: /* original e060, guest PC 0x0c077122 */
if(!s->budget--) { s->failed_pc=0x0c077122u; return 0; }
r[0]=0x00000060u;
goto P_0c077124;
P_0c077124: /* original 00fe, guest PC 0x0c077124 */
if(!s->budget--) { s->failed_pc=0x0c077124u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077126;
P_0c077126: /* original 8805, guest PC 0x0c077126 */
if(!s->budget--) { s->failed_pc=0x0c077126u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c077128;
P_0c077128: /* original 8b01, guest PC 0x0c077128 */
if(!s->budget--) { s->failed_pc=0x0c077128u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07712e; }
goto P_0c07712a;
P_0c07712a: /* original a0b9, guest PC 0x0c07712a */
if(!s->budget--) { s->failed_pc=0x0c07712au; return 0; }
goto P_0c0772a0;
P_0c07712c: /* original 0009, guest PC 0x0c07712c */
if(!s->budget--) { s->failed_pc=0x0c07712cu; return 0; }
goto P_0c07712e;
P_0c07712e: /* original e060, guest PC 0x0c07712e */
if(!s->budget--) { s->failed_pc=0x0c07712eu; return 0; }
r[0]=0x00000060u;
goto P_0c077130;
P_0c077130: /* original 02fe, guest PC 0x0c077130 */
if(!s->budget--) { s->failed_pc=0x0c077130u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077132;
P_0c077132: /* original e305, guest PC 0x0c077132 */
if(!s->budget--) { s->failed_pc=0x0c077132u; return 0; }
r[3]=0x00000005u;
goto P_0c077134;
P_0c077134: /* original 3236, guest PC 0x0c077134 */
if(!s->budget--) { s->failed_pc=0x0c077134u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c077136;
P_0c077136: /* original 8b01, guest PC 0x0c077136 */
if(!s->budget--) { s->failed_pc=0x0c077136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07713c; }
goto P_0c077138;
P_0c077138: /* original a67e, guest PC 0x0c077138 */
if(!s->budget--) { s->failed_pc=0x0c077138u; return 0; }
goto P_0c077e38;
P_0c07713a: /* original 0009, guest PC 0x0c07713a */
if(!s->budget--) { s->failed_pc=0x0c07713au; return 0; }
goto P_0c07713c;
P_0c07713c: /* original e050, guest PC 0x0c07713c */
if(!s->budget--) { s->failed_pc=0x0c07713cu; return 0; }
r[0]=0x00000050u;
goto P_0c07713e;
P_0c07713e: /* original 01fe, guest PC 0x0c07713e */
if(!s->budget--) { s->failed_pc=0x0c07713eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077140;
P_0c077140: /* original 6313, guest PC 0x0c077140 */
if(!s->budget--) { s->failed_pc=0x0c077140u; return 0; }
r[3]=r[1];
goto P_0c077142;
P_0c077142: /* original 2338, guest PC 0x0c077142 */
if(!s->budget--) { s->failed_pc=0x0c077142u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c077144;
P_0c077144: /* original 8d02, guest PC 0x0c077144 */
if(!s->budget--) { s->failed_pc=0x0c077144u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+48,r[1],4);
if(cond) { goto P_0c07714c; }
goto P_0c077148;
P_0c077146: /* original 1f1c, guest PC 0x0c077146 */
if(!s->budget--) { s->failed_pc=0x0c077146u; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c077148;
P_0c077148: /* original e301, guest PC 0x0c077148 */
if(!s->budget--) { s->failed_pc=0x0c077148u; return 0; }
r[3]=0x00000001u;
goto P_0c07714a;
P_0c07714a: /* original 1f3c, guest PC 0x0c07714a */
if(!s->budget--) { s->failed_pc=0x0c07714au; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c07714c;
P_0c07714c: /* original 61f3, guest PC 0x0c07714c */
if(!s->budget--) { s->failed_pc=0x0c07714cu; return 0; }
r[1]=r[15];
goto P_0c07714e;
P_0c07714e: /* original 7150, guest PC 0x0c07714e */
if(!s->budget--) { s->failed_pc=0x0c07714eu; return 0; }
r[1]+=0x00000050u;
goto P_0c077150;
P_0c077150: /* original d314, guest PC 0x0c077150 */
if(!s->budget--) { s->failed_pc=0x0c077150u; return 0; }
r[3]=read(ram,0x0c0771a4u,4);
goto P_0c077152;
P_0c077152: /* original 52fc, guest PC 0x0c077152 */
if(!s->budget--) { s->failed_pc=0x0c077152u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c077154;
P_0c077154: /* original 323c, guest PC 0x0c077154 */
if(!s->budget--) { s->failed_pc=0x0c077154u; return 0; }
r[2]+=r[3];
goto P_0c077156;
P_0c077156: /* original 1f2e, guest PC 0x0c077156 */
if(!s->budget--) { s->failed_pc=0x0c077156u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c077158;
P_0c077158: /* original 6012, guest PC 0x0c077158 */
if(!s->budget--) { s->failed_pc=0x0c077158u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c07715a;
P_0c07715a: /* original c802, guest PC 0x0c07715a */
if(!s->budget--) { s->failed_pc=0x0c07715au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07715c;
P_0c07715c: /* original 8910, guest PC 0x0c07715c */
if(!s->budget--) { s->failed_pc=0x0c07715cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077180; }
goto P_0c07715e;
P_0c07715e: /* original e06c, guest PC 0x0c07715e */
if(!s->budget--) { s->failed_pc=0x0c07715eu; return 0; }
r[0]=0x0000006cu;
goto P_0c077160;
P_0c077160: /* original e11e, guest PC 0x0c077160 */
if(!s->budget--) { s->failed_pc=0x0c077160u; return 0; }
r[1]=0x0000001eu;
goto P_0c077162;
P_0c077162: /* original 0f16, guest PC 0x0c077162 */
if(!s->budget--) { s->failed_pc=0x0c077162u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077164;
P_0c077164: /* original 50f1, guest PC 0x0c077164 */
if(!s->budget--) { s->failed_pc=0x0c077164u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077166;
P_0c077166: /* original c810, guest PC 0x0c077166 */
if(!s->budget--) { s->failed_pc=0x0c077166u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c077168;
P_0c077168: /* original 8902, guest PC 0x0c077168 */
if(!s->budget--) { s->failed_pc=0x0c077168u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077170; }
goto P_0c07716a;
P_0c07716a: /* original e06c, guest PC 0x0c07716a */
if(!s->budget--) { s->failed_pc=0x0c07716au; return 0; }
r[0]=0x0000006cu;
goto P_0c07716c;
P_0c07716c: /* original e11d, guest PC 0x0c07716c */
if(!s->budget--) { s->failed_pc=0x0c07716cu; return 0; }
r[1]=0x0000001du;
goto P_0c07716e;
P_0c07716e: /* original 0f16, guest PC 0x0c07716e */
if(!s->budget--) { s->failed_pc=0x0c07716eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077170;
P_0c077170: /* original e06c, guest PC 0x0c077170 */
if(!s->budget--) { s->failed_pc=0x0c077170u; return 0; }
r[0]=0x0000006cu;
goto P_0c077172;
P_0c077172: /* original d209, guest PC 0x0c077172 */
if(!s->budget--) { s->failed_pc=0x0c077172u; return 0; }
r[2]=read(ram,0x0c077198u,4);
goto P_0c077174;
P_0c077174: /* original 03fe, guest PC 0x0c077174 */
if(!s->budget--) { s->failed_pc=0x0c077174u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077176;
P_0c077176: /* original 51fe, guest PC 0x0c077176 */
if(!s->budget--) { s->failed_pc=0x0c077176u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077178;
P_0c077178: /* original 633b, guest PC 0x0c077178 */
if(!s->budget--) { s->failed_pc=0x0c077178u; return 0; }
r[3]=0u-r[3];
goto P_0c07717a;
P_0c07717a: /* original 423d, guest PC 0x0c07717a */
if(!s->budget--) { s->failed_pc=0x0c07717au; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c07717c;
P_0c07717c: /* original 212b, guest PC 0x0c07717c */
if(!s->budget--) { s->failed_pc=0x0c07717cu; return 0; }
r[1]|=r[2];
goto P_0c07717e;
P_0c07717e: /* original 1f1e, guest PC 0x0c07717e */
if(!s->budget--) { s->failed_pc=0x0c07717eu; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077180;
P_0c077180: /* original 62f3, guest PC 0x0c077180 */
if(!s->budget--) { s->failed_pc=0x0c077180u; return 0; }
r[2]=r[15];
goto P_0c077182;
P_0c077182: /* original 7250, guest PC 0x0c077182 */
if(!s->budget--) { s->failed_pc=0x0c077182u; return 0; }
r[2]+=0x00000050u;
goto P_0c077184;
P_0c077184: /* original 6022, guest PC 0x0c077184 */
if(!s->budget--) { s->failed_pc=0x0c077184u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c077186;
P_0c077186: /* original c808, guest PC 0x0c077186 */
if(!s->budget--) { s->failed_pc=0x0c077186u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c077188;
P_0c077188: /* original 8910, guest PC 0x0c077188 */
if(!s->budget--) { s->failed_pc=0x0c077188u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0771ac; }
goto P_0c07718a;
P_0c07718a: /* original 51fc, guest PC 0x0c07718a */
if(!s->budget--) { s->failed_pc=0x0c07718au; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c07718c;
P_0c07718c: /* original d306, guest PC 0x0c07718c */
if(!s->budget--) { s->failed_pc=0x0c07718cu; return 0; }
r[3]=read(ram,0x0c0771a8u,4);
goto P_0c07718e;
P_0c07718e: /* original a079, guest PC 0x0c07718e */
if(!s->budget--) { s->failed_pc=0x0c07718eu; return 0; }
r[1]+=r[3];
goto P_0c077284;
P_0c077190: /* original 313c, guest PC 0x0c077190 */
if(!s->budget--) { s->failed_pc=0x0c077190u; return 0; }
r[1]+=r[3];
return vf3_matrix_family(0x0c077192u,s,ram);
P_0c0771ac: /* original 62f3, guest PC 0x0c0771ac */
if(!s->budget--) { s->failed_pc=0x0c0771acu; return 0; }
r[2]=r[15];
goto P_0c0771ae;
P_0c0771ae: /* original 7250, guest PC 0x0c0771ae */
if(!s->budget--) { s->failed_pc=0x0c0771aeu; return 0; }
r[2]+=0x00000050u;
goto P_0c0771b0;
P_0c0771b0: /* original 6022, guest PC 0x0c0771b0 */
if(!s->budget--) { s->failed_pc=0x0c0771b0u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0771b2;
P_0c0771b2: /* original c804, guest PC 0x0c0771b2 */
if(!s->budget--) { s->failed_pc=0x0c0771b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0771b4;
P_0c0771b4: /* original 892b, guest PC 0x0c0771b4 */
if(!s->budget--) { s->failed_pc=0x0c0771b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07720e; }
goto P_0c0771b6;
P_0c0771b6: /* original 50fe, guest PC 0x0c0771b6 */
if(!s->budget--) { s->failed_pc=0x0c0771b6u; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c0771b8;
P_0c0771b8: /* original cb40, guest PC 0x0c0771b8 */
if(!s->budget--) { s->failed_pc=0x0c0771b8u; return 0; }
r[0]|=64u;
goto P_0c0771ba;
P_0c0771ba: /* original 1f0e, guest PC 0x0c0771ba */
if(!s->budget--) { s->failed_pc=0x0c0771bau; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c0771bc;
P_0c0771bc: /* original 50f1, guest PC 0x0c0771bc */
if(!s->budget--) { s->failed_pc=0x0c0771bcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0771be;
P_0c0771be: /* original c9f0, guest PC 0x0c0771be */
if(!s->budget--) { s->failed_pc=0x0c0771beu; return 0; }
r[0]&=240u;
goto P_0c0771c0;
P_0c0771c0: /* original 81f5, guest PC 0x0c0771c0 */
if(!s->budget--) { s->failed_pc=0x0c0771c0u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771c2;
P_0c0771c2: /* original 600d, guest PC 0x0c0771c2 */
if(!s->budget--) { s->failed_pc=0x0c0771c2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771c4;
P_0c0771c4: /* original 2008, guest PC 0x0c0771c4 */
if(!s->budget--) { s->failed_pc=0x0c0771c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0771c6;
P_0c0771c6: /* original 895e, guest PC 0x0c0771c6 */
if(!s->budget--) { s->failed_pc=0x0c0771c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077286; }
goto P_0c0771c8;
P_0c0771c8: /* original 85f5, guest PC 0x0c0771c8 */
if(!s->budget--) { s->failed_pc=0x0c0771c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+10,2);
goto P_0c0771ca;
P_0c0771ca: /* original 600d, guest PC 0x0c0771ca */
if(!s->budget--) { s->failed_pc=0x0c0771cau; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771cc;
P_0c0771cc: /* original 4009, guest PC 0x0c0771cc */
if(!s->budget--) { s->failed_pc=0x0c0771ccu; return 0; }
r[0]>>=2;
goto P_0c0771ce;
P_0c0771ce: /* original 4009, guest PC 0x0c0771ce */
if(!s->budget--) { s->failed_pc=0x0c0771ceu; return 0; }
r[0]>>=2;
goto P_0c0771d0;
P_0c0771d0: /* original 81f5, guest PC 0x0c0771d0 */
if(!s->budget--) { s->failed_pc=0x0c0771d0u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771d2;
P_0c0771d2: /* original 600d, guest PC 0x0c0771d2 */
if(!s->budget--) { s->failed_pc=0x0c0771d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771d4;
P_0c0771d4: /* original d12e, guest PC 0x0c0771d4 */
if(!s->budget--) { s->failed_pc=0x0c0771d4u; return 0; }
r[1]=read(ram,0x0c077290u,4);
goto P_0c0771d6;
P_0c0771d6: /* original 4000, guest PC 0x0c0771d6 */
if(!s->budget--) { s->failed_pc=0x0c0771d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0771d8;
P_0c0771d8: /* original 001d, guest PC 0x0c0771d8 */
if(!s->budget--) { s->failed_pc=0x0c0771d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c0771da;
P_0c0771da: /* original 81f5, guest PC 0x0c0771da */
if(!s->budget--) { s->failed_pc=0x0c0771dau; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771dc;
P_0c0771dc: /* original 9056, guest PC 0x0c0771dc */
if(!s->budget--) { s->failed_pc=0x0c0771dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07728cu,2);
goto P_0c0771de;
P_0c0771de: /* original 03ed, guest PC 0x0c0771de */
if(!s->budget--) { s->failed_pc=0x0c0771deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0771e0;
P_0c0771e0: /* original 85f5, guest PC 0x0c0771e0 */
if(!s->budget--) { s->failed_pc=0x0c0771e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+10,2);
goto P_0c0771e2;
P_0c0771e2: /* original 3038, guest PC 0x0c0771e2 */
if(!s->budget--) { s->failed_pc=0x0c0771e2u; return 0; }
r[0]-=r[3];
goto P_0c0771e4;
P_0c0771e4: /* original 81f5, guest PC 0x0c0771e4 */
if(!s->budget--) { s->failed_pc=0x0c0771e4u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771e6;
P_0c0771e6: /* original d32b, guest PC 0x0c0771e6 */
if(!s->budget--) { s->failed_pc=0x0c0771e6u; return 0; }
r[3]=read(ram,0x0c077294u,4);
goto P_0c0771e8;
P_0c0771e8: /* original 6132, guest PC 0x0c0771e8 */
if(!s->budget--) { s->failed_pc=0x0c0771e8u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0771ea;
P_0c0771ea: /* original 851f, guest PC 0x0c0771ea */
if(!s->budget--) { s->failed_pc=0x0c0771eau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+30,2);
goto P_0c0771ec;
P_0c0771ec: /* original 6203, guest PC 0x0c0771ec */
if(!s->budget--) { s->failed_pc=0x0c0771ecu; return 0; }
r[2]=r[0];
goto P_0c0771ee;
P_0c0771ee: /* original 85f5, guest PC 0x0c0771ee */
if(!s->budget--) { s->failed_pc=0x0c0771eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+10,2);
goto P_0c0771f0;
P_0c0771f0: /* original 302c, guest PC 0x0c0771f0 */
if(!s->budget--) { s->failed_pc=0x0c0771f0u; return 0; }
r[0]+=r[2];
goto P_0c0771f2;
P_0c0771f2: /* original 81f5, guest PC 0x0c0771f2 */
if(!s->budget--) { s->failed_pc=0x0c0771f2u; return 0; }
write(ram,r[15]+10,r[0],2);
goto P_0c0771f4;
P_0c0771f4: /* original 600d, guest PC 0x0c0771f4 */
if(!s->budget--) { s->failed_pc=0x0c0771f4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0771f6;
P_0c0771f6: /* original d128, guest PC 0x0c0771f6 */
if(!s->budget--) { s->failed_pc=0x0c0771f6u; return 0; }
r[1]=read(ram,0x0c077298u,4);
goto P_0c0771f8;
P_0c0771f8: /* original 2018, guest PC 0x0c0771f8 */
if(!s->budget--) { s->failed_pc=0x0c0771f8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c0771fa;
P_0c0771fa: /* original 8903, guest PC 0x0c0771fa */
if(!s->budget--) { s->failed_pc=0x0c0771fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077204; }
goto P_0c0771fc;
P_0c0771fc: /* original 50fe, guest PC 0x0c0771fc */
if(!s->budget--) { s->failed_pc=0x0c0771fcu; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c0771fe;
P_0c0771fe: /* original cb80, guest PC 0x0c0771fe */
if(!s->budget--) { s->failed_pc=0x0c0771feu; return 0; }
r[0]|=128u;
goto P_0c077200;
P_0c077200: /* original a041, guest PC 0x0c077200 */
if(!s->budget--) { s->failed_pc=0x0c077200u; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077286;
P_0c077202: /* original 1f0e, guest PC 0x0c077202 */
if(!s->budget--) { s->failed_pc=0x0c077202u; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077204;
P_0c077204: /* original 51fe, guest PC 0x0c077204 */
if(!s->budget--) { s->failed_pc=0x0c077204u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077206;
P_0c077206: /* original 9242, guest PC 0x0c077206 */
if(!s->budget--) { s->failed_pc=0x0c077206u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07728eu,2);
goto P_0c077208;
P_0c077208: /* original 212b, guest PC 0x0c077208 */
if(!s->budget--) { s->failed_pc=0x0c077208u; return 0; }
r[1]|=r[2];
goto P_0c07720a;
P_0c07720a: /* original a03c, guest PC 0x0c07720a */
if(!s->budget--) { s->failed_pc=0x0c07720au; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077286;
P_0c07720c: /* original 1f1e, guest PC 0x0c07720c */
if(!s->budget--) { s->failed_pc=0x0c07720cu; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c07720e;
P_0c07720e: /* original 53f1, guest PC 0x0c07720e */
if(!s->budget--) { s->failed_pc=0x0c07720eu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077210;
P_0c077210: /* original 1f3b, guest PC 0x0c077210 */
if(!s->budget--) { s->failed_pc=0x0c077210u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c077212;
P_0c077212: /* original 52ee, guest PC 0x0c077212 */
if(!s->budget--) { s->failed_pc=0x0c077212u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c077214;
P_0c077214: /* original d321, guest PC 0x0c077214 */
if(!s->budget--) { s->failed_pc=0x0c077214u; return 0; }
r[3]=read(ram,0x0c07729cu,4);
goto P_0c077216;
P_0c077216: /* original 2238, guest PC 0x0c077216 */
if(!s->budget--) { s->failed_pc=0x0c077216u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077218;
P_0c077218: /* original 8902, guest PC 0x0c077218 */
if(!s->budget--) { s->failed_pc=0x0c077218u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077220; }
goto P_0c07721a;
P_0c07721a: /* original e050, guest PC 0x0c07721a */
if(!s->budget--) { s->failed_pc=0x0c07721au; return 0; }
r[0]=0x00000050u;
goto P_0c07721c;
P_0c07721c: /* original 00fe, guest PC 0x0c07721c */
if(!s->budget--) { s->failed_pc=0x0c07721cu; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c07721e;
P_0c07721e: /* original 1f0b, guest PC 0x0c07721e */
if(!s->budget--) { s->failed_pc=0x0c07721eu; return 0; }
write(ram,r[15]+44,r[0],4);
goto P_0c077220;
P_0c077220: /* original 50fb, guest PC 0x0c077220 */
if(!s->budget--) { s->failed_pc=0x0c077220u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c077222;
P_0c077222: /* original c810, guest PC 0x0c077222 */
if(!s->budget--) { s->failed_pc=0x0c077222u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c077224;
P_0c077224: /* original 8b13, guest PC 0x0c077224 */
if(!s->budget--) { s->failed_pc=0x0c077224u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07724e; }
goto P_0c077226;
P_0c077226: /* original 50fb, guest PC 0x0c077226 */
if(!s->budget--) { s->failed_pc=0x0c077226u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c077228;
P_0c077228: /* original c820, guest PC 0x0c077228 */
if(!s->budget--) { s->failed_pc=0x0c077228u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c07722a;
P_0c07722a: /* original 8b10, guest PC 0x0c07722a */
if(!s->budget--) { s->failed_pc=0x0c07722au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07724e; }
goto P_0c07722c;
P_0c07722c: /* original e040, guest PC 0x0c07722c */
if(!s->budget--) { s->failed_pc=0x0c07722cu; return 0; }
r[0]=0x00000040u;
goto P_0c07722e;
P_0c07722e: /* original 53fb, guest PC 0x0c07722e */
if(!s->budget--) { s->failed_pc=0x0c07722eu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c077230;
P_0c077230: /* original 02fe, guest PC 0x0c077230 */
if(!s->budget--) { s->failed_pc=0x0c077230u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077232;
P_0c077232: /* original 2238, guest PC 0x0c077232 */
if(!s->budget--) { s->failed_pc=0x0c077232u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077234;
P_0c077234: /* original 8902, guest PC 0x0c077234 */
if(!s->budget--) { s->failed_pc=0x0c077234u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07723c; }
goto P_0c077236;
P_0c077236: /* original 50fe, guest PC 0x0c077236 */
if(!s->budget--) { s->failed_pc=0x0c077236u; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c077238;
P_0c077238: /* original a007, guest PC 0x0c077238 */
if(!s->budget--) { s->failed_pc=0x0c077238u; return 0; }
r[0]|=32u;
goto P_0c07724a;
P_0c07723a: /* original cb20, guest PC 0x0c07723a */
if(!s->budget--) { s->failed_pc=0x0c07723au; return 0; }
r[0]|=32u;
goto P_0c07723c;
P_0c07723c: /* original e044, guest PC 0x0c07723c */
if(!s->budget--) { s->failed_pc=0x0c07723cu; return 0; }
r[0]=0x00000044u;
goto P_0c07723e;
P_0c07723e: /* original 53fb, guest PC 0x0c07723e */
if(!s->budget--) { s->failed_pc=0x0c07723eu; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c077240;
P_0c077240: /* original 02fe, guest PC 0x0c077240 */
if(!s->budget--) { s->failed_pc=0x0c077240u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077242;
P_0c077242: /* original 2238, guest PC 0x0c077242 */
if(!s->budget--) { s->failed_pc=0x0c077242u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077244;
P_0c077244: /* original 8903, guest PC 0x0c077244 */
if(!s->budget--) { s->failed_pc=0x0c077244u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07724e; }
goto P_0c077246;
P_0c077246: /* original 50fe, guest PC 0x0c077246 */
if(!s->budget--) { s->failed_pc=0x0c077246u; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c077248;
P_0c077248: /* original cb10, guest PC 0x0c077248 */
if(!s->budget--) { s->failed_pc=0x0c077248u; return 0; }
r[0]|=16u;
goto P_0c07724a;
P_0c07724a: /* original a01c, guest PC 0x0c07724a */
if(!s->budget--) { s->failed_pc=0x0c07724au; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077286;
P_0c07724c: /* original 1f0e, guest PC 0x0c07724c */
if(!s->budget--) { s->failed_pc=0x0c07724cu; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c07724e;
P_0c07724e: /* original 53fe, guest PC 0x0c07724e */
if(!s->budget--) { s->failed_pc=0x0c07724eu; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c077250;
P_0c077250: /* original 1f3d, guest PC 0x0c077250 */
if(!s->budget--) { s->failed_pc=0x0c077250u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c077252;
P_0c077252: /* original e3fe, guest PC 0x0c077252 */
if(!s->budget--) { s->failed_pc=0x0c077252u; return 0; }
r[3]=0xfffffffeu;
goto P_0c077254;
P_0c077254: /* original 52ee, guest PC 0x0c077254 */
if(!s->budget--) { s->failed_pc=0x0c077254u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c077256;
P_0c077256: /* original 50fc, guest PC 0x0c077256 */
if(!s->budget--) { s->failed_pc=0x0c077256u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c077258;
P_0c077258: /* original 2239, guest PC 0x0c077258 */
if(!s->budget--) { s->failed_pc=0x0c077258u; return 0; }
r[2]&=r[3];
goto P_0c07725a;
P_0c07725a: /* original c901, guest PC 0x0c07725a */
if(!s->budget--) { s->failed_pc=0x0c07725au; return 0; }
r[0]&=1u;
goto P_0c07725c;
P_0c07725c: /* original 202b, guest PC 0x0c07725c */
if(!s->budget--) { s->failed_pc=0x0c07725cu; return 0; }
r[0]|=r[2];
goto P_0c07725e;
P_0c07725e: /* original 1f0e, guest PC 0x0c07725e */
if(!s->budget--) { s->failed_pc=0x0c07725eu; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077260;
P_0c077260: /* original 50fd, guest PC 0x0c077260 */
if(!s->budget--) { s->failed_pc=0x0c077260u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c077262;
P_0c077262: /* original c804, guest PC 0x0c077262 */
if(!s->budget--) { s->failed_pc=0x0c077262u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c077264;
P_0c077264: /* original 8b09, guest PC 0x0c077264 */
if(!s->budget--) { s->failed_pc=0x0c077264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07727a; }
goto P_0c077266;
P_0c077266: /* original 50fd, guest PC 0x0c077266 */
if(!s->budget--) { s->failed_pc=0x0c077266u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c077268;
P_0c077268: /* original c802, guest PC 0x0c077268 */
if(!s->budget--) { s->failed_pc=0x0c077268u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07726a;
P_0c07726a: /* original 890c, guest PC 0x0c07726a */
if(!s->budget--) { s->failed_pc=0x0c07726au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077286; }
goto P_0c07726c;
P_0c07726c: /* original 50fe, guest PC 0x0c07726c */
if(!s->budget--) { s->failed_pc=0x0c07726cu; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c07726e;
P_0c07726e: /* original e3fb, guest PC 0x0c07726e */
if(!s->budget--) { s->failed_pc=0x0c07726eu; return 0; }
r[3]=0xfffffffbu;
goto P_0c077270;
P_0c077270: /* original cb02, guest PC 0x0c077270 */
if(!s->budget--) { s->failed_pc=0x0c077270u; return 0; }
r[0]|=2u;
goto P_0c077272;
P_0c077272: /* original 6103, guest PC 0x0c077272 */
if(!s->budget--) { s->failed_pc=0x0c077272u; return 0; }
r[1]=r[0];
goto P_0c077274;
P_0c077274: /* original 1f0e, guest PC 0x0c077274 */
if(!s->budget--) { s->failed_pc=0x0c077274u; return 0; }
write(ram,r[15]+56,r[0],4);
goto P_0c077276;
P_0c077276: /* original a005, guest PC 0x0c077276 */
if(!s->budget--) { s->failed_pc=0x0c077276u; return 0; }
r[1]&=r[3];
goto P_0c077284;
P_0c077278: /* original 2139, guest PC 0x0c077278 */
if(!s->budget--) { s->failed_pc=0x0c077278u; return 0; }
r[1]&=r[3];
goto P_0c07727a;
P_0c07727a: /* original 50fe, guest PC 0x0c07727a */
if(!s->budget--) { s->failed_pc=0x0c07727au; return 0; }
r[0]=read(ram,r[15]+56,4);
goto P_0c07727c;
P_0c07727c: /* original e3fd, guest PC 0x0c07727c */
if(!s->budget--) { s->failed_pc=0x0c07727cu; return 0; }
r[3]=0xfffffffdu;
goto P_0c07727e;
P_0c07727e: /* original cb04, guest PC 0x0c07727e */
if(!s->budget--) { s->failed_pc=0x0c07727eu; return 0; }
r[0]|=4u;
goto P_0c077280;
P_0c077280: /* original 6103, guest PC 0x0c077280 */
if(!s->budget--) { s->failed_pc=0x0c077280u; return 0; }
r[1]=r[0];
goto P_0c077282;
P_0c077282: /* original 2139, guest PC 0x0c077282 */
if(!s->budget--) { s->failed_pc=0x0c077282u; return 0; }
r[1]&=r[3];
goto P_0c077284;
P_0c077284: /* original 1f1e, guest PC 0x0c077284 */
if(!s->budget--) { s->failed_pc=0x0c077284u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077286;
P_0c077286: /* original 52fe, guest PC 0x0c077286 */
if(!s->budget--) { s->failed_pc=0x0c077286u; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c077288;
P_0c077288: /* original a5c1, guest PC 0x0c077288 */
if(!s->budget--) { s->failed_pc=0x0c077288u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077e0e;
P_0c07728a: /* original 1e2c, guest PC 0x0c07728a */
if(!s->budget--) { s->failed_pc=0x0c07728au; return 0; }
write(ram,r[14]+48,r[2],4);
return vf3_matrix_family(0x0c07728cu,s,ram);
P_0c0772a0: /* original 61f3, guest PC 0x0c0772a0 */
if(!s->budget--) { s->failed_pc=0x0c0772a0u; return 0; }
r[1]=r[15];
goto P_0c0772a2;
P_0c0772a2: /* original 7150, guest PC 0x0c0772a2 */
if(!s->budget--) { s->failed_pc=0x0c0772a2u; return 0; }
r[1]+=0x00000050u;
goto P_0c0772a4;
P_0c0772a4: /* original 6012, guest PC 0x0c0772a4 */
if(!s->budget--) { s->failed_pc=0x0c0772a4u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0772a6;
P_0c0772a6: /* original c802, guest PC 0x0c0772a6 */
if(!s->budget--) { s->failed_pc=0x0c0772a6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0772a8;
P_0c0772a8: /* original 8927, guest PC 0x0c0772a8 */
if(!s->budget--) { s->failed_pc=0x0c0772a8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0772fa; }
goto P_0c0772aa;
P_0c0772aa: /* original 62f3, guest PC 0x0c0772aa */
if(!s->budget--) { s->failed_pc=0x0c0772aau; return 0; }
r[2]=r[15];
goto P_0c0772ac;
P_0c0772ac: /* original 7250, guest PC 0x0c0772ac */
if(!s->budget--) { s->failed_pc=0x0c0772acu; return 0; }
r[2]+=0x00000050u;
goto P_0c0772ae;
P_0c0772ae: /* original 6022, guest PC 0x0c0772ae */
if(!s->budget--) { s->failed_pc=0x0c0772aeu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0772b0;
P_0c0772b0: /* original c801, guest PC 0x0c0772b0 */
if(!s->budget--) { s->failed_pc=0x0c0772b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0772b2;
P_0c0772b2: /* original 8b22, guest PC 0x0c0772b2 */
if(!s->budget--) { s->failed_pc=0x0c0772b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772b4;
P_0c0772b4: /* original 61f3, guest PC 0x0c0772b4 */
if(!s->budget--) { s->failed_pc=0x0c0772b4u; return 0; }
r[1]=r[15];
goto P_0c0772b6;
P_0c0772b6: /* original 7150, guest PC 0x0c0772b6 */
if(!s->budget--) { s->failed_pc=0x0c0772b6u; return 0; }
r[1]+=0x00000050u;
goto P_0c0772b8;
P_0c0772b8: /* original 6012, guest PC 0x0c0772b8 */
if(!s->budget--) { s->failed_pc=0x0c0772b8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0772ba;
P_0c0772ba: /* original c804, guest PC 0x0c0772ba */
if(!s->budget--) { s->failed_pc=0x0c0772bau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0772bc;
P_0c0772bc: /* original 8b1d, guest PC 0x0c0772bc */
if(!s->budget--) { s->failed_pc=0x0c0772bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772be;
P_0c0772be: /* original 62f3, guest PC 0x0c0772be */
if(!s->budget--) { s->failed_pc=0x0c0772beu; return 0; }
r[2]=r[15];
goto P_0c0772c0;
P_0c0772c0: /* original 7250, guest PC 0x0c0772c0 */
if(!s->budget--) { s->failed_pc=0x0c0772c0u; return 0; }
r[2]+=0x00000050u;
goto P_0c0772c2;
P_0c0772c2: /* original 6022, guest PC 0x0c0772c2 */
if(!s->budget--) { s->failed_pc=0x0c0772c2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0772c4;
P_0c0772c4: /* original c808, guest PC 0x0c0772c4 */
if(!s->budget--) { s->failed_pc=0x0c0772c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0772c6;
P_0c0772c6: /* original 8b18, guest PC 0x0c0772c6 */
if(!s->budget--) { s->failed_pc=0x0c0772c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772c8;
P_0c0772c8: /* original 51ee, guest PC 0x0c0772c8 */
if(!s->budget--) { s->failed_pc=0x0c0772c8u; return 0; }
r[1]=read(ram,r[14]+56,4);
goto P_0c0772ca;
P_0c0772ca: /* original 6013, guest PC 0x0c0772ca */
if(!s->budget--) { s->failed_pc=0x0c0772cau; return 0; }
r[0]=r[1];
goto P_0c0772cc;
P_0c0772cc: /* original c80e, guest PC 0x0c0772cc */
if(!s->budget--) { s->failed_pc=0x0c0772ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&14u)==0)!=0);
goto P_0c0772ce;
P_0c0772ce: /* original 1f1e, guest PC 0x0c0772ce */
if(!s->budget--) { s->failed_pc=0x0c0772ceu; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c0772d0;
P_0c0772d0: /* original 8b13, guest PC 0x0c0772d0 */
if(!s->budget--) { s->failed_pc=0x0c0772d0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0772fa; }
goto P_0c0772d2;
P_0c0772d2: /* original e06c, guest PC 0x0c0772d2 */
if(!s->budget--) { s->failed_pc=0x0c0772d2u; return 0; }
r[0]=0x0000006cu;
goto P_0c0772d4;
P_0c0772d4: /* original e11e, guest PC 0x0c0772d4 */
if(!s->budget--) { s->failed_pc=0x0c0772d4u; return 0; }
r[1]=0x0000001eu;
goto P_0c0772d6;
P_0c0772d6: /* original 0f16, guest PC 0x0c0772d6 */
if(!s->budget--) { s->failed_pc=0x0c0772d6u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0772d8;
P_0c0772d8: /* original 50f1, guest PC 0x0c0772d8 */
if(!s->budget--) { s->failed_pc=0x0c0772d8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0772da;
P_0c0772da: /* original c810, guest PC 0x0c0772da */
if(!s->budget--) { s->failed_pc=0x0c0772dau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0772dc;
P_0c0772dc: /* original 8902, guest PC 0x0c0772dc */
if(!s->budget--) { s->failed_pc=0x0c0772dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0772e4; }
goto P_0c0772de;
P_0c0772de: /* original e06c, guest PC 0x0c0772de */
if(!s->budget--) { s->failed_pc=0x0c0772deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0772e0;
P_0c0772e0: /* original e11d, guest PC 0x0c0772e0 */
if(!s->budget--) { s->failed_pc=0x0c0772e0u; return 0; }
r[1]=0x0000001du;
goto P_0c0772e2;
P_0c0772e2: /* original 0f16, guest PC 0x0c0772e2 */
if(!s->budget--) { s->failed_pc=0x0c0772e2u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c0772e4;
P_0c0772e4: /* original e06c, guest PC 0x0c0772e4 */
if(!s->budget--) { s->failed_pc=0x0c0772e4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0772e6;
P_0c0772e6: /* original d217, guest PC 0x0c0772e6 */
if(!s->budget--) { s->failed_pc=0x0c0772e6u; return 0; }
r[2]=read(ram,0x0c077344u,4);
goto P_0c0772e8;
P_0c0772e8: /* original 03fe, guest PC 0x0c0772e8 */
if(!s->budget--) { s->failed_pc=0x0c0772e8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0772ea;
P_0c0772ea: /* original 51fe, guest PC 0x0c0772ea */
if(!s->budget--) { s->failed_pc=0x0c0772eau; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c0772ec;
P_0c0772ec: /* original 633b, guest PC 0x0c0772ec */
if(!s->budget--) { s->failed_pc=0x0c0772ecu; return 0; }
r[3]=0u-r[3];
goto P_0c0772ee;
P_0c0772ee: /* original 423d, guest PC 0x0c0772ee */
if(!s->budget--) { s->failed_pc=0x0c0772eeu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0772f0;
P_0c0772f0: /* original 212b, guest PC 0x0c0772f0 */
if(!s->budget--) { s->failed_pc=0x0c0772f0u; return 0; }
r[1]|=r[2];
goto P_0c0772f2;
P_0c0772f2: /* original 6313, guest PC 0x0c0772f2 */
if(!s->budget--) { s->failed_pc=0x0c0772f2u; return 0; }
r[3]=r[1];
goto P_0c0772f4;
P_0c0772f4: /* original 1f1e, guest PC 0x0c0772f4 */
if(!s->budget--) { s->failed_pc=0x0c0772f4u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c0772f6;
P_0c0772f6: /* original a58a, guest PC 0x0c0772f6 */
if(!s->budget--) { s->failed_pc=0x0c0772f6u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c077e0e;
P_0c0772f8: /* original 1e3c, guest PC 0x0c0772f8 */
if(!s->budget--) { s->failed_pc=0x0c0772f8u; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c0772fa;
P_0c0772fa: /* original 61f3, guest PC 0x0c0772fa */
if(!s->budget--) { s->failed_pc=0x0c0772fau; return 0; }
r[1]=r[15];
goto P_0c0772fc;
P_0c0772fc: /* original 7150, guest PC 0x0c0772fc */
if(!s->budget--) { s->failed_pc=0x0c0772fcu; return 0; }
r[1]+=0x00000050u;
goto P_0c0772fe;
P_0c0772fe: /* original 6012, guest PC 0x0c0772fe */
if(!s->budget--) { s->failed_pc=0x0c0772feu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077300;
P_0c077300: /* original c804, guest PC 0x0c077300 */
if(!s->budget--) { s->failed_pc=0x0c077300u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c077302;
P_0c077302: /* original 8b01, guest PC 0x0c077302 */
if(!s->budget--) { s->failed_pc=0x0c077302u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077308; }
goto P_0c077304;
P_0c077304: /* original a0b2, guest PC 0x0c077304 */
if(!s->budget--) { s->failed_pc=0x0c077304u; return 0; }
goto P_0c07746c;
P_0c077306: /* original 0009, guest PC 0x0c077306 */
if(!s->budget--) { s->failed_pc=0x0c077306u; return 0; }
goto P_0c077308;
P_0c077308: /* original 62f3, guest PC 0x0c077308 */
if(!s->budget--) { s->failed_pc=0x0c077308u; return 0; }
r[2]=r[15];
goto P_0c07730a;
P_0c07730a: /* original 7250, guest PC 0x0c07730a */
if(!s->budget--) { s->failed_pc=0x0c07730au; return 0; }
r[2]+=0x00000050u;
goto P_0c07730c;
P_0c07730c: /* original 6022, guest PC 0x0c07730c */
if(!s->budget--) { s->failed_pc=0x0c07730cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07730e;
P_0c07730e: /* original c80b, guest PC 0x0c07730e */
if(!s->budget--) { s->failed_pc=0x0c07730eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&11u)==0)!=0);
goto P_0c077310;
P_0c077310: /* original 8901, guest PC 0x0c077310 */
if(!s->budget--) { s->failed_pc=0x0c077310u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077316; }
goto P_0c077312;
P_0c077312: /* original a0d5, guest PC 0x0c077312 */
if(!s->budget--) { s->failed_pc=0x0c077312u; return 0; }
goto P_0c0774c0;
P_0c077314: /* original 0009, guest PC 0x0c077314 */
if(!s->budget--) { s->failed_pc=0x0c077314u; return 0; }
goto P_0c077316;
P_0c077316: /* original 9012, guest PC 0x0c077316 */
if(!s->budget--) { s->failed_pc=0x0c077316u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07733eu,2);
goto P_0c077318;
P_0c077318: /* original d30b, guest PC 0x0c077318 */
if(!s->budget--) { s->failed_pc=0x0c077318u; return 0; }
r[3]=read(ram,0x0c077348u,4);
goto P_0c07731a;
P_0c07731a: /* original 01fe, guest PC 0x0c07731a */
if(!s->budget--) { s->failed_pc=0x0c07731au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07731c;
P_0c07731c: /* original 900f, guest PC 0x0c07731c */
if(!s->budget--) { s->failed_pc=0x0c07731cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07733eu,2);
goto P_0c07731e;
P_0c07731e: /* original 2139, guest PC 0x0c07731e */
if(!s->budget--) { s->failed_pc=0x0c07731eu; return 0; }
r[1]&=r[3];
goto P_0c077320;
P_0c077320: /* original 0f16, guest PC 0x0c077320 */
if(!s->budget--) { s->failed_pc=0x0c077320u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077322;
P_0c077322: /* original 900d, guest PC 0x0c077322 */
if(!s->budget--) { s->failed_pc=0x0c077322u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077340u,2);
goto P_0c077324;
P_0c077324: /* original 02ec, guest PC 0x0c077324 */
if(!s->budget--) { s->failed_pc=0x0c077324u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077326;
P_0c077326: /* original 7001, guest PC 0x0c077326 */
if(!s->budget--) { s->failed_pc=0x0c077326u; return 0; }
r[0]+=0x00000001u;
goto P_0c077328;
P_0c077328: /* original 0e24, guest PC 0x0c077328 */
if(!s->budget--) { s->failed_pc=0x0c077328u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c07732a;
P_0c07732a: /* original 7015, guest PC 0x0c07732a */
if(!s->budget--) { s->failed_pc=0x0c07732au; return 0; }
r[0]+=0x00000015u;
goto P_0c07732c;
P_0c07732c: /* original 01ee, guest PC 0x0c07732c */
if(!s->budget--) { s->failed_pc=0x0c07732cu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c07732e;
P_0c07732e: /* original 2118, guest PC 0x0c07732e */
if(!s->budget--) { s->failed_pc=0x0c07732eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c077330;
P_0c077330: /* original 890c, guest PC 0x0c077330 */
if(!s->budget--) { s->failed_pc=0x0c077330u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07734c; }
goto P_0c077332;
P_0c077332: /* original 9006, guest PC 0x0c077332 */
if(!s->budget--) { s->failed_pc=0x0c077332u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077342u,2);
goto P_0c077334;
P_0c077334: /* original 01ed, guest PC 0x0c077334 */
if(!s->budget--) { s->failed_pc=0x0c077334u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c077336;
P_0c077336: /* original 2118, guest PC 0x0c077336 */
if(!s->budget--) { s->failed_pc=0x0c077336u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c077338;
P_0c077338: /* original 8b3d, guest PC 0x0c077338 */
if(!s->budget--) { s->failed_pc=0x0c077338u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0773b6; }
goto P_0c07733a;
P_0c07733a: /* original a011, guest PC 0x0c07733a */
if(!s->budget--) { s->failed_pc=0x0c07733au; return 0; }
goto P_0c077360;
P_0c07733c: /* original 0009, guest PC 0x0c07733c */
if(!s->budget--) { s->failed_pc=0x0c07733cu; return 0; }
return vf3_matrix_family(0x0c07733eu,s,ram);
P_0c07734c: /* original 907f, guest PC 0x0c07734c */
if(!s->budget--) { s->failed_pc=0x0c07734cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07744eu,2);
goto P_0c07734e;
P_0c07734e: /* original d244, guest PC 0x0c07734e */
if(!s->budget--) { s->failed_pc=0x0c07734eu; return 0; }
r[2]=read(ram,0x0c077460u,4);
goto P_0c077350;
P_0c077350: /* original 01fe, guest PC 0x0c077350 */
if(!s->budget--) { s->failed_pc=0x0c077350u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077352;
P_0c077352: /* original 2128, guest PC 0x0c077352 */
if(!s->budget--) { s->failed_pc=0x0c077352u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077354;
P_0c077354: /* original 8b2f, guest PC 0x0c077354 */
if(!s->budget--) { s->failed_pc=0x0c077354u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0773b6; }
goto P_0c077356;
P_0c077356: /* original 907b, guest PC 0x0c077356 */
if(!s->budget--) { s->failed_pc=0x0c077356u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077450u,2);
goto P_0c077358;
P_0c077358: /* original d342, guest PC 0x0c077358 */
if(!s->budget--) { s->failed_pc=0x0c077358u; return 0; }
r[3]=read(ram,0x0c077464u,4);
goto P_0c07735a;
P_0c07735a: /* original 02fe, guest PC 0x0c07735a */
if(!s->budget--) { s->failed_pc=0x0c07735au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07735c;
P_0c07735c: /* original 2238, guest PC 0x0c07735c */
if(!s->budget--) { s->failed_pc=0x0c07735cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07735e;
P_0c07735e: /* original 8b2a, guest PC 0x0c07735e */
if(!s->budget--) { s->failed_pc=0x0c07735eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0773b6; }
goto P_0c077360;
P_0c077360: /* original e078, guest PC 0x0c077360 */
if(!s->budget--) { s->failed_pc=0x0c077360u; return 0; }
r[0]=0x00000078u;
goto P_0c077362;
P_0c077362: /* original e104, guest PC 0x0c077362 */
if(!s->budget--) { s->failed_pc=0x0c077362u; return 0; }
r[1]=0x00000004u;
goto P_0c077364;
P_0c077364: /* original 0f16, guest PC 0x0c077364 */
if(!s->budget--) { s->failed_pc=0x0c077364u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077366;
P_0c077366: /* original e050, guest PC 0x0c077366 */
if(!s->budget--) { s->failed_pc=0x0c077366u; return 0; }
r[0]=0x00000050u;
goto P_0c077368;
P_0c077368: /* original 03fe, guest PC 0x0c077368 */
if(!s->budget--) { s->failed_pc=0x0c077368u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07736a;
P_0c07736a: /* original e04c, guest PC 0x0c07736a */
if(!s->budget--) { s->failed_pc=0x0c07736au; return 0; }
r[0]=0x0000004cu;
goto P_0c07736c;
P_0c07736c: /* original 2f36, guest PC 0x0c07736c */
if(!s->budget--) { s->failed_pc=0x0c07736cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07736e;
P_0c07736e: /* original 52f2, guest PC 0x0c07736e */
if(!s->budget--) { s->failed_pc=0x0c07736eu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077370;
P_0c077370: /* original 2f26, guest PC 0x0c077370 */
if(!s->budget--) { s->failed_pc=0x0c077370u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077372;
P_0c077372: /* original 03fe, guest PC 0x0c077372 */
if(!s->budget--) { s->failed_pc=0x0c077372u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077374;
P_0c077374: /* original e04c, guest PC 0x0c077374 */
if(!s->budget--) { s->failed_pc=0x0c077374u; return 0; }
r[0]=0x0000004cu;
goto P_0c077376;
P_0c077376: /* original 2f36, guest PC 0x0c077376 */
if(!s->budget--) { s->failed_pc=0x0c077376u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077378;
P_0c077378: /* original 02fe, guest PC 0x0c077378 */
if(!s->budget--) { s->failed_pc=0x0c077378u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07737a;
P_0c07737a: /* original 2f26, guest PC 0x0c07737a */
if(!s->budget--) { s->failed_pc=0x0c07737au; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07737c;
P_0c07737c: /* original 9069, guest PC 0x0c07737c */
if(!s->budget--) { s->failed_pc=0x0c07737cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c07737e;
P_0c07737e: /* original 03fe, guest PC 0x0c07737e */
if(!s->budget--) { s->failed_pc=0x0c07737eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077380;
P_0c077380: /* original e05c, guest PC 0x0c077380 */
if(!s->budget--) { s->failed_pc=0x0c077380u; return 0; }
r[0]=0x0000005cu;
goto P_0c077382;
P_0c077382: /* original 2f36, guest PC 0x0c077382 */
if(!s->budget--) { s->failed_pc=0x0c077382u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077384;
P_0c077384: /* original 02fe, guest PC 0x0c077384 */
if(!s->budget--) { s->failed_pc=0x0c077384u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077386;
P_0c077386: /* original 2f26, guest PC 0x0c077386 */
if(!s->budget--) { s->failed_pc=0x0c077386u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077388;
P_0c077388: /* original 9364, guest PC 0x0c077388 */
if(!s->budget--) { s->failed_pc=0x0c077388u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c07738a;
P_0c07738a: /* original 33fc, guest PC 0x0c07738a */
if(!s->budget--) { s->failed_pc=0x0c07738au; return 0; }
r[3]+=r[15];
goto P_0c07738c;
P_0c07738c: /* original 2f36, guest PC 0x0c07738c */
if(!s->budget--) { s->failed_pc=0x0c07738cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07738e;
P_0c07738e: /* original 9061, guest PC 0x0c07738e */
if(!s->budget--) { s->failed_pc=0x0c07738eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c077390;
P_0c077390: /* original 02fe, guest PC 0x0c077390 */
if(!s->budget--) { s->failed_pc=0x0c077390u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077392;
P_0c077392: /* original 2f26, guest PC 0x0c077392 */
if(!s->budget--) { s->failed_pc=0x0c077392u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077394;
P_0c077394: /* original 905d, guest PC 0x0c077394 */
if(!s->budget--) { s->failed_pc=0x0c077394u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c077396;
P_0c077396: /* original 03fe, guest PC 0x0c077396 */
if(!s->budget--) { s->failed_pc=0x0c077396u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077398;
P_0c077398: /* original 2f36, guest PC 0x0c077398 */
if(!s->budget--) { s->failed_pc=0x0c077398u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07739a;
P_0c07739a: /* original 905c, guest PC 0x0c07739a */
if(!s->budget--) { s->failed_pc=0x0c07739au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c07739c;
P_0c07739c: /* original 02fe, guest PC 0x0c07739c */
if(!s->budget--) { s->failed_pc=0x0c07739cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07739e;
P_0c07739e: /* original 2f26, guest PC 0x0c07739e */
if(!s->budget--) { s->failed_pc=0x0c07739eu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0773a0;
P_0c0773a0: /* original 9759, guest PC 0x0c0773a0 */
if(!s->budget--) { s->failed_pc=0x0c0773a0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c0773a2;
P_0c0773a2: /* original 65e3, guest PC 0x0c0773a2 */
if(!s->budget--) { s->failed_pc=0x0c0773a2u; return 0; }
r[5]=r[14];
goto P_0c0773a4;
P_0c0773a4: /* original 66d3, guest PC 0x0c0773a4 */
if(!s->budget--) { s->failed_pc=0x0c0773a4u; return 0; }
r[6]=r[13];
goto P_0c0773a6;
P_0c0773a6: /* original 37fc, guest PC 0x0c0773a6 */
if(!s->budget--) { s->failed_pc=0x0c0773a6u; return 0; }
r[7]+=r[15];
goto P_0c0773a8;
P_0c0773a8: /* original b707, guest PC 0x0c0773a8 */
if(!s->budget--) { s->failed_pc=0x0c0773a8u; return 0; }
target=0x0c0781bau; r[16]=0x0c0773acu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0773acu) { target=s->pc; goto dispatch; }
goto P_0c0773ac;
P_0c0773aa: /* original 64c3, guest PC 0x0c0773aa */
if(!s->budget--) { s->failed_pc=0x0c0773aau; return 0; }
r[4]=r[12];
goto P_0c0773ac;
P_0c0773ac: /* original 2008, guest PC 0x0c0773ac */
if(!s->budget--) { s->failed_pc=0x0c0773acu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0773ae;
P_0c0773ae: /* original 8d02, guest PC 0x0c0773ae */
if(!s->budget--) { s->failed_pc=0x0c0773aeu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c0773b6; }
goto P_0c0773b2;
P_0c0773b0: /* original 7f28, guest PC 0x0c0773b0 */
if(!s->budget--) { s->failed_pc=0x0c0773b0u; return 0; }
r[15]+=0x00000028u;
goto P_0c0773b2;
P_0c0773b2: /* original a545, guest PC 0x0c0773b2 */
if(!s->budget--) { s->failed_pc=0x0c0773b2u; return 0; }
goto P_0c077e40;
P_0c0773b4: /* original 0009, guest PC 0x0c0773b4 */
if(!s->budget--) { s->failed_pc=0x0c0773b4u; return 0; }
goto P_0c0773b6;
P_0c0773b6: /* original 904f, guest PC 0x0c0773b6 */
if(!s->budget--) { s->failed_pc=0x0c0773b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077458u,2);
goto P_0c0773b8;
P_0c0773b8: /* original 02ec, guest PC 0x0c0773b8 */
if(!s->budget--) { s->failed_pc=0x0c0773b8u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0773ba;
P_0c0773ba: /* original e06c, guest PC 0x0c0773ba */
if(!s->budget--) { s->failed_pc=0x0c0773bau; return 0; }
r[0]=0x0000006cu;
goto P_0c0773bc;
P_0c0773bc: /* original 622c, guest PC 0x0c0773bc */
if(!s->budget--) { s->failed_pc=0x0c0773bcu; return 0; }
r[2]=r[2]&255u;
goto P_0c0773be;
P_0c0773be: /* original 0f26, guest PC 0x0c0773be */
if(!s->budget--) { s->failed_pc=0x0c0773beu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0773c0;
P_0c0773c0: /* original e06c, guest PC 0x0c0773c0 */
if(!s->budget--) { s->failed_pc=0x0c0773c0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0773c2;
P_0c0773c2: /* original 03fc, guest PC 0x0c0773c2 */
if(!s->budget--) { s->failed_pc=0x0c0773c2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0773c4;
P_0c0773c4: /* original 9049, guest PC 0x0c0773c4 */
if(!s->budget--) { s->failed_pc=0x0c0773c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07745au,2);
goto P_0c0773c6;
P_0c0773c6: /* original 0e34, guest PC 0x0c0773c6 */
if(!s->budget--) { s->failed_pc=0x0c0773c6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0773c8;
P_0c0773c8: /* original e06c, guest PC 0x0c0773c8 */
if(!s->budget--) { s->failed_pc=0x0c0773c8u; return 0; }
r[0]=0x0000006cu;
goto P_0c0773ca;
P_0c0773ca: /* original 02fc, guest PC 0x0c0773ca */
if(!s->budget--) { s->failed_pc=0x0c0773cau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0773cc;
P_0c0773cc: /* original e300, guest PC 0x0c0773cc */
if(!s->budget--) { s->failed_pc=0x0c0773ccu; return 0; }
r[3]=0x00000000u;
goto P_0c0773ce;
P_0c0773ce: /* original 9045, guest PC 0x0c0773ce */
if(!s->budget--) { s->failed_pc=0x0c0773ceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07745cu,2);
goto P_0c0773d0;
P_0c0773d0: /* original 0e24, guest PC 0x0c0773d0 */
if(!s->budget--) { s->failed_pc=0x0c0773d0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0773d2;
P_0c0773d2: /* original 7013, guest PC 0x0c0773d2 */
if(!s->budget--) { s->failed_pc=0x0c0773d2u; return 0; }
r[0]+=0x00000013u;
goto P_0c0773d4;
P_0c0773d4: /* original 0e36, guest PC 0x0c0773d4 */
if(!s->budget--) { s->failed_pc=0x0c0773d4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0773d6;
P_0c0773d6: /* original 70f8, guest PC 0x0c0773d6 */
if(!s->budget--) { s->failed_pc=0x0c0773d6u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0773d8;
P_0c0773d8: /* original 6233, guest PC 0x0c0773d8 */
if(!s->budget--) { s->failed_pc=0x0c0773d8u; return 0; }
r[2]=r[3];
goto P_0c0773da;
P_0c0773da: /* original 0e25, guest PC 0x0c0773da */
if(!s->budget--) { s->failed_pc=0x0c0773dau; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0773dc;
P_0c0773dc: /* original e03c, guest PC 0x0c0773dc */
if(!s->budget--) { s->failed_pc=0x0c0773dcu; return 0; }
r[0]=0x0000003cu;
goto P_0c0773de;
P_0c0773de: /* original 03ed, guest PC 0x0c0773de */
if(!s->budget--) { s->failed_pc=0x0c0773deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0773e0;
P_0c0773e0: /* original 2338, guest PC 0x0c0773e0 */
if(!s->budget--) { s->failed_pc=0x0c0773e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0773e2;
P_0c0773e2: /* original 890a, guest PC 0x0c0773e2 */
if(!s->budget--) { s->failed_pc=0x0c0773e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0773fa; }
goto P_0c0773e4;
P_0c0773e4: /* original e03e, guest PC 0x0c0773e4 */
if(!s->budget--) { s->failed_pc=0x0c0773e4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0773e6;
P_0c0773e6: /* original 03ed, guest PC 0x0c0773e6 */
if(!s->budget--) { s->failed_pc=0x0c0773e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0773e8;
P_0c0773e8: /* original 9039, guest PC 0x0c0773e8 */
if(!s->budget--) { s->failed_pc=0x0c0773e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07745eu,2);
goto P_0c0773ea;
P_0c0773ea: /* original 633d, guest PC 0x0c0773ea */
if(!s->budget--) { s->failed_pc=0x0c0773eau; return 0; }
r[3]=r[3]&65535u;
goto P_0c0773ec;
P_0c0773ec: /* original 02ec, guest PC 0x0c0773ec */
if(!s->budget--) { s->failed_pc=0x0c0773ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0773ee;
P_0c0773ee: /* original 622c, guest PC 0x0c0773ee */
if(!s->budget--) { s->failed_pc=0x0c0773eeu; return 0; }
r[2]=r[2]&255u;
goto P_0c0773f0;
P_0c0773f0: /* original 3327, guest PC 0x0c0773f0 */
if(!s->budget--) { s->failed_pc=0x0c0773f0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[2])!=0);
goto P_0c0773f2;
P_0c0773f2: /* original 8902, guest PC 0x0c0773f2 */
if(!s->budget--) { s->failed_pc=0x0c0773f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0773fa; }
goto P_0c0773f4;
P_0c0773f4: /* original d21c, guest PC 0x0c0773f4 */
if(!s->budget--) { s->failed_pc=0x0c0773f4u; return 0; }
r[2]=read(ram,0x0c077468u,4);
goto P_0c0773f6;
P_0c0773f6: /* original a51f, guest PC 0x0c0773f6 */
if(!s->budget--) { s->failed_pc=0x0c0773f6u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077e38;
P_0c0773f8: /* original 1e2c, guest PC 0x0c0773f8 */
if(!s->budget--) { s->failed_pc=0x0c0773f8u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c0773fa;
P_0c0773fa: /* original e050, guest PC 0x0c0773fa */
if(!s->budget--) { s->failed_pc=0x0c0773fau; return 0; }
r[0]=0x00000050u;
goto P_0c0773fc;
P_0c0773fc: /* original 66d3, guest PC 0x0c0773fc */
if(!s->budget--) { s->failed_pc=0x0c0773fcu; return 0; }
r[6]=r[13];
goto P_0c0773fe;
P_0c0773fe: /* original 01fe, guest PC 0x0c0773fe */
if(!s->budget--) { s->failed_pc=0x0c0773feu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077400;
P_0c077400: /* original e04c, guest PC 0x0c077400 */
if(!s->budget--) { s->failed_pc=0x0c077400u; return 0; }
r[0]=0x0000004cu;
goto P_0c077402;
P_0c077402: /* original 2f16, guest PC 0x0c077402 */
if(!s->budget--) { s->failed_pc=0x0c077402u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c077404;
P_0c077404: /* original 53f2, guest PC 0x0c077404 */
if(!s->budget--) { s->failed_pc=0x0c077404u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c077406;
P_0c077406: /* original 2f36, guest PC 0x0c077406 */
if(!s->budget--) { s->failed_pc=0x0c077406u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077408;
P_0c077408: /* original 02fe, guest PC 0x0c077408 */
if(!s->budget--) { s->failed_pc=0x0c077408u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07740a;
P_0c07740a: /* original e04c, guest PC 0x0c07740a */
if(!s->budget--) { s->failed_pc=0x0c07740au; return 0; }
r[0]=0x0000004cu;
goto P_0c07740c;
P_0c07740c: /* original 2f26, guest PC 0x0c07740c */
if(!s->budget--) { s->failed_pc=0x0c07740cu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07740e;
P_0c07740e: /* original 03fe, guest PC 0x0c07740e */
if(!s->budget--) { s->failed_pc=0x0c07740eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077410;
P_0c077410: /* original 2f36, guest PC 0x0c077410 */
if(!s->budget--) { s->failed_pc=0x0c077410u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077412;
P_0c077412: /* original 901e, guest PC 0x0c077412 */
if(!s->budget--) { s->failed_pc=0x0c077412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c077414;
P_0c077414: /* original 02fe, guest PC 0x0c077414 */
if(!s->budget--) { s->failed_pc=0x0c077414u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077416;
P_0c077416: /* original e05c, guest PC 0x0c077416 */
if(!s->budget--) { s->failed_pc=0x0c077416u; return 0; }
r[0]=0x0000005cu;
goto P_0c077418;
P_0c077418: /* original 2f26, guest PC 0x0c077418 */
if(!s->budget--) { s->failed_pc=0x0c077418u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07741a;
P_0c07741a: /* original 03fe, guest PC 0x0c07741a */
if(!s->budget--) { s->failed_pc=0x0c07741au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07741c;
P_0c07741c: /* original 2f36, guest PC 0x0c07741c */
if(!s->budget--) { s->failed_pc=0x0c07741cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07741e;
P_0c07741e: /* original 9219, guest PC 0x0c07741e */
if(!s->budget--) { s->failed_pc=0x0c07741eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c077420;
P_0c077420: /* original 32fc, guest PC 0x0c077420 */
if(!s->budget--) { s->failed_pc=0x0c077420u; return 0; }
r[2]+=r[15];
goto P_0c077422;
P_0c077422: /* original 2f26, guest PC 0x0c077422 */
if(!s->budget--) { s->failed_pc=0x0c077422u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077424;
P_0c077424: /* original 9016, guest PC 0x0c077424 */
if(!s->budget--) { s->failed_pc=0x0c077424u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077454u,2);
goto P_0c077426;
P_0c077426: /* original 03fe, guest PC 0x0c077426 */
if(!s->budget--) { s->failed_pc=0x0c077426u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077428;
P_0c077428: /* original 2f36, guest PC 0x0c077428 */
if(!s->budget--) { s->failed_pc=0x0c077428u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07742a;
P_0c07742a: /* original 9012, guest PC 0x0c07742a */
if(!s->budget--) { s->failed_pc=0x0c07742au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077452u,2);
goto P_0c07742c;
P_0c07742c: /* original 02fe, guest PC 0x0c07742c */
if(!s->budget--) { s->failed_pc=0x0c07742cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07742e;
P_0c07742e: /* original 2f26, guest PC 0x0c07742e */
if(!s->budget--) { s->failed_pc=0x0c07742eu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077430;
P_0c077430: /* original 9011, guest PC 0x0c077430 */
if(!s->budget--) { s->failed_pc=0x0c077430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c077432;
P_0c077432: /* original 03fe, guest PC 0x0c077432 */
if(!s->budget--) { s->failed_pc=0x0c077432u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077434;
P_0c077434: /* original 2f36, guest PC 0x0c077434 */
if(!s->budget--) { s->failed_pc=0x0c077434u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077436;
P_0c077436: /* original 970e, guest PC 0x0c077436 */
if(!s->budget--) { s->failed_pc=0x0c077436u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077456u,2);
goto P_0c077438;
P_0c077438: /* original 37fc, guest PC 0x0c077438 */
if(!s->budget--) { s->failed_pc=0x0c077438u; return 0; }
r[7]+=r[15];
goto P_0c07743a;
P_0c07743a: /* original 65e3, guest PC 0x0c07743a */
if(!s->budget--) { s->failed_pc=0x0c07743au; return 0; }
r[5]=r[14];
goto P_0c07743c;
P_0c07743c: /* original b507, guest PC 0x0c07743c */
if(!s->budget--) { s->failed_pc=0x0c07743cu; return 0; }
target=0x0c077e4eu; r[16]=0x0c077440u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077440u) { target=s->pc; goto dispatch; }
goto P_0c077440;
P_0c07743e: /* original 64c3, guest PC 0x0c07743e */
if(!s->budget--) { s->failed_pc=0x0c07743eu; return 0; }
r[4]=r[12];
goto P_0c077440;
P_0c077440: /* original 2008, guest PC 0x0c077440 */
if(!s->budget--) { s->failed_pc=0x0c077440u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077442;
P_0c077442: /* original 8d02, guest PC 0x0c077442 */
if(!s->budget--) { s->failed_pc=0x0c077442u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c07744a; }
goto P_0c077446;
P_0c077444: /* original 7f28, guest PC 0x0c077444 */
if(!s->budget--) { s->failed_pc=0x0c077444u; return 0; }
r[15]+=0x00000028u;
goto P_0c077446;
P_0c077446: /* original a4fb, guest PC 0x0c077446 */
if(!s->budget--) { s->failed_pc=0x0c077446u; return 0; }
goto P_0c077e40;
P_0c077448: /* original 0009, guest PC 0x0c077448 */
if(!s->budget--) { s->failed_pc=0x0c077448u; return 0; }
goto P_0c07744a;
P_0c07744a: /* original a4f5, guest PC 0x0c07744a */
if(!s->budget--) { s->failed_pc=0x0c07744au; return 0; }
goto P_0c077e38;
P_0c07744c: /* original 0009, guest PC 0x0c07744c */
if(!s->budget--) { s->failed_pc=0x0c07744cu; return 0; }
return vf3_matrix_family(0x0c07744eu,s,ram);
P_0c07746c: /* original e050, guest PC 0x0c07746c */
if(!s->budget--) { s->failed_pc=0x0c07746cu; return 0; }
r[0]=0x00000050u;
goto P_0c07746e;
P_0c07746e: /* original 66d3, guest PC 0x0c07746e */
if(!s->budget--) { s->failed_pc=0x0c07746eu; return 0; }
r[6]=r[13];
goto P_0c077470;
P_0c077470: /* original 03fe, guest PC 0x0c077470 */
if(!s->budget--) { s->failed_pc=0x0c077470u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077472;
P_0c077472: /* original e04c, guest PC 0x0c077472 */
if(!s->budget--) { s->failed_pc=0x0c077472u; return 0; }
r[0]=0x0000004cu;
goto P_0c077474;
P_0c077474: /* original 2f36, guest PC 0x0c077474 */
if(!s->budget--) { s->failed_pc=0x0c077474u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077476;
P_0c077476: /* original 52f2, guest PC 0x0c077476 */
if(!s->budget--) { s->failed_pc=0x0c077476u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077478;
P_0c077478: /* original 2f26, guest PC 0x0c077478 */
if(!s->budget--) { s->failed_pc=0x0c077478u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07747a;
P_0c07747a: /* original 03fe, guest PC 0x0c07747a */
if(!s->budget--) { s->failed_pc=0x0c07747au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07747c;
P_0c07747c: /* original e04c, guest PC 0x0c07747c */
if(!s->budget--) { s->failed_pc=0x0c07747cu; return 0; }
r[0]=0x0000004cu;
goto P_0c07747e;
P_0c07747e: /* original 2f36, guest PC 0x0c07747e */
if(!s->budget--) { s->failed_pc=0x0c07747eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077480;
P_0c077480: /* original 02fe, guest PC 0x0c077480 */
if(!s->budget--) { s->failed_pc=0x0c077480u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077482;
P_0c077482: /* original 2f26, guest PC 0x0c077482 */
if(!s->budget--) { s->failed_pc=0x0c077482u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077484;
P_0c077484: /* original 9072, guest PC 0x0c077484 */
if(!s->budget--) { s->failed_pc=0x0c077484u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c077486;
P_0c077486: /* original 03fe, guest PC 0x0c077486 */
if(!s->budget--) { s->failed_pc=0x0c077486u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077488;
P_0c077488: /* original e05c, guest PC 0x0c077488 */
if(!s->budget--) { s->failed_pc=0x0c077488u; return 0; }
r[0]=0x0000005cu;
goto P_0c07748a;
P_0c07748a: /* original 2f36, guest PC 0x0c07748a */
if(!s->budget--) { s->failed_pc=0x0c07748au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07748c;
P_0c07748c: /* original 02fe, guest PC 0x0c07748c */
if(!s->budget--) { s->failed_pc=0x0c07748cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07748e;
P_0c07748e: /* original 2f26, guest PC 0x0c07748e */
if(!s->budget--) { s->failed_pc=0x0c07748eu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077490;
P_0c077490: /* original 936d, guest PC 0x0c077490 */
if(!s->budget--) { s->failed_pc=0x0c077490u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c077492;
P_0c077492: /* original 33fc, guest PC 0x0c077492 */
if(!s->budget--) { s->failed_pc=0x0c077492u; return 0; }
r[3]+=r[15];
goto P_0c077494;
P_0c077494: /* original 2f36, guest PC 0x0c077494 */
if(!s->budget--) { s->failed_pc=0x0c077494u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077496;
P_0c077496: /* original 906a, guest PC 0x0c077496 */
if(!s->budget--) { s->failed_pc=0x0c077496u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c077498;
P_0c077498: /* original 02fe, guest PC 0x0c077498 */
if(!s->budget--) { s->failed_pc=0x0c077498u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07749a;
P_0c07749a: /* original 2f26, guest PC 0x0c07749a */
if(!s->budget--) { s->failed_pc=0x0c07749au; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07749c;
P_0c07749c: /* original 9066, guest PC 0x0c07749c */
if(!s->budget--) { s->failed_pc=0x0c07749cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c07749e;
P_0c07749e: /* original 03fe, guest PC 0x0c07749e */
if(!s->budget--) { s->failed_pc=0x0c07749eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0774a0;
P_0c0774a0: /* original 2f36, guest PC 0x0c0774a0 */
if(!s->budget--) { s->failed_pc=0x0c0774a0u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0774a2;
P_0c0774a2: /* original 9065, guest PC 0x0c0774a2 */
if(!s->budget--) { s->failed_pc=0x0c0774a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c0774a4;
P_0c0774a4: /* original 02fe, guest PC 0x0c0774a4 */
if(!s->budget--) { s->failed_pc=0x0c0774a4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0774a6;
P_0c0774a6: /* original 2f26, guest PC 0x0c0774a6 */
if(!s->budget--) { s->failed_pc=0x0c0774a6u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c0774a8;
P_0c0774a8: /* original 9762, guest PC 0x0c0774a8 */
if(!s->budget--) { s->failed_pc=0x0c0774a8u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c0774aa;
P_0c0774aa: /* original 37fc, guest PC 0x0c0774aa */
if(!s->budget--) { s->failed_pc=0x0c0774aau; return 0; }
r[7]+=r[15];
goto P_0c0774ac;
P_0c0774ac: /* original 65e3, guest PC 0x0c0774ac */
if(!s->budget--) { s->failed_pc=0x0c0774acu; return 0; }
r[5]=r[14];
goto P_0c0774ae;
P_0c0774ae: /* original b4ce, guest PC 0x0c0774ae */
if(!s->budget--) { s->failed_pc=0x0c0774aeu; return 0; }
target=0x0c077e4eu; r[16]=0x0c0774b2u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0774b2u) { target=s->pc; goto dispatch; }
goto P_0c0774b2;
P_0c0774b0: /* original 64c3, guest PC 0x0c0774b0 */
if(!s->budget--) { s->failed_pc=0x0c0774b0u; return 0; }
r[4]=r[12];
goto P_0c0774b2;
P_0c0774b2: /* original 2008, guest PC 0x0c0774b2 */
if(!s->budget--) { s->failed_pc=0x0c0774b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0774b4;
P_0c0774b4: /* original 8d02, guest PC 0x0c0774b4 */
if(!s->budget--) { s->failed_pc=0x0c0774b4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c0774bc; }
goto P_0c0774b8;
P_0c0774b6: /* original 7f28, guest PC 0x0c0774b6 */
if(!s->budget--) { s->failed_pc=0x0c0774b6u; return 0; }
r[15]+=0x00000028u;
goto P_0c0774b8;
P_0c0774b8: /* original a4c2, guest PC 0x0c0774b8 */
if(!s->budget--) { s->failed_pc=0x0c0774b8u; return 0; }
goto P_0c077e40;
P_0c0774ba: /* original 0009, guest PC 0x0c0774ba */
if(!s->budget--) { s->failed_pc=0x0c0774bau; return 0; }
goto P_0c0774bc;
P_0c0774bc: /* original a006, guest PC 0x0c0774bc */
if(!s->budget--) { s->failed_pc=0x0c0774bcu; return 0; }
goto P_0c0774cc;
P_0c0774be: /* original 0009, guest PC 0x0c0774be */
if(!s->budget--) { s->failed_pc=0x0c0774beu; return 0; }
goto P_0c0774c0;
P_0c0774c0: /* original 9057, guest PC 0x0c0774c0 */
if(!s->budget--) { s->failed_pc=0x0c0774c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077572u,2);
goto P_0c0774c2;
P_0c0774c2: /* original d32f, guest PC 0x0c0774c2 */
if(!s->budget--) { s->failed_pc=0x0c0774c2u; return 0; }
r[3]=read(ram,0x0c077580u,4);
goto P_0c0774c4;
P_0c0774c4: /* original 02fe, guest PC 0x0c0774c4 */
if(!s->budget--) { s->failed_pc=0x0c0774c4u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0774c6;
P_0c0774c6: /* original 9054, guest PC 0x0c0774c6 */
if(!s->budget--) { s->failed_pc=0x0c0774c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077572u,2);
goto P_0c0774c8;
P_0c0774c8: /* original 223b, guest PC 0x0c0774c8 */
if(!s->budget--) { s->failed_pc=0x0c0774c8u; return 0; }
r[2]|=r[3];
goto P_0c0774ca;
P_0c0774ca: /* original 0f26, guest PC 0x0c0774ca */
if(!s->budget--) { s->failed_pc=0x0c0774cau; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0774cc;
P_0c0774cc: /* original 9052, guest PC 0x0c0774cc */
if(!s->budget--) { s->failed_pc=0x0c0774ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077574u,2);
goto P_0c0774ce;
P_0c0774ce: /* original 01ed, guest PC 0x0c0774ce */
if(!s->budget--) { s->failed_pc=0x0c0774ceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0774d0;
P_0c0774d0: /* original 611d, guest PC 0x0c0774d0 */
if(!s->budget--) { s->failed_pc=0x0c0774d0u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0774d2;
P_0c0774d2: /* original 1f15, guest PC 0x0c0774d2 */
if(!s->budget--) { s->failed_pc=0x0c0774d2u; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0774d4;
P_0c0774d4: /* original 904f, guest PC 0x0c0774d4 */
if(!s->budget--) { s->failed_pc=0x0c0774d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077576u,2);
goto P_0c0774d6;
P_0c0774d6: /* original 03ee, guest PC 0x0c0774d6 */
if(!s->budget--) { s->failed_pc=0x0c0774d6u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0774d8;
P_0c0774d8: /* original 2338, guest PC 0x0c0774d8 */
if(!s->budget--) { s->failed_pc=0x0c0774d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0774da;
P_0c0774da: /* original 8953, guest PC 0x0c0774da */
if(!s->budget--) { s->failed_pc=0x0c0774dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077584; }
goto P_0c0774dc;
P_0c0774dc: /* original 53f5, guest PC 0x0c0774dc */
if(!s->budget--) { s->failed_pc=0x0c0774dcu; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0774de;
P_0c0774de: /* original 2338, guest PC 0x0c0774de */
if(!s->budget--) { s->failed_pc=0x0c0774deu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0774e0;
P_0c0774e0: /* original 8950, guest PC 0x0c0774e0 */
if(!s->budget--) { s->failed_pc=0x0c0774e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077584; }
goto P_0c0774e2;
P_0c0774e2: /* original 52f5, guest PC 0x0c0774e2 */
if(!s->budget--) { s->failed_pc=0x0c0774e2u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0774e4;
P_0c0774e4: /* original 9348, guest PC 0x0c0774e4 */
if(!s->budget--) { s->failed_pc=0x0c0774e4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077578u,2);
goto P_0c0774e6;
P_0c0774e6: /* original 3230, guest PC 0x0c0774e6 */
if(!s->budget--) { s->failed_pc=0x0c0774e6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0774e8;
P_0c0774e8: /* original 8916, guest PC 0x0c0774e8 */
if(!s->budget--) { s->failed_pc=0x0c0774e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077518; }
goto P_0c0774ea;
P_0c0774ea: /* original 51f5, guest PC 0x0c0774ea */
if(!s->budget--) { s->failed_pc=0x0c0774eau; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c0774ec;
P_0c0774ec: /* original 9245, guest PC 0x0c0774ec */
if(!s->budget--) { s->failed_pc=0x0c0774ecu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07757au,2);
goto P_0c0774ee;
P_0c0774ee: /* original 3120, guest PC 0x0c0774ee */
if(!s->budget--) { s->failed_pc=0x0c0774eeu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c0774f0;
P_0c0774f0: /* original 8b06, guest PC 0x0c0774f0 */
if(!s->budget--) { s->failed_pc=0x0c0774f0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077500; }
goto P_0c0774f2;
P_0c0774f2: /* original 9043, guest PC 0x0c0774f2 */
if(!s->budget--) { s->failed_pc=0x0c0774f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07757cu,2);
goto P_0c0774f4;
P_0c0774f4: /* original 01ec, guest PC 0x0c0774f4 */
if(!s->budget--) { s->failed_pc=0x0c0774f4u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0774f6;
P_0c0774f6: /* original 611c, guest PC 0x0c0774f6 */
if(!s->budget--) { s->failed_pc=0x0c0774f6u; return 0; }
r[1]=r[1]&255u;
goto P_0c0774f8;
P_0c0774f8: /* original 4115, guest PC 0x0c0774f8 */
if(!s->budget--) { s->failed_pc=0x0c0774f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0774fa;
P_0c0774fa: /* original 8b0a, guest PC 0x0c0774fa */
if(!s->budget--) { s->failed_pc=0x0c0774fau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077512; }
goto P_0c0774fc;
P_0c0774fc: /* original a49c, guest PC 0x0c0774fc */
if(!s->budget--) { s->failed_pc=0x0c0774fcu; return 0; }
goto P_0c077e38;
P_0c0774fe: /* original 0009, guest PC 0x0c0774fe */
if(!s->budget--) { s->failed_pc=0x0c0774feu; return 0; }
goto P_0c077500;
P_0c077500: /* original e03e, guest PC 0x0c077500 */
if(!s->budget--) { s->failed_pc=0x0c077500u; return 0; }
r[0]=0x0000003eu;
goto P_0c077502;
P_0c077502: /* original 53f5, guest PC 0x0c077502 */
if(!s->budget--) { s->failed_pc=0x0c077502u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c077504;
P_0c077504: /* original 02ed, guest PC 0x0c077504 */
if(!s->budget--) { s->failed_pc=0x0c077504u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c077506;
P_0c077506: /* original 622d, guest PC 0x0c077506 */
if(!s->budget--) { s->failed_pc=0x0c077506u; return 0; }
r[2]=r[2]&65535u;
goto P_0c077508;
P_0c077508: /* original 7201, guest PC 0x0c077508 */
if(!s->budget--) { s->failed_pc=0x0c077508u; return 0; }
r[2]+=0x00000001u;
goto P_0c07750a;
P_0c07750a: /* original 3232, guest PC 0x0c07750a */
if(!s->budget--) { s->failed_pc=0x0c07750au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c07750c;
P_0c07750c: /* original 8901, guest PC 0x0c07750c */
if(!s->budget--) { s->failed_pc=0x0c07750cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077512; }
goto P_0c07750e;
P_0c07750e: /* original a493, guest PC 0x0c07750e */
if(!s->budget--) { s->failed_pc=0x0c07750eu; return 0; }
goto P_0c077e38;
P_0c077510: /* original 0009, guest PC 0x0c077510 */
if(!s->budget--) { s->failed_pc=0x0c077510u; return 0; }
goto P_0c077512;
P_0c077512: /* original 902f, guest PC 0x0c077512 */
if(!s->budget--) { s->failed_pc=0x0c077512u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077574u,2);
goto P_0c077514;
P_0c077514: /* original e200, guest PC 0x0c077514 */
if(!s->budget--) { s->failed_pc=0x0c077514u; return 0; }
r[2]=0x00000000u;
goto P_0c077516;
P_0c077516: /* original 0e25, guest PC 0x0c077516 */
if(!s->budget--) { s->failed_pc=0x0c077516u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c077518;
P_0c077518: /* original e050, guest PC 0x0c077518 */
if(!s->budget--) { s->failed_pc=0x0c077518u; return 0; }
r[0]=0x00000050u;
goto P_0c07751a;
P_0c07751a: /* original 66d3, guest PC 0x0c07751a */
if(!s->budget--) { s->failed_pc=0x0c07751au; return 0; }
r[6]=r[13];
goto P_0c07751c;
P_0c07751c: /* original 03fe, guest PC 0x0c07751c */
if(!s->budget--) { s->failed_pc=0x0c07751cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07751e;
P_0c07751e: /* original e04c, guest PC 0x0c07751e */
if(!s->budget--) { s->failed_pc=0x0c07751eu; return 0; }
r[0]=0x0000004cu;
goto P_0c077520;
P_0c077520: /* original 2f36, guest PC 0x0c077520 */
if(!s->budget--) { s->failed_pc=0x0c077520u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077522;
P_0c077522: /* original 52f2, guest PC 0x0c077522 */
if(!s->budget--) { s->failed_pc=0x0c077522u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077524;
P_0c077524: /* original 2f26, guest PC 0x0c077524 */
if(!s->budget--) { s->failed_pc=0x0c077524u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077526;
P_0c077526: /* original 03fe, guest PC 0x0c077526 */
if(!s->budget--) { s->failed_pc=0x0c077526u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077528;
P_0c077528: /* original e04c, guest PC 0x0c077528 */
if(!s->budget--) { s->failed_pc=0x0c077528u; return 0; }
r[0]=0x0000004cu;
goto P_0c07752a;
P_0c07752a: /* original 2f36, guest PC 0x0c07752a */
if(!s->budget--) { s->failed_pc=0x0c07752au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07752c;
P_0c07752c: /* original 02fe, guest PC 0x0c07752c */
if(!s->budget--) { s->failed_pc=0x0c07752cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07752e;
P_0c07752e: /* original 2f26, guest PC 0x0c07752e */
if(!s->budget--) { s->failed_pc=0x0c07752eu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077530;
P_0c077530: /* original 901c, guest PC 0x0c077530 */
if(!s->budget--) { s->failed_pc=0x0c077530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c077532;
P_0c077532: /* original 03fe, guest PC 0x0c077532 */
if(!s->budget--) { s->failed_pc=0x0c077532u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077534;
P_0c077534: /* original e05c, guest PC 0x0c077534 */
if(!s->budget--) { s->failed_pc=0x0c077534u; return 0; }
r[0]=0x0000005cu;
goto P_0c077536;
P_0c077536: /* original 2f36, guest PC 0x0c077536 */
if(!s->budget--) { s->failed_pc=0x0c077536u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077538;
P_0c077538: /* original 02fe, guest PC 0x0c077538 */
if(!s->budget--) { s->failed_pc=0x0c077538u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07753a;
P_0c07753a: /* original 2f26, guest PC 0x0c07753a */
if(!s->budget--) { s->failed_pc=0x0c07753au; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07753c;
P_0c07753c: /* original 9317, guest PC 0x0c07753c */
if(!s->budget--) { s->failed_pc=0x0c07753cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c07753e;
P_0c07753e: /* original 33fc, guest PC 0x0c07753e */
if(!s->budget--) { s->failed_pc=0x0c07753eu; return 0; }
r[3]+=r[15];
goto P_0c077540;
P_0c077540: /* original 2f36, guest PC 0x0c077540 */
if(!s->budget--) { s->failed_pc=0x0c077540u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077542;
P_0c077542: /* original 9014, guest PC 0x0c077542 */
if(!s->budget--) { s->failed_pc=0x0c077542u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756eu,2);
goto P_0c077544;
P_0c077544: /* original 02fe, guest PC 0x0c077544 */
if(!s->budget--) { s->failed_pc=0x0c077544u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077546;
P_0c077546: /* original 2f26, guest PC 0x0c077546 */
if(!s->budget--) { s->failed_pc=0x0c077546u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077548;
P_0c077548: /* original 9010, guest PC 0x0c077548 */
if(!s->budget--) { s->failed_pc=0x0c077548u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07756cu,2);
goto P_0c07754a;
P_0c07754a: /* original 03fe, guest PC 0x0c07754a */
if(!s->budget--) { s->failed_pc=0x0c07754au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07754c;
P_0c07754c: /* original 2f36, guest PC 0x0c07754c */
if(!s->budget--) { s->failed_pc=0x0c07754cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07754e;
P_0c07754e: /* original 900f, guest PC 0x0c07754e */
if(!s->budget--) { s->failed_pc=0x0c07754eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c077550;
P_0c077550: /* original 02fe, guest PC 0x0c077550 */
if(!s->budget--) { s->failed_pc=0x0c077550u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077552;
P_0c077552: /* original 2f26, guest PC 0x0c077552 */
if(!s->budget--) { s->failed_pc=0x0c077552u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077554;
P_0c077554: /* original 970c, guest PC 0x0c077554 */
if(!s->budget--) { s->failed_pc=0x0c077554u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077570u,2);
goto P_0c077556;
P_0c077556: /* original 37fc, guest PC 0x0c077556 */
if(!s->budget--) { s->failed_pc=0x0c077556u; return 0; }
r[7]+=r[15];
goto P_0c077558;
P_0c077558: /* original 65e3, guest PC 0x0c077558 */
if(!s->budget--) { s->failed_pc=0x0c077558u; return 0; }
r[5]=r[14];
goto P_0c07755a;
P_0c07755a: /* original b680, guest PC 0x0c07755a */
if(!s->budget--) { s->failed_pc=0x0c07755au; return 0; }
target=0x0c07825eu; r[16]=0x0c07755eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07755eu) { target=s->pc; goto dispatch; }
goto P_0c07755e;
P_0c07755c: /* original 64c3, guest PC 0x0c07755c */
if(!s->budget--) { s->failed_pc=0x0c07755cu; return 0; }
r[4]=r[12];
goto P_0c07755e;
P_0c07755e: /* original 2008, guest PC 0x0c07755e */
if(!s->budget--) { s->failed_pc=0x0c07755eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077560;
P_0c077560: /* original 8d02, guest PC 0x0c077560 */
if(!s->budget--) { s->failed_pc=0x0c077560u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077568; }
goto P_0c077564;
P_0c077562: /* original 7f28, guest PC 0x0c077562 */
if(!s->budget--) { s->failed_pc=0x0c077562u; return 0; }
r[15]+=0x00000028u;
goto P_0c077564;
P_0c077564: /* original a46c, guest PC 0x0c077564 */
if(!s->budget--) { s->failed_pc=0x0c077564u; return 0; }
goto P_0c077e40;
P_0c077566: /* original 0009, guest PC 0x0c077566 */
if(!s->budget--) { s->failed_pc=0x0c077566u; return 0; }
goto P_0c077568;
P_0c077568: /* original a455, guest PC 0x0c077568 */
if(!s->budget--) { s->failed_pc=0x0c077568u; return 0; }
goto P_0c077e16;
P_0c07756a: /* original 0009, guest PC 0x0c07756a */
if(!s->budget--) { s->failed_pc=0x0c07756au; return 0; }
return vf3_matrix_family(0x0c07756cu,s,ram);
P_0c077584: /* original 903b, guest PC 0x0c077584 */
if(!s->budget--) { s->failed_pc=0x0c077584u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0775feu,2);
goto P_0c077586;
P_0c077586: /* original e300, guest PC 0x0c077586 */
if(!s->budget--) { s->failed_pc=0x0c077586u; return 0; }
r[3]=0x00000000u;
goto P_0c077588;
P_0c077588: /* original 0e34, guest PC 0x0c077588 */
if(!s->budget--) { s->failed_pc=0x0c077588u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07758a;
P_0c07758a: /* original 9039, guest PC 0x0c07758a */
if(!s->budget--) { s->failed_pc=0x0c07758au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077600u,2);
goto P_0c07758c;
P_0c07758c: /* original d31f, guest PC 0x0c07758c */
if(!s->budget--) { s->failed_pc=0x0c07758cu; return 0; }
r[3]=read(ram,0x0c07760cu,4);
goto P_0c07758e;
P_0c07758e: /* original 02fe, guest PC 0x0c07758e */
if(!s->budget--) { s->failed_pc=0x0c07758eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077590;
P_0c077590: /* original 2238, guest PC 0x0c077590 */
if(!s->budget--) { s->failed_pc=0x0c077590u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077592;
P_0c077592: /* original 893f, guest PC 0x0c077592 */
if(!s->budget--) { s->failed_pc=0x0c077592u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077614; }
goto P_0c077594;
P_0c077594: /* original 9035, guest PC 0x0c077594 */
if(!s->budget--) { s->failed_pc=0x0c077594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077602u,2);
goto P_0c077596;
P_0c077596: /* original 02ee, guest PC 0x0c077596 */
if(!s->budget--) { s->failed_pc=0x0c077596u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c077598;
P_0c077598: /* original 2228, guest PC 0x0c077598 */
if(!s->budget--) { s->failed_pc=0x0c077598u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07759a;
P_0c07759a: /* original 8b6a, guest PC 0x0c07759a */
if(!s->budget--) { s->failed_pc=0x0c07759au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077672; }
goto P_0c07759c;
P_0c07759c: /* original e070, guest PC 0x0c07759c */
if(!s->budget--) { s->failed_pc=0x0c07759cu; return 0; }
r[0]=0x00000070u;
goto P_0c07759e;
P_0c07759e: /* original 01fe, guest PC 0x0c07759e */
if(!s->budget--) { s->failed_pc=0x0c07759eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0775a0;
P_0c0775a0: /* original 2118, guest PC 0x0c0775a0 */
if(!s->budget--) { s->failed_pc=0x0c0775a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0775a2;
P_0c0775a2: /* original 8b66, guest PC 0x0c0775a2 */
if(!s->budget--) { s->failed_pc=0x0c0775a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077672; }
goto P_0c0775a4;
P_0c0775a4: /* original 902c, guest PC 0x0c0775a4 */
if(!s->budget--) { s->failed_pc=0x0c0775a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077600u,2);
goto P_0c0775a6;
P_0c0775a6: /* original d31a, guest PC 0x0c0775a6 */
if(!s->budget--) { s->failed_pc=0x0c0775a6u; return 0; }
r[3]=read(ram,0x0c077610u,4);
goto P_0c0775a8;
P_0c0775a8: /* original 01fe, guest PC 0x0c0775a8 */
if(!s->budget--) { s->failed_pc=0x0c0775a8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0775aa;
P_0c0775aa: /* original 2138, guest PC 0x0c0775aa */
if(!s->budget--) { s->failed_pc=0x0c0775aau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0775ac;
P_0c0775ac: /* original 8901, guest PC 0x0c0775ac */
if(!s->budget--) { s->failed_pc=0x0c0775acu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0775b2; }
goto P_0c0775ae;
P_0c0775ae: /* original a443, guest PC 0x0c0775ae */
if(!s->budget--) { s->failed_pc=0x0c0775aeu; return 0; }
goto P_0c077e38;
P_0c0775b0: /* original 0009, guest PC 0x0c0775b0 */
if(!s->budget--) { s->failed_pc=0x0c0775b0u; return 0; }
goto P_0c0775b2;
P_0c0775b2: /* original 9027, guest PC 0x0c0775b2 */
if(!s->budget--) { s->failed_pc=0x0c0775b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077604u,2);
goto P_0c0775b4;
P_0c0775b4: /* original 03ec, guest PC 0x0c0775b4 */
if(!s->budget--) { s->failed_pc=0x0c0775b4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0775b6;
P_0c0775b6: /* original 633c, guest PC 0x0c0775b6 */
if(!s->budget--) { s->failed_pc=0x0c0775b6u; return 0; }
r[3]=r[3]&255u;
goto P_0c0775b8;
P_0c0775b8: /* original 1f38, guest PC 0x0c0775b8 */
if(!s->budget--) { s->failed_pc=0x0c0775b8u; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c0775ba;
P_0c0775ba: /* original 9024, guest PC 0x0c0775ba */
if(!s->budget--) { s->failed_pc=0x0c0775bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077606u,2);
goto P_0c0775bc;
P_0c0775bc: /* original 02ec, guest PC 0x0c0775bc */
if(!s->budget--) { s->failed_pc=0x0c0775bcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0775be;
P_0c0775be: /* original e06c, guest PC 0x0c0775be */
if(!s->budget--) { s->failed_pc=0x0c0775beu; return 0; }
r[0]=0x0000006cu;
goto P_0c0775c0;
P_0c0775c0: /* original 622c, guest PC 0x0c0775c0 */
if(!s->budget--) { s->failed_pc=0x0c0775c0u; return 0; }
r[2]=r[2]&255u;
goto P_0c0775c2;
P_0c0775c2: /* original 1f27, guest PC 0x0c0775c2 */
if(!s->budget--) { s->failed_pc=0x0c0775c2u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c0775c4;
P_0c0775c4: /* original 53f8, guest PC 0x0c0775c4 */
if(!s->budget--) { s->failed_pc=0x0c0775c4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c0775c6;
P_0c0775c6: /* original 3328, guest PC 0x0c0775c6 */
if(!s->budget--) { s->failed_pc=0x0c0775c6u; return 0; }
r[3]-=r[2];
goto P_0c0775c8;
P_0c0775c8: /* original 1f36, guest PC 0x0c0775c8 */
if(!s->budget--) { s->failed_pc=0x0c0775c8u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0775ca;
P_0c0775ca: /* original e30c, guest PC 0x0c0775ca */
if(!s->budget--) { s->failed_pc=0x0c0775cau; return 0; }
r[3]=0x0000000cu;
goto P_0c0775cc;
P_0c0775cc: /* original 0f36, guest PC 0x0c0775cc */
if(!s->budget--) { s->failed_pc=0x0c0775ccu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0775ce;
P_0c0775ce: /* original e04c, guest PC 0x0c0775ce */
if(!s->budget--) { s->failed_pc=0x0c0775ceu; return 0; }
r[0]=0x0000004cu;
goto P_0c0775d0;
P_0c0775d0: /* original 02ee, guest PC 0x0c0775d0 */
if(!s->budget--) { s->failed_pc=0x0c0775d0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0775d2;
P_0c0775d2: /* original 9319, guest PC 0x0c0775d2 */
if(!s->budget--) { s->failed_pc=0x0c0775d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077608u,2);
goto P_0c0775d4;
P_0c0775d4: /* original 2238, guest PC 0x0c0775d4 */
if(!s->budget--) { s->failed_pc=0x0c0775d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0775d6;
P_0c0775d6: /* original 8902, guest PC 0x0c0775d6 */
if(!s->budget--) { s->failed_pc=0x0c0775d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0775de; }
goto P_0c0775d8;
P_0c0775d8: /* original e06c, guest PC 0x0c0775d8 */
if(!s->budget--) { s->failed_pc=0x0c0775d8u; return 0; }
r[0]=0x0000006cu;
goto P_0c0775da;
P_0c0775da: /* original e20d, guest PC 0x0c0775da */
if(!s->budget--) { s->failed_pc=0x0c0775dau; return 0; }
r[2]=0x0000000du;
goto P_0c0775dc;
P_0c0775dc: /* original 0f26, guest PC 0x0c0775dc */
if(!s->budget--) { s->failed_pc=0x0c0775dcu; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0775de;
P_0c0775de: /* original e06c, guest PC 0x0c0775de */
if(!s->budget--) { s->failed_pc=0x0c0775deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0775e0;
P_0c0775e0: /* original 51f6, guest PC 0x0c0775e0 */
if(!s->budget--) { s->failed_pc=0x0c0775e0u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c0775e2;
P_0c0775e2: /* original 03fe, guest PC 0x0c0775e2 */
if(!s->budget--) { s->failed_pc=0x0c0775e2u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0775e4;
P_0c0775e4: /* original 3136, guest PC 0x0c0775e4 */
if(!s->budget--) { s->failed_pc=0x0c0775e4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c0775e6;
P_0c0775e6: /* original 8b00, guest PC 0x0c0775e6 */
if(!s->budget--) { s->failed_pc=0x0c0775e6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0775ea; }
goto P_0c0775e8;
P_0c0775e8: /* original 1f36, guest PC 0x0c0775e8 */
if(!s->budget--) { s->failed_pc=0x0c0775e8u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0775ea;
P_0c0775ea: /* original 52f8, guest PC 0x0c0775ea */
if(!s->budget--) { s->failed_pc=0x0c0775eau; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c0775ec;
P_0c0775ec: /* original 53f6, guest PC 0x0c0775ec */
if(!s->budget--) { s->failed_pc=0x0c0775ecu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c0775ee;
P_0c0775ee: /* original 3238, guest PC 0x0c0775ee */
if(!s->budget--) { s->failed_pc=0x0c0775eeu; return 0; }
r[2]-=r[3];
goto P_0c0775f0;
P_0c0775f0: /* original 6023, guest PC 0x0c0775f0 */
if(!s->budget--) { s->failed_pc=0x0c0775f0u; return 0; }
r[0]=r[2];
goto P_0c0775f2;
P_0c0775f2: /* original c93f, guest PC 0x0c0775f2 */
if(!s->budget--) { s->failed_pc=0x0c0775f2u; return 0; }
r[0]&=63u;
goto P_0c0775f4;
P_0c0775f4: /* original 6303, guest PC 0x0c0775f4 */
if(!s->budget--) { s->failed_pc=0x0c0775f4u; return 0; }
r[3]=r[0];
goto P_0c0775f6;
P_0c0775f6: /* original 1f07, guest PC 0x0c0775f6 */
if(!s->budget--) { s->failed_pc=0x0c0775f6u; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c0775f8;
P_0c0775f8: /* original 9005, guest PC 0x0c0775f8 */
if(!s->budget--) { s->failed_pc=0x0c0775f8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077606u,2);
goto P_0c0775fa;
P_0c0775fa: /* original a41d, guest PC 0x0c0775fa */
if(!s->budget--) { s->failed_pc=0x0c0775fau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077e38;
P_0c0775fc: /* original 0e34, guest PC 0x0c0775fc */
if(!s->budget--) { s->failed_pc=0x0c0775fcu; return 0; }
write(ram,r[14]+r[0],r[3],1);
return vf3_matrix_family(0x0c0775feu,s,ram);
P_0c077614: /* original 90a7, guest PC 0x0c077614 */
if(!s->budget--) { s->failed_pc=0x0c077614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c077616;
P_0c077616: /* original d357, guest PC 0x0c077616 */
if(!s->budget--) { s->failed_pc=0x0c077616u; return 0; }
r[3]=read(ram,0x0c077774u,4);
goto P_0c077618;
P_0c077618: /* original 02fe, guest PC 0x0c077618 */
if(!s->budget--) { s->failed_pc=0x0c077618u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07761a;
P_0c07761a: /* original 2238, guest PC 0x0c07761a */
if(!s->budget--) { s->failed_pc=0x0c07761au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07761c;
P_0c07761c: /* original 8b29, guest PC 0x0c07761c */
if(!s->budget--) { s->failed_pc=0x0c07761cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077672; }
goto P_0c07761e;
P_0c07761e: /* original 90a2, guest PC 0x0c07761e */
if(!s->budget--) { s->failed_pc=0x0c07761eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c077620;
P_0c077620: /* original d255, guest PC 0x0c077620 */
if(!s->budget--) { s->failed_pc=0x0c077620u; return 0; }
r[2]=read(ram,0x0c077778u,4);
goto P_0c077622;
P_0c077622: /* original 01fe, guest PC 0x0c077622 */
if(!s->budget--) { s->failed_pc=0x0c077622u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077624;
P_0c077624: /* original 2128, guest PC 0x0c077624 */
if(!s->budget--) { s->failed_pc=0x0c077624u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077626;
P_0c077626: /* original 8924, guest PC 0x0c077626 */
if(!s->budget--) { s->failed_pc=0x0c077626u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077672; }
goto P_0c077628;
P_0c077628: /* original 909e, guest PC 0x0c077628 */
if(!s->budget--) { s->failed_pc=0x0c077628u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077768u,2);
goto P_0c07762a;
P_0c07762a: /* original 03ec, guest PC 0x0c07762a */
if(!s->budget--) { s->failed_pc=0x0c07762au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07762c;
P_0c07762c: /* original 633c, guest PC 0x0c07762c */
if(!s->budget--) { s->failed_pc=0x0c07762cu; return 0; }
r[3]=r[3]&255u;
goto P_0c07762e;
P_0c07762e: /* original 1f38, guest PC 0x0c07762e */
if(!s->budget--) { s->failed_pc=0x0c07762eu; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c077630;
P_0c077630: /* original 909b, guest PC 0x0c077630 */
if(!s->budget--) { s->failed_pc=0x0c077630u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776au,2);
goto P_0c077632;
P_0c077632: /* original 02ec, guest PC 0x0c077632 */
if(!s->budget--) { s->failed_pc=0x0c077632u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077634;
P_0c077634: /* original e06c, guest PC 0x0c077634 */
if(!s->budget--) { s->failed_pc=0x0c077634u; return 0; }
r[0]=0x0000006cu;
goto P_0c077636;
P_0c077636: /* original 622c, guest PC 0x0c077636 */
if(!s->budget--) { s->failed_pc=0x0c077636u; return 0; }
r[2]=r[2]&255u;
goto P_0c077638;
P_0c077638: /* original 1f27, guest PC 0x0c077638 */
if(!s->budget--) { s->failed_pc=0x0c077638u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07763a;
P_0c07763a: /* original 53f8, guest PC 0x0c07763a */
if(!s->budget--) { s->failed_pc=0x0c07763au; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07763c;
P_0c07763c: /* original 3328, guest PC 0x0c07763c */
if(!s->budget--) { s->failed_pc=0x0c07763cu; return 0; }
r[3]-=r[2];
goto P_0c07763e;
P_0c07763e: /* original 1f36, guest PC 0x0c07763e */
if(!s->budget--) { s->failed_pc=0x0c07763eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c077640;
P_0c077640: /* original e30c, guest PC 0x0c077640 */
if(!s->budget--) { s->failed_pc=0x0c077640u; return 0; }
r[3]=0x0000000cu;
goto P_0c077642;
P_0c077642: /* original 0f36, guest PC 0x0c077642 */
if(!s->budget--) { s->failed_pc=0x0c077642u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077644;
P_0c077644: /* original e04c, guest PC 0x0c077644 */
if(!s->budget--) { s->failed_pc=0x0c077644u; return 0; }
r[0]=0x0000004cu;
goto P_0c077646;
P_0c077646: /* original 02ee, guest PC 0x0c077646 */
if(!s->budget--) { s->failed_pc=0x0c077646u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c077648;
P_0c077648: /* original 9390, guest PC 0x0c077648 */
if(!s->budget--) { s->failed_pc=0x0c077648u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776cu,2);
goto P_0c07764a;
P_0c07764a: /* original 2238, guest PC 0x0c07764a */
if(!s->budget--) { s->failed_pc=0x0c07764au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07764c;
P_0c07764c: /* original 8902, guest PC 0x0c07764c */
if(!s->budget--) { s->failed_pc=0x0c07764cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077654; }
goto P_0c07764e;
P_0c07764e: /* original e06c, guest PC 0x0c07764e */
if(!s->budget--) { s->failed_pc=0x0c07764eu; return 0; }
r[0]=0x0000006cu;
goto P_0c077650;
P_0c077650: /* original e20d, guest PC 0x0c077650 */
if(!s->budget--) { s->failed_pc=0x0c077650u; return 0; }
r[2]=0x0000000du;
goto P_0c077652;
P_0c077652: /* original 0f26, guest PC 0x0c077652 */
if(!s->budget--) { s->failed_pc=0x0c077652u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077654;
P_0c077654: /* original e06c, guest PC 0x0c077654 */
if(!s->budget--) { s->failed_pc=0x0c077654u; return 0; }
r[0]=0x0000006cu;
goto P_0c077656;
P_0c077656: /* original 51f6, guest PC 0x0c077656 */
if(!s->budget--) { s->failed_pc=0x0c077656u; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c077658;
P_0c077658: /* original 03fe, guest PC 0x0c077658 */
if(!s->budget--) { s->failed_pc=0x0c077658u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c07765a;
P_0c07765a: /* original 3136, guest PC 0x0c07765a */
if(!s->budget--) { s->failed_pc=0x0c07765au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c07765c;
P_0c07765c: /* original 8b00, guest PC 0x0c07765c */
if(!s->budget--) { s->failed_pc=0x0c07765cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077660; }
goto P_0c07765e;
P_0c07765e: /* original 1f36, guest PC 0x0c07765e */
if(!s->budget--) { s->failed_pc=0x0c07765eu; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c077660;
P_0c077660: /* original 52f8, guest PC 0x0c077660 */
if(!s->budget--) { s->failed_pc=0x0c077660u; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c077662;
P_0c077662: /* original 53f6, guest PC 0x0c077662 */
if(!s->budget--) { s->failed_pc=0x0c077662u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c077664;
P_0c077664: /* original 3238, guest PC 0x0c077664 */
if(!s->budget--) { s->failed_pc=0x0c077664u; return 0; }
r[2]-=r[3];
goto P_0c077666;
P_0c077666: /* original 6023, guest PC 0x0c077666 */
if(!s->budget--) { s->failed_pc=0x0c077666u; return 0; }
r[0]=r[2];
goto P_0c077668;
P_0c077668: /* original c93f, guest PC 0x0c077668 */
if(!s->budget--) { s->failed_pc=0x0c077668u; return 0; }
r[0]&=63u;
goto P_0c07766a;
P_0c07766a: /* original 6303, guest PC 0x0c07766a */
if(!s->budget--) { s->failed_pc=0x0c07766au; return 0; }
r[3]=r[0];
goto P_0c07766c;
P_0c07766c: /* original 1f07, guest PC 0x0c07766c */
if(!s->budget--) { s->failed_pc=0x0c07766cu; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c07766e;
P_0c07766e: /* original 907e, guest PC 0x0c07766e */
if(!s->budget--) { s->failed_pc=0x0c07766eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077670;
P_0c077670: /* original 0e34, guest PC 0x0c077670 */
if(!s->budget--) { s->failed_pc=0x0c077670u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077672;
P_0c077672: /* original 9079, guest PC 0x0c077672 */
if(!s->budget--) { s->failed_pc=0x0c077672u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077768u,2);
goto P_0c077674;
P_0c077674: /* original 61f3, guest PC 0x0c077674 */
if(!s->budget--) { s->failed_pc=0x0c077674u; return 0; }
r[1]=r[15];
goto P_0c077676;
P_0c077676: /* original 716c, guest PC 0x0c077676 */
if(!s->budget--) { s->failed_pc=0x0c077676u; return 0; }
r[1]+=0x0000006cu;
goto P_0c077678;
P_0c077678: /* original 02ec, guest PC 0x0c077678 */
if(!s->budget--) { s->failed_pc=0x0c077678u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07767a;
P_0c07767a: /* original 622c, guest PC 0x0c07767a */
if(!s->budget--) { s->failed_pc=0x0c07767au; return 0; }
r[2]=r[2]&255u;
goto P_0c07767c;
P_0c07767c: /* original 1f27, guest PC 0x0c07767c */
if(!s->budget--) { s->failed_pc=0x0c07767cu; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07767e;
P_0c07767e: /* original 9076, guest PC 0x0c07767e */
if(!s->budget--) { s->failed_pc=0x0c07767eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077680;
P_0c077680: /* original 03ec, guest PC 0x0c077680 */
if(!s->budget--) { s->failed_pc=0x0c077680u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077682;
P_0c077682: /* original 633c, guest PC 0x0c077682 */
if(!s->budget--) { s->failed_pc=0x0c077682u; return 0; }
r[3]=r[3]&255u;
goto P_0c077684;
P_0c077684: /* original 6233, guest PC 0x0c077684 */
if(!s->budget--) { s->failed_pc=0x0c077684u; return 0; }
r[2]=r[3];
goto P_0c077686;
P_0c077686: /* original 7201, guest PC 0x0c077686 */
if(!s->budget--) { s->failed_pc=0x0c077686u; return 0; }
r[2]+=0x00000001u;
goto P_0c077688;
P_0c077688: /* original 6023, guest PC 0x0c077688 */
if(!s->budget--) { s->failed_pc=0x0c077688u; return 0; }
r[0]=r[2];
goto P_0c07768a;
P_0c07768a: /* original c93f, guest PC 0x0c07768a */
if(!s->budget--) { s->failed_pc=0x0c07768au; return 0; }
r[0]&=63u;
goto P_0c07768c;
P_0c07768c: /* original 2102, guest PC 0x0c07768c */
if(!s->budget--) { s->failed_pc=0x0c07768cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07768e;
P_0c07768e: /* original 53f7, guest PC 0x0c07768e */
if(!s->budget--) { s->failed_pc=0x0c07768eu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c077690;
P_0c077690: /* original 3030, guest PC 0x0c077690 */
if(!s->budget--) { s->failed_pc=0x0c077690u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c077692;
P_0c077692: /* original 8945, guest PC 0x0c077692 */
if(!s->budget--) { s->failed_pc=0x0c077692u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077720; }
goto P_0c077694;
P_0c077694: /* original 906b, guest PC 0x0c077694 */
if(!s->budget--) { s->failed_pc=0x0c077694u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077696;
P_0c077696: /* original 01ec, guest PC 0x0c077696 */
if(!s->budget--) { s->failed_pc=0x0c077696u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077698;
P_0c077698: /* original 611c, guest PC 0x0c077698 */
if(!s->budget--) { s->failed_pc=0x0c077698u; return 0; }
r[1]=r[1]&255u;
goto P_0c07769a;
P_0c07769a: /* original 4108, guest PC 0x0c07769a */
if(!s->budget--) { s->failed_pc=0x0c07769au; return 0; }
r[1]<<=2;
goto P_0c07769c;
P_0c07769c: /* original 6313, guest PC 0x0c07769c */
if(!s->budget--) { s->failed_pc=0x0c07769cu; return 0; }
r[3]=r[1];
goto P_0c07769e;
P_0c07769e: /* original 1f15, guest PC 0x0c07769e */
if(!s->budget--) { s->failed_pc=0x0c07769eu; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c0776a0;
P_0c0776a0: /* original 9266, guest PC 0x0c0776a0 */
if(!s->budget--) { s->failed_pc=0x0c0776a0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077770u,2);
goto P_0c0776a2;
P_0c0776a2: /* original 32ec, guest PC 0x0c0776a2 */
if(!s->budget--) { s->failed_pc=0x0c0776a2u; return 0; }
r[2]+=r[14];
goto P_0c0776a4;
P_0c0776a4: /* original 323c, guest PC 0x0c0776a4 */
if(!s->budget--) { s->failed_pc=0x0c0776a4u; return 0; }
r[2]+=r[3];
goto P_0c0776a6;
P_0c0776a6: /* original 6120, guest PC 0x0c0776a6 */
if(!s->budget--) { s->failed_pc=0x0c0776a6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0776a8;
P_0c0776a8: /* original 611c, guest PC 0x0c0776a8 */
if(!s->budget--) { s->failed_pc=0x0c0776a8u; return 0; }
r[1]=r[1]&255u;
goto P_0c0776aa;
P_0c0776aa: /* original 1f11, guest PC 0x0c0776aa */
if(!s->budget--) { s->failed_pc=0x0c0776aau; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0776ac;
P_0c0776ac: /* original 61f3, guest PC 0x0c0776ac */
if(!s->budget--) { s->failed_pc=0x0c0776acu; return 0; }
r[1]=r[15];
goto P_0c0776ae;
P_0c0776ae: /* original 925f, guest PC 0x0c0776ae */
if(!s->budget--) { s->failed_pc=0x0c0776aeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077770u,2);
goto P_0c0776b0;
P_0c0776b0: /* original 7150, guest PC 0x0c0776b0 */
if(!s->budget--) { s->failed_pc=0x0c0776b0u; return 0; }
r[1]+=0x00000050u;
goto P_0c0776b2;
P_0c0776b2: /* original 53f5, guest PC 0x0c0776b2 */
if(!s->budget--) { s->failed_pc=0x0c0776b2u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0776b4;
P_0c0776b4: /* original 32ec, guest PC 0x0c0776b4 */
if(!s->budget--) { s->failed_pc=0x0c0776b4u; return 0; }
r[2]+=r[14];
goto P_0c0776b6;
P_0c0776b6: /* original 323c, guest PC 0x0c0776b6 */
if(!s->budget--) { s->failed_pc=0x0c0776b6u; return 0; }
r[2]+=r[3];
goto P_0c0776b8;
P_0c0776b8: /* original 8422, guest PC 0x0c0776b8 */
if(!s->budget--) { s->failed_pc=0x0c0776b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c0776ba;
P_0c0776ba: /* original 600c, guest PC 0x0c0776ba */
if(!s->budget--) { s->failed_pc=0x0c0776bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0776bc;
P_0c0776bc: /* original 2102, guest PC 0x0c0776bc */
if(!s->budget--) { s->failed_pc=0x0c0776bcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0776be;
P_0c0776be: /* original 9257, guest PC 0x0c0776be */
if(!s->budget--) { s->failed_pc=0x0c0776beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077770u,2);
goto P_0c0776c0;
P_0c0776c0: /* original 53f5, guest PC 0x0c0776c0 */
if(!s->budget--) { s->failed_pc=0x0c0776c0u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0776c2;
P_0c0776c2: /* original 32ec, guest PC 0x0c0776c2 */
if(!s->budget--) { s->failed_pc=0x0c0776c2u; return 0; }
r[2]+=r[14];
goto P_0c0776c4;
P_0c0776c4: /* original 323c, guest PC 0x0c0776c4 */
if(!s->budget--) { s->failed_pc=0x0c0776c4u; return 0; }
r[2]+=r[3];
goto P_0c0776c6;
P_0c0776c6: /* original 8423, guest PC 0x0c0776c6 */
if(!s->budget--) { s->failed_pc=0x0c0776c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0776c8;
P_0c0776c8: /* original 600c, guest PC 0x0c0776c8 */
if(!s->budget--) { s->failed_pc=0x0c0776c8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0776ca;
P_0c0776ca: /* original 1f0f, guest PC 0x0c0776ca */
if(!s->budget--) { s->failed_pc=0x0c0776cau; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c0776cc;
P_0c0776cc: /* original 9051, guest PC 0x0c0776cc */
if(!s->budget--) { s->failed_pc=0x0c0776ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077772u,2);
goto P_0c0776ce;
P_0c0776ce: /* original d32b, guest PC 0x0c0776ce */
if(!s->budget--) { s->failed_pc=0x0c0776ceu; return 0; }
r[3]=read(ram,0x0c07777cu,4);
goto P_0c0776d0;
P_0c0776d0: /* original 02fe, guest PC 0x0c0776d0 */
if(!s->budget--) { s->failed_pc=0x0c0776d0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0776d2;
P_0c0776d2: /* original 5121, guest PC 0x0c0776d2 */
if(!s->budget--) { s->failed_pc=0x0c0776d2u; return 0; }
r[1]=read(ram,r[2]+4,4);
goto P_0c0776d4;
P_0c0776d4: /* original 2138, guest PC 0x0c0776d4 */
if(!s->budget--) { s->failed_pc=0x0c0776d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0776d6;
P_0c0776d6: /* original 890b, guest PC 0x0c0776d6 */
if(!s->budget--) { s->failed_pc=0x0c0776d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0776f0; }
goto P_0c0776d8;
P_0c0776d8: /* original 50f1, guest PC 0x0c0776d8 */
if(!s->budget--) { s->failed_pc=0x0c0776d8u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0776da;
P_0c0776da: /* original 61f3, guest PC 0x0c0776da */
if(!s->budget--) { s->failed_pc=0x0c0776dau; return 0; }
r[1]=r[15];
goto P_0c0776dc;
P_0c0776dc: /* original 7150, guest PC 0x0c0776dc */
if(!s->budget--) { s->failed_pc=0x0c0776dcu; return 0; }
r[1]+=0x00000050u;
goto P_0c0776de;
P_0c0776de: /* original c910, guest PC 0x0c0776de */
if(!s->budget--) { s->failed_pc=0x0c0776deu; return 0; }
r[0]&=16u;
goto P_0c0776e0;
P_0c0776e0: /* original 1f01, guest PC 0x0c0776e0 */
if(!s->budget--) { s->failed_pc=0x0c0776e0u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0776e2;
P_0c0776e2: /* original e050, guest PC 0x0c0776e2 */
if(!s->budget--) { s->failed_pc=0x0c0776e2u; return 0; }
r[0]=0x00000050u;
goto P_0c0776e4;
P_0c0776e4: /* original 00fe, guest PC 0x0c0776e4 */
if(!s->budget--) { s->failed_pc=0x0c0776e4u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0776e6;
P_0c0776e6: /* original c910, guest PC 0x0c0776e6 */
if(!s->budget--) { s->failed_pc=0x0c0776e6u; return 0; }
r[0]&=16u;
goto P_0c0776e8;
P_0c0776e8: /* original 2102, guest PC 0x0c0776e8 */
if(!s->budget--) { s->failed_pc=0x0c0776e8u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0776ea;
P_0c0776ea: /* original 50ff, guest PC 0x0c0776ea */
if(!s->budget--) { s->failed_pc=0x0c0776eau; return 0; }
r[0]=read(ram,r[15]+60,4);
goto P_0c0776ec;
P_0c0776ec: /* original c910, guest PC 0x0c0776ec */
if(!s->budget--) { s->failed_pc=0x0c0776ecu; return 0; }
r[0]&=16u;
goto P_0c0776ee;
P_0c0776ee: /* original 1f0f, guest PC 0x0c0776ee */
if(!s->budget--) { s->failed_pc=0x0c0776eeu; return 0; }
write(ram,r[15]+60,r[0],4);
goto P_0c0776f0;
P_0c0776f0: /* original 53f1, guest PC 0x0c0776f0 */
if(!s->budget--) { s->failed_pc=0x0c0776f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0776f2;
P_0c0776f2: /* original 66d3, guest PC 0x0c0776f2 */
if(!s->budget--) { s->failed_pc=0x0c0776f2u; return 0; }
r[6]=r[13];
goto P_0c0776f4;
P_0c0776f4: /* original 65e3, guest PC 0x0c0776f4 */
if(!s->budget--) { s->failed_pc=0x0c0776f4u; return 0; }
r[5]=r[14];
goto P_0c0776f6;
P_0c0776f6: /* original e701, guest PC 0x0c0776f6 */
if(!s->budget--) { s->failed_pc=0x0c0776f6u; return 0; }
r[7]=0x00000001u;
goto P_0c0776f8;
P_0c0776f8: /* original 2f36, guest PC 0x0c0776f8 */
if(!s->budget--) { s->failed_pc=0x0c0776f8u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0776fa;
P_0c0776fa: /* original 903a, guest PC 0x0c0776fa */
if(!s->budget--) { s->failed_pc=0x0c0776fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077772u,2);
goto P_0c0776fc;
P_0c0776fc: /* original 02fe, guest PC 0x0c0776fc */
if(!s->budget--) { s->failed_pc=0x0c0776fcu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0776fe;
P_0c0776fe: /* original e058, guest PC 0x0c0776fe */
if(!s->budget--) { s->failed_pc=0x0c0776feu; return 0; }
r[0]=0x00000058u;
goto P_0c077700;
P_0c077700: /* original 2f26, guest PC 0x0c077700 */
if(!s->budget--) { s->failed_pc=0x0c077700u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077702;
P_0c077702: /* original 03fe, guest PC 0x0c077702 */
if(!s->budget--) { s->failed_pc=0x0c077702u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077704;
P_0c077704: /* original 2f36, guest PC 0x0c077704 */
if(!s->budget--) { s->failed_pc=0x0c077704u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077706;
P_0c077706: /* original b49d, guest PC 0x0c077706 */
if(!s->budget--) { s->failed_pc=0x0c077706u; return 0; }
target=0x0c078044u; r[16]=0x0c07770au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07770au) { target=s->pc; goto dispatch; }
goto P_0c07770a;
P_0c077708: /* original 64c3, guest PC 0x0c077708 */
if(!s->budget--) { s->failed_pc=0x0c077708u; return 0; }
r[4]=r[12];
goto P_0c07770a;
P_0c07770a: /* original 7f0c, guest PC 0x0c07770a */
if(!s->budget--) { s->failed_pc=0x0c07770au; return 0; }
r[15]+=0x0000000cu;
goto P_0c07770c;
P_0c07770c: /* original 61f3, guest PC 0x0c07770c */
if(!s->budget--) { s->failed_pc=0x0c07770cu; return 0; }
r[1]=r[15];
goto P_0c07770e;
P_0c07770e: /* original 7150, guest PC 0x0c07770e */
if(!s->budget--) { s->failed_pc=0x0c07770eu; return 0; }
r[1]+=0x00000050u;
goto P_0c077710;
P_0c077710: /* original 2102, guest PC 0x0c077710 */
if(!s->budget--) { s->failed_pc=0x0c077710u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c077712;
P_0c077712: /* original 902c, guest PC 0x0c077712 */
if(!s->budget--) { s->failed_pc=0x0c077712u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077714;
P_0c077714: /* original 03ec, guest PC 0x0c077714 */
if(!s->budget--) { s->failed_pc=0x0c077714u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077716;
P_0c077716: /* original 633c, guest PC 0x0c077716 */
if(!s->budget--) { s->failed_pc=0x0c077716u; return 0; }
r[3]=r[3]&255u;
goto P_0c077718;
P_0c077718: /* original 7301, guest PC 0x0c077718 */
if(!s->budget--) { s->failed_pc=0x0c077718u; return 0; }
r[3]+=0x00000001u;
goto P_0c07771a;
P_0c07771a: /* original 6033, guest PC 0x0c07771a */
if(!s->budget--) { s->failed_pc=0x0c07771au; return 0; }
r[0]=r[3];
goto P_0c07771c;
P_0c07771c: /* original c93f, guest PC 0x0c07771c */
if(!s->budget--) { s->failed_pc=0x0c07771cu; return 0; }
r[0]&=63u;
goto P_0c07771e;
P_0c07771e: /* original 1f07, guest PC 0x0c07771e */
if(!s->budget--) { s->failed_pc=0x0c07771eu; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c077720;
P_0c077720: /* original 9025, guest PC 0x0c077720 */
if(!s->budget--) { s->failed_pc=0x0c077720u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776eu,2);
goto P_0c077722;
P_0c077722: /* original 53f7, guest PC 0x0c077722 */
if(!s->budget--) { s->failed_pc=0x0c077722u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c077724;
P_0c077724: /* original 0e34, guest PC 0x0c077724 */
if(!s->budget--) { s->failed_pc=0x0c077724u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077726;
P_0c077726: /* original 70ff, guest PC 0x0c077726 */
if(!s->budget--) { s->failed_pc=0x0c077726u; return 0; }
r[0]+=0xffffffffu;
goto P_0c077728;
P_0c077728: /* original 02ec, guest PC 0x0c077728 */
if(!s->budget--) { s->failed_pc=0x0c077728u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07772a;
P_0c07772a: /* original e06c, guest PC 0x0c07772a */
if(!s->budget--) { s->failed_pc=0x0c07772au; return 0; }
r[0]=0x0000006cu;
goto P_0c07772c;
P_0c07772c: /* original 622c, guest PC 0x0c07772c */
if(!s->budget--) { s->failed_pc=0x0c07772cu; return 0; }
r[2]=r[2]&255u;
goto P_0c07772e;
P_0c07772e: /* original 1f28, guest PC 0x0c07772e */
if(!s->budget--) { s->failed_pc=0x0c07772eu; return 0; }
write(ram,r[15]+32,r[2],4);
goto P_0c077730;
P_0c077730: /* original 53f7, guest PC 0x0c077730 */
if(!s->budget--) { s->failed_pc=0x0c077730u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c077732;
P_0c077732: /* original 3238, guest PC 0x0c077732 */
if(!s->budget--) { s->failed_pc=0x0c077732u; return 0; }
r[2]-=r[3];
goto P_0c077734;
P_0c077734: /* original 1f26, guest PC 0x0c077734 */
if(!s->budget--) { s->failed_pc=0x0c077734u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c077736;
P_0c077736: /* original e20b, guest PC 0x0c077736 */
if(!s->budget--) { s->failed_pc=0x0c077736u; return 0; }
r[2]=0x0000000bu;
goto P_0c077738;
P_0c077738: /* original 0f26, guest PC 0x0c077738 */
if(!s->budget--) { s->failed_pc=0x0c077738u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07773a;
P_0c07773a: /* original e04c, guest PC 0x0c07773a */
if(!s->budget--) { s->failed_pc=0x0c07773au; return 0; }
r[0]=0x0000004cu;
goto P_0c07773c;
P_0c07773c: /* original 01ee, guest PC 0x0c07773c */
if(!s->budget--) { s->failed_pc=0x0c07773cu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c07773e;
P_0c07773e: /* original 9315, guest PC 0x0c07773e */
if(!s->budget--) { s->failed_pc=0x0c07773eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07776cu,2);
goto P_0c077740;
P_0c077740: /* original 2138, guest PC 0x0c077740 */
if(!s->budget--) { s->failed_pc=0x0c077740u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077742;
P_0c077742: /* original 8902, guest PC 0x0c077742 */
if(!s->budget--) { s->failed_pc=0x0c077742u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07774a; }
goto P_0c077744;
P_0c077744: /* original e06c, guest PC 0x0c077744 */
if(!s->budget--) { s->failed_pc=0x0c077744u; return 0; }
r[0]=0x0000006cu;
goto P_0c077746;
P_0c077746: /* original e20c, guest PC 0x0c077746 */
if(!s->budget--) { s->failed_pc=0x0c077746u; return 0; }
r[2]=0x0000000cu;
goto P_0c077748;
P_0c077748: /* original 0f26, guest PC 0x0c077748 */
if(!s->budget--) { s->failed_pc=0x0c077748u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07774a;
P_0c07774a: /* original e06c, guest PC 0x0c07774a */
if(!s->budget--) { s->failed_pc=0x0c07774au; return 0; }
r[0]=0x0000006cu;
goto P_0c07774c;
P_0c07774c: /* original 51f6, guest PC 0x0c07774c */
if(!s->budget--) { s->failed_pc=0x0c07774cu; return 0; }
r[1]=read(ram,r[15]+24,4);
goto P_0c07774e;
P_0c07774e: /* original 03fe, guest PC 0x0c07774e */
if(!s->budget--) { s->failed_pc=0x0c07774eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077750;
P_0c077750: /* original 3136, guest PC 0x0c077750 */
if(!s->budget--) { s->failed_pc=0x0c077750u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[3])!=0);
goto P_0c077752;
P_0c077752: /* original 8d06, guest PC 0x0c077752 */
if(!s->budget--) { s->failed_pc=0x0c077752u; return 0; }
cond=r[17]&1u;
r[1]=0x00000000u;
if(cond) { goto P_0c077762; }
goto P_0c077756;
P_0c077754: /* original e100, guest PC 0x0c077754 */
if(!s->budget--) { s->failed_pc=0x0c077754u; return 0; }
r[1]=0x00000000u;
goto P_0c077756;
P_0c077756: /* original 9006, guest PC 0x0c077756 */
if(!s->budget--) { s->failed_pc=0x0c077756u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c077758;
P_0c077758: /* original d309, guest PC 0x0c077758 */
if(!s->budget--) { s->failed_pc=0x0c077758u; return 0; }
r[3]=read(ram,0x0c077780u,4);
goto P_0c07775a;
P_0c07775a: /* original 02fe, guest PC 0x0c07775a */
if(!s->budget--) { s->failed_pc=0x0c07775au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07775c;
P_0c07775c: /* original 9003, guest PC 0x0c07775c */
if(!s->budget--) { s->failed_pc=0x0c07775cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077766u,2);
goto P_0c07775e;
P_0c07775e: /* original 2239, guest PC 0x0c07775e */
if(!s->budget--) { s->failed_pc=0x0c07775eu; return 0; }
r[2]&=r[3];
goto P_0c077760;
P_0c077760: /* original 0f26, guest PC 0x0c077760 */
if(!s->budget--) { s->failed_pc=0x0c077760u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077762;
P_0c077762: /* original a00f, guest PC 0x0c077762 */
if(!s->budget--) { s->failed_pc=0x0c077762u; return 0; }
goto P_0c077784;
P_0c077764: /* original 0009, guest PC 0x0c077764 */
if(!s->budget--) { s->failed_pc=0x0c077764u; return 0; }
return vf3_matrix_family(0x0c077766u,s,ram);
P_0c077784: /* original 62f3, guest PC 0x0c077784 */
if(!s->budget--) { s->failed_pc=0x0c077784u; return 0; }
r[2]=r[15];
goto P_0c077786;
P_0c077786: /* original e078, guest PC 0x0c077786 */
if(!s->budget--) { s->failed_pc=0x0c077786u; return 0; }
r[0]=0x00000078u;
goto P_0c077788;
P_0c077788: /* original 7250, guest PC 0x0c077788 */
if(!s->budget--) { s->failed_pc=0x0c077788u; return 0; }
r[2]+=0x00000050u;
goto P_0c07778a;
P_0c07778a: /* original 0f16, guest PC 0x0c07778a */
if(!s->budget--) { s->failed_pc=0x0c07778au; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c07778c;
P_0c07778c: /* original 6022, guest PC 0x0c07778c */
if(!s->budget--) { s->failed_pc=0x0c07778cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07778e;
P_0c07778e: /* original 6313, guest PC 0x0c07778e */
if(!s->budget--) { s->failed_pc=0x0c07778eu; return 0; }
r[3]=r[1];
goto P_0c077790;
P_0c077790: /* original c90b, guest PC 0x0c077790 */
if(!s->budget--) { s->failed_pc=0x0c077790u; return 0; }
r[0]&=11u;
goto P_0c077792;
P_0c077792: /* original 230b, guest PC 0x0c077792 */
if(!s->budget--) { s->failed_pc=0x0c077792u; return 0; }
r[3]|=r[0];
goto P_0c077794;
P_0c077794: /* original e078, guest PC 0x0c077794 */
if(!s->budget--) { s->failed_pc=0x0c077794u; return 0; }
r[0]=0x00000078u;
goto P_0c077796;
P_0c077796: /* original 0f36, guest PC 0x0c077796 */
if(!s->budget--) { s->failed_pc=0x0c077796u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077798;
P_0c077798: /* original 9278, guest PC 0x0c077798 */
if(!s->budget--) { s->failed_pc=0x0c077798u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c07779a;
P_0c07779a: /* original 32fc, guest PC 0x0c07779a */
if(!s->budget--) { s->failed_pc=0x0c07779au; return 0; }
r[2]+=r[15];
goto P_0c07779c;
P_0c07779c: /* original 6022, guest PC 0x0c07779c */
if(!s->budget--) { s->failed_pc=0x0c07779cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c07779e;
P_0c07779e: /* original c840, guest PC 0x0c07779e */
if(!s->budget--) { s->failed_pc=0x0c07779eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0777a0;
P_0c0777a0: /* original 8b08, guest PC 0x0c0777a0 */
if(!s->budget--) { s->failed_pc=0x0c0777a0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0777b4; }
goto P_0c0777a2;
P_0c0777a2: /* original 9173, guest PC 0x0c0777a2 */
if(!s->budget--) { s->failed_pc=0x0c0777a2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c0777a4;
P_0c0777a4: /* original 31fc, guest PC 0x0c0777a4 */
if(!s->budget--) { s->failed_pc=0x0c0777a4u; return 0; }
r[1]+=r[15];
goto P_0c0777a6;
P_0c0777a6: /* original 6012, guest PC 0x0c0777a6 */
if(!s->budget--) { s->failed_pc=0x0c0777a6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0777a8;
P_0c0777a8: /* original c820, guest PC 0x0c0777a8 */
if(!s->budget--) { s->failed_pc=0x0c0777a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0777aa;
P_0c0777aa: /* original 8b03, guest PC 0x0c0777aa */
if(!s->budget--) { s->failed_pc=0x0c0777aau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0777b4; }
goto P_0c0777ac;
P_0c0777ac: /* original e078, guest PC 0x0c0777ac */
if(!s->budget--) { s->failed_pc=0x0c0777acu; return 0; }
r[0]=0x00000078u;
goto P_0c0777ae;
P_0c0777ae: /* original 03fe, guest PC 0x0c0777ae */
if(!s->budget--) { s->failed_pc=0x0c0777aeu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0777b0;
P_0c0777b0: /* original 2338, guest PC 0x0c0777b0 */
if(!s->budget--) { s->failed_pc=0x0c0777b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0777b2;
P_0c0777b2: /* original 8914, guest PC 0x0c0777b2 */
if(!s->budget--) { s->failed_pc=0x0c0777b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0777de; }
goto P_0c0777b4;
P_0c0777b4: /* original 62f3, guest PC 0x0c0777b4 */
if(!s->budget--) { s->failed_pc=0x0c0777b4u; return 0; }
r[2]=r[15];
goto P_0c0777b6;
P_0c0777b6: /* original 61f3, guest PC 0x0c0777b6 */
if(!s->budget--) { s->failed_pc=0x0c0777b6u; return 0; }
r[1]=r[15];
goto P_0c0777b8;
P_0c0777b8: /* original 7250, guest PC 0x0c0777b8 */
if(!s->budget--) { s->failed_pc=0x0c0777b8u; return 0; }
r[2]+=0x00000050u;
goto P_0c0777ba;
P_0c0777ba: /* original 7178, guest PC 0x0c0777ba */
if(!s->budget--) { s->failed_pc=0x0c0777bau; return 0; }
r[1]+=0x00000078u;
goto P_0c0777bc;
P_0c0777bc: /* original 6022, guest PC 0x0c0777bc */
if(!s->budget--) { s->failed_pc=0x0c0777bcu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0777be;
P_0c0777be: /* original 6312, guest PC 0x0c0777be */
if(!s->budget--) { s->failed_pc=0x0c0777beu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c0777c0;
P_0c0777c0: /* original c904, guest PC 0x0c0777c0 */
if(!s->budget--) { s->failed_pc=0x0c0777c0u; return 0; }
r[0]&=4u;
goto P_0c0777c2;
P_0c0777c2: /* original 230b, guest PC 0x0c0777c2 */
if(!s->budget--) { s->failed_pc=0x0c0777c2u; return 0; }
r[3]|=r[0];
goto P_0c0777c4;
P_0c0777c4: /* original e078, guest PC 0x0c0777c4 */
if(!s->budget--) { s->failed_pc=0x0c0777c4u; return 0; }
r[0]=0x00000078u;
goto P_0c0777c6;
P_0c0777c6: /* original 0f36, guest PC 0x0c0777c6 */
if(!s->budget--) { s->failed_pc=0x0c0777c6u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0777c8;
P_0c0777c8: /* original e050, guest PC 0x0c0777c8 */
if(!s->budget--) { s->failed_pc=0x0c0777c8u; return 0; }
r[0]=0x00000050u;
goto P_0c0777ca;
P_0c0777ca: /* original 01fe, guest PC 0x0c0777ca */
if(!s->budget--) { s->failed_pc=0x0c0777cau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0777cc;
P_0c0777cc: /* original 6033, guest PC 0x0c0777cc */
if(!s->budget--) { s->failed_pc=0x0c0777ccu; return 0; }
r[0]=r[3];
goto P_0c0777ce;
P_0c0777ce: /* original 925e, guest PC 0x0c0777ce */
if(!s->budget--) { s->failed_pc=0x0c0777ceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788eu,2);
goto P_0c0777d0;
P_0c0777d0: /* original 2129, guest PC 0x0c0777d0 */
if(!s->budget--) { s->failed_pc=0x0c0777d0u; return 0; }
r[1]&=r[2];
goto P_0c0777d2;
P_0c0777d2: /* original 4109, guest PC 0x0c0777d2 */
if(!s->budget--) { s->failed_pc=0x0c0777d2u; return 0; }
r[1]>>=2;
goto P_0c0777d4;
P_0c0777d4: /* original 4101, guest PC 0x0c0777d4 */
if(!s->budget--) { s->failed_pc=0x0c0777d4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c0777d6;
P_0c0777d6: /* original 201b, guest PC 0x0c0777d6 */
if(!s->budget--) { s->failed_pc=0x0c0777d6u; return 0; }
r[0]|=r[1];
goto P_0c0777d8;
P_0c0777d8: /* original 61f3, guest PC 0x0c0777d8 */
if(!s->budget--) { s->failed_pc=0x0c0777d8u; return 0; }
r[1]=r[15];
goto P_0c0777da;
P_0c0777da: /* original 7178, guest PC 0x0c0777da */
if(!s->budget--) { s->failed_pc=0x0c0777dau; return 0; }
r[1]+=0x00000078u;
goto P_0c0777dc;
P_0c0777dc: /* original 2102, guest PC 0x0c0777dc */
if(!s->budget--) { s->failed_pc=0x0c0777dcu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0777de;
P_0c0777de: /* original e06c, guest PC 0x0c0777de */
if(!s->budget--) { s->failed_pc=0x0c0777deu; return 0; }
r[0]=0x0000006cu;
goto P_0c0777e0;
P_0c0777e0: /* original e300, guest PC 0x0c0777e0 */
if(!s->budget--) { s->failed_pc=0x0c0777e0u; return 0; }
r[3]=0x00000000u;
goto P_0c0777e2;
P_0c0777e2: /* original 0f36, guest PC 0x0c0777e2 */
if(!s->budget--) { s->failed_pc=0x0c0777e2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0777e4;
P_0c0777e4: /* original e078, guest PC 0x0c0777e4 */
if(!s->budget--) { s->failed_pc=0x0c0777e4u; return 0; }
r[0]=0x00000078u;
goto P_0c0777e6;
P_0c0777e6: /* original 00fe, guest PC 0x0c0777e6 */
if(!s->budget--) { s->failed_pc=0x0c0777e6u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0777e8;
P_0c0777e8: /* original 8802, guest PC 0x0c0777e8 */
if(!s->budget--) { s->failed_pc=0x0c0777e8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0777ea;
P_0c0777ea: /* original 8b06, guest PC 0x0c0777ea */
if(!s->budget--) { s->failed_pc=0x0c0777eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0777fa; }
goto P_0c0777ec;
P_0c0777ec: /* original 9050, guest PC 0x0c0777ec */
if(!s->budget--) { s->failed_pc=0x0c0777ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077890u,2);
goto P_0c0777ee;
P_0c0777ee: /* original 02ec, guest PC 0x0c0777ee */
if(!s->budget--) { s->failed_pc=0x0c0777eeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0777f0;
P_0c0777f0: /* original 2228, guest PC 0x0c0777f0 */
if(!s->budget--) { s->failed_pc=0x0c0777f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0777f2;
P_0c0777f2: /* original 8902, guest PC 0x0c0777f2 */
if(!s->budget--) { s->failed_pc=0x0c0777f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0777fa; }
goto P_0c0777f4;
P_0c0777f4: /* original e06c, guest PC 0x0c0777f4 */
if(!s->budget--) { s->failed_pc=0x0c0777f4u; return 0; }
r[0]=0x0000006cu;
goto P_0c0777f6;
P_0c0777f6: /* original e301, guest PC 0x0c0777f6 */
if(!s->budget--) { s->failed_pc=0x0c0777f6u; return 0; }
r[3]=0x00000001u;
goto P_0c0777f8;
P_0c0777f8: /* original 0f36, guest PC 0x0c0777f8 */
if(!s->budget--) { s->failed_pc=0x0c0777f8u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0777fa;
P_0c0777fa: /* original e06c, guest PC 0x0c0777fa */
if(!s->budget--) { s->failed_pc=0x0c0777fau; return 0; }
r[0]=0x0000006cu;
goto P_0c0777fc;
P_0c0777fc: /* original 02fc, guest PC 0x0c0777fc */
if(!s->budget--) { s->failed_pc=0x0c0777fcu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c0777fe;
P_0c0777fe: /* original e01b, guest PC 0x0c0777fe */
if(!s->budget--) { s->failed_pc=0x0c0777feu; return 0; }
r[0]=0x0000001bu;
goto P_0c077800;
P_0c077800: /* original 0c24, guest PC 0x0c077800 */
if(!s->budget--) { s->failed_pc=0x0c077800u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c077802;
P_0c077802: /* original 9043, guest PC 0x0c077802 */
if(!s->budget--) { s->failed_pc=0x0c077802u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c077804;
P_0c077804: /* original d325, guest PC 0x0c077804 */
if(!s->budget--) { s->failed_pc=0x0c077804u; return 0; }
r[3]=read(ram,0x0c07789cu,4);
goto P_0c077806;
P_0c077806: /* original 01fe, guest PC 0x0c077806 */
if(!s->budget--) { s->failed_pc=0x0c077806u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077808;
P_0c077808: /* original 2138, guest PC 0x0c077808 */
if(!s->budget--) { s->failed_pc=0x0c077808u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07780a;
P_0c07780a: /* original 8901, guest PC 0x0c07780a */
if(!s->budget--) { s->failed_pc=0x0c07780au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077810; }
goto P_0c07780c;
P_0c07780c: /* original a089, guest PC 0x0c07780c */
if(!s->budget--) { s->failed_pc=0x0c07780cu; return 0; }
goto P_0c077922;
P_0c07780e: /* original 0009, guest PC 0x0c07780e */
if(!s->budget--) { s->failed_pc=0x0c07780eu; return 0; }
goto P_0c077810;
P_0c077810: /* original 923c, guest PC 0x0c077810 */
if(!s->budget--) { s->failed_pc=0x0c077810u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07788cu,2);
goto P_0c077812;
P_0c077812: /* original 32fc, guest PC 0x0c077812 */
if(!s->budget--) { s->failed_pc=0x0c077812u; return 0; }
r[2]+=r[15];
goto P_0c077814;
P_0c077814: /* original 6022, guest PC 0x0c077814 */
if(!s->budget--) { s->failed_pc=0x0c077814u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c077816;
P_0c077816: /* original c860, guest PC 0x0c077816 */
if(!s->budget--) { s->failed_pc=0x0c077816u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&96u)==0)!=0);
goto P_0c077818;
P_0c077818: /* original 8901, guest PC 0x0c077818 */
if(!s->budget--) { s->failed_pc=0x0c077818u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07781e; }
goto P_0c07781a;
P_0c07781a: /* original a1a0, guest PC 0x0c07781a */
if(!s->budget--) { s->failed_pc=0x0c07781au; return 0; }
goto P_0c077b5e;
P_0c07781c: /* original 0009, guest PC 0x0c07781c */
if(!s->budget--) { s->failed_pc=0x0c07781cu; return 0; }
goto P_0c07781e;
P_0c07781e: /* original 9038, guest PC 0x0c07781e */
if(!s->budget--) { s->failed_pc=0x0c07781eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077892u,2);
goto P_0c077820;
P_0c077820: /* original d21f, guest PC 0x0c077820 */
if(!s->budget--) { s->failed_pc=0x0c077820u; return 0; }
r[2]=read(ram,0x0c0778a0u,4);
goto P_0c077822;
P_0c077822: /* original 01fe, guest PC 0x0c077822 */
if(!s->budget--) { s->failed_pc=0x0c077822u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077824;
P_0c077824: /* original 2128, guest PC 0x0c077824 */
if(!s->budget--) { s->failed_pc=0x0c077824u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077826;
P_0c077826: /* original 8901, guest PC 0x0c077826 */
if(!s->budget--) { s->failed_pc=0x0c077826u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07782c; }
goto P_0c077828;
P_0c077828: /* original a199, guest PC 0x0c077828 */
if(!s->budget--) { s->failed_pc=0x0c077828u; return 0; }
goto P_0c077b5e;
P_0c07782a: /* original 0009, guest PC 0x0c07782a */
if(!s->budget--) { s->failed_pc=0x0c07782au; return 0; }
goto P_0c07782c;
P_0c07782c: /* original 50f1, guest PC 0x0c07782c */
if(!s->budget--) { s->failed_pc=0x0c07782cu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c07782e;
P_0c07782e: /* original c820, guest PC 0x0c07782e */
if(!s->budget--) { s->failed_pc=0x0c07782eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c077830;
P_0c077830: /* original 8b01, guest PC 0x0c077830 */
if(!s->budget--) { s->failed_pc=0x0c077830u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077836; }
goto P_0c077832;
P_0c077832: /* original a194, guest PC 0x0c077832 */
if(!s->budget--) { s->failed_pc=0x0c077832u; return 0; }
goto P_0c077b5e;
P_0c077834: /* original 0009, guest PC 0x0c077834 */
if(!s->budget--) { s->failed_pc=0x0c077834u; return 0; }
goto P_0c077836;
P_0c077836: /* original 50f1, guest PC 0x0c077836 */
if(!s->budget--) { s->failed_pc=0x0c077836u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077838;
P_0c077838: /* original c80f, guest PC 0x0c077838 */
if(!s->budget--) { s->failed_pc=0x0c077838u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c07783a;
P_0c07783a: /* original 8901, guest PC 0x0c07783a */
if(!s->budget--) { s->failed_pc=0x0c07783au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077840; }
goto P_0c07783c;
P_0c07783c: /* original a18f, guest PC 0x0c07783c */
if(!s->budget--) { s->failed_pc=0x0c07783cu; return 0; }
goto P_0c077b5e;
P_0c07783e: /* original 0009, guest PC 0x0c07783e */
if(!s->budget--) { s->failed_pc=0x0c07783eu; return 0; }
goto P_0c077840;
P_0c077840: /* original 9028, guest PC 0x0c077840 */
if(!s->budget--) { s->failed_pc=0x0c077840u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077894u,2);
goto P_0c077842;
P_0c077842: /* original 61f3, guest PC 0x0c077842 */
if(!s->budget--) { s->failed_pc=0x0c077842u; return 0; }
r[1]=r[15];
goto P_0c077844;
P_0c077844: /* original 7168, guest PC 0x0c077844 */
if(!s->budget--) { s->failed_pc=0x0c077844u; return 0; }
r[1]+=0x00000068u;
goto P_0c077846;
P_0c077846: /* original 02ec, guest PC 0x0c077846 */
if(!s->budget--) { s->failed_pc=0x0c077846u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077848;
P_0c077848: /* original 622c, guest PC 0x0c077848 */
if(!s->budget--) { s->failed_pc=0x0c077848u; return 0; }
r[2]=r[2]&255u;
goto P_0c07784a;
P_0c07784a: /* original 72fe, guest PC 0x0c07784a */
if(!s->budget--) { s->failed_pc=0x0c07784au; return 0; }
r[2]+=0xfffffffeu;
goto P_0c07784c;
P_0c07784c: /* original 6023, guest PC 0x0c07784c */
if(!s->budget--) { s->failed_pc=0x0c07784cu; return 0; }
r[0]=r[2];
goto P_0c07784e;
P_0c07784e: /* original c93f, guest PC 0x0c07784e */
if(!s->budget--) { s->failed_pc=0x0c07784eu; return 0; }
r[0]&=63u;
goto P_0c077850;
P_0c077850: /* original 2102, guest PC 0x0c077850 */
if(!s->budget--) { s->failed_pc=0x0c077850u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c077852;
P_0c077852: /* original 61f3, guest PC 0x0c077852 */
if(!s->budget--) { s->failed_pc=0x0c077852u; return 0; }
r[1]=r[15];
goto P_0c077854;
P_0c077854: /* original 7160, guest PC 0x0c077854 */
if(!s->budget--) { s->failed_pc=0x0c077854u; return 0; }
r[1]+=0x00000060u;
goto P_0c077856;
P_0c077856: /* original 4008, guest PC 0x0c077856 */
if(!s->budget--) { s->failed_pc=0x0c077856u; return 0; }
r[0]<<=2;
goto P_0c077858;
P_0c077858: /* original 2102, guest PC 0x0c077858 */
if(!s->budget--) { s->failed_pc=0x0c077858u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07785a;
P_0c07785a: /* original 901c, guest PC 0x0c07785a */
if(!s->budget--) { s->failed_pc=0x0c07785au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077896u,2);
goto P_0c07785c;
P_0c07785c: /* original 03ec, guest PC 0x0c07785c */
if(!s->budget--) { s->failed_pc=0x0c07785cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07785e;
P_0c07785e: /* original e05c, guest PC 0x0c07785e */
if(!s->budget--) { s->failed_pc=0x0c07785eu; return 0; }
r[0]=0x0000005cu;
goto P_0c077860;
P_0c077860: /* original 633c, guest PC 0x0c077860 */
if(!s->budget--) { s->failed_pc=0x0c077860u; return 0; }
r[3]=r[3]&255u;
goto P_0c077862;
P_0c077862: /* original 0f36, guest PC 0x0c077862 */
if(!s->budget--) { s->failed_pc=0x0c077862u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077864;
P_0c077864: /* original e068, guest PC 0x0c077864 */
if(!s->budget--) { s->failed_pc=0x0c077864u; return 0; }
r[0]=0x00000068u;
goto P_0c077866;
P_0c077866: /* original 02fe, guest PC 0x0c077866 */
if(!s->budget--) { s->failed_pc=0x0c077866u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077868;
P_0c077868: /* original 3230, guest PC 0x0c077868 */
if(!s->budget--) { s->failed_pc=0x0c077868u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07786a;
P_0c07786a: /* original 8b01, guest PC 0x0c07786a */
if(!s->budget--) { s->failed_pc=0x0c07786au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077870; }
goto P_0c07786c;
P_0c07786c: /* original a177, guest PC 0x0c07786c */
if(!s->budget--) { s->failed_pc=0x0c07786cu; return 0; }
goto P_0c077b5e;
P_0c07786e: /* original 0009, guest PC 0x0c07786e */
if(!s->budget--) { s->failed_pc=0x0c07786eu; return 0; }
goto P_0c077870;
P_0c077870: /* original e06c, guest PC 0x0c077870 */
if(!s->budget--) { s->failed_pc=0x0c077870u; return 0; }
r[0]=0x0000006cu;
goto P_0c077872;
P_0c077872: /* original e30c, guest PC 0x0c077872 */
if(!s->budget--) { s->failed_pc=0x0c077872u; return 0; }
r[3]=0x0000000cu;
goto P_0c077874;
P_0c077874: /* original 0f36, guest PC 0x0c077874 */
if(!s->budget--) { s->failed_pc=0x0c077874u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077876;
P_0c077876: /* original e04c, guest PC 0x0c077876 */
if(!s->budget--) { s->failed_pc=0x0c077876u; return 0; }
r[0]=0x0000004cu;
goto P_0c077878;
P_0c077878: /* original 02ee, guest PC 0x0c077878 */
if(!s->budget--) { s->failed_pc=0x0c077878u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07787a;
P_0c07787a: /* original 930d, guest PC 0x0c07787a */
if(!s->budget--) { s->failed_pc=0x0c07787au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077898u,2);
goto P_0c07787c;
P_0c07787c: /* original 2238, guest PC 0x0c07787c */
if(!s->budget--) { s->failed_pc=0x0c07787cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07787e;
P_0c07787e: /* original 8d03, guest PC 0x0c07787e */
if(!s->budget--) { s->failed_pc=0x0c07787eu; return 0; }
cond=r[17]&1u;
r[3]=0x00000000u;
if(cond) { goto P_0c077888; }
goto P_0c077882;
P_0c077880: /* original e300, guest PC 0x0c077880 */
if(!s->budget--) { s->failed_pc=0x0c077880u; return 0; }
r[3]=0x00000000u;
goto P_0c077882;
P_0c077882: /* original e06c, guest PC 0x0c077882 */
if(!s->budget--) { s->failed_pc=0x0c077882u; return 0; }
r[0]=0x0000006cu;
goto P_0c077884;
P_0c077884: /* original e206, guest PC 0x0c077884 */
if(!s->budget--) { s->failed_pc=0x0c077884u; return 0; }
r[2]=0x00000006u;
goto P_0c077886;
P_0c077886: /* original 0f26, guest PC 0x0c077886 */
if(!s->budget--) { s->failed_pc=0x0c077886u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077888;
P_0c077888: /* original a02a, guest PC 0x0c077888 */
if(!s->budget--) { s->failed_pc=0x0c077888u; return 0; }
goto P_0c0778e0;
P_0c07788a: /* original 0009, guest PC 0x0c07788a */
if(!s->budget--) { s->failed_pc=0x0c07788au; return 0; }
return vf3_matrix_family(0x0c07788cu,s,ram);
P_0c0778a4: /* original e060, guest PC 0x0c0778a4 */
if(!s->budget--) { s->failed_pc=0x0c0778a4u; return 0; }
r[0]=0x00000060u;
goto P_0c0778a6;
P_0c0778a6: /* original 03fe, guest PC 0x0c0778a6 */
if(!s->budget--) { s->failed_pc=0x0c0778a6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0778a8;
P_0c0778a8: /* original 906b, guest PC 0x0c0778a8 */
if(!s->budget--) { s->failed_pc=0x0c0778a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077982u,2);
goto P_0c0778aa;
P_0c0778aa: /* original 30ec, guest PC 0x0c0778aa */
if(!s->budget--) { s->failed_pc=0x0c0778aau; return 0; }
r[0]+=r[14];
goto P_0c0778ac;
P_0c0778ac: /* original 003c, guest PC 0x0c0778ac */
if(!s->budget--) { s->failed_pc=0x0c0778acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c0778ae;
P_0c0778ae: /* original 600c, guest PC 0x0c0778ae */
if(!s->budget--) { s->failed_pc=0x0c0778aeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0778b0;
P_0c0778b0: /* original c810, guest PC 0x0c0778b0 */
if(!s->budget--) { s->failed_pc=0x0c0778b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0778b2;
P_0c0778b2: /* original 8b1d, guest PC 0x0c0778b2 */
if(!s->budget--) { s->failed_pc=0x0c0778b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0778f0; }
goto P_0c0778b4;
P_0c0778b4: /* original e05c, guest PC 0x0c0778b4 */
if(!s->budget--) { s->failed_pc=0x0c0778b4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0778b6;
P_0c0778b6: /* original 03fe, guest PC 0x0c0778b6 */
if(!s->budget--) { s->failed_pc=0x0c0778b6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c0778b8;
P_0c0778b8: /* original e068, guest PC 0x0c0778b8 */
if(!s->budget--) { s->failed_pc=0x0c0778b8u; return 0; }
r[0]=0x00000068u;
goto P_0c0778ba;
P_0c0778ba: /* original 02fe, guest PC 0x0c0778ba */
if(!s->budget--) { s->failed_pc=0x0c0778bau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0778bc;
P_0c0778bc: /* original 3230, guest PC 0x0c0778bc */
if(!s->budget--) { s->failed_pc=0x0c0778bcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0778be;
P_0c0778be: /* original 8b01, guest PC 0x0c0778be */
if(!s->budget--) { s->failed_pc=0x0c0778beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0778c4; }
goto P_0c0778c0;
P_0c0778c0: /* original a14d, guest PC 0x0c0778c0 */
if(!s->budget--) { s->failed_pc=0x0c0778c0u; return 0; }
goto P_0c077b5e;
P_0c0778c2: /* original 0009, guest PC 0x0c0778c2 */
if(!s->budget--) { s->failed_pc=0x0c0778c2u; return 0; }
goto P_0c0778c4;
P_0c0778c4: /* original e068, guest PC 0x0c0778c4 */
if(!s->budget--) { s->failed_pc=0x0c0778c4u; return 0; }
r[0]=0x00000068u;
goto P_0c0778c6;
P_0c0778c6: /* original 62f3, guest PC 0x0c0778c6 */
if(!s->budget--) { s->failed_pc=0x0c0778c6u; return 0; }
r[2]=r[15];
goto P_0c0778c8;
P_0c0778c8: /* original 01fe, guest PC 0x0c0778c8 */
if(!s->budget--) { s->failed_pc=0x0c0778c8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c0778ca;
P_0c0778ca: /* original 7268, guest PC 0x0c0778ca */
if(!s->budget--) { s->failed_pc=0x0c0778cau; return 0; }
r[2]+=0x00000068u;
goto P_0c0778cc;
P_0c0778cc: /* original 71ff, guest PC 0x0c0778cc */
if(!s->budget--) { s->failed_pc=0x0c0778ccu; return 0; }
r[1]+=0xffffffffu;
goto P_0c0778ce;
P_0c0778ce: /* original 6013, guest PC 0x0c0778ce */
if(!s->budget--) { s->failed_pc=0x0c0778ceu; return 0; }
r[0]=r[1];
goto P_0c0778d0;
P_0c0778d0: /* original c93f, guest PC 0x0c0778d0 */
if(!s->budget--) { s->failed_pc=0x0c0778d0u; return 0; }
r[0]&=63u;
goto P_0c0778d2;
P_0c0778d2: /* original 61f3, guest PC 0x0c0778d2 */
if(!s->budget--) { s->failed_pc=0x0c0778d2u; return 0; }
r[1]=r[15];
goto P_0c0778d4;
P_0c0778d4: /* original 2202, guest PC 0x0c0778d4 */
if(!s->budget--) { s->failed_pc=0x0c0778d4u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c0778d6;
P_0c0778d6: /* original 7160, guest PC 0x0c0778d6 */
if(!s->budget--) { s->failed_pc=0x0c0778d6u; return 0; }
r[1]+=0x00000060u;
goto P_0c0778d8;
P_0c0778d8: /* original 4008, guest PC 0x0c0778d8 */
if(!s->budget--) { s->failed_pc=0x0c0778d8u; return 0; }
r[0]<<=2;
goto P_0c0778da;
P_0c0778da: /* original 2102, guest PC 0x0c0778da */
if(!s->budget--) { s->failed_pc=0x0c0778dau; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0778dc;
P_0c0778dc: /* original 53f3, guest PC 0x0c0778dc */
if(!s->budget--) { s->failed_pc=0x0c0778dcu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0778de;
P_0c0778de: /* original 7301, guest PC 0x0c0778de */
if(!s->budget--) { s->failed_pc=0x0c0778deu; return 0; }
r[3]+=0x00000001u;
goto P_0c0778e0;
P_0c0778e0: /* original e06c, guest PC 0x0c0778e0 */
if(!s->budget--) { s->failed_pc=0x0c0778e0u; return 0; }
r[0]=0x0000006cu;
goto P_0c0778e2;
P_0c0778e2: /* original 6133, guest PC 0x0c0778e2 */
if(!s->budget--) { s->failed_pc=0x0c0778e2u; return 0; }
r[1]=r[3];
goto P_0c0778e4;
P_0c0778e4: /* original 1f33, guest PC 0x0c0778e4 */
if(!s->budget--) { s->failed_pc=0x0c0778e4u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0778e6;
P_0c0778e6: /* original 02fe, guest PC 0x0c0778e6 */
if(!s->budget--) { s->failed_pc=0x0c0778e6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0778e8;
P_0c0778e8: /* original 3122, guest PC 0x0c0778e8 */
if(!s->budget--) { s->failed_pc=0x0c0778e8u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>=r[2])!=0);
goto P_0c0778ea;
P_0c0778ea: /* original 8bdb, guest PC 0x0c0778ea */
if(!s->budget--) { s->failed_pc=0x0c0778eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0778a4; }
goto P_0c0778ec;
P_0c0778ec: /* original a137, guest PC 0x0c0778ec */
if(!s->budget--) { s->failed_pc=0x0c0778ecu; return 0; }
goto P_0c077b5e;
P_0c0778ee: /* original 0009, guest PC 0x0c0778ee */
if(!s->budget--) { s->failed_pc=0x0c0778eeu; return 0; }
goto P_0c0778f0;
P_0c0778f0: /* original d326, guest PC 0x0c0778f0 */
if(!s->budget--) { s->failed_pc=0x0c0778f0u; return 0; }
r[3]=read(ram,0x0c07798cu,4);
goto P_0c0778f2;
P_0c0778f2: /* original e044, guest PC 0x0c0778f2 */
if(!s->budget--) { s->failed_pc=0x0c0778f2u; return 0; }
r[0]=0x00000044u;
goto P_0c0778f4;
P_0c0778f4: /* original 1f3e, guest PC 0x0c0778f4 */
if(!s->budget--) { s->failed_pc=0x0c0778f4u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0778f6;
P_0c0778f6: /* original 02fe, guest PC 0x0c0778f6 */
if(!s->budget--) { s->failed_pc=0x0c0778f6u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0778f8;
P_0c0778f8: /* original 53f1, guest PC 0x0c0778f8 */
if(!s->budget--) { s->failed_pc=0x0c0778f8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0778fa;
P_0c0778fa: /* original 2238, guest PC 0x0c0778fa */
if(!s->budget--) { s->failed_pc=0x0c0778fau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0778fc;
P_0c0778fc: /* original 8903, guest PC 0x0c0778fc */
if(!s->budget--) { s->failed_pc=0x0c0778fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077906; }
goto P_0c0778fe;
P_0c0778fe: /* original 51fe, guest PC 0x0c0778fe */
if(!s->budget--) { s->failed_pc=0x0c0778feu; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077900;
P_0c077900: /* original d223, guest PC 0x0c077900 */
if(!s->budget--) { s->failed_pc=0x0c077900u; return 0; }
r[2]=read(ram,0x0c077990u,4);
goto P_0c077902;
P_0c077902: /* original 212b, guest PC 0x0c077902 */
if(!s->budget--) { s->failed_pc=0x0c077902u; return 0; }
r[1]|=r[2];
goto P_0c077904;
P_0c077904: /* original 1f1e, guest PC 0x0c077904 */
if(!s->budget--) { s->failed_pc=0x0c077904u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077906;
P_0c077906: /* original e040, guest PC 0x0c077906 */
if(!s->budget--) { s->failed_pc=0x0c077906u; return 0; }
r[0]=0x00000040u;
goto P_0c077908;
P_0c077908: /* original 53f1, guest PC 0x0c077908 */
if(!s->budget--) { s->failed_pc=0x0c077908u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07790a;
P_0c07790a: /* original 02fe, guest PC 0x0c07790a */
if(!s->budget--) { s->failed_pc=0x0c07790au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07790c;
P_0c07790c: /* original 2238, guest PC 0x0c07790c */
if(!s->budget--) { s->failed_pc=0x0c07790cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07790e;
P_0c07790e: /* original 8903, guest PC 0x0c07790e */
if(!s->budget--) { s->failed_pc=0x0c07790eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077918; }
goto P_0c077910;
P_0c077910: /* original 51fe, guest PC 0x0c077910 */
if(!s->budget--) { s->failed_pc=0x0c077910u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077912;
P_0c077912: /* original d220, guest PC 0x0c077912 */
if(!s->budget--) { s->failed_pc=0x0c077912u; return 0; }
r[2]=read(ram,0x0c077994u,4);
goto P_0c077914;
P_0c077914: /* original 212b, guest PC 0x0c077914 */
if(!s->budget--) { s->failed_pc=0x0c077914u; return 0; }
r[1]|=r[2];
goto P_0c077916;
P_0c077916: /* original 1f1e, guest PC 0x0c077916 */
if(!s->budget--) { s->failed_pc=0x0c077916u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077918;
P_0c077918: /* original 53fe, guest PC 0x0c077918 */
if(!s->budget--) { s->failed_pc=0x0c077918u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c07791a;
P_0c07791a: /* original e200, guest PC 0x0c07791a */
if(!s->budget--) { s->failed_pc=0x0c07791au; return 0; }
r[2]=0x00000000u;
goto P_0c07791c;
P_0c07791c: /* original 1f3a, guest PC 0x0c07791c */
if(!s->budget--) { s->failed_pc=0x0c07791cu; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c07791e;
P_0c07791e: /* original a070, guest PC 0x0c07791e */
if(!s->budget--) { s->failed_pc=0x0c07791eu; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c077a02;
P_0c077920: /* original 1f29, guest PC 0x0c077920 */
if(!s->budget--) { s->failed_pc=0x0c077920u; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c077922;
P_0c077922: /* original e100, guest PC 0x0c077922 */
if(!s->budget--) { s->failed_pc=0x0c077922u; return 0; }
r[1]=0x00000000u;
goto P_0c077924;
P_0c077924: /* original 1f1e, guest PC 0x0c077924 */
if(!s->budget--) { s->failed_pc=0x0c077924u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077926;
P_0c077926: /* original 902d, guest PC 0x0c077926 */
if(!s->budget--) { s->failed_pc=0x0c077926u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077984u,2);
goto P_0c077928;
P_0c077928: /* original 02ee, guest PC 0x0c077928 */
if(!s->budget--) { s->failed_pc=0x0c077928u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c07792a;
P_0c07792a: /* original 2228, guest PC 0x0c07792a */
if(!s->budget--) { s->failed_pc=0x0c07792au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c07792c;
P_0c07792c: /* original 8934, guest PC 0x0c07792c */
if(!s->budget--) { s->failed_pc=0x0c07792cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077998; }
goto P_0c07792e;
P_0c07792e: /* original e050, guest PC 0x0c07792e */
if(!s->budget--) { s->failed_pc=0x0c07792eu; return 0; }
r[0]=0x00000050u;
goto P_0c077930;
P_0c077930: /* original 66d3, guest PC 0x0c077930 */
if(!s->budget--) { s->failed_pc=0x0c077930u; return 0; }
r[6]=r[13];
goto P_0c077932;
P_0c077932: /* original 02fe, guest PC 0x0c077932 */
if(!s->budget--) { s->failed_pc=0x0c077932u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077934;
P_0c077934: /* original e04c, guest PC 0x0c077934 */
if(!s->budget--) { s->failed_pc=0x0c077934u; return 0; }
r[0]=0x0000004cu;
goto P_0c077936;
P_0c077936: /* original 2f26, guest PC 0x0c077936 */
if(!s->budget--) { s->failed_pc=0x0c077936u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077938;
P_0c077938: /* original 51f2, guest PC 0x0c077938 */
if(!s->budget--) { s->failed_pc=0x0c077938u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07793a;
P_0c07793a: /* original 2f16, guest PC 0x0c07793a */
if(!s->budget--) { s->failed_pc=0x0c07793au; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c07793c;
P_0c07793c: /* original 02fe, guest PC 0x0c07793c */
if(!s->budget--) { s->failed_pc=0x0c07793cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07793e;
P_0c07793e: /* original e04c, guest PC 0x0c07793e */
if(!s->budget--) { s->failed_pc=0x0c07793eu; return 0; }
r[0]=0x0000004cu;
goto P_0c077940;
P_0c077940: /* original 2f26, guest PC 0x0c077940 */
if(!s->budget--) { s->failed_pc=0x0c077940u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077942;
P_0c077942: /* original 01fe, guest PC 0x0c077942 */
if(!s->budget--) { s->failed_pc=0x0c077942u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077944;
P_0c077944: /* original 2f16, guest PC 0x0c077944 */
if(!s->budget--) { s->failed_pc=0x0c077944u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c077946;
P_0c077946: /* original 901e, guest PC 0x0c077946 */
if(!s->budget--) { s->failed_pc=0x0c077946u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077986u,2);
goto P_0c077948;
P_0c077948: /* original 02fe, guest PC 0x0c077948 */
if(!s->budget--) { s->failed_pc=0x0c077948u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07794a;
P_0c07794a: /* original e05c, guest PC 0x0c07794a */
if(!s->budget--) { s->failed_pc=0x0c07794au; return 0; }
r[0]=0x0000005cu;
goto P_0c07794c;
P_0c07794c: /* original 2f26, guest PC 0x0c07794c */
if(!s->budget--) { s->failed_pc=0x0c07794cu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c07794e;
P_0c07794e: /* original 01fe, guest PC 0x0c07794e */
if(!s->budget--) { s->failed_pc=0x0c07794eu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077950;
P_0c077950: /* original 2f16, guest PC 0x0c077950 */
if(!s->budget--) { s->failed_pc=0x0c077950u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c077952;
P_0c077952: /* original 9219, guest PC 0x0c077952 */
if(!s->budget--) { s->failed_pc=0x0c077952u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077988u,2);
goto P_0c077954;
P_0c077954: /* original 32fc, guest PC 0x0c077954 */
if(!s->budget--) { s->failed_pc=0x0c077954u; return 0; }
r[2]+=r[15];
goto P_0c077956;
P_0c077956: /* original 2f26, guest PC 0x0c077956 */
if(!s->budget--) { s->failed_pc=0x0c077956u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077958;
P_0c077958: /* original 9016, guest PC 0x0c077958 */
if(!s->budget--) { s->failed_pc=0x0c077958u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077988u,2);
goto P_0c07795a;
P_0c07795a: /* original 01fe, guest PC 0x0c07795a */
if(!s->budget--) { s->failed_pc=0x0c07795au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c07795c;
P_0c07795c: /* original 2f16, guest PC 0x0c07795c */
if(!s->budget--) { s->failed_pc=0x0c07795cu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c07795e;
P_0c07795e: /* original 9012, guest PC 0x0c07795e */
if(!s->budget--) { s->failed_pc=0x0c07795eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077986u,2);
goto P_0c077960;
P_0c077960: /* original 02fe, guest PC 0x0c077960 */
if(!s->budget--) { s->failed_pc=0x0c077960u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077962;
P_0c077962: /* original 2f26, guest PC 0x0c077962 */
if(!s->budget--) { s->failed_pc=0x0c077962u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077964;
P_0c077964: /* original 9011, guest PC 0x0c077964 */
if(!s->budget--) { s->failed_pc=0x0c077964u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07798au,2);
goto P_0c077966;
P_0c077966: /* original 01fe, guest PC 0x0c077966 */
if(!s->budget--) { s->failed_pc=0x0c077966u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077968;
P_0c077968: /* original 2f16, guest PC 0x0c077968 */
if(!s->budget--) { s->failed_pc=0x0c077968u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c07796a;
P_0c07796a: /* original 970e, guest PC 0x0c07796a */
if(!s->budget--) { s->failed_pc=0x0c07796au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07798au,2);
goto P_0c07796c;
P_0c07796c: /* original 37fc, guest PC 0x0c07796c */
if(!s->budget--) { s->failed_pc=0x0c07796cu; return 0; }
r[7]+=r[15];
goto P_0c07796e;
P_0c07796e: /* original 65e3, guest PC 0x0c07796e */
if(!s->budget--) { s->failed_pc=0x0c07796eu; return 0; }
r[5]=r[14];
goto P_0c077970;
P_0c077970: /* original b493, guest PC 0x0c077970 */
if(!s->budget--) { s->failed_pc=0x0c077970u; return 0; }
target=0x0c07829au; r[16]=0x0c077974u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077974u) { target=s->pc; goto dispatch; }
goto P_0c077974;
P_0c077972: /* original 64c3, guest PC 0x0c077972 */
if(!s->budget--) { s->failed_pc=0x0c077972u; return 0; }
r[4]=r[12];
goto P_0c077974;
P_0c077974: /* original 2008, guest PC 0x0c077974 */
if(!s->budget--) { s->failed_pc=0x0c077974u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077976;
P_0c077976: /* original 8d02, guest PC 0x0c077976 */
if(!s->budget--) { s->failed_pc=0x0c077976u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c07797e; }
goto P_0c07797a;
P_0c077978: /* original 7f28, guest PC 0x0c077978 */
if(!s->budget--) { s->failed_pc=0x0c077978u; return 0; }
r[15]+=0x00000028u;
goto P_0c07797a;
P_0c07797a: /* original a261, guest PC 0x0c07797a */
if(!s->budget--) { s->failed_pc=0x0c07797au; return 0; }
goto P_0c077e40;
P_0c07797c: /* original 0009, guest PC 0x0c07797c */
if(!s->budget--) { s->failed_pc=0x0c07797cu; return 0; }
goto P_0c07797e;
P_0c07797e: /* original a193, guest PC 0x0c07797e */
if(!s->budget--) { s->failed_pc=0x0c07797eu; return 0; }
goto P_0c077ca8;
P_0c077980: /* original 0009, guest PC 0x0c077980 */
if(!s->budget--) { s->failed_pc=0x0c077980u; return 0; }
return vf3_matrix_family(0x0c077982u,s,ram);
P_0c077998: /* original 908a, guest PC 0x0c077998 */
if(!s->budget--) { s->failed_pc=0x0c077998u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab0u,2);
goto P_0c07799a;
P_0c07799a: /* original d349, guest PC 0x0c07799a */
if(!s->budget--) { s->failed_pc=0x0c07799au; return 0; }
r[3]=read(ram,0x0c077ac0u,4);
goto P_0c07799c;
P_0c07799c: /* original 02fe, guest PC 0x0c07799c */
if(!s->budget--) { s->failed_pc=0x0c07799cu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c07799e;
P_0c07799e: /* original 2238, guest PC 0x0c07799e */
if(!s->budget--) { s->failed_pc=0x0c07799eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0779a0;
P_0c0779a0: /* original 8901, guest PC 0x0c0779a0 */
if(!s->budget--) { s->failed_pc=0x0c0779a0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0779a6; }
goto P_0c0779a2;
P_0c0779a2: /* original a249, guest PC 0x0c0779a2 */
if(!s->budget--) { s->failed_pc=0x0c0779a2u; return 0; }
goto P_0c077e38;
P_0c0779a4: /* original 0009, guest PC 0x0c0779a4 */
if(!s->budget--) { s->failed_pc=0x0c0779a4u; return 0; }
goto P_0c0779a6;
P_0c0779a6: /* original 52ee, guest PC 0x0c0779a6 */
if(!s->budget--) { s->failed_pc=0x0c0779a6u; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0779a8;
P_0c0779a8: /* original d346, guest PC 0x0c0779a8 */
if(!s->budget--) { s->failed_pc=0x0c0779a8u; return 0; }
r[3]=read(ram,0x0c077ac4u,4);
goto P_0c0779aa;
P_0c0779aa: /* original 2239, guest PC 0x0c0779aa */
if(!s->budget--) { s->failed_pc=0x0c0779aau; return 0; }
r[2]&=r[3];
goto P_0c0779ac;
P_0c0779ac: /* original 1f2a, guest PC 0x0c0779ac */
if(!s->budget--) { s->failed_pc=0x0c0779acu; return 0; }
write(ram,r[15]+40,r[2],4);
goto P_0c0779ae;
P_0c0779ae: /* original 9080, guest PC 0x0c0779ae */
if(!s->budget--) { s->failed_pc=0x0c0779aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab2u,2);
goto P_0c0779b0;
P_0c0779b0: /* original 01ec, guest PC 0x0c0779b0 */
if(!s->budget--) { s->failed_pc=0x0c0779b0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0779b2;
P_0c0779b2: /* original e062, guest PC 0x0c0779b2 */
if(!s->budget--) { s->failed_pc=0x0c0779b2u; return 0; }
r[0]=0x00000062u;
goto P_0c0779b4;
P_0c0779b4: /* original 611c, guest PC 0x0c0779b4 */
if(!s->budget--) { s->failed_pc=0x0c0779b4u; return 0; }
r[1]=r[1]&255u;
goto P_0c0779b6;
P_0c0779b6: /* original 1f19, guest PC 0x0c0779b6 */
if(!s->budget--) { s->failed_pc=0x0c0779b6u; return 0; }
write(ram,r[15]+36,r[1],4);
goto P_0c0779b8;
P_0c0779b8: /* original 00ec, guest PC 0x0c0779b8 */
if(!s->budget--) { s->failed_pc=0x0c0779b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0779ba;
P_0c0779ba: /* original 600c, guest PC 0x0c0779ba */
if(!s->budget--) { s->failed_pc=0x0c0779bau; return 0; }
r[0]=r[0]&255u;
goto P_0c0779bc;
P_0c0779bc: /* original 8801, guest PC 0x0c0779bc */
if(!s->budget--) { s->failed_pc=0x0c0779bcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0779be;
P_0c0779be: /* original 8b01, guest PC 0x0c0779be */
if(!s->budget--) { s->failed_pc=0x0c0779beu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0779c4; }
goto P_0c0779c0;
P_0c0779c0: /* original a086, guest PC 0x0c0779c0 */
if(!s->budget--) { s->failed_pc=0x0c0779c0u; return 0; }
goto P_0c077ad0;
P_0c0779c2: /* original 0009, guest PC 0x0c0779c2 */
if(!s->budget--) { s->failed_pc=0x0c0779c2u; return 0; }
goto P_0c0779c4;
P_0c0779c4: /* original 50f9, guest PC 0x0c0779c4 */
if(!s->budget--) { s->failed_pc=0x0c0779c4u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0779c6;
P_0c0779c6: /* original c840, guest PC 0x0c0779c6 */
if(!s->budget--) { s->failed_pc=0x0c0779c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0779c8;
P_0c0779c8: /* original 8901, guest PC 0x0c0779c8 */
if(!s->budget--) { s->failed_pc=0x0c0779c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0779ce; }
goto P_0c0779ca;
P_0c0779ca: /* original a0bd, guest PC 0x0c0779ca */
if(!s->budget--) { s->failed_pc=0x0c0779cau; return 0; }
goto P_0c077b48;
P_0c0779cc: /* original 0009, guest PC 0x0c0779cc */
if(!s->budget--) { s->failed_pc=0x0c0779ccu; return 0; }
goto P_0c0779ce;
P_0c0779ce: /* original e03e, guest PC 0x0c0779ce */
if(!s->budget--) { s->failed_pc=0x0c0779ceu; return 0; }
r[0]=0x0000003eu;
goto P_0c0779d0;
P_0c0779d0: /* original 03ed, guest PC 0x0c0779d0 */
if(!s->budget--) { s->failed_pc=0x0c0779d0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0779d2;
P_0c0779d2: /* original 906f, guest PC 0x0c0779d2 */
if(!s->budget--) { s->failed_pc=0x0c0779d2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab4u,2);
goto P_0c0779d4;
P_0c0779d4: /* original 633d, guest PC 0x0c0779d4 */
if(!s->budget--) { s->failed_pc=0x0c0779d4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0779d6;
P_0c0779d6: /* original 02ed, guest PC 0x0c0779d6 */
if(!s->budget--) { s->failed_pc=0x0c0779d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0779d8;
P_0c0779d8: /* original 7301, guest PC 0x0c0779d8 */
if(!s->budget--) { s->failed_pc=0x0c0779d8u; return 0; }
r[3]+=0x00000001u;
goto P_0c0779da;
P_0c0779da: /* original 622d, guest PC 0x0c0779da */
if(!s->budget--) { s->failed_pc=0x0c0779dau; return 0; }
r[2]=r[2]&65535u;
goto P_0c0779dc;
P_0c0779dc: /* original 3323, guest PC 0x0c0779dc */
if(!s->budget--) { s->failed_pc=0x0c0779dcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c0779de;
P_0c0779de: /* original 8b02, guest PC 0x0c0779de */
if(!s->budget--) { s->failed_pc=0x0c0779deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0779e6; }
goto P_0c0779e0;
P_0c0779e0: /* original 50f9, guest PC 0x0c0779e0 */
if(!s->budget--) { s->failed_pc=0x0c0779e0u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0779e2;
P_0c0779e2: /* original cb80, guest PC 0x0c0779e2 */
if(!s->budget--) { s->failed_pc=0x0c0779e2u; return 0; }
r[0]|=128u;
goto P_0c0779e4;
P_0c0779e4: /* original 1f09, guest PC 0x0c0779e4 */
if(!s->budget--) { s->failed_pc=0x0c0779e4u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c0779e6;
P_0c0779e6: /* original 50f1, guest PC 0x0c0779e6 */
if(!s->budget--) { s->failed_pc=0x0c0779e6u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0779e8;
P_0c0779e8: /* original c820, guest PC 0x0c0779e8 */
if(!s->budget--) { s->failed_pc=0x0c0779e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0779ea;
P_0c0779ea: /* original 8b0a, guest PC 0x0c0779ea */
if(!s->budget--) { s->failed_pc=0x0c0779eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a02; }
goto P_0c0779ec;
P_0c0779ec: /* original 51fa, guest PC 0x0c0779ec */
if(!s->budget--) { s->failed_pc=0x0c0779ecu; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c0779ee;
P_0c0779ee: /* original d336, guest PC 0x0c0779ee */
if(!s->budget--) { s->failed_pc=0x0c0779eeu; return 0; }
r[3]=read(ram,0x0c077ac8u,4);
goto P_0c0779f0;
P_0c0779f0: /* original 2138, guest PC 0x0c0779f0 */
if(!s->budget--) { s->failed_pc=0x0c0779f0u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0779f2;
P_0c0779f2: /* original 8b06, guest PC 0x0c0779f2 */
if(!s->budget--) { s->failed_pc=0x0c0779f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a02; }
goto P_0c0779f4;
P_0c0779f4: /* original d235, guest PC 0x0c0779f4 */
if(!s->budget--) { s->failed_pc=0x0c0779f4u; return 0; }
r[2]=read(ram,0x0c077accu,4);
goto P_0c0779f6;
P_0c0779f6: /* original 6123, guest PC 0x0c0779f6 */
if(!s->budget--) { s->failed_pc=0x0c0779f6u; return 0; }
r[1]=r[2];
goto P_0c0779f8;
P_0c0779f8: /* original 1f2e, guest PC 0x0c0779f8 */
if(!s->budget--) { s->failed_pc=0x0c0779f8u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c0779fa;
P_0c0779fa: /* original 1f1a, guest PC 0x0c0779fa */
if(!s->budget--) { s->failed_pc=0x0c0779fau; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c0779fc;
P_0c0779fc: /* original 50f9, guest PC 0x0c0779fc */
if(!s->budget--) { s->failed_pc=0x0c0779fcu; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c0779fe;
P_0c0779fe: /* original cb80, guest PC 0x0c0779fe */
if(!s->budget--) { s->failed_pc=0x0c0779feu; return 0; }
r[0]|=128u;
goto P_0c077a00;
P_0c077a00: /* original 1f09, guest PC 0x0c077a00 */
if(!s->budget--) { s->failed_pc=0x0c077a00u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c077a02;
P_0c077a02: /* original 50f9, guest PC 0x0c077a02 */
if(!s->budget--) { s->failed_pc=0x0c077a02u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a04;
P_0c077a04: /* original c80f, guest PC 0x0c077a04 */
if(!s->budget--) { s->failed_pc=0x0c077a04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c077a06;
P_0c077a06: /* original 8b08, guest PC 0x0c077a06 */
if(!s->budget--) { s->failed_pc=0x0c077a06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a1a; }
goto P_0c077a08;
P_0c077a08: /* original 61f3, guest PC 0x0c077a08 */
if(!s->budget--) { s->failed_pc=0x0c077a08u; return 0; }
r[1]=r[15];
goto P_0c077a0a;
P_0c077a0a: /* original 7178, guest PC 0x0c077a0a */
if(!s->budget--) { s->failed_pc=0x0c077a0au; return 0; }
r[1]+=0x00000078u;
goto P_0c077a0c;
P_0c077a0c: /* original 6012, guest PC 0x0c077a0c */
if(!s->budget--) { s->failed_pc=0x0c077a0cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077a0e;
P_0c077a0e: /* original e3f0, guest PC 0x0c077a0e */
if(!s->budget--) { s->failed_pc=0x0c077a0eu; return 0; }
r[3]=0xfffffff0u;
goto P_0c077a10;
P_0c077a10: /* original 52f9, guest PC 0x0c077a10 */
if(!s->budget--) { s->failed_pc=0x0c077a10u; return 0; }
r[2]=read(ram,r[15]+36,4);
goto P_0c077a12;
P_0c077a12: /* original c90f, guest PC 0x0c077a12 */
if(!s->budget--) { s->failed_pc=0x0c077a12u; return 0; }
r[0]&=15u;
goto P_0c077a14;
P_0c077a14: /* original 2239, guest PC 0x0c077a14 */
if(!s->budget--) { s->failed_pc=0x0c077a14u; return 0; }
r[2]&=r[3];
goto P_0c077a16;
P_0c077a16: /* original 220b, guest PC 0x0c077a16 */
if(!s->budget--) { s->failed_pc=0x0c077a16u; return 0; }
r[2]|=r[0];
goto P_0c077a18;
P_0c077a18: /* original 1f29, guest PC 0x0c077a18 */
if(!s->budget--) { s->failed_pc=0x0c077a18u; return 0; }
write(ram,r[15]+36,r[2],4);
goto P_0c077a1a;
P_0c077a1a: /* original 50f9, guest PC 0x0c077a1a */
if(!s->budget--) { s->failed_pc=0x0c077a1au; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a1c;
P_0c077a1c: /* original 62f3, guest PC 0x0c077a1c */
if(!s->budget--) { s->failed_pc=0x0c077a1cu; return 0; }
r[2]=r[15];
goto P_0c077a1e;
P_0c077a1e: /* original 7278, guest PC 0x0c077a1e */
if(!s->budget--) { s->failed_pc=0x0c077a1eu; return 0; }
r[2]+=0x00000078u;
goto P_0c077a20;
P_0c077a20: /* original c90f, guest PC 0x0c077a20 */
if(!s->budget--) { s->failed_pc=0x0c077a20u; return 0; }
r[0]&=15u;
goto P_0c077a22;
P_0c077a22: /* original 2008, guest PC 0x0c077a22 */
if(!s->budget--) { s->failed_pc=0x0c077a22u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077a24;
P_0c077a24: /* original 8f02, guest PC 0x0c077a24 */
if(!s->budget--) { s->failed_pc=0x0c077a24u; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[0],4);
if(!cond) { goto P_0c077a2c; }
goto P_0c077a28;
P_0c077a26: /* original 2202, guest PC 0x0c077a26 */
if(!s->budget--) { s->failed_pc=0x0c077a26u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c077a28;
P_0c077a28: /* original a08e, guest PC 0x0c077a28 */
if(!s->budget--) { s->failed_pc=0x0c077a28u; return 0; }
goto P_0c077b48;
P_0c077a2a: /* original 0009, guest PC 0x0c077a2a */
if(!s->budget--) { s->failed_pc=0x0c077a2au; return 0; }
goto P_0c077a2c;
P_0c077a2c: /* original 50f9, guest PC 0x0c077a2c */
if(!s->budget--) { s->failed_pc=0x0c077a2cu; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a2e;
P_0c077a2e: /* original c880, guest PC 0x0c077a2e */
if(!s->budget--) { s->failed_pc=0x0c077a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c077a30;
P_0c077a30: /* original 8b01, guest PC 0x0c077a30 */
if(!s->budget--) { s->failed_pc=0x0c077a30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077a36; }
goto P_0c077a32;
P_0c077a32: /* original a089, guest PC 0x0c077a32 */
if(!s->budget--) { s->failed_pc=0x0c077a32u; return 0; }
goto P_0c077b48;
P_0c077a34: /* original 0009, guest PC 0x0c077a34 */
if(!s->budget--) { s->failed_pc=0x0c077a34u; return 0; }
goto P_0c077a36;
P_0c077a36: /* original 52fa, guest PC 0x0c077a36 */
if(!s->budget--) { s->failed_pc=0x0c077a36u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c077a38;
P_0c077a38: /* original d323, guest PC 0x0c077a38 */
if(!s->budget--) { s->failed_pc=0x0c077a38u; return 0; }
r[3]=read(ram,0x0c077ac8u,4);
goto P_0c077a3a;
P_0c077a3a: /* original 2238, guest PC 0x0c077a3a */
if(!s->budget--) { s->failed_pc=0x0c077a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077a3c;
P_0c077a3c: /* original 8902, guest PC 0x0c077a3c */
if(!s->budget--) { s->failed_pc=0x0c077a3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077a44; }
goto P_0c077a3e;
P_0c077a3e: /* original 923a, guest PC 0x0c077a3e */
if(!s->budget--) { s->failed_pc=0x0c077a3eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab6u,2);
goto P_0c077a40;
P_0c077a40: /* original a001, guest PC 0x0c077a40 */
if(!s->budget--) { s->failed_pc=0x0c077a40u; return 0; }
goto P_0c077a46;
P_0c077a42: /* original 0009, guest PC 0x0c077a42 */
if(!s->budget--) { s->failed_pc=0x0c077a42u; return 0; }
goto P_0c077a44;
P_0c077a44: /* original 9238, guest PC 0x0c077a44 */
if(!s->budget--) { s->failed_pc=0x0c077a44u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab8u,2);
goto P_0c077a46;
P_0c077a46: /* original e078, guest PC 0x0c077a46 */
if(!s->budget--) { s->failed_pc=0x0c077a46u; return 0; }
r[0]=0x00000078u;
goto P_0c077a48;
P_0c077a48: /* original 01fe, guest PC 0x0c077a48 */
if(!s->budget--) { s->failed_pc=0x0c077a48u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077a4a;
P_0c077a4a: /* original e078, guest PC 0x0c077a4a */
if(!s->budget--) { s->failed_pc=0x0c077a4au; return 0; }
r[0]=0x00000078u;
goto P_0c077a4c;
P_0c077a4c: /* original 312c, guest PC 0x0c077a4c */
if(!s->budget--) { s->failed_pc=0x0c077a4cu; return 0; }
r[1]+=r[2];
goto P_0c077a4e;
P_0c077a4e: /* original 0f16, guest PC 0x0c077a4e */
if(!s->budget--) { s->failed_pc=0x0c077a4eu; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077a50;
P_0c077a50: /* original 50f9, guest PC 0x0c077a50 */
if(!s->budget--) { s->failed_pc=0x0c077a50u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c077a52;
P_0c077a52: /* original cb40, guest PC 0x0c077a52 */
if(!s->budget--) { s->failed_pc=0x0c077a52u; return 0; }
r[0]|=64u;
goto P_0c077a54;
P_0c077a54: /* original 6203, guest PC 0x0c077a54 */
if(!s->budget--) { s->failed_pc=0x0c077a54u; return 0; }
r[2]=r[0];
goto P_0c077a56;
P_0c077a56: /* original 1f09, guest PC 0x0c077a56 */
if(!s->budget--) { s->failed_pc=0x0c077a56u; return 0; }
write(ram,r[15]+36,r[0],4);
goto P_0c077a58;
P_0c077a58: /* original 902b, guest PC 0x0c077a58 */
if(!s->budget--) { s->failed_pc=0x0c077a58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ab2u,2);
goto P_0c077a5a;
P_0c077a5a: /* original 0e24, guest PC 0x0c077a5a */
if(!s->budget--) { s->failed_pc=0x0c077a5au; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c077a5c;
P_0c077a5c: /* original e050, guest PC 0x0c077a5c */
if(!s->budget--) { s->failed_pc=0x0c077a5cu; return 0; }
r[0]=0x00000050u;
goto P_0c077a5e;
P_0c077a5e: /* original 03fe, guest PC 0x0c077a5e */
if(!s->budget--) { s->failed_pc=0x0c077a5eu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a60;
P_0c077a60: /* original e04c, guest PC 0x0c077a60 */
if(!s->budget--) { s->failed_pc=0x0c077a60u; return 0; }
r[0]=0x0000004cu;
goto P_0c077a62;
P_0c077a62: /* original 2f36, guest PC 0x0c077a62 */
if(!s->budget--) { s->failed_pc=0x0c077a62u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077a64;
P_0c077a64: /* original 52f2, guest PC 0x0c077a64 */
if(!s->budget--) { s->failed_pc=0x0c077a64u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077a66;
P_0c077a66: /* original 2f26, guest PC 0x0c077a66 */
if(!s->budget--) { s->failed_pc=0x0c077a66u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077a68;
P_0c077a68: /* original 03fe, guest PC 0x0c077a68 */
if(!s->budget--) { s->failed_pc=0x0c077a68u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a6a;
P_0c077a6a: /* original e04c, guest PC 0x0c077a6a */
if(!s->budget--) { s->failed_pc=0x0c077a6au; return 0; }
r[0]=0x0000004cu;
goto P_0c077a6c;
P_0c077a6c: /* original 2f36, guest PC 0x0c077a6c */
if(!s->budget--) { s->failed_pc=0x0c077a6cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077a6e;
P_0c077a6e: /* original 02fe, guest PC 0x0c077a6e */
if(!s->budget--) { s->failed_pc=0x0c077a6eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a70;
P_0c077a70: /* original 2f26, guest PC 0x0c077a70 */
if(!s->budget--) { s->failed_pc=0x0c077a70u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077a72;
P_0c077a72: /* original 9022, guest PC 0x0c077a72 */
if(!s->budget--) { s->failed_pc=0x0c077a72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abau,2);
goto P_0c077a74;
P_0c077a74: /* original 03fe, guest PC 0x0c077a74 */
if(!s->budget--) { s->failed_pc=0x0c077a74u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a76;
P_0c077a76: /* original e05c, guest PC 0x0c077a76 */
if(!s->budget--) { s->failed_pc=0x0c077a76u; return 0; }
r[0]=0x0000005cu;
goto P_0c077a78;
P_0c077a78: /* original 2f36, guest PC 0x0c077a78 */
if(!s->budget--) { s->failed_pc=0x0c077a78u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077a7a;
P_0c077a7a: /* original 02fe, guest PC 0x0c077a7a */
if(!s->budget--) { s->failed_pc=0x0c077a7au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a7c;
P_0c077a7c: /* original 2f26, guest PC 0x0c077a7c */
if(!s->budget--) { s->failed_pc=0x0c077a7cu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077a7e;
P_0c077a7e: /* original 931d, guest PC 0x0c077a7e */
if(!s->budget--) { s->failed_pc=0x0c077a7eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abcu,2);
goto P_0c077a80;
P_0c077a80: /* original 33fc, guest PC 0x0c077a80 */
if(!s->budget--) { s->failed_pc=0x0c077a80u; return 0; }
r[3]+=r[15];
goto P_0c077a82;
P_0c077a82: /* original 2f36, guest PC 0x0c077a82 */
if(!s->budget--) { s->failed_pc=0x0c077a82u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077a84;
P_0c077a84: /* original 901a, guest PC 0x0c077a84 */
if(!s->budget--) { s->failed_pc=0x0c077a84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abcu,2);
goto P_0c077a86;
P_0c077a86: /* original 02fe, guest PC 0x0c077a86 */
if(!s->budget--) { s->failed_pc=0x0c077a86u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a88;
P_0c077a88: /* original 65e3, guest PC 0x0c077a88 */
if(!s->budget--) { s->failed_pc=0x0c077a88u; return 0; }
r[5]=r[14];
goto P_0c077a8a;
P_0c077a8a: /* original 66d3, guest PC 0x0c077a8a */
if(!s->budget--) { s->failed_pc=0x0c077a8au; return 0; }
r[6]=r[13];
goto P_0c077a8c;
P_0c077a8c: /* original 2f26, guest PC 0x0c077a8c */
if(!s->budget--) { s->failed_pc=0x0c077a8cu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077a8e;
P_0c077a8e: /* original 9014, guest PC 0x0c077a8e */
if(!s->budget--) { s->failed_pc=0x0c077a8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abau,2);
goto P_0c077a90;
P_0c077a90: /* original 03fe, guest PC 0x0c077a90 */
if(!s->budget--) { s->failed_pc=0x0c077a90u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077a92;
P_0c077a92: /* original 2f36, guest PC 0x0c077a92 */
if(!s->budget--) { s->failed_pc=0x0c077a92u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077a94;
P_0c077a94: /* original 9013, guest PC 0x0c077a94 */
if(!s->budget--) { s->failed_pc=0x0c077a94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abeu,2);
goto P_0c077a96;
P_0c077a96: /* original 02fe, guest PC 0x0c077a96 */
if(!s->budget--) { s->failed_pc=0x0c077a96u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077a98;
P_0c077a98: /* original 2f26, guest PC 0x0c077a98 */
if(!s->budget--) { s->failed_pc=0x0c077a98u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077a9a;
P_0c077a9a: /* original 9710, guest PC 0x0c077a9a */
if(!s->budget--) { s->failed_pc=0x0c077a9au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077abeu,2);
goto P_0c077a9c;
P_0c077a9c: /* original 37fc, guest PC 0x0c077a9c */
if(!s->budget--) { s->failed_pc=0x0c077a9cu; return 0; }
r[7]+=r[15];
goto P_0c077a9e;
P_0c077a9e: /* original b38c, guest PC 0x0c077a9e */
if(!s->budget--) { s->failed_pc=0x0c077a9eu; return 0; }
target=0x0c0781bau; r[16]=0x0c077aa2u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077aa2u) { target=s->pc; goto dispatch; }
goto P_0c077aa2;
P_0c077aa0: /* original 64c3, guest PC 0x0c077aa0 */
if(!s->budget--) { s->failed_pc=0x0c077aa0u; return 0; }
r[4]=r[12];
goto P_0c077aa2;
P_0c077aa2: /* original 2008, guest PC 0x0c077aa2 */
if(!s->budget--) { s->failed_pc=0x0c077aa2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077aa4;
P_0c077aa4: /* original 8d02, guest PC 0x0c077aa4 */
if(!s->budget--) { s->failed_pc=0x0c077aa4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077aac; }
goto P_0c077aa8;
P_0c077aa6: /* original 7f28, guest PC 0x0c077aa6 */
if(!s->budget--) { s->failed_pc=0x0c077aa6u; return 0; }
r[15]+=0x00000028u;
goto P_0c077aa8;
P_0c077aa8: /* original a1ca, guest PC 0x0c077aa8 */
if(!s->budget--) { s->failed_pc=0x0c077aa8u; return 0; }
goto P_0c077e40;
P_0c077aaa: /* original 0009, guest PC 0x0c077aaa */
if(!s->budget--) { s->failed_pc=0x0c077aaau; return 0; }
goto P_0c077aac;
P_0c077aac: /* original a1b3, guest PC 0x0c077aac */
if(!s->budget--) { s->failed_pc=0x0c077aacu; return 0; }
goto P_0c077e16;
P_0c077aae: /* original 0009, guest PC 0x0c077aae */
if(!s->budget--) { s->failed_pc=0x0c077aaeu; return 0; }
return vf3_matrix_family(0x0c077ab0u,s,ram);
P_0c077ad0: /* original 61f3, guest PC 0x0c077ad0 */
if(!s->budget--) { s->failed_pc=0x0c077ad0u; return 0; }
r[1]=r[15];
goto P_0c077ad2;
P_0c077ad2: /* original 7178, guest PC 0x0c077ad2 */
if(!s->budget--) { s->failed_pc=0x0c077ad2u; return 0; }
r[1]+=0x00000078u;
goto P_0c077ad4;
P_0c077ad4: /* original 6012, guest PC 0x0c077ad4 */
if(!s->budget--) { s->failed_pc=0x0c077ad4u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077ad6;
P_0c077ad6: /* original c80f, guest PC 0x0c077ad6 */
if(!s->budget--) { s->failed_pc=0x0c077ad6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&15u)==0)!=0);
goto P_0c077ad8;
P_0c077ad8: /* original 8936, guest PC 0x0c077ad8 */
if(!s->budget--) { s->failed_pc=0x0c077ad8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077b48; }
goto P_0c077ada;
P_0c077ada: /* original 52fa, guest PC 0x0c077ada */
if(!s->budget--) { s->failed_pc=0x0c077adau; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c077adc;
P_0c077adc: /* original d334, guest PC 0x0c077adc */
if(!s->budget--) { s->failed_pc=0x0c077adcu; return 0; }
r[3]=read(ram,0x0c077bb0u,4);
goto P_0c077ade;
P_0c077ade: /* original 2238, guest PC 0x0c077ade */
if(!s->budget--) { s->failed_pc=0x0c077adeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077ae0;
P_0c077ae0: /* original 8b02, guest PC 0x0c077ae0 */
if(!s->budget--) { s->failed_pc=0x0c077ae0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077ae8; }
goto P_0c077ae2;
P_0c077ae2: /* original 925d, guest PC 0x0c077ae2 */
if(!s->budget--) { s->failed_pc=0x0c077ae2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba0u,2);
goto P_0c077ae4;
P_0c077ae4: /* original a001, guest PC 0x0c077ae4 */
if(!s->budget--) { s->failed_pc=0x0c077ae4u; return 0; }
goto P_0c077aea;
P_0c077ae6: /* original 0009, guest PC 0x0c077ae6 */
if(!s->budget--) { s->failed_pc=0x0c077ae6u; return 0; }
goto P_0c077ae8;
P_0c077ae8: /* original 925b, guest PC 0x0c077ae8 */
if(!s->budget--) { s->failed_pc=0x0c077ae8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba2u,2);
goto P_0c077aea;
P_0c077aea: /* original e078, guest PC 0x0c077aea */
if(!s->budget--) { s->failed_pc=0x0c077aeau; return 0; }
r[0]=0x00000078u;
goto P_0c077aec;
P_0c077aec: /* original 01fe, guest PC 0x0c077aec */
if(!s->budget--) { s->failed_pc=0x0c077aecu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077aee;
P_0c077aee: /* original e078, guest PC 0x0c077aee */
if(!s->budget--) { s->failed_pc=0x0c077aeeu; return 0; }
r[0]=0x00000078u;
goto P_0c077af0;
P_0c077af0: /* original 312c, guest PC 0x0c077af0 */
if(!s->budget--) { s->failed_pc=0x0c077af0u; return 0; }
r[1]+=r[2];
goto P_0c077af2;
P_0c077af2: /* original 0f16, guest PC 0x0c077af2 */
if(!s->budget--) { s->failed_pc=0x0c077af2u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077af4;
P_0c077af4: /* original e050, guest PC 0x0c077af4 */
if(!s->budget--) { s->failed_pc=0x0c077af4u; return 0; }
r[0]=0x00000050u;
goto P_0c077af6;
P_0c077af6: /* original 03fe, guest PC 0x0c077af6 */
if(!s->budget--) { s->failed_pc=0x0c077af6u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077af8;
P_0c077af8: /* original e04c, guest PC 0x0c077af8 */
if(!s->budget--) { s->failed_pc=0x0c077af8u; return 0; }
r[0]=0x0000004cu;
goto P_0c077afa;
P_0c077afa: /* original 2f36, guest PC 0x0c077afa */
if(!s->budget--) { s->failed_pc=0x0c077afau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077afc;
P_0c077afc: /* original 52f2, guest PC 0x0c077afc */
if(!s->budget--) { s->failed_pc=0x0c077afcu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077afe;
P_0c077afe: /* original 2f26, guest PC 0x0c077afe */
if(!s->budget--) { s->failed_pc=0x0c077afeu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077b00;
P_0c077b00: /* original 03fe, guest PC 0x0c077b00 */
if(!s->budget--) { s->failed_pc=0x0c077b00u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077b02;
P_0c077b02: /* original e04c, guest PC 0x0c077b02 */
if(!s->budget--) { s->failed_pc=0x0c077b02u; return 0; }
r[0]=0x0000004cu;
goto P_0c077b04;
P_0c077b04: /* original 2f36, guest PC 0x0c077b04 */
if(!s->budget--) { s->failed_pc=0x0c077b04u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077b06;
P_0c077b06: /* original 02fe, guest PC 0x0c077b06 */
if(!s->budget--) { s->failed_pc=0x0c077b06u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b08;
P_0c077b08: /* original 2f26, guest PC 0x0c077b08 */
if(!s->budget--) { s->failed_pc=0x0c077b08u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077b0a;
P_0c077b0a: /* original 904b, guest PC 0x0c077b0a */
if(!s->budget--) { s->failed_pc=0x0c077b0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba4u,2);
goto P_0c077b0c;
P_0c077b0c: /* original 03fe, guest PC 0x0c077b0c */
if(!s->budget--) { s->failed_pc=0x0c077b0cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077b0e;
P_0c077b0e: /* original e05c, guest PC 0x0c077b0e */
if(!s->budget--) { s->failed_pc=0x0c077b0eu; return 0; }
r[0]=0x0000005cu;
goto P_0c077b10;
P_0c077b10: /* original 2f36, guest PC 0x0c077b10 */
if(!s->budget--) { s->failed_pc=0x0c077b10u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077b12;
P_0c077b12: /* original 02fe, guest PC 0x0c077b12 */
if(!s->budget--) { s->failed_pc=0x0c077b12u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b14;
P_0c077b14: /* original 2f26, guest PC 0x0c077b14 */
if(!s->budget--) { s->failed_pc=0x0c077b14u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077b16;
P_0c077b16: /* original 9346, guest PC 0x0c077b16 */
if(!s->budget--) { s->failed_pc=0x0c077b16u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba6u,2);
goto P_0c077b18;
P_0c077b18: /* original 33fc, guest PC 0x0c077b18 */
if(!s->budget--) { s->failed_pc=0x0c077b18u; return 0; }
r[3]+=r[15];
goto P_0c077b1a;
P_0c077b1a: /* original 2f36, guest PC 0x0c077b1a */
if(!s->budget--) { s->failed_pc=0x0c077b1au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077b1c;
P_0c077b1c: /* original 9043, guest PC 0x0c077b1c */
if(!s->budget--) { s->failed_pc=0x0c077b1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba6u,2);
goto P_0c077b1e;
P_0c077b1e: /* original 02fe, guest PC 0x0c077b1e */
if(!s->budget--) { s->failed_pc=0x0c077b1eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b20;
P_0c077b20: /* original 2f26, guest PC 0x0c077b20 */
if(!s->budget--) { s->failed_pc=0x0c077b20u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077b22;
P_0c077b22: /* original 903f, guest PC 0x0c077b22 */
if(!s->budget--) { s->failed_pc=0x0c077b22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba4u,2);
goto P_0c077b24;
P_0c077b24: /* original 03fe, guest PC 0x0c077b24 */
if(!s->budget--) { s->failed_pc=0x0c077b24u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077b26;
P_0c077b26: /* original 2f36, guest PC 0x0c077b26 */
if(!s->budget--) { s->failed_pc=0x0c077b26u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077b28;
P_0c077b28: /* original 903e, guest PC 0x0c077b28 */
if(!s->budget--) { s->failed_pc=0x0c077b28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba8u,2);
goto P_0c077b2a;
P_0c077b2a: /* original 02fe, guest PC 0x0c077b2a */
if(!s->budget--) { s->failed_pc=0x0c077b2au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b2c;
P_0c077b2c: /* original 65e3, guest PC 0x0c077b2c */
if(!s->budget--) { s->failed_pc=0x0c077b2cu; return 0; }
r[5]=r[14];
goto P_0c077b2e;
P_0c077b2e: /* original 66d3, guest PC 0x0c077b2e */
if(!s->budget--) { s->failed_pc=0x0c077b2eu; return 0; }
r[6]=r[13];
goto P_0c077b30;
P_0c077b30: /* original 2f26, guest PC 0x0c077b30 */
if(!s->budget--) { s->failed_pc=0x0c077b30u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077b32;
P_0c077b32: /* original 9739, guest PC 0x0c077b32 */
if(!s->budget--) { s->failed_pc=0x0c077b32u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ba8u,2);
goto P_0c077b34;
P_0c077b34: /* original 37fc, guest PC 0x0c077b34 */
if(!s->budget--) { s->failed_pc=0x0c077b34u; return 0; }
r[7]+=r[15];
goto P_0c077b36;
P_0c077b36: /* original b340, guest PC 0x0c077b36 */
if(!s->budget--) { s->failed_pc=0x0c077b36u; return 0; }
target=0x0c0781bau; r[16]=0x0c077b3au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077b3au) { target=s->pc; goto dispatch; }
goto P_0c077b3a;
P_0c077b38: /* original 64c3, guest PC 0x0c077b38 */
if(!s->budget--) { s->failed_pc=0x0c077b38u; return 0; }
r[4]=r[12];
goto P_0c077b3a;
P_0c077b3a: /* original 2008, guest PC 0x0c077b3a */
if(!s->budget--) { s->failed_pc=0x0c077b3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077b3c;
P_0c077b3c: /* original 8d02, guest PC 0x0c077b3c */
if(!s->budget--) { s->failed_pc=0x0c077b3cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077b44; }
goto P_0c077b40;
P_0c077b3e: /* original 7f28, guest PC 0x0c077b3e */
if(!s->budget--) { s->failed_pc=0x0c077b3eu; return 0; }
r[15]+=0x00000028u;
goto P_0c077b40;
P_0c077b40: /* original a17e, guest PC 0x0c077b40 */
if(!s->budget--) { s->failed_pc=0x0c077b40u; return 0; }
goto P_0c077e40;
P_0c077b42: /* original 0009, guest PC 0x0c077b42 */
if(!s->budget--) { s->failed_pc=0x0c077b42u; return 0; }
goto P_0c077b44;
P_0c077b44: /* original a167, guest PC 0x0c077b44 */
if(!s->budget--) { s->failed_pc=0x0c077b44u; return 0; }
goto P_0c077e16;
P_0c077b46: /* original 0009, guest PC 0x0c077b46 */
if(!s->budget--) { s->failed_pc=0x0c077b46u; return 0; }
goto P_0c077b48;
P_0c077b48: /* original 902f, guest PC 0x0c077b48 */
if(!s->budget--) { s->failed_pc=0x0c077b48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077baau,2);
goto P_0c077b4a;
P_0c077b4a: /* original 53f9, guest PC 0x0c077b4a */
if(!s->budget--) { s->failed_pc=0x0c077b4au; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c077b4c;
P_0c077b4c: /* original 0e34, guest PC 0x0c077b4c */
if(!s->budget--) { s->failed_pc=0x0c077b4cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077b4e;
P_0c077b4e: /* original 52fe, guest PC 0x0c077b4e */
if(!s->budget--) { s->failed_pc=0x0c077b4eu; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c077b50;
P_0c077b50: /* original 2228, guest PC 0x0c077b50 */
if(!s->budget--) { s->failed_pc=0x0c077b50u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c077b52;
P_0c077b52: /* original 8b01, guest PC 0x0c077b52 */
if(!s->budget--) { s->failed_pc=0x0c077b52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077b58; }
goto P_0c077b54;
P_0c077b54: /* original a0a8, guest PC 0x0c077b54 */
if(!s->budget--) { s->failed_pc=0x0c077b54u; return 0; }
goto P_0c077ca8;
P_0c077b56: /* original 0009, guest PC 0x0c077b56 */
if(!s->budget--) { s->failed_pc=0x0c077b56u; return 0; }
goto P_0c077b58;
P_0c077b58: /* original 51fe, guest PC 0x0c077b58 */
if(!s->budget--) { s->failed_pc=0x0c077b58u; return 0; }
r[1]=read(ram,r[15]+56,4);
goto P_0c077b5a;
P_0c077b5a: /* original a15c, guest PC 0x0c077b5a */
if(!s->budget--) { s->failed_pc=0x0c077b5au; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c077e16;
P_0c077b5c: /* original 1e1c, guest PC 0x0c077b5c */
if(!s->budget--) { s->failed_pc=0x0c077b5cu; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c077b5e;
P_0c077b5e: /* original e078, guest PC 0x0c077b5e */
if(!s->budget--) { s->failed_pc=0x0c077b5eu; return 0; }
r[0]=0x00000078u;
goto P_0c077b60;
P_0c077b60: /* original 02fe, guest PC 0x0c077b60 */
if(!s->budget--) { s->failed_pc=0x0c077b60u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b62;
P_0c077b62: /* original 2228, guest PC 0x0c077b62 */
if(!s->budget--) { s->failed_pc=0x0c077b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c077b64;
P_0c077b64: /* original 8965, guest PC 0x0c077b64 */
if(!s->budget--) { s->failed_pc=0x0c077b64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077c32; }
goto P_0c077b66;
P_0c077b66: /* original e04c, guest PC 0x0c077b66 */
if(!s->budget--) { s->failed_pc=0x0c077b66u; return 0; }
r[0]=0x0000004cu;
goto P_0c077b68;
P_0c077b68: /* original 03ee, guest PC 0x0c077b68 */
if(!s->budget--) { s->failed_pc=0x0c077b68u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c077b6a;
P_0c077b6a: /* original e06c, guest PC 0x0c077b6a */
if(!s->budget--) { s->failed_pc=0x0c077b6au; return 0; }
r[0]=0x0000006cu;
goto P_0c077b6c;
P_0c077b6c: /* original 0f36, guest PC 0x0c077b6c */
if(!s->budget--) { s->failed_pc=0x0c077b6cu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c077b6e;
P_0c077b6e: /* original e06c, guest PC 0x0c077b6e */
if(!s->budget--) { s->failed_pc=0x0c077b6eu; return 0; }
r[0]=0x0000006cu;
goto P_0c077b70;
P_0c077b70: /* original 02fe, guest PC 0x0c077b70 */
if(!s->budget--) { s->failed_pc=0x0c077b70u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077b72;
P_0c077b72: /* original d310, guest PC 0x0c077b72 */
if(!s->budget--) { s->failed_pc=0x0c077b72u; return 0; }
r[3]=read(ram,0x0c077bb4u,4);
goto P_0c077b74;
P_0c077b74: /* original 2238, guest PC 0x0c077b74 */
if(!s->budget--) { s->failed_pc=0x0c077b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077b76;
P_0c077b76: /* original 8906, guest PC 0x0c077b76 */
if(!s->budget--) { s->failed_pc=0x0c077b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077b86; }
goto P_0c077b78;
P_0c077b78: /* original e078, guest PC 0x0c077b78 */
if(!s->budget--) { s->failed_pc=0x0c077b78u; return 0; }
r[0]=0x00000078u;
goto P_0c077b7a;
P_0c077b7a: /* original 9217, guest PC 0x0c077b7a */
if(!s->budget--) { s->failed_pc=0x0c077b7au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077bacu,2);
goto P_0c077b7c;
P_0c077b7c: /* original 01fe, guest PC 0x0c077b7c */
if(!s->budget--) { s->failed_pc=0x0c077b7cu; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077b7e;
P_0c077b7e: /* original e078, guest PC 0x0c077b7e */
if(!s->budget--) { s->failed_pc=0x0c077b7eu; return 0; }
r[0]=0x00000078u;
goto P_0c077b80;
P_0c077b80: /* original 312c, guest PC 0x0c077b80 */
if(!s->budget--) { s->failed_pc=0x0c077b80u; return 0; }
r[1]+=r[2];
goto P_0c077b82;
P_0c077b82: /* original a027, guest PC 0x0c077b82 */
if(!s->budget--) { s->failed_pc=0x0c077b82u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077bd4;
P_0c077b84: /* original 0f16, guest PC 0x0c077b84 */
if(!s->budget--) { s->failed_pc=0x0c077b84u; return 0; }
write(ram,r[15]+r[0],r[1],4);
goto P_0c077b86;
P_0c077b86: /* original e06c, guest PC 0x0c077b86 */
if(!s->budget--) { s->failed_pc=0x0c077b86u; return 0; }
r[0]=0x0000006cu;
goto P_0c077b88;
P_0c077b88: /* original d20b, guest PC 0x0c077b88 */
if(!s->budget--) { s->failed_pc=0x0c077b88u; return 0; }
r[2]=read(ram,0x0c077bb8u,4);
goto P_0c077b8a;
P_0c077b8a: /* original 01fe, guest PC 0x0c077b8a */
if(!s->budget--) { s->failed_pc=0x0c077b8au; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077b8c;
P_0c077b8c: /* original 2128, guest PC 0x0c077b8c */
if(!s->budget--) { s->failed_pc=0x0c077b8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077b8e;
P_0c077b8e: /* original 8915, guest PC 0x0c077b8e */
if(!s->budget--) { s->failed_pc=0x0c077b8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077bbc; }
goto P_0c077b90;
P_0c077b90: /* original e078, guest PC 0x0c077b90 */
if(!s->budget--) { s->failed_pc=0x0c077b90u; return 0; }
r[0]=0x00000078u;
goto P_0c077b92;
P_0c077b92: /* original 910c, guest PC 0x0c077b92 */
if(!s->budget--) { s->failed_pc=0x0c077b92u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077baeu,2);
goto P_0c077b94;
P_0c077b94: /* original 00fe, guest PC 0x0c077b94 */
if(!s->budget--) { s->failed_pc=0x0c077b94u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077b96;
P_0c077b96: /* original 63f3, guest PC 0x0c077b96 */
if(!s->budget--) { s->failed_pc=0x0c077b96u; return 0; }
r[3]=r[15];
goto P_0c077b98;
P_0c077b98: /* original 7378, guest PC 0x0c077b98 */
if(!s->budget--) { s->failed_pc=0x0c077b98u; return 0; }
r[3]+=0x00000078u;
goto P_0c077b9a;
P_0c077b9a: /* original 301c, guest PC 0x0c077b9a */
if(!s->budget--) { s->failed_pc=0x0c077b9au; return 0; }
r[0]+=r[1];
goto P_0c077b9c;
P_0c077b9c: /* original a01a, guest PC 0x0c077b9c */
if(!s->budget--) { s->failed_pc=0x0c077b9cu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c077bd4;
P_0c077b9e: /* original 2302, guest PC 0x0c077b9e */
if(!s->budget--) { s->failed_pc=0x0c077b9eu; return 0; }
write(ram,r[3],r[0],4);
return vf3_matrix_family(0x0c077ba0u,s,ram);
P_0c077bbc: /* original 909b, guest PC 0x0c077bbc */
if(!s->budget--) { s->failed_pc=0x0c077bbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cf6u,2);
goto P_0c077bbe;
P_0c077bbe: /* original d153, guest PC 0x0c077bbe */
if(!s->budget--) { s->failed_pc=0x0c077bbeu; return 0; }
r[1]=read(ram,0x0c077d0cu,4);
goto P_0c077bc0;
P_0c077bc0: /* original 00fe, guest PC 0x0c077bc0 */
if(!s->budget--) { s->failed_pc=0x0c077bc0u; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077bc2;
P_0c077bc2: /* original 2018, guest PC 0x0c077bc2 */
if(!s->budget--) { s->failed_pc=0x0c077bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c077bc4;
P_0c077bc4: /* original 8906, guest PC 0x0c077bc4 */
if(!s->budget--) { s->failed_pc=0x0c077bc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077bd4; }
goto P_0c077bc6;
P_0c077bc6: /* original e078, guest PC 0x0c077bc6 */
if(!s->budget--) { s->failed_pc=0x0c077bc6u; return 0; }
r[0]=0x00000078u;
goto P_0c077bc8;
P_0c077bc8: /* original 9396, guest PC 0x0c077bc8 */
if(!s->budget--) { s->failed_pc=0x0c077bc8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cf8u,2);
goto P_0c077bca;
P_0c077bca: /* original 00fe, guest PC 0x0c077bca */
if(!s->budget--) { s->failed_pc=0x0c077bcau; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077bcc;
P_0c077bcc: /* original 62f3, guest PC 0x0c077bcc */
if(!s->budget--) { s->failed_pc=0x0c077bccu; return 0; }
r[2]=r[15];
goto P_0c077bce;
P_0c077bce: /* original 7278, guest PC 0x0c077bce */
if(!s->budget--) { s->failed_pc=0x0c077bceu; return 0; }
r[2]+=0x00000078u;
goto P_0c077bd0;
P_0c077bd0: /* original 303c, guest PC 0x0c077bd0 */
if(!s->budget--) { s->failed_pc=0x0c077bd0u; return 0; }
r[0]+=r[3];
goto P_0c077bd2;
P_0c077bd2: /* original 2202, guest PC 0x0c077bd2 */
if(!s->budget--) { s->failed_pc=0x0c077bd2u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c077bd4;
P_0c077bd4: /* original e050, guest PC 0x0c077bd4 */
if(!s->budget--) { s->failed_pc=0x0c077bd4u; return 0; }
r[0]=0x00000050u;
goto P_0c077bd6;
P_0c077bd6: /* original 66d3, guest PC 0x0c077bd6 */
if(!s->budget--) { s->failed_pc=0x0c077bd6u; return 0; }
r[6]=r[13];
goto P_0c077bd8;
P_0c077bd8: /* original 01fe, guest PC 0x0c077bd8 */
if(!s->budget--) { s->failed_pc=0x0c077bd8u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077bda;
P_0c077bda: /* original e04c, guest PC 0x0c077bda */
if(!s->budget--) { s->failed_pc=0x0c077bdau; return 0; }
r[0]=0x0000004cu;
goto P_0c077bdc;
P_0c077bdc: /* original 2f16, guest PC 0x0c077bdc */
if(!s->budget--) { s->failed_pc=0x0c077bdcu; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c077bde;
P_0c077bde: /* original 53f2, guest PC 0x0c077bde */
if(!s->budget--) { s->failed_pc=0x0c077bdeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c077be0;
P_0c077be0: /* original 2f36, guest PC 0x0c077be0 */
if(!s->budget--) { s->failed_pc=0x0c077be0u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077be2;
P_0c077be2: /* original 02fe, guest PC 0x0c077be2 */
if(!s->budget--) { s->failed_pc=0x0c077be2u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077be4;
P_0c077be4: /* original e04c, guest PC 0x0c077be4 */
if(!s->budget--) { s->failed_pc=0x0c077be4u; return 0; }
r[0]=0x0000004cu;
goto P_0c077be6;
P_0c077be6: /* original 2f26, guest PC 0x0c077be6 */
if(!s->budget--) { s->failed_pc=0x0c077be6u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077be8;
P_0c077be8: /* original 03fe, guest PC 0x0c077be8 */
if(!s->budget--) { s->failed_pc=0x0c077be8u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077bea;
P_0c077bea: /* original 2f36, guest PC 0x0c077bea */
if(!s->budget--) { s->failed_pc=0x0c077beau; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077bec;
P_0c077bec: /* original 9085, guest PC 0x0c077bec */
if(!s->budget--) { s->failed_pc=0x0c077becu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077bee;
P_0c077bee: /* original 02fe, guest PC 0x0c077bee */
if(!s->budget--) { s->failed_pc=0x0c077beeu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077bf0;
P_0c077bf0: /* original e05c, guest PC 0x0c077bf0 */
if(!s->budget--) { s->failed_pc=0x0c077bf0u; return 0; }
r[0]=0x0000005cu;
goto P_0c077bf2;
P_0c077bf2: /* original 2f26, guest PC 0x0c077bf2 */
if(!s->budget--) { s->failed_pc=0x0c077bf2u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077bf4;
P_0c077bf4: /* original 03fe, guest PC 0x0c077bf4 */
if(!s->budget--) { s->failed_pc=0x0c077bf4u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077bf6;
P_0c077bf6: /* original 2f36, guest PC 0x0c077bf6 */
if(!s->budget--) { s->failed_pc=0x0c077bf6u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077bf8;
P_0c077bf8: /* original 9280, guest PC 0x0c077bf8 */
if(!s->budget--) { s->failed_pc=0x0c077bf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077bfa;
P_0c077bfa: /* original 32fc, guest PC 0x0c077bfa */
if(!s->budget--) { s->failed_pc=0x0c077bfau; return 0; }
r[2]+=r[15];
goto P_0c077bfc;
P_0c077bfc: /* original 2f26, guest PC 0x0c077bfc */
if(!s->budget--) { s->failed_pc=0x0c077bfcu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077bfe;
P_0c077bfe: /* original 907d, guest PC 0x0c077bfe */
if(!s->budget--) { s->failed_pc=0x0c077bfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077c00;
P_0c077c00: /* original 03fe, guest PC 0x0c077c00 */
if(!s->budget--) { s->failed_pc=0x0c077c00u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c02;
P_0c077c02: /* original 2f36, guest PC 0x0c077c02 */
if(!s->budget--) { s->failed_pc=0x0c077c02u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c04;
P_0c077c04: /* original 9079, guest PC 0x0c077c04 */
if(!s->budget--) { s->failed_pc=0x0c077c04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077c06;
P_0c077c06: /* original 02fe, guest PC 0x0c077c06 */
if(!s->budget--) { s->failed_pc=0x0c077c06u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c08;
P_0c077c08: /* original 2f26, guest PC 0x0c077c08 */
if(!s->budget--) { s->failed_pc=0x0c077c08u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077c0a;
P_0c077c0a: /* original 9078, guest PC 0x0c077c0a */
if(!s->budget--) { s->failed_pc=0x0c077c0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c0c;
P_0c077c0c: /* original 03fe, guest PC 0x0c077c0c */
if(!s->budget--) { s->failed_pc=0x0c077c0cu; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c0e;
P_0c077c0e: /* original 2f36, guest PC 0x0c077c0e */
if(!s->budget--) { s->failed_pc=0x0c077c0eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c10;
P_0c077c10: /* original 9775, guest PC 0x0c077c10 */
if(!s->budget--) { s->failed_pc=0x0c077c10u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c12;
P_0c077c12: /* original 37fc, guest PC 0x0c077c12 */
if(!s->budget--) { s->failed_pc=0x0c077c12u; return 0; }
r[7]+=r[15];
goto P_0c077c14;
P_0c077c14: /* original 65e3, guest PC 0x0c077c14 */
if(!s->budget--) { s->failed_pc=0x0c077c14u; return 0; }
r[5]=r[14];
goto P_0c077c16;
P_0c077c16: /* original b2d0, guest PC 0x0c077c16 */
if(!s->budget--) { s->failed_pc=0x0c077c16u; return 0; }
target=0x0c0781bau; r[16]=0x0c077c1au;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077c1au) { target=s->pc; goto dispatch; }
goto P_0c077c1a;
P_0c077c18: /* original 64c3, guest PC 0x0c077c18 */
if(!s->budget--) { s->failed_pc=0x0c077c18u; return 0; }
r[4]=r[12];
goto P_0c077c1a;
P_0c077c1a: /* original 2008, guest PC 0x0c077c1a */
if(!s->budget--) { s->failed_pc=0x0c077c1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077c1c;
P_0c077c1c: /* original 8d02, guest PC 0x0c077c1c */
if(!s->budget--) { s->failed_pc=0x0c077c1cu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077c24; }
goto P_0c077c20;
P_0c077c1e: /* original 7f28, guest PC 0x0c077c1e */
if(!s->budget--) { s->failed_pc=0x0c077c1eu; return 0; }
r[15]+=0x00000028u;
goto P_0c077c20;
P_0c077c20: /* original a10e, guest PC 0x0c077c20 */
if(!s->budget--) { s->failed_pc=0x0c077c20u; return 0; }
goto P_0c077e40;
P_0c077c22: /* original 0009, guest PC 0x0c077c22 */
if(!s->budget--) { s->failed_pc=0x0c077c22u; return 0; }
goto P_0c077c24;
P_0c077c24: /* original e074, guest PC 0x0c077c24 */
if(!s->budget--) { s->failed_pc=0x0c077c24u; return 0; }
r[0]=0x00000074u;
goto P_0c077c26;
P_0c077c26: /* original d33a, guest PC 0x0c077c26 */
if(!s->budget--) { s->failed_pc=0x0c077c26u; return 0; }
r[3]=read(ram,0x0c077d10u,4);
goto P_0c077c28;
P_0c077c28: /* original 02fe, guest PC 0x0c077c28 */
if(!s->budget--) { s->failed_pc=0x0c077c28u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c2a;
P_0c077c2a: /* original 2238, guest PC 0x0c077c2a */
if(!s->budget--) { s->failed_pc=0x0c077c2au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077c2c;
P_0c077c2c: /* original 8901, guest PC 0x0c077c2c */
if(!s->budget--) { s->failed_pc=0x0c077c2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077c32; }
goto P_0c077c2e;
P_0c077c2e: /* original a103, guest PC 0x0c077c2e */
if(!s->budget--) { s->failed_pc=0x0c077c2eu; return 0; }
goto P_0c077e38;
P_0c077c30: /* original 0009, guest PC 0x0c077c30 */
if(!s->budget--) { s->failed_pc=0x0c077c30u; return 0; }
goto P_0c077c32;
P_0c077c32: /* original 9065, guest PC 0x0c077c32 */
if(!s->budget--) { s->failed_pc=0x0c077c32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d00u,2);
goto P_0c077c34;
P_0c077c34: /* original d337, guest PC 0x0c077c34 */
if(!s->budget--) { s->failed_pc=0x0c077c34u; return 0; }
r[3]=read(ram,0x0c077d14u,4);
goto P_0c077c36;
P_0c077c36: /* original 01fe, guest PC 0x0c077c36 */
if(!s->budget--) { s->failed_pc=0x0c077c36u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077c38;
P_0c077c38: /* original 2138, guest PC 0x0c077c38 */
if(!s->budget--) { s->failed_pc=0x0c077c38u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077c3a;
P_0c077c3a: /* original 8b35, guest PC 0x0c077c3a */
if(!s->budget--) { s->failed_pc=0x0c077c3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077ca8; }
goto P_0c077c3c;
P_0c077c3c: /* original 9060, guest PC 0x0c077c3c */
if(!s->budget--) { s->failed_pc=0x0c077c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d00u,2);
goto P_0c077c3e;
P_0c077c3e: /* original d233, guest PC 0x0c077c3e */
if(!s->budget--) { s->failed_pc=0x0c077c3eu; return 0; }
r[2]=read(ram,0x0c077d0cu,4);
goto P_0c077c40;
P_0c077c40: /* original 01fe, guest PC 0x0c077c40 */
if(!s->budget--) { s->failed_pc=0x0c077c40u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077c42;
P_0c077c42: /* original 2128, guest PC 0x0c077c42 */
if(!s->budget--) { s->failed_pc=0x0c077c42u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c077c44;
P_0c077c44: /* original 8b30, guest PC 0x0c077c44 */
if(!s->budget--) { s->failed_pc=0x0c077c44u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077ca8; }
goto P_0c077c46;
P_0c077c46: /* original e050, guest PC 0x0c077c46 */
if(!s->budget--) { s->failed_pc=0x0c077c46u; return 0; }
r[0]=0x00000050u;
goto P_0c077c48;
P_0c077c48: /* original 51ff, guest PC 0x0c077c48 */
if(!s->budget--) { s->failed_pc=0x0c077c48u; return 0; }
r[1]=read(ram,r[15]+60,4);
goto P_0c077c4a;
P_0c077c4a: /* original 00fe, guest PC 0x0c077c4a */
if(!s->budget--) { s->failed_pc=0x0c077c4au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c077c4c;
P_0c077c4c: /* original 201b, guest PC 0x0c077c4c */
if(!s->budget--) { s->failed_pc=0x0c077c4cu; return 0; }
r[0]|=r[1];
goto P_0c077c4e;
P_0c077c4e: /* original c8f0, guest PC 0x0c077c4e */
if(!s->budget--) { s->failed_pc=0x0c077c4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&240u)==0)!=0);
goto P_0c077c50;
P_0c077c50: /* original 892a, guest PC 0x0c077c50 */
if(!s->budget--) { s->failed_pc=0x0c077c50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077ca8; }
goto P_0c077c52;
P_0c077c52: /* original e078, guest PC 0x0c077c52 */
if(!s->budget--) { s->failed_pc=0x0c077c52u; return 0; }
r[0]=0x00000078u;
goto P_0c077c54;
P_0c077c54: /* original e200, guest PC 0x0c077c54 */
if(!s->budget--) { s->failed_pc=0x0c077c54u; return 0; }
r[2]=0x00000000u;
goto P_0c077c56;
P_0c077c56: /* original 0f26, guest PC 0x0c077c56 */
if(!s->budget--) { s->failed_pc=0x0c077c56u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077c58;
P_0c077c58: /* original e050, guest PC 0x0c077c58 */
if(!s->budget--) { s->failed_pc=0x0c077c58u; return 0; }
r[0]=0x00000050u;
goto P_0c077c5a;
P_0c077c5a: /* original 03fe, guest PC 0x0c077c5a */
if(!s->budget--) { s->failed_pc=0x0c077c5au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c5c;
P_0c077c5c: /* original e04c, guest PC 0x0c077c5c */
if(!s->budget--) { s->failed_pc=0x0c077c5cu; return 0; }
r[0]=0x0000004cu;
goto P_0c077c5e;
P_0c077c5e: /* original 2f36, guest PC 0x0c077c5e */
if(!s->budget--) { s->failed_pc=0x0c077c5eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c60;
P_0c077c60: /* original 52f2, guest PC 0x0c077c60 */
if(!s->budget--) { s->failed_pc=0x0c077c60u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c077c62;
P_0c077c62: /* original 2f26, guest PC 0x0c077c62 */
if(!s->budget--) { s->failed_pc=0x0c077c62u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077c64;
P_0c077c64: /* original 03fe, guest PC 0x0c077c64 */
if(!s->budget--) { s->failed_pc=0x0c077c64u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c66;
P_0c077c66: /* original e04c, guest PC 0x0c077c66 */
if(!s->budget--) { s->failed_pc=0x0c077c66u; return 0; }
r[0]=0x0000004cu;
goto P_0c077c68;
P_0c077c68: /* original 2f36, guest PC 0x0c077c68 */
if(!s->budget--) { s->failed_pc=0x0c077c68u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c6a;
P_0c077c6a: /* original 02fe, guest PC 0x0c077c6a */
if(!s->budget--) { s->failed_pc=0x0c077c6au; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c6c;
P_0c077c6c: /* original 2f26, guest PC 0x0c077c6c */
if(!s->budget--) { s->failed_pc=0x0c077c6cu; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077c6e;
P_0c077c6e: /* original 9044, guest PC 0x0c077c6e */
if(!s->budget--) { s->failed_pc=0x0c077c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077c70;
P_0c077c70: /* original 03fe, guest PC 0x0c077c70 */
if(!s->budget--) { s->failed_pc=0x0c077c70u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c72;
P_0c077c72: /* original e05c, guest PC 0x0c077c72 */
if(!s->budget--) { s->failed_pc=0x0c077c72u; return 0; }
r[0]=0x0000005cu;
goto P_0c077c74;
P_0c077c74: /* original 2f36, guest PC 0x0c077c74 */
if(!s->budget--) { s->failed_pc=0x0c077c74u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c76;
P_0c077c76: /* original 02fe, guest PC 0x0c077c76 */
if(!s->budget--) { s->failed_pc=0x0c077c76u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c78;
P_0c077c78: /* original 2f26, guest PC 0x0c077c78 */
if(!s->budget--) { s->failed_pc=0x0c077c78u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077c7a;
P_0c077c7a: /* original 933f, guest PC 0x0c077c7a */
if(!s->budget--) { s->failed_pc=0x0c077c7au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077c7c;
P_0c077c7c: /* original 33fc, guest PC 0x0c077c7c */
if(!s->budget--) { s->failed_pc=0x0c077c7cu; return 0; }
r[3]+=r[15];
goto P_0c077c7e;
P_0c077c7e: /* original 2f36, guest PC 0x0c077c7e */
if(!s->budget--) { s->failed_pc=0x0c077c7eu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c80;
P_0c077c80: /* original 903c, guest PC 0x0c077c80 */
if(!s->budget--) { s->failed_pc=0x0c077c80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfcu,2);
goto P_0c077c82;
P_0c077c82: /* original 02fe, guest PC 0x0c077c82 */
if(!s->budget--) { s->failed_pc=0x0c077c82u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c84;
P_0c077c84: /* original 2f26, guest PC 0x0c077c84 */
if(!s->budget--) { s->failed_pc=0x0c077c84u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077c86;
P_0c077c86: /* original 9038, guest PC 0x0c077c86 */
if(!s->budget--) { s->failed_pc=0x0c077c86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfau,2);
goto P_0c077c88;
P_0c077c88: /* original 03fe, guest PC 0x0c077c88 */
if(!s->budget--) { s->failed_pc=0x0c077c88u; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077c8a;
P_0c077c8a: /* original 2f36, guest PC 0x0c077c8a */
if(!s->budget--) { s->failed_pc=0x0c077c8au; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c077c8c;
P_0c077c8c: /* original 9037, guest PC 0x0c077c8c */
if(!s->budget--) { s->failed_pc=0x0c077c8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c8e;
P_0c077c8e: /* original 02fe, guest PC 0x0c077c8e */
if(!s->budget--) { s->failed_pc=0x0c077c8eu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077c90;
P_0c077c90: /* original 2f26, guest PC 0x0c077c90 */
if(!s->budget--) { s->failed_pc=0x0c077c90u; return 0; }
r[15]-=4; write(ram,r[15],r[2],4);
goto P_0c077c92;
P_0c077c92: /* original 9734, guest PC 0x0c077c92 */
if(!s->budget--) { s->failed_pc=0x0c077c92u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077cfeu,2);
goto P_0c077c94;
P_0c077c94: /* original 65e3, guest PC 0x0c077c94 */
if(!s->budget--) { s->failed_pc=0x0c077c94u; return 0; }
r[5]=r[14];
goto P_0c077c96;
P_0c077c96: /* original 66d3, guest PC 0x0c077c96 */
if(!s->budget--) { s->failed_pc=0x0c077c96u; return 0; }
r[6]=r[13];
goto P_0c077c98;
P_0c077c98: /* original 37fc, guest PC 0x0c077c98 */
if(!s->budget--) { s->failed_pc=0x0c077c98u; return 0; }
r[7]+=r[15];
goto P_0c077c9a;
P_0c077c9a: /* original b269, guest PC 0x0c077c9a */
if(!s->budget--) { s->failed_pc=0x0c077c9au; return 0; }
target=0x0c078170u; r[16]=0x0c077c9eu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c077c9eu) { target=s->pc; goto dispatch; }
goto P_0c077c9e;
P_0c077c9c: /* original 64c3, guest PC 0x0c077c9c */
if(!s->budget--) { s->failed_pc=0x0c077c9cu; return 0; }
r[4]=r[12];
goto P_0c077c9e;
P_0c077c9e: /* original 2008, guest PC 0x0c077c9e */
if(!s->budget--) { s->failed_pc=0x0c077c9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c077ca0;
P_0c077ca0: /* original 8d02, guest PC 0x0c077ca0 */
if(!s->budget--) { s->failed_pc=0x0c077ca0u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000028u;
if(cond) { goto P_0c077ca8; }
goto P_0c077ca4;
P_0c077ca2: /* original 7f28, guest PC 0x0c077ca2 */
if(!s->budget--) { s->failed_pc=0x0c077ca2u; return 0; }
r[15]+=0x00000028u;
goto P_0c077ca4;
P_0c077ca4: /* original a0cc, guest PC 0x0c077ca4 */
if(!s->budget--) { s->failed_pc=0x0c077ca4u; return 0; }
goto P_0c077e40;
P_0c077ca6: /* original 0009, guest PC 0x0c077ca6 */
if(!s->budget--) { s->failed_pc=0x0c077ca6u; return 0; }
goto P_0c077ca8;
P_0c077ca8: /* original 902b, guest PC 0x0c077ca8 */
if(!s->budget--) { s->failed_pc=0x0c077ca8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d02u,2);
goto P_0c077caa;
P_0c077caa: /* original 02ec, guest PC 0x0c077caa */
if(!s->budget--) { s->failed_pc=0x0c077caau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cac;
P_0c077cac: /* original 70ff, guest PC 0x0c077cac */
if(!s->budget--) { s->failed_pc=0x0c077cacu; return 0; }
r[0]+=0xffffffffu;
goto P_0c077cae;
P_0c077cae: /* original 03ec, guest PC 0x0c077cae */
if(!s->budget--) { s->failed_pc=0x0c077caeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cb0;
P_0c077cb0: /* original 3230, guest PC 0x0c077cb0 */
if(!s->budget--) { s->failed_pc=0x0c077cb0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c077cb2;
P_0c077cb2: /* original 8901, guest PC 0x0c077cb2 */
if(!s->budget--) { s->failed_pc=0x0c077cb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077cb8; }
goto P_0c077cb4;
P_0c077cb4: /* original acee, guest PC 0x0c077cb4 */
if(!s->budget--) { s->failed_pc=0x0c077cb4u; return 0; }
goto P_0c077694;
P_0c077cb6: /* original 0009, guest PC 0x0c077cb6 */
if(!s->budget--) { s->failed_pc=0x0c077cb6u; return 0; }
goto P_0c077cb8;
P_0c077cb8: /* original 9024, guest PC 0x0c077cb8 */
if(!s->budget--) { s->failed_pc=0x0c077cb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d04u,2);
goto P_0c077cba;
P_0c077cba: /* original 03ec, guest PC 0x0c077cba */
if(!s->budget--) { s->failed_pc=0x0c077cbau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cbc;
P_0c077cbc: /* original 2338, guest PC 0x0c077cbc */
if(!s->budget--) { s->failed_pc=0x0c077cbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c077cbe;
P_0c077cbe: /* original 8903, guest PC 0x0c077cbe */
if(!s->budget--) { s->failed_pc=0x0c077cbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077cc8; }
goto P_0c077cc0;
P_0c077cc0: /* original 9021, guest PC 0x0c077cc0 */
if(!s->budget--) { s->failed_pc=0x0c077cc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d06u,2);
goto P_0c077cc2;
P_0c077cc2: /* original 03ec, guest PC 0x0c077cc2 */
if(!s->budget--) { s->failed_pc=0x0c077cc2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077cc4;
P_0c077cc4: /* original 70ce, guest PC 0x0c077cc4 */
if(!s->budget--) { s->failed_pc=0x0c077cc4u; return 0; }
r[0]+=0xffffffceu;
goto P_0c077cc6;
P_0c077cc6: /* original 0e34, guest PC 0x0c077cc6 */
if(!s->budget--) { s->failed_pc=0x0c077cc6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077cc8;
P_0c077cc8: /* original 901a, guest PC 0x0c077cc8 */
if(!s->budget--) { s->failed_pc=0x0c077cc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d00u,2);
goto P_0c077cca;
P_0c077cca: /* original d312, guest PC 0x0c077cca */
if(!s->budget--) { s->failed_pc=0x0c077ccau; return 0; }
r[3]=read(ram,0x0c077d14u,4);
goto P_0c077ccc;
P_0c077ccc: /* original 02fe, guest PC 0x0c077ccc */
if(!s->budget--) { s->failed_pc=0x0c077cccu; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077cce;
P_0c077cce: /* original 2238, guest PC 0x0c077cce */
if(!s->budget--) { s->failed_pc=0x0c077cceu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077cd0;
P_0c077cd0: /* original 8901, guest PC 0x0c077cd0 */
if(!s->budget--) { s->failed_pc=0x0c077cd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077cd6; }
goto P_0c077cd2;
P_0c077cd2: /* original a0b1, guest PC 0x0c077cd2 */
if(!s->budget--) { s->failed_pc=0x0c077cd2u; return 0; }
goto P_0c077e38;
P_0c077cd4: /* original 0009, guest PC 0x0c077cd4 */
if(!s->budget--) { s->failed_pc=0x0c077cd4u; return 0; }
goto P_0c077cd6;
P_0c077cd6: /* original 9017, guest PC 0x0c077cd6 */
if(!s->budget--) { s->failed_pc=0x0c077cd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d08u,2);
goto P_0c077cd8;
P_0c077cd8: /* original d30f, guest PC 0x0c077cd8 */
if(!s->budget--) { s->failed_pc=0x0c077cd8u; return 0; }
r[3]=read(ram,0x0c077d18u,4);
goto P_0c077cda;
P_0c077cda: /* original 01fe, guest PC 0x0c077cda */
if(!s->budget--) { s->failed_pc=0x0c077cdau; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077cdc;
P_0c077cdc: /* original 2138, guest PC 0x0c077cdc */
if(!s->budget--) { s->failed_pc=0x0c077cdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077cde;
P_0c077cde: /* original 8901, guest PC 0x0c077cde */
if(!s->budget--) { s->failed_pc=0x0c077cdeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077ce4; }
goto P_0c077ce0;
P_0c077ce0: /* original a0aa, guest PC 0x0c077ce0 */
if(!s->budget--) { s->failed_pc=0x0c077ce0u; return 0; }
goto P_0c077e38;
P_0c077ce2: /* original 0009, guest PC 0x0c077ce2 */
if(!s->budget--) { s->failed_pc=0x0c077ce2u; return 0; }
goto P_0c077ce4;
P_0c077ce4: /* original 50f1, guest PC 0x0c077ce4 */
if(!s->budget--) { s->failed_pc=0x0c077ce4u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077ce6;
P_0c077ce6: /* original c8f0, guest PC 0x0c077ce6 */
if(!s->budget--) { s->failed_pc=0x0c077ce6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&240u)==0)!=0);
goto P_0c077ce8;
P_0c077ce8: /* original 8924, guest PC 0x0c077ce8 */
if(!s->budget--) { s->failed_pc=0x0c077ce8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d34; }
goto P_0c077cea;
P_0c077cea: /* original 910d, guest PC 0x0c077cea */
if(!s->budget--) { s->failed_pc=0x0c077ceau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077d08u,2);
goto P_0c077cec;
P_0c077cec: /* original 31fc, guest PC 0x0c077cec */
if(!s->budget--) { s->failed_pc=0x0c077cecu; return 0; }
r[1]+=r[15];
goto P_0c077cee;
P_0c077cee: /* original 6012, guest PC 0x0c077cee */
if(!s->budget--) { s->failed_pc=0x0c077ceeu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077cf0;
P_0c077cf0: /* original c820, guest PC 0x0c077cf0 */
if(!s->budget--) { s->failed_pc=0x0c077cf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c077cf2;
P_0c077cf2: /* original a013, guest PC 0x0c077cf2 */
if(!s->budget--) { s->failed_pc=0x0c077cf2u; return 0; }
goto P_0c077d1c;
P_0c077cf4: /* original 0009, guest PC 0x0c077cf4 */
if(!s->budget--) { s->failed_pc=0x0c077cf4u; return 0; }
return vf3_matrix_family(0x0c077cf6u,s,ram);
P_0c077d1c: /* original 8903, guest PC 0x0c077d1c */
if(!s->budget--) { s->failed_pc=0x0c077d1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d26; }
goto P_0c077d1e;
P_0c077d1e: /* original d331, guest PC 0x0c077d1e */
if(!s->budget--) { s->failed_pc=0x0c077d1eu; return 0; }
r[3]=read(ram,0x0c077de4u,4);
goto P_0c077d20;
P_0c077d20: /* original 6232, guest PC 0x0c077d20 */
if(!s->budget--) { s->failed_pc=0x0c077d20u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c077d22;
P_0c077d22: /* original a078, guest PC 0x0c077d22 */
if(!s->budget--) { s->failed_pc=0x0c077d22u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077e16;
P_0c077d24: /* original 1e2c, guest PC 0x0c077d24 */
if(!s->budget--) { s->failed_pc=0x0c077d24u; return 0; }
write(ram,r[14]+48,r[2],4);
goto P_0c077d26;
P_0c077d26: /* original 9159, guest PC 0x0c077d26 */
if(!s->budget--) { s->failed_pc=0x0c077d26u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ddcu,2);
goto P_0c077d28;
P_0c077d28: /* original 31fc, guest PC 0x0c077d28 */
if(!s->budget--) { s->failed_pc=0x0c077d28u; return 0; }
r[1]+=r[15];
goto P_0c077d2a;
P_0c077d2a: /* original 6012, guest PC 0x0c077d2a */
if(!s->budget--) { s->failed_pc=0x0c077d2au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c077d2c;
P_0c077d2c: /* original c840, guest PC 0x0c077d2c */
if(!s->budget--) { s->failed_pc=0x0c077d2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c077d2e;
P_0c077d2e: /* original 8901, guest PC 0x0c077d2e */
if(!s->budget--) { s->failed_pc=0x0c077d2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d34; }
goto P_0c077d30;
P_0c077d30: /* original a082, guest PC 0x0c077d30 */
if(!s->budget--) { s->failed_pc=0x0c077d30u; return 0; }
goto P_0c077e38;
P_0c077d32: /* original 0009, guest PC 0x0c077d32 */
if(!s->budget--) { s->failed_pc=0x0c077d32u; return 0; }
goto P_0c077d34;
P_0c077d34: /* original 63e3, guest PC 0x0c077d34 */
if(!s->budget--) { s->failed_pc=0x0c077d34u; return 0; }
r[3]=r[14];
goto P_0c077d36;
P_0c077d36: /* original 7338, guest PC 0x0c077d36 */
if(!s->budget--) { s->failed_pc=0x0c077d36u; return 0; }
r[3]+=0x00000038u;
goto P_0c077d38;
P_0c077d38: /* original 8433, guest PC 0x0c077d38 */
if(!s->budget--) { s->failed_pc=0x0c077d38u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+3,1);
goto P_0c077d3a;
P_0c077d3a: /* original 600c, guest PC 0x0c077d3a */
if(!s->budget--) { s->failed_pc=0x0c077d3au; return 0; }
r[0]=r[0]&255u;
goto P_0c077d3c;
P_0c077d3c: /* original 1f04, guest PC 0x0c077d3c */
if(!s->budget--) { s->failed_pc=0x0c077d3cu; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c077d3e;
P_0c077d3e: /* original 50f1, guest PC 0x0c077d3e */
if(!s->budget--) { s->failed_pc=0x0c077d3eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c077d40;
P_0c077d40: /* original c810, guest PC 0x0c077d40 */
if(!s->budget--) { s->failed_pc=0x0c077d40u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c077d42;
P_0c077d42: /* original 8b30, guest PC 0x0c077d42 */
if(!s->budget--) { s->failed_pc=0x0c077d42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077da6; }
goto P_0c077d44;
P_0c077d44: /* original e044, guest PC 0x0c077d44 */
if(!s->budget--) { s->failed_pc=0x0c077d44u; return 0; }
r[0]=0x00000044u;
goto P_0c077d46;
P_0c077d46: /* original 53f1, guest PC 0x0c077d46 */
if(!s->budget--) { s->failed_pc=0x0c077d46u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077d48;
P_0c077d48: /* original 01fe, guest PC 0x0c077d48 */
if(!s->budget--) { s->failed_pc=0x0c077d48u; return 0; }
r[1]=read(ram,r[15]+r[0],4);
goto P_0c077d4a;
P_0c077d4a: /* original 2138, guest PC 0x0c077d4a */
if(!s->budget--) { s->failed_pc=0x0c077d4au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c077d4c;
P_0c077d4c: /* original 890a, guest PC 0x0c077d4c */
if(!s->budget--) { s->failed_pc=0x0c077d4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d64; }
goto P_0c077d4e;
P_0c077d4e: /* original 50f4, guest PC 0x0c077d4e */
if(!s->budget--) { s->failed_pc=0x0c077d4eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077d50;
P_0c077d50: /* original 8810, guest PC 0x0c077d50 */
if(!s->budget--) { s->failed_pc=0x0c077d50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c077d52;
P_0c077d52: /* original 8971, guest PC 0x0c077d52 */
if(!s->budget--) { s->failed_pc=0x0c077d52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077d54;
P_0c077d54: /* original e04c, guest PC 0x0c077d54 */
if(!s->budget--) { s->failed_pc=0x0c077d54u; return 0; }
r[0]=0x0000004cu;
goto P_0c077d56;
P_0c077d56: /* original d324, guest PC 0x0c077d56 */
if(!s->budget--) { s->failed_pc=0x0c077d56u; return 0; }
r[3]=read(ram,0x0c077de8u,4);
goto P_0c077d58;
P_0c077d58: /* original 02ee, guest PC 0x0c077d58 */
if(!s->budget--) { s->failed_pc=0x0c077d58u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c077d5a;
P_0c077d5a: /* original 2238, guest PC 0x0c077d5a */
if(!s->budget--) { s->failed_pc=0x0c077d5au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077d5c;
P_0c077d5c: /* original 8b6c, guest PC 0x0c077d5c */
if(!s->budget--) { s->failed_pc=0x0c077d5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077e38; }
goto P_0c077d5e;
P_0c077d5e: /* original d123, guest PC 0x0c077d5e */
if(!s->budget--) { s->failed_pc=0x0c077d5eu; return 0; }
r[1]=read(ram,0x0c077decu,4);
goto P_0c077d60;
P_0c077d60: /* original a051, guest PC 0x0c077d60 */
if(!s->budget--) { s->failed_pc=0x0c077d60u; return 0; }
goto P_0c077e06;
P_0c077d62: /* original 0009, guest PC 0x0c077d62 */
if(!s->budget--) { s->failed_pc=0x0c077d62u; return 0; }
goto P_0c077d64;
P_0c077d64: /* original e040, guest PC 0x0c077d64 */
if(!s->budget--) { s->failed_pc=0x0c077d64u; return 0; }
r[0]=0x00000040u;
goto P_0c077d66;
P_0c077d66: /* original 53f1, guest PC 0x0c077d66 */
if(!s->budget--) { s->failed_pc=0x0c077d66u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077d68;
P_0c077d68: /* original 02fe, guest PC 0x0c077d68 */
if(!s->budget--) { s->failed_pc=0x0c077d68u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077d6a;
P_0c077d6a: /* original 2238, guest PC 0x0c077d6a */
if(!s->budget--) { s->failed_pc=0x0c077d6au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077d6c;
P_0c077d6c: /* original 8915, guest PC 0x0c077d6c */
if(!s->budget--) { s->failed_pc=0x0c077d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077d9a; }
goto P_0c077d6e;
P_0c077d6e: /* original 50f4, guest PC 0x0c077d6e */
if(!s->budget--) { s->failed_pc=0x0c077d6eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077d70;
P_0c077d70: /* original 8811, guest PC 0x0c077d70 */
if(!s->budget--) { s->failed_pc=0x0c077d70u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c077d72;
P_0c077d72: /* original 8961, guest PC 0x0c077d72 */
if(!s->budget--) { s->failed_pc=0x0c077d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077d74;
P_0c077d74: /* original e048, guest PC 0x0c077d74 */
if(!s->budget--) { s->failed_pc=0x0c077d74u; return 0; }
r[0]=0x00000048u;
goto P_0c077d76;
P_0c077d76: /* original d31e, guest PC 0x0c077d76 */
if(!s->budget--) { s->failed_pc=0x0c077d76u; return 0; }
r[3]=read(ram,0x0c077df0u,4);
goto P_0c077d78;
P_0c077d78: /* original 02fe, guest PC 0x0c077d78 */
if(!s->budget--) { s->failed_pc=0x0c077d78u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077d7a;
P_0c077d7a: /* original 2238, guest PC 0x0c077d7a */
if(!s->budget--) { s->failed_pc=0x0c077d7au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077d7c;
P_0c077d7c: /* original 8b02, guest PC 0x0c077d7c */
if(!s->budget--) { s->failed_pc=0x0c077d7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077d84; }
goto P_0c077d7e;
P_0c077d7e: /* original d21d, guest PC 0x0c077d7e */
if(!s->budget--) { s->failed_pc=0x0c077d7eu; return 0; }
r[2]=read(ram,0x0c077df4u,4);
goto P_0c077d80;
P_0c077d80: /* original a02a, guest PC 0x0c077d80 */
if(!s->budget--) { s->failed_pc=0x0c077d80u; return 0; }
goto P_0c077dd8;
P_0c077d82: /* original 0009, guest PC 0x0c077d82 */
if(!s->budget--) { s->failed_pc=0x0c077d82u; return 0; }
goto P_0c077d84;
P_0c077d84: /* original e061, guest PC 0x0c077d84 */
if(!s->budget--) { s->failed_pc=0x0c077d84u; return 0; }
r[0]=0x00000061u;
goto P_0c077d86;
P_0c077d86: /* original 00ec, guest PC 0x0c077d86 */
if(!s->budget--) { s->failed_pc=0x0c077d86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077d88;
P_0c077d88: /* original 600c, guest PC 0x0c077d88 */
if(!s->budget--) { s->failed_pc=0x0c077d88u; return 0; }
r[0]=r[0]&255u;
goto P_0c077d8a;
P_0c077d8a: /* original 880c, guest PC 0x0c077d8a */
if(!s->budget--) { s->failed_pc=0x0c077d8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c077d8c;
P_0c077d8c: /* original 8b02, guest PC 0x0c077d8c */
if(!s->budget--) { s->failed_pc=0x0c077d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077d94; }
goto P_0c077d8e;
P_0c077d8e: /* original 9226, guest PC 0x0c077d8e */
if(!s->budget--) { s->failed_pc=0x0c077d8eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ddeu,2);
goto P_0c077d90;
P_0c077d90: /* original a022, guest PC 0x0c077d90 */
if(!s->budget--) { s->failed_pc=0x0c077d90u; return 0; }
goto P_0c077dd8;
P_0c077d92: /* original 0009, guest PC 0x0c077d92 */
if(!s->budget--) { s->failed_pc=0x0c077d92u; return 0; }
goto P_0c077d94;
P_0c077d94: /* original 9124, guest PC 0x0c077d94 */
if(!s->budget--) { s->failed_pc=0x0c077d94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077de0u,2);
goto P_0c077d96;
P_0c077d96: /* original a036, guest PC 0x0c077d96 */
if(!s->budget--) { s->failed_pc=0x0c077d96u; return 0; }
goto P_0c077e06;
P_0c077d98: /* original 0009, guest PC 0x0c077d98 */
if(!s->budget--) { s->failed_pc=0x0c077d98u; return 0; }
goto P_0c077d9a;
P_0c077d9a: /* original 50f4, guest PC 0x0c077d9a */
if(!s->budget--) { s->failed_pc=0x0c077d9au; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077d9c;
P_0c077d9c: /* original 8811, guest PC 0x0c077d9c */
if(!s->budget--) { s->failed_pc=0x0c077d9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c077d9e;
P_0c077d9e: /* original 894b, guest PC 0x0c077d9e */
if(!s->budget--) { s->failed_pc=0x0c077d9eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077da0;
P_0c077da0: /* original d315, guest PC 0x0c077da0 */
if(!s->budget--) { s->failed_pc=0x0c077da0u; return 0; }
r[3]=read(ram,0x0c077df8u,4);
goto P_0c077da2;
P_0c077da2: /* original a009, guest PC 0x0c077da2 */
if(!s->budget--) { s->failed_pc=0x0c077da2u; return 0; }
goto P_0c077db8;
P_0c077da4: /* original 0009, guest PC 0x0c077da4 */
if(!s->budget--) { s->failed_pc=0x0c077da4u; return 0; }
goto P_0c077da6;
P_0c077da6: /* original e044, guest PC 0x0c077da6 */
if(!s->budget--) { s->failed_pc=0x0c077da6u; return 0; }
r[0]=0x00000044u;
goto P_0c077da8;
P_0c077da8: /* original 53f1, guest PC 0x0c077da8 */
if(!s->budget--) { s->failed_pc=0x0c077da8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077daa;
P_0c077daa: /* original 02fe, guest PC 0x0c077daa */
if(!s->budget--) { s->failed_pc=0x0c077daau; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077dac;
P_0c077dac: /* original 2238, guest PC 0x0c077dac */
if(!s->budget--) { s->failed_pc=0x0c077dacu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077dae;
P_0c077dae: /* original 8905, guest PC 0x0c077dae */
if(!s->budget--) { s->failed_pc=0x0c077daeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077dbc; }
goto P_0c077db0;
P_0c077db0: /* original 50f4, guest PC 0x0c077db0 */
if(!s->budget--) { s->failed_pc=0x0c077db0u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077db2;
P_0c077db2: /* original 8812, guest PC 0x0c077db2 */
if(!s->budget--) { s->failed_pc=0x0c077db2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c077db4;
P_0c077db4: /* original 8940, guest PC 0x0c077db4 */
if(!s->budget--) { s->failed_pc=0x0c077db4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077db6;
P_0c077db6: /* original d311, guest PC 0x0c077db6 */
if(!s->budget--) { s->failed_pc=0x0c077db6u; return 0; }
r[3]=read(ram,0x0c077dfcu,4);
goto P_0c077db8;
P_0c077db8: /* original a026, guest PC 0x0c077db8 */
if(!s->budget--) { s->failed_pc=0x0c077db8u; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c077e08;
P_0c077dba: /* original 1f3e, guest PC 0x0c077dba */
if(!s->budget--) { s->failed_pc=0x0c077dbau; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c077dbc;
P_0c077dbc: /* original e040, guest PC 0x0c077dbc */
if(!s->budget--) { s->failed_pc=0x0c077dbcu; return 0; }
r[0]=0x00000040u;
goto P_0c077dbe;
P_0c077dbe: /* original 53f1, guest PC 0x0c077dbe */
if(!s->budget--) { s->failed_pc=0x0c077dbeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c077dc0;
P_0c077dc0: /* original 02fe, guest PC 0x0c077dc0 */
if(!s->budget--) { s->failed_pc=0x0c077dc0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077dc2;
P_0c077dc2: /* original 2238, guest PC 0x0c077dc2 */
if(!s->budget--) { s->failed_pc=0x0c077dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077dc4;
P_0c077dc4: /* original 891e, guest PC 0x0c077dc4 */
if(!s->budget--) { s->failed_pc=0x0c077dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e04; }
goto P_0c077dc6;
P_0c077dc6: /* original 50f4, guest PC 0x0c077dc6 */
if(!s->budget--) { s->failed_pc=0x0c077dc6u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c077dc8;
P_0c077dc8: /* original 8813, guest PC 0x0c077dc8 */
if(!s->budget--) { s->failed_pc=0x0c077dc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c077dca;
P_0c077dca: /* original 8935, guest PC 0x0c077dca */
if(!s->budget--) { s->failed_pc=0x0c077dcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c077e38; }
goto P_0c077dcc;
P_0c077dcc: /* original e048, guest PC 0x0c077dcc */
if(!s->budget--) { s->failed_pc=0x0c077dccu; return 0; }
r[0]=0x00000048u;
goto P_0c077dce;
P_0c077dce: /* original d308, guest PC 0x0c077dce */
if(!s->budget--) { s->failed_pc=0x0c077dceu; return 0; }
r[3]=read(ram,0x0c077df0u,4);
goto P_0c077dd0;
P_0c077dd0: /* original 02fe, guest PC 0x0c077dd0 */
if(!s->budget--) { s->failed_pc=0x0c077dd0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c077dd2;
P_0c077dd2: /* original 2238, guest PC 0x0c077dd2 */
if(!s->budget--) { s->failed_pc=0x0c077dd2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c077dd4;
P_0c077dd4: /* original 8bd6, guest PC 0x0c077dd4 */
if(!s->budget--) { s->failed_pc=0x0c077dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c077d84; }
goto P_0c077dd6;
P_0c077dd6: /* original d20a, guest PC 0x0c077dd6 */
if(!s->budget--) { s->failed_pc=0x0c077dd6u; return 0; }
r[2]=read(ram,0x0c077e00u,4);
goto P_0c077dd8;
P_0c077dd8: /* original a016, guest PC 0x0c077dd8 */
if(!s->budget--) { s->failed_pc=0x0c077dd8u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c077e08;
P_0c077dda: /* original 1f2e, guest PC 0x0c077dda */
if(!s->budget--) { s->failed_pc=0x0c077ddau; return 0; }
write(ram,r[15]+56,r[2],4);
return vf3_matrix_family(0x0c077ddcu,s,ram);
P_0c077e04: /* original d13d, guest PC 0x0c077e04 */
if(!s->budget--) { s->failed_pc=0x0c077e04u; return 0; }
r[1]=read(ram,0x0c077efcu,4);
goto P_0c077e06;
P_0c077e06: /* original 1f1e, guest PC 0x0c077e06 */
if(!s->budget--) { s->failed_pc=0x0c077e06u; return 0; }
write(ram,r[15]+56,r[1],4);
goto P_0c077e08;
P_0c077e08: /* original 53fe, guest PC 0x0c077e08 */
if(!s->budget--) { s->failed_pc=0x0c077e08u; return 0; }
r[3]=read(ram,r[15]+56,4);
goto P_0c077e0a;
P_0c077e0a: /* original a015, guest PC 0x0c077e0a */
if(!s->budget--) { s->failed_pc=0x0c077e0au; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c077e38;
P_0c077e0c: /* original 1e3c, guest PC 0x0c077e0c */
if(!s->budget--) { s->failed_pc=0x0c077e0cu; return 0; }
write(ram,r[14]+48,r[3],4);
goto P_0c077e0e;
P_0c077e0e: /* original 906c, guest PC 0x0c077e0e */
if(!s->budget--) { s->failed_pc=0x0c077e0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077eeau,2);
goto P_0c077e10;
P_0c077e10: /* original 01ec, guest PC 0x0c077e10 */
if(!s->budget--) { s->failed_pc=0x0c077e10u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077e12;
P_0c077e12: /* original 7001, guest PC 0x0c077e12 */
if(!s->budget--) { s->failed_pc=0x0c077e12u; return 0; }
r[0]+=0x00000001u;
goto P_0c077e14;
P_0c077e14: /* original 0e14, guest PC 0x0c077e14 */
if(!s->budget--) { s->failed_pc=0x0c077e14u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c077e16;
P_0c077e16: /* original 9069, guest PC 0x0c077e16 */
if(!s->budget--) { s->failed_pc=0x0c077e16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077eecu,2);
goto P_0c077e18;
P_0c077e18: /* original 03ec, guest PC 0x0c077e18 */
if(!s->budget--) { s->failed_pc=0x0c077e18u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077e1a;
P_0c077e1a: /* original 7001, guest PC 0x0c077e1a */
if(!s->budget--) { s->failed_pc=0x0c077e1au; return 0; }
r[0]+=0x00000001u;
goto P_0c077e1c;
P_0c077e1c: /* original 0e34, guest PC 0x0c077e1c */
if(!s->budget--) { s->failed_pc=0x0c077e1cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077e1e;
P_0c077e1e: /* original 70ff, guest PC 0x0c077e1e */
if(!s->budget--) { s->failed_pc=0x0c077e1eu; return 0; }
r[0]+=0xffffffffu;
goto P_0c077e20;
P_0c077e20: /* original 02ec, guest PC 0x0c077e20 */
if(!s->budget--) { s->failed_pc=0x0c077e20u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c077e22;
P_0c077e22: /* original e06c, guest PC 0x0c077e22 */
if(!s->budget--) { s->failed_pc=0x0c077e22u; return 0; }
r[0]=0x0000006cu;
goto P_0c077e24;
P_0c077e24: /* original 622c, guest PC 0x0c077e24 */
if(!s->budget--) { s->failed_pc=0x0c077e24u; return 0; }
r[2]=r[2]&255u;
goto P_0c077e26;
P_0c077e26: /* original 0f26, guest PC 0x0c077e26 */
if(!s->budget--) { s->failed_pc=0x0c077e26u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c077e28;
P_0c077e28: /* original e06c, guest PC 0x0c077e28 */
if(!s->budget--) { s->failed_pc=0x0c077e28u; return 0; }
r[0]=0x0000006cu;
goto P_0c077e2a;
P_0c077e2a: /* original 03fc, guest PC 0x0c077e2a */
if(!s->budget--) { s->failed_pc=0x0c077e2au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077e2c;
P_0c077e2c: /* original 905f, guest PC 0x0c077e2c */
if(!s->budget--) { s->failed_pc=0x0c077e2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077eeeu,2);
goto P_0c077e2e;
P_0c077e2e: /* original 0e34, guest PC 0x0c077e2e */
if(!s->budget--) { s->failed_pc=0x0c077e2eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c077e30;
P_0c077e30: /* original e06c, guest PC 0x0c077e30 */
if(!s->budget--) { s->failed_pc=0x0c077e30u; return 0; }
r[0]=0x0000006cu;
goto P_0c077e32;
P_0c077e32: /* original 02fc, guest PC 0x0c077e32 */
if(!s->budget--) { s->failed_pc=0x0c077e32u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c077e34;
P_0c077e34: /* original 905c, guest PC 0x0c077e34 */
if(!s->budget--) { s->failed_pc=0x0c077e34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef0u,2);
goto P_0c077e36;
P_0c077e36: /* original 0e24, guest PC 0x0c077e36 */
if(!s->budget--) { s->failed_pc=0x0c077e36u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c077e38;
P_0c077e38: /* original 905b, guest PC 0x0c077e38 */
if(!s->budget--) { s->failed_pc=0x0c077e38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef2u,2);
goto P_0c077e3a;
P_0c077e3a: /* original 03fe, guest PC 0x0c077e3a */
if(!s->budget--) { s->failed_pc=0x0c077e3au; return 0; }
r[3]=read(ram,r[15]+r[0],4);
goto P_0c077e3c;
P_0c077e3c: /* original 905a, guest PC 0x0c077e3c */
if(!s->budget--) { s->failed_pc=0x0c077e3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef4u,2);
goto P_0c077e3e;
P_0c077e3e: /* original 0e36, guest PC 0x0c077e3e */
if(!s->budget--) { s->failed_pc=0x0c077e3eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c077e40;
P_0c077e40: /* original 9159, guest PC 0x0c077e40 */
if(!s->budget--) { s->failed_pc=0x0c077e40u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c077ef6u,2);
goto P_0c077e42;
P_0c077e42: /* original 3f1c, guest PC 0x0c077e42 */
if(!s->budget--) { s->failed_pc=0x0c077e42u; return 0; }
r[15]+=r[1];
goto P_0c077e44;
P_0c077e44: /* original 4f26, guest PC 0x0c077e44 */
if(!s->budget--) { s->failed_pc=0x0c077e44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c077e46;
P_0c077e46: /* original 6cf6, guest PC 0x0c077e46 */
if(!s->budget--) { s->failed_pc=0x0c077e46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c077e48;
P_0c077e48: /* original 6df6, guest PC 0x0c077e48 */
if(!s->budget--) { s->failed_pc=0x0c077e48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c077e4a;
P_0c077e4a: /* original 000b, guest PC 0x0c077e4a */
if(!s->budget--) { s->failed_pc=0x0c077e4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c077e4c: /* original 6ef6, guest PC 0x0c077e4c */
if(!s->budget--) { s->failed_pc=0x0c077e4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c077e4e;
P_0c077e4e: /* original 2fe6, guest PC 0x0c077e4e */
if(!s->budget--) { s->failed_pc=0x0c077e4eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c077e50;
P_0c077e50: /* original 2fd6, guest PC 0x0c077e50 */
if(!s->budget--) { s->failed_pc=0x0c077e50u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c077e52;
P_0c077e52: /* original 2fc6, guest PC 0x0c077e52 */
if(!s->budget--) { s->failed_pc=0x0c077e52u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c077e54;
P_0c077e54: /* original 2fb6, guest PC 0x0c077e54 */
if(!s->budget--) { s->failed_pc=0x0c077e54u; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c077e56;
P_0c077e56: /* original 2fa6, guest PC 0x0c077e56 */
if(!s->budget--) { s->failed_pc=0x0c077e56u; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c077e58;
P_0c077e58: /* original 2f96, guest PC 0x0c077e58 */
if(!s->budget--) { s->failed_pc=0x0c077e58u; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c077e5a;
P_0c077e5a: /* original 2f86, guest PC 0x0c077e5a */
if(!s->budget--) { s->failed_pc=0x0c077e5au; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
return vf3_matrix_family(0x0c077e5cu,s,ram);
P_0c078044: /* original 2fe6, guest PC 0x0c078044 */
if(!s->budget--) { s->failed_pc=0x0c078044u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c078046;
P_0c078046: /* original e40f, guest PC 0x0c078046 */
if(!s->budget--) { s->failed_pc=0x0c078046u; return 0; }
r[4]=0x0000000fu;
goto P_0c078048;
P_0c078048: /* original 2fd6, guest PC 0x0c078048 */
if(!s->budget--) { s->failed_pc=0x0c078048u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07804a;
P_0c07804a: /* original 9e86, guest PC 0x0c07804a */
if(!s->budget--) { s->failed_pc=0x0c07804au; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815au,2);
goto P_0c07804c;
P_0c07804c: /* original 56f2, guest PC 0x0c07804c */
if(!s->budget--) { s->failed_pc=0x0c07804cu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c07804e;
P_0c07804e: /* original 3e5c, guest PC 0x0c07804e */
if(!s->budget--) { s->failed_pc=0x0c07804eu; return 0; }
r[14]+=r[5];
goto P_0c078050;
P_0c078050: /* original 3e7c, guest PC 0x0c078050 */
if(!s->budget--) { s->failed_pc=0x0c078050u; return 0; }
r[14]+=r[7];
goto P_0c078052;
P_0c078052: /* original 6ee0, guest PC 0x0c078052 */
if(!s->budget--) { s->failed_pc=0x0c078052u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[14]=tmp;
goto P_0c078054;
P_0c078054: /* original 6eec, guest PC 0x0c078054 */
if(!s->budget--) { s->failed_pc=0x0c078054u; return 0; }
r[14]=r[14]&255u;
goto P_0c078056;
P_0c078056: /* original 2ee8, guest PC 0x0c078056 */
if(!s->budget--) { s->failed_pc=0x0c078056u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c078058;
P_0c078058: /* original 8f1a, guest PC 0x0c078058 */
if(!s->budget--) { s->failed_pc=0x0c078058u; return 0; }
cond=r[17]&1u;
r[4]&=r[6];
if(!cond) { goto P_0c078090; }
goto P_0c07805c;
P_0c07805a: /* original 2469, guest PC 0x0c07805a */
if(!s->budget--) { s->failed_pc=0x0c07805au; return 0; }
r[4]&=r[6];
goto P_0c07805c;
P_0c07805c: /* original 2448, guest PC 0x0c07805c */
if(!s->budget--) { s->failed_pc=0x0c07805cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07805e;
P_0c07805e: /* original 890d, guest PC 0x0c07805e */
if(!s->budget--) { s->failed_pc=0x0c07805eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07807c; }
goto P_0c078060;
P_0c078060: /* original 6043, guest PC 0x0c078060 */
if(!s->budget--) { s->failed_pc=0x0c078060u; return 0; }
r[0]=r[4];
goto P_0c078062;
P_0c078062: /* original 880f, guest PC 0x0c078062 */
if(!s->budget--) { s->failed_pc=0x0c078062u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c078064;
P_0c078064: /* original 890a, guest PC 0x0c078064 */
if(!s->budget--) { s->failed_pc=0x0c078064u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07807c; }
goto P_0c078066;
P_0c078066: /* original 9278, guest PC 0x0c078066 */
if(!s->budget--) { s->failed_pc=0x0c078066u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815au,2);
goto P_0c078068;
P_0c078068: /* original e301, guest PC 0x0c078068 */
if(!s->budget--) { s->failed_pc=0x0c078068u; return 0; }
r[3]=0x00000001u;
goto P_0c07806a;
P_0c07806a: /* original 325c, guest PC 0x0c07806a */
if(!s->budget--) { s->failed_pc=0x0c07806au; return 0; }
r[2]+=r[5];
goto P_0c07806c;
P_0c07806c: /* original 327c, guest PC 0x0c07806c */
if(!s->budget--) { s->failed_pc=0x0c07806cu; return 0; }
r[2]+=r[7];
goto P_0c07806e;
P_0c07806e: /* original 2230, guest PC 0x0c07806e */
if(!s->budget--) { s->failed_pc=0x0c07806eu; return 0; }
write(ram,r[2],r[3],1);
goto P_0c078070;
P_0c078070: /* original e3f0, guest PC 0x0c078070 */
if(!s->budget--) { s->failed_pc=0x0c078070u; return 0; }
r[3]=0xfffffff0u;
goto P_0c078072;
P_0c078072: /* original 9273, guest PC 0x0c078072 */
if(!s->budget--) { s->failed_pc=0x0c078072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815cu,2);
goto P_0c078074;
P_0c078074: /* original 2639, guest PC 0x0c078074 */
if(!s->budget--) { s->failed_pc=0x0c078074u; return 0; }
r[6]&=r[3];
goto P_0c078076;
P_0c078076: /* original 325c, guest PC 0x0c078076 */
if(!s->budget--) { s->failed_pc=0x0c078076u; return 0; }
r[2]+=r[5];
goto P_0c078078;
P_0c078078: /* original 327c, guest PC 0x0c078078 */
if(!s->budget--) { s->failed_pc=0x0c078078u; return 0; }
r[2]+=r[7];
goto P_0c07807a;
P_0c07807a: /* original 2240, guest PC 0x0c07807a */
if(!s->budget--) { s->failed_pc=0x0c07807au; return 0; }
write(ram,r[2],r[4],1);
goto P_0c07807c;
P_0c07807c: /* original 906f, guest PC 0x0c07807c */
if(!s->budget--) { s->failed_pc=0x0c07807cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815eu,2);
goto P_0c07807e;
P_0c07807e: /* original 936f, guest PC 0x0c07807e */
if(!s->budget--) { s->failed_pc=0x0c07807eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078160u,2);
goto P_0c078080;
P_0c078080: /* original 045c, guest PC 0x0c078080 */
if(!s->budget--) { s->failed_pc=0x0c078080u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c078082;
P_0c078082: /* original 7033, guest PC 0x0c078082 */
if(!s->budget--) { s->failed_pc=0x0c078082u; return 0; }
r[0]+=0x00000033u;
goto P_0c078084;
P_0c078084: /* original 335c, guest PC 0x0c078084 */
if(!s->budget--) { s->failed_pc=0x0c078084u; return 0; }
r[3]+=r[5];
goto P_0c078086;
P_0c078086: /* original 373c, guest PC 0x0c078086 */
if(!s->budget--) { s->failed_pc=0x0c078086u; return 0; }
r[7]+=r[3];
goto P_0c078088;
P_0c078088: /* original 644c, guest PC 0x0c078088 */
if(!s->budget--) { s->failed_pc=0x0c078088u; return 0; }
r[4]=r[4]&255u;
goto P_0c07808a;
P_0c07808a: /* original 2740, guest PC 0x0c07808a */
if(!s->budget--) { s->failed_pc=0x0c07808au; return 0; }
write(ram,r[7],r[4],1);
goto P_0c07808c;
P_0c07808c: /* original a03c, guest PC 0x0c07808c */
if(!s->budget--) { s->failed_pc=0x0c07808cu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c078108;
P_0c07808e: /* original 0544, guest PC 0x0c07808e */
if(!s->budget--) { s->failed_pc=0x0c07808eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c078090;
P_0c078090: /* original 9d64, guest PC 0x0c078090 */
if(!s->budget--) { s->failed_pc=0x0c078090u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815cu,2);
goto P_0c078092;
P_0c078092: /* original d336, guest PC 0x0c078092 */
if(!s->budget--) { s->failed_pc=0x0c078092u; return 0; }
r[3]=read(ram,0x0c07816cu,4);
goto P_0c078094;
P_0c078094: /* original 3d5c, guest PC 0x0c078094 */
if(!s->budget--) { s->failed_pc=0x0c078094u; return 0; }
r[13]+=r[5];
goto P_0c078096;
P_0c078096: /* original 52f3, guest PC 0x0c078096 */
if(!s->budget--) { s->failed_pc=0x0c078096u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c078098;
P_0c078098: /* original 3d7c, guest PC 0x0c078098 */
if(!s->budget--) { s->failed_pc=0x0c078098u; return 0; }
r[13]+=r[7];
goto P_0c07809a;
P_0c07809a: /* original 6dd0, guest PC 0x0c07809a */
if(!s->budget--) { s->failed_pc=0x0c07809au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]=tmp;
goto P_0c07809c;
P_0c07809c: /* original 2238, guest PC 0x0c07809c */
if(!s->budget--) { s->failed_pc=0x0c07809cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07809e;
P_0c07809e: /* original 8f13, guest PC 0x0c07809e */
if(!s->budget--) { s->failed_pc=0x0c07809eu; return 0; }
cond=r[17]&1u;
r[13]=r[13]&255u;
if(!cond) { goto P_0c0780c8; }
goto P_0c0780a2;
P_0c0780a0: /* original 6ddc, guest PC 0x0c0780a0 */
if(!s->budget--) { s->failed_pc=0x0c0780a0u; return 0; }
r[13]=r[13]&255u;
goto P_0c0780a2;
P_0c0780a2: /* original 60d3, guest PC 0x0c0780a2 */
if(!s->budget--) { s->failed_pc=0x0c0780a2u; return 0; }
r[0]=r[13];
goto P_0c0780a4;
P_0c0780a4: /* original 8804, guest PC 0x0c0780a4 */
if(!s->budget--) { s->failed_pc=0x0c0780a4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0780a6;
P_0c0780a6: /* original 8b0f, guest PC 0x0c0780a6 */
if(!s->budget--) { s->failed_pc=0x0c0780a6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0780c8; }
goto P_0c0780a8;
P_0c0780a8: /* original 50f4, guest PC 0x0c0780a8 */
if(!s->budget--) { s->failed_pc=0x0c0780a8u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0780aa;
P_0c0780aa: /* original c804, guest PC 0x0c0780aa */
if(!s->budget--) { s->failed_pc=0x0c0780aau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0780ac;
P_0c0780ac: /* original 8b0c, guest PC 0x0c0780ac */
if(!s->budget--) { s->failed_pc=0x0c0780acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0780c8; }
goto P_0c0780ae;
P_0c0780ae: /* original 6043, guest PC 0x0c0780ae */
if(!s->budget--) { s->failed_pc=0x0c0780aeu; return 0; }
r[0]=r[4];
goto P_0c0780b0;
P_0c0780b0: /* original 8801, guest PC 0x0c0780b0 */
if(!s->budget--) { s->failed_pc=0x0c0780b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0780b2;
P_0c0780b2: /* original 8b09, guest PC 0x0c0780b2 */
if(!s->budget--) { s->failed_pc=0x0c0780b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0780c8; }
goto P_0c0780b4;
P_0c0780b4: /* original 9053, guest PC 0x0c0780b4 */
if(!s->budget--) { s->failed_pc=0x0c0780b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815eu,2);
goto P_0c0780b6;
P_0c0780b6: /* original 9353, guest PC 0x0c0780b6 */
if(!s->budget--) { s->failed_pc=0x0c0780b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078160u,2);
goto P_0c0780b8;
P_0c0780b8: /* original 0e5c, guest PC 0x0c0780b8 */
if(!s->budget--) { s->failed_pc=0x0c0780b8u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0780ba;
P_0c0780ba: /* original 7033, guest PC 0x0c0780ba */
if(!s->budget--) { s->failed_pc=0x0c0780bau; return 0; }
r[0]+=0x00000033u;
goto P_0c0780bc;
P_0c0780bc: /* original 335c, guest PC 0x0c0780bc */
if(!s->budget--) { s->failed_pc=0x0c0780bcu; return 0; }
r[3]+=r[5];
goto P_0c0780be;
P_0c0780be: /* original 337c, guest PC 0x0c0780be */
if(!s->budget--) { s->failed_pc=0x0c0780beu; return 0; }
r[3]+=r[7];
goto P_0c0780c0;
P_0c0780c0: /* original 6eec, guest PC 0x0c0780c0 */
if(!s->budget--) { s->failed_pc=0x0c0780c0u; return 0; }
r[14]=r[14]&255u;
goto P_0c0780c2;
P_0c0780c2: /* original 23e0, guest PC 0x0c0780c2 */
if(!s->budget--) { s->failed_pc=0x0c0780c2u; return 0; }
write(ram,r[3],r[14],1);
goto P_0c0780c4;
P_0c0780c4: /* original a01a, guest PC 0x0c0780c4 */
if(!s->budget--) { s->failed_pc=0x0c0780c4u; return 0; }
write(ram,r[5]+r[0],r[14],1);
goto P_0c0780fc;
P_0c0780c6: /* original 05e4, guest PC 0x0c0780c6 */
if(!s->budget--) { s->failed_pc=0x0c0780c6u; return 0; }
write(ram,r[5]+r[0],r[14],1);
goto P_0c0780c8;
P_0c0780c8: /* original 60d3, guest PC 0x0c0780c8 */
if(!s->budget--) { s->failed_pc=0x0c0780c8u; return 0; }
r[0]=r[13];
goto P_0c0780ca;
P_0c0780ca: /* original 8806, guest PC 0x0c0780ca */
if(!s->budget--) { s->failed_pc=0x0c0780cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0780cc;
P_0c0780cc: /* original 8b05, guest PC 0x0c0780cc */
if(!s->budget--) { s->failed_pc=0x0c0780ccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0780da; }
goto P_0c0780ce;
P_0c0780ce: /* original 50f4, guest PC 0x0c0780ce */
if(!s->budget--) { s->failed_pc=0x0c0780ceu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0780d0;
P_0c0780d0: /* original c90f, guest PC 0x0c0780d0 */
if(!s->budget--) { s->failed_pc=0x0c0780d0u; return 0; }
r[0]&=15u;
goto P_0c0780d2;
P_0c0780d2: /* original 8802, guest PC 0x0c0780d2 */
if(!s->budget--) { s->failed_pc=0x0c0780d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0780d4;
P_0c0780d4: /* original 8b01, guest PC 0x0c0780d4 */
if(!s->budget--) { s->failed_pc=0x0c0780d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0780da; }
goto P_0c0780d6;
P_0c0780d6: /* original 9244, guest PC 0x0c0780d6 */
if(!s->budget--) { s->failed_pc=0x0c0780d6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c078162u,2);
goto P_0c0780d8;
P_0c0780d8: /* original 262b, guest PC 0x0c0780d8 */
if(!s->budget--) { s->failed_pc=0x0c0780d8u; return 0; }
r[6]|=r[2];
goto P_0c0780da;
P_0c0780da: /* original 24db, guest PC 0x0c0780da */
if(!s->budget--) { s->failed_pc=0x0c0780dau; return 0; }
r[4]|=r[13];
goto P_0c0780dc;
P_0c0780dc: /* original 6043, guest PC 0x0c0780dc */
if(!s->budget--) { s->failed_pc=0x0c0780dcu; return 0; }
r[0]=r[4];
goto P_0c0780de;
P_0c0780de: /* original 880f, guest PC 0x0c0780de */
if(!s->budget--) { s->failed_pc=0x0c0780deu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c0780e0;
P_0c0780e0: /* original 890c, guest PC 0x0c0780e0 */
if(!s->budget--) { s->failed_pc=0x0c0780e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0780fc; }
goto P_0c0780e2;
P_0c0780e2: /* original 4e10, guest PC 0x0c0780e2 */
if(!s->budget--) { s->failed_pc=0x0c0780e2u; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c0780e4;
P_0c0780e4: /* original 890a, guest PC 0x0c0780e4 */
if(!s->budget--) { s->failed_pc=0x0c0780e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0780fc; }
goto P_0c0780e6;
P_0c0780e6: /* original 9338, guest PC 0x0c0780e6 */
if(!s->budget--) { s->failed_pc=0x0c0780e6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815au,2);
goto P_0c0780e8;
P_0c0780e8: /* original 335c, guest PC 0x0c0780e8 */
if(!s->budget--) { s->failed_pc=0x0c0780e8u; return 0; }
r[3]+=r[5];
goto P_0c0780ea;
P_0c0780ea: /* original 337c, guest PC 0x0c0780ea */
if(!s->budget--) { s->failed_pc=0x0c0780eau; return 0; }
r[3]+=r[7];
goto P_0c0780ec;
P_0c0780ec: /* original 23e0, guest PC 0x0c0780ec */
if(!s->budget--) { s->failed_pc=0x0c0780ecu; return 0; }
write(ram,r[3],r[14],1);
goto P_0c0780ee;
P_0c0780ee: /* original e3f0, guest PC 0x0c0780ee */
if(!s->budget--) { s->failed_pc=0x0c0780eeu; return 0; }
r[3]=0xfffffff0u;
goto P_0c0780f0;
P_0c0780f0: /* original 9234, guest PC 0x0c0780f0 */
if(!s->budget--) { s->failed_pc=0x0c0780f0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815cu,2);
goto P_0c0780f2;
P_0c0780f2: /* original 325c, guest PC 0x0c0780f2 */
if(!s->budget--) { s->failed_pc=0x0c0780f2u; return 0; }
r[2]+=r[5];
goto P_0c0780f4;
P_0c0780f4: /* original 372c, guest PC 0x0c0780f4 */
if(!s->budget--) { s->failed_pc=0x0c0780f4u; return 0; }
r[7]+=r[2];
goto P_0c0780f6;
P_0c0780f6: /* original 2740, guest PC 0x0c0780f6 */
if(!s->budget--) { s->failed_pc=0x0c0780f6u; return 0; }
write(ram,r[7],r[4],1);
goto P_0c0780f8;
P_0c0780f8: /* original a006, guest PC 0x0c0780f8 */
if(!s->budget--) { s->failed_pc=0x0c0780f8u; return 0; }
r[6]&=r[3];
goto P_0c078108;
P_0c0780fa: /* original 2639, guest PC 0x0c0780fa */
if(!s->budget--) { s->failed_pc=0x0c0780fau; return 0; }
r[6]&=r[3];
goto P_0c0780fc;
P_0c0780fc: /* original 912d, guest PC 0x0c0780fc */
if(!s->budget--) { s->failed_pc=0x0c0780fcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07815au,2);
goto P_0c0780fe;
P_0c0780fe: /* original e300, guest PC 0x0c0780fe */
if(!s->budget--) { s->failed_pc=0x0c0780feu; return 0; }
r[3]=0x00000000u;
goto P_0c078100;
P_0c078100: /* original 264b, guest PC 0x0c078100 */
if(!s->budget--) { s->failed_pc=0x0c078100u; return 0; }
r[6]|=r[4];
goto P_0c078102;
P_0c078102: /* original 315c, guest PC 0x0c078102 */
if(!s->budget--) { s->failed_pc=0x0c078102u; return 0; }
r[1]+=r[5];
goto P_0c078104;
P_0c078104: /* original 371c, guest PC 0x0c078104 */
if(!s->budget--) { s->failed_pc=0x0c078104u; return 0; }
r[7]+=r[1];
goto P_0c078106;
P_0c078106: /* original 2730, guest PC 0x0c078106 */
if(!s->budget--) { s->failed_pc=0x0c078106u; return 0; }
write(ram,r[7],r[3],1);
goto P_0c078108;
P_0c078108: /* original 6df6, guest PC 0x0c078108 */
if(!s->budget--) { s->failed_pc=0x0c078108u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07810a;
P_0c07810a: /* original 6063, guest PC 0x0c07810a */
if(!s->budget--) { s->failed_pc=0x0c07810au; return 0; }
r[0]=r[6];
goto P_0c07810c;
P_0c07810c: /* original 000b, guest PC 0x0c07810c */
if(!s->budget--) { s->failed_pc=0x0c07810cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07810e: /* original 6ef6, guest PC 0x0c07810e */
if(!s->budget--) { s->failed_pc=0x0c07810eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c078110u,s,ram);
P_0c078170: /* original 90b2, guest PC 0x0c078170 */
if(!s->budget--) { s->failed_pc=0x0c078170u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0782d8u,2);
return vf3_matrix_family(0x0c078172u,s,ram);
P_0c0781ba: /* original 2fe6, guest PC 0x0c0781ba */
if(!s->budget--) { s->failed_pc=0x0c0781bau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0781bc;
P_0c0781bc: /* original 6e43, guest PC 0x0c0781bc */
if(!s->budget--) { s->failed_pc=0x0c0781bcu; return 0; }
r[14]=r[4];
goto P_0c0781be;
P_0c0781be: /* original e019, guest PC 0x0c0781be */
if(!s->budget--) { s->failed_pc=0x0c0781beu; return 0; }
r[0]=0x00000019u;
goto P_0c0781c0;
P_0c0781c0: /* original 2fd6, guest PC 0x0c0781c0 */
if(!s->budget--) { s->failed_pc=0x0c0781c0u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
return vf3_matrix_family(0x0c0781c2u,s,ram);
P_0c07b9ae: /* original 4f22, guest PC 0x0c07b9ae */
if(!s->budget--) { s->failed_pc=0x0c07b9aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b9b0;
P_0c07b9b0: /* original d419, guest PC 0x0c07b9b0 */
if(!s->budget--) { s->failed_pc=0x0c07b9b0u; return 0; }
r[4]=read(ram,0x0c07ba18u,4);
goto P_0c07b9b2;
P_0c07b9b2: /* original d31a, guest PC 0x0c07b9b2 */
if(!s->budget--) { s->failed_pc=0x0c07b9b2u; return 0; }
r[3]=read(ram,0x0c07ba1cu,4);
goto P_0c07b9b4;
P_0c07b9b4: /* original 7ffc, guest PC 0x0c07b9b4 */
if(!s->budget--) { s->failed_pc=0x0c07b9b4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b9b6;
P_0c07b9b6: /* original 430b, guest PC 0x0c07b9b6 */
if(!s->budget--) { s->failed_pc=0x0c07b9b6u; return 0; }
target=r[3];
r[16]=0x0c07b9bau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b9bau) { target=s->pc; goto dispatch; }
goto P_0c07b9ba;
P_0c07b9b8: /* original 64e3, guest PC 0x0c07b9b8 */
if(!s->budget--) { s->failed_pc=0x0c07b9b8u; return 0; }
r[4]=r[14];
goto P_0c07b9ba;
P_0c07b9ba: /* original d519, guest PC 0x0c07b9ba */
if(!s->budget--) { s->failed_pc=0x0c07b9bau; return 0; }
r[5]=read(ram,0x0c07ba20u,4);
goto P_0c07b9bc;
P_0c07b9bc: /* original e010, guest PC 0x0c07b9bc */
if(!s->budget--) { s->failed_pc=0x0c07b9bcu; return 0; }
r[0]=0x00000010u;
goto P_0c07b9be;
P_0c07b9be: /* original 0d5c, guest PC 0x0c07b9be */
if(!s->budget--) { s->failed_pc=0x0c07b9beu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07b9c0;
P_0c07b9c0: /* original e011, guest PC 0x0c07b9c0 */
if(!s->budget--) { s->failed_pc=0x0c07b9c0u; return 0; }
r[0]=0x00000011u;
goto P_0c07b9c2;
P_0c07b9c2: /* original 6ddc, guest PC 0x0c07b9c2 */
if(!s->budget--) { s->failed_pc=0x0c07b9c2u; return 0; }
r[13]=r[13]&255u;
goto P_0c07b9c4;
P_0c07b9c4: /* original 05d4, guest PC 0x0c07b9c4 */
if(!s->budget--) { s->failed_pc=0x0c07b9c4u; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c07b9c6;
P_0c07b9c6: /* original 9020, guest PC 0x0c07b9c6 */
if(!s->budget--) { s->failed_pc=0x0c07b9c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ba0au,2);
goto P_0c07b9c8;
P_0c07b9c8: /* original 04ee, guest PC 0x0c07b9c8 */
if(!s->budget--) { s->failed_pc=0x0c07b9c8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c07b9ca;
P_0c07b9ca: /* original 2448, guest PC 0x0c07b9ca */
if(!s->budget--) { s->failed_pc=0x0c07b9cau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b9cc;
P_0c07b9cc: /* original 8901, guest PC 0x0c07b9cc */
if(!s->budget--) { s->failed_pc=0x0c07b9ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b9d2; }
goto P_0c07b9ce;
P_0c07b9ce: /* original 74ff, guest PC 0x0c07b9ce */
if(!s->budget--) { s->failed_pc=0x0c07b9ceu; return 0; }
r[4]+=0xffffffffu;
goto P_0c07b9d0;
P_0c07b9d0: /* original 0e46, guest PC 0x0c07b9d0 */
if(!s->budget--) { s->failed_pc=0x0c07b9d0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c07b9d2;
P_0c07b9d2: /* original e012, guest PC 0x0c07b9d2 */
if(!s->budget--) { s->failed_pc=0x0c07b9d2u; return 0; }
r[0]=0x00000012u;
goto P_0c07b9d4;
P_0c07b9d4: /* original 045c, guest PC 0x0c07b9d4 */
if(!s->budget--) { s->failed_pc=0x0c07b9d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07b9d6;
P_0c07b9d6: /* original 644c, guest PC 0x0c07b9d6 */
if(!s->budget--) { s->failed_pc=0x0c07b9d6u; return 0; }
r[4]=r[4]&255u;
goto P_0c07b9d8;
P_0c07b9d8: /* original 34d0, guest PC 0x0c07b9d8 */
if(!s->budget--) { s->failed_pc=0x0c07b9d8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c07b9da;
P_0c07b9da: /* original 8909, guest PC 0x0c07b9da */
if(!s->budget--) { s->failed_pc=0x0c07b9dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b9f0; }
goto P_0c07b9dc;
P_0c07b9dc: /* original 64d3, guest PC 0x0c07b9dc */
if(!s->budget--) { s->failed_pc=0x0c07b9dcu; return 0; }
r[4]=r[13];
goto P_0c07b9de;
P_0c07b9de: /* original 7401, guest PC 0x0c07b9de */
if(!s->budget--) { s->failed_pc=0x0c07b9deu; return 0; }
r[4]+=0x00000001u;
goto P_0c07b9e0;
P_0c07b9e0: /* original 0544, guest PC 0x0c07b9e0 */
if(!s->budget--) { s->failed_pc=0x0c07b9e0u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c07b9e2;
P_0c07b9e2: /* original 53e4, guest PC 0x0c07b9e2 */
if(!s->budget--) { s->failed_pc=0x0c07b9e2u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c07b9e4;
P_0c07b9e4: /* original 6233, guest PC 0x0c07b9e4 */
if(!s->budget--) { s->failed_pc=0x0c07b9e4u; return 0; }
r[2]=r[3];
goto P_0c07b9e6;
P_0c07b9e6: /* original 2f32, guest PC 0x0c07b9e6 */
if(!s->budget--) { s->failed_pc=0x0c07b9e6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07b9e8;
P_0c07b9e8: /* original 420b, guest PC 0x0c07b9e8 */
if(!s->budget--) { s->failed_pc=0x0c07b9e8u; return 0; }
target=r[2];
r[16]=0x0c07b9ecu;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07b9ecu) { target=s->pc; goto dispatch; }
goto P_0c07b9ec;
P_0c07b9ea: /* original 64c3, guest PC 0x0c07b9ea */
if(!s->budget--) { s->failed_pc=0x0c07b9eau; return 0; }
r[4]=r[12];
goto P_0c07b9ec;
P_0c07b9ec: /* original d309, guest PC 0x0c07b9ec */
if(!s->budget--) { s->failed_pc=0x0c07b9ecu; return 0; }
r[3]=read(ram,0x0c07ba14u,4);
goto P_0c07b9ee;
P_0c07b9ee: /* original 1e34, guest PC 0x0c07b9ee */
if(!s->budget--) { s->failed_pc=0x0c07b9eeu; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c07b9f0;
P_0c07b9f0: /* original d00c, guest PC 0x0c07b9f0 */
if(!s->budget--) { s->failed_pc=0x0c07b9f0u; return 0; }
r[0]=read(ram,0x0c07ba24u,4);
goto P_0c07b9f2;
P_0c07b9f2: /* original 4d08, guest PC 0x0c07b9f2 */
if(!s->budget--) { s->failed_pc=0x0c07b9f2u; return 0; }
r[13]<<=2;
goto P_0c07b9f4;
P_0c07b9f4: /* original 64c3, guest PC 0x0c07b9f4 */
if(!s->budget--) { s->failed_pc=0x0c07b9f4u; return 0; }
r[4]=r[12];
goto P_0c07b9f6;
P_0c07b9f6: /* original e500, guest PC 0x0c07b9f6 */
if(!s->budget--) { s->failed_pc=0x0c07b9f6u; return 0; }
r[5]=0x00000000u;
goto P_0c07b9f8;
P_0c07b9f8: /* original 02de, guest PC 0x0c07b9f8 */
if(!s->budget--) { s->failed_pc=0x0c07b9f8u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c07b9fa;
P_0c07b9fa: /* original 2f22, guest PC 0x0c07b9fa */
if(!s->budget--) { s->failed_pc=0x0c07b9fau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07b9fc;
P_0c07b9fc: /* original 7f04, guest PC 0x0c07b9fc */
if(!s->budget--) { s->failed_pc=0x0c07b9fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c07b9fe;
P_0c07b9fe: /* original 4f26, guest PC 0x0c07b9fe */
if(!s->budget--) { s->failed_pc=0x0c07b9feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ba00;
P_0c07ba00: /* original 6323, guest PC 0x0c07ba00 */
if(!s->budget--) { s->failed_pc=0x0c07ba00u; return 0; }
r[3]=r[2];
goto P_0c07ba02;
P_0c07ba02: /* original 6cf6, guest PC 0x0c07ba02 */
if(!s->budget--) { s->failed_pc=0x0c07ba02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ba04;
P_0c07ba04: /* original 6df6, guest PC 0x0c07ba04 */
if(!s->budget--) { s->failed_pc=0x0c07ba04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ba06;
P_0c07ba06: /* original 432b, guest PC 0x0c07ba06 */
if(!s->budget--) { s->failed_pc=0x0c07ba06u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07ba08: /* original 6ef6, guest PC 0x0c07ba08 */
if(!s->budget--) { s->failed_pc=0x0c07ba08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ba0au,s,ram);
P_0c07c534: /* original 2fe6, guest PC 0x0c07c534 */
if(!s->budget--) { s->failed_pc=0x0c07c534u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c536;
P_0c07c536: /* original 2fd6, guest PC 0x0c07c536 */
if(!s->budget--) { s->failed_pc=0x0c07c536u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c07c538;
P_0c07c538: /* original 2fc6, guest PC 0x0c07c538 */
if(!s->budget--) { s->failed_pc=0x0c07c538u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c07c53a;
P_0c07c53a: /* original 2fb6, guest PC 0x0c07c53a */
if(!s->budget--) { s->failed_pc=0x0c07c53au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c07c53c;
P_0c07c53c: /* original 2fa6, guest PC 0x0c07c53c */
if(!s->budget--) { s->failed_pc=0x0c07c53cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c07c53e;
P_0c07c53e: /* original 2f96, guest PC 0x0c07c53e */
if(!s->budget--) { s->failed_pc=0x0c07c53eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
return vf3_matrix_family(0x0c07c540u,s,ram);
P_0c07c600: /* original e300, guest PC 0x0c07c600 */
if(!s->budget--) { s->failed_pc=0x0c07c600u; return 0; }
r[3]=0x00000000u;
goto P_0c07c602;
P_0c07c602: /* original 2fe6, guest PC 0x0c07c602 */
if(!s->budget--) { s->failed_pc=0x0c07c602u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c604;
P_0c07c604: /* original d61f, guest PC 0x0c07c604 */
if(!s->budget--) { s->failed_pc=0x0c07c604u; return 0; }
r[6]=read(ram,0x0c07c684u,4);
goto P_0c07c606;
P_0c07c606: /* original e210, guest PC 0x0c07c606 */
if(!s->budget--) { s->failed_pc=0x0c07c606u; return 0; }
r[2]=0x00000010u;
goto P_0c07c608;
P_0c07c608: /* original 6023, guest PC 0x0c07c608 */
if(!s->budget--) { s->failed_pc=0x0c07c608u; return 0; }
r[0]=r[2];
goto P_0c07c60a;
P_0c07c60a: /* original 6e43, guest PC 0x0c07c60a */
if(!s->budget--) { s->failed_pc=0x0c07c60au; return 0; }
r[14]=r[4];
goto P_0c07c60c;
P_0c07c60c: /* original 1636, guest PC 0x0c07c60c */
if(!s->budget--) { s->failed_pc=0x0c07c60cu; return 0; }
write(ram,r[6]+24,r[3],4);
goto P_0c07c60e;
P_0c07c60e: /* original 1625, guest PC 0x0c07c60e */
if(!s->budget--) { s->failed_pc=0x0c07c60eu; return 0; }
write(ram,r[6]+20,r[2],4);
goto P_0c07c610;
P_0c07c610: /* original d324, guest PC 0x0c07c610 */
if(!s->budget--) { s->failed_pc=0x0c07c610u; return 0; }
r[3]=read(ram,0x0c07c6a4u,4);
return vf3_matrix_family(0x0c07c612u,s,ram);
P_0c07c820: /* original 2fe6, guest PC 0x0c07c820 */
if(!s->budget--) { s->failed_pc=0x0c07c820u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c822;
P_0c07c822: /* original e507, guest PC 0x0c07c822 */
if(!s->budget--) { s->failed_pc=0x0c07c822u; return 0; }
r[5]=0x00000007u;
goto P_0c07c824;
P_0c07c824: /* original 4f22, guest PC 0x0c07c824 */
if(!s->budget--) { s->failed_pc=0x0c07c824u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07c826;
P_0c07c826: /* original 7ff8, guest PC 0x0c07c826 */
if(!s->budget--) { s->failed_pc=0x0c07c826u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07c828;
P_0c07c828: /* original 1f41, guest PC 0x0c07c828 */
if(!s->budget--) { s->failed_pc=0x0c07c828u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07c82a;
P_0c07c82a: /* original d347, guest PC 0x0c07c82a */
if(!s->budget--) { s->failed_pc=0x0c07c82au; return 0; }
r[3]=read(ram,0x0c07c948u,4);
goto P_0c07c82c;
P_0c07c82c: /* original 6432, guest PC 0x0c07c82c */
if(!s->budget--) { s->failed_pc=0x0c07c82cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c07c82e;
P_0c07c82e: /* original 6e43, guest PC 0x0c07c82e */
if(!s->budget--) { s->failed_pc=0x0c07c82eu; return 0; }
r[14]=r[4];
goto P_0c07c830;
P_0c07c830: /* original 4e19, guest PC 0x0c07c830 */
if(!s->budget--) { s->failed_pc=0x0c07c830u; return 0; }
r[14]>>=8;
goto P_0c07c832;
P_0c07c832: /* original 3e57, guest PC 0x0c07c832 */
if(!s->budget--) { s->failed_pc=0x0c07c832u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[5])!=0);
goto P_0c07c834;
P_0c07c834: /* original 7401, guest PC 0x0c07c834 */
if(!s->budget--) { s->failed_pc=0x0c07c834u; return 0; }
r[4]+=0x00000001u;
goto P_0c07c836;
P_0c07c836: /* original 8f01, guest PC 0x0c07c836 */
if(!s->budget--) { s->failed_pc=0x0c07c836u; return 0; }
cond=r[17]&1u;
r[4]>>=8;
if(!cond) { goto P_0c07c83c; }
goto P_0c07c83a;
P_0c07c838: /* original 4419, guest PC 0x0c07c838 */
if(!s->budget--) { s->failed_pc=0x0c07c838u; return 0; }
r[4]>>=8;
goto P_0c07c83a;
P_0c07c83a: /* original 6e53, guest PC 0x0c07c83a */
if(!s->budget--) { s->failed_pc=0x0c07c83au; return 0; }
r[14]=r[5];
goto P_0c07c83c;
P_0c07c83c: /* original 34e0, guest PC 0x0c07c83c */
if(!s->budget--) { s->failed_pc=0x0c07c83cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[14])!=0);
goto P_0c07c83e;
P_0c07c83e: /* original 890a, guest PC 0x0c07c83e */
if(!s->budget--) { s->failed_pc=0x0c07c83eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c856; }
goto P_0c07c840;
P_0c07c840: /* original d242, guest PC 0x0c07c840 */
if(!s->budget--) { s->failed_pc=0x0c07c840u; return 0; }
r[2]=read(ram,0x0c07c94cu,4);
goto P_0c07c842;
P_0c07c842: /* original e320, guest PC 0x0c07c842 */
if(!s->budget--) { s->failed_pc=0x0c07c842u; return 0; }
r[3]=0x00000020u;
goto P_0c07c844;
P_0c07c844: /* original e63a, guest PC 0x0c07c844 */
if(!s->budget--) { s->failed_pc=0x0c07c844u; return 0; }
r[6]=0x0000003au;
goto P_0c07c846;
P_0c07c846: /* original 2f22, guest PC 0x0c07c846 */
if(!s->budget--) { s->failed_pc=0x0c07c846u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07c848;
P_0c07c848: /* original e723, guest PC 0x0c07c848 */
if(!s->budget--) { s->failed_pc=0x0c07c848u; return 0; }
r[7]=0x00000023u;
goto P_0c07c84a;
P_0c07c84a: /* original 9570, guest PC 0x0c07c84a */
if(!s->budget--) { s->failed_pc=0x0c07c84au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c92eu,2);
goto P_0c07c84c;
P_0c07c84c: /* original 2f36, guest PC 0x0c07c84c */
if(!s->budget--) { s->failed_pc=0x0c07c84cu; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c07c84e;
P_0c07c84e: /* original d240, guest PC 0x0c07c84e */
if(!s->budget--) { s->failed_pc=0x0c07c84eu; return 0; }
r[2]=read(ram,0x0c07c950u,4);
goto P_0c07c850;
P_0c07c850: /* original 420b, guest PC 0x0c07c850 */
if(!s->budget--) { s->failed_pc=0x0c07c850u; return 0; }
target=r[2];
r[16]=0x0c07c854u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c854u) { target=s->pc; goto dispatch; }
goto P_0c07c854;
P_0c07c852: /* original 54f1, guest PC 0x0c07c852 */
if(!s->budget--) { s->failed_pc=0x0c07c852u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07c854;
P_0c07c854: /* original 7f04, guest PC 0x0c07c854 */
if(!s->budget--) { s->failed_pc=0x0c07c854u; return 0; }
r[15]+=0x00000004u;
goto P_0c07c856;
P_0c07c856: /* original d03f, guest PC 0x0c07c856 */
if(!s->budget--) { s->failed_pc=0x0c07c856u; return 0; }
r[0]=read(ram,0x0c07c954u,4);
goto P_0c07c858;
P_0c07c858: /* original 4e08, guest PC 0x0c07c858 */
if(!s->budget--) { s->failed_pc=0x0c07c858u; return 0; }
r[14]<<=2;
goto P_0c07c85a;
P_0c07c85a: /* original 03ee, guest PC 0x0c07c85a */
if(!s->budget--) { s->failed_pc=0x0c07c85au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c07c85c;
P_0c07c85c: /* original 6233, guest PC 0x0c07c85c */
if(!s->budget--) { s->failed_pc=0x0c07c85cu; return 0; }
r[2]=r[3];
goto P_0c07c85e;
P_0c07c85e: /* original 2f32, guest PC 0x0c07c85e */
if(!s->budget--) { s->failed_pc=0x0c07c85eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07c860;
P_0c07c860: /* original 420b, guest PC 0x0c07c860 */
if(!s->budget--) { s->failed_pc=0x0c07c860u; return 0; }
target=r[2];
r[16]=0x0c07c864u;
r[4]=read(ram,r[15]+4,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c07c864u) { target=s->pc; goto dispatch; }
goto P_0c07c864;
P_0c07c862: /* original 54f1, guest PC 0x0c07c862 */
if(!s->budget--) { s->failed_pc=0x0c07c862u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07c864;
P_0c07c864: /* original 7f08, guest PC 0x0c07c864 */
if(!s->budget--) { s->failed_pc=0x0c07c864u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c866;
P_0c07c866: /* original 4f26, guest PC 0x0c07c866 */
if(!s->budget--) { s->failed_pc=0x0c07c866u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c868;
P_0c07c868: /* original 000b, guest PC 0x0c07c868 */
if(!s->budget--) { s->failed_pc=0x0c07c868u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07c86a: /* original 6ef6, guest PC 0x0c07c86a */
if(!s->budget--) { s->failed_pc=0x0c07c86au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c86cu,s,ram);
P_0c07c99a: /* original 2fe6, guest PC 0x0c07c99a */
if(!s->budget--) { s->failed_pc=0x0c07c99au; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c07c99c;
P_0c07c99c: /* original e300, guest PC 0x0c07c99c */
if(!s->budget--) { s->failed_pc=0x0c07c99cu; return 0; }
r[3]=0x00000000u;
return vf3_matrix_family(0x0c07c99eu,s,ram);
P_0c08049c: /* original d214, guest PC 0x0c08049c */
if(!s->budget--) { s->failed_pc=0x0c08049cu; return 0; }
r[2]=read(ram,0x0c0804f0u,4);
goto P_0c08049e;
P_0c08049e: /* original e3ff, guest PC 0x0c08049e */
if(!s->budget--) { s->failed_pc=0x0c08049eu; return 0; }
r[3]=0xffffffffu;
goto P_0c0804a0;
P_0c0804a0: /* original 000b, guest PC 0x0c0804a0 */
if(!s->budget--) { s->failed_pc=0x0c0804a0u; return 0; }
target=r[16];
write(ram,r[2],r[3],4);
s->pc=target; return ram->oob==0;
P_0c0804a2: /* original 2232, guest PC 0x0c0804a2 */
if(!s->budget--) { s->failed_pc=0x0c0804a2u; return 0; }
write(ram,r[2],r[3],4);
return vf3_matrix_family(0x0c0804a4u,s,ram);
P_0c081184: /* original 2fe6, guest PC 0x0c081184 */
if(!s->budget--) { s->failed_pc=0x0c081184u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c081186;
P_0c081186: /* original 2fd6, guest PC 0x0c081186 */
if(!s->budget--) { s->failed_pc=0x0c081186u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c081188;
P_0c081188: /* original 2fc6, guest PC 0x0c081188 */
if(!s->budget--) { s->failed_pc=0x0c081188u; return 0; }
r[15]-=4; write(ram,r[15],r[12],4);
goto P_0c08118a;
P_0c08118a: /* original 2fb6, guest PC 0x0c08118a */
if(!s->budget--) { s->failed_pc=0x0c08118au; return 0; }
r[15]-=4; write(ram,r[15],r[11],4);
goto P_0c08118c;
P_0c08118c: /* original 2fa6, guest PC 0x0c08118c */
if(!s->budget--) { s->failed_pc=0x0c08118cu; return 0; }
r[15]-=4; write(ram,r[15],r[10],4);
goto P_0c08118e;
P_0c08118e: /* original 2f96, guest PC 0x0c08118e */
if(!s->budget--) { s->failed_pc=0x0c08118eu; return 0; }
r[15]-=4; write(ram,r[15],r[9],4);
goto P_0c081190;
P_0c081190: /* original 2f86, guest PC 0x0c081190 */
if(!s->budget--) { s->failed_pc=0x0c081190u; return 0; }
r[15]-=4; write(ram,r[15],r[8],4);
goto P_0c081192;
P_0c081192: /* original d132, guest PC 0x0c081192 */
if(!s->budget--) { s->failed_pc=0x0c081192u; return 0; }
r[1]=read(ram,0x0c08125cu,4);
return vf3_matrix_family(0x0c081194u,s,ram);
P_0c0968d0: /* original d418, guest PC 0x0c0968d0 */
if(!s->budget--) { s->failed_pc=0x0c0968d0u; return 0; }
r[4]=read(ram,0x0c096934u,4);
goto P_0c0968d2;
P_0c0968d2: /* original 7ffc, guest PC 0x0c0968d2 */
if(!s->budget--) { s->failed_pc=0x0c0968d2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0968d4;
P_0c0968d4: /* original 5343, guest PC 0x0c0968d4 */
if(!s->budget--) { s->failed_pc=0x0c0968d4u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c0968d6;
P_0c0968d6: /* original 73ff, guest PC 0x0c0968d6 */
if(!s->budget--) { s->failed_pc=0x0c0968d6u; return 0; }
r[3]+=0xffffffffu;
goto P_0c0968d8;
P_0c0968d8: /* original 1433, guest PC 0x0c0968d8 */
if(!s->budget--) { s->failed_pc=0x0c0968d8u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c0968da;
P_0c0968da: /* original 844a, guest PC 0x0c0968da */
if(!s->budget--) { s->failed_pc=0x0c0968dau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+10,1);
goto P_0c0968dc;
P_0c0968dc: /* original 650c, guest PC 0x0c0968dc */
if(!s->budget--) { s->failed_pc=0x0c0968dcu; return 0; }
r[5]=r[0]&255u;
goto P_0c0968de;
P_0c0968de: /* original 6053, guest PC 0x0c0968de */
if(!s->budget--) { s->failed_pc=0x0c0968deu; return 0; }
r[0]=r[5];
goto P_0c0968e0;
P_0c0968e0: /* original 8048, guest PC 0x0c0968e0 */
if(!s->budget--) { s->failed_pc=0x0c0968e0u; return 0; }
write(ram,r[4]+8,r[0],1);
goto P_0c0968e2;
P_0c0968e2: /* original d215, guest PC 0x0c0968e2 */
if(!s->budget--) { s->failed_pc=0x0c0968e2u; return 0; }
r[2]=read(ram,0x0c096938u,4);
goto P_0c0968e4;
P_0c0968e4: /* original 635b, guest PC 0x0c0968e4 */
if(!s->budget--) { s->failed_pc=0x0c0968e4u; return 0; }
r[3]=0u-r[5];
goto P_0c0968e6;
P_0c0968e6: /* original 4508, guest PC 0x0c0968e6 */
if(!s->budget--) { s->failed_pc=0x0c0968e6u; return 0; }
r[5]<<=2;
goto P_0c0968e8;
P_0c0968e8: /* original 423d, guest PC 0x0c0968e8 */
if(!s->budget--) { s->failed_pc=0x0c0968e8u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c0968ea;
P_0c0968ea: /* original 2422, guest PC 0x0c0968ea */
if(!s->budget--) { s->failed_pc=0x0c0968eau; return 0; }
write(ram,r[4],r[2],4);
goto P_0c0968ec;
P_0c0968ec: /* original d013, guest PC 0x0c0968ec */
if(!s->budget--) { s->failed_pc=0x0c0968ecu; return 0; }
r[0]=read(ram,0x0c09693cu,4);
goto P_0c0968ee;
P_0c0968ee: /* original 035e, guest PC 0x0c0968ee */
if(!s->budget--) { s->failed_pc=0x0c0968eeu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c0968f0;
P_0c0968f0: /* original 6233, guest PC 0x0c0968f0 */
if(!s->budget--) { s->failed_pc=0x0c0968f0u; return 0; }
r[2]=r[3];
goto P_0c0968f2;
P_0c0968f2: /* original 2f32, guest PC 0x0c0968f2 */
if(!s->budget--) { s->failed_pc=0x0c0968f2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0968f4;
P_0c0968f4: /* original 422b, guest PC 0x0c0968f4 */
if(!s->budget--) { s->failed_pc=0x0c0968f4u; return 0; }
target=r[2];
r[15]+=0x00000004u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0968f6: /* original 7f04, guest PC 0x0c0968f6 */
if(!s->budget--) { s->failed_pc=0x0c0968f6u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0968f8u,s,ram);
P_0c096d5e: /* original 2fe6, guest PC 0x0c096d5e */
if(!s->budget--) { s->failed_pc=0x0c096d5eu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c096d60;
P_0c096d60: /* original 2fd6, guest PC 0x0c096d60 */
if(!s->budget--) { s->failed_pc=0x0c096d60u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c096d62;
P_0c096d62: /* original 4f22, guest PC 0x0c096d62 */
if(!s->budget--) { s->failed_pc=0x0c096d62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c096d64;
P_0c096d64: /* original d327, guest PC 0x0c096d64 */
if(!s->budget--) { s->failed_pc=0x0c096d64u; return 0; }
r[3]=read(ram,0x0c096e04u,4);
goto P_0c096d66;
P_0c096d66: /* original dd2a, guest PC 0x0c096d66 */
if(!s->budget--) { s->failed_pc=0x0c096d66u; return 0; }
r[13]=read(ram,0x0c096e10u,4);
goto P_0c096d68;
P_0c096d68: /* original 7ffc, guest PC 0x0c096d68 */
if(!s->budget--) { s->failed_pc=0x0c096d68u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c096d6a;
P_0c096d6a: /* original 2f32, guest PC 0x0c096d6a */
if(!s->budget--) { s->failed_pc=0x0c096d6au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c096d6c;
P_0c096d6c: /* original 52d2, guest PC 0x0c096d6c */
if(!s->budget--) { s->failed_pc=0x0c096d6cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d6e;
P_0c096d6e: /* original d329, guest PC 0x0c096d6e */
if(!s->budget--) { s->failed_pc=0x0c096d6eu; return 0; }
r[3]=read(ram,0x0c096e14u,4);
goto P_0c096d70;
P_0c096d70: /* original 2238, guest PC 0x0c096d70 */
if(!s->budget--) { s->failed_pc=0x0c096d70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c096d72;
P_0c096d72: /* original 8920, guest PC 0x0c096d72 */
if(!s->budget--) { s->failed_pc=0x0c096d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c096db6; }
goto P_0c096d74;
P_0c096d74: /* original de28, guest PC 0x0c096d74 */
if(!s->budget--) { s->failed_pc=0x0c096d74u; return 0; }
r[14]=read(ram,0x0c096e18u,4);
goto P_0c096d76;
P_0c096d76: /* original bdc4, guest PC 0x0c096d76 */
if(!s->budget--) { s->failed_pc=0x0c096d76u; return 0; }
target=0x0c096902u; r[16]=0x0c096d7au;
r[4]=read(ram,r[14]+32,4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d7au) { target=s->pc; goto dispatch; }
goto P_0c096d7a;
P_0c096d78: /* original 54e8, guest PC 0x0c096d78 */
if(!s->budget--) { s->failed_pc=0x0c096d78u; return 0; }
r[4]=read(ram,r[14]+32,4);
goto P_0c096d7a;
P_0c096d7a: /* original e044, guest PC 0x0c096d7a */
if(!s->budget--) { s->failed_pc=0x0c096d7au; return 0; }
r[0]=0x00000044u;
goto P_0c096d7c;
P_0c096d7c: /* original bdc1, guest PC 0x0c096d7c */
if(!s->budget--) { s->failed_pc=0x0c096d7cu; return 0; }
target=0x0c096902u; r[16]=0x0c096d80u;
r[4]=read(ram,r[14]+r[0],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d80u) { target=s->pc; goto dispatch; }
goto P_0c096d80;
P_0c096d7e: /* original 04ee, guest PC 0x0c096d7e */
if(!s->budget--) { s->failed_pc=0x0c096d7eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d80;
P_0c096d80: /* original 52d2, guest PC 0x0c096d80 */
if(!s->budget--) { s->failed_pc=0x0c096d80u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c096d82;
P_0c096d82: /* original e044, guest PC 0x0c096d82 */
if(!s->budget--) { s->failed_pc=0x0c096d82u; return 0; }
r[0]=0x00000044u;
goto P_0c096d84;
P_0c096d84: /* original d325, guest PC 0x0c096d84 */
if(!s->budget--) { s->failed_pc=0x0c096d84u; return 0; }
r[3]=read(ram,0x0c096e1cu,4);
goto P_0c096d86;
P_0c096d86: /* original 223b, guest PC 0x0c096d86 */
if(!s->budget--) { s->failed_pc=0x0c096d86u; return 0; }
r[2]|=r[3];
goto P_0c096d88;
P_0c096d88: /* original 1d22, guest PC 0x0c096d88 */
if(!s->budget--) { s->failed_pc=0x0c096d88u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c096d8a;
P_0c096d8a: /* original e201, guest PC 0x0c096d8a */
if(!s->budget--) { s->failed_pc=0x0c096d8au; return 0; }
r[2]=0x00000001u;
goto P_0c096d8c;
P_0c096d8c: /* original d124, guest PC 0x0c096d8c */
if(!s->budget--) { s->failed_pc=0x0c096d8cu; return 0; }
r[1]=read(ram,0x0c096e20u,4);
goto P_0c096d8e;
P_0c096d8e: /* original 04ee, guest PC 0x0c096d8e */
if(!s->budget--) { s->failed_pc=0x0c096d8eu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c096d90;
P_0c096d90: /* original 410b, guest PC 0x0c096d90 */
if(!s->budget--) { s->failed_pc=0x0c096d90u; return 0; }
target=r[1];
r[16]=0x0c096d94u;
write(ram,r[4],r[2],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c096d94u) { target=s->pc; goto dispatch; }
goto P_0c096d94;
P_0c096d92: /* original 2422, guest PC 0x0c096d92 */
if(!s->budget--) { s->failed_pc=0x0c096d92u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c096d94;
P_0c096d94: /* original 55e5, guest PC 0x0c096d94 */
if(!s->budget--) { s->failed_pc=0x0c096d94u; return 0; }
r[5]=read(ram,r[14]+20,4);
goto P_0c096d96;
P_0c096d96: /* original e400, guest PC 0x0c096d96 */
if(!s->budget--) { s->failed_pc=0x0c096d96u; return 0; }
r[4]=0x00000000u;
goto P_0c096d98;
P_0c096d98: /* original 56e4, guest PC 0x0c096d98 */
if(!s->budget--) { s->failed_pc=0x0c096d98u; return 0; }
r[6]=read(ram,r[14]+16,4);
goto P_0c096d9a;
P_0c096d9a: /* original e061, guest PC 0x0c096d9a */
if(!s->budget--) { s->failed_pc=0x0c096d9au; return 0; }
r[0]=0x00000061u;
goto P_0c096d9c;
P_0c096d9c: /* original 0644, guest PC 0x0c096d9c */
if(!s->budget--) { s->failed_pc=0x0c096d9cu; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096d9e;
P_0c096d9e: /* original 0544, guest PC 0x0c096d9e */
if(!s->budget--) { s->failed_pc=0x0c096d9eu; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da0;
P_0c096da0: /* original e060, guest PC 0x0c096da0 */
if(!s->budget--) { s->failed_pc=0x0c096da0u; return 0; }
r[0]=0x00000060u;
goto P_0c096da2;
P_0c096da2: /* original 0644, guest PC 0x0c096da2 */
if(!s->budget--) { s->failed_pc=0x0c096da2u; return 0; }
write(ram,r[6]+r[0],r[4],1);
goto P_0c096da4;
P_0c096da4: /* original 0544, guest PC 0x0c096da4 */
if(!s->budget--) { s->failed_pc=0x0c096da4u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c096da6;
P_0c096da6: /* original e016, guest PC 0x0c096da6 */
if(!s->budget--) { s->failed_pc=0x0c096da6u; return 0; }
r[0]=0x00000016u;
goto P_0c096da8;
P_0c096da8: /* original 63f2, guest PC 0x0c096da8 */
if(!s->budget--) { s->failed_pc=0x0c096da8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c096daa;
P_0c096daa: /* original 7f04, guest PC 0x0c096daa */
if(!s->budget--) { s->failed_pc=0x0c096daau; return 0; }
r[15]+=0x00000004u;
goto P_0c096dac;
P_0c096dac: /* original 4f26, guest PC 0x0c096dac */
if(!s->budget--) { s->failed_pc=0x0c096dacu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dae;
P_0c096dae: /* original 803a, guest PC 0x0c096dae */
if(!s->budget--) { s->failed_pc=0x0c096daeu; return 0; }
write(ram,r[3]+10,r[0],1);
goto P_0c096db0;
P_0c096db0: /* original 6df6, guest PC 0x0c096db0 */
if(!s->budget--) { s->failed_pc=0x0c096db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096db2;
P_0c096db2: /* original ad8d, guest PC 0x0c096db2 */
if(!s->budget--) { s->failed_pc=0x0c096db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0968d0;
P_0c096db4: /* original 6ef6, guest PC 0x0c096db4 */
if(!s->budget--) { s->failed_pc=0x0c096db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096db6;
P_0c096db6: /* original 7f04, guest PC 0x0c096db6 */
if(!s->budget--) { s->failed_pc=0x0c096db6u; return 0; }
r[15]+=0x00000004u;
goto P_0c096db8;
P_0c096db8: /* original 4f26, guest PC 0x0c096db8 */
if(!s->budget--) { s->failed_pc=0x0c096db8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096dba;
P_0c096dba: /* original 6df6, guest PC 0x0c096dba */
if(!s->budget--) { s->failed_pc=0x0c096dbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096dbc;
P_0c096dbc: /* original 000b, guest PC 0x0c096dbc */
if(!s->budget--) { s->failed_pc=0x0c096dbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096dbe: /* original 6ef6, guest PC 0x0c096dbe */
if(!s->budget--) { s->failed_pc=0x0c096dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c096dc0u,s,ram);
P_0c097042: /* original 4f22, guest PC 0x0c097042 */
if(!s->budget--) { s->failed_pc=0x0c097042u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c097044;
P_0c097044: /* original d334, guest PC 0x0c097044 */
if(!s->budget--) { s->failed_pc=0x0c097044u; return 0; }
r[3]=read(ram,0x0c097118u,4);
goto P_0c097046;
P_0c097046: /* original de33, guest PC 0x0c097046 */
if(!s->budget--) { s->failed_pc=0x0c097046u; return 0; }
r[14]=read(ram,0x0c097114u,4);
goto P_0c097048;
P_0c097048: /* original 430b, guest PC 0x0c097048 */
if(!s->budget--) { s->failed_pc=0x0c097048u; return 0; }
target=r[3];
r[16]=0x0c09704cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09704cu) { target=s->pc; goto dispatch; }
goto P_0c09704c;
P_0c09704a: /* original 0009, guest PC 0x0c09704a */
if(!s->budget--) { s->failed_pc=0x0c09704au; return 0; }
goto P_0c09704c;
P_0c09704c: /* original 52e3, guest PC 0x0c09704c */
if(!s->budget--) { s->failed_pc=0x0c09704cu; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c09704e;
P_0c09704e: /* original 2228, guest PC 0x0c09704e */
if(!s->budget--) { s->failed_pc=0x0c09704eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c097050;
P_0c097050: /* original 8b02, guest PC 0x0c097050 */
if(!s->budget--) { s->failed_pc=0x0c097050u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c097058; }
goto P_0c097052;
P_0c097052: /* original 84eb, guest PC 0x0c097052 */
if(!s->budget--) { s->failed_pc=0x0c097052u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+11,1);
goto P_0c097054;
P_0c097054: /* original 7001, guest PC 0x0c097054 */
if(!s->budget--) { s->failed_pc=0x0c097054u; return 0; }
r[0]+=0x00000001u;
goto P_0c097056;
P_0c097056: /* original 80eb, guest PC 0x0c097056 */
if(!s->budget--) { s->failed_pc=0x0c097056u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c097058;
P_0c097058: /* original 4f26, guest PC 0x0c097058 */
if(!s->budget--) { s->failed_pc=0x0c097058u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09705a;
P_0c09705a: /* original ae80, guest PC 0x0c09705a */
if(!s->budget--) { s->failed_pc=0x0c09705au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c096d5e;
P_0c09705c: /* original 6ef6, guest PC 0x0c09705c */
if(!s->budget--) { s->failed_pc=0x0c09705cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09705eu,s,ram);
P_0c0a7b36: /* original 2fe6, guest PC 0x0c0a7b36 */
if(!s->budget--) { s->failed_pc=0x0c0a7b36u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0a7b38;
P_0c0a7b38: /* original 6e43, guest PC 0x0c0a7b38 */
if(!s->budget--) { s->failed_pc=0x0c0a7b38u; return 0; }
r[14]=r[4];
goto P_0c0a7b3a;
P_0c0a7b3a: /* original 9026, guest PC 0x0c0a7b3a */
if(!s->budget--) { s->failed_pc=0x0c0a7b3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b8au,2);
goto P_0c0a7b3c;
P_0c0a7b3c: /* original f5e6, guest PC 0x0c0a7b3c */
if(!s->budget--) { s->failed_pc=0x0c0a7b3cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0a7b3e;
P_0c0a7b3e: /* original 70f0, guest PC 0x0c0a7b3e */
if(!s->budget--) { s->failed_pc=0x0c0a7b3eu; return 0; }
r[0]+=0xfffffff0u;
goto P_0c0a7b40;
P_0c0a7b40: /* original f4e6, guest PC 0x0c0a7b40 */
if(!s->budget--) { s->failed_pc=0x0c0a7b40u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0a7b42;
P_0c0a7b42: /* original 7016, guest PC 0x0c0a7b42 */
if(!s->budget--) { s->failed_pc=0x0c0a7b42u; return 0; }
r[0]+=0x00000016u;
goto P_0c0a7b44;
P_0c0a7b44: /* original 06ec, guest PC 0x0c0a7b44 */
if(!s->budget--) { s->failed_pc=0x0c0a7b44u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7b46;
P_0c0a7b46: /* original 70ff, guest PC 0x0c0a7b46 */
if(!s->budget--) { s->failed_pc=0x0c0a7b46u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a7b48;
P_0c0a7b48: /* original 05ec, guest PC 0x0c0a7b48 */
if(!s->budget--) { s->failed_pc=0x0c0a7b48u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7b4a;
P_0c0a7b4a: /* original 70ff, guest PC 0x0c0a7b4a */
if(!s->budget--) { s->failed_pc=0x0c0a7b4au; return 0; }
r[0]+=0xffffffffu;
goto P_0c0a7b4c;
P_0c0a7b4c: /* original 04ec, guest PC 0x0c0a7b4c */
if(!s->budget--) { s->failed_pc=0x0c0a7b4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a7b4e;
P_0c0a7b4e: /* original af5d, guest PC 0x0c0a7b4e */
if(!s->budget--) { s->failed_pc=0x0c0a7b4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7a0cu,s,ram);
P_0c0a7b50: /* original 6ef6, guest PC 0x0c0a7b50 */
if(!s->budget--) { s->failed_pc=0x0c0a7b50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a7b52u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c076ba6u,0x0c076ba8u,0x0c076baau,0x0c076bacu,0x0c076baeu,0x0c076bb0u,0x0c076bb2u,0x0c076bb4u,0x0c076bb6u,0x0c076bb8u,0x0c076bbau,0x0c076bbcu,0x0c076bbeu,0x0c076bc0u,0x0c076bc2u,0x0c076bc4u,
0x0c076bc6u,0x0c076bc8u,0x0c076bcau,0x0c076bccu,0x0c076bceu,0x0c076bd0u,0x0c076bd2u,0x0c076bd4u,0x0c076bd6u,0x0c076bd8u,0x0c076bdau,0x0c076bdcu,0x0c076bdeu,0x0c076be0u,0x0c076be2u,0x0c076be4u,
0x0c076be6u,0x0c076be8u,0x0c076beau,0x0c076becu,0x0c076beeu,0x0c076bf0u,0x0c076bf2u,0x0c076bf4u,0x0c076bf6u,0x0c076bf8u,0x0c076bfau,0x0c076bfcu,0x0c076bfeu,0x0c076c00u,0x0c076c02u,0x0c076c04u,
0x0c076c06u,0x0c076c08u,0x0c076c0au,0x0c076c0cu,0x0c076c0eu,0x0c076c10u,0x0c076c12u,0x0c076c14u,0x0c076c16u,0x0c076c18u,0x0c076c1au,0x0c076c1cu,0x0c076c1eu,0x0c076c20u,0x0c076c22u,0x0c076c24u,
0x0c076c26u,0x0c076c28u,0x0c076c2au,0x0c076c2cu,0x0c076c2eu,0x0c076c30u,0x0c076c32u,0x0c076c34u,0x0c076c36u,0x0c076c38u,0x0c076c3au,0x0c076c3cu,0x0c076c3eu,0x0c076c40u,0x0c076c42u,0x0c076c44u,
0x0c076c46u,0x0c076c48u,0x0c076c4au,0x0c076c4cu,0x0c076c4eu,0x0c076c50u,0x0c076c52u,0x0c076c54u,0x0c076c56u,0x0c076c58u,0x0c076c5au,0x0c076c5cu,0x0c076c5eu,0x0c076c60u,0x0c076c62u,0x0c076c64u,
0x0c076c66u,0x0c076c68u,0x0c076c6au,0x0c076c6cu,0x0c076c6eu,0x0c076c70u,0x0c076c72u,0x0c076c74u,0x0c076c76u,0x0c076c78u,0x0c076c7au,0x0c076c7cu,0x0c076c7eu,0x0c076c80u,0x0c076c82u,0x0c076c84u,
0x0c076c86u,0x0c076c88u,0x0c076c8au,0x0c076c8cu,0x0c076c8eu,0x0c076c90u,0x0c076c92u,0x0c076c94u,0x0c076c96u,0x0c076c98u,0x0c076c9au,0x0c076c9cu,0x0c076c9eu,0x0c076cd8u,0x0c076cdau,0x0c076cdcu,
0x0c076cdeu,0x0c076ce0u,0x0c076ce2u,0x0c076ce4u,0x0c076ce6u,0x0c076ce8u,0x0c076ceau,0x0c076cecu,0x0c076ceeu,0x0c076cf0u,0x0c076cf2u,0x0c076cf4u,0x0c076cf6u,0x0c076cf8u,0x0c076cfau,0x0c076cfcu,
0x0c076cfeu,0x0c076d00u,0x0c076d02u,0x0c076d04u,0x0c076d06u,0x0c076d08u,0x0c076d0au,0x0c076d0cu,0x0c076d0eu,0x0c076d10u,0x0c076d12u,0x0c076d14u,0x0c076d16u,0x0c076d18u,0x0c076d1au,0x0c076d1cu,
0x0c076d1eu,0x0c076d20u,0x0c076d22u,0x0c076d24u,0x0c076d26u,0x0c076d28u,0x0c076d2au,0x0c076d2cu,0x0c076d2eu,0x0c076d30u,0x0c076d32u,0x0c076d34u,0x0c076d36u,0x0c076d38u,0x0c076d3au,0x0c076d3cu,
0x0c076d3eu,0x0c076d40u,0x0c076d42u,0x0c076d44u,0x0c076d46u,0x0c076d48u,0x0c076d4au,0x0c076d4cu,0x0c076d4eu,0x0c076d50u,0x0c076d52u,0x0c076d54u,0x0c076d56u,0x0c076d58u,0x0c076d5au,0x0c076d5cu,
0x0c076d5eu,0x0c076d60u,0x0c076d62u,0x0c076d64u,0x0c076d66u,0x0c076d68u,0x0c076d6au,0x0c076d6cu,0x0c076d6eu,0x0c076d70u,0x0c076d72u,0x0c076d74u,0x0c076d76u,0x0c076d78u,0x0c076d7au,0x0c076d7cu,
0x0c076d7eu,0x0c076d80u,0x0c076d82u,0x0c076d84u,0x0c076d86u,0x0c076d88u,0x0c076d8au,0x0c076d8cu,0x0c076d8eu,0x0c076d90u,0x0c076d92u,0x0c076d94u,0x0c076d96u,0x0c076d98u,0x0c076d9au,0x0c076d9cu,
0x0c076d9eu,0x0c076da0u,0x0c076da2u,0x0c076da4u,0x0c076da6u,0x0c076da8u,0x0c076de0u,0x0c076de2u,0x0c076de4u,0x0c076de6u,0x0c076de8u,0x0c076deau,0x0c076decu,0x0c076deeu,0x0c076df0u,0x0c076df2u,
0x0c076df4u,0x0c076df6u,0x0c076df8u,0x0c076dfau,0x0c076dfcu,0x0c076dfeu,0x0c076e00u,0x0c076e02u,0x0c076e04u,0x0c076e06u,0x0c076e08u,0x0c076e0au,0x0c076e0cu,0x0c076e0eu,0x0c076e10u,0x0c076e12u,
0x0c076e14u,0x0c076e16u,0x0c076e18u,0x0c076e1au,0x0c076e1cu,0x0c076e1eu,0x0c076e20u,0x0c076e22u,0x0c076e24u,0x0c076e26u,0x0c076e28u,0x0c076e2au,0x0c076e2cu,0x0c076e2eu,0x0c076e30u,0x0c076e32u,
0x0c076e34u,0x0c076e36u,0x0c076e38u,0x0c076e3au,0x0c076e3cu,0x0c076e3eu,0x0c076e40u,0x0c076e42u,0x0c076e44u,0x0c076e46u,0x0c076e48u,0x0c076e4au,0x0c076e4cu,0x0c076e4eu,0x0c076e50u,0x0c076e52u,
0x0c076e54u,0x0c076e56u,0x0c076e58u,0x0c076e5au,0x0c076e5cu,0x0c076e5eu,0x0c076e60u,0x0c076e62u,0x0c076e64u,0x0c076e66u,0x0c076e68u,0x0c076e6au,0x0c076e6cu,0x0c076e6eu,0x0c076e70u,0x0c076e72u,
0x0c076e74u,0x0c076e76u,0x0c076e78u,0x0c076e7au,0x0c076e7cu,0x0c076e7eu,0x0c076e80u,0x0c076e82u,0x0c076e84u,0x0c076e86u,0x0c076e88u,0x0c076e8au,0x0c076e8cu,0x0c076e8eu,0x0c076e90u,0x0c076e92u,
0x0c076e94u,0x0c076e96u,0x0c076e98u,0x0c076e9au,0x0c076e9cu,0x0c076e9eu,0x0c076ea0u,0x0c076ea2u,0x0c076ea4u,0x0c076ea6u,0x0c076ea8u,0x0c076eaau,0x0c076eacu,0x0c076eaeu,0x0c076eb0u,0x0c076eb2u,
0x0c076eb4u,0x0c076eb6u,0x0c076eb8u,0x0c076ebau,0x0c076ef4u,0x0c076ef6u,0x0c076ef8u,0x0c076efau,0x0c076efcu,0x0c076efeu,0x0c076f00u,0x0c076f02u,0x0c076f04u,0x0c076f06u,0x0c076f08u,0x0c076f0au,
0x0c076f0cu,0x0c076f0eu,0x0c076f10u,0x0c076f12u,0x0c076f14u,0x0c076f16u,0x0c076f18u,0x0c076f1au,0x0c076f1cu,0x0c076f1eu,0x0c076f20u,0x0c076f22u,0x0c076f24u,0x0c076f26u,0x0c076f28u,0x0c076f2au,
0x0c076f2cu,0x0c076f2eu,0x0c076f30u,0x0c076f32u,0x0c076f34u,0x0c076f36u,0x0c076f38u,0x0c076f3au,0x0c076f3cu,0x0c076f3eu,0x0c076f40u,0x0c076f42u,0x0c076f44u,0x0c076f46u,0x0c076f48u,0x0c076f4au,
0x0c076f4cu,0x0c076f4eu,0x0c076f50u,0x0c076f52u,0x0c076f54u,0x0c076f56u,0x0c076f58u,0x0c076f5au,0x0c076f5cu,0x0c076f5eu,0x0c076f60u,0x0c076f62u,0x0c076f64u,0x0c076f66u,0x0c076f68u,0x0c076f6au,
0x0c076f6cu,0x0c076f6eu,0x0c076f70u,0x0c076f72u,0x0c076f74u,0x0c076f76u,0x0c076f78u,0x0c076f7au,0x0c076f7cu,0x0c076f7eu,0x0c076f80u,0x0c076f82u,0x0c076f84u,0x0c076f86u,0x0c076f88u,0x0c076f8au,
0x0c076f8cu,0x0c076f8eu,0x0c076f90u,0x0c076f92u,0x0c076f94u,0x0c076f96u,0x0c076f98u,0x0c076f9au,0x0c076f9cu,0x0c076f9eu,0x0c076fa0u,0x0c076fa2u,0x0c076fa4u,0x0c076fa6u,0x0c076fa8u,0x0c076faau,
0x0c076facu,0x0c076faeu,0x0c076fb0u,0x0c076fb2u,0x0c076fb4u,0x0c076fb6u,0x0c076fb8u,0x0c076fbau,0x0c076fbcu,0x0c076fbeu,0x0c076fc0u,0x0c076fc2u,0x0c076fc4u,0x0c076fc6u,0x0c076fc8u,0x0c076fcau,
0x0c076fccu,0x0c076fceu,0x0c076fd0u,0x0c076fd2u,0x0c076fd4u,0x0c076fd6u,0x0c076fd8u,0x0c076fdau,0x0c076fdcu,0x0c076fdeu,0x0c076fe0u,0x0c076fe2u,0x0c076fe4u,0x0c076fe6u,0x0c076fe8u,0x0c076feau,
0x0c076fecu,0x0c076feeu,0x0c076ff0u,0x0c076ff2u,0x0c076ff4u,0x0c076ff6u,0x0c076ff8u,0x0c076ffau,0x0c076ffcu,0x0c076ffeu,0x0c077000u,0x0c077002u,0x0c077004u,0x0c077006u,0x0c077008u,0x0c07700au,
0x0c07700cu,0x0c07700eu,0x0c077010u,0x0c077012u,0x0c077014u,0x0c077016u,0x0c077018u,0x0c07701au,0x0c07701cu,0x0c07701eu,0x0c077020u,0x0c077022u,0x0c077024u,0x0c077026u,0x0c077028u,0x0c07702au,
0x0c07702cu,0x0c07702eu,0x0c077030u,0x0c077032u,0x0c077034u,0x0c077036u,0x0c077038u,0x0c07703au,0x0c07703cu,0x0c07703eu,0x0c077040u,0x0c077042u,0x0c077044u,0x0c077046u,0x0c077048u,0x0c07704au,
0x0c07704cu,0x0c07704eu,0x0c077050u,0x0c077052u,0x0c077054u,0x0c077056u,0x0c077058u,0x0c07705au,0x0c07705cu,0x0c07705eu,0x0c077080u,0x0c077082u,0x0c077084u,0x0c077086u,0x0c077088u,0x0c07708au,
0x0c07708cu,0x0c07708eu,0x0c077090u,0x0c077092u,0x0c077094u,0x0c077096u,0x0c077098u,0x0c07709au,0x0c07709cu,0x0c07709eu,0x0c0770a0u,0x0c0770a2u,0x0c0770a4u,0x0c0770a6u,0x0c0770a8u,0x0c0770aau,
0x0c0770acu,0x0c0770aeu,0x0c0770b0u,0x0c0770b2u,0x0c0770b4u,0x0c0770b6u,0x0c0770b8u,0x0c0770bau,0x0c0770bcu,0x0c0770beu,0x0c0770c0u,0x0c0770c2u,0x0c0770c4u,0x0c0770c6u,0x0c0770c8u,0x0c0770cau,
0x0c0770ccu,0x0c0770ceu,0x0c0770d0u,0x0c0770d2u,0x0c0770d4u,0x0c0770d6u,0x0c0770d8u,0x0c0770dau,0x0c0770dcu,0x0c0770deu,0x0c0770e0u,0x0c0770e2u,0x0c0770e4u,0x0c0770e6u,0x0c0770e8u,0x0c0770eau,
0x0c0770ecu,0x0c0770eeu,0x0c0770f0u,0x0c0770f2u,0x0c0770f4u,0x0c0770f6u,0x0c0770f8u,0x0c0770fau,0x0c0770fcu,0x0c0770feu,0x0c077100u,0x0c077102u,0x0c077104u,0x0c077106u,0x0c077108u,0x0c07710au,
0x0c07710cu,0x0c07710eu,0x0c077110u,0x0c077112u,0x0c077114u,0x0c077116u,0x0c077118u,0x0c07711au,0x0c07711cu,0x0c07711eu,0x0c077120u,0x0c077122u,0x0c077124u,0x0c077126u,0x0c077128u,0x0c07712au,
0x0c07712cu,0x0c07712eu,0x0c077130u,0x0c077132u,0x0c077134u,0x0c077136u,0x0c077138u,0x0c07713au,0x0c07713cu,0x0c07713eu,0x0c077140u,0x0c077142u,0x0c077144u,0x0c077146u,0x0c077148u,0x0c07714au,
0x0c07714cu,0x0c07714eu,0x0c077150u,0x0c077152u,0x0c077154u,0x0c077156u,0x0c077158u,0x0c07715au,0x0c07715cu,0x0c07715eu,0x0c077160u,0x0c077162u,0x0c077164u,0x0c077166u,0x0c077168u,0x0c07716au,
0x0c07716cu,0x0c07716eu,0x0c077170u,0x0c077172u,0x0c077174u,0x0c077176u,0x0c077178u,0x0c07717au,0x0c07717cu,0x0c07717eu,0x0c077180u,0x0c077182u,0x0c077184u,0x0c077186u,0x0c077188u,0x0c07718au,
0x0c07718cu,0x0c07718eu,0x0c077190u,0x0c0771acu,0x0c0771aeu,0x0c0771b0u,0x0c0771b2u,0x0c0771b4u,0x0c0771b6u,0x0c0771b8u,0x0c0771bau,0x0c0771bcu,0x0c0771beu,0x0c0771c0u,0x0c0771c2u,0x0c0771c4u,
0x0c0771c6u,0x0c0771c8u,0x0c0771cau,0x0c0771ccu,0x0c0771ceu,0x0c0771d0u,0x0c0771d2u,0x0c0771d4u,0x0c0771d6u,0x0c0771d8u,0x0c0771dau,0x0c0771dcu,0x0c0771deu,0x0c0771e0u,0x0c0771e2u,0x0c0771e4u,
0x0c0771e6u,0x0c0771e8u,0x0c0771eau,0x0c0771ecu,0x0c0771eeu,0x0c0771f0u,0x0c0771f2u,0x0c0771f4u,0x0c0771f6u,0x0c0771f8u,0x0c0771fau,0x0c0771fcu,0x0c0771feu,0x0c077200u,0x0c077202u,0x0c077204u,
0x0c077206u,0x0c077208u,0x0c07720au,0x0c07720cu,0x0c07720eu,0x0c077210u,0x0c077212u,0x0c077214u,0x0c077216u,0x0c077218u,0x0c07721au,0x0c07721cu,0x0c07721eu,0x0c077220u,0x0c077222u,0x0c077224u,
0x0c077226u,0x0c077228u,0x0c07722au,0x0c07722cu,0x0c07722eu,0x0c077230u,0x0c077232u,0x0c077234u,0x0c077236u,0x0c077238u,0x0c07723au,0x0c07723cu,0x0c07723eu,0x0c077240u,0x0c077242u,0x0c077244u,
0x0c077246u,0x0c077248u,0x0c07724au,0x0c07724cu,0x0c07724eu,0x0c077250u,0x0c077252u,0x0c077254u,0x0c077256u,0x0c077258u,0x0c07725au,0x0c07725cu,0x0c07725eu,0x0c077260u,0x0c077262u,0x0c077264u,
0x0c077266u,0x0c077268u,0x0c07726au,0x0c07726cu,0x0c07726eu,0x0c077270u,0x0c077272u,0x0c077274u,0x0c077276u,0x0c077278u,0x0c07727au,0x0c07727cu,0x0c07727eu,0x0c077280u,0x0c077282u,0x0c077284u,
0x0c077286u,0x0c077288u,0x0c07728au,0x0c0772a0u,0x0c0772a2u,0x0c0772a4u,0x0c0772a6u,0x0c0772a8u,0x0c0772aau,0x0c0772acu,0x0c0772aeu,0x0c0772b0u,0x0c0772b2u,0x0c0772b4u,0x0c0772b6u,0x0c0772b8u,
0x0c0772bau,0x0c0772bcu,0x0c0772beu,0x0c0772c0u,0x0c0772c2u,0x0c0772c4u,0x0c0772c6u,0x0c0772c8u,0x0c0772cau,0x0c0772ccu,0x0c0772ceu,0x0c0772d0u,0x0c0772d2u,0x0c0772d4u,0x0c0772d6u,0x0c0772d8u,
0x0c0772dau,0x0c0772dcu,0x0c0772deu,0x0c0772e0u,0x0c0772e2u,0x0c0772e4u,0x0c0772e6u,0x0c0772e8u,0x0c0772eau,0x0c0772ecu,0x0c0772eeu,0x0c0772f0u,0x0c0772f2u,0x0c0772f4u,0x0c0772f6u,0x0c0772f8u,
0x0c0772fau,0x0c0772fcu,0x0c0772feu,0x0c077300u,0x0c077302u,0x0c077304u,0x0c077306u,0x0c077308u,0x0c07730au,0x0c07730cu,0x0c07730eu,0x0c077310u,0x0c077312u,0x0c077314u,0x0c077316u,0x0c077318u,
0x0c07731au,0x0c07731cu,0x0c07731eu,0x0c077320u,0x0c077322u,0x0c077324u,0x0c077326u,0x0c077328u,0x0c07732au,0x0c07732cu,0x0c07732eu,0x0c077330u,0x0c077332u,0x0c077334u,0x0c077336u,0x0c077338u,
0x0c07733au,0x0c07733cu,0x0c07734cu,0x0c07734eu,0x0c077350u,0x0c077352u,0x0c077354u,0x0c077356u,0x0c077358u,0x0c07735au,0x0c07735cu,0x0c07735eu,0x0c077360u,0x0c077362u,0x0c077364u,0x0c077366u,
0x0c077368u,0x0c07736au,0x0c07736cu,0x0c07736eu,0x0c077370u,0x0c077372u,0x0c077374u,0x0c077376u,0x0c077378u,0x0c07737au,0x0c07737cu,0x0c07737eu,0x0c077380u,0x0c077382u,0x0c077384u,0x0c077386u,
0x0c077388u,0x0c07738au,0x0c07738cu,0x0c07738eu,0x0c077390u,0x0c077392u,0x0c077394u,0x0c077396u,0x0c077398u,0x0c07739au,0x0c07739cu,0x0c07739eu,0x0c0773a0u,0x0c0773a2u,0x0c0773a4u,0x0c0773a6u,
0x0c0773a8u,0x0c0773aau,0x0c0773acu,0x0c0773aeu,0x0c0773b0u,0x0c0773b2u,0x0c0773b4u,0x0c0773b6u,0x0c0773b8u,0x0c0773bau,0x0c0773bcu,0x0c0773beu,0x0c0773c0u,0x0c0773c2u,0x0c0773c4u,0x0c0773c6u,
0x0c0773c8u,0x0c0773cau,0x0c0773ccu,0x0c0773ceu,0x0c0773d0u,0x0c0773d2u,0x0c0773d4u,0x0c0773d6u,0x0c0773d8u,0x0c0773dau,0x0c0773dcu,0x0c0773deu,0x0c0773e0u,0x0c0773e2u,0x0c0773e4u,0x0c0773e6u,
0x0c0773e8u,0x0c0773eau,0x0c0773ecu,0x0c0773eeu,0x0c0773f0u,0x0c0773f2u,0x0c0773f4u,0x0c0773f6u,0x0c0773f8u,0x0c0773fau,0x0c0773fcu,0x0c0773feu,0x0c077400u,0x0c077402u,0x0c077404u,0x0c077406u,
0x0c077408u,0x0c07740au,0x0c07740cu,0x0c07740eu,0x0c077410u,0x0c077412u,0x0c077414u,0x0c077416u,0x0c077418u,0x0c07741au,0x0c07741cu,0x0c07741eu,0x0c077420u,0x0c077422u,0x0c077424u,0x0c077426u,
0x0c077428u,0x0c07742au,0x0c07742cu,0x0c07742eu,0x0c077430u,0x0c077432u,0x0c077434u,0x0c077436u,0x0c077438u,0x0c07743au,0x0c07743cu,0x0c07743eu,0x0c077440u,0x0c077442u,0x0c077444u,0x0c077446u,
0x0c077448u,0x0c07744au,0x0c07744cu,0x0c07746cu,0x0c07746eu,0x0c077470u,0x0c077472u,0x0c077474u,0x0c077476u,0x0c077478u,0x0c07747au,0x0c07747cu,0x0c07747eu,0x0c077480u,0x0c077482u,0x0c077484u,
0x0c077486u,0x0c077488u,0x0c07748au,0x0c07748cu,0x0c07748eu,0x0c077490u,0x0c077492u,0x0c077494u,0x0c077496u,0x0c077498u,0x0c07749au,0x0c07749cu,0x0c07749eu,0x0c0774a0u,0x0c0774a2u,0x0c0774a4u,
0x0c0774a6u,0x0c0774a8u,0x0c0774aau,0x0c0774acu,0x0c0774aeu,0x0c0774b0u,0x0c0774b2u,0x0c0774b4u,0x0c0774b6u,0x0c0774b8u,0x0c0774bau,0x0c0774bcu,0x0c0774beu,0x0c0774c0u,0x0c0774c2u,0x0c0774c4u,
0x0c0774c6u,0x0c0774c8u,0x0c0774cau,0x0c0774ccu,0x0c0774ceu,0x0c0774d0u,0x0c0774d2u,0x0c0774d4u,0x0c0774d6u,0x0c0774d8u,0x0c0774dau,0x0c0774dcu,0x0c0774deu,0x0c0774e0u,0x0c0774e2u,0x0c0774e4u,
0x0c0774e6u,0x0c0774e8u,0x0c0774eau,0x0c0774ecu,0x0c0774eeu,0x0c0774f0u,0x0c0774f2u,0x0c0774f4u,0x0c0774f6u,0x0c0774f8u,0x0c0774fau,0x0c0774fcu,0x0c0774feu,0x0c077500u,0x0c077502u,0x0c077504u,
0x0c077506u,0x0c077508u,0x0c07750au,0x0c07750cu,0x0c07750eu,0x0c077510u,0x0c077512u,0x0c077514u,0x0c077516u,0x0c077518u,0x0c07751au,0x0c07751cu,0x0c07751eu,0x0c077520u,0x0c077522u,0x0c077524u,
0x0c077526u,0x0c077528u,0x0c07752au,0x0c07752cu,0x0c07752eu,0x0c077530u,0x0c077532u,0x0c077534u,0x0c077536u,0x0c077538u,0x0c07753au,0x0c07753cu,0x0c07753eu,0x0c077540u,0x0c077542u,0x0c077544u,
0x0c077546u,0x0c077548u,0x0c07754au,0x0c07754cu,0x0c07754eu,0x0c077550u,0x0c077552u,0x0c077554u,0x0c077556u,0x0c077558u,0x0c07755au,0x0c07755cu,0x0c07755eu,0x0c077560u,0x0c077562u,0x0c077564u,
0x0c077566u,0x0c077568u,0x0c07756au,0x0c077584u,0x0c077586u,0x0c077588u,0x0c07758au,0x0c07758cu,0x0c07758eu,0x0c077590u,0x0c077592u,0x0c077594u,0x0c077596u,0x0c077598u,0x0c07759au,0x0c07759cu,
0x0c07759eu,0x0c0775a0u,0x0c0775a2u,0x0c0775a4u,0x0c0775a6u,0x0c0775a8u,0x0c0775aau,0x0c0775acu,0x0c0775aeu,0x0c0775b0u,0x0c0775b2u,0x0c0775b4u,0x0c0775b6u,0x0c0775b8u,0x0c0775bau,0x0c0775bcu,
0x0c0775beu,0x0c0775c0u,0x0c0775c2u,0x0c0775c4u,0x0c0775c6u,0x0c0775c8u,0x0c0775cau,0x0c0775ccu,0x0c0775ceu,0x0c0775d0u,0x0c0775d2u,0x0c0775d4u,0x0c0775d6u,0x0c0775d8u,0x0c0775dau,0x0c0775dcu,
0x0c0775deu,0x0c0775e0u,0x0c0775e2u,0x0c0775e4u,0x0c0775e6u,0x0c0775e8u,0x0c0775eau,0x0c0775ecu,0x0c0775eeu,0x0c0775f0u,0x0c0775f2u,0x0c0775f4u,0x0c0775f6u,0x0c0775f8u,0x0c0775fau,0x0c0775fcu,
0x0c077614u,0x0c077616u,0x0c077618u,0x0c07761au,0x0c07761cu,0x0c07761eu,0x0c077620u,0x0c077622u,0x0c077624u,0x0c077626u,0x0c077628u,0x0c07762au,0x0c07762cu,0x0c07762eu,0x0c077630u,0x0c077632u,
0x0c077634u,0x0c077636u,0x0c077638u,0x0c07763au,0x0c07763cu,0x0c07763eu,0x0c077640u,0x0c077642u,0x0c077644u,0x0c077646u,0x0c077648u,0x0c07764au,0x0c07764cu,0x0c07764eu,0x0c077650u,0x0c077652u,
0x0c077654u,0x0c077656u,0x0c077658u,0x0c07765au,0x0c07765cu,0x0c07765eu,0x0c077660u,0x0c077662u,0x0c077664u,0x0c077666u,0x0c077668u,0x0c07766au,0x0c07766cu,0x0c07766eu,0x0c077670u,0x0c077672u,
0x0c077674u,0x0c077676u,0x0c077678u,0x0c07767au,0x0c07767cu,0x0c07767eu,0x0c077680u,0x0c077682u,0x0c077684u,0x0c077686u,0x0c077688u,0x0c07768au,0x0c07768cu,0x0c07768eu,0x0c077690u,0x0c077692u,
0x0c077694u,0x0c077696u,0x0c077698u,0x0c07769au,0x0c07769cu,0x0c07769eu,0x0c0776a0u,0x0c0776a2u,0x0c0776a4u,0x0c0776a6u,0x0c0776a8u,0x0c0776aau,0x0c0776acu,0x0c0776aeu,0x0c0776b0u,0x0c0776b2u,
0x0c0776b4u,0x0c0776b6u,0x0c0776b8u,0x0c0776bau,0x0c0776bcu,0x0c0776beu,0x0c0776c0u,0x0c0776c2u,0x0c0776c4u,0x0c0776c6u,0x0c0776c8u,0x0c0776cau,0x0c0776ccu,0x0c0776ceu,0x0c0776d0u,0x0c0776d2u,
0x0c0776d4u,0x0c0776d6u,0x0c0776d8u,0x0c0776dau,0x0c0776dcu,0x0c0776deu,0x0c0776e0u,0x0c0776e2u,0x0c0776e4u,0x0c0776e6u,0x0c0776e8u,0x0c0776eau,0x0c0776ecu,0x0c0776eeu,0x0c0776f0u,0x0c0776f2u,
0x0c0776f4u,0x0c0776f6u,0x0c0776f8u,0x0c0776fau,0x0c0776fcu,0x0c0776feu,0x0c077700u,0x0c077702u,0x0c077704u,0x0c077706u,0x0c077708u,0x0c07770au,0x0c07770cu,0x0c07770eu,0x0c077710u,0x0c077712u,
0x0c077714u,0x0c077716u,0x0c077718u,0x0c07771au,0x0c07771cu,0x0c07771eu,0x0c077720u,0x0c077722u,0x0c077724u,0x0c077726u,0x0c077728u,0x0c07772au,0x0c07772cu,0x0c07772eu,0x0c077730u,0x0c077732u,
0x0c077734u,0x0c077736u,0x0c077738u,0x0c07773au,0x0c07773cu,0x0c07773eu,0x0c077740u,0x0c077742u,0x0c077744u,0x0c077746u,0x0c077748u,0x0c07774au,0x0c07774cu,0x0c07774eu,0x0c077750u,0x0c077752u,
0x0c077754u,0x0c077756u,0x0c077758u,0x0c07775au,0x0c07775cu,0x0c07775eu,0x0c077760u,0x0c077762u,0x0c077764u,0x0c077784u,0x0c077786u,0x0c077788u,0x0c07778au,0x0c07778cu,0x0c07778eu,0x0c077790u,
0x0c077792u,0x0c077794u,0x0c077796u,0x0c077798u,0x0c07779au,0x0c07779cu,0x0c07779eu,0x0c0777a0u,0x0c0777a2u,0x0c0777a4u,0x0c0777a6u,0x0c0777a8u,0x0c0777aau,0x0c0777acu,0x0c0777aeu,0x0c0777b0u,
0x0c0777b2u,0x0c0777b4u,0x0c0777b6u,0x0c0777b8u,0x0c0777bau,0x0c0777bcu,0x0c0777beu,0x0c0777c0u,0x0c0777c2u,0x0c0777c4u,0x0c0777c6u,0x0c0777c8u,0x0c0777cau,0x0c0777ccu,0x0c0777ceu,0x0c0777d0u,
0x0c0777d2u,0x0c0777d4u,0x0c0777d6u,0x0c0777d8u,0x0c0777dau,0x0c0777dcu,0x0c0777deu,0x0c0777e0u,0x0c0777e2u,0x0c0777e4u,0x0c0777e6u,0x0c0777e8u,0x0c0777eau,0x0c0777ecu,0x0c0777eeu,0x0c0777f0u,
0x0c0777f2u,0x0c0777f4u,0x0c0777f6u,0x0c0777f8u,0x0c0777fau,0x0c0777fcu,0x0c0777feu,0x0c077800u,0x0c077802u,0x0c077804u,0x0c077806u,0x0c077808u,0x0c07780au,0x0c07780cu,0x0c07780eu,0x0c077810u,
0x0c077812u,0x0c077814u,0x0c077816u,0x0c077818u,0x0c07781au,0x0c07781cu,0x0c07781eu,0x0c077820u,0x0c077822u,0x0c077824u,0x0c077826u,0x0c077828u,0x0c07782au,0x0c07782cu,0x0c07782eu,0x0c077830u,
0x0c077832u,0x0c077834u,0x0c077836u,0x0c077838u,0x0c07783au,0x0c07783cu,0x0c07783eu,0x0c077840u,0x0c077842u,0x0c077844u,0x0c077846u,0x0c077848u,0x0c07784au,0x0c07784cu,0x0c07784eu,0x0c077850u,
0x0c077852u,0x0c077854u,0x0c077856u,0x0c077858u,0x0c07785au,0x0c07785cu,0x0c07785eu,0x0c077860u,0x0c077862u,0x0c077864u,0x0c077866u,0x0c077868u,0x0c07786au,0x0c07786cu,0x0c07786eu,0x0c077870u,
0x0c077872u,0x0c077874u,0x0c077876u,0x0c077878u,0x0c07787au,0x0c07787cu,0x0c07787eu,0x0c077880u,0x0c077882u,0x0c077884u,0x0c077886u,0x0c077888u,0x0c07788au,0x0c0778a4u,0x0c0778a6u,0x0c0778a8u,
0x0c0778aau,0x0c0778acu,0x0c0778aeu,0x0c0778b0u,0x0c0778b2u,0x0c0778b4u,0x0c0778b6u,0x0c0778b8u,0x0c0778bau,0x0c0778bcu,0x0c0778beu,0x0c0778c0u,0x0c0778c2u,0x0c0778c4u,0x0c0778c6u,0x0c0778c8u,
0x0c0778cau,0x0c0778ccu,0x0c0778ceu,0x0c0778d0u,0x0c0778d2u,0x0c0778d4u,0x0c0778d6u,0x0c0778d8u,0x0c0778dau,0x0c0778dcu,0x0c0778deu,0x0c0778e0u,0x0c0778e2u,0x0c0778e4u,0x0c0778e6u,0x0c0778e8u,
0x0c0778eau,0x0c0778ecu,0x0c0778eeu,0x0c0778f0u,0x0c0778f2u,0x0c0778f4u,0x0c0778f6u,0x0c0778f8u,0x0c0778fau,0x0c0778fcu,0x0c0778feu,0x0c077900u,0x0c077902u,0x0c077904u,0x0c077906u,0x0c077908u,
0x0c07790au,0x0c07790cu,0x0c07790eu,0x0c077910u,0x0c077912u,0x0c077914u,0x0c077916u,0x0c077918u,0x0c07791au,0x0c07791cu,0x0c07791eu,0x0c077920u,0x0c077922u,0x0c077924u,0x0c077926u,0x0c077928u,
0x0c07792au,0x0c07792cu,0x0c07792eu,0x0c077930u,0x0c077932u,0x0c077934u,0x0c077936u,0x0c077938u,0x0c07793au,0x0c07793cu,0x0c07793eu,0x0c077940u,0x0c077942u,0x0c077944u,0x0c077946u,0x0c077948u,
0x0c07794au,0x0c07794cu,0x0c07794eu,0x0c077950u,0x0c077952u,0x0c077954u,0x0c077956u,0x0c077958u,0x0c07795au,0x0c07795cu,0x0c07795eu,0x0c077960u,0x0c077962u,0x0c077964u,0x0c077966u,0x0c077968u,
0x0c07796au,0x0c07796cu,0x0c07796eu,0x0c077970u,0x0c077972u,0x0c077974u,0x0c077976u,0x0c077978u,0x0c07797au,0x0c07797cu,0x0c07797eu,0x0c077980u,0x0c077998u,0x0c07799au,0x0c07799cu,0x0c07799eu,
0x0c0779a0u,0x0c0779a2u,0x0c0779a4u,0x0c0779a6u,0x0c0779a8u,0x0c0779aau,0x0c0779acu,0x0c0779aeu,0x0c0779b0u,0x0c0779b2u,0x0c0779b4u,0x0c0779b6u,0x0c0779b8u,0x0c0779bau,0x0c0779bcu,0x0c0779beu,
0x0c0779c0u,0x0c0779c2u,0x0c0779c4u,0x0c0779c6u,0x0c0779c8u,0x0c0779cau,0x0c0779ccu,0x0c0779ceu,0x0c0779d0u,0x0c0779d2u,0x0c0779d4u,0x0c0779d6u,0x0c0779d8u,0x0c0779dau,0x0c0779dcu,0x0c0779deu,
0x0c0779e0u,0x0c0779e2u,0x0c0779e4u,0x0c0779e6u,0x0c0779e8u,0x0c0779eau,0x0c0779ecu,0x0c0779eeu,0x0c0779f0u,0x0c0779f2u,0x0c0779f4u,0x0c0779f6u,0x0c0779f8u,0x0c0779fau,0x0c0779fcu,0x0c0779feu,
0x0c077a00u,0x0c077a02u,0x0c077a04u,0x0c077a06u,0x0c077a08u,0x0c077a0au,0x0c077a0cu,0x0c077a0eu,0x0c077a10u,0x0c077a12u,0x0c077a14u,0x0c077a16u,0x0c077a18u,0x0c077a1au,0x0c077a1cu,0x0c077a1eu,
0x0c077a20u,0x0c077a22u,0x0c077a24u,0x0c077a26u,0x0c077a28u,0x0c077a2au,0x0c077a2cu,0x0c077a2eu,0x0c077a30u,0x0c077a32u,0x0c077a34u,0x0c077a36u,0x0c077a38u,0x0c077a3au,0x0c077a3cu,0x0c077a3eu,
0x0c077a40u,0x0c077a42u,0x0c077a44u,0x0c077a46u,0x0c077a48u,0x0c077a4au,0x0c077a4cu,0x0c077a4eu,0x0c077a50u,0x0c077a52u,0x0c077a54u,0x0c077a56u,0x0c077a58u,0x0c077a5au,0x0c077a5cu,0x0c077a5eu,
0x0c077a60u,0x0c077a62u,0x0c077a64u,0x0c077a66u,0x0c077a68u,0x0c077a6au,0x0c077a6cu,0x0c077a6eu,0x0c077a70u,0x0c077a72u,0x0c077a74u,0x0c077a76u,0x0c077a78u,0x0c077a7au,0x0c077a7cu,0x0c077a7eu,
0x0c077a80u,0x0c077a82u,0x0c077a84u,0x0c077a86u,0x0c077a88u,0x0c077a8au,0x0c077a8cu,0x0c077a8eu,0x0c077a90u,0x0c077a92u,0x0c077a94u,0x0c077a96u,0x0c077a98u,0x0c077a9au,0x0c077a9cu,0x0c077a9eu,
0x0c077aa0u,0x0c077aa2u,0x0c077aa4u,0x0c077aa6u,0x0c077aa8u,0x0c077aaau,0x0c077aacu,0x0c077aaeu,0x0c077ad0u,0x0c077ad2u,0x0c077ad4u,0x0c077ad6u,0x0c077ad8u,0x0c077adau,0x0c077adcu,0x0c077adeu,
0x0c077ae0u,0x0c077ae2u,0x0c077ae4u,0x0c077ae6u,0x0c077ae8u,0x0c077aeau,0x0c077aecu,0x0c077aeeu,0x0c077af0u,0x0c077af2u,0x0c077af4u,0x0c077af6u,0x0c077af8u,0x0c077afau,0x0c077afcu,0x0c077afeu,
0x0c077b00u,0x0c077b02u,0x0c077b04u,0x0c077b06u,0x0c077b08u,0x0c077b0au,0x0c077b0cu,0x0c077b0eu,0x0c077b10u,0x0c077b12u,0x0c077b14u,0x0c077b16u,0x0c077b18u,0x0c077b1au,0x0c077b1cu,0x0c077b1eu,
0x0c077b20u,0x0c077b22u,0x0c077b24u,0x0c077b26u,0x0c077b28u,0x0c077b2au,0x0c077b2cu,0x0c077b2eu,0x0c077b30u,0x0c077b32u,0x0c077b34u,0x0c077b36u,0x0c077b38u,0x0c077b3au,0x0c077b3cu,0x0c077b3eu,
0x0c077b40u,0x0c077b42u,0x0c077b44u,0x0c077b46u,0x0c077b48u,0x0c077b4au,0x0c077b4cu,0x0c077b4eu,0x0c077b50u,0x0c077b52u,0x0c077b54u,0x0c077b56u,0x0c077b58u,0x0c077b5au,0x0c077b5cu,0x0c077b5eu,
0x0c077b60u,0x0c077b62u,0x0c077b64u,0x0c077b66u,0x0c077b68u,0x0c077b6au,0x0c077b6cu,0x0c077b6eu,0x0c077b70u,0x0c077b72u,0x0c077b74u,0x0c077b76u,0x0c077b78u,0x0c077b7au,0x0c077b7cu,0x0c077b7eu,
0x0c077b80u,0x0c077b82u,0x0c077b84u,0x0c077b86u,0x0c077b88u,0x0c077b8au,0x0c077b8cu,0x0c077b8eu,0x0c077b90u,0x0c077b92u,0x0c077b94u,0x0c077b96u,0x0c077b98u,0x0c077b9au,0x0c077b9cu,0x0c077b9eu,
0x0c077bbcu,0x0c077bbeu,0x0c077bc0u,0x0c077bc2u,0x0c077bc4u,0x0c077bc6u,0x0c077bc8u,0x0c077bcau,0x0c077bccu,0x0c077bceu,0x0c077bd0u,0x0c077bd2u,0x0c077bd4u,0x0c077bd6u,0x0c077bd8u,0x0c077bdau,
0x0c077bdcu,0x0c077bdeu,0x0c077be0u,0x0c077be2u,0x0c077be4u,0x0c077be6u,0x0c077be8u,0x0c077beau,0x0c077becu,0x0c077beeu,0x0c077bf0u,0x0c077bf2u,0x0c077bf4u,0x0c077bf6u,0x0c077bf8u,0x0c077bfau,
0x0c077bfcu,0x0c077bfeu,0x0c077c00u,0x0c077c02u,0x0c077c04u,0x0c077c06u,0x0c077c08u,0x0c077c0au,0x0c077c0cu,0x0c077c0eu,0x0c077c10u,0x0c077c12u,0x0c077c14u,0x0c077c16u,0x0c077c18u,0x0c077c1au,
0x0c077c1cu,0x0c077c1eu,0x0c077c20u,0x0c077c22u,0x0c077c24u,0x0c077c26u,0x0c077c28u,0x0c077c2au,0x0c077c2cu,0x0c077c2eu,0x0c077c30u,0x0c077c32u,0x0c077c34u,0x0c077c36u,0x0c077c38u,0x0c077c3au,
0x0c077c3cu,0x0c077c3eu,0x0c077c40u,0x0c077c42u,0x0c077c44u,0x0c077c46u,0x0c077c48u,0x0c077c4au,0x0c077c4cu,0x0c077c4eu,0x0c077c50u,0x0c077c52u,0x0c077c54u,0x0c077c56u,0x0c077c58u,0x0c077c5au,
0x0c077c5cu,0x0c077c5eu,0x0c077c60u,0x0c077c62u,0x0c077c64u,0x0c077c66u,0x0c077c68u,0x0c077c6au,0x0c077c6cu,0x0c077c6eu,0x0c077c70u,0x0c077c72u,0x0c077c74u,0x0c077c76u,0x0c077c78u,0x0c077c7au,
0x0c077c7cu,0x0c077c7eu,0x0c077c80u,0x0c077c82u,0x0c077c84u,0x0c077c86u,0x0c077c88u,0x0c077c8au,0x0c077c8cu,0x0c077c8eu,0x0c077c90u,0x0c077c92u,0x0c077c94u,0x0c077c96u,0x0c077c98u,0x0c077c9au,
0x0c077c9cu,0x0c077c9eu,0x0c077ca0u,0x0c077ca2u,0x0c077ca4u,0x0c077ca6u,0x0c077ca8u,0x0c077caau,0x0c077cacu,0x0c077caeu,0x0c077cb0u,0x0c077cb2u,0x0c077cb4u,0x0c077cb6u,0x0c077cb8u,0x0c077cbau,
0x0c077cbcu,0x0c077cbeu,0x0c077cc0u,0x0c077cc2u,0x0c077cc4u,0x0c077cc6u,0x0c077cc8u,0x0c077ccau,0x0c077cccu,0x0c077cceu,0x0c077cd0u,0x0c077cd2u,0x0c077cd4u,0x0c077cd6u,0x0c077cd8u,0x0c077cdau,
0x0c077cdcu,0x0c077cdeu,0x0c077ce0u,0x0c077ce2u,0x0c077ce4u,0x0c077ce6u,0x0c077ce8u,0x0c077ceau,0x0c077cecu,0x0c077ceeu,0x0c077cf0u,0x0c077cf2u,0x0c077cf4u,0x0c077d1cu,0x0c077d1eu,0x0c077d20u,
0x0c077d22u,0x0c077d24u,0x0c077d26u,0x0c077d28u,0x0c077d2au,0x0c077d2cu,0x0c077d2eu,0x0c077d30u,0x0c077d32u,0x0c077d34u,0x0c077d36u,0x0c077d38u,0x0c077d3au,0x0c077d3cu,0x0c077d3eu,0x0c077d40u,
0x0c077d42u,0x0c077d44u,0x0c077d46u,0x0c077d48u,0x0c077d4au,0x0c077d4cu,0x0c077d4eu,0x0c077d50u,0x0c077d52u,0x0c077d54u,0x0c077d56u,0x0c077d58u,0x0c077d5au,0x0c077d5cu,0x0c077d5eu,0x0c077d60u,
0x0c077d62u,0x0c077d64u,0x0c077d66u,0x0c077d68u,0x0c077d6au,0x0c077d6cu,0x0c077d6eu,0x0c077d70u,0x0c077d72u,0x0c077d74u,0x0c077d76u,0x0c077d78u,0x0c077d7au,0x0c077d7cu,0x0c077d7eu,0x0c077d80u,
0x0c077d82u,0x0c077d84u,0x0c077d86u,0x0c077d88u,0x0c077d8au,0x0c077d8cu,0x0c077d8eu,0x0c077d90u,0x0c077d92u,0x0c077d94u,0x0c077d96u,0x0c077d98u,0x0c077d9au,0x0c077d9cu,0x0c077d9eu,0x0c077da0u,
0x0c077da2u,0x0c077da4u,0x0c077da6u,0x0c077da8u,0x0c077daau,0x0c077dacu,0x0c077daeu,0x0c077db0u,0x0c077db2u,0x0c077db4u,0x0c077db6u,0x0c077db8u,0x0c077dbau,0x0c077dbcu,0x0c077dbeu,0x0c077dc0u,
0x0c077dc2u,0x0c077dc4u,0x0c077dc6u,0x0c077dc8u,0x0c077dcau,0x0c077dccu,0x0c077dceu,0x0c077dd0u,0x0c077dd2u,0x0c077dd4u,0x0c077dd6u,0x0c077dd8u,0x0c077ddau,0x0c077e04u,0x0c077e06u,0x0c077e08u,
0x0c077e0au,0x0c077e0cu,0x0c077e0eu,0x0c077e10u,0x0c077e12u,0x0c077e14u,0x0c077e16u,0x0c077e18u,0x0c077e1au,0x0c077e1cu,0x0c077e1eu,0x0c077e20u,0x0c077e22u,0x0c077e24u,0x0c077e26u,0x0c077e28u,
0x0c077e2au,0x0c077e2cu,0x0c077e2eu,0x0c077e30u,0x0c077e32u,0x0c077e34u,0x0c077e36u,0x0c077e38u,0x0c077e3au,0x0c077e3cu,0x0c077e3eu,0x0c077e40u,0x0c077e42u,0x0c077e44u,0x0c077e46u,0x0c077e48u,
0x0c077e4au,0x0c077e4cu,0x0c077e4eu,0x0c077e50u,0x0c077e52u,0x0c077e54u,0x0c077e56u,0x0c077e58u,0x0c077e5au,0x0c078044u,0x0c078046u,0x0c078048u,0x0c07804au,0x0c07804cu,0x0c07804eu,0x0c078050u,
0x0c078052u,0x0c078054u,0x0c078056u,0x0c078058u,0x0c07805au,0x0c07805cu,0x0c07805eu,0x0c078060u,0x0c078062u,0x0c078064u,0x0c078066u,0x0c078068u,0x0c07806au,0x0c07806cu,0x0c07806eu,0x0c078070u,
0x0c078072u,0x0c078074u,0x0c078076u,0x0c078078u,0x0c07807au,0x0c07807cu,0x0c07807eu,0x0c078080u,0x0c078082u,0x0c078084u,0x0c078086u,0x0c078088u,0x0c07808au,0x0c07808cu,0x0c07808eu,0x0c078090u,
0x0c078092u,0x0c078094u,0x0c078096u,0x0c078098u,0x0c07809au,0x0c07809cu,0x0c07809eu,0x0c0780a0u,0x0c0780a2u,0x0c0780a4u,0x0c0780a6u,0x0c0780a8u,0x0c0780aau,0x0c0780acu,0x0c0780aeu,0x0c0780b0u,
0x0c0780b2u,0x0c0780b4u,0x0c0780b6u,0x0c0780b8u,0x0c0780bau,0x0c0780bcu,0x0c0780beu,0x0c0780c0u,0x0c0780c2u,0x0c0780c4u,0x0c0780c6u,0x0c0780c8u,0x0c0780cau,0x0c0780ccu,0x0c0780ceu,0x0c0780d0u,
0x0c0780d2u,0x0c0780d4u,0x0c0780d6u,0x0c0780d8u,0x0c0780dau,0x0c0780dcu,0x0c0780deu,0x0c0780e0u,0x0c0780e2u,0x0c0780e4u,0x0c0780e6u,0x0c0780e8u,0x0c0780eau,0x0c0780ecu,0x0c0780eeu,0x0c0780f0u,
0x0c0780f2u,0x0c0780f4u,0x0c0780f6u,0x0c0780f8u,0x0c0780fau,0x0c0780fcu,0x0c0780feu,0x0c078100u,0x0c078102u,0x0c078104u,0x0c078106u,0x0c078108u,0x0c07810au,0x0c07810cu,0x0c07810eu,0x0c078170u,
0x0c0781bau,0x0c0781bcu,0x0c0781beu,0x0c0781c0u,0x0c07b9aeu,0x0c07b9b0u,0x0c07b9b2u,0x0c07b9b4u,0x0c07b9b6u,0x0c07b9b8u,0x0c07b9bau,0x0c07b9bcu,0x0c07b9beu,0x0c07b9c0u,0x0c07b9c2u,0x0c07b9c4u,
0x0c07b9c6u,0x0c07b9c8u,0x0c07b9cau,0x0c07b9ccu,0x0c07b9ceu,0x0c07b9d0u,0x0c07b9d2u,0x0c07b9d4u,0x0c07b9d6u,0x0c07b9d8u,0x0c07b9dau,0x0c07b9dcu,0x0c07b9deu,0x0c07b9e0u,0x0c07b9e2u,0x0c07b9e4u,
0x0c07b9e6u,0x0c07b9e8u,0x0c07b9eau,0x0c07b9ecu,0x0c07b9eeu,0x0c07b9f0u,0x0c07b9f2u,0x0c07b9f4u,0x0c07b9f6u,0x0c07b9f8u,0x0c07b9fau,0x0c07b9fcu,0x0c07b9feu,0x0c07ba00u,0x0c07ba02u,0x0c07ba04u,
0x0c07ba06u,0x0c07ba08u,0x0c07c534u,0x0c07c536u,0x0c07c538u,0x0c07c53au,0x0c07c53cu,0x0c07c53eu,0x0c07c600u,0x0c07c602u,0x0c07c604u,0x0c07c606u,0x0c07c608u,0x0c07c60au,0x0c07c60cu,0x0c07c60eu,
0x0c07c610u,0x0c07c820u,0x0c07c822u,0x0c07c824u,0x0c07c826u,0x0c07c828u,0x0c07c82au,0x0c07c82cu,0x0c07c82eu,0x0c07c830u,0x0c07c832u,0x0c07c834u,0x0c07c836u,0x0c07c838u,0x0c07c83au,0x0c07c83cu,
0x0c07c83eu,0x0c07c840u,0x0c07c842u,0x0c07c844u,0x0c07c846u,0x0c07c848u,0x0c07c84au,0x0c07c84cu,0x0c07c84eu,0x0c07c850u,0x0c07c852u,0x0c07c854u,0x0c07c856u,0x0c07c858u,0x0c07c85au,0x0c07c85cu,
0x0c07c85eu,0x0c07c860u,0x0c07c862u,0x0c07c864u,0x0c07c866u,0x0c07c868u,0x0c07c86au,0x0c07c99au,0x0c07c99cu,0x0c08049cu,0x0c08049eu,0x0c0804a0u,0x0c0804a2u,0x0c081184u,0x0c081186u,0x0c081188u,
0x0c08118au,0x0c08118cu,0x0c08118eu,0x0c081190u,0x0c081192u,0x0c0968d0u,0x0c0968d2u,0x0c0968d4u,0x0c0968d6u,0x0c0968d8u,0x0c0968dau,0x0c0968dcu,0x0c0968deu,0x0c0968e0u,0x0c0968e2u,0x0c0968e4u,
0x0c0968e6u,0x0c0968e8u,0x0c0968eau,0x0c0968ecu,0x0c0968eeu,0x0c0968f0u,0x0c0968f2u,0x0c0968f4u,0x0c0968f6u,0x0c096d5eu,0x0c096d60u,0x0c096d62u,0x0c096d64u,0x0c096d66u,0x0c096d68u,0x0c096d6au,
0x0c096d6cu,0x0c096d6eu,0x0c096d70u,0x0c096d72u,0x0c096d74u,0x0c096d76u,0x0c096d78u,0x0c096d7au,0x0c096d7cu,0x0c096d7eu,0x0c096d80u,0x0c096d82u,0x0c096d84u,0x0c096d86u,0x0c096d88u,0x0c096d8au,
0x0c096d8cu,0x0c096d8eu,0x0c096d90u,0x0c096d92u,0x0c096d94u,0x0c096d96u,0x0c096d98u,0x0c096d9au,0x0c096d9cu,0x0c096d9eu,0x0c096da0u,0x0c096da2u,0x0c096da4u,0x0c096da6u,0x0c096da8u,0x0c096daau,
0x0c096dacu,0x0c096daeu,0x0c096db0u,0x0c096db2u,0x0c096db4u,0x0c096db6u,0x0c096db8u,0x0c096dbau,0x0c096dbcu,0x0c096dbeu,0x0c097042u,0x0c097044u,0x0c097046u,0x0c097048u,0x0c09704au,0x0c09704cu,
0x0c09704eu,0x0c097050u,0x0c097052u,0x0c097054u,0x0c097056u,0x0c097058u,0x0c09705au,0x0c09705cu,0x0c0a7b36u,0x0c0a7b38u,0x0c0a7b3au,0x0c0a7b3cu,0x0c0a7b3eu,0x0c0a7b40u,0x0c0a7b42u,0x0c0a7b44u,
0x0c0a7b46u,0x0c0a7b48u,0x0c0a7b4au,0x0c0a7b4cu,0x0c0a7b4eu,0x0c0a7b50u,
};
int vf3_fifth_leaf_extra_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
