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
int vf3_away_batch14_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c088b44u: goto P_0c088b44;
case 0x0c088b46u: goto P_0c088b46;
case 0x0c088b48u: goto P_0c088b48;
case 0x0c088b4au: goto P_0c088b4a;
case 0x0c088b4cu: goto P_0c088b4c;
case 0x0c088b4eu: goto P_0c088b4e;
case 0x0c088b50u: goto P_0c088b50;
case 0x0c088b52u: goto P_0c088b52;
case 0x0c088b54u: goto P_0c088b54;
case 0x0c088b56u: goto P_0c088b56;
case 0x0c088b58u: goto P_0c088b58;
case 0x0c088b5au: goto P_0c088b5a;
case 0x0c088b5cu: goto P_0c088b5c;
case 0x0c088b5eu: goto P_0c088b5e;
case 0x0c088b60u: goto P_0c088b60;
case 0x0c088b62u: goto P_0c088b62;
case 0x0c088b64u: goto P_0c088b64;
case 0x0c088b66u: goto P_0c088b66;
case 0x0c088b68u: goto P_0c088b68;
case 0x0c088b6au: goto P_0c088b6a;
case 0x0c088b6cu: goto P_0c088b6c;
case 0x0c088b6eu: goto P_0c088b6e;
case 0x0c088b70u: goto P_0c088b70;
case 0x0c088b72u: goto P_0c088b72;
case 0x0c088b74u: goto P_0c088b74;
case 0x0c088b76u: goto P_0c088b76;
case 0x0c088b78u: goto P_0c088b78;
case 0x0c088b7au: goto P_0c088b7a;
case 0x0c088b7cu: goto P_0c088b7c;
case 0x0c088b7eu: goto P_0c088b7e;
case 0x0c088b80u: goto P_0c088b80;
case 0x0c088b82u: goto P_0c088b82;
case 0x0c088b84u: goto P_0c088b84;
case 0x0c088b86u: goto P_0c088b86;
case 0x0c088b88u: goto P_0c088b88;
case 0x0c088b8au: goto P_0c088b8a;
case 0x0c088b8cu: goto P_0c088b8c;
case 0x0c088b8eu: goto P_0c088b8e;
case 0x0c088b90u: goto P_0c088b90;
case 0x0c088b92u: goto P_0c088b92;
case 0x0c088b94u: goto P_0c088b94;
case 0x0c088b96u: goto P_0c088b96;
case 0x0c088b98u: goto P_0c088b98;
case 0x0c088b9au: goto P_0c088b9a;
case 0x0c088b9cu: goto P_0c088b9c;
case 0x0c088b9eu: goto P_0c088b9e;
case 0x0c088ba0u: goto P_0c088ba0;
case 0x0c088ba2u: goto P_0c088ba2;
case 0x0c088ba4u: goto P_0c088ba4;
case 0x0c088ba6u: goto P_0c088ba6;
case 0x0c088ba8u: goto P_0c088ba8;
case 0x0c088baau: goto P_0c088baa;
case 0x0c088bacu: goto P_0c088bac;
case 0x0c088baeu: goto P_0c088bae;
case 0x0c088bb0u: goto P_0c088bb0;
case 0x0c088bb2u: goto P_0c088bb2;
case 0x0c088bb4u: goto P_0c088bb4;
case 0x0c088bb6u: goto P_0c088bb6;
case 0x0c088bb8u: goto P_0c088bb8;
case 0x0c088bbau: goto P_0c088bba;
case 0x0c088bbcu: goto P_0c088bbc;
case 0x0c088bbeu: goto P_0c088bbe;
case 0x0c088bc0u: goto P_0c088bc0;
case 0x0c088bc2u: goto P_0c088bc2;
case 0x0c088bc4u: goto P_0c088bc4;
case 0x0c088bc6u: goto P_0c088bc6;
case 0x0c088bc8u: goto P_0c088bc8;
case 0x0c088bcau: goto P_0c088bca;
case 0x0c088bccu: goto P_0c088bcc;
case 0x0c088bceu: goto P_0c088bce;
case 0x0c088bd0u: goto P_0c088bd0;
case 0x0c088bd2u: goto P_0c088bd2;
case 0x0c088bd4u: goto P_0c088bd4;
case 0x0c088bd6u: goto P_0c088bd6;
case 0x0c088bd8u: goto P_0c088bd8;
case 0x0c088bdau: goto P_0c088bda;
case 0x0c088bdcu: goto P_0c088bdc;
case 0x0c088bdeu: goto P_0c088bde;
case 0x0c088be0u: goto P_0c088be0;
case 0x0c088be2u: goto P_0c088be2;
case 0x0c088be4u: goto P_0c088be4;
case 0x0c088be6u: goto P_0c088be6;
case 0x0c088be8u: goto P_0c088be8;
case 0x0c088beau: goto P_0c088bea;
case 0x0c088becu: goto P_0c088bec;
case 0x0c088beeu: goto P_0c088bee;
case 0x0c088bf0u: goto P_0c088bf0;
case 0x0c088bf2u: goto P_0c088bf2;
case 0x0c088bf4u: goto P_0c088bf4;
case 0x0c088bf6u: goto P_0c088bf6;
case 0x0c088bf8u: goto P_0c088bf8;
case 0x0c088bfau: goto P_0c088bfa;
case 0x0c088bfcu: goto P_0c088bfc;
case 0x0c088bfeu: goto P_0c088bfe;
case 0x0c088c00u: goto P_0c088c00;
case 0x0c088c02u: goto P_0c088c02;
case 0x0c088c04u: goto P_0c088c04;
case 0x0c088c06u: goto P_0c088c06;
case 0x0c088c08u: goto P_0c088c08;
case 0x0c088c0au: goto P_0c088c0a;
case 0x0c088c0cu: goto P_0c088c0c;
case 0x0c088c0eu: goto P_0c088c0e;
case 0x0c088c10u: goto P_0c088c10;
case 0x0c088c34u: goto P_0c088c34;
case 0x0c088c36u: goto P_0c088c36;
case 0x0c088c38u: goto P_0c088c38;
case 0x0c088c3au: goto P_0c088c3a;
case 0x0c088c3cu: goto P_0c088c3c;
case 0x0c088c3eu: goto P_0c088c3e;
case 0x0c088c40u: goto P_0c088c40;
case 0x0c088c42u: goto P_0c088c42;
case 0x0c088c44u: goto P_0c088c44;
case 0x0c088c46u: goto P_0c088c46;
case 0x0c088c48u: goto P_0c088c48;
case 0x0c088c4au: goto P_0c088c4a;
case 0x0c088c4cu: goto P_0c088c4c;
case 0x0c088c4eu: goto P_0c088c4e;
case 0x0c088c50u: goto P_0c088c50;
case 0x0c088c52u: goto P_0c088c52;
case 0x0c088c54u: goto P_0c088c54;
case 0x0c088c56u: goto P_0c088c56;
case 0x0c088c58u: goto P_0c088c58;
case 0x0c088c5au: goto P_0c088c5a;
case 0x0c088c5cu: goto P_0c088c5c;
case 0x0c088c5eu: goto P_0c088c5e;
case 0x0c088c60u: goto P_0c088c60;
case 0x0c088c62u: goto P_0c088c62;
case 0x0c088c64u: goto P_0c088c64;
case 0x0c088c66u: goto P_0c088c66;
case 0x0c088c68u: goto P_0c088c68;
case 0x0c088c6au: goto P_0c088c6a;
case 0x0c088c6cu: goto P_0c088c6c;
case 0x0c088c6eu: goto P_0c088c6e;
case 0x0c088c70u: goto P_0c088c70;
case 0x0c088c72u: goto P_0c088c72;
case 0x0c088c74u: goto P_0c088c74;
case 0x0c088c76u: goto P_0c088c76;
case 0x0c088c78u: goto P_0c088c78;
case 0x0c088c7au: goto P_0c088c7a;
case 0x0c088c7cu: goto P_0c088c7c;
case 0x0c088c7eu: goto P_0c088c7e;
case 0x0c088c80u: goto P_0c088c80;
case 0x0c088c82u: goto P_0c088c82;
case 0x0c088c84u: goto P_0c088c84;
case 0x0c088c86u: goto P_0c088c86;
case 0x0c088c88u: goto P_0c088c88;
case 0x0c088c8au: goto P_0c088c8a;
case 0x0c088c8cu: goto P_0c088c8c;
case 0x0c088c8eu: goto P_0c088c8e;
case 0x0c088c90u: goto P_0c088c90;
case 0x0c088c92u: goto P_0c088c92;
case 0x0c088c94u: goto P_0c088c94;
case 0x0c088c96u: goto P_0c088c96;
case 0x0c088c98u: goto P_0c088c98;
case 0x0c088c9au: goto P_0c088c9a;
case 0x0c088c9cu: goto P_0c088c9c;
case 0x0c088c9eu: goto P_0c088c9e;
case 0x0c088ca0u: goto P_0c088ca0;
case 0x0c088ca2u: goto P_0c088ca2;
case 0x0c088ca4u: goto P_0c088ca4;
case 0x0c088ca6u: goto P_0c088ca6;
case 0x0c088ca8u: goto P_0c088ca8;
case 0x0c088caau: goto P_0c088caa;
case 0x0c088cacu: goto P_0c088cac;
case 0x0c088caeu: goto P_0c088cae;
case 0x0c088cb0u: goto P_0c088cb0;
case 0x0c088cb2u: goto P_0c088cb2;
case 0x0c088cb4u: goto P_0c088cb4;
case 0x0c088cb6u: goto P_0c088cb6;
case 0x0c088cb8u: goto P_0c088cb8;
case 0x0c088cbau: goto P_0c088cba;
case 0x0c088cbcu: goto P_0c088cbc;
case 0x0c088cbeu: goto P_0c088cbe;
case 0x0c088cc0u: goto P_0c088cc0;
case 0x0c088cc2u: goto P_0c088cc2;
case 0x0c088cc4u: goto P_0c088cc4;
case 0x0c088cc6u: goto P_0c088cc6;
case 0x0c088cc8u: goto P_0c088cc8;
case 0x0c088ccau: goto P_0c088cca;
case 0x0c088cccu: goto P_0c088ccc;
case 0x0c088cceu: goto P_0c088cce;
case 0x0c088cd0u: goto P_0c088cd0;
case 0x0c088cd2u: goto P_0c088cd2;
case 0x0c088cd4u: goto P_0c088cd4;
case 0x0c088cd6u: goto P_0c088cd6;
case 0x0c088cd8u: goto P_0c088cd8;
case 0x0c088cdau: goto P_0c088cda;
case 0x0c088cdcu: goto P_0c088cdc;
case 0x0c088cdeu: goto P_0c088cde;
case 0x0c088ce0u: goto P_0c088ce0;
case 0x0c088ce2u: goto P_0c088ce2;
case 0x0c088ce4u: goto P_0c088ce4;
case 0x0c088ce6u: goto P_0c088ce6;
case 0x0c088ce8u: goto P_0c088ce8;
case 0x0c088ceau: goto P_0c088cea;
case 0x0c088cecu: goto P_0c088cec;
case 0x0c088ceeu: goto P_0c088cee;
case 0x0c088cf0u: goto P_0c088cf0;
case 0x0c088cf2u: goto P_0c088cf2;
case 0x0c088cf4u: goto P_0c088cf4;
case 0x0c088cf6u: goto P_0c088cf6;
case 0x0c088cf8u: goto P_0c088cf8;
case 0x0c088cfau: goto P_0c088cfa;
case 0x0c088cfcu: goto P_0c088cfc;
case 0x0c088cfeu: goto P_0c088cfe;
case 0x0c088d00u: goto P_0c088d00;
case 0x0c088d02u: goto P_0c088d02;
case 0x0c088d04u: goto P_0c088d04;
default: return vf3_matrix_family(target,s,ram);
}
P_0c088b44: /* original 2fe6, guest PC 0x0c088b44 */
if(!s->budget--) { s->failed_pc=0x0c088b44u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b46;
P_0c088b46: /* original 6243, guest PC 0x0c088b46 */
if(!s->budget--) { s->failed_pc=0x0c088b46u; return 0; }
r[2]=r[4];
goto P_0c088b48;
P_0c088b48: /* original 2fd6, guest PC 0x0c088b48 */
if(!s->budget--) { s->failed_pc=0x0c088b48u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b4a;
P_0c088b4a: /* original 7208, guest PC 0x0c088b4a */
if(!s->budget--) { s->failed_pc=0x0c088b4au; return 0; }
r[2]+=0x00000008u;
goto P_0c088b4c;
P_0c088b4c: /* original 2fc6, guest PC 0x0c088b4c */
if(!s->budget--) { s->failed_pc=0x0c088b4cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b4e;
P_0c088b4e: /* original 2fb6, guest PC 0x0c088b4e */
if(!s->budget--) { s->failed_pc=0x0c088b4eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b50;
P_0c088b50: /* original 2fa6, guest PC 0x0c088b50 */
if(!s->budget--) { s->failed_pc=0x0c088b50u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b52;
P_0c088b52: /* original 2f96, guest PC 0x0c088b52 */
if(!s->budget--) { s->failed_pc=0x0c088b52u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b54;
P_0c088b54: /* original 2f86, guest PC 0x0c088b54 */
if(!s->budget--) { s->failed_pc=0x0c088b54u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088b56;
P_0c088b56: /* original fffb, guest PC 0x0c088b56 */
if(!s->budget--) { s->failed_pc=0x0c088b56u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c088b58;
P_0c088b58: /* original ffeb, guest PC 0x0c088b58 */
if(!s->budget--) { s->failed_pc=0x0c088b58u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c088b5a;
P_0c088b5a: /* original ffdb, guest PC 0x0c088b5a */
if(!s->budget--) { s->failed_pc=0x0c088b5au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c088b5c;
P_0c088b5c: /* original 4f22, guest PC 0x0c088b5c */
if(!s->budget--) { s->failed_pc=0x0c088b5cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088b5e;
P_0c088b5e: /* original d32d, guest PC 0x0c088b5e */
if(!s->budget--) { s->failed_pc=0x0c088b5eu; return 0; }
r[3]=read(ram,0x0c088c14u,4);
goto P_0c088b60;
P_0c088b60: /* original 7fec, guest PC 0x0c088b60 */
if(!s->budget--) { s->failed_pc=0x0c088b60u; return 0; }
r[15]+=0xffffffecu;
goto P_0c088b62;
P_0c088b62: /* original 2f32, guest PC 0x0c088b62 */
if(!s->budget--) { s->failed_pc=0x0c088b62u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c088b64;
P_0c088b64: /* original d32d, guest PC 0x0c088b64 */
if(!s->budget--) { s->failed_pc=0x0c088b64u; return 0; }
r[3]=read(ram,0x0c088c1cu,4);
goto P_0c088b66;
P_0c088b66: /* original dd2c, guest PC 0x0c088b66 */
if(!s->budget--) { s->failed_pc=0x0c088b66u; return 0; }
r[13]=read(ram,0x0c088c18u,4);
goto P_0c088b68;
P_0c088b68: /* original 1f34, guest PC 0x0c088b68 */
if(!s->budget--) { s->failed_pc=0x0c088b68u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c088b6a;
P_0c088b6a: /* original 1f22, guest PC 0x0c088b6a */
if(!s->budget--) { s->failed_pc=0x0c088b6au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c088b6c;
P_0c088b6c: /* original 8543, guest PC 0x0c088b6c */
if(!s->budget--) { s->failed_pc=0x0c088b6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+6,2);
goto P_0c088b6e;
P_0c088b6e: /* original 81f6, guest PC 0x0c088b6e */
if(!s->budget--) { s->failed_pc=0x0c088b6eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c088b70;
P_0c088b70: /* original e001, guest PC 0x0c088b70 */
if(!s->budget--) { s->failed_pc=0x0c088b70u; return 0; }
r[0]=0x00000001u;
goto P_0c088b72;
P_0c088b72: /* original 81f2, guest PC 0x0c088b72 */
if(!s->budget--) { s->failed_pc=0x0c088b72u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088b74;
P_0c088b74: /* original d32a, guest PC 0x0c088b74 */
if(!s->budget--) { s->failed_pc=0x0c088b74u; return 0; }
r[3]=read(ram,0x0c088c20u,4);
goto P_0c088b76;
P_0c088b76: /* original 430b, guest PC 0x0c088b76 */
if(!s->budget--) { s->failed_pc=0x0c088b76u; return 0; }
target=r[3];
r[16]=code_base|0x0c088b7au;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088b7au) { target=s->pc; goto dispatch; }
goto P_0c088b7a;
P_0c088b78: /* original e400, guest PC 0x0c088b78 */
if(!s->budget--) { s->failed_pc=0x0c088b78u; return 0; }
r[4]=0x00000000u;
goto P_0c088b7a;
P_0c088b7a: /* original dc2c, guest PC 0x0c088b7a */
if(!s->budget--) { s->failed_pc=0x0c088b7au; return 0; }
r[12]=read(ram,0x0c088c2cu,4);
goto P_0c088b7c;
P_0c088b7c: /* original e80e, guest PC 0x0c088b7c */
if(!s->budget--) { s->failed_pc=0x0c088b7cu; return 0; }
r[8]=0x0000000eu;
goto P_0c088b7e;
P_0c088b7e: /* original db2a, guest PC 0x0c088b7e */
if(!s->budget--) { s->failed_pc=0x0c088b7eu; return 0; }
r[11]=read(ram,0x0c088c28u,4);
goto P_0c088b80;
P_0c088b80: /* original da28, guest PC 0x0c088b80 */
if(!s->budget--) { s->failed_pc=0x0c088b80u; return 0; }
r[10]=read(ram,0x0c088c24u,4);
goto P_0c088b82;
P_0c088b82: /* original 85f6, guest PC 0x0c088b82 */
if(!s->budget--) { s->failed_pc=0x0c088b82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c088b84;
P_0c088b84: /* original fed9, guest PC 0x0c088b84 */
if(!s->budget--) { s->failed_pc=0x0c088b84u; return 0; }
vf3_matrix_load(s,ram,14,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c088b86;
P_0c088b86: /* original 600d, guest PC 0x0c088b86 */
if(!s->budget--) { s->failed_pc=0x0c088b86u; return 0; }
r[0]=r[0]&65535u;
goto P_0c088b88;
P_0c088b88: /* original fdd9, guest PC 0x0c088b88 */
if(!s->budget--) { s->failed_pc=0x0c088b88u; return 0; }
vf3_matrix_load(s,ram,13,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c088b8a;
P_0c088b8a: /* original 6303, guest PC 0x0c088b8a */
if(!s->budget--) { s->failed_pc=0x0c088b8au; return 0; }
r[3]=r[0];
goto P_0c088b8c;
P_0c088b8c: /* original 85f2, guest PC 0x0c088b8c */
if(!s->budget--) { s->failed_pc=0x0c088b8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088b8e;
P_0c088b8e: /* original f4d9, guest PC 0x0c088b8e */
if(!s->budget--) { s->failed_pc=0x0c088b8eu; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c088b90;
P_0c088b90: /* original 600d, guest PC 0x0c088b90 */
if(!s->budget--) { s->failed_pc=0x0c088b90u; return 0; }
r[0]=r[0]&65535u;
goto P_0c088b92;
P_0c088b92: /* original 2308, guest PC 0x0c088b92 */
if(!s->budget--) { s->failed_pc=0x0c088b92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[0])==0)!=0);
goto P_0c088b94;
P_0c088b94: /* original ff4c, guest PC 0x0c088b94 */
if(!s->budget--) { s->failed_pc=0x0c088b94u; return 0; }
vf3_matrix_move(s,15,4);
goto P_0c088b96;
P_0c088b96: /* original 8d02, guest PC 0x0c088b96 */
if(!s->budget--) { s->failed_pc=0x0c088b96u; return 0; }
cond=r[17]&1u;
fr[15]^=0x80000000u;
if(cond) { goto P_0c088b9e; }
goto P_0c088b9a;
P_0c088b98: /* original ff4d, guest PC 0x0c088b98 */
if(!s->budget--) { s->failed_pc=0x0c088b98u; return 0; }
fr[15]^=0x80000000u;
goto P_0c088b9a;
P_0c088b9a: /* original a002, guest PC 0x0c088b9a */
if(!s->budget--) { s->failed_pc=0x0c088b9au; return 0; }
r[14]=0x00000010u;
goto P_0c088ba2;
P_0c088b9c: /* original ee10, guest PC 0x0c088b9c */
if(!s->budget--) { s->failed_pc=0x0c088b9cu; return 0; }
r[14]=0x00000010u;
goto P_0c088b9e;
P_0c088b9e: /* original 5ef2, guest PC 0x0c088b9e */
if(!s->budget--) { s->failed_pc=0x0c088b9eu; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c088ba0;
P_0c088ba0: /* original 6ee1, guest PC 0x0c088ba0 */
if(!s->budget--) { s->failed_pc=0x0c088ba0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]=tmp;
goto P_0c088ba2;
P_0c088ba2: /* original 69f2, guest PC 0x0c088ba2 */
if(!s->budget--) { s->failed_pc=0x0c088ba2u; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c088ba4;
P_0c088ba4: /* original 60ef, guest PC 0x0c088ba4 */
if(!s->budget--) { s->failed_pc=0x0c088ba4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c088ba6;
P_0c088ba6: /* original 8810, guest PC 0x0c088ba6 */
if(!s->budget--) { s->failed_pc=0x0c088ba6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c088ba8;
P_0c088ba8: /* original 7902, guest PC 0x0c088ba8 */
if(!s->budget--) { s->failed_pc=0x0c088ba8u; return 0; }
r[9]+=0x00000002u;
goto P_0c088baa;
P_0c088baa: /* original 2f92, guest PC 0x0c088baa */
if(!s->budget--) { s->failed_pc=0x0c088baau; return 0; }
write(ram,r[15],r[9],4);
goto P_0c088bac;
P_0c088bac: /* original 79fe, guest PC 0x0c088bac */
if(!s->budget--) { s->failed_pc=0x0c088bacu; return 0; }
r[9]+=0xfffffffeu;
goto P_0c088bae;
P_0c088bae: /* original 64f2, guest PC 0x0c088bae */
if(!s->budget--) { s->failed_pc=0x0c088baeu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c088bb0;
P_0c088bb0: /* original 6991, guest PC 0x0c088bb0 */
if(!s->budget--) { s->failed_pc=0x0c088bb0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[9]=tmp;
goto P_0c088bb2;
P_0c088bb2: /* original 7402, guest PC 0x0c088bb2 */
if(!s->budget--) { s->failed_pc=0x0c088bb2u; return 0; }
r[4]+=0x00000002u;
goto P_0c088bb4;
P_0c088bb4: /* original 2f42, guest PC 0x0c088bb4 */
if(!s->budget--) { s->failed_pc=0x0c088bb4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c088bb6;
P_0c088bb6: /* original 74fe, guest PC 0x0c088bb6 */
if(!s->budget--) { s->failed_pc=0x0c088bb6u; return 0; }
r[4]+=0xfffffffeu;
goto P_0c088bb8;
P_0c088bb8: /* original 8f01, guest PC 0x0c088bb8 */
if(!s->budget--) { s->failed_pc=0x0c088bb8u; return 0; }
cond=r[17]&1u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
if(!cond) { goto P_0c088bbe; }
goto P_0c088bbc;
P_0c088bba: /* original 6441, guest PC 0x0c088bba */
if(!s->budget--) { s->failed_pc=0x0c088bbau; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c088bbc;
P_0c088bbc: /* original 6943, guest PC 0x0c088bbc */
if(!s->budget--) { s->failed_pc=0x0c088bbcu; return 0; }
r[9]=r[4];
goto P_0c088bbe;
P_0c088bbe: /* original 4a0b, guest PC 0x0c088bbe */
if(!s->budget--) { s->failed_pc=0x0c088bbeu; return 0; }
target=r[10];
r[16]=code_base|0x0c088bc2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088bc2u) { target=s->pc; goto dispatch; }
goto P_0c088bc2;
P_0c088bc0: /* original 0009, guest PC 0x0c088bc0 */
if(!s->budget--) { s->failed_pc=0x0c088bc0u; return 0; }
goto P_0c088bc2;
P_0c088bc2: /* original f5dc, guest PC 0x0c088bc2 */
if(!s->budget--) { s->failed_pc=0x0c088bc2u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088bc4;
P_0c088bc4: /* original f6fc, guest PC 0x0c088bc4 */
if(!s->budget--) { s->failed_pc=0x0c088bc4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c088bc6;
P_0c088bc6: /* original 4b0b, guest PC 0x0c088bc6 */
if(!s->budget--) { s->failed_pc=0x0c088bc6u; return 0; }
target=r[11];
r[16]=code_base|0x0c088bcau;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088bcau) { target=s->pc; goto dispatch; }
goto P_0c088bca;
P_0c088bc8: /* original f4ec, guest PC 0x0c088bc8 */
if(!s->budget--) { s->failed_pc=0x0c088bc8u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088bca;
P_0c088bca: /* original 4c0b, guest PC 0x0c088bca */
if(!s->budget--) { s->failed_pc=0x0c088bcau; return 0; }
target=r[12];
r[16]=code_base|0x0c088bceu;
r[4]=(uint32_t)(int32_t)(int16_t)r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088bceu) { target=s->pc; goto dispatch; }
goto P_0c088bce;
P_0c088bcc: /* original 649f, guest PC 0x0c088bcc */
if(!s->budget--) { s->failed_pc=0x0c088bccu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[9];
goto P_0c088bce;
P_0c088bce: /* original 50f4, guest PC 0x0c088bce */
if(!s->budget--) { s->failed_pc=0x0c088bceu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c088bd0;
P_0c088bd0: /* original 6eef, guest PC 0x0c088bd0 */
if(!s->budget--) { s->failed_pc=0x0c088bd0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c088bd2;
P_0c088bd2: /* original 4e00, guest PC 0x0c088bd2 */
if(!s->budget--) { s->failed_pc=0x0c088bd2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c088bd4;
P_0c088bd4: /* original 4a0b, guest PC 0x0c088bd4 */
if(!s->budget--) { s->failed_pc=0x0c088bd4u; return 0; }
target=r[10];
r[16]=code_base|0x0c088bd8u;
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088bd8u) { target=s->pc; goto dispatch; }
goto P_0c088bd8;
P_0c088bd6: /* original 0eed, guest PC 0x0c088bd6 */
if(!s->budget--) { s->failed_pc=0x0c088bd6u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c088bd8;
P_0c088bd8: /* original f5dc, guest PC 0x0c088bd8 */
if(!s->budget--) { s->failed_pc=0x0c088bd8u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c088bda;
P_0c088bda: /* original f6fc, guest PC 0x0c088bda */
if(!s->budget--) { s->failed_pc=0x0c088bdau; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c088bdc;
P_0c088bdc: /* original 4b0b, guest PC 0x0c088bdc */
if(!s->budget--) { s->failed_pc=0x0c088bdcu; return 0; }
target=r[11];
r[16]=code_base|0x0c088be0u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088be0u) { target=s->pc; goto dispatch; }
goto P_0c088be0;
P_0c088bde: /* original f4ec, guest PC 0x0c088bde */
if(!s->budget--) { s->failed_pc=0x0c088bdeu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c088be0;
P_0c088be0: /* original 4c0b, guest PC 0x0c088be0 */
if(!s->budget--) { s->failed_pc=0x0c088be0u; return 0; }
target=r[12];
r[16]=code_base|0x0c088be4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088be4u) { target=s->pc; goto dispatch; }
goto P_0c088be4;
P_0c088be2: /* original 64ef, guest PC 0x0c088be2 */
if(!s->budget--) { s->failed_pc=0x0c088be2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c088be4;
P_0c088be4: /* original 85f2, guest PC 0x0c088be4 */
if(!s->budget--) { s->failed_pc=0x0c088be4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c088be6;
P_0c088be6: /* original 4000, guest PC 0x0c088be6 */
if(!s->budget--) { s->failed_pc=0x0c088be6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c088be8;
P_0c088be8: /* original 4810, guest PC 0x0c088be8 */
if(!s->budget--) { s->failed_pc=0x0c088be8u; return 0; }
--r[8];
r[17]=(r[17]&~1u)|((r[8]==0)!=0);
goto P_0c088bea;
P_0c088bea: /* original 81f2, guest PC 0x0c088bea */
if(!s->budget--) { s->failed_pc=0x0c088beau; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c088bec;
P_0c088bec: /* original 53f2, guest PC 0x0c088bec */
if(!s->budget--) { s->failed_pc=0x0c088becu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c088bee;
P_0c088bee: /* original 7304, guest PC 0x0c088bee */
if(!s->budget--) { s->failed_pc=0x0c088beeu; return 0; }
r[3]+=0x00000004u;
goto P_0c088bf0;
P_0c088bf0: /* original 8fc7, guest PC 0x0c088bf0 */
if(!s->budget--) { s->failed_pc=0x0c088bf0u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c088b82; }
goto P_0c088bf4;
P_0c088bf2: /* original 1f32, guest PC 0x0c088bf2 */
if(!s->budget--) { s->failed_pc=0x0c088bf2u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c088bf4;
P_0c088bf4: /* original 7f14, guest PC 0x0c088bf4 */
if(!s->budget--) { s->failed_pc=0x0c088bf4u; return 0; }
r[15]+=0x00000014u;
goto P_0c088bf6;
P_0c088bf6: /* original d30e, guest PC 0x0c088bf6 */
if(!s->budget--) { s->failed_pc=0x0c088bf6u; return 0; }
r[3]=read(ram,0x0c088c30u,4);
goto P_0c088bf8;
P_0c088bf8: /* original 4f26, guest PC 0x0c088bf8 */
if(!s->budget--) { s->failed_pc=0x0c088bf8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088bfa;
P_0c088bfa: /* original e401, guest PC 0x0c088bfa */
if(!s->budget--) { s->failed_pc=0x0c088bfau; return 0; }
r[4]=0x00000001u;
goto P_0c088bfc;
P_0c088bfc: /* original fdf9, guest PC 0x0c088bfc */
if(!s->budget--) { s->failed_pc=0x0c088bfcu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088bfe;
P_0c088bfe: /* original fef9, guest PC 0x0c088bfe */
if(!s->budget--) { s->failed_pc=0x0c088bfeu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088c00;
P_0c088c00: /* original fff9, guest PC 0x0c088c00 */
if(!s->budget--) { s->failed_pc=0x0c088c00u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c088c02;
P_0c088c02: /* original 68f6, guest PC 0x0c088c02 */
if(!s->budget--) { s->failed_pc=0x0c088c02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088c04;
P_0c088c04: /* original 69f6, guest PC 0x0c088c04 */
if(!s->budget--) { s->failed_pc=0x0c088c04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c088c06;
P_0c088c06: /* original 6af6, guest PC 0x0c088c06 */
if(!s->budget--) { s->failed_pc=0x0c088c06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c088c08;
P_0c088c08: /* original 6bf6, guest PC 0x0c088c08 */
if(!s->budget--) { s->failed_pc=0x0c088c08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088c0a;
P_0c088c0a: /* original 6cf6, guest PC 0x0c088c0a */
if(!s->budget--) { s->failed_pc=0x0c088c0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088c0c;
P_0c088c0c: /* original 6df6, guest PC 0x0c088c0c */
if(!s->budget--) { s->failed_pc=0x0c088c0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088c0e;
P_0c088c0e: /* original 432b, guest PC 0x0c088c0e */
if(!s->budget--) { s->failed_pc=0x0c088c0eu; return 0; }
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
P_0c088c10: /* original 6ef6, guest PC 0x0c088c10 */
if(!s->budget--) { s->failed_pc=0x0c088c10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c088c12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c088c12u; return 0; } return 1;
P_0c088c34: /* original 2fe6, guest PC 0x0c088c34 */
if(!s->budget--) { s->failed_pc=0x0c088c34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c36;
P_0c088c36: /* original e000, guest PC 0x0c088c36 */
if(!s->budget--) { s->failed_pc=0x0c088c36u; return 0; }
r[0]=0x00000000u;
goto P_0c088c38;
P_0c088c38: /* original 2fd6, guest PC 0x0c088c38 */
if(!s->budget--) { s->failed_pc=0x0c088c38u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c3a;
P_0c088c3a: /* original ee02, guest PC 0x0c088c3a */
if(!s->budget--) { s->failed_pc=0x0c088c3au; return 0; }
r[14]=0x00000002u;
goto P_0c088c3c;
P_0c088c3c: /* original 2fc6, guest PC 0x0c088c3c */
if(!s->budget--) { s->failed_pc=0x0c088c3cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c3e;
P_0c088c3e: /* original 2fb6, guest PC 0x0c088c3e */
if(!s->budget--) { s->failed_pc=0x0c088c3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c40;
P_0c088c40: /* original 6b43, guest PC 0x0c088c40 */
if(!s->budget--) { s->failed_pc=0x0c088c40u; return 0; }
r[11]=r[4];
goto P_0c088c42;
P_0c088c42: /* original 2f86, guest PC 0x0c088c42 */
if(!s->budget--) { s->failed_pc=0x0c088c42u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c088c44;
P_0c088c44: /* original 7410, guest PC 0x0c088c44 */
if(!s->budget--) { s->failed_pc=0x0c088c44u; return 0; }
r[4]+=0x00000010u;
goto P_0c088c46;
P_0c088c46: /* original 80b2, guest PC 0x0c088c46 */
if(!s->budget--) { s->failed_pc=0x0c088c46u; return 0; }
write(ram,r[11]+2,r[0],1);
goto P_0c088c48;
P_0c088c48: /* original 80b3, guest PC 0x0c088c48 */
if(!s->budget--) { s->failed_pc=0x0c088c48u; return 0; }
write(ram,r[11]+3,r[0],1);
goto P_0c088c4a;
P_0c088c4a: /* original c755, guest PC 0x0c088c4a */
if(!s->budget--) { s->failed_pc=0x0c088c4au; return 0; }
r[0]=code_base|0x00088da0u;
goto P_0c088c4c;
P_0c088c4c: /* original 4f22, guest PC 0x0c088c4c */
if(!s->budget--) { s->failed_pc=0x0c088c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c088c4e;
P_0c088c4e: /* original f408, guest PC 0x0c088c4e */
if(!s->budget--) { s->failed_pc=0x0c088c4eu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c088c50;
P_0c088c50: /* original d054, guest PC 0x0c088c50 */
if(!s->budget--) { s->failed_pc=0x0c088c50u; return 0; }
r[0]=read(ram,0x0c088da4u,4);
goto P_0c088c52;
P_0c088c52: /* original 68e3, guest PC 0x0c088c52 */
if(!s->budget--) { s->failed_pc=0x0c088c52u; return 0; }
r[8]=r[14];
goto P_0c088c54;
P_0c088c54: /* original 4808, guest PC 0x0c088c54 */
if(!s->budget--) { s->failed_pc=0x0c088c54u; return 0; }
r[8]<<=2;
goto P_0c088c56;
P_0c088c56: /* original 62e3, guest PC 0x0c088c56 */
if(!s->budget--) { s->failed_pc=0x0c088c56u; return 0; }
r[2]=r[14];
goto P_0c088c58;
P_0c088c58: /* original 07ec, guest PC 0x0c088c58 */
if(!s->budget--) { s->failed_pc=0x0c088c58u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c088c5a;
P_0c088c5a: /* original 6c73, guest PC 0x0c088c5a */
if(!s->budget--) { s->failed_pc=0x0c088c5au; return 0; }
r[12]=r[7];
goto P_0c088c5c;
P_0c088c5c: /* original 6d73, guest PC 0x0c088c5c */
if(!s->budget--) { s->failed_pc=0x0c088c5cu; return 0; }
r[13]=r[7];
goto P_0c088c5e;
P_0c088c5e: /* original 4c08, guest PC 0x0c088c5e */
if(!s->budget--) { s->failed_pc=0x0c088c5eu; return 0; }
r[12]<<=2;
goto P_0c088c60;
P_0c088c60: /* original 4d00, guest PC 0x0c088c60 */
if(!s->budget--) { s->failed_pc=0x0c088c60u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c088c62;
P_0c088c62: /* original 4c00, guest PC 0x0c088c62 */
if(!s->budget--) { s->failed_pc=0x0c088c62u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c088c64;
P_0c088c64: /* original 4800, guest PC 0x0c088c64 */
if(!s->budget--) { s->failed_pc=0x0c088c64u; return 0; }
r[17]=(r[17]&~1u)|((r[8]>>31)!=0);
r[8]<<=1;
goto P_0c088c66;
P_0c088c66: /* original 4200, guest PC 0x0c088c66 */
if(!s->budget--) { s->failed_pc=0x0c088c66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c088c68;
P_0c088c68: /* original 4711, guest PC 0x0c088c68 */
if(!s->budget--) { s->failed_pc=0x0c088c68u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c088c6a;
P_0c088c6a: /* original 8b37, guest PC 0x0c088c6a */
if(!s->budget--) { s->failed_pc=0x0c088c6au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c088cdc; }
goto P_0c088c6c;
P_0c088c6c: /* original 66c3, guest PC 0x0c088c6c */
if(!s->budget--) { s->failed_pc=0x0c088c6cu; return 0; }
r[6]=r[12];
goto P_0c088c6e;
P_0c088c6e: /* original 36dc, guest PC 0x0c088c6e */
if(!s->budget--) { s->failed_pc=0x0c088c6eu; return 0; }
r[6]+=r[13];
goto P_0c088c70;
P_0c088c70: /* original 4600, guest PC 0x0c088c70 */
if(!s->budget--) { s->failed_pc=0x0c088c70u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c088c72;
P_0c088c72: /* original 6583, guest PC 0x0c088c72 */
if(!s->budget--) { s->failed_pc=0x0c088c72u; return 0; }
r[5]=r[8];
goto P_0c088c74;
P_0c088c74: /* original 6163, guest PC 0x0c088c74 */
if(!s->budget--) { s->failed_pc=0x0c088c74u; return 0; }
r[1]=r[6];
goto P_0c088c76;
P_0c088c76: /* original 760a, guest PC 0x0c088c76 */
if(!s->budget--) { s->failed_pc=0x0c088c76u; return 0; }
r[6]+=0x0000000au;
goto P_0c088c78;
P_0c088c78: /* original 465a, guest PC 0x0c088c78 */
if(!s->budget--) { s->failed_pc=0x0c088c78u; return 0; }
r[53]=r[6];
goto P_0c088c7a;
P_0c088c7a: /* original 352c, guest PC 0x0c088c7a */
if(!s->budget--) { s->failed_pc=0x0c088c7au; return 0; }
r[5]+=r[2];
goto P_0c088c7c;
P_0c088c7c: /* original 4500, guest PC 0x0c088c7c */
if(!s->budget--) { s->failed_pc=0x0c088c7cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c088c7e;
P_0c088c7e: /* original 215b, guest PC 0x0c088c7e */
if(!s->budget--) { s->failed_pc=0x0c088c7eu; return 0; }
r[1]|=r[5];
goto P_0c088c80;
P_0c088c80: /* original f32d, guest PC 0x0c088c80 */
if(!s->budget--) { s->failed_pc=0x0c088c80u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c088c82;
P_0c088c82: /* original 750a, guest PC 0x0c088c82 */
if(!s->budget--) { s->failed_pc=0x0c088c82u; return 0; }
r[5]+=0x0000000au;
goto P_0c088c84;
P_0c088c84: /* original 455a, guest PC 0x0c088c84 */
if(!s->budget--) { s->failed_pc=0x0c088c84u; return 0; }
r[53]=r[5];
goto P_0c088c86;
P_0c088c86: /* original e004, guest PC 0x0c088c86 */
if(!s->budget--) { s->failed_pc=0x0c088c86u; return 0; }
r[0]=0x00000004u;
goto P_0c088c88;
P_0c088c88: /* original 9586, guest PC 0x0c088c88 */
if(!s->budget--) { s->failed_pc=0x0c088c88u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c088d98u,2);
goto P_0c088c8a;
P_0c088c8a: /* original f22d, guest PC 0x0c088c8a */
if(!s->budget--) { s->failed_pc=0x0c088c8au; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c088c8c;
P_0c088c8c: /* original f53c, guest PC 0x0c088c8c */
if(!s->budget--) { s->failed_pc=0x0c088c8cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c088c8e;
P_0c088c8e: /* original f341, guest PC 0x0c088c8e */
if(!s->budget--) { s->failed_pc=0x0c088c8eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c088c90;
P_0c088c90: /* original f72c, guest PC 0x0c088c90 */
if(!s->budget--) { s->failed_pc=0x0c088c90u; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c088c92;
P_0c088c92: /* original f43a, guest PC 0x0c088c92 */
if(!s->budget--) { s->failed_pc=0x0c088c92u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c088c94;
P_0c088c94: /* original f97c, guest PC 0x0c088c94 */
if(!s->budget--) { s->failed_pc=0x0c088c94u; return 0; }
vf3_matrix_move(s,9,7);
goto P_0c088c96;
P_0c088c96: /* original f940, guest PC 0x0c088c96 */
if(!s->budget--) { s->failed_pc=0x0c088c96u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[4],r[18],'+');
goto P_0c088c98;
P_0c088c98: /* original f497, guest PC 0x0c088c98 */
if(!s->budget--) { s->failed_pc=0x0c088c98u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c088c9a;
P_0c088c9a: /* original 1452, guest PC 0x0c088c9a */
if(!s->budget--) { s->failed_pc=0x0c088c9au; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088c9c;
P_0c088c9c: /* original 740c, guest PC 0x0c088c9c */
if(!s->budget--) { s->failed_pc=0x0c088c9cu; return 0; }
r[4]+=0x0000000cu;
goto P_0c088c9e;
P_0c088c9e: /* original f65c, guest PC 0x0c088c9e */
if(!s->budget--) { s->failed_pc=0x0c088c9eu; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c088ca0;
P_0c088ca0: /* original f64d, guest PC 0x0c088ca0 */
if(!s->budget--) { s->failed_pc=0x0c088ca0u; return 0; }
fr[6]^=0x80000000u;
goto P_0c088ca2;
P_0c088ca2: /* original f36c, guest PC 0x0c088ca2 */
if(!s->budget--) { s->failed_pc=0x0c088ca2u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c088ca4;
P_0c088ca4: /* original f341, guest PC 0x0c088ca4 */
if(!s->budget--) { s->failed_pc=0x0c088ca4u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'-');
goto P_0c088ca6;
P_0c088ca6: /* original f43a, guest PC 0x0c088ca6 */
if(!s->budget--) { s->failed_pc=0x0c088ca6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c088ca8;
P_0c088ca8: /* original f497, guest PC 0x0c088ca8 */
if(!s->budget--) { s->failed_pc=0x0c088ca8u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c088caa;
P_0c088caa: /* original 1452, guest PC 0x0c088caa */
if(!s->budget--) { s->failed_pc=0x0c088caau; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088cac;
P_0c088cac: /* original 2118, guest PC 0x0c088cac */
if(!s->budget--) { s->failed_pc=0x0c088cacu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c088cae;
P_0c088cae: /* original 8d09, guest PC 0x0c088cae */
if(!s->budget--) { s->failed_pc=0x0c088caeu; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(cond) { goto P_0c088cc4; }
goto P_0c088cb2;
P_0c088cb0: /* original 740c, guest PC 0x0c088cb0 */
if(!s->budget--) { s->failed_pc=0x0c088cb0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c088cb2;
P_0c088cb2: /* original f87c, guest PC 0x0c088cb2 */
if(!s->budget--) { s->failed_pc=0x0c088cb2u; return 0; }
vf3_matrix_move(s,8,7);
goto P_0c088cb4;
P_0c088cb4: /* original f541, guest PC 0x0c088cb4 */
if(!s->budget--) { s->failed_pc=0x0c088cb4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c088cb6;
P_0c088cb6: /* original f84d, guest PC 0x0c088cb6 */
if(!s->budget--) { s->failed_pc=0x0c088cb6u; return 0; }
fr[8]^=0x80000000u;
goto P_0c088cb8;
P_0c088cb8: /* original f45a, guest PC 0x0c088cb8 */
if(!s->budget--) { s->failed_pc=0x0c088cb8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c088cba;
P_0c088cba: /* original f38c, guest PC 0x0c088cba */
if(!s->budget--) { s->failed_pc=0x0c088cbau; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c088cbc;
P_0c088cbc: /* original f340, guest PC 0x0c088cbc */
if(!s->budget--) { s->failed_pc=0x0c088cbcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c088cbe;
P_0c088cbe: /* original f437, guest PC 0x0c088cbe */
if(!s->budget--) { s->failed_pc=0x0c088cbeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088cc0;
P_0c088cc0: /* original 1452, guest PC 0x0c088cc0 */
if(!s->budget--) { s->failed_pc=0x0c088cc0u; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088cc2;
P_0c088cc2: /* original 740c, guest PC 0x0c088cc2 */
if(!s->budget--) { s->failed_pc=0x0c088cc2u; return 0; }
r[4]+=0x0000000cu;
goto P_0c088cc4;
P_0c088cc4: /* original f641, guest PC 0x0c088cc4 */
if(!s->budget--) { s->failed_pc=0x0c088cc4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'-');
goto P_0c088cc6;
P_0c088cc6: /* original 77ff, guest PC 0x0c088cc6 */
if(!s->budget--) { s->failed_pc=0x0c088cc6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c088cc8;
P_0c088cc8: /* original 4711, guest PC 0x0c088cc8 */
if(!s->budget--) { s->failed_pc=0x0c088cc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c088cca;
P_0c088cca: /* original 7dfe, guest PC 0x0c088cca */
if(!s->budget--) { s->failed_pc=0x0c088ccau; return 0; }
r[13]+=0xfffffffeu;
goto P_0c088ccc;
P_0c088ccc: /* original f46a, guest PC 0x0c088ccc */
if(!s->budget--) { s->failed_pc=0x0c088cccu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c088cce;
P_0c088cce: /* original f38c, guest PC 0x0c088cce */
if(!s->budget--) { s->failed_pc=0x0c088cceu; return 0; }
vf3_matrix_move(s,3,8);
goto P_0c088cd0;
P_0c088cd0: /* original f340, guest PC 0x0c088cd0 */
if(!s->budget--) { s->failed_pc=0x0c088cd0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c088cd2;
P_0c088cd2: /* original f437, guest PC 0x0c088cd2 */
if(!s->budget--) { s->failed_pc=0x0c088cd2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c088cd4;
P_0c088cd4: /* original 1452, guest PC 0x0c088cd4 */
if(!s->budget--) { s->failed_pc=0x0c088cd4u; return 0; }
write(ram,r[4]+8,r[5],4);
goto P_0c088cd6;
P_0c088cd6: /* original 740c, guest PC 0x0c088cd6 */
if(!s->budget--) { s->failed_pc=0x0c088cd6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c088cd8;
P_0c088cd8: /* original 8dc8, guest PC 0x0c088cd8 */
if(!s->budget--) { s->failed_pc=0x0c088cd8u; return 0; }
cond=r[17]&1u;
r[12]+=0xfffffff8u;
if(cond) { goto P_0c088c6c; }
goto P_0c088cdc;
P_0c088cda: /* original 7cf8, guest PC 0x0c088cda */
if(!s->budget--) { s->failed_pc=0x0c088cdau; return 0; }
r[12]+=0xfffffff8u;
goto P_0c088cdc;
P_0c088cdc: /* original 7eff, guest PC 0x0c088cdc */
if(!s->budget--) { s->failed_pc=0x0c088cdcu; return 0; }
r[14]+=0xffffffffu;
goto P_0c088cde;
P_0c088cde: /* original 4e11, guest PC 0x0c088cde */
if(!s->budget--) { s->failed_pc=0x0c088cdeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c088ce0;
P_0c088ce0: /* original 89b6, guest PC 0x0c088ce0 */
if(!s->budget--) { s->failed_pc=0x0c088ce0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c088c50; }
goto P_0c088ce2;
P_0c088ce2: /* original d331, guest PC 0x0c088ce2 */
if(!s->budget--) { s->failed_pc=0x0c088ce2u; return 0; }
r[3]=read(ram,0x0c088da8u,4);
goto P_0c088ce4;
P_0c088ce4: /* original 430b, guest PC 0x0c088ce4 */
if(!s->budget--) { s->failed_pc=0x0c088ce4u; return 0; }
target=r[3];
r[16]=code_base|0x0c088ce8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c088ce8u) { target=s->pc; goto dispatch; }
goto P_0c088ce8;
P_0c088ce6: /* original 0009, guest PC 0x0c088ce6 */
if(!s->budget--) { s->failed_pc=0x0c088ce6u; return 0; }
goto P_0c088ce8;
P_0c088ce8: /* original 640d, guest PC 0x0c088ce8 */
if(!s->budget--) { s->failed_pc=0x0c088ce8u; return 0; }
r[4]=r[0]&65535u;
goto P_0c088cea;
P_0c088cea: /* original e000, guest PC 0x0c088cea */
if(!s->budget--) { s->failed_pc=0x0c088ceau; return 0; }
r[0]=0x00000000u;
goto P_0c088cec;
P_0c088cec: /* original 4f26, guest PC 0x0c088cec */
if(!s->budget--) { s->failed_pc=0x0c088cecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c088cee;
P_0c088cee: /* original 81b2, guest PC 0x0c088cee */
if(!s->budget--) { s->failed_pc=0x0c088ceeu; return 0; }
write(ram,r[11]+4,r[0],2);
goto P_0c088cf0;
P_0c088cf0: /* original 6043, guest PC 0x0c088cf0 */
if(!s->budget--) { s->failed_pc=0x0c088cf0u; return 0; }
r[0]=r[4];
goto P_0c088cf2;
P_0c088cf2: /* original 654c, guest PC 0x0c088cf2 */
if(!s->budget--) { s->failed_pc=0x0c088cf2u; return 0; }
r[5]=r[4]&255u;
goto P_0c088cf4;
P_0c088cf4: /* original 81b3, guest PC 0x0c088cf4 */
if(!s->budget--) { s->failed_pc=0x0c088cf4u; return 0; }
write(ram,r[11]+6,r[0],2);
goto P_0c088cf6;
P_0c088cf6: /* original 6053, guest PC 0x0c088cf6 */
if(!s->budget--) { s->failed_pc=0x0c088cf6u; return 0; }
r[0]=r[5];
goto P_0c088cf8;
P_0c088cf8: /* original 81b4, guest PC 0x0c088cf8 */
if(!s->budget--) { s->failed_pc=0x0c088cf8u; return 0; }
write(ram,r[11]+8,r[0],2);
goto P_0c088cfa;
P_0c088cfa: /* original 68f6, guest PC 0x0c088cfa */
if(!s->budget--) { s->failed_pc=0x0c088cfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c088cfc;
P_0c088cfc: /* original 6bf6, guest PC 0x0c088cfc */
if(!s->budget--) { s->failed_pc=0x0c088cfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c088cfe;
P_0c088cfe: /* original 6cf6, guest PC 0x0c088cfe */
if(!s->budget--) { s->failed_pc=0x0c088cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c088d00;
P_0c088d00: /* original 6df6, guest PC 0x0c088d00 */
if(!s->budget--) { s->failed_pc=0x0c088d00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c088d02;
P_0c088d02: /* original 000b, guest PC 0x0c088d02 */
if(!s->budget--) { s->failed_pc=0x0c088d02u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c088d04: /* original 6ef6, guest PC 0x0c088d04 */
if(!s->budget--) { s->failed_pc=0x0c088d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c088d06u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
