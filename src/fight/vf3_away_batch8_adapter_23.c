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
int vf3_away_batch8_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c065a94u: goto P_0c065a94;
case 0x0c065a96u: goto P_0c065a96;
case 0x0c065a98u: goto P_0c065a98;
case 0x0c065a9au: goto P_0c065a9a;
case 0x0c065a9cu: goto P_0c065a9c;
case 0x0c065a9eu: goto P_0c065a9e;
case 0x0c065aa0u: goto P_0c065aa0;
case 0x0c065aa2u: goto P_0c065aa2;
case 0x0c065aa4u: goto P_0c065aa4;
case 0x0c065aa6u: goto P_0c065aa6;
case 0x0c065aa8u: goto P_0c065aa8;
case 0x0c065aaau: goto P_0c065aaa;
case 0x0c065aacu: goto P_0c065aac;
case 0x0c065aaeu: goto P_0c065aae;
case 0x0c065ab0u: goto P_0c065ab0;
case 0x0c065ab2u: goto P_0c065ab2;
case 0x0c065ab4u: goto P_0c065ab4;
case 0x0c065ab6u: goto P_0c065ab6;
case 0x0c065ab8u: goto P_0c065ab8;
case 0x0c065abau: goto P_0c065aba;
case 0x0c065abcu: goto P_0c065abc;
case 0x0c065abeu: goto P_0c065abe;
case 0x0c065ac0u: goto P_0c065ac0;
case 0x0c065ac2u: goto P_0c065ac2;
case 0x0c065ac4u: goto P_0c065ac4;
case 0x0c065ac6u: goto P_0c065ac6;
case 0x0c065ac8u: goto P_0c065ac8;
case 0x0c065acau: goto P_0c065aca;
case 0x0c065accu: goto P_0c065acc;
case 0x0c065aceu: goto P_0c065ace;
case 0x0c065ad0u: goto P_0c065ad0;
case 0x0c065ad2u: goto P_0c065ad2;
case 0x0c065ad4u: goto P_0c065ad4;
case 0x0c065ad6u: goto P_0c065ad6;
case 0x0c065ad8u: goto P_0c065ad8;
case 0x0c065adau: goto P_0c065ada;
case 0x0c065adcu: goto P_0c065adc;
case 0x0c065adeu: goto P_0c065ade;
case 0x0c065ae0u: goto P_0c065ae0;
case 0x0c065ae2u: goto P_0c065ae2;
case 0x0c065ae4u: goto P_0c065ae4;
case 0x0c065ae6u: goto P_0c065ae6;
case 0x0c065ae8u: goto P_0c065ae8;
case 0x0c065aeau: goto P_0c065aea;
case 0x0c065aecu: goto P_0c065aec;
case 0x0c065aeeu: goto P_0c065aee;
case 0x0c065af0u: goto P_0c065af0;
case 0x0c065af2u: goto P_0c065af2;
case 0x0c065af4u: goto P_0c065af4;
case 0x0c065af6u: goto P_0c065af6;
case 0x0c065af8u: goto P_0c065af8;
case 0x0c065afau: goto P_0c065afa;
case 0x0c065afcu: goto P_0c065afc;
case 0x0c065afeu: goto P_0c065afe;
case 0x0c065b00u: goto P_0c065b00;
case 0x0c065b02u: goto P_0c065b02;
case 0x0c065b04u: goto P_0c065b04;
case 0x0c065b06u: goto P_0c065b06;
case 0x0c065b08u: goto P_0c065b08;
case 0x0c065b0au: goto P_0c065b0a;
case 0x0c065b0cu: goto P_0c065b0c;
case 0x0c065b0eu: goto P_0c065b0e;
case 0x0c065b10u: goto P_0c065b10;
case 0x0c065b12u: goto P_0c065b12;
case 0x0c065b14u: goto P_0c065b14;
case 0x0c065b16u: goto P_0c065b16;
case 0x0c065b18u: goto P_0c065b18;
case 0x0c065b1au: goto P_0c065b1a;
case 0x0c065b1cu: goto P_0c065b1c;
case 0x0c065b1eu: goto P_0c065b1e;
case 0x0c065b20u: goto P_0c065b20;
case 0x0c065b22u: goto P_0c065b22;
case 0x0c065b24u: goto P_0c065b24;
case 0x0c065b26u: goto P_0c065b26;
case 0x0c065b28u: goto P_0c065b28;
case 0x0c065b2au: goto P_0c065b2a;
case 0x0c065b2cu: goto P_0c065b2c;
case 0x0c065b2eu: goto P_0c065b2e;
case 0x0c065b30u: goto P_0c065b30;
case 0x0c065b32u: goto P_0c065b32;
case 0x0c065b34u: goto P_0c065b34;
case 0x0c065b36u: goto P_0c065b36;
case 0x0c065b38u: goto P_0c065b38;
case 0x0c065b3au: goto P_0c065b3a;
case 0x0c065b3cu: goto P_0c065b3c;
case 0x0c065b3eu: goto P_0c065b3e;
case 0x0c065b40u: goto P_0c065b40;
case 0x0c065b42u: goto P_0c065b42;
case 0x0c065b44u: goto P_0c065b44;
case 0x0c065b46u: goto P_0c065b46;
case 0x0c065b48u: goto P_0c065b48;
case 0x0c065b4au: goto P_0c065b4a;
case 0x0c065b4cu: goto P_0c065b4c;
case 0x0c065b4eu: goto P_0c065b4e;
case 0x0c065b50u: goto P_0c065b50;
case 0x0c065b52u: goto P_0c065b52;
case 0x0c065b54u: goto P_0c065b54;
case 0x0c065b56u: goto P_0c065b56;
case 0x0c065b58u: goto P_0c065b58;
case 0x0c065b5au: goto P_0c065b5a;
case 0x0c065b5cu: goto P_0c065b5c;
case 0x0c065b5eu: goto P_0c065b5e;
case 0x0c065b60u: goto P_0c065b60;
case 0x0c065b62u: goto P_0c065b62;
case 0x0c065b64u: goto P_0c065b64;
case 0x0c065b66u: goto P_0c065b66;
case 0x0c065b68u: goto P_0c065b68;
case 0x0c065b6au: goto P_0c065b6a;
case 0x0c065b6cu: goto P_0c065b6c;
case 0x0c065b6eu: goto P_0c065b6e;
case 0x0c065b70u: goto P_0c065b70;
case 0x0c065b72u: goto P_0c065b72;
case 0x0c065b74u: goto P_0c065b74;
case 0x0c065b76u: goto P_0c065b76;
case 0x0c065b78u: goto P_0c065b78;
case 0x0c065b7au: goto P_0c065b7a;
case 0x0c065b7cu: goto P_0c065b7c;
case 0x0c065b7eu: goto P_0c065b7e;
case 0x0c065b80u: goto P_0c065b80;
case 0x0c065b82u: goto P_0c065b82;
case 0x0c065b84u: goto P_0c065b84;
case 0x0c065b86u: goto P_0c065b86;
case 0x0c065b88u: goto P_0c065b88;
case 0x0c065b8au: goto P_0c065b8a;
case 0x0c065b8cu: goto P_0c065b8c;
case 0x0c065b8eu: goto P_0c065b8e;
case 0x0c065b90u: goto P_0c065b90;
case 0x0c065b92u: goto P_0c065b92;
case 0x0c065b94u: goto P_0c065b94;
case 0x0c065b96u: goto P_0c065b96;
case 0x0c065b98u: goto P_0c065b98;
case 0x0c065b9au: goto P_0c065b9a;
case 0x0c065b9cu: goto P_0c065b9c;
case 0x0c065b9eu: goto P_0c065b9e;
case 0x0c065ba0u: goto P_0c065ba0;
case 0x0c065ba2u: goto P_0c065ba2;
case 0x0c065ba4u: goto P_0c065ba4;
case 0x0c065ba6u: goto P_0c065ba6;
case 0x0c065ba8u: goto P_0c065ba8;
case 0x0c065baau: goto P_0c065baa;
case 0x0c065bacu: goto P_0c065bac;
case 0x0c065baeu: goto P_0c065bae;
case 0x0c065bb0u: goto P_0c065bb0;
case 0x0c065bb2u: goto P_0c065bb2;
case 0x0c065bb4u: goto P_0c065bb4;
case 0x0c065bb6u: goto P_0c065bb6;
case 0x0c065bb8u: goto P_0c065bb8;
case 0x0c065bbau: goto P_0c065bba;
case 0x0c065bbcu: goto P_0c065bbc;
case 0x0c065bbeu: goto P_0c065bbe;
case 0x0c065bc0u: goto P_0c065bc0;
case 0x0c065bc2u: goto P_0c065bc2;
case 0x0c065bc4u: goto P_0c065bc4;
case 0x0c065bc6u: goto P_0c065bc6;
case 0x0c065bc8u: goto P_0c065bc8;
case 0x0c065bcau: goto P_0c065bca;
case 0x0c065bccu: goto P_0c065bcc;
case 0x0c065bceu: goto P_0c065bce;
case 0x0c065bd0u: goto P_0c065bd0;
case 0x0c065bd2u: goto P_0c065bd2;
case 0x0c065bd4u: goto P_0c065bd4;
case 0x0c065bd6u: goto P_0c065bd6;
case 0x0c065bd8u: goto P_0c065bd8;
case 0x0c065bdau: goto P_0c065bda;
case 0x0c065bdcu: goto P_0c065bdc;
case 0x0c065bdeu: goto P_0c065bde;
case 0x0c065be0u: goto P_0c065be0;
case 0x0c065be2u: goto P_0c065be2;
case 0x0c065be4u: goto P_0c065be4;
case 0x0c065be6u: goto P_0c065be6;
case 0x0c065be8u: goto P_0c065be8;
case 0x0c065beau: goto P_0c065bea;
case 0x0c065becu: goto P_0c065bec;
case 0x0c065beeu: goto P_0c065bee;
case 0x0c065bf0u: goto P_0c065bf0;
case 0x0c065bf2u: goto P_0c065bf2;
case 0x0c065bf4u: goto P_0c065bf4;
case 0x0c065bf6u: goto P_0c065bf6;
case 0x0c065bf8u: goto P_0c065bf8;
case 0x0c065bfau: goto P_0c065bfa;
case 0x0c065bfcu: goto P_0c065bfc;
case 0x0c065bfeu: goto P_0c065bfe;
case 0x0c065c00u: goto P_0c065c00;
case 0x0c065c02u: goto P_0c065c02;
case 0x0c065c04u: goto P_0c065c04;
case 0x0c065c06u: goto P_0c065c06;
case 0x0c065c08u: goto P_0c065c08;
case 0x0c065c0au: goto P_0c065c0a;
case 0x0c065c0cu: goto P_0c065c0c;
case 0x0c065c0eu: goto P_0c065c0e;
case 0x0c065c10u: goto P_0c065c10;
case 0x0c065c12u: goto P_0c065c12;
case 0x0c06629cu: goto P_0c06629c;
case 0x0c06629eu: goto P_0c06629e;
case 0x0c0662a0u: goto P_0c0662a0;
case 0x0c0662a2u: goto P_0c0662a2;
case 0x0c0662a4u: goto P_0c0662a4;
case 0x0c0662a6u: goto P_0c0662a6;
case 0x0c0662a8u: goto P_0c0662a8;
case 0x0c0662aau: goto P_0c0662aa;
case 0x0c0662acu: goto P_0c0662ac;
case 0x0c0662aeu: goto P_0c0662ae;
case 0x0c0662b0u: goto P_0c0662b0;
case 0x0c0662b2u: goto P_0c0662b2;
case 0x0c0662b4u: goto P_0c0662b4;
case 0x0c0662b6u: goto P_0c0662b6;
case 0x0c0662b8u: goto P_0c0662b8;
case 0x0c0662bau: goto P_0c0662ba;
case 0x0c0662bcu: goto P_0c0662bc;
case 0x0c0662beu: goto P_0c0662be;
case 0x0c0662c0u: goto P_0c0662c0;
case 0x0c0662c2u: goto P_0c0662c2;
case 0x0c0662c4u: goto P_0c0662c4;
case 0x0c0662c6u: goto P_0c0662c6;
case 0x0c0662c8u: goto P_0c0662c8;
case 0x0c0662cau: goto P_0c0662ca;
case 0x0c0662ccu: goto P_0c0662cc;
case 0x0c0662ceu: goto P_0c0662ce;
case 0x0c0662d0u: goto P_0c0662d0;
case 0x0c0662d2u: goto P_0c0662d2;
case 0x0c0662d4u: goto P_0c0662d4;
case 0x0c0662d6u: goto P_0c0662d6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c065a94: /* original 2fe6, guest PC 0x0c065a94 */
if(!s->budget--) { s->failed_pc=0x0c065a94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065a96;
P_0c065a96: /* original 2fd6, guest PC 0x0c065a96 */
if(!s->budget--) { s->failed_pc=0x0c065a96u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065a98;
P_0c065a98: /* original 2fc6, guest PC 0x0c065a98 */
if(!s->budget--) { s->failed_pc=0x0c065a98u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065a9a;
P_0c065a9a: /* original ec00, guest PC 0x0c065a9a */
if(!s->budget--) { s->failed_pc=0x0c065a9au; return 0; }
r[12]=0x00000000u;
goto P_0c065a9c;
P_0c065a9c: /* original 2fb6, guest PC 0x0c065a9c */
if(!s->budget--) { s->failed_pc=0x0c065a9cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065a9e;
P_0c065a9e: /* original 2fa6, guest PC 0x0c065a9e */
if(!s->budget--) { s->failed_pc=0x0c065a9eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c065aa0;
P_0c065aa0: /* original 4f22, guest PC 0x0c065aa0 */
if(!s->budget--) { s->failed_pc=0x0c065aa0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c065aa2;
P_0c065aa2: /* original 7ff0, guest PC 0x0c065aa2 */
if(!s->budget--) { s->failed_pc=0x0c065aa2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c065aa4;
P_0c065aa4: /* original 6342, guest PC 0x0c065aa4 */
if(!s->budget--) { s->failed_pc=0x0c065aa4u; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c065aa6;
P_0c065aa6: /* original 65f3, guest PC 0x0c065aa6 */
if(!s->budget--) { s->failed_pc=0x0c065aa6u; return 0; }
r[5]=r[15];
goto P_0c065aa8;
P_0c065aa8: /* original 7504, guest PC 0x0c065aa8 */
if(!s->budget--) { s->failed_pc=0x0c065aa8u; return 0; }
r[5]+=0x00000004u;
goto P_0c065aaa;
P_0c065aaa: /* original 6d53, guest PC 0x0c065aaa */
if(!s->budget--) { s->failed_pc=0x0c065aaau; return 0; }
r[13]=r[5];
goto P_0c065aac;
P_0c065aac: /* original 2d32, guest PC 0x0c065aac */
if(!s->budget--) { s->failed_pc=0x0c065aacu; return 0; }
write(ram,r[13],r[3],4);
goto P_0c065aae;
P_0c065aae: /* original 6ad3, guest PC 0x0c065aae */
if(!s->budget--) { s->failed_pc=0x0c065aaeu; return 0; }
r[10]=r[13];
goto P_0c065ab0;
P_0c065ab0: /* original 5241, guest PC 0x0c065ab0 */
if(!s->budget--) { s->failed_pc=0x0c065ab0u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c065ab2;
P_0c065ab2: /* original 6bd3, guest PC 0x0c065ab2 */
if(!s->budget--) { s->failed_pc=0x0c065ab2u; return 0; }
r[11]=r[13];
goto P_0c065ab4;
P_0c065ab4: /* original 7a04, guest PC 0x0c065ab4 */
if(!s->budget--) { s->failed_pc=0x0c065ab4u; return 0; }
r[10]+=0x00000004u;
goto P_0c065ab6;
P_0c065ab6: /* original 7b08, guest PC 0x0c065ab6 */
if(!s->budget--) { s->failed_pc=0x0c065ab6u; return 0; }
r[11]+=0x00000008u;
goto P_0c065ab8;
P_0c065ab8: /* original 2a22, guest PC 0x0c065ab8 */
if(!s->budget--) { s->failed_pc=0x0c065ab8u; return 0; }
write(ram,r[10],r[2],4);
goto P_0c065aba;
P_0c065aba: /* original 5342, guest PC 0x0c065aba */
if(!s->budget--) { s->failed_pc=0x0c065abau; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c065abc;
P_0c065abc: /* original d255, guest PC 0x0c065abc */
if(!s->budget--) { s->failed_pc=0x0c065abcu; return 0; }
r[2]=read(ram,0x0c065c14u,4);
goto P_0c065abe;
P_0c065abe: /* original 2b32, guest PC 0x0c065abe */
if(!s->budget--) { s->failed_pc=0x0c065abeu; return 0; }
write(ram,r[11],r[3],4);
goto P_0c065ac0;
P_0c065ac0: /* original 6e22, guest PC 0x0c065ac0 */
if(!s->budget--) { s->failed_pc=0x0c065ac0u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c065ac2;
P_0c065ac2: /* original d355, guest PC 0x0c065ac2 */
if(!s->budget--) { s->failed_pc=0x0c065ac2u; return 0; }
r[3]=read(ram,0x0c065c18u,4);
goto P_0c065ac4;
P_0c065ac4: /* original 6432, guest PC 0x0c065ac4 */
if(!s->budget--) { s->failed_pc=0x0c065ac4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c065ac6;
P_0c065ac6: /* original d155, guest PC 0x0c065ac6 */
if(!s->budget--) { s->failed_pc=0x0c065ac6u; return 0; }
r[1]=read(ram,0x0c065c1cu,4);
goto P_0c065ac8;
P_0c065ac8: /* original 6512, guest PC 0x0c065ac8 */
if(!s->budget--) { s->failed_pc=0x0c065ac8u; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c065aca;
P_0c065aca: /* original d055, guest PC 0x0c065aca */
if(!s->budget--) { s->failed_pc=0x0c065acau; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065acc;
P_0c065acc: /* original 62c3, guest PC 0x0c065acc */
if(!s->budget--) { s->failed_pc=0x0c065accu; return 0; }
r[2]=r[12];
goto P_0c065ace;
P_0c065ace: /* original 7c01, guest PC 0x0c065ace */
if(!s->budget--) { s->failed_pc=0x0c065aceu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ad0;
P_0c065ad0: /* original 4208, guest PC 0x0c065ad0 */
if(!s->budget--) { s->failed_pc=0x0c065ad0u; return 0; }
r[2]<<=2;
goto P_0c065ad2;
P_0c065ad2: /* original 02e6, guest PC 0x0c065ad2 */
if(!s->budget--) { s->failed_pc=0x0c065ad2u; return 0; }
write(ram,r[2]+r[0],r[14],4);
goto P_0c065ad4;
P_0c065ad4: /* original 63c3, guest PC 0x0c065ad4 */
if(!s->budget--) { s->failed_pc=0x0c065ad4u; return 0; }
r[3]=r[12];
goto P_0c065ad6;
P_0c065ad6: /* original 7c01, guest PC 0x0c065ad6 */
if(!s->budget--) { s->failed_pc=0x0c065ad6u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ad8;
P_0c065ad8: /* original 4308, guest PC 0x0c065ad8 */
if(!s->budget--) { s->failed_pc=0x0c065ad8u; return 0; }
r[3]<<=2;
goto P_0c065ada;
P_0c065ada: /* original 0346, guest PC 0x0c065ada */
if(!s->budget--) { s->failed_pc=0x0c065adau; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c065adc;
P_0c065adc: /* original 62c3, guest PC 0x0c065adc */
if(!s->budget--) { s->failed_pc=0x0c065adcu; return 0; }
r[2]=r[12];
goto P_0c065ade;
P_0c065ade: /* original 7c01, guest PC 0x0c065ade */
if(!s->budget--) { s->failed_pc=0x0c065adeu; return 0; }
r[12]+=0x00000001u;
goto P_0c065ae0;
P_0c065ae0: /* original 4208, guest PC 0x0c065ae0 */
if(!s->budget--) { s->failed_pc=0x0c065ae0u; return 0; }
r[2]<<=2;
goto P_0c065ae2;
P_0c065ae2: /* original 0256, guest PC 0x0c065ae2 */
if(!s->budget--) { s->failed_pc=0x0c065ae2u; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c065ae4;
P_0c065ae4: /* original 62d2, guest PC 0x0c065ae4 */
if(!s->budget--) { s->failed_pc=0x0c065ae4u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065ae6;
P_0c065ae6: /* original 63c3, guest PC 0x0c065ae6 */
if(!s->budget--) { s->failed_pc=0x0c065ae6u; return 0; }
r[3]=r[12];
goto P_0c065ae8;
P_0c065ae8: /* original 5221, guest PC 0x0c065ae8 */
if(!s->budget--) { s->failed_pc=0x0c065ae8u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c065aea;
P_0c065aea: /* original 7c01, guest PC 0x0c065aea */
if(!s->budget--) { s->failed_pc=0x0c065aeau; return 0; }
r[12]+=0x00000001u;
goto P_0c065aec;
P_0c065aec: /* original 4308, guest PC 0x0c065aec */
if(!s->budget--) { s->failed_pc=0x0c065aecu; return 0; }
r[3]<<=2;
goto P_0c065aee;
P_0c065aee: /* original 0326, guest PC 0x0c065aee */
if(!s->budget--) { s->failed_pc=0x0c065aeeu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065af0;
P_0c065af0: /* original 62d2, guest PC 0x0c065af0 */
if(!s->budget--) { s->failed_pc=0x0c065af0u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065af2;
P_0c065af2: /* original 63c3, guest PC 0x0c065af2 */
if(!s->budget--) { s->failed_pc=0x0c065af2u; return 0; }
r[3]=r[12];
goto P_0c065af4;
P_0c065af4: /* original 5222, guest PC 0x0c065af4 */
if(!s->budget--) { s->failed_pc=0x0c065af4u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c065af6;
P_0c065af6: /* original 7c01, guest PC 0x0c065af6 */
if(!s->budget--) { s->failed_pc=0x0c065af6u; return 0; }
r[12]+=0x00000001u;
goto P_0c065af8;
P_0c065af8: /* original 4308, guest PC 0x0c065af8 */
if(!s->budget--) { s->failed_pc=0x0c065af8u; return 0; }
r[3]<<=2;
goto P_0c065afa;
P_0c065afa: /* original 0326, guest PC 0x0c065afa */
if(!s->budget--) { s->failed_pc=0x0c065afau; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065afc;
P_0c065afc: /* original 62d2, guest PC 0x0c065afc */
if(!s->budget--) { s->failed_pc=0x0c065afcu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065afe;
P_0c065afe: /* original 63c3, guest PC 0x0c065afe */
if(!s->budget--) { s->failed_pc=0x0c065afeu; return 0; }
r[3]=r[12];
goto P_0c065b00;
P_0c065b00: /* original 5223, guest PC 0x0c065b00 */
if(!s->budget--) { s->failed_pc=0x0c065b00u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c065b02;
P_0c065b02: /* original 7c01, guest PC 0x0c065b02 */
if(!s->budget--) { s->failed_pc=0x0c065b02u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b04;
P_0c065b04: /* original 4308, guest PC 0x0c065b04 */
if(!s->budget--) { s->failed_pc=0x0c065b04u; return 0; }
r[3]<<=2;
goto P_0c065b06;
P_0c065b06: /* original 0326, guest PC 0x0c065b06 */
if(!s->budget--) { s->failed_pc=0x0c065b06u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c065b08;
P_0c065b08: /* original 67d2, guest PC 0x0c065b08 */
if(!s->budget--) { s->failed_pc=0x0c065b08u; return 0; }
tmp=read(ram,r[13],4);
r[7]=tmp;
goto P_0c065b0a;
P_0c065b0a: /* original 2f72, guest PC 0x0c065b0a */
if(!s->budget--) { s->failed_pc=0x0c065b0au; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065b0c;
P_0c065b0c: /* original 5775, guest PC 0x0c065b0c */
if(!s->budget--) { s->failed_pc=0x0c065b0cu; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065b0e;
P_0c065b0e: /* original 66f2, guest PC 0x0c065b0e */
if(!s->budget--) { s->failed_pc=0x0c065b0eu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065b10;
P_0c065b10: /* original 5664, guest PC 0x0c065b10 */
if(!s->budget--) { s->failed_pc=0x0c065b10u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065b12;
P_0c065b12: /* original 65c3, guest PC 0x0c065b12 */
if(!s->budget--) { s->failed_pc=0x0c065b12u; return 0; }
r[5]=r[12];
goto P_0c065b14;
P_0c065b14: /* original d348, guest PC 0x0c065b14 */
if(!s->budget--) { s->failed_pc=0x0c065b14u; return 0; }
r[3]=read(ram,0x0c065c38u,4);
goto P_0c065b16;
P_0c065b16: /* original 430b, guest PC 0x0c065b16 */
if(!s->budget--) { s->failed_pc=0x0c065b16u; return 0; }
target=r[3];
r[16]=code_base|0x0c065b1au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065b1au) { target=s->pc; goto dispatch; }
goto P_0c065b1a;
P_0c065b18: /* original 64e3, guest PC 0x0c065b18 */
if(!s->budget--) { s->failed_pc=0x0c065b18u; return 0; }
r[4]=r[14];
goto P_0c065b1a;
P_0c065b1a: /* original 6c03, guest PC 0x0c065b1a */
if(!s->budget--) { s->failed_pc=0x0c065b1au; return 0; }
r[12]=r[0];
goto P_0c065b1c;
P_0c065b1c: /* original 63d2, guest PC 0x0c065b1c */
if(!s->budget--) { s->failed_pc=0x0c065b1cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c065b1e;
P_0c065b1e: /* original 62c3, guest PC 0x0c065b1e */
if(!s->budget--) { s->failed_pc=0x0c065b1eu; return 0; }
r[2]=r[12];
goto P_0c065b20;
P_0c065b20: /* original d03f, guest PC 0x0c065b20 */
if(!s->budget--) { s->failed_pc=0x0c065b20u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b22;
P_0c065b22: /* original 7c01, guest PC 0x0c065b22 */
if(!s->budget--) { s->failed_pc=0x0c065b22u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b24;
P_0c065b24: /* original 5136, guest PC 0x0c065b24 */
if(!s->budget--) { s->failed_pc=0x0c065b24u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065b26;
P_0c065b26: /* original 4208, guest PC 0x0c065b26 */
if(!s->budget--) { s->failed_pc=0x0c065b26u; return 0; }
r[2]<<=2;
goto P_0c065b28;
P_0c065b28: /* original 0216, guest PC 0x0c065b28 */
if(!s->budget--) { s->failed_pc=0x0c065b28u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065b2a;
P_0c065b2a: /* original 65c3, guest PC 0x0c065b2a */
if(!s->budget--) { s->failed_pc=0x0c065b2au; return 0; }
r[5]=r[12];
goto P_0c065b2c;
P_0c065b2c: /* original d343, guest PC 0x0c065b2c */
if(!s->budget--) { s->failed_pc=0x0c065b2cu; return 0; }
r[3]=read(ram,0x0c065c3cu,4);
goto P_0c065b2e;
P_0c065b2e: /* original 66d2, guest PC 0x0c065b2e */
if(!s->budget--) { s->failed_pc=0x0c065b2eu; return 0; }
tmp=read(ram,r[13],4);
r[6]=tmp;
goto P_0c065b30;
P_0c065b30: /* original 5667, guest PC 0x0c065b30 */
if(!s->budget--) { s->failed_pc=0x0c065b30u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065b32;
P_0c065b32: /* original 430b, guest PC 0x0c065b32 */
if(!s->budget--) { s->failed_pc=0x0c065b32u; return 0; }
target=r[3];
r[16]=code_base|0x0c065b36u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065b36u) { target=s->pc; goto dispatch; }
goto P_0c065b36;
P_0c065b34: /* original 64e3, guest PC 0x0c065b34 */
if(!s->budget--) { s->failed_pc=0x0c065b34u; return 0; }
r[4]=r[14];
goto P_0c065b36;
P_0c065b36: /* original 6c03, guest PC 0x0c065b36 */
if(!s->budget--) { s->failed_pc=0x0c065b36u; return 0; }
r[12]=r[0];
goto P_0c065b38;
P_0c065b38: /* original 61a2, guest PC 0x0c065b38 */
if(!s->budget--) { s->failed_pc=0x0c065b38u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065b3a;
P_0c065b3a: /* original 62c3, guest PC 0x0c065b3a */
if(!s->budget--) { s->failed_pc=0x0c065b3au; return 0; }
r[2]=r[12];
goto P_0c065b3c;
P_0c065b3c: /* original d038, guest PC 0x0c065b3c */
if(!s->budget--) { s->failed_pc=0x0c065b3cu; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b3e;
P_0c065b3e: /* original 7c01, guest PC 0x0c065b3e */
if(!s->budget--) { s->failed_pc=0x0c065b3eu; return 0; }
r[12]+=0x00000001u;
goto P_0c065b40;
P_0c065b40: /* original 5311, guest PC 0x0c065b40 */
if(!s->budget--) { s->failed_pc=0x0c065b40u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065b42;
P_0c065b42: /* original 4208, guest PC 0x0c065b42 */
if(!s->budget--) { s->failed_pc=0x0c065b42u; return 0; }
r[2]<<=2;
goto P_0c065b44;
P_0c065b44: /* original 0236, guest PC 0x0c065b44 */
if(!s->budget--) { s->failed_pc=0x0c065b44u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b46;
P_0c065b46: /* original 62c3, guest PC 0x0c065b46 */
if(!s->budget--) { s->failed_pc=0x0c065b46u; return 0; }
r[2]=r[12];
goto P_0c065b48;
P_0c065b48: /* original 61a2, guest PC 0x0c065b48 */
if(!s->budget--) { s->failed_pc=0x0c065b48u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065b4a;
P_0c065b4a: /* original 7c01, guest PC 0x0c065b4a */
if(!s->budget--) { s->failed_pc=0x0c065b4au; return 0; }
r[12]+=0x00000001u;
goto P_0c065b4c;
P_0c065b4c: /* original 5312, guest PC 0x0c065b4c */
if(!s->budget--) { s->failed_pc=0x0c065b4cu; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065b4e;
P_0c065b4e: /* original 4208, guest PC 0x0c065b4e */
if(!s->budget--) { s->failed_pc=0x0c065b4eu; return 0; }
r[2]<<=2;
goto P_0c065b50;
P_0c065b50: /* original 0236, guest PC 0x0c065b50 */
if(!s->budget--) { s->failed_pc=0x0c065b50u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b52;
P_0c065b52: /* original 62c3, guest PC 0x0c065b52 */
if(!s->budget--) { s->failed_pc=0x0c065b52u; return 0; }
r[2]=r[12];
goto P_0c065b54;
P_0c065b54: /* original 61a2, guest PC 0x0c065b54 */
if(!s->budget--) { s->failed_pc=0x0c065b54u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c065b56;
P_0c065b56: /* original 7c01, guest PC 0x0c065b56 */
if(!s->budget--) { s->failed_pc=0x0c065b56u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b58;
P_0c065b58: /* original 5313, guest PC 0x0c065b58 */
if(!s->budget--) { s->failed_pc=0x0c065b58u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065b5a;
P_0c065b5a: /* original 4208, guest PC 0x0c065b5a */
if(!s->budget--) { s->failed_pc=0x0c065b5au; return 0; }
r[2]<<=2;
goto P_0c065b5c;
P_0c065b5c: /* original 0236, guest PC 0x0c065b5c */
if(!s->budget--) { s->failed_pc=0x0c065b5cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b5e;
P_0c065b5e: /* original 65c3, guest PC 0x0c065b5e */
if(!s->budget--) { s->failed_pc=0x0c065b5eu; return 0; }
r[5]=r[12];
goto P_0c065b60;
P_0c065b60: /* original d335, guest PC 0x0c065b60 */
if(!s->budget--) { s->failed_pc=0x0c065b60u; return 0; }
r[3]=read(ram,0x0c065c38u,4);
goto P_0c065b62;
P_0c065b62: /* original 67a2, guest PC 0x0c065b62 */
if(!s->budget--) { s->failed_pc=0x0c065b62u; return 0; }
tmp=read(ram,r[10],4);
r[7]=tmp;
goto P_0c065b64;
P_0c065b64: /* original 2f72, guest PC 0x0c065b64 */
if(!s->budget--) { s->failed_pc=0x0c065b64u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065b66;
P_0c065b66: /* original 5775, guest PC 0x0c065b66 */
if(!s->budget--) { s->failed_pc=0x0c065b66u; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065b68;
P_0c065b68: /* original 66f2, guest PC 0x0c065b68 */
if(!s->budget--) { s->failed_pc=0x0c065b68u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065b6a;
P_0c065b6a: /* original 5664, guest PC 0x0c065b6a */
if(!s->budget--) { s->failed_pc=0x0c065b6au; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065b6c;
P_0c065b6c: /* original 430b, guest PC 0x0c065b6c */
if(!s->budget--) { s->failed_pc=0x0c065b6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c065b70u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065b70u) { target=s->pc; goto dispatch; }
goto P_0c065b70;
P_0c065b6e: /* original 64e3, guest PC 0x0c065b6e */
if(!s->budget--) { s->failed_pc=0x0c065b6eu; return 0; }
r[4]=r[14];
goto P_0c065b70;
P_0c065b70: /* original 63a2, guest PC 0x0c065b70 */
if(!s->budget--) { s->failed_pc=0x0c065b70u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c065b72;
P_0c065b72: /* original 6c03, guest PC 0x0c065b72 */
if(!s->budget--) { s->failed_pc=0x0c065b72u; return 0; }
r[12]=r[0];
goto P_0c065b74;
P_0c065b74: /* original 5136, guest PC 0x0c065b74 */
if(!s->budget--) { s->failed_pc=0x0c065b74u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065b76;
P_0c065b76: /* original 62c3, guest PC 0x0c065b76 */
if(!s->budget--) { s->failed_pc=0x0c065b76u; return 0; }
r[2]=r[12];
goto P_0c065b78;
P_0c065b78: /* original d029, guest PC 0x0c065b78 */
if(!s->budget--) { s->failed_pc=0x0c065b78u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b7a;
P_0c065b7a: /* original 7c01, guest PC 0x0c065b7a */
if(!s->budget--) { s->failed_pc=0x0c065b7au; return 0; }
r[12]+=0x00000001u;
goto P_0c065b7c;
P_0c065b7c: /* original 4208, guest PC 0x0c065b7c */
if(!s->budget--) { s->failed_pc=0x0c065b7cu; return 0; }
r[2]<<=2;
goto P_0c065b7e;
P_0c065b7e: /* original 0216, guest PC 0x0c065b7e */
if(!s->budget--) { s->failed_pc=0x0c065b7eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065b80;
P_0c065b80: /* original 66a2, guest PC 0x0c065b80 */
if(!s->budget--) { s->failed_pc=0x0c065b80u; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c065b82;
P_0c065b82: /* original 65c3, guest PC 0x0c065b82 */
if(!s->budget--) { s->failed_pc=0x0c065b82u; return 0; }
r[5]=r[12];
goto P_0c065b84;
P_0c065b84: /* original d32d, guest PC 0x0c065b84 */
if(!s->budget--) { s->failed_pc=0x0c065b84u; return 0; }
r[3]=read(ram,0x0c065c3cu,4);
goto P_0c065b86;
P_0c065b86: /* original 5667, guest PC 0x0c065b86 */
if(!s->budget--) { s->failed_pc=0x0c065b86u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065b88;
P_0c065b88: /* original 430b, guest PC 0x0c065b88 */
if(!s->budget--) { s->failed_pc=0x0c065b88u; return 0; }
target=r[3];
r[16]=code_base|0x0c065b8cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065b8cu) { target=s->pc; goto dispatch; }
goto P_0c065b8c;
P_0c065b8a: /* original 64e3, guest PC 0x0c065b8a */
if(!s->budget--) { s->failed_pc=0x0c065b8au; return 0; }
r[4]=r[14];
goto P_0c065b8c;
P_0c065b8c: /* original 61b2, guest PC 0x0c065b8c */
if(!s->budget--) { s->failed_pc=0x0c065b8cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065b8e;
P_0c065b8e: /* original 6c03, guest PC 0x0c065b8e */
if(!s->budget--) { s->failed_pc=0x0c065b8eu; return 0; }
r[12]=r[0];
goto P_0c065b90;
P_0c065b90: /* original 5311, guest PC 0x0c065b90 */
if(!s->budget--) { s->failed_pc=0x0c065b90u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c065b92;
P_0c065b92: /* original 62c3, guest PC 0x0c065b92 */
if(!s->budget--) { s->failed_pc=0x0c065b92u; return 0; }
r[2]=r[12];
goto P_0c065b94;
P_0c065b94: /* original d022, guest PC 0x0c065b94 */
if(!s->budget--) { s->failed_pc=0x0c065b94u; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065b96;
P_0c065b96: /* original 7c01, guest PC 0x0c065b96 */
if(!s->budget--) { s->failed_pc=0x0c065b96u; return 0; }
r[12]+=0x00000001u;
goto P_0c065b98;
P_0c065b98: /* original 4208, guest PC 0x0c065b98 */
if(!s->budget--) { s->failed_pc=0x0c065b98u; return 0; }
r[2]<<=2;
goto P_0c065b9a;
P_0c065b9a: /* original 0236, guest PC 0x0c065b9a */
if(!s->budget--) { s->failed_pc=0x0c065b9au; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065b9c;
P_0c065b9c: /* original 61b2, guest PC 0x0c065b9c */
if(!s->budget--) { s->failed_pc=0x0c065b9cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065b9e;
P_0c065b9e: /* original 62c3, guest PC 0x0c065b9e */
if(!s->budget--) { s->failed_pc=0x0c065b9eu; return 0; }
r[2]=r[12];
goto P_0c065ba0;
P_0c065ba0: /* original 5312, guest PC 0x0c065ba0 */
if(!s->budget--) { s->failed_pc=0x0c065ba0u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c065ba2;
P_0c065ba2: /* original 7c01, guest PC 0x0c065ba2 */
if(!s->budget--) { s->failed_pc=0x0c065ba2u; return 0; }
r[12]+=0x00000001u;
goto P_0c065ba4;
P_0c065ba4: /* original 4208, guest PC 0x0c065ba4 */
if(!s->budget--) { s->failed_pc=0x0c065ba4u; return 0; }
r[2]<<=2;
goto P_0c065ba6;
P_0c065ba6: /* original 0236, guest PC 0x0c065ba6 */
if(!s->budget--) { s->failed_pc=0x0c065ba6u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065ba8;
P_0c065ba8: /* original 61b2, guest PC 0x0c065ba8 */
if(!s->budget--) { s->failed_pc=0x0c065ba8u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c065baa;
P_0c065baa: /* original 62c3, guest PC 0x0c065baa */
if(!s->budget--) { s->failed_pc=0x0c065baau; return 0; }
r[2]=r[12];
goto P_0c065bac;
P_0c065bac: /* original 5313, guest PC 0x0c065bac */
if(!s->budget--) { s->failed_pc=0x0c065bacu; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c065bae;
P_0c065bae: /* original 7c01, guest PC 0x0c065bae */
if(!s->budget--) { s->failed_pc=0x0c065baeu; return 0; }
r[12]+=0x00000001u;
goto P_0c065bb0;
P_0c065bb0: /* original 4208, guest PC 0x0c065bb0 */
if(!s->budget--) { s->failed_pc=0x0c065bb0u; return 0; }
r[2]<<=2;
goto P_0c065bb2;
P_0c065bb2: /* original 0236, guest PC 0x0c065bb2 */
if(!s->budget--) { s->failed_pc=0x0c065bb2u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c065bb4;
P_0c065bb4: /* original 67b2, guest PC 0x0c065bb4 */
if(!s->budget--) { s->failed_pc=0x0c065bb4u; return 0; }
tmp=read(ram,r[11],4);
r[7]=tmp;
goto P_0c065bb6;
P_0c065bb6: /* original 65c3, guest PC 0x0c065bb6 */
if(!s->budget--) { s->failed_pc=0x0c065bb6u; return 0; }
r[5]=r[12];
goto P_0c065bb8;
P_0c065bb8: /* original d31f, guest PC 0x0c065bb8 */
if(!s->budget--) { s->failed_pc=0x0c065bb8u; return 0; }
r[3]=read(ram,0x0c065c38u,4);
goto P_0c065bba;
P_0c065bba: /* original 2f72, guest PC 0x0c065bba */
if(!s->budget--) { s->failed_pc=0x0c065bbau; return 0; }
write(ram,r[15],r[7],4);
goto P_0c065bbc;
P_0c065bbc: /* original 5775, guest PC 0x0c065bbc */
if(!s->budget--) { s->failed_pc=0x0c065bbcu; return 0; }
r[7]=read(ram,r[7]+20,4);
goto P_0c065bbe;
P_0c065bbe: /* original 66f2, guest PC 0x0c065bbe */
if(!s->budget--) { s->failed_pc=0x0c065bbeu; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c065bc0;
P_0c065bc0: /* original 5664, guest PC 0x0c065bc0 */
if(!s->budget--) { s->failed_pc=0x0c065bc0u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c065bc2;
P_0c065bc2: /* original 430b, guest PC 0x0c065bc2 */
if(!s->budget--) { s->failed_pc=0x0c065bc2u; return 0; }
target=r[3];
r[16]=code_base|0x0c065bc6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065bc6u) { target=s->pc; goto dispatch; }
goto P_0c065bc6;
P_0c065bc4: /* original 64e3, guest PC 0x0c065bc4 */
if(!s->budget--) { s->failed_pc=0x0c065bc4u; return 0; }
r[4]=r[14];
goto P_0c065bc6;
P_0c065bc6: /* original 6c03, guest PC 0x0c065bc6 */
if(!s->budget--) { s->failed_pc=0x0c065bc6u; return 0; }
r[12]=r[0];
goto P_0c065bc8;
P_0c065bc8: /* original 63b2, guest PC 0x0c065bc8 */
if(!s->budget--) { s->failed_pc=0x0c065bc8u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c065bca;
P_0c065bca: /* original 62c3, guest PC 0x0c065bca */
if(!s->budget--) { s->failed_pc=0x0c065bcau; return 0; }
r[2]=r[12];
goto P_0c065bcc;
P_0c065bcc: /* original d014, guest PC 0x0c065bcc */
if(!s->budget--) { s->failed_pc=0x0c065bccu; return 0; }
r[0]=read(ram,0x0c065c20u,4);
goto P_0c065bce;
P_0c065bce: /* original 7c01, guest PC 0x0c065bce */
if(!s->budget--) { s->failed_pc=0x0c065bceu; return 0; }
r[12]+=0x00000001u;
goto P_0c065bd0;
P_0c065bd0: /* original 5136, guest PC 0x0c065bd0 */
if(!s->budget--) { s->failed_pc=0x0c065bd0u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c065bd2;
P_0c065bd2: /* original 4208, guest PC 0x0c065bd2 */
if(!s->budget--) { s->failed_pc=0x0c065bd2u; return 0; }
r[2]<<=2;
goto P_0c065bd4;
P_0c065bd4: /* original 0216, guest PC 0x0c065bd4 */
if(!s->budget--) { s->failed_pc=0x0c065bd4u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c065bd6;
P_0c065bd6: /* original 65c3, guest PC 0x0c065bd6 */
if(!s->budget--) { s->failed_pc=0x0c065bd6u; return 0; }
r[5]=r[12];
goto P_0c065bd8;
P_0c065bd8: /* original d318, guest PC 0x0c065bd8 */
if(!s->budget--) { s->failed_pc=0x0c065bd8u; return 0; }
r[3]=read(ram,0x0c065c3cu,4);
goto P_0c065bda;
P_0c065bda: /* original 66b2, guest PC 0x0c065bda */
if(!s->budget--) { s->failed_pc=0x0c065bdau; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c065bdc;
P_0c065bdc: /* original 5667, guest PC 0x0c065bdc */
if(!s->budget--) { s->failed_pc=0x0c065bdcu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c065bde;
P_0c065bde: /* original 430b, guest PC 0x0c065bde */
if(!s->budget--) { s->failed_pc=0x0c065bdeu; return 0; }
target=r[3];
r[16]=code_base|0x0c065be2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065be2u) { target=s->pc; goto dispatch; }
goto P_0c065be2;
P_0c065be0: /* original 64e3, guest PC 0x0c065be0 */
if(!s->budget--) { s->failed_pc=0x0c065be0u; return 0; }
r[4]=r[14];
goto P_0c065be2;
P_0c065be2: /* original 6403, guest PC 0x0c065be2 */
if(!s->budget--) { s->failed_pc=0x0c065be2u; return 0; }
r[4]=r[0];
goto P_0c065be4;
P_0c065be4: /* original d210, guest PC 0x0c065be4 */
if(!s->budget--) { s->failed_pc=0x0c065be4u; return 0; }
r[2]=read(ram,0x0c065c28u,4);
goto P_0c065be6;
P_0c065be6: /* original 4408, guest PC 0x0c065be6 */
if(!s->budget--) { s->failed_pc=0x0c065be6u; return 0; }
r[4]<<=2;
goto P_0c065be8;
P_0c065be8: /* original 2242, guest PC 0x0c065be8 */
if(!s->budget--) { s->failed_pc=0x0c065be8u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c065bea;
P_0c065bea: /* original d310, guest PC 0x0c065bea */
if(!s->budget--) { s->failed_pc=0x0c065beau; return 0; }
r[3]=read(ram,0x0c065c2cu,4);
goto P_0c065bec;
P_0c065bec: /* original 430b, guest PC 0x0c065bec */
if(!s->budget--) { s->failed_pc=0x0c065becu; return 0; }
target=r[3];
r[16]=code_base|0x0c065bf0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065bf0u) { target=s->pc; goto dispatch; }
goto P_0c065bf0;
P_0c065bee: /* original 64e3, guest PC 0x0c065bee */
if(!s->budget--) { s->failed_pc=0x0c065beeu; return 0; }
r[4]=r[14];
goto P_0c065bf0;
P_0c065bf0: /* original d20f, guest PC 0x0c065bf0 */
if(!s->budget--) { s->failed_pc=0x0c065bf0u; return 0; }
r[2]=read(ram,0x0c065c30u,4);
goto P_0c065bf2;
P_0c065bf2: /* original 6403, guest PC 0x0c065bf2 */
if(!s->budget--) { s->failed_pc=0x0c065bf2u; return 0; }
r[4]=r[0];
goto P_0c065bf4;
P_0c065bf4: /* original e500, guest PC 0x0c065bf4 */
if(!s->budget--) { s->failed_pc=0x0c065bf4u; return 0; }
r[5]=0x00000000u;
goto P_0c065bf6;
P_0c065bf6: /* original 420b, guest PC 0x0c065bf6 */
if(!s->budget--) { s->failed_pc=0x0c065bf6u; return 0; }
target=r[2];
r[16]=code_base|0x0c065bfau;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c065bfau) { target=s->pc; goto dispatch; }
goto P_0c065bfa;
P_0c065bf8: /* original 6653, guest PC 0x0c065bf8 */
if(!s->budget--) { s->failed_pc=0x0c065bf8u; return 0; }
r[6]=r[5];
goto P_0c065bfa;
P_0c065bfa: /* original 62d2, guest PC 0x0c065bfa */
if(!s->budget--) { s->failed_pc=0x0c065bfau; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c065bfc;
P_0c065bfc: /* original d10d, guest PC 0x0c065bfc */
if(!s->budget--) { s->failed_pc=0x0c065bfcu; return 0; }
r[1]=read(ram,0x0c065c34u,4);
goto P_0c065bfe;
P_0c065bfe: /* original 5323, guest PC 0x0c065bfe */
if(!s->budget--) { s->failed_pc=0x0c065bfeu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c065c00;
P_0c065c00: /* original 2132, guest PC 0x0c065c00 */
if(!s->budget--) { s->failed_pc=0x0c065c00u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c065c02;
P_0c065c02: /* original e000, guest PC 0x0c065c02 */
if(!s->budget--) { s->failed_pc=0x0c065c02u; return 0; }
r[0]=0x00000000u;
goto P_0c065c04;
P_0c065c04: /* original 7f10, guest PC 0x0c065c04 */
if(!s->budget--) { s->failed_pc=0x0c065c04u; return 0; }
r[15]+=0x00000010u;
goto P_0c065c06;
P_0c065c06: /* original 4f26, guest PC 0x0c065c06 */
if(!s->budget--) { s->failed_pc=0x0c065c06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c065c08;
P_0c065c08: /* original 6af6, guest PC 0x0c065c08 */
if(!s->budget--) { s->failed_pc=0x0c065c08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c065c0a;
P_0c065c0a: /* original 6bf6, guest PC 0x0c065c0a */
if(!s->budget--) { s->failed_pc=0x0c065c0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c065c0c;
P_0c065c0c: /* original 6cf6, guest PC 0x0c065c0c */
if(!s->budget--) { s->failed_pc=0x0c065c0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c065c0e;
P_0c065c0e: /* original 6df6, guest PC 0x0c065c0e */
if(!s->budget--) { s->failed_pc=0x0c065c0eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c065c10;
P_0c065c10: /* original 000b, guest PC 0x0c065c10 */
if(!s->budget--) { s->failed_pc=0x0c065c10u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c065c12: /* original 6ef6, guest PC 0x0c065c12 */
if(!s->budget--) { s->failed_pc=0x0c065c12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c065c14u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c065c14u; return 0; } return 1;
P_0c06629c: /* original d540, guest PC 0x0c06629c */
if(!s->budget--) { s->failed_pc=0x0c06629cu; return 0; }
r[5]=read(ram,0x0c0663a0u,4);
goto P_0c06629e;
P_0c06629e: /* original d341, guest PC 0x0c06629e */
if(!s->budget--) { s->failed_pc=0x0c06629eu; return 0; }
r[3]=read(ram,0x0c0663a4u,4);
goto P_0c0662a0;
P_0c0662a0: /* original 6032, guest PC 0x0c0662a0 */
if(!s->budget--) { s->failed_pc=0x0c0662a0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0662a2;
P_0c0662a2: /* original 4008, guest PC 0x0c0662a2 */
if(!s->budget--) { s->failed_pc=0x0c0662a2u; return 0; }
r[0]<<=2;
goto P_0c0662a4;
P_0c0662a4: /* original 025e, guest PC 0x0c0662a4 */
if(!s->budget--) { s->failed_pc=0x0c0662a4u; return 0; }
r[2]=read(ram,r[5]+r[0],4);
goto P_0c0662a6;
P_0c0662a6: /* original d140, guest PC 0x0c0662a6 */
if(!s->budget--) { s->failed_pc=0x0c0662a6u; return 0; }
r[1]=read(ram,0x0c0663a8u,4);
goto P_0c0662a8;
P_0c0662a8: /* original 6012, guest PC 0x0c0662a8 */
if(!s->budget--) { s->failed_pc=0x0c0662a8u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c0662aa;
P_0c0662aa: /* original 4008, guest PC 0x0c0662aa */
if(!s->budget--) { s->failed_pc=0x0c0662aau; return 0; }
r[0]<<=2;
goto P_0c0662ac;
P_0c0662ac: /* original 005e, guest PC 0x0c0662ac */
if(!s->budget--) { s->failed_pc=0x0c0662acu; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662ae;
P_0c0662ae: /* original 7308, guest PC 0x0c0662ae */
if(!s->budget--) { s->failed_pc=0x0c0662aeu; return 0; }
r[3]+=0x00000008u;
goto P_0c0662b0;
P_0c0662b0: /* original 320c, guest PC 0x0c0662b0 */
if(!s->budget--) { s->failed_pc=0x0c0662b0u; return 0; }
r[2]+=r[0];
goto P_0c0662b2;
P_0c0662b2: /* original 6032, guest PC 0x0c0662b2 */
if(!s->budget--) { s->failed_pc=0x0c0662b2u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0662b4;
P_0c0662b4: /* original 4008, guest PC 0x0c0662b4 */
if(!s->budget--) { s->failed_pc=0x0c0662b4u; return 0; }
r[0]<<=2;
goto P_0c0662b6;
P_0c0662b6: /* original 7304, guest PC 0x0c0662b6 */
if(!s->budget--) { s->failed_pc=0x0c0662b6u; return 0; }
r[3]+=0x00000004u;
goto P_0c0662b8;
P_0c0662b8: /* original 005e, guest PC 0x0c0662b8 */
if(!s->budget--) { s->failed_pc=0x0c0662b8u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662ba;
P_0c0662ba: /* original 320c, guest PC 0x0c0662ba */
if(!s->budget--) { s->failed_pc=0x0c0662bau; return 0; }
r[2]+=r[0];
goto P_0c0662bc;
P_0c0662bc: /* original 6032, guest PC 0x0c0662bc */
if(!s->budget--) { s->failed_pc=0x0c0662bcu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c0662be;
P_0c0662be: /* original 4008, guest PC 0x0c0662be */
if(!s->budget--) { s->failed_pc=0x0c0662beu; return 0; }
r[0]<<=2;
goto P_0c0662c0;
P_0c0662c0: /* original 005e, guest PC 0x0c0662c0 */
if(!s->budget--) { s->failed_pc=0x0c0662c0u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662c2;
P_0c0662c2: /* original 320c, guest PC 0x0c0662c2 */
if(!s->budget--) { s->failed_pc=0x0c0662c2u; return 0; }
r[2]+=r[0];
goto P_0c0662c4;
P_0c0662c4: /* original 5031, guest PC 0x0c0662c4 */
if(!s->budget--) { s->failed_pc=0x0c0662c4u; return 0; }
r[0]=read(ram,r[3]+4,4);
goto P_0c0662c6;
P_0c0662c6: /* original 4008, guest PC 0x0c0662c6 */
if(!s->budget--) { s->failed_pc=0x0c0662c6u; return 0; }
r[0]<<=2;
goto P_0c0662c8;
P_0c0662c8: /* original 005e, guest PC 0x0c0662c8 */
if(!s->budget--) { s->failed_pc=0x0c0662c8u; return 0; }
r[0]=read(ram,r[5]+r[0],4);
goto P_0c0662ca;
P_0c0662ca: /* original 320c, guest PC 0x0c0662ca */
if(!s->budget--) { s->failed_pc=0x0c0662cau; return 0; }
r[2]+=r[0];
goto P_0c0662cc;
P_0c0662cc: /* original 0247, guest PC 0x0c0662cc */
if(!s->budget--) { s->failed_pc=0x0c0662ccu; return 0; }
r[19]=r[2]*r[4];
goto P_0c0662ce;
P_0c0662ce: /* original 021a, guest PC 0x0c0662ce */
if(!s->budget--) { s->failed_pc=0x0c0662ceu; return 0; }
r[2]=r[19];
goto P_0c0662d0;
P_0c0662d0: /* original 6423, guest PC 0x0c0662d0 */
if(!s->budget--) { s->failed_pc=0x0c0662d0u; return 0; }
r[4]=r[2];
goto P_0c0662d2;
P_0c0662d2: /* original 4408, guest PC 0x0c0662d2 */
if(!s->budget--) { s->failed_pc=0x0c0662d2u; return 0; }
r[4]<<=2;
goto P_0c0662d4;
P_0c0662d4: /* original 000b, guest PC 0x0c0662d4 */
if(!s->budget--) { s->failed_pc=0x0c0662d4u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c0662d6: /* original 6043, guest PC 0x0c0662d6 */
if(!s->budget--) { s->failed_pc=0x0c0662d6u; return 0; }
r[0]=r[4];
return vf3_matrix_family(0x0c0662d8u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
