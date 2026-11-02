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
int vf3_away_batch108_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c092a70u: goto P_0c092a70;
case 0x0c092a72u: goto P_0c092a72;
case 0x0c092a74u: goto P_0c092a74;
case 0x0c092a76u: goto P_0c092a76;
case 0x0c092a78u: goto P_0c092a78;
case 0x0c092a7au: goto P_0c092a7a;
case 0x0c092a7cu: goto P_0c092a7c;
case 0x0c092a7eu: goto P_0c092a7e;
case 0x0c092a80u: goto P_0c092a80;
case 0x0c092a82u: goto P_0c092a82;
case 0x0c092a84u: goto P_0c092a84;
case 0x0c092a86u: goto P_0c092a86;
case 0x0c092a88u: goto P_0c092a88;
case 0x0c092a8au: goto P_0c092a8a;
case 0x0c092a8cu: goto P_0c092a8c;
case 0x0c092a8eu: goto P_0c092a8e;
case 0x0c092a90u: goto P_0c092a90;
case 0x0c092a92u: goto P_0c092a92;
case 0x0c092a94u: goto P_0c092a94;
case 0x0c092a96u: goto P_0c092a96;
case 0x0c092a98u: goto P_0c092a98;
case 0x0c092a9au: goto P_0c092a9a;
case 0x0c092aa8u: goto P_0c092aa8;
case 0x0c092aaau: goto P_0c092aaa;
case 0x0c092aacu: goto P_0c092aac;
case 0x0c092aaeu: goto P_0c092aae;
case 0x0c092ab0u: goto P_0c092ab0;
case 0x0c092ab2u: goto P_0c092ab2;
case 0x0c092ab4u: goto P_0c092ab4;
case 0x0c092ab6u: goto P_0c092ab6;
case 0x0c092ab8u: goto P_0c092ab8;
case 0x0c092abau: goto P_0c092aba;
case 0x0c092abcu: goto P_0c092abc;
case 0x0c092abeu: goto P_0c092abe;
case 0x0c092ac0u: goto P_0c092ac0;
case 0x0c092ac2u: goto P_0c092ac2;
case 0x0c092ac4u: goto P_0c092ac4;
case 0x0c092ac6u: goto P_0c092ac6;
case 0x0c092ac8u: goto P_0c092ac8;
case 0x0c092acau: goto P_0c092aca;
case 0x0c092accu: goto P_0c092acc;
case 0x0c092aceu: goto P_0c092ace;
case 0x0c092ad0u: goto P_0c092ad0;
case 0x0c092ad2u: goto P_0c092ad2;
case 0x0c092ad4u: goto P_0c092ad4;
case 0x0c092b16u: goto P_0c092b16;
case 0x0c092b18u: goto P_0c092b18;
case 0x0c092b1au: goto P_0c092b1a;
case 0x0c092b1cu: goto P_0c092b1c;
case 0x0c092b1eu: goto P_0c092b1e;
case 0x0c092b20u: goto P_0c092b20;
case 0x0c092b22u: goto P_0c092b22;
case 0x0c092b24u: goto P_0c092b24;
case 0x0c092b26u: goto P_0c092b26;
case 0x0c092b28u: goto P_0c092b28;
case 0x0c092b2au: goto P_0c092b2a;
case 0x0c092b2cu: goto P_0c092b2c;
case 0x0c092b2eu: goto P_0c092b2e;
case 0x0c092b30u: goto P_0c092b30;
case 0x0c092b32u: goto P_0c092b32;
case 0x0c092b34u: goto P_0c092b34;
case 0x0c092b36u: goto P_0c092b36;
case 0x0c092b38u: goto P_0c092b38;
case 0x0c092b3au: goto P_0c092b3a;
case 0x0c092b3cu: goto P_0c092b3c;
case 0x0c092b3eu: goto P_0c092b3e;
case 0x0c092b40u: goto P_0c092b40;
case 0x0c092b42u: goto P_0c092b42;
case 0x0c092b44u: goto P_0c092b44;
case 0x0c092b46u: goto P_0c092b46;
case 0x0c092b48u: goto P_0c092b48;
case 0x0c092b4au: goto P_0c092b4a;
case 0x0c092b4cu: goto P_0c092b4c;
case 0x0c092b4eu: goto P_0c092b4e;
case 0x0c092b50u: goto P_0c092b50;
case 0x0c092b52u: goto P_0c092b52;
case 0x0c092b54u: goto P_0c092b54;
case 0x0c092b56u: goto P_0c092b56;
case 0x0c092b58u: goto P_0c092b58;
case 0x0c092b5au: goto P_0c092b5a;
case 0x0c092b5cu: goto P_0c092b5c;
case 0x0c092b5eu: goto P_0c092b5e;
case 0x0c092b60u: goto P_0c092b60;
case 0x0c092b74u: goto P_0c092b74;
case 0x0c092b76u: goto P_0c092b76;
case 0x0c092b78u: goto P_0c092b78;
case 0x0c092b7au: goto P_0c092b7a;
case 0x0c092b7cu: goto P_0c092b7c;
case 0x0c092b7eu: goto P_0c092b7e;
case 0x0c092b80u: goto P_0c092b80;
case 0x0c092b82u: goto P_0c092b82;
case 0x0c092b84u: goto P_0c092b84;
case 0x0c092b86u: goto P_0c092b86;
case 0x0c092b88u: goto P_0c092b88;
case 0x0c092b8au: goto P_0c092b8a;
case 0x0c092b8cu: goto P_0c092b8c;
case 0x0c092b8eu: goto P_0c092b8e;
case 0x0c092b90u: goto P_0c092b90;
case 0x0c092b92u: goto P_0c092b92;
case 0x0c092b94u: goto P_0c092b94;
case 0x0c092b96u: goto P_0c092b96;
case 0x0c092b98u: goto P_0c092b98;
case 0x0c092b9au: goto P_0c092b9a;
case 0x0c092b9cu: goto P_0c092b9c;
case 0x0c092b9eu: goto P_0c092b9e;
case 0x0c092ba0u: goto P_0c092ba0;
case 0x0c092ba2u: goto P_0c092ba2;
case 0x0c092ba4u: goto P_0c092ba4;
case 0x0c092ba6u: goto P_0c092ba6;
case 0x0c092ba8u: goto P_0c092ba8;
case 0x0c092baau: goto P_0c092baa;
case 0x0c092bacu: goto P_0c092bac;
case 0x0c092bb4u: goto P_0c092bb4;
case 0x0c092bb6u: goto P_0c092bb6;
case 0x0c092bb8u: goto P_0c092bb8;
case 0x0c092bbau: goto P_0c092bba;
case 0x0c092bbcu: goto P_0c092bbc;
case 0x0c092bbeu: goto P_0c092bbe;
case 0x0c092bc0u: goto P_0c092bc0;
case 0x0c092bc2u: goto P_0c092bc2;
case 0x0c092bc4u: goto P_0c092bc4;
case 0x0c092bc6u: goto P_0c092bc6;
case 0x0c092bc8u: goto P_0c092bc8;
case 0x0c092bcau: goto P_0c092bca;
case 0x0c092bccu: goto P_0c092bcc;
case 0x0c092bceu: goto P_0c092bce;
case 0x0c092bd0u: goto P_0c092bd0;
case 0x0c092bd2u: goto P_0c092bd2;
case 0x0c092bd4u: goto P_0c092bd4;
case 0x0c092bd6u: goto P_0c092bd6;
case 0x0c092bd8u: goto P_0c092bd8;
case 0x0c092bdau: goto P_0c092bda;
case 0x0c092bdcu: goto P_0c092bdc;
case 0x0c092bdeu: goto P_0c092bde;
case 0x0c092be0u: goto P_0c092be0;
case 0x0c092be2u: goto P_0c092be2;
case 0x0c092be4u: goto P_0c092be4;
case 0x0c092be6u: goto P_0c092be6;
case 0x0c092be8u: goto P_0c092be8;
case 0x0c092beau: goto P_0c092bea;
case 0x0c092becu: goto P_0c092bec;
case 0x0c092beeu: goto P_0c092bee;
case 0x0c092bf0u: goto P_0c092bf0;
case 0x0c092bf2u: goto P_0c092bf2;
case 0x0c092bf4u: goto P_0c092bf4;
case 0x0c092bf6u: goto P_0c092bf6;
case 0x0c092bf8u: goto P_0c092bf8;
case 0x0c092bfau: goto P_0c092bfa;
case 0x0c092bfcu: goto P_0c092bfc;
case 0x0c092bfeu: goto P_0c092bfe;
case 0x0c092c04u: goto P_0c092c04;
case 0x0c092c06u: goto P_0c092c06;
case 0x0c092c08u: goto P_0c092c08;
case 0x0c092c0au: goto P_0c092c0a;
case 0x0c092c0cu: goto P_0c092c0c;
case 0x0c092c0eu: goto P_0c092c0e;
case 0x0c092c10u: goto P_0c092c10;
case 0x0c092c12u: goto P_0c092c12;
case 0x0c092c14u: goto P_0c092c14;
case 0x0c092c16u: goto P_0c092c16;
case 0x0c092c18u: goto P_0c092c18;
case 0x0c092c1au: goto P_0c092c1a;
case 0x0c092c1cu: goto P_0c092c1c;
case 0x0c092c1eu: goto P_0c092c1e;
case 0x0c092c20u: goto P_0c092c20;
case 0x0c092c22u: goto P_0c092c22;
case 0x0c092c24u: goto P_0c092c24;
case 0x0c092c26u: goto P_0c092c26;
case 0x0c092c28u: goto P_0c092c28;
case 0x0c092c2au: goto P_0c092c2a;
case 0x0c092c2cu: goto P_0c092c2c;
case 0x0c092c2eu: goto P_0c092c2e;
case 0x0c092c30u: goto P_0c092c30;
case 0x0c092c32u: goto P_0c092c32;
case 0x0c092c34u: goto P_0c092c34;
case 0x0c092c36u: goto P_0c092c36;
case 0x0c092c38u: goto P_0c092c38;
case 0x0c092c3au: goto P_0c092c3a;
case 0x0c092c3cu: goto P_0c092c3c;
case 0x0c092c3eu: goto P_0c092c3e;
case 0x0c092c40u: goto P_0c092c40;
case 0x0c092c42u: goto P_0c092c42;
case 0x0c092c44u: goto P_0c092c44;
case 0x0c092c46u: goto P_0c092c46;
case 0x0c092c48u: goto P_0c092c48;
case 0x0c092c4au: goto P_0c092c4a;
case 0x0c092c4cu: goto P_0c092c4c;
case 0x0c092c4eu: goto P_0c092c4e;
case 0x0c092c50u: goto P_0c092c50;
case 0x0c092c52u: goto P_0c092c52;
case 0x0c092c54u: goto P_0c092c54;
case 0x0c092c56u: goto P_0c092c56;
case 0x0c092c58u: goto P_0c092c58;
case 0x0c092c5au: goto P_0c092c5a;
case 0x0c092c5cu: goto P_0c092c5c;
case 0x0c092c5eu: goto P_0c092c5e;
case 0x0c092c60u: goto P_0c092c60;
case 0x0c092c62u: goto P_0c092c62;
case 0x0c092c64u: goto P_0c092c64;
case 0x0c092c66u: goto P_0c092c66;
case 0x0c092c68u: goto P_0c092c68;
case 0x0c092c6au: goto P_0c092c6a;
case 0x0c092c6cu: goto P_0c092c6c;
case 0x0c092c6eu: goto P_0c092c6e;
case 0x0c092c70u: goto P_0c092c70;
case 0x0c092c72u: goto P_0c092c72;
case 0x0c092c74u: goto P_0c092c74;
case 0x0c092c76u: goto P_0c092c76;
case 0x0c092c78u: goto P_0c092c78;
case 0x0c092c7au: goto P_0c092c7a;
case 0x0c092c7cu: goto P_0c092c7c;
case 0x0c092c7eu: goto P_0c092c7e;
case 0x0c092c80u: goto P_0c092c80;
case 0x0c092c82u: goto P_0c092c82;
case 0x0c092c84u: goto P_0c092c84;
case 0x0c092c86u: goto P_0c092c86;
case 0x0c092c88u: goto P_0c092c88;
case 0x0c092c8au: goto P_0c092c8a;
case 0x0c092c8cu: goto P_0c092c8c;
case 0x0c092c8eu: goto P_0c092c8e;
case 0x0c092c90u: goto P_0c092c90;
case 0x0c092c92u: goto P_0c092c92;
case 0x0c092c94u: goto P_0c092c94;
case 0x0c092c96u: goto P_0c092c96;
case 0x0c092c98u: goto P_0c092c98;
case 0x0c092c9au: goto P_0c092c9a;
case 0x0c092c9cu: goto P_0c092c9c;
case 0x0c092c9eu: goto P_0c092c9e;
case 0x0c092ca0u: goto P_0c092ca0;
case 0x0c092ca2u: goto P_0c092ca2;
case 0x0c092ca4u: goto P_0c092ca4;
case 0x0c092ca6u: goto P_0c092ca6;
case 0x0c092ca8u: goto P_0c092ca8;
case 0x0c092caau: goto P_0c092caa;
case 0x0c092cacu: goto P_0c092cac;
case 0x0c092caeu: goto P_0c092cae;
case 0x0c092cb0u: goto P_0c092cb0;
case 0x0c092cb2u: goto P_0c092cb2;
case 0x0c092cb4u: goto P_0c092cb4;
case 0x0c092cb6u: goto P_0c092cb6;
case 0x0c092cb8u: goto P_0c092cb8;
case 0x0c092cbau: goto P_0c092cba;
case 0x0c092cbcu: goto P_0c092cbc;
case 0x0c092cbeu: goto P_0c092cbe;
case 0x0c092cc0u: goto P_0c092cc0;
case 0x0c092cc2u: goto P_0c092cc2;
case 0x0c092cc4u: goto P_0c092cc4;
case 0x0c092cc6u: goto P_0c092cc6;
case 0x0c092cc8u: goto P_0c092cc8;
case 0x0c092ccau: goto P_0c092cca;
case 0x0c092cccu: goto P_0c092ccc;
case 0x0c092cceu: goto P_0c092cce;
case 0x0c092cd0u: goto P_0c092cd0;
case 0x0c092cd2u: goto P_0c092cd2;
case 0x0c092cd4u: goto P_0c092cd4;
case 0x0c092cd6u: goto P_0c092cd6;
case 0x0c092cd8u: goto P_0c092cd8;
case 0x0c092cdau: goto P_0c092cda;
case 0x0c092cdcu: goto P_0c092cdc;
case 0x0c092cdeu: goto P_0c092cde;
case 0x0c092ce0u: goto P_0c092ce0;
case 0x0c092ce2u: goto P_0c092ce2;
case 0x0c092ce4u: goto P_0c092ce4;
case 0x0c092ce6u: goto P_0c092ce6;
case 0x0c092ce8u: goto P_0c092ce8;
case 0x0c092ceau: goto P_0c092cea;
case 0x0c092cecu: goto P_0c092cec;
case 0x0c092ceeu: goto P_0c092cee;
case 0x0c092cf0u: goto P_0c092cf0;
case 0x0c092cf2u: goto P_0c092cf2;
case 0x0c092cf4u: goto P_0c092cf4;
case 0x0c092cf6u: goto P_0c092cf6;
case 0x0c092cf8u: goto P_0c092cf8;
case 0x0c092cfau: goto P_0c092cfa;
case 0x0c092cfcu: goto P_0c092cfc;
case 0x0c092cfeu: goto P_0c092cfe;
case 0x0c092d00u: goto P_0c092d00;
case 0x0c092d02u: goto P_0c092d02;
case 0x0c092d04u: goto P_0c092d04;
case 0x0c092d06u: goto P_0c092d06;
case 0x0c092d08u: goto P_0c092d08;
case 0x0c092d0au: goto P_0c092d0a;
case 0x0c092d0cu: goto P_0c092d0c;
case 0x0c092d0eu: goto P_0c092d0e;
case 0x0c092d10u: goto P_0c092d10;
case 0x0c092d12u: goto P_0c092d12;
case 0x0c092d14u: goto P_0c092d14;
case 0x0c092d16u: goto P_0c092d16;
case 0x0c092d18u: goto P_0c092d18;
case 0x0c092d1au: goto P_0c092d1a;
case 0x0c092d1cu: goto P_0c092d1c;
case 0x0c092d1eu: goto P_0c092d1e;
case 0x0c092d20u: goto P_0c092d20;
case 0x0c092d22u: goto P_0c092d22;
case 0x0c092d24u: goto P_0c092d24;
case 0x0c092d26u: goto P_0c092d26;
case 0x0c092d28u: goto P_0c092d28;
case 0x0c092d2au: goto P_0c092d2a;
case 0x0c092d2cu: goto P_0c092d2c;
case 0x0c092d2eu: goto P_0c092d2e;
case 0x0c092d30u: goto P_0c092d30;
case 0x0c092d32u: goto P_0c092d32;
case 0x0c092d34u: goto P_0c092d34;
case 0x0c092d36u: goto P_0c092d36;
case 0x0c092d38u: goto P_0c092d38;
case 0x0c092d3au: goto P_0c092d3a;
case 0x0c092d3cu: goto P_0c092d3c;
case 0x0c092d3eu: goto P_0c092d3e;
case 0x0c092d40u: goto P_0c092d40;
case 0x0c092d42u: goto P_0c092d42;
case 0x0c092d44u: goto P_0c092d44;
case 0x0c092d46u: goto P_0c092d46;
case 0x0c092d48u: goto P_0c092d48;
case 0x0c092d4au: goto P_0c092d4a;
case 0x0c092d4cu: goto P_0c092d4c;
case 0x0c092d4eu: goto P_0c092d4e;
case 0x0c092d50u: goto P_0c092d50;
case 0x0c092d52u: goto P_0c092d52;
case 0x0c092d54u: goto P_0c092d54;
case 0x0c092d56u: goto P_0c092d56;
case 0x0c092d58u: goto P_0c092d58;
case 0x0c092d5au: goto P_0c092d5a;
case 0x0c092d5cu: goto P_0c092d5c;
case 0x0c092d5eu: goto P_0c092d5e;
case 0x0c092d60u: goto P_0c092d60;
case 0x0c092d62u: goto P_0c092d62;
case 0x0c092d64u: goto P_0c092d64;
case 0x0c092d66u: goto P_0c092d66;
case 0x0c092d68u: goto P_0c092d68;
case 0x0c092d6au: goto P_0c092d6a;
case 0x0c092d6cu: goto P_0c092d6c;
case 0x0c092d6eu: goto P_0c092d6e;
case 0x0c092d70u: goto P_0c092d70;
case 0x0c092d72u: goto P_0c092d72;
case 0x0c092d74u: goto P_0c092d74;
case 0x0c092d76u: goto P_0c092d76;
case 0x0c092d78u: goto P_0c092d78;
case 0x0c092d7au: goto P_0c092d7a;
case 0x0c092d7cu: goto P_0c092d7c;
case 0x0c092d7eu: goto P_0c092d7e;
case 0x0c092d80u: goto P_0c092d80;
case 0x0c092d82u: goto P_0c092d82;
case 0x0c092d84u: goto P_0c092d84;
case 0x0c092d86u: goto P_0c092d86;
case 0x0c092d88u: goto P_0c092d88;
case 0x0c092d8au: goto P_0c092d8a;
case 0x0c092d8cu: goto P_0c092d8c;
case 0x0c092d8eu: goto P_0c092d8e;
case 0x0c092d90u: goto P_0c092d90;
case 0x0c092d92u: goto P_0c092d92;
case 0x0c092d94u: goto P_0c092d94;
case 0x0c092dacu: goto P_0c092dac;
case 0x0c092daeu: goto P_0c092dae;
case 0x0c092db0u: goto P_0c092db0;
case 0x0c092db2u: goto P_0c092db2;
case 0x0c092db4u: goto P_0c092db4;
case 0x0c092db6u: goto P_0c092db6;
case 0x0c092db8u: goto P_0c092db8;
case 0x0c092dbau: goto P_0c092dba;
case 0x0c092dbcu: goto P_0c092dbc;
case 0x0c092dbeu: goto P_0c092dbe;
case 0x0c092dc0u: goto P_0c092dc0;
case 0x0c092dc2u: goto P_0c092dc2;
case 0x0c092dc4u: goto P_0c092dc4;
case 0x0c092dc6u: goto P_0c092dc6;
case 0x0c092dc8u: goto P_0c092dc8;
case 0x0c092dcau: goto P_0c092dca;
case 0x0c092dccu: goto P_0c092dcc;
case 0x0c092dceu: goto P_0c092dce;
case 0x0c092dd0u: goto P_0c092dd0;
case 0x0c092dd2u: goto P_0c092dd2;
case 0x0c092dd4u: goto P_0c092dd4;
case 0x0c092dd6u: goto P_0c092dd6;
case 0x0c092dd8u: goto P_0c092dd8;
case 0x0c092ddau: goto P_0c092dda;
case 0x0c092ddcu: goto P_0c092ddc;
case 0x0c092ddeu: goto P_0c092dde;
case 0x0c092de0u: goto P_0c092de0;
case 0x0c092de2u: goto P_0c092de2;
case 0x0c092de4u: goto P_0c092de4;
case 0x0c092de6u: goto P_0c092de6;
case 0x0c092de8u: goto P_0c092de8;
case 0x0c092deau: goto P_0c092dea;
case 0x0c092decu: goto P_0c092dec;
case 0x0c092deeu: goto P_0c092dee;
case 0x0c092df0u: goto P_0c092df0;
case 0x0c092df2u: goto P_0c092df2;
case 0x0c092df4u: goto P_0c092df4;
case 0x0c092df6u: goto P_0c092df6;
case 0x0c092df8u: goto P_0c092df8;
case 0x0c092dfau: goto P_0c092dfa;
case 0x0c092dfcu: goto P_0c092dfc;
case 0x0c092dfeu: goto P_0c092dfe;
case 0x0c092e00u: goto P_0c092e00;
case 0x0c092e02u: goto P_0c092e02;
case 0x0c092e04u: goto P_0c092e04;
case 0x0c092e06u: goto P_0c092e06;
case 0x0c092e08u: goto P_0c092e08;
case 0x0c092e0au: goto P_0c092e0a;
case 0x0c092e0cu: goto P_0c092e0c;
case 0x0c092e0eu: goto P_0c092e0e;
case 0x0c092e10u: goto P_0c092e10;
case 0x0c092e12u: goto P_0c092e12;
case 0x0c092e14u: goto P_0c092e14;
case 0x0c092e16u: goto P_0c092e16;
case 0x0c092e18u: goto P_0c092e18;
case 0x0c092e1au: goto P_0c092e1a;
case 0x0c092e1cu: goto P_0c092e1c;
case 0x0c092e1eu: goto P_0c092e1e;
case 0x0c092e20u: goto P_0c092e20;
case 0x0c092e22u: goto P_0c092e22;
case 0x0c092e24u: goto P_0c092e24;
case 0x0c092e26u: goto P_0c092e26;
case 0x0c092e28u: goto P_0c092e28;
case 0x0c092e2au: goto P_0c092e2a;
case 0x0c092e2cu: goto P_0c092e2c;
case 0x0c092e2eu: goto P_0c092e2e;
case 0x0c092e30u: goto P_0c092e30;
case 0x0c092e32u: goto P_0c092e32;
case 0x0c092e34u: goto P_0c092e34;
case 0x0c092e36u: goto P_0c092e36;
case 0x0c092e38u: goto P_0c092e38;
case 0x0c092e3au: goto P_0c092e3a;
case 0x0c092e3cu: goto P_0c092e3c;
case 0x0c092e3eu: goto P_0c092e3e;
case 0x0c092e40u: goto P_0c092e40;
case 0x0c092e42u: goto P_0c092e42;
case 0x0c092e44u: goto P_0c092e44;
case 0x0c092e46u: goto P_0c092e46;
case 0x0c092e48u: goto P_0c092e48;
case 0x0c092e4au: goto P_0c092e4a;
case 0x0c092e4cu: goto P_0c092e4c;
case 0x0c092e4eu: goto P_0c092e4e;
case 0x0c092e50u: goto P_0c092e50;
case 0x0c092e52u: goto P_0c092e52;
default: return vf3_matrix_family(target,s,ram);
}
P_0c092a70: /* original 7ff4, guest PC 0x0c092a70 */
if(!s->budget--) { s->failed_pc=0x0c092a70u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c092a72;
P_0c092a72: /* original 1f52, guest PC 0x0c092a72 */
if(!s->budget--) { s->failed_pc=0x0c092a72u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c092a74;
P_0c092a74: /* original 1f61, guest PC 0x0c092a74 */
if(!s->budget--) { s->failed_pc=0x0c092a74u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c092a76;
P_0c092a76: /* original 2f72, guest PC 0x0c092a76 */
if(!s->budget--) { s->failed_pc=0x0c092a76u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c092a78;
P_0c092a78: /* original d109, guest PC 0x0c092a78 */
if(!s->budget--) { s->failed_pc=0x0c092a78u; return 0; }
r[1]=read(ram,0x0c092aa0u,4);
goto P_0c092a7a;
P_0c092a7a: /* original d308, guest PC 0x0c092a7a */
if(!s->budget--) { s->failed_pc=0x0c092a7au; return 0; }
r[3]=read(ram,0x0c092a9cu,4);
goto P_0c092a7c;
P_0c092a7c: /* original 6212, guest PC 0x0c092a7c */
if(!s->budget--) { s->failed_pc=0x0c092a7cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c092a7e;
P_0c092a7e: /* original 2238, guest PC 0x0c092a7e */
if(!s->budget--) { s->failed_pc=0x0c092a7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c092a80;
P_0c092a80: /* original 8907, guest PC 0x0c092a80 */
if(!s->budget--) { s->failed_pc=0x0c092a80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092a92; }
goto P_0c092a82;
P_0c092a82: /* original e061, guest PC 0x0c092a82 */
if(!s->budget--) { s->failed_pc=0x0c092a82u; return 0; }
r[0]=0x00000061u;
goto P_0c092a84;
P_0c092a84: /* original 004c, guest PC 0x0c092a84 */
if(!s->budget--) { s->failed_pc=0x0c092a84u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c092a86;
P_0c092a86: /* original 600c, guest PC 0x0c092a86 */
if(!s->budget--) { s->failed_pc=0x0c092a86u; return 0; }
r[0]=r[0]&255u;
goto P_0c092a88;
P_0c092a88: /* original 880b, guest PC 0x0c092a88 */
if(!s->budget--) { s->failed_pc=0x0c092a88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c092a8a;
P_0c092a8a: /* original 8b02, guest PC 0x0c092a8a */
if(!s->budget--) { s->failed_pc=0x0c092a8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092a92; }
goto P_0c092a8c;
P_0c092a8c: /* original d205, guest PC 0x0c092a8c */
if(!s->budget--) { s->failed_pc=0x0c092a8cu; return 0; }
r[2]=read(ram,0x0c092aa4u,4);
goto P_0c092a8e;
P_0c092a8e: /* original 422b, guest PC 0x0c092a8e */
if(!s->budget--) { s->failed_pc=0x0c092a8eu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c092ac0u: goto P_0c092ac0;
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
P_0c092a90: /* original 0009, guest PC 0x0c092a90 */
if(!s->budget--) { s->failed_pc=0x0c092a90u; return 0; }
goto P_0c092a92;
P_0c092a92: /* original 55f2, guest PC 0x0c092a92 */
if(!s->budget--) { s->failed_pc=0x0c092a92u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c092a94;
P_0c092a94: /* original 64f2, guest PC 0x0c092a94 */
if(!s->budget--) { s->failed_pc=0x0c092a94u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c092a96;
P_0c092a96: /* original 7518, guest PC 0x0c092a96 */
if(!s->budget--) { s->failed_pc=0x0c092a96u; return 0; }
r[5]+=0x00000018u;
goto P_0c092a98;
P_0c092a98: /* original a006, guest PC 0x0c092a98 */
if(!s->budget--) { s->failed_pc=0x0c092a98u; return 0; }
goto P_0c092aa8;
P_0c092a9a: /* original 0009, guest PC 0x0c092a9a */
if(!s->budget--) { s->failed_pc=0x0c092a9au; return 0; }
if(!vf3_matrix_family(0x0c092a9cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092a9cu; return 0; } return 1;
P_0c092aa8: /* original f049, guest PC 0x0c092aa8 */
if(!s->budget--) { s->failed_pc=0x0c092aa8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092aaa;
P_0c092aaa: /* original f359, guest PC 0x0c092aaa */
if(!s->budget--) { s->failed_pc=0x0c092aaau; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092aac;
P_0c092aac: /* original f149, guest PC 0x0c092aac */
if(!s->budget--) { s->failed_pc=0x0c092aacu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092aae;
P_0c092aae: /* original f459, guest PC 0x0c092aae */
if(!s->budget--) { s->failed_pc=0x0c092aaeu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092ab0;
P_0c092ab0: /* original f249, guest PC 0x0c092ab0 */
if(!s->budget--) { s->failed_pc=0x0c092ab0u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092ab2;
P_0c092ab2: /* original f559, guest PC 0x0c092ab2 */
if(!s->budget--) { s->failed_pc=0x0c092ab2u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092ab4;
P_0c092ab4: /* original f030, guest PC 0x0c092ab4 */
if(!s->budget--) { s->failed_pc=0x0c092ab4u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c092ab6;
P_0c092ab6: /* original f250, guest PC 0x0c092ab6 */
if(!s->budget--) { s->failed_pc=0x0c092ab6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c092ab8;
P_0c092ab8: /* original f140, guest PC 0x0c092ab8 */
if(!s->budget--) { s->failed_pc=0x0c092ab8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c092aba;
P_0c092aba: /* original f42b, guest PC 0x0c092aba */
if(!s->budget--) { s->failed_pc=0x0c092abau; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092abc;
P_0c092abc: /* original f41b, guest PC 0x0c092abc */
if(!s->budget--) { s->failed_pc=0x0c092abcu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092abe;
P_0c092abe: /* original f40b, guest PC 0x0c092abe */
if(!s->budget--) { s->failed_pc=0x0c092abeu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092ac0;
P_0c092ac0: /* original 53f1, guest PC 0x0c092ac0 */
if(!s->budget--) { s->failed_pc=0x0c092ac0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c092ac2;
P_0c092ac2: /* original e004, guest PC 0x0c092ac2 */
if(!s->budget--) { s->failed_pc=0x0c092ac2u; return 0; }
r[0]=0x00000004u;
goto P_0c092ac4;
P_0c092ac4: /* original 6103, guest PC 0x0c092ac4 */
if(!s->budget--) { s->failed_pc=0x0c092ac4u; return 0; }
r[1]=r[0];
goto P_0c092ac6;
P_0c092ac6: /* original 62f2, guest PC 0x0c092ac6 */
if(!s->budget--) { s->failed_pc=0x0c092ac6u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c092ac8;
P_0c092ac8: /* original 313c, guest PC 0x0c092ac8 */
if(!s->budget--) { s->failed_pc=0x0c092ac8u; return 0; }
r[1]+=r[3];
goto P_0c092aca;
P_0c092aca: /* original f226, guest PC 0x0c092aca */
if(!s->budget--) { s->failed_pc=0x0c092acau; return 0; }
vf3_matrix_load(s,ram,2,r[2]+r[0]);
goto P_0c092acc;
P_0c092acc: /* original f318, guest PC 0x0c092acc */
if(!s->budget--) { s->failed_pc=0x0c092accu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c092ace;
P_0c092ace: /* original f230, guest PC 0x0c092ace */
if(!s->budget--) { s->failed_pc=0x0c092aceu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c092ad0;
P_0c092ad0: /* original f227, guest PC 0x0c092ad0 */
if(!s->budget--) { s->failed_pc=0x0c092ad0u; return 0; }
vf3_matrix_store(s,ram,2,r[2]+r[0]);
goto P_0c092ad2;
P_0c092ad2: /* original 000b, guest PC 0x0c092ad2 */
if(!s->budget--) { s->failed_pc=0x0c092ad2u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c092ad4: /* original 7f0c, guest PC 0x0c092ad4 */
if(!s->budget--) { s->failed_pc=0x0c092ad4u; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c092ad6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092ad6u; return 0; } return 1;
P_0c092b16: /* original d116, guest PC 0x0c092b16 */
if(!s->budget--) { s->failed_pc=0x0c092b16u; return 0; }
r[1]=read(ram,0x0c092b70u,4);
goto P_0c092b18;
P_0c092b18: /* original d314, guest PC 0x0c092b18 */
if(!s->budget--) { s->failed_pc=0x0c092b18u; return 0; }
r[3]=read(ram,0x0c092b6cu,4);
goto P_0c092b1a;
P_0c092b1a: /* original 6212, guest PC 0x0c092b1a */
if(!s->budget--) { s->failed_pc=0x0c092b1au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c092b1c;
P_0c092b1c: /* original 2238, guest PC 0x0c092b1c */
if(!s->budget--) { s->failed_pc=0x0c092b1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c092b1e;
P_0c092b1e: /* original 8901, guest PC 0x0c092b1e */
if(!s->budget--) { s->failed_pc=0x0c092b1eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092b24; }
goto P_0c092b20;
P_0c092b20: /* original a001, guest PC 0x0c092b20 */
if(!s->budget--) { s->failed_pc=0x0c092b20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+4,2);
goto P_0c092b26;
P_0c092b22: /* original 8552, guest PC 0x0c092b22 */
if(!s->budget--) { s->failed_pc=0x0c092b22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+4,2);
goto P_0c092b24;
P_0c092b24: /* original 8553, guest PC 0x0c092b24 */
if(!s->budget--) { s->failed_pc=0x0c092b24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+6,2);
goto P_0c092b26;
P_0c092b26: /* original 8151, guest PC 0x0c092b26 */
if(!s->budget--) { s->failed_pc=0x0c092b26u; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c092b28;
P_0c092b28: /* original 6603, guest PC 0x0c092b28 */
if(!s->budget--) { s->failed_pc=0x0c092b28u; return 0; }
r[6]=r[0];
goto P_0c092b2a;
P_0c092b2a: /* original 6051, guest PC 0x0c092b2a */
if(!s->budget--) { s->failed_pc=0x0c092b2au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[0]=tmp;
goto P_0c092b2c;
P_0c092b2c: /* original c804, guest PC 0x0c092b2c */
if(!s->budget--) { s->failed_pc=0x0c092b2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c092b2e;
P_0c092b2e: /* original 890a, guest PC 0x0c092b2e */
if(!s->budget--) { s->failed_pc=0x0c092b2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092b46; }
goto P_0c092b30;
P_0c092b30: /* original 6051, guest PC 0x0c092b30 */
if(!s->budget--) { s->failed_pc=0x0c092b30u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[0]=tmp;
goto P_0c092b32;
P_0c092b32: /* original cb08, guest PC 0x0c092b32 */
if(!s->budget--) { s->failed_pc=0x0c092b32u; return 0; }
r[0]|=8u;
goto P_0c092b34;
P_0c092b34: /* original 2501, guest PC 0x0c092b34 */
if(!s->budget--) { s->failed_pc=0x0c092b34u; return 0; }
write(ram,r[5],r[0],2);
goto P_0c092b36;
P_0c092b36: /* original 9015, guest PC 0x0c092b36 */
if(!s->budget--) { s->failed_pc=0x0c092b36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092b64u,2);
goto P_0c092b38;
P_0c092b38: /* original 024e, guest PC 0x0c092b38 */
if(!s->budget--) { s->failed_pc=0x0c092b38u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c092b3a;
P_0c092b3a: /* original 2228, guest PC 0x0c092b3a */
if(!s->budget--) { s->failed_pc=0x0c092b3au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c092b3c;
P_0c092b3c: /* original 8903, guest PC 0x0c092b3c */
if(!s->budget--) { s->failed_pc=0x0c092b3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092b46; }
goto P_0c092b3e;
P_0c092b3e: /* original 6251, guest PC 0x0c092b3e */
if(!s->budget--) { s->failed_pc=0x0c092b3eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c092b40;
P_0c092b40: /* original e3f7, guest PC 0x0c092b40 */
if(!s->budget--) { s->failed_pc=0x0c092b40u; return 0; }
r[3]=0xfffffff7u;
goto P_0c092b42;
P_0c092b42: /* original 2239, guest PC 0x0c092b42 */
if(!s->budget--) { s->failed_pc=0x0c092b42u; return 0; }
r[2]&=r[3];
goto P_0c092b44;
P_0c092b44: /* original 2521, guest PC 0x0c092b44 */
if(!s->budget--) { s->failed_pc=0x0c092b44u; return 0; }
write(ram,r[5],r[2],2);
goto P_0c092b46;
P_0c092b46: /* original 000b, guest PC 0x0c092b46 */
if(!s->budget--) { s->failed_pc=0x0c092b46u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c092b48: /* original 6063, guest PC 0x0c092b48 */
if(!s->budget--) { s->failed_pc=0x0c092b48u; return 0; }
r[0]=r[6];
goto P_0c092b4a;
P_0c092b4a: /* original 2fe6, guest PC 0x0c092b4a */
if(!s->budget--) { s->failed_pc=0x0c092b4au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092b4c;
P_0c092b4c: /* original 6e43, guest PC 0x0c092b4c */
if(!s->budget--) { s->failed_pc=0x0c092b4cu; return 0; }
r[14]=r[4];
goto P_0c092b4e;
P_0c092b4e: /* original 7fe8, guest PC 0x0c092b4e */
if(!s->budget--) { s->failed_pc=0x0c092b4eu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c092b50;
P_0c092b50: /* original 64e3, guest PC 0x0c092b50 */
if(!s->budget--) { s->failed_pc=0x0c092b50u; return 0; }
r[4]=r[14];
goto P_0c092b52;
P_0c092b52: /* original 2f52, guest PC 0x0c092b52 */
if(!s->budget--) { s->failed_pc=0x0c092b52u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c092b54;
P_0c092b54: /* original 7418, guest PC 0x0c092b54 */
if(!s->budget--) { s->failed_pc=0x0c092b54u; return 0; }
r[4]+=0x00000018u;
goto P_0c092b56;
P_0c092b56: /* original 1f62, guest PC 0x0c092b56 */
if(!s->budget--) { s->failed_pc=0x0c092b56u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c092b58;
P_0c092b58: /* original 1f71, guest PC 0x0c092b58 */
if(!s->budget--) { s->failed_pc=0x0c092b58u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c092b5a;
P_0c092b5a: /* original 55f7, guest PC 0x0c092b5a */
if(!s->budget--) { s->failed_pc=0x0c092b5au; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c092b5c;
P_0c092b5c: /* original 56f8, guest PC 0x0c092b5c */
if(!s->budget--) { s->failed_pc=0x0c092b5cu; return 0; }
r[6]=read(ram,r[15]+32,4);
goto P_0c092b5e;
P_0c092b5e: /* original a009, guest PC 0x0c092b5e */
if(!s->budget--) { s->failed_pc=0x0c092b5eu; return 0; }
goto P_0c092b74;
P_0c092b60: /* original 0009, guest PC 0x0c092b60 */
if(!s->budget--) { s->failed_pc=0x0c092b60u; return 0; }
if(!vf3_matrix_family(0x0c092b62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092b62u; return 0; } return 1;
P_0c092b74: /* original f059, guest PC 0x0c092b74 */
if(!s->budget--) { s->failed_pc=0x0c092b74u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092b76;
P_0c092b76: /* original f369, guest PC 0x0c092b76 */
if(!s->budget--) { s->failed_pc=0x0c092b76u; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c092b78;
P_0c092b78: /* original f159, guest PC 0x0c092b78 */
if(!s->budget--) { s->failed_pc=0x0c092b78u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092b7a;
P_0c092b7a: /* original f469, guest PC 0x0c092b7a */
if(!s->budget--) { s->failed_pc=0x0c092b7au; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c092b7c;
P_0c092b7c: /* original f031, guest PC 0x0c092b7c */
if(!s->budget--) { s->failed_pc=0x0c092b7cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c092b7e;
P_0c092b7e: /* original f258, guest PC 0x0c092b7e */
if(!s->budget--) { s->failed_pc=0x0c092b7eu; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c092b80;
P_0c092b80: /* original f568, guest PC 0x0c092b80 */
if(!s->budget--) { s->failed_pc=0x0c092b80u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c092b82;
P_0c092b82: /* original f141, guest PC 0x0c092b82 */
if(!s->budget--) { s->failed_pc=0x0c092b82u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c092b84;
P_0c092b84: /* original f251, guest PC 0x0c092b84 */
if(!s->budget--) { s->failed_pc=0x0c092b84u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c092b86;
P_0c092b86: /* original 7408, guest PC 0x0c092b86 */
if(!s->budget--) { s->failed_pc=0x0c092b86u; return 0; }
r[4]+=0x00000008u;
goto P_0c092b88;
P_0c092b88: /* original f42a, guest PC 0x0c092b88 */
if(!s->budget--) { s->failed_pc=0x0c092b88u; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092b8a;
P_0c092b8a: /* original f41b, guest PC 0x0c092b8a */
if(!s->budget--) { s->failed_pc=0x0c092b8au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092b8c;
P_0c092b8c: /* original f40b, guest PC 0x0c092b8c */
if(!s->budget--) { s->failed_pc=0x0c092b8cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092b8e;
P_0c092b8e: /* original 0009, guest PC 0x0c092b8e */
if(!s->budget--) { s->failed_pc=0x0c092b8eu; return 0; }
goto P_0c092b90;
P_0c092b90: /* original 52f2, guest PC 0x0c092b90 */
if(!s->budget--) { s->failed_pc=0x0c092b90u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c092b92;
P_0c092b92: /* original 51fa, guest PC 0x0c092b92 */
if(!s->budget--) { s->failed_pc=0x0c092b92u; return 0; }
r[1]=read(ram,r[15]+40,4);
goto P_0c092b94;
P_0c092b94: /* original 930b, guest PC 0x0c092b94 */
if(!s->budget--) { s->failed_pc=0x0c092b94u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092baeu,2);
goto P_0c092b96;
P_0c092b96: /* original f428, guest PC 0x0c092b96 */
if(!s->budget--) { s->failed_pc=0x0c092b96u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
goto P_0c092b98;
P_0c092b98: /* original 2138, guest PC 0x0c092b98 */
if(!s->budget--) { s->failed_pc=0x0c092b98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c092b9a;
P_0c092b9a: /* original 8d03, guest PC 0x0c092b9a */
if(!s->budget--) { s->failed_pc=0x0c092b9au; return 0; }
cond=r[17]&1u;
r[5]=r[14];
if(cond) { goto P_0c092ba4; }
goto P_0c092b9e;
P_0c092b9c: /* original 65e3, guest PC 0x0c092b9c */
if(!s->budget--) { s->failed_pc=0x0c092b9cu; return 0; }
r[5]=r[14];
goto P_0c092b9e;
P_0c092b9e: /* original c704, guest PC 0x0c092b9e */
if(!s->budget--) { s->failed_pc=0x0c092b9eu; return 0; }
r[0]=code_base|0x00092bb0u;
goto P_0c092ba0;
P_0c092ba0: /* original f308, guest PC 0x0c092ba0 */
if(!s->budget--) { s->failed_pc=0x0c092ba0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c092ba2;
P_0c092ba2: /* original f432, guest PC 0x0c092ba2 */
if(!s->budget--) { s->failed_pc=0x0c092ba2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c092ba4;
P_0c092ba4: /* original 64e3, guest PC 0x0c092ba4 */
if(!s->budget--) { s->failed_pc=0x0c092ba4u; return 0; }
r[4]=r[14];
goto P_0c092ba6;
P_0c092ba6: /* original 7418, guest PC 0x0c092ba6 */
if(!s->budget--) { s->failed_pc=0x0c092ba6u; return 0; }
r[4]+=0x00000018u;
goto P_0c092ba8;
P_0c092ba8: /* original 7518, guest PC 0x0c092ba8 */
if(!s->budget--) { s->failed_pc=0x0c092ba8u; return 0; }
r[5]+=0x00000018u;
goto P_0c092baa;
P_0c092baa: /* original a003, guest PC 0x0c092baa */
if(!s->budget--) { s->failed_pc=0x0c092baau; return 0; }
goto P_0c092bb4;
P_0c092bac: /* original 0009, guest PC 0x0c092bac */
if(!s->budget--) { s->failed_pc=0x0c092bacu; return 0; }
if(!vf3_matrix_family(0x0c092baeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092baeu; return 0; } return 1;
P_0c092bb4: /* original f059, guest PC 0x0c092bb4 */
if(!s->budget--) { s->failed_pc=0x0c092bb4u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092bb6;
P_0c092bb6: /* original f159, guest PC 0x0c092bb6 */
if(!s->budget--) { s->failed_pc=0x0c092bb6u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092bb8;
P_0c092bb8: /* original f259, guest PC 0x0c092bb8 */
if(!s->budget--) { s->failed_pc=0x0c092bb8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092bba;
P_0c092bba: /* original 740c, guest PC 0x0c092bba */
if(!s->budget--) { s->failed_pc=0x0c092bbau; return 0; }
r[4]+=0x0000000cu;
goto P_0c092bbc;
P_0c092bbc: /* original f242, guest PC 0x0c092bbc */
if(!s->budget--) { s->failed_pc=0x0c092bbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c092bbe;
P_0c092bbe: /* original f142, guest PC 0x0c092bbe */
if(!s->budget--) { s->failed_pc=0x0c092bbeu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c092bc0;
P_0c092bc0: /* original f042, guest PC 0x0c092bc0 */
if(!s->budget--) { s->failed_pc=0x0c092bc0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c092bc2;
P_0c092bc2: /* original f42b, guest PC 0x0c092bc2 */
if(!s->budget--) { s->failed_pc=0x0c092bc2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092bc4;
P_0c092bc4: /* original f41b, guest PC 0x0c092bc4 */
if(!s->budget--) { s->failed_pc=0x0c092bc4u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092bc6;
P_0c092bc6: /* original f40b, guest PC 0x0c092bc6 */
if(!s->budget--) { s->failed_pc=0x0c092bc6u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092bc8;
P_0c092bc8: /* original 50fa, guest PC 0x0c092bc8 */
if(!s->budget--) { s->failed_pc=0x0c092bc8u; return 0; }
r[0]=read(ram,r[15]+40,4);
goto P_0c092bca;
P_0c092bca: /* original c802, guest PC 0x0c092bca */
if(!s->budget--) { s->failed_pc=0x0c092bcau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c092bcc;
P_0c092bcc: /* original 8902, guest PC 0x0c092bcc */
if(!s->budget--) { s->failed_pc=0x0c092bccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092bd4; }
goto P_0c092bce;
P_0c092bce: /* original d30c, guest PC 0x0c092bce */
if(!s->budget--) { s->failed_pc=0x0c092bceu; return 0; }
r[3]=read(ram,0x0c092c00u,4);
goto P_0c092bd0;
P_0c092bd0: /* original 432b, guest PC 0x0c092bd0 */
if(!s->budget--) { s->failed_pc=0x0c092bd0u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c092c38u: goto P_0c092c38;
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
P_0c092bd2: /* original 0009, guest PC 0x0c092bd2 */
if(!s->budget--) { s->failed_pc=0x0c092bd2u; return 0; }
goto P_0c092bd4;
P_0c092bd4: /* original 52f1, guest PC 0x0c092bd4 */
if(!s->budget--) { s->failed_pc=0x0c092bd4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c092bd6;
P_0c092bd6: /* original e014, guest PC 0x0c092bd6 */
if(!s->budget--) { s->failed_pc=0x0c092bd6u; return 0; }
r[0]=0x00000014u;
goto P_0c092bd8;
P_0c092bd8: /* original f28d, guest PC 0x0c092bd8 */
if(!s->budget--) { s->failed_pc=0x0c092bd8u; return 0; }
fr[2]=0;
goto P_0c092bda;
P_0c092bda: /* original f426, guest PC 0x0c092bda */
if(!s->budget--) { s->failed_pc=0x0c092bdau; return 0; }
vf3_matrix_load(s,ram,4,r[2]+r[0]);
goto P_0c092bdc;
P_0c092bdc: /* original f34c, guest PC 0x0c092bdc */
if(!s->budget--) { s->failed_pc=0x0c092bdcu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c092bde;
P_0c092bde: /* original f430, guest PC 0x0c092bde */
if(!s->budget--) { s->failed_pc=0x0c092bdeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c092be0;
P_0c092be0: /* original f424, guest PC 0x0c092be0 */
if(!s->budget--) { s->failed_pc=0x0c092be0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[2]))!=0);
goto P_0c092be2;
P_0c092be2: /* original 8b02, guest PC 0x0c092be2 */
if(!s->budget--) { s->failed_pc=0x0c092be2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092bea; }
goto P_0c092be4;
P_0c092be4: /* original d306, guest PC 0x0c092be4 */
if(!s->budget--) { s->failed_pc=0x0c092be4u; return 0; }
r[3]=read(ram,0x0c092c00u,4);
goto P_0c092be6;
P_0c092be6: /* original 432b, guest PC 0x0c092be6 */
if(!s->budget--) { s->failed_pc=0x0c092be6u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c092c38u: goto P_0c092c38;
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
P_0c092be8: /* original 0009, guest PC 0x0c092be8 */
if(!s->budget--) { s->failed_pc=0x0c092be8u; return 0; }
goto P_0c092bea;
P_0c092bea: /* original 61f2, guest PC 0x0c092bea */
if(!s->budget--) { s->failed_pc=0x0c092beau; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c092bec;
P_0c092bec: /* original 2118, guest PC 0x0c092bec */
if(!s->budget--) { s->failed_pc=0x0c092becu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c092bee;
P_0c092bee: /* original 8b02, guest PC 0x0c092bee */
if(!s->budget--) { s->failed_pc=0x0c092beeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092bf6; }
goto P_0c092bf0;
P_0c092bf0: /* original d103, guest PC 0x0c092bf0 */
if(!s->budget--) { s->failed_pc=0x0c092bf0u; return 0; }
r[1]=read(ram,0x0c092c00u,4);
goto P_0c092bf2;
P_0c092bf2: /* original 412b, guest PC 0x0c092bf2 */
if(!s->budget--) { s->failed_pc=0x0c092bf2u; return 0; }
target=r[1];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c092c38u: goto P_0c092c38;
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
P_0c092bf4: /* original 0009, guest PC 0x0c092bf4 */
if(!s->budget--) { s->failed_pc=0x0c092bf4u; return 0; }
goto P_0c092bf6;
P_0c092bf6: /* original 64f3, guest PC 0x0c092bf6 */
if(!s->budget--) { s->failed_pc=0x0c092bf6u; return 0; }
r[4]=r[15];
goto P_0c092bf8;
P_0c092bf8: /* original 55f9, guest PC 0x0c092bf8 */
if(!s->budget--) { s->failed_pc=0x0c092bf8u; return 0; }
r[5]=read(ram,r[15]+36,4);
goto P_0c092bfa;
P_0c092bfa: /* original 740c, guest PC 0x0c092bfa */
if(!s->budget--) { s->failed_pc=0x0c092bfau; return 0; }
r[4]+=0x0000000cu;
goto P_0c092bfc;
P_0c092bfc: /* original a002, guest PC 0x0c092bfc */
if(!s->budget--) { s->failed_pc=0x0c092bfcu; return 0; }
goto P_0c092c04;
P_0c092bfe: /* original 0009, guest PC 0x0c092bfe */
if(!s->budget--) { s->failed_pc=0x0c092bfeu; return 0; }
if(!vf3_matrix_family(0x0c092c00u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092c00u; return 0; } return 1;
P_0c092c04: /* original f059, guest PC 0x0c092c04 */
if(!s->budget--) { s->failed_pc=0x0c092c04u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c06;
P_0c092c06: /* original f159, guest PC 0x0c092c06 */
if(!s->budget--) { s->failed_pc=0x0c092c06u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c08;
P_0c092c08: /* original f259, guest PC 0x0c092c08 */
if(!s->budget--) { s->failed_pc=0x0c092c08u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c0a;
P_0c092c0a: /* original 740c, guest PC 0x0c092c0a */
if(!s->budget--) { s->failed_pc=0x0c092c0au; return 0; }
r[4]+=0x0000000cu;
goto P_0c092c0c;
P_0c092c0c: /* original f242, guest PC 0x0c092c0c */
if(!s->budget--) { s->failed_pc=0x0c092c0cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c092c0e;
P_0c092c0e: /* original f142, guest PC 0x0c092c0e */
if(!s->budget--) { s->failed_pc=0x0c092c0eu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c092c10;
P_0c092c10: /* original f042, guest PC 0x0c092c10 */
if(!s->budget--) { s->failed_pc=0x0c092c10u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c092c12;
P_0c092c12: /* original f42b, guest PC 0x0c092c12 */
if(!s->budget--) { s->failed_pc=0x0c092c12u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092c14;
P_0c092c14: /* original f41b, guest PC 0x0c092c14 */
if(!s->budget--) { s->failed_pc=0x0c092c14u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092c16;
P_0c092c16: /* original f40b, guest PC 0x0c092c16 */
if(!s->budget--) { s->failed_pc=0x0c092c16u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092c18;
P_0c092c18: /* original 64f2, guest PC 0x0c092c18 */
if(!s->budget--) { s->failed_pc=0x0c092c18u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c092c1a;
P_0c092c1a: /* original 65f3, guest PC 0x0c092c1a */
if(!s->budget--) { s->failed_pc=0x0c092c1au; return 0; }
r[5]=r[15];
goto P_0c092c1c;
P_0c092c1c: /* original 750c, guest PC 0x0c092c1c */
if(!s->budget--) { s->failed_pc=0x0c092c1cu; return 0; }
r[5]+=0x0000000cu;
goto P_0c092c1e;
P_0c092c1e: /* original 7418, guest PC 0x0c092c1e */
if(!s->budget--) { s->failed_pc=0x0c092c1eu; return 0; }
r[4]+=0x00000018u;
goto P_0c092c20;
P_0c092c20: /* original f049, guest PC 0x0c092c20 */
if(!s->budget--) { s->failed_pc=0x0c092c20u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092c22;
P_0c092c22: /* original f359, guest PC 0x0c092c22 */
if(!s->budget--) { s->failed_pc=0x0c092c22u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c24;
P_0c092c24: /* original f149, guest PC 0x0c092c24 */
if(!s->budget--) { s->failed_pc=0x0c092c24u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092c26;
P_0c092c26: /* original f459, guest PC 0x0c092c26 */
if(!s->budget--) { s->failed_pc=0x0c092c26u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c28;
P_0c092c28: /* original f249, guest PC 0x0c092c28 */
if(!s->budget--) { s->failed_pc=0x0c092c28u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c092c2a;
P_0c092c2a: /* original f559, guest PC 0x0c092c2a */
if(!s->budget--) { s->failed_pc=0x0c092c2au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c092c2c;
P_0c092c2c: /* original f030, guest PC 0x0c092c2c */
if(!s->budget--) { s->failed_pc=0x0c092c2cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c092c2e;
P_0c092c2e: /* original f250, guest PC 0x0c092c2e */
if(!s->budget--) { s->failed_pc=0x0c092c2eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c092c30;
P_0c092c30: /* original f140, guest PC 0x0c092c30 */
if(!s->budget--) { s->failed_pc=0x0c092c30u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c092c32;
P_0c092c32: /* original f42b, guest PC 0x0c092c32 */
if(!s->budget--) { s->failed_pc=0x0c092c32u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c092c34;
P_0c092c34: /* original f41b, guest PC 0x0c092c34 */
if(!s->budget--) { s->failed_pc=0x0c092c34u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c092c36;
P_0c092c36: /* original f40b, guest PC 0x0c092c36 */
if(!s->budget--) { s->failed_pc=0x0c092c36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092c38;
P_0c092c38: /* original 7f18, guest PC 0x0c092c38 */
if(!s->budget--) { s->failed_pc=0x0c092c38u; return 0; }
r[15]+=0x00000018u;
goto P_0c092c3a;
P_0c092c3a: /* original 000b, guest PC 0x0c092c3a */
if(!s->budget--) { s->failed_pc=0x0c092c3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092c3c: /* original 6ef6, guest PC 0x0c092c3c */
if(!s->budget--) { s->failed_pc=0x0c092c3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c092c3e;
P_0c092c3e: /* original 2fe6, guest PC 0x0c092c3e */
if(!s->budget--) { s->failed_pc=0x0c092c3eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092c40;
P_0c092c40: /* original 2fd6, guest PC 0x0c092c40 */
if(!s->budget--) { s->failed_pc=0x0c092c40u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092c42;
P_0c092c42: /* original 2fc6, guest PC 0x0c092c42 */
if(!s->budget--) { s->failed_pc=0x0c092c42u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092c44;
P_0c092c44: /* original 6c63, guest PC 0x0c092c44 */
if(!s->budget--) { s->failed_pc=0x0c092c44u; return 0; }
r[12]=r[6];
goto P_0c092c46;
P_0c092c46: /* original 2fb6, guest PC 0x0c092c46 */
if(!s->budget--) { s->failed_pc=0x0c092c46u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092c48;
P_0c092c48: /* original 2fa6, guest PC 0x0c092c48 */
if(!s->budget--) { s->failed_pc=0x0c092c48u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c092c4a;
P_0c092c4a: /* original fffb, guest PC 0x0c092c4a */
if(!s->budget--) { s->failed_pc=0x0c092c4au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c092c4c;
P_0c092c4c: /* original 4f22, guest PC 0x0c092c4c */
if(!s->budget--) { s->failed_pc=0x0c092c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c092c4e;
P_0c092c4e: /* original db54, guest PC 0x0c092c4e */
if(!s->budget--) { s->failed_pc=0x0c092c4eu; return 0; }
r[11]=read(ram,0x0c092da0u,4);
goto P_0c092c50;
P_0c092c50: /* original 7ff0, guest PC 0x0c092c50 */
if(!s->budget--) { s->failed_pc=0x0c092c50u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c092c52;
P_0c092c52: /* original 50fc, guest PC 0x0c092c52 */
if(!s->budget--) { s->failed_pc=0x0c092c52u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c092c54;
P_0c092c54: /* original 5dfb, guest PC 0x0c092c54 */
if(!s->budget--) { s->failed_pc=0x0c092c54u; return 0; }
r[13]=read(ram,r[15]+44,4);
goto P_0c092c56;
P_0c092c56: /* original c810, guest PC 0x0c092c56 */
if(!s->budget--) { s->failed_pc=0x0c092c56u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c092c58;
P_0c092c58: /* original 8f2b, guest PC 0x0c092c58 */
if(!s->budget--) { s->failed_pc=0x0c092c58u; return 0; }
cond=r[17]&1u;
r[14]=r[7];
if(!cond) { goto P_0c092cb2; }
goto P_0c092c5c;
P_0c092c5a: /* original 6e73, guest PC 0x0c092c5a */
if(!s->budget--) { s->failed_pc=0x0c092c5au; return 0; }
r[14]=r[7];
goto P_0c092c5c;
P_0c092c5c: /* original 52fc, guest PC 0x0c092c5c */
if(!s->budget--) { s->failed_pc=0x0c092c5cu; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c092c5e;
P_0c092c5e: /* original 939a, guest PC 0x0c092c5e */
if(!s->budget--) { s->failed_pc=0x0c092c5eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092d96u,2);
goto P_0c092c60;
P_0c092c60: /* original 2238, guest PC 0x0c092c60 */
if(!s->budget--) { s->failed_pc=0x0c092c60u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c092c62;
P_0c092c62: /* original 8b01, guest PC 0x0c092c62 */
if(!s->budget--) { s->failed_pc=0x0c092c62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092c68; }
goto P_0c092c64;
P_0c092c64: /* original a0ed, guest PC 0x0c092c64 */
if(!s->budget--) { s->failed_pc=0x0c092c64u; return 0; }
goto P_0c092e42;
P_0c092c66: /* original 0009, guest PC 0x0c092c66 */
if(!s->budget--) { s->failed_pc=0x0c092c66u; return 0; }
goto P_0c092c68;
P_0c092c68: /* original e004, guest PC 0x0c092c68 */
if(!s->budget--) { s->failed_pc=0x0c092c68u; return 0; }
r[0]=0x00000004u;
goto P_0c092c6a;
P_0c092c6a: /* original f2d6, guest PC 0x0c092c6a */
if(!s->budget--) { s->failed_pc=0x0c092c6au; return 0; }
vf3_matrix_load(s,ram,2,r[13]+r[0]);
goto P_0c092c6c;
P_0c092c6c: /* original f3e6, guest PC 0x0c092c6c */
if(!s->budget--) { s->failed_pc=0x0c092c6cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c092c6e;
P_0c092c6e: /* original e028, guest PC 0x0c092c6e */
if(!s->budget--) { s->failed_pc=0x0c092c6eu; return 0; }
r[0]=0x00000028u;
goto P_0c092c70;
P_0c092c70: /* original ffc6, guest PC 0x0c092c70 */
if(!s->budget--) { s->failed_pc=0x0c092c70u; return 0; }
vf3_matrix_load(s,ram,15,r[12]+r[0]);
goto P_0c092c72;
P_0c092c72: /* original c74c, guest PC 0x0c092c72 */
if(!s->budget--) { s->failed_pc=0x0c092c72u; return 0; }
r[0]=code_base|0x00092da4u;
goto P_0c092c74;
P_0c092c74: /* original f231, guest PC 0x0c092c74 */
if(!s->budget--) { s->failed_pc=0x0c092c74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c092c76;
P_0c092c76: /* original f408, guest PC 0x0c092c76 */
if(!s->budget--) { s->failed_pc=0x0c092c76u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c092c78;
P_0c092c78: /* original ff22, guest PC 0x0c092c78 */
if(!s->budget--) { s->failed_pc=0x0c092c78u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[2],r[18],'*');
goto P_0c092c7a;
P_0c092c7a: /* original ff45, guest PC 0x0c092c7a */
if(!s->budget--) { s->failed_pc=0x0c092c7au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[4]))!=0);
goto P_0c092c7c;
P_0c092c7c: /* original 8b03, guest PC 0x0c092c7c */
if(!s->budget--) { s->failed_pc=0x0c092c7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092c86; }
goto P_0c092c7e;
P_0c092c7e: /* original 928b, guest PC 0x0c092c7e */
if(!s->budget--) { s->failed_pc=0x0c092c7eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092d98u,2);
goto P_0c092c80;
P_0c092c80: /* original e032, guest PC 0x0c092c80 */
if(!s->budget--) { s->failed_pc=0x0c092c80u; return 0; }
r[0]=0x00000032u;
goto P_0c092c82;
P_0c092c82: /* original a0de, guest PC 0x0c092c82 */
if(!s->budget--) { s->failed_pc=0x0c092c82u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c092e42;
P_0c092c84: /* original 0c25, guest PC 0x0c092c84 */
if(!s->budget--) { s->failed_pc=0x0c092c84u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c092c86;
P_0c092c86: /* original d248, guest PC 0x0c092c86 */
if(!s->budget--) { s->failed_pc=0x0c092c86u; return 0; }
r[2]=read(ram,0x0c092da8u,4);
goto P_0c092c88;
P_0c092c88: /* original f4fc, guest PC 0x0c092c88 */
if(!s->budget--) { s->failed_pc=0x0c092c88u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c092c8a;
P_0c092c8a: /* original 420b, guest PC 0x0c092c8a */
if(!s->budget--) { s->failed_pc=0x0c092c8au; return 0; }
target=r[2];
r[16]=code_base|0x0c092c8eu;
fr[4]^=0x80000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092c8eu) { target=s->pc; goto dispatch; }
goto P_0c092c8e;
P_0c092c8c: /* original f44d, guest PC 0x0c092c8c */
if(!s->budget--) { s->failed_pc=0x0c092c8cu; return 0; }
fr[4]^=0x80000000u;
goto P_0c092c8e;
P_0c092c8e: /* original e132, guest PC 0x0c092c8e */
if(!s->budget--) { s->failed_pc=0x0c092c8eu; return 0; }
r[1]=0x00000032u;
goto P_0c092c90;
P_0c092c90: /* original 600f, guest PC 0x0c092c90 */
if(!s->budget--) { s->failed_pc=0x0c092c90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092c92;
P_0c092c92: /* original 31cc, guest PC 0x0c092c92 */
if(!s->budget--) { s->failed_pc=0x0c092c92u; return 0; }
r[1]+=r[12];
goto P_0c092c94;
P_0c092c94: /* original 2101, guest PC 0x0c092c94 */
if(!s->budget--) { s->failed_pc=0x0c092c94u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c092c96;
P_0c092c96: /* original e008, guest PC 0x0c092c96 */
if(!s->budget--) { s->failed_pc=0x0c092c96u; return 0; }
r[0]=0x00000008u;
goto P_0c092c98;
P_0c092c98: /* original f3d8, guest PC 0x0c092c98 */
if(!s->budget--) { s->failed_pc=0x0c092c98u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092c9a;
P_0c092c9a: /* original f5e8, guest PC 0x0c092c9a */
if(!s->budget--) { s->failed_pc=0x0c092c9au; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c092c9c;
P_0c092c9c: /* original f4e6, guest PC 0x0c092c9c */
if(!s->budget--) { s->failed_pc=0x0c092c9cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092c9e;
P_0c092c9e: /* original f531, guest PC 0x0c092c9e */
if(!s->budget--) { s->failed_pc=0x0c092c9eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c092ca0;
P_0c092ca0: /* original f3d6, guest PC 0x0c092ca0 */
if(!s->budget--) { s->failed_pc=0x0c092ca0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092ca2;
P_0c092ca2: /* original 4b0b, guest PC 0x0c092ca2 */
if(!s->budget--) { s->failed_pc=0x0c092ca2u; return 0; }
target=r[11];
r[16]=code_base|0x0c092ca6u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092ca6u) { target=s->pc; goto dispatch; }
goto P_0c092ca6;
P_0c092ca4: /* original f431, guest PC 0x0c092ca4 */
if(!s->budget--) { s->failed_pc=0x0c092ca4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092ca6;
P_0c092ca6: /* original e130, guest PC 0x0c092ca6 */
if(!s->budget--) { s->failed_pc=0x0c092ca6u; return 0; }
r[1]=0x00000030u;
goto P_0c092ca8;
P_0c092ca8: /* original 31cc, guest PC 0x0c092ca8 */
if(!s->budget--) { s->failed_pc=0x0c092ca8u; return 0; }
r[1]+=r[12];
goto P_0c092caa;
P_0c092caa: /* original 600b, guest PC 0x0c092caa */
if(!s->budget--) { s->failed_pc=0x0c092caau; return 0; }
r[0]=0u-r[0];
goto P_0c092cac;
P_0c092cac: /* original 2101, guest PC 0x0c092cac */
if(!s->budget--) { s->failed_pc=0x0c092cacu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c092cae;
P_0c092cae: /* original a0c8, guest PC 0x0c092cae */
if(!s->budget--) { s->failed_pc=0x0c092caeu; return 0; }
goto P_0c092e42;
P_0c092cb0: /* original 0009, guest PC 0x0c092cb0 */
if(!s->budget--) { s->failed_pc=0x0c092cb0u; return 0; }
goto P_0c092cb2;
P_0c092cb2: /* original e061, guest PC 0x0c092cb2 */
if(!s->budget--) { s->failed_pc=0x0c092cb2u; return 0; }
r[0]=0x00000061u;
goto P_0c092cb4;
P_0c092cb4: /* original 055c, guest PC 0x0c092cb4 */
if(!s->budget--) { s->failed_pc=0x0c092cb4u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c092cb6;
P_0c092cb6: /* original 655c, guest PC 0x0c092cb6 */
if(!s->budget--) { s->failed_pc=0x0c092cb6u; return 0; }
r[5]=r[5]&255u;
goto P_0c092cb8;
P_0c092cb8: /* original 6053, guest PC 0x0c092cb8 */
if(!s->budget--) { s->failed_pc=0x0c092cb8u; return 0; }
r[0]=r[5];
goto P_0c092cba;
P_0c092cba: /* original 8802, guest PC 0x0c092cba */
if(!s->budget--) { s->failed_pc=0x0c092cbau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c092cbc;
P_0c092cbc: /* original 8934, guest PC 0x0c092cbc */
if(!s->budget--) { s->failed_pc=0x0c092cbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092d28; }
goto P_0c092cbe;
P_0c092cbe: /* original 6053, guest PC 0x0c092cbe */
if(!s->budget--) { s->failed_pc=0x0c092cbeu; return 0; }
r[0]=r[5];
goto P_0c092cc0;
P_0c092cc0: /* original 880a, guest PC 0x0c092cc0 */
if(!s->budget--) { s->failed_pc=0x0c092cc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c092cc2;
P_0c092cc2: /* original 8973, guest PC 0x0c092cc2 */
if(!s->budget--) { s->failed_pc=0x0c092cc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092dac; }
goto P_0c092cc4;
P_0c092cc4: /* original e05c, guest PC 0x0c092cc4 */
if(!s->budget--) { s->failed_pc=0x0c092cc4u; return 0; }
r[0]=0x0000005cu;
goto P_0c092cc6;
P_0c092cc6: /* original ff46, guest PC 0x0c092cc6 */
if(!s->budget--) { s->failed_pc=0x0c092cc6u; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c092cc8;
P_0c092cc8: /* original e060, guest PC 0x0c092cc8 */
if(!s->budget--) { s->failed_pc=0x0c092cc8u; return 0; }
r[0]=0x00000060u;
goto P_0c092cca;
P_0c092cca: /* original f346, guest PC 0x0c092cca */
if(!s->budget--) { s->failed_pc=0x0c092ccau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c092ccc;
P_0c092ccc: /* original e008, guest PC 0x0c092ccc */
if(!s->budget--) { s->failed_pc=0x0c092cccu; return 0; }
r[0]=0x00000008u;
goto P_0c092cce;
P_0c092cce: /* original ff37, guest PC 0x0c092cce */
if(!s->budget--) { s->failed_pc=0x0c092cceu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092cd0;
P_0c092cd0: /* original e064, guest PC 0x0c092cd0 */
if(!s->budget--) { s->failed_pc=0x0c092cd0u; return 0; }
r[0]=0x00000064u;
goto P_0c092cd2;
P_0c092cd2: /* original f446, guest PC 0x0c092cd2 */
if(!s->budget--) { s->failed_pc=0x0c092cd2u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c092cd4;
P_0c092cd4: /* original 4b0b, guest PC 0x0c092cd4 */
if(!s->budget--) { s->failed_pc=0x0c092cd4u; return 0; }
target=r[11];
r[16]=code_base|0x0c092cd8u;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092cd8u) { target=s->pc; goto dispatch; }
goto P_0c092cd8;
P_0c092cd6: /* original f5fc, guest PC 0x0c092cd6 */
if(!s->budget--) { s->failed_pc=0x0c092cd6u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c092cd8;
P_0c092cd8: /* original 600f, guest PC 0x0c092cd8 */
if(!s->budget--) { s->failed_pc=0x0c092cd8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092cda;
P_0c092cda: /* original 600b, guest PC 0x0c092cda */
if(!s->budget--) { s->failed_pc=0x0c092cdau; return 0; }
r[0]=0u-r[0];
goto P_0c092cdc;
P_0c092cdc: /* original 2f02, guest PC 0x0c092cdc */
if(!s->budget--) { s->failed_pc=0x0c092cdcu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c092cde;
P_0c092cde: /* original e008, guest PC 0x0c092cde */
if(!s->budget--) { s->failed_pc=0x0c092cdeu; return 0; }
r[0]=0x00000008u;
goto P_0c092ce0;
P_0c092ce0: /* original f3d8, guest PC 0x0c092ce0 */
if(!s->budget--) { s->failed_pc=0x0c092ce0u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092ce2;
P_0c092ce2: /* original f5e8, guest PC 0x0c092ce2 */
if(!s->budget--) { s->failed_pc=0x0c092ce2u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c092ce4;
P_0c092ce4: /* original f4e6, guest PC 0x0c092ce4 */
if(!s->budget--) { s->failed_pc=0x0c092ce4u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092ce6;
P_0c092ce6: /* original f531, guest PC 0x0c092ce6 */
if(!s->budget--) { s->failed_pc=0x0c092ce6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c092ce8;
P_0c092ce8: /* original f3d6, guest PC 0x0c092ce8 */
if(!s->budget--) { s->failed_pc=0x0c092ce8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092cea;
P_0c092cea: /* original 4b0b, guest PC 0x0c092cea */
if(!s->budget--) { s->failed_pc=0x0c092ceau; return 0; }
target=r[11];
r[16]=code_base|0x0c092ceeu;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092ceeu) { target=s->pc; goto dispatch; }
goto P_0c092cee;
P_0c092cec: /* original f431, guest PC 0x0c092cec */
if(!s->budget--) { s->failed_pc=0x0c092cecu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092cee;
P_0c092cee: /* original 63f2, guest PC 0x0c092cee */
if(!s->budget--) { s->failed_pc=0x0c092ceeu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092cf0;
P_0c092cf0: /* original 600f, guest PC 0x0c092cf0 */
if(!s->budget--) { s->failed_pc=0x0c092cf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092cf2;
P_0c092cf2: /* original 640b, guest PC 0x0c092cf2 */
if(!s->budget--) { s->failed_pc=0x0c092cf2u; return 0; }
r[4]=0u-r[0];
goto P_0c092cf4;
P_0c092cf4: /* original e030, guest PC 0x0c092cf4 */
if(!s->budget--) { s->failed_pc=0x0c092cf4u; return 0; }
r[0]=0x00000030u;
goto P_0c092cf6;
P_0c092cf6: /* original 3438, guest PC 0x0c092cf6 */
if(!s->budget--) { s->failed_pc=0x0c092cf6u; return 0; }
r[4]-=r[3];
goto P_0c092cf8;
P_0c092cf8: /* original 0c45, guest PC 0x0c092cf8 */
if(!s->budget--) { s->failed_pc=0x0c092cf8u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c092cfa;
P_0c092cfa: /* original e02e, guest PC 0x0c092cfa */
if(!s->budget--) { s->failed_pc=0x0c092cfau; return 0; }
r[0]=0x0000002eu;
goto P_0c092cfc;
P_0c092cfc: /* original 0c45, guest PC 0x0c092cfc */
if(!s->budget--) { s->failed_pc=0x0c092cfcu; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c092cfe;
P_0c092cfe: /* original e008, guest PC 0x0c092cfe */
if(!s->budget--) { s->failed_pc=0x0c092cfeu; return 0; }
r[0]=0x00000008u;
goto P_0c092d00;
P_0c092d00: /* original f5fc, guest PC 0x0c092d00 */
if(!s->budget--) { s->failed_pc=0x0c092d00u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c092d02;
P_0c092d02: /* original 4b0b, guest PC 0x0c092d02 */
if(!s->budget--) { s->failed_pc=0x0c092d02u; return 0; }
target=r[11];
r[16]=code_base|0x0c092d06u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092d06u) { target=s->pc; goto dispatch; }
goto P_0c092d06;
P_0c092d04: /* original f4f6, guest PC 0x0c092d04 */
if(!s->budget--) { s->failed_pc=0x0c092d04u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c092d06;
P_0c092d06: /* original 600f, guest PC 0x0c092d06 */
if(!s->budget--) { s->failed_pc=0x0c092d06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092d08;
P_0c092d08: /* original 600b, guest PC 0x0c092d08 */
if(!s->budget--) { s->failed_pc=0x0c092d08u; return 0; }
r[0]=0u-r[0];
goto P_0c092d0a;
P_0c092d0a: /* original 2f02, guest PC 0x0c092d0a */
if(!s->budget--) { s->failed_pc=0x0c092d0au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c092d0c;
P_0c092d0c: /* original e004, guest PC 0x0c092d0c */
if(!s->budget--) { s->failed_pc=0x0c092d0cu; return 0; }
r[0]=0x00000004u;
goto P_0c092d0e;
P_0c092d0e: /* original f3d8, guest PC 0x0c092d0e */
if(!s->budget--) { s->failed_pc=0x0c092d0eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092d10;
P_0c092d10: /* original f5e8, guest PC 0x0c092d10 */
if(!s->budget--) { s->failed_pc=0x0c092d10u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c092d12;
P_0c092d12: /* original f4e6, guest PC 0x0c092d12 */
if(!s->budget--) { s->failed_pc=0x0c092d12u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092d14;
P_0c092d14: /* original f531, guest PC 0x0c092d14 */
if(!s->budget--) { s->failed_pc=0x0c092d14u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c092d16;
P_0c092d16: /* original f3d6, guest PC 0x0c092d16 */
if(!s->budget--) { s->failed_pc=0x0c092d16u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092d18;
P_0c092d18: /* original 4b0b, guest PC 0x0c092d18 */
if(!s->budget--) { s->failed_pc=0x0c092d18u; return 0; }
target=r[11];
r[16]=code_base|0x0c092d1cu;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092d1cu) { target=s->pc; goto dispatch; }
goto P_0c092d1c;
P_0c092d1a: /* original f431, guest PC 0x0c092d1a */
if(!s->budget--) { s->failed_pc=0x0c092d1au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092d1c;
P_0c092d1c: /* original 63f2, guest PC 0x0c092d1c */
if(!s->budget--) { s->failed_pc=0x0c092d1cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092d1e;
P_0c092d1e: /* original 600f, guest PC 0x0c092d1e */
if(!s->budget--) { s->failed_pc=0x0c092d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092d20;
P_0c092d20: /* original 640b, guest PC 0x0c092d20 */
if(!s->budget--) { s->failed_pc=0x0c092d20u; return 0; }
r[4]=0u-r[0];
goto P_0c092d22;
P_0c092d22: /* original 3438, guest PC 0x0c092d22 */
if(!s->budget--) { s->failed_pc=0x0c092d22u; return 0; }
r[4]-=r[3];
goto P_0c092d24;
P_0c092d24: /* original a035, guest PC 0x0c092d24 */
if(!s->budget--) { s->failed_pc=0x0c092d24u; return 0; }
r[0]=0x00000032u;
goto P_0c092d92;
P_0c092d26: /* original e032, guest PC 0x0c092d26 */
if(!s->budget--) { s->failed_pc=0x0c092d26u; return 0; }
r[0]=0x00000032u;
goto P_0c092d28;
P_0c092d28: /* original e05c, guest PC 0x0c092d28 */
if(!s->budget--) { s->failed_pc=0x0c092d28u; return 0; }
r[0]=0x0000005cu;
goto P_0c092d2a;
P_0c092d2a: /* original ff46, guest PC 0x0c092d2a */
if(!s->budget--) { s->failed_pc=0x0c092d2au; return 0; }
vf3_matrix_load(s,ram,15,r[4]+r[0]);
goto P_0c092d2c;
P_0c092d2c: /* original e060, guest PC 0x0c092d2c */
if(!s->budget--) { s->failed_pc=0x0c092d2cu; return 0; }
r[0]=0x00000060u;
goto P_0c092d2e;
P_0c092d2e: /* original f346, guest PC 0x0c092d2e */
if(!s->budget--) { s->failed_pc=0x0c092d2eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c092d30;
P_0c092d30: /* original e00c, guest PC 0x0c092d30 */
if(!s->budget--) { s->failed_pc=0x0c092d30u; return 0; }
r[0]=0x0000000cu;
goto P_0c092d32;
P_0c092d32: /* original ff37, guest PC 0x0c092d32 */
if(!s->budget--) { s->failed_pc=0x0c092d32u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092d34;
P_0c092d34: /* original e064, guest PC 0x0c092d34 */
if(!s->budget--) { s->failed_pc=0x0c092d34u; return 0; }
r[0]=0x00000064u;
goto P_0c092d36;
P_0c092d36: /* original f446, guest PC 0x0c092d36 */
if(!s->budget--) { s->failed_pc=0x0c092d36u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c092d38;
P_0c092d38: /* original 4b0b, guest PC 0x0c092d38 */
if(!s->budget--) { s->failed_pc=0x0c092d38u; return 0; }
target=r[11];
r[16]=code_base|0x0c092d3cu;
vf3_matrix_move(s,5,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092d3cu) { target=s->pc; goto dispatch; }
goto P_0c092d3c;
P_0c092d3a: /* original f5fc, guest PC 0x0c092d3a */
if(!s->budget--) { s->failed_pc=0x0c092d3au; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c092d3c;
P_0c092d3c: /* original 600f, guest PC 0x0c092d3c */
if(!s->budget--) { s->failed_pc=0x0c092d3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092d3e;
P_0c092d3e: /* original 600b, guest PC 0x0c092d3e */
if(!s->budget--) { s->failed_pc=0x0c092d3eu; return 0; }
r[0]=0u-r[0];
goto P_0c092d40;
P_0c092d40: /* original 2f02, guest PC 0x0c092d40 */
if(!s->budget--) { s->failed_pc=0x0c092d40u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c092d42;
P_0c092d42: /* original e008, guest PC 0x0c092d42 */
if(!s->budget--) { s->failed_pc=0x0c092d42u; return 0; }
r[0]=0x00000008u;
goto P_0c092d44;
P_0c092d44: /* original f3d8, guest PC 0x0c092d44 */
if(!s->budget--) { s->failed_pc=0x0c092d44u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092d46;
P_0c092d46: /* original f5e8, guest PC 0x0c092d46 */
if(!s->budget--) { s->failed_pc=0x0c092d46u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c092d48;
P_0c092d48: /* original f4e6, guest PC 0x0c092d48 */
if(!s->budget--) { s->failed_pc=0x0c092d48u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092d4a;
P_0c092d4a: /* original f531, guest PC 0x0c092d4a */
if(!s->budget--) { s->failed_pc=0x0c092d4au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c092d4c;
P_0c092d4c: /* original f3d6, guest PC 0x0c092d4c */
if(!s->budget--) { s->failed_pc=0x0c092d4cu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092d4e;
P_0c092d4e: /* original 4b0b, guest PC 0x0c092d4e */
if(!s->budget--) { s->failed_pc=0x0c092d4eu; return 0; }
target=r[11];
r[16]=code_base|0x0c092d52u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092d52u) { target=s->pc; goto dispatch; }
goto P_0c092d52;
P_0c092d50: /* original f431, guest PC 0x0c092d50 */
if(!s->budget--) { s->failed_pc=0x0c092d50u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092d52;
P_0c092d52: /* original 63f2, guest PC 0x0c092d52 */
if(!s->budget--) { s->failed_pc=0x0c092d52u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092d54;
P_0c092d54: /* original 600f, guest PC 0x0c092d54 */
if(!s->budget--) { s->failed_pc=0x0c092d54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092d56;
P_0c092d56: /* original 9420, guest PC 0x0c092d56 */
if(!s->budget--) { s->failed_pc=0x0c092d56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092d9au,2);
goto P_0c092d58;
P_0c092d58: /* original 650b, guest PC 0x0c092d58 */
if(!s->budget--) { s->failed_pc=0x0c092d58u; return 0; }
r[5]=0u-r[0];
goto P_0c092d5a;
P_0c092d5a: /* original 3538, guest PC 0x0c092d5a */
if(!s->budget--) { s->failed_pc=0x0c092d5au; return 0; }
r[5]-=r[3];
goto P_0c092d5c;
P_0c092d5c: /* original e032, guest PC 0x0c092d5c */
if(!s->budget--) { s->failed_pc=0x0c092d5cu; return 0; }
r[0]=0x00000032u;
goto P_0c092d5e;
P_0c092d5e: /* original 354c, guest PC 0x0c092d5e */
if(!s->budget--) { s->failed_pc=0x0c092d5eu; return 0; }
r[5]+=r[4];
goto P_0c092d60;
P_0c092d60: /* original 0c55, guest PC 0x0c092d60 */
if(!s->budget--) { s->failed_pc=0x0c092d60u; return 0; }
write(ram,r[12]+r[0],r[5],2);
goto P_0c092d62;
P_0c092d62: /* original e02e, guest PC 0x0c092d62 */
if(!s->budget--) { s->failed_pc=0x0c092d62u; return 0; }
r[0]=0x0000002eu;
goto P_0c092d64;
P_0c092d64: /* original 0c45, guest PC 0x0c092d64 */
if(!s->budget--) { s->failed_pc=0x0c092d64u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c092d66;
P_0c092d66: /* original e00c, guest PC 0x0c092d66 */
if(!s->budget--) { s->failed_pc=0x0c092d66u; return 0; }
r[0]=0x0000000cu;
goto P_0c092d68;
P_0c092d68: /* original f5fc, guest PC 0x0c092d68 */
if(!s->budget--) { s->failed_pc=0x0c092d68u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c092d6a;
P_0c092d6a: /* original 4b0b, guest PC 0x0c092d6a */
if(!s->budget--) { s->failed_pc=0x0c092d6au; return 0; }
target=r[11];
r[16]=code_base|0x0c092d6eu;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092d6eu) { target=s->pc; goto dispatch; }
goto P_0c092d6e;
P_0c092d6c: /* original f4f6, guest PC 0x0c092d6c */
if(!s->budget--) { s->failed_pc=0x0c092d6cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c092d6e;
P_0c092d6e: /* original 600f, guest PC 0x0c092d6e */
if(!s->budget--) { s->failed_pc=0x0c092d6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092d70;
P_0c092d70: /* original 600b, guest PC 0x0c092d70 */
if(!s->budget--) { s->failed_pc=0x0c092d70u; return 0; }
r[0]=0u-r[0];
goto P_0c092d72;
P_0c092d72: /* original 2f02, guest PC 0x0c092d72 */
if(!s->budget--) { s->failed_pc=0x0c092d72u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c092d74;
P_0c092d74: /* original e004, guest PC 0x0c092d74 */
if(!s->budget--) { s->failed_pc=0x0c092d74u; return 0; }
r[0]=0x00000004u;
goto P_0c092d76;
P_0c092d76: /* original f3d8, guest PC 0x0c092d76 */
if(!s->budget--) { s->failed_pc=0x0c092d76u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092d78;
P_0c092d78: /* original f5e8, guest PC 0x0c092d78 */
if(!s->budget--) { s->failed_pc=0x0c092d78u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c092d7a;
P_0c092d7a: /* original f4e6, guest PC 0x0c092d7a */
if(!s->budget--) { s->failed_pc=0x0c092d7au; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092d7c;
P_0c092d7c: /* original f531, guest PC 0x0c092d7c */
if(!s->budget--) { s->failed_pc=0x0c092d7cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c092d7e;
P_0c092d7e: /* original f3d6, guest PC 0x0c092d7e */
if(!s->budget--) { s->failed_pc=0x0c092d7eu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092d80;
P_0c092d80: /* original 4b0b, guest PC 0x0c092d80 */
if(!s->budget--) { s->failed_pc=0x0c092d80u; return 0; }
target=r[11];
r[16]=code_base|0x0c092d84u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092d84u) { target=s->pc; goto dispatch; }
goto P_0c092d84;
P_0c092d82: /* original f431, guest PC 0x0c092d82 */
if(!s->budget--) { s->failed_pc=0x0c092d82u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092d84;
P_0c092d84: /* original 63f2, guest PC 0x0c092d84 */
if(!s->budget--) { s->failed_pc=0x0c092d84u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092d86;
P_0c092d86: /* original 600f, guest PC 0x0c092d86 */
if(!s->budget--) { s->failed_pc=0x0c092d86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092d88;
P_0c092d88: /* original 640b, guest PC 0x0c092d88 */
if(!s->budget--) { s->failed_pc=0x0c092d88u; return 0; }
r[4]=0u-r[0];
goto P_0c092d8a;
P_0c092d8a: /* original 3438, guest PC 0x0c092d8a */
if(!s->budget--) { s->failed_pc=0x0c092d8au; return 0; }
r[4]-=r[3];
goto P_0c092d8c;
P_0c092d8c: /* original 9306, guest PC 0x0c092d8c */
if(!s->budget--) { s->failed_pc=0x0c092d8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092d9cu,2);
goto P_0c092d8e;
P_0c092d8e: /* original e030, guest PC 0x0c092d8e */
if(!s->budget--) { s->failed_pc=0x0c092d8eu; return 0; }
r[0]=0x00000030u;
goto P_0c092d90;
P_0c092d90: /* original 343c, guest PC 0x0c092d90 */
if(!s->budget--) { s->failed_pc=0x0c092d90u; return 0; }
r[4]+=r[3];
goto P_0c092d92;
P_0c092d92: /* original a056, guest PC 0x0c092d92 */
if(!s->budget--) { s->failed_pc=0x0c092d92u; return 0; }
write(ram,r[12]+r[0],r[4],2);
goto P_0c092e42;
P_0c092d94: /* original 0c45, guest PC 0x0c092d94 */
if(!s->budget--) { s->failed_pc=0x0c092d94u; return 0; }
write(ram,r[12]+r[0],r[4],2);
if(!vf3_matrix_family(0x0c092d96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c092d96u; return 0; } return 1;
P_0c092dac: /* original e02e, guest PC 0x0c092dac */
if(!s->budget--) { s->failed_pc=0x0c092dacu; return 0; }
r[0]=0x0000002eu;
goto P_0c092dae;
P_0c092dae: /* original ea00, guest PC 0x0c092dae */
if(!s->budget--) { s->failed_pc=0x0c092daeu; return 0; }
r[10]=0x00000000u;
goto P_0c092db0;
P_0c092db0: /* original 0ca5, guest PC 0x0c092db0 */
if(!s->budget--) { s->failed_pc=0x0c092db0u; return 0; }
write(ram,r[12]+r[0],r[10],2);
goto P_0c092db2;
P_0c092db2: /* original e030, guest PC 0x0c092db2 */
if(!s->budget--) { s->failed_pc=0x0c092db2u; return 0; }
r[0]=0x00000030u;
goto P_0c092db4;
P_0c092db4: /* original 0ca5, guest PC 0x0c092db4 */
if(!s->budget--) { s->failed_pc=0x0c092db4u; return 0; }
write(ram,r[12]+r[0],r[10],2);
goto P_0c092db6;
P_0c092db6: /* original e05c, guest PC 0x0c092db6 */
if(!s->budget--) { s->failed_pc=0x0c092db6u; return 0; }
r[0]=0x0000005cu;
goto P_0c092db8;
P_0c092db8: /* original f546, guest PC 0x0c092db8 */
if(!s->budget--) { s->failed_pc=0x0c092db8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c092dba;
P_0c092dba: /* original e060, guest PC 0x0c092dba */
if(!s->budget--) { s->failed_pc=0x0c092dbau; return 0; }
r[0]=0x00000060u;
goto P_0c092dbc;
P_0c092dbc: /* original f346, guest PC 0x0c092dbc */
if(!s->budget--) { s->failed_pc=0x0c092dbcu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c092dbe;
P_0c092dbe: /* original e004, guest PC 0x0c092dbe */
if(!s->budget--) { s->failed_pc=0x0c092dbeu; return 0; }
r[0]=0x00000004u;
goto P_0c092dc0;
P_0c092dc0: /* original ff37, guest PC 0x0c092dc0 */
if(!s->budget--) { s->failed_pc=0x0c092dc0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c092dc2;
P_0c092dc2: /* original e064, guest PC 0x0c092dc2 */
if(!s->budget--) { s->failed_pc=0x0c092dc2u; return 0; }
r[0]=0x00000064u;
goto P_0c092dc4;
P_0c092dc4: /* original f35c, guest PC 0x0c092dc4 */
if(!s->budget--) { s->failed_pc=0x0c092dc4u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c092dc6;
P_0c092dc6: /* original f352, guest PC 0x0c092dc6 */
if(!s->budget--) { s->failed_pc=0x0c092dc6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c092dc8;
P_0c092dc8: /* original f446, guest PC 0x0c092dc8 */
if(!s->budget--) { s->failed_pc=0x0c092dc8u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c092dca;
P_0c092dca: /* original c734, guest PC 0x0c092dca */
if(!s->budget--) { s->failed_pc=0x0c092dcau; return 0; }
r[0]=code_base|0x00092e9cu;
goto P_0c092dcc;
P_0c092dcc: /* original f208, guest PC 0x0c092dcc */
if(!s->budget--) { s->failed_pc=0x0c092dccu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c092dce;
P_0c092dce: /* original f04c, guest PC 0x0c092dce */
if(!s->budget--) { s->failed_pc=0x0c092dceu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c092dd0;
P_0c092dd0: /* original f34e, guest PC 0x0c092dd0 */
if(!s->budget--) { s->failed_pc=0x0c092dd0u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c092dd2;
P_0c092dd2: /* original f235, guest PC 0x0c092dd2 */
if(!s->budget--) { s->failed_pc=0x0c092dd2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c092dd4;
P_0c092dd4: /* original 8f02, guest PC 0x0c092dd4 */
if(!s->budget--) { s->failed_pc=0x0c092dd4u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,3);
if(!cond) { goto P_0c092ddc; }
goto P_0c092dd8;
P_0c092dd6: /* original f63c, guest PC 0x0c092dd6 */
if(!s->budget--) { s->failed_pc=0x0c092dd6u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c092dd8;
P_0c092dd8: /* original a002, guest PC 0x0c092dd8 */
if(!s->budget--) { s->failed_pc=0x0c092dd8u; return 0; }
fr[5]=0;
goto P_0c092de0;
P_0c092dda: /* original f58d, guest PC 0x0c092dda */
if(!s->budget--) { s->failed_pc=0x0c092ddau; return 0; }
fr[5]=0;
goto P_0c092ddc;
P_0c092ddc: /* original f56c, guest PC 0x0c092ddc */
if(!s->budget--) { s->failed_pc=0x0c092ddcu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c092dde;
P_0c092dde: /* original f56d, guest PC 0x0c092dde */
if(!s->budget--) { s->failed_pc=0x0c092ddeu; return 0; }
fr[5]=vf3_fpu_sqrt(fr[5],r[18]);
goto P_0c092de0;
P_0c092de0: /* original e004, guest PC 0x0c092de0 */
if(!s->budget--) { s->failed_pc=0x0c092de0u; return 0; }
r[0]=0x00000004u;
goto P_0c092de2;
P_0c092de2: /* original 4b0b, guest PC 0x0c092de2 */
if(!s->budget--) { s->failed_pc=0x0c092de2u; return 0; }
target=r[11];
r[16]=code_base|0x0c092de6u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092de6u) { target=s->pc; goto dispatch; }
goto P_0c092de6;
P_0c092de4: /* original f4f6, guest PC 0x0c092de4 */
if(!s->budget--) { s->failed_pc=0x0c092de4u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c092de6;
P_0c092de6: /* original 600f, guest PC 0x0c092de6 */
if(!s->budget--) { s->failed_pc=0x0c092de6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092de8;
P_0c092de8: /* original 600b, guest PC 0x0c092de8 */
if(!s->budget--) { s->failed_pc=0x0c092de8u; return 0; }
r[0]=0u-r[0];
goto P_0c092dea;
P_0c092dea: /* original 2f02, guest PC 0x0c092dea */
if(!s->budget--) { s->failed_pc=0x0c092deau; return 0; }
write(ram,r[15],r[0],4);
goto P_0c092dec;
P_0c092dec: /* original e008, guest PC 0x0c092dec */
if(!s->budget--) { s->failed_pc=0x0c092decu; return 0; }
r[0]=0x00000008u;
goto P_0c092dee;
P_0c092dee: /* original f3d8, guest PC 0x0c092dee */
if(!s->budget--) { s->failed_pc=0x0c092deeu; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c092df0;
P_0c092df0: /* original f5e8, guest PC 0x0c092df0 */
if(!s->budget--) { s->failed_pc=0x0c092df0u; return 0; }
vf3_matrix_load(s,ram,5,r[14]);
goto P_0c092df2;
P_0c092df2: /* original f4e6, guest PC 0x0c092df2 */
if(!s->budget--) { s->failed_pc=0x0c092df2u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092df4;
P_0c092df4: /* original f531, guest PC 0x0c092df4 */
if(!s->budget--) { s->failed_pc=0x0c092df4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c092df6;
P_0c092df6: /* original f3d6, guest PC 0x0c092df6 */
if(!s->budget--) { s->failed_pc=0x0c092df6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092df8;
P_0c092df8: /* original c728, guest PC 0x0c092df8 */
if(!s->budget--) { s->failed_pc=0x0c092df8u; return 0; }
r[0]=code_base|0x00092e9cu;
goto P_0c092dfa;
P_0c092dfa: /* original f431, guest PC 0x0c092dfa */
if(!s->budget--) { s->failed_pc=0x0c092dfau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092dfc;
P_0c092dfc: /* original f208, guest PC 0x0c092dfc */
if(!s->budget--) { s->failed_pc=0x0c092dfcu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c092dfe;
P_0c092dfe: /* original f35c, guest PC 0x0c092dfe */
if(!s->budget--) { s->failed_pc=0x0c092dfeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c092e00;
P_0c092e00: /* original f352, guest PC 0x0c092e00 */
if(!s->budget--) { s->failed_pc=0x0c092e00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c092e02;
P_0c092e02: /* original f04c, guest PC 0x0c092e02 */
if(!s->budget--) { s->failed_pc=0x0c092e02u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c092e04;
P_0c092e04: /* original f34e, guest PC 0x0c092e04 */
if(!s->budget--) { s->failed_pc=0x0c092e04u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c092e06;
P_0c092e06: /* original f235, guest PC 0x0c092e06 */
if(!s->budget--) { s->failed_pc=0x0c092e06u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c092e08;
P_0c092e08: /* original 8f02, guest PC 0x0c092e08 */
if(!s->budget--) { s->failed_pc=0x0c092e08u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,3);
if(!cond) { goto P_0c092e10; }
goto P_0c092e0c;
P_0c092e0a: /* original f63c, guest PC 0x0c092e0a */
if(!s->budget--) { s->failed_pc=0x0c092e0au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c092e0c;
P_0c092e0c: /* original a002, guest PC 0x0c092e0c */
if(!s->budget--) { s->failed_pc=0x0c092e0cu; return 0; }
fr[5]=0;
goto P_0c092e14;
P_0c092e0e: /* original f58d, guest PC 0x0c092e0e */
if(!s->budget--) { s->failed_pc=0x0c092e0eu; return 0; }
fr[5]=0;
goto P_0c092e10;
P_0c092e10: /* original f56c, guest PC 0x0c092e10 */
if(!s->budget--) { s->failed_pc=0x0c092e10u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c092e12;
P_0c092e12: /* original f56d, guest PC 0x0c092e12 */
if(!s->budget--) { s->failed_pc=0x0c092e12u; return 0; }
fr[5]=vf3_fpu_sqrt(fr[5],r[18]);
goto P_0c092e14;
P_0c092e14: /* original e004, guest PC 0x0c092e14 */
if(!s->budget--) { s->failed_pc=0x0c092e14u; return 0; }
r[0]=0x00000004u;
goto P_0c092e16;
P_0c092e16: /* original f4e6, guest PC 0x0c092e16 */
if(!s->budget--) { s->failed_pc=0x0c092e16u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c092e18;
P_0c092e18: /* original f3d6, guest PC 0x0c092e18 */
if(!s->budget--) { s->failed_pc=0x0c092e18u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c092e1a;
P_0c092e1a: /* original 4b0b, guest PC 0x0c092e1a */
if(!s->budget--) { s->failed_pc=0x0c092e1au; return 0; }
target=r[11];
r[16]=code_base|0x0c092e1eu;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c092e1eu) { target=s->pc; goto dispatch; }
goto P_0c092e1e;
P_0c092e1c: /* original f431, guest PC 0x0c092e1c */
if(!s->budget--) { s->failed_pc=0x0c092e1cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c092e1e;
P_0c092e1e: /* original 63f2, guest PC 0x0c092e1e */
if(!s->budget--) { s->failed_pc=0x0c092e1eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c092e20;
P_0c092e20: /* original 600f, guest PC 0x0c092e20 */
if(!s->budget--) { s->failed_pc=0x0c092e20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c092e22;
P_0c092e22: /* original 9238, guest PC 0x0c092e22 */
if(!s->budget--) { s->failed_pc=0x0c092e22u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092e96u,2);
goto P_0c092e24;
P_0c092e24: /* original 640b, guest PC 0x0c092e24 */
if(!s->budget--) { s->failed_pc=0x0c092e24u; return 0; }
r[4]=0u-r[0];
goto P_0c092e26;
P_0c092e26: /* original 3438, guest PC 0x0c092e26 */
if(!s->budget--) { s->failed_pc=0x0c092e26u; return 0; }
r[4]-=r[3];
goto P_0c092e28;
P_0c092e28: /* original 342c, guest PC 0x0c092e28 */
if(!s->budget--) { s->failed_pc=0x0c092e28u; return 0; }
r[4]+=r[2];
goto P_0c092e2a;
P_0c092e2a: /* original 4415, guest PC 0x0c092e2a */
if(!s->budget--) { s->failed_pc=0x0c092e2au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c092e2c;
P_0c092e2c: /* original 8901, guest PC 0x0c092e2c */
if(!s->budget--) { s->failed_pc=0x0c092e2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c092e32; }
goto P_0c092e2e;
P_0c092e2e: /* original a004, guest PC 0x0c092e2e */
if(!s->budget--) { s->failed_pc=0x0c092e2eu; return 0; }
r[4]=r[10];
goto P_0c092e3a;
P_0c092e30: /* original 64a3, guest PC 0x0c092e30 */
if(!s->budget--) { s->failed_pc=0x0c092e30u; return 0; }
r[4]=r[10];
goto P_0c092e32;
P_0c092e32: /* original 9531, guest PC 0x0c092e32 */
if(!s->budget--) { s->failed_pc=0x0c092e32u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092e98u,2);
goto P_0c092e34;
P_0c092e34: /* original 3457, guest PC 0x0c092e34 */
if(!s->budget--) { s->failed_pc=0x0c092e34u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c092e36;
P_0c092e36: /* original 8b00, guest PC 0x0c092e36 */
if(!s->budget--) { s->failed_pc=0x0c092e36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c092e3a; }
goto P_0c092e38;
P_0c092e38: /* original 6453, guest PC 0x0c092e38 */
if(!s->budget--) { s->failed_pc=0x0c092e38u; return 0; }
r[4]=r[5];
goto P_0c092e3a;
P_0c092e3a: /* original 932e, guest PC 0x0c092e3a */
if(!s->budget--) { s->failed_pc=0x0c092e3au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c092e9au,2);
goto P_0c092e3c;
P_0c092e3c: /* original e032, guest PC 0x0c092e3c */
if(!s->budget--) { s->failed_pc=0x0c092e3cu; return 0; }
r[0]=0x00000032u;
goto P_0c092e3e;
P_0c092e3e: /* original 3348, guest PC 0x0c092e3e */
if(!s->budget--) { s->failed_pc=0x0c092e3eu; return 0; }
r[3]-=r[4];
goto P_0c092e40;
P_0c092e40: /* original 0c35, guest PC 0x0c092e40 */
if(!s->budget--) { s->failed_pc=0x0c092e40u; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c092e42;
P_0c092e42: /* original 7f10, guest PC 0x0c092e42 */
if(!s->budget--) { s->failed_pc=0x0c092e42u; return 0; }
r[15]+=0x00000010u;
goto P_0c092e44;
P_0c092e44: /* original 4f26, guest PC 0x0c092e44 */
if(!s->budget--) { s->failed_pc=0x0c092e44u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c092e46;
P_0c092e46: /* original fff9, guest PC 0x0c092e46 */
if(!s->budget--) { s->failed_pc=0x0c092e46u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c092e48;
P_0c092e48: /* original 6af6, guest PC 0x0c092e48 */
if(!s->budget--) { s->failed_pc=0x0c092e48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c092e4a;
P_0c092e4a: /* original 6bf6, guest PC 0x0c092e4a */
if(!s->budget--) { s->failed_pc=0x0c092e4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c092e4c;
P_0c092e4c: /* original 6cf6, guest PC 0x0c092e4c */
if(!s->budget--) { s->failed_pc=0x0c092e4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c092e4e;
P_0c092e4e: /* original 6df6, guest PC 0x0c092e4e */
if(!s->budget--) { s->failed_pc=0x0c092e4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c092e50;
P_0c092e50: /* original 000b, guest PC 0x0c092e50 */
if(!s->budget--) { s->failed_pc=0x0c092e50u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092e52: /* original 6ef6, guest PC 0x0c092e52 */
if(!s->budget--) { s->failed_pc=0x0c092e52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c092e54u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
