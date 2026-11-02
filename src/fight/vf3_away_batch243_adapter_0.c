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
int vf3_away_batch243_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09571cu: goto P_0c09571c;
case 0x0c09571eu: goto P_0c09571e;
case 0x0c095720u: goto P_0c095720;
case 0x0c095722u: goto P_0c095722;
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
case 0x0c0a2e86u: goto P_0c0a2e86;
case 0x0c0a2e88u: goto P_0c0a2e88;
case 0x0c0a2e8au: goto P_0c0a2e8a;
case 0x0c0a2e8cu: goto P_0c0a2e8c;
case 0x0c0a2e8eu: goto P_0c0a2e8e;
case 0x0c0a2e90u: goto P_0c0a2e90;
case 0x0c0a2e92u: goto P_0c0a2e92;
case 0x0c0a2e94u: goto P_0c0a2e94;
case 0x0c0a2e96u: goto P_0c0a2e96;
case 0x0c0a2e98u: goto P_0c0a2e98;
case 0x0c0a2e9au: goto P_0c0a2e9a;
case 0x0c0a2e9cu: goto P_0c0a2e9c;
case 0x0c0a2e9eu: goto P_0c0a2e9e;
case 0x0c0a2ea0u: goto P_0c0a2ea0;
case 0x0c0a2ea2u: goto P_0c0a2ea2;
case 0x0c0a2ea4u: goto P_0c0a2ea4;
case 0x0c0a2ea6u: goto P_0c0a2ea6;
case 0x0c0a2ea8u: goto P_0c0a2ea8;
case 0x0c0a2eaau: goto P_0c0a2eaa;
case 0x0c0a2eacu: goto P_0c0a2eac;
case 0x0c0a2eaeu: goto P_0c0a2eae;
case 0x0c0a2eb0u: goto P_0c0a2eb0;
case 0x0c0a2eb2u: goto P_0c0a2eb2;
case 0x0c0a2eb4u: goto P_0c0a2eb4;
case 0x0c0a2eb6u: goto P_0c0a2eb6;
case 0x0c0a2eb8u: goto P_0c0a2eb8;
case 0x0c0a2ebau: goto P_0c0a2eba;
case 0x0c0a2ebcu: goto P_0c0a2ebc;
case 0x0c0a2ebeu: goto P_0c0a2ebe;
case 0x0c0a2ec0u: goto P_0c0a2ec0;
case 0x0c0a2ec2u: goto P_0c0a2ec2;
case 0x0c0a2ec4u: goto P_0c0a2ec4;
case 0x0c0a2ec6u: goto P_0c0a2ec6;
case 0x0c0a2ec8u: goto P_0c0a2ec8;
case 0x0c0a2ecau: goto P_0c0a2eca;
case 0x0c0a2eccu: goto P_0c0a2ecc;
case 0x0c0a2eceu: goto P_0c0a2ece;
case 0x0c0a2ed0u: goto P_0c0a2ed0;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c09571c: /* original d21c, guest PC 0x0c09571c */
if(!s->budget--) { s->failed_pc=0x0c09571cu; return 0; }
r[2]=read(ram,0x0c095790u,4);
goto P_0c09571e;
P_0c09571e: /* original 6322, guest PC 0x0c09571e */
if(!s->budget--) { s->failed_pc=0x0c09571eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c095720;
P_0c095720: /* original 432b, guest PC 0x0c095720 */
if(!s->budget--) { s->failed_pc=0x0c095720u; return 0; }
target=r[3];
r[4]=0x00000001u;
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
P_0c095722: /* original e401, guest PC 0x0c095722 */
if(!s->budget--) { s->failed_pc=0x0c095722u; return 0; }
r[4]=0x00000001u;
if(!vf3_matrix_family(0x0c095724u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095724u; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c0a2c36u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c36u; return 0; } return 1;
P_0c0a2e86: /* original 2fe6, guest PC 0x0c0a2e86 */
if(!s->budget--) { s->failed_pc=0x0c0a2e86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e88;
P_0c0a2e88: /* original 4411, guest PC 0x0c0a2e88 */
if(!s->budget--) { s->failed_pc=0x0c0a2e88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0a2e8a;
P_0c0a2e8a: /* original 2fd6, guest PC 0x0c0a2e8a */
if(!s->budget--) { s->failed_pc=0x0c0a2e8au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2e8c;
P_0c0a2e8c: /* original 4f22, guest PC 0x0c0a2e8c */
if(!s->budget--) { s->failed_pc=0x0c0a2e8cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2e8e;
P_0c0a2e8e: /* original 8b1c, guest PC 0x0c0a2e8e */
if(!s->budget--) { s->failed_pc=0x0c0a2e8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2eca; }
goto P_0c0a2e90;
P_0c0a2e90: /* original e21a, guest PC 0x0c0a2e90 */
if(!s->budget--) { s->failed_pc=0x0c0a2e90u; return 0; }
r[2]=0x0000001au;
goto P_0c0a2e92;
P_0c0a2e92: /* original 3423, guest PC 0x0c0a2e92 */
if(!s->budget--) { s->failed_pc=0x0c0a2e92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0a2e94;
P_0c0a2e94: /* original 8919, guest PC 0x0c0a2e94 */
if(!s->budget--) { s->failed_pc=0x0c0a2e94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2e96;
P_0c0a2e96: /* original 6e43, guest PC 0x0c0a2e96 */
if(!s->budget--) { s->failed_pc=0x0c0a2e96u; return 0; }
r[14]=r[4];
goto P_0c0a2e98;
P_0c0a2e98: /* original 4e08, guest PC 0x0c0a2e98 */
if(!s->budget--) { s->failed_pc=0x0c0a2e98u; return 0; }
r[14]<<=2;
goto P_0c0a2e9a;
P_0c0a2e9a: /* original 4e00, guest PC 0x0c0a2e9a */
if(!s->budget--) { s->failed_pc=0x0c0a2e9au; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0a2e9c;
P_0c0a2e9c: /* original 6343, guest PC 0x0c0a2e9c */
if(!s->budget--) { s->failed_pc=0x0c0a2e9cu; return 0; }
r[3]=r[4];
goto P_0c0a2e9e;
P_0c0a2e9e: /* original 3e3c, guest PC 0x0c0a2e9e */
if(!s->budget--) { s->failed_pc=0x0c0a2e9eu; return 0; }
r[14]+=r[3];
goto P_0c0a2ea0;
P_0c0a2ea0: /* original d233, guest PC 0x0c0a2ea0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea0u; return 0; }
r[2]=read(ram,0x0c0a2f70u,4);
goto P_0c0a2ea2;
P_0c0a2ea2: /* original 4e08, guest PC 0x0c0a2ea2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea2u; return 0; }
r[14]<<=2;
goto P_0c0a2ea4;
P_0c0a2ea4: /* original 6eef, guest PC 0x0c0a2ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea4u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0a2ea6;
P_0c0a2ea6: /* original 3e2c, guest PC 0x0c0a2ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea6u; return 0; }
r[14]+=r[2];
goto P_0c0a2ea8;
P_0c0a2ea8: /* original 53e6, guest PC 0x0c0a2ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ea8u; return 0; }
r[3]=read(ram,r[14]+24,4);
goto P_0c0a2eaa;
P_0c0a2eaa: /* original 2338, guest PC 0x0c0a2eaa */
if(!s->budget--) { s->failed_pc=0x0c0a2eaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2eac;
P_0c0a2eac: /* original 890d, guest PC 0x0c0a2eac */
if(!s->budget--) { s->failed_pc=0x0c0a2eacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2eca; }
goto P_0c0a2eae;
P_0c0a2eae: /* original 5de6, guest PC 0x0c0a2eae */
if(!s->budget--) { s->failed_pc=0x0c0a2eaeu; return 0; }
r[13]=read(ram,r[14]+24,4);
goto P_0c0a2eb0;
P_0c0a2eb0: /* original d330, guest PC 0x0c0a2eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb0u; return 0; }
r[3]=read(ram,0x0c0a2f74u,4);
goto P_0c0a2eb2;
P_0c0a2eb2: /* original 2d3b, guest PC 0x0c0a2eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb2u; return 0; }
r[13]|=r[3];
goto P_0c0a2eb4;
P_0c0a2eb4: /* original 62d2, guest PC 0x0c0a2eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0a2eb6;
P_0c0a2eb6: /* original 2228, guest PC 0x0c0a2eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2eb8;
P_0c0a2eb8: /* original 8905, guest PC 0x0c0a2eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2eb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2ec6; }
goto P_0c0a2eba;
P_0c0a2eba: /* original 52e8, guest PC 0x0c0a2eba */
if(!s->budget--) { s->failed_pc=0x0c0a2ebau; return 0; }
r[2]=read(ram,r[14]+32,4);
goto P_0c0a2ebc;
P_0c0a2ebc: /* original 420b, guest PC 0x0c0a2ebc */
if(!s->budget--) { s->failed_pc=0x0c0a2ebcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2ec0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ec0u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec0;
P_0c0a2ebe: /* original 0009, guest PC 0x0c0a2ebe */
if(!s->budget--) { s->failed_pc=0x0c0a2ebeu; return 0; }
goto P_0c0a2ec0;
P_0c0a2ec0: /* original d32d, guest PC 0x0c0a2ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec0u; return 0; }
r[3]=read(ram,0x0c0a2f78u,4);
goto P_0c0a2ec2;
P_0c0a2ec2: /* original 430b, guest PC 0x0c0a2ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ec6u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ec6u) { target=s->pc; goto dispatch; }
goto P_0c0a2ec6;
P_0c0a2ec4: /* original 54e6, guest PC 0x0c0a2ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec4u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c0a2ec6;
P_0c0a2ec6: /* original e200, guest PC 0x0c0a2ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec6u; return 0; }
r[2]=0x00000000u;
goto P_0c0a2ec8;
P_0c0a2ec8: /* original 2d22, guest PC 0x0c0a2ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ec8u; return 0; }
write(ram,r[13],r[2],4);
goto P_0c0a2eca;
P_0c0a2eca: /* original 4f26, guest PC 0x0c0a2eca */
if(!s->budget--) { s->failed_pc=0x0c0a2ecau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2ecc;
P_0c0a2ecc: /* original 6df6, guest PC 0x0c0a2ecc */
if(!s->budget--) { s->failed_pc=0x0c0a2eccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2ece;
P_0c0a2ece: /* original 000b, guest PC 0x0c0a2ece */
if(!s->budget--) { s->failed_pc=0x0c0a2eceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2ed0: /* original 6ef6, guest PC 0x0c0a2ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ed0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2ed2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2ed2u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
