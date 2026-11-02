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
int vf3_away_batch25_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a2c36u: goto P_0c0a2c36;
case 0x0c0a2c38u: goto P_0c0a2c38;
case 0x0c0a2c3au: goto P_0c0a2c3a;
case 0x0c0a2c3cu: goto P_0c0a2c3c;
case 0x0c0a2c3eu: goto P_0c0a2c3e;
case 0x0c0a2c40u: goto P_0c0a2c40;
case 0x0c0a2c42u: goto P_0c0a2c42;
case 0x0c0a2c44u: goto P_0c0a2c44;
case 0x0c0a2c46u: goto P_0c0a2c46;
case 0x0c0a2c48u: goto P_0c0a2c48;
case 0x0c0a2c4au: goto P_0c0a2c4a;
case 0x0c0a2c4cu: goto P_0c0a2c4c;
case 0x0c0a2c4eu: goto P_0c0a2c4e;
case 0x0c0a2c50u: goto P_0c0a2c50;
case 0x0c0a2c52u: goto P_0c0a2c52;
case 0x0c0a2c54u: goto P_0c0a2c54;
case 0x0c0a2c56u: goto P_0c0a2c56;
case 0x0c0a2c58u: goto P_0c0a2c58;
case 0x0c0a2c5au: goto P_0c0a2c5a;
case 0x0c0a2c5cu: goto P_0c0a2c5c;
case 0x0c0a2c5eu: goto P_0c0a2c5e;
case 0x0c0a2c60u: goto P_0c0a2c60;
case 0x0c0a2c62u: goto P_0c0a2c62;
case 0x0c0a2c64u: goto P_0c0a2c64;
case 0x0c0a2c66u: goto P_0c0a2c66;
case 0x0c0a2c68u: goto P_0c0a2c68;
case 0x0c0a2c6au: goto P_0c0a2c6a;
case 0x0c0a2c6cu: goto P_0c0a2c6c;
case 0x0c0a2c6eu: goto P_0c0a2c6e;
case 0x0c0a2c70u: goto P_0c0a2c70;
case 0x0c0a2c72u: goto P_0c0a2c72;
case 0x0c0a2c74u: goto P_0c0a2c74;
case 0x0c0a2c76u: goto P_0c0a2c76;
case 0x0c0a2c78u: goto P_0c0a2c78;
case 0x0c0a2c7au: goto P_0c0a2c7a;
case 0x0c0a2c7cu: goto P_0c0a2c7c;
case 0x0c0a2c7eu: goto P_0c0a2c7e;
case 0x0c0a2c80u: goto P_0c0a2c80;
case 0x0c0a2c82u: goto P_0c0a2c82;
case 0x0c0a2c84u: goto P_0c0a2c84;
case 0x0c0a2c86u: goto P_0c0a2c86;
case 0x0c0a2c88u: goto P_0c0a2c88;
case 0x0c0a2c8au: goto P_0c0a2c8a;
case 0x0c0a2c8cu: goto P_0c0a2c8c;
case 0x0c0a2c8eu: goto P_0c0a2c8e;
case 0x0c0a2c90u: goto P_0c0a2c90;
case 0x0c0a2c92u: goto P_0c0a2c92;
case 0x0c0a2c94u: goto P_0c0a2c94;
case 0x0c0a2c96u: goto P_0c0a2c96;
case 0x0c0a2c98u: goto P_0c0a2c98;
case 0x0c0a2c9au: goto P_0c0a2c9a;
case 0x0c0a2c9cu: goto P_0c0a2c9c;
case 0x0c0a2cb8u: goto P_0c0a2cb8;
case 0x0c0a2cbau: goto P_0c0a2cba;
case 0x0c0a2cbcu: goto P_0c0a2cbc;
case 0x0c0a2cbeu: goto P_0c0a2cbe;
case 0x0c0a2cc0u: goto P_0c0a2cc0;
case 0x0c0a2cc2u: goto P_0c0a2cc2;
case 0x0c0a2cc4u: goto P_0c0a2cc4;
case 0x0c0a2cc6u: goto P_0c0a2cc6;
case 0x0c0a2cc8u: goto P_0c0a2cc8;
case 0x0c0a2ccau: goto P_0c0a2cca;
case 0x0c0a2cccu: goto P_0c0a2ccc;
case 0x0c0a2cceu: goto P_0c0a2cce;
case 0x0c0a2cd0u: goto P_0c0a2cd0;
case 0x0c0a2cd2u: goto P_0c0a2cd2;
case 0x0c0a2cd4u: goto P_0c0a2cd4;
case 0x0c0a2cd6u: goto P_0c0a2cd6;
case 0x0c0a2cd8u: goto P_0c0a2cd8;
case 0x0c0a2cdau: goto P_0c0a2cda;
case 0x0c0a2cdcu: goto P_0c0a2cdc;
case 0x0c0a2cdeu: goto P_0c0a2cde;
case 0x0c0a2ce0u: goto P_0c0a2ce0;
case 0x0c0a2ce2u: goto P_0c0a2ce2;
case 0x0c0a2ce4u: goto P_0c0a2ce4;
case 0x0c0a2ce6u: goto P_0c0a2ce6;
case 0x0c0a2ce8u: goto P_0c0a2ce8;
case 0x0c0a2ceau: goto P_0c0a2cea;
case 0x0c0a2cecu: goto P_0c0a2cec;
case 0x0c0a2ceeu: goto P_0c0a2cee;
case 0x0c0a2cf0u: goto P_0c0a2cf0;
case 0x0c0a2cf2u: goto P_0c0a2cf2;
case 0x0c0a2cf4u: goto P_0c0a2cf4;
case 0x0c0a2cf6u: goto P_0c0a2cf6;
case 0x0c0a2cf8u: goto P_0c0a2cf8;
case 0x0c0a2cfau: goto P_0c0a2cfa;
case 0x0c0a2cfcu: goto P_0c0a2cfc;
case 0x0c0a2cfeu: goto P_0c0a2cfe;
case 0x0c0a2d00u: goto P_0c0a2d00;
case 0x0c0a2d02u: goto P_0c0a2d02;
case 0x0c0a2d04u: goto P_0c0a2d04;
case 0x0c0a2d06u: goto P_0c0a2d06;
case 0x0c0a2d08u: goto P_0c0a2d08;
case 0x0c0a2d0au: goto P_0c0a2d0a;
case 0x0c0a2d0cu: goto P_0c0a2d0c;
case 0x0c0a2d0eu: goto P_0c0a2d0e;
case 0x0c0a2d10u: goto P_0c0a2d10;
case 0x0c0a2d12u: goto P_0c0a2d12;
case 0x0c0a2d14u: goto P_0c0a2d14;
case 0x0c0a2d16u: goto P_0c0a2d16;
case 0x0c0a2d18u: goto P_0c0a2d18;
case 0x0c0a2d1au: goto P_0c0a2d1a;
case 0x0c0a2d1cu: goto P_0c0a2d1c;
case 0x0c0a2d1eu: goto P_0c0a2d1e;
case 0x0c0a2d20u: goto P_0c0a2d20;
case 0x0c0a2d22u: goto P_0c0a2d22;
case 0x0c0a2d24u: goto P_0c0a2d24;
case 0x0c0a2d26u: goto P_0c0a2d26;
case 0x0c0a2d28u: goto P_0c0a2d28;
case 0x0c0a2d2au: goto P_0c0a2d2a;
case 0x0c0a2d2cu: goto P_0c0a2d2c;
case 0x0c0a2d2eu: goto P_0c0a2d2e;
case 0x0c0a2d30u: goto P_0c0a2d30;
case 0x0c0a2d32u: goto P_0c0a2d32;
case 0x0c0a2d34u: goto P_0c0a2d34;
case 0x0c0a2d36u: goto P_0c0a2d36;
case 0x0c0a2d38u: goto P_0c0a2d38;
case 0x0c0a2d3au: goto P_0c0a2d3a;
case 0x0c0a2d3cu: goto P_0c0a2d3c;
case 0x0c0a2d3eu: goto P_0c0a2d3e;
case 0x0c0a2d40u: goto P_0c0a2d40;
case 0x0c0a2d42u: goto P_0c0a2d42;
case 0x0c0a2d44u: goto P_0c0a2d44;
case 0x0c0a2d46u: goto P_0c0a2d46;
case 0x0c0a2d48u: goto P_0c0a2d48;
case 0x0c0a2d4au: goto P_0c0a2d4a;
case 0x0c0a2d4cu: goto P_0c0a2d4c;
case 0x0c0a2d4eu: goto P_0c0a2d4e;
case 0x0c0a2d50u: goto P_0c0a2d50;
case 0x0c0a2d52u: goto P_0c0a2d52;
case 0x0c0a2d54u: goto P_0c0a2d54;
case 0x0c0a2d56u: goto P_0c0a2d56;
case 0x0c0a2d58u: goto P_0c0a2d58;
case 0x0c0a2d5au: goto P_0c0a2d5a;
case 0x0c0a2d5cu: goto P_0c0a2d5c;
case 0x0c0a2d5eu: goto P_0c0a2d5e;
case 0x0c0a2d60u: goto P_0c0a2d60;
case 0x0c0a2d62u: goto P_0c0a2d62;
case 0x0c0a2d64u: goto P_0c0a2d64;
case 0x0c0a2d66u: goto P_0c0a2d66;
case 0x0c0a2d68u: goto P_0c0a2d68;
case 0x0c0a2d6au: goto P_0c0a2d6a;
case 0x0c0a2d6cu: goto P_0c0a2d6c;
case 0x0c0a2d6eu: goto P_0c0a2d6e;
case 0x0c0a2d70u: goto P_0c0a2d70;
case 0x0c0a2d72u: goto P_0c0a2d72;
case 0x0c0a2d74u: goto P_0c0a2d74;
case 0x0c0a2d76u: goto P_0c0a2d76;
case 0x0c0a2d78u: goto P_0c0a2d78;
case 0x0c0a2d7au: goto P_0c0a2d7a;
case 0x0c0a2d7cu: goto P_0c0a2d7c;
case 0x0c0a2d7eu: goto P_0c0a2d7e;
case 0x0c0a2d80u: goto P_0c0a2d80;
case 0x0c0a2d82u: goto P_0c0a2d82;
case 0x0c0a2d84u: goto P_0c0a2d84;
case 0x0c0a2d86u: goto P_0c0a2d86;
case 0x0c0a2d88u: goto P_0c0a2d88;
case 0x0c0a2d8au: goto P_0c0a2d8a;
case 0x0c0a2d8cu: goto P_0c0a2d8c;
case 0x0c0a2d8eu: goto P_0c0a2d8e;
case 0x0c0a2d90u: goto P_0c0a2d90;
case 0x0c0a2d92u: goto P_0c0a2d92;
case 0x0c0a2d94u: goto P_0c0a2d94;
case 0x0c0a2d96u: goto P_0c0a2d96;
case 0x0c0a2d98u: goto P_0c0a2d98;
case 0x0c0a2d9au: goto P_0c0a2d9a;
case 0x0c0a2d9cu: goto P_0c0a2d9c;
case 0x0c0a2d9eu: goto P_0c0a2d9e;
case 0x0c0a2da0u: goto P_0c0a2da0;
case 0x0c0a2da2u: goto P_0c0a2da2;
case 0x0c0a2da4u: goto P_0c0a2da4;
case 0x0c0a2da6u: goto P_0c0a2da6;
case 0x0c0a2da8u: goto P_0c0a2da8;
case 0x0c0a2daau: goto P_0c0a2daa;
case 0x0c0a2dacu: goto P_0c0a2dac;
case 0x0c0a2daeu: goto P_0c0a2dae;
case 0x0c0a2db0u: goto P_0c0a2db0;
case 0x0c0a2db2u: goto P_0c0a2db2;
case 0x0c0a2db4u: goto P_0c0a2db4;
case 0x0c0a2db6u: goto P_0c0a2db6;
case 0x0c0a2db8u: goto P_0c0a2db8;
case 0x0c0a2dbau: goto P_0c0a2dba;
case 0x0c0a2dbcu: goto P_0c0a2dbc;
case 0x0c0a2dbeu: goto P_0c0a2dbe;
case 0x0c0a2dc0u: goto P_0c0a2dc0;
case 0x0c0a2dc2u: goto P_0c0a2dc2;
case 0x0c0a2dc4u: goto P_0c0a2dc4;
case 0x0c0a2dc6u: goto P_0c0a2dc6;
case 0x0c0a2dc8u: goto P_0c0a2dc8;
case 0x0c0a2dcau: goto P_0c0a2dca;
case 0x0c0a2dccu: goto P_0c0a2dcc;
case 0x0c0a2dceu: goto P_0c0a2dce;
case 0x0c0a2dd0u: goto P_0c0a2dd0;
case 0x0c0a2dd2u: goto P_0c0a2dd2;
case 0x0c0a2dd4u: goto P_0c0a2dd4;
case 0x0c0a2dd6u: goto P_0c0a2dd6;
case 0x0c0a2dd8u: goto P_0c0a2dd8;
case 0x0c0a2ddau: goto P_0c0a2dda;
case 0x0c0a2ddcu: goto P_0c0a2ddc;
case 0x0c0a2ddeu: goto P_0c0a2dde;
case 0x0c0a2de0u: goto P_0c0a2de0;
case 0x0c0a2de2u: goto P_0c0a2de2;
case 0x0c0a2de4u: goto P_0c0a2de4;
case 0x0c0a2de6u: goto P_0c0a2de6;
case 0x0c0a2de8u: goto P_0c0a2de8;
case 0x0c0a2deau: goto P_0c0a2dea;
case 0x0c0a2decu: goto P_0c0a2dec;
case 0x0c0a2deeu: goto P_0c0a2dee;
case 0x0c0a2df0u: goto P_0c0a2df0;
case 0x0c0a2df2u: goto P_0c0a2df2;
case 0x0c0a2df4u: goto P_0c0a2df4;
case 0x0c0a2df6u: goto P_0c0a2df6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a2c36: /* original 2fe6, guest PC 0x0c0a2c36 */
if(!s->budget--) { s->failed_pc=0x0c0a2c36u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c38;
P_0c0a2c38: /* original 2fd6, guest PC 0x0c0a2c38 */
if(!s->budget--) { s->failed_pc=0x0c0a2c38u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c3a;
P_0c0a2c3a: /* original 2fc6, guest PC 0x0c0a2c3a */
if(!s->budget--) { s->failed_pc=0x0c0a2c3au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c3c;
P_0c0a2c3c: /* original 2fb6, guest PC 0x0c0a2c3c */
if(!s->budget--) { s->failed_pc=0x0c0a2c3cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c3e;
P_0c0a2c3e: /* original 6b43, guest PC 0x0c0a2c3e */
if(!s->budget--) { s->failed_pc=0x0c0a2c3eu; return 0; }
r[11]=r[4];
goto P_0c0a2c40;
P_0c0a2c40: /* original 2fa6, guest PC 0x0c0a2c40 */
if(!s->budget--) { s->failed_pc=0x0c0a2c40u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c42;
P_0c0a2c42: /* original e400, guest PC 0x0c0a2c42 */
if(!s->budget--) { s->failed_pc=0x0c0a2c42u; return 0; }
r[4]=0x00000000u;
goto P_0c0a2c44;
P_0c0a2c44: /* original 2f96, guest PC 0x0c0a2c44 */
if(!s->budget--) { s->failed_pc=0x0c0a2c44u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c46;
P_0c0a2c46: /* original 2f86, guest PC 0x0c0a2c46 */
if(!s->budget--) { s->failed_pc=0x0c0a2c46u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2c48;
P_0c0a2c48: /* original 4f22, guest PC 0x0c0a2c48 */
if(!s->budget--) { s->failed_pc=0x0c0a2c48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2c4a;
P_0c0a2c4a: /* original 7ff8, guest PC 0x0c0a2c4a */
if(!s->budget--) { s->failed_pc=0x0c0a2c4au; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0a2c4c;
P_0c0a2c4c: /* original 1f41, guest PC 0x0c0a2c4c */
if(!s->budget--) { s->failed_pc=0x0c0a2c4cu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0a2c4e;
P_0c0a2c4e: /* original 60b2, guest PC 0x0c0a2c4e */
if(!s->budget--) { s->failed_pc=0x0c0a2c4eu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0a2c50;
P_0c0a2c50: /* original c880, guest PC 0x0c0a2c50 */
if(!s->budget--) { s->failed_pc=0x0c0a2c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c0a2c52;
P_0c0a2c52: /* original 8d03, guest PC 0x0c0a2c52 */
if(!s->budget--) { s->failed_pc=0x0c0a2c52u; return 0; }
cond=r[17]&1u;
r[13]=r[11];
if(cond) { goto P_0c0a2c5c; }
goto P_0c0a2c56;
P_0c0a2c54: /* original 6db3, guest PC 0x0c0a2c54 */
if(!s->budget--) { s->failed_pc=0x0c0a2c54u; return 0; }
r[13]=r[11];
goto P_0c0a2c56;
P_0c0a2c56: /* original d217, guest PC 0x0c0a2c56 */
if(!s->budget--) { s->failed_pc=0x0c0a2c56u; return 0; }
r[2]=read(ram,0x0c0a2cb4u,4);
goto P_0c0a2c58;
P_0c0a2c58: /* original a06b, guest PC 0x0c0a2c58 */
if(!s->budget--) { s->failed_pc=0x0c0a2c58u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2d32;
P_0c0a2c5a: /* original 1f21, guest PC 0x0c0a2c5a */
if(!s->budget--) { s->failed_pc=0x0c0a2c5au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a2c5c;
P_0c0a2c5c: /* original 51b4, guest PC 0x0c0a2c5c */
if(!s->budget--) { s->failed_pc=0x0c0a2c5cu; return 0; }
r[1]=read(ram,r[11]+16,4);
goto P_0c0a2c5e;
P_0c0a2c5e: /* original e8fe, guest PC 0x0c0a2c5e */
if(!s->budget--) { s->failed_pc=0x0c0a2c5eu; return 0; }
r[8]=0xfffffffeu;
goto P_0c0a2c60;
P_0c0a2c60: /* original ea01, guest PC 0x0c0a2c60 */
if(!s->budget--) { s->failed_pc=0x0c0a2c60u; return 0; }
r[10]=0x00000001u;
goto P_0c0a2c62;
P_0c0a2c62: /* original 31bc, guest PC 0x0c0a2c62 */
if(!s->budget--) { s->failed_pc=0x0c0a2c62u; return 0; }
r[1]+=r[11];
goto P_0c0a2c64;
P_0c0a2c64: /* original 1b14, guest PC 0x0c0a2c64 */
if(!s->budget--) { s->failed_pc=0x0c0a2c64u; return 0; }
write(ram,r[11]+16,r[1],4);
goto P_0c0a2c66;
P_0c0a2c66: /* original 53b5, guest PC 0x0c0a2c66 */
if(!s->budget--) { s->failed_pc=0x0c0a2c66u; return 0; }
r[3]=read(ram,r[11]+20,4);
goto P_0c0a2c68;
P_0c0a2c68: /* original 33bc, guest PC 0x0c0a2c68 */
if(!s->budget--) { s->failed_pc=0x0c0a2c68u; return 0; }
r[3]+=r[11];
goto P_0c0a2c6a;
P_0c0a2c6a: /* original 1b35, guest PC 0x0c0a2c6a */
if(!s->budget--) { s->failed_pc=0x0c0a2c6au; return 0; }
write(ram,r[11]+20,r[3],4);
goto P_0c0a2c6c;
P_0c0a2c6c: /* original 52b4, guest PC 0x0c0a2c6c */
if(!s->budget--) { s->failed_pc=0x0c0a2c6cu; return 0; }
r[2]=read(ram,r[11]+16,4);
goto P_0c0a2c6e;
P_0c0a2c6e: /* original 2f22, guest PC 0x0c0a2c6e */
if(!s->budget--) { s->failed_pc=0x0c0a2c6eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a2c70;
P_0c0a2c70: /* original a058, guest PC 0x0c0a2c70 */
if(!s->budget--) { s->failed_pc=0x0c0a2c70u; return 0; }
r[9]=r[4];
goto P_0c0a2d24;
P_0c0a2c72: /* original 6943, guest PC 0x0c0a2c72 */
if(!s->budget--) { s->failed_pc=0x0c0a2c72u; return 0; }
r[9]=r[4];
goto P_0c0a2c74;
P_0c0a2c74: /* original 63f2, guest PC 0x0c0a2c74 */
if(!s->budget--) { s->failed_pc=0x0c0a2c74u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a2c76;
P_0c0a2c76: /* original 6c93, guest PC 0x0c0a2c76 */
if(!s->budget--) { s->failed_pc=0x0c0a2c76u; return 0; }
r[12]=r[9];
goto P_0c0a2c78;
P_0c0a2c78: /* original 4c08, guest PC 0x0c0a2c78 */
if(!s->budget--) { s->failed_pc=0x0c0a2c78u; return 0; }
r[12]<<=2;
goto P_0c0a2c7a;
P_0c0a2c7a: /* original 3c3c, guest PC 0x0c0a2c7a */
if(!s->budget--) { s->failed_pc=0x0c0a2c7au; return 0; }
r[12]+=r[3];
goto P_0c0a2c7c;
P_0c0a2c7c: /* original 62c2, guest PC 0x0c0a2c7c */
if(!s->budget--) { s->failed_pc=0x0c0a2c7cu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a2c7e;
P_0c0a2c7e: /* original 2228, guest PC 0x0c0a2c7e */
if(!s->budget--) { s->failed_pc=0x0c0a2c7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2c80;
P_0c0a2c80: /* original 894f, guest PC 0x0c0a2c80 */
if(!s->budget--) { s->failed_pc=0x0c0a2c80u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2c82;
P_0c0a2c82: /* original 62c2, guest PC 0x0c0a2c82 */
if(!s->budget--) { s->failed_pc=0x0c0a2c82u; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c0a2c84;
P_0c0a2c84: /* original 32dc, guest PC 0x0c0a2c84 */
if(!s->budget--) { s->failed_pc=0x0c0a2c84u; return 0; }
r[2]+=r[13];
goto P_0c0a2c86;
P_0c0a2c86: /* original 2c22, guest PC 0x0c0a2c86 */
if(!s->budget--) { s->failed_pc=0x0c0a2c86u; return 0; }
write(ram,r[12],r[2],4);
goto P_0c0a2c88;
P_0c0a2c88: /* original 63c2, guest PC 0x0c0a2c88 */
if(!s->budget--) { s->failed_pc=0x0c0a2c88u; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0a2c8a;
P_0c0a2c8a: /* original 23a8, guest PC 0x0c0a2c8a */
if(!s->budget--) { s->failed_pc=0x0c0a2c8au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[10])==0)!=0);
goto P_0c0a2c8c;
P_0c0a2c8c: /* original 8914, guest PC 0x0c0a2c8c */
if(!s->budget--) { s->failed_pc=0x0c0a2c8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cb8; }
goto P_0c0a2c8e;
P_0c0a2c8e: /* original 61c2, guest PC 0x0c0a2c8e */
if(!s->budget--) { s->failed_pc=0x0c0a2c8eu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0a2c90;
P_0c0a2c90: /* original 2189, guest PC 0x0c0a2c90 */
if(!s->budget--) { s->failed_pc=0x0c0a2c90u; return 0; }
r[1]&=r[8];
goto P_0c0a2c92;
P_0c0a2c92: /* original 6413, guest PC 0x0c0a2c92 */
if(!s->budget--) { s->failed_pc=0x0c0a2c92u; return 0; }
r[4]=r[1];
goto P_0c0a2c94;
P_0c0a2c94: /* original 2c12, guest PC 0x0c0a2c94 */
if(!s->budget--) { s->failed_pc=0x0c0a2c94u; return 0; }
write(ram,r[12],r[1],4);
goto P_0c0a2c96;
P_0c0a2c96: /* original 5341, guest PC 0x0c0a2c96 */
if(!s->budget--) { s->failed_pc=0x0c0a2c96u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2c98;
P_0c0a2c98: /* original 23ab, guest PC 0x0c0a2c98 */
if(!s->budget--) { s->failed_pc=0x0c0a2c98u; return 0; }
r[3]|=r[10];
goto P_0c0a2c9a;
P_0c0a2c9a: /* original a042, guest PC 0x0c0a2c9a */
if(!s->budget--) { s->failed_pc=0x0c0a2c9au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d22;
P_0c0a2c9c: /* original 1431, guest PC 0x0c0a2c9c */
if(!s->budget--) { s->failed_pc=0x0c0a2c9cu; return 0; }
write(ram,r[4]+4,r[3],4);
if(!vf3_matrix_family(0x0c0a2c9eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2c9eu; return 0; } return 1;
P_0c0a2cb8: /* original 6ec2, guest PC 0x0c0a2cb8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cb8u; return 0; }
tmp=read(ram,r[12],4);
r[14]=tmp;
goto P_0c0a2cba;
P_0c0a2cba: /* original 63e2, guest PC 0x0c0a2cba */
if(!s->budget--) { s->failed_pc=0x0c0a2cbau; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a2cbc;
P_0c0a2cbc: /* original 2338, guest PC 0x0c0a2cbc */
if(!s->budget--) { s->failed_pc=0x0c0a2cbcu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2cbe;
P_0c0a2cbe: /* original 8908, guest PC 0x0c0a2cbe */
if(!s->budget--) { s->failed_pc=0x0c0a2cbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cd2; }
goto P_0c0a2cc0;
P_0c0a2cc0: /* original 63e2, guest PC 0x0c0a2cc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc0u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0a2cc2;
P_0c0a2cc2: /* original 33d2, guest PC 0x0c0a2cc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cc4;
P_0c0a2cc4: /* original 8905, guest PC 0x0c0a2cc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2cd2; }
goto P_0c0a2cc6;
P_0c0a2cc6: /* original 61e2, guest PC 0x0c0a2cc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0a2cc8;
P_0c0a2cc8: /* original 65d3, guest PC 0x0c0a2cc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cc8u; return 0; }
r[5]=r[13];
goto P_0c0a2cca;
P_0c0a2cca: /* original 31dc, guest PC 0x0c0a2cca */
if(!s->budget--) { s->failed_pc=0x0c0a2ccau; return 0; }
r[1]+=r[13];
goto P_0c0a2ccc;
P_0c0a2ccc: /* original 2e12, guest PC 0x0c0a2ccc */
if(!s->budget--) { s->failed_pc=0x0c0a2cccu; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0a2cce;
P_0c0a2cce: /* original b03b, guest PC 0x0c0a2cce */
if(!s->budget--) { s->failed_pc=0x0c0a2cceu; return 0; }
target=code_base|0x0c0a2d48u; r[16]=code_base|0x0c0a2cd2u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2cd2u) { target=s->pc; goto dispatch; }
goto P_0c0a2cd2;
P_0c0a2cd0: /* original 6413, guest PC 0x0c0a2cd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd0u; return 0; }
r[4]=r[1];
goto P_0c0a2cd2;
P_0c0a2cd2: /* original 52e1, guest PC 0x0c0a2cd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd2u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cd4;
P_0c0a2cd4: /* original 2228, guest PC 0x0c0a2cd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2cd6;
P_0c0a2cd6: /* original 8913, guest PC 0x0c0a2cd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cd8;
P_0c0a2cd8: /* original 53e1, guest PC 0x0c0a2cd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cd8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2cda;
P_0c0a2cda: /* original 33d2, guest PC 0x0c0a2cda */
if(!s->budget--) { s->failed_pc=0x0c0a2cdau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cdc;
P_0c0a2cdc: /* original 8910, guest PC 0x0c0a2cdc */
if(!s->budget--) { s->failed_pc=0x0c0a2cdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cde;
P_0c0a2cde: /* original 51e1, guest PC 0x0c0a2cde */
if(!s->budget--) { s->failed_pc=0x0c0a2cdeu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2ce0;
P_0c0a2ce0: /* original 31dc, guest PC 0x0c0a2ce0 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce0u; return 0; }
r[1]+=r[13];
goto P_0c0a2ce2;
P_0c0a2ce2: /* original 6313, guest PC 0x0c0a2ce2 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce2u; return 0; }
r[3]=r[1];
goto P_0c0a2ce4;
P_0c0a2ce4: /* original 1e11, guest PC 0x0c0a2ce4 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce4u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2ce6;
P_0c0a2ce6: /* original 6232, guest PC 0x0c0a2ce6 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce6u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0a2ce8;
P_0c0a2ce8: /* original 2228, guest PC 0x0c0a2ce8 */
if(!s->budget--) { s->failed_pc=0x0c0a2ce8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2cea;
P_0c0a2cea: /* original 8909, guest PC 0x0c0a2cea */
if(!s->budget--) { s->failed_pc=0x0c0a2ceau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cec;
P_0c0a2cec: /* original 52e1, guest PC 0x0c0a2cec */
if(!s->budget--) { s->failed_pc=0x0c0a2cecu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cee;
P_0c0a2cee: /* original 6322, guest PC 0x0c0a2cee */
if(!s->budget--) { s->failed_pc=0x0c0a2ceeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0a2cf0;
P_0c0a2cf0: /* original 33d2, guest PC 0x0c0a2cf0 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2cf2;
P_0c0a2cf2: /* original 8905, guest PC 0x0c0a2cf2 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d00; }
goto P_0c0a2cf4;
P_0c0a2cf4: /* original 61c2, guest PC 0x0c0a2cf4 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf4u; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0a2cf6;
P_0c0a2cf6: /* original 52e1, guest PC 0x0c0a2cf6 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf6u; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2cf8;
P_0c0a2cf8: /* original 5311, guest PC 0x0c0a2cf8 */
if(!s->budget--) { s->failed_pc=0x0c0a2cf8u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c0a2cfa;
P_0c0a2cfa: /* original 6122, guest PC 0x0c0a2cfa */
if(!s->budget--) { s->failed_pc=0x0c0a2cfau; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c0a2cfc;
P_0c0a2cfc: /* original 31dc, guest PC 0x0c0a2cfc */
if(!s->budget--) { s->failed_pc=0x0c0a2cfcu; return 0; }
r[1]+=r[13];
goto P_0c0a2cfe;
P_0c0a2cfe: /* original 2312, guest PC 0x0c0a2cfe */
if(!s->budget--) { s->failed_pc=0x0c0a2cfeu; return 0; }
write(ram,r[3],r[1],4);
goto P_0c0a2d00;
P_0c0a2d00: /* original 53e2, guest PC 0x0c0a2d00 */
if(!s->budget--) { s->failed_pc=0x0c0a2d00u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0a2d02;
P_0c0a2d02: /* original 2338, guest PC 0x0c0a2d02 */
if(!s->budget--) { s->failed_pc=0x0c0a2d02u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d04;
P_0c0a2d04: /* original 890d, guest PC 0x0c0a2d04 */
if(!s->budget--) { s->failed_pc=0x0c0a2d04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d06;
P_0c0a2d06: /* original 53e2, guest PC 0x0c0a2d06 */
if(!s->budget--) { s->failed_pc=0x0c0a2d06u; return 0; }
r[3]=read(ram,r[14]+8,4);
goto P_0c0a2d08;
P_0c0a2d08: /* original 33d2, guest PC 0x0c0a2d08 */
if(!s->budget--) { s->failed_pc=0x0c0a2d08u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d0a;
P_0c0a2d0a: /* original 890a, guest PC 0x0c0a2d0a */
if(!s->budget--) { s->failed_pc=0x0c0a2d0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d0c;
P_0c0a2d0c: /* original 51e2, guest PC 0x0c0a2d0c */
if(!s->budget--) { s->failed_pc=0x0c0a2d0cu; return 0; }
r[1]=read(ram,r[14]+8,4);
goto P_0c0a2d0e;
P_0c0a2d0e: /* original 31dc, guest PC 0x0c0a2d0e */
if(!s->budget--) { s->failed_pc=0x0c0a2d0eu; return 0; }
r[1]+=r[13];
goto P_0c0a2d10;
P_0c0a2d10: /* original 6313, guest PC 0x0c0a2d10 */
if(!s->budget--) { s->failed_pc=0x0c0a2d10u; return 0; }
r[3]=r[1];
goto P_0c0a2d12;
P_0c0a2d12: /* original 1e12, guest PC 0x0c0a2d12 */
if(!s->budget--) { s->failed_pc=0x0c0a2d12u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c0a2d14;
P_0c0a2d14: /* original 6232, guest PC 0x0c0a2d14 */
if(!s->budget--) { s->failed_pc=0x0c0a2d14u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c0a2d16;
P_0c0a2d16: /* original 2228, guest PC 0x0c0a2d16 */
if(!s->budget--) { s->failed_pc=0x0c0a2d16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d18;
P_0c0a2d18: /* original 8903, guest PC 0x0c0a2d18 */
if(!s->budget--) { s->failed_pc=0x0c0a2d18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d22; }
goto P_0c0a2d1a;
P_0c0a2d1a: /* original 54e2, guest PC 0x0c0a2d1a */
if(!s->budget--) { s->failed_pc=0x0c0a2d1au; return 0; }
r[4]=read(ram,r[14]+8,4);
goto P_0c0a2d1c;
P_0c0a2d1c: /* original 6342, guest PC 0x0c0a2d1c */
if(!s->budget--) { s->failed_pc=0x0c0a2d1cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c0a2d1e;
P_0c0a2d1e: /* original 33dc, guest PC 0x0c0a2d1e */
if(!s->budget--) { s->failed_pc=0x0c0a2d1eu; return 0; }
r[3]+=r[13];
goto P_0c0a2d20;
P_0c0a2d20: /* original 2432, guest PC 0x0c0a2d20 */
if(!s->budget--) { s->failed_pc=0x0c0a2d20u; return 0; }
write(ram,r[4],r[3],4);
goto P_0c0a2d22;
P_0c0a2d22: /* original 7901, guest PC 0x0c0a2d22 */
if(!s->budget--) { s->failed_pc=0x0c0a2d22u; return 0; }
r[9]+=0x00000001u;
goto P_0c0a2d24;
P_0c0a2d24: /* original 85b6, guest PC 0x0c0a2d24 */
if(!s->budget--) { s->failed_pc=0x0c0a2d24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[11]+12,2);
goto P_0c0a2d26;
P_0c0a2d26: /* original 600d, guest PC 0x0c0a2d26 */
if(!s->budget--) { s->failed_pc=0x0c0a2d26u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0a2d28;
P_0c0a2d28: /* original 3903, guest PC 0x0c0a2d28 */
if(!s->budget--) { s->failed_pc=0x0c0a2d28u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[0])!=0);
goto P_0c0a2d2a;
P_0c0a2d2a: /* original 8ba3, guest PC 0x0c0a2d2a */
if(!s->budget--) { s->failed_pc=0x0c0a2d2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a2c74; }
goto P_0c0a2d2c;
P_0c0a2d2c: /* original 60b2, guest PC 0x0c0a2d2c */
if(!s->budget--) { s->failed_pc=0x0c0a2d2cu; return 0; }
tmp=read(ram,r[11],4);
r[0]=tmp;
goto P_0c0a2d2e;
P_0c0a2d2e: /* original cb80, guest PC 0x0c0a2d2e */
if(!s->budget--) { s->failed_pc=0x0c0a2d2eu; return 0; }
r[0]|=128u;
goto P_0c0a2d30;
P_0c0a2d30: /* original 2b02, guest PC 0x0c0a2d30 */
if(!s->budget--) { s->failed_pc=0x0c0a2d30u; return 0; }
write(ram,r[11],r[0],4);
goto P_0c0a2d32;
P_0c0a2d32: /* original 50f1, guest PC 0x0c0a2d32 */
if(!s->budget--) { s->failed_pc=0x0c0a2d32u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c0a2d34;
P_0c0a2d34: /* original 7f08, guest PC 0x0c0a2d34 */
if(!s->budget--) { s->failed_pc=0x0c0a2d34u; return 0; }
r[15]+=0x00000008u;
goto P_0c0a2d36;
P_0c0a2d36: /* original 4f26, guest PC 0x0c0a2d36 */
if(!s->budget--) { s->failed_pc=0x0c0a2d36u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2d38;
P_0c0a2d38: /* original 68f6, guest PC 0x0c0a2d38 */
if(!s->budget--) { s->failed_pc=0x0c0a2d38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0a2d3a;
P_0c0a2d3a: /* original 69f6, guest PC 0x0c0a2d3a */
if(!s->budget--) { s->failed_pc=0x0c0a2d3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0a2d3c;
P_0c0a2d3c: /* original 6af6, guest PC 0x0c0a2d3c */
if(!s->budget--) { s->failed_pc=0x0c0a2d3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a2d3e;
P_0c0a2d3e: /* original 6bf6, guest PC 0x0c0a2d3e */
if(!s->budget--) { s->failed_pc=0x0c0a2d3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a2d40;
P_0c0a2d40: /* original 6cf6, guest PC 0x0c0a2d40 */
if(!s->budget--) { s->failed_pc=0x0c0a2d40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a2d42;
P_0c0a2d42: /* original 6df6, guest PC 0x0c0a2d42 */
if(!s->budget--) { s->failed_pc=0x0c0a2d42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2d44;
P_0c0a2d44: /* original 000b, guest PC 0x0c0a2d44 */
if(!s->budget--) { s->failed_pc=0x0c0a2d44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2d46: /* original 6ef6, guest PC 0x0c0a2d46 */
if(!s->budget--) { s->failed_pc=0x0c0a2d46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a2d48;
P_0c0a2d48: /* original 2fe6, guest PC 0x0c0a2d48 */
if(!s->budget--) { s->failed_pc=0x0c0a2d48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4a;
P_0c0a2d4a: /* original 6e43, guest PC 0x0c0a2d4a */
if(!s->budget--) { s->failed_pc=0x0c0a2d4au; return 0; }
r[14]=r[4];
goto P_0c0a2d4c;
P_0c0a2d4c: /* original 2fd6, guest PC 0x0c0a2d4c */
if(!s->budget--) { s->failed_pc=0x0c0a2d4cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a2d4e;
P_0c0a2d4e: /* original 6d53, guest PC 0x0c0a2d4e */
if(!s->budget--) { s->failed_pc=0x0c0a2d4eu; return 0; }
r[13]=r[5];
goto P_0c0a2d50;
P_0c0a2d50: /* original 4f22, guest PC 0x0c0a2d50 */
if(!s->budget--) { s->failed_pc=0x0c0a2d50u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a2d52;
P_0c0a2d52: /* original 53e1, guest PC 0x0c0a2d52 */
if(!s->budget--) { s->failed_pc=0x0c0a2d52u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d54;
P_0c0a2d54: /* original 2338, guest PC 0x0c0a2d54 */
if(!s->budget--) { s->failed_pc=0x0c0a2d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d56;
P_0c0a2d56: /* original 8933, guest PC 0x0c0a2d56 */
if(!s->budget--) { s->failed_pc=0x0c0a2d56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d58;
P_0c0a2d58: /* original 53e1, guest PC 0x0c0a2d58 */
if(!s->budget--) { s->failed_pc=0x0c0a2d58u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d5a;
P_0c0a2d5a: /* original 33d2, guest PC 0x0c0a2d5a */
if(!s->budget--) { s->failed_pc=0x0c0a2d5au; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d5c;
P_0c0a2d5c: /* original 8930, guest PC 0x0c0a2d5c */
if(!s->budget--) { s->failed_pc=0x0c0a2d5cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dc0; }
goto P_0c0a2d5e;
P_0c0a2d5e: /* original 51e1, guest PC 0x0c0a2d5e */
if(!s->budget--) { s->failed_pc=0x0c0a2d5eu; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c0a2d60;
P_0c0a2d60: /* original 31dc, guest PC 0x0c0a2d60 */
if(!s->budget--) { s->failed_pc=0x0c0a2d60u; return 0; }
r[1]+=r[13];
goto P_0c0a2d62;
P_0c0a2d62: /* original 6313, guest PC 0x0c0a2d62 */
if(!s->budget--) { s->failed_pc=0x0c0a2d62u; return 0; }
r[3]=r[1];
goto P_0c0a2d64;
P_0c0a2d64: /* original 1e11, guest PC 0x0c0a2d64 */
if(!s->budget--) { s->failed_pc=0x0c0a2d64u; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c0a2d66;
P_0c0a2d66: /* original 5231, guest PC 0x0c0a2d66 */
if(!s->budget--) { s->failed_pc=0x0c0a2d66u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c0a2d68;
P_0c0a2d68: /* original 2228, guest PC 0x0c0a2d68 */
if(!s->budget--) { s->failed_pc=0x0c0a2d68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2d6a;
P_0c0a2d6a: /* original 8907, guest PC 0x0c0a2d6a */
if(!s->budget--) { s->failed_pc=0x0c0a2d6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d6c;
P_0c0a2d6c: /* original 52e1, guest PC 0x0c0a2d6c */
if(!s->budget--) { s->failed_pc=0x0c0a2d6cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d6e;
P_0c0a2d6e: /* original 5321, guest PC 0x0c0a2d6e */
if(!s->budget--) { s->failed_pc=0x0c0a2d6eu; return 0; }
r[3]=read(ram,r[2]+4,4);
goto P_0c0a2d70;
P_0c0a2d70: /* original 33d2, guest PC 0x0c0a2d70 */
if(!s->budget--) { s->failed_pc=0x0c0a2d70u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2d72;
P_0c0a2d72: /* original 8903, guest PC 0x0c0a2d72 */
if(!s->budget--) { s->failed_pc=0x0c0a2d72u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d7c; }
goto P_0c0a2d74;
P_0c0a2d74: /* original 54e1, guest PC 0x0c0a2d74 */
if(!s->budget--) { s->failed_pc=0x0c0a2d74u; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d76;
P_0c0a2d76: /* original 5341, guest PC 0x0c0a2d76 */
if(!s->budget--) { s->failed_pc=0x0c0a2d76u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0a2d78;
P_0c0a2d78: /* original 33dc, guest PC 0x0c0a2d78 */
if(!s->budget--) { s->failed_pc=0x0c0a2d78u; return 0; }
r[3]+=r[13];
goto P_0c0a2d7a;
P_0c0a2d7a: /* original 1431, guest PC 0x0c0a2d7a */
if(!s->budget--) { s->failed_pc=0x0c0a2d7au; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0a2d7c;
P_0c0a2d7c: /* original 52e1, guest PC 0x0c0a2d7c */
if(!s->budget--) { s->failed_pc=0x0c0a2d7cu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0a2d7e;
P_0c0a2d7e: /* original 5323, guest PC 0x0c0a2d7e */
if(!s->budget--) { s->failed_pc=0x0c0a2d7eu; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c0a2d80;
P_0c0a2d80: /* original 2338, guest PC 0x0c0a2d80 */
if(!s->budget--) { s->failed_pc=0x0c0a2d80u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2d82;
P_0c0a2d82: /* original 8907, guest PC 0x0c0a2d82 */
if(!s->budget--) { s->failed_pc=0x0c0a2d82u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d84;
P_0c0a2d84: /* original 53e1, guest PC 0x0c0a2d84 */
if(!s->budget--) { s->failed_pc=0x0c0a2d84u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d86;
P_0c0a2d86: /* original 5233, guest PC 0x0c0a2d86 */
if(!s->budget--) { s->failed_pc=0x0c0a2d86u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c0a2d88;
P_0c0a2d88: /* original 32d2, guest PC 0x0c0a2d88 */
if(!s->budget--) { s->failed_pc=0x0c0a2d88u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[13])!=0);
goto P_0c0a2d8a;
P_0c0a2d8a: /* original 8903, guest PC 0x0c0a2d8a */
if(!s->budget--) { s->failed_pc=0x0c0a2d8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2d94; }
goto P_0c0a2d8c;
P_0c0a2d8c: /* original 54e1, guest PC 0x0c0a2d8c */
if(!s->budget--) { s->failed_pc=0x0c0a2d8cu; return 0; }
r[4]=read(ram,r[14]+4,4);
goto P_0c0a2d8e;
P_0c0a2d8e: /* original 5243, guest PC 0x0c0a2d8e */
if(!s->budget--) { s->failed_pc=0x0c0a2d8eu; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c0a2d90;
P_0c0a2d90: /* original 32dc, guest PC 0x0c0a2d90 */
if(!s->budget--) { s->failed_pc=0x0c0a2d90u; return 0; }
r[2]+=r[13];
goto P_0c0a2d92;
P_0c0a2d92: /* original 1423, guest PC 0x0c0a2d92 */
if(!s->budget--) { s->failed_pc=0x0c0a2d92u; return 0; }
write(ram,r[4]+12,r[2],4);
goto P_0c0a2d94;
P_0c0a2d94: /* original c718, guest PC 0x0c0a2d94 */
if(!s->budget--) { s->failed_pc=0x0c0a2d94u; return 0; }
r[0]=code_base|0x000a2df8u;
goto P_0c0a2d96;
P_0c0a2d96: /* original 53e1, guest PC 0x0c0a2d96 */
if(!s->budget--) { s->failed_pc=0x0c0a2d96u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2d98;
P_0c0a2d98: /* original f408, guest PC 0x0c0a2d98 */
if(!s->budget--) { s->failed_pc=0x0c0a2d98u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0a2d9a;
P_0c0a2d9a: /* original e010, guest PC 0x0c0a2d9a */
if(!s->budget--) { s->failed_pc=0x0c0a2d9au; return 0; }
r[0]=0x00000010u;
goto P_0c0a2d9c;
P_0c0a2d9c: /* original f336, guest PC 0x0c0a2d9c */
if(!s->budget--) { s->failed_pc=0x0c0a2d9cu; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2d9e;
P_0c0a2d9e: /* original f342, guest PC 0x0c0a2d9e */
if(!s->budget--) { s->failed_pc=0x0c0a2d9eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2da0;
P_0c0a2da0: /* original f337, guest PC 0x0c0a2da0 */
if(!s->budget--) { s->failed_pc=0x0c0a2da0u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2da2;
P_0c0a2da2: /* original e014, guest PC 0x0c0a2da2 */
if(!s->budget--) { s->failed_pc=0x0c0a2da2u; return 0; }
r[0]=0x00000014u;
goto P_0c0a2da4;
P_0c0a2da4: /* original 53e1, guest PC 0x0c0a2da4 */
if(!s->budget--) { s->failed_pc=0x0c0a2da4u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2da6;
P_0c0a2da6: /* original f336, guest PC 0x0c0a2da6 */
if(!s->budget--) { s->failed_pc=0x0c0a2da6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2da8;
P_0c0a2da8: /* original f342, guest PC 0x0c0a2da8 */
if(!s->budget--) { s->failed_pc=0x0c0a2da8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2daa;
P_0c0a2daa: /* original f337, guest PC 0x0c0a2daa */
if(!s->budget--) { s->failed_pc=0x0c0a2daau; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dac;
P_0c0a2dac: /* original e018, guest PC 0x0c0a2dac */
if(!s->budget--) { s->failed_pc=0x0c0a2dacu; return 0; }
r[0]=0x00000018u;
goto P_0c0a2dae;
P_0c0a2dae: /* original 53e1, guest PC 0x0c0a2dae */
if(!s->budget--) { s->failed_pc=0x0c0a2daeu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2db0;
P_0c0a2db0: /* original f336, guest PC 0x0c0a2db0 */
if(!s->budget--) { s->failed_pc=0x0c0a2db0u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2db2;
P_0c0a2db2: /* original f342, guest PC 0x0c0a2db2 */
if(!s->budget--) { s->failed_pc=0x0c0a2db2u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2db4;
P_0c0a2db4: /* original f337, guest PC 0x0c0a2db4 */
if(!s->budget--) { s->failed_pc=0x0c0a2db4u; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2db6;
P_0c0a2db6: /* original e01c, guest PC 0x0c0a2db6 */
if(!s->budget--) { s->failed_pc=0x0c0a2db6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0a2db8;
P_0c0a2db8: /* original 53e1, guest PC 0x0c0a2db8 */
if(!s->budget--) { s->failed_pc=0x0c0a2db8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0a2dba;
P_0c0a2dba: /* original f336, guest PC 0x0c0a2dba */
if(!s->budget--) { s->failed_pc=0x0c0a2dbau; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0a2dbc;
P_0c0a2dbc: /* original f342, guest PC 0x0c0a2dbc */
if(!s->budget--) { s->failed_pc=0x0c0a2dbcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c0a2dbe;
P_0c0a2dbe: /* original f337, guest PC 0x0c0a2dbe */
if(!s->budget--) { s->failed_pc=0x0c0a2dbeu; return 0; }
vf3_matrix_store(s,ram,3,r[3]+r[0]);
goto P_0c0a2dc0;
P_0c0a2dc0: /* original 53eb, guest PC 0x0c0a2dc0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc0u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc2;
P_0c0a2dc2: /* original 2338, guest PC 0x0c0a2dc2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a2dc4;
P_0c0a2dc4: /* original 8908, guest PC 0x0c0a2dc4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dc6;
P_0c0a2dc6: /* original 53eb, guest PC 0x0c0a2dc6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc6u; return 0; }
r[3]=read(ram,r[14]+44,4);
goto P_0c0a2dc8;
P_0c0a2dc8: /* original 33d2, guest PC 0x0c0a2dc8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dc8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2dca;
P_0c0a2dca: /* original 8905, guest PC 0x0c0a2dca */
if(!s->budget--) { s->failed_pc=0x0c0a2dcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2dd8; }
goto P_0c0a2dcc;
P_0c0a2dcc: /* original 51eb, guest PC 0x0c0a2dcc */
if(!s->budget--) { s->failed_pc=0x0c0a2dccu; return 0; }
r[1]=read(ram,r[14]+44,4);
goto P_0c0a2dce;
P_0c0a2dce: /* original 65d3, guest PC 0x0c0a2dce */
if(!s->budget--) { s->failed_pc=0x0c0a2dceu; return 0; }
r[5]=r[13];
goto P_0c0a2dd0;
P_0c0a2dd0: /* original 31dc, guest PC 0x0c0a2dd0 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd0u; return 0; }
r[1]+=r[13];
goto P_0c0a2dd2;
P_0c0a2dd2: /* original 1e1b, guest PC 0x0c0a2dd2 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd2u; return 0; }
write(ram,r[14]+44,r[1],4);
goto P_0c0a2dd4;
P_0c0a2dd4: /* original bfb8, guest PC 0x0c0a2dd4 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd4u; return 0; }
target=code_base|0x0c0a2d48u; r[16]=code_base|0x0c0a2dd8u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a2dd8u) { target=s->pc; goto dispatch; }
goto P_0c0a2dd8;
P_0c0a2dd6: /* original 6413, guest PC 0x0c0a2dd6 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd6u; return 0; }
r[4]=r[1];
goto P_0c0a2dd8;
P_0c0a2dd8: /* original 52ec, guest PC 0x0c0a2dd8 */
if(!s->budget--) { s->failed_pc=0x0c0a2dd8u; return 0; }
r[2]=read(ram,r[14]+48,4);
goto P_0c0a2dda;
P_0c0a2dda: /* original 2228, guest PC 0x0c0a2dda */
if(!s->budget--) { s->failed_pc=0x0c0a2ddau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a2ddc;
P_0c0a2ddc: /* original 8908, guest PC 0x0c0a2ddc */
if(!s->budget--) { s->failed_pc=0x0c0a2ddcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2dde;
P_0c0a2dde: /* original 53ec, guest PC 0x0c0a2dde */
if(!s->budget--) { s->failed_pc=0x0c0a2ddeu; return 0; }
r[3]=read(ram,r[14]+48,4);
goto P_0c0a2de0;
P_0c0a2de0: /* original 33d2, guest PC 0x0c0a2de0 */
if(!s->budget--) { s->failed_pc=0x0c0a2de0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[13])!=0);
goto P_0c0a2de2;
P_0c0a2de2: /* original 8905, guest PC 0x0c0a2de2 */
if(!s->budget--) { s->failed_pc=0x0c0a2de2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a2df0; }
goto P_0c0a2de4;
P_0c0a2de4: /* original 51ec, guest PC 0x0c0a2de4 */
if(!s->budget--) { s->failed_pc=0x0c0a2de4u; return 0; }
r[1]=read(ram,r[14]+48,4);
goto P_0c0a2de6;
P_0c0a2de6: /* original 64d3, guest PC 0x0c0a2de6 */
if(!s->budget--) { s->failed_pc=0x0c0a2de6u; return 0; }
r[4]=r[13];
goto P_0c0a2de8;
P_0c0a2de8: /* original 31dc, guest PC 0x0c0a2de8 */
if(!s->budget--) { s->failed_pc=0x0c0a2de8u; return 0; }
r[1]+=r[13];
goto P_0c0a2dea;
P_0c0a2dea: /* original 1e1c, guest PC 0x0c0a2dea */
if(!s->budget--) { s->failed_pc=0x0c0a2deau; return 0; }
write(ram,r[14]+48,r[1],4);
goto P_0c0a2dec;
P_0c0a2dec: /* original afb1, guest PC 0x0c0a2dec */
if(!s->budget--) { s->failed_pc=0x0c0a2decu; return 0; }
r[14]=r[1];
goto P_0c0a2d52;
P_0c0a2dee: /* original 6e13, guest PC 0x0c0a2dee */
if(!s->budget--) { s->failed_pc=0x0c0a2deeu; return 0; }
r[14]=r[1];
goto P_0c0a2df0;
P_0c0a2df0: /* original 4f26, guest PC 0x0c0a2df0 */
if(!s->budget--) { s->failed_pc=0x0c0a2df0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a2df2;
P_0c0a2df2: /* original 6df6, guest PC 0x0c0a2df2 */
if(!s->budget--) { s->failed_pc=0x0c0a2df2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a2df4;
P_0c0a2df4: /* original 000b, guest PC 0x0c0a2df4 */
if(!s->budget--) { s->failed_pc=0x0c0a2df4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a2df6: /* original 6ef6, guest PC 0x0c0a2df6 */
if(!s->budget--) { s->failed_pc=0x0c0a2df6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a2df8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a2df8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
