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
int vf3_away_batch249_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062bfau: goto P_0c062bfa;
case 0x0c062bfcu: goto P_0c062bfc;
case 0x0c062bfeu: goto P_0c062bfe;
case 0x0c062c00u: goto P_0c062c00;
case 0x0c062c02u: goto P_0c062c02;
case 0x0c062c04u: goto P_0c062c04;
case 0x0c062c06u: goto P_0c062c06;
case 0x0c062c08u: goto P_0c062c08;
case 0x0c062c0au: goto P_0c062c0a;
case 0x0c062c0cu: goto P_0c062c0c;
case 0x0c062c0eu: goto P_0c062c0e;
case 0x0c062c10u: goto P_0c062c10;
case 0x0c062c12u: goto P_0c062c12;
case 0x0c062c14u: goto P_0c062c14;
case 0x0c062c16u: goto P_0c062c16;
case 0x0c062c18u: goto P_0c062c18;
case 0x0c062c1au: goto P_0c062c1a;
case 0x0c062c1cu: goto P_0c062c1c;
case 0x0c062c1eu: goto P_0c062c1e;
case 0x0c062c20u: goto P_0c062c20;
case 0x0c062c22u: goto P_0c062c22;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062c4eu: goto P_0c062c4e;
case 0x0c062c50u: goto P_0c062c50;
case 0x0c062c52u: goto P_0c062c52;
case 0x0c062c54u: goto P_0c062c54;
case 0x0c062c56u: goto P_0c062c56;
case 0x0c062c58u: goto P_0c062c58;
case 0x0c062c5au: goto P_0c062c5a;
case 0x0c062c5cu: goto P_0c062c5c;
case 0x0c062c5eu: goto P_0c062c5e;
case 0x0c062c60u: goto P_0c062c60;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
case 0x0c0a2984u: goto P_0c0a2984;
case 0x0c0a2986u: goto P_0c0a2986;
case 0x0c0a2988u: goto P_0c0a2988;
case 0x0c0a298au: goto P_0c0a298a;
case 0x0c0a298cu: goto P_0c0a298c;
case 0x0c0a298eu: goto P_0c0a298e;
case 0x0c0a2990u: goto P_0c0a2990;
case 0x0c0a2992u: goto P_0c0a2992;
case 0x0c0a2994u: goto P_0c0a2994;
case 0x0c0a2996u: goto P_0c0a2996;
case 0x0c0a2998u: goto P_0c0a2998;
case 0x0c0a299au: goto P_0c0a299a;
case 0x0c0a299cu: goto P_0c0a299c;
case 0x0c0a299eu: goto P_0c0a299e;
case 0x0c0a29a0u: goto P_0c0a29a0;
case 0x0c0a29a2u: goto P_0c0a29a2;
case 0x0c0a29a4u: goto P_0c0a29a4;
case 0x0c0a29a6u: goto P_0c0a29a6;
case 0x0c0a29a8u: goto P_0c0a29a8;
case 0x0c0a29aau: goto P_0c0a29aa;
case 0x0c0a29acu: goto P_0c0a29ac;
case 0x0c0a29aeu: goto P_0c0a29ae;
case 0x0c0a29b0u: goto P_0c0a29b0;
case 0x0c0a29b2u: goto P_0c0a29b2;
case 0x0c0a29b4u: goto P_0c0a29b4;
case 0x0c0a29b6u: goto P_0c0a29b6;
case 0x0c0a29b8u: goto P_0c0a29b8;
case 0x0c0a29bau: goto P_0c0a29ba;
case 0x0c0a29bcu: goto P_0c0a29bc;
case 0x0c0a29beu: goto P_0c0a29be;
case 0x0c0a29c0u: goto P_0c0a29c0;
case 0x0c0a29c2u: goto P_0c0a29c2;
case 0x0c0a29c4u: goto P_0c0a29c4;
case 0x0c0a29c6u: goto P_0c0a29c6;
case 0x0c0a29c8u: goto P_0c0a29c8;
case 0x0c0a29cau: goto P_0c0a29ca;
case 0x0c0a29ccu: goto P_0c0a29cc;
case 0x0c0a29ceu: goto P_0c0a29ce;
case 0x0c0a29d0u: goto P_0c0a29d0;
case 0x0c0a29d2u: goto P_0c0a29d2;
case 0x0c0a29d4u: goto P_0c0a29d4;
case 0x0c0a29d6u: goto P_0c0a29d6;
case 0x0c0a29d8u: goto P_0c0a29d8;
case 0x0c0a29dau: goto P_0c0a29da;
case 0x0c0a29dcu: goto P_0c0a29dc;
case 0x0c0a29deu: goto P_0c0a29de;
case 0x0c0a29e0u: goto P_0c0a29e0;
case 0x0c0a29e2u: goto P_0c0a29e2;
case 0x0c0a29e4u: goto P_0c0a29e4;
case 0x0c0a29e6u: goto P_0c0a29e6;
case 0x0c0a29e8u: goto P_0c0a29e8;
case 0x0c0a29eau: goto P_0c0a29ea;
case 0x0c0a29ecu: goto P_0c0a29ec;
case 0x0c0a29eeu: goto P_0c0a29ee;
case 0x0c0a29f0u: goto P_0c0a29f0;
case 0x0c0a29f2u: goto P_0c0a29f2;
case 0x0c0a29f4u: goto P_0c0a29f4;
case 0x0c0a29f6u: goto P_0c0a29f6;
case 0x0c0a29f8u: goto P_0c0a29f8;
case 0x0c0a29fau: goto P_0c0a29fa;
case 0x0c0a29fcu: goto P_0c0a29fc;
case 0x0c0a29feu: goto P_0c0a29fe;
case 0x0c0a2a00u: goto P_0c0a2a00;
case 0x0c0a2a02u: goto P_0c0a2a02;
case 0x0c0a2a04u: goto P_0c0a2a04;
case 0x0c0a2a06u: goto P_0c0a2a06;
case 0x0c0a2a08u: goto P_0c0a2a08;
case 0x0c0a2a0au: goto P_0c0a2a0a;
case 0x0c0a2a0cu: goto P_0c0a2a0c;
case 0x0c0a2a0eu: goto P_0c0a2a0e;
case 0x0c0a2a10u: goto P_0c0a2a10;
case 0x0c0a2a12u: goto P_0c0a2a12;
case 0x0c0a2a14u: goto P_0c0a2a14;
case 0x0c0a2a16u: goto P_0c0a2a16;
case 0x0c0a2a18u: goto P_0c0a2a18;
case 0x0c0a2a1au: goto P_0c0a2a1a;
case 0x0c0a2a1cu: goto P_0c0a2a1c;
case 0x0c0a2a1eu: goto P_0c0a2a1e;
case 0x0c0a2a20u: goto P_0c0a2a20;
case 0x0c0a2a22u: goto P_0c0a2a22;
case 0x0c0a2a24u: goto P_0c0a2a24;
case 0x0c0a2a26u: goto P_0c0a2a26;
case 0x0c0a2a28u: goto P_0c0a2a28;
case 0x0c0a2a2au: goto P_0c0a2a2a;
case 0x0c0a2a2cu: goto P_0c0a2a2c;
case 0x0c0a2a2eu: goto P_0c0a2a2e;
case 0x0c0a2a30u: goto P_0c0a2a30;
case 0x0c0a2a32u: goto P_0c0a2a32;
case 0x0c0a2a34u: goto P_0c0a2a34;
case 0x0c0a2a36u: goto P_0c0a2a36;
case 0x0c0a2a38u: goto P_0c0a2a38;
case 0x0c0a2a3au: goto P_0c0a2a3a;
case 0x0c0a2a3cu: goto P_0c0a2a3c;
case 0x0c0a2a3eu: goto P_0c0a2a3e;
case 0x0c0a2a40u: goto P_0c0a2a40;
case 0x0c0a2a42u: goto P_0c0a2a42;
case 0x0c0a2a44u: goto P_0c0a2a44;
case 0x0c0a2a46u: goto P_0c0a2a46;
case 0x0c0a2a48u: goto P_0c0a2a48;
case 0x0c0a2a4au: goto P_0c0a2a4a;
case 0x0c0a2a4cu: goto P_0c0a2a4c;
case 0x0c0a2a4eu: goto P_0c0a2a4e;
case 0x0c0a2a50u: goto P_0c0a2a50;
case 0x0c0a2a52u: goto P_0c0a2a52;
case 0x0c0a2a54u: goto P_0c0a2a54;
case 0x0c0a2a56u: goto P_0c0a2a56;
case 0x0c0a2a58u: goto P_0c0a2a58;
case 0x0c0a2a5au: goto P_0c0a2a5a;
case 0x0c0a2a5cu: goto P_0c0a2a5c;
case 0x0c0a2a5eu: goto P_0c0a2a5e;
case 0x0c0a2a60u: goto P_0c0a2a60;
case 0x0c0a2a62u: goto P_0c0a2a62;
case 0x0c0a2a64u: goto P_0c0a2a64;
case 0x0c0a2a66u: goto P_0c0a2a66;
case 0x0c0a2a68u: goto P_0c0a2a68;
case 0x0c0a2a6au: goto P_0c0a2a6a;
case 0x0c0a2a6cu: goto P_0c0a2a6c;
case 0x0c0a2a6eu: goto P_0c0a2a6e;
case 0x0c0a2a70u: goto P_0c0a2a70;
case 0x0c0a2a72u: goto P_0c0a2a72;
case 0x0c0a2c36u: goto P_0c0a2c36;
case 0x0c0a2c38u: goto P_0c0a2c38;
case 0x0c0a2c3au: goto P_0c0a2c3a;
case 0x0c0a2c3cu: goto P_0c0a2c3c;
case 0x0c0a2c3eu: goto P_0c0a2c3e;
case 0x0c0a2c40u: goto P_0c0a2c40;
case 0x0c0a2c42u: goto P_0c0a2c42;
case 0x0c0a2c44u: goto P_0c0a2c44;
case 0x0c0a2c46u: goto P_0c0a2c46;
case 0x0c0a2c48u: goto P_0c0a2c48;
case 0x0c0a2c4au: goto P_0c0a2c4a;
case 0x0c0a2c4cu: goto P_0c0a2c4c;
case 0x0c0a2c4eu: goto P_0c0a2c4e;
case 0x0c0a2c50u: goto P_0c0a2c50;
case 0x0c0a2c52u: goto P_0c0a2c52;
case 0x0c0a2c54u: goto P_0c0a2c54;
case 0x0c0a2c56u: goto P_0c0a2c56;
case 0x0c0a2c58u: goto P_0c0a2c58;
case 0x0c0a2c5au: goto P_0c0a2c5a;
case 0x0c0a2c5cu: goto P_0c0a2c5c;
case 0x0c0a2c5eu: goto P_0c0a2c5e;
case 0x0c0a2c60u: goto P_0c0a2c60;
case 0x0c0a2c62u: goto P_0c0a2c62;
case 0x0c0a2c64u: goto P_0c0a2c64;
case 0x0c0a2c66u: goto P_0c0a2c66;
case 0x0c0a2c68u: goto P_0c0a2c68;
case 0x0c0a2c6au: goto P_0c0a2c6a;
case 0x0c0a2c6cu: goto P_0c0a2c6c;
case 0x0c0a2c6eu: goto P_0c0a2c6e;
case 0x0c0a2c70u: goto P_0c0a2c70;
case 0x0c0a2c72u: goto P_0c0a2c72;
case 0x0c0a2c74u: goto P_0c0a2c74;
case 0x0c0a2c76u: goto P_0c0a2c76;
case 0x0c0a2c78u: goto P_0c0a2c78;
case 0x0c0a2c7au: goto P_0c0a2c7a;
case 0x0c0a2c7cu: goto P_0c0a2c7c;
case 0x0c0a2c7eu: goto P_0c0a2c7e;
case 0x0c0a2c80u: goto P_0c0a2c80;
case 0x0c0a2c82u: goto P_0c0a2c82;
case 0x0c0a2c84u: goto P_0c0a2c84;
case 0x0c0a2c86u: goto P_0c0a2c86;
case 0x0c0a2c88u: goto P_0c0a2c88;
case 0x0c0a2c8au: goto P_0c0a2c8a;
case 0x0c0a2c8cu: goto P_0c0a2c8c;
case 0x0c0a2c8eu: goto P_0c0a2c8e;
case 0x0c0a2c90u: goto P_0c0a2c90;
case 0x0c0a2c92u: goto P_0c0a2c92;
case 0x0c0a2c94u: goto P_0c0a2c94;
case 0x0c0a2c96u: goto P_0c0a2c96;
case 0x0c0a2c98u: goto P_0c0a2c98;
case 0x0c0a2c9au: goto P_0c0a2c9a;
case 0x0c0a2c9cu: goto P_0c0a2c9c;
case 0x0c0a2cb8u: goto P_0c0a2cb8;
case 0x0c0a2cbau: goto P_0c0a2cba;
case 0x0c0a2cbcu: goto P_0c0a2cbc;
case 0x0c0a2cbeu: goto P_0c0a2cbe;
case 0x0c0a2cc0u: goto P_0c0a2cc0;
case 0x0c0a2cc2u: goto P_0c0a2cc2;
case 0x0c0a2cc4u: goto P_0c0a2cc4;
case 0x0c0a2cc6u: goto P_0c0a2cc6;
case 0x0c0a2cc8u: goto P_0c0a2cc8;
case 0x0c0a2ccau: goto P_0c0a2cca;
case 0x0c0a2cccu: goto P_0c0a2ccc;
case 0x0c0a2cceu: goto P_0c0a2cce;
case 0x0c0a2cd0u: goto P_0c0a2cd0;
case 0x0c0a2cd2u: goto P_0c0a2cd2;
case 0x0c0a2cd4u: goto P_0c0a2cd4;
case 0x0c0a2cd6u: goto P_0c0a2cd6;
case 0x0c0a2cd8u: goto P_0c0a2cd8;
case 0x0c0a2cdau: goto P_0c0a2cda;
case 0x0c0a2cdcu: goto P_0c0a2cdc;
case 0x0c0a2cdeu: goto P_0c0a2cde;
case 0x0c0a2ce0u: goto P_0c0a2ce0;
case 0x0c0a2ce2u: goto P_0c0a2ce2;
case 0x0c0a2ce4u: goto P_0c0a2ce4;
case 0x0c0a2ce6u: goto P_0c0a2ce6;
case 0x0c0a2ce8u: goto P_0c0a2ce8;
case 0x0c0a2ceau: goto P_0c0a2cea;
case 0x0c0a2cecu: goto P_0c0a2cec;
case 0x0c0a2ceeu: goto P_0c0a2cee;
case 0x0c0a2cf0u: goto P_0c0a2cf0;
case 0x0c0a2cf2u: goto P_0c0a2cf2;
case 0x0c0a2cf4u: goto P_0c0a2cf4;
case 0x0c0a2cf6u: goto P_0c0a2cf6;
case 0x0c0a2cf8u: goto P_0c0a2cf8;
case 0x0c0a2cfau: goto P_0c0a2cfa;
case 0x0c0a2cfcu: goto P_0c0a2cfc;
case 0x0c0a2cfeu: goto P_0c0a2cfe;
case 0x0c0a2d00u: goto P_0c0a2d00;
case 0x0c0a2d02u: goto P_0c0a2d02;
case 0x0c0a2d04u: goto P_0c0a2d04;
case 0x0c0a2d06u: goto P_0c0a2d06;
case 0x0c0a2d08u: goto P_0c0a2d08;
case 0x0c0a2d0au: goto P_0c0a2d0a;
case 0x0c0a2d0cu: goto P_0c0a2d0c;
case 0x0c0a2d0eu: goto P_0c0a2d0e;
case 0x0c0a2d10u: goto P_0c0a2d10;
case 0x0c0a2d12u: goto P_0c0a2d12;
case 0x0c0a2d14u: goto P_0c0a2d14;
case 0x0c0a2d16u: goto P_0c0a2d16;
case 0x0c0a2d18u: goto P_0c0a2d18;
case 0x0c0a2d1au: goto P_0c0a2d1a;
case 0x0c0a2d1cu: goto P_0c0a2d1c;
case 0x0c0a2d1eu: goto P_0c0a2d1e;
case 0x0c0a2d20u: goto P_0c0a2d20;
case 0x0c0a2d22u: goto P_0c0a2d22;
case 0x0c0a2d24u: goto P_0c0a2d24;
case 0x0c0a2d26u: goto P_0c0a2d26;
case 0x0c0a2d28u: goto P_0c0a2d28;
case 0x0c0a2d2au: goto P_0c0a2d2a;
case 0x0c0a2d2cu: goto P_0c0a2d2c;
case 0x0c0a2d2eu: goto P_0c0a2d2e;
case 0x0c0a2d30u: goto P_0c0a2d30;
case 0x0c0a2d32u: goto P_0c0a2d32;
case 0x0c0a2d34u: goto P_0c0a2d34;
case 0x0c0a2d36u: goto P_0c0a2d36;
case 0x0c0a2d38u: goto P_0c0a2d38;
case 0x0c0a2d3au: goto P_0c0a2d3a;
case 0x0c0a2d3cu: goto P_0c0a2d3c;
case 0x0c0a2d3eu: goto P_0c0a2d3e;
case 0x0c0a2d40u: goto P_0c0a2d40;
case 0x0c0a2d42u: goto P_0c0a2d42;
case 0x0c0a2d44u: goto P_0c0a2d44;
case 0x0c0a2d46u: goto P_0c0a2d46;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062bfa: /* original e700, guest PC 0x0c062bfa */
if(!s->budget--) { s->failed_pc=0x0c062bfau; return 0; }
r[7]=0x00000000u;
goto P_0c062bfc;
P_0c062bfc: /* original d526, guest PC 0x0c062bfc */
if(!s->budget--) { s->failed_pc=0x0c062bfcu; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062bfe;
P_0c062bfe: /* original 6453, guest PC 0x0c062bfe */
if(!s->budget--) { s->failed_pc=0x0c062bfeu; return 0; }
r[4]=r[5];
goto P_0c062c00;
P_0c062c00: /* original 9047, guest PC 0x0c062c00 */
if(!s->budget--) { s->failed_pc=0x0c062c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c02;
P_0c062c02: /* original 6653, guest PC 0x0c062c02 */
if(!s->budget--) { s->failed_pc=0x0c062c02u; return 0; }
r[6]=r[5];
goto P_0c062c04;
P_0c062c04: /* original e501, guest PC 0x0c062c04 */
if(!s->budget--) { s->failed_pc=0x0c062c04u; return 0; }
r[5]=0x00000001u;
goto P_0c062c06;
P_0c062c06: /* original 6361, guest PC 0x0c062c06 */
if(!s->budget--) { s->failed_pc=0x0c062c06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c062c08;
P_0c062c08: /* original 633d, guest PC 0x0c062c08 */
if(!s->budget--) { s->failed_pc=0x0c062c08u; return 0; }
r[3]=r[3]&65535u;
goto P_0c062c0a;
P_0c062c0a: /* original 2358, guest PC 0x0c062c0a */
if(!s->budget--) { s->failed_pc=0x0c062c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c062c0c;
P_0c062c0c: /* original 8b02, guest PC 0x0c062c0c */
if(!s->budget--) { s->failed_pc=0x0c062c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c14; }
goto P_0c062c0e;
P_0c062c0e: /* original 2451, guest PC 0x0c062c0e */
if(!s->budget--) { s->failed_pc=0x0c062c0eu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c062c10;
P_0c062c10: /* original 000b, guest PC 0x0c062c10 */
if(!s->budget--) { s->failed_pc=0x0c062c10u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c062c12: /* original 6043, guest PC 0x0c062c12 */
if(!s->budget--) { s->failed_pc=0x0c062c12u; return 0; }
r[0]=r[4];
goto P_0c062c14;
P_0c062c14: /* original 7701, guest PC 0x0c062c14 */
if(!s->budget--) { s->failed_pc=0x0c062c14u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c16;
P_0c062c16: /* original 744c, guest PC 0x0c062c16 */
if(!s->budget--) { s->failed_pc=0x0c062c16u; return 0; }
r[4]+=0x0000004cu;
goto P_0c062c18;
P_0c062c18: /* original 3703, guest PC 0x0c062c18 */
if(!s->budget--) { s->failed_pc=0x0c062c18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c062c1a;
P_0c062c1a: /* original 8ff4, guest PC 0x0c062c1a */
if(!s->budget--) { s->failed_pc=0x0c062c1au; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c06; }
goto P_0c062c1e;
P_0c062c1c: /* original 764c, guest PC 0x0c062c1c */
if(!s->budget--) { s->failed_pc=0x0c062c1cu; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c1e;
P_0c062c1e: /* original e000, guest PC 0x0c062c1e */
if(!s->budget--) { s->failed_pc=0x0c062c1eu; return 0; }
r[0]=0x00000000u;
goto P_0c062c20;
P_0c062c20: /* original 000b, guest PC 0x0c062c20 */
if(!s->budget--) { s->failed_pc=0x0c062c20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062c22: /* original 0009, guest PC 0x0c062c22 */
if(!s->budget--) { s->failed_pc=0x0c062c22u; return 0; }
goto P_0c062c24;
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062c4e;
P_0c062c4e: /* original 6342, guest PC 0x0c062c4e */
if(!s->budget--) { s->failed_pc=0x0c062c4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c062c50;
P_0c062c50: /* original 2338, guest PC 0x0c062c50 */
if(!s->budget--) { s->failed_pc=0x0c062c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062c52;
P_0c062c52: /* original 8b02, guest PC 0x0c062c52 */
if(!s->budget--) { s->failed_pc=0x0c062c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c5a; }
goto P_0c062c54;
P_0c062c54: /* original e300, guest PC 0x0c062c54 */
if(!s->budget--) { s->failed_pc=0x0c062c54u; return 0; }
r[3]=0x00000000u;
goto P_0c062c56;
P_0c062c56: /* original a002, guest PC 0x0c062c56 */
if(!s->budget--) { s->failed_pc=0x0c062c56u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5e;
P_0c062c58: /* original 1531, guest PC 0x0c062c58 */
if(!s->budget--) { s->failed_pc=0x0c062c58u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5a;
P_0c062c5a: /* original 6242, guest PC 0x0c062c5a */
if(!s->budget--) { s->failed_pc=0x0c062c5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c062c5c;
P_0c062c5c: /* original 1521, guest PC 0x0c062c5c */
if(!s->budget--) { s->failed_pc=0x0c062c5cu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c062c5e;
P_0c062c5e: /* original 000b, guest PC 0x0c062c5e */
if(!s->budget--) { s->failed_pc=0x0c062c5eu; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c062c60: /* original 2452, guest PC 0x0c062c60 */
if(!s->budget--) { s->failed_pc=0x0c062c60u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c062c62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c62u; return 0; } return 1;
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0644d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644d6u; return 0; } return 1;
P_0c0a2984: /* original 2fe6, guest PC 0x0c0a2984 */
if(!s->budget--) { s->failed_pc=0x0c0a2984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2986;
P_0c0a2986: /* original 6e43, guest PC 0x0c0a2986 */
if(!s->budget--) { s->failed_pc=0x0c0a2986u; return 0; }
r[14]=r[4];
goto P_0c0a2988;
P_0c0a2988: /* original 2fd6, guest PC 0x0c0a2988 */
if(!s->budget--) { s->failed_pc=0x0c0a2988u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298a;
P_0c0a298a: /* original 2fc6, guest PC 0x0c0a298a */
if(!s->budget--) { s->failed_pc=0x0c0a298au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298c;
P_0c0a298c: /* original 2fb6, guest PC 0x0c0a298c */
if(!s->budget--) { s->failed_pc=0x0c0a298cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298e;
P_0c0a298e: /* original 2fa6, guest PC 0x0c0a298e */
if(!s->budget--) { s->failed_pc=0x0c0a298eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2990;
P_0c0a2990: /* original 2f96, guest PC 0x0c0a2990 */
if(!s->budget--) { s->failed_pc=0x0c0a2990u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2992;
P_0c0a2992: /* original 2f86, guest PC 0x0c0a2992 */
if(!s->budget--) { s->failed_pc=0x0c0a2992u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2994;
P_0c0a2994: /* original 4f22, guest PC 0x0c0a2994 */
if(!s->budget--) { s->failed_pc=0x0c0a2994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2996;
P_0c0a2996: /* original 7ff8, guest PC 0x0c0a2996 */
if(!s->budget--) { s->failed_pc=0x0c0a2996u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2998;
P_0c0a2998: /* original 2f61, guest PC 0x0c0a2998 */
if(!s->budget--) { s->failed_pc=0x0c0a2998u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a299a;
P_0c0a299a: /* original b14c, guest PC 0x0c0a299a */
if(!s->budget--) { s->failed_pc=0x0c0a299au; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a299eu;
r[10]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a299eu) { target=s->pc; goto dispatch; }
goto P_0c0a299e;
P_0c0a299c: /* original 6a53, guest PC 0x0c0a299c */
if(!s->budget--) { s->failed_pc=0x0c0a299cu; return 0; }
r[10]=r[5];
goto P_0c0a299e;
P_0c0a299e: /* original 6403, guest PC 0x0c0a299e */
if(!s->budget--) { s->failed_pc=0x0c0a299eu; return 0; }
r[4]=r[0];
goto P_0c0a29a0;
P_0c0a29a0: /* original 2448, guest PC 0x0c0a29a0 */
if(!s->budget--) { s->failed_pc=0x0c0a29a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a29a2;
P_0c0a29a2: /* original 8902, guest PC 0x0c0a29a2 */
if(!s->budget--) { s->failed_pc=0x0c0a29a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a29aa; }
goto P_0c0a29a4;
P_0c0a29a4: /* original d375, guest PC 0x0c0a29a4 */
if(!s->budget--) { s->failed_pc=0x0c0a29a4u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a29a6;
P_0c0a29a6: /* original 3430, guest PC 0x0c0a29a6 */
if(!s->budget--) { s->failed_pc=0x0c0a29a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a29a8;
P_0c0a29a8: /* original 8b59, guest PC 0x0c0a29a8 */
if(!s->budget--) { s->failed_pc=0x0c0a29a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29aa;
P_0c0a29aa: /* original e020, guest PC 0x0c0a29aa */
if(!s->budget--) { s->failed_pc=0x0c0a29aau; return 0; }
r[0]=0x00000020u;
goto P_0c0a29ac;
P_0c0a29ac: /* original 01ed, guest PC 0x0c0a29ac */
if(!s->budget--) { s->failed_pc=0x0c0a29acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ae;
P_0c0a29ae: /* original e022, guest PC 0x0c0a29ae */
if(!s->budget--) { s->failed_pc=0x0c0a29aeu; return 0; }
r[0]=0x00000022u;
goto P_0c0a29b0;
P_0c0a29b0: /* original 03ed, guest PC 0x0c0a29b0 */
if(!s->budget--) { s->failed_pc=0x0c0a29b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29b2;
P_0c0a29b2: /* original 611d, guest PC 0x0c0a29b2 */
if(!s->budget--) { s->failed_pc=0x0c0a29b2u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a29b4;
P_0c0a29b4: /* original 633d, guest PC 0x0c0a29b4 */
if(!s->budget--) { s->failed_pc=0x0c0a29b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a29b6;
P_0c0a29b6: /* original 213b, guest PC 0x0c0a29b6 */
if(!s->budget--) { s->failed_pc=0x0c0a29b6u; return 0; }
r[1]|=r[3];
goto P_0c0a29b8;
P_0c0a29b8: /* original 2118, guest PC 0x0c0a29b8 */
if(!s->budget--) { s->failed_pc=0x0c0a29b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a29ba;
P_0c0a29ba: /* original 8b50, guest PC 0x0c0a29ba */
if(!s->budget--) { s->failed_pc=0x0c0a29bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29bc;
P_0c0a29bc: /* original e020, guest PC 0x0c0a29bc */
if(!s->budget--) { s->failed_pc=0x0c0a29bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0a29be;
P_0c0a29be: /* original 52e4, guest PC 0x0c0a29be */
if(!s->budget--) { s->failed_pc=0x0c0a29beu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a29c0;
P_0c0a29c0: /* original 1f21, guest PC 0x0c0a29c0 */
if(!s->budget--) { s->failed_pc=0x0c0a29c0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a29c2;
P_0c0a29c2: /* original 63f1, guest PC 0x0c0a29c2 */
if(!s->budget--) { s->failed_pc=0x0c0a29c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a29c4;
P_0c0a29c4: /* original 5ce5, guest PC 0x0c0a29c4 */
if(!s->budget--) { s->failed_pc=0x0c0a29c4u; return 0; }
r[12]=read(ram,r[14]+20,4);
goto P_0c0a29c6;
P_0c0a29c6: /* original 0e35, guest PC 0x0c0a29c6 */
if(!s->budget--) { s->failed_pc=0x0c0a29c6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a29c8;
P_0c0a29c8: /* original 04ed, guest PC 0x0c0a29c8 */
if(!s->budget--) { s->failed_pc=0x0c0a29c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ca;
P_0c0a29ca: /* original d36d, guest PC 0x0c0a29ca */
if(!s->budget--) { s->failed_pc=0x0c0a29cau; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a29cc;
P_0c0a29cc: /* original 430b, guest PC 0x0c0a29cc */
if(!s->budget--) { s->failed_pc=0x0c0a29ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a29d0u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a29d0u) { target=s->pc; goto dispatch; }
goto P_0c0a29d0;
P_0c0a29ce: /* original 644d, guest PC 0x0c0a29ce */
if(!s->budget--) { s->failed_pc=0x0c0a29ceu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a29d0;
P_0c0a29d0: /* original eb00, guest PC 0x0c0a29d0 */
if(!s->budget--) { s->failed_pc=0x0c0a29d0u; return 0; }
r[11]=0x00000000u;
goto P_0c0a29d2;
P_0c0a29d2: /* original a039, guest PC 0x0c0a29d2 */
if(!s->budget--) { s->failed_pc=0x0c0a29d2u; return 0; }
r[8]=r[11];
goto P_0c0a2a48;
P_0c0a29d4: /* original 68b3, guest PC 0x0c0a29d4 */
if(!s->budget--) { s->failed_pc=0x0c0a29d4u; return 0; }
r[8]=r[11];
goto P_0c0a29d6;
P_0c0a29d6: /* original 53f1, guest PC 0x0c0a29d6 */
if(!s->budget--) { s->failed_pc=0x0c0a29d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a29d8;
P_0c0a29d8: /* original 6d83, guest PC 0x0c0a29d8 */
if(!s->budget--) { s->failed_pc=0x0c0a29d8u; return 0; }
r[13]=r[8];
goto P_0c0a29da;
P_0c0a29da: /* original 4d08, guest PC 0x0c0a29da */
if(!s->budget--) { s->failed_pc=0x0c0a29dau; return 0; }
r[13]<<=2;
goto P_0c0a29dc;
P_0c0a29dc: /* original 3d3c, guest PC 0x0c0a29dc */
if(!s->budget--) { s->failed_pc=0x0c0a29dcu; return 0; }
r[13]+=r[3];
goto P_0c0a29de;
P_0c0a29de: /* original 60d2, guest PC 0x0c0a29de */
if(!s->budget--) { s->failed_pc=0x0c0a29deu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a29e0;
P_0c0a29e0: /* original 5001, guest PC 0x0c0a29e0 */
if(!s->budget--) { s->failed_pc=0x0c0a29e0u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a29e2;
P_0c0a29e2: /* original c801, guest PC 0x0c0a29e2 */
if(!s->budget--) { s->failed_pc=0x0c0a29e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a29e4;
P_0c0a29e4: /* original 8922, guest PC 0x0c0a29e4 */
if(!s->budget--) { s->failed_pc=0x0c0a29e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a2c; }
goto P_0c0a29e6;
P_0c0a29e6: /* original a008, guest PC 0x0c0a29e6 */
if(!s->budget--) { s->failed_pc=0x0c0a29e6u; return 0; }
r[4]=r[11];
goto P_0c0a29fa;
P_0c0a29e8: /* original 64b3, guest PC 0x0c0a29e8 */
if(!s->budget--) { s->failed_pc=0x0c0a29e8u; return 0; }
r[4]=r[11];
goto P_0c0a29ea;
P_0c0a29ea: /* original 6343, guest PC 0x0c0a29ea */
if(!s->budget--) { s->failed_pc=0x0c0a29eau; return 0; }
r[3]=r[4];
goto P_0c0a29ec;
P_0c0a29ec: /* original 4308, guest PC 0x0c0a29ec */
if(!s->budget--) { s->failed_pc=0x0c0a29ecu; return 0; }
r[3]<<=2;
goto P_0c0a29ee;
P_0c0a29ee: /* original 4308, guest PC 0x0c0a29ee */
if(!s->budget--) { s->failed_pc=0x0c0a29eeu; return 0; }
r[3]<<=2;
goto P_0c0a29f0;
P_0c0a29f0: /* original 33cc, guest PC 0x0c0a29f0 */
if(!s->budget--) { s->failed_pc=0x0c0a29f0u; return 0; }
r[3]+=r[12];
goto P_0c0a29f2;
P_0c0a29f2: /* original 5232, guest PC 0x0c0a29f2 */
if(!s->budget--) { s->failed_pc=0x0c0a29f2u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a29f4;
P_0c0a29f4: /* original 7401, guest PC 0x0c0a29f4 */
if(!s->budget--) { s->failed_pc=0x0c0a29f4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a29f6;
P_0c0a29f6: /* original 32ac, guest PC 0x0c0a29f6 */
if(!s->budget--) { s->failed_pc=0x0c0a29f6u; return 0; }
r[2]+=r[10];
goto P_0c0a29f8;
P_0c0a29f8: /* original 1322, guest PC 0x0c0a29f8 */
if(!s->budget--) { s->failed_pc=0x0c0a29f8u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a29fa;
P_0c0a29fa: /* original 85e7, guest PC 0x0c0a29fa */
if(!s->budget--) { s->failed_pc=0x0c0a29fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a29fc;
P_0c0a29fc: /* original 600d, guest PC 0x0c0a29fc */
if(!s->budget--) { s->failed_pc=0x0c0a29fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a29fe;
P_0c0a29fe: /* original 3403, guest PC 0x0c0a29fe */
if(!s->budget--) { s->failed_pc=0x0c0a29feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a00;
P_0c0a2a00: /* original 8bf3, guest PC 0x0c0a2a00 */
if(!s->budget--) { s->failed_pc=0x0c0a2a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29ea; }
goto P_0c0a2a02;
P_0c0a2a02: /* original d260, guest PC 0x0c0a2a02 */
if(!s->budget--) { s->failed_pc=0x0c0a2a02u; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2a04;
P_0c0a2a04: /* original 65c3, guest PC 0x0c0a2a04 */
if(!s->budget--) { s->failed_pc=0x0c0a2a04u; return 0; }
r[5]=r[12];
goto P_0c0a2a06;
P_0c0a2a06: /* original 420b, guest PC 0x0c0a2a06 */
if(!s->budget--) { s->failed_pc=0x0c0a2a06u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2a0au;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a0au) { target=s->pc; goto dispatch; }
goto P_0c0a2a0a;
P_0c0a2a08: /* original 64d2, guest PC 0x0c0a2a08 */
if(!s->budget--) { s->failed_pc=0x0c0a2a08u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a0a;
P_0c0a2a0a: /* original 2008, guest PC 0x0c0a2a0a */
if(!s->budget--) { s->failed_pc=0x0c0a2a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a0c;
P_0c0a2a0c: /* original a008, guest PC 0x0c0a2a0c */
if(!s->budget--) { s->failed_pc=0x0c0a2a0cu; return 0; }
r[4]=r[11];
goto P_0c0a2a20;
P_0c0a2a0e: /* original 64b3, guest PC 0x0c0a2a0e */
if(!s->budget--) { s->failed_pc=0x0c0a2a0eu; return 0; }
r[4]=r[11];
goto P_0c0a2a10;
P_0c0a2a10: /* original 6343, guest PC 0x0c0a2a10 */
if(!s->budget--) { s->failed_pc=0x0c0a2a10u; return 0; }
r[3]=r[4];
goto P_0c0a2a12;
P_0c0a2a12: /* original 4308, guest PC 0x0c0a2a12 */
if(!s->budget--) { s->failed_pc=0x0c0a2a12u; return 0; }
r[3]<<=2;
goto P_0c0a2a14;
P_0c0a2a14: /* original 4308, guest PC 0x0c0a2a14 */
if(!s->budget--) { s->failed_pc=0x0c0a2a14u; return 0; }
r[3]<<=2;
goto P_0c0a2a16;
P_0c0a2a16: /* original 33cc, guest PC 0x0c0a2a16 */
if(!s->budget--) { s->failed_pc=0x0c0a2a16u; return 0; }
r[3]+=r[12];
goto P_0c0a2a18;
P_0c0a2a18: /* original 5232, guest PC 0x0c0a2a18 */
if(!s->budget--) { s->failed_pc=0x0c0a2a18u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2a1a;
P_0c0a2a1a: /* original 7401, guest PC 0x0c0a2a1a */
if(!s->budget--) { s->failed_pc=0x0c0a2a1au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2a1c;
P_0c0a2a1c: /* original 32a8, guest PC 0x0c0a2a1c */
if(!s->budget--) { s->failed_pc=0x0c0a2a1cu; return 0; }
r[2]-=r[10];
goto P_0c0a2a1e;
P_0c0a2a1e: /* original 1322, guest PC 0x0c0a2a1e */
if(!s->budget--) { s->failed_pc=0x0c0a2a1eu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2a20;
P_0c0a2a20: /* original 85e7, guest PC 0x0c0a2a20 */
if(!s->budget--) { s->failed_pc=0x0c0a2a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a22;
P_0c0a2a22: /* original 600d, guest PC 0x0c0a2a22 */
if(!s->budget--) { s->failed_pc=0x0c0a2a22u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a24;
P_0c0a2a24: /* original 3403, guest PC 0x0c0a2a24 */
if(!s->budget--) { s->failed_pc=0x0c0a2a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a26;
P_0c0a2a26: /* original 8bf3, guest PC 0x0c0a2a26 */
if(!s->budget--) { s->failed_pc=0x0c0a2a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a10; }
goto P_0c0a2a28;
P_0c0a2a28: /* original a00d, guest PC 0x0c0a2a28 */
if(!s->budget--) { s->failed_pc=0x0c0a2a28u; return 0; }
goto P_0c0a2a46;
P_0c0a2a2a: /* original 0009, guest PC 0x0c0a2a2a */
if(!s->budget--) { s->failed_pc=0x0c0a2a2au; return 0; }
goto P_0c0a2a2c;
P_0c0a2a2c: /* original 64d2, guest PC 0x0c0a2a2c */
if(!s->budget--) { s->failed_pc=0x0c0a2a2cu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a2e;
P_0c0a2a2e: /* original 66a3, guest PC 0x0c0a2a2e */
if(!s->budget--) { s->failed_pc=0x0c0a2a2eu; return 0; }
r[6]=r[10];
goto P_0c0a2a30;
P_0c0a2a30: /* original d355, guest PC 0x0c0a2a30 */
if(!s->budget--) { s->failed_pc=0x0c0a2a30u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2a32;
P_0c0a2a32: /* original 65c3, guest PC 0x0c0a2a32 */
if(!s->budget--) { s->failed_pc=0x0c0a2a32u; return 0; }
r[5]=r[12];
goto P_0c0a2a34;
P_0c0a2a34: /* original 430b, guest PC 0x0c0a2a34 */
if(!s->budget--) { s->failed_pc=0x0c0a2a34u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a38u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a38u) { target=s->pc; goto dispatch; }
goto P_0c0a2a38;
P_0c0a2a36: /* original 5441, guest PC 0x0c0a2a36 */
if(!s->budget--) { s->failed_pc=0x0c0a2a36u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2a38;
P_0c0a2a38: /* original 69d2, guest PC 0x0c0a2a38 */
if(!s->budget--) { s->failed_pc=0x0c0a2a38u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c0a2a3a;
P_0c0a2a3a: /* original 2008, guest PC 0x0c0a2a3a */
if(!s->budget--) { s->failed_pc=0x0c0a2a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a3c;
P_0c0a2a3c: /* original d353, guest PC 0x0c0a2a3c */
if(!s->budget--) { s->failed_pc=0x0c0a2a3cu; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2a3e;
P_0c0a2a3e: /* original 5591, guest PC 0x0c0a2a3e */
if(!s->budget--) { s->failed_pc=0x0c0a2a3eu; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2a40;
P_0c0a2a40: /* original 5692, guest PC 0x0c0a2a40 */
if(!s->budget--) { s->failed_pc=0x0c0a2a40u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2a42;
P_0c0a2a42: /* original 430b, guest PC 0x0c0a2a42 */
if(!s->budget--) { s->failed_pc=0x0c0a2a42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a46u;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a46u) { target=s->pc; goto dispatch; }
goto P_0c0a2a46;
P_0c0a2a44: /* original 6492, guest PC 0x0c0a2a44 */
if(!s->budget--) { s->failed_pc=0x0c0a2a44u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2a46;
P_0c0a2a46: /* original 7801, guest PC 0x0c0a2a46 */
if(!s->budget--) { s->failed_pc=0x0c0a2a46u; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2a48;
P_0c0a2a48: /* original 85e6, guest PC 0x0c0a2a48 */
if(!s->budget--) { s->failed_pc=0x0c0a2a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2a4a;
P_0c0a2a4a: /* original 600d, guest PC 0x0c0a2a4a */
if(!s->budget--) { s->failed_pc=0x0c0a2a4au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a4c;
P_0c0a2a4c: /* original 3803, guest PC 0x0c0a2a4c */
if(!s->budget--) { s->failed_pc=0x0c0a2a4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2a4e;
P_0c0a2a4e: /* original 8bc2, guest PC 0x0c0a2a4e */
if(!s->budget--) { s->failed_pc=0x0c0a2a4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29d6; }
goto P_0c0a2a50;
P_0c0a2a50: /* original 63f1, guest PC 0x0c0a2a50 */
if(!s->budget--) { s->failed_pc=0x0c0a2a50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2a52;
P_0c0a2a52: /* original e222, guest PC 0x0c0a2a52 */
if(!s->budget--) { s->failed_pc=0x0c0a2a52u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2a54;
P_0c0a2a54: /* original 85e7, guest PC 0x0c0a2a54 */
if(!s->budget--) { s->failed_pc=0x0c0a2a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a56;
P_0c0a2a56: /* original 32ec, guest PC 0x0c0a2a56 */
if(!s->budget--) { s->failed_pc=0x0c0a2a56u; return 0; }
r[2]+=r[14];
goto P_0c0a2a58;
P_0c0a2a58: /* original 64b3, guest PC 0x0c0a2a58 */
if(!s->budget--) { s->failed_pc=0x0c0a2a58u; return 0; }
r[4]=r[11];
goto P_0c0a2a5a;
P_0c0a2a5a: /* original 303c, guest PC 0x0c0a2a5a */
if(!s->budget--) { s->failed_pc=0x0c0a2a5au; return 0; }
r[0]+=r[3];
goto P_0c0a2a5c;
P_0c0a2a5c: /* original 2201, guest PC 0x0c0a2a5c */
if(!s->budget--) { s->failed_pc=0x0c0a2a5cu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2a5e;
P_0c0a2a5e: /* original 7f08, guest PC 0x0c0a2a5e */
if(!s->budget--) { s->failed_pc=0x0c0a2a5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2a60;
P_0c0a2a60: /* original 6043, guest PC 0x0c0a2a60 */
if(!s->budget--) { s->failed_pc=0x0c0a2a60u; return 0; }
r[0]=r[4];
goto P_0c0a2a62;
P_0c0a2a62: /* original 4f26, guest PC 0x0c0a2a62 */
if(!s->budget--) { s->failed_pc=0x0c0a2a62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2a64;
P_0c0a2a64: /* original 68f6, guest PC 0x0c0a2a64 */
if(!s->budget--) { s->failed_pc=0x0c0a2a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2a66;
P_0c0a2a66: /* original 69f6, guest PC 0x0c0a2a66 */
if(!s->budget--) { s->failed_pc=0x0c0a2a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2a68;
P_0c0a2a68: /* original 6af6, guest PC 0x0c0a2a68 */
if(!s->budget--) { s->failed_pc=0x0c0a2a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2a6a;
P_0c0a2a6a: /* original 6bf6, guest PC 0x0c0a2a6a */
if(!s->budget--) { s->failed_pc=0x0c0a2a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2a6c;
P_0c0a2a6c: /* original 6cf6, guest PC 0x0c0a2a6c */
if(!s->budget--) { s->failed_pc=0x0c0a2a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2a6e;
P_0c0a2a6e: /* original 6df6, guest PC 0x0c0a2a6e */
if(!s->budget--) { s->failed_pc=0x0c0a2a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2a70;
P_0c0a2a70: /* original 000b, guest PC 0x0c0a2a70 */
if(!s->budget--) { s->failed_pc=0x0c0a2a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2a72: /* original 6ef6, guest PC 0x0c0a2a72 */
if(!s->budget--) { s->failed_pc=0x0c0a2a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2a74u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2a74u; return 0; } return 1;
P_0c0a2c36: /* original 2fe6, guest PC 0x0c0a2c36 */
if(!s->budget--) { s->failed_pc=0x0c0a2c36u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c38;
P_0c0a2c38: /* original 2fd6, guest PC 0x0c0a2c38 */
if(!s->budget--) { s->failed_pc=0x0c0a2c38u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c3a;
P_0c0a2c3a: /* original 2fc6, guest PC 0x0c0a2c3a */
if(!s->budget--) { s->failed_pc=0x0c0a2c3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c3c;
P_0c0a2c3c: /* original 2fb6, guest PC 0x0c0a2c3c */
if(!s->budget--) { s->failed_pc=0x0c0a2c3cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c3e;
P_0c0a2c3e: /* original 6b43, guest PC 0x0c0a2c3e */
if(!s->budget--) { s->failed_pc=0x0c0a2c3eu; return 0; }
r[11]=r[4];
goto P_0c0a2c40;
P_0c0a2c40: /* original 2fa6, guest PC 0x0c0a2c40 */
if(!s->budget--) { s->failed_pc=0x0c0a2c40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c42;
P_0c0a2c42: /* original e400, guest PC 0x0c0a2c42 */
if(!s->budget--) { s->failed_pc=0x0c0a2c42u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2c44;
P_0c0a2c44: /* original 2f96, guest PC 0x0c0a2c44 */
if(!s->budget--) { s->failed_pc=0x0c0a2c44u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c46;
P_0c0a2c46: /* original 2f86, guest PC 0x0c0a2c46 */
if(!s->budget--) { s->failed_pc=0x0c0a2c46u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c48;
P_0c0a2c48: /* original 4f22, guest PC 0x0c0a2c48 */
if(!s->budget--) { s->failed_pc=0x0c0a2c48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2c4a;
P_0c0a2c4a: /* original 7ff8, guest PC 0x0c0a2c4a */
if(!s->budget--) { s->failed_pc=0x0c0a2c4au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2c4c;
P_0c0a2c4c: /* original 1f41, guest PC 0x0c0a2c4c */
if(!s->budget--) { s->failed_pc=0x0c0a2c4cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a2c4e;
P_0c0a2c4e: /* original 60b2, guest PC 0x0c0a2c4e */
if(!s->budget--) { s->failed_pc=0x0c0a2c4eu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0a2c50;
P_0c0a2c50: /* original c880, guest PC 0x0c0a2c50 */
if(!s->budget--) { s->failed_pc=0x0c0a2c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2c52;
P_0c0a2c52: /* original 8d03, guest PC 0x0c0a2c52 */
if(!s->budget--) { s->failed_pc=0x0c0a2c52u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c0a2c5c; }
goto P_0c0a2c56;
P_0c0a2c54: /* original 6db3, guest PC 0x0c0a2c54 */
if(!s->budget--) { s->failed_pc=0x0c0a2c54u; return 0; }
r[13]=r[11];
goto P_0c0a2c56;
P_0c0a2c56: /* original d217, guest PC 0x0c0a2c56 */
if(!s->budget--) { s->failed_pc=0x0c0a2c56u; return 0; }
r[2]=read(ram,0x0c0a2cb4u,4);
goto P_0c0a2c58;
P_0c0a2c58: /* original a06b, guest PC 0x0c0a2c58 */
if(!s->budget--) { s->failed_pc=0x0c0a2c58u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2d32;
P_0c0a2c5a: /* original 1f21, guest PC 0x0c0a2c5a */
if(!s->budget--) { s->failed_pc=0x0c0a2c5au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2c5c;
P_0c0a2c5c: /* original 51b4, guest PC 0x0c0a2c5c */
if(!s->budget--) { s->failed_pc=0x0c0a2c5cu; return 0; }
r[1]=read(ram,r[11]+16,4);
goto P_0c0a2c5e;
P_0c0a2c5e: /* original e8fe, guest PC 0x0c0a2c5e */
if(!s->budget--) { s->failed_pc=0x0c0a2c5eu; return 0; }
r[8]=0xfffffffeu;
goto P_0c0a2c60;
P_0c0a2c60: /* original ea01, guest PC 0x0c0a2c60 */
if(!s->budget--) { s->failed_pc=0x0c0a2c60u; return 0; }
r[10]=0x00000001u;
goto P_0c0a2c62;
P_0c0a2c62: /* original 31bc, guest PC 0x0c0a2c62 */
if(!s->budget--) { s->failed_pc=0x0c0a2c62u; return 0; }
r[1]+=r[11];
goto P_0c0a2c64;
P_0c0a2c64: /* original 1b14, guest PC 0x0c0a2c64 */
if(!s->budget--) { s->failed_pc=0x0c0a2c64u; return 0; }
write(ram,r[11]+16,r[1],4);
goto P_0c0a2c66;
P_0c0a2c66: /* original 53b5, guest PC 0x0c0a2c66 */
if(!s->budget--) { s->failed_pc=0x0c0a2c66u; return 0; }
r[3]=read(ram,r[11]+20,4);
goto P_0c0a2c68;
P_0c0a2c68: /* original 33bc, guest PC 0x0c0a2c68 */
if(!s->budget--) { s->failed_pc=0x0c0a2c68u; return 0; }
r[3]+=r[11];
goto P_0c0a2c6a;
P_0c0a2c6a: /* original 1b35, guest PC 0x0c0a2c6a */
if(!s->budget--) { s->failed_pc=0x0c0a2c6au; return 0; }
write(ram,r[11]+20,r[3],4);
goto P_0c0a2c6c;
P_0c0a2c6c: /* original 52b4, guest PC 0x0c0a2c6c */
if(!s->budget--) { s->failed_pc=0x0c0a2c6cu; return 0; }
r[2]=read(ram,r[11]+16,4);
goto P_0c0a2c6e;
P_0c0a2c6e: /* original 2f22, guest PC 0x0c0a2c6e */
if(!s->budget--) { s->failed_pc=0x0c0a2c6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a2c70;
P_0c0a2c70: /* original a058, guest PC 0x0c0a2c70 */
if(!s->budget--) { s->failed_pc=0x0c0a2c70u; return 0; }
r[9]=r[4];
goto P_0c0a2d24;
P_0c0a2c72: /* original 6943, guest PC 0x0c0a2c72 */
if(!s->budget--) { s->failed_pc=0x0c0a2c72u; return 0; }
r[9]=r[4];
goto P_0c0a2c74;
P_0c0a2c74: /* original 63f2, guest PC 0x0c0a2c74 */
if(!s->budget--) { s->failed_pc=0x0c0a2c74u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a2c76;
P_0c0a2c76: /* original 6c93, guest PC 0x0c0a2c76 */
if(!s->budget--) { s->failed_pc=0x0c0a2c76u; return 0; }
r[12]=r[9];
goto P_0c0a2c78;
P_0c0a2c78: /* original 4c08, guest PC 0x0c0a2c78 */
if(!s->budget--) { s->failed_pc=0x0c0a2c78u; return 0; }
r[12]<<=2;
goto P_0c0a2c7a;
P_0c0a2c7a: /* original 3c3c, guest PC 0x0c0a2c7a */
if(!s->budget--) { s->failed_pc=0x0c0a2c7au; return 0; }
r[12]+=r[3];
goto P_0c0a2c7c;
P_0c0a2c7c: /* original 62c2, guest PC 0x0c0a2c7c */
if(!s->budget--) { s->failed_pc=0x0c0a2c7cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a2c7e;
P_0c0a2c7e: /* original 2228, guest PC 0x0c0a2c7e */
if(!s->budget--) { s->failed_pc=0x0c0a2c7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2c80;
P_0c0a2c80: /* original 894f, guest PC 0x0c0a2c80 */
if(!s->budget--) { s->failed_pc=0x0c0a2c80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2c82;
P_0c0a2c82: /* original 62c2, guest PC 0x0c0a2c82 */
if(!s->budget--) { s->failed_pc=0x0c0a2c82u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a2c84;
P_0c0a2c84: /* original 32dc, guest PC 0x0c0a2c84 */
if(!s->budget--) { s->failed_pc=0x0c0a2c84u; return 0; }
r[2]+=r[13];
goto P_0c0a2c86;
P_0c0a2c86: /* original 2c22, guest PC 0x0c0a2c86 */
if(!s->budget--) { s->failed_pc=0x0c0a2c86u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0a2c88;
P_0c0a2c88: /* original 63c2, guest PC 0x0c0a2c88 */
if(!s->budget--) { s->failed_pc=0x0c0a2c88u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0a2c8a;
P_0c0a2c8a: /* original 23a8, guest PC 0x0c0a2c8a */
if(!s->budget--) { s->failed_pc=0x0c0a2c8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0a2c8c;
P_0c0a2c8c: /* original 8914, guest PC 0x0c0a2c8c */
if(!s->budget--) { s->failed_pc=0x0c0a2c8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cb8; }
goto P_0c0a2c8e;
P_0c0a2c8e: /* original 61c2, guest PC 0x0c0a2c8e */
if(!s->budget--) { s->failed_pc=0x0c0a2c8eu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0a2c90;
P_0c0a2c90: /* original 2189, guest PC 0x0c0a2c90 */
if(!s->budget--) { s->failed_pc=0x0c0a2c90u; return 0; }
r[1]&=r[8];
goto P_0c0a2c92;
P_0c0a2c92: /* original 6413, guest PC 0x0c0a2c92 */
if(!s->budget--) { s->failed_pc=0x0c0a2c92u; return 0; }
r[4]=r[1];
goto P_0c0a2c94;
P_0c0a2c94: /* original 2c12, guest PC 0x0c0a2c94 */
if(!s->budget--) { s->failed_pc=0x0c0a2c94u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0a2c96;
P_0c0a2c96: /* original 5341, guest PC 0x0c0a2c96 */
if(!s->budget--) { s->failed_pc=0x0c0a2c96u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2c98;
P_0c0a2c98: /* original 23ab, guest PC 0x0c0a2c98 */
if(!s->budget--) { s->failed_pc=0x0c0a2c98u; return 0; }
r[3]|=r[10];
goto P_0c0a2c9a;
P_0c0a2c9a: /* original a042, guest PC 0x0c0a2c9a */
if(!s->budget--) { s->failed_pc=0x0c0a2c9au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d22;
P_0c0a2c9c: /* original 1431, guest PC 0x0c0a2c9c */
if(!s->budget--) { s->failed_pc=0x0c0a2c9cu; return 0; }
write(ram,r[4]+4,r[3],4);
if(!vf3_matrix_family(0x0c0a2c9eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c9eu; return 0; } return 1;
P_0c0a2cb8: /* original 6ec2, guest PC 0x0c0a2cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cb8u; return 0; }
tmp=read(ram,r[12],4);
r[14]=tmp;
goto P_0c0a2cba;
P_0c0a2cba: /* original 63e2, guest PC 0x0c0a2cba */
if(!s->budget--) { s->failed_pc=0x0c0a2cbau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a2cbc;
P_0c0a2cbc: /* original 2338, guest PC 0x0c0a2cbc */
if(!s->budget--) { s->failed_pc=0x0c0a2cbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2cbe;
P_0c0a2cbe: /* original 8908, guest PC 0x0c0a2cbe */
if(!s->budget--) { s->failed_pc=0x0c0a2cbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cd2; }
goto P_0c0a2cc0;
P_0c0a2cc0: /* original 63e2, guest PC 0x0c0a2cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a2cc2;
P_0c0a2cc2: /* original 33d2, guest PC 0x0c0a2cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cc4;
P_0c0a2cc4: /* original 8905, guest PC 0x0c0a2cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cd2; }
goto P_0c0a2cc6;
P_0c0a2cc6: /* original 61e2, guest PC 0x0c0a2cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a2cc8;
P_0c0a2cc8: /* original 65d3, guest PC 0x0c0a2cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc8u; return 0; }
r[5]=r[13];
goto P_0c0a2cca;
P_0c0a2cca: /* original 31dc, guest PC 0x0c0a2cca */
if(!s->budget--) { s->failed_pc=0x0c0a2ccau; return 0; }
r[1]+=r[13];
goto P_0c0a2ccc;
P_0c0a2ccc: /* original 2e12, guest PC 0x0c0a2ccc */
if(!s->budget--) { s->failed_pc=0x0c0a2cccu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0a2cce;
P_0c0a2cce: /* original b03b, guest PC 0x0c0a2cce */
if(!s->budget--) { s->failed_pc=0x0c0a2cceu; return 0; }
target=code_base|0x0c0a2d48u; r[16]=code_base|0x0c0a2cd2u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2cd2u) { target=s->pc; goto dispatch; }
goto P_0c0a2cd2;
P_0c0a2cd0: /* original 6413, guest PC 0x0c0a2cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd0u; return 0; }
r[4]=r[1];
goto P_0c0a2cd2;
P_0c0a2cd2: /* original 52e1, guest PC 0x0c0a2cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd2u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cd4;
P_0c0a2cd4: /* original 2228, guest PC 0x0c0a2cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2cd6;
P_0c0a2cd6: /* original 8913, guest PC 0x0c0a2cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cd8;
P_0c0a2cd8: /* original 53e1, guest PC 0x0c0a2cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2cda;
P_0c0a2cda: /* original 33d2, guest PC 0x0c0a2cda */
if(!s->budget--) { s->failed_pc=0x0c0a2cdau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cdc;
P_0c0a2cdc: /* original 8910, guest PC 0x0c0a2cdc */
if(!s->budget--) { s->failed_pc=0x0c0a2cdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cde;
P_0c0a2cde: /* original 51e1, guest PC 0x0c0a2cde */
if(!s->budget--) { s->failed_pc=0x0c0a2cdeu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2ce0;
P_0c0a2ce0: /* original 31dc, guest PC 0x0c0a2ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce0u; return 0; }
r[1]+=r[13];
goto P_0c0a2ce2;
P_0c0a2ce2: /* original 6313, guest PC 0x0c0a2ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce2u; return 0; }
r[3]=r[1];
goto P_0c0a2ce4;
P_0c0a2ce4: /* original 1e11, guest PC 0x0c0a2ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce4u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2ce6;
P_0c0a2ce6: /* original 6232, guest PC 0x0c0a2ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0a2ce8;
P_0c0a2ce8: /* original 2228, guest PC 0x0c0a2ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2cea;
P_0c0a2cea: /* original 8909, guest PC 0x0c0a2cea */
if(!s->budget--) { s->failed_pc=0x0c0a2ceau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cec;
P_0c0a2cec: /* original 52e1, guest PC 0x0c0a2cec */
if(!s->budget--) { s->failed_pc=0x0c0a2cecu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cee;
P_0c0a2cee: /* original 6322, guest PC 0x0c0a2cee */
if(!s->budget--) { s->failed_pc=0x0c0a2ceeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0a2cf0;
P_0c0a2cf0: /* original 33d2, guest PC 0x0c0a2cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cf2;
P_0c0a2cf2: /* original 8905, guest PC 0x0c0a2cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cf4;
P_0c0a2cf4: /* original 61c2, guest PC 0x0c0a2cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0a2cf6;
P_0c0a2cf6: /* original 52e1, guest PC 0x0c0a2cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf6u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cf8;
P_0c0a2cf8: /* original 5311, guest PC 0x0c0a2cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf8u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0a2cfa;
P_0c0a2cfa: /* original 6122, guest PC 0x0c0a2cfa */
if(!s->budget--) { s->failed_pc=0x0c0a2cfau; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0a2cfc;
P_0c0a2cfc: /* original 31dc, guest PC 0x0c0a2cfc */
if(!s->budget--) { s->failed_pc=0x0c0a2cfcu; return 0; }
r[1]+=r[13];
goto P_0c0a2cfe;
P_0c0a2cfe: /* original 2312, guest PC 0x0c0a2cfe */
if(!s->budget--) { s->failed_pc=0x0c0a2cfeu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a2d00;
P_0c0a2d00: /* original 53e2, guest PC 0x0c0a2d00 */
if(!s->budget--) { s->failed_pc=0x0c0a2d00u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0a2d02;
P_0c0a2d02: /* original 2338, guest PC 0x0c0a2d02 */
if(!s->budget--) { s->failed_pc=0x0c0a2d02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d04;
P_0c0a2d04: /* original 890d, guest PC 0x0c0a2d04 */
if(!s->budget--) { s->failed_pc=0x0c0a2d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d06;
P_0c0a2d06: /* original 53e2, guest PC 0x0c0a2d06 */
if(!s->budget--) { s->failed_pc=0x0c0a2d06u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0a2d08;
P_0c0a2d08: /* original 33d2, guest PC 0x0c0a2d08 */
if(!s->budget--) { s->failed_pc=0x0c0a2d08u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d0a;
P_0c0a2d0a: /* original 890a, guest PC 0x0c0a2d0a */
if(!s->budget--) { s->failed_pc=0x0c0a2d0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d0c;
P_0c0a2d0c: /* original 51e2, guest PC 0x0c0a2d0c */
if(!s->budget--) { s->failed_pc=0x0c0a2d0cu; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c0a2d0e;
P_0c0a2d0e: /* original 31dc, guest PC 0x0c0a2d0e */
if(!s->budget--) { s->failed_pc=0x0c0a2d0eu; return 0; }
r[1]+=r[13];
goto P_0c0a2d10;
P_0c0a2d10: /* original 6313, guest PC 0x0c0a2d10 */
if(!s->budget--) { s->failed_pc=0x0c0a2d10u; return 0; }
r[3]=r[1];
goto P_0c0a2d12;
P_0c0a2d12: /* original 1e12, guest PC 0x0c0a2d12 */
if(!s->budget--) { s->failed_pc=0x0c0a2d12u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c0a2d14;
P_0c0a2d14: /* original 6232, guest PC 0x0c0a2d14 */
if(!s->budget--) { s->failed_pc=0x0c0a2d14u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0a2d16;
P_0c0a2d16: /* original 2228, guest PC 0x0c0a2d16 */
if(!s->budget--) { s->failed_pc=0x0c0a2d16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d18;
P_0c0a2d18: /* original 8903, guest PC 0x0c0a2d18 */
if(!s->budget--) { s->failed_pc=0x0c0a2d18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d1a;
P_0c0a2d1a: /* original 54e2, guest PC 0x0c0a2d1a */
if(!s->budget--) { s->failed_pc=0x0c0a2d1au; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0a2d1c;
P_0c0a2d1c: /* original 6342, guest PC 0x0c0a2d1c */
if(!s->budget--) { s->failed_pc=0x0c0a2d1cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0a2d1e;
P_0c0a2d1e: /* original 33dc, guest PC 0x0c0a2d1e */
if(!s->budget--) { s->failed_pc=0x0c0a2d1eu; return 0; }
r[3]+=r[13];
goto P_0c0a2d20;
P_0c0a2d20: /* original 2432, guest PC 0x0c0a2d20 */
if(!s->budget--) { s->failed_pc=0x0c0a2d20u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0a2d22;
P_0c0a2d22: /* original 7901, guest PC 0x0c0a2d22 */
if(!s->budget--) { s->failed_pc=0x0c0a2d22u; return 0; }
r[9]+=0x00000001u;
goto P_0c0a2d24;
P_0c0a2d24: /* original 85b6, guest PC 0x0c0a2d24 */
if(!s->budget--) { s->failed_pc=0x0c0a2d24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0a2d26;
P_0c0a2d26: /* original 600d, guest PC 0x0c0a2d26 */
if(!s->budget--) { s->failed_pc=0x0c0a2d26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2d28;
P_0c0a2d28: /* original 3903, guest PC 0x0c0a2d28 */
if(!s->budget--) { s->failed_pc=0x0c0a2d28u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[0])!=0);
goto P_0c0a2d2a;
P_0c0a2d2a: /* original 8ba3, guest PC 0x0c0a2d2a */
if(!s->budget--) { s->failed_pc=0x0c0a2d2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2c74; }
goto P_0c0a2d2c;
P_0c0a2d2c: /* original 60b2, guest PC 0x0c0a2d2c */
if(!s->budget--) { s->failed_pc=0x0c0a2d2cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0a2d2e;
P_0c0a2d2e: /* original cb80, guest PC 0x0c0a2d2e */
if(!s->budget--) { s->failed_pc=0x0c0a2d2eu; return 0; }
r[0]|=128u;
goto P_0c0a2d30;
P_0c0a2d30: /* original 2b02, guest PC 0x0c0a2d30 */
if(!s->budget--) { s->failed_pc=0x0c0a2d30u; return 0; }
write(ram,r[11],r[0],4);
goto P_0c0a2d32;
P_0c0a2d32: /* original 50f1, guest PC 0x0c0a2d32 */
if(!s->budget--) { s->failed_pc=0x0c0a2d32u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a2d34;
P_0c0a2d34: /* original 7f08, guest PC 0x0c0a2d34 */
if(!s->budget--) { s->failed_pc=0x0c0a2d34u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2d36;
P_0c0a2d36: /* original 4f26, guest PC 0x0c0a2d36 */
if(!s->budget--) { s->failed_pc=0x0c0a2d36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2d38;
P_0c0a2d38: /* original 68f6, guest PC 0x0c0a2d38 */
if(!s->budget--) { s->failed_pc=0x0c0a2d38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2d3a;
P_0c0a2d3a: /* original 69f6, guest PC 0x0c0a2d3a */
if(!s->budget--) { s->failed_pc=0x0c0a2d3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2d3c;
P_0c0a2d3c: /* original 6af6, guest PC 0x0c0a2d3c */
if(!s->budget--) { s->failed_pc=0x0c0a2d3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2d3e;
P_0c0a2d3e: /* original 6bf6, guest PC 0x0c0a2d3e */
if(!s->budget--) { s->failed_pc=0x0c0a2d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2d40;
P_0c0a2d40: /* original 6cf6, guest PC 0x0c0a2d40 */
if(!s->budget--) { s->failed_pc=0x0c0a2d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2d42;
P_0c0a2d42: /* original 6df6, guest PC 0x0c0a2d42 */
if(!s->budget--) { s->failed_pc=0x0c0a2d42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2d44;
P_0c0a2d44: /* original 000b, guest PC 0x0c0a2d44 */
if(!s->budget--) { s->failed_pc=0x0c0a2d44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2d46: /* original 6ef6, guest PC 0x0c0a2d46 */
if(!s->budget--) { s->failed_pc=0x0c0a2d46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0a2d48u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
