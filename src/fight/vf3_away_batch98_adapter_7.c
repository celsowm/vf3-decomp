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
int vf3_away_batch98_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c3b40u: goto P_0c0c3b40;
case 0x0c0c3b42u: goto P_0c0c3b42;
case 0x0c0c3b44u: goto P_0c0c3b44;
case 0x0c0c3b46u: goto P_0c0c3b46;
case 0x0c0c3b48u: goto P_0c0c3b48;
case 0x0c0c3b4au: goto P_0c0c3b4a;
case 0x0c0c3b4cu: goto P_0c0c3b4c;
case 0x0c0c3b4eu: goto P_0c0c3b4e;
case 0x0c0c3b50u: goto P_0c0c3b50;
case 0x0c0c3b52u: goto P_0c0c3b52;
case 0x0c0c3b54u: goto P_0c0c3b54;
case 0x0c0c3b56u: goto P_0c0c3b56;
case 0x0c0c3b58u: goto P_0c0c3b58;
case 0x0c0c3b5au: goto P_0c0c3b5a;
case 0x0c0c3b5cu: goto P_0c0c3b5c;
case 0x0c0c3b5eu: goto P_0c0c3b5e;
case 0x0c0c3b60u: goto P_0c0c3b60;
case 0x0c0c3b62u: goto P_0c0c3b62;
case 0x0c0c3b64u: goto P_0c0c3b64;
case 0x0c0c3b66u: goto P_0c0c3b66;
case 0x0c0c3b68u: goto P_0c0c3b68;
case 0x0c0c3b6au: goto P_0c0c3b6a;
case 0x0c0c3b6cu: goto P_0c0c3b6c;
case 0x0c0c3b6eu: goto P_0c0c3b6e;
case 0x0c0c3b70u: goto P_0c0c3b70;
case 0x0c0c3b72u: goto P_0c0c3b72;
case 0x0c0c3b74u: goto P_0c0c3b74;
case 0x0c0c3b76u: goto P_0c0c3b76;
case 0x0c0c3b78u: goto P_0c0c3b78;
case 0x0c0c3b7au: goto P_0c0c3b7a;
case 0x0c0c3b7cu: goto P_0c0c3b7c;
case 0x0c0c3b7eu: goto P_0c0c3b7e;
case 0x0c0c3b80u: goto P_0c0c3b80;
case 0x0c0c3b82u: goto P_0c0c3b82;
case 0x0c0c3ba4u: goto P_0c0c3ba4;
case 0x0c0c3ba6u: goto P_0c0c3ba6;
case 0x0c0c3ba8u: goto P_0c0c3ba8;
case 0x0c0c3baau: goto P_0c0c3baa;
case 0x0c0c3bacu: goto P_0c0c3bac;
case 0x0c0c3baeu: goto P_0c0c3bae;
case 0x0c0c3bb0u: goto P_0c0c3bb0;
case 0x0c0c3bb2u: goto P_0c0c3bb2;
case 0x0c0c3bb4u: goto P_0c0c3bb4;
case 0x0c0c3bb6u: goto P_0c0c3bb6;
case 0x0c0c3bb8u: goto P_0c0c3bb8;
case 0x0c0c3bbau: goto P_0c0c3bba;
case 0x0c0c3bbcu: goto P_0c0c3bbc;
case 0x0c0c3bbeu: goto P_0c0c3bbe;
case 0x0c0c3bc0u: goto P_0c0c3bc0;
case 0x0c0c3bc2u: goto P_0c0c3bc2;
case 0x0c0c3bc4u: goto P_0c0c3bc4;
case 0x0c0c3bc6u: goto P_0c0c3bc6;
case 0x0c0c3bc8u: goto P_0c0c3bc8;
case 0x0c0c3bcau: goto P_0c0c3bca;
case 0x0c0c3bccu: goto P_0c0c3bcc;
case 0x0c0c3bceu: goto P_0c0c3bce;
case 0x0c0c3bd0u: goto P_0c0c3bd0;
case 0x0c0c3bd2u: goto P_0c0c3bd2;
case 0x0c0c3bd4u: goto P_0c0c3bd4;
case 0x0c0c3bd6u: goto P_0c0c3bd6;
case 0x0c0c3bd8u: goto P_0c0c3bd8;
case 0x0c0c3bdau: goto P_0c0c3bda;
case 0x0c0c3bdcu: goto P_0c0c3bdc;
case 0x0c0c3bdeu: goto P_0c0c3bde;
case 0x0c0c3be0u: goto P_0c0c3be0;
case 0x0c0c3be2u: goto P_0c0c3be2;
case 0x0c0c3be4u: goto P_0c0c3be4;
case 0x0c0c3be6u: goto P_0c0c3be6;
case 0x0c0c3be8u: goto P_0c0c3be8;
case 0x0c0c3beau: goto P_0c0c3bea;
case 0x0c0c3becu: goto P_0c0c3bec;
case 0x0c0c3beeu: goto P_0c0c3bee;
case 0x0c0c3bf0u: goto P_0c0c3bf0;
case 0x0c0c3bf2u: goto P_0c0c3bf2;
case 0x0c0c3bf4u: goto P_0c0c3bf4;
case 0x0c0c3bf6u: goto P_0c0c3bf6;
case 0x0c0c3bf8u: goto P_0c0c3bf8;
case 0x0c0c3bfau: goto P_0c0c3bfa;
case 0x0c0c3bfcu: goto P_0c0c3bfc;
case 0x0c0c3bfeu: goto P_0c0c3bfe;
case 0x0c0c3c00u: goto P_0c0c3c00;
case 0x0c0c3c02u: goto P_0c0c3c02;
case 0x0c0c3c04u: goto P_0c0c3c04;
case 0x0c0c3c06u: goto P_0c0c3c06;
case 0x0c0c3c08u: goto P_0c0c3c08;
case 0x0c0c3c0au: goto P_0c0c3c0a;
case 0x0c0c3c0cu: goto P_0c0c3c0c;
case 0x0c0c3c0eu: goto P_0c0c3c0e;
case 0x0c0c3c10u: goto P_0c0c3c10;
case 0x0c0c3c12u: goto P_0c0c3c12;
case 0x0c0c3c14u: goto P_0c0c3c14;
case 0x0c0c3c16u: goto P_0c0c3c16;
case 0x0c0c3c18u: goto P_0c0c3c18;
case 0x0c0c3c1au: goto P_0c0c3c1a;
case 0x0c0c3c1cu: goto P_0c0c3c1c;
case 0x0c0c3c1eu: goto P_0c0c3c1e;
case 0x0c0c3c20u: goto P_0c0c3c20;
case 0x0c0c3c22u: goto P_0c0c3c22;
case 0x0c0c3c24u: goto P_0c0c3c24;
case 0x0c0c3c26u: goto P_0c0c3c26;
case 0x0c0c3c28u: goto P_0c0c3c28;
case 0x0c0c3c2au: goto P_0c0c3c2a;
case 0x0c0c3c2cu: goto P_0c0c3c2c;
case 0x0c0c3c2eu: goto P_0c0c3c2e;
case 0x0c0c3c30u: goto P_0c0c3c30;
case 0x0c0c3c32u: goto P_0c0c3c32;
case 0x0c0c3c34u: goto P_0c0c3c34;
case 0x0c0c3c36u: goto P_0c0c3c36;
case 0x0c0c3c38u: goto P_0c0c3c38;
case 0x0c0c3c3au: goto P_0c0c3c3a;
case 0x0c0c3c3cu: goto P_0c0c3c3c;
case 0x0c0c3c3eu: goto P_0c0c3c3e;
case 0x0c0c3c40u: goto P_0c0c3c40;
case 0x0c0c3c42u: goto P_0c0c3c42;
case 0x0c0c3c44u: goto P_0c0c3c44;
case 0x0c0c3c46u: goto P_0c0c3c46;
case 0x0c0c3c48u: goto P_0c0c3c48;
case 0x0c0c3c4au: goto P_0c0c3c4a;
case 0x0c0c3c4cu: goto P_0c0c3c4c;
case 0x0c0c3c4eu: goto P_0c0c3c4e;
case 0x0c0c3c50u: goto P_0c0c3c50;
case 0x0c0c3c52u: goto P_0c0c3c52;
case 0x0c0c3c54u: goto P_0c0c3c54;
case 0x0c0c3c56u: goto P_0c0c3c56;
case 0x0c0c3c58u: goto P_0c0c3c58;
case 0x0c0c3c5au: goto P_0c0c3c5a;
case 0x0c0c3c5cu: goto P_0c0c3c5c;
case 0x0c0c3c5eu: goto P_0c0c3c5e;
case 0x0c0c3c60u: goto P_0c0c3c60;
case 0x0c0c3c62u: goto P_0c0c3c62;
case 0x0c0c3c64u: goto P_0c0c3c64;
case 0x0c0c3c66u: goto P_0c0c3c66;
case 0x0c0c3c68u: goto P_0c0c3c68;
case 0x0c0c3c6au: goto P_0c0c3c6a;
case 0x0c0c3c6cu: goto P_0c0c3c6c;
case 0x0c0c3c6eu: goto P_0c0c3c6e;
case 0x0c0c3c70u: goto P_0c0c3c70;
case 0x0c0c3c72u: goto P_0c0c3c72;
case 0x0c0c3c74u: goto P_0c0c3c74;
case 0x0c0c3c76u: goto P_0c0c3c76;
case 0x0c0c3c78u: goto P_0c0c3c78;
case 0x0c0c3c7au: goto P_0c0c3c7a;
case 0x0c0c3c7cu: goto P_0c0c3c7c;
case 0x0c0c3c7eu: goto P_0c0c3c7e;
case 0x0c0c3c80u: goto P_0c0c3c80;
case 0x0c0c3c82u: goto P_0c0c3c82;
case 0x0c0c3c84u: goto P_0c0c3c84;
case 0x0c0c3c86u: goto P_0c0c3c86;
case 0x0c0c3c88u: goto P_0c0c3c88;
case 0x0c0c3c8au: goto P_0c0c3c8a;
case 0x0c0c3c8cu: goto P_0c0c3c8c;
case 0x0c0c3c8eu: goto P_0c0c3c8e;
case 0x0c0c3c90u: goto P_0c0c3c90;
case 0x0c0c3cbcu: goto P_0c0c3cbc;
case 0x0c0c3cbeu: goto P_0c0c3cbe;
case 0x0c0c3cc0u: goto P_0c0c3cc0;
case 0x0c0c3cc2u: goto P_0c0c3cc2;
case 0x0c0c3cc4u: goto P_0c0c3cc4;
case 0x0c0c3cc6u: goto P_0c0c3cc6;
case 0x0c0c3cc8u: goto P_0c0c3cc8;
case 0x0c0c3ccau: goto P_0c0c3cca;
case 0x0c0c3cccu: goto P_0c0c3ccc;
case 0x0c0c3cceu: goto P_0c0c3cce;
case 0x0c0c3cd0u: goto P_0c0c3cd0;
case 0x0c0c3cd2u: goto P_0c0c3cd2;
case 0x0c0c3cd4u: goto P_0c0c3cd4;
case 0x0c0c3cd6u: goto P_0c0c3cd6;
case 0x0c0c3cd8u: goto P_0c0c3cd8;
case 0x0c0c3cdau: goto P_0c0c3cda;
case 0x0c0c3cdcu: goto P_0c0c3cdc;
case 0x0c0c3cdeu: goto P_0c0c3cde;
case 0x0c0c3ce0u: goto P_0c0c3ce0;
case 0x0c0c3ce2u: goto P_0c0c3ce2;
case 0x0c0c3ce4u: goto P_0c0c3ce4;
case 0x0c0c3ce6u: goto P_0c0c3ce6;
case 0x0c0c3ce8u: goto P_0c0c3ce8;
case 0x0c0c3ceau: goto P_0c0c3cea;
case 0x0c0c3cecu: goto P_0c0c3cec;
case 0x0c0c3ceeu: goto P_0c0c3cee;
case 0x0c0c3cf0u: goto P_0c0c3cf0;
case 0x0c0c3cf2u: goto P_0c0c3cf2;
case 0x0c0c3cf4u: goto P_0c0c3cf4;
case 0x0c0c3cf6u: goto P_0c0c3cf6;
case 0x0c0c3cf8u: goto P_0c0c3cf8;
case 0x0c0c3cfau: goto P_0c0c3cfa;
case 0x0c0c3cfcu: goto P_0c0c3cfc;
case 0x0c0c3cfeu: goto P_0c0c3cfe;
case 0x0c0c3d00u: goto P_0c0c3d00;
case 0x0c0c3d02u: goto P_0c0c3d02;
case 0x0c0c3d04u: goto P_0c0c3d04;
case 0x0c0c3d06u: goto P_0c0c3d06;
case 0x0c0c3d08u: goto P_0c0c3d08;
case 0x0c0c3d0au: goto P_0c0c3d0a;
case 0x0c0c3d0cu: goto P_0c0c3d0c;
case 0x0c0c3d0eu: goto P_0c0c3d0e;
case 0x0c0c3d10u: goto P_0c0c3d10;
case 0x0c0c3d12u: goto P_0c0c3d12;
case 0x0c0c3d14u: goto P_0c0c3d14;
case 0x0c0c3d16u: goto P_0c0c3d16;
case 0x0c0c3d18u: goto P_0c0c3d18;
case 0x0c0c3d1au: goto P_0c0c3d1a;
case 0x0c0c3d1cu: goto P_0c0c3d1c;
case 0x0c0c3d1eu: goto P_0c0c3d1e;
case 0x0c0c3d20u: goto P_0c0c3d20;
case 0x0c0c3d22u: goto P_0c0c3d22;
case 0x0c0c3d24u: goto P_0c0c3d24;
case 0x0c0c3d26u: goto P_0c0c3d26;
case 0x0c0c3d28u: goto P_0c0c3d28;
case 0x0c0c3d2au: goto P_0c0c3d2a;
case 0x0c0c3d2cu: goto P_0c0c3d2c;
case 0x0c0c3d2eu: goto P_0c0c3d2e;
case 0x0c0c3d30u: goto P_0c0c3d30;
case 0x0c0c3d32u: goto P_0c0c3d32;
case 0x0c0c3d34u: goto P_0c0c3d34;
case 0x0c0c3d36u: goto P_0c0c3d36;
case 0x0c0c3d38u: goto P_0c0c3d38;
case 0x0c0c3d3au: goto P_0c0c3d3a;
case 0x0c0c3d3cu: goto P_0c0c3d3c;
case 0x0c0c3d3eu: goto P_0c0c3d3e;
case 0x0c0c3d40u: goto P_0c0c3d40;
case 0x0c0c3d42u: goto P_0c0c3d42;
case 0x0c0c3d44u: goto P_0c0c3d44;
case 0x0c0c3d46u: goto P_0c0c3d46;
case 0x0c0c3d48u: goto P_0c0c3d48;
case 0x0c0c3d4au: goto P_0c0c3d4a;
case 0x0c0c3d4cu: goto P_0c0c3d4c;
case 0x0c0c3d4eu: goto P_0c0c3d4e;
case 0x0c0c3d50u: goto P_0c0c3d50;
case 0x0c0c3d52u: goto P_0c0c3d52;
case 0x0c0c3d54u: goto P_0c0c3d54;
case 0x0c0c3d56u: goto P_0c0c3d56;
case 0x0c0c3d58u: goto P_0c0c3d58;
case 0x0c0c3d5au: goto P_0c0c3d5a;
case 0x0c0c3d5cu: goto P_0c0c3d5c;
case 0x0c0c3d5eu: goto P_0c0c3d5e;
case 0x0c0c3d60u: goto P_0c0c3d60;
case 0x0c0c3d62u: goto P_0c0c3d62;
case 0x0c0c3d64u: goto P_0c0c3d64;
case 0x0c0c3d66u: goto P_0c0c3d66;
case 0x0c0c3d68u: goto P_0c0c3d68;
case 0x0c0c3d6au: goto P_0c0c3d6a;
case 0x0c0c3d6cu: goto P_0c0c3d6c;
case 0x0c0c3d6eu: goto P_0c0c3d6e;
case 0x0c0c3d70u: goto P_0c0c3d70;
case 0x0c0c3d72u: goto P_0c0c3d72;
case 0x0c0c3d74u: goto P_0c0c3d74;
case 0x0c0c3d76u: goto P_0c0c3d76;
case 0x0c0c3dacu: goto P_0c0c3dac;
case 0x0c0c3daeu: goto P_0c0c3dae;
case 0x0c0c3db0u: goto P_0c0c3db0;
case 0x0c0c3db2u: goto P_0c0c3db2;
case 0x0c0c3db4u: goto P_0c0c3db4;
case 0x0c0c3db6u: goto P_0c0c3db6;
case 0x0c0c3db8u: goto P_0c0c3db8;
case 0x0c0c3dbau: goto P_0c0c3dba;
case 0x0c0c3dbcu: goto P_0c0c3dbc;
case 0x0c0c3dbeu: goto P_0c0c3dbe;
case 0x0c0c3dc0u: goto P_0c0c3dc0;
case 0x0c0c3dc2u: goto P_0c0c3dc2;
case 0x0c0c3dc4u: goto P_0c0c3dc4;
case 0x0c0c3dc6u: goto P_0c0c3dc6;
case 0x0c0c3dc8u: goto P_0c0c3dc8;
case 0x0c0c3dcau: goto P_0c0c3dca;
case 0x0c0c3dccu: goto P_0c0c3dcc;
case 0x0c0c3dceu: goto P_0c0c3dce;
case 0x0c0c3dd0u: goto P_0c0c3dd0;
case 0x0c0c3dd2u: goto P_0c0c3dd2;
case 0x0c0c3dd4u: goto P_0c0c3dd4;
case 0x0c0c3dd6u: goto P_0c0c3dd6;
case 0x0c0c3dd8u: goto P_0c0c3dd8;
case 0x0c0c3ddau: goto P_0c0c3dda;
case 0x0c0c3ddcu: goto P_0c0c3ddc;
case 0x0c0c3ddeu: goto P_0c0c3dde;
case 0x0c0c3de0u: goto P_0c0c3de0;
case 0x0c0c3de2u: goto P_0c0c3de2;
case 0x0c0c3de4u: goto P_0c0c3de4;
case 0x0c0c3de6u: goto P_0c0c3de6;
case 0x0c0c3de8u: goto P_0c0c3de8;
case 0x0c0c3deau: goto P_0c0c3dea;
case 0x0c0c3decu: goto P_0c0c3dec;
case 0x0c0c3deeu: goto P_0c0c3dee;
case 0x0c0c3df0u: goto P_0c0c3df0;
case 0x0c0c3df2u: goto P_0c0c3df2;
case 0x0c0c3df4u: goto P_0c0c3df4;
case 0x0c0c3df6u: goto P_0c0c3df6;
case 0x0c0c3df8u: goto P_0c0c3df8;
case 0x0c0c3dfau: goto P_0c0c3dfa;
case 0x0c0c3dfcu: goto P_0c0c3dfc;
case 0x0c0c3dfeu: goto P_0c0c3dfe;
case 0x0c0c3e00u: goto P_0c0c3e00;
case 0x0c0c3e02u: goto P_0c0c3e02;
case 0x0c0c3e04u: goto P_0c0c3e04;
case 0x0c0c3e06u: goto P_0c0c3e06;
case 0x0c0c3e08u: goto P_0c0c3e08;
case 0x0c0c3e0au: goto P_0c0c3e0a;
case 0x0c0c3e0cu: goto P_0c0c3e0c;
case 0x0c0c3e0eu: goto P_0c0c3e0e;
case 0x0c0c3e10u: goto P_0c0c3e10;
case 0x0c0c3e12u: goto P_0c0c3e12;
case 0x0c0c3e14u: goto P_0c0c3e14;
case 0x0c0c3e16u: goto P_0c0c3e16;
case 0x0c0c3e18u: goto P_0c0c3e18;
case 0x0c0c3e1au: goto P_0c0c3e1a;
case 0x0c0c3e1cu: goto P_0c0c3e1c;
case 0x0c0c3e1eu: goto P_0c0c3e1e;
case 0x0c0c3e20u: goto P_0c0c3e20;
case 0x0c0c3e22u: goto P_0c0c3e22;
case 0x0c0c3e24u: goto P_0c0c3e24;
case 0x0c0c3e26u: goto P_0c0c3e26;
case 0x0c0c3e28u: goto P_0c0c3e28;
case 0x0c0c3e2au: goto P_0c0c3e2a;
case 0x0c0c3e2cu: goto P_0c0c3e2c;
case 0x0c0c3e2eu: goto P_0c0c3e2e;
case 0x0c0c3e30u: goto P_0c0c3e30;
case 0x0c0c3e32u: goto P_0c0c3e32;
case 0x0c0c3e34u: goto P_0c0c3e34;
case 0x0c0c3e36u: goto P_0c0c3e36;
case 0x0c0c3e38u: goto P_0c0c3e38;
case 0x0c0c3e3au: goto P_0c0c3e3a;
case 0x0c0c3e3cu: goto P_0c0c3e3c;
case 0x0c0c3e3eu: goto P_0c0c3e3e;
case 0x0c0c3e40u: goto P_0c0c3e40;
case 0x0c0c3e42u: goto P_0c0c3e42;
case 0x0c0c3e44u: goto P_0c0c3e44;
case 0x0c0c3e46u: goto P_0c0c3e46;
case 0x0c0c3e48u: goto P_0c0c3e48;
case 0x0c0c3e4au: goto P_0c0c3e4a;
case 0x0c0c3e4cu: goto P_0c0c3e4c;
case 0x0c0c3e4eu: goto P_0c0c3e4e;
case 0x0c0c3e50u: goto P_0c0c3e50;
case 0x0c0c3e52u: goto P_0c0c3e52;
case 0x0c0c3e54u: goto P_0c0c3e54;
case 0x0c0c3e56u: goto P_0c0c3e56;
case 0x0c0c3e58u: goto P_0c0c3e58;
case 0x0c0c3e5au: goto P_0c0c3e5a;
case 0x0c0c3e5cu: goto P_0c0c3e5c;
case 0x0c0c3e5eu: goto P_0c0c3e5e;
case 0x0c0c3e7cu: goto P_0c0c3e7c;
case 0x0c0c3e7eu: goto P_0c0c3e7e;
case 0x0c0c3e80u: goto P_0c0c3e80;
case 0x0c0c3e82u: goto P_0c0c3e82;
case 0x0c0c3e84u: goto P_0c0c3e84;
case 0x0c0c3e86u: goto P_0c0c3e86;
case 0x0c0c3e88u: goto P_0c0c3e88;
case 0x0c0c3e8au: goto P_0c0c3e8a;
case 0x0c0c3e8cu: goto P_0c0c3e8c;
case 0x0c0c3e8eu: goto P_0c0c3e8e;
case 0x0c0c3e90u: goto P_0c0c3e90;
case 0x0c0c3e92u: goto P_0c0c3e92;
case 0x0c0c3e94u: goto P_0c0c3e94;
case 0x0c0c3e96u: goto P_0c0c3e96;
case 0x0c0c3e98u: goto P_0c0c3e98;
case 0x0c0c3e9au: goto P_0c0c3e9a;
case 0x0c0c3e9cu: goto P_0c0c3e9c;
case 0x0c0c3e9eu: goto P_0c0c3e9e;
case 0x0c0c3ea0u: goto P_0c0c3ea0;
case 0x0c0c3ea2u: goto P_0c0c3ea2;
case 0x0c0c3ea4u: goto P_0c0c3ea4;
case 0x0c0c3ea6u: goto P_0c0c3ea6;
case 0x0c0c3ea8u: goto P_0c0c3ea8;
case 0x0c0c3eaau: goto P_0c0c3eaa;
case 0x0c0c3eacu: goto P_0c0c3eac;
case 0x0c0c3eaeu: goto P_0c0c3eae;
case 0x0c0c3eb0u: goto P_0c0c3eb0;
case 0x0c0c3eb2u: goto P_0c0c3eb2;
case 0x0c0c3eb4u: goto P_0c0c3eb4;
case 0x0c0c3eb6u: goto P_0c0c3eb6;
case 0x0c0c3eb8u: goto P_0c0c3eb8;
case 0x0c0c3ebau: goto P_0c0c3eba;
case 0x0c0c3ebcu: goto P_0c0c3ebc;
case 0x0c0c3ebeu: goto P_0c0c3ebe;
case 0x0c0c3ec0u: goto P_0c0c3ec0;
case 0x0c0c3ec2u: goto P_0c0c3ec2;
case 0x0c0c3ec4u: goto P_0c0c3ec4;
case 0x0c0c3ec6u: goto P_0c0c3ec6;
case 0x0c0c3ec8u: goto P_0c0c3ec8;
case 0x0c0c3ecau: goto P_0c0c3eca;
case 0x0c0c3eccu: goto P_0c0c3ecc;
case 0x0c0c3eceu: goto P_0c0c3ece;
case 0x0c0c3ed0u: goto P_0c0c3ed0;
case 0x0c0c3ed2u: goto P_0c0c3ed2;
case 0x0c0c3ed4u: goto P_0c0c3ed4;
case 0x0c0c3ed6u: goto P_0c0c3ed6;
case 0x0c0c3ed8u: goto P_0c0c3ed8;
case 0x0c0c3edau: goto P_0c0c3eda;
case 0x0c0c3edcu: goto P_0c0c3edc;
case 0x0c0c3edeu: goto P_0c0c3ede;
case 0x0c0c3ee0u: goto P_0c0c3ee0;
case 0x0c0c3ee2u: goto P_0c0c3ee2;
case 0x0c0c3ee4u: goto P_0c0c3ee4;
case 0x0c0c3ee6u: goto P_0c0c3ee6;
case 0x0c0c3ee8u: goto P_0c0c3ee8;
case 0x0c0c3eeau: goto P_0c0c3eea;
case 0x0c0c3eecu: goto P_0c0c3eec;
case 0x0c0c3eeeu: goto P_0c0c3eee;
case 0x0c0c3ef0u: goto P_0c0c3ef0;
case 0x0c0c3ef2u: goto P_0c0c3ef2;
case 0x0c0c3ef4u: goto P_0c0c3ef4;
case 0x0c0c3ef6u: goto P_0c0c3ef6;
case 0x0c0c3ef8u: goto P_0c0c3ef8;
case 0x0c0c3efau: goto P_0c0c3efa;
case 0x0c0c3efcu: goto P_0c0c3efc;
case 0x0c0c3efeu: goto P_0c0c3efe;
case 0x0c0c3f00u: goto P_0c0c3f00;
case 0x0c0c3f02u: goto P_0c0c3f02;
case 0x0c0c3f04u: goto P_0c0c3f04;
case 0x0c0c3f06u: goto P_0c0c3f06;
case 0x0c0c3f08u: goto P_0c0c3f08;
case 0x0c0c3f0au: goto P_0c0c3f0a;
case 0x0c0c3f0cu: goto P_0c0c3f0c;
case 0x0c0c3f0eu: goto P_0c0c3f0e;
case 0x0c0c3f10u: goto P_0c0c3f10;
case 0x0c0c3f12u: goto P_0c0c3f12;
case 0x0c0c3f14u: goto P_0c0c3f14;
case 0x0c0c3f16u: goto P_0c0c3f16;
case 0x0c0c3f18u: goto P_0c0c3f18;
case 0x0c0c3f1au: goto P_0c0c3f1a;
case 0x0c0c3f1cu: goto P_0c0c3f1c;
case 0x0c0c3f1eu: goto P_0c0c3f1e;
case 0x0c0c3f20u: goto P_0c0c3f20;
case 0x0c0c3f22u: goto P_0c0c3f22;
case 0x0c0c3f24u: goto P_0c0c3f24;
case 0x0c0c3f26u: goto P_0c0c3f26;
case 0x0c0c3f28u: goto P_0c0c3f28;
case 0x0c0c3f2au: goto P_0c0c3f2a;
case 0x0c0c3f2cu: goto P_0c0c3f2c;
case 0x0c0c3f2eu: goto P_0c0c3f2e;
case 0x0c0c3f30u: goto P_0c0c3f30;
case 0x0c0c3f32u: goto P_0c0c3f32;
case 0x0c0c3f34u: goto P_0c0c3f34;
case 0x0c0c3f36u: goto P_0c0c3f36;
case 0x0c0c3f48u: goto P_0c0c3f48;
case 0x0c0c3f4au: goto P_0c0c3f4a;
case 0x0c0c3f4cu: goto P_0c0c3f4c;
case 0x0c0c3f4eu: goto P_0c0c3f4e;
case 0x0c0c3f50u: goto P_0c0c3f50;
case 0x0c0c3f52u: goto P_0c0c3f52;
case 0x0c0c3f54u: goto P_0c0c3f54;
case 0x0c0c3f56u: goto P_0c0c3f56;
case 0x0c0c3f58u: goto P_0c0c3f58;
case 0x0c0c3f5au: goto P_0c0c3f5a;
case 0x0c0c3f5cu: goto P_0c0c3f5c;
case 0x0c0c3f5eu: goto P_0c0c3f5e;
case 0x0c0c3f60u: goto P_0c0c3f60;
case 0x0c0c3f62u: goto P_0c0c3f62;
case 0x0c0c3f64u: goto P_0c0c3f64;
case 0x0c0c3f66u: goto P_0c0c3f66;
case 0x0c0c3f68u: goto P_0c0c3f68;
case 0x0c0c3f6au: goto P_0c0c3f6a;
case 0x0c0c3f6cu: goto P_0c0c3f6c;
case 0x0c0c3f6eu: goto P_0c0c3f6e;
case 0x0c0c3f70u: goto P_0c0c3f70;
case 0x0c0c3f72u: goto P_0c0c3f72;
case 0x0c0c3f74u: goto P_0c0c3f74;
case 0x0c0c3f76u: goto P_0c0c3f76;
case 0x0c0c3f78u: goto P_0c0c3f78;
case 0x0c0c3f7au: goto P_0c0c3f7a;
case 0x0c0c3f7cu: goto P_0c0c3f7c;
case 0x0c0c3f7eu: goto P_0c0c3f7e;
case 0x0c0c3f80u: goto P_0c0c3f80;
case 0x0c0c3f82u: goto P_0c0c3f82;
case 0x0c0c3f84u: goto P_0c0c3f84;
case 0x0c0c3f86u: goto P_0c0c3f86;
case 0x0c0c3f88u: goto P_0c0c3f88;
case 0x0c0c3f8au: goto P_0c0c3f8a;
case 0x0c0c3f8cu: goto P_0c0c3f8c;
case 0x0c0c3f8eu: goto P_0c0c3f8e;
case 0x0c0c3f90u: goto P_0c0c3f90;
case 0x0c0c3f92u: goto P_0c0c3f92;
case 0x0c0c3f94u: goto P_0c0c3f94;
case 0x0c0c3f96u: goto P_0c0c3f96;
case 0x0c0c3f98u: goto P_0c0c3f98;
case 0x0c0c3f9au: goto P_0c0c3f9a;
case 0x0c0c3f9cu: goto P_0c0c3f9c;
case 0x0c0c3f9eu: goto P_0c0c3f9e;
case 0x0c0c3fa0u: goto P_0c0c3fa0;
case 0x0c0c3fa2u: goto P_0c0c3fa2;
case 0x0c0c3fa4u: goto P_0c0c3fa4;
case 0x0c0c3fa6u: goto P_0c0c3fa6;
case 0x0c0c3fa8u: goto P_0c0c3fa8;
case 0x0c0c3faau: goto P_0c0c3faa;
case 0x0c0c3facu: goto P_0c0c3fac;
case 0x0c0c3faeu: goto P_0c0c3fae;
case 0x0c0c3fb0u: goto P_0c0c3fb0;
case 0x0c0c3fb2u: goto P_0c0c3fb2;
case 0x0c0c3fb4u: goto P_0c0c3fb4;
case 0x0c0c3fb6u: goto P_0c0c3fb6;
case 0x0c0c3fb8u: goto P_0c0c3fb8;
case 0x0c0c3fbau: goto P_0c0c3fba;
case 0x0c0c3fbcu: goto P_0c0c3fbc;
case 0x0c0c3fbeu: goto P_0c0c3fbe;
case 0x0c0c3fc0u: goto P_0c0c3fc0;
case 0x0c0c3fc2u: goto P_0c0c3fc2;
case 0x0c0c3fc4u: goto P_0c0c3fc4;
case 0x0c0c3fc6u: goto P_0c0c3fc6;
case 0x0c0c3fc8u: goto P_0c0c3fc8;
case 0x0c0c3fcau: goto P_0c0c3fca;
case 0x0c0c3fccu: goto P_0c0c3fcc;
case 0x0c0c3fceu: goto P_0c0c3fce;
case 0x0c0c3fd0u: goto P_0c0c3fd0;
case 0x0c0c3fd2u: goto P_0c0c3fd2;
case 0x0c0c3fd4u: goto P_0c0c3fd4;
case 0x0c0c3fd6u: goto P_0c0c3fd6;
case 0x0c0c3fd8u: goto P_0c0c3fd8;
case 0x0c0c3fdau: goto P_0c0c3fda;
case 0x0c0c3fdcu: goto P_0c0c3fdc;
case 0x0c0c3fdeu: goto P_0c0c3fde;
case 0x0c0c3fe0u: goto P_0c0c3fe0;
case 0x0c0c3fecu: goto P_0c0c3fec;
case 0x0c0c3feeu: goto P_0c0c3fee;
case 0x0c0c3ff0u: goto P_0c0c3ff0;
case 0x0c0c3ff2u: goto P_0c0c3ff2;
case 0x0c0c3ff4u: goto P_0c0c3ff4;
case 0x0c0c3ff6u: goto P_0c0c3ff6;
case 0x0c0c3ff8u: goto P_0c0c3ff8;
case 0x0c0c3ffau: goto P_0c0c3ffa;
case 0x0c0c3ffcu: goto P_0c0c3ffc;
case 0x0c0c3ffeu: goto P_0c0c3ffe;
case 0x0c0c4000u: goto P_0c0c4000;
case 0x0c0c4002u: goto P_0c0c4002;
case 0x0c0c4004u: goto P_0c0c4004;
case 0x0c0c4006u: goto P_0c0c4006;
case 0x0c0c4008u: goto P_0c0c4008;
case 0x0c0c400au: goto P_0c0c400a;
case 0x0c0c400cu: goto P_0c0c400c;
case 0x0c0c400eu: goto P_0c0c400e;
case 0x0c0c4010u: goto P_0c0c4010;
case 0x0c0c4012u: goto P_0c0c4012;
case 0x0c0c4014u: goto P_0c0c4014;
case 0x0c0c4016u: goto P_0c0c4016;
case 0x0c0c4018u: goto P_0c0c4018;
case 0x0c0c401au: goto P_0c0c401a;
case 0x0c0c401cu: goto P_0c0c401c;
case 0x0c0c401eu: goto P_0c0c401e;
case 0x0c0c4020u: goto P_0c0c4020;
case 0x0c0c4022u: goto P_0c0c4022;
case 0x0c0c4024u: goto P_0c0c4024;
case 0x0c0c4026u: goto P_0c0c4026;
case 0x0c0c4028u: goto P_0c0c4028;
case 0x0c0c402au: goto P_0c0c402a;
case 0x0c0c402cu: goto P_0c0c402c;
case 0x0c0c402eu: goto P_0c0c402e;
case 0x0c0c4030u: goto P_0c0c4030;
case 0x0c0c4032u: goto P_0c0c4032;
case 0x0c0c4034u: goto P_0c0c4034;
case 0x0c0c4036u: goto P_0c0c4036;
case 0x0c0c4038u: goto P_0c0c4038;
case 0x0c0c403au: goto P_0c0c403a;
case 0x0c0c403cu: goto P_0c0c403c;
case 0x0c0c403eu: goto P_0c0c403e;
case 0x0c0c4040u: goto P_0c0c4040;
case 0x0c0c4042u: goto P_0c0c4042;
case 0x0c0c4044u: goto P_0c0c4044;
case 0x0c0c4046u: goto P_0c0c4046;
case 0x0c0c4048u: goto P_0c0c4048;
case 0x0c0c404au: goto P_0c0c404a;
case 0x0c0c404cu: goto P_0c0c404c;
case 0x0c0c404eu: goto P_0c0c404e;
case 0x0c0c4050u: goto P_0c0c4050;
case 0x0c0c4052u: goto P_0c0c4052;
case 0x0c0c4054u: goto P_0c0c4054;
case 0x0c0c4056u: goto P_0c0c4056;
case 0x0c0c4058u: goto P_0c0c4058;
case 0x0c0c405au: goto P_0c0c405a;
case 0x0c0c405cu: goto P_0c0c405c;
case 0x0c0c405eu: goto P_0c0c405e;
case 0x0c0c4060u: goto P_0c0c4060;
case 0x0c0c4062u: goto P_0c0c4062;
case 0x0c0c4064u: goto P_0c0c4064;
case 0x0c0c4066u: goto P_0c0c4066;
case 0x0c0c4068u: goto P_0c0c4068;
case 0x0c0c406au: goto P_0c0c406a;
case 0x0c0c406cu: goto P_0c0c406c;
case 0x0c0c406eu: goto P_0c0c406e;
case 0x0c0c4070u: goto P_0c0c4070;
case 0x0c0c4072u: goto P_0c0c4072;
case 0x0c0c4074u: goto P_0c0c4074;
case 0x0c0c4076u: goto P_0c0c4076;
case 0x0c0c4078u: goto P_0c0c4078;
case 0x0c0c407au: goto P_0c0c407a;
case 0x0c0c407cu: goto P_0c0c407c;
case 0x0c0c407eu: goto P_0c0c407e;
case 0x0c0c4080u: goto P_0c0c4080;
case 0x0c0c4082u: goto P_0c0c4082;
case 0x0c0c4084u: goto P_0c0c4084;
case 0x0c0c4086u: goto P_0c0c4086;
case 0x0c0c4088u: goto P_0c0c4088;
case 0x0c0c408au: goto P_0c0c408a;
case 0x0c0c408cu: goto P_0c0c408c;
case 0x0c0c408eu: goto P_0c0c408e;
case 0x0c0c4090u: goto P_0c0c4090;
case 0x0c0c4092u: goto P_0c0c4092;
case 0x0c0c4094u: goto P_0c0c4094;
case 0x0c0c4096u: goto P_0c0c4096;
case 0x0c0c4098u: goto P_0c0c4098;
case 0x0c0c409au: goto P_0c0c409a;
case 0x0c0c409cu: goto P_0c0c409c;
case 0x0c0c409eu: goto P_0c0c409e;
case 0x0c0c40a0u: goto P_0c0c40a0;
case 0x0c0c40a2u: goto P_0c0c40a2;
case 0x0c0c40a4u: goto P_0c0c40a4;
case 0x0c0c40a6u: goto P_0c0c40a6;
case 0x0c0c40a8u: goto P_0c0c40a8;
case 0x0c0c40aau: goto P_0c0c40aa;
case 0x0c0c40acu: goto P_0c0c40ac;
case 0x0c0c40aeu: goto P_0c0c40ae;
case 0x0c0c40b0u: goto P_0c0c40b0;
case 0x0c0c40b2u: goto P_0c0c40b2;
case 0x0c0c40b4u: goto P_0c0c40b4;
case 0x0c0c40b6u: goto P_0c0c40b6;
case 0x0c0c40b8u: goto P_0c0c40b8;
case 0x0c0c40bau: goto P_0c0c40ba;
case 0x0c0c40bcu: goto P_0c0c40bc;
case 0x0c0c40beu: goto P_0c0c40be;
case 0x0c0c40c0u: goto P_0c0c40c0;
case 0x0c0c40c2u: goto P_0c0c40c2;
case 0x0c0c40c4u: goto P_0c0c40c4;
case 0x0c0c40c6u: goto P_0c0c40c6;
case 0x0c0c40c8u: goto P_0c0c40c8;
case 0x0c0c40cau: goto P_0c0c40ca;
case 0x0c0c40ccu: goto P_0c0c40cc;
case 0x0c0c40ceu: goto P_0c0c40ce;
case 0x0c0c40d0u: goto P_0c0c40d0;
case 0x0c0c40fcu: goto P_0c0c40fc;
case 0x0c0c40feu: goto P_0c0c40fe;
case 0x0c0c4100u: goto P_0c0c4100;
case 0x0c0c4102u: goto P_0c0c4102;
case 0x0c0c4104u: goto P_0c0c4104;
case 0x0c0c4106u: goto P_0c0c4106;
case 0x0c0c4108u: goto P_0c0c4108;
case 0x0c0c410au: goto P_0c0c410a;
case 0x0c0c410cu: goto P_0c0c410c;
case 0x0c0c410eu: goto P_0c0c410e;
case 0x0c0c4110u: goto P_0c0c4110;
case 0x0c0c4112u: goto P_0c0c4112;
case 0x0c0c4114u: goto P_0c0c4114;
case 0x0c0c4116u: goto P_0c0c4116;
case 0x0c0c4118u: goto P_0c0c4118;
case 0x0c0c411au: goto P_0c0c411a;
case 0x0c0c411cu: goto P_0c0c411c;
case 0x0c0c411eu: goto P_0c0c411e;
case 0x0c0c4120u: goto P_0c0c4120;
case 0x0c0c4122u: goto P_0c0c4122;
case 0x0c0c4124u: goto P_0c0c4124;
case 0x0c0c4126u: goto P_0c0c4126;
case 0x0c0c4128u: goto P_0c0c4128;
case 0x0c0c412au: goto P_0c0c412a;
case 0x0c0c412cu: goto P_0c0c412c;
case 0x0c0c412eu: goto P_0c0c412e;
case 0x0c0c4130u: goto P_0c0c4130;
case 0x0c0c4132u: goto P_0c0c4132;
case 0x0c0c4134u: goto P_0c0c4134;
case 0x0c0c4136u: goto P_0c0c4136;
case 0x0c0c4138u: goto P_0c0c4138;
case 0x0c0c413au: goto P_0c0c413a;
case 0x0c0c413cu: goto P_0c0c413c;
case 0x0c0c413eu: goto P_0c0c413e;
case 0x0c0c4140u: goto P_0c0c4140;
case 0x0c0c4142u: goto P_0c0c4142;
case 0x0c0c4144u: goto P_0c0c4144;
case 0x0c0c4146u: goto P_0c0c4146;
case 0x0c0c4148u: goto P_0c0c4148;
case 0x0c0c414au: goto P_0c0c414a;
case 0x0c0c414cu: goto P_0c0c414c;
case 0x0c0c414eu: goto P_0c0c414e;
case 0x0c0c4150u: goto P_0c0c4150;
case 0x0c0c4152u: goto P_0c0c4152;
case 0x0c0c4154u: goto P_0c0c4154;
case 0x0c0c4156u: goto P_0c0c4156;
case 0x0c0c4158u: goto P_0c0c4158;
case 0x0c0c415au: goto P_0c0c415a;
case 0x0c0c415cu: goto P_0c0c415c;
case 0x0c0c415eu: goto P_0c0c415e;
case 0x0c0c4160u: goto P_0c0c4160;
case 0x0c0c4162u: goto P_0c0c4162;
case 0x0c0c4164u: goto P_0c0c4164;
case 0x0c0c4166u: goto P_0c0c4166;
case 0x0c0c4168u: goto P_0c0c4168;
case 0x0c0c416au: goto P_0c0c416a;
case 0x0c0c416cu: goto P_0c0c416c;
case 0x0c0c416eu: goto P_0c0c416e;
case 0x0c0c4170u: goto P_0c0c4170;
case 0x0c0c4172u: goto P_0c0c4172;
case 0x0c0c4174u: goto P_0c0c4174;
case 0x0c0c4176u: goto P_0c0c4176;
case 0x0c0c4178u: goto P_0c0c4178;
case 0x0c0c417au: goto P_0c0c417a;
case 0x0c0c417cu: goto P_0c0c417c;
case 0x0c0c417eu: goto P_0c0c417e;
case 0x0c0c4180u: goto P_0c0c4180;
case 0x0c0c4182u: goto P_0c0c4182;
case 0x0c0c4184u: goto P_0c0c4184;
case 0x0c0c4186u: goto P_0c0c4186;
case 0x0c0c4188u: goto P_0c0c4188;
case 0x0c0c418au: goto P_0c0c418a;
case 0x0c0c418cu: goto P_0c0c418c;
case 0x0c0c418eu: goto P_0c0c418e;
case 0x0c0c4190u: goto P_0c0c4190;
case 0x0c0c4192u: goto P_0c0c4192;
case 0x0c0c4194u: goto P_0c0c4194;
case 0x0c0c4196u: goto P_0c0c4196;
case 0x0c0c4198u: goto P_0c0c4198;
case 0x0c0c419au: goto P_0c0c419a;
case 0x0c0c419cu: goto P_0c0c419c;
case 0x0c0c419eu: goto P_0c0c419e;
case 0x0c0c41a0u: goto P_0c0c41a0;
case 0x0c0c41a2u: goto P_0c0c41a2;
case 0x0c0c41a4u: goto P_0c0c41a4;
case 0x0c0c41a6u: goto P_0c0c41a6;
case 0x0c0c41a8u: goto P_0c0c41a8;
case 0x0c0c41aau: goto P_0c0c41aa;
case 0x0c0c41acu: goto P_0c0c41ac;
case 0x0c0c41aeu: goto P_0c0c41ae;
case 0x0c0c41b0u: goto P_0c0c41b0;
case 0x0c0c41b2u: goto P_0c0c41b2;
case 0x0c0c41b4u: goto P_0c0c41b4;
case 0x0c0c41b6u: goto P_0c0c41b6;
case 0x0c0c41b8u: goto P_0c0c41b8;
case 0x0c0c41bau: goto P_0c0c41ba;
case 0x0c0c41bcu: goto P_0c0c41bc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c3b40: /* original 2fe6, guest PC 0x0c0c3b40 */
if(!s->budget--) { s->failed_pc=0x0c0c3b40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3b42;
P_0c0c3b42: /* original 2fd6, guest PC 0x0c0c3b42 */
if(!s->budget--) { s->failed_pc=0x0c0c3b42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3b44;
P_0c0c3b44: /* original 2fc6, guest PC 0x0c0c3b44 */
if(!s->budget--) { s->failed_pc=0x0c0c3b44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3b46;
P_0c0c3b46: /* original d613, guest PC 0x0c0c3b46 */
if(!s->budget--) { s->failed_pc=0x0c0c3b46u; return 0; }
r[6]=read(ram,0x0c0c3b94u,4);
goto P_0c0c3b48;
P_0c0c3b48: /* original 7ff8, guest PC 0x0c0c3b48 */
if(!s->budget--) { s->failed_pc=0x0c0c3b48u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c3b4a;
P_0c0c3b4a: /* original 901b, guest PC 0x0c0c3b4a */
if(!s->budget--) { s->failed_pc=0x0c0c3b4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3b84u,2);
goto P_0c0c3b4c;
P_0c0c3b4c: /* original d412, guest PC 0x0c0c3b4c */
if(!s->budget--) { s->failed_pc=0x0c0c3b4cu; return 0; }
r[4]=read(ram,0x0c0c3b98u,4);
goto P_0c0c3b4e;
P_0c0c3b4e: /* original 056e, guest PC 0x0c0c3b4e */
if(!s->budget--) { s->failed_pc=0x0c0c3b4eu; return 0; }
r[5]=read(ram,r[6]+r[0],4);
goto P_0c0c3b50;
P_0c0c3b50: /* original e029, guest PC 0x0c0c3b50 */
if(!s->budget--) { s->failed_pc=0x0c0c3b50u; return 0; }
r[0]=0x00000029u;
goto P_0c0c3b52;
P_0c0c3b52: /* original 6743, guest PC 0x0c0c3b52 */
if(!s->budget--) { s->failed_pc=0x0c0c3b52u; return 0; }
r[7]=r[4];
goto P_0c0c3b54;
P_0c0c3b54: /* original 0c7c, guest PC 0x0c0c3b54 */
if(!s->budget--) { s->failed_pc=0x0c0c3b54u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0c3b56;
P_0c0c3b56: /* original e02a, guest PC 0x0c0c3b56 */
if(!s->budget--) { s->failed_pc=0x0c0c3b56u; return 0; }
r[0]=0x0000002au;
goto P_0c0c3b58;
P_0c0c3b58: /* original 9d15, guest PC 0x0c0c3b58 */
if(!s->budget--) { s->failed_pc=0x0c0c3b58u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3b86u,2);
goto P_0c0c3b5a;
P_0c0c3b5a: /* original 6ccc, guest PC 0x0c0c3b5a */
if(!s->budget--) { s->failed_pc=0x0c0c3b5au; return 0; }
r[12]=r[12]&255u;
goto P_0c0c3b5c;
P_0c0c3b5c: /* original 077c, guest PC 0x0c0c3b5c */
if(!s->budget--) { s->failed_pc=0x0c0c3b5cu; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c0c3b5e;
P_0c0c3b5e: /* original 6ec3, guest PC 0x0c0c3b5e */
if(!s->budget--) { s->failed_pc=0x0c0c3b5eu; return 0; }
r[14]=r[12];
goto P_0c0c3b60;
P_0c0c3b60: /* original 7efd, guest PC 0x0c0c3b60 */
if(!s->budget--) { s->failed_pc=0x0c0c3b60u; return 0; }
r[14]+=0xfffffffdu;
goto P_0c0c3b62;
P_0c0c3b62: /* original 2ee8, guest PC 0x0c0c3b62 */
if(!s->budget--) { s->failed_pc=0x0c0c3b62u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c3b64;
P_0c0c3b64: /* original 3d4c, guest PC 0x0c0c3b64 */
if(!s->budget--) { s->failed_pc=0x0c0c3b64u; return 0; }
r[13]+=r[4];
goto P_0c0c3b66;
P_0c0c3b66: /* original 677c, guest PC 0x0c0c3b66 */
if(!s->budget--) { s->failed_pc=0x0c0c3b66u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3b68;
P_0c0c3b68: /* original 8d02, guest PC 0x0c0c3b68 */
if(!s->budget--) { s->failed_pc=0x0c0c3b68u; return 0; }
cond=r[17]&1u;
r[7]+=0xfffffffeu;
if(cond) { goto P_0c0c3b70; }
goto P_0c0c3b6c;
P_0c0c3b6a: /* original 77fe, guest PC 0x0c0c3b6a */
if(!s->budget--) { s->failed_pc=0x0c0c3b6au; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0c3b6c;
P_0c0c3b6c: /* original 67c3, guest PC 0x0c0c3b6c */
if(!s->budget--) { s->failed_pc=0x0c0c3b6cu; return 0; }
r[7]=r[12];
goto P_0c0c3b6e;
P_0c0c3b6e: /* original 77fe, guest PC 0x0c0c3b6e */
if(!s->budget--) { s->failed_pc=0x0c0c3b6eu; return 0; }
r[7]+=0xfffffffeu;
goto P_0c0c3b70;
P_0c0c3b70: /* original 5342, guest PC 0x0c0c3b70 */
if(!s->budget--) { s->failed_pc=0x0c0c3b70u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c0c3b72;
P_0c0c3b72: /* original 6033, guest PC 0x0c0c3b72 */
if(!s->budget--) { s->failed_pc=0x0c0c3b72u; return 0; }
r[0]=r[3];
goto P_0c0c3b74;
P_0c0c3b74: /* original c804, guest PC 0x0c0c3b74 */
if(!s->budget--) { s->failed_pc=0x0c0c3b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c0c3b76;
P_0c0c3b76: /* original 2f32, guest PC 0x0c0c3b76 */
if(!s->budget--) { s->failed_pc=0x0c0c3b76u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3b78;
P_0c0c3b78: /* original 8939, guest PC 0x0c0c3b78 */
if(!s->budget--) { s->failed_pc=0x0c0c3b78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3bee; }
goto P_0c0c3b7a;
P_0c0c3b7a: /* original 2778, guest PC 0x0c0c3b7a */
if(!s->budget--) { s->failed_pc=0x0c0c3b7au; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3b7c;
P_0c0c3b7c: /* original 8b12, guest PC 0x0c0c3b7c */
if(!s->budget--) { s->failed_pc=0x0c0c3b7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ba4; }
goto P_0c0c3b7e;
P_0c0c3b7e: /* original 9c03, guest PC 0x0c0c3b7e */
if(!s->budget--) { s->failed_pc=0x0c0c3b7eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3b88u,2);
goto P_0c0c3b80;
P_0c0c3b80: /* original a011, guest PC 0x0c0c3b80 */
if(!s->budget--) { s->failed_pc=0x0c0c3b80u; return 0; }
goto P_0c0c3ba6;
P_0c0c3b82: /* original 0009, guest PC 0x0c0c3b82 */
if(!s->budget--) { s->failed_pc=0x0c0c3b82u; return 0; }
if(!vf3_matrix_family(0x0c0c3b84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3b84u; return 0; } return 1;
P_0c0c3ba4: /* original 9c75, guest PC 0x0c0c3ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ba4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c92u,2);
goto P_0c0c3ba6;
P_0c0c3ba6: /* original 9075, guest PC 0x0c0c3ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ba6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c94u,2);
goto P_0c0c3ba8;
P_0c0c3ba8: /* original ee00, guest PC 0x0c0c3ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ba8u; return 0; }
r[14]=0x00000000u;
goto P_0c0c3baa;
P_0c0c3baa: /* original 3c4c, guest PC 0x0c0c3baa */
if(!s->budget--) { s->failed_pc=0x0c0c3baau; return 0; }
r[12]+=r[4];
goto P_0c0c3bac;
P_0c0c3bac: /* original 034c, guest PC 0x0c0c3bac */
if(!s->budget--) { s->failed_pc=0x0c0c3bacu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c3bae;
P_0c0c3bae: /* original 2f32, guest PC 0x0c0c3bae */
if(!s->budget--) { s->failed_pc=0x0c0c3baeu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3bb0;
P_0c0c3bb0: /* original 60e3, guest PC 0x0c0c3bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb0u; return 0; }
r[0]=r[14];
goto P_0c0c3bb2;
P_0c0c3bb2: /* original 04cc, guest PC 0x0c0c3bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c3bb4;
P_0c0c3bb4: /* original e30d, guest PC 0x0c0c3bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb4u; return 0; }
r[3]=0x0000000du;
goto P_0c0c3bb6;
P_0c0c3bb6: /* original 644c, guest PC 0x0c0c3bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb6u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3bb8;
P_0c0c3bb8: /* original 3432, guest PC 0x0c0c3bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bb8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c0c3bba;
P_0c0c3bba: /* original 8b00, guest PC 0x0c0c3bba */
if(!s->budget--) { s->failed_pc=0x0c0c3bbau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3bbe; }
goto P_0c0c3bbc;
P_0c0c3bbc: /* original 74f3, guest PC 0x0c0c3bbc */
if(!s->budget--) { s->failed_pc=0x0c0c3bbcu; return 0; }
r[4]+=0xfffffff3u;
goto P_0c0c3bbe;
P_0c0c3bbe: /* original 6743, guest PC 0x0c0c3bbe */
if(!s->budget--) { s->failed_pc=0x0c0c3bbeu; return 0; }
r[7]=r[4];
goto P_0c0c3bc0;
P_0c0c3bc0: /* original 37dc, guest PC 0x0c0c3bc0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc0u; return 0; }
r[7]+=r[13];
goto P_0c0c3bc2;
P_0c0c3bc2: /* original 1f71, guest PC 0x0c0c3bc2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc2u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0c3bc4;
P_0c0c3bc4: /* original 6770, guest PC 0x0c0c3bc4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0c3bc6;
P_0c0c3bc6: /* original 53f1, guest PC 0x0c0c3bc6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c3bc8;
P_0c0c3bc8: /* original 677c, guest PC 0x0c0c3bc8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bc8u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3bca;
P_0c0c3bca: /* original 77ff, guest PC 0x0c0c3bca */
if(!s->budget--) { s->failed_pc=0x0c0c3bcau; return 0; }
r[7]+=0xffffffffu;
goto P_0c0c3bcc;
P_0c0c3bcc: /* original 2370, guest PC 0x0c0c3bcc */
if(!s->budget--) { s->failed_pc=0x0c0c3bccu; return 0; }
write(ram,r[3],r[7],1);
goto P_0c0c3bce;
P_0c0c3bce: /* original e300, guest PC 0x0c0c3bce */
if(!s->budget--) { s->failed_pc=0x0c0c3bceu; return 0; }
r[3]=0x00000000u;
goto P_0c0c3bd0;
P_0c0c3bd0: /* original 3736, guest PC 0x0c0c3bd0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd0u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>r[3])!=0);
goto P_0c0c3bd2;
P_0c0c3bd2: /* original 8d07, guest PC 0x0c0c3bd2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd2u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000001u;
if(cond) { goto P_0c0c3be4; }
goto P_0c0c3bd6;
P_0c0c3bd4: /* original 7e01, guest PC 0x0c0c3bd4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd4u; return 0; }
r[14]+=0x00000001u;
goto P_0c0c3bd6;
P_0c0c3bd6: /* original d231, guest PC 0x0c0c3bd6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd6u; return 0; }
r[2]=read(ram,0x0c0c3c9cu,4);
goto P_0c0c3bd8;
P_0c0c3bd8: /* original 644b, guest PC 0x0c0c3bd8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bd8u; return 0; }
r[4]=0u-r[4];
goto P_0c0c3bda;
P_0c0c3bda: /* original 905c, guest PC 0x0c0c3bda */
if(!s->budget--) { s->failed_pc=0x0c0c3bdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c96u,2);
goto P_0c0c3bdc;
P_0c0c3bdc: /* original 424d, guest PC 0x0c0c3bdc */
if(!s->budget--) { s->failed_pc=0x0c0c3bdcu; return 0; }
r[2]=(r[4]&0x80000000u)?((r[4]&31u)?r[2]>>((-r[4])&31u):0):r[2]<<(r[4]&31u);
goto P_0c0c3bde;
P_0c0c3bde: /* original 6227, guest PC 0x0c0c3bde */
if(!s->budget--) { s->failed_pc=0x0c0c3bdeu; return 0; }
r[2]=~r[2];
goto P_0c0c3be0;
P_0c0c3be0: /* original 2529, guest PC 0x0c0c3be0 */
if(!s->budget--) { s->failed_pc=0x0c0c3be0u; return 0; }
r[5]&=r[2];
goto P_0c0c3be2;
P_0c0c3be2: /* original 0656, guest PC 0x0c0c3be2 */
if(!s->budget--) { s->failed_pc=0x0c0c3be2u; return 0; }
write(ram,r[6]+r[0],r[5],4);
goto P_0c0c3be4;
P_0c0c3be4: /* original 63f2, guest PC 0x0c0c3be4 */
if(!s->budget--) { s->failed_pc=0x0c0c3be4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c3be6;
P_0c0c3be6: /* original 3e32, guest PC 0x0c0c3be6 */
if(!s->budget--) { s->failed_pc=0x0c0c3be6u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[3])!=0);
goto P_0c0c3be8;
P_0c0c3be8: /* original 8be2, guest PC 0x0c0c3be8 */
if(!s->budget--) { s->failed_pc=0x0c0c3be8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3bb0; }
goto P_0c0c3bea;
P_0c0c3bea: /* original a01c, guest PC 0x0c0c3bea */
if(!s->budget--) { s->failed_pc=0x0c0c3beau; return 0; }
goto P_0c0c3c26;
P_0c0c3bec: /* original 0009, guest PC 0x0c0c3bec */
if(!s->budget--) { s->failed_pc=0x0c0c3becu; return 0; }
goto P_0c0c3bee;
P_0c0c3bee: /* original 2ee8, guest PC 0x0c0c3bee */
if(!s->budget--) { s->failed_pc=0x0c0c3beeu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c3bf0;
P_0c0c3bf0: /* original 8b19, guest PC 0x0c0c3bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3c26; }
goto P_0c0c3bf2;
P_0c0c3bf2: /* original d12b, guest PC 0x0c0c3bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf2u; return 0; }
r[1]=read(ram,0x0c0c3ca0u,4);
goto P_0c0c3bf4;
P_0c0c3bf4: /* original 2778, guest PC 0x0c0c3bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3bf6;
P_0c0c3bf6: /* original 8d02, guest PC 0x0c0c3bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf6u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[1],4);
r[4]=tmp;
if(cond) { goto P_0c0c3bfe; }
goto P_0c0c3bfa;
P_0c0c3bf8: /* original 6412, guest PC 0x0c0c3bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c3bf8u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c0c3bfa;
P_0c0c3bfa: /* original d22a, guest PC 0x0c0c3bfa */
if(!s->budget--) { s->failed_pc=0x0c0c3bfau; return 0; }
r[2]=read(ram,0x0c0c3ca4u,4);
goto P_0c0c3bfc;
P_0c0c3bfc: /* original 6422, guest PC 0x0c0c3bfc */
if(!s->budget--) { s->failed_pc=0x0c0c3bfcu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0c3bfe;
P_0c0c3bfe: /* original e061, guest PC 0x0c0c3bfe */
if(!s->budget--) { s->failed_pc=0x0c0c3bfeu; return 0; }
r[0]=0x00000061u;
goto P_0c0c3c00;
P_0c0c3c00: /* original 074c, guest PC 0x0c0c3c00 */
if(!s->budget--) { s->failed_pc=0x0c0c3c00u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c3c02;
P_0c0c3c02: /* original 677c, guest PC 0x0c0c3c02 */
if(!s->budget--) { s->failed_pc=0x0c0c3c02u; return 0; }
r[7]=r[7]&255u;
goto P_0c0c3c04;
P_0c0c3c04: /* original 6473, guest PC 0x0c0c3c04 */
if(!s->budget--) { s->failed_pc=0x0c0c3c04u; return 0; }
r[4]=r[7];
goto P_0c0c3c06;
P_0c0c3c06: /* original 34dc, guest PC 0x0c0c3c06 */
if(!s->budget--) { s->failed_pc=0x0c0c3c06u; return 0; }
r[4]+=r[13];
goto P_0c0c3c08;
P_0c0c3c08: /* original 2f42, guest PC 0x0c0c3c08 */
if(!s->budget--) { s->failed_pc=0x0c0c3c08u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c3c0a;
P_0c0c3c0a: /* original 6440, guest PC 0x0c0c3c0a */
if(!s->budget--) { s->failed_pc=0x0c0c3c0au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0c3c0c;
P_0c0c3c0c: /* original 63f2, guest PC 0x0c0c3c0c */
if(!s->budget--) { s->failed_pc=0x0c0c3c0cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0c3c0e;
P_0c0c3c0e: /* original 644c, guest PC 0x0c0c3c0e */
if(!s->budget--) { s->failed_pc=0x0c0c3c0eu; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3c10;
P_0c0c3c10: /* original 74ff, guest PC 0x0c0c3c10 */
if(!s->budget--) { s->failed_pc=0x0c0c3c10u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c3c12;
P_0c0c3c12: /* original 2448, guest PC 0x0c0c3c12 */
if(!s->budget--) { s->failed_pc=0x0c0c3c12u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3c14;
P_0c0c3c14: /* original 2340, guest PC 0x0c0c3c14 */
if(!s->budget--) { s->failed_pc=0x0c0c3c14u; return 0; }
write(ram,r[3],r[4],1);
goto P_0c0c3c16;
P_0c0c3c16: /* original 8b06, guest PC 0x0c0c3c16 */
if(!s->budget--) { s->failed_pc=0x0c0c3c16u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3c26; }
goto P_0c0c3c18;
P_0c0c3c18: /* original d320, guest PC 0x0c0c3c18 */
if(!s->budget--) { s->failed_pc=0x0c0c3c18u; return 0; }
r[3]=read(ram,0x0c0c3c9cu,4);
goto P_0c0c3c1a;
P_0c0c3c1a: /* original 677b, guest PC 0x0c0c3c1a */
if(!s->budget--) { s->failed_pc=0x0c0c3c1au; return 0; }
r[7]=0u-r[7];
goto P_0c0c3c1c;
P_0c0c3c1c: /* original 903b, guest PC 0x0c0c3c1c */
if(!s->budget--) { s->failed_pc=0x0c0c3c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c96u,2);
goto P_0c0c3c1e;
P_0c0c3c1e: /* original 437d, guest PC 0x0c0c3c1e */
if(!s->budget--) { s->failed_pc=0x0c0c3c1eu; return 0; }
r[3]=(r[7]&0x80000000u)?((r[7]&31u)?r[3]>>((-r[7])&31u):0):r[3]<<(r[7]&31u);
goto P_0c0c3c20;
P_0c0c3c20: /* original 6337, guest PC 0x0c0c3c20 */
if(!s->budget--) { s->failed_pc=0x0c0c3c20u; return 0; }
r[3]=~r[3];
goto P_0c0c3c22;
P_0c0c3c22: /* original 2539, guest PC 0x0c0c3c22 */
if(!s->budget--) { s->failed_pc=0x0c0c3c22u; return 0; }
r[5]&=r[3];
goto P_0c0c3c24;
P_0c0c3c24: /* original 0656, guest PC 0x0c0c3c24 */
if(!s->budget--) { s->failed_pc=0x0c0c3c24u; return 0; }
write(ram,r[6]+r[0],r[5],4);
goto P_0c0c3c26;
P_0c0c3c26: /* original 7f08, guest PC 0x0c0c3c26 */
if(!s->budget--) { s->failed_pc=0x0c0c3c26u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c3c28;
P_0c0c3c28: /* original 6cf6, guest PC 0x0c0c3c28 */
if(!s->budget--) { s->failed_pc=0x0c0c3c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c3c2a;
P_0c0c3c2a: /* original 6df6, guest PC 0x0c0c3c2a */
if(!s->budget--) { s->failed_pc=0x0c0c3c2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c3c2c;
P_0c0c3c2c: /* original 000b, guest PC 0x0c0c3c2c */
if(!s->budget--) { s->failed_pc=0x0c0c3c2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c3c2e: /* original 6ef6, guest PC 0x0c0c3c2e */
if(!s->budget--) { s->failed_pc=0x0c0c3c2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c3c30;
P_0c0c3c30: /* original 2fe6, guest PC 0x0c0c3c30 */
if(!s->budget--) { s->failed_pc=0x0c0c3c30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c32;
P_0c0c3c32: /* original 2fd6, guest PC 0x0c0c3c32 */
if(!s->budget--) { s->failed_pc=0x0c0c3c32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c34;
P_0c0c3c34: /* original 2fc6, guest PC 0x0c0c3c34 */
if(!s->budget--) { s->failed_pc=0x0c0c3c34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c36;
P_0c0c3c36: /* original 2fb6, guest PC 0x0c0c3c36 */
if(!s->budget--) { s->failed_pc=0x0c0c3c36u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c38;
P_0c0c3c38: /* original 2fa6, guest PC 0x0c0c3c38 */
if(!s->budget--) { s->failed_pc=0x0c0c3c38u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c3a;
P_0c0c3c3a: /* original 2f96, guest PC 0x0c0c3c3a */
if(!s->budget--) { s->failed_pc=0x0c0c3c3au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c3c;
P_0c0c3c3c: /* original 2f86, guest PC 0x0c0c3c3c */
if(!s->budget--) { s->failed_pc=0x0c0c3c3cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3c3e;
P_0c0c3c3e: /* original 4f22, guest PC 0x0c0c3c3e */
if(!s->budget--) { s->failed_pc=0x0c0c3c3eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c3c40;
P_0c0c3c40: /* original dc19, guest PC 0x0c0c3c40 */
if(!s->budget--) { s->failed_pc=0x0c0c3c40u; return 0; }
r[12]=read(ram,0x0c0c3ca8u,4);
goto P_0c0c3c42;
P_0c0c3c42: /* original d31b, guest PC 0x0c0c3c42 */
if(!s->budget--) { s->failed_pc=0x0c0c3c42u; return 0; }
r[3]=read(ram,0x0c0c3cb0u,4);
goto P_0c0c3c44;
P_0c0c3c44: /* original 7fe0, guest PC 0x0c0c3c44 */
if(!s->budget--) { s->failed_pc=0x0c0c3c44u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c0c3c46;
P_0c0c3c46: /* original de19, guest PC 0x0c0c3c46 */
if(!s->budget--) { s->failed_pc=0x0c0c3c46u; return 0; }
r[14]=read(ram,0x0c0c3cacu,4);
goto P_0c0c3c48;
P_0c0c3c48: /* original 1f37, guest PC 0x0c0c3c48 */
if(!s->budget--) { s->failed_pc=0x0c0c3c48u; return 0; }
write(ram,r[15]+28,r[3],4);
goto P_0c0c3c4a;
P_0c0c3c4a: /* original d21a, guest PC 0x0c0c3c4a */
if(!s->budget--) { s->failed_pc=0x0c0c3c4au; return 0; }
r[2]=read(ram,0x0c0c3cb4u,4);
goto P_0c0c3c4c;
P_0c0c3c4c: /* original 1f26, guest PC 0x0c0c3c4c */
if(!s->budget--) { s->failed_pc=0x0c0c3c4cu; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c0c3c4e;
P_0c0c3c4e: /* original 9023, guest PC 0x0c0c3c4e */
if(!s->budget--) { s->failed_pc=0x0c0c3c4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c98u,2);
goto P_0c0c3c50;
P_0c0c3c50: /* original 5de2, guest PC 0x0c0c3c50 */
if(!s->budget--) { s->failed_pc=0x0c0c3c50u; return 0; }
r[13]=read(ram,r[14]+8,4);
goto P_0c0c3c52;
P_0c0c3c52: /* original 0ace, guest PC 0x0c0c3c52 */
if(!s->budget--) { s->failed_pc=0x0c0c3c52u; return 0; }
r[10]=read(ram,r[12]+r[0],4);
goto P_0c0c3c54;
P_0c0c3c54: /* original 70fc, guest PC 0x0c0c3c54 */
if(!s->budget--) { s->failed_pc=0x0c0c3c54u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c3c56;
P_0c0c3c56: /* original 03ce, guest PC 0x0c0c3c56 */
if(!s->budget--) { s->failed_pc=0x0c0c3c56u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c0c3c58;
P_0c0c3c58: /* original 1f34, guest PC 0x0c0c3c58 */
if(!s->budget--) { s->failed_pc=0x0c0c3c58u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c0c3c5a;
P_0c0c3c5a: /* original d310, guest PC 0x0c0c3c5a */
if(!s->budget--) { s->failed_pc=0x0c0c3c5au; return 0; }
r[3]=read(ram,0x0c0c3c9cu,4);
goto P_0c0c3c5c;
P_0c0c3c5c: /* original 23a8, guest PC 0x0c0c3c5c */
if(!s->budget--) { s->failed_pc=0x0c0c3c5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0c3c5e;
P_0c0c3c5e: /* original 8f03, guest PC 0x0c0c3c5e */
if(!s->budget--) { s->failed_pc=0x0c0c3c5eu; return 0; }
cond=r[17]&1u;
r[8]=0x00000002u;
if(!cond) { goto P_0c0c3c68; }
goto P_0c0c3c62;
P_0c0c3c60: /* original e802, guest PC 0x0c0c3c60 */
if(!s->budget--) { s->failed_pc=0x0c0c3c60u; return 0; }
r[8]=0x00000002u;
goto P_0c0c3c62;
P_0c0c3c62: /* original e204, guest PC 0x0c0c3c62 */
if(!s->budget--) { s->failed_pc=0x0c0c3c62u; return 0; }
r[2]=0x00000004u;
goto P_0c0c3c64;
P_0c0c3c64: /* original 22a8, guest PC 0x0c0c3c64 */
if(!s->budget--) { s->failed_pc=0x0c0c3c64u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c0c3c66;
P_0c0c3c66: /* original 8929, guest PC 0x0c0c3c66 */
if(!s->budget--) { s->failed_pc=0x0c0c3c66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3cbc; }
goto P_0c0c3c68;
P_0c0c3c68: /* original 61c2, guest PC 0x0c0c3c68 */
if(!s->budget--) { s->failed_pc=0x0c0c3c68u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c3c6a;
P_0c0c3c6a: /* original 9316, guest PC 0x0c0c3c6a */
if(!s->budget--) { s->failed_pc=0x0c0c3c6au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c9au,2);
goto P_0c0c3c6c;
P_0c0c3c6c: /* original 2138, guest PC 0x0c0c3c6c */
if(!s->budget--) { s->failed_pc=0x0c0c3c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c3c6e;
P_0c0c3c6e: /* original 8b06, guest PC 0x0c0c3c6e */
if(!s->budget--) { s->failed_pc=0x0c0c3c6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3c7e; }
goto P_0c0c3c70;
P_0c0c3c70: /* original d311, guest PC 0x0c0c3c70 */
if(!s->budget--) { s->failed_pc=0x0c0c3c70u; return 0; }
r[3]=read(ram,0x0c0c3cb8u,4);
goto P_0c0c3c72;
P_0c0c3c72: /* original 54f6, guest PC 0x0c0c3c72 */
if(!s->budget--) { s->failed_pc=0x0c0c3c72u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0c3c74;
P_0c0c3c74: /* original 430b, guest PC 0x0c0c3c74 */
if(!s->budget--) { s->failed_pc=0x0c0c3c74u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3c78u;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3c78u) { target=s->pc; goto dispatch; }
goto P_0c0c3c78;
P_0c0c3c76: /* original 7430, guest PC 0x0c0c3c76 */
if(!s->budget--) { s->failed_pc=0x0c0c3c76u; return 0; }
r[4]+=0x00000030u;
goto P_0c0c3c78;
P_0c0c3c78: /* original 640c, guest PC 0x0c0c3c78 */
if(!s->budget--) { s->failed_pc=0x0c0c3c78u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c3c7a;
P_0c0c3c7a: /* original 2448, guest PC 0x0c0c3c7a */
if(!s->budget--) { s->failed_pc=0x0c0c3c7au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3c7c;
P_0c0c3c7c: /* original 8b1e, guest PC 0x0c0c3c7c */
if(!s->budget--) { s->failed_pc=0x0c0c3c7cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3cbc; }
goto P_0c0c3c7e;
P_0c0c3c7e: /* original 2d8b, guest PC 0x0c0c3c7e */
if(!s->budget--) { s->failed_pc=0x0c0c3c7eu; return 0; }
r[13]|=r[8];
goto P_0c0c3c80;
P_0c0c3c80: /* original 1ed2, guest PC 0x0c0c3c80 */
if(!s->budget--) { s->failed_pc=0x0c0c3c80u; return 0; }
write(ram,r[14]+8,r[13],4);
goto P_0c0c3c82;
P_0c0c3c82: /* original 930a, guest PC 0x0c0c3c82 */
if(!s->budget--) { s->failed_pc=0x0c0c3c82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3c9au,2);
goto P_0c0c3c84;
P_0c0c3c84: /* original 62c2, guest PC 0x0c0c3c84 */
if(!s->budget--) { s->failed_pc=0x0c0c3c84u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0c3c86;
P_0c0c3c86: /* original 2238, guest PC 0x0c0c3c86 */
if(!s->budget--) { s->failed_pc=0x0c0c3c86u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c3c88;
P_0c0c3c88: /* original 8901, guest PC 0x0c0c3c88 */
if(!s->budget--) { s->failed_pc=0x0c0c3c88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3c8e; }
goto P_0c0c3c8a;
P_0c0c3c8a: /* original a28e, guest PC 0x0c0c3c8a */
if(!s->budget--) { s->failed_pc=0x0c0c3c8au; return 0; }
goto P_0c0c41aa;
P_0c0c3c8c: /* original 0009, guest PC 0x0c0c3c8c */
if(!s->budget--) { s->failed_pc=0x0c0c3c8cu; return 0; }
goto P_0c0c3c8e;
P_0c0c3c8e: /* original a28c, guest PC 0x0c0c3c8e */
if(!s->budget--) { s->failed_pc=0x0c0c3c8eu; return 0; }
goto P_0c0c41aa;
P_0c0c3c90: /* original 0009, guest PC 0x0c0c3c90 */
if(!s->budget--) { s->failed_pc=0x0c0c3c90u; return 0; }
if(!vf3_matrix_family(0x0c0c3c92u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3c92u; return 0; } return 1;
P_0c0c3cbc: /* original 84c8, guest PC 0x0c0c3cbc */
if(!s->budget--) { s->failed_pc=0x0c0c3cbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+8,1);
goto P_0c0c3cbe;
P_0c0c3cbe: /* original 600c, guest PC 0x0c0c3cbe */
if(!s->budget--) { s->failed_pc=0x0c0c3cbeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0c3cc0;
P_0c0c3cc0: /* original 880d, guest PC 0x0c0c3cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c3cc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0c3cc2;
P_0c0c3cc2: /* original 8f11, guest PC 0x0c0c3cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c3cc2u; return 0; }
cond=r[17]&1u;
r[9]=0x00000000u;
if(!cond) { goto P_0c0c3ce8; }
goto P_0c0c3cc6;
P_0c0c3cc4: /* original e900, guest PC 0x0c0c3cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c3cc4u; return 0; }
r[9]=0x00000000u;
goto P_0c0c3cc6;
P_0c0c3cc6: /* original 50f4, guest PC 0x0c0c3cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c3cc6u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c3cc8;
P_0c0c3cc8: /* original c930, guest PC 0x0c0c3cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c3cc8u; return 0; }
r[0]&=48u;
goto P_0c0c3cca;
P_0c0c3cca: /* original 6403, guest PC 0x0c0c3cca */
if(!s->budget--) { s->failed_pc=0x0c0c3ccau; return 0; }
r[4]=r[0];
goto P_0c0c3ccc;
P_0c0c3ccc: /* original 2448, guest PC 0x0c0c3ccc */
if(!s->budget--) { s->failed_pc=0x0c0c3cccu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3cce;
P_0c0c3cce: /* original 8b01, guest PC 0x0c0c3cce */
if(!s->budget--) { s->failed_pc=0x0c0c3cceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3cd4; }
goto P_0c0c3cd0;
P_0c0c3cd0: /* original a008, guest PC 0x0c0c3cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c3cd0u; return 0; }
r[4]=r[9];
goto P_0c0c3ce4;
P_0c0c3cd2: /* original 6493, guest PC 0x0c0c3cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c3cd2u; return 0; }
r[4]=r[9];
goto P_0c0c3cd4;
P_0c0c3cd4: /* original 9050, guest PC 0x0c0c3cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c3cd4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3d78u,2);
goto P_0c0c3cd6;
P_0c0c3cd6: /* original e340, guest PC 0x0c0c3cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c3cd6u; return 0; }
r[3]=0x00000040u;
goto P_0c0c3cd8;
P_0c0c3cd8: /* original 04cc, guest PC 0x0c0c3cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c3cd8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c3cda;
P_0c0c3cda: /* original 7401, guest PC 0x0c0c3cda */
if(!s->budget--) { s->failed_pc=0x0c0c3cdau; return 0; }
r[4]+=0x00000001u;
goto P_0c0c3cdc;
P_0c0c3cdc: /* original 3432, guest PC 0x0c0c3cdc */
if(!s->budget--) { s->failed_pc=0x0c0c3cdcu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c0c3cde;
P_0c0c3cde: /* original 8b01, guest PC 0x0c0c3cde */
if(!s->budget--) { s->failed_pc=0x0c0c3cdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ce4; }
goto P_0c0c3ce0;
P_0c0c3ce0: /* original 1ed2, guest PC 0x0c0c3ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ce0u; return 0; }
write(ram,r[14]+8,r[13],4);
goto P_0c0c3ce2;
P_0c0c3ce2: /* original 6493, guest PC 0x0c0c3ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ce2u; return 0; }
r[4]=r[9];
goto P_0c0c3ce4;
P_0c0c3ce4: /* original 9048, guest PC 0x0c0c3ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ce4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3d78u,2);
goto P_0c0c3ce6;
P_0c0c3ce6: /* original 0c44, guest PC 0x0c0c3ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ce6u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c0c3ce8;
P_0c0c3ce8: /* original 52e2, guest PC 0x0c0c3ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ce8u; return 0; }
r[2]=read(ram,r[14]+8,4);
goto P_0c0c3cea;
P_0c0c3cea: /* original d326, guest PC 0x0c0c3cea */
if(!s->budget--) { s->failed_pc=0x0c0c3ceau; return 0; }
r[3]=read(ram,0x0c0c3d84u,4);
goto P_0c0c3cec;
P_0c0c3cec: /* original 2238, guest PC 0x0c0c3cec */
if(!s->budget--) { s->failed_pc=0x0c0c3cecu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c3cee;
P_0c0c3cee: /* original 8901, guest PC 0x0c0c3cee */
if(!s->budget--) { s->failed_pc=0x0c0c3ceeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3cf4; }
goto P_0c0c3cf0;
P_0c0c3cf0: /* original a25b, guest PC 0x0c0c3cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c3cf0u; return 0; }
goto P_0c0c41aa;
P_0c0c3cf2: /* original 0009, guest PC 0x0c0c3cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c3cf2u; return 0; }
goto P_0c0c3cf4;
P_0c0c3cf4: /* original 9041, guest PC 0x0c0c3cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c3cf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3d7au,2);
goto P_0c0c3cf6;
P_0c0c3cf6: /* original 00cc, guest PC 0x0c0c3cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c3cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c3cf8;
P_0c0c3cf8: /* original 2008, guest PC 0x0c0c3cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c3cf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c3cfa;
P_0c0c3cfa: /* original 8901, guest PC 0x0c0c3cfa */
if(!s->budget--) { s->failed_pc=0x0c0c3cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3d00; }
goto P_0c0c3cfc;
P_0c0c3cfc: /* original a255, guest PC 0x0c0c3cfc */
if(!s->budget--) { s->failed_pc=0x0c0c3cfcu; return 0; }
goto P_0c0c41aa;
P_0c0c3cfe: /* original 0009, guest PC 0x0c0c3cfe */
if(!s->budget--) { s->failed_pc=0x0c0c3cfeu; return 0; }
goto P_0c0c3d00;
P_0c0c3d00: /* original d022, guest PC 0x0c0c3d00 */
if(!s->budget--) { s->failed_pc=0x0c0c3d00u; return 0; }
r[0]=read(ram,0x0c0c3d8cu,4);
goto P_0c0c3d02;
P_0c0c3d02: /* original d221, guest PC 0x0c0c3d02 */
if(!s->budget--) { s->failed_pc=0x0c0c3d02u; return 0; }
r[2]=read(ram,0x0c0c3d88u,4);
goto P_0c0c3d04;
P_0c0c3d04: /* original 6102, guest PC 0x0c0c3d04 */
if(!s->budget--) { s->failed_pc=0x0c0c3d04u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0c3d06;
P_0c0c3d06: /* original 2128, guest PC 0x0c0c3d06 */
if(!s->budget--) { s->failed_pc=0x0c0c3d06u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0c3d08;
P_0c0c3d08: /* original 8901, guest PC 0x0c0c3d08 */
if(!s->budget--) { s->failed_pc=0x0c0c3d08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3d0e; }
goto P_0c0c3d0a;
P_0c0c3d0a: /* original a24e, guest PC 0x0c0c3d0a */
if(!s->budget--) { s->failed_pc=0x0c0c3d0au; return 0; }
goto P_0c0c41aa;
P_0c0c3d0c: /* original 0009, guest PC 0x0c0c3d0c */
if(!s->budget--) { s->failed_pc=0x0c0c3d0cu; return 0; }
goto P_0c0c3d0e;
P_0c0c3d0e: /* original d220, guest PC 0x0c0c3d0e */
if(!s->budget--) { s->failed_pc=0x0c0c3d0eu; return 0; }
r[2]=read(ram,0x0c0c3d90u,4);
goto P_0c0c3d10;
P_0c0c3d10: /* original 65c2, guest PC 0x0c0c3d10 */
if(!s->budget--) { s->failed_pc=0x0c0c3d10u; return 0; }
tmp=read(ram,r[12],4);
r[5]=tmp;
goto P_0c0c3d12;
P_0c0c3d12: /* original 2258, guest PC 0x0c0c3d12 */
if(!s->budget--) { s->failed_pc=0x0c0c3d12u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c0c3d14;
P_0c0c3d14: /* original 8b01, guest PC 0x0c0c3d14 */
if(!s->budget--) { s->failed_pc=0x0c0c3d14u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3d1a; }
goto P_0c0c3d16;
P_0c0c3d16: /* original a248, guest PC 0x0c0c3d16 */
if(!s->budget--) { s->failed_pc=0x0c0c3d16u; return 0; }
goto P_0c0c41aa;
P_0c0c3d18: /* original 0009, guest PC 0x0c0c3d18 */
if(!s->budget--) { s->failed_pc=0x0c0c3d18u; return 0; }
goto P_0c0c3d1a;
P_0c0c3d1a: /* original d31f, guest PC 0x0c0c3d1a */
if(!s->budget--) { s->failed_pc=0x0c0c3d1au; return 0; }
r[3]=read(ram,0x0c0c3d98u,4);
goto P_0c0c3d1c;
P_0c0c3d1c: /* original e029, guest PC 0x0c0c3d1c */
if(!s->budget--) { s->failed_pc=0x0c0c3d1cu; return 0; }
r[0]=0x00000029u;
goto P_0c0c3d1e;
P_0c0c3d1e: /* original 04ec, guest PC 0x0c0c3d1e */
if(!s->budget--) { s->failed_pc=0x0c0c3d1eu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3d20;
P_0c0c3d20: /* original 23d9, guest PC 0x0c0c3d20 */
if(!s->budget--) { s->failed_pc=0x0c0c3d20u; return 0; }
r[3]&=r[13];
goto P_0c0c3d22;
P_0c0c3d22: /* original db1c, guest PC 0x0c0c3d22 */
if(!s->budget--) { s->failed_pc=0x0c0c3d22u; return 0; }
r[11]=read(ram,0x0c0c3d94u,4);
goto P_0c0c3d24;
P_0c0c3d24: /* original 1f33, guest PC 0x0c0c3d24 */
if(!s->budget--) { s->failed_pc=0x0c0c3d24u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0c3d26;
P_0c0c3d26: /* original 644c, guest PC 0x0c0c3d26 */
if(!s->budget--) { s->failed_pc=0x0c0c3d26u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3d28;
P_0c0c3d28: /* original 9228, guest PC 0x0c0c3d28 */
if(!s->budget--) { s->failed_pc=0x0c0c3d28u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3d7cu,2);
goto P_0c0c3d2a;
P_0c0c3d2a: /* original 51f4, guest PC 0x0c0c3d2a */
if(!s->budget--) { s->failed_pc=0x0c0c3d2au; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c0c3d2c;
P_0c0c3d2c: /* original 2129, guest PC 0x0c0c3d2c */
if(!s->budget--) { s->failed_pc=0x0c0c3d2cu; return 0; }
r[1]&=r[2];
goto P_0c0c3d2e;
P_0c0c3d2e: /* original 4218, guest PC 0x0c0c3d2e */
if(!s->budget--) { s->failed_pc=0x0c0c3d2eu; return 0; }
r[2]<<=8;
goto P_0c0c3d30;
P_0c0c3d30: /* original 1f12, guest PC 0x0c0c3d30 */
if(!s->budget--) { s->failed_pc=0x0c0c3d30u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c0c3d32;
P_0c0c3d32: /* original 9324, guest PC 0x0c0c3d32 */
if(!s->budget--) { s->failed_pc=0x0c0c3d32u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3d7eu,2);
goto P_0c0c3d34;
P_0c0c3d34: /* original 23db, guest PC 0x0c0c3d34 */
if(!s->budget--) { s->failed_pc=0x0c0c3d34u; return 0; }
r[3]|=r[13];
goto P_0c0c3d36;
P_0c0c3d36: /* original 2f32, guest PC 0x0c0c3d36 */
if(!s->budget--) { s->failed_pc=0x0c0c3d36u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3d38;
P_0c0c3d38: /* original 50f4, guest PC 0x0c0c3d38 */
if(!s->budget--) { s->failed_pc=0x0c0c3d38u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c0c3d3a;
P_0c0c3d3a: /* original 2029, guest PC 0x0c0c3d3a */
if(!s->budget--) { s->failed_pc=0x0c0c3d3au; return 0; }
r[0]&=r[2];
goto P_0c0c3d3c;
P_0c0c3d3c: /* original 1f01, guest PC 0x0c0c3d3c */
if(!s->budget--) { s->failed_pc=0x0c0c3d3cu; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0c3d3e;
P_0c0c3d3e: /* original d217, guest PC 0x0c0c3d3e */
if(!s->budget--) { s->failed_pc=0x0c0c3d3eu; return 0; }
r[2]=read(ram,0x0c0c3d9cu,4);
goto P_0c0c3d40;
P_0c0c3d40: /* original 22d9, guest PC 0x0c0c3d40 */
if(!s->budget--) { s->failed_pc=0x0c0c3d40u; return 0; }
r[2]&=r[13];
goto P_0c0c3d42;
P_0c0c3d42: /* original 1f25, guest PC 0x0c0c3d42 */
if(!s->budget--) { s->failed_pc=0x0c0c3d42u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c0c3d44;
P_0c0c3d44: /* original d316, guest PC 0x0c0c3d44 */
if(!s->budget--) { s->failed_pc=0x0c0c3d44u; return 0; }
r[3]=read(ram,0x0c0c3da0u,4);
goto P_0c0c3d46;
P_0c0c3d46: /* original 961b, guest PC 0x0c0c3d46 */
if(!s->budget--) { s->failed_pc=0x0c0c3d46u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3d80u,2);
goto P_0c0c3d48;
P_0c0c3d48: /* original 2358, guest PC 0x0c0c3d48 */
if(!s->budget--) { s->failed_pc=0x0c0c3d48u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0c3d4a;
P_0c0c3d4a: /* original 8f78, guest PC 0x0c0c3d4a */
if(!s->budget--) { s->failed_pc=0x0c0c3d4au; return 0; }
cond=r[17]&1u;
r[6]|=r[13];
if(!cond) { goto P_0c0c3e3e; }
goto P_0c0c3d4e;
P_0c0c3d4c: /* original 26db, guest PC 0x0c0c3d4c */
if(!s->budget--) { s->failed_pc=0x0c0c3d4cu; return 0; }
r[6]|=r[13];
goto P_0c0c3d4e;
P_0c0c3d4e: /* original d615, guest PC 0x0c0c3d4e */
if(!s->budget--) { s->failed_pc=0x0c0c3d4eu; return 0; }
r[6]=read(ram,0x0c0c3da4u,4);
goto P_0c0c3d50;
P_0c0c3d50: /* original 6353, guest PC 0x0c0c3d50 */
if(!s->budget--) { s->failed_pc=0x0c0c3d50u; return 0; }
r[3]=r[5];
goto P_0c0c3d52;
P_0c0c3d52: /* original 2368, guest PC 0x0c0c3d52 */
if(!s->budget--) { s->failed_pc=0x0c0c3d52u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c0c3d54;
P_0c0c3d54: /* original 8906, guest PC 0x0c0c3d54 */
if(!s->budget--) { s->failed_pc=0x0c0c3d54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3d64; }
goto P_0c0c3d56;
P_0c0c3d56: /* original 51c1, guest PC 0x0c0c3d56 */
if(!s->budget--) { s->failed_pc=0x0c0c3d56u; return 0; }
r[1]=read(ram,r[12]+4,4);
goto P_0c0c3d58;
P_0c0c3d58: /* original 2618, guest PC 0x0c0c3d58 */
if(!s->budget--) { s->failed_pc=0x0c0c3d58u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[1])==0)!=0);
goto P_0c0c3d5a;
P_0c0c3d5a: /* original 8901, guest PC 0x0c0c3d5a */
if(!s->budget--) { s->failed_pc=0x0c0c3d5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3d60; }
goto P_0c0c3d5c;
P_0c0c3d5c: /* original a225, guest PC 0x0c0c3d5c */
if(!s->budget--) { s->failed_pc=0x0c0c3d5cu; return 0; }
goto P_0c0c41aa;
P_0c0c3d5e: /* original 0009, guest PC 0x0c0c3d5e */
if(!s->budget--) { s->failed_pc=0x0c0c3d5eu; return 0; }
goto P_0c0c3d60;
P_0c0c3d60: /* original a1cc, guest PC 0x0c0c3d60 */
if(!s->budget--) { s->failed_pc=0x0c0c3d60u; return 0; }
goto P_0c0c40fc;
P_0c0c3d62: /* original 0009, guest PC 0x0c0c3d62 */
if(!s->budget--) { s->failed_pc=0x0c0c3d62u; return 0; }
goto P_0c0c3d64;
P_0c0c3d64: /* original d310, guest PC 0x0c0c3d64 */
if(!s->budget--) { s->failed_pc=0x0c0c3d64u; return 0; }
r[3]=read(ram,0x0c0c3da8u,4);
goto P_0c0c3d66;
P_0c0c3d66: /* original 2538, guest PC 0x0c0c3d66 */
if(!s->budget--) { s->failed_pc=0x0c0c3d66u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c3d68;
P_0c0c3d68: /* original 8920, guest PC 0x0c0c3d68 */
if(!s->budget--) { s->failed_pc=0x0c0c3d68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3dac; }
goto P_0c0c3d6a;
P_0c0c3d6a: /* original 54eb, guest PC 0x0c0c3d6a */
if(!s->budget--) { s->failed_pc=0x0c0c3d6au; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c0c3d6c;
P_0c0c3d6c: /* original 4415, guest PC 0x0c0c3d6c */
if(!s->budget--) { s->failed_pc=0x0c0c3d6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c3d6e;
P_0c0c3d6e: /* original 8b01, guest PC 0x0c0c3d6e */
if(!s->budget--) { s->failed_pc=0x0c0c3d6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3d74; }
goto P_0c0c3d70;
P_0c0c3d70: /* original a1c4, guest PC 0x0c0c3d70 */
if(!s->budget--) { s->failed_pc=0x0c0c3d70u; return 0; }
goto P_0c0c40fc;
P_0c0c3d72: /* original 0009, guest PC 0x0c0c3d72 */
if(!s->budget--) { s->failed_pc=0x0c0c3d72u; return 0; }
goto P_0c0c3d74;
P_0c0c3d74: /* original a219, guest PC 0x0c0c3d74 */
if(!s->budget--) { s->failed_pc=0x0c0c3d74u; return 0; }
goto P_0c0c41aa;
P_0c0c3d76: /* original 0009, guest PC 0x0c0c3d76 */
if(!s->budget--) { s->failed_pc=0x0c0c3d76u; return 0; }
if(!vf3_matrix_family(0x0c0c3d78u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3d78u; return 0; } return 1;
P_0c0c3dac: /* original 56b5, guest PC 0x0c0c3dac */
if(!s->budget--) { s->failed_pc=0x0c0c3dacu; return 0; }
r[6]=read(ram,r[11]+20,4);
goto P_0c0c3dae;
P_0c0c3dae: /* original 55b4, guest PC 0x0c0c3dae */
if(!s->budget--) { s->failed_pc=0x0c0c3daeu; return 0; }
r[5]=read(ram,r[11]+16,4);
goto P_0c0c3db0;
P_0c0c3db0: /* original 6662, guest PC 0x0c0c3db0 */
if(!s->budget--) { s->failed_pc=0x0c0c3db0u; return 0; }
tmp=read(ram,r[6],4);
r[6]=tmp;
goto P_0c0c3db2;
P_0c0c3db2: /* original 6552, guest PC 0x0c0c3db2 */
if(!s->budget--) { s->failed_pc=0x0c0c3db2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0c3db4;
P_0c0c3db4: /* original d32c, guest PC 0x0c0c3db4 */
if(!s->budget--) { s->failed_pc=0x0c0c3db4u; return 0; }
r[3]=read(ram,0x0c0c3e68u,4);
goto P_0c0c3db6;
P_0c0c3db6: /* original 256b, guest PC 0x0c0c3db6 */
if(!s->budget--) { s->failed_pc=0x0c0c3db6u; return 0; }
r[5]|=r[6];
goto P_0c0c3db8;
P_0c0c3db8: /* original 2538, guest PC 0x0c0c3db8 */
if(!s->budget--) { s->failed_pc=0x0c0c3db8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0c3dba;
P_0c0c3dba: /* original 8905, guest PC 0x0c0c3dba */
if(!s->budget--) { s->failed_pc=0x0c0c3dbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3dc8; }
goto P_0c0c3dbc;
P_0c0c3dbc: /* original 52c1, guest PC 0x0c0c3dbc */
if(!s->budget--) { s->failed_pc=0x0c0c3dbcu; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0c3dbe;
P_0c0c3dbe: /* original d32b, guest PC 0x0c0c3dbe */
if(!s->budget--) { s->failed_pc=0x0c0c3dbeu; return 0; }
r[3]=read(ram,0x0c0c3e6cu,4);
goto P_0c0c3dc0;
P_0c0c3dc0: /* original 2238, guest PC 0x0c0c3dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c3dc0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c3dc2;
P_0c0c3dc2: /* original 8901, guest PC 0x0c0c3dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c3dc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3dc8; }
goto P_0c0c3dc4;
P_0c0c3dc4: /* original a1f1, guest PC 0x0c0c3dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c3dc4u; return 0; }
goto P_0c0c41aa;
P_0c0c3dc6: /* original 0009, guest PC 0x0c0c3dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c3dc6u; return 0; }
goto P_0c0c3dc8;
P_0c0c3dc8: /* original e010, guest PC 0x0c0c3dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c3dc8u; return 0; }
r[0]=0x00000010u;
goto P_0c0c3dca;
P_0c0c3dca: /* original 20d8, guest PC 0x0c0c3dca */
if(!s->budget--) { s->failed_pc=0x0c0c3dcau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[13])==0)!=0);
goto P_0c0c3dcc;
P_0c0c3dcc: /* original 8901, guest PC 0x0c0c3dcc */
if(!s->budget--) { s->failed_pc=0x0c0c3dccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3dd2; }
goto P_0c0c3dce;
P_0c0c3dce: /* original a1ec, guest PC 0x0c0c3dce */
if(!s->budget--) { s->failed_pc=0x0c0c3dceu; return 0; }
goto P_0c0c41aa;
P_0c0c3dd0: /* original 0009, guest PC 0x0c0c3dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c3dd0u; return 0; }
goto P_0c0c3dd2;
P_0c0c3dd2: /* original 6043, guest PC 0x0c0c3dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c3dd2u; return 0; }
r[0]=r[4];
goto P_0c0c3dd4;
P_0c0c3dd4: /* original 8803, guest PC 0x0c0c3dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c3dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c3dd6;
P_0c0c3dd6: /* original 890e, guest PC 0x0c0c3dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c3dd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3df6; }
goto P_0c0c3dd8;
P_0c0c3dd8: /* original 2448, guest PC 0x0c0c3dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c3dd8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3dda;
P_0c0c3dda: /* original 8b01, guest PC 0x0c0c3dda */
if(!s->budget--) { s->failed_pc=0x0c0c3ddau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3de0; }
goto P_0c0c3ddc;
P_0c0c3ddc: /* original a106, guest PC 0x0c0c3ddc */
if(!s->budget--) { s->failed_pc=0x0c0c3ddcu; return 0; }
goto P_0c0c3fec;
P_0c0c3dde: /* original 0009, guest PC 0x0c0c3dde */
if(!s->budget--) { s->failed_pc=0x0c0c3ddeu; return 0; }
goto P_0c0c3de0;
P_0c0c3de0: /* original 55bb, guest PC 0x0c0c3de0 */
if(!s->budget--) { s->failed_pc=0x0c0c3de0u; return 0; }
r[5]=read(ram,r[11]+44,4);
goto P_0c0c3de2;
P_0c0c3de2: /* original 54ba, guest PC 0x0c0c3de2 */
if(!s->budget--) { s->failed_pc=0x0c0c3de2u; return 0; }
r[4]=read(ram,r[11]+40,4);
goto P_0c0c3de4;
P_0c0c3de4: /* original 6552, guest PC 0x0c0c3de4 */
if(!s->budget--) { s->failed_pc=0x0c0c3de4u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0c3de6;
P_0c0c3de6: /* original 6442, guest PC 0x0c0c3de6 */
if(!s->budget--) { s->failed_pc=0x0c0c3de6u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c3de8;
P_0c0c3de8: /* original 245b, guest PC 0x0c0c3de8 */
if(!s->budget--) { s->failed_pc=0x0c0c3de8u; return 0; }
r[4]|=r[5];
goto P_0c0c3dea;
P_0c0c3dea: /* original 2488, guest PC 0x0c0c3dea */
if(!s->budget--) { s->failed_pc=0x0c0c3deau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0c3dec;
P_0c0c3dec: /* original 8901, guest PC 0x0c0c3dec */
if(!s->budget--) { s->failed_pc=0x0c0c3decu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3df2; }
goto P_0c0c3dee;
P_0c0c3dee: /* original a0fd, guest PC 0x0c0c3dee */
if(!s->budget--) { s->failed_pc=0x0c0c3deeu; return 0; }
goto P_0c0c3fec;
P_0c0c3df0: /* original 0009, guest PC 0x0c0c3df0 */
if(!s->budget--) { s->failed_pc=0x0c0c3df0u; return 0; }
goto P_0c0c3df2;
P_0c0c3df2: /* original a1da, guest PC 0x0c0c3df2 */
if(!s->budget--) { s->failed_pc=0x0c0c3df2u; return 0; }
goto P_0c0c41aa;
P_0c0c3df4: /* original 0009, guest PC 0x0c0c3df4 */
if(!s->budget--) { s->failed_pc=0x0c0c3df4u; return 0; }
goto P_0c0c3df6;
P_0c0c3df6: /* original d31e, guest PC 0x0c0c3df6 */
if(!s->budget--) { s->failed_pc=0x0c0c3df6u; return 0; }
r[3]=read(ram,0x0c0c3e70u,4);
goto P_0c0c3df8;
P_0c0c3df8: /* original 54f6, guest PC 0x0c0c3df8 */
if(!s->budget--) { s->failed_pc=0x0c0c3df8u; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0c3dfa;
P_0c0c3dfa: /* original 430b, guest PC 0x0c0c3dfa */
if(!s->budget--) { s->failed_pc=0x0c0c3dfau; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3dfeu;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3dfeu) { target=s->pc; goto dispatch; }
goto P_0c0c3dfe;
P_0c0c3dfc: /* original 7413, guest PC 0x0c0c3dfc */
if(!s->budget--) { s->failed_pc=0x0c0c3dfcu; return 0; }
r[4]+=0x00000013u;
goto P_0c0c3dfe;
P_0c0c3dfe: /* original 640c, guest PC 0x0c0c3dfe */
if(!s->budget--) { s->failed_pc=0x0c0c3dfeu; return 0; }
r[4]=r[0]&255u;
goto P_0c0c3e00;
P_0c0c3e00: /* original 2448, guest PC 0x0c0c3e00 */
if(!s->budget--) { s->failed_pc=0x0c0c3e00u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3e02;
P_0c0c3e02: /* original 8905, guest PC 0x0c0c3e02 */
if(!s->budget--) { s->failed_pc=0x0c0c3e02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3e10; }
goto P_0c0c3e04;
P_0c0c3e04: /* original 902c, guest PC 0x0c0c3e04 */
if(!s->budget--) { s->failed_pc=0x0c0c3e04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3e60u,2);
goto P_0c0c3e06;
P_0c0c3e06: /* original 02ee, guest PC 0x0c0c3e06 */
if(!s->budget--) { s->failed_pc=0x0c0c3e06u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0c3e08;
P_0c0c3e08: /* original 3242, guest PC 0x0c0c3e08 */
if(!s->budget--) { s->failed_pc=0x0c0c3e08u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[4])!=0);
goto P_0c0c3e0a;
P_0c0c3e0a: /* original 8b01, guest PC 0x0c0c3e0a */
if(!s->budget--) { s->failed_pc=0x0c0c3e0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3e10; }
goto P_0c0c3e0c;
P_0c0c3e0c: /* original a1cd, guest PC 0x0c0c3e0c */
if(!s->budget--) { s->failed_pc=0x0c0c3e0cu; return 0; }
goto P_0c0c41aa;
P_0c0c3e0e: /* original 0009, guest PC 0x0c0c3e0e */
if(!s->budget--) { s->failed_pc=0x0c0c3e0eu; return 0; }
goto P_0c0c3e10;
P_0c0c3e10: /* original 51c1, guest PC 0x0c0c3e10 */
if(!s->budget--) { s->failed_pc=0x0c0c3e10u; return 0; }
r[1]=read(ram,r[12]+4,4);
goto P_0c0c3e12;
P_0c0c3e12: /* original d318, guest PC 0x0c0c3e12 */
if(!s->budget--) { s->failed_pc=0x0c0c3e12u; return 0; }
r[3]=read(ram,0x0c0c3e74u,4);
goto P_0c0c3e14;
P_0c0c3e14: /* original 2138, guest PC 0x0c0c3e14 */
if(!s->budget--) { s->failed_pc=0x0c0c3e14u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c3e16;
P_0c0c3e16: /* original 8901, guest PC 0x0c0c3e16 */
if(!s->budget--) { s->failed_pc=0x0c0c3e16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3e1c; }
goto P_0c0c3e18;
P_0c0c3e18: /* original a1c7, guest PC 0x0c0c3e18 */
if(!s->budget--) { s->failed_pc=0x0c0c3e18u; return 0; }
goto P_0c0c41aa;
P_0c0c3e1a: /* original 0009, guest PC 0x0c0c3e1a */
if(!s->budget--) { s->failed_pc=0x0c0c3e1au; return 0; }
goto P_0c0c3e1c;
P_0c0c3e1c: /* original 9322, guest PC 0x0c0c3e1c */
if(!s->budget--) { s->failed_pc=0x0c0c3e1cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3e64u,2);
goto P_0c0c3e1e;
P_0c0c3e1e: /* original 9020, guest PC 0x0c0c3e1e */
if(!s->budget--) { s->failed_pc=0x0c0c3e1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3e62u,2);
goto P_0c0c3e20;
P_0c0c3e20: /* original 33ec, guest PC 0x0c0c3e20 */
if(!s->budget--) { s->failed_pc=0x0c0c3e20u; return 0; }
r[3]+=r[14];
goto P_0c0c3e22;
P_0c0c3e22: /* original 6330, guest PC 0x0c0c3e22 */
if(!s->budget--) { s->failed_pc=0x0c0c3e22u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[3]=tmp;
goto P_0c0c3e24;
P_0c0c3e24: /* original 00ec, guest PC 0x0c0c3e24 */
if(!s->budget--) { s->failed_pc=0x0c0c3e24u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3e26;
P_0c0c3e26: /* original 3030, guest PC 0x0c0c3e26 */
if(!s->budget--) { s->failed_pc=0x0c0c3e26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[3])!=0);
goto P_0c0c3e28;
P_0c0c3e28: /* original 8b01, guest PC 0x0c0c3e28 */
if(!s->budget--) { s->failed_pc=0x0c0c3e28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3e2e; }
goto P_0c0c3e2a;
P_0c0c3e2a: /* original a0df, guest PC 0x0c0c3e2a */
if(!s->budget--) { s->failed_pc=0x0c0c3e2au; return 0; }
goto P_0c0c3fec;
P_0c0c3e2c: /* original 0009, guest PC 0x0c0c3e2c */
if(!s->budget--) { s->failed_pc=0x0c0c3e2cu; return 0; }
goto P_0c0c3e2e;
P_0c0c3e2e: /* original 52c1, guest PC 0x0c0c3e2e */
if(!s->budget--) { s->failed_pc=0x0c0c3e2eu; return 0; }
r[2]=read(ram,r[12]+4,4);
goto P_0c0c3e30;
P_0c0c3e30: /* original d311, guest PC 0x0c0c3e30 */
if(!s->budget--) { s->failed_pc=0x0c0c3e30u; return 0; }
r[3]=read(ram,0x0c0c3e78u,4);
goto P_0c0c3e32;
P_0c0c3e32: /* original 2238, guest PC 0x0c0c3e32 */
if(!s->budget--) { s->failed_pc=0x0c0c3e32u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c3e34;
P_0c0c3e34: /* original 8b01, guest PC 0x0c0c3e34 */
if(!s->budget--) { s->failed_pc=0x0c0c3e34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3e3a; }
goto P_0c0c3e36;
P_0c0c3e36: /* original a0d9, guest PC 0x0c0c3e36 */
if(!s->budget--) { s->failed_pc=0x0c0c3e36u; return 0; }
goto P_0c0c3fec;
P_0c0c3e38: /* original 0009, guest PC 0x0c0c3e38 */
if(!s->budget--) { s->failed_pc=0x0c0c3e38u; return 0; }
goto P_0c0c3e3a;
P_0c0c3e3a: /* original a1b6, guest PC 0x0c0c3e3a */
if(!s->budget--) { s->failed_pc=0x0c0c3e3au; return 0; }
goto P_0c0c41aa;
P_0c0c3e3c: /* original 0009, guest PC 0x0c0c3e3c */
if(!s->budget--) { s->failed_pc=0x0c0c3e3cu; return 0; }
goto P_0c0c3e3e;
P_0c0c3e3e: /* original 6043, guest PC 0x0c0c3e3e */
if(!s->budget--) { s->failed_pc=0x0c0c3e3eu; return 0; }
r[0]=r[4];
goto P_0c0c3e40;
P_0c0c3e40: /* original 8801, guest PC 0x0c0c3e40 */
if(!s->budget--) { s->failed_pc=0x0c0c3e40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c3e42;
P_0c0c3e42: /* original 8f02, guest PC 0x0c0c3e42 */
if(!s->budget--) { s->failed_pc=0x0c0c3e42u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c0c3e4a; }
goto P_0c0c3e46;
P_0c0c3e44: /* original 6043, guest PC 0x0c0c3e44 */
if(!s->budget--) { s->failed_pc=0x0c0c3e44u; return 0; }
r[0]=r[4];
goto P_0c0c3e46;
P_0c0c3e46: /* original a001, guest PC 0x0c0c3e46 */
if(!s->budget--) { s->failed_pc=0x0c0c3e46u; return 0; }
r[5]=r[9];
goto P_0c0c3e4c;
P_0c0c3e48: /* original 6593, guest PC 0x0c0c3e48 */
if(!s->budget--) { s->failed_pc=0x0c0c3e48u; return 0; }
r[5]=r[9];
goto P_0c0c3e4a;
P_0c0c3e4a: /* original e501, guest PC 0x0c0c3e4a */
if(!s->budget--) { s->failed_pc=0x0c0c3e4au; return 0; }
r[5]=0x00000001u;
goto P_0c0c3e4c;
P_0c0c3e4c: /* original 8802, guest PC 0x0c0c3e4c */
if(!s->budget--) { s->failed_pc=0x0c0c3e4cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c3e4e;
P_0c0c3e4e: /* original 8f02, guest PC 0x0c0c3e4e */
if(!s->budget--) { s->failed_pc=0x0c0c3e4eu; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c0c3e56; }
goto P_0c0c3e52;
P_0c0c3e50: /* original 6043, guest PC 0x0c0c3e50 */
if(!s->budget--) { s->failed_pc=0x0c0c3e50u; return 0; }
r[0]=r[4];
goto P_0c0c3e52;
P_0c0c3e52: /* original a001, guest PC 0x0c0c3e52 */
if(!s->budget--) { s->failed_pc=0x0c0c3e52u; return 0; }
r[7]=r[9];
goto P_0c0c3e58;
P_0c0c3e54: /* original 6793, guest PC 0x0c0c3e54 */
if(!s->budget--) { s->failed_pc=0x0c0c3e54u; return 0; }
r[7]=r[9];
goto P_0c0c3e56;
P_0c0c3e56: /* original e701, guest PC 0x0c0c3e56 */
if(!s->budget--) { s->failed_pc=0x0c0c3e56u; return 0; }
r[7]=0x00000001u;
goto P_0c0c3e58;
P_0c0c3e58: /* original 8803, guest PC 0x0c0c3e58 */
if(!s->budget--) { s->failed_pc=0x0c0c3e58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c3e5a;
P_0c0c3e5a: /* original 8b0f, guest PC 0x0c0c3e5a */
if(!s->budget--) { s->failed_pc=0x0c0c3e5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3e7c; }
goto P_0c0c3e5c;
P_0c0c3e5c: /* original a00f, guest PC 0x0c0c3e5c */
if(!s->budget--) { s->failed_pc=0x0c0c3e5cu; return 0; }
r[4]=r[9];
goto P_0c0c3e7e;
P_0c0c3e5e: /* original 6493, guest PC 0x0c0c3e5e */
if(!s->budget--) { s->failed_pc=0x0c0c3e5eu; return 0; }
r[4]=r[9];
if(!vf3_matrix_family(0x0c0c3e60u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3e60u; return 0; } return 1;
P_0c0c3e7c: /* original e401, guest PC 0x0c0c3e7c */
if(!s->budget--) { s->failed_pc=0x0c0c3e7cu; return 0; }
r[4]=0x00000001u;
goto P_0c0c3e7e;
P_0c0c3e7e: /* original 2558, guest PC 0x0c0c3e7e */
if(!s->budget--) { s->failed_pc=0x0c0c3e7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c3e80;
P_0c0c3e80: /* original 8b26, guest PC 0x0c0c3e80 */
if(!s->budget--) { s->failed_pc=0x0c0c3e80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ed0; }
goto P_0c0c3e82;
P_0c0c3e82: /* original e310, guest PC 0x0c0c3e82 */
if(!s->budget--) { s->failed_pc=0x0c0c3e82u; return 0; }
r[3]=0x00000010u;
goto P_0c0c3e84;
P_0c0c3e84: /* original 2a38, guest PC 0x0c0c3e84 */
if(!s->budget--) { s->failed_pc=0x0c0c3e84u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0c3e86;
P_0c0c3e86: /* original 8b01, guest PC 0x0c0c3e86 */
if(!s->budget--) { s->failed_pc=0x0c0c3e86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3e8c; }
goto P_0c0c3e88;
P_0c0c3e88: /* original a18f, guest PC 0x0c0c3e88 */
if(!s->budget--) { s->failed_pc=0x0c0c3e88u; return 0; }
goto P_0c0c41aa;
P_0c0c3e8a: /* original 0009, guest PC 0x0c0c3e8a */
if(!s->budget--) { s->failed_pc=0x0c0c3e8au; return 0; }
goto P_0c0c3e8c;
P_0c0c3e8c: /* original 54ba, guest PC 0x0c0c3e8c */
if(!s->budget--) { s->failed_pc=0x0c0c3e8cu; return 0; }
r[4]=read(ram,r[11]+40,4);
goto P_0c0c3e8e;
P_0c0c3e8e: /* original 6442, guest PC 0x0c0c3e8e */
if(!s->budget--) { s->failed_pc=0x0c0c3e8eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c3e90;
P_0c0c3e90: /* original 2488, guest PC 0x0c0c3e90 */
if(!s->budget--) { s->failed_pc=0x0c0c3e90u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0c3e92;
P_0c0c3e92: /* original 8901, guest PC 0x0c0c3e92 */
if(!s->budget--) { s->failed_pc=0x0c0c3e92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3e98; }
goto P_0c0c3e94;
P_0c0c3e94: /* original a189, guest PC 0x0c0c3e94 */
if(!s->budget--) { s->failed_pc=0x0c0c3e94u; return 0; }
goto P_0c0c41aa;
P_0c0c3e96: /* original 0009, guest PC 0x0c0c3e96 */
if(!s->budget--) { s->failed_pc=0x0c0c3e96u; return 0; }
goto P_0c0c3e98;
P_0c0c3e98: /* original 52f3, guest PC 0x0c0c3e98 */
if(!s->budget--) { s->failed_pc=0x0c0c3e98u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c3e9a;
P_0c0c3e9a: /* original 2228, guest PC 0x0c0c3e9a */
if(!s->budget--) { s->failed_pc=0x0c0c3e9au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c3e9c;
P_0c0c3e9c: /* original 8901, guest PC 0x0c0c3e9c */
if(!s->budget--) { s->failed_pc=0x0c0c3e9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3ea2; }
goto P_0c0c3e9e;
P_0c0c3e9e: /* original a183, guest PC 0x0c0c3e9e */
if(!s->budget--) { s->failed_pc=0x0c0c3e9eu; return 0; }
goto P_0c0c41a8;
P_0c0c3ea0: /* original 0009, guest PC 0x0c0c3ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ea0u; return 0; }
goto P_0c0c3ea2;
P_0c0c3ea2: /* original 53f2, guest PC 0x0c0c3ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ea2u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0c3ea4;
P_0c0c3ea4: /* original 9248, guest PC 0x0c0c3ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ea4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f38u,2);
goto P_0c0c3ea6;
P_0c0c3ea6: /* original 3320, guest PC 0x0c0c3ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ea6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c3ea8;
P_0c0c3ea8: /* original 8b00, guest PC 0x0c0c3ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ea8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3eac; }
goto P_0c0c3eaa;
P_0c0c3eaa: /* original 6df2, guest PC 0x0c0c3eaa */
if(!s->budget--) { s->failed_pc=0x0c0c3eaau; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0c3eac;
P_0c0c3eac: /* original 9045, guest PC 0x0c0c3eac */
if(!s->budget--) { s->failed_pc=0x0c0c3eacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3au,2);
goto P_0c0c3eae;
P_0c0c3eae: /* original 03ec, guest PC 0x0c0c3eae */
if(!s->budget--) { s->failed_pc=0x0c0c3eaeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3eb0;
P_0c0c3eb0: /* original 2f32, guest PC 0x0c0c3eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c3eb0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3eb2;
P_0c0c3eb2: /* original b184, guest PC 0x0c0c3eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c3eb2u; return 0; }
target=code_base|0x0c0c41beu; r[16]=code_base|0x0c0c3eb6u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3eb6u) { target=s->pc; goto dispatch; }
goto P_0c0c3eb6;
P_0c0c3eb4: /* original 6433, guest PC 0x0c0c3eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c3eb4u; return 0; }
r[4]=r[3];
goto P_0c0c3eb6;
P_0c0c3eb6: /* original 88ff, guest PC 0x0c0c3eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c3eb6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3eb8;
P_0c0c3eb8: /* original 8f02, guest PC 0x0c0c3eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c3eb8u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c3ec0; }
goto P_0c0c3ebc;
P_0c0c3eba: /* original 6403, guest PC 0x0c0c3eba */
if(!s->budget--) { s->failed_pc=0x0c0c3ebau; return 0; }
r[4]=r[0];
goto P_0c0c3ebc;
P_0c0c3ebc: /* original a174, guest PC 0x0c0c3ebc */
if(!s->budget--) { s->failed_pc=0x0c0c3ebcu; return 0; }
goto P_0c0c41a8;
P_0c0c3ebe: /* original 0009, guest PC 0x0c0c3ebe */
if(!s->budget--) { s->failed_pc=0x0c0c3ebeu; return 0; }
goto P_0c0c3ec0;
P_0c0c3ec0: /* original 903c, guest PC 0x0c0c3ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ec0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3cu,2);
goto P_0c0c3ec2;
P_0c0c3ec2: /* original e301, guest PC 0x0c0c3ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ec2u; return 0; }
r[3]=0x00000001u;
goto P_0c0c3ec4;
P_0c0c3ec4: /* original 04ec, guest PC 0x0c0c3ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ec4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3ec6;
P_0c0c3ec6: /* original 903a, guest PC 0x0c0c3ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ec6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3eu,2);
goto P_0c0c3ec8;
P_0c0c3ec8: /* original 0e44, guest PC 0x0c0c3ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ec8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c3eca;
P_0c0c3eca: /* original 9037, guest PC 0x0c0c3eca */
if(!s->budget--) { s->failed_pc=0x0c0c3ecau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3cu,2);
goto P_0c0c3ecc;
P_0c0c3ecc: /* original a0c5, guest PC 0x0c0c3ecc */
if(!s->budget--) { s->failed_pc=0x0c0c3eccu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c405a;
P_0c0c3ece: /* original 0e34, guest PC 0x0c0c3ece */
if(!s->budget--) { s->failed_pc=0x0c0c3eceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c3ed0;
P_0c0c3ed0: /* original 2778, guest PC 0x0c0c3ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ed0u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3ed2;
P_0c0c3ed2: /* original 8b25, guest PC 0x0c0c3ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3f20; }
goto P_0c0c3ed4;
P_0c0c3ed4: /* original e220, guest PC 0x0c0c3ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ed4u; return 0; }
r[2]=0x00000020u;
goto P_0c0c3ed6;
P_0c0c3ed6: /* original 2a28, guest PC 0x0c0c3ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ed6u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0c3ed8;
P_0c0c3ed8: /* original 8b01, guest PC 0x0c0c3ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ed8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ede; }
goto P_0c0c3eda;
P_0c0c3eda: /* original a166, guest PC 0x0c0c3eda */
if(!s->budget--) { s->failed_pc=0x0c0c3edau; return 0; }
goto P_0c0c41aa;
P_0c0c3edc: /* original 0009, guest PC 0x0c0c3edc */
if(!s->budget--) { s->failed_pc=0x0c0c3edcu; return 0; }
goto P_0c0c3ede;
P_0c0c3ede: /* original 54bb, guest PC 0x0c0c3ede */
if(!s->budget--) { s->failed_pc=0x0c0c3edeu; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c0c3ee0;
P_0c0c3ee0: /* original 6442, guest PC 0x0c0c3ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ee0u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c3ee2;
P_0c0c3ee2: /* original 2488, guest PC 0x0c0c3ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[8])==0)!=0);
goto P_0c0c3ee4;
P_0c0c3ee4: /* original 8901, guest PC 0x0c0c3ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ee4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3eea; }
goto P_0c0c3ee6;
P_0c0c3ee6: /* original a160, guest PC 0x0c0c3ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ee6u; return 0; }
goto P_0c0c41aa;
P_0c0c3ee8: /* original 0009, guest PC 0x0c0c3ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ee8u; return 0; }
goto P_0c0c3eea;
P_0c0c3eea: /* original 53f5, guest PC 0x0c0c3eea */
if(!s->budget--) { s->failed_pc=0x0c0c3eeau; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c0c3eec;
P_0c0c3eec: /* original 2338, guest PC 0x0c0c3eec */
if(!s->budget--) { s->failed_pc=0x0c0c3eecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c3eee;
P_0c0c3eee: /* original 8901, guest PC 0x0c0c3eee */
if(!s->budget--) { s->failed_pc=0x0c0c3eeeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3ef4; }
goto P_0c0c3ef0;
P_0c0c3ef0: /* original a15a, guest PC 0x0c0c3ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ef0u; return 0; }
goto P_0c0c41a8;
P_0c0c3ef2: /* original 0009, guest PC 0x0c0c3ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ef2u; return 0; }
goto P_0c0c3ef4;
P_0c0c3ef4: /* original 52f1, guest PC 0x0c0c3ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ef4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0c3ef6;
P_0c0c3ef6: /* original d413, guest PC 0x0c0c3ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ef6u; return 0; }
r[4]=read(ram,0x0c0c3f44u,4);
goto P_0c0c3ef8;
P_0c0c3ef8: /* original 3240, guest PC 0x0c0c3ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ef8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[4])!=0);
goto P_0c0c3efa;
P_0c0c3efa: /* original 8b00, guest PC 0x0c0c3efa */
if(!s->budget--) { s->failed_pc=0x0c0c3efau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3efe; }
goto P_0c0c3efc;
P_0c0c3efc: /* original 6d63, guest PC 0x0c0c3efc */
if(!s->budget--) { s->failed_pc=0x0c0c3efcu; return 0; }
r[13]=r[6];
goto P_0c0c3efe;
P_0c0c3efe: /* original 901c, guest PC 0x0c0c3efe */
if(!s->budget--) { s->failed_pc=0x0c0c3efeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3au,2);
goto P_0c0c3f00;
P_0c0c3f00: /* original 03ec, guest PC 0x0c0c3f00 */
if(!s->budget--) { s->failed_pc=0x0c0c3f00u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3f02;
P_0c0c3f02: /* original 2f32, guest PC 0x0c0c3f02 */
if(!s->budget--) { s->failed_pc=0x0c0c3f02u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3f04;
P_0c0c3f04: /* original b1ab, guest PC 0x0c0c3f04 */
if(!s->budget--) { s->failed_pc=0x0c0c3f04u; return 0; }
target=code_base|0x0c0c425eu; r[16]=code_base|0x0c0c3f08u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3f08u) { target=s->pc; goto dispatch; }
goto P_0c0c3f08;
P_0c0c3f06: /* original 6433, guest PC 0x0c0c3f06 */
if(!s->budget--) { s->failed_pc=0x0c0c3f06u; return 0; }
r[4]=r[3];
goto P_0c0c3f08;
P_0c0c3f08: /* original 88ff, guest PC 0x0c0c3f08 */
if(!s->budget--) { s->failed_pc=0x0c0c3f08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3f0a;
P_0c0c3f0a: /* original 8f02, guest PC 0x0c0c3f0a */
if(!s->budget--) { s->failed_pc=0x0c0c3f0au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c3f12; }
goto P_0c0c3f0e;
P_0c0c3f0c: /* original 6403, guest PC 0x0c0c3f0c */
if(!s->budget--) { s->failed_pc=0x0c0c3f0cu; return 0; }
r[4]=r[0];
goto P_0c0c3f0e;
P_0c0c3f0e: /* original a14b, guest PC 0x0c0c3f0e */
if(!s->budget--) { s->failed_pc=0x0c0c3f0eu; return 0; }
goto P_0c0c41a8;
P_0c0c3f10: /* original 0009, guest PC 0x0c0c3f10 */
if(!s->budget--) { s->failed_pc=0x0c0c3f10u; return 0; }
goto P_0c0c3f12;
P_0c0c3f12: /* original 9013, guest PC 0x0c0c3f12 */
if(!s->budget--) { s->failed_pc=0x0c0c3f12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3cu,2);
goto P_0c0c3f14;
P_0c0c3f14: /* original 03ec, guest PC 0x0c0c3f14 */
if(!s->budget--) { s->failed_pc=0x0c0c3f14u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3f16;
P_0c0c3f16: /* original 9012, guest PC 0x0c0c3f16 */
if(!s->budget--) { s->failed_pc=0x0c0c3f16u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3eu,2);
goto P_0c0c3f18;
P_0c0c3f18: /* original 0e34, guest PC 0x0c0c3f18 */
if(!s->budget--) { s->failed_pc=0x0c0c3f18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c3f1a;
P_0c0c3f1a: /* original 900f, guest PC 0x0c0c3f1a */
if(!s->budget--) { s->failed_pc=0x0c0c3f1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f3cu,2);
goto P_0c0c3f1c;
P_0c0c3f1c: /* original a0d6, guest PC 0x0c0c3f1c */
if(!s->budget--) { s->failed_pc=0x0c0c3f1cu; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0c40cc;
P_0c0c3f1e: /* original 0e84, guest PC 0x0c0c3f1e */
if(!s->budget--) { s->failed_pc=0x0c0c3f1eu; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0c3f20;
P_0c0c3f20: /* original 2448, guest PC 0x0c0c3f20 */
if(!s->budget--) { s->failed_pc=0x0c0c3f20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3f22;
P_0c0c3f22: /* original 8901, guest PC 0x0c0c3f22 */
if(!s->budget--) { s->failed_pc=0x0c0c3f22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3f28; }
goto P_0c0c3f24;
P_0c0c3f24: /* original a141, guest PC 0x0c0c3f24 */
if(!s->budget--) { s->failed_pc=0x0c0c3f24u; return 0; }
goto P_0c0c41aa;
P_0c0c3f26: /* original 0009, guest PC 0x0c0c3f26 */
if(!s->budget--) { s->failed_pc=0x0c0c3f26u; return 0; }
goto P_0c0c3f28;
P_0c0c3f28: /* original 900a, guest PC 0x0c0c3f28 */
if(!s->budget--) { s->failed_pc=0x0c0c3f28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3f40u,2);
goto P_0c0c3f2a;
P_0c0c3f2a: /* original 03ec, guest PC 0x0c0c3f2a */
if(!s->budget--) { s->failed_pc=0x0c0c3f2au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3f2c;
P_0c0c3f2c: /* original 7002, guest PC 0x0c0c3f2c */
if(!s->budget--) { s->failed_pc=0x0c0c3f2cu; return 0; }
r[0]+=0x00000002u;
goto P_0c0c3f2e;
P_0c0c3f2e: /* original 02ec, guest PC 0x0c0c3f2e */
if(!s->budget--) { s->failed_pc=0x0c0c3f2eu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3f30;
P_0c0c3f30: /* original 3320, guest PC 0x0c0c3f30 */
if(!s->budget--) { s->failed_pc=0x0c0c3f30u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c3f32;
P_0c0c3f32: /* original 8b09, guest PC 0x0c0c3f32 */
if(!s->budget--) { s->failed_pc=0x0c0c3f32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3f48; }
goto P_0c0c3f34;
P_0c0c3f34: /* original a009, guest PC 0x0c0c3f34 */
if(!s->budget--) { s->failed_pc=0x0c0c3f34u; return 0; }
r[4]=r[9];
goto P_0c0c3f4a;
P_0c0c3f36: /* original 6493, guest PC 0x0c0c3f36 */
if(!s->budget--) { s->failed_pc=0x0c0c3f36u; return 0; }
r[4]=r[9];
if(!vf3_matrix_family(0x0c0c3f38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3f38u; return 0; } return 1;
P_0c0c3f48: /* original e401, guest PC 0x0c0c3f48 */
if(!s->budget--) { s->failed_pc=0x0c0c3f48u; return 0; }
r[4]=0x00000001u;
goto P_0c0c3f4a;
P_0c0c3f4a: /* original 904a, guest PC 0x0c0c3f4a */
if(!s->budget--) { s->failed_pc=0x0c0c3f4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3fe2u,2);
goto P_0c0c3f4c;
P_0c0c3f4c: /* original 00ec, guest PC 0x0c0c3f4c */
if(!s->budget--) { s->failed_pc=0x0c0c3f4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3f4e;
P_0c0c3f4e: /* original 8801, guest PC 0x0c0c3f4e */
if(!s->budget--) { s->failed_pc=0x0c0c3f4eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c3f50;
P_0c0c3f50: /* original 8923, guest PC 0x0c0c3f50 */
if(!s->budget--) { s->failed_pc=0x0c0c3f50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3f9a; }
goto P_0c0c3f52;
P_0c0c3f52: /* original 2448, guest PC 0x0c0c3f52 */
if(!s->budget--) { s->failed_pc=0x0c0c3f52u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3f54;
P_0c0c3f54: /* original 894a, guest PC 0x0c0c3f54 */
if(!s->budget--) { s->failed_pc=0x0c0c3f54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3fec; }
goto P_0c0c3f56;
P_0c0c3f56: /* original e310, guest PC 0x0c0c3f56 */
if(!s->budget--) { s->failed_pc=0x0c0c3f56u; return 0; }
r[3]=0x00000010u;
goto P_0c0c3f58;
P_0c0c3f58: /* original 2a38, guest PC 0x0c0c3f58 */
if(!s->budget--) { s->failed_pc=0x0c0c3f58u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0c3f5a;
P_0c0c3f5a: /* original 8b01, guest PC 0x0c0c3f5a */
if(!s->budget--) { s->failed_pc=0x0c0c3f5au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3f60; }
goto P_0c0c3f5c;
P_0c0c3f5c: /* original a125, guest PC 0x0c0c3f5c */
if(!s->budget--) { s->failed_pc=0x0c0c3f5cu; return 0; }
goto P_0c0c41aa;
P_0c0c3f5e: /* original 0009, guest PC 0x0c0c3f5e */
if(!s->budget--) { s->failed_pc=0x0c0c3f5eu; return 0; }
goto P_0c0c3f60;
P_0c0c3f60: /* original 54ba, guest PC 0x0c0c3f60 */
if(!s->budget--) { s->failed_pc=0x0c0c3f60u; return 0; }
r[4]=read(ram,r[11]+40,4);
goto P_0c0c3f62;
P_0c0c3f62: /* original e30e, guest PC 0x0c0c3f62 */
if(!s->budget--) { s->failed_pc=0x0c0c3f62u; return 0; }
r[3]=0x0000000eu;
goto P_0c0c3f64;
P_0c0c3f64: /* original 6442, guest PC 0x0c0c3f64 */
if(!s->budget--) { s->failed_pc=0x0c0c3f64u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c3f66;
P_0c0c3f66: /* original 2438, guest PC 0x0c0c3f66 */
if(!s->budget--) { s->failed_pc=0x0c0c3f66u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c3f68;
P_0c0c3f68: /* original 8901, guest PC 0x0c0c3f68 */
if(!s->budget--) { s->failed_pc=0x0c0c3f68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3f6e; }
goto P_0c0c3f6a;
P_0c0c3f6a: /* original a11e, guest PC 0x0c0c3f6a */
if(!s->budget--) { s->failed_pc=0x0c0c3f6au; return 0; }
goto P_0c0c41aa;
P_0c0c3f6c: /* original 0009, guest PC 0x0c0c3f6c */
if(!s->budget--) { s->failed_pc=0x0c0c3f6cu; return 0; }
goto P_0c0c3f6e;
P_0c0c3f6e: /* original 51f3, guest PC 0x0c0c3f6e */
if(!s->budget--) { s->failed_pc=0x0c0c3f6eu; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c0c3f70;
P_0c0c3f70: /* original 2118, guest PC 0x0c0c3f70 */
if(!s->budget--) { s->failed_pc=0x0c0c3f70u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c3f72;
P_0c0c3f72: /* original 8901, guest PC 0x0c0c3f72 */
if(!s->budget--) { s->failed_pc=0x0c0c3f72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3f78; }
goto P_0c0c3f74;
P_0c0c3f74: /* original a118, guest PC 0x0c0c3f74 */
if(!s->budget--) { s->failed_pc=0x0c0c3f74u; return 0; }
goto P_0c0c41a8;
P_0c0c3f76: /* original 0009, guest PC 0x0c0c3f76 */
if(!s->budget--) { s->failed_pc=0x0c0c3f76u; return 0; }
goto P_0c0c3f78;
P_0c0c3f78: /* original 52f2, guest PC 0x0c0c3f78 */
if(!s->budget--) { s->failed_pc=0x0c0c3f78u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c3f7a;
P_0c0c3f7a: /* original 9133, guest PC 0x0c0c3f7a */
if(!s->budget--) { s->failed_pc=0x0c0c3f7au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3fe4u,2);
goto P_0c0c3f7c;
P_0c0c3f7c: /* original 3210, guest PC 0x0c0c3f7c */
if(!s->budget--) { s->failed_pc=0x0c0c3f7cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0c3f7e;
P_0c0c3f7e: /* original 8b00, guest PC 0x0c0c3f7e */
if(!s->budget--) { s->failed_pc=0x0c0c3f7eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3f82; }
goto P_0c0c3f80;
P_0c0c3f80: /* original 6df2, guest PC 0x0c0c3f80 */
if(!s->budget--) { s->failed_pc=0x0c0c3f80u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0c3f82;
P_0c0c3f82: /* original 9030, guest PC 0x0c0c3f82 */
if(!s->budget--) { s->failed_pc=0x0c0c3f82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3fe6u,2);
goto P_0c0c3f84;
P_0c0c3f84: /* original 03ec, guest PC 0x0c0c3f84 */
if(!s->budget--) { s->failed_pc=0x0c0c3f84u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3f86;
P_0c0c3f86: /* original 2f32, guest PC 0x0c0c3f86 */
if(!s->budget--) { s->failed_pc=0x0c0c3f86u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3f88;
P_0c0c3f88: /* original b119, guest PC 0x0c0c3f88 */
if(!s->budget--) { s->failed_pc=0x0c0c3f88u; return 0; }
target=code_base|0x0c0c41beu; r[16]=code_base|0x0c0c3f8cu;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3f8cu) { target=s->pc; goto dispatch; }
goto P_0c0c3f8c;
P_0c0c3f8a: /* original 6433, guest PC 0x0c0c3f8a */
if(!s->budget--) { s->failed_pc=0x0c0c3f8au; return 0; }
r[4]=r[3];
goto P_0c0c3f8c;
P_0c0c3f8c: /* original 88ff, guest PC 0x0c0c3f8c */
if(!s->budget--) { s->failed_pc=0x0c0c3f8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3f8e;
P_0c0c3f8e: /* original 8f02, guest PC 0x0c0c3f8e */
if(!s->budget--) { s->failed_pc=0x0c0c3f8eu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c3f96; }
goto P_0c0c3f92;
P_0c0c3f90: /* original 6403, guest PC 0x0c0c3f90 */
if(!s->budget--) { s->failed_pc=0x0c0c3f90u; return 0; }
r[4]=r[0];
goto P_0c0c3f92;
P_0c0c3f92: /* original a109, guest PC 0x0c0c3f92 */
if(!s->budget--) { s->failed_pc=0x0c0c3f92u; return 0; }
goto P_0c0c41a8;
P_0c0c3f94: /* original 0009, guest PC 0x0c0c3f94 */
if(!s->budget--) { s->failed_pc=0x0c0c3f94u; return 0; }
goto P_0c0c3f96;
P_0c0c3f96: /* original a060, guest PC 0x0c0c3f96 */
if(!s->budget--) { s->failed_pc=0x0c0c3f96u; return 0; }
goto P_0c0c405a;
P_0c0c3f98: /* original 0009, guest PC 0x0c0c3f98 */
if(!s->budget--) { s->failed_pc=0x0c0c3f98u; return 0; }
goto P_0c0c3f9a;
P_0c0c3f9a: /* original 2448, guest PC 0x0c0c3f9a */
if(!s->budget--) { s->failed_pc=0x0c0c3f9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c3f9c;
P_0c0c3f9c: /* original 8960, guest PC 0x0c0c3f9c */
if(!s->budget--) { s->failed_pc=0x0c0c3f9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4060; }
goto P_0c0c3f9e;
P_0c0c3f9e: /* original e320, guest PC 0x0c0c3f9e */
if(!s->budget--) { s->failed_pc=0x0c0c3f9eu; return 0; }
r[3]=0x00000020u;
goto P_0c0c3fa0;
P_0c0c3fa0: /* original 2a38, guest PC 0x0c0c3fa0 */
if(!s->budget--) { s->failed_pc=0x0c0c3fa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0c3fa2;
P_0c0c3fa2: /* original 8b01, guest PC 0x0c0c3fa2 */
if(!s->budget--) { s->failed_pc=0x0c0c3fa2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3fa8; }
goto P_0c0c3fa4;
P_0c0c3fa4: /* original a101, guest PC 0x0c0c3fa4 */
if(!s->budget--) { s->failed_pc=0x0c0c3fa4u; return 0; }
goto P_0c0c41aa;
P_0c0c3fa6: /* original 0009, guest PC 0x0c0c3fa6 */
if(!s->budget--) { s->failed_pc=0x0c0c3fa6u; return 0; }
goto P_0c0c3fa8;
P_0c0c3fa8: /* original 54bb, guest PC 0x0c0c3fa8 */
if(!s->budget--) { s->failed_pc=0x0c0c3fa8u; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c0c3faa;
P_0c0c3faa: /* original e30e, guest PC 0x0c0c3faa */
if(!s->budget--) { s->failed_pc=0x0c0c3faau; return 0; }
r[3]=0x0000000eu;
goto P_0c0c3fac;
P_0c0c3fac: /* original 6442, guest PC 0x0c0c3fac */
if(!s->budget--) { s->failed_pc=0x0c0c3facu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c3fae;
P_0c0c3fae: /* original 2438, guest PC 0x0c0c3fae */
if(!s->budget--) { s->failed_pc=0x0c0c3faeu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c3fb0;
P_0c0c3fb0: /* original 8901, guest PC 0x0c0c3fb0 */
if(!s->budget--) { s->failed_pc=0x0c0c3fb0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3fb6; }
goto P_0c0c3fb2;
P_0c0c3fb2: /* original a0fa, guest PC 0x0c0c3fb2 */
if(!s->budget--) { s->failed_pc=0x0c0c3fb2u; return 0; }
goto P_0c0c41aa;
P_0c0c3fb4: /* original 0009, guest PC 0x0c0c3fb4 */
if(!s->budget--) { s->failed_pc=0x0c0c3fb4u; return 0; }
goto P_0c0c3fb6;
P_0c0c3fb6: /* original 51f5, guest PC 0x0c0c3fb6 */
if(!s->budget--) { s->failed_pc=0x0c0c3fb6u; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c0c3fb8;
P_0c0c3fb8: /* original 2118, guest PC 0x0c0c3fb8 */
if(!s->budget--) { s->failed_pc=0x0c0c3fb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c3fba;
P_0c0c3fba: /* original 8901, guest PC 0x0c0c3fba */
if(!s->budget--) { s->failed_pc=0x0c0c3fbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3fc0; }
goto P_0c0c3fbc;
P_0c0c3fbc: /* original a0f4, guest PC 0x0c0c3fbc */
if(!s->budget--) { s->failed_pc=0x0c0c3fbcu; return 0; }
goto P_0c0c41a8;
P_0c0c3fbe: /* original 0009, guest PC 0x0c0c3fbe */
if(!s->budget--) { s->failed_pc=0x0c0c3fbeu; return 0; }
goto P_0c0c3fc0;
P_0c0c3fc0: /* original 53f1, guest PC 0x0c0c3fc0 */
if(!s->budget--) { s->failed_pc=0x0c0c3fc0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c3fc2;
P_0c0c3fc2: /* original d409, guest PC 0x0c0c3fc2 */
if(!s->budget--) { s->failed_pc=0x0c0c3fc2u; return 0; }
r[4]=read(ram,0x0c0c3fe8u,4);
goto P_0c0c3fc4;
P_0c0c3fc4: /* original 3340, guest PC 0x0c0c3fc4 */
if(!s->budget--) { s->failed_pc=0x0c0c3fc4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0c3fc6;
P_0c0c3fc6: /* original 8b00, guest PC 0x0c0c3fc6 */
if(!s->budget--) { s->failed_pc=0x0c0c3fc6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3fca; }
goto P_0c0c3fc8;
P_0c0c3fc8: /* original 6d63, guest PC 0x0c0c3fc8 */
if(!s->budget--) { s->failed_pc=0x0c0c3fc8u; return 0; }
r[13]=r[6];
goto P_0c0c3fca;
P_0c0c3fca: /* original 900c, guest PC 0x0c0c3fca */
if(!s->budget--) { s->failed_pc=0x0c0c3fcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c3fe6u,2);
goto P_0c0c3fcc;
P_0c0c3fcc: /* original 03ec, guest PC 0x0c0c3fcc */
if(!s->budget--) { s->failed_pc=0x0c0c3fccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3fce;
P_0c0c3fce: /* original 2f32, guest PC 0x0c0c3fce */
if(!s->budget--) { s->failed_pc=0x0c0c3fceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c3fd0;
P_0c0c3fd0: /* original b145, guest PC 0x0c0c3fd0 */
if(!s->budget--) { s->failed_pc=0x0c0c3fd0u; return 0; }
target=code_base|0x0c0c425eu; r[16]=code_base|0x0c0c3fd4u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3fd4u) { target=s->pc; goto dispatch; }
goto P_0c0c3fd4;
P_0c0c3fd2: /* original 6433, guest PC 0x0c0c3fd2 */
if(!s->budget--) { s->failed_pc=0x0c0c3fd2u; return 0; }
r[4]=r[3];
goto P_0c0c3fd4;
P_0c0c3fd4: /* original 88ff, guest PC 0x0c0c3fd4 */
if(!s->budget--) { s->failed_pc=0x0c0c3fd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3fd6;
P_0c0c3fd6: /* original 8f02, guest PC 0x0c0c3fd6 */
if(!s->budget--) { s->failed_pc=0x0c0c3fd6u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c3fde; }
goto P_0c0c3fda;
P_0c0c3fd8: /* original 6403, guest PC 0x0c0c3fd8 */
if(!s->budget--) { s->failed_pc=0x0c0c3fd8u; return 0; }
r[4]=r[0];
goto P_0c0c3fda;
P_0c0c3fda: /* original a0e5, guest PC 0x0c0c3fda */
if(!s->budget--) { s->failed_pc=0x0c0c3fdau; return 0; }
goto P_0c0c41a8;
P_0c0c3fdc: /* original 0009, guest PC 0x0c0c3fdc */
if(!s->budget--) { s->failed_pc=0x0c0c3fdcu; return 0; }
goto P_0c0c3fde;
P_0c0c3fde: /* original a075, guest PC 0x0c0c3fde */
if(!s->budget--) { s->failed_pc=0x0c0c3fdeu; return 0; }
goto P_0c0c40cc;
P_0c0c3fe0: /* original 0009, guest PC 0x0c0c3fe0 */
if(!s->budget--) { s->failed_pc=0x0c0c3fe0u; return 0; }
if(!vf3_matrix_family(0x0c0c3fe2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3fe2u; return 0; } return 1;
P_0c0c3fec: /* original 63c2, guest PC 0x0c0c3fec */
if(!s->budget--) { s->failed_pc=0x0c0c3fecu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c3fee;
P_0c0c3fee: /* original d23b, guest PC 0x0c0c3fee */
if(!s->budget--) { s->failed_pc=0x0c0c3feeu; return 0; }
r[2]=read(ram,0x0c0c40dcu,4);
goto P_0c0c3ff0;
P_0c0c3ff0: /* original 3320, guest PC 0x0c0c3ff0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ff0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c3ff2;
P_0c0c3ff2: /* original 8b12, guest PC 0x0c0c3ff2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ff2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c401a; }
goto P_0c0c3ff4;
P_0c0c3ff4: /* original 51e2, guest PC 0x0c0c3ff4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ff4u; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c0c3ff6;
P_0c0c3ff6: /* original d33a, guest PC 0x0c0c3ff6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ff6u; return 0; }
r[3]=read(ram,0x0c0c40e0u,4);
goto P_0c0c3ff8;
P_0c0c3ff8: /* original 2138, guest PC 0x0c0c3ff8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ff8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c3ffa;
P_0c0c3ffa: /* original 8901, guest PC 0x0c0c3ffa */
if(!s->budget--) { s->failed_pc=0x0c0c3ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4000; }
goto P_0c0c3ffc;
P_0c0c3ffc: /* original a0d4, guest PC 0x0c0c3ffc */
if(!s->budget--) { s->failed_pc=0x0c0c3ffcu; return 0; }
goto P_0c0c41a8;
P_0c0c3ffe: /* original 0009, guest PC 0x0c0c3ffe */
if(!s->budget--) { s->failed_pc=0x0c0c3ffeu; return 0; }
goto P_0c0c4000;
P_0c0c4000: /* original 9067, guest PC 0x0c0c4000 */
if(!s->budget--) { s->failed_pc=0x0c0c4000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d2u,2);
goto P_0c0c4002;
P_0c0c4002: /* original 01cc, guest PC 0x0c0c4002 */
if(!s->budget--) { s->failed_pc=0x0c0c4002u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4004;
P_0c0c4004: /* original 2118, guest PC 0x0c0c4004 */
if(!s->budget--) { s->failed_pc=0x0c0c4004u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c4006;
P_0c0c4006: /* original 8901, guest PC 0x0c0c4006 */
if(!s->budget--) { s->failed_pc=0x0c0c4006u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c400c; }
goto P_0c0c4008;
P_0c0c4008: /* original a0ce, guest PC 0x0c0c4008 */
if(!s->budget--) { s->failed_pc=0x0c0c4008u; return 0; }
goto P_0c0c41a8;
P_0c0c400a: /* original 0009, guest PC 0x0c0c400a */
if(!s->budget--) { s->failed_pc=0x0c0c400au; return 0; }
goto P_0c0c400c;
P_0c0c400c: /* original d336, guest PC 0x0c0c400c */
if(!s->budget--) { s->failed_pc=0x0c0c400cu; return 0; }
r[3]=read(ram,0x0c0c40e8u,4);
goto P_0c0c400e;
P_0c0c400e: /* original d235, guest PC 0x0c0c400e */
if(!s->budget--) { s->failed_pc=0x0c0c400eu; return 0; }
r[2]=read(ram,0x0c0c40e4u,4);
goto P_0c0c4010;
P_0c0c4010: /* original 6132, guest PC 0x0c0c4010 */
if(!s->budget--) { s->failed_pc=0x0c0c4010u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0c4012;
P_0c0c4012: /* original 2128, guest PC 0x0c0c4012 */
if(!s->budget--) { s->failed_pc=0x0c0c4012u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0c4014;
P_0c0c4014: /* original 8901, guest PC 0x0c0c4014 */
if(!s->budget--) { s->failed_pc=0x0c0c4014u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c401a; }
goto P_0c0c4016;
P_0c0c4016: /* original a0c7, guest PC 0x0c0c4016 */
if(!s->budget--) { s->failed_pc=0x0c0c4016u; return 0; }
goto P_0c0c41a8;
P_0c0c4018: /* original 0009, guest PC 0x0c0c4018 */
if(!s->budget--) { s->failed_pc=0x0c0c4018u; return 0; }
goto P_0c0c401a;
P_0c0c401a: /* original e310, guest PC 0x0c0c401a */
if(!s->budget--) { s->failed_pc=0x0c0c401au; return 0; }
r[3]=0x00000010u;
goto P_0c0c401c;
P_0c0c401c: /* original 23a8, guest PC 0x0c0c401c */
if(!s->budget--) { s->failed_pc=0x0c0c401cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0c401e;
P_0c0c401e: /* original 891f, guest PC 0x0c0c401e */
if(!s->budget--) { s->failed_pc=0x0c0c401eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4060; }
goto P_0c0c4020;
P_0c0c4020: /* original 54ba, guest PC 0x0c0c4020 */
if(!s->budget--) { s->failed_pc=0x0c0c4020u; return 0; }
r[4]=read(ram,r[11]+40,4);
goto P_0c0c4022;
P_0c0c4022: /* original e30e, guest PC 0x0c0c4022 */
if(!s->budget--) { s->failed_pc=0x0c0c4022u; return 0; }
r[3]=0x0000000eu;
goto P_0c0c4024;
P_0c0c4024: /* original 6442, guest PC 0x0c0c4024 */
if(!s->budget--) { s->failed_pc=0x0c0c4024u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c4026;
P_0c0c4026: /* original 2438, guest PC 0x0c0c4026 */
if(!s->budget--) { s->failed_pc=0x0c0c4026u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4028;
P_0c0c4028: /* original 8b1a, guest PC 0x0c0c4028 */
if(!s->budget--) { s->failed_pc=0x0c0c4028u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4060; }
goto P_0c0c402a;
P_0c0c402a: /* original 52f3, guest PC 0x0c0c402a */
if(!s->budget--) { s->failed_pc=0x0c0c402au; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c402c;
P_0c0c402c: /* original 2228, guest PC 0x0c0c402c */
if(!s->budget--) { s->failed_pc=0x0c0c402cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c402e;
P_0c0c402e: /* original 8b17, guest PC 0x0c0c402e */
if(!s->budget--) { s->failed_pc=0x0c0c402eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4060; }
goto P_0c0c4030;
P_0c0c4030: /* original 52f2, guest PC 0x0c0c4030 */
if(!s->budget--) { s->failed_pc=0x0c0c4030u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c4032;
P_0c0c4032: /* original 914f, guest PC 0x0c0c4032 */
if(!s->budget--) { s->failed_pc=0x0c0c4032u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d4u,2);
goto P_0c0c4034;
P_0c0c4034: /* original 3210, guest PC 0x0c0c4034 */
if(!s->budget--) { s->failed_pc=0x0c0c4034u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c0c4036;
P_0c0c4036: /* original 8b00, guest PC 0x0c0c4036 */
if(!s->budget--) { s->failed_pc=0x0c0c4036u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c403a; }
goto P_0c0c4038;
P_0c0c4038: /* original 6df2, guest PC 0x0c0c4038 */
if(!s->budget--) { s->failed_pc=0x0c0c4038u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0c403a;
P_0c0c403a: /* original 53f7, guest PC 0x0c0c403a */
if(!s->budget--) { s->failed_pc=0x0c0c403au; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c0c403c;
P_0c0c403c: /* original 2390, guest PC 0x0c0c403c */
if(!s->budget--) { s->failed_pc=0x0c0c403cu; return 0; }
write(ram,r[3],r[9],1);
goto P_0c0c403e;
P_0c0c403e: /* original 904a, guest PC 0x0c0c403e */
if(!s->budget--) { s->failed_pc=0x0c0c403eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d6u,2);
goto P_0c0c4040;
P_0c0c4040: /* original 03ec, guest PC 0x0c0c4040 */
if(!s->budget--) { s->failed_pc=0x0c0c4040u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4042;
P_0c0c4042: /* original 2f32, guest PC 0x0c0c4042 */
if(!s->budget--) { s->failed_pc=0x0c0c4042u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c4044;
P_0c0c4044: /* original b0bb, guest PC 0x0c0c4044 */
if(!s->budget--) { s->failed_pc=0x0c0c4044u; return 0; }
target=code_base|0x0c0c41beu; r[16]=code_base|0x0c0c4048u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4048u) { target=s->pc; goto dispatch; }
goto P_0c0c4048;
P_0c0c4046: /* original 6433, guest PC 0x0c0c4046 */
if(!s->budget--) { s->failed_pc=0x0c0c4046u; return 0; }
r[4]=r[3];
goto P_0c0c4048;
P_0c0c4048: /* original 88ff, guest PC 0x0c0c4048 */
if(!s->budget--) { s->failed_pc=0x0c0c4048u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c404a;
P_0c0c404a: /* original 8f02, guest PC 0x0c0c404a */
if(!s->budget--) { s->failed_pc=0x0c0c404au; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c4052; }
goto P_0c0c404e;
P_0c0c404c: /* original 6403, guest PC 0x0c0c404c */
if(!s->budget--) { s->failed_pc=0x0c0c404cu; return 0; }
r[4]=r[0];
goto P_0c0c404e;
P_0c0c404e: /* original a0ab, guest PC 0x0c0c404e */
if(!s->budget--) { s->failed_pc=0x0c0c404eu; return 0; }
goto P_0c0c41a8;
P_0c0c4050: /* original 0009, guest PC 0x0c0c4050 */
if(!s->budget--) { s->failed_pc=0x0c0c4050u; return 0; }
goto P_0c0c4052;
P_0c0c4052: /* original d326, guest PC 0x0c0c4052 */
if(!s->budget--) { s->failed_pc=0x0c0c4052u; return 0; }
r[3]=read(ram,0x0c0c40ecu,4);
goto P_0c0c4054;
P_0c0c4054: /* original 9440, guest PC 0x0c0c4054 */
if(!s->budget--) { s->failed_pc=0x0c0c4054u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d8u,2);
goto P_0c0c4056;
P_0c0c4056: /* original 430b, guest PC 0x0c0c4056 */
if(!s->budget--) { s->failed_pc=0x0c0c4056u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c405au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c405au) { target=s->pc; goto dispatch; }
goto P_0c0c405a;
P_0c0c4058: /* original 0009, guest PC 0x0c0c4058 */
if(!s->budget--) { s->failed_pc=0x0c0c4058u; return 0; }
goto P_0c0c405a;
P_0c0c405a: /* original d225, guest PC 0x0c0c405a */
if(!s->budget--) { s->failed_pc=0x0c0c405au; return 0; }
r[2]=read(ram,0x0c0c40f0u,4);
goto P_0c0c405c;
P_0c0c405c: /* original a0a4, guest PC 0x0c0c405c */
if(!s->budget--) { s->failed_pc=0x0c0c405cu; return 0; }
r[13]|=r[2];
goto P_0c0c41a8;
P_0c0c405e: /* original 2d2b, guest PC 0x0c0c405e */
if(!s->budget--) { s->failed_pc=0x0c0c405eu; return 0; }
r[13]|=r[2];
goto P_0c0c4060;
P_0c0c4060: /* original 61c2, guest PC 0x0c0c4060 */
if(!s->budget--) { s->failed_pc=0x0c0c4060u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0c4062;
P_0c0c4062: /* original d31e, guest PC 0x0c0c4062 */
if(!s->budget--) { s->failed_pc=0x0c0c4062u; return 0; }
r[3]=read(ram,0x0c0c40dcu,4);
goto P_0c0c4064;
P_0c0c4064: /* original 2138, guest PC 0x0c0c4064 */
if(!s->budget--) { s->failed_pc=0x0c0c4064u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c4066;
P_0c0c4066: /* original 890b, guest PC 0x0c0c4066 */
if(!s->budget--) { s->failed_pc=0x0c0c4066u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4080; }
goto P_0c0c4068;
P_0c0c4068: /* original 50e2, guest PC 0x0c0c4068 */
if(!s->budget--) { s->failed_pc=0x0c0c4068u; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0c406a;
P_0c0c406a: /* original d21d, guest PC 0x0c0c406a */
if(!s->budget--) { s->failed_pc=0x0c0c406au; return 0; }
r[2]=read(ram,0x0c0c40e0u,4);
goto P_0c0c406c;
P_0c0c406c: /* original 2028, guest PC 0x0c0c406c */
if(!s->budget--) { s->failed_pc=0x0c0c406cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[2])==0)!=0);
goto P_0c0c406e;
P_0c0c406e: /* original 8901, guest PC 0x0c0c406e */
if(!s->budget--) { s->failed_pc=0x0c0c406eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4074; }
goto P_0c0c4070;
P_0c0c4070: /* original a09a, guest PC 0x0c0c4070 */
if(!s->budget--) { s->failed_pc=0x0c0c4070u; return 0; }
goto P_0c0c41a8;
P_0c0c4072: /* original 0009, guest PC 0x0c0c4072 */
if(!s->budget--) { s->failed_pc=0x0c0c4072u; return 0; }
goto P_0c0c4074;
P_0c0c4074: /* original 902d, guest PC 0x0c0c4074 */
if(!s->budget--) { s->failed_pc=0x0c0c4074u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d2u,2);
goto P_0c0c4076;
P_0c0c4076: /* original 01cc, guest PC 0x0c0c4076 */
if(!s->budget--) { s->failed_pc=0x0c0c4076u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0c4078;
P_0c0c4078: /* original 2118, guest PC 0x0c0c4078 */
if(!s->budget--) { s->failed_pc=0x0c0c4078u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c407a;
P_0c0c407a: /* original 8901, guest PC 0x0c0c407a */
if(!s->budget--) { s->failed_pc=0x0c0c407au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4080; }
goto P_0c0c407c;
P_0c0c407c: /* original a094, guest PC 0x0c0c407c */
if(!s->budget--) { s->failed_pc=0x0c0c407cu; return 0; }
goto P_0c0c41a8;
P_0c0c407e: /* original 0009, guest PC 0x0c0c407e */
if(!s->budget--) { s->failed_pc=0x0c0c407eu; return 0; }
goto P_0c0c4080;
P_0c0c4080: /* original e120, guest PC 0x0c0c4080 */
if(!s->budget--) { s->failed_pc=0x0c0c4080u; return 0; }
r[1]=0x00000020u;
goto P_0c0c4082;
P_0c0c4082: /* original 2a18, guest PC 0x0c0c4082 */
if(!s->budget--) { s->failed_pc=0x0c0c4082u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[1])==0)!=0);
goto P_0c0c4084;
P_0c0c4084: /* original 8b01, guest PC 0x0c0c4084 */
if(!s->budget--) { s->failed_pc=0x0c0c4084u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c408a; }
goto P_0c0c4086;
P_0c0c4086: /* original a08f, guest PC 0x0c0c4086 */
if(!s->budget--) { s->failed_pc=0x0c0c4086u; return 0; }
goto P_0c0c41a8;
P_0c0c4088: /* original 0009, guest PC 0x0c0c4088 */
if(!s->budget--) { s->failed_pc=0x0c0c4088u; return 0; }
goto P_0c0c408a;
P_0c0c408a: /* original 54bb, guest PC 0x0c0c408a */
if(!s->budget--) { s->failed_pc=0x0c0c408au; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c0c408c;
P_0c0c408c: /* original e30e, guest PC 0x0c0c408c */
if(!s->budget--) { s->failed_pc=0x0c0c408cu; return 0; }
r[3]=0x0000000eu;
goto P_0c0c408e;
P_0c0c408e: /* original 6442, guest PC 0x0c0c408e */
if(!s->budget--) { s->failed_pc=0x0c0c408eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c4090;
P_0c0c4090: /* original 2438, guest PC 0x0c0c4090 */
if(!s->budget--) { s->failed_pc=0x0c0c4090u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4092;
P_0c0c4092: /* original 8901, guest PC 0x0c0c4092 */
if(!s->budget--) { s->failed_pc=0x0c0c4092u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4098; }
goto P_0c0c4094;
P_0c0c4094: /* original a088, guest PC 0x0c0c4094 */
if(!s->budget--) { s->failed_pc=0x0c0c4094u; return 0; }
goto P_0c0c41a8;
P_0c0c4096: /* original 0009, guest PC 0x0c0c4096 */
if(!s->budget--) { s->failed_pc=0x0c0c4096u; return 0; }
goto P_0c0c4098;
P_0c0c4098: /* original 52f5, guest PC 0x0c0c4098 */
if(!s->budget--) { s->failed_pc=0x0c0c4098u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0c409a;
P_0c0c409a: /* original 2228, guest PC 0x0c0c409a */
if(!s->budget--) { s->failed_pc=0x0c0c409au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c409c;
P_0c0c409c: /* original 8901, guest PC 0x0c0c409c */
if(!s->budget--) { s->failed_pc=0x0c0c409cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c40a2; }
goto P_0c0c409e;
P_0c0c409e: /* original a083, guest PC 0x0c0c409e */
if(!s->budget--) { s->failed_pc=0x0c0c409eu; return 0; }
goto P_0c0c41a8;
P_0c0c40a0: /* original 0009, guest PC 0x0c0c40a0 */
if(!s->budget--) { s->failed_pc=0x0c0c40a0u; return 0; }
goto P_0c0c40a2;
P_0c0c40a2: /* original 53f1, guest PC 0x0c0c40a2 */
if(!s->budget--) { s->failed_pc=0x0c0c40a2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c40a4;
P_0c0c40a4: /* original d413, guest PC 0x0c0c40a4 */
if(!s->budget--) { s->failed_pc=0x0c0c40a4u; return 0; }
r[4]=read(ram,0x0c0c40f4u,4);
goto P_0c0c40a6;
P_0c0c40a6: /* original 3340, guest PC 0x0c0c40a6 */
if(!s->budget--) { s->failed_pc=0x0c0c40a6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0c40a8;
P_0c0c40a8: /* original 8b01, guest PC 0x0c0c40a8 */
if(!s->budget--) { s->failed_pc=0x0c0c40a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c40ae; }
goto P_0c0c40aa;
P_0c0c40aa: /* original 9216, guest PC 0x0c0c40aa */
if(!s->budget--) { s->failed_pc=0x0c0c40aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40dau,2);
goto P_0c0c40ac;
P_0c0c40ac: /* original 2d2b, guest PC 0x0c0c40ac */
if(!s->budget--) { s->failed_pc=0x0c0c40acu; return 0; }
r[13]|=r[2];
goto P_0c0c40ae;
P_0c0c40ae: /* original 53f7, guest PC 0x0c0c40ae */
if(!s->budget--) { s->failed_pc=0x0c0c40aeu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c0c40b0;
P_0c0c40b0: /* original 6093, guest PC 0x0c0c40b0 */
if(!s->budget--) { s->failed_pc=0x0c0c40b0u; return 0; }
r[0]=r[9];
goto P_0c0c40b2;
P_0c0c40b2: /* original 8031, guest PC 0x0c0c40b2 */
if(!s->budget--) { s->failed_pc=0x0c0c40b2u; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c0c40b4;
P_0c0c40b4: /* original 900f, guest PC 0x0c0c40b4 */
if(!s->budget--) { s->failed_pc=0x0c0c40b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d6u,2);
goto P_0c0c40b6;
P_0c0c40b6: /* original 03ec, guest PC 0x0c0c40b6 */
if(!s->budget--) { s->failed_pc=0x0c0c40b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c40b8;
P_0c0c40b8: /* original 2f32, guest PC 0x0c0c40b8 */
if(!s->budget--) { s->failed_pc=0x0c0c40b8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c40ba;
P_0c0c40ba: /* original b0d0, guest PC 0x0c0c40ba */
if(!s->budget--) { s->failed_pc=0x0c0c40bau; return 0; }
target=code_base|0x0c0c425eu; r[16]=code_base|0x0c0c40beu;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c40beu) { target=s->pc; goto dispatch; }
goto P_0c0c40be;
P_0c0c40bc: /* original 6433, guest PC 0x0c0c40bc */
if(!s->budget--) { s->failed_pc=0x0c0c40bcu; return 0; }
r[4]=r[3];
goto P_0c0c40be;
P_0c0c40be: /* original 88ff, guest PC 0x0c0c40be */
if(!s->budget--) { s->failed_pc=0x0c0c40beu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c40c0;
P_0c0c40c0: /* original 8d72, guest PC 0x0c0c40c0 */
if(!s->budget--) { s->failed_pc=0x0c0c40c0u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c41a8; }
goto P_0c0c40c4;
P_0c0c40c2: /* original 6403, guest PC 0x0c0c40c2 */
if(!s->budget--) { s->failed_pc=0x0c0c40c2u; return 0; }
r[4]=r[0];
goto P_0c0c40c4;
P_0c0c40c4: /* original d309, guest PC 0x0c0c40c4 */
if(!s->budget--) { s->failed_pc=0x0c0c40c4u; return 0; }
r[3]=read(ram,0x0c0c40ecu,4);
goto P_0c0c40c6;
P_0c0c40c6: /* original 9407, guest PC 0x0c0c40c6 */
if(!s->budget--) { s->failed_pc=0x0c0c40c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c40d8u,2);
goto P_0c0c40c8;
P_0c0c40c8: /* original 430b, guest PC 0x0c0c40c8 */
if(!s->budget--) { s->failed_pc=0x0c0c40c8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c40ccu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c40ccu) { target=s->pc; goto dispatch; }
goto P_0c0c40cc;
P_0c0c40ca: /* original 0009, guest PC 0x0c0c40ca */
if(!s->budget--) { s->failed_pc=0x0c0c40cau; return 0; }
goto P_0c0c40cc;
P_0c0c40cc: /* original d20a, guest PC 0x0c0c40cc */
if(!s->budget--) { s->failed_pc=0x0c0c40ccu; return 0; }
r[2]=read(ram,0x0c0c40f8u,4);
goto P_0c0c40ce;
P_0c0c40ce: /* original a06b, guest PC 0x0c0c40ce */
if(!s->budget--) { s->failed_pc=0x0c0c40ceu; return 0; }
r[13]|=r[2];
goto P_0c0c41a8;
P_0c0c40d0: /* original 2d2b, guest PC 0x0c0c40d0 */
if(!s->budget--) { s->failed_pc=0x0c0c40d0u; return 0; }
r[13]|=r[2];
if(!vf3_matrix_family(0x0c0c40d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c40d2u; return 0; } return 1;
P_0c0c40fc: /* original e110, guest PC 0x0c0c40fc */
if(!s->budget--) { s->failed_pc=0x0c0c40fcu; return 0; }
r[1]=0x00000010u;
goto P_0c0c40fe;
P_0c0c40fe: /* original 21a8, guest PC 0x0c0c40fe */
if(!s->budget--) { s->failed_pc=0x0c0c40feu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[10])==0)!=0);
goto P_0c0c4100;
P_0c0c4100: /* original 8927, guest PC 0x0c0c4100 */
if(!s->budget--) { s->failed_pc=0x0c0c4100u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4152; }
goto P_0c0c4102;
P_0c0c4102: /* original 54ba, guest PC 0x0c0c4102 */
if(!s->budget--) { s->failed_pc=0x0c0c4102u; return 0; }
r[4]=read(ram,r[11]+40,4);
goto P_0c0c4104;
P_0c0c4104: /* original e30e, guest PC 0x0c0c4104 */
if(!s->budget--) { s->failed_pc=0x0c0c4104u; return 0; }
r[3]=0x0000000eu;
goto P_0c0c4106;
P_0c0c4106: /* original 6442, guest PC 0x0c0c4106 */
if(!s->budget--) { s->failed_pc=0x0c0c4106u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c4108;
P_0c0c4108: /* original 2438, guest PC 0x0c0c4108 */
if(!s->budget--) { s->failed_pc=0x0c0c4108u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c410a;
P_0c0c410a: /* original 8b22, guest PC 0x0c0c410a */
if(!s->budget--) { s->failed_pc=0x0c0c410au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4152; }
goto P_0c0c410c;
P_0c0c410c: /* original 52f3, guest PC 0x0c0c410c */
if(!s->budget--) { s->failed_pc=0x0c0c410cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c0c410e;
P_0c0c410e: /* original 2228, guest PC 0x0c0c410e */
if(!s->budget--) { s->failed_pc=0x0c0c410eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4110;
P_0c0c4110: /* original 8b1f, guest PC 0x0c0c4110 */
if(!s->budget--) { s->failed_pc=0x0c0c4110u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4152; }
goto P_0c0c4112;
P_0c0c4112: /* original 9067, guest PC 0x0c0c4112 */
if(!s->budget--) { s->failed_pc=0x0c0c4112u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e4u,2);
goto P_0c0c4114;
P_0c0c4114: /* original 00ec, guest PC 0x0c0c4114 */
if(!s->budget--) { s->failed_pc=0x0c0c4114u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4116;
P_0c0c4116: /* original 8802, guest PC 0x0c0c4116 */
if(!s->budget--) { s->failed_pc=0x0c0c4116u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c4118;
P_0c0c4118: /* original 898a, guest PC 0x0c0c4118 */
if(!s->budget--) { s->failed_pc=0x0c0c4118u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4030; }
goto P_0c0c411a;
P_0c0c411a: /* original 52f2, guest PC 0x0c0c411a */
if(!s->budget--) { s->failed_pc=0x0c0c411au; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c411c;
P_0c0c411c: /* original 9363, guest PC 0x0c0c411c */
if(!s->budget--) { s->failed_pc=0x0c0c411cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e6u,2);
goto P_0c0c411e;
P_0c0c411e: /* original 3230, guest PC 0x0c0c411e */
if(!s->budget--) { s->failed_pc=0x0c0c411eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0c4120;
P_0c0c4120: /* original 8b00, guest PC 0x0c0c4120 */
if(!s->budget--) { s->failed_pc=0x0c0c4120u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4124; }
goto P_0c0c4122;
P_0c0c4122: /* original 6df2, guest PC 0x0c0c4122 */
if(!s->budget--) { s->failed_pc=0x0c0c4122u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c0c4124;
P_0c0c4124: /* original 9060, guest PC 0x0c0c4124 */
if(!s->budget--) { s->failed_pc=0x0c0c4124u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e8u,2);
goto P_0c0c4126;
P_0c0c4126: /* original d333, guest PC 0x0c0c4126 */
if(!s->budget--) { s->failed_pc=0x0c0c4126u; return 0; }
r[3]=read(ram,0x0c0c41f4u,4);
goto P_0c0c4128;
P_0c0c4128: /* original 02ec, guest PC 0x0c0c4128 */
if(!s->budget--) { s->failed_pc=0x0c0c4128u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c412a;
P_0c0c412a: /* original 2d3b, guest PC 0x0c0c412a */
if(!s->budget--) { s->failed_pc=0x0c0c412au; return 0; }
r[13]|=r[3];
goto P_0c0c412c;
P_0c0c412c: /* original 2f22, guest PC 0x0c0c412c */
if(!s->budget--) { s->failed_pc=0x0c0c412cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c412e;
P_0c0c412e: /* original b046, guest PC 0x0c0c412e */
if(!s->budget--) { s->failed_pc=0x0c0c412eu; return 0; }
target=code_base|0x0c0c41beu; r[16]=code_base|0x0c0c4132u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4132u) { target=s->pc; goto dispatch; }
goto P_0c0c4132;
P_0c0c4130: /* original 6423, guest PC 0x0c0c4130 */
if(!s->budget--) { s->failed_pc=0x0c0c4130u; return 0; }
r[4]=r[2];
goto P_0c0c4132;
P_0c0c4132: /* original 88ff, guest PC 0x0c0c4132 */
if(!s->budget--) { s->failed_pc=0x0c0c4132u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4134;
P_0c0c4134: /* original 8d0d, guest PC 0x0c0c4134 */
if(!s->budget--) { s->failed_pc=0x0c0c4134u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c4152; }
goto P_0c0c4138;
P_0c0c4136: /* original 6403, guest PC 0x0c0c4136 */
if(!s->budget--) { s->failed_pc=0x0c0c4136u; return 0; }
r[4]=r[0];
goto P_0c0c4138;
P_0c0c4138: /* original d32f, guest PC 0x0c0c4138 */
if(!s->budget--) { s->failed_pc=0x0c0c4138u; return 0; }
r[3]=read(ram,0x0c0c41f8u,4);
goto P_0c0c413a;
P_0c0c413a: /* original 9456, guest PC 0x0c0c413a */
if(!s->budget--) { s->failed_pc=0x0c0c413au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41eau,2);
goto P_0c0c413c;
P_0c0c413c: /* original 430b, guest PC 0x0c0c413c */
if(!s->budget--) { s->failed_pc=0x0c0c413cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4140u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4140u) { target=s->pc; goto dispatch; }
goto P_0c0c4140;
P_0c0c413e: /* original 0009, guest PC 0x0c0c413e */
if(!s->budget--) { s->failed_pc=0x0c0c413eu; return 0; }
goto P_0c0c4140;
P_0c0c4140: /* original 9050, guest PC 0x0c0c4140 */
if(!s->budget--) { s->failed_pc=0x0c0c4140u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e4u,2);
goto P_0c0c4142;
P_0c0c4142: /* original e301, guest PC 0x0c0c4142 */
if(!s->budget--) { s->failed_pc=0x0c0c4142u; return 0; }
r[3]=0x00000001u;
goto P_0c0c4144;
P_0c0c4144: /* original 02ec, guest PC 0x0c0c4144 */
if(!s->budget--) { s->failed_pc=0x0c0c4144u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4146;
P_0c0c4146: /* original 9051, guest PC 0x0c0c4146 */
if(!s->budget--) { s->failed_pc=0x0c0c4146u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41ecu,2);
goto P_0c0c4148;
P_0c0c4148: /* original 0e24, guest PC 0x0c0c4148 */
if(!s->budget--) { s->failed_pc=0x0c0c4148u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c414a;
P_0c0c414a: /* original 904b, guest PC 0x0c0c414a */
if(!s->budget--) { s->failed_pc=0x0c0c414au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e4u,2);
goto P_0c0c414c;
P_0c0c414c: /* original 0e34, guest PC 0x0c0c414c */
if(!s->budget--) { s->failed_pc=0x0c0c414cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c414e;
P_0c0c414e: /* original d22b, guest PC 0x0c0c414e */
if(!s->budget--) { s->failed_pc=0x0c0c414eu; return 0; }
r[2]=read(ram,0x0c0c41fcu,4);
goto P_0c0c4150;
P_0c0c4150: /* original 2d2b, guest PC 0x0c0c4150 */
if(!s->budget--) { s->failed_pc=0x0c0c4150u; return 0; }
r[13]|=r[2];
goto P_0c0c4152;
P_0c0c4152: /* original e320, guest PC 0x0c0c4152 */
if(!s->budget--) { s->failed_pc=0x0c0c4152u; return 0; }
r[3]=0x00000020u;
goto P_0c0c4154;
P_0c0c4154: /* original 2a38, guest PC 0x0c0c4154 */
if(!s->budget--) { s->failed_pc=0x0c0c4154u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0c4156;
P_0c0c4156: /* original 8927, guest PC 0x0c0c4156 */
if(!s->budget--) { s->failed_pc=0x0c0c4156u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c41a8; }
goto P_0c0c4158;
P_0c0c4158: /* original 54bb, guest PC 0x0c0c4158 */
if(!s->budget--) { s->failed_pc=0x0c0c4158u; return 0; }
r[4]=read(ram,r[11]+44,4);
goto P_0c0c415a;
P_0c0c415a: /* original e30e, guest PC 0x0c0c415a */
if(!s->budget--) { s->failed_pc=0x0c0c415au; return 0; }
r[3]=0x0000000eu;
goto P_0c0c415c;
P_0c0c415c: /* original 6442, guest PC 0x0c0c415c */
if(!s->budget--) { s->failed_pc=0x0c0c415cu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c415e;
P_0c0c415e: /* original 2438, guest PC 0x0c0c415e */
if(!s->budget--) { s->failed_pc=0x0c0c415eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0c4160;
P_0c0c4160: /* original 8b22, guest PC 0x0c0c4160 */
if(!s->budget--) { s->failed_pc=0x0c0c4160u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c41a8; }
goto P_0c0c4162;
P_0c0c4162: /* original d227, guest PC 0x0c0c4162 */
if(!s->budget--) { s->failed_pc=0x0c0c4162u; return 0; }
r[2]=read(ram,0x0c0c4200u,4);
goto P_0c0c4164;
P_0c0c4164: /* original 22d8, guest PC 0x0c0c4164 */
if(!s->budget--) { s->failed_pc=0x0c0c4164u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[13])==0)!=0);
goto P_0c0c4166;
P_0c0c4166: /* original 8b1f, guest PC 0x0c0c4166 */
if(!s->budget--) { s->failed_pc=0x0c0c4166u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c41a8; }
goto P_0c0c4168;
P_0c0c4168: /* original 903c, guest PC 0x0c0c4168 */
if(!s->budget--) { s->failed_pc=0x0c0c4168u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e4u,2);
goto P_0c0c416a;
P_0c0c416a: /* original 00ec, guest PC 0x0c0c416a */
if(!s->budget--) { s->failed_pc=0x0c0c416au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c416c;
P_0c0c416c: /* original 8801, guest PC 0x0c0c416c */
if(!s->budget--) { s->failed_pc=0x0c0c416cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c416e;
P_0c0c416e: /* original 8998, guest PC 0x0c0c416e */
if(!s->budget--) { s->failed_pc=0x0c0c416eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c40a2; }
goto P_0c0c4170;
P_0c0c4170: /* original 53f1, guest PC 0x0c0c4170 */
if(!s->budget--) { s->failed_pc=0x0c0c4170u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c4172;
P_0c0c4172: /* original d424, guest PC 0x0c0c4172 */
if(!s->budget--) { s->failed_pc=0x0c0c4172u; return 0; }
r[4]=read(ram,0x0c0c4204u,4);
goto P_0c0c4174;
P_0c0c4174: /* original 3340, guest PC 0x0c0c4174 */
if(!s->budget--) { s->failed_pc=0x0c0c4174u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c0c4176;
P_0c0c4176: /* original 8b01, guest PC 0x0c0c4176 */
if(!s->budget--) { s->failed_pc=0x0c0c4176u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c417c; }
goto P_0c0c4178;
P_0c0c4178: /* original 9239, guest PC 0x0c0c4178 */
if(!s->budget--) { s->failed_pc=0x0c0c4178u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41eeu,2);
goto P_0c0c417a;
P_0c0c417a: /* original 2d2b, guest PC 0x0c0c417a */
if(!s->budget--) { s->failed_pc=0x0c0c417au; return 0; }
r[13]|=r[2];
goto P_0c0c417c;
P_0c0c417c: /* original 9034, guest PC 0x0c0c417c */
if(!s->budget--) { s->failed_pc=0x0c0c417cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e8u,2);
goto P_0c0c417e;
P_0c0c417e: /* original d31d, guest PC 0x0c0c417e */
if(!s->budget--) { s->failed_pc=0x0c0c417eu; return 0; }
r[3]=read(ram,0x0c0c41f4u,4);
goto P_0c0c4180;
P_0c0c4180: /* original 02ec, guest PC 0x0c0c4180 */
if(!s->budget--) { s->failed_pc=0x0c0c4180u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4182;
P_0c0c4182: /* original 2d3b, guest PC 0x0c0c4182 */
if(!s->budget--) { s->failed_pc=0x0c0c4182u; return 0; }
r[13]|=r[3];
goto P_0c0c4184;
P_0c0c4184: /* original 2f22, guest PC 0x0c0c4184 */
if(!s->budget--) { s->failed_pc=0x0c0c4184u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c4186;
P_0c0c4186: /* original b06a, guest PC 0x0c0c4186 */
if(!s->budget--) { s->failed_pc=0x0c0c4186u; return 0; }
target=code_base|0x0c0c425eu; r[16]=code_base|0x0c0c418au;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c418au) { target=s->pc; goto dispatch; }
goto P_0c0c418a;
P_0c0c4188: /* original 6423, guest PC 0x0c0c4188 */
if(!s->budget--) { s->failed_pc=0x0c0c4188u; return 0; }
r[4]=r[2];
goto P_0c0c418a;
P_0c0c418a: /* original 88ff, guest PC 0x0c0c418a */
if(!s->budget--) { s->failed_pc=0x0c0c418au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c418c;
P_0c0c418c: /* original 8d0c, guest PC 0x0c0c418c */
if(!s->budget--) { s->failed_pc=0x0c0c418cu; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c0c41a8; }
goto P_0c0c4190;
P_0c0c418e: /* original 6403, guest PC 0x0c0c418e */
if(!s->budget--) { s->failed_pc=0x0c0c418eu; return 0; }
r[4]=r[0];
goto P_0c0c4190;
P_0c0c4190: /* original d319, guest PC 0x0c0c4190 */
if(!s->budget--) { s->failed_pc=0x0c0c4190u; return 0; }
r[3]=read(ram,0x0c0c41f8u,4);
goto P_0c0c4192;
P_0c0c4192: /* original 942a, guest PC 0x0c0c4192 */
if(!s->budget--) { s->failed_pc=0x0c0c4192u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41eau,2);
goto P_0c0c4194;
P_0c0c4194: /* original 430b, guest PC 0x0c0c4194 */
if(!s->budget--) { s->failed_pc=0x0c0c4194u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4198u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4198u) { target=s->pc; goto dispatch; }
goto P_0c0c4198;
P_0c0c4196: /* original 0009, guest PC 0x0c0c4196 */
if(!s->budget--) { s->failed_pc=0x0c0c4196u; return 0; }
goto P_0c0c4198;
P_0c0c4198: /* original 9024, guest PC 0x0c0c4198 */
if(!s->budget--) { s->failed_pc=0x0c0c4198u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e4u,2);
goto P_0c0c419a;
P_0c0c419a: /* original 02ec, guest PC 0x0c0c419a */
if(!s->budget--) { s->failed_pc=0x0c0c419au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c419c;
P_0c0c419c: /* original 9026, guest PC 0x0c0c419c */
if(!s->budget--) { s->failed_pc=0x0c0c419cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41ecu,2);
goto P_0c0c419e;
P_0c0c419e: /* original 0e24, guest PC 0x0c0c419e */
if(!s->budget--) { s->failed_pc=0x0c0c419eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c41a0;
P_0c0c41a0: /* original 9020, guest PC 0x0c0c41a0 */
if(!s->budget--) { s->failed_pc=0x0c0c41a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c41e4u,2);
goto P_0c0c41a2;
P_0c0c41a2: /* original 0e84, guest PC 0x0c0c41a2 */
if(!s->budget--) { s->failed_pc=0x0c0c41a2u; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0c41a4;
P_0c0c41a4: /* original d316, guest PC 0x0c0c41a4 */
if(!s->budget--) { s->failed_pc=0x0c0c41a4u; return 0; }
r[3]=read(ram,0x0c0c4200u,4);
goto P_0c0c41a6;
P_0c0c41a6: /* original 2d3b, guest PC 0x0c0c41a6 */
if(!s->budget--) { s->failed_pc=0x0c0c41a6u; return 0; }
r[13]|=r[3];
goto P_0c0c41a8;
P_0c0c41a8: /* original 1ed2, guest PC 0x0c0c41a8 */
if(!s->budget--) { s->failed_pc=0x0c0c41a8u; return 0; }
write(ram,r[14]+8,r[13],4);
goto P_0c0c41aa;
P_0c0c41aa: /* original 7f20, guest PC 0x0c0c41aa */
if(!s->budget--) { s->failed_pc=0x0c0c41aau; return 0; }
r[15]+=0x00000020u;
goto P_0c0c41ac;
P_0c0c41ac: /* original 4f26, guest PC 0x0c0c41ac */
if(!s->budget--) { s->failed_pc=0x0c0c41acu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c41ae;
P_0c0c41ae: /* original 68f6, guest PC 0x0c0c41ae */
if(!s->budget--) { s->failed_pc=0x0c0c41aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c41b0;
P_0c0c41b0: /* original 69f6, guest PC 0x0c0c41b0 */
if(!s->budget--) { s->failed_pc=0x0c0c41b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c41b2;
P_0c0c41b2: /* original 6af6, guest PC 0x0c0c41b2 */
if(!s->budget--) { s->failed_pc=0x0c0c41b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c41b4;
P_0c0c41b4: /* original 6bf6, guest PC 0x0c0c41b4 */
if(!s->budget--) { s->failed_pc=0x0c0c41b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c41b6;
P_0c0c41b6: /* original 6cf6, guest PC 0x0c0c41b6 */
if(!s->budget--) { s->failed_pc=0x0c0c41b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c41b8;
P_0c0c41b8: /* original 6df6, guest PC 0x0c0c41b8 */
if(!s->budget--) { s->failed_pc=0x0c0c41b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c41ba;
P_0c0c41ba: /* original 000b, guest PC 0x0c0c41ba */
if(!s->budget--) { s->failed_pc=0x0c0c41bau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c41bc: /* original 6ef6, guest PC 0x0c0c41bc */
if(!s->budget--) { s->failed_pc=0x0c0c41bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c41beu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
