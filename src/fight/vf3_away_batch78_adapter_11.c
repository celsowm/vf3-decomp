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
int vf3_away_batch78_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2984u: goto P_0c0a2984;
case 0x0c0a2986u: goto P_0c0a2986;
case 0x0c0a2988u: goto P_0c0a2988;
case 0x0c0a298au: goto P_0c0a298a;
case 0x0c0a298cu: goto P_0c0a298c;
case 0x0c0a298eu: goto P_0c0a298e;
case 0x0c0a2990u: goto P_0c0a2990;
case 0x0c0a2992u: goto P_0c0a2992;
case 0x0c0a2994u: goto P_0c0a2994;
case 0x0c0a2996u: goto P_0c0a2996;
case 0x0c0a2998u: goto P_0c0a2998;
case 0x0c0a299au: goto P_0c0a299a;
case 0x0c0a299cu: goto P_0c0a299c;
case 0x0c0a299eu: goto P_0c0a299e;
case 0x0c0a29a0u: goto P_0c0a29a0;
case 0x0c0a29a2u: goto P_0c0a29a2;
case 0x0c0a29a4u: goto P_0c0a29a4;
case 0x0c0a29a6u: goto P_0c0a29a6;
case 0x0c0a29a8u: goto P_0c0a29a8;
case 0x0c0a29aau: goto P_0c0a29aa;
case 0x0c0a29acu: goto P_0c0a29ac;
case 0x0c0a29aeu: goto P_0c0a29ae;
case 0x0c0a29b0u: goto P_0c0a29b0;
case 0x0c0a29b2u: goto P_0c0a29b2;
case 0x0c0a29b4u: goto P_0c0a29b4;
case 0x0c0a29b6u: goto P_0c0a29b6;
case 0x0c0a29b8u: goto P_0c0a29b8;
case 0x0c0a29bau: goto P_0c0a29ba;
case 0x0c0a29bcu: goto P_0c0a29bc;
case 0x0c0a29beu: goto P_0c0a29be;
case 0x0c0a29c0u: goto P_0c0a29c0;
case 0x0c0a29c2u: goto P_0c0a29c2;
case 0x0c0a29c4u: goto P_0c0a29c4;
case 0x0c0a29c6u: goto P_0c0a29c6;
case 0x0c0a29c8u: goto P_0c0a29c8;
case 0x0c0a29cau: goto P_0c0a29ca;
case 0x0c0a29ccu: goto P_0c0a29cc;
case 0x0c0a29ceu: goto P_0c0a29ce;
case 0x0c0a29d0u: goto P_0c0a29d0;
case 0x0c0a29d2u: goto P_0c0a29d2;
case 0x0c0a29d4u: goto P_0c0a29d4;
case 0x0c0a29d6u: goto P_0c0a29d6;
case 0x0c0a29d8u: goto P_0c0a29d8;
case 0x0c0a29dau: goto P_0c0a29da;
case 0x0c0a29dcu: goto P_0c0a29dc;
case 0x0c0a29deu: goto P_0c0a29de;
case 0x0c0a29e0u: goto P_0c0a29e0;
case 0x0c0a29e2u: goto P_0c0a29e2;
case 0x0c0a29e4u: goto P_0c0a29e4;
case 0x0c0a29e6u: goto P_0c0a29e6;
case 0x0c0a29e8u: goto P_0c0a29e8;
case 0x0c0a29eau: goto P_0c0a29ea;
case 0x0c0a29ecu: goto P_0c0a29ec;
case 0x0c0a29eeu: goto P_0c0a29ee;
case 0x0c0a29f0u: goto P_0c0a29f0;
case 0x0c0a29f2u: goto P_0c0a29f2;
case 0x0c0a29f4u: goto P_0c0a29f4;
case 0x0c0a29f6u: goto P_0c0a29f6;
case 0x0c0a29f8u: goto P_0c0a29f8;
case 0x0c0a29fau: goto P_0c0a29fa;
case 0x0c0a29fcu: goto P_0c0a29fc;
case 0x0c0a29feu: goto P_0c0a29fe;
case 0x0c0a2a00u: goto P_0c0a2a00;
case 0x0c0a2a02u: goto P_0c0a2a02;
case 0x0c0a2a04u: goto P_0c0a2a04;
case 0x0c0a2a06u: goto P_0c0a2a06;
case 0x0c0a2a08u: goto P_0c0a2a08;
case 0x0c0a2a0au: goto P_0c0a2a0a;
case 0x0c0a2a0cu: goto P_0c0a2a0c;
case 0x0c0a2a0eu: goto P_0c0a2a0e;
case 0x0c0a2a10u: goto P_0c0a2a10;
case 0x0c0a2a12u: goto P_0c0a2a12;
case 0x0c0a2a14u: goto P_0c0a2a14;
case 0x0c0a2a16u: goto P_0c0a2a16;
case 0x0c0a2a18u: goto P_0c0a2a18;
case 0x0c0a2a1au: goto P_0c0a2a1a;
case 0x0c0a2a1cu: goto P_0c0a2a1c;
case 0x0c0a2a1eu: goto P_0c0a2a1e;
case 0x0c0a2a20u: goto P_0c0a2a20;
case 0x0c0a2a22u: goto P_0c0a2a22;
case 0x0c0a2a24u: goto P_0c0a2a24;
case 0x0c0a2a26u: goto P_0c0a2a26;
case 0x0c0a2a28u: goto P_0c0a2a28;
case 0x0c0a2a2au: goto P_0c0a2a2a;
case 0x0c0a2a2cu: goto P_0c0a2a2c;
case 0x0c0a2a2eu: goto P_0c0a2a2e;
case 0x0c0a2a30u: goto P_0c0a2a30;
case 0x0c0a2a32u: goto P_0c0a2a32;
case 0x0c0a2a34u: goto P_0c0a2a34;
case 0x0c0a2a36u: goto P_0c0a2a36;
case 0x0c0a2a38u: goto P_0c0a2a38;
case 0x0c0a2a3au: goto P_0c0a2a3a;
case 0x0c0a2a3cu: goto P_0c0a2a3c;
case 0x0c0a2a3eu: goto P_0c0a2a3e;
case 0x0c0a2a40u: goto P_0c0a2a40;
case 0x0c0a2a42u: goto P_0c0a2a42;
case 0x0c0a2a44u: goto P_0c0a2a44;
case 0x0c0a2a46u: goto P_0c0a2a46;
case 0x0c0a2a48u: goto P_0c0a2a48;
case 0x0c0a2a4au: goto P_0c0a2a4a;
case 0x0c0a2a4cu: goto P_0c0a2a4c;
case 0x0c0a2a4eu: goto P_0c0a2a4e;
case 0x0c0a2a50u: goto P_0c0a2a50;
case 0x0c0a2a52u: goto P_0c0a2a52;
case 0x0c0a2a54u: goto P_0c0a2a54;
case 0x0c0a2a56u: goto P_0c0a2a56;
case 0x0c0a2a58u: goto P_0c0a2a58;
case 0x0c0a2a5au: goto P_0c0a2a5a;
case 0x0c0a2a5cu: goto P_0c0a2a5c;
case 0x0c0a2a5eu: goto P_0c0a2a5e;
case 0x0c0a2a60u: goto P_0c0a2a60;
case 0x0c0a2a62u: goto P_0c0a2a62;
case 0x0c0a2a64u: goto P_0c0a2a64;
case 0x0c0a2a66u: goto P_0c0a2a66;
case 0x0c0a2a68u: goto P_0c0a2a68;
case 0x0c0a2a6au: goto P_0c0a2a6a;
case 0x0c0a2a6cu: goto P_0c0a2a6c;
case 0x0c0a2a6eu: goto P_0c0a2a6e;
case 0x0c0a2a70u: goto P_0c0a2a70;
case 0x0c0a2a72u: goto P_0c0a2a72;
case 0x0c0a2a74u: goto P_0c0a2a74;
case 0x0c0a2a76u: goto P_0c0a2a76;
case 0x0c0a2a78u: goto P_0c0a2a78;
case 0x0c0a2a7au: goto P_0c0a2a7a;
case 0x0c0a2a7cu: goto P_0c0a2a7c;
case 0x0c0a2a7eu: goto P_0c0a2a7e;
case 0x0c0a2a80u: goto P_0c0a2a80;
case 0x0c0a2a82u: goto P_0c0a2a82;
case 0x0c0a2a84u: goto P_0c0a2a84;
case 0x0c0a2a86u: goto P_0c0a2a86;
case 0x0c0a2a88u: goto P_0c0a2a88;
case 0x0c0a2a8au: goto P_0c0a2a8a;
case 0x0c0a2a8cu: goto P_0c0a2a8c;
case 0x0c0a2a8eu: goto P_0c0a2a8e;
case 0x0c0a2a90u: goto P_0c0a2a90;
case 0x0c0a2a92u: goto P_0c0a2a92;
case 0x0c0a2a94u: goto P_0c0a2a94;
case 0x0c0a2a96u: goto P_0c0a2a96;
case 0x0c0a2a98u: goto P_0c0a2a98;
case 0x0c0a2a9au: goto P_0c0a2a9a;
case 0x0c0a2a9cu: goto P_0c0a2a9c;
case 0x0c0a2a9eu: goto P_0c0a2a9e;
case 0x0c0a2aa0u: goto P_0c0a2aa0;
case 0x0c0a2aa2u: goto P_0c0a2aa2;
case 0x0c0a2aa4u: goto P_0c0a2aa4;
case 0x0c0a2aa6u: goto P_0c0a2aa6;
case 0x0c0a2aa8u: goto P_0c0a2aa8;
case 0x0c0a2aaau: goto P_0c0a2aaa;
case 0x0c0a2aacu: goto P_0c0a2aac;
case 0x0c0a2aaeu: goto P_0c0a2aae;
case 0x0c0a2ab0u: goto P_0c0a2ab0;
case 0x0c0a2ab2u: goto P_0c0a2ab2;
case 0x0c0a2ab4u: goto P_0c0a2ab4;
case 0x0c0a2ab6u: goto P_0c0a2ab6;
case 0x0c0a2ab8u: goto P_0c0a2ab8;
case 0x0c0a2abau: goto P_0c0a2aba;
case 0x0c0a2abcu: goto P_0c0a2abc;
case 0x0c0a2abeu: goto P_0c0a2abe;
case 0x0c0a2ac0u: goto P_0c0a2ac0;
case 0x0c0a2ac2u: goto P_0c0a2ac2;
case 0x0c0a2ac4u: goto P_0c0a2ac4;
case 0x0c0a2ac6u: goto P_0c0a2ac6;
case 0x0c0a2ac8u: goto P_0c0a2ac8;
case 0x0c0a2acau: goto P_0c0a2aca;
case 0x0c0a2accu: goto P_0c0a2acc;
case 0x0c0a2aceu: goto P_0c0a2ace;
case 0x0c0a2ad0u: goto P_0c0a2ad0;
case 0x0c0a2ad2u: goto P_0c0a2ad2;
case 0x0c0a2ad4u: goto P_0c0a2ad4;
case 0x0c0a2ad6u: goto P_0c0a2ad6;
case 0x0c0a2ad8u: goto P_0c0a2ad8;
case 0x0c0a2adau: goto P_0c0a2ada;
case 0x0c0a2adcu: goto P_0c0a2adc;
case 0x0c0a2adeu: goto P_0c0a2ade;
case 0x0c0a2ae0u: goto P_0c0a2ae0;
case 0x0c0a2ae2u: goto P_0c0a2ae2;
case 0x0c0a2ae4u: goto P_0c0a2ae4;
case 0x0c0a2ae6u: goto P_0c0a2ae6;
case 0x0c0a2ae8u: goto P_0c0a2ae8;
case 0x0c0a2aeau: goto P_0c0a2aea;
case 0x0c0a2aecu: goto P_0c0a2aec;
case 0x0c0a2aeeu: goto P_0c0a2aee;
case 0x0c0a2af0u: goto P_0c0a2af0;
case 0x0c0a2af2u: goto P_0c0a2af2;
case 0x0c0a2af4u: goto P_0c0a2af4;
case 0x0c0a2af6u: goto P_0c0a2af6;
case 0x0c0a2af8u: goto P_0c0a2af8;
case 0x0c0a2afau: goto P_0c0a2afa;
case 0x0c0a2afcu: goto P_0c0a2afc;
case 0x0c0a2afeu: goto P_0c0a2afe;
case 0x0c0a2b00u: goto P_0c0a2b00;
case 0x0c0a2b02u: goto P_0c0a2b02;
case 0x0c0a2b04u: goto P_0c0a2b04;
case 0x0c0a2b06u: goto P_0c0a2b06;
case 0x0c0a2b08u: goto P_0c0a2b08;
case 0x0c0a2b0au: goto P_0c0a2b0a;
case 0x0c0a2b0cu: goto P_0c0a2b0c;
case 0x0c0a2b0eu: goto P_0c0a2b0e;
case 0x0c0a2b10u: goto P_0c0a2b10;
case 0x0c0a2b12u: goto P_0c0a2b12;
case 0x0c0a2b14u: goto P_0c0a2b14;
case 0x0c0a2b16u: goto P_0c0a2b16;
case 0x0c0a2b18u: goto P_0c0a2b18;
case 0x0c0a2b1au: goto P_0c0a2b1a;
case 0x0c0a2b1cu: goto P_0c0a2b1c;
case 0x0c0a2b1eu: goto P_0c0a2b1e;
case 0x0c0a2b20u: goto P_0c0a2b20;
case 0x0c0a2b22u: goto P_0c0a2b22;
case 0x0c0a2b24u: goto P_0c0a2b24;
case 0x0c0a2b26u: goto P_0c0a2b26;
case 0x0c0a2b28u: goto P_0c0a2b28;
case 0x0c0a2b2au: goto P_0c0a2b2a;
case 0x0c0a2b2cu: goto P_0c0a2b2c;
case 0x0c0a2b2eu: goto P_0c0a2b2e;
case 0x0c0a2b30u: goto P_0c0a2b30;
case 0x0c0a2b32u: goto P_0c0a2b32;
case 0x0c0a2b34u: goto P_0c0a2b34;
case 0x0c0a2b36u: goto P_0c0a2b36;
case 0x0c0a2b38u: goto P_0c0a2b38;
case 0x0c0a2b3au: goto P_0c0a2b3a;
case 0x0c0a2b3cu: goto P_0c0a2b3c;
case 0x0c0a2b3eu: goto P_0c0a2b3e;
case 0x0c0a2b40u: goto P_0c0a2b40;
case 0x0c0a2b42u: goto P_0c0a2b42;
case 0x0c0a2b44u: goto P_0c0a2b44;
case 0x0c0a2b46u: goto P_0c0a2b46;
case 0x0c0a2b48u: goto P_0c0a2b48;
case 0x0c0a2b4au: goto P_0c0a2b4a;
case 0x0c0a2b4cu: goto P_0c0a2b4c;
case 0x0c0a2b4eu: goto P_0c0a2b4e;
case 0x0c0a2b50u: goto P_0c0a2b50;
case 0x0c0a2b52u: goto P_0c0a2b52;
case 0x0c0a2b54u: goto P_0c0a2b54;
case 0x0c0a2b56u: goto P_0c0a2b56;
case 0x0c0a2b58u: goto P_0c0a2b58;
case 0x0c0a2b5au: goto P_0c0a2b5a;
case 0x0c0a2b5cu: goto P_0c0a2b5c;
case 0x0c0a2b5eu: goto P_0c0a2b5e;
case 0x0c0a2b60u: goto P_0c0a2b60;
case 0x0c0a2b62u: goto P_0c0a2b62;
case 0x0c0a2b64u: goto P_0c0a2b64;
case 0x0c0a2b66u: goto P_0c0a2b66;
case 0x0c0a2b68u: goto P_0c0a2b68;
case 0x0c0a2b6au: goto P_0c0a2b6a;
case 0x0c0a2b6cu: goto P_0c0a2b6c;
case 0x0c0a2b6eu: goto P_0c0a2b6e;
case 0x0c0a2b70u: goto P_0c0a2b70;
case 0x0c0a2b72u: goto P_0c0a2b72;
case 0x0c0a2b74u: goto P_0c0a2b74;
case 0x0c0a2b76u: goto P_0c0a2b76;
case 0x0c0a2b78u: goto P_0c0a2b78;
case 0x0c0a2b7au: goto P_0c0a2b7a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2984: /* original 2fe6, guest PC 0x0c0a2984 */
if(!s->budget--) { s->failed_pc=0x0c0a2984u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2986;
P_0c0a2986: /* original 6e43, guest PC 0x0c0a2986 */
if(!s->budget--) { s->failed_pc=0x0c0a2986u; return 0; }
r[14]=r[4];
goto P_0c0a2988;
P_0c0a2988: /* original 2fd6, guest PC 0x0c0a2988 */
if(!s->budget--) { s->failed_pc=0x0c0a2988u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298a;
P_0c0a298a: /* original 2fc6, guest PC 0x0c0a298a */
if(!s->budget--) { s->failed_pc=0x0c0a298au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298c;
P_0c0a298c: /* original 2fb6, guest PC 0x0c0a298c */
if(!s->budget--) { s->failed_pc=0x0c0a298cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a298e;
P_0c0a298e: /* original 2fa6, guest PC 0x0c0a298e */
if(!s->budget--) { s->failed_pc=0x0c0a298eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2990;
P_0c0a2990: /* original 2f96, guest PC 0x0c0a2990 */
if(!s->budget--) { s->failed_pc=0x0c0a2990u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2992;
P_0c0a2992: /* original 2f86, guest PC 0x0c0a2992 */
if(!s->budget--) { s->failed_pc=0x0c0a2992u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2994;
P_0c0a2994: /* original 4f22, guest PC 0x0c0a2994 */
if(!s->budget--) { s->failed_pc=0x0c0a2994u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2996;
P_0c0a2996: /* original 7ff8, guest PC 0x0c0a2996 */
if(!s->budget--) { s->failed_pc=0x0c0a2996u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2998;
P_0c0a2998: /* original 2f61, guest PC 0x0c0a2998 */
if(!s->budget--) { s->failed_pc=0x0c0a2998u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a299a;
P_0c0a299a: /* original b14c, guest PC 0x0c0a299a */
if(!s->budget--) { s->failed_pc=0x0c0a299au; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a299eu;
r[10]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a299eu) { target=s->pc; goto dispatch; }
goto P_0c0a299e;
P_0c0a299c: /* original 6a53, guest PC 0x0c0a299c */
if(!s->budget--) { s->failed_pc=0x0c0a299cu; return 0; }
r[10]=r[5];
goto P_0c0a299e;
P_0c0a299e: /* original 6403, guest PC 0x0c0a299e */
if(!s->budget--) { s->failed_pc=0x0c0a299eu; return 0; }
r[4]=r[0];
goto P_0c0a29a0;
P_0c0a29a0: /* original 2448, guest PC 0x0c0a29a0 */
if(!s->budget--) { s->failed_pc=0x0c0a29a0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a29a2;
P_0c0a29a2: /* original 8902, guest PC 0x0c0a29a2 */
if(!s->budget--) { s->failed_pc=0x0c0a29a2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a29aa; }
goto P_0c0a29a4;
P_0c0a29a4: /* original d375, guest PC 0x0c0a29a4 */
if(!s->budget--) { s->failed_pc=0x0c0a29a4u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a29a6;
P_0c0a29a6: /* original 3430, guest PC 0x0c0a29a6 */
if(!s->budget--) { s->failed_pc=0x0c0a29a6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c0a29a8;
P_0c0a29a8: /* original 8b59, guest PC 0x0c0a29a8 */
if(!s->budget--) { s->failed_pc=0x0c0a29a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29aa;
P_0c0a29aa: /* original e020, guest PC 0x0c0a29aa */
if(!s->budget--) { s->failed_pc=0x0c0a29aau; return 0; }
r[0]=0x00000020u;
goto P_0c0a29ac;
P_0c0a29ac: /* original 01ed, guest PC 0x0c0a29ac */
if(!s->budget--) { s->failed_pc=0x0c0a29acu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ae;
P_0c0a29ae: /* original e022, guest PC 0x0c0a29ae */
if(!s->budget--) { s->failed_pc=0x0c0a29aeu; return 0; }
r[0]=0x00000022u;
goto P_0c0a29b0;
P_0c0a29b0: /* original 03ed, guest PC 0x0c0a29b0 */
if(!s->budget--) { s->failed_pc=0x0c0a29b0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29b2;
P_0c0a29b2: /* original 611d, guest PC 0x0c0a29b2 */
if(!s->budget--) { s->failed_pc=0x0c0a29b2u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a29b4;
P_0c0a29b4: /* original 633d, guest PC 0x0c0a29b4 */
if(!s->budget--) { s->failed_pc=0x0c0a29b4u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a29b6;
P_0c0a29b6: /* original 213b, guest PC 0x0c0a29b6 */
if(!s->budget--) { s->failed_pc=0x0c0a29b6u; return 0; }
r[1]|=r[3];
goto P_0c0a29b8;
P_0c0a29b8: /* original 2118, guest PC 0x0c0a29b8 */
if(!s->budget--) { s->failed_pc=0x0c0a29b8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a29ba;
P_0c0a29ba: /* original 8b50, guest PC 0x0c0a29ba */
if(!s->budget--) { s->failed_pc=0x0c0a29bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a5e; }
goto P_0c0a29bc;
P_0c0a29bc: /* original e020, guest PC 0x0c0a29bc */
if(!s->budget--) { s->failed_pc=0x0c0a29bcu; return 0; }
r[0]=0x00000020u;
goto P_0c0a29be;
P_0c0a29be: /* original 52e4, guest PC 0x0c0a29be */
if(!s->budget--) { s->failed_pc=0x0c0a29beu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a29c0;
P_0c0a29c0: /* original 1f21, guest PC 0x0c0a29c0 */
if(!s->budget--) { s->failed_pc=0x0c0a29c0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a29c2;
P_0c0a29c2: /* original 63f1, guest PC 0x0c0a29c2 */
if(!s->budget--) { s->failed_pc=0x0c0a29c2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a29c4;
P_0c0a29c4: /* original 5ce5, guest PC 0x0c0a29c4 */
if(!s->budget--) { s->failed_pc=0x0c0a29c4u; return 0; }
r[12]=read(ram,r[14]+20,4);
goto P_0c0a29c6;
P_0c0a29c6: /* original 0e35, guest PC 0x0c0a29c6 */
if(!s->budget--) { s->failed_pc=0x0c0a29c6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a29c8;
P_0c0a29c8: /* original 04ed, guest PC 0x0c0a29c8 */
if(!s->budget--) { s->failed_pc=0x0c0a29c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a29ca;
P_0c0a29ca: /* original d36d, guest PC 0x0c0a29ca */
if(!s->budget--) { s->failed_pc=0x0c0a29cau; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a29cc;
P_0c0a29cc: /* original 430b, guest PC 0x0c0a29cc */
if(!s->budget--) { s->failed_pc=0x0c0a29ccu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a29d0u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a29d0u) { target=s->pc; goto dispatch; }
goto P_0c0a29d0;
P_0c0a29ce: /* original 644d, guest PC 0x0c0a29ce */
if(!s->budget--) { s->failed_pc=0x0c0a29ceu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a29d0;
P_0c0a29d0: /* original eb00, guest PC 0x0c0a29d0 */
if(!s->budget--) { s->failed_pc=0x0c0a29d0u; return 0; }
r[11]=0x00000000u;
goto P_0c0a29d2;
P_0c0a29d2: /* original a039, guest PC 0x0c0a29d2 */
if(!s->budget--) { s->failed_pc=0x0c0a29d2u; return 0; }
r[8]=r[11];
goto P_0c0a2a48;
P_0c0a29d4: /* original 68b3, guest PC 0x0c0a29d4 */
if(!s->budget--) { s->failed_pc=0x0c0a29d4u; return 0; }
r[8]=r[11];
goto P_0c0a29d6;
P_0c0a29d6: /* original 53f1, guest PC 0x0c0a29d6 */
if(!s->budget--) { s->failed_pc=0x0c0a29d6u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a29d8;
P_0c0a29d8: /* original 6d83, guest PC 0x0c0a29d8 */
if(!s->budget--) { s->failed_pc=0x0c0a29d8u; return 0; }
r[13]=r[8];
goto P_0c0a29da;
P_0c0a29da: /* original 4d08, guest PC 0x0c0a29da */
if(!s->budget--) { s->failed_pc=0x0c0a29dau; return 0; }
r[13]<<=2;
goto P_0c0a29dc;
P_0c0a29dc: /* original 3d3c, guest PC 0x0c0a29dc */
if(!s->budget--) { s->failed_pc=0x0c0a29dcu; return 0; }
r[13]+=r[3];
goto P_0c0a29de;
P_0c0a29de: /* original 60d2, guest PC 0x0c0a29de */
if(!s->budget--) { s->failed_pc=0x0c0a29deu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0a29e0;
P_0c0a29e0: /* original 5001, guest PC 0x0c0a29e0 */
if(!s->budget--) { s->failed_pc=0x0c0a29e0u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a29e2;
P_0c0a29e2: /* original c801, guest PC 0x0c0a29e2 */
if(!s->budget--) { s->failed_pc=0x0c0a29e2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a29e4;
P_0c0a29e4: /* original 8922, guest PC 0x0c0a29e4 */
if(!s->budget--) { s->failed_pc=0x0c0a29e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a2c; }
goto P_0c0a29e6;
P_0c0a29e6: /* original a008, guest PC 0x0c0a29e6 */
if(!s->budget--) { s->failed_pc=0x0c0a29e6u; return 0; }
r[4]=r[11];
goto P_0c0a29fa;
P_0c0a29e8: /* original 64b3, guest PC 0x0c0a29e8 */
if(!s->budget--) { s->failed_pc=0x0c0a29e8u; return 0; }
r[4]=r[11];
goto P_0c0a29ea;
P_0c0a29ea: /* original 6343, guest PC 0x0c0a29ea */
if(!s->budget--) { s->failed_pc=0x0c0a29eau; return 0; }
r[3]=r[4];
goto P_0c0a29ec;
P_0c0a29ec: /* original 4308, guest PC 0x0c0a29ec */
if(!s->budget--) { s->failed_pc=0x0c0a29ecu; return 0; }
r[3]<<=2;
goto P_0c0a29ee;
P_0c0a29ee: /* original 4308, guest PC 0x0c0a29ee */
if(!s->budget--) { s->failed_pc=0x0c0a29eeu; return 0; }
r[3]<<=2;
goto P_0c0a29f0;
P_0c0a29f0: /* original 33cc, guest PC 0x0c0a29f0 */
if(!s->budget--) { s->failed_pc=0x0c0a29f0u; return 0; }
r[3]+=r[12];
goto P_0c0a29f2;
P_0c0a29f2: /* original 5232, guest PC 0x0c0a29f2 */
if(!s->budget--) { s->failed_pc=0x0c0a29f2u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a29f4;
P_0c0a29f4: /* original 7401, guest PC 0x0c0a29f4 */
if(!s->budget--) { s->failed_pc=0x0c0a29f4u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a29f6;
P_0c0a29f6: /* original 32ac, guest PC 0x0c0a29f6 */
if(!s->budget--) { s->failed_pc=0x0c0a29f6u; return 0; }
r[2]+=r[10];
goto P_0c0a29f8;
P_0c0a29f8: /* original 1322, guest PC 0x0c0a29f8 */
if(!s->budget--) { s->failed_pc=0x0c0a29f8u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a29fa;
P_0c0a29fa: /* original 85e7, guest PC 0x0c0a29fa */
if(!s->budget--) { s->failed_pc=0x0c0a29fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a29fc;
P_0c0a29fc: /* original 600d, guest PC 0x0c0a29fc */
if(!s->budget--) { s->failed_pc=0x0c0a29fcu; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a29fe;
P_0c0a29fe: /* original 3403, guest PC 0x0c0a29fe */
if(!s->budget--) { s->failed_pc=0x0c0a29feu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a00;
P_0c0a2a00: /* original 8bf3, guest PC 0x0c0a2a00 */
if(!s->budget--) { s->failed_pc=0x0c0a2a00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29ea; }
goto P_0c0a2a02;
P_0c0a2a02: /* original d260, guest PC 0x0c0a2a02 */
if(!s->budget--) { s->failed_pc=0x0c0a2a02u; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2a04;
P_0c0a2a04: /* original 65c3, guest PC 0x0c0a2a04 */
if(!s->budget--) { s->failed_pc=0x0c0a2a04u; return 0; }
r[5]=r[12];
goto P_0c0a2a06;
P_0c0a2a06: /* original 420b, guest PC 0x0c0a2a06 */
if(!s->budget--) { s->failed_pc=0x0c0a2a06u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2a0au;
tmp=read(ram,r[13],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a0au) { target=s->pc; goto dispatch; }
goto P_0c0a2a0a;
P_0c0a2a08: /* original 64d2, guest PC 0x0c0a2a08 */
if(!s->budget--) { s->failed_pc=0x0c0a2a08u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a0a;
P_0c0a2a0a: /* original 2008, guest PC 0x0c0a2a0a */
if(!s->budget--) { s->failed_pc=0x0c0a2a0au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a0c;
P_0c0a2a0c: /* original a008, guest PC 0x0c0a2a0c */
if(!s->budget--) { s->failed_pc=0x0c0a2a0cu; return 0; }
r[4]=r[11];
goto P_0c0a2a20;
P_0c0a2a0e: /* original 64b3, guest PC 0x0c0a2a0e */
if(!s->budget--) { s->failed_pc=0x0c0a2a0eu; return 0; }
r[4]=r[11];
goto P_0c0a2a10;
P_0c0a2a10: /* original 6343, guest PC 0x0c0a2a10 */
if(!s->budget--) { s->failed_pc=0x0c0a2a10u; return 0; }
r[3]=r[4];
goto P_0c0a2a12;
P_0c0a2a12: /* original 4308, guest PC 0x0c0a2a12 */
if(!s->budget--) { s->failed_pc=0x0c0a2a12u; return 0; }
r[3]<<=2;
goto P_0c0a2a14;
P_0c0a2a14: /* original 4308, guest PC 0x0c0a2a14 */
if(!s->budget--) { s->failed_pc=0x0c0a2a14u; return 0; }
r[3]<<=2;
goto P_0c0a2a16;
P_0c0a2a16: /* original 33cc, guest PC 0x0c0a2a16 */
if(!s->budget--) { s->failed_pc=0x0c0a2a16u; return 0; }
r[3]+=r[12];
goto P_0c0a2a18;
P_0c0a2a18: /* original 5232, guest PC 0x0c0a2a18 */
if(!s->budget--) { s->failed_pc=0x0c0a2a18u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2a1a;
P_0c0a2a1a: /* original 7401, guest PC 0x0c0a2a1a */
if(!s->budget--) { s->failed_pc=0x0c0a2a1au; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2a1c;
P_0c0a2a1c: /* original 32a8, guest PC 0x0c0a2a1c */
if(!s->budget--) { s->failed_pc=0x0c0a2a1cu; return 0; }
r[2]-=r[10];
goto P_0c0a2a1e;
P_0c0a2a1e: /* original 1322, guest PC 0x0c0a2a1e */
if(!s->budget--) { s->failed_pc=0x0c0a2a1eu; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2a20;
P_0c0a2a20: /* original 85e7, guest PC 0x0c0a2a20 */
if(!s->budget--) { s->failed_pc=0x0c0a2a20u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a22;
P_0c0a2a22: /* original 600d, guest PC 0x0c0a2a22 */
if(!s->budget--) { s->failed_pc=0x0c0a2a22u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a24;
P_0c0a2a24: /* original 3403, guest PC 0x0c0a2a24 */
if(!s->budget--) { s->failed_pc=0x0c0a2a24u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2a26;
P_0c0a2a26: /* original 8bf3, guest PC 0x0c0a2a26 */
if(!s->budget--) { s->failed_pc=0x0c0a2a26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2a10; }
goto P_0c0a2a28;
P_0c0a2a28: /* original a00d, guest PC 0x0c0a2a28 */
if(!s->budget--) { s->failed_pc=0x0c0a2a28u; return 0; }
goto P_0c0a2a46;
P_0c0a2a2a: /* original 0009, guest PC 0x0c0a2a2a */
if(!s->budget--) { s->failed_pc=0x0c0a2a2au; return 0; }
goto P_0c0a2a2c;
P_0c0a2a2c: /* original 64d2, guest PC 0x0c0a2a2c */
if(!s->budget--) { s->failed_pc=0x0c0a2a2cu; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0a2a2e;
P_0c0a2a2e: /* original 66a3, guest PC 0x0c0a2a2e */
if(!s->budget--) { s->failed_pc=0x0c0a2a2eu; return 0; }
r[6]=r[10];
goto P_0c0a2a30;
P_0c0a2a30: /* original d355, guest PC 0x0c0a2a30 */
if(!s->budget--) { s->failed_pc=0x0c0a2a30u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2a32;
P_0c0a2a32: /* original 65c3, guest PC 0x0c0a2a32 */
if(!s->budget--) { s->failed_pc=0x0c0a2a32u; return 0; }
r[5]=r[12];
goto P_0c0a2a34;
P_0c0a2a34: /* original 430b, guest PC 0x0c0a2a34 */
if(!s->budget--) { s->failed_pc=0x0c0a2a34u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a38u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a38u) { target=s->pc; goto dispatch; }
goto P_0c0a2a38;
P_0c0a2a36: /* original 5441, guest PC 0x0c0a2a36 */
if(!s->budget--) { s->failed_pc=0x0c0a2a36u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2a38;
P_0c0a2a38: /* original 69d2, guest PC 0x0c0a2a38 */
if(!s->budget--) { s->failed_pc=0x0c0a2a38u; return 0; }
tmp=read(ram,r[13],4);
r[9]=tmp;
goto P_0c0a2a3a;
P_0c0a2a3a: /* original 2008, guest PC 0x0c0a2a3a */
if(!s->budget--) { s->failed_pc=0x0c0a2a3au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2a3c;
P_0c0a2a3c: /* original d353, guest PC 0x0c0a2a3c */
if(!s->budget--) { s->failed_pc=0x0c0a2a3cu; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2a3e;
P_0c0a2a3e: /* original 5591, guest PC 0x0c0a2a3e */
if(!s->budget--) { s->failed_pc=0x0c0a2a3eu; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2a40;
P_0c0a2a40: /* original 5692, guest PC 0x0c0a2a40 */
if(!s->budget--) { s->failed_pc=0x0c0a2a40u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2a42;
P_0c0a2a42: /* original 430b, guest PC 0x0c0a2a42 */
if(!s->budget--) { s->failed_pc=0x0c0a2a42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2a46u;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a46u) { target=s->pc; goto dispatch; }
goto P_0c0a2a46;
P_0c0a2a44: /* original 6492, guest PC 0x0c0a2a44 */
if(!s->budget--) { s->failed_pc=0x0c0a2a44u; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2a46;
P_0c0a2a46: /* original 7801, guest PC 0x0c0a2a46 */
if(!s->budget--) { s->failed_pc=0x0c0a2a46u; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2a48;
P_0c0a2a48: /* original 85e6, guest PC 0x0c0a2a48 */
if(!s->budget--) { s->failed_pc=0x0c0a2a48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2a4a;
P_0c0a2a4a: /* original 600d, guest PC 0x0c0a2a4a */
if(!s->budget--) { s->failed_pc=0x0c0a2a4au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2a4c;
P_0c0a2a4c: /* original 3803, guest PC 0x0c0a2a4c */
if(!s->budget--) { s->failed_pc=0x0c0a2a4cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2a4e;
P_0c0a2a4e: /* original 8bc2, guest PC 0x0c0a2a4e */
if(!s->budget--) { s->failed_pc=0x0c0a2a4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a29d6; }
goto P_0c0a2a50;
P_0c0a2a50: /* original 63f1, guest PC 0x0c0a2a50 */
if(!s->budget--) { s->failed_pc=0x0c0a2a50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2a52;
P_0c0a2a52: /* original e222, guest PC 0x0c0a2a52 */
if(!s->budget--) { s->failed_pc=0x0c0a2a52u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2a54;
P_0c0a2a54: /* original 85e7, guest PC 0x0c0a2a54 */
if(!s->budget--) { s->failed_pc=0x0c0a2a54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2a56;
P_0c0a2a56: /* original 32ec, guest PC 0x0c0a2a56 */
if(!s->budget--) { s->failed_pc=0x0c0a2a56u; return 0; }
r[2]+=r[14];
goto P_0c0a2a58;
P_0c0a2a58: /* original 64b3, guest PC 0x0c0a2a58 */
if(!s->budget--) { s->failed_pc=0x0c0a2a58u; return 0; }
r[4]=r[11];
goto P_0c0a2a5a;
P_0c0a2a5a: /* original 303c, guest PC 0x0c0a2a5a */
if(!s->budget--) { s->failed_pc=0x0c0a2a5au; return 0; }
r[0]+=r[3];
goto P_0c0a2a5c;
P_0c0a2a5c: /* original 2201, guest PC 0x0c0a2a5c */
if(!s->budget--) { s->failed_pc=0x0c0a2a5cu; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2a5e;
P_0c0a2a5e: /* original 7f08, guest PC 0x0c0a2a5e */
if(!s->budget--) { s->failed_pc=0x0c0a2a5eu; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2a60;
P_0c0a2a60: /* original 6043, guest PC 0x0c0a2a60 */
if(!s->budget--) { s->failed_pc=0x0c0a2a60u; return 0; }
r[0]=r[4];
goto P_0c0a2a62;
P_0c0a2a62: /* original 4f26, guest PC 0x0c0a2a62 */
if(!s->budget--) { s->failed_pc=0x0c0a2a62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2a64;
P_0c0a2a64: /* original 68f6, guest PC 0x0c0a2a64 */
if(!s->budget--) { s->failed_pc=0x0c0a2a64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2a66;
P_0c0a2a66: /* original 69f6, guest PC 0x0c0a2a66 */
if(!s->budget--) { s->failed_pc=0x0c0a2a66u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2a68;
P_0c0a2a68: /* original 6af6, guest PC 0x0c0a2a68 */
if(!s->budget--) { s->failed_pc=0x0c0a2a68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2a6a;
P_0c0a2a6a: /* original 6bf6, guest PC 0x0c0a2a6a */
if(!s->budget--) { s->failed_pc=0x0c0a2a6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2a6c;
P_0c0a2a6c: /* original 6cf6, guest PC 0x0c0a2a6c */
if(!s->budget--) { s->failed_pc=0x0c0a2a6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2a6e;
P_0c0a2a6e: /* original 6df6, guest PC 0x0c0a2a6e */
if(!s->budget--) { s->failed_pc=0x0c0a2a6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2a70;
P_0c0a2a70: /* original 000b, guest PC 0x0c0a2a70 */
if(!s->budget--) { s->failed_pc=0x0c0a2a70u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2a72: /* original 6ef6, guest PC 0x0c0a2a72 */
if(!s->budget--) { s->failed_pc=0x0c0a2a72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2a74;
P_0c0a2a74: /* original 2fe6, guest PC 0x0c0a2a74 */
if(!s->budget--) { s->failed_pc=0x0c0a2a74u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a76;
P_0c0a2a76: /* original 6e43, guest PC 0x0c0a2a76 */
if(!s->budget--) { s->failed_pc=0x0c0a2a76u; return 0; }
r[14]=r[4];
goto P_0c0a2a78;
P_0c0a2a78: /* original 2fd6, guest PC 0x0c0a2a78 */
if(!s->budget--) { s->failed_pc=0x0c0a2a78u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a7a;
P_0c0a2a7a: /* original 2fc6, guest PC 0x0c0a2a7a */
if(!s->budget--) { s->failed_pc=0x0c0a2a7au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a7c;
P_0c0a2a7c: /* original 2fb6, guest PC 0x0c0a2a7c */
if(!s->budget--) { s->failed_pc=0x0c0a2a7cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a7e;
P_0c0a2a7e: /* original 2fa6, guest PC 0x0c0a2a7e */
if(!s->budget--) { s->failed_pc=0x0c0a2a7eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a80;
P_0c0a2a80: /* original 2f96, guest PC 0x0c0a2a80 */
if(!s->budget--) { s->failed_pc=0x0c0a2a80u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a82;
P_0c0a2a82: /* original 2f86, guest PC 0x0c0a2a82 */
if(!s->budget--) { s->failed_pc=0x0c0a2a82u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2a84;
P_0c0a2a84: /* original 4f22, guest PC 0x0c0a2a84 */
if(!s->budget--) { s->failed_pc=0x0c0a2a84u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2a86;
P_0c0a2a86: /* original 7ff4, guest PC 0x0c0a2a86 */
if(!s->budget--) { s->failed_pc=0x0c0a2a86u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a2a88;
P_0c0a2a88: /* original 2f61, guest PC 0x0c0a2a88 */
if(!s->budget--) { s->failed_pc=0x0c0a2a88u; return 0; }
write(ram,r[15],r[6],2);
goto P_0c0a2a8a;
P_0c0a2a8a: /* original 1f72, guest PC 0x0c0a2a8a */
if(!s->budget--) { s->failed_pc=0x0c0a2a8au; return 0; }
write(ram,r[15]+8,r[7],4);
goto P_0c0a2a8c;
P_0c0a2a8c: /* original b0d3, guest PC 0x0c0a2a8c */
if(!s->budget--) { s->failed_pc=0x0c0a2a8cu; return 0; }
target=code_base|0x0c0a2c36u; r[16]=code_base|0x0c0a2a90u;
r[11]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2a90u) { target=s->pc; goto dispatch; }
goto P_0c0a2a90;
P_0c0a2a8e: /* original 6b53, guest PC 0x0c0a2a8e */
if(!s->budget--) { s->failed_pc=0x0c0a2a8eu; return 0; }
r[11]=r[5];
goto P_0c0a2a90;
P_0c0a2a90: /* original 6d03, guest PC 0x0c0a2a90 */
if(!s->budget--) { s->failed_pc=0x0c0a2a90u; return 0; }
r[13]=r[0];
goto P_0c0a2a92;
P_0c0a2a92: /* original 2dd8, guest PC 0x0c0a2a92 */
if(!s->budget--) { s->failed_pc=0x0c0a2a92u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a2a94;
P_0c0a2a94: /* original 8902, guest PC 0x0c0a2a94 */
if(!s->budget--) { s->failed_pc=0x0c0a2a94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2a9c; }
goto P_0c0a2a96;
P_0c0a2a96: /* original d339, guest PC 0x0c0a2a96 */
if(!s->budget--) { s->failed_pc=0x0c0a2a96u; return 0; }
r[3]=read(ram,0x0c0a2b7cu,4);
goto P_0c0a2a98;
P_0c0a2a98: /* original 3d30, guest PC 0x0c0a2a98 */
if(!s->budget--) { s->failed_pc=0x0c0a2a98u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0a2a9a;
P_0c0a2a9a: /* original 8b60, guest PC 0x0c0a2a9a */
if(!s->budget--) { s->failed_pc=0x0c0a2a9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b5e; }
goto P_0c0a2a9c;
P_0c0a2a9c: /* original e020, guest PC 0x0c0a2a9c */
if(!s->budget--) { s->failed_pc=0x0c0a2a9cu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2a9e;
P_0c0a2a9e: /* original 01ed, guest PC 0x0c0a2a9e */
if(!s->budget--) { s->failed_pc=0x0c0a2a9eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2aa0;
P_0c0a2aa0: /* original e022, guest PC 0x0c0a2aa0 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa0u; return 0; }
r[0]=0x00000022u;
goto P_0c0a2aa2;
P_0c0a2aa2: /* original 03ed, guest PC 0x0c0a2aa2 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2aa4;
P_0c0a2aa4: /* original 611d, guest PC 0x0c0a2aa4 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c0a2aa6;
P_0c0a2aa6: /* original 633d, guest PC 0x0c0a2aa6 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa6u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0a2aa8;
P_0c0a2aa8: /* original 213b, guest PC 0x0c0a2aa8 */
if(!s->budget--) { s->failed_pc=0x0c0a2aa8u; return 0; }
r[1]|=r[3];
goto P_0c0a2aaa;
P_0c0a2aaa: /* original 2118, guest PC 0x0c0a2aaa */
if(!s->budget--) { s->failed_pc=0x0c0a2aaau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0a2aac;
P_0c0a2aac: /* original 8b5b, guest PC 0x0c0a2aac */
if(!s->budget--) { s->failed_pc=0x0c0a2aacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b66; }
goto P_0c0a2aae;
P_0c0a2aae: /* original e020, guest PC 0x0c0a2aae */
if(!s->budget--) { s->failed_pc=0x0c0a2aaeu; return 0; }
r[0]=0x00000020u;
goto P_0c0a2ab0;
P_0c0a2ab0: /* original 52e4, guest PC 0x0c0a2ab0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab0u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c0a2ab2;
P_0c0a2ab2: /* original 1f21, guest PC 0x0c0a2ab2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab2u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2ab4;
P_0c0a2ab4: /* original 63f1, guest PC 0x0c0a2ab4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab4u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2ab6;
P_0c0a2ab6: /* original 5de5, guest PC 0x0c0a2ab6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab6u; return 0; }
r[13]=read(ram,r[14]+20,4);
goto P_0c0a2ab8;
P_0c0a2ab8: /* original 0e35, guest PC 0x0c0a2ab8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ab8u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0a2aba;
P_0c0a2aba: /* original 04ed, guest PC 0x0c0a2aba */
if(!s->budget--) { s->failed_pc=0x0c0a2abau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a2abc;
P_0c0a2abc: /* original d330, guest PC 0x0c0a2abc */
if(!s->budget--) { s->failed_pc=0x0c0a2abcu; return 0; }
r[3]=read(ram,0x0c0a2b80u,4);
goto P_0c0a2abe;
P_0c0a2abe: /* original 430b, guest PC 0x0c0a2abe */
if(!s->budget--) { s->failed_pc=0x0c0a2abeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ac2u;
r[4]=r[4]&65535u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ac2u) { target=s->pc; goto dispatch; }
goto P_0c0a2ac2;
P_0c0a2ac0: /* original 644d, guest PC 0x0c0a2ac0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac0u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a2ac2;
P_0c0a2ac2: /* original d333, guest PC 0x0c0a2ac2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac2u; return 0; }
r[3]=read(ram,0x0c0a2b90u,4);
goto P_0c0a2ac4;
P_0c0a2ac4: /* original 430b, guest PC 0x0c0a2ac4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2ac8u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2ac8u) { target=s->pc; goto dispatch; }
goto P_0c0a2ac8;
P_0c0a2ac6: /* original 54f2, guest PC 0x0c0a2ac6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac6u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0a2ac8;
P_0c0a2ac8: /* original ea00, guest PC 0x0c0a2ac8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ac8u; return 0; }
r[10]=0x00000000u;
goto P_0c0a2aca;
P_0c0a2aca: /* original a039, guest PC 0x0c0a2aca */
if(!s->budget--) { s->failed_pc=0x0c0a2acau; return 0; }
r[8]=r[10];
goto P_0c0a2b40;
P_0c0a2acc: /* original 68a3, guest PC 0x0c0a2acc */
if(!s->budget--) { s->failed_pc=0x0c0a2accu; return 0; }
r[8]=r[10];
goto P_0c0a2ace;
P_0c0a2ace: /* original 53f1, guest PC 0x0c0a2ace */
if(!s->budget--) { s->failed_pc=0x0c0a2aceu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0a2ad0;
P_0c0a2ad0: /* original 6c83, guest PC 0x0c0a2ad0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad0u; return 0; }
r[12]=r[8];
goto P_0c0a2ad2;
P_0c0a2ad2: /* original 4c08, guest PC 0x0c0a2ad2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad2u; return 0; }
r[12]<<=2;
goto P_0c0a2ad4;
P_0c0a2ad4: /* original 3c3c, guest PC 0x0c0a2ad4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad4u; return 0; }
r[12]+=r[3];
goto P_0c0a2ad6;
P_0c0a2ad6: /* original 60c2, guest PC 0x0c0a2ad6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad6u; return 0; }
tmp=read(ram,r[12],4);
r[0]=tmp;
goto P_0c0a2ad8;
P_0c0a2ad8: /* original 5001, guest PC 0x0c0a2ad8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ad8u; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c0a2ada;
P_0c0a2ada: /* original c801, guest PC 0x0c0a2ada */
if(!s->budget--) { s->failed_pc=0x0c0a2adau; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c0a2adc;
P_0c0a2adc: /* original 8922, guest PC 0x0c0a2adc */
if(!s->budget--) { s->failed_pc=0x0c0a2adcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2b24; }
goto P_0c0a2ade;
P_0c0a2ade: /* original a008, guest PC 0x0c0a2ade */
if(!s->budget--) { s->failed_pc=0x0c0a2adeu; return 0; }
r[4]=r[10];
goto P_0c0a2af2;
P_0c0a2ae0: /* original 64a3, guest PC 0x0c0a2ae0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae0u; return 0; }
r[4]=r[10];
goto P_0c0a2ae2;
P_0c0a2ae2: /* original 6343, guest PC 0x0c0a2ae2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae2u; return 0; }
r[3]=r[4];
goto P_0c0a2ae4;
P_0c0a2ae4: /* original 4308, guest PC 0x0c0a2ae4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae4u; return 0; }
r[3]<<=2;
goto P_0c0a2ae6;
P_0c0a2ae6: /* original 4308, guest PC 0x0c0a2ae6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae6u; return 0; }
r[3]<<=2;
goto P_0c0a2ae8;
P_0c0a2ae8: /* original 33dc, guest PC 0x0c0a2ae8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ae8u; return 0; }
r[3]+=r[13];
goto P_0c0a2aea;
P_0c0a2aea: /* original 5232, guest PC 0x0c0a2aea */
if(!s->budget--) { s->failed_pc=0x0c0a2aeau; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2aec;
P_0c0a2aec: /* original 7401, guest PC 0x0c0a2aec */
if(!s->budget--) { s->failed_pc=0x0c0a2aecu; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2aee;
P_0c0a2aee: /* original 32bc, guest PC 0x0c0a2aee */
if(!s->budget--) { s->failed_pc=0x0c0a2aeeu; return 0; }
r[2]+=r[11];
goto P_0c0a2af0;
P_0c0a2af0: /* original 1322, guest PC 0x0c0a2af0 */
if(!s->budget--) { s->failed_pc=0x0c0a2af0u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2af2;
P_0c0a2af2: /* original 85e7, guest PC 0x0c0a2af2 */
if(!s->budget--) { s->failed_pc=0x0c0a2af2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2af4;
P_0c0a2af4: /* original 600d, guest PC 0x0c0a2af4 */
if(!s->budget--) { s->failed_pc=0x0c0a2af4u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2af6;
P_0c0a2af6: /* original 3403, guest PC 0x0c0a2af6 */
if(!s->budget--) { s->failed_pc=0x0c0a2af6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2af8;
P_0c0a2af8: /* original 8bf3, guest PC 0x0c0a2af8 */
if(!s->budget--) { s->failed_pc=0x0c0a2af8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2ae2; }
goto P_0c0a2afa;
P_0c0a2afa: /* original d222, guest PC 0x0c0a2afa */
if(!s->budget--) { s->failed_pc=0x0c0a2afau; return 0; }
r[2]=read(ram,0x0c0a2b84u,4);
goto P_0c0a2afc;
P_0c0a2afc: /* original 65d3, guest PC 0x0c0a2afc */
if(!s->budget--) { s->failed_pc=0x0c0a2afcu; return 0; }
r[5]=r[13];
goto P_0c0a2afe;
P_0c0a2afe: /* original 420b, guest PC 0x0c0a2afe */
if(!s->budget--) { s->failed_pc=0x0c0a2afeu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b02u;
tmp=read(ram,r[12],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b02u) { target=s->pc; goto dispatch; }
goto P_0c0a2b02;
P_0c0a2b00: /* original 64c2, guest PC 0x0c0a2b00 */
if(!s->budget--) { s->failed_pc=0x0c0a2b00u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a2b02;
P_0c0a2b02: /* original 2008, guest PC 0x0c0a2b02 */
if(!s->budget--) { s->failed_pc=0x0c0a2b02u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2b04;
P_0c0a2b04: /* original a008, guest PC 0x0c0a2b04 */
if(!s->budget--) { s->failed_pc=0x0c0a2b04u; return 0; }
r[4]=r[10];
goto P_0c0a2b18;
P_0c0a2b06: /* original 64a3, guest PC 0x0c0a2b06 */
if(!s->budget--) { s->failed_pc=0x0c0a2b06u; return 0; }
r[4]=r[10];
goto P_0c0a2b08;
P_0c0a2b08: /* original 6343, guest PC 0x0c0a2b08 */
if(!s->budget--) { s->failed_pc=0x0c0a2b08u; return 0; }
r[3]=r[4];
goto P_0c0a2b0a;
P_0c0a2b0a: /* original 4308, guest PC 0x0c0a2b0a */
if(!s->budget--) { s->failed_pc=0x0c0a2b0au; return 0; }
r[3]<<=2;
goto P_0c0a2b0c;
P_0c0a2b0c: /* original 4308, guest PC 0x0c0a2b0c */
if(!s->budget--) { s->failed_pc=0x0c0a2b0cu; return 0; }
r[3]<<=2;
goto P_0c0a2b0e;
P_0c0a2b0e: /* original 33dc, guest PC 0x0c0a2b0e */
if(!s->budget--) { s->failed_pc=0x0c0a2b0eu; return 0; }
r[3]+=r[13];
goto P_0c0a2b10;
P_0c0a2b10: /* original 5232, guest PC 0x0c0a2b10 */
if(!s->budget--) { s->failed_pc=0x0c0a2b10u; return 0; }
r[2]=read(ram,r[3]+8,4);
goto P_0c0a2b12;
P_0c0a2b12: /* original 7401, guest PC 0x0c0a2b12 */
if(!s->budget--) { s->failed_pc=0x0c0a2b12u; return 0; }
r[4]+=0x00000001u;
goto P_0c0a2b14;
P_0c0a2b14: /* original 32b8, guest PC 0x0c0a2b14 */
if(!s->budget--) { s->failed_pc=0x0c0a2b14u; return 0; }
r[2]-=r[11];
goto P_0c0a2b16;
P_0c0a2b16: /* original 1322, guest PC 0x0c0a2b16 */
if(!s->budget--) { s->failed_pc=0x0c0a2b16u; return 0; }
write(ram,r[3]+8,r[2],4);
goto P_0c0a2b18;
P_0c0a2b18: /* original 85e7, guest PC 0x0c0a2b18 */
if(!s->budget--) { s->failed_pc=0x0c0a2b18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2b1a;
P_0c0a2b1a: /* original 600d, guest PC 0x0c0a2b1a */
if(!s->budget--) { s->failed_pc=0x0c0a2b1au; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2b1c;
P_0c0a2b1c: /* original 3403, guest PC 0x0c0a2b1c */
if(!s->budget--) { s->failed_pc=0x0c0a2b1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[0])!=0);
goto P_0c0a2b1e;
P_0c0a2b1e: /* original 8bf3, guest PC 0x0c0a2b1e */
if(!s->budget--) { s->failed_pc=0x0c0a2b1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2b08; }
goto P_0c0a2b20;
P_0c0a2b20: /* original a00d, guest PC 0x0c0a2b20 */
if(!s->budget--) { s->failed_pc=0x0c0a2b20u; return 0; }
goto P_0c0a2b3e;
P_0c0a2b22: /* original 0009, guest PC 0x0c0a2b22 */
if(!s->budget--) { s->failed_pc=0x0c0a2b22u; return 0; }
goto P_0c0a2b24;
P_0c0a2b24: /* original 64c2, guest PC 0x0c0a2b24 */
if(!s->budget--) { s->failed_pc=0x0c0a2b24u; return 0; }
tmp=read(ram,r[12],4);
r[4]=tmp;
goto P_0c0a2b26;
P_0c0a2b26: /* original 66b3, guest PC 0x0c0a2b26 */
if(!s->budget--) { s->failed_pc=0x0c0a2b26u; return 0; }
r[6]=r[11];
goto P_0c0a2b28;
P_0c0a2b28: /* original d317, guest PC 0x0c0a2b28 */
if(!s->budget--) { s->failed_pc=0x0c0a2b28u; return 0; }
r[3]=read(ram,0x0c0a2b88u,4);
goto P_0c0a2b2a;
P_0c0a2b2a: /* original 65d3, guest PC 0x0c0a2b2a */
if(!s->budget--) { s->failed_pc=0x0c0a2b2au; return 0; }
r[5]=r[13];
goto P_0c0a2b2c;
P_0c0a2b2c: /* original 430b, guest PC 0x0c0a2b2c */
if(!s->budget--) { s->failed_pc=0x0c0a2b2cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2b30u;
r[4]=read(ram,r[4]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b30u) { target=s->pc; goto dispatch; }
goto P_0c0a2b30;
P_0c0a2b2e: /* original 5441, guest PC 0x0c0a2b2e */
if(!s->budget--) { s->failed_pc=0x0c0a2b2eu; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0a2b30;
P_0c0a2b30: /* original 69c2, guest PC 0x0c0a2b30 */
if(!s->budget--) { s->failed_pc=0x0c0a2b30u; return 0; }
tmp=read(ram,r[12],4);
r[9]=tmp;
goto P_0c0a2b32;
P_0c0a2b32: /* original 2008, guest PC 0x0c0a2b32 */
if(!s->budget--) { s->failed_pc=0x0c0a2b32u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0a2b34;
P_0c0a2b34: /* original d315, guest PC 0x0c0a2b34 */
if(!s->budget--) { s->failed_pc=0x0c0a2b34u; return 0; }
r[3]=read(ram,0x0c0a2b8cu,4);
goto P_0c0a2b36;
P_0c0a2b36: /* original 5591, guest PC 0x0c0a2b36 */
if(!s->budget--) { s->failed_pc=0x0c0a2b36u; return 0; }
r[5]=read(ram,r[9]+4,4);
goto P_0c0a2b38;
P_0c0a2b38: /* original 5692, guest PC 0x0c0a2b38 */
if(!s->budget--) { s->failed_pc=0x0c0a2b38u; return 0; }
r[6]=read(ram,r[9]+8,4);
goto P_0c0a2b3a;
P_0c0a2b3a: /* original 430b, guest PC 0x0c0a2b3a */
if(!s->budget--) { s->failed_pc=0x0c0a2b3au; return 0; }
target=r[3];
r[16]=code_base|0x0c0a2b3eu;
tmp=read(ram,r[9],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b3eu) { target=s->pc; goto dispatch; }
goto P_0c0a2b3e;
P_0c0a2b3c: /* original 6492, guest PC 0x0c0a2b3c */
if(!s->budget--) { s->failed_pc=0x0c0a2b3cu; return 0; }
tmp=read(ram,r[9],4);
r[4]=tmp;
goto P_0c0a2b3e;
P_0c0a2b3e: /* original 7801, guest PC 0x0c0a2b3e */
if(!s->budget--) { s->failed_pc=0x0c0a2b3eu; return 0; }
r[8]+=0x00000001u;
goto P_0c0a2b40;
P_0c0a2b40: /* original 85e6, guest PC 0x0c0a2b40 */
if(!s->budget--) { s->failed_pc=0x0c0a2b40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+12,2);
goto P_0c0a2b42;
P_0c0a2b42: /* original 600d, guest PC 0x0c0a2b42 */
if(!s->budget--) { s->failed_pc=0x0c0a2b42u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2b44;
P_0c0a2b44: /* original 3803, guest PC 0x0c0a2b44 */
if(!s->budget--) { s->failed_pc=0x0c0a2b44u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>=(int32_t)r[0])!=0);
goto P_0c0a2b46;
P_0c0a2b46: /* original 8bc2, guest PC 0x0c0a2b46 */
if(!s->budget--) { s->failed_pc=0x0c0a2b46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2ace; }
goto P_0c0a2b48;
P_0c0a2b48: /* original d211, guest PC 0x0c0a2b48 */
if(!s->budget--) { s->failed_pc=0x0c0a2b48u; return 0; }
r[2]=read(ram,0x0c0a2b90u,4);
goto P_0c0a2b4a;
P_0c0a2b4a: /* original 420b, guest PC 0x0c0a2b4a */
if(!s->budget--) { s->failed_pc=0x0c0a2b4au; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b4eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b4eu) { target=s->pc; goto dispatch; }
goto P_0c0a2b4e;
P_0c0a2b4c: /* original e400, guest PC 0x0c0a2b4c */
if(!s->budget--) { s->failed_pc=0x0c0a2b4cu; return 0; }
r[4]=0x00000000u;
goto P_0c0a2b4e;
P_0c0a2b4e: /* original 63f1, guest PC 0x0c0a2b4e */
if(!s->budget--) { s->failed_pc=0x0c0a2b4eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[3]=tmp;
goto P_0c0a2b50;
P_0c0a2b50: /* original e222, guest PC 0x0c0a2b50 */
if(!s->budget--) { s->failed_pc=0x0c0a2b50u; return 0; }
r[2]=0x00000022u;
goto P_0c0a2b52;
P_0c0a2b52: /* original 85e7, guest PC 0x0c0a2b52 */
if(!s->budget--) { s->failed_pc=0x0c0a2b52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+14,2);
goto P_0c0a2b54;
P_0c0a2b54: /* original 32ec, guest PC 0x0c0a2b54 */
if(!s->budget--) { s->failed_pc=0x0c0a2b54u; return 0; }
r[2]+=r[14];
goto P_0c0a2b56;
P_0c0a2b56: /* original 303c, guest PC 0x0c0a2b56 */
if(!s->budget--) { s->failed_pc=0x0c0a2b56u; return 0; }
r[0]+=r[3];
goto P_0c0a2b58;
P_0c0a2b58: /* original 2201, guest PC 0x0c0a2b58 */
if(!s->budget--) { s->failed_pc=0x0c0a2b58u; return 0; }
write(ram,r[2],r[0],2);
goto P_0c0a2b5a;
P_0c0a2b5a: /* original a004, guest PC 0x0c0a2b5a */
if(!s->budget--) { s->failed_pc=0x0c0a2b5au; return 0; }
r[13]=0x00000000u;
goto P_0c0a2b66;
P_0c0a2b5c: /* original ed00, guest PC 0x0c0a2b5c */
if(!s->budget--) { s->failed_pc=0x0c0a2b5cu; return 0; }
r[13]=0x00000000u;
goto P_0c0a2b5e;
P_0c0a2b5e: /* original d20d, guest PC 0x0c0a2b5e */
if(!s->budget--) { s->failed_pc=0x0c0a2b5eu; return 0; }
r[2]=read(ram,0x0c0a2b94u,4);
goto P_0c0a2b60;
P_0c0a2b60: /* original e57e, guest PC 0x0c0a2b60 */
if(!s->budget--) { s->failed_pc=0x0c0a2b60u; return 0; }
r[5]=0x0000007eu;
goto P_0c0a2b62;
P_0c0a2b62: /* original 420b, guest PC 0x0c0a2b62 */
if(!s->budget--) { s->failed_pc=0x0c0a2b62u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a2b66u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2b66u) { target=s->pc; goto dispatch; }
goto P_0c0a2b66;
P_0c0a2b64: /* original e401, guest PC 0x0c0a2b64 */
if(!s->budget--) { s->failed_pc=0x0c0a2b64u; return 0; }
r[4]=0x00000001u;
goto P_0c0a2b66;
P_0c0a2b66: /* original 7f0c, guest PC 0x0c0a2b66 */
if(!s->budget--) { s->failed_pc=0x0c0a2b66u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a2b68;
P_0c0a2b68: /* original 60d3, guest PC 0x0c0a2b68 */
if(!s->budget--) { s->failed_pc=0x0c0a2b68u; return 0; }
r[0]=r[13];
goto P_0c0a2b6a;
P_0c0a2b6a: /* original 4f26, guest PC 0x0c0a2b6a */
if(!s->budget--) { s->failed_pc=0x0c0a2b6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2b6c;
P_0c0a2b6c: /* original 68f6, guest PC 0x0c0a2b6c */
if(!s->budget--) { s->failed_pc=0x0c0a2b6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2b6e;
P_0c0a2b6e: /* original 69f6, guest PC 0x0c0a2b6e */
if(!s->budget--) { s->failed_pc=0x0c0a2b6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2b70;
P_0c0a2b70: /* original 6af6, guest PC 0x0c0a2b70 */
if(!s->budget--) { s->failed_pc=0x0c0a2b70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2b72;
P_0c0a2b72: /* original 6bf6, guest PC 0x0c0a2b72 */
if(!s->budget--) { s->failed_pc=0x0c0a2b72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2b74;
P_0c0a2b74: /* original 6cf6, guest PC 0x0c0a2b74 */
if(!s->budget--) { s->failed_pc=0x0c0a2b74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2b76;
P_0c0a2b76: /* original 6df6, guest PC 0x0c0a2b76 */
if(!s->budget--) { s->failed_pc=0x0c0a2b76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2b78;
P_0c0a2b78: /* original 000b, guest PC 0x0c0a2b78 */
if(!s->budget--) { s->failed_pc=0x0c0a2b78u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2b7a: /* original 6ef6, guest PC 0x0c0a2b7a */
if(!s->budget--) { s->failed_pc=0x0c0a2b7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2b7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2b7cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
