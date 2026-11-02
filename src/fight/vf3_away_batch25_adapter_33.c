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
int vf3_away_batch25_adapter_33(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c3a16u: goto P_0c0c3a16;
case 0x0c0c3a18u: goto P_0c0c3a18;
case 0x0c0c3a1au: goto P_0c0c3a1a;
case 0x0c0c3a1cu: goto P_0c0c3a1c;
case 0x0c0c3a1eu: goto P_0c0c3a1e;
case 0x0c0c3a20u: goto P_0c0c3a20;
case 0x0c0c3a22u: goto P_0c0c3a22;
case 0x0c0c3a24u: goto P_0c0c3a24;
case 0x0c0c3a26u: goto P_0c0c3a26;
case 0x0c0c3a28u: goto P_0c0c3a28;
case 0x0c0c3a2au: goto P_0c0c3a2a;
case 0x0c0c3a2cu: goto P_0c0c3a2c;
case 0x0c0c3a2eu: goto P_0c0c3a2e;
case 0x0c0c3a30u: goto P_0c0c3a30;
case 0x0c0c3a32u: goto P_0c0c3a32;
case 0x0c0c3a34u: goto P_0c0c3a34;
case 0x0c0c3a36u: goto P_0c0c3a36;
case 0x0c0c3a38u: goto P_0c0c3a38;
case 0x0c0c3a3au: goto P_0c0c3a3a;
case 0x0c0c3a3cu: goto P_0c0c3a3c;
case 0x0c0c3a3eu: goto P_0c0c3a3e;
case 0x0c0c3a40u: goto P_0c0c3a40;
case 0x0c0c3a42u: goto P_0c0c3a42;
case 0x0c0c3a44u: goto P_0c0c3a44;
case 0x0c0c3a46u: goto P_0c0c3a46;
case 0x0c0c3a48u: goto P_0c0c3a48;
case 0x0c0c3a84u: goto P_0c0c3a84;
case 0x0c0c3a86u: goto P_0c0c3a86;
case 0x0c0c3a88u: goto P_0c0c3a88;
case 0x0c0c3a8au: goto P_0c0c3a8a;
case 0x0c0c3a8cu: goto P_0c0c3a8c;
case 0x0c0c3a8eu: goto P_0c0c3a8e;
case 0x0c0c3a90u: goto P_0c0c3a90;
case 0x0c0c3a92u: goto P_0c0c3a92;
case 0x0c0c3a94u: goto P_0c0c3a94;
case 0x0c0c3a96u: goto P_0c0c3a96;
case 0x0c0c3a98u: goto P_0c0c3a98;
case 0x0c0c3a9au: goto P_0c0c3a9a;
case 0x0c0c3a9cu: goto P_0c0c3a9c;
case 0x0c0c3a9eu: goto P_0c0c3a9e;
case 0x0c0c3aa0u: goto P_0c0c3aa0;
case 0x0c0c3aa2u: goto P_0c0c3aa2;
case 0x0c0c3aa4u: goto P_0c0c3aa4;
case 0x0c0c3aa6u: goto P_0c0c3aa6;
case 0x0c0c3aa8u: goto P_0c0c3aa8;
case 0x0c0c3aaau: goto P_0c0c3aaa;
case 0x0c0c3aacu: goto P_0c0c3aac;
case 0x0c0c3aaeu: goto P_0c0c3aae;
case 0x0c0c3ab0u: goto P_0c0c3ab0;
case 0x0c0c3ab2u: goto P_0c0c3ab2;
case 0x0c0c3ab4u: goto P_0c0c3ab4;
case 0x0c0c3ab6u: goto P_0c0c3ab6;
case 0x0c0c3ab8u: goto P_0c0c3ab8;
case 0x0c0c3abau: goto P_0c0c3aba;
case 0x0c0c3abcu: goto P_0c0c3abc;
case 0x0c0c3abeu: goto P_0c0c3abe;
case 0x0c0c3ac0u: goto P_0c0c3ac0;
case 0x0c0c3ac2u: goto P_0c0c3ac2;
case 0x0c0c3ac4u: goto P_0c0c3ac4;
case 0x0c0c3ac6u: goto P_0c0c3ac6;
case 0x0c0c3ac8u: goto P_0c0c3ac8;
case 0x0c0c3acau: goto P_0c0c3aca;
case 0x0c0c3accu: goto P_0c0c3acc;
case 0x0c0c3aceu: goto P_0c0c3ace;
case 0x0c0c3ad0u: goto P_0c0c3ad0;
case 0x0c0c3ad2u: goto P_0c0c3ad2;
case 0x0c0c3ad4u: goto P_0c0c3ad4;
case 0x0c0c3ad6u: goto P_0c0c3ad6;
case 0x0c0c3ad8u: goto P_0c0c3ad8;
case 0x0c0c3adau: goto P_0c0c3ada;
case 0x0c0c3adcu: goto P_0c0c3adc;
case 0x0c0c3adeu: goto P_0c0c3ade;
case 0x0c0c3ae0u: goto P_0c0c3ae0;
case 0x0c0c3ae2u: goto P_0c0c3ae2;
case 0x0c0c3ae4u: goto P_0c0c3ae4;
case 0x0c0c3ae6u: goto P_0c0c3ae6;
case 0x0c0c3ae8u: goto P_0c0c3ae8;
case 0x0c0c3aeau: goto P_0c0c3aea;
case 0x0c0c3aecu: goto P_0c0c3aec;
case 0x0c0c3aeeu: goto P_0c0c3aee;
case 0x0c0c3af0u: goto P_0c0c3af0;
case 0x0c0c3af2u: goto P_0c0c3af2;
case 0x0c0c3af4u: goto P_0c0c3af4;
case 0x0c0c3af6u: goto P_0c0c3af6;
case 0x0c0c3af8u: goto P_0c0c3af8;
case 0x0c0c3afau: goto P_0c0c3afa;
case 0x0c0c3afcu: goto P_0c0c3afc;
case 0x0c0c3afeu: goto P_0c0c3afe;
case 0x0c0c3b00u: goto P_0c0c3b00;
case 0x0c0c3b02u: goto P_0c0c3b02;
case 0x0c0c3b04u: goto P_0c0c3b04;
case 0x0c0c3b06u: goto P_0c0c3b06;
case 0x0c0c3b08u: goto P_0c0c3b08;
case 0x0c0c3b0au: goto P_0c0c3b0a;
case 0x0c0c3b0cu: goto P_0c0c3b0c;
case 0x0c0c3b0eu: goto P_0c0c3b0e;
case 0x0c0c3b10u: goto P_0c0c3b10;
case 0x0c0c3b12u: goto P_0c0c3b12;
case 0x0c0c3b14u: goto P_0c0c3b14;
case 0x0c0c3b16u: goto P_0c0c3b16;
case 0x0c0c3b18u: goto P_0c0c3b18;
case 0x0c0c3b1au: goto P_0c0c3b1a;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c3a16: /* original 2fe6, guest PC 0x0c0c3a16 */
if(!s->budget--) { s->failed_pc=0x0c0c3a16u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3a18;
P_0c0c3a18: /* original 6e43, guest PC 0x0c0c3a18 */
if(!s->budget--) { s->failed_pc=0x0c0c3a18u; return 0; }
r[14]=r[4];
goto P_0c0c3a1a;
P_0c0c3a1a: /* original 2fd6, guest PC 0x0c0c3a1a */
if(!s->budget--) { s->failed_pc=0x0c0c3a1au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3a1c;
P_0c0c3a1c: /* original 2fc6, guest PC 0x0c0c3a1c */
if(!s->budget--) { s->failed_pc=0x0c0c3a1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3a1e;
P_0c0c3a1e: /* original 2fb6, guest PC 0x0c0c3a1e */
if(!s->budget--) { s->failed_pc=0x0c0c3a1eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3a20;
P_0c0c3a20: /* original 2fa6, guest PC 0x0c0c3a20 */
if(!s->budget--) { s->failed_pc=0x0c0c3a20u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c3a22;
P_0c0c3a22: /* original 84e4, guest PC 0x0c0c3a22 */
if(!s->budget--) { s->failed_pc=0x0c0c3a22u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c3a24;
P_0c0c3a24: /* original d315, guest PC 0x0c0c3a24 */
if(!s->budget--) { s->failed_pc=0x0c0c3a24u; return 0; }
r[3]=read(ram,0x0c0c3a7cu,4);
goto P_0c0c3a26;
P_0c0c3a26: /* original 4f22, guest PC 0x0c0c3a26 */
if(!s->budget--) { s->failed_pc=0x0c0c3a26u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c3a28;
P_0c0c3a28: /* original 6632, guest PC 0x0c0c3a28 */
if(!s->budget--) { s->failed_pc=0x0c0c3a28u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0c3a2a;
P_0c0c3a2a: /* original 670c, guest PC 0x0c0c3a2a */
if(!s->budget--) { s->failed_pc=0x0c0c3a2au; return 0; }
r[7]=r[0]&255u;
goto P_0c0c3a2c;
P_0c0c3a2c: /* original d214, guest PC 0x0c0c3a2c */
if(!s->budget--) { s->failed_pc=0x0c0c3a2cu; return 0; }
r[2]=read(ram,0x0c0c3a80u,4);
goto P_0c0c3a2e;
P_0c0c3a2e: /* original 2778, guest PC 0x0c0c3a2e */
if(!s->budget--) { s->failed_pc=0x0c0c3a2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c3a30;
P_0c0c3a30: /* original d411, guest PC 0x0c0c3a30 */
if(!s->budget--) { s->failed_pc=0x0c0c3a30u; return 0; }
r[4]=read(ram,0x0c0c3a78u,4);
goto P_0c0c3a32;
P_0c0c3a32: /* original 8f27, guest PC 0x0c0c3a32 */
if(!s->budget--) { s->failed_pc=0x0c0c3a32u; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[2],4);
r[5]=tmp;
if(!cond) { goto P_0c0c3a84; }
goto P_0c0c3a36;
P_0c0c3a34: /* original 6522, guest PC 0x0c0c3a34 */
if(!s->budget--) { s->failed_pc=0x0c0c3a34u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c0c3a36;
P_0c0c3a36: /* original 6743, guest PC 0x0c0c3a36 */
if(!s->budget--) { s->failed_pc=0x0c0c3a36u; return 0; }
r[7]=r[4];
goto P_0c0c3a38;
P_0c0c3a38: /* original 6a43, guest PC 0x0c0c3a38 */
if(!s->budget--) { s->failed_pc=0x0c0c3a38u; return 0; }
r[10]=r[4];
goto P_0c0c3a3a;
P_0c0c3a3a: /* original 6c43, guest PC 0x0c0c3a3a */
if(!s->budget--) { s->failed_pc=0x0c0c3a3au; return 0; }
r[12]=r[4];
goto P_0c0c3a3c;
P_0c0c3a3c: /* original 6d43, guest PC 0x0c0c3a3c */
if(!s->budget--) { s->failed_pc=0x0c0c3a3cu; return 0; }
r[13]=r[4];
goto P_0c0c3a3e;
P_0c0c3a3e: /* original 772c, guest PC 0x0c0c3a3e */
if(!s->budget--) { s->failed_pc=0x0c0c3a3eu; return 0; }
r[7]+=0x0000002cu;
goto P_0c0c3a40;
P_0c0c3a40: /* original 7a24, guest PC 0x0c0c3a40 */
if(!s->budget--) { s->failed_pc=0x0c0c3a40u; return 0; }
r[10]+=0x00000024u;
goto P_0c0c3a42;
P_0c0c3a42: /* original 7d20, guest PC 0x0c0c3a42 */
if(!s->budget--) { s->failed_pc=0x0c0c3a42u; return 0; }
r[13]+=0x00000020u;
goto P_0c0c3a44;
P_0c0c3a44: /* original 7c28, guest PC 0x0c0c3a44 */
if(!s->budget--) { s->failed_pc=0x0c0c3a44u; return 0; }
r[12]+=0x00000028u;
goto P_0c0c3a46;
P_0c0c3a46: /* original a026, guest PC 0x0c0c3a46 */
if(!s->budget--) { s->failed_pc=0x0c0c3a46u; return 0; }
r[11]=r[6];
goto P_0c0c3a96;
P_0c0c3a48: /* original 6b63, guest PC 0x0c0c3a48 */
if(!s->budget--) { s->failed_pc=0x0c0c3a48u; return 0; }
r[11]=r[6];
if(!vf3_matrix_family(0x0c0c3a4au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3a4au; return 0; } return 1;
P_0c0c3a84: /* original 6a43, guest PC 0x0c0c3a84 */
if(!s->budget--) { s->failed_pc=0x0c0c3a84u; return 0; }
r[10]=r[4];
goto P_0c0c3a86;
P_0c0c3a86: /* original 6743, guest PC 0x0c0c3a86 */
if(!s->budget--) { s->failed_pc=0x0c0c3a86u; return 0; }
r[7]=r[4];
goto P_0c0c3a88;
P_0c0c3a88: /* original 6c43, guest PC 0x0c0c3a88 */
if(!s->budget--) { s->failed_pc=0x0c0c3a88u; return 0; }
r[12]=r[4];
goto P_0c0c3a8a;
P_0c0c3a8a: /* original 6d43, guest PC 0x0c0c3a8a */
if(!s->budget--) { s->failed_pc=0x0c0c3a8au; return 0; }
r[13]=r[4];
goto P_0c0c3a8c;
P_0c0c3a8c: /* original 7728, guest PC 0x0c0c3a8c */
if(!s->budget--) { s->failed_pc=0x0c0c3a8cu; return 0; }
r[7]+=0x00000028u;
goto P_0c0c3a8e;
P_0c0c3a8e: /* original 6b53, guest PC 0x0c0c3a8e */
if(!s->budget--) { s->failed_pc=0x0c0c3a8eu; return 0; }
r[11]=r[5];
goto P_0c0c3a90;
P_0c0c3a90: /* original 7c2c, guest PC 0x0c0c3a90 */
if(!s->budget--) { s->failed_pc=0x0c0c3a90u; return 0; }
r[12]+=0x0000002cu;
goto P_0c0c3a92;
P_0c0c3a92: /* original 7d24, guest PC 0x0c0c3a92 */
if(!s->budget--) { s->failed_pc=0x0c0c3a92u; return 0; }
r[13]+=0x00000024u;
goto P_0c0c3a94;
P_0c0c3a94: /* original 7a20, guest PC 0x0c0c3a94 */
if(!s->budget--) { s->failed_pc=0x0c0c3a94u; return 0; }
r[10]+=0x00000020u;
goto P_0c0c3a96;
P_0c0c3a96: /* original e036, guest PC 0x0c0c3a96 */
if(!s->budget--) { s->failed_pc=0x0c0c3a96u; return 0; }
r[0]=0x00000036u;
goto P_0c0c3a98;
P_0c0c3a98: /* original 03ec, guest PC 0x0c0c3a98 */
if(!s->budget--) { s->failed_pc=0x0c0c3a98u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c3a9a;
P_0c0c3a9a: /* original 2338, guest PC 0x0c0c3a9a */
if(!s->budget--) { s->failed_pc=0x0c0c3a9au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c3a9c;
P_0c0c3a9c: /* original 8d15, guest PC 0x0c0c3a9c */
if(!s->budget--) { s->failed_pc=0x0c0c3a9cu; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c0c3aca; }
goto P_0c0c3aa0;
P_0c0c3a9e: /* original e400, guest PC 0x0c0c3a9e */
if(!s->budget--) { s->failed_pc=0x0c0c3a9eu; return 0; }
r[4]=0x00000000u;
goto P_0c0c3aa0;
P_0c0c3aa0: /* original 52ef, guest PC 0x0c0c3aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa0u; return 0; }
r[2]=read(ram,r[14]+60,4);
goto P_0c0c3aa2;
P_0c0c3aa2: /* original e106, guest PC 0x0c0c3aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa2u; return 0; }
r[1]=0x00000006u;
goto P_0c0c3aa4;
P_0c0c3aa4: /* original 3213, guest PC 0x0c0c3aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[1])!=0);
goto P_0c0c3aa6;
P_0c0c3aa6: /* original 8912, guest PC 0x0c0c3aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c3ace; }
goto P_0c0c3aa8;
P_0c0c3aa8: /* original 60d2, guest PC 0x0c0c3aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c3aa8u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c3aaa;
P_0c0c3aaa: /* original 88ff, guest PC 0x0c0c3aaa */
if(!s->budget--) { s->failed_pc=0x0c0c3aaau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3aac;
P_0c0c3aac: /* original 8b09, guest PC 0x0c0c3aac */
if(!s->budget--) { s->failed_pc=0x0c0c3aacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ac2; }
goto P_0c0c3aae;
P_0c0c3aae: /* original 60c2, guest PC 0x0c0c3aae */
if(!s->budget--) { s->failed_pc=0x0c0c3aaeu; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0c3ab0;
P_0c0c3ab0: /* original 88ff, guest PC 0x0c0c3ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ab2;
P_0c0c3ab2: /* original 8b06, guest PC 0x0c0c3ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3ac2; }
goto P_0c0c3ab4;
P_0c0c3ab4: /* original d335, guest PC 0x0c0c3ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab4u; return 0; }
r[3]=read(ram,0x0c0c3b8cu,4);
goto P_0c0c3ab6;
P_0c0c3ab6: /* original e040, guest PC 0x0c0c3ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab6u; return 0; }
r[0]=0x00000040u;
goto P_0c0c3ab8;
P_0c0c3ab8: /* original 430b, guest PC 0x0c0c3ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ab8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3abcu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3abcu) { target=s->pc; goto dispatch; }
goto P_0c0c3abc;
P_0c0c3aba: /* original 04ee, guest PC 0x0c0c3aba */
if(!s->budget--) { s->failed_pc=0x0c0c3abau; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c3abc;
P_0c0c3abc: /* original e040, guest PC 0x0c0c3abc */
if(!s->budget--) { s->failed_pc=0x0c0c3abcu; return 0; }
r[0]=0x00000040u;
goto P_0c0c3abe;
P_0c0c3abe: /* original e2ff, guest PC 0x0c0c3abe */
if(!s->budget--) { s->failed_pc=0x0c0c3abeu; return 0; }
r[2]=0xffffffffu;
goto P_0c0c3ac0;
P_0c0c3ac0: /* original 0e26, guest PC 0x0c0c3ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c3ac2;
P_0c0c3ac2: /* original 53ef, guest PC 0x0c0c3ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac2u; return 0; }
r[3]=read(ram,r[14]+60,4);
goto P_0c0c3ac4;
P_0c0c3ac4: /* original 7301, guest PC 0x0c0c3ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac4u; return 0; }
r[3]+=0x00000001u;
goto P_0c0c3ac6;
P_0c0c3ac6: /* original a022, guest PC 0x0c0c3ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac6u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c0c3b0e;
P_0c0c3ac8: /* original 1e3f, guest PC 0x0c0c3ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ac8u; return 0; }
write(ram,r[14]+60,r[3],4);
goto P_0c0c3aca;
P_0c0c3aca: /* original a020, guest PC 0x0c0c3aca */
if(!s->budget--) { s->failed_pc=0x0c0c3acau; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c3b0e;
P_0c0c3acc: /* original 1e4f, guest PC 0x0c0c3acc */
if(!s->budget--) { s->failed_pc=0x0c0c3accu; return 0; }
write(ram,r[14]+60,r[4],4);
goto P_0c0c3ace;
P_0c0c3ace: /* original 60a2, guest PC 0x0c0c3ace */
if(!s->budget--) { s->failed_pc=0x0c0c3aceu; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c0c3ad0;
P_0c0c3ad0: /* original 88ff, guest PC 0x0c0c3ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ad2;
P_0c0c3ad2: /* original 8b1c, guest PC 0x0c0c3ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ad4;
P_0c0c3ad4: /* original 6072, guest PC 0x0c0c3ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad4u; return 0; }
tmp=read(ram,r[7],4);
r[0]=tmp;
goto P_0c0c3ad6;
P_0c0c3ad6: /* original 88ff, guest PC 0x0c0c3ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ad8;
P_0c0c3ad8: /* original 8b19, guest PC 0x0c0c3ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ad8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ada;
P_0c0c3ada: /* original 60d2, guest PC 0x0c0c3ada */
if(!s->budget--) { s->failed_pc=0x0c0c3adau; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c3adc;
P_0c0c3adc: /* original 88ff, guest PC 0x0c0c3adc */
if(!s->budget--) { s->failed_pc=0x0c0c3adcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ade;
P_0c0c3ade: /* original 8b16, guest PC 0x0c0c3ade */
if(!s->budget--) { s->failed_pc=0x0c0c3adeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ae0;
P_0c0c3ae0: /* original 60c2, guest PC 0x0c0c3ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae0u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0c3ae2;
P_0c0c3ae2: /* original 88ff, guest PC 0x0c0c3ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c3ae4;
P_0c0c3ae4: /* original 8b13, guest PC 0x0c0c3ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c3b0e; }
goto P_0c0c3ae6;
P_0c0c3ae6: /* original e036, guest PC 0x0c0c3ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae6u; return 0; }
r[0]=0x00000036u;
goto P_0c0c3ae8;
P_0c0c3ae8: /* original 0e44, guest PC 0x0c0c3ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c3ae8u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c3aea;
P_0c0c3aea: /* original e040, guest PC 0x0c0c3aea */
if(!s->budget--) { s->failed_pc=0x0c0c3aeau; return 0; }
r[0]=0x00000040u;
goto P_0c0c3aec;
P_0c0c3aec: /* original 2d42, guest PC 0x0c0c3aec */
if(!s->budget--) { s->failed_pc=0x0c0c3aecu; return 0; }
write(ram,r[13],r[4],4);
goto P_0c0c3aee;
P_0c0c3aee: /* original 2c42, guest PC 0x0c0c3aee */
if(!s->budget--) { s->failed_pc=0x0c0c3aeeu; return 0; }
write(ram,r[12],r[4],4);
goto P_0c0c3af0;
P_0c0c3af0: /* original d326, guest PC 0x0c0c3af0 */
if(!s->budget--) { s->failed_pc=0x0c0c3af0u; return 0; }
r[3]=read(ram,0x0c0c3b8cu,4);
goto P_0c0c3af2;
P_0c0c3af2: /* original 430b, guest PC 0x0c0c3af2 */
if(!s->budget--) { s->failed_pc=0x0c0c3af2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3af6u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3af6u) { target=s->pc; goto dispatch; }
goto P_0c0c3af6;
P_0c0c3af4: /* original 04ee, guest PC 0x0c0c3af4 */
if(!s->budget--) { s->failed_pc=0x0c0c3af4u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c3af6;
P_0c0c3af6: /* original e060, guest PC 0x0c0c3af6 */
if(!s->budget--) { s->failed_pc=0x0c0c3af6u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3af8;
P_0c0c3af8: /* original d325, guest PC 0x0c0c3af8 */
if(!s->budget--) { s->failed_pc=0x0c0c3af8u; return 0; }
r[3]=read(ram,0x0c0c3b90u,4);
goto P_0c0c3afa;
P_0c0c3afa: /* original 04bc, guest PC 0x0c0c3afa */
if(!s->budget--) { s->failed_pc=0x0c0c3afau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c3afc;
P_0c0c3afc: /* original 65d3, guest PC 0x0c0c3afc */
if(!s->budget--) { s->failed_pc=0x0c0c3afcu; return 0; }
r[5]=r[13];
goto P_0c0c3afe;
P_0c0c3afe: /* original 66c3, guest PC 0x0c0c3afe */
if(!s->budget--) { s->failed_pc=0x0c0c3afeu; return 0; }
r[6]=r[12];
goto P_0c0c3b00;
P_0c0c3b00: /* original 430b, guest PC 0x0c0c3b00 */
if(!s->budget--) { s->failed_pc=0x0c0c3b00u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c3b04u;
r[4]=r[4]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c3b04u) { target=s->pc; goto dispatch; }
goto P_0c0c3b04;
P_0c0c3b02: /* original 644c, guest PC 0x0c0c3b02 */
if(!s->budget--) { s->failed_pc=0x0c0c3b02u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c3b04;
P_0c0c3b04: /* original e060, guest PC 0x0c0c3b04 */
if(!s->budget--) { s->failed_pc=0x0c0c3b04u; return 0; }
r[0]=0x00000060u;
goto P_0c0c3b06;
P_0c0c3b06: /* original 02bc, guest PC 0x0c0c3b06 */
if(!s->budget--) { s->failed_pc=0x0c0c3b06u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c3b08;
P_0c0c3b08: /* original e040, guest PC 0x0c0c3b08 */
if(!s->budget--) { s->failed_pc=0x0c0c3b08u; return 0; }
r[0]=0x00000040u;
goto P_0c0c3b0a;
P_0c0c3b0a: /* original 622c, guest PC 0x0c0c3b0a */
if(!s->budget--) { s->failed_pc=0x0c0c3b0au; return 0; }
r[2]=r[2]&255u;
goto P_0c0c3b0c;
P_0c0c3b0c: /* original 0e26, guest PC 0x0c0c3b0c */
if(!s->budget--) { s->failed_pc=0x0c0c3b0cu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0c3b0e;
P_0c0c3b0e: /* original 4f26, guest PC 0x0c0c3b0e */
if(!s->budget--) { s->failed_pc=0x0c0c3b0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c3b10;
P_0c0c3b10: /* original 6af6, guest PC 0x0c0c3b10 */
if(!s->budget--) { s->failed_pc=0x0c0c3b10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c3b12;
P_0c0c3b12: /* original 6bf6, guest PC 0x0c0c3b12 */
if(!s->budget--) { s->failed_pc=0x0c0c3b12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c3b14;
P_0c0c3b14: /* original 6cf6, guest PC 0x0c0c3b14 */
if(!s->budget--) { s->failed_pc=0x0c0c3b14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c3b16;
P_0c0c3b16: /* original 6df6, guest PC 0x0c0c3b16 */
if(!s->budget--) { s->failed_pc=0x0c0c3b16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c3b18;
P_0c0c3b18: /* original 000b, guest PC 0x0c0c3b18 */
if(!s->budget--) { s->failed_pc=0x0c0c3b18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c3b1a: /* original 6ef6, guest PC 0x0c0c3b1a */
if(!s->budget--) { s->failed_pc=0x0c0c3b1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c3b1cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c3b1cu; return 0; } return 1;
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
return vf3_matrix_family(0x0c0c3c30u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
