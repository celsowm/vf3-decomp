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
int vf3_away_batch221_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
return vf3_matrix_family(0x0c0b1decu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
