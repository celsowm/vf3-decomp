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
int vf3_away_batch8_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c063af6u: goto P_0c063af6;
case 0x0c063af8u: goto P_0c063af8;
case 0x0c063afau: goto P_0c063afa;
case 0x0c063afcu: goto P_0c063afc;
case 0x0c063afeu: goto P_0c063afe;
case 0x0c063b00u: goto P_0c063b00;
case 0x0c063b02u: goto P_0c063b02;
case 0x0c063b04u: goto P_0c063b04;
case 0x0c063b06u: goto P_0c063b06;
case 0x0c063b08u: goto P_0c063b08;
case 0x0c063b0au: goto P_0c063b0a;
case 0x0c063b0cu: goto P_0c063b0c;
case 0x0c063b0eu: goto P_0c063b0e;
case 0x0c063b10u: goto P_0c063b10;
case 0x0c063b12u: goto P_0c063b12;
case 0x0c063b14u: goto P_0c063b14;
case 0x0c063b16u: goto P_0c063b16;
case 0x0c063b18u: goto P_0c063b18;
case 0x0c063b1au: goto P_0c063b1a;
case 0x0c063b1cu: goto P_0c063b1c;
case 0x0c063b1eu: goto P_0c063b1e;
case 0x0c063b20u: goto P_0c063b20;
case 0x0c063b22u: goto P_0c063b22;
case 0x0c063b24u: goto P_0c063b24;
case 0x0c063b26u: goto P_0c063b26;
case 0x0c063b28u: goto P_0c063b28;
case 0x0c063b2au: goto P_0c063b2a;
case 0x0c063b2cu: goto P_0c063b2c;
case 0x0c063b2eu: goto P_0c063b2e;
case 0x0c063b30u: goto P_0c063b30;
case 0x0c063b32u: goto P_0c063b32;
case 0x0c063b34u: goto P_0c063b34;
case 0x0c063b36u: goto P_0c063b36;
case 0x0c063b38u: goto P_0c063b38;
case 0x0c063b3au: goto P_0c063b3a;
case 0x0c063b3cu: goto P_0c063b3c;
case 0x0c063b3eu: goto P_0c063b3e;
case 0x0c063b40u: goto P_0c063b40;
case 0x0c063b42u: goto P_0c063b42;
case 0x0c063b44u: goto P_0c063b44;
case 0x0c063b46u: goto P_0c063b46;
case 0x0c063b48u: goto P_0c063b48;
case 0x0c063b4au: goto P_0c063b4a;
case 0x0c063b4cu: goto P_0c063b4c;
case 0x0c063b4eu: goto P_0c063b4e;
case 0x0c063b50u: goto P_0c063b50;
case 0x0c063b52u: goto P_0c063b52;
case 0x0c063b54u: goto P_0c063b54;
case 0x0c063b56u: goto P_0c063b56;
case 0x0c063b58u: goto P_0c063b58;
case 0x0c063b5au: goto P_0c063b5a;
case 0x0c063b5cu: goto P_0c063b5c;
case 0x0c063b5eu: goto P_0c063b5e;
case 0x0c063b60u: goto P_0c063b60;
case 0x0c063b62u: goto P_0c063b62;
case 0x0c063b64u: goto P_0c063b64;
case 0x0c063b66u: goto P_0c063b66;
case 0x0c063b68u: goto P_0c063b68;
case 0x0c063b6au: goto P_0c063b6a;
case 0x0c063b6cu: goto P_0c063b6c;
case 0x0c063b6eu: goto P_0c063b6e;
case 0x0c063b70u: goto P_0c063b70;
case 0x0c063b72u: goto P_0c063b72;
case 0x0c063b74u: goto P_0c063b74;
case 0x0c063b76u: goto P_0c063b76;
case 0x0c063b78u: goto P_0c063b78;
case 0x0c063b7au: goto P_0c063b7a;
case 0x0c063b7cu: goto P_0c063b7c;
case 0x0c063b7eu: goto P_0c063b7e;
case 0x0c063b80u: goto P_0c063b80;
case 0x0c063b82u: goto P_0c063b82;
case 0x0c063b84u: goto P_0c063b84;
case 0x0c063b86u: goto P_0c063b86;
case 0x0c063b88u: goto P_0c063b88;
case 0x0c063b8au: goto P_0c063b8a;
case 0x0c063b8cu: goto P_0c063b8c;
case 0x0c063b8eu: goto P_0c063b8e;
case 0x0c063b90u: goto P_0c063b90;
case 0x0c063b92u: goto P_0c063b92;
case 0x0c063b94u: goto P_0c063b94;
case 0x0c063b96u: goto P_0c063b96;
case 0x0c063b98u: goto P_0c063b98;
case 0x0c063b9au: goto P_0c063b9a;
case 0x0c063b9cu: goto P_0c063b9c;
case 0x0c063b9eu: goto P_0c063b9e;
case 0x0c063ba0u: goto P_0c063ba0;
case 0x0c063ba2u: goto P_0c063ba2;
case 0x0c063ba4u: goto P_0c063ba4;
case 0x0c063ba6u: goto P_0c063ba6;
case 0x0c063ba8u: goto P_0c063ba8;
case 0x0c063baau: goto P_0c063baa;
case 0x0c063bacu: goto P_0c063bac;
case 0x0c063baeu: goto P_0c063bae;
case 0x0c063bb0u: goto P_0c063bb0;
case 0x0c063bb2u: goto P_0c063bb2;
case 0x0c063bb4u: goto P_0c063bb4;
case 0x0c063bb6u: goto P_0c063bb6;
case 0x0c063bb8u: goto P_0c063bb8;
case 0x0c063bbau: goto P_0c063bba;
case 0x0c063bbcu: goto P_0c063bbc;
case 0x0c063bbeu: goto P_0c063bbe;
case 0x0c063bc0u: goto P_0c063bc0;
case 0x0c063bc2u: goto P_0c063bc2;
case 0x0c063bc4u: goto P_0c063bc4;
case 0x0c063bc6u: goto P_0c063bc6;
case 0x0c063bc8u: goto P_0c063bc8;
case 0x0c063bcau: goto P_0c063bca;
case 0x0c063bccu: goto P_0c063bcc;
case 0x0c063bceu: goto P_0c063bce;
case 0x0c063bd0u: goto P_0c063bd0;
case 0x0c063bd2u: goto P_0c063bd2;
case 0x0c063bd4u: goto P_0c063bd4;
case 0x0c063bd6u: goto P_0c063bd6;
case 0x0c063bd8u: goto P_0c063bd8;
case 0x0c063bdau: goto P_0c063bda;
case 0x0c063bdcu: goto P_0c063bdc;
case 0x0c063bdeu: goto P_0c063bde;
case 0x0c063be0u: goto P_0c063be0;
case 0x0c063be2u: goto P_0c063be2;
case 0x0c063be4u: goto P_0c063be4;
case 0x0c063be6u: goto P_0c063be6;
case 0x0c063be8u: goto P_0c063be8;
case 0x0c063beau: goto P_0c063bea;
case 0x0c063becu: goto P_0c063bec;
case 0x0c063beeu: goto P_0c063bee;
case 0x0c063bf0u: goto P_0c063bf0;
case 0x0c063bf2u: goto P_0c063bf2;
case 0x0c063bf4u: goto P_0c063bf4;
case 0x0c063bf6u: goto P_0c063bf6;
case 0x0c063bf8u: goto P_0c063bf8;
case 0x0c063bfau: goto P_0c063bfa;
case 0x0c063bfcu: goto P_0c063bfc;
case 0x0c063bfeu: goto P_0c063bfe;
case 0x0c063c00u: goto P_0c063c00;
case 0x0c063c02u: goto P_0c063c02;
case 0x0c063c04u: goto P_0c063c04;
case 0x0c063c06u: goto P_0c063c06;
case 0x0c063c08u: goto P_0c063c08;
case 0x0c063c0au: goto P_0c063c0a;
case 0x0c063c0cu: goto P_0c063c0c;
case 0x0c063c0eu: goto P_0c063c0e;
case 0x0c063c10u: goto P_0c063c10;
case 0x0c063c12u: goto P_0c063c12;
case 0x0c063c14u: goto P_0c063c14;
case 0x0c063c16u: goto P_0c063c16;
case 0x0c063c18u: goto P_0c063c18;
case 0x0c063c1au: goto P_0c063c1a;
case 0x0c063c1cu: goto P_0c063c1c;
case 0x0c063c1eu: goto P_0c063c1e;
case 0x0c063c20u: goto P_0c063c20;
case 0x0c063c22u: goto P_0c063c22;
case 0x0c063c24u: goto P_0c063c24;
case 0x0c063c26u: goto P_0c063c26;
case 0x0c063c28u: goto P_0c063c28;
case 0x0c063c2au: goto P_0c063c2a;
case 0x0c063c2cu: goto P_0c063c2c;
case 0x0c063c2eu: goto P_0c063c2e;
case 0x0c063c30u: goto P_0c063c30;
case 0x0c063c32u: goto P_0c063c32;
case 0x0c063c34u: goto P_0c063c34;
case 0x0c063c36u: goto P_0c063c36;
case 0x0c063c38u: goto P_0c063c38;
case 0x0c063c3au: goto P_0c063c3a;
case 0x0c063c3cu: goto P_0c063c3c;
case 0x0c063c3eu: goto P_0c063c3e;
case 0x0c063c40u: goto P_0c063c40;
case 0x0c063c42u: goto P_0c063c42;
case 0x0c063c44u: goto P_0c063c44;
case 0x0c063c46u: goto P_0c063c46;
case 0x0c063c48u: goto P_0c063c48;
case 0x0c063c4au: goto P_0c063c4a;
case 0x0c063c4cu: goto P_0c063c4c;
case 0x0c063c4eu: goto P_0c063c4e;
case 0x0c063c50u: goto P_0c063c50;
case 0x0c063c52u: goto P_0c063c52;
case 0x0c063d00u: goto P_0c063d00;
case 0x0c063d02u: goto P_0c063d02;
case 0x0c063d04u: goto P_0c063d04;
case 0x0c063d06u: goto P_0c063d06;
case 0x0c063d08u: goto P_0c063d08;
case 0x0c063d0au: goto P_0c063d0a;
case 0x0c063d0cu: goto P_0c063d0c;
case 0x0c063d0eu: goto P_0c063d0e;
case 0x0c063d10u: goto P_0c063d10;
case 0x0c063d12u: goto P_0c063d12;
case 0x0c063d14u: goto P_0c063d14;
case 0x0c063d16u: goto P_0c063d16;
case 0x0c063d18u: goto P_0c063d18;
case 0x0c063d1au: goto P_0c063d1a;
case 0x0c063d1cu: goto P_0c063d1c;
case 0x0c063d1eu: goto P_0c063d1e;
case 0x0c063d20u: goto P_0c063d20;
case 0x0c063d22u: goto P_0c063d22;
case 0x0c063d24u: goto P_0c063d24;
case 0x0c063d26u: goto P_0c063d26;
case 0x0c063d28u: goto P_0c063d28;
case 0x0c063d2au: goto P_0c063d2a;
case 0x0c063d2cu: goto P_0c063d2c;
case 0x0c063d2eu: goto P_0c063d2e;
case 0x0c063d30u: goto P_0c063d30;
case 0x0c063d32u: goto P_0c063d32;
case 0x0c063d34u: goto P_0c063d34;
case 0x0c063d36u: goto P_0c063d36;
case 0x0c063d38u: goto P_0c063d38;
case 0x0c063d3au: goto P_0c063d3a;
case 0x0c063d3cu: goto P_0c063d3c;
case 0x0c063d3eu: goto P_0c063d3e;
case 0x0c063d40u: goto P_0c063d40;
case 0x0c063d42u: goto P_0c063d42;
case 0x0c063d44u: goto P_0c063d44;
case 0x0c063d46u: goto P_0c063d46;
case 0x0c063d48u: goto P_0c063d48;
case 0x0c063d4au: goto P_0c063d4a;
case 0x0c063d4cu: goto P_0c063d4c;
case 0x0c063d4eu: goto P_0c063d4e;
case 0x0c063d50u: goto P_0c063d50;
case 0x0c063d52u: goto P_0c063d52;
case 0x0c063d54u: goto P_0c063d54;
case 0x0c063d56u: goto P_0c063d56;
case 0x0c063d58u: goto P_0c063d58;
case 0x0c063d5au: goto P_0c063d5a;
case 0x0c063d5cu: goto P_0c063d5c;
case 0x0c063d5eu: goto P_0c063d5e;
case 0x0c063d60u: goto P_0c063d60;
case 0x0c063d62u: goto P_0c063d62;
case 0x0c063d64u: goto P_0c063d64;
case 0x0c063d66u: goto P_0c063d66;
case 0x0c063d68u: goto P_0c063d68;
case 0x0c063d6au: goto P_0c063d6a;
case 0x0c063d6cu: goto P_0c063d6c;
case 0x0c063d6eu: goto P_0c063d6e;
case 0x0c063d70u: goto P_0c063d70;
case 0x0c063d72u: goto P_0c063d72;
case 0x0c063d74u: goto P_0c063d74;
case 0x0c063d76u: goto P_0c063d76;
case 0x0c063d78u: goto P_0c063d78;
case 0x0c063d7au: goto P_0c063d7a;
case 0x0c063d7cu: goto P_0c063d7c;
case 0x0c063d7eu: goto P_0c063d7e;
case 0x0c063d80u: goto P_0c063d80;
case 0x0c063d82u: goto P_0c063d82;
case 0x0c063d84u: goto P_0c063d84;
case 0x0c063d86u: goto P_0c063d86;
case 0x0c063d88u: goto P_0c063d88;
case 0x0c063d8au: goto P_0c063d8a;
case 0x0c063d8cu: goto P_0c063d8c;
case 0x0c063d8eu: goto P_0c063d8e;
case 0x0c063d90u: goto P_0c063d90;
case 0x0c063d92u: goto P_0c063d92;
case 0x0c063d94u: goto P_0c063d94;
case 0x0c063d96u: goto P_0c063d96;
case 0x0c063d98u: goto P_0c063d98;
case 0x0c063d9au: goto P_0c063d9a;
case 0x0c063d9cu: goto P_0c063d9c;
case 0x0c063d9eu: goto P_0c063d9e;
case 0x0c063da0u: goto P_0c063da0;
case 0x0c063da2u: goto P_0c063da2;
case 0x0c063da4u: goto P_0c063da4;
case 0x0c063da6u: goto P_0c063da6;
case 0x0c063da8u: goto P_0c063da8;
case 0x0c063daau: goto P_0c063daa;
case 0x0c063dacu: goto P_0c063dac;
case 0x0c063daeu: goto P_0c063dae;
case 0x0c063db0u: goto P_0c063db0;
case 0x0c063db2u: goto P_0c063db2;
case 0x0c063db4u: goto P_0c063db4;
case 0x0c063db6u: goto P_0c063db6;
case 0x0c063db8u: goto P_0c063db8;
case 0x0c063dbau: goto P_0c063dba;
case 0x0c063dbcu: goto P_0c063dbc;
case 0x0c063dbeu: goto P_0c063dbe;
case 0x0c063dc0u: goto P_0c063dc0;
case 0x0c063dc2u: goto P_0c063dc2;
case 0x0c063dc4u: goto P_0c063dc4;
case 0x0c063dc6u: goto P_0c063dc6;
case 0x0c063dc8u: goto P_0c063dc8;
case 0x0c063dcau: goto P_0c063dca;
case 0x0c063dccu: goto P_0c063dcc;
case 0x0c063dceu: goto P_0c063dce;
case 0x0c063dd0u: goto P_0c063dd0;
case 0x0c063dd2u: goto P_0c063dd2;
case 0x0c063dd4u: goto P_0c063dd4;
case 0x0c063dd6u: goto P_0c063dd6;
case 0x0c063dd8u: goto P_0c063dd8;
case 0x0c063ddau: goto P_0c063dda;
case 0x0c063ddcu: goto P_0c063ddc;
case 0x0c063ddeu: goto P_0c063dde;
case 0x0c063de0u: goto P_0c063de0;
case 0x0c063de2u: goto P_0c063de2;
case 0x0c063de4u: goto P_0c063de4;
case 0x0c063de6u: goto P_0c063de6;
case 0x0c063de8u: goto P_0c063de8;
case 0x0c063deau: goto P_0c063dea;
case 0x0c063decu: goto P_0c063dec;
case 0x0c063deeu: goto P_0c063dee;
case 0x0c063df0u: goto P_0c063df0;
case 0x0c063df2u: goto P_0c063df2;
case 0x0c063df4u: goto P_0c063df4;
case 0x0c063df6u: goto P_0c063df6;
case 0x0c063df8u: goto P_0c063df8;
case 0x0c063dfau: goto P_0c063dfa;
case 0x0c063e4cu: goto P_0c063e4c;
case 0x0c063e4eu: goto P_0c063e4e;
case 0x0c063e50u: goto P_0c063e50;
case 0x0c063e52u: goto P_0c063e52;
case 0x0c063e54u: goto P_0c063e54;
case 0x0c063e56u: goto P_0c063e56;
case 0x0c063e58u: goto P_0c063e58;
case 0x0c063e5au: goto P_0c063e5a;
case 0x0c063e5cu: goto P_0c063e5c;
case 0x0c063e5eu: goto P_0c063e5e;
case 0x0c063e60u: goto P_0c063e60;
case 0x0c063e62u: goto P_0c063e62;
case 0x0c063e64u: goto P_0c063e64;
case 0x0c063e66u: goto P_0c063e66;
case 0x0c063e68u: goto P_0c063e68;
case 0x0c063e6au: goto P_0c063e6a;
case 0x0c063e6cu: goto P_0c063e6c;
case 0x0c063e6eu: goto P_0c063e6e;
case 0x0c063e70u: goto P_0c063e70;
case 0x0c063e72u: goto P_0c063e72;
case 0x0c063e74u: goto P_0c063e74;
case 0x0c063e76u: goto P_0c063e76;
case 0x0c063e78u: goto P_0c063e78;
case 0x0c063e7au: goto P_0c063e7a;
case 0x0c063e7cu: goto P_0c063e7c;
case 0x0c063e7eu: goto P_0c063e7e;
case 0x0c063e80u: goto P_0c063e80;
case 0x0c063e82u: goto P_0c063e82;
case 0x0c063e84u: goto P_0c063e84;
case 0x0c063e86u: goto P_0c063e86;
case 0x0c063e88u: goto P_0c063e88;
case 0x0c063e8au: goto P_0c063e8a;
case 0x0c063e8cu: goto P_0c063e8c;
case 0x0c063e8eu: goto P_0c063e8e;
case 0x0c063e90u: goto P_0c063e90;
case 0x0c063e92u: goto P_0c063e92;
case 0x0c063e94u: goto P_0c063e94;
case 0x0c063e96u: goto P_0c063e96;
case 0x0c063e98u: goto P_0c063e98;
case 0x0c063e9au: goto P_0c063e9a;
case 0x0c063e9cu: goto P_0c063e9c;
case 0x0c063e9eu: goto P_0c063e9e;
case 0x0c063ea0u: goto P_0c063ea0;
case 0x0c063ea2u: goto P_0c063ea2;
case 0x0c063ea4u: goto P_0c063ea4;
case 0x0c063ea6u: goto P_0c063ea6;
case 0x0c063ea8u: goto P_0c063ea8;
case 0x0c063eaau: goto P_0c063eaa;
case 0x0c063eacu: goto P_0c063eac;
case 0x0c063eaeu: goto P_0c063eae;
case 0x0c063eb0u: goto P_0c063eb0;
case 0x0c063eb2u: goto P_0c063eb2;
case 0x0c063eb4u: goto P_0c063eb4;
case 0x0c063eb6u: goto P_0c063eb6;
case 0x0c063eb8u: goto P_0c063eb8;
case 0x0c063ebau: goto P_0c063eba;
case 0x0c063ebcu: goto P_0c063ebc;
case 0x0c063ebeu: goto P_0c063ebe;
case 0x0c063ec0u: goto P_0c063ec0;
case 0x0c063ec2u: goto P_0c063ec2;
case 0x0c063ec4u: goto P_0c063ec4;
case 0x0c063ec6u: goto P_0c063ec6;
case 0x0c063ec8u: goto P_0c063ec8;
case 0x0c063ecau: goto P_0c063eca;
case 0x0c063eccu: goto P_0c063ecc;
case 0x0c063eceu: goto P_0c063ece;
case 0x0c063ed0u: goto P_0c063ed0;
case 0x0c063ed2u: goto P_0c063ed2;
case 0x0c063ed4u: goto P_0c063ed4;
case 0x0c063ed6u: goto P_0c063ed6;
case 0x0c063ed8u: goto P_0c063ed8;
case 0x0c063edau: goto P_0c063eda;
case 0x0c063edcu: goto P_0c063edc;
case 0x0c063edeu: goto P_0c063ede;
case 0x0c063ee0u: goto P_0c063ee0;
case 0x0c063ee2u: goto P_0c063ee2;
case 0x0c063ee4u: goto P_0c063ee4;
case 0x0c063ee6u: goto P_0c063ee6;
case 0x0c063ee8u: goto P_0c063ee8;
case 0x0c063eeau: goto P_0c063eea;
case 0x0c063eecu: goto P_0c063eec;
case 0x0c063eeeu: goto P_0c063eee;
case 0x0c063ef0u: goto P_0c063ef0;
case 0x0c063ef2u: goto P_0c063ef2;
case 0x0c063ef4u: goto P_0c063ef4;
case 0x0c063ef6u: goto P_0c063ef6;
case 0x0c063ef8u: goto P_0c063ef8;
case 0x0c063efau: goto P_0c063efa;
case 0x0c063efcu: goto P_0c063efc;
case 0x0c063efeu: goto P_0c063efe;
case 0x0c063f00u: goto P_0c063f00;
case 0x0c063f02u: goto P_0c063f02;
case 0x0c063f04u: goto P_0c063f04;
case 0x0c063f06u: goto P_0c063f06;
case 0x0c063f08u: goto P_0c063f08;
case 0x0c063f0au: goto P_0c063f0a;
case 0x0c063f0cu: goto P_0c063f0c;
case 0x0c063f0eu: goto P_0c063f0e;
case 0x0c063f10u: goto P_0c063f10;
case 0x0c063f12u: goto P_0c063f12;
case 0x0c063f14u: goto P_0c063f14;
case 0x0c063f16u: goto P_0c063f16;
case 0x0c063f18u: goto P_0c063f18;
case 0x0c063f1au: goto P_0c063f1a;
case 0x0c063f1cu: goto P_0c063f1c;
case 0x0c063f1eu: goto P_0c063f1e;
case 0x0c063f20u: goto P_0c063f20;
case 0x0c063f22u: goto P_0c063f22;
case 0x0c063f24u: goto P_0c063f24;
case 0x0c063f26u: goto P_0c063f26;
case 0x0c063f28u: goto P_0c063f28;
case 0x0c063f2au: goto P_0c063f2a;
case 0x0c063f2cu: goto P_0c063f2c;
case 0x0c063f2eu: goto P_0c063f2e;
case 0x0c063f30u: goto P_0c063f30;
case 0x0c063f32u: goto P_0c063f32;
case 0x0c063f34u: goto P_0c063f34;
case 0x0c063f36u: goto P_0c063f36;
case 0x0c063f38u: goto P_0c063f38;
case 0x0c063f3au: goto P_0c063f3a;
case 0x0c063f3cu: goto P_0c063f3c;
case 0x0c063f3eu: goto P_0c063f3e;
case 0x0c063f40u: goto P_0c063f40;
case 0x0c063f42u: goto P_0c063f42;
case 0x0c063f44u: goto P_0c063f44;
case 0x0c063f46u: goto P_0c063f46;
case 0x0c063f48u: goto P_0c063f48;
case 0x0c063f4au: goto P_0c063f4a;
case 0x0c063f4cu: goto P_0c063f4c;
case 0x0c063f4eu: goto P_0c063f4e;
case 0x0c063f50u: goto P_0c063f50;
case 0x0c063f52u: goto P_0c063f52;
case 0x0c063f54u: goto P_0c063f54;
case 0x0c063f56u: goto P_0c063f56;
case 0x0c063f58u: goto P_0c063f58;
case 0x0c063f5au: goto P_0c063f5a;
case 0x0c063f5cu: goto P_0c063f5c;
case 0x0c063f5eu: goto P_0c063f5e;
case 0x0c063f60u: goto P_0c063f60;
case 0x0c063f62u: goto P_0c063f62;
case 0x0c063f64u: goto P_0c063f64;
case 0x0c063f66u: goto P_0c063f66;
case 0x0c063f68u: goto P_0c063f68;
case 0x0c063f6au: goto P_0c063f6a;
case 0x0c063f6cu: goto P_0c063f6c;
case 0x0c063f6eu: goto P_0c063f6e;
case 0x0c063f70u: goto P_0c063f70;
case 0x0c063f72u: goto P_0c063f72;
case 0x0c063f74u: goto P_0c063f74;
case 0x0c063f76u: goto P_0c063f76;
case 0x0c063f78u: goto P_0c063f78;
case 0x0c063f7au: goto P_0c063f7a;
case 0x0c063f7cu: goto P_0c063f7c;
case 0x0c063f7eu: goto P_0c063f7e;
case 0x0c063f80u: goto P_0c063f80;
case 0x0c063f82u: goto P_0c063f82;
case 0x0c063f84u: goto P_0c063f84;
default: return vf3_matrix_family(target,s,ram);
}
P_0c063af6: /* original 2fe6, guest PC 0x0c063af6 */
if(!s->budget--) { s->failed_pc=0x0c063af6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063af8;
P_0c063af8: /* original 2fd6, guest PC 0x0c063af8 */
if(!s->budget--) { s->failed_pc=0x0c063af8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063afa;
P_0c063afa: /* original ee01, guest PC 0x0c063afa */
if(!s->budget--) { s->failed_pc=0x0c063afau; return 0; }
r[14]=0x00000001u;
goto P_0c063afc;
P_0c063afc: /* original 2fc6, guest PC 0x0c063afc */
if(!s->budget--) { s->failed_pc=0x0c063afcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063afe;
P_0c063afe: /* original ed00, guest PC 0x0c063afe */
if(!s->budget--) { s->failed_pc=0x0c063afeu; return 0; }
r[13]=0x00000000u;
goto P_0c063b00;
P_0c063b00: /* original 2fb6, guest PC 0x0c063b00 */
if(!s->budget--) { s->failed_pc=0x0c063b00u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063b02;
P_0c063b02: /* original eb04, guest PC 0x0c063b02 */
if(!s->budget--) { s->failed_pc=0x0c063b02u; return 0; }
r[11]=0x00000004u;
goto P_0c063b04;
P_0c063b04: /* original 2fa6, guest PC 0x0c063b04 */
if(!s->budget--) { s->failed_pc=0x0c063b04u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063b06;
P_0c063b06: /* original 6ad3, guest PC 0x0c063b06 */
if(!s->budget--) { s->failed_pc=0x0c063b06u; return 0; }
r[10]=r[13];
goto P_0c063b08;
P_0c063b08: /* original 2f96, guest PC 0x0c063b08 */
if(!s->budget--) { s->failed_pc=0x0c063b08u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063b0a;
P_0c063b0a: /* original 2f86, guest PC 0x0c063b0a */
if(!s->budget--) { s->failed_pc=0x0c063b0au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063b0c;
P_0c063b0c: /* original 4f22, guest PC 0x0c063b0c */
if(!s->budget--) { s->failed_pc=0x0c063b0cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c063b0e;
P_0c063b0e: /* original 7ffc, guest PC 0x0c063b0e */
if(!s->budget--) { s->failed_pc=0x0c063b0eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c063b10;
P_0c063b10: /* original d85a, guest PC 0x0c063b10 */
if(!s->budget--) { s->failed_pc=0x0c063b10u; return 0; }
r[8]=read(ram,0x0c063c7cu,4);
goto P_0c063b12;
P_0c063b12: /* original 6983, guest PC 0x0c063b12 */
if(!s->budget--) { s->failed_pc=0x0c063b12u; return 0; }
r[9]=r[8];
goto P_0c063b14;
P_0c063b14: /* original 7958, guest PC 0x0c063b14 */
if(!s->budget--) { s->failed_pc=0x0c063b14u; return 0; }
r[9]+=0x00000058u;
goto P_0c063b16;
P_0c063b16: /* original 60d3, guest PC 0x0c063b16 */
if(!s->budget--) { s->failed_pc=0x0c063b16u; return 0; }
r[0]=r[13];
goto P_0c063b18;
P_0c063b18: /* original 0009, guest PC 0x0c063b18 */
if(!s->budget--) { s->failed_pc=0x0c063b18u; return 0; }
goto P_0c063b1a;
P_0c063b1a: /* original 4008, guest PC 0x0c063b1a */
if(!s->budget--) { s->failed_pc=0x0c063b1au; return 0; }
r[0]<<=2;
goto P_0c063b1c;
P_0c063b1c: /* original d158, guest PC 0x0c063b1c */
if(!s->budget--) { s->failed_pc=0x0c063b1cu; return 0; }
r[1]=read(ram,0x0c063c80u,4);
goto P_0c063b1e;
P_0c063b1e: /* original 001e, guest PC 0x0c063b1e */
if(!s->budget--) { s->failed_pc=0x0c063b1eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c063b20;
P_0c063b20: /* original 8803, guest PC 0x0c063b20 */
if(!s->budget--) { s->failed_pc=0x0c063b20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c063b22;
P_0c063b22: /* original 8901, guest PC 0x0c063b22 */
if(!s->budget--) { s->failed_pc=0x0c063b22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063b28; }
goto P_0c063b24;
P_0c063b24: /* original a0ec, guest PC 0x0c063b24 */
if(!s->budget--) { s->failed_pc=0x0c063b24u; return 0; }
goto P_0c063d00;
P_0c063b26: /* original 0009, guest PC 0x0c063b26 */
if(!s->budget--) { s->failed_pc=0x0c063b26u; return 0; }
goto P_0c063b28;
P_0c063b28: /* original d356, guest PC 0x0c063b28 */
if(!s->budget--) { s->failed_pc=0x0c063b28u; return 0; }
r[3]=read(ram,0x0c063c84u,4);
goto P_0c063b2a;
P_0c063b2a: /* original 6232, guest PC 0x0c063b2a */
if(!s->budget--) { s->failed_pc=0x0c063b2au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c063b2c;
P_0c063b2c: /* original 2228, guest PC 0x0c063b2c */
if(!s->budget--) { s->failed_pc=0x0c063b2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c063b2e;
P_0c063b2e: /* original 8901, guest PC 0x0c063b2e */
if(!s->budget--) { s->failed_pc=0x0c063b2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063b34; }
goto P_0c063b30;
P_0c063b30: /* original a0e6, guest PC 0x0c063b30 */
if(!s->budget--) { s->failed_pc=0x0c063b30u; return 0; }
goto P_0c063d00;
P_0c063b32: /* original 0009, guest PC 0x0c063b32 */
if(!s->budget--) { s->failed_pc=0x0c063b32u; return 0; }
goto P_0c063b34;
P_0c063b34: /* original d154, guest PC 0x0c063b34 */
if(!s->budget--) { s->failed_pc=0x0c063b34u; return 0; }
r[1]=read(ram,0x0c063c88u,4);
goto P_0c063b36;
P_0c063b36: /* original 6cd3, guest PC 0x0c063b36 */
if(!s->budget--) { s->failed_pc=0x0c063b36u; return 0; }
r[12]=r[13];
goto P_0c063b38;
P_0c063b38: /* original 2ce9, guest PC 0x0c063b38 */
if(!s->budget--) { s->failed_pc=0x0c063b38u; return 0; }
r[12]&=r[14];
goto P_0c063b3a;
P_0c063b3a: /* original 62c3, guest PC 0x0c063b3a */
if(!s->budget--) { s->failed_pc=0x0c063b3au; return 0; }
r[2]=r[12];
goto P_0c063b3c;
P_0c063b3c: /* original 7201, guest PC 0x0c063b3c */
if(!s->budget--) { s->failed_pc=0x0c063b3cu; return 0; }
r[2]+=0x00000001u;
goto P_0c063b3e;
P_0c063b3e: /* original 2f22, guest PC 0x0c063b3e */
if(!s->budget--) { s->failed_pc=0x0c063b3eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c063b40;
P_0c063b40: /* original 6312, guest PC 0x0c063b40 */
if(!s->budget--) { s->failed_pc=0x0c063b40u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c063b42;
P_0c063b42: /* original 2238, guest PC 0x0c063b42 */
if(!s->budget--) { s->failed_pc=0x0c063b42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c063b44;
P_0c063b44: /* original 8916, guest PC 0x0c063b44 */
if(!s->budget--) { s->failed_pc=0x0c063b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063b74; }
goto P_0c063b46;
P_0c063b46: /* original d051, guest PC 0x0c063b46 */
if(!s->budget--) { s->failed_pc=0x0c063b46u; return 0; }
r[0]=read(ram,0x0c063c8cu,4);
goto P_0c063b48;
P_0c063b48: /* original 6302, guest PC 0x0c063b48 */
if(!s->budget--) { s->failed_pc=0x0c063b48u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c063b4a;
P_0c063b4a: /* original 6337, guest PC 0x0c063b4a */
if(!s->budget--) { s->failed_pc=0x0c063b4au; return 0; }
r[3]=~r[3];
goto P_0c063b4c;
P_0c063b4c: /* original 23e9, guest PC 0x0c063b4c */
if(!s->budget--) { s->failed_pc=0x0c063b4cu; return 0; }
r[3]&=r[14];
goto P_0c063b4e;
P_0c063b4e: /* original e701, guest PC 0x0c063b4e */
if(!s->budget--) { s->failed_pc=0x0c063b4eu; return 0; }
r[7]=0x00000001u;
goto P_0c063b50;
P_0c063b50: /* original 2f36, guest PC 0x0c063b50 */
if(!s->budget--) { s->failed_pc=0x0c063b50u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063b52;
P_0c063b52: /* original e600, guest PC 0x0c063b52 */
if(!s->budget--) { s->failed_pc=0x0c063b52u; return 0; }
r[6]=0x00000000u;
goto P_0c063b54;
P_0c063b54: /* original 2fc6, guest PC 0x0c063b54 */
if(!s->budget--) { s->failed_pc=0x0c063b54u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063b56;
P_0c063b56: /* original d34e, guest PC 0x0c063b56 */
if(!s->budget--) { s->failed_pc=0x0c063b56u; return 0; }
r[3]=read(ram,0x0c063c90u,4);
goto P_0c063b58;
P_0c063b58: /* original 6532, guest PC 0x0c063b58 */
if(!s->budget--) { s->failed_pc=0x0c063b58u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c063b5a;
P_0c063b5a: /* original d24e, guest PC 0x0c063b5a */
if(!s->budget--) { s->failed_pc=0x0c063b5au; return 0; }
r[2]=read(ram,0x0c063c94u,4);
goto P_0c063b5c;
P_0c063b5c: /* original d34e, guest PC 0x0c063b5c */
if(!s->budget--) { s->failed_pc=0x0c063b5cu; return 0; }
r[3]=read(ram,0x0c063c98u,4);
goto P_0c063b5e;
P_0c063b5e: /* original 430b, guest PC 0x0c063b5e */
if(!s->budget--) { s->failed_pc=0x0c063b5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c063b62u;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063b62u) { target=s->pc; goto dispatch; }
goto P_0c063b62;
P_0c063b60: /* original 6422, guest PC 0x0c063b60 */
if(!s->budget--) { s->failed_pc=0x0c063b60u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c063b62;
P_0c063b62: /* original 7f08, guest PC 0x0c063b62 */
if(!s->budget--) { s->failed_pc=0x0c063b62u; return 0; }
r[15]+=0x00000008u;
goto P_0c063b64;
P_0c063b64: /* original d248, guest PC 0x0c063b64 */
if(!s->budget--) { s->failed_pc=0x0c063b64u; return 0; }
r[2]=read(ram,0x0c063c88u,4);
goto P_0c063b66;
P_0c063b66: /* original 60f2, guest PC 0x0c063b66 */
if(!s->budget--) { s->failed_pc=0x0c063b66u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c063b68;
P_0c063b68: /* original 6007, guest PC 0x0c063b68 */
if(!s->budget--) { s->failed_pc=0x0c063b68u; return 0; }
r[0]=~r[0];
goto P_0c063b6a;
P_0c063b6a: /* original 6322, guest PC 0x0c063b6a */
if(!s->budget--) { s->failed_pc=0x0c063b6au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c063b6c;
P_0c063b6c: /* original 2039, guest PC 0x0c063b6c */
if(!s->budget--) { s->failed_pc=0x0c063b6cu; return 0; }
r[0]&=r[3];
goto P_0c063b6e;
P_0c063b6e: /* original c903, guest PC 0x0c063b6e */
if(!s->budget--) { s->failed_pc=0x0c063b6eu; return 0; }
r[0]&=3u;
goto P_0c063b70;
P_0c063b70: /* original 6323, guest PC 0x0c063b70 */
if(!s->budget--) { s->failed_pc=0x0c063b70u; return 0; }
r[3]=r[2];
goto P_0c063b72;
P_0c063b72: /* original 2302, guest PC 0x0c063b72 */
if(!s->budget--) { s->failed_pc=0x0c063b72u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c063b74;
P_0c063b74: /* original d243, guest PC 0x0c063b74 */
if(!s->budget--) { s->failed_pc=0x0c063b74u; return 0; }
r[2]=read(ram,0x0c063c84u,4);
goto P_0c063b76;
P_0c063b76: /* original 22e2, guest PC 0x0c063b76 */
if(!s->budget--) { s->failed_pc=0x0c063b76u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c063b78;
P_0c063b78: /* original d041, guest PC 0x0c063b78 */
if(!s->budget--) { s->failed_pc=0x0c063b78u; return 0; }
r[0]=read(ram,0x0c063c80u,4);
goto P_0c063b7a;
P_0c063b7a: /* original 63d3, guest PC 0x0c063b7a */
if(!s->budget--) { s->failed_pc=0x0c063b7au; return 0; }
r[3]=r[13];
goto P_0c063b7c;
P_0c063b7c: /* original 4308, guest PC 0x0c063b7c */
if(!s->budget--) { s->failed_pc=0x0c063b7cu; return 0; }
r[3]<<=2;
goto P_0c063b7e;
P_0c063b7e: /* original 03b6, guest PC 0x0c063b7e */
if(!s->budget--) { s->failed_pc=0x0c063b7eu; return 0; }
write(ram,r[3]+r[0],r[11],4);
goto P_0c063b80;
P_0c063b80: /* original d146, guest PC 0x0c063b80 */
if(!s->budget--) { s->failed_pc=0x0c063b80u; return 0; }
r[1]=read(ram,0x0c063c9cu,4);
goto P_0c063b82;
P_0c063b82: /* original 6012, guest PC 0x0c063b82 */
if(!s->budget--) { s->failed_pc=0x0c063b82u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c063b84;
P_0c063b84: /* original c810, guest PC 0x0c063b84 */
if(!s->budget--) { s->failed_pc=0x0c063b84u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c063b86;
P_0c063b86: /* original 8d03, guest PC 0x0c063b86 */
if(!s->budget--) { s->failed_pc=0x0c063b86u; return 0; }
cond=r[17]&1u;
r[4]=r[12];
if(cond) { goto P_0c063b90; }
goto P_0c063b8a;
P_0c063b88: /* original 64c3, guest PC 0x0c063b88 */
if(!s->budget--) { s->failed_pc=0x0c063b88u; return 0; }
r[4]=r[12];
goto P_0c063b8a;
P_0c063b8a: /* original e302, guest PC 0x0c063b8a */
if(!s->budget--) { s->failed_pc=0x0c063b8au; return 0; }
r[3]=0x00000002u;
goto P_0c063b8c;
P_0c063b8c: /* original 2832, guest PC 0x0c063b8c */
if(!s->budget--) { s->failed_pc=0x0c063b8cu; return 0; }
write(ram,r[8],r[3],4);
goto P_0c063b8e;
P_0c063b8e: /* original 28a2, guest PC 0x0c063b8e */
if(!s->budget--) { s->failed_pc=0x0c063b8eu; return 0; }
write(ram,r[8],r[10],4);
goto P_0c063b90;
P_0c063b90: /* original d043, guest PC 0x0c063b90 */
if(!s->budget--) { s->failed_pc=0x0c063b90u; return 0; }
r[0]=read(ram,0x0c063ca0u,4);
goto P_0c063b92;
P_0c063b92: /* original 4408, guest PC 0x0c063b92 */
if(!s->budget--) { s->failed_pc=0x0c063b92u; return 0; }
r[4]<<=2;
goto P_0c063b94;
P_0c063b94: /* original 4408, guest PC 0x0c063b94 */
if(!s->budget--) { s->failed_pc=0x0c063b94u; return 0; }
r[4]<<=2;
goto P_0c063b96;
P_0c063b96: /* original 4400, guest PC 0x0c063b96 */
if(!s->budget--) { s->failed_pc=0x0c063b96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c063b98;
P_0c063b98: /* original 024e, guest PC 0x0c063b98 */
if(!s->budget--) { s->failed_pc=0x0c063b98u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c063b9a;
P_0c063b9a: /* original d342, guest PC 0x0c063b9a */
if(!s->budget--) { s->failed_pc=0x0c063b9au; return 0; }
r[3]=read(ram,0x0c063ca4u,4);
goto P_0c063b9c;
P_0c063b9c: /* original 2322, guest PC 0x0c063b9c */
if(!s->budget--) { s->failed_pc=0x0c063b9cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063b9e;
P_0c063b9e: /* original 7014, guest PC 0x0c063b9e */
if(!s->budget--) { s->failed_pc=0x0c063b9eu; return 0; }
r[0]+=0x00000014u;
goto P_0c063ba0;
P_0c063ba0: /* original 014e, guest PC 0x0c063ba0 */
if(!s->budget--) { s->failed_pc=0x0c063ba0u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c063ba2;
P_0c063ba2: /* original d241, guest PC 0x0c063ba2 */
if(!s->budget--) { s->failed_pc=0x0c063ba2u; return 0; }
r[2]=read(ram,0x0c063ca8u,4);
goto P_0c063ba4;
P_0c063ba4: /* original 2212, guest PC 0x0c063ba4 */
if(!s->budget--) { s->failed_pc=0x0c063ba4u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c063ba6;
P_0c063ba6: /* original d341, guest PC 0x0c063ba6 */
if(!s->budget--) { s->failed_pc=0x0c063ba6u; return 0; }
r[3]=read(ram,0x0c063cacu,4);
goto P_0c063ba8;
P_0c063ba8: /* original 6032, guest PC 0x0c063ba8 */
if(!s->budget--) { s->failed_pc=0x0c063ba8u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063baa;
P_0c063baa: /* original 8801, guest PC 0x0c063baa */
if(!s->budget--) { s->failed_pc=0x0c063baau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063bac;
P_0c063bac: /* original 8915, guest PC 0x0c063bac */
if(!s->budget--) { s->failed_pc=0x0c063bacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063bda; }
goto P_0c063bae;
P_0c063bae: /* original d140, guest PC 0x0c063bae */
if(!s->budget--) { s->failed_pc=0x0c063baeu; return 0; }
r[1]=read(ram,0x0c063cb0u,4);
goto P_0c063bb0;
P_0c063bb0: /* original 6012, guest PC 0x0c063bb0 */
if(!s->budget--) { s->failed_pc=0x0c063bb0u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c063bb2;
P_0c063bb2: /* original 20e9, guest PC 0x0c063bb2 */
if(!s->budget--) { s->failed_pc=0x0c063bb2u; return 0; }
r[0]&=r[14];
goto P_0c063bb4;
P_0c063bb4: /* original 8801, guest PC 0x0c063bb4 */
if(!s->budget--) { s->failed_pc=0x0c063bb4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063bb6;
P_0c063bb6: /* original 890c, guest PC 0x0c063bb6 */
if(!s->budget--) { s->failed_pc=0x0c063bb6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063bd2; }
goto P_0c063bb8;
P_0c063bb8: /* original d23d, guest PC 0x0c063bb8 */
if(!s->budget--) { s->failed_pc=0x0c063bb8u; return 0; }
r[2]=read(ram,0x0c063cb0u,4);
goto P_0c063bba;
P_0c063bba: /* original 6022, guest PC 0x0c063bba */
if(!s->budget--) { s->failed_pc=0x0c063bbau; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063bbc;
P_0c063bbc: /* original c92c, guest PC 0x0c063bbc */
if(!s->budget--) { s->failed_pc=0x0c063bbcu; return 0; }
r[0]&=44u;
goto P_0c063bbe;
P_0c063bbe: /* original 8820, guest PC 0x0c063bbe */
if(!s->budget--) { s->failed_pc=0x0c063bbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c063bc0;
P_0c063bc0: /* original 8b07, guest PC 0x0c063bc0 */
if(!s->budget--) { s->failed_pc=0x0c063bc0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063bd2; }
goto P_0c063bc2;
P_0c063bc2: /* original 2ee8, guest PC 0x0c063bc2 */
if(!s->budget--) { s->failed_pc=0x0c063bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c063bc4;
P_0c063bc4: /* original 8905, guest PC 0x0c063bc4 */
if(!s->budget--) { s->failed_pc=0x0c063bc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063bd2; }
goto P_0c063bc6;
P_0c063bc6: /* original d03b, guest PC 0x0c063bc6 */
if(!s->budget--) { s->failed_pc=0x0c063bc6u; return 0; }
r[0]=read(ram,0x0c063cb4u,4);
goto P_0c063bc8;
P_0c063bc8: /* original d23b, guest PC 0x0c063bc8 */
if(!s->budget--) { s->failed_pc=0x0c063bc8u; return 0; }
r[2]=read(ram,0x0c063cb8u,4);
goto P_0c063bca;
P_0c063bca: /* original 6322, guest PC 0x0c063bca */
if(!s->budget--) { s->failed_pc=0x0c063bcau; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c063bcc;
P_0c063bcc: /* original 4308, guest PC 0x0c063bcc */
if(!s->budget--) { s->failed_pc=0x0c063bccu; return 0; }
r[3]<<=2;
goto P_0c063bce;
P_0c063bce: /* original a003, guest PC 0x0c063bce */
if(!s->budget--) { s->failed_pc=0x0c063bceu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c063bd8;
P_0c063bd0: /* original 033e, guest PC 0x0c063bd0 */
if(!s->budget--) { s->failed_pc=0x0c063bd0u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c063bd2;
P_0c063bd2: /* original 4c08, guest PC 0x0c063bd2 */
if(!s->budget--) { s->failed_pc=0x0c063bd2u; return 0; }
r[12]<<=2;
goto P_0c063bd4;
P_0c063bd4: /* original d037, guest PC 0x0c063bd4 */
if(!s->budget--) { s->failed_pc=0x0c063bd4u; return 0; }
r[0]=read(ram,0x0c063cb4u,4);
goto P_0c063bd6;
P_0c063bd6: /* original 03ce, guest PC 0x0c063bd6 */
if(!s->budget--) { s->failed_pc=0x0c063bd6u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c063bd8;
P_0c063bd8: /* original 2932, guest PC 0x0c063bd8 */
if(!s->budget--) { s->failed_pc=0x0c063bd8u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c063bda;
P_0c063bda: /* original d138, guest PC 0x0c063bda */
if(!s->budget--) { s->failed_pc=0x0c063bdau; return 0; }
r[1]=read(ram,0x0c063cbcu,4);
goto P_0c063bdc;
P_0c063bdc: /* original 6212, guest PC 0x0c063bdc */
if(!s->budget--) { s->failed_pc=0x0c063bdcu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c063bde;
P_0c063bde: /* original d038, guest PC 0x0c063bde */
if(!s->budget--) { s->failed_pc=0x0c063bdeu; return 0; }
r[0]=read(ram,0x0c063cc0u,4);
goto P_0c063be0;
P_0c063be0: /* original 2022, guest PC 0x0c063be0 */
if(!s->budget--) { s->failed_pc=0x0c063be0u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c063be2;
P_0c063be2: /* original e3f0, guest PC 0x0c063be2 */
if(!s->budget--) { s->failed_pc=0x0c063be2u; return 0; }
r[3]=0xfffffff0u;
goto P_0c063be4;
P_0c063be4: /* original 71fc, guest PC 0x0c063be4 */
if(!s->budget--) { s->failed_pc=0x0c063be4u; return 0; }
r[1]+=0xfffffffcu;
goto P_0c063be6;
P_0c063be6: /* original 6212, guest PC 0x0c063be6 */
if(!s->budget--) { s->failed_pc=0x0c063be6u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c063be8;
P_0c063be8: /* original 2239, guest PC 0x0c063be8 */
if(!s->budget--) { s->failed_pc=0x0c063be8u; return 0; }
r[2]&=r[3];
goto P_0c063bea;
P_0c063bea: /* original 70fc, guest PC 0x0c063bea */
if(!s->budget--) { s->failed_pc=0x0c063beau; return 0; }
r[0]+=0xfffffffcu;
goto P_0c063bec;
P_0c063bec: /* original 2022, guest PC 0x0c063bec */
if(!s->budget--) { s->failed_pc=0x0c063becu; return 0; }
write(ram,r[0],r[2],4);
goto P_0c063bee;
P_0c063bee: /* original d235, guest PC 0x0c063bee */
if(!s->budget--) { s->failed_pc=0x0c063beeu; return 0; }
r[2]=read(ram,0x0c063cc4u,4);
goto P_0c063bf0;
P_0c063bf0: /* original 6122, guest PC 0x0c063bf0 */
if(!s->budget--) { s->failed_pc=0x0c063bf0u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063bf2;
P_0c063bf2: /* original d335, guest PC 0x0c063bf2 */
if(!s->budget--) { s->failed_pc=0x0c063bf2u; return 0; }
r[3]=read(ram,0x0c063cc8u,4);
goto P_0c063bf4;
P_0c063bf4: /* original 2312, guest PC 0x0c063bf4 */
if(!s->budget--) { s->failed_pc=0x0c063bf4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c063bf6;
P_0c063bf6: /* original d135, guest PC 0x0c063bf6 */
if(!s->budget--) { s->failed_pc=0x0c063bf6u; return 0; }
r[1]=read(ram,0x0c063cccu,4);
goto P_0c063bf8;
P_0c063bf8: /* original 6012, guest PC 0x0c063bf8 */
if(!s->budget--) { s->failed_pc=0x0c063bf8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c063bfa;
P_0c063bfa: /* original 7304, guest PC 0x0c063bfa */
if(!s->budget--) { s->failed_pc=0x0c063bfau; return 0; }
r[3]+=0x00000004u;
goto P_0c063bfc;
P_0c063bfc: /* original 2302, guest PC 0x0c063bfc */
if(!s->budget--) { s->failed_pc=0x0c063bfcu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c063bfe;
P_0c063bfe: /* original d034, guest PC 0x0c063bfe */
if(!s->budget--) { s->failed_pc=0x0c063bfeu; return 0; }
r[0]=read(ram,0x0c063cd0u,4);
goto P_0c063c00;
P_0c063c00: /* original 6202, guest PC 0x0c063c00 */
if(!s->budget--) { s->failed_pc=0x0c063c00u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c063c02;
P_0c063c02: /* original 73e0, guest PC 0x0c063c02 */
if(!s->budget--) { s->failed_pc=0x0c063c02u; return 0; }
r[3]+=0xffffffe0u;
goto P_0c063c04;
P_0c063c04: /* original 2322, guest PC 0x0c063c04 */
if(!s->budget--) { s->failed_pc=0x0c063c04u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063c06;
P_0c063c06: /* original d233, guest PC 0x0c063c06 */
if(!s->budget--) { s->failed_pc=0x0c063c06u; return 0; }
r[2]=read(ram,0x0c063cd4u,4);
goto P_0c063c08;
P_0c063c08: /* original 6122, guest PC 0x0c063c08 */
if(!s->budget--) { s->failed_pc=0x0c063c08u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063c0a;
P_0c063c0a: /* original 73fc, guest PC 0x0c063c0a */
if(!s->budget--) { s->failed_pc=0x0c063c0au; return 0; }
r[3]+=0xfffffffcu;
goto P_0c063c0c;
P_0c063c0c: /* original 2312, guest PC 0x0c063c0c */
if(!s->budget--) { s->failed_pc=0x0c063c0cu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c063c0e;
P_0c063c0e: /* original e3ed, guest PC 0x0c063c0e */
if(!s->budget--) { s->failed_pc=0x0c063c0eu; return 0; }
r[3]=0xffffffedu;
goto P_0c063c10;
P_0c063c10: /* original d127, guest PC 0x0c063c10 */
if(!s->budget--) { s->failed_pc=0x0c063c10u; return 0; }
r[1]=read(ram,0x0c063cb0u,4);
goto P_0c063c12;
P_0c063c12: /* original d031, guest PC 0x0c063c12 */
if(!s->budget--) { s->failed_pc=0x0c063c12u; return 0; }
r[0]=read(ram,0x0c063cd8u,4);
goto P_0c063c14;
P_0c063c14: /* original 20a2, guest PC 0x0c063c14 */
if(!s->budget--) { s->failed_pc=0x0c063c14u; return 0; }
write(ram,r[0],r[10],4);
goto P_0c063c16;
P_0c063c16: /* original 6012, guest PC 0x0c063c16 */
if(!s->budget--) { s->failed_pc=0x0c063c16u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c063c18;
P_0c063c18: /* original 2039, guest PC 0x0c063c18 */
if(!s->budget--) { s->failed_pc=0x0c063c18u; return 0; }
r[0]&=r[3];
goto P_0c063c1a;
P_0c063c1a: /* original 8820, guest PC 0x0c063c1a */
if(!s->budget--) { s->failed_pc=0x0c063c1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c063c1c;
P_0c063c1c: /* original 8b0e, guest PC 0x0c063c1c */
if(!s->budget--) { s->failed_pc=0x0c063c1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063c3c; }
goto P_0c063c1e;
P_0c063c1e: /* original d226, guest PC 0x0c063c1e */
if(!s->budget--) { s->failed_pc=0x0c063c1eu; return 0; }
r[2]=read(ram,0x0c063cb8u,4);
goto P_0c063c20;
P_0c063c20: /* original 6122, guest PC 0x0c063c20 */
if(!s->budget--) { s->failed_pc=0x0c063c20u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063c22;
P_0c063c22: /* original 2118, guest PC 0x0c063c22 */
if(!s->budget--) { s->failed_pc=0x0c063c22u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c063c24;
P_0c063c24: /* original 8b04, guest PC 0x0c063c24 */
if(!s->budget--) { s->failed_pc=0x0c063c24u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063c30; }
goto P_0c063c26;
P_0c063c26: /* original d12d, guest PC 0x0c063c26 */
if(!s->budget--) { s->failed_pc=0x0c063c26u; return 0; }
r[1]=read(ram,0x0c063cdcu,4);
goto P_0c063c28;
P_0c063c28: /* original d32d, guest PC 0x0c063c28 */
if(!s->budget--) { s->failed_pc=0x0c063c28u; return 0; }
r[3]=read(ram,0x0c063ce0u,4);
goto P_0c063c2a;
P_0c063c2a: /* original 6032, guest PC 0x0c063c2a */
if(!s->budget--) { s->failed_pc=0x0c063c2au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063c2c;
P_0c063c2c: /* original a003, guest PC 0x0c063c2c */
if(!s->budget--) { s->failed_pc=0x0c063c2cu; return 0; }
goto P_0c063c36;
P_0c063c2e: /* original 0009, guest PC 0x0c063c2e */
if(!s->budget--) { s->failed_pc=0x0c063c2eu; return 0; }
goto P_0c063c30;
P_0c063c30: /* original d12c, guest PC 0x0c063c30 */
if(!s->budget--) { s->failed_pc=0x0c063c30u; return 0; }
r[1]=read(ram,0x0c063ce4u,4);
goto P_0c063c32;
P_0c063c32: /* original d32b, guest PC 0x0c063c32 */
if(!s->budget--) { s->failed_pc=0x0c063c32u; return 0; }
r[3]=read(ram,0x0c063ce0u,4);
goto P_0c063c34;
P_0c063c34: /* original 6032, guest PC 0x0c063c34 */
if(!s->budget--) { s->failed_pc=0x0c063c34u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063c36;
P_0c063c36: /* original 201b, guest PC 0x0c063c36 */
if(!s->budget--) { s->failed_pc=0x0c063c36u; return 0; }
r[0]|=r[1];
goto P_0c063c38;
P_0c063c38: /* original d22b, guest PC 0x0c063c38 */
if(!s->budget--) { s->failed_pc=0x0c063c38u; return 0; }
r[2]=read(ram,0x0c063ce8u,4);
goto P_0c063c3a;
P_0c063c3a: /* original 2202, guest PC 0x0c063c3a */
if(!s->budget--) { s->failed_pc=0x0c063c3au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c063c3c;
P_0c063c3c: /* original d12b, guest PC 0x0c063c3c */
if(!s->budget--) { s->failed_pc=0x0c063c3cu; return 0; }
r[1]=read(ram,0x0c063cecu,4);
goto P_0c063c3e;
P_0c063c3e: /* original 6312, guest PC 0x0c063c3e */
if(!s->budget--) { s->failed_pc=0x0c063c3eu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c063c40;
P_0c063c40: /* original d22b, guest PC 0x0c063c40 */
if(!s->budget--) { s->failed_pc=0x0c063c40u; return 0; }
r[2]=read(ram,0x0c063cf0u,4);
goto P_0c063c42;
P_0c063c42: /* original 2232, guest PC 0x0c063c42 */
if(!s->budget--) { s->failed_pc=0x0c063c42u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c063c44;
P_0c063c44: /* original d02b, guest PC 0x0c063c44 */
if(!s->budget--) { s->failed_pc=0x0c063c44u; return 0; }
r[0]=read(ram,0x0c063cf4u,4);
goto P_0c063c46;
P_0c063c46: /* original 20d2, guest PC 0x0c063c46 */
if(!s->budget--) { s->failed_pc=0x0c063c46u; return 0; }
write(ram,r[0],r[13],4);
goto P_0c063c48;
P_0c063c48: /* original d32b, guest PC 0x0c063c48 */
if(!s->budget--) { s->failed_pc=0x0c063c48u; return 0; }
r[3]=read(ram,0x0c063cf8u,4);
goto P_0c063c4a;
P_0c063c4a: /* original e2ff, guest PC 0x0c063c4a */
if(!s->budget--) { s->failed_pc=0x0c063c4au; return 0; }
r[2]=0xffffffffu;
goto P_0c063c4c;
P_0c063c4c: /* original d12b, guest PC 0x0c063c4c */
if(!s->budget--) { s->failed_pc=0x0c063c4cu; return 0; }
r[1]=read(ram,0x0c063cfcu,4);
goto P_0c063c4e;
P_0c063c4e: /* original 23e2, guest PC 0x0c063c4e */
if(!s->budget--) { s->failed_pc=0x0c063c4eu; return 0; }
write(ram,r[3],r[14],4);
goto P_0c063c50;
P_0c063c50: /* original a05b, guest PC 0x0c063c50 */
if(!s->budget--) { s->failed_pc=0x0c063c50u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c063d0a;
P_0c063c52: /* original 2122, guest PC 0x0c063c52 */
if(!s->budget--) { s->failed_pc=0x0c063c52u; return 0; }
write(ram,r[1],r[2],4);
if(!vf3_matrix_family(0x0c063c54u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c063c54u; return 0; } return 1;
P_0c063d00: /* original 7d01, guest PC 0x0c063d00 */
if(!s->budget--) { s->failed_pc=0x0c063d00u; return 0; }
r[13]+=0x00000001u;
goto P_0c063d02;
P_0c063d02: /* original 3db3, guest PC 0x0c063d02 */
if(!s->budget--) { s->failed_pc=0x0c063d02u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[11])!=0);
goto P_0c063d04;
P_0c063d04: /* original 8901, guest PC 0x0c063d04 */
if(!s->budget--) { s->failed_pc=0x0c063d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063d0a; }
goto P_0c063d06;
P_0c063d06: /* original af06, guest PC 0x0c063d06 */
if(!s->budget--) { s->failed_pc=0x0c063d06u; return 0; }
goto P_0c063b16;
P_0c063d08: /* original 0009, guest PC 0x0c063d08 */
if(!s->budget--) { s->failed_pc=0x0c063d08u; return 0; }
goto P_0c063d0a;
P_0c063d0a: /* original 7f04, guest PC 0x0c063d0a */
if(!s->budget--) { s->failed_pc=0x0c063d0au; return 0; }
r[15]+=0x00000004u;
goto P_0c063d0c;
P_0c063d0c: /* original 4f26, guest PC 0x0c063d0c */
if(!s->budget--) { s->failed_pc=0x0c063d0cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063d0e;
P_0c063d0e: /* original 68f6, guest PC 0x0c063d0e */
if(!s->budget--) { s->failed_pc=0x0c063d0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c063d10;
P_0c063d10: /* original 69f6, guest PC 0x0c063d10 */
if(!s->budget--) { s->failed_pc=0x0c063d10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c063d12;
P_0c063d12: /* original 6af6, guest PC 0x0c063d12 */
if(!s->budget--) { s->failed_pc=0x0c063d12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c063d14;
P_0c063d14: /* original 6bf6, guest PC 0x0c063d14 */
if(!s->budget--) { s->failed_pc=0x0c063d14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c063d16;
P_0c063d16: /* original 6cf6, guest PC 0x0c063d16 */
if(!s->budget--) { s->failed_pc=0x0c063d16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c063d18;
P_0c063d18: /* original 6df6, guest PC 0x0c063d18 */
if(!s->budget--) { s->failed_pc=0x0c063d18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c063d1a;
P_0c063d1a: /* original 000b, guest PC 0x0c063d1a */
if(!s->budget--) { s->failed_pc=0x0c063d1au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c063d1c: /* original 6ef6, guest PC 0x0c063d1c */
if(!s->budget--) { s->failed_pc=0x0c063d1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c063d1e;
P_0c063d1e: /* original e308, guest PC 0x0c063d1e */
if(!s->budget--) { s->failed_pc=0x0c063d1eu; return 0; }
r[3]=0x00000008u;
goto P_0c063d20;
P_0c063d20: /* original d238, guest PC 0x0c063d20 */
if(!s->budget--) { s->failed_pc=0x0c063d20u; return 0; }
r[2]=read(ram,0x0c063e04u,4);
goto P_0c063d22;
P_0c063d22: /* original 2fe6, guest PC 0x0c063d22 */
if(!s->budget--) { s->failed_pc=0x0c063d22u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d24;
P_0c063d24: /* original 2fd6, guest PC 0x0c063d24 */
if(!s->budget--) { s->failed_pc=0x0c063d24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d26;
P_0c063d26: /* original 2fc6, guest PC 0x0c063d26 */
if(!s->budget--) { s->failed_pc=0x0c063d26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d28;
P_0c063d28: /* original 2fb6, guest PC 0x0c063d28 */
if(!s->budget--) { s->failed_pc=0x0c063d28u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d2a;
P_0c063d2a: /* original eb02, guest PC 0x0c063d2a */
if(!s->budget--) { s->failed_pc=0x0c063d2au; return 0; }
r[11]=0x00000002u;
goto P_0c063d2c;
P_0c063d2c: /* original de34, guest PC 0x0c063d2c */
if(!s->budget--) { s->failed_pc=0x0c063d2cu; return 0; }
r[14]=read(ram,0x0c063e00u,4);
goto P_0c063d2e;
P_0c063d2e: /* original 2fa6, guest PC 0x0c063d2e */
if(!s->budget--) { s->failed_pc=0x0c063d2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d30;
P_0c063d30: /* original 2f96, guest PC 0x0c063d30 */
if(!s->budget--) { s->failed_pc=0x0c063d30u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d32;
P_0c063d32: /* original e904, guest PC 0x0c063d32 */
if(!s->budget--) { s->failed_pc=0x0c063d32u; return 0; }
r[9]=0x00000004u;
goto P_0c063d34;
P_0c063d34: /* original 2f86, guest PC 0x0c063d34 */
if(!s->budget--) { s->failed_pc=0x0c063d34u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c063d36;
P_0c063d36: /* original 4f22, guest PC 0x0c063d36 */
if(!s->budget--) { s->failed_pc=0x0c063d36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c063d38;
P_0c063d38: /* original 7ff0, guest PC 0x0c063d38 */
if(!s->budget--) { s->failed_pc=0x0c063d38u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c063d3a;
P_0c063d3a: /* original 2232, guest PC 0x0c063d3a */
if(!s->budget--) { s->failed_pc=0x0c063d3au; return 0; }
write(ram,r[2],r[3],4);
goto P_0c063d3c;
P_0c063d3c: /* original d332, guest PC 0x0c063d3c */
if(!s->budget--) { s->failed_pc=0x0c063d3cu; return 0; }
r[3]=read(ram,0x0c063e08u,4);
goto P_0c063d3e;
P_0c063d3e: /* original 6132, guest PC 0x0c063d3e */
if(!s->budget--) { s->failed_pc=0x0c063d3eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c063d40;
P_0c063d40: /* original 21bb, guest PC 0x0c063d40 */
if(!s->budget--) { s->failed_pc=0x0c063d40u; return 0; }
r[1]|=r[11];
goto P_0c063d42;
P_0c063d42: /* original 2312, guest PC 0x0c063d42 */
if(!s->budget--) { s->failed_pc=0x0c063d42u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c063d44;
P_0c063d44: /* original d331, guest PC 0x0c063d44 */
if(!s->budget--) { s->failed_pc=0x0c063d44u; return 0; }
r[3]=read(ram,0x0c063e0cu,4);
goto P_0c063d46;
P_0c063d46: /* original 6032, guest PC 0x0c063d46 */
if(!s->budget--) { s->failed_pc=0x0c063d46u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c063d48;
P_0c063d48: /* original 7001, guest PC 0x0c063d48 */
if(!s->budget--) { s->failed_pc=0x0c063d48u; return 0; }
r[0]+=0x00000001u;
goto P_0c063d4a;
P_0c063d4a: /* original 2302, guest PC 0x0c063d4a */
if(!s->budget--) { s->failed_pc=0x0c063d4au; return 0; }
write(ram,r[3],r[0],4);
goto P_0c063d4c;
P_0c063d4c: /* original d530, guest PC 0x0c063d4c */
if(!s->budget--) { s->failed_pc=0x0c063d4cu; return 0; }
r[5]=read(ram,0x0c063e10u,4);
goto P_0c063d4e;
P_0c063d4e: /* original d131, guest PC 0x0c063d4e */
if(!s->budget--) { s->failed_pc=0x0c063d4eu; return 0; }
r[1]=read(ram,0x0c063e14u,4);
goto P_0c063d50;
P_0c063d50: /* original 6312, guest PC 0x0c063d50 */
if(!s->budget--) { s->failed_pc=0x0c063d50u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c063d52;
P_0c063d52: /* original 23b8, guest PC 0x0c063d52 */
if(!s->budget--) { s->failed_pc=0x0c063d52u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c063d54;
P_0c063d54: /* original 8d07, guest PC 0x0c063d54 */
if(!s->budget--) { s->failed_pc=0x0c063d54u; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c063d66; }
goto P_0c063d58;
P_0c063d56: /* original ed00, guest PC 0x0c063d56 */
if(!s->budget--) { s->failed_pc=0x0c063d56u; return 0; }
r[13]=0x00000000u;
goto P_0c063d58;
P_0c063d58: /* original 9350, guest PC 0x0c063d58 */
if(!s->budget--) { s->failed_pc=0x0c063d58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c063dfcu,2);
goto P_0c063d5a;
P_0c063d5a: /* original d22f, guest PC 0x0c063d5a */
if(!s->budget--) { s->failed_pc=0x0c063d5au; return 0; }
r[2]=read(ram,0x0c063e18u,4);
goto P_0c063d5c;
P_0c063d5c: /* original 6022, guest PC 0x0c063d5c */
if(!s->budget--) { s->failed_pc=0x0c063d5cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063d5e;
P_0c063d5e: /* original 2039, guest PC 0x0c063d5e */
if(!s->budget--) { s->failed_pc=0x0c063d5eu; return 0; }
r[0]&=r[3];
goto P_0c063d60;
P_0c063d60: /* original 4019, guest PC 0x0c063d60 */
if(!s->budget--) { s->failed_pc=0x0c063d60u; return 0; }
r[0]>>=8;
goto P_0c063d62;
P_0c063d62: /* original a006, guest PC 0x0c063d62 */
if(!s->budget--) { s->failed_pc=0x0c063d62u; return 0; }
r[0]>>=2;
goto P_0c063d72;
P_0c063d64: /* original 4009, guest PC 0x0c063d64 */
if(!s->budget--) { s->failed_pc=0x0c063d64u; return 0; }
r[0]>>=2;
goto P_0c063d66;
P_0c063d66: /* original d42d, guest PC 0x0c063d66 */
if(!s->budget--) { s->failed_pc=0x0c063d66u; return 0; }
r[4]=read(ram,0x0c063e1cu,4);
goto P_0c063d68;
P_0c063d68: /* original 6042, guest PC 0x0c063d68 */
if(!s->budget--) { s->failed_pc=0x0c063d68u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c063d6a;
P_0c063d6a: /* original 7001, guest PC 0x0c063d6a */
if(!s->budget--) { s->failed_pc=0x0c063d6au; return 0; }
r[0]+=0x00000001u;
goto P_0c063d6c;
P_0c063d6c: /* original c901, guest PC 0x0c063d6c */
if(!s->budget--) { s->failed_pc=0x0c063d6cu; return 0; }
r[0]&=1u;
goto P_0c063d6e;
P_0c063d6e: /* original 6303, guest PC 0x0c063d6e */
if(!s->budget--) { s->failed_pc=0x0c063d6eu; return 0; }
r[3]=r[0];
goto P_0c063d70;
P_0c063d70: /* original 2402, guest PC 0x0c063d70 */
if(!s->budget--) { s->failed_pc=0x0c063d70u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c063d72;
P_0c063d72: /* original 2502, guest PC 0x0c063d72 */
if(!s->budget--) { s->failed_pc=0x0c063d72u; return 0; }
write(ram,r[5],r[0],4);
goto P_0c063d74;
P_0c063d74: /* original d22a, guest PC 0x0c063d74 */
if(!s->budget--) { s->failed_pc=0x0c063d74u; return 0; }
r[2]=read(ram,0x0c063e20u,4);
goto P_0c063d76;
P_0c063d76: /* original 6022, guest PC 0x0c063d76 */
if(!s->budget--) { s->failed_pc=0x0c063d76u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c063d78;
P_0c063d78: /* original 2099, guest PC 0x0c063d78 */
if(!s->budget--) { s->failed_pc=0x0c063d78u; return 0; }
r[0]&=r[9];
goto P_0c063d7a;
P_0c063d7a: /* original 8804, guest PC 0x0c063d7a */
if(!s->budget--) { s->failed_pc=0x0c063d7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c063d7c;
P_0c063d7c: /* original 8b04, guest PC 0x0c063d7c */
if(!s->budget--) { s->failed_pc=0x0c063d7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063d88; }
goto P_0c063d7e;
P_0c063d7e: /* original 6052, guest PC 0x0c063d7e */
if(!s->budget--) { s->failed_pc=0x0c063d7eu; return 0; }
tmp=read(ram,r[5],4);
r[0]=tmp;
goto P_0c063d80;
P_0c063d80: /* original 8801, guest PC 0x0c063d80 */
if(!s->budget--) { s->failed_pc=0x0c063d80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c063d82;
P_0c063d82: /* original 8b01, guest PC 0x0c063d82 */
if(!s->budget--) { s->failed_pc=0x0c063d82u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063d88; }
goto P_0c063d84;
P_0c063d84: /* original a010, guest PC 0x0c063d84 */
if(!s->budget--) { s->failed_pc=0x0c063d84u; return 0; }
r[5]=0x00000001u;
goto P_0c063da8;
P_0c063d86: /* original e501, guest PC 0x0c063d86 */
if(!s->budget--) { s->failed_pc=0x0c063d86u; return 0; }
r[5]=0x00000001u;
goto P_0c063d88;
P_0c063d88: /* original d326, guest PC 0x0c063d88 */
if(!s->budget--) { s->failed_pc=0x0c063d88u; return 0; }
r[3]=read(ram,0x0c063e24u,4);
goto P_0c063d8a;
P_0c063d8a: /* original 6232, guest PC 0x0c063d8a */
if(!s->budget--) { s->failed_pc=0x0c063d8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c063d8c;
P_0c063d8c: /* original 72ff, guest PC 0x0c063d8c */
if(!s->budget--) { s->failed_pc=0x0c063d8cu; return 0; }
r[2]+=0xffffffffu;
goto P_0c063d8e;
P_0c063d8e: /* original 2322, guest PC 0x0c063d8e */
if(!s->budget--) { s->failed_pc=0x0c063d8eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063d90;
P_0c063d90: /* original 6133, guest PC 0x0c063d90 */
if(!s->budget--) { s->failed_pc=0x0c063d90u; return 0; }
r[1]=r[3];
goto P_0c063d92;
P_0c063d92: /* original 6312, guest PC 0x0c063d92 */
if(!s->budget--) { s->failed_pc=0x0c063d92u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c063d94;
P_0c063d94: /* original 4311, guest PC 0x0c063d94 */
if(!s->budget--) { s->failed_pc=0x0c063d94u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c063d96;
P_0c063d96: /* original 8b01, guest PC 0x0c063d96 */
if(!s->budget--) { s->failed_pc=0x0c063d96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063d9c; }
goto P_0c063d98;
P_0c063d98: /* original a005, guest PC 0x0c063d98 */
if(!s->budget--) { s->failed_pc=0x0c063d98u; return 0; }
r[4]=0x00000001u;
goto P_0c063da6;
P_0c063d9a: /* original e401, guest PC 0x0c063d9a */
if(!s->budget--) { s->failed_pc=0x0c063d9au; return 0; }
r[4]=0x00000001u;
goto P_0c063d9c;
P_0c063d9c: /* original d322, guest PC 0x0c063d9c */
if(!s->budget--) { s->failed_pc=0x0c063d9cu; return 0; }
r[3]=read(ram,0x0c063e28u,4);
goto P_0c063d9e;
P_0c063d9e: /* original 6232, guest PC 0x0c063d9e */
if(!s->budget--) { s->failed_pc=0x0c063d9eu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c063da0;
P_0c063da0: /* original d020, guest PC 0x0c063da0 */
if(!s->budget--) { s->failed_pc=0x0c063da0u; return 0; }
r[0]=read(ram,0x0c063e24u,4);
goto P_0c063da2;
P_0c063da2: /* original 2022, guest PC 0x0c063da2 */
if(!s->budget--) { s->failed_pc=0x0c063da2u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c063da4;
P_0c063da4: /* original e400, guest PC 0x0c063da4 */
if(!s->budget--) { s->failed_pc=0x0c063da4u; return 0; }
r[4]=0x00000000u;
goto P_0c063da6;
P_0c063da6: /* original 6543, guest PC 0x0c063da6 */
if(!s->budget--) { s->failed_pc=0x0c063da6u; return 0; }
r[5]=r[4];
goto P_0c063da8;
P_0c063da8: /* original 2558, guest PC 0x0c063da8 */
if(!s->budget--) { s->failed_pc=0x0c063da8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c063daa;
P_0c063daa: /* original 8901, guest PC 0x0c063daa */
if(!s->budget--) { s->failed_pc=0x0c063daau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063db0; }
goto P_0c063dac;
P_0c063dac: /* original a0e0, guest PC 0x0c063dac */
if(!s->budget--) { s->failed_pc=0x0c063dacu; return 0; }
goto P_0c063f70;
P_0c063dae: /* original 0009, guest PC 0x0c063dae */
if(!s->budget--) { s->failed_pc=0x0c063daeu; return 0; }
goto P_0c063db0;
P_0c063db0: /* original d21e, guest PC 0x0c063db0 */
if(!s->budget--) { s->failed_pc=0x0c063db0u; return 0; }
r[2]=read(ram,0x0c063e2cu,4);
goto P_0c063db2;
P_0c063db2: /* original 6322, guest PC 0x0c063db2 */
if(!s->budget--) { s->failed_pc=0x0c063db2u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c063db4;
P_0c063db4: /* original 2338, guest PC 0x0c063db4 */
if(!s->budget--) { s->failed_pc=0x0c063db4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c063db6;
P_0c063db6: /* original 8f1f, guest PC 0x0c063db6 */
if(!s->budget--) { s->failed_pc=0x0c063db6u; return 0; }
cond=r[17]&1u;
r[8]=0x00000000u;
if(!cond) { goto P_0c063df8; }
goto P_0c063dba;
P_0c063db8: /* original e800, guest PC 0x0c063db8 */
if(!s->budget--) { s->failed_pc=0x0c063db8u; return 0; }
r[8]=0x00000000u;
goto P_0c063dba;
P_0c063dba: /* original d31d, guest PC 0x0c063dba */
if(!s->budget--) { s->failed_pc=0x0c063dbau; return 0; }
r[3]=read(ram,0x0c063e30u,4);
goto P_0c063dbc;
P_0c063dbc: /* original 6232, guest PC 0x0c063dbc */
if(!s->budget--) { s->failed_pc=0x0c063dbcu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c063dbe;
P_0c063dbe: /* original 2228, guest PC 0x0c063dbe */
if(!s->budget--) { s->failed_pc=0x0c063dbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c063dc0;
P_0c063dc0: /* original 8944, guest PC 0x0c063dc0 */
if(!s->budget--) { s->failed_pc=0x0c063dc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063e4c; }
goto P_0c063dc2;
P_0c063dc2: /* original e110, guest PC 0x0c063dc2 */
if(!s->budget--) { s->failed_pc=0x0c063dc2u; return 0; }
r[1]=0x00000010u;
goto P_0c063dc4;
P_0c063dc4: /* original 52e6, guest PC 0x0c063dc4 */
if(!s->budget--) { s->failed_pc=0x0c063dc4u; return 0; }
r[2]=read(ram,r[14]+24,4);
goto P_0c063dc6;
P_0c063dc6: /* original 7201, guest PC 0x0c063dc6 */
if(!s->budget--) { s->failed_pc=0x0c063dc6u; return 0; }
r[2]+=0x00000001u;
goto P_0c063dc8;
P_0c063dc8: /* original 1e26, guest PC 0x0c063dc8 */
if(!s->budget--) { s->failed_pc=0x0c063dc8u; return 0; }
write(ram,r[14]+24,r[2],4);
goto P_0c063dca;
P_0c063dca: /* original 6023, guest PC 0x0c063dca */
if(!s->budget--) { s->failed_pc=0x0c063dcau; return 0; }
r[0]=r[2];
goto P_0c063dcc;
P_0c063dcc: /* original 0009, guest PC 0x0c063dcc */
if(!s->budget--) { s->failed_pc=0x0c063dccu; return 0; }
goto P_0c063dce;
P_0c063dce: /* original 3016, guest PC 0x0c063dce */
if(!s->budget--) { s->failed_pc=0x0c063dceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[1])!=0);
goto P_0c063dd0;
P_0c063dd0: /* original 8b12, guest PC 0x0c063dd0 */
if(!s->budget--) { s->failed_pc=0x0c063dd0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063df8; }
goto P_0c063dd2;
P_0c063dd2: /* original d018, guest PC 0x0c063dd2 */
if(!s->budget--) { s->failed_pc=0x0c063dd2u; return 0; }
r[0]=read(ram,0x0c063e34u,4);
goto P_0c063dd4;
P_0c063dd4: /* original 6202, guest PC 0x0c063dd4 */
if(!s->budget--) { s->failed_pc=0x0c063dd4u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c063dd6;
P_0c063dd6: /* original d318, guest PC 0x0c063dd6 */
if(!s->budget--) { s->failed_pc=0x0c063dd6u; return 0; }
r[3]=read(ram,0x0c063e38u,4);
goto P_0c063dd8;
P_0c063dd8: /* original 2322, guest PC 0x0c063dd8 */
if(!s->budget--) { s->failed_pc=0x0c063dd8u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063dda;
P_0c063dda: /* original d218, guest PC 0x0c063dda */
if(!s->budget--) { s->failed_pc=0x0c063ddau; return 0; }
r[2]=read(ram,0x0c063e3cu,4);
goto P_0c063ddc;
P_0c063ddc: /* original 6122, guest PC 0x0c063ddc */
if(!s->budget--) { s->failed_pc=0x0c063ddcu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c063dde;
P_0c063dde: /* original 7304, guest PC 0x0c063dde */
if(!s->budget--) { s->failed_pc=0x0c063ddeu; return 0; }
r[3]+=0x00000004u;
goto P_0c063de0;
P_0c063de0: /* original 2312, guest PC 0x0c063de0 */
if(!s->budget--) { s->failed_pc=0x0c063de0u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c063de2;
P_0c063de2: /* original d117, guest PC 0x0c063de2 */
if(!s->budget--) { s->failed_pc=0x0c063de2u; return 0; }
r[1]=read(ram,0x0c063e40u,4);
goto P_0c063de4;
P_0c063de4: /* original 6012, guest PC 0x0c063de4 */
if(!s->budget--) { s->failed_pc=0x0c063de4u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c063de6;
P_0c063de6: /* original 731c, guest PC 0x0c063de6 */
if(!s->budget--) { s->failed_pc=0x0c063de6u; return 0; }
r[3]+=0x0000001cu;
goto P_0c063de8;
P_0c063de8: /* original 2302, guest PC 0x0c063de8 */
if(!s->budget--) { s->failed_pc=0x0c063de8u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c063dea;
P_0c063dea: /* original d016, guest PC 0x0c063dea */
if(!s->budget--) { s->failed_pc=0x0c063deau; return 0; }
r[0]=read(ram,0x0c063e44u,4);
goto P_0c063dec;
P_0c063dec: /* original 6202, guest PC 0x0c063dec */
if(!s->budget--) { s->failed_pc=0x0c063decu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c063dee;
P_0c063dee: /* original 7304, guest PC 0x0c063dee */
if(!s->budget--) { s->failed_pc=0x0c063deeu; return 0; }
r[3]+=0x00000004u;
goto P_0c063df0;
P_0c063df0: /* original 2322, guest PC 0x0c063df0 */
if(!s->budget--) { s->failed_pc=0x0c063df0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c063df2;
P_0c063df2: /* original d115, guest PC 0x0c063df2 */
if(!s->budget--) { s->failed_pc=0x0c063df2u; return 0; }
r[1]=read(ram,0x0c063e48u,4);
goto P_0c063df4;
P_0c063df4: /* original 21d2, guest PC 0x0c063df4 */
if(!s->budget--) { s->failed_pc=0x0c063df4u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c063df6;
P_0c063df6: /* original 1ed6, guest PC 0x0c063df6 */
if(!s->budget--) { s->failed_pc=0x0c063df6u; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c063df8;
P_0c063df8: /* original a0ac, guest PC 0x0c063df8 */
if(!s->budget--) { s->failed_pc=0x0c063df8u; return 0; }
r[4]=0x00000001u;
goto P_0c063f54;
P_0c063dfa: /* original e401, guest PC 0x0c063dfa */
if(!s->budget--) { s->failed_pc=0x0c063dfau; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c063dfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c063dfcu; return 0; } return 1;
P_0c063e4c: /* original e300, guest PC 0x0c063e4c */
if(!s->budget--) { s->failed_pc=0x0c063e4cu; return 0; }
r[3]=0x00000000u;
goto P_0c063e4e;
P_0c063e4e: /* original 2f32, guest PC 0x0c063e4e */
if(!s->budget--) { s->failed_pc=0x0c063e4eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c063e50;
P_0c063e50: /* original 1fd3, guest PC 0x0c063e50 */
if(!s->budget--) { s->failed_pc=0x0c063e50u; return 0; }
write(ram,r[15]+12,r[13],4);
goto P_0c063e52;
P_0c063e52: /* original 1fd2, guest PC 0x0c063e52 */
if(!s->budget--) { s->failed_pc=0x0c063e52u; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c063e54;
P_0c063e54: /* original a077, guest PC 0x0c063e54 */
if(!s->budget--) { s->failed_pc=0x0c063e54u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c063f46;
P_0c063e56: /* original 1fd1, guest PC 0x0c063e56 */
if(!s->budget--) { s->failed_pc=0x0c063e56u; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c063e58;
P_0c063e58: /* original 6cf2, guest PC 0x0c063e58 */
if(!s->budget--) { s->failed_pc=0x0c063e58u; return 0; }
tmp=read(ram,r[15],4);
r[12]=tmp;
goto P_0c063e5a;
P_0c063e5a: /* original 4c08, guest PC 0x0c063e5a */
if(!s->budget--) { s->failed_pc=0x0c063e5au; return 0; }
r[12]<<=2;
goto P_0c063e5c;
P_0c063e5c: /* original d076, guest PC 0x0c063e5c */
if(!s->budget--) { s->failed_pc=0x0c063e5cu; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063e5e;
P_0c063e5e: /* original 03ce, guest PC 0x0c063e5e */
if(!s->budget--) { s->failed_pc=0x0c063e5eu; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c063e60;
P_0c063e60: /* original 4311, guest PC 0x0c063e60 */
if(!s->budget--) { s->failed_pc=0x0c063e60u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c063e62;
P_0c063e62: /* original 8b64, guest PC 0x0c063e62 */
if(!s->budget--) { s->failed_pc=0x0c063e62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f2e; }
goto P_0c063e64;
P_0c063e64: /* original 03ce, guest PC 0x0c063e64 */
if(!s->budget--) { s->failed_pc=0x0c063e64u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c063e66;
P_0c063e66: /* original e401, guest PC 0x0c063e66 */
if(!s->budget--) { s->failed_pc=0x0c063e66u; return 0; }
r[4]=0x00000001u;
goto P_0c063e68;
P_0c063e68: /* original 2348, guest PC 0x0c063e68 */
if(!s->budget--) { s->failed_pc=0x0c063e68u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c063e6a;
P_0c063e6a: /* original 8b60, guest PC 0x0c063e6a */
if(!s->budget--) { s->failed_pc=0x0c063e6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f2e; }
goto P_0c063e6c;
P_0c063e6c: /* original d473, guest PC 0x0c063e6c */
if(!s->budget--) { s->failed_pc=0x0c063e6cu; return 0; }
r[4]=read(ram,0x0c06403cu,4);
goto P_0c063e6e;
P_0c063e6e: /* original e505, guest PC 0x0c063e6e */
if(!s->budget--) { s->failed_pc=0x0c063e6eu; return 0; }
r[5]=0x00000005u;
goto P_0c063e70;
P_0c063e70: /* original d273, guest PC 0x0c063e70 */
if(!s->budget--) { s->failed_pc=0x0c063e70u; return 0; }
r[2]=read(ram,0x0c064040u,4);
goto P_0c063e72;
P_0c063e72: /* original 6322, guest PC 0x0c063e72 */
if(!s->budget--) { s->failed_pc=0x0c063e72u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c063e74;
P_0c063e74: /* original 2338, guest PC 0x0c063e74 */
if(!s->budget--) { s->failed_pc=0x0c063e74u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c063e76;
P_0c063e76: /* original 8f27, guest PC 0x0c063e76 */
if(!s->budget--) { s->failed_pc=0x0c063e76u; return 0; }
cond=r[17]&1u;
r[10]=0xffffffffu;
if(!cond) { goto P_0c063ec8; }
goto P_0c063e7a;
P_0c063e78: /* original eaff, guest PC 0x0c063e78 */
if(!s->budget--) { s->failed_pc=0x0c063e78u; return 0; }
r[10]=0xffffffffu;
goto P_0c063e7a;
P_0c063e7a: /* original 00ce, guest PC 0x0c063e7a */
if(!s->budget--) { s->failed_pc=0x0c063e7au; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c063e7c;
P_0c063e7c: /* original 8804, guest PC 0x0c063e7c */
if(!s->budget--) { s->failed_pc=0x0c063e7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c063e7e;
P_0c063e7e: /* original 8b0d, guest PC 0x0c063e7e */
if(!s->budget--) { s->failed_pc=0x0c063e7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063e9c; }
goto P_0c063e80;
P_0c063e80: /* original d06d, guest PC 0x0c063e80 */
if(!s->budget--) { s->failed_pc=0x0c063e80u; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063e82;
P_0c063e82: /* original 0c56, guest PC 0x0c063e82 */
if(!s->budget--) { s->failed_pc=0x0c063e82u; return 0; }
write(ram,r[12]+r[0],r[5],4);
goto P_0c063e84;
P_0c063e84: /* original d36f, guest PC 0x0c063e84 */
if(!s->budget--) { s->failed_pc=0x0c063e84u; return 0; }
r[3]=read(ram,0x0c064044u,4);
goto P_0c063e86;
P_0c063e86: /* original 6132, guest PC 0x0c063e86 */
if(!s->budget--) { s->failed_pc=0x0c063e86u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c063e88;
P_0c063e88: /* original 2118, guest PC 0x0c063e88 */
if(!s->budget--) { s->failed_pc=0x0c063e88u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c063e8a;
P_0c063e8a: /* original 8902, guest PC 0x0c063e8a */
if(!s->budget--) { s->failed_pc=0x0c063e8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c063e92; }
goto P_0c063e8c;
P_0c063e8c: /* original 52e2, guest PC 0x0c063e8c */
if(!s->budget--) { s->failed_pc=0x0c063e8cu; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c063e8e;
P_0c063e8e: /* original 7201, guest PC 0x0c063e8e */
if(!s->budget--) { s->failed_pc=0x0c063e8eu; return 0; }
r[2]+=0x00000001u;
goto P_0c063e90;
P_0c063e90: /* original 1e22, guest PC 0x0c063e90 */
if(!s->budget--) { s->failed_pc=0x0c063e90u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c063e92;
P_0c063e92: /* original d36c, guest PC 0x0c063e92 */
if(!s->budget--) { s->failed_pc=0x0c063e92u; return 0; }
r[3]=read(ram,0x0c064044u,4);
goto P_0c063e94;
P_0c063e94: /* original 23d2, guest PC 0x0c063e94 */
if(!s->budget--) { s->failed_pc=0x0c063e94u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c063e96;
P_0c063e96: /* original 24b2, guest PC 0x0c063e96 */
if(!s->budget--) { s->failed_pc=0x0c063e96u; return 0; }
write(ram,r[4],r[11],4);
goto P_0c063e98;
P_0c063e98: /* original a049, guest PC 0x0c063e98 */
if(!s->budget--) { s->failed_pc=0x0c063e98u; return 0; }
write(ram,r[4],r[13],4);
goto P_0c063f2e;
P_0c063e9a: /* original 24d2, guest PC 0x0c063e9a */
if(!s->budget--) { s->failed_pc=0x0c063e9au; return 0; }
write(ram,r[4],r[13],4);
goto P_0c063e9c;
P_0c063e9c: /* original d066, guest PC 0x0c063e9c */
if(!s->budget--) { s->failed_pc=0x0c063e9cu; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063e9e;
P_0c063e9e: /* original 00ce, guest PC 0x0c063e9e */
if(!s->budget--) { s->failed_pc=0x0c063e9eu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c063ea0;
P_0c063ea0: /* original 8802, guest PC 0x0c063ea0 */
if(!s->budget--) { s->failed_pc=0x0c063ea0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c063ea2;
P_0c063ea2: /* original 8f44, guest PC 0x0c063ea2 */
if(!s->budget--) { s->failed_pc=0x0c063ea2u; return 0; }
cond=r[17]&1u;
r[8]=0x00000001u;
if(!cond) { goto P_0c063f2e; }
goto P_0c063ea6;
P_0c063ea4: /* original e801, guest PC 0x0c063ea4 */
if(!s->budget--) { s->failed_pc=0x0c063ea4u; return 0; }
r[8]=0x00000001u;
goto P_0c063ea6;
P_0c063ea6: /* original 51e1, guest PC 0x0c063ea6 */
if(!s->budget--) { s->failed_pc=0x0c063ea6u; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c063ea8;
P_0c063ea8: /* original 7101, guest PC 0x0c063ea8 */
if(!s->budget--) { s->failed_pc=0x0c063ea8u; return 0; }
r[1]+=0x00000001u;
goto P_0c063eaa;
P_0c063eaa: /* original 1e11, guest PC 0x0c063eaa */
if(!s->budget--) { s->failed_pc=0x0c063eaau; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c063eac;
P_0c063eac: /* original d166, guest PC 0x0c063eac */
if(!s->budget--) { s->failed_pc=0x0c063eacu; return 0; }
r[1]=read(ram,0x0c064048u,4);
goto P_0c063eae;
P_0c063eae: /* original 6312, guest PC 0x0c063eae */
if(!s->budget--) { s->failed_pc=0x0c063eaeu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c063eb0;
P_0c063eb0: /* original 50e1, guest PC 0x0c063eb0 */
if(!s->budget--) { s->failed_pc=0x0c063eb0u; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c063eb2;
P_0c063eb2: /* original 3036, guest PC 0x0c063eb2 */
if(!s->budget--) { s->failed_pc=0x0c063eb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[3])!=0);
goto P_0c063eb4;
P_0c063eb4: /* original 8b3b, guest PC 0x0c063eb4 */
if(!s->budget--) { s->failed_pc=0x0c063eb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f2e; }
goto P_0c063eb6;
P_0c063eb6: /* original 53e3, guest PC 0x0c063eb6 */
if(!s->budget--) { s->failed_pc=0x0c063eb6u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c063eb8;
P_0c063eb8: /* original 7301, guest PC 0x0c063eb8 */
if(!s->budget--) { s->failed_pc=0x0c063eb8u; return 0; }
r[3]+=0x00000001u;
goto P_0c063eba;
P_0c063eba: /* original 1e33, guest PC 0x0c063eba */
if(!s->budget--) { s->failed_pc=0x0c063ebau; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c063ebc;
P_0c063ebc: /* original d363, guest PC 0x0c063ebc */
if(!s->budget--) { s->failed_pc=0x0c063ebcu; return 0; }
r[3]=read(ram,0x0c06404cu,4);
goto P_0c063ebe;
P_0c063ebe: /* original 430b, guest PC 0x0c063ebe */
if(!s->budget--) { s->failed_pc=0x0c063ebeu; return 0; }
target=r[3];
r[16]=code_base|0x0c063ec2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063ec2u) { target=s->pc; goto dispatch; }
goto P_0c063ec2;
P_0c063ec0: /* original 0009, guest PC 0x0c063ec0 */
if(!s->budget--) { s->failed_pc=0x0c063ec0u; return 0; }
goto P_0c063ec2;
P_0c063ec2: /* original d05d, guest PC 0x0c063ec2 */
if(!s->budget--) { s->failed_pc=0x0c063ec2u; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063ec4;
P_0c063ec4: /* original a030, guest PC 0x0c063ec4 */
if(!s->budget--) { s->failed_pc=0x0c063ec4u; return 0; }
write(ram,r[12]+r[0],r[10],4);
goto P_0c063f28;
P_0c063ec6: /* original 0ca6, guest PC 0x0c063ec6 */
if(!s->budget--) { s->failed_pc=0x0c063ec6u; return 0; }
write(ram,r[12]+r[0],r[10],4);
goto P_0c063ec8;
P_0c063ec8: /* original 00ce, guest PC 0x0c063ec8 */
if(!s->budget--) { s->failed_pc=0x0c063ec8u; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c063eca;
P_0c063eca: /* original 8804, guest PC 0x0c063eca */
if(!s->budget--) { s->failed_pc=0x0c063ecau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c063ecc;
P_0c063ecc: /* original 8f17, guest PC 0x0c063ecc */
if(!s->budget--) { s->failed_pc=0x0c063eccu; return 0; }
cond=r[17]&1u;
r[8]=0x00000001u;
if(!cond) { goto P_0c063efe; }
goto P_0c063ed0;
P_0c063ece: /* original e801, guest PC 0x0c063ece */
if(!s->budget--) { s->failed_pc=0x0c063eceu; return 0; }
r[8]=0x00000001u;
goto P_0c063ed0;
P_0c063ed0: /* original 61e2, guest PC 0x0c063ed0 */
if(!s->budget--) { s->failed_pc=0x0c063ed0u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c063ed2;
P_0c063ed2: /* original 7101, guest PC 0x0c063ed2 */
if(!s->budget--) { s->failed_pc=0x0c063ed2u; return 0; }
r[1]+=0x00000001u;
goto P_0c063ed4;
P_0c063ed4: /* original 2e12, guest PC 0x0c063ed4 */
if(!s->budget--) { s->failed_pc=0x0c063ed4u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c063ed6;
P_0c063ed6: /* original d15a, guest PC 0x0c063ed6 */
if(!s->budget--) { s->failed_pc=0x0c063ed6u; return 0; }
r[1]=read(ram,0x0c064040u,4);
goto P_0c063ed8;
P_0c063ed8: /* original 60e2, guest PC 0x0c063ed8 */
if(!s->budget--) { s->failed_pc=0x0c063ed8u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c063eda;
P_0c063eda: /* original 6312, guest PC 0x0c063eda */
if(!s->budget--) { s->failed_pc=0x0c063edau; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c063edc;
P_0c063edc: /* original 3036, guest PC 0x0c063edc */
if(!s->budget--) { s->failed_pc=0x0c063edcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[3])!=0);
goto P_0c063ede;
P_0c063ede: /* original 8b0e, guest PC 0x0c063ede */
if(!s->budget--) { s->failed_pc=0x0c063edeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063efe; }
goto P_0c063ee0;
P_0c063ee0: /* original 53e2, guest PC 0x0c063ee0 */
if(!s->budget--) { s->failed_pc=0x0c063ee0u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c063ee2;
P_0c063ee2: /* original 7301, guest PC 0x0c063ee2 */
if(!s->budget--) { s->failed_pc=0x0c063ee2u; return 0; }
r[3]+=0x00000001u;
goto P_0c063ee4;
P_0c063ee4: /* original 1e32, guest PC 0x0c063ee4 */
if(!s->budget--) { s->failed_pc=0x0c063ee4u; return 0; }
write(ram,r[14]+8,r[3],4);
goto P_0c063ee6;
P_0c063ee6: /* original 24b2, guest PC 0x0c063ee6 */
if(!s->budget--) { s->failed_pc=0x0c063ee6u; return 0; }
write(ram,r[4],r[11],4);
goto P_0c063ee8;
P_0c063ee8: /* original 24d2, guest PC 0x0c063ee8 */
if(!s->budget--) { s->failed_pc=0x0c063ee8u; return 0; }
write(ram,r[4],r[13],4);
goto P_0c063eea;
P_0c063eea: /* original 53f1, guest PC 0x0c063eea */
if(!s->budget--) { s->failed_pc=0x0c063eeau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c063eec;
P_0c063eec: /* original d052, guest PC 0x0c063eec */
if(!s->budget--) { s->failed_pc=0x0c063eecu; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063eee;
P_0c063eee: /* original 0356, guest PC 0x0c063eee */
if(!s->budget--) { s->failed_pc=0x0c063eeeu; return 0; }
write(ram,r[3]+r[0],r[5],4);
goto P_0c063ef0;
P_0c063ef0: /* original d354, guest PC 0x0c063ef0 */
if(!s->budget--) { s->failed_pc=0x0c063ef0u; return 0; }
r[3]=read(ram,0x0c064044u,4);
goto P_0c063ef2;
P_0c063ef2: /* original 23d2, guest PC 0x0c063ef2 */
if(!s->budget--) { s->failed_pc=0x0c063ef2u; return 0; }
write(ram,r[3],r[13],4);
goto P_0c063ef4;
P_0c063ef4: /* original d456, guest PC 0x0c063ef4 */
if(!s->budget--) { s->failed_pc=0x0c063ef4u; return 0; }
r[4]=read(ram,0x0c064050u,4);
goto P_0c063ef6;
P_0c063ef6: /* original 6242, guest PC 0x0c063ef6 */
if(!s->budget--) { s->failed_pc=0x0c063ef6u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c063ef8;
P_0c063ef8: /* original 7201, guest PC 0x0c063ef8 */
if(!s->budget--) { s->failed_pc=0x0c063ef8u; return 0; }
r[2]+=0x00000001u;
goto P_0c063efa;
P_0c063efa: /* original 2422, guest PC 0x0c063efa */
if(!s->budget--) { s->failed_pc=0x0c063efau; return 0; }
write(ram,r[4],r[2],4);
goto P_0c063efc;
P_0c063efc: /* original 2ed2, guest PC 0x0c063efc */
if(!s->budget--) { s->failed_pc=0x0c063efcu; return 0; }
write(ram,r[14],r[13],4);
goto P_0c063efe;
P_0c063efe: /* original 53f2, guest PC 0x0c063efe */
if(!s->budget--) { s->failed_pc=0x0c063efeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c063f00;
P_0c063f00: /* original d04d, guest PC 0x0c063f00 */
if(!s->budget--) { s->failed_pc=0x0c063f00u; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063f02;
P_0c063f02: /* original 003e, guest PC 0x0c063f02 */
if(!s->budget--) { s->failed_pc=0x0c063f02u; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c063f04;
P_0c063f04: /* original 8802, guest PC 0x0c063f04 */
if(!s->budget--) { s->failed_pc=0x0c063f04u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c063f06;
P_0c063f06: /* original 8b12, guest PC 0x0c063f06 */
if(!s->budget--) { s->failed_pc=0x0c063f06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f2e; }
goto P_0c063f08;
P_0c063f08: /* original 53e1, guest PC 0x0c063f08 */
if(!s->budget--) { s->failed_pc=0x0c063f08u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c063f0a;
P_0c063f0a: /* original 7301, guest PC 0x0c063f0a */
if(!s->budget--) { s->failed_pc=0x0c063f0au; return 0; }
r[3]+=0x00000001u;
goto P_0c063f0c;
P_0c063f0c: /* original 1e31, guest PC 0x0c063f0c */
if(!s->budget--) { s->failed_pc=0x0c063f0cu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c063f0e;
P_0c063f0e: /* original 6133, guest PC 0x0c063f0e */
if(!s->budget--) { s->failed_pc=0x0c063f0eu; return 0; }
r[1]=r[3];
goto P_0c063f10;
P_0c063f10: /* original d04d, guest PC 0x0c063f10 */
if(!s->budget--) { s->failed_pc=0x0c063f10u; return 0; }
r[0]=read(ram,0x0c064048u,4);
goto P_0c063f12;
P_0c063f12: /* original 6202, guest PC 0x0c063f12 */
if(!s->budget--) { s->failed_pc=0x0c063f12u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c063f14;
P_0c063f14: /* original 3126, guest PC 0x0c063f14 */
if(!s->budget--) { s->failed_pc=0x0c063f14u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[2])!=0);
goto P_0c063f16;
P_0c063f16: /* original 8b0a, guest PC 0x0c063f16 */
if(!s->budget--) { s->failed_pc=0x0c063f16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f2e; }
goto P_0c063f18;
P_0c063f18: /* original 53e3, guest PC 0x0c063f18 */
if(!s->budget--) { s->failed_pc=0x0c063f18u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c063f1a;
P_0c063f1a: /* original 7301, guest PC 0x0c063f1a */
if(!s->budget--) { s->failed_pc=0x0c063f1au; return 0; }
r[3]+=0x00000001u;
goto P_0c063f1c;
P_0c063f1c: /* original d24b, guest PC 0x0c063f1c */
if(!s->budget--) { s->failed_pc=0x0c063f1cu; return 0; }
r[2]=read(ram,0x0c06404cu,4);
goto P_0c063f1e;
P_0c063f1e: /* original 420b, guest PC 0x0c063f1e */
if(!s->budget--) { s->failed_pc=0x0c063f1eu; return 0; }
target=r[2];
r[16]=code_base|0x0c063f22u;
write(ram,r[14]+12,r[3],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063f22u) { target=s->pc; goto dispatch; }
goto P_0c063f22;
P_0c063f20: /* original 1e33, guest PC 0x0c063f20 */
if(!s->budget--) { s->failed_pc=0x0c063f20u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c063f22;
P_0c063f22: /* original 51f3, guest PC 0x0c063f22 */
if(!s->budget--) { s->failed_pc=0x0c063f22u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c063f24;
P_0c063f24: /* original d044, guest PC 0x0c063f24 */
if(!s->budget--) { s->failed_pc=0x0c063f24u; return 0; }
r[0]=read(ram,0x0c064038u,4);
goto P_0c063f26;
P_0c063f26: /* original 01a6, guest PC 0x0c063f26 */
if(!s->budget--) { s->failed_pc=0x0c063f26u; return 0; }
write(ram,r[1]+r[0],r[10],4);
goto P_0c063f28;
P_0c063f28: /* original d34a, guest PC 0x0c063f28 */
if(!s->budget--) { s->failed_pc=0x0c063f28u; return 0; }
r[3]=read(ram,0x0c064054u,4);
goto P_0c063f2a;
P_0c063f2a: /* original 23d2, guest PC 0x0c063f2a */
if(!s->budget--) { s->failed_pc=0x0c063f2au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c063f2c;
P_0c063f2c: /* original 1ed1, guest PC 0x0c063f2c */
if(!s->budget--) { s->failed_pc=0x0c063f2cu; return 0; }
write(ram,r[14]+4,r[13],4);
goto P_0c063f2e;
P_0c063f2e: /* original 62f2, guest PC 0x0c063f2e */
if(!s->budget--) { s->failed_pc=0x0c063f2eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c063f30;
P_0c063f30: /* original 7201, guest PC 0x0c063f30 */
if(!s->budget--) { s->failed_pc=0x0c063f30u; return 0; }
r[2]+=0x00000001u;
goto P_0c063f32;
P_0c063f32: /* original 2f22, guest PC 0x0c063f32 */
if(!s->budget--) { s->failed_pc=0x0c063f32u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c063f34;
P_0c063f34: /* original 53f3, guest PC 0x0c063f34 */
if(!s->budget--) { s->failed_pc=0x0c063f34u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c063f36;
P_0c063f36: /* original 7304, guest PC 0x0c063f36 */
if(!s->budget--) { s->failed_pc=0x0c063f36u; return 0; }
r[3]+=0x00000004u;
goto P_0c063f38;
P_0c063f38: /* original 1f33, guest PC 0x0c063f38 */
if(!s->budget--) { s->failed_pc=0x0c063f38u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c063f3a;
P_0c063f3a: /* original 51f2, guest PC 0x0c063f3a */
if(!s->budget--) { s->failed_pc=0x0c063f3au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c063f3c;
P_0c063f3c: /* original 7104, guest PC 0x0c063f3c */
if(!s->budget--) { s->failed_pc=0x0c063f3cu; return 0; }
r[1]+=0x00000004u;
goto P_0c063f3e;
P_0c063f3e: /* original 1f12, guest PC 0x0c063f3e */
if(!s->budget--) { s->failed_pc=0x0c063f3eu; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c063f40;
P_0c063f40: /* original 53f1, guest PC 0x0c063f40 */
if(!s->budget--) { s->failed_pc=0x0c063f40u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c063f42;
P_0c063f42: /* original 7304, guest PC 0x0c063f42 */
if(!s->budget--) { s->failed_pc=0x0c063f42u; return 0; }
r[3]+=0x00000004u;
goto P_0c063f44;
P_0c063f44: /* original 1f31, guest PC 0x0c063f44 */
if(!s->budget--) { s->failed_pc=0x0c063f44u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c063f46;
P_0c063f46: /* original 62f2, guest PC 0x0c063f46 */
if(!s->budget--) { s->failed_pc=0x0c063f46u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c063f48;
P_0c063f48: /* original 3293, guest PC 0x0c063f48 */
if(!s->budget--) { s->failed_pc=0x0c063f48u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[9])!=0);
goto P_0c063f4a;
P_0c063f4a: /* original 8b85, guest PC 0x0c063f4a */
if(!s->budget--) { s->failed_pc=0x0c063f4au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063e58; }
goto P_0c063f4c;
P_0c063f4c: /* original d33d, guest PC 0x0c063f4c */
if(!s->budget--) { s->failed_pc=0x0c063f4cu; return 0; }
r[3]=read(ram,0x0c064044u,4);
goto P_0c063f4e;
P_0c063f4e: /* original 6132, guest PC 0x0c063f4e */
if(!s->budget--) { s->failed_pc=0x0c063f4eu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c063f50;
P_0c063f50: /* original 281b, guest PC 0x0c063f50 */
if(!s->budget--) { s->failed_pc=0x0c063f50u; return 0; }
r[8]|=r[1];
goto P_0c063f52;
P_0c063f52: /* original 6483, guest PC 0x0c063f52 */
if(!s->budget--) { s->failed_pc=0x0c063f52u; return 0; }
r[4]=r[8];
goto P_0c063f54;
P_0c063f54: /* original 2448, guest PC 0x0c063f54 */
if(!s->budget--) { s->failed_pc=0x0c063f54u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c063f56;
P_0c063f56: /* original 8b0b, guest PC 0x0c063f56 */
if(!s->budget--) { s->failed_pc=0x0c063f56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f70; }
goto P_0c063f58;
P_0c063f58: /* original bc08, guest PC 0x0c063f58 */
if(!s->budget--) { s->failed_pc=0x0c063f58u; return 0; }
target=code_base|0x0c06376cu; r[16]=code_base|0x0c063f5cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063f5cu) { target=s->pc; goto dispatch; }
goto P_0c063f5c;
P_0c063f5a: /* original 0009, guest PC 0x0c063f5a */
if(!s->budget--) { s->failed_pc=0x0c063f5au; return 0; }
goto P_0c063f5c;
P_0c063f5c: /* original bc92, guest PC 0x0c063f5c */
if(!s->budget--) { s->failed_pc=0x0c063f5cu; return 0; }
target=code_base|0x0c063884u; r[16]=code_base|0x0c063f60u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063f60u) { target=s->pc; goto dispatch; }
goto P_0c063f60;
P_0c063f5e: /* original 0009, guest PC 0x0c063f5e */
if(!s->budget--) { s->failed_pc=0x0c063f5eu; return 0; }
goto P_0c063f60;
P_0c063f60: /* original 2008, guest PC 0x0c063f60 */
if(!s->budget--) { s->failed_pc=0x0c063f60u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c063f62;
P_0c063f62: /* original 8b01, guest PC 0x0c063f62 */
if(!s->budget--) { s->failed_pc=0x0c063f62u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c063f68; }
goto P_0c063f64;
P_0c063f64: /* original a005, guest PC 0x0c063f64 */
if(!s->budget--) { s->failed_pc=0x0c063f64u; return 0; }
r[0]=0x00000001u;
goto P_0c063f72;
P_0c063f66: /* original e001, guest PC 0x0c063f66 */
if(!s->budget--) { s->failed_pc=0x0c063f66u; return 0; }
r[0]=0x00000001u;
goto P_0c063f68;
P_0c063f68: /* original bdc5, guest PC 0x0c063f68 */
if(!s->budget--) { s->failed_pc=0x0c063f68u; return 0; }
target=code_base|0x0c063af6u; r[16]=code_base|0x0c063f6cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c063f6cu) { target=s->pc; goto dispatch; }
goto P_0c063f6c;
P_0c063f6a: /* original 0009, guest PC 0x0c063f6a */
if(!s->budget--) { s->failed_pc=0x0c063f6au; return 0; }
goto P_0c063f6c;
P_0c063f6c: /* original d23a, guest PC 0x0c063f6c */
if(!s->budget--) { s->failed_pc=0x0c063f6cu; return 0; }
r[2]=read(ram,0x0c064058u,4);
goto P_0c063f6e;
P_0c063f6e: /* original 22d2, guest PC 0x0c063f6e */
if(!s->budget--) { s->failed_pc=0x0c063f6eu; return 0; }
write(ram,r[2],r[13],4);
goto P_0c063f70;
P_0c063f70: /* original e000, guest PC 0x0c063f70 */
if(!s->budget--) { s->failed_pc=0x0c063f70u; return 0; }
r[0]=0x00000000u;
goto P_0c063f72;
P_0c063f72: /* original 7f10, guest PC 0x0c063f72 */
if(!s->budget--) { s->failed_pc=0x0c063f72u; return 0; }
r[15]+=0x00000010u;
goto P_0c063f74;
P_0c063f74: /* original 4f26, guest PC 0x0c063f74 */
if(!s->budget--) { s->failed_pc=0x0c063f74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c063f76;
P_0c063f76: /* original 68f6, guest PC 0x0c063f76 */
if(!s->budget--) { s->failed_pc=0x0c063f76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c063f78;
P_0c063f78: /* original 69f6, guest PC 0x0c063f78 */
if(!s->budget--) { s->failed_pc=0x0c063f78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c063f7a;
P_0c063f7a: /* original 6af6, guest PC 0x0c063f7a */
if(!s->budget--) { s->failed_pc=0x0c063f7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c063f7c;
P_0c063f7c: /* original 6bf6, guest PC 0x0c063f7c */
if(!s->budget--) { s->failed_pc=0x0c063f7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c063f7e;
P_0c063f7e: /* original 6cf6, guest PC 0x0c063f7e */
if(!s->budget--) { s->failed_pc=0x0c063f7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c063f80;
P_0c063f80: /* original 6df6, guest PC 0x0c063f80 */
if(!s->budget--) { s->failed_pc=0x0c063f80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c063f82;
P_0c063f82: /* original 000b, guest PC 0x0c063f82 */
if(!s->budget--) { s->failed_pc=0x0c063f82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c063f84: /* original 6ef6, guest PC 0x0c063f84 */
if(!s->budget--) { s->failed_pc=0x0c063f84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c063f86u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
