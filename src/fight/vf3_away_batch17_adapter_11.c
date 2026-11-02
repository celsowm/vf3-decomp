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
int vf3_away_batch17_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c093a9cu: goto P_0c093a9c;
case 0x0c093a9eu: goto P_0c093a9e;
case 0x0c093aa0u: goto P_0c093aa0;
case 0x0c093aa2u: goto P_0c093aa2;
case 0x0c093aa4u: goto P_0c093aa4;
case 0x0c093aa6u: goto P_0c093aa6;
case 0x0c093aa8u: goto P_0c093aa8;
case 0x0c093aaau: goto P_0c093aaa;
case 0x0c093aacu: goto P_0c093aac;
case 0x0c093aaeu: goto P_0c093aae;
case 0x0c093ab0u: goto P_0c093ab0;
case 0x0c093ab2u: goto P_0c093ab2;
case 0x0c093ab4u: goto P_0c093ab4;
case 0x0c093ab8u: goto P_0c093ab8;
case 0x0c093abau: goto P_0c093aba;
case 0x0c093abcu: goto P_0c093abc;
case 0x0c093abeu: goto P_0c093abe;
case 0x0c093ac0u: goto P_0c093ac0;
case 0x0c093ac2u: goto P_0c093ac2;
case 0x0c093ac4u: goto P_0c093ac4;
case 0x0c093ac6u: goto P_0c093ac6;
case 0x0c093ac8u: goto P_0c093ac8;
case 0x0c093acau: goto P_0c093aca;
case 0x0c093accu: goto P_0c093acc;
case 0x0c093aceu: goto P_0c093ace;
case 0x0c093ad0u: goto P_0c093ad0;
case 0x0c093ad2u: goto P_0c093ad2;
case 0x0c093ad4u: goto P_0c093ad4;
case 0x0c093ad6u: goto P_0c093ad6;
case 0x0c093ad8u: goto P_0c093ad8;
case 0x0c093adau: goto P_0c093ada;
case 0x0c093adcu: goto P_0c093adc;
case 0x0c093adeu: goto P_0c093ade;
case 0x0c093ae0u: goto P_0c093ae0;
case 0x0c093ae2u: goto P_0c093ae2;
case 0x0c093ae4u: goto P_0c093ae4;
case 0x0c093ae6u: goto P_0c093ae6;
case 0x0c093ae8u: goto P_0c093ae8;
case 0x0c093aeau: goto P_0c093aea;
case 0x0c093aecu: goto P_0c093aec;
case 0x0c093aeeu: goto P_0c093aee;
case 0x0c093af0u: goto P_0c093af0;
case 0x0c093af2u: goto P_0c093af2;
case 0x0c093af4u: goto P_0c093af4;
case 0x0c093af6u: goto P_0c093af6;
case 0x0c093af8u: goto P_0c093af8;
case 0x0c093afau: goto P_0c093afa;
case 0x0c093afcu: goto P_0c093afc;
case 0x0c093afeu: goto P_0c093afe;
case 0x0c093b00u: goto P_0c093b00;
case 0x0c093b02u: goto P_0c093b02;
case 0x0c093b04u: goto P_0c093b04;
case 0x0c093b06u: goto P_0c093b06;
case 0x0c093b08u: goto P_0c093b08;
case 0x0c093b10u: goto P_0c093b10;
case 0x0c093b12u: goto P_0c093b12;
case 0x0c093b14u: goto P_0c093b14;
case 0x0c093b16u: goto P_0c093b16;
case 0x0c093b18u: goto P_0c093b18;
case 0x0c093b1au: goto P_0c093b1a;
case 0x0c093b1cu: goto P_0c093b1c;
case 0x0c093b1eu: goto P_0c093b1e;
case 0x0c093b20u: goto P_0c093b20;
case 0x0c093b22u: goto P_0c093b22;
case 0x0c093b24u: goto P_0c093b24;
case 0x0c093b26u: goto P_0c093b26;
case 0x0c093b28u: goto P_0c093b28;
case 0x0c093b2au: goto P_0c093b2a;
case 0x0c093b2cu: goto P_0c093b2c;
case 0x0c093b2eu: goto P_0c093b2e;
case 0x0c093b30u: goto P_0c093b30;
case 0x0c093b32u: goto P_0c093b32;
case 0x0c093b34u: goto P_0c093b34;
case 0x0c093b36u: goto P_0c093b36;
case 0x0c093b38u: goto P_0c093b38;
case 0x0c093b3au: goto P_0c093b3a;
case 0x0c093b3cu: goto P_0c093b3c;
case 0x0c093b3eu: goto P_0c093b3e;
case 0x0c093b40u: goto P_0c093b40;
case 0x0c093b42u: goto P_0c093b42;
case 0x0c093b44u: goto P_0c093b44;
case 0x0c093b46u: goto P_0c093b46;
case 0x0c093b48u: goto P_0c093b48;
case 0x0c093b4au: goto P_0c093b4a;
case 0x0c093b4cu: goto P_0c093b4c;
case 0x0c093b4eu: goto P_0c093b4e;
case 0x0c093b50u: goto P_0c093b50;
case 0x0c093b52u: goto P_0c093b52;
case 0x0c093beau: goto P_0c093bea;
case 0x0c093becu: goto P_0c093bec;
case 0x0c093beeu: goto P_0c093bee;
case 0x0c093bf0u: goto P_0c093bf0;
case 0x0c093bf2u: goto P_0c093bf2;
case 0x0c093bf4u: goto P_0c093bf4;
case 0x0c093bf6u: goto P_0c093bf6;
case 0x0c093bf8u: goto P_0c093bf8;
case 0x0c093bfau: goto P_0c093bfa;
case 0x0c093bfcu: goto P_0c093bfc;
case 0x0c093bfeu: goto P_0c093bfe;
case 0x0c093c00u: goto P_0c093c00;
case 0x0c093c02u: goto P_0c093c02;
case 0x0c093c04u: goto P_0c093c04;
case 0x0c093c06u: goto P_0c093c06;
case 0x0c093c08u: goto P_0c093c08;
case 0x0c093c0au: goto P_0c093c0a;
case 0x0c093c0cu: goto P_0c093c0c;
case 0x0c093c0eu: goto P_0c093c0e;
case 0x0c093c10u: goto P_0c093c10;
case 0x0c093c12u: goto P_0c093c12;
case 0x0c093c14u: goto P_0c093c14;
case 0x0c093c16u: goto P_0c093c16;
case 0x0c093c18u: goto P_0c093c18;
case 0x0c093c1au: goto P_0c093c1a;
case 0x0c093c1cu: goto P_0c093c1c;
case 0x0c093c1eu: goto P_0c093c1e;
case 0x0c093c20u: goto P_0c093c20;
case 0x0c093c22u: goto P_0c093c22;
case 0x0c093c24u: goto P_0c093c24;
case 0x0c093c26u: goto P_0c093c26;
case 0x0c093c28u: goto P_0c093c28;
case 0x0c093c2au: goto P_0c093c2a;
case 0x0c093c2cu: goto P_0c093c2c;
case 0x0c093c2eu: goto P_0c093c2e;
case 0x0c093c30u: goto P_0c093c30;
case 0x0c093c4cu: goto P_0c093c4c;
case 0x0c093c4eu: goto P_0c093c4e;
case 0x0c093c50u: goto P_0c093c50;
case 0x0c093c52u: goto P_0c093c52;
case 0x0c093c54u: goto P_0c093c54;
case 0x0c093c56u: goto P_0c093c56;
case 0x0c093c58u: goto P_0c093c58;
case 0x0c093c5au: goto P_0c093c5a;
case 0x0c093c5cu: goto P_0c093c5c;
case 0x0c093c5eu: goto P_0c093c5e;
case 0x0c093c60u: goto P_0c093c60;
case 0x0c093c62u: goto P_0c093c62;
case 0x0c093c64u: goto P_0c093c64;
case 0x0c093c66u: goto P_0c093c66;
case 0x0c093c68u: goto P_0c093c68;
case 0x0c093c6au: goto P_0c093c6a;
case 0x0c093c6cu: goto P_0c093c6c;
case 0x0c093c6eu: goto P_0c093c6e;
case 0x0c093c70u: goto P_0c093c70;
case 0x0c093c72u: goto P_0c093c72;
case 0x0c093c74u: goto P_0c093c74;
case 0x0c093c76u: goto P_0c093c76;
case 0x0c093c78u: goto P_0c093c78;
case 0x0c093c7au: goto P_0c093c7a;
case 0x0c093c7cu: goto P_0c093c7c;
case 0x0c093c7eu: goto P_0c093c7e;
case 0x0c093c80u: goto P_0c093c80;
case 0x0c093c82u: goto P_0c093c82;
case 0x0c093c84u: goto P_0c093c84;
case 0x0c093c86u: goto P_0c093c86;
case 0x0c093c88u: goto P_0c093c88;
case 0x0c093c8au: goto P_0c093c8a;
case 0x0c093c8cu: goto P_0c093c8c;
case 0x0c093c8eu: goto P_0c093c8e;
case 0x0c093c90u: goto P_0c093c90;
case 0x0c093c92u: goto P_0c093c92;
case 0x0c093c94u: goto P_0c093c94;
case 0x0c093c96u: goto P_0c093c96;
case 0x0c093c98u: goto P_0c093c98;
case 0x0c093c9au: goto P_0c093c9a;
case 0x0c093c9cu: goto P_0c093c9c;
case 0x0c093c9eu: goto P_0c093c9e;
case 0x0c093ca0u: goto P_0c093ca0;
case 0x0c093ca2u: goto P_0c093ca2;
case 0x0c093ca4u: goto P_0c093ca4;
case 0x0c093ca6u: goto P_0c093ca6;
case 0x0c093ca8u: goto P_0c093ca8;
case 0x0c093caau: goto P_0c093caa;
case 0x0c093cacu: goto P_0c093cac;
case 0x0c093caeu: goto P_0c093cae;
case 0x0c093cb0u: goto P_0c093cb0;
case 0x0c093cb2u: goto P_0c093cb2;
case 0x0c093cb4u: goto P_0c093cb4;
case 0x0c093cb6u: goto P_0c093cb6;
case 0x0c093cb8u: goto P_0c093cb8;
case 0x0c093cbau: goto P_0c093cba;
case 0x0c093cbcu: goto P_0c093cbc;
case 0x0c093cbeu: goto P_0c093cbe;
case 0x0c093cc0u: goto P_0c093cc0;
case 0x0c093cc2u: goto P_0c093cc2;
case 0x0c093cc4u: goto P_0c093cc4;
case 0x0c093cc6u: goto P_0c093cc6;
case 0x0c093cc8u: goto P_0c093cc8;
case 0x0c093ccau: goto P_0c093cca;
case 0x0c093cccu: goto P_0c093ccc;
case 0x0c093cceu: goto P_0c093cce;
case 0x0c093cd0u: goto P_0c093cd0;
case 0x0c093cd2u: goto P_0c093cd2;
case 0x0c093cd4u: goto P_0c093cd4;
case 0x0c093cd6u: goto P_0c093cd6;
case 0x0c093cd8u: goto P_0c093cd8;
case 0x0c093cdau: goto P_0c093cda;
case 0x0c093cdcu: goto P_0c093cdc;
case 0x0c093cdeu: goto P_0c093cde;
case 0x0c093ce0u: goto P_0c093ce0;
case 0x0c093ce2u: goto P_0c093ce2;
case 0x0c093ce4u: goto P_0c093ce4;
case 0x0c093ce6u: goto P_0c093ce6;
case 0x0c093ce8u: goto P_0c093ce8;
case 0x0c093ceau: goto P_0c093cea;
case 0x0c093cecu: goto P_0c093cec;
case 0x0c093ceeu: goto P_0c093cee;
case 0x0c093cf0u: goto P_0c093cf0;
case 0x0c093cf2u: goto P_0c093cf2;
case 0x0c093cf4u: goto P_0c093cf4;
case 0x0c093cf6u: goto P_0c093cf6;
case 0x0c093cf8u: goto P_0c093cf8;
case 0x0c093cfau: goto P_0c093cfa;
case 0x0c093cfcu: goto P_0c093cfc;
case 0x0c093cfeu: goto P_0c093cfe;
case 0x0c093d00u: goto P_0c093d00;
case 0x0c093d02u: goto P_0c093d02;
case 0x0c093d04u: goto P_0c093d04;
case 0x0c093d06u: goto P_0c093d06;
case 0x0c093d08u: goto P_0c093d08;
case 0x0c093d0au: goto P_0c093d0a;
case 0x0c093d0cu: goto P_0c093d0c;
case 0x0c093d0eu: goto P_0c093d0e;
case 0x0c093d10u: goto P_0c093d10;
case 0x0c093d12u: goto P_0c093d12;
case 0x0c093d14u: goto P_0c093d14;
case 0x0c093d16u: goto P_0c093d16;
case 0x0c093d18u: goto P_0c093d18;
case 0x0c093d1au: goto P_0c093d1a;
case 0x0c093d1cu: goto P_0c093d1c;
case 0x0c093d1eu: goto P_0c093d1e;
case 0x0c093d20u: goto P_0c093d20;
case 0x0c093d22u: goto P_0c093d22;
case 0x0c093d24u: goto P_0c093d24;
case 0x0c093d26u: goto P_0c093d26;
case 0x0c093d28u: goto P_0c093d28;
case 0x0c093d2au: goto P_0c093d2a;
case 0x0c093d2cu: goto P_0c093d2c;
case 0x0c093d2eu: goto P_0c093d2e;
case 0x0c093d30u: goto P_0c093d30;
case 0x0c093d32u: goto P_0c093d32;
case 0x0c093d34u: goto P_0c093d34;
case 0x0c093d36u: goto P_0c093d36;
case 0x0c093d38u: goto P_0c093d38;
case 0x0c093d3au: goto P_0c093d3a;
case 0x0c093d3cu: goto P_0c093d3c;
case 0x0c093d3eu: goto P_0c093d3e;
case 0x0c093d40u: goto P_0c093d40;
case 0x0c093d42u: goto P_0c093d42;
case 0x0c093d44u: goto P_0c093d44;
case 0x0c093d46u: goto P_0c093d46;
case 0x0c093d68u: goto P_0c093d68;
case 0x0c093d6au: goto P_0c093d6a;
case 0x0c093d6cu: goto P_0c093d6c;
case 0x0c093d6eu: goto P_0c093d6e;
case 0x0c093d70u: goto P_0c093d70;
case 0x0c093d72u: goto P_0c093d72;
case 0x0c093d74u: goto P_0c093d74;
case 0x0c093d76u: goto P_0c093d76;
case 0x0c093d78u: goto P_0c093d78;
case 0x0c093d7au: goto P_0c093d7a;
case 0x0c093d7cu: goto P_0c093d7c;
case 0x0c093d7eu: goto P_0c093d7e;
case 0x0c093d80u: goto P_0c093d80;
case 0x0c093d82u: goto P_0c093d82;
case 0x0c093d84u: goto P_0c093d84;
case 0x0c093d86u: goto P_0c093d86;
case 0x0c093d88u: goto P_0c093d88;
case 0x0c093d8au: goto P_0c093d8a;
case 0x0c093d8cu: goto P_0c093d8c;
case 0x0c093d8eu: goto P_0c093d8e;
case 0x0c093d90u: goto P_0c093d90;
case 0x0c093d92u: goto P_0c093d92;
case 0x0c093d94u: goto P_0c093d94;
case 0x0c093d96u: goto P_0c093d96;
case 0x0c093d98u: goto P_0c093d98;
case 0x0c093d9au: goto P_0c093d9a;
case 0x0c093d9cu: goto P_0c093d9c;
case 0x0c093d9eu: goto P_0c093d9e;
case 0x0c093da0u: goto P_0c093da0;
case 0x0c093da2u: goto P_0c093da2;
case 0x0c093da4u: goto P_0c093da4;
case 0x0c093da6u: goto P_0c093da6;
case 0x0c093da8u: goto P_0c093da8;
case 0x0c093daau: goto P_0c093daa;
case 0x0c093dacu: goto P_0c093dac;
case 0x0c093daeu: goto P_0c093dae;
case 0x0c093db0u: goto P_0c093db0;
case 0x0c093db2u: goto P_0c093db2;
case 0x0c093db4u: goto P_0c093db4;
case 0x0c093db6u: goto P_0c093db6;
case 0x0c093db8u: goto P_0c093db8;
case 0x0c093dbau: goto P_0c093dba;
case 0x0c093dbcu: goto P_0c093dbc;
case 0x0c093dbeu: goto P_0c093dbe;
case 0x0c093dc0u: goto P_0c093dc0;
case 0x0c093dc2u: goto P_0c093dc2;
case 0x0c093dc4u: goto P_0c093dc4;
case 0x0c093dc6u: goto P_0c093dc6;
case 0x0c093dc8u: goto P_0c093dc8;
case 0x0c093dcau: goto P_0c093dca;
case 0x0c093dccu: goto P_0c093dcc;
case 0x0c093dceu: goto P_0c093dce;
case 0x0c093dd0u: goto P_0c093dd0;
case 0x0c093dd2u: goto P_0c093dd2;
case 0x0c093dd4u: goto P_0c093dd4;
case 0x0c093dd6u: goto P_0c093dd6;
case 0x0c093dd8u: goto P_0c093dd8;
case 0x0c093ddau: goto P_0c093dda;
case 0x0c093ddcu: goto P_0c093ddc;
case 0x0c093ddeu: goto P_0c093dde;
case 0x0c093de0u: goto P_0c093de0;
case 0x0c093de2u: goto P_0c093de2;
case 0x0c093de4u: goto P_0c093de4;
case 0x0c093de6u: goto P_0c093de6;
case 0x0c093de8u: goto P_0c093de8;
case 0x0c093deau: goto P_0c093dea;
case 0x0c093decu: goto P_0c093dec;
case 0x0c093deeu: goto P_0c093dee;
case 0x0c093df0u: goto P_0c093df0;
case 0x0c093df2u: goto P_0c093df2;
case 0x0c093df4u: goto P_0c093df4;
case 0x0c093df6u: goto P_0c093df6;
case 0x0c093df8u: goto P_0c093df8;
case 0x0c093dfau: goto P_0c093dfa;
case 0x0c093dfcu: goto P_0c093dfc;
case 0x0c093dfeu: goto P_0c093dfe;
case 0x0c093e00u: goto P_0c093e00;
case 0x0c093e02u: goto P_0c093e02;
case 0x0c093e04u: goto P_0c093e04;
case 0x0c093e06u: goto P_0c093e06;
case 0x0c093e08u: goto P_0c093e08;
case 0x0c093e0au: goto P_0c093e0a;
case 0x0c093e0cu: goto P_0c093e0c;
case 0x0c093e0eu: goto P_0c093e0e;
case 0x0c093e10u: goto P_0c093e10;
case 0x0c093e12u: goto P_0c093e12;
case 0x0c093e14u: goto P_0c093e14;
case 0x0c093e16u: goto P_0c093e16;
case 0x0c093e18u: goto P_0c093e18;
case 0x0c093e1au: goto P_0c093e1a;
case 0x0c093e1cu: goto P_0c093e1c;
case 0x0c093e1eu: goto P_0c093e1e;
case 0x0c093e20u: goto P_0c093e20;
case 0x0c093e22u: goto P_0c093e22;
case 0x0c093e24u: goto P_0c093e24;
case 0x0c093e26u: goto P_0c093e26;
case 0x0c093e28u: goto P_0c093e28;
case 0x0c093e2au: goto P_0c093e2a;
case 0x0c093e2cu: goto P_0c093e2c;
case 0x0c093e2eu: goto P_0c093e2e;
case 0x0c093e48u: goto P_0c093e48;
case 0x0c093e4au: goto P_0c093e4a;
case 0x0c093e4cu: goto P_0c093e4c;
case 0x0c093e4eu: goto P_0c093e4e;
case 0x0c093e50u: goto P_0c093e50;
case 0x0c093e52u: goto P_0c093e52;
case 0x0c093e54u: goto P_0c093e54;
case 0x0c093e56u: goto P_0c093e56;
case 0x0c093e58u: goto P_0c093e58;
case 0x0c093e5au: goto P_0c093e5a;
case 0x0c093e5cu: goto P_0c093e5c;
case 0x0c093e5eu: goto P_0c093e5e;
case 0x0c093e60u: goto P_0c093e60;
case 0x0c093e62u: goto P_0c093e62;
case 0x0c093e64u: goto P_0c093e64;
case 0x0c093e66u: goto P_0c093e66;
case 0x0c093e68u: goto P_0c093e68;
case 0x0c093e6au: goto P_0c093e6a;
case 0x0c093e6cu: goto P_0c093e6c;
case 0x0c093e6eu: goto P_0c093e6e;
case 0x0c093e70u: goto P_0c093e70;
case 0x0c093e72u: goto P_0c093e72;
case 0x0c093e74u: goto P_0c093e74;
case 0x0c093e76u: goto P_0c093e76;
case 0x0c093e78u: goto P_0c093e78;
case 0x0c093e7au: goto P_0c093e7a;
case 0x0c093e7cu: goto P_0c093e7c;
case 0x0c093e7eu: goto P_0c093e7e;
case 0x0c093e80u: goto P_0c093e80;
case 0x0c093e82u: goto P_0c093e82;
case 0x0c093e84u: goto P_0c093e84;
case 0x0c093e86u: goto P_0c093e86;
case 0x0c093e88u: goto P_0c093e88;
case 0x0c093e8au: goto P_0c093e8a;
case 0x0c093e8cu: goto P_0c093e8c;
case 0x0c093e8eu: goto P_0c093e8e;
case 0x0c093e90u: goto P_0c093e90;
case 0x0c093e92u: goto P_0c093e92;
case 0x0c093e94u: goto P_0c093e94;
case 0x0c093e96u: goto P_0c093e96;
case 0x0c093e98u: goto P_0c093e98;
case 0x0c093e9au: goto P_0c093e9a;
case 0x0c093e9cu: goto P_0c093e9c;
case 0x0c093e9eu: goto P_0c093e9e;
case 0x0c093ea0u: goto P_0c093ea0;
case 0x0c093ea2u: goto P_0c093ea2;
case 0x0c093ea4u: goto P_0c093ea4;
case 0x0c093ea6u: goto P_0c093ea6;
case 0x0c093ea8u: goto P_0c093ea8;
case 0x0c093eaau: goto P_0c093eaa;
case 0x0c093eacu: goto P_0c093eac;
case 0x0c093eaeu: goto P_0c093eae;
case 0x0c093eb0u: goto P_0c093eb0;
case 0x0c093eb2u: goto P_0c093eb2;
case 0x0c093eb4u: goto P_0c093eb4;
case 0x0c093eb6u: goto P_0c093eb6;
case 0x0c093eb8u: goto P_0c093eb8;
case 0x0c093ebau: goto P_0c093eba;
case 0x0c093ebcu: goto P_0c093ebc;
case 0x0c093ebeu: goto P_0c093ebe;
case 0x0c093ec0u: goto P_0c093ec0;
case 0x0c093ec2u: goto P_0c093ec2;
case 0x0c093ec4u: goto P_0c093ec4;
case 0x0c093ec6u: goto P_0c093ec6;
case 0x0c093ec8u: goto P_0c093ec8;
case 0x0c093ecau: goto P_0c093eca;
case 0x0c093eccu: goto P_0c093ecc;
case 0x0c093eceu: goto P_0c093ece;
case 0x0c093ed0u: goto P_0c093ed0;
case 0x0c093ed2u: goto P_0c093ed2;
case 0x0c093ed4u: goto P_0c093ed4;
case 0x0c093ed6u: goto P_0c093ed6;
case 0x0c093ed8u: goto P_0c093ed8;
case 0x0c093edau: goto P_0c093eda;
case 0x0c093edcu: goto P_0c093edc;
case 0x0c093edeu: goto P_0c093ede;
case 0x0c093ee0u: goto P_0c093ee0;
case 0x0c093ee2u: goto P_0c093ee2;
case 0x0c093ee4u: goto P_0c093ee4;
case 0x0c093ee6u: goto P_0c093ee6;
case 0x0c093ee8u: goto P_0c093ee8;
case 0x0c093eeau: goto P_0c093eea;
case 0x0c093eecu: goto P_0c093eec;
case 0x0c093eeeu: goto P_0c093eee;
case 0x0c093ef0u: goto P_0c093ef0;
case 0x0c093ef2u: goto P_0c093ef2;
case 0x0c093ef4u: goto P_0c093ef4;
case 0x0c093ef6u: goto P_0c093ef6;
case 0x0c093ef8u: goto P_0c093ef8;
case 0x0c093efau: goto P_0c093efa;
case 0x0c093efcu: goto P_0c093efc;
case 0x0c093efeu: goto P_0c093efe;
case 0x0c093f00u: goto P_0c093f00;
case 0x0c093f02u: goto P_0c093f02;
case 0x0c093f04u: goto P_0c093f04;
case 0x0c093f06u: goto P_0c093f06;
case 0x0c093f08u: goto P_0c093f08;
case 0x0c093f0au: goto P_0c093f0a;
case 0x0c093f0cu: goto P_0c093f0c;
case 0x0c093f0eu: goto P_0c093f0e;
case 0x0c093f10u: goto P_0c093f10;
case 0x0c093f12u: goto P_0c093f12;
case 0x0c093f14u: goto P_0c093f14;
case 0x0c093f16u: goto P_0c093f16;
case 0x0c093f18u: goto P_0c093f18;
case 0x0c093f1au: goto P_0c093f1a;
case 0x0c093f1cu: goto P_0c093f1c;
case 0x0c093f1eu: goto P_0c093f1e;
case 0x0c093f20u: goto P_0c093f20;
case 0x0c093f22u: goto P_0c093f22;
case 0x0c093f24u: goto P_0c093f24;
case 0x0c093f26u: goto P_0c093f26;
case 0x0c093f28u: goto P_0c093f28;
case 0x0c093f2au: goto P_0c093f2a;
case 0x0c093f2cu: goto P_0c093f2c;
case 0x0c093f2eu: goto P_0c093f2e;
case 0x0c093f30u: goto P_0c093f30;
case 0x0c093f32u: goto P_0c093f32;
case 0x0c093f34u: goto P_0c093f34;
case 0x0c093f36u: goto P_0c093f36;
case 0x0c093f38u: goto P_0c093f38;
case 0x0c093f3au: goto P_0c093f3a;
case 0x0c093f3cu: goto P_0c093f3c;
case 0x0c093f3eu: goto P_0c093f3e;
case 0x0c093f40u: goto P_0c093f40;
case 0x0c093f42u: goto P_0c093f42;
case 0x0c093f44u: goto P_0c093f44;
case 0x0c093f46u: goto P_0c093f46;
case 0x0c093f48u: goto P_0c093f48;
case 0x0c093f4au: goto P_0c093f4a;
case 0x0c093f4cu: goto P_0c093f4c;
case 0x0c093f4eu: goto P_0c093f4e;
case 0x0c093f50u: goto P_0c093f50;
case 0x0c093f52u: goto P_0c093f52;
case 0x0c093f54u: goto P_0c093f54;
case 0x0c093f56u: goto P_0c093f56;
case 0x0c093f58u: goto P_0c093f58;
case 0x0c093f5au: goto P_0c093f5a;
case 0x0c093f5cu: goto P_0c093f5c;
case 0x0c093f5eu: goto P_0c093f5e;
case 0x0c093f60u: goto P_0c093f60;
case 0x0c093f62u: goto P_0c093f62;
case 0x0c093f64u: goto P_0c093f64;
case 0x0c093f66u: goto P_0c093f66;
case 0x0c093f68u: goto P_0c093f68;
case 0x0c093f6au: goto P_0c093f6a;
case 0x0c093f6cu: goto P_0c093f6c;
case 0x0c093f6eu: goto P_0c093f6e;
case 0x0c093f70u: goto P_0c093f70;
case 0x0c093f72u: goto P_0c093f72;
case 0x0c093f74u: goto P_0c093f74;
case 0x0c093f76u: goto P_0c093f76;
case 0x0c093f78u: goto P_0c093f78;
case 0x0c093f7au: goto P_0c093f7a;
case 0x0c093f7cu: goto P_0c093f7c;
case 0x0c093f7eu: goto P_0c093f7e;
case 0x0c093f80u: goto P_0c093f80;
case 0x0c093f82u: goto P_0c093f82;
case 0x0c093f84u: goto P_0c093f84;
case 0x0c093f86u: goto P_0c093f86;
case 0x0c093f88u: goto P_0c093f88;
case 0x0c093f8au: goto P_0c093f8a;
case 0x0c093f8cu: goto P_0c093f8c;
case 0x0c093f8eu: goto P_0c093f8e;
case 0x0c093f90u: goto P_0c093f90;
case 0x0c093f92u: goto P_0c093f92;
case 0x0c093f94u: goto P_0c093f94;
case 0x0c093f96u: goto P_0c093f96;
case 0x0c093f98u: goto P_0c093f98;
case 0x0c093fb4u: goto P_0c093fb4;
case 0x0c093fb6u: goto P_0c093fb6;
case 0x0c093fb8u: goto P_0c093fb8;
case 0x0c093fbau: goto P_0c093fba;
case 0x0c093fbcu: goto P_0c093fbc;
case 0x0c093fbeu: goto P_0c093fbe;
case 0x0c093fc0u: goto P_0c093fc0;
case 0x0c093fc2u: goto P_0c093fc2;
case 0x0c093fc4u: goto P_0c093fc4;
case 0x0c093fc6u: goto P_0c093fc6;
case 0x0c093fc8u: goto P_0c093fc8;
case 0x0c093fcau: goto P_0c093fca;
case 0x0c093fccu: goto P_0c093fcc;
case 0x0c093fceu: goto P_0c093fce;
case 0x0c093fd0u: goto P_0c093fd0;
case 0x0c093fd2u: goto P_0c093fd2;
case 0x0c093fd4u: goto P_0c093fd4;
case 0x0c093fd6u: goto P_0c093fd6;
case 0x0c093fd8u: goto P_0c093fd8;
case 0x0c093fdau: goto P_0c093fda;
case 0x0c093fdcu: goto P_0c093fdc;
case 0x0c093fdeu: goto P_0c093fde;
case 0x0c093fe0u: goto P_0c093fe0;
case 0x0c093fe2u: goto P_0c093fe2;
case 0x0c093fe4u: goto P_0c093fe4;
case 0x0c093fe6u: goto P_0c093fe6;
case 0x0c093fe8u: goto P_0c093fe8;
case 0x0c093feau: goto P_0c093fea;
case 0x0c093fecu: goto P_0c093fec;
case 0x0c093feeu: goto P_0c093fee;
case 0x0c093ff0u: goto P_0c093ff0;
case 0x0c093ff2u: goto P_0c093ff2;
case 0x0c093ff4u: goto P_0c093ff4;
case 0x0c093ff6u: goto P_0c093ff6;
case 0x0c093ff8u: goto P_0c093ff8;
case 0x0c093ffau: goto P_0c093ffa;
case 0x0c093ffcu: goto P_0c093ffc;
case 0x0c093ffeu: goto P_0c093ffe;
case 0x0c094000u: goto P_0c094000;
case 0x0c094002u: goto P_0c094002;
case 0x0c094004u: goto P_0c094004;
case 0x0c094006u: goto P_0c094006;
case 0x0c094008u: goto P_0c094008;
case 0x0c09400au: goto P_0c09400a;
case 0x0c09400cu: goto P_0c09400c;
case 0x0c09400eu: goto P_0c09400e;
case 0x0c094010u: goto P_0c094010;
case 0x0c094012u: goto P_0c094012;
case 0x0c094014u: goto P_0c094014;
case 0x0c094016u: goto P_0c094016;
case 0x0c094018u: goto P_0c094018;
case 0x0c09401au: goto P_0c09401a;
case 0x0c09401cu: goto P_0c09401c;
case 0x0c09401eu: goto P_0c09401e;
case 0x0c094020u: goto P_0c094020;
case 0x0c094022u: goto P_0c094022;
case 0x0c094024u: goto P_0c094024;
case 0x0c094026u: goto P_0c094026;
case 0x0c094028u: goto P_0c094028;
case 0x0c09402au: goto P_0c09402a;
case 0x0c09402cu: goto P_0c09402c;
case 0x0c09402eu: goto P_0c09402e;
case 0x0c094030u: goto P_0c094030;
case 0x0c094032u: goto P_0c094032;
case 0x0c094034u: goto P_0c094034;
case 0x0c094036u: goto P_0c094036;
case 0x0c094038u: goto P_0c094038;
case 0x0c09403au: goto P_0c09403a;
case 0x0c09403cu: goto P_0c09403c;
case 0x0c09403eu: goto P_0c09403e;
case 0x0c094040u: goto P_0c094040;
case 0x0c094042u: goto P_0c094042;
case 0x0c094044u: goto P_0c094044;
case 0x0c094046u: goto P_0c094046;
case 0x0c094048u: goto P_0c094048;
case 0x0c09404au: goto P_0c09404a;
case 0x0c09404cu: goto P_0c09404c;
case 0x0c09404eu: goto P_0c09404e;
case 0x0c094050u: goto P_0c094050;
case 0x0c094052u: goto P_0c094052;
case 0x0c094054u: goto P_0c094054;
case 0x0c094056u: goto P_0c094056;
case 0x0c094058u: goto P_0c094058;
case 0x0c09405au: goto P_0c09405a;
case 0x0c09405cu: goto P_0c09405c;
case 0x0c09405eu: goto P_0c09405e;
case 0x0c094060u: goto P_0c094060;
case 0x0c094062u: goto P_0c094062;
case 0x0c094064u: goto P_0c094064;
case 0x0c094066u: goto P_0c094066;
case 0x0c094068u: goto P_0c094068;
case 0x0c09406au: goto P_0c09406a;
case 0x0c09406cu: goto P_0c09406c;
case 0x0c09406eu: goto P_0c09406e;
case 0x0c094070u: goto P_0c094070;
case 0x0c094072u: goto P_0c094072;
case 0x0c094074u: goto P_0c094074;
case 0x0c094076u: goto P_0c094076;
case 0x0c094078u: goto P_0c094078;
case 0x0c09407au: goto P_0c09407a;
case 0x0c09407cu: goto P_0c09407c;
case 0x0c09407eu: goto P_0c09407e;
case 0x0c094080u: goto P_0c094080;
case 0x0c094082u: goto P_0c094082;
case 0x0c094084u: goto P_0c094084;
case 0x0c094086u: goto P_0c094086;
case 0x0c094088u: goto P_0c094088;
case 0x0c09408au: goto P_0c09408a;
case 0x0c09408cu: goto P_0c09408c;
case 0x0c09408eu: goto P_0c09408e;
case 0x0c094090u: goto P_0c094090;
case 0x0c094092u: goto P_0c094092;
case 0x0c094094u: goto P_0c094094;
case 0x0c094096u: goto P_0c094096;
case 0x0c094098u: goto P_0c094098;
case 0x0c09409au: goto P_0c09409a;
case 0x0c09409cu: goto P_0c09409c;
case 0x0c09409eu: goto P_0c09409e;
case 0x0c0940a0u: goto P_0c0940a0;
case 0x0c0940a2u: goto P_0c0940a2;
case 0x0c0940a4u: goto P_0c0940a4;
case 0x0c0940a6u: goto P_0c0940a6;
case 0x0c0940a8u: goto P_0c0940a8;
case 0x0c0940aau: goto P_0c0940aa;
case 0x0c0940acu: goto P_0c0940ac;
case 0x0c0940aeu: goto P_0c0940ae;
case 0x0c0940b0u: goto P_0c0940b0;
case 0x0c0940b2u: goto P_0c0940b2;
case 0x0c0940b4u: goto P_0c0940b4;
case 0x0c0940b6u: goto P_0c0940b6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c093a9c: /* original 2fe6, guest PC 0x0c093a9c */
if(!s->budget--) { s->failed_pc=0x0c093a9cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093a9e;
P_0c093a9e: /* original 6e43, guest PC 0x0c093a9e */
if(!s->budget--) { s->failed_pc=0x0c093a9eu; return 0; }
r[14]=r[4];
goto P_0c093aa0;
P_0c093aa0: /* original 7fe8, guest PC 0x0c093aa0 */
if(!s->budget--) { s->failed_pc=0x0c093aa0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c093aa2;
P_0c093aa2: /* original 64f3, guest PC 0x0c093aa2 */
if(!s->budget--) { s->failed_pc=0x0c093aa2u; return 0; }
r[4]=r[15];
goto P_0c093aa4;
P_0c093aa4: /* original 1f52, guest PC 0x0c093aa4 */
if(!s->budget--) { s->failed_pc=0x0c093aa4u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c093aa6;
P_0c093aa6: /* original e004, guest PC 0x0c093aa6 */
if(!s->budget--) { s->failed_pc=0x0c093aa6u; return 0; }
r[0]=0x00000004u;
goto P_0c093aa8;
P_0c093aa8: /* original 65e3, guest PC 0x0c093aa8 */
if(!s->budget--) { s->failed_pc=0x0c093aa8u; return 0; }
r[5]=r[14];
goto P_0c093aaa;
P_0c093aaa: /* original 740c, guest PC 0x0c093aaa */
if(!s->budget--) { s->failed_pc=0x0c093aaau; return 0; }
r[4]+=0x0000000cu;
goto P_0c093aac;
P_0c093aac: /* original ff47, guest PC 0x0c093aac */
if(!s->budget--) { s->failed_pc=0x0c093aacu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c093aae;
P_0c093aae: /* original 2f62, guest PC 0x0c093aae */
if(!s->budget--) { s->failed_pc=0x0c093aaeu; return 0; }
write(ram,r[15],r[6],4);
goto P_0c093ab0;
P_0c093ab0: /* original 56f2, guest PC 0x0c093ab0 */
if(!s->budget--) { s->failed_pc=0x0c093ab0u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c093ab2;
P_0c093ab2: /* original a001, guest PC 0x0c093ab2 */
if(!s->budget--) { s->failed_pc=0x0c093ab2u; return 0; }
goto P_0c093ab8;
P_0c093ab4: /* original 0009, guest PC 0x0c093ab4 */
if(!s->budget--) { s->failed_pc=0x0c093ab4u; return 0; }
if(!vf3_matrix_family(0x0c093ab6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093ab6u; return 0; } return 1;
P_0c093ab8: /* original f059, guest PC 0x0c093ab8 */
if(!s->budget--) { s->failed_pc=0x0c093ab8u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093aba;
P_0c093aba: /* original f369, guest PC 0x0c093aba */
if(!s->budget--) { s->failed_pc=0x0c093abau; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093abc;
P_0c093abc: /* original f159, guest PC 0x0c093abc */
if(!s->budget--) { s->failed_pc=0x0c093abcu; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093abe;
P_0c093abe: /* original f469, guest PC 0x0c093abe */
if(!s->budget--) { s->failed_pc=0x0c093abeu; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
r[6]+=(r[18]&0x100000u)?8:4;
goto P_0c093ac0;
P_0c093ac0: /* original f031, guest PC 0x0c093ac0 */
if(!s->budget--) { s->failed_pc=0x0c093ac0u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c093ac2;
P_0c093ac2: /* original f258, guest PC 0x0c093ac2 */
if(!s->budget--) { s->failed_pc=0x0c093ac2u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c093ac4;
P_0c093ac4: /* original f568, guest PC 0x0c093ac4 */
if(!s->budget--) { s->failed_pc=0x0c093ac4u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c093ac6;
P_0c093ac6: /* original f141, guest PC 0x0c093ac6 */
if(!s->budget--) { s->failed_pc=0x0c093ac6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'-');
goto P_0c093ac8;
P_0c093ac8: /* original f251, guest PC 0x0c093ac8 */
if(!s->budget--) { s->failed_pc=0x0c093ac8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'-');
goto P_0c093aca;
P_0c093aca: /* original 7408, guest PC 0x0c093aca */
if(!s->budget--) { s->failed_pc=0x0c093acau; return 0; }
r[4]+=0x00000008u;
goto P_0c093acc;
P_0c093acc: /* original f42a, guest PC 0x0c093acc */
if(!s->budget--) { s->failed_pc=0x0c093accu; return 0; }
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093ace;
P_0c093ace: /* original f41b, guest PC 0x0c093ace */
if(!s->budget--) { s->failed_pc=0x0c093aceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093ad0;
P_0c093ad0: /* original f40b, guest PC 0x0c093ad0 */
if(!s->budget--) { s->failed_pc=0x0c093ad0u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093ad2;
P_0c093ad2: /* original 0009, guest PC 0x0c093ad2 */
if(!s->budget--) { s->failed_pc=0x0c093ad2u; return 0; }
goto P_0c093ad4;
P_0c093ad4: /* original 64f3, guest PC 0x0c093ad4 */
if(!s->budget--) { s->failed_pc=0x0c093ad4u; return 0; }
r[4]=r[15];
goto P_0c093ad6;
P_0c093ad6: /* original 740c, guest PC 0x0c093ad6 */
if(!s->budget--) { s->failed_pc=0x0c093ad6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093ad8;
P_0c093ad8: /* original f049, guest PC 0x0c093ad8 */
if(!s->budget--) { s->failed_pc=0x0c093ad8u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093ada;
P_0c093ada: /* original f149, guest PC 0x0c093ada */
if(!s->budget--) { s->failed_pc=0x0c093adau; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093adc;
P_0c093adc: /* original f249, guest PC 0x0c093adc */
if(!s->budget--) { s->failed_pc=0x0c093adcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093ade;
P_0c093ade: /* original f38d, guest PC 0x0c093ade */
if(!s->budget--) { s->failed_pc=0x0c093adeu; return 0; }
fr[3]=0;
goto P_0c093ae0;
P_0c093ae0: /* original f0ed, guest PC 0x0c093ae0 */
if(!s->budget--) { s->failed_pc=0x0c093ae0u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c093ae2;
P_0c093ae2: /* original f03c, guest PC 0x0c093ae2 */
if(!s->budget--) { s->failed_pc=0x0c093ae2u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c093ae4;
P_0c093ae4: /* original f06d, guest PC 0x0c093ae4 */
if(!s->budget--) { s->failed_pc=0x0c093ae4u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c093ae6;
P_0c093ae6: /* original 0009, guest PC 0x0c093ae6 */
if(!s->budget--) { s->failed_pc=0x0c093ae6u; return 0; }
goto P_0c093ae8;
P_0c093ae8: /* original e004, guest PC 0x0c093ae8 */
if(!s->budget--) { s->failed_pc=0x0c093ae8u; return 0; }
r[0]=0x00000004u;
goto P_0c093aea;
P_0c093aea: /* original f40c, guest PC 0x0c093aea */
if(!s->budget--) { s->failed_pc=0x0c093aeau; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c093aec;
P_0c093aec: /* original f3f6, guest PC 0x0c093aec */
if(!s->budget--) { s->failed_pc=0x0c093aecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c093aee;
P_0c093aee: /* original f345, guest PC 0x0c093aee */
if(!s->budget--) { s->failed_pc=0x0c093aeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c093af0;
P_0c093af0: /* original 8902, guest PC 0x0c093af0 */
if(!s->budget--) { s->failed_pc=0x0c093af0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093af8; }
goto P_0c093af2;
P_0c093af2: /* original d306, guest PC 0x0c093af2 */
if(!s->budget--) { s->failed_pc=0x0c093af2u; return 0; }
r[3]=read(ram,0x0c093b0cu,4);
goto P_0c093af4;
P_0c093af4: /* original 432b, guest PC 0x0c093af4 */
if(!s->budget--) { s->failed_pc=0x0c093af4u; return 0; }
target=r[3];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093b4au: goto P_0c093b4a;
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
P_0c093af6: /* original 0009, guest PC 0x0c093af6 */
if(!s->budget--) { s->failed_pc=0x0c093af6u; return 0; }
goto P_0c093af8;
P_0c093af8: /* original e004, guest PC 0x0c093af8 */
if(!s->budget--) { s->failed_pc=0x0c093af8u; return 0; }
r[0]=0x00000004u;
goto P_0c093afa;
P_0c093afa: /* original f34c, guest PC 0x0c093afa */
if(!s->budget--) { s->failed_pc=0x0c093afau; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c093afc;
P_0c093afc: /* original f4f6, guest PC 0x0c093afc */
if(!s->budget--) { s->failed_pc=0x0c093afcu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c093afe;
P_0c093afe: /* original 65f3, guest PC 0x0c093afe */
if(!s->budget--) { s->failed_pc=0x0c093afeu; return 0; }
r[5]=r[15];
goto P_0c093b00;
P_0c093b00: /* original 64e3, guest PC 0x0c093b00 */
if(!s->budget--) { s->failed_pc=0x0c093b00u; return 0; }
r[4]=r[14];
goto P_0c093b02;
P_0c093b02: /* original 750c, guest PC 0x0c093b02 */
if(!s->budget--) { s->failed_pc=0x0c093b02u; return 0; }
r[5]+=0x0000000cu;
goto P_0c093b04;
P_0c093b04: /* original f433, guest PC 0x0c093b04 */
if(!s->budget--) { s->failed_pc=0x0c093b04u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c093b06;
P_0c093b06: /* original a003, guest PC 0x0c093b06 */
if(!s->budget--) { s->failed_pc=0x0c093b06u; return 0; }
goto P_0c093b10;
P_0c093b08: /* original 0009, guest PC 0x0c093b08 */
if(!s->budget--) { s->failed_pc=0x0c093b08u; return 0; }
if(!vf3_matrix_family(0x0c093b0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093b0au; return 0; } return 1;
P_0c093b10: /* original f059, guest PC 0x0c093b10 */
if(!s->budget--) { s->failed_pc=0x0c093b10u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b12;
P_0c093b12: /* original f159, guest PC 0x0c093b12 */
if(!s->budget--) { s->failed_pc=0x0c093b12u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b14;
P_0c093b14: /* original f259, guest PC 0x0c093b14 */
if(!s->budget--) { s->failed_pc=0x0c093b14u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b16;
P_0c093b16: /* original 740c, guest PC 0x0c093b16 */
if(!s->budget--) { s->failed_pc=0x0c093b16u; return 0; }
r[4]+=0x0000000cu;
goto P_0c093b18;
P_0c093b18: /* original f242, guest PC 0x0c093b18 */
if(!s->budget--) { s->failed_pc=0x0c093b18u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c093b1a;
P_0c093b1a: /* original f142, guest PC 0x0c093b1a */
if(!s->budget--) { s->failed_pc=0x0c093b1au; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'*');
goto P_0c093b1c;
P_0c093b1c: /* original f042, guest PC 0x0c093b1c */
if(!s->budget--) { s->failed_pc=0x0c093b1cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'*');
goto P_0c093b1e;
P_0c093b1e: /* original f42b, guest PC 0x0c093b1e */
if(!s->budget--) { s->failed_pc=0x0c093b1eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093b20;
P_0c093b20: /* original f41b, guest PC 0x0c093b20 */
if(!s->budget--) { s->failed_pc=0x0c093b20u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093b22;
P_0c093b22: /* original f40b, guest PC 0x0c093b22 */
if(!s->budget--) { s->failed_pc=0x0c093b22u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093b24;
P_0c093b24: /* original 55f2, guest PC 0x0c093b24 */
if(!s->budget--) { s->failed_pc=0x0c093b24u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c093b26;
P_0c093b26: /* original 64e3, guest PC 0x0c093b26 */
if(!s->budget--) { s->failed_pc=0x0c093b26u; return 0; }
r[4]=r[14];
goto P_0c093b28;
P_0c093b28: /* original f049, guest PC 0x0c093b28 */
if(!s->budget--) { s->failed_pc=0x0c093b28u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2a;
P_0c093b2a: /* original f359, guest PC 0x0c093b2a */
if(!s->budget--) { s->failed_pc=0x0c093b2au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2c;
P_0c093b2c: /* original f149, guest PC 0x0c093b2c */
if(!s->budget--) { s->failed_pc=0x0c093b2cu; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b2e;
P_0c093b2e: /* original f459, guest PC 0x0c093b2e */
if(!s->budget--) { s->failed_pc=0x0c093b2eu; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b30;
P_0c093b30: /* original f249, guest PC 0x0c093b30 */
if(!s->budget--) { s->failed_pc=0x0c093b30u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093b32;
P_0c093b32: /* original f559, guest PC 0x0c093b32 */
if(!s->budget--) { s->failed_pc=0x0c093b32u; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c093b34;
P_0c093b34: /* original f030, guest PC 0x0c093b34 */
if(!s->budget--) { s->failed_pc=0x0c093b34u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'+');
goto P_0c093b36;
P_0c093b36: /* original f250, guest PC 0x0c093b36 */
if(!s->budget--) { s->failed_pc=0x0c093b36u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c093b38;
P_0c093b38: /* original f140, guest PC 0x0c093b38 */
if(!s->budget--) { s->failed_pc=0x0c093b38u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[4],r[18],'+');
goto P_0c093b3a;
P_0c093b3a: /* original f42b, guest PC 0x0c093b3a */
if(!s->budget--) { s->failed_pc=0x0c093b3au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c093b3c;
P_0c093b3c: /* original f41b, guest PC 0x0c093b3c */
if(!s->budget--) { s->failed_pc=0x0c093b3cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c093b3e;
P_0c093b3e: /* original f40b, guest PC 0x0c093b3e */
if(!s->budget--) { s->failed_pc=0x0c093b3eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c093b40;
P_0c093b40: /* original 63f2, guest PC 0x0c093b40 */
if(!s->budget--) { s->failed_pc=0x0c093b40u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c093b42;
P_0c093b42: /* original 9276, guest PC 0x0c093b42 */
if(!s->budget--) { s->failed_pc=0x0c093b42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c32u,2);
goto P_0c093b44;
P_0c093b44: /* original 6132, guest PC 0x0c093b44 */
if(!s->budget--) { s->failed_pc=0x0c093b44u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c093b46;
P_0c093b46: /* original 212b, guest PC 0x0c093b46 */
if(!s->budget--) { s->failed_pc=0x0c093b46u; return 0; }
r[1]|=r[2];
goto P_0c093b48;
P_0c093b48: /* original 2312, guest PC 0x0c093b48 */
if(!s->budget--) { s->failed_pc=0x0c093b48u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c093b4a;
P_0c093b4a: /* original 60f2, guest PC 0x0c093b4a */
if(!s->budget--) { s->failed_pc=0x0c093b4au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093b4c;
P_0c093b4c: /* original 7f18, guest PC 0x0c093b4c */
if(!s->budget--) { s->failed_pc=0x0c093b4cu; return 0; }
r[15]+=0x00000018u;
goto P_0c093b4e;
P_0c093b4e: /* original 6002, guest PC 0x0c093b4e */
if(!s->budget--) { s->failed_pc=0x0c093b4eu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c093b50;
P_0c093b50: /* original 000b, guest PC 0x0c093b50 */
if(!s->budget--) { s->failed_pc=0x0c093b50u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093b52: /* original 6ef6, guest PC 0x0c093b52 */
if(!s->budget--) { s->failed_pc=0x0c093b52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c093b54u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093b54u; return 0; } return 1;
P_0c093bea: /* original 2fe6, guest PC 0x0c093bea */
if(!s->budget--) { s->failed_pc=0x0c093beau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bec;
P_0c093bec: /* original 6e43, guest PC 0x0c093bec */
if(!s->budget--) { s->failed_pc=0x0c093becu; return 0; }
r[14]=r[4];
goto P_0c093bee;
P_0c093bee: /* original 2fd6, guest PC 0x0c093bee */
if(!s->budget--) { s->failed_pc=0x0c093beeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf0;
P_0c093bf0: /* original 6d53, guest PC 0x0c093bf0 */
if(!s->budget--) { s->failed_pc=0x0c093bf0u; return 0; }
r[13]=r[5];
goto P_0c093bf2;
P_0c093bf2: /* original 2fc6, guest PC 0x0c093bf2 */
if(!s->budget--) { s->failed_pc=0x0c093bf2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf4;
P_0c093bf4: /* original 2fb6, guest PC 0x0c093bf4 */
if(!s->budget--) { s->failed_pc=0x0c093bf4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf6;
P_0c093bf6: /* original 2fa6, guest PC 0x0c093bf6 */
if(!s->budget--) { s->failed_pc=0x0c093bf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093bf8;
P_0c093bf8: /* original 84d4, guest PC 0x0c093bf8 */
if(!s->budget--) { s->failed_pc=0x0c093bf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c093bfa;
P_0c093bfa: /* original 4f22, guest PC 0x0c093bfa */
if(!s->budget--) { s->failed_pc=0x0c093bfau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c093bfc;
P_0c093bfc: /* original 2008, guest PC 0x0c093bfc */
if(!s->budget--) { s->failed_pc=0x0c093bfcu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c093bfe;
P_0c093bfe: /* original 8f25, guest PC 0x0c093bfe */
if(!s->budget--) { s->failed_pc=0x0c093bfeu; return 0; }
cond=r[17]&1u;
r[5]=0x00000001u;
if(!cond) { goto P_0c093c4c; }
goto P_0c093c02;
P_0c093c00: /* original e501, guest PC 0x0c093c00 */
if(!s->budget--) { s->failed_pc=0x0c093c00u; return 0; }
r[5]=0x00000001u;
goto P_0c093c02;
P_0c093c02: /* original 84d4, guest PC 0x0c093c02 */
if(!s->budget--) { s->failed_pc=0x0c093c02u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c093c04;
P_0c093c04: /* original 9218, guest PC 0x0c093c04 */
if(!s->budget--) { s->failed_pc=0x0c093c04u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c38u,2);
goto P_0c093c06;
P_0c093c06: /* original 6403, guest PC 0x0c093c06 */
if(!s->budget--) { s->failed_pc=0x0c093c06u; return 0; }
r[4]=r[0];
goto P_0c093c08;
P_0c093c08: /* original 6b4c, guest PC 0x0c093c08 */
if(!s->budget--) { s->failed_pc=0x0c093c08u; return 0; }
r[11]=r[4]&255u;
goto P_0c093c0a;
P_0c093c0a: /* original 63b3, guest PC 0x0c093c0a */
if(!s->budget--) { s->failed_pc=0x0c093c0au; return 0; }
r[3]=r[11];
goto P_0c093c0c;
P_0c093c0c: /* original 4b00, guest PC 0x0c093c0c */
if(!s->budget--) { s->failed_pc=0x0c093c0cu; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c093c0e;
P_0c093c0e: /* original 3b3c, guest PC 0x0c093c0e */
if(!s->budget--) { s->failed_pc=0x0c093c0eu; return 0; }
r[11]+=r[3];
goto P_0c093c10;
P_0c093c10: /* original 6c03, guest PC 0x0c093c10 */
if(!s->budget--) { s->failed_pc=0x0c093c10u; return 0; }
r[12]=r[0];
goto P_0c093c12;
P_0c093c12: /* original 4b18, guest PC 0x0c093c12 */
if(!s->budget--) { s->failed_pc=0x0c093c12u; return 0; }
r[11]<<=8;
goto P_0c093c14;
P_0c093c14: /* original 6303, guest PC 0x0c093c14 */
if(!s->budget--) { s->failed_pc=0x0c093c14u; return 0; }
r[3]=r[0];
goto P_0c093c16;
P_0c093c16: /* original 4b08, guest PC 0x0c093c16 */
if(!s->budget--) { s->failed_pc=0x0c093c16u; return 0; }
r[11]<<=2;
goto P_0c093c18;
P_0c093c18: /* original 4b08, guest PC 0x0c093c18 */
if(!s->budget--) { s->failed_pc=0x0c093c18u; return 0; }
r[11]<<=2;
goto P_0c093c1a;
P_0c093c1a: /* original 32ec, guest PC 0x0c093c1a */
if(!s->budget--) { s->failed_pc=0x0c093c1au; return 0; }
r[2]+=r[14];
goto P_0c093c1c;
P_0c093c1c: /* original 6bbf, guest PC 0x0c093c1c */
if(!s->budget--) { s->failed_pc=0x0c093c1cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c093c1e;
P_0c093c1e: /* original 4c08, guest PC 0x0c093c1e */
if(!s->budget--) { s->failed_pc=0x0c093c1eu; return 0; }
r[12]<<=2;
goto P_0c093c20;
P_0c093c20: /* original 3b2c, guest PC 0x0c093c20 */
if(!s->budget--) { s->failed_pc=0x0c093c20u; return 0; }
r[11]+=r[2];
goto P_0c093c22;
P_0c093c22: /* original 920a, guest PC 0x0c093c22 */
if(!s->budget--) { s->failed_pc=0x0c093c22u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093c3au,2);
goto P_0c093c24;
P_0c093c24: /* original 3c3c, guest PC 0x0c093c24 */
if(!s->budget--) { s->failed_pc=0x0c093c24u; return 0; }
r[12]+=r[3];
goto P_0c093c26;
P_0c093c26: /* original 4c08, guest PC 0x0c093c26 */
if(!s->budget--) { s->failed_pc=0x0c093c26u; return 0; }
r[12]<<=2;
goto P_0c093c28;
P_0c093c28: /* original 32ec, guest PC 0x0c093c28 */
if(!s->budget--) { s->failed_pc=0x0c093c28u; return 0; }
r[2]+=r[14];
goto P_0c093c2a;
P_0c093c2a: /* original 6cce, guest PC 0x0c093c2a */
if(!s->budget--) { s->failed_pc=0x0c093c2au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c093c2c;
P_0c093c2c: /* original 3c2c, guest PC 0x0c093c2c */
if(!s->budget--) { s->failed_pc=0x0c093c2cu; return 0; }
r[12]+=r[2];
goto P_0c093c2e;
P_0c093c2e: /* original a023, guest PC 0x0c093c2e */
if(!s->budget--) { s->failed_pc=0x0c093c2eu; return 0; }
r[0]=0x0000002cu;
goto P_0c093c78;
P_0c093c30: /* original e02c, guest PC 0x0c093c30 */
if(!s->budget--) { s->failed_pc=0x0c093c30u; return 0; }
r[0]=0x0000002cu;
if(!vf3_matrix_family(0x0c093c32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093c32u; return 0; } return 1;
P_0c093c4c: /* original 6403, guest PC 0x0c093c4c */
if(!s->budget--) { s->failed_pc=0x0c093c4cu; return 0; }
r[4]=r[0];
goto P_0c093c4e;
P_0c093c4e: /* original 6b4c, guest PC 0x0c093c4e */
if(!s->budget--) { s->failed_pc=0x0c093c4eu; return 0; }
r[11]=r[4]&255u;
goto P_0c093c50;
P_0c093c50: /* original 63b3, guest PC 0x0c093c50 */
if(!s->budget--) { s->failed_pc=0x0c093c50u; return 0; }
r[3]=r[11];
goto P_0c093c52;
P_0c093c52: /* original 4b00, guest PC 0x0c093c52 */
if(!s->budget--) { s->failed_pc=0x0c093c52u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c093c54;
P_0c093c54: /* original 3b3c, guest PC 0x0c093c54 */
if(!s->budget--) { s->failed_pc=0x0c093c54u; return 0; }
r[11]+=r[3];
goto P_0c093c56;
P_0c093c56: /* original 9277, guest PC 0x0c093c56 */
if(!s->budget--) { s->failed_pc=0x0c093c56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d48u,2);
goto P_0c093c58;
P_0c093c58: /* original 4b18, guest PC 0x0c093c58 */
if(!s->budget--) { s->failed_pc=0x0c093c58u; return 0; }
r[11]<<=8;
goto P_0c093c5a;
P_0c093c5a: /* original 6c03, guest PC 0x0c093c5a */
if(!s->budget--) { s->failed_pc=0x0c093c5au; return 0; }
r[12]=r[0];
goto P_0c093c5c;
P_0c093c5c: /* original 4b08, guest PC 0x0c093c5c */
if(!s->budget--) { s->failed_pc=0x0c093c5cu; return 0; }
r[11]<<=2;
goto P_0c093c5e;
P_0c093c5e: /* original 6303, guest PC 0x0c093c5e */
if(!s->budget--) { s->failed_pc=0x0c093c5eu; return 0; }
r[3]=r[0];
goto P_0c093c60;
P_0c093c60: /* original 4b08, guest PC 0x0c093c60 */
if(!s->budget--) { s->failed_pc=0x0c093c60u; return 0; }
r[11]<<=2;
goto P_0c093c62;
P_0c093c62: /* original 32ec, guest PC 0x0c093c62 */
if(!s->budget--) { s->failed_pc=0x0c093c62u; return 0; }
r[2]+=r[14];
goto P_0c093c64;
P_0c093c64: /* original 6bbf, guest PC 0x0c093c64 */
if(!s->budget--) { s->failed_pc=0x0c093c64u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c093c66;
P_0c093c66: /* original 4c08, guest PC 0x0c093c66 */
if(!s->budget--) { s->failed_pc=0x0c093c66u; return 0; }
r[12]<<=2;
goto P_0c093c68;
P_0c093c68: /* original 3b2c, guest PC 0x0c093c68 */
if(!s->budget--) { s->failed_pc=0x0c093c68u; return 0; }
r[11]+=r[2];
goto P_0c093c6a;
P_0c093c6a: /* original 926e, guest PC 0x0c093c6a */
if(!s->budget--) { s->failed_pc=0x0c093c6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d4au,2);
goto P_0c093c6c;
P_0c093c6c: /* original 3c3c, guest PC 0x0c093c6c */
if(!s->budget--) { s->failed_pc=0x0c093c6cu; return 0; }
r[12]+=r[3];
goto P_0c093c6e;
P_0c093c6e: /* original 4c08, guest PC 0x0c093c6e */
if(!s->budget--) { s->failed_pc=0x0c093c6eu; return 0; }
r[12]<<=2;
goto P_0c093c70;
P_0c093c70: /* original 32ec, guest PC 0x0c093c70 */
if(!s->budget--) { s->failed_pc=0x0c093c70u; return 0; }
r[2]+=r[14];
goto P_0c093c72;
P_0c093c72: /* original 6cce, guest PC 0x0c093c72 */
if(!s->budget--) { s->failed_pc=0x0c093c72u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[12];
goto P_0c093c74;
P_0c093c74: /* original e02e, guest PC 0x0c093c74 */
if(!s->budget--) { s->failed_pc=0x0c093c74u; return 0; }
r[0]=0x0000002eu;
goto P_0c093c76;
P_0c093c76: /* original 3c2c, guest PC 0x0c093c76 */
if(!s->budget--) { s->failed_pc=0x0c093c76u; return 0; }
r[12]+=r[2];
goto P_0c093c78;
P_0c093c78: /* original 0e55, guest PC 0x0c093c78 */
if(!s->budget--) { s->failed_pc=0x0c093c78u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c093c7a;
P_0c093c7a: /* original e060, guest PC 0x0c093c7a */
if(!s->budget--) { s->failed_pc=0x0c093c7au; return 0; }
r[0]=0x00000060u;
goto P_0c093c7c;
P_0c093c7c: /* original 0adc, guest PC 0x0c093c7c */
if(!s->budget--) { s->failed_pc=0x0c093c7cu; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c093c7e;
P_0c093c7e: /* original 65c3, guest PC 0x0c093c7e */
if(!s->budget--) { s->failed_pc=0x0c093c7eu; return 0; }
r[5]=r[12];
goto P_0c093c80;
P_0c093c80: /* original 6aac, guest PC 0x0c093c80 */
if(!s->budget--) { s->failed_pc=0x0c093c80u; return 0; }
r[10]=r[10]&255u;
goto P_0c093c82;
P_0c093c82: /* original 66a3, guest PC 0x0c093c82 */
if(!s->budget--) { s->failed_pc=0x0c093c82u; return 0; }
r[6]=r[10];
goto P_0c093c84;
P_0c093c84: /* original b012, guest PC 0x0c093c84 */
if(!s->budget--) { s->failed_pc=0x0c093c84u; return 0; }
target=code_base|0x0c093cacu; r[16]=code_base|0x0c093c88u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093c88u) { target=s->pc; goto dispatch; }
goto P_0c093c88;
P_0c093c86: /* original 64e3, guest PC 0x0c093c86 */
if(!s->budget--) { s->failed_pc=0x0c093c86u; return 0; }
r[4]=r[14];
goto P_0c093c88;
P_0c093c88: /* original 66c3, guest PC 0x0c093c88 */
if(!s->budget--) { s->failed_pc=0x0c093c88u; return 0; }
r[6]=r[12];
goto P_0c093c8a;
P_0c093c8a: /* original 65d3, guest PC 0x0c093c8a */
if(!s->budget--) { s->failed_pc=0x0c093c8au; return 0; }
r[5]=r[13];
goto P_0c093c8c;
P_0c093c8c: /* original 2fa6, guest PC 0x0c093c8c */
if(!s->budget--) { s->failed_pc=0x0c093c8cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093c8e;
P_0c093c8e: /* original 67b3, guest PC 0x0c093c8e */
if(!s->budget--) { s->failed_pc=0x0c093c8eu; return 0; }
r[7]=r[11];
goto P_0c093c90;
P_0c093c90: /* original b026, guest PC 0x0c093c90 */
if(!s->budget--) { s->failed_pc=0x0c093c90u; return 0; }
target=code_base|0x0c093ce0u; r[16]=code_base|0x0c093c94u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c093c94u) { target=s->pc; goto dispatch; }
goto P_0c093c94;
P_0c093c92: /* original 64e3, guest PC 0x0c093c92 */
if(!s->budget--) { s->failed_pc=0x0c093c92u; return 0; }
r[4]=r[14];
goto P_0c093c94;
P_0c093c94: /* original 7f04, guest PC 0x0c093c94 */
if(!s->budget--) { s->failed_pc=0x0c093c94u; return 0; }
r[15]+=0x00000004u;
goto P_0c093c96;
P_0c093c96: /* original 9459, guest PC 0x0c093c96 */
if(!s->budget--) { s->failed_pc=0x0c093c96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d4cu,2);
goto P_0c093c98;
P_0c093c98: /* original 4f26, guest PC 0x0c093c98 */
if(!s->budget--) { s->failed_pc=0x0c093c98u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c093c9a;
P_0c093c9a: /* original e300, guest PC 0x0c093c9a */
if(!s->budget--) { s->failed_pc=0x0c093c9au; return 0; }
r[3]=0x00000000u;
goto P_0c093c9c;
P_0c093c9c: /* original 34ec, guest PC 0x0c093c9c */
if(!s->budget--) { s->failed_pc=0x0c093c9cu; return 0; }
r[4]+=r[14];
goto P_0c093c9e;
P_0c093c9e: /* original 2432, guest PC 0x0c093c9e */
if(!s->budget--) { s->failed_pc=0x0c093c9eu; return 0; }
write(ram,r[4],r[3],4);
goto P_0c093ca0;
P_0c093ca0: /* original 6af6, guest PC 0x0c093ca0 */
if(!s->budget--) { s->failed_pc=0x0c093ca0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c093ca2;
P_0c093ca2: /* original 6bf6, guest PC 0x0c093ca2 */
if(!s->budget--) { s->failed_pc=0x0c093ca2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c093ca4;
P_0c093ca4: /* original 6cf6, guest PC 0x0c093ca4 */
if(!s->budget--) { s->failed_pc=0x0c093ca4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c093ca6;
P_0c093ca6: /* original 6df6, guest PC 0x0c093ca6 */
if(!s->budget--) { s->failed_pc=0x0c093ca6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c093ca8;
P_0c093ca8: /* original 000b, guest PC 0x0c093ca8 */
if(!s->budget--) { s->failed_pc=0x0c093ca8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c093caa: /* original 6ef6, guest PC 0x0c093caa */
if(!s->budget--) { s->failed_pc=0x0c093caau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c093cac;
P_0c093cac: /* original d028, guest PC 0x0c093cac */
if(!s->budget--) { s->failed_pc=0x0c093cacu; return 0; }
r[0]=read(ram,0x0c093d50u,4);
goto P_0c093cae;
P_0c093cae: /* original 036c, guest PC 0x0c093cae */
if(!s->budget--) { s->failed_pc=0x0c093caeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+r[0],1);
goto P_0c093cb0;
P_0c093cb0: /* original d028, guest PC 0x0c093cb0 */
if(!s->budget--) { s->failed_pc=0x0c093cb0u; return 0; }
r[0]=read(ram,0x0c093d54u,4);
goto P_0c093cb2;
P_0c093cb2: /* original 663c, guest PC 0x0c093cb2 */
if(!s->budget--) { s->failed_pc=0x0c093cb2u; return 0; }
r[6]=r[3]&255u;
goto P_0c093cb4;
P_0c093cb4: /* original 4601, guest PC 0x0c093cb4 */
if(!s->budget--) { s->failed_pc=0x0c093cb4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c093cb6;
P_0c093cb6: /* original 4600, guest PC 0x0c093cb6 */
if(!s->budget--) { s->failed_pc=0x0c093cb6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c093cb8;
P_0c093cb8: /* original 026d, guest PC 0x0c093cb8 */
if(!s->budget--) { s->failed_pc=0x0c093cb8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c093cba;
P_0c093cba: /* original 8548, guest PC 0x0c093cba */
if(!s->budget--) { s->failed_pc=0x0c093cbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+16,2);
goto P_0c093cbc;
P_0c093cbc: /* original 600d, guest PC 0x0c093cbc */
if(!s->budget--) { s->failed_pc=0x0c093cbcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c093cbe;
P_0c093cbe: /* original c801, guest PC 0x0c093cbe */
if(!s->budget--) { s->failed_pc=0x0c093cbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c093cc0;
P_0c093cc0: /* original 8f0c, guest PC 0x0c093cc0 */
if(!s->budget--) { s->failed_pc=0x0c093cc0u; return 0; }
cond=r[17]&1u;
r[6]=(uint32_t)(int32_t)(int16_t)r[2];
if(!cond) { goto P_0c093cdc; }
goto P_0c093cc4;
P_0c093cc2: /* original 662f, guest PC 0x0c093cc2 */
if(!s->budget--) { s->failed_pc=0x0c093cc2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c093cc4;
P_0c093cc4: /* original d324, guest PC 0x0c093cc4 */
if(!s->budget--) { s->failed_pc=0x0c093cc4u; return 0; }
r[3]=read(ram,0x0c093d58u,4);
goto P_0c093cc6;
P_0c093cc6: /* original d125, guest PC 0x0c093cc6 */
if(!s->budget--) { s->failed_pc=0x0c093cc6u; return 0; }
r[1]=read(ram,0x0c093d5cu,4);
goto P_0c093cc8;
P_0c093cc8: /* original 6030, guest PC 0x0c093cc8 */
if(!s->budget--) { s->failed_pc=0x0c093cc8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c093cca;
P_0c093cca: /* original f38d, guest PC 0x0c093cca */
if(!s->budget--) { s->failed_pc=0x0c093ccau; return 0; }
fr[3]=0;
goto P_0c093ccc;
P_0c093ccc: /* original 600c, guest PC 0x0c093ccc */
if(!s->budget--) { s->failed_pc=0x0c093cccu; return 0; }
r[0]=r[0]&255u;
goto P_0c093cce;
P_0c093cce: /* original c90f, guest PC 0x0c093cce */
if(!s->budget--) { s->failed_pc=0x0c093cceu; return 0; }
r[0]&=15u;
goto P_0c093cd0;
P_0c093cd0: /* original 4008, guest PC 0x0c093cd0 */
if(!s->budget--) { s->failed_pc=0x0c093cd0u; return 0; }
r[0]<<=2;
goto P_0c093cd2;
P_0c093cd2: /* original f416, guest PC 0x0c093cd2 */
if(!s->budget--) { s->failed_pc=0x0c093cd2u; return 0; }
vf3_matrix_load(s,ram,4,r[1]+r[0]);
goto P_0c093cd4;
P_0c093cd4: /* original f434, guest PC 0x0c093cd4 */
if(!s->budget--) { s->failed_pc=0x0c093cd4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c093cd6;
P_0c093cd6: /* original 8901, guest PC 0x0c093cd6 */
if(!s->budget--) { s->failed_pc=0x0c093cd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093cdc; }
goto P_0c093cd8;
P_0c093cd8: /* original e110, guest PC 0x0c093cd8 */
if(!s->budget--) { s->failed_pc=0x0c093cd8u; return 0; }
r[1]=0x00000010u;
goto P_0c093cda;
P_0c093cda: /* original 261b, guest PC 0x0c093cda */
if(!s->budget--) { s->failed_pc=0x0c093cdau; return 0; }
r[6]|=r[1];
goto P_0c093cdc;
P_0c093cdc: /* original 000b, guest PC 0x0c093cdc */
if(!s->budget--) { s->failed_pc=0x0c093cdcu; return 0; }
target=r[16];
write(ram,r[5],r[6],2);
s->pc=target; return ram->oob==0;
P_0c093cde: /* original 2561, guest PC 0x0c093cde */
if(!s->budget--) { s->failed_pc=0x0c093cdeu; return 0; }
write(ram,r[5],r[6],2);
goto P_0c093ce0;
P_0c093ce0: /* original 2fe6, guest PC 0x0c093ce0 */
if(!s->budget--) { s->failed_pc=0x0c093ce0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093ce2;
P_0c093ce2: /* original e05c, guest PC 0x0c093ce2 */
if(!s->budget--) { s->failed_pc=0x0c093ce2u; return 0; }
r[0]=0x0000005cu;
goto P_0c093ce4;
P_0c093ce4: /* original 2fd6, guest PC 0x0c093ce4 */
if(!s->budget--) { s->failed_pc=0x0c093ce4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093ce6;
P_0c093ce6: /* original 6e73, guest PC 0x0c093ce6 */
if(!s->budget--) { s->failed_pc=0x0c093ce6u; return 0; }
r[14]=r[7];
goto P_0c093ce8;
P_0c093ce8: /* original 2fc6, guest PC 0x0c093ce8 */
if(!s->budget--) { s->failed_pc=0x0c093ce8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093cea;
P_0c093cea: /* original 2fb6, guest PC 0x0c093cea */
if(!s->budget--) { s->failed_pc=0x0c093ceau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093cec;
P_0c093cec: /* original 2fa6, guest PC 0x0c093cec */
if(!s->budget--) { s->failed_pc=0x0c093cecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093cee;
P_0c093cee: /* original 2f96, guest PC 0x0c093cee */
if(!s->budget--) { s->failed_pc=0x0c093ceeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093cf0;
P_0c093cf0: /* original 6953, guest PC 0x0c093cf0 */
if(!s->budget--) { s->failed_pc=0x0c093cf0u; return 0; }
r[9]=r[5];
goto P_0c093cf2;
P_0c093cf2: /* original 2f86, guest PC 0x0c093cf2 */
if(!s->budget--) { s->failed_pc=0x0c093cf2u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c093cf4;
P_0c093cf4: /* original 7fc0, guest PC 0x0c093cf4 */
if(!s->budget--) { s->failed_pc=0x0c093cf4u; return 0; }
r[15]+=0xffffffc0u;
goto P_0c093cf6;
P_0c093cf6: /* original 2f42, guest PC 0x0c093cf6 */
if(!s->budget--) { s->failed_pc=0x0c093cf6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c093cf8;
P_0c093cf8: /* original 0afe, guest PC 0x0c093cf8 */
if(!s->budget--) { s->failed_pc=0x0c093cf8u; return 0; }
r[10]=read(ram,r[15]+r[0],4);
goto P_0c093cfa;
P_0c093cfa: /* original 60f2, guest PC 0x0c093cfa */
if(!s->budget--) { s->failed_pc=0x0c093cfau; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093cfc;
P_0c093cfc: /* original 8508, guest PC 0x0c093cfc */
if(!s->budget--) { s->failed_pc=0x0c093cfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[0]+16,2);
goto P_0c093cfe;
P_0c093cfe: /* original 600d, guest PC 0x0c093cfe */
if(!s->budget--) { s->failed_pc=0x0c093cfeu; return 0; }
r[0]=r[0]&65535u;
goto P_0c093d00;
P_0c093d00: /* original c801, guest PC 0x0c093d00 */
if(!s->budget--) { s->failed_pc=0x0c093d00u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c093d02;
P_0c093d02: /* original 8d0e, guest PC 0x0c093d02 */
if(!s->budget--) { s->failed_pc=0x0c093d02u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c093d22; }
goto P_0c093d06;
P_0c093d04: /* original 64a3, guest PC 0x0c093d04 */
if(!s->budget--) { s->failed_pc=0x0c093d04u; return 0; }
r[4]=r[10];
goto P_0c093d06;
P_0c093d06: /* original 60a3, guest PC 0x0c093d06 */
if(!s->budget--) { s->failed_pc=0x0c093d06u; return 0; }
r[0]=r[10];
goto P_0c093d08;
P_0c093d08: /* original 880f, guest PC 0x0c093d08 */
if(!s->budget--) { s->failed_pc=0x0c093d08u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c093d0a;
P_0c093d0a: /* original 8b01, guest PC 0x0c093d0a */
if(!s->budget--) { s->failed_pc=0x0c093d0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093d10; }
goto P_0c093d0c;
P_0c093d0c: /* original a04e, guest PC 0x0c093d0c */
if(!s->budget--) { s->failed_pc=0x0c093d0cu; return 0; }
r[4]=0x0000001bu;
goto P_0c093dac;
P_0c093d0e: /* original e41b, guest PC 0x0c093d0e */
if(!s->budget--) { s->failed_pc=0x0c093d0eu; return 0; }
r[4]=0x0000001bu;
goto P_0c093d10;
P_0c093d10: /* original 880b, guest PC 0x0c093d10 */
if(!s->budget--) { s->failed_pc=0x0c093d10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c093d12;
P_0c093d12: /* original 8b01, guest PC 0x0c093d12 */
if(!s->budget--) { s->failed_pc=0x0c093d12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093d18; }
goto P_0c093d14;
P_0c093d14: /* original a04a, guest PC 0x0c093d14 */
if(!s->budget--) { s->failed_pc=0x0c093d14u; return 0; }
r[4]=0x0000001cu;
goto P_0c093dac;
P_0c093d16: /* original e41c, guest PC 0x0c093d16 */
if(!s->budget--) { s->failed_pc=0x0c093d16u; return 0; }
r[4]=0x0000001cu;
goto P_0c093d18;
P_0c093d18: /* original 60a3, guest PC 0x0c093d18 */
if(!s->budget--) { s->failed_pc=0x0c093d18u; return 0; }
r[0]=r[10];
goto P_0c093d1a;
P_0c093d1a: /* original 8818, guest PC 0x0c093d1a */
if(!s->budget--) { s->failed_pc=0x0c093d1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c093d1c;
P_0c093d1c: /* original 8b46, guest PC 0x0c093d1c */
if(!s->budget--) { s->failed_pc=0x0c093d1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093dac; }
goto P_0c093d1e;
P_0c093d1e: /* original a045, guest PC 0x0c093d1e */
if(!s->budget--) { s->failed_pc=0x0c093d1eu; return 0; }
r[4]=0x0000001du;
goto P_0c093dac;
P_0c093d20: /* original e41d, guest PC 0x0c093d20 */
if(!s->budget--) { s->failed_pc=0x0c093d20u; return 0; }
r[4]=0x0000001du;
goto P_0c093d22;
P_0c093d22: /* original 60a3, guest PC 0x0c093d22 */
if(!s->budget--) { s->failed_pc=0x0c093d22u; return 0; }
r[0]=r[10];
goto P_0c093d24;
P_0c093d24: /* original d50e, guest PC 0x0c093d24 */
if(!s->budget--) { s->failed_pc=0x0c093d24u; return 0; }
r[5]=read(ram,0x0c093d60u,4);
goto P_0c093d26;
P_0c093d26: /* original 880c, guest PC 0x0c093d26 */
if(!s->budget--) { s->failed_pc=0x0c093d26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c093d28;
P_0c093d28: /* original 8b05, guest PC 0x0c093d28 */
if(!s->budget--) { s->failed_pc=0x0c093d28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093d36; }
goto P_0c093d2a;
P_0c093d2a: /* original 9010, guest PC 0x0c093d2a */
if(!s->budget--) { s->failed_pc=0x0c093d2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093d4eu,2);
goto P_0c093d2c;
P_0c093d2c: /* original 035c, guest PC 0x0c093d2c */
if(!s->budget--) { s->failed_pc=0x0c093d2cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c093d2e;
P_0c093d2e: /* original 2338, guest PC 0x0c093d2e */
if(!s->budget--) { s->failed_pc=0x0c093d2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c093d30;
P_0c093d30: /* original 893c, guest PC 0x0c093d30 */
if(!s->budget--) { s->failed_pc=0x0c093d30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093dac; }
goto P_0c093d32;
P_0c093d32: /* original a03b, guest PC 0x0c093d32 */
if(!s->budget--) { s->failed_pc=0x0c093d32u; return 0; }
r[4]=0x0000001au;
goto P_0c093dac;
P_0c093d34: /* original e41a, guest PC 0x0c093d34 */
if(!s->budget--) { s->failed_pc=0x0c093d34u; return 0; }
r[4]=0x0000001au;
goto P_0c093d36;
P_0c093d36: /* original 880f, guest PC 0x0c093d36 */
if(!s->budget--) { s->failed_pc=0x0c093d36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c093d38;
P_0c093d38: /* original 8b28, guest PC 0x0c093d38 */
if(!s->budget--) { s->failed_pc=0x0c093d38u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093d8c; }
goto P_0c093d3a;
P_0c093d3a: /* original 8494, guest PC 0x0c093d3a */
if(!s->budget--) { s->failed_pc=0x0c093d3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+4,1);
goto P_0c093d3c;
P_0c093d3c: /* original d409, guest PC 0x0c093d3c */
if(!s->budget--) { s->failed_pc=0x0c093d3cu; return 0; }
r[4]=read(ram,0x0c093d64u,4);
goto P_0c093d3e;
P_0c093d3e: /* original 2008, guest PC 0x0c093d3e */
if(!s->budget--) { s->failed_pc=0x0c093d3eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c093d40;
P_0c093d40: /* original 8f12, guest PC 0x0c093d40 */
if(!s->budget--) { s->failed_pc=0x0c093d40u; return 0; }
cond=r[17]&1u;
r[0]=0x00000060u;
if(!cond) { goto P_0c093d68; }
goto P_0c093d44;
P_0c093d42: /* original e060, guest PC 0x0c093d42 */
if(!s->budget--) { s->failed_pc=0x0c093d42u; return 0; }
r[0]=0x00000060u;
goto P_0c093d44;
P_0c093d44: /* original a011, guest PC 0x0c093d44 */
if(!s->budget--) { s->failed_pc=0x0c093d44u; return 0; }
r[5]=read(ram,r[4]+20,4);
goto P_0c093d6a;
P_0c093d46: /* original 5545, guest PC 0x0c093d46 */
if(!s->budget--) { s->failed_pc=0x0c093d46u; return 0; }
r[5]=read(ram,r[4]+20,4);
if(!vf3_matrix_family(0x0c093d48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093d48u; return 0; } return 1;
P_0c093d68: /* original 5544, guest PC 0x0c093d68 */
if(!s->budget--) { s->failed_pc=0x0c093d68u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c093d6a;
P_0c093d6a: /* original 045c, guest PC 0x0c093d6a */
if(!s->budget--) { s->failed_pc=0x0c093d6au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c093d6c;
P_0c093d6c: /* original d031, guest PC 0x0c093d6c */
if(!s->budget--) { s->failed_pc=0x0c093d6cu; return 0; }
r[0]=read(ram,0x0c093e34u,4);
goto P_0c093d6e;
P_0c093d6e: /* original 644c, guest PC 0x0c093d6e */
if(!s->budget--) { s->failed_pc=0x0c093d6eu; return 0; }
r[4]=r[4]&255u;
goto P_0c093d70;
P_0c093d70: /* original d731, guest PC 0x0c093d70 */
if(!s->budget--) { s->failed_pc=0x0c093d70u; return 0; }
r[7]=read(ram,0x0c093e38u,4);
goto P_0c093d72;
P_0c093d72: /* original 044c, guest PC 0x0c093d72 */
if(!s->budget--) { s->failed_pc=0x0c093d72u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c093d74;
P_0c093d74: /* original 905c, guest PC 0x0c093d74 */
if(!s->budget--) { s->failed_pc=0x0c093d74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093e30u,2);
goto P_0c093d76;
P_0c093d76: /* original 037e, guest PC 0x0c093d76 */
if(!s->budget--) { s->failed_pc=0x0c093d76u; return 0; }
r[3]=read(ram,r[7]+r[0],4);
goto P_0c093d78;
P_0c093d78: /* original 2338, guest PC 0x0c093d78 */
if(!s->budget--) { s->failed_pc=0x0c093d78u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c093d7a;
P_0c093d7a: /* original 8d17, guest PC 0x0c093d7a */
if(!s->budget--) { s->failed_pc=0x0c093d7au; return 0; }
cond=r[17]&1u;
r[4]=r[4]&255u;
if(cond) { goto P_0c093dac; }
goto P_0c093d7e;
P_0c093d7c: /* original 644c, guest PC 0x0c093d7c */
if(!s->budget--) { s->failed_pc=0x0c093d7cu; return 0; }
r[4]=r[4]&255u;
goto P_0c093d7e;
P_0c093d7e: /* original e060, guest PC 0x0c093d7e */
if(!s->budget--) { s->failed_pc=0x0c093d7eu; return 0; }
r[0]=0x00000060u;
goto P_0c093d80;
P_0c093d80: /* original 045c, guest PC 0x0c093d80 */
if(!s->budget--) { s->failed_pc=0x0c093d80u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c093d82;
P_0c093d82: /* original d02e, guest PC 0x0c093d82 */
if(!s->budget--) { s->failed_pc=0x0c093d82u; return 0; }
r[0]=read(ram,0x0c093e3cu,4);
goto P_0c093d84;
P_0c093d84: /* original 644c, guest PC 0x0c093d84 */
if(!s->budget--) { s->failed_pc=0x0c093d84u; return 0; }
r[4]=r[4]&255u;
goto P_0c093d86;
P_0c093d86: /* original 044c, guest PC 0x0c093d86 */
if(!s->budget--) { s->failed_pc=0x0c093d86u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c093d88;
P_0c093d88: /* original a010, guest PC 0x0c093d88 */
if(!s->budget--) { s->failed_pc=0x0c093d88u; return 0; }
r[4]=r[4]&255u;
goto P_0c093dac;
P_0c093d8a: /* original 644c, guest PC 0x0c093d8a */
if(!s->budget--) { s->failed_pc=0x0c093d8au; return 0; }
r[4]=r[4]&255u;
goto P_0c093d8c;
P_0c093d8c: /* original 60a3, guest PC 0x0c093d8c */
if(!s->budget--) { s->failed_pc=0x0c093d8cu; return 0; }
r[0]=r[10];
goto P_0c093d8e;
P_0c093d8e: /* original 880b, guest PC 0x0c093d8e */
if(!s->budget--) { s->failed_pc=0x0c093d8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c093d90;
P_0c093d90: /* original 8b05, guest PC 0x0c093d90 */
if(!s->budget--) { s->failed_pc=0x0c093d90u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093d9e; }
goto P_0c093d92;
P_0c093d92: /* original 904e, guest PC 0x0c093d92 */
if(!s->budget--) { s->failed_pc=0x0c093d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093e32u,2);
goto P_0c093d94;
P_0c093d94: /* original 035c, guest PC 0x0c093d94 */
if(!s->budget--) { s->failed_pc=0x0c093d94u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c093d96;
P_0c093d96: /* original 2338, guest PC 0x0c093d96 */
if(!s->budget--) { s->failed_pc=0x0c093d96u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c093d98;
P_0c093d98: /* original 8908, guest PC 0x0c093d98 */
if(!s->budget--) { s->failed_pc=0x0c093d98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093dac; }
goto P_0c093d9a;
P_0c093d9a: /* original a007, guest PC 0x0c093d9a */
if(!s->budget--) { s->failed_pc=0x0c093d9au; return 0; }
r[4]=0x0000001eu;
goto P_0c093dac;
P_0c093d9c: /* original e41e, guest PC 0x0c093d9c */
if(!s->budget--) { s->failed_pc=0x0c093d9cu; return 0; }
r[4]=0x0000001eu;
goto P_0c093d9e;
P_0c093d9e: /* original 8818, guest PC 0x0c093d9e */
if(!s->budget--) { s->failed_pc=0x0c093d9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c093da0;
P_0c093da0: /* original 8b04, guest PC 0x0c093da0 */
if(!s->budget--) { s->failed_pc=0x0c093da0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093dac; }
goto P_0c093da2;
P_0c093da2: /* original 9046, guest PC 0x0c093da2 */
if(!s->budget--) { s->failed_pc=0x0c093da2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093e32u,2);
goto P_0c093da4;
P_0c093da4: /* original 035c, guest PC 0x0c093da4 */
if(!s->budget--) { s->failed_pc=0x0c093da4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c093da6;
P_0c093da6: /* original 2338, guest PC 0x0c093da6 */
if(!s->budget--) { s->failed_pc=0x0c093da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c093da8;
P_0c093da8: /* original 8900, guest PC 0x0c093da8 */
if(!s->budget--) { s->failed_pc=0x0c093da8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093dac; }
goto P_0c093daa;
P_0c093daa: /* original e41f, guest PC 0x0c093daa */
if(!s->budget--) { s->failed_pc=0x0c093daau; return 0; }
r[4]=0x0000001fu;
goto P_0c093dac;
P_0c093dac: /* original 6543, guest PC 0x0c093dac */
if(!s->budget--) { s->failed_pc=0x0c093dacu; return 0; }
r[5]=r[4];
goto P_0c093dae;
P_0c093dae: /* original d324, guest PC 0x0c093dae */
if(!s->budget--) { s->failed_pc=0x0c093daeu; return 0; }
r[3]=read(ram,0x0c093e40u,4);
goto P_0c093db0;
P_0c093db0: /* original 4508, guest PC 0x0c093db0 */
if(!s->budget--) { s->failed_pc=0x0c093db0u; return 0; }
r[5]<<=2;
goto P_0c093db2;
P_0c093db2: /* original 4500, guest PC 0x0c093db2 */
if(!s->budget--) { s->failed_pc=0x0c093db2u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c093db4;
P_0c093db4: /* original 353c, guest PC 0x0c093db4 */
if(!s->budget--) { s->failed_pc=0x0c093db4u; return 0; }
r[5]+=r[3];
goto P_0c093db6;
P_0c093db6: /* original 6251, guest PC 0x0c093db6 */
if(!s->budget--) { s->failed_pc=0x0c093db6u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c093db8;
P_0c093db8: /* original 622d, guest PC 0x0c093db8 */
if(!s->budget--) { s->failed_pc=0x0c093db8u; return 0; }
r[2]=r[2]&65535u;
goto P_0c093dba;
P_0c093dba: /* original 1f21, guest PC 0x0c093dba */
if(!s->budget--) { s->failed_pc=0x0c093dbau; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c093dbc;
P_0c093dbc: /* original 8551, guest PC 0x0c093dbc */
if(!s->budget--) { s->failed_pc=0x0c093dbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c093dbe;
P_0c093dbe: /* original 5d51, guest PC 0x0c093dbe */
if(!s->budget--) { s->failed_pc=0x0c093dbeu; return 0; }
r[13]=read(ram,r[5]+4,4);
goto P_0c093dc0;
P_0c093dc0: /* original 640d, guest PC 0x0c093dc0 */
if(!s->budget--) { s->failed_pc=0x0c093dc0u; return 0; }
r[4]=r[0]&65535u;
goto P_0c093dc2;
P_0c093dc2: /* original 85f2, guest PC 0x0c093dc2 */
if(!s->budget--) { s->failed_pc=0x0c093dc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c093dc4;
P_0c093dc4: /* original 8162, guest PC 0x0c093dc4 */
if(!s->budget--) { s->failed_pc=0x0c093dc4u; return 0; }
write(ram,r[6]+4,r[0],2);
goto P_0c093dc6;
P_0c093dc6: /* original 6043, guest PC 0x0c093dc6 */
if(!s->budget--) { s->failed_pc=0x0c093dc6u; return 0; }
r[0]=r[4];
goto P_0c093dc8;
P_0c093dc8: /* original 8163, guest PC 0x0c093dc8 */
if(!s->budget--) { s->failed_pc=0x0c093dc8u; return 0; }
write(ram,r[6]+6,r[0],2);
goto P_0c093dca;
P_0c093dca: /* original 52f1, guest PC 0x0c093dca */
if(!s->budget--) { s->failed_pc=0x0c093dcau; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c093dcc;
P_0c093dcc: /* original 2228, guest PC 0x0c093dcc */
if(!s->budget--) { s->failed_pc=0x0c093dccu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c093dce;
P_0c093dce: /* original 8b02, guest PC 0x0c093dce */
if(!s->budget--) { s->failed_pc=0x0c093dceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093dd6; }
goto P_0c093dd0;
P_0c093dd0: /* original d21c, guest PC 0x0c093dd0 */
if(!s->budget--) { s->failed_pc=0x0c093dd0u; return 0; }
r[2]=read(ram,0x0c093e44u,4);
goto P_0c093dd2;
P_0c093dd2: /* original 422b, guest PC 0x0c093dd2 */
if(!s->budget--) { s->failed_pc=0x0c093dd2u; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0940a0u: goto P_0c0940a0;
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
P_0c093dd4: /* original 0009, guest PC 0x0c093dd4 */
if(!s->budget--) { s->failed_pc=0x0c093dd4u; return 0; }
goto P_0c093dd6;
P_0c093dd6: /* original e300, guest PC 0x0c093dd6 */
if(!s->budget--) { s->failed_pc=0x0c093dd6u; return 0; }
r[3]=0x00000000u;
goto P_0c093dd8;
P_0c093dd8: /* original 1f33, guest PC 0x0c093dd8 */
if(!s->budget--) { s->failed_pc=0x0c093dd8u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c093dda;
P_0c093dda: /* original 62d6, guest PC 0x0c093dda */
if(!s->budget--) { s->failed_pc=0x0c093ddau; return 0; }
tmp=read(ram,r[13],4);
r[13]+=4;
r[2]=tmp;
goto P_0c093ddc;
P_0c093ddc: /* original 6cf3, guest PC 0x0c093ddc */
if(!s->budget--) { s->failed_pc=0x0c093ddcu; return 0; }
r[12]=r[15];
goto P_0c093dde;
P_0c093dde: /* original 7c34, guest PC 0x0c093dde */
if(!s->budget--) { s->failed_pc=0x0c093ddeu; return 0; }
r[12]+=0x00000034u;
goto P_0c093de0;
P_0c093de0: /* original 6bf3, guest PC 0x0c093de0 */
if(!s->budget--) { s->failed_pc=0x0c093de0u; return 0; }
r[11]=r[15];
goto P_0c093de2;
P_0c093de2: /* original e004, guest PC 0x0c093de2 */
if(!s->budget--) { s->failed_pc=0x0c093de2u; return 0; }
r[0]=0x00000004u;
goto P_0c093de4;
P_0c093de4: /* original 1f26, guest PC 0x0c093de4 */
if(!s->budget--) { s->failed_pc=0x0c093de4u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c093de6;
P_0c093de6: /* original f3d9, guest PC 0x0c093de6 */
if(!s->budget--) { s->failed_pc=0x0c093de6u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093de8;
P_0c093de8: /* original 7b28, guest PC 0x0c093de8 */
if(!s->budget--) { s->failed_pc=0x0c093de8u; return 0; }
r[11]+=0x00000028u;
goto P_0c093dea;
P_0c093dea: /* original fc3a, guest PC 0x0c093dea */
if(!s->budget--) { s->failed_pc=0x0c093deau; return 0; }
vf3_matrix_store(s,ram,3,r[12]);
goto P_0c093dec;
P_0c093dec: /* original f2d9, guest PC 0x0c093dec */
if(!s->budget--) { s->failed_pc=0x0c093decu; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093dee;
P_0c093dee: /* original fc27, guest PC 0x0c093dee */
if(!s->budget--) { s->failed_pc=0x0c093deeu; return 0; }
vf3_matrix_store(s,ram,2,r[12]+r[0]);
goto P_0c093df0;
P_0c093df0: /* original e008, guest PC 0x0c093df0 */
if(!s->budget--) { s->failed_pc=0x0c093df0u; return 0; }
r[0]=0x00000008u;
goto P_0c093df2;
P_0c093df2: /* original f3d9, guest PC 0x0c093df2 */
if(!s->budget--) { s->failed_pc=0x0c093df2u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093df4;
P_0c093df4: /* original fc37, guest PC 0x0c093df4 */
if(!s->budget--) { s->failed_pc=0x0c093df4u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c093df6;
P_0c093df6: /* original e004, guest PC 0x0c093df6 */
if(!s->budget--) { s->failed_pc=0x0c093df6u; return 0; }
r[0]=0x00000004u;
goto P_0c093df8;
P_0c093df8: /* original f3d9, guest PC 0x0c093df8 */
if(!s->budget--) { s->failed_pc=0x0c093df8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093dfa;
P_0c093dfa: /* original fb3a, guest PC 0x0c093dfa */
if(!s->budget--) { s->failed_pc=0x0c093dfau; return 0; }
vf3_matrix_store(s,ram,3,r[11]);
goto P_0c093dfc;
P_0c093dfc: /* original f2d9, guest PC 0x0c093dfc */
if(!s->budget--) { s->failed_pc=0x0c093dfcu; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093dfe;
P_0c093dfe: /* original fb27, guest PC 0x0c093dfe */
if(!s->budget--) { s->failed_pc=0x0c093dfeu; return 0; }
vf3_matrix_store(s,ram,2,r[11]+r[0]);
goto P_0c093e00;
P_0c093e00: /* original e008, guest PC 0x0c093e00 */
if(!s->budget--) { s->failed_pc=0x0c093e00u; return 0; }
r[0]=0x00000008u;
goto P_0c093e02;
P_0c093e02: /* original f3d9, guest PC 0x0c093e02 */
if(!s->budget--) { s->failed_pc=0x0c093e02u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093e04;
P_0c093e04: /* original fb37, guest PC 0x0c093e04 */
if(!s->budget--) { s->failed_pc=0x0c093e04u; return 0; }
vf3_matrix_store(s,ram,3,r[11]+r[0]);
goto P_0c093e06;
P_0c093e06: /* original e01c, guest PC 0x0c093e06 */
if(!s->budget--) { s->failed_pc=0x0c093e06u; return 0; }
r[0]=0x0000001cu;
goto P_0c093e08;
P_0c093e08: /* original f2b8, guest PC 0x0c093e08 */
if(!s->budget--) { s->failed_pc=0x0c093e08u; return 0; }
vf3_matrix_load(s,ram,2,r[11]);
goto P_0c093e0a;
P_0c093e0a: /* original f3c8, guest PC 0x0c093e0a */
if(!s->budget--) { s->failed_pc=0x0c093e0au; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c093e0c;
P_0c093e0c: /* original f231, guest PC 0x0c093e0c */
if(!s->budget--) { s->failed_pc=0x0c093e0cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c093e0e;
P_0c093e0e: /* original ff27, guest PC 0x0c093e0e */
if(!s->budget--) { s->failed_pc=0x0c093e0eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c093e10;
P_0c093e10: /* original e004, guest PC 0x0c093e10 */
if(!s->budget--) { s->failed_pc=0x0c093e10u; return 0; }
r[0]=0x00000004u;
goto P_0c093e12;
P_0c093e12: /* original f2b6, guest PC 0x0c093e12 */
if(!s->budget--) { s->failed_pc=0x0c093e12u; return 0; }
vf3_matrix_load(s,ram,2,r[11]+r[0]);
goto P_0c093e14;
P_0c093e14: /* original f3c6, guest PC 0x0c093e14 */
if(!s->budget--) { s->failed_pc=0x0c093e14u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c093e16;
P_0c093e16: /* original e020, guest PC 0x0c093e16 */
if(!s->budget--) { s->failed_pc=0x0c093e16u; return 0; }
r[0]=0x00000020u;
goto P_0c093e18;
P_0c093e18: /* original f231, guest PC 0x0c093e18 */
if(!s->budget--) { s->failed_pc=0x0c093e18u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c093e1a;
P_0c093e1a: /* original ff27, guest PC 0x0c093e1a */
if(!s->budget--) { s->failed_pc=0x0c093e1au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c093e1c;
P_0c093e1c: /* original e008, guest PC 0x0c093e1c */
if(!s->budget--) { s->failed_pc=0x0c093e1cu; return 0; }
r[0]=0x00000008u;
goto P_0c093e1e;
P_0c093e1e: /* original f2b6, guest PC 0x0c093e1e */
if(!s->budget--) { s->failed_pc=0x0c093e1eu; return 0; }
vf3_matrix_load(s,ram,2,r[11]+r[0]);
goto P_0c093e20;
P_0c093e20: /* original 64f3, guest PC 0x0c093e20 */
if(!s->budget--) { s->failed_pc=0x0c093e20u; return 0; }
r[4]=r[15];
goto P_0c093e22;
P_0c093e22: /* original f3c6, guest PC 0x0c093e22 */
if(!s->budget--) { s->failed_pc=0x0c093e22u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c093e24;
P_0c093e24: /* original e024, guest PC 0x0c093e24 */
if(!s->budget--) { s->failed_pc=0x0c093e24u; return 0; }
r[0]=0x00000024u;
goto P_0c093e26;
P_0c093e26: /* original 741c, guest PC 0x0c093e26 */
if(!s->budget--) { s->failed_pc=0x0c093e26u; return 0; }
r[4]+=0x0000001cu;
goto P_0c093e28;
P_0c093e28: /* original f231, guest PC 0x0c093e28 */
if(!s->budget--) { s->failed_pc=0x0c093e28u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c093e2a;
P_0c093e2a: /* original ff27, guest PC 0x0c093e2a */
if(!s->budget--) { s->failed_pc=0x0c093e2au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c093e2c;
P_0c093e2c: /* original a00c, guest PC 0x0c093e2c */
if(!s->budget--) { s->failed_pc=0x0c093e2cu; return 0; }
goto P_0c093e48;
P_0c093e2e: /* original 0009, guest PC 0x0c093e2e */
if(!s->budget--) { s->failed_pc=0x0c093e2eu; return 0; }
if(!vf3_matrix_family(0x0c093e30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093e30u; return 0; } return 1;
P_0c093e48: /* original f049, guest PC 0x0c093e48 */
if(!s->budget--) { s->failed_pc=0x0c093e48u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093e4a;
P_0c093e4a: /* original f149, guest PC 0x0c093e4a */
if(!s->budget--) { s->failed_pc=0x0c093e4au; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093e4c;
P_0c093e4c: /* original f249, guest PC 0x0c093e4c */
if(!s->budget--) { s->failed_pc=0x0c093e4cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c093e4e;
P_0c093e4e: /* original f38d, guest PC 0x0c093e4e */
if(!s->budget--) { s->failed_pc=0x0c093e4eu; return 0; }
fr[3]=0;
goto P_0c093e50;
P_0c093e50: /* original f0ed, guest PC 0x0c093e50 */
if(!s->budget--) { s->failed_pc=0x0c093e50u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c093e52;
P_0c093e52: /* original f03c, guest PC 0x0c093e52 */
if(!s->budget--) { s->failed_pc=0x0c093e52u; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c093e54;
P_0c093e54: /* original f06d, guest PC 0x0c093e54 */
if(!s->budget--) { s->failed_pc=0x0c093e54u; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c093e56;
P_0c093e56: /* original 0009, guest PC 0x0c093e56 */
if(!s->budget--) { s->failed_pc=0x0c093e56u; return 0; }
goto P_0c093e58;
P_0c093e58: /* original f38d, guest PC 0x0c093e58 */
if(!s->budget--) { s->failed_pc=0x0c093e58u; return 0; }
fr[3]=0;
goto P_0c093e5a;
P_0c093e5a: /* original f40c, guest PC 0x0c093e5a */
if(!s->budget--) { s->failed_pc=0x0c093e5au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c093e5c;
P_0c093e5c: /* original f434, guest PC 0x0c093e5c */
if(!s->budget--) { s->failed_pc=0x0c093e5cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c093e5e;
P_0c093e5e: /* original 8913, guest PC 0x0c093e5e */
if(!s->budget--) { s->failed_pc=0x0c093e5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093e88; }
goto P_0c093e60;
P_0c093e60: /* original e01c, guest PC 0x0c093e60 */
if(!s->budget--) { s->failed_pc=0x0c093e60u; return 0; }
r[0]=0x0000001cu;
goto P_0c093e62;
P_0c093e62: /* original f1c8, guest PC 0x0c093e62 */
if(!s->budget--) { s->failed_pc=0x0c093e62u; return 0; }
vf3_matrix_load(s,ram,1,r[12]);
goto P_0c093e64;
P_0c093e64: /* original f2f6, guest PC 0x0c093e64 */
if(!s->budget--) { s->failed_pc=0x0c093e64u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c093e66;
P_0c093e66: /* original e020, guest PC 0x0c093e66 */
if(!s->budget--) { s->failed_pc=0x0c093e66u; return 0; }
r[0]=0x00000020u;
goto P_0c093e68;
P_0c093e68: /* original f243, guest PC 0x0c093e68 */
if(!s->budget--) { s->failed_pc=0x0c093e68u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c093e6a;
P_0c093e6a: /* original f210, guest PC 0x0c093e6a */
if(!s->budget--) { s->failed_pc=0x0c093e6au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c093e6c;
P_0c093e6c: /* original fb2a, guest PC 0x0c093e6c */
if(!s->budget--) { s->failed_pc=0x0c093e6cu; return 0; }
vf3_matrix_store(s,ram,2,r[11]);
goto P_0c093e6e;
P_0c093e6e: /* original f2f6, guest PC 0x0c093e6e */
if(!s->budget--) { s->failed_pc=0x0c093e6eu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c093e70;
P_0c093e70: /* original e004, guest PC 0x0c093e70 */
if(!s->budget--) { s->failed_pc=0x0c093e70u; return 0; }
r[0]=0x00000004u;
goto P_0c093e72;
P_0c093e72: /* original f1c6, guest PC 0x0c093e72 */
if(!s->budget--) { s->failed_pc=0x0c093e72u; return 0; }
vf3_matrix_load(s,ram,1,r[12]+r[0]);
goto P_0c093e74;
P_0c093e74: /* original f243, guest PC 0x0c093e74 */
if(!s->budget--) { s->failed_pc=0x0c093e74u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c093e76;
P_0c093e76: /* original f210, guest PC 0x0c093e76 */
if(!s->budget--) { s->failed_pc=0x0c093e76u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c093e78;
P_0c093e78: /* original fb27, guest PC 0x0c093e78 */
if(!s->budget--) { s->failed_pc=0x0c093e78u; return 0; }
vf3_matrix_store(s,ram,2,r[11]+r[0]);
goto P_0c093e7a;
P_0c093e7a: /* original e024, guest PC 0x0c093e7a */
if(!s->budget--) { s->failed_pc=0x0c093e7au; return 0; }
r[0]=0x00000024u;
goto P_0c093e7c;
P_0c093e7c: /* original f2f6, guest PC 0x0c093e7c */
if(!s->budget--) { s->failed_pc=0x0c093e7cu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c093e7e;
P_0c093e7e: /* original e008, guest PC 0x0c093e7e */
if(!s->budget--) { s->failed_pc=0x0c093e7eu; return 0; }
r[0]=0x00000008u;
goto P_0c093e80;
P_0c093e80: /* original f1c6, guest PC 0x0c093e80 */
if(!s->budget--) { s->failed_pc=0x0c093e80u; return 0; }
vf3_matrix_load(s,ram,1,r[12]+r[0]);
goto P_0c093e82;
P_0c093e82: /* original f243, guest PC 0x0c093e82 */
if(!s->budget--) { s->failed_pc=0x0c093e82u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'/');
goto P_0c093e84;
P_0c093e84: /* original f210, guest PC 0x0c093e84 */
if(!s->budget--) { s->failed_pc=0x0c093e84u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[1],r[18],'+');
goto P_0c093e86;
P_0c093e86: /* original fb27, guest PC 0x0c093e86 */
if(!s->budget--) { s->failed_pc=0x0c093e86u; return 0; }
vf3_matrix_store(s,ram,2,r[11]+r[0]);
goto P_0c093e88;
P_0c093e88: /* original f4d9, guest PC 0x0c093e88 */
if(!s->budget--) { s->failed_pc=0x0c093e88u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c093e8a;
P_0c093e8a: /* original c747, guest PC 0x0c093e8a */
if(!s->budget--) { s->failed_pc=0x0c093e8au; return 0; }
r[0]=code_base|0x00093fa8u;
goto P_0c093e8c;
P_0c093e8c: /* original f608, guest PC 0x0c093e8c */
if(!s->budget--) { s->failed_pc=0x0c093e8cu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c093e8e;
P_0c093e8e: /* original 63d5, guest PC 0x0c093e8e */
if(!s->budget--) { s->failed_pc=0x0c093e8eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[3]=tmp;
goto P_0c093e90;
P_0c093e90: /* original f462, guest PC 0x0c093e90 */
if(!s->budget--) { s->failed_pc=0x0c093e90u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c093e92;
P_0c093e92: /* original 633d, guest PC 0x0c093e92 */
if(!s->budget--) { s->failed_pc=0x0c093e92u; return 0; }
r[3]=r[3]&65535u;
goto P_0c093e94;
P_0c093e94: /* original 1f32, guest PC 0x0c093e94 */
if(!s->budget--) { s->failed_pc=0x0c093e94u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c093e96;
P_0c093e96: /* original 67d4, guest PC 0x0c093e96 */
if(!s->budget--) { s->failed_pc=0x0c093e96u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[7]=tmp;
goto P_0c093e98;
P_0c093e98: /* original 62d4, guest PC 0x0c093e98 */
if(!s->budget--) { s->failed_pc=0x0c093e98u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[2]=tmp;
goto P_0c093e9a;
P_0c093e9a: /* original 622c, guest PC 0x0c093e9a */
if(!s->budget--) { s->failed_pc=0x0c093e9au; return 0; }
r[2]=r[2]&255u;
goto P_0c093e9c;
P_0c093e9c: /* original 1f25, guest PC 0x0c093e9c */
if(!s->budget--) { s->failed_pc=0x0c093e9cu; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c093e9e;
P_0c093e9e: /* original 64d5, guest PC 0x0c093e9e */
if(!s->budget--) { s->failed_pc=0x0c093e9eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[4]=tmp;
goto P_0c093ea0;
P_0c093ea0: /* original 917b, guest PC 0x0c093ea0 */
if(!s->budget--) { s->failed_pc=0x0c093ea0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093f9au,2);
goto P_0c093ea2;
P_0c093ea2: /* original 644d, guest PC 0x0c093ea2 */
if(!s->budget--) { s->failed_pc=0x0c093ea2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c093ea4;
P_0c093ea4: /* original 2148, guest PC 0x0c093ea4 */
if(!s->budget--) { s->failed_pc=0x0c093ea4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c093ea6;
P_0c093ea6: /* original 8d04, guest PC 0x0c093ea6 */
if(!s->budget--) { s->failed_pc=0x0c093ea6u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c093eb2; }
goto P_0c093eaa;
P_0c093ea8: /* original 677c, guest PC 0x0c093ea8 */
if(!s->budget--) { s->failed_pc=0x0c093ea8u; return 0; }
r[7]=r[7]&255u;
goto P_0c093eaa;
P_0c093eaa: /* original 62d5, guest PC 0x0c093eaa */
if(!s->budget--) { s->failed_pc=0x0c093eaau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[2]=tmp;
goto P_0c093eac;
P_0c093eac: /* original e02e, guest PC 0x0c093eac */
if(!s->budget--) { s->failed_pc=0x0c093eacu; return 0; }
r[0]=0x0000002eu;
goto P_0c093eae;
P_0c093eae: /* original 7d02, guest PC 0x0c093eae */
if(!s->budget--) { s->failed_pc=0x0c093eaeu; return 0; }
r[13]+=0x00000002u;
goto P_0c093eb0;
P_0c093eb0: /* original 0e25, guest PC 0x0c093eb0 */
if(!s->budget--) { s->failed_pc=0x0c093eb0u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c093eb2;
P_0c093eb2: /* original 9673, guest PC 0x0c093eb2 */
if(!s->budget--) { s->failed_pc=0x0c093eb2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093f9cu,2);
goto P_0c093eb4;
P_0c093eb4: /* original 6343, guest PC 0x0c093eb4 */
if(!s->budget--) { s->failed_pc=0x0c093eb4u; return 0; }
r[3]=r[4];
goto P_0c093eb6;
P_0c093eb6: /* original 2368, guest PC 0x0c093eb6 */
if(!s->budget--) { s->failed_pc=0x0c093eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c093eb8;
P_0c093eb8: /* original 8906, guest PC 0x0c093eb8 */
if(!s->budget--) { s->failed_pc=0x0c093eb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093ec8; }
goto P_0c093eba;
P_0c093eba: /* original 9371, guest PC 0x0c093eba */
if(!s->budget--) { s->failed_pc=0x0c093ebau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093fa0u,2);
goto P_0c093ebc;
P_0c093ebc: /* original 986f, guest PC 0x0c093ebc */
if(!s->budget--) { s->failed_pc=0x0c093ebcu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093f9eu,2);
goto P_0c093ebe;
P_0c093ebe: /* original 2348, guest PC 0x0c093ebe */
if(!s->budget--) { s->failed_pc=0x0c093ebeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c093ec0;
P_0c093ec0: /* original 8f01, guest PC 0x0c093ec0 */
if(!s->budget--) { s->failed_pc=0x0c093ec0u; return 0; }
cond=r[17]&1u;
r[0]=0x0000002eu;
if(!cond) { goto P_0c093ec6; }
goto P_0c093ec4;
P_0c093ec2: /* original e02e, guest PC 0x0c093ec2 */
if(!s->budget--) { s->failed_pc=0x0c093ec2u; return 0; }
r[0]=0x0000002eu;
goto P_0c093ec4;
P_0c093ec4: /* original d839, guest PC 0x0c093ec4 */
if(!s->budget--) { s->failed_pc=0x0c093ec4u; return 0; }
r[8]=read(ram,0x0c093facu,4);
goto P_0c093ec6;
P_0c093ec6: /* original 0e85, guest PC 0x0c093ec6 */
if(!s->budget--) { s->failed_pc=0x0c093ec6u; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c093ec8;
P_0c093ec8: /* original 65d4, guest PC 0x0c093ec8 */
if(!s->budget--) { s->failed_pc=0x0c093ec8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[5]=tmp;
goto P_0c093eca;
P_0c093eca: /* original e057, guest PC 0x0c093eca */
if(!s->budget--) { s->failed_pc=0x0c093ecau; return 0; }
r[0]=0x00000057u;
goto P_0c093ecc;
P_0c093ecc: /* original 63d4, guest PC 0x0c093ecc */
if(!s->budget--) { s->failed_pc=0x0c093eccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[3]=tmp;
goto P_0c093ece;
P_0c093ece: /* original 0e34, guest PC 0x0c093ece */
if(!s->budget--) { s->failed_pc=0x0c093eceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c093ed0;
P_0c093ed0: /* original 60f2, guest PC 0x0c093ed0 */
if(!s->budget--) { s->failed_pc=0x0c093ed0u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093ed2;
P_0c093ed2: /* original 8508, guest PC 0x0c093ed2 */
if(!s->budget--) { s->failed_pc=0x0c093ed2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[0]+16,2);
goto P_0c093ed4;
P_0c093ed4: /* original 600d, guest PC 0x0c093ed4 */
if(!s->budget--) { s->failed_pc=0x0c093ed4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c093ed6;
P_0c093ed6: /* original c801, guest PC 0x0c093ed6 */
if(!s->budget--) { s->failed_pc=0x0c093ed6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c093ed8;
P_0c093ed8: /* original 8f0d, guest PC 0x0c093ed8 */
if(!s->budget--) { s->failed_pc=0x0c093ed8u; return 0; }
cond=r[17]&1u;
r[5]=r[5]&255u;
if(!cond) { goto P_0c093ef6; }
goto P_0c093edc;
P_0c093eda: /* original 655c, guest PC 0x0c093eda */
if(!s->budget--) { s->failed_pc=0x0c093edau; return 0; }
r[5]=r[5]&255u;
goto P_0c093edc;
P_0c093edc: /* original e061, guest PC 0x0c093edc */
if(!s->budget--) { s->failed_pc=0x0c093edcu; return 0; }
r[0]=0x00000061u;
goto P_0c093ede;
P_0c093ede: /* original 009c, guest PC 0x0c093ede */
if(!s->budget--) { s->failed_pc=0x0c093edeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c093ee0;
P_0c093ee0: /* original 600c, guest PC 0x0c093ee0 */
if(!s->budget--) { s->failed_pc=0x0c093ee0u; return 0; }
r[0]=r[0]&255u;
goto P_0c093ee2;
P_0c093ee2: /* original 8802, guest PC 0x0c093ee2 */
if(!s->budget--) { s->failed_pc=0x0c093ee2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c093ee4;
P_0c093ee4: /* original 8b07, guest PC 0x0c093ee4 */
if(!s->budget--) { s->failed_pc=0x0c093ee4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c093ef6; }
goto P_0c093ee6;
P_0c093ee6: /* original e210, guest PC 0x0c093ee6 */
if(!s->budget--) { s->failed_pc=0x0c093ee6u; return 0; }
r[2]=0x00000010u;
goto P_0c093ee8;
P_0c093ee8: /* original 2248, guest PC 0x0c093ee8 */
if(!s->budget--) { s->failed_pc=0x0c093ee8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c093eea;
P_0c093eea: /* original 8904, guest PC 0x0c093eea */
if(!s->budget--) { s->failed_pc=0x0c093eeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093ef6; }
goto P_0c093eec;
P_0c093eec: /* original e1ef, guest PC 0x0c093eec */
if(!s->budget--) { s->failed_pc=0x0c093eecu; return 0; }
r[1]=0xffffffefu;
goto P_0c093eee;
P_0c093eee: /* original e304, guest PC 0x0c093eee */
if(!s->budget--) { s->failed_pc=0x0c093eeeu; return 0; }
r[3]=0x00000004u;
goto P_0c093ef0;
P_0c093ef0: /* original 2419, guest PC 0x0c093ef0 */
if(!s->budget--) { s->failed_pc=0x0c093ef0u; return 0; }
r[4]&=r[1];
goto P_0c093ef2;
P_0c093ef2: /* original e708, guest PC 0x0c093ef2 */
if(!s->budget--) { s->failed_pc=0x0c093ef2u; return 0; }
r[7]=0x00000008u;
goto P_0c093ef4;
P_0c093ef4: /* original 243b, guest PC 0x0c093ef4 */
if(!s->budget--) { s->failed_pc=0x0c093ef4u; return 0; }
r[4]|=r[3];
goto P_0c093ef6;
P_0c093ef6: /* original e204, guest PC 0x0c093ef6 */
if(!s->budget--) { s->failed_pc=0x0c093ef6u; return 0; }
r[2]=0x00000004u;
goto P_0c093ef8;
P_0c093ef8: /* original 2248, guest PC 0x0c093ef8 */
if(!s->budget--) { s->failed_pc=0x0c093ef8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c093efa;
P_0c093efa: /* original 891a, guest PC 0x0c093efa */
if(!s->budget--) { s->failed_pc=0x0c093efau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093f32; }
goto P_0c093efc;
P_0c093efc: /* original 6373, guest PC 0x0c093efc */
if(!s->budget--) { s->failed_pc=0x0c093efcu; return 0; }
r[3]=r[7];
goto P_0c093efe;
P_0c093efe: /* original 6173, guest PC 0x0c093efe */
if(!s->budget--) { s->failed_pc=0x0c093efeu; return 0; }
r[1]=r[7];
goto P_0c093f00;
P_0c093f00: /* original d02b, guest PC 0x0c093f00 */
if(!s->budget--) { s->failed_pc=0x0c093f00u; return 0; }
r[0]=read(ram,0x0c093fb0u,4);
goto P_0c093f02;
P_0c093f02: /* original 4308, guest PC 0x0c093f02 */
if(!s->budget--) { s->failed_pc=0x0c093f02u; return 0; }
r[3]<<=2;
goto P_0c093f04;
P_0c093f04: /* original 4100, guest PC 0x0c093f04 */
if(!s->budget--) { s->failed_pc=0x0c093f04u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c093f06;
P_0c093f06: /* original 313c, guest PC 0x0c093f06 */
if(!s->budget--) { s->failed_pc=0x0c093f06u; return 0; }
r[1]+=r[3];
goto P_0c093f08;
P_0c093f08: /* original 6373, guest PC 0x0c093f08 */
if(!s->budget--) { s->failed_pc=0x0c093f08u; return 0; }
r[3]=r[7];
goto P_0c093f0a;
P_0c093f0a: /* original 021d, guest PC 0x0c093f0a */
if(!s->budget--) { s->failed_pc=0x0c093f0au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[1]+r[0],2);
goto P_0c093f0c;
P_0c093f0c: /* original e02e, guest PC 0x0c093f0c */
if(!s->budget--) { s->failed_pc=0x0c093f0cu; return 0; }
r[0]=0x0000002eu;
goto P_0c093f0e;
P_0c093f0e: /* original 4300, guest PC 0x0c093f0e */
if(!s->budget--) { s->failed_pc=0x0c093f0eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c093f10;
P_0c093f10: /* original 0e25, guest PC 0x0c093f10 */
if(!s->budget--) { s->failed_pc=0x0c093f10u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c093f12;
P_0c093f12: /* original 6273, guest PC 0x0c093f12 */
if(!s->budget--) { s->failed_pc=0x0c093f12u; return 0; }
r[2]=r[7];
goto P_0c093f14;
P_0c093f14: /* original 332c, guest PC 0x0c093f14 */
if(!s->budget--) { s->failed_pc=0x0c093f14u; return 0; }
r[3]+=r[2];
goto P_0c093f16;
P_0c093f16: /* original 1f34, guest PC 0x0c093f16 */
if(!s->budget--) { s->failed_pc=0x0c093f16u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c093f18;
P_0c093f18: /* original 7301, guest PC 0x0c093f18 */
if(!s->budget--) { s->failed_pc=0x0c093f18u; return 0; }
r[3]+=0x00000001u;
goto P_0c093f1a;
P_0c093f1a: /* original d025, guest PC 0x0c093f1a */
if(!s->budget--) { s->failed_pc=0x0c093f1au; return 0; }
r[0]=read(ram,0x0c093fb0u,4);
goto P_0c093f1c;
P_0c093f1c: /* original 4300, guest PC 0x0c093f1c */
if(!s->budget--) { s->failed_pc=0x0c093f1cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c093f1e;
P_0c093f1e: /* original 033d, guest PC 0x0c093f1e */
if(!s->budget--) { s->failed_pc=0x0c093f1eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c093f20;
P_0c093f20: /* original e030, guest PC 0x0c093f20 */
if(!s->budget--) { s->failed_pc=0x0c093f20u; return 0; }
r[0]=0x00000030u;
goto P_0c093f22;
P_0c093f22: /* original 0e35, guest PC 0x0c093f22 */
if(!s->budget--) { s->failed_pc=0x0c093f22u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c093f24;
P_0c093f24: /* original 52f4, guest PC 0x0c093f24 */
if(!s->budget--) { s->failed_pc=0x0c093f24u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c093f26;
P_0c093f26: /* original d022, guest PC 0x0c093f26 */
if(!s->budget--) { s->failed_pc=0x0c093f26u; return 0; }
r[0]=read(ram,0x0c093fb0u,4);
goto P_0c093f28;
P_0c093f28: /* original 7202, guest PC 0x0c093f28 */
if(!s->budget--) { s->failed_pc=0x0c093f28u; return 0; }
r[2]+=0x00000002u;
goto P_0c093f2a;
P_0c093f2a: /* original 4200, guest PC 0x0c093f2a */
if(!s->budget--) { s->failed_pc=0x0c093f2au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c093f2c;
P_0c093f2c: /* original 032d, guest PC 0x0c093f2c */
if(!s->budget--) { s->failed_pc=0x0c093f2cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c093f2e;
P_0c093f2e: /* original e032, guest PC 0x0c093f2e */
if(!s->budget--) { s->failed_pc=0x0c093f2eu; return 0; }
r[0]=0x00000032u;
goto P_0c093f30;
P_0c093f30: /* original 0e35, guest PC 0x0c093f30 */
if(!s->budget--) { s->failed_pc=0x0c093f30u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c093f32;
P_0c093f32: /* original 60f2, guest PC 0x0c093f32 */
if(!s->budget--) { s->failed_pc=0x0c093f32u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c093f34;
P_0c093f34: /* original 8508, guest PC 0x0c093f34 */
if(!s->budget--) { s->failed_pc=0x0c093f34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[0]+16,2);
goto P_0c093f36;
P_0c093f36: /* original 600d, guest PC 0x0c093f36 */
if(!s->budget--) { s->failed_pc=0x0c093f36u; return 0; }
r[0]=r[0]&65535u;
goto P_0c093f38;
P_0c093f38: /* original c801, guest PC 0x0c093f38 */
if(!s->budget--) { s->failed_pc=0x0c093f38u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c093f3a;
P_0c093f3a: /* original 8909, guest PC 0x0c093f3a */
if(!s->budget--) { s->failed_pc=0x0c093f3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093f50; }
goto P_0c093f3c;
P_0c093f3c: /* original 9332, guest PC 0x0c093f3c */
if(!s->budget--) { s->failed_pc=0x0c093f3cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093fa4u,2);
goto P_0c093f3e;
P_0c093f3e: /* original 51f2, guest PC 0x0c093f3e */
if(!s->budget--) { s->failed_pc=0x0c093f3eu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c093f40;
P_0c093f40: /* original 339c, guest PC 0x0c093f40 */
if(!s->budget--) { s->failed_pc=0x0c093f40u; return 0; }
r[3]+=r[9];
goto P_0c093f42;
P_0c093f42: /* original 922e, guest PC 0x0c093f42 */
if(!s->budget--) { s->failed_pc=0x0c093f42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093fa2u,2);
goto P_0c093f44;
P_0c093f44: /* original 3398, guest PC 0x0c093f44 */
if(!s->budget--) { s->failed_pc=0x0c093f44u; return 0; }
r[3]-=r[9];
goto P_0c093f46;
P_0c093f46: /* original 3130, guest PC 0x0c093f46 */
if(!s->budget--) { s->failed_pc=0x0c093f46u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c093f48;
P_0c093f48: /* original 8d02, guest PC 0x0c093f48 */
if(!s->budget--) { s->failed_pc=0x0c093f48u; return 0; }
cond=r[17]&1u;
r[4]|=r[2];
if(cond) { goto P_0c093f50; }
goto P_0c093f4c;
P_0c093f4a: /* original 242b, guest PC 0x0c093f4a */
if(!s->budget--) { s->failed_pc=0x0c093f4au; return 0; }
r[4]|=r[2];
goto P_0c093f4c;
P_0c093f4c: /* original 932b, guest PC 0x0c093f4c */
if(!s->budget--) { s->failed_pc=0x0c093f4cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c093fa6u,2);
goto P_0c093f4e;
P_0c093f4e: /* original 243b, guest PC 0x0c093f4e */
if(!s->budget--) { s->failed_pc=0x0c093f4eu; return 0; }
r[4]|=r[3];
goto P_0c093f50;
P_0c093f50: /* original 52f3, guest PC 0x0c093f50 */
if(!s->budget--) { s->failed_pc=0x0c093f50u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c093f52;
P_0c093f52: /* original e056, guest PC 0x0c093f52 */
if(!s->budget--) { s->failed_pc=0x0c093f52u; return 0; }
r[0]=0x00000056u;
goto P_0c093f54;
P_0c093f54: /* original 0e24, guest PC 0x0c093f54 */
if(!s->budget--) { s->failed_pc=0x0c093f54u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c093f56;
P_0c093f56: /* original 60a3, guest PC 0x0c093f56 */
if(!s->budget--) { s->failed_pc=0x0c093f56u; return 0; }
r[0]=r[10];
goto P_0c093f58;
P_0c093f58: /* original 8802, guest PC 0x0c093f58 */
if(!s->budget--) { s->failed_pc=0x0c093f58u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c093f5a;
P_0c093f5a: /* original 8907, guest PC 0x0c093f5a */
if(!s->budget--) { s->failed_pc=0x0c093f5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c093f6c; }
goto P_0c093f5c;
P_0c093f5c: /* original 52f3, guest PC 0x0c093f5c */
if(!s->budget--) { s->failed_pc=0x0c093f5cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c093f5e;
P_0c093f5e: /* original e308, guest PC 0x0c093f5e */
if(!s->budget--) { s->failed_pc=0x0c093f5eu; return 0; }
r[3]=0x00000008u;
goto P_0c093f60;
P_0c093f60: /* original 7201, guest PC 0x0c093f60 */
if(!s->budget--) { s->failed_pc=0x0c093f60u; return 0; }
r[2]+=0x00000001u;
goto P_0c093f62;
P_0c093f62: /* original 3232, guest PC 0x0c093f62 */
if(!s->budget--) { s->failed_pc=0x0c093f62u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c093f64;
P_0c093f64: /* original 8f02, guest PC 0x0c093f64 */
if(!s->budget--) { s->failed_pc=0x0c093f64u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[2],4);
if(!cond) { goto P_0c093f6c; }
goto P_0c093f68;
P_0c093f66: /* original 1f23, guest PC 0x0c093f66 */
if(!s->budget--) { s->failed_pc=0x0c093f66u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c093f68;
P_0c093f68: /* original e000, guest PC 0x0c093f68 */
if(!s->budget--) { s->failed_pc=0x0c093f68u; return 0; }
r[0]=0x00000000u;
goto P_0c093f6a;
P_0c093f6a: /* original 1f03, guest PC 0x0c093f6a */
if(!s->budget--) { s->failed_pc=0x0c093f6au; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c093f6c;
P_0c093f6c: /* original 53f6, guest PC 0x0c093f6c */
if(!s->budget--) { s->failed_pc=0x0c093f6cu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c093f6e;
P_0c093f6e: /* original e02c, guest PC 0x0c093f6e */
if(!s->budget--) { s->failed_pc=0x0c093f6eu; return 0; }
r[0]=0x0000002cu;
goto P_0c093f70;
P_0c093f70: /* original 0e35, guest PC 0x0c093f70 */
if(!s->budget--) { s->failed_pc=0x0c093f70u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c093f72;
P_0c093f72: /* original e038, guest PC 0x0c093f72 */
if(!s->budget--) { s->failed_pc=0x0c093f72u; return 0; }
r[0]=0x00000038u;
goto P_0c093f74;
P_0c093f74: /* original f3c8, guest PC 0x0c093f74 */
if(!s->budget--) { s->failed_pc=0x0c093f74u; return 0; }
vf3_matrix_load(s,ram,3,r[12]);
goto P_0c093f76;
P_0c093f76: /* original fe37, guest PC 0x0c093f76 */
if(!s->budget--) { s->failed_pc=0x0c093f76u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093f78;
P_0c093f78: /* original e004, guest PC 0x0c093f78 */
if(!s->budget--) { s->failed_pc=0x0c093f78u; return 0; }
r[0]=0x00000004u;
goto P_0c093f7a;
P_0c093f7a: /* original f3c6, guest PC 0x0c093f7a */
if(!s->budget--) { s->failed_pc=0x0c093f7au; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c093f7c;
P_0c093f7c: /* original e03c, guest PC 0x0c093f7c */
if(!s->budget--) { s->failed_pc=0x0c093f7cu; return 0; }
r[0]=0x0000003cu;
goto P_0c093f7e;
P_0c093f7e: /* original fe37, guest PC 0x0c093f7e */
if(!s->budget--) { s->failed_pc=0x0c093f7eu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093f80;
P_0c093f80: /* original e008, guest PC 0x0c093f80 */
if(!s->budget--) { s->failed_pc=0x0c093f80u; return 0; }
r[0]=0x00000008u;
goto P_0c093f82;
P_0c093f82: /* original f3c6, guest PC 0x0c093f82 */
if(!s->budget--) { s->failed_pc=0x0c093f82u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c093f84;
P_0c093f84: /* original e040, guest PC 0x0c093f84 */
if(!s->budget--) { s->failed_pc=0x0c093f84u; return 0; }
r[0]=0x00000040u;
goto P_0c093f86;
P_0c093f86: /* original fe37, guest PC 0x0c093f86 */
if(!s->budget--) { s->failed_pc=0x0c093f86u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093f88;
P_0c093f88: /* original e044, guest PC 0x0c093f88 */
if(!s->budget--) { s->failed_pc=0x0c093f88u; return 0; }
r[0]=0x00000044u;
goto P_0c093f8a;
P_0c093f8a: /* original f3b8, guest PC 0x0c093f8a */
if(!s->budget--) { s->failed_pc=0x0c093f8au; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
goto P_0c093f8c;
P_0c093f8c: /* original fe37, guest PC 0x0c093f8c */
if(!s->budget--) { s->failed_pc=0x0c093f8cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093f8e;
P_0c093f8e: /* original e004, guest PC 0x0c093f8e */
if(!s->budget--) { s->failed_pc=0x0c093f8eu; return 0; }
r[0]=0x00000004u;
goto P_0c093f90;
P_0c093f90: /* original f3b6, guest PC 0x0c093f90 */
if(!s->budget--) { s->failed_pc=0x0c093f90u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c093f92;
P_0c093f92: /* original e048, guest PC 0x0c093f92 */
if(!s->budget--) { s->failed_pc=0x0c093f92u; return 0; }
r[0]=0x00000048u;
goto P_0c093f94;
P_0c093f94: /* original fe37, guest PC 0x0c093f94 */
if(!s->budget--) { s->failed_pc=0x0c093f94u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093f96;
P_0c093f96: /* original a00d, guest PC 0x0c093f96 */
if(!s->budget--) { s->failed_pc=0x0c093f96u; return 0; }
goto P_0c093fb4;
P_0c093f98: /* original 0009, guest PC 0x0c093f98 */
if(!s->budget--) { s->failed_pc=0x0c093f98u; return 0; }
if(!vf3_matrix_family(0x0c093f9au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c093f9au; return 0; } return 1;
P_0c093fb4: /* original e008, guest PC 0x0c093fb4 */
if(!s->budget--) { s->failed_pc=0x0c093fb4u; return 0; }
r[0]=0x00000008u;
goto P_0c093fb6;
P_0c093fb6: /* original f3b6, guest PC 0x0c093fb6 */
if(!s->budget--) { s->failed_pc=0x0c093fb6u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c093fb8;
P_0c093fb8: /* original e04c, guest PC 0x0c093fb8 */
if(!s->budget--) { s->failed_pc=0x0c093fb8u; return 0; }
r[0]=0x0000004cu;
goto P_0c093fba;
P_0c093fba: /* original fe37, guest PC 0x0c093fba */
if(!s->budget--) { s->failed_pc=0x0c093fbau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093fbc;
P_0c093fbc: /* original e024, guest PC 0x0c093fbc */
if(!s->budget--) { s->failed_pc=0x0c093fbcu; return 0; }
r[0]=0x00000024u;
goto P_0c093fbe;
P_0c093fbe: /* original fe47, guest PC 0x0c093fbe */
if(!s->budget--) { s->failed_pc=0x0c093fbeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c093fc0;
P_0c093fc0: /* original e028, guest PC 0x0c093fc0 */
if(!s->budget--) { s->failed_pc=0x0c093fc0u; return 0; }
r[0]=0x00000028u;
goto P_0c093fc2;
P_0c093fc2: /* original f79d, guest PC 0x0c093fc2 */
if(!s->budget--) { s->failed_pc=0x0c093fc2u; return 0; }
fr[7]=0x3f800000u;
goto P_0c093fc4;
P_0c093fc4: /* original f37c, guest PC 0x0c093fc4 */
if(!s->budget--) { s->failed_pc=0x0c093fc4u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c093fc6;
P_0c093fc6: /* original f343, guest PC 0x0c093fc6 */
if(!s->budget--) { s->failed_pc=0x0c093fc6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'/');
goto P_0c093fc8;
P_0c093fc8: /* original fe37, guest PC 0x0c093fc8 */
if(!s->budget--) { s->failed_pc=0x0c093fc8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c093fca;
P_0c093fca: /* original e037, guest PC 0x0c093fca */
if(!s->budget--) { s->failed_pc=0x0c093fcau; return 0; }
r[0]=0x00000037u;
goto P_0c093fcc;
P_0c093fcc: /* original 0e74, guest PC 0x0c093fcc */
if(!s->budget--) { s->failed_pc=0x0c093fccu; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c093fce;
P_0c093fce: /* original e054, guest PC 0x0c093fce */
if(!s->budget--) { s->failed_pc=0x0c093fceu; return 0; }
r[0]=0x00000054u;
goto P_0c093fd0;
P_0c093fd0: /* original 53f2, guest PC 0x0c093fd0 */
if(!s->budget--) { s->failed_pc=0x0c093fd0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c093fd2;
P_0c093fd2: /* original 0e35, guest PC 0x0c093fd2 */
if(!s->budget--) { s->failed_pc=0x0c093fd2u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c093fd4;
P_0c093fd4: /* original e036, guest PC 0x0c093fd4 */
if(!s->budget--) { s->failed_pc=0x0c093fd4u; return 0; }
r[0]=0x00000036u;
goto P_0c093fd6;
P_0c093fd6: /* original 52f5, guest PC 0x0c093fd6 */
if(!s->budget--) { s->failed_pc=0x0c093fd6u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c093fd8;
P_0c093fd8: /* original 0e24, guest PC 0x0c093fd8 */
if(!s->budget--) { s->failed_pc=0x0c093fd8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c093fda;
P_0c093fda: /* original e034, guest PC 0x0c093fda */
if(!s->budget--) { s->failed_pc=0x0c093fdau; return 0; }
r[0]=0x00000034u;
goto P_0c093fdc;
P_0c093fdc: /* original 0e45, guest PC 0x0c093fdc */
if(!s->budget--) { s->failed_pc=0x0c093fdcu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c093fde;
P_0c093fde: /* original e018, guest PC 0x0c093fde */
if(!s->budget--) { s->failed_pc=0x0c093fdeu; return 0; }
r[0]=0x00000018u;
goto P_0c093fe0;
P_0c093fe0: /* original f48d, guest PC 0x0c093fe0 */
if(!s->budget--) { s->failed_pc=0x0c093fe0u; return 0; }
fr[4]=0;
goto P_0c093fe2;
P_0c093fe2: /* original fe47, guest PC 0x0c093fe2 */
if(!s->budget--) { s->failed_pc=0x0c093fe2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c093fe4;
P_0c093fe4: /* original e01c, guest PC 0x0c093fe4 */
if(!s->budget--) { s->failed_pc=0x0c093fe4u; return 0; }
r[0]=0x0000001cu;
goto P_0c093fe6;
P_0c093fe6: /* original fe47, guest PC 0x0c093fe6 */
if(!s->budget--) { s->failed_pc=0x0c093fe6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c093fe8;
P_0c093fe8: /* original e020, guest PC 0x0c093fe8 */
if(!s->budget--) { s->failed_pc=0x0c093fe8u; return 0; }
r[0]=0x00000020u;
goto P_0c093fea;
P_0c093fea: /* original fe47, guest PC 0x0c093fea */
if(!s->budget--) { s->failed_pc=0x0c093feau; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c093fec;
P_0c093fec: /* original e004, guest PC 0x0c093fec */
if(!s->budget--) { s->failed_pc=0x0c093fecu; return 0; }
r[0]=0x00000004u;
goto P_0c093fee;
P_0c093fee: /* original fe4a, guest PC 0x0c093fee */
if(!s->budget--) { s->failed_pc=0x0c093feeu; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c093ff0;
P_0c093ff0: /* original fe47, guest PC 0x0c093ff0 */
if(!s->budget--) { s->failed_pc=0x0c093ff0u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c093ff2;
P_0c093ff2: /* original e008, guest PC 0x0c093ff2 */
if(!s->budget--) { s->failed_pc=0x0c093ff2u; return 0; }
r[0]=0x00000008u;
goto P_0c093ff4;
P_0c093ff4: /* original 2558, guest PC 0x0c093ff4 */
if(!s->budget--) { s->failed_pc=0x0c093ff4u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c093ff6;
P_0c093ff6: /* original fe47, guest PC 0x0c093ff6 */
if(!s->budget--) { s->failed_pc=0x0c093ff6u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c093ff8;
P_0c093ff8: /* original 8d4a, guest PC 0x0c093ff8 */
if(!s->budget--) { s->failed_pc=0x0c093ff8u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000058u;
if(cond) { goto P_0c094090; }
goto P_0c093ffc;
P_0c093ffa: /* original 7e58, guest PC 0x0c093ffa */
if(!s->budget--) { s->failed_pc=0x0c093ffau; return 0; }
r[14]+=0x00000058u;
goto P_0c093ffc;
P_0c093ffc: /* original 63d6, guest PC 0x0c093ffc */
if(!s->budget--) { s->failed_pc=0x0c093ffcu; return 0; }
tmp=read(ram,r[13],4);
r[13]+=4;
r[3]=tmp;
goto P_0c093ffe;
P_0c093ffe: /* original 1f34, guest PC 0x0c093ffe */
if(!s->budget--) { s->failed_pc=0x0c093ffeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c094000;
P_0c094000: /* original f5d9, guest PC 0x0c094000 */
if(!s->budget--) { s->failed_pc=0x0c094000u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c094002;
P_0c094002: /* original 64d5, guest PC 0x0c094002 */
if(!s->budget--) { s->failed_pc=0x0c094002u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[13]+=2;
r[4]=tmp;
goto P_0c094004;
P_0c094004: /* original 644d, guest PC 0x0c094004 */
if(!s->budget--) { s->failed_pc=0x0c094004u; return 0; }
r[4]=r[4]&65535u;
goto P_0c094006;
P_0c094006: /* original 6343, guest PC 0x0c094006 */
if(!s->budget--) { s->failed_pc=0x0c094006u; return 0; }
r[3]=r[4];
goto P_0c094008;
P_0c094008: /* original 2368, guest PC 0x0c094008 */
if(!s->budget--) { s->failed_pc=0x0c094008u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[6])==0)!=0);
goto P_0c09400a;
P_0c09400a: /* original 8d08, guest PC 0x0c09400a */
if(!s->budget--) { s->failed_pc=0x0c09400au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
if(cond) { goto P_0c09401e; }
goto P_0c09400e;
P_0c09400c: /* original f562, guest PC 0x0c09400c */
if(!s->budget--) { s->failed_pc=0x0c09400cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c09400e;
P_0c09400e: /* original 9153, guest PC 0x0c09400e */
if(!s->budget--) { s->failed_pc=0x0c09400eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0940b8u,2);
goto P_0c094010;
P_0c094010: /* original 2148, guest PC 0x0c094010 */
if(!s->budget--) { s->failed_pc=0x0c094010u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c094012;
P_0c094012: /* original 8d02, guest PC 0x0c094012 */
if(!s->budget--) { s->failed_pc=0x0c094012u; return 0; }
cond=r[17]&1u;
r[0]=0x0000002eu;
if(cond) { goto P_0c09401a; }
goto P_0c094016;
P_0c094014: /* original e02e, guest PC 0x0c094014 */
if(!s->budget--) { s->failed_pc=0x0c094014u; return 0; }
r[0]=0x0000002eu;
goto P_0c094016;
P_0c094016: /* original a001, guest PC 0x0c094016 */
if(!s->budget--) { s->failed_pc=0x0c094016u; return 0; }
r[8]+=r[6];
goto P_0c09401c;
P_0c094018: /* original 386c, guest PC 0x0c094018 */
if(!s->budget--) { s->failed_pc=0x0c094018u; return 0; }
r[8]+=r[6];
goto P_0c09401a;
P_0c09401a: /* original 3868, guest PC 0x0c09401a */
if(!s->budget--) { s->failed_pc=0x0c09401au; return 0; }
r[8]-=r[6];
goto P_0c09401c;
P_0c09401c: /* original 0e85, guest PC 0x0c09401c */
if(!s->budget--) { s->failed_pc=0x0c09401cu; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c09401e;
P_0c09401e: /* original 934c, guest PC 0x0c09401e */
if(!s->budget--) { s->failed_pc=0x0c09401eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0940bau,2);
goto P_0c094020;
P_0c094020: /* original 2348, guest PC 0x0c094020 */
if(!s->budget--) { s->failed_pc=0x0c094020u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[4])==0)!=0);
goto P_0c094022;
P_0c094022: /* original 8903, guest PC 0x0c094022 */
if(!s->budget--) { s->failed_pc=0x0c094022u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09402c; }
goto P_0c094024;
P_0c094024: /* original 61d1, guest PC 0x0c094024 */
if(!s->budget--) { s->failed_pc=0x0c094024u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[1]=tmp;
goto P_0c094026;
P_0c094026: /* original e02e, guest PC 0x0c094026 */
if(!s->budget--) { s->failed_pc=0x0c094026u; return 0; }
r[0]=0x0000002eu;
goto P_0c094028;
P_0c094028: /* original 7d04, guest PC 0x0c094028 */
if(!s->budget--) { s->failed_pc=0x0c094028u; return 0; }
r[13]+=0x00000004u;
goto P_0c09402a;
P_0c09402a: /* original 0e15, guest PC 0x0c09402a */
if(!s->budget--) { s->failed_pc=0x0c09402au; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c09402c;
P_0c09402c: /* original 63d4, guest PC 0x0c09402c */
if(!s->budget--) { s->failed_pc=0x0c09402cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[3]=tmp;
goto P_0c09402e;
P_0c09402e: /* original 633c, guest PC 0x0c09402e */
if(!s->budget--) { s->failed_pc=0x0c09402eu; return 0; }
r[3]=r[3]&255u;
goto P_0c094030;
P_0c094030: /* original 1f35, guest PC 0x0c094030 */
if(!s->budget--) { s->failed_pc=0x0c094030u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c094032;
P_0c094032: /* original 60f2, guest PC 0x0c094032 */
if(!s->budget--) { s->failed_pc=0x0c094032u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c094034;
P_0c094034: /* original 67d4, guest PC 0x0c094034 */
if(!s->budget--) { s->failed_pc=0x0c094034u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[13],1);
r[13]+=1;
r[7]=tmp;
goto P_0c094036;
P_0c094036: /* original 8508, guest PC 0x0c094036 */
if(!s->budget--) { s->failed_pc=0x0c094036u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[0]+16,2);
goto P_0c094038;
P_0c094038: /* original 600d, guest PC 0x0c094038 */
if(!s->budget--) { s->failed_pc=0x0c094038u; return 0; }
r[0]=r[0]&65535u;
goto P_0c09403a;
P_0c09403a: /* original c801, guest PC 0x0c09403a */
if(!s->budget--) { s->failed_pc=0x0c09403au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c09403c;
P_0c09403c: /* original 8d0a, guest PC 0x0c09403c */
if(!s->budget--) { s->failed_pc=0x0c09403cu; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c094054; }
goto P_0c094040;
P_0c09403e: /* original 677c, guest PC 0x0c09403e */
if(!s->budget--) { s->failed_pc=0x0c09403eu; return 0; }
r[7]=r[7]&255u;
goto P_0c094040;
P_0c094040: /* original 933d, guest PC 0x0c094040 */
if(!s->budget--) { s->failed_pc=0x0c094040u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0940beu,2);
goto P_0c094042;
P_0c094042: /* original 51f2, guest PC 0x0c094042 */
if(!s->budget--) { s->failed_pc=0x0c094042u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c094044;
P_0c094044: /* original 339c, guest PC 0x0c094044 */
if(!s->budget--) { s->failed_pc=0x0c094044u; return 0; }
r[3]+=r[9];
goto P_0c094046;
P_0c094046: /* original 9239, guest PC 0x0c094046 */
if(!s->budget--) { s->failed_pc=0x0c094046u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0940bcu,2);
goto P_0c094048;
P_0c094048: /* original 3398, guest PC 0x0c094048 */
if(!s->budget--) { s->failed_pc=0x0c094048u; return 0; }
r[3]-=r[9];
goto P_0c09404a;
P_0c09404a: /* original 3130, guest PC 0x0c09404a */
if(!s->budget--) { s->failed_pc=0x0c09404au; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[3])!=0);
goto P_0c09404c;
P_0c09404c: /* original 8d02, guest PC 0x0c09404c */
if(!s->budget--) { s->failed_pc=0x0c09404cu; return 0; }
cond=r[17]&1u;
r[4]|=r[2];
if(cond) { goto P_0c094054; }
goto P_0c094050;
P_0c09404e: /* original 242b, guest PC 0x0c09404e */
if(!s->budget--) { s->failed_pc=0x0c09404eu; return 0; }
r[4]|=r[2];
goto P_0c094050;
P_0c094050: /* original 9336, guest PC 0x0c094050 */
if(!s->budget--) { s->failed_pc=0x0c094050u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0940c0u,2);
goto P_0c094052;
P_0c094052: /* original 243b, guest PC 0x0c094052 */
if(!s->budget--) { s->failed_pc=0x0c094052u; return 0; }
r[4]|=r[3];
goto P_0c094054;
P_0c094054: /* original 52f4, guest PC 0x0c094054 */
if(!s->budget--) { s->failed_pc=0x0c094054u; return 0; }
r[2]=read(ram,r[15]+16,4);
goto P_0c094056;
P_0c094056: /* original e02c, guest PC 0x0c094056 */
if(!s->budget--) { s->failed_pc=0x0c094056u; return 0; }
r[0]=0x0000002cu;
goto P_0c094058;
P_0c094058: /* original 4510, guest PC 0x0c094058 */
if(!s->budget--) { s->failed_pc=0x0c094058u; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09405a;
P_0c09405a: /* original 0e25, guest PC 0x0c09405a */
if(!s->budget--) { s->failed_pc=0x0c09405au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c09405c;
P_0c09405c: /* original e024, guest PC 0x0c09405c */
if(!s->budget--) { s->failed_pc=0x0c09405cu; return 0; }
r[0]=0x00000024u;
goto P_0c09405e;
P_0c09405e: /* original fe57, guest PC 0x0c09405e */
if(!s->budget--) { s->failed_pc=0x0c09405eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c094060;
P_0c094060: /* original e028, guest PC 0x0c094060 */
if(!s->budget--) { s->failed_pc=0x0c094060u; return 0; }
r[0]=0x00000028u;
goto P_0c094062;
P_0c094062: /* original f37c, guest PC 0x0c094062 */
if(!s->budget--) { s->failed_pc=0x0c094062u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c094064;
P_0c094064: /* original f353, guest PC 0x0c094064 */
if(!s->budget--) { s->failed_pc=0x0c094064u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'/');
goto P_0c094066;
P_0c094066: /* original fe37, guest PC 0x0c094066 */
if(!s->budget--) { s->failed_pc=0x0c094066u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c094068;
P_0c094068: /* original e037, guest PC 0x0c094068 */
if(!s->budget--) { s->failed_pc=0x0c094068u; return 0; }
r[0]=0x00000037u;
goto P_0c09406a;
P_0c09406a: /* original 53f5, guest PC 0x0c09406a */
if(!s->budget--) { s->failed_pc=0x0c09406au; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c09406c;
P_0c09406c: /* original 0e34, guest PC 0x0c09406c */
if(!s->budget--) { s->failed_pc=0x0c09406cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09406e;
P_0c09406e: /* original e036, guest PC 0x0c09406e */
if(!s->budget--) { s->failed_pc=0x0c09406eu; return 0; }
r[0]=0x00000036u;
goto P_0c094070;
P_0c094070: /* original 0e74, guest PC 0x0c094070 */
if(!s->budget--) { s->failed_pc=0x0c094070u; return 0; }
write(ram,r[14]+r[0],r[7],1);
goto P_0c094072;
P_0c094072: /* original e034, guest PC 0x0c094072 */
if(!s->budget--) { s->failed_pc=0x0c094072u; return 0; }
r[0]=0x00000034u;
goto P_0c094074;
P_0c094074: /* original 0e45, guest PC 0x0c094074 */
if(!s->budget--) { s->failed_pc=0x0c094074u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c094076;
P_0c094076: /* original e018, guest PC 0x0c094076 */
if(!s->budget--) { s->failed_pc=0x0c094076u; return 0; }
r[0]=0x00000018u;
goto P_0c094078;
P_0c094078: /* original fe47, guest PC 0x0c094078 */
if(!s->budget--) { s->failed_pc=0x0c094078u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09407a;
P_0c09407a: /* original e01c, guest PC 0x0c09407a */
if(!s->budget--) { s->failed_pc=0x0c09407au; return 0; }
r[0]=0x0000001cu;
goto P_0c09407c;
P_0c09407c: /* original fe47, guest PC 0x0c09407c */
if(!s->budget--) { s->failed_pc=0x0c09407cu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09407e;
P_0c09407e: /* original e020, guest PC 0x0c09407e */
if(!s->budget--) { s->failed_pc=0x0c09407eu; return 0; }
r[0]=0x00000020u;
goto P_0c094080;
P_0c094080: /* original fe47, guest PC 0x0c094080 */
if(!s->budget--) { s->failed_pc=0x0c094080u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c094082;
P_0c094082: /* original e004, guest PC 0x0c094082 */
if(!s->budget--) { s->failed_pc=0x0c094082u; return 0; }
r[0]=0x00000004u;
goto P_0c094084;
P_0c094084: /* original fe4a, guest PC 0x0c094084 */
if(!s->budget--) { s->failed_pc=0x0c094084u; return 0; }
vf3_matrix_store(s,ram,4,r[14]);
goto P_0c094086;
P_0c094086: /* original fe47, guest PC 0x0c094086 */
if(!s->budget--) { s->failed_pc=0x0c094086u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c094088;
P_0c094088: /* original e008, guest PC 0x0c094088 */
if(!s->budget--) { s->failed_pc=0x0c094088u; return 0; }
r[0]=0x00000008u;
goto P_0c09408a;
P_0c09408a: /* original fe47, guest PC 0x0c09408a */
if(!s->budget--) { s->failed_pc=0x0c09408au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c09408c;
P_0c09408c: /* original 8fb6, guest PC 0x0c09408c */
if(!s->budget--) { s->failed_pc=0x0c09408cu; return 0; }
cond=r[17]&1u;
r[14]+=0x00000038u;
if(!cond) { goto P_0c093ffc; }
goto P_0c094090;
P_0c09408e: /* original 7e38, guest PC 0x0c09408e */
if(!s->budget--) { s->failed_pc=0x0c09408eu; return 0; }
r[14]+=0x00000038u;
goto P_0c094090;
P_0c094090: /* original 53f1, guest PC 0x0c094090 */
if(!s->budget--) { s->failed_pc=0x0c094090u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c094092;
P_0c094092: /* original 73ff, guest PC 0x0c094092 */
if(!s->budget--) { s->failed_pc=0x0c094092u; return 0; }
r[3]+=0xffffffffu;
goto P_0c094094;
P_0c094094: /* original 2338, guest PC 0x0c094094 */
if(!s->budget--) { s->failed_pc=0x0c094094u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c094096;
P_0c094096: /* original 8d03, guest PC 0x0c094096 */
if(!s->budget--) { s->failed_pc=0x0c094096u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c0940a0; }
goto P_0c09409a;
P_0c094098: /* original 1f31, guest PC 0x0c094098 */
if(!s->budget--) { s->failed_pc=0x0c094098u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c09409a;
P_0c09409a: /* original d20a, guest PC 0x0c09409a */
if(!s->budget--) { s->failed_pc=0x0c09409au; return 0; }
r[2]=read(ram,0x0c0940c4u,4);
goto P_0c09409c;
P_0c09409c: /* original 422b, guest PC 0x0c09409c */
if(!s->budget--) { s->failed_pc=0x0c09409cu; return 0; }
target=r[2];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c093ddau: goto P_0c093dda;
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
P_0c09409e: /* original 0009, guest PC 0x0c09409e */
if(!s->budget--) { s->failed_pc=0x0c09409eu; return 0; }
goto P_0c0940a0;
P_0c0940a0: /* original 7f40, guest PC 0x0c0940a0 */
if(!s->budget--) { s->failed_pc=0x0c0940a0u; return 0; }
r[15]+=0x00000040u;
goto P_0c0940a2;
P_0c0940a2: /* original e200, guest PC 0x0c0940a2 */
if(!s->budget--) { s->failed_pc=0x0c0940a2u; return 0; }
r[2]=0x00000000u;
goto P_0c0940a4;
P_0c0940a4: /* original e034, guest PC 0x0c0940a4 */
if(!s->budget--) { s->failed_pc=0x0c0940a4u; return 0; }
r[0]=0x00000034u;
goto P_0c0940a6;
P_0c0940a6: /* original 0e25, guest PC 0x0c0940a6 */
if(!s->budget--) { s->failed_pc=0x0c0940a6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0940a8;
P_0c0940a8: /* original 68f6, guest PC 0x0c0940a8 */
if(!s->budget--) { s->failed_pc=0x0c0940a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0940aa;
P_0c0940aa: /* original 69f6, guest PC 0x0c0940aa */
if(!s->budget--) { s->failed_pc=0x0c0940aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0940ac;
P_0c0940ac: /* original 6af6, guest PC 0x0c0940ac */
if(!s->budget--) { s->failed_pc=0x0c0940acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0940ae;
P_0c0940ae: /* original 6bf6, guest PC 0x0c0940ae */
if(!s->budget--) { s->failed_pc=0x0c0940aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0940b0;
P_0c0940b0: /* original 6cf6, guest PC 0x0c0940b0 */
if(!s->budget--) { s->failed_pc=0x0c0940b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0940b2;
P_0c0940b2: /* original 6df6, guest PC 0x0c0940b2 */
if(!s->budget--) { s->failed_pc=0x0c0940b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0940b4;
P_0c0940b4: /* original 000b, guest PC 0x0c0940b4 */
if(!s->budget--) { s->failed_pc=0x0c0940b4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0940b6: /* original 6ef6, guest PC 0x0c0940b6 */
if(!s->budget--) { s->failed_pc=0x0c0940b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0940b8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0940b8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
