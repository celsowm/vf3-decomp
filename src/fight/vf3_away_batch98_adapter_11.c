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
int vf3_away_batch98_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c5a74u: goto P_0c0c5a74;
case 0x0c0c5a76u: goto P_0c0c5a76;
case 0x0c0c5a78u: goto P_0c0c5a78;
case 0x0c0c5a7au: goto P_0c0c5a7a;
case 0x0c0c5a7cu: goto P_0c0c5a7c;
case 0x0c0c5a7eu: goto P_0c0c5a7e;
case 0x0c0c5a80u: goto P_0c0c5a80;
case 0x0c0c5a82u: goto P_0c0c5a82;
case 0x0c0c5a84u: goto P_0c0c5a84;
case 0x0c0c5a86u: goto P_0c0c5a86;
case 0x0c0c5a88u: goto P_0c0c5a88;
case 0x0c0c5a8au: goto P_0c0c5a8a;
case 0x0c0c5a8cu: goto P_0c0c5a8c;
case 0x0c0c5a8eu: goto P_0c0c5a8e;
case 0x0c0c5a90u: goto P_0c0c5a90;
case 0x0c0c5a92u: goto P_0c0c5a92;
case 0x0c0c5a94u: goto P_0c0c5a94;
case 0x0c0c5a96u: goto P_0c0c5a96;
case 0x0c0c5a98u: goto P_0c0c5a98;
case 0x0c0c5a9au: goto P_0c0c5a9a;
case 0x0c0c5a9cu: goto P_0c0c5a9c;
case 0x0c0c5a9eu: goto P_0c0c5a9e;
case 0x0c0c5aa0u: goto P_0c0c5aa0;
case 0x0c0c5aa2u: goto P_0c0c5aa2;
case 0x0c0c5aa4u: goto P_0c0c5aa4;
case 0x0c0c5aa6u: goto P_0c0c5aa6;
case 0x0c0c5aa8u: goto P_0c0c5aa8;
case 0x0c0c5aaau: goto P_0c0c5aaa;
case 0x0c0c5aacu: goto P_0c0c5aac;
case 0x0c0c5aaeu: goto P_0c0c5aae;
case 0x0c0c5ab0u: goto P_0c0c5ab0;
case 0x0c0c5ab2u: goto P_0c0c5ab2;
case 0x0c0c5ab4u: goto P_0c0c5ab4;
case 0x0c0c5ab6u: goto P_0c0c5ab6;
case 0x0c0c5ab8u: goto P_0c0c5ab8;
case 0x0c0c5abau: goto P_0c0c5aba;
case 0x0c0c5abcu: goto P_0c0c5abc;
case 0x0c0c5abeu: goto P_0c0c5abe;
case 0x0c0c5ac0u: goto P_0c0c5ac0;
case 0x0c0c5ac2u: goto P_0c0c5ac2;
case 0x0c0c5ac4u: goto P_0c0c5ac4;
case 0x0c0c5ac6u: goto P_0c0c5ac6;
case 0x0c0c5ac8u: goto P_0c0c5ac8;
case 0x0c0c5acau: goto P_0c0c5aca;
case 0x0c0c5accu: goto P_0c0c5acc;
case 0x0c0c5aceu: goto P_0c0c5ace;
case 0x0c0c5ad0u: goto P_0c0c5ad0;
case 0x0c0c5ad2u: goto P_0c0c5ad2;
case 0x0c0c5ad4u: goto P_0c0c5ad4;
case 0x0c0c5ad6u: goto P_0c0c5ad6;
case 0x0c0c5ad8u: goto P_0c0c5ad8;
case 0x0c0c5adau: goto P_0c0c5ada;
case 0x0c0c5adcu: goto P_0c0c5adc;
case 0x0c0c5adeu: goto P_0c0c5ade;
case 0x0c0c5ae0u: goto P_0c0c5ae0;
case 0x0c0c5ae2u: goto P_0c0c5ae2;
case 0x0c0c5ae4u: goto P_0c0c5ae4;
case 0x0c0c5ae6u: goto P_0c0c5ae6;
case 0x0c0c5ae8u: goto P_0c0c5ae8;
case 0x0c0c5aeau: goto P_0c0c5aea;
case 0x0c0c5aecu: goto P_0c0c5aec;
case 0x0c0c5b08u: goto P_0c0c5b08;
case 0x0c0c5b0au: goto P_0c0c5b0a;
case 0x0c0c5b0cu: goto P_0c0c5b0c;
case 0x0c0c5b0eu: goto P_0c0c5b0e;
case 0x0c0c5b10u: goto P_0c0c5b10;
case 0x0c0c5b12u: goto P_0c0c5b12;
case 0x0c0c5b14u: goto P_0c0c5b14;
case 0x0c0c5b16u: goto P_0c0c5b16;
case 0x0c0c5b18u: goto P_0c0c5b18;
case 0x0c0c5b1au: goto P_0c0c5b1a;
case 0x0c0c5b1cu: goto P_0c0c5b1c;
case 0x0c0c5b1eu: goto P_0c0c5b1e;
case 0x0c0c5b20u: goto P_0c0c5b20;
case 0x0c0c5b22u: goto P_0c0c5b22;
case 0x0c0c5b24u: goto P_0c0c5b24;
case 0x0c0c5b26u: goto P_0c0c5b26;
case 0x0c0c5b28u: goto P_0c0c5b28;
case 0x0c0c5b2au: goto P_0c0c5b2a;
case 0x0c0c5b2cu: goto P_0c0c5b2c;
case 0x0c0c5b2eu: goto P_0c0c5b2e;
case 0x0c0c5b30u: goto P_0c0c5b30;
case 0x0c0c5b32u: goto P_0c0c5b32;
case 0x0c0c5b34u: goto P_0c0c5b34;
case 0x0c0c5b36u: goto P_0c0c5b36;
case 0x0c0c5b38u: goto P_0c0c5b38;
case 0x0c0c5b3au: goto P_0c0c5b3a;
case 0x0c0c5b3cu: goto P_0c0c5b3c;
case 0x0c0c5b3eu: goto P_0c0c5b3e;
case 0x0c0c5b40u: goto P_0c0c5b40;
case 0x0c0c5b42u: goto P_0c0c5b42;
case 0x0c0c5b44u: goto P_0c0c5b44;
case 0x0c0c5b46u: goto P_0c0c5b46;
case 0x0c0c5b48u: goto P_0c0c5b48;
case 0x0c0c5b4au: goto P_0c0c5b4a;
case 0x0c0c5b4cu: goto P_0c0c5b4c;
case 0x0c0c5b4eu: goto P_0c0c5b4e;
case 0x0c0c5b50u: goto P_0c0c5b50;
case 0x0c0c5b52u: goto P_0c0c5b52;
case 0x0c0c5b54u: goto P_0c0c5b54;
case 0x0c0c5b56u: goto P_0c0c5b56;
case 0x0c0c5b58u: goto P_0c0c5b58;
case 0x0c0c5b5au: goto P_0c0c5b5a;
case 0x0c0c5b5cu: goto P_0c0c5b5c;
case 0x0c0c5b5eu: goto P_0c0c5b5e;
case 0x0c0c5b60u: goto P_0c0c5b60;
case 0x0c0c5b62u: goto P_0c0c5b62;
case 0x0c0c5b64u: goto P_0c0c5b64;
case 0x0c0c5b66u: goto P_0c0c5b66;
case 0x0c0c5b68u: goto P_0c0c5b68;
case 0x0c0c5b6au: goto P_0c0c5b6a;
case 0x0c0c5b6cu: goto P_0c0c5b6c;
case 0x0c0c5b6eu: goto P_0c0c5b6e;
case 0x0c0c5b70u: goto P_0c0c5b70;
case 0x0c0c5b72u: goto P_0c0c5b72;
case 0x0c0c5b74u: goto P_0c0c5b74;
case 0x0c0c5b76u: goto P_0c0c5b76;
case 0x0c0c5b78u: goto P_0c0c5b78;
case 0x0c0c5b7au: goto P_0c0c5b7a;
case 0x0c0c5b7cu: goto P_0c0c5b7c;
case 0x0c0c5b7eu: goto P_0c0c5b7e;
case 0x0c0c5b80u: goto P_0c0c5b80;
case 0x0c0c5b82u: goto P_0c0c5b82;
case 0x0c0c5b84u: goto P_0c0c5b84;
case 0x0c0c5b86u: goto P_0c0c5b86;
case 0x0c0c5b88u: goto P_0c0c5b88;
case 0x0c0c5b8au: goto P_0c0c5b8a;
case 0x0c0c5b8cu: goto P_0c0c5b8c;
case 0x0c0c5b8eu: goto P_0c0c5b8e;
case 0x0c0c5b90u: goto P_0c0c5b90;
case 0x0c0c5b92u: goto P_0c0c5b92;
case 0x0c0c5b94u: goto P_0c0c5b94;
case 0x0c0c5b96u: goto P_0c0c5b96;
case 0x0c0c5b98u: goto P_0c0c5b98;
case 0x0c0c5b9au: goto P_0c0c5b9a;
case 0x0c0c5b9cu: goto P_0c0c5b9c;
case 0x0c0c5b9eu: goto P_0c0c5b9e;
case 0x0c0c5ba0u: goto P_0c0c5ba0;
case 0x0c0c5ba2u: goto P_0c0c5ba2;
case 0x0c0c5ba4u: goto P_0c0c5ba4;
case 0x0c0c5ba6u: goto P_0c0c5ba6;
case 0x0c0c5ba8u: goto P_0c0c5ba8;
case 0x0c0c5baau: goto P_0c0c5baa;
case 0x0c0c5bacu: goto P_0c0c5bac;
case 0x0c0c5baeu: goto P_0c0c5bae;
case 0x0c0c5bb0u: goto P_0c0c5bb0;
case 0x0c0c5bb2u: goto P_0c0c5bb2;
case 0x0c0c5bb4u: goto P_0c0c5bb4;
case 0x0c0c5bb6u: goto P_0c0c5bb6;
case 0x0c0c5bb8u: goto P_0c0c5bb8;
case 0x0c0c5bbau: goto P_0c0c5bba;
case 0x0c0c5c94u: goto P_0c0c5c94;
case 0x0c0c5c96u: goto P_0c0c5c96;
case 0x0c0c5c98u: goto P_0c0c5c98;
case 0x0c0c5c9au: goto P_0c0c5c9a;
case 0x0c0c5c9cu: goto P_0c0c5c9c;
case 0x0c0c5c9eu: goto P_0c0c5c9e;
case 0x0c0c5ca0u: goto P_0c0c5ca0;
case 0x0c0c5ca2u: goto P_0c0c5ca2;
case 0x0c0c5ca4u: goto P_0c0c5ca4;
case 0x0c0c5ca6u: goto P_0c0c5ca6;
case 0x0c0c5ca8u: goto P_0c0c5ca8;
case 0x0c0c5caau: goto P_0c0c5caa;
case 0x0c0c5cacu: goto P_0c0c5cac;
case 0x0c0c5caeu: goto P_0c0c5cae;
case 0x0c0c5cb0u: goto P_0c0c5cb0;
case 0x0c0c5cf4u: goto P_0c0c5cf4;
case 0x0c0c5cf6u: goto P_0c0c5cf6;
case 0x0c0c5cf8u: goto P_0c0c5cf8;
case 0x0c0c5cfau: goto P_0c0c5cfa;
case 0x0c0c5cfcu: goto P_0c0c5cfc;
case 0x0c0c5cfeu: goto P_0c0c5cfe;
case 0x0c0c5d00u: goto P_0c0c5d00;
case 0x0c0c5d02u: goto P_0c0c5d02;
case 0x0c0c5d04u: goto P_0c0c5d04;
case 0x0c0c5d06u: goto P_0c0c5d06;
case 0x0c0c5d08u: goto P_0c0c5d08;
case 0x0c0c5d0au: goto P_0c0c5d0a;
case 0x0c0c5d0cu: goto P_0c0c5d0c;
case 0x0c0c5d0eu: goto P_0c0c5d0e;
case 0x0c0c5d10u: goto P_0c0c5d10;
case 0x0c0c5d12u: goto P_0c0c5d12;
case 0x0c0c5d14u: goto P_0c0c5d14;
case 0x0c0c5d16u: goto P_0c0c5d16;
case 0x0c0c5d18u: goto P_0c0c5d18;
case 0x0c0c5d1au: goto P_0c0c5d1a;
case 0x0c0c5d1cu: goto P_0c0c5d1c;
case 0x0c0c5d1eu: goto P_0c0c5d1e;
case 0x0c0c5d20u: goto P_0c0c5d20;
case 0x0c0c5d22u: goto P_0c0c5d22;
case 0x0c0c5d24u: goto P_0c0c5d24;
case 0x0c0c5d26u: goto P_0c0c5d26;
case 0x0c0c5d28u: goto P_0c0c5d28;
case 0x0c0c5d2au: goto P_0c0c5d2a;
case 0x0c0c5d2cu: goto P_0c0c5d2c;
case 0x0c0c5d2eu: goto P_0c0c5d2e;
case 0x0c0c5d30u: goto P_0c0c5d30;
case 0x0c0c5d32u: goto P_0c0c5d32;
case 0x0c0c5d34u: goto P_0c0c5d34;
case 0x0c0c5d36u: goto P_0c0c5d36;
case 0x0c0c5d38u: goto P_0c0c5d38;
case 0x0c0c5d3au: goto P_0c0c5d3a;
case 0x0c0c5d3cu: goto P_0c0c5d3c;
case 0x0c0c5d3eu: goto P_0c0c5d3e;
case 0x0c0c5d40u: goto P_0c0c5d40;
case 0x0c0c5d42u: goto P_0c0c5d42;
case 0x0c0c5d44u: goto P_0c0c5d44;
case 0x0c0c5d46u: goto P_0c0c5d46;
case 0x0c0c5d48u: goto P_0c0c5d48;
case 0x0c0c5d4au: goto P_0c0c5d4a;
case 0x0c0c5d4cu: goto P_0c0c5d4c;
case 0x0c0c5d4eu: goto P_0c0c5d4e;
case 0x0c0c5d50u: goto P_0c0c5d50;
case 0x0c0c5d52u: goto P_0c0c5d52;
case 0x0c0c5d54u: goto P_0c0c5d54;
case 0x0c0c5d56u: goto P_0c0c5d56;
case 0x0c0c5d58u: goto P_0c0c5d58;
case 0x0c0c5d5au: goto P_0c0c5d5a;
case 0x0c0c5d5cu: goto P_0c0c5d5c;
case 0x0c0c5d5eu: goto P_0c0c5d5e;
case 0x0c0c5d60u: goto P_0c0c5d60;
case 0x0c0c5d62u: goto P_0c0c5d62;
case 0x0c0c5d64u: goto P_0c0c5d64;
case 0x0c0c5d66u: goto P_0c0c5d66;
case 0x0c0c5d68u: goto P_0c0c5d68;
case 0x0c0c5d6au: goto P_0c0c5d6a;
case 0x0c0c5d6cu: goto P_0c0c5d6c;
case 0x0c0c5d6eu: goto P_0c0c5d6e;
case 0x0c0c5d70u: goto P_0c0c5d70;
case 0x0c0c5d72u: goto P_0c0c5d72;
case 0x0c0c5d74u: goto P_0c0c5d74;
case 0x0c0c5d76u: goto P_0c0c5d76;
case 0x0c0c5d78u: goto P_0c0c5d78;
case 0x0c0c5d7au: goto P_0c0c5d7a;
case 0x0c0c5d7cu: goto P_0c0c5d7c;
case 0x0c0c5d7eu: goto P_0c0c5d7e;
case 0x0c0c5d80u: goto P_0c0c5d80;
case 0x0c0c5d82u: goto P_0c0c5d82;
case 0x0c0c5d84u: goto P_0c0c5d84;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c5a74: /* original 2fe6, guest PC 0x0c0c5a74 */
if(!s->budget--) { s->failed_pc=0x0c0c5a74u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5a76;
P_0c0c5a76: /* original 2fd6, guest PC 0x0c0c5a76 */
if(!s->budget--) { s->failed_pc=0x0c0c5a76u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5a78;
P_0c0c5a78: /* original 2fc6, guest PC 0x0c0c5a78 */
if(!s->budget--) { s->failed_pc=0x0c0c5a78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5a7a;
P_0c0c5a7a: /* original 2fb6, guest PC 0x0c0c5a7a */
if(!s->budget--) { s->failed_pc=0x0c0c5a7au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5a7c;
P_0c0c5a7c: /* original 2fa6, guest PC 0x0c0c5a7c */
if(!s->budget--) { s->failed_pc=0x0c0c5a7cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5a7e;
P_0c0c5a7e: /* original 2f86, guest PC 0x0c0c5a7e */
if(!s->budget--) { s->failed_pc=0x0c0c5a7eu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5a80;
P_0c0c5a80: /* original d21e, guest PC 0x0c0c5a80 */
if(!s->budget--) { s->failed_pc=0x0c0c5a80u; return 0; }
r[2]=read(ram,0x0c0c5afcu,4);
goto P_0c0c5a82;
P_0c0c5a82: /* original 4f22, guest PC 0x0c0c5a82 */
if(!s->budget--) { s->failed_pc=0x0c0c5a82u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5a84;
P_0c0c5a84: /* original 6022, guest PC 0x0c0c5a84 */
if(!s->budget--) { s->failed_pc=0x0c0c5a84u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c0c5a86;
P_0c0c5a86: /* original d31c, guest PC 0x0c0c5a86 */
if(!s->budget--) { s->failed_pc=0x0c0c5a86u; return 0; }
r[3]=read(ram,0x0c0c5af8u,4);
goto P_0c0c5a88;
P_0c0c5a88: /* original 7ff8, guest PC 0x0c0c5a88 */
if(!s->budget--) { s->failed_pc=0x0c0c5a88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5a8a;
P_0c0c5a8a: /* original 2038, guest PC 0x0c0c5a8a */
if(!s->budget--) { s->failed_pc=0x0c0c5a8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[3])==0)!=0);
goto P_0c0c5a8c;
P_0c0c5a8c: /* original 8901, guest PC 0x0c0c5a8c */
if(!s->budget--) { s->failed_pc=0x0c0c5a8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5a92; }
goto P_0c0c5a8e;
P_0c0c5a8e: /* original a087, guest PC 0x0c0c5a8e */
if(!s->budget--) { s->failed_pc=0x0c0c5a8eu; return 0; }
goto P_0c0c5ba0;
P_0c0c5a90: /* original 0009, guest PC 0x0c0c5a90 */
if(!s->budget--) { s->failed_pc=0x0c0c5a90u; return 0; }
goto P_0c0c5a92;
P_0c0c5a92: /* original 902c, guest PC 0x0c0c5a92 */
if(!s->budget--) { s->failed_pc=0x0c0c5a92u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5aeeu,2);
goto P_0c0c5a94;
P_0c0c5a94: /* original 666b, guest PC 0x0c0c5a94 */
if(!s->budget--) { s->failed_pc=0x0c0c5a94u; return 0; }
r[6]=0u-r[6];
goto P_0c0c5a96;
P_0c0c5a96: /* original 932b, guest PC 0x0c0c5a96 */
if(!s->budget--) { s->failed_pc=0x0c0c5a96u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5af0u,2);
goto P_0c0c5a98;
P_0c0c5a98: /* original 054e, guest PC 0x0c0c5a98 */
if(!s->budget--) { s->failed_pc=0x0c0c5a98u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c5a9a;
P_0c0c5a9a: /* original 7501, guest PC 0x0c0c5a9a */
if(!s->budget--) { s->failed_pc=0x0c0c5a9au; return 0; }
r[5]+=0x00000001u;
goto P_0c0c5a9c;
P_0c0c5a9c: /* original 3533, guest PC 0x0c0c5a9c */
if(!s->budget--) { s->failed_pc=0x0c0c5a9cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[3])!=0);
goto P_0c0c5a9e;
P_0c0c5a9e: /* original 8f01, guest PC 0x0c0c5a9e */
if(!s->budget--) { s->failed_pc=0x0c0c5a9eu; return 0; }
cond=r[17]&1u;
r[14]=0x00000000u;
if(!cond) { goto P_0c0c5aa4; }
goto P_0c0c5aa2;
P_0c0c5aa0: /* original ee00, guest PC 0x0c0c5aa0 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa0u; return 0; }
r[14]=0x00000000u;
goto P_0c0c5aa2;
P_0c0c5aa2: /* original 65e3, guest PC 0x0c0c5aa2 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa2u; return 0; }
r[5]=r[14];
goto P_0c0c5aa4;
P_0c0c5aa4: /* original e764, guest PC 0x0c0c5aa4 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa4u; return 0; }
r[7]=0x00000064u;
goto P_0c0c5aa6;
P_0c0c5aa6: /* original 0456, guest PC 0x0c0c5aa6 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c5aa8;
P_0c0c5aa8: /* original 3768, guest PC 0x0c0c5aa8 */
if(!s->budget--) { s->failed_pc=0x0c0c5aa8u; return 0; }
r[7]-=r[6];
goto P_0c0c5aaa;
P_0c0c5aaa: /* original 9d22, guest PC 0x0c0c5aaa */
if(!s->budget--) { s->failed_pc=0x0c0c5aaau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5af2u,2);
goto P_0c0c5aac;
P_0c0c5aac: /* original db14, guest PC 0x0c0c5aac */
if(!s->budget--) { s->failed_pc=0x0c0c5aacu; return 0; }
r[11]=read(ram,0x0c0c5b00u,4);
goto P_0c0c5aae;
P_0c0c5aae: /* original 4521, guest PC 0x0c0c5aae */
if(!s->budget--) { s->failed_pc=0x0c0c5aaeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0c5ab0;
P_0c0c5ab0: /* original 4711, guest PC 0x0c0c5ab0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=0)!=0);
goto P_0c0c5ab2;
P_0c0c5ab2: /* original 8913, guest PC 0x0c0c5ab2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5adc; }
goto P_0c0c5ab4;
P_0c0c5ab4: /* original 6673, guest PC 0x0c0c5ab4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab4u; return 0; }
r[6]=r[7];
goto P_0c0c5ab6;
P_0c0c5ab6: /* original 36dc, guest PC 0x0c0c5ab6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab6u; return 0; }
r[6]+=r[13];
goto P_0c0c5ab8;
P_0c0c5ab8: /* original 4611, guest PC 0x0c0c5ab8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ab8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0c5aba;
P_0c0c5aba: /* original 8d01, guest PC 0x0c0c5aba */
if(!s->budget--) { s->failed_pc=0x0c0c5abau; return 0; }
cond=r[17]&1u;
r[5]-=r[7];
if(cond) { goto P_0c0c5ac0; }
goto P_0c0c5abe;
P_0c0c5abc: /* original 3578, guest PC 0x0c0c5abc */
if(!s->budget--) { s->failed_pc=0x0c0c5abcu; return 0; }
r[5]-=r[7];
goto P_0c0c5abe;
P_0c0c5abe: /* original 66e3, guest PC 0x0c0c5abe */
if(!s->budget--) { s->failed_pc=0x0c0c5abeu; return 0; }
r[6]=r[14];
goto P_0c0c5ac0;
P_0c0c5ac0: /* original d310, guest PC 0x0c0c5ac0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac0u; return 0; }
r[3]=read(ram,0x0c0c5b04u,4);
goto P_0c0c5ac2;
P_0c0c5ac2: /* original 60d3, guest PC 0x0c0c5ac2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac2u; return 0; }
r[0]=r[13];
goto P_0c0c5ac4;
P_0c0c5ac4: /* original 430b, guest PC 0x0c0c5ac4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5ac8u;
r[1]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5ac8u) { target=s->pc; goto dispatch; }
goto P_0c0c5ac8;
P_0c0c5ac6: /* original 6153, guest PC 0x0c0c5ac6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac6u; return 0; }
r[1]=r[5];
goto P_0c0c5ac8;
P_0c0c5ac8: /* original 6703, guest PC 0x0c0c5ac8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ac8u; return 0; }
r[7]=r[0];
goto P_0c0c5aca;
P_0c0c5aca: /* original 4708, guest PC 0x0c0c5aca */
if(!s->budget--) { s->failed_pc=0x0c0c5acau; return 0; }
r[7]<<=2;
goto P_0c0c5acc;
P_0c0c5acc: /* original 6303, guest PC 0x0c0c5acc */
if(!s->budget--) { s->failed_pc=0x0c0c5accu; return 0; }
r[3]=r[0];
goto P_0c0c5ace;
P_0c0c5ace: /* original 373c, guest PC 0x0c0c5ace */
if(!s->budget--) { s->failed_pc=0x0c0c5aceu; return 0; }
r[7]+=r[3];
goto P_0c0c5ad0;
P_0c0c5ad0: /* original 4708, guest PC 0x0c0c5ad0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad0u; return 0; }
r[7]<<=2;
goto P_0c0c5ad2;
P_0c0c5ad2: /* original 4708, guest PC 0x0c0c5ad2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad2u; return 0; }
r[7]<<=2;
goto P_0c0c5ad4;
P_0c0c5ad4: /* original 4700, guest PC 0x0c0c5ad4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c0c5ad6;
P_0c0c5ad6: /* original 3578, guest PC 0x0c0c5ad6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad6u; return 0; }
r[5]-=r[7];
goto P_0c0c5ad8;
P_0c0c5ad8: /* original a019, guest PC 0x0c0c5ad8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ad8u; return 0; }
r[7]=r[14];
goto P_0c0c5b0e;
P_0c0c5ada: /* original 67e3, guest PC 0x0c0c5ada */
if(!s->budget--) { s->failed_pc=0x0c0c5adau; return 0; }
r[7]=r[14];
goto P_0c0c5adc;
P_0c0c5adc: /* original 960a, guest PC 0x0c0c5adc */
if(!s->budget--) { s->failed_pc=0x0c0c5adcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5af4u,2);
goto P_0c0c5ade;
P_0c0c5ade: /* original 3767, guest PC 0x0c0c5ade */
if(!s->budget--) { s->failed_pc=0x0c0c5adeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>(int32_t)r[6])!=0);
goto P_0c0c5ae0;
P_0c0c5ae0: /* original 8b00, guest PC 0x0c0c5ae0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5ae4; }
goto P_0c0c5ae2;
P_0c0c5ae2: /* original 6763, guest PC 0x0c0c5ae2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae2u; return 0; }
r[7]=r[6];
goto P_0c0c5ae4;
P_0c0c5ae4: /* original 3678, guest PC 0x0c0c5ae4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae4u; return 0; }
r[6]-=r[7];
goto P_0c0c5ae6;
P_0c0c5ae6: /* original 4611, guest PC 0x0c0c5ae6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c0c5ae8;
P_0c0c5ae8: /* original 890e, guest PC 0x0c0c5ae8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ae8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5b08; }
goto P_0c0c5aea;
P_0c0c5aea: /* original a010, guest PC 0x0c0c5aea */
if(!s->budget--) { s->failed_pc=0x0c0c5aeau; return 0; }
r[6]=r[14];
goto P_0c0c5b0e;
P_0c0c5aec: /* original 66e3, guest PC 0x0c0c5aec */
if(!s->budget--) { s->failed_pc=0x0c0c5aecu; return 0; }
r[6]=r[14];
if(!vf3_matrix_family(0x0c0c5aeeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5aeeu; return 0; } return 1;
P_0c0c5b08: /* original 36d7, guest PC 0x0c0c5b08 */
if(!s->budget--) { s->failed_pc=0x0c0c5b08u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>(int32_t)r[13])!=0);
goto P_0c0c5b0a;
P_0c0c5b0a: /* original 8b00, guest PC 0x0c0c5b0a */
if(!s->budget--) { s->failed_pc=0x0c0c5b0au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5b0e; }
goto P_0c0c5b0c;
P_0c0c5b0c: /* original 66d3, guest PC 0x0c0c5b0c */
if(!s->budget--) { s->failed_pc=0x0c0c5b0cu; return 0; }
r[6]=r[13];
goto P_0c0c5b0e;
P_0c0c5b0e: /* original 9c55, guest PC 0x0c0c5b0e */
if(!s->budget--) { s->failed_pc=0x0c0c5b0eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5bbcu,2);
goto P_0c0c5b10;
P_0c0c5b10: /* original 3c78, guest PC 0x0c0c5b10 */
if(!s->budget--) { s->failed_pc=0x0c0c5b10u; return 0; }
r[12]-=r[7];
goto P_0c0c5b12;
P_0c0c5b12: /* original 3c68, guest PC 0x0c0c5b12 */
if(!s->budget--) { s->failed_pc=0x0c0c5b12u; return 0; }
r[12]-=r[6];
goto P_0c0c5b14;
P_0c0c5b14: /* original 4c11, guest PC 0x0c0c5b14 */
if(!s->budget--) { s->failed_pc=0x0c0c5b14u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c0c5b16;
P_0c0c5b16: /* original 8d01, guest PC 0x0c0c5b16 */
if(!s->budget--) { s->failed_pc=0x0c0c5b16u; return 0; }
cond=r[17]&1u;
r[2]=r[4];
if(cond) { goto P_0c0c5b1c; }
goto P_0c0c5b1a;
P_0c0c5b18: /* original 6243, guest PC 0x0c0c5b18 */
if(!s->budget--) { s->failed_pc=0x0c0c5b18u; return 0; }
r[2]=r[4];
goto P_0c0c5b1a;
P_0c0c5b1a: /* original 6ce3, guest PC 0x0c0c5b1a */
if(!s->budget--) { s->failed_pc=0x0c0c5b1au; return 0; }
r[12]=r[14];
goto P_0c0c5b1c;
P_0c0c5b1c: /* original 6353, guest PC 0x0c0c5b1c */
if(!s->budget--) { s->failed_pc=0x0c0c5b1cu; return 0; }
r[3]=r[5];
goto P_0c0c5b1e;
P_0c0c5b1e: /* original 4308, guest PC 0x0c0c5b1e */
if(!s->budget--) { s->failed_pc=0x0c0c5b1eu; return 0; }
r[3]<<=2;
goto P_0c0c5b20;
P_0c0c5b20: /* original 7208, guest PC 0x0c0c5b20 */
if(!s->budget--) { s->failed_pc=0x0c0c5b20u; return 0; }
r[2]+=0x00000008u;
goto P_0c0c5b22;
P_0c0c5b22: /* original 332c, guest PC 0x0c0c5b22 */
if(!s->budget--) { s->failed_pc=0x0c0c5b22u; return 0; }
r[3]+=r[2];
goto P_0c0c5b24;
P_0c0c5b24: /* original 2778, guest PC 0x0c0c5b24 */
if(!s->budget--) { s->failed_pc=0x0c0c5b24u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c5b26;
P_0c0c5b26: /* original 2f32, guest PC 0x0c0c5b26 */
if(!s->budget--) { s->failed_pc=0x0c0c5b26u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c5b28;
P_0c0c5b28: /* original 8d08, guest PC 0x0c0c5b28 */
if(!s->budget--) { s->failed_pc=0x0c0c5b28u; return 0; }
cond=r[17]&1u;
r[10]=0x00000008u;
if(cond) { goto P_0c0c5b3c; }
goto P_0c0c5b2c;
P_0c0c5b2a: /* original ea08, guest PC 0x0c0c5b2a */
if(!s->budget--) { s->failed_pc=0x0c0c5b2au; return 0; }
r[10]=0x00000008u;
goto P_0c0c5b2c;
P_0c0c5b2c: /* original 6073, guest PC 0x0c0c5b2c */
if(!s->budget--) { s->failed_pc=0x0c0c5b2cu; return 0; }
r[0]=r[7];
goto P_0c0c5b2e;
P_0c0c5b2e: /* original 4015, guest PC 0x0c0c5b2e */
if(!s->budget--) { s->failed_pc=0x0c0c5b2eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0c5b30;
P_0c0c5b30: /* original 8b04, guest PC 0x0c0c5b30 */
if(!s->budget--) { s->failed_pc=0x0c0c5b30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5b3c; }
goto P_0c0c5b32;
P_0c0c5b32: /* original 70ff, guest PC 0x0c0c5b32 */
if(!s->budget--) { s->failed_pc=0x0c0c5b32u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0c5b34;
P_0c0c5b34: /* original 2ba1, guest PC 0x0c0c5b34 */
if(!s->budget--) { s->failed_pc=0x0c0c5b34u; return 0; }
write(ram,r[11],r[10],2);
goto P_0c0c5b36;
P_0c0c5b36: /* original 4015, guest PC 0x0c0c5b36 */
if(!s->budget--) { s->failed_pc=0x0c0c5b36u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>0)!=0);
goto P_0c0c5b38;
P_0c0c5b38: /* original 8dfb, guest PC 0x0c0c5b38 */
if(!s->budget--) { s->failed_pc=0x0c0c5b38u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000002u;
if(cond) { goto P_0c0c5b32; }
goto P_0c0c5b3c;
P_0c0c5b3a: /* original 7b02, guest PC 0x0c0c5b3a */
if(!s->budget--) { s->failed_pc=0x0c0c5b3au; return 0; }
r[11]+=0x00000002u;
goto P_0c0c5b3c;
P_0c0c5b3c: /* original 2668, guest PC 0x0c0c5b3c */
if(!s->budget--) { s->failed_pc=0x0c0c5b3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c5b3e;
P_0c0c5b3e: /* original 8925, guest PC 0x0c0c5b3e */
if(!s->budget--) { s->failed_pc=0x0c0c5b3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5b8c; }
goto P_0c0c5b40;
P_0c0c5b40: /* original 63d3, guest PC 0x0c0c5b40 */
if(!s->budget--) { s->failed_pc=0x0c0c5b40u; return 0; }
r[3]=r[13];
goto P_0c0c5b42;
P_0c0c5b42: /* original 3368, guest PC 0x0c0c5b42 */
if(!s->budget--) { s->failed_pc=0x0c0c5b42u; return 0; }
r[3]-=r[6];
goto P_0c0c5b44;
P_0c0c5b44: /* original c71e, guest PC 0x0c0c5b44 */
if(!s->budget--) { s->failed_pc=0x0c0c5b44u; return 0; }
r[0]=code_base|0x000c5bc0u;
goto P_0c0c5b46;
P_0c0c5b46: /* original 6863, guest PC 0x0c0c5b46 */
if(!s->budget--) { s->failed_pc=0x0c0c5b46u; return 0; }
r[8]=r[6];
goto P_0c0c5b48;
P_0c0c5b48: /* original f608, guest PC 0x0c0c5b48 */
if(!s->budget--) { s->failed_pc=0x0c0c5b48u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c5b4a;
P_0c0c5b4a: /* original 4815, guest PC 0x0c0c5b4a */
if(!s->budget--) { s->failed_pc=0x0c0c5b4au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c0c5b4c;
P_0c0c5b4c: /* original 1f31, guest PC 0x0c0c5b4c */
if(!s->budget--) { s->failed_pc=0x0c0c5b4cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5b4e;
P_0c0c5b4e: /* original 435a, guest PC 0x0c0c5b4e */
if(!s->budget--) { s->failed_pc=0x0c0c5b4eu; return 0; }
r[53]=r[3];
goto P_0c0c5b50;
P_0c0c5b50: /* original f56c, guest PC 0x0c0c5b50 */
if(!s->budget--) { s->failed_pc=0x0c0c5b50u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0c5b52;
P_0c0c5b52: /* original f32d, guest PC 0x0c0c5b52 */
if(!s->budget--) { s->failed_pc=0x0c0c5b52u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c5b54;
P_0c0c5b54: /* original f43c, guest PC 0x0c0c5b54 */
if(!s->budget--) { s->failed_pc=0x0c0c5b54u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c5b56;
P_0c0c5b56: /* original 8f19, guest PC 0x0c0c5b56 */
if(!s->budget--) { s->failed_pc=0x0c0c5b56u; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
if(!cond) { goto P_0c0c5b8c; }
goto P_0c0c5b5a;
P_0c0c5b58: /* original f542, guest PC 0x0c0c5b58 */
if(!s->budget--) { s->failed_pc=0x0c0c5b58u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0c5b5a;
P_0c0c5b5a: /* original 62f2, guest PC 0x0c0c5b5a */
if(!s->budget--) { s->failed_pc=0x0c0c5b5au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0c5b5c;
P_0c0c5b5c: /* original 7501, guest PC 0x0c0c5b5c */
if(!s->budget--) { s->failed_pc=0x0c0c5b5cu; return 0; }
r[5]+=0x00000001u;
goto P_0c0c5b5e;
P_0c0c5b5e: /* original 35d3, guest PC 0x0c0c5b5e */
if(!s->budget--) { s->failed_pc=0x0c0c5b5eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[13])!=0);
goto P_0c0c5b60;
P_0c0c5b60: /* original 7204, guest PC 0x0c0c5b60 */
if(!s->budget--) { s->failed_pc=0x0c0c5b60u; return 0; }
r[2]+=0x00000004u;
goto P_0c0c5b62;
P_0c0c5b62: /* original 2f22, guest PC 0x0c0c5b62 */
if(!s->budget--) { s->failed_pc=0x0c0c5b62u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c5b64;
P_0c0c5b64: /* original 72fc, guest PC 0x0c0c5b64 */
if(!s->budget--) { s->failed_pc=0x0c0c5b64u; return 0; }
r[2]+=0xfffffffcu;
goto P_0c0c5b66;
P_0c0c5b66: /* original 8f04, guest PC 0x0c0c5b66 */
if(!s->budget--) { s->failed_pc=0x0c0c5b66u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[2]);
if(!cond) { goto P_0c0c5b72; }
goto P_0c0c5b6a;
P_0c0c5b68: /* original f428, guest PC 0x0c0c5b68 */
if(!s->budget--) { s->failed_pc=0x0c0c5b68u; return 0; }
vf3_matrix_load(s,ram,4,r[2]);
goto P_0c0c5b6a;
P_0c0c5b6a: /* original 6243, guest PC 0x0c0c5b6a */
if(!s->budget--) { s->failed_pc=0x0c0c5b6au; return 0; }
r[2]=r[4];
goto P_0c0c5b6c;
P_0c0c5b6c: /* original 7208, guest PC 0x0c0c5b6c */
if(!s->budget--) { s->failed_pc=0x0c0c5b6cu; return 0; }
r[2]+=0x00000008u;
goto P_0c0c5b6e;
P_0c0c5b6e: /* original 2f22, guest PC 0x0c0c5b6e */
if(!s->budget--) { s->failed_pc=0x0c0c5b6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0c5b70;
P_0c0c5b70: /* original 65e3, guest PC 0x0c0c5b70 */
if(!s->budget--) { s->failed_pc=0x0c0c5b70u; return 0; }
r[5]=r[14];
goto P_0c0c5b72;
P_0c0c5b72: /* original d314, guest PC 0x0c0c5b72 */
if(!s->budget--) { s->failed_pc=0x0c0c5b72u; return 0; }
r[3]=read(ram,0x0c0c5bc4u,4);
goto P_0c0c5b74;
P_0c0c5b74: /* original f452, guest PC 0x0c0c5b74 */
if(!s->budget--) { s->failed_pc=0x0c0c5b74u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0c5b76;
P_0c0c5b76: /* original f560, guest PC 0x0c0c5b76 */
if(!s->budget--) { s->failed_pc=0x0c0c5b76u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'+');
goto P_0c0c5b78;
P_0c0c5b78: /* original 78ff, guest PC 0x0c0c5b78 */
if(!s->budget--) { s->failed_pc=0x0c0c5b78u; return 0; }
r[8]+=0xffffffffu;
goto P_0c0c5b7a;
P_0c0c5b7a: /* original f338, guest PC 0x0c0c5b7a */
if(!s->budget--) { s->failed_pc=0x0c0c5b7au; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0c5b7c;
P_0c0c5b7c: /* original 4815, guest PC 0x0c0c5b7c */
if(!s->budget--) { s->failed_pc=0x0c0c5b7cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[8]>0)!=0);
goto P_0c0c5b7e;
P_0c0c5b7e: /* original f432, guest PC 0x0c0c5b7e */
if(!s->budget--) { s->failed_pc=0x0c0c5b7eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0c5b80;
P_0c0c5b80: /* original f43d, guest PC 0x0c0c5b80 */
if(!s->budget--) { s->failed_pc=0x0c0c5b80u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c5b82;
P_0c0c5b82: /* original 005a, guest PC 0x0c0c5b82 */
if(!s->budget--) { s->failed_pc=0x0c0c5b82u; return 0; }
r[0]=r[53];
goto P_0c0c5b84;
P_0c0c5b84: /* original 7008, guest PC 0x0c0c5b84 */
if(!s->budget--) { s->failed_pc=0x0c0c5b84u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c5b86;
P_0c0c5b86: /* original 2b01, guest PC 0x0c0c5b86 */
if(!s->budget--) { s->failed_pc=0x0c0c5b86u; return 0; }
write(ram,r[11],r[0],2);
goto P_0c0c5b88;
P_0c0c5b88: /* original 8de7, guest PC 0x0c0c5b88 */
if(!s->budget--) { s->failed_pc=0x0c0c5b88u; return 0; }
cond=r[17]&1u;
r[11]+=0x00000002u;
if(cond) { goto P_0c0c5b5a; }
goto P_0c0c5b8c;
P_0c0c5b8a: /* original 7b02, guest PC 0x0c0c5b8a */
if(!s->budget--) { s->failed_pc=0x0c0c5b8au; return 0; }
r[11]+=0x00000002u;
goto P_0c0c5b8c;
P_0c0c5b8c: /* original 2cc8, guest PC 0x0c0c5b8c */
if(!s->budget--) { s->failed_pc=0x0c0c5b8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0c5b8e;
P_0c0c5b8e: /* original 8907, guest PC 0x0c0c5b8e */
if(!s->budget--) { s->failed_pc=0x0c0c5b8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5ba0; }
goto P_0c0c5b90;
P_0c0c5b90: /* original 64c3, guest PC 0x0c0c5b90 */
if(!s->budget--) { s->failed_pc=0x0c0c5b90u; return 0; }
r[4]=r[12];
goto P_0c0c5b92;
P_0c0c5b92: /* original 4415, guest PC 0x0c0c5b92 */
if(!s->budget--) { s->failed_pc=0x0c0c5b92u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c5b94;
P_0c0c5b94: /* original 8b04, guest PC 0x0c0c5b94 */
if(!s->budget--) { s->failed_pc=0x0c0c5b94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5ba0; }
goto P_0c0c5b96;
P_0c0c5b96: /* original 74ff, guest PC 0x0c0c5b96 */
if(!s->budget--) { s->failed_pc=0x0c0c5b96u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c5b98;
P_0c0c5b98: /* original 2ba1, guest PC 0x0c0c5b98 */
if(!s->budget--) { s->failed_pc=0x0c0c5b98u; return 0; }
write(ram,r[11],r[10],2);
goto P_0c0c5b9a;
P_0c0c5b9a: /* original 4415, guest PC 0x0c0c5b9a */
if(!s->budget--) { s->failed_pc=0x0c0c5b9au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0c5b9c;
P_0c0c5b9c: /* original 8dfb, guest PC 0x0c0c5b9c */
if(!s->budget--) { s->failed_pc=0x0c0c5b9cu; return 0; }
cond=r[17]&1u;
r[11]+=0x00000002u;
if(cond) { goto P_0c0c5b96; }
goto P_0c0c5ba0;
P_0c0c5b9e: /* original 7b02, guest PC 0x0c0c5b9e */
if(!s->budget--) { s->failed_pc=0x0c0c5b9eu; return 0; }
r[11]+=0x00000002u;
goto P_0c0c5ba0;
P_0c0c5ba0: /* original 7f08, guest PC 0x0c0c5ba0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5ba2;
P_0c0c5ba2: /* original d309, guest PC 0x0c0c5ba2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba2u; return 0; }
r[3]=read(ram,0x0c0c5bc8u,4);
goto P_0c0c5ba4;
P_0c0c5ba4: /* original 4f26, guest PC 0x0c0c5ba4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5ba6;
P_0c0c5ba6: /* original 2372, guest PC 0x0c0c5ba6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba6u; return 0; }
write(ram,r[3],r[7],4);
goto P_0c0c5ba8;
P_0c0c5ba8: /* original 376c, guest PC 0x0c0c5ba8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ba8u; return 0; }
r[7]+=r[6];
goto P_0c0c5baa;
P_0c0c5baa: /* original d208, guest PC 0x0c0c5baa */
if(!s->budget--) { s->failed_pc=0x0c0c5baau; return 0; }
r[2]=read(ram,0x0c0c5bccu,4);
goto P_0c0c5bac;
P_0c0c5bac: /* original 2272, guest PC 0x0c0c5bac */
if(!s->budget--) { s->failed_pc=0x0c0c5bacu; return 0; }
write(ram,r[2],r[7],4);
goto P_0c0c5bae;
P_0c0c5bae: /* original 68f6, guest PC 0x0c0c5bae */
if(!s->budget--) { s->failed_pc=0x0c0c5baeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c5bb0;
P_0c0c5bb0: /* original 6af6, guest PC 0x0c0c5bb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c5bb2;
P_0c0c5bb2: /* original 6bf6, guest PC 0x0c0c5bb2 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5bb4;
P_0c0c5bb4: /* original 6cf6, guest PC 0x0c0c5bb4 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5bb6;
P_0c0c5bb6: /* original 6df6, guest PC 0x0c0c5bb6 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5bb8;
P_0c0c5bb8: /* original 000b, guest PC 0x0c0c5bb8 */
if(!s->budget--) { s->failed_pc=0x0c0c5bb8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5bba: /* original 6ef6, guest PC 0x0c0c5bba */
if(!s->budget--) { s->failed_pc=0x0c0c5bbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5bbcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5bbcu; return 0; } return 1;
P_0c0c5c94: /* original 2fe6, guest PC 0x0c0c5c94 */
if(!s->budget--) { s->failed_pc=0x0c0c5c94u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c96;
P_0c0c5c96: /* original 6043, guest PC 0x0c0c5c96 */
if(!s->budget--) { s->failed_pc=0x0c0c5c96u; return 0; }
r[0]=r[4];
goto P_0c0c5c98;
P_0c0c5c98: /* original 2fd6, guest PC 0x0c0c5c98 */
if(!s->budget--) { s->failed_pc=0x0c0c5c98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9a;
P_0c0c5c9a: /* original 88ff, guest PC 0x0c0c5c9a */
if(!s->budget--) { s->failed_pc=0x0c0c5c9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c5c9c;
P_0c0c5c9c: /* original 2fc6, guest PC 0x0c0c5c9c */
if(!s->budget--) { s->failed_pc=0x0c0c5c9cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5c9e;
P_0c0c5c9e: /* original 6d43, guest PC 0x0c0c5c9e */
if(!s->budget--) { s->failed_pc=0x0c0c5c9eu; return 0; }
r[13]=r[4];
goto P_0c0c5ca0;
P_0c0c5ca0: /* original 2fb6, guest PC 0x0c0c5ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5ca2;
P_0c0c5ca2: /* original 4f22, guest PC 0x0c0c5ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5ca4;
P_0c0c5ca4: /* original 8d03, guest PC 0x0c0c5ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca4u; return 0; }
cond=r[17]&1u;
r[11]=r[5];
if(cond) { goto P_0c0c5cae; }
goto P_0c0c5ca8;
P_0c0c5ca6: /* original 6b53, guest PC 0x0c0c5ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca6u; return 0; }
r[11]=r[5];
goto P_0c0c5ca8;
P_0c0c5ca8: /* original 930d, guest PC 0x0c0c5ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c5ca8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5cc6u,2);
goto P_0c0c5caa;
P_0c0c5caa: /* original 3d30, guest PC 0x0c0c5caa */
if(!s->budget--) { s->failed_pc=0x0c0c5caau; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cac;
P_0c0c5cac: /* original 8b22, guest PC 0x0c0c5cac */
if(!s->budget--) { s->failed_pc=0x0c0c5cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5cf4; }
goto P_0c0c5cae;
P_0c0c5cae: /* original a064, guest PC 0x0c0c5cae */
if(!s->budget--) { s->failed_pc=0x0c0c5caeu; return 0; }
r[0]=0xffffffffu;
goto P_0c0c5d7a;
P_0c0c5cb0: /* original e0ff, guest PC 0x0c0c5cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c5cb0u; return 0; }
r[0]=0xffffffffu;
if(!vf3_matrix_family(0x0c0c5cb2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5cb2u; return 0; } return 1;
P_0c0c5cf4: /* original 9381, guest PC 0x0c0c5cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfau,2);
goto P_0c0c5cf6;
P_0c0c5cf6: /* original de43, guest PC 0x0c0c5cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf6u; return 0; }
r[14]=read(ram,0x0c0c5e04u,4);
goto P_0c0c5cf8;
P_0c0c5cf8: /* original 3d30, guest PC 0x0c0c5cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c5cf8u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5cfa;
P_0c0c5cfa: /* original 8905, guest PC 0x0c0c5cfa */
if(!s->budget--) { s->failed_pc=0x0c0c5cfau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5cfc;
P_0c0c5cfc: /* original 917e, guest PC 0x0c0c5cfc */
if(!s->budget--) { s->failed_pc=0x0c0c5cfcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfcu,2);
goto P_0c0c5cfe;
P_0c0c5cfe: /* original 3d10, guest PC 0x0c0c5cfe */
if(!s->budget--) { s->failed_pc=0x0c0c5cfeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d00;
P_0c0c5d00: /* original 8902, guest PC 0x0c0c5d00 */
if(!s->budget--) { s->failed_pc=0x0c0c5d00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5d08; }
goto P_0c0c5d02;
P_0c0c5d02: /* original 907c, guest PC 0x0c0c5d02 */
if(!s->budget--) { s->failed_pc=0x0c0c5d02u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5dfeu,2);
goto P_0c0c5d04;
P_0c0c5d04: /* original 3d00, guest PC 0x0c0c5d04 */
if(!s->budget--) { s->failed_pc=0x0c0c5d04u; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[0])!=0);
goto P_0c0c5d06;
P_0c0c5d06: /* original 8b07, guest PC 0x0c0c5d06 */
if(!s->budget--) { s->failed_pc=0x0c0c5d06u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d18; }
goto P_0c0c5d08;
P_0c0c5d08: /* original 65d3, guest PC 0x0c0c5d08 */
if(!s->budget--) { s->failed_pc=0x0c0c5d08u; return 0; }
r[5]=r[13];
goto P_0c0c5d0a;
P_0c0c5d0a: /* original 66b3, guest PC 0x0c0c5d0a */
if(!s->budget--) { s->failed_pc=0x0c0c5d0au; return 0; }
r[6]=r[11];
goto P_0c0c5d0c;
P_0c0c5d0c: /* original 4e0b, guest PC 0x0c0c5d0c */
if(!s->budget--) { s->failed_pc=0x0c0c5d0cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d10u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d10u) { target=s->pc; goto dispatch; }
goto P_0c0c5d10;
P_0c0c5d0e: /* original e404, guest PC 0x0c0c5d0e */
if(!s->budget--) { s->failed_pc=0x0c0c5d0eu; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d10;
P_0c0c5d10: /* original 65d3, guest PC 0x0c0c5d10 */
if(!s->budget--) { s->failed_pc=0x0c0c5d10u; return 0; }
r[5]=r[13];
goto P_0c0c5d12;
P_0c0c5d12: /* original 66b3, guest PC 0x0c0c5d12 */
if(!s->budget--) { s->failed_pc=0x0c0c5d12u; return 0; }
r[6]=r[11];
goto P_0c0c5d14;
P_0c0c5d14: /* original a02f, guest PC 0x0c0c5d14 */
if(!s->budget--) { s->failed_pc=0x0c0c5d14u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d76;
P_0c0c5d16: /* original e403, guest PC 0x0c0c5d16 */
if(!s->budget--) { s->failed_pc=0x0c0c5d16u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d18;
P_0c0c5d18: /* original d33c, guest PC 0x0c0c5d18 */
if(!s->budget--) { s->failed_pc=0x0c0c5d18u; return 0; }
r[3]=read(ram,0x0c0c5e0cu,4);
goto P_0c0c5d1a;
P_0c0c5d1a: /* original dc3b, guest PC 0x0c0c5d1a */
if(!s->budget--) { s->failed_pc=0x0c0c5d1au; return 0; }
r[12]=read(ram,0x0c0c5e08u,4);
goto P_0c0c5d1c;
P_0c0c5d1c: /* original 3d30, guest PC 0x0c0c5d1c */
if(!s->budget--) { s->failed_pc=0x0c0c5d1cu; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[3])!=0);
goto P_0c0c5d1e;
P_0c0c5d1e: /* original 8b0b, guest PC 0x0c0c5d1e */
if(!s->budget--) { s->failed_pc=0x0c0c5d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d38; }
goto P_0c0c5d20;
P_0c0c5d20: /* original 65c3, guest PC 0x0c0c5d20 */
if(!s->budget--) { s->failed_pc=0x0c0c5d20u; return 0; }
r[5]=r[12];
goto P_0c0c5d22;
P_0c0c5d22: /* original e600, guest PC 0x0c0c5d22 */
if(!s->budget--) { s->failed_pc=0x0c0c5d22u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d24;
P_0c0c5d24: /* original 4e0b, guest PC 0x0c0c5d24 */
if(!s->budget--) { s->failed_pc=0x0c0c5d24u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d28u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d28u) { target=s->pc; goto dispatch; }
goto P_0c0c5d28;
P_0c0c5d26: /* original e401, guest PC 0x0c0c5d26 */
if(!s->budget--) { s->failed_pc=0x0c0c5d26u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d28;
P_0c0c5d28: /* original 65c3, guest PC 0x0c0c5d28 */
if(!s->budget--) { s->failed_pc=0x0c0c5d28u; return 0; }
r[5]=r[12];
goto P_0c0c5d2a;
P_0c0c5d2a: /* original e600, guest PC 0x0c0c5d2a */
if(!s->budget--) { s->failed_pc=0x0c0c5d2au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d2c;
P_0c0c5d2c: /* original 4e0b, guest PC 0x0c0c5d2c */
if(!s->budget--) { s->failed_pc=0x0c0c5d2cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d30u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d30u) { target=s->pc; goto dispatch; }
goto P_0c0c5d30;
P_0c0c5d2e: /* original e402, guest PC 0x0c0c5d2e */
if(!s->budget--) { s->failed_pc=0x0c0c5d2eu; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d30;
P_0c0c5d30: /* original 65c3, guest PC 0x0c0c5d30 */
if(!s->budget--) { s->failed_pc=0x0c0c5d30u; return 0; }
r[5]=r[12];
goto P_0c0c5d32;
P_0c0c5d32: /* original e600, guest PC 0x0c0c5d32 */
if(!s->budget--) { s->failed_pc=0x0c0c5d32u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d34;
P_0c0c5d34: /* original a00a, guest PC 0x0c0c5d34 */
if(!s->budget--) { s->failed_pc=0x0c0c5d34u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d4c;
P_0c0c5d36: /* original e403, guest PC 0x0c0c5d36 */
if(!s->budget--) { s->failed_pc=0x0c0c5d36u; return 0; }
r[4]=0x00000003u;
goto P_0c0c5d38;
P_0c0c5d38: /* original d135, guest PC 0x0c0c5d38 */
if(!s->budget--) { s->failed_pc=0x0c0c5d38u; return 0; }
r[1]=read(ram,0x0c0c5e10u,4);
goto P_0c0c5d3a;
P_0c0c5d3a: /* original 3d10, guest PC 0x0c0c5d3a */
if(!s->budget--) { s->failed_pc=0x0c0c5d3au; return 0; }
r[17]=(r[17]&~1u)|((r[13]==r[1])!=0);
goto P_0c0c5d3c;
P_0c0c5d3c: /* original 8b18, guest PC 0x0c0c5d3c */
if(!s->budget--) { s->failed_pc=0x0c0c5d3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5d70; }
goto P_0c0c5d3e;
P_0c0c5d3e: /* original 65c3, guest PC 0x0c0c5d3e */
if(!s->budget--) { s->failed_pc=0x0c0c5d3eu; return 0; }
r[5]=r[12];
goto P_0c0c5d40;
P_0c0c5d40: /* original e600, guest PC 0x0c0c5d40 */
if(!s->budget--) { s->failed_pc=0x0c0c5d40u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d42;
P_0c0c5d42: /* original 4e0b, guest PC 0x0c0c5d42 */
if(!s->budget--) { s->failed_pc=0x0c0c5d42u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d46u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d46u) { target=s->pc; goto dispatch; }
goto P_0c0c5d46;
P_0c0c5d44: /* original e401, guest PC 0x0c0c5d44 */
if(!s->budget--) { s->failed_pc=0x0c0c5d44u; return 0; }
r[4]=0x00000001u;
goto P_0c0c5d46;
P_0c0c5d46: /* original e402, guest PC 0x0c0c5d46 */
if(!s->budget--) { s->failed_pc=0x0c0c5d46u; return 0; }
r[4]=0x00000002u;
goto P_0c0c5d48;
P_0c0c5d48: /* original 65c3, guest PC 0x0c0c5d48 */
if(!s->budget--) { s->failed_pc=0x0c0c5d48u; return 0; }
r[5]=r[12];
goto P_0c0c5d4a;
P_0c0c5d4a: /* original e600, guest PC 0x0c0c5d4a */
if(!s->budget--) { s->failed_pc=0x0c0c5d4au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d4c;
P_0c0c5d4c: /* original 4e0b, guest PC 0x0c0c5d4c */
if(!s->budget--) { s->failed_pc=0x0c0c5d4cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d50u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d50u) { target=s->pc; goto dispatch; }
goto P_0c0c5d50;
P_0c0c5d4e: /* original 0009, guest PC 0x0c0c5d4e */
if(!s->budget--) { s->failed_pc=0x0c0c5d4eu; return 0; }
goto P_0c0c5d50;
P_0c0c5d50: /* original 65c3, guest PC 0x0c0c5d50 */
if(!s->budget--) { s->failed_pc=0x0c0c5d50u; return 0; }
r[5]=r[12];
goto P_0c0c5d52;
P_0c0c5d52: /* original e600, guest PC 0x0c0c5d52 */
if(!s->budget--) { s->failed_pc=0x0c0c5d52u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d54;
P_0c0c5d54: /* original 4e0b, guest PC 0x0c0c5d54 */
if(!s->budget--) { s->failed_pc=0x0c0c5d54u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d58u;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d58u) { target=s->pc; goto dispatch; }
goto P_0c0c5d58;
P_0c0c5d56: /* original e404, guest PC 0x0c0c5d56 */
if(!s->budget--) { s->failed_pc=0x0c0c5d56u; return 0; }
r[4]=0x00000004u;
goto P_0c0c5d58;
P_0c0c5d58: /* original 65c3, guest PC 0x0c0c5d58 */
if(!s->budget--) { s->failed_pc=0x0c0c5d58u; return 0; }
r[5]=r[12];
goto P_0c0c5d5a;
P_0c0c5d5a: /* original e600, guest PC 0x0c0c5d5a */
if(!s->budget--) { s->failed_pc=0x0c0c5d5au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d5c;
P_0c0c5d5c: /* original 4e0b, guest PC 0x0c0c5d5c */
if(!s->budget--) { s->failed_pc=0x0c0c5d5cu; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d60u;
r[4]=0x00000005u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d60u) { target=s->pc; goto dispatch; }
goto P_0c0c5d60;
P_0c0c5d5e: /* original e405, guest PC 0x0c0c5d5e */
if(!s->budget--) { s->failed_pc=0x0c0c5d5eu; return 0; }
r[4]=0x00000005u;
goto P_0c0c5d60;
P_0c0c5d60: /* original 65c3, guest PC 0x0c0c5d60 */
if(!s->budget--) { s->failed_pc=0x0c0c5d60u; return 0; }
r[5]=r[12];
goto P_0c0c5d62;
P_0c0c5d62: /* original e600, guest PC 0x0c0c5d62 */
if(!s->budget--) { s->failed_pc=0x0c0c5d62u; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d64;
P_0c0c5d64: /* original 4e0b, guest PC 0x0c0c5d64 */
if(!s->budget--) { s->failed_pc=0x0c0c5d64u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d68u;
r[4]=0x00000006u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d68u) { target=s->pc; goto dispatch; }
goto P_0c0c5d68;
P_0c0c5d66: /* original e406, guest PC 0x0c0c5d66 */
if(!s->budget--) { s->failed_pc=0x0c0c5d66u; return 0; }
r[4]=0x00000006u;
goto P_0c0c5d68;
P_0c0c5d68: /* original 65c3, guest PC 0x0c0c5d68 */
if(!s->budget--) { s->failed_pc=0x0c0c5d68u; return 0; }
r[5]=r[12];
goto P_0c0c5d6a;
P_0c0c5d6a: /* original e600, guest PC 0x0c0c5d6a */
if(!s->budget--) { s->failed_pc=0x0c0c5d6au; return 0; }
r[6]=0x00000000u;
goto P_0c0c5d6c;
P_0c0c5d6c: /* original a003, guest PC 0x0c0c5d6c */
if(!s->budget--) { s->failed_pc=0x0c0c5d6cu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d76;
P_0c0c5d6e: /* original e407, guest PC 0x0c0c5d6e */
if(!s->budget--) { s->failed_pc=0x0c0c5d6eu; return 0; }
r[4]=0x00000007u;
goto P_0c0c5d70;
P_0c0c5d70: /* original e400, guest PC 0x0c0c5d70 */
if(!s->budget--) { s->failed_pc=0x0c0c5d70u; return 0; }
r[4]=0x00000000u;
goto P_0c0c5d72;
P_0c0c5d72: /* original 65d3, guest PC 0x0c0c5d72 */
if(!s->budget--) { s->failed_pc=0x0c0c5d72u; return 0; }
r[5]=r[13];
goto P_0c0c5d74;
P_0c0c5d74: /* original 66b3, guest PC 0x0c0c5d74 */
if(!s->budget--) { s->failed_pc=0x0c0c5d74u; return 0; }
r[6]=r[11];
goto P_0c0c5d76;
P_0c0c5d76: /* original 4e0b, guest PC 0x0c0c5d76 */
if(!s->budget--) { s->failed_pc=0x0c0c5d76u; return 0; }
target=r[14];
r[16]=code_base|0x0c0c5d7au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5d7au) { target=s->pc; goto dispatch; }
goto P_0c0c5d7a;
P_0c0c5d78: /* original 0009, guest PC 0x0c0c5d78 */
if(!s->budget--) { s->failed_pc=0x0c0c5d78u; return 0; }
goto P_0c0c5d7a;
P_0c0c5d7a: /* original 4f26, guest PC 0x0c0c5d7a */
if(!s->budget--) { s->failed_pc=0x0c0c5d7au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5d7c;
P_0c0c5d7c: /* original 6bf6, guest PC 0x0c0c5d7c */
if(!s->budget--) { s->failed_pc=0x0c0c5d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c5d7e;
P_0c0c5d7e: /* original 6cf6, guest PC 0x0c0c5d7e */
if(!s->budget--) { s->failed_pc=0x0c0c5d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c5d80;
P_0c0c5d80: /* original 6df6, guest PC 0x0c0c5d80 */
if(!s->budget--) { s->failed_pc=0x0c0c5d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c5d82;
P_0c0c5d82: /* original 000b, guest PC 0x0c0c5d82 */
if(!s->budget--) { s->failed_pc=0x0c0c5d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5d84: /* original 6ef6, guest PC 0x0c0c5d84 */
if(!s->budget--) { s->failed_pc=0x0c0c5d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c5d86u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
