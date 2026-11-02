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
int vf3_away_batch14_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0879dau: goto P_0c0879da;
case 0x0c0879dcu: goto P_0c0879dc;
case 0x0c0879deu: goto P_0c0879de;
case 0x0c0879e0u: goto P_0c0879e0;
case 0x0c0879e2u: goto P_0c0879e2;
case 0x0c0879e4u: goto P_0c0879e4;
case 0x0c0879e6u: goto P_0c0879e6;
case 0x0c0879e8u: goto P_0c0879e8;
case 0x0c0879eau: goto P_0c0879ea;
case 0x0c0879ecu: goto P_0c0879ec;
case 0x0c0879eeu: goto P_0c0879ee;
case 0x0c0879f0u: goto P_0c0879f0;
case 0x0c0879f2u: goto P_0c0879f2;
case 0x0c0879f4u: goto P_0c0879f4;
case 0x0c0879f6u: goto P_0c0879f6;
case 0x0c0879f8u: goto P_0c0879f8;
case 0x0c0879fau: goto P_0c0879fa;
case 0x0c0879fcu: goto P_0c0879fc;
case 0x0c0879feu: goto P_0c0879fe;
case 0x0c087a00u: goto P_0c087a00;
case 0x0c087a02u: goto P_0c087a02;
case 0x0c087a04u: goto P_0c087a04;
case 0x0c087a06u: goto P_0c087a06;
case 0x0c087a08u: goto P_0c087a08;
case 0x0c087a0au: goto P_0c087a0a;
case 0x0c087a0cu: goto P_0c087a0c;
case 0x0c087a0eu: goto P_0c087a0e;
case 0x0c087a10u: goto P_0c087a10;
case 0x0c087a12u: goto P_0c087a12;
case 0x0c087a14u: goto P_0c087a14;
case 0x0c087a16u: goto P_0c087a16;
case 0x0c087a18u: goto P_0c087a18;
case 0x0c087a1au: goto P_0c087a1a;
case 0x0c087a1cu: goto P_0c087a1c;
case 0x0c087a1eu: goto P_0c087a1e;
case 0x0c087a20u: goto P_0c087a20;
case 0x0c087a22u: goto P_0c087a22;
case 0x0c087a40u: goto P_0c087a40;
case 0x0c087a42u: goto P_0c087a42;
case 0x0c087a44u: goto P_0c087a44;
case 0x0c087a46u: goto P_0c087a46;
case 0x0c087a48u: goto P_0c087a48;
case 0x0c087a4au: goto P_0c087a4a;
case 0x0c087a4cu: goto P_0c087a4c;
case 0x0c087a4eu: goto P_0c087a4e;
case 0x0c087a50u: goto P_0c087a50;
case 0x0c087a52u: goto P_0c087a52;
case 0x0c087a54u: goto P_0c087a54;
case 0x0c087a56u: goto P_0c087a56;
case 0x0c087a58u: goto P_0c087a58;
case 0x0c087a5au: goto P_0c087a5a;
case 0x0c087a5cu: goto P_0c087a5c;
case 0x0c087a5eu: goto P_0c087a5e;
case 0x0c087a60u: goto P_0c087a60;
case 0x0c087a62u: goto P_0c087a62;
case 0x0c087a64u: goto P_0c087a64;
case 0x0c087a66u: goto P_0c087a66;
case 0x0c087a68u: goto P_0c087a68;
case 0x0c087a6au: goto P_0c087a6a;
case 0x0c087a6cu: goto P_0c087a6c;
case 0x0c087a6eu: goto P_0c087a6e;
case 0x0c087a70u: goto P_0c087a70;
case 0x0c087a72u: goto P_0c087a72;
case 0x0c087a74u: goto P_0c087a74;
case 0x0c087a76u: goto P_0c087a76;
case 0x0c087a78u: goto P_0c087a78;
case 0x0c087a7au: goto P_0c087a7a;
case 0x0c087a7cu: goto P_0c087a7c;
case 0x0c087a7eu: goto P_0c087a7e;
case 0x0c087a80u: goto P_0c087a80;
case 0x0c087a82u: goto P_0c087a82;
case 0x0c087a84u: goto P_0c087a84;
case 0x0c087a86u: goto P_0c087a86;
case 0x0c087a88u: goto P_0c087a88;
case 0x0c087a8au: goto P_0c087a8a;
case 0x0c087a8cu: goto P_0c087a8c;
case 0x0c087a8eu: goto P_0c087a8e;
case 0x0c087a90u: goto P_0c087a90;
case 0x0c087a92u: goto P_0c087a92;
case 0x0c087a94u: goto P_0c087a94;
case 0x0c087a96u: goto P_0c087a96;
case 0x0c087a98u: goto P_0c087a98;
case 0x0c087a9au: goto P_0c087a9a;
case 0x0c087a9cu: goto P_0c087a9c;
case 0x0c087a9eu: goto P_0c087a9e;
case 0x0c087aa0u: goto P_0c087aa0;
case 0x0c087aa2u: goto P_0c087aa2;
case 0x0c087aa4u: goto P_0c087aa4;
case 0x0c087aa6u: goto P_0c087aa6;
case 0x0c087aa8u: goto P_0c087aa8;
case 0x0c087aaau: goto P_0c087aaa;
case 0x0c087aacu: goto P_0c087aac;
case 0x0c087aaeu: goto P_0c087aae;
case 0x0c087ab0u: goto P_0c087ab0;
case 0x0c087ab2u: goto P_0c087ab2;
case 0x0c087ab4u: goto P_0c087ab4;
case 0x0c087ab6u: goto P_0c087ab6;
case 0x0c087ab8u: goto P_0c087ab8;
case 0x0c087abau: goto P_0c087aba;
case 0x0c087abcu: goto P_0c087abc;
case 0x0c087abeu: goto P_0c087abe;
case 0x0c087ac0u: goto P_0c087ac0;
case 0x0c087ac2u: goto P_0c087ac2;
case 0x0c087ac4u: goto P_0c087ac4;
case 0x0c087ac6u: goto P_0c087ac6;
case 0x0c087ac8u: goto P_0c087ac8;
case 0x0c087acau: goto P_0c087aca;
case 0x0c087accu: goto P_0c087acc;
case 0x0c087aceu: goto P_0c087ace;
case 0x0c087ad0u: goto P_0c087ad0;
case 0x0c087ad2u: goto P_0c087ad2;
case 0x0c087ad4u: goto P_0c087ad4;
case 0x0c087ad6u: goto P_0c087ad6;
case 0x0c087ad8u: goto P_0c087ad8;
case 0x0c087adau: goto P_0c087ada;
case 0x0c087adcu: goto P_0c087adc;
case 0x0c087adeu: goto P_0c087ade;
case 0x0c087ae0u: goto P_0c087ae0;
case 0x0c087ae2u: goto P_0c087ae2;
case 0x0c087ae4u: goto P_0c087ae4;
case 0x0c087ae6u: goto P_0c087ae6;
case 0x0c087ae8u: goto P_0c087ae8;
case 0x0c087aeau: goto P_0c087aea;
case 0x0c087aecu: goto P_0c087aec;
case 0x0c087aeeu: goto P_0c087aee;
case 0x0c087af0u: goto P_0c087af0;
case 0x0c087af2u: goto P_0c087af2;
case 0x0c087af4u: goto P_0c087af4;
case 0x0c087af6u: goto P_0c087af6;
case 0x0c087af8u: goto P_0c087af8;
case 0x0c087afau: goto P_0c087afa;
case 0x0c087afcu: goto P_0c087afc;
case 0x0c087afeu: goto P_0c087afe;
case 0x0c087b00u: goto P_0c087b00;
case 0x0c087b02u: goto P_0c087b02;
case 0x0c087b04u: goto P_0c087b04;
case 0x0c087b06u: goto P_0c087b06;
case 0x0c087b08u: goto P_0c087b08;
case 0x0c087b0au: goto P_0c087b0a;
case 0x0c087b0cu: goto P_0c087b0c;
case 0x0c087b0eu: goto P_0c087b0e;
case 0x0c087b10u: goto P_0c087b10;
case 0x0c087b12u: goto P_0c087b12;
case 0x0c087b14u: goto P_0c087b14;
case 0x0c087b16u: goto P_0c087b16;
case 0x0c087b18u: goto P_0c087b18;
case 0x0c087b1au: goto P_0c087b1a;
case 0x0c087b1cu: goto P_0c087b1c;
case 0x0c087b1eu: goto P_0c087b1e;
case 0x0c087b20u: goto P_0c087b20;
case 0x0c087b22u: goto P_0c087b22;
case 0x0c087b24u: goto P_0c087b24;
case 0x0c087b26u: goto P_0c087b26;
case 0x0c087b28u: goto P_0c087b28;
case 0x0c087b2au: goto P_0c087b2a;
case 0x0c087b2cu: goto P_0c087b2c;
case 0x0c087b2eu: goto P_0c087b2e;
case 0x0c087b30u: goto P_0c087b30;
case 0x0c087b32u: goto P_0c087b32;
case 0x0c087b34u: goto P_0c087b34;
case 0x0c087b36u: goto P_0c087b36;
case 0x0c087b38u: goto P_0c087b38;
case 0x0c087b3au: goto P_0c087b3a;
case 0x0c087b3cu: goto P_0c087b3c;
case 0x0c087b3eu: goto P_0c087b3e;
case 0x0c087b40u: goto P_0c087b40;
case 0x0c087b42u: goto P_0c087b42;
case 0x0c087b44u: goto P_0c087b44;
case 0x0c087b46u: goto P_0c087b46;
case 0x0c087b48u: goto P_0c087b48;
case 0x0c087b4au: goto P_0c087b4a;
case 0x0c087b4cu: goto P_0c087b4c;
case 0x0c087b4eu: goto P_0c087b4e;
case 0x0c087b50u: goto P_0c087b50;
case 0x0c087b52u: goto P_0c087b52;
case 0x0c087b54u: goto P_0c087b54;
case 0x0c087b80u: goto P_0c087b80;
case 0x0c087b82u: goto P_0c087b82;
case 0x0c087b84u: goto P_0c087b84;
case 0x0c087b86u: goto P_0c087b86;
case 0x0c087b88u: goto P_0c087b88;
case 0x0c087b8au: goto P_0c087b8a;
case 0x0c087b8cu: goto P_0c087b8c;
case 0x0c087b8eu: goto P_0c087b8e;
case 0x0c087b90u: goto P_0c087b90;
case 0x0c087b92u: goto P_0c087b92;
case 0x0c087b94u: goto P_0c087b94;
case 0x0c087b96u: goto P_0c087b96;
case 0x0c087b98u: goto P_0c087b98;
case 0x0c087b9au: goto P_0c087b9a;
case 0x0c087b9cu: goto P_0c087b9c;
case 0x0c087b9eu: goto P_0c087b9e;
case 0x0c087ba0u: goto P_0c087ba0;
case 0x0c087ba2u: goto P_0c087ba2;
case 0x0c087ba4u: goto P_0c087ba4;
case 0x0c087ba6u: goto P_0c087ba6;
case 0x0c087ba8u: goto P_0c087ba8;
case 0x0c087baau: goto P_0c087baa;
case 0x0c087bacu: goto P_0c087bac;
case 0x0c087baeu: goto P_0c087bae;
case 0x0c087bb0u: goto P_0c087bb0;
case 0x0c087bb2u: goto P_0c087bb2;
case 0x0c087bb4u: goto P_0c087bb4;
case 0x0c087bb6u: goto P_0c087bb6;
case 0x0c087bb8u: goto P_0c087bb8;
case 0x0c087bbau: goto P_0c087bba;
case 0x0c087bbcu: goto P_0c087bbc;
case 0x0c087bbeu: goto P_0c087bbe;
case 0x0c087bc0u: goto P_0c087bc0;
case 0x0c087bc2u: goto P_0c087bc2;
case 0x0c087bc4u: goto P_0c087bc4;
case 0x0c087bc6u: goto P_0c087bc6;
case 0x0c087bc8u: goto P_0c087bc8;
case 0x0c087bcau: goto P_0c087bca;
case 0x0c087bccu: goto P_0c087bcc;
case 0x0c087bceu: goto P_0c087bce;
case 0x0c087bd0u: goto P_0c087bd0;
case 0x0c087bd2u: goto P_0c087bd2;
case 0x0c087bd4u: goto P_0c087bd4;
case 0x0c087bd6u: goto P_0c087bd6;
case 0x0c087bd8u: goto P_0c087bd8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0879da: /* original 4f22, guest PC 0x0c0879da */
if(!s->budget--) { s->failed_pc=0x0c0879dau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0879dc;
P_0c0879dc: /* original 9024, guest PC 0x0c0879dc */
if(!s->budget--) { s->failed_pc=0x0c0879dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a28u,2);
goto P_0c0879de;
P_0c0879de: /* original 4f12, guest PC 0x0c0879de */
if(!s->budget--) { s->failed_pc=0x0c0879deu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0879e0;
P_0c0879e0: /* original f346, guest PC 0x0c0879e0 */
if(!s->budget--) { s->failed_pc=0x0c0879e0u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0879e2;
P_0c0879e2: /* original e008, guest PC 0x0c0879e2 */
if(!s->budget--) { s->failed_pc=0x0c0879e2u; return 0; }
r[0]=0x00000008u;
goto P_0c0879e4;
P_0c0879e4: /* original 7ff4, guest PC 0x0c0879e4 */
if(!s->budget--) { s->failed_pc=0x0c0879e4u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0879e6;
P_0c0879e6: /* original ff37, guest PC 0x0c0879e6 */
if(!s->budget--) { s->failed_pc=0x0c0879e6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0879e8;
P_0c0879e8: /* original 901f, guest PC 0x0c0879e8 */
if(!s->budget--) { s->failed_pc=0x0c0879e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a2au,2);
goto P_0c0879ea;
P_0c0879ea: /* original f346, guest PC 0x0c0879ea */
if(!s->budget--) { s->failed_pc=0x0c0879eau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0879ec;
P_0c0879ec: /* original ff3a, guest PC 0x0c0879ec */
if(!s->budget--) { s->failed_pc=0x0c0879ecu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0879ee;
P_0c0879ee: /* original 901d, guest PC 0x0c0879ee */
if(!s->budget--) { s->failed_pc=0x0c0879eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087a2cu,2);
goto P_0c0879f0;
P_0c0879f0: /* original 054e, guest PC 0x0c0879f0 */
if(!s->budget--) { s->failed_pc=0x0c0879f0u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0879f2;
P_0c0879f2: /* original 7008, guest PC 0x0c0879f2 */
if(!s->budget--) { s->failed_pc=0x0c0879f2u; return 0; }
r[0]+=0x00000008u;
goto P_0c0879f4;
P_0c0879f4: /* original 044e, guest PC 0x0c0879f4 */
if(!s->budget--) { s->failed_pc=0x0c0879f4u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c0879f6;
P_0c0879f6: /* original c710, guest PC 0x0c0879f6 */
if(!s->budget--) { s->failed_pc=0x0c0879f6u; return 0; }
r[0]=code_base|0x00087a38u;
goto P_0c0879f8;
P_0c0879f8: /* original f308, guest PC 0x0c0879f8 */
if(!s->budget--) { s->failed_pc=0x0c0879f8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0879fa;
P_0c0879fa: /* original f432, guest PC 0x0c0879fa */
if(!s->budget--) { s->failed_pc=0x0c0879fau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0879fc;
P_0c0879fc: /* original f43d, guest PC 0x0c0879fc */
if(!s->budget--) { s->failed_pc=0x0c0879fcu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0879fe;
P_0c0879fe: /* original 065a, guest PC 0x0c0879fe */
if(!s->budget--) { s->failed_pc=0x0c0879feu; return 0; }
r[6]=r[53];
goto P_0c087a00;
P_0c087a00: /* original 346c, guest PC 0x0c087a00 */
if(!s->budget--) { s->failed_pc=0x0c087a00u; return 0; }
r[4]+=r[6];
goto P_0c087a02;
P_0c087a02: /* original 0547, guest PC 0x0c087a02 */
if(!s->budget--) { s->failed_pc=0x0c087a02u; return 0; }
r[19]=r[5]*r[4];
goto P_0c087a04;
P_0c087a04: /* original 041a, guest PC 0x0c087a04 */
if(!s->budget--) { s->failed_pc=0x0c087a04u; return 0; }
r[4]=r[19];
goto P_0c087a06;
P_0c087a06: /* original 644d, guest PC 0x0c087a06 */
if(!s->budget--) { s->failed_pc=0x0c087a06u; return 0; }
r[4]=r[4]&65535u;
goto P_0c087a08;
P_0c087a08: /* original 1f41, guest PC 0x0c087a08 */
if(!s->budget--) { s->failed_pc=0x0c087a08u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c087a0a;
P_0c087a0a: /* original d30c, guest PC 0x0c087a0a */
if(!s->budget--) { s->failed_pc=0x0c087a0au; return 0; }
r[3]=read(ram,0x0c087a3cu,4);
goto P_0c087a0c;
P_0c087a0c: /* original 430b, guest PC 0x0c087a0c */
if(!s->budget--) { s->failed_pc=0x0c087a0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c087a10u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087a10u) { target=s->pc; goto dispatch; }
goto P_0c087a10;
P_0c087a0e: /* original 644f, guest PC 0x0c087a0e */
if(!s->budget--) { s->failed_pc=0x0c087a0eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c087a10;
P_0c087a10: /* original e008, guest PC 0x0c087a10 */
if(!s->budget--) { s->failed_pc=0x0c087a10u; return 0; }
r[0]=0x00000008u;
goto P_0c087a12;
P_0c087a12: /* original f2f8, guest PC 0x0c087a12 */
if(!s->budget--) { s->failed_pc=0x0c087a12u; return 0; }
vf3_matrix_load(s,ram,2,r[15]);
goto P_0c087a14;
P_0c087a14: /* original f3f6, guest PC 0x0c087a14 */
if(!s->budget--) { s->failed_pc=0x0c087a14u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c087a16;
P_0c087a16: /* original 7f0c, guest PC 0x0c087a16 */
if(!s->budget--) { s->failed_pc=0x0c087a16u; return 0; }
r[15]+=0x0000000cu;
goto P_0c087a18;
P_0c087a18: /* original 4f16, guest PC 0x0c087a18 */
if(!s->budget--) { s->failed_pc=0x0c087a18u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c087a1a;
P_0c087a1a: /* original f32e, guest PC 0x0c087a1a */
if(!s->budget--) { s->failed_pc=0x0c087a1au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c087a1c;
P_0c087a1c: /* original 4f26, guest PC 0x0c087a1c */
if(!s->budget--) { s->failed_pc=0x0c087a1cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087a1e;
P_0c087a1e: /* original f03c, guest PC 0x0c087a1e */
if(!s->budget--) { s->failed_pc=0x0c087a1eu; return 0; }
vf3_matrix_move(s,0,3);
goto P_0c087a20;
P_0c087a20: /* original 000b, guest PC 0x0c087a20 */
if(!s->budget--) { s->failed_pc=0x0c087a20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087a22: /* original 0009, guest PC 0x0c087a22 */
if(!s->budget--) { s->failed_pc=0x0c087a22u; return 0; }
if(!vf3_matrix_family(0x0c087a24u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087a24u; return 0; } return 1;
P_0c087a40: /* original d347, guest PC 0x0c087a40 */
if(!s->budget--) { s->failed_pc=0x0c087a40u; return 0; }
r[3]=read(ram,0x0c087b60u,4);
goto P_0c087a42;
P_0c087a42: /* original 9088, guest PC 0x0c087a42 */
if(!s->budget--) { s->failed_pc=0x0c087a42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b56u,2);
goto P_0c087a44;
P_0c087a44: /* original 6432, guest PC 0x0c087a44 */
if(!s->budget--) { s->failed_pc=0x0c087a44u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c087a46;
P_0c087a46: /* original 044e, guest PC 0x0c087a46 */
if(!s->budget--) { s->failed_pc=0x0c087a46u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c087a48;
P_0c087a48: /* original 2448, guest PC 0x0c087a48 */
if(!s->budget--) { s->failed_pc=0x0c087a48u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087a4a;
P_0c087a4a: /* original 893d, guest PC 0x0c087a4a */
if(!s->budget--) { s->failed_pc=0x0c087a4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087ac8; }
goto P_0c087a4c;
P_0c087a4c: /* original c745, guest PC 0x0c087a4c */
if(!s->budget--) { s->failed_pc=0x0c087a4cu; return 0; }
r[0]=code_base|0x00087b64u;
goto P_0c087a4e;
P_0c087a4e: /* original 9383, guest PC 0x0c087a4e */
if(!s->budget--) { s->failed_pc=0x0c087a4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b58u,2);
goto P_0c087a50;
P_0c087a50: /* original f908, guest PC 0x0c087a50 */
if(!s->budget--) { s->failed_pc=0x0c087a50u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c087a52;
P_0c087a52: /* original c745, guest PC 0x0c087a52 */
if(!s->budget--) { s->failed_pc=0x0c087a52u; return 0; }
r[0]=code_base|0x00087b68u;
goto P_0c087a54;
P_0c087a54: /* original f808, guest PC 0x0c087a54 */
if(!s->budget--) { s->failed_pc=0x0c087a54u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c087a56;
P_0c087a56: /* original e608, guest PC 0x0c087a56 */
if(!s->budget--) { s->failed_pc=0x0c087a56u; return 0; }
r[6]=0x00000008u;
goto P_0c087a58;
P_0c087a58: /* original 343c, guest PC 0x0c087a58 */
if(!s->budget--) { s->failed_pc=0x0c087a58u; return 0; }
r[4]+=r[3];
goto P_0c087a5a;
P_0c087a5a: /* original e500, guest PC 0x0c087a5a */
if(!s->budget--) { s->failed_pc=0x0c087a5au; return 0; }
r[5]=0x00000000u;
goto P_0c087a5c;
P_0c087a5c: /* original 907d, guest PC 0x0c087a5c */
if(!s->budget--) { s->failed_pc=0x0c087a5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5au,2);
goto P_0c087a5e;
P_0c087a5e: /* original f69c, guest PC 0x0c087a5e */
if(!s->budget--) { s->failed_pc=0x0c087a5eu; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c087a60;
P_0c087a60: /* original f346, guest PC 0x0c087a60 */
if(!s->budget--) { s->failed_pc=0x0c087a60u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087a62;
P_0c087a62: /* original 7004, guest PC 0x0c087a62 */
if(!s->budget--) { s->failed_pc=0x0c087a62u; return 0; }
r[0]+=0x00000004u;
goto P_0c087a64;
P_0c087a64: /* original f746, guest PC 0x0c087a64 */
if(!s->budget--) { s->failed_pc=0x0c087a64u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c087a66;
P_0c087a66: /* original 7004, guest PC 0x0c087a66 */
if(!s->budget--) { s->failed_pc=0x0c087a66u; return 0; }
r[0]+=0x00000004u;
goto P_0c087a68;
P_0c087a68: /* original f632, guest PC 0x0c087a68 */
if(!s->budget--) { s->failed_pc=0x0c087a68u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c087a6a;
P_0c087a6a: /* original fa46, guest PC 0x0c087a6a */
if(!s->budget--) { s->failed_pc=0x0c087a6au; return 0; }
vf3_matrix_load(s,ram,10,r[4]+r[0]);
goto P_0c087a6c;
P_0c087a6c: /* original f37c, guest PC 0x0c087a6c */
if(!s->budget--) { s->failed_pc=0x0c087a6cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087a6e;
P_0c087a6e: /* original 7008, guest PC 0x0c087a6e */
if(!s->budget--) { s->failed_pc=0x0c087a6eu; return 0; }
r[0]+=0x00000008u;
goto P_0c087a70;
P_0c087a70: /* original f79c, guest PC 0x0c087a70 */
if(!s->budget--) { s->failed_pc=0x0c087a70u; return 0; }
vf3_matrix_move(s,7,9);
goto P_0c087a72;
P_0c087a72: /* original f732, guest PC 0x0c087a72 */
if(!s->budget--) { s->failed_pc=0x0c087a72u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c087a74;
P_0c087a74: /* original fb46, guest PC 0x0c087a74 */
if(!s->budget--) { s->failed_pc=0x0c087a74u; return 0; }
vf3_matrix_load(s,ram,11,r[4]+r[0]);
goto P_0c087a76;
P_0c087a76: /* original f16c, guest PC 0x0c087a76 */
if(!s->budget--) { s->failed_pc=0x0c087a76u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c087a78;
P_0c087a78: /* original f1a0, guest PC 0x0c087a78 */
if(!s->budget--) { s->failed_pc=0x0c087a78u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[10],r[18],'+');
goto P_0c087a7a;
P_0c087a7a: /* original f07c, guest PC 0x0c087a7a */
if(!s->budget--) { s->failed_pc=0x0c087a7au; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c087a7c;
P_0c087a7c: /* original f0b0, guest PC 0x0c087a7c */
if(!s->budget--) { s->failed_pc=0x0c087a7cu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[11],r[18],'+');
goto P_0c087a7e;
P_0c087a7e: /* original f31c, guest PC 0x0c087a7e */
if(!s->budget--) { s->failed_pc=0x0c087a7eu; return 0; }
vf3_matrix_move(s,3,1);
goto P_0c087a80;
P_0c087a80: /* original f14c, guest PC 0x0c087a80 */
if(!s->budget--) { s->failed_pc=0x0c087a80u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c087a82;
P_0c087a82: /* original f131, guest PC 0x0c087a82 */
if(!s->budget--) { s->failed_pc=0x0c087a82u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'-');
goto P_0c087a84;
P_0c087a84: /* original f30c, guest PC 0x0c087a84 */
if(!s->budget--) { s->failed_pc=0x0c087a84u; return 0; }
vf3_matrix_move(s,3,0);
goto P_0c087a86;
P_0c087a86: /* original f05c, guest PC 0x0c087a86 */
if(!s->budget--) { s->failed_pc=0x0c087a86u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c087a88;
P_0c087a88: /* original f031, guest PC 0x0c087a88 */
if(!s->budget--) { s->failed_pc=0x0c087a88u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'-');
goto P_0c087a8a;
P_0c087a8a: /* original f36c, guest PC 0x0c087a8a */
if(!s->budget--) { s->failed_pc=0x0c087a8au; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c087a8c;
P_0c087a8c: /* original f6ac, guest PC 0x0c087a8c */
if(!s->budget--) { s->failed_pc=0x0c087a8cu; return 0; }
vf3_matrix_move(s,6,10);
goto P_0c087a8e;
P_0c087a8e: /* original f631, guest PC 0x0c087a8e */
if(!s->budget--) { s->failed_pc=0x0c087a8eu; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c087a90;
P_0c087a90: /* original f37c, guest PC 0x0c087a90 */
if(!s->budget--) { s->failed_pc=0x0c087a90u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087a92;
P_0c087a92: /* original f7bc, guest PC 0x0c087a92 */
if(!s->budget--) { s->failed_pc=0x0c087a92u; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c087a94;
P_0c087a94: /* original f731, guest PC 0x0c087a94 */
if(!s->budget--) { s->failed_pc=0x0c087a94u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c087a96;
P_0c087a96: /* original f36c, guest PC 0x0c087a96 */
if(!s->budget--) { s->failed_pc=0x0c087a96u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c087a98;
P_0c087a98: /* original f64c, guest PC 0x0c087a98 */
if(!s->budget--) { s->failed_pc=0x0c087a98u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c087a9a;
P_0c087a9a: /* original f631, guest PC 0x0c087a9a */
if(!s->budget--) { s->failed_pc=0x0c087a9au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c087a9c;
P_0c087a9c: /* original f815, guest PC 0x0c087a9c */
if(!s->budget--) { s->failed_pc=0x0c087a9cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[1]))!=0);
goto P_0c087a9e;
P_0c087a9e: /* original f37c, guest PC 0x0c087a9e */
if(!s->budget--) { s->failed_pc=0x0c087a9eu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c087aa0;
P_0c087aa0: /* original f75c, guest PC 0x0c087aa0 */
if(!s->budget--) { s->failed_pc=0x0c087aa0u; return 0; }
vf3_matrix_move(s,7,5);
goto P_0c087aa2;
P_0c087aa2: /* original 8f0c, guest PC 0x0c087aa2 */
if(!s->budget--) { s->failed_pc=0x0c087aa2u; return 0; }
cond=r[17]&1u;
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
if(!cond) { goto P_0c087abe; }
goto P_0c087aa6;
P_0c087aa4: /* original f731, guest PC 0x0c087aa4 */
if(!s->budget--) { s->failed_pc=0x0c087aa4u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'-');
goto P_0c087aa6;
P_0c087aa6: /* original f805, guest PC 0x0c087aa6 */
if(!s->budget--) { s->failed_pc=0x0c087aa6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[0]))!=0);
goto P_0c087aa8;
P_0c087aa8: /* original 8b09, guest PC 0x0c087aa8 */
if(!s->budget--) { s->failed_pc=0x0c087aa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087aaa;
P_0c087aaa: /* original c730, guest PC 0x0c087aaa */
if(!s->budget--) { s->failed_pc=0x0c087aaau; return 0; }
r[0]=code_base|0x00087b6cu;
goto P_0c087aac;
P_0c087aac: /* original f308, guest PC 0x0c087aac */
if(!s->budget--) { s->failed_pc=0x0c087aacu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087aae;
P_0c087aae: /* original f635, guest PC 0x0c087aae */
if(!s->budget--) { s->failed_pc=0x0c087aaeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[3]))!=0);
goto P_0c087ab0;
P_0c087ab0: /* original 8b05, guest PC 0x0c087ab0 */
if(!s->budget--) { s->failed_pc=0x0c087ab0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087ab2;
P_0c087ab2: /* original c72e, guest PC 0x0c087ab2 */
if(!s->budget--) { s->failed_pc=0x0c087ab2u; return 0; }
r[0]=code_base|0x00087b6cu;
goto P_0c087ab4;
P_0c087ab4: /* original f308, guest PC 0x0c087ab4 */
if(!s->budget--) { s->failed_pc=0x0c087ab4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087ab6;
P_0c087ab6: /* original f735, guest PC 0x0c087ab6 */
if(!s->budget--) { s->failed_pc=0x0c087ab6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[3]))!=0);
goto P_0c087ab8;
P_0c087ab8: /* original 8b01, guest PC 0x0c087ab8 */
if(!s->budget--) { s->failed_pc=0x0c087ab8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087abe; }
goto P_0c087aba;
P_0c087aba: /* original 000b, guest PC 0x0c087aba */
if(!s->budget--) { s->failed_pc=0x0c087abau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c087abc: /* original 6043, guest PC 0x0c087abc */
if(!s->budget--) { s->failed_pc=0x0c087abcu; return 0; }
r[0]=r[4];
goto P_0c087abe;
P_0c087abe: /* original 7501, guest PC 0x0c087abe */
if(!s->budget--) { s->failed_pc=0x0c087abeu; return 0; }
r[5]+=0x00000001u;
goto P_0c087ac0;
P_0c087ac0: /* original 924c, guest PC 0x0c087ac0 */
if(!s->budget--) { s->failed_pc=0x0c087ac0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5cu,2);
goto P_0c087ac2;
P_0c087ac2: /* original 3563, guest PC 0x0c087ac2 */
if(!s->budget--) { s->failed_pc=0x0c087ac2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c087ac4;
P_0c087ac4: /* original 8fca, guest PC 0x0c087ac4 */
if(!s->budget--) { s->failed_pc=0x0c087ac4u; return 0; }
cond=r[17]&1u;
r[4]+=r[2];
if(!cond) { goto P_0c087a5c; }
goto P_0c087ac8;
P_0c087ac6: /* original 342c, guest PC 0x0c087ac6 */
if(!s->budget--) { s->failed_pc=0x0c087ac6u; return 0; }
r[4]+=r[2];
goto P_0c087ac8;
P_0c087ac8: /* original e000, guest PC 0x0c087ac8 */
if(!s->budget--) { s->failed_pc=0x0c087ac8u; return 0; }
r[0]=0x00000000u;
goto P_0c087aca;
P_0c087aca: /* original 000b, guest PC 0x0c087aca */
if(!s->budget--) { s->failed_pc=0x0c087acau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c087acc: /* original 0009, guest PC 0x0c087acc */
if(!s->budget--) { s->failed_pc=0x0c087accu; return 0; }
goto P_0c087ace;
P_0c087ace: /* original 2fe6, guest PC 0x0c087ace */
if(!s->budget--) { s->failed_pc=0x0c087aceu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ad0;
P_0c087ad0: /* original 2fd6, guest PC 0x0c087ad0 */
if(!s->budget--) { s->failed_pc=0x0c087ad0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ad2;
P_0c087ad2: /* original 6d63, guest PC 0x0c087ad2 */
if(!s->budget--) { s->failed_pc=0x0c087ad2u; return 0; }
r[13]=r[6];
goto P_0c087ad4;
P_0c087ad4: /* original 2fc6, guest PC 0x0c087ad4 */
if(!s->budget--) { s->failed_pc=0x0c087ad4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ad6;
P_0c087ad6: /* original 6c43, guest PC 0x0c087ad6 */
if(!s->budget--) { s->failed_pc=0x0c087ad6u; return 0; }
r[12]=r[4];
goto P_0c087ad8;
P_0c087ad8: /* original 2fb6, guest PC 0x0c087ad8 */
if(!s->budget--) { s->failed_pc=0x0c087ad8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ada;
P_0c087ada: /* original 6b53, guest PC 0x0c087ada */
if(!s->budget--) { s->failed_pc=0x0c087adau; return 0; }
r[11]=r[5];
goto P_0c087adc;
P_0c087adc: /* original 4f22, guest PC 0x0c087adc */
if(!s->budget--) { s->failed_pc=0x0c087adcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087ade;
P_0c087ade: /* original 7ffc, guest PC 0x0c087ade */
if(!s->budget--) { s->failed_pc=0x0c087adeu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c087ae0;
P_0c087ae0: /* original 2f72, guest PC 0x0c087ae0 */
if(!s->budget--) { s->failed_pc=0x0c087ae0u; return 0; }
write(ram,r[15],r[7],4);
goto P_0c087ae2;
P_0c087ae2: /* original f5d8, guest PC 0x0c087ae2 */
if(!s->budget--) { s->failed_pc=0x0c087ae2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
goto P_0c087ae4;
P_0c087ae4: /* original bfac, guest PC 0x0c087ae4 */
if(!s->budget--) { s->failed_pc=0x0c087ae4u; return 0; }
target=code_base|0x0c087a40u; r[16]=code_base|0x0c087ae8u;
vf3_matrix_load(s,ram,4,r[12]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087ae8u) { target=s->pc; goto dispatch; }
goto P_0c087ae8;
P_0c087ae6: /* original f4c8, guest PC 0x0c087ae6 */
if(!s->budget--) { s->failed_pc=0x0c087ae6u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c087ae8;
P_0c087ae8: /* original 6e03, guest PC 0x0c087ae8 */
if(!s->budget--) { s->failed_pc=0x0c087ae8u; return 0; }
r[14]=r[0];
goto P_0c087aea;
P_0c087aea: /* original 2ee8, guest PC 0x0c087aea */
if(!s->budget--) { s->failed_pc=0x0c087aeau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c087aec;
P_0c087aec: /* original 892c, guest PC 0x0c087aec */
if(!s->budget--) { s->failed_pc=0x0c087aecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087b48; }
goto P_0c087aee;
P_0c087aee: /* original d320, guest PC 0x0c087aee */
if(!s->budget--) { s->failed_pc=0x0c087aeeu; return 0; }
r[3]=read(ram,0x0c087b70u,4);
goto P_0c087af0;
P_0c087af0: /* original 430b, guest PC 0x0c087af0 */
if(!s->budget--) { s->failed_pc=0x0c087af0u; return 0; }
target=r[3];
r[16]=code_base|0x0c087af4u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087af4u) { target=s->pc; goto dispatch; }
goto P_0c087af4;
P_0c087af2: /* original e400, guest PC 0x0c087af2 */
if(!s->budget--) { s->failed_pc=0x0c087af2u; return 0; }
r[4]=0x00000000u;
goto P_0c087af4;
P_0c087af4: /* original d21f, guest PC 0x0c087af4 */
if(!s->budget--) { s->failed_pc=0x0c087af4u; return 0; }
r[2]=read(ram,0x0c087b74u,4);
goto P_0c087af6;
P_0c087af6: /* original 420b, guest PC 0x0c087af6 */
if(!s->budget--) { s->failed_pc=0x0c087af6u; return 0; }
target=r[2];
r[16]=code_base|0x0c087afau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087afau) { target=s->pc; goto dispatch; }
goto P_0c087afa;
P_0c087af8: /* original 64e3, guest PC 0x0c087af8 */
if(!s->budget--) { s->failed_pc=0x0c087af8u; return 0; }
r[4]=r[14];
goto P_0c087afa;
P_0c087afa: /* original 9030, guest PC 0x0c087afa */
if(!s->budget--) { s->failed_pc=0x0c087afau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087b5eu,2);
goto P_0c087afc;
P_0c087afc: /* original 66d3, guest PC 0x0c087afc */
if(!s->budget--) { s->failed_pc=0x0c087afcu; return 0; }
r[6]=r[13];
goto P_0c087afe;
P_0c087afe: /* original f2c8, guest PC 0x0c087afe */
if(!s->budget--) { s->failed_pc=0x0c087afeu; return 0; }
vf3_matrix_load(s,ram,2,r[12]);
goto P_0c087b00;
P_0c087b00: /* original 65b3, guest PC 0x0c087b00 */
if(!s->budget--) { s->failed_pc=0x0c087b00u; return 0; }
r[5]=r[11];
goto P_0c087b02;
P_0c087b02: /* original f3e6, guest PC 0x0c087b02 */
if(!s->budget--) { s->failed_pc=0x0c087b02u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087b04;
P_0c087b04: /* original 7004, guest PC 0x0c087b04 */
if(!s->budget--) { s->failed_pc=0x0c087b04u; return 0; }
r[0]+=0x00000004u;
goto P_0c087b06;
P_0c087b06: /* original f231, guest PC 0x0c087b06 */
if(!s->budget--) { s->failed_pc=0x0c087b06u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c087b08;
P_0c087b08: /* original fc2a, guest PC 0x0c087b08 */
if(!s->budget--) { s->failed_pc=0x0c087b08u; return 0; }
vf3_matrix_store(s,ram,2,r[12]);
goto P_0c087b0a;
P_0c087b0a: /* original f2b8, guest PC 0x0c087b0a */
if(!s->budget--) { s->failed_pc=0x0c087b0au; return 0; }
vf3_matrix_load(s,ram,2,r[11]);
goto P_0c087b0c;
P_0c087b0c: /* original f3e6, guest PC 0x0c087b0c */
if(!s->budget--) { s->failed_pc=0x0c087b0cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087b0e;
P_0c087b0e: /* original 7004, guest PC 0x0c087b0e */
if(!s->budget--) { s->failed_pc=0x0c087b0eu; return 0; }
r[0]+=0x00000004u;
goto P_0c087b10;
P_0c087b10: /* original f231, guest PC 0x0c087b10 */
if(!s->budget--) { s->failed_pc=0x0c087b10u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c087b12;
P_0c087b12: /* original fb2a, guest PC 0x0c087b12 */
if(!s->budget--) { s->failed_pc=0x0c087b12u; return 0; }
vf3_matrix_store(s,ram,2,r[11]);
goto P_0c087b14;
P_0c087b14: /* original f2d8, guest PC 0x0c087b14 */
if(!s->budget--) { s->failed_pc=0x0c087b14u; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
goto P_0c087b16;
P_0c087b16: /* original f3e6, guest PC 0x0c087b16 */
if(!s->budget--) { s->failed_pc=0x0c087b16u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c087b18;
P_0c087b18: /* original c717, guest PC 0x0c087b18 */
if(!s->budget--) { s->failed_pc=0x0c087b18u; return 0; }
r[0]=code_base|0x00087b78u;
goto P_0c087b1a;
P_0c087b1a: /* original f231, guest PC 0x0c087b1a */
if(!s->budget--) { s->failed_pc=0x0c087b1au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c087b1c;
P_0c087b1c: /* original fd2a, guest PC 0x0c087b1c */
if(!s->budget--) { s->failed_pc=0x0c087b1cu; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c087b1e;
P_0c087b1e: /* original f308, guest PC 0x0c087b1e */
if(!s->budget--) { s->failed_pc=0x0c087b1eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087b20;
P_0c087b20: /* original f232, guest PC 0x0c087b20 */
if(!s->budget--) { s->failed_pc=0x0c087b20u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c087b22;
P_0c087b22: /* original fd2a, guest PC 0x0c087b22 */
if(!s->budget--) { s->failed_pc=0x0c087b22u; return 0; }
vf3_matrix_store(s,ram,2,r[13]);
goto P_0c087b24;
P_0c087b24: /* original f5b8, guest PC 0x0c087b24 */
if(!s->budget--) { s->failed_pc=0x0c087b24u; return 0; }
vf3_matrix_load(s,ram,5,r[11]);
goto P_0c087b26;
P_0c087b26: /* original f4c8, guest PC 0x0c087b26 */
if(!s->budget--) { s->failed_pc=0x0c087b26u; return 0; }
vf3_matrix_load(s,ram,4,r[12]);
goto P_0c087b28;
P_0c087b28: /* original f62c, guest PC 0x0c087b28 */
if(!s->budget--) { s->failed_pc=0x0c087b28u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c087b2a;
P_0c087b2a: /* original bde2, guest PC 0x0c087b2a */
if(!s->budget--) { s->failed_pc=0x0c087b2au; return 0; }
target=code_base|0x0c0876f2u; r[16]=code_base|0x0c087b2eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087b2eu) { target=s->pc; goto dispatch; }
goto P_0c087b2e;
P_0c087b2c: /* original 64c3, guest PC 0x0c087b2c */
if(!s->budget--) { s->failed_pc=0x0c087b2cu; return 0; }
r[4]=r[12];
goto P_0c087b2e;
P_0c087b2e: /* original 55f6, guest PC 0x0c087b2e */
if(!s->budget--) { s->failed_pc=0x0c087b2eu; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c087b30;
P_0c087b30: /* original 56f7, guest PC 0x0c087b30 */
if(!s->budget--) { s->failed_pc=0x0c087b30u; return 0; }
r[6]=read(ram,r[15]+28,4);
goto P_0c087b32;
P_0c087b32: /* original bdff, guest PC 0x0c087b32 */
if(!s->budget--) { s->failed_pc=0x0c087b32u; return 0; }
target=code_base|0x0c087734u; r[16]=code_base|0x0c087b36u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087b36u) { target=s->pc; goto dispatch; }
goto P_0c087b36;
P_0c087b34: /* original 64f2, guest PC 0x0c087b34 */
if(!s->budget--) { s->failed_pc=0x0c087b34u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c087b36;
P_0c087b36: /* original 7f04, guest PC 0x0c087b36 */
if(!s->budget--) { s->failed_pc=0x0c087b36u; return 0; }
r[15]+=0x00000004u;
goto P_0c087b38;
P_0c087b38: /* original d210, guest PC 0x0c087b38 */
if(!s->budget--) { s->failed_pc=0x0c087b38u; return 0; }
r[2]=read(ram,0x0c087b7cu,4);
goto P_0c087b3a;
P_0c087b3a: /* original 4f26, guest PC 0x0c087b3a */
if(!s->budget--) { s->failed_pc=0x0c087b3au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087b3c;
P_0c087b3c: /* original e401, guest PC 0x0c087b3c */
if(!s->budget--) { s->failed_pc=0x0c087b3cu; return 0; }
r[4]=0x00000001u;
goto P_0c087b3e;
P_0c087b3e: /* original 6bf6, guest PC 0x0c087b3e */
if(!s->budget--) { s->failed_pc=0x0c087b3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087b40;
P_0c087b40: /* original 6cf6, guest PC 0x0c087b40 */
if(!s->budget--) { s->failed_pc=0x0c087b40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087b42;
P_0c087b42: /* original 6df6, guest PC 0x0c087b42 */
if(!s->budget--) { s->failed_pc=0x0c087b42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087b44;
P_0c087b44: /* original 422b, guest PC 0x0c087b44 */
if(!s->budget--) { s->failed_pc=0x0c087b44u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c087b46: /* original 6ef6, guest PC 0x0c087b46 */
if(!s->budget--) { s->failed_pc=0x0c087b46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c087b48;
P_0c087b48: /* original 7f04, guest PC 0x0c087b48 */
if(!s->budget--) { s->failed_pc=0x0c087b48u; return 0; }
r[15]+=0x00000004u;
goto P_0c087b4a;
P_0c087b4a: /* original 4f26, guest PC 0x0c087b4a */
if(!s->budget--) { s->failed_pc=0x0c087b4au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087b4c;
P_0c087b4c: /* original 6bf6, guest PC 0x0c087b4c */
if(!s->budget--) { s->failed_pc=0x0c087b4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087b4e;
P_0c087b4e: /* original 6cf6, guest PC 0x0c087b4e */
if(!s->budget--) { s->failed_pc=0x0c087b4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087b50;
P_0c087b50: /* original 6df6, guest PC 0x0c087b50 */
if(!s->budget--) { s->failed_pc=0x0c087b50u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087b52;
P_0c087b52: /* original 000b, guest PC 0x0c087b52 */
if(!s->budget--) { s->failed_pc=0x0c087b52u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087b54: /* original 6ef6, guest PC 0x0c087b54 */
if(!s->budget--) { s->failed_pc=0x0c087b54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c087b56u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087b56u; return 0; } return 1;
P_0c087b80: /* original c718, guest PC 0x0c087b80 */
if(!s->budget--) { s->failed_pc=0x0c087b80u; return 0; }
r[0]=code_base|0x00087be4u;
goto P_0c087b82;
P_0c087b82: /* original d319, guest PC 0x0c087b82 */
if(!s->budget--) { s->failed_pc=0x0c087b82u; return 0; }
r[3]=read(ram,0x0c087be8u,4);
goto P_0c087b84;
P_0c087b84: /* original f608, guest PC 0x0c087b84 */
if(!s->budget--) { s->failed_pc=0x0c087b84u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c087b86;
P_0c087b86: /* original e048, guest PC 0x0c087b86 */
if(!s->budget--) { s->failed_pc=0x0c087b86u; return 0; }
r[0]=0x00000048u;
goto P_0c087b88;
P_0c087b88: /* original 054e, guest PC 0x0c087b88 */
if(!s->budget--) { s->failed_pc=0x0c087b88u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087b8a;
P_0c087b8a: /* original 2358, guest PC 0x0c087b8a */
if(!s->budget--) { s->failed_pc=0x0c087b8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c087b8c;
P_0c087b8c: /* original 8d05, guest PC 0x0c087b8c */
if(!s->budget--) { s->failed_pc=0x0c087b8cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,6);
if(cond) { goto P_0c087b9a; }
goto P_0c087b90;
P_0c087b8e: /* original f46c, guest PC 0x0c087b8e */
if(!s->budget--) { s->failed_pc=0x0c087b8eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087b90;
P_0c087b90: /* original d116, guest PC 0x0c087b90 */
if(!s->budget--) { s->failed_pc=0x0c087b90u; return 0; }
r[1]=read(ram,0x0c087becu,4);
goto P_0c087b92;
P_0c087b92: /* original 2158, guest PC 0x0c087b92 */
if(!s->budget--) { s->failed_pc=0x0c087b92u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[5])==0)!=0);
goto P_0c087b94;
P_0c087b94: /* original 8b01, guest PC 0x0c087b94 */
if(!s->budget--) { s->failed_pc=0x0c087b94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087b9a; }
goto P_0c087b96;
P_0c087b96: /* original c716, guest PC 0x0c087b96 */
if(!s->budget--) { s->failed_pc=0x0c087b96u; return 0; }
r[0]=code_base|0x00087bf0u;
goto P_0c087b98;
P_0c087b98: /* original f408, guest PC 0x0c087b98 */
if(!s->budget--) { s->failed_pc=0x0c087b98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087b9a;
P_0c087b9a: /* original 901e, guest PC 0x0c087b9a */
if(!s->budget--) { s->failed_pc=0x0c087b9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdau,2);
goto P_0c087b9c;
P_0c087b9c: /* original 064e, guest PC 0x0c087b9c */
if(!s->budget--) { s->failed_pc=0x0c087b9cu; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c087b9e;
P_0c087b9e: /* original 7004, guest PC 0x0c087b9e */
if(!s->budget--) { s->failed_pc=0x0c087b9eu; return 0; }
r[0]+=0x00000004u;
goto P_0c087ba0;
P_0c087ba0: /* original 2668, guest PC 0x0c087ba0 */
if(!s->budget--) { s->failed_pc=0x0c087ba0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c087ba2;
P_0c087ba2: /* original 8d09, guest PC 0x0c087ba2 */
if(!s->budget--) { s->failed_pc=0x0c087ba2u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(cond) { goto P_0c087bb8; }
goto P_0c087ba6;
P_0c087ba4: /* original 054e, guest PC 0x0c087ba4 */
if(!s->budget--) { s->failed_pc=0x0c087ba4u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087ba6;
P_0c087ba6: /* original 2558, guest PC 0x0c087ba6 */
if(!s->budget--) { s->failed_pc=0x0c087ba6u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087ba8;
P_0c087ba8: /* original 8b06, guest PC 0x0c087ba8 */
if(!s->budget--) { s->failed_pc=0x0c087ba8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087bb8; }
goto P_0c087baa;
P_0c087baa: /* original 9017, guest PC 0x0c087baa */
if(!s->budget--) { s->failed_pc=0x0c087baau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdcu,2);
goto P_0c087bac;
P_0c087bac: /* original e303, guest PC 0x0c087bac */
if(!s->budget--) { s->failed_pc=0x0c087bacu; return 0; }
r[3]=0x00000003u;
goto P_0c087bae;
P_0c087bae: /* original f346, guest PC 0x0c087bae */
if(!s->budget--) { s->failed_pc=0x0c087baeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c087bb0;
P_0c087bb0: /* original 7004, guest PC 0x0c087bb0 */
if(!s->budget--) { s->failed_pc=0x0c087bb0u; return 0; }
r[0]+=0x00000004u;
goto P_0c087bb2;
P_0c087bb2: /* original f437, guest PC 0x0c087bb2 */
if(!s->budget--) { s->failed_pc=0x0c087bb2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c087bb4;
P_0c087bb4: /* original 7004, guest PC 0x0c087bb4 */
if(!s->budget--) { s->failed_pc=0x0c087bb4u; return 0; }
r[0]+=0x00000004u;
goto P_0c087bb6;
P_0c087bb6: /* original 0436, guest PC 0x0c087bb6 */
if(!s->budget--) { s->failed_pc=0x0c087bb6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c087bb8;
P_0c087bb8: /* original 9011, guest PC 0x0c087bb8 */
if(!s->budget--) { s->failed_pc=0x0c087bb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087bdeu,2);
goto P_0c087bba;
P_0c087bba: /* original 054e, guest PC 0x0c087bba */
if(!s->budget--) { s->failed_pc=0x0c087bbau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c087bbc;
P_0c087bbc: /* original 2558, guest PC 0x0c087bbc */
if(!s->budget--) { s->failed_pc=0x0c087bbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087bbe;
P_0c087bbe: /* original 890a, guest PC 0x0c087bbe */
if(!s->budget--) { s->failed_pc=0x0c087bbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087bd6; }
goto P_0c087bc0;
P_0c087bc0: /* original 75ff, guest PC 0x0c087bc0 */
if(!s->budget--) { s->failed_pc=0x0c087bc0u; return 0; }
r[5]+=0xffffffffu;
goto P_0c087bc2;
P_0c087bc2: /* original 2558, guest PC 0x0c087bc2 */
if(!s->budget--) { s->failed_pc=0x0c087bc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c087bc4;
P_0c087bc4: /* original 625c, guest PC 0x0c087bc4 */
if(!s->budget--) { s->failed_pc=0x0c087bc4u; return 0; }
r[2]=r[5]&255u;
goto P_0c087bc6;
P_0c087bc6: /* original 8f06, guest PC 0x0c087bc6 */
if(!s->budget--) { s->failed_pc=0x0c087bc6u; return 0; }
cond=r[17]&1u;
write(ram,r[4]+r[0],r[2],4);
if(!cond) { goto P_0c087bd6; }
goto P_0c087bca;
P_0c087bc8: /* original 0426, guest PC 0x0c087bc8 */
if(!s->budget--) { s->failed_pc=0x0c087bc8u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c087bca;
P_0c087bca: /* original 9009, guest PC 0x0c087bca */
if(!s->budget--) { s->failed_pc=0x0c087bcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087be0u,2);
goto P_0c087bcc;
P_0c087bcc: /* original f546, guest PC 0x0c087bcc */
if(!s->budget--) { s->failed_pc=0x0c087bccu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c087bce;
P_0c087bce: /* original c709, guest PC 0x0c087bce */
if(!s->budget--) { s->failed_pc=0x0c087bceu; return 0; }
r[0]=code_base|0x00087bf4u;
goto P_0c087bd0;
P_0c087bd0: /* original f008, guest PC 0x0c087bd0 */
if(!s->budget--) { s->failed_pc=0x0c087bd0u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c087bd2;
P_0c087bd2: /* original f65e, guest PC 0x0c087bd2 */
if(!s->budget--) { s->failed_pc=0x0c087bd2u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[5],fr[6],r[18]);
goto P_0c087bd4;
P_0c087bd4: /* original f46c, guest PC 0x0c087bd4 */
if(!s->budget--) { s->failed_pc=0x0c087bd4u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087bd6;
P_0c087bd6: /* original 000b, guest PC 0x0c087bd6 */
if(!s->budget--) { s->failed_pc=0x0c087bd6u; return 0; }
target=r[16];
vf3_matrix_move(s,0,4);
s->pc=target; return ram->oob==0;
P_0c087bd8: /* original f04c, guest PC 0x0c087bd8 */
if(!s->budget--) { s->failed_pc=0x0c087bd8u; return 0; }
vf3_matrix_move(s,0,4);
if(!vf3_matrix_family(0x0c087bdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087bdau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
