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
int vf3_away_batch28_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c066a66u: goto P_0c066a66;
case 0x0c066a68u: goto P_0c066a68;
case 0x0c066a6au: goto P_0c066a6a;
case 0x0c066a6cu: goto P_0c066a6c;
case 0x0c066a6eu: goto P_0c066a6e;
case 0x0c066a70u: goto P_0c066a70;
case 0x0c066a72u: goto P_0c066a72;
case 0x0c066a74u: goto P_0c066a74;
case 0x0c066a76u: goto P_0c066a76;
case 0x0c066a78u: goto P_0c066a78;
case 0x0c066a7au: goto P_0c066a7a;
case 0x0c066a7cu: goto P_0c066a7c;
case 0x0c066a7eu: goto P_0c066a7e;
case 0x0c066a80u: goto P_0c066a80;
case 0x0c066a82u: goto P_0c066a82;
case 0x0c066a84u: goto P_0c066a84;
case 0x0c066a86u: goto P_0c066a86;
case 0x0c066a88u: goto P_0c066a88;
case 0x0c066ac0u: goto P_0c066ac0;
case 0x0c066ac2u: goto P_0c066ac2;
case 0x0c066ac4u: goto P_0c066ac4;
case 0x0c066ac6u: goto P_0c066ac6;
case 0x0c066ac8u: goto P_0c066ac8;
case 0x0c066acau: goto P_0c066aca;
case 0x0c066accu: goto P_0c066acc;
case 0x0c066aceu: goto P_0c066ace;
case 0x0c066ad0u: goto P_0c066ad0;
case 0x0c066ad2u: goto P_0c066ad2;
case 0x0c066ad4u: goto P_0c066ad4;
case 0x0c066ad6u: goto P_0c066ad6;
case 0x0c066ad8u: goto P_0c066ad8;
case 0x0c066adau: goto P_0c066ada;
case 0x0c066adcu: goto P_0c066adc;
case 0x0c066adeu: goto P_0c066ade;
case 0x0c066ae0u: goto P_0c066ae0;
case 0x0c066ae2u: goto P_0c066ae2;
case 0x0c066ae4u: goto P_0c066ae4;
case 0x0c066ae6u: goto P_0c066ae6;
case 0x0c066ae8u: goto P_0c066ae8;
case 0x0c066aeau: goto P_0c066aea;
case 0x0c066aecu: goto P_0c066aec;
case 0x0c066aeeu: goto P_0c066aee;
case 0x0c066af0u: goto P_0c066af0;
case 0x0c066af2u: goto P_0c066af2;
case 0x0c066af4u: goto P_0c066af4;
case 0x0c066af6u: goto P_0c066af6;
case 0x0c066af8u: goto P_0c066af8;
case 0x0c066afau: goto P_0c066afa;
case 0x0c066afcu: goto P_0c066afc;
case 0x0c066afeu: goto P_0c066afe;
case 0x0c066b00u: goto P_0c066b00;
case 0x0c066b02u: goto P_0c066b02;
case 0x0c066b04u: goto P_0c066b04;
case 0x0c066b06u: goto P_0c066b06;
case 0x0c066b08u: goto P_0c066b08;
case 0x0c066b0au: goto P_0c066b0a;
case 0x0c066b0cu: goto P_0c066b0c;
case 0x0c066b0eu: goto P_0c066b0e;
case 0x0c066b10u: goto P_0c066b10;
case 0x0c066b12u: goto P_0c066b12;
case 0x0c066b14u: goto P_0c066b14;
case 0x0c066b16u: goto P_0c066b16;
case 0x0c066b18u: goto P_0c066b18;
case 0x0c066b1au: goto P_0c066b1a;
case 0x0c066b1cu: goto P_0c066b1c;
case 0x0c066b1eu: goto P_0c066b1e;
case 0x0c066b20u: goto P_0c066b20;
case 0x0c066b22u: goto P_0c066b22;
case 0x0c066b24u: goto P_0c066b24;
case 0x0c066b26u: goto P_0c066b26;
case 0x0c066b28u: goto P_0c066b28;
case 0x0c066b2au: goto P_0c066b2a;
case 0x0c066b2cu: goto P_0c066b2c;
case 0x0c066b2eu: goto P_0c066b2e;
case 0x0c066b30u: goto P_0c066b30;
case 0x0c066b32u: goto P_0c066b32;
case 0x0c066b34u: goto P_0c066b34;
case 0x0c066b36u: goto P_0c066b36;
case 0x0c066b38u: goto P_0c066b38;
case 0x0c066b3au: goto P_0c066b3a;
case 0x0c066b3cu: goto P_0c066b3c;
case 0x0c066b3eu: goto P_0c066b3e;
case 0x0c066b40u: goto P_0c066b40;
case 0x0c066b42u: goto P_0c066b42;
case 0x0c066b44u: goto P_0c066b44;
case 0x0c066b46u: goto P_0c066b46;
case 0x0c066b48u: goto P_0c066b48;
case 0x0c066b4au: goto P_0c066b4a;
case 0x0c066b4cu: goto P_0c066b4c;
case 0x0c066b4eu: goto P_0c066b4e;
case 0x0c066b50u: goto P_0c066b50;
case 0x0c066b52u: goto P_0c066b52;
case 0x0c066b54u: goto P_0c066b54;
case 0x0c066b56u: goto P_0c066b56;
case 0x0c066b58u: goto P_0c066b58;
case 0x0c066b5au: goto P_0c066b5a;
case 0x0c066b5cu: goto P_0c066b5c;
case 0x0c066b5eu: goto P_0c066b5e;
case 0x0c066b60u: goto P_0c066b60;
case 0x0c066b62u: goto P_0c066b62;
case 0x0c066b64u: goto P_0c066b64;
case 0x0c066b66u: goto P_0c066b66;
case 0x0c066b68u: goto P_0c066b68;
case 0x0c066b6au: goto P_0c066b6a;
case 0x0c066b6cu: goto P_0c066b6c;
case 0x0c066b6eu: goto P_0c066b6e;
case 0x0c066b70u: goto P_0c066b70;
case 0x0c066b72u: goto P_0c066b72;
case 0x0c066b74u: goto P_0c066b74;
case 0x0c066b76u: goto P_0c066b76;
case 0x0c066b78u: goto P_0c066b78;
case 0x0c066b7au: goto P_0c066b7a;
case 0x0c066b7cu: goto P_0c066b7c;
case 0x0c066b7eu: goto P_0c066b7e;
case 0x0c066b80u: goto P_0c066b80;
case 0x0c066b82u: goto P_0c066b82;
case 0x0c066b84u: goto P_0c066b84;
case 0x0c066b86u: goto P_0c066b86;
case 0x0c066b88u: goto P_0c066b88;
case 0x0c066b8au: goto P_0c066b8a;
case 0x0c066b8cu: goto P_0c066b8c;
case 0x0c066b8eu: goto P_0c066b8e;
case 0x0c066b90u: goto P_0c066b90;
case 0x0c066b92u: goto P_0c066b92;
case 0x0c066b94u: goto P_0c066b94;
case 0x0c066b96u: goto P_0c066b96;
case 0x0c066b98u: goto P_0c066b98;
case 0x0c066b9au: goto P_0c066b9a;
case 0x0c066b9cu: goto P_0c066b9c;
case 0x0c066b9eu: goto P_0c066b9e;
case 0x0c066ba0u: goto P_0c066ba0;
case 0x0c066ba2u: goto P_0c066ba2;
case 0x0c066ba4u: goto P_0c066ba4;
case 0x0c066ba6u: goto P_0c066ba6;
case 0x0c066ba8u: goto P_0c066ba8;
case 0x0c066baau: goto P_0c066baa;
case 0x0c066bfcu: goto P_0c066bfc;
case 0x0c066bfeu: goto P_0c066bfe;
case 0x0c066c00u: goto P_0c066c00;
case 0x0c066c02u: goto P_0c066c02;
case 0x0c066c04u: goto P_0c066c04;
case 0x0c066c06u: goto P_0c066c06;
case 0x0c066c08u: goto P_0c066c08;
case 0x0c066c0au: goto P_0c066c0a;
case 0x0c066c0cu: goto P_0c066c0c;
case 0x0c066c0eu: goto P_0c066c0e;
case 0x0c066c10u: goto P_0c066c10;
case 0x0c066c12u: goto P_0c066c12;
case 0x0c066c14u: goto P_0c066c14;
case 0x0c066c16u: goto P_0c066c16;
case 0x0c066c18u: goto P_0c066c18;
case 0x0c066c1au: goto P_0c066c1a;
case 0x0c066c1cu: goto P_0c066c1c;
case 0x0c066c1eu: goto P_0c066c1e;
case 0x0c066c20u: goto P_0c066c20;
case 0x0c066c22u: goto P_0c066c22;
case 0x0c066c24u: goto P_0c066c24;
case 0x0c066c26u: goto P_0c066c26;
case 0x0c066c28u: goto P_0c066c28;
case 0x0c066c2au: goto P_0c066c2a;
case 0x0c066c2cu: goto P_0c066c2c;
case 0x0c066c2eu: goto P_0c066c2e;
case 0x0c066c30u: goto P_0c066c30;
case 0x0c066c32u: goto P_0c066c32;
case 0x0c066c34u: goto P_0c066c34;
case 0x0c066c36u: goto P_0c066c36;
case 0x0c066c38u: goto P_0c066c38;
case 0x0c066c3au: goto P_0c066c3a;
case 0x0c066c3cu: goto P_0c066c3c;
case 0x0c066c3eu: goto P_0c066c3e;
case 0x0c066c40u: goto P_0c066c40;
case 0x0c066c42u: goto P_0c066c42;
case 0x0c066c44u: goto P_0c066c44;
case 0x0c066c46u: goto P_0c066c46;
case 0x0c066c48u: goto P_0c066c48;
case 0x0c066c4au: goto P_0c066c4a;
case 0x0c066c4cu: goto P_0c066c4c;
case 0x0c066c4eu: goto P_0c066c4e;
case 0x0c066c50u: goto P_0c066c50;
case 0x0c066c52u: goto P_0c066c52;
case 0x0c066c54u: goto P_0c066c54;
case 0x0c066c56u: goto P_0c066c56;
case 0x0c066c58u: goto P_0c066c58;
case 0x0c066c5au: goto P_0c066c5a;
case 0x0c066c5cu: goto P_0c066c5c;
case 0x0c066c5eu: goto P_0c066c5e;
case 0x0c066c60u: goto P_0c066c60;
case 0x0c066c62u: goto P_0c066c62;
case 0x0c066c64u: goto P_0c066c64;
case 0x0c066c66u: goto P_0c066c66;
case 0x0c066c68u: goto P_0c066c68;
case 0x0c066c6au: goto P_0c066c6a;
case 0x0c066c6cu: goto P_0c066c6c;
case 0x0c066c6eu: goto P_0c066c6e;
case 0x0c066c70u: goto P_0c066c70;
case 0x0c066c72u: goto P_0c066c72;
case 0x0c066c74u: goto P_0c066c74;
case 0x0c066c76u: goto P_0c066c76;
case 0x0c066c78u: goto P_0c066c78;
case 0x0c066c7au: goto P_0c066c7a;
case 0x0c066c7cu: goto P_0c066c7c;
case 0x0c066c7eu: goto P_0c066c7e;
case 0x0c066c80u: goto P_0c066c80;
case 0x0c066c82u: goto P_0c066c82;
case 0x0c066c84u: goto P_0c066c84;
case 0x0c066c86u: goto P_0c066c86;
case 0x0c066c88u: goto P_0c066c88;
case 0x0c066c8au: goto P_0c066c8a;
case 0x0c066c8cu: goto P_0c066c8c;
case 0x0c066c8eu: goto P_0c066c8e;
case 0x0c066c90u: goto P_0c066c90;
case 0x0c066c92u: goto P_0c066c92;
case 0x0c066c94u: goto P_0c066c94;
case 0x0c066c96u: goto P_0c066c96;
case 0x0c066c98u: goto P_0c066c98;
case 0x0c066c9au: goto P_0c066c9a;
case 0x0c066c9cu: goto P_0c066c9c;
case 0x0c066c9eu: goto P_0c066c9e;
case 0x0c066ca0u: goto P_0c066ca0;
case 0x0c066ca2u: goto P_0c066ca2;
case 0x0c066ca4u: goto P_0c066ca4;
case 0x0c066ca6u: goto P_0c066ca6;
case 0x0c066ca8u: goto P_0c066ca8;
case 0x0c066caau: goto P_0c066caa;
case 0x0c066cacu: goto P_0c066cac;
case 0x0c066caeu: goto P_0c066cae;
case 0x0c066cb0u: goto P_0c066cb0;
case 0x0c066cb2u: goto P_0c066cb2;
case 0x0c066cb4u: goto P_0c066cb4;
case 0x0c066cb6u: goto P_0c066cb6;
case 0x0c066cb8u: goto P_0c066cb8;
case 0x0c066cbau: goto P_0c066cba;
case 0x0c066cbcu: goto P_0c066cbc;
case 0x0c066cbeu: goto P_0c066cbe;
case 0x0c066cc0u: goto P_0c066cc0;
case 0x0c066cc2u: goto P_0c066cc2;
case 0x0c066cc4u: goto P_0c066cc4;
case 0x0c066cc6u: goto P_0c066cc6;
case 0x0c066cc8u: goto P_0c066cc8;
case 0x0c066ccau: goto P_0c066cca;
case 0x0c066cccu: goto P_0c066ccc;
case 0x0c066cceu: goto P_0c066cce;
case 0x0c066cd0u: goto P_0c066cd0;
case 0x0c066cd2u: goto P_0c066cd2;
case 0x0c066cd4u: goto P_0c066cd4;
case 0x0c066cd6u: goto P_0c066cd6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c066a66: /* original e201, guest PC 0x0c066a66 */
if(!s->budget--) { s->failed_pc=0x0c066a66u; return 0; }
r[2]=0x00000001u;
goto P_0c066a68;
P_0c066a68: /* original 2fe6, guest PC 0x0c066a68 */
if(!s->budget--) { s->failed_pc=0x0c066a68u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a6a;
P_0c066a6a: /* original 2fd6, guest PC 0x0c066a6a */
if(!s->budget--) { s->failed_pc=0x0c066a6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a6c;
P_0c066a6c: /* original 2fc6, guest PC 0x0c066a6c */
if(!s->budget--) { s->failed_pc=0x0c066a6cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a6e;
P_0c066a6e: /* original 2fb6, guest PC 0x0c066a6e */
if(!s->budget--) { s->failed_pc=0x0c066a6eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a70;
P_0c066a70: /* original 2fa6, guest PC 0x0c066a70 */
if(!s->budget--) { s->failed_pc=0x0c066a70u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a72;
P_0c066a72: /* original 2f96, guest PC 0x0c066a72 */
if(!s->budget--) { s->failed_pc=0x0c066a72u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a74;
P_0c066a74: /* original 2f86, guest PC 0x0c066a74 */
if(!s->budget--) { s->failed_pc=0x0c066a74u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066a76;
P_0c066a76: /* original 4f22, guest PC 0x0c066a76 */
if(!s->budget--) { s->failed_pc=0x0c066a76u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c066a78;
P_0c066a78: /* original d310, guest PC 0x0c066a78 */
if(!s->budget--) { s->failed_pc=0x0c066a78u; return 0; }
r[3]=read(ram,0x0c066abcu,4);
goto P_0c066a7a;
P_0c066a7a: /* original 7ffc, guest PC 0x0c066a7a */
if(!s->budget--) { s->failed_pc=0x0c066a7au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c066a7c;
P_0c066a7c: /* original 54f9, guest PC 0x0c066a7c */
if(!s->budget--) { s->failed_pc=0x0c066a7cu; return 0; }
r[4]=read(ram,r[15]+36,4);
goto P_0c066a7e;
P_0c066a7e: /* original 2248, guest PC 0x0c066a7e */
if(!s->budget--) { s->failed_pc=0x0c066a7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c066a80;
P_0c066a80: /* original 8d1e, guest PC 0x0c066a80 */
if(!s->budget--) { s->failed_pc=0x0c066a80u; return 0; }
cond=r[17]&1u;
write(ram,r[3],r[4],4);
if(cond) { goto P_0c066ac0; }
goto P_0c066a84;
P_0c066a82: /* original 2342, guest PC 0x0c066a82 */
if(!s->budget--) { s->failed_pc=0x0c066a82u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c066a84;
P_0c066a84: /* original e000, guest PC 0x0c066a84 */
if(!s->budget--) { s->failed_pc=0x0c066a84u; return 0; }
r[0]=0x00000000u;
goto P_0c066a86;
P_0c066a86: /* original a01c, guest PC 0x0c066a86 */
if(!s->budget--) { s->failed_pc=0x0c066a86u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c066ac2;
P_0c066a88: /* original 2f02, guest PC 0x0c066a88 */
if(!s->budget--) { s->failed_pc=0x0c066a88u; return 0; }
write(ram,r[15],r[0],4);
if(!vf3_matrix_family(0x0c066a8au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066a8au; return 0; } return 1;
P_0c066ac0: /* original 2f22, guest PC 0x0c066ac0 */
if(!s->budget--) { s->failed_pc=0x0c066ac0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c066ac2;
P_0c066ac2: /* original d33b, guest PC 0x0c066ac2 */
if(!s->budget--) { s->failed_pc=0x0c066ac2u; return 0; }
r[3]=read(ram,0x0c066bb0u,4);
goto P_0c066ac4;
P_0c066ac4: /* original d23b, guest PC 0x0c066ac4 */
if(!s->budget--) { s->failed_pc=0x0c066ac4u; return 0; }
r[2]=read(ram,0x0c066bb4u,4);
goto P_0c066ac6;
P_0c066ac6: /* original 2349, guest PC 0x0c066ac6 */
if(!s->budget--) { s->failed_pc=0x0c066ac6u; return 0; }
r[3]&=r[4];
goto P_0c066ac8;
P_0c066ac8: /* original 4329, guest PC 0x0c066ac8 */
if(!s->budget--) { s->failed_pc=0x0c066ac8u; return 0; }
r[3]>>=16;
goto P_0c066aca;
P_0c066aca: /* original 2232, guest PC 0x0c066aca */
if(!s->budget--) { s->failed_pc=0x0c066acau; return 0; }
write(ram,r[2],r[3],4);
goto P_0c066acc;
P_0c066acc: /* original d13a, guest PC 0x0c066acc */
if(!s->budget--) { s->failed_pc=0x0c066accu; return 0; }
r[1]=read(ram,0x0c066bb8u,4);
goto P_0c066ace;
P_0c066ace: /* original 2149, guest PC 0x0c066ace */
if(!s->budget--) { s->failed_pc=0x0c066aceu; return 0; }
r[1]&=r[4];
goto P_0c066ad0;
P_0c066ad0: /* original d33a, guest PC 0x0c066ad0 */
if(!s->budget--) { s->failed_pc=0x0c066ad0u; return 0; }
r[3]=read(ram,0x0c066bbcu,4);
goto P_0c066ad2;
P_0c066ad2: /* original 4129, guest PC 0x0c066ad2 */
if(!s->budget--) { s->failed_pc=0x0c066ad2u; return 0; }
r[1]>>=16;
goto P_0c066ad4;
P_0c066ad4: /* original 4101, guest PC 0x0c066ad4 */
if(!s->budget--) { s->failed_pc=0x0c066ad4u; return 0; }
r[17]=(r[17]&~1u)|((r[1]&1)!=0);
r[1]>>=1;
goto P_0c066ad6;
P_0c066ad6: /* original 2312, guest PC 0x0c066ad6 */
if(!s->budget--) { s->failed_pc=0x0c066ad6u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c066ad8;
P_0c066ad8: /* original d039, guest PC 0x0c066ad8 */
if(!s->budget--) { s->failed_pc=0x0c066ad8u; return 0; }
r[0]=read(ram,0x0c066bc0u,4);
goto P_0c066ada;
P_0c066ada: /* original 7208, guest PC 0x0c066ada */
if(!s->budget--) { s->failed_pc=0x0c066adau; return 0; }
r[2]+=0x00000008u;
goto P_0c066adc;
P_0c066adc: /* original 2049, guest PC 0x0c066adc */
if(!s->budget--) { s->failed_pc=0x0c066adcu; return 0; }
r[0]&=r[4];
goto P_0c066ade;
P_0c066ade: /* original 4029, guest PC 0x0c066ade */
if(!s->budget--) { s->failed_pc=0x0c066adeu; return 0; }
r[0]>>=16;
goto P_0c066ae0;
P_0c066ae0: /* original 4009, guest PC 0x0c066ae0 */
if(!s->budget--) { s->failed_pc=0x0c066ae0u; return 0; }
r[0]>>=2;
goto P_0c066ae2;
P_0c066ae2: /* original 4001, guest PC 0x0c066ae2 */
if(!s->budget--) { s->failed_pc=0x0c066ae2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c066ae4;
P_0c066ae4: /* original 2202, guest PC 0x0c066ae4 */
if(!s->budget--) { s->failed_pc=0x0c066ae4u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c066ae6;
P_0c066ae6: /* original e3eb, guest PC 0x0c066ae6 */
if(!s->budget--) { s->failed_pc=0x0c066ae6u; return 0; }
r[3]=0xffffffebu;
goto P_0c066ae8;
P_0c066ae8: /* original d037, guest PC 0x0c066ae8 */
if(!s->budget--) { s->failed_pc=0x0c066ae8u; return 0; }
r[0]=read(ram,0x0c066bc8u,4);
goto P_0c066aea;
P_0c066aea: /* original d136, guest PC 0x0c066aea */
if(!s->budget--) { s->failed_pc=0x0c066aeau; return 0; }
r[1]=read(ram,0x0c066bc4u,4);
goto P_0c066aec;
P_0c066aec: /* original 2149, guest PC 0x0c066aec */
if(!s->budget--) { s->failed_pc=0x0c066aecu; return 0; }
r[1]&=r[4];
goto P_0c066aee;
P_0c066aee: /* original 413d, guest PC 0x0c066aee */
if(!s->budget--) { s->failed_pc=0x0c066aeeu; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?r[1]>>((-r[3])&31u):0):r[1]<<(r[3]&31u);
goto P_0c066af0;
P_0c066af0: /* original 2012, guest PC 0x0c066af0 */
if(!s->budget--) { s->failed_pc=0x0c066af0u; return 0; }
write(ram,r[0],r[1],4);
goto P_0c066af2;
P_0c066af2: /* original e2e9, guest PC 0x0c066af2 */
if(!s->budget--) { s->failed_pc=0x0c066af2u; return 0; }
r[2]=0xffffffe9u;
goto P_0c066af4;
P_0c066af4: /* original d136, guest PC 0x0c066af4 */
if(!s->budget--) { s->failed_pc=0x0c066af4u; return 0; }
r[1]=read(ram,0x0c066bd0u,4);
goto P_0c066af6;
P_0c066af6: /* original d335, guest PC 0x0c066af6 */
if(!s->budget--) { s->failed_pc=0x0c066af6u; return 0; }
r[3]=read(ram,0x0c066bccu,4);
goto P_0c066af8;
P_0c066af8: /* original 2349, guest PC 0x0c066af8 */
if(!s->budget--) { s->failed_pc=0x0c066af8u; return 0; }
r[3]&=r[4];
goto P_0c066afa;
P_0c066afa: /* original 432d, guest PC 0x0c066afa */
if(!s->budget--) { s->failed_pc=0x0c066afau; return 0; }
r[3]=(r[2]&0x80000000u)?((r[2]&31u)?r[3]>>((-r[2])&31u):0):r[3]<<(r[2]&31u);
goto P_0c066afc;
P_0c066afc: /* original 2132, guest PC 0x0c066afc */
if(!s->budget--) { s->failed_pc=0x0c066afcu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c066afe;
P_0c066afe: /* original d235, guest PC 0x0c066afe */
if(!s->budget--) { s->failed_pc=0x0c066afeu; return 0; }
r[2]=read(ram,0x0c066bd4u,4);
goto P_0c066b00;
P_0c066b00: /* original d335, guest PC 0x0c066b00 */
if(!s->budget--) { s->failed_pc=0x0c066b00u; return 0; }
r[3]=read(ram,0x0c066bd8u,4);
goto P_0c066b02;
P_0c066b02: /* original 2429, guest PC 0x0c066b02 */
if(!s->budget--) { s->failed_pc=0x0c066b02u; return 0; }
r[4]&=r[2];
goto P_0c066b04;
P_0c066b04: /* original 4429, guest PC 0x0c066b04 */
if(!s->budget--) { s->failed_pc=0x0c066b04u; return 0; }
r[4]>>=16;
goto P_0c066b06;
P_0c066b06: /* original 4419, guest PC 0x0c066b06 */
if(!s->budget--) { s->failed_pc=0x0c066b06u; return 0; }
r[4]>>=8;
goto P_0c066b08;
P_0c066b08: /* original 4401, guest PC 0x0c066b08 */
if(!s->budget--) { s->failed_pc=0x0c066b08u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c066b0a;
P_0c066b0a: /* original 2342, guest PC 0x0c066b0a */
if(!s->budget--) { s->failed_pc=0x0c066b0au; return 0; }
write(ram,r[3],r[4],4);
goto P_0c066b0c;
P_0c066b0c: /* original 70a0, guest PC 0x0c066b0c */
if(!s->budget--) { s->failed_pc=0x0c066b0cu; return 0; }
r[0]+=0xffffffa0u;
goto P_0c066b0e;
P_0c066b0e: /* original 6102, guest PC 0x0c066b0e */
if(!s->budget--) { s->failed_pc=0x0c066b0eu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c066b10;
P_0c066b10: /* original 4109, guest PC 0x0c066b10 */
if(!s->budget--) { s->failed_pc=0x0c066b10u; return 0; }
r[1]>>=2;
goto P_0c066b12;
P_0c066b12: /* original 6313, guest PC 0x0c066b12 */
if(!s->budget--) { s->failed_pc=0x0c066b12u; return 0; }
r[3]=r[1];
goto P_0c066b14;
P_0c066b14: /* original 4100, guest PC 0x0c066b14 */
if(!s->budget--) { s->failed_pc=0x0c066b14u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c066b16;
P_0c066b16: /* original 313c, guest PC 0x0c066b16 */
if(!s->budget--) { s->failed_pc=0x0c066b16u; return 0; }
r[1]+=r[3];
goto P_0c066b18;
P_0c066b18: /* original d330, guest PC 0x0c066b18 */
if(!s->budget--) { s->failed_pc=0x0c066b18u; return 0; }
r[3]=read(ram,0x0c066bdcu,4);
goto P_0c066b1a;
P_0c066b1a: /* original 2312, guest PC 0x0c066b1a */
if(!s->budget--) { s->failed_pc=0x0c066b1au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c066b1c;
P_0c066b1c: /* original d130, guest PC 0x0c066b1c */
if(!s->budget--) { s->failed_pc=0x0c066b1cu; return 0; }
r[1]=read(ram,0x0c066be0u,4);
goto P_0c066b1e;
P_0c066b1e: /* original 6212, guest PC 0x0c066b1e */
if(!s->budget--) { s->failed_pc=0x0c066b1eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c066b20;
P_0c066b20: /* original 5134, guest PC 0x0c066b20 */
if(!s->budget--) { s->failed_pc=0x0c066b20u; return 0; }
r[1]=read(ram,r[3]+16,4);
goto P_0c066b22;
P_0c066b22: /* original 0127, guest PC 0x0c066b22 */
if(!s->budget--) { s->failed_pc=0x0c066b22u; return 0; }
r[19]=r[1]*r[2];
goto P_0c066b24;
P_0c066b24: /* original bbba, guest PC 0x0c066b24 */
if(!s->budget--) { s->failed_pc=0x0c066b24u; return 0; }
target=code_base|0x0c06629cu; r[16]=code_base|0x0c066b28u;
r[4]=r[19];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066b28u) { target=s->pc; goto dispatch; }
goto P_0c066b28;
P_0c066b26: /* original 041a, guest PC 0x0c066b26 */
if(!s->budget--) { s->failed_pc=0x0c066b26u; return 0; }
r[4]=r[19];
goto P_0c066b28;
P_0c066b28: /* original 9940, guest PC 0x0c066b28 */
if(!s->budget--) { s->failed_pc=0x0c066b28u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066bacu,2);
goto P_0c066b2a;
P_0c066b2a: /* original ede0, guest PC 0x0c066b2a */
if(!s->budget--) { s->failed_pc=0x0c066b2au; return 0; }
r[13]=0xffffffe0u;
goto P_0c066b2c;
P_0c066b2c: /* original 6c03, guest PC 0x0c066b2c */
if(!s->budget--) { s->failed_pc=0x0c066b2cu; return 0; }
r[12]=r[0];
goto P_0c066b2e;
P_0c066b2e: /* original eb00, guest PC 0x0c066b2e */
if(!s->budget--) { s->failed_pc=0x0c066b2eu; return 0; }
r[11]=0x00000000u;
goto P_0c066b30;
P_0c066b30: /* original 6ab3, guest PC 0x0c066b30 */
if(!s->budget--) { s->failed_pc=0x0c066b30u; return 0; }
r[10]=r[11];
goto P_0c066b32;
P_0c066b32: /* original 66b3, guest PC 0x0c066b32 */
if(!s->budget--) { s->failed_pc=0x0c066b32u; return 0; }
r[6]=r[11];
goto P_0c066b34;
P_0c066b34: /* original 65b3, guest PC 0x0c066b34 */
if(!s->budget--) { s->failed_pc=0x0c066b34u; return 0; }
r[5]=r[11];
goto P_0c066b36;
P_0c066b36: /* original 64b3, guest PC 0x0c066b36 */
if(!s->budget--) { s->failed_pc=0x0c066b36u; return 0; }
r[4]=r[11];
goto P_0c066b38;
P_0c066b38: /* original e802, guest PC 0x0c066b38 */
if(!s->budget--) { s->failed_pc=0x0c066b38u; return 0; }
r[8]=0x00000002u;
goto P_0c066b3a;
P_0c066b3a: /* original e780, guest PC 0x0c066b3a */
if(!s->budget--) { s->failed_pc=0x0c066b3au; return 0; }
r[7]=0xffffff80u;
goto P_0c066b3c;
P_0c066b3c: /* original d129, guest PC 0x0c066b3c */
if(!s->budget--) { s->failed_pc=0x0c066b3cu; return 0; }
r[1]=read(ram,0x0c066be4u,4);
goto P_0c066b3e;
P_0c066b3e: /* original 6eb3, guest PC 0x0c066b3e */
if(!s->budget--) { s->failed_pc=0x0c066b3eu; return 0; }
r[14]=r[11];
goto P_0c066b40;
P_0c066b40: /* original 4e08, guest PC 0x0c066b40 */
if(!s->budget--) { s->failed_pc=0x0c066b40u; return 0; }
r[14]<<=2;
goto P_0c066b42;
P_0c066b42: /* original 4e08, guest PC 0x0c066b42 */
if(!s->budget--) { s->failed_pc=0x0c066b42u; return 0; }
r[14]<<=2;
goto P_0c066b44;
P_0c066b44: /* original 4e00, guest PC 0x0c066b44 */
if(!s->budget--) { s->failed_pc=0x0c066b44u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c066b46;
P_0c066b46: /* original 6312, guest PC 0x0c066b46 */
if(!s->budget--) { s->failed_pc=0x0c066b46u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c066b48;
P_0c066b48: /* original d027, guest PC 0x0c066b48 */
if(!s->budget--) { s->failed_pc=0x0c066b48u; return 0; }
r[0]=read(ram,0x0c066be8u,4);
goto P_0c066b4a;
P_0c066b4a: /* original 02ee, guest PC 0x0c066b4a */
if(!s->budget--) { s->failed_pc=0x0c066b4au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c066b4c;
P_0c066b4c: /* original 323c, guest PC 0x0c066b4c */
if(!s->budget--) { s->failed_pc=0x0c066b4cu; return 0; }
r[2]+=r[3];
goto P_0c066b4e;
P_0c066b4e: /* original 7004, guest PC 0x0c066b4e */
if(!s->budget--) { s->failed_pc=0x0c066b4eu; return 0; }
r[0]+=0x00000004u;
goto P_0c066b50;
P_0c066b50: /* original 0e26, guest PC 0x0c066b50 */
if(!s->budget--) { s->failed_pc=0x0c066b50u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c066b52;
P_0c066b52: /* original d326, guest PC 0x0c066b52 */
if(!s->budget--) { s->failed_pc=0x0c066b52u; return 0; }
r[3]=read(ram,0x0c066becu,4);
goto P_0c066b54;
P_0c066b54: /* original 6032, guest PC 0x0c066b54 */
if(!s->budget--) { s->failed_pc=0x0c066b54u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c066b56;
P_0c066b56: /* original c820, guest PC 0x0c066b56 */
if(!s->budget--) { s->failed_pc=0x0c066b56u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c066b58;
P_0c066b58: /* original 8950, guest PC 0x0c066b58 */
if(!s->budget--) { s->failed_pc=0x0c066b58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066bfc; }
goto P_0c066b5a;
P_0c066b5a: /* original d025, guest PC 0x0c066b5a */
if(!s->budget--) { s->failed_pc=0x0c066b5au; return 0; }
r[0]=read(ram,0x0c066bf0u,4);
goto P_0c066b5c;
P_0c066b5c: /* original 6202, guest PC 0x0c066b5c */
if(!s->budget--) { s->failed_pc=0x0c066b5cu; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c066b5e;
P_0c066b5e: /* original 2228, guest PC 0x0c066b5e */
if(!s->budget--) { s->failed_pc=0x0c066b5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c066b60;
P_0c066b60: /* original 8913, guest PC 0x0c066b60 */
if(!s->budget--) { s->failed_pc=0x0c066b60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c066b8a; }
goto P_0c066b62;
P_0c066b62: /* original d024, guest PC 0x0c066b62 */
if(!s->budget--) { s->failed_pc=0x0c066b62u; return 0; }
r[0]=read(ram,0x0c066bf4u,4);
goto P_0c066b64;
P_0c066b64: /* original 02ee, guest PC 0x0c066b64 */
if(!s->budget--) { s->failed_pc=0x0c066b64u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c066b66;
P_0c066b66: /* original 72bc, guest PC 0x0c066b66 */
if(!s->budget--) { s->failed_pc=0x0c066b66u; return 0; }
r[2]+=0xffffffbcu;
goto P_0c066b68;
P_0c066b68: /* original 0e26, guest PC 0x0c066b68 */
if(!s->budget--) { s->failed_pc=0x0c066b68u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c066b6a;
P_0c066b6a: /* original d11d, guest PC 0x0c066b6a */
if(!s->budget--) { s->failed_pc=0x0c066b6au; return 0; }
r[1]=read(ram,0x0c066be0u,4);
goto P_0c066b6c;
P_0c066b6c: /* original 6212, guest PC 0x0c066b6c */
if(!s->budget--) { s->failed_pc=0x0c066b6cu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c066b6e;
P_0c066b6e: /* original d322, guest PC 0x0c066b6e */
if(!s->budget--) { s->failed_pc=0x0c066b6eu; return 0; }
r[3]=read(ram,0x0c066bf8u,4);
goto P_0c066b70;
P_0c066b70: /* original 6132, guest PC 0x0c066b70 */
if(!s->budget--) { s->failed_pc=0x0c066b70u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c066b72;
P_0c066b72: /* original 0127, guest PC 0x0c066b72 */
if(!s->budget--) { s->failed_pc=0x0c066b72u; return 0; }
r[19]=r[1]*r[2];
goto P_0c066b74;
P_0c066b74: /* original 021a, guest PC 0x0c066b74 */
if(!s->budget--) { s->failed_pc=0x0c066b74u; return 0; }
r[2]=r[19];
goto P_0c066b76;
P_0c066b76: /* original 6123, guest PC 0x0c066b76 */
if(!s->budget--) { s->failed_pc=0x0c066b76u; return 0; }
r[1]=r[2];
goto P_0c066b78;
P_0c066b78: /* original 4200, guest PC 0x0c066b78 */
if(!s->budget--) { s->failed_pc=0x0c066b78u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c066b7a;
P_0c066b7a: /* original 321c, guest PC 0x0c066b7a */
if(!s->budget--) { s->failed_pc=0x0c066b7au; return 0; }
r[2]+=r[1];
goto P_0c066b7c;
P_0c066b7c: /* original 4208, guest PC 0x0c066b7c */
if(!s->budget--) { s->failed_pc=0x0c066b7cu; return 0; }
r[2]<<=2;
goto P_0c066b7e;
P_0c066b7e: /* original 4208, guest PC 0x0c066b7e */
if(!s->budget--) { s->failed_pc=0x0c066b7eu; return 0; }
r[2]<<=2;
goto P_0c066b80;
P_0c066b80: /* original 4200, guest PC 0x0c066b80 */
if(!s->budget--) { s->failed_pc=0x0c066b80u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c066b82;
P_0c066b82: /* original 01ee, guest PC 0x0c066b82 */
if(!s->budget--) { s->failed_pc=0x0c066b82u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c066b84;
P_0c066b84: /* original 3128, guest PC 0x0c066b84 */
if(!s->budget--) { s->failed_pc=0x0c066b84u; return 0; }
r[1]-=r[2];
goto P_0c066b86;
P_0c066b86: /* original a00f, guest PC 0x0c066b86 */
if(!s->budget--) { s->failed_pc=0x0c066b86u; return 0; }
goto P_0c066ba8;
P_0c066b88: /* original 0009, guest PC 0x0c066b88 */
if(!s->budget--) { s->failed_pc=0x0c066b88u; return 0; }
goto P_0c066b8a;
P_0c066b8a: /* original d01a, guest PC 0x0c066b8a */
if(!s->budget--) { s->failed_pc=0x0c066b8au; return 0; }
r[0]=read(ram,0x0c066bf4u,4);
goto P_0c066b8c;
P_0c066b8c: /* original 6103, guest PC 0x0c066b8c */
if(!s->budget--) { s->failed_pc=0x0c066b8cu; return 0; }
r[1]=r[0];
goto P_0c066b8e;
P_0c066b8e: /* original 71f0, guest PC 0x0c066b8e */
if(!s->budget--) { s->failed_pc=0x0c066b8eu; return 0; }
r[1]+=0xfffffff0u;
goto P_0c066b90;
P_0c066b90: /* original 6212, guest PC 0x0c066b90 */
if(!s->budget--) { s->failed_pc=0x0c066b90u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c066b92;
P_0c066b92: /* original d319, guest PC 0x0c066b92 */
if(!s->budget--) { s->failed_pc=0x0c066b92u; return 0; }
r[3]=read(ram,0x0c066bf8u,4);
goto P_0c066b94;
P_0c066b94: /* original 6132, guest PC 0x0c066b94 */
if(!s->budget--) { s->failed_pc=0x0c066b94u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c066b96;
P_0c066b96: /* original 0127, guest PC 0x0c066b96 */
if(!s->budget--) { s->failed_pc=0x0c066b96u; return 0; }
r[19]=r[1]*r[2];
goto P_0c066b98;
P_0c066b98: /* original 021a, guest PC 0x0c066b98 */
if(!s->budget--) { s->failed_pc=0x0c066b98u; return 0; }
r[2]=r[19];
goto P_0c066b9a;
P_0c066b9a: /* original 6123, guest PC 0x0c066b9a */
if(!s->budget--) { s->failed_pc=0x0c066b9au; return 0; }
r[1]=r[2];
goto P_0c066b9c;
P_0c066b9c: /* original 4200, guest PC 0x0c066b9c */
if(!s->budget--) { s->failed_pc=0x0c066b9cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c066b9e;
P_0c066b9e: /* original 321c, guest PC 0x0c066b9e */
if(!s->budget--) { s->failed_pc=0x0c066b9eu; return 0; }
r[2]+=r[1];
goto P_0c066ba0;
P_0c066ba0: /* original 4208, guest PC 0x0c066ba0 */
if(!s->budget--) { s->failed_pc=0x0c066ba0u; return 0; }
r[2]<<=2;
goto P_0c066ba2;
P_0c066ba2: /* original 4208, guest PC 0x0c066ba2 */
if(!s->budget--) { s->failed_pc=0x0c066ba2u; return 0; }
r[2]<<=2;
goto P_0c066ba4;
P_0c066ba4: /* original 01ee, guest PC 0x0c066ba4 */
if(!s->budget--) { s->failed_pc=0x0c066ba4u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c066ba6;
P_0c066ba6: /* original 3128, guest PC 0x0c066ba6 */
if(!s->budget--) { s->failed_pc=0x0c066ba6u; return 0; }
r[1]-=r[2];
goto P_0c066ba8;
P_0c066ba8: /* original a038, guest PC 0x0c066ba8 */
if(!s->budget--) { s->failed_pc=0x0c066ba8u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c066c1c;
P_0c066baa: /* original 0e16, guest PC 0x0c066baa */
if(!s->budget--) { s->failed_pc=0x0c066baau; return 0; }
write(ram,r[14]+r[0],r[1],4);
if(!vf3_matrix_family(0x0c066bacu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066bacu; return 0; } return 1;
P_0c066bfc: /* original d03e, guest PC 0x0c066bfc */
if(!s->budget--) { s->failed_pc=0x0c066bfcu; return 0; }
r[0]=read(ram,0x0c066cf8u,4);
goto P_0c066bfe;
P_0c066bfe: /* original 6103, guest PC 0x0c066bfe */
if(!s->budget--) { s->failed_pc=0x0c066bfeu; return 0; }
r[1]=r[0];
goto P_0c066c00;
P_0c066c00: /* original 71f0, guest PC 0x0c066c00 */
if(!s->budget--) { s->failed_pc=0x0c066c00u; return 0; }
r[1]+=0xfffffff0u;
goto P_0c066c02;
P_0c066c02: /* original 6212, guest PC 0x0c066c02 */
if(!s->budget--) { s->failed_pc=0x0c066c02u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c066c04;
P_0c066c04: /* original d33d, guest PC 0x0c066c04 */
if(!s->budget--) { s->failed_pc=0x0c066c04u; return 0; }
r[3]=read(ram,0x0c066cfcu,4);
goto P_0c066c06;
P_0c066c06: /* original 6132, guest PC 0x0c066c06 */
if(!s->budget--) { s->failed_pc=0x0c066c06u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c066c08;
P_0c066c08: /* original 0127, guest PC 0x0c066c08 */
if(!s->budget--) { s->failed_pc=0x0c066c08u; return 0; }
r[19]=r[1]*r[2];
goto P_0c066c0a;
P_0c066c0a: /* original 021a, guest PC 0x0c066c0a */
if(!s->budget--) { s->failed_pc=0x0c066c0au; return 0; }
r[2]=r[19];
goto P_0c066c0c;
P_0c066c0c: /* original 6123, guest PC 0x0c066c0c */
if(!s->budget--) { s->failed_pc=0x0c066c0cu; return 0; }
r[1]=r[2];
goto P_0c066c0e;
P_0c066c0e: /* original 4200, guest PC 0x0c066c0e */
if(!s->budget--) { s->failed_pc=0x0c066c0eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c066c10;
P_0c066c10: /* original 321c, guest PC 0x0c066c10 */
if(!s->budget--) { s->failed_pc=0x0c066c10u; return 0; }
r[2]+=r[1];
goto P_0c066c12;
P_0c066c12: /* original 4208, guest PC 0x0c066c12 */
if(!s->budget--) { s->failed_pc=0x0c066c12u; return 0; }
r[2]<<=2;
goto P_0c066c14;
P_0c066c14: /* original 4200, guest PC 0x0c066c14 */
if(!s->budget--) { s->failed_pc=0x0c066c14u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c066c16;
P_0c066c16: /* original 01ee, guest PC 0x0c066c16 */
if(!s->budget--) { s->failed_pc=0x0c066c16u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c066c18;
P_0c066c18: /* original 3128, guest PC 0x0c066c18 */
if(!s->budget--) { s->failed_pc=0x0c066c18u; return 0; }
r[1]-=r[2];
goto P_0c066c1a;
P_0c066c1a: /* original 0e16, guest PC 0x0c066c1a */
if(!s->budget--) { s->failed_pc=0x0c066c1au; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c066c1c;
P_0c066c1c: /* original d238, guest PC 0x0c066c1c */
if(!s->budget--) { s->failed_pc=0x0c066c1cu; return 0; }
r[2]=read(ram,0x0c066d00u,4);
goto P_0c066c1e;
P_0c066c1e: /* original 6322, guest PC 0x0c066c1e */
if(!s->budget--) { s->failed_pc=0x0c066c1eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c066c20;
P_0c066c20: /* original 2338, guest PC 0x0c066c20 */
if(!s->budget--) { s->failed_pc=0x0c066c20u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c066c22;
P_0c066c22: /* original 8b14, guest PC 0x0c066c22 */
if(!s->budget--) { s->failed_pc=0x0c066c22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c066c4e; }
goto P_0c066c24;
P_0c066c24: /* original d137, guest PC 0x0c066c24 */
if(!s->budget--) { s->failed_pc=0x0c066c24u; return 0; }
r[1]=read(ram,0x0c066d04u,4);
goto P_0c066c26;
P_0c066c26: /* original 6312, guest PC 0x0c066c26 */
if(!s->budget--) { s->failed_pc=0x0c066c26u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c066c28;
P_0c066c28: /* original d037, guest PC 0x0c066c28 */
if(!s->budget--) { s->failed_pc=0x0c066c28u; return 0; }
r[0]=read(ram,0x0c066d08u,4);
goto P_0c066c2a;
P_0c066c2a: /* original 004e, guest PC 0x0c066c2a */
if(!s->budget--) { s->failed_pc=0x0c066c2au; return 0; }
r[0]=read(ram,r[4]+r[0],4);
goto P_0c066c2c;
P_0c066c2c: /* original 303c, guest PC 0x0c066c2c */
if(!s->budget--) { s->failed_pc=0x0c066c2cu; return 0; }
r[0]+=r[3];
goto P_0c066c2e;
P_0c066c2e: /* original 20d9, guest PC 0x0c066c2e */
if(!s->budget--) { s->failed_pc=0x0c066c2eu; return 0; }
r[0]&=r[13];
goto P_0c066c30;
P_0c066c30: /* original d236, guest PC 0x0c066c30 */
if(!s->budget--) { s->failed_pc=0x0c066c30u; return 0; }
r[2]=read(ram,0x0c066d0cu,4);
goto P_0c066c32;
P_0c066c32: /* original 324c, guest PC 0x0c066c32 */
if(!s->budget--) { s->failed_pc=0x0c066c32u; return 0; }
r[2]+=r[4];
goto P_0c066c34;
P_0c066c34: /* original 2202, guest PC 0x0c066c34 */
if(!s->budget--) { s->failed_pc=0x0c066c34u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c066c36;
P_0c066c36: /* original d030, guest PC 0x0c066c36 */
if(!s->budget--) { s->failed_pc=0x0c066c36u; return 0; }
r[0]=read(ram,0x0c066cf8u,4);
goto P_0c066c38;
P_0c066c38: /* original 034e, guest PC 0x0c066c38 */
if(!s->budget--) { s->failed_pc=0x0c066c38u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c066c3a;
P_0c066c3a: /* original 33c8, guest PC 0x0c066c3a */
if(!s->budget--) { s->failed_pc=0x0c066c3au; return 0; }
r[3]-=r[12];
goto P_0c066c3c;
P_0c066c3c: /* original 2379, guest PC 0x0c066c3c */
if(!s->budget--) { s->failed_pc=0x0c066c3cu; return 0; }
r[3]&=r[7];
goto P_0c066c3e;
P_0c066c3e: /* original 700c, guest PC 0x0c066c3e */
if(!s->budget--) { s->failed_pc=0x0c066c3eu; return 0; }
r[0]+=0x0000000cu;
goto P_0c066c40;
P_0c066c40: /* original 0436, guest PC 0x0c066c40 */
if(!s->budget--) { s->failed_pc=0x0c066c40u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c066c42;
P_0c066c42: /* original 70fc, guest PC 0x0c066c42 */
if(!s->budget--) { s->failed_pc=0x0c066c42u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c066c44;
P_0c066c44: /* original 024e, guest PC 0x0c066c44 */
if(!s->budget--) { s->failed_pc=0x0c066c44u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c066c46;
P_0c066c46: /* original 32cc, guest PC 0x0c066c46 */
if(!s->budget--) { s->failed_pc=0x0c066c46u; return 0; }
r[2]+=r[12];
goto P_0c066c48;
P_0c066c48: /* original 7008, guest PC 0x0c066c48 */
if(!s->budget--) { s->failed_pc=0x0c066c48u; return 0; }
r[0]+=0x00000008u;
goto P_0c066c4a;
P_0c066c4a: /* original a012, guest PC 0x0c066c4a */
if(!s->budget--) { s->failed_pc=0x0c066c4au; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c066c72;
P_0c066c4c: /* original 0426, guest PC 0x0c066c4c */
if(!s->budget--) { s->failed_pc=0x0c066c4cu; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c066c4e;
P_0c066c4e: /* original d02a, guest PC 0x0c066c4e */
if(!s->budget--) { s->failed_pc=0x0c066c4eu; return 0; }
r[0]=read(ram,0x0c066cf8u,4);
goto P_0c066c50;
P_0c066c50: /* original 015e, guest PC 0x0c066c50 */
if(!s->budget--) { s->failed_pc=0x0c066c50u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c066c52;
P_0c066c52: /* original 31c8, guest PC 0x0c066c52 */
if(!s->budget--) { s->failed_pc=0x0c066c52u; return 0; }
r[1]-=r[12];
goto P_0c066c54;
P_0c066c54: /* original 2179, guest PC 0x0c066c54 */
if(!s->budget--) { s->failed_pc=0x0c066c54u; return 0; }
r[1]&=r[7];
goto P_0c066c56;
P_0c066c56: /* original 7008, guest PC 0x0c066c56 */
if(!s->budget--) { s->failed_pc=0x0c066c56u; return 0; }
r[0]+=0x00000008u;
goto P_0c066c58;
P_0c066c58: /* original 0516, guest PC 0x0c066c58 */
if(!s->budget--) { s->failed_pc=0x0c066c58u; return 0; }
write(ram,r[5]+r[0],r[1],4);
goto P_0c066c5a;
P_0c066c5a: /* original d12a, guest PC 0x0c066c5a */
if(!s->budget--) { s->failed_pc=0x0c066c5au; return 0; }
r[1]=read(ram,0x0c066d04u,4);
goto P_0c066c5c;
P_0c066c5c: /* original 6312, guest PC 0x0c066c5c */
if(!s->budget--) { s->failed_pc=0x0c066c5cu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c066c5e;
P_0c066c5e: /* original 70f4, guest PC 0x0c066c5e */
if(!s->budget--) { s->failed_pc=0x0c066c5eu; return 0; }
r[0]+=0xfffffff4u;
goto P_0c066c60;
P_0c066c60: /* original 015e, guest PC 0x0c066c60 */
if(!s->budget--) { s->failed_pc=0x0c066c60u; return 0; }
r[1]=read(ram,r[5]+r[0],4);
goto P_0c066c62;
P_0c066c62: /* original 313c, guest PC 0x0c066c62 */
if(!s->budget--) { s->failed_pc=0x0c066c62u; return 0; }
r[1]+=r[3];
goto P_0c066c64;
P_0c066c64: /* original 21d9, guest PC 0x0c066c64 */
if(!s->budget--) { s->failed_pc=0x0c066c64u; return 0; }
r[1]&=r[13];
goto P_0c066c66;
P_0c066c66: /* original 7010, guest PC 0x0c066c66 */
if(!s->budget--) { s->failed_pc=0x0c066c66u; return 0; }
r[0]+=0x00000010u;
goto P_0c066c68;
P_0c066c68: /* original 0516, guest PC 0x0c066c68 */
if(!s->budget--) { s->failed_pc=0x0c066c68u; return 0; }
write(ram,r[5]+r[0],r[1],4);
goto P_0c066c6a;
P_0c066c6a: /* original 70fc, guest PC 0x0c066c6a */
if(!s->budget--) { s->failed_pc=0x0c066c6au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c066c6c;
P_0c066c6c: /* original 035e, guest PC 0x0c066c6c */
if(!s->budget--) { s->failed_pc=0x0c066c6cu; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c066c6e;
P_0c066c6e: /* original 7008, guest PC 0x0c066c6e */
if(!s->budget--) { s->failed_pc=0x0c066c6eu; return 0; }
r[0]+=0x00000008u;
goto P_0c066c70;
P_0c066c70: /* original 0536, guest PC 0x0c066c70 */
if(!s->budget--) { s->failed_pc=0x0c066c70u; return 0; }
write(ram,r[5]+r[0],r[3],4);
goto P_0c066c72;
P_0c066c72: /* original d025, guest PC 0x0c066c72 */
if(!s->budget--) { s->failed_pc=0x0c066c72u; return 0; }
r[0]=read(ram,0x0c066d08u,4);
goto P_0c066c74;
P_0c066c74: /* original 026e, guest PC 0x0c066c74 */
if(!s->budget--) { s->failed_pc=0x0c066c74u; return 0; }
r[2]=read(ram,r[6]+r[0],4);
goto P_0c066c76;
P_0c066c76: /* original 7018, guest PC 0x0c066c76 */
if(!s->budget--) { s->failed_pc=0x0c066c76u; return 0; }
r[0]+=0x00000018u;
goto P_0c066c78;
P_0c066c78: /* original 0626, guest PC 0x0c066c78 */
if(!s->budget--) { s->failed_pc=0x0c066c78u; return 0; }
write(ram,r[6]+r[0],r[2],4);
goto P_0c066c7a;
P_0c066c7a: /* original d222, guest PC 0x0c066c7a */
if(!s->budget--) { s->failed_pc=0x0c066c7au; return 0; }
r[2]=read(ram,0x0c066d04u,4);
goto P_0c066c7c;
P_0c066c7c: /* original 6322, guest PC 0x0c066c7c */
if(!s->budget--) { s->failed_pc=0x0c066c7cu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c066c7e;
P_0c066c7e: /* original 70e8, guest PC 0x0c066c7e */
if(!s->budget--) { s->failed_pc=0x0c066c7eu; return 0; }
r[0]+=0xffffffe8u;
goto P_0c066c80;
P_0c066c80: /* original 016e, guest PC 0x0c066c80 */
if(!s->budget--) { s->failed_pc=0x0c066c80u; return 0; }
r[1]=read(ram,r[6]+r[0],4);
goto P_0c066c82;
P_0c066c82: /* original 313c, guest PC 0x0c066c82 */
if(!s->budget--) { s->failed_pc=0x0c066c82u; return 0; }
r[1]+=r[3];
goto P_0c066c84;
P_0c066c84: /* original 319c, guest PC 0x0c066c84 */
if(!s->budget--) { s->failed_pc=0x0c066c84u; return 0; }
r[1]+=r[9];
goto P_0c066c86;
P_0c066c86: /* original 701c, guest PC 0x0c066c86 */
if(!s->budget--) { s->failed_pc=0x0c066c86u; return 0; }
r[0]+=0x0000001cu;
goto P_0c066c88;
P_0c066c88: /* original 0616, guest PC 0x0c066c88 */
if(!s->budget--) { s->failed_pc=0x0c066c88u; return 0; }
write(ram,r[6]+r[0],r[1],4);
goto P_0c066c8a;
P_0c066c8a: /* original 7b01, guest PC 0x0c066c8a */
if(!s->budget--) { s->failed_pc=0x0c066c8au; return 0; }
r[11]+=0x00000001u;
goto P_0c066c8c;
P_0c066c8c: /* original 7620, guest PC 0x0c066c8c */
if(!s->budget--) { s->failed_pc=0x0c066c8cu; return 0; }
r[6]+=0x00000020u;
goto P_0c066c8e;
P_0c066c8e: /* original 7520, guest PC 0x0c066c8e */
if(!s->budget--) { s->failed_pc=0x0c066c8eu; return 0; }
r[5]+=0x00000020u;
goto P_0c066c90;
P_0c066c90: /* original 3b83, guest PC 0x0c066c90 */
if(!s->budget--) { s->failed_pc=0x0c066c90u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[8])!=0);
goto P_0c066c92;
P_0c066c92: /* original 8d02, guest PC 0x0c066c92 */
if(!s->budget--) { s->failed_pc=0x0c066c92u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000020u;
if(cond) { goto P_0c066c9a; }
goto P_0c066c96;
P_0c066c94: /* original 7420, guest PC 0x0c066c94 */
if(!s->budget--) { s->failed_pc=0x0c066c94u; return 0; }
r[4]+=0x00000020u;
goto P_0c066c96;
P_0c066c96: /* original af51, guest PC 0x0c066c96 */
if(!s->budget--) { s->failed_pc=0x0c066c96u; return 0; }
goto P_0c066b3c;
P_0c066c98: /* original 0009, guest PC 0x0c066c98 */
if(!s->budget--) { s->failed_pc=0x0c066c98u; return 0; }
goto P_0c066c9a;
P_0c066c9a: /* original e701, guest PC 0x0c066c9a */
if(!s->budget--) { s->failed_pc=0x0c066c9au; return 0; }
r[7]=0x00000001u;
goto P_0c066c9c;
P_0c066c9c: /* original d31c, guest PC 0x0c066c9c */
if(!s->budget--) { s->failed_pc=0x0c066c9cu; return 0; }
r[3]=read(ram,0x0c066d10u,4);
goto P_0c066c9e;
P_0c066c9e: /* original e600, guest PC 0x0c066c9e */
if(!s->budget--) { s->failed_pc=0x0c066c9eu; return 0; }
r[6]=0x00000000u;
goto P_0c066ca0;
P_0c066ca0: /* original 62f2, guest PC 0x0c066ca0 */
if(!s->budget--) { s->failed_pc=0x0c066ca0u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c066ca2;
P_0c066ca2: /* original 2f26, guest PC 0x0c066ca2 */
if(!s->budget--) { s->failed_pc=0x0c066ca2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066ca4;
P_0c066ca4: /* original 2fa6, guest PC 0x0c066ca4 */
if(!s->budget--) { s->failed_pc=0x0c066ca4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066ca6;
P_0c066ca6: /* original 6532, guest PC 0x0c066ca6 */
if(!s->budget--) { s->failed_pc=0x0c066ca6u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c066ca8;
P_0c066ca8: /* original d214, guest PC 0x0c066ca8 */
if(!s->budget--) { s->failed_pc=0x0c066ca8u; return 0; }
r[2]=read(ram,0x0c066cfcu,4);
goto P_0c066caa;
P_0c066caa: /* original bbc8, guest PC 0x0c066caa */
if(!s->budget--) { s->failed_pc=0x0c066caau; return 0; }
target=code_base|0x0c06643eu; r[16]=code_base|0x0c066caeu;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066caeu) { target=s->pc; goto dispatch; }
goto P_0c066cae;
P_0c066cac: /* original 6422, guest PC 0x0c066cac */
if(!s->budget--) { s->failed_pc=0x0c066cacu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c066cae;
P_0c066cae: /* original e201, guest PC 0x0c066cae */
if(!s->budget--) { s->failed_pc=0x0c066caeu; return 0; }
r[2]=0x00000001u;
goto P_0c066cb0;
P_0c066cb0: /* original 53f2, guest PC 0x0c066cb0 */
if(!s->budget--) { s->failed_pc=0x0c066cb0u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c066cb2;
P_0c066cb2: /* original e600, guest PC 0x0c066cb2 */
if(!s->budget--) { s->failed_pc=0x0c066cb2u; return 0; }
r[6]=0x00000000u;
goto P_0c066cb4;
P_0c066cb4: /* original 2f36, guest PC 0x0c066cb4 */
if(!s->budget--) { s->failed_pc=0x0c066cb4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066cb6;
P_0c066cb6: /* original 6723, guest PC 0x0c066cb6 */
if(!s->budget--) { s->failed_pc=0x0c066cb6u; return 0; }
r[7]=r[2];
goto P_0c066cb8;
P_0c066cb8: /* original 2f26, guest PC 0x0c066cb8 */
if(!s->budget--) { s->failed_pc=0x0c066cb8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c066cba;
P_0c066cba: /* original d315, guest PC 0x0c066cba */
if(!s->budget--) { s->failed_pc=0x0c066cbau; return 0; }
r[3]=read(ram,0x0c066d10u,4);
goto P_0c066cbc;
P_0c066cbc: /* original 6532, guest PC 0x0c066cbc */
if(!s->budget--) { s->failed_pc=0x0c066cbcu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c066cbe;
P_0c066cbe: /* original d10f, guest PC 0x0c066cbe */
if(!s->budget--) { s->failed_pc=0x0c066cbeu; return 0; }
r[1]=read(ram,0x0c066cfcu,4);
goto P_0c066cc0;
P_0c066cc0: /* original bbbd, guest PC 0x0c066cc0 */
if(!s->budget--) { s->failed_pc=0x0c066cc0u; return 0; }
target=code_base|0x0c06643eu; r[16]=code_base|0x0c066cc4u;
tmp=read(ram,r[1],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066cc4u) { target=s->pc; goto dispatch; }
goto P_0c066cc4;
P_0c066cc2: /* original 6412, guest PC 0x0c066cc2 */
if(!s->budget--) { s->failed_pc=0x0c066cc2u; return 0; }
tmp=read(ram,r[1],4);
r[4]=tmp;
goto P_0c066cc4;
P_0c066cc4: /* original 7f14, guest PC 0x0c066cc4 */
if(!s->budget--) { s->failed_pc=0x0c066cc4u; return 0; }
r[15]+=0x00000014u;
goto P_0c066cc6;
P_0c066cc6: /* original 4f26, guest PC 0x0c066cc6 */
if(!s->budget--) { s->failed_pc=0x0c066cc6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c066cc8;
P_0c066cc8: /* original 68f6, guest PC 0x0c066cc8 */
if(!s->budget--) { s->failed_pc=0x0c066cc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c066cca;
P_0c066cca: /* original 69f6, guest PC 0x0c066cca */
if(!s->budget--) { s->failed_pc=0x0c066ccau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c066ccc;
P_0c066ccc: /* original 6af6, guest PC 0x0c066ccc */
if(!s->budget--) { s->failed_pc=0x0c066cccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c066cce;
P_0c066cce: /* original 6bf6, guest PC 0x0c066cce */
if(!s->budget--) { s->failed_pc=0x0c066cceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c066cd0;
P_0c066cd0: /* original 6cf6, guest PC 0x0c066cd0 */
if(!s->budget--) { s->failed_pc=0x0c066cd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c066cd2;
P_0c066cd2: /* original 6df6, guest PC 0x0c066cd2 */
if(!s->budget--) { s->failed_pc=0x0c066cd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c066cd4;
P_0c066cd4: /* original 000b, guest PC 0x0c066cd4 */
if(!s->budget--) { s->failed_pc=0x0c066cd4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066cd6: /* original 6ef6, guest PC 0x0c066cd6 */
if(!s->budget--) { s->failed_pc=0x0c066cd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c066cd8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066cd8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
