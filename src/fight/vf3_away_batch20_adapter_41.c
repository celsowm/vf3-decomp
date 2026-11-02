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
int vf3_away_batch20_adapter_41(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2a74u: goto P_0c0a2a74;
case 0x0c0a2a76u: goto P_0c0a2a76;
case 0x0c0a2a78u: goto P_0c0a2a78;
case 0x0c0a2a7au: goto P_0c0a2a7a;
case 0x0c0a2a7cu: goto P_0c0a2a7c;
case 0x0c0a2a7eu: goto P_0c0a2a7e;
case 0x0c0a2a80u: goto P_0c0a2a80;
case 0x0c0a2a82u: goto P_0c0a2a82;
case 0x0c0a2a84u: goto P_0c0a2a84;
case 0x0c0a2a86u: goto P_0c0a2a86;
case 0x0c0a2a88u: goto P_0c0a2a88;
case 0x0c0a2a8au: goto P_0c0a2a8a;
case 0x0c0a2a8cu: goto P_0c0a2a8c;
case 0x0c0a2a8eu: goto P_0c0a2a8e;
case 0x0c0a2a90u: goto P_0c0a2a90;
case 0x0c0a2a92u: goto P_0c0a2a92;
case 0x0c0a2a94u: goto P_0c0a2a94;
case 0x0c0a2a96u: goto P_0c0a2a96;
case 0x0c0a2a98u: goto P_0c0a2a98;
case 0x0c0a2a9au: goto P_0c0a2a9a;
case 0x0c0a2a9cu: goto P_0c0a2a9c;
case 0x0c0a2a9eu: goto P_0c0a2a9e;
case 0x0c0a2aa0u: goto P_0c0a2aa0;
case 0x0c0a2aa2u: goto P_0c0a2aa2;
case 0x0c0a2aa4u: goto P_0c0a2aa4;
case 0x0c0a2aa6u: goto P_0c0a2aa6;
case 0x0c0a2aa8u: goto P_0c0a2aa8;
case 0x0c0a2aaau: goto P_0c0a2aaa;
case 0x0c0a2aacu: goto P_0c0a2aac;
case 0x0c0a2aaeu: goto P_0c0a2aae;
case 0x0c0a2ab0u: goto P_0c0a2ab0;
case 0x0c0a2ab2u: goto P_0c0a2ab2;
case 0x0c0a2ab4u: goto P_0c0a2ab4;
case 0x0c0a2ab6u: goto P_0c0a2ab6;
case 0x0c0a2ab8u: goto P_0c0a2ab8;
case 0x0c0a2abau: goto P_0c0a2aba;
case 0x0c0a2abcu: goto P_0c0a2abc;
case 0x0c0a2abeu: goto P_0c0a2abe;
case 0x0c0a2ac0u: goto P_0c0a2ac0;
case 0x0c0a2ac2u: goto P_0c0a2ac2;
case 0x0c0a2ac4u: goto P_0c0a2ac4;
case 0x0c0a2ac6u: goto P_0c0a2ac6;
case 0x0c0a2ac8u: goto P_0c0a2ac8;
case 0x0c0a2acau: goto P_0c0a2aca;
case 0x0c0a2accu: goto P_0c0a2acc;
case 0x0c0a2aceu: goto P_0c0a2ace;
case 0x0c0a2ad0u: goto P_0c0a2ad0;
case 0x0c0a2ad2u: goto P_0c0a2ad2;
case 0x0c0a2ad4u: goto P_0c0a2ad4;
case 0x0c0a2ad6u: goto P_0c0a2ad6;
case 0x0c0a2ad8u: goto P_0c0a2ad8;
case 0x0c0a2adau: goto P_0c0a2ada;
case 0x0c0a2adcu: goto P_0c0a2adc;
case 0x0c0a2adeu: goto P_0c0a2ade;
case 0x0c0a2ae0u: goto P_0c0a2ae0;
case 0x0c0a2ae2u: goto P_0c0a2ae2;
case 0x0c0a2ae4u: goto P_0c0a2ae4;
case 0x0c0a2ae6u: goto P_0c0a2ae6;
case 0x0c0a2ae8u: goto P_0c0a2ae8;
case 0x0c0a2aeau: goto P_0c0a2aea;
case 0x0c0a2aecu: goto P_0c0a2aec;
case 0x0c0a2aeeu: goto P_0c0a2aee;
case 0x0c0a2af0u: goto P_0c0a2af0;
case 0x0c0a2af2u: goto P_0c0a2af2;
case 0x0c0a2af4u: goto P_0c0a2af4;
case 0x0c0a2af6u: goto P_0c0a2af6;
case 0x0c0a2af8u: goto P_0c0a2af8;
case 0x0c0a2afau: goto P_0c0a2afa;
case 0x0c0a2afcu: goto P_0c0a2afc;
case 0x0c0a2afeu: goto P_0c0a2afe;
case 0x0c0a2b00u: goto P_0c0a2b00;
case 0x0c0a2b02u: goto P_0c0a2b02;
case 0x0c0a2b04u: goto P_0c0a2b04;
case 0x0c0a2b06u: goto P_0c0a2b06;
case 0x0c0a2b08u: goto P_0c0a2b08;
case 0x0c0a2b0au: goto P_0c0a2b0a;
case 0x0c0a2b0cu: goto P_0c0a2b0c;
case 0x0c0a2b0eu: goto P_0c0a2b0e;
case 0x0c0a2b10u: goto P_0c0a2b10;
case 0x0c0a2b12u: goto P_0c0a2b12;
case 0x0c0a2b14u: goto P_0c0a2b14;
case 0x0c0a2b16u: goto P_0c0a2b16;
case 0x0c0a2b18u: goto P_0c0a2b18;
case 0x0c0a2b1au: goto P_0c0a2b1a;
case 0x0c0a2b1cu: goto P_0c0a2b1c;
case 0x0c0a2b1eu: goto P_0c0a2b1e;
case 0x0c0a2b20u: goto P_0c0a2b20;
case 0x0c0a2b22u: goto P_0c0a2b22;
case 0x0c0a2b24u: goto P_0c0a2b24;
case 0x0c0a2b26u: goto P_0c0a2b26;
case 0x0c0a2b28u: goto P_0c0a2b28;
case 0x0c0a2b2au: goto P_0c0a2b2a;
case 0x0c0a2b2cu: goto P_0c0a2b2c;
case 0x0c0a2b2eu: goto P_0c0a2b2e;
case 0x0c0a2b30u: goto P_0c0a2b30;
case 0x0c0a2b32u: goto P_0c0a2b32;
case 0x0c0a2b34u: goto P_0c0a2b34;
case 0x0c0a2b36u: goto P_0c0a2b36;
case 0x0c0a2b38u: goto P_0c0a2b38;
case 0x0c0a2b3au: goto P_0c0a2b3a;
case 0x0c0a2b3cu: goto P_0c0a2b3c;
case 0x0c0a2b3eu: goto P_0c0a2b3e;
case 0x0c0a2b40u: goto P_0c0a2b40;
case 0x0c0a2b42u: goto P_0c0a2b42;
case 0x0c0a2b44u: goto P_0c0a2b44;
case 0x0c0a2b46u: goto P_0c0a2b46;
case 0x0c0a2b48u: goto P_0c0a2b48;
case 0x0c0a2b4au: goto P_0c0a2b4a;
case 0x0c0a2b4cu: goto P_0c0a2b4c;
case 0x0c0a2b4eu: goto P_0c0a2b4e;
case 0x0c0a2b50u: goto P_0c0a2b50;
case 0x0c0a2b52u: goto P_0c0a2b52;
case 0x0c0a2b54u: goto P_0c0a2b54;
case 0x0c0a2b56u: goto P_0c0a2b56;
case 0x0c0a2b58u: goto P_0c0a2b58;
case 0x0c0a2b5au: goto P_0c0a2b5a;
case 0x0c0a2b5cu: goto P_0c0a2b5c;
case 0x0c0a2b5eu: goto P_0c0a2b5e;
case 0x0c0a2b60u: goto P_0c0a2b60;
case 0x0c0a2b62u: goto P_0c0a2b62;
case 0x0c0a2b64u: goto P_0c0a2b64;
case 0x0c0a2b66u: goto P_0c0a2b66;
case 0x0c0a2b68u: goto P_0c0a2b68;
case 0x0c0a2b6au: goto P_0c0a2b6a;
case 0x0c0a2b6cu: goto P_0c0a2b6c;
case 0x0c0a2b6eu: goto P_0c0a2b6e;
case 0x0c0a2b70u: goto P_0c0a2b70;
case 0x0c0a2b72u: goto P_0c0a2b72;
case 0x0c0a2b74u: goto P_0c0a2b74;
case 0x0c0a2b76u: goto P_0c0a2b76;
case 0x0c0a2b78u: goto P_0c0a2b78;
case 0x0c0a2b7au: goto P_0c0a2b7a;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2a74: /* original 2fe6, guest PC 0x0c0a2a74 */
if(!s->budget--) { s->failed_pc=0x0c0a2a74u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a76;
P_0c0a2a76: /* original 6e43, guest PC 0x0c0a2a76 */
if(!s->budget--) { s->failed_pc=0x0c0a2a76u; return 0; }
r[14]=r[4];
goto P_0c0a2a78;
P_0c0a2a78: /* original 2fd6, guest PC 0x0c0a2a78 */
if(!s->budget--) { s->failed_pc=0x0c0a2a78u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a7a;
P_0c0a2a7a: /* original 2fc6, guest PC 0x0c0a2a7a */
if(!s->budget--) { s->failed_pc=0x0c0a2a7au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a7c;
P_0c0a2a7c: /* original 2fb6, guest PC 0x0c0a2a7c */
if(!s->budget--) { s->failed_pc=0x0c0a2a7cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a7e;
P_0c0a2a7e: /* original 2fa6, guest PC 0x0c0a2a7e */
if(!s->budget--) { s->failed_pc=0x0c0a2a7eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a80;
P_0c0a2a80: /* original 2f96, guest PC 0x0c0a2a80 */
if(!s->budget--) { s->failed_pc=0x0c0a2a80u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a82;
P_0c0a2a82: /* original 2f86, guest PC 0x0c0a2a82 */
if(!s->budget--) { s->failed_pc=0x0c0a2a82u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a84;
P_0c0a2a84: /* original 4f22, guest PC 0x0c0a2a84 */
if(!s->budget--) { s->failed_pc=0x0c0a2a84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2a86;
P_0c0a2a86: /* original 7ff4, guest PC 0x0c0a2a86 */
if(!s->budget--) { s->failed_pc=0x0c0a2a86u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2a88;
P_0c0a2a88: /* original 2f61, guest PC 0x0c0a2a88 */
if(!s->budget--) { s->failed_pc=0x0c0a2a88u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a2a8a;
P_0c0a2a8a: /* original 1f72, guest PC 0x0c0a2a8a */
if(!s->budget--) { s->failed_pc=0x0c0a2a8au; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a2a8c;
P_0c0a2a8c: /* original b0d3, guest PC 0x0c0a2a8c */
if(!s->budget--) { s->failed_pc=0x0c0a2a8cu; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a2a90u;
r[11]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a90u) { target=s->pc; goto dispatch; }
goto P_0c0a2a90;
P_0c0a2a8e: /* original 6b53, guest PC 0x0c0a2a8e */
if(!s->budget--) { s->failed_pc=0x0c0a2a8eu; return 0; }
r[11]=r[5];
goto P_0c0a2a90;
P_0c0a2a90: /* original 6d03, guest PC 0x0c0a2a90 */
if(!s->budget--) { s->failed_pc=0x0c0a2a90u; return 0; }
r[13]=r[0];
goto P_0c0a2a92;
P_0c0a2a92: /* original 2dd8, guest PC 0x0c0a2a92 */
if(!s->budget--) { s->failed_pc=0x0c0a2a92u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a2a94;
P_0c0a2a94: /* original 8902, guest PC 0x0c0a2a94 */
if(!s->budget--) { s->failed_pc=0x0c0a2a94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a9c; }
goto P_0c0a2a96;
P_0c0a2a96: /* original d339, guest PC 0x0c0a2a96 */
if(!s->budget--) { s->failed_pc=0x0c0a2a96u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a2a98;
P_0c0a2a98: /* original 3d30, guest PC 0x0c0a2a98 */
if(!s->budget--) { s->failed_pc=0x0c0a2a98u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0a2a9a;
P_0c0a2a9a: /* original 8b60, guest PC 0x0c0a2a9a */
if(!s->budget--) { s->failed_pc=0x0c0a2a9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b5e; }
goto P_0c0a2a9c;
P_0c0a2a9c: /* original e020, guest PC 0x0c0a2a9c */
if(!s->budget--) { s->failed_pc=0x0c0a2a9cu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2a9e;
P_0c0a2a9e: /* original 01ed, guest PC 0x0c0a2a9e */
if(!s->budget--) { s->failed_pc=0x0c0a2a9eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2aa0;
P_0c0a2aa0: /* original e022, guest PC 0x0c0a2aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa0u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2aa2;
P_0c0a2aa2: /* original 03ed, guest PC 0x0c0a2aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2aa4;
P_0c0a2aa4: /* original 611d, guest PC 0x0c0a2aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a2aa6;
P_0c0a2aa6: /* original 633d, guest PC 0x0c0a2aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa6u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2aa8;
P_0c0a2aa8: /* original 213b, guest PC 0x0c0a2aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa8u; return 0; }
r[1]|=r[3];
goto P_0c0a2aaa;
P_0c0a2aaa: /* original 2118, guest PC 0x0c0a2aaa */
if(!s->budget--) { s->failed_pc=0x0c0a2aaau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a2aac;
P_0c0a2aac: /* original 8b5b, guest PC 0x0c0a2aac */
if(!s->budget--) { s->failed_pc=0x0c0a2aacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b66; }
goto P_0c0a2aae;
P_0c0a2aae: /* original e020, guest PC 0x0c0a2aae */
if(!s->budget--) { s->failed_pc=0x0c0a2aaeu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2ab0;
P_0c0a2ab0: /* original 52e4, guest PC 0x0c0a2ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab0u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a2ab2;
P_0c0a2ab2: /* original 1f21, guest PC 0x0c0a2ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab2u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2ab4;
P_0c0a2ab4: /* original 63f1, guest PC 0x0c0a2ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2ab6;
P_0c0a2ab6: /* original 5de5, guest PC 0x0c0a2ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab6u; return 0; }
r[13]=read(ram,r[14]+20,4);
goto P_0c0a2ab8;
P_0c0a2ab8: /* original 0e35, guest PC 0x0c0a2ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a2aba;
P_0c0a2aba: /* original 04ed, guest PC 0x0c0a2aba */
if(!s->budget--) { s->failed_pc=0x0c0a2abau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2abc;
P_0c0a2abc: /* original d330, guest PC 0x0c0a2abc */
if(!s->budget--) { s->failed_pc=0x0c0a2abcu; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a2abe;
P_0c0a2abe: /* original 430b, guest PC 0x0c0a2abe */
if(!s->budget--) { s->failed_pc=0x0c0a2abeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ac2u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ac2u) { target=s->pc; goto dispatch; }
goto P_0c0a2ac2;
P_0c0a2ac0: /* original 644d, guest PC 0x0c0a2ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2ac2;
P_0c0a2ac2: /* original d333, guest PC 0x0c0a2ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac2u; return 0; }
r[3]=read(ram,0x0c0a2b90u,4);
goto P_0c0a2ac4;
P_0c0a2ac4: /* original 430b, guest PC 0x0c0a2ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ac8u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ac8u) { target=s->pc; goto dispatch; }
goto P_0c0a2ac8;
P_0c0a2ac6: /* original 54f2, guest PC 0x0c0a2ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0a2ac8;
P_0c0a2ac8: /* original ea00, guest PC 0x0c0a2ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac8u; return 0; }
r[10]=0x00000000u;
goto P_0c0a2aca;
P_0c0a2aca: /* original a039, guest PC 0x0c0a2aca */
if(!s->budget--) { s->failed_pc=0x0c0a2acau; return 0; }
r[8]=r[10];
goto P_0c0a2b40;
P_0c0a2acc: /* original 68a3, guest PC 0x0c0a2acc */
if(!s->budget--) { s->failed_pc=0x0c0a2accu; return 0; }
r[8]=r[10];
goto P_0c0a2ace;
P_0c0a2ace: /* original 53f1, guest PC 0x0c0a2ace */
if(!s->budget--) { s->failed_pc=0x0c0a2aceu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a2ad0;
P_0c0a2ad0: /* original 6c83, guest PC 0x0c0a2ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad0u; return 0; }
r[12]=r[8];
goto P_0c0a2ad2;
P_0c0a2ad2: /* original 4c08, guest PC 0x0c0a2ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad2u; return 0; }
r[12]<<=2;
goto P_0c0a2ad4;
P_0c0a2ad4: /* original 3c3c, guest PC 0x0c0a2ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad4u; return 0; }
r[12]+=r[3];
goto P_0c0a2ad6;
P_0c0a2ad6: /* original 60c2, guest PC 0x0c0a2ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad6u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0a2ad8;
P_0c0a2ad8: /* original 5001, guest PC 0x0c0a2ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad8u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a2ada;
P_0c0a2ada: /* original c801, guest PC 0x0c0a2ada */
if(!s->budget--) { s->failed_pc=0x0c0a2adau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2adc;
P_0c0a2adc: /* original 8922, guest PC 0x0c0a2adc */
if(!s->budget--) { s->failed_pc=0x0c0a2adcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2b24; }
goto P_0c0a2ade;
P_0c0a2ade: /* original a008, guest PC 0x0c0a2ade */
if(!s->budget--) { s->failed_pc=0x0c0a2adeu; return 0; }
r[4]=r[10];
goto P_0c0a2af2;
P_0c0a2ae0: /* original 64a3, guest PC 0x0c0a2ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae0u; return 0; }
r[4]=r[10];
goto P_0c0a2ae2;
P_0c0a2ae2: /* original 6343, guest PC 0x0c0a2ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae2u; return 0; }
r[3]=r[4];
goto P_0c0a2ae4;
P_0c0a2ae4: /* original 4308, guest PC 0x0c0a2ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae4u; return 0; }
r[3]<<=2;
goto P_0c0a2ae6;
P_0c0a2ae6: /* original 4308, guest PC 0x0c0a2ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae6u; return 0; }
r[3]<<=2;
goto P_0c0a2ae8;
P_0c0a2ae8: /* original 33dc, guest PC 0x0c0a2ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae8u; return 0; }
r[3]+=r[13];
goto P_0c0a2aea;
P_0c0a2aea: /* original 5232, guest PC 0x0c0a2aea */
if(!s->budget--) { s->failed_pc=0x0c0a2aeau; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2aec;
P_0c0a2aec: /* original 7401, guest PC 0x0c0a2aec */
if(!s->budget--) { s->failed_pc=0x0c0a2aecu; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2aee;
P_0c0a2aee: /* original 32bc, guest PC 0x0c0a2aee */
if(!s->budget--) { s->failed_pc=0x0c0a2aeeu; return 0; }
r[2]+=r[11];
goto P_0c0a2af0;
P_0c0a2af0: /* original 1322, guest PC 0x0c0a2af0 */
if(!s->budget--) { s->failed_pc=0x0c0a2af0u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2af2;
P_0c0a2af2: /* original 85e7, guest PC 0x0c0a2af2 */
if(!s->budget--) { s->failed_pc=0x0c0a2af2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2af4;
P_0c0a2af4: /* original 600d, guest PC 0x0c0a2af4 */
if(!s->budget--) { s->failed_pc=0x0c0a2af4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2af6;
P_0c0a2af6: /* original 3403, guest PC 0x0c0a2af6 */
if(!s->budget--) { s->failed_pc=0x0c0a2af6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2af8;
P_0c0a2af8: /* original 8bf3, guest PC 0x0c0a2af8 */
if(!s->budget--) { s->failed_pc=0x0c0a2af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2ae2; }
goto P_0c0a2afa;
P_0c0a2afa: /* original d222, guest PC 0x0c0a2afa */
if(!s->budget--) { s->failed_pc=0x0c0a2afau; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2afc;
P_0c0a2afc: /* original 65d3, guest PC 0x0c0a2afc */
if(!s->budget--) { s->failed_pc=0x0c0a2afcu; return 0; }
r[5]=r[13];
goto P_0c0a2afe;
P_0c0a2afe: /* original 420b, guest PC 0x0c0a2afe */
if(!s->budget--) { s->failed_pc=0x0c0a2afeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b02u;
tmp=read(ram,r[12],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b02u) { target=s->pc; goto dispatch; }
goto P_0c0a2b02;
P_0c0a2b00: /* original 64c2, guest PC 0x0c0a2b00 */
if(!s->budget--) { s->failed_pc=0x0c0a2b00u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a2b02;
P_0c0a2b02: /* original 2008, guest PC 0x0c0a2b02 */
if(!s->budget--) { s->failed_pc=0x0c0a2b02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2b04;
P_0c0a2b04: /* original a008, guest PC 0x0c0a2b04 */
if(!s->budget--) { s->failed_pc=0x0c0a2b04u; return 0; }
r[4]=r[10];
goto P_0c0a2b18;
P_0c0a2b06: /* original 64a3, guest PC 0x0c0a2b06 */
if(!s->budget--) { s->failed_pc=0x0c0a2b06u; return 0; }
r[4]=r[10];
goto P_0c0a2b08;
P_0c0a2b08: /* original 6343, guest PC 0x0c0a2b08 */
if(!s->budget--) { s->failed_pc=0x0c0a2b08u; return 0; }
r[3]=r[4];
goto P_0c0a2b0a;
P_0c0a2b0a: /* original 4308, guest PC 0x0c0a2b0a */
if(!s->budget--) { s->failed_pc=0x0c0a2b0au; return 0; }
r[3]<<=2;
goto P_0c0a2b0c;
P_0c0a2b0c: /* original 4308, guest PC 0x0c0a2b0c */
if(!s->budget--) { s->failed_pc=0x0c0a2b0cu; return 0; }
r[3]<<=2;
goto P_0c0a2b0e;
P_0c0a2b0e: /* original 33dc, guest PC 0x0c0a2b0e */
if(!s->budget--) { s->failed_pc=0x0c0a2b0eu; return 0; }
r[3]+=r[13];
goto P_0c0a2b10;
P_0c0a2b10: /* original 5232, guest PC 0x0c0a2b10 */
if(!s->budget--) { s->failed_pc=0x0c0a2b10u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2b12;
P_0c0a2b12: /* original 7401, guest PC 0x0c0a2b12 */
if(!s->budget--) { s->failed_pc=0x0c0a2b12u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2b14;
P_0c0a2b14: /* original 32b8, guest PC 0x0c0a2b14 */
if(!s->budget--) { s->failed_pc=0x0c0a2b14u; return 0; }
r[2]-=r[11];
goto P_0c0a2b16;
P_0c0a2b16: /* original 1322, guest PC 0x0c0a2b16 */
if(!s->budget--) { s->failed_pc=0x0c0a2b16u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2b18;
P_0c0a2b18: /* original 85e7, guest PC 0x0c0a2b18 */
if(!s->budget--) { s->failed_pc=0x0c0a2b18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2b1a;
P_0c0a2b1a: /* original 600d, guest PC 0x0c0a2b1a */
if(!s->budget--) { s->failed_pc=0x0c0a2b1au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2b1c;
P_0c0a2b1c: /* original 3403, guest PC 0x0c0a2b1c */
if(!s->budget--) { s->failed_pc=0x0c0a2b1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2b1e;
P_0c0a2b1e: /* original 8bf3, guest PC 0x0c0a2b1e */
if(!s->budget--) { s->failed_pc=0x0c0a2b1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b08; }
goto P_0c0a2b20;
P_0c0a2b20: /* original a00d, guest PC 0x0c0a2b20 */
if(!s->budget--) { s->failed_pc=0x0c0a2b20u; return 0; }
goto P_0c0a2b3e;
P_0c0a2b22: /* original 0009, guest PC 0x0c0a2b22 */
if(!s->budget--) { s->failed_pc=0x0c0a2b22u; return 0; }
goto P_0c0a2b24;
P_0c0a2b24: /* original 64c2, guest PC 0x0c0a2b24 */
if(!s->budget--) { s->failed_pc=0x0c0a2b24u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a2b26;
P_0c0a2b26: /* original 66b3, guest PC 0x0c0a2b26 */
if(!s->budget--) { s->failed_pc=0x0c0a2b26u; return 0; }
r[6]=r[11];
goto P_0c0a2b28;
P_0c0a2b28: /* original d317, guest PC 0x0c0a2b28 */
if(!s->budget--) { s->failed_pc=0x0c0a2b28u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2b2a;
P_0c0a2b2a: /* original 65d3, guest PC 0x0c0a2b2a */
if(!s->budget--) { s->failed_pc=0x0c0a2b2au; return 0; }
r[5]=r[13];
goto P_0c0a2b2c;
P_0c0a2b2c: /* original 430b, guest PC 0x0c0a2b2c */
if(!s->budget--) { s->failed_pc=0x0c0a2b2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2b30u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b30u) { target=s->pc; goto dispatch; }
goto P_0c0a2b30;
P_0c0a2b2e: /* original 5441, guest PC 0x0c0a2b2e */
if(!s->budget--) { s->failed_pc=0x0c0a2b2eu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2b30;
P_0c0a2b30: /* original 69c2, guest PC 0x0c0a2b30 */
if(!s->budget--) { s->failed_pc=0x0c0a2b30u; return 0; }
tmp=read(ram,r[12],4);
r[9]=tmp;
goto P_0c0a2b32;
P_0c0a2b32: /* original 2008, guest PC 0x0c0a2b32 */
if(!s->budget--) { s->failed_pc=0x0c0a2b32u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2b34;
P_0c0a2b34: /* original d315, guest PC 0x0c0a2b34 */
if(!s->budget--) { s->failed_pc=0x0c0a2b34u; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2b36;
P_0c0a2b36: /* original 5591, guest PC 0x0c0a2b36 */
if(!s->budget--) { s->failed_pc=0x0c0a2b36u; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2b38;
P_0c0a2b38: /* original 5692, guest PC 0x0c0a2b38 */
if(!s->budget--) { s->failed_pc=0x0c0a2b38u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2b3a;
P_0c0a2b3a: /* original 430b, guest PC 0x0c0a2b3a */
if(!s->budget--) { s->failed_pc=0x0c0a2b3au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2b3eu;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b3eu) { target=s->pc; goto dispatch; }
goto P_0c0a2b3e;
P_0c0a2b3c: /* original 6492, guest PC 0x0c0a2b3c */
if(!s->budget--) { s->failed_pc=0x0c0a2b3cu; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2b3e;
P_0c0a2b3e: /* original 7801, guest PC 0x0c0a2b3e */
if(!s->budget--) { s->failed_pc=0x0c0a2b3eu; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2b40;
P_0c0a2b40: /* original 85e6, guest PC 0x0c0a2b40 */
if(!s->budget--) { s->failed_pc=0x0c0a2b40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2b42;
P_0c0a2b42: /* original 600d, guest PC 0x0c0a2b42 */
if(!s->budget--) { s->failed_pc=0x0c0a2b42u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2b44;
P_0c0a2b44: /* original 3803, guest PC 0x0c0a2b44 */
if(!s->budget--) { s->failed_pc=0x0c0a2b44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2b46;
P_0c0a2b46: /* original 8bc2, guest PC 0x0c0a2b46 */
if(!s->budget--) { s->failed_pc=0x0c0a2b46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2ace; }
goto P_0c0a2b48;
P_0c0a2b48: /* original d211, guest PC 0x0c0a2b48 */
if(!s->budget--) { s->failed_pc=0x0c0a2b48u; return 0; }
r[2]=read(ram,0x0c0a2b90u,4);
goto P_0c0a2b4a;
P_0c0a2b4a: /* original 420b, guest PC 0x0c0a2b4a */
if(!s->budget--) { s->failed_pc=0x0c0a2b4au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b4eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b4eu) { target=s->pc; goto dispatch; }
goto P_0c0a2b4e;
P_0c0a2b4c: /* original e400, guest PC 0x0c0a2b4c */
if(!s->budget--) { s->failed_pc=0x0c0a2b4cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a2b4e;
P_0c0a2b4e: /* original 63f1, guest PC 0x0c0a2b4e */
if(!s->budget--) { s->failed_pc=0x0c0a2b4eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2b50;
P_0c0a2b50: /* original e222, guest PC 0x0c0a2b50 */
if(!s->budget--) { s->failed_pc=0x0c0a2b50u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2b52;
P_0c0a2b52: /* original 85e7, guest PC 0x0c0a2b52 */
if(!s->budget--) { s->failed_pc=0x0c0a2b52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2b54;
P_0c0a2b54: /* original 32ec, guest PC 0x0c0a2b54 */
if(!s->budget--) { s->failed_pc=0x0c0a2b54u; return 0; }
r[2]+=r[14];
goto P_0c0a2b56;
P_0c0a2b56: /* original 303c, guest PC 0x0c0a2b56 */
if(!s->budget--) { s->failed_pc=0x0c0a2b56u; return 0; }
r[0]+=r[3];
goto P_0c0a2b58;
P_0c0a2b58: /* original 2201, guest PC 0x0c0a2b58 */
if(!s->budget--) { s->failed_pc=0x0c0a2b58u; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2b5a;
P_0c0a2b5a: /* original a004, guest PC 0x0c0a2b5a */
if(!s->budget--) { s->failed_pc=0x0c0a2b5au; return 0; }
r[13]=0x00000000u;
goto P_0c0a2b66;
P_0c0a2b5c: /* original ed00, guest PC 0x0c0a2b5c */
if(!s->budget--) { s->failed_pc=0x0c0a2b5cu; return 0; }
r[13]=0x00000000u;
goto P_0c0a2b5e;
P_0c0a2b5e: /* original d20d, guest PC 0x0c0a2b5e */
if(!s->budget--) { s->failed_pc=0x0c0a2b5eu; return 0; }
r[2]=read(ram,0x0c0a2b94u,4);
goto P_0c0a2b60;
P_0c0a2b60: /* original e57e, guest PC 0x0c0a2b60 */
if(!s->budget--) { s->failed_pc=0x0c0a2b60u; return 0; }
r[5]=0x0000007eu;
goto P_0c0a2b62;
P_0c0a2b62: /* original 420b, guest PC 0x0c0a2b62 */
if(!s->budget--) { s->failed_pc=0x0c0a2b62u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b66u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b66u) { target=s->pc; goto dispatch; }
goto P_0c0a2b66;
P_0c0a2b64: /* original e401, guest PC 0x0c0a2b64 */
if(!s->budget--) { s->failed_pc=0x0c0a2b64u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2b66;
P_0c0a2b66: /* original 7f0c, guest PC 0x0c0a2b66 */
if(!s->budget--) { s->failed_pc=0x0c0a2b66u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2b68;
P_0c0a2b68: /* original 60d3, guest PC 0x0c0a2b68 */
if(!s->budget--) { s->failed_pc=0x0c0a2b68u; return 0; }
r[0]=r[13];
goto P_0c0a2b6a;
P_0c0a2b6a: /* original 4f26, guest PC 0x0c0a2b6a */
if(!s->budget--) { s->failed_pc=0x0c0a2b6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2b6c;
P_0c0a2b6c: /* original 68f6, guest PC 0x0c0a2b6c */
if(!s->budget--) { s->failed_pc=0x0c0a2b6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2b6e;
P_0c0a2b6e: /* original 69f6, guest PC 0x0c0a2b6e */
if(!s->budget--) { s->failed_pc=0x0c0a2b6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2b70;
P_0c0a2b70: /* original 6af6, guest PC 0x0c0a2b70 */
if(!s->budget--) { s->failed_pc=0x0c0a2b70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2b72;
P_0c0a2b72: /* original 6bf6, guest PC 0x0c0a2b72 */
if(!s->budget--) { s->failed_pc=0x0c0a2b72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2b74;
P_0c0a2b74: /* original 6cf6, guest PC 0x0c0a2b74 */
if(!s->budget--) { s->failed_pc=0x0c0a2b74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2b76;
P_0c0a2b76: /* original 6df6, guest PC 0x0c0a2b76 */
if(!s->budget--) { s->failed_pc=0x0c0a2b76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2b78;
P_0c0a2b78: /* original 000b, guest PC 0x0c0a2b78 */
if(!s->budget--) { s->failed_pc=0x0c0a2b78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2b7a: /* original 6ef6, guest PC 0x0c0a2b7a */
if(!s->budget--) { s->failed_pc=0x0c0a2b7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2b7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2b7cu; return 0; } return 1;
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
return vf3_matrix_family(0x0c0a2c36u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
