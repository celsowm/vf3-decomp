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
int vf3_away_batch14_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c086b20u: goto P_0c086b20;
case 0x0c086b22u: goto P_0c086b22;
case 0x0c086b24u: goto P_0c086b24;
case 0x0c086b26u: goto P_0c086b26;
case 0x0c086b28u: goto P_0c086b28;
case 0x0c086b2au: goto P_0c086b2a;
case 0x0c086b2cu: goto P_0c086b2c;
case 0x0c086b2eu: goto P_0c086b2e;
case 0x0c086b30u: goto P_0c086b30;
case 0x0c086b32u: goto P_0c086b32;
case 0x0c086b34u: goto P_0c086b34;
case 0x0c086b36u: goto P_0c086b36;
case 0x0c086b38u: goto P_0c086b38;
case 0x0c086b3au: goto P_0c086b3a;
case 0x0c086b3cu: goto P_0c086b3c;
case 0x0c086b3eu: goto P_0c086b3e;
case 0x0c086b40u: goto P_0c086b40;
case 0x0c086b42u: goto P_0c086b42;
case 0x0c086b44u: goto P_0c086b44;
case 0x0c086b46u: goto P_0c086b46;
case 0x0c086b48u: goto P_0c086b48;
case 0x0c086b4au: goto P_0c086b4a;
case 0x0c086b4cu: goto P_0c086b4c;
case 0x0c086b4eu: goto P_0c086b4e;
case 0x0c086b50u: goto P_0c086b50;
case 0x0c086b52u: goto P_0c086b52;
case 0x0c086b54u: goto P_0c086b54;
case 0x0c086b56u: goto P_0c086b56;
case 0x0c086b58u: goto P_0c086b58;
case 0x0c086b5au: goto P_0c086b5a;
case 0x0c086b5cu: goto P_0c086b5c;
case 0x0c086b5eu: goto P_0c086b5e;
case 0x0c086b60u: goto P_0c086b60;
case 0x0c086b62u: goto P_0c086b62;
case 0x0c086b64u: goto P_0c086b64;
case 0x0c086b66u: goto P_0c086b66;
case 0x0c086b68u: goto P_0c086b68;
case 0x0c086b6au: goto P_0c086b6a;
case 0x0c086b6cu: goto P_0c086b6c;
case 0x0c086b6eu: goto P_0c086b6e;
case 0x0c086b70u: goto P_0c086b70;
case 0x0c086b72u: goto P_0c086b72;
case 0x0c086b74u: goto P_0c086b74;
case 0x0c086b76u: goto P_0c086b76;
case 0x0c086b78u: goto P_0c086b78;
case 0x0c086b7au: goto P_0c086b7a;
case 0x0c086b7cu: goto P_0c086b7c;
case 0x0c086b7eu: goto P_0c086b7e;
case 0x0c086b80u: goto P_0c086b80;
case 0x0c086b9cu: goto P_0c086b9c;
case 0x0c086b9eu: goto P_0c086b9e;
case 0x0c086ba0u: goto P_0c086ba0;
case 0x0c086ba2u: goto P_0c086ba2;
case 0x0c086ba4u: goto P_0c086ba4;
case 0x0c086ba6u: goto P_0c086ba6;
case 0x0c086ba8u: goto P_0c086ba8;
case 0x0c086baau: goto P_0c086baa;
case 0x0c086bacu: goto P_0c086bac;
case 0x0c086baeu: goto P_0c086bae;
case 0x0c086bb0u: goto P_0c086bb0;
case 0x0c086bb2u: goto P_0c086bb2;
case 0x0c086bb4u: goto P_0c086bb4;
case 0x0c086bb6u: goto P_0c086bb6;
case 0x0c086bb8u: goto P_0c086bb8;
case 0x0c086bbau: goto P_0c086bba;
case 0x0c086bbcu: goto P_0c086bbc;
case 0x0c086bbeu: goto P_0c086bbe;
case 0x0c086bc0u: goto P_0c086bc0;
case 0x0c086bc2u: goto P_0c086bc2;
case 0x0c086bc4u: goto P_0c086bc4;
case 0x0c086bc6u: goto P_0c086bc6;
case 0x0c086bc8u: goto P_0c086bc8;
case 0x0c086bcau: goto P_0c086bca;
case 0x0c086bccu: goto P_0c086bcc;
case 0x0c086bceu: goto P_0c086bce;
case 0x0c086bd0u: goto P_0c086bd0;
case 0x0c086bd2u: goto P_0c086bd2;
case 0x0c086bd4u: goto P_0c086bd4;
case 0x0c086bd6u: goto P_0c086bd6;
case 0x0c086bd8u: goto P_0c086bd8;
case 0x0c086bdau: goto P_0c086bda;
case 0x0c086bdcu: goto P_0c086bdc;
case 0x0c086bdeu: goto P_0c086bde;
case 0x0c086be0u: goto P_0c086be0;
case 0x0c086be2u: goto P_0c086be2;
case 0x0c086be4u: goto P_0c086be4;
case 0x0c086be6u: goto P_0c086be6;
case 0x0c086be8u: goto P_0c086be8;
case 0x0c086beau: goto P_0c086bea;
case 0x0c086becu: goto P_0c086bec;
case 0x0c086beeu: goto P_0c086bee;
case 0x0c086bf0u: goto P_0c086bf0;
case 0x0c086bf2u: goto P_0c086bf2;
case 0x0c086bf4u: goto P_0c086bf4;
case 0x0c086bf6u: goto P_0c086bf6;
case 0x0c086bf8u: goto P_0c086bf8;
case 0x0c086bfau: goto P_0c086bfa;
case 0x0c086bfcu: goto P_0c086bfc;
case 0x0c086bfeu: goto P_0c086bfe;
case 0x0c086c00u: goto P_0c086c00;
case 0x0c086c02u: goto P_0c086c02;
case 0x0c086c04u: goto P_0c086c04;
case 0x0c086c06u: goto P_0c086c06;
case 0x0c086c08u: goto P_0c086c08;
case 0x0c086c0au: goto P_0c086c0a;
case 0x0c086c0cu: goto P_0c086c0c;
case 0x0c086c0eu: goto P_0c086c0e;
case 0x0c086c10u: goto P_0c086c10;
case 0x0c086c12u: goto P_0c086c12;
case 0x0c086c14u: goto P_0c086c14;
case 0x0c086c16u: goto P_0c086c16;
case 0x0c086c18u: goto P_0c086c18;
case 0x0c086c1au: goto P_0c086c1a;
case 0x0c086c1cu: goto P_0c086c1c;
case 0x0c086c1eu: goto P_0c086c1e;
case 0x0c086c20u: goto P_0c086c20;
case 0x0c086c22u: goto P_0c086c22;
case 0x0c086c24u: goto P_0c086c24;
case 0x0c086c26u: goto P_0c086c26;
case 0x0c086c28u: goto P_0c086c28;
case 0x0c086c2au: goto P_0c086c2a;
case 0x0c086c2cu: goto P_0c086c2c;
case 0x0c086c2eu: goto P_0c086c2e;
case 0x0c086c30u: goto P_0c086c30;
case 0x0c086c32u: goto P_0c086c32;
case 0x0c086c34u: goto P_0c086c34;
case 0x0c086c36u: goto P_0c086c36;
case 0x0c086c38u: goto P_0c086c38;
case 0x0c086c3au: goto P_0c086c3a;
case 0x0c086c3cu: goto P_0c086c3c;
case 0x0c086c3eu: goto P_0c086c3e;
case 0x0c086c40u: goto P_0c086c40;
case 0x0c086c42u: goto P_0c086c42;
case 0x0c086c44u: goto P_0c086c44;
case 0x0c086c46u: goto P_0c086c46;
case 0x0c086c48u: goto P_0c086c48;
case 0x0c086c4au: goto P_0c086c4a;
case 0x0c086c4cu: goto P_0c086c4c;
case 0x0c086c4eu: goto P_0c086c4e;
case 0x0c086c50u: goto P_0c086c50;
case 0x0c086c52u: goto P_0c086c52;
case 0x0c086c54u: goto P_0c086c54;
case 0x0c086c56u: goto P_0c086c56;
case 0x0c086c58u: goto P_0c086c58;
case 0x0c086c5au: goto P_0c086c5a;
case 0x0c086c5cu: goto P_0c086c5c;
case 0x0c086c5eu: goto P_0c086c5e;
case 0x0c086c60u: goto P_0c086c60;
case 0x0c086c62u: goto P_0c086c62;
case 0x0c086c64u: goto P_0c086c64;
case 0x0c086c66u: goto P_0c086c66;
case 0x0c086c68u: goto P_0c086c68;
case 0x0c086c6au: goto P_0c086c6a;
case 0x0c086c6cu: goto P_0c086c6c;
case 0x0c086c6eu: goto P_0c086c6e;
case 0x0c086c70u: goto P_0c086c70;
case 0x0c086c72u: goto P_0c086c72;
case 0x0c086c74u: goto P_0c086c74;
case 0x0c086c76u: goto P_0c086c76;
case 0x0c086c78u: goto P_0c086c78;
case 0x0c086c7au: goto P_0c086c7a;
case 0x0c086c7cu: goto P_0c086c7c;
case 0x0c086c7eu: goto P_0c086c7e;
case 0x0c086c80u: goto P_0c086c80;
case 0x0c086c82u: goto P_0c086c82;
case 0x0c086c84u: goto P_0c086c84;
case 0x0c086c86u: goto P_0c086c86;
case 0x0c086c88u: goto P_0c086c88;
case 0x0c086c8au: goto P_0c086c8a;
case 0x0c086c8cu: goto P_0c086c8c;
case 0x0c086c8eu: goto P_0c086c8e;
case 0x0c086c90u: goto P_0c086c90;
case 0x0c086c92u: goto P_0c086c92;
case 0x0c086c94u: goto P_0c086c94;
case 0x0c086c96u: goto P_0c086c96;
case 0x0c086c98u: goto P_0c086c98;
case 0x0c086c9au: goto P_0c086c9a;
case 0x0c086c9cu: goto P_0c086c9c;
case 0x0c086c9eu: goto P_0c086c9e;
case 0x0c086ca0u: goto P_0c086ca0;
case 0x0c086ca2u: goto P_0c086ca2;
case 0x0c086ca4u: goto P_0c086ca4;
case 0x0c086ca6u: goto P_0c086ca6;
case 0x0c086ca8u: goto P_0c086ca8;
case 0x0c086caau: goto P_0c086caa;
case 0x0c086cacu: goto P_0c086cac;
case 0x0c086caeu: goto P_0c086cae;
case 0x0c086cb0u: goto P_0c086cb0;
case 0x0c086cb2u: goto P_0c086cb2;
case 0x0c086cb4u: goto P_0c086cb4;
case 0x0c086cb6u: goto P_0c086cb6;
case 0x0c086cb8u: goto P_0c086cb8;
case 0x0c086cbau: goto P_0c086cba;
case 0x0c086cbcu: goto P_0c086cbc;
case 0x0c086cbeu: goto P_0c086cbe;
case 0x0c086cc0u: goto P_0c086cc0;
case 0x0c086cc2u: goto P_0c086cc2;
case 0x0c086cc4u: goto P_0c086cc4;
case 0x0c086cc6u: goto P_0c086cc6;
case 0x0c086cc8u: goto P_0c086cc8;
case 0x0c086ccau: goto P_0c086cca;
case 0x0c086cccu: goto P_0c086ccc;
case 0x0c086cceu: goto P_0c086cce;
case 0x0c086cd0u: goto P_0c086cd0;
case 0x0c086cd2u: goto P_0c086cd2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c086b20: /* original 2fe6, guest PC 0x0c086b20 */
if(!s->budget--) { s->failed_pc=0x0c086b20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b22;
P_0c086b22: /* original 2fd6, guest PC 0x0c086b22 */
if(!s->budget--) { s->failed_pc=0x0c086b22u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b24;
P_0c086b24: /* original 6d43, guest PC 0x0c086b24 */
if(!s->budget--) { s->failed_pc=0x0c086b24u; return 0; }
r[13]=r[4];
goto P_0c086b26;
P_0c086b26: /* original 2fc6, guest PC 0x0c086b26 */
if(!s->budget--) { s->failed_pc=0x0c086b26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b28;
P_0c086b28: /* original 2fb6, guest PC 0x0c086b28 */
if(!s->budget--) { s->failed_pc=0x0c086b28u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b2a;
P_0c086b2a: /* original 2fa6, guest PC 0x0c086b2a */
if(!s->budget--) { s->failed_pc=0x0c086b2au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b2c;
P_0c086b2c: /* original 2f96, guest PC 0x0c086b2c */
if(!s->budget--) { s->failed_pc=0x0c086b2cu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b2e;
P_0c086b2e: /* original 2f86, guest PC 0x0c086b2e */
if(!s->budget--) { s->failed_pc=0x0c086b2eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c086b30;
P_0c086b30: /* original fffb, guest PC 0x0c086b30 */
if(!s->budget--) { s->failed_pc=0x0c086b30u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c086b32;
P_0c086b32: /* original ffeb, guest PC 0x0c086b32 */
if(!s->budget--) { s->failed_pc=0x0c086b32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c086b34;
P_0c086b34: /* original ffdb, guest PC 0x0c086b34 */
if(!s->budget--) { s->failed_pc=0x0c086b34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c086b36;
P_0c086b36: /* original ffcb, guest PC 0x0c086b36 */
if(!s->budget--) { s->failed_pc=0x0c086b36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c086b38;
P_0c086b38: /* original d412, guest PC 0x0c086b38 */
if(!s->budget--) { s->failed_pc=0x0c086b38u; return 0; }
r[4]=read(ram,0x0c086b84u,4);
goto P_0c086b3a;
P_0c086b3a: /* original 4f22, guest PC 0x0c086b3a */
if(!s->budget--) { s->failed_pc=0x0c086b3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c086b3c;
P_0c086b3c: /* original 6242, guest PC 0x0c086b3c */
if(!s->budget--) { s->failed_pc=0x0c086b3cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c086b3e;
P_0c086b3e: /* original d312, guest PC 0x0c086b3e */
if(!s->budget--) { s->failed_pc=0x0c086b3eu; return 0; }
r[3]=read(ram,0x0c086b88u,4);
goto P_0c086b40;
P_0c086b40: /* original 7ff8, guest PC 0x0c086b40 */
if(!s->budget--) { s->failed_pc=0x0c086b40u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c086b42;
P_0c086b42: /* original 2238, guest PC 0x0c086b42 */
if(!s->budget--) { s->failed_pc=0x0c086b42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c086b44;
P_0c086b44: /* original 8901, guest PC 0x0c086b44 */
if(!s->budget--) { s->failed_pc=0x0c086b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086b4a; }
goto P_0c086b46;
P_0c086b46: /* original a0b7, guest PC 0x0c086b46 */
if(!s->budget--) { s->failed_pc=0x0c086b46u; return 0; }
goto P_0c086cb8;
P_0c086b48: /* original 0009, guest PC 0x0c086b48 */
if(!s->budget--) { s->failed_pc=0x0c086b48u; return 0; }
goto P_0c086b4a;
P_0c086b4a: /* original 5141, guest PC 0x0c086b4a */
if(!s->budget--) { s->failed_pc=0x0c086b4au; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c086b4c;
P_0c086b4c: /* original d30f, guest PC 0x0c086b4c */
if(!s->budget--) { s->failed_pc=0x0c086b4cu; return 0; }
r[3]=read(ram,0x0c086b8cu,4);
goto P_0c086b4e;
P_0c086b4e: /* original 2138, guest PC 0x0c086b4e */
if(!s->budget--) { s->failed_pc=0x0c086b4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c086b50;
P_0c086b50: /* original 8901, guest PC 0x0c086b50 */
if(!s->budget--) { s->failed_pc=0x0c086b50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c086b56; }
goto P_0c086b52;
P_0c086b52: /* original a0b1, guest PC 0x0c086b52 */
if(!s->budget--) { s->failed_pc=0x0c086b52u; return 0; }
goto P_0c086cb8;
P_0c086b54: /* original 0009, guest PC 0x0c086b54 */
if(!s->budget--) { s->failed_pc=0x0c086b54u; return 0; }
goto P_0c086b56;
P_0c086b56: /* original d00e, guest PC 0x0c086b56 */
if(!s->budget--) { s->failed_pc=0x0c086b56u; return 0; }
r[0]=read(ram,0x0c086b90u,4);
goto P_0c086b58;
P_0c086b58: /* original ec01, guest PC 0x0c086b58 */
if(!s->budget--) { s->failed_pc=0x0c086b58u; return 0; }
r[12]=0x00000001u;
goto P_0c086b5a;
P_0c086b5a: /* original eb0f, guest PC 0x0c086b5a */
if(!s->budget--) { s->failed_pc=0x0c086b5au; return 0; }
r[11]=0x0000000fu;
goto P_0c086b5c;
P_0c086b5c: /* original 6802, guest PC 0x0c086b5c */
if(!s->budget--) { s->failed_pc=0x0c086b5cu; return 0; }
tmp=read(ram,r[0],4);
r[8]=tmp;
goto P_0c086b5e;
P_0c086b5e: /* original e00c, guest PC 0x0c086b5e */
if(!s->budget--) { s->failed_pc=0x0c086b5eu; return 0; }
r[0]=0x0000000cu;
goto P_0c086b60;
P_0c086b60: /* original fdd6, guest PC 0x0c086b60 */
if(!s->budget--) { s->failed_pc=0x0c086b60u; return 0; }
vf3_matrix_load(s,ram,13,r[13]+r[0]);
goto P_0c086b62;
P_0c086b62: /* original e010, guest PC 0x0c086b62 */
if(!s->budget--) { s->failed_pc=0x0c086b62u; return 0; }
r[0]=0x00000010u;
goto P_0c086b64;
P_0c086b64: /* original f3d6, guest PC 0x0c086b64 */
if(!s->budget--) { s->failed_pc=0x0c086b64u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086b66;
P_0c086b66: /* original e014, guest PC 0x0c086b66 */
if(!s->budget--) { s->failed_pc=0x0c086b66u; return 0; }
r[0]=0x00000014u;
goto P_0c086b68;
P_0c086b68: /* original ff3a, guest PC 0x0c086b68 */
if(!s->budget--) { s->failed_pc=0x0c086b68u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c086b6a;
P_0c086b6a: /* original fcd6, guest PC 0x0c086b6a */
if(!s->budget--) { s->failed_pc=0x0c086b6au; return 0; }
vf3_matrix_load(s,ram,12,r[13]+r[0]);
goto P_0c086b6c;
P_0c086b6c: /* original e03c, guest PC 0x0c086b6c */
if(!s->budget--) { s->failed_pc=0x0c086b6cu; return 0; }
r[0]=0x0000003cu;
goto P_0c086b6e;
P_0c086b6e: /* original fed6, guest PC 0x0c086b6e */
if(!s->budget--) { s->failed_pc=0x0c086b6eu; return 0; }
vf3_matrix_load(s,ram,14,r[13]+r[0]);
goto P_0c086b70;
P_0c086b70: /* original e040, guest PC 0x0c086b70 */
if(!s->budget--) { s->failed_pc=0x0c086b70u; return 0; }
r[0]=0x00000040u;
goto P_0c086b72;
P_0c086b72: /* original f3d6, guest PC 0x0c086b72 */
if(!s->budget--) { s->failed_pc=0x0c086b72u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c086b74;
P_0c086b74: /* original e004, guest PC 0x0c086b74 */
if(!s->budget--) { s->failed_pc=0x0c086b74u; return 0; }
r[0]=0x00000004u;
goto P_0c086b76;
P_0c086b76: /* original ff37, guest PC 0x0c086b76 */
if(!s->budget--) { s->failed_pc=0x0c086b76u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c086b78;
P_0c086b78: /* original c706, guest PC 0x0c086b78 */
if(!s->budget--) { s->failed_pc=0x0c086b78u; return 0; }
r[0]=code_base|0x00086b94u;
goto P_0c086b7a;
P_0c086b7a: /* original da07, guest PC 0x0c086b7a */
if(!s->budget--) { s->failed_pc=0x0c086b7au; return 0; }
r[10]=read(ram,0x0c086b98u,4);
goto P_0c086b7c;
P_0c086b7c: /* original ff08, guest PC 0x0c086b7c */
if(!s->budget--) { s->failed_pc=0x0c086b7cu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c086b7e;
P_0c086b7e: /* original a072, guest PC 0x0c086b7e */
if(!s->budget--) { s->failed_pc=0x0c086b7eu; return 0; }
r[9]=0x00000002u;
goto P_0c086c66;
P_0c086b80: /* original e902, guest PC 0x0c086b80 */
if(!s->budget--) { s->failed_pc=0x0c086b80u; return 0; }
r[9]=0x00000002u;
if(!vf3_matrix_family(0x0c086b82u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086b82u; return 0; } return 1;
P_0c086b9c: /* original d24f, guest PC 0x0c086b9c */
if(!s->budget--) { s->failed_pc=0x0c086b9cu; return 0; }
r[2]=read(ram,0x0c086cdcu,4);
goto P_0c086b9e;
P_0c086b9e: /* original 420b, guest PC 0x0c086b9e */
if(!s->budget--) { s->failed_pc=0x0c086b9eu; return 0; }
target=r[2];
r[16]=code_base|0x0c086ba2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086ba2u) { target=s->pc; goto dispatch; }
goto P_0c086ba2;
P_0c086ba0: /* original 64d3, guest PC 0x0c086ba0 */
if(!s->budget--) { s->failed_pc=0x0c086ba0u; return 0; }
r[4]=r[13];
goto P_0c086ba2;
P_0c086ba2: /* original 88ff, guest PC 0x0c086ba2 */
if(!s->budget--) { s->failed_pc=0x0c086ba2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c086ba4;
P_0c086ba4: /* original 8f02, guest PC 0x0c086ba4 */
if(!s->budget--) { s->failed_pc=0x0c086ba4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c086bac; }
goto P_0c086ba8;
P_0c086ba6: /* original 6403, guest PC 0x0c086ba6 */
if(!s->budget--) { s->failed_pc=0x0c086ba6u; return 0; }
r[4]=r[0];
goto P_0c086ba8;
P_0c086ba8: /* original a086, guest PC 0x0c086ba8 */
if(!s->budget--) { s->failed_pc=0x0c086ba8u; return 0; }
goto P_0c086cb8;
P_0c086baa: /* original 0009, guest PC 0x0c086baa */
if(!s->budget--) { s->failed_pc=0x0c086baau; return 0; }
goto P_0c086bac;
P_0c086bac: /* original e00c, guest PC 0x0c086bac */
if(!s->budget--) { s->failed_pc=0x0c086bacu; return 0; }
r[0]=0x0000000cu;
goto P_0c086bae;
P_0c086bae: /* original 6e43, guest PC 0x0c086bae */
if(!s->budget--) { s->failed_pc=0x0c086baeu; return 0; }
r[14]=r[4];
goto P_0c086bb0;
P_0c086bb0: /* original fed7, guest PC 0x0c086bb0 */
if(!s->budget--) { s->failed_pc=0x0c086bb0u; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c086bb2;
P_0c086bb2: /* original e010, guest PC 0x0c086bb2 */
if(!s->budget--) { s->failed_pc=0x0c086bb2u; return 0; }
r[0]=0x00000010u;
goto P_0c086bb4;
P_0c086bb4: /* original f3f8, guest PC 0x0c086bb4 */
if(!s->budget--) { s->failed_pc=0x0c086bb4u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c086bb6;
P_0c086bb6: /* original fe37, guest PC 0x0c086bb6 */
if(!s->budget--) { s->failed_pc=0x0c086bb6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c086bb8;
P_0c086bb8: /* original e014, guest PC 0x0c086bb8 */
if(!s->budget--) { s->failed_pc=0x0c086bb8u; return 0; }
r[0]=0x00000014u;
goto P_0c086bba;
P_0c086bba: /* original 4a0b, guest PC 0x0c086bba */
if(!s->budget--) { s->failed_pc=0x0c086bbau; return 0; }
target=r[10];
r[16]=code_base|0x0c086bbeu;
vf3_matrix_store(s,ram,12,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086bbeu) { target=s->pc; goto dispatch; }
goto P_0c086bbe;
P_0c086bbc: /* original fec7, guest PC 0x0c086bbc */
if(!s->budget--) { s->failed_pc=0x0c086bbcu; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c086bbe;
P_0c086bbe: /* original 6503, guest PC 0x0c086bbe */
if(!s->budget--) { s->failed_pc=0x0c086bbeu; return 0; }
r[5]=r[0];
goto P_0c086bc0;
P_0c086bc0: /* original 25b9, guest PC 0x0c086bc0 */
if(!s->budget--) { s->failed_pc=0x0c086bc0u; return 0; }
r[5]&=r[11];
goto P_0c086bc2;
P_0c086bc2: /* original 455a, guest PC 0x0c086bc2 */
if(!s->budget--) { s->failed_pc=0x0c086bc2u; return 0; }
r[53]=r[5];
goto P_0c086bc4;
P_0c086bc4: /* original e3fb, guest PC 0x0c086bc4 */
if(!s->budget--) { s->failed_pc=0x0c086bc4u; return 0; }
r[3]=0xfffffffbu;
goto P_0c086bc6;
P_0c086bc6: /* original 6403, guest PC 0x0c086bc6 */
if(!s->budget--) { s->failed_pc=0x0c086bc6u; return 0; }
r[4]=r[0];
goto P_0c086bc8;
P_0c086bc8: /* original e61f, guest PC 0x0c086bc8 */
if(!s->budget--) { s->failed_pc=0x0c086bc8u; return 0; }
r[6]=0x0000001fu;
goto P_0c086bca;
P_0c086bca: /* original 403c, guest PC 0x0c086bca */
if(!s->budget--) { s->failed_pc=0x0c086bcau; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[0]>>((-r[3])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[3]&31u);
goto P_0c086bcc;
P_0c086bcc: /* original f7fc, guest PC 0x0c086bcc */
if(!s->budget--) { s->failed_pc=0x0c086bccu; return 0; }
vf3_matrix_move(s,7,15);
goto P_0c086bce;
P_0c086bce: /* original f32d, guest PC 0x0c086bce */
if(!s->budget--) { s->failed_pc=0x0c086bceu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c086bd0;
P_0c086bd0: /* original 2609, guest PC 0x0c086bd0 */
if(!s->budget--) { s->failed_pc=0x0c086bd0u; return 0; }
r[6]&=r[0];
goto P_0c086bd2;
P_0c086bd2: /* original 465a, guest PC 0x0c086bd2 */
if(!s->budget--) { s->failed_pc=0x0c086bd2u; return 0; }
r[53]=r[6];
goto P_0c086bd4;
P_0c086bd4: /* original e3f7, guest PC 0x0c086bd4 */
if(!s->budget--) { s->failed_pc=0x0c086bd4u; return 0; }
r[3]=0xfffffff7u;
goto P_0c086bd6;
P_0c086bd6: /* original 443c, guest PC 0x0c086bd6 */
if(!s->budget--) { s->failed_pc=0x0c086bd6u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c086bd8;
P_0c086bd8: /* original 24b9, guest PC 0x0c086bd8 */
if(!s->budget--) { s->failed_pc=0x0c086bd8u; return 0; }
r[4]&=r[11];
goto P_0c086bda;
P_0c086bda: /* original f22d, guest PC 0x0c086bda */
if(!s->budget--) { s->failed_pc=0x0c086bdau; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c086bdc;
P_0c086bdc: /* original 445a, guest PC 0x0c086bdc */
if(!s->budget--) { s->failed_pc=0x0c086bdcu; return 0; }
r[53]=r[4];
goto P_0c086bde;
P_0c086bde: /* original f53c, guest PC 0x0c086bde */
if(!s->budget--) { s->failed_pc=0x0c086bdeu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c086be0;
P_0c086be0: /* original f572, guest PC 0x0c086be0 */
if(!s->budget--) { s->failed_pc=0x0c086be0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c086be2;
P_0c086be2: /* original 25c8, guest PC 0x0c086be2 */
if(!s->budget--) { s->failed_pc=0x0c086be2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[12])==0)!=0);
goto P_0c086be4;
P_0c086be4: /* original f32d, guest PC 0x0c086be4 */
if(!s->budget--) { s->failed_pc=0x0c086be4u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c086be6;
P_0c086be6: /* original f62c, guest PC 0x0c086be6 */
if(!s->budget--) { s->failed_pc=0x0c086be6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c086be8;
P_0c086be8: /* original f672, guest PC 0x0c086be8 */
if(!s->budget--) { s->failed_pc=0x0c086be8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c086bea;
P_0c086bea: /* original f43c, guest PC 0x0c086bea */
if(!s->budget--) { s->failed_pc=0x0c086beau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c086bec;
P_0c086bec: /* original 8f01, guest PC 0x0c086bec */
if(!s->budget--) { s->failed_pc=0x0c086becu; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
if(!cond) { goto P_0c086bf2; }
goto P_0c086bf0;
P_0c086bee: /* original f472, guest PC 0x0c086bee */
if(!s->budget--) { s->failed_pc=0x0c086beeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c086bf0;
P_0c086bf0: /* original f54d, guest PC 0x0c086bf0 */
if(!s->budget--) { s->failed_pc=0x0c086bf0u; return 0; }
fr[5]^=0x80000000u;
goto P_0c086bf2;
P_0c086bf2: /* original 26c8, guest PC 0x0c086bf2 */
if(!s->budget--) { s->failed_pc=0x0c086bf2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[12])==0)!=0);
goto P_0c086bf4;
P_0c086bf4: /* original 8b00, guest PC 0x0c086bf4 */
if(!s->budget--) { s->failed_pc=0x0c086bf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086bf8; }
goto P_0c086bf6;
P_0c086bf6: /* original f64d, guest PC 0x0c086bf6 */
if(!s->budget--) { s->failed_pc=0x0c086bf6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c086bf8;
P_0c086bf8: /* original 24c8, guest PC 0x0c086bf8 */
if(!s->budget--) { s->failed_pc=0x0c086bf8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[12])==0)!=0);
goto P_0c086bfa;
P_0c086bfa: /* original 8f01, guest PC 0x0c086bfa */
if(!s->budget--) { s->failed_pc=0x0c086bfau; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
if(!cond) { goto P_0c086c00; }
goto P_0c086bfe;
P_0c086bfc: /* original f5e0, guest PC 0x0c086bfc */
if(!s->budget--) { s->failed_pc=0x0c086bfcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[14],r[18],'+');
goto P_0c086bfe;
P_0c086bfe: /* original f44d, guest PC 0x0c086bfe */
if(!s->budget--) { s->failed_pc=0x0c086bfeu; return 0; }
fr[4]^=0x80000000u;
goto P_0c086c00;
P_0c086c00: /* original e004, guest PC 0x0c086c00 */
if(!s->budget--) { s->failed_pc=0x0c086c00u; return 0; }
r[0]=0x00000004u;
goto P_0c086c02;
P_0c086c02: /* original f3f6, guest PC 0x0c086c02 */
if(!s->budget--) { s->failed_pc=0x0c086c02u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c086c04;
P_0c086c04: /* original e018, guest PC 0x0c086c04 */
if(!s->budget--) { s->failed_pc=0x0c086c04u; return 0; }
r[0]=0x00000018u;
goto P_0c086c06;
P_0c086c06: /* original fe57, guest PC 0x0c086c06 */
if(!s->budget--) { s->failed_pc=0x0c086c06u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c086c08;
P_0c086c08: /* original e01c, guest PC 0x0c086c08 */
if(!s->budget--) { s->failed_pc=0x0c086c08u; return 0; }
r[0]=0x0000001cu;
goto P_0c086c0a;
P_0c086c0a: /* original f430, guest PC 0x0c086c0a */
if(!s->budget--) { s->failed_pc=0x0c086c0au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c086c0c;
P_0c086c0c: /* original fe67, guest PC 0x0c086c0c */
if(!s->budget--) { s->failed_pc=0x0c086c0cu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c086c0e;
P_0c086c0e: /* original e020, guest PC 0x0c086c0e */
if(!s->budget--) { s->failed_pc=0x0c086c0eu; return 0; }
r[0]=0x00000020u;
goto P_0c086c10;
P_0c086c10: /* original e300, guest PC 0x0c086c10 */
if(!s->budget--) { s->failed_pc=0x0c086c10u; return 0; }
r[3]=0x00000000u;
goto P_0c086c12;
P_0c086c12: /* original fe47, guest PC 0x0c086c12 */
if(!s->budget--) { s->failed_pc=0x0c086c12u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c086c14;
P_0c086c14: /* original e026, guest PC 0x0c086c14 */
if(!s->budget--) { s->failed_pc=0x0c086c14u; return 0; }
r[0]=0x00000026u;
goto P_0c086c16;
P_0c086c16: /* original 4a0b, guest PC 0x0c086c16 */
if(!s->budget--) { s->failed_pc=0x0c086c16u; return 0; }
target=r[10];
r[16]=code_base|0x0c086c1au;
write(ram,r[14]+r[0],r[3],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086c1au) { target=s->pc; goto dispatch; }
goto P_0c086c1a;
P_0c086c18: /* original 0e34, guest PC 0x0c086c18 */
if(!s->budget--) { s->failed_pc=0x0c086c18u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c086c1a;
P_0c086c1a: /* original e507, guest PC 0x0c086c1a */
if(!s->budget--) { s->failed_pc=0x0c086c1au; return 0; }
r[5]=0x00000007u;
goto P_0c086c1c;
P_0c086c1c: /* original 6403, guest PC 0x0c086c1c */
if(!s->budget--) { s->failed_pc=0x0c086c1cu; return 0; }
r[4]=r[0];
goto P_0c086c1e;
P_0c086c1e: /* original e038, guest PC 0x0c086c1e */
if(!s->budget--) { s->failed_pc=0x0c086c1eu; return 0; }
r[0]=0x00000038u;
goto P_0c086c20;
P_0c086c20: /* original 2549, guest PC 0x0c086c20 */
if(!s->budget--) { s->failed_pc=0x0c086c20u; return 0; }
r[5]&=r[4];
goto P_0c086c22;
P_0c086c22: /* original 04dc, guest PC 0x0c086c22 */
if(!s->budget--) { s->failed_pc=0x0c086c22u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086c24;
P_0c086c24: /* original d02e, guest PC 0x0c086c24 */
if(!s->budget--) { s->failed_pc=0x0c086c24u; return 0; }
r[0]=read(ram,0x0c086ce0u,4);
goto P_0c086c26;
P_0c086c26: /* original 4408, guest PC 0x0c086c26 */
if(!s->budget--) { s->failed_pc=0x0c086c26u; return 0; }
r[4]<<=2;
goto P_0c086c28;
P_0c086c28: /* original 4400, guest PC 0x0c086c28 */
if(!s->budget--) { s->failed_pc=0x0c086c28u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c086c2a;
P_0c086c2a: /* original 354c, guest PC 0x0c086c2a */
if(!s->budget--) { s->failed_pc=0x0c086c2au; return 0; }
r[5]+=r[4];
goto P_0c086c2c;
P_0c086c2c: /* original 055c, guest PC 0x0c086c2c */
if(!s->budget--) { s->failed_pc=0x0c086c2cu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c086c2e;
P_0c086c2e: /* original d02d, guest PC 0x0c086c2e */
if(!s->budget--) { s->failed_pc=0x0c086c2eu; return 0; }
r[0]=read(ram,0x0c086ce4u,4);
goto P_0c086c30;
P_0c086c30: /* original 4508, guest PC 0x0c086c30 */
if(!s->budget--) { s->failed_pc=0x0c086c30u; return 0; }
r[5]<<=2;
goto P_0c086c32;
P_0c086c32: /* original 055e, guest PC 0x0c086c32 */
if(!s->budget--) { s->failed_pc=0x0c086c32u; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c086c34;
P_0c086c34: /* original 1e5a, guest PC 0x0c086c34 */
if(!s->budget--) { s->failed_pc=0x0c086c34u; return 0; }
write(ram,r[14]+40,r[5],4);
goto P_0c086c36;
P_0c086c36: /* original d32c, guest PC 0x0c086c36 */
if(!s->budget--) { s->failed_pc=0x0c086c36u; return 0; }
r[3]=read(ram,0x0c086ce8u,4);
goto P_0c086c38;
P_0c086c38: /* original 430b, guest PC 0x0c086c38 */
if(!s->budget--) { s->failed_pc=0x0c086c38u; return 0; }
target=r[3];
r[16]=code_base|0x0c086c3cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c086c3cu) { target=s->pc; goto dispatch; }
goto P_0c086c3c;
P_0c086c3a: /* original 64e3, guest PC 0x0c086c3a */
if(!s->budget--) { s->failed_pc=0x0c086c3au; return 0; }
r[4]=r[14];
goto P_0c086c3c;
P_0c086c3c: /* original 858f, guest PC 0x0c086c3c */
if(!s->budget--) { s->failed_pc=0x0c086c3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[8]+30,2);
goto P_0c086c3e;
P_0c086c3e: /* original 79ff, guest PC 0x0c086c3e */
if(!s->budget--) { s->failed_pc=0x0c086c3eu; return 0; }
r[9]+=0xffffffffu;
goto P_0c086c40;
P_0c086c40: /* original d32a, guest PC 0x0c086c40 */
if(!s->budget--) { s->failed_pc=0x0c086c40u; return 0; }
r[3]=read(ram,0x0c086cecu,4);
goto P_0c086c42;
P_0c086c42: /* original 6403, guest PC 0x0c086c42 */
if(!s->budget--) { s->failed_pc=0x0c086c42u; return 0; }
r[4]=r[0];
goto P_0c086c44;
P_0c086c44: /* original 9146, guest PC 0x0c086c44 */
if(!s->budget--) { s->failed_pc=0x0c086c44u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd4u,2);
goto P_0c086c46;
P_0c086c46: /* original 6032, guest PC 0x0c086c46 */
if(!s->budget--) { s->failed_pc=0x0c086c46u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c086c48;
P_0c086c48: /* original e3f3, guest PC 0x0c086c48 */
if(!s->budget--) { s->failed_pc=0x0c086c48u; return 0; }
r[3]=0xfffffff3u;
goto P_0c086c4a;
P_0c086c4a: /* original c903, guest PC 0x0c086c4a */
if(!s->budget--) { s->failed_pc=0x0c086c4au; return 0; }
r[0]&=3u;
goto P_0c086c4c;
P_0c086c4c: /* original 6503, guest PC 0x0c086c4c */
if(!s->budget--) { s->failed_pc=0x0c086c4cu; return 0; }
r[5]=r[0];
goto P_0c086c4e;
P_0c086c4e: /* original d028, guest PC 0x0c086c4e */
if(!s->budget--) { s->failed_pc=0x0c086c4eu; return 0; }
r[0]=read(ram,0x0c086cf0u,4);
goto P_0c086c50;
P_0c086c50: /* original 4500, guest PC 0x0c086c50 */
if(!s->budget--) { s->failed_pc=0x0c086c50u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c086c52;
P_0c086c52: /* original 025d, guest PC 0x0c086c52 */
if(!s->budget--) { s->failed_pc=0x0c086c52u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c086c54;
P_0c086c54: /* original 903f, guest PC 0x0c086c54 */
if(!s->budget--) { s->failed_pc=0x0c086c54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd6u,2);
goto P_0c086c56;
P_0c086c56: /* original 652d, guest PC 0x0c086c56 */
if(!s->budget--) { s->failed_pc=0x0c086c56u; return 0; }
r[5]=r[2]&65535u;
goto P_0c086c58;
P_0c086c58: /* original 345c, guest PC 0x0c086c58 */
if(!s->budget--) { s->failed_pc=0x0c086c58u; return 0; }
r[4]+=r[5];
goto P_0c086c5a;
P_0c086c5a: /* original 341c, guest PC 0x0c086c5a */
if(!s->budget--) { s->failed_pc=0x0c086c5au; return 0; }
r[4]+=r[1];
goto P_0c086c5c;
P_0c086c5c: /* original e503, guest PC 0x0c086c5c */
if(!s->budget--) { s->failed_pc=0x0c086c5cu; return 0; }
r[5]=0x00000003u;
goto P_0c086c5e;
P_0c086c5e: /* original 443c, guest PC 0x0c086c5e */
if(!s->budget--) { s->failed_pc=0x0c086c5eu; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c086c60;
P_0c086c60: /* original 2549, guest PC 0x0c086c60 */
if(!s->budget--) { s->failed_pc=0x0c086c60u; return 0; }
r[5]&=r[4];
goto P_0c086c62;
P_0c086c62: /* original 305c, guest PC 0x0c086c62 */
if(!s->budget--) { s->failed_pc=0x0c086c62u; return 0; }
r[0]+=r[5];
goto P_0c086c64;
P_0c086c64: /* original 81e5, guest PC 0x0c086c64 */
if(!s->budget--) { s->failed_pc=0x0c086c64u; return 0; }
write(ram,r[14]+10,r[0],2);
goto P_0c086c66;
P_0c086c66: /* original 2998, guest PC 0x0c086c66 */
if(!s->budget--) { s->failed_pc=0x0c086c66u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c086c68;
P_0c086c68: /* original 8b98, guest PC 0x0c086c68 */
if(!s->budget--) { s->failed_pc=0x0c086c68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086b9c; }
goto P_0c086c6a;
P_0c086c6a: /* original e03b, guest PC 0x0c086c6a */
if(!s->budget--) { s->failed_pc=0x0c086c6au; return 0; }
r[0]=0x0000003bu;
goto P_0c086c6c;
P_0c086c6c: /* original 04dc, guest PC 0x0c086c6c */
if(!s->budget--) { s->failed_pc=0x0c086c6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c086c6e;
P_0c086c6e: /* original 4410, guest PC 0x0c086c6e */
if(!s->budget--) { s->failed_pc=0x0c086c6eu; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c086c70;
P_0c086c70: /* original 8b20, guest PC 0x0c086c70 */
if(!s->budget--) { s->failed_pc=0x0c086c70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c086cb4; }
goto P_0c086c72;
P_0c086c72: /* original c721, guest PC 0x0c086c72 */
if(!s->budget--) { s->failed_pc=0x0c086c72u; return 0; }
r[0]=code_base|0x00086cf8u;
goto P_0c086c74;
P_0c086c74: /* original d31f, guest PC 0x0c086c74 */
if(!s->budget--) { s->failed_pc=0x0c086c74u; return 0; }
r[3]=read(ram,0x0c086cf4u,4);
goto P_0c086c76;
P_0c086c76: /* original f608, guest PC 0x0c086c76 */
if(!s->budget--) { s->failed_pc=0x0c086c76u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c086c78;
P_0c086c78: /* original e010, guest PC 0x0c086c78 */
if(!s->budget--) { s->failed_pc=0x0c086c78u; return 0; }
r[0]=0x00000010u;
goto P_0c086c7a;
P_0c086c7a: /* original f486, guest PC 0x0c086c7a */
if(!s->budget--) { s->failed_pc=0x0c086c7au; return 0; }
vf3_matrix_load(s,ram,4,r[8]+r[0]);
goto P_0c086c7c;
P_0c086c7c: /* original e018, guest PC 0x0c086c7c */
if(!s->budget--) { s->failed_pc=0x0c086c7cu; return 0; }
r[0]=0x00000018u;
goto P_0c086c7e;
P_0c086c7e: /* original f586, guest PC 0x0c086c7e */
if(!s->budget--) { s->failed_pc=0x0c086c7eu; return 0; }
vf3_matrix_load(s,ram,5,r[8]+r[0]);
goto P_0c086c80;
P_0c086c80: /* original e00c, guest PC 0x0c086c80 */
if(!s->budget--) { s->failed_pc=0x0c086c80u; return 0; }
r[0]=0x0000000cu;
goto P_0c086c82;
P_0c086c82: /* original f7d6, guest PC 0x0c086c82 */
if(!s->budget--) { s->failed_pc=0x0c086c82u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c086c84;
P_0c086c84: /* original e014, guest PC 0x0c086c84 */
if(!s->budget--) { s->failed_pc=0x0c086c84u; return 0; }
r[0]=0x00000014u;
goto P_0c086c86;
P_0c086c86: /* original f8d6, guest PC 0x0c086c86 */
if(!s->budget--) { s->failed_pc=0x0c086c86u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c086c88;
P_0c086c88: /* original e43f, guest PC 0x0c086c88 */
if(!s->budget--) { s->failed_pc=0x0c086c88u; return 0; }
r[4]=0x0000003fu;
goto P_0c086c8a;
P_0c086c8a: /* original f471, guest PC 0x0c086c8a */
if(!s->budget--) { s->failed_pc=0x0c086c8au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c086c8c;
P_0c086c8c: /* original 2459, guest PC 0x0c086c8c */
if(!s->budget--) { s->failed_pc=0x0c086c8cu; return 0; }
r[4]&=r[5];
goto P_0c086c8e;
P_0c086c8e: /* original f581, guest PC 0x0c086c8e */
if(!s->budget--) { s->failed_pc=0x0c086c8eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c086c90;
P_0c086c90: /* original 6532, guest PC 0x0c086c90 */
if(!s->budget--) { s->failed_pc=0x0c086c90u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c086c92;
P_0c086c92: /* original 7407, guest PC 0x0c086c92 */
if(!s->budget--) { s->failed_pc=0x0c086c92u; return 0; }
r[4]+=0x00000007u;
goto P_0c086c94;
P_0c086c94: /* original f34c, guest PC 0x0c086c94 */
if(!s->budget--) { s->failed_pc=0x0c086c94u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c086c96;
P_0c086c96: /* original f432, guest PC 0x0c086c96 */
if(!s->budget--) { s->failed_pc=0x0c086c96u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c086c98;
P_0c086c98: /* original f35c, guest PC 0x0c086c98 */
if(!s->budget--) { s->failed_pc=0x0c086c98u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c086c9a;
P_0c086c9a: /* original f532, guest PC 0x0c086c9a */
if(!s->budget--) { s->failed_pc=0x0c086c9au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c086c9c;
P_0c086c9c: /* original f450, guest PC 0x0c086c9c */
if(!s->budget--) { s->failed_pc=0x0c086c9cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c086c9e;
P_0c086c9e: /* original f465, guest PC 0x0c086c9e */
if(!s->budget--) { s->failed_pc=0x0c086c9eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c086ca0;
P_0c086ca0: /* original 8d03, guest PC 0x0c086ca0 */
if(!s->budget--) { s->failed_pc=0x0c086ca0u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[5],4);
r[5]=tmp;
if(cond) { goto P_0c086caa; }
goto P_0c086ca4;
P_0c086ca2: /* original 6552, guest PC 0x0c086ca2 */
if(!s->budget--) { s->failed_pc=0x0c086ca2u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c086ca4;
P_0c086ca4: /* original 9118, guest PC 0x0c086ca4 */
if(!s->budget--) { s->failed_pc=0x0c086ca4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cd8u,2);
goto P_0c086ca6;
P_0c086ca6: /* original a002, guest PC 0x0c086ca6 */
if(!s->budget--) { s->failed_pc=0x0c086ca6u; return 0; }
r[5]|=r[1];
goto P_0c086cae;
P_0c086ca8: /* original 251b, guest PC 0x0c086ca8 */
if(!s->budget--) { s->failed_pc=0x0c086ca8u; return 0; }
r[5]|=r[1];
goto P_0c086caa;
P_0c086caa: /* original 9016, guest PC 0x0c086caa */
if(!s->budget--) { s->failed_pc=0x0c086caau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c086cdau,2);
goto P_0c086cac;
P_0c086cac: /* original 250b, guest PC 0x0c086cac */
if(!s->budget--) { s->failed_pc=0x0c086cacu; return 0; }
r[5]|=r[0];
goto P_0c086cae;
P_0c086cae: /* original d211, guest PC 0x0c086cae */
if(!s->budget--) { s->failed_pc=0x0c086caeu; return 0; }
r[2]=read(ram,0x0c086cf4u,4);
goto P_0c086cb0;
P_0c086cb0: /* original 6322, guest PC 0x0c086cb0 */
if(!s->budget--) { s->failed_pc=0x0c086cb0u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c086cb2;
P_0c086cb2: /* original 2352, guest PC 0x0c086cb2 */
if(!s->budget--) { s->failed_pc=0x0c086cb2u; return 0; }
write(ram,r[3],r[5],4);
goto P_0c086cb4;
P_0c086cb4: /* original e03b, guest PC 0x0c086cb4 */
if(!s->budget--) { s->failed_pc=0x0c086cb4u; return 0; }
r[0]=0x0000003bu;
goto P_0c086cb6;
P_0c086cb6: /* original 0d44, guest PC 0x0c086cb6 */
if(!s->budget--) { s->failed_pc=0x0c086cb6u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c086cb8;
P_0c086cb8: /* original 7f08, guest PC 0x0c086cb8 */
if(!s->budget--) { s->failed_pc=0x0c086cb8u; return 0; }
r[15]+=0x00000008u;
goto P_0c086cba;
P_0c086cba: /* original 4f26, guest PC 0x0c086cba */
if(!s->budget--) { s->failed_pc=0x0c086cbau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c086cbc;
P_0c086cbc: /* original fcf9, guest PC 0x0c086cbc */
if(!s->budget--) { s->failed_pc=0x0c086cbcu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cbe;
P_0c086cbe: /* original fdf9, guest PC 0x0c086cbe */
if(!s->budget--) { s->failed_pc=0x0c086cbeu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc0;
P_0c086cc0: /* original fef9, guest PC 0x0c086cc0 */
if(!s->budget--) { s->failed_pc=0x0c086cc0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc2;
P_0c086cc2: /* original fff9, guest PC 0x0c086cc2 */
if(!s->budget--) { s->failed_pc=0x0c086cc2u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c086cc4;
P_0c086cc4: /* original 68f6, guest PC 0x0c086cc4 */
if(!s->budget--) { s->failed_pc=0x0c086cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c086cc6;
P_0c086cc6: /* original 69f6, guest PC 0x0c086cc6 */
if(!s->budget--) { s->failed_pc=0x0c086cc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c086cc8;
P_0c086cc8: /* original 6af6, guest PC 0x0c086cc8 */
if(!s->budget--) { s->failed_pc=0x0c086cc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c086cca;
P_0c086cca: /* original 6bf6, guest PC 0x0c086cca */
if(!s->budget--) { s->failed_pc=0x0c086ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c086ccc;
P_0c086ccc: /* original 6cf6, guest PC 0x0c086ccc */
if(!s->budget--) { s->failed_pc=0x0c086cccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c086cce;
P_0c086cce: /* original 6df6, guest PC 0x0c086cce */
if(!s->budget--) { s->failed_pc=0x0c086cceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c086cd0;
P_0c086cd0: /* original 000b, guest PC 0x0c086cd0 */
if(!s->budget--) { s->failed_pc=0x0c086cd0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c086cd2: /* original 6ef6, guest PC 0x0c086cd2 */
if(!s->budget--) { s->failed_pc=0x0c086cd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c086cd4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c086cd4u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
