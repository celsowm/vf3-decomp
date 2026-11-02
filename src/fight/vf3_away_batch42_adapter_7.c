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
int vf3_away_batch42_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c073aacu: goto P_0c073aac;
case 0x0c073aaeu: goto P_0c073aae;
case 0x0c073ab0u: goto P_0c073ab0;
case 0x0c073ab2u: goto P_0c073ab2;
case 0x0c073ab4u: goto P_0c073ab4;
case 0x0c073ab6u: goto P_0c073ab6;
case 0x0c073ab8u: goto P_0c073ab8;
case 0x0c073abau: goto P_0c073aba;
case 0x0c073abcu: goto P_0c073abc;
case 0x0c073abeu: goto P_0c073abe;
case 0x0c073ac0u: goto P_0c073ac0;
case 0x0c073ac2u: goto P_0c073ac2;
case 0x0c073ac4u: goto P_0c073ac4;
case 0x0c073ac6u: goto P_0c073ac6;
case 0x0c073ac8u: goto P_0c073ac8;
case 0x0c073acau: goto P_0c073aca;
case 0x0c073accu: goto P_0c073acc;
case 0x0c073aceu: goto P_0c073ace;
case 0x0c073ad0u: goto P_0c073ad0;
case 0x0c073ad2u: goto P_0c073ad2;
case 0x0c073ad4u: goto P_0c073ad4;
case 0x0c073ad6u: goto P_0c073ad6;
case 0x0c073ad8u: goto P_0c073ad8;
case 0x0c073adau: goto P_0c073ada;
case 0x0c073adcu: goto P_0c073adc;
case 0x0c073adeu: goto P_0c073ade;
case 0x0c073ae0u: goto P_0c073ae0;
case 0x0c073ae2u: goto P_0c073ae2;
case 0x0c073ae4u: goto P_0c073ae4;
case 0x0c073ae6u: goto P_0c073ae6;
case 0x0c073ae8u: goto P_0c073ae8;
case 0x0c073aeau: goto P_0c073aea;
case 0x0c073aecu: goto P_0c073aec;
case 0x0c073aeeu: goto P_0c073aee;
case 0x0c073af0u: goto P_0c073af0;
case 0x0c073af2u: goto P_0c073af2;
case 0x0c073af4u: goto P_0c073af4;
case 0x0c073af6u: goto P_0c073af6;
case 0x0c073af8u: goto P_0c073af8;
case 0x0c073afau: goto P_0c073afa;
case 0x0c073afcu: goto P_0c073afc;
case 0x0c073afeu: goto P_0c073afe;
case 0x0c073b00u: goto P_0c073b00;
case 0x0c073b02u: goto P_0c073b02;
case 0x0c073b04u: goto P_0c073b04;
case 0x0c073b06u: goto P_0c073b06;
case 0x0c073b08u: goto P_0c073b08;
case 0x0c073b0au: goto P_0c073b0a;
case 0x0c073b0cu: goto P_0c073b0c;
case 0x0c073b0eu: goto P_0c073b0e;
case 0x0c073b10u: goto P_0c073b10;
case 0x0c073b12u: goto P_0c073b12;
case 0x0c073b14u: goto P_0c073b14;
case 0x0c073b16u: goto P_0c073b16;
case 0x0c073b18u: goto P_0c073b18;
case 0x0c073b1au: goto P_0c073b1a;
case 0x0c073b1cu: goto P_0c073b1c;
case 0x0c073b1eu: goto P_0c073b1e;
case 0x0c073b20u: goto P_0c073b20;
case 0x0c073b22u: goto P_0c073b22;
case 0x0c073b24u: goto P_0c073b24;
case 0x0c073b26u: goto P_0c073b26;
case 0x0c073b28u: goto P_0c073b28;
case 0x0c073b2au: goto P_0c073b2a;
case 0x0c073b2cu: goto P_0c073b2c;
case 0x0c073b2eu: goto P_0c073b2e;
case 0x0c073b30u: goto P_0c073b30;
case 0x0c073b32u: goto P_0c073b32;
case 0x0c073b34u: goto P_0c073b34;
case 0x0c073b36u: goto P_0c073b36;
case 0x0c073b38u: goto P_0c073b38;
case 0x0c073b3au: goto P_0c073b3a;
case 0x0c073b3cu: goto P_0c073b3c;
case 0x0c073b3eu: goto P_0c073b3e;
case 0x0c073b40u: goto P_0c073b40;
case 0x0c073b42u: goto P_0c073b42;
case 0x0c073b44u: goto P_0c073b44;
case 0x0c073b46u: goto P_0c073b46;
case 0x0c073b48u: goto P_0c073b48;
case 0x0c073b4au: goto P_0c073b4a;
case 0x0c073b4cu: goto P_0c073b4c;
case 0x0c073b4eu: goto P_0c073b4e;
case 0x0c073b50u: goto P_0c073b50;
case 0x0c073b52u: goto P_0c073b52;
case 0x0c073b54u: goto P_0c073b54;
case 0x0c073b56u: goto P_0c073b56;
case 0x0c073b58u: goto P_0c073b58;
case 0x0c073b5au: goto P_0c073b5a;
case 0x0c073b5cu: goto P_0c073b5c;
case 0x0c073b5eu: goto P_0c073b5e;
case 0x0c073b60u: goto P_0c073b60;
case 0x0c073b62u: goto P_0c073b62;
case 0x0c073b80u: goto P_0c073b80;
case 0x0c073b82u: goto P_0c073b82;
case 0x0c073b84u: goto P_0c073b84;
case 0x0c073b86u: goto P_0c073b86;
case 0x0c073b88u: goto P_0c073b88;
case 0x0c073b8au: goto P_0c073b8a;
case 0x0c073b8cu: goto P_0c073b8c;
case 0x0c073b8eu: goto P_0c073b8e;
case 0x0c073b90u: goto P_0c073b90;
case 0x0c073b92u: goto P_0c073b92;
case 0x0c073b94u: goto P_0c073b94;
case 0x0c073b96u: goto P_0c073b96;
case 0x0c073b98u: goto P_0c073b98;
case 0x0c073b9au: goto P_0c073b9a;
case 0x0c073b9cu: goto P_0c073b9c;
case 0x0c073b9eu: goto P_0c073b9e;
case 0x0c073ba0u: goto P_0c073ba0;
case 0x0c073ba2u: goto P_0c073ba2;
case 0x0c073ba4u: goto P_0c073ba4;
case 0x0c073ba6u: goto P_0c073ba6;
case 0x0c073ba8u: goto P_0c073ba8;
case 0x0c073baau: goto P_0c073baa;
case 0x0c073bacu: goto P_0c073bac;
case 0x0c073baeu: goto P_0c073bae;
case 0x0c073bb0u: goto P_0c073bb0;
case 0x0c073bb2u: goto P_0c073bb2;
case 0x0c073bb4u: goto P_0c073bb4;
case 0x0c073bb6u: goto P_0c073bb6;
case 0x0c073bb8u: goto P_0c073bb8;
case 0x0c073bbau: goto P_0c073bba;
case 0x0c073bbcu: goto P_0c073bbc;
case 0x0c073bbeu: goto P_0c073bbe;
case 0x0c073bc0u: goto P_0c073bc0;
case 0x0c073bc2u: goto P_0c073bc2;
case 0x0c073bc4u: goto P_0c073bc4;
case 0x0c073bc6u: goto P_0c073bc6;
case 0x0c073bc8u: goto P_0c073bc8;
case 0x0c073bcau: goto P_0c073bca;
case 0x0c073bccu: goto P_0c073bcc;
case 0x0c073bceu: goto P_0c073bce;
case 0x0c073bd0u: goto P_0c073bd0;
case 0x0c073bd2u: goto P_0c073bd2;
case 0x0c073bd4u: goto P_0c073bd4;
case 0x0c073bd6u: goto P_0c073bd6;
case 0x0c073bd8u: goto P_0c073bd8;
case 0x0c073bdau: goto P_0c073bda;
case 0x0c073bdcu: goto P_0c073bdc;
case 0x0c073bdeu: goto P_0c073bde;
case 0x0c073be0u: goto P_0c073be0;
case 0x0c073be2u: goto P_0c073be2;
case 0x0c073be4u: goto P_0c073be4;
case 0x0c073be6u: goto P_0c073be6;
case 0x0c073be8u: goto P_0c073be8;
case 0x0c073beau: goto P_0c073bea;
case 0x0c073becu: goto P_0c073bec;
case 0x0c073beeu: goto P_0c073bee;
case 0x0c073bf0u: goto P_0c073bf0;
case 0x0c073bf2u: goto P_0c073bf2;
case 0x0c073bf4u: goto P_0c073bf4;
case 0x0c073bf6u: goto P_0c073bf6;
case 0x0c073bf8u: goto P_0c073bf8;
case 0x0c073bfau: goto P_0c073bfa;
case 0x0c073bfcu: goto P_0c073bfc;
case 0x0c073bfeu: goto P_0c073bfe;
case 0x0c073c00u: goto P_0c073c00;
case 0x0c073c02u: goto P_0c073c02;
case 0x0c073c04u: goto P_0c073c04;
case 0x0c073c06u: goto P_0c073c06;
case 0x0c073c08u: goto P_0c073c08;
case 0x0c073c0au: goto P_0c073c0a;
case 0x0c073c0cu: goto P_0c073c0c;
case 0x0c073c0eu: goto P_0c073c0e;
case 0x0c073c10u: goto P_0c073c10;
case 0x0c073c12u: goto P_0c073c12;
case 0x0c073c14u: goto P_0c073c14;
case 0x0c073c16u: goto P_0c073c16;
case 0x0c073c18u: goto P_0c073c18;
case 0x0c073c1au: goto P_0c073c1a;
case 0x0c073c1cu: goto P_0c073c1c;
case 0x0c073c1eu: goto P_0c073c1e;
case 0x0c073c20u: goto P_0c073c20;
case 0x0c073c22u: goto P_0c073c22;
case 0x0c073c24u: goto P_0c073c24;
case 0x0c073c26u: goto P_0c073c26;
case 0x0c073c28u: goto P_0c073c28;
case 0x0c073c2au: goto P_0c073c2a;
case 0x0c073c2cu: goto P_0c073c2c;
case 0x0c073c2eu: goto P_0c073c2e;
case 0x0c073c30u: goto P_0c073c30;
case 0x0c073c32u: goto P_0c073c32;
case 0x0c073c34u: goto P_0c073c34;
case 0x0c073c36u: goto P_0c073c36;
case 0x0c073c38u: goto P_0c073c38;
case 0x0c073c3au: goto P_0c073c3a;
case 0x0c073c3cu: goto P_0c073c3c;
case 0x0c073c3eu: goto P_0c073c3e;
case 0x0c073c40u: goto P_0c073c40;
case 0x0c073c42u: goto P_0c073c42;
case 0x0c073c44u: goto P_0c073c44;
case 0x0c073c46u: goto P_0c073c46;
case 0x0c073c48u: goto P_0c073c48;
case 0x0c073c4au: goto P_0c073c4a;
case 0x0c073c4cu: goto P_0c073c4c;
case 0x0c073c4eu: goto P_0c073c4e;
case 0x0c073c50u: goto P_0c073c50;
case 0x0c073c52u: goto P_0c073c52;
case 0x0c073c54u: goto P_0c073c54;
case 0x0c073c56u: goto P_0c073c56;
case 0x0c073c58u: goto P_0c073c58;
case 0x0c073c5au: goto P_0c073c5a;
case 0x0c073c5cu: goto P_0c073c5c;
case 0x0c073c5eu: goto P_0c073c5e;
case 0x0c073c60u: goto P_0c073c60;
case 0x0c073c62u: goto P_0c073c62;
case 0x0c073c64u: goto P_0c073c64;
case 0x0c073c66u: goto P_0c073c66;
case 0x0c073c68u: goto P_0c073c68;
case 0x0c073c6au: goto P_0c073c6a;
case 0x0c073c6cu: goto P_0c073c6c;
case 0x0c073c6eu: goto P_0c073c6e;
case 0x0c073c70u: goto P_0c073c70;
case 0x0c073c72u: goto P_0c073c72;
case 0x0c073c74u: goto P_0c073c74;
case 0x0c073c76u: goto P_0c073c76;
case 0x0c073c78u: goto P_0c073c78;
case 0x0c073c7au: goto P_0c073c7a;
case 0x0c073c7cu: goto P_0c073c7c;
case 0x0c073c7eu: goto P_0c073c7e;
case 0x0c073c80u: goto P_0c073c80;
case 0x0c073c82u: goto P_0c073c82;
case 0x0c073c84u: goto P_0c073c84;
case 0x0c073c86u: goto P_0c073c86;
case 0x0c073c88u: goto P_0c073c88;
case 0x0c073c8au: goto P_0c073c8a;
case 0x0c073c8cu: goto P_0c073c8c;
case 0x0c073c8eu: goto P_0c073c8e;
case 0x0c073c90u: goto P_0c073c90;
case 0x0c073c92u: goto P_0c073c92;
case 0x0c073c94u: goto P_0c073c94;
case 0x0c073c96u: goto P_0c073c96;
case 0x0c073c98u: goto P_0c073c98;
case 0x0c073c9au: goto P_0c073c9a;
case 0x0c073c9cu: goto P_0c073c9c;
case 0x0c073c9eu: goto P_0c073c9e;
case 0x0c073ca0u: goto P_0c073ca0;
case 0x0c073ca2u: goto P_0c073ca2;
case 0x0c073cbcu: goto P_0c073cbc;
case 0x0c073cbeu: goto P_0c073cbe;
case 0x0c073cc0u: goto P_0c073cc0;
case 0x0c073cc2u: goto P_0c073cc2;
case 0x0c073cc4u: goto P_0c073cc4;
case 0x0c073cc6u: goto P_0c073cc6;
case 0x0c073cc8u: goto P_0c073cc8;
case 0x0c073ccau: goto P_0c073cca;
case 0x0c073cccu: goto P_0c073ccc;
case 0x0c073cceu: goto P_0c073cce;
case 0x0c073cd0u: goto P_0c073cd0;
case 0x0c073cd2u: goto P_0c073cd2;
case 0x0c073cd4u: goto P_0c073cd4;
case 0x0c073cd6u: goto P_0c073cd6;
case 0x0c073cd8u: goto P_0c073cd8;
case 0x0c073cdau: goto P_0c073cda;
case 0x0c073cdcu: goto P_0c073cdc;
case 0x0c073cdeu: goto P_0c073cde;
case 0x0c073ce0u: goto P_0c073ce0;
case 0x0c073ce2u: goto P_0c073ce2;
case 0x0c073ce4u: goto P_0c073ce4;
case 0x0c073ce6u: goto P_0c073ce6;
case 0x0c073ce8u: goto P_0c073ce8;
case 0x0c073ceau: goto P_0c073cea;
case 0x0c073cecu: goto P_0c073cec;
case 0x0c073ceeu: goto P_0c073cee;
case 0x0c073cf0u: goto P_0c073cf0;
case 0x0c073cf2u: goto P_0c073cf2;
case 0x0c073cf4u: goto P_0c073cf4;
case 0x0c073cf6u: goto P_0c073cf6;
case 0x0c073cf8u: goto P_0c073cf8;
case 0x0c073cfau: goto P_0c073cfa;
case 0x0c073cfcu: goto P_0c073cfc;
case 0x0c073cfeu: goto P_0c073cfe;
case 0x0c073d00u: goto P_0c073d00;
case 0x0c073d02u: goto P_0c073d02;
case 0x0c073d04u: goto P_0c073d04;
case 0x0c073d06u: goto P_0c073d06;
case 0x0c073d08u: goto P_0c073d08;
case 0x0c073d0au: goto P_0c073d0a;
case 0x0c073d0cu: goto P_0c073d0c;
case 0x0c073d0eu: goto P_0c073d0e;
case 0x0c073d10u: goto P_0c073d10;
case 0x0c073d12u: goto P_0c073d12;
case 0x0c073d14u: goto P_0c073d14;
case 0x0c073d16u: goto P_0c073d16;
case 0x0c073d18u: goto P_0c073d18;
case 0x0c073d1au: goto P_0c073d1a;
case 0x0c073d1cu: goto P_0c073d1c;
case 0x0c073d1eu: goto P_0c073d1e;
case 0x0c073d20u: goto P_0c073d20;
case 0x0c073d22u: goto P_0c073d22;
case 0x0c073d24u: goto P_0c073d24;
case 0x0c073d26u: goto P_0c073d26;
case 0x0c073d28u: goto P_0c073d28;
case 0x0c073d2au: goto P_0c073d2a;
case 0x0c073d2cu: goto P_0c073d2c;
case 0x0c073d2eu: goto P_0c073d2e;
case 0x0c073d30u: goto P_0c073d30;
case 0x0c073d32u: goto P_0c073d32;
case 0x0c073d34u: goto P_0c073d34;
case 0x0c073d36u: goto P_0c073d36;
case 0x0c073d38u: goto P_0c073d38;
case 0x0c073d3au: goto P_0c073d3a;
case 0x0c073d3cu: goto P_0c073d3c;
case 0x0c073d3eu: goto P_0c073d3e;
case 0x0c073d40u: goto P_0c073d40;
case 0x0c073d42u: goto P_0c073d42;
case 0x0c073d44u: goto P_0c073d44;
case 0x0c073d46u: goto P_0c073d46;
case 0x0c073d48u: goto P_0c073d48;
case 0x0c073d4au: goto P_0c073d4a;
case 0x0c073d4cu: goto P_0c073d4c;
case 0x0c073d4eu: goto P_0c073d4e;
case 0x0c073d50u: goto P_0c073d50;
case 0x0c073d52u: goto P_0c073d52;
case 0x0c073d54u: goto P_0c073d54;
case 0x0c073d56u: goto P_0c073d56;
case 0x0c073d58u: goto P_0c073d58;
case 0x0c073d5au: goto P_0c073d5a;
case 0x0c073d5cu: goto P_0c073d5c;
case 0x0c073d5eu: goto P_0c073d5e;
case 0x0c073d60u: goto P_0c073d60;
case 0x0c073d62u: goto P_0c073d62;
case 0x0c073d64u: goto P_0c073d64;
case 0x0c073d66u: goto P_0c073d66;
case 0x0c073d68u: goto P_0c073d68;
case 0x0c073d6au: goto P_0c073d6a;
case 0x0c073d6cu: goto P_0c073d6c;
case 0x0c073d6eu: goto P_0c073d6e;
case 0x0c073d70u: goto P_0c073d70;
case 0x0c073d72u: goto P_0c073d72;
case 0x0c073d74u: goto P_0c073d74;
case 0x0c073d76u: goto P_0c073d76;
case 0x0c073d78u: goto P_0c073d78;
case 0x0c073d7au: goto P_0c073d7a;
case 0x0c073d7cu: goto P_0c073d7c;
case 0x0c073d7eu: goto P_0c073d7e;
case 0x0c073d80u: goto P_0c073d80;
case 0x0c073d82u: goto P_0c073d82;
case 0x0c073d84u: goto P_0c073d84;
case 0x0c073d86u: goto P_0c073d86;
case 0x0c073d88u: goto P_0c073d88;
case 0x0c073d8au: goto P_0c073d8a;
case 0x0c073d8cu: goto P_0c073d8c;
case 0x0c073d8eu: goto P_0c073d8e;
case 0x0c073d90u: goto P_0c073d90;
case 0x0c073d92u: goto P_0c073d92;
case 0x0c073d94u: goto P_0c073d94;
case 0x0c073d96u: goto P_0c073d96;
case 0x0c073d98u: goto P_0c073d98;
case 0x0c073d9au: goto P_0c073d9a;
case 0x0c073d9cu: goto P_0c073d9c;
case 0x0c073d9eu: goto P_0c073d9e;
case 0x0c073da0u: goto P_0c073da0;
case 0x0c073da2u: goto P_0c073da2;
case 0x0c073da4u: goto P_0c073da4;
case 0x0c073da6u: goto P_0c073da6;
case 0x0c073da8u: goto P_0c073da8;
case 0x0c073daau: goto P_0c073daa;
case 0x0c073dacu: goto P_0c073dac;
case 0x0c073daeu: goto P_0c073dae;
case 0x0c073db0u: goto P_0c073db0;
case 0x0c073db2u: goto P_0c073db2;
case 0x0c073db4u: goto P_0c073db4;
case 0x0c073db6u: goto P_0c073db6;
case 0x0c073db8u: goto P_0c073db8;
case 0x0c073dbau: goto P_0c073dba;
case 0x0c073dbcu: goto P_0c073dbc;
case 0x0c073dbeu: goto P_0c073dbe;
case 0x0c073dc0u: goto P_0c073dc0;
case 0x0c073dc2u: goto P_0c073dc2;
case 0x0c073dc4u: goto P_0c073dc4;
case 0x0c073dc6u: goto P_0c073dc6;
case 0x0c073dc8u: goto P_0c073dc8;
case 0x0c073dcau: goto P_0c073dca;
case 0x0c073dccu: goto P_0c073dcc;
case 0x0c073dceu: goto P_0c073dce;
case 0x0c073dd0u: goto P_0c073dd0;
case 0x0c073dd2u: goto P_0c073dd2;
case 0x0c073dd4u: goto P_0c073dd4;
case 0x0c073dd6u: goto P_0c073dd6;
case 0x0c073dd8u: goto P_0c073dd8;
case 0x0c073ddau: goto P_0c073dda;
case 0x0c073ddcu: goto P_0c073ddc;
case 0x0c073ddeu: goto P_0c073dde;
case 0x0c073de0u: goto P_0c073de0;
case 0x0c073de2u: goto P_0c073de2;
case 0x0c073de4u: goto P_0c073de4;
case 0x0c073de6u: goto P_0c073de6;
case 0x0c073de8u: goto P_0c073de8;
case 0x0c073deau: goto P_0c073dea;
case 0x0c073decu: goto P_0c073dec;
case 0x0c073deeu: goto P_0c073dee;
case 0x0c073df0u: goto P_0c073df0;
case 0x0c073df2u: goto P_0c073df2;
case 0x0c073df4u: goto P_0c073df4;
case 0x0c073df6u: goto P_0c073df6;
case 0x0c073df8u: goto P_0c073df8;
case 0x0c073dfau: goto P_0c073dfa;
case 0x0c073dfcu: goto P_0c073dfc;
case 0x0c073dfeu: goto P_0c073dfe;
case 0x0c073e00u: goto P_0c073e00;
case 0x0c073e02u: goto P_0c073e02;
case 0x0c073e04u: goto P_0c073e04;
case 0x0c073e06u: goto P_0c073e06;
case 0x0c073e08u: goto P_0c073e08;
case 0x0c073e0au: goto P_0c073e0a;
case 0x0c073e0cu: goto P_0c073e0c;
case 0x0c073e0eu: goto P_0c073e0e;
case 0x0c073e10u: goto P_0c073e10;
case 0x0c073e12u: goto P_0c073e12;
case 0x0c073e14u: goto P_0c073e14;
case 0x0c073e16u: goto P_0c073e16;
case 0x0c073e18u: goto P_0c073e18;
case 0x0c073e1au: goto P_0c073e1a;
case 0x0c073e1cu: goto P_0c073e1c;
case 0x0c073e1eu: goto P_0c073e1e;
case 0x0c073e20u: goto P_0c073e20;
case 0x0c073e22u: goto P_0c073e22;
case 0x0c073e24u: goto P_0c073e24;
case 0x0c073e26u: goto P_0c073e26;
case 0x0c073e28u: goto P_0c073e28;
case 0x0c073e2au: goto P_0c073e2a;
case 0x0c073e2cu: goto P_0c073e2c;
case 0x0c073e2eu: goto P_0c073e2e;
case 0x0c073e30u: goto P_0c073e30;
case 0x0c073e32u: goto P_0c073e32;
case 0x0c073e34u: goto P_0c073e34;
case 0x0c073e36u: goto P_0c073e36;
case 0x0c073e38u: goto P_0c073e38;
case 0x0c073e3au: goto P_0c073e3a;
case 0x0c073e3cu: goto P_0c073e3c;
case 0x0c073e3eu: goto P_0c073e3e;
case 0x0c073e40u: goto P_0c073e40;
case 0x0c073e42u: goto P_0c073e42;
case 0x0c073e44u: goto P_0c073e44;
case 0x0c073e46u: goto P_0c073e46;
case 0x0c073e48u: goto P_0c073e48;
case 0x0c073e4au: goto P_0c073e4a;
case 0x0c073e4cu: goto P_0c073e4c;
case 0x0c073e4eu: goto P_0c073e4e;
case 0x0c073e50u: goto P_0c073e50;
case 0x0c073e52u: goto P_0c073e52;
case 0x0c073e54u: goto P_0c073e54;
case 0x0c073e56u: goto P_0c073e56;
case 0x0c073e58u: goto P_0c073e58;
case 0x0c073e5au: goto P_0c073e5a;
case 0x0c073e5cu: goto P_0c073e5c;
case 0x0c073e5eu: goto P_0c073e5e;
case 0x0c073e60u: goto P_0c073e60;
case 0x0c073e62u: goto P_0c073e62;
case 0x0c073e64u: goto P_0c073e64;
case 0x0c073e66u: goto P_0c073e66;
case 0x0c073e68u: goto P_0c073e68;
case 0x0c073e6au: goto P_0c073e6a;
case 0x0c073e6cu: goto P_0c073e6c;
case 0x0c073e6eu: goto P_0c073e6e;
case 0x0c073e70u: goto P_0c073e70;
case 0x0c073e72u: goto P_0c073e72;
case 0x0c073e74u: goto P_0c073e74;
case 0x0c073e76u: goto P_0c073e76;
case 0x0c073e78u: goto P_0c073e78;
case 0x0c073e7au: goto P_0c073e7a;
case 0x0c073e7cu: goto P_0c073e7c;
case 0x0c073e7eu: goto P_0c073e7e;
case 0x0c073e80u: goto P_0c073e80;
case 0x0c073e82u: goto P_0c073e82;
case 0x0c073e84u: goto P_0c073e84;
case 0x0c073e86u: goto P_0c073e86;
case 0x0c073e88u: goto P_0c073e88;
case 0x0c073e8au: goto P_0c073e8a;
case 0x0c073e8cu: goto P_0c073e8c;
case 0x0c073e8eu: goto P_0c073e8e;
case 0x0c073e90u: goto P_0c073e90;
case 0x0c073e92u: goto P_0c073e92;
case 0x0c073e94u: goto P_0c073e94;
case 0x0c073e96u: goto P_0c073e96;
case 0x0c073e98u: goto P_0c073e98;
case 0x0c073e9au: goto P_0c073e9a;
case 0x0c073e9cu: goto P_0c073e9c;
case 0x0c073e9eu: goto P_0c073e9e;
case 0x0c073ea0u: goto P_0c073ea0;
case 0x0c073ea2u: goto P_0c073ea2;
case 0x0c073ea4u: goto P_0c073ea4;
case 0x0c073ea6u: goto P_0c073ea6;
case 0x0c073ea8u: goto P_0c073ea8;
case 0x0c073eaau: goto P_0c073eaa;
case 0x0c073eacu: goto P_0c073eac;
case 0x0c073eaeu: goto P_0c073eae;
case 0x0c073eb0u: goto P_0c073eb0;
case 0x0c073eb2u: goto P_0c073eb2;
case 0x0c073eb4u: goto P_0c073eb4;
case 0x0c073eb6u: goto P_0c073eb6;
case 0x0c073eb8u: goto P_0c073eb8;
case 0x0c073ebau: goto P_0c073eba;
case 0x0c073ebcu: goto P_0c073ebc;
case 0x0c073ebeu: goto P_0c073ebe;
case 0x0c073ec0u: goto P_0c073ec0;
case 0x0c073ec2u: goto P_0c073ec2;
case 0x0c073ec4u: goto P_0c073ec4;
case 0x0c073ec6u: goto P_0c073ec6;
case 0x0c073ec8u: goto P_0c073ec8;
case 0x0c073ecau: goto P_0c073eca;
case 0x0c073eccu: goto P_0c073ecc;
case 0x0c073eceu: goto P_0c073ece;
case 0x0c073ed0u: goto P_0c073ed0;
case 0x0c073ed2u: goto P_0c073ed2;
case 0x0c073ed4u: goto P_0c073ed4;
case 0x0c073ee0u: goto P_0c073ee0;
case 0x0c073ee2u: goto P_0c073ee2;
case 0x0c073ee4u: goto P_0c073ee4;
case 0x0c073ee6u: goto P_0c073ee6;
case 0x0c073ee8u: goto P_0c073ee8;
case 0x0c073eeau: goto P_0c073eea;
case 0x0c073eecu: goto P_0c073eec;
case 0x0c073eeeu: goto P_0c073eee;
case 0x0c073ef0u: goto P_0c073ef0;
case 0x0c073ef2u: goto P_0c073ef2;
case 0x0c073ef4u: goto P_0c073ef4;
case 0x0c073ef6u: goto P_0c073ef6;
case 0x0c073ef8u: goto P_0c073ef8;
case 0x0c073efau: goto P_0c073efa;
case 0x0c073efcu: goto P_0c073efc;
case 0x0c073efeu: goto P_0c073efe;
case 0x0c073f00u: goto P_0c073f00;
case 0x0c073f02u: goto P_0c073f02;
case 0x0c073f04u: goto P_0c073f04;
case 0x0c073f06u: goto P_0c073f06;
case 0x0c073f08u: goto P_0c073f08;
case 0x0c073f0au: goto P_0c073f0a;
case 0x0c073f0cu: goto P_0c073f0c;
case 0x0c073f0eu: goto P_0c073f0e;
case 0x0c073f10u: goto P_0c073f10;
case 0x0c073f12u: goto P_0c073f12;
case 0x0c073f14u: goto P_0c073f14;
case 0x0c073f16u: goto P_0c073f16;
case 0x0c073f18u: goto P_0c073f18;
case 0x0c073f1au: goto P_0c073f1a;
case 0x0c073f1cu: goto P_0c073f1c;
case 0x0c073f1eu: goto P_0c073f1e;
case 0x0c073f20u: goto P_0c073f20;
case 0x0c073f22u: goto P_0c073f22;
case 0x0c073f24u: goto P_0c073f24;
case 0x0c073f26u: goto P_0c073f26;
case 0x0c073f28u: goto P_0c073f28;
case 0x0c073f2au: goto P_0c073f2a;
case 0x0c073f2cu: goto P_0c073f2c;
case 0x0c073f2eu: goto P_0c073f2e;
case 0x0c073f30u: goto P_0c073f30;
case 0x0c073f32u: goto P_0c073f32;
case 0x0c073f34u: goto P_0c073f34;
case 0x0c073f36u: goto P_0c073f36;
case 0x0c073f38u: goto P_0c073f38;
case 0x0c073f3au: goto P_0c073f3a;
case 0x0c073f3cu: goto P_0c073f3c;
case 0x0c073f3eu: goto P_0c073f3e;
case 0x0c073f40u: goto P_0c073f40;
case 0x0c073f42u: goto P_0c073f42;
case 0x0c073f44u: goto P_0c073f44;
case 0x0c073f46u: goto P_0c073f46;
case 0x0c073f48u: goto P_0c073f48;
case 0x0c073f4au: goto P_0c073f4a;
case 0x0c073f4cu: goto P_0c073f4c;
case 0x0c073f4eu: goto P_0c073f4e;
case 0x0c073f50u: goto P_0c073f50;
case 0x0c073f52u: goto P_0c073f52;
case 0x0c073f54u: goto P_0c073f54;
case 0x0c073f56u: goto P_0c073f56;
case 0x0c073f58u: goto P_0c073f58;
case 0x0c073f5au: goto P_0c073f5a;
case 0x0c073f5cu: goto P_0c073f5c;
case 0x0c073f5eu: goto P_0c073f5e;
case 0x0c073f60u: goto P_0c073f60;
case 0x0c073f62u: goto P_0c073f62;
case 0x0c073f64u: goto P_0c073f64;
case 0x0c073f66u: goto P_0c073f66;
case 0x0c073f68u: goto P_0c073f68;
case 0x0c073f6au: goto P_0c073f6a;
case 0x0c073f6cu: goto P_0c073f6c;
case 0x0c073f6eu: goto P_0c073f6e;
case 0x0c073f70u: goto P_0c073f70;
case 0x0c073f72u: goto P_0c073f72;
case 0x0c073f74u: goto P_0c073f74;
case 0x0c073f76u: goto P_0c073f76;
case 0x0c073f78u: goto P_0c073f78;
case 0x0c073f7au: goto P_0c073f7a;
case 0x0c073f7cu: goto P_0c073f7c;
case 0x0c073f7eu: goto P_0c073f7e;
case 0x0c073f80u: goto P_0c073f80;
default: return vf3_matrix_family(target,s,ram);
}
P_0c073aac: /* original 2fe6, guest PC 0x0c073aac */
if(!s->budget--) { s->failed_pc=0x0c073aacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073aae;
P_0c073aae: /* original 2fd6, guest PC 0x0c073aae */
if(!s->budget--) { s->failed_pc=0x0c073aaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073ab0;
P_0c073ab0: /* original 2fc6, guest PC 0x0c073ab0 */
if(!s->budget--) { s->failed_pc=0x0c073ab0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073ab2;
P_0c073ab2: /* original 2fb6, guest PC 0x0c073ab2 */
if(!s->budget--) { s->failed_pc=0x0c073ab2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073ab4;
P_0c073ab4: /* original 2fa6, guest PC 0x0c073ab4 */
if(!s->budget--) { s->failed_pc=0x0c073ab4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073ab6;
P_0c073ab6: /* original 2f96, guest PC 0x0c073ab6 */
if(!s->budget--) { s->failed_pc=0x0c073ab6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073ab8;
P_0c073ab8: /* original 2f86, guest PC 0x0c073ab8 */
if(!s->budget--) { s->failed_pc=0x0c073ab8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c073aba;
P_0c073aba: /* original fffb, guest PC 0x0c073aba */
if(!s->budget--) { s->failed_pc=0x0c073abau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c073abc;
P_0c073abc: /* original ffeb, guest PC 0x0c073abc */
if(!s->budget--) { s->failed_pc=0x0c073abcu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c073abe;
P_0c073abe: /* original ffdb, guest PC 0x0c073abe */
if(!s->budget--) { s->failed_pc=0x0c073abeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c073ac0;
P_0c073ac0: /* original ffcb, guest PC 0x0c073ac0 */
if(!s->budget--) { s->failed_pc=0x0c073ac0u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c073ac2;
P_0c073ac2: /* original d12b, guest PC 0x0c073ac2 */
if(!s->budget--) { s->failed_pc=0x0c073ac2u; return 0; }
r[1]=read(ram,0x0c073b70u,4);
goto P_0c073ac4;
P_0c073ac4: /* original d329, guest PC 0x0c073ac4 */
if(!s->budget--) { s->failed_pc=0x0c073ac4u; return 0; }
r[3]=read(ram,0x0c073b6cu,4);
goto P_0c073ac6;
P_0c073ac6: /* original 6212, guest PC 0x0c073ac6 */
if(!s->budget--) { s->failed_pc=0x0c073ac6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c073ac8;
P_0c073ac8: /* original 904c, guest PC 0x0c073ac8 */
if(!s->budget--) { s->failed_pc=0x0c073ac8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073b64u,2);
goto P_0c073aca;
P_0c073aca: /* original 2238, guest PC 0x0c073aca */
if(!s->budget--) { s->failed_pc=0x0c073acau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c073acc;
P_0c073acc: /* original 3f0c, guest PC 0x0c073acc */
if(!s->budget--) { s->failed_pc=0x0c073accu; return 0; }
r[15]+=r[0];
goto P_0c073ace;
P_0c073ace: /* original 8901, guest PC 0x0c073ace */
if(!s->budget--) { s->failed_pc=0x0c073aceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073ad4; }
goto P_0c073ad0;
P_0c073ad0: /* original a249, guest PC 0x0c073ad0 */
if(!s->budget--) { s->failed_pc=0x0c073ad0u; return 0; }
goto P_0c073f66;
P_0c073ad2: /* original 0009, guest PC 0x0c073ad2 */
if(!s->budget--) { s->failed_pc=0x0c073ad2u; return 0; }
goto P_0c073ad4;
P_0c073ad4: /* original e038, guest PC 0x0c073ad4 */
if(!s->budget--) { s->failed_pc=0x0c073ad4u; return 0; }
r[0]=0x00000038u;
goto P_0c073ad6;
P_0c073ad6: /* original e700, guest PC 0x0c073ad6 */
if(!s->budget--) { s->failed_pc=0x0c073ad6u; return 0; }
r[7]=0x00000000u;
goto P_0c073ad8;
P_0c073ad8: /* original 0f74, guest PC 0x0c073ad8 */
if(!s->budget--) { s->failed_pc=0x0c073ad8u; return 0; }
write(ram,r[15]+r[0],r[7],1);
goto P_0c073ada;
P_0c073ada: /* original e030, guest PC 0x0c073ada */
if(!s->budget--) { s->failed_pc=0x0c073adau; return 0; }
r[0]=0x00000030u;
goto P_0c073adc;
P_0c073adc: /* original f38d, guest PC 0x0c073adc */
if(!s->budget--) { s->failed_pc=0x0c073adcu; return 0; }
fr[3]=0;
goto P_0c073ade;
P_0c073ade: /* original 6973, guest PC 0x0c073ade */
if(!s->budget--) { s->failed_pc=0x0c073adeu; return 0; }
r[9]=r[7];
goto P_0c073ae0;
P_0c073ae0: /* original ff37, guest PC 0x0c073ae0 */
if(!s->budget--) { s->failed_pc=0x0c073ae0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073ae2;
P_0c073ae2: /* original e030, guest PC 0x0c073ae2 */
if(!s->budget--) { s->failed_pc=0x0c073ae2u; return 0; }
r[0]=0x00000030u;
goto P_0c073ae4;
P_0c073ae4: /* original f437, guest PC 0x0c073ae4 */
if(!s->budget--) { s->failed_pc=0x0c073ae4u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c073ae6;
P_0c073ae6: /* original 6873, guest PC 0x0c073ae6 */
if(!s->budget--) { s->failed_pc=0x0c073ae6u; return 0; }
r[8]=r[7];
goto P_0c073ae8;
P_0c073ae8: /* original 903d, guest PC 0x0c073ae8 */
if(!s->budget--) { s->failed_pc=0x0c073ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073b66u,2);
goto P_0c073aea;
P_0c073aea: /* original 6b73, guest PC 0x0c073aea */
if(!s->budget--) { s->failed_pc=0x0c073aeau; return 0; }
r[11]=r[7];
goto P_0c073aec;
P_0c073aec: /* original 6a73, guest PC 0x0c073aec */
if(!s->budget--) { s->failed_pc=0x0c073aecu; return 0; }
r[10]=r[7];
goto P_0c073aee;
P_0c073aee: /* original 035e, guest PC 0x0c073aee */
if(!s->budget--) { s->failed_pc=0x0c073aeeu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c073af0;
P_0c073af0: /* original 2f32, guest PC 0x0c073af0 */
if(!s->budget--) { s->failed_pc=0x0c073af0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c073af2;
P_0c073af2: /* original 9038, guest PC 0x0c073af2 */
if(!s->budget--) { s->failed_pc=0x0c073af2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073b66u,2);
goto P_0c073af4;
P_0c073af4: /* original 026e, guest PC 0x0c073af4 */
if(!s->budget--) { s->failed_pc=0x0c073af4u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c073af6;
P_0c073af6: /* original 1f22, guest PC 0x0c073af6 */
if(!s->budget--) { s->failed_pc=0x0c073af6u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c073af8;
P_0c073af8: /* original dc1e, guest PC 0x0c073af8 */
if(!s->budget--) { s->failed_pc=0x0c073af8u; return 0; }
r[12]=read(ram,0x0c073b74u,4);
goto P_0c073afa;
P_0c073afa: /* original 63f2, guest PC 0x0c073afa */
if(!s->budget--) { s->failed_pc=0x0c073afau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c073afc;
P_0c073afc: /* original de1e, guest PC 0x0c073afc */
if(!s->budget--) { s->failed_pc=0x0c073afcu; return 0; }
r[14]=read(ram,0x0c073b78u,4);
goto P_0c073afe;
P_0c073afe: /* original 23c9, guest PC 0x0c073afe */
if(!s->budget--) { s->failed_pc=0x0c073afeu; return 0; }
r[3]&=r[12];
goto P_0c073b00;
P_0c073b00: /* original 2338, guest PC 0x0c073b00 */
if(!s->budget--) { s->failed_pc=0x0c073b00u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c073b02;
P_0c073b02: /* original 8d16, guest PC 0x0c073b02 */
if(!s->budget--) { s->failed_pc=0x0c073b02u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c073b32; }
goto P_0c073b06;
P_0c073b04: /* original 2f32, guest PC 0x0c073b04 */
if(!s->budget--) { s->failed_pc=0x0c073b04u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c073b06;
P_0c073b06: /* original 902f, guest PC 0x0c073b06 */
if(!s->budget--) { s->failed_pc=0x0c073b06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073b68u,2);
goto P_0c073b08;
P_0c073b08: /* original db1c, guest PC 0x0c073b08 */
if(!s->budget--) { s->failed_pc=0x0c073b08u; return 0; }
r[11]=read(ram,0x0c073b7cu,4);
goto P_0c073b0a;
P_0c073b0a: /* original 005c, guest PC 0x0c073b0a */
if(!s->budget--) { s->failed_pc=0x0c073b0au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c073b0c;
P_0c073b0c: /* original 600c, guest PC 0x0c073b0c */
if(!s->budget--) { s->failed_pc=0x0c073b0cu; return 0; }
r[0]=r[0]&255u;
goto P_0c073b0e;
P_0c073b0e: /* original 4008, guest PC 0x0c073b0e */
if(!s->budget--) { s->failed_pc=0x0c073b0eu; return 0; }
r[0]<<=2;
goto P_0c073b10;
P_0c073b10: /* original 08ee, guest PC 0x0c073b10 */
if(!s->budget--) { s->failed_pc=0x0c073b10u; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c073b12;
P_0c073b12: /* original e04c, guest PC 0x0c073b12 */
if(!s->budget--) { s->failed_pc=0x0c073b12u; return 0; }
r[0]=0x0000004cu;
goto P_0c073b14;
P_0c073b14: /* original 005e, guest PC 0x0c073b14 */
if(!s->budget--) { s->failed_pc=0x0c073b14u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c073b16;
P_0c073b16: /* original c920, guest PC 0x0c073b16 */
if(!s->budget--) { s->failed_pc=0x0c073b16u; return 0; }
r[0]&=32u;
goto P_0c073b18;
P_0c073b18: /* original 1f01, guest PC 0x0c073b18 */
if(!s->budget--) { s->failed_pc=0x0c073b18u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073b1a;
P_0c073b1a: /* original 4028, guest PC 0x0c073b1a */
if(!s->budget--) { s->failed_pc=0x0c073b1au; return 0; }
r[0]<<=16;
goto P_0c073b1c;
P_0c073b1c: /* original 4018, guest PC 0x0c073b1c */
if(!s->budget--) { s->failed_pc=0x0c073b1cu; return 0; }
r[0]<<=8;
goto P_0c073b1e;
P_0c073b1e: /* original 4008, guest PC 0x0c073b1e */
if(!s->budget--) { s->failed_pc=0x0c073b1eu; return 0; }
r[0]<<=2;
goto P_0c073b20;
P_0c073b20: /* original 2f02, guest PC 0x0c073b20 */
if(!s->budget--) { s->failed_pc=0x0c073b20u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073b22;
P_0c073b22: /* original 53f1, guest PC 0x0c073b22 */
if(!s->budget--) { s->failed_pc=0x0c073b22u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c073b24;
P_0c073b24: /* original 2338, guest PC 0x0c073b24 */
if(!s->budget--) { s->failed_pc=0x0c073b24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c073b26;
P_0c073b26: /* original 8d02, guest PC 0x0c073b26 */
if(!s->budget--) { s->failed_pc=0x0c073b26u; return 0; }
cond=r[17]&1u;
r[11]&=r[8];
if(cond) { goto P_0c073b2e; }
goto P_0c073b2a;
P_0c073b28: /* original 2b89, guest PC 0x0c073b28 */
if(!s->budget--) { s->failed_pc=0x0c073b28u; return 0; }
r[11]&=r[8];
goto P_0c073b2a;
P_0c073b2a: /* original a002, guest PC 0x0c073b2a */
if(!s->budget--) { s->failed_pc=0x0c073b2au; return 0; }
r[8]=r[7];
goto P_0c073b32;
P_0c073b2c: /* original 6873, guest PC 0x0c073b2c */
if(!s->budget--) { s->failed_pc=0x0c073b2cu; return 0; }
r[8]=r[7];
goto P_0c073b2e;
P_0c073b2e: /* original 62f2, guest PC 0x0c073b2e */
if(!s->budget--) { s->failed_pc=0x0c073b2eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c073b30;
P_0c073b30: /* original 282b, guest PC 0x0c073b30 */
if(!s->budget--) { s->failed_pc=0x0c073b30u; return 0; }
r[8]|=r[2];
goto P_0c073b32;
P_0c073b32: /* original 53f2, guest PC 0x0c073b32 */
if(!s->budget--) { s->failed_pc=0x0c073b32u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c073b34;
P_0c073b34: /* original 23c9, guest PC 0x0c073b34 */
if(!s->budget--) { s->failed_pc=0x0c073b34u; return 0; }
r[3]&=r[12];
goto P_0c073b36;
P_0c073b36: /* original 2338, guest PC 0x0c073b36 */
if(!s->budget--) { s->failed_pc=0x0c073b36u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c073b38;
P_0c073b38: /* original 8d24, guest PC 0x0c073b38 */
if(!s->budget--) { s->failed_pc=0x0c073b38u; return 0; }
cond=r[17]&1u;
write(ram,r[15],r[3],4);
if(cond) { goto P_0c073b84; }
goto P_0c073b3c;
P_0c073b3a: /* original 2f32, guest PC 0x0c073b3a */
if(!s->budget--) { s->failed_pc=0x0c073b3au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c073b3c;
P_0c073b3c: /* original 9014, guest PC 0x0c073b3c */
if(!s->budget--) { s->failed_pc=0x0c073b3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073b68u,2);
goto P_0c073b3e;
P_0c073b3e: /* original da0f, guest PC 0x0c073b3e */
if(!s->budget--) { s->failed_pc=0x0c073b3eu; return 0; }
r[10]=read(ram,0x0c073b7cu,4);
goto P_0c073b40;
P_0c073b40: /* original 006c, guest PC 0x0c073b40 */
if(!s->budget--) { s->failed_pc=0x0c073b40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c073b42;
P_0c073b42: /* original 600c, guest PC 0x0c073b42 */
if(!s->budget--) { s->failed_pc=0x0c073b42u; return 0; }
r[0]=r[0]&255u;
goto P_0c073b44;
P_0c073b44: /* original 4008, guest PC 0x0c073b44 */
if(!s->budget--) { s->failed_pc=0x0c073b44u; return 0; }
r[0]<<=2;
goto P_0c073b46;
P_0c073b46: /* original 09ee, guest PC 0x0c073b46 */
if(!s->budget--) { s->failed_pc=0x0c073b46u; return 0; }
r[9]=read(ram,r[14]+r[0],4);
goto P_0c073b48;
P_0c073b48: /* original e04c, guest PC 0x0c073b48 */
if(!s->budget--) { s->failed_pc=0x0c073b48u; return 0; }
r[0]=0x0000004cu;
goto P_0c073b4a;
P_0c073b4a: /* original 006e, guest PC 0x0c073b4a */
if(!s->budget--) { s->failed_pc=0x0c073b4au; return 0; }
r[0]=read(ram,r[6]+r[0],4);
goto P_0c073b4c;
P_0c073b4c: /* original c920, guest PC 0x0c073b4c */
if(!s->budget--) { s->failed_pc=0x0c073b4cu; return 0; }
r[0]&=32u;
goto P_0c073b4e;
P_0c073b4e: /* original 2f02, guest PC 0x0c073b4e */
if(!s->budget--) { s->failed_pc=0x0c073b4eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c073b50;
P_0c073b50: /* original 4028, guest PC 0x0c073b50 */
if(!s->budget--) { s->failed_pc=0x0c073b50u; return 0; }
r[0]<<=16;
goto P_0c073b52;
P_0c073b52: /* original 4018, guest PC 0x0c073b52 */
if(!s->budget--) { s->failed_pc=0x0c073b52u; return 0; }
r[0]<<=8;
goto P_0c073b54;
P_0c073b54: /* original 4008, guest PC 0x0c073b54 */
if(!s->budget--) { s->failed_pc=0x0c073b54u; return 0; }
r[0]<<=2;
goto P_0c073b56;
P_0c073b56: /* original 1f01, guest PC 0x0c073b56 */
if(!s->budget--) { s->failed_pc=0x0c073b56u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073b58;
P_0c073b58: /* original 63f2, guest PC 0x0c073b58 */
if(!s->budget--) { s->failed_pc=0x0c073b58u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c073b5a;
P_0c073b5a: /* original 2338, guest PC 0x0c073b5a */
if(!s->budget--) { s->failed_pc=0x0c073b5au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c073b5c;
P_0c073b5c: /* original 8d10, guest PC 0x0c073b5c */
if(!s->budget--) { s->failed_pc=0x0c073b5cu; return 0; }
cond=r[17]&1u;
r[10]&=r[9];
if(cond) { goto P_0c073b80; }
goto P_0c073b60;
P_0c073b5e: /* original 2a99, guest PC 0x0c073b5e */
if(!s->budget--) { s->failed_pc=0x0c073b5eu; return 0; }
r[10]&=r[9];
goto P_0c073b60;
P_0c073b60: /* original a010, guest PC 0x0c073b60 */
if(!s->budget--) { s->failed_pc=0x0c073b60u; return 0; }
r[9]=r[7];
goto P_0c073b84;
P_0c073b62: /* original 6973, guest PC 0x0c073b62 */
if(!s->budget--) { s->failed_pc=0x0c073b62u; return 0; }
r[9]=r[7];
if(!vf3_matrix_family(0x0c073b64u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073b64u; return 0; } return 1;
P_0c073b80: /* original 52f1, guest PC 0x0c073b80 */
if(!s->budget--) { s->failed_pc=0x0c073b80u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c073b82;
P_0c073b82: /* original 292b, guest PC 0x0c073b82 */
if(!s->budget--) { s->failed_pc=0x0c073b82u; return 0; }
r[9]|=r[2];
goto P_0c073b84;
P_0c073b84: /* original 908e, guest PC 0x0c073b84 */
if(!s->budget--) { s->failed_pc=0x0c073b84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca4u,2);
goto P_0c073b86;
P_0c073b86: /* original de4a, guest PC 0x0c073b86 */
if(!s->budget--) { s->failed_pc=0x0c073b86u; return 0; }
r[14]=read(ram,0x0c073cb0u,4);
goto P_0c073b88;
P_0c073b88: /* original 005c, guest PC 0x0c073b88 */
if(!s->budget--) { s->failed_pc=0x0c073b88u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c073b8a;
P_0c073b8a: /* original 600c, guest PC 0x0c073b8a */
if(!s->budget--) { s->failed_pc=0x0c073b8au; return 0; }
r[0]=r[0]&255u;
goto P_0c073b8c;
P_0c073b8c: /* original c802, guest PC 0x0c073b8c */
if(!s->budget--) { s->failed_pc=0x0c073b8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c073b8e;
P_0c073b8e: /* original 8b4f, guest PC 0x0c073b8e */
if(!s->budget--) { s->failed_pc=0x0c073b8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073c30; }
goto P_0c073b90;
P_0c073b90: /* original 9389, guest PC 0x0c073b90 */
if(!s->budget--) { s->failed_pc=0x0c073b90u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca6u,2);
goto P_0c073b92;
P_0c073b92: /* original 9d88, guest PC 0x0c073b92 */
if(!s->budget--) { s->failed_pc=0x0c073b92u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca6u,2);
goto P_0c073b94;
P_0c073b94: /* original 336c, guest PC 0x0c073b94 */
if(!s->budget--) { s->failed_pc=0x0c073b94u; return 0; }
r[3]+=r[6];
goto P_0c073b96;
P_0c073b96: /* original 1f32, guest PC 0x0c073b96 */
if(!s->budget--) { s->failed_pc=0x0c073b96u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c073b98;
P_0c073b98: /* original 3d5c, guest PC 0x0c073b98 */
if(!s->budget--) { s->failed_pc=0x0c073b98u; return 0; }
r[13]+=r[5];
goto P_0c073b9a;
P_0c073b9a: /* original 63d3, guest PC 0x0c073b9a */
if(!s->budget--) { s->failed_pc=0x0c073b9au; return 0; }
r[3]=r[13];
goto P_0c073b9c;
P_0c073b9c: /* original 7308, guest PC 0x0c073b9c */
if(!s->budget--) { s->failed_pc=0x0c073b9cu; return 0; }
r[3]+=0x00000008u;
goto P_0c073b9e;
P_0c073b9e: /* original 62d3, guest PC 0x0c073b9e */
if(!s->budget--) { s->failed_pc=0x0c073b9eu; return 0; }
r[2]=r[13];
goto P_0c073ba0;
P_0c073ba0: /* original 7270, guest PC 0x0c073ba0 */
if(!s->budget--) { s->failed_pc=0x0c073ba0u; return 0; }
r[2]+=0x00000070u;
goto P_0c073ba2;
P_0c073ba2: /* original 1f24, guest PC 0x0c073ba2 */
if(!s->budget--) { s->failed_pc=0x0c073ba2u; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c073ba4;
P_0c073ba4: /* original 1f3a, guest PC 0x0c073ba4 */
if(!s->budget--) { s->failed_pc=0x0c073ba4u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c073ba6;
P_0c073ba6: /* original e361, guest PC 0x0c073ba6 */
if(!s->budget--) { s->failed_pc=0x0c073ba6u; return 0; }
r[3]=0x00000061u;
goto P_0c073ba8;
P_0c073ba8: /* original 335c, guest PC 0x0c073ba8 */
if(!s->budget--) { s->failed_pc=0x0c073ba8u; return 0; }
r[3]+=r[5];
goto P_0c073baa;
P_0c073baa: /* original d042, guest PC 0x0c073baa */
if(!s->budget--) { s->failed_pc=0x0c073baau; return 0; }
r[0]=read(ram,0x0c073cb4u,4);
goto P_0c073bac;
P_0c073bac: /* original 1f01, guest PC 0x0c073bac */
if(!s->budget--) { s->failed_pc=0x0c073bacu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c073bae;
P_0c073bae: /* original 6330, guest PC 0x0c073bae */
if(!s->budget--) { s->failed_pc=0x0c073baeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c073bb0;
P_0c073bb0: /* original 633c, guest PC 0x0c073bb0 */
if(!s->budget--) { s->failed_pc=0x0c073bb0u; return 0; }
r[3]=r[3]&255u;
goto P_0c073bb2;
P_0c073bb2: /* original 4308, guest PC 0x0c073bb2 */
if(!s->budget--) { s->failed_pc=0x0c073bb2u; return 0; }
r[3]<<=2;
goto P_0c073bb4;
P_0c073bb4: /* original 023e, guest PC 0x0c073bb4 */
if(!s->budget--) { s->failed_pc=0x0c073bb4u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c073bb6;
P_0c073bb6: /* original e061, guest PC 0x0c073bb6 */
if(!s->budget--) { s->failed_pc=0x0c073bb6u; return 0; }
r[0]=0x00000061u;
goto P_0c073bb8;
P_0c073bb8: /* original 2f22, guest PC 0x0c073bb8 */
if(!s->budget--) { s->failed_pc=0x0c073bb8u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c073bba;
P_0c073bba: /* original 036c, guest PC 0x0c073bba */
if(!s->budget--) { s->failed_pc=0x0c073bbau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c073bbc;
P_0c073bbc: /* original 50f1, guest PC 0x0c073bbc */
if(!s->budget--) { s->failed_pc=0x0c073bbcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c073bbe;
P_0c073bbe: /* original 633c, guest PC 0x0c073bbe */
if(!s->budget--) { s->failed_pc=0x0c073bbeu; return 0; }
r[3]=r[3]&255u;
goto P_0c073bc0;
P_0c073bc0: /* original 4308, guest PC 0x0c073bc0 */
if(!s->budget--) { s->failed_pc=0x0c073bc0u; return 0; }
r[3]<<=2;
goto P_0c073bc2;
P_0c073bc2: /* original 033e, guest PC 0x0c073bc2 */
if(!s->budget--) { s->failed_pc=0x0c073bc2u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c073bc4;
P_0c073bc4: /* original c73c, guest PC 0x0c073bc4 */
if(!s->budget--) { s->failed_pc=0x0c073bc4u; return 0; }
r[0]=code_base|0x00073cb8u;
goto P_0c073bc6;
P_0c073bc6: /* original 1f31, guest PC 0x0c073bc6 */
if(!s->budget--) { s->failed_pc=0x0c073bc6u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c073bc8;
P_0c073bc8: /* original 1fb3, guest PC 0x0c073bc8 */
if(!s->budget--) { s->failed_pc=0x0c073bc8u; return 0; }
write(ram,r[15]+12,r[11],4);
goto P_0c073bca;
P_0c073bca: /* original 6ba3, guest PC 0x0c073bca */
if(!s->budget--) { s->failed_pc=0x0c073bcau; return 0; }
r[11]=r[10];
goto P_0c073bcc;
P_0c073bcc: /* original 6352, guest PC 0x0c073bcc */
if(!s->budget--) { s->failed_pc=0x0c073bccu; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c073bce;
P_0c073bce: /* original 1f35, guest PC 0x0c073bce */
if(!s->budget--) { s->failed_pc=0x0c073bceu; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c073bd0;
P_0c073bd0: /* original 53f4, guest PC 0x0c073bd0 */
if(!s->budget--) { s->failed_pc=0x0c073bd0u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c073bd2;
P_0c073bd2: /* original f408, guest PC 0x0c073bd2 */
if(!s->budget--) { s->failed_pc=0x0c073bd2u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c073bd4;
P_0c073bd4: /* original 3d30, guest PC 0x0c073bd4 */
if(!s->budget--) { s->failed_pc=0x0c073bd4u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c073bd6;
P_0c073bd6: /* original 8d2b, guest PC 0x0c073bd6 */
if(!s->budget--) { s->failed_pc=0x0c073bd6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[10]=tmp;
if(cond) { goto P_0c073c30; }
goto P_0c073bda;
P_0c073bd8: /* original 6a62, guest PC 0x0c073bd8 */
if(!s->budget--) { s->failed_pc=0x0c073bd8u; return 0; }
tmp=read(ram,r[6],4);
r[10]=tmp;
goto P_0c073bda;
P_0c073bda: /* original 53f1, guest PC 0x0c073bda */
if(!s->budget--) { s->failed_pc=0x0c073bdau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c073bdc;
P_0c073bdc: /* original 52f3, guest PC 0x0c073bdc */
if(!s->budget--) { s->failed_pc=0x0c073bdcu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c073bde;
P_0c073bde: /* original f538, guest PC 0x0c073bde */
if(!s->budget--) { s->failed_pc=0x0c073bdeu; return 0; }
vf3_matrix_load(s,ram,5,r[3]);
goto P_0c073be0;
P_0c073be0: /* original 61f2, guest PC 0x0c073be0 */
if(!s->budget--) { s->failed_pc=0x0c073be0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c073be2;
P_0c073be2: /* original 22e8, guest PC 0x0c073be2 */
if(!s->budget--) { s->failed_pc=0x0c073be2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c073be4;
P_0c073be4: /* original 8d01, guest PC 0x0c073be4 */
if(!s->budget--) { s->failed_pc=0x0c073be4u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[1]);
if(cond) { goto P_0c073bea; }
goto P_0c073be8;
P_0c073be6: /* original f618, guest PC 0x0c073be6 */
if(!s->budget--) { s->failed_pc=0x0c073be6u; return 0; }
vf3_matrix_load(s,ram,6,r[1]);
goto P_0c073be8;
P_0c073be8: /* original f642, guest PC 0x0c073be8 */
if(!s->budget--) { s->failed_pc=0x0c073be8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c073bea;
P_0c073bea: /* original 52f3, guest PC 0x0c073bea */
if(!s->budget--) { s->failed_pc=0x0c073beau; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c073bec;
P_0c073bec: /* original 63b3, guest PC 0x0c073bec */
if(!s->budget--) { s->failed_pc=0x0c073becu; return 0; }
r[3]=r[11];
goto P_0c073bee;
P_0c073bee: /* original 4200, guest PC 0x0c073bee */
if(!s->budget--) { s->failed_pc=0x0c073beeu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c073bf0;
P_0c073bf0: /* original 23e8, guest PC 0x0c073bf0 */
if(!s->budget--) { s->failed_pc=0x0c073bf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[14])==0)!=0);
goto P_0c073bf2;
P_0c073bf2: /* original 8d01, guest PC 0x0c073bf2 */
if(!s->budget--) { s->failed_pc=0x0c073bf2u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[2],4);
if(cond) { goto P_0c073bf8; }
goto P_0c073bf6;
P_0c073bf4: /* original 1f23, guest PC 0x0c073bf4 */
if(!s->budget--) { s->failed_pc=0x0c073bf4u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c073bf6;
P_0c073bf6: /* original f542, guest PC 0x0c073bf6 */
if(!s->budget--) { s->failed_pc=0x0c073bf6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c073bf8;
P_0c073bf8: /* original 53fa, guest PC 0x0c073bf8 */
if(!s->budget--) { s->failed_pc=0x0c073bf8u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c073bfa;
P_0c073bfa: /* original 4b00, guest PC 0x0c073bfa */
if(!s->budget--) { s->failed_pc=0x0c073bfau; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c073bfc;
P_0c073bfc: /* original 3d30, guest PC 0x0c073bfc */
if(!s->budget--) { s->failed_pc=0x0c073bfcu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c073bfe;
P_0c073bfe: /* original 8b07, guest PC 0x0c073bfe */
if(!s->budget--) { s->failed_pc=0x0c073bfeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073c10; }
goto P_0c073c00;
P_0c073c00: /* original 51f5, guest PC 0x0c073c00 */
if(!s->budget--) { s->failed_pc=0x0c073c00u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c073c02;
P_0c073c02: /* original 21c8, guest PC 0x0c073c02 */
if(!s->budget--) { s->failed_pc=0x0c073c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c073c04;
P_0c073c04: /* original 8d01, guest PC 0x0c073c04 */
if(!s->budget--) { s->failed_pc=0x0c073c04u; return 0; }
cond=r[17]&1u;
r[2]=r[10];
if(cond) { goto P_0c073c0a; }
goto P_0c073c08;
P_0c073c06: /* original 62a3, guest PC 0x0c073c06 */
if(!s->budget--) { s->failed_pc=0x0c073c06u; return 0; }
r[2]=r[10];
goto P_0c073c08;
P_0c073c08: /* original f642, guest PC 0x0c073c08 */
if(!s->budget--) { s->failed_pc=0x0c073c08u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c073c0a;
P_0c073c0a: /* original 22c8, guest PC 0x0c073c0a */
if(!s->budget--) { s->failed_pc=0x0c073c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c073c0c;
P_0c073c0c: /* original 8900, guest PC 0x0c073c0c */
if(!s->budget--) { s->failed_pc=0x0c073c0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073c10; }
goto P_0c073c0e;
P_0c073c0e: /* original f542, guest PC 0x0c073c0e */
if(!s->budget--) { s->failed_pc=0x0c073c0eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c073c10;
P_0c073c10: /* original fd6a, guest PC 0x0c073c10 */
if(!s->budget--) { s->failed_pc=0x0c073c10u; return 0; }
vf3_matrix_store(s,ram,6,r[13]);
goto P_0c073c12;
P_0c073c12: /* original 7d04, guest PC 0x0c073c12 */
if(!s->budget--) { s->failed_pc=0x0c073c12u; return 0; }
r[13]+=0x00000004u;
goto P_0c073c14;
P_0c073c14: /* original 52f2, guest PC 0x0c073c14 */
if(!s->budget--) { s->failed_pc=0x0c073c14u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c073c16;
P_0c073c16: /* original f25a, guest PC 0x0c073c16 */
if(!s->budget--) { s->failed_pc=0x0c073c16u; return 0; }
vf3_matrix_store(s,ram,5,r[2]);
goto P_0c073c18;
P_0c073c18: /* original 63f2, guest PC 0x0c073c18 */
if(!s->budget--) { s->failed_pc=0x0c073c18u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c073c1a;
P_0c073c1a: /* original 7304, guest PC 0x0c073c1a */
if(!s->budget--) { s->failed_pc=0x0c073c1au; return 0; }
r[3]+=0x00000004u;
goto P_0c073c1c;
P_0c073c1c: /* original 2f32, guest PC 0x0c073c1c */
if(!s->budget--) { s->failed_pc=0x0c073c1cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c073c1e;
P_0c073c1e: /* original 52f1, guest PC 0x0c073c1e */
if(!s->budget--) { s->failed_pc=0x0c073c1eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c073c20;
P_0c073c20: /* original 7204, guest PC 0x0c073c20 */
if(!s->budget--) { s->failed_pc=0x0c073c20u; return 0; }
r[2]+=0x00000004u;
goto P_0c073c22;
P_0c073c22: /* original 1f21, guest PC 0x0c073c22 */
if(!s->budget--) { s->failed_pc=0x0c073c22u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c073c24;
P_0c073c24: /* original 51f2, guest PC 0x0c073c24 */
if(!s->budget--) { s->failed_pc=0x0c073c24u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c073c26;
P_0c073c26: /* original 7104, guest PC 0x0c073c26 */
if(!s->budget--) { s->failed_pc=0x0c073c26u; return 0; }
r[1]+=0x00000004u;
goto P_0c073c28;
P_0c073c28: /* original 1f12, guest PC 0x0c073c28 */
if(!s->budget--) { s->failed_pc=0x0c073c28u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c073c2a;
P_0c073c2a: /* original 53f4, guest PC 0x0c073c2a */
if(!s->budget--) { s->failed_pc=0x0c073c2au; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c073c2c;
P_0c073c2c: /* original 3d30, guest PC 0x0c073c2c */
if(!s->budget--) { s->failed_pc=0x0c073c2cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c073c2e;
P_0c073c2e: /* original 8bd4, guest PC 0x0c073c2e */
if(!s->budget--) { s->failed_pc=0x0c073c2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073bda; }
goto P_0c073c30;
P_0c073c30: /* original 9d3a, guest PC 0x0c073c30 */
if(!s->budget--) { s->failed_pc=0x0c073c30u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca8u,2);
goto P_0c073c32;
P_0c073c32: /* original 3d6c, guest PC 0x0c073c32 */
if(!s->budget--) { s->failed_pc=0x0c073c32u; return 0; }
r[13]+=r[6];
goto P_0c073c34;
P_0c073c34: /* original 6cd3, guest PC 0x0c073c34 */
if(!s->budget--) { s->failed_pc=0x0c073c34u; return 0; }
r[12]=r[13];
goto P_0c073c36;
P_0c073c36: /* original 7c70, guest PC 0x0c073c36 */
if(!s->budget--) { s->failed_pc=0x0c073c36u; return 0; }
r[12]+=0x00000070u;
goto P_0c073c38;
P_0c073c38: /* original 3dc0, guest PC 0x0c073c38 */
if(!s->budget--) { s->failed_pc=0x0c073c38u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[12])!=0);
goto P_0c073c3a;
P_0c073c3a: /* original 8903, guest PC 0x0c073c3a */
if(!s->budget--) { s->failed_pc=0x0c073c3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073c44; }
goto P_0c073c3c;
P_0c073c3c: /* original 2d72, guest PC 0x0c073c3c */
if(!s->budget--) { s->failed_pc=0x0c073c3cu; return 0; }
write(ram,r[13],r[7],4);
goto P_0c073c3e;
P_0c073c3e: /* original 7d04, guest PC 0x0c073c3e */
if(!s->budget--) { s->failed_pc=0x0c073c3eu; return 0; }
r[13]+=0x00000004u;
goto P_0c073c40;
P_0c073c40: /* original 3dc0, guest PC 0x0c073c40 */
if(!s->budget--) { s->failed_pc=0x0c073c40u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[12])!=0);
goto P_0c073c42;
P_0c073c42: /* original 8bfb, guest PC 0x0c073c42 */
if(!s->budget--) { s->failed_pc=0x0c073c42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073c3c; }
goto P_0c073c44;
P_0c073c44: /* original 9031, guest PC 0x0c073c44 */
if(!s->budget--) { s->failed_pc=0x0c073c44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073caau,2);
goto P_0c073c46;
P_0c073c46: /* original 9331, guest PC 0x0c073c46 */
if(!s->budget--) { s->failed_pc=0x0c073c46u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073cacu,2);
goto P_0c073c48;
P_0c073c48: /* original 0b5e, guest PC 0x0c073c48 */
if(!s->budget--) { s->failed_pc=0x0c073c48u; return 0; }
r[11]=read(ram,r[5]+r[0],4);
goto P_0c073c4a;
P_0c073c4a: /* original 33bc, guest PC 0x0c073c4a */
if(!s->budget--) { s->failed_pc=0x0c073c4au; return 0; }
r[3]+=r[11];
goto P_0c073c4c;
P_0c073c4c: /* original 1f3f, guest PC 0x0c073c4c */
if(!s->budget--) { s->failed_pc=0x0c073c4cu; return 0; }
write(ram,r[15]+60,r[3],4);
goto P_0c073c4e;
P_0c073c4e: /* original 902e, guest PC 0x0c073c4e */
if(!s->budget--) { s->failed_pc=0x0c073c4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073caeu,2);
goto P_0c073c50;
P_0c073c50: /* original 025e, guest PC 0x0c073c50 */
if(!s->budget--) { s->failed_pc=0x0c073c50u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c073c52;
P_0c073c52: /* original 1f21, guest PC 0x0c073c52 */
if(!s->budget--) { s->failed_pc=0x0c073c52u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c073c54;
P_0c073c54: /* original 9327, guest PC 0x0c073c54 */
if(!s->budget--) { s->failed_pc=0x0c073c54u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca6u,2);
goto P_0c073c56;
P_0c073c56: /* original 335c, guest PC 0x0c073c56 */
if(!s->budget--) { s->failed_pc=0x0c073c56u; return 0; }
r[3]+=r[5];
goto P_0c073c58;
P_0c073c58: /* original 1f3d, guest PC 0x0c073c58 */
if(!s->budget--) { s->failed_pc=0x0c073c58u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c073c5a;
P_0c073c5a: /* original 9225, guest PC 0x0c073c5a */
if(!s->budget--) { s->failed_pc=0x0c073c5au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca8u,2);
goto P_0c073c5c;
P_0c073c5c: /* original 325c, guest PC 0x0c073c5c */
if(!s->budget--) { s->failed_pc=0x0c073c5cu; return 0; }
r[2]+=r[5];
goto P_0c073c5e;
P_0c073c5e: /* original 1f25, guest PC 0x0c073c5e */
if(!s->budget--) { s->failed_pc=0x0c073c5eu; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c073c60;
P_0c073c60: /* original a174, guest PC 0x0c073c60 */
if(!s->budget--) { s->failed_pc=0x0c073c60u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c073f4c;
P_0c073c62: /* original 2fe2, guest PC 0x0c073c62 */
if(!s->budget--) { s->failed_pc=0x0c073c62u; return 0; }
write(ram,r[15],r[14],4);
goto P_0c073c64;
P_0c073c64: /* original e004, guest PC 0x0c073c64 */
if(!s->budget--) { s->failed_pc=0x0c073c64u; return 0; }
r[0]=0x00000004u;
goto P_0c073c66;
P_0c073c66: /* original f9b8, guest PC 0x0c073c66 */
if(!s->budget--) { s->failed_pc=0x0c073c66u; return 0; }
vf3_matrix_load(s,ram,9,r[11]);
goto P_0c073c68;
P_0c073c68: /* original fbb6, guest PC 0x0c073c68 */
if(!s->budget--) { s->failed_pc=0x0c073c68u; return 0; }
vf3_matrix_load(s,ram,11,r[11]+r[0]);
goto P_0c073c6a;
P_0c073c6a: /* original e008, guest PC 0x0c073c6a */
if(!s->budget--) { s->failed_pc=0x0c073c6au; return 0; }
r[0]=0x00000008u;
goto P_0c073c6c;
P_0c073c6c: /* original f3b6, guest PC 0x0c073c6c */
if(!s->budget--) { s->failed_pc=0x0c073c6cu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c073c6e;
P_0c073c6e: /* original e018, guest PC 0x0c073c6e */
if(!s->budget--) { s->failed_pc=0x0c073c6eu; return 0; }
r[0]=0x00000018u;
goto P_0c073c70;
P_0c073c70: /* original ff37, guest PC 0x0c073c70 */
if(!s->budget--) { s->failed_pc=0x0c073c70u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073c72;
P_0c073c72: /* original e004, guest PC 0x0c073c72 */
if(!s->budget--) { s->failed_pc=0x0c073c72u; return 0; }
r[0]=0x00000004u;
goto P_0c073c74;
P_0c073c74: /* original 5af1, guest PC 0x0c073c74 */
if(!s->budget--) { s->failed_pc=0x0c073c74u; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c073c76;
P_0c073c76: /* original ffa6, guest PC 0x0c073c76 */
if(!s->budget--) { s->failed_pc=0x0c073c76u; return 0; }
vf3_matrix_load(s,ram,15,r[10]+r[0]);
goto P_0c073c78;
P_0c073c78: /* original e008, guest PC 0x0c073c78 */
if(!s->budget--) { s->failed_pc=0x0c073c78u; return 0; }
r[0]=0x00000008u;
goto P_0c073c7a;
P_0c073c7a: /* original f3a6, guest PC 0x0c073c7a */
if(!s->budget--) { s->failed_pc=0x0c073c7au; return 0; }
vf3_matrix_load(s,ram,3,r[10]+r[0]);
goto P_0c073c7c;
P_0c073c7c: /* original e020, guest PC 0x0c073c7c */
if(!s->budget--) { s->failed_pc=0x0c073c7cu; return 0; }
r[0]=0x00000020u;
goto P_0c073c7e;
P_0c073c7e: /* original fca8, guest PC 0x0c073c7e */
if(!s->budget--) { s->failed_pc=0x0c073c7eu; return 0; }
vf3_matrix_load(s,ram,12,r[10]);
goto P_0c073c80;
P_0c073c80: /* original ff37, guest PC 0x0c073c80 */
if(!s->budget--) { s->failed_pc=0x0c073c80u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073c82;
P_0c073c82: /* original 9311, guest PC 0x0c073c82 */
if(!s->budget--) { s->failed_pc=0x0c073c82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca8u,2);
goto P_0c073c84;
P_0c073c84: /* original 336c, guest PC 0x0c073c84 */
if(!s->budget--) { s->failed_pc=0x0c073c84u; return 0; }
r[3]+=r[6];
goto P_0c073c86;
P_0c073c86: /* original 1f32, guest PC 0x0c073c86 */
if(!s->budget--) { s->failed_pc=0x0c073c86u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c073c88;
P_0c073c88: /* original 9c0d, guest PC 0x0c073c88 */
if(!s->budget--) { s->failed_pc=0x0c073c88u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ca6u,2);
goto P_0c073c8a;
P_0c073c8a: /* original 3c6c, guest PC 0x0c073c8a */
if(!s->budget--) { s->failed_pc=0x0c073c8au; return 0; }
r[12]+=r[6];
goto P_0c073c8c;
P_0c073c8c: /* original 63c3, guest PC 0x0c073c8c */
if(!s->budget--) { s->failed_pc=0x0c073c8cu; return 0; }
r[3]=r[12];
goto P_0c073c8e;
P_0c073c8e: /* original 7370, guest PC 0x0c073c8e */
if(!s->budget--) { s->failed_pc=0x0c073c8eu; return 0; }
r[3]+=0x00000070u;
goto P_0c073c90;
P_0c073c90: /* original 1f3a, guest PC 0x0c073c90 */
if(!s->budget--) { s->failed_pc=0x0c073c90u; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c073c92;
P_0c073c92: /* original 900a, guest PC 0x0c073c92 */
if(!s->budget--) { s->failed_pc=0x0c073c92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073caau,2);
goto P_0c073c94;
P_0c073c94: /* original 52fd, guest PC 0x0c073c94 */
if(!s->budget--) { s->failed_pc=0x0c073c94u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c073c96;
P_0c073c96: /* original 0d6e, guest PC 0x0c073c96 */
if(!s->budget--) { s->failed_pc=0x0c073c96u; return 0; }
r[13]=read(ram,r[6]+r[0],4);
goto P_0c073c98;
P_0c073c98: /* original 7004, guest PC 0x0c073c98 */
if(!s->budget--) { s->failed_pc=0x0c073c98u; return 0; }
r[0]+=0x00000004u;
goto P_0c073c9a;
P_0c073c9a: /* original 056e, guest PC 0x0c073c9a */
if(!s->budget--) { s->failed_pc=0x0c073c9au; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c073c9c;
P_0c073c9c: /* original f528, guest PC 0x0c073c9c */
if(!s->budget--) { s->failed_pc=0x0c073c9cu; return 0; }
vf3_matrix_load(s,ram,5,r[2]);
goto P_0c073c9e;
P_0c073c9e: /* original 1f74, guest PC 0x0c073c9e */
if(!s->budget--) { s->failed_pc=0x0c073c9eu; return 0; }
write(ram,r[15]+16,r[7],4);
goto P_0c073ca0;
P_0c073ca0: /* original a13f, guest PC 0x0c073ca0 */
if(!s->budget--) { s->failed_pc=0x0c073ca0u; return 0; }
r[10]=r[7];
goto P_0c073f22;
P_0c073ca2: /* original 6a73, guest PC 0x0c073ca2 */
if(!s->budget--) { s->failed_pc=0x0c073ca2u; return 0; }
r[10]=r[7];
if(!vf3_matrix_family(0x0c073ca4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073ca4u; return 0; } return 1;
P_0c073cbc: /* original e004, guest PC 0x0c073cbc */
if(!s->budget--) { s->failed_pc=0x0c073cbcu; return 0; }
r[0]=0x00000004u;
goto P_0c073cbe;
P_0c073cbe: /* original fbf5, guest PC 0x0c073cbe */
if(!s->budget--) { s->failed_pc=0x0c073cbeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[11])>as_float(fr[15]))!=0);
goto P_0c073cc0;
P_0c073cc0: /* original fed6, guest PC 0x0c073cc0 */
if(!s->budget--) { s->failed_pc=0x0c073cc0u; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c073cc2;
P_0c073cc2: /* original e008, guest PC 0x0c073cc2 */
if(!s->budget--) { s->failed_pc=0x0c073cc2u; return 0; }
r[0]=0x00000008u;
goto P_0c073cc4;
P_0c073cc4: /* original f7d6, guest PC 0x0c073cc4 */
if(!s->budget--) { s->failed_pc=0x0c073cc4u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c073cc6;
P_0c073cc6: /* original e004, guest PC 0x0c073cc6 */
if(!s->budget--) { s->failed_pc=0x0c073cc6u; return 0; }
r[0]=0x00000004u;
goto P_0c073cc8;
P_0c073cc8: /* original f856, guest PC 0x0c073cc8 */
if(!s->budget--) { s->failed_pc=0x0c073cc8u; return 0; }
vf3_matrix_load(s,ram,8,r[5]+r[0]);
goto P_0c073cca;
P_0c073cca: /* original e008, guest PC 0x0c073cca */
if(!s->budget--) { s->failed_pc=0x0c073ccau; return 0; }
r[0]=0x00000008u;
goto P_0c073ccc;
P_0c073ccc: /* original f356, guest PC 0x0c073ccc */
if(!s->budget--) { s->failed_pc=0x0c073cccu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c073cce;
P_0c073cce: /* original e01c, guest PC 0x0c073cce */
if(!s->budget--) { s->failed_pc=0x0c073cceu; return 0; }
r[0]=0x0000001cu;
goto P_0c073cd0;
P_0c073cd0: /* original f658, guest PC 0x0c073cd0 */
if(!s->budget--) { s->failed_pc=0x0c073cd0u; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
goto P_0c073cd2;
P_0c073cd2: /* original fad8, guest PC 0x0c073cd2 */
if(!s->budget--) { s->failed_pc=0x0c073cd2u; return 0; }
vf3_matrix_load(s,ram,10,r[13]);
goto P_0c073cd4;
P_0c073cd4: /* original ff37, guest PC 0x0c073cd4 */
if(!s->budget--) { s->failed_pc=0x0c073cd4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073cd6;
P_0c073cd6: /* original 8f04, guest PC 0x0c073cd6 */
if(!s->budget--) { s->failed_pc=0x0c073cd6u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[12]);
if(!cond) { goto P_0c073ce2; }
goto P_0c073cda;
P_0c073cd8: /* original f4c8, guest PC 0x0c073cd8 */
if(!s->budget--) { s->failed_pc=0x0c073cd8u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c073cda;
P_0c073cda: /* original fdfc, guest PC 0x0c073cda */
if(!s->budget--) { s->failed_pc=0x0c073cdau; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c073cdc;
P_0c073cdc: /* original fd51, guest PC 0x0c073cdc */
if(!s->budget--) { s->failed_pc=0x0c073cdcu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'-');
goto P_0c073cde;
P_0c073cde: /* original a003, guest PC 0x0c073cde */
if(!s->budget--) { s->failed_pc=0x0c073cdeu; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c073ce8;
P_0c073ce0: /* original f3bc, guest PC 0x0c073ce0 */
if(!s->budget--) { s->failed_pc=0x0c073ce0u; return 0; }
vf3_matrix_move(s,3,11);
goto P_0c073ce2;
P_0c073ce2: /* original fdbc, guest PC 0x0c073ce2 */
if(!s->budget--) { s->failed_pc=0x0c073ce2u; return 0; }
vf3_matrix_move(s,13,11);
goto P_0c073ce4;
P_0c073ce4: /* original fd51, guest PC 0x0c073ce4 */
if(!s->budget--) { s->failed_pc=0x0c073ce4u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'-');
goto P_0c073ce6;
P_0c073ce6: /* original f3fc, guest PC 0x0c073ce6 */
if(!s->budget--) { s->failed_pc=0x0c073ce6u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c073ce8;
P_0c073ce8: /* original fe85, guest PC 0x0c073ce8 */
if(!s->budget--) { s->failed_pc=0x0c073ce8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[8]))!=0);
goto P_0c073cea;
P_0c073cea: /* original e058, guest PC 0x0c073cea */
if(!s->budget--) { s->failed_pc=0x0c073ceau; return 0; }
r[0]=0x00000058u;
goto P_0c073cec;
P_0c073cec: /* original f350, guest PC 0x0c073cec */
if(!s->budget--) { s->failed_pc=0x0c073cecu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'+');
goto P_0c073cee;
P_0c073cee: /* original 8f06, guest PC 0x0c073cee */
if(!s->budget--) { s->failed_pc=0x0c073ceeu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[15]+r[0]);
if(!cond) { goto P_0c073cfe; }
goto P_0c073cf2;
P_0c073cf0: /* original ff37, guest PC 0x0c073cf0 */
if(!s->budget--) { s->failed_pc=0x0c073cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073cf2;
P_0c073cf2: /* original f38c, guest PC 0x0c073cf2 */
if(!s->budget--) { s->failed_pc=0x0c073cf2u; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c073cf4;
P_0c073cf4: /* original f341, guest PC 0x0c073cf4 */
if(!s->budget--) { s->failed_pc=0x0c073cf4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c073cf6;
P_0c073cf6: /* original e048, guest PC 0x0c073cf6 */
if(!s->budget--) { s->failed_pc=0x0c073cf6u; return 0; }
r[0]=0x00000048u;
goto P_0c073cf8;
P_0c073cf8: /* original ff37, guest PC 0x0c073cf8 */
if(!s->budget--) { s->failed_pc=0x0c073cf8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073cfa;
P_0c073cfa: /* original a005, guest PC 0x0c073cfa */
if(!s->budget--) { s->failed_pc=0x0c073cfau; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c073d08;
P_0c073cfc: /* original f2ec, guest PC 0x0c073cfc */
if(!s->budget--) { s->failed_pc=0x0c073cfcu; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c073cfe;
P_0c073cfe: /* original f3ec, guest PC 0x0c073cfe */
if(!s->budget--) { s->failed_pc=0x0c073cfeu; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c073d00;
P_0c073d00: /* original f341, guest PC 0x0c073d00 */
if(!s->budget--) { s->failed_pc=0x0c073d00u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c073d02;
P_0c073d02: /* original e048, guest PC 0x0c073d02 */
if(!s->budget--) { s->failed_pc=0x0c073d02u; return 0; }
r[0]=0x00000048u;
goto P_0c073d04;
P_0c073d04: /* original ff37, guest PC 0x0c073d04 */
if(!s->budget--) { s->failed_pc=0x0c073d04u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073d06;
P_0c073d06: /* original f28c, guest PC 0x0c073d06 */
if(!s->budget--) { s->failed_pc=0x0c073d06u; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c073d08;
P_0c073d08: /* original f240, guest PC 0x0c073d08 */
if(!s->budget--) { s->failed_pc=0x0c073d08u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c073d0a;
P_0c073d0a: /* original e044, guest PC 0x0c073d0a */
if(!s->budget--) { s->failed_pc=0x0c073d0au; return 0; }
r[0]=0x00000044u;
goto P_0c073d0c;
P_0c073d0c: /* original ff27, guest PC 0x0c073d0c */
if(!s->budget--) { s->failed_pc=0x0c073d0cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c073d0e;
P_0c073d0e: /* original e048, guest PC 0x0c073d0e */
if(!s->budget--) { s->failed_pc=0x0c073d0eu; return 0; }
r[0]=0x00000048u;
goto P_0c073d10;
P_0c073d10: /* original f3f6, guest PC 0x0c073d10 */
if(!s->budget--) { s->failed_pc=0x0c073d10u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073d12;
P_0c073d12: /* original e058, guest PC 0x0c073d12 */
if(!s->budget--) { s->failed_pc=0x0c073d12u; return 0; }
r[0]=0x00000058u;
goto P_0c073d14;
P_0c073d14: /* original f2f6, guest PC 0x0c073d14 */
if(!s->budget--) { s->failed_pc=0x0c073d14u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c073d16;
P_0c073d16: /* original f325, guest PC 0x0c073d16 */
if(!s->budget--) { s->failed_pc=0x0c073d16u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c073d18;
P_0c073d18: /* original 8b01, guest PC 0x0c073d18 */
if(!s->budget--) { s->failed_pc=0x0c073d18u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073d1e; }
goto P_0c073d1a;
P_0c073d1a: /* original a0fb, guest PC 0x0c073d1a */
if(!s->budget--) { s->failed_pc=0x0c073d1au; return 0; }
goto P_0c073f14;
P_0c073d1c: /* original 0009, guest PC 0x0c073d1c */
if(!s->budget--) { s->failed_pc=0x0c073d1cu; return 0; }
goto P_0c073d1e;
P_0c073d1e: /* original e044, guest PC 0x0c073d1e */
if(!s->budget--) { s->failed_pc=0x0c073d1eu; return 0; }
r[0]=0x00000044u;
goto P_0c073d20;
P_0c073d20: /* original f3f6, guest PC 0x0c073d20 */
if(!s->budget--) { s->failed_pc=0x0c073d20u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073d22;
P_0c073d22: /* original fd35, guest PC 0x0c073d22 */
if(!s->budget--) { s->failed_pc=0x0c073d22u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[13])>as_float(fr[3]))!=0);
goto P_0c073d24;
P_0c073d24: /* original 8b01, guest PC 0x0c073d24 */
if(!s->budget--) { s->failed_pc=0x0c073d24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073d2a; }
goto P_0c073d26;
P_0c073d26: /* original a0f5, guest PC 0x0c073d26 */
if(!s->budget--) { s->failed_pc=0x0c073d26u; return 0; }
goto P_0c073f14;
P_0c073d28: /* original 0009, guest PC 0x0c073d28 */
if(!s->budget--) { s->failed_pc=0x0c073d28u; return 0; }
goto P_0c073d2a;
P_0c073d2a: /* original f9c5, guest PC 0x0c073d2a */
if(!s->budget--) { s->failed_pc=0x0c073d2au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[9])>as_float(fr[12]))!=0);
goto P_0c073d2c;
P_0c073d2c: /* original 8b05, guest PC 0x0c073d2c */
if(!s->budget--) { s->failed_pc=0x0c073d2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073d3a; }
goto P_0c073d2e;
P_0c073d2e: /* original f3cc, guest PC 0x0c073d2e */
if(!s->budget--) { s->failed_pc=0x0c073d2eu; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c073d30;
P_0c073d30: /* original f351, guest PC 0x0c073d30 */
if(!s->budget--) { s->failed_pc=0x0c073d30u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c073d32;
P_0c073d32: /* original e05c, guest PC 0x0c073d32 */
if(!s->budget--) { s->failed_pc=0x0c073d32u; return 0; }
r[0]=0x0000005cu;
goto P_0c073d34;
P_0c073d34: /* original ff37, guest PC 0x0c073d34 */
if(!s->budget--) { s->failed_pc=0x0c073d34u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073d36;
P_0c073d36: /* original a005, guest PC 0x0c073d36 */
if(!s->budget--) { s->failed_pc=0x0c073d36u; return 0; }
vf3_matrix_move(s,13,9);
goto P_0c073d44;
P_0c073d38: /* original fd9c, guest PC 0x0c073d38 */
if(!s->budget--) { s->failed_pc=0x0c073d38u; return 0; }
vf3_matrix_move(s,13,9);
goto P_0c073d3a;
P_0c073d3a: /* original f39c, guest PC 0x0c073d3a */
if(!s->budget--) { s->failed_pc=0x0c073d3au; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c073d3c;
P_0c073d3c: /* original f351, guest PC 0x0c073d3c */
if(!s->budget--) { s->failed_pc=0x0c073d3cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c073d3e;
P_0c073d3e: /* original e05c, guest PC 0x0c073d3e */
if(!s->budget--) { s->failed_pc=0x0c073d3eu; return 0; }
r[0]=0x0000005cu;
goto P_0c073d40;
P_0c073d40: /* original ff37, guest PC 0x0c073d40 */
if(!s->budget--) { s->failed_pc=0x0c073d40u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073d42;
P_0c073d42: /* original fdcc, guest PC 0x0c073d42 */
if(!s->budget--) { s->failed_pc=0x0c073d42u; return 0; }
vf3_matrix_move(s,13,12);
goto P_0c073d44;
P_0c073d44: /* original fa65, guest PC 0x0c073d44 */
if(!s->budget--) { s->failed_pc=0x0c073d44u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[6]))!=0);
goto P_0c073d46;
P_0c073d46: /* original 8f06, guest PC 0x0c073d46 */
if(!s->budget--) { s->failed_pc=0x0c073d46u; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
if(!cond) { goto P_0c073d56; }
goto P_0c073d4a;
P_0c073d48: /* original fd50, guest PC 0x0c073d48 */
if(!s->budget--) { s->failed_pc=0x0c073d48u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
goto P_0c073d4a;
P_0c073d4a: /* original f36c, guest PC 0x0c073d4a */
if(!s->budget--) { s->failed_pc=0x0c073d4au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c073d4c;
P_0c073d4c: /* original f341, guest PC 0x0c073d4c */
if(!s->budget--) { s->failed_pc=0x0c073d4cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c073d4e;
P_0c073d4e: /* original e064, guest PC 0x0c073d4e */
if(!s->budget--) { s->failed_pc=0x0c073d4eu; return 0; }
r[0]=0x00000064u;
goto P_0c073d50;
P_0c073d50: /* original ff37, guest PC 0x0c073d50 */
if(!s->budget--) { s->failed_pc=0x0c073d50u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073d52;
P_0c073d52: /* original a005, guest PC 0x0c073d52 */
if(!s->budget--) { s->failed_pc=0x0c073d52u; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c073d60;
P_0c073d54: /* original f2ac, guest PC 0x0c073d54 */
if(!s->budget--) { s->failed_pc=0x0c073d54u; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c073d56;
P_0c073d56: /* original f3ac, guest PC 0x0c073d56 */
if(!s->budget--) { s->failed_pc=0x0c073d56u; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c073d58;
P_0c073d58: /* original f341, guest PC 0x0c073d58 */
if(!s->budget--) { s->failed_pc=0x0c073d58u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c073d5a;
P_0c073d5a: /* original e064, guest PC 0x0c073d5a */
if(!s->budget--) { s->failed_pc=0x0c073d5au; return 0; }
r[0]=0x00000064u;
goto P_0c073d5c;
P_0c073d5c: /* original ff37, guest PC 0x0c073d5c */
if(!s->budget--) { s->failed_pc=0x0c073d5cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073d5e;
P_0c073d5e: /* original f26c, guest PC 0x0c073d5e */
if(!s->budget--) { s->failed_pc=0x0c073d5eu; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c073d60;
P_0c073d60: /* original f240, guest PC 0x0c073d60 */
if(!s->budget--) { s->failed_pc=0x0c073d60u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'+');
goto P_0c073d62;
P_0c073d62: /* original e060, guest PC 0x0c073d62 */
if(!s->budget--) { s->failed_pc=0x0c073d62u; return 0; }
r[0]=0x00000060u;
goto P_0c073d64;
P_0c073d64: /* original ff27, guest PC 0x0c073d64 */
if(!s->budget--) { s->failed_pc=0x0c073d64u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c073d66;
P_0c073d66: /* original e064, guest PC 0x0c073d66 */
if(!s->budget--) { s->failed_pc=0x0c073d66u; return 0; }
r[0]=0x00000064u;
goto P_0c073d68;
P_0c073d68: /* original f3f6, guest PC 0x0c073d68 */
if(!s->budget--) { s->failed_pc=0x0c073d68u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073d6a;
P_0c073d6a: /* original f3d5, guest PC 0x0c073d6a */
if(!s->budget--) { s->failed_pc=0x0c073d6au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[13]))!=0);
goto P_0c073d6c;
P_0c073d6c: /* original 8b01, guest PC 0x0c073d6c */
if(!s->budget--) { s->failed_pc=0x0c073d6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073d72; }
goto P_0c073d6e;
P_0c073d6e: /* original a0d1, guest PC 0x0c073d6e */
if(!s->budget--) { s->failed_pc=0x0c073d6eu; return 0; }
goto P_0c073f14;
P_0c073d70: /* original 0009, guest PC 0x0c073d70 */
if(!s->budget--) { s->failed_pc=0x0c073d70u; return 0; }
goto P_0c073d72;
P_0c073d72: /* original e05c, guest PC 0x0c073d72 */
if(!s->budget--) { s->failed_pc=0x0c073d72u; return 0; }
r[0]=0x0000005cu;
goto P_0c073d74;
P_0c073d74: /* original f3f6, guest PC 0x0c073d74 */
if(!s->budget--) { s->failed_pc=0x0c073d74u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073d76;
P_0c073d76: /* original e060, guest PC 0x0c073d76 */
if(!s->budget--) { s->failed_pc=0x0c073d76u; return 0; }
r[0]=0x00000060u;
goto P_0c073d78;
P_0c073d78: /* original f2f6, guest PC 0x0c073d78 */
if(!s->budget--) { s->failed_pc=0x0c073d78u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c073d7a;
P_0c073d7a: /* original f325, guest PC 0x0c073d7a */
if(!s->budget--) { s->failed_pc=0x0c073d7au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c073d7c;
P_0c073d7c: /* original 8b01, guest PC 0x0c073d7c */
if(!s->budget--) { s->failed_pc=0x0c073d7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073d82; }
goto P_0c073d7e;
P_0c073d7e: /* original a0c9, guest PC 0x0c073d7e */
if(!s->budget--) { s->failed_pc=0x0c073d7eu; return 0; }
goto P_0c073f14;
P_0c073d80: /* original 0009, guest PC 0x0c073d80 */
if(!s->budget--) { s->failed_pc=0x0c073d80u; return 0; }
goto P_0c073d82;
P_0c073d82: /* original e018, guest PC 0x0c073d82 */
if(!s->budget--) { s->failed_pc=0x0c073d82u; return 0; }
r[0]=0x00000018u;
goto P_0c073d84;
P_0c073d84: /* original f3f6, guest PC 0x0c073d84 */
if(!s->budget--) { s->failed_pc=0x0c073d84u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073d86;
P_0c073d86: /* original e020, guest PC 0x0c073d86 */
if(!s->budget--) { s->failed_pc=0x0c073d86u; return 0; }
r[0]=0x00000020u;
goto P_0c073d88;
P_0c073d88: /* original f2f6, guest PC 0x0c073d88 */
if(!s->budget--) { s->failed_pc=0x0c073d88u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c073d8a;
P_0c073d8a: /* original f325, guest PC 0x0c073d8a */
if(!s->budget--) { s->failed_pc=0x0c073d8au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c073d8c;
P_0c073d8c: /* original 8b05, guest PC 0x0c073d8c */
if(!s->budget--) { s->failed_pc=0x0c073d8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073d9a; }
goto P_0c073d8e;
P_0c073d8e: /* original f251, guest PC 0x0c073d8e */
if(!s->budget--) { s->failed_pc=0x0c073d8eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c073d90;
P_0c073d90: /* original e04c, guest PC 0x0c073d90 */
if(!s->budget--) { s->failed_pc=0x0c073d90u; return 0; }
r[0]=0x0000004cu;
goto P_0c073d92;
P_0c073d92: /* original ff27, guest PC 0x0c073d92 */
if(!s->budget--) { s->failed_pc=0x0c073d92u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c073d94;
P_0c073d94: /* original e018, guest PC 0x0c073d94 */
if(!s->budget--) { s->failed_pc=0x0c073d94u; return 0; }
r[0]=0x00000018u;
goto P_0c073d96;
P_0c073d96: /* original a006, guest PC 0x0c073d96 */
if(!s->budget--) { s->failed_pc=0x0c073d96u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c073da6;
P_0c073d98: /* original fdf6, guest PC 0x0c073d98 */
if(!s->budget--) { s->failed_pc=0x0c073d98u; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c073d9a;
P_0c073d9a: /* original e018, guest PC 0x0c073d9a */
if(!s->budget--) { s->failed_pc=0x0c073d9au; return 0; }
r[0]=0x00000018u;
goto P_0c073d9c;
P_0c073d9c: /* original f3f6, guest PC 0x0c073d9c */
if(!s->budget--) { s->failed_pc=0x0c073d9cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073d9e;
P_0c073d9e: /* original e04c, guest PC 0x0c073d9e */
if(!s->budget--) { s->failed_pc=0x0c073d9eu; return 0; }
r[0]=0x0000004cu;
goto P_0c073da0;
P_0c073da0: /* original f351, guest PC 0x0c073da0 */
if(!s->budget--) { s->failed_pc=0x0c073da0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'-');
goto P_0c073da2;
P_0c073da2: /* original ff37, guest PC 0x0c073da2 */
if(!s->budget--) { s->failed_pc=0x0c073da2u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073da4;
P_0c073da4: /* original fd2c, guest PC 0x0c073da4 */
if(!s->budget--) { s->failed_pc=0x0c073da4u; return 0; }
vf3_matrix_move(s,13,2);
goto P_0c073da6;
P_0c073da6: /* original e01c, guest PC 0x0c073da6 */
if(!s->budget--) { s->failed_pc=0x0c073da6u; return 0; }
r[0]=0x0000001cu;
goto P_0c073da8;
P_0c073da8: /* original f3f6, guest PC 0x0c073da8 */
if(!s->budget--) { s->failed_pc=0x0c073da8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073daa;
P_0c073daa: /* original f735, guest PC 0x0c073daa */
if(!s->budget--) { s->failed_pc=0x0c073daau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c073dac;
P_0c073dac: /* original 8f05, guest PC 0x0c073dac */
if(!s->budget--) { s->failed_pc=0x0c073dacu; return 0; }
cond=r[17]&1u;
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
if(!cond) { goto P_0c073dba; }
goto P_0c073db0;
P_0c073dae: /* original fd50, guest PC 0x0c073dae */
if(!s->budget--) { s->failed_pc=0x0c073daeu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[5],r[18],'+');
goto P_0c073db0;
P_0c073db0: /* original f341, guest PC 0x0c073db0 */
if(!s->budget--) { s->failed_pc=0x0c073db0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c073db2;
P_0c073db2: /* original e054, guest PC 0x0c073db2 */
if(!s->budget--) { s->failed_pc=0x0c073db2u; return 0; }
r[0]=0x00000054u;
goto P_0c073db4;
P_0c073db4: /* original ff37, guest PC 0x0c073db4 */
if(!s->budget--) { s->failed_pc=0x0c073db4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073db6;
P_0c073db6: /* original a004, guest PC 0x0c073db6 */
if(!s->budget--) { s->failed_pc=0x0c073db6u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c073dc2;
P_0c073db8: /* original f37c, guest PC 0x0c073db8 */
if(!s->budget--) { s->failed_pc=0x0c073db8u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c073dba;
P_0c073dba: /* original f27c, guest PC 0x0c073dba */
if(!s->budget--) { s->failed_pc=0x0c073dbau; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c073dbc;
P_0c073dbc: /* original f241, guest PC 0x0c073dbc */
if(!s->budget--) { s->failed_pc=0x0c073dbcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c073dbe;
P_0c073dbe: /* original e054, guest PC 0x0c073dbe */
if(!s->budget--) { s->failed_pc=0x0c073dbeu; return 0; }
r[0]=0x00000054u;
goto P_0c073dc0;
P_0c073dc0: /* original ff27, guest PC 0x0c073dc0 */
if(!s->budget--) { s->failed_pc=0x0c073dc0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c073dc2;
P_0c073dc2: /* original f340, guest PC 0x0c073dc2 */
if(!s->budget--) { s->failed_pc=0x0c073dc2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c073dc4;
P_0c073dc4: /* original e050, guest PC 0x0c073dc4 */
if(!s->budget--) { s->failed_pc=0x0c073dc4u; return 0; }
r[0]=0x00000050u;
goto P_0c073dc6;
P_0c073dc6: /* original ff37, guest PC 0x0c073dc6 */
if(!s->budget--) { s->failed_pc=0x0c073dc6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073dc8;
P_0c073dc8: /* original e054, guest PC 0x0c073dc8 */
if(!s->budget--) { s->failed_pc=0x0c073dc8u; return 0; }
r[0]=0x00000054u;
goto P_0c073dca;
P_0c073dca: /* original f3f6, guest PC 0x0c073dca */
if(!s->budget--) { s->failed_pc=0x0c073dcau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073dcc;
P_0c073dcc: /* original f3d5, guest PC 0x0c073dcc */
if(!s->budget--) { s->failed_pc=0x0c073dccu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[13]))!=0);
goto P_0c073dce;
P_0c073dce: /* original 8b01, guest PC 0x0c073dce */
if(!s->budget--) { s->failed_pc=0x0c073dceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073dd4; }
goto P_0c073dd0;
P_0c073dd0: /* original a0a0, guest PC 0x0c073dd0 */
if(!s->budget--) { s->failed_pc=0x0c073dd0u; return 0; }
goto P_0c073f14;
P_0c073dd2: /* original 0009, guest PC 0x0c073dd2 */
if(!s->budget--) { s->failed_pc=0x0c073dd2u; return 0; }
goto P_0c073dd4;
P_0c073dd4: /* original e04c, guest PC 0x0c073dd4 */
if(!s->budget--) { s->failed_pc=0x0c073dd4u; return 0; }
r[0]=0x0000004cu;
goto P_0c073dd6;
P_0c073dd6: /* original f3f6, guest PC 0x0c073dd6 */
if(!s->budget--) { s->failed_pc=0x0c073dd6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073dd8;
P_0c073dd8: /* original e050, guest PC 0x0c073dd8 */
if(!s->budget--) { s->failed_pc=0x0c073dd8u; return 0; }
r[0]=0x00000050u;
goto P_0c073dda;
P_0c073dda: /* original f2f6, guest PC 0x0c073dda */
if(!s->budget--) { s->failed_pc=0x0c073ddau; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c073ddc;
P_0c073ddc: /* original f325, guest PC 0x0c073ddc */
if(!s->budget--) { s->failed_pc=0x0c073ddcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c073dde;
P_0c073dde: /* original 8b01, guest PC 0x0c073dde */
if(!s->budget--) { s->failed_pc=0x0c073ddeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073de4; }
goto P_0c073de0;
P_0c073de0: /* original a098, guest PC 0x0c073de0 */
if(!s->budget--) { s->failed_pc=0x0c073de0u; return 0; }
goto P_0c073f14;
P_0c073de2: /* original 0009, guest PC 0x0c073de2 */
if(!s->budget--) { s->failed_pc=0x0c073de2u; return 0; }
goto P_0c073de4;
P_0c073de4: /* original f3cc, guest PC 0x0c073de4 */
if(!s->budget--) { s->failed_pc=0x0c073de4u; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c073de6;
P_0c073de6: /* original f361, guest PC 0x0c073de6 */
if(!s->budget--) { s->failed_pc=0x0c073de6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c073de8;
P_0c073de8: /* original e024, guest PC 0x0c073de8 */
if(!s->budget--) { s->failed_pc=0x0c073de8u; return 0; }
r[0]=0x00000024u;
goto P_0c073dea;
P_0c073dea: /* original ff37, guest PC 0x0c073dea */
if(!s->budget--) { s->failed_pc=0x0c073deau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c073dec;
P_0c073dec: /* original e01c, guest PC 0x0c073dec */
if(!s->budget--) { s->failed_pc=0x0c073decu; return 0; }
r[0]=0x0000001cu;
goto P_0c073dee;
P_0c073dee: /* original f19c, guest PC 0x0c073dee */
if(!s->budget--) { s->failed_pc=0x0c073deeu; return 0; }
vf3_matrix_move(s,1,9);
goto P_0c073df0;
P_0c073df0: /* original f1a1, guest PC 0x0c073df0 */
if(!s->budget--) { s->failed_pc=0x0c073df0u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[10],r[18],'-');
goto P_0c073df2;
P_0c073df2: /* original f2f6, guest PC 0x0c073df2 */
if(!s->budget--) { s->failed_pc=0x0c073df2u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c073df4;
P_0c073df4: /* original e020, guest PC 0x0c073df4 */
if(!s->budget--) { s->failed_pc=0x0c073df4u; return 0; }
r[0]=0x00000020u;
goto P_0c073df6;
P_0c073df6: /* original fdfc, guest PC 0x0c073df6 */
if(!s->budget--) { s->failed_pc=0x0c073df6u; return 0; }
vf3_matrix_move(s,13,15);
goto P_0c073df8;
P_0c073df8: /* original fd81, guest PC 0x0c073df8 */
if(!s->budget--) { s->failed_pc=0x0c073df8u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[8],r[18],'-');
goto P_0c073dfa;
P_0c073dfa: /* original f8f6, guest PC 0x0c073dfa */
if(!s->budget--) { s->failed_pc=0x0c073dfau; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c073dfc;
P_0c073dfc: /* original e040, guest PC 0x0c073dfc */
if(!s->budget--) { s->failed_pc=0x0c073dfcu; return 0; }
r[0]=0x00000040u;
goto P_0c073dfe;
P_0c073dfe: /* original ff17, guest PC 0x0c073dfe */
if(!s->budget--) { s->failed_pc=0x0c073dfeu; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c073e00;
P_0c073e00: /* original e018, guest PC 0x0c073e00 */
if(!s->budget--) { s->failed_pc=0x0c073e00u; return 0; }
r[0]=0x00000018u;
goto P_0c073e02;
P_0c073e02: /* original fabc, guest PC 0x0c073e02 */
if(!s->budget--) { s->failed_pc=0x0c073e02u; return 0; }
vf3_matrix_move(s,10,11);
goto P_0c073e04;
P_0c073e04: /* original fae1, guest PC 0x0c073e04 */
if(!s->budget--) { s->failed_pc=0x0c073e04u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[14],r[18],'-');
goto P_0c073e06;
P_0c073e06: /* original f6f6, guest PC 0x0c073e06 */
if(!s->budget--) { s->failed_pc=0x0c073e06u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c073e08;
P_0c073e08: /* original e024, guest PC 0x0c073e08 */
if(!s->budget--) { s->failed_pc=0x0c073e08u; return 0; }
r[0]=0x00000024u;
goto P_0c073e0a;
P_0c073e0a: /* original f3f6, guest PC 0x0c073e0a */
if(!s->budget--) { s->failed_pc=0x0c073e0au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073e0c;
P_0c073e0c: /* original f821, guest PC 0x0c073e0c */
if(!s->budget--) { s->failed_pc=0x0c073e0cu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[2],r[18],'-');
goto P_0c073e0e;
P_0c073e0e: /* original f671, guest PC 0x0c073e0e */
if(!s->budget--) { s->failed_pc=0x0c073e0eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'-');
goto P_0c073e10;
P_0c073e10: /* original f71c, guest PC 0x0c073e10 */
if(!s->budget--) { s->failed_pc=0x0c073e10u; return 0; }
vf3_matrix_move(s,7,1);
goto P_0c073e12;
P_0c073e12: /* original fad1, guest PC 0x0c073e12 */
if(!s->budget--) { s->failed_pc=0x0c073e12u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[13],r[18],'-');
goto P_0c073e14;
P_0c073e14: /* original f731, guest PC 0x0c073e14 */
if(!s->budget--) { s->failed_pc=0x0c073e14u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c073e16;
P_0c073e16: /* original fe6c, guest PC 0x0c073e16 */
if(!s->budget--) { s->failed_pc=0x0c073e16u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c073e18;
P_0c073e18: /* original fe81, guest PC 0x0c073e18 */
if(!s->budget--) { s->failed_pc=0x0c073e18u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[8],r[18],'-');
goto P_0c073e1a;
P_0c073e1a: /* original f3ac, guest PC 0x0c073e1a */
if(!s->budget--) { s->failed_pc=0x0c073e1au; return 0; }
vf3_matrix_move(s,3,10);
goto P_0c073e1c;
P_0c073e1c: /* original f3a2, guest PC 0x0c073e1c */
if(!s->budget--) { s->failed_pc=0x0c073e1cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c073e1e;
P_0c073e1e: /* original f07c, guest PC 0x0c073e1e */
if(!s->budget--) { s->failed_pc=0x0c073e1eu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c073e20;
P_0c073e20: /* original f37e, guest PC 0x0c073e20 */
if(!s->budget--) { s->failed_pc=0x0c073e20u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c073e22;
P_0c073e22: /* original f0ec, guest PC 0x0c073e22 */
if(!s->budget--) { s->failed_pc=0x0c073e22u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c073e24;
P_0c073e24: /* original f3ee, guest PC 0x0c073e24 */
if(!s->budget--) { s->failed_pc=0x0c073e24u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c073e26;
P_0c073e26: /* original f08d, guest PC 0x0c073e26 */
if(!s->budget--) { s->failed_pc=0x0c073e26u; return 0; }
fr[0]=0;
goto P_0c073e28;
P_0c073e28: /* original f63c, guest PC 0x0c073e28 */
if(!s->budget--) { s->failed_pc=0x0c073e28u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c073e2a;
P_0c073e2a: /* original f064, guest PC 0x0c073e2a */
if(!s->budget--) { s->failed_pc=0x0c073e2au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[0])==as_float(fr[6]))!=0);
goto P_0c073e2c;
P_0c073e2c: /* original 8972, guest PC 0x0c073e2c */
if(!s->budget--) { s->failed_pc=0x0c073e2cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073f14; }
goto P_0c073e2e;
P_0c073e2e: /* original f35c, guest PC 0x0c073e2e */
if(!s->budget--) { s->failed_pc=0x0c073e2eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c073e30;
P_0c073e30: /* original f340, guest PC 0x0c073e30 */
if(!s->budget--) { s->failed_pc=0x0c073e30u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c073e32;
P_0c073e32: /* original e02c, guest PC 0x0c073e32 */
if(!s->budget--) { s->failed_pc=0x0c073e32u; return 0; }
r[0]=0x0000002cu;
goto P_0c073e34;
P_0c073e34: /* original f23c, guest PC 0x0c073e34 */
if(!s->budget--) { s->failed_pc=0x0c073e34u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c073e36;
P_0c073e36: /* original f232, guest PC 0x0c073e36 */
if(!s->budget--) { s->failed_pc=0x0c073e36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c073e38;
P_0c073e38: /* original ff27, guest PC 0x0c073e38 */
if(!s->budget--) { s->failed_pc=0x0c073e38u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c073e3a;
P_0c073e3a: /* original e024, guest PC 0x0c073e3a */
if(!s->budget--) { s->failed_pc=0x0c073e3au; return 0; }
r[0]=0x00000024u;
goto P_0c073e3c;
P_0c073e3c: /* original f3dc, guest PC 0x0c073e3c */
if(!s->budget--) { s->failed_pc=0x0c073e3cu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c073e3e;
P_0c073e3e: /* original f3a2, guest PC 0x0c073e3e */
if(!s->budget--) { s->failed_pc=0x0c073e3eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[10],r[18],'*');
goto P_0c073e40;
P_0c073e40: /* original f0f6, guest PC 0x0c073e40 */
if(!s->budget--) { s->failed_pc=0x0c073e40u; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c073e42;
P_0c073e42: /* original e024, guest PC 0x0c073e42 */
if(!s->budget--) { s->failed_pc=0x0c073e42u; return 0; }
r[0]=0x00000024u;
goto P_0c073e44;
P_0c073e44: /* original f16c, guest PC 0x0c073e44 */
if(!s->budget--) { s->failed_pc=0x0c073e44u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c073e46;
P_0c073e46: /* original f37e, guest PC 0x0c073e46 */
if(!s->budget--) { s->failed_pc=0x0c073e46u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[7],fr[3],r[18]);
goto P_0c073e48;
P_0c073e48: /* original f08c, guest PC 0x0c073e48 */
if(!s->budget--) { s->failed_pc=0x0c073e48u; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c073e4a;
P_0c073e4a: /* original f3ee, guest PC 0x0c073e4a */
if(!s->budget--) { s->failed_pc=0x0c073e4au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c073e4c;
P_0c073e4c: /* original f0f6, guest PC 0x0c073e4c */
if(!s->budget--) { s->failed_pc=0x0c073e4cu; return 0; }
vf3_matrix_load(s,ram,0,r[15]+r[0]);
goto P_0c073e4e;
P_0c073e4e: /* original e02c, guest PC 0x0c073e4e */
if(!s->budget--) { s->failed_pc=0x0c073e4eu; return 0; }
r[0]=0x0000002cu;
goto P_0c073e50;
P_0c073e50: /* original f20c, guest PC 0x0c073e50 */
if(!s->budget--) { s->failed_pc=0x0c073e50u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c073e52;
P_0c073e52: /* original f43c, guest PC 0x0c073e52 */
if(!s->budget--) { s->failed_pc=0x0c073e52u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c073e54;
P_0c073e54: /* original f3dc, guest PC 0x0c073e54 */
if(!s->budget--) { s->failed_pc=0x0c073e54u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c073e56;
P_0c073e56: /* original f3d2, guest PC 0x0c073e56 */
if(!s->budget--) { s->failed_pc=0x0c073e56u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[13],r[18],'*');
goto P_0c073e58;
P_0c073e58: /* original f32e, guest PC 0x0c073e58 */
if(!s->budget--) { s->failed_pc=0x0c073e58u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c073e5a;
P_0c073e5a: /* original f08c, guest PC 0x0c073e5a */
if(!s->budget--) { s->failed_pc=0x0c073e5au; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c073e5c;
P_0c073e5c: /* original f24c, guest PC 0x0c073e5c */
if(!s->budget--) { s->failed_pc=0x0c073e5cu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c073e5e;
P_0c073e5e: /* original f242, guest PC 0x0c073e5e */
if(!s->budget--) { s->failed_pc=0x0c073e5eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c073e60;
P_0c073e60: /* original f38e, guest PC 0x0c073e60 */
if(!s->budget--) { s->failed_pc=0x0c073e60u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c073e62;
P_0c073e62: /* original fa2c, guest PC 0x0c073e62 */
if(!s->budget--) { s->failed_pc=0x0c073e62u; return 0; }
vf3_matrix_move(s,10,2);
goto P_0c073e64;
P_0c073e64: /* original f73c, guest PC 0x0c073e64 */
if(!s->budget--) { s->failed_pc=0x0c073e64u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c073e66;
P_0c073e66: /* original f3f6, guest PC 0x0c073e66 */
if(!s->budget--) { s->failed_pc=0x0c073e66u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073e68;
P_0c073e68: /* original f87c, guest PC 0x0c073e68 */
if(!s->budget--) { s->failed_pc=0x0c073e68u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c073e6a;
P_0c073e6a: /* original f831, guest PC 0x0c073e6a */
if(!s->budget--) { s->failed_pc=0x0c073e6au; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[3],r[18],'-');
goto P_0c073e6c;
P_0c073e6c: /* original f182, guest PC 0x0c073e6c */
if(!s->budget--) { s->failed_pc=0x0c073e6cu; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[8],r[18],'*');
goto P_0c073e6e;
P_0c073e6e: /* original fa11, guest PC 0x0c073e6e */
if(!s->budget--) { s->failed_pc=0x0c073e6eu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[1],r[18],'-');
goto P_0c073e70;
P_0c073e70: /* original f28d, guest PC 0x0c073e70 */
if(!s->budget--) { s->failed_pc=0x0c073e70u; return 0; }
fr[2]=0;
goto P_0c073e72;
P_0c073e72: /* original f2a5, guest PC 0x0c073e72 */
if(!s->budget--) { s->failed_pc=0x0c073e72u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[10]))!=0);
goto P_0c073e74;
P_0c073e74: /* original 894e, guest PC 0x0c073e74 */
if(!s->budget--) { s->failed_pc=0x0c073e74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073f14; }
goto P_0c073e76;
P_0c073e76: /* original f38d, guest PC 0x0c073e76 */
if(!s->budget--) { s->failed_pc=0x0c073e76u; return 0; }
fr[3]=0;
goto P_0c073e78;
P_0c073e78: /* original f835, guest PC 0x0c073e78 */
if(!s->budget--) { s->failed_pc=0x0c073e78u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[3]))!=0);
goto P_0c073e7a;
P_0c073e7a: /* original fa4c, guest PC 0x0c073e7a */
if(!s->budget--) { s->failed_pc=0x0c073e7au; return 0; }
vf3_matrix_move(s,10,4);
goto P_0c073e7c;
P_0c073e7c: /* original 8f0e, guest PC 0x0c073e7c */
if(!s->budget--) { s->failed_pc=0x0c073e7cu; return 0; }
cond=r[17]&1u;
fr[10]^=0x80000000u;
if(!cond) { goto P_0c073e9c; }
goto P_0c073e80;
P_0c073e7e: /* original fa4d, guest PC 0x0c073e7e */
if(!s->budget--) { s->failed_pc=0x0c073e7eu; return 0; }
fr[10]^=0x80000000u;
goto P_0c073e80;
P_0c073e80: /* original c715, guest PC 0x0c073e80 */
if(!s->budget--) { s->failed_pc=0x0c073e80u; return 0; }
r[0]=code_base|0x00073ed8u;
goto P_0c073e82;
P_0c073e82: /* original f36c, guest PC 0x0c073e82 */
if(!s->budget--) { s->failed_pc=0x0c073e82u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c073e84;
P_0c073e84: /* original fe08, guest PC 0x0c073e84 */
if(!s->budget--) { s->failed_pc=0x0c073e84u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c073e86;
P_0c073e86: /* original f28d, guest PC 0x0c073e86 */
if(!s->budget--) { s->failed_pc=0x0c073e86u; return 0; }
fr[2]=0;
goto P_0c073e88;
P_0c073e88: /* original f0ec, guest PC 0x0c073e88 */
if(!s->budget--) { s->failed_pc=0x0c073e88u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c073e8a;
P_0c073e8a: /* original f34e, guest PC 0x0c073e8a */
if(!s->budget--) { s->failed_pc=0x0c073e8au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c073e8c;
P_0c073e8c: /* original f380, guest PC 0x0c073e8c */
if(!s->budget--) { s->failed_pc=0x0c073e8cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'+');
goto P_0c073e8e;
P_0c073e8e: /* original f325, guest PC 0x0c073e8e */
if(!s->budget--) { s->failed_pc=0x0c073e8eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c073e90;
P_0c073e90: /* original 8b04, guest PC 0x0c073e90 */
if(!s->budget--) { s->failed_pc=0x0c073e90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073e9c; }
goto P_0c073e92;
P_0c073e92: /* original f38d, guest PC 0x0c073e92 */
if(!s->budget--) { s->failed_pc=0x0c073e92u; return 0; }
fr[3]=0;
goto P_0c073e94;
P_0c073e94: /* original f345, guest PC 0x0c073e94 */
if(!s->budget--) { s->failed_pc=0x0c073e94u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c073e96;
P_0c073e96: /* original 8b3d, guest PC 0x0c073e96 */
if(!s->budget--) { s->failed_pc=0x0c073e96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073f14; }
goto P_0c073e98;
P_0c073e98: /* original f6a5, guest PC 0x0c073e98 */
if(!s->budget--) { s->failed_pc=0x0c073e98u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[10]))!=0);
goto P_0c073e9a;
P_0c073e9a: /* original 8b3b, guest PC 0x0c073e9a */
if(!s->budget--) { s->failed_pc=0x0c073e9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073f14; }
goto P_0c073e9c;
P_0c073e9c: /* original 63f2, guest PC 0x0c073e9c */
if(!s->budget--) { s->failed_pc=0x0c073e9cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c073e9e;
P_0c073e9e: /* original f8ac, guest PC 0x0c073e9e */
if(!s->budget--) { s->failed_pc=0x0c073e9eu; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c073ea0;
P_0c073ea0: /* original 2388, guest PC 0x0c073ea0 */
if(!s->budget--) { s->failed_pc=0x0c073ea0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[8])==0)!=0);
goto P_0c073ea2;
P_0c073ea2: /* original 8f25, guest PC 0x0c073ea2 */
if(!s->budget--) { s->failed_pc=0x0c073ea2u; return 0; }
cond=r[17]&1u;
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
if(!cond) { goto P_0c073ef0; }
goto P_0c073ea6;
P_0c073ea4: /* original f863, guest PC 0x0c073ea4 */
if(!s->budget--) { s->failed_pc=0x0c073ea4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'/');
goto P_0c073ea6;
P_0c073ea6: /* original 6193, guest PC 0x0c073ea6 */
if(!s->budget--) { s->failed_pc=0x0c073ea6u; return 0; }
r[1]=r[9];
goto P_0c073ea8;
P_0c073ea8: /* original 41ad, guest PC 0x0c073ea8 */
if(!s->budget--) { s->failed_pc=0x0c073ea8u; return 0; }
r[1]=(r[10]&0x80000000u)?((r[10]&31u)?r[1]>>((-r[10])&31u):0):r[1]<<(r[10]&31u);
goto P_0c073eaa;
P_0c073eaa: /* original 21e8, guest PC 0x0c073eaa */
if(!s->budget--) { s->failed_pc=0x0c073eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c073eac;
P_0c073eac: /* original 8b20, guest PC 0x0c073eac */
if(!s->budget--) { s->failed_pc=0x0c073eacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073ef0; }
goto P_0c073eae;
P_0c073eae: /* original f38d, guest PC 0x0c073eae */
if(!s->budget--) { s->failed_pc=0x0c073eaeu; return 0; }
fr[3]=0;
goto P_0c073eb0;
P_0c073eb0: /* original f835, guest PC 0x0c073eb0 */
if(!s->budget--) { s->failed_pc=0x0c073eb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[3]))!=0);
goto P_0c073eb2;
P_0c073eb2: /* original 8901, guest PC 0x0c073eb2 */
if(!s->budget--) { s->failed_pc=0x0c073eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073eb8; }
goto P_0c073eb4;
P_0c073eb4: /* original a009, guest PC 0x0c073eb4 */
if(!s->budget--) { s->failed_pc=0x0c073eb4u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c073eca;
P_0c073eb6: /* original f67c, guest PC 0x0c073eb6 */
if(!s->budget--) { s->failed_pc=0x0c073eb6u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c073eb8;
P_0c073eb8: /* original f69d, guest PC 0x0c073eb8 */
if(!s->budget--) { s->failed_pc=0x0c073eb8u; return 0; }
fr[6]=0x3f800000u;
goto P_0c073eba;
P_0c073eba: /* original f685, guest PC 0x0c073eba */
if(!s->budget--) { s->failed_pc=0x0c073ebau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[8]))!=0);
goto P_0c073ebc;
P_0c073ebc: /* original 8902, guest PC 0x0c073ebc */
if(!s->budget--) { s->failed_pc=0x0c073ebcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073ec4; }
goto P_0c073ebe;
P_0c073ebe: /* original f64c, guest PC 0x0c073ebe */
if(!s->budget--) { s->failed_pc=0x0c073ebeu; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c073ec0;
P_0c073ec0: /* original a003, guest PC 0x0c073ec0 */
if(!s->budget--) { s->failed_pc=0x0c073ec0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c073eca;
P_0c073ec2: /* original f670, guest PC 0x0c073ec2 */
if(!s->budget--) { s->failed_pc=0x0c073ec2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'+');
goto P_0c073ec4;
P_0c073ec4: /* original f04c, guest PC 0x0c073ec4 */
if(!s->budget--) { s->failed_pc=0x0c073ec4u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c073ec6;
P_0c073ec6: /* original f78e, guest PC 0x0c073ec6 */
if(!s->budget--) { s->failed_pc=0x0c073ec6u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[8],fr[7],r[18]);
goto P_0c073ec8;
P_0c073ec8: /* original f67c, guest PC 0x0c073ec8 */
if(!s->budget--) { s->failed_pc=0x0c073ec8u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c073eca;
P_0c073eca: /* original c704, guest PC 0x0c073eca */
if(!s->budget--) { s->failed_pc=0x0c073ecau; return 0; }
r[0]=code_base|0x00073edcu;
goto P_0c073ecc;
P_0c073ecc: /* original f408, guest PC 0x0c073ecc */
if(!s->budget--) { s->failed_pc=0x0c073eccu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c073ece;
P_0c073ece: /* original f465, guest PC 0x0c073ece */
if(!s->budget--) { s->failed_pc=0x0c073eceu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c073ed0;
P_0c073ed0: /* original 8b06, guest PC 0x0c073ed0 */
if(!s->budget--) { s->failed_pc=0x0c073ed0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c073ee0; }
goto P_0c073ed2;
P_0c073ed2: /* original a007, guest PC 0x0c073ed2 */
if(!s->budget--) { s->failed_pc=0x0c073ed2u; return 0; }
fr[4]=0;
goto P_0c073ee4;
P_0c073ed4: /* original f48d, guest PC 0x0c073ed4 */
if(!s->budget--) { s->failed_pc=0x0c073ed4u; return 0; }
fr[4]=0;
if(!vf3_matrix_family(0x0c073ed6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c073ed6u; return 0; } return 1;
P_0c073ee0: /* original f46c, guest PC 0x0c073ee0 */
if(!s->budget--) { s->failed_pc=0x0c073ee0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c073ee2;
P_0c073ee2: /* original f46d, guest PC 0x0c073ee2 */
if(!s->budget--) { s->failed_pc=0x0c073ee2u; return 0; }
fr[4]=vf3_fpu_sqrt(fr[4],r[18]);
goto P_0c073ee4;
P_0c073ee4: /* original e030, guest PC 0x0c073ee4 */
if(!s->budget--) { s->failed_pc=0x0c073ee4u; return 0; }
r[0]=0x00000030u;
goto P_0c073ee6;
P_0c073ee6: /* original f3f6, guest PC 0x0c073ee6 */
if(!s->budget--) { s->failed_pc=0x0c073ee6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073ee8;
P_0c073ee8: /* original f345, guest PC 0x0c073ee8 */
if(!s->budget--) { s->failed_pc=0x0c073ee8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c073eea;
P_0c073eea: /* original 8901, guest PC 0x0c073eea */
if(!s->budget--) { s->failed_pc=0x0c073eeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073ef0; }
goto P_0c073eec;
P_0c073eec: /* original e030, guest PC 0x0c073eec */
if(!s->budget--) { s->failed_pc=0x0c073eecu; return 0; }
r[0]=0x00000030u;
goto P_0c073eee;
P_0c073eee: /* original ff47, guest PC 0x0c073eee */
if(!s->budget--) { s->failed_pc=0x0c073eeeu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c073ef0;
P_0c073ef0: /* original 62e3, guest PC 0x0c073ef0 */
if(!s->budget--) { s->failed_pc=0x0c073ef0u; return 0; }
r[2]=r[14];
goto P_0c073ef2;
P_0c073ef2: /* original 63ab, guest PC 0x0c073ef2 */
if(!s->budget--) { s->failed_pc=0x0c073ef2u; return 0; }
r[3]=0u-r[10];
goto P_0c073ef4;
P_0c073ef4: /* original 423d, guest PC 0x0c073ef4 */
if(!s->budget--) { s->failed_pc=0x0c073ef4u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c073ef6;
P_0c073ef6: /* original 1f23, guest PC 0x0c073ef6 */
if(!s->budget--) { s->failed_pc=0x0c073ef6u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c073ef8;
P_0c073ef8: /* original 53f2, guest PC 0x0c073ef8 */
if(!s->budget--) { s->failed_pc=0x0c073ef8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c073efa;
P_0c073efa: /* original 61f2, guest PC 0x0c073efa */
if(!s->budget--) { s->failed_pc=0x0c073efau; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c073efc;
P_0c073efc: /* original 6032, guest PC 0x0c073efc */
if(!s->budget--) { s->failed_pc=0x0c073efcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c073efe;
P_0c073efe: /* original 201b, guest PC 0x0c073efe */
if(!s->budget--) { s->failed_pc=0x0c073efeu; return 0; }
r[0]|=r[1];
goto P_0c073f00;
P_0c073f00: /* original 2302, guest PC 0x0c073f00 */
if(!s->budget--) { s->failed_pc=0x0c073f00u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c073f02;
P_0c073f02: /* original e038, guest PC 0x0c073f02 */
if(!s->budget--) { s->failed_pc=0x0c073f02u; return 0; }
r[0]=0x00000038u;
goto P_0c073f04;
P_0c073f04: /* original 53f3, guest PC 0x0c073f04 */
if(!s->budget--) { s->failed_pc=0x0c073f04u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c073f06;
P_0c073f06: /* original 52f4, guest PC 0x0c073f06 */
if(!s->budget--) { s->failed_pc=0x0c073f06u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c073f08;
P_0c073f08: /* original 223b, guest PC 0x0c073f08 */
if(!s->budget--) { s->failed_pc=0x0c073f08u; return 0; }
r[2]|=r[3];
goto P_0c073f0a;
P_0c073f0a: /* original 1f24, guest PC 0x0c073f0a */
if(!s->budget--) { s->failed_pc=0x0c073f0au; return 0; }
write(ram,r[15]+16,r[2],4);
goto P_0c073f0c;
P_0c073f0c: /* original 01fc, guest PC 0x0c073f0c */
if(!s->budget--) { s->failed_pc=0x0c073f0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c073f0e;
P_0c073f0e: /* original e038, guest PC 0x0c073f0e */
if(!s->budget--) { s->failed_pc=0x0c073f0eu; return 0; }
r[0]=0x00000038u;
goto P_0c073f10;
P_0c073f10: /* original 7101, guest PC 0x0c073f10 */
if(!s->budget--) { s->failed_pc=0x0c073f10u; return 0; }
r[1]+=0x00000001u;
goto P_0c073f12;
P_0c073f12: /* original 0f14, guest PC 0x0c073f12 */
if(!s->budget--) { s->failed_pc=0x0c073f12u; return 0; }
write(ram,r[15]+r[0],r[1],1);
goto P_0c073f14;
P_0c073f14: /* original 53f2, guest PC 0x0c073f14 */
if(!s->budget--) { s->failed_pc=0x0c073f14u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c073f16;
P_0c073f16: /* original 7c04, guest PC 0x0c073f16 */
if(!s->budget--) { s->failed_pc=0x0c073f16u; return 0; }
r[12]+=0x00000004u;
goto P_0c073f18;
P_0c073f18: /* original 7a01, guest PC 0x0c073f18 */
if(!s->budget--) { s->failed_pc=0x0c073f18u; return 0; }
r[10]+=0x00000001u;
goto P_0c073f1a;
P_0c073f1a: /* original 7304, guest PC 0x0c073f1a */
if(!s->budget--) { s->failed_pc=0x0c073f1au; return 0; }
r[3]+=0x00000004u;
goto P_0c073f1c;
P_0c073f1c: /* original 1f32, guest PC 0x0c073f1c */
if(!s->budget--) { s->failed_pc=0x0c073f1cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c073f1e;
P_0c073f1e: /* original 7d0c, guest PC 0x0c073f1e */
if(!s->budget--) { s->failed_pc=0x0c073f1eu; return 0; }
r[13]+=0x0000000cu;
goto P_0c073f20;
P_0c073f20: /* original 750c, guest PC 0x0c073f20 */
if(!s->budget--) { s->failed_pc=0x0c073f20u; return 0; }
r[5]+=0x0000000cu;
goto P_0c073f22;
P_0c073f22: /* original 52fa, guest PC 0x0c073f22 */
if(!s->budget--) { s->failed_pc=0x0c073f22u; return 0; }
r[2]=read(ram,r[15]+40,4);
goto P_0c073f24;
P_0c073f24: /* original 3c20, guest PC 0x0c073f24 */
if(!s->budget--) { s->failed_pc=0x0c073f24u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[2])!=0);
goto P_0c073f26;
P_0c073f26: /* original 8901, guest PC 0x0c073f26 */
if(!s->budget--) { s->failed_pc=0x0c073f26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073f2c; }
goto P_0c073f28;
P_0c073f28: /* original aec8, guest PC 0x0c073f28 */
if(!s->budget--) { s->failed_pc=0x0c073f28u; return 0; }
goto P_0c073cbc;
P_0c073f2a: /* original 0009, guest PC 0x0c073f2a */
if(!s->budget--) { s->failed_pc=0x0c073f2au; return 0; }
goto P_0c073f2c;
P_0c073f2c: /* original 61f2, guest PC 0x0c073f2c */
if(!s->budget--) { s->failed_pc=0x0c073f2cu; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c073f2e;
P_0c073f2e: /* original 7b0c, guest PC 0x0c073f2e */
if(!s->budget--) { s->failed_pc=0x0c073f2eu; return 0; }
r[11]+=0x0000000cu;
goto P_0c073f30;
P_0c073f30: /* original 4101, guest PC 0x0c073f30 */
if(!s->budget--) { s->failed_pc=0x0c073f30u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c073f32;
P_0c073f32: /* original 2f12, guest PC 0x0c073f32 */
if(!s->budget--) { s->failed_pc=0x0c073f32u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c073f34;
P_0c073f34: /* original 53f5, guest PC 0x0c073f34 */
if(!s->budget--) { s->failed_pc=0x0c073f34u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c073f36;
P_0c073f36: /* original 52f4, guest PC 0x0c073f36 */
if(!s->budget--) { s->failed_pc=0x0c073f36u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c073f38;
P_0c073f38: /* original 2322, guest PC 0x0c073f38 */
if(!s->budget--) { s->failed_pc=0x0c073f38u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c073f3a;
P_0c073f3a: /* original 53f1, guest PC 0x0c073f3a */
if(!s->budget--) { s->failed_pc=0x0c073f3au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c073f3c;
P_0c073f3c: /* original 730c, guest PC 0x0c073f3c */
if(!s->budget--) { s->failed_pc=0x0c073f3cu; return 0; }
r[3]+=0x0000000cu;
goto P_0c073f3e;
P_0c073f3e: /* original 1f31, guest PC 0x0c073f3e */
if(!s->budget--) { s->failed_pc=0x0c073f3eu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c073f40;
P_0c073f40: /* original 52fd, guest PC 0x0c073f40 */
if(!s->budget--) { s->failed_pc=0x0c073f40u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c073f42;
P_0c073f42: /* original 7204, guest PC 0x0c073f42 */
if(!s->budget--) { s->failed_pc=0x0c073f42u; return 0; }
r[2]+=0x00000004u;
goto P_0c073f44;
P_0c073f44: /* original 1f2d, guest PC 0x0c073f44 */
if(!s->budget--) { s->failed_pc=0x0c073f44u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c073f46;
P_0c073f46: /* original 51f5, guest PC 0x0c073f46 */
if(!s->budget--) { s->failed_pc=0x0c073f46u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c073f48;
P_0c073f48: /* original 7104, guest PC 0x0c073f48 */
if(!s->budget--) { s->failed_pc=0x0c073f48u; return 0; }
r[1]+=0x00000004u;
goto P_0c073f4a;
P_0c073f4a: /* original 1f15, guest PC 0x0c073f4a */
if(!s->budget--) { s->failed_pc=0x0c073f4au; return 0; }
write(ram,r[15]+20,r[1],4);
goto P_0c073f4c;
P_0c073f4c: /* original 53ff, guest PC 0x0c073f4c */
if(!s->budget--) { s->failed_pc=0x0c073f4cu; return 0; }
r[3]=read(ram,r[15]+60,4);
goto P_0c073f4e;
P_0c073f4e: /* original 3b30, guest PC 0x0c073f4e */
if(!s->budget--) { s->failed_pc=0x0c073f4eu; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c073f50;
P_0c073f50: /* original 8901, guest PC 0x0c073f50 */
if(!s->budget--) { s->failed_pc=0x0c073f50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c073f56; }
goto P_0c073f52;
P_0c073f52: /* original ae87, guest PC 0x0c073f52 */
if(!s->budget--) { s->failed_pc=0x0c073f52u; return 0; }
goto P_0c073c64;
P_0c073f54: /* original 0009, guest PC 0x0c073f54 */
if(!s->budget--) { s->failed_pc=0x0c073f54u; return 0; }
goto P_0c073f56;
P_0c073f56: /* original e030, guest PC 0x0c073f56 */
if(!s->budget--) { s->failed_pc=0x0c073f56u; return 0; }
r[0]=0x00000030u;
goto P_0c073f58;
P_0c073f58: /* original f3f6, guest PC 0x0c073f58 */
if(!s->budget--) { s->failed_pc=0x0c073f58u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c073f5a;
P_0c073f5a: /* original e030, guest PC 0x0c073f5a */
if(!s->budget--) { s->failed_pc=0x0c073f5au; return 0; }
r[0]=0x00000030u;
goto P_0c073f5c;
P_0c073f5c: /* original f437, guest PC 0x0c073f5c */
if(!s->budget--) { s->failed_pc=0x0c073f5cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c073f5e;
P_0c073f5e: /* original e038, guest PC 0x0c073f5e */
if(!s->budget--) { s->failed_pc=0x0c073f5eu; return 0; }
r[0]=0x00000038u;
goto P_0c073f60;
P_0c073f60: /* original 03fc, guest PC 0x0c073f60 */
if(!s->budget--) { s->failed_pc=0x0c073f60u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c073f62;
P_0c073f62: /* original e034, guest PC 0x0c073f62 */
if(!s->budget--) { s->failed_pc=0x0c073f62u; return 0; }
r[0]=0x00000034u;
goto P_0c073f64;
P_0c073f64: /* original 0434, guest PC 0x0c073f64 */
if(!s->budget--) { s->failed_pc=0x0c073f64u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c073f66;
P_0c073f66: /* original 9148, guest PC 0x0c073f66 */
if(!s->budget--) { s->failed_pc=0x0c073f66u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c073ffau,2);
goto P_0c073f68;
P_0c073f68: /* original 3f1c, guest PC 0x0c073f68 */
if(!s->budget--) { s->failed_pc=0x0c073f68u; return 0; }
r[15]+=r[1];
goto P_0c073f6a;
P_0c073f6a: /* original fcf9, guest PC 0x0c073f6a */
if(!s->budget--) { s->failed_pc=0x0c073f6au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c073f6c;
P_0c073f6c: /* original fdf9, guest PC 0x0c073f6c */
if(!s->budget--) { s->failed_pc=0x0c073f6cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c073f6e;
P_0c073f6e: /* original fef9, guest PC 0x0c073f6e */
if(!s->budget--) { s->failed_pc=0x0c073f6eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c073f70;
P_0c073f70: /* original fff9, guest PC 0x0c073f70 */
if(!s->budget--) { s->failed_pc=0x0c073f70u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c073f72;
P_0c073f72: /* original 68f6, guest PC 0x0c073f72 */
if(!s->budget--) { s->failed_pc=0x0c073f72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c073f74;
P_0c073f74: /* original 69f6, guest PC 0x0c073f74 */
if(!s->budget--) { s->failed_pc=0x0c073f74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c073f76;
P_0c073f76: /* original 6af6, guest PC 0x0c073f76 */
if(!s->budget--) { s->failed_pc=0x0c073f76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c073f78;
P_0c073f78: /* original 6bf6, guest PC 0x0c073f78 */
if(!s->budget--) { s->failed_pc=0x0c073f78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c073f7a;
P_0c073f7a: /* original 6cf6, guest PC 0x0c073f7a */
if(!s->budget--) { s->failed_pc=0x0c073f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c073f7c;
P_0c073f7c: /* original 6df6, guest PC 0x0c073f7c */
if(!s->budget--) { s->failed_pc=0x0c073f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c073f7e;
P_0c073f7e: /* original 000b, guest PC 0x0c073f7e */
if(!s->budget--) { s->failed_pc=0x0c073f7eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c073f80: /* original 6ef6, guest PC 0x0c073f80 */
if(!s->budget--) { s->failed_pc=0x0c073f80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c073f82u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
