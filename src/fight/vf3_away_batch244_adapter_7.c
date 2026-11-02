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
int vf3_away_batch244_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c4d14u: goto P_0c0c4d14;
case 0x0c0c4d16u: goto P_0c0c4d16;
case 0x0c0c4d18u: goto P_0c0c4d18;
case 0x0c0c4d1au: goto P_0c0c4d1a;
case 0x0c0c4d1cu: goto P_0c0c4d1c;
case 0x0c0c4d1eu: goto P_0c0c4d1e;
case 0x0c0c4d20u: goto P_0c0c4d20;
case 0x0c0c4d22u: goto P_0c0c4d22;
case 0x0c0c4d24u: goto P_0c0c4d24;
case 0x0c0c4d26u: goto P_0c0c4d26;
case 0x0c0c4d28u: goto P_0c0c4d28;
case 0x0c0c4d2au: goto P_0c0c4d2a;
case 0x0c0c4d2cu: goto P_0c0c4d2c;
case 0x0c0c4d2eu: goto P_0c0c4d2e;
case 0x0c0c4d30u: goto P_0c0c4d30;
case 0x0c0c4d32u: goto P_0c0c4d32;
case 0x0c0c4d34u: goto P_0c0c4d34;
case 0x0c0c4d36u: goto P_0c0c4d36;
case 0x0c0c4d38u: goto P_0c0c4d38;
case 0x0c0c4d3au: goto P_0c0c4d3a;
case 0x0c0c4d3cu: goto P_0c0c4d3c;
case 0x0c0c4d3eu: goto P_0c0c4d3e;
case 0x0c0c4d40u: goto P_0c0c4d40;
case 0x0c0c4d42u: goto P_0c0c4d42;
case 0x0c0c4d44u: goto P_0c0c4d44;
case 0x0c0c4d46u: goto P_0c0c4d46;
case 0x0c0c4d48u: goto P_0c0c4d48;
case 0x0c0c4d4au: goto P_0c0c4d4a;
case 0x0c0c4d4cu: goto P_0c0c4d4c;
case 0x0c0c4d4eu: goto P_0c0c4d4e;
case 0x0c0c4d50u: goto P_0c0c4d50;
case 0x0c0c4d52u: goto P_0c0c4d52;
case 0x0c0c4d54u: goto P_0c0c4d54;
case 0x0c0c4d56u: goto P_0c0c4d56;
case 0x0c0c4d58u: goto P_0c0c4d58;
case 0x0c0c4d5au: goto P_0c0c4d5a;
case 0x0c0c4d5cu: goto P_0c0c4d5c;
case 0x0c0c4d5eu: goto P_0c0c4d5e;
case 0x0c0c4d60u: goto P_0c0c4d60;
case 0x0c0c4d62u: goto P_0c0c4d62;
case 0x0c0c4d64u: goto P_0c0c4d64;
case 0x0c0c4d66u: goto P_0c0c4d66;
case 0x0c0c4d68u: goto P_0c0c4d68;
case 0x0c0c4d6au: goto P_0c0c4d6a;
case 0x0c0c4d6cu: goto P_0c0c4d6c;
case 0x0c0c4d6eu: goto P_0c0c4d6e;
case 0x0c0c4d70u: goto P_0c0c4d70;
case 0x0c0c4d72u: goto P_0c0c4d72;
case 0x0c0c4d74u: goto P_0c0c4d74;
case 0x0c0c4d76u: goto P_0c0c4d76;
case 0x0c0c4d78u: goto P_0c0c4d78;
case 0x0c0c4d7au: goto P_0c0c4d7a;
case 0x0c0c4d7cu: goto P_0c0c4d7c;
case 0x0c0c4d7eu: goto P_0c0c4d7e;
case 0x0c0c4d80u: goto P_0c0c4d80;
case 0x0c0c4d82u: goto P_0c0c4d82;
case 0x0c0c4d84u: goto P_0c0c4d84;
case 0x0c0c4d86u: goto P_0c0c4d86;
case 0x0c0c4d88u: goto P_0c0c4d88;
case 0x0c0c4d8au: goto P_0c0c4d8a;
case 0x0c0c4d8cu: goto P_0c0c4d8c;
case 0x0c0c4d8eu: goto P_0c0c4d8e;
case 0x0c0c4d90u: goto P_0c0c4d90;
case 0x0c0c4d92u: goto P_0c0c4d92;
case 0x0c0c4d94u: goto P_0c0c4d94;
case 0x0c0c4d96u: goto P_0c0c4d96;
case 0x0c0c4d98u: goto P_0c0c4d98;
case 0x0c0c4d9au: goto P_0c0c4d9a;
case 0x0c0c4d9cu: goto P_0c0c4d9c;
case 0x0c0c4d9eu: goto P_0c0c4d9e;
case 0x0c0c4da0u: goto P_0c0c4da0;
case 0x0c0c4da2u: goto P_0c0c4da2;
case 0x0c0c4da4u: goto P_0c0c4da4;
case 0x0c0c4da6u: goto P_0c0c4da6;
case 0x0c0c4da8u: goto P_0c0c4da8;
case 0x0c0c4daau: goto P_0c0c4daa;
case 0x0c0c4dacu: goto P_0c0c4dac;
case 0x0c0c4daeu: goto P_0c0c4dae;
case 0x0c0c4db0u: goto P_0c0c4db0;
case 0x0c0c4db2u: goto P_0c0c4db2;
case 0x0c0c4db4u: goto P_0c0c4db4;
case 0x0c0c4db6u: goto P_0c0c4db6;
case 0x0c0c4db8u: goto P_0c0c4db8;
case 0x0c0c4dbau: goto P_0c0c4dba;
case 0x0c0c4dbcu: goto P_0c0c4dbc;
case 0x0c0c4dbeu: goto P_0c0c4dbe;
case 0x0c0c4dc0u: goto P_0c0c4dc0;
case 0x0c0c4dc2u: goto P_0c0c4dc2;
case 0x0c0c4dc4u: goto P_0c0c4dc4;
case 0x0c0c4dc6u: goto P_0c0c4dc6;
case 0x0c0c4dc8u: goto P_0c0c4dc8;
case 0x0c0c4dcau: goto P_0c0c4dca;
case 0x0c0c4dccu: goto P_0c0c4dcc;
case 0x0c0c4dceu: goto P_0c0c4dce;
case 0x0c0c4dd0u: goto P_0c0c4dd0;
case 0x0c0c4dd2u: goto P_0c0c4dd2;
case 0x0c0c4dd4u: goto P_0c0c4dd4;
case 0x0c0c4dd6u: goto P_0c0c4dd6;
case 0x0c0c4dd8u: goto P_0c0c4dd8;
case 0x0c0c4ddau: goto P_0c0c4dda;
case 0x0c0c4ddcu: goto P_0c0c4ddc;
case 0x0c0c4ddeu: goto P_0c0c4dde;
case 0x0c0c4de0u: goto P_0c0c4de0;
case 0x0c0c4de2u: goto P_0c0c4de2;
case 0x0c0c4de4u: goto P_0c0c4de4;
case 0x0c0c4de6u: goto P_0c0c4de6;
case 0x0c0c4de8u: goto P_0c0c4de8;
case 0x0c0c4deau: goto P_0c0c4dea;
case 0x0c0c4decu: goto P_0c0c4dec;
case 0x0c0c4deeu: goto P_0c0c4dee;
case 0x0c0c4df0u: goto P_0c0c4df0;
case 0x0c0c4df2u: goto P_0c0c4df2;
case 0x0c0c4df4u: goto P_0c0c4df4;
case 0x0c0c4df6u: goto P_0c0c4df6;
case 0x0c0c4df8u: goto P_0c0c4df8;
case 0x0c0c4dfau: goto P_0c0c4dfa;
case 0x0c0c4dfcu: goto P_0c0c4dfc;
case 0x0c0c4dfeu: goto P_0c0c4dfe;
case 0x0c0c4e00u: goto P_0c0c4e00;
case 0x0c0c4e02u: goto P_0c0c4e02;
case 0x0c0c4e04u: goto P_0c0c4e04;
case 0x0c0c4e06u: goto P_0c0c4e06;
case 0x0c0c4e08u: goto P_0c0c4e08;
case 0x0c0c4e0au: goto P_0c0c4e0a;
case 0x0c0c4e0cu: goto P_0c0c4e0c;
case 0x0c0c4e0eu: goto P_0c0c4e0e;
case 0x0c0c4e10u: goto P_0c0c4e10;
case 0x0c0c4e12u: goto P_0c0c4e12;
case 0x0c0c4e14u: goto P_0c0c4e14;
case 0x0c0c4e16u: goto P_0c0c4e16;
case 0x0c0c5d86u: goto P_0c0c5d86;
case 0x0c0c5d88u: goto P_0c0c5d88;
case 0x0c0c5d8au: goto P_0c0c5d8a;
case 0x0c0c5d8cu: goto P_0c0c5d8c;
case 0x0c0c5d8eu: goto P_0c0c5d8e;
case 0x0c0c5d90u: goto P_0c0c5d90;
case 0x0c0c5d92u: goto P_0c0c5d92;
case 0x0c0c5d94u: goto P_0c0c5d94;
case 0x0c0c5d96u: goto P_0c0c5d96;
case 0x0c0c5d98u: goto P_0c0c5d98;
case 0x0c0c5d9au: goto P_0c0c5d9a;
case 0x0c0c5d9cu: goto P_0c0c5d9c;
case 0x0c0c5d9eu: goto P_0c0c5d9e;
case 0x0c0c5da0u: goto P_0c0c5da0;
case 0x0c0c5da2u: goto P_0c0c5da2;
case 0x0c0c5da4u: goto P_0c0c5da4;
case 0x0c0c5da6u: goto P_0c0c5da6;
case 0x0c0c5da8u: goto P_0c0c5da8;
case 0x0c0c5daau: goto P_0c0c5daa;
case 0x0c0c5dacu: goto P_0c0c5dac;
case 0x0c0c5daeu: goto P_0c0c5dae;
case 0x0c0c5db0u: goto P_0c0c5db0;
case 0x0c0c5db2u: goto P_0c0c5db2;
case 0x0c0c5db4u: goto P_0c0c5db4;
case 0x0c0c5db6u: goto P_0c0c5db6;
case 0x0c0c5db8u: goto P_0c0c5db8;
case 0x0c0c5dbau: goto P_0c0c5dba;
case 0x0c0c5dbcu: goto P_0c0c5dbc;
case 0x0c0c5dbeu: goto P_0c0c5dbe;
case 0x0c0c5dc0u: goto P_0c0c5dc0;
case 0x0c0c5dc2u: goto P_0c0c5dc2;
case 0x0c0c5dc4u: goto P_0c0c5dc4;
case 0x0c0c5dc6u: goto P_0c0c5dc6;
case 0x0c0c5dc8u: goto P_0c0c5dc8;
case 0x0c0c5dcau: goto P_0c0c5dca;
case 0x0c0c5dccu: goto P_0c0c5dcc;
case 0x0c0c5dceu: goto P_0c0c5dce;
case 0x0c0c5dd0u: goto P_0c0c5dd0;
case 0x0c0c5dd2u: goto P_0c0c5dd2;
case 0x0c0c5dd4u: goto P_0c0c5dd4;
case 0x0c0c5dd6u: goto P_0c0c5dd6;
case 0x0c0c5dd8u: goto P_0c0c5dd8;
case 0x0c0c5ddau: goto P_0c0c5dda;
case 0x0c0c5ddcu: goto P_0c0c5ddc;
case 0x0c0c5ddeu: goto P_0c0c5dde;
case 0x0c0c5de0u: goto P_0c0c5de0;
case 0x0c0c5de2u: goto P_0c0c5de2;
case 0x0c0c5de4u: goto P_0c0c5de4;
case 0x0c0c5de6u: goto P_0c0c5de6;
case 0x0c0c5de8u: goto P_0c0c5de8;
case 0x0c0c5deau: goto P_0c0c5dea;
case 0x0c0c5decu: goto P_0c0c5dec;
case 0x0c0c5deeu: goto P_0c0c5dee;
case 0x0c0c5df0u: goto P_0c0c5df0;
case 0x0c0c5df2u: goto P_0c0c5df2;
case 0x0c0c5df4u: goto P_0c0c5df4;
case 0x0c0c66b8u: goto P_0c0c66b8;
case 0x0c0c66bau: goto P_0c0c66ba;
case 0x0c0c9ce6u: goto P_0c0c9ce6;
case 0x0c0c9ce8u: goto P_0c0c9ce8;
case 0x0c0c9ceau: goto P_0c0c9cea;
case 0x0c0c9cecu: goto P_0c0c9cec;
case 0x0c0c9ceeu: goto P_0c0c9cee;
case 0x0c0c9cf0u: goto P_0c0c9cf0;
case 0x0c0c9cf2u: goto P_0c0c9cf2;
case 0x0c0c9cf4u: goto P_0c0c9cf4;
case 0x0c0c9cf6u: goto P_0c0c9cf6;
case 0x0c0c9cf8u: goto P_0c0c9cf8;
case 0x0c0c9cfau: goto P_0c0c9cfa;
case 0x0c0c9cfcu: goto P_0c0c9cfc;
case 0x0c0c9cfeu: goto P_0c0c9cfe;
case 0x0c0c9d00u: goto P_0c0c9d00;
case 0x0c0c9d02u: goto P_0c0c9d02;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c4d14: /* original 2fe6, guest PC 0x0c0c4d14 */
if(!s->budget--) { s->failed_pc=0x0c0c4d14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4d16;
P_0c0c4d16: /* original 6e53, guest PC 0x0c0c4d16 */
if(!s->budget--) { s->failed_pc=0x0c0c4d16u; return 0; }
r[14]=r[5];
goto P_0c0c4d18;
P_0c0c4d18: /* original e060, guest PC 0x0c0c4d18 */
if(!s->budget--) { s->failed_pc=0x0c0c4d18u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d1a;
P_0c0c4d1a: /* original 2fd6, guest PC 0x0c0c4d1a */
if(!s->budget--) { s->failed_pc=0x0c0c4d1au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4d1c;
P_0c0c4d1c: /* original 06ec, guest PC 0x0c0c4d1c */
if(!s->budget--) { s->failed_pc=0x0c0c4d1cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d1e;
P_0c0c4d1e: /* original d040, guest PC 0x0c0c4d1e */
if(!s->budget--) { s->failed_pc=0x0c0c4d1eu; return 0; }
r[0]=read(ram,0x0c0c4e20u,4);
goto P_0c0c4d20;
P_0c0c4d20: /* original 666c, guest PC 0x0c0c4d20 */
if(!s->budget--) { s->failed_pc=0x0c0c4d20u; return 0; }
r[6]=r[6]&255u;
goto P_0c0c4d22;
P_0c0c4d22: /* original d73e, guest PC 0x0c0c4d22 */
if(!s->budget--) { s->failed_pc=0x0c0c4d22u; return 0; }
r[7]=read(ram,0x0c0c4e1cu,4);
goto P_0c0c4d24;
P_0c0c4d24: /* original 4608, guest PC 0x0c0c4d24 */
if(!s->budget--) { s->failed_pc=0x0c0c4d24u; return 0; }
r[6]<<=2;
goto P_0c0c4d26;
P_0c0c4d26: /* original 066e, guest PC 0x0c0c4d26 */
if(!s->budget--) { s->failed_pc=0x0c0c4d26u; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c0c4d28;
P_0c0c4d28: /* original e052, guest PC 0x0c0c4d28 */
if(!s->budget--) { s->failed_pc=0x0c0c4d28u; return 0; }
r[0]=0x00000052u;
goto P_0c0c4d2a;
P_0c0c4d2a: /* original 054c, guest PC 0x0c0c4d2a */
if(!s->budget--) { s->failed_pc=0x0c0c4d2au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d2c;
P_0c0c4d2c: /* original 4f22, guest PC 0x0c0c4d2c */
if(!s->budget--) { s->failed_pc=0x0c0c4d2cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4d2e;
P_0c0c4d2e: /* original 6053, guest PC 0x0c0c4d2e */
if(!s->budget--) { s->failed_pc=0x0c0c4d2eu; return 0; }
r[0]=r[5];
goto P_0c0c4d30;
P_0c0c4d30: /* original 4001, guest PC 0x0c0c4d30 */
if(!s->budget--) { s->failed_pc=0x0c0c4d30u; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c0c4d32;
P_0c0c4d32: /* original 4000, guest PC 0x0c0c4d32 */
if(!s->budget--) { s->failed_pc=0x0c0c4d32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4d34;
P_0c0c4d34: /* original 006d, guest PC 0x0c0c4d34 */
if(!s->budget--) { s->failed_pc=0x0c0c4d34u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[6]+r[0],2);
goto P_0c0c4d36;
P_0c0c4d36: /* original 88ff, guest PC 0x0c0c4d36 */
if(!s->budget--) { s->failed_pc=0x0c0c4d36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4d38;
P_0c0c4d38: /* original 8d05, guest PC 0x0c0c4d38 */
if(!s->budget--) { s->failed_pc=0x0c0c4d38u; return 0; }
cond=r[17]&1u;
r[13]=r[0];
if(cond) { goto P_0c0c4d46; }
goto P_0c0c4d3c;
P_0c0c4d3a: /* original 6d03, guest PC 0x0c0c4d3a */
if(!s->budget--) { s->failed_pc=0x0c0c4d3au; return 0; }
r[13]=r[0];
goto P_0c0c4d3c;
P_0c0c4d3c: /* original e052, guest PC 0x0c0c4d3c */
if(!s->budget--) { s->failed_pc=0x0c0c4d3cu; return 0; }
r[0]=0x00000052u;
goto P_0c0c4d3e;
P_0c0c4d3e: /* original 7502, guest PC 0x0c0c4d3e */
if(!s->budget--) { s->failed_pc=0x0c0c4d3eu; return 0; }
r[5]+=0x00000002u;
goto P_0c0c4d40;
P_0c0c4d40: /* original 0454, guest PC 0x0c0c4d40 */
if(!s->budget--) { s->failed_pc=0x0c0c4d40u; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c0c4d42;
P_0c0c4d42: /* original a02c, guest PC 0x0c0c4d42 */
if(!s->budget--) { s->failed_pc=0x0c0c4d42u; return 0; }
r[4]=r[13];
goto P_0c0c4d9e;
P_0c0c4d44: /* original 64d3, guest PC 0x0c0c4d44 */
if(!s->budget--) { s->failed_pc=0x0c0c4d44u; return 0; }
r[4]=r[13];
goto P_0c0c4d46;
P_0c0c4d46: /* original e050, guest PC 0x0c0c4d46 */
if(!s->budget--) { s->failed_pc=0x0c0c4d46u; return 0; }
r[0]=0x00000050u;
goto P_0c0c4d48;
P_0c0c4d48: /* original 064c, guest PC 0x0c0c4d48 */
if(!s->budget--) { s->failed_pc=0x0c0c4d48u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d4a;
P_0c0c4d4a: /* original 636c, guest PC 0x0c0c4d4a */
if(!s->budget--) { s->failed_pc=0x0c0c4d4au; return 0; }
r[3]=r[6]&255u;
goto P_0c0c4d4c;
P_0c0c4d4c: /* original 2338, guest PC 0x0c0c4d4c */
if(!s->budget--) { s->failed_pc=0x0c0c4d4cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4d4e;
P_0c0c4d4e: /* original 8b1a, guest PC 0x0c0c4d4e */
if(!s->budget--) { s->failed_pc=0x0c0c4d4eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4d86; }
goto P_0c0c4d50;
P_0c0c4d50: /* original e060, guest PC 0x0c0c4d50 */
if(!s->budget--) { s->failed_pc=0x0c0c4d50u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d52;
P_0c0c4d52: /* original 05ec, guest PC 0x0c0c4d52 */
if(!s->budget--) { s->failed_pc=0x0c0c4d52u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d54;
P_0c0c4d54: /* original 605c, guest PC 0x0c0c4d54 */
if(!s->budget--) { s->failed_pc=0x0c0c4d54u; return 0; }
r[0]=r[5]&255u;
goto P_0c0c4d56;
P_0c0c4d56: /* original 8803, guest PC 0x0c0c4d56 */
if(!s->budget--) { s->failed_pc=0x0c0c4d56u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c4d58;
P_0c0c4d58: /* original 8d16, guest PC 0x0c0c4d58 */
if(!s->budget--) { s->failed_pc=0x0c0c4d58u; return 0; }
cond=r[17]&1u;
r[5]=r[0];
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d5c;
P_0c0c4d5a: /* original 6503, guest PC 0x0c0c4d5a */
if(!s->budget--) { s->failed_pc=0x0c0c4d5au; return 0; }
r[5]=r[0];
goto P_0c0c4d5c;
P_0c0c4d5c: /* original 6053, guest PC 0x0c0c4d5c */
if(!s->budget--) { s->failed_pc=0x0c0c4d5cu; return 0; }
r[0]=r[5];
goto P_0c0c4d5e;
P_0c0c4d5e: /* original 8810, guest PC 0x0c0c4d5e */
if(!s->budget--) { s->failed_pc=0x0c0c4d5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c0c4d60;
P_0c0c4d60: /* original 8912, guest PC 0x0c0c4d60 */
if(!s->budget--) { s->failed_pc=0x0c0c4d60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d62;
P_0c0c4d62: /* original 6053, guest PC 0x0c0c4d62 */
if(!s->budget--) { s->failed_pc=0x0c0c4d62u; return 0; }
r[0]=r[5];
goto P_0c0c4d64;
P_0c0c4d64: /* original 8807, guest PC 0x0c0c4d64 */
if(!s->budget--) { s->failed_pc=0x0c0c4d64u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c4d66;
P_0c0c4d66: /* original 890f, guest PC 0x0c0c4d66 */
if(!s->budget--) { s->failed_pc=0x0c0c4d66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d68;
P_0c0c4d68: /* original 6053, guest PC 0x0c0c4d68 */
if(!s->budget--) { s->failed_pc=0x0c0c4d68u; return 0; }
r[0]=r[5];
goto P_0c0c4d6a;
P_0c0c4d6a: /* original 8814, guest PC 0x0c0c4d6a */
if(!s->budget--) { s->failed_pc=0x0c0c4d6au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c0c4d6c;
P_0c0c4d6c: /* original 890c, guest PC 0x0c0c4d6c */
if(!s->budget--) { s->failed_pc=0x0c0c4d6cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4d88; }
goto P_0c0c4d6e;
P_0c0c4d6e: /* original e057, guest PC 0x0c0c4d6e */
if(!s->budget--) { s->failed_pc=0x0c0c4d6eu; return 0; }
r[0]=0x00000057u;
goto P_0c0c4d70;
P_0c0c4d70: /* original 024c, guest PC 0x0c0c4d70 */
if(!s->budget--) { s->failed_pc=0x0c0c4d70u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c4d72;
P_0c0c4d72: /* original 2228, guest PC 0x0c0c4d72 */
if(!s->budget--) { s->failed_pc=0x0c0c4d72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c4d74;
P_0c0c4d74: /* original 8f07, guest PC 0x0c0c4d74 */
if(!s->budget--) { s->failed_pc=0x0c0c4d74u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c0c4d86; }
goto P_0c0c4d78;
P_0c0c4d76: /* original e601, guest PC 0x0c0c4d76 */
if(!s->budget--) { s->failed_pc=0x0c0c4d76u; return 0; }
r[6]=0x00000001u;
goto P_0c0c4d78;
P_0c0c4d78: /* original 904e, guest PC 0x0c0c4d78 */
if(!s->budget--) { s->failed_pc=0x0c0c4d78u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4e18u,2);
goto P_0c0c4d7a;
P_0c0c4d7a: /* original 655b, guest PC 0x0c0c4d7a */
if(!s->budget--) { s->failed_pc=0x0c0c4d7au; return 0; }
r[5]=0u-r[5];
goto P_0c0c4d7c;
P_0c0c4d7c: /* original d329, guest PC 0x0c0c4d7c */
if(!s->budget--) { s->failed_pc=0x0c0c4d7cu; return 0; }
r[3]=read(ram,0x0c0c4e24u,4);
goto P_0c0c4d7e;
P_0c0c4d7e: /* original 0d7e, guest PC 0x0c0c4d7e */
if(!s->budget--) { s->failed_pc=0x0c0c4d7eu; return 0; }
r[13]=read(ram,r[7]+r[0],4);
goto P_0c0c4d80;
P_0c0c4d80: /* original 435d, guest PC 0x0c0c4d80 */
if(!s->budget--) { s->failed_pc=0x0c0c4d80u; return 0; }
r[3]=(r[5]&0x80000000u)?((r[5]&31u)?r[3]>>((-r[5])&31u):0):r[3]<<(r[5]&31u);
goto P_0c0c4d82;
P_0c0c4d82: /* original 2d3b, guest PC 0x0c0c4d82 */
if(!s->budget--) { s->failed_pc=0x0c0c4d82u; return 0; }
r[13]|=r[3];
goto P_0c0c4d84;
P_0c0c4d84: /* original 07d6, guest PC 0x0c0c4d84 */
if(!s->budget--) { s->failed_pc=0x0c0c4d84u; return 0; }
write(ram,r[7]+r[0],r[13],4);
goto P_0c0c4d86;
P_0c0c4d86: /* original 76ff, guest PC 0x0c0c4d86 */
if(!s->budget--) { s->failed_pc=0x0c0c4d86u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0c4d88;
P_0c0c4d88: /* original 9047, guest PC 0x0c0c4d88 */
if(!s->budget--) { s->failed_pc=0x0c0c4d88u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c4e1au,2);
goto P_0c0c4d8a;
P_0c0c4d8a: /* original e303, guest PC 0x0c0c4d8a */
if(!s->budget--) { s->failed_pc=0x0c0c4d8au; return 0; }
r[3]=0x00000003u;
goto P_0c0c4d8c;
P_0c0c4d8c: /* original 0e34, guest PC 0x0c0c4d8c */
if(!s->budget--) { s->failed_pc=0x0c0c4d8cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4d8e;
P_0c0c4d8e: /* original e050, guest PC 0x0c0c4d8e */
if(!s->budget--) { s->failed_pc=0x0c0c4d8eu; return 0; }
r[0]=0x00000050u;
goto P_0c0c4d90;
P_0c0c4d90: /* original 0464, guest PC 0x0c0c4d90 */
if(!s->budget--) { s->failed_pc=0x0c0c4d90u; return 0; }
write(ram,r[4]+r[0],r[6],1);
goto P_0c0c4d92;
P_0c0c4d92: /* original e060, guest PC 0x0c0c4d92 */
if(!s->budget--) { s->failed_pc=0x0c0c4d92u; return 0; }
r[0]=0x00000060u;
goto P_0c0c4d94;
P_0c0c4d94: /* original 04ec, guest PC 0x0c0c4d94 */
if(!s->budget--) { s->failed_pc=0x0c0c4d94u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4d96;
P_0c0c4d96: /* original d024, guest PC 0x0c0c4d96 */
if(!s->budget--) { s->failed_pc=0x0c0c4d96u; return 0; }
r[0]=read(ram,0x0c0c4e28u,4);
goto P_0c0c4d98;
P_0c0c4d98: /* original 644c, guest PC 0x0c0c4d98 */
if(!s->budget--) { s->failed_pc=0x0c0c4d98u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c4d9a;
P_0c0c4d9a: /* original 4400, guest PC 0x0c0c4d9a */
if(!s->budget--) { s->failed_pc=0x0c0c4d9au; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0c4d9c;
P_0c0c4d9c: /* original 044d, guest PC 0x0c0c4d9c */
if(!s->budget--) { s->failed_pc=0x0c0c4d9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c4d9e;
P_0c0c4d9e: /* original d323, guest PC 0x0c0c4d9e */
if(!s->budget--) { s->failed_pc=0x0c0c4d9eu; return 0; }
r[3]=read(ram,0x0c0c4e2cu,4);
goto P_0c0c4da0;
P_0c0c4da0: /* original 430b, guest PC 0x0c0c4da0 */
if(!s->budget--) { s->failed_pc=0x0c0c4da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4da4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4da4u) { target=s->pc; goto dispatch; }
goto P_0c0c4da4;
P_0c0c4da2: /* original 0009, guest PC 0x0c0c4da2 */
if(!s->budget--) { s->failed_pc=0x0c0c4da2u; return 0; }
goto P_0c0c4da4;
P_0c0c4da4: /* original 4f26, guest PC 0x0c0c4da4 */
if(!s->budget--) { s->failed_pc=0x0c0c4da4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4da6;
P_0c0c4da6: /* original 6df6, guest PC 0x0c0c4da6 */
if(!s->budget--) { s->failed_pc=0x0c0c4da6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4da8;
P_0c0c4da8: /* original 000b, guest PC 0x0c0c4da8 */
if(!s->budget--) { s->failed_pc=0x0c0c4da8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c4daa: /* original 6ef6, guest PC 0x0c0c4daa */
if(!s->budget--) { s->failed_pc=0x0c0c4daau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c4dac;
P_0c0c4dac: /* original 2fe6, guest PC 0x0c0c4dac */
if(!s->budget--) { s->failed_pc=0x0c0c4dacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4dae;
P_0c0c4dae: /* original e060, guest PC 0x0c0c4dae */
if(!s->budget--) { s->failed_pc=0x0c0c4daeu; return 0; }
r[0]=0x00000060u;
goto P_0c0c4db0;
P_0c0c4db0: /* original 2fd6, guest PC 0x0c0c4db0 */
if(!s->budget--) { s->failed_pc=0x0c0c4db0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c4db2;
P_0c0c4db2: /* original 6e43, guest PC 0x0c0c4db2 */
if(!s->budget--) { s->failed_pc=0x0c0c4db2u; return 0; }
r[14]=r[4];
goto P_0c0c4db4;
P_0c0c4db4: /* original 0d5c, guest PC 0x0c0c4db4 */
if(!s->budget--) { s->failed_pc=0x0c0c4db4u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0c4db6;
P_0c0c4db6: /* original d01a, guest PC 0x0c0c4db6 */
if(!s->budget--) { s->failed_pc=0x0c0c4db6u; return 0; }
r[0]=read(ram,0x0c0c4e20u,4);
goto P_0c0c4db8;
P_0c0c4db8: /* original 6ddc, guest PC 0x0c0c4db8 */
if(!s->budget--) { s->failed_pc=0x0c0c4db8u; return 0; }
r[13]=r[13]&255u;
goto P_0c0c4dba;
P_0c0c4dba: /* original 4d08, guest PC 0x0c0c4dba */
if(!s->budget--) { s->failed_pc=0x0c0c4dbau; return 0; }
r[13]<<=2;
goto P_0c0c4dbc;
P_0c0c4dbc: /* original 0dde, guest PC 0x0c0c4dbc */
if(!s->budget--) { s->failed_pc=0x0c0c4dbcu; return 0; }
r[13]=read(ram,r[13]+r[0],4);
goto P_0c0c4dbe;
P_0c0c4dbe: /* original 60e2, guest PC 0x0c0c4dbe */
if(!s->budget--) { s->failed_pc=0x0c0c4dbeu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c0c4dc0;
P_0c0c4dc0: /* original 4f22, guest PC 0x0c0c4dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4dc2;
P_0c0c4dc2: /* original c80a, guest PC 0x0c0c4dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&10u)==0)!=0);
goto P_0c0c4dc4;
P_0c0c4dc4: /* original 8b1f, guest PC 0x0c0c4dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e06; }
goto P_0c0c4dc6;
P_0c0c4dc6: /* original e051, guest PC 0x0c0c4dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc6u; return 0; }
r[0]=0x00000051u;
goto P_0c0c4dc8;
P_0c0c4dc8: /* original 04ec, guest PC 0x0c0c4dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dca;
P_0c0c4dca: /* original 634c, guest PC 0x0c0c4dca */
if(!s->budget--) { s->failed_pc=0x0c0c4dcau; return 0; }
r[3]=r[4]&255u;
goto P_0c0c4dcc;
P_0c0c4dcc: /* original 2338, guest PC 0x0c0c4dcc */
if(!s->budget--) { s->failed_pc=0x0c0c4dccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4dce;
P_0c0c4dce: /* original 8b1a, guest PC 0x0c0c4dce */
if(!s->budget--) { s->failed_pc=0x0c0c4dceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e06; }
goto P_0c0c4dd0;
P_0c0c4dd0: /* original e052, guest PC 0x0c0c4dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd0u; return 0; }
r[0]=0x00000052u;
goto P_0c0c4dd2;
P_0c0c4dd2: /* original 03ec, guest PC 0x0c0c4dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dd4;
P_0c0c4dd4: /* original 04ec, guest PC 0x0c0c4dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dd6;
P_0c0c4dd6: /* original 7302, guest PC 0x0c0c4dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd6u; return 0; }
r[3]+=0x00000002u;
goto P_0c0c4dd8;
P_0c0c4dd8: /* original 4401, guest PC 0x0c0c4dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0c4dda;
P_0c0c4dda: /* original 0e34, guest PC 0x0c0c4dda */
if(!s->budget--) { s->failed_pc=0x0c0c4ddau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4ddc;
P_0c0c4ddc: /* original 6043, guest PC 0x0c0c4ddc */
if(!s->budget--) { s->failed_pc=0x0c0c4ddcu; return 0; }
r[0]=r[4];
goto P_0c0c4dde;
P_0c0c4dde: /* original 4000, guest PC 0x0c0c4dde */
if(!s->budget--) { s->failed_pc=0x0c0c4ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4de0;
P_0c0c4de0: /* original 03dd, guest PC 0x0c0c4de0 */
if(!s->budget--) { s->failed_pc=0x0c0c4de0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0c4de2;
P_0c0c4de2: /* original 643f, guest PC 0x0c0c4de2 */
if(!s->budget--) { s->failed_pc=0x0c0c4de2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0c4de4;
P_0c0c4de4: /* original 6043, guest PC 0x0c0c4de4 */
if(!s->budget--) { s->failed_pc=0x0c0c4de4u; return 0; }
r[0]=r[4];
goto P_0c0c4de6;
P_0c0c4de6: /* original 88ff, guest PC 0x0c0c4de6 */
if(!s->budget--) { s->failed_pc=0x0c0c4de6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4de8;
P_0c0c4de8: /* original 8b11, guest PC 0x0c0c4de8 */
if(!s->budget--) { s->failed_pc=0x0c0c4de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e0e; }
goto P_0c0c4dea;
P_0c0c4dea: /* original d311, guest PC 0x0c0c4dea */
if(!s->budget--) { s->failed_pc=0x0c0c4deau; return 0; }
r[3]=read(ram,0x0c0c4e30u,4);
goto P_0c0c4dec;
P_0c0c4dec: /* original e052, guest PC 0x0c0c4dec */
if(!s->budget--) { s->failed_pc=0x0c0c4decu; return 0; }
r[0]=0x00000052u;
goto P_0c0c4dee;
P_0c0c4dee: /* original e200, guest PC 0x0c0c4dee */
if(!s->budget--) { s->failed_pc=0x0c0c4deeu; return 0; }
r[2]=0x00000000u;
goto P_0c0c4df0;
P_0c0c4df0: /* original 430b, guest PC 0x0c0c4df0 */
if(!s->budget--) { s->failed_pc=0x0c0c4df0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4df4u;
write(ram,r[14]+r[0],r[2],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c4df4u) { target=s->pc; goto dispatch; }
goto P_0c0c4df4;
P_0c0c4df2: /* original 0e24, guest PC 0x0c0c4df2 */
if(!s->budget--) { s->failed_pc=0x0c0c4df2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c4df4;
P_0c0c4df4: /* original e47f, guest PC 0x0c0c4df4 */
if(!s->budget--) { s->failed_pc=0x0c0c4df4u; return 0; }
r[4]=0x0000007fu;
goto P_0c0c4df6;
P_0c0c4df6: /* original 6503, guest PC 0x0c0c4df6 */
if(!s->budget--) { s->failed_pc=0x0c0c4df6u; return 0; }
r[5]=r[0];
goto P_0c0c4df8;
P_0c0c4df8: /* original 2459, guest PC 0x0c0c4df8 */
if(!s->budget--) { s->failed_pc=0x0c0c4df8u; return 0; }
r[4]&=r[5];
goto P_0c0c4dfa;
P_0c0c4dfa: /* original e320, guest PC 0x0c0c4dfa */
if(!s->budget--) { s->failed_pc=0x0c0c4dfau; return 0; }
r[3]=0x00000020u;
goto P_0c0c4dfc;
P_0c0c4dfc: /* original 624c, guest PC 0x0c0c4dfc */
if(!s->budget--) { s->failed_pc=0x0c0c4dfcu; return 0; }
r[2]=r[4]&255u;
goto P_0c0c4dfe;
P_0c0c4dfe: /* original 3237, guest PC 0x0c0c4dfe */
if(!s->budget--) { s->failed_pc=0x0c0c4dfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0c4e00;
P_0c0c4e00: /* original 8901, guest PC 0x0c0c4e00 */
if(!s->budget--) { s->failed_pc=0x0c0c4e00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4e06; }
goto P_0c0c4e02;
P_0c0c4e02: /* original 6453, guest PC 0x0c0c4e02 */
if(!s->budget--) { s->failed_pc=0x0c0c4e02u; return 0; }
r[4]=r[5];
goto P_0c0c4e04;
P_0c0c4e04: /* original 7420, guest PC 0x0c0c4e04 */
if(!s->budget--) { s->failed_pc=0x0c0c4e04u; return 0; }
r[4]+=0x00000020u;
goto P_0c0c4e06;
P_0c0c4e06: /* original e051, guest PC 0x0c0c4e06 */
if(!s->budget--) { s->failed_pc=0x0c0c4e06u; return 0; }
r[0]=0x00000051u;
goto P_0c0c4e08;
P_0c0c4e08: /* original 74ff, guest PC 0x0c0c4e08 */
if(!s->budget--) { s->failed_pc=0x0c0c4e08u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c4e0a;
P_0c0c4e0a: /* original 0e44, guest PC 0x0c0c4e0a */
if(!s->budget--) { s->failed_pc=0x0c0c4e0au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c4e0c;
P_0c0c4e0c: /* original 64d1, guest PC 0x0c0c4e0c */
if(!s->budget--) { s->failed_pc=0x0c0c4e0cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c0c4e0e;
P_0c0c4e0e: /* original 4f26, guest PC 0x0c0c4e0e */
if(!s->budget--) { s->failed_pc=0x0c0c4e0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e10;
P_0c0c4e10: /* original d306, guest PC 0x0c0c4e10 */
if(!s->budget--) { s->failed_pc=0x0c0c4e10u; return 0; }
r[3]=read(ram,0x0c0c4e2cu,4);
goto P_0c0c4e12;
P_0c0c4e12: /* original 6df6, guest PC 0x0c0c4e12 */
if(!s->budget--) { s->failed_pc=0x0c0c4e12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4e14;
P_0c0c4e14: /* original 432b, guest PC 0x0c0c4e14 */
if(!s->budget--) { s->failed_pc=0x0c0c4e14u; return 0; }
target=r[3];
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
P_0c0c4e16: /* original 6ef6, guest PC 0x0c0c4e16 */
if(!s->budget--) { s->failed_pc=0x0c0c4e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c4e18u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c4e18u; return 0; } return 1;
P_0c0c5d86: /* original 4f22, guest PC 0x0c0c5d86 */
if(!s->budget--) { s->failed_pc=0x0c0c5d86u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5d88;
P_0c0c5d88: /* original 7ff8, guest PC 0x0c0c5d88 */
if(!s->budget--) { s->failed_pc=0x0c0c5d88u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0c5d8a;
P_0c0c5d8a: /* original 2f42, guest PC 0x0c0c5d8a */
if(!s->budget--) { s->failed_pc=0x0c0c5d8au; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0c5d8c;
P_0c0c5d8c: /* original d421, guest PC 0x0c0c5d8c */
if(!s->budget--) { s->failed_pc=0x0c0c5d8cu; return 0; }
r[4]=read(ram,0x0c0c5e14u,4);
goto P_0c0c5d8e;
P_0c0c5d8e: /* original d322, guest PC 0x0c0c5d8e */
if(!s->budget--) { s->failed_pc=0x0c0c5d8eu; return 0; }
r[3]=read(ram,0x0c0c5e18u,4);
goto P_0c0c5d90;
P_0c0c5d90: /* original 1f31, guest PC 0x0c0c5d90 */
if(!s->budget--) { s->failed_pc=0x0c0c5d90u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0c5d92;
P_0c0c5d92: /* original 8448, guest PC 0x0c0c5d92 */
if(!s->budget--) { s->failed_pc=0x0c0c5d92u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+8,1);
goto P_0c0c5d94;
P_0c0c5d94: /* original 600c, guest PC 0x0c0c5d94 */
if(!s->budget--) { s->failed_pc=0x0c0c5d94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c5d96;
P_0c0c5d96: /* original 8803, guest PC 0x0c0c5d96 */
if(!s->budget--) { s->failed_pc=0x0c0c5d96u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c5d98;
P_0c0c5d98: /* original 8f07, guest PC 0x0c0c5d98 */
if(!s->budget--) { s->failed_pc=0x0c0c5d98u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c0c5daa; }
goto P_0c0c5d9c;
P_0c0c5d9a: /* original 6403, guest PC 0x0c0c5d9a */
if(!s->budget--) { s->failed_pc=0x0c0c5d9au; return 0; }
r[4]=r[0];
goto P_0c0c5d9c;
P_0c0c5d9c: /* original d31f, guest PC 0x0c0c5d9c */
if(!s->budget--) { s->failed_pc=0x0c0c5d9cu; return 0; }
r[3]=read(ram,0x0c0c5e1cu,4);
goto P_0c0c5d9e;
P_0c0c5d9e: /* original 54f1, guest PC 0x0c0c5d9e */
if(!s->budget--) { s->failed_pc=0x0c0c5d9eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c5da0;
P_0c0c5da0: /* original 430b, guest PC 0x0c0c5da0 */
if(!s->budget--) { s->failed_pc=0x0c0c5da0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5da4u;
r[4]+=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5da4u) { target=s->pc; goto dispatch; }
goto P_0c0c5da4;
P_0c0c5da2: /* original 7403, guest PC 0x0c0c5da2 */
if(!s->budget--) { s->failed_pc=0x0c0c5da2u; return 0; }
r[4]+=0x00000003u;
goto P_0c0c5da4;
P_0c0c5da4: /* original 640c, guest PC 0x0c0c5da4 */
if(!s->budget--) { s->failed_pc=0x0c0c5da4u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c5da6;
P_0c0c5da6: /* original 2448, guest PC 0x0c0c5da6 */
if(!s->budget--) { s->failed_pc=0x0c0c5da6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c5da8;
P_0c0c5da8: /* original 8b03, guest PC 0x0c0c5da8 */
if(!s->budget--) { s->failed_pc=0x0c0c5da8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5db2; }
goto P_0c0c5daa;
P_0c0c5daa: /* original 64f2, guest PC 0x0c0c5daa */
if(!s->budget--) { s->failed_pc=0x0c0c5daau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c5dac;
P_0c0c5dac: /* original 7f08, guest PC 0x0c0c5dac */
if(!s->budget--) { s->failed_pc=0x0c0c5dacu; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5dae;
P_0c0c5dae: /* original a004, guest PC 0x0c0c5dae */
if(!s->budget--) { s->failed_pc=0x0c0c5daeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5dba;
P_0c0c5db0: /* original 4f26, guest PC 0x0c0c5db0 */
if(!s->budget--) { s->failed_pc=0x0c0c5db0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db2;
P_0c0c5db2: /* original 7f08, guest PC 0x0c0c5db2 */
if(!s->budget--) { s->failed_pc=0x0c0c5db2u; return 0; }
r[15]+=0x00000008u;
goto P_0c0c5db4;
P_0c0c5db4: /* original 4f26, guest PC 0x0c0c5db4 */
if(!s->budget--) { s->failed_pc=0x0c0c5db4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5db6;
P_0c0c5db6: /* original 000b, guest PC 0x0c0c5db6 */
if(!s->budget--) { s->failed_pc=0x0c0c5db6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0c5db8: /* original 0009, guest PC 0x0c0c5db8 */
if(!s->budget--) { s->failed_pc=0x0c0c5db8u; return 0; }
goto P_0c0c5dba;
P_0c0c5dba: /* original 2fe6, guest PC 0x0c0c5dba */
if(!s->budget--) { s->failed_pc=0x0c0c5dbau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c5dbc;
P_0c0c5dbc: /* original 4411, guest PC 0x0c0c5dbc */
if(!s->budget--) { s->failed_pc=0x0c0c5dbcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c5dbe;
P_0c0c5dbe: /* original 4f22, guest PC 0x0c0c5dbe */
if(!s->budget--) { s->failed_pc=0x0c0c5dbeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c5dc0;
P_0c0c5dc0: /* original d517, guest PC 0x0c0c5dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc0u; return 0; }
r[5]=read(ram,0x0c0c5e20u,4);
goto P_0c0c5dc2;
P_0c0c5dc2: /* original 8b15, guest PC 0x0c0c5dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dc4;
P_0c0c5dc4: /* original 921c, guest PC 0x0c0c5dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c5e00u,2);
goto P_0c0c5dc6;
P_0c0c5dc6: /* original 3423, guest PC 0x0c0c5dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c5dc8;
P_0c0c5dc8: /* original 8912, guest PC 0x0c0c5dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5dca;
P_0c0c5dca: /* original d016, guest PC 0x0c0c5dca */
if(!s->budget--) { s->failed_pc=0x0c0c5dcau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dcc;
P_0c0c5dcc: /* original 4408, guest PC 0x0c0c5dcc */
if(!s->budget--) { s->failed_pc=0x0c0c5dccu; return 0; }
r[4]<<=2;
goto P_0c0c5dce;
P_0c0c5dce: /* original 6e43, guest PC 0x0c0c5dce */
if(!s->budget--) { s->failed_pc=0x0c0c5dceu; return 0; }
r[14]=r[4];
goto P_0c0c5dd0;
P_0c0c5dd0: /* original 03ee, guest PC 0x0c0c5dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0c5dd2;
P_0c0c5dd2: /* original 4311, guest PC 0x0c0c5dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=0)!=0);
goto P_0c0c5dd4;
P_0c0c5dd4: /* original 8b0c, guest PC 0x0c0c5dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c5df0; }
goto P_0c0c5dd6;
P_0c0c5dd6: /* original d414, guest PC 0x0c0c5dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd6u; return 0; }
r[4]=read(ram,0x0c0c5e28u,4);
goto P_0c0c5dd8;
P_0c0c5dd8: /* original 60e3, guest PC 0x0c0c5dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c5dd8u; return 0; }
r[0]=r[14];
goto P_0c0c5dda;
P_0c0c5dda: /* original 6252, guest PC 0x0c0c5dda */
if(!s->budget--) { s->failed_pc=0x0c0c5ddau; return 0; }
tmp=read(ram,r[5],4);
r[2]=tmp;
goto P_0c0c5ddc;
P_0c0c5ddc: /* original 034e, guest PC 0x0c0c5ddc */
if(!s->budget--) { s->failed_pc=0x0c0c5ddcu; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c5dde;
P_0c0c5dde: /* original 3320, guest PC 0x0c0c5dde */
if(!s->budget--) { s->failed_pc=0x0c0c5ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0c5de0;
P_0c0c5de0: /* original 8906, guest PC 0x0c0c5de0 */
if(!s->budget--) { s->failed_pc=0x0c0c5de0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c5df0; }
goto P_0c0c5de2;
P_0c0c5de2: /* original 6352, guest PC 0x0c0c5de2 */
if(!s->budget--) { s->failed_pc=0x0c0c5de2u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c0c5de4;
P_0c0c5de4: /* original 60e3, guest PC 0x0c0c5de4 */
if(!s->budget--) { s->failed_pc=0x0c0c5de4u; return 0; }
r[0]=r[14];
goto P_0c0c5de6;
P_0c0c5de6: /* original 0436, guest PC 0x0c0c5de6 */
if(!s->budget--) { s->failed_pc=0x0c0c5de6u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0c5de8;
P_0c0c5de8: /* original d310, guest PC 0x0c0c5de8 */
if(!s->budget--) { s->failed_pc=0x0c0c5de8u; return 0; }
r[3]=read(ram,0x0c0c5e2cu,4);
goto P_0c0c5dea;
P_0c0c5dea: /* original d00e, guest PC 0x0c0c5dea */
if(!s->budget--) { s->failed_pc=0x0c0c5deau; return 0; }
r[0]=read(ram,0x0c0c5e24u,4);
goto P_0c0c5dec;
P_0c0c5dec: /* original 430b, guest PC 0x0c0c5dec */
if(!s->budget--) { s->failed_pc=0x0c0c5decu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c5df0u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c5df0u) { target=s->pc; goto dispatch; }
goto P_0c0c5df0;
P_0c0c5dee: /* original 04ee, guest PC 0x0c0c5dee */
if(!s->budget--) { s->failed_pc=0x0c0c5deeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0c5df0;
P_0c0c5df0: /* original 4f26, guest PC 0x0c0c5df0 */
if(!s->budget--) { s->failed_pc=0x0c0c5df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c5df2;
P_0c0c5df2: /* original 000b, guest PC 0x0c0c5df2 */
if(!s->budget--) { s->failed_pc=0x0c0c5df2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c5df4: /* original 6ef6, guest PC 0x0c0c5df4 */
if(!s->budget--) { s->failed_pc=0x0c0c5df4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c5df6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5df6u; return 0; } return 1;
P_0c0c66b8: /* original 000b, guest PC 0x0c0c66b8 */
if(!s->budget--) { s->failed_pc=0x0c0c66b8u; return 0; }
target=r[16];
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c66ba: /* original 6040, guest PC 0x0c0c66ba */
if(!s->budget--) { s->failed_pc=0x0c0c66bau; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
if(!vf3_matrix_family(0x0c0c66bcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66bcu; return 0; } return 1;
P_0c0c9ce6: /* original 901d, guest PC 0x0c0c9ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d24u,2);
goto P_0c0c9ce8;
P_0c0c9ce8: /* original d412, guest PC 0x0c0c9ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce8u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cea;
P_0c0c9cea: /* original d316, guest PC 0x0c0c9cea */
if(!s->budget--) { s->failed_pc=0x0c0c9ceau; return 0; }
r[3]=read(ram,0x0c0c9d44u,4);
goto P_0c0c9cec;
P_0c0c9cec: /* original 054e, guest PC 0x0c0c9cec */
if(!s->budget--) { s->failed_pc=0x0c0c9cecu; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0c9cee;
P_0c0c9cee: /* original 4f12, guest PC 0x0c0c9cee */
if(!s->budget--) { s->failed_pc=0x0c0c9ceeu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cf0;
P_0c0c9cf0: /* original 0537, guest PC 0x0c0c9cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf0u; return 0; }
r[19]=r[5]*r[3];
goto P_0c0c9cf2;
P_0c0c9cf2: /* original 051a, guest PC 0x0c0c9cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf2u; return 0; }
r[5]=r[19];
goto P_0c0c9cf4;
P_0c0c9cf4: /* original 7501, guest PC 0x0c0c9cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf4u; return 0; }
r[5]+=0x00000001u;
goto P_0c0c9cf6;
P_0c0c9cf6: /* original 0456, guest PC 0x0c0c9cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf6u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cf8;
P_0c0c9cf8: /* original 4529, guest PC 0x0c0c9cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cf8u; return 0; }
r[5]>>=16;
goto P_0c0c9cfa;
P_0c0c9cfa: /* original 9412, guest PC 0x0c0c9cfa */
if(!s->budget--) { s->failed_pc=0x0c0c9cfau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cfc;
P_0c0c9cfc: /* original 2459, guest PC 0x0c0c9cfc */
if(!s->budget--) { s->failed_pc=0x0c0c9cfcu; return 0; }
r[4]&=r[5];
goto P_0c0c9cfe;
P_0c0c9cfe: /* original 6043, guest PC 0x0c0c9cfe */
if(!s->budget--) { s->failed_pc=0x0c0c9cfeu; return 0; }
r[0]=r[4];
goto P_0c0c9d00;
P_0c0c9d00: /* original 000b, guest PC 0x0c0c9d00 */
if(!s->budget--) { s->failed_pc=0x0c0c9d00u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9d02: /* original 4f16, guest PC 0x0c0c9d02 */
if(!s->budget--) { s->failed_pc=0x0c0c9d02u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c9d04u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9d04u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
