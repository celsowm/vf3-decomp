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
int vf3_away_batch81_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a99a6u: goto P_0c0a99a6;
case 0x0c0a99a8u: goto P_0c0a99a8;
case 0x0c0a99aau: goto P_0c0a99aa;
case 0x0c0a99acu: goto P_0c0a99ac;
case 0x0c0a99aeu: goto P_0c0a99ae;
case 0x0c0a99b0u: goto P_0c0a99b0;
case 0x0c0a99b2u: goto P_0c0a99b2;
case 0x0c0a99b4u: goto P_0c0a99b4;
case 0x0c0a99b6u: goto P_0c0a99b6;
case 0x0c0a99b8u: goto P_0c0a99b8;
case 0x0c0a99bau: goto P_0c0a99ba;
case 0x0c0a99bcu: goto P_0c0a99bc;
case 0x0c0a99beu: goto P_0c0a99be;
case 0x0c0a99c0u: goto P_0c0a99c0;
case 0x0c0a99c2u: goto P_0c0a99c2;
case 0x0c0a99c4u: goto P_0c0a99c4;
case 0x0c0a99c6u: goto P_0c0a99c6;
case 0x0c0a99c8u: goto P_0c0a99c8;
case 0x0c0a99cau: goto P_0c0a99ca;
case 0x0c0a9a00u: goto P_0c0a9a00;
case 0x0c0a9a02u: goto P_0c0a9a02;
case 0x0c0a9a04u: goto P_0c0a9a04;
case 0x0c0a9a06u: goto P_0c0a9a06;
case 0x0c0a9a08u: goto P_0c0a9a08;
case 0x0c0a9a0au: goto P_0c0a9a0a;
case 0x0c0a9a0cu: goto P_0c0a9a0c;
case 0x0c0a9a0eu: goto P_0c0a9a0e;
case 0x0c0a9a10u: goto P_0c0a9a10;
case 0x0c0a9a12u: goto P_0c0a9a12;
case 0x0c0a9a14u: goto P_0c0a9a14;
case 0x0c0a9a16u: goto P_0c0a9a16;
case 0x0c0a9a18u: goto P_0c0a9a18;
case 0x0c0a9a1au: goto P_0c0a9a1a;
case 0x0c0a9a1cu: goto P_0c0a9a1c;
case 0x0c0a9a1eu: goto P_0c0a9a1e;
case 0x0c0a9a20u: goto P_0c0a9a20;
case 0x0c0a9a22u: goto P_0c0a9a22;
case 0x0c0a9a24u: goto P_0c0a9a24;
case 0x0c0a9a26u: goto P_0c0a9a26;
case 0x0c0a9a28u: goto P_0c0a9a28;
case 0x0c0a9a2au: goto P_0c0a9a2a;
case 0x0c0a9a2cu: goto P_0c0a9a2c;
case 0x0c0a9a2eu: goto P_0c0a9a2e;
case 0x0c0a9a30u: goto P_0c0a9a30;
case 0x0c0a9a32u: goto P_0c0a9a32;
case 0x0c0a9a34u: goto P_0c0a9a34;
case 0x0c0a9a36u: goto P_0c0a9a36;
case 0x0c0a9a38u: goto P_0c0a9a38;
case 0x0c0a9a3au: goto P_0c0a9a3a;
case 0x0c0a9a3cu: goto P_0c0a9a3c;
case 0x0c0a9a3eu: goto P_0c0a9a3e;
case 0x0c0a9a40u: goto P_0c0a9a40;
case 0x0c0a9a42u: goto P_0c0a9a42;
case 0x0c0a9a44u: goto P_0c0a9a44;
case 0x0c0a9a46u: goto P_0c0a9a46;
case 0x0c0a9a48u: goto P_0c0a9a48;
case 0x0c0a9a4au: goto P_0c0a9a4a;
case 0x0c0a9a4cu: goto P_0c0a9a4c;
case 0x0c0a9a4eu: goto P_0c0a9a4e;
case 0x0c0a9a50u: goto P_0c0a9a50;
case 0x0c0a9a52u: goto P_0c0a9a52;
case 0x0c0a9a54u: goto P_0c0a9a54;
case 0x0c0a9a56u: goto P_0c0a9a56;
case 0x0c0a9a58u: goto P_0c0a9a58;
case 0x0c0a9a5au: goto P_0c0a9a5a;
case 0x0c0a9a5cu: goto P_0c0a9a5c;
case 0x0c0a9a5eu: goto P_0c0a9a5e;
case 0x0c0a9a60u: goto P_0c0a9a60;
case 0x0c0a9a62u: goto P_0c0a9a62;
case 0x0c0a9a64u: goto P_0c0a9a64;
case 0x0c0a9a66u: goto P_0c0a9a66;
case 0x0c0a9a68u: goto P_0c0a9a68;
case 0x0c0a9a6au: goto P_0c0a9a6a;
case 0x0c0a9a6cu: goto P_0c0a9a6c;
case 0x0c0a9a6eu: goto P_0c0a9a6e;
case 0x0c0a9a70u: goto P_0c0a9a70;
case 0x0c0a9a72u: goto P_0c0a9a72;
case 0x0c0a9a74u: goto P_0c0a9a74;
case 0x0c0a9a76u: goto P_0c0a9a76;
case 0x0c0a9a78u: goto P_0c0a9a78;
case 0x0c0a9a7au: goto P_0c0a9a7a;
case 0x0c0a9a7cu: goto P_0c0a9a7c;
case 0x0c0a9a7eu: goto P_0c0a9a7e;
case 0x0c0a9a80u: goto P_0c0a9a80;
case 0x0c0a9a82u: goto P_0c0a9a82;
case 0x0c0a9a84u: goto P_0c0a9a84;
case 0x0c0a9a86u: goto P_0c0a9a86;
case 0x0c0a9a88u: goto P_0c0a9a88;
case 0x0c0a9a8au: goto P_0c0a9a8a;
case 0x0c0a9a8cu: goto P_0c0a9a8c;
case 0x0c0a9a8eu: goto P_0c0a9a8e;
case 0x0c0a9a90u: goto P_0c0a9a90;
case 0x0c0a9a92u: goto P_0c0a9a92;
case 0x0c0a9a94u: goto P_0c0a9a94;
case 0x0c0a9a96u: goto P_0c0a9a96;
case 0x0c0a9a98u: goto P_0c0a9a98;
case 0x0c0a9a9au: goto P_0c0a9a9a;
case 0x0c0a9a9cu: goto P_0c0a9a9c;
case 0x0c0a9a9eu: goto P_0c0a9a9e;
case 0x0c0a9aa0u: goto P_0c0a9aa0;
case 0x0c0a9aa2u: goto P_0c0a9aa2;
case 0x0c0a9aa4u: goto P_0c0a9aa4;
case 0x0c0a9aa6u: goto P_0c0a9aa6;
case 0x0c0a9aa8u: goto P_0c0a9aa8;
case 0x0c0a9aaau: goto P_0c0a9aaa;
case 0x0c0a9aacu: goto P_0c0a9aac;
case 0x0c0a9aaeu: goto P_0c0a9aae;
case 0x0c0a9ab0u: goto P_0c0a9ab0;
case 0x0c0a9ab2u: goto P_0c0a9ab2;
case 0x0c0a9ab4u: goto P_0c0a9ab4;
case 0x0c0a9ab6u: goto P_0c0a9ab6;
case 0x0c0a9ab8u: goto P_0c0a9ab8;
case 0x0c0a9abau: goto P_0c0a9aba;
case 0x0c0a9abcu: goto P_0c0a9abc;
case 0x0c0a9abeu: goto P_0c0a9abe;
case 0x0c0a9ac0u: goto P_0c0a9ac0;
case 0x0c0a9ac2u: goto P_0c0a9ac2;
case 0x0c0a9ac4u: goto P_0c0a9ac4;
case 0x0c0a9ac6u: goto P_0c0a9ac6;
case 0x0c0a9ac8u: goto P_0c0a9ac8;
case 0x0c0a9acau: goto P_0c0a9aca;
case 0x0c0a9accu: goto P_0c0a9acc;
case 0x0c0a9aceu: goto P_0c0a9ace;
case 0x0c0a9ad0u: goto P_0c0a9ad0;
case 0x0c0a9ad2u: goto P_0c0a9ad2;
case 0x0c0a9ad4u: goto P_0c0a9ad4;
case 0x0c0a9ad6u: goto P_0c0a9ad6;
case 0x0c0a9ad8u: goto P_0c0a9ad8;
case 0x0c0a9adau: goto P_0c0a9ada;
case 0x0c0a9adcu: goto P_0c0a9adc;
case 0x0c0a9adeu: goto P_0c0a9ade;
case 0x0c0a9ae0u: goto P_0c0a9ae0;
case 0x0c0a9ae2u: goto P_0c0a9ae2;
case 0x0c0a9ae4u: goto P_0c0a9ae4;
case 0x0c0a9ae6u: goto P_0c0a9ae6;
case 0x0c0a9ae8u: goto P_0c0a9ae8;
case 0x0c0a9aeau: goto P_0c0a9aea;
case 0x0c0a9aecu: goto P_0c0a9aec;
case 0x0c0a9aeeu: goto P_0c0a9aee;
case 0x0c0a9af0u: goto P_0c0a9af0;
case 0x0c0a9af2u: goto P_0c0a9af2;
case 0x0c0a9af4u: goto P_0c0a9af4;
case 0x0c0a9af6u: goto P_0c0a9af6;
case 0x0c0a9af8u: goto P_0c0a9af8;
case 0x0c0a9afau: goto P_0c0a9afa;
case 0x0c0a9afcu: goto P_0c0a9afc;
case 0x0c0a9afeu: goto P_0c0a9afe;
case 0x0c0a9b00u: goto P_0c0a9b00;
case 0x0c0a9b3cu: goto P_0c0a9b3c;
case 0x0c0a9b3eu: goto P_0c0a9b3e;
case 0x0c0a9b40u: goto P_0c0a9b40;
case 0x0c0a9b42u: goto P_0c0a9b42;
case 0x0c0a9b44u: goto P_0c0a9b44;
case 0x0c0a9b46u: goto P_0c0a9b46;
case 0x0c0a9b48u: goto P_0c0a9b48;
case 0x0c0a9b4au: goto P_0c0a9b4a;
case 0x0c0a9b4cu: goto P_0c0a9b4c;
case 0x0c0a9b4eu: goto P_0c0a9b4e;
case 0x0c0a9b50u: goto P_0c0a9b50;
case 0x0c0a9b52u: goto P_0c0a9b52;
case 0x0c0a9b54u: goto P_0c0a9b54;
case 0x0c0a9b56u: goto P_0c0a9b56;
case 0x0c0a9b58u: goto P_0c0a9b58;
case 0x0c0a9b5au: goto P_0c0a9b5a;
case 0x0c0a9b5cu: goto P_0c0a9b5c;
case 0x0c0a9b5eu: goto P_0c0a9b5e;
case 0x0c0a9b60u: goto P_0c0a9b60;
case 0x0c0a9b62u: goto P_0c0a9b62;
case 0x0c0a9b64u: goto P_0c0a9b64;
case 0x0c0a9b66u: goto P_0c0a9b66;
case 0x0c0a9b68u: goto P_0c0a9b68;
case 0x0c0a9b6au: goto P_0c0a9b6a;
case 0x0c0a9b6cu: goto P_0c0a9b6c;
case 0x0c0a9b6eu: goto P_0c0a9b6e;
case 0x0c0a9b70u: goto P_0c0a9b70;
case 0x0c0a9b72u: goto P_0c0a9b72;
case 0x0c0a9b74u: goto P_0c0a9b74;
case 0x0c0a9b76u: goto P_0c0a9b76;
case 0x0c0a9b78u: goto P_0c0a9b78;
case 0x0c0a9b7au: goto P_0c0a9b7a;
case 0x0c0a9b7cu: goto P_0c0a9b7c;
case 0x0c0a9b7eu: goto P_0c0a9b7e;
case 0x0c0a9b80u: goto P_0c0a9b80;
case 0x0c0a9b82u: goto P_0c0a9b82;
case 0x0c0a9b84u: goto P_0c0a9b84;
case 0x0c0a9b86u: goto P_0c0a9b86;
case 0x0c0a9b88u: goto P_0c0a9b88;
case 0x0c0a9b8au: goto P_0c0a9b8a;
case 0x0c0a9b8cu: goto P_0c0a9b8c;
case 0x0c0a9b8eu: goto P_0c0a9b8e;
case 0x0c0a9b90u: goto P_0c0a9b90;
case 0x0c0a9b92u: goto P_0c0a9b92;
case 0x0c0a9b94u: goto P_0c0a9b94;
case 0x0c0a9b96u: goto P_0c0a9b96;
case 0x0c0a9b98u: goto P_0c0a9b98;
case 0x0c0a9b9au: goto P_0c0a9b9a;
case 0x0c0a9b9cu: goto P_0c0a9b9c;
case 0x0c0a9b9eu: goto P_0c0a9b9e;
case 0x0c0a9ba0u: goto P_0c0a9ba0;
case 0x0c0a9ba2u: goto P_0c0a9ba2;
case 0x0c0a9ba4u: goto P_0c0a9ba4;
case 0x0c0a9ba6u: goto P_0c0a9ba6;
case 0x0c0a9ba8u: goto P_0c0a9ba8;
case 0x0c0a9baau: goto P_0c0a9baa;
case 0x0c0a9bacu: goto P_0c0a9bac;
case 0x0c0a9baeu: goto P_0c0a9bae;
case 0x0c0a9bb0u: goto P_0c0a9bb0;
case 0x0c0a9bb2u: goto P_0c0a9bb2;
case 0x0c0a9bb4u: goto P_0c0a9bb4;
case 0x0c0a9bb6u: goto P_0c0a9bb6;
case 0x0c0a9bb8u: goto P_0c0a9bb8;
case 0x0c0a9bbau: goto P_0c0a9bba;
case 0x0c0a9bbcu: goto P_0c0a9bbc;
case 0x0c0a9bbeu: goto P_0c0a9bbe;
case 0x0c0a9bc0u: goto P_0c0a9bc0;
case 0x0c0a9bc2u: goto P_0c0a9bc2;
case 0x0c0a9bc4u: goto P_0c0a9bc4;
case 0x0c0a9bc6u: goto P_0c0a9bc6;
case 0x0c0a9bc8u: goto P_0c0a9bc8;
case 0x0c0a9bcau: goto P_0c0a9bca;
case 0x0c0a9bccu: goto P_0c0a9bcc;
case 0x0c0a9bceu: goto P_0c0a9bce;
case 0x0c0a9bd0u: goto P_0c0a9bd0;
case 0x0c0a9bd2u: goto P_0c0a9bd2;
case 0x0c0a9bd4u: goto P_0c0a9bd4;
case 0x0c0a9bd6u: goto P_0c0a9bd6;
case 0x0c0a9bd8u: goto P_0c0a9bd8;
case 0x0c0a9bdau: goto P_0c0a9bda;
case 0x0c0a9bdcu: goto P_0c0a9bdc;
case 0x0c0a9bdeu: goto P_0c0a9bde;
case 0x0c0a9be0u: goto P_0c0a9be0;
case 0x0c0a9be2u: goto P_0c0a9be2;
case 0x0c0a9be4u: goto P_0c0a9be4;
case 0x0c0a9be6u: goto P_0c0a9be6;
case 0x0c0a9be8u: goto P_0c0a9be8;
case 0x0c0a9beau: goto P_0c0a9bea;
case 0x0c0a9becu: goto P_0c0a9bec;
case 0x0c0a9beeu: goto P_0c0a9bee;
case 0x0c0a9bf0u: goto P_0c0a9bf0;
case 0x0c0a9bf2u: goto P_0c0a9bf2;
case 0x0c0a9bf4u: goto P_0c0a9bf4;
case 0x0c0a9bf6u: goto P_0c0a9bf6;
case 0x0c0a9bf8u: goto P_0c0a9bf8;
case 0x0c0a9bfau: goto P_0c0a9bfa;
case 0x0c0a9bfcu: goto P_0c0a9bfc;
case 0x0c0a9bfeu: goto P_0c0a9bfe;
case 0x0c0a9c00u: goto P_0c0a9c00;
case 0x0c0a9c02u: goto P_0c0a9c02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a99a6: /* original 2fe6, guest PC 0x0c0a99a6 */
if(!s->budget--) { s->failed_pc=0x0c0a99a6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a99a8;
P_0c0a99a8: /* original 2fd6, guest PC 0x0c0a99a8 */
if(!s->budget--) { s->failed_pc=0x0c0a99a8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a99aa;
P_0c0a99aa: /* original 4f22, guest PC 0x0c0a99aa */
if(!s->budget--) { s->failed_pc=0x0c0a99aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a99ac;
P_0c0a99ac: /* original d311, guest PC 0x0c0a99ac */
if(!s->budget--) { s->failed_pc=0x0c0a99acu; return 0; }
r[3]=read(ram,0x0c0a99f4u,4);
goto P_0c0a99ae;
P_0c0a99ae: /* original 7ff8, guest PC 0x0c0a99ae */
if(!s->budget--) { s->failed_pc=0x0c0a99aeu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a99b0;
P_0c0a99b0: /* original 1f31, guest PC 0x0c0a99b0 */
if(!s->budget--) { s->failed_pc=0x0c0a99b0u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0a99b2;
P_0c0a99b2: /* original d311, guest PC 0x0c0a99b2 */
if(!s->budget--) { s->failed_pc=0x0c0a99b2u; return 0; }
r[3]=read(ram,0x0c0a99f8u,4);
goto P_0c0a99b4;
P_0c0a99b4: /* original 430b, guest PC 0x0c0a99b4 */
if(!s->budget--) { s->failed_pc=0x0c0a99b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a99b8u;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a99b8u) { target=s->pc; goto dispatch; }
goto P_0c0a99b8;
P_0c0a99b6: /* original 6e43, guest PC 0x0c0a99b6 */
if(!s->budget--) { s->failed_pc=0x0c0a99b6u; return 0; }
r[14]=r[4];
goto P_0c0a99b8;
P_0c0a99b8: /* original 2008, guest PC 0x0c0a99b8 */
if(!s->budget--) { s->failed_pc=0x0c0a99b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a99ba;
P_0c0a99ba: /* original 8b01, guest PC 0x0c0a99ba */
if(!s->budget--) { s->failed_pc=0x0c0a99bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a99c0; }
goto P_0c0a99bc;
P_0c0a99bc: /* original a11d, guest PC 0x0c0a99bc */
if(!s->budget--) { s->failed_pc=0x0c0a99bcu; return 0; }
goto P_0c0a9bfa;
P_0c0a99be: /* original 0009, guest PC 0x0c0a99be */
if(!s->budget--) { s->failed_pc=0x0c0a99beu; return 0; }
goto P_0c0a99c0;
P_0c0a99c0: /* original 84e4, guest PC 0x0c0a99c0 */
if(!s->budget--) { s->failed_pc=0x0c0a99c0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a99c2;
P_0c0a99c2: /* original d40e, guest PC 0x0c0a99c2 */
if(!s->budget--) { s->failed_pc=0x0c0a99c2u; return 0; }
r[4]=read(ram,0x0c0a99fcu,4);
goto P_0c0a99c4;
P_0c0a99c4: /* original 2008, guest PC 0x0c0a99c4 */
if(!s->budget--) { s->failed_pc=0x0c0a99c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a99c6;
P_0c0a99c6: /* original 891b, guest PC 0x0c0a99c6 */
if(!s->budget--) { s->failed_pc=0x0c0a99c6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9a00; }
goto P_0c0a99c8;
P_0c0a99c8: /* original a01b, guest PC 0x0c0a99c8 */
if(!s->budget--) { s->failed_pc=0x0c0a99c8u; return 0; }
r[13]=read(ram,r[4]+16,4);
goto P_0c0a9a02;
P_0c0a99ca: /* original 5d44, guest PC 0x0c0a99ca */
if(!s->budget--) { s->failed_pc=0x0c0a99cau; return 0; }
r[13]=read(ram,r[4]+16,4);
if(!vf3_matrix_family(0x0c0a99ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a99ccu; return 0; } return 1;
P_0c0a9a00: /* original 5d45, guest PC 0x0c0a9a00 */
if(!s->budget--) { s->failed_pc=0x0c0a9a00u; return 0; }
r[13]=read(ram,r[4]+20,4);
goto P_0c0a9a02;
P_0c0a9a02: /* original d146, guest PC 0x0c0a9a02 */
if(!s->budget--) { s->failed_pc=0x0c0a9a02u; return 0; }
r[1]=read(ram,0x0c0a9b1cu,4);
goto P_0c0a9a04;
P_0c0a9a04: /* original d344, guest PC 0x0c0a9a04 */
if(!s->budget--) { s->failed_pc=0x0c0a9a04u; return 0; }
r[3]=read(ram,0x0c0a9b18u,4);
goto P_0c0a9a06;
P_0c0a9a06: /* original 6212, guest PC 0x0c0a9a06 */
if(!s->budget--) { s->failed_pc=0x0c0a9a06u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0a9a08;
P_0c0a9a08: /* original 2238, guest PC 0x0c0a9a08 */
if(!s->budget--) { s->failed_pc=0x0c0a9a08u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9a0a;
P_0c0a9a0a: /* original 8901, guest PC 0x0c0a9a0a */
if(!s->budget--) { s->failed_pc=0x0c0a9a0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9a10; }
goto P_0c0a9a0c;
P_0c0a9a0c: /* original a0eb, guest PC 0x0c0a9a0c */
if(!s->budget--) { s->failed_pc=0x0c0a9a0cu; return 0; }
goto P_0c0a9be6;
P_0c0a9a0e: /* original 0009, guest PC 0x0c0a9a0e */
if(!s->budget--) { s->failed_pc=0x0c0a9a0eu; return 0; }
goto P_0c0a9a10;
P_0c0a9a10: /* original 9177, guest PC 0x0c0a9a10 */
if(!s->budget--) { s->failed_pc=0x0c0a9a10u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b02u,2);
goto P_0c0a9a12;
P_0c0a9a12: /* original 60e2, guest PC 0x0c0a9a12 */
if(!s->budget--) { s->failed_pc=0x0c0a9a12u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0a9a14;
P_0c0a9a14: /* original 31ec, guest PC 0x0c0a9a14 */
if(!s->budget--) { s->failed_pc=0x0c0a9a14u; return 0; }
r[1]+=r[14];
goto P_0c0a9a16;
P_0c0a9a16: /* original 2102, guest PC 0x0c0a9a16 */
if(!s->budget--) { s->failed_pc=0x0c0a9a16u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0a9a18;
P_0c0a9a18: /* original e048, guest PC 0x0c0a9a18 */
if(!s->budget--) { s->failed_pc=0x0c0a9a18u; return 0; }
r[0]=0x00000048u;
goto P_0c0a9a1a;
P_0c0a9a1a: /* original 03ee, guest PC 0x0c0a9a1a */
if(!s->budget--) { s->failed_pc=0x0c0a9a1au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0a9a1c;
P_0c0a9a1c: /* original 9072, guest PC 0x0c0a9a1c */
if(!s->budget--) { s->failed_pc=0x0c0a9a1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b04u,2);
goto P_0c0a9a1e;
P_0c0a9a1e: /* original 0e36, guest PC 0x0c0a9a1e */
if(!s->budget--) { s->failed_pc=0x0c0a9a1eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0a9a20;
P_0c0a9a20: /* original 84e4, guest PC 0x0c0a9a20 */
if(!s->budget--) { s->failed_pc=0x0c0a9a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0a9a22;
P_0c0a9a22: /* original 2008, guest PC 0x0c0a9a22 */
if(!s->budget--) { s->failed_pc=0x0c0a9a22u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a9a24;
P_0c0a9a24: /* original 8902, guest PC 0x0c0a9a24 */
if(!s->budget--) { s->failed_pc=0x0c0a9a24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9a2c; }
goto P_0c0a9a26;
P_0c0a9a26: /* original 60d2, guest PC 0x0c0a9a26 */
if(!s->budget--) { s->failed_pc=0x0c0a9a26u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a9a28;
P_0c0a9a28: /* original c801, guest PC 0x0c0a9a28 */
if(!s->budget--) { s->failed_pc=0x0c0a9a28u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a9a2a;
P_0c0a9a2a: /* original 8b02, guest PC 0x0c0a9a2a */
if(!s->budget--) { s->failed_pc=0x0c0a9a2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9a32; }
goto P_0c0a9a2c;
P_0c0a9a2c: /* original 65d3, guest PC 0x0c0a9a2c */
if(!s->budget--) { s->failed_pc=0x0c0a9a2cu; return 0; }
r[5]=r[13];
goto P_0c0a9a2e;
P_0c0a9a2e: /* original b105, guest PC 0x0c0a9a2e */
if(!s->budget--) { s->failed_pc=0x0c0a9a2eu; return 0; }
target=code_base|0x0c0a9c3cu; r[16]=code_base|0x0c0a9a32u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9a32u) { target=s->pc; goto dispatch; }
goto P_0c0a9a32;
P_0c0a9a30: /* original 64e3, guest PC 0x0c0a9a30 */
if(!s->budget--) { s->failed_pc=0x0c0a9a30u; return 0; }
r[4]=r[14];
goto P_0c0a9a32;
P_0c0a9a32: /* original d23b, guest PC 0x0c0a9a32 */
if(!s->budget--) { s->failed_pc=0x0c0a9a32u; return 0; }
r[2]=read(ram,0x0c0a9b20u,4);
goto P_0c0a9a34;
P_0c0a9a34: /* original 65e2, guest PC 0x0c0a9a34 */
if(!s->budget--) { s->failed_pc=0x0c0a9a34u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0a9a36;
P_0c0a9a36: /* original d33b, guest PC 0x0c0a9a36 */
if(!s->budget--) { s->failed_pc=0x0c0a9a36u; return 0; }
r[3]=read(ram,0x0c0a9b24u,4);
goto P_0c0a9a38;
P_0c0a9a38: /* original 2529, guest PC 0x0c0a9a38 */
if(!s->budget--) { s->failed_pc=0x0c0a9a38u; return 0; }
r[5]&=r[2];
goto P_0c0a9a3a;
P_0c0a9a3a: /* original 2358, guest PC 0x0c0a9a3a */
if(!s->budget--) { s->failed_pc=0x0c0a9a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0a9a3c;
P_0c0a9a3c: /* original 8b01, guest PC 0x0c0a9a3c */
if(!s->budget--) { s->failed_pc=0x0c0a9a3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9a42; }
goto P_0c0a9a3e;
P_0c0a9a3e: /* original a0af, guest PC 0x0c0a9a3e */
if(!s->budget--) { s->failed_pc=0x0c0a9a3eu; return 0; }
goto P_0c0a9ba0;
P_0c0a9a40: /* original 0009, guest PC 0x0c0a9a40 */
if(!s->budget--) { s->failed_pc=0x0c0a9a40u; return 0; }
goto P_0c0a9a42;
P_0c0a9a42: /* original e044, guest PC 0x0c0a9a42 */
if(!s->budget--) { s->failed_pc=0x0c0a9a42u; return 0; }
r[0]=0x00000044u;
goto P_0c0a9a44;
P_0c0a9a44: /* original 03ed, guest PC 0x0c0a9a44 */
if(!s->budget--) { s->failed_pc=0x0c0a9a44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a46;
P_0c0a9a46: /* original 7301, guest PC 0x0c0a9a46 */
if(!s->budget--) { s->failed_pc=0x0c0a9a46u; return 0; }
r[3]+=0x00000001u;
goto P_0c0a9a48;
P_0c0a9a48: /* original 0e35, guest PC 0x0c0a9a48 */
if(!s->budget--) { s->failed_pc=0x0c0a9a48u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a9a4a;
P_0c0a9a4a: /* original e03e, guest PC 0x0c0a9a4a */
if(!s->budget--) { s->failed_pc=0x0c0a9a4au; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9a4c;
P_0c0a9a4c: /* original 04ed, guest PC 0x0c0a9a4c */
if(!s->budget--) { s->failed_pc=0x0c0a9a4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a4e;
P_0c0a9a4e: /* original e040, guest PC 0x0c0a9a4e */
if(!s->budget--) { s->failed_pc=0x0c0a9a4eu; return 0; }
r[0]=0x00000040u;
goto P_0c0a9a50;
P_0c0a9a50: /* original 06ed, guest PC 0x0c0a9a50 */
if(!s->budget--) { s->failed_pc=0x0c0a9a50u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a52;
P_0c0a9a52: /* original e042, guest PC 0x0c0a9a52 */
if(!s->budget--) { s->failed_pc=0x0c0a9a52u; return 0; }
r[0]=0x00000042u;
goto P_0c0a9a54;
P_0c0a9a54: /* original 07ed, guest PC 0x0c0a9a54 */
if(!s->budget--) { s->failed_pc=0x0c0a9a54u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a56;
P_0c0a9a56: /* original e03c, guest PC 0x0c0a9a56 */
if(!s->budget--) { s->failed_pc=0x0c0a9a56u; return 0; }
r[0]=0x0000003cu;
goto P_0c0a9a58;
P_0c0a9a58: /* original 03ed, guest PC 0x0c0a9a58 */
if(!s->budget--) { s->failed_pc=0x0c0a9a58u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a5a;
P_0c0a9a5a: /* original 644d, guest PC 0x0c0a9a5a */
if(!s->budget--) { s->failed_pc=0x0c0a9a5au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9a5c;
P_0c0a9a5c: /* original 666d, guest PC 0x0c0a9a5c */
if(!s->budget--) { s->failed_pc=0x0c0a9a5cu; return 0; }
r[6]=r[6]&65535u;
goto P_0c0a9a5e;
P_0c0a9a5e: /* original 633d, guest PC 0x0c0a9a5e */
if(!s->budget--) { s->failed_pc=0x0c0a9a5eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a9a60;
P_0c0a9a60: /* original 2f32, guest PC 0x0c0a9a60 */
if(!s->budget--) { s->failed_pc=0x0c0a9a60u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0a9a62;
P_0c0a9a62: /* original 677d, guest PC 0x0c0a9a62 */
if(!s->budget--) { s->failed_pc=0x0c0a9a62u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0a9a64;
P_0c0a9a64: /* original 904f, guest PC 0x0c0a9a64 */
if(!s->budget--) { s->failed_pc=0x0c0a9a64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b06u,2);
goto P_0c0a9a66;
P_0c0a9a66: /* original 4718, guest PC 0x0c0a9a66 */
if(!s->budget--) { s->failed_pc=0x0c0a9a66u; return 0; }
r[7]<<=8;
goto P_0c0a9a68;
P_0c0a9a68: /* original 0e45, guest PC 0x0c0a9a68 */
if(!s->budget--) { s->failed_pc=0x0c0a9a68u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9a6a;
P_0c0a9a6a: /* original 4428, guest PC 0x0c0a9a6a */
if(!s->budget--) { s->failed_pc=0x0c0a9a6au; return 0; }
r[4]<<=16;
goto P_0c0a9a6c;
P_0c0a9a6c: /* original 904c, guest PC 0x0c0a9a6c */
if(!s->budget--) { s->failed_pc=0x0c0a9a6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b08u,2);
goto P_0c0a9a6e;
P_0c0a9a6e: /* original 246b, guest PC 0x0c0a9a6e */
if(!s->budget--) { s->failed_pc=0x0c0a9a6eu; return 0; }
r[4]|=r[6];
goto P_0c0a9a70;
P_0c0a9a70: /* original 347c, guest PC 0x0c0a9a70 */
if(!s->budget--) { s->failed_pc=0x0c0a9a70u; return 0; }
r[4]+=r[7];
goto P_0c0a9a72;
P_0c0a9a72: /* original 0e65, guest PC 0x0c0a9a72 */
if(!s->budget--) { s->failed_pc=0x0c0a9a72u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0a9a74;
P_0c0a9a74: /* original 9049, guest PC 0x0c0a9a74 */
if(!s->budget--) { s->failed_pc=0x0c0a9a74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b0au,2);
goto P_0c0a9a76;
P_0c0a9a76: /* original 63f2, guest PC 0x0c0a9a76 */
if(!s->budget--) { s->failed_pc=0x0c0a9a76u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a9a78;
P_0c0a9a78: /* original 0e35, guest PC 0x0c0a9a78 */
if(!s->budget--) { s->failed_pc=0x0c0a9a78u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a9a7a;
P_0c0a9a7a: /* original e040, guest PC 0x0c0a9a7a */
if(!s->budget--) { s->failed_pc=0x0c0a9a7au; return 0; }
r[0]=0x00000040u;
goto P_0c0a9a7c;
P_0c0a9a7c: /* original 0e45, guest PC 0x0c0a9a7c */
if(!s->budget--) { s->failed_pc=0x0c0a9a7cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9a7e;
P_0c0a9a7e: /* original e03e, guest PC 0x0c0a9a7e */
if(!s->budget--) { s->failed_pc=0x0c0a9a7eu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9a80;
P_0c0a9a80: /* original 4429, guest PC 0x0c0a9a80 */
if(!s->budget--) { s->failed_pc=0x0c0a9a80u; return 0; }
r[4]>>=16;
goto P_0c0a9a82;
P_0c0a9a82: /* original 0e45, guest PC 0x0c0a9a82 */
if(!s->budget--) { s->failed_pc=0x0c0a9a82u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9a84;
P_0c0a9a84: /* original 9042, guest PC 0x0c0a9a84 */
if(!s->budget--) { s->failed_pc=0x0c0a9a84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b0cu,2);
goto P_0c0a9a86;
P_0c0a9a86: /* original 07ed, guest PC 0x0c0a9a86 */
if(!s->budget--) { s->failed_pc=0x0c0a9a86u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a88;
P_0c0a9a88: /* original 677d, guest PC 0x0c0a9a88 */
if(!s->budget--) { s->failed_pc=0x0c0a9a88u; return 0; }
r[7]=r[7]&65535u;
goto P_0c0a9a8a;
P_0c0a9a8a: /* original 3472, guest PC 0x0c0a9a8a */
if(!s->budget--) { s->failed_pc=0x0c0a9a8au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[7])!=0);
goto P_0c0a9a8c;
P_0c0a9a8c: /* original 8f10, guest PC 0x0c0a9a8c */
if(!s->budget--) { s->failed_pc=0x0c0a9a8cu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(!cond) { goto P_0c0a9ab0; }
goto P_0c0a9a90;
P_0c0a9a8e: /* original e600, guest PC 0x0c0a9a8e */
if(!s->budget--) { s->failed_pc=0x0c0a9a8eu; return 0; }
r[6]=0x00000000u;
goto P_0c0a9a90;
P_0c0a9a90: /* original 3476, guest PC 0x0c0a9a90 */
if(!s->budget--) { s->failed_pc=0x0c0a9a90u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[7])!=0);
goto P_0c0a9a92;
P_0c0a9a92: /* original 8905, guest PC 0x0c0a9a92 */
if(!s->budget--) { s->failed_pc=0x0c0a9a92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9aa0; }
goto P_0c0a9a94;
P_0c0a9a94: /* original e040, guest PC 0x0c0a9a94 */
if(!s->budget--) { s->failed_pc=0x0c0a9a94u; return 0; }
r[0]=0x00000040u;
goto P_0c0a9a96;
P_0c0a9a96: /* original 04ed, guest PC 0x0c0a9a96 */
if(!s->budget--) { s->failed_pc=0x0c0a9a96u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9a98;
P_0c0a9a98: /* original 644d, guest PC 0x0c0a9a98 */
if(!s->budget--) { s->failed_pc=0x0c0a9a98u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9a9a;
P_0c0a9a9a: /* original 2448, guest PC 0x0c0a9a9a */
if(!s->budget--) { s->failed_pc=0x0c0a9a9au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9a9c;
P_0c0a9a9c: /* original 8908, guest PC 0x0c0a9a9c */
if(!s->budget--) { s->failed_pc=0x0c0a9a9cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9ab0; }
goto P_0c0a9a9e;
P_0c0a9a9e: /* original 0e65, guest PC 0x0c0a9a9e */
if(!s->budget--) { s->failed_pc=0x0c0a9a9eu; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c0a9aa0;
P_0c0a9aa0: /* original 9035, guest PC 0x0c0a9aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a9aa0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b0eu,2);
goto P_0c0a9aa2;
P_0c0a9aa2: /* original d321, guest PC 0x0c0a9aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a9aa2u; return 0; }
r[3]=read(ram,0x0c0a9b28u,4);
goto P_0c0a9aa4;
P_0c0a9aa4: /* original 02ed, guest PC 0x0c0a9aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a9aa4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9aa6;
P_0c0a9aa6: /* original 2228, guest PC 0x0c0a9aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a9aa6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a9aa8;
P_0c0a9aa8: /* original 8f02, guest PC 0x0c0a9aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a9aa8u; return 0; }
cond=r[17]&1u;
r[5]|=r[3];
if(!cond) { goto P_0c0a9ab0; }
goto P_0c0a9aac;
P_0c0a9aaa: /* original 253b, guest PC 0x0c0a9aaa */
if(!s->budget--) { s->failed_pc=0x0c0a9aaau; return 0; }
r[5]|=r[3];
goto P_0c0a9aac;
P_0c0a9aac: /* original 9230, guest PC 0x0c0a9aac */
if(!s->budget--) { s->failed_pc=0x0c0a9aacu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b10u,2);
goto P_0c0a9aae;
P_0c0a9aae: /* original 252b, guest PC 0x0c0a9aae */
if(!s->budget--) { s->failed_pc=0x0c0a9aaeu; return 0; }
r[5]|=r[2];
goto P_0c0a9ab0;
P_0c0a9ab0: /* original 53f1, guest PC 0x0c0a9ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ab0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a9ab2;
P_0c0a9ab2: /* original d21f, guest PC 0x0c0a9ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ab2u; return 0; }
r[2]=read(ram,0x0c0a9b30u,4);
goto P_0c0a9ab4;
P_0c0a9ab4: /* original 6132, guest PC 0x0c0a9ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ab4u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c0a9ab6;
P_0c0a9ab6: /* original d71d, guest PC 0x0c0a9ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ab6u; return 0; }
r[7]=read(ram,0x0c0a9b2cu,4);
goto P_0c0a9ab8;
P_0c0a9ab8: /* original 2128, guest PC 0x0c0a9ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ab8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0a9aba;
P_0c0a9aba: /* original 8b61, guest PC 0x0c0a9aba */
if(!s->budget--) { s->failed_pc=0x0c0a9abau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9b80; }
goto P_0c0a9abc;
P_0c0a9abc: /* original e04c, guest PC 0x0c0a9abc */
if(!s->budget--) { s->failed_pc=0x0c0a9abcu; return 0; }
r[0]=0x0000004cu;
goto P_0c0a9abe;
P_0c0a9abe: /* original d31d, guest PC 0x0c0a9abe */
if(!s->budget--) { s->failed_pc=0x0c0a9abeu; return 0; }
r[3]=read(ram,0x0c0a9b34u,4);
goto P_0c0a9ac0;
P_0c0a9ac0: /* original 00ee, guest PC 0x0c0a9ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ac0u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0a9ac2;
P_0c0a9ac2: /* original 2038, guest PC 0x0c0a9ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ac2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c0a9ac4;
P_0c0a9ac4: /* original 8b09, guest PC 0x0c0a9ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ac4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9ada; }
goto P_0c0a9ac6;
P_0c0a9ac6: /* original e048, guest PC 0x0c0a9ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ac6u; return 0; }
r[0]=0x00000048u;
goto P_0c0a9ac8;
P_0c0a9ac8: /* original d31b, guest PC 0x0c0a9ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ac8u; return 0; }
r[3]=read(ram,0x0c0a9b38u,4);
goto P_0c0a9aca;
P_0c0a9aca: /* original 02ee, guest PC 0x0c0a9aca */
if(!s->budget--) { s->failed_pc=0x0c0a9acau; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0a9acc;
P_0c0a9acc: /* original 2238, guest PC 0x0c0a9acc */
if(!s->budget--) { s->failed_pc=0x0c0a9accu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9ace;
P_0c0a9ace: /* original 8b04, guest PC 0x0c0a9ace */
if(!s->budget--) { s->failed_pc=0x0c0a9aceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9ada; }
goto P_0c0a9ad0;
P_0c0a9ad0: /* original 901f, guest PC 0x0c0a9ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ad0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b12u,2);
goto P_0c0a9ad2;
P_0c0a9ad2: /* original 04ed, guest PC 0x0c0a9ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ad2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9ad4;
P_0c0a9ad4: /* original 74ff, guest PC 0x0c0a9ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ad4u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9ad6;
P_0c0a9ad6: /* original 4411, guest PC 0x0c0a9ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ad6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a9ad8;
P_0c0a9ad8: /* original 8900, guest PC 0x0c0a9ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ad8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9adc; }
goto P_0c0a9ada;
P_0c0a9ada: /* original 6463, guest PC 0x0c0a9ada */
if(!s->budget--) { s->failed_pc=0x0c0a9adau; return 0; }
r[4]=r[6];
goto P_0c0a9adc;
P_0c0a9adc: /* original 9019, guest PC 0x0c0a9adc */
if(!s->budget--) { s->failed_pc=0x0c0a9adcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b12u,2);
goto P_0c0a9ade;
P_0c0a9ade: /* original 0e45, guest PC 0x0c0a9ade */
if(!s->budget--) { s->failed_pc=0x0c0a9adeu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9ae0;
P_0c0a9ae0: /* original 9018, guest PC 0x0c0a9ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ae0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b14u,2);
goto P_0c0a9ae2;
P_0c0a9ae2: /* original 04ed, guest PC 0x0c0a9ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ae2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9ae4;
P_0c0a9ae4: /* original 74ff, guest PC 0x0c0a9ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ae4u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9ae6;
P_0c0a9ae6: /* original 4411, guest PC 0x0c0a9ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ae6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a9ae8;
P_0c0a9ae8: /* original 8900, guest PC 0x0c0a9ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ae8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9aec; }
goto P_0c0a9aea;
P_0c0a9aea: /* original 6463, guest PC 0x0c0a9aea */
if(!s->budget--) { s->failed_pc=0x0c0a9aeau; return 0; }
r[4]=r[6];
goto P_0c0a9aec;
P_0c0a9aec: /* original 0e45, guest PC 0x0c0a9aec */
if(!s->budget--) { s->failed_pc=0x0c0a9aecu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9aee;
P_0c0a9aee: /* original 70fc, guest PC 0x0c0a9aee */
if(!s->budget--) { s->failed_pc=0x0c0a9aeeu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0a9af0;
P_0c0a9af0: /* original 04ed, guest PC 0x0c0a9af0 */
if(!s->budget--) { s->failed_pc=0x0c0a9af0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9af2;
P_0c0a9af2: /* original 74ff, guest PC 0x0c0a9af2 */
if(!s->budget--) { s->failed_pc=0x0c0a9af2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9af4;
P_0c0a9af4: /* original 4411, guest PC 0x0c0a9af4 */
if(!s->budget--) { s->failed_pc=0x0c0a9af4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a9af6;
P_0c0a9af6: /* original 8900, guest PC 0x0c0a9af6 */
if(!s->budget--) { s->failed_pc=0x0c0a9af6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9afa; }
goto P_0c0a9af8;
P_0c0a9af8: /* original 6463, guest PC 0x0c0a9af8 */
if(!s->budget--) { s->failed_pc=0x0c0a9af8u; return 0; }
r[4]=r[6];
goto P_0c0a9afa;
P_0c0a9afa: /* original 900c, guest PC 0x0c0a9afa */
if(!s->budget--) { s->failed_pc=0x0c0a9afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9b16u,2);
goto P_0c0a9afc;
P_0c0a9afc: /* original 0e45, guest PC 0x0c0a9afc */
if(!s->budget--) { s->failed_pc=0x0c0a9afcu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9afe;
P_0c0a9afe: /* original a01d, guest PC 0x0c0a9afe */
if(!s->budget--) { s->failed_pc=0x0c0a9afeu; return 0; }
goto P_0c0a9b3c;
P_0c0a9b00: /* original 0009, guest PC 0x0c0a9b00 */
if(!s->budget--) { s->failed_pc=0x0c0a9b00u; return 0; }
if(!vf3_matrix_family(0x0c0a9b02u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9b02u; return 0; } return 1;
P_0c0a9b3c: /* original 7002, guest PC 0x0c0a9b3c */
if(!s->budget--) { s->failed_pc=0x0c0a9b3cu; return 0; }
r[0]+=0x00000002u;
goto P_0c0a9b3e;
P_0c0a9b3e: /* original 04ed, guest PC 0x0c0a9b3e */
if(!s->budget--) { s->failed_pc=0x0c0a9b3eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9b40;
P_0c0a9b40: /* original 74ff, guest PC 0x0c0a9b40 */
if(!s->budget--) { s->failed_pc=0x0c0a9b40u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9b42;
P_0c0a9b42: /* original 4411, guest PC 0x0c0a9b42 */
if(!s->budget--) { s->failed_pc=0x0c0a9b42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a9b44;
P_0c0a9b44: /* original 8900, guest PC 0x0c0a9b44 */
if(!s->budget--) { s->failed_pc=0x0c0a9b44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9b48; }
goto P_0c0a9b46;
P_0c0a9b46: /* original 6463, guest PC 0x0c0a9b46 */
if(!s->budget--) { s->failed_pc=0x0c0a9b46u; return 0; }
r[4]=r[6];
goto P_0c0a9b48;
P_0c0a9b48: /* original 905c, guest PC 0x0c0a9b48 */
if(!s->budget--) { s->failed_pc=0x0c0a9b48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9c04u,2);
goto P_0c0a9b4a;
P_0c0a9b4a: /* original 0e45, guest PC 0x0c0a9b4a */
if(!s->budget--) { s->failed_pc=0x0c0a9b4au; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9b4c;
P_0c0a9b4c: /* original 905b, guest PC 0x0c0a9b4c */
if(!s->budget--) { s->failed_pc=0x0c0a9b4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9c06u,2);
goto P_0c0a9b4e;
P_0c0a9b4e: /* original 04ed, guest PC 0x0c0a9b4e */
if(!s->budget--) { s->failed_pc=0x0c0a9b4eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9b50;
P_0c0a9b50: /* original 74ff, guest PC 0x0c0a9b50 */
if(!s->budget--) { s->failed_pc=0x0c0a9b50u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9b52;
P_0c0a9b52: /* original 4411, guest PC 0x0c0a9b52 */
if(!s->budget--) { s->failed_pc=0x0c0a9b52u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a9b54;
P_0c0a9b54: /* original 8900, guest PC 0x0c0a9b54 */
if(!s->budget--) { s->failed_pc=0x0c0a9b54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9b58; }
goto P_0c0a9b56;
P_0c0a9b56: /* original 6463, guest PC 0x0c0a9b56 */
if(!s->budget--) { s->failed_pc=0x0c0a9b56u; return 0; }
r[4]=r[6];
goto P_0c0a9b58;
P_0c0a9b58: /* original 0e45, guest PC 0x0c0a9b58 */
if(!s->budget--) { s->failed_pc=0x0c0a9b58u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9b5a;
P_0c0a9b5a: /* original e048, guest PC 0x0c0a9b5a */
if(!s->budget--) { s->failed_pc=0x0c0a9b5au; return 0; }
r[0]=0x00000048u;
goto P_0c0a9b5c;
P_0c0a9b5c: /* original 00ee, guest PC 0x0c0a9b5c */
if(!s->budget--) { s->failed_pc=0x0c0a9b5cu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c0a9b5e;
P_0c0a9b5e: /* original c808, guest PC 0x0c0a9b5e */
if(!s->budget--) { s->failed_pc=0x0c0a9b5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c0a9b60;
P_0c0a9b60: /* original 890e, guest PC 0x0c0a9b60 */
if(!s->budget--) { s->failed_pc=0x0c0a9b60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9b80; }
goto P_0c0a9b62;
P_0c0a9b62: /* original e048, guest PC 0x0c0a9b62 */
if(!s->budget--) { s->failed_pc=0x0c0a9b62u; return 0; }
r[0]=0x00000048u;
goto P_0c0a9b64;
P_0c0a9b64: /* original 03ee, guest PC 0x0c0a9b64 */
if(!s->budget--) { s->failed_pc=0x0c0a9b64u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0a9b66;
P_0c0a9b66: /* original 2378, guest PC 0x0c0a9b66 */
if(!s->budget--) { s->failed_pc=0x0c0a9b66u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[7])==0)!=0);
goto P_0c0a9b68;
P_0c0a9b68: /* original 890a, guest PC 0x0c0a9b68 */
if(!s->budget--) { s->failed_pc=0x0c0a9b68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9b80; }
goto P_0c0a9b6a;
P_0c0a9b6a: /* original 02de, guest PC 0x0c0a9b6a */
if(!s->budget--) { s->failed_pc=0x0c0a9b6au; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0a9b6c;
P_0c0a9b6c: /* original d327, guest PC 0x0c0a9b6c */
if(!s->budget--) { s->failed_pc=0x0c0a9b6cu; return 0; }
r[3]=read(ram,0x0c0a9c0cu,4);
goto P_0c0a9b6e;
P_0c0a9b6e: /* original 2238, guest PC 0x0c0a9b6e */
if(!s->budget--) { s->failed_pc=0x0c0a9b6eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9b70;
P_0c0a9b70: /* original 8b06, guest PC 0x0c0a9b70 */
if(!s->budget--) { s->failed_pc=0x0c0a9b70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9b80; }
goto P_0c0a9b72;
P_0c0a9b72: /* original e061, guest PC 0x0c0a9b72 */
if(!s->budget--) { s->failed_pc=0x0c0a9b72u; return 0; }
r[0]=0x00000061u;
goto P_0c0a9b74;
P_0c0a9b74: /* original 01ec, guest PC 0x0c0a9b74 */
if(!s->budget--) { s->failed_pc=0x0c0a9b74u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0a9b76;
P_0c0a9b76: /* original d026, guest PC 0x0c0a9b76 */
if(!s->budget--) { s->failed_pc=0x0c0a9b76u; return 0; }
r[0]=read(ram,0x0c0a9c10u,4);
goto P_0c0a9b78;
P_0c0a9b78: /* original 611c, guest PC 0x0c0a9b78 */
if(!s->budget--) { s->failed_pc=0x0c0a9b78u; return 0; }
r[1]=r[1]&255u;
goto P_0c0a9b7a;
P_0c0a9b7a: /* original 031c, guest PC 0x0c0a9b7a */
if(!s->budget--) { s->failed_pc=0x0c0a9b7au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0a9b7c;
P_0c0a9b7c: /* original 9044, guest PC 0x0c0a9b7c */
if(!s->budget--) { s->failed_pc=0x0c0a9b7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9c08u,2);
goto P_0c0a9b7e;
P_0c0a9b7e: /* original 0e35, guest PC 0x0c0a9b7e */
if(!s->budget--) { s->failed_pc=0x0c0a9b7eu; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a9b80;
P_0c0a9b80: /* original 9042, guest PC 0x0c0a9b80 */
if(!s->budget--) { s->failed_pc=0x0c0a9b80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9c08u,2);
goto P_0c0a9b82;
P_0c0a9b82: /* original 04ed, guest PC 0x0c0a9b82 */
if(!s->budget--) { s->failed_pc=0x0c0a9b82u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9b84;
P_0c0a9b84: /* original e048, guest PC 0x0c0a9b84 */
if(!s->budget--) { s->failed_pc=0x0c0a9b84u; return 0; }
r[0]=0x00000048u;
goto P_0c0a9b86;
P_0c0a9b86: /* original 03de, guest PC 0x0c0a9b86 */
if(!s->budget--) { s->failed_pc=0x0c0a9b86u; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c0a9b88;
P_0c0a9b88: /* original 2738, guest PC 0x0c0a9b88 */
if(!s->budget--) { s->failed_pc=0x0c0a9b88u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0a9b8a;
P_0c0a9b8a: /* original 8b03, guest PC 0x0c0a9b8a */
if(!s->budget--) { s->failed_pc=0x0c0a9b8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9b94; }
goto P_0c0a9b8c;
P_0c0a9b8c: /* original 02de, guest PC 0x0c0a9b8c */
if(!s->budget--) { s->failed_pc=0x0c0a9b8cu; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c0a9b8e;
P_0c0a9b8e: /* original d31f, guest PC 0x0c0a9b8e */
if(!s->budget--) { s->failed_pc=0x0c0a9b8eu; return 0; }
r[3]=read(ram,0x0c0a9c0cu,4);
goto P_0c0a9b90;
P_0c0a9b90: /* original 2238, guest PC 0x0c0a9b90 */
if(!s->budget--) { s->failed_pc=0x0c0a9b90u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9b92;
P_0c0a9b92: /* original 8b03, guest PC 0x0c0a9b92 */
if(!s->budget--) { s->failed_pc=0x0c0a9b92u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9b9c; }
goto P_0c0a9b94;
P_0c0a9b94: /* original 74ff, guest PC 0x0c0a9b94 */
if(!s->budget--) { s->failed_pc=0x0c0a9b94u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9b96;
P_0c0a9b96: /* original 4411, guest PC 0x0c0a9b96 */
if(!s->budget--) { s->failed_pc=0x0c0a9b96u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a9b98;
P_0c0a9b98: /* original 8900, guest PC 0x0c0a9b98 */
if(!s->budget--) { s->failed_pc=0x0c0a9b98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9b9c; }
goto P_0c0a9b9a;
P_0c0a9b9a: /* original 6463, guest PC 0x0c0a9b9a */
if(!s->budget--) { s->failed_pc=0x0c0a9b9au; return 0; }
r[4]=r[6];
goto P_0c0a9b9c;
P_0c0a9b9c: /* original 9034, guest PC 0x0c0a9b9c */
if(!s->budget--) { s->failed_pc=0x0c0a9b9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9c08u,2);
goto P_0c0a9b9e;
P_0c0a9b9e: /* original 0e45, guest PC 0x0c0a9b9e */
if(!s->budget--) { s->failed_pc=0x0c0a9b9eu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9ba0;
P_0c0a9ba0: /* original e066, guest PC 0x0c0a9ba0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ba0u; return 0; }
r[0]=0x00000066u;
goto P_0c0a9ba2;
P_0c0a9ba2: /* original 2e52, guest PC 0x0c0a9ba2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ba2u; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0a9ba4;
P_0c0a9ba4: /* original 03ed, guest PC 0x0c0a9ba4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ba4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9ba6;
P_0c0a9ba6: /* original 9030, guest PC 0x0c0a9ba6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ba6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9c0au,2);
goto P_0c0a9ba8;
P_0c0a9ba8: /* original 0e35, guest PC 0x0c0a9ba8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ba8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a9baa;
P_0c0a9baa: /* original d31a, guest PC 0x0c0a9baa */
if(!s->budget--) { s->failed_pc=0x0c0a9baau; return 0; }
r[3]=read(ram,0x0c0a9c14u,4);
goto P_0c0a9bac;
P_0c0a9bac: /* original 430b, guest PC 0x0c0a9bac */
if(!s->budget--) { s->failed_pc=0x0c0a9bacu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9bb0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bb0u) { target=s->pc; goto dispatch; }
goto P_0c0a9bb0;
P_0c0a9bae: /* original 64e3, guest PC 0x0c0a9bae */
if(!s->budget--) { s->failed_pc=0x0c0a9baeu; return 0; }
r[4]=r[14];
goto P_0c0a9bb0;
P_0c0a9bb0: /* original 65d3, guest PC 0x0c0a9bb0 */
if(!s->budget--) { s->failed_pc=0x0c0a9bb0u; return 0; }
r[5]=r[13];
goto P_0c0a9bb2;
P_0c0a9bb2: /* original b1d5, guest PC 0x0c0a9bb2 */
if(!s->budget--) { s->failed_pc=0x0c0a9bb2u; return 0; }
target=code_base|0x0c0a9f60u; r[16]=code_base|0x0c0a9bb6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bb6u) { target=s->pc; goto dispatch; }
goto P_0c0a9bb6;
P_0c0a9bb4: /* original 64e3, guest PC 0x0c0a9bb4 */
if(!s->budget--) { s->failed_pc=0x0c0a9bb4u; return 0; }
r[4]=r[14];
goto P_0c0a9bb6;
P_0c0a9bb6: /* original 65d3, guest PC 0x0c0a9bb6 */
if(!s->budget--) { s->failed_pc=0x0c0a9bb6u; return 0; }
r[5]=r[13];
goto P_0c0a9bb8;
P_0c0a9bb8: /* original b444, guest PC 0x0c0a9bb8 */
if(!s->budget--) { s->failed_pc=0x0c0a9bb8u; return 0; }
target=code_base|0x0c0aa444u; r[16]=code_base|0x0c0a9bbcu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bbcu) { target=s->pc; goto dispatch; }
goto P_0c0a9bbc;
P_0c0a9bba: /* original 64e3, guest PC 0x0c0a9bba */
if(!s->budget--) { s->failed_pc=0x0c0a9bbau; return 0; }
r[4]=r[14];
goto P_0c0a9bbc;
P_0c0a9bbc: /* original d216, guest PC 0x0c0a9bbc */
if(!s->budget--) { s->failed_pc=0x0c0a9bbcu; return 0; }
r[2]=read(ram,0x0c0a9c18u,4);
goto P_0c0a9bbe;
P_0c0a9bbe: /* original 65d3, guest PC 0x0c0a9bbe */
if(!s->budget--) { s->failed_pc=0x0c0a9bbeu; return 0; }
r[5]=r[13];
goto P_0c0a9bc0;
P_0c0a9bc0: /* original 420b, guest PC 0x0c0a9bc0 */
if(!s->budget--) { s->failed_pc=0x0c0a9bc0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9bc4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bc4u) { target=s->pc; goto dispatch; }
goto P_0c0a9bc4;
P_0c0a9bc2: /* original 64e3, guest PC 0x0c0a9bc2 */
if(!s->budget--) { s->failed_pc=0x0c0a9bc2u; return 0; }
r[4]=r[14];
goto P_0c0a9bc4;
P_0c0a9bc4: /* original d315, guest PC 0x0c0a9bc4 */
if(!s->budget--) { s->failed_pc=0x0c0a9bc4u; return 0; }
r[3]=read(ram,0x0c0a9c1cu,4);
goto P_0c0a9bc6;
P_0c0a9bc6: /* original 65d3, guest PC 0x0c0a9bc6 */
if(!s->budget--) { s->failed_pc=0x0c0a9bc6u; return 0; }
r[5]=r[13];
goto P_0c0a9bc8;
P_0c0a9bc8: /* original 430b, guest PC 0x0c0a9bc8 */
if(!s->budget--) { s->failed_pc=0x0c0a9bc8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9bccu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bccu) { target=s->pc; goto dispatch; }
goto P_0c0a9bcc;
P_0c0a9bca: /* original 64e3, guest PC 0x0c0a9bca */
if(!s->budget--) { s->failed_pc=0x0c0a9bcau; return 0; }
r[4]=r[14];
goto P_0c0a9bcc;
P_0c0a9bcc: /* original d214, guest PC 0x0c0a9bcc */
if(!s->budget--) { s->failed_pc=0x0c0a9bccu; return 0; }
r[2]=read(ram,0x0c0a9c20u,4);
goto P_0c0a9bce;
P_0c0a9bce: /* original 65d3, guest PC 0x0c0a9bce */
if(!s->budget--) { s->failed_pc=0x0c0a9bceu; return 0; }
r[5]=r[13];
goto P_0c0a9bd0;
P_0c0a9bd0: /* original 420b, guest PC 0x0c0a9bd0 */
if(!s->budget--) { s->failed_pc=0x0c0a9bd0u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9bd4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bd4u) { target=s->pc; goto dispatch; }
goto P_0c0a9bd4;
P_0c0a9bd2: /* original 64e3, guest PC 0x0c0a9bd2 */
if(!s->budget--) { s->failed_pc=0x0c0a9bd2u; return 0; }
r[4]=r[14];
goto P_0c0a9bd4;
P_0c0a9bd4: /* original d313, guest PC 0x0c0a9bd4 */
if(!s->budget--) { s->failed_pc=0x0c0a9bd4u; return 0; }
r[3]=read(ram,0x0c0a9c24u,4);
goto P_0c0a9bd6;
P_0c0a9bd6: /* original 430b, guest PC 0x0c0a9bd6 */
if(!s->budget--) { s->failed_pc=0x0c0a9bd6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9bdau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bdau) { target=s->pc; goto dispatch; }
goto P_0c0a9bda;
P_0c0a9bd8: /* original 64e3, guest PC 0x0c0a9bd8 */
if(!s->budget--) { s->failed_pc=0x0c0a9bd8u; return 0; }
r[4]=r[14];
goto P_0c0a9bda;
P_0c0a9bda: /* original d213, guest PC 0x0c0a9bda */
if(!s->budget--) { s->failed_pc=0x0c0a9bdau; return 0; }
r[2]=read(ram,0x0c0a9c28u,4);
goto P_0c0a9bdc;
P_0c0a9bdc: /* original 420b, guest PC 0x0c0a9bdc */
if(!s->budget--) { s->failed_pc=0x0c0a9bdcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9be0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9be0u) { target=s->pc; goto dispatch; }
goto P_0c0a9be0;
P_0c0a9bde: /* original 64e3, guest PC 0x0c0a9bde */
if(!s->budget--) { s->failed_pc=0x0c0a9bdeu; return 0; }
r[4]=r[14];
goto P_0c0a9be0;
P_0c0a9be0: /* original d312, guest PC 0x0c0a9be0 */
if(!s->budget--) { s->failed_pc=0x0c0a9be0u; return 0; }
r[3]=read(ram,0x0c0a9c2cu,4);
goto P_0c0a9be2;
P_0c0a9be2: /* original 430b, guest PC 0x0c0a9be2 */
if(!s->budget--) { s->failed_pc=0x0c0a9be2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9be6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9be6u) { target=s->pc; goto dispatch; }
goto P_0c0a9be6;
P_0c0a9be4: /* original 64e3, guest PC 0x0c0a9be4 */
if(!s->budget--) { s->failed_pc=0x0c0a9be4u; return 0; }
r[4]=r[14];
goto P_0c0a9be6;
P_0c0a9be6: /* original d212, guest PC 0x0c0a9be6 */
if(!s->budget--) { s->failed_pc=0x0c0a9be6u; return 0; }
r[2]=read(ram,0x0c0a9c30u,4);
goto P_0c0a9be8;
P_0c0a9be8: /* original 420b, guest PC 0x0c0a9be8 */
if(!s->budget--) { s->failed_pc=0x0c0a9be8u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a9becu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9becu) { target=s->pc; goto dispatch; }
goto P_0c0a9bec;
P_0c0a9bea: /* original 64e3, guest PC 0x0c0a9bea */
if(!s->budget--) { s->failed_pc=0x0c0a9beau; return 0; }
r[4]=r[14];
goto P_0c0a9bec;
P_0c0a9bec: /* original d311, guest PC 0x0c0a9bec */
if(!s->budget--) { s->failed_pc=0x0c0a9becu; return 0; }
r[3]=read(ram,0x0c0a9c34u,4);
goto P_0c0a9bee;
P_0c0a9bee: /* original 430b, guest PC 0x0c0a9bee */
if(!s->budget--) { s->failed_pc=0x0c0a9beeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9bf2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9bf2u) { target=s->pc; goto dispatch; }
goto P_0c0a9bf2;
P_0c0a9bf0: /* original 64e3, guest PC 0x0c0a9bf0 */
if(!s->budget--) { s->failed_pc=0x0c0a9bf0u; return 0; }
r[4]=r[14];
goto P_0c0a9bf2;
P_0c0a9bf2: /* original 62e2, guest PC 0x0c0a9bf2 */
if(!s->budget--) { s->failed_pc=0x0c0a9bf2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a9bf4;
P_0c0a9bf4: /* original d310, guest PC 0x0c0a9bf4 */
if(!s->budget--) { s->failed_pc=0x0c0a9bf4u; return 0; }
r[3]=read(ram,0x0c0a9c38u,4);
goto P_0c0a9bf6;
P_0c0a9bf6: /* original 223b, guest PC 0x0c0a9bf6 */
if(!s->budget--) { s->failed_pc=0x0c0a9bf6u; return 0; }
r[2]|=r[3];
goto P_0c0a9bf8;
P_0c0a9bf8: /* original 2e22, guest PC 0x0c0a9bf8 */
if(!s->budget--) { s->failed_pc=0x0c0a9bf8u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0a9bfa;
P_0c0a9bfa: /* original 7f08, guest PC 0x0c0a9bfa */
if(!s->budget--) { s->failed_pc=0x0c0a9bfau; return 0; }
r[15]+=0x00000008u;
goto P_0c0a9bfc;
P_0c0a9bfc: /* original 4f26, guest PC 0x0c0a9bfc */
if(!s->budget--) { s->failed_pc=0x0c0a9bfcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9bfe;
P_0c0a9bfe: /* original 6df6, guest PC 0x0c0a9bfe */
if(!s->budget--) { s->failed_pc=0x0c0a9bfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9c00;
P_0c0a9c00: /* original 000b, guest PC 0x0c0a9c00 */
if(!s->budget--) { s->failed_pc=0x0c0a9c00u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9c02: /* original 6ef6, guest PC 0x0c0a9c02 */
if(!s->budget--) { s->failed_pc=0x0c0a9c02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a9c04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9c04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
