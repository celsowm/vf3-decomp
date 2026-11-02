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
int vf3_away_batch106_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c091b54u: goto P_0c091b54;
case 0x0c091b56u: goto P_0c091b56;
case 0x0c091b58u: goto P_0c091b58;
case 0x0c091b5au: goto P_0c091b5a;
case 0x0c091b5cu: goto P_0c091b5c;
case 0x0c091b5eu: goto P_0c091b5e;
case 0x0c091b60u: goto P_0c091b60;
case 0x0c091b62u: goto P_0c091b62;
case 0x0c091b64u: goto P_0c091b64;
case 0x0c091b66u: goto P_0c091b66;
case 0x0c091b68u: goto P_0c091b68;
case 0x0c091b6au: goto P_0c091b6a;
case 0x0c091b6cu: goto P_0c091b6c;
case 0x0c091b6eu: goto P_0c091b6e;
case 0x0c091b70u: goto P_0c091b70;
case 0x0c091b72u: goto P_0c091b72;
case 0x0c091b74u: goto P_0c091b74;
case 0x0c091b76u: goto P_0c091b76;
case 0x0c091b78u: goto P_0c091b78;
case 0x0c091b7au: goto P_0c091b7a;
case 0x0c091b7cu: goto P_0c091b7c;
case 0x0c091b7eu: goto P_0c091b7e;
case 0x0c091b80u: goto P_0c091b80;
case 0x0c091b82u: goto P_0c091b82;
case 0x0c091b84u: goto P_0c091b84;
case 0x0c091b86u: goto P_0c091b86;
case 0x0c091b88u: goto P_0c091b88;
case 0x0c091b8au: goto P_0c091b8a;
case 0x0c091b8cu: goto P_0c091b8c;
case 0x0c091b8eu: goto P_0c091b8e;
case 0x0c091b90u: goto P_0c091b90;
case 0x0c091b92u: goto P_0c091b92;
case 0x0c091b94u: goto P_0c091b94;
case 0x0c091b96u: goto P_0c091b96;
case 0x0c091b98u: goto P_0c091b98;
case 0x0c091b9au: goto P_0c091b9a;
case 0x0c091b9cu: goto P_0c091b9c;
case 0x0c091b9eu: goto P_0c091b9e;
case 0x0c091ba0u: goto P_0c091ba0;
case 0x0c091ba2u: goto P_0c091ba2;
case 0x0c091ba4u: goto P_0c091ba4;
case 0x0c091ba6u: goto P_0c091ba6;
case 0x0c091ba8u: goto P_0c091ba8;
case 0x0c091baau: goto P_0c091baa;
case 0x0c091bacu: goto P_0c091bac;
case 0x0c091baeu: goto P_0c091bae;
case 0x0c091bb0u: goto P_0c091bb0;
case 0x0c091bb2u: goto P_0c091bb2;
case 0x0c091bb4u: goto P_0c091bb4;
case 0x0c091bb6u: goto P_0c091bb6;
case 0x0c091bb8u: goto P_0c091bb8;
case 0x0c091bbau: goto P_0c091bba;
case 0x0c091bbcu: goto P_0c091bbc;
case 0x0c091bbeu: goto P_0c091bbe;
case 0x0c091bc0u: goto P_0c091bc0;
case 0x0c091bc2u: goto P_0c091bc2;
case 0x0c091bc4u: goto P_0c091bc4;
case 0x0c091bc6u: goto P_0c091bc6;
case 0x0c091bc8u: goto P_0c091bc8;
case 0x0c091bcau: goto P_0c091bca;
case 0x0c091bccu: goto P_0c091bcc;
case 0x0c091bceu: goto P_0c091bce;
case 0x0c091bd0u: goto P_0c091bd0;
case 0x0c091bd2u: goto P_0c091bd2;
case 0x0c091bd4u: goto P_0c091bd4;
case 0x0c091bd6u: goto P_0c091bd6;
case 0x0c091bd8u: goto P_0c091bd8;
case 0x0c091bdau: goto P_0c091bda;
case 0x0c091bdcu: goto P_0c091bdc;
case 0x0c091bdeu: goto P_0c091bde;
case 0x0c091be0u: goto P_0c091be0;
case 0x0c091be2u: goto P_0c091be2;
case 0x0c091be4u: goto P_0c091be4;
case 0x0c091be6u: goto P_0c091be6;
case 0x0c091be8u: goto P_0c091be8;
case 0x0c091beau: goto P_0c091bea;
case 0x0c091becu: goto P_0c091bec;
case 0x0c091beeu: goto P_0c091bee;
case 0x0c091bf0u: goto P_0c091bf0;
case 0x0c091bf2u: goto P_0c091bf2;
case 0x0c091c20u: goto P_0c091c20;
case 0x0c091c22u: goto P_0c091c22;
case 0x0c091c24u: goto P_0c091c24;
case 0x0c091c26u: goto P_0c091c26;
case 0x0c091c28u: goto P_0c091c28;
case 0x0c091c2au: goto P_0c091c2a;
case 0x0c091c2cu: goto P_0c091c2c;
case 0x0c091c2eu: goto P_0c091c2e;
case 0x0c091c30u: goto P_0c091c30;
case 0x0c091c32u: goto P_0c091c32;
case 0x0c091c34u: goto P_0c091c34;
case 0x0c091c36u: goto P_0c091c36;
case 0x0c091c38u: goto P_0c091c38;
case 0x0c091c3au: goto P_0c091c3a;
case 0x0c091c3cu: goto P_0c091c3c;
case 0x0c091c3eu: goto P_0c091c3e;
case 0x0c091c40u: goto P_0c091c40;
case 0x0c091c42u: goto P_0c091c42;
case 0x0c091c44u: goto P_0c091c44;
case 0x0c091c46u: goto P_0c091c46;
case 0x0c091c48u: goto P_0c091c48;
case 0x0c091c4au: goto P_0c091c4a;
case 0x0c091c4cu: goto P_0c091c4c;
case 0x0c091c4eu: goto P_0c091c4e;
case 0x0c091c50u: goto P_0c091c50;
case 0x0c091c52u: goto P_0c091c52;
case 0x0c091c54u: goto P_0c091c54;
case 0x0c091c56u: goto P_0c091c56;
case 0x0c091c58u: goto P_0c091c58;
case 0x0c091c5au: goto P_0c091c5a;
case 0x0c091c5cu: goto P_0c091c5c;
case 0x0c091c5eu: goto P_0c091c5e;
case 0x0c091c60u: goto P_0c091c60;
case 0x0c091c62u: goto P_0c091c62;
case 0x0c091c64u: goto P_0c091c64;
case 0x0c091c66u: goto P_0c091c66;
case 0x0c091c68u: goto P_0c091c68;
case 0x0c091c6au: goto P_0c091c6a;
case 0x0c091c6cu: goto P_0c091c6c;
case 0x0c091c6eu: goto P_0c091c6e;
case 0x0c091c70u: goto P_0c091c70;
case 0x0c091c72u: goto P_0c091c72;
case 0x0c091c74u: goto P_0c091c74;
case 0x0c091c76u: goto P_0c091c76;
case 0x0c091c78u: goto P_0c091c78;
case 0x0c091c7au: goto P_0c091c7a;
case 0x0c091c7cu: goto P_0c091c7c;
case 0x0c091c7eu: goto P_0c091c7e;
case 0x0c091c80u: goto P_0c091c80;
case 0x0c091c82u: goto P_0c091c82;
case 0x0c091c84u: goto P_0c091c84;
case 0x0c091c86u: goto P_0c091c86;
case 0x0c091c88u: goto P_0c091c88;
case 0x0c091c8au: goto P_0c091c8a;
case 0x0c091c8cu: goto P_0c091c8c;
case 0x0c091c8eu: goto P_0c091c8e;
case 0x0c091c90u: goto P_0c091c90;
case 0x0c091c92u: goto P_0c091c92;
case 0x0c091c94u: goto P_0c091c94;
case 0x0c091c96u: goto P_0c091c96;
case 0x0c091c98u: goto P_0c091c98;
case 0x0c091c9au: goto P_0c091c9a;
case 0x0c091c9cu: goto P_0c091c9c;
case 0x0c091c9eu: goto P_0c091c9e;
case 0x0c091ca0u: goto P_0c091ca0;
case 0x0c091ca2u: goto P_0c091ca2;
case 0x0c091ca4u: goto P_0c091ca4;
case 0x0c091ca6u: goto P_0c091ca6;
case 0x0c091ca8u: goto P_0c091ca8;
case 0x0c091caau: goto P_0c091caa;
case 0x0c091cacu: goto P_0c091cac;
case 0x0c091caeu: goto P_0c091cae;
case 0x0c091cb0u: goto P_0c091cb0;
case 0x0c091cb2u: goto P_0c091cb2;
case 0x0c091cb4u: goto P_0c091cb4;
case 0x0c091cb6u: goto P_0c091cb6;
case 0x0c091cb8u: goto P_0c091cb8;
case 0x0c091cbau: goto P_0c091cba;
case 0x0c091cbcu: goto P_0c091cbc;
case 0x0c091cbeu: goto P_0c091cbe;
case 0x0c091cc0u: goto P_0c091cc0;
case 0x0c091cc2u: goto P_0c091cc2;
case 0x0c091cc4u: goto P_0c091cc4;
case 0x0c091cc6u: goto P_0c091cc6;
case 0x0c091cc8u: goto P_0c091cc8;
case 0x0c091ccau: goto P_0c091cca;
case 0x0c091cccu: goto P_0c091ccc;
case 0x0c091cceu: goto P_0c091cce;
case 0x0c091cd0u: goto P_0c091cd0;
case 0x0c091cd2u: goto P_0c091cd2;
case 0x0c091cd4u: goto P_0c091cd4;
case 0x0c091cd6u: goto P_0c091cd6;
case 0x0c091cd8u: goto P_0c091cd8;
case 0x0c091cdau: goto P_0c091cda;
case 0x0c091cdcu: goto P_0c091cdc;
case 0x0c091cdeu: goto P_0c091cde;
case 0x0c091ce0u: goto P_0c091ce0;
case 0x0c091ce2u: goto P_0c091ce2;
case 0x0c091ce4u: goto P_0c091ce4;
case 0x0c091ce6u: goto P_0c091ce6;
case 0x0c091ce8u: goto P_0c091ce8;
case 0x0c091ceau: goto P_0c091cea;
case 0x0c091cecu: goto P_0c091cec;
case 0x0c091ceeu: goto P_0c091cee;
case 0x0c091cf0u: goto P_0c091cf0;
case 0x0c091cf2u: goto P_0c091cf2;
case 0x0c091cf4u: goto P_0c091cf4;
case 0x0c091cf6u: goto P_0c091cf6;
case 0x0c091cf8u: goto P_0c091cf8;
case 0x0c091cfau: goto P_0c091cfa;
case 0x0c091cfcu: goto P_0c091cfc;
case 0x0c091cfeu: goto P_0c091cfe;
case 0x0c091d00u: goto P_0c091d00;
case 0x0c091d02u: goto P_0c091d02;
case 0x0c091d04u: goto P_0c091d04;
case 0x0c091d06u: goto P_0c091d06;
case 0x0c091d08u: goto P_0c091d08;
case 0x0c091d0au: goto P_0c091d0a;
case 0x0c091d0cu: goto P_0c091d0c;
case 0x0c091d0eu: goto P_0c091d0e;
case 0x0c091d10u: goto P_0c091d10;
case 0x0c091d12u: goto P_0c091d12;
case 0x0c091d14u: goto P_0c091d14;
case 0x0c091d16u: goto P_0c091d16;
case 0x0c091d18u: goto P_0c091d18;
case 0x0c091d1au: goto P_0c091d1a;
case 0x0c091d1cu: goto P_0c091d1c;
case 0x0c091d1eu: goto P_0c091d1e;
case 0x0c091d20u: goto P_0c091d20;
case 0x0c091d22u: goto P_0c091d22;
case 0x0c091d24u: goto P_0c091d24;
case 0x0c091d26u: goto P_0c091d26;
case 0x0c091d28u: goto P_0c091d28;
case 0x0c091d2au: goto P_0c091d2a;
case 0x0c091d2cu: goto P_0c091d2c;
case 0x0c091d2eu: goto P_0c091d2e;
case 0x0c091d30u: goto P_0c091d30;
case 0x0c091d32u: goto P_0c091d32;
case 0x0c091d34u: goto P_0c091d34;
case 0x0c091d36u: goto P_0c091d36;
case 0x0c091d38u: goto P_0c091d38;
case 0x0c091d3au: goto P_0c091d3a;
case 0x0c091d3cu: goto P_0c091d3c;
case 0x0c091d3eu: goto P_0c091d3e;
case 0x0c091d40u: goto P_0c091d40;
case 0x0c091d42u: goto P_0c091d42;
case 0x0c091d44u: goto P_0c091d44;
case 0x0c091d46u: goto P_0c091d46;
case 0x0c091d48u: goto P_0c091d48;
case 0x0c091d4au: goto P_0c091d4a;
case 0x0c091d4cu: goto P_0c091d4c;
case 0x0c091d4eu: goto P_0c091d4e;
case 0x0c091d50u: goto P_0c091d50;
case 0x0c091d52u: goto P_0c091d52;
case 0x0c091d54u: goto P_0c091d54;
case 0x0c091d56u: goto P_0c091d56;
case 0x0c091d58u: goto P_0c091d58;
case 0x0c091d5au: goto P_0c091d5a;
case 0x0c091d5cu: goto P_0c091d5c;
case 0x0c091d5eu: goto P_0c091d5e;
case 0x0c091d60u: goto P_0c091d60;
case 0x0c091d62u: goto P_0c091d62;
case 0x0c091d64u: goto P_0c091d64;
case 0x0c091d66u: goto P_0c091d66;
case 0x0c091d68u: goto P_0c091d68;
case 0x0c091d6au: goto P_0c091d6a;
case 0x0c091d98u: goto P_0c091d98;
case 0x0c091d9au: goto P_0c091d9a;
case 0x0c091d9cu: goto P_0c091d9c;
case 0x0c091d9eu: goto P_0c091d9e;
case 0x0c091da0u: goto P_0c091da0;
case 0x0c091da2u: goto P_0c091da2;
case 0x0c091da4u: goto P_0c091da4;
case 0x0c091da6u: goto P_0c091da6;
case 0x0c091da8u: goto P_0c091da8;
case 0x0c091daau: goto P_0c091daa;
case 0x0c091dacu: goto P_0c091dac;
case 0x0c091daeu: goto P_0c091dae;
case 0x0c091db0u: goto P_0c091db0;
case 0x0c091db2u: goto P_0c091db2;
case 0x0c091db4u: goto P_0c091db4;
case 0x0c091db6u: goto P_0c091db6;
case 0x0c091db8u: goto P_0c091db8;
case 0x0c091dbau: goto P_0c091dba;
case 0x0c091dbcu: goto P_0c091dbc;
case 0x0c091e4cu: goto P_0c091e4c;
case 0x0c091e4eu: goto P_0c091e4e;
case 0x0c091e50u: goto P_0c091e50;
case 0x0c091e52u: goto P_0c091e52;
case 0x0c091e54u: goto P_0c091e54;
case 0x0c091e56u: goto P_0c091e56;
case 0x0c091e58u: goto P_0c091e58;
case 0x0c091e5au: goto P_0c091e5a;
case 0x0c091e5cu: goto P_0c091e5c;
case 0x0c091e5eu: goto P_0c091e5e;
case 0x0c091e60u: goto P_0c091e60;
default: return vf3_matrix_family(target,s,ram);
}
P_0c091b54: /* original 2fe6, guest PC 0x0c091b54 */
if(!s->budget--) { s->failed_pc=0x0c091b54u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091b56;
P_0c091b56: /* original e061, guest PC 0x0c091b56 */
if(!s->budget--) { s->failed_pc=0x0c091b56u; return 0; }
r[0]=0x00000061u;
goto P_0c091b58;
P_0c091b58: /* original 6e43, guest PC 0x0c091b58 */
if(!s->budget--) { s->failed_pc=0x0c091b58u; return 0; }
r[14]=r[4];
goto P_0c091b5a;
P_0c091b5a: /* original 2fd6, guest PC 0x0c091b5a */
if(!s->budget--) { s->failed_pc=0x0c091b5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091b5c;
P_0c091b5c: /* original 04ec, guest PC 0x0c091b5c */
if(!s->budget--) { s->failed_pc=0x0c091b5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c091b5e;
P_0c091b5e: /* original e060, guest PC 0x0c091b5e */
if(!s->budget--) { s->failed_pc=0x0c091b5eu; return 0; }
r[0]=0x00000060u;
goto P_0c091b60;
P_0c091b60: /* original 4f22, guest PC 0x0c091b60 */
if(!s->budget--) { s->failed_pc=0x0c091b60u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091b62;
P_0c091b62: /* original e30d, guest PC 0x0c091b62 */
if(!s->budget--) { s->failed_pc=0x0c091b62u; return 0; }
r[3]=0x0000000du;
goto P_0c091b64;
P_0c091b64: /* original 06ec, guest PC 0x0c091b64 */
if(!s->budget--) { s->failed_pc=0x0c091b64u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c091b66;
P_0c091b66: /* original 644c, guest PC 0x0c091b66 */
if(!s->budget--) { s->failed_pc=0x0c091b66u; return 0; }
r[4]=r[4]&255u;
goto P_0c091b68;
P_0c091b68: /* original 3432, guest PC 0x0c091b68 */
if(!s->budget--) { s->failed_pc=0x0c091b68u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[3])!=0);
goto P_0c091b6a;
P_0c091b6a: /* original 8f01, guest PC 0x0c091b6a */
if(!s->budget--) { s->failed_pc=0x0c091b6au; return 0; }
cond=r[17]&1u;
r[6]=r[6]&255u;
if(!cond) { goto P_0c091b70; }
goto P_0c091b6e;
P_0c091b6c: /* original 666c, guest PC 0x0c091b6c */
if(!s->budget--) { s->failed_pc=0x0c091b6cu; return 0; }
r[6]=r[6]&255u;
goto P_0c091b6e;
P_0c091b6e: /* original 3438, guest PC 0x0c091b6e */
if(!s->budget--) { s->failed_pc=0x0c091b6eu; return 0; }
r[4]-=r[3];
goto P_0c091b70;
P_0c091b70: /* original d028, guest PC 0x0c091b70 */
if(!s->budget--) { s->failed_pc=0x0c091b70u; return 0; }
r[0]=read(ram,0x0c091c14u,4);
goto P_0c091b72;
P_0c091b72: /* original e30d, guest PC 0x0c091b72 */
if(!s->budget--) { s->failed_pc=0x0c091b72u; return 0; }
r[3]=0x0000000du;
goto P_0c091b74;
P_0c091b74: /* original 6743, guest PC 0x0c091b74 */
if(!s->budget--) { s->failed_pc=0x0c091b74u; return 0; }
r[7]=r[4];
goto P_0c091b76;
P_0c091b76: /* original 3632, guest PC 0x0c091b76 */
if(!s->budget--) { s->failed_pc=0x0c091b76u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[3])!=0);
goto P_0c091b78;
P_0c091b78: /* original 4708, guest PC 0x0c091b78 */
if(!s->budget--) { s->failed_pc=0x0c091b78u; return 0; }
r[7]<<=2;
goto P_0c091b7a;
P_0c091b7a: /* original 8f01, guest PC 0x0c091b7a */
if(!s->budget--) { s->failed_pc=0x0c091b7au; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[7]+r[0],4);
if(!cond) { goto P_0c091b80; }
goto P_0c091b7e;
P_0c091b7c: /* original 057e, guest PC 0x0c091b7c */
if(!s->budget--) { s->failed_pc=0x0c091b7cu; return 0; }
r[5]=read(ram,r[7]+r[0],4);
goto P_0c091b7e;
P_0c091b7e: /* original 7540, guest PC 0x0c091b7e */
if(!s->budget--) { s->failed_pc=0x0c091b7eu; return 0; }
r[5]+=0x00000040u;
goto P_0c091b80;
P_0c091b80: /* original 9038, guest PC 0x0c091b80 */
if(!s->budget--) { s->failed_pc=0x0c091b80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091bf4u,2);
goto P_0c091b82;
P_0c091b82: /* original 0e56, guest PC 0x0c091b82 */
if(!s->budget--) { s->failed_pc=0x0c091b82u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c091b84;
P_0c091b84: /* original 7520, guest PC 0x0c091b84 */
if(!s->budget--) { s->failed_pc=0x0c091b84u; return 0; }
r[5]+=0x00000020u;
goto P_0c091b86;
P_0c091b86: /* original 9036, guest PC 0x0c091b86 */
if(!s->budget--) { s->failed_pc=0x0c091b86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091bf6u,2);
goto P_0c091b88;
P_0c091b88: /* original 0e56, guest PC 0x0c091b88 */
if(!s->budget--) { s->failed_pc=0x0c091b88u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c091b8a;
P_0c091b8a: /* original d023, guest PC 0x0c091b8a */
if(!s->budget--) { s->failed_pc=0x0c091b8au; return 0; }
r[0]=read(ram,0x0c091c18u,4);
goto P_0c091b8c;
P_0c091b8c: /* original 057e, guest PC 0x0c091b8c */
if(!s->budget--) { s->failed_pc=0x0c091b8cu; return 0; }
r[5]=read(ram,r[7]+r[0],4);
goto P_0c091b8e;
P_0c091b8e: /* original 6043, guest PC 0x0c091b8e */
if(!s->budget--) { s->failed_pc=0x0c091b8eu; return 0; }
r[0]=r[4];
goto P_0c091b90;
P_0c091b90: /* original 4008, guest PC 0x0c091b90 */
if(!s->budget--) { s->failed_pc=0x0c091b90u; return 0; }
r[0]<<=2;
goto P_0c091b92;
P_0c091b92: /* original d722, guest PC 0x0c091b92 */
if(!s->budget--) { s->failed_pc=0x0c091b92u; return 0; }
r[7]=read(ram,0x0c091c1cu,4);
goto P_0c091b94;
P_0c091b94: /* original 4000, guest PC 0x0c091b94 */
if(!s->budget--) { s->failed_pc=0x0c091b94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091b96;
P_0c091b96: /* original 067e, guest PC 0x0c091b96 */
if(!s->budget--) { s->failed_pc=0x0c091b96u; return 0; }
r[6]=read(ram,r[7]+r[0],4);
goto P_0c091b98;
P_0c091b98: /* original 6043, guest PC 0x0c091b98 */
if(!s->budget--) { s->failed_pc=0x0c091b98u; return 0; }
r[0]=r[4];
goto P_0c091b9a;
P_0c091b9a: /* original 4000, guest PC 0x0c091b9a */
if(!s->budget--) { s->failed_pc=0x0c091b9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c091b9c;
P_0c091b9c: /* original 7001, guest PC 0x0c091b9c */
if(!s->budget--) { s->failed_pc=0x0c091b9cu; return 0; }
r[0]+=0x00000001u;
goto P_0c091b9e;
P_0c091b9e: /* original 4008, guest PC 0x0c091b9e */
if(!s->budget--) { s->failed_pc=0x0c091b9eu; return 0; }
r[0]<<=2;
goto P_0c091ba0;
P_0c091ba0: /* original 0d7e, guest PC 0x0c091ba0 */
if(!s->budget--) { s->failed_pc=0x0c091ba0u; return 0; }
r[13]=read(ram,r[7]+r[0],4);
goto P_0c091ba2;
P_0c091ba2: /* original 9029, guest PC 0x0c091ba2 */
if(!s->budget--) { s->failed_pc=0x0c091ba2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091bf8u,2);
goto P_0c091ba4;
P_0c091ba4: /* original 0e56, guest PC 0x0c091ba4 */
if(!s->budget--) { s->failed_pc=0x0c091ba4u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c091ba6;
P_0c091ba6: /* original 9028, guest PC 0x0c091ba6 */
if(!s->budget--) { s->failed_pc=0x0c091ba6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091bfau,2);
goto P_0c091ba8;
P_0c091ba8: /* original 0e56, guest PC 0x0c091ba8 */
if(!s->budget--) { s->failed_pc=0x0c091ba8u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c091baa;
P_0c091baa: /* original 9027, guest PC 0x0c091baa */
if(!s->budget--) { s->failed_pc=0x0c091baau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091bfcu,2);
goto P_0c091bac;
P_0c091bac: /* original 0e66, guest PC 0x0c091bac */
if(!s->budget--) { s->failed_pc=0x0c091bacu; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c091bae;
P_0c091bae: /* original 9026, guest PC 0x0c091bae */
if(!s->budget--) { s->failed_pc=0x0c091baeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091bfeu,2);
goto P_0c091bb0;
P_0c091bb0: /* original 0e66, guest PC 0x0c091bb0 */
if(!s->budget--) { s->failed_pc=0x0c091bb0u; return 0; }
write(ram,r[14]+r[0],r[6],4);
goto P_0c091bb2;
P_0c091bb2: /* original 9025, guest PC 0x0c091bb2 */
if(!s->budget--) { s->failed_pc=0x0c091bb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c00u,2);
goto P_0c091bb4;
P_0c091bb4: /* original 0ed6, guest PC 0x0c091bb4 */
if(!s->budget--) { s->failed_pc=0x0c091bb4u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c091bb6;
P_0c091bb6: /* original 9024, guest PC 0x0c091bb6 */
if(!s->budget--) { s->failed_pc=0x0c091bb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c02u,2);
goto P_0c091bb8;
P_0c091bb8: /* original 0ed6, guest PC 0x0c091bb8 */
if(!s->budget--) { s->failed_pc=0x0c091bb8u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c091bba;
P_0c091bba: /* original 9523, guest PC 0x0c091bba */
if(!s->budget--) { s->failed_pc=0x0c091bbau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c04u,2);
goto P_0c091bbc;
P_0c091bbc: /* original 35ec, guest PC 0x0c091bbc */
if(!s->budget--) { s->failed_pc=0x0c091bbcu; return 0; }
r[5]+=r[14];
goto P_0c091bbe;
P_0c091bbe: /* original b145, guest PC 0x0c091bbe */
if(!s->budget--) { s->failed_pc=0x0c091bbeu; return 0; }
target=code_base|0x0c091e4cu; r[16]=code_base|0x0c091bc2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091bc2u) { target=s->pc; goto dispatch; }
goto P_0c091bc2;
P_0c091bc0: /* original 64d3, guest PC 0x0c091bc0 */
if(!s->budget--) { s->failed_pc=0x0c091bc0u; return 0; }
r[4]=r[13];
goto P_0c091bc2;
P_0c091bc2: /* original 9520, guest PC 0x0c091bc2 */
if(!s->budget--) { s->failed_pc=0x0c091bc2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c06u,2);
goto P_0c091bc4;
P_0c091bc4: /* original 35ec, guest PC 0x0c091bc4 */
if(!s->budget--) { s->failed_pc=0x0c091bc4u; return 0; }
r[5]+=r[14];
goto P_0c091bc6;
P_0c091bc6: /* original b141, guest PC 0x0c091bc6 */
if(!s->budget--) { s->failed_pc=0x0c091bc6u; return 0; }
target=code_base|0x0c091e4cu; r[16]=code_base|0x0c091bcau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091bcau) { target=s->pc; goto dispatch; }
goto P_0c091bca;
P_0c091bc8: /* original 64d3, guest PC 0x0c091bc8 */
if(!s->budget--) { s->failed_pc=0x0c091bc8u; return 0; }
r[4]=r[13];
goto P_0c091bca;
P_0c091bca: /* original 951d, guest PC 0x0c091bca */
if(!s->budget--) { s->failed_pc=0x0c091bcau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c08u,2);
goto P_0c091bcc;
P_0c091bcc: /* original 35ec, guest PC 0x0c091bcc */
if(!s->budget--) { s->failed_pc=0x0c091bccu; return 0; }
r[5]+=r[14];
goto P_0c091bce;
P_0c091bce: /* original b13d, guest PC 0x0c091bce */
if(!s->budget--) { s->failed_pc=0x0c091bceu; return 0; }
target=code_base|0x0c091e4cu; r[16]=code_base|0x0c091bd2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091bd2u) { target=s->pc; goto dispatch; }
goto P_0c091bd2;
P_0c091bd0: /* original 64d3, guest PC 0x0c091bd0 */
if(!s->budget--) { s->failed_pc=0x0c091bd0u; return 0; }
r[4]=r[13];
goto P_0c091bd2;
P_0c091bd2: /* original 951a, guest PC 0x0c091bd2 */
if(!s->budget--) { s->failed_pc=0x0c091bd2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c0au,2);
goto P_0c091bd4;
P_0c091bd4: /* original 35ec, guest PC 0x0c091bd4 */
if(!s->budget--) { s->failed_pc=0x0c091bd4u; return 0; }
r[5]+=r[14];
goto P_0c091bd6;
P_0c091bd6: /* original b139, guest PC 0x0c091bd6 */
if(!s->budget--) { s->failed_pc=0x0c091bd6u; return 0; }
target=code_base|0x0c091e4cu; r[16]=code_base|0x0c091bdau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091bdau) { target=s->pc; goto dispatch; }
goto P_0c091bda;
P_0c091bd8: /* original 64d3, guest PC 0x0c091bd8 */
if(!s->budget--) { s->failed_pc=0x0c091bd8u; return 0; }
r[4]=r[13];
goto P_0c091bda;
P_0c091bda: /* original 9017, guest PC 0x0c091bda */
if(!s->budget--) { s->failed_pc=0x0c091bdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c0cu,2);
goto P_0c091bdc;
P_0c091bdc: /* original f39d, guest PC 0x0c091bdc */
if(!s->budget--) { s->failed_pc=0x0c091bdcu; return 0; }
fr[3]=0x3f800000u;
goto P_0c091bde;
P_0c091bde: /* original fe37, guest PC 0x0c091bde */
if(!s->budget--) { s->failed_pc=0x0c091bdeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091be0;
P_0c091be0: /* original 9015, guest PC 0x0c091be0 */
if(!s->budget--) { s->failed_pc=0x0c091be0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c0eu,2);
goto P_0c091be2;
P_0c091be2: /* original 4f26, guest PC 0x0c091be2 */
if(!s->budget--) { s->failed_pc=0x0c091be2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091be4;
P_0c091be4: /* original fe37, guest PC 0x0c091be4 */
if(!s->budget--) { s->failed_pc=0x0c091be4u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091be6;
P_0c091be6: /* original 9013, guest PC 0x0c091be6 */
if(!s->budget--) { s->failed_pc=0x0c091be6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c10u,2);
goto P_0c091be8;
P_0c091be8: /* original fe37, guest PC 0x0c091be8 */
if(!s->budget--) { s->failed_pc=0x0c091be8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091bea;
P_0c091bea: /* original 9012, guest PC 0x0c091bea */
if(!s->budget--) { s->failed_pc=0x0c091beau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091c12u,2);
goto P_0c091bec;
P_0c091bec: /* original fe37, guest PC 0x0c091bec */
if(!s->budget--) { s->failed_pc=0x0c091becu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c091bee;
P_0c091bee: /* original 6df6, guest PC 0x0c091bee */
if(!s->budget--) { s->failed_pc=0x0c091beeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091bf0;
P_0c091bf0: /* original 000b, guest PC 0x0c091bf0 */
if(!s->budget--) { s->failed_pc=0x0c091bf0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c091bf2: /* original 6ef6, guest PC 0x0c091bf2 */
if(!s->budget--) { s->failed_pc=0x0c091bf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c091bf4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091bf4u; return 0; } return 1;
P_0c091c20: /* original 2fe6, guest PC 0x0c091c20 */
if(!s->budget--) { s->failed_pc=0x0c091c20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c22;
P_0c091c22: /* original 2fd6, guest PC 0x0c091c22 */
if(!s->budget--) { s->failed_pc=0x0c091c22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c24;
P_0c091c24: /* original 6d53, guest PC 0x0c091c24 */
if(!s->budget--) { s->failed_pc=0x0c091c24u; return 0; }
r[13]=r[5];
goto P_0c091c26;
P_0c091c26: /* original 2fc6, guest PC 0x0c091c26 */
if(!s->budget--) { s->failed_pc=0x0c091c26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c28;
P_0c091c28: /* original 7d68, guest PC 0x0c091c28 */
if(!s->budget--) { s->failed_pc=0x0c091c28u; return 0; }
r[13]+=0x00000068u;
goto P_0c091c2a;
P_0c091c2a: /* original 2fb6, guest PC 0x0c091c2a */
if(!s->budget--) { s->failed_pc=0x0c091c2au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c2c;
P_0c091c2c: /* original 6b73, guest PC 0x0c091c2c */
if(!s->budget--) { s->failed_pc=0x0c091c2cu; return 0; }
r[11]=r[7];
goto P_0c091c2e;
P_0c091c2e: /* original 2fa6, guest PC 0x0c091c2e */
if(!s->budget--) { s->failed_pc=0x0c091c2eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c30;
P_0c091c30: /* original 2f96, guest PC 0x0c091c30 */
if(!s->budget--) { s->failed_pc=0x0c091c30u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c32;
P_0c091c32: /* original 2f86, guest PC 0x0c091c32 */
if(!s->budget--) { s->failed_pc=0x0c091c32u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c091c34;
P_0c091c34: /* original fffb, guest PC 0x0c091c34 */
if(!s->budget--) { s->failed_pc=0x0c091c34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c091c36;
P_0c091c36: /* original ffeb, guest PC 0x0c091c36 */
if(!s->budget--) { s->failed_pc=0x0c091c36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c091c38;
P_0c091c38: /* original ffdb, guest PC 0x0c091c38 */
if(!s->budget--) { s->failed_pc=0x0c091c38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c091c3a;
P_0c091c3a: /* original 4f22, guest PC 0x0c091c3a */
if(!s->budget--) { s->failed_pc=0x0c091c3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c091c3c;
P_0c091c3c: /* original 7fe0, guest PC 0x0c091c3c */
if(!s->budget--) { s->failed_pc=0x0c091c3cu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c091c3e;
P_0c091c3e: /* original 1f65, guest PC 0x0c091c3e */
if(!s->budget--) { s->failed_pc=0x0c091c3eu; return 0; }
write(ram,r[15]+20,r[6],4);
goto P_0c091c40;
P_0c091c40: /* original 9094, guest PC 0x0c091c40 */
if(!s->budget--) { s->failed_pc=0x0c091c40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c091d6cu,2);
goto P_0c091c42;
P_0c091c42: /* original 0c5e, guest PC 0x0c091c42 */
if(!s->budget--) { s->failed_pc=0x0c091c42u; return 0; }
r[12]=read(ram,r[5]+r[0],4);
goto P_0c091c44;
P_0c091c44: /* original 7004, guest PC 0x0c091c44 */
if(!s->budget--) { s->failed_pc=0x0c091c44u; return 0; }
r[0]+=0x00000004u;
goto P_0c091c46;
P_0c091c46: /* original 045e, guest PC 0x0c091c46 */
if(!s->budget--) { s->failed_pc=0x0c091c46u; return 0; }
r[4]=read(ram,r[5]+r[0],4);
goto P_0c091c48;
P_0c091c48: /* original 63c1, guest PC 0x0c091c48 */
if(!s->budget--) { s->failed_pc=0x0c091c48u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[3]=tmp;
goto P_0c091c4a;
P_0c091c4a: /* original 6943, guest PC 0x0c091c4a */
if(!s->budget--) { s->failed_pc=0x0c091c4au; return 0; }
r[9]=r[4];
goto P_0c091c4c;
P_0c091c4c: /* original 793c, guest PC 0x0c091c4c */
if(!s->budget--) { s->failed_pc=0x0c091c4cu; return 0; }
r[9]+=0x0000003cu;
goto P_0c091c4e;
P_0c091c4e: /* original 2f31, guest PC 0x0c091c4e */
if(!s->budget--) { s->failed_pc=0x0c091c4eu; return 0; }
write(ram,r[15],r[3],2);
goto P_0c091c50;
P_0c091c50: /* original 6a43, guest PC 0x0c091c50 */
if(!s->budget--) { s->failed_pc=0x0c091c50u; return 0; }
r[10]=r[4];
goto P_0c091c52;
P_0c091c52: /* original d347, guest PC 0x0c091c52 */
if(!s->budget--) { s->failed_pc=0x0c091c52u; return 0; }
r[3]=read(ram,0x0c091d70u,4);
goto P_0c091c54;
P_0c091c54: /* original 430b, guest PC 0x0c091c54 */
if(!s->budget--) { s->failed_pc=0x0c091c54u; return 0; }
target=r[3];
r[16]=code_base|0x0c091c58u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091c58u) { target=s->pc; goto dispatch; }
goto P_0c091c58;
P_0c091c56: /* original 54f5, guest PC 0x0c091c56 */
if(!s->budget--) { s->failed_pc=0x0c091c56u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c091c58;
P_0c091c58: /* original d246, guest PC 0x0c091c58 */
if(!s->budget--) { s->failed_pc=0x0c091c58u; return 0; }
r[2]=read(ram,0x0c091d74u,4);
goto P_0c091c5a;
P_0c091c5a: /* original 420b, guest PC 0x0c091c5a */
if(!s->budget--) { s->failed_pc=0x0c091c5au; return 0; }
target=r[2];
r[16]=code_base|0x0c091c5eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091c5eu) { target=s->pc; goto dispatch; }
goto P_0c091c5e;
P_0c091c5c: /* original e400, guest PC 0x0c091c5c */
if(!s->budget--) { s->failed_pc=0x0c091c5cu; return 0; }
r[4]=0x00000000u;
goto P_0c091c5e;
P_0c091c5e: /* original 2bb8, guest PC 0x0c091c5e */
if(!s->budget--) { s->failed_pc=0x0c091c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c091c60;
P_0c091c60: /* original 8b02, guest PC 0x0c091c60 */
if(!s->budget--) { s->failed_pc=0x0c091c60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c091c68; }
goto P_0c091c62;
P_0c091c62: /* original d245, guest PC 0x0c091c62 */
if(!s->budget--) { s->failed_pc=0x0c091c62u; return 0; }
r[2]=read(ram,0x0c091d78u,4);
goto P_0c091c64;
P_0c091c64: /* original 420b, guest PC 0x0c091c64 */
if(!s->budget--) { s->failed_pc=0x0c091c64u; return 0; }
target=r[2];
r[16]=code_base|0x0c091c68u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091c68u) { target=s->pc; goto dispatch; }
goto P_0c091c68;
P_0c091c66: /* original 0009, guest PC 0x0c091c66 */
if(!s->budget--) { s->failed_pc=0x0c091c66u; return 0; }
goto P_0c091c68;
P_0c091c68: /* original d344, guest PC 0x0c091c68 */
if(!s->budget--) { s->failed_pc=0x0c091c68u; return 0; }
r[3]=read(ram,0x0c091d7cu,4);
goto P_0c091c6a;
P_0c091c6a: /* original 430b, guest PC 0x0c091c6a */
if(!s->budget--) { s->failed_pc=0x0c091c6au; return 0; }
target=r[3];
r[16]=code_base|0x0c091c6eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091c6eu) { target=s->pc; goto dispatch; }
goto P_0c091c6e;
P_0c091c6c: /* original e401, guest PC 0x0c091c6c */
if(!s->budget--) { s->failed_pc=0x0c091c6cu; return 0; }
r[4]=0x00000001u;
goto P_0c091c6e;
P_0c091c6e: /* original 64f1, guest PC 0x0c091c6e */
if(!s->budget--) { s->failed_pc=0x0c091c6eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c091c70;
P_0c091c70: /* original d843, guest PC 0x0c091c70 */
if(!s->budget--) { s->failed_pc=0x0c091c70u; return 0; }
r[8]=read(ram,0x0c091d80u,4);
goto P_0c091c72;
P_0c091c72: /* original 480b, guest PC 0x0c091c72 */
if(!s->budget--) { s->failed_pc=0x0c091c72u; return 0; }
target=r[8];
r[16]=code_base|0x0c091c76u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091c76u) { target=s->pc; goto dispatch; }
goto P_0c091c76;
P_0c091c74: /* original 644d, guest PC 0x0c091c74 */
if(!s->budget--) { s->failed_pc=0x0c091c74u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091c76;
P_0c091c76: /* original d33f, guest PC 0x0c091c76 */
if(!s->budget--) { s->failed_pc=0x0c091c76u; return 0; }
r[3]=read(ram,0x0c091d74u,4);
goto P_0c091c78;
P_0c091c78: /* original 6ec3, guest PC 0x0c091c78 */
if(!s->budget--) { s->failed_pc=0x0c091c78u; return 0; }
r[14]=r[12];
goto P_0c091c7a;
P_0c091c7a: /* original 7e02, guest PC 0x0c091c7a */
if(!s->budget--) { s->failed_pc=0x0c091c7au; return 0; }
r[14]+=0x00000002u;
goto P_0c091c7c;
P_0c091c7c: /* original 430b, guest PC 0x0c091c7c */
if(!s->budget--) { s->failed_pc=0x0c091c7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c091c80u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091c80u) { target=s->pc; goto dispatch; }
goto P_0c091c80;
P_0c091c7e: /* original e400, guest PC 0x0c091c7e */
if(!s->budget--) { s->failed_pc=0x0c091c7eu; return 0; }
r[4]=0x00000000u;
goto P_0c091c80;
P_0c091c80: /* original e200, guest PC 0x0c091c80 */
if(!s->budget--) { s->failed_pc=0x0c091c80u; return 0; }
r[2]=0x00000000u;
goto P_0c091c82;
P_0c091c82: /* original 2f22, guest PC 0x0c091c82 */
if(!s->budget--) { s->failed_pc=0x0c091c82u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c091c84;
P_0c091c84: /* original d33f, guest PC 0x0c091c84 */
if(!s->budget--) { s->failed_pc=0x0c091c84u; return 0; }
r[3]=read(ram,0x0c091d84u,4);
goto P_0c091c86;
P_0c091c86: /* original ff8d, guest PC 0x0c091c86 */
if(!s->budget--) { s->failed_pc=0x0c091c86u; return 0; }
fr[15]=0;
goto P_0c091c88;
P_0c091c88: /* original 1f35, guest PC 0x0c091c88 */
if(!s->budget--) { s->failed_pc=0x0c091c88u; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c091c8a;
P_0c091c8a: /* original 60d1, guest PC 0x0c091c8a */
if(!s->budget--) { s->failed_pc=0x0c091c8au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[0]=tmp;
goto P_0c091c8c;
P_0c091c8c: /* original 2bb8, guest PC 0x0c091c8c */
if(!s->budget--) { s->failed_pc=0x0c091c8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c091c8e;
P_0c091c8e: /* original 81f4, guest PC 0x0c091c8e */
if(!s->budget--) { s->failed_pc=0x0c091c8eu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091c90;
P_0c091c90: /* original 85d1, guest PC 0x0c091c90 */
if(!s->budget--) { s->failed_pc=0x0c091c90u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+2,2);
goto P_0c091c92;
P_0c091c92: /* original 81fe, guest PC 0x0c091c92 */
if(!s->budget--) { s->failed_pc=0x0c091c92u; return 0; }
write(ram,r[15]+28,r[0],2);
goto P_0c091c94;
P_0c091c94: /* original 85d2, guest PC 0x0c091c94 */
if(!s->budget--) { s->failed_pc=0x0c091c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c091c96;
P_0c091c96: /* original 81f6, guest PC 0x0c091c96 */
if(!s->budget--) { s->failed_pc=0x0c091c96u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c091c98;
P_0c091c98: /* original 85d3, guest PC 0x0c091c98 */
if(!s->budget--) { s->failed_pc=0x0c091c98u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+6,2);
goto P_0c091c9a;
P_0c091c9a: /* original 81f2, guest PC 0x0c091c9a */
if(!s->budget--) { s->failed_pc=0x0c091c9au; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091c9c;
P_0c091c9c: /* original 85d4, guest PC 0x0c091c9c */
if(!s->budget--) { s->failed_pc=0x0c091c9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+8,2);
goto P_0c091c9e;
P_0c091c9e: /* original 81f8, guest PC 0x0c091c9e */
if(!s->budget--) { s->failed_pc=0x0c091c9eu; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c091ca0;
P_0c091ca0: /* original f4a9, guest PC 0x0c091ca0 */
if(!s->budget--) { s->failed_pc=0x0c091ca0u; return 0; }
vf3_matrix_load(s,ram,4,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca2;
P_0c091ca2: /* original fd99, guest PC 0x0c091ca2 */
if(!s->budget--) { s->failed_pc=0x0c091ca2u; return 0; }
vf3_matrix_load(s,ram,13,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca4;
P_0c091ca4: /* original f5a9, guest PC 0x0c091ca4 */
if(!s->budget--) { s->failed_pc=0x0c091ca4u; return 0; }
vf3_matrix_load(s,ram,5,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca6;
P_0c091ca6: /* original f6a9, guest PC 0x0c091ca6 */
if(!s->budget--) { s->failed_pc=0x0c091ca6u; return 0; }
vf3_matrix_load(s,ram,6,r[10]);
r[10]+=(r[18]&0x100000u)?8:4;
goto P_0c091ca8;
P_0c091ca8: /* original 8f0d, guest PC 0x0c091ca8 */
if(!s->budget--) { s->failed_pc=0x0c091ca8u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
if(!cond) { goto P_0c091cc6; }
goto P_0c091cac;
P_0c091caa: /* original fe99, guest PC 0x0c091caa */
if(!s->budget--) { s->failed_pc=0x0c091caau; return 0; }
vf3_matrix_load(s,ram,14,r[9]);
r[9]+=(r[18]&0x100000u)?8:4;
goto P_0c091cac;
P_0c091cac: /* original 85f4, guest PC 0x0c091cac */
if(!s->budget--) { s->failed_pc=0x0c091cacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091cae;
P_0c091cae: /* original 600b, guest PC 0x0c091cae */
if(!s->budget--) { s->failed_pc=0x0c091caeu; return 0; }
r[0]=0u-r[0];
goto P_0c091cb0;
P_0c091cb0: /* original 81f4, guest PC 0x0c091cb0 */
if(!s->budget--) { s->failed_pc=0x0c091cb0u; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091cb2;
P_0c091cb2: /* original 85f6, guest PC 0x0c091cb2 */
if(!s->budget--) { s->failed_pc=0x0c091cb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c091cb4;
P_0c091cb4: /* original 600b, guest PC 0x0c091cb4 */
if(!s->budget--) { s->failed_pc=0x0c091cb4u; return 0; }
r[0]=0u-r[0];
goto P_0c091cb6;
P_0c091cb6: /* original 81f6, guest PC 0x0c091cb6 */
if(!s->budget--) { s->failed_pc=0x0c091cb6u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c091cb8;
P_0c091cb8: /* original 85f2, guest PC 0x0c091cb8 */
if(!s->budget--) { s->failed_pc=0x0c091cb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091cba;
P_0c091cba: /* original 600b, guest PC 0x0c091cba */
if(!s->budget--) { s->failed_pc=0x0c091cbau; return 0; }
r[0]=0u-r[0];
goto P_0c091cbc;
P_0c091cbc: /* original 81f2, guest PC 0x0c091cbc */
if(!s->budget--) { s->failed_pc=0x0c091cbcu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091cbe;
P_0c091cbe: /* original 85f8, guest PC 0x0c091cbe */
if(!s->budget--) { s->failed_pc=0x0c091cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c091cc0;
P_0c091cc0: /* original 600b, guest PC 0x0c091cc0 */
if(!s->budget--) { s->failed_pc=0x0c091cc0u; return 0; }
r[0]=0u-r[0];
goto P_0c091cc2;
P_0c091cc2: /* original 81f8, guest PC 0x0c091cc2 */
if(!s->budget--) { s->failed_pc=0x0c091cc2u; return 0; }
write(ram,r[15]+16,r[0],2);
goto P_0c091cc4;
P_0c091cc4: /* original f64d, guest PC 0x0c091cc4 */
if(!s->budget--) { s->failed_pc=0x0c091cc4u; return 0; }
fr[6]^=0x80000000u;
goto P_0c091cc6;
P_0c091cc6: /* original 63f2, guest PC 0x0c091cc6 */
if(!s->budget--) { s->failed_pc=0x0c091cc6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091cc8;
P_0c091cc8: /* original 2338, guest PC 0x0c091cc8 */
if(!s->budget--) { s->failed_pc=0x0c091cc8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c091cca;
P_0c091cca: /* original 8d03, guest PC 0x0c091cca */
if(!s->budget--) { s->failed_pc=0x0c091ccau; return 0; }
cond=r[17]&1u;
fr[6]^=0x80000000u;
if(cond) { goto P_0c091cd4; }
goto P_0c091cce;
P_0c091ccc: /* original f64d, guest PC 0x0c091ccc */
if(!s->budget--) { s->failed_pc=0x0c091cccu; return 0; }
fr[6]^=0x80000000u;
goto P_0c091cce;
P_0c091cce: /* original d32e, guest PC 0x0c091cce */
if(!s->budget--) { s->failed_pc=0x0c091cceu; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091cd0;
P_0c091cd0: /* original 430b, guest PC 0x0c091cd0 */
if(!s->budget--) { s->failed_pc=0x0c091cd0u; return 0; }
target=r[3];
r[16]=code_base|0x0c091cd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091cd4u) { target=s->pc; goto dispatch; }
goto P_0c091cd4;
P_0c091cd2: /* original 0009, guest PC 0x0c091cd2 */
if(!s->budget--) { s->failed_pc=0x0c091cd2u; return 0; }
goto P_0c091cd4;
P_0c091cd4: /* original 60e5, guest PC 0x0c091cd4 */
if(!s->budget--) { s->failed_pc=0x0c091cd4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091cd6;
P_0c091cd6: /* original 81fc, guest PC 0x0c091cd6 */
if(!s->budget--) { s->failed_pc=0x0c091cd6u; return 0; }
write(ram,r[15]+24,r[0],2);
goto P_0c091cd8;
P_0c091cd8: /* original d32c, guest PC 0x0c091cd8 */
if(!s->budget--) { s->failed_pc=0x0c091cd8u; return 0; }
r[3]=read(ram,0x0c091d8cu,4);
goto P_0c091cda;
P_0c091cda: /* original 85fe, guest PC 0x0c091cda */
if(!s->budget--) { s->failed_pc=0x0c091cdau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+28,2);
goto P_0c091cdc;
P_0c091cdc: /* original 430b, guest PC 0x0c091cdc */
if(!s->budget--) { s->failed_pc=0x0c091cdcu; return 0; }
target=r[3];
r[16]=code_base|0x0c091ce0u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091ce0u) { target=s->pc; goto dispatch; }
goto P_0c091ce0;
P_0c091cde: /* original 6403, guest PC 0x0c091cde */
if(!s->budget--) { s->failed_pc=0x0c091cdeu; return 0; }
r[4]=r[0];
goto P_0c091ce0;
P_0c091ce0: /* original d32b, guest PC 0x0c091ce0 */
if(!s->budget--) { s->failed_pc=0x0c091ce0u; return 0; }
r[3]=read(ram,0x0c091d90u,4);
goto P_0c091ce2;
P_0c091ce2: /* original 85f4, guest PC 0x0c091ce2 */
if(!s->budget--) { s->failed_pc=0x0c091ce2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091ce4;
P_0c091ce4: /* original 430b, guest PC 0x0c091ce4 */
if(!s->budget--) { s->failed_pc=0x0c091ce4u; return 0; }
target=r[3];
r[16]=code_base|0x0c091ce8u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091ce8u) { target=s->pc; goto dispatch; }
goto P_0c091ce8;
P_0c091ce6: /* original 6403, guest PC 0x0c091ce6 */
if(!s->budget--) { s->failed_pc=0x0c091ce6u; return 0; }
r[4]=r[0];
goto P_0c091ce8;
P_0c091ce8: /* original d32a, guest PC 0x0c091ce8 */
if(!s->budget--) { s->failed_pc=0x0c091ce8u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091cea;
P_0c091cea: /* original 85f6, guest PC 0x0c091cea */
if(!s->budget--) { s->failed_pc=0x0c091ceau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c091cec;
P_0c091cec: /* original 430b, guest PC 0x0c091cec */
if(!s->budget--) { s->failed_pc=0x0c091cecu; return 0; }
target=r[3];
r[16]=code_base|0x0c091cf0u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091cf0u) { target=s->pc; goto dispatch; }
goto P_0c091cf0;
P_0c091cee: /* original 6403, guest PC 0x0c091cee */
if(!s->budget--) { s->failed_pc=0x0c091ceeu; return 0; }
r[4]=r[0];
goto P_0c091cf0;
P_0c091cf0: /* original 85fc, guest PC 0x0c091cf0 */
if(!s->budget--) { s->failed_pc=0x0c091cf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+24,2);
goto P_0c091cf2;
P_0c091cf2: /* original 6403, guest PC 0x0c091cf2 */
if(!s->budget--) { s->failed_pc=0x0c091cf2u; return 0; }
r[4]=r[0];
goto P_0c091cf4;
P_0c091cf4: /* original 480b, guest PC 0x0c091cf4 */
if(!s->budget--) { s->failed_pc=0x0c091cf4u; return 0; }
target=r[8];
r[16]=code_base|0x0c091cf8u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091cf8u) { target=s->pc; goto dispatch; }
goto P_0c091cf8;
P_0c091cf6: /* original 644d, guest PC 0x0c091cf6 */
if(!s->budget--) { s->failed_pc=0x0c091cf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091cf8;
P_0c091cf8: /* original 60e5, guest PC 0x0c091cf8 */
if(!s->budget--) { s->failed_pc=0x0c091cf8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091cfa;
P_0c091cfa: /* original 81f4, guest PC 0x0c091cfa */
if(!s->budget--) { s->failed_pc=0x0c091cfau; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c091cfc;
P_0c091cfc: /* original d322, guest PC 0x0c091cfc */
if(!s->budget--) { s->failed_pc=0x0c091cfcu; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091cfe;
P_0c091cfe: /* original f5fc, guest PC 0x0c091cfe */
if(!s->budget--) { s->failed_pc=0x0c091cfeu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091d00;
P_0c091d00: /* original f6fc, guest PC 0x0c091d00 */
if(!s->budget--) { s->failed_pc=0x0c091d00u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c091d02;
P_0c091d02: /* original 430b, guest PC 0x0c091d02 */
if(!s->budget--) { s->failed_pc=0x0c091d02u; return 0; }
target=r[3];
r[16]=code_base|0x0c091d06u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091d06u) { target=s->pc; goto dispatch; }
goto P_0c091d06;
P_0c091d04: /* original f4dc, guest PC 0x0c091d04 */
if(!s->budget--) { s->failed_pc=0x0c091d04u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c091d06;
P_0c091d06: /* original d323, guest PC 0x0c091d06 */
if(!s->budget--) { s->failed_pc=0x0c091d06u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091d08;
P_0c091d08: /* original 85f2, guest PC 0x0c091d08 */
if(!s->budget--) { s->failed_pc=0x0c091d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091d0a;
P_0c091d0a: /* original 430b, guest PC 0x0c091d0a */
if(!s->budget--) { s->failed_pc=0x0c091d0au; return 0; }
target=r[3];
r[16]=code_base|0x0c091d0eu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091d0eu) { target=s->pc; goto dispatch; }
goto P_0c091d0e;
P_0c091d0c: /* original 6403, guest PC 0x0c091d0c */
if(!s->budget--) { s->failed_pc=0x0c091d0cu; return 0; }
r[4]=r[0];
goto P_0c091d0e;
P_0c091d0e: /* original 85f4, guest PC 0x0c091d0e */
if(!s->budget--) { s->failed_pc=0x0c091d0eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+8,2);
goto P_0c091d10;
P_0c091d10: /* original 6403, guest PC 0x0c091d10 */
if(!s->budget--) { s->failed_pc=0x0c091d10u; return 0; }
r[4]=r[0];
goto P_0c091d12;
P_0c091d12: /* original 480b, guest PC 0x0c091d12 */
if(!s->budget--) { s->failed_pc=0x0c091d12u; return 0; }
target=r[8];
r[16]=code_base|0x0c091d16u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091d16u) { target=s->pc; goto dispatch; }
goto P_0c091d16;
P_0c091d14: /* original 644d, guest PC 0x0c091d14 */
if(!s->budget--) { s->failed_pc=0x0c091d14u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091d16;
P_0c091d16: /* original 60e5, guest PC 0x0c091d16 */
if(!s->budget--) { s->failed_pc=0x0c091d16u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]+=2;
r[0]=tmp;
goto P_0c091d18;
P_0c091d18: /* original 81f2, guest PC 0x0c091d18 */
if(!s->budget--) { s->failed_pc=0x0c091d18u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c091d1a;
P_0c091d1a: /* original d31b, guest PC 0x0c091d1a */
if(!s->budget--) { s->failed_pc=0x0c091d1au; return 0; }
r[3]=read(ram,0x0c091d88u,4);
goto P_0c091d1c;
P_0c091d1c: /* original f5fc, guest PC 0x0c091d1c */
if(!s->budget--) { s->failed_pc=0x0c091d1cu; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c091d1e;
P_0c091d1e: /* original f6fc, guest PC 0x0c091d1e */
if(!s->budget--) { s->failed_pc=0x0c091d1eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c091d20;
P_0c091d20: /* original 430b, guest PC 0x0c091d20 */
if(!s->budget--) { s->failed_pc=0x0c091d20u; return 0; }
target=r[3];
r[16]=code_base|0x0c091d24u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091d24u) { target=s->pc; goto dispatch; }
goto P_0c091d24;
P_0c091d22: /* original f4ec, guest PC 0x0c091d22 */
if(!s->budget--) { s->failed_pc=0x0c091d22u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c091d24;
P_0c091d24: /* original d31b, guest PC 0x0c091d24 */
if(!s->budget--) { s->failed_pc=0x0c091d24u; return 0; }
r[3]=read(ram,0x0c091d94u,4);
goto P_0c091d26;
P_0c091d26: /* original 85f8, guest PC 0x0c091d26 */
if(!s->budget--) { s->failed_pc=0x0c091d26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+16,2);
goto P_0c091d28;
P_0c091d28: /* original 430b, guest PC 0x0c091d28 */
if(!s->budget--) { s->failed_pc=0x0c091d28u; return 0; }
target=r[3];
r[16]=code_base|0x0c091d2cu;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091d2cu) { target=s->pc; goto dispatch; }
goto P_0c091d2c;
P_0c091d2a: /* original 6403, guest PC 0x0c091d2a */
if(!s->budget--) { s->failed_pc=0x0c091d2au; return 0; }
r[4]=r[0];
goto P_0c091d2c;
P_0c091d2c: /* original 85f2, guest PC 0x0c091d2c */
if(!s->budget--) { s->failed_pc=0x0c091d2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c091d2e;
P_0c091d2e: /* original 6403, guest PC 0x0c091d2e */
if(!s->budget--) { s->failed_pc=0x0c091d2eu; return 0; }
r[4]=r[0];
goto P_0c091d30;
P_0c091d30: /* original 480b, guest PC 0x0c091d30 */
if(!s->budget--) { s->failed_pc=0x0c091d30u; return 0; }
target=r[8];
r[16]=code_base|0x0c091d34u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c091d34u) { target=s->pc; goto dispatch; }
goto P_0c091d34;
P_0c091d32: /* original 644d, guest PC 0x0c091d32 */
if(!s->budget--) { s->failed_pc=0x0c091d32u; return 0; }
r[4]=r[4]&65535u;
goto P_0c091d34;
P_0c091d34: /* original 54f5, guest PC 0x0c091d34 */
if(!s->budget--) { s->failed_pc=0x0c091d34u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c091d36;
P_0c091d36: /* original fbfd, guest PC 0x0c091d36 */
if(!s->budget--) { s->failed_pc=0x0c091d36u; return 0; }
vf3_matrix_swap(s);
goto P_0c091d38;
P_0c091d38: /* original 63f2, guest PC 0x0c091d38 */
if(!s->budget--) { s->failed_pc=0x0c091d38u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c091d3a;
P_0c091d3a: /* original e205, guest PC 0x0c091d3a */
if(!s->budget--) { s->failed_pc=0x0c091d3au; return 0; }
r[2]=0x00000005u;
goto P_0c091d3c;
P_0c091d3c: /* original 5442, guest PC 0x0c091d3c */
if(!s->budget--) { s->failed_pc=0x0c091d3cu; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c091d3e;
P_0c091d3e: /* original 7d0a, guest PC 0x0c091d3e */
if(!s->budget--) { s->failed_pc=0x0c091d3eu; return 0; }
r[13]+=0x0000000au;
goto P_0c091d40;
P_0c091d40: /* original 7301, guest PC 0x0c091d40 */
if(!s->budget--) { s->failed_pc=0x0c091d40u; return 0; }
r[3]+=0x00000001u;
goto P_0c091d42;
P_0c091d42: /* original 74c0, guest PC 0x0c091d42 */
if(!s->budget--) { s->failed_pc=0x0c091d42u; return 0; }
r[4]+=0xffffffc0u;
goto P_0c091d44;
P_0c091d44: /* original 3323, guest PC 0x0c091d44 */
if(!s->budget--) { s->failed_pc=0x0c091d44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c091d46;
P_0c091d46: /* original f049, guest PC 0x0c091d46 */
if(!s->budget--) { s->failed_pc=0x0c091d46u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d48;
P_0c091d48: /* original f149, guest PC 0x0c091d48 */
if(!s->budget--) { s->failed_pc=0x0c091d48u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4a;
P_0c091d4a: /* original f249, guest PC 0x0c091d4a */
if(!s->budget--) { s->failed_pc=0x0c091d4au; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4c;
P_0c091d4c: /* original f349, guest PC 0x0c091d4c */
if(!s->budget--) { s->failed_pc=0x0c091d4cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d4e;
P_0c091d4e: /* original f449, guest PC 0x0c091d4e */
if(!s->budget--) { s->failed_pc=0x0c091d4eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d50;
P_0c091d50: /* original f549, guest PC 0x0c091d50 */
if(!s->budget--) { s->failed_pc=0x0c091d50u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d52;
P_0c091d52: /* original f649, guest PC 0x0c091d52 */
if(!s->budget--) { s->failed_pc=0x0c091d52u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d54;
P_0c091d54: /* original f749, guest PC 0x0c091d54 */
if(!s->budget--) { s->failed_pc=0x0c091d54u; return 0; }
vf3_matrix_load(s,ram,7,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d56;
P_0c091d56: /* original f849, guest PC 0x0c091d56 */
if(!s->budget--) { s->failed_pc=0x0c091d56u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d58;
P_0c091d58: /* original f949, guest PC 0x0c091d58 */
if(!s->budget--) { s->failed_pc=0x0c091d58u; return 0; }
vf3_matrix_load(s,ram,9,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5a;
P_0c091d5a: /* original fa49, guest PC 0x0c091d5a */
if(!s->budget--) { s->failed_pc=0x0c091d5au; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5c;
P_0c091d5c: /* original fb49, guest PC 0x0c091d5c */
if(!s->budget--) { s->failed_pc=0x0c091d5cu; return 0; }
vf3_matrix_load(s,ram,11,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d5e;
P_0c091d5e: /* original fc49, guest PC 0x0c091d5e */
if(!s->budget--) { s->failed_pc=0x0c091d5eu; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d60;
P_0c091d60: /* original fd49, guest PC 0x0c091d60 */
if(!s->budget--) { s->failed_pc=0x0c091d60u; return 0; }
vf3_matrix_load(s,ram,13,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d62;
P_0c091d62: /* original fe49, guest PC 0x0c091d62 */
if(!s->budget--) { s->failed_pc=0x0c091d62u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d64;
P_0c091d64: /* original ff49, guest PC 0x0c091d64 */
if(!s->budget--) { s->failed_pc=0x0c091d64u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c091d66;
P_0c091d66: /* original fbfd, guest PC 0x0c091d66 */
if(!s->budget--) { s->failed_pc=0x0c091d66u; return 0; }
vf3_matrix_swap(s);
goto P_0c091d68;
P_0c091d68: /* original a016, guest PC 0x0c091d68 */
if(!s->budget--) { s->failed_pc=0x0c091d68u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c091d98;
P_0c091d6a: /* original 2f32, guest PC 0x0c091d6a */
if(!s->budget--) { s->failed_pc=0x0c091d6au; return 0; }
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(0x0c091d6cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091d6cu; return 0; } return 1;
P_0c091d98: /* original 8d02, guest PC 0x0c091d98 */
if(!s->budget--) { s->failed_pc=0x0c091d98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c091da0; }
goto P_0c091d9c;
P_0c091d9a: /* original 0009, guest PC 0x0c091d9a */
if(!s->budget--) { s->failed_pc=0x0c091d9au; return 0; }
goto P_0c091d9c;
P_0c091d9c: /* original af75, guest PC 0x0c091d9c */
if(!s->budget--) { s->failed_pc=0x0c091d9cu; return 0; }
goto P_0c091c8a;
P_0c091d9e: /* original 0009, guest PC 0x0c091d9e */
if(!s->budget--) { s->failed_pc=0x0c091d9eu; return 0; }
goto P_0c091da0;
P_0c091da0: /* original 7f20, guest PC 0x0c091da0 */
if(!s->budget--) { s->failed_pc=0x0c091da0u; return 0; }
r[15]+=0x00000020u;
goto P_0c091da2;
P_0c091da2: /* original d332, guest PC 0x0c091da2 */
if(!s->budget--) { s->failed_pc=0x0c091da2u; return 0; }
r[3]=read(ram,0x0c091e6cu,4);
goto P_0c091da4;
P_0c091da4: /* original 4f26, guest PC 0x0c091da4 */
if(!s->budget--) { s->failed_pc=0x0c091da4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c091da6;
P_0c091da6: /* original e401, guest PC 0x0c091da6 */
if(!s->budget--) { s->failed_pc=0x0c091da6u; return 0; }
r[4]=0x00000001u;
goto P_0c091da8;
P_0c091da8: /* original fdf9, guest PC 0x0c091da8 */
if(!s->budget--) { s->failed_pc=0x0c091da8u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091daa;
P_0c091daa: /* original fef9, guest PC 0x0c091daa */
if(!s->budget--) { s->failed_pc=0x0c091daau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091dac;
P_0c091dac: /* original fff9, guest PC 0x0c091dac */
if(!s->budget--) { s->failed_pc=0x0c091dacu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c091dae;
P_0c091dae: /* original 68f6, guest PC 0x0c091dae */
if(!s->budget--) { s->failed_pc=0x0c091daeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c091db0;
P_0c091db0: /* original 69f6, guest PC 0x0c091db0 */
if(!s->budget--) { s->failed_pc=0x0c091db0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c091db2;
P_0c091db2: /* original 6af6, guest PC 0x0c091db2 */
if(!s->budget--) { s->failed_pc=0x0c091db2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c091db4;
P_0c091db4: /* original 6bf6, guest PC 0x0c091db4 */
if(!s->budget--) { s->failed_pc=0x0c091db4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c091db6;
P_0c091db6: /* original 6cf6, guest PC 0x0c091db6 */
if(!s->budget--) { s->failed_pc=0x0c091db6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c091db8;
P_0c091db8: /* original 6df6, guest PC 0x0c091db8 */
if(!s->budget--) { s->failed_pc=0x0c091db8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c091dba;
P_0c091dba: /* original 432b, guest PC 0x0c091dba */
if(!s->budget--) { s->failed_pc=0x0c091dbau; return 0; }
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
P_0c091dbc: /* original 6ef6, guest PC 0x0c091dbc */
if(!s->budget--) { s->failed_pc=0x0c091dbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c091dbeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091dbeu; return 0; } return 1;
P_0c091e4c: /* original 6653, guest PC 0x0c091e4c */
if(!s->budget--) { s->failed_pc=0x0c091e4cu; return 0; }
r[6]=r[5];
goto P_0c091e4e;
P_0c091e4e: /* original a003, guest PC 0x0c091e4e */
if(!s->budget--) { s->failed_pc=0x0c091e4eu; return 0; }
r[5]=0x0000001au;
goto P_0c091e58;
P_0c091e50: /* original e51a, guest PC 0x0c091e50 */
if(!s->budget--) { s->failed_pc=0x0c091e50u; return 0; }
r[5]=0x0000001au;
goto P_0c091e52;
P_0c091e52: /* original 6345, guest PC 0x0c091e52 */
if(!s->budget--) { s->failed_pc=0x0c091e52u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]+=2;
r[3]=tmp;
goto P_0c091e54;
P_0c091e54: /* original 2631, guest PC 0x0c091e54 */
if(!s->budget--) { s->failed_pc=0x0c091e54u; return 0; }
write(ram,r[6],r[3],2);
goto P_0c091e56;
P_0c091e56: /* original 7602, guest PC 0x0c091e56 */
if(!s->budget--) { s->failed_pc=0x0c091e56u; return 0; }
r[6]+=0x00000002u;
goto P_0c091e58;
P_0c091e58: /* original 4515, guest PC 0x0c091e58 */
if(!s->budget--) { s->failed_pc=0x0c091e58u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c091e5a;
P_0c091e5a: /* original 8dfa, guest PC 0x0c091e5a */
if(!s->budget--) { s->failed_pc=0x0c091e5au; return 0; }
cond=r[17]&1u;
r[5]+=0xffffffffu;
if(cond) { goto P_0c091e52; }
goto P_0c091e5e;
P_0c091e5c: /* original 75ff, guest PC 0x0c091e5c */
if(!s->budget--) { s->failed_pc=0x0c091e5cu; return 0; }
r[5]+=0xffffffffu;
goto P_0c091e5e;
P_0c091e5e: /* original 000b, guest PC 0x0c091e5e */
if(!s->budget--) { s->failed_pc=0x0c091e5eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c091e60: /* original 0009, guest PC 0x0c091e60 */
if(!s->budget--) { s->failed_pc=0x0c091e60u; return 0; }
if(!vf3_matrix_family(0x0c091e62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c091e62u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
