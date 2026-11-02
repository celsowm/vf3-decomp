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
int vf3_away_batch118_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042e30u: goto P_0c042e30;
case 0x0c042e32u: goto P_0c042e32;
case 0x0c042e34u: goto P_0c042e34;
case 0x0c042e36u: goto P_0c042e36;
case 0x0c042e38u: goto P_0c042e38;
case 0x0c042e3au: goto P_0c042e3a;
case 0x0c042efcu: goto P_0c042efc;
case 0x0c042efeu: goto P_0c042efe;
case 0x0c042f00u: goto P_0c042f00;
case 0x0c042f02u: goto P_0c042f02;
case 0x0c042f04u: goto P_0c042f04;
case 0x0c042f06u: goto P_0c042f06;
case 0x0c059840u: goto P_0c059840;
case 0x0c059842u: goto P_0c059842;
case 0x0c059844u: goto P_0c059844;
case 0x0c059846u: goto P_0c059846;
case 0x0c059848u: goto P_0c059848;
case 0x0c05984au: goto P_0c05984a;
case 0x0c05984cu: goto P_0c05984c;
case 0x0c05984eu: goto P_0c05984e;
case 0x0c059850u: goto P_0c059850;
case 0x0c059852u: goto P_0c059852;
case 0x0c059854u: goto P_0c059854;
case 0x0c059856u: goto P_0c059856;
case 0x0c059858u: goto P_0c059858;
case 0x0c05985au: goto P_0c05985a;
case 0x0c05985cu: goto P_0c05985c;
case 0x0c05985eu: goto P_0c05985e;
case 0x0c059860u: goto P_0c059860;
case 0x0c059862u: goto P_0c059862;
case 0x0c059864u: goto P_0c059864;
case 0x0c059866u: goto P_0c059866;
case 0x0c059868u: goto P_0c059868;
case 0x0c05986au: goto P_0c05986a;
case 0x0c05986cu: goto P_0c05986c;
case 0x0c05986eu: goto P_0c05986e;
case 0x0c059870u: goto P_0c059870;
case 0x0c059872u: goto P_0c059872;
case 0x0c059874u: goto P_0c059874;
case 0x0c059876u: goto P_0c059876;
case 0x0c059878u: goto P_0c059878;
case 0x0c05987au: goto P_0c05987a;
case 0x0c05987cu: goto P_0c05987c;
case 0x0c05987eu: goto P_0c05987e;
case 0x0c059880u: goto P_0c059880;
case 0x0c059882u: goto P_0c059882;
case 0x0c059884u: goto P_0c059884;
case 0x0c059886u: goto P_0c059886;
case 0x0c059888u: goto P_0c059888;
case 0x0c05988au: goto P_0c05988a;
case 0x0c05988cu: goto P_0c05988c;
case 0x0c05988eu: goto P_0c05988e;
case 0x0c059890u: goto P_0c059890;
case 0x0c059892u: goto P_0c059892;
case 0x0c059894u: goto P_0c059894;
case 0x0c059a20u: goto P_0c059a20;
case 0x0c059a22u: goto P_0c059a22;
case 0x0c059a24u: goto P_0c059a24;
case 0x0c059a26u: goto P_0c059a26;
case 0x0c059a28u: goto P_0c059a28;
case 0x0c059a2au: goto P_0c059a2a;
case 0x0c059a2cu: goto P_0c059a2c;
case 0x0c059a2eu: goto P_0c059a2e;
case 0x0c059a30u: goto P_0c059a30;
case 0x0c059a32u: goto P_0c059a32;
case 0x0c059a34u: goto P_0c059a34;
case 0x0c059a36u: goto P_0c059a36;
case 0x0c059a38u: goto P_0c059a38;
case 0x0c059a3au: goto P_0c059a3a;
case 0x0c059a3cu: goto P_0c059a3c;
case 0x0c059a3eu: goto P_0c059a3e;
case 0x0c059a40u: goto P_0c059a40;
case 0x0c059a42u: goto P_0c059a42;
case 0x0c059a44u: goto P_0c059a44;
case 0x0c059a46u: goto P_0c059a46;
case 0x0c059a48u: goto P_0c059a48;
case 0x0c059a4au: goto P_0c059a4a;
case 0x0c059a4cu: goto P_0c059a4c;
case 0x0c059a4eu: goto P_0c059a4e;
case 0x0c059a50u: goto P_0c059a50;
case 0x0c059a52u: goto P_0c059a52;
case 0x0c059a54u: goto P_0c059a54;
case 0x0c059a56u: goto P_0c059a56;
case 0x0c059a58u: goto P_0c059a58;
case 0x0c059a5au: goto P_0c059a5a;
case 0x0c059a5cu: goto P_0c059a5c;
case 0x0c059a5eu: goto P_0c059a5e;
case 0x0c059a60u: goto P_0c059a60;
case 0x0c059a62u: goto P_0c059a62;
case 0x0c059a64u: goto P_0c059a64;
case 0x0c059a66u: goto P_0c059a66;
case 0x0c059a68u: goto P_0c059a68;
case 0x0c059a6au: goto P_0c059a6a;
case 0x0c059a6cu: goto P_0c059a6c;
case 0x0c059a6eu: goto P_0c059a6e;
case 0x0c059a70u: goto P_0c059a70;
case 0x0c059a72u: goto P_0c059a72;
case 0x0c059a74u: goto P_0c059a74;
case 0x0c059a76u: goto P_0c059a76;
case 0x0c059a78u: goto P_0c059a78;
case 0x0c059a7au: goto P_0c059a7a;
case 0x0c059a7cu: goto P_0c059a7c;
case 0x0c059a7eu: goto P_0c059a7e;
case 0x0c059a80u: goto P_0c059a80;
case 0x0c059a82u: goto P_0c059a82;
case 0x0c059a84u: goto P_0c059a84;
case 0x0c059a86u: goto P_0c059a86;
case 0x0c059a88u: goto P_0c059a88;
case 0x0c059a8au: goto P_0c059a8a;
case 0x0c059a8cu: goto P_0c059a8c;
case 0x0c059a8eu: goto P_0c059a8e;
case 0x0c059a90u: goto P_0c059a90;
case 0x0c059a92u: goto P_0c059a92;
case 0x0c059a94u: goto P_0c059a94;
case 0x0c059a96u: goto P_0c059a96;
case 0x0c059a98u: goto P_0c059a98;
case 0x0c059a9au: goto P_0c059a9a;
case 0x0c059a9cu: goto P_0c059a9c;
case 0x0c059a9eu: goto P_0c059a9e;
case 0x0c059aa0u: goto P_0c059aa0;
case 0x0c059aa2u: goto P_0c059aa2;
case 0x0c059aa4u: goto P_0c059aa4;
case 0x0c059aa6u: goto P_0c059aa6;
case 0x0c059aa8u: goto P_0c059aa8;
case 0x0c059aaau: goto P_0c059aaa;
case 0x0c059aacu: goto P_0c059aac;
case 0x0c059aaeu: goto P_0c059aae;
case 0x0c059ab0u: goto P_0c059ab0;
case 0x0c059ab2u: goto P_0c059ab2;
case 0x0c059ab4u: goto P_0c059ab4;
case 0x0c059ab6u: goto P_0c059ab6;
case 0x0c059ab8u: goto P_0c059ab8;
case 0x0c059abau: goto P_0c059aba;
case 0x0c059abcu: goto P_0c059abc;
case 0x0c059abeu: goto P_0c059abe;
case 0x0c059ac0u: goto P_0c059ac0;
case 0x0c059ac2u: goto P_0c059ac2;
case 0x0c059ac4u: goto P_0c059ac4;
case 0x0c059ac6u: goto P_0c059ac6;
case 0x0c059ac8u: goto P_0c059ac8;
case 0x0c059acau: goto P_0c059aca;
case 0x0c059accu: goto P_0c059acc;
case 0x0c059aceu: goto P_0c059ace;
case 0x0c059ad0u: goto P_0c059ad0;
case 0x0c059ad2u: goto P_0c059ad2;
case 0x0c059ad4u: goto P_0c059ad4;
case 0x0c059ad6u: goto P_0c059ad6;
case 0x0c059ad8u: goto P_0c059ad8;
case 0x0c059adau: goto P_0c059ada;
case 0x0c059adcu: goto P_0c059adc;
case 0x0c059adeu: goto P_0c059ade;
case 0x0c059ae0u: goto P_0c059ae0;
case 0x0c059ae2u: goto P_0c059ae2;
case 0x0c059ae4u: goto P_0c059ae4;
case 0x0c059ae6u: goto P_0c059ae6;
case 0x0c059ae8u: goto P_0c059ae8;
case 0x0c059aeau: goto P_0c059aea;
case 0x0c059aecu: goto P_0c059aec;
case 0x0c059aeeu: goto P_0c059aee;
case 0x0c059af0u: goto P_0c059af0;
case 0x0c059af2u: goto P_0c059af2;
case 0x0c059af4u: goto P_0c059af4;
case 0x0c059af6u: goto P_0c059af6;
case 0x0c059af8u: goto P_0c059af8;
case 0x0c059afau: goto P_0c059afa;
case 0x0c059afcu: goto P_0c059afc;
case 0x0c059afeu: goto P_0c059afe;
case 0x0c059b00u: goto P_0c059b00;
case 0x0c059b02u: goto P_0c059b02;
case 0x0c059b04u: goto P_0c059b04;
case 0x0c059b06u: goto P_0c059b06;
case 0x0c059b08u: goto P_0c059b08;
case 0x0c059b0au: goto P_0c059b0a;
case 0x0c059b0cu: goto P_0c059b0c;
case 0x0c059b40u: goto P_0c059b40;
case 0x0c059b42u: goto P_0c059b42;
case 0x0c059b44u: goto P_0c059b44;
case 0x0c059b46u: goto P_0c059b46;
case 0x0c059b48u: goto P_0c059b48;
case 0x0c059b4au: goto P_0c059b4a;
case 0x0c059b4cu: goto P_0c059b4c;
case 0x0c059b4eu: goto P_0c059b4e;
case 0x0c059b50u: goto P_0c059b50;
case 0x0c059b52u: goto P_0c059b52;
case 0x0c059b54u: goto P_0c059b54;
case 0x0c059b56u: goto P_0c059b56;
case 0x0c059b58u: goto P_0c059b58;
case 0x0c059b5au: goto P_0c059b5a;
case 0x0c059b5cu: goto P_0c059b5c;
case 0x0c059b5eu: goto P_0c059b5e;
case 0x0c059b60u: goto P_0c059b60;
case 0x0c059b62u: goto P_0c059b62;
case 0x0c059b64u: goto P_0c059b64;
case 0x0c059b66u: goto P_0c059b66;
case 0x0c059b68u: goto P_0c059b68;
case 0x0c059b6au: goto P_0c059b6a;
case 0x0c059b6cu: goto P_0c059b6c;
case 0x0c059b6eu: goto P_0c059b6e;
case 0x0c059b70u: goto P_0c059b70;
case 0x0c059b72u: goto P_0c059b72;
case 0x0c059b74u: goto P_0c059b74;
case 0x0c059b76u: goto P_0c059b76;
case 0x0c059b78u: goto P_0c059b78;
case 0x0c059b7au: goto P_0c059b7a;
case 0x0c059b7cu: goto P_0c059b7c;
case 0x0c059b7eu: goto P_0c059b7e;
case 0x0c059b80u: goto P_0c059b80;
case 0x0c059b82u: goto P_0c059b82;
case 0x0c059b84u: goto P_0c059b84;
case 0x0c059b86u: goto P_0c059b86;
case 0x0c059b88u: goto P_0c059b88;
case 0x0c059b8au: goto P_0c059b8a;
case 0x0c059b8cu: goto P_0c059b8c;
case 0x0c059b8eu: goto P_0c059b8e;
case 0x0c059b90u: goto P_0c059b90;
case 0x0c059b92u: goto P_0c059b92;
case 0x0c059b94u: goto P_0c059b94;
case 0x0c059b96u: goto P_0c059b96;
case 0x0c059b98u: goto P_0c059b98;
case 0x0c059b9au: goto P_0c059b9a;
case 0x0c059b9cu: goto P_0c059b9c;
case 0x0c059b9eu: goto P_0c059b9e;
case 0x0c059ba0u: goto P_0c059ba0;
case 0x0c059ba2u: goto P_0c059ba2;
case 0x0c059ba4u: goto P_0c059ba4;
case 0x0c059ba6u: goto P_0c059ba6;
case 0x0c059ba8u: goto P_0c059ba8;
case 0x0c059baau: goto P_0c059baa;
case 0x0c059bacu: goto P_0c059bac;
case 0x0c059baeu: goto P_0c059bae;
case 0x0c059bb0u: goto P_0c059bb0;
case 0x0c059bb2u: goto P_0c059bb2;
case 0x0c059bb4u: goto P_0c059bb4;
case 0x0c059bb6u: goto P_0c059bb6;
case 0x0c059bb8u: goto P_0c059bb8;
case 0x0c059bbau: goto P_0c059bba;
case 0x0c059bbcu: goto P_0c059bbc;
case 0x0c059bbeu: goto P_0c059bbe;
case 0x0c059bc0u: goto P_0c059bc0;
case 0x0c059bc2u: goto P_0c059bc2;
case 0x0c059bc4u: goto P_0c059bc4;
case 0x0c059bc6u: goto P_0c059bc6;
case 0x0c059bc8u: goto P_0c059bc8;
case 0x0c059bcau: goto P_0c059bca;
case 0x0c059bccu: goto P_0c059bcc;
case 0x0c059bceu: goto P_0c059bce;
case 0x0c059bd0u: goto P_0c059bd0;
case 0x0c059bd2u: goto P_0c059bd2;
case 0x0c059bd4u: goto P_0c059bd4;
case 0x0c059bd6u: goto P_0c059bd6;
case 0x0c059bd8u: goto P_0c059bd8;
case 0x0c059bdau: goto P_0c059bda;
case 0x0c059bdcu: goto P_0c059bdc;
case 0x0c059bdeu: goto P_0c059bde;
case 0x0c059be0u: goto P_0c059be0;
case 0x0c059be2u: goto P_0c059be2;
case 0x0c059be4u: goto P_0c059be4;
case 0x0c059be6u: goto P_0c059be6;
case 0x0c059be8u: goto P_0c059be8;
case 0x0c059beau: goto P_0c059bea;
case 0x0c059becu: goto P_0c059bec;
case 0x0c059beeu: goto P_0c059bee;
case 0x0c059bf0u: goto P_0c059bf0;
case 0x0c059bf2u: goto P_0c059bf2;
case 0x0c059bf4u: goto P_0c059bf4;
case 0x0c059bf6u: goto P_0c059bf6;
case 0x0c059bf8u: goto P_0c059bf8;
case 0x0c059bfau: goto P_0c059bfa;
case 0x0c059bfcu: goto P_0c059bfc;
case 0x0c059bfeu: goto P_0c059bfe;
case 0x0c059c00u: goto P_0c059c00;
case 0x0c059c02u: goto P_0c059c02;
case 0x0c059c04u: goto P_0c059c04;
case 0x0c059c06u: goto P_0c059c06;
case 0x0c059c08u: goto P_0c059c08;
case 0x0c059c0au: goto P_0c059c0a;
case 0x0c059c0cu: goto P_0c059c0c;
case 0x0c059c0eu: goto P_0c059c0e;
case 0x0c059c10u: goto P_0c059c10;
case 0x0c059c12u: goto P_0c059c12;
case 0x0c059c14u: goto P_0c059c14;
case 0x0c059c16u: goto P_0c059c16;
case 0x0c059c18u: goto P_0c059c18;
case 0x0c059c1au: goto P_0c059c1a;
case 0x0c059c1cu: goto P_0c059c1c;
case 0x0c059c1eu: goto P_0c059c1e;
case 0x0c059c88u: goto P_0c059c88;
case 0x0c059c8au: goto P_0c059c8a;
case 0x0c059c8cu: goto P_0c059c8c;
case 0x0c059c8eu: goto P_0c059c8e;
case 0x0c059c90u: goto P_0c059c90;
case 0x0c059c92u: goto P_0c059c92;
case 0x0c059c94u: goto P_0c059c94;
case 0x0c059c96u: goto P_0c059c96;
case 0x0c059c98u: goto P_0c059c98;
case 0x0c059c9au: goto P_0c059c9a;
case 0x0c059c9cu: goto P_0c059c9c;
case 0x0c059c9eu: goto P_0c059c9e;
case 0x0c059ca0u: goto P_0c059ca0;
case 0x0c059ca2u: goto P_0c059ca2;
case 0x0c059ca4u: goto P_0c059ca4;
case 0x0c059ca6u: goto P_0c059ca6;
case 0x0c059ca8u: goto P_0c059ca8;
case 0x0c059caau: goto P_0c059caa;
case 0x0c059cacu: goto P_0c059cac;
case 0x0c059caeu: goto P_0c059cae;
case 0x0c059cb0u: goto P_0c059cb0;
case 0x0c059cb2u: goto P_0c059cb2;
case 0x0c059cb4u: goto P_0c059cb4;
case 0x0c059cb6u: goto P_0c059cb6;
case 0x0c059cb8u: goto P_0c059cb8;
case 0x0c059cbau: goto P_0c059cba;
case 0x0c059cbcu: goto P_0c059cbc;
case 0x0c059cbeu: goto P_0c059cbe;
case 0x0c059cc0u: goto P_0c059cc0;
case 0x0c059cc2u: goto P_0c059cc2;
case 0x0c059cc4u: goto P_0c059cc4;
case 0x0c059cc6u: goto P_0c059cc6;
case 0x0c059cc8u: goto P_0c059cc8;
case 0x0c059ccau: goto P_0c059cca;
case 0x0c059cccu: goto P_0c059ccc;
case 0x0c059cceu: goto P_0c059cce;
case 0x0c059cd0u: goto P_0c059cd0;
case 0x0c059cd2u: goto P_0c059cd2;
case 0x0c059cd4u: goto P_0c059cd4;
case 0x0c059cd6u: goto P_0c059cd6;
case 0x0c059cd8u: goto P_0c059cd8;
case 0x0c059cdau: goto P_0c059cda;
case 0x0c059cdcu: goto P_0c059cdc;
case 0x0c059cdeu: goto P_0c059cde;
case 0x0c059ce0u: goto P_0c059ce0;
case 0x0c059ce2u: goto P_0c059ce2;
case 0x0c059ce4u: goto P_0c059ce4;
case 0x0c059ce6u: goto P_0c059ce6;
case 0x0c059ce8u: goto P_0c059ce8;
case 0x0c059ceau: goto P_0c059cea;
case 0x0c059cecu: goto P_0c059cec;
case 0x0c059ceeu: goto P_0c059cee;
case 0x0c059cf0u: goto P_0c059cf0;
case 0x0c059cf2u: goto P_0c059cf2;
case 0x0c059cf4u: goto P_0c059cf4;
case 0x0c059cf6u: goto P_0c059cf6;
case 0x0c059cf8u: goto P_0c059cf8;
case 0x0c059cfau: goto P_0c059cfa;
case 0x0c059cfcu: goto P_0c059cfc;
case 0x0c059cfeu: goto P_0c059cfe;
case 0x0c059d00u: goto P_0c059d00;
case 0x0c059d02u: goto P_0c059d02;
case 0x0c059d04u: goto P_0c059d04;
case 0x0c059d06u: goto P_0c059d06;
case 0x0c059d08u: goto P_0c059d08;
case 0x0c059d0au: goto P_0c059d0a;
case 0x0c059d0cu: goto P_0c059d0c;
case 0x0c059d0eu: goto P_0c059d0e;
case 0x0c059d10u: goto P_0c059d10;
case 0x0c059d12u: goto P_0c059d12;
case 0x0c059d14u: goto P_0c059d14;
case 0x0c059d16u: goto P_0c059d16;
case 0x0c059d18u: goto P_0c059d18;
case 0x0c059d1au: goto P_0c059d1a;
case 0x0c059d1cu: goto P_0c059d1c;
case 0x0c059d1eu: goto P_0c059d1e;
case 0x0c059d20u: goto P_0c059d20;
case 0x0c059d22u: goto P_0c059d22;
case 0x0c059d24u: goto P_0c059d24;
case 0x0c059d26u: goto P_0c059d26;
case 0x0c059d28u: goto P_0c059d28;
case 0x0c059d2au: goto P_0c059d2a;
case 0x0c059d2cu: goto P_0c059d2c;
case 0x0c059d2eu: goto P_0c059d2e;
case 0x0c059d30u: goto P_0c059d30;
case 0x0c059d32u: goto P_0c059d32;
case 0x0c059d34u: goto P_0c059d34;
case 0x0c059d36u: goto P_0c059d36;
case 0x0c059d38u: goto P_0c059d38;
case 0x0c059d3au: goto P_0c059d3a;
case 0x0c059d3cu: goto P_0c059d3c;
case 0x0c059d3eu: goto P_0c059d3e;
case 0x0c059d40u: goto P_0c059d40;
case 0x0c059d42u: goto P_0c059d42;
case 0x0c059d44u: goto P_0c059d44;
case 0x0c059d46u: goto P_0c059d46;
case 0x0c059d48u: goto P_0c059d48;
case 0x0c059d4au: goto P_0c059d4a;
case 0x0c059d4cu: goto P_0c059d4c;
case 0x0c059d4eu: goto P_0c059d4e;
case 0x0c059d50u: goto P_0c059d50;
case 0x0c059d52u: goto P_0c059d52;
case 0x0c059d54u: goto P_0c059d54;
case 0x0c059d56u: goto P_0c059d56;
case 0x0c059d58u: goto P_0c059d58;
case 0x0c059d5au: goto P_0c059d5a;
case 0x0c059d5cu: goto P_0c059d5c;
case 0x0c059d5eu: goto P_0c059d5e;
case 0x0c059d60u: goto P_0c059d60;
case 0x0c059d62u: goto P_0c059d62;
case 0x0c059d64u: goto P_0c059d64;
case 0x0c059d66u: goto P_0c059d66;
case 0x0c059d68u: goto P_0c059d68;
case 0x0c059d6au: goto P_0c059d6a;
case 0x0c059d6cu: goto P_0c059d6c;
case 0x0c059d6eu: goto P_0c059d6e;
case 0x0c059d70u: goto P_0c059d70;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042e30: /* original d102, guest PC 0x0c042e30 */
if(!s->budget--) { s->failed_pc=0x0c042e30u; return 0; }
r[1]=read(ram,0x0c042e3cu,4);
goto P_0c042e32;
P_0c042e32: /* original d203, guest PC 0x0c042e32 */
if(!s->budget--) { s->failed_pc=0x0c042e32u; return 0; }
r[2]=read(ram,0x0c042e40u,4);
goto P_0c042e34;
P_0c042e34: /* original e000, guest PC 0x0c042e34 */
if(!s->budget--) { s->failed_pc=0x0c042e34u; return 0; }
r[0]=0x00000000u;
goto P_0c042e36;
P_0c042e36: /* original 2122, guest PC 0x0c042e36 */
if(!s->budget--) { s->failed_pc=0x0c042e36u; return 0; }
write(ram,r[1],r[2],4);
goto P_0c042e38;
P_0c042e38: /* original 000b, guest PC 0x0c042e38 */
if(!s->budget--) { s->failed_pc=0x0c042e38u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042e3a: /* original 62f6, guest PC 0x0c042e3a */
if(!s->budget--) { s->failed_pc=0x0c042e3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
if(!vf3_matrix_family(0x0c042e3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042e3cu; return 0; } return 1;
P_0c042efc: /* original 2f36, guest PC 0x0c042efc */
if(!s->budget--) { s->failed_pc=0x0c042efcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042efe;
P_0c042efe: /* original d305, guest PC 0x0c042efe */
if(!s->budget--) { s->failed_pc=0x0c042efeu; return 0; }
r[3]=read(ram,0x0c042f14u,4);
goto P_0c042f00;
P_0c042f00: /* original 033e, guest PC 0x0c042f00 */
if(!s->budget--) { s->failed_pc=0x0c042f00u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c042f02;
P_0c042f02: /* original 70fc, guest PC 0x0c042f02 */
if(!s->budget--) { s->failed_pc=0x0c042f02u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c042f04;
P_0c042f04: /* original 432b, guest PC 0x0c042f04 */
if(!s->budget--) { s->failed_pc=0x0c042f04u; return 0; }
target=r[3];
r[0]=read(ram,r[2]+r[0],4);
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
P_0c042f06: /* original 002e, guest PC 0x0c042f06 */
if(!s->budget--) { s->failed_pc=0x0c042f06u; return 0; }
r[0]=read(ram,r[2]+r[0],4);
if(!vf3_matrix_family(0x0c042f08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042f08u; return 0; } return 1;
P_0c059840: /* original 2fe6, guest PC 0x0c059840 */
if(!s->budget--) { s->failed_pc=0x0c059840u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059842;
P_0c059842: /* original 2fd6, guest PC 0x0c059842 */
if(!s->budget--) { s->failed_pc=0x0c059842u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059844;
P_0c059844: /* original 2fc6, guest PC 0x0c059844 */
if(!s->budget--) { s->failed_pc=0x0c059844u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059846;
P_0c059846: /* original 2fb6, guest PC 0x0c059846 */
if(!s->budget--) { s->failed_pc=0x0c059846u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059848;
P_0c059848: /* original 4f22, guest PC 0x0c059848 */
if(!s->budget--) { s->failed_pc=0x0c059848u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05984a;
P_0c05984a: /* original d32a, guest PC 0x0c05984a */
if(!s->budget--) { s->failed_pc=0x0c05984au; return 0; }
r[3]=read(ram,0x0c0598f4u,4);
goto P_0c05984c;
P_0c05984c: /* original de2a, guest PC 0x0c05984c */
if(!s->budget--) { s->failed_pc=0x0c05984cu; return 0; }
r[14]=read(ram,0x0c0598f8u,4);
goto P_0c05984e;
P_0c05984e: /* original 6432, guest PC 0x0c05984e */
if(!s->budget--) { s->failed_pc=0x0c05984eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059850;
P_0c059850: /* original d22a, guest PC 0x0c059850 */
if(!s->budget--) { s->failed_pc=0x0c059850u; return 0; }
r[2]=read(ram,0x0c0598fcu,4);
goto P_0c059852;
P_0c059852: /* original 6442, guest PC 0x0c059852 */
if(!s->budget--) { s->failed_pc=0x0c059852u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c059854;
P_0c059854: /* original 6543, guest PC 0x0c059854 */
if(!s->budget--) { s->failed_pc=0x0c059854u; return 0; }
r[5]=r[4];
goto P_0c059856;
P_0c059856: /* original 4529, guest PC 0x0c059856 */
if(!s->budget--) { s->failed_pc=0x0c059856u; return 0; }
r[5]>>=16;
goto P_0c059858;
P_0c059858: /* original 4519, guest PC 0x0c059858 */
if(!s->budget--) { s->failed_pc=0x0c059858u; return 0; }
r[5]>>=8;
goto P_0c05985a;
P_0c05985a: /* original 2252, guest PC 0x0c05985a */
if(!s->budget--) { s->failed_pc=0x0c05985au; return 0; }
write(ram,r[2],r[5],4);
goto P_0c05985c;
P_0c05985c: /* original d128, guest PC 0x0c05985c */
if(!s->budget--) { s->failed_pc=0x0c05985cu; return 0; }
r[1]=read(ram,0x0c059900u,4);
goto P_0c05985e;
P_0c05985e: /* original 2152, guest PC 0x0c05985e */
if(!s->budget--) { s->failed_pc=0x0c05985eu; return 0; }
write(ram,r[1],r[5],4);
goto P_0c059860;
P_0c059860: /* original dd28, guest PC 0x0c059860 */
if(!s->budget--) { s->failed_pc=0x0c059860u; return 0; }
r[13]=read(ram,0x0c059904u,4);
goto P_0c059862;
P_0c059862: /* original ec04, guest PC 0x0c059862 */
if(!s->budget--) { s->failed_pc=0x0c059862u; return 0; }
r[12]=0x00000004u;
goto P_0c059864;
P_0c059864: /* original d328, guest PC 0x0c059864 */
if(!s->budget--) { s->failed_pc=0x0c059864u; return 0; }
r[3]=read(ram,0x0c059908u,4);
goto P_0c059866;
P_0c059866: /* original 2d49, guest PC 0x0c059866 */
if(!s->budget--) { s->failed_pc=0x0c059866u; return 0; }
r[13]&=r[4];
goto P_0c059868;
P_0c059868: /* original db28, guest PC 0x0c059868 */
if(!s->budget--) { s->failed_pc=0x0c059868u; return 0; }
r[11]=read(ram,0x0c05990cu,4);
goto P_0c05986a;
P_0c05986a: /* original 2d3b, guest PC 0x0c05986a */
if(!s->budget--) { s->failed_pc=0x0c05986au; return 0; }
r[13]|=r[3];
goto P_0c05986c;
P_0c05986c: /* original e620, guest PC 0x0c05986c */
if(!s->budget--) { s->failed_pc=0x0c05986cu; return 0; }
r[6]=0x00000020u;
goto P_0c05986e;
P_0c05986e: /* original 65e3, guest PC 0x0c05986e */
if(!s->budget--) { s->failed_pc=0x0c05986eu; return 0; }
r[5]=r[14];
goto P_0c059870;
P_0c059870: /* original 4b0b, guest PC 0x0c059870 */
if(!s->budget--) { s->failed_pc=0x0c059870u; return 0; }
target=r[11];
r[16]=code_base|0x0c059874u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059874u) { target=s->pc; goto dispatch; }
goto P_0c059874;
P_0c059872: /* original 64d3, guest PC 0x0c059872 */
if(!s->budget--) { s->failed_pc=0x0c059872u; return 0; }
r[4]=r[13];
goto P_0c059874;
P_0c059874: /* original 0d83, guest PC 0x0c059874 */
if(!s->budget--) { s->failed_pc=0x0c059874u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c059876;
P_0c059876: /* original 7d20, guest PC 0x0c059876 */
if(!s->budget--) { s->failed_pc=0x0c059876u; return 0; }
r[13]+=0x00000020u;
goto P_0c059878;
P_0c059878: /* original 4c10, guest PC 0x0c059878 */
if(!s->budget--) { s->failed_pc=0x0c059878u; return 0; }
--r[12];
r[17]=(r[17]&~1u)|((r[12]==0)!=0);
goto P_0c05987a;
P_0c05987a: /* original 8ff7, guest PC 0x0c05987a */
if(!s->budget--) { s->failed_pc=0x0c05987au; return 0; }
cond=r[17]&1u;
r[14]+=0x00000020u;
if(!cond) { goto P_0c05986c; }
goto P_0c05987e;
P_0c05987c: /* original 7e20, guest PC 0x0c05987c */
if(!s->budget--) { s->failed_pc=0x0c05987cu; return 0; }
r[14]+=0x00000020u;
goto P_0c05987e;
P_0c05987e: /* original d21d, guest PC 0x0c05987e */
if(!s->budget--) { s->failed_pc=0x0c05987eu; return 0; }
r[2]=read(ram,0x0c0598f4u,4);
goto P_0c059880;
P_0c059880: /* original 9136, guest PC 0x0c059880 */
if(!s->budget--) { s->failed_pc=0x0c059880u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0598f0u,2);
goto P_0c059882;
P_0c059882: /* original 6322, guest PC 0x0c059882 */
if(!s->budget--) { s->failed_pc=0x0c059882u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059884;
P_0c059884: /* original 6032, guest PC 0x0c059884 */
if(!s->budget--) { s->failed_pc=0x0c059884u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059886;
P_0c059886: /* original 301c, guest PC 0x0c059886 */
if(!s->budget--) { s->failed_pc=0x0c059886u; return 0; }
r[0]+=r[1];
goto P_0c059888;
P_0c059888: /* original 2302, guest PC 0x0c059888 */
if(!s->budget--) { s->failed_pc=0x0c059888u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05988a;
P_0c05988a: /* original 4f26, guest PC 0x0c05988a */
if(!s->budget--) { s->failed_pc=0x0c05988au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05988c;
P_0c05988c: /* original 6bf6, guest PC 0x0c05988c */
if(!s->budget--) { s->failed_pc=0x0c05988cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05988e;
P_0c05988e: /* original 6cf6, guest PC 0x0c05988e */
if(!s->budget--) { s->failed_pc=0x0c05988eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059890;
P_0c059890: /* original 6df6, guest PC 0x0c059890 */
if(!s->budget--) { s->failed_pc=0x0c059890u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059892;
P_0c059892: /* original 000b, guest PC 0x0c059892 */
if(!s->budget--) { s->failed_pc=0x0c059892u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059894: /* original 6ef6, guest PC 0x0c059894 */
if(!s->budget--) { s->failed_pc=0x0c059894u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c059896u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059896u; return 0; } return 1;
P_0c059a20: /* original 2fe6, guest PC 0x0c059a20 */
if(!s->budget--) { s->failed_pc=0x0c059a20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a22;
P_0c059a22: /* original 2fd6, guest PC 0x0c059a22 */
if(!s->budget--) { s->failed_pc=0x0c059a22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a24;
P_0c059a24: /* original 2fc6, guest PC 0x0c059a24 */
if(!s->budget--) { s->failed_pc=0x0c059a24u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a26;
P_0c059a26: /* original 2fb6, guest PC 0x0c059a26 */
if(!s->budget--) { s->failed_pc=0x0c059a26u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a28;
P_0c059a28: /* original 2fa6, guest PC 0x0c059a28 */
if(!s->budget--) { s->failed_pc=0x0c059a28u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2a;
P_0c059a2a: /* original 2f96, guest PC 0x0c059a2a */
if(!s->budget--) { s->failed_pc=0x0c059a2au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2c;
P_0c059a2c: /* original 2f86, guest PC 0x0c059a2c */
if(!s->budget--) { s->failed_pc=0x0c059a2cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a2e;
P_0c059a2e: /* original 4f22, guest PC 0x0c059a2e */
if(!s->budget--) { s->failed_pc=0x0c059a2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059a30;
P_0c059a30: /* original d337, guest PC 0x0c059a30 */
if(!s->budget--) { s->failed_pc=0x0c059a30u; return 0; }
r[3]=read(ram,0x0c059b10u,4);
goto P_0c059a32;
P_0c059a32: /* original 7ff8, guest PC 0x0c059a32 */
if(!s->budget--) { s->failed_pc=0x0c059a32u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059a34;
P_0c059a34: /* original 1f41, guest PC 0x0c059a34 */
if(!s->budget--) { s->failed_pc=0x0c059a34u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c059a36;
P_0c059a36: /* original 6432, guest PC 0x0c059a36 */
if(!s->budget--) { s->failed_pc=0x0c059a36u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c059a38;
P_0c059a38: /* original 6543, guest PC 0x0c059a38 */
if(!s->budget--) { s->failed_pc=0x0c059a38u; return 0; }
r[5]=r[4];
goto P_0c059a3a;
P_0c059a3a: /* original 4508, guest PC 0x0c059a3a */
if(!s->budget--) { s->failed_pc=0x0c059a3au; return 0; }
r[5]<<=2;
goto P_0c059a3c;
P_0c059a3c: /* original d935, guest PC 0x0c059a3c */
if(!s->budget--) { s->failed_pc=0x0c059a3cu; return 0; }
r[9]=read(ram,0x0c059b14u,4);
goto P_0c059a3e;
P_0c059a3e: /* original ee00, guest PC 0x0c059a3e */
if(!s->budget--) { s->failed_pc=0x0c059a3eu; return 0; }
r[14]=0x00000000u;
goto P_0c059a40;
P_0c059a40: /* original db35, guest PC 0x0c059a40 */
if(!s->budget--) { s->failed_pc=0x0c059a40u; return 0; }
r[11]=read(ram,0x0c059b18u,4);
goto P_0c059a42;
P_0c059a42: /* original 395c, guest PC 0x0c059a42 */
if(!s->budget--) { s->failed_pc=0x0c059a42u; return 0; }
r[9]+=r[5];
goto P_0c059a44;
P_0c059a44: /* original d835, guest PC 0x0c059a44 */
if(!s->budget--) { s->failed_pc=0x0c059a44u; return 0; }
r[8]=read(ram,0x0c059b1cu,4);
goto P_0c059a46;
P_0c059a46: /* original 3b5c, guest PC 0x0c059a46 */
if(!s->budget--) { s->failed_pc=0x0c059a46u; return 0; }
r[11]+=r[5];
goto P_0c059a48;
P_0c059a48: /* original da35, guest PC 0x0c059a48 */
if(!s->budget--) { s->failed_pc=0x0c059a48u; return 0; }
r[10]=read(ram,0x0c059b20u,4);
goto P_0c059a4a;
P_0c059a4a: /* original dc36, guest PC 0x0c059a4a */
if(!s->budget--) { s->failed_pc=0x0c059a4au; return 0; }
r[12]=read(ram,0x0c059b24u,4);
goto P_0c059a4c;
P_0c059a4c: /* original 9d5f, guest PC 0x0c059a4c */
if(!s->budget--) { s->failed_pc=0x0c059a4cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059b0eu,2);
goto P_0c059a4e;
P_0c059a4e: /* original 62b2, guest PC 0x0c059a4e */
if(!s->budget--) { s->failed_pc=0x0c059a4eu; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c059a50;
P_0c059a50: /* original 2228, guest PC 0x0c059a50 */
if(!s->budget--) { s->failed_pc=0x0c059a50u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c059a52;
P_0c059a52: /* original 8931, guest PC 0x0c059a52 */
if(!s->budget--) { s->failed_pc=0x0c059a52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059ab8; }
goto P_0c059a54;
P_0c059a54: /* original 53f1, guest PC 0x0c059a54 */
if(!s->budget--) { s->failed_pc=0x0c059a54u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c059a56;
P_0c059a56: /* original 33e0, guest PC 0x0c059a56 */
if(!s->budget--) { s->failed_pc=0x0c059a56u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[14])!=0);
goto P_0c059a58;
P_0c059a58: /* original 892e, guest PC 0x0c059a58 */
if(!s->budget--) { s->failed_pc=0x0c059a58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059ab8; }
goto P_0c059a5a;
P_0c059a5a: /* original d133, guest PC 0x0c059a5a */
if(!s->budget--) { s->failed_pc=0x0c059a5au; return 0; }
r[1]=read(ram,0x0c059b28u,4);
goto P_0c059a5c;
P_0c059a5c: /* original 6012, guest PC 0x0c059a5c */
if(!s->budget--) { s->failed_pc=0x0c059a5cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059a5e;
P_0c059a5e: /* original 8801, guest PC 0x0c059a5e */
if(!s->budget--) { s->failed_pc=0x0c059a5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059a60;
P_0c059a60: /* original 8b1f, guest PC 0x0c059a60 */
if(!s->budget--) { s->failed_pc=0x0c059a60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059aa2; }
goto P_0c059a62;
P_0c059a62: /* original 60e3, guest PC 0x0c059a62 */
if(!s->budget--) { s->failed_pc=0x0c059a62u; return 0; }
r[0]=r[14];
goto P_0c059a64;
P_0c059a64: /* original 0009, guest PC 0x0c059a64 */
if(!s->budget--) { s->failed_pc=0x0c059a64u; return 0; }
goto P_0c059a66;
P_0c059a66: /* original 8801, guest PC 0x0c059a66 */
if(!s->budget--) { s->failed_pc=0x0c059a66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059a68;
P_0c059a68: /* original 8903, guest PC 0x0c059a68 */
if(!s->budget--) { s->failed_pc=0x0c059a68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059a72; }
goto P_0c059a6a;
P_0c059a6a: /* original 60e3, guest PC 0x0c059a6a */
if(!s->budget--) { s->failed_pc=0x0c059a6au; return 0; }
r[0]=r[14];
goto P_0c059a6c;
P_0c059a6c: /* original 0009, guest PC 0x0c059a6c */
if(!s->budget--) { s->failed_pc=0x0c059a6cu; return 0; }
goto P_0c059a6e;
P_0c059a6e: /* original 8803, guest PC 0x0c059a6e */
if(!s->budget--) { s->failed_pc=0x0c059a6eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c059a70;
P_0c059a70: /* original 8b17, guest PC 0x0c059a70 */
if(!s->budget--) { s->failed_pc=0x0c059a70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059aa2; }
goto P_0c059a72;
P_0c059a72: /* original d32e, guest PC 0x0c059a72 */
if(!s->budget--) { s->failed_pc=0x0c059a72u; return 0; }
r[3]=read(ram,0x0c059b2cu,4);
goto P_0c059a74;
P_0c059a74: /* original 6232, guest PC 0x0c059a74 */
if(!s->budget--) { s->failed_pc=0x0c059a74u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059a76;
P_0c059a76: /* original 6033, guest PC 0x0c059a76 */
if(!s->budget--) { s->failed_pc=0x0c059a76u; return 0; }
r[0]=r[3];
goto P_0c059a78;
P_0c059a78: /* original 0009, guest PC 0x0c059a78 */
if(!s->budget--) { s->failed_pc=0x0c059a78u; return 0; }
goto P_0c059a7a;
P_0c059a7a: /* original 6102, guest PC 0x0c059a7a */
if(!s->budget--) { s->failed_pc=0x0c059a7au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059a7c;
P_0c059a7c: /* original 6112, guest PC 0x0c059a7c */
if(!s->budget--) { s->failed_pc=0x0c059a7cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c059a7e;
P_0c059a7e: /* original 63e3, guest PC 0x0c059a7e */
if(!s->budget--) { s->failed_pc=0x0c059a7eu; return 0; }
r[3]=r[14];
goto P_0c059a80;
P_0c059a80: /* original 2189, guest PC 0x0c059a80 */
if(!s->budget--) { s->failed_pc=0x0c059a80u; return 0; }
r[1]&=r[8];
goto P_0c059a82;
P_0c059a82: /* original 4328, guest PC 0x0c059a82 */
if(!s->budget--) { s->failed_pc=0x0c059a82u; return 0; }
r[3]<<=16;
goto P_0c059a84;
P_0c059a84: /* original 4318, guest PC 0x0c059a84 */
if(!s->budget--) { s->failed_pc=0x0c059a84u; return 0; }
r[3]<<=8;
goto P_0c059a86;
P_0c059a86: /* original 213b, guest PC 0x0c059a86 */
if(!s->budget--) { s->failed_pc=0x0c059a86u; return 0; }
r[1]|=r[3];
goto P_0c059a88;
P_0c059a88: /* original 2212, guest PC 0x0c059a88 */
if(!s->budget--) { s->failed_pc=0x0c059a88u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c059a8a;
P_0c059a8a: /* original 63f3, guest PC 0x0c059a8a */
if(!s->budget--) { s->failed_pc=0x0c059a8au; return 0; }
r[3]=r[15];
goto P_0c059a8c;
P_0c059a8c: /* original d228, guest PC 0x0c059a8c */
if(!s->budget--) { s->failed_pc=0x0c059a8cu; return 0; }
r[2]=read(ram,0x0c059b30u,4);
goto P_0c059a8e;
P_0c059a8e: /* original e710, guest PC 0x0c059a8e */
if(!s->budget--) { s->failed_pc=0x0c059a8eu; return 0; }
r[7]=0x00000010u;
goto P_0c059a90;
P_0c059a90: /* original 2f36, guest PC 0x0c059a90 */
if(!s->budget--) { s->failed_pc=0x0c059a90u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059a92;
P_0c059a92: /* original 6622, guest PC 0x0c059a92 */
if(!s->budget--) { s->failed_pc=0x0c059a92u; return 0; }
tmp=read(ram,r[2],4);
r[6]=tmp;
goto P_0c059a94;
P_0c059a94: /* original d325, guest PC 0x0c059a94 */
if(!s->budget--) { s->failed_pc=0x0c059a94u; return 0; }
r[3]=read(ram,0x0c059b2cu,4);
goto P_0c059a96;
P_0c059a96: /* original 6532, guest PC 0x0c059a96 */
if(!s->budget--) { s->failed_pc=0x0c059a96u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c059a98;
P_0c059a98: /* original 4a0b, guest PC 0x0c059a98 */
if(!s->budget--) { s->failed_pc=0x0c059a98u; return 0; }
target=r[10];
r[16]=code_base|0x0c059a9cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059a9cu) { target=s->pc; goto dispatch; }
goto P_0c059a9c;
P_0c059a9a: /* original 64c3, guest PC 0x0c059a9a */
if(!s->budget--) { s->failed_pc=0x0c059a9au; return 0; }
r[4]=r[12];
goto P_0c059a9c;
P_0c059a9c: /* original 30d0, guest PC 0x0c059a9c */
if(!s->budget--) { s->failed_pc=0x0c059a9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c059a9e;
P_0c059a9e: /* original 8df4, guest PC 0x0c059a9e */
if(!s->budget--) { s->failed_pc=0x0c059a9eu; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059a8a; }
goto P_0c059aa2;
P_0c059aa0: /* original 7f04, guest PC 0x0c059aa0 */
if(!s->budget--) { s->failed_pc=0x0c059aa0u; return 0; }
r[15]+=0x00000004u;
goto P_0c059aa2;
P_0c059aa2: /* original 62f3, guest PC 0x0c059aa2 */
if(!s->budget--) { s->failed_pc=0x0c059aa2u; return 0; }
r[2]=r[15];
goto P_0c059aa4;
P_0c059aa4: /* original 2f26, guest PC 0x0c059aa4 */
if(!s->budget--) { s->failed_pc=0x0c059aa4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059aa6;
P_0c059aa6: /* original e710, guest PC 0x0c059aa6 */
if(!s->budget--) { s->failed_pc=0x0c059aa6u; return 0; }
r[7]=0x00000010u;
goto P_0c059aa8;
P_0c059aa8: /* original 66b2, guest PC 0x0c059aa8 */
if(!s->budget--) { s->failed_pc=0x0c059aa8u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c059aaa;
P_0c059aaa: /* original 7620, guest PC 0x0c059aaa */
if(!s->budget--) { s->failed_pc=0x0c059aaau; return 0; }
r[6]+=0x00000020u;
goto P_0c059aac;
P_0c059aac: /* original 6592, guest PC 0x0c059aac */
if(!s->budget--) { s->failed_pc=0x0c059aacu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c059aae;
P_0c059aae: /* original 4a0b, guest PC 0x0c059aae */
if(!s->budget--) { s->failed_pc=0x0c059aaeu; return 0; }
target=r[10];
r[16]=code_base|0x0c059ab2u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059ab2u) { target=s->pc; goto dispatch; }
goto P_0c059ab2;
P_0c059ab0: /* original 64c3, guest PC 0x0c059ab0 */
if(!s->budget--) { s->failed_pc=0x0c059ab0u; return 0; }
r[4]=r[12];
goto P_0c059ab2;
P_0c059ab2: /* original 30d0, guest PC 0x0c059ab2 */
if(!s->budget--) { s->failed_pc=0x0c059ab2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[13])!=0);
goto P_0c059ab4;
P_0c059ab4: /* original 8df5, guest PC 0x0c059ab4 */
if(!s->budget--) { s->failed_pc=0x0c059ab4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059aa2; }
goto P_0c059ab8;
P_0c059ab6: /* original 7f04, guest PC 0x0c059ab6 */
if(!s->budget--) { s->failed_pc=0x0c059ab6u; return 0; }
r[15]+=0x00000004u;
goto P_0c059ab8;
P_0c059ab8: /* original 7b10, guest PC 0x0c059ab8 */
if(!s->budget--) { s->failed_pc=0x0c059ab8u; return 0; }
r[11]+=0x00000010u;
goto P_0c059aba;
P_0c059aba: /* original 7e01, guest PC 0x0c059aba */
if(!s->budget--) { s->failed_pc=0x0c059abau; return 0; }
r[14]+=0x00000001u;
goto P_0c059abc;
P_0c059abc: /* original e205, guest PC 0x0c059abc */
if(!s->budget--) { s->failed_pc=0x0c059abcu; return 0; }
r[2]=0x00000005u;
goto P_0c059abe;
P_0c059abe: /* original 3e22, guest PC 0x0c059abe */
if(!s->budget--) { s->failed_pc=0x0c059abeu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>=r[2])!=0);
goto P_0c059ac0;
P_0c059ac0: /* original 8fc5, guest PC 0x0c059ac0 */
if(!s->budget--) { s->failed_pc=0x0c059ac0u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000010u;
if(!cond) { goto P_0c059a4e; }
goto P_0c059ac4;
P_0c059ac2: /* original 7910, guest PC 0x0c059ac2 */
if(!s->budget--) { s->failed_pc=0x0c059ac2u; return 0; }
r[9]+=0x00000010u;
goto P_0c059ac4;
P_0c059ac4: /* original 7f08, guest PC 0x0c059ac4 */
if(!s->budget--) { s->failed_pc=0x0c059ac4u; return 0; }
r[15]+=0x00000008u;
goto P_0c059ac6;
P_0c059ac6: /* original 4f26, guest PC 0x0c059ac6 */
if(!s->budget--) { s->failed_pc=0x0c059ac6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059ac8;
P_0c059ac8: /* original 68f6, guest PC 0x0c059ac8 */
if(!s->budget--) { s->failed_pc=0x0c059ac8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c059aca;
P_0c059aca: /* original 69f6, guest PC 0x0c059aca */
if(!s->budget--) { s->failed_pc=0x0c059acau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c059acc;
P_0c059acc: /* original 6af6, guest PC 0x0c059acc */
if(!s->budget--) { s->failed_pc=0x0c059accu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c059ace;
P_0c059ace: /* original 6bf6, guest PC 0x0c059ace */
if(!s->budget--) { s->failed_pc=0x0c059aceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c059ad0;
P_0c059ad0: /* original 6cf6, guest PC 0x0c059ad0 */
if(!s->budget--) { s->failed_pc=0x0c059ad0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059ad2;
P_0c059ad2: /* original 6df6, guest PC 0x0c059ad2 */
if(!s->budget--) { s->failed_pc=0x0c059ad2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059ad4;
P_0c059ad4: /* original 000b, guest PC 0x0c059ad4 */
if(!s->budget--) { s->failed_pc=0x0c059ad4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059ad6: /* original 6ef6, guest PC 0x0c059ad6 */
if(!s->budget--) { s->failed_pc=0x0c059ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c059ad8;
P_0c059ad8: /* original 2fe6, guest PC 0x0c059ad8 */
if(!s->budget--) { s->failed_pc=0x0c059ad8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059ada;
P_0c059ada: /* original 2fd6, guest PC 0x0c059ada */
if(!s->budget--) { s->failed_pc=0x0c059adau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059adc;
P_0c059adc: /* original 2fc6, guest PC 0x0c059adc */
if(!s->budget--) { s->failed_pc=0x0c059adcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059ade;
P_0c059ade: /* original ec00, guest PC 0x0c059ade */
if(!s->budget--) { s->failed_pc=0x0c059adeu; return 0; }
r[12]=0x00000000u;
goto P_0c059ae0;
P_0c059ae0: /* original d214, guest PC 0x0c059ae0 */
if(!s->budget--) { s->failed_pc=0x0c059ae0u; return 0; }
r[2]=read(ram,0x0c059b34u,4);
goto P_0c059ae2;
P_0c059ae2: /* original 2fb6, guest PC 0x0c059ae2 */
if(!s->budget--) { s->failed_pc=0x0c059ae2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059ae4;
P_0c059ae4: /* original 2fa6, guest PC 0x0c059ae4 */
if(!s->budget--) { s->failed_pc=0x0c059ae4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059ae6;
P_0c059ae6: /* original 2f96, guest PC 0x0c059ae6 */
if(!s->budget--) { s->failed_pc=0x0c059ae6u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059ae8;
P_0c059ae8: /* original 2f86, guest PC 0x0c059ae8 */
if(!s->budget--) { s->failed_pc=0x0c059ae8u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059aea;
P_0c059aea: /* original 4f22, guest PC 0x0c059aea */
if(!s->budget--) { s->failed_pc=0x0c059aeau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059aec;
P_0c059aec: /* original 7ff8, guest PC 0x0c059aec */
if(!s->budget--) { s->failed_pc=0x0c059aecu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c059aee;
P_0c059aee: /* original 6322, guest PC 0x0c059aee */
if(!s->budget--) { s->failed_pc=0x0c059aeeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059af0;
P_0c059af0: /* original 2338, guest PC 0x0c059af0 */
if(!s->budget--) { s->failed_pc=0x0c059af0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059af2;
P_0c059af2: /* original 8f74, guest PC 0x0c059af2 */
if(!s->budget--) { s->failed_pc=0x0c059af2u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c059bde; }
goto P_0c059af6;
P_0c059af4: /* original ed01, guest PC 0x0c059af4 */
if(!s->budget--) { s->failed_pc=0x0c059af4u; return 0; }
r[13]=0x00000001u;
goto P_0c059af6;
P_0c059af6: /* original d110, guest PC 0x0c059af6 */
if(!s->budget--) { s->failed_pc=0x0c059af6u; return 0; }
r[1]=read(ram,0x0c059b38u,4);
goto P_0c059af8;
P_0c059af8: /* original 6312, guest PC 0x0c059af8 */
if(!s->budget--) { s->failed_pc=0x0c059af8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059afa;
P_0c059afa: /* original 2338, guest PC 0x0c059afa */
if(!s->budget--) { s->failed_pc=0x0c059afau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059afc;
P_0c059afc: /* original 8b20, guest PC 0x0c059afc */
if(!s->budget--) { s->failed_pc=0x0c059afcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059b40; }
goto P_0c059afe;
P_0c059afe: /* original d004, guest PC 0x0c059afe */
if(!s->budget--) { s->failed_pc=0x0c059afeu; return 0; }
r[0]=read(ram,0x0c059b10u,4);
goto P_0c059b00;
P_0c059b00: /* original 6302, guest PC 0x0c059b00 */
if(!s->budget--) { s->failed_pc=0x0c059b00u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b02;
P_0c059b02: /* original 70f0, guest PC 0x0c059b02 */
if(!s->budget--) { s->failed_pc=0x0c059b02u; return 0; }
r[0]+=0xfffffff0u;
goto P_0c059b04;
P_0c059b04: /* original 4308, guest PC 0x0c059b04 */
if(!s->budget--) { s->failed_pc=0x0c059b04u; return 0; }
r[3]<<=2;
goto P_0c059b06;
P_0c059b06: /* original 03d6, guest PC 0x0c059b06 */
if(!s->budget--) { s->failed_pc=0x0c059b06u; return 0; }
write(ram,r[3]+r[0],r[13],4);
goto P_0c059b08;
P_0c059b08: /* original d30c, guest PC 0x0c059b08 */
if(!s->budget--) { s->failed_pc=0x0c059b08u; return 0; }
r[3]=read(ram,0x0c059b3cu,4);
goto P_0c059b0a;
P_0c059b0a: /* original a068, guest PC 0x0c059b0a */
if(!s->budget--) { s->failed_pc=0x0c059b0au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c059bde;
P_0c059b0c: /* original 23d2, guest PC 0x0c059b0c */
if(!s->budget--) { s->failed_pc=0x0c059b0cu; return 0; }
write(ram,r[3],r[13],4);
if(!vf3_matrix_family(0x0c059b0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059b0eu; return 0; } return 1;
P_0c059b40: /* original d538, guest PC 0x0c059b40 */
if(!s->budget--) { s->failed_pc=0x0c059b40u; return 0; }
r[5]=read(ram,0x0c059c24u,4);
goto P_0c059b42;
P_0c059b42: /* original d039, guest PC 0x0c059b42 */
if(!s->budget--) { s->failed_pc=0x0c059b42u; return 0; }
r[0]=read(ram,0x0c059c28u,4);
goto P_0c059b44;
P_0c059b44: /* original d239, guest PC 0x0c059b44 */
if(!s->budget--) { s->failed_pc=0x0c059b44u; return 0; }
r[2]=read(ram,0x0c059c2cu,4);
goto P_0c059b46;
P_0c059b46: /* original 6302, guest PC 0x0c059b46 */
if(!s->budget--) { s->failed_pc=0x0c059b46u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b48;
P_0c059b48: /* original e048, guest PC 0x0c059b48 */
if(!s->budget--) { s->failed_pc=0x0c059b48u; return 0; }
r[0]=0x00000048u;
goto P_0c059b4a;
P_0c059b4a: /* original 0536, guest PC 0x0c059b4a */
if(!s->budget--) { s->failed_pc=0x0c059b4au; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c059b4c;
P_0c059b4c: /* original 6422, guest PC 0x0c059b4c */
if(!s->budget--) { s->failed_pc=0x0c059b4cu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c059b4e;
P_0c059b4e: /* original d338, guest PC 0x0c059b4e */
if(!s->budget--) { s->failed_pc=0x0c059b4eu; return 0; }
r[3]=read(ram,0x0c059c30u,4);
goto P_0c059b50;
P_0c059b50: /* original 2342, guest PC 0x0c059b50 */
if(!s->budget--) { s->failed_pc=0x0c059b50u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c059b52;
P_0c059b52: /* original d138, guest PC 0x0c059b52 */
if(!s->budget--) { s->failed_pc=0x0c059b52u; return 0; }
r[1]=read(ram,0x0c059c34u,4);
goto P_0c059b54;
P_0c059b54: /* original 21d2, guest PC 0x0c059b54 */
if(!s->budget--) { s->failed_pc=0x0c059b54u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c059b56;
P_0c059b56: /* original d238, guest PC 0x0c059b56 */
if(!s->budget--) { s->failed_pc=0x0c059b56u; return 0; }
r[2]=read(ram,0x0c059c38u,4);
goto P_0c059b58;
P_0c059b58: /* original 22c2, guest PC 0x0c059b58 */
if(!s->budget--) { s->failed_pc=0x0c059b58u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c059b5a;
P_0c059b5a: /* original d038, guest PC 0x0c059b5a */
if(!s->budget--) { s->failed_pc=0x0c059b5au; return 0; }
r[0]=read(ram,0x0c059c3cu,4);
goto P_0c059b5c;
P_0c059b5c: /* original 6302, guest PC 0x0c059b5c */
if(!s->budget--) { s->failed_pc=0x0c059b5cu; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059b5e;
P_0c059b5e: /* original d138, guest PC 0x0c059b5e */
if(!s->budget--) { s->failed_pc=0x0c059b5eu; return 0; }
r[1]=read(ram,0x0c059c40u,4);
goto P_0c059b60;
P_0c059b60: /* original 2132, guest PC 0x0c059b60 */
if(!s->budget--) { s->failed_pc=0x0c059b60u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059b62;
P_0c059b62: /* original 7208, guest PC 0x0c059b62 */
if(!s->budget--) { s->failed_pc=0x0c059b62u; return 0; }
r[2]+=0x00000008u;
goto P_0c059b64;
P_0c059b64: /* original 22d2, guest PC 0x0c059b64 */
if(!s->budget--) { s->failed_pc=0x0c059b64u; return 0; }
write(ram,r[2],r[13],4);
goto P_0c059b66;
P_0c059b66: /* original 4408, guest PC 0x0c059b66 */
if(!s->budget--) { s->failed_pc=0x0c059b66u; return 0; }
r[4]<<=2;
goto P_0c059b68;
P_0c059b68: /* original 15c1, guest PC 0x0c059b68 */
if(!s->budget--) { s->failed_pc=0x0c059b68u; return 0; }
write(ram,r[5]+4,r[12],4);
goto P_0c059b6a;
P_0c059b6a: /* original e302, guest PC 0x0c059b6a */
if(!s->budget--) { s->failed_pc=0x0c059b6au; return 0; }
r[3]=0x00000002u;
goto P_0c059b6c;
P_0c059b6c: /* original d035, guest PC 0x0c059b6c */
if(!s->budget--) { s->failed_pc=0x0c059b6cu; return 0; }
r[0]=read(ram,0x0c059c44u,4);
goto P_0c059b6e;
P_0c059b6e: /* original 0436, guest PC 0x0c059b6e */
if(!s->budget--) { s->failed_pc=0x0c059b6eu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c059b70;
P_0c059b70: /* original d135, guest PC 0x0c059b70 */
if(!s->budget--) { s->failed_pc=0x0c059b70u; return 0; }
r[1]=read(ram,0x0c059c48u,4);
goto P_0c059b72;
P_0c059b72: /* original 6012, guest PC 0x0c059b72 */
if(!s->budget--) { s->failed_pc=0x0c059b72u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059b74;
P_0c059b74: /* original c820, guest PC 0x0c059b74 */
if(!s->budget--) { s->failed_pc=0x0c059b74u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c059b76;
P_0c059b76: /* original 890d, guest PC 0x0c059b76 */
if(!s->budget--) { s->failed_pc=0x0c059b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059b94; }
goto P_0c059b78;
P_0c059b78: /* original d034, guest PC 0x0c059b78 */
if(!s->budget--) { s->failed_pc=0x0c059b78u; return 0; }
r[0]=read(ram,0x0c059c4cu,4);
goto P_0c059b7a;
P_0c059b7a: /* original e410, guest PC 0x0c059b7a */
if(!s->budget--) { s->failed_pc=0x0c059b7au; return 0; }
r[4]=0x00000010u;
goto P_0c059b7c;
P_0c059b7c: /* original 2042, guest PC 0x0c059b7c */
if(!s->budget--) { s->failed_pc=0x0c059b7cu; return 0; }
write(ram,r[0],r[4],4);
goto P_0c059b7e;
P_0c059b7e: /* original d334, guest PC 0x0c059b7e */
if(!s->budget--) { s->failed_pc=0x0c059b7eu; return 0; }
r[3]=read(ram,0x0c059c50u,4);
goto P_0c059b80;
P_0c059b80: /* original 2342, guest PC 0x0c059b80 */
if(!s->budget--) { s->failed_pc=0x0c059b80u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c059b82;
P_0c059b82: /* original d534, guest PC 0x0c059b82 */
if(!s->budget--) { s->failed_pc=0x0c059b82u; return 0; }
r[5]=read(ram,0x0c059c54u,4);
goto P_0c059b84;
P_0c059b84: /* original d434, guest PC 0x0c059b84 */
if(!s->budget--) { s->failed_pc=0x0c059b84u; return 0; }
r[4]=read(ram,0x0c059c58u,4);
goto P_0c059b86;
P_0c059b86: /* original d235, guest PC 0x0c059b86 */
if(!s->budget--) { s->failed_pc=0x0c059b86u; return 0; }
r[2]=read(ram,0x0c059c5cu,4);
goto P_0c059b88;
P_0c059b88: /* original 420b, guest PC 0x0c059b88 */
if(!s->budget--) { s->failed_pc=0x0c059b88u; return 0; }
target=r[2];
r[16]=code_base|0x0c059b8cu;
r[6]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059b8cu) { target=s->pc; goto dispatch; }
goto P_0c059b8c;
P_0c059b8a: /* original e604, guest PC 0x0c059b8a */
if(!s->budget--) { s->failed_pc=0x0c059b8au; return 0; }
r[6]=0x00000004u;
goto P_0c059b8c;
P_0c059b8c: /* original d332, guest PC 0x0c059b8c */
if(!s->budget--) { s->failed_pc=0x0c059b8cu; return 0; }
r[3]=read(ram,0x0c059c58u,4);
goto P_0c059b8e;
P_0c059b8e: /* original 0383, guest PC 0x0c059b8e */
if(!s->budget--) { s->failed_pc=0x0c059b8eu; return 0; }
if((r[3]&0xFC000000u)==0xE0000000u) pref(ram,r[3]);
goto P_0c059b90;
P_0c059b90: /* original a022, guest PC 0x0c059b90 */
if(!s->budget--) { s->failed_pc=0x0c059b90u; return 0; }
goto P_0c059bd8;
P_0c059b92: /* original 0009, guest PC 0x0c059b92 */
if(!s->budget--) { s->failed_pc=0x0c059b92u; return 0; }
goto P_0c059b94;
P_0c059b94: /* original d025, guest PC 0x0c059b94 */
if(!s->budget--) { s->failed_pc=0x0c059b94u; return 0; }
r[0]=read(ram,0x0c059c2cu,4);
goto P_0c059b96;
P_0c059b96: /* original 6902, guest PC 0x0c059b96 */
if(!s->budget--) { s->failed_pc=0x0c059b96u; return 0; }
tmp=read(ram,r[0],4);
r[9]=tmp;
goto P_0c059b98;
P_0c059b98: /* original d331, guest PC 0x0c059b98 */
if(!s->budget--) { s->failed_pc=0x0c059b98u; return 0; }
r[3]=read(ram,0x0c059c60u,4);
goto P_0c059b9a;
P_0c059b9a: /* original 6203, guest PC 0x0c059b9a */
if(!s->budget--) { s->failed_pc=0x0c059b9au; return 0; }
r[2]=r[0];
goto P_0c059b9c;
P_0c059b9c: /* original 6a22, guest PC 0x0c059b9c */
if(!s->budget--) { s->failed_pc=0x0c059b9cu; return 0; }
tmp=read(ram,r[2],4);
r[10]=tmp;
goto P_0c059b9e;
P_0c059b9e: /* original 4908, guest PC 0x0c059b9e */
if(!s->budget--) { s->failed_pc=0x0c059b9eu; return 0; }
r[9]<<=2;
goto P_0c059ba0;
P_0c059ba0: /* original d030, guest PC 0x0c059ba0 */
if(!s->budget--) { s->failed_pc=0x0c059ba0u; return 0; }
r[0]=read(ram,0x0c059c64u,4);
goto P_0c059ba2;
P_0c059ba2: /* original 4a08, guest PC 0x0c059ba2 */
if(!s->budget--) { s->failed_pc=0x0c059ba2u; return 0; }
r[10]<<=2;
goto P_0c059ba4;
P_0c059ba4: /* original 393c, guest PC 0x0c059ba4 */
if(!s->budget--) { s->failed_pc=0x0c059ba4u; return 0; }
r[9]+=r[3];
goto P_0c059ba6;
P_0c059ba6: /* original 7350, guest PC 0x0c059ba6 */
if(!s->budget--) { s->failed_pc=0x0c059ba6u; return 0; }
r[3]+=0x00000050u;
goto P_0c059ba8;
P_0c059ba8: /* original 3a3c, guest PC 0x0c059ba8 */
if(!s->budget--) { s->failed_pc=0x0c059ba8u; return 0; }
r[10]+=r[3];
goto P_0c059baa;
P_0c059baa: /* original 6102, guest PC 0x0c059baa */
if(!s->budget--) { s->failed_pc=0x0c059baau; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059bac;
P_0c059bac: /* original 4108, guest PC 0x0c059bac */
if(!s->budget--) { s->failed_pc=0x0c059bacu; return 0; }
r[1]<<=2;
goto P_0c059bae;
P_0c059bae: /* original 4108, guest PC 0x0c059bae */
if(!s->budget--) { s->failed_pc=0x0c059baeu; return 0; }
r[1]<<=2;
goto P_0c059bb0;
P_0c059bb0: /* original 3a1c, guest PC 0x0c059bb0 */
if(!s->budget--) { s->failed_pc=0x0c059bb0u; return 0; }
r[10]+=r[1];
goto P_0c059bb2;
P_0c059bb2: /* original 6103, guest PC 0x0c059bb2 */
if(!s->budget--) { s->failed_pc=0x0c059bb2u; return 0; }
r[1]=r[0];
goto P_0c059bb4;
P_0c059bb4: /* original 6312, guest PC 0x0c059bb4 */
if(!s->budget--) { s->failed_pc=0x0c059bb4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059bb6;
P_0c059bb6: /* original 4308, guest PC 0x0c059bb6 */
if(!s->budget--) { s->failed_pc=0x0c059bb6u; return 0; }
r[3]<<=2;
goto P_0c059bb8;
P_0c059bb8: /* original d82b, guest PC 0x0c059bb8 */
if(!s->budget--) { s->failed_pc=0x0c059bb8u; return 0; }
r[8]=read(ram,0x0c059c68u,4);
goto P_0c059bba;
P_0c059bba: /* original 4308, guest PC 0x0c059bba */
if(!s->budget--) { s->failed_pc=0x0c059bbau; return 0; }
r[3]<<=2;
goto P_0c059bbc;
P_0c059bbc: /* original db2b, guest PC 0x0c059bbc */
if(!s->budget--) { s->failed_pc=0x0c059bbcu; return 0; }
r[11]=read(ram,0x0c059c6cu,4);
goto P_0c059bbe;
P_0c059bbe: /* original 393c, guest PC 0x0c059bbe */
if(!s->budget--) { s->failed_pc=0x0c059bbeu; return 0; }
r[9]+=r[3];
goto P_0c059bc0;
P_0c059bc0: /* original 9e2e, guest PC 0x0c059bc0 */
if(!s->budget--) { s->failed_pc=0x0c059bc0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059c20u,2);
goto P_0c059bc2;
P_0c059bc2: /* original 62f3, guest PC 0x0c059bc2 */
if(!s->budget--) { s->failed_pc=0x0c059bc2u; return 0; }
r[2]=r[15];
goto P_0c059bc4;
P_0c059bc4: /* original 2f26, guest PC 0x0c059bc4 */
if(!s->budget--) { s->failed_pc=0x0c059bc4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059bc6;
P_0c059bc6: /* original e710, guest PC 0x0c059bc6 */
if(!s->budget--) { s->failed_pc=0x0c059bc6u; return 0; }
r[7]=0x00000010u;
goto P_0c059bc8;
P_0c059bc8: /* original 66a2, guest PC 0x0c059bc8 */
if(!s->budget--) { s->failed_pc=0x0c059bc8u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c059bca;
P_0c059bca: /* original 7620, guest PC 0x0c059bca */
if(!s->budget--) { s->failed_pc=0x0c059bcau; return 0; }
r[6]+=0x00000020u;
goto P_0c059bcc;
P_0c059bcc: /* original 6592, guest PC 0x0c059bcc */
if(!s->budget--) { s->failed_pc=0x0c059bccu; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c059bce;
P_0c059bce: /* original 480b, guest PC 0x0c059bce */
if(!s->budget--) { s->failed_pc=0x0c059bceu; return 0; }
target=r[8];
r[16]=code_base|0x0c059bd2u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059bd2u) { target=s->pc; goto dispatch; }
goto P_0c059bd2;
P_0c059bd0: /* original 64b3, guest PC 0x0c059bd0 */
if(!s->budget--) { s->failed_pc=0x0c059bd0u; return 0; }
r[4]=r[11];
goto P_0c059bd2;
P_0c059bd2: /* original 30e0, guest PC 0x0c059bd2 */
if(!s->budget--) { s->failed_pc=0x0c059bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[14])!=0);
goto P_0c059bd4;
P_0c059bd4: /* original 8df5, guest PC 0x0c059bd4 */
if(!s->budget--) { s->failed_pc=0x0c059bd4u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c059bc2; }
goto P_0c059bd8;
P_0c059bd6: /* original 7f04, guest PC 0x0c059bd6 */
if(!s->budget--) { s->failed_pc=0x0c059bd6u; return 0; }
r[15]+=0x00000004u;
goto P_0c059bd8;
P_0c059bd8: /* original d222, guest PC 0x0c059bd8 */
if(!s->budget--) { s->failed_pc=0x0c059bd8u; return 0; }
r[2]=read(ram,0x0c059c64u,4);
goto P_0c059bda;
P_0c059bda: /* original bf21, guest PC 0x0c059bda */
if(!s->budget--) { s->failed_pc=0x0c059bdau; return 0; }
target=code_base|0x0c059a20u; r[16]=code_base|0x0c059bdeu;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059bdeu) { target=s->pc; goto dispatch; }
goto P_0c059bde;
P_0c059bdc: /* original 6422, guest PC 0x0c059bdc */
if(!s->budget--) { s->failed_pc=0x0c059bdcu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c059bde;
P_0c059bde: /* original d124, guest PC 0x0c059bde */
if(!s->budget--) { s->failed_pc=0x0c059bdeu; return 0; }
r[1]=read(ram,0x0c059c70u,4);
goto P_0c059be0;
P_0c059be0: /* original 21c2, guest PC 0x0c059be0 */
if(!s->budget--) { s->failed_pc=0x0c059be0u; return 0; }
write(ram,r[1],r[12],4);
goto P_0c059be2;
P_0c059be2: /* original a010, guest PC 0x0c059be2 */
if(!s->budget--) { s->failed_pc=0x0c059be2u; return 0; }
r[14]=0x00000000u;
goto P_0c059c06;
P_0c059be4: /* original ee00, guest PC 0x0c059be4 */
if(!s->budget--) { s->failed_pc=0x0c059be4u; return 0; }
r[14]=0x00000000u;
goto P_0c059be6;
P_0c059be6: /* original d223, guest PC 0x0c059be6 */
if(!s->budget--) { s->failed_pc=0x0c059be6u; return 0; }
r[2]=read(ram,0x0c059c74u,4);
goto P_0c059be8;
P_0c059be8: /* original 6322, guest PC 0x0c059be8 */
if(!s->budget--) { s->failed_pc=0x0c059be8u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059bea;
P_0c059bea: /* original 430b, guest PC 0x0c059bea */
if(!s->budget--) { s->failed_pc=0x0c059beau; return 0; }
target=r[3];
r[16]=code_base|0x0c059beeu;
r[4]=read(ram,r[2]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059beeu) { target=s->pc; goto dispatch; }
goto P_0c059bee;
P_0c059bec: /* original 5421, guest PC 0x0c059bec */
if(!s->budget--) { s->failed_pc=0x0c059becu; return 0; }
r[4]=read(ram,r[2]+4,4);
goto P_0c059bee;
P_0c059bee: /* original d022, guest PC 0x0c059bee */
if(!s->budget--) { s->failed_pc=0x0c059beeu; return 0; }
r[0]=read(ram,0x0c059c78u,4);
goto P_0c059bf0;
P_0c059bf0: /* original 6302, guest PC 0x0c059bf0 */
if(!s->budget--) { s->failed_pc=0x0c059bf0u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059bf2;
P_0c059bf2: /* original d222, guest PC 0x0c059bf2 */
if(!s->budget--) { s->failed_pc=0x0c059bf2u; return 0; }
r[2]=read(ram,0x0c059c7cu,4);
goto P_0c059bf4;
P_0c059bf4: /* original 6122, guest PC 0x0c059bf4 */
if(!s->budget--) { s->failed_pc=0x0c059bf4u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c059bf6;
P_0c059bf6: /* original 313c, guest PC 0x0c059bf6 */
if(!s->budget--) { s->failed_pc=0x0c059bf6u; return 0; }
r[1]+=r[3];
goto P_0c059bf8;
P_0c059bf8: /* original d21d, guest PC 0x0c059bf8 */
if(!s->budget--) { s->failed_pc=0x0c059bf8u; return 0; }
r[2]=read(ram,0x0c059c70u,4);
goto P_0c059bfa;
P_0c059bfa: /* original 7101, guest PC 0x0c059bfa */
if(!s->budget--) { s->failed_pc=0x0c059bfau; return 0; }
r[1]+=0x00000001u;
goto P_0c059bfc;
P_0c059bfc: /* original 6322, guest PC 0x0c059bfc */
if(!s->budget--) { s->failed_pc=0x0c059bfcu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059bfe;
P_0c059bfe: /* original 3316, guest PC 0x0c059bfe */
if(!s->budget--) { s->failed_pc=0x0c059bfeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c059c00;
P_0c059c00: /* original 8b01, guest PC 0x0c059c00 */
if(!s->budget--) { s->failed_pc=0x0c059c00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c06; }
goto P_0c059c02;
P_0c059c02: /* original a004, guest PC 0x0c059c02 */
if(!s->budget--) { s->failed_pc=0x0c059c02u; return 0; }
r[14]=0x00000001u;
goto P_0c059c0e;
P_0c059c04: /* original ee01, guest PC 0x0c059c04 */
if(!s->budget--) { s->failed_pc=0x0c059c04u; return 0; }
r[14]=0x00000001u;
goto P_0c059c06;
P_0c059c06: /* original d31e, guest PC 0x0c059c06 */
if(!s->budget--) { s->failed_pc=0x0c059c06u; return 0; }
r[3]=read(ram,0x0c059c80u,4);
goto P_0c059c08;
P_0c059c08: /* original 6232, guest PC 0x0c059c08 */
if(!s->budget--) { s->failed_pc=0x0c059c08u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059c0a;
P_0c059c0a: /* original 2228, guest PC 0x0c059c0a */
if(!s->budget--) { s->failed_pc=0x0c059c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c059c0c;
P_0c059c0c: /* original 8beb, guest PC 0x0c059c0c */
if(!s->budget--) { s->failed_pc=0x0c059c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059be6; }
goto P_0c059c0e;
P_0c059c0e: /* original 2ee8, guest PC 0x0c059c0e */
if(!s->budget--) { s->failed_pc=0x0c059c0eu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c059c10;
P_0c059c10: /* original 894d, guest PC 0x0c059c10 */
if(!s->budget--) { s->failed_pc=0x0c059c10u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cae; }
goto P_0c059c12;
P_0c059c12: /* original d31c, guest PC 0x0c059c12 */
if(!s->budget--) { s->failed_pc=0x0c059c12u; return 0; }
r[3]=read(ram,0x0c059c84u,4);
goto P_0c059c14;
P_0c059c14: /* original 23c2, guest PC 0x0c059c14 */
if(!s->budget--) { s->failed_pc=0x0c059c14u; return 0; }
write(ram,r[3],r[12],4);
goto P_0c059c16;
P_0c059c16: /* original d216, guest PC 0x0c059c16 */
if(!s->budget--) { s->failed_pc=0x0c059c16u; return 0; }
r[2]=read(ram,0x0c059c70u,4);
goto P_0c059c18;
P_0c059c18: /* original 22c2, guest PC 0x0c059c18 */
if(!s->budget--) { s->failed_pc=0x0c059c18u; return 0; }
write(ram,r[2],r[12],4);
goto P_0c059c1a;
P_0c059c1a: /* original eb00, guest PC 0x0c059c1a */
if(!s->budget--) { s->failed_pc=0x0c059c1au; return 0; }
r[11]=0x00000000u;
goto P_0c059c1c;
P_0c059c1c: /* original a03e, guest PC 0x0c059c1c */
if(!s->budget--) { s->failed_pc=0x0c059c1cu; return 0; }
r[14]=0x00000014u;
goto P_0c059c9c;
P_0c059c1e: /* original ee14, guest PC 0x0c059c1e */
if(!s->budget--) { s->failed_pc=0x0c059c1eu; return 0; }
r[14]=0x00000014u;
if(!vf3_matrix_family(0x0c059c20u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059c20u; return 0; } return 1;
P_0c059c88: /* original d340, guest PC 0x0c059c88 */
if(!s->budget--) { s->failed_pc=0x0c059c88u; return 0; }
r[3]=read(ram,0x0c059d8cu,4);
goto P_0c059c8a;
P_0c059c8a: /* original 6232, guest PC 0x0c059c8a */
if(!s->budget--) { s->failed_pc=0x0c059c8au; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059c8c;
P_0c059c8c: /* original 420b, guest PC 0x0c059c8c */
if(!s->budget--) { s->failed_pc=0x0c059c8cu; return 0; }
target=r[2];
r[16]=code_base|0x0c059c90u;
r[4]=read(ram,r[3]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059c90u) { target=s->pc; goto dispatch; }
goto P_0c059c90;
P_0c059c8e: /* original 5431, guest PC 0x0c059c8e */
if(!s->budget--) { s->failed_pc=0x0c059c8eu; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c059c90;
P_0c059c90: /* original d23f, guest PC 0x0c059c90 */
if(!s->budget--) { s->failed_pc=0x0c059c90u; return 0; }
r[2]=read(ram,0x0c059d90u,4);
goto P_0c059c92;
P_0c059c92: /* original 6122, guest PC 0x0c059c92 */
if(!s->budget--) { s->failed_pc=0x0c059c92u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c059c94;
P_0c059c94: /* original 31e6, guest PC 0x0c059c94 */
if(!s->budget--) { s->failed_pc=0x0c059c94u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[14])!=0);
goto P_0c059c96;
P_0c059c96: /* original 8b01, guest PC 0x0c059c96 */
if(!s->budget--) { s->failed_pc=0x0c059c96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c9c; }
goto P_0c059c98;
P_0c059c98: /* original a004, guest PC 0x0c059c98 */
if(!s->budget--) { s->failed_pc=0x0c059c98u; return 0; }
r[11]=0x00000001u;
goto P_0c059ca4;
P_0c059c9a: /* original eb01, guest PC 0x0c059c9a */
if(!s->budget--) { s->failed_pc=0x0c059c9au; return 0; }
r[11]=0x00000001u;
goto P_0c059c9c;
P_0c059c9c: /* original d23d, guest PC 0x0c059c9c */
if(!s->budget--) { s->failed_pc=0x0c059c9cu; return 0; }
r[2]=read(ram,0x0c059d94u,4);
goto P_0c059c9e;
P_0c059c9e: /* original 6322, guest PC 0x0c059c9e */
if(!s->budget--) { s->failed_pc=0x0c059c9eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059ca0;
P_0c059ca0: /* original 2338, guest PC 0x0c059ca0 */
if(!s->budget--) { s->failed_pc=0x0c059ca0u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059ca2;
P_0c059ca2: /* original 8bf1, guest PC 0x0c059ca2 */
if(!s->budget--) { s->failed_pc=0x0c059ca2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059c88; }
goto P_0c059ca4;
P_0c059ca4: /* original 2bb8, guest PC 0x0c059ca4 */
if(!s->budget--) { s->failed_pc=0x0c059ca4u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c059ca6;
P_0c059ca6: /* original 8902, guest PC 0x0c059ca6 */
if(!s->budget--) { s->failed_pc=0x0c059ca6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cae; }
goto P_0c059ca8;
P_0c059ca8: /* original d23b, guest PC 0x0c059ca8 */
if(!s->budget--) { s->failed_pc=0x0c059ca8u; return 0; }
r[2]=read(ram,0x0c059d98u,4);
goto P_0c059caa;
P_0c059caa: /* original 420b, guest PC 0x0c059caa */
if(!s->budget--) { s->failed_pc=0x0c059caau; return 0; }
target=r[2];
r[16]=code_base|0x0c059caeu;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059caeu) { target=s->pc; goto dispatch; }
goto P_0c059cae;
P_0c059cac: /* original e404, guest PC 0x0c059cac */
if(!s->budget--) { s->failed_pc=0x0c059cacu; return 0; }
r[4]=0x00000004u;
goto P_0c059cae;
P_0c059cae: /* original d33b, guest PC 0x0c059cae */
if(!s->budget--) { s->failed_pc=0x0c059caeu; return 0; }
r[3]=read(ram,0x0c059d9cu,4);
goto P_0c059cb0;
P_0c059cb0: /* original 6232, guest PC 0x0c059cb0 */
if(!s->budget--) { s->failed_pc=0x0c059cb0u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cb2;
P_0c059cb2: /* original 7201, guest PC 0x0c059cb2 */
if(!s->budget--) { s->failed_pc=0x0c059cb2u; return 0; }
r[2]+=0x00000001u;
goto P_0c059cb4;
P_0c059cb4: /* original 2322, guest PC 0x0c059cb4 */
if(!s->budget--) { s->failed_pc=0x0c059cb4u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059cb6;
P_0c059cb6: /* original 6032, guest PC 0x0c059cb6 */
if(!s->budget--) { s->failed_pc=0x0c059cb6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c059cb8;
P_0c059cb8: /* original c903, guest PC 0x0c059cb8 */
if(!s->budget--) { s->failed_pc=0x0c059cb8u; return 0; }
r[0]&=3u;
goto P_0c059cba;
P_0c059cba: /* original 2302, guest PC 0x0c059cba */
if(!s->budget--) { s->failed_pc=0x0c059cbau; return 0; }
write(ram,r[3],r[0],4);
goto P_0c059cbc;
P_0c059cbc: /* original d038, guest PC 0x0c059cbc */
if(!s->budget--) { s->failed_pc=0x0c059cbcu; return 0; }
r[0]=read(ram,0x0c059da0u,4);
goto P_0c059cbe;
P_0c059cbe: /* original 6232, guest PC 0x0c059cbe */
if(!s->budget--) { s->failed_pc=0x0c059cbeu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cc0;
P_0c059cc0: /* original 4208, guest PC 0x0c059cc0 */
if(!s->budget--) { s->failed_pc=0x0c059cc0u; return 0; }
r[2]<<=2;
goto P_0c059cc2;
P_0c059cc2: /* original 02c6, guest PC 0x0c059cc2 */
if(!s->budget--) { s->failed_pc=0x0c059cc2u; return 0; }
write(ram,r[2]+r[0],r[12],4);
goto P_0c059cc4;
P_0c059cc4: /* original d237, guest PC 0x0c059cc4 */
if(!s->budget--) { s->failed_pc=0x0c059cc4u; return 0; }
r[2]=read(ram,0x0c059da4u,4);
goto P_0c059cc6;
P_0c059cc6: /* original 6022, guest PC 0x0c059cc6 */
if(!s->budget--) { s->failed_pc=0x0c059cc6u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c059cc8;
P_0c059cc8: /* original 8801, guest PC 0x0c059cc8 */
if(!s->budget--) { s->failed_pc=0x0c059cc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059cca;
P_0c059cca: /* original 8903, guest PC 0x0c059cca */
if(!s->budget--) { s->failed_pc=0x0c059ccau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059cd4; }
goto P_0c059ccc;
P_0c059ccc: /* original d136, guest PC 0x0c059ccc */
if(!s->budget--) { s->failed_pc=0x0c059cccu; return 0; }
r[1]=read(ram,0x0c059da8u,4);
goto P_0c059cce;
P_0c059cce: /* original 6012, guest PC 0x0c059cce */
if(!s->budget--) { s->failed_pc=0x0c059cceu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059cd0;
P_0c059cd0: /* original 8801, guest PC 0x0c059cd0 */
if(!s->budget--) { s->failed_pc=0x0c059cd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c059cd2;
P_0c059cd2: /* original 8b43, guest PC 0x0c059cd2 */
if(!s->budget--) { s->failed_pc=0x0c059cd2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c059d5c; }
goto P_0c059cd4;
P_0c059cd4: /* original d331, guest PC 0x0c059cd4 */
if(!s->budget--) { s->failed_pc=0x0c059cd4u; return 0; }
r[3]=read(ram,0x0c059d9cu,4);
goto P_0c059cd6;
P_0c059cd6: /* original 6232, guest PC 0x0c059cd6 */
if(!s->budget--) { s->failed_pc=0x0c059cd6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c059cd8;
P_0c059cd8: /* original 22d9, guest PC 0x0c059cd8 */
if(!s->budget--) { s->failed_pc=0x0c059cd8u; return 0; }
r[2]&=r[13];
goto P_0c059cda;
P_0c059cda: /* original e501, guest PC 0x0c059cda */
if(!s->budget--) { s->failed_pc=0x0c059cdau; return 0; }
r[5]=0x00000001u;
goto P_0c059cdc;
P_0c059cdc: /* original 1f21, guest PC 0x0c059cdc */
if(!s->budget--) { s->failed_pc=0x0c059cdcu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c059cde;
P_0c059cde: /* original de33, guest PC 0x0c059cde */
if(!s->budget--) { s->failed_pc=0x0c059cdeu; return 0; }
r[14]=read(ram,0x0c059dacu,4);
goto P_0c059ce0;
P_0c059ce0: /* original 4e0b, guest PC 0x0c059ce0 */
if(!s->budget--) { s->failed_pc=0x0c059ce0u; return 0; }
target=r[14];
r[16]=code_base|0x0c059ce4u;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059ce4u) { target=s->pc; goto dispatch; }
goto P_0c059ce4;
P_0c059ce2: /* original e408, guest PC 0x0c059ce2 */
if(!s->budget--) { s->failed_pc=0x0c059ce2u; return 0; }
r[4]=0x00000008u;
goto P_0c059ce4;
P_0c059ce4: /* original e500, guest PC 0x0c059ce4 */
if(!s->budget--) { s->failed_pc=0x0c059ce4u; return 0; }
r[5]=0x00000000u;
goto P_0c059ce6;
P_0c059ce6: /* original 4e0b, guest PC 0x0c059ce6 */
if(!s->budget--) { s->failed_pc=0x0c059ce6u; return 0; }
target=r[14];
r[16]=code_base|0x0c059ceau;
r[4]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059ceau) { target=s->pc; goto dispatch; }
goto P_0c059cea;
P_0c059ce8: /* original e408, guest PC 0x0c059ce8 */
if(!s->budget--) { s->failed_pc=0x0c059ce8u; return 0; }
r[4]=0x00000008u;
goto P_0c059cea;
P_0c059cea: /* original 5bf1, guest PC 0x0c059cea */
if(!s->budget--) { s->failed_pc=0x0c059ceau; return 0; }
r[11]=read(ram,r[15]+4,4);
goto P_0c059cec;
P_0c059cec: /* original d030, guest PC 0x0c059cec */
if(!s->budget--) { s->failed_pc=0x0c059cecu; return 0; }
r[0]=read(ram,0x0c059db0u,4);
goto P_0c059cee;
P_0c059cee: /* original 4b08, guest PC 0x0c059cee */
if(!s->budget--) { s->failed_pc=0x0c059ceeu; return 0; }
r[11]<<=2;
goto P_0c059cf0;
P_0c059cf0: /* original 9445, guest PC 0x0c059cf0 */
if(!s->budget--) { s->failed_pc=0x0c059cf0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d7eu,2);
goto P_0c059cf2;
P_0c059cf2: /* original 4b08, guest PC 0x0c059cf2 */
if(!s->budget--) { s->failed_pc=0x0c059cf2u; return 0; }
r[11]<<=2;
goto P_0c059cf4;
P_0c059cf4: /* original 4b00, guest PC 0x0c059cf4 */
if(!s->budget--) { s->failed_pc=0x0c059cf4u; return 0; }
r[17]=(r[17]&~1u)|((r[11]>>31)!=0);
r[11]<<=1;
goto P_0c059cf6;
P_0c059cf6: /* original 4e0b, guest PC 0x0c059cf6 */
if(!s->budget--) { s->failed_pc=0x0c059cf6u; return 0; }
target=r[14];
r[16]=code_base|0x0c059cfau;
r[5]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059cfau) { target=s->pc; goto dispatch; }
goto P_0c059cfa;
P_0c059cf8: /* original 05be, guest PC 0x0c059cf8 */
if(!s->budget--) { s->failed_pc=0x0c059cf8u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059cfa;
P_0c059cfa: /* original d02e, guest PC 0x0c059cfa */
if(!s->budget--) { s->failed_pc=0x0c059cfau; return 0; }
r[0]=read(ram,0x0c059db4u,4);
goto P_0c059cfc;
P_0c059cfc: /* original 9440, guest PC 0x0c059cfc */
if(!s->budget--) { s->failed_pc=0x0c059cfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d80u,2);
goto P_0c059cfe;
P_0c059cfe: /* original 4e0b, guest PC 0x0c059cfe */
if(!s->budget--) { s->failed_pc=0x0c059cfeu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d02u;
r[5]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059d02u) { target=s->pc; goto dispatch; }
goto P_0c059d02;
P_0c059d00: /* original 05be, guest PC 0x0c059d00 */
if(!s->budget--) { s->failed_pc=0x0c059d00u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d02;
P_0c059d02: /* original d02d, guest PC 0x0c059d02 */
if(!s->budget--) { s->failed_pc=0x0c059d02u; return 0; }
r[0]=read(ram,0x0c059db8u,4);
goto P_0c059d04;
P_0c059d04: /* original 943d, guest PC 0x0c059d04 */
if(!s->budget--) { s->failed_pc=0x0c059d04u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d82u,2);
goto P_0c059d06;
P_0c059d06: /* original 4e0b, guest PC 0x0c059d06 */
if(!s->budget--) { s->failed_pc=0x0c059d06u; return 0; }
target=r[14];
r[16]=code_base|0x0c059d0au;
r[5]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059d0au) { target=s->pc; goto dispatch; }
goto P_0c059d0a;
P_0c059d08: /* original 05be, guest PC 0x0c059d08 */
if(!s->budget--) { s->failed_pc=0x0c059d08u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d0a;
P_0c059d0a: /* original d02c, guest PC 0x0c059d0a */
if(!s->budget--) { s->failed_pc=0x0c059d0au; return 0; }
r[0]=read(ram,0x0c059dbcu,4);
goto P_0c059d0c;
P_0c059d0c: /* original 943a, guest PC 0x0c059d0c */
if(!s->budget--) { s->failed_pc=0x0c059d0cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d84u,2);
goto P_0c059d0e;
P_0c059d0e: /* original 4e0b, guest PC 0x0c059d0e */
if(!s->budget--) { s->failed_pc=0x0c059d0eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d12u;
r[5]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059d12u) { target=s->pc; goto dispatch; }
goto P_0c059d12;
P_0c059d10: /* original 05be, guest PC 0x0c059d10 */
if(!s->budget--) { s->failed_pc=0x0c059d10u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d12;
P_0c059d12: /* original d02b, guest PC 0x0c059d12 */
if(!s->budget--) { s->failed_pc=0x0c059d12u; return 0; }
r[0]=read(ram,0x0c059dc0u,4);
goto P_0c059d14;
P_0c059d14: /* original 9437, guest PC 0x0c059d14 */
if(!s->budget--) { s->failed_pc=0x0c059d14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d86u,2);
goto P_0c059d16;
P_0c059d16: /* original 4e0b, guest PC 0x0c059d16 */
if(!s->budget--) { s->failed_pc=0x0c059d16u; return 0; }
target=r[14];
r[16]=code_base|0x0c059d1au;
r[5]=read(ram,r[11]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059d1au) { target=s->pc; goto dispatch; }
goto P_0c059d1a;
P_0c059d18: /* original 05be, guest PC 0x0c059d18 */
if(!s->budget--) { s->failed_pc=0x0c059d18u; return 0; }
r[5]=read(ram,r[11]+r[0],4);
goto P_0c059d1a;
P_0c059d1a: /* original d52a, guest PC 0x0c059d1a */
if(!s->budget--) { s->failed_pc=0x0c059d1au; return 0; }
r[5]=read(ram,0x0c059dc4u,4);
goto P_0c059d1c;
P_0c059d1c: /* original 9434, guest PC 0x0c059d1c */
if(!s->budget--) { s->failed_pc=0x0c059d1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d88u,2);
goto P_0c059d1e;
P_0c059d1e: /* original 4e0b, guest PC 0x0c059d1e */
if(!s->budget--) { s->failed_pc=0x0c059d1eu; return 0; }
target=r[14];
r[16]=code_base|0x0c059d22u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059d22u) { target=s->pc; goto dispatch; }
goto P_0c059d22;
P_0c059d20: /* original 0009, guest PC 0x0c059d20 */
if(!s->budget--) { s->failed_pc=0x0c059d20u; return 0; }
goto P_0c059d22;
P_0c059d22: /* original 9431, guest PC 0x0c059d22 */
if(!s->budget--) { s->failed_pc=0x0c059d22u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c059d88u,2);
goto P_0c059d24;
P_0c059d24: /* original d328, guest PC 0x0c059d24 */
if(!s->budget--) { s->failed_pc=0x0c059d24u; return 0; }
r[3]=read(ram,0x0c059dc8u,4);
goto P_0c059d26;
P_0c059d26: /* original 430b, guest PC 0x0c059d26 */
if(!s->budget--) { s->failed_pc=0x0c059d26u; return 0; }
target=r[3];
r[16]=code_base|0x0c059d2au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059d2au) { target=s->pc; goto dispatch; }
goto P_0c059d2a;
P_0c059d28: /* original 0009, guest PC 0x0c059d28 */
if(!s->budget--) { s->failed_pc=0x0c059d28u; return 0; }
goto P_0c059d2a;
P_0c059d2a: /* original e200, guest PC 0x0c059d2a */
if(!s->budget--) { s->failed_pc=0x0c059d2au; return 0; }
r[2]=0x00000000u;
goto P_0c059d2c;
P_0c059d2c: /* original d327, guest PC 0x0c059d2c */
if(!s->budget--) { s->failed_pc=0x0c059d2cu; return 0; }
r[3]=read(ram,0x0c059dccu,4);
goto P_0c059d2e;
P_0c059d2e: /* original 2322, guest PC 0x0c059d2e */
if(!s->budget--) { s->failed_pc=0x0c059d2eu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c059d30;
P_0c059d30: /* original d027, guest PC 0x0c059d30 */
if(!s->budget--) { s->failed_pc=0x0c059d30u; return 0; }
r[0]=read(ram,0x0c059dd0u,4);
goto P_0c059d32;
P_0c059d32: /* original 6102, guest PC 0x0c059d32 */
if(!s->budget--) { s->failed_pc=0x0c059d32u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c059d34;
P_0c059d34: /* original d227, guest PC 0x0c059d34 */
if(!s->budget--) { s->failed_pc=0x0c059d34u; return 0; }
r[2]=read(ram,0x0c059dd4u,4);
goto P_0c059d36;
P_0c059d36: /* original 2212, guest PC 0x0c059d36 */
if(!s->budget--) { s->failed_pc=0x0c059d36u; return 0; }
write(ram,r[2],r[1],4);
goto P_0c059d38;
P_0c059d38: /* original d11b, guest PC 0x0c059d38 */
if(!s->budget--) { s->failed_pc=0x0c059d38u; return 0; }
r[1]=read(ram,0x0c059da8u,4);
goto P_0c059d3a;
P_0c059d3a: /* original 6312, guest PC 0x0c059d3a */
if(!s->budget--) { s->failed_pc=0x0c059d3au; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059d3c;
P_0c059d3c: /* original 2338, guest PC 0x0c059d3c */
if(!s->budget--) { s->failed_pc=0x0c059d3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059d3e;
P_0c059d3e: /* original 890d, guest PC 0x0c059d3e */
if(!s->budget--) { s->failed_pc=0x0c059d3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059d5c; }
goto P_0c059d40;
P_0c059d40: /* original d216, guest PC 0x0c059d40 */
if(!s->budget--) { s->failed_pc=0x0c059d40u; return 0; }
r[2]=read(ram,0x0c059d9cu,4);
goto P_0c059d42;
P_0c059d42: /* original 6322, guest PC 0x0c059d42 */
if(!s->budget--) { s->failed_pc=0x0c059d42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059d44;
P_0c059d44: /* original d024, guest PC 0x0c059d44 */
if(!s->budget--) { s->failed_pc=0x0c059d44u; return 0; }
r[0]=read(ram,0x0c059dd8u,4);
goto P_0c059d46;
P_0c059d46: /* original 2032, guest PC 0x0c059d46 */
if(!s->budget--) { s->failed_pc=0x0c059d46u; return 0; }
write(ram,r[0],r[3],4);
goto P_0c059d48;
P_0c059d48: /* original 70e8, guest PC 0x0c059d48 */
if(!s->budget--) { s->failed_pc=0x0c059d48u; return 0; }
r[0]+=0xffffffe8u;
goto P_0c059d4a;
P_0c059d4a: /* original 6323, guest PC 0x0c059d4a */
if(!s->budget--) { s->failed_pc=0x0c059d4au; return 0; }
r[3]=r[2];
goto P_0c059d4c;
P_0c059d4c: /* original 6132, guest PC 0x0c059d4c */
if(!s->budget--) { s->failed_pc=0x0c059d4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c059d4e;
P_0c059d4e: /* original e202, guest PC 0x0c059d4e */
if(!s->budget--) { s->failed_pc=0x0c059d4eu; return 0; }
r[2]=0x00000002u;
goto P_0c059d50;
P_0c059d50: /* original 4108, guest PC 0x0c059d50 */
if(!s->budget--) { s->failed_pc=0x0c059d50u; return 0; }
r[1]<<=2;
goto P_0c059d52;
P_0c059d52: /* original 0126, guest PC 0x0c059d52 */
if(!s->budget--) { s->failed_pc=0x0c059d52u; return 0; }
write(ram,r[1]+r[0],r[2],4);
goto P_0c059d54;
P_0c059d54: /* original d121, guest PC 0x0c059d54 */
if(!s->budget--) { s->failed_pc=0x0c059d54u; return 0; }
r[1]=read(ram,0x0c059ddcu,4);
goto P_0c059d56;
P_0c059d56: /* original 21d2, guest PC 0x0c059d56 */
if(!s->budget--) { s->failed_pc=0x0c059d56u; return 0; }
write(ram,r[1],r[13],4);
goto P_0c059d58;
P_0c059d58: /* original 7320, guest PC 0x0c059d58 */
if(!s->budget--) { s->failed_pc=0x0c059d58u; return 0; }
r[3]+=0x00000020u;
goto P_0c059d5a;
P_0c059d5a: /* original 23d2, guest PC 0x0c059d5a */
if(!s->budget--) { s->failed_pc=0x0c059d5au; return 0; }
write(ram,r[3],r[13],4);
goto P_0c059d5c;
P_0c059d5c: /* original e000, guest PC 0x0c059d5c */
if(!s->budget--) { s->failed_pc=0x0c059d5cu; return 0; }
r[0]=0x00000000u;
goto P_0c059d5e;
P_0c059d5e: /* original 7f08, guest PC 0x0c059d5e */
if(!s->budget--) { s->failed_pc=0x0c059d5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c059d60;
P_0c059d60: /* original 4f26, guest PC 0x0c059d60 */
if(!s->budget--) { s->failed_pc=0x0c059d60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c059d62;
P_0c059d62: /* original 68f6, guest PC 0x0c059d62 */
if(!s->budget--) { s->failed_pc=0x0c059d62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c059d64;
P_0c059d64: /* original 69f6, guest PC 0x0c059d64 */
if(!s->budget--) { s->failed_pc=0x0c059d64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c059d66;
P_0c059d66: /* original 6af6, guest PC 0x0c059d66 */
if(!s->budget--) { s->failed_pc=0x0c059d66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c059d68;
P_0c059d68: /* original 6bf6, guest PC 0x0c059d68 */
if(!s->budget--) { s->failed_pc=0x0c059d68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c059d6a;
P_0c059d6a: /* original 6cf6, guest PC 0x0c059d6a */
if(!s->budget--) { s->failed_pc=0x0c059d6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c059d6c;
P_0c059d6c: /* original 6df6, guest PC 0x0c059d6c */
if(!s->budget--) { s->failed_pc=0x0c059d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c059d6e;
P_0c059d6e: /* original 000b, guest PC 0x0c059d6e */
if(!s->budget--) { s->failed_pc=0x0c059d6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c059d70: /* original 6ef6, guest PC 0x0c059d70 */
if(!s->budget--) { s->failed_pc=0x0c059d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c059d72u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
