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
int vf3_away_batch150_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b3a88u: goto P_0c0b3a88;
case 0x0c0b3a8au: goto P_0c0b3a8a;
case 0x0c0b3a8cu: goto P_0c0b3a8c;
case 0x0c0b3a8eu: goto P_0c0b3a8e;
case 0x0c0b3a90u: goto P_0c0b3a90;
case 0x0c0b3a92u: goto P_0c0b3a92;
case 0x0c0b3a94u: goto P_0c0b3a94;
case 0x0c0b3a96u: goto P_0c0b3a96;
case 0x0c0b3a98u: goto P_0c0b3a98;
case 0x0c0b3a9au: goto P_0c0b3a9a;
case 0x0c0b3a9cu: goto P_0c0b3a9c;
case 0x0c0b3a9eu: goto P_0c0b3a9e;
case 0x0c0b3aa0u: goto P_0c0b3aa0;
case 0x0c0b3aa2u: goto P_0c0b3aa2;
case 0x0c0b3aa4u: goto P_0c0b3aa4;
case 0x0c0b3aa6u: goto P_0c0b3aa6;
case 0x0c0b3aa8u: goto P_0c0b3aa8;
case 0x0c0b3aaau: goto P_0c0b3aaa;
case 0x0c0b3aacu: goto P_0c0b3aac;
case 0x0c0b3aaeu: goto P_0c0b3aae;
case 0x0c0b3ab0u: goto P_0c0b3ab0;
case 0x0c0b3ab2u: goto P_0c0b3ab2;
case 0x0c0b3ab4u: goto P_0c0b3ab4;
case 0x0c0b3ab6u: goto P_0c0b3ab6;
case 0x0c0b3ab8u: goto P_0c0b3ab8;
case 0x0c0b3abau: goto P_0c0b3aba;
case 0x0c0b3abcu: goto P_0c0b3abc;
case 0x0c0b3abeu: goto P_0c0b3abe;
case 0x0c0b3ac0u: goto P_0c0b3ac0;
case 0x0c0b3ac2u: goto P_0c0b3ac2;
case 0x0c0b3ac4u: goto P_0c0b3ac4;
case 0x0c0b3ac6u: goto P_0c0b3ac6;
case 0x0c0b3ac8u: goto P_0c0b3ac8;
case 0x0c0b3acau: goto P_0c0b3aca;
case 0x0c0b3accu: goto P_0c0b3acc;
case 0x0c0b3aceu: goto P_0c0b3ace;
case 0x0c0b3ad0u: goto P_0c0b3ad0;
case 0x0c0b3ad2u: goto P_0c0b3ad2;
case 0x0c0b3ad4u: goto P_0c0b3ad4;
case 0x0c0b3ad6u: goto P_0c0b3ad6;
case 0x0c0b3ad8u: goto P_0c0b3ad8;
case 0x0c0b3adau: goto P_0c0b3ada;
case 0x0c0b3adcu: goto P_0c0b3adc;
case 0x0c0b3adeu: goto P_0c0b3ade;
case 0x0c0b3ae0u: goto P_0c0b3ae0;
case 0x0c0b3ae2u: goto P_0c0b3ae2;
case 0x0c0b3ae4u: goto P_0c0b3ae4;
case 0x0c0b3ae6u: goto P_0c0b3ae6;
case 0x0c0b3ae8u: goto P_0c0b3ae8;
case 0x0c0b3aeau: goto P_0c0b3aea;
case 0x0c0b3aecu: goto P_0c0b3aec;
case 0x0c0b3aeeu: goto P_0c0b3aee;
case 0x0c0b3af0u: goto P_0c0b3af0;
case 0x0c0b3af2u: goto P_0c0b3af2;
case 0x0c0b3af4u: goto P_0c0b3af4;
case 0x0c0b3af6u: goto P_0c0b3af6;
case 0x0c0b3af8u: goto P_0c0b3af8;
case 0x0c0b3afau: goto P_0c0b3afa;
case 0x0c0b3afcu: goto P_0c0b3afc;
case 0x0c0b3afeu: goto P_0c0b3afe;
case 0x0c0b3b00u: goto P_0c0b3b00;
case 0x0c0b3b02u: goto P_0c0b3b02;
case 0x0c0b3b04u: goto P_0c0b3b04;
case 0x0c0b3b06u: goto P_0c0b3b06;
case 0x0c0b3b08u: goto P_0c0b3b08;
case 0x0c0b3b0au: goto P_0c0b3b0a;
case 0x0c0b3b0cu: goto P_0c0b3b0c;
case 0x0c0b3b0eu: goto P_0c0b3b0e;
case 0x0c0b3b10u: goto P_0c0b3b10;
case 0x0c0b3b12u: goto P_0c0b3b12;
case 0x0c0b3b14u: goto P_0c0b3b14;
case 0x0c0b3b16u: goto P_0c0b3b16;
case 0x0c0b3b18u: goto P_0c0b3b18;
case 0x0c0b3b1au: goto P_0c0b3b1a;
case 0x0c0b3b1cu: goto P_0c0b3b1c;
case 0x0c0b3b1eu: goto P_0c0b3b1e;
case 0x0c0b3b20u: goto P_0c0b3b20;
case 0x0c0b3b22u: goto P_0c0b3b22;
case 0x0c0b3b24u: goto P_0c0b3b24;
case 0x0c0b3b26u: goto P_0c0b3b26;
case 0x0c0b3b28u: goto P_0c0b3b28;
case 0x0c0b3b2au: goto P_0c0b3b2a;
case 0x0c0b3b2cu: goto P_0c0b3b2c;
case 0x0c0b3b2eu: goto P_0c0b3b2e;
case 0x0c0b3b30u: goto P_0c0b3b30;
case 0x0c0b3b32u: goto P_0c0b3b32;
case 0x0c0b3b34u: goto P_0c0b3b34;
case 0x0c0b3b36u: goto P_0c0b3b36;
case 0x0c0b3b38u: goto P_0c0b3b38;
case 0x0c0b3b3au: goto P_0c0b3b3a;
case 0x0c0b3b3cu: goto P_0c0b3b3c;
case 0x0c0b3b3eu: goto P_0c0b3b3e;
case 0x0c0b3b40u: goto P_0c0b3b40;
case 0x0c0b3b42u: goto P_0c0b3b42;
case 0x0c0b3b44u: goto P_0c0b3b44;
case 0x0c0b3b46u: goto P_0c0b3b46;
case 0x0c0b3b48u: goto P_0c0b3b48;
case 0x0c0b3b4au: goto P_0c0b3b4a;
case 0x0c0b3b4cu: goto P_0c0b3b4c;
case 0x0c0b3b4eu: goto P_0c0b3b4e;
case 0x0c0b3b50u: goto P_0c0b3b50;
case 0x0c0b3b52u: goto P_0c0b3b52;
case 0x0c0b3b54u: goto P_0c0b3b54;
case 0x0c0b3b56u: goto P_0c0b3b56;
case 0x0c0b3b58u: goto P_0c0b3b58;
case 0x0c0b3b5au: goto P_0c0b3b5a;
case 0x0c0b3b5cu: goto P_0c0b3b5c;
case 0x0c0b3b5eu: goto P_0c0b3b5e;
case 0x0c0b3b60u: goto P_0c0b3b60;
case 0x0c0b3b62u: goto P_0c0b3b62;
case 0x0c0b3b64u: goto P_0c0b3b64;
case 0x0c0b3b66u: goto P_0c0b3b66;
case 0x0c0b3b68u: goto P_0c0b3b68;
case 0x0c0b3b6au: goto P_0c0b3b6a;
case 0x0c0b3b6cu: goto P_0c0b3b6c;
case 0x0c0b3b6eu: goto P_0c0b3b6e;
case 0x0c0b3b70u: goto P_0c0b3b70;
case 0x0c0b3b72u: goto P_0c0b3b72;
case 0x0c0b3b74u: goto P_0c0b3b74;
case 0x0c0b3b76u: goto P_0c0b3b76;
case 0x0c0b3b78u: goto P_0c0b3b78;
case 0x0c0b3b7au: goto P_0c0b3b7a;
case 0x0c0b3b7cu: goto P_0c0b3b7c;
case 0x0c0b3b7eu: goto P_0c0b3b7e;
case 0x0c0b3b80u: goto P_0c0b3b80;
case 0x0c0b3b82u: goto P_0c0b3b82;
case 0x0c0b3b84u: goto P_0c0b3b84;
case 0x0c0b3b86u: goto P_0c0b3b86;
case 0x0c0b3b88u: goto P_0c0b3b88;
case 0x0c0b3b8au: goto P_0c0b3b8a;
case 0x0c0b3b8cu: goto P_0c0b3b8c;
case 0x0c0b3b8eu: goto P_0c0b3b8e;
case 0x0c0b3b90u: goto P_0c0b3b90;
case 0x0c0b3b92u: goto P_0c0b3b92;
case 0x0c0b3b94u: goto P_0c0b3b94;
case 0x0c0b3b96u: goto P_0c0b3b96;
case 0x0c0b3b98u: goto P_0c0b3b98;
case 0x0c0b3b9au: goto P_0c0b3b9a;
case 0x0c0b3b9cu: goto P_0c0b3b9c;
case 0x0c0b3b9eu: goto P_0c0b3b9e;
case 0x0c0b3ba0u: goto P_0c0b3ba0;
case 0x0c0b3ba2u: goto P_0c0b3ba2;
case 0x0c0b3ba4u: goto P_0c0b3ba4;
case 0x0c0b3ba6u: goto P_0c0b3ba6;
case 0x0c0b3ba8u: goto P_0c0b3ba8;
case 0x0c0b3baau: goto P_0c0b3baa;
case 0x0c0b3bacu: goto P_0c0b3bac;
case 0x0c0b3baeu: goto P_0c0b3bae;
case 0x0c0b3bb0u: goto P_0c0b3bb0;
case 0x0c0b3bb2u: goto P_0c0b3bb2;
case 0x0c0b3bb4u: goto P_0c0b3bb4;
case 0x0c0b3bb6u: goto P_0c0b3bb6;
case 0x0c0b3bb8u: goto P_0c0b3bb8;
case 0x0c0b3bbau: goto P_0c0b3bba;
case 0x0c0b3bbcu: goto P_0c0b3bbc;
case 0x0c0b3bbeu: goto P_0c0b3bbe;
case 0x0c0b3bc0u: goto P_0c0b3bc0;
case 0x0c0b3bc2u: goto P_0c0b3bc2;
case 0x0c0b3bc4u: goto P_0c0b3bc4;
case 0x0c0b3bc6u: goto P_0c0b3bc6;
case 0x0c0b3bc8u: goto P_0c0b3bc8;
case 0x0c0b3bcau: goto P_0c0b3bca;
case 0x0c0b3bccu: goto P_0c0b3bcc;
case 0x0c0b3bceu: goto P_0c0b3bce;
case 0x0c0b3bd0u: goto P_0c0b3bd0;
case 0x0c0b3bd2u: goto P_0c0b3bd2;
case 0x0c0b3bd4u: goto P_0c0b3bd4;
case 0x0c0b3bd6u: goto P_0c0b3bd6;
case 0x0c0b3bd8u: goto P_0c0b3bd8;
case 0x0c0b3bdau: goto P_0c0b3bda;
case 0x0c0b3bdcu: goto P_0c0b3bdc;
case 0x0c0b3bdeu: goto P_0c0b3bde;
case 0x0c0b3be0u: goto P_0c0b3be0;
case 0x0c0b3be2u: goto P_0c0b3be2;
case 0x0c0b3be4u: goto P_0c0b3be4;
case 0x0c0b3be6u: goto P_0c0b3be6;
case 0x0c0b3be8u: goto P_0c0b3be8;
case 0x0c0b3beau: goto P_0c0b3bea;
case 0x0c0b3c5cu: goto P_0c0b3c5c;
case 0x0c0b3c5eu: goto P_0c0b3c5e;
case 0x0c0b3c60u: goto P_0c0b3c60;
case 0x0c0b3c62u: goto P_0c0b3c62;
case 0x0c0b3c64u: goto P_0c0b3c64;
case 0x0c0b3c66u: goto P_0c0b3c66;
case 0x0c0b3c68u: goto P_0c0b3c68;
case 0x0c0b3c6au: goto P_0c0b3c6a;
case 0x0c0b3c6cu: goto P_0c0b3c6c;
case 0x0c0b3c6eu: goto P_0c0b3c6e;
case 0x0c0b3c70u: goto P_0c0b3c70;
case 0x0c0b3c72u: goto P_0c0b3c72;
case 0x0c0b3c74u: goto P_0c0b3c74;
case 0x0c0b3c76u: goto P_0c0b3c76;
case 0x0c0b3c78u: goto P_0c0b3c78;
case 0x0c0b3c7au: goto P_0c0b3c7a;
case 0x0c0b3c7cu: goto P_0c0b3c7c;
case 0x0c0b3c7eu: goto P_0c0b3c7e;
case 0x0c0b3c80u: goto P_0c0b3c80;
case 0x0c0b3c82u: goto P_0c0b3c82;
case 0x0c0b3c84u: goto P_0c0b3c84;
case 0x0c0b3c86u: goto P_0c0b3c86;
case 0x0c0b3c88u: goto P_0c0b3c88;
case 0x0c0b3c8au: goto P_0c0b3c8a;
case 0x0c0b3c8cu: goto P_0c0b3c8c;
case 0x0c0b3c8eu: goto P_0c0b3c8e;
case 0x0c0b3c90u: goto P_0c0b3c90;
case 0x0c0b3c92u: goto P_0c0b3c92;
case 0x0c0b3c94u: goto P_0c0b3c94;
case 0x0c0b3c96u: goto P_0c0b3c96;
case 0x0c0b3c98u: goto P_0c0b3c98;
case 0x0c0b3c9au: goto P_0c0b3c9a;
case 0x0c0b3c9cu: goto P_0c0b3c9c;
case 0x0c0b3c9eu: goto P_0c0b3c9e;
case 0x0c0b3ca0u: goto P_0c0b3ca0;
case 0x0c0b3ca2u: goto P_0c0b3ca2;
case 0x0c0b3ca4u: goto P_0c0b3ca4;
case 0x0c0b3ca6u: goto P_0c0b3ca6;
case 0x0c0b3ca8u: goto P_0c0b3ca8;
case 0x0c0b3caau: goto P_0c0b3caa;
case 0x0c0b3cacu: goto P_0c0b3cac;
case 0x0c0b3caeu: goto P_0c0b3cae;
case 0x0c0b3cb0u: goto P_0c0b3cb0;
case 0x0c0b3cb2u: goto P_0c0b3cb2;
case 0x0c0b3cb4u: goto P_0c0b3cb4;
case 0x0c0b3cb6u: goto P_0c0b3cb6;
case 0x0c0b3cb8u: goto P_0c0b3cb8;
case 0x0c0b3cbau: goto P_0c0b3cba;
case 0x0c0b3cbcu: goto P_0c0b3cbc;
case 0x0c0b3cbeu: goto P_0c0b3cbe;
case 0x0c0b3cc0u: goto P_0c0b3cc0;
case 0x0c0b3cc2u: goto P_0c0b3cc2;
case 0x0c0b3cc4u: goto P_0c0b3cc4;
case 0x0c0b3cc6u: goto P_0c0b3cc6;
case 0x0c0b3cc8u: goto P_0c0b3cc8;
case 0x0c0b3ccau: goto P_0c0b3cca;
case 0x0c0b3cccu: goto P_0c0b3ccc;
case 0x0c0b3cceu: goto P_0c0b3cce;
case 0x0c0b3cd0u: goto P_0c0b3cd0;
case 0x0c0b3cd2u: goto P_0c0b3cd2;
case 0x0c0b3cd4u: goto P_0c0b3cd4;
case 0x0c0b3cd6u: goto P_0c0b3cd6;
case 0x0c0b3cd8u: goto P_0c0b3cd8;
case 0x0c0b3cdau: goto P_0c0b3cda;
case 0x0c0b3cdcu: goto P_0c0b3cdc;
case 0x0c0b3cdeu: goto P_0c0b3cde;
case 0x0c0b3ce0u: goto P_0c0b3ce0;
case 0x0c0b3ce2u: goto P_0c0b3ce2;
case 0x0c0b3ce4u: goto P_0c0b3ce4;
case 0x0c0b3ce6u: goto P_0c0b3ce6;
case 0x0c0b3ce8u: goto P_0c0b3ce8;
case 0x0c0b3ceau: goto P_0c0b3cea;
case 0x0c0b3cecu: goto P_0c0b3cec;
case 0x0c0b3ceeu: goto P_0c0b3cee;
case 0x0c0b3cf0u: goto P_0c0b3cf0;
case 0x0c0b3cf2u: goto P_0c0b3cf2;
case 0x0c0b3cf4u: goto P_0c0b3cf4;
case 0x0c0b3cf6u: goto P_0c0b3cf6;
case 0x0c0b3cf8u: goto P_0c0b3cf8;
case 0x0c0b3cfau: goto P_0c0b3cfa;
case 0x0c0b3cfcu: goto P_0c0b3cfc;
case 0x0c0b3cfeu: goto P_0c0b3cfe;
case 0x0c0b3d00u: goto P_0c0b3d00;
case 0x0c0b3d02u: goto P_0c0b3d02;
case 0x0c0b3d04u: goto P_0c0b3d04;
case 0x0c0b3d06u: goto P_0c0b3d06;
case 0x0c0b3d08u: goto P_0c0b3d08;
case 0x0c0b3d0au: goto P_0c0b3d0a;
case 0x0c0b3d0cu: goto P_0c0b3d0c;
case 0x0c0b3d0eu: goto P_0c0b3d0e;
case 0x0c0b3d10u: goto P_0c0b3d10;
case 0x0c0b3d12u: goto P_0c0b3d12;
case 0x0c0b3d14u: goto P_0c0b3d14;
case 0x0c0b3d16u: goto P_0c0b3d16;
case 0x0c0b3d18u: goto P_0c0b3d18;
case 0x0c0b3d1au: goto P_0c0b3d1a;
case 0x0c0b3d1cu: goto P_0c0b3d1c;
case 0x0c0b3d1eu: goto P_0c0b3d1e;
case 0x0c0b3d20u: goto P_0c0b3d20;
case 0x0c0b3d22u: goto P_0c0b3d22;
case 0x0c0b3d24u: goto P_0c0b3d24;
case 0x0c0b3d26u: goto P_0c0b3d26;
case 0x0c0b3d28u: goto P_0c0b3d28;
case 0x0c0b3d2au: goto P_0c0b3d2a;
case 0x0c0b3d2cu: goto P_0c0b3d2c;
case 0x0c0b3d2eu: goto P_0c0b3d2e;
case 0x0c0b3d30u: goto P_0c0b3d30;
case 0x0c0b3d32u: goto P_0c0b3d32;
case 0x0c0b3d34u: goto P_0c0b3d34;
case 0x0c0b3d36u: goto P_0c0b3d36;
case 0x0c0b3d38u: goto P_0c0b3d38;
case 0x0c0b3d3au: goto P_0c0b3d3a;
case 0x0c0b3d3cu: goto P_0c0b3d3c;
case 0x0c0b3d3eu: goto P_0c0b3d3e;
case 0x0c0b3d40u: goto P_0c0b3d40;
case 0x0c0b3d42u: goto P_0c0b3d42;
case 0x0c0b3d44u: goto P_0c0b3d44;
case 0x0c0b3d46u: goto P_0c0b3d46;
case 0x0c0b3d48u: goto P_0c0b3d48;
case 0x0c0b3d4au: goto P_0c0b3d4a;
case 0x0c0b3d4cu: goto P_0c0b3d4c;
case 0x0c0b3d4eu: goto P_0c0b3d4e;
case 0x0c0b3d50u: goto P_0c0b3d50;
case 0x0c0b3d52u: goto P_0c0b3d52;
case 0x0c0b3d54u: goto P_0c0b3d54;
case 0x0c0b3d56u: goto P_0c0b3d56;
case 0x0c0b3d58u: goto P_0c0b3d58;
case 0x0c0b3d5au: goto P_0c0b3d5a;
case 0x0c0b3d5cu: goto P_0c0b3d5c;
case 0x0c0b3d5eu: goto P_0c0b3d5e;
case 0x0c0b3d60u: goto P_0c0b3d60;
case 0x0c0b3d62u: goto P_0c0b3d62;
case 0x0c0b3d64u: goto P_0c0b3d64;
case 0x0c0b3d66u: goto P_0c0b3d66;
case 0x0c0b3d68u: goto P_0c0b3d68;
case 0x0c0b3d6au: goto P_0c0b3d6a;
case 0x0c0b3d6cu: goto P_0c0b3d6c;
case 0x0c0b3d6eu: goto P_0c0b3d6e;
case 0x0c0b3d70u: goto P_0c0b3d70;
case 0x0c0b3d72u: goto P_0c0b3d72;
case 0x0c0b3d74u: goto P_0c0b3d74;
case 0x0c0b3d76u: goto P_0c0b3d76;
case 0x0c0b3d78u: goto P_0c0b3d78;
case 0x0c0b3d7au: goto P_0c0b3d7a;
case 0x0c0b3d7cu: goto P_0c0b3d7c;
case 0x0c0b3d7eu: goto P_0c0b3d7e;
case 0x0c0b3d80u: goto P_0c0b3d80;
case 0x0c0b3d82u: goto P_0c0b3d82;
case 0x0c0b3d84u: goto P_0c0b3d84;
case 0x0c0b3d86u: goto P_0c0b3d86;
case 0x0c0b3d88u: goto P_0c0b3d88;
case 0x0c0b3d8au: goto P_0c0b3d8a;
case 0x0c0b3d8cu: goto P_0c0b3d8c;
case 0x0c0b3d8eu: goto P_0c0b3d8e;
case 0x0c0b3d90u: goto P_0c0b3d90;
case 0x0c0b3d92u: goto P_0c0b3d92;
case 0x0c0b3d94u: goto P_0c0b3d94;
case 0x0c0b3d96u: goto P_0c0b3d96;
case 0x0c0b3d98u: goto P_0c0b3d98;
case 0x0c0b3d9au: goto P_0c0b3d9a;
case 0x0c0b3d9cu: goto P_0c0b3d9c;
case 0x0c0b3d9eu: goto P_0c0b3d9e;
case 0x0c0b3da0u: goto P_0c0b3da0;
case 0x0c0b3da2u: goto P_0c0b3da2;
case 0x0c0b3da4u: goto P_0c0b3da4;
case 0x0c0b3da6u: goto P_0c0b3da6;
case 0x0c0b3da8u: goto P_0c0b3da8;
case 0x0c0b3daau: goto P_0c0b3daa;
case 0x0c0b3dacu: goto P_0c0b3dac;
case 0x0c0b3daeu: goto P_0c0b3dae;
case 0x0c0b3db0u: goto P_0c0b3db0;
case 0x0c0b3db2u: goto P_0c0b3db2;
case 0x0c0b3db4u: goto P_0c0b3db4;
case 0x0c0b3e2eu: goto P_0c0b3e2e;
case 0x0c0b3e30u: goto P_0c0b3e30;
case 0x0c0b3e32u: goto P_0c0b3e32;
case 0x0c0b3e34u: goto P_0c0b3e34;
case 0x0c0b3e36u: goto P_0c0b3e36;
case 0x0c0b3e38u: goto P_0c0b3e38;
case 0x0c0b3e3au: goto P_0c0b3e3a;
case 0x0c0b3e3cu: goto P_0c0b3e3c;
case 0x0c0b3e3eu: goto P_0c0b3e3e;
case 0x0c0b3e40u: goto P_0c0b3e40;
case 0x0c0b3e42u: goto P_0c0b3e42;
case 0x0c0b3e44u: goto P_0c0b3e44;
case 0x0c0b3e46u: goto P_0c0b3e46;
case 0x0c0b3e48u: goto P_0c0b3e48;
case 0x0c0b3e4au: goto P_0c0b3e4a;
case 0x0c0b3e4cu: goto P_0c0b3e4c;
case 0x0c0b3e4eu: goto P_0c0b3e4e;
case 0x0c0b3e50u: goto P_0c0b3e50;
case 0x0c0b3e52u: goto P_0c0b3e52;
case 0x0c0b3e54u: goto P_0c0b3e54;
case 0x0c0b3e56u: goto P_0c0b3e56;
case 0x0c0b3e58u: goto P_0c0b3e58;
case 0x0c0b3e5au: goto P_0c0b3e5a;
case 0x0c0b3e5cu: goto P_0c0b3e5c;
case 0x0c0b3e5eu: goto P_0c0b3e5e;
case 0x0c0b3e60u: goto P_0c0b3e60;
case 0x0c0b3e62u: goto P_0c0b3e62;
case 0x0c0b3e64u: goto P_0c0b3e64;
case 0x0c0b3e66u: goto P_0c0b3e66;
case 0x0c0b3e68u: goto P_0c0b3e68;
case 0x0c0b3e6au: goto P_0c0b3e6a;
case 0x0c0b3e6cu: goto P_0c0b3e6c;
case 0x0c0b3e6eu: goto P_0c0b3e6e;
case 0x0c0b3e70u: goto P_0c0b3e70;
case 0x0c0b3e72u: goto P_0c0b3e72;
case 0x0c0b3e74u: goto P_0c0b3e74;
case 0x0c0b3e76u: goto P_0c0b3e76;
case 0x0c0b3e78u: goto P_0c0b3e78;
case 0x0c0b3e7au: goto P_0c0b3e7a;
case 0x0c0b3e7cu: goto P_0c0b3e7c;
case 0x0c0b3e7eu: goto P_0c0b3e7e;
case 0x0c0b3e80u: goto P_0c0b3e80;
case 0x0c0b3e82u: goto P_0c0b3e82;
case 0x0c0b3e84u: goto P_0c0b3e84;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b3a88: /* original 2fe6, guest PC 0x0c0b3a88 */
if(!s->budget--) { s->failed_pc=0x0c0b3a88u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b3a8a;
P_0c0b3a8a: /* original 2fd6, guest PC 0x0c0b3a8a */
if(!s->budget--) { s->failed_pc=0x0c0b3a8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b3a8c;
P_0c0b3a8c: /* original 2fc6, guest PC 0x0c0b3a8c */
if(!s->budget--) { s->failed_pc=0x0c0b3a8cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b3a8e;
P_0c0b3a8e: /* original 2fb6, guest PC 0x0c0b3a8e */
if(!s->budget--) { s->failed_pc=0x0c0b3a8eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b3a90;
P_0c0b3a90: /* original 2fa6, guest PC 0x0c0b3a90 */
if(!s->budget--) { s->failed_pc=0x0c0b3a90u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b3a92;
P_0c0b3a92: /* original 2f96, guest PC 0x0c0b3a92 */
if(!s->budget--) { s->failed_pc=0x0c0b3a92u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b3a94;
P_0c0b3a94: /* original 4f22, guest PC 0x0c0b3a94 */
if(!s->budget--) { s->failed_pc=0x0c0b3a94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b3a96;
P_0c0b3a96: /* original 5d44, guest PC 0x0c0b3a96 */
if(!s->budget--) { s->failed_pc=0x0c0b3a96u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b3a98;
P_0c0b3a98: /* original 94a8, guest PC 0x0c0b3a98 */
if(!s->budget--) { s->failed_pc=0x0c0b3a98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3becu,2);
goto P_0c0b3a9a;
P_0c0b3a9a: /* original de6f, guest PC 0x0c0b3a9a */
if(!s->budget--) { s->failed_pc=0x0c0b3a9au; return 0; }
r[14]=read(ram,0x0c0b3c58u,4);
goto P_0c0b3a9c;
P_0c0b3a9c: /* original 7ff8, guest PC 0x0c0b3a9c */
if(!s->budget--) { s->failed_pc=0x0c0b3a9cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b3a9e;
P_0c0b3a9e: /* original 4e0b, guest PC 0x0c0b3a9e */
if(!s->budget--) { s->failed_pc=0x0c0b3a9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3aa2u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3aa2u) { target=s->pc; goto dispatch; }
goto P_0c0b3aa2;
P_0c0b3aa0: /* original 65d2, guest PC 0x0c0b3aa0 */
if(!s->budget--) { s->failed_pc=0x0c0b3aa0u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b3aa2;
P_0c0b3aa2: /* original 94a4, guest PC 0x0c0b3aa2 */
if(!s->budget--) { s->failed_pc=0x0c0b3aa2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3beeu,2);
goto P_0c0b3aa4;
P_0c0b3aa4: /* original 4e0b, guest PC 0x0c0b3aa4 */
if(!s->budget--) { s->failed_pc=0x0c0b3aa4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3aa8u;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3aa8u) { target=s->pc; goto dispatch; }
goto P_0c0b3aa8;
P_0c0b3aa6: /* original 55d1, guest PC 0x0c0b3aa6 */
if(!s->budget--) { s->failed_pc=0x0c0b3aa6u; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b3aa8;
P_0c0b3aa8: /* original 94a2, guest PC 0x0c0b3aa8 */
if(!s->budget--) { s->failed_pc=0x0c0b3aa8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bf0u,2);
goto P_0c0b3aaa;
P_0c0b3aaa: /* original 4e0b, guest PC 0x0c0b3aaa */
if(!s->budget--) { s->failed_pc=0x0c0b3aaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3aaeu;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3aaeu) { target=s->pc; goto dispatch; }
goto P_0c0b3aae;
P_0c0b3aac: /* original 55d2, guest PC 0x0c0b3aac */
if(!s->budget--) { s->failed_pc=0x0c0b3aacu; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b3aae;
P_0c0b3aae: /* original 94a0, guest PC 0x0c0b3aae */
if(!s->budget--) { s->failed_pc=0x0c0b3aaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bf2u,2);
goto P_0c0b3ab0;
P_0c0b3ab0: /* original 4e0b, guest PC 0x0c0b3ab0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ab0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ab4u;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ab4u) { target=s->pc; goto dispatch; }
goto P_0c0b3ab4;
P_0c0b3ab2: /* original 55d3, guest PC 0x0c0b3ab2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ab2u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b3ab4;
P_0c0b3ab4: /* original 949e, guest PC 0x0c0b3ab4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ab4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bf4u,2);
goto P_0c0b3ab6;
P_0c0b3ab6: /* original 4e0b, guest PC 0x0c0b3ab6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ab6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3abau;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3abau) { target=s->pc; goto dispatch; }
goto P_0c0b3aba;
P_0c0b3ab8: /* original 55d4, guest PC 0x0c0b3ab8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ab8u; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b3aba;
P_0c0b3aba: /* original 949c, guest PC 0x0c0b3aba */
if(!s->budget--) { s->failed_pc=0x0c0b3abau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bf6u,2);
goto P_0c0b3abc;
P_0c0b3abc: /* original 4e0b, guest PC 0x0c0b3abc */
if(!s->budget--) { s->failed_pc=0x0c0b3abcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ac0u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ac0u) { target=s->pc; goto dispatch; }
goto P_0c0b3ac0;
P_0c0b3abe: /* original 55d5, guest PC 0x0c0b3abe */
if(!s->budget--) { s->failed_pc=0x0c0b3abeu; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b3ac0;
P_0c0b3ac0: /* original 949a, guest PC 0x0c0b3ac0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bf8u,2);
goto P_0c0b3ac2;
P_0c0b3ac2: /* original 4e0b, guest PC 0x0c0b3ac2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ac2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ac6u;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ac6u) { target=s->pc; goto dispatch; }
goto P_0c0b3ac6;
P_0c0b3ac4: /* original 55d6, guest PC 0x0c0b3ac4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ac4u; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b3ac6;
P_0c0b3ac6: /* original 9498, guest PC 0x0c0b3ac6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ac6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bfau,2);
goto P_0c0b3ac8;
P_0c0b3ac8: /* original 4e0b, guest PC 0x0c0b3ac8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ac8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3accu;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3accu) { target=s->pc; goto dispatch; }
goto P_0c0b3acc;
P_0c0b3aca: /* original 55d7, guest PC 0x0c0b3aca */
if(!s->budget--) { s->failed_pc=0x0c0b3acau; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b3acc;
P_0c0b3acc: /* original 9496, guest PC 0x0c0b3acc */
if(!s->budget--) { s->failed_pc=0x0c0b3accu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bfcu,2);
goto P_0c0b3ace;
P_0c0b3ace: /* original 4e0b, guest PC 0x0c0b3ace */
if(!s->budget--) { s->failed_pc=0x0c0b3aceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ad2u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ad2u) { target=s->pc; goto dispatch; }
goto P_0c0b3ad2;
P_0c0b3ad0: /* original 55d8, guest PC 0x0c0b3ad0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ad0u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b3ad2;
P_0c0b3ad2: /* original 9494, guest PC 0x0c0b3ad2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ad2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3bfeu,2);
goto P_0c0b3ad4;
P_0c0b3ad4: /* original 4e0b, guest PC 0x0c0b3ad4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ad4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ad8u;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ad8u) { target=s->pc; goto dispatch; }
goto P_0c0b3ad8;
P_0c0b3ad6: /* original 55d9, guest PC 0x0c0b3ad6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ad6u; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b3ad8;
P_0c0b3ad8: /* original 9492, guest PC 0x0c0b3ad8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ad8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c00u,2);
goto P_0c0b3ada;
P_0c0b3ada: /* original 4e0b, guest PC 0x0c0b3ada */
if(!s->budget--) { s->failed_pc=0x0c0b3adau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3adeu;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3adeu) { target=s->pc; goto dispatch; }
goto P_0c0b3ade;
P_0c0b3adc: /* original 55da, guest PC 0x0c0b3adc */
if(!s->budget--) { s->failed_pc=0x0c0b3adcu; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b3ade;
P_0c0b3ade: /* original 9490, guest PC 0x0c0b3ade */
if(!s->budget--) { s->failed_pc=0x0c0b3adeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c02u,2);
goto P_0c0b3ae0;
P_0c0b3ae0: /* original 4e0b, guest PC 0x0c0b3ae0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ae0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ae4u;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ae4u) { target=s->pc; goto dispatch; }
goto P_0c0b3ae4;
P_0c0b3ae2: /* original 55db, guest PC 0x0c0b3ae2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ae2u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b3ae4;
P_0c0b3ae4: /* original 948e, guest PC 0x0c0b3ae4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ae4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c04u,2);
goto P_0c0b3ae6;
P_0c0b3ae6: /* original 4e0b, guest PC 0x0c0b3ae6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ae6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3aeau;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3aeau) { target=s->pc; goto dispatch; }
goto P_0c0b3aea;
P_0c0b3ae8: /* original 55dc, guest PC 0x0c0b3ae8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ae8u; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b3aea;
P_0c0b3aea: /* original 948c, guest PC 0x0c0b3aea */
if(!s->budget--) { s->failed_pc=0x0c0b3aeau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c06u,2);
goto P_0c0b3aec;
P_0c0b3aec: /* original 4e0b, guest PC 0x0c0b3aec */
if(!s->budget--) { s->failed_pc=0x0c0b3aecu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3af0u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3af0u) { target=s->pc; goto dispatch; }
goto P_0c0b3af0;
P_0c0b3aee: /* original 55dd, guest PC 0x0c0b3aee */
if(!s->budget--) { s->failed_pc=0x0c0b3aeeu; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b3af0;
P_0c0b3af0: /* original 948a, guest PC 0x0c0b3af0 */
if(!s->budget--) { s->failed_pc=0x0c0b3af0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c08u,2);
goto P_0c0b3af2;
P_0c0b3af2: /* original 4e0b, guest PC 0x0c0b3af2 */
if(!s->budget--) { s->failed_pc=0x0c0b3af2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3af6u;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3af6u) { target=s->pc; goto dispatch; }
goto P_0c0b3af6;
P_0c0b3af4: /* original 55de, guest PC 0x0c0b3af4 */
if(!s->budget--) { s->failed_pc=0x0c0b3af4u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b3af6;
P_0c0b3af6: /* original 9488, guest PC 0x0c0b3af6 */
if(!s->budget--) { s->failed_pc=0x0c0b3af6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c0au,2);
goto P_0c0b3af8;
P_0c0b3af8: /* original 4e0b, guest PC 0x0c0b3af8 */
if(!s->budget--) { s->failed_pc=0x0c0b3af8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3afcu;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3afcu) { target=s->pc; goto dispatch; }
goto P_0c0b3afc;
P_0c0b3afa: /* original 55df, guest PC 0x0c0b3afa */
if(!s->budget--) { s->failed_pc=0x0c0b3afau; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b3afc;
P_0c0b3afc: /* original 9486, guest PC 0x0c0b3afc */
if(!s->budget--) { s->failed_pc=0x0c0b3afcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c0cu,2);
goto P_0c0b3afe;
P_0c0b3afe: /* original e040, guest PC 0x0c0b3afe */
if(!s->budget--) { s->failed_pc=0x0c0b3afeu; return 0; }
r[0]=0x00000040u;
goto P_0c0b3b00;
P_0c0b3b00: /* original 4e0b, guest PC 0x0c0b3b00 */
if(!s->budget--) { s->failed_pc=0x0c0b3b00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b04u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b04u) { target=s->pc; goto dispatch; }
goto P_0c0b3b04;
P_0c0b3b02: /* original 05de, guest PC 0x0c0b3b02 */
if(!s->budget--) { s->failed_pc=0x0c0b3b02u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b04;
P_0c0b3b04: /* original 9483, guest PC 0x0c0b3b04 */
if(!s->budget--) { s->failed_pc=0x0c0b3b04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c0eu,2);
goto P_0c0b3b06;
P_0c0b3b06: /* original e044, guest PC 0x0c0b3b06 */
if(!s->budget--) { s->failed_pc=0x0c0b3b06u; return 0; }
r[0]=0x00000044u;
goto P_0c0b3b08;
P_0c0b3b08: /* original 4e0b, guest PC 0x0c0b3b08 */
if(!s->budget--) { s->failed_pc=0x0c0b3b08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b0cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b0cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b0c;
P_0c0b3b0a: /* original 05de, guest PC 0x0c0b3b0a */
if(!s->budget--) { s->failed_pc=0x0c0b3b0au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b0c;
P_0c0b3b0c: /* original 9480, guest PC 0x0c0b3b0c */
if(!s->budget--) { s->failed_pc=0x0c0b3b0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c10u,2);
goto P_0c0b3b0e;
P_0c0b3b0e: /* original e048, guest PC 0x0c0b3b0e */
if(!s->budget--) { s->failed_pc=0x0c0b3b0eu; return 0; }
r[0]=0x00000048u;
goto P_0c0b3b10;
P_0c0b3b10: /* original 4e0b, guest PC 0x0c0b3b10 */
if(!s->budget--) { s->failed_pc=0x0c0b3b10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b14u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b14u) { target=s->pc; goto dispatch; }
goto P_0c0b3b14;
P_0c0b3b12: /* original 05de, guest PC 0x0c0b3b12 */
if(!s->budget--) { s->failed_pc=0x0c0b3b12u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b14;
P_0c0b3b14: /* original 947d, guest PC 0x0c0b3b14 */
if(!s->budget--) { s->failed_pc=0x0c0b3b14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c12u,2);
goto P_0c0b3b16;
P_0c0b3b16: /* original e04c, guest PC 0x0c0b3b16 */
if(!s->budget--) { s->failed_pc=0x0c0b3b16u; return 0; }
r[0]=0x0000004cu;
goto P_0c0b3b18;
P_0c0b3b18: /* original 4e0b, guest PC 0x0c0b3b18 */
if(!s->budget--) { s->failed_pc=0x0c0b3b18u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b1cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b1cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b1c;
P_0c0b3b1a: /* original 05de, guest PC 0x0c0b3b1a */
if(!s->budget--) { s->failed_pc=0x0c0b3b1au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b1c;
P_0c0b3b1c: /* original 947a, guest PC 0x0c0b3b1c */
if(!s->budget--) { s->failed_pc=0x0c0b3b1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c14u,2);
goto P_0c0b3b1e;
P_0c0b3b1e: /* original e050, guest PC 0x0c0b3b1e */
if(!s->budget--) { s->failed_pc=0x0c0b3b1eu; return 0; }
r[0]=0x00000050u;
goto P_0c0b3b20;
P_0c0b3b20: /* original 4e0b, guest PC 0x0c0b3b20 */
if(!s->budget--) { s->failed_pc=0x0c0b3b20u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b24u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b24u) { target=s->pc; goto dispatch; }
goto P_0c0b3b24;
P_0c0b3b22: /* original 05de, guest PC 0x0c0b3b22 */
if(!s->budget--) { s->failed_pc=0x0c0b3b22u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b24;
P_0c0b3b24: /* original 9477, guest PC 0x0c0b3b24 */
if(!s->budget--) { s->failed_pc=0x0c0b3b24u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c16u,2);
goto P_0c0b3b26;
P_0c0b3b26: /* original e054, guest PC 0x0c0b3b26 */
if(!s->budget--) { s->failed_pc=0x0c0b3b26u; return 0; }
r[0]=0x00000054u;
goto P_0c0b3b28;
P_0c0b3b28: /* original 4e0b, guest PC 0x0c0b3b28 */
if(!s->budget--) { s->failed_pc=0x0c0b3b28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b2cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b2cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b2c;
P_0c0b3b2a: /* original 05de, guest PC 0x0c0b3b2a */
if(!s->budget--) { s->failed_pc=0x0c0b3b2au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b2c;
P_0c0b3b2c: /* original 9474, guest PC 0x0c0b3b2c */
if(!s->budget--) { s->failed_pc=0x0c0b3b2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c18u,2);
goto P_0c0b3b2e;
P_0c0b3b2e: /* original e058, guest PC 0x0c0b3b2e */
if(!s->budget--) { s->failed_pc=0x0c0b3b2eu; return 0; }
r[0]=0x00000058u;
goto P_0c0b3b30;
P_0c0b3b30: /* original 4e0b, guest PC 0x0c0b3b30 */
if(!s->budget--) { s->failed_pc=0x0c0b3b30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b34u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b34u) { target=s->pc; goto dispatch; }
goto P_0c0b3b34;
P_0c0b3b32: /* original 05de, guest PC 0x0c0b3b32 */
if(!s->budget--) { s->failed_pc=0x0c0b3b32u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b34;
P_0c0b3b34: /* original 9471, guest PC 0x0c0b3b34 */
if(!s->budget--) { s->failed_pc=0x0c0b3b34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c1au,2);
goto P_0c0b3b36;
P_0c0b3b36: /* original e05c, guest PC 0x0c0b3b36 */
if(!s->budget--) { s->failed_pc=0x0c0b3b36u; return 0; }
r[0]=0x0000005cu;
goto P_0c0b3b38;
P_0c0b3b38: /* original 4e0b, guest PC 0x0c0b3b38 */
if(!s->budget--) { s->failed_pc=0x0c0b3b38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b3cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b3c;
P_0c0b3b3a: /* original 05de, guest PC 0x0c0b3b3a */
if(!s->budget--) { s->failed_pc=0x0c0b3b3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b3c;
P_0c0b3b3c: /* original 946e, guest PC 0x0c0b3b3c */
if(!s->budget--) { s->failed_pc=0x0c0b3b3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c1cu,2);
goto P_0c0b3b3e;
P_0c0b3b3e: /* original e060, guest PC 0x0c0b3b3e */
if(!s->budget--) { s->failed_pc=0x0c0b3b3eu; return 0; }
r[0]=0x00000060u;
goto P_0c0b3b40;
P_0c0b3b40: /* original 4e0b, guest PC 0x0c0b3b40 */
if(!s->budget--) { s->failed_pc=0x0c0b3b40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b44u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b44u) { target=s->pc; goto dispatch; }
goto P_0c0b3b44;
P_0c0b3b42: /* original 05de, guest PC 0x0c0b3b42 */
if(!s->budget--) { s->failed_pc=0x0c0b3b42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b44;
P_0c0b3b44: /* original 946b, guest PC 0x0c0b3b44 */
if(!s->budget--) { s->failed_pc=0x0c0b3b44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c1eu,2);
goto P_0c0b3b46;
P_0c0b3b46: /* original e064, guest PC 0x0c0b3b46 */
if(!s->budget--) { s->failed_pc=0x0c0b3b46u; return 0; }
r[0]=0x00000064u;
goto P_0c0b3b48;
P_0c0b3b48: /* original 4e0b, guest PC 0x0c0b3b48 */
if(!s->budget--) { s->failed_pc=0x0c0b3b48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b4cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b4c;
P_0c0b3b4a: /* original 05de, guest PC 0x0c0b3b4a */
if(!s->budget--) { s->failed_pc=0x0c0b3b4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b4c;
P_0c0b3b4c: /* original 9468, guest PC 0x0c0b3b4c */
if(!s->budget--) { s->failed_pc=0x0c0b3b4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c20u,2);
goto P_0c0b3b4e;
P_0c0b3b4e: /* original e068, guest PC 0x0c0b3b4e */
if(!s->budget--) { s->failed_pc=0x0c0b3b4eu; return 0; }
r[0]=0x00000068u;
goto P_0c0b3b50;
P_0c0b3b50: /* original 4e0b, guest PC 0x0c0b3b50 */
if(!s->budget--) { s->failed_pc=0x0c0b3b50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b54u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b54u) { target=s->pc; goto dispatch; }
goto P_0c0b3b54;
P_0c0b3b52: /* original 05de, guest PC 0x0c0b3b52 */
if(!s->budget--) { s->failed_pc=0x0c0b3b52u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b54;
P_0c0b3b54: /* original 9465, guest PC 0x0c0b3b54 */
if(!s->budget--) { s->failed_pc=0x0c0b3b54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c22u,2);
goto P_0c0b3b56;
P_0c0b3b56: /* original e06c, guest PC 0x0c0b3b56 */
if(!s->budget--) { s->failed_pc=0x0c0b3b56u; return 0; }
r[0]=0x0000006cu;
goto P_0c0b3b58;
P_0c0b3b58: /* original 4e0b, guest PC 0x0c0b3b58 */
if(!s->budget--) { s->failed_pc=0x0c0b3b58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b5cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b5cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b5c;
P_0c0b3b5a: /* original 05de, guest PC 0x0c0b3b5a */
if(!s->budget--) { s->failed_pc=0x0c0b3b5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b5c;
P_0c0b3b5c: /* original 9462, guest PC 0x0c0b3b5c */
if(!s->budget--) { s->failed_pc=0x0c0b3b5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c24u,2);
goto P_0c0b3b5e;
P_0c0b3b5e: /* original e070, guest PC 0x0c0b3b5e */
if(!s->budget--) { s->failed_pc=0x0c0b3b5eu; return 0; }
r[0]=0x00000070u;
goto P_0c0b3b60;
P_0c0b3b60: /* original 4e0b, guest PC 0x0c0b3b60 */
if(!s->budget--) { s->failed_pc=0x0c0b3b60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b64u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b64u) { target=s->pc; goto dispatch; }
goto P_0c0b3b64;
P_0c0b3b62: /* original 05de, guest PC 0x0c0b3b62 */
if(!s->budget--) { s->failed_pc=0x0c0b3b62u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b64;
P_0c0b3b64: /* original 945f, guest PC 0x0c0b3b64 */
if(!s->budget--) { s->failed_pc=0x0c0b3b64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c26u,2);
goto P_0c0b3b66;
P_0c0b3b66: /* original e074, guest PC 0x0c0b3b66 */
if(!s->budget--) { s->failed_pc=0x0c0b3b66u; return 0; }
r[0]=0x00000074u;
goto P_0c0b3b68;
P_0c0b3b68: /* original 4e0b, guest PC 0x0c0b3b68 */
if(!s->budget--) { s->failed_pc=0x0c0b3b68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b6cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b6cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b6c;
P_0c0b3b6a: /* original 05de, guest PC 0x0c0b3b6a */
if(!s->budget--) { s->failed_pc=0x0c0b3b6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b6c;
P_0c0b3b6c: /* original 945c, guest PC 0x0c0b3b6c */
if(!s->budget--) { s->failed_pc=0x0c0b3b6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c28u,2);
goto P_0c0b3b6e;
P_0c0b3b6e: /* original e078, guest PC 0x0c0b3b6e */
if(!s->budget--) { s->failed_pc=0x0c0b3b6eu; return 0; }
r[0]=0x00000078u;
goto P_0c0b3b70;
P_0c0b3b70: /* original 4e0b, guest PC 0x0c0b3b70 */
if(!s->budget--) { s->failed_pc=0x0c0b3b70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b74u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b74u) { target=s->pc; goto dispatch; }
goto P_0c0b3b74;
P_0c0b3b72: /* original 05de, guest PC 0x0c0b3b72 */
if(!s->budget--) { s->failed_pc=0x0c0b3b72u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b74;
P_0c0b3b74: /* original 9459, guest PC 0x0c0b3b74 */
if(!s->budget--) { s->failed_pc=0x0c0b3b74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c2au,2);
goto P_0c0b3b76;
P_0c0b3b76: /* original e07c, guest PC 0x0c0b3b76 */
if(!s->budget--) { s->failed_pc=0x0c0b3b76u; return 0; }
r[0]=0x0000007cu;
goto P_0c0b3b78;
P_0c0b3b78: /* original 4e0b, guest PC 0x0c0b3b78 */
if(!s->budget--) { s->failed_pc=0x0c0b3b78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b7cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b7cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b7c;
P_0c0b3b7a: /* original 05de, guest PC 0x0c0b3b7a */
if(!s->budget--) { s->failed_pc=0x0c0b3b7au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b7c;
P_0c0b3b7c: /* original 9457, guest PC 0x0c0b3b7c */
if(!s->budget--) { s->failed_pc=0x0c0b3b7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c2eu,2);
goto P_0c0b3b7e;
P_0c0b3b7e: /* original 9055, guest PC 0x0c0b3b7e */
if(!s->budget--) { s->failed_pc=0x0c0b3b7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c2cu,2);
goto P_0c0b3b80;
P_0c0b3b80: /* original 4e0b, guest PC 0x0c0b3b80 */
if(!s->budget--) { s->failed_pc=0x0c0b3b80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b84u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b84u) { target=s->pc; goto dispatch; }
goto P_0c0b3b84;
P_0c0b3b82: /* original 05de, guest PC 0x0c0b3b82 */
if(!s->budget--) { s->failed_pc=0x0c0b3b82u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3b84;
P_0c0b3b84: /* original 9554, guest PC 0x0c0b3b84 */
if(!s->budget--) { s->failed_pc=0x0c0b3b84u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c30u,2);
goto P_0c0b3b86;
P_0c0b3b86: /* original 35dc, guest PC 0x0c0b3b86 */
if(!s->budget--) { s->failed_pc=0x0c0b3b86u; return 0; }
r[5]+=r[13];
goto P_0c0b3b88;
P_0c0b3b88: /* original 2f52, guest PC 0x0c0b3b88 */
if(!s->budget--) { s->failed_pc=0x0c0b3b88u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3b8a;
P_0c0b3b8a: /* original 9452, guest PC 0x0c0b3b8a */
if(!s->budget--) { s->failed_pc=0x0c0b3b8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c32u,2);
goto P_0c0b3b8c;
P_0c0b3b8c: /* original 4e0b, guest PC 0x0c0b3b8c */
if(!s->budget--) { s->failed_pc=0x0c0b3b8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b90u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b90u) { target=s->pc; goto dispatch; }
goto P_0c0b3b90;
P_0c0b3b8e: /* original 6552, guest PC 0x0c0b3b8e */
if(!s->budget--) { s->failed_pc=0x0c0b3b8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3b90;
P_0c0b3b90: /* original 9550, guest PC 0x0c0b3b90 */
if(!s->budget--) { s->failed_pc=0x0c0b3b90u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c34u,2);
goto P_0c0b3b92;
P_0c0b3b92: /* original 35dc, guest PC 0x0c0b3b92 */
if(!s->budget--) { s->failed_pc=0x0c0b3b92u; return 0; }
r[5]+=r[13];
goto P_0c0b3b94;
P_0c0b3b94: /* original 1f51, guest PC 0x0c0b3b94 */
if(!s->budget--) { s->failed_pc=0x0c0b3b94u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b3b96;
P_0c0b3b96: /* original 944e, guest PC 0x0c0b3b96 */
if(!s->budget--) { s->failed_pc=0x0c0b3b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c36u,2);
goto P_0c0b3b98;
P_0c0b3b98: /* original 4e0b, guest PC 0x0c0b3b98 */
if(!s->budget--) { s->failed_pc=0x0c0b3b98u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3b9cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3b9cu) { target=s->pc; goto dispatch; }
goto P_0c0b3b9c;
P_0c0b3b9a: /* original 6552, guest PC 0x0c0b3b9a */
if(!s->budget--) { s->failed_pc=0x0c0b3b9au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3b9c;
P_0c0b3b9c: /* original 944d, guest PC 0x0c0b3b9c */
if(!s->budget--) { s->failed_pc=0x0c0b3b9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c3au,2);
goto P_0c0b3b9e;
P_0c0b3b9e: /* original 904b, guest PC 0x0c0b3b9e */
if(!s->budget--) { s->failed_pc=0x0c0b3b9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c38u,2);
goto P_0c0b3ba0;
P_0c0b3ba0: /* original 4e0b, guest PC 0x0c0b3ba0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ba0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ba4u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ba4u) { target=s->pc; goto dispatch; }
goto P_0c0b3ba4;
P_0c0b3ba2: /* original 05de, guest PC 0x0c0b3ba2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ba2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3ba4;
P_0c0b3ba4: /* original 944b, guest PC 0x0c0b3ba4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c3eu,2);
goto P_0c0b3ba6;
P_0c0b3ba6: /* original 9049, guest PC 0x0c0b3ba6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ba6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c3cu,2);
goto P_0c0b3ba8;
P_0c0b3ba8: /* original 4e0b, guest PC 0x0c0b3ba8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ba8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bacu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bacu) { target=s->pc; goto dispatch; }
goto P_0c0b3bac;
P_0c0b3baa: /* original 05de, guest PC 0x0c0b3baa */
if(!s->budget--) { s->failed_pc=0x0c0b3baau; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3bac;
P_0c0b3bac: /* original 9948, guest PC 0x0c0b3bac */
if(!s->budget--) { s->failed_pc=0x0c0b3bacu; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c40u,2);
goto P_0c0b3bae;
P_0c0b3bae: /* original 9448, guest PC 0x0c0b3bae */
if(!s->budget--) { s->failed_pc=0x0c0b3baeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c42u,2);
goto P_0c0b3bb0;
P_0c0b3bb0: /* original 39dc, guest PC 0x0c0b3bb0 */
if(!s->budget--) { s->failed_pc=0x0c0b3bb0u; return 0; }
r[9]+=r[13];
goto P_0c0b3bb2;
P_0c0b3bb2: /* original 4e0b, guest PC 0x0c0b3bb2 */
if(!s->budget--) { s->failed_pc=0x0c0b3bb2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bb6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bb6u) { target=s->pc; goto dispatch; }
goto P_0c0b3bb6;
P_0c0b3bb4: /* original 6592, guest PC 0x0c0b3bb4 */
if(!s->budget--) { s->failed_pc=0x0c0b3bb4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3bb6;
P_0c0b3bb6: /* original 9445, guest PC 0x0c0b3bb6 */
if(!s->budget--) { s->failed_pc=0x0c0b3bb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c44u,2);
goto P_0c0b3bb8;
P_0c0b3bb8: /* original 4e0b, guest PC 0x0c0b3bb8 */
if(!s->budget--) { s->failed_pc=0x0c0b3bb8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bbcu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bbcu) { target=s->pc; goto dispatch; }
goto P_0c0b3bbc;
P_0c0b3bba: /* original 6592, guest PC 0x0c0b3bba */
if(!s->budget--) { s->failed_pc=0x0c0b3bbau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3bbc;
P_0c0b3bbc: /* original 9443, guest PC 0x0c0b3bbc */
if(!s->budget--) { s->failed_pc=0x0c0b3bbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c46u,2);
goto P_0c0b3bbe;
P_0c0b3bbe: /* original 4e0b, guest PC 0x0c0b3bbe */
if(!s->budget--) { s->failed_pc=0x0c0b3bbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bc2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bc2u) { target=s->pc; goto dispatch; }
goto P_0c0b3bc2;
P_0c0b3bc0: /* original 6592, guest PC 0x0c0b3bc0 */
if(!s->budget--) { s->failed_pc=0x0c0b3bc0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3bc2;
P_0c0b3bc2: /* original 9441, guest PC 0x0c0b3bc2 */
if(!s->budget--) { s->failed_pc=0x0c0b3bc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c48u,2);
goto P_0c0b3bc4;
P_0c0b3bc4: /* original 4e0b, guest PC 0x0c0b3bc4 */
if(!s->budget--) { s->failed_pc=0x0c0b3bc4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bc8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bc8u) { target=s->pc; goto dispatch; }
goto P_0c0b3bc8;
P_0c0b3bc6: /* original 6592, guest PC 0x0c0b3bc6 */
if(!s->budget--) { s->failed_pc=0x0c0b3bc6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3bc8;
P_0c0b3bc8: /* original 9c3f, guest PC 0x0c0b3bc8 */
if(!s->budget--) { s->failed_pc=0x0c0b3bc8u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c4au,2);
goto P_0c0b3bca;
P_0c0b3bca: /* original 943f, guest PC 0x0c0b3bca */
if(!s->budget--) { s->failed_pc=0x0c0b3bcau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c4cu,2);
goto P_0c0b3bcc;
P_0c0b3bcc: /* original 3cdc, guest PC 0x0c0b3bcc */
if(!s->budget--) { s->failed_pc=0x0c0b3bccu; return 0; }
r[12]+=r[13];
goto P_0c0b3bce;
P_0c0b3bce: /* original 4e0b, guest PC 0x0c0b3bce */
if(!s->budget--) { s->failed_pc=0x0c0b3bceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bd2u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bd2u) { target=s->pc; goto dispatch; }
goto P_0c0b3bd2;
P_0c0b3bd0: /* original 65c2, guest PC 0x0c0b3bd0 */
if(!s->budget--) { s->failed_pc=0x0c0b3bd0u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3bd2;
P_0c0b3bd2: /* original 943c, guest PC 0x0c0b3bd2 */
if(!s->budget--) { s->failed_pc=0x0c0b3bd2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c4eu,2);
goto P_0c0b3bd4;
P_0c0b3bd4: /* original 4e0b, guest PC 0x0c0b3bd4 */
if(!s->budget--) { s->failed_pc=0x0c0b3bd4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bd8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bd8u) { target=s->pc; goto dispatch; }
goto P_0c0b3bd8;
P_0c0b3bd6: /* original 65c2, guest PC 0x0c0b3bd6 */
if(!s->budget--) { s->failed_pc=0x0c0b3bd6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3bd8;
P_0c0b3bd8: /* original 943a, guest PC 0x0c0b3bd8 */
if(!s->budget--) { s->failed_pc=0x0c0b3bd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c50u,2);
goto P_0c0b3bda;
P_0c0b3bda: /* original 4e0b, guest PC 0x0c0b3bda */
if(!s->budget--) { s->failed_pc=0x0c0b3bdau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3bdeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3bdeu) { target=s->pc; goto dispatch; }
goto P_0c0b3bde;
P_0c0b3bdc: /* original 65c2, guest PC 0x0c0b3bdc */
if(!s->budget--) { s->failed_pc=0x0c0b3bdcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3bde;
P_0c0b3bde: /* original 9438, guest PC 0x0c0b3bde */
if(!s->budget--) { s->failed_pc=0x0c0b3bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c52u,2);
goto P_0c0b3be0;
P_0c0b3be0: /* original 4e0b, guest PC 0x0c0b3be0 */
if(!s->budget--) { s->failed_pc=0x0c0b3be0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3be4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3be4u) { target=s->pc; goto dispatch; }
goto P_0c0b3be4;
P_0c0b3be2: /* original 65c2, guest PC 0x0c0b3be2 */
if(!s->budget--) { s->failed_pc=0x0c0b3be2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3be4;
P_0c0b3be4: /* original 9b36, guest PC 0x0c0b3be4 */
if(!s->budget--) { s->failed_pc=0x0c0b3be4u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3c54u,2);
goto P_0c0b3be6;
P_0c0b3be6: /* original 3bdc, guest PC 0x0c0b3be6 */
if(!s->budget--) { s->failed_pc=0x0c0b3be6u; return 0; }
r[11]+=r[13];
goto P_0c0b3be8;
P_0c0b3be8: /* original a038, guest PC 0x0c0b3be8 */
if(!s->budget--) { s->failed_pc=0x0c0b3be8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3c5c;
P_0c0b3bea: /* original 65b2, guest PC 0x0c0b3bea */
if(!s->budget--) { s->failed_pc=0x0c0b3beau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b3becu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b3becu; return 0; } return 1;
P_0c0b3c5c: /* original 94ab, guest PC 0x0c0b3c5c */
if(!s->budget--) { s->failed_pc=0x0c0b3c5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3db6u,2);
goto P_0c0b3c5e;
P_0c0b3c5e: /* original 4e0b, guest PC 0x0c0b3c5e */
if(!s->budget--) { s->failed_pc=0x0c0b3c5eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c62u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c62u) { target=s->pc; goto dispatch; }
goto P_0c0b3c62;
P_0c0b3c60: /* original 0009, guest PC 0x0c0b3c60 */
if(!s->budget--) { s->failed_pc=0x0c0b3c60u; return 0; }
goto P_0c0b3c62;
P_0c0b3c62: /* original 94a9, guest PC 0x0c0b3c62 */
if(!s->budget--) { s->failed_pc=0x0c0b3c62u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3db8u,2);
goto P_0c0b3c64;
P_0c0b3c64: /* original 4e0b, guest PC 0x0c0b3c64 */
if(!s->budget--) { s->failed_pc=0x0c0b3c64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c68u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c68u) { target=s->pc; goto dispatch; }
goto P_0c0b3c68;
P_0c0b3c66: /* original 65b2, guest PC 0x0c0b3c66 */
if(!s->budget--) { s->failed_pc=0x0c0b3c66u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3c68;
P_0c0b3c68: /* original 94a7, guest PC 0x0c0b3c68 */
if(!s->budget--) { s->failed_pc=0x0c0b3c68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dbau,2);
goto P_0c0b3c6a;
P_0c0b3c6a: /* original 4e0b, guest PC 0x0c0b3c6a */
if(!s->budget--) { s->failed_pc=0x0c0b3c6au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c6eu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c6eu) { target=s->pc; goto dispatch; }
goto P_0c0b3c6e;
P_0c0b3c6c: /* original 65b2, guest PC 0x0c0b3c6c */
if(!s->budget--) { s->failed_pc=0x0c0b3c6cu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3c6e;
P_0c0b3c6e: /* original 94a5, guest PC 0x0c0b3c6e */
if(!s->budget--) { s->failed_pc=0x0c0b3c6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dbcu,2);
goto P_0c0b3c70;
P_0c0b3c70: /* original 4e0b, guest PC 0x0c0b3c70 */
if(!s->budget--) { s->failed_pc=0x0c0b3c70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c74u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c74u) { target=s->pc; goto dispatch; }
goto P_0c0b3c74;
P_0c0b3c72: /* original 65b2, guest PC 0x0c0b3c72 */
if(!s->budget--) { s->failed_pc=0x0c0b3c72u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3c74;
P_0c0b3c74: /* original 9aa3, guest PC 0x0c0b3c74 */
if(!s->budget--) { s->failed_pc=0x0c0b3c74u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dbeu,2);
goto P_0c0b3c76;
P_0c0b3c76: /* original 94a3, guest PC 0x0c0b3c76 */
if(!s->budget--) { s->failed_pc=0x0c0b3c76u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dc0u,2);
goto P_0c0b3c78;
P_0c0b3c78: /* original 3adc, guest PC 0x0c0b3c78 */
if(!s->budget--) { s->failed_pc=0x0c0b3c78u; return 0; }
r[10]+=r[13];
goto P_0c0b3c7a;
P_0c0b3c7a: /* original 4e0b, guest PC 0x0c0b3c7a */
if(!s->budget--) { s->failed_pc=0x0c0b3c7au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c7eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c7eu) { target=s->pc; goto dispatch; }
goto P_0c0b3c7e;
P_0c0b3c7c: /* original 65a2, guest PC 0x0c0b3c7c */
if(!s->budget--) { s->failed_pc=0x0c0b3c7cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3c7e;
P_0c0b3c7e: /* original 94a0, guest PC 0x0c0b3c7e */
if(!s->budget--) { s->failed_pc=0x0c0b3c7eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dc2u,2);
goto P_0c0b3c80;
P_0c0b3c80: /* original 4e0b, guest PC 0x0c0b3c80 */
if(!s->budget--) { s->failed_pc=0x0c0b3c80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c84u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c84u) { target=s->pc; goto dispatch; }
goto P_0c0b3c84;
P_0c0b3c82: /* original 65a2, guest PC 0x0c0b3c82 */
if(!s->budget--) { s->failed_pc=0x0c0b3c82u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3c84;
P_0c0b3c84: /* original 949e, guest PC 0x0c0b3c84 */
if(!s->budget--) { s->failed_pc=0x0c0b3c84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dc4u,2);
goto P_0c0b3c86;
P_0c0b3c86: /* original 4e0b, guest PC 0x0c0b3c86 */
if(!s->budget--) { s->failed_pc=0x0c0b3c86u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c8au;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c8au) { target=s->pc; goto dispatch; }
goto P_0c0b3c8a;
P_0c0b3c88: /* original 65a2, guest PC 0x0c0b3c88 */
if(!s->budget--) { s->failed_pc=0x0c0b3c88u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3c8a;
P_0c0b3c8a: /* original 949c, guest PC 0x0c0b3c8a */
if(!s->budget--) { s->failed_pc=0x0c0b3c8au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dc6u,2);
goto P_0c0b3c8c;
P_0c0b3c8c: /* original 4e0b, guest PC 0x0c0b3c8c */
if(!s->budget--) { s->failed_pc=0x0c0b3c8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c90u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c90u) { target=s->pc; goto dispatch; }
goto P_0c0b3c90;
P_0c0b3c8e: /* original 65a2, guest PC 0x0c0b3c8e */
if(!s->budget--) { s->failed_pc=0x0c0b3c8eu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3c90;
P_0c0b3c90: /* original 949a, guest PC 0x0c0b3c90 */
if(!s->budget--) { s->failed_pc=0x0c0b3c90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dc8u,2);
goto P_0c0b3c92;
P_0c0b3c92: /* original 65f2, guest PC 0x0c0b3c92 */
if(!s->budget--) { s->failed_pc=0x0c0b3c92u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3c94;
P_0c0b3c94: /* original 4e0b, guest PC 0x0c0b3c94 */
if(!s->budget--) { s->failed_pc=0x0c0b3c94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3c98u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3c98u) { target=s->pc; goto dispatch; }
goto P_0c0b3c98;
P_0c0b3c96: /* original 6552, guest PC 0x0c0b3c96 */
if(!s->budget--) { s->failed_pc=0x0c0b3c96u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3c98;
P_0c0b3c98: /* original 9497, guest PC 0x0c0b3c98 */
if(!s->budget--) { s->failed_pc=0x0c0b3c98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dcau,2);
goto P_0c0b3c9a;
P_0c0b3c9a: /* original 55f1, guest PC 0x0c0b3c9a */
if(!s->budget--) { s->failed_pc=0x0c0b3c9au; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b3c9c;
P_0c0b3c9c: /* original 4e0b, guest PC 0x0c0b3c9c */
if(!s->budget--) { s->failed_pc=0x0c0b3c9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ca0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ca0u) { target=s->pc; goto dispatch; }
goto P_0c0b3ca0;
P_0c0b3c9e: /* original 6552, guest PC 0x0c0b3c9e */
if(!s->budget--) { s->failed_pc=0x0c0b3c9eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3ca0;
P_0c0b3ca0: /* original 9494, guest PC 0x0c0b3ca0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ca0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dccu,2);
goto P_0c0b3ca2;
P_0c0b3ca2: /* original 4e0b, guest PC 0x0c0b3ca2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ca2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ca6u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ca6u) { target=s->pc; goto dispatch; }
goto P_0c0b3ca6;
P_0c0b3ca4: /* original 6592, guest PC 0x0c0b3ca4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ca4u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3ca6;
P_0c0b3ca6: /* original 9492, guest PC 0x0c0b3ca6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ca6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dceu,2);
goto P_0c0b3ca8;
P_0c0b3ca8: /* original 4e0b, guest PC 0x0c0b3ca8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ca8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cacu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cacu) { target=s->pc; goto dispatch; }
goto P_0c0b3cac;
P_0c0b3caa: /* original 6592, guest PC 0x0c0b3caa */
if(!s->budget--) { s->failed_pc=0x0c0b3caau; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3cac;
P_0c0b3cac: /* original 9490, guest PC 0x0c0b3cac */
if(!s->budget--) { s->failed_pc=0x0c0b3cacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dd0u,2);
goto P_0c0b3cae;
P_0c0b3cae: /* original 4e0b, guest PC 0x0c0b3cae */
if(!s->budget--) { s->failed_pc=0x0c0b3caeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cb2u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cb2u) { target=s->pc; goto dispatch; }
goto P_0c0b3cb2;
P_0c0b3cb0: /* original 6592, guest PC 0x0c0b3cb0 */
if(!s->budget--) { s->failed_pc=0x0c0b3cb0u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3cb2;
P_0c0b3cb2: /* original 948e, guest PC 0x0c0b3cb2 */
if(!s->budget--) { s->failed_pc=0x0c0b3cb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dd2u,2);
goto P_0c0b3cb4;
P_0c0b3cb4: /* original 4e0b, guest PC 0x0c0b3cb4 */
if(!s->budget--) { s->failed_pc=0x0c0b3cb4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cb8u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cb8u) { target=s->pc; goto dispatch; }
goto P_0c0b3cb8;
P_0c0b3cb6: /* original 6592, guest PC 0x0c0b3cb6 */
if(!s->budget--) { s->failed_pc=0x0c0b3cb6u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b3cb8;
P_0c0b3cb8: /* original 948c, guest PC 0x0c0b3cb8 */
if(!s->budget--) { s->failed_pc=0x0c0b3cb8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dd4u,2);
goto P_0c0b3cba;
P_0c0b3cba: /* original 4e0b, guest PC 0x0c0b3cba */
if(!s->budget--) { s->failed_pc=0x0c0b3cbau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cbeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cbeu) { target=s->pc; goto dispatch; }
goto P_0c0b3cbe;
P_0c0b3cbc: /* original 65c2, guest PC 0x0c0b3cbc */
if(!s->budget--) { s->failed_pc=0x0c0b3cbcu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3cbe;
P_0c0b3cbe: /* original 948a, guest PC 0x0c0b3cbe */
if(!s->budget--) { s->failed_pc=0x0c0b3cbeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dd6u,2);
goto P_0c0b3cc0;
P_0c0b3cc0: /* original 4e0b, guest PC 0x0c0b3cc0 */
if(!s->budget--) { s->failed_pc=0x0c0b3cc0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cc4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cc4u) { target=s->pc; goto dispatch; }
goto P_0c0b3cc4;
P_0c0b3cc2: /* original 65c2, guest PC 0x0c0b3cc2 */
if(!s->budget--) { s->failed_pc=0x0c0b3cc2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3cc4;
P_0c0b3cc4: /* original 9488, guest PC 0x0c0b3cc4 */
if(!s->budget--) { s->failed_pc=0x0c0b3cc4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dd8u,2);
goto P_0c0b3cc6;
P_0c0b3cc6: /* original 4e0b, guest PC 0x0c0b3cc6 */
if(!s->budget--) { s->failed_pc=0x0c0b3cc6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ccau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ccau) { target=s->pc; goto dispatch; }
goto P_0c0b3cca;
P_0c0b3cc8: /* original 65c2, guest PC 0x0c0b3cc8 */
if(!s->budget--) { s->failed_pc=0x0c0b3cc8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3cca;
P_0c0b3cca: /* original 9486, guest PC 0x0c0b3cca */
if(!s->budget--) { s->failed_pc=0x0c0b3ccau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ddau,2);
goto P_0c0b3ccc;
P_0c0b3ccc: /* original 4e0b, guest PC 0x0c0b3ccc */
if(!s->budget--) { s->failed_pc=0x0c0b3cccu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cd0u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cd0u) { target=s->pc; goto dispatch; }
goto P_0c0b3cd0;
P_0c0b3cce: /* original 65c2, guest PC 0x0c0b3cce */
if(!s->budget--) { s->failed_pc=0x0c0b3cceu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b3cd0;
P_0c0b3cd0: /* original 9484, guest PC 0x0c0b3cd0 */
if(!s->budget--) { s->failed_pc=0x0c0b3cd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ddcu,2);
goto P_0c0b3cd2;
P_0c0b3cd2: /* original 4e0b, guest PC 0x0c0b3cd2 */
if(!s->budget--) { s->failed_pc=0x0c0b3cd2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cd6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cd6u) { target=s->pc; goto dispatch; }
goto P_0c0b3cd6;
P_0c0b3cd4: /* original 65b2, guest PC 0x0c0b3cd4 */
if(!s->budget--) { s->failed_pc=0x0c0b3cd4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3cd6;
P_0c0b3cd6: /* original 9482, guest PC 0x0c0b3cd6 */
if(!s->budget--) { s->failed_pc=0x0c0b3cd6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ddeu,2);
goto P_0c0b3cd8;
P_0c0b3cd8: /* original 4e0b, guest PC 0x0c0b3cd8 */
if(!s->budget--) { s->failed_pc=0x0c0b3cd8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cdcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cdcu) { target=s->pc; goto dispatch; }
goto P_0c0b3cdc;
P_0c0b3cda: /* original 65b2, guest PC 0x0c0b3cda */
if(!s->budget--) { s->failed_pc=0x0c0b3cdau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3cdc;
P_0c0b3cdc: /* original 9480, guest PC 0x0c0b3cdc */
if(!s->budget--) { s->failed_pc=0x0c0b3cdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3de0u,2);
goto P_0c0b3cde;
P_0c0b3cde: /* original 4e0b, guest PC 0x0c0b3cde */
if(!s->budget--) { s->failed_pc=0x0c0b3cdeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ce2u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ce2u) { target=s->pc; goto dispatch; }
goto P_0c0b3ce2;
P_0c0b3ce0: /* original 65b2, guest PC 0x0c0b3ce0 */
if(!s->budget--) { s->failed_pc=0x0c0b3ce0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3ce2;
P_0c0b3ce2: /* original 947e, guest PC 0x0c0b3ce2 */
if(!s->budget--) { s->failed_pc=0x0c0b3ce2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3de2u,2);
goto P_0c0b3ce4;
P_0c0b3ce4: /* original 4e0b, guest PC 0x0c0b3ce4 */
if(!s->budget--) { s->failed_pc=0x0c0b3ce4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ce8u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ce8u) { target=s->pc; goto dispatch; }
goto P_0c0b3ce8;
P_0c0b3ce6: /* original 65b2, guest PC 0x0c0b3ce6 */
if(!s->budget--) { s->failed_pc=0x0c0b3ce6u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b3ce8;
P_0c0b3ce8: /* original 947c, guest PC 0x0c0b3ce8 */
if(!s->budget--) { s->failed_pc=0x0c0b3ce8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3de4u,2);
goto P_0c0b3cea;
P_0c0b3cea: /* original 4e0b, guest PC 0x0c0b3cea */
if(!s->budget--) { s->failed_pc=0x0c0b3ceau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3ceeu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3ceeu) { target=s->pc; goto dispatch; }
goto P_0c0b3cee;
P_0c0b3cec: /* original 65a2, guest PC 0x0c0b3cec */
if(!s->budget--) { s->failed_pc=0x0c0b3cecu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3cee;
P_0c0b3cee: /* original 947a, guest PC 0x0c0b3cee */
if(!s->budget--) { s->failed_pc=0x0c0b3ceeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3de6u,2);
goto P_0c0b3cf0;
P_0c0b3cf0: /* original 4e0b, guest PC 0x0c0b3cf0 */
if(!s->budget--) { s->failed_pc=0x0c0b3cf0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cf4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cf4u) { target=s->pc; goto dispatch; }
goto P_0c0b3cf4;
P_0c0b3cf2: /* original 65a2, guest PC 0x0c0b3cf2 */
if(!s->budget--) { s->failed_pc=0x0c0b3cf2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3cf4;
P_0c0b3cf4: /* original 9478, guest PC 0x0c0b3cf4 */
if(!s->budget--) { s->failed_pc=0x0c0b3cf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3de8u,2);
goto P_0c0b3cf6;
P_0c0b3cf6: /* original 4e0b, guest PC 0x0c0b3cf6 */
if(!s->budget--) { s->failed_pc=0x0c0b3cf6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3cfau;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3cfau) { target=s->pc; goto dispatch; }
goto P_0c0b3cfa;
P_0c0b3cf8: /* original 65a2, guest PC 0x0c0b3cf8 */
if(!s->budget--) { s->failed_pc=0x0c0b3cf8u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3cfa;
P_0c0b3cfa: /* original 9476, guest PC 0x0c0b3cfa */
if(!s->budget--) { s->failed_pc=0x0c0b3cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3deau,2);
goto P_0c0b3cfc;
P_0c0b3cfc: /* original 4e0b, guest PC 0x0c0b3cfc */
if(!s->budget--) { s->failed_pc=0x0c0b3cfcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d00u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d00u) { target=s->pc; goto dispatch; }
goto P_0c0b3d00;
P_0c0b3cfe: /* original 65a2, guest PC 0x0c0b3cfe */
if(!s->budget--) { s->failed_pc=0x0c0b3cfeu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b3d00;
P_0c0b3d00: /* original 9574, guest PC 0x0c0b3d00 */
if(!s->budget--) { s->failed_pc=0x0c0b3d00u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3decu,2);
goto P_0c0b3d02;
P_0c0b3d02: /* original 35dc, guest PC 0x0c0b3d02 */
if(!s->budget--) { s->failed_pc=0x0c0b3d02u; return 0; }
r[5]+=r[13];
goto P_0c0b3d04;
P_0c0b3d04: /* original 2f52, guest PC 0x0c0b3d04 */
if(!s->budget--) { s->failed_pc=0x0c0b3d04u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3d06;
P_0c0b3d06: /* original 9472, guest PC 0x0c0b3d06 */
if(!s->budget--) { s->failed_pc=0x0c0b3d06u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3deeu,2);
goto P_0c0b3d08;
P_0c0b3d08: /* original 4e0b, guest PC 0x0c0b3d08 */
if(!s->budget--) { s->failed_pc=0x0c0b3d08u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d0cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d0cu) { target=s->pc; goto dispatch; }
goto P_0c0b3d0c;
P_0c0b3d0a: /* original 6552, guest PC 0x0c0b3d0a */
if(!s->budget--) { s->failed_pc=0x0c0b3d0au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d0c;
P_0c0b3d0c: /* original 9470, guest PC 0x0c0b3d0c */
if(!s->budget--) { s->failed_pc=0x0c0b3d0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3df0u,2);
goto P_0c0b3d0e;
P_0c0b3d0e: /* original 65f2, guest PC 0x0c0b3d0e */
if(!s->budget--) { s->failed_pc=0x0c0b3d0eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3d10;
P_0c0b3d10: /* original 4e0b, guest PC 0x0c0b3d10 */
if(!s->budget--) { s->failed_pc=0x0c0b3d10u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d14u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d14u) { target=s->pc; goto dispatch; }
goto P_0c0b3d14;
P_0c0b3d12: /* original 6552, guest PC 0x0c0b3d12 */
if(!s->budget--) { s->failed_pc=0x0c0b3d12u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d14;
P_0c0b3d14: /* original 956d, guest PC 0x0c0b3d14 */
if(!s->budget--) { s->failed_pc=0x0c0b3d14u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3df2u,2);
goto P_0c0b3d16;
P_0c0b3d16: /* original 35dc, guest PC 0x0c0b3d16 */
if(!s->budget--) { s->failed_pc=0x0c0b3d16u; return 0; }
r[5]+=r[13];
goto P_0c0b3d18;
P_0c0b3d18: /* original 2f52, guest PC 0x0c0b3d18 */
if(!s->budget--) { s->failed_pc=0x0c0b3d18u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3d1a;
P_0c0b3d1a: /* original 946b, guest PC 0x0c0b3d1a */
if(!s->budget--) { s->failed_pc=0x0c0b3d1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3df4u,2);
goto P_0c0b3d1c;
P_0c0b3d1c: /* original 4e0b, guest PC 0x0c0b3d1c */
if(!s->budget--) { s->failed_pc=0x0c0b3d1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d20u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d20u) { target=s->pc; goto dispatch; }
goto P_0c0b3d20;
P_0c0b3d1e: /* original 6552, guest PC 0x0c0b3d1e */
if(!s->budget--) { s->failed_pc=0x0c0b3d1eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d20;
P_0c0b3d20: /* original 9469, guest PC 0x0c0b3d20 */
if(!s->budget--) { s->failed_pc=0x0c0b3d20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3df6u,2);
goto P_0c0b3d22;
P_0c0b3d22: /* original 65f2, guest PC 0x0c0b3d22 */
if(!s->budget--) { s->failed_pc=0x0c0b3d22u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3d24;
P_0c0b3d24: /* original 4e0b, guest PC 0x0c0b3d24 */
if(!s->budget--) { s->failed_pc=0x0c0b3d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d28u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d28u) { target=s->pc; goto dispatch; }
goto P_0c0b3d28;
P_0c0b3d26: /* original 6552, guest PC 0x0c0b3d26 */
if(!s->budget--) { s->failed_pc=0x0c0b3d26u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d28;
P_0c0b3d28: /* original 9467, guest PC 0x0c0b3d28 */
if(!s->budget--) { s->failed_pc=0x0c0b3d28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dfau,2);
goto P_0c0b3d2a;
P_0c0b3d2a: /* original 9065, guest PC 0x0c0b3d2a */
if(!s->budget--) { s->failed_pc=0x0c0b3d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3df8u,2);
goto P_0c0b3d2c;
P_0c0b3d2c: /* original 4e0b, guest PC 0x0c0b3d2c */
if(!s->budget--) { s->failed_pc=0x0c0b3d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d30u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d30u) { target=s->pc; goto dispatch; }
goto P_0c0b3d30;
P_0c0b3d2e: /* original 05de, guest PC 0x0c0b3d2e */
if(!s->budget--) { s->failed_pc=0x0c0b3d2eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3d30;
P_0c0b3d30: /* original 9564, guest PC 0x0c0b3d30 */
if(!s->budget--) { s->failed_pc=0x0c0b3d30u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dfcu,2);
goto P_0c0b3d32;
P_0c0b3d32: /* original 35dc, guest PC 0x0c0b3d32 */
if(!s->budget--) { s->failed_pc=0x0c0b3d32u; return 0; }
r[5]+=r[13];
goto P_0c0b3d34;
P_0c0b3d34: /* original 2f52, guest PC 0x0c0b3d34 */
if(!s->budget--) { s->failed_pc=0x0c0b3d34u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3d36;
P_0c0b3d36: /* original 9462, guest PC 0x0c0b3d36 */
if(!s->budget--) { s->failed_pc=0x0c0b3d36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3dfeu,2);
goto P_0c0b3d38;
P_0c0b3d38: /* original 4e0b, guest PC 0x0c0b3d38 */
if(!s->budget--) { s->failed_pc=0x0c0b3d38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d3cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d3cu) { target=s->pc; goto dispatch; }
goto P_0c0b3d3c;
P_0c0b3d3a: /* original 6552, guest PC 0x0c0b3d3a */
if(!s->budget--) { s->failed_pc=0x0c0b3d3au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d3c;
P_0c0b3d3c: /* original 9460, guest PC 0x0c0b3d3c */
if(!s->budget--) { s->failed_pc=0x0c0b3d3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e00u,2);
goto P_0c0b3d3e;
P_0c0b3d3e: /* original 65f2, guest PC 0x0c0b3d3e */
if(!s->budget--) { s->failed_pc=0x0c0b3d3eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3d40;
P_0c0b3d40: /* original 4e0b, guest PC 0x0c0b3d40 */
if(!s->budget--) { s->failed_pc=0x0c0b3d40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d44u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d44u) { target=s->pc; goto dispatch; }
goto P_0c0b3d44;
P_0c0b3d42: /* original 6552, guest PC 0x0c0b3d42 */
if(!s->budget--) { s->failed_pc=0x0c0b3d42u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d44;
P_0c0b3d44: /* original 945e, guest PC 0x0c0b3d44 */
if(!s->budget--) { s->failed_pc=0x0c0b3d44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e04u,2);
goto P_0c0b3d46;
P_0c0b3d46: /* original 905c, guest PC 0x0c0b3d46 */
if(!s->budget--) { s->failed_pc=0x0c0b3d46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e02u,2);
goto P_0c0b3d48;
P_0c0b3d48: /* original 4e0b, guest PC 0x0c0b3d48 */
if(!s->budget--) { s->failed_pc=0x0c0b3d48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d4cu) { target=s->pc; goto dispatch; }
goto P_0c0b3d4c;
P_0c0b3d4a: /* original 05de, guest PC 0x0c0b3d4a */
if(!s->budget--) { s->failed_pc=0x0c0b3d4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3d4c;
P_0c0b3d4c: /* original 955b, guest PC 0x0c0b3d4c */
if(!s->budget--) { s->failed_pc=0x0c0b3d4cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e06u,2);
goto P_0c0b3d4e;
P_0c0b3d4e: /* original 35dc, guest PC 0x0c0b3d4e */
if(!s->budget--) { s->failed_pc=0x0c0b3d4eu; return 0; }
r[5]+=r[13];
goto P_0c0b3d50;
P_0c0b3d50: /* original 2f52, guest PC 0x0c0b3d50 */
if(!s->budget--) { s->failed_pc=0x0c0b3d50u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3d52;
P_0c0b3d52: /* original 9459, guest PC 0x0c0b3d52 */
if(!s->budget--) { s->failed_pc=0x0c0b3d52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e08u,2);
goto P_0c0b3d54;
P_0c0b3d54: /* original 4e0b, guest PC 0x0c0b3d54 */
if(!s->budget--) { s->failed_pc=0x0c0b3d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d58u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d58u) { target=s->pc; goto dispatch; }
goto P_0c0b3d58;
P_0c0b3d56: /* original 6552, guest PC 0x0c0b3d56 */
if(!s->budget--) { s->failed_pc=0x0c0b3d56u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d58;
P_0c0b3d58: /* original 9457, guest PC 0x0c0b3d58 */
if(!s->budget--) { s->failed_pc=0x0c0b3d58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e0au,2);
goto P_0c0b3d5a;
P_0c0b3d5a: /* original 65f2, guest PC 0x0c0b3d5a */
if(!s->budget--) { s->failed_pc=0x0c0b3d5au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3d5c;
P_0c0b3d5c: /* original 4e0b, guest PC 0x0c0b3d5c */
if(!s->budget--) { s->failed_pc=0x0c0b3d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d60u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d60u) { target=s->pc; goto dispatch; }
goto P_0c0b3d60;
P_0c0b3d5e: /* original 6552, guest PC 0x0c0b3d5e */
if(!s->budget--) { s->failed_pc=0x0c0b3d5eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d60;
P_0c0b3d60: /* original 9455, guest PC 0x0c0b3d60 */
if(!s->budget--) { s->failed_pc=0x0c0b3d60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e0eu,2);
goto P_0c0b3d62;
P_0c0b3d62: /* original 9053, guest PC 0x0c0b3d62 */
if(!s->budget--) { s->failed_pc=0x0c0b3d62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e0cu,2);
goto P_0c0b3d64;
P_0c0b3d64: /* original 4e0b, guest PC 0x0c0b3d64 */
if(!s->budget--) { s->failed_pc=0x0c0b3d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d68u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d68u) { target=s->pc; goto dispatch; }
goto P_0c0b3d68;
P_0c0b3d66: /* original 05de, guest PC 0x0c0b3d66 */
if(!s->budget--) { s->failed_pc=0x0c0b3d66u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3d68;
P_0c0b3d68: /* original 9552, guest PC 0x0c0b3d68 */
if(!s->budget--) { s->failed_pc=0x0c0b3d68u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e10u,2);
goto P_0c0b3d6a;
P_0c0b3d6a: /* original 35dc, guest PC 0x0c0b3d6a */
if(!s->budget--) { s->failed_pc=0x0c0b3d6au; return 0; }
r[5]+=r[13];
goto P_0c0b3d6c;
P_0c0b3d6c: /* original 2f52, guest PC 0x0c0b3d6c */
if(!s->budget--) { s->failed_pc=0x0c0b3d6cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3d6e;
P_0c0b3d6e: /* original 9450, guest PC 0x0c0b3d6e */
if(!s->budget--) { s->failed_pc=0x0c0b3d6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e12u,2);
goto P_0c0b3d70;
P_0c0b3d70: /* original 4e0b, guest PC 0x0c0b3d70 */
if(!s->budget--) { s->failed_pc=0x0c0b3d70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d74u) { target=s->pc; goto dispatch; }
goto P_0c0b3d74;
P_0c0b3d72: /* original 6552, guest PC 0x0c0b3d72 */
if(!s->budget--) { s->failed_pc=0x0c0b3d72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d74;
P_0c0b3d74: /* original 944e, guest PC 0x0c0b3d74 */
if(!s->budget--) { s->failed_pc=0x0c0b3d74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e14u,2);
goto P_0c0b3d76;
P_0c0b3d76: /* original 65f2, guest PC 0x0c0b3d76 */
if(!s->budget--) { s->failed_pc=0x0c0b3d76u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3d78;
P_0c0b3d78: /* original 4e0b, guest PC 0x0c0b3d78 */
if(!s->budget--) { s->failed_pc=0x0c0b3d78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d7cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d7cu) { target=s->pc; goto dispatch; }
goto P_0c0b3d7c;
P_0c0b3d7a: /* original 6552, guest PC 0x0c0b3d7a */
if(!s->budget--) { s->failed_pc=0x0c0b3d7au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d7c;
P_0c0b3d7c: /* original 954b, guest PC 0x0c0b3d7c */
if(!s->budget--) { s->failed_pc=0x0c0b3d7cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e16u,2);
goto P_0c0b3d7e;
P_0c0b3d7e: /* original 35dc, guest PC 0x0c0b3d7e */
if(!s->budget--) { s->failed_pc=0x0c0b3d7eu; return 0; }
r[5]+=r[13];
goto P_0c0b3d80;
P_0c0b3d80: /* original 2f52, guest PC 0x0c0b3d80 */
if(!s->budget--) { s->failed_pc=0x0c0b3d80u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b3d82;
P_0c0b3d82: /* original 9449, guest PC 0x0c0b3d82 */
if(!s->budget--) { s->failed_pc=0x0c0b3d82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e18u,2);
goto P_0c0b3d84;
P_0c0b3d84: /* original 4e0b, guest PC 0x0c0b3d84 */
if(!s->budget--) { s->failed_pc=0x0c0b3d84u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d88u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d88u) { target=s->pc; goto dispatch; }
goto P_0c0b3d88;
P_0c0b3d86: /* original 6552, guest PC 0x0c0b3d86 */
if(!s->budget--) { s->failed_pc=0x0c0b3d86u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d88;
P_0c0b3d88: /* original 9447, guest PC 0x0c0b3d88 */
if(!s->budget--) { s->failed_pc=0x0c0b3d88u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e1au,2);
goto P_0c0b3d8a;
P_0c0b3d8a: /* original 65f2, guest PC 0x0c0b3d8a */
if(!s->budget--) { s->failed_pc=0x0c0b3d8au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b3d8c;
P_0c0b3d8c: /* original 4e0b, guest PC 0x0c0b3d8c */
if(!s->budget--) { s->failed_pc=0x0c0b3d8cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d90u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d90u) { target=s->pc; goto dispatch; }
goto P_0c0b3d90;
P_0c0b3d8e: /* original 6552, guest PC 0x0c0b3d8e */
if(!s->budget--) { s->failed_pc=0x0c0b3d8eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b3d90;
P_0c0b3d90: /* original 9445, guest PC 0x0c0b3d90 */
if(!s->budget--) { s->failed_pc=0x0c0b3d90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e1eu,2);
goto P_0c0b3d92;
P_0c0b3d92: /* original 9043, guest PC 0x0c0b3d92 */
if(!s->budget--) { s->failed_pc=0x0c0b3d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e1cu,2);
goto P_0c0b3d94;
P_0c0b3d94: /* original 4e0b, guest PC 0x0c0b3d94 */
if(!s->budget--) { s->failed_pc=0x0c0b3d94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3d98u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3d98u) { target=s->pc; goto dispatch; }
goto P_0c0b3d98;
P_0c0b3d96: /* original 05de, guest PC 0x0c0b3d96 */
if(!s->budget--) { s->failed_pc=0x0c0b3d96u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3d98;
P_0c0b3d98: /* original 9443, guest PC 0x0c0b3d98 */
if(!s->budget--) { s->failed_pc=0x0c0b3d98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e22u,2);
goto P_0c0b3d9a;
P_0c0b3d9a: /* original 9041, guest PC 0x0c0b3d9a */
if(!s->budget--) { s->failed_pc=0x0c0b3d9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e20u,2);
goto P_0c0b3d9c;
P_0c0b3d9c: /* original 4e0b, guest PC 0x0c0b3d9c */
if(!s->budget--) { s->failed_pc=0x0c0b3d9cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3da0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3da0u) { target=s->pc; goto dispatch; }
goto P_0c0b3da0;
P_0c0b3d9e: /* original 05de, guest PC 0x0c0b3d9e */
if(!s->budget--) { s->failed_pc=0x0c0b3d9eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3da0;
P_0c0b3da0: /* original 9441, guest PC 0x0c0b3da0 */
if(!s->budget--) { s->failed_pc=0x0c0b3da0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e26u,2);
goto P_0c0b3da2;
P_0c0b3da2: /* original 903f, guest PC 0x0c0b3da2 */
if(!s->budget--) { s->failed_pc=0x0c0b3da2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e24u,2);
goto P_0c0b3da4;
P_0c0b3da4: /* original 4e0b, guest PC 0x0c0b3da4 */
if(!s->budget--) { s->failed_pc=0x0c0b3da4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3da8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3da8u) { target=s->pc; goto dispatch; }
goto P_0c0b3da8;
P_0c0b3da6: /* original 05de, guest PC 0x0c0b3da6 */
if(!s->budget--) { s->failed_pc=0x0c0b3da6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3da8;
P_0c0b3da8: /* original 943f, guest PC 0x0c0b3da8 */
if(!s->budget--) { s->failed_pc=0x0c0b3da8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e2au,2);
goto P_0c0b3daa;
P_0c0b3daa: /* original 903d, guest PC 0x0c0b3daa */
if(!s->budget--) { s->failed_pc=0x0c0b3daau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e28u,2);
goto P_0c0b3dac;
P_0c0b3dac: /* original 4e0b, guest PC 0x0c0b3dac */
if(!s->budget--) { s->failed_pc=0x0c0b3dacu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3db0u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3db0u) { target=s->pc; goto dispatch; }
goto P_0c0b3db0;
P_0c0b3dae: /* original 05de, guest PC 0x0c0b3dae */
if(!s->budget--) { s->failed_pc=0x0c0b3daeu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3db0;
P_0c0b3db0: /* original 903c, guest PC 0x0c0b3db0 */
if(!s->budget--) { s->failed_pc=0x0c0b3db0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e2cu,2);
goto P_0c0b3db2;
P_0c0b3db2: /* original a03c, guest PC 0x0c0b3db2 */
if(!s->budget--) { s->failed_pc=0x0c0b3db2u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e2e;
P_0c0b3db4: /* original 05de, guest PC 0x0c0b3db4 */
if(!s->budget--) { s->failed_pc=0x0c0b3db4u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b3db6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b3db6u; return 0; } return 1;
P_0c0b3e2e: /* original 942a, guest PC 0x0c0b3e2e */
if(!s->budget--) { s->failed_pc=0x0c0b3e2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e86u,2);
goto P_0c0b3e30;
P_0c0b3e30: /* original 4e0b, guest PC 0x0c0b3e30 */
if(!s->budget--) { s->failed_pc=0x0c0b3e30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e34u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e34u) { target=s->pc; goto dispatch; }
goto P_0c0b3e34;
P_0c0b3e32: /* original 0009, guest PC 0x0c0b3e32 */
if(!s->budget--) { s->failed_pc=0x0c0b3e32u; return 0; }
goto P_0c0b3e34;
P_0c0b3e34: /* original 9429, guest PC 0x0c0b3e34 */
if(!s->budget--) { s->failed_pc=0x0c0b3e34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e8au,2);
goto P_0c0b3e36;
P_0c0b3e36: /* original 9027, guest PC 0x0c0b3e36 */
if(!s->budget--) { s->failed_pc=0x0c0b3e36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e88u,2);
goto P_0c0b3e38;
P_0c0b3e38: /* original 4e0b, guest PC 0x0c0b3e38 */
if(!s->budget--) { s->failed_pc=0x0c0b3e38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e3cu) { target=s->pc; goto dispatch; }
goto P_0c0b3e3c;
P_0c0b3e3a: /* original 05de, guest PC 0x0c0b3e3a */
if(!s->budget--) { s->failed_pc=0x0c0b3e3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e3c;
P_0c0b3e3c: /* original 9427, guest PC 0x0c0b3e3c */
if(!s->budget--) { s->failed_pc=0x0c0b3e3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e8eu,2);
goto P_0c0b3e3e;
P_0c0b3e3e: /* original 9025, guest PC 0x0c0b3e3e */
if(!s->budget--) { s->failed_pc=0x0c0b3e3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e8cu,2);
goto P_0c0b3e40;
P_0c0b3e40: /* original 4e0b, guest PC 0x0c0b3e40 */
if(!s->budget--) { s->failed_pc=0x0c0b3e40u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e44u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e44u) { target=s->pc; goto dispatch; }
goto P_0c0b3e44;
P_0c0b3e42: /* original 05de, guest PC 0x0c0b3e42 */
if(!s->budget--) { s->failed_pc=0x0c0b3e42u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e44;
P_0c0b3e44: /* original 9425, guest PC 0x0c0b3e44 */
if(!s->budget--) { s->failed_pc=0x0c0b3e44u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e92u,2);
goto P_0c0b3e46;
P_0c0b3e46: /* original 9023, guest PC 0x0c0b3e46 */
if(!s->budget--) { s->failed_pc=0x0c0b3e46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e90u,2);
goto P_0c0b3e48;
P_0c0b3e48: /* original 4e0b, guest PC 0x0c0b3e48 */
if(!s->budget--) { s->failed_pc=0x0c0b3e48u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e4cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e4cu) { target=s->pc; goto dispatch; }
goto P_0c0b3e4c;
P_0c0b3e4a: /* original 05de, guest PC 0x0c0b3e4a */
if(!s->budget--) { s->failed_pc=0x0c0b3e4au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e4c;
P_0c0b3e4c: /* original 9423, guest PC 0x0c0b3e4c */
if(!s->budget--) { s->failed_pc=0x0c0b3e4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e96u,2);
goto P_0c0b3e4e;
P_0c0b3e4e: /* original 9021, guest PC 0x0c0b3e4e */
if(!s->budget--) { s->failed_pc=0x0c0b3e4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e94u,2);
goto P_0c0b3e50;
P_0c0b3e50: /* original 4e0b, guest PC 0x0c0b3e50 */
if(!s->budget--) { s->failed_pc=0x0c0b3e50u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e54u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e54u) { target=s->pc; goto dispatch; }
goto P_0c0b3e54;
P_0c0b3e52: /* original 05de, guest PC 0x0c0b3e52 */
if(!s->budget--) { s->failed_pc=0x0c0b3e52u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e54;
P_0c0b3e54: /* original 9421, guest PC 0x0c0b3e54 */
if(!s->budget--) { s->failed_pc=0x0c0b3e54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e9au,2);
goto P_0c0b3e56;
P_0c0b3e56: /* original 901f, guest PC 0x0c0b3e56 */
if(!s->budget--) { s->failed_pc=0x0c0b3e56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e98u,2);
goto P_0c0b3e58;
P_0c0b3e58: /* original 4e0b, guest PC 0x0c0b3e58 */
if(!s->budget--) { s->failed_pc=0x0c0b3e58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e5cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e5cu) { target=s->pc; goto dispatch; }
goto P_0c0b3e5c;
P_0c0b3e5a: /* original 05de, guest PC 0x0c0b3e5a */
if(!s->budget--) { s->failed_pc=0x0c0b3e5au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e5c;
P_0c0b3e5c: /* original 941f, guest PC 0x0c0b3e5c */
if(!s->budget--) { s->failed_pc=0x0c0b3e5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e9eu,2);
goto P_0c0b3e5e;
P_0c0b3e5e: /* original 901d, guest PC 0x0c0b3e5e */
if(!s->budget--) { s->failed_pc=0x0c0b3e5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3e9cu,2);
goto P_0c0b3e60;
P_0c0b3e60: /* original 4e0b, guest PC 0x0c0b3e60 */
if(!s->budget--) { s->failed_pc=0x0c0b3e60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e64u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e64u) { target=s->pc; goto dispatch; }
goto P_0c0b3e64;
P_0c0b3e62: /* original 05de, guest PC 0x0c0b3e62 */
if(!s->budget--) { s->failed_pc=0x0c0b3e62u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e64;
P_0c0b3e64: /* original 941d, guest PC 0x0c0b3e64 */
if(!s->budget--) { s->failed_pc=0x0c0b3e64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ea2u,2);
goto P_0c0b3e66;
P_0c0b3e66: /* original 901b, guest PC 0x0c0b3e66 */
if(!s->budget--) { s->failed_pc=0x0c0b3e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ea0u,2);
goto P_0c0b3e68;
P_0c0b3e68: /* original 4e0b, guest PC 0x0c0b3e68 */
if(!s->budget--) { s->failed_pc=0x0c0b3e68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e6cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e6cu) { target=s->pc; goto dispatch; }
goto P_0c0b3e6c;
P_0c0b3e6a: /* original 05de, guest PC 0x0c0b3e6a */
if(!s->budget--) { s->failed_pc=0x0c0b3e6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e6c;
P_0c0b3e6c: /* original 941b, guest PC 0x0c0b3e6c */
if(!s->budget--) { s->failed_pc=0x0c0b3e6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ea6u,2);
goto P_0c0b3e6e;
P_0c0b3e6e: /* original 9019, guest PC 0x0c0b3e6e */
if(!s->budget--) { s->failed_pc=0x0c0b3e6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b3ea4u,2);
goto P_0c0b3e70;
P_0c0b3e70: /* original 4e0b, guest PC 0x0c0b3e70 */
if(!s->budget--) { s->failed_pc=0x0c0b3e70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b3e74u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b3e74u) { target=s->pc; goto dispatch; }
goto P_0c0b3e74;
P_0c0b3e72: /* original 05de, guest PC 0x0c0b3e72 */
if(!s->budget--) { s->failed_pc=0x0c0b3e72u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b3e74;
P_0c0b3e74: /* original 7f08, guest PC 0x0c0b3e74 */
if(!s->budget--) { s->failed_pc=0x0c0b3e74u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b3e76;
P_0c0b3e76: /* original 4f26, guest PC 0x0c0b3e76 */
if(!s->budget--) { s->failed_pc=0x0c0b3e76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b3e78;
P_0c0b3e78: /* original 69f6, guest PC 0x0c0b3e78 */
if(!s->budget--) { s->failed_pc=0x0c0b3e78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b3e7a;
P_0c0b3e7a: /* original 6af6, guest PC 0x0c0b3e7a */
if(!s->budget--) { s->failed_pc=0x0c0b3e7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b3e7c;
P_0c0b3e7c: /* original 6bf6, guest PC 0x0c0b3e7c */
if(!s->budget--) { s->failed_pc=0x0c0b3e7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b3e7e;
P_0c0b3e7e: /* original 6cf6, guest PC 0x0c0b3e7e */
if(!s->budget--) { s->failed_pc=0x0c0b3e7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b3e80;
P_0c0b3e80: /* original 6df6, guest PC 0x0c0b3e80 */
if(!s->budget--) { s->failed_pc=0x0c0b3e80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b3e82;
P_0c0b3e82: /* original 000b, guest PC 0x0c0b3e82 */
if(!s->budget--) { s->failed_pc=0x0c0b3e82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b3e84: /* original 6ef6, guest PC 0x0c0b3e84 */
if(!s->budget--) { s->failed_pc=0x0c0b3e84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b3e86u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b3e86u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
