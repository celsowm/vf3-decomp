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
int vf3_away_batch23_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b1a46u: goto P_0c0b1a46;
case 0x0c0b1a48u: goto P_0c0b1a48;
case 0x0c0b1a4au: goto P_0c0b1a4a;
case 0x0c0b1a4cu: goto P_0c0b1a4c;
case 0x0c0b1a4eu: goto P_0c0b1a4e;
case 0x0c0b1a50u: goto P_0c0b1a50;
case 0x0c0b1a52u: goto P_0c0b1a52;
case 0x0c0b1a54u: goto P_0c0b1a54;
case 0x0c0b1a56u: goto P_0c0b1a56;
case 0x0c0b1a58u: goto P_0c0b1a58;
case 0x0c0b1a5au: goto P_0c0b1a5a;
case 0x0c0b1a5cu: goto P_0c0b1a5c;
case 0x0c0b1a5eu: goto P_0c0b1a5e;
case 0x0c0b1a60u: goto P_0c0b1a60;
case 0x0c0b1a62u: goto P_0c0b1a62;
case 0x0c0b1a64u: goto P_0c0b1a64;
case 0x0c0b1a66u: goto P_0c0b1a66;
case 0x0c0b1a68u: goto P_0c0b1a68;
case 0x0c0b1a6au: goto P_0c0b1a6a;
case 0x0c0b1a6cu: goto P_0c0b1a6c;
case 0x0c0b1a6eu: goto P_0c0b1a6e;
case 0x0c0b1a70u: goto P_0c0b1a70;
case 0x0c0b1a72u: goto P_0c0b1a72;
case 0x0c0b1a74u: goto P_0c0b1a74;
case 0x0c0b1a76u: goto P_0c0b1a76;
case 0x0c0b1a78u: goto P_0c0b1a78;
case 0x0c0b1a7au: goto P_0c0b1a7a;
case 0x0c0b1a7cu: goto P_0c0b1a7c;
case 0x0c0b1a7eu: goto P_0c0b1a7e;
case 0x0c0b1a80u: goto P_0c0b1a80;
case 0x0c0b1a82u: goto P_0c0b1a82;
case 0x0c0b1a84u: goto P_0c0b1a84;
case 0x0c0b1a86u: goto P_0c0b1a86;
case 0x0c0b1a88u: goto P_0c0b1a88;
case 0x0c0b1a8au: goto P_0c0b1a8a;
case 0x0c0b1a8cu: goto P_0c0b1a8c;
case 0x0c0b1a8eu: goto P_0c0b1a8e;
case 0x0c0b1a90u: goto P_0c0b1a90;
case 0x0c0b1a92u: goto P_0c0b1a92;
case 0x0c0b1a94u: goto P_0c0b1a94;
case 0x0c0b1a96u: goto P_0c0b1a96;
case 0x0c0b1a98u: goto P_0c0b1a98;
case 0x0c0b1a9au: goto P_0c0b1a9a;
case 0x0c0b1a9cu: goto P_0c0b1a9c;
case 0x0c0b1a9eu: goto P_0c0b1a9e;
case 0x0c0b1aa0u: goto P_0c0b1aa0;
case 0x0c0b1ac4u: goto P_0c0b1ac4;
case 0x0c0b1ac6u: goto P_0c0b1ac6;
case 0x0c0b1ac8u: goto P_0c0b1ac8;
case 0x0c0b1acau: goto P_0c0b1aca;
case 0x0c0b1accu: goto P_0c0b1acc;
case 0x0c0b1aceu: goto P_0c0b1ace;
case 0x0c0b1ad0u: goto P_0c0b1ad0;
case 0x0c0b1ad2u: goto P_0c0b1ad2;
case 0x0c0b1ad4u: goto P_0c0b1ad4;
case 0x0c0b1ad6u: goto P_0c0b1ad6;
case 0x0c0b1ad8u: goto P_0c0b1ad8;
case 0x0c0b1adau: goto P_0c0b1ada;
case 0x0c0b1adcu: goto P_0c0b1adc;
case 0x0c0b1adeu: goto P_0c0b1ade;
case 0x0c0b1ae0u: goto P_0c0b1ae0;
case 0x0c0b1ae2u: goto P_0c0b1ae2;
case 0x0c0b1ae4u: goto P_0c0b1ae4;
case 0x0c0b1ae6u: goto P_0c0b1ae6;
case 0x0c0b1ae8u: goto P_0c0b1ae8;
case 0x0c0b1aeau: goto P_0c0b1aea;
case 0x0c0b1aecu: goto P_0c0b1aec;
case 0x0c0b1aeeu: goto P_0c0b1aee;
case 0x0c0b1af0u: goto P_0c0b1af0;
case 0x0c0b1af2u: goto P_0c0b1af2;
case 0x0c0b1af4u: goto P_0c0b1af4;
case 0x0c0b1af6u: goto P_0c0b1af6;
case 0x0c0b1af8u: goto P_0c0b1af8;
case 0x0c0b1afau: goto P_0c0b1afa;
case 0x0c0b1afcu: goto P_0c0b1afc;
case 0x0c0b1afeu: goto P_0c0b1afe;
case 0x0c0b1b00u: goto P_0c0b1b00;
case 0x0c0b1b02u: goto P_0c0b1b02;
case 0x0c0b1b04u: goto P_0c0b1b04;
case 0x0c0b1b06u: goto P_0c0b1b06;
case 0x0c0b1b08u: goto P_0c0b1b08;
case 0x0c0b1b0au: goto P_0c0b1b0a;
case 0x0c0b1b0cu: goto P_0c0b1b0c;
case 0x0c0b1b0eu: goto P_0c0b1b0e;
case 0x0c0b1b10u: goto P_0c0b1b10;
case 0x0c0b1b12u: goto P_0c0b1b12;
case 0x0c0b1b14u: goto P_0c0b1b14;
case 0x0c0b1b16u: goto P_0c0b1b16;
case 0x0c0b1b18u: goto P_0c0b1b18;
case 0x0c0b1b1au: goto P_0c0b1b1a;
case 0x0c0b1b1cu: goto P_0c0b1b1c;
case 0x0c0b1b1eu: goto P_0c0b1b1e;
case 0x0c0b1b20u: goto P_0c0b1b20;
case 0x0c0b1b22u: goto P_0c0b1b22;
case 0x0c0b1b24u: goto P_0c0b1b24;
case 0x0c0b1b26u: goto P_0c0b1b26;
case 0x0c0b1b28u: goto P_0c0b1b28;
case 0x0c0b1b2au: goto P_0c0b1b2a;
case 0x0c0b1b2cu: goto P_0c0b1b2c;
case 0x0c0b1b2eu: goto P_0c0b1b2e;
case 0x0c0b1b30u: goto P_0c0b1b30;
case 0x0c0b1b32u: goto P_0c0b1b32;
case 0x0c0b1b34u: goto P_0c0b1b34;
case 0x0c0b1b36u: goto P_0c0b1b36;
case 0x0c0b1b38u: goto P_0c0b1b38;
case 0x0c0b1b3au: goto P_0c0b1b3a;
case 0x0c0b1b3cu: goto P_0c0b1b3c;
case 0x0c0b1b3eu: goto P_0c0b1b3e;
case 0x0c0b1b40u: goto P_0c0b1b40;
case 0x0c0b1b42u: goto P_0c0b1b42;
case 0x0c0b1b44u: goto P_0c0b1b44;
case 0x0c0b1b46u: goto P_0c0b1b46;
case 0x0c0b1b48u: goto P_0c0b1b48;
case 0x0c0b1b4au: goto P_0c0b1b4a;
case 0x0c0b1b4cu: goto P_0c0b1b4c;
case 0x0c0b1b4eu: goto P_0c0b1b4e;
case 0x0c0b1b50u: goto P_0c0b1b50;
case 0x0c0b1b52u: goto P_0c0b1b52;
case 0x0c0b1b54u: goto P_0c0b1b54;
case 0x0c0b1b56u: goto P_0c0b1b56;
case 0x0c0b1b58u: goto P_0c0b1b58;
case 0x0c0b1b5au: goto P_0c0b1b5a;
case 0x0c0b1b5cu: goto P_0c0b1b5c;
case 0x0c0b1b5eu: goto P_0c0b1b5e;
case 0x0c0b1b60u: goto P_0c0b1b60;
case 0x0c0b1b62u: goto P_0c0b1b62;
case 0x0c0b1b64u: goto P_0c0b1b64;
case 0x0c0b1b66u: goto P_0c0b1b66;
case 0x0c0b1b68u: goto P_0c0b1b68;
case 0x0c0b1b6au: goto P_0c0b1b6a;
case 0x0c0b1b7cu: goto P_0c0b1b7c;
case 0x0c0b1b7eu: goto P_0c0b1b7e;
case 0x0c0b1b80u: goto P_0c0b1b80;
case 0x0c0b1b82u: goto P_0c0b1b82;
case 0x0c0b1b84u: goto P_0c0b1b84;
case 0x0c0b1b86u: goto P_0c0b1b86;
case 0x0c0b1b88u: goto P_0c0b1b88;
case 0x0c0b1b8au: goto P_0c0b1b8a;
case 0x0c0b1b8cu: goto P_0c0b1b8c;
case 0x0c0b1b8eu: goto P_0c0b1b8e;
case 0x0c0b1b90u: goto P_0c0b1b90;
case 0x0c0b1b92u: goto P_0c0b1b92;
case 0x0c0b1b94u: goto P_0c0b1b94;
case 0x0c0b1b96u: goto P_0c0b1b96;
case 0x0c0b1b98u: goto P_0c0b1b98;
case 0x0c0b1b9au: goto P_0c0b1b9a;
case 0x0c0b1b9cu: goto P_0c0b1b9c;
case 0x0c0b1b9eu: goto P_0c0b1b9e;
case 0x0c0b1ba0u: goto P_0c0b1ba0;
case 0x0c0b1ba2u: goto P_0c0b1ba2;
case 0x0c0b1ba4u: goto P_0c0b1ba4;
case 0x0c0b1ba6u: goto P_0c0b1ba6;
case 0x0c0b1ba8u: goto P_0c0b1ba8;
case 0x0c0b1baau: goto P_0c0b1baa;
case 0x0c0b1bacu: goto P_0c0b1bac;
case 0x0c0b1baeu: goto P_0c0b1bae;
case 0x0c0b1bb0u: goto P_0c0b1bb0;
case 0x0c0b1bb2u: goto P_0c0b1bb2;
case 0x0c0b1bb4u: goto P_0c0b1bb4;
case 0x0c0b1bb6u: goto P_0c0b1bb6;
case 0x0c0b1bb8u: goto P_0c0b1bb8;
case 0x0c0b1bbau: goto P_0c0b1bba;
case 0x0c0b1bbcu: goto P_0c0b1bbc;
case 0x0c0b1bbeu: goto P_0c0b1bbe;
case 0x0c0b1bc0u: goto P_0c0b1bc0;
case 0x0c0b1bc2u: goto P_0c0b1bc2;
case 0x0c0b1bc4u: goto P_0c0b1bc4;
case 0x0c0b1bc6u: goto P_0c0b1bc6;
case 0x0c0b1bc8u: goto P_0c0b1bc8;
case 0x0c0b1bcau: goto P_0c0b1bca;
case 0x0c0b1bccu: goto P_0c0b1bcc;
case 0x0c0b1bceu: goto P_0c0b1bce;
case 0x0c0b1bd0u: goto P_0c0b1bd0;
case 0x0c0b1bd2u: goto P_0c0b1bd2;
case 0x0c0b1bd4u: goto P_0c0b1bd4;
case 0x0c0b1bd6u: goto P_0c0b1bd6;
case 0x0c0b1bd8u: goto P_0c0b1bd8;
case 0x0c0b1bdau: goto P_0c0b1bda;
case 0x0c0b1bdcu: goto P_0c0b1bdc;
case 0x0c0b1bdeu: goto P_0c0b1bde;
case 0x0c0b1be0u: goto P_0c0b1be0;
case 0x0c0b1be2u: goto P_0c0b1be2;
case 0x0c0b1be4u: goto P_0c0b1be4;
case 0x0c0b1be6u: goto P_0c0b1be6;
case 0x0c0b1be8u: goto P_0c0b1be8;
case 0x0c0b1beau: goto P_0c0b1bea;
case 0x0c0b1becu: goto P_0c0b1bec;
case 0x0c0b1beeu: goto P_0c0b1bee;
case 0x0c0b1bf0u: goto P_0c0b1bf0;
case 0x0c0b1bf2u: goto P_0c0b1bf2;
case 0x0c0b1bf4u: goto P_0c0b1bf4;
case 0x0c0b1bf6u: goto P_0c0b1bf6;
case 0x0c0b1bf8u: goto P_0c0b1bf8;
case 0x0c0b1bfau: goto P_0c0b1bfa;
case 0x0c0b1bfcu: goto P_0c0b1bfc;
case 0x0c0b1bfeu: goto P_0c0b1bfe;
case 0x0c0b1c00u: goto P_0c0b1c00;
case 0x0c0b1c02u: goto P_0c0b1c02;
case 0x0c0b1c04u: goto P_0c0b1c04;
case 0x0c0b1c06u: goto P_0c0b1c06;
case 0x0c0b1c08u: goto P_0c0b1c08;
case 0x0c0b1c0au: goto P_0c0b1c0a;
case 0x0c0b1c0cu: goto P_0c0b1c0c;
case 0x0c0b1c0eu: goto P_0c0b1c0e;
case 0x0c0b1c10u: goto P_0c0b1c10;
case 0x0c0b1c12u: goto P_0c0b1c12;
case 0x0c0b1c14u: goto P_0c0b1c14;
case 0x0c0b1c28u: goto P_0c0b1c28;
case 0x0c0b1c2au: goto P_0c0b1c2a;
case 0x0c0b1c2cu: goto P_0c0b1c2c;
case 0x0c0b1c2eu: goto P_0c0b1c2e;
case 0x0c0b1c30u: goto P_0c0b1c30;
case 0x0c0b1c32u: goto P_0c0b1c32;
case 0x0c0b1c34u: goto P_0c0b1c34;
case 0x0c0b1c36u: goto P_0c0b1c36;
case 0x0c0b1c38u: goto P_0c0b1c38;
case 0x0c0b1c3au: goto P_0c0b1c3a;
case 0x0c0b1c3cu: goto P_0c0b1c3c;
case 0x0c0b1c3eu: goto P_0c0b1c3e;
case 0x0c0b1c40u: goto P_0c0b1c40;
case 0x0c0b1c42u: goto P_0c0b1c42;
case 0x0c0b1c44u: goto P_0c0b1c44;
case 0x0c0b1c46u: goto P_0c0b1c46;
case 0x0c0b1c48u: goto P_0c0b1c48;
case 0x0c0b1c4au: goto P_0c0b1c4a;
case 0x0c0b1c4cu: goto P_0c0b1c4c;
case 0x0c0b1c4eu: goto P_0c0b1c4e;
case 0x0c0b1c50u: goto P_0c0b1c50;
case 0x0c0b1c52u: goto P_0c0b1c52;
case 0x0c0b1c54u: goto P_0c0b1c54;
case 0x0c0b1c56u: goto P_0c0b1c56;
case 0x0c0b1c58u: goto P_0c0b1c58;
case 0x0c0b1c5au: goto P_0c0b1c5a;
case 0x0c0b1c5cu: goto P_0c0b1c5c;
case 0x0c0b1c5eu: goto P_0c0b1c5e;
case 0x0c0b1c60u: goto P_0c0b1c60;
case 0x0c0b1c62u: goto P_0c0b1c62;
case 0x0c0b1c64u: goto P_0c0b1c64;
case 0x0c0b1c66u: goto P_0c0b1c66;
case 0x0c0b1c68u: goto P_0c0b1c68;
case 0x0c0b1c6au: goto P_0c0b1c6a;
case 0x0c0b1c6cu: goto P_0c0b1c6c;
case 0x0c0b1c6eu: goto P_0c0b1c6e;
case 0x0c0b1c70u: goto P_0c0b1c70;
case 0x0c0b1c72u: goto P_0c0b1c72;
case 0x0c0b1c74u: goto P_0c0b1c74;
case 0x0c0b1c76u: goto P_0c0b1c76;
case 0x0c0b1c78u: goto P_0c0b1c78;
case 0x0c0b1c7au: goto P_0c0b1c7a;
case 0x0c0b1c7cu: goto P_0c0b1c7c;
case 0x0c0b1c7eu: goto P_0c0b1c7e;
case 0x0c0b1c80u: goto P_0c0b1c80;
case 0x0c0b1c82u: goto P_0c0b1c82;
case 0x0c0b1c84u: goto P_0c0b1c84;
case 0x0c0b1c86u: goto P_0c0b1c86;
case 0x0c0b1c88u: goto P_0c0b1c88;
case 0x0c0b1c8au: goto P_0c0b1c8a;
case 0x0c0b1c8cu: goto P_0c0b1c8c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b1a46: /* original 2fe6, guest PC 0x0c0b1a46 */
if(!s->budget--) { s->failed_pc=0x0c0b1a46u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1a48;
P_0c0b1a48: /* original 6e53, guest PC 0x0c0b1a48 */
if(!s->budget--) { s->failed_pc=0x0c0b1a48u; return 0; }
r[14]=r[5];
goto P_0c0b1a4a;
P_0c0b1a4a: /* original 2fd6, guest PC 0x0c0b1a4a */
if(!s->budget--) { s->failed_pc=0x0c0b1a4au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1a4c;
P_0c0b1a4c: /* original 6d43, guest PC 0x0c0b1a4c */
if(!s->budget--) { s->failed_pc=0x0c0b1a4cu; return 0; }
r[13]=r[4];
goto P_0c0b1a4e;
P_0c0b1a4e: /* original 2fc6, guest PC 0x0c0b1a4e */
if(!s->budget--) { s->failed_pc=0x0c0b1a4eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1a50;
P_0c0b1a50: /* original 2fb6, guest PC 0x0c0b1a50 */
if(!s->budget--) { s->failed_pc=0x0c0b1a50u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1a52;
P_0c0b1a52: /* original 6b63, guest PC 0x0c0b1a52 */
if(!s->budget--) { s->failed_pc=0x0c0b1a52u; return 0; }
r[11]=r[6];
goto P_0c0b1a54;
P_0c0b1a54: /* original 4f22, guest PC 0x0c0b1a54 */
if(!s->budget--) { s->failed_pc=0x0c0b1a54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1a56;
P_0c0b1a56: /* original 7ffc, guest PC 0x0c0b1a56 */
if(!s->budget--) { s->failed_pc=0x0c0b1a56u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b1a58;
P_0c0b1a58: /* original 2f72, guest PC 0x0c0b1a58 */
if(!s->budget--) { s->failed_pc=0x0c0b1a58u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c0b1a5a;
P_0c0b1a5a: /* original d318, guest PC 0x0c0b1a5a */
if(!s->budget--) { s->failed_pc=0x0c0b1a5au; return 0; }
r[3]=read(ram,0x0c0b1abcu,4);
goto P_0c0b1a5c;
P_0c0b1a5c: /* original 430b, guest PC 0x0c0b1a5c */
if(!s->budget--) { s->failed_pc=0x0c0b1a5cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1a60u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a60u) { target=s->pc; goto dispatch; }
goto P_0c0b1a60;
P_0c0b1a5e: /* original e400, guest PC 0x0c0b1a5e */
if(!s->budget--) { s->failed_pc=0x0c0b1a5eu; return 0; }
r[4]=0x00000000u;
goto P_0c0b1a60;
P_0c0b1a60: /* original d313, guest PC 0x0c0b1a60 */
if(!s->budget--) { s->failed_pc=0x0c0b1a60u; return 0; }
r[3]=read(ram,0x0c0b1ab0u,4);
goto P_0c0b1a62;
P_0c0b1a62: /* original 430b, guest PC 0x0c0b1a62 */
if(!s->budget--) { s->failed_pc=0x0c0b1a62u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1a66u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a66u) { target=s->pc; goto dispatch; }
goto P_0c0b1a66;
P_0c0b1a64: /* original 64f2, guest PC 0x0c0b1a64 */
if(!s->budget--) { s->failed_pc=0x0c0b1a64u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1a66;
P_0c0b1a66: /* original 50f6, guest PC 0x0c0b1a66 */
if(!s->budget--) { s->failed_pc=0x0c0b1a66u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0b1a68;
P_0c0b1a68: /* original dc15, guest PC 0x0c0b1a68 */
if(!s->budget--) { s->failed_pc=0x0c0b1a68u; return 0; }
r[12]=read(ram,0x0c0b1ac0u,4);
goto P_0c0b1a6a;
P_0c0b1a6a: /* original 8801, guest PC 0x0c0b1a6a */
if(!s->budget--) { s->failed_pc=0x0c0b1a6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0b1a6c;
P_0c0b1a6c: /* original 8909, guest PC 0x0c0b1a6c */
if(!s->budget--) { s->failed_pc=0x0c0b1a6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a82; }
goto P_0c0b1a6e;
P_0c0b1a6e: /* original 8805, guest PC 0x0c0b1a6e */
if(!s->budget--) { s->failed_pc=0x0c0b1a6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b1a70;
P_0c0b1a70: /* original 8909, guest PC 0x0c0b1a70 */
if(!s->budget--) { s->failed_pc=0x0c0b1a70u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a86; }
goto P_0c0b1a72;
P_0c0b1a72: /* original 8809, guest PC 0x0c0b1a72 */
if(!s->budget--) { s->failed_pc=0x0c0b1a72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b1a74;
P_0c0b1a74: /* original 890a, guest PC 0x0c0b1a74 */
if(!s->budget--) { s->failed_pc=0x0c0b1a74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a8c; }
goto P_0c0b1a76;
P_0c0b1a76: /* original 880e, guest PC 0x0c0b1a76 */
if(!s->budget--) { s->failed_pc=0x0c0b1a76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0b1a78;
P_0c0b1a78: /* original 890b, guest PC 0x0c0b1a78 */
if(!s->budget--) { s->failed_pc=0x0c0b1a78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a92; }
goto P_0c0b1a7a;
P_0c0b1a7a: /* original 8811, guest PC 0x0c0b1a7a */
if(!s->budget--) { s->failed_pc=0x0c0b1a7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c0b1a7c;
P_0c0b1a7c: /* original 890c, guest PC 0x0c0b1a7c */
if(!s->budget--) { s->failed_pc=0x0c0b1a7cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1a98; }
goto P_0c0b1a7e;
P_0c0b1a7e: /* original a021, guest PC 0x0c0b1a7e */
if(!s->budget--) { s->failed_pc=0x0c0b1a7eu; return 0; }
goto P_0c0b1ac4;
P_0c0b1a80: /* original 0009, guest PC 0x0c0b1a80 */
if(!s->budget--) { s->failed_pc=0x0c0b1a80u; return 0; }
goto P_0c0b1a82;
P_0c0b1a82: /* original a00a, guest PC 0x0c0b1a82 */
if(!s->budget--) { s->failed_pc=0x0c0b1a82u; return 0; }
r[0]=0x00000070u;
goto P_0c0b1a9a;
P_0c0b1a84: /* original e070, guest PC 0x0c0b1a84 */
if(!s->budget--) { s->failed_pc=0x0c0b1a84u; return 0; }
r[0]=0x00000070u;
goto P_0c0b1a86;
P_0c0b1a86: /* original 900c, guest PC 0x0c0b1a86 */
if(!s->budget--) { s->failed_pc=0x0c0b1a86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1aa2u,2);
goto P_0c0b1a88;
P_0c0b1a88: /* original a007, guest PC 0x0c0b1a88 */
if(!s->budget--) { s->failed_pc=0x0c0b1a88u; return 0; }
goto P_0c0b1a9a;
P_0c0b1a8a: /* original 0009, guest PC 0x0c0b1a8a */
if(!s->budget--) { s->failed_pc=0x0c0b1a8au; return 0; }
goto P_0c0b1a8c;
P_0c0b1a8c: /* original 900a, guest PC 0x0c0b1a8c */
if(!s->budget--) { s->failed_pc=0x0c0b1a8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1aa4u,2);
goto P_0c0b1a8e;
P_0c0b1a8e: /* original a004, guest PC 0x0c0b1a8e */
if(!s->budget--) { s->failed_pc=0x0c0b1a8eu; return 0; }
goto P_0c0b1a9a;
P_0c0b1a90: /* original 0009, guest PC 0x0c0b1a90 */
if(!s->budget--) { s->failed_pc=0x0c0b1a90u; return 0; }
goto P_0c0b1a92;
P_0c0b1a92: /* original 9008, guest PC 0x0c0b1a92 */
if(!s->budget--) { s->failed_pc=0x0c0b1a92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1aa6u,2);
goto P_0c0b1a94;
P_0c0b1a94: /* original a001, guest PC 0x0c0b1a94 */
if(!s->budget--) { s->failed_pc=0x0c0b1a94u; return 0; }
goto P_0c0b1a9a;
P_0c0b1a96: /* original 0009, guest PC 0x0c0b1a96 */
if(!s->budget--) { s->failed_pc=0x0c0b1a96u; return 0; }
goto P_0c0b1a98;
P_0c0b1a98: /* original 9006, guest PC 0x0c0b1a98 */
if(!s->budget--) { s->failed_pc=0x0c0b1a98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1aa8u,2);
goto P_0c0b1a9a;
P_0c0b1a9a: /* original 4c0b, guest PC 0x0c0b1a9a */
if(!s->budget--) { s->failed_pc=0x0c0b1a9au; return 0; }
target=r[12];
r[16]=code_base|0x0c0b1a9eu;
r[4]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1a9eu) { target=s->pc; goto dispatch; }
goto P_0c0b1a9e;
P_0c0b1a9c: /* original 04de, guest PC 0x0c0b1a9c */
if(!s->budget--) { s->failed_pc=0x0c0b1a9cu; return 0; }
r[4]=read(ram,r[13]+r[0],4);
goto P_0c0b1a9e;
P_0c0b1a9e: /* original a018, guest PC 0x0c0b1a9e */
if(!s->budget--) { s->failed_pc=0x0c0b1a9eu; return 0; }
goto P_0c0b1ad2;
P_0c0b1aa0: /* original 0009, guest PC 0x0c0b1aa0 */
if(!s->budget--) { s->failed_pc=0x0c0b1aa0u; return 0; }
if(!vf3_matrix_family(0x0c0b1aa2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1aa2u; return 0; } return 1;
P_0c0b1ac4: /* original 52e1, guest PC 0x0c0b1ac4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ac4u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0b1ac6;
P_0c0b1ac6: /* original 2228, guest PC 0x0c0b1ac6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ac6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0b1ac8;
P_0c0b1ac8: /* original 8903, guest PC 0x0c0b1ac8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ac8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1ad2; }
goto P_0c0b1aca;
P_0c0b1aca: /* original d329, guest PC 0x0c0b1aca */
if(!s->budget--) { s->failed_pc=0x0c0b1acau; return 0; }
r[3]=read(ram,0x0c0b1b70u,4);
goto P_0c0b1acc;
P_0c0b1acc: /* original f49d, guest PC 0x0c0b1acc */
if(!s->budget--) { s->failed_pc=0x0c0b1accu; return 0; }
fr[4]=0x3f800000u;
goto P_0c0b1ace;
P_0c0b1ace: /* original 430b, guest PC 0x0c0b1ace */
if(!s->budget--) { s->failed_pc=0x0c0b1aceu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1ad2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1ad2u) { target=s->pc; goto dispatch; }
goto P_0c0b1ad2;
P_0c0b1ad0: /* original 64e3, guest PC 0x0c0b1ad0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ad0u; return 0; }
r[4]=r[14];
goto P_0c0b1ad2;
P_0c0b1ad2: /* original 50f6, guest PC 0x0c0b1ad2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ad2u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0b1ad4;
P_0c0b1ad4: /* original 8801, guest PC 0x0c0b1ad4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ad4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0b1ad6;
P_0c0b1ad6: /* original 890f, guest PC 0x0c0b1ad6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ad6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1af8; }
goto P_0c0b1ad8;
P_0c0b1ad8: /* original 8805, guest PC 0x0c0b1ad8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ad8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0b1ada;
P_0c0b1ada: /* original 8910, guest PC 0x0c0b1ada */
if(!s->budget--) { s->failed_pc=0x0c0b1adau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1afe; }
goto P_0c0b1adc;
P_0c0b1adc: /* original 8809, guest PC 0x0c0b1adc */
if(!s->budget--) { s->failed_pc=0x0c0b1adcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0b1ade;
P_0c0b1ade: /* original 890e, guest PC 0x0c0b1ade */
if(!s->budget--) { s->failed_pc=0x0c0b1adeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1afe; }
goto P_0c0b1ae0;
P_0c0b1ae0: /* original 880b, guest PC 0x0c0b1ae0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ae0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0b1ae2;
P_0c0b1ae2: /* original 890e, guest PC 0x0c0b1ae2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ae2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b02; }
goto P_0c0b1ae4;
P_0c0b1ae4: /* original 880d, guest PC 0x0c0b1ae4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ae4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0b1ae6;
P_0c0b1ae6: /* original 8912, guest PC 0x0c0b1ae6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ae6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b0e; }
goto P_0c0b1ae8;
P_0c0b1ae8: /* original 880e, guest PC 0x0c0b1ae8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ae8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0b1aea;
P_0c0b1aea: /* original 8915, guest PC 0x0c0b1aea */
if(!s->budget--) { s->failed_pc=0x0c0b1aeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b18; }
goto P_0c0b1aec;
P_0c0b1aec: /* original 8810, guest PC 0x0c0b1aec */
if(!s->budget--) { s->failed_pc=0x0c0b1aecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0b1aee;
P_0c0b1aee: /* original 8913, guest PC 0x0c0b1aee */
if(!s->budget--) { s->failed_pc=0x0c0b1aeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b18; }
goto P_0c0b1af0;
P_0c0b1af0: /* original 8811, guest PC 0x0c0b1af0 */
if(!s->budget--) { s->failed_pc=0x0c0b1af0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000011u)!=0);
goto P_0c0b1af2;
P_0c0b1af2: /* original 8911, guest PC 0x0c0b1af2 */
if(!s->budget--) { s->failed_pc=0x0c0b1af2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b18; }
goto P_0c0b1af4;
P_0c0b1af4: /* original a00d, guest PC 0x0c0b1af4 */
if(!s->budget--) { s->failed_pc=0x0c0b1af4u; return 0; }
goto P_0c0b1b12;
P_0c0b1af6: /* original 0009, guest PC 0x0c0b1af6 */
if(!s->budget--) { s->failed_pc=0x0c0b1af6u; return 0; }
goto P_0c0b1af8;
P_0c0b1af8: /* original 53ec, guest PC 0x0c0b1af8 */
if(!s->budget--) { s->failed_pc=0x0c0b1af8u; return 0; }
r[3]=read(ram,r[14]+48,4);
goto P_0c0b1afa;
P_0c0b1afa: /* original a00d, guest PC 0x0c0b1afa */
if(!s->budget--) { s->failed_pc=0x0c0b1afau; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0b1b18;
P_0c0b1afc: /* original 2b32, guest PC 0x0c0b1afc */
if(!s->budget--) { s->failed_pc=0x0c0b1afcu; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0b1afe;
P_0c0b1afe: /* original a003, guest PC 0x0c0b1afe */
if(!s->budget--) { s->failed_pc=0x0c0b1afeu; return 0; }
tmp=read(ram,r[11],4);
r[14]=tmp;
goto P_0c0b1b08;
P_0c0b1b00: /* original 6eb2, guest PC 0x0c0b1b00 */
if(!s->budget--) { s->failed_pc=0x0c0b1b00u; return 0; }
tmp=read(ram,r[11],4);
r[14]=tmp;
goto P_0c0b1b02;
P_0c0b1b02: /* original 2ee8, guest PC 0x0c0b1b02 */
if(!s->budget--) { s->failed_pc=0x0c0b1b02u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0b1b04;
P_0c0b1b04: /* original 8908, guest PC 0x0c0b1b04 */
if(!s->budget--) { s->failed_pc=0x0c0b1b04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b18; }
goto P_0c0b1b06;
P_0c0b1b06: /* original 5eeb, guest PC 0x0c0b1b06 */
if(!s->budget--) { s->failed_pc=0x0c0b1b06u; return 0; }
r[14]=read(ram,r[14]+44,4);
goto P_0c0b1b08;
P_0c0b1b08: /* original 52ec, guest PC 0x0c0b1b08 */
if(!s->budget--) { s->failed_pc=0x0c0b1b08u; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c0b1b0a;
P_0c0b1b0a: /* original a005, guest PC 0x0c0b1b0a */
if(!s->budget--) { s->failed_pc=0x0c0b1b0au; return 0; }
write(ram,r[11],r[2],4);
goto P_0c0b1b18;
P_0c0b1b0c: /* original 2b22, guest PC 0x0c0b1b0c */
if(!s->budget--) { s->failed_pc=0x0c0b1b0cu; return 0; }
write(ram,r[11],r[2],4);
goto P_0c0b1b0e;
P_0c0b1b0e: /* original a003, guest PC 0x0c0b1b0e */
if(!s->budget--) { s->failed_pc=0x0c0b1b0eu; return 0; }
tmp=read(ram,r[11],4);
r[14]=tmp;
goto P_0c0b1b18;
P_0c0b1b10: /* original 6eb2, guest PC 0x0c0b1b10 */
if(!s->budget--) { s->failed_pc=0x0c0b1b10u; return 0; }
tmp=read(ram,r[11],4);
r[14]=tmp;
goto P_0c0b1b12;
P_0c0b1b12: /* original 2ee8, guest PC 0x0c0b1b12 */
if(!s->budget--) { s->failed_pc=0x0c0b1b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0b1b14;
P_0c0b1b14: /* original 8900, guest PC 0x0c0b1b14 */
if(!s->budget--) { s->failed_pc=0x0c0b1b14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b18; }
goto P_0c0b1b16;
P_0c0b1b16: /* original 5eeb, guest PC 0x0c0b1b16 */
if(!s->budget--) { s->failed_pc=0x0c0b1b16u; return 0; }
r[14]=read(ram,r[14]+44,4);
goto P_0c0b1b18;
P_0c0b1b18: /* original d216, guest PC 0x0c0b1b18 */
if(!s->budget--) { s->failed_pc=0x0c0b1b18u; return 0; }
r[2]=read(ram,0x0c0b1b74u,4);
goto P_0c0b1b1a;
P_0c0b1b1a: /* original 420b, guest PC 0x0c0b1b1a */
if(!s->budget--) { s->failed_pc=0x0c0b1b1au; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1b1eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1b1eu) { target=s->pc; goto dispatch; }
goto P_0c0b1b1e;
P_0c0b1b1c: /* original e401, guest PC 0x0c0b1b1c */
if(!s->budget--) { s->failed_pc=0x0c0b1b1cu; return 0; }
r[4]=0x00000001u;
goto P_0c0b1b1e;
P_0c0b1b1e: /* original 7f04, guest PC 0x0c0b1b1e */
if(!s->budget--) { s->failed_pc=0x0c0b1b1eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0b1b20;
P_0c0b1b20: /* original 60e3, guest PC 0x0c0b1b20 */
if(!s->budget--) { s->failed_pc=0x0c0b1b20u; return 0; }
r[0]=r[14];
goto P_0c0b1b22;
P_0c0b1b22: /* original 4f26, guest PC 0x0c0b1b22 */
if(!s->budget--) { s->failed_pc=0x0c0b1b22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1b24;
P_0c0b1b24: /* original 6bf6, guest PC 0x0c0b1b24 */
if(!s->budget--) { s->failed_pc=0x0c0b1b24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b1b26;
P_0c0b1b26: /* original 6cf6, guest PC 0x0c0b1b26 */
if(!s->budget--) { s->failed_pc=0x0c0b1b26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1b28;
P_0c0b1b28: /* original 6df6, guest PC 0x0c0b1b28 */
if(!s->budget--) { s->failed_pc=0x0c0b1b28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1b2a;
P_0c0b1b2a: /* original 000b, guest PC 0x0c0b1b2a */
if(!s->budget--) { s->failed_pc=0x0c0b1b2au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1b2c: /* original 6ef6, guest PC 0x0c0b1b2c */
if(!s->budget--) { s->failed_pc=0x0c0b1b2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0b1b2e;
P_0c0b1b2e: /* original 2fe6, guest PC 0x0c0b1b2e */
if(!s->budget--) { s->failed_pc=0x0c0b1b2eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b30;
P_0c0b1b30: /* original 2fd6, guest PC 0x0c0b1b30 */
if(!s->budget--) { s->failed_pc=0x0c0b1b30u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b32;
P_0c0b1b32: /* original 2fc6, guest PC 0x0c0b1b32 */
if(!s->budget--) { s->failed_pc=0x0c0b1b32u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b34;
P_0c0b1b34: /* original 4f22, guest PC 0x0c0b1b34 */
if(!s->budget--) { s->failed_pc=0x0c0b1b34u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1b36;
P_0c0b1b36: /* original 7ffc, guest PC 0x0c0b1b36 */
if(!s->budget--) { s->failed_pc=0x0c0b1b36u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0b1b38;
P_0c0b1b38: /* original 2f42, guest PC 0x0c0b1b38 */
if(!s->budget--) { s->failed_pc=0x0c0b1b38u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0b1b3a;
P_0c0b1b3a: /* original e411, guest PC 0x0c0b1b3a */
if(!s->budget--) { s->failed_pc=0x0c0b1b3au; return 0; }
r[4]=0x00000011u;
goto P_0c0b1b3c;
P_0c0b1b3c: /* original 3546, guest PC 0x0c0b1b3c */
if(!s->budget--) { s->failed_pc=0x0c0b1b3cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[4])!=0);
goto P_0c0b1b3e;
P_0c0b1b3e: /* original 8f01, guest PC 0x0c0b1b3e */
if(!s->budget--) { s->failed_pc=0x0c0b1b3eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c0b1b44; }
goto P_0c0b1b42;
P_0c0b1b40: /* original e600, guest PC 0x0c0b1b40 */
if(!s->budget--) { s->failed_pc=0x0c0b1b40u; return 0; }
r[6]=0x00000000u;
goto P_0c0b1b42;
P_0c0b1b42: /* original 6543, guest PC 0x0c0b1b42 */
if(!s->budget--) { s->failed_pc=0x0c0b1b42u; return 0; }
r[5]=r[4];
goto P_0c0b1b44;
P_0c0b1b44: /* original d00c, guest PC 0x0c0b1b44 */
if(!s->budget--) { s->failed_pc=0x0c0b1b44u; return 0; }
r[0]=read(ram,0x0c0b1b78u,4);
goto P_0c0b1b46;
P_0c0b1b46: /* original 6c53, guest PC 0x0c0b1b46 */
if(!s->budget--) { s->failed_pc=0x0c0b1b46u; return 0; }
r[12]=r[5];
goto P_0c0b1b48;
P_0c0b1b48: /* original 4c08, guest PC 0x0c0b1b48 */
if(!s->budget--) { s->failed_pc=0x0c0b1b48u; return 0; }
r[12]<<=2;
goto P_0c0b1b4a;
P_0c0b1b4a: /* original 6d63, guest PC 0x0c0b1b4a */
if(!s->budget--) { s->failed_pc=0x0c0b1b4au; return 0; }
r[13]=r[6];
goto P_0c0b1b4c;
P_0c0b1b4c: /* original 0cce, guest PC 0x0c0b1b4c */
if(!s->budget--) { s->failed_pc=0x0c0b1b4cu; return 0; }
r[12]=read(ram,r[12]+r[0],4);
goto P_0c0b1b4e;
P_0c0b1b4e: /* original 60d3, guest PC 0x0c0b1b4e */
if(!s->budget--) { s->failed_pc=0x0c0b1b4eu; return 0; }
r[0]=r[13];
goto P_0c0b1b50;
P_0c0b1b50: /* original 4008, guest PC 0x0c0b1b50 */
if(!s->budget--) { s->failed_pc=0x0c0b1b50u; return 0; }
r[0]<<=2;
goto P_0c0b1b52;
P_0c0b1b52: /* original 0ece, guest PC 0x0c0b1b52 */
if(!s->budget--) { s->failed_pc=0x0c0b1b52u; return 0; }
r[14]=read(ram,r[12]+r[0],4);
goto P_0c0b1b54;
P_0c0b1b54: /* original 2ee8, guest PC 0x0c0b1b54 */
if(!s->budget--) { s->failed_pc=0x0c0b1b54u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0b1b56;
P_0c0b1b56: /* original 8903, guest PC 0x0c0b1b56 */
if(!s->budget--) { s->failed_pc=0x0c0b1b56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1b60; }
goto P_0c0b1b58;
P_0c0b1b58: /* original 4e0b, guest PC 0x0c0b1b58 */
if(!s->budget--) { s->failed_pc=0x0c0b1b58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b1b5cu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1b5cu) { target=s->pc; goto dispatch; }
goto P_0c0b1b5c;
P_0c0b1b5a: /* original 64f2, guest PC 0x0c0b1b5a */
if(!s->budget--) { s->failed_pc=0x0c0b1b5au; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0b1b5c;
P_0c0b1b5c: /* original aff7, guest PC 0x0c0b1b5c */
if(!s->budget--) { s->failed_pc=0x0c0b1b5cu; return 0; }
r[13]+=0x00000001u;
goto P_0c0b1b4e;
P_0c0b1b5e: /* original 7d01, guest PC 0x0c0b1b5e */
if(!s->budget--) { s->failed_pc=0x0c0b1b5eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0b1b60;
P_0c0b1b60: /* original 7f04, guest PC 0x0c0b1b60 */
if(!s->budget--) { s->failed_pc=0x0c0b1b60u; return 0; }
r[15]+=0x00000004u;
goto P_0c0b1b62;
P_0c0b1b62: /* original 4f26, guest PC 0x0c0b1b62 */
if(!s->budget--) { s->failed_pc=0x0c0b1b62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1b64;
P_0c0b1b64: /* original 6cf6, guest PC 0x0c0b1b64 */
if(!s->budget--) { s->failed_pc=0x0c0b1b64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1b66;
P_0c0b1b66: /* original 6df6, guest PC 0x0c0b1b66 */
if(!s->budget--) { s->failed_pc=0x0c0b1b66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1b68;
P_0c0b1b68: /* original 000b, guest PC 0x0c0b1b68 */
if(!s->budget--) { s->failed_pc=0x0c0b1b68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1b6a: /* original 6ef6, guest PC 0x0c0b1b6a */
if(!s->budget--) { s->failed_pc=0x0c0b1b6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1b6cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1b6cu; return 0; } return 1;
P_0c0b1b7c: /* original 2fe6, guest PC 0x0c0b1b7c */
if(!s->budget--) { s->failed_pc=0x0c0b1b7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b7e;
P_0c0b1b7e: /* original 6e43, guest PC 0x0c0b1b7e */
if(!s->budget--) { s->failed_pc=0x0c0b1b7eu; return 0; }
r[14]=r[4];
goto P_0c0b1b80;
P_0c0b1b80: /* original 2fd6, guest PC 0x0c0b1b80 */
if(!s->budget--) { s->failed_pc=0x0c0b1b80u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b82;
P_0c0b1b82: /* original e060, guest PC 0x0c0b1b82 */
if(!s->budget--) { s->failed_pc=0x0c0b1b82u; return 0; }
r[0]=0x00000060u;
goto P_0c0b1b84;
P_0c0b1b84: /* original 2fc6, guest PC 0x0c0b1b84 */
if(!s->budget--) { s->failed_pc=0x0c0b1b84u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b86;
P_0c0b1b86: /* original 2fb6, guest PC 0x0c0b1b86 */
if(!s->budget--) { s->failed_pc=0x0c0b1b86u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b88;
P_0c0b1b88: /* original 2fa6, guest PC 0x0c0b1b88 */
if(!s->budget--) { s->failed_pc=0x0c0b1b88u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b1b8a;
P_0c0b1b8a: /* original 4f22, guest PC 0x0c0b1b8a */
if(!s->budget--) { s->failed_pc=0x0c0b1b8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b1b8c;
P_0c0b1b8c: /* original 0dec, guest PC 0x0c0b1b8c */
if(!s->budget--) { s->failed_pc=0x0c0b1b8cu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b1b8e;
P_0c0b1b8e: /* original 6ddc, guest PC 0x0c0b1b8e */
if(!s->budget--) { s->failed_pc=0x0c0b1b8eu; return 0; }
r[13]=r[13]&255u;
goto P_0c0b1b90;
P_0c0b1b90: /* original 7ff0, guest PC 0x0c0b1b90 */
if(!s->budget--) { s->failed_pc=0x0c0b1b90u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0b1b92;
P_0c0b1b92: /* original 2fd2, guest PC 0x0c0b1b92 */
if(!s->budget--) { s->failed_pc=0x0c0b1b92u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c0b1b94;
P_0c0b1b94: /* original 4d08, guest PC 0x0c0b1b94 */
if(!s->budget--) { s->failed_pc=0x0c0b1b94u; return 0; }
r[13]<<=2;
goto P_0c0b1b96;
P_0c0b1b96: /* original d022, guest PC 0x0c0b1b96 */
if(!s->budget--) { s->failed_pc=0x0c0b1b96u; return 0; }
r[0]=read(ram,0x0c0b1c20u,4);
goto P_0c0b1b98;
P_0c0b1b98: /* original 0dde, guest PC 0x0c0b1b98 */
if(!s->budget--) { s->failed_pc=0x0c0b1b98u; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0b1b9a;
P_0c0b1b9a: /* original e061, guest PC 0x0c0b1b9a */
if(!s->budget--) { s->failed_pc=0x0c0b1b9au; return 0; }
r[0]=0x00000061u;
goto P_0c0b1b9c;
P_0c0b1b9c: /* original 0aec, guest PC 0x0c0b1b9c */
if(!s->budget--) { s->failed_pc=0x0c0b1b9cu; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0b1b9e;
P_0c0b1b9e: /* original 6cd1, guest PC 0x0c0b1b9e */
if(!s->budget--) { s->failed_pc=0x0c0b1b9eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c0b1ba0;
P_0c0b1ba0: /* original 6aac, guest PC 0x0c0b1ba0 */
if(!s->budget--) { s->failed_pc=0x0c0b1ba0u; return 0; }
r[10]=r[10]&255u;
goto P_0c0b1ba2;
P_0c0b1ba2: /* original 6ccd, guest PC 0x0c0b1ba2 */
if(!s->budget--) { s->failed_pc=0x0c0b1ba2u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0b1ba4;
P_0c0b1ba4: /* original 2cc8, guest PC 0x0c0b1ba4 */
if(!s->budget--) { s->failed_pc=0x0c0b1ba4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0b1ba6;
P_0c0b1ba6: /* original 896a, guest PC 0x0c0b1ba6 */
if(!s->budget--) { s->failed_pc=0x0c0b1ba6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c7e; }
goto P_0c0b1ba8;
P_0c0b1ba8: /* original 60a3, guest PC 0x0c0b1ba8 */
if(!s->budget--) { s->failed_pc=0x0c0b1ba8u; return 0; }
r[0]=r[10];
goto P_0c0b1baa;
P_0c0b1baa: /* original 8808, guest PC 0x0c0b1baa */
if(!s->budget--) { s->failed_pc=0x0c0b1baau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0b1bac;
P_0c0b1bac: /* original 8b1e, guest PC 0x0c0b1bac */
if(!s->budget--) { s->failed_pc=0x0c0b1bacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1bec; }
goto P_0c0b1bae;
P_0c0b1bae: /* original 60c3, guest PC 0x0c0b1bae */
if(!s->budget--) { s->failed_pc=0x0c0b1baeu; return 0; }
r[0]=r[12];
goto P_0c0b1bb0;
P_0c0b1bb0: /* original 8802, guest PC 0x0c0b1bb0 */
if(!s->budget--) { s->failed_pc=0x0c0b1bb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0b1bb2;
P_0c0b1bb2: /* original 8918, guest PC 0x0c0b1bb2 */
if(!s->budget--) { s->failed_pc=0x0c0b1bb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1be6; }
goto P_0c0b1bb4;
P_0c0b1bb4: /* original e048, guest PC 0x0c0b1bb4 */
if(!s->budget--) { s->failed_pc=0x0c0b1bb4u; return 0; }
r[0]=0x00000048u;
goto P_0c0b1bb6;
P_0c0b1bb6: /* original 65e2, guest PC 0x0c0b1bb6 */
if(!s->budget--) { s->failed_pc=0x0c0b1bb6u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0b1bb8;
P_0c0b1bb8: /* original 04ee, guest PC 0x0c0b1bb8 */
if(!s->budget--) { s->failed_pc=0x0c0b1bb8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0b1bba;
P_0c0b1bba: /* original e210, guest PC 0x0c0b1bba */
if(!s->budget--) { s->failed_pc=0x0c0b1bbau; return 0; }
r[2]=0x00000010u;
goto P_0c0b1bbc;
P_0c0b1bbc: /* original e30f, guest PC 0x0c0b1bbc */
if(!s->budget--) { s->failed_pc=0x0c0b1bbcu; return 0; }
r[3]=0x0000000fu;
goto P_0c0b1bbe;
P_0c0b1bbe: /* original 2528, guest PC 0x0c0b1bbe */
if(!s->budget--) { s->failed_pc=0x0c0b1bbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0b1bc0;
P_0c0b1bc0: /* original 443d, guest PC 0x0c0b1bc0 */
if(!s->budget--) { s->failed_pc=0x0c0b1bc0u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?r[4]>>((-r[3])&31u):0):r[4]<<(r[3]&31u);
goto P_0c0b1bc2;
P_0c0b1bc2: /* original 8d5c, guest PC 0x0c0b1bc2 */
if(!s->budget--) { s->failed_pc=0x0c0b1bc2u; return 0; }
cond=r[17]&1u;
r[4]^=r[5];
if(cond) { goto P_0c0b1c7e; }
goto P_0c0b1bc6;
P_0c0b1bc4: /* original 245a, guest PC 0x0c0b1bc4 */
if(!s->budget--) { s->failed_pc=0x0c0b1bc4u; return 0; }
r[4]^=r[5];
goto P_0c0b1bc6;
P_0c0b1bc6: /* original e03c, guest PC 0x0c0b1bc6 */
if(!s->budget--) { s->failed_pc=0x0c0b1bc6u; return 0; }
r[0]=0x0000003cu;
goto P_0c0b1bc8;
P_0c0b1bc8: /* original 9225, guest PC 0x0c0b1bc8 */
if(!s->budget--) { s->failed_pc=0x0c0b1bc8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1c16u,2);
goto P_0c0b1bca;
P_0c0b1bca: /* original 03ed, guest PC 0x0c0b1bca */
if(!s->budget--) { s->failed_pc=0x0c0b1bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0b1bcc;
P_0c0b1bcc: /* original d515, guest PC 0x0c0b1bcc */
if(!s->budget--) { s->failed_pc=0x0c0b1bccu; return 0; }
r[5]=read(ram,0x0c0b1c24u,4);
goto P_0c0b1bce;
P_0c0b1bce: /* original 633d, guest PC 0x0c0b1bce */
if(!s->budget--) { s->failed_pc=0x0c0b1bceu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0b1bd0;
P_0c0b1bd0: /* original 3320, guest PC 0x0c0b1bd0 */
if(!s->budget--) { s->failed_pc=0x0c0b1bd0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0b1bd2;
P_0c0b1bd2: /* original 8f04, guest PC 0x0c0b1bd2 */
if(!s->budget--) { s->failed_pc=0x0c0b1bd2u; return 0; }
cond=r[17]&1u;
r[5]&=r[4];
if(!cond) { goto P_0c0b1bde; }
goto P_0c0b1bd6;
P_0c0b1bd4: /* original 2549, guest PC 0x0c0b1bd4 */
if(!s->budget--) { s->failed_pc=0x0c0b1bd4u; return 0; }
r[5]&=r[4];
goto P_0c0b1bd6;
P_0c0b1bd6: /* original 2558, guest PC 0x0c0b1bd6 */
if(!s->budget--) { s->failed_pc=0x0c0b1bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0b1bd8;
P_0c0b1bd8: /* original 8b08, guest PC 0x0c0b1bd8 */
if(!s->budget--) { s->failed_pc=0x0c0b1bd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1bec; }
goto P_0c0b1bda;
P_0c0b1bda: /* original a002, guest PC 0x0c0b1bda */
if(!s->budget--) { s->failed_pc=0x0c0b1bdau; return 0; }
goto P_0c0b1be2;
P_0c0b1bdc: /* original 0009, guest PC 0x0c0b1bdc */
if(!s->budget--) { s->failed_pc=0x0c0b1bdcu; return 0; }
goto P_0c0b1bde;
P_0c0b1bde: /* original 2558, guest PC 0x0c0b1bde */
if(!s->budget--) { s->failed_pc=0x0c0b1bdeu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0b1be0;
P_0c0b1be0: /* original 8904, guest PC 0x0c0b1be0 */
if(!s->budget--) { s->failed_pc=0x0c0b1be0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1bec; }
goto P_0c0b1be2;
P_0c0b1be2: /* original a003, guest PC 0x0c0b1be2 */
if(!s->budget--) { s->failed_pc=0x0c0b1be2u; return 0; }
r[13]+=0x00000018u;
goto P_0c0b1bec;
P_0c0b1be4: /* original 7d18, guest PC 0x0c0b1be4 */
if(!s->budget--) { s->failed_pc=0x0c0b1be4u; return 0; }
r[13]+=0x00000018u;
goto P_0c0b1be6;
P_0c0b1be6: /* original 60f2, guest PC 0x0c0b1be6 */
if(!s->budget--) { s->failed_pc=0x0c0b1be6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0b1be8;
P_0c0b1be8: /* original 8815, guest PC 0x0c0b1be8 */
if(!s->budget--) { s->failed_pc=0x0c0b1be8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000015u)!=0);
goto P_0c0b1bea;
P_0c0b1bea: /* original 8945, guest PC 0x0c0b1bea */
if(!s->budget--) { s->failed_pc=0x0c0b1beau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c78; }
goto P_0c0b1bec;
P_0c0b1bec: /* original 85d1, guest PC 0x0c0b1bec */
if(!s->budget--) { s->failed_pc=0x0c0b1becu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c0b1bee;
P_0c0b1bee: /* original 600d, guest PC 0x0c0b1bee */
if(!s->budget--) { s->failed_pc=0x0c0b1beeu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0b1bf0;
P_0c0b1bf0: /* original 8801, guest PC 0x0c0b1bf0 */
if(!s->budget--) { s->failed_pc=0x0c0b1bf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0b1bf2;
P_0c0b1bf2: /* original 8907, guest PC 0x0c0b1bf2 */
if(!s->budget--) { s->failed_pc=0x0c0b1bf2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c04; }
goto P_0c0b1bf4;
P_0c0b1bf4: /* original 8802, guest PC 0x0c0b1bf4 */
if(!s->budget--) { s->failed_pc=0x0c0b1bf4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0b1bf6;
P_0c0b1bf6: /* original 8908, guest PC 0x0c0b1bf6 */
if(!s->budget--) { s->failed_pc=0x0c0b1bf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c0a; }
goto P_0c0b1bf8;
P_0c0b1bf8: /* original 8803, guest PC 0x0c0b1bf8 */
if(!s->budget--) { s->failed_pc=0x0c0b1bf8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0b1bfa;
P_0c0b1bfa: /* original 8909, guest PC 0x0c0b1bfa */
if(!s->budget--) { s->failed_pc=0x0c0b1bfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c10; }
goto P_0c0b1bfc;
P_0c0b1bfc: /* original 8804, guest PC 0x0c0b1bfc */
if(!s->budget--) { s->failed_pc=0x0c0b1bfcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0b1bfe;
P_0c0b1bfe: /* original 8913, guest PC 0x0c0b1bfe */
if(!s->budget--) { s->failed_pc=0x0c0b1bfeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c28; }
goto P_0c0b1c00;
P_0c0b1c00: /* original a014, guest PC 0x0c0b1c00 */
if(!s->budget--) { s->failed_pc=0x0c0b1c00u; return 0; }
goto P_0c0b1c2c;
P_0c0b1c02: /* original 0009, guest PC 0x0c0b1c02 */
if(!s->budget--) { s->failed_pc=0x0c0b1c02u; return 0; }
goto P_0c0b1c04;
P_0c0b1c04: /* original 9b08, guest PC 0x0c0b1c04 */
if(!s->budget--) { s->failed_pc=0x0c0b1c04u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1c18u,2);
goto P_0c0b1c06;
P_0c0b1c06: /* original a010, guest PC 0x0c0b1c06 */
if(!s->budget--) { s->failed_pc=0x0c0b1c06u; return 0; }
goto P_0c0b1c2a;
P_0c0b1c08: /* original 0009, guest PC 0x0c0b1c08 */
if(!s->budget--) { s->failed_pc=0x0c0b1c08u; return 0; }
goto P_0c0b1c0a;
P_0c0b1c0a: /* original 9b06, guest PC 0x0c0b1c0a */
if(!s->budget--) { s->failed_pc=0x0c0b1c0au; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1c1au,2);
goto P_0c0b1c0c;
P_0c0b1c0c: /* original a00d, guest PC 0x0c0b1c0c */
if(!s->budget--) { s->failed_pc=0x0c0b1c0cu; return 0; }
goto P_0c0b1c2a;
P_0c0b1c0e: /* original 0009, guest PC 0x0c0b1c0e */
if(!s->budget--) { s->failed_pc=0x0c0b1c0eu; return 0; }
goto P_0c0b1c10;
P_0c0b1c10: /* original 9b04, guest PC 0x0c0b1c10 */
if(!s->budget--) { s->failed_pc=0x0c0b1c10u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1c1cu,2);
goto P_0c0b1c12;
P_0c0b1c12: /* original a00a, guest PC 0x0c0b1c12 */
if(!s->budget--) { s->failed_pc=0x0c0b1c12u; return 0; }
goto P_0c0b1c2a;
P_0c0b1c14: /* original 0009, guest PC 0x0c0b1c14 */
if(!s->budget--) { s->failed_pc=0x0c0b1c14u; return 0; }
if(!vf3_matrix_family(0x0c0b1c16u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1c16u; return 0; } return 1;
P_0c0b1c28: /* original 9b5f, guest PC 0x0c0b1c28 */
if(!s->budget--) { s->failed_pc=0x0c0b1c28u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1ceau,2);
goto P_0c0b1c2a;
P_0c0b1c2a: /* original 3bec, guest PC 0x0c0b1c2a */
if(!s->budget--) { s->failed_pc=0x0c0b1c2au; return 0; }
r[11]+=r[14];
goto P_0c0b1c2c;
P_0c0b1c2c: /* original d332, guest PC 0x0c0b1c2c */
if(!s->budget--) { s->failed_pc=0x0c0b1c2cu; return 0; }
r[3]=read(ram,0x0c0b1cf8u,4);
goto P_0c0b1c2e;
P_0c0b1c2e: /* original 430b, guest PC 0x0c0b1c2e */
if(!s->budget--) { s->failed_pc=0x0c0b1c2eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1c32u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c32u) { target=s->pc; goto dispatch; }
goto P_0c0b1c32;
P_0c0b1c30: /* original 64b3, guest PC 0x0c0b1c30 */
if(!s->budget--) { s->failed_pc=0x0c0b1c30u; return 0; }
r[4]=r[11];
goto P_0c0b1c32;
P_0c0b1c32: /* original d232, guest PC 0x0c0b1c32 */
if(!s->budget--) { s->failed_pc=0x0c0b1c32u; return 0; }
r[2]=read(ram,0x0c0b1cfcu,4);
goto P_0c0b1c34;
P_0c0b1c34: /* original 64d3, guest PC 0x0c0b1c34 */
if(!s->budget--) { s->failed_pc=0x0c0b1c34u; return 0; }
r[4]=r[13];
goto P_0c0b1c36;
P_0c0b1c36: /* original 420b, guest PC 0x0c0b1c36 */
if(!s->budget--) { s->failed_pc=0x0c0b1c36u; return 0; }
target=r[2];
r[16]=code_base|0x0c0b1c3au;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c3au) { target=s->pc; goto dispatch; }
goto P_0c0b1c3a;
P_0c0b1c38: /* original 740c, guest PC 0x0c0b1c38 */
if(!s->budget--) { s->failed_pc=0x0c0b1c38u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0b1c3a;
P_0c0b1c3a: /* original d331, guest PC 0x0c0b1c3a */
if(!s->budget--) { s->failed_pc=0x0c0b1c3au; return 0; }
r[3]=read(ram,0x0c0b1d00u,4);
goto P_0c0b1c3c;
P_0c0b1c3c: /* original 85d5, guest PC 0x0c0b1c3c */
if(!s->budget--) { s->failed_pc=0x0c0b1c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+10,2);
goto P_0c0b1c3e;
P_0c0b1c3e: /* original 430b, guest PC 0x0c0b1c3e */
if(!s->budget--) { s->failed_pc=0x0c0b1c3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1c42u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c42u) { target=s->pc; goto dispatch; }
goto P_0c0b1c42;
P_0c0b1c40: /* original 6403, guest PC 0x0c0b1c40 */
if(!s->budget--) { s->failed_pc=0x0c0b1c40u; return 0; }
r[4]=r[0];
goto P_0c0b1c42;
P_0c0b1c42: /* original d330, guest PC 0x0c0b1c42 */
if(!s->budget--) { s->failed_pc=0x0c0b1c42u; return 0; }
r[3]=read(ram,0x0c0b1d04u,4);
goto P_0c0b1c44;
P_0c0b1c44: /* original 85d4, guest PC 0x0c0b1c44 */
if(!s->budget--) { s->failed_pc=0x0c0b1c44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+8,2);
goto P_0c0b1c46;
P_0c0b1c46: /* original 430b, guest PC 0x0c0b1c46 */
if(!s->budget--) { s->failed_pc=0x0c0b1c46u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1c4au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c4au) { target=s->pc; goto dispatch; }
goto P_0c0b1c4a;
P_0c0b1c48: /* original 6403, guest PC 0x0c0b1c48 */
if(!s->budget--) { s->failed_pc=0x0c0b1c48u; return 0; }
r[4]=r[0];
goto P_0c0b1c4a;
P_0c0b1c4a: /* original d32f, guest PC 0x0c0b1c4a */
if(!s->budget--) { s->failed_pc=0x0c0b1c4au; return 0; }
r[3]=read(ram,0x0c0b1d08u,4);
goto P_0c0b1c4c;
P_0c0b1c4c: /* original 85d3, guest PC 0x0c0b1c4c */
if(!s->budget--) { s->failed_pc=0x0c0b1c4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c0b1c4e;
P_0c0b1c4e: /* original 430b, guest PC 0x0c0b1c4e */
if(!s->budget--) { s->failed_pc=0x0c0b1c4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1c52u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c52u) { target=s->pc; goto dispatch; }
goto P_0c0b1c52;
P_0c0b1c50: /* original 6403, guest PC 0x0c0b1c50 */
if(!s->budget--) { s->failed_pc=0x0c0b1c50u; return 0; }
r[4]=r[0];
goto P_0c0b1c52;
P_0c0b1c52: /* original 904b, guest PC 0x0c0b1c52 */
if(!s->budget--) { s->failed_pc=0x0c0b1c52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1cecu,2);
goto P_0c0b1c54;
P_0c0b1c54: /* original 04ee, guest PC 0x0c0b1c54 */
if(!s->budget--) { s->failed_pc=0x0c0b1c54u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0b1c56;
P_0c0b1c56: /* original 60a3, guest PC 0x0c0b1c56 */
if(!s->budget--) { s->failed_pc=0x0c0b1c56u; return 0; }
r[0]=r[10];
goto P_0c0b1c58;
P_0c0b1c58: /* original 8808, guest PC 0x0c0b1c58 */
if(!s->budget--) { s->failed_pc=0x0c0b1c58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0b1c5a;
P_0c0b1c5a: /* original 8b02, guest PC 0x0c0b1c5a */
if(!s->budget--) { s->failed_pc=0x0c0b1c5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1c62; }
goto P_0c0b1c5c;
P_0c0b1c5c: /* original 60c3, guest PC 0x0c0b1c5c */
if(!s->budget--) { s->failed_pc=0x0c0b1c5cu; return 0; }
r[0]=r[12];
goto P_0c0b1c5e;
P_0c0b1c5e: /* original 8801, guest PC 0x0c0b1c5e */
if(!s->budget--) { s->failed_pc=0x0c0b1c5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0b1c60;
P_0c0b1c60: /* original 8906, guest PC 0x0c0b1c60 */
if(!s->budget--) { s->failed_pc=0x0c0b1c60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0b1c70; }
goto P_0c0b1c62;
P_0c0b1c62: /* original e307, guest PC 0x0c0b1c62 */
if(!s->budget--) { s->failed_pc=0x0c0b1c62u; return 0; }
r[3]=0x00000007u;
goto P_0c0b1c64;
P_0c0b1c64: /* original 2438, guest PC 0x0c0b1c64 */
if(!s->budget--) { s->failed_pc=0x0c0b1c64u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0b1c66;
P_0c0b1c66: /* original 8b07, guest PC 0x0c0b1c66 */
if(!s->budget--) { s->failed_pc=0x0c0b1c66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0b1c78; }
goto P_0c0b1c68;
P_0c0b1c68: /* original d328, guest PC 0x0c0b1c68 */
if(!s->budget--) { s->failed_pc=0x0c0b1c68u; return 0; }
r[3]=read(ram,0x0c0b1d0cu,4);
goto P_0c0b1c6a;
P_0c0b1c6a: /* original 9440, guest PC 0x0c0b1c6a */
if(!s->budget--) { s->failed_pc=0x0c0b1c6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b1ceeu,2);
goto P_0c0b1c6c;
P_0c0b1c6c: /* original 430b, guest PC 0x0c0b1c6c */
if(!s->budget--) { s->failed_pc=0x0c0b1c6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1c70u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c70u) { target=s->pc; goto dispatch; }
goto P_0c0b1c70;
P_0c0b1c6e: /* original 34ec, guest PC 0x0c0b1c6e */
if(!s->budget--) { s->failed_pc=0x0c0b1c6eu; return 0; }
r[4]+=r[14];
goto P_0c0b1c70;
P_0c0b1c70: /* original d327, guest PC 0x0c0b1c70 */
if(!s->budget--) { s->failed_pc=0x0c0b1c70u; return 0; }
r[3]=read(ram,0x0c0b1d10u,4);
goto P_0c0b1c72;
P_0c0b1c72: /* original 85d2, guest PC 0x0c0b1c72 */
if(!s->budget--) { s->failed_pc=0x0c0b1c72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c0b1c74;
P_0c0b1c74: /* original 430b, guest PC 0x0c0b1c74 */
if(!s->budget--) { s->failed_pc=0x0c0b1c74u; return 0; }
target=r[3];
r[16]=code_base|0x0c0b1c78u;
r[4]=r[0]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b1c78u) { target=s->pc; goto dispatch; }
goto P_0c0b1c78;
P_0c0b1c76: /* original 640d, guest PC 0x0c0b1c76 */
if(!s->budget--) { s->failed_pc=0x0c0b1c76u; return 0; }
r[4]=r[0]&65535u;
goto P_0c0b1c78;
P_0c0b1c78: /* original 7cff, guest PC 0x0c0b1c78 */
if(!s->budget--) { s->failed_pc=0x0c0b1c78u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0b1c7a;
P_0c0b1c7a: /* original af93, guest PC 0x0c0b1c7a */
if(!s->budget--) { s->failed_pc=0x0c0b1c7au; return 0; }
r[13]+=0x00000018u;
goto P_0c0b1ba4;
P_0c0b1c7c: /* original 7d18, guest PC 0x0c0b1c7c */
if(!s->budget--) { s->failed_pc=0x0c0b1c7cu; return 0; }
r[13]+=0x00000018u;
goto P_0c0b1c7e;
P_0c0b1c7e: /* original 7f10, guest PC 0x0c0b1c7e */
if(!s->budget--) { s->failed_pc=0x0c0b1c7eu; return 0; }
r[15]+=0x00000010u;
goto P_0c0b1c80;
P_0c0b1c80: /* original 4f26, guest PC 0x0c0b1c80 */
if(!s->budget--) { s->failed_pc=0x0c0b1c80u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b1c82;
P_0c0b1c82: /* original 6af6, guest PC 0x0c0b1c82 */
if(!s->budget--) { s->failed_pc=0x0c0b1c82u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b1c84;
P_0c0b1c84: /* original 6bf6, guest PC 0x0c0b1c84 */
if(!s->budget--) { s->failed_pc=0x0c0b1c84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b1c86;
P_0c0b1c86: /* original 6cf6, guest PC 0x0c0b1c86 */
if(!s->budget--) { s->failed_pc=0x0c0b1c86u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b1c88;
P_0c0b1c88: /* original 6df6, guest PC 0x0c0b1c88 */
if(!s->budget--) { s->failed_pc=0x0c0b1c88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b1c8a;
P_0c0b1c8a: /* original 000b, guest PC 0x0c0b1c8a */
if(!s->budget--) { s->failed_pc=0x0c0b1c8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b1c8c: /* original 6ef6, guest PC 0x0c0b1c8c */
if(!s->budget--) { s->failed_pc=0x0c0b1c8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b1c8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b1c8eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
