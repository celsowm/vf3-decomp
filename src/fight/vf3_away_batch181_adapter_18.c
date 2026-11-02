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
int vf3_away_batch181_adapter_18(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2b98u: goto P_0c0a2b98;
case 0x0c0a2b9au: goto P_0c0a2b9a;
case 0x0c0a2b9cu: goto P_0c0a2b9c;
case 0x0c0a2b9eu: goto P_0c0a2b9e;
case 0x0c0a2ba0u: goto P_0c0a2ba0;
case 0x0c0a2ba2u: goto P_0c0a2ba2;
case 0x0c0a2ba4u: goto P_0c0a2ba4;
case 0x0c0a2ba6u: goto P_0c0a2ba6;
case 0x0c0a2ba8u: goto P_0c0a2ba8;
case 0x0c0a2baau: goto P_0c0a2baa;
case 0x0c0a2bacu: goto P_0c0a2bac;
case 0x0c0a2baeu: goto P_0c0a2bae;
case 0x0c0a2bb0u: goto P_0c0a2bb0;
case 0x0c0a2bb2u: goto P_0c0a2bb2;
case 0x0c0a2bb4u: goto P_0c0a2bb4;
case 0x0c0a2bb6u: goto P_0c0a2bb6;
case 0x0c0a2bb8u: goto P_0c0a2bb8;
case 0x0c0a2bbau: goto P_0c0a2bba;
case 0x0c0a2bbcu: goto P_0c0a2bbc;
case 0x0c0a2bbeu: goto P_0c0a2bbe;
case 0x0c0a2bc0u: goto P_0c0a2bc0;
case 0x0c0a2bc2u: goto P_0c0a2bc2;
case 0x0c0a2bc4u: goto P_0c0a2bc4;
case 0x0c0a2bc6u: goto P_0c0a2bc6;
case 0x0c0a2bc8u: goto P_0c0a2bc8;
case 0x0c0a2bcau: goto P_0c0a2bca;
case 0x0c0a2bccu: goto P_0c0a2bcc;
case 0x0c0a2bceu: goto P_0c0a2bce;
case 0x0c0a2bd0u: goto P_0c0a2bd0;
case 0x0c0a2bd2u: goto P_0c0a2bd2;
case 0x0c0a2bd4u: goto P_0c0a2bd4;
case 0x0c0a2bd6u: goto P_0c0a2bd6;
case 0x0c0a2bd8u: goto P_0c0a2bd8;
case 0x0c0a2bdau: goto P_0c0a2bda;
case 0x0c0a2bdcu: goto P_0c0a2bdc;
case 0x0c0a2bdeu: goto P_0c0a2bde;
case 0x0c0a2be0u: goto P_0c0a2be0;
case 0x0c0a2be2u: goto P_0c0a2be2;
case 0x0c0a2be4u: goto P_0c0a2be4;
case 0x0c0a2be6u: goto P_0c0a2be6;
case 0x0c0a2be8u: goto P_0c0a2be8;
case 0x0c0a2beau: goto P_0c0a2bea;
case 0x0c0a2becu: goto P_0c0a2bec;
case 0x0c0a2beeu: goto P_0c0a2bee;
case 0x0c0a2bf0u: goto P_0c0a2bf0;
case 0x0c0a2bf2u: goto P_0c0a2bf2;
case 0x0c0a2bf4u: goto P_0c0a2bf4;
case 0x0c0a2bf6u: goto P_0c0a2bf6;
case 0x0c0a2bf8u: goto P_0c0a2bf8;
case 0x0c0a2bfau: goto P_0c0a2bfa;
case 0x0c0a2bfcu: goto P_0c0a2bfc;
case 0x0c0a2bfeu: goto P_0c0a2bfe;
case 0x0c0a2c00u: goto P_0c0a2c00;
case 0x0c0a2c02u: goto P_0c0a2c02;
case 0x0c0a2c04u: goto P_0c0a2c04;
case 0x0c0a2c06u: goto P_0c0a2c06;
case 0x0c0a2c08u: goto P_0c0a2c08;
case 0x0c0a2c0au: goto P_0c0a2c0a;
case 0x0c0a2c0cu: goto P_0c0a2c0c;
case 0x0c0a2c0eu: goto P_0c0a2c0e;
case 0x0c0a2c10u: goto P_0c0a2c10;
case 0x0c0a2c12u: goto P_0c0a2c12;
case 0x0c0a2c14u: goto P_0c0a2c14;
case 0x0c0a2c16u: goto P_0c0a2c16;
case 0x0c0a2c18u: goto P_0c0a2c18;
case 0x0c0a2c1au: goto P_0c0a2c1a;
case 0x0c0a2c1cu: goto P_0c0a2c1c;
case 0x0c0a2c1eu: goto P_0c0a2c1e;
case 0x0c0a2c20u: goto P_0c0a2c20;
case 0x0c0a2c22u: goto P_0c0a2c22;
case 0x0c0a2c24u: goto P_0c0a2c24;
case 0x0c0a2c26u: goto P_0c0a2c26;
case 0x0c0a2c28u: goto P_0c0a2c28;
case 0x0c0a2c2au: goto P_0c0a2c2a;
case 0x0c0a2c2cu: goto P_0c0a2c2c;
case 0x0c0a2c2eu: goto P_0c0a2c2e;
case 0x0c0a2c30u: goto P_0c0a2c30;
case 0x0c0a2c32u: goto P_0c0a2c32;
case 0x0c0a2c34u: goto P_0c0a2c34;
case 0x0c0a7a0cu: goto P_0c0a7a0c;
case 0x0c0a7a0eu: goto P_0c0a7a0e;
case 0x0c0a7a10u: goto P_0c0a7a10;
case 0x0c0a7a12u: goto P_0c0a7a12;
case 0x0c0a7a14u: goto P_0c0a7a14;
case 0x0c0a7a16u: goto P_0c0a7a16;
case 0x0c0a7a18u: goto P_0c0a7a18;
case 0x0c0a7a1au: goto P_0c0a7a1a;
case 0x0c0a7a1cu: goto P_0c0a7a1c;
case 0x0c0a7a1eu: goto P_0c0a7a1e;
case 0x0c0a7a20u: goto P_0c0a7a20;
case 0x0c0a7a22u: goto P_0c0a7a22;
case 0x0c0a7a24u: goto P_0c0a7a24;
case 0x0c0a7a26u: goto P_0c0a7a26;
case 0x0c0a7a28u: goto P_0c0a7a28;
case 0x0c0a7a2au: goto P_0c0a7a2a;
case 0x0c0a7a2cu: goto P_0c0a7a2c;
case 0x0c0a7a2eu: goto P_0c0a7a2e;
case 0x0c0a7a30u: goto P_0c0a7a30;
case 0x0c0a7a32u: goto P_0c0a7a32;
case 0x0c0a7a34u: goto P_0c0a7a34;
case 0x0c0a7a36u: goto P_0c0a7a36;
case 0x0c0a7a38u: goto P_0c0a7a38;
case 0x0c0a7a3au: goto P_0c0a7a3a;
case 0x0c0a7a3cu: goto P_0c0a7a3c;
case 0x0c0a7a3eu: goto P_0c0a7a3e;
case 0x0c0a7a40u: goto P_0c0a7a40;
case 0x0c0a7a42u: goto P_0c0a7a42;
case 0x0c0a7a44u: goto P_0c0a7a44;
case 0x0c0a7a46u: goto P_0c0a7a46;
case 0x0c0a7a48u: goto P_0c0a7a48;
case 0x0c0a7a4au: goto P_0c0a7a4a;
case 0x0c0a7a4cu: goto P_0c0a7a4c;
case 0x0c0a7a4eu: goto P_0c0a7a4e;
case 0x0c0a7a50u: goto P_0c0a7a50;
case 0x0c0a7a52u: goto P_0c0a7a52;
case 0x0c0a7a54u: goto P_0c0a7a54;
case 0x0c0a7a56u: goto P_0c0a7a56;
case 0x0c0a7a58u: goto P_0c0a7a58;
case 0x0c0a7a5au: goto P_0c0a7a5a;
case 0x0c0a7a5cu: goto P_0c0a7a5c;
case 0x0c0a7a5eu: goto P_0c0a7a5e;
case 0x0c0a7a60u: goto P_0c0a7a60;
case 0x0c0a7a62u: goto P_0c0a7a62;
case 0x0c0a7a64u: goto P_0c0a7a64;
case 0x0c0a7a66u: goto P_0c0a7a66;
case 0x0c0a7a68u: goto P_0c0a7a68;
case 0x0c0a7a6au: goto P_0c0a7a6a;
case 0x0c0a7a6cu: goto P_0c0a7a6c;
case 0x0c0a7a6eu: goto P_0c0a7a6e;
case 0x0c0a7a70u: goto P_0c0a7a70;
case 0x0c0a7a72u: goto P_0c0a7a72;
case 0x0c0a7a74u: goto P_0c0a7a74;
case 0x0c0a7a76u: goto P_0c0a7a76;
case 0x0c0a7a78u: goto P_0c0a7a78;
case 0x0c0a7a7au: goto P_0c0a7a7a;
case 0x0c0a7a7cu: goto P_0c0a7a7c;
case 0x0c0a7a7eu: goto P_0c0a7a7e;
case 0x0c0a7a80u: goto P_0c0a7a80;
case 0x0c0a7a82u: goto P_0c0a7a82;
case 0x0c0a7a84u: goto P_0c0a7a84;
case 0x0c0a7a86u: goto P_0c0a7a86;
case 0x0c0a7a88u: goto P_0c0a7a88;
case 0x0c0a7a8au: goto P_0c0a7a8a;
case 0x0c0a7a8cu: goto P_0c0a7a8c;
case 0x0c0a7a8eu: goto P_0c0a7a8e;
case 0x0c0a7a90u: goto P_0c0a7a90;
case 0x0c0a7a92u: goto P_0c0a7a92;
case 0x0c0a7a94u: goto P_0c0a7a94;
case 0x0c0a7a96u: goto P_0c0a7a96;
case 0x0c0a7a98u: goto P_0c0a7a98;
case 0x0c0a7a9au: goto P_0c0a7a9a;
case 0x0c0a7a9cu: goto P_0c0a7a9c;
case 0x0c0a7a9eu: goto P_0c0a7a9e;
case 0x0c0a7aa0u: goto P_0c0a7aa0;
case 0x0c0a7aa2u: goto P_0c0a7aa2;
case 0x0c0a7ae0u: goto P_0c0a7ae0;
case 0x0c0a7ae2u: goto P_0c0a7ae2;
case 0x0c0a7ae4u: goto P_0c0a7ae4;
case 0x0c0a7ae6u: goto P_0c0a7ae6;
case 0x0c0a7ae8u: goto P_0c0a7ae8;
case 0x0c0a7aeau: goto P_0c0a7aea;
case 0x0c0a7aecu: goto P_0c0a7aec;
case 0x0c0a7aeeu: goto P_0c0a7aee;
case 0x0c0a7af0u: goto P_0c0a7af0;
case 0x0c0a7af2u: goto P_0c0a7af2;
case 0x0c0a7af4u: goto P_0c0a7af4;
case 0x0c0a7af6u: goto P_0c0a7af6;
case 0x0c0a7af8u: goto P_0c0a7af8;
case 0x0c0a7afau: goto P_0c0a7afa;
case 0x0c0a7afcu: goto P_0c0a7afc;
case 0x0c0a7afeu: goto P_0c0a7afe;
case 0x0c0a7b00u: goto P_0c0a7b00;
case 0x0c0a7b02u: goto P_0c0a7b02;
case 0x0c0a7b04u: goto P_0c0a7b04;
case 0x0c0a7b06u: goto P_0c0a7b06;
case 0x0c0a7b08u: goto P_0c0a7b08;
case 0x0c0a7b0au: goto P_0c0a7b0a;
case 0x0c0a7b0cu: goto P_0c0a7b0c;
case 0x0c0a7b0eu: goto P_0c0a7b0e;
case 0x0c0a7b10u: goto P_0c0a7b10;
case 0x0c0a7b12u: goto P_0c0a7b12;
case 0x0c0a7b14u: goto P_0c0a7b14;
case 0x0c0a7b16u: goto P_0c0a7b16;
case 0x0c0a7b18u: goto P_0c0a7b18;
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2b98: /* original 2fe6, guest PC 0x0c0a2b98 */
if(!s->budget--) { s->failed_pc=0x0c0a2b98u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9a;
P_0c0a2b9a: /* original 6e43, guest PC 0x0c0a2b9a */
if(!s->budget--) { s->failed_pc=0x0c0a2b9au; return 0; }
r[14]=r[4];
goto P_0c0a2b9c;
P_0c0a2b9c: /* original 2fd6, guest PC 0x0c0a2b9c */
if(!s->budget--) { s->failed_pc=0x0c0a2b9cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2b9e;
P_0c0a2b9e: /* original 2fc6, guest PC 0x0c0a2b9e */
if(!s->budget--) { s->failed_pc=0x0c0a2b9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba0;
P_0c0a2ba0: /* original 2fb6, guest PC 0x0c0a2ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba2;
P_0c0a2ba2: /* original 2fa6, guest PC 0x0c0a2ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba4;
P_0c0a2ba4: /* original 2f96, guest PC 0x0c0a2ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba6;
P_0c0a2ba6: /* original 2f86, guest PC 0x0c0a2ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2ba8;
P_0c0a2ba8: /* original 60e2, guest PC 0x0c0a2ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ba8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a2baa;
P_0c0a2baa: /* original 4f22, guest PC 0x0c0a2baa */
if(!s->budget--) { s->failed_pc=0x0c0a2baau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2bac;
P_0c0a2bac: /* original c880, guest PC 0x0c0a2bac */
if(!s->budget--) { s->failed_pc=0x0c0a2bacu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2bae;
P_0c0a2bae: /* original 8938, guest PC 0x0c0a2bae */
if(!s->budget--) { s->failed_pc=0x0c0a2baeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bb0;
P_0c0a2bb0: /* original 62e2, guest PC 0x0c0a2bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb0u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a2bb2;
P_0c0a2bb2: /* original d33b, guest PC 0x0c0a2bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb2u; return 0; }
r[3]=read(ram,0x0c0a2ca0u,4);
goto P_0c0a2bb4;
P_0c0a2bb4: /* original 9173, guest PC 0x0c0a2bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a2c9eu,2);
goto P_0c0a2bb6;
P_0c0a2bb6: /* original 2239, guest PC 0x0c0a2bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb6u; return 0; }
r[2]&=r[3];
goto P_0c0a2bb8;
P_0c0a2bb8: /* original 3210, guest PC 0x0c0a2bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0a2bba;
P_0c0a2bba: /* original 8905, guest PC 0x0c0a2bba */
if(!s->budget--) { s->failed_pc=0x0c0a2bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2bc8; }
goto P_0c0a2bbc;
P_0c0a2bbc: /* original d239, guest PC 0x0c0a2bbc */
if(!s->budget--) { s->failed_pc=0x0c0a2bbcu; return 0; }
r[2]=read(ram,0x0c0a2ca4u,4);
goto P_0c0a2bbe;
P_0c0a2bbe: /* original e56a, guest PC 0x0c0a2bbe */
if(!s->budget--) { s->failed_pc=0x0c0a2bbeu; return 0; }
r[5]=0x0000006au;
goto P_0c0a2bc0;
P_0c0a2bc0: /* original 420b, guest PC 0x0c0a2bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2bc4u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a2bc4;
P_0c0a2bc2: /* original e401, guest PC 0x0c0a2bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc2u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2bc4;
P_0c0a2bc4: /* original a02e, guest PC 0x0c0a2bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc4u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2c24;
P_0c0a2bc6: /* original e0ff, guest PC 0x0c0a2bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc6u; return 0; }
r[0]=0xffffffffu;
goto P_0c0a2bc8;
P_0c0a2bc8: /* original e020, guest PC 0x0c0a2bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bc8u; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bca;
P_0c0a2bca: /* original 03ed, guest PC 0x0c0a2bca */
if(!s->budget--) { s->failed_pc=0x0c0a2bcau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bcc;
P_0c0a2bcc: /* original e022, guest PC 0x0c0a2bcc */
if(!s->budget--) { s->failed_pc=0x0c0a2bccu; return 0; }
r[0]=0x00000022u;
goto P_0c0a2bce;
P_0c0a2bce: /* original 02ed, guest PC 0x0c0a2bce */
if(!s->budget--) { s->failed_pc=0x0c0a2bceu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2bd0;
P_0c0a2bd0: /* original 633d, guest PC 0x0c0a2bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd0u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2bd2;
P_0c0a2bd2: /* original 622d, guest PC 0x0c0a2bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a2bd4;
P_0c0a2bd4: /* original 232b, guest PC 0x0c0a2bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd4u; return 0; }
r[3]|=r[2];
goto P_0c0a2bd6;
P_0c0a2bd6: /* original 2338, guest PC 0x0c0a2bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2bd8;
P_0c0a2bd8: /* original 8923, guest PC 0x0c0a2bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c22; }
goto P_0c0a2bda;
P_0c0a2bda: /* original e020, guest PC 0x0c0a2bda */
if(!s->budget--) { s->failed_pc=0x0c0a2bdau; return 0; }
r[0]=0x00000020u;
goto P_0c0a2bdc;
P_0c0a2bdc: /* original d332, guest PC 0x0c0a2bdc */
if(!s->budget--) { s->failed_pc=0x0c0a2bdcu; return 0; }
r[3]=read(ram,0x0c0a2ca8u,4);
goto P_0c0a2bde;
P_0c0a2bde: /* original 04ed, guest PC 0x0c0a2bde */
if(!s->budget--) { s->failed_pc=0x0c0a2bdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2be0;
P_0c0a2be0: /* original 430b, guest PC 0x0c0a2be0 */
if(!s->budget--) { s->failed_pc=0x0c0a2be0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2be4u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2be4u) { target=s->pc; goto dispatch; }
goto P_0c0a2be4;
P_0c0a2be2: /* original 644d, guest PC 0x0c0a2be2 */
if(!s->budget--) { s->failed_pc=0x0c0a2be2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2be4;
P_0c0a2be4: /* original d932, guest PC 0x0c0a2be4 */
if(!s->budget--) { s->failed_pc=0x0c0a2be4u; return 0; }
r[9]=read(ram,0x0c0a2cb0u,4);
goto P_0c0a2be6;
P_0c0a2be6: /* original eb01, guest PC 0x0c0a2be6 */
if(!s->budget--) { s->failed_pc=0x0c0a2be6u; return 0; }
r[11]=0x00000001u;
goto P_0c0a2be8;
P_0c0a2be8: /* original d830, guest PC 0x0c0a2be8 */
if(!s->budget--) { s->failed_pc=0x0c0a2be8u; return 0; }
r[8]=read(ram,0x0c0a2cacu,4);
goto P_0c0a2bea;
P_0c0a2bea: /* original 5ae4, guest PC 0x0c0a2bea */
if(!s->budget--) { s->failed_pc=0x0c0a2beau; return 0; }
r[10]=read(ram,r[14]+16,4);
goto P_0c0a2bec;
P_0c0a2bec: /* original a010, guest PC 0x0c0a2bec */
if(!s->budget--) { s->failed_pc=0x0c0a2becu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2c10;
P_0c0a2bee: /* original ec00, guest PC 0x0c0a2bee */
if(!s->budget--) { s->failed_pc=0x0c0a2beeu; return 0; }
r[12]=0x00000000u;
goto P_0c0a2bf0;
P_0c0a2bf0: /* original 6dc3, guest PC 0x0c0a2bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf0u; return 0; }
r[13]=r[12];
goto P_0c0a2bf2;
P_0c0a2bf2: /* original 4d08, guest PC 0x0c0a2bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf2u; return 0; }
r[13]<<=2;
goto P_0c0a2bf4;
P_0c0a2bf4: /* original 3dac, guest PC 0x0c0a2bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf4u; return 0; }
r[13]+=r[10];
goto P_0c0a2bf6;
P_0c0a2bf6: /* original 63d2, guest PC 0x0c0a2bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0a2bf8;
P_0c0a2bf8: /* original 5231, guest PC 0x0c0a2bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2bf8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2bfa;
P_0c0a2bfa: /* original 22b8, guest PC 0x0c0a2bfa */
if(!s->budget--) { s->failed_pc=0x0c0a2bfau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[11])==0)!=0);
goto P_0c0a2bfc;
P_0c0a2bfc: /* original 8903, guest PC 0x0c0a2bfc */
if(!s->budget--) { s->failed_pc=0x0c0a2bfcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2c06; }
goto P_0c0a2bfe;
P_0c0a2bfe: /* original 480b, guest PC 0x0c0a2bfe */
if(!s->budget--) { s->failed_pc=0x0c0a2bfeu; return 0; }
target=r[8];
r[16]=code_base|0x0c0a2c02u;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c02u) { target=s->pc; goto dispatch; }
goto P_0c0a2c02;
P_0c0a2c00: /* original 64d2, guest PC 0x0c0a2c00 */
if(!s->budget--) { s->failed_pc=0x0c0a2c00u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c02;
P_0c0a2c02: /* original a004, guest PC 0x0c0a2c02 */
if(!s->budget--) { s->failed_pc=0x0c0a2c02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c04: /* original 2008, guest PC 0x0c0a2c04 */
if(!s->budget--) { s->failed_pc=0x0c0a2c04u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c06;
P_0c0a2c06: /* original 64d2, guest PC 0x0c0a2c06 */
if(!s->budget--) { s->failed_pc=0x0c0a2c06u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2c08;
P_0c0a2c08: /* original 490b, guest PC 0x0c0a2c08 */
if(!s->budget--) { s->failed_pc=0x0c0a2c08u; return 0; }
target=r[9];
r[16]=code_base|0x0c0a2c0cu;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2c0cu) { target=s->pc; goto dispatch; }
goto P_0c0a2c0c;
P_0c0a2c0a: /* original 5441, guest PC 0x0c0a2c0a */
if(!s->budget--) { s->failed_pc=0x0c0a2c0au; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2c0c;
P_0c0a2c0c: /* original 2008, guest PC 0x0c0a2c0c */
if(!s->budget--) { s->failed_pc=0x0c0a2c0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2c0e;
P_0c0a2c0e: /* original 7c01, guest PC 0x0c0a2c0e */
if(!s->budget--) { s->failed_pc=0x0c0a2c0eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0a2c10;
P_0c0a2c10: /* original 85e6, guest PC 0x0c0a2c10 */
if(!s->budget--) { s->failed_pc=0x0c0a2c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2c12;
P_0c0a2c12: /* original 600d, guest PC 0x0c0a2c12 */
if(!s->budget--) { s->failed_pc=0x0c0a2c12u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2c14;
P_0c0a2c14: /* original 3c03, guest PC 0x0c0a2c14 */
if(!s->budget--) { s->failed_pc=0x0c0a2c14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[0])!=0);
goto P_0c0a2c16;
P_0c0a2c16: /* original 8beb, guest PC 0x0c0a2c16 */
if(!s->budget--) { s->failed_pc=0x0c0a2c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2bf0; }
goto P_0c0a2c18;
P_0c0a2c18: /* original e022, guest PC 0x0c0a2c18 */
if(!s->budget--) { s->failed_pc=0x0c0a2c18u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2c1a;
P_0c0a2c1a: /* original e200, guest PC 0x0c0a2c1a */
if(!s->budget--) { s->failed_pc=0x0c0a2c1au; return 0; }
r[2]=0x00000000u;
goto P_0c0a2c1c;
P_0c0a2c1c: /* original 0e25, guest PC 0x0c0a2c1c */
if(!s->budget--) { s->failed_pc=0x0c0a2c1cu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c1e;
P_0c0a2c1e: /* original e020, guest PC 0x0c0a2c1e */
if(!s->budget--) { s->failed_pc=0x0c0a2c1eu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2c20;
P_0c0a2c20: /* original 0e25, guest PC 0x0c0a2c20 */
if(!s->budget--) { s->failed_pc=0x0c0a2c20u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0a2c22;
P_0c0a2c22: /* original e000, guest PC 0x0c0a2c22 */
if(!s->budget--) { s->failed_pc=0x0c0a2c22u; return 0; }
r[0]=0x00000000u;
goto P_0c0a2c24;
P_0c0a2c24: /* original 4f26, guest PC 0x0c0a2c24 */
if(!s->budget--) { s->failed_pc=0x0c0a2c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2c26;
P_0c0a2c26: /* original 68f6, guest PC 0x0c0a2c26 */
if(!s->budget--) { s->failed_pc=0x0c0a2c26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2c28;
P_0c0a2c28: /* original 69f6, guest PC 0x0c0a2c28 */
if(!s->budget--) { s->failed_pc=0x0c0a2c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2c2a;
P_0c0a2c2a: /* original 6af6, guest PC 0x0c0a2c2a */
if(!s->budget--) { s->failed_pc=0x0c0a2c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2c2c;
P_0c0a2c2c: /* original 6bf6, guest PC 0x0c0a2c2c */
if(!s->budget--) { s->failed_pc=0x0c0a2c2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2c2e;
P_0c0a2c2e: /* original 6cf6, guest PC 0x0c0a2c2e */
if(!s->budget--) { s->failed_pc=0x0c0a2c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2c30;
P_0c0a2c30: /* original 6df6, guest PC 0x0c0a2c30 */
if(!s->budget--) { s->failed_pc=0x0c0a2c30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2c32;
P_0c0a2c32: /* original 000b, guest PC 0x0c0a2c32 */
if(!s->budget--) { s->failed_pc=0x0c0a2c32u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2c34: /* original 6ef6, guest PC 0x0c0a2c34 */
if(!s->budget--) { s->failed_pc=0x0c0a2c34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2c36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c36u; return 0; } return 1;
P_0c0a7a0c: /* original 2fe6, guest PC 0x0c0a7a0c */
if(!s->budget--) { s->failed_pc=0x0c0a7a0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a0e;
P_0c0a7a0e: /* original 6743, guest PC 0x0c0a7a0e */
if(!s->budget--) { s->failed_pc=0x0c0a7a0eu; return 0; }
r[7]=r[4];
goto P_0c0a7a10;
P_0c0a7a10: /* original 2fd6, guest PC 0x0c0a7a10 */
if(!s->budget--) { s->failed_pc=0x0c0a7a10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7a12;
P_0c0a7a12: /* original 4728, guest PC 0x0c0a7a12 */
if(!s->budget--) { s->failed_pc=0x0c0a7a12u; return 0; }
r[7]<<=16;
goto P_0c0a7a14;
P_0c0a7a14: /* original fffb, guest PC 0x0c0a7a14 */
if(!s->budget--) { s->failed_pc=0x0c0a7a14u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0a7a16;
P_0c0a7a16: /* original 6e73, guest PC 0x0c0a7a16 */
if(!s->budget--) { s->failed_pc=0x0c0a7a16u; return 0; }
r[14]=r[7];
goto P_0c0a7a18;
P_0c0a7a18: /* original 4518, guest PC 0x0c0a7a18 */
if(!s->budget--) { s->failed_pc=0x0c0a7a18u; return 0; }
r[5]<<=8;
goto P_0c0a7a1a;
P_0c0a7a1a: /* original 6463, guest PC 0x0c0a7a1a */
if(!s->budget--) { s->failed_pc=0x0c0a7a1au; return 0; }
r[4]=r[6];
goto P_0c0a7a1c;
P_0c0a7a1c: /* original 4f22, guest PC 0x0c0a7a1c */
if(!s->budget--) { s->failed_pc=0x0c0a7a1cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7a1e;
P_0c0a7a1e: /* original 2e5b, guest PC 0x0c0a7a1e */
if(!s->budget--) { s->failed_pc=0x0c0a7a1eu; return 0; }
r[14]|=r[5];
goto P_0c0a7a20;
P_0c0a7a20: /* original 2e4b, guest PC 0x0c0a7a20 */
if(!s->budget--) { s->failed_pc=0x0c0a7a20u; return 0; }
r[14]|=r[4];
goto P_0c0a7a22;
P_0c0a7a22: /* original 7ffc, guest PC 0x0c0a7a22 */
if(!s->budget--) { s->failed_pc=0x0c0a7a22u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7a24;
P_0c0a7a24: /* original ff4a, guest PC 0x0c0a7a24 */
if(!s->budget--) { s->failed_pc=0x0c0a7a24u; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c0a7a26;
P_0c0a7a26: /* original d327, guest PC 0x0c0a7a26 */
if(!s->budget--) { s->failed_pc=0x0c0a7a26u; return 0; }
r[3]=read(ram,0x0c0a7ac4u,4);
goto P_0c0a7a28;
P_0c0a7a28: /* original 903c, guest PC 0x0c0a7a28 */
if(!s->budget--) { s->failed_pc=0x0c0a7a28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa4u,2);
goto P_0c0a7a2a;
P_0c0a7a2a: /* original dd27, guest PC 0x0c0a7a2a */
if(!s->budget--) { s->failed_pc=0x0c0a7a2au; return 0; }
r[13]=read(ram,0x0c0a7ac8u,4);
goto P_0c0a7a2c;
P_0c0a7a2c: /* original 2e3b, guest PC 0x0c0a7a2c */
if(!s->budget--) { s->failed_pc=0x0c0a7a2cu; return 0; }
r[14]|=r[3];
goto P_0c0a7a2e;
P_0c0a7a2e: /* original ff5c, guest PC 0x0c0a7a2e */
if(!s->budget--) { s->failed_pc=0x0c0a7a2eu; return 0; }
vf3_matrix_move(s,15,5);
goto P_0c0a7a30;
P_0c0a7a30: /* original 0de6, guest PC 0x0c0a7a30 */
if(!s->budget--) { s->failed_pc=0x0c0a7a30u; return 0; }
write(ram,r[13]+r[0],r[14],4);
goto P_0c0a7a32;
P_0c0a7a32: /* original d226, guest PC 0x0c0a7a32 */
if(!s->budget--) { s->failed_pc=0x0c0a7a32u; return 0; }
r[2]=read(ram,0x0c0a7accu,4);
goto P_0c0a7a34;
P_0c0a7a34: /* original 420b, guest PC 0x0c0a7a34 */
if(!s->budget--) { s->failed_pc=0x0c0a7a34u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7a38u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a38u) { target=s->pc; goto dispatch; }
goto P_0c0a7a38;
P_0c0a7a36: /* original 64e3, guest PC 0x0c0a7a36 */
if(!s->budget--) { s->failed_pc=0x0c0a7a36u; return 0; }
r[4]=r[14];
goto P_0c0a7a38;
P_0c0a7a38: /* original d325, guest PC 0x0c0a7a38 */
if(!s->budget--) { s->failed_pc=0x0c0a7a38u; return 0; }
r[3]=read(ram,0x0c0a7ad0u,4);
goto P_0c0a7a3a;
P_0c0a7a3a: /* original 65e3, guest PC 0x0c0a7a3a */
if(!s->budget--) { s->failed_pc=0x0c0a7a3au; return 0; }
r[5]=r[14];
goto P_0c0a7a3c;
P_0c0a7a3c: /* original 66e3, guest PC 0x0c0a7a3c */
if(!s->budget--) { s->failed_pc=0x0c0a7a3cu; return 0; }
r[6]=r[14];
goto P_0c0a7a3e;
P_0c0a7a3e: /* original 430b, guest PC 0x0c0a7a3e */
if(!s->budget--) { s->failed_pc=0x0c0a7a3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7a42u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7a42u) { target=s->pc; goto dispatch; }
goto P_0c0a7a42;
P_0c0a7a40: /* original 64e3, guest PC 0x0c0a7a40 */
if(!s->budget--) { s->failed_pc=0x0c0a7a40u; return 0; }
r[4]=r[14];
goto P_0c0a7a42;
P_0c0a7a42: /* original f2f8, guest PC 0x0c0a7a42 */
if(!s->budget--) { s->failed_pc=0x0c0a7a42u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c0a7a44;
P_0c0a7a44: /* original e500, guest PC 0x0c0a7a44 */
if(!s->budget--) { s->failed_pc=0x0c0a7a44u; return 0; }
r[5]=0x00000000u;
goto P_0c0a7a46;
P_0c0a7a46: /* original f38d, guest PC 0x0c0a7a46 */
if(!s->budget--) { s->failed_pc=0x0c0a7a46u; return 0; }
fr[3]=0;
goto P_0c0a7a48;
P_0c0a7a48: /* original e100, guest PC 0x0c0a7a48 */
if(!s->budget--) { s->failed_pc=0x0c0a7a48u; return 0; }
r[1]=0x00000000u;
goto P_0c0a7a4a;
P_0c0a7a4a: /* original f235, guest PC 0x0c0a7a4a */
if(!s->budget--) { s->failed_pc=0x0c0a7a4au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0a7a4c;
P_0c0a7a4c: /* original 9e2b, guest PC 0x0c0a7a4c */
if(!s->budget--) { s->failed_pc=0x0c0a7a4cu; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa6u,2);
goto P_0c0a7a4e;
P_0c0a7a4e: /* original 942b, guest PC 0x0c0a7a4e */
if(!s->budget--) { s->failed_pc=0x0c0a7a4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aa8u,2);
goto P_0c0a7a50;
P_0c0a7a50: /* original 3edc, guest PC 0x0c0a7a50 */
if(!s->budget--) { s->failed_pc=0x0c0a7a50u; return 0; }
r[14]+=r[13];
goto P_0c0a7a52;
P_0c0a7a52: /* original f68d, guest PC 0x0c0a7a52 */
if(!s->budget--) { s->failed_pc=0x0c0a7a52u; return 0; }
fr[6]=0;
goto P_0c0a7a54;
P_0c0a7a54: /* original 8d0c, guest PC 0x0c0a7a54 */
if(!s->budget--) { s->failed_pc=0x0c0a7a54u; return 0; }
cond=r[17]&1u;
r[1]+=r[14];
if(cond) { goto P_0c0a7a70; }
goto P_0c0a7a58;
P_0c0a7a56: /* original 31ec, guest PC 0x0c0a7a56 */
if(!s->budget--) { s->failed_pc=0x0c0a7a56u; return 0; }
r[1]+=r[14];
goto P_0c0a7a58;
P_0c0a7a58: /* original 6653, guest PC 0x0c0a7a58 */
if(!s->budget--) { s->failed_pc=0x0c0a7a58u; return 0; }
r[6]=r[5];
goto P_0c0a7a5a;
P_0c0a7a5a: /* original 6513, guest PC 0x0c0a7a5a */
if(!s->budget--) { s->failed_pc=0x0c0a7a5au; return 0; }
r[5]=r[1];
goto P_0c0a7a5c;
P_0c0a7a5c: /* original 7601, guest PC 0x0c0a7a5c */
if(!s->budget--) { s->failed_pc=0x0c0a7a5cu; return 0; }
r[6]+=0x00000001u;
goto P_0c0a7a5e;
P_0c0a7a5e: /* original f56a, guest PC 0x0c0a7a5e */
if(!s->budget--) { s->failed_pc=0x0c0a7a5eu; return 0; }
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c0a7a60;
P_0c0a7a60: /* original 3647, guest PC 0x0c0a7a60 */
if(!s->budget--) { s->failed_pc=0x0c0a7a60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[4])!=0);
goto P_0c0a7a62;
P_0c0a7a62: /* original 8ffb, guest PC 0x0c0a7a62 */
if(!s->budget--) { s->failed_pc=0x0c0a7a62u; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c0a7a5c; }
goto P_0c0a7a66;
P_0c0a7a64: /* original 7504, guest PC 0x0c0a7a64 */
if(!s->budget--) { s->failed_pc=0x0c0a7a64u; return 0; }
r[5]+=0x00000004u;
goto P_0c0a7a66;
P_0c0a7a66: /* original c71b, guest PC 0x0c0a7a66 */
if(!s->budget--) { s->failed_pc=0x0c0a7a66u; return 0; }
r[0]=code_base|0x000a7ad4u;
goto P_0c0a7a68;
P_0c0a7a68: /* original f308, guest PC 0x0c0a7a68 */
if(!s->budget--) { s->failed_pc=0x0c0a7a68u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a6a;
P_0c0a7a6a: /* original 901e, guest PC 0x0c0a7a6a */
if(!s->budget--) { s->failed_pc=0x0c0a7a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a6c;
P_0c0a7a6c: /* original a049, guest PC 0x0c0a7a6c */
if(!s->budget--) { s->failed_pc=0x0c0a7a6cu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7b02;
P_0c0a7a6e: /* original fd37, guest PC 0x0c0a7a6e */
if(!s->budget--) { s->failed_pc=0x0c0a7a6eu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0a7a70;
P_0c0a7a70: /* original c719, guest PC 0x0c0a7a70 */
if(!s->budget--) { s->failed_pc=0x0c0a7a70u; return 0; }
r[0]=code_base|0x000a7ad8u;
goto P_0c0a7a72;
P_0c0a7a72: /* original f59d, guest PC 0x0c0a7a72 */
if(!s->budget--) { s->failed_pc=0x0c0a7a72u; return 0; }
fr[5]=0x3f800000u;
goto P_0c0a7a74;
P_0c0a7a74: /* original f308, guest PC 0x0c0a7a74 */
if(!s->budget--) { s->failed_pc=0x0c0a7a74u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0a7a76;
P_0c0a7a76: /* original 6753, guest PC 0x0c0a7a76 */
if(!s->budget--) { s->failed_pc=0x0c0a7a76u; return 0; }
r[7]=r[5];
goto P_0c0a7a78;
P_0c0a7a78: /* original f75c, guest PC 0x0c0a7a78 */
if(!s->budget--) { s->failed_pc=0x0c0a7a78u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c0a7a7a;
P_0c0a7a7a: /* original f7f1, guest PC 0x0c0a7a7a */
if(!s->budget--) { s->failed_pc=0x0c0a7a7au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'-');
goto P_0c0a7a7c;
P_0c0a7a7c: /* original f232, guest PC 0x0c0a7a7c */
if(!s->budget--) { s->failed_pc=0x0c0a7a7cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0a7a7e;
P_0c0a7a7e: /* original 9014, guest PC 0x0c0a7a7e */
if(!s->budget--) { s->failed_pc=0x0c0a7a7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7aaau,2);
goto P_0c0a7a80;
P_0c0a7a80: /* original 6543, guest PC 0x0c0a7a80 */
if(!s->budget--) { s->failed_pc=0x0c0a7a80u; return 0; }
r[5]=r[4];
goto P_0c0a7a82;
P_0c0a7a82: /* original 6613, guest PC 0x0c0a7a82 */
if(!s->budget--) { s->failed_pc=0x0c0a7a82u; return 0; }
r[6]=r[1];
goto P_0c0a7a84;
P_0c0a7a84: /* original f47c, guest PC 0x0c0a7a84 */
if(!s->budget--) { s->failed_pc=0x0c0a7a84u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0a7a86;
P_0c0a7a86: /* original f423, guest PC 0x0c0a7a86 */
if(!s->budget--) { s->failed_pc=0x0c0a7a86u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[2],r[18],'/');
goto P_0c0a7a88;
P_0c0a7a88: /* original fd47, guest PC 0x0c0a7a88 */
if(!s->budget--) { s->failed_pc=0x0c0a7a88u; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0a7a8a;
P_0c0a7a8a: /* original c714, guest PC 0x0c0a7a8a */
if(!s->budget--) { s->failed_pc=0x0c0a7a8au; return 0; }
r[0]=code_base|0x000a7adcu;
goto P_0c0a7a8c;
P_0c0a7a8c: /* original f808, guest PC 0x0c0a7a8c */
if(!s->budget--) { s->failed_pc=0x0c0a7a8cu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0a7a8e;
P_0c0a7a8e: /* original 455a, guest PC 0x0c0a7a8e */
if(!s->budget--) { s->failed_pc=0x0c0a7a8eu; return 0; }
r[53]=r[5];
goto P_0c0a7a90;
P_0c0a7a90: /* original f28d, guest PC 0x0c0a7a90 */
if(!s->budget--) { s->failed_pc=0x0c0a7a90u; return 0; }
fr[2]=0;
goto P_0c0a7a92;
P_0c0a7a92: /* original f32d, guest PC 0x0c0a7a92 */
if(!s->budget--) { s->failed_pc=0x0c0a7a92u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0a7a94;
P_0c0a7a94: /* original f372, guest PC 0x0c0a7a94 */
if(!s->budget--) { s->failed_pc=0x0c0a7a94u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'*');
goto P_0c0a7a96;
P_0c0a7a96: /* original f383, guest PC 0x0c0a7a96 */
if(!s->budget--) { s->failed_pc=0x0c0a7a96u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'/');
goto P_0c0a7a98;
P_0c0a7a98: /* original f43c, guest PC 0x0c0a7a98 */
if(!s->budget--) { s->failed_pc=0x0c0a7a98u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0a7a9a;
P_0c0a7a9a: /* original f4f0, guest PC 0x0c0a7a9a */
if(!s->budget--) { s->failed_pc=0x0c0a7a9au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'+');
goto P_0c0a7a9c;
P_0c0a7a9c: /* original f245, guest PC 0x0c0a7a9c */
if(!s->budget--) { s->failed_pc=0x0c0a7a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c0a7a9e;
P_0c0a7a9e: /* original 8b1f, guest PC 0x0c0a7a9e */
if(!s->budget--) { s->failed_pc=0x0c0a7a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae0; }
goto P_0c0a7aa0;
P_0c0a7aa0: /* original a021, guest PC 0x0c0a7aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0a7ae6;
P_0c0a7aa2: /* original f46c, guest PC 0x0c0a7aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7aa2u; return 0; }
vf3_matrix_move(s,4,6);
if(!vf3_matrix_family(0x0c0a7aa4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7aa4u; return 0; } return 1;
P_0c0a7ae0: /* original f455, guest PC 0x0c0a7ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0a7ae2;
P_0c0a7ae2: /* original 8b00, guest PC 0x0c0a7ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7ae6; }
goto P_0c0a7ae4;
P_0c0a7ae4: /* original f45c, guest PC 0x0c0a7ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae4u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0a7ae6;
P_0c0a7ae6: /* original 7701, guest PC 0x0c0a7ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae6u; return 0; }
r[7]+=0x00000001u;
goto P_0c0a7ae8;
P_0c0a7ae8: /* original f64a, guest PC 0x0c0a7ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ae8u; return 0; }
vf3_matrix_store(s,ram,4,r[6]);
goto P_0c0a7aea;
P_0c0a7aea: /* original 3743, guest PC 0x0c0a7aea */
if(!s->budget--) { s->failed_pc=0x0c0a7aeau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[4])!=0);
goto P_0c0a7aec;
P_0c0a7aec: /* original 7604, guest PC 0x0c0a7aec */
if(!s->budget--) { s->failed_pc=0x0c0a7aecu; return 0; }
r[6]+=0x00000004u;
goto P_0c0a7aee;
P_0c0a7aee: /* original 8fce, guest PC 0x0c0a7aee */
if(!s->budget--) { s->failed_pc=0x0c0a7aeeu; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(!cond) { goto P_0c0a7a8e; }
goto P_0c0a7af2;
P_0c0a7af0: /* original 75ff, guest PC 0x0c0a7af0 */
if(!s->budget--) { s->failed_pc=0x0c0a7af0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a7af2;
P_0c0a7af2: /* original f28d, guest PC 0x0c0a7af2 */
if(!s->budget--) { s->failed_pc=0x0c0a7af2u; return 0; }
fr[2]=0;
goto P_0c0a7af4;
P_0c0a7af4: /* original f2f5, guest PC 0x0c0a7af4 */
if(!s->budget--) { s->failed_pc=0x0c0a7af4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c0a7af6;
P_0c0a7af6: /* original 8b01, guest PC 0x0c0a7af6 */
if(!s->budget--) { s->failed_pc=0x0c0a7af6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7afc; }
goto P_0c0a7af8;
P_0c0a7af8: /* original a001, guest PC 0x0c0a7af8 */
if(!s->budget--) { s->failed_pc=0x0c0a7af8u; return 0; }
fr[3]=0;
goto P_0c0a7afe;
P_0c0a7afa: /* original f38d, guest PC 0x0c0a7afa */
if(!s->budget--) { s->failed_pc=0x0c0a7afau; return 0; }
fr[3]=0;
goto P_0c0a7afc;
P_0c0a7afc: /* original f3fc, guest PC 0x0c0a7afc */
if(!s->budget--) { s->failed_pc=0x0c0a7afcu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0a7afe;
P_0c0a7afe: /* original 9042, guest PC 0x0c0a7afe */
if(!s->budget--) { s->failed_pc=0x0c0a7afeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7b86u,2);
goto P_0c0a7b00;
P_0c0a7b00: /* original fe37, guest PC 0x0c0a7b00 */
if(!s->budget--) { s->failed_pc=0x0c0a7b00u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0a7b02;
P_0c0a7b02: /* original 7f04, guest PC 0x0c0a7b02 */
if(!s->budget--) { s->failed_pc=0x0c0a7b02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7b04;
P_0c0a7b04: /* original 60d2, guest PC 0x0c0a7b04 */
if(!s->budget--) { s->failed_pc=0x0c0a7b04u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a7b06;
P_0c0a7b06: /* original 4f26, guest PC 0x0c0a7b06 */
if(!s->budget--) { s->failed_pc=0x0c0a7b06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a7b08;
P_0c0a7b08: /* original cb01, guest PC 0x0c0a7b08 */
if(!s->budget--) { s->failed_pc=0x0c0a7b08u; return 0; }
r[0]|=1u;
goto P_0c0a7b0a;
P_0c0a7b0a: /* original 2d02, guest PC 0x0c0a7b0a */
if(!s->budget--) { s->failed_pc=0x0c0a7b0au; return 0; }
write(ram,r[13],r[0],4);
goto P_0c0a7b0c;
P_0c0a7b0c: /* original e500, guest PC 0x0c0a7b0c */
if(!s->budget--) { s->failed_pc=0x0c0a7b0cu; return 0; }
r[5]=0x00000000u;
goto P_0c0a7b0e;
P_0c0a7b0e: /* original fff9, guest PC 0x0c0a7b0e */
if(!s->budget--) { s->failed_pc=0x0c0a7b0eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0a7b10;
P_0c0a7b10: /* original d320, guest PC 0x0c0a7b10 */
if(!s->budget--) { s->failed_pc=0x0c0a7b10u; return 0; }
r[3]=read(ram,0x0c0a7b94u,4);
goto P_0c0a7b12;
P_0c0a7b12: /* original 6df6, guest PC 0x0c0a7b12 */
if(!s->budget--) { s->failed_pc=0x0c0a7b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a7b14;
P_0c0a7b14: /* original d41e, guest PC 0x0c0a7b14 */
if(!s->budget--) { s->failed_pc=0x0c0a7b14u; return 0; }
r[4]=read(ram,0x0c0a7b90u,4);
goto P_0c0a7b16;
P_0c0a7b16: /* original 432b, guest PC 0x0c0a7b16 */
if(!s->budget--) { s->failed_pc=0x0c0a7b16u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0a7b18: /* original 6ef6, guest PC 0x0c0a7b18 */
if(!s->budget--) { s->failed_pc=0x0c0a7b18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a7b1au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7b1au; return 0; } return 1;
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
