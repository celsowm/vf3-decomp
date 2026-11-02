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
int vf3_away_batch12_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c080b3cu: goto P_0c080b3c;
case 0x0c080b3eu: goto P_0c080b3e;
case 0x0c080b40u: goto P_0c080b40;
case 0x0c080b42u: goto P_0c080b42;
case 0x0c080b44u: goto P_0c080b44;
case 0x0c080b46u: goto P_0c080b46;
case 0x0c080b48u: goto P_0c080b48;
case 0x0c080b4au: goto P_0c080b4a;
case 0x0c080b4cu: goto P_0c080b4c;
case 0x0c080b4eu: goto P_0c080b4e;
case 0x0c080b50u: goto P_0c080b50;
case 0x0c080b52u: goto P_0c080b52;
case 0x0c080b54u: goto P_0c080b54;
case 0x0c080b56u: goto P_0c080b56;
case 0x0c080b58u: goto P_0c080b58;
case 0x0c080b5au: goto P_0c080b5a;
case 0x0c080b5cu: goto P_0c080b5c;
case 0x0c080b5eu: goto P_0c080b5e;
case 0x0c080b60u: goto P_0c080b60;
case 0x0c080b62u: goto P_0c080b62;
case 0x0c080b64u: goto P_0c080b64;
case 0x0c080b66u: goto P_0c080b66;
case 0x0c080b68u: goto P_0c080b68;
case 0x0c080b6au: goto P_0c080b6a;
case 0x0c080b6cu: goto P_0c080b6c;
case 0x0c080b6eu: goto P_0c080b6e;
case 0x0c080b70u: goto P_0c080b70;
case 0x0c080b72u: goto P_0c080b72;
case 0x0c080b74u: goto P_0c080b74;
case 0x0c080b76u: goto P_0c080b76;
case 0x0c080b78u: goto P_0c080b78;
case 0x0c080b7au: goto P_0c080b7a;
case 0x0c080b7cu: goto P_0c080b7c;
case 0x0c080b7eu: goto P_0c080b7e;
case 0x0c080b80u: goto P_0c080b80;
case 0x0c080b82u: goto P_0c080b82;
case 0x0c080b84u: goto P_0c080b84;
case 0x0c080b86u: goto P_0c080b86;
case 0x0c080b88u: goto P_0c080b88;
case 0x0c080b8au: goto P_0c080b8a;
case 0x0c080b8cu: goto P_0c080b8c;
case 0x0c080b8eu: goto P_0c080b8e;
case 0x0c080b90u: goto P_0c080b90;
case 0x0c080b92u: goto P_0c080b92;
case 0x0c080b94u: goto P_0c080b94;
case 0x0c080b96u: goto P_0c080b96;
case 0x0c080b98u: goto P_0c080b98;
case 0x0c080b9au: goto P_0c080b9a;
case 0x0c080b9cu: goto P_0c080b9c;
case 0x0c080b9eu: goto P_0c080b9e;
case 0x0c080ba0u: goto P_0c080ba0;
case 0x0c080ba2u: goto P_0c080ba2;
case 0x0c080ba4u: goto P_0c080ba4;
case 0x0c080ba6u: goto P_0c080ba6;
case 0x0c080ba8u: goto P_0c080ba8;
case 0x0c080baau: goto P_0c080baa;
case 0x0c080bacu: goto P_0c080bac;
case 0x0c080baeu: goto P_0c080bae;
case 0x0c080bb0u: goto P_0c080bb0;
case 0x0c080bb2u: goto P_0c080bb2;
case 0x0c080bb4u: goto P_0c080bb4;
case 0x0c080bb6u: goto P_0c080bb6;
case 0x0c080bb8u: goto P_0c080bb8;
case 0x0c080bbau: goto P_0c080bba;
case 0x0c080bbcu: goto P_0c080bbc;
case 0x0c080bbeu: goto P_0c080bbe;
case 0x0c080bc0u: goto P_0c080bc0;
case 0x0c080bc2u: goto P_0c080bc2;
case 0x0c080bc4u: goto P_0c080bc4;
case 0x0c080bc6u: goto P_0c080bc6;
case 0x0c080bc8u: goto P_0c080bc8;
case 0x0c080bcau: goto P_0c080bca;
case 0x0c080bccu: goto P_0c080bcc;
case 0x0c080bceu: goto P_0c080bce;
case 0x0c080bd0u: goto P_0c080bd0;
case 0x0c080bd2u: goto P_0c080bd2;
case 0x0c080bd4u: goto P_0c080bd4;
case 0x0c080bd6u: goto P_0c080bd6;
case 0x0c080bd8u: goto P_0c080bd8;
case 0x0c080bdau: goto P_0c080bda;
case 0x0c080bdcu: goto P_0c080bdc;
case 0x0c080bdeu: goto P_0c080bde;
case 0x0c080be0u: goto P_0c080be0;
case 0x0c080be2u: goto P_0c080be2;
case 0x0c080be4u: goto P_0c080be4;
case 0x0c080be6u: goto P_0c080be6;
case 0x0c080be8u: goto P_0c080be8;
case 0x0c080beau: goto P_0c080bea;
case 0x0c080becu: goto P_0c080bec;
case 0x0c080beeu: goto P_0c080bee;
case 0x0c080bf0u: goto P_0c080bf0;
case 0x0c080bf2u: goto P_0c080bf2;
case 0x0c080bf4u: goto P_0c080bf4;
case 0x0c080bf6u: goto P_0c080bf6;
case 0x0c080bf8u: goto P_0c080bf8;
case 0x0c080bfau: goto P_0c080bfa;
case 0x0c080bfcu: goto P_0c080bfc;
case 0x0c080bfeu: goto P_0c080bfe;
case 0x0c080c00u: goto P_0c080c00;
case 0x0c080c02u: goto P_0c080c02;
case 0x0c080c04u: goto P_0c080c04;
case 0x0c080c06u: goto P_0c080c06;
case 0x0c080c08u: goto P_0c080c08;
case 0x0c080c0au: goto P_0c080c0a;
case 0x0c080c0cu: goto P_0c080c0c;
case 0x0c080c0eu: goto P_0c080c0e;
case 0x0c080c10u: goto P_0c080c10;
case 0x0c080c12u: goto P_0c080c12;
case 0x0c080c14u: goto P_0c080c14;
case 0x0c080c16u: goto P_0c080c16;
case 0x0c080c18u: goto P_0c080c18;
case 0x0c080c1au: goto P_0c080c1a;
case 0x0c080c1cu: goto P_0c080c1c;
case 0x0c080c1eu: goto P_0c080c1e;
case 0x0c080c20u: goto P_0c080c20;
case 0x0c080c22u: goto P_0c080c22;
case 0x0c080c24u: goto P_0c080c24;
case 0x0c080c26u: goto P_0c080c26;
case 0x0c080c28u: goto P_0c080c28;
case 0x0c080c2au: goto P_0c080c2a;
case 0x0c080c2cu: goto P_0c080c2c;
case 0x0c080c2eu: goto P_0c080c2e;
case 0x0c080c30u: goto P_0c080c30;
case 0x0c080c32u: goto P_0c080c32;
case 0x0c080c34u: goto P_0c080c34;
case 0x0c080c36u: goto P_0c080c36;
case 0x0c080c38u: goto P_0c080c38;
case 0x0c080c3au: goto P_0c080c3a;
case 0x0c080c3cu: goto P_0c080c3c;
case 0x0c080c3eu: goto P_0c080c3e;
case 0x0c080c40u: goto P_0c080c40;
case 0x0c080c42u: goto P_0c080c42;
case 0x0c080c44u: goto P_0c080c44;
case 0x0c080c46u: goto P_0c080c46;
case 0x0c080c48u: goto P_0c080c48;
case 0x0c080c4au: goto P_0c080c4a;
case 0x0c080d14u: goto P_0c080d14;
case 0x0c080d16u: goto P_0c080d16;
case 0x0c080d18u: goto P_0c080d18;
case 0x0c080d1au: goto P_0c080d1a;
case 0x0c080d1cu: goto P_0c080d1c;
case 0x0c080d1eu: goto P_0c080d1e;
case 0x0c080d20u: goto P_0c080d20;
case 0x0c080d22u: goto P_0c080d22;
case 0x0c080d24u: goto P_0c080d24;
case 0x0c080d26u: goto P_0c080d26;
case 0x0c080d28u: goto P_0c080d28;
case 0x0c080d2au: goto P_0c080d2a;
case 0x0c080d2cu: goto P_0c080d2c;
case 0x0c080d2eu: goto P_0c080d2e;
case 0x0c080d30u: goto P_0c080d30;
case 0x0c080d32u: goto P_0c080d32;
case 0x0c080d34u: goto P_0c080d34;
case 0x0c080d36u: goto P_0c080d36;
case 0x0c080d38u: goto P_0c080d38;
case 0x0c080d3au: goto P_0c080d3a;
case 0x0c080d3cu: goto P_0c080d3c;
case 0x0c080d3eu: goto P_0c080d3e;
case 0x0c080d40u: goto P_0c080d40;
case 0x0c080d42u: goto P_0c080d42;
case 0x0c080d44u: goto P_0c080d44;
case 0x0c080d46u: goto P_0c080d46;
case 0x0c080d48u: goto P_0c080d48;
case 0x0c080d4au: goto P_0c080d4a;
case 0x0c080d4cu: goto P_0c080d4c;
case 0x0c080d4eu: goto P_0c080d4e;
case 0x0c080d50u: goto P_0c080d50;
case 0x0c080d52u: goto P_0c080d52;
case 0x0c080d54u: goto P_0c080d54;
case 0x0c080d56u: goto P_0c080d56;
case 0x0c080d58u: goto P_0c080d58;
case 0x0c080d5au: goto P_0c080d5a;
case 0x0c080d5cu: goto P_0c080d5c;
case 0x0c080d5eu: goto P_0c080d5e;
case 0x0c080d60u: goto P_0c080d60;
case 0x0c080d62u: goto P_0c080d62;
case 0x0c080d64u: goto P_0c080d64;
case 0x0c080d66u: goto P_0c080d66;
case 0x0c080d68u: goto P_0c080d68;
case 0x0c080d6au: goto P_0c080d6a;
case 0x0c080d6cu: goto P_0c080d6c;
case 0x0c080d6eu: goto P_0c080d6e;
case 0x0c080d70u: goto P_0c080d70;
case 0x0c080d72u: goto P_0c080d72;
case 0x0c080d74u: goto P_0c080d74;
case 0x0c080d76u: goto P_0c080d76;
case 0x0c080d78u: goto P_0c080d78;
case 0x0c080d7au: goto P_0c080d7a;
case 0x0c080d7cu: goto P_0c080d7c;
case 0x0c080d7eu: goto P_0c080d7e;
case 0x0c080d80u: goto P_0c080d80;
case 0x0c080d82u: goto P_0c080d82;
case 0x0c080d84u: goto P_0c080d84;
case 0x0c080d86u: goto P_0c080d86;
case 0x0c080d88u: goto P_0c080d88;
case 0x0c080d8au: goto P_0c080d8a;
case 0x0c080d8cu: goto P_0c080d8c;
case 0x0c080d8eu: goto P_0c080d8e;
case 0x0c080d90u: goto P_0c080d90;
case 0x0c080d92u: goto P_0c080d92;
case 0x0c080d94u: goto P_0c080d94;
case 0x0c080d96u: goto P_0c080d96;
case 0x0c080d98u: goto P_0c080d98;
case 0x0c080d9au: goto P_0c080d9a;
case 0x0c080d9cu: goto P_0c080d9c;
case 0x0c080d9eu: goto P_0c080d9e;
case 0x0c080da0u: goto P_0c080da0;
case 0x0c080da2u: goto P_0c080da2;
case 0x0c080da4u: goto P_0c080da4;
case 0x0c080da6u: goto P_0c080da6;
case 0x0c080da8u: goto P_0c080da8;
case 0x0c080daau: goto P_0c080daa;
case 0x0c080dacu: goto P_0c080dac;
case 0x0c080daeu: goto P_0c080dae;
case 0x0c080db0u: goto P_0c080db0;
case 0x0c080db2u: goto P_0c080db2;
case 0x0c080db4u: goto P_0c080db4;
case 0x0c080db6u: goto P_0c080db6;
case 0x0c080db8u: goto P_0c080db8;
case 0x0c080dbau: goto P_0c080dba;
case 0x0c080dbcu: goto P_0c080dbc;
case 0x0c080dbeu: goto P_0c080dbe;
case 0x0c080dc0u: goto P_0c080dc0;
case 0x0c080dc2u: goto P_0c080dc2;
case 0x0c080dc4u: goto P_0c080dc4;
case 0x0c080dc6u: goto P_0c080dc6;
case 0x0c080dc8u: goto P_0c080dc8;
case 0x0c080dcau: goto P_0c080dca;
case 0x0c080dccu: goto P_0c080dcc;
case 0x0c080dceu: goto P_0c080dce;
case 0x0c080dd0u: goto P_0c080dd0;
case 0x0c080dd2u: goto P_0c080dd2;
case 0x0c080dd4u: goto P_0c080dd4;
case 0x0c080dd6u: goto P_0c080dd6;
case 0x0c080dd8u: goto P_0c080dd8;
case 0x0c080ddau: goto P_0c080dda;
case 0x0c080ddcu: goto P_0c080ddc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c080b3c: /* original 2fe6, guest PC 0x0c080b3c */
if(!s->budget--) { s->failed_pc=0x0c080b3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b3e;
P_0c080b3e: /* original e2fa, guest PC 0x0c080b3e */
if(!s->budget--) { s->failed_pc=0x0c080b3eu; return 0; }
r[2]=0xfffffffau;
goto P_0c080b40;
P_0c080b40: /* original 2fd6, guest PC 0x0c080b40 */
if(!s->budget--) { s->failed_pc=0x0c080b40u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b42;
P_0c080b42: /* original e164, guest PC 0x0c080b42 */
if(!s->budget--) { s->failed_pc=0x0c080b42u; return 0; }
r[1]=0x00000064u;
goto P_0c080b44;
P_0c080b44: /* original 2fc6, guest PC 0x0c080b44 */
if(!s->budget--) { s->failed_pc=0x0c080b44u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080b46;
P_0c080b46: /* original e60a, guest PC 0x0c080b46 */
if(!s->budget--) { s->failed_pc=0x0c080b46u; return 0; }
r[6]=0x0000000au;
goto P_0c080b48;
P_0c080b48: /* original d346, guest PC 0x0c080b48 */
if(!s->budget--) { s->failed_pc=0x0c080b48u; return 0; }
r[3]=read(ram,0x0c080c64u,4);
goto P_0c080b4a;
P_0c080b4a: /* original 4f22, guest PC 0x0c080b4a */
if(!s->budget--) { s->failed_pc=0x0c080b4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080b4c;
P_0c080b4c: /* original 6432, guest PC 0x0c080b4c */
if(!s->budget--) { s->failed_pc=0x0c080b4cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080b4e;
P_0c080b4e: /* original e3fa, guest PC 0x0c080b4e */
if(!s->budget--) { s->failed_pc=0x0c080b4eu; return 0; }
r[3]=0xfffffffau;
goto P_0c080b50;
P_0c080b50: /* original de43, guest PC 0x0c080b50 */
if(!s->budget--) { s->failed_pc=0x0c080b50u; return 0; }
r[14]=read(ram,0x0c080c60u,4);
goto P_0c080b52;
P_0c080b52: /* original 6543, guest PC 0x0c080b52 */
if(!s->budget--) { s->failed_pc=0x0c080b52u; return 0; }
r[5]=r[4];
goto P_0c080b54;
P_0c080b54: /* original 452c, guest PC 0x0c080b54 */
if(!s->budget--) { s->failed_pc=0x0c080b54u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c080b56;
P_0c080b56: /* original e23f, guest PC 0x0c080b56 */
if(!s->budget--) { s->failed_pc=0x0c080b56u; return 0; }
r[2]=0x0000003fu;
goto P_0c080b58;
P_0c080b58: /* original 2429, guest PC 0x0c080b58 */
if(!s->budget--) { s->failed_pc=0x0c080b58u; return 0; }
r[4]&=r[2];
goto P_0c080b5a;
P_0c080b5a: /* original 4f12, guest PC 0x0c080b5a */
if(!s->budget--) { s->failed_pc=0x0c080b5au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c080b5c;
P_0c080b5c: /* original 0417, guest PC 0x0c080b5c */
if(!s->budget--) { s->failed_pc=0x0c080b5cu; return 0; }
r[19]=r[4]*r[1];
goto P_0c080b5e;
P_0c080b5e: /* original 6153, guest PC 0x0c080b5e */
if(!s->budget--) { s->failed_pc=0x0c080b5eu; return 0; }
r[1]=r[5];
goto P_0c080b60;
P_0c080b60: /* original 7fec, guest PC 0x0c080b60 */
if(!s->budget--) { s->failed_pc=0x0c080b60u; return 0; }
r[15]+=0xffffffecu;
goto P_0c080b62;
P_0c080b62: /* original 1f52, guest PC 0x0c080b62 */
if(!s->budget--) { s->failed_pc=0x0c080b62u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c080b64;
P_0c080b64: /* original 041a, guest PC 0x0c080b64 */
if(!s->budget--) { s->failed_pc=0x0c080b64u; return 0; }
r[4]=r[19];
goto P_0c080b66;
P_0c080b66: /* original 443c, guest PC 0x0c080b66 */
if(!s->budget--) { s->failed_pc=0x0c080b66u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c080b68;
P_0c080b68: /* original d33f, guest PC 0x0c080b68 */
if(!s->budget--) { s->failed_pc=0x0c080b68u; return 0; }
r[3]=read(ram,0x0c080c68u,4);
goto P_0c080b6a;
P_0c080b6a: /* original 430b, guest PC 0x0c080b6a */
if(!s->budget--) { s->failed_pc=0x0c080b6au; return 0; }
target=r[3];
r[16]=code_base|0x0c080b6eu;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080b6eu) { target=s->pc; goto dispatch; }
goto P_0c080b6e;
P_0c080b6c: /* original 6063, guest PC 0x0c080b6c */
if(!s->budget--) { s->failed_pc=0x0c080b6cu; return 0; }
r[0]=r[6];
goto P_0c080b6e;
P_0c080b6e: /* original d33e, guest PC 0x0c080b6e */
if(!s->budget--) { s->failed_pc=0x0c080b6eu; return 0; }
r[3]=read(ram,0x0c080c68u,4);
goto P_0c080b70;
P_0c080b70: /* original 6143, guest PC 0x0c080b70 */
if(!s->budget--) { s->failed_pc=0x0c080b70u; return 0; }
r[1]=r[4];
goto P_0c080b72;
P_0c080b72: /* original 6c03, guest PC 0x0c080b72 */
if(!s->budget--) { s->failed_pc=0x0c080b72u; return 0; }
r[12]=r[0];
goto P_0c080b74;
P_0c080b74: /* original 430b, guest PC 0x0c080b74 */
if(!s->budget--) { s->failed_pc=0x0c080b74u; return 0; }
target=r[3];
r[16]=code_base|0x0c080b78u;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080b78u) { target=s->pc; goto dispatch; }
goto P_0c080b78;
P_0c080b76: /* original 6063, guest PC 0x0c080b76 */
if(!s->budget--) { s->failed_pc=0x0c080b76u; return 0; }
r[0]=r[6];
goto P_0c080b78;
P_0c080b78: /* original 61c3, guest PC 0x0c080b78 */
if(!s->budget--) { s->failed_pc=0x0c080b78u; return 0; }
r[1]=r[12];
goto P_0c080b7a;
P_0c080b7a: /* original 4108, guest PC 0x0c080b7a */
if(!s->budget--) { s->failed_pc=0x0c080b7au; return 0; }
r[1]<<=2;
goto P_0c080b7c;
P_0c080b7c: /* original 63c3, guest PC 0x0c080b7c */
if(!s->budget--) { s->failed_pc=0x0c080b7cu; return 0; }
r[3]=r[12];
goto P_0c080b7e;
P_0c080b7e: /* original 6603, guest PC 0x0c080b7e */
if(!s->budget--) { s->failed_pc=0x0c080b7eu; return 0; }
r[6]=r[0];
goto P_0c080b80;
P_0c080b80: /* original 6763, guest PC 0x0c080b80 */
if(!s->budget--) { s->failed_pc=0x0c080b80u; return 0; }
r[7]=r[6];
goto P_0c080b82;
P_0c080b82: /* original 313c, guest PC 0x0c080b82 */
if(!s->budget--) { s->failed_pc=0x0c080b82u; return 0; }
r[1]+=r[3];
goto P_0c080b84;
P_0c080b84: /* original 6363, guest PC 0x0c080b84 */
if(!s->budget--) { s->failed_pc=0x0c080b84u; return 0; }
r[3]=r[6];
goto P_0c080b86;
P_0c080b86: /* original 4708, guest PC 0x0c080b86 */
if(!s->budget--) { s->failed_pc=0x0c080b86u; return 0; }
r[7]<<=2;
goto P_0c080b88;
P_0c080b88: /* original 373c, guest PC 0x0c080b88 */
if(!s->budget--) { s->failed_pc=0x0c080b88u; return 0; }
r[7]+=r[3];
goto P_0c080b8a;
P_0c080b8a: /* original 4100, guest PC 0x0c080b8a */
if(!s->budget--) { s->failed_pc=0x0c080b8au; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c080b8c;
P_0c080b8c: /* original 4700, guest PC 0x0c080b8c */
if(!s->budget--) { s->failed_pc=0x0c080b8cu; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c080b8e;
P_0c080b8e: /* original 2f12, guest PC 0x0c080b8e */
if(!s->budget--) { s->failed_pc=0x0c080b8eu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c080b90;
P_0c080b90: /* original 3478, guest PC 0x0c080b90 */
if(!s->budget--) { s->failed_pc=0x0c080b90u; return 0; }
r[4]-=r[7];
goto P_0c080b92;
P_0c080b92: /* original 3518, guest PC 0x0c080b92 */
if(!s->budget--) { s->failed_pc=0x0c080b92u; return 0; }
r[5]-=r[1];
goto P_0c080b94;
P_0c080b94: /* original 1f51, guest PC 0x0c080b94 */
if(!s->budget--) { s->failed_pc=0x0c080b94u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c080b96;
P_0c080b96: /* original 1f64, guest PC 0x0c080b96 */
if(!s->budget--) { s->failed_pc=0x0c080b96u; return 0; }
write(ram,r[15]+16,r[6],4);
goto P_0c080b98;
P_0c080b98: /* original 1f43, guest PC 0x0c080b98 */
if(!s->budget--) { s->failed_pc=0x0c080b98u; return 0; }
write(ram,r[15]+12,r[4],4);
goto P_0c080b9a;
P_0c080b9a: /* original d334, guest PC 0x0c080b9a */
if(!s->budget--) { s->failed_pc=0x0c080b9au; return 0; }
r[3]=read(ram,0x0c080c6cu,4);
goto P_0c080b9c;
P_0c080b9c: /* original 9d56, guest PC 0x0c080b9c */
if(!s->budget--) { s->failed_pc=0x0c080b9cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c4cu,2);
goto P_0c080b9e;
P_0c080b9e: /* original 2f32, guest PC 0x0c080b9e */
if(!s->budget--) { s->failed_pc=0x0c080b9eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080ba0;
P_0c080ba0: /* original 6433, guest PC 0x0c080ba0 */
if(!s->budget--) { s->failed_pc=0x0c080ba0u; return 0; }
r[4]=r[3];
goto P_0c080ba2;
P_0c080ba2: /* original d333, guest PC 0x0c080ba2 */
if(!s->budget--) { s->failed_pc=0x0c080ba2u; return 0; }
r[3]=read(ram,0x0c080c70u,4);
goto P_0c080ba4;
P_0c080ba4: /* original 430b, guest PC 0x0c080ba4 */
if(!s->budget--) { s->failed_pc=0x0c080ba4u; return 0; }
target=r[3];
r[16]=code_base|0x0c080ba8u;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080ba8u) { target=s->pc; goto dispatch; }
goto P_0c080ba8;
P_0c080ba6: /* original 740a, guest PC 0x0c080ba6 */
if(!s->budget--) { s->failed_pc=0x0c080ba6u; return 0; }
r[4]+=0x0000000au;
goto P_0c080ba8;
P_0c080ba8: /* original 600d, guest PC 0x0c080ba8 */
if(!s->budget--) { s->failed_pc=0x0c080ba8u; return 0; }
r[0]=r[0]&65535u;
goto P_0c080baa;
P_0c080baa: /* original 8803, guest PC 0x0c080baa */
if(!s->budget--) { s->failed_pc=0x0c080baau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c080bac;
P_0c080bac: /* original 8f01, guest PC 0x0c080bac */
if(!s->budget--) { s->failed_pc=0x0c080bacu; return 0; }
cond=r[17]&1u;
r[3]=0x00000000u;
if(!cond) { goto P_0c080bb2; }
goto P_0c080bb0;
P_0c080bae: /* original e300, guest PC 0x0c080bae */
if(!s->budget--) { s->failed_pc=0x0c080baeu; return 0; }
r[3]=0x00000000u;
goto P_0c080bb0;
P_0c080bb0: /* original 9d4d, guest PC 0x0c080bb0 */
if(!s->budget--) { s->failed_pc=0x0c080bb0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c4eu,2);
goto P_0c080bb2;
P_0c080bb2: /* original 66e3, guest PC 0x0c080bb2 */
if(!s->budget--) { s->failed_pc=0x0c080bb2u; return 0; }
r[6]=r[14];
goto P_0c080bb4;
P_0c080bb4: /* original 2f36, guest PC 0x0c080bb4 */
if(!s->budget--) { s->failed_pc=0x0c080bb4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080bb6;
P_0c080bb6: /* original 944b, guest PC 0x0c080bb6 */
if(!s->budget--) { s->failed_pc=0x0c080bb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c50u,2);
goto P_0c080bb8;
P_0c080bb8: /* original 6733, guest PC 0x0c080bb8 */
if(!s->budget--) { s->failed_pc=0x0c080bb8u; return 0; }
r[7]=r[3];
goto P_0c080bba;
P_0c080bba: /* original d22e, guest PC 0x0c080bba */
if(!s->budget--) { s->failed_pc=0x0c080bbau; return 0; }
r[2]=read(ram,0x0c080c74u,4);
goto P_0c080bbc;
P_0c080bbc: /* original 420b, guest PC 0x0c080bbc */
if(!s->budget--) { s->failed_pc=0x0c080bbcu; return 0; }
target=r[2];
r[16]=code_base|0x0c080bc0u;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080bc0u) { target=s->pc; goto dispatch; }
goto P_0c080bc0;
P_0c080bbe: /* original 65d3, guest PC 0x0c080bbe */
if(!s->budget--) { s->failed_pc=0x0c080bbeu; return 0; }
r[5]=r[13];
goto P_0c080bc0;
P_0c080bc0: /* original d32a, guest PC 0x0c080bc0 */
if(!s->budget--) { s->failed_pc=0x0c080bc0u; return 0; }
r[3]=read(ram,0x0c080c6cu,4);
goto P_0c080bc2;
P_0c080bc2: /* original 7f04, guest PC 0x0c080bc2 */
if(!s->budget--) { s->failed_pc=0x0c080bc2u; return 0; }
r[15]+=0x00000004u;
goto P_0c080bc4;
P_0c080bc4: /* original 6433, guest PC 0x0c080bc4 */
if(!s->budget--) { s->failed_pc=0x0c080bc4u; return 0; }
r[4]=r[3];
goto P_0c080bc6;
P_0c080bc6: /* original 2f32, guest PC 0x0c080bc6 */
if(!s->budget--) { s->failed_pc=0x0c080bc6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080bc8;
P_0c080bc8: /* original d329, guest PC 0x0c080bc8 */
if(!s->budget--) { s->failed_pc=0x0c080bc8u; return 0; }
r[3]=read(ram,0x0c080c70u,4);
goto P_0c080bca;
P_0c080bca: /* original 430b, guest PC 0x0c080bca */
if(!s->budget--) { s->failed_pc=0x0c080bcau; return 0; }
target=r[3];
r[16]=code_base|0x0c080bceu;
r[4]+=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080bceu) { target=s->pc; goto dispatch; }
goto P_0c080bce;
P_0c080bcc: /* original 740a, guest PC 0x0c080bcc */
if(!s->budget--) { s->failed_pc=0x0c080bccu; return 0; }
r[4]+=0x0000000au;
goto P_0c080bce;
P_0c080bce: /* original e203, guest PC 0x0c080bce */
if(!s->budget--) { s->failed_pc=0x0c080bceu; return 0; }
r[2]=0x00000003u;
goto P_0c080bd0;
P_0c080bd0: /* original 600d, guest PC 0x0c080bd0 */
if(!s->budget--) { s->failed_pc=0x0c080bd0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c080bd2;
P_0c080bd2: /* original 3023, guest PC 0x0c080bd2 */
if(!s->budget--) { s->failed_pc=0x0c080bd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[2])!=0);
goto P_0c080bd4;
P_0c080bd4: /* original 8933, guest PC 0x0c080bd4 */
if(!s->budget--) { s->failed_pc=0x0c080bd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c080c3e; }
goto P_0c080bd6;
P_0c080bd6: /* original d428, guest PC 0x0c080bd6 */
if(!s->budget--) { s->failed_pc=0x0c080bd6u; return 0; }
r[4]=read(ram,0x0c080c78u,4);
goto P_0c080bd8;
P_0c080bd8: /* original e208, guest PC 0x0c080bd8 */
if(!s->budget--) { s->failed_pc=0x0c080bd8u; return 0; }
r[2]=0x00000008u;
goto P_0c080bda;
P_0c080bda: /* original d328, guest PC 0x0c080bda */
if(!s->budget--) { s->failed_pc=0x0c080bdau; return 0; }
r[3]=read(ram,0x0c080c7cu,4);
goto P_0c080bdc;
P_0c080bdc: /* original 8448, guest PC 0x0c080bdc */
if(!s->budget--) { s->failed_pc=0x0c080bdcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c080bde;
P_0c080bde: /* original dd28, guest PC 0x0c080bde */
if(!s->budget--) { s->failed_pc=0x0c080bdeu; return 0; }
r[13]=read(ram,0x0c080c80u,4);
goto P_0c080be0;
P_0c080be0: /* original 650c, guest PC 0x0c080be0 */
if(!s->budget--) { s->failed_pc=0x0c080be0u; return 0; }
r[5]=r[0]&255u;
goto P_0c080be2;
P_0c080be2: /* original 8449, guest PC 0x0c080be2 */
if(!s->budget--) { s->failed_pc=0x0c080be2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+9,1);
goto P_0c080be4;
P_0c080be4: /* original 6432, guest PC 0x0c080be4 */
if(!s->budget--) { s->failed_pc=0x0c080be4u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080be6;
P_0c080be6: /* original 2429, guest PC 0x0c080be6 */
if(!s->budget--) { s->failed_pc=0x0c080be6u; return 0; }
r[4]&=r[2];
goto P_0c080be8;
P_0c080be8: /* original 2448, guest PC 0x0c080be8 */
if(!s->budget--) { s->failed_pc=0x0c080be8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c080bea;
P_0c080bea: /* original 8f14, guest PC 0x0c080bea */
if(!s->budget--) { s->failed_pc=0x0c080beau; return 0; }
cond=r[17]&1u;
r[6]=r[0]&255u;
if(!cond) { goto P_0c080c16; }
goto P_0c080bee;
P_0c080bec: /* original 660c, guest PC 0x0c080bec */
if(!s->budget--) { s->failed_pc=0x0c080becu; return 0; }
r[6]=r[0]&255u;
goto P_0c080bee;
P_0c080bee: /* original 51f2, guest PC 0x0c080bee */
if(!s->budget--) { s->failed_pc=0x0c080beeu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c080bf0;
P_0c080bf0: /* original e006, guest PC 0x0c080bf0 */
if(!s->budget--) { s->failed_pc=0x0c080bf0u; return 0; }
r[0]=0x00000006u;
goto P_0c080bf2;
P_0c080bf2: /* original 3103, guest PC 0x0c080bf2 */
if(!s->budget--) { s->failed_pc=0x0c080bf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[0])!=0);
goto P_0c080bf4;
P_0c080bf4: /* original 890f, guest PC 0x0c080bf4 */
if(!s->budget--) { s->failed_pc=0x0c080bf4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c080c16; }
goto P_0c080bf6;
P_0c080bf6: /* original 6053, guest PC 0x0c080bf6 */
if(!s->budget--) { s->failed_pc=0x0c080bf6u; return 0; }
r[0]=r[5];
goto P_0c080bf8;
P_0c080bf8: /* original 8807, guest PC 0x0c080bf8 */
if(!s->budget--) { s->failed_pc=0x0c080bf8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c080bfa;
P_0c080bfa: /* original 8b0c, guest PC 0x0c080bfa */
if(!s->budget--) { s->failed_pc=0x0c080bfau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080c16; }
goto P_0c080bfc;
P_0c080bfc: /* original 6063, guest PC 0x0c080bfc */
if(!s->budget--) { s->failed_pc=0x0c080bfcu; return 0; }
r[0]=r[6];
goto P_0c080bfe;
P_0c080bfe: /* original 8809, guest PC 0x0c080bfe */
if(!s->budget--) { s->failed_pc=0x0c080bfeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c080c00;
P_0c080c00: /* original 8b09, guest PC 0x0c080c00 */
if(!s->budget--) { s->failed_pc=0x0c080c00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c080c16; }
goto P_0c080c02;
P_0c080c02: /* original e220, guest PC 0x0c080c02 */
if(!s->budget--) { s->failed_pc=0x0c080c02u; return 0; }
r[2]=0x00000020u;
goto P_0c080c04;
P_0c080c04: /* original e604, guest PC 0x0c080c04 */
if(!s->budget--) { s->failed_pc=0x0c080c04u; return 0; }
r[6]=0x00000004u;
goto P_0c080c06;
P_0c080c06: /* original 2f26, guest PC 0x0c080c06 */
if(!s->budget--) { s->failed_pc=0x0c080c06u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080c08;
P_0c080c08: /* original 9523, guest PC 0x0c080c08 */
if(!s->budget--) { s->failed_pc=0x0c080c08u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c52u,2);
goto P_0c080c0a;
P_0c080c0a: /* original e703, guest PC 0x0c080c0a */
if(!s->budget--) { s->failed_pc=0x0c080c0au; return 0; }
r[7]=0x00000003u;
goto P_0c080c0c;
P_0c080c0c: /* original d31d, guest PC 0x0c080c0c */
if(!s->budget--) { s->failed_pc=0x0c080c0cu; return 0; }
r[3]=read(ram,0x0c080c84u,4);
goto P_0c080c0e;
P_0c080c0e: /* original 430b, guest PC 0x0c080c0e */
if(!s->budget--) { s->failed_pc=0x0c080c0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c080c12u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080c12u) { target=s->pc; goto dispatch; }
goto P_0c080c12;
P_0c080c10: /* original 64e3, guest PC 0x0c080c10 */
if(!s->budget--) { s->failed_pc=0x0c080c10u; return 0; }
r[4]=r[14];
goto P_0c080c12;
P_0c080c12: /* original a00a, guest PC 0x0c080c12 */
if(!s->budget--) { s->failed_pc=0x0c080c12u; return 0; }
r[15]+=0x00000004u;
goto P_0c080c2a;
P_0c080c14: /* original 7f04, guest PC 0x0c080c14 */
if(!s->budget--) { s->failed_pc=0x0c080c14u; return 0; }
r[15]+=0x00000004u;
goto P_0c080c16;
P_0c080c16: /* original 951c, guest PC 0x0c080c16 */
if(!s->budget--) { s->failed_pc=0x0c080c16u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c52u,2);
goto P_0c080c18;
P_0c080c18: /* original 66c3, guest PC 0x0c080c18 */
if(!s->budget--) { s->failed_pc=0x0c080c18u; return 0; }
r[6]=r[12];
goto P_0c080c1a;
P_0c080c1a: /* original 971b, guest PC 0x0c080c1a */
if(!s->budget--) { s->failed_pc=0x0c080c1au; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c54u,2);
goto P_0c080c1c;
P_0c080c1c: /* original 4d0b, guest PC 0x0c080c1c */
if(!s->budget--) { s->failed_pc=0x0c080c1cu; return 0; }
target=r[13];
r[16]=code_base|0x0c080c20u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080c20u) { target=s->pc; goto dispatch; }
goto P_0c080c20;
P_0c080c1e: /* original 64e3, guest PC 0x0c080c1e */
if(!s->budget--) { s->failed_pc=0x0c080c1eu; return 0; }
r[4]=r[14];
goto P_0c080c20;
P_0c080c20: /* original 9519, guest PC 0x0c080c20 */
if(!s->budget--) { s->failed_pc=0x0c080c20u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c56u,2);
goto P_0c080c22;
P_0c080c22: /* original 56f1, guest PC 0x0c080c22 */
if(!s->budget--) { s->failed_pc=0x0c080c22u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c080c24;
P_0c080c24: /* original 9716, guest PC 0x0c080c24 */
if(!s->budget--) { s->failed_pc=0x0c080c24u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c54u,2);
goto P_0c080c26;
P_0c080c26: /* original 4d0b, guest PC 0x0c080c26 */
if(!s->budget--) { s->failed_pc=0x0c080c26u; return 0; }
target=r[13];
r[16]=code_base|0x0c080c2au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080c2au) { target=s->pc; goto dispatch; }
goto P_0c080c2a;
P_0c080c28: /* original 64e3, guest PC 0x0c080c28 */
if(!s->budget--) { s->failed_pc=0x0c080c28u; return 0; }
r[4]=r[14];
goto P_0c080c2a;
P_0c080c2a: /* original 9516, guest PC 0x0c080c2a */
if(!s->budget--) { s->failed_pc=0x0c080c2au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c5au,2);
goto P_0c080c2c;
P_0c080c2c: /* original 56f4, guest PC 0x0c080c2c */
if(!s->budget--) { s->failed_pc=0x0c080c2cu; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c080c2e;
P_0c080c2e: /* original 9713, guest PC 0x0c080c2e */
if(!s->budget--) { s->failed_pc=0x0c080c2eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c58u,2);
goto P_0c080c30;
P_0c080c30: /* original 4d0b, guest PC 0x0c080c30 */
if(!s->budget--) { s->failed_pc=0x0c080c30u; return 0; }
target=r[13];
r[16]=code_base|0x0c080c34u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080c34u) { target=s->pc; goto dispatch; }
goto P_0c080c34;
P_0c080c32: /* original 64e3, guest PC 0x0c080c32 */
if(!s->budget--) { s->failed_pc=0x0c080c32u; return 0; }
r[4]=r[14];
goto P_0c080c34;
P_0c080c34: /* original 9512, guest PC 0x0c080c34 */
if(!s->budget--) { s->failed_pc=0x0c080c34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c5cu,2);
goto P_0c080c36;
P_0c080c36: /* original 56f3, guest PC 0x0c080c36 */
if(!s->budget--) { s->failed_pc=0x0c080c36u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c080c38;
P_0c080c38: /* original 970e, guest PC 0x0c080c38 */
if(!s->budget--) { s->failed_pc=0x0c080c38u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080c58u,2);
goto P_0c080c3a;
P_0c080c3a: /* original 4d0b, guest PC 0x0c080c3a */
if(!s->budget--) { s->failed_pc=0x0c080c3au; return 0; }
target=r[13];
r[16]=code_base|0x0c080c3eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080c3eu) { target=s->pc; goto dispatch; }
goto P_0c080c3e;
P_0c080c3c: /* original 64e3, guest PC 0x0c080c3c */
if(!s->budget--) { s->failed_pc=0x0c080c3cu; return 0; }
r[4]=r[14];
goto P_0c080c3e;
P_0c080c3e: /* original 7f14, guest PC 0x0c080c3e */
if(!s->budget--) { s->failed_pc=0x0c080c3eu; return 0; }
r[15]+=0x00000014u;
goto P_0c080c40;
P_0c080c40: /* original 4f16, guest PC 0x0c080c40 */
if(!s->budget--) { s->failed_pc=0x0c080c40u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c080c42;
P_0c080c42: /* original 4f26, guest PC 0x0c080c42 */
if(!s->budget--) { s->failed_pc=0x0c080c42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080c44;
P_0c080c44: /* original 6cf6, guest PC 0x0c080c44 */
if(!s->budget--) { s->failed_pc=0x0c080c44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080c46;
P_0c080c46: /* original 6df6, guest PC 0x0c080c46 */
if(!s->budget--) { s->failed_pc=0x0c080c46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080c48;
P_0c080c48: /* original 000b, guest PC 0x0c080c48 */
if(!s->budget--) { s->failed_pc=0x0c080c48u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080c4a: /* original 6ef6, guest PC 0x0c080c4a */
if(!s->budget--) { s->failed_pc=0x0c080c4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c080c4cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080c4cu; return 0; } return 1;
P_0c080d14: /* original 2fe6, guest PC 0x0c080d14 */
if(!s->budget--) { s->failed_pc=0x0c080d14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d16;
P_0c080d16: /* original e01a, guest PC 0x0c080d16 */
if(!s->budget--) { s->failed_pc=0x0c080d16u; return 0; }
r[0]=0x0000001au;
goto P_0c080d18;
P_0c080d18: /* original 2fd6, guest PC 0x0c080d18 */
if(!s->budget--) { s->failed_pc=0x0c080d18u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d1a;
P_0c080d1a: /* original ee00, guest PC 0x0c080d1a */
if(!s->budget--) { s->failed_pc=0x0c080d1au; return 0; }
r[14]=0x00000000u;
goto P_0c080d1c;
P_0c080d1c: /* original 2fc6, guest PC 0x0c080d1c */
if(!s->budget--) { s->failed_pc=0x0c080d1cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d1e;
P_0c080d1e: /* original 2fb6, guest PC 0x0c080d1e */
if(!s->budget--) { s->failed_pc=0x0c080d1eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d20;
P_0c080d20: /* original 2fa6, guest PC 0x0c080d20 */
if(!s->budget--) { s->failed_pc=0x0c080d20u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d22;
P_0c080d22: /* original ea30, guest PC 0x0c080d22 */
if(!s->budget--) { s->failed_pc=0x0c080d22u; return 0; }
r[10]=0x00000030u;
goto P_0c080d24;
P_0c080d24: /* original 2f96, guest PC 0x0c080d24 */
if(!s->budget--) { s->failed_pc=0x0c080d24u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d26;
P_0c080d26: /* original e948, guest PC 0x0c080d26 */
if(!s->budget--) { s->failed_pc=0x0c080d26u; return 0; }
r[9]=0x00000048u;
goto P_0c080d28;
P_0c080d28: /* original 2f86, guest PC 0x0c080d28 */
if(!s->budget--) { s->failed_pc=0x0c080d28u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d2a;
P_0c080d2a: /* original e801, guest PC 0x0c080d2a */
if(!s->budget--) { s->failed_pc=0x0c080d2au; return 0; }
r[8]=0x00000001u;
goto P_0c080d2c;
P_0c080d2c: /* original 4f22, guest PC 0x0c080d2c */
if(!s->budget--) { s->failed_pc=0x0c080d2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c080d2e;
P_0c080d2e: /* original d332, guest PC 0x0c080d2e */
if(!s->budget--) { s->failed_pc=0x0c080d2eu; return 0; }
r[3]=read(ram,0x0c080df8u,4);
goto P_0c080d30;
P_0c080d30: /* original 7fe4, guest PC 0x0c080d30 */
if(!s->budget--) { s->failed_pc=0x0c080d30u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c080d32;
P_0c080d32: /* original 1f32, guest PC 0x0c080d32 */
if(!s->budget--) { s->failed_pc=0x0c080d32u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c080d34;
P_0c080d34: /* original d431, guest PC 0x0c080d34 */
if(!s->budget--) { s->failed_pc=0x0c080d34u; return 0; }
r[4]=read(ram,0x0c080dfcu,4);
goto P_0c080d36;
P_0c080d36: /* original 534f, guest PC 0x0c080d36 */
if(!s->budget--) { s->failed_pc=0x0c080d36u; return 0; }
r[3]=read(ram,r[4]+60,4);
goto P_0c080d38;
P_0c080d38: /* original 1f34, guest PC 0x0c080d38 */
if(!s->budget--) { s->failed_pc=0x0c080d38u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c080d3a;
P_0c080d3a: /* original 024c, guest PC 0x0c080d3a */
if(!s->budget--) { s->failed_pc=0x0c080d3au; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080d3c;
P_0c080d3c: /* original e014, guest PC 0x0c080d3c */
if(!s->budget--) { s->failed_pc=0x0c080d3cu; return 0; }
r[0]=0x00000014u;
goto P_0c080d3e;
P_0c080d3e: /* original 0f24, guest PC 0x0c080d3e */
if(!s->budget--) { s->failed_pc=0x0c080d3eu; return 0; }
write(ram,r[15]+r[0],r[2],1);
goto P_0c080d40;
P_0c080d40: /* original e01b, guest PC 0x0c080d40 */
if(!s->budget--) { s->failed_pc=0x0c080d40u; return 0; }
r[0]=0x0000001bu;
goto P_0c080d42;
P_0c080d42: /* original 034c, guest PC 0x0c080d42 */
if(!s->budget--) { s->failed_pc=0x0c080d42u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c080d44;
P_0c080d44: /* original e018, guest PC 0x0c080d44 */
if(!s->budget--) { s->failed_pc=0x0c080d44u; return 0; }
r[0]=0x00000018u;
goto P_0c080d46;
P_0c080d46: /* original e207, guest PC 0x0c080d46 */
if(!s->budget--) { s->failed_pc=0x0c080d46u; return 0; }
r[2]=0x00000007u;
goto P_0c080d48;
P_0c080d48: /* original 0f34, guest PC 0x0c080d48 */
if(!s->budget--) { s->failed_pc=0x0c080d48u; return 0; }
write(ram,r[15]+r[0],r[3],1);
goto P_0c080d4a;
P_0c080d4a: /* original d329, guest PC 0x0c080d4a */
if(!s->budget--) { s->failed_pc=0x0c080d4au; return 0; }
r[3]=read(ram,0x0c080df0u,4);
goto P_0c080d4c;
P_0c080d4c: /* original 6432, guest PC 0x0c080d4c */
if(!s->budget--) { s->failed_pc=0x0c080d4cu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c080d4e;
P_0c080d4e: /* original 1fe1, guest PC 0x0c080d4e */
if(!s->budget--) { s->failed_pc=0x0c080d4eu; return 0; }
write(ram,r[15]+4,r[14],4);
goto P_0c080d50;
P_0c080d50: /* original 7406, guest PC 0x0c080d50 */
if(!s->budget--) { s->failed_pc=0x0c080d50u; return 0; }
r[4]+=0x00000006u;
goto P_0c080d52;
P_0c080d52: /* original 6b43, guest PC 0x0c080d52 */
if(!s->budget--) { s->failed_pc=0x0c080d52u; return 0; }
r[11]=r[4];
goto P_0c080d54;
P_0c080d54: /* original 51f4, guest PC 0x0c080d54 */
if(!s->budget--) { s->failed_pc=0x0c080d54u; return 0; }
r[1]=read(ram,r[15]+16,4);
goto P_0c080d56;
P_0c080d56: /* original 4b2c, guest PC 0x0c080d56 */
if(!s->budget--) { s->failed_pc=0x0c080d56u; return 0; }
r[11]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[11]>>((-r[2])&31u)):((int32_t)r[11]<0?0xffffffffu:0)):r[11]<<(r[2]&31u);
goto P_0c080d58;
P_0c080d58: /* original ec81, guest PC 0x0c080d58 */
if(!s->budget--) { s->failed_pc=0x0c080d58u; return 0; }
r[12]=0xffffff81u;
goto P_0c080d5a;
P_0c080d5a: /* original 4115, guest PC 0x0c080d5a */
if(!s->budget--) { s->failed_pc=0x0c080d5au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c080d5c;
P_0c080d5c: /* original 8f35, guest PC 0x0c080d5c */
if(!s->budget--) { s->failed_pc=0x0c080d5cu; return 0; }
cond=r[17]&1u;
r[13]=0x0000007eu;
if(!cond) { goto P_0c080dca; }
goto P_0c080d60;
P_0c080d5e: /* original ed7e, guest PC 0x0c080d5e */
if(!s->budget--) { s->failed_pc=0x0c080d5eu; return 0; }
r[13]=0x0000007eu;
goto P_0c080d60;
P_0c080d60: /* original 62b3, guest PC 0x0c080d60 */
if(!s->budget--) { s->failed_pc=0x0c080d60u; return 0; }
r[2]=r[11];
goto P_0c080d62;
P_0c080d62: /* original 63a3, guest PC 0x0c080d62 */
if(!s->budget--) { s->failed_pc=0x0c080d62u; return 0; }
r[3]=r[10];
goto P_0c080d64;
P_0c080d64: /* original 22c9, guest PC 0x0c080d64 */
if(!s->budget--) { s->failed_pc=0x0c080d64u; return 0; }
r[2]&=r[12];
goto P_0c080d66;
P_0c080d66: /* original 23d9, guest PC 0x0c080d66 */
if(!s->budget--) { s->failed_pc=0x0c080d66u; return 0; }
r[3]&=r[13];
goto P_0c080d68;
P_0c080d68: /* original e014, guest PC 0x0c080d68 */
if(!s->budget--) { s->failed_pc=0x0c080d68u; return 0; }
r[0]=0x00000014u;
goto P_0c080d6a;
P_0c080d6a: /* original 232b, guest PC 0x0c080d6a */
if(!s->budget--) { s->failed_pc=0x0c080d6au; return 0; }
r[3]|=r[2];
goto P_0c080d6c;
P_0c080d6c: /* original 2f32, guest PC 0x0c080d6c */
if(!s->budget--) { s->failed_pc=0x0c080d6cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c080d6e;
P_0c080d6e: /* original 9237, guest PC 0x0c080d6e */
if(!s->budget--) { s->failed_pc=0x0c080d6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de0u,2);
goto P_0c080d70;
P_0c080d70: /* original 1f23, guest PC 0x0c080d70 */
if(!s->budget--) { s->failed_pc=0x0c080d70u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c080d72;
P_0c080d72: /* original 01fc, guest PC 0x0c080d72 */
if(!s->budget--) { s->failed_pc=0x0c080d72u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c080d74;
P_0c080d74: /* original 3183, guest PC 0x0c080d74 */
if(!s->budget--) { s->failed_pc=0x0c080d74u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[8])!=0);
goto P_0c080d76;
P_0c080d76: /* original 8f02, guest PC 0x0c080d76 */
if(!s->budget--) { s->failed_pc=0x0c080d76u; return 0; }
cond=r[17]&1u;
r[10]+=0xfffffffcu;
if(!cond) { goto P_0c080d7e; }
goto P_0c080d7a;
P_0c080d78: /* original 7afc, guest PC 0x0c080d78 */
if(!s->budget--) { s->failed_pc=0x0c080d78u; return 0; }
r[10]+=0xfffffffcu;
goto P_0c080d7a;
P_0c080d7a: /* original 9132, guest PC 0x0c080d7a */
if(!s->budget--) { s->failed_pc=0x0c080d7au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de2u,2);
goto P_0c080d7c;
P_0c080d7c: /* original 1f13, guest PC 0x0c080d7c */
if(!s->budget--) { s->failed_pc=0x0c080d7cu; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c080d7e;
P_0c080d7e: /* original 2fe6, guest PC 0x0c080d7e */
if(!s->budget--) { s->failed_pc=0x0c080d7eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080d80;
P_0c080d80: /* original e700, guest PC 0x0c080d80 */
if(!s->budget--) { s->failed_pc=0x0c080d80u; return 0; }
r[7]=0x00000000u;
goto P_0c080d82;
P_0c080d82: /* original 55f4, guest PC 0x0c080d82 */
if(!s->budget--) { s->failed_pc=0x0c080d82u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c080d84;
P_0c080d84: /* original d31e, guest PC 0x0c080d84 */
if(!s->budget--) { s->failed_pc=0x0c080d84u; return 0; }
r[3]=read(ram,0x0c080e00u,4);
goto P_0c080d86;
P_0c080d86: /* original 56f3, guest PC 0x0c080d86 */
if(!s->budget--) { s->failed_pc=0x0c080d86u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c080d88;
P_0c080d88: /* original 430b, guest PC 0x0c080d88 */
if(!s->budget--) { s->failed_pc=0x0c080d88u; return 0; }
target=r[3];
r[16]=code_base|0x0c080d8cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080d8cu) { target=s->pc; goto dispatch; }
goto P_0c080d8c;
P_0c080d8a: /* original 54f1, guest PC 0x0c080d8a */
if(!s->budget--) { s->failed_pc=0x0c080d8au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080d8c;
P_0c080d8c: /* original 63b3, guest PC 0x0c080d8c */
if(!s->budget--) { s->failed_pc=0x0c080d8cu; return 0; }
r[3]=r[11];
goto P_0c080d8e;
P_0c080d8e: /* original 6293, guest PC 0x0c080d8e */
if(!s->budget--) { s->failed_pc=0x0c080d8eu; return 0; }
r[2]=r[9];
goto P_0c080d90;
P_0c080d90: /* original 23c9, guest PC 0x0c080d90 */
if(!s->budget--) { s->failed_pc=0x0c080d90u; return 0; }
r[3]&=r[12];
goto P_0c080d92;
P_0c080d92: /* original 22d9, guest PC 0x0c080d92 */
if(!s->budget--) { s->failed_pc=0x0c080d92u; return 0; }
r[2]&=r[13];
goto P_0c080d94;
P_0c080d94: /* original e018, guest PC 0x0c080d94 */
if(!s->budget--) { s->failed_pc=0x0c080d94u; return 0; }
r[0]=0x00000018u;
goto P_0c080d96;
P_0c080d96: /* original 223b, guest PC 0x0c080d96 */
if(!s->budget--) { s->failed_pc=0x0c080d96u; return 0; }
r[2]|=r[3];
goto P_0c080d98;
P_0c080d98: /* original 7f04, guest PC 0x0c080d98 */
if(!s->budget--) { s->failed_pc=0x0c080d98u; return 0; }
r[15]+=0x00000004u;
goto P_0c080d9a;
P_0c080d9a: /* original 2f22, guest PC 0x0c080d9a */
if(!s->budget--) { s->failed_pc=0x0c080d9au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c080d9c;
P_0c080d9c: /* original 9322, guest PC 0x0c080d9c */
if(!s->budget--) { s->failed_pc=0x0c080d9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de4u,2);
goto P_0c080d9e;
P_0c080d9e: /* original 1f33, guest PC 0x0c080d9e */
if(!s->budget--) { s->failed_pc=0x0c080d9eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c080da0;
P_0c080da0: /* original 01fc, guest PC 0x0c080da0 */
if(!s->budget--) { s->failed_pc=0x0c080da0u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c080da2;
P_0c080da2: /* original 3183, guest PC 0x0c080da2 */
if(!s->budget--) { s->failed_pc=0x0c080da2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[8])!=0);
goto P_0c080da4;
P_0c080da4: /* original 8f02, guest PC 0x0c080da4 */
if(!s->budget--) { s->failed_pc=0x0c080da4u; return 0; }
cond=r[17]&1u;
r[9]+=0x00000004u;
if(!cond) { goto P_0c080dac; }
goto P_0c080da8;
P_0c080da6: /* original 7904, guest PC 0x0c080da6 */
if(!s->budget--) { s->failed_pc=0x0c080da6u; return 0; }
r[9]+=0x00000004u;
goto P_0c080da8;
P_0c080da8: /* original 911d, guest PC 0x0c080da8 */
if(!s->budget--) { s->failed_pc=0x0c080da8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c080de6u,2);
goto P_0c080daa;
P_0c080daa: /* original 1f13, guest PC 0x0c080daa */
if(!s->budget--) { s->failed_pc=0x0c080daau; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c080dac;
P_0c080dac: /* original 2fe6, guest PC 0x0c080dac */
if(!s->budget--) { s->failed_pc=0x0c080dacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c080dae;
P_0c080dae: /* original e700, guest PC 0x0c080dae */
if(!s->budget--) { s->failed_pc=0x0c080daeu; return 0; }
r[7]=0x00000000u;
goto P_0c080db0;
P_0c080db0: /* original 55f4, guest PC 0x0c080db0 */
if(!s->budget--) { s->failed_pc=0x0c080db0u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c080db2;
P_0c080db2: /* original d313, guest PC 0x0c080db2 */
if(!s->budget--) { s->failed_pc=0x0c080db2u; return 0; }
r[3]=read(ram,0x0c080e00u,4);
goto P_0c080db4;
P_0c080db4: /* original 56f3, guest PC 0x0c080db4 */
if(!s->budget--) { s->failed_pc=0x0c080db4u; return 0; }
r[6]=read(ram,r[15]+12,4);
goto P_0c080db6;
P_0c080db6: /* original 430b, guest PC 0x0c080db6 */
if(!s->budget--) { s->failed_pc=0x0c080db6u; return 0; }
target=r[3];
r[16]=code_base|0x0c080dbau;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c080dbau) { target=s->pc; goto dispatch; }
goto P_0c080dba;
P_0c080db8: /* original 54f1, guest PC 0x0c080db8 */
if(!s->budget--) { s->failed_pc=0x0c080db8u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c080dba;
P_0c080dba: /* original 7f04, guest PC 0x0c080dba */
if(!s->budget--) { s->failed_pc=0x0c080dbau; return 0; }
r[15]+=0x00000004u;
goto P_0c080dbc;
P_0c080dbc: /* original 52f1, guest PC 0x0c080dbc */
if(!s->budget--) { s->failed_pc=0x0c080dbcu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c080dbe;
P_0c080dbe: /* original 7201, guest PC 0x0c080dbe */
if(!s->budget--) { s->failed_pc=0x0c080dbeu; return 0; }
r[2]+=0x00000001u;
goto P_0c080dc0;
P_0c080dc0: /* original 1f21, guest PC 0x0c080dc0 */
if(!s->budget--) { s->failed_pc=0x0c080dc0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c080dc2;
P_0c080dc2: /* original 53f4, guest PC 0x0c080dc2 */
if(!s->budget--) { s->failed_pc=0x0c080dc2u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c080dc4;
P_0c080dc4: /* original 3233, guest PC 0x0c080dc4 */
if(!s->budget--) { s->failed_pc=0x0c080dc4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c080dc6;
P_0c080dc6: /* original 8fcb, guest PC 0x0c080dc6 */
if(!s->budget--) { s->failed_pc=0x0c080dc6u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000001u;
if(!cond) { goto P_0c080d60; }
goto P_0c080dca;
P_0c080dc8: /* original 7801, guest PC 0x0c080dc8 */
if(!s->budget--) { s->failed_pc=0x0c080dc8u; return 0; }
r[8]+=0x00000001u;
goto P_0c080dca;
P_0c080dca: /* original 7f1c, guest PC 0x0c080dca */
if(!s->budget--) { s->failed_pc=0x0c080dcau; return 0; }
r[15]+=0x0000001cu;
goto P_0c080dcc;
P_0c080dcc: /* original 4f26, guest PC 0x0c080dcc */
if(!s->budget--) { s->failed_pc=0x0c080dccu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c080dce;
P_0c080dce: /* original 68f6, guest PC 0x0c080dce */
if(!s->budget--) { s->failed_pc=0x0c080dceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c080dd0;
P_0c080dd0: /* original 69f6, guest PC 0x0c080dd0 */
if(!s->budget--) { s->failed_pc=0x0c080dd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c080dd2;
P_0c080dd2: /* original 6af6, guest PC 0x0c080dd2 */
if(!s->budget--) { s->failed_pc=0x0c080dd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c080dd4;
P_0c080dd4: /* original 6bf6, guest PC 0x0c080dd4 */
if(!s->budget--) { s->failed_pc=0x0c080dd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c080dd6;
P_0c080dd6: /* original 6cf6, guest PC 0x0c080dd6 */
if(!s->budget--) { s->failed_pc=0x0c080dd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c080dd8;
P_0c080dd8: /* original 6df6, guest PC 0x0c080dd8 */
if(!s->budget--) { s->failed_pc=0x0c080dd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c080dda;
P_0c080dda: /* original 000b, guest PC 0x0c080dda */
if(!s->budget--) { s->failed_pc=0x0c080ddau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c080ddc: /* original 6ef6, guest PC 0x0c080ddc */
if(!s->budget--) { s->failed_pc=0x0c080ddcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c080ddeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c080ddeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
