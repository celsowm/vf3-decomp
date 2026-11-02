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
int vf3_away_batch129_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c042a40u: goto P_0c042a40;
case 0x0c042a42u: goto P_0c042a42;
case 0x0c042a44u: goto P_0c042a44;
case 0x0c042a46u: goto P_0c042a46;
case 0x0c042a48u: goto P_0c042a48;
case 0x0c042a4au: goto P_0c042a4a;
case 0x0c042a4cu: goto P_0c042a4c;
case 0x0c042a4eu: goto P_0c042a4e;
case 0x0c042a50u: goto P_0c042a50;
case 0x0c042a52u: goto P_0c042a52;
case 0x0c042a54u: goto P_0c042a54;
case 0x0c042a56u: goto P_0c042a56;
case 0x0c042a58u: goto P_0c042a58;
case 0x0c042a5au: goto P_0c042a5a;
case 0x0c042a5cu: goto P_0c042a5c;
case 0x0c042a5eu: goto P_0c042a5e;
case 0x0c042a60u: goto P_0c042a60;
case 0x0c042a62u: goto P_0c042a62;
case 0x0c042a64u: goto P_0c042a64;
case 0x0c042a66u: goto P_0c042a66;
case 0x0c042a68u: goto P_0c042a68;
case 0x0c042a6au: goto P_0c042a6a;
case 0x0c042a6cu: goto P_0c042a6c;
case 0x0c042a6eu: goto P_0c042a6e;
case 0x0c042a70u: goto P_0c042a70;
case 0x0c042a72u: goto P_0c042a72;
case 0x0c042a74u: goto P_0c042a74;
case 0x0c042a76u: goto P_0c042a76;
case 0x0c042a78u: goto P_0c042a78;
case 0x0c042a7au: goto P_0c042a7a;
case 0x0c042a7cu: goto P_0c042a7c;
case 0x0c042a7eu: goto P_0c042a7e;
case 0x0c042aa0u: goto P_0c042aa0;
case 0x0c042aa2u: goto P_0c042aa2;
case 0x0c042aa4u: goto P_0c042aa4;
case 0x0c042aa6u: goto P_0c042aa6;
case 0x0c042aa8u: goto P_0c042aa8;
case 0x0c042aaau: goto P_0c042aaa;
case 0x0c042aacu: goto P_0c042aac;
case 0x0c042aaeu: goto P_0c042aae;
case 0x0c042ab0u: goto P_0c042ab0;
case 0x0c042ab2u: goto P_0c042ab2;
case 0x0c042ab4u: goto P_0c042ab4;
case 0x0c042ab6u: goto P_0c042ab6;
case 0x0c042ab8u: goto P_0c042ab8;
case 0x0c042abau: goto P_0c042aba;
case 0x0c042abcu: goto P_0c042abc;
case 0x0c042abeu: goto P_0c042abe;
case 0x0c042ac0u: goto P_0c042ac0;
case 0x0c042ac2u: goto P_0c042ac2;
case 0x0c042ac4u: goto P_0c042ac4;
case 0x0c042ad0u: goto P_0c042ad0;
case 0x0c042ad2u: goto P_0c042ad2;
case 0x0c042ad4u: goto P_0c042ad4;
case 0x0c042ad6u: goto P_0c042ad6;
case 0x0c042ad8u: goto P_0c042ad8;
case 0x0c042adau: goto P_0c042ada;
case 0x0c042ae0u: goto P_0c042ae0;
case 0x0c042ae2u: goto P_0c042ae2;
case 0x0c042ae4u: goto P_0c042ae4;
case 0x0c042ae6u: goto P_0c042ae6;
case 0x0c042ae8u: goto P_0c042ae8;
case 0x0c042aeau: goto P_0c042aea;
case 0x0c042aecu: goto P_0c042aec;
case 0x0c042aeeu: goto P_0c042aee;
case 0x0c042af0u: goto P_0c042af0;
case 0x0c042af2u: goto P_0c042af2;
case 0x0c042af4u: goto P_0c042af4;
case 0x0c042af6u: goto P_0c042af6;
case 0x0c042af8u: goto P_0c042af8;
case 0x0c042afau: goto P_0c042afa;
case 0x0c042afcu: goto P_0c042afc;
case 0x0c042afeu: goto P_0c042afe;
case 0x0c042b00u: goto P_0c042b00;
case 0x0c042b02u: goto P_0c042b02;
case 0x0c042b04u: goto P_0c042b04;
case 0x0c042b06u: goto P_0c042b06;
case 0x0c042b10u: goto P_0c042b10;
case 0x0c042b12u: goto P_0c042b12;
case 0x0c042b14u: goto P_0c042b14;
case 0x0c042b16u: goto P_0c042b16;
case 0x0c042b18u: goto P_0c042b18;
case 0x0c042b1au: goto P_0c042b1a;
case 0x0c042b1cu: goto P_0c042b1c;
case 0x0c042b1eu: goto P_0c042b1e;
case 0x0c042b20u: goto P_0c042b20;
case 0x0c042b22u: goto P_0c042b22;
case 0x0c042b24u: goto P_0c042b24;
case 0x0c042b26u: goto P_0c042b26;
case 0x0c042b30u: goto P_0c042b30;
case 0x0c042b32u: goto P_0c042b32;
case 0x0c042b34u: goto P_0c042b34;
case 0x0c042b36u: goto P_0c042b36;
case 0x0c042b38u: goto P_0c042b38;
case 0x0c042b3au: goto P_0c042b3a;
case 0x0c042b40u: goto P_0c042b40;
case 0x0c042b42u: goto P_0c042b42;
case 0x0c042b44u: goto P_0c042b44;
case 0x0c042b46u: goto P_0c042b46;
case 0x0c042b48u: goto P_0c042b48;
case 0x0c042b4au: goto P_0c042b4a;
case 0x0c042b4cu: goto P_0c042b4c;
case 0x0c042b4eu: goto P_0c042b4e;
case 0x0c042b50u: goto P_0c042b50;
case 0x0c042b52u: goto P_0c042b52;
case 0x0c042b54u: goto P_0c042b54;
case 0x0c042b56u: goto P_0c042b56;
case 0x0c042b58u: goto P_0c042b58;
case 0x0c042b5au: goto P_0c042b5a;
case 0x0c042b5cu: goto P_0c042b5c;
case 0x0c042b5eu: goto P_0c042b5e;
case 0x0c042b60u: goto P_0c042b60;
case 0x0c042b62u: goto P_0c042b62;
case 0x0c042b64u: goto P_0c042b64;
case 0x0c042b70u: goto P_0c042b70;
case 0x0c042b72u: goto P_0c042b72;
case 0x0c042b74u: goto P_0c042b74;
case 0x0c042b76u: goto P_0c042b76;
case 0x0c042b78u: goto P_0c042b78;
case 0x0c042b7au: goto P_0c042b7a;
case 0x0c042b7cu: goto P_0c042b7c;
case 0x0c042b7eu: goto P_0c042b7e;
case 0x0c042b80u: goto P_0c042b80;
case 0x0c042b82u: goto P_0c042b82;
case 0x0c042b84u: goto P_0c042b84;
case 0x0c042b86u: goto P_0c042b86;
case 0x0c042b88u: goto P_0c042b88;
case 0x0c042b8au: goto P_0c042b8a;
case 0x0c042b8cu: goto P_0c042b8c;
case 0x0c042bb0u: goto P_0c042bb0;
case 0x0c042bb2u: goto P_0c042bb2;
case 0x0c042bb4u: goto P_0c042bb4;
case 0x0c042bb6u: goto P_0c042bb6;
case 0x0c042bb8u: goto P_0c042bb8;
case 0x0c042bbau: goto P_0c042bba;
case 0x0c042bbcu: goto P_0c042bbc;
case 0x0c042bbeu: goto P_0c042bbe;
case 0x0c042bc0u: goto P_0c042bc0;
case 0x0c042bc2u: goto P_0c042bc2;
case 0x0c042bc4u: goto P_0c042bc4;
case 0x0c042bc6u: goto P_0c042bc6;
case 0x0c042bc8u: goto P_0c042bc8;
case 0x0c042bcau: goto P_0c042bca;
case 0x0c042bccu: goto P_0c042bcc;
case 0x0c042bceu: goto P_0c042bce;
case 0x0c042bd0u: goto P_0c042bd0;
case 0x0c042be0u: goto P_0c042be0;
case 0x0c042be2u: goto P_0c042be2;
case 0x0c042be4u: goto P_0c042be4;
case 0x0c042be6u: goto P_0c042be6;
case 0x0c042be8u: goto P_0c042be8;
case 0x0c042beau: goto P_0c042bea;
case 0x0c042becu: goto P_0c042bec;
case 0x0c042beeu: goto P_0c042bee;
case 0x0c042bf0u: goto P_0c042bf0;
case 0x0c042bf2u: goto P_0c042bf2;
case 0x0c042bf4u: goto P_0c042bf4;
case 0x0c042bf6u: goto P_0c042bf6;
case 0x0c042bf8u: goto P_0c042bf8;
case 0x0c042bfau: goto P_0c042bfa;
case 0x0c042c00u: goto P_0c042c00;
case 0x0c042c02u: goto P_0c042c02;
case 0x0c042c04u: goto P_0c042c04;
case 0x0c042c1eu: goto P_0c042c1e;
case 0x0c042c20u: goto P_0c042c20;
case 0x0c042c22u: goto P_0c042c22;
case 0x0c042c24u: goto P_0c042c24;
case 0x0c042c26u: goto P_0c042c26;
case 0x0c042c28u: goto P_0c042c28;
case 0x0c042c2au: goto P_0c042c2a;
case 0x0c042c2cu: goto P_0c042c2c;
case 0x0c042c2eu: goto P_0c042c2e;
case 0x0c042c30u: goto P_0c042c30;
case 0x0c042c32u: goto P_0c042c32;
case 0x0c042c34u: goto P_0c042c34;
case 0x0c042c36u: goto P_0c042c36;
case 0x0c042c38u: goto P_0c042c38;
case 0x0c042c3au: goto P_0c042c3a;
case 0x0c042c3cu: goto P_0c042c3c;
case 0x0c042c3eu: goto P_0c042c3e;
case 0x0c042c40u: goto P_0c042c40;
case 0x0c042c42u: goto P_0c042c42;
case 0x0c042c44u: goto P_0c042c44;
case 0x0c042c46u: goto P_0c042c46;
case 0x0c042c48u: goto P_0c042c48;
case 0x0c042c4au: goto P_0c042c4a;
case 0x0c042c4cu: goto P_0c042c4c;
case 0x0c042c4eu: goto P_0c042c4e;
case 0x0c042c50u: goto P_0c042c50;
case 0x0c042c52u: goto P_0c042c52;
case 0x0c042c54u: goto P_0c042c54;
case 0x0c042c56u: goto P_0c042c56;
case 0x0c042c58u: goto P_0c042c58;
case 0x0c042c5au: goto P_0c042c5a;
case 0x0c042c5cu: goto P_0c042c5c;
case 0x0c042c5eu: goto P_0c042c5e;
case 0x0c042c60u: goto P_0c042c60;
case 0x0c042c62u: goto P_0c042c62;
case 0x0c042c64u: goto P_0c042c64;
case 0x0c042c66u: goto P_0c042c66;
case 0x0c042c68u: goto P_0c042c68;
case 0x0c042c6au: goto P_0c042c6a;
case 0x0c042c6cu: goto P_0c042c6c;
case 0x0c042c6eu: goto P_0c042c6e;
case 0x0c042c70u: goto P_0c042c70;
case 0x0c042c72u: goto P_0c042c72;
case 0x0c042c74u: goto P_0c042c74;
case 0x0c042c76u: goto P_0c042c76;
case 0x0c042c78u: goto P_0c042c78;
case 0x0c042c7au: goto P_0c042c7a;
case 0x0c042c7cu: goto P_0c042c7c;
case 0x0c042c7eu: goto P_0c042c7e;
case 0x0c042c80u: goto P_0c042c80;
case 0x0c042c82u: goto P_0c042c82;
case 0x0c042c84u: goto P_0c042c84;
case 0x0c042c86u: goto P_0c042c86;
case 0x0c042c88u: goto P_0c042c88;
case 0x0c042c8au: goto P_0c042c8a;
case 0x0c042c8cu: goto P_0c042c8c;
case 0x0c042c8eu: goto P_0c042c8e;
case 0x0c042c90u: goto P_0c042c90;
case 0x0c042c92u: goto P_0c042c92;
case 0x0c042c94u: goto P_0c042c94;
case 0x0c042c96u: goto P_0c042c96;
case 0x0c042c98u: goto P_0c042c98;
case 0x0c042c9au: goto P_0c042c9a;
case 0x0c042c9cu: goto P_0c042c9c;
case 0x0c042c9eu: goto P_0c042c9e;
case 0x0c042ca0u: goto P_0c042ca0;
case 0x0c042ca2u: goto P_0c042ca2;
case 0x0c042ca4u: goto P_0c042ca4;
case 0x0c042ca6u: goto P_0c042ca6;
case 0x0c042ca8u: goto P_0c042ca8;
case 0x0c042caau: goto P_0c042caa;
case 0x0c042cacu: goto P_0c042cac;
case 0x0c042caeu: goto P_0c042cae;
case 0x0c042cb0u: goto P_0c042cb0;
case 0x0c042cb2u: goto P_0c042cb2;
case 0x0c042cb4u: goto P_0c042cb4;
case 0x0c042cb6u: goto P_0c042cb6;
case 0x0c042cb8u: goto P_0c042cb8;
case 0x0c042cbau: goto P_0c042cba;
case 0x0c042cbcu: goto P_0c042cbc;
case 0x0c042cbeu: goto P_0c042cbe;
default: return vf3_matrix_family(target,s,ram);
}
P_0c042a40: /* original 2fe6, guest PC 0x0c042a40 */
if(!s->budget--) { s->failed_pc=0x0c042a40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042a42;
P_0c042a42: /* original 2fd6, guest PC 0x0c042a42 */
if(!s->budget--) { s->failed_pc=0x0c042a42u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042a44;
P_0c042a44: /* original 2fc6, guest PC 0x0c042a44 */
if(!s->budget--) { s->failed_pc=0x0c042a44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042a46;
P_0c042a46: /* original dd10, guest PC 0x0c042a46 */
if(!s->budget--) { s->failed_pc=0x0c042a46u; return 0; }
r[13]=read(ram,0x0c042a88u,4);
goto P_0c042a48;
P_0c042a48: /* original 4f22, guest PC 0x0c042a48 */
if(!s->budget--) { s->failed_pc=0x0c042a48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042a4a;
P_0c042a4a: /* original 6ed2, guest PC 0x0c042a4a */
if(!s->budget--) { s->failed_pc=0x0c042a4au; return 0; }
tmp=read(ram,r[13],4);
r[14]=tmp;
goto P_0c042a4c;
P_0c042a4c: /* original 2ee8, guest PC 0x0c042a4c */
if(!s->budget--) { s->failed_pc=0x0c042a4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c042a4e;
P_0c042a4e: /* original 893f, guest PC 0x0c042a4e */
if(!s->budget--) { s->failed_pc=0x0c042a4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042ad0; }
goto P_0c042a50;
P_0c042a50: /* original e202, guest PC 0x0c042a50 */
if(!s->budget--) { s->failed_pc=0x0c042a50u; return 0; }
r[2]=0x00000002u;
goto P_0c042a52;
P_0c042a52: /* original 6c4e, guest PC 0x0c042a52 */
if(!s->budget--) { s->failed_pc=0x0c042a52u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c042a54;
P_0c042a54: /* original 22c8, guest PC 0x0c042a54 */
if(!s->budget--) { s->failed_pc=0x0c042a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c042a56;
P_0c042a56: /* original 8903, guest PC 0x0c042a56 */
if(!s->budget--) { s->failed_pc=0x0c042a56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a60; }
goto P_0c042a58;
P_0c042a58: /* original d20c, guest PC 0x0c042a58 */
if(!s->budget--) { s->failed_pc=0x0c042a58u; return 0; }
r[2]=read(ram,0x0c042a8cu,4);
goto P_0c042a5a;
P_0c042a5a: /* original e540, guest PC 0x0c042a5a */
if(!s->budget--) { s->failed_pc=0x0c042a5au; return 0; }
r[5]=0x00000040u;
goto P_0c042a5c;
P_0c042a5c: /* original 420b, guest PC 0x0c042a5c */
if(!s->budget--) { s->failed_pc=0x0c042a5cu; return 0; }
target=r[2];
r[16]=code_base|0x0c042a60u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042a60u) { target=s->pc; goto dispatch; }
goto P_0c042a60;
P_0c042a5e: /* original 64e3, guest PC 0x0c042a5e */
if(!s->budget--) { s->failed_pc=0x0c042a5eu; return 0; }
r[4]=r[14];
goto P_0c042a60;
P_0c042a60: /* original e301, guest PC 0x0c042a60 */
if(!s->budget--) { s->failed_pc=0x0c042a60u; return 0; }
r[3]=0x00000001u;
goto P_0c042a62;
P_0c042a62: /* original 2c38, guest PC 0x0c042a62 */
if(!s->budget--) { s->failed_pc=0x0c042a62u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c042a64;
P_0c042a64: /* original 8905, guest PC 0x0c042a64 */
if(!s->budget--) { s->failed_pc=0x0c042a64u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042a72; }
goto P_0c042a66;
P_0c042a66: /* original 950e, guest PC 0x0c042a66 */
if(!s->budget--) { s->failed_pc=0x0c042a66u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042a86u,2);
goto P_0c042a68;
P_0c042a68: /* original 64d2, guest PC 0x0c042a68 */
if(!s->budget--) { s->failed_pc=0x0c042a68u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c042a6a;
P_0c042a6a: /* original d108, guest PC 0x0c042a6a */
if(!s->budget--) { s->failed_pc=0x0c042a6au; return 0; }
r[1]=read(ram,0x0c042a8cu,4);
goto P_0c042a6c;
P_0c042a6c: /* original 6253, guest PC 0x0c042a6c */
if(!s->budget--) { s->failed_pc=0x0c042a6cu; return 0; }
r[2]=r[5];
goto P_0c042a6e;
P_0c042a6e: /* original 410b, guest PC 0x0c042a6e */
if(!s->budget--) { s->failed_pc=0x0c042a6eu; return 0; }
target=r[1];
r[16]=code_base|0x0c042a72u;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042a72u) { target=s->pc; goto dispatch; }
goto P_0c042a72;
P_0c042a70: /* original 342c, guest PC 0x0c042a70 */
if(!s->budget--) { s->failed_pc=0x0c042a70u; return 0; }
r[4]+=r[2];
goto P_0c042a72;
P_0c042a72: /* original de07, guest PC 0x0c042a72 */
if(!s->budget--) { s->failed_pc=0x0c042a72u; return 0; }
r[14]=read(ram,0x0c042a90u,4);
goto P_0c042a74;
P_0c042a74: /* original 60e0, guest PC 0x0c042a74 */
if(!s->budget--) { s->failed_pc=0x0c042a74u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[0]=tmp;
goto P_0c042a76;
P_0c042a76: /* original 8802, guest PC 0x0c042a76 */
if(!s->budget--) { s->failed_pc=0x0c042a76u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c042a78;
P_0c042a78: /* original 8f12, guest PC 0x0c042a78 */
if(!s->budget--) { s->failed_pc=0x0c042a78u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c042aa0; }
goto P_0c042a7c;
P_0c042a7a: /* original 6403, guest PC 0x0c042a7a */
if(!s->budget--) { s->failed_pc=0x0c042a7au; return 0; }
r[4]=r[0];
goto P_0c042a7c;
P_0c042a7c: /* original a012, guest PC 0x0c042a7c */
if(!s->budget--) { s->failed_pc=0x0c042a7cu; return 0; }
r[3]=0x00000000u;
goto P_0c042aa4;
P_0c042a7e: /* original e300, guest PC 0x0c042a7e */
if(!s->budget--) { s->failed_pc=0x0c042a7eu; return 0; }
r[3]=0x00000000u;
if(!vf3_matrix_family(0x0c042a80u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042a80u; return 0; } return 1;
P_0c042aa0: /* original 6343, guest PC 0x0c042aa0 */
if(!s->budget--) { s->failed_pc=0x0c042aa0u; return 0; }
r[3]=r[4];
goto P_0c042aa2;
P_0c042aa2: /* original 7301, guest PC 0x0c042aa2 */
if(!s->budget--) { s->failed_pc=0x0c042aa2u; return 0; }
r[3]+=0x00000001u;
goto P_0c042aa4;
P_0c042aa4: /* original 2e30, guest PC 0x0c042aa4 */
if(!s->budget--) { s->failed_pc=0x0c042aa4u; return 0; }
write(ram,r[14],r[3],1);
goto P_0c042aa6;
P_0c042aa6: /* original e700, guest PC 0x0c042aa6 */
if(!s->budget--) { s->failed_pc=0x0c042aa6u; return 0; }
r[7]=0x00000000u;
goto P_0c042aa8;
P_0c042aa8: /* original 64e0, guest PC 0x0c042aa8 */
if(!s->budget--) { s->failed_pc=0x0c042aa8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[4]=tmp;
goto P_0c042aaa;
P_0c042aaa: /* original 6673, guest PC 0x0c042aaa */
if(!s->budget--) { s->failed_pc=0x0c042aaau; return 0; }
r[6]=r[7];
goto P_0c042aac;
P_0c042aac: /* original d23b, guest PC 0x0c042aac */
if(!s->budget--) { s->failed_pc=0x0c042aacu; return 0; }
r[2]=read(ram,0x0c042b9cu,4);
goto P_0c042aae;
P_0c042aae: /* original 6343, guest PC 0x0c042aae */
if(!s->budget--) { s->failed_pc=0x0c042aaeu; return 0; }
r[3]=r[4];
goto P_0c042ab0;
P_0c042ab0: /* original 4408, guest PC 0x0c042ab0 */
if(!s->budget--) { s->failed_pc=0x0c042ab0u; return 0; }
r[4]<<=2;
goto P_0c042ab2;
P_0c042ab2: /* original 343c, guest PC 0x0c042ab2 */
if(!s->budget--) { s->failed_pc=0x0c042ab2u; return 0; }
r[4]+=r[3];
goto P_0c042ab4;
P_0c042ab4: /* original d33a, guest PC 0x0c042ab4 */
if(!s->budget--) { s->failed_pc=0x0c042ab4u; return 0; }
r[3]=read(ram,0x0c042ba0u,4);
goto P_0c042ab6;
P_0c042ab6: /* original 4408, guest PC 0x0c042ab6 */
if(!s->budget--) { s->failed_pc=0x0c042ab6u; return 0; }
r[4]<<=2;
goto P_0c042ab8;
P_0c042ab8: /* original 65d2, guest PC 0x0c042ab8 */
if(!s->budget--) { s->failed_pc=0x0c042ab8u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c042aba;
P_0c042aba: /* original 4400, guest PC 0x0c042aba */
if(!s->budget--) { s->failed_pc=0x0c042abau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c042abc;
P_0c042abc: /* original 644e, guest PC 0x0c042abc */
if(!s->budget--) { s->failed_pc=0x0c042abcu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c042abe;
P_0c042abe: /* original 430b, guest PC 0x0c042abe */
if(!s->budget--) { s->failed_pc=0x0c042abeu; return 0; }
target=r[3];
r[16]=code_base|0x0c042ac2u;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c042ac2u) { target=s->pc; goto dispatch; }
goto P_0c042ac2;
P_0c042ac0: /* original 342c, guest PC 0x0c042ac0 */
if(!s->budget--) { s->failed_pc=0x0c042ac0u; return 0; }
r[4]+=r[2];
goto P_0c042ac2;
P_0c042ac2: /* original a006, guest PC 0x0c042ac2 */
if(!s->budget--) { s->failed_pc=0x0c042ac2u; return 0; }
goto P_0c042ad2;
P_0c042ac4: /* original 0009, guest PC 0x0c042ac4 */
if(!s->budget--) { s->failed_pc=0x0c042ac4u; return 0; }
if(!vf3_matrix_family(0x0c042ac6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042ac6u; return 0; } return 1;
P_0c042ad0: /* original e000, guest PC 0x0c042ad0 */
if(!s->budget--) { s->failed_pc=0x0c042ad0u; return 0; }
r[0]=0x00000000u;
goto P_0c042ad2;
P_0c042ad2: /* original 4f26, guest PC 0x0c042ad2 */
if(!s->budget--) { s->failed_pc=0x0c042ad2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c042ad4;
P_0c042ad4: /* original 6cf6, guest PC 0x0c042ad4 */
if(!s->budget--) { s->failed_pc=0x0c042ad4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c042ad6;
P_0c042ad6: /* original 6df6, guest PC 0x0c042ad6 */
if(!s->budget--) { s->failed_pc=0x0c042ad6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c042ad8;
P_0c042ad8: /* original 000b, guest PC 0x0c042ad8 */
if(!s->budget--) { s->failed_pc=0x0c042ad8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c042ada: /* original 6ef6, guest PC 0x0c042ada */
if(!s->budget--) { s->failed_pc=0x0c042adau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c042adcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042adcu; return 0; } return 1;
P_0c042ae0: /* original e620, guest PC 0x0c042ae0 */
if(!s->budget--) { s->failed_pc=0x0c042ae0u; return 0; }
r[6]=0x00000020u;
goto P_0c042ae2;
P_0c042ae2: /* original 3467, guest PC 0x0c042ae2 */
if(!s->budget--) { s->failed_pc=0x0c042ae2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[6])!=0);
goto P_0c042ae4;
P_0c042ae4: /* original 8b27, guest PC 0x0c042ae4 */
if(!s->budget--) { s->failed_pc=0x0c042ae4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b36; }
goto P_0c042ae6;
P_0c042ae6: /* original 6043, guest PC 0x0c042ae6 */
if(!s->budget--) { s->failed_pc=0x0c042ae6u; return 0; }
r[0]=r[4];
goto P_0c042ae8;
P_0c042ae8: /* original 0009, guest PC 0x0c042ae8 */
if(!s->budget--) { s->failed_pc=0x0c042ae8u; return 0; }
goto P_0c042aea;
P_0c042aea: /* original 887f, guest PC 0x0c042aea */
if(!s->budget--) { s->failed_pc=0x0c042aeau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007fu)!=0);
goto P_0c042aec;
P_0c042aec: /* original 8923, guest PC 0x0c042aec */
if(!s->budget--) { s->failed_pc=0x0c042aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b36; }
goto P_0c042aee;
P_0c042aee: /* original d52d, guest PC 0x0c042aee */
if(!s->budget--) { s->failed_pc=0x0c042aeeu; return 0; }
r[5]=read(ram,0x0c042ba4u,4);
goto P_0c042af0;
P_0c042af0: /* original e77f, guest PC 0x0c042af0 */
if(!s->budget--) { s->failed_pc=0x0c042af0u; return 0; }
r[7]=0x0000007fu;
goto P_0c042af2;
P_0c042af2: /* original 3473, guest PC 0x0c042af2 */
if(!s->budget--) { s->failed_pc=0x0c042af2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[7])!=0);
goto P_0c042af4;
P_0c042af4: /* original 891c, guest PC 0x0c042af4 */
if(!s->budget--) { s->failed_pc=0x0c042af4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b30; }
goto P_0c042af6;
P_0c042af6: /* original 6350, guest PC 0x0c042af6 */
if(!s->budget--) { s->failed_pc=0x0c042af6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c042af8;
P_0c042af8: /* original 2338, guest PC 0x0c042af8 */
if(!s->budget--) { s->failed_pc=0x0c042af8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c042afa;
P_0c042afa: /* original 890c, guest PC 0x0c042afa */
if(!s->budget--) { s->failed_pc=0x0c042afau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b16; }
goto P_0c042afc;
P_0c042afc: /* original 6043, guest PC 0x0c042afc */
if(!s->budget--) { s->failed_pc=0x0c042afcu; return 0; }
r[0]=r[4];
goto P_0c042afe;
P_0c042afe: /* original 0009, guest PC 0x0c042afe */
if(!s->budget--) { s->failed_pc=0x0c042afeu; return 0; }
goto P_0c042b00;
P_0c042b00: /* original 885c, guest PC 0x0c042b00 */
if(!s->budget--) { s->failed_pc=0x0c042b00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005cu)!=0);
goto P_0c042b02;
P_0c042b02: /* original 8b05, guest PC 0x0c042b02 */
if(!s->budget--) { s->failed_pc=0x0c042b02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b10; }
goto P_0c042b04;
P_0c042b04: /* original a007, guest PC 0x0c042b04 */
if(!s->budget--) { s->failed_pc=0x0c042b04u; return 0; }
r[4]=r[7];
goto P_0c042b16;
P_0c042b06: /* original 6473, guest PC 0x0c042b06 */
if(!s->budget--) { s->failed_pc=0x0c042b06u; return 0; }
r[4]=r[7];
if(!vf3_matrix_family(0x0c042b08u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b08u; return 0; } return 1;
P_0c042b10: /* original 887e, guest PC 0x0c042b10 */
if(!s->budget--) { s->failed_pc=0x0c042b10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000007eu)!=0);
goto P_0c042b12;
P_0c042b12: /* original 8b00, guest PC 0x0c042b12 */
if(!s->budget--) { s->failed_pc=0x0c042b12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042b16; }
goto P_0c042b14;
P_0c042b14: /* original 6463, guest PC 0x0c042b14 */
if(!s->budget--) { s->failed_pc=0x0c042b14u; return 0; }
r[4]=r[6];
goto P_0c042b16;
P_0c042b16: /* original 6043, guest PC 0x0c042b16 */
if(!s->budget--) { s->failed_pc=0x0c042b16u; return 0; }
r[0]=r[4];
goto P_0c042b18;
P_0c042b18: /* original 0009, guest PC 0x0c042b18 */
if(!s->budget--) { s->failed_pc=0x0c042b18u; return 0; }
goto P_0c042b1a;
P_0c042b1a: /* original 70e0, guest PC 0x0c042b1a */
if(!s->budget--) { s->failed_pc=0x0c042b1au; return 0; }
r[0]+=0xffffffe0u;
goto P_0c042b1c;
P_0c042b1c: /* original 6303, guest PC 0x0c042b1c */
if(!s->budget--) { s->failed_pc=0x0c042b1cu; return 0; }
r[3]=r[0];
goto P_0c042b1e;
P_0c042b1e: /* original 4008, guest PC 0x0c042b1e */
if(!s->budget--) { s->failed_pc=0x0c042b1eu; return 0; }
r[0]<<=2;
goto P_0c042b20;
P_0c042b20: /* original 4000, guest PC 0x0c042b20 */
if(!s->budget--) { s->failed_pc=0x0c042b20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b22;
P_0c042b22: /* original 303c, guest PC 0x0c042b22 */
if(!s->budget--) { s->failed_pc=0x0c042b22u; return 0; }
r[0]+=r[3];
goto P_0c042b24;
P_0c042b24: /* original 000b, guest PC 0x0c042b24 */
if(!s->budget--) { s->failed_pc=0x0c042b24u; return 0; }
target=r[16];
r[0]<<=2;
s->pc=target; return ram->oob==0;
P_0c042b26: /* original 4008, guest PC 0x0c042b26 */
if(!s->budget--) { s->failed_pc=0x0c042b26u; return 0; }
r[0]<<=2;
if(!vf3_matrix_family(0x0c042b28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b28u; return 0; } return 1;
P_0c042b30: /* original 922d, guest PC 0x0c042b30 */
if(!s->budget--) { s->failed_pc=0x0c042b30u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b8eu,2);
goto P_0c042b32;
P_0c042b32: /* original 3423, guest PC 0x0c042b32 */
if(!s->budget--) { s->failed_pc=0x0c042b32u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c042b34;
P_0c042b34: /* original 8904, guest PC 0x0c042b34 */
if(!s->budget--) { s->failed_pc=0x0c042b34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b40; }
goto P_0c042b36;
P_0c042b36: /* original 902b, guest PC 0x0c042b36 */
if(!s->budget--) { s->failed_pc=0x0c042b36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b90u,2);
goto P_0c042b38;
P_0c042b38: /* original 000b, guest PC 0x0c042b38 */
if(!s->budget--) { s->failed_pc=0x0c042b38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c042b3a: /* original 0009, guest PC 0x0c042b3a */
if(!s->budget--) { s->failed_pc=0x0c042b3au; return 0; }
if(!vf3_matrix_family(0x0c042b3cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b3cu; return 0; } return 1;
P_0c042b40: /* original 9627, guest PC 0x0c042b40 */
if(!s->budget--) { s->failed_pc=0x0c042b40u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b92u,2);
goto P_0c042b42;
P_0c042b42: /* original 3463, guest PC 0x0c042b42 */
if(!s->budget--) { s->failed_pc=0x0c042b42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[6])!=0);
goto P_0c042b44;
P_0c042b44: /* original 8914, guest PC 0x0c042b44 */
if(!s->budget--) { s->failed_pc=0x0c042b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042b70; }
goto P_0c042b46;
P_0c042b46: /* original 9625, guest PC 0x0c042b46 */
if(!s->budget--) { s->failed_pc=0x0c042b46u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b94u,2);
goto P_0c042b48;
P_0c042b48: /* original 6250, guest PC 0x0c042b48 */
if(!s->budget--) { s->failed_pc=0x0c042b48u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c042b4a;
P_0c042b4a: /* original 364c, guest PC 0x0c042b4a */
if(!s->budget--) { s->failed_pc=0x0c042b4au; return 0; }
r[6]+=r[4];
goto P_0c042b4c;
P_0c042b4c: /* original 6363, guest PC 0x0c042b4c */
if(!s->budget--) { s->failed_pc=0x0c042b4cu; return 0; }
r[3]=r[6];
goto P_0c042b4e;
P_0c042b4e: /* original 4608, guest PC 0x0c042b4e */
if(!s->budget--) { s->failed_pc=0x0c042b4eu; return 0; }
r[6]<<=2;
goto P_0c042b50;
P_0c042b50: /* original 4600, guest PC 0x0c042b50 */
if(!s->budget--) { s->failed_pc=0x0c042b50u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c042b52;
P_0c042b52: /* original 2228, guest PC 0x0c042b52 */
if(!s->budget--) { s->failed_pc=0x0c042b52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c042b54;
P_0c042b54: /* original 363c, guest PC 0x0c042b54 */
if(!s->budget--) { s->failed_pc=0x0c042b54u; return 0; }
r[6]+=r[3];
goto P_0c042b56;
P_0c042b56: /* original 8d03, guest PC 0x0c042b56 */
if(!s->budget--) { s->failed_pc=0x0c042b56u; return 0; }
cond=r[17]&1u;
r[6]<<=2;
if(cond) { goto P_0c042b60; }
goto P_0c042b5a;
P_0c042b58: /* original 4608, guest PC 0x0c042b58 */
if(!s->budget--) { s->failed_pc=0x0c042b58u; return 0; }
r[6]<<=2;
goto P_0c042b5a;
P_0c042b5a: /* original 901c, guest PC 0x0c042b5a */
if(!s->budget--) { s->failed_pc=0x0c042b5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b96u,2);
goto P_0c042b5c;
P_0c042b5c: /* original a001, guest PC 0x0c042b5c */
if(!s->budget--) { s->failed_pc=0x0c042b5cu; return 0; }
goto P_0c042b62;
P_0c042b5e: /* original 0009, guest PC 0x0c042b5e */
if(!s->budget--) { s->failed_pc=0x0c042b5eu; return 0; }
goto P_0c042b60;
P_0c042b60: /* original 9016, guest PC 0x0c042b60 */
if(!s->budget--) { s->failed_pc=0x0c042b60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b90u,2);
goto P_0c042b62;
P_0c042b62: /* original 000b, guest PC 0x0c042b62 */
if(!s->budget--) { s->failed_pc=0x0c042b62u; return 0; }
target=r[16];
r[0]+=r[6];
s->pc=target; return ram->oob==0;
P_0c042b64: /* original 306c, guest PC 0x0c042b64 */
if(!s->budget--) { s->failed_pc=0x0c042b64u; return 0; }
r[0]+=r[6];
if(!vf3_matrix_family(0x0c042b66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b66u; return 0; } return 1;
P_0c042b70: /* original 9212, guest PC 0x0c042b70 */
if(!s->budget--) { s->failed_pc=0x0c042b70u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b98u,2);
goto P_0c042b72;
P_0c042b72: /* original 3468, guest PC 0x0c042b72 */
if(!s->budget--) { s->failed_pc=0x0c042b72u; return 0; }
r[4]-=r[6];
goto P_0c042b74;
P_0c042b74: /* original 3423, guest PC 0x0c042b74 */
if(!s->budget--) { s->failed_pc=0x0c042b74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c042b76;
P_0c042b76: /* original 891b, guest PC 0x0c042b76 */
if(!s->budget--) { s->failed_pc=0x0c042b76u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042bb0; }
goto P_0c042b78;
P_0c042b78: /* original 6043, guest PC 0x0c042b78 */
if(!s->budget--) { s->failed_pc=0x0c042b78u; return 0; }
r[0]=r[4];
goto P_0c042b7a;
P_0c042b7a: /* original 0009, guest PC 0x0c042b7a */
if(!s->budget--) { s->failed_pc=0x0c042b7au; return 0; }
goto P_0c042b7c;
P_0c042b7c: /* original 4008, guest PC 0x0c042b7c */
if(!s->budget--) { s->failed_pc=0x0c042b7cu; return 0; }
r[0]<<=2;
goto P_0c042b7e;
P_0c042b7e: /* original 6343, guest PC 0x0c042b7e */
if(!s->budget--) { s->failed_pc=0x0c042b7eu; return 0; }
r[3]=r[4];
goto P_0c042b80;
P_0c042b80: /* original 4000, guest PC 0x0c042b80 */
if(!s->budget--) { s->failed_pc=0x0c042b80u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b82;
P_0c042b82: /* original 910a, guest PC 0x0c042b82 */
if(!s->budget--) { s->failed_pc=0x0c042b82u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042b9au,2);
goto P_0c042b84;
P_0c042b84: /* original 303c, guest PC 0x0c042b84 */
if(!s->budget--) { s->failed_pc=0x0c042b84u; return 0; }
r[0]+=r[3];
goto P_0c042b86;
P_0c042b86: /* original 4008, guest PC 0x0c042b86 */
if(!s->budget--) { s->failed_pc=0x0c042b86u; return 0; }
r[0]<<=2;
goto P_0c042b88;
P_0c042b88: /* original 4000, guest PC 0x0c042b88 */
if(!s->budget--) { s->failed_pc=0x0c042b88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042b8a;
P_0c042b8a: /* original 000b, guest PC 0x0c042b8a */
if(!s->budget--) { s->failed_pc=0x0c042b8au; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042b8c: /* original 301c, guest PC 0x0c042b8c */
if(!s->budget--) { s->failed_pc=0x0c042b8cu; return 0; }
r[0]+=r[1];
if(!vf3_matrix_family(0x0c042b8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042b8eu; return 0; } return 1;
P_0c042bb0: /* original 9329, guest PC 0x0c042bb0 */
if(!s->budget--) { s->failed_pc=0x0c042bb0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c06u,2);
goto P_0c042bb2;
P_0c042bb2: /* original 3433, guest PC 0x0c042bb2 */
if(!s->budget--) { s->failed_pc=0x0c042bb2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042bb4;
P_0c042bb4: /* original 8b24, guest PC 0x0c042bb4 */
if(!s->budget--) { s->failed_pc=0x0c042bb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c042c00; }
goto P_0c042bb6;
P_0c042bb6: /* original 9327, guest PC 0x0c042bb6 */
if(!s->budget--) { s->failed_pc=0x0c042bb6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c08u,2);
goto P_0c042bb8;
P_0c042bb8: /* original 3433, guest PC 0x0c042bb8 */
if(!s->budget--) { s->failed_pc=0x0c042bb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042bba;
P_0c042bba: /* original 8911, guest PC 0x0c042bba */
if(!s->budget--) { s->failed_pc=0x0c042bbau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042be0; }
goto P_0c042bbc;
P_0c042bbc: /* original 9025, guest PC 0x0c042bbc */
if(!s->budget--) { s->failed_pc=0x0c042bbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0au,2);
goto P_0c042bbe;
P_0c042bbe: /* original d115, guest PC 0x0c042bbe */
if(!s->budget--) { s->failed_pc=0x0c042bbeu; return 0; }
r[1]=read(ram,0x0c042c14u,4);
goto P_0c042bc0;
P_0c042bc0: /* original 304c, guest PC 0x0c042bc0 */
if(!s->budget--) { s->failed_pc=0x0c042bc0u; return 0; }
r[0]+=r[4];
goto P_0c042bc2;
P_0c042bc2: /* original 6203, guest PC 0x0c042bc2 */
if(!s->budget--) { s->failed_pc=0x0c042bc2u; return 0; }
r[2]=r[0];
goto P_0c042bc4;
P_0c042bc4: /* original 4008, guest PC 0x0c042bc4 */
if(!s->budget--) { s->failed_pc=0x0c042bc4u; return 0; }
r[0]<<=2;
goto P_0c042bc6;
P_0c042bc6: /* original 4000, guest PC 0x0c042bc6 */
if(!s->budget--) { s->failed_pc=0x0c042bc6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bc8;
P_0c042bc8: /* original 302c, guest PC 0x0c042bc8 */
if(!s->budget--) { s->failed_pc=0x0c042bc8u; return 0; }
r[0]+=r[2];
goto P_0c042bca;
P_0c042bca: /* original 4008, guest PC 0x0c042bca */
if(!s->budget--) { s->failed_pc=0x0c042bcau; return 0; }
r[0]<<=2;
goto P_0c042bcc;
P_0c042bcc: /* original 4000, guest PC 0x0c042bcc */
if(!s->budget--) { s->failed_pc=0x0c042bccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bce;
P_0c042bce: /* original 000b, guest PC 0x0c042bce */
if(!s->budget--) { s->failed_pc=0x0c042bceu; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042bd0: /* original 301c, guest PC 0x0c042bd0 */
if(!s->budget--) { s->failed_pc=0x0c042bd0u; return 0; }
r[0]+=r[1];
if(!vf3_matrix_family(0x0c042bd2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042bd2u; return 0; } return 1;
P_0c042be0: /* original 9314, guest PC 0x0c042be0 */
if(!s->budget--) { s->failed_pc=0x0c042be0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0cu,2);
goto P_0c042be2;
P_0c042be2: /* original 3433, guest PC 0x0c042be2 */
if(!s->budget--) { s->failed_pc=0x0c042be2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[3])!=0);
goto P_0c042be4;
P_0c042be4: /* original 890c, guest PC 0x0c042be4 */
if(!s->budget--) { s->failed_pc=0x0c042be4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c042c00; }
goto P_0c042be6;
P_0c042be6: /* original 9012, guest PC 0x0c042be6 */
if(!s->budget--) { s->failed_pc=0x0c042be6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c0eu,2);
goto P_0c042be8;
P_0c042be8: /* original d10b, guest PC 0x0c042be8 */
if(!s->budget--) { s->failed_pc=0x0c042be8u; return 0; }
r[1]=read(ram,0x0c042c18u,4);
goto P_0c042bea;
P_0c042bea: /* original 304c, guest PC 0x0c042bea */
if(!s->budget--) { s->failed_pc=0x0c042beau; return 0; }
r[0]+=r[4];
goto P_0c042bec;
P_0c042bec: /* original 6203, guest PC 0x0c042bec */
if(!s->budget--) { s->failed_pc=0x0c042becu; return 0; }
r[2]=r[0];
goto P_0c042bee;
P_0c042bee: /* original 4008, guest PC 0x0c042bee */
if(!s->budget--) { s->failed_pc=0x0c042beeu; return 0; }
r[0]<<=2;
goto P_0c042bf0;
P_0c042bf0: /* original 4000, guest PC 0x0c042bf0 */
if(!s->budget--) { s->failed_pc=0x0c042bf0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bf2;
P_0c042bf2: /* original 302c, guest PC 0x0c042bf2 */
if(!s->budget--) { s->failed_pc=0x0c042bf2u; return 0; }
r[0]+=r[2];
goto P_0c042bf4;
P_0c042bf4: /* original 4008, guest PC 0x0c042bf4 */
if(!s->budget--) { s->failed_pc=0x0c042bf4u; return 0; }
r[0]<<=2;
goto P_0c042bf6;
P_0c042bf6: /* original 4000, guest PC 0x0c042bf6 */
if(!s->budget--) { s->failed_pc=0x0c042bf6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c042bf8;
P_0c042bf8: /* original 000b, guest PC 0x0c042bf8 */
if(!s->budget--) { s->failed_pc=0x0c042bf8u; return 0; }
target=r[16];
r[0]+=r[1];
s->pc=target; return ram->oob==0;
P_0c042bfa: /* original 301c, guest PC 0x0c042bfa */
if(!s->budget--) { s->failed_pc=0x0c042bfau; return 0; }
r[0]+=r[1];
if(!vf3_matrix_family(0x0c042bfcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042bfcu; return 0; } return 1;
P_0c042c00: /* original 9006, guest PC 0x0c042c00 */
if(!s->budget--) { s->failed_pc=0x0c042c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c042c10u,2);
goto P_0c042c02;
P_0c042c02: /* original 000b, guest PC 0x0c042c02 */
if(!s->budget--) { s->failed_pc=0x0c042c02u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c042c04: /* original 0009, guest PC 0x0c042c04 */
if(!s->budget--) { s->failed_pc=0x0c042c04u; return 0; }
if(!vf3_matrix_family(0x0c042c06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c042c06u; return 0; } return 1;
P_0c042c1e: /* original 4f22, guest PC 0x0c042c1e */
if(!s->budget--) { s->failed_pc=0x0c042c1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c042c20;
P_0c042c20: /* original 2008, guest PC 0x0c042c20 */
if(!s->budget--) { s->failed_pc=0x0c042c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c042c22;
P_0c042c22: /* original 2f26, guest PC 0x0c042c22 */
if(!s->budget--) { s->failed_pc=0x0c042c22u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c24;
P_0c042c24: /* original 8d4c, guest PC 0x0c042c24 */
if(!s->budget--) { s->failed_pc=0x0c042c24u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c042cc0u,s,ram); }
goto P_0c042c28;
P_0c042c26: /* original 0009, guest PC 0x0c042c26 */
if(!s->budget--) { s->failed_pc=0x0c042c26u; return 0; }
goto P_0c042c28;
P_0c042c28: /* original 2f36, guest PC 0x0c042c28 */
if(!s->budget--) { s->failed_pc=0x0c042c28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c042c2a;
P_0c042c2a: /* original e200, guest PC 0x0c042c2a */
if(!s->budget--) { s->failed_pc=0x0c042c2au; return 0; }
r[2]=0x00000000u;
goto P_0c042c2c;
P_0c042c2c: /* original 2127, guest PC 0x0c042c2c */
if(!s->budget--) { s->failed_pc=0x0c042c2cu; return 0; }
r[17]=(r[17]&~0x301u)|((r[1]>>31)<<8)|((r[2]>>31)<<9)|(((r[1]^r[2])>>31)&1u);
goto P_0c042c2e;
P_0c042c2e: /* original 333a, guest PC 0x0c042c2e */
if(!s->budget--) { s->failed_pc=0x0c042c2eu; return 0; }
wide=(uint64_t)r[3]-r[3]-(r[17]&1u); r[3]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c30;
P_0c042c30: /* original 312a, guest PC 0x0c042c30 */
if(!s->budget--) { s->failed_pc=0x0c042c30u; return 0; }
wide=(uint64_t)r[1]-r[2]-(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042c32;
P_0c042c32: /* original 2307, guest PC 0x0c042c32 */
if(!s->budget--) { s->failed_pc=0x0c042c32u; return 0; }
r[17]=(r[17]&~0x301u)|((r[3]>>31)<<8)|((r[0]>>31)<<9)|(((r[3]^r[0])>>31)&1u);
goto P_0c042c34;
P_0c042c34: /* original 4124, guest PC 0x0c042c34 */
if(!s->budget--) { s->failed_pc=0x0c042c34u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c36;
P_0c042c36: /* original 3304, guest PC 0x0c042c36 */
if(!s->budget--) { s->failed_pc=0x0c042c36u; return 0; }
divide_step(s,3,0);
goto P_0c042c38;
P_0c042c38: /* original 4124, guest PC 0x0c042c38 */
if(!s->budget--) { s->failed_pc=0x0c042c38u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3a;
P_0c042c3a: /* original 3304, guest PC 0x0c042c3a */
if(!s->budget--) { s->failed_pc=0x0c042c3au; return 0; }
divide_step(s,3,0);
goto P_0c042c3c;
P_0c042c3c: /* original 4124, guest PC 0x0c042c3c */
if(!s->budget--) { s->failed_pc=0x0c042c3cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c3e;
P_0c042c3e: /* original 3304, guest PC 0x0c042c3e */
if(!s->budget--) { s->failed_pc=0x0c042c3eu; return 0; }
divide_step(s,3,0);
goto P_0c042c40;
P_0c042c40: /* original 4124, guest PC 0x0c042c40 */
if(!s->budget--) { s->failed_pc=0x0c042c40u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c42;
P_0c042c42: /* original 3304, guest PC 0x0c042c42 */
if(!s->budget--) { s->failed_pc=0x0c042c42u; return 0; }
divide_step(s,3,0);
goto P_0c042c44;
P_0c042c44: /* original 4124, guest PC 0x0c042c44 */
if(!s->budget--) { s->failed_pc=0x0c042c44u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c46;
P_0c042c46: /* original 3304, guest PC 0x0c042c46 */
if(!s->budget--) { s->failed_pc=0x0c042c46u; return 0; }
divide_step(s,3,0);
goto P_0c042c48;
P_0c042c48: /* original 4124, guest PC 0x0c042c48 */
if(!s->budget--) { s->failed_pc=0x0c042c48u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4a;
P_0c042c4a: /* original 3304, guest PC 0x0c042c4a */
if(!s->budget--) { s->failed_pc=0x0c042c4au; return 0; }
divide_step(s,3,0);
goto P_0c042c4c;
P_0c042c4c: /* original 4124, guest PC 0x0c042c4c */
if(!s->budget--) { s->failed_pc=0x0c042c4cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c4e;
P_0c042c4e: /* original 3304, guest PC 0x0c042c4e */
if(!s->budget--) { s->failed_pc=0x0c042c4eu; return 0; }
divide_step(s,3,0);
goto P_0c042c50;
P_0c042c50: /* original 4124, guest PC 0x0c042c50 */
if(!s->budget--) { s->failed_pc=0x0c042c50u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c52;
P_0c042c52: /* original 3304, guest PC 0x0c042c52 */
if(!s->budget--) { s->failed_pc=0x0c042c52u; return 0; }
divide_step(s,3,0);
goto P_0c042c54;
P_0c042c54: /* original 4124, guest PC 0x0c042c54 */
if(!s->budget--) { s->failed_pc=0x0c042c54u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c56;
P_0c042c56: /* original 3304, guest PC 0x0c042c56 */
if(!s->budget--) { s->failed_pc=0x0c042c56u; return 0; }
divide_step(s,3,0);
goto P_0c042c58;
P_0c042c58: /* original 4124, guest PC 0x0c042c58 */
if(!s->budget--) { s->failed_pc=0x0c042c58u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5a;
P_0c042c5a: /* original 3304, guest PC 0x0c042c5a */
if(!s->budget--) { s->failed_pc=0x0c042c5au; return 0; }
divide_step(s,3,0);
goto P_0c042c5c;
P_0c042c5c: /* original 4124, guest PC 0x0c042c5c */
if(!s->budget--) { s->failed_pc=0x0c042c5cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c5e;
P_0c042c5e: /* original 3304, guest PC 0x0c042c5e */
if(!s->budget--) { s->failed_pc=0x0c042c5eu; return 0; }
divide_step(s,3,0);
goto P_0c042c60;
P_0c042c60: /* original 4124, guest PC 0x0c042c60 */
if(!s->budget--) { s->failed_pc=0x0c042c60u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c62;
P_0c042c62: /* original 3304, guest PC 0x0c042c62 */
if(!s->budget--) { s->failed_pc=0x0c042c62u; return 0; }
divide_step(s,3,0);
goto P_0c042c64;
P_0c042c64: /* original 4124, guest PC 0x0c042c64 */
if(!s->budget--) { s->failed_pc=0x0c042c64u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c66;
P_0c042c66: /* original 3304, guest PC 0x0c042c66 */
if(!s->budget--) { s->failed_pc=0x0c042c66u; return 0; }
divide_step(s,3,0);
goto P_0c042c68;
P_0c042c68: /* original 4124, guest PC 0x0c042c68 */
if(!s->budget--) { s->failed_pc=0x0c042c68u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6a;
P_0c042c6a: /* original 3304, guest PC 0x0c042c6a */
if(!s->budget--) { s->failed_pc=0x0c042c6au; return 0; }
divide_step(s,3,0);
goto P_0c042c6c;
P_0c042c6c: /* original 4124, guest PC 0x0c042c6c */
if(!s->budget--) { s->failed_pc=0x0c042c6cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c6e;
P_0c042c6e: /* original 3304, guest PC 0x0c042c6e */
if(!s->budget--) { s->failed_pc=0x0c042c6eu; return 0; }
divide_step(s,3,0);
goto P_0c042c70;
P_0c042c70: /* original 4124, guest PC 0x0c042c70 */
if(!s->budget--) { s->failed_pc=0x0c042c70u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c72;
P_0c042c72: /* original 3304, guest PC 0x0c042c72 */
if(!s->budget--) { s->failed_pc=0x0c042c72u; return 0; }
divide_step(s,3,0);
goto P_0c042c74;
P_0c042c74: /* original 4124, guest PC 0x0c042c74 */
if(!s->budget--) { s->failed_pc=0x0c042c74u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c76;
P_0c042c76: /* original 3304, guest PC 0x0c042c76 */
if(!s->budget--) { s->failed_pc=0x0c042c76u; return 0; }
divide_step(s,3,0);
goto P_0c042c78;
P_0c042c78: /* original 4124, guest PC 0x0c042c78 */
if(!s->budget--) { s->failed_pc=0x0c042c78u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7a;
P_0c042c7a: /* original 3304, guest PC 0x0c042c7a */
if(!s->budget--) { s->failed_pc=0x0c042c7au; return 0; }
divide_step(s,3,0);
goto P_0c042c7c;
P_0c042c7c: /* original 4124, guest PC 0x0c042c7c */
if(!s->budget--) { s->failed_pc=0x0c042c7cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c7e;
P_0c042c7e: /* original 3304, guest PC 0x0c042c7e */
if(!s->budget--) { s->failed_pc=0x0c042c7eu; return 0; }
divide_step(s,3,0);
goto P_0c042c80;
P_0c042c80: /* original 4124, guest PC 0x0c042c80 */
if(!s->budget--) { s->failed_pc=0x0c042c80u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c82;
P_0c042c82: /* original 3304, guest PC 0x0c042c82 */
if(!s->budget--) { s->failed_pc=0x0c042c82u; return 0; }
divide_step(s,3,0);
goto P_0c042c84;
P_0c042c84: /* original 4124, guest PC 0x0c042c84 */
if(!s->budget--) { s->failed_pc=0x0c042c84u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c86;
P_0c042c86: /* original 3304, guest PC 0x0c042c86 */
if(!s->budget--) { s->failed_pc=0x0c042c86u; return 0; }
divide_step(s,3,0);
goto P_0c042c88;
P_0c042c88: /* original 4124, guest PC 0x0c042c88 */
if(!s->budget--) { s->failed_pc=0x0c042c88u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8a;
P_0c042c8a: /* original 3304, guest PC 0x0c042c8a */
if(!s->budget--) { s->failed_pc=0x0c042c8au; return 0; }
divide_step(s,3,0);
goto P_0c042c8c;
P_0c042c8c: /* original 4124, guest PC 0x0c042c8c */
if(!s->budget--) { s->failed_pc=0x0c042c8cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c8e;
P_0c042c8e: /* original 3304, guest PC 0x0c042c8e */
if(!s->budget--) { s->failed_pc=0x0c042c8eu; return 0; }
divide_step(s,3,0);
goto P_0c042c90;
P_0c042c90: /* original 4124, guest PC 0x0c042c90 */
if(!s->budget--) { s->failed_pc=0x0c042c90u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c92;
P_0c042c92: /* original 3304, guest PC 0x0c042c92 */
if(!s->budget--) { s->failed_pc=0x0c042c92u; return 0; }
divide_step(s,3,0);
goto P_0c042c94;
P_0c042c94: /* original 4124, guest PC 0x0c042c94 */
if(!s->budget--) { s->failed_pc=0x0c042c94u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c96;
P_0c042c96: /* original 3304, guest PC 0x0c042c96 */
if(!s->budget--) { s->failed_pc=0x0c042c96u; return 0; }
divide_step(s,3,0);
goto P_0c042c98;
P_0c042c98: /* original 4124, guest PC 0x0c042c98 */
if(!s->budget--) { s->failed_pc=0x0c042c98u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9a;
P_0c042c9a: /* original 3304, guest PC 0x0c042c9a */
if(!s->budget--) { s->failed_pc=0x0c042c9au; return 0; }
divide_step(s,3,0);
goto P_0c042c9c;
P_0c042c9c: /* original 4124, guest PC 0x0c042c9c */
if(!s->budget--) { s->failed_pc=0x0c042c9cu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042c9e;
P_0c042c9e: /* original 3304, guest PC 0x0c042c9e */
if(!s->budget--) { s->failed_pc=0x0c042c9eu; return 0; }
divide_step(s,3,0);
goto P_0c042ca0;
P_0c042ca0: /* original 4124, guest PC 0x0c042ca0 */
if(!s->budget--) { s->failed_pc=0x0c042ca0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca2;
P_0c042ca2: /* original 3304, guest PC 0x0c042ca2 */
if(!s->budget--) { s->failed_pc=0x0c042ca2u; return 0; }
divide_step(s,3,0);
goto P_0c042ca4;
P_0c042ca4: /* original 4124, guest PC 0x0c042ca4 */
if(!s->budget--) { s->failed_pc=0x0c042ca4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042ca6;
P_0c042ca6: /* original 3304, guest PC 0x0c042ca6 */
if(!s->budget--) { s->failed_pc=0x0c042ca6u; return 0; }
divide_step(s,3,0);
goto P_0c042ca8;
P_0c042ca8: /* original 4124, guest PC 0x0c042ca8 */
if(!s->budget--) { s->failed_pc=0x0c042ca8u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042caa;
P_0c042caa: /* original 3304, guest PC 0x0c042caa */
if(!s->budget--) { s->failed_pc=0x0c042caau; return 0; }
divide_step(s,3,0);
goto P_0c042cac;
P_0c042cac: /* original 4124, guest PC 0x0c042cac */
if(!s->budget--) { s->failed_pc=0x0c042cacu; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cae;
P_0c042cae: /* original 3304, guest PC 0x0c042cae */
if(!s->budget--) { s->failed_pc=0x0c042caeu; return 0; }
divide_step(s,3,0);
goto P_0c042cb0;
P_0c042cb0: /* original 4124, guest PC 0x0c042cb0 */
if(!s->budget--) { s->failed_pc=0x0c042cb0u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb2;
P_0c042cb2: /* original 3304, guest PC 0x0c042cb2 */
if(!s->budget--) { s->failed_pc=0x0c042cb2u; return 0; }
divide_step(s,3,0);
goto P_0c042cb4;
P_0c042cb4: /* original 4124, guest PC 0x0c042cb4 */
if(!s->budget--) { s->failed_pc=0x0c042cb4u; return 0; }
tmp=r[1]>>31; r[1]=(r[1]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c042cb6;
P_0c042cb6: /* original 312e, guest PC 0x0c042cb6 */
if(!s->budget--) { s->failed_pc=0x0c042cb6u; return 0; }
wide=(uint64_t)r[1]+r[2]+(r[17]&1u); r[1]=(uint32_t)wide;
r[17]=(r[17]&~1u)|((wide>>32)!=0);
goto P_0c042cb8;
P_0c042cb8: /* original 6013, guest PC 0x0c042cb8 */
if(!s->budget--) { s->failed_pc=0x0c042cb8u; return 0; }
r[0]=r[1];
goto P_0c042cba;
P_0c042cba: /* original 63f6, guest PC 0x0c042cba */
if(!s->budget--) { s->failed_pc=0x0c042cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c042cbc;
P_0c042cbc: /* original 000b, guest PC 0x0c042cbc */
if(!s->budget--) { s->failed_pc=0x0c042cbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
s->pc=target; return ram->oob==0;
P_0c042cbe: /* original 62f6, guest PC 0x0c042cbe */
if(!s->budget--) { s->failed_pc=0x0c042cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
return vf3_matrix_family(0x0c042cc0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
