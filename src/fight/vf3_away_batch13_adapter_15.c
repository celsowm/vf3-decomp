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
int vf3_away_batch13_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c085a0cu: goto P_0c085a0c;
case 0x0c085a0eu: goto P_0c085a0e;
case 0x0c085a10u: goto P_0c085a10;
case 0x0c085a12u: goto P_0c085a12;
case 0x0c085a14u: goto P_0c085a14;
case 0x0c085a16u: goto P_0c085a16;
case 0x0c085a18u: goto P_0c085a18;
case 0x0c085a1au: goto P_0c085a1a;
case 0x0c085a1cu: goto P_0c085a1c;
case 0x0c085a1eu: goto P_0c085a1e;
case 0x0c085a20u: goto P_0c085a20;
case 0x0c085a22u: goto P_0c085a22;
case 0x0c085a24u: goto P_0c085a24;
case 0x0c085a26u: goto P_0c085a26;
case 0x0c085a28u: goto P_0c085a28;
case 0x0c085a2au: goto P_0c085a2a;
case 0x0c085a2cu: goto P_0c085a2c;
case 0x0c085a2eu: goto P_0c085a2e;
case 0x0c085a30u: goto P_0c085a30;
case 0x0c085a32u: goto P_0c085a32;
case 0x0c085a34u: goto P_0c085a34;
case 0x0c085a36u: goto P_0c085a36;
case 0x0c085a38u: goto P_0c085a38;
case 0x0c085a3au: goto P_0c085a3a;
case 0x0c085a3cu: goto P_0c085a3c;
case 0x0c085a3eu: goto P_0c085a3e;
case 0x0c085a40u: goto P_0c085a40;
case 0x0c085a42u: goto P_0c085a42;
case 0x0c085a44u: goto P_0c085a44;
case 0x0c085a46u: goto P_0c085a46;
case 0x0c085a48u: goto P_0c085a48;
case 0x0c085a4au: goto P_0c085a4a;
case 0x0c085a4cu: goto P_0c085a4c;
case 0x0c085a4eu: goto P_0c085a4e;
case 0x0c085a50u: goto P_0c085a50;
case 0x0c085a52u: goto P_0c085a52;
case 0x0c085a54u: goto P_0c085a54;
case 0x0c085a56u: goto P_0c085a56;
case 0x0c085a58u: goto P_0c085a58;
case 0x0c085a5au: goto P_0c085a5a;
case 0x0c085a5cu: goto P_0c085a5c;
case 0x0c085a5eu: goto P_0c085a5e;
case 0x0c085a60u: goto P_0c085a60;
case 0x0c085a62u: goto P_0c085a62;
case 0x0c085a64u: goto P_0c085a64;
case 0x0c085a66u: goto P_0c085a66;
case 0x0c085a68u: goto P_0c085a68;
case 0x0c085a6au: goto P_0c085a6a;
case 0x0c085a6cu: goto P_0c085a6c;
case 0x0c085a6eu: goto P_0c085a6e;
case 0x0c085a70u: goto P_0c085a70;
case 0x0c085a72u: goto P_0c085a72;
case 0x0c085a74u: goto P_0c085a74;
case 0x0c085a76u: goto P_0c085a76;
case 0x0c085a78u: goto P_0c085a78;
case 0x0c085a7au: goto P_0c085a7a;
case 0x0c085a7cu: goto P_0c085a7c;
case 0x0c085a7eu: goto P_0c085a7e;
case 0x0c085a80u: goto P_0c085a80;
case 0x0c085a82u: goto P_0c085a82;
case 0x0c085a84u: goto P_0c085a84;
case 0x0c085a86u: goto P_0c085a86;
case 0x0c085a88u: goto P_0c085a88;
case 0x0c085a8au: goto P_0c085a8a;
case 0x0c085a8cu: goto P_0c085a8c;
case 0x0c085a8eu: goto P_0c085a8e;
case 0x0c085a90u: goto P_0c085a90;
case 0x0c085a92u: goto P_0c085a92;
case 0x0c085a94u: goto P_0c085a94;
case 0x0c085a96u: goto P_0c085a96;
case 0x0c085a98u: goto P_0c085a98;
case 0x0c085a9au: goto P_0c085a9a;
case 0x0c085a9cu: goto P_0c085a9c;
case 0x0c085a9eu: goto P_0c085a9e;
case 0x0c085aa0u: goto P_0c085aa0;
case 0x0c085aa2u: goto P_0c085aa2;
case 0x0c085aa4u: goto P_0c085aa4;
case 0x0c085aa6u: goto P_0c085aa6;
case 0x0c085aa8u: goto P_0c085aa8;
case 0x0c085aaau: goto P_0c085aaa;
case 0x0c085aacu: goto P_0c085aac;
case 0x0c085aaeu: goto P_0c085aae;
case 0x0c085ab0u: goto P_0c085ab0;
case 0x0c085ab2u: goto P_0c085ab2;
case 0x0c085ab4u: goto P_0c085ab4;
case 0x0c085ab6u: goto P_0c085ab6;
case 0x0c085ab8u: goto P_0c085ab8;
case 0x0c085abau: goto P_0c085aba;
case 0x0c085abcu: goto P_0c085abc;
case 0x0c085abeu: goto P_0c085abe;
case 0x0c085ac0u: goto P_0c085ac0;
case 0x0c085ac2u: goto P_0c085ac2;
case 0x0c085ac4u: goto P_0c085ac4;
case 0x0c085ac6u: goto P_0c085ac6;
case 0x0c085ac8u: goto P_0c085ac8;
case 0x0c085acau: goto P_0c085aca;
case 0x0c085accu: goto P_0c085acc;
case 0x0c085aceu: goto P_0c085ace;
case 0x0c085ad0u: goto P_0c085ad0;
case 0x0c085ad2u: goto P_0c085ad2;
case 0x0c085ad4u: goto P_0c085ad4;
case 0x0c085ad6u: goto P_0c085ad6;
case 0x0c085ad8u: goto P_0c085ad8;
case 0x0c085adau: goto P_0c085ada;
case 0x0c085adcu: goto P_0c085adc;
case 0x0c085adeu: goto P_0c085ade;
case 0x0c085ae0u: goto P_0c085ae0;
case 0x0c085ae2u: goto P_0c085ae2;
case 0x0c085ae4u: goto P_0c085ae4;
case 0x0c085ae6u: goto P_0c085ae6;
case 0x0c085ae8u: goto P_0c085ae8;
case 0x0c085aeau: goto P_0c085aea;
case 0x0c085aecu: goto P_0c085aec;
case 0x0c085aeeu: goto P_0c085aee;
case 0x0c085af0u: goto P_0c085af0;
case 0x0c085af2u: goto P_0c085af2;
case 0x0c085af4u: goto P_0c085af4;
case 0x0c085af6u: goto P_0c085af6;
case 0x0c085af8u: goto P_0c085af8;
case 0x0c085afau: goto P_0c085afa;
case 0x0c085afcu: goto P_0c085afc;
case 0x0c085afeu: goto P_0c085afe;
case 0x0c085b00u: goto P_0c085b00;
case 0x0c085b02u: goto P_0c085b02;
case 0x0c085b04u: goto P_0c085b04;
case 0x0c085b06u: goto P_0c085b06;
case 0x0c085b08u: goto P_0c085b08;
case 0x0c085b0au: goto P_0c085b0a;
case 0x0c085b0cu: goto P_0c085b0c;
case 0x0c085b0eu: goto P_0c085b0e;
case 0x0c085b10u: goto P_0c085b10;
case 0x0c085b12u: goto P_0c085b12;
case 0x0c085b14u: goto P_0c085b14;
case 0x0c085b16u: goto P_0c085b16;
case 0x0c085b18u: goto P_0c085b18;
case 0x0c085b1au: goto P_0c085b1a;
case 0x0c085b1cu: goto P_0c085b1c;
case 0x0c085b1eu: goto P_0c085b1e;
case 0x0c085b20u: goto P_0c085b20;
case 0x0c085b22u: goto P_0c085b22;
case 0x0c085b24u: goto P_0c085b24;
case 0x0c085b26u: goto P_0c085b26;
case 0x0c085b28u: goto P_0c085b28;
case 0x0c085b2au: goto P_0c085b2a;
case 0x0c085b2cu: goto P_0c085b2c;
case 0x0c085b2eu: goto P_0c085b2e;
case 0x0c085b30u: goto P_0c085b30;
case 0x0c085b32u: goto P_0c085b32;
case 0x0c085b34u: goto P_0c085b34;
case 0x0c085b36u: goto P_0c085b36;
case 0x0c085b38u: goto P_0c085b38;
case 0x0c085b3au: goto P_0c085b3a;
case 0x0c085b3cu: goto P_0c085b3c;
case 0x0c085b3eu: goto P_0c085b3e;
case 0x0c085b40u: goto P_0c085b40;
case 0x0c085b42u: goto P_0c085b42;
case 0x0c085b44u: goto P_0c085b44;
case 0x0c085b46u: goto P_0c085b46;
case 0x0c085b48u: goto P_0c085b48;
case 0x0c085b4au: goto P_0c085b4a;
case 0x0c085b88u: goto P_0c085b88;
case 0x0c085b8au: goto P_0c085b8a;
case 0x0c085b8cu: goto P_0c085b8c;
case 0x0c085b8eu: goto P_0c085b8e;
case 0x0c085b90u: goto P_0c085b90;
case 0x0c085b92u: goto P_0c085b92;
case 0x0c085b94u: goto P_0c085b94;
case 0x0c085b96u: goto P_0c085b96;
case 0x0c085b98u: goto P_0c085b98;
case 0x0c085b9au: goto P_0c085b9a;
case 0x0c085b9cu: goto P_0c085b9c;
case 0x0c085b9eu: goto P_0c085b9e;
case 0x0c085ba0u: goto P_0c085ba0;
case 0x0c085ba2u: goto P_0c085ba2;
case 0x0c085ba4u: goto P_0c085ba4;
case 0x0c085ba6u: goto P_0c085ba6;
case 0x0c085ba8u: goto P_0c085ba8;
case 0x0c085baau: goto P_0c085baa;
case 0x0c085bacu: goto P_0c085bac;
case 0x0c085baeu: goto P_0c085bae;
case 0x0c085bb0u: goto P_0c085bb0;
case 0x0c085bb2u: goto P_0c085bb2;
case 0x0c085bb4u: goto P_0c085bb4;
case 0x0c085bb6u: goto P_0c085bb6;
case 0x0c085bb8u: goto P_0c085bb8;
case 0x0c085bbau: goto P_0c085bba;
case 0x0c085bbcu: goto P_0c085bbc;
case 0x0c085bbeu: goto P_0c085bbe;
case 0x0c085bc0u: goto P_0c085bc0;
case 0x0c085bc2u: goto P_0c085bc2;
case 0x0c085bc4u: goto P_0c085bc4;
case 0x0c085bd4u: goto P_0c085bd4;
case 0x0c085bd6u: goto P_0c085bd6;
case 0x0c085bd8u: goto P_0c085bd8;
case 0x0c085bdau: goto P_0c085bda;
case 0x0c085bdcu: goto P_0c085bdc;
case 0x0c085bdeu: goto P_0c085bde;
case 0x0c085be0u: goto P_0c085be0;
case 0x0c085be2u: goto P_0c085be2;
case 0x0c085be4u: goto P_0c085be4;
case 0x0c085be6u: goto P_0c085be6;
case 0x0c085be8u: goto P_0c085be8;
case 0x0c085beau: goto P_0c085bea;
case 0x0c085becu: goto P_0c085bec;
case 0x0c085beeu: goto P_0c085bee;
case 0x0c085bf0u: goto P_0c085bf0;
case 0x0c085bf2u: goto P_0c085bf2;
case 0x0c085bf4u: goto P_0c085bf4;
case 0x0c085bf6u: goto P_0c085bf6;
case 0x0c085bf8u: goto P_0c085bf8;
case 0x0c085bfau: goto P_0c085bfa;
case 0x0c085bfcu: goto P_0c085bfc;
case 0x0c085bfeu: goto P_0c085bfe;
case 0x0c085c00u: goto P_0c085c00;
default: return vf3_matrix_family(target,s,ram);
}
P_0c085a0c: /* original 2fe6, guest PC 0x0c085a0c */
if(!s->budget--) { s->failed_pc=0x0c085a0cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a0e;
P_0c085a0e: /* original 2fd6, guest PC 0x0c085a0e */
if(!s->budget--) { s->failed_pc=0x0c085a0eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a10;
P_0c085a10: /* original 2fc6, guest PC 0x0c085a10 */
if(!s->budget--) { s->failed_pc=0x0c085a10u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a12;
P_0c085a12: /* original 2fb6, guest PC 0x0c085a12 */
if(!s->budget--) { s->failed_pc=0x0c085a12u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a14;
P_0c085a14: /* original 2fa6, guest PC 0x0c085a14 */
if(!s->budget--) { s->failed_pc=0x0c085a14u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a16;
P_0c085a16: /* original 4f22, guest PC 0x0c085a16 */
if(!s->budget--) { s->failed_pc=0x0c085a16u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085a18;
P_0c085a18: /* original 9098, guest PC 0x0c085a18 */
if(!s->budget--) { s->failed_pc=0x0c085a18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b4cu,2);
goto P_0c085a1a;
P_0c085a1a: /* original d351, guest PC 0x0c085a1a */
if(!s->budget--) { s->failed_pc=0x0c085a1au; return 0; }
r[3]=read(ram,0x0c085b60u,4);
goto P_0c085a1c;
P_0c085a1c: /* original 3f0c, guest PC 0x0c085a1c */
if(!s->budget--) { s->failed_pc=0x0c085a1cu; return 0; }
r[15]+=r[0];
goto P_0c085a1e;
P_0c085a1e: /* original d052, guest PC 0x0c085a1e */
if(!s->budget--) { s->failed_pc=0x0c085a1eu; return 0; }
r[0]=read(ram,0x0c085b68u,4);
goto P_0c085a20;
P_0c085a20: /* original d250, guest PC 0x0c085a20 */
if(!s->budget--) { s->failed_pc=0x0c085a20u; return 0; }
r[2]=read(ram,0x0c085b64u,4);
goto P_0c085a22;
P_0c085a22: /* original 6102, guest PC 0x0c085a22 */
if(!s->budget--) { s->failed_pc=0x0c085a22u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c085a24;
P_0c085a24: /* original 6e32, guest PC 0x0c085a24 */
if(!s->budget--) { s->failed_pc=0x0c085a24u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c085a26;
P_0c085a26: /* original 2128, guest PC 0x0c085a26 */
if(!s->budget--) { s->failed_pc=0x0c085a26u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c085a28;
P_0c085a28: /* original 8b06, guest PC 0x0c085a28 */
if(!s->budget--) { s->failed_pc=0x0c085a28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c085a38; }
goto P_0c085a2a;
P_0c085a2a: /* original 85e3, guest PC 0x0c085a2a */
if(!s->budget--) { s->failed_pc=0x0c085a2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+6,2);
goto P_0c085a2c;
P_0c085a2c: /* original e37f, guest PC 0x0c085a2c */
if(!s->budget--) { s->failed_pc=0x0c085a2cu; return 0; }
r[3]=0x0000007fu;
goto P_0c085a2e;
P_0c085a2e: /* original 640d, guest PC 0x0c085a2e */
if(!s->budget--) { s->failed_pc=0x0c085a2eu; return 0; }
r[4]=r[0]&65535u;
goto P_0c085a30;
P_0c085a30: /* original 7401, guest PC 0x0c085a30 */
if(!s->budget--) { s->failed_pc=0x0c085a30u; return 0; }
r[4]+=0x00000001u;
goto P_0c085a32;
P_0c085a32: /* original 2439, guest PC 0x0c085a32 */
if(!s->budget--) { s->failed_pc=0x0c085a32u; return 0; }
r[4]&=r[3];
goto P_0c085a34;
P_0c085a34: /* original 6043, guest PC 0x0c085a34 */
if(!s->budget--) { s->failed_pc=0x0c085a34u; return 0; }
r[0]=r[4];
goto P_0c085a36;
P_0c085a36: /* original 81e3, guest PC 0x0c085a36 */
if(!s->budget--) { s->failed_pc=0x0c085a36u; return 0; }
write(ram,r[14]+6,r[0],2);
goto P_0c085a38;
P_0c085a38: /* original d34c, guest PC 0x0c085a38 */
if(!s->budget--) { s->failed_pc=0x0c085a38u; return 0; }
r[3]=read(ram,0x0c085b6cu,4);
goto P_0c085a3a;
P_0c085a3a: /* original 64f3, guest PC 0x0c085a3a */
if(!s->budget--) { s->failed_pc=0x0c085a3au; return 0; }
r[4]=r[15];
goto P_0c085a3c;
P_0c085a3c: /* original 430b, guest PC 0x0c085a3c */
if(!s->budget--) { s->failed_pc=0x0c085a3cu; return 0; }
target=r[3];
r[16]=code_base|0x0c085a40u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085a40u) { target=s->pc; goto dispatch; }
goto P_0c085a40;
P_0c085a3e: /* original 7410, guest PC 0x0c085a3e */
if(!s->budget--) { s->failed_pc=0x0c085a3eu; return 0; }
r[4]+=0x00000010u;
goto P_0c085a40;
P_0c085a40: /* original d24c, guest PC 0x0c085a40 */
if(!s->budget--) { s->failed_pc=0x0c085a40u; return 0; }
r[2]=read(ram,0x0c085b74u,4);
goto P_0c085a42;
P_0c085a42: /* original d44b, guest PC 0x0c085a42 */
if(!s->budget--) { s->failed_pc=0x0c085a42u; return 0; }
r[4]=read(ram,0x0c085b70u,4);
goto P_0c085a44;
P_0c085a44: /* original 420b, guest PC 0x0c085a44 */
if(!s->budget--) { s->failed_pc=0x0c085a44u; return 0; }
target=r[2];
r[16]=code_base|0x0c085a48u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085a48u) { target=s->pc; goto dispatch; }
goto P_0c085a48;
P_0c085a46: /* original 0009, guest PC 0x0c085a46 */
if(!s->budget--) { s->failed_pc=0x0c085a46u; return 0; }
goto P_0c085a48;
P_0c085a48: /* original ed00, guest PC 0x0c085a48 */
if(!s->budget--) { s->failed_pc=0x0c085a48u; return 0; }
r[13]=0x00000000u;
goto P_0c085a4a;
P_0c085a4a: /* original 9480, guest PC 0x0c085a4a */
if(!s->budget--) { s->failed_pc=0x0c085a4au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b4eu,2);
goto P_0c085a4c;
P_0c085a4c: /* original 60d3, guest PC 0x0c085a4c */
if(!s->budget--) { s->failed_pc=0x0c085a4cu; return 0; }
r[0]=r[13];
goto P_0c085a4e;
P_0c085a4e: /* original 81f6, guest PC 0x0c085a4e */
if(!s->budget--) { s->failed_pc=0x0c085a4eu; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c085a50;
P_0c085a50: /* original f68d, guest PC 0x0c085a50 */
if(!s->budget--) { s->failed_pc=0x0c085a50u; return 0; }
fr[6]=0;
goto P_0c085a52;
P_0c085a52: /* original 67d3, guest PC 0x0c085a52 */
if(!s->budget--) { s->failed_pc=0x0c085a52u; return 0; }
r[7]=r[13];
goto P_0c085a54;
P_0c085a54: /* original f46c, guest PC 0x0c085a54 */
if(!s->budget--) { s->failed_pc=0x0c085a54u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c085a56;
P_0c085a56: /* original f56c, guest PC 0x0c085a56 */
if(!s->budget--) { s->failed_pc=0x0c085a56u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c085a58;
P_0c085a58: /* original ff6a, guest PC 0x0c085a58 */
if(!s->budget--) { s->failed_pc=0x0c085a58u; return 0; }
vf3_matrix_store(s,ram,6,r[15]);
goto P_0c085a5a;
P_0c085a5a: /* original 85f6, guest PC 0x0c085a5a */
if(!s->budget--) { s->failed_pc=0x0c085a5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c085a5c;
P_0c085a5c: /* original 6603, guest PC 0x0c085a5c */
if(!s->budget--) { s->failed_pc=0x0c085a5cu; return 0; }
r[6]=r[0];
goto P_0c085a5e;
P_0c085a5e: /* original b054, guest PC 0x0c085a5e */
if(!s->budget--) { s->failed_pc=0x0c085a5eu; return 0; }
target=code_base|0x0c085b0au; r[16]=code_base|0x0c085a62u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085a62u) { target=s->pc; goto dispatch; }
goto P_0c085a62;
P_0c085a60: /* original 65d3, guest PC 0x0c085a60 */
if(!s->budget--) { s->failed_pc=0x0c085a60u; return 0; }
r[5]=r[13];
goto P_0c085a62;
P_0c085a62: /* original 9077, guest PC 0x0c085a62 */
if(!s->budget--) { s->failed_pc=0x0c085a62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b54u,2);
goto P_0c085a64;
P_0c085a64: /* original 9c75, guest PC 0x0c085a64 */
if(!s->budget--) { s->failed_pc=0x0c085a64u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b52u,2);
goto P_0c085a66;
P_0c085a66: /* original 05ed, guest PC 0x0c085a66 */
if(!s->budget--) { s->failed_pc=0x0c085a66u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a68;
P_0c085a68: /* original 7002, guest PC 0x0c085a68 */
if(!s->budget--) { s->failed_pc=0x0c085a68u; return 0; }
r[0]+=0x00000002u;
goto P_0c085a6a;
P_0c085a6a: /* original 04ed, guest PC 0x0c085a6a */
if(!s->budget--) { s->failed_pc=0x0c085a6au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a6c;
P_0c085a6c: /* original 3c5c, guest PC 0x0c085a6c */
if(!s->budget--) { s->failed_pc=0x0c085a6cu; return 0; }
r[12]+=r[5];
goto P_0c085a6e;
P_0c085a6e: /* original 9b6f, guest PC 0x0c085a6e */
if(!s->budget--) { s->failed_pc=0x0c085a6eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b50u,2);
goto P_0c085a70;
P_0c085a70: /* original 6ccf, guest PC 0x0c085a70 */
if(!s->budget--) { s->failed_pc=0x0c085a70u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085a72;
P_0c085a72: /* original da41, guest PC 0x0c085a72 */
if(!s->budget--) { s->failed_pc=0x0c085a72u; return 0; }
r[10]=read(ram,0x0c085b78u,4);
goto P_0c085a74;
P_0c085a74: /* original 2fd6, guest PC 0x0c085a74 */
if(!s->budget--) { s->failed_pc=0x0c085a74u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a76;
P_0c085a76: /* original 3b4c, guest PC 0x0c085a76 */
if(!s->budget--) { s->failed_pc=0x0c085a76u; return 0; }
r[11]+=r[4];
goto P_0c085a78;
P_0c085a78: /* original 2fc6, guest PC 0x0c085a78 */
if(!s->budget--) { s->failed_pc=0x0c085a78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a7a;
P_0c085a7a: /* original 67bf, guest PC 0x0c085a7a */
if(!s->budget--) { s->failed_pc=0x0c085a7au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c085a7c;
P_0c085a7c: /* original 65f3, guest PC 0x0c085a7c */
if(!s->budget--) { s->failed_pc=0x0c085a7cu; return 0; }
r[5]=r[15];
goto P_0c085a7e;
P_0c085a7e: /* original 66f3, guest PC 0x0c085a7e */
if(!s->budget--) { s->failed_pc=0x0c085a7eu; return 0; }
r[6]=r[15];
goto P_0c085a80;
P_0c085a80: /* original 64f3, guest PC 0x0c085a80 */
if(!s->budget--) { s->failed_pc=0x0c085a80u; return 0; }
r[4]=r[15];
goto P_0c085a82;
P_0c085a82: /* original 750c, guest PC 0x0c085a82 */
if(!s->budget--) { s->failed_pc=0x0c085a82u; return 0; }
r[5]+=0x0000000cu;
goto P_0c085a84;
P_0c085a84: /* original 7610, guest PC 0x0c085a84 */
if(!s->budget--) { s->failed_pc=0x0c085a84u; return 0; }
r[6]+=0x00000010u;
goto P_0c085a86;
P_0c085a86: /* original 4a0b, guest PC 0x0c085a86 */
if(!s->budget--) { s->failed_pc=0x0c085a86u; return 0; }
target=r[10];
r[16]=code_base|0x0c085a8au;
r[4]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085a8au) { target=s->pc; goto dispatch; }
goto P_0c085a8a;
P_0c085a88: /* original 7408, guest PC 0x0c085a88 */
if(!s->budget--) { s->failed_pc=0x0c085a88u; return 0; }
r[4]+=0x00000008u;
goto P_0c085a8a;
P_0c085a8a: /* original 9063, guest PC 0x0c085a8a */
if(!s->budget--) { s->failed_pc=0x0c085a8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b54u,2);
goto P_0c085a8c;
P_0c085a8c: /* original 9c63, guest PC 0x0c085a8c */
if(!s->budget--) { s->failed_pc=0x0c085a8cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b56u,2);
goto P_0c085a8e;
P_0c085a8e: /* original 04ed, guest PC 0x0c085a8e */
if(!s->budget--) { s->failed_pc=0x0c085a8eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a90;
P_0c085a90: /* original 7002, guest PC 0x0c085a90 */
if(!s->budget--) { s->failed_pc=0x0c085a90u; return 0; }
r[0]+=0x00000002u;
goto P_0c085a92;
P_0c085a92: /* original 9b5c, guest PC 0x0c085a92 */
if(!s->budget--) { s->failed_pc=0x0c085a92u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b4eu,2);
goto P_0c085a94;
P_0c085a94: /* original 654b, guest PC 0x0c085a94 */
if(!s->budget--) { s->failed_pc=0x0c085a94u; return 0; }
r[5]=0u-r[4];
goto P_0c085a96;
P_0c085a96: /* original 04ed, guest PC 0x0c085a96 */
if(!s->budget--) { s->failed_pc=0x0c085a96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085a98;
P_0c085a98: /* original 3c5c, guest PC 0x0c085a98 */
if(!s->budget--) { s->failed_pc=0x0c085a98u; return 0; }
r[12]+=r[5];
goto P_0c085a9a;
P_0c085a9a: /* original 2fd6, guest PC 0x0c085a9a */
if(!s->budget--) { s->failed_pc=0x0c085a9au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085a9c;
P_0c085a9c: /* original 6ccf, guest PC 0x0c085a9c */
if(!s->budget--) { s->failed_pc=0x0c085a9cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085a9e;
P_0c085a9e: /* original 2fc6, guest PC 0x0c085a9e */
if(!s->budget--) { s->failed_pc=0x0c085a9eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085aa0;
P_0c085aa0: /* original 3b4c, guest PC 0x0c085aa0 */
if(!s->budget--) { s->failed_pc=0x0c085aa0u; return 0; }
r[11]+=r[4];
goto P_0c085aa2;
P_0c085aa2: /* original 66f3, guest PC 0x0c085aa2 */
if(!s->budget--) { s->failed_pc=0x0c085aa2u; return 0; }
r[6]=r[15];
goto P_0c085aa4;
P_0c085aa4: /* original 65f3, guest PC 0x0c085aa4 */
if(!s->budget--) { s->failed_pc=0x0c085aa4u; return 0; }
r[5]=r[15];
goto P_0c085aa6;
P_0c085aa6: /* original 7514, guest PC 0x0c085aa6 */
if(!s->budget--) { s->failed_pc=0x0c085aa6u; return 0; }
r[5]+=0x00000014u;
goto P_0c085aa8;
P_0c085aa8: /* original 64f3, guest PC 0x0c085aa8 */
if(!s->budget--) { s->failed_pc=0x0c085aa8u; return 0; }
r[4]=r[15];
goto P_0c085aaa;
P_0c085aaa: /* original 7618, guest PC 0x0c085aaa */
if(!s->budget--) { s->failed_pc=0x0c085aaau; return 0; }
r[6]+=0x00000018u;
goto P_0c085aac;
P_0c085aac: /* original 67bf, guest PC 0x0c085aac */
if(!s->budget--) { s->failed_pc=0x0c085aacu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c085aae;
P_0c085aae: /* original 4a0b, guest PC 0x0c085aae */
if(!s->budget--) { s->failed_pc=0x0c085aaeu; return 0; }
target=r[10];
r[16]=code_base|0x0c085ab2u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085ab2u) { target=s->pc; goto dispatch; }
goto P_0c085ab2;
P_0c085ab0: /* original 7410, guest PC 0x0c085ab0 */
if(!s->budget--) { s->failed_pc=0x0c085ab0u; return 0; }
r[4]+=0x00000010u;
goto P_0c085ab2;
P_0c085ab2: /* original 904f, guest PC 0x0c085ab2 */
if(!s->budget--) { s->failed_pc=0x0c085ab2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b54u,2);
goto P_0c085ab4;
P_0c085ab4: /* original 9c51, guest PC 0x0c085ab4 */
if(!s->budget--) { s->failed_pc=0x0c085ab4u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b5au,2);
goto P_0c085ab6;
P_0c085ab6: /* original 05ed, guest PC 0x0c085ab6 */
if(!s->budget--) { s->failed_pc=0x0c085ab6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085ab8;
P_0c085ab8: /* original 7002, guest PC 0x0c085ab8 */
if(!s->budget--) { s->failed_pc=0x0c085ab8u; return 0; }
r[0]+=0x00000002u;
goto P_0c085aba;
P_0c085aba: /* original 9b4d, guest PC 0x0c085aba */
if(!s->budget--) { s->failed_pc=0x0c085abau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b58u,2);
goto P_0c085abc;
P_0c085abc: /* original 3c5c, guest PC 0x0c085abc */
if(!s->budget--) { s->failed_pc=0x0c085abcu; return 0; }
r[12]+=r[5];
goto P_0c085abe;
P_0c085abe: /* original 04ed, guest PC 0x0c085abe */
if(!s->budget--) { s->failed_pc=0x0c085abeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085ac0;
P_0c085ac0: /* original 6ccf, guest PC 0x0c085ac0 */
if(!s->budget--) { s->failed_pc=0x0c085ac0u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085ac2;
P_0c085ac2: /* original 2fd6, guest PC 0x0c085ac2 */
if(!s->budget--) { s->failed_pc=0x0c085ac2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ac4;
P_0c085ac4: /* original 2fc6, guest PC 0x0c085ac4 */
if(!s->budget--) { s->failed_pc=0x0c085ac4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085ac6;
P_0c085ac6: /* original 3b4c, guest PC 0x0c085ac6 */
if(!s->budget--) { s->failed_pc=0x0c085ac6u; return 0; }
r[11]+=r[4];
goto P_0c085ac8;
P_0c085ac8: /* original 66f3, guest PC 0x0c085ac8 */
if(!s->budget--) { s->failed_pc=0x0c085ac8u; return 0; }
r[6]=r[15];
goto P_0c085aca;
P_0c085aca: /* original 65f3, guest PC 0x0c085aca */
if(!s->budget--) { s->failed_pc=0x0c085acau; return 0; }
r[5]=r[15];
goto P_0c085acc;
P_0c085acc: /* original 751c, guest PC 0x0c085acc */
if(!s->budget--) { s->failed_pc=0x0c085accu; return 0; }
r[5]+=0x0000001cu;
goto P_0c085ace;
P_0c085ace: /* original 64f3, guest PC 0x0c085ace */
if(!s->budget--) { s->failed_pc=0x0c085aceu; return 0; }
r[4]=r[15];
goto P_0c085ad0;
P_0c085ad0: /* original 67bf, guest PC 0x0c085ad0 */
if(!s->budget--) { s->failed_pc=0x0c085ad0u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)r[11];
goto P_0c085ad2;
P_0c085ad2: /* original 7620, guest PC 0x0c085ad2 */
if(!s->budget--) { s->failed_pc=0x0c085ad2u; return 0; }
r[6]+=0x00000020u;
goto P_0c085ad4;
P_0c085ad4: /* original 4a0b, guest PC 0x0c085ad4 */
if(!s->budget--) { s->failed_pc=0x0c085ad4u; return 0; }
target=r[10];
r[16]=code_base|0x0c085ad8u;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085ad8u) { target=s->pc; goto dispatch; }
goto P_0c085ad8;
P_0c085ad6: /* original 7418, guest PC 0x0c085ad6 */
if(!s->budget--) { s->failed_pc=0x0c085ad6u; return 0; }
r[4]+=0x00000018u;
goto P_0c085ad8;
P_0c085ad8: /* original d328, guest PC 0x0c085ad8 */
if(!s->budget--) { s->failed_pc=0x0c085ad8u; return 0; }
r[3]=read(ram,0x0c085b7cu,4);
goto P_0c085ada;
P_0c085ada: /* original 7f18, guest PC 0x0c085ada */
if(!s->budget--) { s->failed_pc=0x0c085adau; return 0; }
r[15]+=0x00000018u;
goto P_0c085adc;
P_0c085adc: /* original 1f33, guest PC 0x0c085adc */
if(!s->budget--) { s->failed_pc=0x0c085adcu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c085ade;
P_0c085ade: /* original de28, guest PC 0x0c085ade */
if(!s->budget--) { s->failed_pc=0x0c085adeu; return 0; }
r[14]=read(ram,0x0c085b80u,4);
goto P_0c085ae0;
P_0c085ae0: /* original 60e1, guest PC 0x0c085ae0 */
if(!s->budget--) { s->failed_pc=0x0c085ae0u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c085ae2;
P_0c085ae2: /* original 88ff, guest PC 0x0c085ae2 */
if(!s->budget--) { s->failed_pc=0x0c085ae2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c085ae4;
P_0c085ae4: /* original 8d04, guest PC 0x0c085ae4 */
if(!s->budget--) { s->failed_pc=0x0c085ae4u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(cond) { goto P_0c085af0; }
goto P_0c085ae8;
P_0c085ae6: /* original 6403, guest PC 0x0c085ae6 */
if(!s->budget--) { s->failed_pc=0x0c085ae6u; return 0; }
r[4]=r[0];
goto P_0c085ae8;
P_0c085ae8: /* original 85e1, guest PC 0x0c085ae8 */
if(!s->budget--) { s->failed_pc=0x0c085ae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c085aea;
P_0c085aea: /* original 6503, guest PC 0x0c085aea */
if(!s->budget--) { s->failed_pc=0x0c085aeau; return 0; }
r[5]=r[0];
goto P_0c085aec;
P_0c085aec: /* original b02c, guest PC 0x0c085aec */
if(!s->budget--) { s->failed_pc=0x0c085aecu; return 0; }
target=code_base|0x0c085b48u; r[16]=code_base|0x0c085af0u;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085af0u) { target=s->pc; goto dispatch; }
goto P_0c085af0;
P_0c085aee: /* original 54f3, guest PC 0x0c085aee */
if(!s->budget--) { s->failed_pc=0x0c085aeeu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c085af0;
P_0c085af0: /* original d324, guest PC 0x0c085af0 */
if(!s->budget--) { s->failed_pc=0x0c085af0u; return 0; }
r[3]=read(ram,0x0c085b84u,4);
goto P_0c085af2;
P_0c085af2: /* original 64f3, guest PC 0x0c085af2 */
if(!s->budget--) { s->failed_pc=0x0c085af2u; return 0; }
r[4]=r[15];
goto P_0c085af4;
P_0c085af4: /* original 430b, guest PC 0x0c085af4 */
if(!s->budget--) { s->failed_pc=0x0c085af4u; return 0; }
target=r[3];
r[16]=code_base|0x0c085af8u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085af8u) { target=s->pc; goto dispatch; }
goto P_0c085af8;
P_0c085af6: /* original 7410, guest PC 0x0c085af6 */
if(!s->budget--) { s->failed_pc=0x0c085af6u; return 0; }
r[4]+=0x00000010u;
goto P_0c085af8;
P_0c085af8: /* original 9130, guest PC 0x0c085af8 */
if(!s->budget--) { s->failed_pc=0x0c085af8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085b5cu,2);
goto P_0c085afa;
P_0c085afa: /* original 3f1c, guest PC 0x0c085afa */
if(!s->budget--) { s->failed_pc=0x0c085afau; return 0; }
r[15]+=r[1];
goto P_0c085afc;
P_0c085afc: /* original 4f26, guest PC 0x0c085afc */
if(!s->budget--) { s->failed_pc=0x0c085afcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085afe;
P_0c085afe: /* original 6af6, guest PC 0x0c085afe */
if(!s->budget--) { s->failed_pc=0x0c085afeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085b00;
P_0c085b00: /* original 6bf6, guest PC 0x0c085b00 */
if(!s->budget--) { s->failed_pc=0x0c085b00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085b02;
P_0c085b02: /* original 6cf6, guest PC 0x0c085b02 */
if(!s->budget--) { s->failed_pc=0x0c085b02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085b04;
P_0c085b04: /* original 6df6, guest PC 0x0c085b04 */
if(!s->budget--) { s->failed_pc=0x0c085b04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085b06;
P_0c085b06: /* original 000b, guest PC 0x0c085b06 */
if(!s->budget--) { s->failed_pc=0x0c085b06u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085b08: /* original 6ef6, guest PC 0x0c085b08 */
if(!s->budget--) { s->failed_pc=0x0c085b08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085b0a;
P_0c085b0a: /* original 2fe6, guest PC 0x0c085b0a */
if(!s->budget--) { s->failed_pc=0x0c085b0au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b0c;
P_0c085b0c: /* original 6053, guest PC 0x0c085b0c */
if(!s->budget--) { s->failed_pc=0x0c085b0cu; return 0; }
r[0]=r[5];
goto P_0c085b0e;
P_0c085b0e: /* original 4f22, guest PC 0x0c085b0e */
if(!s->budget--) { s->failed_pc=0x0c085b0eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085b10;
P_0c085b10: /* original 6e4f, guest PC 0x0c085b10 */
if(!s->budget--) { s->failed_pc=0x0c085b10u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c085b12;
P_0c085b12: /* original 2ee8, guest PC 0x0c085b12 */
if(!s->budget--) { s->failed_pc=0x0c085b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c085b14;
P_0c085b14: /* original 7fec, guest PC 0x0c085b14 */
if(!s->budget--) { s->failed_pc=0x0c085b14u; return 0; }
r[15]+=0xffffffecu;
goto P_0c085b16;
P_0c085b16: /* original 63f3, guest PC 0x0c085b16 */
if(!s->budget--) { s->failed_pc=0x0c085b16u; return 0; }
r[3]=r[15];
goto P_0c085b18;
P_0c085b18: /* original 7310, guest PC 0x0c085b18 */
if(!s->budget--) { s->failed_pc=0x0c085b18u; return 0; }
r[3]+=0x00000010u;
goto P_0c085b1a;
P_0c085b1a: /* original f36a, guest PC 0x0c085b1a */
if(!s->budget--) { s->failed_pc=0x0c085b1au; return 0; }
vf3_matrix_store(s,ram,6,r[3]);
goto P_0c085b1c;
P_0c085b1c: /* original 81f4, guest PC 0x0c085b1c */
if(!s->budget--) { s->failed_pc=0x0c085b1cu; return 0; }
write(ram,r[15]+8,r[0],2);
goto P_0c085b1e;
P_0c085b1e: /* original 6063, guest PC 0x0c085b1e */
if(!s->budget--) { s->failed_pc=0x0c085b1eu; return 0; }
r[0]=r[6];
goto P_0c085b20;
P_0c085b20: /* original 8d0e, guest PC 0x0c085b20 */
if(!s->budget--) { s->failed_pc=0x0c085b20u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[0],2);
if(cond) { goto P_0c085b40; }
goto P_0c085b24;
P_0c085b22: /* original 81f6, guest PC 0x0c085b22 */
if(!s->budget--) { s->failed_pc=0x0c085b22u; return 0; }
write(ram,r[15]+12,r[0],2);
goto P_0c085b24;
P_0c085b24: /* original 85f6, guest PC 0x0c085b24 */
if(!s->budget--) { s->failed_pc=0x0c085b24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c085b26;
P_0c085b26: /* original 67e3, guest PC 0x0c085b26 */
if(!s->budget--) { s->failed_pc=0x0c085b26u; return 0; }
r[7]=r[14];
goto P_0c085b28;
P_0c085b28: /* original 2f06, guest PC 0x0c085b28 */
if(!s->budget--) { s->failed_pc=0x0c085b28u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b2a;
P_0c085b2a: /* original 85f6, guest PC 0x0c085b2a */
if(!s->budget--) { s->failed_pc=0x0c085b2au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+12,2);
goto P_0c085b2c;
P_0c085b2c: /* original 2f06, guest PC 0x0c085b2c */
if(!s->budget--) { s->failed_pc=0x0c085b2cu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b2e;
P_0c085b2e: /* original 65f3, guest PC 0x0c085b2e */
if(!s->budget--) { s->failed_pc=0x0c085b2eu; return 0; }
r[5]=r[15];
goto P_0c085b30;
P_0c085b30: /* original d311, guest PC 0x0c085b30 */
if(!s->budget--) { s->failed_pc=0x0c085b30u; return 0; }
r[3]=read(ram,0x0c085b78u,4);
goto P_0c085b32;
P_0c085b32: /* original 66f3, guest PC 0x0c085b32 */
if(!s->budget--) { s->failed_pc=0x0c085b32u; return 0; }
r[6]=r[15];
goto P_0c085b34;
P_0c085b34: /* original 64f3, guest PC 0x0c085b34 */
if(!s->budget--) { s->failed_pc=0x0c085b34u; return 0; }
r[4]=r[15];
goto P_0c085b36;
P_0c085b36: /* original 760c, guest PC 0x0c085b36 */
if(!s->budget--) { s->failed_pc=0x0c085b36u; return 0; }
r[6]+=0x0000000cu;
goto P_0c085b38;
P_0c085b38: /* original 7508, guest PC 0x0c085b38 */
if(!s->budget--) { s->failed_pc=0x0c085b38u; return 0; }
r[5]+=0x00000008u;
goto P_0c085b3a;
P_0c085b3a: /* original 430b, guest PC 0x0c085b3a */
if(!s->budget--) { s->failed_pc=0x0c085b3au; return 0; }
target=r[3];
r[16]=code_base|0x0c085b3eu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085b3eu) { target=s->pc; goto dispatch; }
goto P_0c085b3e;
P_0c085b3c: /* original 7418, guest PC 0x0c085b3c */
if(!s->budget--) { s->failed_pc=0x0c085b3cu; return 0; }
r[4]+=0x00000018u;
goto P_0c085b3e;
P_0c085b3e: /* original 7f08, guest PC 0x0c085b3e */
if(!s->budget--) { s->failed_pc=0x0c085b3eu; return 0; }
r[15]+=0x00000008u;
goto P_0c085b40;
P_0c085b40: /* original 7f14, guest PC 0x0c085b40 */
if(!s->budget--) { s->failed_pc=0x0c085b40u; return 0; }
r[15]+=0x00000014u;
goto P_0c085b42;
P_0c085b42: /* original 4f26, guest PC 0x0c085b42 */
if(!s->budget--) { s->failed_pc=0x0c085b42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085b44;
P_0c085b44: /* original 000b, guest PC 0x0c085b44 */
if(!s->budget--) { s->failed_pc=0x0c085b44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085b46: /* original 6ef6, guest PC 0x0c085b46 */
if(!s->budget--) { s->failed_pc=0x0c085b46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c085b48;
P_0c085b48: /* original 000b, guest PC 0x0c085b48 */
if(!s->budget--) { s->failed_pc=0x0c085b48u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c085b4a: /* original 0009, guest PC 0x0c085b4a */
if(!s->budget--) { s->failed_pc=0x0c085b4au; return 0; }
if(!vf3_matrix_family(0x0c085b4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085b4cu; return 0; } return 1;
P_0c085b88: /* original 2fe6, guest PC 0x0c085b88 */
if(!s->budget--) { s->failed_pc=0x0c085b88u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085b8a;
P_0c085b8a: /* original 6e43, guest PC 0x0c085b8a */
if(!s->budget--) { s->failed_pc=0x0c085b8au; return 0; }
r[14]=r[4];
goto P_0c085b8c;
P_0c085b8c: /* original 4f22, guest PC 0x0c085b8c */
if(!s->budget--) { s->failed_pc=0x0c085b8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085b8e;
P_0c085b8e: /* original e340, guest PC 0x0c085b8e */
if(!s->budget--) { s->failed_pc=0x0c085b8eu; return 0; }
r[3]=0x00000040u;
goto P_0c085b90;
P_0c085b90: /* original 7ffc, guest PC 0x0c085b90 */
if(!s->budget--) { s->failed_pc=0x0c085b90u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c085b92;
P_0c085b92: /* original 2f52, guest PC 0x0c085b92 */
if(!s->budget--) { s->failed_pc=0x0c085b92u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c085b94;
P_0c085b94: /* original 9017, guest PC 0x0c085b94 */
if(!s->budget--) { s->failed_pc=0x0c085b94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085bc6u,2);
goto P_0c085b96;
P_0c085b96: /* original 04ed, guest PC 0x0c085b96 */
if(!s->budget--) { s->failed_pc=0x0c085b96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c085b98;
P_0c085b98: /* original 7401, guest PC 0x0c085b98 */
if(!s->budget--) { s->failed_pc=0x0c085b98u; return 0; }
r[4]+=0x00000001u;
goto P_0c085b9a;
P_0c085b9a: /* original 2438, guest PC 0x0c085b9a */
if(!s->budget--) { s->failed_pc=0x0c085b9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c085b9c;
P_0c085b9c: /* original 8d0f, guest PC 0x0c085b9c */
if(!s->budget--) { s->failed_pc=0x0c085b9cu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],2);
if(cond) { goto P_0c085bbe; }
goto P_0c085ba0;
P_0c085b9e: /* original 0e45, guest PC 0x0c085b9e */
if(!s->budget--) { s->failed_pc=0x0c085b9eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c085ba0;
P_0c085ba0: /* original d30a, guest PC 0x0c085ba0 */
if(!s->budget--) { s->failed_pc=0x0c085ba0u; return 0; }
r[3]=read(ram,0x0c085bccu,4);
goto P_0c085ba2;
P_0c085ba2: /* original e200, guest PC 0x0c085ba2 */
if(!s->budget--) { s->failed_pc=0x0c085ba2u; return 0; }
r[2]=0x00000000u;
goto P_0c085ba4;
P_0c085ba4: /* original 430b, guest PC 0x0c085ba4 */
if(!s->budget--) { s->failed_pc=0x0c085ba4u; return 0; }
target=r[3];
r[16]=code_base|0x0c085ba8u;
write(ram,r[14]+r[0],r[2],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085ba8u) { target=s->pc; goto dispatch; }
goto P_0c085ba8;
P_0c085ba6: /* original 0e25, guest PC 0x0c085ba6 */
if(!s->budget--) { s->failed_pc=0x0c085ba6u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c085ba8;
P_0c085ba8: /* original 6403, guest PC 0x0c085ba8 */
if(!s->budget--) { s->failed_pc=0x0c085ba8u; return 0; }
r[4]=r[0];
goto P_0c085baa;
P_0c085baa: /* original e00e, guest PC 0x0c085baa */
if(!s->budget--) { s->failed_pc=0x0c085baau; return 0; }
r[0]=0x0000000eu;
goto P_0c085bac;
P_0c085bac: /* original 4400, guest PC 0x0c085bac */
if(!s->budget--) { s->failed_pc=0x0c085bacu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c085bae;
P_0c085bae: /* original 2049, guest PC 0x0c085bae */
if(!s->budget--) { s->failed_pc=0x0c085baeu; return 0; }
r[0]&=r[4];
goto P_0c085bb0;
P_0c085bb0: /* original d407, guest PC 0x0c085bb0 */
if(!s->budget--) { s->failed_pc=0x0c085bb0u; return 0; }
r[4]=read(ram,0x0c085bd0u,4);
goto P_0c085bb2;
P_0c085bb2: /* original 034d, guest PC 0x0c085bb2 */
if(!s->budget--) { s->failed_pc=0x0c085bb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c085bb4;
P_0c085bb4: /* original 9008, guest PC 0x0c085bb4 */
if(!s->budget--) { s->failed_pc=0x0c085bb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c085bc8u,2);
goto P_0c085bb6;
P_0c085bb6: /* original 6433, guest PC 0x0c085bb6 */
if(!s->budget--) { s->failed_pc=0x0c085bb6u; return 0; }
r[4]=r[3];
goto P_0c085bb8;
P_0c085bb8: /* original 0e45, guest PC 0x0c085bb8 */
if(!s->budget--) { s->failed_pc=0x0c085bb8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c085bba;
P_0c085bba: /* original 63f2, guest PC 0x0c085bba */
if(!s->budget--) { s->failed_pc=0x0c085bbau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c085bbc;
P_0c085bbc: /* original 2342, guest PC 0x0c085bbc */
if(!s->budget--) { s->failed_pc=0x0c085bbcu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c085bbe;
P_0c085bbe: /* original 7f04, guest PC 0x0c085bbe */
if(!s->budget--) { s->failed_pc=0x0c085bbeu; return 0; }
r[15]+=0x00000004u;
goto P_0c085bc0;
P_0c085bc0: /* original 4f26, guest PC 0x0c085bc0 */
if(!s->budget--) { s->failed_pc=0x0c085bc0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085bc2;
P_0c085bc2: /* original 000b, guest PC 0x0c085bc2 */
if(!s->budget--) { s->failed_pc=0x0c085bc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085bc4: /* original 6ef6, guest PC 0x0c085bc4 */
if(!s->budget--) { s->failed_pc=0x0c085bc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085bc6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085bc6u; return 0; } return 1;
P_0c085bd4: /* original 2fe6, guest PC 0x0c085bd4 */
if(!s->budget--) { s->failed_pc=0x0c085bd4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085bd6;
P_0c085bd6: /* original ee08, guest PC 0x0c085bd6 */
if(!s->budget--) { s->failed_pc=0x0c085bd6u; return 0; }
r[14]=0x00000008u;
goto P_0c085bd8;
P_0c085bd8: /* original 2fd6, guest PC 0x0c085bd8 */
if(!s->budget--) { s->failed_pc=0x0c085bd8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085bda;
P_0c085bda: /* original 6d43, guest PC 0x0c085bda */
if(!s->budget--) { s->failed_pc=0x0c085bdau; return 0; }
r[13]=r[4];
goto P_0c085bdc;
P_0c085bdc: /* original 2fc6, guest PC 0x0c085bdc */
if(!s->budget--) { s->failed_pc=0x0c085bdcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085bde;
P_0c085bde: /* original ec7f, guest PC 0x0c085bde */
if(!s->budget--) { s->failed_pc=0x0c085bdeu; return 0; }
r[12]=0x0000007fu;
goto P_0c085be0;
P_0c085be0: /* original 2fb6, guest PC 0x0c085be0 */
if(!s->budget--) { s->failed_pc=0x0c085be0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085be2;
P_0c085be2: /* original 4f22, guest PC 0x0c085be2 */
if(!s->budget--) { s->failed_pc=0x0c085be2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085be4;
P_0c085be4: /* original db25, guest PC 0x0c085be4 */
if(!s->budget--) { s->failed_pc=0x0c085be4u; return 0; }
r[11]=read(ram,0x0c085c7cu,4);
goto P_0c085be6;
P_0c085be6: /* original 4b0b, guest PC 0x0c085be6 */
if(!s->budget--) { s->failed_pc=0x0c085be6u; return 0; }
target=r[11];
r[16]=code_base|0x0c085beau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085beau) { target=s->pc; goto dispatch; }
goto P_0c085bea;
P_0c085be8: /* original 0009, guest PC 0x0c085be8 */
if(!s->budget--) { s->failed_pc=0x0c085be8u; return 0; }
goto P_0c085bea;
P_0c085bea: /* original 6403, guest PC 0x0c085bea */
if(!s->budget--) { s->failed_pc=0x0c085beau; return 0; }
r[4]=r[0];
goto P_0c085bec;
P_0c085bec: /* original 24c9, guest PC 0x0c085bec */
if(!s->budget--) { s->failed_pc=0x0c085becu; return 0; }
r[4]&=r[12];
goto P_0c085bee;
P_0c085bee: /* original 4e10, guest PC 0x0c085bee */
if(!s->budget--) { s->failed_pc=0x0c085beeu; return 0; }
--r[14];
r[17]=(r[17]&~1u)|((r[14]==0)!=0);
goto P_0c085bf0;
P_0c085bf0: /* original 2d41, guest PC 0x0c085bf0 */
if(!s->budget--) { s->failed_pc=0x0c085bf0u; return 0; }
write(ram,r[13],r[4],2);
goto P_0c085bf2;
P_0c085bf2: /* original 8ff8, guest PC 0x0c085bf2 */
if(!s->budget--) { s->failed_pc=0x0c085bf2u; return 0; }
cond=r[17]&1u;
r[13]+=0x00000004u;
if(!cond) { goto P_0c085be6; }
goto P_0c085bf6;
P_0c085bf4: /* original 7d04, guest PC 0x0c085bf4 */
if(!s->budget--) { s->failed_pc=0x0c085bf4u; return 0; }
r[13]+=0x00000004u;
goto P_0c085bf6;
P_0c085bf6: /* original 4f26, guest PC 0x0c085bf6 */
if(!s->budget--) { s->failed_pc=0x0c085bf6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085bf8;
P_0c085bf8: /* original 6bf6, guest PC 0x0c085bf8 */
if(!s->budget--) { s->failed_pc=0x0c085bf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085bfa;
P_0c085bfa: /* original 6cf6, guest PC 0x0c085bfa */
if(!s->budget--) { s->failed_pc=0x0c085bfau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085bfc;
P_0c085bfc: /* original 6df6, guest PC 0x0c085bfc */
if(!s->budget--) { s->failed_pc=0x0c085bfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085bfe;
P_0c085bfe: /* original 000b, guest PC 0x0c085bfe */
if(!s->budget--) { s->failed_pc=0x0c085bfeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c085c00: /* original 6ef6, guest PC 0x0c085c00 */
if(!s->budget--) { s->failed_pc=0x0c085c00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085c02u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085c02u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
