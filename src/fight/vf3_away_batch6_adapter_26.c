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
int vf3_away_batch6_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c054a88u: goto P_0c054a88;
case 0x0c054a8au: goto P_0c054a8a;
case 0x0c054a8cu: goto P_0c054a8c;
case 0x0c054a8eu: goto P_0c054a8e;
case 0x0c054a90u: goto P_0c054a90;
case 0x0c054a92u: goto P_0c054a92;
case 0x0c054a94u: goto P_0c054a94;
case 0x0c054a96u: goto P_0c054a96;
case 0x0c054a98u: goto P_0c054a98;
case 0x0c054a9au: goto P_0c054a9a;
case 0x0c054a9cu: goto P_0c054a9c;
case 0x0c054a9eu: goto P_0c054a9e;
case 0x0c054aa0u: goto P_0c054aa0;
case 0x0c054aa2u: goto P_0c054aa2;
case 0x0c054aa4u: goto P_0c054aa4;
case 0x0c054aa6u: goto P_0c054aa6;
case 0x0c054aa8u: goto P_0c054aa8;
case 0x0c054aaau: goto P_0c054aaa;
case 0x0c054aacu: goto P_0c054aac;
case 0x0c054aaeu: goto P_0c054aae;
case 0x0c054ab0u: goto P_0c054ab0;
case 0x0c054ab2u: goto P_0c054ab2;
case 0x0c054ab4u: goto P_0c054ab4;
case 0x0c054ab6u: goto P_0c054ab6;
case 0x0c054ab8u: goto P_0c054ab8;
case 0x0c054abau: goto P_0c054aba;
case 0x0c054abcu: goto P_0c054abc;
case 0x0c054abeu: goto P_0c054abe;
case 0x0c054ac0u: goto P_0c054ac0;
case 0x0c054ac2u: goto P_0c054ac2;
case 0x0c054ac4u: goto P_0c054ac4;
case 0x0c054ac6u: goto P_0c054ac6;
case 0x0c054ac8u: goto P_0c054ac8;
case 0x0c054acau: goto P_0c054aca;
case 0x0c054accu: goto P_0c054acc;
case 0x0c054aceu: goto P_0c054ace;
case 0x0c054ad0u: goto P_0c054ad0;
case 0x0c054ad2u: goto P_0c054ad2;
case 0x0c054ad4u: goto P_0c054ad4;
case 0x0c054ad6u: goto P_0c054ad6;
case 0x0c054ad8u: goto P_0c054ad8;
case 0x0c054adau: goto P_0c054ada;
case 0x0c054adcu: goto P_0c054adc;
case 0x0c054adeu: goto P_0c054ade;
case 0x0c054ae0u: goto P_0c054ae0;
case 0x0c054ae2u: goto P_0c054ae2;
case 0x0c054ae4u: goto P_0c054ae4;
case 0x0c054ae6u: goto P_0c054ae6;
case 0x0c054ae8u: goto P_0c054ae8;
case 0x0c054aeau: goto P_0c054aea;
case 0x0c054aecu: goto P_0c054aec;
case 0x0c054aeeu: goto P_0c054aee;
case 0x0c054af0u: goto P_0c054af0;
case 0x0c054af2u: goto P_0c054af2;
case 0x0c054af4u: goto P_0c054af4;
case 0x0c054af6u: goto P_0c054af6;
case 0x0c054af8u: goto P_0c054af8;
case 0x0c054afau: goto P_0c054afa;
case 0x0c054afcu: goto P_0c054afc;
case 0x0c054afeu: goto P_0c054afe;
case 0x0c054b00u: goto P_0c054b00;
case 0x0c054b02u: goto P_0c054b02;
case 0x0c054b04u: goto P_0c054b04;
case 0x0c054b06u: goto P_0c054b06;
case 0x0c054b08u: goto P_0c054b08;
case 0x0c054b0au: goto P_0c054b0a;
case 0x0c054b0cu: goto P_0c054b0c;
case 0x0c054b0eu: goto P_0c054b0e;
case 0x0c054b10u: goto P_0c054b10;
case 0x0c054b12u: goto P_0c054b12;
case 0x0c054b14u: goto P_0c054b14;
case 0x0c054b16u: goto P_0c054b16;
case 0x0c054b18u: goto P_0c054b18;
case 0x0c054b1au: goto P_0c054b1a;
case 0x0c054b1cu: goto P_0c054b1c;
case 0x0c054b1eu: goto P_0c054b1e;
case 0x0c054b20u: goto P_0c054b20;
case 0x0c054b22u: goto P_0c054b22;
case 0x0c054b24u: goto P_0c054b24;
case 0x0c054b26u: goto P_0c054b26;
case 0x0c054b28u: goto P_0c054b28;
case 0x0c054b2au: goto P_0c054b2a;
case 0x0c054b2cu: goto P_0c054b2c;
case 0x0c054b2eu: goto P_0c054b2e;
case 0x0c054b30u: goto P_0c054b30;
case 0x0c054b32u: goto P_0c054b32;
case 0x0c054b34u: goto P_0c054b34;
case 0x0c054b36u: goto P_0c054b36;
case 0x0c054b38u: goto P_0c054b38;
case 0x0c054b3au: goto P_0c054b3a;
case 0x0c054b3cu: goto P_0c054b3c;
case 0x0c054b3eu: goto P_0c054b3e;
case 0x0c054b40u: goto P_0c054b40;
case 0x0c054b42u: goto P_0c054b42;
case 0x0c054b44u: goto P_0c054b44;
case 0x0c054b46u: goto P_0c054b46;
case 0x0c054b48u: goto P_0c054b48;
case 0x0c054b4au: goto P_0c054b4a;
case 0x0c054b4cu: goto P_0c054b4c;
case 0x0c054b4eu: goto P_0c054b4e;
case 0x0c054b50u: goto P_0c054b50;
case 0x0c054b52u: goto P_0c054b52;
case 0x0c054b54u: goto P_0c054b54;
case 0x0c054b56u: goto P_0c054b56;
case 0x0c054b58u: goto P_0c054b58;
case 0x0c054b5au: goto P_0c054b5a;
case 0x0c054b5cu: goto P_0c054b5c;
case 0x0c054b5eu: goto P_0c054b5e;
case 0x0c054b60u: goto P_0c054b60;
case 0x0c054b62u: goto P_0c054b62;
case 0x0c054b64u: goto P_0c054b64;
case 0x0c054b66u: goto P_0c054b66;
case 0x0c054b68u: goto P_0c054b68;
case 0x0c054b6au: goto P_0c054b6a;
case 0x0c054b6cu: goto P_0c054b6c;
case 0x0c054b6eu: goto P_0c054b6e;
case 0x0c054b70u: goto P_0c054b70;
case 0x0c054b7cu: goto P_0c054b7c;
case 0x0c054b7eu: goto P_0c054b7e;
case 0x0c054b80u: goto P_0c054b80;
case 0x0c054b82u: goto P_0c054b82;
case 0x0c054b84u: goto P_0c054b84;
case 0x0c054b86u: goto P_0c054b86;
case 0x0c054b88u: goto P_0c054b88;
case 0x0c054b8au: goto P_0c054b8a;
case 0x0c054b8cu: goto P_0c054b8c;
case 0x0c054b8eu: goto P_0c054b8e;
case 0x0c054b90u: goto P_0c054b90;
case 0x0c054b92u: goto P_0c054b92;
case 0x0c054b94u: goto P_0c054b94;
case 0x0c054b96u: goto P_0c054b96;
case 0x0c054b98u: goto P_0c054b98;
case 0x0c054b9au: goto P_0c054b9a;
case 0x0c054b9cu: goto P_0c054b9c;
case 0x0c054b9eu: goto P_0c054b9e;
case 0x0c054ba0u: goto P_0c054ba0;
case 0x0c054ba2u: goto P_0c054ba2;
case 0x0c054ba4u: goto P_0c054ba4;
case 0x0c054ba6u: goto P_0c054ba6;
case 0x0c054ba8u: goto P_0c054ba8;
case 0x0c054baau: goto P_0c054baa;
case 0x0c054bacu: goto P_0c054bac;
case 0x0c054baeu: goto P_0c054bae;
case 0x0c054bb0u: goto P_0c054bb0;
case 0x0c054bb2u: goto P_0c054bb2;
case 0x0c054bb4u: goto P_0c054bb4;
case 0x0c054bb6u: goto P_0c054bb6;
case 0x0c054bb8u: goto P_0c054bb8;
case 0x0c054bbau: goto P_0c054bba;
case 0x0c054bbcu: goto P_0c054bbc;
case 0x0c054bbeu: goto P_0c054bbe;
case 0x0c054bc0u: goto P_0c054bc0;
case 0x0c054bc2u: goto P_0c054bc2;
case 0x0c054bc4u: goto P_0c054bc4;
case 0x0c054bc6u: goto P_0c054bc6;
case 0x0c054bc8u: goto P_0c054bc8;
case 0x0c054bcau: goto P_0c054bca;
case 0x0c054bccu: goto P_0c054bcc;
case 0x0c054bceu: goto P_0c054bce;
case 0x0c054bd0u: goto P_0c054bd0;
case 0x0c054bd2u: goto P_0c054bd2;
case 0x0c054bd4u: goto P_0c054bd4;
case 0x0c054bd6u: goto P_0c054bd6;
case 0x0c054bd8u: goto P_0c054bd8;
case 0x0c054bdau: goto P_0c054bda;
case 0x0c054bdcu: goto P_0c054bdc;
case 0x0c054bdeu: goto P_0c054bde;
case 0x0c054be0u: goto P_0c054be0;
case 0x0c054be2u: goto P_0c054be2;
case 0x0c054be4u: goto P_0c054be4;
case 0x0c054be6u: goto P_0c054be6;
case 0x0c054be8u: goto P_0c054be8;
case 0x0c054beau: goto P_0c054bea;
case 0x0c054becu: goto P_0c054bec;
case 0x0c054beeu: goto P_0c054bee;
case 0x0c054bf0u: goto P_0c054bf0;
case 0x0c054bf2u: goto P_0c054bf2;
case 0x0c054bf4u: goto P_0c054bf4;
case 0x0c054bf6u: goto P_0c054bf6;
case 0x0c054f94u: goto P_0c054f94;
case 0x0c054f96u: goto P_0c054f96;
case 0x0c054f98u: goto P_0c054f98;
case 0x0c054f9au: goto P_0c054f9a;
case 0x0c054f9cu: goto P_0c054f9c;
case 0x0c054f9eu: goto P_0c054f9e;
case 0x0c054fa0u: goto P_0c054fa0;
case 0x0c054fa2u: goto P_0c054fa2;
case 0x0c054fa4u: goto P_0c054fa4;
case 0x0c054fa6u: goto P_0c054fa6;
case 0x0c054fa8u: goto P_0c054fa8;
case 0x0c054faau: goto P_0c054faa;
case 0x0c054facu: goto P_0c054fac;
case 0x0c054faeu: goto P_0c054fae;
case 0x0c054fb0u: goto P_0c054fb0;
case 0x0c054fb2u: goto P_0c054fb2;
case 0x0c054fb4u: goto P_0c054fb4;
case 0x0c054fb6u: goto P_0c054fb6;
case 0x0c054fb8u: goto P_0c054fb8;
case 0x0c054fbau: goto P_0c054fba;
case 0x0c054fbcu: goto P_0c054fbc;
case 0x0c054fbeu: goto P_0c054fbe;
case 0x0c054fc0u: goto P_0c054fc0;
case 0x0c054fc2u: goto P_0c054fc2;
case 0x0c054fc4u: goto P_0c054fc4;
case 0x0c054fc6u: goto P_0c054fc6;
case 0x0c054fc8u: goto P_0c054fc8;
case 0x0c054fcau: goto P_0c054fca;
case 0x0c054fccu: goto P_0c054fcc;
case 0x0c054fceu: goto P_0c054fce;
case 0x0c054fd0u: goto P_0c054fd0;
case 0x0c054fd2u: goto P_0c054fd2;
case 0x0c054fd4u: goto P_0c054fd4;
case 0x0c054fd6u: goto P_0c054fd6;
case 0x0c054fd8u: goto P_0c054fd8;
case 0x0c054fdau: goto P_0c054fda;
case 0x0c054fdcu: goto P_0c054fdc;
case 0x0c054fdeu: goto P_0c054fde;
case 0x0c054fe0u: goto P_0c054fe0;
case 0x0c054fe2u: goto P_0c054fe2;
case 0x0c054fe4u: goto P_0c054fe4;
case 0x0c054fe6u: goto P_0c054fe6;
case 0x0c054fe8u: goto P_0c054fe8;
case 0x0c054feau: goto P_0c054fea;
case 0x0c054fecu: goto P_0c054fec;
case 0x0c054feeu: goto P_0c054fee;
case 0x0c054ff0u: goto P_0c054ff0;
case 0x0c054ff2u: goto P_0c054ff2;
case 0x0c054ff4u: goto P_0c054ff4;
case 0x0c054ff6u: goto P_0c054ff6;
case 0x0c054ff8u: goto P_0c054ff8;
case 0x0c054ffau: goto P_0c054ffa;
case 0x0c054ffcu: goto P_0c054ffc;
case 0x0c054ffeu: goto P_0c054ffe;
case 0x0c055000u: goto P_0c055000;
case 0x0c055002u: goto P_0c055002;
case 0x0c055004u: goto P_0c055004;
case 0x0c055006u: goto P_0c055006;
case 0x0c055008u: goto P_0c055008;
case 0x0c05500au: goto P_0c05500a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c054a88: /* original 2fe6, guest PC 0x0c054a88 */
if(!s->budget--) { s->failed_pc=0x0c054a88u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054a8a;
P_0c054a8a: /* original e608, guest PC 0x0c054a8a */
if(!s->budget--) { s->failed_pc=0x0c054a8au; return 0; }
r[6]=0x00000008u;
goto P_0c054a8c;
P_0c054a8c: /* original d339, guest PC 0x0c054a8c */
if(!s->budget--) { s->failed_pc=0x0c054a8cu; return 0; }
r[3]=read(ram,0x0c054b74u,4);
goto P_0c054a8e;
P_0c054a8e: /* original e700, guest PC 0x0c054a8e */
if(!s->budget--) { s->failed_pc=0x0c054a8eu; return 0; }
r[7]=0x00000000u;
goto P_0c054a90;
P_0c054a90: /* original 4f22, guest PC 0x0c054a90 */
if(!s->budget--) { s->failed_pc=0x0c054a90u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054a92;
P_0c054a92: /* original 6153, guest PC 0x0c054a92 */
if(!s->budget--) { s->failed_pc=0x0c054a92u; return 0; }
r[1]=r[5];
goto P_0c054a94;
P_0c054a94: /* original 7ff0, guest PC 0x0c054a94 */
if(!s->budget--) { s->failed_pc=0x0c054a94u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c054a96;
P_0c054a96: /* original 430b, guest PC 0x0c054a96 */
if(!s->budget--) { s->failed_pc=0x0c054a96u; return 0; }
target=r[3];
r[16]=code_base|0x0c054a9au;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054a9au) { target=s->pc; goto dispatch; }
goto P_0c054a9a;
P_0c054a98: /* original 6063, guest PC 0x0c054a98 */
if(!s->budget--) { s->failed_pc=0x0c054a98u; return 0; }
r[0]=r[6];
goto P_0c054a9a;
P_0c054a9a: /* original 6e03, guest PC 0x0c054a9a */
if(!s->budget--) { s->failed_pc=0x0c054a9au; return 0; }
r[14]=r[0];
goto P_0c054a9c;
P_0c054a9c: /* original d236, guest PC 0x0c054a9c */
if(!s->budget--) { s->failed_pc=0x0c054a9cu; return 0; }
r[2]=read(ram,0x0c054b78u,4);
goto P_0c054a9e;
P_0c054a9e: /* original 6153, guest PC 0x0c054a9e */
if(!s->budget--) { s->failed_pc=0x0c054a9eu; return 0; }
r[1]=r[5];
goto P_0c054aa0;
P_0c054aa0: /* original 3e4c, guest PC 0x0c054aa0 */
if(!s->budget--) { s->failed_pc=0x0c054aa0u; return 0; }
r[14]+=r[4];
goto P_0c054aa2;
P_0c054aa2: /* original 420b, guest PC 0x0c054aa2 */
if(!s->budget--) { s->failed_pc=0x0c054aa2u; return 0; }
target=r[2];
r[16]=code_base|0x0c054aa6u;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054aa6u) { target=s->pc; goto dispatch; }
goto P_0c054aa6;
P_0c054aa4: /* original 6063, guest PC 0x0c054aa4 */
if(!s->budget--) { s->failed_pc=0x0c054aa4u; return 0; }
r[0]=r[6];
goto P_0c054aa6;
P_0c054aa6: /* original 600b, guest PC 0x0c054aa6 */
if(!s->budget--) { s->failed_pc=0x0c054aa6u; return 0; }
r[0]=0u-r[0];
goto P_0c054aa8;
P_0c054aa8: /* original 9363, guest PC 0x0c054aa8 */
if(!s->budget--) { s->failed_pc=0x0c054aa8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054b72u,2);
goto P_0c054aaa;
P_0c054aaa: /* original 0009, guest PC 0x0c054aaa */
if(!s->budget--) { s->failed_pc=0x0c054aaau; return 0; }
goto P_0c054aac;
P_0c054aac: /* original 430c, guest PC 0x0c054aac */
if(!s->budget--) { s->failed_pc=0x0c054aacu; return 0; }
r[3]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[3]>>((-r[0])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[0]&31u);
goto P_0c054aae;
P_0c054aae: /* original 6153, guest PC 0x0c054aae */
if(!s->budget--) { s->failed_pc=0x0c054aaeu; return 0; }
r[1]=r[5];
goto P_0c054ab0;
P_0c054ab0: /* original 2f30, guest PC 0x0c054ab0 */
if(!s->budget--) { s->failed_pc=0x0c054ab0u; return 0; }
write(ram,r[15],r[3],1);
goto P_0c054ab2;
P_0c054ab2: /* original 71ff, guest PC 0x0c054ab2 */
if(!s->budget--) { s->failed_pc=0x0c054ab2u; return 0; }
r[1]+=0xffffffffu;
goto P_0c054ab4;
P_0c054ab4: /* original 633c, guest PC 0x0c054ab4 */
if(!s->budget--) { s->failed_pc=0x0c054ab4u; return 0; }
r[3]=r[3]&255u;
goto P_0c054ab6;
P_0c054ab6: /* original 1f33, guest PC 0x0c054ab6 */
if(!s->budget--) { s->failed_pc=0x0c054ab6u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c054ab8;
P_0c054ab8: /* original 4321, guest PC 0x0c054ab8 */
if(!s->budget--) { s->failed_pc=0x0c054ab8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]&1)!=0);
r[3]=(uint32_t)((int32_t)r[3]>>1);
goto P_0c054aba;
P_0c054aba: /* original 2f30, guest PC 0x0c054aba */
if(!s->budget--) { s->failed_pc=0x0c054abau; return 0; }
write(ram,r[15],r[3],1);
goto P_0c054abc;
P_0c054abc: /* original 60f0, guest PC 0x0c054abc */
if(!s->budget--) { s->failed_pc=0x0c054abcu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[0]=tmp;
goto P_0c054abe;
P_0c054abe: /* original 600c, guest PC 0x0c054abe */
if(!s->budget--) { s->failed_pc=0x0c054abeu; return 0; }
r[0]=r[0]&255u;
goto P_0c054ac0;
P_0c054ac0: /* original 1f02, guest PC 0x0c054ac0 */
if(!s->budget--) { s->failed_pc=0x0c054ac0u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c054ac2;
P_0c054ac2: /* original 4021, guest PC 0x0c054ac2 */
if(!s->budget--) { s->failed_pc=0x0c054ac2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]=(uint32_t)((int32_t)r[0]>>1);
goto P_0c054ac4;
P_0c054ac4: /* original d32b, guest PC 0x0c054ac4 */
if(!s->budget--) { s->failed_pc=0x0c054ac4u; return 0; }
r[3]=read(ram,0x0c054b74u,4);
goto P_0c054ac6;
P_0c054ac6: /* original 80f4, guest PC 0x0c054ac6 */
if(!s->budget--) { s->failed_pc=0x0c054ac6u; return 0; }
write(ram,r[15]+4,r[0],1);
goto P_0c054ac8;
P_0c054ac8: /* original 2f12, guest PC 0x0c054ac8 */
if(!s->budget--) { s->failed_pc=0x0c054ac8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c054aca;
P_0c054aca: /* original 430b, guest PC 0x0c054aca */
if(!s->budget--) { s->failed_pc=0x0c054acau; return 0; }
target=r[3];
r[16]=code_base|0x0c054aceu;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054aceu) { target=s->pc; goto dispatch; }
goto P_0c054ace;
P_0c054acc: /* original 6063, guest PC 0x0c054acc */
if(!s->budget--) { s->failed_pc=0x0c054accu; return 0; }
r[0]=r[6];
goto P_0c054ace;
P_0c054ace: /* original 6503, guest PC 0x0c054ace */
if(!s->budget--) { s->failed_pc=0x0c054aceu; return 0; }
r[5]=r[0];
goto P_0c054ad0;
P_0c054ad0: /* original 61f2, guest PC 0x0c054ad0 */
if(!s->budget--) { s->failed_pc=0x0c054ad0u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c054ad2;
P_0c054ad2: /* original 354c, guest PC 0x0c054ad2 */
if(!s->budget--) { s->failed_pc=0x0c054ad2u; return 0; }
r[5]+=r[4];
goto P_0c054ad4;
P_0c054ad4: /* original d228, guest PC 0x0c054ad4 */
if(!s->budget--) { s->failed_pc=0x0c054ad4u; return 0; }
r[2]=read(ram,0x0c054b78u,4);
goto P_0c054ad6;
P_0c054ad6: /* original 420b, guest PC 0x0c054ad6 */
if(!s->budget--) { s->failed_pc=0x0c054ad6u; return 0; }
target=r[2];
r[16]=code_base|0x0c054adau;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054adau) { target=s->pc; goto dispatch; }
goto P_0c054ada;
P_0c054ad8: /* original 6063, guest PC 0x0c054ad8 */
if(!s->budget--) { s->failed_pc=0x0c054ad8u; return 0; }
r[0]=r[6];
goto P_0c054ada;
P_0c054ada: /* original 600b, guest PC 0x0c054ada */
if(!s->budget--) { s->failed_pc=0x0c054adau; return 0; }
r[0]=0u-r[0];
goto P_0c054adc;
P_0c054adc: /* original 7678, guest PC 0x0c054adc */
if(!s->budget--) { s->failed_pc=0x0c054adcu; return 0; }
r[6]+=0x00000078u;
goto P_0c054ade;
P_0c054ade: /* original 0009, guest PC 0x0c054ade */
if(!s->budget--) { s->failed_pc=0x0c054adeu; return 0; }
goto P_0c054ae0;
P_0c054ae0: /* original 460c, guest PC 0x0c054ae0 */
if(!s->budget--) { s->failed_pc=0x0c054ae0u; return 0; }
r[6]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[6]>>((-r[0])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[0]&31u);
goto P_0c054ae2;
P_0c054ae2: /* original 63e0, guest PC 0x0c054ae2 */
if(!s->budget--) { s->failed_pc=0x0c054ae2u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[3]=tmp;
goto P_0c054ae4;
P_0c054ae4: /* original 52f3, guest PC 0x0c054ae4 */
if(!s->budget--) { s->failed_pc=0x0c054ae4u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c054ae6;
P_0c054ae6: /* original 633c, guest PC 0x0c054ae6 */
if(!s->budget--) { s->failed_pc=0x0c054ae6u; return 0; }
r[3]=r[3]&255u;
goto P_0c054ae8;
P_0c054ae8: /* original 2328, guest PC 0x0c054ae8 */
if(!s->budget--) { s->failed_pc=0x0c054ae8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c054aea;
P_0c054aea: /* original 8d16, guest PC 0x0c054aea */
if(!s->budget--) { s->failed_pc=0x0c054aeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054b1a; }
goto P_0c054aee;
P_0c054aec: /* original 0009, guest PC 0x0c054aec */
if(!s->budget--) { s->failed_pc=0x0c054aecu; return 0; }
goto P_0c054aee;
P_0c054aee: /* original 61e0, guest PC 0x0c054aee */
if(!s->budget--) { s->failed_pc=0x0c054aeeu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[1]=tmp;
goto P_0c054af0;
P_0c054af0: /* original 611c, guest PC 0x0c054af0 */
if(!s->budget--) { s->failed_pc=0x0c054af0u; return 0; }
r[1]=r[1]&255u;
goto P_0c054af2;
P_0c054af2: /* original 2f12, guest PC 0x0c054af2 */
if(!s->budget--) { s->failed_pc=0x0c054af2u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c054af4;
P_0c054af4: /* original 53f2, guest PC 0x0c054af4 */
if(!s->budget--) { s->failed_pc=0x0c054af4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c054af6;
P_0c054af6: /* original 2138, guest PC 0x0c054af6 */
if(!s->budget--) { s->failed_pc=0x0c054af6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c054af8;
P_0c054af8: /* original 8f06, guest PC 0x0c054af8 */
if(!s->budget--) { s->failed_pc=0x0c054af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054b08; }
goto P_0c054afc;
P_0c054afa: /* original 0009, guest PC 0x0c054afa */
if(!s->budget--) { s->failed_pc=0x0c054afau; return 0; }
goto P_0c054afc;
P_0c054afc: /* original 84f4, guest PC 0x0c054afc */
if(!s->budget--) { s->failed_pc=0x0c054afcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+4,1);
goto P_0c054afe;
P_0c054afe: /* original 600c, guest PC 0x0c054afe */
if(!s->budget--) { s->failed_pc=0x0c054afeu; return 0; }
r[0]=r[0]&255u;
goto P_0c054b00;
P_0c054b00: /* original 61f2, guest PC 0x0c054b00 */
if(!s->budget--) { s->failed_pc=0x0c054b00u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c054b02;
P_0c054b02: /* original 2018, guest PC 0x0c054b02 */
if(!s->budget--) { s->failed_pc=0x0c054b02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c054b04;
P_0c054b04: /* original 8d02, guest PC 0x0c054b04 */
if(!s->budget--) { s->failed_pc=0x0c054b04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054b0c; }
goto P_0c054b08;
P_0c054b06: /* original 0009, guest PC 0x0c054b06 */
if(!s->budget--) { s->failed_pc=0x0c054b06u; return 0; }
goto P_0c054b08;
P_0c054b08: /* original a007, guest PC 0x0c054b08 */
if(!s->budget--) { s->failed_pc=0x0c054b08u; return 0; }
r[7]=0x00000001u;
goto P_0c054b1a;
P_0c054b0a: /* original e701, guest PC 0x0c054b0a */
if(!s->budget--) { s->failed_pc=0x0c054b0au; return 0; }
r[7]=0x00000001u;
goto P_0c054b0c;
P_0c054b0c: /* original 6250, guest PC 0x0c054b0c */
if(!s->budget--) { s->failed_pc=0x0c054b0cu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c054b0e;
P_0c054b0e: /* original 636c, guest PC 0x0c054b0e */
if(!s->budget--) { s->failed_pc=0x0c054b0eu; return 0; }
r[3]=r[6]&255u;
goto P_0c054b10;
P_0c054b10: /* original 622c, guest PC 0x0c054b10 */
if(!s->budget--) { s->failed_pc=0x0c054b10u; return 0; }
r[2]=r[2]&255u;
goto P_0c054b12;
P_0c054b12: /* original 2238, guest PC 0x0c054b12 */
if(!s->budget--) { s->failed_pc=0x0c054b12u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c054b14;
P_0c054b14: /* original 8d01, guest PC 0x0c054b14 */
if(!s->budget--) { s->failed_pc=0x0c054b14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054b1a; }
goto P_0c054b18;
P_0c054b16: /* original 0009, guest PC 0x0c054b16 */
if(!s->budget--) { s->failed_pc=0x0c054b16u; return 0; }
goto P_0c054b18;
P_0c054b18: /* original e701, guest PC 0x0c054b18 */
if(!s->budget--) { s->failed_pc=0x0c054b18u; return 0; }
r[7]=0x00000001u;
goto P_0c054b1a;
P_0c054b1a: /* original 6073, guest PC 0x0c054b1a */
if(!s->budget--) { s->failed_pc=0x0c054b1au; return 0; }
r[0]=r[7];
goto P_0c054b1c;
P_0c054b1c: /* original 0009, guest PC 0x0c054b1c */
if(!s->budget--) { s->failed_pc=0x0c054b1cu; return 0; }
goto P_0c054b1e;
P_0c054b1e: /* original 8801, guest PC 0x0c054b1e */
if(!s->budget--) { s->failed_pc=0x0c054b1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c054b20;
P_0c054b20: /* original 8f22, guest PC 0x0c054b20 */
if(!s->budget--) { s->failed_pc=0x0c054b20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054b68; }
goto P_0c054b24;
P_0c054b22: /* original 0009, guest PC 0x0c054b22 */
if(!s->budget--) { s->failed_pc=0x0c054b22u; return 0; }
goto P_0c054b24;
P_0c054b24: /* original a00b, guest PC 0x0c054b24 */
if(!s->budget--) { s->failed_pc=0x0c054b24u; return 0; }
goto P_0c054b3e;
P_0c054b26: /* original 0009, guest PC 0x0c054b26 */
if(!s->budget--) { s->failed_pc=0x0c054b26u; return 0; }
goto P_0c054b28;
P_0c054b28: /* original 6350, guest PC 0x0c054b28 */
if(!s->budget--) { s->failed_pc=0x0c054b28u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c054b2a;
P_0c054b2a: /* original 6267, guest PC 0x0c054b2a */
if(!s->budget--) { s->failed_pc=0x0c054b2au; return 0; }
r[2]=~r[6];
goto P_0c054b2c;
P_0c054b2c: /* original 2329, guest PC 0x0c054b2c */
if(!s->budget--) { s->failed_pc=0x0c054b2cu; return 0; }
r[3]&=r[2];
goto P_0c054b2e;
P_0c054b2e: /* original 4600, guest PC 0x0c054b2e */
if(!s->budget--) { s->failed_pc=0x0c054b2eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]>>31)!=0);
r[6]<<=1;
goto P_0c054b30;
P_0c054b30: /* original 2530, guest PC 0x0c054b30 */
if(!s->budget--) { s->failed_pc=0x0c054b30u; return 0; }
write(ram,r[5],r[3],1);
goto P_0c054b32;
P_0c054b32: /* original 626c, guest PC 0x0c054b32 */
if(!s->budget--) { s->failed_pc=0x0c054b32u; return 0; }
r[2]=r[6]&255u;
goto P_0c054b34;
P_0c054b34: /* original 2228, guest PC 0x0c054b34 */
if(!s->budget--) { s->failed_pc=0x0c054b34u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054b36;
P_0c054b36: /* original 8f02, guest PC 0x0c054b36 */
if(!s->budget--) { s->failed_pc=0x0c054b36u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054b3e; }
goto P_0c054b3a;
P_0c054b38: /* original 0009, guest PC 0x0c054b38 */
if(!s->budget--) { s->failed_pc=0x0c054b38u; return 0; }
goto P_0c054b3a;
P_0c054b3a: /* original 75ff, guest PC 0x0c054b3a */
if(!s->budget--) { s->failed_pc=0x0c054b3au; return 0; }
r[5]+=0xffffffffu;
goto P_0c054b3c;
P_0c054b3c: /* original e601, guest PC 0x0c054b3c */
if(!s->budget--) { s->failed_pc=0x0c054b3cu; return 0; }
r[6]=0x00000001u;
goto P_0c054b3e;
P_0c054b3e: /* original 636c, guest PC 0x0c054b3e */
if(!s->budget--) { s->failed_pc=0x0c054b3eu; return 0; }
r[3]=r[6]&255u;
goto P_0c054b40;
P_0c054b40: /* original 6250, guest PC 0x0c054b40 */
if(!s->budget--) { s->failed_pc=0x0c054b40u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[2]=tmp;
goto P_0c054b42;
P_0c054b42: /* original 622c, guest PC 0x0c054b42 */
if(!s->budget--) { s->failed_pc=0x0c054b42u; return 0; }
r[2]=r[2]&255u;
goto P_0c054b44;
P_0c054b44: /* original 2238, guest PC 0x0c054b44 */
if(!s->budget--) { s->failed_pc=0x0c054b44u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c054b46;
P_0c054b46: /* original 8d03, guest PC 0x0c054b46 */
if(!s->budget--) { s->failed_pc=0x0c054b46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054b50; }
goto P_0c054b4a;
P_0c054b48: /* original 0009, guest PC 0x0c054b48 */
if(!s->budget--) { s->failed_pc=0x0c054b48u; return 0; }
goto P_0c054b4a;
P_0c054b4a: /* original 3542, guest PC 0x0c054b4a */
if(!s->budget--) { s->failed_pc=0x0c054b4au; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[4])!=0);
goto P_0c054b4c;
P_0c054b4c: /* original 8dec, guest PC 0x0c054b4c */
if(!s->budget--) { s->failed_pc=0x0c054b4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054b28; }
goto P_0c054b50;
P_0c054b4e: /* original 0009, guest PC 0x0c054b4e */
if(!s->budget--) { s->failed_pc=0x0c054b4eu; return 0; }
goto P_0c054b50;
P_0c054b50: /* original 3542, guest PC 0x0c054b50 */
if(!s->budget--) { s->failed_pc=0x0c054b50u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[4])!=0);
goto P_0c054b52;
P_0c054b52: /* original 8f04, guest PC 0x0c054b52 */
if(!s->budget--) { s->failed_pc=0x0c054b52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054b5e; }
goto P_0c054b56;
P_0c054b54: /* original 0009, guest PC 0x0c054b54 */
if(!s->budget--) { s->failed_pc=0x0c054b54u; return 0; }
goto P_0c054b56;
P_0c054b56: /* original 6350, guest PC 0x0c054b56 */
if(!s->budget--) { s->failed_pc=0x0c054b56u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[3]=tmp;
goto P_0c054b58;
P_0c054b58: /* original 236b, guest PC 0x0c054b58 */
if(!s->budget--) { s->failed_pc=0x0c054b58u; return 0; }
r[3]|=r[6];
goto P_0c054b5a;
P_0c054b5a: /* original a005, guest PC 0x0c054b5a */
if(!s->budget--) { s->failed_pc=0x0c054b5au; return 0; }
write(ram,r[5],r[3],1);
goto P_0c054b68;
P_0c054b5c: /* original 2530, guest PC 0x0c054b5c */
if(!s->budget--) { s->failed_pc=0x0c054b5cu; return 0; }
write(ram,r[5],r[3],1);
goto P_0c054b5e;
P_0c054b5e: /* original e001, guest PC 0x0c054b5e */
if(!s->budget--) { s->failed_pc=0x0c054b5eu; return 0; }
r[0]=0x00000001u;
goto P_0c054b60;
P_0c054b60: /* original 7f10, guest PC 0x0c054b60 */
if(!s->budget--) { s->failed_pc=0x0c054b60u; return 0; }
r[15]+=0x00000010u;
goto P_0c054b62;
P_0c054b62: /* original 4f26, guest PC 0x0c054b62 */
if(!s->budget--) { s->failed_pc=0x0c054b62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054b64;
P_0c054b64: /* original 000b, guest PC 0x0c054b64 */
if(!s->budget--) { s->failed_pc=0x0c054b64u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054b66: /* original 6ef6, guest PC 0x0c054b66 */
if(!s->budget--) { s->failed_pc=0x0c054b66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c054b68;
P_0c054b68: /* original e000, guest PC 0x0c054b68 */
if(!s->budget--) { s->failed_pc=0x0c054b68u; return 0; }
r[0]=0x00000000u;
goto P_0c054b6a;
P_0c054b6a: /* original 7f10, guest PC 0x0c054b6a */
if(!s->budget--) { s->failed_pc=0x0c054b6au; return 0; }
r[15]+=0x00000010u;
goto P_0c054b6c;
P_0c054b6c: /* original 4f26, guest PC 0x0c054b6c */
if(!s->budget--) { s->failed_pc=0x0c054b6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054b6e;
P_0c054b6e: /* original 000b, guest PC 0x0c054b6e */
if(!s->budget--) { s->failed_pc=0x0c054b6eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054b70: /* original 6ef6, guest PC 0x0c054b70 */
if(!s->budget--) { s->failed_pc=0x0c054b70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054b72u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054b72u; return 0; } return 1;
P_0c054b7c: /* original 2fe6, guest PC 0x0c054b7c */
if(!s->budget--) { s->failed_pc=0x0c054b7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054b7e;
P_0c054b7e: /* original e008, guest PC 0x0c054b7e */
if(!s->budget--) { s->failed_pc=0x0c054b7eu; return 0; }
r[0]=0x00000008u;
goto P_0c054b80;
P_0c054b80: /* original d31e, guest PC 0x0c054b80 */
if(!s->budget--) { s->failed_pc=0x0c054b80u; return 0; }
r[3]=read(ram,0x0c054bfcu,4);
goto P_0c054b82;
P_0c054b82: /* original 2fd6, guest PC 0x0c054b82 */
if(!s->budget--) { s->failed_pc=0x0c054b82u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054b84;
P_0c054b84: /* original 4f22, guest PC 0x0c054b84 */
if(!s->budget--) { s->failed_pc=0x0c054b84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c054b86;
P_0c054b86: /* original 430b, guest PC 0x0c054b86 */
if(!s->budget--) { s->failed_pc=0x0c054b86u; return 0; }
target=r[3];
r[16]=code_base|0x0c054b8au;
r[1]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054b8au) { target=s->pc; goto dispatch; }
goto P_0c054b8a;
P_0c054b88: /* original 6163, guest PC 0x0c054b88 */
if(!s->budget--) { s->failed_pc=0x0c054b88u; return 0; }
r[1]=r[6];
goto P_0c054b8a;
P_0c054b8a: /* original 6e03, guest PC 0x0c054b8a */
if(!s->budget--) { s->failed_pc=0x0c054b8au; return 0; }
r[14]=r[0];
goto P_0c054b8c;
P_0c054b8c: /* original d21c, guest PC 0x0c054b8c */
if(!s->budget--) { s->failed_pc=0x0c054b8cu; return 0; }
r[2]=read(ram,0x0c054c00u,4);
goto P_0c054b8e;
P_0c054b8e: /* original 6163, guest PC 0x0c054b8e */
if(!s->budget--) { s->failed_pc=0x0c054b8eu; return 0; }
r[1]=r[6];
goto P_0c054b90;
P_0c054b90: /* original 3e4c, guest PC 0x0c054b90 */
if(!s->budget--) { s->failed_pc=0x0c054b90u; return 0; }
r[14]+=r[4];
goto P_0c054b92;
P_0c054b92: /* original 67e3, guest PC 0x0c054b92 */
if(!s->budget--) { s->failed_pc=0x0c054b92u; return 0; }
r[7]=r[14];
goto P_0c054b94;
P_0c054b94: /* original 420b, guest PC 0x0c054b94 */
if(!s->budget--) { s->failed_pc=0x0c054b94u; return 0; }
target=r[2];
r[16]=code_base|0x0c054b98u;
r[0]=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c054b98u) { target=s->pc; goto dispatch; }
goto P_0c054b98;
P_0c054b96: /* original e008, guest PC 0x0c054b96 */
if(!s->budget--) { s->failed_pc=0x0c054b96u; return 0; }
r[0]=0x00000008u;
goto P_0c054b98;
P_0c054b98: /* original 9d2e, guest PC 0x0c054b98 */
if(!s->budget--) { s->failed_pc=0x0c054b98u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c054bf8u,2);
goto P_0c054b9a;
P_0c054b9a: /* original 600b, guest PC 0x0c054b9a */
if(!s->budget--) { s->failed_pc=0x0c054b9au; return 0; }
r[0]=0u-r[0];
goto P_0c054b9c;
P_0c054b9c: /* original 0009, guest PC 0x0c054b9c */
if(!s->budget--) { s->failed_pc=0x0c054b9cu; return 0; }
goto P_0c054b9e;
P_0c054b9e: /* original 4d0c, guest PC 0x0c054b9e */
if(!s->budget--) { s->failed_pc=0x0c054b9eu; return 0; }
r[13]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[13]>>((-r[0])&31u)):((int32_t)r[13]<0?0xffffffffu:0)):r[13]<<(r[0]&31u);
goto P_0c054ba0;
P_0c054ba0: /* original 6370, guest PC 0x0c054ba0 */
if(!s->budget--) { s->failed_pc=0x0c054ba0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c054ba2;
P_0c054ba2: /* original 62dc, guest PC 0x0c054ba2 */
if(!s->budget--) { s->failed_pc=0x0c054ba2u; return 0; }
r[2]=r[13]&255u;
goto P_0c054ba4;
P_0c054ba4: /* original 633c, guest PC 0x0c054ba4 */
if(!s->budget--) { s->failed_pc=0x0c054ba4u; return 0; }
r[3]=r[3]&255u;
goto P_0c054ba6;
P_0c054ba6: /* original 2328, guest PC 0x0c054ba6 */
if(!s->budget--) { s->failed_pc=0x0c054ba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c054ba8;
P_0c054ba8: /* original 8f22, guest PC 0x0c054ba8 */
if(!s->budget--) { s->failed_pc=0x0c054ba8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054bf0; }
goto P_0c054bac;
P_0c054baa: /* original 0009, guest PC 0x0c054baa */
if(!s->budget--) { s->failed_pc=0x0c054baau; return 0; }
goto P_0c054bac;
P_0c054bac: /* original 66d3, guest PC 0x0c054bac */
if(!s->budget--) { s->failed_pc=0x0c054bacu; return 0; }
r[6]=r[13];
goto P_0c054bae;
P_0c054bae: /* original a003, guest PC 0x0c054bae */
if(!s->budget--) { s->failed_pc=0x0c054baeu; return 0; }
r[0]=0x00000000u;
goto P_0c054bb8;
P_0c054bb0: /* original e000, guest PC 0x0c054bb0 */
if(!s->budget--) { s->failed_pc=0x0c054bb0u; return 0; }
r[0]=0x00000000u;
goto P_0c054bb2;
P_0c054bb2: /* original 206b, guest PC 0x0c054bb2 */
if(!s->budget--) { s->failed_pc=0x0c054bb2u; return 0; }
r[0]|=r[6];
goto P_0c054bb4;
P_0c054bb4: /* original 666c, guest PC 0x0c054bb4 */
if(!s->budget--) { s->failed_pc=0x0c054bb4u; return 0; }
r[6]=r[6]&255u;
goto P_0c054bb6;
P_0c054bb6: /* original 4601, guest PC 0x0c054bb6 */
if(!s->budget--) { s->failed_pc=0x0c054bb6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c054bb8;
P_0c054bb8: /* original 626c, guest PC 0x0c054bb8 */
if(!s->budget--) { s->failed_pc=0x0c054bb8u; return 0; }
r[2]=r[6]&255u;
goto P_0c054bba;
P_0c054bba: /* original 2228, guest PC 0x0c054bba */
if(!s->budget--) { s->failed_pc=0x0c054bbau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054bbc;
P_0c054bbc: /* original 8ff9, guest PC 0x0c054bbc */
if(!s->budget--) { s->failed_pc=0x0c054bbcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054bb2; }
goto P_0c054bc0;
P_0c054bbe: /* original 0009, guest PC 0x0c054bbe */
if(!s->budget--) { s->failed_pc=0x0c054bbeu; return 0; }
goto P_0c054bc0;
P_0c054bc0: /* original 6170, guest PC 0x0c054bc0 */
if(!s->budget--) { s->failed_pc=0x0c054bc0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[1]=tmp;
goto P_0c054bc2;
P_0c054bc2: /* original 600c, guest PC 0x0c054bc2 */
if(!s->budget--) { s->failed_pc=0x0c054bc2u; return 0; }
r[0]=r[0]&255u;
goto P_0c054bc4;
P_0c054bc4: /* original 611c, guest PC 0x0c054bc4 */
if(!s->budget--) { s->failed_pc=0x0c054bc4u; return 0; }
r[1]=r[1]&255u;
goto P_0c054bc6;
P_0c054bc6: /* original 2108, guest PC 0x0c054bc6 */
if(!s->budget--) { s->failed_pc=0x0c054bc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[0])==0)!=0);
goto P_0c054bc8;
P_0c054bc8: /* original 8d04, guest PC 0x0c054bc8 */
if(!s->budget--) { s->failed_pc=0x0c054bc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054bd4; }
goto P_0c054bcc;
P_0c054bca: /* original 0009, guest PC 0x0c054bca */
if(!s->budget--) { s->failed_pc=0x0c054bcau; return 0; }
goto P_0c054bcc;
P_0c054bcc: /* original 6270, guest PC 0x0c054bcc */
if(!s->budget--) { s->failed_pc=0x0c054bccu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[2]=tmp;
goto P_0c054bce;
P_0c054bce: /* original 22db, guest PC 0x0c054bce */
if(!s->budget--) { s->failed_pc=0x0c054bceu; return 0; }
r[2]|=r[13];
goto P_0c054bd0;
P_0c054bd0: /* original a00e, guest PC 0x0c054bd0 */
if(!s->budget--) { s->failed_pc=0x0c054bd0u; return 0; }
write(ram,r[7],r[2],1);
goto P_0c054bf0;
P_0c054bd2: /* original 2720, guest PC 0x0c054bd2 */
if(!s->budget--) { s->failed_pc=0x0c054bd2u; return 0; }
write(ram,r[7],r[2],1);
goto P_0c054bd4;
P_0c054bd4: /* original a008, guest PC 0x0c054bd4 */
if(!s->budget--) { s->failed_pc=0x0c054bd4u; return 0; }
r[4]+=r[5];
goto P_0c054be8;
P_0c054bd6: /* original 345c, guest PC 0x0c054bd6 */
if(!s->budget--) { s->failed_pc=0x0c054bd6u; return 0; }
r[4]+=r[5];
goto P_0c054bd8;
P_0c054bd8: /* original 6370, guest PC 0x0c054bd8 */
if(!s->budget--) { s->failed_pc=0x0c054bd8u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[3]=tmp;
goto P_0c054bda;
P_0c054bda: /* original 2338, guest PC 0x0c054bda */
if(!s->budget--) { s->failed_pc=0x0c054bdau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c054bdc;
P_0c054bdc: /* original 8d04, guest PC 0x0c054bdc */
if(!s->budget--) { s->failed_pc=0x0c054bdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054be8; }
goto P_0c054be0;
P_0c054bde: /* original 0009, guest PC 0x0c054bde */
if(!s->budget--) { s->failed_pc=0x0c054bdeu; return 0; }
goto P_0c054be0;
P_0c054be0: /* original 61e0, guest PC 0x0c054be0 */
if(!s->budget--) { s->failed_pc=0x0c054be0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[14],1);
r[1]=tmp;
goto P_0c054be2;
P_0c054be2: /* original 21db, guest PC 0x0c054be2 */
if(!s->budget--) { s->failed_pc=0x0c054be2u; return 0; }
r[1]|=r[13];
goto P_0c054be4;
P_0c054be4: /* original a004, guest PC 0x0c054be4 */
if(!s->budget--) { s->failed_pc=0x0c054be4u; return 0; }
write(ram,r[14],r[1],1);
goto P_0c054bf0;
P_0c054be6: /* original 2e10, guest PC 0x0c054be6 */
if(!s->budget--) { s->failed_pc=0x0c054be6u; return 0; }
write(ram,r[14],r[1],1);
goto P_0c054be8;
P_0c054be8: /* original 7701, guest PC 0x0c054be8 */
if(!s->budget--) { s->failed_pc=0x0c054be8u; return 0; }
r[7]+=0x00000001u;
goto P_0c054bea;
P_0c054bea: /* original 3742, guest PC 0x0c054bea */
if(!s->budget--) { s->failed_pc=0x0c054beau; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[4])!=0);
goto P_0c054bec;
P_0c054bec: /* original 8ff4, guest PC 0x0c054bec */
if(!s->budget--) { s->failed_pc=0x0c054becu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054bd8; }
goto P_0c054bf0;
P_0c054bee: /* original 0009, guest PC 0x0c054bee */
if(!s->budget--) { s->failed_pc=0x0c054beeu; return 0; }
goto P_0c054bf0;
P_0c054bf0: /* original 4f26, guest PC 0x0c054bf0 */
if(!s->budget--) { s->failed_pc=0x0c054bf0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c054bf2;
P_0c054bf2: /* original 6df6, guest PC 0x0c054bf2 */
if(!s->budget--) { s->failed_pc=0x0c054bf2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c054bf4;
P_0c054bf4: /* original 000b, guest PC 0x0c054bf4 */
if(!s->budget--) { s->failed_pc=0x0c054bf4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c054bf6: /* original 6ef6, guest PC 0x0c054bf6 */
if(!s->budget--) { s->failed_pc=0x0c054bf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c054bf8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c054bf8u; return 0; } return 1;
P_0c054f94: /* original 2f16, guest PC 0x0c054f94 */
if(!s->budget--) { s->failed_pc=0x0c054f94u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054f96;
P_0c054f96: /* original 2f26, guest PC 0x0c054f96 */
if(!s->budget--) { s->failed_pc=0x0c054f96u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054f98;
P_0c054f98: /* original 2f36, guest PC 0x0c054f98 */
if(!s->budget--) { s->failed_pc=0x0c054f98u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054f9a;
P_0c054f9a: /* original 2f46, guest PC 0x0c054f9a */
if(!s->budget--) { s->failed_pc=0x0c054f9au; return 0; }
tmp=r[4]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054f9c;
P_0c054f9c: /* original 2f56, guest PC 0x0c054f9c */
if(!s->budget--) { s->failed_pc=0x0c054f9cu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c054f9e;
P_0c054f9e: /* original 51f5, guest PC 0x0c054f9e */
if(!s->budget--) { s->failed_pc=0x0c054f9eu; return 0; }
r[1]=read(ram,r[15]+20,4);
goto P_0c054fa0;
P_0c054fa0: /* original 50f6, guest PC 0x0c054fa0 */
if(!s->budget--) { s->failed_pc=0x0c054fa0u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c054fa2;
P_0c054fa2: /* original d41b, guest PC 0x0c054fa2 */
if(!s->budget--) { s->failed_pc=0x0c054fa2u; return 0; }
r[4]=read(ram,0x0c055010u,4);
goto P_0c054fa4;
P_0c054fa4: /* original d51b, guest PC 0x0c054fa4 */
if(!s->budget--) { s->failed_pc=0x0c054fa4u; return 0; }
r[5]=read(ram,0x0c055014u,4);
goto P_0c054fa6;
P_0c054fa6: /* original 6303, guest PC 0x0c054fa6 */
if(!s->budget--) { s->failed_pc=0x0c054fa6u; return 0; }
r[3]=r[0];
goto P_0c054fa8;
P_0c054fa8: /* original 6203, guest PC 0x0c054fa8 */
if(!s->budget--) { s->failed_pc=0x0c054fa8u; return 0; }
r[2]=r[0];
goto P_0c054faa;
P_0c054faa: /* original 4229, guest PC 0x0c054faa */
if(!s->budget--) { s->failed_pc=0x0c054faau; return 0; }
r[2]>>=16;
goto P_0c054fac;
P_0c054fac: /* original 4209, guest PC 0x0c054fac */
if(!s->budget--) { s->failed_pc=0x0c054facu; return 0; }
r[2]>>=2;
goto P_0c054fae;
P_0c054fae: /* original 4209, guest PC 0x0c054fae */
if(!s->budget--) { s->failed_pc=0x0c054faeu; return 0; }
r[2]>>=2;
goto P_0c054fb0;
P_0c054fb0: /* original 2249, guest PC 0x0c054fb0 */
if(!s->budget--) { s->failed_pc=0x0c054fb0u; return 0; }
r[2]&=r[4];
goto P_0c054fb2;
P_0c054fb2: /* original 2059, guest PC 0x0c054fb2 */
if(!s->budget--) { s->failed_pc=0x0c054fb2u; return 0; }
r[0]&=r[5];
goto P_0c054fb4;
P_0c054fb4: /* original d419, guest PC 0x0c054fb4 */
if(!s->budget--) { s->failed_pc=0x0c054fb4u; return 0; }
r[4]=read(ram,0x0c05501cu,4);
goto P_0c054fb6;
P_0c054fb6: /* original 3248, guest PC 0x0c054fb6 */
if(!s->budget--) { s->failed_pc=0x0c054fb6u; return 0; }
r[2]-=r[4];
goto P_0c054fb8;
P_0c054fb8: /* original 4211, guest PC 0x0c054fb8 */
if(!s->budget--) { s->failed_pc=0x0c054fb8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c054fba;
P_0c054fba: /* original 8b27, guest PC 0x0c054fba */
if(!s->budget--) { s->failed_pc=0x0c054fbau; return 0; }
cond=r[17]&1u;
if(!cond) { return vf3_matrix_family(0x0c05500cu,s,ram); }
goto P_0c054fbc;
P_0c054fbc: /* original e453, guest PC 0x0c054fbc */
if(!s->budget--) { s->failed_pc=0x0c054fbcu; return 0; }
r[4]=0x00000053u;
goto P_0c054fbe;
P_0c054fbe: /* original 3247, guest PC 0x0c054fbe */
if(!s->budget--) { s->failed_pc=0x0c054fbeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[4])!=0);
goto P_0c054fc0;
P_0c054fc0: /* original 8924, guest PC 0x0c054fc0 */
if(!s->budget--) { s->failed_pc=0x0c054fc0u; return 0; }
cond=r[17]&1u;
if(cond) { return vf3_matrix_family(0x0c05500cu,s,ram); }
goto P_0c054fc2;
P_0c054fc2: /* original d415, guest PC 0x0c054fc2 */
if(!s->budget--) { s->failed_pc=0x0c054fc2u; return 0; }
r[4]=read(ram,0x0c055018u,4);
goto P_0c054fc4;
P_0c054fc4: /* original 204b, guest PC 0x0c054fc4 */
if(!s->budget--) { s->failed_pc=0x0c054fc4u; return 0; }
r[0]|=r[4];
goto P_0c054fc6;
P_0c054fc6: /* original 72ec, guest PC 0x0c054fc6 */
if(!s->budget--) { s->failed_pc=0x0c054fc6u; return 0; }
r[2]+=0xffffffecu;
goto P_0c054fc8;
P_0c054fc8: /* original 4211, guest PC 0x0c054fc8 */
if(!s->budget--) { s->failed_pc=0x0c054fc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c054fca;
P_0c054fca: /* original 8b11, guest PC 0x0c054fca */
if(!s->budget--) { s->failed_pc=0x0c054fcau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054ff0; }
goto P_0c054fcc;
P_0c054fcc: /* original e420, guest PC 0x0c054fcc */
if(!s->budget--) { s->failed_pc=0x0c054fccu; return 0; }
r[4]=0x00000020u;
goto P_0c054fce;
P_0c054fce: /* original 3243, guest PC 0x0c054fce */
if(!s->budget--) { s->failed_pc=0x0c054fceu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c054fd0;
P_0c054fd0: /* original 8905, guest PC 0x0c054fd0 */
if(!s->budget--) { s->failed_pc=0x0c054fd0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054fde; }
goto P_0c054fd2;
P_0c054fd2: /* original 7201, guest PC 0x0c054fd2 */
if(!s->budget--) { s->failed_pc=0x0c054fd2u; return 0; }
r[2]+=0x00000001u;
goto P_0c054fd4;
P_0c054fd4: /* original 4210, guest PC 0x0c054fd4 */
if(!s->budget--) { s->failed_pc=0x0c054fd4u; return 0; }
--r[2];
r[17]=(r[17]&~1u)|((r[2]==0)!=0);
goto P_0c054fd6;
P_0c054fd6: /* original 890f, guest PC 0x0c054fd6 */
if(!s->budget--) { s->failed_pc=0x0c054fd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054ff8; }
goto P_0c054fd8;
P_0c054fd8: /* original 4100, guest PC 0x0c054fd8 */
if(!s->budget--) { s->failed_pc=0x0c054fd8u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c054fda;
P_0c054fda: /* original affb, guest PC 0x0c054fda */
if(!s->budget--) { s->failed_pc=0x0c054fdau; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054fd4;
P_0c054fdc: /* original 4024, guest PC 0x0c054fdc */
if(!s->budget--) { s->failed_pc=0x0c054fdcu; return 0; }
tmp=r[0]>>31; r[0]=(r[0]<<1)|(r[17]&1u);
r[17]=(r[17]&~1u)|((tmp)!=0);
goto P_0c054fde;
P_0c054fde: /* original 6013, guest PC 0x0c054fde */
if(!s->budget--) { s->failed_pc=0x0c054fdeu; return 0; }
r[0]=r[1];
goto P_0c054fe0;
P_0c054fe0: /* original 72e0, guest PC 0x0c054fe0 */
if(!s->budget--) { s->failed_pc=0x0c054fe0u; return 0; }
r[2]+=0xffffffe0u;
goto P_0c054fe2;
P_0c054fe2: /* original 2228, guest PC 0x0c054fe2 */
if(!s->budget--) { s->failed_pc=0x0c054fe2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c054fe4;
P_0c054fe4: /* original 8908, guest PC 0x0c054fe4 */
if(!s->budget--) { s->failed_pc=0x0c054fe4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c054ff8; }
goto P_0c054fe6;
P_0c054fe6: /* original 4210, guest PC 0x0c054fe6 */
if(!s->budget--) { s->failed_pc=0x0c054fe6u; return 0; }
--r[2];
r[17]=(r[17]&~1u)|((r[2]==0)!=0);
goto P_0c054fe8;
P_0c054fe8: /* original 8ffd, guest PC 0x0c054fe8 */
if(!s->budget--) { s->failed_pc=0x0c054fe8u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
if(!cond) { goto P_0c054fe6; }
goto P_0c054fec;
P_0c054fea: /* original 4000, guest PC 0x0c054fea */
if(!s->budget--) { s->failed_pc=0x0c054feau; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c054fec;
P_0c054fec: /* original a004, guest PC 0x0c054fec */
if(!s->budget--) { s->failed_pc=0x0c054fecu; return 0; }
goto P_0c054ff8;
P_0c054fee: /* original 0009, guest PC 0x0c054fee */
if(!s->budget--) { s->failed_pc=0x0c054feeu; return 0; }
goto P_0c054ff0;
P_0c054ff0: /* original 622b, guest PC 0x0c054ff0 */
if(!s->budget--) { s->failed_pc=0x0c054ff0u; return 0; }
r[2]=0u-r[2];
goto P_0c054ff2;
P_0c054ff2: /* original 4210, guest PC 0x0c054ff2 */
if(!s->budget--) { s->failed_pc=0x0c054ff2u; return 0; }
--r[2];
r[17]=(r[17]&~1u)|((r[2]==0)!=0);
goto P_0c054ff4;
P_0c054ff4: /* original 8ffd, guest PC 0x0c054ff4 */
if(!s->budget--) { s->failed_pc=0x0c054ff4u; return 0; }
cond=r[17]&1u;
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
if(!cond) { goto P_0c054ff2; }
goto P_0c054ff8;
P_0c054ff6: /* original 4001, guest PC 0x0c054ff6 */
if(!s->budget--) { s->failed_pc=0x0c054ff6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c054ff8;
P_0c054ff8: /* original 4300, guest PC 0x0c054ff8 */
if(!s->budget--) { s->failed_pc=0x0c054ff8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c054ffa;
P_0c054ffa: /* original 8b00, guest PC 0x0c054ffa */
if(!s->budget--) { s->failed_pc=0x0c054ffau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c054ffe; }
goto P_0c054ffc;
P_0c054ffc: /* original 600b, guest PC 0x0c054ffc */
if(!s->budget--) { s->failed_pc=0x0c054ffcu; return 0; }
r[0]=0u-r[0];
goto P_0c054ffe;
P_0c054ffe: /* original 65f6, guest PC 0x0c054ffe */
if(!s->budget--) { s->failed_pc=0x0c054ffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[5]=tmp;
goto P_0c055000;
P_0c055000: /* original 64f6, guest PC 0x0c055000 */
if(!s->budget--) { s->failed_pc=0x0c055000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[4]=tmp;
goto P_0c055002;
P_0c055002: /* original 63f6, guest PC 0x0c055002 */
if(!s->budget--) { s->failed_pc=0x0c055002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c055004;
P_0c055004: /* original 62f6, guest PC 0x0c055004 */
if(!s->budget--) { s->failed_pc=0x0c055004u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[2]=tmp;
goto P_0c055006;
P_0c055006: /* original 61f6, guest PC 0x0c055006 */
if(!s->budget--) { s->failed_pc=0x0c055006u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c055008;
P_0c055008: /* original 000b, guest PC 0x0c055008 */
if(!s->budget--) { s->failed_pc=0x0c055008u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c05500a: /* original 7f08, guest PC 0x0c05500a */
if(!s->budget--) { s->failed_pc=0x0c05500au; return 0; }
r[15]+=0x00000008u;
return vf3_matrix_family(0x0c05500cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
