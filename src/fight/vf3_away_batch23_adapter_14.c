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
int vf3_away_batch23_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0b495eu: goto P_0c0b495e;
case 0x0c0b4960u: goto P_0c0b4960;
case 0x0c0b4962u: goto P_0c0b4962;
case 0x0c0b4964u: goto P_0c0b4964;
case 0x0c0b4966u: goto P_0c0b4966;
case 0x0c0b4968u: goto P_0c0b4968;
case 0x0c0b496au: goto P_0c0b496a;
case 0x0c0b496cu: goto P_0c0b496c;
case 0x0c0b496eu: goto P_0c0b496e;
case 0x0c0b4970u: goto P_0c0b4970;
case 0x0c0b4972u: goto P_0c0b4972;
case 0x0c0b4974u: goto P_0c0b4974;
case 0x0c0b4976u: goto P_0c0b4976;
case 0x0c0b4978u: goto P_0c0b4978;
case 0x0c0b497au: goto P_0c0b497a;
case 0x0c0b497cu: goto P_0c0b497c;
case 0x0c0b497eu: goto P_0c0b497e;
case 0x0c0b4980u: goto P_0c0b4980;
case 0x0c0b4982u: goto P_0c0b4982;
case 0x0c0b4984u: goto P_0c0b4984;
case 0x0c0b4986u: goto P_0c0b4986;
case 0x0c0b4988u: goto P_0c0b4988;
case 0x0c0b498au: goto P_0c0b498a;
case 0x0c0b498cu: goto P_0c0b498c;
case 0x0c0b498eu: goto P_0c0b498e;
case 0x0c0b4990u: goto P_0c0b4990;
case 0x0c0b4992u: goto P_0c0b4992;
case 0x0c0b4994u: goto P_0c0b4994;
case 0x0c0b4996u: goto P_0c0b4996;
case 0x0c0b4998u: goto P_0c0b4998;
case 0x0c0b499au: goto P_0c0b499a;
case 0x0c0b499cu: goto P_0c0b499c;
case 0x0c0b499eu: goto P_0c0b499e;
case 0x0c0b49a0u: goto P_0c0b49a0;
case 0x0c0b49a2u: goto P_0c0b49a2;
case 0x0c0b49a4u: goto P_0c0b49a4;
case 0x0c0b49a6u: goto P_0c0b49a6;
case 0x0c0b49a8u: goto P_0c0b49a8;
case 0x0c0b49aau: goto P_0c0b49aa;
case 0x0c0b49acu: goto P_0c0b49ac;
case 0x0c0b49aeu: goto P_0c0b49ae;
case 0x0c0b49b0u: goto P_0c0b49b0;
case 0x0c0b49b2u: goto P_0c0b49b2;
case 0x0c0b49b4u: goto P_0c0b49b4;
case 0x0c0b49b6u: goto P_0c0b49b6;
case 0x0c0b49b8u: goto P_0c0b49b8;
case 0x0c0b49bau: goto P_0c0b49ba;
case 0x0c0b49bcu: goto P_0c0b49bc;
case 0x0c0b49beu: goto P_0c0b49be;
case 0x0c0b49c0u: goto P_0c0b49c0;
case 0x0c0b49c2u: goto P_0c0b49c2;
case 0x0c0b49c4u: goto P_0c0b49c4;
case 0x0c0b49c6u: goto P_0c0b49c6;
case 0x0c0b49c8u: goto P_0c0b49c8;
case 0x0c0b49cau: goto P_0c0b49ca;
case 0x0c0b49ccu: goto P_0c0b49cc;
case 0x0c0b49ceu: goto P_0c0b49ce;
case 0x0c0b49d0u: goto P_0c0b49d0;
case 0x0c0b49d2u: goto P_0c0b49d2;
case 0x0c0b49d4u: goto P_0c0b49d4;
case 0x0c0b49d6u: goto P_0c0b49d6;
case 0x0c0b49d8u: goto P_0c0b49d8;
case 0x0c0b49dau: goto P_0c0b49da;
case 0x0c0b49dcu: goto P_0c0b49dc;
case 0x0c0b49deu: goto P_0c0b49de;
case 0x0c0b49e0u: goto P_0c0b49e0;
case 0x0c0b49e2u: goto P_0c0b49e2;
case 0x0c0b49e4u: goto P_0c0b49e4;
case 0x0c0b49e6u: goto P_0c0b49e6;
case 0x0c0b49e8u: goto P_0c0b49e8;
case 0x0c0b49eau: goto P_0c0b49ea;
case 0x0c0b49ecu: goto P_0c0b49ec;
case 0x0c0b49eeu: goto P_0c0b49ee;
case 0x0c0b49f0u: goto P_0c0b49f0;
case 0x0c0b49f2u: goto P_0c0b49f2;
case 0x0c0b49f4u: goto P_0c0b49f4;
case 0x0c0b49f6u: goto P_0c0b49f6;
case 0x0c0b49f8u: goto P_0c0b49f8;
case 0x0c0b49fau: goto P_0c0b49fa;
case 0x0c0b49fcu: goto P_0c0b49fc;
case 0x0c0b49feu: goto P_0c0b49fe;
case 0x0c0b4a00u: goto P_0c0b4a00;
case 0x0c0b4a02u: goto P_0c0b4a02;
case 0x0c0b4a04u: goto P_0c0b4a04;
case 0x0c0b4a06u: goto P_0c0b4a06;
case 0x0c0b4a08u: goto P_0c0b4a08;
case 0x0c0b4a0au: goto P_0c0b4a0a;
case 0x0c0b4a0cu: goto P_0c0b4a0c;
case 0x0c0b4a0eu: goto P_0c0b4a0e;
case 0x0c0b4a10u: goto P_0c0b4a10;
case 0x0c0b4a12u: goto P_0c0b4a12;
case 0x0c0b4a14u: goto P_0c0b4a14;
case 0x0c0b4a16u: goto P_0c0b4a16;
case 0x0c0b4a18u: goto P_0c0b4a18;
case 0x0c0b4a1au: goto P_0c0b4a1a;
case 0x0c0b4a1cu: goto P_0c0b4a1c;
case 0x0c0b4a1eu: goto P_0c0b4a1e;
case 0x0c0b4a20u: goto P_0c0b4a20;
case 0x0c0b4a22u: goto P_0c0b4a22;
case 0x0c0b4a24u: goto P_0c0b4a24;
case 0x0c0b4a26u: goto P_0c0b4a26;
case 0x0c0b4a28u: goto P_0c0b4a28;
case 0x0c0b4a2au: goto P_0c0b4a2a;
case 0x0c0b4a2cu: goto P_0c0b4a2c;
case 0x0c0b4a2eu: goto P_0c0b4a2e;
case 0x0c0b4a30u: goto P_0c0b4a30;
case 0x0c0b4a32u: goto P_0c0b4a32;
case 0x0c0b4a34u: goto P_0c0b4a34;
case 0x0c0b4a36u: goto P_0c0b4a36;
case 0x0c0b4a38u: goto P_0c0b4a38;
case 0x0c0b4a3au: goto P_0c0b4a3a;
case 0x0c0b4a3cu: goto P_0c0b4a3c;
case 0x0c0b4a3eu: goto P_0c0b4a3e;
case 0x0c0b4a40u: goto P_0c0b4a40;
case 0x0c0b4a42u: goto P_0c0b4a42;
case 0x0c0b4a44u: goto P_0c0b4a44;
case 0x0c0b4a46u: goto P_0c0b4a46;
case 0x0c0b4a48u: goto P_0c0b4a48;
case 0x0c0b4a4au: goto P_0c0b4a4a;
case 0x0c0b4a4cu: goto P_0c0b4a4c;
case 0x0c0b4a4eu: goto P_0c0b4a4e;
case 0x0c0b4a50u: goto P_0c0b4a50;
case 0x0c0b4a52u: goto P_0c0b4a52;
case 0x0c0b4a54u: goto P_0c0b4a54;
case 0x0c0b4a56u: goto P_0c0b4a56;
case 0x0c0b4a58u: goto P_0c0b4a58;
case 0x0c0b4a5au: goto P_0c0b4a5a;
case 0x0c0b4a5cu: goto P_0c0b4a5c;
case 0x0c0b4a5eu: goto P_0c0b4a5e;
case 0x0c0b4a60u: goto P_0c0b4a60;
case 0x0c0b4a62u: goto P_0c0b4a62;
case 0x0c0b4a64u: goto P_0c0b4a64;
case 0x0c0b4a66u: goto P_0c0b4a66;
case 0x0c0b4a68u: goto P_0c0b4a68;
case 0x0c0b4a6au: goto P_0c0b4a6a;
case 0x0c0b4a6cu: goto P_0c0b4a6c;
case 0x0c0b4a6eu: goto P_0c0b4a6e;
case 0x0c0b4a70u: goto P_0c0b4a70;
case 0x0c0b4a72u: goto P_0c0b4a72;
case 0x0c0b4a74u: goto P_0c0b4a74;
case 0x0c0b4a76u: goto P_0c0b4a76;
case 0x0c0b4a78u: goto P_0c0b4a78;
case 0x0c0b4a7au: goto P_0c0b4a7a;
case 0x0c0b4a7cu: goto P_0c0b4a7c;
case 0x0c0b4a7eu: goto P_0c0b4a7e;
case 0x0c0b4a80u: goto P_0c0b4a80;
case 0x0c0b4a82u: goto P_0c0b4a82;
case 0x0c0b4a84u: goto P_0c0b4a84;
case 0x0c0b4a86u: goto P_0c0b4a86;
case 0x0c0b4a88u: goto P_0c0b4a88;
case 0x0c0b4a8au: goto P_0c0b4a8a;
case 0x0c0b4a8cu: goto P_0c0b4a8c;
case 0x0c0b4a8eu: goto P_0c0b4a8e;
case 0x0c0b4a90u: goto P_0c0b4a90;
case 0x0c0b4a92u: goto P_0c0b4a92;
case 0x0c0b4a94u: goto P_0c0b4a94;
case 0x0c0b4a96u: goto P_0c0b4a96;
case 0x0c0b4a98u: goto P_0c0b4a98;
case 0x0c0b4a9au: goto P_0c0b4a9a;
case 0x0c0b4a9cu: goto P_0c0b4a9c;
case 0x0c0b4a9eu: goto P_0c0b4a9e;
case 0x0c0b4aa0u: goto P_0c0b4aa0;
case 0x0c0b4aa2u: goto P_0c0b4aa2;
case 0x0c0b4aa4u: goto P_0c0b4aa4;
case 0x0c0b4aa6u: goto P_0c0b4aa6;
case 0x0c0b4aa8u: goto P_0c0b4aa8;
case 0x0c0b4aaau: goto P_0c0b4aaa;
case 0x0c0b4aacu: goto P_0c0b4aac;
case 0x0c0b4aaeu: goto P_0c0b4aae;
case 0x0c0b4ab0u: goto P_0c0b4ab0;
case 0x0c0b4ab2u: goto P_0c0b4ab2;
case 0x0c0b4ab4u: goto P_0c0b4ab4;
case 0x0c0b4ab6u: goto P_0c0b4ab6;
case 0x0c0b4ab8u: goto P_0c0b4ab8;
case 0x0c0b4abau: goto P_0c0b4aba;
case 0x0c0b4abcu: goto P_0c0b4abc;
case 0x0c0b4abeu: goto P_0c0b4abe;
case 0x0c0b4ac0u: goto P_0c0b4ac0;
case 0x0c0b4b30u: goto P_0c0b4b30;
case 0x0c0b4b32u: goto P_0c0b4b32;
case 0x0c0b4b34u: goto P_0c0b4b34;
case 0x0c0b4b36u: goto P_0c0b4b36;
case 0x0c0b4b38u: goto P_0c0b4b38;
case 0x0c0b4b3au: goto P_0c0b4b3a;
case 0x0c0b4b3cu: goto P_0c0b4b3c;
case 0x0c0b4b3eu: goto P_0c0b4b3e;
case 0x0c0b4b40u: goto P_0c0b4b40;
case 0x0c0b4b42u: goto P_0c0b4b42;
case 0x0c0b4b44u: goto P_0c0b4b44;
case 0x0c0b4b46u: goto P_0c0b4b46;
case 0x0c0b4b48u: goto P_0c0b4b48;
case 0x0c0b4b4au: goto P_0c0b4b4a;
case 0x0c0b4b4cu: goto P_0c0b4b4c;
case 0x0c0b4b4eu: goto P_0c0b4b4e;
case 0x0c0b4b50u: goto P_0c0b4b50;
case 0x0c0b4b52u: goto P_0c0b4b52;
case 0x0c0b4b54u: goto P_0c0b4b54;
case 0x0c0b4b56u: goto P_0c0b4b56;
case 0x0c0b4b58u: goto P_0c0b4b58;
case 0x0c0b4b5au: goto P_0c0b4b5a;
case 0x0c0b4b5cu: goto P_0c0b4b5c;
case 0x0c0b4b5eu: goto P_0c0b4b5e;
case 0x0c0b4b60u: goto P_0c0b4b60;
case 0x0c0b4b62u: goto P_0c0b4b62;
case 0x0c0b4b64u: goto P_0c0b4b64;
case 0x0c0b4b66u: goto P_0c0b4b66;
case 0x0c0b4b68u: goto P_0c0b4b68;
case 0x0c0b4b6au: goto P_0c0b4b6a;
case 0x0c0b4b6cu: goto P_0c0b4b6c;
case 0x0c0b4b6eu: goto P_0c0b4b6e;
case 0x0c0b4b70u: goto P_0c0b4b70;
case 0x0c0b4b72u: goto P_0c0b4b72;
case 0x0c0b4b74u: goto P_0c0b4b74;
case 0x0c0b4b76u: goto P_0c0b4b76;
case 0x0c0b4b78u: goto P_0c0b4b78;
case 0x0c0b4b7au: goto P_0c0b4b7a;
case 0x0c0b4b7cu: goto P_0c0b4b7c;
case 0x0c0b4b7eu: goto P_0c0b4b7e;
case 0x0c0b4b80u: goto P_0c0b4b80;
case 0x0c0b4b82u: goto P_0c0b4b82;
case 0x0c0b4b84u: goto P_0c0b4b84;
case 0x0c0b4b86u: goto P_0c0b4b86;
case 0x0c0b4b88u: goto P_0c0b4b88;
case 0x0c0b4b8au: goto P_0c0b4b8a;
case 0x0c0b4b8cu: goto P_0c0b4b8c;
case 0x0c0b4b8eu: goto P_0c0b4b8e;
case 0x0c0b4b90u: goto P_0c0b4b90;
case 0x0c0b4b92u: goto P_0c0b4b92;
case 0x0c0b4b94u: goto P_0c0b4b94;
case 0x0c0b4b96u: goto P_0c0b4b96;
case 0x0c0b4b98u: goto P_0c0b4b98;
case 0x0c0b4b9au: goto P_0c0b4b9a;
case 0x0c0b4b9cu: goto P_0c0b4b9c;
case 0x0c0b4b9eu: goto P_0c0b4b9e;
case 0x0c0b4ba0u: goto P_0c0b4ba0;
case 0x0c0b4ba2u: goto P_0c0b4ba2;
case 0x0c0b4ba4u: goto P_0c0b4ba4;
case 0x0c0b4ba6u: goto P_0c0b4ba6;
case 0x0c0b4ba8u: goto P_0c0b4ba8;
case 0x0c0b4baau: goto P_0c0b4baa;
case 0x0c0b4bacu: goto P_0c0b4bac;
case 0x0c0b4baeu: goto P_0c0b4bae;
case 0x0c0b4bb0u: goto P_0c0b4bb0;
case 0x0c0b4bb2u: goto P_0c0b4bb2;
case 0x0c0b4bb4u: goto P_0c0b4bb4;
case 0x0c0b4bb6u: goto P_0c0b4bb6;
case 0x0c0b4bb8u: goto P_0c0b4bb8;
case 0x0c0b4bbau: goto P_0c0b4bba;
case 0x0c0b4bbcu: goto P_0c0b4bbc;
case 0x0c0b4bbeu: goto P_0c0b4bbe;
case 0x0c0b4bc0u: goto P_0c0b4bc0;
case 0x0c0b4bc2u: goto P_0c0b4bc2;
case 0x0c0b4bc4u: goto P_0c0b4bc4;
case 0x0c0b4bc6u: goto P_0c0b4bc6;
case 0x0c0b4bc8u: goto P_0c0b4bc8;
case 0x0c0b4bcau: goto P_0c0b4bca;
case 0x0c0b4bccu: goto P_0c0b4bcc;
case 0x0c0b4bceu: goto P_0c0b4bce;
case 0x0c0b4bd0u: goto P_0c0b4bd0;
case 0x0c0b4bd2u: goto P_0c0b4bd2;
case 0x0c0b4bd4u: goto P_0c0b4bd4;
case 0x0c0b4bd6u: goto P_0c0b4bd6;
case 0x0c0b4bd8u: goto P_0c0b4bd8;
case 0x0c0b4bdau: goto P_0c0b4bda;
case 0x0c0b4bdcu: goto P_0c0b4bdc;
case 0x0c0b4bdeu: goto P_0c0b4bde;
case 0x0c0b4be0u: goto P_0c0b4be0;
case 0x0c0b4be2u: goto P_0c0b4be2;
case 0x0c0b4be4u: goto P_0c0b4be4;
case 0x0c0b4be6u: goto P_0c0b4be6;
case 0x0c0b4be8u: goto P_0c0b4be8;
case 0x0c0b4beau: goto P_0c0b4bea;
case 0x0c0b4becu: goto P_0c0b4bec;
case 0x0c0b4beeu: goto P_0c0b4bee;
case 0x0c0b4bf0u: goto P_0c0b4bf0;
case 0x0c0b4bf2u: goto P_0c0b4bf2;
case 0x0c0b4bf4u: goto P_0c0b4bf4;
case 0x0c0b4bf6u: goto P_0c0b4bf6;
case 0x0c0b4bf8u: goto P_0c0b4bf8;
case 0x0c0b4bfau: goto P_0c0b4bfa;
case 0x0c0b4bfcu: goto P_0c0b4bfc;
case 0x0c0b4bfeu: goto P_0c0b4bfe;
case 0x0c0b4c00u: goto P_0c0b4c00;
case 0x0c0b4c02u: goto P_0c0b4c02;
case 0x0c0b4c04u: goto P_0c0b4c04;
case 0x0c0b4c06u: goto P_0c0b4c06;
case 0x0c0b4c08u: goto P_0c0b4c08;
case 0x0c0b4c0au: goto P_0c0b4c0a;
case 0x0c0b4c0cu: goto P_0c0b4c0c;
case 0x0c0b4c0eu: goto P_0c0b4c0e;
case 0x0c0b4c10u: goto P_0c0b4c10;
case 0x0c0b4c12u: goto P_0c0b4c12;
case 0x0c0b4c14u: goto P_0c0b4c14;
case 0x0c0b4c16u: goto P_0c0b4c16;
case 0x0c0b4c18u: goto P_0c0b4c18;
case 0x0c0b4c1au: goto P_0c0b4c1a;
case 0x0c0b4c1cu: goto P_0c0b4c1c;
case 0x0c0b4c1eu: goto P_0c0b4c1e;
case 0x0c0b4c20u: goto P_0c0b4c20;
case 0x0c0b4c22u: goto P_0c0b4c22;
case 0x0c0b4c24u: goto P_0c0b4c24;
case 0x0c0b4c26u: goto P_0c0b4c26;
case 0x0c0b4c28u: goto P_0c0b4c28;
case 0x0c0b4c2au: goto P_0c0b4c2a;
case 0x0c0b4c2cu: goto P_0c0b4c2c;
case 0x0c0b4c2eu: goto P_0c0b4c2e;
case 0x0c0b4c30u: goto P_0c0b4c30;
case 0x0c0b4c32u: goto P_0c0b4c32;
case 0x0c0b4c34u: goto P_0c0b4c34;
case 0x0c0b4c36u: goto P_0c0b4c36;
case 0x0c0b4c38u: goto P_0c0b4c38;
case 0x0c0b4c3au: goto P_0c0b4c3a;
case 0x0c0b4c3cu: goto P_0c0b4c3c;
case 0x0c0b4c3eu: goto P_0c0b4c3e;
case 0x0c0b4c40u: goto P_0c0b4c40;
case 0x0c0b4c42u: goto P_0c0b4c42;
case 0x0c0b4c44u: goto P_0c0b4c44;
case 0x0c0b4c46u: goto P_0c0b4c46;
case 0x0c0b4c48u: goto P_0c0b4c48;
case 0x0c0b4c4au: goto P_0c0b4c4a;
case 0x0c0b4c4cu: goto P_0c0b4c4c;
case 0x0c0b4c4eu: goto P_0c0b4c4e;
case 0x0c0b4c50u: goto P_0c0b4c50;
case 0x0c0b4c52u: goto P_0c0b4c52;
case 0x0c0b4c54u: goto P_0c0b4c54;
case 0x0c0b4c56u: goto P_0c0b4c56;
case 0x0c0b4c58u: goto P_0c0b4c58;
case 0x0c0b4c5au: goto P_0c0b4c5a;
case 0x0c0b4c5cu: goto P_0c0b4c5c;
case 0x0c0b4c5eu: goto P_0c0b4c5e;
case 0x0c0b4c60u: goto P_0c0b4c60;
case 0x0c0b4c62u: goto P_0c0b4c62;
case 0x0c0b4c64u: goto P_0c0b4c64;
case 0x0c0b4c66u: goto P_0c0b4c66;
case 0x0c0b4c68u: goto P_0c0b4c68;
case 0x0c0b4c6au: goto P_0c0b4c6a;
case 0x0c0b4c6cu: goto P_0c0b4c6c;
case 0x0c0b4c6eu: goto P_0c0b4c6e;
case 0x0c0b4c70u: goto P_0c0b4c70;
case 0x0c0b4c72u: goto P_0c0b4c72;
case 0x0c0b4c74u: goto P_0c0b4c74;
case 0x0c0b4c76u: goto P_0c0b4c76;
case 0x0c0b4c78u: goto P_0c0b4c78;
case 0x0c0b4c7au: goto P_0c0b4c7a;
case 0x0c0b4c7cu: goto P_0c0b4c7c;
case 0x0c0b4c7eu: goto P_0c0b4c7e;
case 0x0c0b4c80u: goto P_0c0b4c80;
case 0x0c0b4c82u: goto P_0c0b4c82;
case 0x0c0b4c84u: goto P_0c0b4c84;
case 0x0c0b4c86u: goto P_0c0b4c86;
case 0x0c0b4c88u: goto P_0c0b4c88;
case 0x0c0b4d02u: goto P_0c0b4d02;
case 0x0c0b4d04u: goto P_0c0b4d04;
case 0x0c0b4d06u: goto P_0c0b4d06;
case 0x0c0b4d08u: goto P_0c0b4d08;
case 0x0c0b4d0au: goto P_0c0b4d0a;
case 0x0c0b4d0cu: goto P_0c0b4d0c;
case 0x0c0b4d0eu: goto P_0c0b4d0e;
case 0x0c0b4d10u: goto P_0c0b4d10;
case 0x0c0b4d12u: goto P_0c0b4d12;
case 0x0c0b4d14u: goto P_0c0b4d14;
case 0x0c0b4d16u: goto P_0c0b4d16;
case 0x0c0b4d18u: goto P_0c0b4d18;
case 0x0c0b4d1au: goto P_0c0b4d1a;
case 0x0c0b4d1cu: goto P_0c0b4d1c;
case 0x0c0b4d1eu: goto P_0c0b4d1e;
case 0x0c0b4d20u: goto P_0c0b4d20;
case 0x0c0b4d22u: goto P_0c0b4d22;
case 0x0c0b4d24u: goto P_0c0b4d24;
case 0x0c0b4d26u: goto P_0c0b4d26;
case 0x0c0b4d28u: goto P_0c0b4d28;
case 0x0c0b4d2au: goto P_0c0b4d2a;
case 0x0c0b4d2cu: goto P_0c0b4d2c;
case 0x0c0b4d2eu: goto P_0c0b4d2e;
case 0x0c0b4d30u: goto P_0c0b4d30;
case 0x0c0b4d32u: goto P_0c0b4d32;
case 0x0c0b4d34u: goto P_0c0b4d34;
case 0x0c0b4d36u: goto P_0c0b4d36;
case 0x0c0b4d38u: goto P_0c0b4d38;
case 0x0c0b4d3au: goto P_0c0b4d3a;
case 0x0c0b4d3cu: goto P_0c0b4d3c;
case 0x0c0b4d3eu: goto P_0c0b4d3e;
case 0x0c0b4d40u: goto P_0c0b4d40;
case 0x0c0b4d42u: goto P_0c0b4d42;
case 0x0c0b4d44u: goto P_0c0b4d44;
case 0x0c0b4d46u: goto P_0c0b4d46;
case 0x0c0b4d48u: goto P_0c0b4d48;
case 0x0c0b4d4au: goto P_0c0b4d4a;
case 0x0c0b4d4cu: goto P_0c0b4d4c;
case 0x0c0b4d4eu: goto P_0c0b4d4e;
case 0x0c0b4d50u: goto P_0c0b4d50;
case 0x0c0b4d52u: goto P_0c0b4d52;
case 0x0c0b4d54u: goto P_0c0b4d54;
case 0x0c0b4d56u: goto P_0c0b4d56;
case 0x0c0b4d58u: goto P_0c0b4d58;
case 0x0c0b4d5au: goto P_0c0b4d5a;
case 0x0c0b4d5cu: goto P_0c0b4d5c;
case 0x0c0b4d5eu: goto P_0c0b4d5e;
case 0x0c0b4d60u: goto P_0c0b4d60;
case 0x0c0b4d62u: goto P_0c0b4d62;
case 0x0c0b4d64u: goto P_0c0b4d64;
case 0x0c0b4d66u: goto P_0c0b4d66;
case 0x0c0b4d68u: goto P_0c0b4d68;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0b495e: /* original 2fe6, guest PC 0x0c0b495e */
if(!s->budget--) { s->failed_pc=0x0c0b495eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b4960;
P_0c0b4960: /* original 2fd6, guest PC 0x0c0b4960 */
if(!s->budget--) { s->failed_pc=0x0c0b4960u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b4962;
P_0c0b4962: /* original 2fc6, guest PC 0x0c0b4962 */
if(!s->budget--) { s->failed_pc=0x0c0b4962u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b4964;
P_0c0b4964: /* original 2fb6, guest PC 0x0c0b4964 */
if(!s->budget--) { s->failed_pc=0x0c0b4964u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b4966;
P_0c0b4966: /* original 2fa6, guest PC 0x0c0b4966 */
if(!s->budget--) { s->failed_pc=0x0c0b4966u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b4968;
P_0c0b4968: /* original 2f96, guest PC 0x0c0b4968 */
if(!s->budget--) { s->failed_pc=0x0c0b4968u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0b496a;
P_0c0b496a: /* original 4f22, guest PC 0x0c0b496a */
if(!s->budget--) { s->failed_pc=0x0c0b496au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0b496c;
P_0c0b496c: /* original 5d44, guest PC 0x0c0b496c */
if(!s->budget--) { s->failed_pc=0x0c0b496cu; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0b496e;
P_0c0b496e: /* original 94a8, guest PC 0x0c0b496e */
if(!s->budget--) { s->failed_pc=0x0c0b496eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ac2u,2);
goto P_0c0b4970;
P_0c0b4970: /* original de6e, guest PC 0x0c0b4970 */
if(!s->budget--) { s->failed_pc=0x0c0b4970u; return 0; }
r[14]=read(ram,0x0c0b4b2cu,4);
goto P_0c0b4972;
P_0c0b4972: /* original 7ff8, guest PC 0x0c0b4972 */
if(!s->budget--) { s->failed_pc=0x0c0b4972u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0b4974;
P_0c0b4974: /* original 4e0b, guest PC 0x0c0b4974 */
if(!s->budget--) { s->failed_pc=0x0c0b4974u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4978u;
tmp=read(ram,r[13],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4978u) { target=s->pc; goto dispatch; }
goto P_0c0b4978;
P_0c0b4976: /* original 65d2, guest PC 0x0c0b4976 */
if(!s->budget--) { s->failed_pc=0x0c0b4976u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0b4978;
P_0c0b4978: /* original 94a4, guest PC 0x0c0b4978 */
if(!s->budget--) { s->failed_pc=0x0c0b4978u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ac4u,2);
goto P_0c0b497a;
P_0c0b497a: /* original 4e0b, guest PC 0x0c0b497a */
if(!s->budget--) { s->failed_pc=0x0c0b497au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b497eu;
r[5]=read(ram,r[13]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b497eu) { target=s->pc; goto dispatch; }
goto P_0c0b497e;
P_0c0b497c: /* original 55d1, guest PC 0x0c0b497c */
if(!s->budget--) { s->failed_pc=0x0c0b497cu; return 0; }
r[5]=read(ram,r[13]+4,4);
goto P_0c0b497e;
P_0c0b497e: /* original 94a2, guest PC 0x0c0b497e */
if(!s->budget--) { s->failed_pc=0x0c0b497eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ac6u,2);
goto P_0c0b4980;
P_0c0b4980: /* original 4e0b, guest PC 0x0c0b4980 */
if(!s->budget--) { s->failed_pc=0x0c0b4980u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4984u;
r[5]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4984u) { target=s->pc; goto dispatch; }
goto P_0c0b4984;
P_0c0b4982: /* original 55d2, guest PC 0x0c0b4982 */
if(!s->budget--) { s->failed_pc=0x0c0b4982u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0b4984;
P_0c0b4984: /* original 94a0, guest PC 0x0c0b4984 */
if(!s->budget--) { s->failed_pc=0x0c0b4984u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ac8u,2);
goto P_0c0b4986;
P_0c0b4986: /* original 4e0b, guest PC 0x0c0b4986 */
if(!s->budget--) { s->failed_pc=0x0c0b4986u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b498au;
r[5]=read(ram,r[13]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b498au) { target=s->pc; goto dispatch; }
goto P_0c0b498a;
P_0c0b4988: /* original 55d3, guest PC 0x0c0b4988 */
if(!s->budget--) { s->failed_pc=0x0c0b4988u; return 0; }
r[5]=read(ram,r[13]+12,4);
goto P_0c0b498a;
P_0c0b498a: /* original 949e, guest PC 0x0c0b498a */
if(!s->budget--) { s->failed_pc=0x0c0b498au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4acau,2);
goto P_0c0b498c;
P_0c0b498c: /* original 4e0b, guest PC 0x0c0b498c */
if(!s->budget--) { s->failed_pc=0x0c0b498cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4990u;
r[5]=read(ram,r[13]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4990u) { target=s->pc; goto dispatch; }
goto P_0c0b4990;
P_0c0b498e: /* original 55d4, guest PC 0x0c0b498e */
if(!s->budget--) { s->failed_pc=0x0c0b498eu; return 0; }
r[5]=read(ram,r[13]+16,4);
goto P_0c0b4990;
P_0c0b4990: /* original 949c, guest PC 0x0c0b4990 */
if(!s->budget--) { s->failed_pc=0x0c0b4990u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4accu,2);
goto P_0c0b4992;
P_0c0b4992: /* original 4e0b, guest PC 0x0c0b4992 */
if(!s->budget--) { s->failed_pc=0x0c0b4992u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4996u;
r[5]=read(ram,r[13]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4996u) { target=s->pc; goto dispatch; }
goto P_0c0b4996;
P_0c0b4994: /* original 55d5, guest PC 0x0c0b4994 */
if(!s->budget--) { s->failed_pc=0x0c0b4994u; return 0; }
r[5]=read(ram,r[13]+20,4);
goto P_0c0b4996;
P_0c0b4996: /* original 949a, guest PC 0x0c0b4996 */
if(!s->budget--) { s->failed_pc=0x0c0b4996u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4aceu,2);
goto P_0c0b4998;
P_0c0b4998: /* original 4e0b, guest PC 0x0c0b4998 */
if(!s->budget--) { s->failed_pc=0x0c0b4998u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b499cu;
r[5]=read(ram,r[13]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b499cu) { target=s->pc; goto dispatch; }
goto P_0c0b499c;
P_0c0b499a: /* original 55d6, guest PC 0x0c0b499a */
if(!s->budget--) { s->failed_pc=0x0c0b499au; return 0; }
r[5]=read(ram,r[13]+24,4);
goto P_0c0b499c;
P_0c0b499c: /* original 9498, guest PC 0x0c0b499c */
if(!s->budget--) { s->failed_pc=0x0c0b499cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ad0u,2);
goto P_0c0b499e;
P_0c0b499e: /* original 4e0b, guest PC 0x0c0b499e */
if(!s->budget--) { s->failed_pc=0x0c0b499eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49a2u;
r[5]=read(ram,r[13]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49a2u) { target=s->pc; goto dispatch; }
goto P_0c0b49a2;
P_0c0b49a0: /* original 55d7, guest PC 0x0c0b49a0 */
if(!s->budget--) { s->failed_pc=0x0c0b49a0u; return 0; }
r[5]=read(ram,r[13]+28,4);
goto P_0c0b49a2;
P_0c0b49a2: /* original 9496, guest PC 0x0c0b49a2 */
if(!s->budget--) { s->failed_pc=0x0c0b49a2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ad2u,2);
goto P_0c0b49a4;
P_0c0b49a4: /* original 4e0b, guest PC 0x0c0b49a4 */
if(!s->budget--) { s->failed_pc=0x0c0b49a4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49a8u;
r[5]=read(ram,r[13]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49a8u) { target=s->pc; goto dispatch; }
goto P_0c0b49a8;
P_0c0b49a6: /* original 55d8, guest PC 0x0c0b49a6 */
if(!s->budget--) { s->failed_pc=0x0c0b49a6u; return 0; }
r[5]=read(ram,r[13]+32,4);
goto P_0c0b49a8;
P_0c0b49a8: /* original 9494, guest PC 0x0c0b49a8 */
if(!s->budget--) { s->failed_pc=0x0c0b49a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ad4u,2);
goto P_0c0b49aa;
P_0c0b49aa: /* original 4e0b, guest PC 0x0c0b49aa */
if(!s->budget--) { s->failed_pc=0x0c0b49aau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49aeu;
r[5]=read(ram,r[13]+36,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49aeu) { target=s->pc; goto dispatch; }
goto P_0c0b49ae;
P_0c0b49ac: /* original 55d9, guest PC 0x0c0b49ac */
if(!s->budget--) { s->failed_pc=0x0c0b49acu; return 0; }
r[5]=read(ram,r[13]+36,4);
goto P_0c0b49ae;
P_0c0b49ae: /* original 9492, guest PC 0x0c0b49ae */
if(!s->budget--) { s->failed_pc=0x0c0b49aeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ad6u,2);
goto P_0c0b49b0;
P_0c0b49b0: /* original 4e0b, guest PC 0x0c0b49b0 */
if(!s->budget--) { s->failed_pc=0x0c0b49b0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49b4u;
r[5]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49b4u) { target=s->pc; goto dispatch; }
goto P_0c0b49b4;
P_0c0b49b2: /* original 55da, guest PC 0x0c0b49b2 */
if(!s->budget--) { s->failed_pc=0x0c0b49b2u; return 0; }
r[5]=read(ram,r[13]+40,4);
goto P_0c0b49b4;
P_0c0b49b4: /* original 9490, guest PC 0x0c0b49b4 */
if(!s->budget--) { s->failed_pc=0x0c0b49b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ad8u,2);
goto P_0c0b49b6;
P_0c0b49b6: /* original 4e0b, guest PC 0x0c0b49b6 */
if(!s->budget--) { s->failed_pc=0x0c0b49b6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49bau;
r[5]=read(ram,r[13]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49bau) { target=s->pc; goto dispatch; }
goto P_0c0b49ba;
P_0c0b49b8: /* original 55db, guest PC 0x0c0b49b8 */
if(!s->budget--) { s->failed_pc=0x0c0b49b8u; return 0; }
r[5]=read(ram,r[13]+44,4);
goto P_0c0b49ba;
P_0c0b49ba: /* original 948e, guest PC 0x0c0b49ba */
if(!s->budget--) { s->failed_pc=0x0c0b49bau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4adau,2);
goto P_0c0b49bc;
P_0c0b49bc: /* original 4e0b, guest PC 0x0c0b49bc */
if(!s->budget--) { s->failed_pc=0x0c0b49bcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49c0u;
r[5]=read(ram,r[13]+48,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49c0u) { target=s->pc; goto dispatch; }
goto P_0c0b49c0;
P_0c0b49be: /* original 55dc, guest PC 0x0c0b49be */
if(!s->budget--) { s->failed_pc=0x0c0b49beu; return 0; }
r[5]=read(ram,r[13]+48,4);
goto P_0c0b49c0;
P_0c0b49c0: /* original 948c, guest PC 0x0c0b49c0 */
if(!s->budget--) { s->failed_pc=0x0c0b49c0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4adcu,2);
goto P_0c0b49c2;
P_0c0b49c2: /* original 4e0b, guest PC 0x0c0b49c2 */
if(!s->budget--) { s->failed_pc=0x0c0b49c2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49c6u;
r[5]=read(ram,r[13]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49c6u) { target=s->pc; goto dispatch; }
goto P_0c0b49c6;
P_0c0b49c4: /* original 55dd, guest PC 0x0c0b49c4 */
if(!s->budget--) { s->failed_pc=0x0c0b49c4u; return 0; }
r[5]=read(ram,r[13]+52,4);
goto P_0c0b49c6;
P_0c0b49c6: /* original 948a, guest PC 0x0c0b49c6 */
if(!s->budget--) { s->failed_pc=0x0c0b49c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4adeu,2);
goto P_0c0b49c8;
P_0c0b49c8: /* original 4e0b, guest PC 0x0c0b49c8 */
if(!s->budget--) { s->failed_pc=0x0c0b49c8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49ccu;
r[5]=read(ram,r[13]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49ccu) { target=s->pc; goto dispatch; }
goto P_0c0b49cc;
P_0c0b49ca: /* original 55de, guest PC 0x0c0b49ca */
if(!s->budget--) { s->failed_pc=0x0c0b49cau; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c0b49cc;
P_0c0b49cc: /* original 9488, guest PC 0x0c0b49cc */
if(!s->budget--) { s->failed_pc=0x0c0b49ccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ae0u,2);
goto P_0c0b49ce;
P_0c0b49ce: /* original 4e0b, guest PC 0x0c0b49ce */
if(!s->budget--) { s->failed_pc=0x0c0b49ceu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49d2u;
r[5]=read(ram,r[13]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49d2u) { target=s->pc; goto dispatch; }
goto P_0c0b49d2;
P_0c0b49d0: /* original 55df, guest PC 0x0c0b49d0 */
if(!s->budget--) { s->failed_pc=0x0c0b49d0u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c0b49d2;
P_0c0b49d2: /* original 9486, guest PC 0x0c0b49d2 */
if(!s->budget--) { s->failed_pc=0x0c0b49d2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ae2u,2);
goto P_0c0b49d4;
P_0c0b49d4: /* original e040, guest PC 0x0c0b49d4 */
if(!s->budget--) { s->failed_pc=0x0c0b49d4u; return 0; }
r[0]=0x00000040u;
goto P_0c0b49d6;
P_0c0b49d6: /* original 4e0b, guest PC 0x0c0b49d6 */
if(!s->budget--) { s->failed_pc=0x0c0b49d6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49dau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49dau) { target=s->pc; goto dispatch; }
goto P_0c0b49da;
P_0c0b49d8: /* original 05de, guest PC 0x0c0b49d8 */
if(!s->budget--) { s->failed_pc=0x0c0b49d8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b49da;
P_0c0b49da: /* original 9483, guest PC 0x0c0b49da */
if(!s->budget--) { s->failed_pc=0x0c0b49dau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ae4u,2);
goto P_0c0b49dc;
P_0c0b49dc: /* original e044, guest PC 0x0c0b49dc */
if(!s->budget--) { s->failed_pc=0x0c0b49dcu; return 0; }
r[0]=0x00000044u;
goto P_0c0b49de;
P_0c0b49de: /* original 4e0b, guest PC 0x0c0b49de */
if(!s->budget--) { s->failed_pc=0x0c0b49deu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49e2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49e2u) { target=s->pc; goto dispatch; }
goto P_0c0b49e2;
P_0c0b49e0: /* original 05de, guest PC 0x0c0b49e0 */
if(!s->budget--) { s->failed_pc=0x0c0b49e0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b49e2;
P_0c0b49e2: /* original 9480, guest PC 0x0c0b49e2 */
if(!s->budget--) { s->failed_pc=0x0c0b49e2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ae6u,2);
goto P_0c0b49e4;
P_0c0b49e4: /* original e048, guest PC 0x0c0b49e4 */
if(!s->budget--) { s->failed_pc=0x0c0b49e4u; return 0; }
r[0]=0x00000048u;
goto P_0c0b49e6;
P_0c0b49e6: /* original 4e0b, guest PC 0x0c0b49e6 */
if(!s->budget--) { s->failed_pc=0x0c0b49e6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49eau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49eau) { target=s->pc; goto dispatch; }
goto P_0c0b49ea;
P_0c0b49e8: /* original 05de, guest PC 0x0c0b49e8 */
if(!s->budget--) { s->failed_pc=0x0c0b49e8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b49ea;
P_0c0b49ea: /* original 947d, guest PC 0x0c0b49ea */
if(!s->budget--) { s->failed_pc=0x0c0b49eau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ae8u,2);
goto P_0c0b49ec;
P_0c0b49ec: /* original e04c, guest PC 0x0c0b49ec */
if(!s->budget--) { s->failed_pc=0x0c0b49ecu; return 0; }
r[0]=0x0000004cu;
goto P_0c0b49ee;
P_0c0b49ee: /* original 4e0b, guest PC 0x0c0b49ee */
if(!s->budget--) { s->failed_pc=0x0c0b49eeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49f2u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49f2u) { target=s->pc; goto dispatch; }
goto P_0c0b49f2;
P_0c0b49f0: /* original 05de, guest PC 0x0c0b49f0 */
if(!s->budget--) { s->failed_pc=0x0c0b49f0u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b49f2;
P_0c0b49f2: /* original 947a, guest PC 0x0c0b49f2 */
if(!s->budget--) { s->failed_pc=0x0c0b49f2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4aeau,2);
goto P_0c0b49f4;
P_0c0b49f4: /* original e050, guest PC 0x0c0b49f4 */
if(!s->budget--) { s->failed_pc=0x0c0b49f4u; return 0; }
r[0]=0x00000050u;
goto P_0c0b49f6;
P_0c0b49f6: /* original 4e0b, guest PC 0x0c0b49f6 */
if(!s->budget--) { s->failed_pc=0x0c0b49f6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b49fau;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b49fau) { target=s->pc; goto dispatch; }
goto P_0c0b49fa;
P_0c0b49f8: /* original 05de, guest PC 0x0c0b49f8 */
if(!s->budget--) { s->failed_pc=0x0c0b49f8u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b49fa;
P_0c0b49fa: /* original 9477, guest PC 0x0c0b49fa */
if(!s->budget--) { s->failed_pc=0x0c0b49fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4aecu,2);
goto P_0c0b49fc;
P_0c0b49fc: /* original e054, guest PC 0x0c0b49fc */
if(!s->budget--) { s->failed_pc=0x0c0b49fcu; return 0; }
r[0]=0x00000054u;
goto P_0c0b49fe;
P_0c0b49fe: /* original 4e0b, guest PC 0x0c0b49fe */
if(!s->budget--) { s->failed_pc=0x0c0b49feu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a02u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a02u) { target=s->pc; goto dispatch; }
goto P_0c0b4a02;
P_0c0b4a00: /* original 05de, guest PC 0x0c0b4a00 */
if(!s->budget--) { s->failed_pc=0x0c0b4a00u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a02;
P_0c0b4a02: /* original 9474, guest PC 0x0c0b4a02 */
if(!s->budget--) { s->failed_pc=0x0c0b4a02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4aeeu,2);
goto P_0c0b4a04;
P_0c0b4a04: /* original e058, guest PC 0x0c0b4a04 */
if(!s->budget--) { s->failed_pc=0x0c0b4a04u; return 0; }
r[0]=0x00000058u;
goto P_0c0b4a06;
P_0c0b4a06: /* original 4e0b, guest PC 0x0c0b4a06 */
if(!s->budget--) { s->failed_pc=0x0c0b4a06u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a0au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a0au) { target=s->pc; goto dispatch; }
goto P_0c0b4a0a;
P_0c0b4a08: /* original 05de, guest PC 0x0c0b4a08 */
if(!s->budget--) { s->failed_pc=0x0c0b4a08u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a0a;
P_0c0b4a0a: /* original 9471, guest PC 0x0c0b4a0a */
if(!s->budget--) { s->failed_pc=0x0c0b4a0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4af0u,2);
goto P_0c0b4a0c;
P_0c0b4a0c: /* original e05c, guest PC 0x0c0b4a0c */
if(!s->budget--) { s->failed_pc=0x0c0b4a0cu; return 0; }
r[0]=0x0000005cu;
goto P_0c0b4a0e;
P_0c0b4a0e: /* original 4e0b, guest PC 0x0c0b4a0e */
if(!s->budget--) { s->failed_pc=0x0c0b4a0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a12u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a12u) { target=s->pc; goto dispatch; }
goto P_0c0b4a12;
P_0c0b4a10: /* original 05de, guest PC 0x0c0b4a10 */
if(!s->budget--) { s->failed_pc=0x0c0b4a10u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a12;
P_0c0b4a12: /* original 946e, guest PC 0x0c0b4a12 */
if(!s->budget--) { s->failed_pc=0x0c0b4a12u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4af2u,2);
goto P_0c0b4a14;
P_0c0b4a14: /* original e060, guest PC 0x0c0b4a14 */
if(!s->budget--) { s->failed_pc=0x0c0b4a14u; return 0; }
r[0]=0x00000060u;
goto P_0c0b4a16;
P_0c0b4a16: /* original 4e0b, guest PC 0x0c0b4a16 */
if(!s->budget--) { s->failed_pc=0x0c0b4a16u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a1au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a1au) { target=s->pc; goto dispatch; }
goto P_0c0b4a1a;
P_0c0b4a18: /* original 05de, guest PC 0x0c0b4a18 */
if(!s->budget--) { s->failed_pc=0x0c0b4a18u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a1a;
P_0c0b4a1a: /* original 946b, guest PC 0x0c0b4a1a */
if(!s->budget--) { s->failed_pc=0x0c0b4a1au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4af4u,2);
goto P_0c0b4a1c;
P_0c0b4a1c: /* original e064, guest PC 0x0c0b4a1c */
if(!s->budget--) { s->failed_pc=0x0c0b4a1cu; return 0; }
r[0]=0x00000064u;
goto P_0c0b4a1e;
P_0c0b4a1e: /* original 4e0b, guest PC 0x0c0b4a1e */
if(!s->budget--) { s->failed_pc=0x0c0b4a1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a22u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a22u) { target=s->pc; goto dispatch; }
goto P_0c0b4a22;
P_0c0b4a20: /* original 05de, guest PC 0x0c0b4a20 */
if(!s->budget--) { s->failed_pc=0x0c0b4a20u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a22;
P_0c0b4a22: /* original 9468, guest PC 0x0c0b4a22 */
if(!s->budget--) { s->failed_pc=0x0c0b4a22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4af6u,2);
goto P_0c0b4a24;
P_0c0b4a24: /* original e068, guest PC 0x0c0b4a24 */
if(!s->budget--) { s->failed_pc=0x0c0b4a24u; return 0; }
r[0]=0x00000068u;
goto P_0c0b4a26;
P_0c0b4a26: /* original 4e0b, guest PC 0x0c0b4a26 */
if(!s->budget--) { s->failed_pc=0x0c0b4a26u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a2au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a2au) { target=s->pc; goto dispatch; }
goto P_0c0b4a2a;
P_0c0b4a28: /* original 05de, guest PC 0x0c0b4a28 */
if(!s->budget--) { s->failed_pc=0x0c0b4a28u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a2a;
P_0c0b4a2a: /* original 9465, guest PC 0x0c0b4a2a */
if(!s->budget--) { s->failed_pc=0x0c0b4a2au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4af8u,2);
goto P_0c0b4a2c;
P_0c0b4a2c: /* original e06c, guest PC 0x0c0b4a2c */
if(!s->budget--) { s->failed_pc=0x0c0b4a2cu; return 0; }
r[0]=0x0000006cu;
goto P_0c0b4a2e;
P_0c0b4a2e: /* original 4e0b, guest PC 0x0c0b4a2e */
if(!s->budget--) { s->failed_pc=0x0c0b4a2eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a32u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a32u) { target=s->pc; goto dispatch; }
goto P_0c0b4a32;
P_0c0b4a30: /* original 05de, guest PC 0x0c0b4a30 */
if(!s->budget--) { s->failed_pc=0x0c0b4a30u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a32;
P_0c0b4a32: /* original 9462, guest PC 0x0c0b4a32 */
if(!s->budget--) { s->failed_pc=0x0c0b4a32u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4afau,2);
goto P_0c0b4a34;
P_0c0b4a34: /* original e070, guest PC 0x0c0b4a34 */
if(!s->budget--) { s->failed_pc=0x0c0b4a34u; return 0; }
r[0]=0x00000070u;
goto P_0c0b4a36;
P_0c0b4a36: /* original 4e0b, guest PC 0x0c0b4a36 */
if(!s->budget--) { s->failed_pc=0x0c0b4a36u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a3au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a3au) { target=s->pc; goto dispatch; }
goto P_0c0b4a3a;
P_0c0b4a38: /* original 05de, guest PC 0x0c0b4a38 */
if(!s->budget--) { s->failed_pc=0x0c0b4a38u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a3a;
P_0c0b4a3a: /* original 945f, guest PC 0x0c0b4a3a */
if(!s->budget--) { s->failed_pc=0x0c0b4a3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4afcu,2);
goto P_0c0b4a3c;
P_0c0b4a3c: /* original e074, guest PC 0x0c0b4a3c */
if(!s->budget--) { s->failed_pc=0x0c0b4a3cu; return 0; }
r[0]=0x00000074u;
goto P_0c0b4a3e;
P_0c0b4a3e: /* original 4e0b, guest PC 0x0c0b4a3e */
if(!s->budget--) { s->failed_pc=0x0c0b4a3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a42u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a42u) { target=s->pc; goto dispatch; }
goto P_0c0b4a42;
P_0c0b4a40: /* original 05de, guest PC 0x0c0b4a40 */
if(!s->budget--) { s->failed_pc=0x0c0b4a40u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a42;
P_0c0b4a42: /* original 945c, guest PC 0x0c0b4a42 */
if(!s->budget--) { s->failed_pc=0x0c0b4a42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4afeu,2);
goto P_0c0b4a44;
P_0c0b4a44: /* original e078, guest PC 0x0c0b4a44 */
if(!s->budget--) { s->failed_pc=0x0c0b4a44u; return 0; }
r[0]=0x00000078u;
goto P_0c0b4a46;
P_0c0b4a46: /* original 4e0b, guest PC 0x0c0b4a46 */
if(!s->budget--) { s->failed_pc=0x0c0b4a46u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a4au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a4au) { target=s->pc; goto dispatch; }
goto P_0c0b4a4a;
P_0c0b4a48: /* original 05de, guest PC 0x0c0b4a48 */
if(!s->budget--) { s->failed_pc=0x0c0b4a48u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a4a;
P_0c0b4a4a: /* original 9459, guest PC 0x0c0b4a4a */
if(!s->budget--) { s->failed_pc=0x0c0b4a4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b00u,2);
goto P_0c0b4a4c;
P_0c0b4a4c: /* original e07c, guest PC 0x0c0b4a4c */
if(!s->budget--) { s->failed_pc=0x0c0b4a4cu; return 0; }
r[0]=0x0000007cu;
goto P_0c0b4a4e;
P_0c0b4a4e: /* original 4e0b, guest PC 0x0c0b4a4e */
if(!s->budget--) { s->failed_pc=0x0c0b4a4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a52u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a52u) { target=s->pc; goto dispatch; }
goto P_0c0b4a52;
P_0c0b4a50: /* original 05de, guest PC 0x0c0b4a50 */
if(!s->budget--) { s->failed_pc=0x0c0b4a50u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a52;
P_0c0b4a52: /* original 9457, guest PC 0x0c0b4a52 */
if(!s->budget--) { s->failed_pc=0x0c0b4a52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b04u,2);
goto P_0c0b4a54;
P_0c0b4a54: /* original 9055, guest PC 0x0c0b4a54 */
if(!s->budget--) { s->failed_pc=0x0c0b4a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b02u,2);
goto P_0c0b4a56;
P_0c0b4a56: /* original 4e0b, guest PC 0x0c0b4a56 */
if(!s->budget--) { s->failed_pc=0x0c0b4a56u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a5au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a5au) { target=s->pc; goto dispatch; }
goto P_0c0b4a5a;
P_0c0b4a58: /* original 05de, guest PC 0x0c0b4a58 */
if(!s->budget--) { s->failed_pc=0x0c0b4a58u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a5a;
P_0c0b4a5a: /* original 9554, guest PC 0x0c0b4a5a */
if(!s->budget--) { s->failed_pc=0x0c0b4a5au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b06u,2);
goto P_0c0b4a5c;
P_0c0b4a5c: /* original 35dc, guest PC 0x0c0b4a5c */
if(!s->budget--) { s->failed_pc=0x0c0b4a5cu; return 0; }
r[5]+=r[13];
goto P_0c0b4a5e;
P_0c0b4a5e: /* original 2f52, guest PC 0x0c0b4a5e */
if(!s->budget--) { s->failed_pc=0x0c0b4a5eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4a60;
P_0c0b4a60: /* original 9452, guest PC 0x0c0b4a60 */
if(!s->budget--) { s->failed_pc=0x0c0b4a60u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b08u,2);
goto P_0c0b4a62;
P_0c0b4a62: /* original 4e0b, guest PC 0x0c0b4a62 */
if(!s->budget--) { s->failed_pc=0x0c0b4a62u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a66u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a66u) { target=s->pc; goto dispatch; }
goto P_0c0b4a66;
P_0c0b4a64: /* original 6552, guest PC 0x0c0b4a64 */
if(!s->budget--) { s->failed_pc=0x0c0b4a64u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4a66;
P_0c0b4a66: /* original 9550, guest PC 0x0c0b4a66 */
if(!s->budget--) { s->failed_pc=0x0c0b4a66u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b0au,2);
goto P_0c0b4a68;
P_0c0b4a68: /* original 35dc, guest PC 0x0c0b4a68 */
if(!s->budget--) { s->failed_pc=0x0c0b4a68u; return 0; }
r[5]+=r[13];
goto P_0c0b4a6a;
P_0c0b4a6a: /* original 1f51, guest PC 0x0c0b4a6a */
if(!s->budget--) { s->failed_pc=0x0c0b4a6au; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0b4a6c;
P_0c0b4a6c: /* original 944e, guest PC 0x0c0b4a6c */
if(!s->budget--) { s->failed_pc=0x0c0b4a6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b0cu,2);
goto P_0c0b4a6e;
P_0c0b4a6e: /* original 4e0b, guest PC 0x0c0b4a6e */
if(!s->budget--) { s->failed_pc=0x0c0b4a6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a72u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a72u) { target=s->pc; goto dispatch; }
goto P_0c0b4a72;
P_0c0b4a70: /* original 6552, guest PC 0x0c0b4a70 */
if(!s->budget--) { s->failed_pc=0x0c0b4a70u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4a72;
P_0c0b4a72: /* original 944d, guest PC 0x0c0b4a72 */
if(!s->budget--) { s->failed_pc=0x0c0b4a72u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b10u,2);
goto P_0c0b4a74;
P_0c0b4a74: /* original 904b, guest PC 0x0c0b4a74 */
if(!s->budget--) { s->failed_pc=0x0c0b4a74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b0eu,2);
goto P_0c0b4a76;
P_0c0b4a76: /* original 4e0b, guest PC 0x0c0b4a76 */
if(!s->budget--) { s->failed_pc=0x0c0b4a76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a7au;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a7au) { target=s->pc; goto dispatch; }
goto P_0c0b4a7a;
P_0c0b4a78: /* original 05de, guest PC 0x0c0b4a78 */
if(!s->budget--) { s->failed_pc=0x0c0b4a78u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a7a;
P_0c0b4a7a: /* original 944b, guest PC 0x0c0b4a7a */
if(!s->budget--) { s->failed_pc=0x0c0b4a7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b14u,2);
goto P_0c0b4a7c;
P_0c0b4a7c: /* original 9049, guest PC 0x0c0b4a7c */
if(!s->budget--) { s->failed_pc=0x0c0b4a7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b12u,2);
goto P_0c0b4a7e;
P_0c0b4a7e: /* original 4e0b, guest PC 0x0c0b4a7e */
if(!s->budget--) { s->failed_pc=0x0c0b4a7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a82u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a82u) { target=s->pc; goto dispatch; }
goto P_0c0b4a82;
P_0c0b4a80: /* original 05de, guest PC 0x0c0b4a80 */
if(!s->budget--) { s->failed_pc=0x0c0b4a80u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4a82;
P_0c0b4a82: /* original 9948, guest PC 0x0c0b4a82 */
if(!s->budget--) { s->failed_pc=0x0c0b4a82u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b16u,2);
goto P_0c0b4a84;
P_0c0b4a84: /* original 9448, guest PC 0x0c0b4a84 */
if(!s->budget--) { s->failed_pc=0x0c0b4a84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b18u,2);
goto P_0c0b4a86;
P_0c0b4a86: /* original 39dc, guest PC 0x0c0b4a86 */
if(!s->budget--) { s->failed_pc=0x0c0b4a86u; return 0; }
r[9]+=r[13];
goto P_0c0b4a88;
P_0c0b4a88: /* original 4e0b, guest PC 0x0c0b4a88 */
if(!s->budget--) { s->failed_pc=0x0c0b4a88u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a8cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a8cu) { target=s->pc; goto dispatch; }
goto P_0c0b4a8c;
P_0c0b4a8a: /* original 6592, guest PC 0x0c0b4a8a */
if(!s->budget--) { s->failed_pc=0x0c0b4a8au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4a8c;
P_0c0b4a8c: /* original 9445, guest PC 0x0c0b4a8c */
if(!s->budget--) { s->failed_pc=0x0c0b4a8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b1au,2);
goto P_0c0b4a8e;
P_0c0b4a8e: /* original 4e0b, guest PC 0x0c0b4a8e */
if(!s->budget--) { s->failed_pc=0x0c0b4a8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a92u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a92u) { target=s->pc; goto dispatch; }
goto P_0c0b4a92;
P_0c0b4a90: /* original 6592, guest PC 0x0c0b4a90 */
if(!s->budget--) { s->failed_pc=0x0c0b4a90u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4a92;
P_0c0b4a92: /* original 9443, guest PC 0x0c0b4a92 */
if(!s->budget--) { s->failed_pc=0x0c0b4a92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b1cu,2);
goto P_0c0b4a94;
P_0c0b4a94: /* original 4e0b, guest PC 0x0c0b4a94 */
if(!s->budget--) { s->failed_pc=0x0c0b4a94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a98u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a98u) { target=s->pc; goto dispatch; }
goto P_0c0b4a98;
P_0c0b4a96: /* original 6592, guest PC 0x0c0b4a96 */
if(!s->budget--) { s->failed_pc=0x0c0b4a96u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4a98;
P_0c0b4a98: /* original 9441, guest PC 0x0c0b4a98 */
if(!s->budget--) { s->failed_pc=0x0c0b4a98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b1eu,2);
goto P_0c0b4a9a;
P_0c0b4a9a: /* original 4e0b, guest PC 0x0c0b4a9a */
if(!s->budget--) { s->failed_pc=0x0c0b4a9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4a9eu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4a9eu) { target=s->pc; goto dispatch; }
goto P_0c0b4a9e;
P_0c0b4a9c: /* original 6592, guest PC 0x0c0b4a9c */
if(!s->budget--) { s->failed_pc=0x0c0b4a9cu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4a9e;
P_0c0b4a9e: /* original 9c3f, guest PC 0x0c0b4a9e */
if(!s->budget--) { s->failed_pc=0x0c0b4a9eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b20u,2);
goto P_0c0b4aa0;
P_0c0b4aa0: /* original 943f, guest PC 0x0c0b4aa0 */
if(!s->budget--) { s->failed_pc=0x0c0b4aa0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b22u,2);
goto P_0c0b4aa2;
P_0c0b4aa2: /* original 3cdc, guest PC 0x0c0b4aa2 */
if(!s->budget--) { s->failed_pc=0x0c0b4aa2u; return 0; }
r[12]+=r[13];
goto P_0c0b4aa4;
P_0c0b4aa4: /* original 4e0b, guest PC 0x0c0b4aa4 */
if(!s->budget--) { s->failed_pc=0x0c0b4aa4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4aa8u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4aa8u) { target=s->pc; goto dispatch; }
goto P_0c0b4aa8;
P_0c0b4aa6: /* original 65c2, guest PC 0x0c0b4aa6 */
if(!s->budget--) { s->failed_pc=0x0c0b4aa6u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4aa8;
P_0c0b4aa8: /* original 943c, guest PC 0x0c0b4aa8 */
if(!s->budget--) { s->failed_pc=0x0c0b4aa8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b24u,2);
goto P_0c0b4aaa;
P_0c0b4aaa: /* original 4e0b, guest PC 0x0c0b4aaa */
if(!s->budget--) { s->failed_pc=0x0c0b4aaau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4aaeu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4aaeu) { target=s->pc; goto dispatch; }
goto P_0c0b4aae;
P_0c0b4aac: /* original 65c2, guest PC 0x0c0b4aac */
if(!s->budget--) { s->failed_pc=0x0c0b4aacu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4aae;
P_0c0b4aae: /* original 943a, guest PC 0x0c0b4aae */
if(!s->budget--) { s->failed_pc=0x0c0b4aaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b26u,2);
goto P_0c0b4ab0;
P_0c0b4ab0: /* original 4e0b, guest PC 0x0c0b4ab0 */
if(!s->budget--) { s->failed_pc=0x0c0b4ab0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4ab4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4ab4u) { target=s->pc; goto dispatch; }
goto P_0c0b4ab4;
P_0c0b4ab2: /* original 65c2, guest PC 0x0c0b4ab2 */
if(!s->budget--) { s->failed_pc=0x0c0b4ab2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4ab4;
P_0c0b4ab4: /* original 9438, guest PC 0x0c0b4ab4 */
if(!s->budget--) { s->failed_pc=0x0c0b4ab4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b28u,2);
goto P_0c0b4ab6;
P_0c0b4ab6: /* original 4e0b, guest PC 0x0c0b4ab6 */
if(!s->budget--) { s->failed_pc=0x0c0b4ab6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4abau;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4abau) { target=s->pc; goto dispatch; }
goto P_0c0b4aba;
P_0c0b4ab8: /* original 65c2, guest PC 0x0c0b4ab8 */
if(!s->budget--) { s->failed_pc=0x0c0b4ab8u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4aba;
P_0c0b4aba: /* original 9b36, guest PC 0x0c0b4aba */
if(!s->budget--) { s->failed_pc=0x0c0b4abau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4b2au,2);
goto P_0c0b4abc;
P_0c0b4abc: /* original 3bdc, guest PC 0x0c0b4abc */
if(!s->budget--) { s->failed_pc=0x0c0b4abcu; return 0; }
r[11]+=r[13];
goto P_0c0b4abe;
P_0c0b4abe: /* original a037, guest PC 0x0c0b4abe */
if(!s->budget--) { s->failed_pc=0x0c0b4abeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4b30;
P_0c0b4ac0: /* original 65b2, guest PC 0x0c0b4ac0 */
if(!s->budget--) { s->failed_pc=0x0c0b4ac0u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
if(!vf3_matrix_family(0x0c0b4ac2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b4ac2u; return 0; } return 1;
P_0c0b4b30: /* original 94ab, guest PC 0x0c0b4b30 */
if(!s->budget--) { s->failed_pc=0x0c0b4b30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c8au,2);
goto P_0c0b4b32;
P_0c0b4b32: /* original 4e0b, guest PC 0x0c0b4b32 */
if(!s->budget--) { s->failed_pc=0x0c0b4b32u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b36u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b36u) { target=s->pc; goto dispatch; }
goto P_0c0b4b36;
P_0c0b4b34: /* original 0009, guest PC 0x0c0b4b34 */
if(!s->budget--) { s->failed_pc=0x0c0b4b34u; return 0; }
goto P_0c0b4b36;
P_0c0b4b36: /* original 94a9, guest PC 0x0c0b4b36 */
if(!s->budget--) { s->failed_pc=0x0c0b4b36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c8cu,2);
goto P_0c0b4b38;
P_0c0b4b38: /* original 4e0b, guest PC 0x0c0b4b38 */
if(!s->budget--) { s->failed_pc=0x0c0b4b38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b3cu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b3cu) { target=s->pc; goto dispatch; }
goto P_0c0b4b3c;
P_0c0b4b3a: /* original 65b2, guest PC 0x0c0b4b3a */
if(!s->budget--) { s->failed_pc=0x0c0b4b3au; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4b3c;
P_0c0b4b3c: /* original 94a7, guest PC 0x0c0b4b3c */
if(!s->budget--) { s->failed_pc=0x0c0b4b3cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c8eu,2);
goto P_0c0b4b3e;
P_0c0b4b3e: /* original 4e0b, guest PC 0x0c0b4b3e */
if(!s->budget--) { s->failed_pc=0x0c0b4b3eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b42u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b42u) { target=s->pc; goto dispatch; }
goto P_0c0b4b42;
P_0c0b4b40: /* original 65b2, guest PC 0x0c0b4b40 */
if(!s->budget--) { s->failed_pc=0x0c0b4b40u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4b42;
P_0c0b4b42: /* original 94a5, guest PC 0x0c0b4b42 */
if(!s->budget--) { s->failed_pc=0x0c0b4b42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c90u,2);
goto P_0c0b4b44;
P_0c0b4b44: /* original 4e0b, guest PC 0x0c0b4b44 */
if(!s->budget--) { s->failed_pc=0x0c0b4b44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b48u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b48u) { target=s->pc; goto dispatch; }
goto P_0c0b4b48;
P_0c0b4b46: /* original 65b2, guest PC 0x0c0b4b46 */
if(!s->budget--) { s->failed_pc=0x0c0b4b46u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4b48;
P_0c0b4b48: /* original 9aa3, guest PC 0x0c0b4b48 */
if(!s->budget--) { s->failed_pc=0x0c0b4b48u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c92u,2);
goto P_0c0b4b4a;
P_0c0b4b4a: /* original 94a3, guest PC 0x0c0b4b4a */
if(!s->budget--) { s->failed_pc=0x0c0b4b4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c94u,2);
goto P_0c0b4b4c;
P_0c0b4b4c: /* original 3adc, guest PC 0x0c0b4b4c */
if(!s->budget--) { s->failed_pc=0x0c0b4b4cu; return 0; }
r[10]+=r[13];
goto P_0c0b4b4e;
P_0c0b4b4e: /* original 4e0b, guest PC 0x0c0b4b4e */
if(!s->budget--) { s->failed_pc=0x0c0b4b4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b52u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b52u) { target=s->pc; goto dispatch; }
goto P_0c0b4b52;
P_0c0b4b50: /* original 65a2, guest PC 0x0c0b4b50 */
if(!s->budget--) { s->failed_pc=0x0c0b4b50u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4b52;
P_0c0b4b52: /* original 94a0, guest PC 0x0c0b4b52 */
if(!s->budget--) { s->failed_pc=0x0c0b4b52u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c96u,2);
goto P_0c0b4b54;
P_0c0b4b54: /* original 4e0b, guest PC 0x0c0b4b54 */
if(!s->budget--) { s->failed_pc=0x0c0b4b54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b58u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b58u) { target=s->pc; goto dispatch; }
goto P_0c0b4b58;
P_0c0b4b56: /* original 65a2, guest PC 0x0c0b4b56 */
if(!s->budget--) { s->failed_pc=0x0c0b4b56u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4b58;
P_0c0b4b58: /* original 949e, guest PC 0x0c0b4b58 */
if(!s->budget--) { s->failed_pc=0x0c0b4b58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c98u,2);
goto P_0c0b4b5a;
P_0c0b4b5a: /* original 4e0b, guest PC 0x0c0b4b5a */
if(!s->budget--) { s->failed_pc=0x0c0b4b5au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b5eu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b5eu) { target=s->pc; goto dispatch; }
goto P_0c0b4b5e;
P_0c0b4b5c: /* original 65a2, guest PC 0x0c0b4b5c */
if(!s->budget--) { s->failed_pc=0x0c0b4b5cu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4b5e;
P_0c0b4b5e: /* original 949c, guest PC 0x0c0b4b5e */
if(!s->budget--) { s->failed_pc=0x0c0b4b5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c9au,2);
goto P_0c0b4b60;
P_0c0b4b60: /* original 4e0b, guest PC 0x0c0b4b60 */
if(!s->budget--) { s->failed_pc=0x0c0b4b60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b64u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b64u) { target=s->pc; goto dispatch; }
goto P_0c0b4b64;
P_0c0b4b62: /* original 65a2, guest PC 0x0c0b4b62 */
if(!s->budget--) { s->failed_pc=0x0c0b4b62u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4b64;
P_0c0b4b64: /* original 949a, guest PC 0x0c0b4b64 */
if(!s->budget--) { s->failed_pc=0x0c0b4b64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c9cu,2);
goto P_0c0b4b66;
P_0c0b4b66: /* original 65f2, guest PC 0x0c0b4b66 */
if(!s->budget--) { s->failed_pc=0x0c0b4b66u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4b68;
P_0c0b4b68: /* original 4e0b, guest PC 0x0c0b4b68 */
if(!s->budget--) { s->failed_pc=0x0c0b4b68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b6cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b6cu) { target=s->pc; goto dispatch; }
goto P_0c0b4b6c;
P_0c0b4b6a: /* original 6552, guest PC 0x0c0b4b6a */
if(!s->budget--) { s->failed_pc=0x0c0b4b6au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4b6c;
P_0c0b4b6c: /* original 9497, guest PC 0x0c0b4b6c */
if(!s->budget--) { s->failed_pc=0x0c0b4b6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4c9eu,2);
goto P_0c0b4b6e;
P_0c0b4b6e: /* original 55f1, guest PC 0x0c0b4b6e */
if(!s->budget--) { s->failed_pc=0x0c0b4b6eu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c0b4b70;
P_0c0b4b70: /* original 4e0b, guest PC 0x0c0b4b70 */
if(!s->budget--) { s->failed_pc=0x0c0b4b70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b74u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b74u) { target=s->pc; goto dispatch; }
goto P_0c0b4b74;
P_0c0b4b72: /* original 6552, guest PC 0x0c0b4b72 */
if(!s->budget--) { s->failed_pc=0x0c0b4b72u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4b74;
P_0c0b4b74: /* original 9494, guest PC 0x0c0b4b74 */
if(!s->budget--) { s->failed_pc=0x0c0b4b74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ca0u,2);
goto P_0c0b4b76;
P_0c0b4b76: /* original 4e0b, guest PC 0x0c0b4b76 */
if(!s->budget--) { s->failed_pc=0x0c0b4b76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b7au;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b7au) { target=s->pc; goto dispatch; }
goto P_0c0b4b7a;
P_0c0b4b78: /* original 6592, guest PC 0x0c0b4b78 */
if(!s->budget--) { s->failed_pc=0x0c0b4b78u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4b7a;
P_0c0b4b7a: /* original 9492, guest PC 0x0c0b4b7a */
if(!s->budget--) { s->failed_pc=0x0c0b4b7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ca2u,2);
goto P_0c0b4b7c;
P_0c0b4b7c: /* original 4e0b, guest PC 0x0c0b4b7c */
if(!s->budget--) { s->failed_pc=0x0c0b4b7cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b80u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b80u) { target=s->pc; goto dispatch; }
goto P_0c0b4b80;
P_0c0b4b7e: /* original 6592, guest PC 0x0c0b4b7e */
if(!s->budget--) { s->failed_pc=0x0c0b4b7eu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4b80;
P_0c0b4b80: /* original 9490, guest PC 0x0c0b4b80 */
if(!s->budget--) { s->failed_pc=0x0c0b4b80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ca4u,2);
goto P_0c0b4b82;
P_0c0b4b82: /* original 4e0b, guest PC 0x0c0b4b82 */
if(!s->budget--) { s->failed_pc=0x0c0b4b82u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b86u;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b86u) { target=s->pc; goto dispatch; }
goto P_0c0b4b86;
P_0c0b4b84: /* original 6592, guest PC 0x0c0b4b84 */
if(!s->budget--) { s->failed_pc=0x0c0b4b84u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4b86;
P_0c0b4b86: /* original 948e, guest PC 0x0c0b4b86 */
if(!s->budget--) { s->failed_pc=0x0c0b4b86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ca6u,2);
goto P_0c0b4b88;
P_0c0b4b88: /* original 4e0b, guest PC 0x0c0b4b88 */
if(!s->budget--) { s->failed_pc=0x0c0b4b88u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b8cu;
tmp=read(ram,r[9],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b8cu) { target=s->pc; goto dispatch; }
goto P_0c0b4b8c;
P_0c0b4b8a: /* original 6592, guest PC 0x0c0b4b8a */
if(!s->budget--) { s->failed_pc=0x0c0b4b8au; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0b4b8c;
P_0c0b4b8c: /* original 948c, guest PC 0x0c0b4b8c */
if(!s->budget--) { s->failed_pc=0x0c0b4b8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ca8u,2);
goto P_0c0b4b8e;
P_0c0b4b8e: /* original 4e0b, guest PC 0x0c0b4b8e */
if(!s->budget--) { s->failed_pc=0x0c0b4b8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b92u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b92u) { target=s->pc; goto dispatch; }
goto P_0c0b4b92;
P_0c0b4b90: /* original 65c2, guest PC 0x0c0b4b90 */
if(!s->budget--) { s->failed_pc=0x0c0b4b90u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4b92;
P_0c0b4b92: /* original 948a, guest PC 0x0c0b4b92 */
if(!s->budget--) { s->failed_pc=0x0c0b4b92u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4caau,2);
goto P_0c0b4b94;
P_0c0b4b94: /* original 4e0b, guest PC 0x0c0b4b94 */
if(!s->budget--) { s->failed_pc=0x0c0b4b94u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b98u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b98u) { target=s->pc; goto dispatch; }
goto P_0c0b4b98;
P_0c0b4b96: /* original 65c2, guest PC 0x0c0b4b96 */
if(!s->budget--) { s->failed_pc=0x0c0b4b96u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4b98;
P_0c0b4b98: /* original 9488, guest PC 0x0c0b4b98 */
if(!s->budget--) { s->failed_pc=0x0c0b4b98u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cacu,2);
goto P_0c0b4b9a;
P_0c0b4b9a: /* original 4e0b, guest PC 0x0c0b4b9a */
if(!s->budget--) { s->failed_pc=0x0c0b4b9au; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4b9eu;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4b9eu) { target=s->pc; goto dispatch; }
goto P_0c0b4b9e;
P_0c0b4b9c: /* original 65c2, guest PC 0x0c0b4b9c */
if(!s->budget--) { s->failed_pc=0x0c0b4b9cu; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4b9e;
P_0c0b4b9e: /* original 9486, guest PC 0x0c0b4b9e */
if(!s->budget--) { s->failed_pc=0x0c0b4b9eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4caeu,2);
goto P_0c0b4ba0;
P_0c0b4ba0: /* original 4e0b, guest PC 0x0c0b4ba0 */
if(!s->budget--) { s->failed_pc=0x0c0b4ba0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4ba4u;
tmp=read(ram,r[12],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4ba4u) { target=s->pc; goto dispatch; }
goto P_0c0b4ba4;
P_0c0b4ba2: /* original 65c2, guest PC 0x0c0b4ba2 */
if(!s->budget--) { s->failed_pc=0x0c0b4ba2u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0b4ba4;
P_0c0b4ba4: /* original 9484, guest PC 0x0c0b4ba4 */
if(!s->budget--) { s->failed_pc=0x0c0b4ba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cb0u,2);
goto P_0c0b4ba6;
P_0c0b4ba6: /* original 4e0b, guest PC 0x0c0b4ba6 */
if(!s->budget--) { s->failed_pc=0x0c0b4ba6u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4baau;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4baau) { target=s->pc; goto dispatch; }
goto P_0c0b4baa;
P_0c0b4ba8: /* original 65b2, guest PC 0x0c0b4ba8 */
if(!s->budget--) { s->failed_pc=0x0c0b4ba8u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4baa;
P_0c0b4baa: /* original 9482, guest PC 0x0c0b4baa */
if(!s->budget--) { s->failed_pc=0x0c0b4baau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cb2u,2);
goto P_0c0b4bac;
P_0c0b4bac: /* original 4e0b, guest PC 0x0c0b4bac */
if(!s->budget--) { s->failed_pc=0x0c0b4bacu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bb0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bb0u) { target=s->pc; goto dispatch; }
goto P_0c0b4bb0;
P_0c0b4bae: /* original 65b2, guest PC 0x0c0b4bae */
if(!s->budget--) { s->failed_pc=0x0c0b4baeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4bb0;
P_0c0b4bb0: /* original 9480, guest PC 0x0c0b4bb0 */
if(!s->budget--) { s->failed_pc=0x0c0b4bb0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cb4u,2);
goto P_0c0b4bb2;
P_0c0b4bb2: /* original 4e0b, guest PC 0x0c0b4bb2 */
if(!s->budget--) { s->failed_pc=0x0c0b4bb2u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bb6u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bb6u) { target=s->pc; goto dispatch; }
goto P_0c0b4bb6;
P_0c0b4bb4: /* original 65b2, guest PC 0x0c0b4bb4 */
if(!s->budget--) { s->failed_pc=0x0c0b4bb4u; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4bb6;
P_0c0b4bb6: /* original 947e, guest PC 0x0c0b4bb6 */
if(!s->budget--) { s->failed_pc=0x0c0b4bb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cb6u,2);
goto P_0c0b4bb8;
P_0c0b4bb8: /* original 4e0b, guest PC 0x0c0b4bb8 */
if(!s->budget--) { s->failed_pc=0x0c0b4bb8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bbcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bbcu) { target=s->pc; goto dispatch; }
goto P_0c0b4bbc;
P_0c0b4bba: /* original 65b2, guest PC 0x0c0b4bba */
if(!s->budget--) { s->failed_pc=0x0c0b4bbau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c0b4bbc;
P_0c0b4bbc: /* original 947c, guest PC 0x0c0b4bbc */
if(!s->budget--) { s->failed_pc=0x0c0b4bbcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cb8u,2);
goto P_0c0b4bbe;
P_0c0b4bbe: /* original 4e0b, guest PC 0x0c0b4bbe */
if(!s->budget--) { s->failed_pc=0x0c0b4bbeu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bc2u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bc2u) { target=s->pc; goto dispatch; }
goto P_0c0b4bc2;
P_0c0b4bc0: /* original 65a2, guest PC 0x0c0b4bc0 */
if(!s->budget--) { s->failed_pc=0x0c0b4bc0u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4bc2;
P_0c0b4bc2: /* original 947a, guest PC 0x0c0b4bc2 */
if(!s->budget--) { s->failed_pc=0x0c0b4bc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cbau,2);
goto P_0c0b4bc4;
P_0c0b4bc4: /* original 4e0b, guest PC 0x0c0b4bc4 */
if(!s->budget--) { s->failed_pc=0x0c0b4bc4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bc8u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bc8u) { target=s->pc; goto dispatch; }
goto P_0c0b4bc8;
P_0c0b4bc6: /* original 65a2, guest PC 0x0c0b4bc6 */
if(!s->budget--) { s->failed_pc=0x0c0b4bc6u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4bc8;
P_0c0b4bc8: /* original 9478, guest PC 0x0c0b4bc8 */
if(!s->budget--) { s->failed_pc=0x0c0b4bc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cbcu,2);
goto P_0c0b4bca;
P_0c0b4bca: /* original 4e0b, guest PC 0x0c0b4bca */
if(!s->budget--) { s->failed_pc=0x0c0b4bcau; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bceu;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bceu) { target=s->pc; goto dispatch; }
goto P_0c0b4bce;
P_0c0b4bcc: /* original 65a2, guest PC 0x0c0b4bcc */
if(!s->budget--) { s->failed_pc=0x0c0b4bccu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4bce;
P_0c0b4bce: /* original 9476, guest PC 0x0c0b4bce */
if(!s->budget--) { s->failed_pc=0x0c0b4bceu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cbeu,2);
goto P_0c0b4bd0;
P_0c0b4bd0: /* original 4e0b, guest PC 0x0c0b4bd0 */
if(!s->budget--) { s->failed_pc=0x0c0b4bd0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bd4u;
tmp=read(ram,r[10],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bd4u) { target=s->pc; goto dispatch; }
goto P_0c0b4bd4;
P_0c0b4bd2: /* original 65a2, guest PC 0x0c0b4bd2 */
if(!s->budget--) { s->failed_pc=0x0c0b4bd2u; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0b4bd4;
P_0c0b4bd4: /* original 9574, guest PC 0x0c0b4bd4 */
if(!s->budget--) { s->failed_pc=0x0c0b4bd4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cc0u,2);
goto P_0c0b4bd6;
P_0c0b4bd6: /* original 35dc, guest PC 0x0c0b4bd6 */
if(!s->budget--) { s->failed_pc=0x0c0b4bd6u; return 0; }
r[5]+=r[13];
goto P_0c0b4bd8;
P_0c0b4bd8: /* original 2f52, guest PC 0x0c0b4bd8 */
if(!s->budget--) { s->failed_pc=0x0c0b4bd8u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4bda;
P_0c0b4bda: /* original 9472, guest PC 0x0c0b4bda */
if(!s->budget--) { s->failed_pc=0x0c0b4bdau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cc2u,2);
goto P_0c0b4bdc;
P_0c0b4bdc: /* original 4e0b, guest PC 0x0c0b4bdc */
if(!s->budget--) { s->failed_pc=0x0c0b4bdcu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4be0u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4be0u) { target=s->pc; goto dispatch; }
goto P_0c0b4be0;
P_0c0b4bde: /* original 6552, guest PC 0x0c0b4bde */
if(!s->budget--) { s->failed_pc=0x0c0b4bdeu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4be0;
P_0c0b4be0: /* original 9470, guest PC 0x0c0b4be0 */
if(!s->budget--) { s->failed_pc=0x0c0b4be0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cc4u,2);
goto P_0c0b4be2;
P_0c0b4be2: /* original 65f2, guest PC 0x0c0b4be2 */
if(!s->budget--) { s->failed_pc=0x0c0b4be2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4be4;
P_0c0b4be4: /* original 4e0b, guest PC 0x0c0b4be4 */
if(!s->budget--) { s->failed_pc=0x0c0b4be4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4be8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4be8u) { target=s->pc; goto dispatch; }
goto P_0c0b4be8;
P_0c0b4be6: /* original 6552, guest PC 0x0c0b4be6 */
if(!s->budget--) { s->failed_pc=0x0c0b4be6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4be8;
P_0c0b4be8: /* original 956d, guest PC 0x0c0b4be8 */
if(!s->budget--) { s->failed_pc=0x0c0b4be8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cc6u,2);
goto P_0c0b4bea;
P_0c0b4bea: /* original 35dc, guest PC 0x0c0b4bea */
if(!s->budget--) { s->failed_pc=0x0c0b4beau; return 0; }
r[5]+=r[13];
goto P_0c0b4bec;
P_0c0b4bec: /* original 2f52, guest PC 0x0c0b4bec */
if(!s->budget--) { s->failed_pc=0x0c0b4becu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4bee;
P_0c0b4bee: /* original 946b, guest PC 0x0c0b4bee */
if(!s->budget--) { s->failed_pc=0x0c0b4beeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cc8u,2);
goto P_0c0b4bf0;
P_0c0b4bf0: /* original 4e0b, guest PC 0x0c0b4bf0 */
if(!s->budget--) { s->failed_pc=0x0c0b4bf0u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bf4u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bf4u) { target=s->pc; goto dispatch; }
goto P_0c0b4bf4;
P_0c0b4bf2: /* original 6552, guest PC 0x0c0b4bf2 */
if(!s->budget--) { s->failed_pc=0x0c0b4bf2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4bf4;
P_0c0b4bf4: /* original 9469, guest PC 0x0c0b4bf4 */
if(!s->budget--) { s->failed_pc=0x0c0b4bf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ccau,2);
goto P_0c0b4bf6;
P_0c0b4bf6: /* original 65f2, guest PC 0x0c0b4bf6 */
if(!s->budget--) { s->failed_pc=0x0c0b4bf6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4bf8;
P_0c0b4bf8: /* original 4e0b, guest PC 0x0c0b4bf8 */
if(!s->budget--) { s->failed_pc=0x0c0b4bf8u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4bfcu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4bfcu) { target=s->pc; goto dispatch; }
goto P_0c0b4bfc;
P_0c0b4bfa: /* original 6552, guest PC 0x0c0b4bfa */
if(!s->budget--) { s->failed_pc=0x0c0b4bfau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4bfc;
P_0c0b4bfc: /* original 9467, guest PC 0x0c0b4bfc */
if(!s->budget--) { s->failed_pc=0x0c0b4bfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cceu,2);
goto P_0c0b4bfe;
P_0c0b4bfe: /* original 9065, guest PC 0x0c0b4bfe */
if(!s->budget--) { s->failed_pc=0x0c0b4bfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cccu,2);
goto P_0c0b4c00;
P_0c0b4c00: /* original 4e0b, guest PC 0x0c0b4c00 */
if(!s->budget--) { s->failed_pc=0x0c0b4c00u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c04u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c04u) { target=s->pc; goto dispatch; }
goto P_0c0b4c04;
P_0c0b4c02: /* original 05de, guest PC 0x0c0b4c02 */
if(!s->budget--) { s->failed_pc=0x0c0b4c02u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c04;
P_0c0b4c04: /* original 9564, guest PC 0x0c0b4c04 */
if(!s->budget--) { s->failed_pc=0x0c0b4c04u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cd0u,2);
goto P_0c0b4c06;
P_0c0b4c06: /* original 35dc, guest PC 0x0c0b4c06 */
if(!s->budget--) { s->failed_pc=0x0c0b4c06u; return 0; }
r[5]+=r[13];
goto P_0c0b4c08;
P_0c0b4c08: /* original 2f52, guest PC 0x0c0b4c08 */
if(!s->budget--) { s->failed_pc=0x0c0b4c08u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4c0a;
P_0c0b4c0a: /* original 9462, guest PC 0x0c0b4c0a */
if(!s->budget--) { s->failed_pc=0x0c0b4c0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cd2u,2);
goto P_0c0b4c0c;
P_0c0b4c0c: /* original 4e0b, guest PC 0x0c0b4c0c */
if(!s->budget--) { s->failed_pc=0x0c0b4c0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c10u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c10u) { target=s->pc; goto dispatch; }
goto P_0c0b4c10;
P_0c0b4c0e: /* original 6552, guest PC 0x0c0b4c0e */
if(!s->budget--) { s->failed_pc=0x0c0b4c0eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c10;
P_0c0b4c10: /* original 9460, guest PC 0x0c0b4c10 */
if(!s->budget--) { s->failed_pc=0x0c0b4c10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cd4u,2);
goto P_0c0b4c12;
P_0c0b4c12: /* original 65f2, guest PC 0x0c0b4c12 */
if(!s->budget--) { s->failed_pc=0x0c0b4c12u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4c14;
P_0c0b4c14: /* original 4e0b, guest PC 0x0c0b4c14 */
if(!s->budget--) { s->failed_pc=0x0c0b4c14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c18u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c18u) { target=s->pc; goto dispatch; }
goto P_0c0b4c18;
P_0c0b4c16: /* original 6552, guest PC 0x0c0b4c16 */
if(!s->budget--) { s->failed_pc=0x0c0b4c16u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c18;
P_0c0b4c18: /* original 945e, guest PC 0x0c0b4c18 */
if(!s->budget--) { s->failed_pc=0x0c0b4c18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cd8u,2);
goto P_0c0b4c1a;
P_0c0b4c1a: /* original 905c, guest PC 0x0c0b4c1a */
if(!s->budget--) { s->failed_pc=0x0c0b4c1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cd6u,2);
goto P_0c0b4c1c;
P_0c0b4c1c: /* original 4e0b, guest PC 0x0c0b4c1c */
if(!s->budget--) { s->failed_pc=0x0c0b4c1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c20u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c20u) { target=s->pc; goto dispatch; }
goto P_0c0b4c20;
P_0c0b4c1e: /* original 05de, guest PC 0x0c0b4c1e */
if(!s->budget--) { s->failed_pc=0x0c0b4c1eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c20;
P_0c0b4c20: /* original 955b, guest PC 0x0c0b4c20 */
if(!s->budget--) { s->failed_pc=0x0c0b4c20u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cdau,2);
goto P_0c0b4c22;
P_0c0b4c22: /* original 35dc, guest PC 0x0c0b4c22 */
if(!s->budget--) { s->failed_pc=0x0c0b4c22u; return 0; }
r[5]+=r[13];
goto P_0c0b4c24;
P_0c0b4c24: /* original 2f52, guest PC 0x0c0b4c24 */
if(!s->budget--) { s->failed_pc=0x0c0b4c24u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4c26;
P_0c0b4c26: /* original 9459, guest PC 0x0c0b4c26 */
if(!s->budget--) { s->failed_pc=0x0c0b4c26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cdcu,2);
goto P_0c0b4c28;
P_0c0b4c28: /* original 4e0b, guest PC 0x0c0b4c28 */
if(!s->budget--) { s->failed_pc=0x0c0b4c28u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c2cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c2cu) { target=s->pc; goto dispatch; }
goto P_0c0b4c2c;
P_0c0b4c2a: /* original 6552, guest PC 0x0c0b4c2a */
if(!s->budget--) { s->failed_pc=0x0c0b4c2au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c2c;
P_0c0b4c2c: /* original 9457, guest PC 0x0c0b4c2c */
if(!s->budget--) { s->failed_pc=0x0c0b4c2cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cdeu,2);
goto P_0c0b4c2e;
P_0c0b4c2e: /* original 65f2, guest PC 0x0c0b4c2e */
if(!s->budget--) { s->failed_pc=0x0c0b4c2eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4c30;
P_0c0b4c30: /* original 4e0b, guest PC 0x0c0b4c30 */
if(!s->budget--) { s->failed_pc=0x0c0b4c30u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c34u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c34u) { target=s->pc; goto dispatch; }
goto P_0c0b4c34;
P_0c0b4c32: /* original 6552, guest PC 0x0c0b4c32 */
if(!s->budget--) { s->failed_pc=0x0c0b4c32u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c34;
P_0c0b4c34: /* original 9455, guest PC 0x0c0b4c34 */
if(!s->budget--) { s->failed_pc=0x0c0b4c34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ce2u,2);
goto P_0c0b4c36;
P_0c0b4c36: /* original 9053, guest PC 0x0c0b4c36 */
if(!s->budget--) { s->failed_pc=0x0c0b4c36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ce0u,2);
goto P_0c0b4c38;
P_0c0b4c38: /* original 4e0b, guest PC 0x0c0b4c38 */
if(!s->budget--) { s->failed_pc=0x0c0b4c38u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c3cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c3cu) { target=s->pc; goto dispatch; }
goto P_0c0b4c3c;
P_0c0b4c3a: /* original 05de, guest PC 0x0c0b4c3a */
if(!s->budget--) { s->failed_pc=0x0c0b4c3au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c3c;
P_0c0b4c3c: /* original 9552, guest PC 0x0c0b4c3c */
if(!s->budget--) { s->failed_pc=0x0c0b4c3cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ce4u,2);
goto P_0c0b4c3e;
P_0c0b4c3e: /* original 35dc, guest PC 0x0c0b4c3e */
if(!s->budget--) { s->failed_pc=0x0c0b4c3eu; return 0; }
r[5]+=r[13];
goto P_0c0b4c40;
P_0c0b4c40: /* original 2f52, guest PC 0x0c0b4c40 */
if(!s->budget--) { s->failed_pc=0x0c0b4c40u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4c42;
P_0c0b4c42: /* original 9450, guest PC 0x0c0b4c42 */
if(!s->budget--) { s->failed_pc=0x0c0b4c42u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ce6u,2);
goto P_0c0b4c44;
P_0c0b4c44: /* original 4e0b, guest PC 0x0c0b4c44 */
if(!s->budget--) { s->failed_pc=0x0c0b4c44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c48u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c48u) { target=s->pc; goto dispatch; }
goto P_0c0b4c48;
P_0c0b4c46: /* original 6552, guest PC 0x0c0b4c46 */
if(!s->budget--) { s->failed_pc=0x0c0b4c46u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c48;
P_0c0b4c48: /* original 944e, guest PC 0x0c0b4c48 */
if(!s->budget--) { s->failed_pc=0x0c0b4c48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ce8u,2);
goto P_0c0b4c4a;
P_0c0b4c4a: /* original 65f2, guest PC 0x0c0b4c4a */
if(!s->budget--) { s->failed_pc=0x0c0b4c4au; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4c4c;
P_0c0b4c4c: /* original 4e0b, guest PC 0x0c0b4c4c */
if(!s->budget--) { s->failed_pc=0x0c0b4c4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c50u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c50u) { target=s->pc; goto dispatch; }
goto P_0c0b4c50;
P_0c0b4c4e: /* original 6552, guest PC 0x0c0b4c4e */
if(!s->budget--) { s->failed_pc=0x0c0b4c4eu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c50;
P_0c0b4c50: /* original 954b, guest PC 0x0c0b4c50 */
if(!s->budget--) { s->failed_pc=0x0c0b4c50u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ceau,2);
goto P_0c0b4c52;
P_0c0b4c52: /* original 35dc, guest PC 0x0c0b4c52 */
if(!s->budget--) { s->failed_pc=0x0c0b4c52u; return 0; }
r[5]+=r[13];
goto P_0c0b4c54;
P_0c0b4c54: /* original 2f52, guest PC 0x0c0b4c54 */
if(!s->budget--) { s->failed_pc=0x0c0b4c54u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0b4c56;
P_0c0b4c56: /* original 9449, guest PC 0x0c0b4c56 */
if(!s->budget--) { s->failed_pc=0x0c0b4c56u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cecu,2);
goto P_0c0b4c58;
P_0c0b4c58: /* original 4e0b, guest PC 0x0c0b4c58 */
if(!s->budget--) { s->failed_pc=0x0c0b4c58u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c5cu;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c5cu) { target=s->pc; goto dispatch; }
goto P_0c0b4c5c;
P_0c0b4c5a: /* original 6552, guest PC 0x0c0b4c5a */
if(!s->budget--) { s->failed_pc=0x0c0b4c5au; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c5c;
P_0c0b4c5c: /* original 9447, guest PC 0x0c0b4c5c */
if(!s->budget--) { s->failed_pc=0x0c0b4c5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4ceeu,2);
goto P_0c0b4c5e;
P_0c0b4c5e: /* original 65f2, guest PC 0x0c0b4c5e */
if(!s->budget--) { s->failed_pc=0x0c0b4c5eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0b4c60;
P_0c0b4c60: /* original 4e0b, guest PC 0x0c0b4c60 */
if(!s->budget--) { s->failed_pc=0x0c0b4c60u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c64u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c64u) { target=s->pc; goto dispatch; }
goto P_0c0b4c64;
P_0c0b4c62: /* original 6552, guest PC 0x0c0b4c62 */
if(!s->budget--) { s->failed_pc=0x0c0b4c62u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0b4c64;
P_0c0b4c64: /* original 9445, guest PC 0x0c0b4c64 */
if(!s->budget--) { s->failed_pc=0x0c0b4c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cf2u,2);
goto P_0c0b4c66;
P_0c0b4c66: /* original 9043, guest PC 0x0c0b4c66 */
if(!s->budget--) { s->failed_pc=0x0c0b4c66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cf0u,2);
goto P_0c0b4c68;
P_0c0b4c68: /* original 4e0b, guest PC 0x0c0b4c68 */
if(!s->budget--) { s->failed_pc=0x0c0b4c68u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c6cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c6cu) { target=s->pc; goto dispatch; }
goto P_0c0b4c6c;
P_0c0b4c6a: /* original 05de, guest PC 0x0c0b4c6a */
if(!s->budget--) { s->failed_pc=0x0c0b4c6au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c6c;
P_0c0b4c6c: /* original 9443, guest PC 0x0c0b4c6c */
if(!s->budget--) { s->failed_pc=0x0c0b4c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cf6u,2);
goto P_0c0b4c6e;
P_0c0b4c6e: /* original 9041, guest PC 0x0c0b4c6e */
if(!s->budget--) { s->failed_pc=0x0c0b4c6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cf4u,2);
goto P_0c0b4c70;
P_0c0b4c70: /* original 4e0b, guest PC 0x0c0b4c70 */
if(!s->budget--) { s->failed_pc=0x0c0b4c70u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c74u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c74u) { target=s->pc; goto dispatch; }
goto P_0c0b4c74;
P_0c0b4c72: /* original 05de, guest PC 0x0c0b4c72 */
if(!s->budget--) { s->failed_pc=0x0c0b4c72u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c74;
P_0c0b4c74: /* original 9441, guest PC 0x0c0b4c74 */
if(!s->budget--) { s->failed_pc=0x0c0b4c74u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cfau,2);
goto P_0c0b4c76;
P_0c0b4c76: /* original 903f, guest PC 0x0c0b4c76 */
if(!s->budget--) { s->failed_pc=0x0c0b4c76u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cf8u,2);
goto P_0c0b4c78;
P_0c0b4c78: /* original 4e0b, guest PC 0x0c0b4c78 */
if(!s->budget--) { s->failed_pc=0x0c0b4c78u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c7cu;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c7cu) { target=s->pc; goto dispatch; }
goto P_0c0b4c7c;
P_0c0b4c7a: /* original 05de, guest PC 0x0c0b4c7a */
if(!s->budget--) { s->failed_pc=0x0c0b4c7au; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c7c;
P_0c0b4c7c: /* original 943f, guest PC 0x0c0b4c7c */
if(!s->budget--) { s->failed_pc=0x0c0b4c7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cfeu,2);
goto P_0c0b4c7e;
P_0c0b4c7e: /* original 903d, guest PC 0x0c0b4c7e */
if(!s->budget--) { s->failed_pc=0x0c0b4c7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4cfcu,2);
goto P_0c0b4c80;
P_0c0b4c80: /* original 4e0b, guest PC 0x0c0b4c80 */
if(!s->budget--) { s->failed_pc=0x0c0b4c80u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4c84u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4c84u) { target=s->pc; goto dispatch; }
goto P_0c0b4c84;
P_0c0b4c82: /* original 05de, guest PC 0x0c0b4c82 */
if(!s->budget--) { s->failed_pc=0x0c0b4c82u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4c84;
P_0c0b4c84: /* original 903c, guest PC 0x0c0b4c84 */
if(!s->budget--) { s->failed_pc=0x0c0b4c84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d00u,2);
goto P_0c0b4c86;
P_0c0b4c86: /* original a03c, guest PC 0x0c0b4c86 */
if(!s->budget--) { s->failed_pc=0x0c0b4c86u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d02;
P_0c0b4c88: /* original 05de, guest PC 0x0c0b4c88 */
if(!s->budget--) { s->failed_pc=0x0c0b4c88u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
if(!vf3_matrix_family(0x0c0b4c8au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b4c8au; return 0; } return 1;
P_0c0b4d02: /* original 9432, guest PC 0x0c0b4d02 */
if(!s->budget--) { s->failed_pc=0x0c0b4d02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d6au,2);
goto P_0c0b4d04;
P_0c0b4d04: /* original 4e0b, guest PC 0x0c0b4d04 */
if(!s->budget--) { s->failed_pc=0x0c0b4d04u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d08u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d08u) { target=s->pc; goto dispatch; }
goto P_0c0b4d08;
P_0c0b4d06: /* original 0009, guest PC 0x0c0b4d06 */
if(!s->budget--) { s->failed_pc=0x0c0b4d06u; return 0; }
goto P_0c0b4d08;
P_0c0b4d08: /* original 9431, guest PC 0x0c0b4d08 */
if(!s->budget--) { s->failed_pc=0x0c0b4d08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d6eu,2);
goto P_0c0b4d0a;
P_0c0b4d0a: /* original 902f, guest PC 0x0c0b4d0a */
if(!s->budget--) { s->failed_pc=0x0c0b4d0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d6cu,2);
goto P_0c0b4d0c;
P_0c0b4d0c: /* original 4e0b, guest PC 0x0c0b4d0c */
if(!s->budget--) { s->failed_pc=0x0c0b4d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d10u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d10u) { target=s->pc; goto dispatch; }
goto P_0c0b4d10;
P_0c0b4d0e: /* original 05de, guest PC 0x0c0b4d0e */
if(!s->budget--) { s->failed_pc=0x0c0b4d0eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d10;
P_0c0b4d10: /* original 942f, guest PC 0x0c0b4d10 */
if(!s->budget--) { s->failed_pc=0x0c0b4d10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d72u,2);
goto P_0c0b4d12;
P_0c0b4d12: /* original 902d, guest PC 0x0c0b4d12 */
if(!s->budget--) { s->failed_pc=0x0c0b4d12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d70u,2);
goto P_0c0b4d14;
P_0c0b4d14: /* original 4e0b, guest PC 0x0c0b4d14 */
if(!s->budget--) { s->failed_pc=0x0c0b4d14u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d18u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d18u) { target=s->pc; goto dispatch; }
goto P_0c0b4d18;
P_0c0b4d16: /* original 05de, guest PC 0x0c0b4d16 */
if(!s->budget--) { s->failed_pc=0x0c0b4d16u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d18;
P_0c0b4d18: /* original 942d, guest PC 0x0c0b4d18 */
if(!s->budget--) { s->failed_pc=0x0c0b4d18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d76u,2);
goto P_0c0b4d1a;
P_0c0b4d1a: /* original 902b, guest PC 0x0c0b4d1a */
if(!s->budget--) { s->failed_pc=0x0c0b4d1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d74u,2);
goto P_0c0b4d1c;
P_0c0b4d1c: /* original 4e0b, guest PC 0x0c0b4d1c */
if(!s->budget--) { s->failed_pc=0x0c0b4d1cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d20u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d20u) { target=s->pc; goto dispatch; }
goto P_0c0b4d20;
P_0c0b4d1e: /* original 05de, guest PC 0x0c0b4d1e */
if(!s->budget--) { s->failed_pc=0x0c0b4d1eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d20;
P_0c0b4d20: /* original 942b, guest PC 0x0c0b4d20 */
if(!s->budget--) { s->failed_pc=0x0c0b4d20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d7au,2);
goto P_0c0b4d22;
P_0c0b4d22: /* original 9029, guest PC 0x0c0b4d22 */
if(!s->budget--) { s->failed_pc=0x0c0b4d22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d78u,2);
goto P_0c0b4d24;
P_0c0b4d24: /* original 4e0b, guest PC 0x0c0b4d24 */
if(!s->budget--) { s->failed_pc=0x0c0b4d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d28u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d28u) { target=s->pc; goto dispatch; }
goto P_0c0b4d28;
P_0c0b4d26: /* original 05de, guest PC 0x0c0b4d26 */
if(!s->budget--) { s->failed_pc=0x0c0b4d26u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d28;
P_0c0b4d28: /* original 9429, guest PC 0x0c0b4d28 */
if(!s->budget--) { s->failed_pc=0x0c0b4d28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d7eu,2);
goto P_0c0b4d2a;
P_0c0b4d2a: /* original 9027, guest PC 0x0c0b4d2a */
if(!s->budget--) { s->failed_pc=0x0c0b4d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d7cu,2);
goto P_0c0b4d2c;
P_0c0b4d2c: /* original 4e0b, guest PC 0x0c0b4d2c */
if(!s->budget--) { s->failed_pc=0x0c0b4d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d30u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d30u) { target=s->pc; goto dispatch; }
goto P_0c0b4d30;
P_0c0b4d2e: /* original 05de, guest PC 0x0c0b4d2e */
if(!s->budget--) { s->failed_pc=0x0c0b4d2eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d30;
P_0c0b4d30: /* original 9427, guest PC 0x0c0b4d30 */
if(!s->budget--) { s->failed_pc=0x0c0b4d30u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d82u,2);
goto P_0c0b4d32;
P_0c0b4d32: /* original 9025, guest PC 0x0c0b4d32 */
if(!s->budget--) { s->failed_pc=0x0c0b4d32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d80u,2);
goto P_0c0b4d34;
P_0c0b4d34: /* original 4e0b, guest PC 0x0c0b4d34 */
if(!s->budget--) { s->failed_pc=0x0c0b4d34u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d38u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d38u) { target=s->pc; goto dispatch; }
goto P_0c0b4d38;
P_0c0b4d36: /* original 05de, guest PC 0x0c0b4d36 */
if(!s->budget--) { s->failed_pc=0x0c0b4d36u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d38;
P_0c0b4d38: /* original 9425, guest PC 0x0c0b4d38 */
if(!s->budget--) { s->failed_pc=0x0c0b4d38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d86u,2);
goto P_0c0b4d3a;
P_0c0b4d3a: /* original 9023, guest PC 0x0c0b4d3a */
if(!s->budget--) { s->failed_pc=0x0c0b4d3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d84u,2);
goto P_0c0b4d3c;
P_0c0b4d3c: /* original 4e0b, guest PC 0x0c0b4d3c */
if(!s->budget--) { s->failed_pc=0x0c0b4d3cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d40u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d40u) { target=s->pc; goto dispatch; }
goto P_0c0b4d40;
P_0c0b4d3e: /* original 05de, guest PC 0x0c0b4d3e */
if(!s->budget--) { s->failed_pc=0x0c0b4d3eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d40;
P_0c0b4d40: /* original 9423, guest PC 0x0c0b4d40 */
if(!s->budget--) { s->failed_pc=0x0c0b4d40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d8au,2);
goto P_0c0b4d42;
P_0c0b4d42: /* original 9021, guest PC 0x0c0b4d42 */
if(!s->budget--) { s->failed_pc=0x0c0b4d42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d88u,2);
goto P_0c0b4d44;
P_0c0b4d44: /* original 4e0b, guest PC 0x0c0b4d44 */
if(!s->budget--) { s->failed_pc=0x0c0b4d44u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d48u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d48u) { target=s->pc; goto dispatch; }
goto P_0c0b4d48;
P_0c0b4d46: /* original 05de, guest PC 0x0c0b4d46 */
if(!s->budget--) { s->failed_pc=0x0c0b4d46u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d48;
P_0c0b4d48: /* original 9421, guest PC 0x0c0b4d48 */
if(!s->budget--) { s->failed_pc=0x0c0b4d48u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d8eu,2);
goto P_0c0b4d4a;
P_0c0b4d4a: /* original 901f, guest PC 0x0c0b4d4a */
if(!s->budget--) { s->failed_pc=0x0c0b4d4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d8cu,2);
goto P_0c0b4d4c;
P_0c0b4d4c: /* original 4e0b, guest PC 0x0c0b4d4c */
if(!s->budget--) { s->failed_pc=0x0c0b4d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d50u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d50u) { target=s->pc; goto dispatch; }
goto P_0c0b4d50;
P_0c0b4d4e: /* original 05de, guest PC 0x0c0b4d4e */
if(!s->budget--) { s->failed_pc=0x0c0b4d4eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d50;
P_0c0b4d50: /* original 941f, guest PC 0x0c0b4d50 */
if(!s->budget--) { s->failed_pc=0x0c0b4d50u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d92u,2);
goto P_0c0b4d52;
P_0c0b4d52: /* original 901d, guest PC 0x0c0b4d52 */
if(!s->budget--) { s->failed_pc=0x0c0b4d52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0b4d90u,2);
goto P_0c0b4d54;
P_0c0b4d54: /* original 4e0b, guest PC 0x0c0b4d54 */
if(!s->budget--) { s->failed_pc=0x0c0b4d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0b4d58u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0b4d58u) { target=s->pc; goto dispatch; }
goto P_0c0b4d58;
P_0c0b4d56: /* original 05de, guest PC 0x0c0b4d56 */
if(!s->budget--) { s->failed_pc=0x0c0b4d56u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0b4d58;
P_0c0b4d58: /* original 7f08, guest PC 0x0c0b4d58 */
if(!s->budget--) { s->failed_pc=0x0c0b4d58u; return 0; }
r[15]+=0x00000008u;
goto P_0c0b4d5a;
P_0c0b4d5a: /* original 4f26, guest PC 0x0c0b4d5a */
if(!s->budget--) { s->failed_pc=0x0c0b4d5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0b4d5c;
P_0c0b4d5c: /* original 69f6, guest PC 0x0c0b4d5c */
if(!s->budget--) { s->failed_pc=0x0c0b4d5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0b4d5e;
P_0c0b4d5e: /* original 6af6, guest PC 0x0c0b4d5e */
if(!s->budget--) { s->failed_pc=0x0c0b4d5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0b4d60;
P_0c0b4d60: /* original 6bf6, guest PC 0x0c0b4d60 */
if(!s->budget--) { s->failed_pc=0x0c0b4d60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0b4d62;
P_0c0b4d62: /* original 6cf6, guest PC 0x0c0b4d62 */
if(!s->budget--) { s->failed_pc=0x0c0b4d62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0b4d64;
P_0c0b4d64: /* original 6df6, guest PC 0x0c0b4d64 */
if(!s->budget--) { s->failed_pc=0x0c0b4d64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0b4d66;
P_0c0b4d66: /* original 000b, guest PC 0x0c0b4d66 */
if(!s->budget--) { s->failed_pc=0x0c0b4d66u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0b4d68: /* original 6ef6, guest PC 0x0c0b4d68 */
if(!s->budget--) { s->failed_pc=0x0c0b4d68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0b4d6au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0b4d6au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
