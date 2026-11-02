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
int vf3_away_batch71_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062bfau: goto P_0c062bfa;
case 0x0c062bfcu: goto P_0c062bfc;
case 0x0c062bfeu: goto P_0c062bfe;
case 0x0c062c00u: goto P_0c062c00;
case 0x0c062c02u: goto P_0c062c02;
case 0x0c062c04u: goto P_0c062c04;
case 0x0c062c06u: goto P_0c062c06;
case 0x0c062c08u: goto P_0c062c08;
case 0x0c062c0au: goto P_0c062c0a;
case 0x0c062c0cu: goto P_0c062c0c;
case 0x0c062c0eu: goto P_0c062c0e;
case 0x0c062c10u: goto P_0c062c10;
case 0x0c062c12u: goto P_0c062c12;
case 0x0c062c14u: goto P_0c062c14;
case 0x0c062c16u: goto P_0c062c16;
case 0x0c062c18u: goto P_0c062c18;
case 0x0c062c1au: goto P_0c062c1a;
case 0x0c062c1cu: goto P_0c062c1c;
case 0x0c062c1eu: goto P_0c062c1e;
case 0x0c062c20u: goto P_0c062c20;
case 0x0c062c22u: goto P_0c062c22;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062c4eu: goto P_0c062c4e;
case 0x0c062c50u: goto P_0c062c50;
case 0x0c062c52u: goto P_0c062c52;
case 0x0c062c54u: goto P_0c062c54;
case 0x0c062c56u: goto P_0c062c56;
case 0x0c062c58u: goto P_0c062c58;
case 0x0c062c5au: goto P_0c062c5a;
case 0x0c062c5cu: goto P_0c062c5c;
case 0x0c062c5eu: goto P_0c062c5e;
case 0x0c062c60u: goto P_0c062c60;
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
case 0x0c068c58u: goto P_0c068c58;
case 0x0c068c5au: goto P_0c068c5a;
case 0x0c068c5cu: goto P_0c068c5c;
case 0x0c068c5eu: goto P_0c068c5e;
case 0x0c068c60u: goto P_0c068c60;
case 0x0c068c62u: goto P_0c068c62;
case 0x0c068c64u: goto P_0c068c64;
case 0x0c068c66u: goto P_0c068c66;
case 0x0c068c68u: goto P_0c068c68;
case 0x0c068c6au: goto P_0c068c6a;
case 0x0c068c6cu: goto P_0c068c6c;
case 0x0c068c6eu: goto P_0c068c6e;
case 0x0c068c70u: goto P_0c068c70;
case 0x0c068c72u: goto P_0c068c72;
case 0x0c068c74u: goto P_0c068c74;
case 0x0c068c76u: goto P_0c068c76;
case 0x0c068c78u: goto P_0c068c78;
case 0x0c068c7au: goto P_0c068c7a;
case 0x0c068c7cu: goto P_0c068c7c;
case 0x0c068c7eu: goto P_0c068c7e;
case 0x0c068c80u: goto P_0c068c80;
case 0x0c068c82u: goto P_0c068c82;
case 0x0c068c84u: goto P_0c068c84;
case 0x0c068c86u: goto P_0c068c86;
case 0x0c068c88u: goto P_0c068c88;
case 0x0c068c8au: goto P_0c068c8a;
case 0x0c068c8cu: goto P_0c068c8c;
case 0x0c068c8eu: goto P_0c068c8e;
case 0x0c068c90u: goto P_0c068c90;
case 0x0c068c92u: goto P_0c068c92;
case 0x0c068c94u: goto P_0c068c94;
case 0x0c068c96u: goto P_0c068c96;
case 0x0c068c98u: goto P_0c068c98;
case 0x0c068c9au: goto P_0c068c9a;
case 0x0c068c9cu: goto P_0c068c9c;
case 0x0c068c9eu: goto P_0c068c9e;
case 0x0c068ca0u: goto P_0c068ca0;
case 0x0c068ca2u: goto P_0c068ca2;
case 0x0c068ca4u: goto P_0c068ca4;
case 0x0c068ca6u: goto P_0c068ca6;
case 0x0c068ca8u: goto P_0c068ca8;
case 0x0c068caau: goto P_0c068caa;
case 0x0c068cacu: goto P_0c068cac;
case 0x0c068caeu: goto P_0c068cae;
case 0x0c068cb0u: goto P_0c068cb0;
case 0x0c068cb2u: goto P_0c068cb2;
case 0x0c068cb4u: goto P_0c068cb4;
case 0x0c068cb6u: goto P_0c068cb6;
case 0x0c068cb8u: goto P_0c068cb8;
case 0x0c068cbau: goto P_0c068cba;
case 0x0c068cbcu: goto P_0c068cbc;
case 0x0c068cbeu: goto P_0c068cbe;
case 0x0c068cc0u: goto P_0c068cc0;
case 0x0c068cc2u: goto P_0c068cc2;
case 0x0c068cc4u: goto P_0c068cc4;
case 0x0c068cc6u: goto P_0c068cc6;
case 0x0c068cc8u: goto P_0c068cc8;
case 0x0c068ccau: goto P_0c068cca;
case 0x0c068cccu: goto P_0c068ccc;
case 0x0c068cceu: goto P_0c068cce;
case 0x0c068cd0u: goto P_0c068cd0;
case 0x0c068cd2u: goto P_0c068cd2;
case 0x0c068cd4u: goto P_0c068cd4;
case 0x0c068cd6u: goto P_0c068cd6;
case 0x0c068cd8u: goto P_0c068cd8;
case 0x0c068cdau: goto P_0c068cda;
case 0x0c068cdcu: goto P_0c068cdc;
case 0x0c068cdeu: goto P_0c068cde;
case 0x0c068ce0u: goto P_0c068ce0;
case 0x0c068ce2u: goto P_0c068ce2;
case 0x0c068ce4u: goto P_0c068ce4;
case 0x0c068ce6u: goto P_0c068ce6;
case 0x0c068ce8u: goto P_0c068ce8;
case 0x0c068ceau: goto P_0c068cea;
case 0x0c068cecu: goto P_0c068cec;
case 0x0c068ceeu: goto P_0c068cee;
case 0x0c068cf0u: goto P_0c068cf0;
case 0x0c068cf2u: goto P_0c068cf2;
case 0x0c068cf4u: goto P_0c068cf4;
case 0x0c068cf6u: goto P_0c068cf6;
case 0x0c068cf8u: goto P_0c068cf8;
case 0x0c068cfau: goto P_0c068cfa;
case 0x0c068cfcu: goto P_0c068cfc;
case 0x0c068cfeu: goto P_0c068cfe;
case 0x0c068d00u: goto P_0c068d00;
case 0x0c068d02u: goto P_0c068d02;
case 0x0c068d04u: goto P_0c068d04;
case 0x0c068d06u: goto P_0c068d06;
case 0x0c068d08u: goto P_0c068d08;
case 0x0c068d0au: goto P_0c068d0a;
case 0x0c068d0cu: goto P_0c068d0c;
case 0x0c068d54u: goto P_0c068d54;
case 0x0c068d56u: goto P_0c068d56;
case 0x0c068d58u: goto P_0c068d58;
case 0x0c068d5au: goto P_0c068d5a;
case 0x0c068d5cu: goto P_0c068d5c;
case 0x0c068d5eu: goto P_0c068d5e;
case 0x0c068d60u: goto P_0c068d60;
case 0x0c068d62u: goto P_0c068d62;
case 0x0c068d64u: goto P_0c068d64;
case 0x0c068d66u: goto P_0c068d66;
case 0x0c068d68u: goto P_0c068d68;
case 0x0c068d6au: goto P_0c068d6a;
case 0x0c068d6cu: goto P_0c068d6c;
case 0x0c068d6eu: goto P_0c068d6e;
case 0x0c068d70u: goto P_0c068d70;
case 0x0c068d72u: goto P_0c068d72;
case 0x0c068d74u: goto P_0c068d74;
case 0x0c068d76u: goto P_0c068d76;
case 0x0c068d78u: goto P_0c068d78;
case 0x0c068d7au: goto P_0c068d7a;
case 0x0c068d7cu: goto P_0c068d7c;
case 0x0c068d7eu: goto P_0c068d7e;
case 0x0c068d80u: goto P_0c068d80;
case 0x0c068d82u: goto P_0c068d82;
case 0x0c068d84u: goto P_0c068d84;
case 0x0c068d86u: goto P_0c068d86;
case 0x0c068d88u: goto P_0c068d88;
case 0x0c068d8au: goto P_0c068d8a;
case 0x0c068d8cu: goto P_0c068d8c;
case 0x0c068d8eu: goto P_0c068d8e;
case 0x0c068d90u: goto P_0c068d90;
case 0x0c068d92u: goto P_0c068d92;
case 0x0c068d94u: goto P_0c068d94;
case 0x0c068d96u: goto P_0c068d96;
case 0x0c068d98u: goto P_0c068d98;
case 0x0c068d9au: goto P_0c068d9a;
case 0x0c068d9cu: goto P_0c068d9c;
case 0x0c068d9eu: goto P_0c068d9e;
case 0x0c068da0u: goto P_0c068da0;
case 0x0c068da2u: goto P_0c068da2;
case 0x0c068da4u: goto P_0c068da4;
case 0x0c068da6u: goto P_0c068da6;
case 0x0c068da8u: goto P_0c068da8;
case 0x0c068daau: goto P_0c068daa;
case 0x0c068dacu: goto P_0c068dac;
case 0x0c068daeu: goto P_0c068dae;
case 0x0c068db0u: goto P_0c068db0;
case 0x0c068db2u: goto P_0c068db2;
case 0x0c068db4u: goto P_0c068db4;
case 0x0c068db6u: goto P_0c068db6;
case 0x0c068db8u: goto P_0c068db8;
case 0x0c068dbau: goto P_0c068dba;
case 0x0c068dbcu: goto P_0c068dbc;
case 0x0c068dbeu: goto P_0c068dbe;
case 0x0c068dc0u: goto P_0c068dc0;
case 0x0c068dc2u: goto P_0c068dc2;
case 0x0c068dc4u: goto P_0c068dc4;
case 0x0c068dc6u: goto P_0c068dc6;
case 0x0c068dc8u: goto P_0c068dc8;
case 0x0c068dcau: goto P_0c068dca;
case 0x0c068dccu: goto P_0c068dcc;
case 0x0c068dceu: goto P_0c068dce;
case 0x0c068dd0u: goto P_0c068dd0;
case 0x0c068dd2u: goto P_0c068dd2;
case 0x0c068dd4u: goto P_0c068dd4;
case 0x0c068dd6u: goto P_0c068dd6;
case 0x0c068dd8u: goto P_0c068dd8;
case 0x0c068ddau: goto P_0c068dda;
case 0x0c068ddcu: goto P_0c068ddc;
case 0x0c068ddeu: goto P_0c068dde;
case 0x0c068de0u: goto P_0c068de0;
case 0x0c068de2u: goto P_0c068de2;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062bfa: /* original e700, guest PC 0x0c062bfa */
if(!s->budget--) { s->failed_pc=0x0c062bfau; return 0; }
r[7]=0x00000000u;
goto P_0c062bfc;
P_0c062bfc: /* original d526, guest PC 0x0c062bfc */
if(!s->budget--) { s->failed_pc=0x0c062bfcu; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062bfe;
P_0c062bfe: /* original 6453, guest PC 0x0c062bfe */
if(!s->budget--) { s->failed_pc=0x0c062bfeu; return 0; }
r[4]=r[5];
goto P_0c062c00;
P_0c062c00: /* original 9047, guest PC 0x0c062c00 */
if(!s->budget--) { s->failed_pc=0x0c062c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c02;
P_0c062c02: /* original 6653, guest PC 0x0c062c02 */
if(!s->budget--) { s->failed_pc=0x0c062c02u; return 0; }
r[6]=r[5];
goto P_0c062c04;
P_0c062c04: /* original e501, guest PC 0x0c062c04 */
if(!s->budget--) { s->failed_pc=0x0c062c04u; return 0; }
r[5]=0x00000001u;
goto P_0c062c06;
P_0c062c06: /* original 6361, guest PC 0x0c062c06 */
if(!s->budget--) { s->failed_pc=0x0c062c06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c062c08;
P_0c062c08: /* original 633d, guest PC 0x0c062c08 */
if(!s->budget--) { s->failed_pc=0x0c062c08u; return 0; }
r[3]=r[3]&65535u;
goto P_0c062c0a;
P_0c062c0a: /* original 2358, guest PC 0x0c062c0a */
if(!s->budget--) { s->failed_pc=0x0c062c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c062c0c;
P_0c062c0c: /* original 8b02, guest PC 0x0c062c0c */
if(!s->budget--) { s->failed_pc=0x0c062c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c14; }
goto P_0c062c0e;
P_0c062c0e: /* original 2451, guest PC 0x0c062c0e */
if(!s->budget--) { s->failed_pc=0x0c062c0eu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c062c10;
P_0c062c10: /* original 000b, guest PC 0x0c062c10 */
if(!s->budget--) { s->failed_pc=0x0c062c10u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c062c12: /* original 6043, guest PC 0x0c062c12 */
if(!s->budget--) { s->failed_pc=0x0c062c12u; return 0; }
r[0]=r[4];
goto P_0c062c14;
P_0c062c14: /* original 7701, guest PC 0x0c062c14 */
if(!s->budget--) { s->failed_pc=0x0c062c14u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c16;
P_0c062c16: /* original 744c, guest PC 0x0c062c16 */
if(!s->budget--) { s->failed_pc=0x0c062c16u; return 0; }
r[4]+=0x0000004cu;
goto P_0c062c18;
P_0c062c18: /* original 3703, guest PC 0x0c062c18 */
if(!s->budget--) { s->failed_pc=0x0c062c18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c062c1a;
P_0c062c1a: /* original 8ff4, guest PC 0x0c062c1a */
if(!s->budget--) { s->failed_pc=0x0c062c1au; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c06; }
goto P_0c062c1e;
P_0c062c1c: /* original 764c, guest PC 0x0c062c1c */
if(!s->budget--) { s->failed_pc=0x0c062c1cu; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c1e;
P_0c062c1e: /* original e000, guest PC 0x0c062c1e */
if(!s->budget--) { s->failed_pc=0x0c062c1eu; return 0; }
r[0]=0x00000000u;
goto P_0c062c20;
P_0c062c20: /* original 000b, guest PC 0x0c062c20 */
if(!s->budget--) { s->failed_pc=0x0c062c20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062c22: /* original 0009, guest PC 0x0c062c22 */
if(!s->budget--) { s->failed_pc=0x0c062c22u; return 0; }
goto P_0c062c24;
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062c4e;
P_0c062c4e: /* original 6342, guest PC 0x0c062c4e */
if(!s->budget--) { s->failed_pc=0x0c062c4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c062c50;
P_0c062c50: /* original 2338, guest PC 0x0c062c50 */
if(!s->budget--) { s->failed_pc=0x0c062c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062c52;
P_0c062c52: /* original 8b02, guest PC 0x0c062c52 */
if(!s->budget--) { s->failed_pc=0x0c062c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c5a; }
goto P_0c062c54;
P_0c062c54: /* original e300, guest PC 0x0c062c54 */
if(!s->budget--) { s->failed_pc=0x0c062c54u; return 0; }
r[3]=0x00000000u;
goto P_0c062c56;
P_0c062c56: /* original a002, guest PC 0x0c062c56 */
if(!s->budget--) { s->failed_pc=0x0c062c56u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5e;
P_0c062c58: /* original 1531, guest PC 0x0c062c58 */
if(!s->budget--) { s->failed_pc=0x0c062c58u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5a;
P_0c062c5a: /* original 6242, guest PC 0x0c062c5a */
if(!s->budget--) { s->failed_pc=0x0c062c5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c062c5c;
P_0c062c5c: /* original 1521, guest PC 0x0c062c5c */
if(!s->budget--) { s->failed_pc=0x0c062c5cu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c062c5e;
P_0c062c5e: /* original 000b, guest PC 0x0c062c5e */
if(!s->budget--) { s->failed_pc=0x0c062c5eu; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c062c60: /* original 2452, guest PC 0x0c062c60 */
if(!s->budget--) { s->failed_pc=0x0c062c60u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c062c62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c62u; return 0; } return 1;
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0644d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644d6u; return 0; } return 1;
P_0c068c58: /* original 2fe6, guest PC 0x0c068c58 */
if(!s->budget--) { s->failed_pc=0x0c068c58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5a;
P_0c068c5a: /* original 2fd6, guest PC 0x0c068c5a */
if(!s->budget--) { s->failed_pc=0x0c068c5au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5c;
P_0c068c5c: /* original 2fc6, guest PC 0x0c068c5c */
if(!s->budget--) { s->failed_pc=0x0c068c5cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c5e;
P_0c068c5e: /* original ec0f, guest PC 0x0c068c5e */
if(!s->budget--) { s->failed_pc=0x0c068c5eu; return 0; }
r[12]=0x0000000fu;
goto P_0c068c60;
P_0c068c60: /* original 2fb6, guest PC 0x0c068c60 */
if(!s->budget--) { s->failed_pc=0x0c068c60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c62;
P_0c068c62: /* original 2fa6, guest PC 0x0c068c62 */
if(!s->budget--) { s->failed_pc=0x0c068c62u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c64;
P_0c068c64: /* original 2f96, guest PC 0x0c068c64 */
if(!s->budget--) { s->failed_pc=0x0c068c64u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c66;
P_0c068c66: /* original 2f86, guest PC 0x0c068c66 */
if(!s->budget--) { s->failed_pc=0x0c068c66u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068c68;
P_0c068c68: /* original d92b, guest PC 0x0c068c68 */
if(!s->budget--) { s->failed_pc=0x0c068c68u; return 0; }
r[9]=read(ram,0x0c068d18u,4);
goto P_0c068c6a;
P_0c068c6a: /* original d833, guest PC 0x0c068c6a */
if(!s->budget--) { s->failed_pc=0x0c068c6au; return 0; }
r[8]=read(ram,0x0c068d38u,4);
goto P_0c068c6c;
P_0c068c6c: /* original 6393, guest PC 0x0c068c6c */
if(!s->budget--) { s->failed_pc=0x0c068c6cu; return 0; }
r[3]=r[9];
goto P_0c068c6e;
P_0c068c6e: /* original 731c, guest PC 0x0c068c6e */
if(!s->budget--) { s->failed_pc=0x0c068c6eu; return 0; }
r[3]+=0x0000001cu;
goto P_0c068c70;
P_0c068c70: /* original 6030, guest PC 0x0c068c70 */
if(!s->budget--) { s->failed_pc=0x0c068c70u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c068c72;
P_0c068c72: /* original 4f22, guest PC 0x0c068c72 */
if(!s->budget--) { s->failed_pc=0x0c068c72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c068c74;
P_0c068c74: /* original 600c, guest PC 0x0c068c74 */
if(!s->budget--) { s->failed_pc=0x0c068c74u; return 0; }
r[0]=r[0]&255u;
goto P_0c068c76;
P_0c068c76: /* original da31, guest PC 0x0c068c76 */
if(!s->budget--) { s->failed_pc=0x0c068c76u; return 0; }
r[10]=read(ram,0x0c068d3cu,4);
goto P_0c068c78;
P_0c068c78: /* original 2c09, guest PC 0x0c068c78 */
if(!s->budget--) { s->failed_pc=0x0c068c78u; return 0; }
r[12]&=r[0];
goto P_0c068c7a;
P_0c068c7a: /* original de2a, guest PC 0x0c068c7a */
if(!s->budget--) { s->failed_pc=0x0c068c7au; return 0; }
r[14]=read(ram,0x0c068d24u,4);
goto P_0c068c7c;
P_0c068c7c: /* original 6bc3, guest PC 0x0c068c7c */
if(!s->budget--) { s->failed_pc=0x0c068c7cu; return 0; }
r[11]=r[12];
goto P_0c068c7e;
P_0c068c7e: /* original 4b08, guest PC 0x0c068c7e */
if(!s->budget--) { s->failed_pc=0x0c068c7eu; return 0; }
r[11]<<=2;
goto P_0c068c80;
P_0c068c80: /* original 60b3, guest PC 0x0c068c80 */
if(!s->budget--) { s->failed_pc=0x0c068c80u; return 0; }
r[0]=r[11];
goto P_0c068c82;
P_0c068c82: /* original 008e, guest PC 0x0c068c82 */
if(!s->budget--) { s->failed_pc=0x0c068c82u; return 0; }
r[0]=read(ram,r[8]+r[0],4);
goto P_0c068c84;
P_0c068c84: /* original 88ff, guest PC 0x0c068c84 */
if(!s->budget--) { s->failed_pc=0x0c068c84u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c068c86;
P_0c068c86: /* original 8d36, guest PC 0x0c068c86 */
if(!s->budget--) { s->failed_pc=0x0c068c86u; return 0; }
cond=r[17]&1u;
r[4]=0x00000000u;
if(cond) { goto P_0c068cf6; }
goto P_0c068c8a;
P_0c068c88: /* original e400, guest PC 0x0c068c88 */
if(!s->budget--) { s->failed_pc=0x0c068c88u; return 0; }
r[4]=0x00000000u;
goto P_0c068c8a;
P_0c068c8a: /* original 6192, guest PC 0x0c068c8a */
if(!s->budget--) { s->failed_pc=0x0c068c8au; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c068c8c;
P_0c068c8c: /* original d22c, guest PC 0x0c068c8c */
if(!s->budget--) { s->failed_pc=0x0c068c8cu; return 0; }
r[2]=read(ram,0x0c068d40u,4);
goto P_0c068c8e;
P_0c068c8e: /* original dd23, guest PC 0x0c068c8e */
if(!s->budget--) { s->failed_pc=0x0c068c8eu; return 0; }
r[13]=read(ram,0x0c068d1cu,4);
goto P_0c068c90;
P_0c068c90: /* original 2128, guest PC 0x0c068c90 */
if(!s->budget--) { s->failed_pc=0x0c068c90u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c068c92;
P_0c068c92: /* original 8912, guest PC 0x0c068c92 */
if(!s->budget--) { s->failed_pc=0x0c068c92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068cba; }
goto P_0c068c94;
P_0c068c94: /* original 903d, guest PC 0x0c068c94 */
if(!s->budget--) { s->failed_pc=0x0c068c94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068c96;
P_0c068c96: /* original 0a46, guest PC 0x0c068c96 */
if(!s->budget--) { s->failed_pc=0x0c068c96u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068c98;
P_0c068c98: /* original 60b3, guest PC 0x0c068c98 */
if(!s->budget--) { s->failed_pc=0x0c068c98u; return 0; }
r[0]=r[11];
goto P_0c068c9a;
P_0c068c9a: /* original 2e42, guest PC 0x0c068c9a */
if(!s->budget--) { s->failed_pc=0x0c068c9au; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068c9c;
P_0c068c9c: /* original 933a, guest PC 0x0c068c9c */
if(!s->budget--) { s->failed_pc=0x0c068c9cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d14u,2);
goto P_0c068c9e;
P_0c068c9e: /* original 2f36, guest PC 0x0c068c9e */
if(!s->budget--) { s->failed_pc=0x0c068c9eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca0;
P_0c068ca0: /* original d228, guest PC 0x0c068ca0 */
if(!s->budget--) { s->failed_pc=0x0c068ca0u; return 0; }
r[2]=read(ram,0x0c068d44u,4);
goto P_0c068ca2;
P_0c068ca2: /* original 2f26, guest PC 0x0c068ca2 */
if(!s->budget--) { s->failed_pc=0x0c068ca2u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca4;
P_0c068ca4: /* original 2fc6, guest PC 0x0c068ca4 */
if(!s->budget--) { s->failed_pc=0x0c068ca4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c068ca6;
P_0c068ca6: /* original 9636, guest PC 0x0c068ca6 */
if(!s->budget--) { s->failed_pc=0x0c068ca6u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d16u,2);
goto P_0c068ca8;
P_0c068ca8: /* original d727, guest PC 0x0c068ca8 */
if(!s->budget--) { s->failed_pc=0x0c068ca8u; return 0; }
r[7]=read(ram,0x0c068d48u,4);
goto P_0c068caa;
P_0c068caa: /* original 369c, guest PC 0x0c068caa */
if(!s->budget--) { s->failed_pc=0x0c068caau; return 0; }
r[6]+=r[9];
goto P_0c068cac;
P_0c068cac: /* original 65d2, guest PC 0x0c068cac */
if(!s->budget--) { s->failed_pc=0x0c068cacu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cae;
P_0c068cae: /* original d327, guest PC 0x0c068cae */
if(!s->budget--) { s->failed_pc=0x0c068caeu; return 0; }
r[3]=read(ram,0x0c068d4cu,4);
goto P_0c068cb0;
P_0c068cb0: /* original 7608, guest PC 0x0c068cb0 */
if(!s->budget--) { s->failed_pc=0x0c068cb0u; return 0; }
r[6]+=0x00000008u;
goto P_0c068cb2;
P_0c068cb2: /* original 430b, guest PC 0x0c068cb2 */
if(!s->budget--) { s->failed_pc=0x0c068cb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cb6u;
r[4]=read(ram,r[8]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068cb6u) { target=s->pc; goto dispatch; }
goto P_0c068cb6;
P_0c068cb4: /* original 048e, guest PC 0x0c068cb4 */
if(!s->budget--) { s->failed_pc=0x0c068cb4u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cb6;
P_0c068cb6: /* original a021, guest PC 0x0c068cb6 */
if(!s->budget--) { s->failed_pc=0x0c068cb6u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cfc;
P_0c068cb8: /* original 7f0c, guest PC 0x0c068cb8 */
if(!s->budget--) { s->failed_pc=0x0c068cb8u; return 0; }
r[15]+=0x0000000cu;
goto P_0c068cba;
P_0c068cba: /* original d325, guest PC 0x0c068cba */
if(!s->budget--) { s->failed_pc=0x0c068cbau; return 0; }
r[3]=read(ram,0x0c068d50u,4);
goto P_0c068cbc;
P_0c068cbc: /* original 60b3, guest PC 0x0c068cbc */
if(!s->budget--) { s->failed_pc=0x0c068cbcu; return 0; }
r[0]=r[11];
goto P_0c068cbe;
P_0c068cbe: /* original 65d2, guest PC 0x0c068cbe */
if(!s->budget--) { s->failed_pc=0x0c068cbeu; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c068cc0;
P_0c068cc0: /* original 430b, guest PC 0x0c068cc0 */
if(!s->budget--) { s->failed_pc=0x0c068cc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c068cc4u;
r[4]=read(ram,r[8]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c068cc4u) { target=s->pc; goto dispatch; }
goto P_0c068cc4;
P_0c068cc2: /* original 048e, guest PC 0x0c068cc2 */
if(!s->budget--) { s->failed_pc=0x0c068cc2u; return 0; }
r[4]=read(ram,r[8]+r[0],4);
goto P_0c068cc4;
P_0c068cc4: /* original 64d2, guest PC 0x0c068cc4 */
if(!s->budget--) { s->failed_pc=0x0c068cc4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c068cc6;
P_0c068cc6: /* original 9024, guest PC 0x0c068cc6 */
if(!s->budget--) { s->failed_pc=0x0c068cc6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cc8;
P_0c068cc8: /* original 6542, guest PC 0x0c068cc8 */
if(!s->budget--) { s->failed_pc=0x0c068cc8u; return 0; }
tmp=read(ram,r[4],4);
r[5]=tmp;
goto P_0c068cca;
P_0c068cca: /* original 6343, guest PC 0x0c068cca */
if(!s->budget--) { s->failed_pc=0x0c068ccau; return 0; }
r[3]=r[4];
goto P_0c068ccc;
P_0c068ccc: /* original 353c, guest PC 0x0c068ccc */
if(!s->budget--) { s->failed_pc=0x0c068cccu; return 0; }
r[5]+=r[3];
goto P_0c068cce;
P_0c068cce: /* original 0a56, guest PC 0x0c068cce */
if(!s->budget--) { s->failed_pc=0x0c068cceu; return 0; }
write(ram,r[10]+r[0],r[5],4);
goto P_0c068cd0;
P_0c068cd0: /* original 60c3, guest PC 0x0c068cd0 */
if(!s->budget--) { s->failed_pc=0x0c068cd0u; return 0; }
r[0]=r[12];
goto P_0c068cd2;
P_0c068cd2: /* original 5441, guest PC 0x0c068cd2 */
if(!s->budget--) { s->failed_pc=0x0c068cd2u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c068cd4;
P_0c068cd4: /* original 880c, guest PC 0x0c068cd4 */
if(!s->budget--) { s->failed_pc=0x0c068cd4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c068cd6;
P_0c068cd6: /* original 63d2, guest PC 0x0c068cd6 */
if(!s->budget--) { s->failed_pc=0x0c068cd6u; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c068cd8;
P_0c068cd8: /* original 343c, guest PC 0x0c068cd8 */
if(!s->budget--) { s->failed_pc=0x0c068cd8u; return 0; }
r[4]+=r[3];
goto P_0c068cda;
P_0c068cda: /* original 8f0f, guest PC 0x0c068cda */
if(!s->budget--) { s->failed_pc=0x0c068cdau; return 0; }
cond=r[17]&1u;
write(ram,r[14],r[4],4);
if(!cond) { goto P_0c068cfc; }
goto P_0c068cde;
P_0c068cdc: /* original 2e42, guest PC 0x0c068cdc */
if(!s->budget--) { s->failed_pc=0x0c068cdcu; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cde;
P_0c068cde: /* original c713, guest PC 0x0c068cde */
if(!s->budget--) { s->failed_pc=0x0c068cdeu; return 0; }
r[0]=code_base|0x00068d2cu;
goto P_0c068ce0;
P_0c068ce0: /* original 63e2, guest PC 0x0c068ce0 */
if(!s->budget--) { s->failed_pc=0x0c068ce0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068ce2;
P_0c068ce2: /* original f308, guest PC 0x0c068ce2 */
if(!s->budget--) { s->failed_pc=0x0c068ce2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068ce4;
P_0c068ce4: /* original d012, guest PC 0x0c068ce4 */
if(!s->budget--) { s->failed_pc=0x0c068ce4u; return 0; }
r[0]=read(ram,0x0c068d30u,4);
goto P_0c068ce6;
P_0c068ce6: /* original f337, guest PC 0x0c068ce6 */
if(!s->budget--) { s->failed_pc=0x0c068ce6u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068ce8;
P_0c068ce8: /* original c712, guest PC 0x0c068ce8 */
if(!s->budget--) { s->failed_pc=0x0c068ce8u; return 0; }
r[0]=code_base|0x00068d34u;
goto P_0c068cea;
P_0c068cea: /* original f308, guest PC 0x0c068cea */
if(!s->budget--) { s->failed_pc=0x0c068ceau; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c068cec;
P_0c068cec: /* original 900f, guest PC 0x0c068cec */
if(!s->budget--) { s->failed_pc=0x0c068cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d0eu,2);
goto P_0c068cee;
P_0c068cee: /* original 63e2, guest PC 0x0c068cee */
if(!s->budget--) { s->failed_pc=0x0c068ceeu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c068cf0;
P_0c068cf0: /* original f337, guest PC 0x0c068cf0 */
if(!s->budget--) { s->failed_pc=0x0c068cf0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c068cf2;
P_0c068cf2: /* original a003, guest PC 0x0c068cf2 */
if(!s->budget--) { s->failed_pc=0x0c068cf2u; return 0; }
goto P_0c068cfc;
P_0c068cf4: /* original 0009, guest PC 0x0c068cf4 */
if(!s->budget--) { s->failed_pc=0x0c068cf4u; return 0; }
goto P_0c068cf6;
P_0c068cf6: /* original 900c, guest PC 0x0c068cf6 */
if(!s->budget--) { s->failed_pc=0x0c068cf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c068d12u,2);
goto P_0c068cf8;
P_0c068cf8: /* original 0a46, guest PC 0x0c068cf8 */
if(!s->budget--) { s->failed_pc=0x0c068cf8u; return 0; }
write(ram,r[10]+r[0],r[4],4);
goto P_0c068cfa;
P_0c068cfa: /* original 2e42, guest PC 0x0c068cfa */
if(!s->budget--) { s->failed_pc=0x0c068cfau; return 0; }
write(ram,r[14],r[4],4);
goto P_0c068cfc;
P_0c068cfc: /* original 4f26, guest PC 0x0c068cfc */
if(!s->budget--) { s->failed_pc=0x0c068cfcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c068cfe;
P_0c068cfe: /* original 68f6, guest PC 0x0c068cfe */
if(!s->budget--) { s->failed_pc=0x0c068cfeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c068d00;
P_0c068d00: /* original 69f6, guest PC 0x0c068d00 */
if(!s->budget--) { s->failed_pc=0x0c068d00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c068d02;
P_0c068d02: /* original 6af6, guest PC 0x0c068d02 */
if(!s->budget--) { s->failed_pc=0x0c068d02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c068d04;
P_0c068d04: /* original 6bf6, guest PC 0x0c068d04 */
if(!s->budget--) { s->failed_pc=0x0c068d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c068d06;
P_0c068d06: /* original 6cf6, guest PC 0x0c068d06 */
if(!s->budget--) { s->failed_pc=0x0c068d06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c068d08;
P_0c068d08: /* original 6df6, guest PC 0x0c068d08 */
if(!s->budget--) { s->failed_pc=0x0c068d08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c068d0a;
P_0c068d0a: /* original 000b, guest PC 0x0c068d0a */
if(!s->budget--) { s->failed_pc=0x0c068d0au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c068d0c: /* original 6ef6, guest PC 0x0c068d0c */
if(!s->budget--) { s->failed_pc=0x0c068d0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c068d0eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c068d0eu; return 0; } return 1;
P_0c068d54: /* original 6043, guest PC 0x0c068d54 */
if(!s->budget--) { s->failed_pc=0x0c068d54u; return 0; }
r[0]=r[4];
goto P_0c068d56;
P_0c068d56: /* original 8802, guest PC 0x0c068d56 */
if(!s->budget--) { s->failed_pc=0x0c068d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c068d58;
P_0c068d58: /* original 8902, guest PC 0x0c068d58 */
if(!s->budget--) { s->failed_pc=0x0c068d58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068d60; }
goto P_0c068d5a;
P_0c068d5a: /* original 6043, guest PC 0x0c068d5a */
if(!s->budget--) { s->failed_pc=0x0c068d5au; return 0; }
r[0]=r[4];
goto P_0c068d5c;
P_0c068d5c: /* original 8807, guest PC 0x0c068d5c */
if(!s->budget--) { s->failed_pc=0x0c068d5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c068d5e;
P_0c068d5e: /* original 8b08, guest PC 0x0c068d5e */
if(!s->budget--) { s->failed_pc=0x0c068d5eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068d72; }
goto P_0c068d60;
P_0c068d60: /* original c73b, guest PC 0x0c068d60 */
if(!s->budget--) { s->failed_pc=0x0c068d60u; return 0; }
r[0]=code_base|0x00068e50u;
goto P_0c068d62;
P_0c068d62: /* original f358, guest PC 0x0c068d62 */
if(!s->budget--) { s->failed_pc=0x0c068d62u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c068d64;
P_0c068d64: /* original f408, guest PC 0x0c068d64 */
if(!s->budget--) { s->failed_pc=0x0c068d64u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c068d66;
P_0c068d66: /* original f342, guest PC 0x0c068d66 */
if(!s->budget--) { s->failed_pc=0x0c068d66u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c068d68;
P_0c068d68: /* original f53a, guest PC 0x0c068d68 */
if(!s->budget--) { s->failed_pc=0x0c068d68u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c068d6a;
P_0c068d6a: /* original f268, guest PC 0x0c068d6a */
if(!s->budget--) { s->failed_pc=0x0c068d6au; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068d6c;
P_0c068d6c: /* original f242, guest PC 0x0c068d6c */
if(!s->budget--) { s->failed_pc=0x0c068d6cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'*');
goto P_0c068d6e;
P_0c068d6e: /* original 000b, guest PC 0x0c068d6e */
if(!s->budget--) { s->failed_pc=0x0c068d6eu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[6]);
s->pc=target; return ram->oob==0;
P_0c068d70: /* original f62a, guest PC 0x0c068d70 */
if(!s->budget--) { s->failed_pc=0x0c068d70u; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068d72;
P_0c068d72: /* original 880d, guest PC 0x0c068d72 */
if(!s->budget--) { s->failed_pc=0x0c068d72u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c068d74;
P_0c068d74: /* original 8b34, guest PC 0x0c068d74 */
if(!s->budget--) { s->failed_pc=0x0c068d74u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c068de0; }
goto P_0c068d76;
P_0c068d76: /* original c737, guest PC 0x0c068d76 */
if(!s->budget--) { s->failed_pc=0x0c068d76u; return 0; }
r[0]=code_base|0x00068e54u;
goto P_0c068d78;
P_0c068d78: /* original f458, guest PC 0x0c068d78 */
if(!s->budget--) { s->failed_pc=0x0c068d78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
goto P_0c068d7a;
P_0c068d7a: /* original f508, guest PC 0x0c068d7a */
if(!s->budget--) { s->failed_pc=0x0c068d7au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c068d7c;
P_0c068d7c: /* original f452, guest PC 0x0c068d7c */
if(!s->budget--) { s->failed_pc=0x0c068d7cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c068d7e;
P_0c068d7e: /* original f35c, guest PC 0x0c068d7e */
if(!s->budget--) { s->failed_pc=0x0c068d7eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c068d80;
P_0c068d80: /* original f568, guest PC 0x0c068d80 */
if(!s->budget--) { s->failed_pc=0x0c068d80u; return 0; }
vf3_matrix_load(s,ram,5,r[6]);
goto P_0c068d82;
P_0c068d82: /* original f532, guest PC 0x0c068d82 */
if(!s->budget--) { s->failed_pc=0x0c068d82u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c068d84;
P_0c068d84: /* original f43d, guest PC 0x0c068d84 */
if(!s->budget--) { s->failed_pc=0x0c068d84u; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c068d86;
P_0c068d86: /* original 045a, guest PC 0x0c068d86 */
if(!s->budget--) { s->failed_pc=0x0c068d86u; return 0; }
r[4]=r[53];
goto P_0c068d88;
P_0c068d88: /* original f53d, guest PC 0x0c068d88 */
if(!s->budget--) { s->failed_pc=0x0c068d88u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c068d8a;
P_0c068d8a: /* original 2448, guest PC 0x0c068d8a */
if(!s->budget--) { s->failed_pc=0x0c068d8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c068d8c;
P_0c068d8c: /* original 8d13, guest PC 0x0c068d8c */
if(!s->budget--) { s->failed_pc=0x0c068d8cu; return 0; }
cond=r[17]&1u;
r[7]=r[53];
if(cond) { goto P_0c068db6; }
goto P_0c068d90;
P_0c068d8e: /* original 075a, guest PC 0x0c068d8e */
if(!s->budget--) { s->failed_pc=0x0c068d8eu; return 0; }
r[7]=r[53];
goto P_0c068d90;
P_0c068d90: /* original e201, guest PC 0x0c068d90 */
if(!s->budget--) { s->failed_pc=0x0c068d90u; return 0; }
r[2]=0x00000001u;
goto P_0c068d92;
P_0c068d92: /* original 2248, guest PC 0x0c068d92 */
if(!s->budget--) { s->failed_pc=0x0c068d92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[4])==0)!=0);
goto P_0c068d94;
P_0c068d94: /* original 8905, guest PC 0x0c068d94 */
if(!s->budget--) { s->failed_pc=0x0c068d94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da2; }
goto P_0c068d96;
P_0c068d96: /* original d130, guest PC 0x0c068d96 */
if(!s->budget--) { s->failed_pc=0x0c068d96u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068d98;
P_0c068d98: /* original 2148, guest PC 0x0c068d98 */
if(!s->budget--) { s->failed_pc=0x0c068d98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[4])==0)!=0);
goto P_0c068d9a;
P_0c068d9a: /* original 8901, guest PC 0x0c068d9a */
if(!s->budget--) { s->failed_pc=0x0c068d9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068da0; }
goto P_0c068d9c;
P_0c068d9c: /* original a001, guest PC 0x0c068d9c */
if(!s->budget--) { s->failed_pc=0x0c068d9cu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da2;
P_0c068d9e: /* original 74ff, guest PC 0x0c068d9e */
if(!s->budget--) { s->failed_pc=0x0c068d9eu; return 0; }
r[4]+=0xffffffffu;
goto P_0c068da0;
P_0c068da0: /* original 7401, guest PC 0x0c068da0 */
if(!s->budget--) { s->failed_pc=0x0c068da0u; return 0; }
r[4]+=0x00000001u;
goto P_0c068da2;
P_0c068da2: /* original 6343, guest PC 0x0c068da2 */
if(!s->budget--) { s->failed_pc=0x0c068da2u; return 0; }
r[3]=r[4];
goto P_0c068da4;
P_0c068da4: /* original 4408, guest PC 0x0c068da4 */
if(!s->budget--) { s->failed_pc=0x0c068da4u; return 0; }
r[4]<<=2;
goto P_0c068da6;
P_0c068da6: /* original 343c, guest PC 0x0c068da6 */
if(!s->budget--) { s->failed_pc=0x0c068da6u; return 0; }
r[4]+=r[3];
goto P_0c068da8;
P_0c068da8: /* original f258, guest PC 0x0c068da8 */
if(!s->budget--) { s->failed_pc=0x0c068da8u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c068daa;
P_0c068daa: /* original 4400, guest PC 0x0c068daa */
if(!s->budget--) { s->failed_pc=0x0c068daau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c068dac;
P_0c068dac: /* original 445a, guest PC 0x0c068dac */
if(!s->budget--) { s->failed_pc=0x0c068dacu; return 0; }
r[53]=r[4];
goto P_0c068dae;
P_0c068dae: /* original f32d, guest PC 0x0c068dae */
if(!s->budget--) { s->failed_pc=0x0c068daeu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068db0;
P_0c068db0: /* original f43c, guest PC 0x0c068db0 */
if(!s->budget--) { s->failed_pc=0x0c068db0u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068db2;
P_0c068db2: /* original f241, guest PC 0x0c068db2 */
if(!s->budget--) { s->failed_pc=0x0c068db2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068db4;
P_0c068db4: /* original f52a, guest PC 0x0c068db4 */
if(!s->budget--) { s->failed_pc=0x0c068db4u; return 0; }
vf3_matrix_store(s,ram,2,r[5]);
goto P_0c068db6;
P_0c068db6: /* original 2778, guest PC 0x0c068db6 */
if(!s->budget--) { s->failed_pc=0x0c068db6u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c068db8;
P_0c068db8: /* original 8912, guest PC 0x0c068db8 */
if(!s->budget--) { s->failed_pc=0x0c068db8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068de0; }
goto P_0c068dba;
P_0c068dba: /* original e201, guest PC 0x0c068dba */
if(!s->budget--) { s->failed_pc=0x0c068dbau; return 0; }
r[2]=0x00000001u;
goto P_0c068dbc;
P_0c068dbc: /* original 2278, guest PC 0x0c068dbc */
if(!s->budget--) { s->failed_pc=0x0c068dbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[7])==0)!=0);
goto P_0c068dbe;
P_0c068dbe: /* original 8905, guest PC 0x0c068dbe */
if(!s->budget--) { s->failed_pc=0x0c068dbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dcc; }
goto P_0c068dc0;
P_0c068dc0: /* original d125, guest PC 0x0c068dc0 */
if(!s->budget--) { s->failed_pc=0x0c068dc0u; return 0; }
r[1]=read(ram,0x0c068e58u,4);
goto P_0c068dc2;
P_0c068dc2: /* original 2178, guest PC 0x0c068dc2 */
if(!s->budget--) { s->failed_pc=0x0c068dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[7])==0)!=0);
goto P_0c068dc4;
P_0c068dc4: /* original 8901, guest PC 0x0c068dc4 */
if(!s->budget--) { s->failed_pc=0x0c068dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c068dca; }
goto P_0c068dc6;
P_0c068dc6: /* original a001, guest PC 0x0c068dc6 */
if(!s->budget--) { s->failed_pc=0x0c068dc6u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dcc;
P_0c068dc8: /* original 77ff, guest PC 0x0c068dc8 */
if(!s->budget--) { s->failed_pc=0x0c068dc8u; return 0; }
r[7]+=0xffffffffu;
goto P_0c068dca;
P_0c068dca: /* original 7701, guest PC 0x0c068dca */
if(!s->budget--) { s->failed_pc=0x0c068dcau; return 0; }
r[7]+=0x00000001u;
goto P_0c068dcc;
P_0c068dcc: /* original 6373, guest PC 0x0c068dcc */
if(!s->budget--) { s->failed_pc=0x0c068dccu; return 0; }
r[3]=r[7];
goto P_0c068dce;
P_0c068dce: /* original 4708, guest PC 0x0c068dce */
if(!s->budget--) { s->failed_pc=0x0c068dceu; return 0; }
r[7]<<=2;
goto P_0c068dd0;
P_0c068dd0: /* original 373c, guest PC 0x0c068dd0 */
if(!s->budget--) { s->failed_pc=0x0c068dd0u; return 0; }
r[7]+=r[3];
goto P_0c068dd2;
P_0c068dd2: /* original f268, guest PC 0x0c068dd2 */
if(!s->budget--) { s->failed_pc=0x0c068dd2u; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c068dd4;
P_0c068dd4: /* original 4700, guest PC 0x0c068dd4 */
if(!s->budget--) { s->failed_pc=0x0c068dd4u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c068dd6;
P_0c068dd6: /* original 475a, guest PC 0x0c068dd6 */
if(!s->budget--) { s->failed_pc=0x0c068dd6u; return 0; }
r[53]=r[7];
goto P_0c068dd8;
P_0c068dd8: /* original f32d, guest PC 0x0c068dd8 */
if(!s->budget--) { s->failed_pc=0x0c068dd8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c068dda;
P_0c068dda: /* original f43c, guest PC 0x0c068dda */
if(!s->budget--) { s->failed_pc=0x0c068ddau; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c068ddc;
P_0c068ddc: /* original f241, guest PC 0x0c068ddc */
if(!s->budget--) { s->failed_pc=0x0c068ddcu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[4],r[18],'-');
goto P_0c068dde;
P_0c068dde: /* original f62a, guest PC 0x0c068dde */
if(!s->budget--) { s->failed_pc=0x0c068ddeu; return 0; }
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c068de0;
P_0c068de0: /* original 000b, guest PC 0x0c068de0 */
if(!s->budget--) { s->failed_pc=0x0c068de0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c068de2: /* original 0009, guest PC 0x0c068de2 */
if(!s->budget--) { s->failed_pc=0x0c068de2u; return 0; }
return vf3_matrix_family(0x0c068de4u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
