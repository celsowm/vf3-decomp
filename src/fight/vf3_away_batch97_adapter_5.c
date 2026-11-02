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
int vf3_away_batch97_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0c4e34u: goto P_0c0c4e34;
case 0x0c0c4e36u: goto P_0c0c4e36;
case 0x0c0c4e38u: goto P_0c0c4e38;
case 0x0c0c4e3au: goto P_0c0c4e3a;
case 0x0c0c4e3cu: goto P_0c0c4e3c;
case 0x0c0c4e3eu: goto P_0c0c4e3e;
case 0x0c0c4e40u: goto P_0c0c4e40;
case 0x0c0c4e42u: goto P_0c0c4e42;
case 0x0c0c4e44u: goto P_0c0c4e44;
case 0x0c0c4e46u: goto P_0c0c4e46;
case 0x0c0c4e48u: goto P_0c0c4e48;
case 0x0c0c4e4au: goto P_0c0c4e4a;
case 0x0c0c4e4cu: goto P_0c0c4e4c;
case 0x0c0c4e4eu: goto P_0c0c4e4e;
case 0x0c0c4e50u: goto P_0c0c4e50;
case 0x0c0c4e52u: goto P_0c0c4e52;
case 0x0c0c4e54u: goto P_0c0c4e54;
case 0x0c0c4e56u: goto P_0c0c4e56;
case 0x0c0c4e58u: goto P_0c0c4e58;
case 0x0c0c4e5au: goto P_0c0c4e5a;
case 0x0c0c4e5cu: goto P_0c0c4e5c;
case 0x0c0c4e5eu: goto P_0c0c4e5e;
case 0x0c0c4e60u: goto P_0c0c4e60;
case 0x0c0c4e62u: goto P_0c0c4e62;
case 0x0c0c4e64u: goto P_0c0c4e64;
case 0x0c0c4e66u: goto P_0c0c4e66;
case 0x0c0c4e68u: goto P_0c0c4e68;
case 0x0c0c4e6au: goto P_0c0c4e6a;
case 0x0c0c4e6cu: goto P_0c0c4e6c;
case 0x0c0c4e6eu: goto P_0c0c4e6e;
case 0x0c0c4e70u: goto P_0c0c4e70;
case 0x0c0c4e72u: goto P_0c0c4e72;
case 0x0c0c4e74u: goto P_0c0c4e74;
case 0x0c0c4e76u: goto P_0c0c4e76;
case 0x0c0c4e78u: goto P_0c0c4e78;
case 0x0c0c4e7au: goto P_0c0c4e7a;
case 0x0c0c4e7cu: goto P_0c0c4e7c;
case 0x0c0c4e7eu: goto P_0c0c4e7e;
case 0x0c0c4e80u: goto P_0c0c4e80;
case 0x0c0c4e82u: goto P_0c0c4e82;
case 0x0c0c4e84u: goto P_0c0c4e84;
case 0x0c0c4e86u: goto P_0c0c4e86;
case 0x0c0c4e88u: goto P_0c0c4e88;
case 0x0c0c4e8au: goto P_0c0c4e8a;
case 0x0c0c4e8cu: goto P_0c0c4e8c;
case 0x0c0c4e8eu: goto P_0c0c4e8e;
case 0x0c0c4e90u: goto P_0c0c4e90;
case 0x0c0c4e92u: goto P_0c0c4e92;
case 0x0c0c4e94u: goto P_0c0c4e94;
case 0x0c0c4e96u: goto P_0c0c4e96;
case 0x0c0c4e98u: goto P_0c0c4e98;
case 0x0c0c4e9au: goto P_0c0c4e9a;
case 0x0c0c4e9cu: goto P_0c0c4e9c;
case 0x0c0c4e9eu: goto P_0c0c4e9e;
case 0x0c0c4ea0u: goto P_0c0c4ea0;
case 0x0c0c4ea2u: goto P_0c0c4ea2;
case 0x0c0c4ea4u: goto P_0c0c4ea4;
case 0x0c0c4ea6u: goto P_0c0c4ea6;
case 0x0c0c4ea8u: goto P_0c0c4ea8;
case 0x0c0c4eaau: goto P_0c0c4eaa;
case 0x0c0c4eacu: goto P_0c0c4eac;
case 0x0c0c4eaeu: goto P_0c0c4eae;
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
P_0c0c4e34: /* original 2fe6, guest PC 0x0c0c4e34 */
if(!s->budget--) { s->failed_pc=0x0c0c4e34u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e36;
P_0c0c4e36: /* original 2fd6, guest PC 0x0c0c4e36 */
if(!s->budget--) { s->failed_pc=0x0c0c4e36u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e38;
P_0c0c4e38: /* original ed00, guest PC 0x0c0c4e38 */
if(!s->budget--) { s->failed_pc=0x0c0c4e38u; return 0; }
r[13]=0x00000000u;
goto P_0c0c4e3a;
P_0c0c4e3a: /* original 2fc6, guest PC 0x0c0c4e3a */
if(!s->budget--) { s->failed_pc=0x0c0c4e3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e3c;
P_0c0c4e3c: /* original 6ed3, guest PC 0x0c0c4e3c */
if(!s->budget--) { s->failed_pc=0x0c0c4e3cu; return 0; }
r[14]=r[13];
goto P_0c0c4e3e;
P_0c0c4e3e: /* original 2fb6, guest PC 0x0c0c4e3e */
if(!s->budget--) { s->failed_pc=0x0c0c4e3eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e40;
P_0c0c4e40: /* original 2fa6, guest PC 0x0c0c4e40 */
if(!s->budget--) { s->failed_pc=0x0c0c4e40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e42;
P_0c0c4e42: /* original 2f96, guest PC 0x0c0c4e42 */
if(!s->budget--) { s->failed_pc=0x0c0c4e42u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e44;
P_0c0c4e44: /* original 2f86, guest PC 0x0c0c4e44 */
if(!s->budget--) { s->failed_pc=0x0c0c4e44u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4e46;
P_0c0c4e46: /* original fffb, guest PC 0x0c0c4e46 */
if(!s->budget--) { s->failed_pc=0x0c0c4e46u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c4e48;
P_0c0c4e48: /* original ffeb, guest PC 0x0c0c4e48 */
if(!s->budget--) { s->failed_pc=0x0c0c4e48u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c4e4a;
P_0c0c4e4a: /* original 4f22, guest PC 0x0c0c4e4a */
if(!s->budget--) { s->failed_pc=0x0c0c4e4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4e4c;
P_0c0c4e4c: /* original 7ff8, guest PC 0x0c0c4e4c */
if(!s->budget--) { s->failed_pc=0x0c0c4e4cu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c4e4e;
P_0c0c4e4e: /* original 2f42, guest PC 0x0c0c4e4e */
if(!s->budget--) { s->failed_pc=0x0c0c4e4eu; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c4e50;
P_0c0c4e50: /* original 9078, guest PC 0x0c0c4e50 */
if(!s->budget--) { s->failed_pc=0x0c0c4e50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f44u,2);
goto P_0c0c4e52;
P_0c0c4e52: /* original 9876, guest PC 0x0c0c4e52 */
if(!s->budget--) { s->failed_pc=0x0c0c4e52u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f42u,2);
goto P_0c0c4e54;
P_0c0c4e54: /* original 81f2, guest PC 0x0c0c4e54 */
if(!s->budget--) { s->failed_pc=0x0c0c4e54u; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c0c4e56;
P_0c0c4e56: /* original c740, guest PC 0x0c0c4e56 */
if(!s->budget--) { s->failed_pc=0x0c0c4e56u; return 0; }
r[0]=code_base|0x000c4f58u;
goto P_0c0c4e58;
P_0c0c4e58: /* original fe08, guest PC 0x0c0c4e58 */
if(!s->budget--) { s->failed_pc=0x0c0c4e58u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c4e5a;
P_0c0c4e5a: /* original c740, guest PC 0x0c0c4e5a */
if(!s->budget--) { s->failed_pc=0x0c0c4e5au; return 0; }
r[0]=code_base|0x000c4f5cu;
goto P_0c0c4e5c;
P_0c0c4e5c: /* original 69f2, guest PC 0x0c0c4e5c */
if(!s->budget--) { s->failed_pc=0x0c0c4e5cu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c0c4e5e;
P_0c0c4e5e: /* original 9b72, guest PC 0x0c0c4e5e */
if(!s->budget--) { s->failed_pc=0x0c0c4e5eu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f46u,2);
goto P_0c0c4e60;
P_0c0c4e60: /* original dc3f, guest PC 0x0c0c4e60 */
if(!s->budget--) { s->failed_pc=0x0c0c4e60u; return 0; }
r[12]=read(ram,0x0c0c4f60u,4);
goto P_0c0c4e62;
P_0c0c4e62: /* original 7904, guest PC 0x0c0c4e62 */
if(!s->budget--) { s->failed_pc=0x0c0c4e62u; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e64;
P_0c0c4e64: /* original ff08, guest PC 0x0c0c4e64 */
if(!s->budget--) { s->failed_pc=0x0c0c4e64u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c4e66;
P_0c0c4e66: /* original 85f2, guest PC 0x0c0c4e66 */
if(!s->budget--) { s->failed_pc=0x0c0c4e66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c0c4e68;
P_0c0c4e68: /* original 3d8c, guest PC 0x0c0c4e68 */
if(!s->budget--) { s->failed_pc=0x0c0c4e68u; return 0; }
r[13]+=r[8];
goto P_0c0c4e6a;
P_0c0c4e6a: /* original 3e0c, guest PC 0x0c0c4e6a */
if(!s->budget--) { s->failed_pc=0x0c0c4e6au; return 0; }
r[14]+=r[0];
goto P_0c0c4e6c;
P_0c0c4e6c: /* original 4c0b, guest PC 0x0c0c4e6c */
if(!s->budget--) { s->failed_pc=0x0c0c4e6cu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e70u;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e70u) { target=s->pc; goto dispatch; }
goto P_0c0c4e70;
P_0c0c4e6e: /* original 64ef, guest PC 0x0c0c4e6e */
if(!s->budget--) { s->failed_pc=0x0c0c4e6eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c4e70;
P_0c0c4e70: /* original f4fc, guest PC 0x0c0c4e70 */
if(!s->budget--) { s->failed_pc=0x0c0c4e70u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0c4e72;
P_0c0c4e72: /* original 6add, guest PC 0x0c0c4e72 */
if(!s->budget--) { s->failed_pc=0x0c0c4e72u; return 0; }
r[10]=r[13]&65535u;
goto P_0c0c4e74;
P_0c0c4e74: /* original f30c, guest PC 0x0c0c4e74 */
if(!s->budget--) { s->failed_pc=0x0c0c4e74u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e76;
P_0c0c4e76: /* original f432, guest PC 0x0c0c4e76 */
if(!s->budget--) { s->failed_pc=0x0c0c4e76u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e78;
P_0c0c4e78: /* original f43d, guest PC 0x0c0c4e78 */
if(!s->budget--) { s->failed_pc=0x0c0c4e78u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c4e7a;
P_0c0c4e7a: /* original 045a, guest PC 0x0c0c4e7a */
if(!s->budget--) { s->failed_pc=0x0c0c4e7au; return 0; }
r[4]=r[53];
goto P_0c0c4e7c;
P_0c0c4e7c: /* original 3a4c, guest PC 0x0c0c4e7c */
if(!s->budget--) { s->failed_pc=0x0c0c4e7cu; return 0; }
r[10]+=r[4];
goto P_0c0c4e7e;
P_0c0c4e7e: /* original 4c0b, guest PC 0x0c0c4e7e */
if(!s->budget--) { s->failed_pc=0x0c0c4e7eu; return 0; }
target=r[12];
r[16]=code_base|0x0c0c4e82u;
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4e82u) { target=s->pc; goto dispatch; }
goto P_0c0c4e82;
P_0c0c4e80: /* original 64af, guest PC 0x0c0c4e80 */
if(!s->budget--) { s->failed_pc=0x0c0c4e80u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[10];
goto P_0c0c4e82;
P_0c0c4e82: /* original f4ec, guest PC 0x0c0c4e82 */
if(!s->budget--) { s->failed_pc=0x0c0c4e82u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c4e84;
P_0c0c4e84: /* original 4b10, guest PC 0x0c0c4e84 */
if(!s->budget--) { s->failed_pc=0x0c0c4e84u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0c4e86;
P_0c0c4e86: /* original f30c, guest PC 0x0c0c4e86 */
if(!s->budget--) { s->failed_pc=0x0c0c4e86u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c0c4e88;
P_0c0c4e88: /* original f432, guest PC 0x0c0c4e88 */
if(!s->budget--) { s->failed_pc=0x0c0c4e88u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c4e8a;
P_0c0c4e8a: /* original 7904, guest PC 0x0c0c4e8a */
if(!s->budget--) { s->failed_pc=0x0c0c4e8au; return 0; }
r[9]+=0x00000004u;
goto P_0c0c4e8c;
P_0c0c4e8c: /* original 8feb, guest PC 0x0c0c4e8c */
if(!s->budget--) { s->failed_pc=0x0c0c4e8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,4,r[9]);
if(!cond) { goto P_0c0c4e66; }
goto P_0c0c4e90;
P_0c0c4e8e: /* original f94a, guest PC 0x0c0c4e8e */
if(!s->budget--) { s->failed_pc=0x0c0c4e8eu; return 0; }
vf3_matrix_store(s,ram,4,r[9]);
goto P_0c0c4e90;
P_0c0c4e90: /* original 62f2, guest PC 0x0c0c4e90 */
if(!s->budget--) { s->failed_pc=0x0c0c4e90u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c4e92;
P_0c0c4e92: /* original 7f08, guest PC 0x0c0c4e92 */
if(!s->budget--) { s->failed_pc=0x0c0c4e92u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c4e94;
P_0c0c4e94: /* original 4f26, guest PC 0x0c0c4e94 */
if(!s->budget--) { s->failed_pc=0x0c0c4e94u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e96;
P_0c0c4e96: /* original 9057, guest PC 0x0c0c4e96 */
if(!s->budget--) { s->failed_pc=0x0c0c4e96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4f48u,2);
goto P_0c0c4e98;
P_0c0c4e98: /* original e300, guest PC 0x0c0c4e98 */
if(!s->budget--) { s->failed_pc=0x0c0c4e98u; return 0; }
r[3]=0x00000000u;
goto P_0c0c4e9a;
P_0c0c4e9a: /* original 0236, guest PC 0x0c0c4e9a */
if(!s->budget--) { s->failed_pc=0x0c0c4e9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c0c4e9c;
P_0c0c4e9c: /* original fef9, guest PC 0x0c0c4e9c */
if(!s->budget--) { s->failed_pc=0x0c0c4e9cu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4e9e;
P_0c0c4e9e: /* original fff9, guest PC 0x0c0c4e9e */
if(!s->budget--) { s->failed_pc=0x0c0c4e9eu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c4ea0;
P_0c0c4ea0: /* original 68f6, guest PC 0x0c0c4ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c4ea2;
P_0c0c4ea2: /* original 69f6, guest PC 0x0c0c4ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c4ea4;
P_0c0c4ea4: /* original 6af6, guest PC 0x0c0c4ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c4ea6;
P_0c0c4ea6: /* original 6bf6, guest PC 0x0c0c4ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c4ea8;
P_0c0c4ea8: /* original 6cf6, guest PC 0x0c0c4ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c4ea8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c4eaa;
P_0c0c4eaa: /* original 6df6, guest PC 0x0c0c4eaa */
if(!s->budget--) { s->failed_pc=0x0c0c4eaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4eac;
P_0c0c4eac: /* original 000b, guest PC 0x0c0c4eac */
if(!s->budget--) { s->failed_pc=0x0c0c4eacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4eae: /* original 6ef6, guest PC 0x0c0c4eae */
if(!s->budget--) { s->failed_pc=0x0c0c4eaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c4eb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4eb0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
