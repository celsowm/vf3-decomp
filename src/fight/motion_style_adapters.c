/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_motion_style_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c094a36u: goto P_0c094a36;
case 0x0c094a38u: goto P_0c094a38;
case 0x0c094a3au: goto P_0c094a3a;
case 0x0c094a3cu: goto P_0c094a3c;
case 0x0c094a3eu: goto P_0c094a3e;
case 0x0c094a40u: goto P_0c094a40;
case 0x0c094a42u: goto P_0c094a42;
case 0x0c094a44u: goto P_0c094a44;
case 0x0c094a46u: goto P_0c094a46;
case 0x0c094a48u: goto P_0c094a48;
case 0x0c094a4au: goto P_0c094a4a;
case 0x0c094a4cu: goto P_0c094a4c;
case 0x0c094a4eu: goto P_0c094a4e;
case 0x0c094a74u: goto P_0c094a74;
case 0x0c094a76u: goto P_0c094a76;
case 0x0c094a78u: goto P_0c094a78;
case 0x0c094a7au: goto P_0c094a7a;
case 0x0c094a7cu: goto P_0c094a7c;
case 0x0c094a7eu: goto P_0c094a7e;
case 0x0c094a80u: goto P_0c094a80;
case 0x0c094a82u: goto P_0c094a82;
case 0x0c094a84u: goto P_0c094a84;
case 0x0c094a86u: goto P_0c094a86;
case 0x0c094a88u: goto P_0c094a88;
case 0x0c094a8au: goto P_0c094a8a;
case 0x0c094a8cu: goto P_0c094a8c;
case 0x0c094a8eu: goto P_0c094a8e;
case 0x0c094a90u: goto P_0c094a90;
case 0x0c094a92u: goto P_0c094a92;
case 0x0c094a94u: goto P_0c094a94;
case 0x0c094a96u: goto P_0c094a96;
case 0x0c094a98u: goto P_0c094a98;
case 0x0c094a9au: goto P_0c094a9a;
case 0x0c094a9cu: goto P_0c094a9c;
case 0x0c094a9eu: goto P_0c094a9e;
case 0x0c094aa0u: goto P_0c094aa0;
case 0x0c094aa2u: goto P_0c094aa2;
case 0x0c094aa4u: goto P_0c094aa4;
case 0x0c094aa6u: goto P_0c094aa6;
case 0x0c094aa8u: goto P_0c094aa8;
case 0x0c094aaau: goto P_0c094aaa;
case 0x0c094aacu: goto P_0c094aac;
case 0x0c094aaeu: goto P_0c094aae;
case 0x0c094ab0u: goto P_0c094ab0;
case 0x0c094ab2u: goto P_0c094ab2;
case 0x0c094ab4u: goto P_0c094ab4;
case 0x0c094ab6u: goto P_0c094ab6;
case 0x0c094ab8u: goto P_0c094ab8;
case 0x0c094abau: goto P_0c094aba;
case 0x0c094abcu: goto P_0c094abc;
case 0x0c094abeu: goto P_0c094abe;
case 0x0c094ac0u: goto P_0c094ac0;
case 0x0c094ac2u: goto P_0c094ac2;
case 0x0c094ac4u: goto P_0c094ac4;
case 0x0c094ac6u: goto P_0c094ac6;
case 0x0c094ac8u: goto P_0c094ac8;
case 0x0c094acau: goto P_0c094aca;
case 0x0c094accu: goto P_0c094acc;
case 0x0c094aceu: goto P_0c094ace;
case 0x0c094ad0u: goto P_0c094ad0;
case 0x0c094ad2u: goto P_0c094ad2;
case 0x0c094ad4u: goto P_0c094ad4;
case 0x0c094ad6u: goto P_0c094ad6;
case 0x0c094ad8u: goto P_0c094ad8;
case 0x0c094adau: goto P_0c094ada;
case 0x0c094adcu: goto P_0c094adc;
case 0x0c094adeu: goto P_0c094ade;
case 0x0c094ae0u: goto P_0c094ae0;
case 0x0c094ae2u: goto P_0c094ae2;
case 0x0c094ae4u: goto P_0c094ae4;
case 0x0c094ae6u: goto P_0c094ae6;
case 0x0c094ae8u: goto P_0c094ae8;
case 0x0c094aeau: goto P_0c094aea;
case 0x0c094aecu: goto P_0c094aec;
case 0x0c094aeeu: goto P_0c094aee;
case 0x0c094af0u: goto P_0c094af0;
case 0x0c094af2u: goto P_0c094af2;
case 0x0c094af4u: goto P_0c094af4;
case 0x0c094af6u: goto P_0c094af6;
case 0x0c094af8u: goto P_0c094af8;
case 0x0c094afau: goto P_0c094afa;
case 0x0c094afcu: goto P_0c094afc;
case 0x0c094afeu: goto P_0c094afe;
case 0x0c094b00u: goto P_0c094b00;
case 0x0c094b02u: goto P_0c094b02;
case 0x0c094b04u: goto P_0c094b04;
case 0x0c094b06u: goto P_0c094b06;
case 0x0c094b08u: goto P_0c094b08;
case 0x0c094b0au: goto P_0c094b0a;
case 0x0c094b0cu: goto P_0c094b0c;
case 0x0c094b0eu: goto P_0c094b0e;
case 0x0c094b10u: goto P_0c094b10;
case 0x0c094b12u: goto P_0c094b12;
case 0x0c094b14u: goto P_0c094b14;
case 0x0c094b16u: goto P_0c094b16;
case 0x0c094b18u: goto P_0c094b18;
case 0x0c094b1au: goto P_0c094b1a;
case 0x0c094b1cu: goto P_0c094b1c;
case 0x0c094b1eu: goto P_0c094b1e;
case 0x0c094b20u: goto P_0c094b20;
case 0x0c094b22u: goto P_0c094b22;
case 0x0c094b24u: goto P_0c094b24;
case 0x0c094b26u: goto P_0c094b26;
case 0x0c094b28u: goto P_0c094b28;
case 0x0c094dc6u: goto P_0c094dc6;
case 0x0c094dc8u: goto P_0c094dc8;
case 0x0c094dcau: goto P_0c094dca;
case 0x0c094dccu: goto P_0c094dcc;
case 0x0c094dceu: goto P_0c094dce;
case 0x0c094dd0u: goto P_0c094dd0;
case 0x0c094dd2u: goto P_0c094dd2;
case 0x0c094dd4u: goto P_0c094dd4;
case 0x0c094dd6u: goto P_0c094dd6;
case 0x0c094dd8u: goto P_0c094dd8;
case 0x0c094ddau: goto P_0c094dda;
case 0x0c094ddcu: goto P_0c094ddc;
case 0x0c094ddeu: goto P_0c094dde;
case 0x0c094de0u: goto P_0c094de0;
case 0x0c094de2u: goto P_0c094de2;
case 0x0c094de4u: goto P_0c094de4;
case 0x0c094de6u: goto P_0c094de6;
case 0x0c094de8u: goto P_0c094de8;
case 0x0c094deau: goto P_0c094dea;
case 0x0c094decu: goto P_0c094dec;
case 0x0c094deeu: goto P_0c094dee;
case 0x0c094df0u: goto P_0c094df0;
case 0x0c094df2u: goto P_0c094df2;
case 0x0c094df4u: goto P_0c094df4;
case 0x0c094df6u: goto P_0c094df6;
case 0x0c094df8u: goto P_0c094df8;
case 0x0c094dfau: goto P_0c094dfa;
case 0x0c094dfcu: goto P_0c094dfc;
case 0x0c094dfeu: goto P_0c094dfe;
case 0x0c094e00u: goto P_0c094e00;
case 0x0c094e02u: goto P_0c094e02;
case 0x0c094e04u: goto P_0c094e04;
case 0x0c094e06u: goto P_0c094e06;
case 0x0c094e08u: goto P_0c094e08;
case 0x0c094e0au: goto P_0c094e0a;
case 0x0c094e0cu: goto P_0c094e0c;
case 0x0c094e0eu: goto P_0c094e0e;
case 0x0c094e10u: goto P_0c094e10;
case 0x0c094e12u: goto P_0c094e12;
case 0x0c094e14u: goto P_0c094e14;
case 0x0c094e16u: goto P_0c094e16;
case 0x0c094e18u: goto P_0c094e18;
case 0x0c094e1au: goto P_0c094e1a;
case 0x0c094e1cu: goto P_0c094e1c;
case 0x0c094e1eu: goto P_0c094e1e;
case 0x0c094e20u: goto P_0c094e20;
case 0x0c094e22u: goto P_0c094e22;
case 0x0c094e24u: goto P_0c094e24;
case 0x0c094e26u: goto P_0c094e26;
case 0x0c094e28u: goto P_0c094e28;
case 0x0c094e2au: goto P_0c094e2a;
case 0x0c094e2cu: goto P_0c094e2c;
case 0x0c094e2eu: goto P_0c094e2e;
case 0x0c094e30u: goto P_0c094e30;
case 0x0c094e32u: goto P_0c094e32;
case 0x0c094e34u: goto P_0c094e34;
case 0x0c094e36u: goto P_0c094e36;
case 0x0c094e38u: goto P_0c094e38;
case 0x0c094e3au: goto P_0c094e3a;
case 0x0c094e3cu: goto P_0c094e3c;
case 0x0c094e3eu: goto P_0c094e3e;
case 0x0c094e40u: goto P_0c094e40;
case 0x0c094e42u: goto P_0c094e42;
case 0x0c094e44u: goto P_0c094e44;
case 0x0c094e46u: goto P_0c094e46;
case 0x0c094e48u: goto P_0c094e48;
case 0x0c094e4au: goto P_0c094e4a;
case 0x0c094e4cu: goto P_0c094e4c;
case 0x0c094e4eu: goto P_0c094e4e;
case 0x0c094e50u: goto P_0c094e50;
case 0x0c094e52u: goto P_0c094e52;
case 0x0c094e54u: goto P_0c094e54;
case 0x0c094e56u: goto P_0c094e56;
case 0x0c094e58u: goto P_0c094e58;
case 0x0c094e5au: goto P_0c094e5a;
case 0x0c094e5cu: goto P_0c094e5c;
case 0x0c094e5eu: goto P_0c094e5e;
case 0x0c094e60u: goto P_0c094e60;
case 0x0c094e62u: goto P_0c094e62;
case 0x0c094e64u: goto P_0c094e64;
case 0x0c094e66u: goto P_0c094e66;
case 0x0c094e68u: goto P_0c094e68;
case 0x0c094e6au: goto P_0c094e6a;
case 0x0c094e6cu: goto P_0c094e6c;
case 0x0c094e6eu: goto P_0c094e6e;
case 0x0c094e70u: goto P_0c094e70;
case 0x0c094e72u: goto P_0c094e72;
case 0x0c094e74u: goto P_0c094e74;
case 0x0c094e76u: goto P_0c094e76;
case 0x0c094e78u: goto P_0c094e78;
case 0x0c094e7au: goto P_0c094e7a;
case 0x0c094e7cu: goto P_0c094e7c;
case 0x0c094e7eu: goto P_0c094e7e;
case 0x0c094e80u: goto P_0c094e80;
case 0x0c094e82u: goto P_0c094e82;
case 0x0c094e84u: goto P_0c094e84;
case 0x0c094e86u: goto P_0c094e86;
case 0x0c094e88u: goto P_0c094e88;
case 0x0c094e8au: goto P_0c094e8a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c094a36: /* original 4f22, guest PC 0x0c094a36 */
if(!s->budget--) { s->failed_pc=0x0c094a36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094a38;
P_0c094a38: /* original d30c, guest PC 0x0c094a38 */
if(!s->budget--) { s->failed_pc=0x0c094a38u; return 0; }
r[3]=read(ram,0x0c094a6cu,4);
goto P_0c094a3a;
P_0c094a3a: /* original d609, guest PC 0x0c094a3a */
if(!s->budget--) { s->failed_pc=0x0c094a3au; return 0; }
r[6]=read(ram,0x0c094a60u,4);
goto P_0c094a3c;
P_0c094a3c: /* original 7ffc, guest PC 0x0c094a3c */
if(!s->budget--) { s->failed_pc=0x0c094a3cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c094a3e;
P_0c094a3e: /* original 2f32, guest PC 0x0c094a3e */
if(!s->budget--) { s->failed_pc=0x0c094a3eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c094a40;
P_0c094a40: /* original 8444, guest PC 0x0c094a40 */
if(!s->budget--) { s->failed_pc=0x0c094a40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c094a42;
P_0c094a42: /* original d70b, guest PC 0x0c094a42 */
if(!s->budget--) { s->failed_pc=0x0c094a42u; return 0; }
r[7]=read(ram,0x0c094a70u,4);
goto P_0c094a44;
P_0c094a44: /* original 2008, guest PC 0x0c094a44 */
if(!s->budget--) { s->failed_pc=0x0c094a44u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c094a46;
P_0c094a46: /* original 8f15, guest PC 0x0c094a46 */
if(!s->budget--) { s->failed_pc=0x0c094a46u; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
if(!cond) { goto P_0c094a74; }
goto P_0c094a4a;
P_0c094a48: /* original 8468, guest PC 0x0c094a48 */
if(!s->budget--) { s->failed_pc=0x0c094a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c094a4a;
P_0c094a4a: /* original 5e7a, guest PC 0x0c094a4a */
if(!s->budget--) { s->failed_pc=0x0c094a4au; return 0; }
r[14]=read(ram,r[7]+40,4);
goto P_0c094a4c;
P_0c094a4c: /* original a014, guest PC 0x0c094a4c */
if(!s->budget--) { s->failed_pc=0x0c094a4cu; return 0; }
r[5]=read(ram,r[7]+16,4);
goto P_0c094a78;
P_0c094a4e: /* original 5574, guest PC 0x0c094a4e */
if(!s->budget--) { s->failed_pc=0x0c094a4eu; return 0; }
r[5]=read(ram,r[7]+16,4);
return vf3_matrix_family(0x0c094a50u,s,ram);
P_0c094a74: /* original 5575, guest PC 0x0c094a74 */
if(!s->budget--) { s->failed_pc=0x0c094a74u; return 0; }
r[5]=read(ram,r[7]+20,4);
goto P_0c094a76;
P_0c094a76: /* original 5e7b, guest PC 0x0c094a76 */
if(!s->budget--) { s->failed_pc=0x0c094a76u; return 0; }
r[14]=read(ram,r[7]+44,4);
goto P_0c094a78;
P_0c094a78: /* original 600c, guest PC 0x0c094a78 */
if(!s->budget--) { s->failed_pc=0x0c094a78u; return 0; }
r[0]=r[0]&255u;
goto P_0c094a7a;
P_0c094a7a: /* original 8804, guest PC 0x0c094a7a */
if(!s->budget--) { s->failed_pc=0x0c094a7au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c094a7c;
P_0c094a7c: /* original 8d03, guest PC 0x0c094a7c */
if(!s->budget--) { s->failed_pc=0x0c094a7cu; return 0; }
cond=r[17]&1u;
r[7]=r[0];
if(cond) { goto P_0c094a86; }
goto P_0c094a80;
P_0c094a7e: /* original 6703, guest PC 0x0c094a7e */
if(!s->budget--) { s->failed_pc=0x0c094a7eu; return 0; }
r[7]=r[0];
goto P_0c094a80;
P_0c094a80: /* original 6073, guest PC 0x0c094a80 */
if(!s->budget--) { s->failed_pc=0x0c094a80u; return 0; }
r[0]=r[7];
goto P_0c094a82;
P_0c094a82: /* original 8805, guest PC 0x0c094a82 */
if(!s->budget--) { s->failed_pc=0x0c094a82u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c094a84;
P_0c094a84: /* original 8b0e, guest PC 0x0c094a84 */
if(!s->budget--) { s->failed_pc=0x0c094a84u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094aa4; }
goto P_0c094a86;
P_0c094a86: /* original e060, guest PC 0x0c094a86 */
if(!s->budget--) { s->failed_pc=0x0c094a86u; return 0; }
r[0]=0x00000060u;
goto P_0c094a88;
P_0c094a88: /* original d333, guest PC 0x0c094a88 */
if(!s->budget--) { s->failed_pc=0x0c094a88u; return 0; }
r[3]=read(ram,0x0c094b58u,4);
goto P_0c094a8a;
P_0c094a8a: /* original 055c, guest PC 0x0c094a8a */
if(!s->budget--) { s->failed_pc=0x0c094a8au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c094a8c;
P_0c094a8c: /* original 7040, guest PC 0x0c094a8c */
if(!s->budget--) { s->failed_pc=0x0c094a8cu; return 0; }
r[0]+=0x00000040u;
goto P_0c094a8e;
P_0c094a8e: /* original 066e, guest PC 0x0c094a8e */
if(!s->budget--) { s->failed_pc=0x0c094a8eu; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c094a90;
P_0c094a90: /* original 655c, guest PC 0x0c094a90 */
if(!s->budget--) { s->failed_pc=0x0c094a90u; return 0; }
r[5]=r[5]&255u;
goto P_0c094a92;
P_0c094a92: /* original 465d, guest PC 0x0c094a92 */
if(!s->budget--) { s->failed_pc=0x0c094a92u; return 0; }
r[6]=(r[5]&0x80000000u)?((r[5]&31u)?r[6]>>((-r[5])&31u):0):r[6]<<(r[5]&31u);
goto P_0c094a94;
P_0c094a94: /* original 2638, guest PC 0x0c094a94 */
if(!s->budget--) { s->failed_pc=0x0c094a94u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c094a96;
P_0c094a96: /* original 893f, guest PC 0x0c094a96 */
if(!s->budget--) { s->failed_pc=0x0c094a96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094b18; }
goto P_0c094a98;
P_0c094a98: /* original e057, guest PC 0x0c094a98 */
if(!s->budget--) { s->failed_pc=0x0c094a98u; return 0; }
r[0]=0x00000057u;
goto P_0c094a9a;
P_0c094a9a: /* original 02ec, guest PC 0x0c094a9a */
if(!s->budget--) { s->failed_pc=0x0c094a9au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c094a9c;
P_0c094a9c: /* original 2228, guest PC 0x0c094a9c */
if(!s->budget--) { s->failed_pc=0x0c094a9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c094a9e;
P_0c094a9e: /* original 8b3b, guest PC 0x0c094a9e */
if(!s->budget--) { s->failed_pc=0x0c094a9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094b18; }
goto P_0c094aa0;
P_0c094aa0: /* original a02b, guest PC 0x0c094aa0 */
if(!s->budget--) { s->failed_pc=0x0c094aa0u; return 0; }
goto P_0c094afa;
P_0c094aa2: /* original 0009, guest PC 0x0c094aa2 */
if(!s->budget--) { s->failed_pc=0x0c094aa2u; return 0; }
goto P_0c094aa4;
P_0c094aa4: /* original 9055, guest PC 0x0c094aa4 */
if(!s->budget--) { s->failed_pc=0x0c094aa4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094b52u,2);
goto P_0c094aa6;
P_0c094aa6: /* original 67f2, guest PC 0x0c094aa6 */
if(!s->budget--) { s->failed_pc=0x0c094aa6u; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c094aa8;
P_0c094aa8: /* original 077e, guest PC 0x0c094aa8 */
if(!s->budget--) { s->failed_pc=0x0c094aa8u; return 0; }
r[7]=read(ram,r[7]+r[0],4);
goto P_0c094aaa;
P_0c094aaa: /* original 8444, guest PC 0x0c094aaa */
if(!s->budget--) { s->failed_pc=0x0c094aaau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c094aac;
P_0c094aac: /* original 6303, guest PC 0x0c094aac */
if(!s->budget--) { s->failed_pc=0x0c094aacu; return 0; }
r[3]=r[0];
goto P_0c094aae;
P_0c094aae: /* original 8474, guest PC 0x0c094aae */
if(!s->budget--) { s->failed_pc=0x0c094aaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c094ab0;
P_0c094ab0: /* original 3300, guest PC 0x0c094ab0 */
if(!s->budget--) { s->failed_pc=0x0c094ab0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c094ab2;
P_0c094ab2: /* original 8b31, guest PC 0x0c094ab2 */
if(!s->budget--) { s->failed_pc=0x0c094ab2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094b18; }
goto P_0c094ab4;
P_0c094ab4: /* original e060, guest PC 0x0c094ab4 */
if(!s->budget--) { s->failed_pc=0x0c094ab4u; return 0; }
r[0]=0x00000060u;
goto P_0c094ab6;
P_0c094ab6: /* original 057c, guest PC 0x0c094ab6 */
if(!s->budget--) { s->failed_pc=0x0c094ab6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094ab8;
P_0c094ab8: /* original 7040, guest PC 0x0c094ab8 */
if(!s->budget--) { s->failed_pc=0x0c094ab8u; return 0; }
r[0]+=0x00000040u;
goto P_0c094aba;
P_0c094aba: /* original 036e, guest PC 0x0c094aba */
if(!s->budget--) { s->failed_pc=0x0c094abau; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c094abc;
P_0c094abc: /* original 655c, guest PC 0x0c094abc */
if(!s->budget--) { s->failed_pc=0x0c094abcu; return 0; }
r[5]=r[5]&255u;
goto P_0c094abe;
P_0c094abe: /* original 6233, guest PC 0x0c094abe */
if(!s->budget--) { s->failed_pc=0x0c094abeu; return 0; }
r[2]=r[3];
goto P_0c094ac0;
P_0c094ac0: /* original 2f32, guest PC 0x0c094ac0 */
if(!s->budget--) { s->failed_pc=0x0c094ac0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c094ac2;
P_0c094ac2: /* original d325, guest PC 0x0c094ac2 */
if(!s->budget--) { s->failed_pc=0x0c094ac2u; return 0; }
r[3]=read(ram,0x0c094b58u,4);
goto P_0c094ac4;
P_0c094ac4: /* original 425d, guest PC 0x0c094ac4 */
if(!s->budget--) { s->failed_pc=0x0c094ac4u; return 0; }
r[2]=(r[5]&0x80000000u)?((r[5]&31u)?r[2]>>((-r[5])&31u):0):r[2]<<(r[5]&31u);
goto P_0c094ac6;
P_0c094ac6: /* original 2238, guest PC 0x0c094ac6 */
if(!s->budget--) { s->failed_pc=0x0c094ac6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c094ac8;
P_0c094ac8: /* original 8926, guest PC 0x0c094ac8 */
if(!s->budget--) { s->failed_pc=0x0c094ac8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094b18; }
goto P_0c094aca;
P_0c094aca: /* original e061, guest PC 0x0c094aca */
if(!s->budget--) { s->failed_pc=0x0c094acau; return 0; }
r[0]=0x00000061u;
goto P_0c094acc;
P_0c094acc: /* original 007c, guest PC 0x0c094acc */
if(!s->budget--) { s->failed_pc=0x0c094accu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094ace;
P_0c094ace: /* original 600c, guest PC 0x0c094ace */
if(!s->budget--) { s->failed_pc=0x0c094aceu; return 0; }
r[0]=r[0]&255u;
goto P_0c094ad0;
P_0c094ad0: /* original 8803, guest PC 0x0c094ad0 */
if(!s->budget--) { s->failed_pc=0x0c094ad0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c094ad2;
P_0c094ad2: /* original 8b10, guest PC 0x0c094ad2 */
if(!s->budget--) { s->failed_pc=0x0c094ad2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094af6; }
goto P_0c094ad4;
P_0c094ad4: /* original 903e, guest PC 0x0c094ad4 */
if(!s->budget--) { s->failed_pc=0x0c094ad4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094b54u,2);
goto P_0c094ad6;
P_0c094ad6: /* original 027e, guest PC 0x0c094ad6 */
if(!s->budget--) { s->failed_pc=0x0c094ad6u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c094ad8;
P_0c094ad8: /* original 2228, guest PC 0x0c094ad8 */
if(!s->budget--) { s->failed_pc=0x0c094ad8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c094ada;
P_0c094ada: /* original 8b0c, guest PC 0x0c094ada */
if(!s->budget--) { s->failed_pc=0x0c094adau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094af6; }
goto P_0c094adc;
P_0c094adc: /* original 903b, guest PC 0x0c094adc */
if(!s->budget--) { s->failed_pc=0x0c094adcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094b56u,2);
goto P_0c094ade;
P_0c094ade: /* original e301, guest PC 0x0c094ade */
if(!s->budget--) { s->failed_pc=0x0c094adeu; return 0; }
r[3]=0x00000001u;
goto P_0c094ae0;
P_0c094ae0: /* original 7f04, guest PC 0x0c094ae0 */
if(!s->budget--) { s->failed_pc=0x0c094ae0u; return 0; }
r[15]+=0x00000004u;
goto P_0c094ae2;
P_0c094ae2: /* original 026e, guest PC 0x0c094ae2 */
if(!s->budget--) { s->failed_pc=0x0c094ae2u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c094ae4;
P_0c094ae4: /* original 4f26, guest PC 0x0c094ae4 */
if(!s->budget--) { s->failed_pc=0x0c094ae4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094ae6;
P_0c094ae6: /* original 2239, guest PC 0x0c094ae6 */
if(!s->budget--) { s->failed_pc=0x0c094ae6u; return 0; }
r[2]&=r[3];
goto P_0c094ae8;
P_0c094ae8: /* original 0626, guest PC 0x0c094ae8 */
if(!s->budget--) { s->failed_pc=0x0c094ae8u; return 0; }
write(ram,r[6]+r[0],r[2],4);
goto P_0c094aea;
P_0c094aea: /* original e2fe, guest PC 0x0c094aea */
if(!s->budget--) { s->failed_pc=0x0c094aeau; return 0; }
r[2]=0xfffffffeu;
goto P_0c094aec;
P_0c094aec: /* original 6142, guest PC 0x0c094aec */
if(!s->budget--) { s->failed_pc=0x0c094aecu; return 0; }
tmp=read(ram,r[4],4);
r[1]=tmp;
goto P_0c094aee;
P_0c094aee: /* original 2129, guest PC 0x0c094aee */
if(!s->budget--) { s->failed_pc=0x0c094aeeu; return 0; }
r[1]&=r[2];
goto P_0c094af0;
P_0c094af0: /* original 2412, guest PC 0x0c094af0 */
if(!s->budget--) { s->failed_pc=0x0c094af0u; return 0; }
write(ram,r[4],r[1],4);
goto P_0c094af2;
P_0c094af2: /* original 000b, guest PC 0x0c094af2 */
if(!s->budget--) { s->failed_pc=0x0c094af2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094af4: /* original 6ef6, guest PC 0x0c094af4 */
if(!s->budget--) { s->failed_pc=0x0c094af4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094af6;
P_0c094af6: /* original d319, guest PC 0x0c094af6 */
if(!s->budget--) { s->failed_pc=0x0c094af6u; return 0; }
r[3]=read(ram,0x0c094b5cu,4);
goto P_0c094af8;
P_0c094af8: /* original 2350, guest PC 0x0c094af8 */
if(!s->budget--) { s->failed_pc=0x0c094af8u; return 0; }
write(ram,r[3],r[5],1);
goto P_0c094afa;
P_0c094afa: /* original e057, guest PC 0x0c094afa */
if(!s->budget--) { s->failed_pc=0x0c094afau; return 0; }
r[0]=0x00000057u;
goto P_0c094afc;
P_0c094afc: /* original 6353, guest PC 0x0c094afc */
if(!s->budget--) { s->failed_pc=0x0c094afcu; return 0; }
r[3]=r[5];
goto P_0c094afe;
P_0c094afe: /* original e201, guest PC 0x0c094afe */
if(!s->budget--) { s->failed_pc=0x0c094afeu; return 0; }
r[2]=0x00000001u;
goto P_0c094b00;
P_0c094b00: /* original 0e24, guest PC 0x0c094b00 */
if(!s->budget--) { s->failed_pc=0x0c094b00u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c094b02;
P_0c094b02: /* original 4308, guest PC 0x0c094b02 */
if(!s->budget--) { s->failed_pc=0x0c094b02u; return 0; }
r[3]<<=2;
goto P_0c094b04;
P_0c094b04: /* original 6253, guest PC 0x0c094b04 */
if(!s->budget--) { s->failed_pc=0x0c094b04u; return 0; }
r[2]=r[5];
goto P_0c094b06;
P_0c094b06: /* original d116, guest PC 0x0c094b06 */
if(!s->budget--) { s->failed_pc=0x0c094b06u; return 0; }
r[1]=read(ram,0x0c094b60u,4);
goto P_0c094b08;
P_0c094b08: /* original 332c, guest PC 0x0c094b08 */
if(!s->budget--) { s->failed_pc=0x0c094b08u; return 0; }
r[3]+=r[2];
goto P_0c094b0a;
P_0c094b0a: /* original 4308, guest PC 0x0c094b0a */
if(!s->budget--) { s->failed_pc=0x0c094b0au; return 0; }
r[3]<<=2;
goto P_0c094b0c;
P_0c094b0c: /* original 331c, guest PC 0x0c094b0c */
if(!s->budget--) { s->failed_pc=0x0c094b0cu; return 0; }
r[3]+=r[1];
goto P_0c094b0e;
P_0c094b0e: /* original 1434, guest PC 0x0c094b0e */
if(!s->budget--) { s->failed_pc=0x0c094b0eu; return 0; }
write(ram,r[4]+16,r[3],4);
goto P_0c094b10;
P_0c094b10: /* original 1455, guest PC 0x0c094b10 */
if(!s->budget--) { s->failed_pc=0x0c094b10u; return 0; }
write(ram,r[4]+20,r[5],4);
goto P_0c094b12;
P_0c094b12: /* original d314, guest PC 0x0c094b12 */
if(!s->budget--) { s->failed_pc=0x0c094b12u; return 0; }
r[3]=read(ram,0x0c094b64u,4);
goto P_0c094b14;
P_0c094b14: /* original b004, guest PC 0x0c094b14 */
if(!s->budget--) { s->failed_pc=0x0c094b14u; return 0; }
target=0x0c094b20u; r[16]=0x0c094b18u;
write(ram,r[4]+12,r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094b18u) { target=s->pc; goto dispatch; }
goto P_0c094b18;
P_0c094b16: /* original 1433, guest PC 0x0c094b16 */
if(!s->budget--) { s->failed_pc=0x0c094b16u; return 0; }
write(ram,r[4]+12,r[3],4);
goto P_0c094b18;
P_0c094b18: /* original 7f04, guest PC 0x0c094b18 */
if(!s->budget--) { s->failed_pc=0x0c094b18u; return 0; }
r[15]+=0x00000004u;
goto P_0c094b1a;
P_0c094b1a: /* original 4f26, guest PC 0x0c094b1a */
if(!s->budget--) { s->failed_pc=0x0c094b1au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094b1c;
P_0c094b1c: /* original 000b, guest PC 0x0c094b1c */
if(!s->budget--) { s->failed_pc=0x0c094b1cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094b1e: /* original 6ef6, guest PC 0x0c094b1e */
if(!s->budget--) { s->failed_pc=0x0c094b1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094b20;
P_0c094b20: /* original 2fe6, guest PC 0x0c094b20 */
if(!s->budget--) { s->failed_pc=0x0c094b20u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b22;
P_0c094b22: /* original 6e43, guest PC 0x0c094b22 */
if(!s->budget--) { s->failed_pc=0x0c094b22u; return 0; }
r[14]=r[4];
goto P_0c094b24;
P_0c094b24: /* original 2fd6, guest PC 0x0c094b24 */
if(!s->budget--) { s->failed_pc=0x0c094b24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b26;
P_0c094b26: /* original 2fc6, guest PC 0x0c094b26 */
if(!s->budget--) { s->failed_pc=0x0c094b26u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094b28;
P_0c094b28: /* original d70f, guest PC 0x0c094b28 */
if(!s->budget--) { s->failed_pc=0x0c094b28u; return 0; }
r[7]=read(ram,0x0c094b68u,4);
return vf3_matrix_family(0x0c094b2au,s,ram);
P_0c094dc6: /* original 4f22, guest PC 0x0c094dc6 */
if(!s->budget--) { s->failed_pc=0x0c094dc6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c094dc8;
P_0c094dc8: /* original 6ed3, guest PC 0x0c094dc8 */
if(!s->budget--) { s->failed_pc=0x0c094dc8u; return 0; }
r[14]=r[13];
goto P_0c094dca;
P_0c094dca: /* original 3e5c, guest PC 0x0c094dca */
if(!s->budget--) { s->failed_pc=0x0c094dcau; return 0; }
r[14]+=r[5];
goto P_0c094dcc;
P_0c094dcc: /* original 3300, guest PC 0x0c094dcc */
if(!s->budget--) { s->failed_pc=0x0c094dccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[0])!=0);
goto P_0c094dce;
P_0c094dce: /* original 61e3, guest PC 0x0c094dce */
if(!s->budget--) { s->failed_pc=0x0c094dceu; return 0; }
r[1]=r[14];
goto P_0c094dd0;
P_0c094dd0: /* original 8f47, guest PC 0x0c094dd0 */
if(!s->budget--) { s->failed_pc=0x0c094dd0u; return 0; }
cond=r[17]&1u;
r[1]+=r[5];
if(!cond) { goto P_0c094e62; }
goto P_0c094dd4;
P_0c094dd2: /* original 315c, guest PC 0x0c094dd2 */
if(!s->budget--) { s->failed_pc=0x0c094dd2u; return 0; }
r[1]+=r[5];
goto P_0c094dd4;
P_0c094dd4: /* original e060, guest PC 0x0c094dd4 */
if(!s->budget--) { s->failed_pc=0x0c094dd4u; return 0; }
r[0]=0x00000060u;
goto P_0c094dd6;
P_0c094dd6: /* original 057c, guest PC 0x0c094dd6 */
if(!s->budget--) { s->failed_pc=0x0c094dd6u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094dd8;
P_0c094dd8: /* original 605c, guest PC 0x0c094dd8 */
if(!s->budget--) { s->failed_pc=0x0c094dd8u; return 0; }
r[0]=r[5]&255u;
goto P_0c094dda;
P_0c094dda: /* original 8807, guest PC 0x0c094dda */
if(!s->budget--) { s->failed_pc=0x0c094ddau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c094ddc;
P_0c094ddc: /* original 8d0a, guest PC 0x0c094ddc */
if(!s->budget--) { s->failed_pc=0x0c094ddcu; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c094df4; }
goto P_0c094de0;
P_0c094dde: /* original 6503, guest PC 0x0c094dde */
if(!s->budget--) { s->failed_pc=0x0c094ddeu; return 0; }
r[5]=r[0];
goto P_0c094de0;
P_0c094de0: /* original 6053, guest PC 0x0c094de0 */
if(!s->budget--) { s->failed_pc=0x0c094de0u; return 0; }
r[0]=r[5];
goto P_0c094de2;
P_0c094de2: /* original 8805, guest PC 0x0c094de2 */
if(!s->budget--) { s->failed_pc=0x0c094de2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c094de4;
P_0c094de4: /* original 8906, guest PC 0x0c094de4 */
if(!s->budget--) { s->failed_pc=0x0c094de4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094df4; }
goto P_0c094de6;
P_0c094de6: /* original 6053, guest PC 0x0c094de6 */
if(!s->budget--) { s->failed_pc=0x0c094de6u; return 0; }
r[0]=r[5];
goto P_0c094de8;
P_0c094de8: /* original 8812, guest PC 0x0c094de8 */
if(!s->budget--) { s->failed_pc=0x0c094de8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c094dea;
P_0c094dea: /* original 8903, guest PC 0x0c094dea */
if(!s->budget--) { s->failed_pc=0x0c094deau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094df4; }
goto P_0c094dec;
P_0c094dec: /* original 6262, guest PC 0x0c094dec */
if(!s->budget--) { s->failed_pc=0x0c094decu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c094dee;
P_0c094dee: /* original e3fe, guest PC 0x0c094dee */
if(!s->budget--) { s->failed_pc=0x0c094deeu; return 0; }
r[3]=0xfffffffeu;
goto P_0c094df0;
P_0c094df0: /* original 2239, guest PC 0x0c094df0 */
if(!s->budget--) { s->failed_pc=0x0c094df0u; return 0; }
r[2]&=r[3];
goto P_0c094df2;
P_0c094df2: /* original 2622, guest PC 0x0c094df2 */
if(!s->budget--) { s->failed_pc=0x0c094df2u; return 0; }
write(ram,r[6],r[2],4);
goto P_0c094df4;
P_0c094df4: /* original 6053, guest PC 0x0c094df4 */
if(!s->budget--) { s->failed_pc=0x0c094df4u; return 0; }
r[0]=r[5];
goto P_0c094df6;
P_0c094df6: /* original 8807, guest PC 0x0c094df6 */
if(!s->budget--) { s->failed_pc=0x0c094df6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c094df8;
P_0c094df8: /* original 8b08, guest PC 0x0c094df8 */
if(!s->budget--) { s->failed_pc=0x0c094df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094e0c; }
goto P_0c094dfa;
P_0c094dfa: /* original 904f, guest PC 0x0c094dfa */
if(!s->budget--) { s->failed_pc=0x0c094dfau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094e9cu,2);
goto P_0c094dfc;
P_0c094dfc: /* original 007c, guest PC 0x0c094dfc */
if(!s->budget--) { s->failed_pc=0x0c094dfcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+r[0],1);
goto P_0c094dfe;
P_0c094dfe: /* original 600c, guest PC 0x0c094dfe */
if(!s->budget--) { s->failed_pc=0x0c094dfeu; return 0; }
r[0]=r[0]&255u;
goto P_0c094e00;
P_0c094e00: /* original 8801, guest PC 0x0c094e00 */
if(!s->budget--) { s->failed_pc=0x0c094e00u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c094e02;
P_0c094e02: /* original 8b03, guest PC 0x0c094e02 */
if(!s->budget--) { s->failed_pc=0x0c094e02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c094e0c; }
goto P_0c094e04;
P_0c094e04: /* original 6262, guest PC 0x0c094e04 */
if(!s->budget--) { s->failed_pc=0x0c094e04u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c094e06;
P_0c094e06: /* original e3fe, guest PC 0x0c094e06 */
if(!s->budget--) { s->failed_pc=0x0c094e06u; return 0; }
r[3]=0xfffffffeu;
goto P_0c094e08;
P_0c094e08: /* original 2239, guest PC 0x0c094e08 */
if(!s->budget--) { s->failed_pc=0x0c094e08u; return 0; }
r[2]&=r[3];
goto P_0c094e0a;
P_0c094e0a: /* original 2622, guest PC 0x0c094e0a */
if(!s->budget--) { s->failed_pc=0x0c094e0au; return 0; }
write(ram,r[6],r[2],4);
goto P_0c094e0c;
P_0c094e0c: /* original d025, guest PC 0x0c094e0c */
if(!s->budget--) { s->failed_pc=0x0c094e0cu; return 0; }
r[0]=read(ram,0x0c094ea4u,4);
goto P_0c094e0e;
P_0c094e0e: /* original 6753, guest PC 0x0c094e0e */
if(!s->budget--) { s->failed_pc=0x0c094e0eu; return 0; }
r[7]=r[5];
goto P_0c094e10;
P_0c094e10: /* original 4708, guest PC 0x0c094e10 */
if(!s->budget--) { s->failed_pc=0x0c094e10u; return 0; }
r[7]<<=2;
goto P_0c094e12;
P_0c094e12: /* original 077e, guest PC 0x0c094e12 */
if(!s->budget--) { s->failed_pc=0x0c094e12u; return 0; }
r[7]=read(ram,r[7]+r[0],4);
goto P_0c094e14;
P_0c094e14: /* original 2778, guest PC 0x0c094e14 */
if(!s->budget--) { s->failed_pc=0x0c094e14u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c094e16;
P_0c094e16: /* original 8924, guest PC 0x0c094e16 */
if(!s->budget--) { s->failed_pc=0x0c094e16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c094e62; }
goto P_0c094e18;
P_0c094e18: /* original 6376, guest PC 0x0c094e18 */
if(!s->budget--) { s->failed_pc=0x0c094e18u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e1a;
P_0c094e1a: /* original 1634, guest PC 0x0c094e1a */
if(!s->budget--) { s->failed_pc=0x0c094e1au; return 0; }
write(ram,r[6]+16,r[3],4);
goto P_0c094e1c;
P_0c094e1c: /* original 6376, guest PC 0x0c094e1c */
if(!s->budget--) { s->failed_pc=0x0c094e1cu; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e1e;
P_0c094e1e: /* original 1c34, guest PC 0x0c094e1e */
if(!s->budget--) { s->failed_pc=0x0c094e1eu; return 0; }
write(ram,r[12]+16,r[3],4);
goto P_0c094e20;
P_0c094e20: /* original 6376, guest PC 0x0c094e20 */
if(!s->budget--) { s->failed_pc=0x0c094e20u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e22;
P_0c094e22: /* original 1d34, guest PC 0x0c094e22 */
if(!s->budget--) { s->failed_pc=0x0c094e22u; return 0; }
write(ram,r[13]+16,r[3],4);
goto P_0c094e24;
P_0c094e24: /* original 6376, guest PC 0x0c094e24 */
if(!s->budget--) { s->failed_pc=0x0c094e24u; return 0; }
tmp=read(ram,r[7],4);
r[7]+=4;
r[3]=tmp;
goto P_0c094e26;
P_0c094e26: /* original 1e34, guest PC 0x0c094e26 */
if(!s->budget--) { s->failed_pc=0x0c094e26u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c094e28;
P_0c094e28: /* original 6272, guest PC 0x0c094e28 */
if(!s->budget--) { s->failed_pc=0x0c094e28u; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c094e2a;
P_0c094e2a: /* original 6713, guest PC 0x0c094e2a */
if(!s->budget--) { s->failed_pc=0x0c094e2au; return 0; }
r[7]=r[1];
goto P_0c094e2c;
P_0c094e2c: /* original 1124, guest PC 0x0c094e2c */
if(!s->budget--) { s->failed_pc=0x0c094e2cu; return 0; }
write(ram,r[1]+16,r[2],4);
goto P_0c094e2e;
P_0c094e2e: /* original 1655, guest PC 0x0c094e2e */
if(!s->budget--) { s->failed_pc=0x0c094e2eu; return 0; }
write(ram,r[6]+20,r[5],4);
goto P_0c094e30;
P_0c094e30: /* original 1c55, guest PC 0x0c094e30 */
if(!s->budget--) { s->failed_pc=0x0c094e30u; return 0; }
write(ram,r[12]+20,r[5],4);
goto P_0c094e32;
P_0c094e32: /* original 1d55, guest PC 0x0c094e32 */
if(!s->budget--) { s->failed_pc=0x0c094e32u; return 0; }
write(ram,r[13]+20,r[5],4);
goto P_0c094e34;
P_0c094e34: /* original 1e55, guest PC 0x0c094e34 */
if(!s->budget--) { s->failed_pc=0x0c094e34u; return 0; }
write(ram,r[14]+20,r[5],4);
goto P_0c094e36;
P_0c094e36: /* original 1155, guest PC 0x0c094e36 */
if(!s->budget--) { s->failed_pc=0x0c094e36u; return 0; }
write(ram,r[1]+20,r[5],4);
goto P_0c094e38;
P_0c094e38: /* original 6563, guest PC 0x0c094e38 */
if(!s->budget--) { s->failed_pc=0x0c094e38u; return 0; }
r[5]=r[6];
goto P_0c094e3a;
P_0c094e3a: /* original d31b, guest PC 0x0c094e3a */
if(!s->budget--) { s->failed_pc=0x0c094e3au; return 0; }
r[3]=read(ram,0x0c094ea8u,4);
goto P_0c094e3c;
P_0c094e3c: /* original 1633, guest PC 0x0c094e3c */
if(!s->budget--) { s->failed_pc=0x0c094e3cu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c094e3e;
P_0c094e3e: /* original e610, guest PC 0x0c094e3e */
if(!s->budget--) { s->failed_pc=0x0c094e3eu; return 0; }
r[6]=0x00000010u;
goto P_0c094e40;
P_0c094e40: /* original 6352, guest PC 0x0c094e40 */
if(!s->budget--) { s->failed_pc=0x0c094e40u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c094e42;
P_0c094e42: /* original 76ff, guest PC 0x0c094e42 */
if(!s->budget--) { s->failed_pc=0x0c094e42u; return 0; }
r[6]+=0xffffffffu;
goto P_0c094e44;
P_0c094e44: /* original 2668, guest PC 0x0c094e44 */
if(!s->budget--) { s->failed_pc=0x0c094e44u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c094e46;
P_0c094e46: /* original 2c32, guest PC 0x0c094e46 */
if(!s->budget--) { s->failed_pc=0x0c094e46u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c094e48;
P_0c094e48: /* original 7c04, guest PC 0x0c094e48 */
if(!s->budget--) { s->failed_pc=0x0c094e48u; return 0; }
r[12]+=0x00000004u;
goto P_0c094e4a;
P_0c094e4a: /* original 6352, guest PC 0x0c094e4a */
if(!s->budget--) { s->failed_pc=0x0c094e4au; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c094e4c;
P_0c094e4c: /* original 2d32, guest PC 0x0c094e4c */
if(!s->budget--) { s->failed_pc=0x0c094e4cu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c094e4e;
P_0c094e4e: /* original 7d04, guest PC 0x0c094e4e */
if(!s->budget--) { s->failed_pc=0x0c094e4eu; return 0; }
r[13]+=0x00000004u;
goto P_0c094e50;
P_0c094e50: /* original 6352, guest PC 0x0c094e50 */
if(!s->budget--) { s->failed_pc=0x0c094e50u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c094e52;
P_0c094e52: /* original 2e32, guest PC 0x0c094e52 */
if(!s->budget--) { s->failed_pc=0x0c094e52u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c094e54;
P_0c094e54: /* original 7e04, guest PC 0x0c094e54 */
if(!s->budget--) { s->failed_pc=0x0c094e54u; return 0; }
r[14]+=0x00000004u;
goto P_0c094e56;
P_0c094e56: /* original 6356, guest PC 0x0c094e56 */
if(!s->budget--) { s->failed_pc=0x0c094e56u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[3]=tmp;
goto P_0c094e58;
P_0c094e58: /* original 2732, guest PC 0x0c094e58 */
if(!s->budget--) { s->failed_pc=0x0c094e58u; return 0; }
write(ram,r[7],r[3],4);
goto P_0c094e5a;
P_0c094e5a: /* original 8ff1, guest PC 0x0c094e5a */
if(!s->budget--) { s->failed_pc=0x0c094e5au; return 0; }
cond=r[17]&1u;
r[7]+=0x00000004u;
if(!cond) { goto P_0c094e40; }
goto P_0c094e5e;
P_0c094e5c: /* original 7704, guest PC 0x0c094e5c */
if(!s->budget--) { s->failed_pc=0x0c094e5cu; return 0; }
r[7]+=0x00000004u;
goto P_0c094e5e;
P_0c094e5e: /* original b005, guest PC 0x0c094e5e */
if(!s->budget--) { s->failed_pc=0x0c094e5eu; return 0; }
target=0x0c094e6cu; r[16]=0x0c094e62u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c094e62u) { target=s->pc; goto dispatch; }
goto P_0c094e62;
P_0c094e60: /* original 0009, guest PC 0x0c094e60 */
if(!s->budget--) { s->failed_pc=0x0c094e60u; return 0; }
goto P_0c094e62;
P_0c094e62: /* original 4f26, guest PC 0x0c094e62 */
if(!s->budget--) { s->failed_pc=0x0c094e62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c094e64;
P_0c094e64: /* original 6cf6, guest PC 0x0c094e64 */
if(!s->budget--) { s->failed_pc=0x0c094e64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c094e66;
P_0c094e66: /* original 6df6, guest PC 0x0c094e66 */
if(!s->budget--) { s->failed_pc=0x0c094e66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c094e68;
P_0c094e68: /* original 000b, guest PC 0x0c094e68 */
if(!s->budget--) { s->failed_pc=0x0c094e68u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c094e6a: /* original 6ef6, guest PC 0x0c094e6a */
if(!s->budget--) { s->failed_pc=0x0c094e6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c094e6c;
P_0c094e6c: /* original 2fe6, guest PC 0x0c094e6c */
if(!s->budget--) { s->failed_pc=0x0c094e6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e6e;
P_0c094e6e: /* original 2fd6, guest PC 0x0c094e6e */
if(!s->budget--) { s->failed_pc=0x0c094e6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e70;
P_0c094e70: /* original 6d43, guest PC 0x0c094e70 */
if(!s->budget--) { s->failed_pc=0x0c094e70u; return 0; }
r[13]=r[4];
goto P_0c094e72;
P_0c094e72: /* original 2fc6, guest PC 0x0c094e72 */
if(!s->budget--) { s->failed_pc=0x0c094e72u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e74;
P_0c094e74: /* original 2fb6, guest PC 0x0c094e74 */
if(!s->budget--) { s->failed_pc=0x0c094e74u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e76;
P_0c094e76: /* original 2fa6, guest PC 0x0c094e76 */
if(!s->budget--) { s->failed_pc=0x0c094e76u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e78;
P_0c094e78: /* original 2f96, guest PC 0x0c094e78 */
if(!s->budget--) { s->failed_pc=0x0c094e78u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c094e7a;
P_0c094e7a: /* original 950d, guest PC 0x0c094e7a */
if(!s->budget--) { s->failed_pc=0x0c094e7au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c094e98u,2);
goto P_0c094e7c;
P_0c094e7c: /* original 8444, guest PC 0x0c094e7c */
if(!s->budget--) { s->failed_pc=0x0c094e7cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c094e7e;
P_0c094e7e: /* original 3d5c, guest PC 0x0c094e7e */
if(!s->budget--) { s->failed_pc=0x0c094e7eu; return 0; }
r[13]+=r[5];
goto P_0c094e80;
P_0c094e80: /* original 6cd3, guest PC 0x0c094e80 */
if(!s->budget--) { s->failed_pc=0x0c094e80u; return 0; }
r[12]=r[13];
goto P_0c094e82;
P_0c094e82: /* original 3c5c, guest PC 0x0c094e82 */
if(!s->budget--) { s->failed_pc=0x0c094e82u; return 0; }
r[12]+=r[5];
goto P_0c094e84;
P_0c094e84: /* original 6ec3, guest PC 0x0c094e84 */
if(!s->budget--) { s->failed_pc=0x0c094e84u; return 0; }
r[14]=r[12];
goto P_0c094e86;
P_0c094e86: /* original 3e5c, guest PC 0x0c094e86 */
if(!s->budget--) { s->failed_pc=0x0c094e86u; return 0; }
r[14]+=r[5];
goto P_0c094e88;
P_0c094e88: /* original 6be3, guest PC 0x0c094e88 */
if(!s->budget--) { s->failed_pc=0x0c094e88u; return 0; }
r[11]=r[14];
goto P_0c094e8a;
P_0c094e8a: /* original 3b5c, guest PC 0x0c094e8a */
if(!s->budget--) { s->failed_pc=0x0c094e8au; return 0; }
r[11]+=r[5];
return vf3_matrix_family(0x0c094e8cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c094a36u,0x0c094a38u,0x0c094a3au,0x0c094a3cu,0x0c094a3eu,0x0c094a40u,0x0c094a42u,0x0c094a44u,0x0c094a46u,0x0c094a48u,0x0c094a4au,0x0c094a4cu,0x0c094a4eu,0x0c094a74u,0x0c094a76u,0x0c094a78u,
0x0c094a7au,0x0c094a7cu,0x0c094a7eu,0x0c094a80u,0x0c094a82u,0x0c094a84u,0x0c094a86u,0x0c094a88u,0x0c094a8au,0x0c094a8cu,0x0c094a8eu,0x0c094a90u,0x0c094a92u,0x0c094a94u,0x0c094a96u,0x0c094a98u,
0x0c094a9au,0x0c094a9cu,0x0c094a9eu,0x0c094aa0u,0x0c094aa2u,0x0c094aa4u,0x0c094aa6u,0x0c094aa8u,0x0c094aaau,0x0c094aacu,0x0c094aaeu,0x0c094ab0u,0x0c094ab2u,0x0c094ab4u,0x0c094ab6u,0x0c094ab8u,
0x0c094abau,0x0c094abcu,0x0c094abeu,0x0c094ac0u,0x0c094ac2u,0x0c094ac4u,0x0c094ac6u,0x0c094ac8u,0x0c094acau,0x0c094accu,0x0c094aceu,0x0c094ad0u,0x0c094ad2u,0x0c094ad4u,0x0c094ad6u,0x0c094ad8u,
0x0c094adau,0x0c094adcu,0x0c094adeu,0x0c094ae0u,0x0c094ae2u,0x0c094ae4u,0x0c094ae6u,0x0c094ae8u,0x0c094aeau,0x0c094aecu,0x0c094aeeu,0x0c094af0u,0x0c094af2u,0x0c094af4u,0x0c094af6u,0x0c094af8u,
0x0c094afau,0x0c094afcu,0x0c094afeu,0x0c094b00u,0x0c094b02u,0x0c094b04u,0x0c094b06u,0x0c094b08u,0x0c094b0au,0x0c094b0cu,0x0c094b0eu,0x0c094b10u,0x0c094b12u,0x0c094b14u,0x0c094b16u,0x0c094b18u,
0x0c094b1au,0x0c094b1cu,0x0c094b1eu,0x0c094b20u,0x0c094b22u,0x0c094b24u,0x0c094b26u,0x0c094b28u,0x0c094dc6u,0x0c094dc8u,0x0c094dcau,0x0c094dccu,0x0c094dceu,0x0c094dd0u,0x0c094dd2u,0x0c094dd4u,
0x0c094dd6u,0x0c094dd8u,0x0c094ddau,0x0c094ddcu,0x0c094ddeu,0x0c094de0u,0x0c094de2u,0x0c094de4u,0x0c094de6u,0x0c094de8u,0x0c094deau,0x0c094decu,0x0c094deeu,0x0c094df0u,0x0c094df2u,0x0c094df4u,
0x0c094df6u,0x0c094df8u,0x0c094dfau,0x0c094dfcu,0x0c094dfeu,0x0c094e00u,0x0c094e02u,0x0c094e04u,0x0c094e06u,0x0c094e08u,0x0c094e0au,0x0c094e0cu,0x0c094e0eu,0x0c094e10u,0x0c094e12u,0x0c094e14u,
0x0c094e16u,0x0c094e18u,0x0c094e1au,0x0c094e1cu,0x0c094e1eu,0x0c094e20u,0x0c094e22u,0x0c094e24u,0x0c094e26u,0x0c094e28u,0x0c094e2au,0x0c094e2cu,0x0c094e2eu,0x0c094e30u,0x0c094e32u,0x0c094e34u,
0x0c094e36u,0x0c094e38u,0x0c094e3au,0x0c094e3cu,0x0c094e3eu,0x0c094e40u,0x0c094e42u,0x0c094e44u,0x0c094e46u,0x0c094e48u,0x0c094e4au,0x0c094e4cu,0x0c094e4eu,0x0c094e50u,0x0c094e52u,0x0c094e54u,
0x0c094e56u,0x0c094e58u,0x0c094e5au,0x0c094e5cu,0x0c094e5eu,0x0c094e60u,0x0c094e62u,0x0c094e64u,0x0c094e66u,0x0c094e68u,0x0c094e6au,0x0c094e6cu,0x0c094e6eu,0x0c094e70u,0x0c094e72u,0x0c094e74u,
0x0c094e76u,0x0c094e78u,0x0c094e7au,0x0c094e7cu,0x0c094e7eu,0x0c094e80u,0x0c094e82u,0x0c094e84u,0x0c094e86u,0x0c094e88u,0x0c094e8au,
};
int vf3_motion_style_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
