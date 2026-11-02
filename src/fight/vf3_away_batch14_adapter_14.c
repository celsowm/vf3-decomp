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
int vf3_away_batch14_adapter_14(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c087bf8u: goto P_0c087bf8;
case 0x0c087bfau: goto P_0c087bfa;
case 0x0c087bfcu: goto P_0c087bfc;
case 0x0c087bfeu: goto P_0c087bfe;
case 0x0c087c00u: goto P_0c087c00;
case 0x0c087c02u: goto P_0c087c02;
case 0x0c087c04u: goto P_0c087c04;
case 0x0c087c06u: goto P_0c087c06;
case 0x0c087c08u: goto P_0c087c08;
case 0x0c087c0au: goto P_0c087c0a;
case 0x0c087c0cu: goto P_0c087c0c;
case 0x0c087c0eu: goto P_0c087c0e;
case 0x0c087c10u: goto P_0c087c10;
case 0x0c087c12u: goto P_0c087c12;
case 0x0c087c14u: goto P_0c087c14;
case 0x0c087c16u: goto P_0c087c16;
case 0x0c087c18u: goto P_0c087c18;
case 0x0c087c1au: goto P_0c087c1a;
case 0x0c087c1cu: goto P_0c087c1c;
case 0x0c087c1eu: goto P_0c087c1e;
case 0x0c087c20u: goto P_0c087c20;
case 0x0c087c22u: goto P_0c087c22;
case 0x0c087c24u: goto P_0c087c24;
case 0x0c087c26u: goto P_0c087c26;
case 0x0c087c28u: goto P_0c087c28;
case 0x0c087c2au: goto P_0c087c2a;
case 0x0c087c2cu: goto P_0c087c2c;
case 0x0c087c2eu: goto P_0c087c2e;
case 0x0c087c30u: goto P_0c087c30;
case 0x0c087c32u: goto P_0c087c32;
case 0x0c087c34u: goto P_0c087c34;
case 0x0c087c36u: goto P_0c087c36;
case 0x0c087c38u: goto P_0c087c38;
case 0x0c087c3au: goto P_0c087c3a;
case 0x0c087c3cu: goto P_0c087c3c;
case 0x0c087c3eu: goto P_0c087c3e;
case 0x0c087c40u: goto P_0c087c40;
case 0x0c087c42u: goto P_0c087c42;
case 0x0c087c44u: goto P_0c087c44;
case 0x0c087c46u: goto P_0c087c46;
case 0x0c087c48u: goto P_0c087c48;
case 0x0c087c4au: goto P_0c087c4a;
case 0x0c087c4cu: goto P_0c087c4c;
case 0x0c087c4eu: goto P_0c087c4e;
case 0x0c087c50u: goto P_0c087c50;
case 0x0c087c52u: goto P_0c087c52;
case 0x0c087c54u: goto P_0c087c54;
case 0x0c087c56u: goto P_0c087c56;
case 0x0c087c58u: goto P_0c087c58;
case 0x0c087c5au: goto P_0c087c5a;
case 0x0c087c5cu: goto P_0c087c5c;
case 0x0c087c5eu: goto P_0c087c5e;
case 0x0c087c60u: goto P_0c087c60;
case 0x0c087c62u: goto P_0c087c62;
case 0x0c087c64u: goto P_0c087c64;
case 0x0c087c66u: goto P_0c087c66;
case 0x0c087c68u: goto P_0c087c68;
case 0x0c087c6au: goto P_0c087c6a;
case 0x0c087c6cu: goto P_0c087c6c;
case 0x0c087c6eu: goto P_0c087c6e;
case 0x0c087c70u: goto P_0c087c70;
case 0x0c087c72u: goto P_0c087c72;
case 0x0c087c74u: goto P_0c087c74;
case 0x0c087c76u: goto P_0c087c76;
case 0x0c087c78u: goto P_0c087c78;
case 0x0c087c7au: goto P_0c087c7a;
case 0x0c087c7cu: goto P_0c087c7c;
case 0x0c087c7eu: goto P_0c087c7e;
case 0x0c087c80u: goto P_0c087c80;
case 0x0c087c82u: goto P_0c087c82;
case 0x0c087c84u: goto P_0c087c84;
case 0x0c087c86u: goto P_0c087c86;
case 0x0c087c88u: goto P_0c087c88;
case 0x0c087c8au: goto P_0c087c8a;
case 0x0c087c8cu: goto P_0c087c8c;
case 0x0c087c8eu: goto P_0c087c8e;
case 0x0c087c90u: goto P_0c087c90;
case 0x0c087c92u: goto P_0c087c92;
case 0x0c087c94u: goto P_0c087c94;
case 0x0c087c96u: goto P_0c087c96;
case 0x0c087c98u: goto P_0c087c98;
case 0x0c087c9au: goto P_0c087c9a;
case 0x0c087c9cu: goto P_0c087c9c;
case 0x0c087c9eu: goto P_0c087c9e;
case 0x0c087ca0u: goto P_0c087ca0;
case 0x0c087ca2u: goto P_0c087ca2;
case 0x0c087ca4u: goto P_0c087ca4;
case 0x0c087ca6u: goto P_0c087ca6;
case 0x0c087ca8u: goto P_0c087ca8;
case 0x0c087caau: goto P_0c087caa;
case 0x0c087cacu: goto P_0c087cac;
case 0x0c087caeu: goto P_0c087cae;
case 0x0c087cb0u: goto P_0c087cb0;
case 0x0c087cb2u: goto P_0c087cb2;
case 0x0c087cb4u: goto P_0c087cb4;
case 0x0c087cb6u: goto P_0c087cb6;
case 0x0c087cb8u: goto P_0c087cb8;
case 0x0c087cbau: goto P_0c087cba;
case 0x0c087cbcu: goto P_0c087cbc;
case 0x0c087cbeu: goto P_0c087cbe;
case 0x0c087cc0u: goto P_0c087cc0;
case 0x0c087cc2u: goto P_0c087cc2;
case 0x0c087cc4u: goto P_0c087cc4;
case 0x0c087cdcu: goto P_0c087cdc;
case 0x0c087cdeu: goto P_0c087cde;
case 0x0c087ce0u: goto P_0c087ce0;
case 0x0c087ce2u: goto P_0c087ce2;
case 0x0c087ce4u: goto P_0c087ce4;
case 0x0c087ce6u: goto P_0c087ce6;
case 0x0c087ce8u: goto P_0c087ce8;
case 0x0c087ceau: goto P_0c087cea;
case 0x0c087cecu: goto P_0c087cec;
case 0x0c087ceeu: goto P_0c087cee;
case 0x0c087cf0u: goto P_0c087cf0;
case 0x0c087cf2u: goto P_0c087cf2;
case 0x0c087cf4u: goto P_0c087cf4;
case 0x0c087cf6u: goto P_0c087cf6;
case 0x0c087cf8u: goto P_0c087cf8;
case 0x0c087cfau: goto P_0c087cfa;
case 0x0c087cfcu: goto P_0c087cfc;
case 0x0c087cfeu: goto P_0c087cfe;
case 0x0c087d00u: goto P_0c087d00;
case 0x0c087d02u: goto P_0c087d02;
case 0x0c087d04u: goto P_0c087d04;
case 0x0c087d06u: goto P_0c087d06;
case 0x0c087d08u: goto P_0c087d08;
case 0x0c087d0au: goto P_0c087d0a;
case 0x0c087d0cu: goto P_0c087d0c;
case 0x0c087d0eu: goto P_0c087d0e;
case 0x0c087d10u: goto P_0c087d10;
case 0x0c087d12u: goto P_0c087d12;
case 0x0c087d14u: goto P_0c087d14;
case 0x0c087d16u: goto P_0c087d16;
case 0x0c087d18u: goto P_0c087d18;
case 0x0c087d1au: goto P_0c087d1a;
case 0x0c087d1cu: goto P_0c087d1c;
case 0x0c087d1eu: goto P_0c087d1e;
case 0x0c087d20u: goto P_0c087d20;
case 0x0c087d22u: goto P_0c087d22;
case 0x0c087d24u: goto P_0c087d24;
case 0x0c087d26u: goto P_0c087d26;
case 0x0c087d28u: goto P_0c087d28;
case 0x0c087d2au: goto P_0c087d2a;
case 0x0c087d2cu: goto P_0c087d2c;
case 0x0c087d2eu: goto P_0c087d2e;
case 0x0c087d30u: goto P_0c087d30;
case 0x0c087d32u: goto P_0c087d32;
case 0x0c087d34u: goto P_0c087d34;
case 0x0c087d36u: goto P_0c087d36;
case 0x0c087d38u: goto P_0c087d38;
case 0x0c087d3au: goto P_0c087d3a;
case 0x0c087d3cu: goto P_0c087d3c;
case 0x0c087d3eu: goto P_0c087d3e;
case 0x0c087d40u: goto P_0c087d40;
case 0x0c087d42u: goto P_0c087d42;
case 0x0c087d44u: goto P_0c087d44;
case 0x0c087d46u: goto P_0c087d46;
case 0x0c087d48u: goto P_0c087d48;
case 0x0c087d4au: goto P_0c087d4a;
case 0x0c087d4cu: goto P_0c087d4c;
case 0x0c087d4eu: goto P_0c087d4e;
case 0x0c087d50u: goto P_0c087d50;
case 0x0c087d52u: goto P_0c087d52;
case 0x0c087d54u: goto P_0c087d54;
case 0x0c087d56u: goto P_0c087d56;
case 0x0c087d58u: goto P_0c087d58;
case 0x0c087d5au: goto P_0c087d5a;
case 0x0c087d5cu: goto P_0c087d5c;
case 0x0c087d5eu: goto P_0c087d5e;
case 0x0c087d60u: goto P_0c087d60;
case 0x0c087d62u: goto P_0c087d62;
case 0x0c087d64u: goto P_0c087d64;
case 0x0c087d66u: goto P_0c087d66;
case 0x0c087d68u: goto P_0c087d68;
case 0x0c087d6au: goto P_0c087d6a;
case 0x0c087d6cu: goto P_0c087d6c;
case 0x0c087d6eu: goto P_0c087d6e;
case 0x0c087d70u: goto P_0c087d70;
case 0x0c087d72u: goto P_0c087d72;
case 0x0c087d74u: goto P_0c087d74;
case 0x0c087d76u: goto P_0c087d76;
case 0x0c087d78u: goto P_0c087d78;
case 0x0c087d7au: goto P_0c087d7a;
case 0x0c087d7cu: goto P_0c087d7c;
case 0x0c087d7eu: goto P_0c087d7e;
case 0x0c087d80u: goto P_0c087d80;
case 0x0c087d82u: goto P_0c087d82;
case 0x0c087d84u: goto P_0c087d84;
case 0x0c087d86u: goto P_0c087d86;
case 0x0c087d88u: goto P_0c087d88;
case 0x0c087d8au: goto P_0c087d8a;
case 0x0c087d8cu: goto P_0c087d8c;
case 0x0c087d8eu: goto P_0c087d8e;
case 0x0c087d90u: goto P_0c087d90;
case 0x0c087d92u: goto P_0c087d92;
case 0x0c087d94u: goto P_0c087d94;
case 0x0c087d96u: goto P_0c087d96;
case 0x0c087d98u: goto P_0c087d98;
case 0x0c087d9au: goto P_0c087d9a;
case 0x0c087d9cu: goto P_0c087d9c;
case 0x0c087d9eu: goto P_0c087d9e;
case 0x0c087da0u: goto P_0c087da0;
case 0x0c087da2u: goto P_0c087da2;
case 0x0c087da4u: goto P_0c087da4;
case 0x0c087da6u: goto P_0c087da6;
case 0x0c087da8u: goto P_0c087da8;
case 0x0c087daau: goto P_0c087daa;
case 0x0c087dacu: goto P_0c087dac;
case 0x0c087daeu: goto P_0c087dae;
case 0x0c087db0u: goto P_0c087db0;
case 0x0c087db2u: goto P_0c087db2;
case 0x0c087db4u: goto P_0c087db4;
case 0x0c087db6u: goto P_0c087db6;
case 0x0c087db8u: goto P_0c087db8;
case 0x0c087dbau: goto P_0c087dba;
case 0x0c087dbcu: goto P_0c087dbc;
case 0x0c087dbeu: goto P_0c087dbe;
case 0x0c087dc0u: goto P_0c087dc0;
case 0x0c087dc2u: goto P_0c087dc2;
case 0x0c087dc4u: goto P_0c087dc4;
case 0x0c087dc6u: goto P_0c087dc6;
case 0x0c087dc8u: goto P_0c087dc8;
case 0x0c087dcau: goto P_0c087dca;
default: return vf3_matrix_family(target,s,ram);
}
P_0c087bf8: /* original 2fe6, guest PC 0x0c087bf8 */
if(!s->budget--) { s->failed_pc=0x0c087bf8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfa;
P_0c087bfa: /* original 2fd6, guest PC 0x0c087bfa */
if(!s->budget--) { s->failed_pc=0x0c087bfau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfc;
P_0c087bfc: /* original 2fc6, guest PC 0x0c087bfc */
if(!s->budget--) { s->failed_pc=0x0c087bfcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087bfe;
P_0c087bfe: /* original 2fb6, guest PC 0x0c087bfe */
if(!s->budget--) { s->failed_pc=0x0c087bfeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087c00;
P_0c087c00: /* original 2fa6, guest PC 0x0c087c00 */
if(!s->budget--) { s->failed_pc=0x0c087c00u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087c02;
P_0c087c02: /* original fffb, guest PC 0x0c087c02 */
if(!s->budget--) { s->failed_pc=0x0c087c02u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087c04;
P_0c087c04: /* original ffeb, guest PC 0x0c087c04 */
if(!s->budget--) { s->failed_pc=0x0c087c04u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c087c06;
P_0c087c06: /* original ffdb, guest PC 0x0c087c06 */
if(!s->budget--) { s->failed_pc=0x0c087c06u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c087c08;
P_0c087c08: /* original ffcb, guest PC 0x0c087c08 */
if(!s->budget--) { s->failed_pc=0x0c087c08u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c087c0a;
P_0c087c0a: /* original 905c, guest PC 0x0c087c0a */
if(!s->budget--) { s->failed_pc=0x0c087c0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087cc6u,2);
goto P_0c087c0c;
P_0c087c0c: /* original f38d, guest PC 0x0c087c0c */
if(!s->budget--) { s->failed_pc=0x0c087c0cu; return 0; }
fr[3]=0;
goto P_0c087c0e;
P_0c087c0e: /* original 0c4e, guest PC 0x0c087c0e */
if(!s->budget--) { s->failed_pc=0x0c087c0eu; return 0; }
r[12]=read(ram,r[4]+r[0],4);
goto P_0c087c10;
P_0c087c10: /* original 905a, guest PC 0x0c087c10 */
if(!s->budget--) { s->failed_pc=0x0c087c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087cc8u,2);
goto P_0c087c12;
P_0c087c12: /* original 4f22, guest PC 0x0c087c12 */
if(!s->budget--) { s->failed_pc=0x0c087c12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087c14;
P_0c087c14: /* original fe46, guest PC 0x0c087c14 */
if(!s->budget--) { s->failed_pc=0x0c087c14u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c087c16;
P_0c087c16: /* original c72d, guest PC 0x0c087c16 */
if(!s->budget--) { s->failed_pc=0x0c087c16u; return 0; }
r[0]=code_base|0x00087cccu;
goto P_0c087c18;
P_0c087c18: /* original f408, guest PC 0x0c087c18 */
if(!s->budget--) { s->failed_pc=0x0c087c18u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c087c1a;
P_0c087c1a: /* original f5ec, guest PC 0x0c087c1a */
if(!s->budget--) { s->failed_pc=0x0c087c1au; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c087c1c;
P_0c087c1c: /* original 7ffc, guest PC 0x0c087c1c */
if(!s->budget--) { s->failed_pc=0x0c087c1cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c087c1e;
P_0c087c1e: /* original f541, guest PC 0x0c087c1e */
if(!s->budget--) { s->failed_pc=0x0c087c1eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c087c20;
P_0c087c20: /* original f355, guest PC 0x0c087c20 */
if(!s->budget--) { s->failed_pc=0x0c087c20u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c087c22;
P_0c087c22: /* original 8900, guest PC 0x0c087c22 */
if(!s->budget--) { s->failed_pc=0x0c087c22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087c26; }
goto P_0c087c24;
P_0c087c24: /* original fe4c, guest PC 0x0c087c24 */
if(!s->budget--) { s->failed_pc=0x0c087c24u; return 0; }
vf3_matrix_move(s,14,4);
goto P_0c087c26;
P_0c087c26: /* original 9050, guest PC 0x0c087c26 */
if(!s->budget--) { s->failed_pc=0x0c087c26u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ccau,2);
goto P_0c087c28;
P_0c087c28: /* original 65c3, guest PC 0x0c087c28 */
if(!s->budget--) { s->failed_pc=0x0c087c28u; return 0; }
r[5]=r[12];
goto P_0c087c2a;
P_0c087c2a: /* original dd29, guest PC 0x0c087c2a */
if(!s->budget--) { s->failed_pc=0x0c087c2au; return 0; }
r[13]=read(ram,0x0c087cd0u,4);
goto P_0c087c2c;
P_0c087c2c: /* original e61c, guest PC 0x0c087c2c */
if(!s->budget--) { s->failed_pc=0x0c087c2cu; return 0; }
r[6]=0x0000001cu;
goto P_0c087c2e;
P_0c087c2e: /* original f68d, guest PC 0x0c087c2e */
if(!s->budget--) { s->failed_pc=0x0c087c2eu; return 0; }
fr[6]=0;
goto P_0c087c30;
P_0c087c30: /* original eefe, guest PC 0x0c087c30 */
if(!s->budget--) { s->failed_pc=0x0c087c30u; return 0; }
r[14]=0xfffffffeu;
goto P_0c087c32;
P_0c087c32: /* original 0b4e, guest PC 0x0c087c32 */
if(!s->budget--) { s->failed_pc=0x0c087c32u; return 0; }
r[11]=read(ram,r[4]+r[0],4);
goto P_0c087c34;
P_0c087c34: /* original e700, guest PC 0x0c087c34 */
if(!s->budget--) { s->failed_pc=0x0c087c34u; return 0; }
r[7]=0x00000000u;
goto P_0c087c36;
P_0c087c36: /* original f59d, guest PC 0x0c087c36 */
if(!s->budget--) { s->failed_pc=0x0c087c36u; return 0; }
fr[5]=0x3f800000u;
goto P_0c087c38;
P_0c087c38: /* original fd6c, guest PC 0x0c087c38 */
if(!s->budget--) { s->failed_pc=0x0c087c38u; return 0; }
vf3_matrix_move(s,13,6);
goto P_0c087c3a;
P_0c087c3a: /* original f46c, guest PC 0x0c087c3a */
if(!s->budget--) { s->failed_pc=0x0c087c3au; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c087c3c;
P_0c087c3c: /* original 6353, guest PC 0x0c087c3c */
if(!s->budget--) { s->failed_pc=0x0c087c3cu; return 0; }
r[3]=r[5];
goto P_0c087c3e;
P_0c087c3e: /* original 6a53, guest PC 0x0c087c3e */
if(!s->budget--) { s->failed_pc=0x0c087c3eu; return 0; }
r[10]=r[5];
goto P_0c087c40;
P_0c087c40: /* original 4300, guest PC 0x0c087c40 */
if(!s->budget--) { s->failed_pc=0x0c087c40u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c087c42;
P_0c087c42: /* original 2ad9, guest PC 0x0c087c42 */
if(!s->budget--) { s->failed_pc=0x0c087c42u; return 0; }
r[10]&=r[13];
goto P_0c087c44;
P_0c087c44: /* original 6533, guest PC 0x0c087c44 */
if(!s->budget--) { s->failed_pc=0x0c087c44u; return 0; }
r[5]=r[3];
goto P_0c087c46;
P_0c087c46: /* original 2aa8, guest PC 0x0c087c46 */
if(!s->budget--) { s->failed_pc=0x0c087c46u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c087c48;
P_0c087c48: /* original 8d02, guest PC 0x0c087c48 */
if(!s->budget--) { s->failed_pc=0x0c087c48u; return 0; }
cond=r[17]&1u;
r[5]&=r[14];
if(cond) { goto P_0c087c50; }
goto P_0c087c4c;
P_0c087c4a: /* original 25e9, guest PC 0x0c087c4a */
if(!s->budget--) { s->failed_pc=0x0c087c4au; return 0; }
r[5]&=r[14];
goto P_0c087c4c;
P_0c087c4c: /* original f450, guest PC 0x0c087c4c */
if(!s->budget--) { s->failed_pc=0x0c087c4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'+');
goto P_0c087c4e;
P_0c087c4e: /* original 7701, guest PC 0x0c087c4e */
if(!s->budget--) { s->failed_pc=0x0c087c4eu; return 0; }
r[7]+=0x00000001u;
goto P_0c087c50;
P_0c087c50: /* original 4610, guest PC 0x0c087c50 */
if(!s->budget--) { s->failed_pc=0x0c087c50u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c087c52;
P_0c087c52: /* original 8bf3, guest PC 0x0c087c52 */
if(!s->budget--) { s->failed_pc=0x0c087c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087c3c; }
goto P_0c087c54;
P_0c087c54: /* original 2778, guest PC 0x0c087c54 */
if(!s->budget--) { s->failed_pc=0x0c087c54u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c087c56;
P_0c087c56: /* original 892a, guest PC 0x0c087c56 */
if(!s->budget--) { s->failed_pc=0x0c087c56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087cae; }
goto P_0c087c58;
P_0c087c58: /* original bf92, guest PC 0x0c087c58 */
if(!s->budget--) { s->failed_pc=0x0c087c58u; return 0; }
target=code_base|0x0c087b80u; r[16]=code_base|0x0c087c5cu;
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087c5cu) { target=s->pc; goto dispatch; }
goto P_0c087c5c;
P_0c087c5a: /* original fe43, guest PC 0x0c087c5a */
if(!s->budget--) { s->failed_pc=0x0c087c5au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'/');
goto P_0c087c5c;
P_0c087c5c: /* original f40c, guest PC 0x0c087c5c */
if(!s->budget--) { s->failed_pc=0x0c087c5cu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c087c5e;
P_0c087c5e: /* original fe42, guest PC 0x0c087c5e */
if(!s->budget--) { s->failed_pc=0x0c087c5eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[4],r[18],'*');
goto P_0c087c60;
P_0c087c60: /* original ea1c, guest PC 0x0c087c60 */
if(!s->budget--) { s->failed_pc=0x0c087c60u; return 0; }
r[10]=0x0000001cu;
goto P_0c087c62;
P_0c087c62: /* original 62c3, guest PC 0x0c087c62 */
if(!s->budget--) { s->failed_pc=0x0c087c62u; return 0; }
r[2]=r[12];
goto P_0c087c64;
P_0c087c64: /* original 64c3, guest PC 0x0c087c64 */
if(!s->budget--) { s->failed_pc=0x0c087c64u; return 0; }
r[4]=r[12];
goto P_0c087c66;
P_0c087c66: /* original 4200, guest PC 0x0c087c66 */
if(!s->budget--) { s->failed_pc=0x0c087c66u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c087c68;
P_0c087c68: /* original 24d9, guest PC 0x0c087c68 */
if(!s->budget--) { s->failed_pc=0x0c087c68u; return 0; }
r[4]&=r[13];
goto P_0c087c6a;
P_0c087c6a: /* original 6c23, guest PC 0x0c087c6a */
if(!s->budget--) { s->failed_pc=0x0c087c6au; return 0; }
r[12]=r[2];
goto P_0c087c6c;
P_0c087c6c: /* original 2448, guest PC 0x0c087c6c */
if(!s->budget--) { s->failed_pc=0x0c087c6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087c6e;
P_0c087c6e: /* original 8d1c, guest PC 0x0c087c6e */
if(!s->budget--) { s->failed_pc=0x0c087c6eu; return 0; }
cond=r[17]&1u;
r[12]&=r[14];
if(cond) { goto P_0c087caa; }
goto P_0c087c72;
P_0c087c70: /* original 2ce9, guest PC 0x0c087c70 */
if(!s->budget--) { s->failed_pc=0x0c087c70u; return 0; }
r[12]&=r[14];
goto P_0c087c72;
P_0c087c72: /* original fcb9, guest PC 0x0c087c72 */
if(!s->budget--) { s->failed_pc=0x0c087c72u; return 0; }
vf3_matrix_load(s,ram,12,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c74;
P_0c087c74: /* original c717, guest PC 0x0c087c74 */
if(!s->budget--) { s->failed_pc=0x0c087c74u; return 0; }
r[0]=code_base|0x00087cd4u;
goto P_0c087c76;
P_0c087c76: /* original f3b9, guest PC 0x0c087c76 */
if(!s->budget--) { s->failed_pc=0x0c087c76u; return 0; }
vf3_matrix_load(s,ram,3,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c78;
P_0c087c78: /* original ff3a, guest PC 0x0c087c78 */
if(!s->budget--) { s->failed_pc=0x0c087c78u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c087c7a;
P_0c087c7a: /* original f308, guest PC 0x0c087c7a */
if(!s->budget--) { s->failed_pc=0x0c087c7au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087c7c;
P_0c087c7c: /* original ffb9, guest PC 0x0c087c7c */
if(!s->budget--) { s->failed_pc=0x0c087c7cu; return 0; }
vf3_matrix_load(s,ram,15,r[11]);
r[11]+=(r[18]&0x100000u)?8:4;
goto P_0c087c7e;
P_0c087c7e: /* original ff32, guest PC 0x0c087c7e */
if(!s->budget--) { s->failed_pc=0x0c087c7eu; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'*');
goto P_0c087c80;
P_0c087c80: /* original f5fc, guest PC 0x0c087c80 */
if(!s->budget--) { s->failed_pc=0x0c087c80u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c087c82;
P_0c087c82: /* original bedd, guest PC 0x0c087c82 */
if(!s->budget--) { s->failed_pc=0x0c087c82u; return 0; }
target=code_base|0x0c087a40u; r[16]=code_base|0x0c087c86u;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087c86u) { target=s->pc; goto dispatch; }
goto P_0c087c86;
P_0c087c84: /* original f4cc, guest PC 0x0c087c84 */
if(!s->budget--) { s->failed_pc=0x0c087c84u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c087c86;
P_0c087c86: /* original 6403, guest PC 0x0c087c86 */
if(!s->budget--) { s->failed_pc=0x0c087c86u; return 0; }
r[4]=r[0];
goto P_0c087c88;
P_0c087c88: /* original 2448, guest PC 0x0c087c88 */
if(!s->budget--) { s->failed_pc=0x0c087c88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c087c8a;
P_0c087c8a: /* original 890e, guest PC 0x0c087c8a */
if(!s->budget--) { s->failed_pc=0x0c087c8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c087caa; }
goto P_0c087c8c;
P_0c087c8c: /* original c712, guest PC 0x0c087c8c */
if(!s->budget--) { s->failed_pc=0x0c087c8cu; return 0; }
r[0]=code_base|0x00087cd8u;
goto P_0c087c8e;
P_0c087c8e: /* original f1fc, guest PC 0x0c087c8e */
if(!s->budget--) { s->failed_pc=0x0c087c8eu; return 0; }
vf3_matrix_move(s,1,15);
goto P_0c087c90;
P_0c087c90: /* original f308, guest PC 0x0c087c90 */
if(!s->budget--) { s->failed_pc=0x0c087c90u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087c92;
P_0c087c92: /* original e038, guest PC 0x0c087c92 */
if(!s->budget--) { s->failed_pc=0x0c087c92u; return 0; }
r[0]=0x00000038u;
goto P_0c087c94;
P_0c087c94: /* original f246, guest PC 0x0c087c94 */
if(!s->budget--) { s->failed_pc=0x0c087c94u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c087c96;
P_0c087c96: /* original f5f8, guest PC 0x0c087c96 */
if(!s->budget--) { s->failed_pc=0x0c087c96u; return 0; }
vf3_matrix_load(s,ram,5,r[15]);
goto P_0c087c98;
P_0c087c98: /* original f232, guest PC 0x0c087c98 */
if(!s->budget--) { s->failed_pc=0x0c087c98u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c087c9a;
P_0c087c9a: /* original f7dc, guest PC 0x0c087c9a */
if(!s->budget--) { s->failed_pc=0x0c087c9au; return 0; }
vf3_matrix_move(s,7,13);
goto P_0c087c9c;
P_0c087c9c: /* original f9dc, guest PC 0x0c087c9c */
if(!s->budget--) { s->failed_pc=0x0c087c9cu; return 0; }
vf3_matrix_move(s,9,13);
goto P_0c087c9e;
P_0c087c9e: /* original f8ec, guest PC 0x0c087c9e */
if(!s->budget--) { s->failed_pc=0x0c087c9eu; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c087ca0;
P_0c087ca0: /* original ff2c, guest PC 0x0c087ca0 */
if(!s->budget--) { s->failed_pc=0x0c087ca0u; return 0; }
vf3_matrix_move(s,15,2);
goto P_0c087ca2;
P_0c087ca2: /* original ff11, guest PC 0x0c087ca2 */
if(!s->budget--) { s->failed_pc=0x0c087ca2u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[1],r[18],'-');
goto P_0c087ca4;
P_0c087ca4: /* original f6fc, guest PC 0x0c087ca4 */
if(!s->budget--) { s->failed_pc=0x0c087ca4u; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c087ca6;
P_0c087ca6: /* original be1f, guest PC 0x0c087ca6 */
if(!s->budget--) { s->failed_pc=0x0c087ca6u; return 0; }
target=code_base|0x0c0878e8u; r[16]=code_base|0x0c087caau;
vf3_matrix_move(s,4,12);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087caau) { target=s->pc; goto dispatch; }
goto P_0c087caa;
P_0c087ca8: /* original f4cc, guest PC 0x0c087ca8 */
if(!s->budget--) { s->failed_pc=0x0c087ca8u; return 0; }
vf3_matrix_move(s,4,12);
goto P_0c087caa;
P_0c087caa: /* original 4a10, guest PC 0x0c087caa */
if(!s->budget--) { s->failed_pc=0x0c087caau; return 0; }
--r[10];
r[17]=(r[17]&~1u)|((r[10]==0)!=0);
goto P_0c087cac;
P_0c087cac: /* original 8bd9, guest PC 0x0c087cac */
if(!s->budget--) { s->failed_pc=0x0c087cacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c087c62; }
goto P_0c087cae;
P_0c087cae: /* original 7f04, guest PC 0x0c087cae */
if(!s->budget--) { s->failed_pc=0x0c087caeu; return 0; }
r[15]+=0x00000004u;
goto P_0c087cb0;
P_0c087cb0: /* original 4f26, guest PC 0x0c087cb0 */
if(!s->budget--) { s->failed_pc=0x0c087cb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087cb2;
P_0c087cb2: /* original fcf9, guest PC 0x0c087cb2 */
if(!s->budget--) { s->failed_pc=0x0c087cb2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb4;
P_0c087cb4: /* original fdf9, guest PC 0x0c087cb4 */
if(!s->budget--) { s->failed_pc=0x0c087cb4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb6;
P_0c087cb6: /* original fef9, guest PC 0x0c087cb6 */
if(!s->budget--) { s->failed_pc=0x0c087cb6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cb8;
P_0c087cb8: /* original fff9, guest PC 0x0c087cb8 */
if(!s->budget--) { s->failed_pc=0x0c087cb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087cba;
P_0c087cba: /* original 6af6, guest PC 0x0c087cba */
if(!s->budget--) { s->failed_pc=0x0c087cbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c087cbc;
P_0c087cbc: /* original 6bf6, guest PC 0x0c087cbc */
if(!s->budget--) { s->failed_pc=0x0c087cbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087cbe;
P_0c087cbe: /* original 6cf6, guest PC 0x0c087cbe */
if(!s->budget--) { s->failed_pc=0x0c087cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087cc0;
P_0c087cc0: /* original 6df6, guest PC 0x0c087cc0 */
if(!s->budget--) { s->failed_pc=0x0c087cc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087cc2;
P_0c087cc2: /* original 000b, guest PC 0x0c087cc2 */
if(!s->budget--) { s->failed_pc=0x0c087cc2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087cc4: /* original 6ef6, guest PC 0x0c087cc4 */
if(!s->budget--) { s->failed_pc=0x0c087cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c087cc6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087cc6u; return 0; } return 1;
P_0c087cdc: /* original 2fe6, guest PC 0x0c087cdc */
if(!s->budget--) { s->failed_pc=0x0c087cdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087cde;
P_0c087cde: /* original 2fd6, guest PC 0x0c087cde */
if(!s->budget--) { s->failed_pc=0x0c087cdeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce0;
P_0c087ce0: /* original 2fc6, guest PC 0x0c087ce0 */
if(!s->budget--) { s->failed_pc=0x0c087ce0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce2;
P_0c087ce2: /* original 6c43, guest PC 0x0c087ce2 */
if(!s->budget--) { s->failed_pc=0x0c087ce2u; return 0; }
r[12]=r[4];
goto P_0c087ce4;
P_0c087ce4: /* original 2fb6, guest PC 0x0c087ce4 */
if(!s->budget--) { s->failed_pc=0x0c087ce4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce6;
P_0c087ce6: /* original 2fa6, guest PC 0x0c087ce6 */
if(!s->budget--) { s->failed_pc=0x0c087ce6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087ce8;
P_0c087ce8: /* original 2f96, guest PC 0x0c087ce8 */
if(!s->budget--) { s->failed_pc=0x0c087ce8u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087cea;
P_0c087cea: /* original 2f86, guest PC 0x0c087cea */
if(!s->budget--) { s->failed_pc=0x0c087ceau; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c087cec;
P_0c087cec: /* original fffb, guest PC 0x0c087cec */
if(!s->budget--) { s->failed_pc=0x0c087cecu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c087cee;
P_0c087cee: /* original ffeb, guest PC 0x0c087cee */
if(!s->budget--) { s->failed_pc=0x0c087ceeu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c087cf0;
P_0c087cf0: /* original 9e6c, guest PC 0x0c087cf0 */
if(!s->budget--) { s->failed_pc=0x0c087cf0u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dccu,2);
goto P_0c087cf2;
P_0c087cf2: /* original 4f22, guest PC 0x0c087cf2 */
if(!s->budget--) { s->failed_pc=0x0c087cf2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c087cf4;
P_0c087cf4: /* original dd3a, guest PC 0x0c087cf4 */
if(!s->budget--) { s->failed_pc=0x0c087cf4u; return 0; }
r[13]=read(ram,0x0c087de0u,4);
goto P_0c087cf6;
P_0c087cf6: /* original 3ecc, guest PC 0x0c087cf6 */
if(!s->budget--) { s->failed_pc=0x0c087cf6u; return 0; }
r[14]+=r[12];
goto P_0c087cf8;
P_0c087cf8: /* original d33a, guest PC 0x0c087cf8 */
if(!s->budget--) { s->failed_pc=0x0c087cf8u; return 0; }
r[3]=read(ram,0x0c087de4u,4);
goto P_0c087cfa;
P_0c087cfa: /* original 430b, guest PC 0x0c087cfa */
if(!s->budget--) { s->failed_pc=0x0c087cfau; return 0; }
target=r[3];
r[16]=code_base|0x0c087cfeu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087cfeu) { target=s->pc; goto dispatch; }
goto P_0c087cfe;
P_0c087cfc: /* original e400, guest PC 0x0c087cfc */
if(!s->budget--) { s->failed_pc=0x0c087cfcu; return 0; }
r[4]=0x00000000u;
goto P_0c087cfe;
P_0c087cfe: /* original da3b, guest PC 0x0c087cfe */
if(!s->budget--) { s->failed_pc=0x0c087cfeu; return 0; }
r[10]=read(ram,0x0c087decu,4);
goto P_0c087d00;
P_0c087d00: /* original e908, guest PC 0x0c087d00 */
if(!s->budget--) { s->failed_pc=0x0c087d00u; return 0; }
r[9]=0x00000008u;
goto P_0c087d02;
P_0c087d02: /* original db3b, guest PC 0x0c087d02 */
if(!s->budget--) { s->failed_pc=0x0c087d02u; return 0; }
r[11]=read(ram,0x0c087df0u,4);
goto P_0c087d04;
P_0c087d04: /* original d838, guest PC 0x0c087d04 */
if(!s->budget--) { s->failed_pc=0x0c087d04u; return 0; }
r[8]=read(ram,0x0c087de8u,4);
goto P_0c087d06;
P_0c087d06: /* original ff8d, guest PC 0x0c087d06 */
if(!s->budget--) { s->failed_pc=0x0c087d06u; return 0; }
fr[15]=0;
goto P_0c087d08;
P_0c087d08: /* original fe9d, guest PC 0x0c087d08 */
if(!s->budget--) { s->failed_pc=0x0c087d08u; return 0; }
fr[14]=0x3f800000u;
goto P_0c087d0a;
P_0c087d0a: /* original 4b0b, guest PC 0x0c087d0a */
if(!s->budget--) { s->failed_pc=0x0c087d0au; return 0; }
target=r[11];
r[16]=code_base|0x0c087d0eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d0eu) { target=s->pc; goto dispatch; }
goto P_0c087d0e;
P_0c087d0c: /* original 0009, guest PC 0x0c087d0c */
if(!s->budget--) { s->failed_pc=0x0c087d0cu; return 0; }
goto P_0c087d0e;
P_0c087d0e: /* original e004, guest PC 0x0c087d0e */
if(!s->budget--) { s->failed_pc=0x0c087d0eu; return 0; }
r[0]=0x00000004u;
goto P_0c087d10;
P_0c087d10: /* original f4d8, guest PC 0x0c087d10 */
if(!s->budget--) { s->failed_pc=0x0c087d10u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c087d12;
P_0c087d12: /* original f5d6, guest PC 0x0c087d12 */
if(!s->budget--) { s->failed_pc=0x0c087d12u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c087d14;
P_0c087d14: /* original e008, guest PC 0x0c087d14 */
if(!s->budget--) { s->failed_pc=0x0c087d14u; return 0; }
r[0]=0x00000008u;
goto P_0c087d16;
P_0c087d16: /* original f6d6, guest PC 0x0c087d16 */
if(!s->budget--) { s->failed_pc=0x0c087d16u; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c087d18;
P_0c087d18: /* original 9059, guest PC 0x0c087d18 */
if(!s->budget--) { s->failed_pc=0x0c087d18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dceu,2);
goto P_0c087d1a;
P_0c087d1a: /* original fe47, guest PC 0x0c087d1a */
if(!s->budget--) { s->failed_pc=0x0c087d1au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c087d1c;
P_0c087d1c: /* original 7004, guest PC 0x0c087d1c */
if(!s->budget--) { s->failed_pc=0x0c087d1cu; return 0; }
r[0]+=0x00000004u;
goto P_0c087d1e;
P_0c087d1e: /* original fe57, guest PC 0x0c087d1e */
if(!s->budget--) { s->failed_pc=0x0c087d1eu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c087d20;
P_0c087d20: /* original 7004, guest PC 0x0c087d20 */
if(!s->budget--) { s->failed_pc=0x0c087d20u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d22;
P_0c087d22: /* original 480b, guest PC 0x0c087d22 */
if(!s->budget--) { s->failed_pc=0x0c087d22u; return 0; }
target=r[8];
r[16]=code_base|0x0c087d26u;
vf3_matrix_store(s,ram,6,r[14]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d26u) { target=s->pc; goto dispatch; }
goto P_0c087d26;
P_0c087d24: /* original fe67, guest PC 0x0c087d24 */
if(!s->budget--) { s->failed_pc=0x0c087d24u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c087d26;
P_0c087d26: /* original 4a0b, guest PC 0x0c087d26 */
if(!s->budget--) { s->failed_pc=0x0c087d26u; return 0; }
target=r[10];
r[16]=code_base|0x0c087d2au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d2au) { target=s->pc; goto dispatch; }
goto P_0c087d2a;
P_0c087d28: /* original 64e3, guest PC 0x0c087d28 */
if(!s->budget--) { s->failed_pc=0x0c087d28u; return 0; }
r[4]=r[14];
goto P_0c087d2a;
P_0c087d2a: /* original 4b0b, guest PC 0x0c087d2a */
if(!s->budget--) { s->failed_pc=0x0c087d2au; return 0; }
target=r[11];
r[16]=code_base|0x0c087d2eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d2eu) { target=s->pc; goto dispatch; }
goto P_0c087d2e;
P_0c087d2c: /* original 0009, guest PC 0x0c087d2c */
if(!s->budget--) { s->failed_pc=0x0c087d2cu; return 0; }
goto P_0c087d2e;
P_0c087d2e: /* original 64e3, guest PC 0x0c087d2e */
if(!s->budget--) { s->failed_pc=0x0c087d2eu; return 0; }
r[4]=r[14];
goto P_0c087d30;
P_0c087d30: /* original 4a0b, guest PC 0x0c087d30 */
if(!s->budget--) { s->failed_pc=0x0c087d30u; return 0; }
target=r[10];
r[16]=code_base|0x0c087d34u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d34u) { target=s->pc; goto dispatch; }
goto P_0c087d34;
P_0c087d32: /* original 7440, guest PC 0x0c087d32 */
if(!s->budget--) { s->failed_pc=0x0c087d32u; return 0; }
r[4]+=0x00000040u;
goto P_0c087d34;
P_0c087d34: /* original e00c, guest PC 0x0c087d34 */
if(!s->budget--) { s->failed_pc=0x0c087d34u; return 0; }
r[0]=0x0000000cu;
goto P_0c087d36;
P_0c087d36: /* original f3d6, guest PC 0x0c087d36 */
if(!s->budget--) { s->failed_pc=0x0c087d36u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d38;
P_0c087d38: /* original 4910, guest PC 0x0c087d38 */
if(!s->budget--) { s->failed_pc=0x0c087d38u; return 0; }
--r[9];
r[17]=(r[17]&~1u)|((r[9]==0)!=0);
goto P_0c087d3a;
P_0c087d3a: /* original 9049, guest PC 0x0c087d3a */
if(!s->budget--) { s->failed_pc=0x0c087d3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd0u,2);
goto P_0c087d3c;
P_0c087d3c: /* original fe37, guest PC 0x0c087d3c */
if(!s->budget--) { s->failed_pc=0x0c087d3cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d3e;
P_0c087d3e: /* original e010, guest PC 0x0c087d3e */
if(!s->budget--) { s->failed_pc=0x0c087d3eu; return 0; }
r[0]=0x00000010u;
goto P_0c087d40;
P_0c087d40: /* original f3d6, guest PC 0x0c087d40 */
if(!s->budget--) { s->failed_pc=0x0c087d40u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d42;
P_0c087d42: /* original 9046, guest PC 0x0c087d42 */
if(!s->budget--) { s->failed_pc=0x0c087d42u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd2u,2);
goto P_0c087d44;
P_0c087d44: /* original fe37, guest PC 0x0c087d44 */
if(!s->budget--) { s->failed_pc=0x0c087d44u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d46;
P_0c087d46: /* original e014, guest PC 0x0c087d46 */
if(!s->budget--) { s->failed_pc=0x0c087d46u; return 0; }
r[0]=0x00000014u;
goto P_0c087d48;
P_0c087d48: /* original f3d6, guest PC 0x0c087d48 */
if(!s->budget--) { s->failed_pc=0x0c087d48u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d4a;
P_0c087d4a: /* original 707c, guest PC 0x0c087d4a */
if(!s->budget--) { s->failed_pc=0x0c087d4au; return 0; }
r[0]+=0x0000007cu;
goto P_0c087d4c;
P_0c087d4c: /* original fe37, guest PC 0x0c087d4c */
if(!s->budget--) { s->failed_pc=0x0c087d4cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d4e;
P_0c087d4e: /* original e018, guest PC 0x0c087d4e */
if(!s->budget--) { s->failed_pc=0x0c087d4eu; return 0; }
r[0]=0x00000018u;
goto P_0c087d50;
P_0c087d50: /* original f3d6, guest PC 0x0c087d50 */
if(!s->budget--) { s->failed_pc=0x0c087d50u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c087d52;
P_0c087d52: /* original 707c, guest PC 0x0c087d52 */
if(!s->budget--) { s->failed_pc=0x0c087d52u; return 0; }
r[0]+=0x0000007cu;
goto P_0c087d54;
P_0c087d54: /* original fe37, guest PC 0x0c087d54 */
if(!s->budget--) { s->failed_pc=0x0c087d54u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c087d56;
P_0c087d56: /* original 913d, guest PC 0x0c087d56 */
if(!s->budget--) { s->failed_pc=0x0c087d56u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd4u,2);
goto P_0c087d58;
P_0c087d58: /* original 85de, guest PC 0x0c087d58 */
if(!s->budget--) { s->failed_pc=0x0c087d58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+28,2);
goto P_0c087d5a;
P_0c087d5a: /* original 7d20, guest PC 0x0c087d5a */
if(!s->budget--) { s->failed_pc=0x0c087d5au; return 0; }
r[13]+=0x00000020u;
goto P_0c087d5c;
P_0c087d5c: /* original 31ec, guest PC 0x0c087d5c */
if(!s->budget--) { s->failed_pc=0x0c087d5cu; return 0; }
r[1]+=r[14];
goto P_0c087d5e;
P_0c087d5e: /* original 2101, guest PC 0x0c087d5e */
if(!s->budget--) { s->failed_pc=0x0c087d5eu; return 0; }
write(ram,r[1],r[0],2);
goto P_0c087d60;
P_0c087d60: /* original 9039, guest PC 0x0c087d60 */
if(!s->budget--) { s->failed_pc=0x0c087d60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd6u,2);
goto P_0c087d62;
P_0c087d62: /* original fee7, guest PC 0x0c087d62 */
if(!s->budget--) { s->failed_pc=0x0c087d62u; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c087d64;
P_0c087d64: /* original 7004, guest PC 0x0c087d64 */
if(!s->budget--) { s->failed_pc=0x0c087d64u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d66;
P_0c087d66: /* original fef7, guest PC 0x0c087d66 */
if(!s->budget--) { s->failed_pc=0x0c087d66u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087d68;
P_0c087d68: /* original 7004, guest PC 0x0c087d68 */
if(!s->budget--) { s->failed_pc=0x0c087d68u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d6a;
P_0c087d6a: /* original fef7, guest PC 0x0c087d6a */
if(!s->budget--) { s->failed_pc=0x0c087d6au; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087d6c;
P_0c087d6c: /* original 7004, guest PC 0x0c087d6c */
if(!s->budget--) { s->failed_pc=0x0c087d6cu; return 0; }
r[0]+=0x00000004u;
goto P_0c087d6e;
P_0c087d6e: /* original fef7, guest PC 0x0c087d6e */
if(!s->budget--) { s->failed_pc=0x0c087d6eu; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c087d70;
P_0c087d70: /* original 9332, guest PC 0x0c087d70 */
if(!s->budget--) { s->failed_pc=0x0c087d70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087dd8u,2);
goto P_0c087d72;
P_0c087d72: /* original 8fca, guest PC 0x0c087d72 */
if(!s->budget--) { s->failed_pc=0x0c087d72u; return 0; }
cond=r[17]&1u;
r[14]+=r[3];
if(!cond) { goto P_0c087d0a; }
goto P_0c087d76;
P_0c087d74: /* original 3e3c, guest PC 0x0c087d74 */
if(!s->budget--) { s->failed_pc=0x0c087d74u; return 0; }
r[14]+=r[3];
goto P_0c087d76;
P_0c087d76: /* original d31f, guest PC 0x0c087d76 */
if(!s->budget--) { s->failed_pc=0x0c087d76u; return 0; }
r[3]=read(ram,0x0c087df4u,4);
goto P_0c087d78;
P_0c087d78: /* original 430b, guest PC 0x0c087d78 */
if(!s->budget--) { s->failed_pc=0x0c087d78u; return 0; }
target=r[3];
r[16]=code_base|0x0c087d7cu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c087d7cu) { target=s->pc; goto dispatch; }
goto P_0c087d7c;
P_0c087d7a: /* original e401, guest PC 0x0c087d7a */
if(!s->budget--) { s->failed_pc=0x0c087d7au; return 0; }
r[4]=0x00000001u;
goto P_0c087d7c;
P_0c087d7c: /* original c71e, guest PC 0x0c087d7c */
if(!s->budget--) { s->failed_pc=0x0c087d7cu; return 0; }
r[0]=code_base|0x00087df8u;
goto P_0c087d7e;
P_0c087d7e: /* original f308, guest PC 0x0c087d7e */
if(!s->budget--) { s->failed_pc=0x0c087d7eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087d80;
P_0c087d80: /* original e344, guest PC 0x0c087d80 */
if(!s->budget--) { s->failed_pc=0x0c087d80u; return 0; }
r[3]=0x00000044u;
goto P_0c087d82;
P_0c087d82: /* original 902a, guest PC 0x0c087d82 */
if(!s->budget--) { s->failed_pc=0x0c087d82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ddau,2);
goto P_0c087d84;
P_0c087d84: /* original e2f6, guest PC 0x0c087d84 */
if(!s->budget--) { s->failed_pc=0x0c087d84u; return 0; }
r[2]=0xfffffff6u;
goto P_0c087d86;
P_0c087d86: /* original e600, guest PC 0x0c087d86 */
if(!s->budget--) { s->failed_pc=0x0c087d86u; return 0; }
r[6]=0x00000000u;
goto P_0c087d88;
P_0c087d88: /* original fc37, guest PC 0x0c087d88 */
if(!s->budget--) { s->failed_pc=0x0c087d88u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c087d8a;
P_0c087d8a: /* original c71c, guest PC 0x0c087d8a */
if(!s->budget--) { s->failed_pc=0x0c087d8au; return 0; }
r[0]=code_base|0x00087dfcu;
goto P_0c087d8c;
P_0c087d8c: /* original f308, guest PC 0x0c087d8c */
if(!s->budget--) { s->failed_pc=0x0c087d8cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c087d8e;
P_0c087d8e: /* original 9025, guest PC 0x0c087d8e */
if(!s->budget--) { s->failed_pc=0x0c087d8eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ddcu,2);
goto P_0c087d90;
P_0c087d90: /* original 4f26, guest PC 0x0c087d90 */
if(!s->budget--) { s->failed_pc=0x0c087d90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c087d92;
P_0c087d92: /* original fc37, guest PC 0x0c087d92 */
if(!s->budget--) { s->failed_pc=0x0c087d92u; return 0; }
vf3_matrix_store(s,ram,3,r[12]+r[0]);
goto P_0c087d94;
P_0c087d94: /* original 7004, guest PC 0x0c087d94 */
if(!s->budget--) { s->failed_pc=0x0c087d94u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d96;
P_0c087d96: /* original 0c36, guest PC 0x0c087d96 */
if(!s->budget--) { s->failed_pc=0x0c087d96u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c087d98;
P_0c087d98: /* original 7004, guest PC 0x0c087d98 */
if(!s->budget--) { s->failed_pc=0x0c087d98u; return 0; }
r[0]+=0x00000004u;
goto P_0c087d9a;
P_0c087d9a: /* original 0c26, guest PC 0x0c087d9a */
if(!s->budget--) { s->failed_pc=0x0c087d9au; return 0; }
write(ram,r[12]+r[0],r[2],4);
goto P_0c087d9c;
P_0c087d9c: /* original 7004, guest PC 0x0c087d9c */
if(!s->budget--) { s->failed_pc=0x0c087d9cu; return 0; }
r[0]+=0x00000004u;
goto P_0c087d9e;
P_0c087d9e: /* original 0c66, guest PC 0x0c087d9e */
if(!s->budget--) { s->failed_pc=0x0c087d9eu; return 0; }
write(ram,r[12]+r[0],r[6],4);
goto P_0c087da0;
P_0c087da0: /* original d517, guest PC 0x0c087da0 */
if(!s->budget--) { s->failed_pc=0x0c087da0u; return 0; }
r[5]=read(ram,0x0c087e00u,4);
goto P_0c087da2;
P_0c087da2: /* original 901c, guest PC 0x0c087da2 */
if(!s->budget--) { s->failed_pc=0x0c087da2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c087ddeu,2);
goto P_0c087da4;
P_0c087da4: /* original 5454, guest PC 0x0c087da4 */
if(!s->budget--) { s->failed_pc=0x0c087da4u; return 0; }
r[4]=read(ram,r[5]+16,4);
goto P_0c087da6;
P_0c087da6: /* original 5555, guest PC 0x0c087da6 */
if(!s->budget--) { s->failed_pc=0x0c087da6u; return 0; }
r[5]=read(ram,r[5]+20,4);
goto P_0c087da8;
P_0c087da8: /* original f5f7, guest PC 0x0c087da8 */
if(!s->budget--) { s->failed_pc=0x0c087da8u; return 0; }
vf3_matrix_store(s,ram,15,r[5]+r[0]);
goto P_0c087daa;
P_0c087daa: /* original f4f7, guest PC 0x0c087daa */
if(!s->budget--) { s->failed_pc=0x0c087daau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c087dac;
P_0c087dac: /* original 70fc, guest PC 0x0c087dac */
if(!s->budget--) { s->failed_pc=0x0c087dacu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c087dae;
P_0c087dae: /* original f5f7, guest PC 0x0c087dae */
if(!s->budget--) { s->failed_pc=0x0c087daeu; return 0; }
vf3_matrix_store(s,ram,15,r[5]+r[0]);
goto P_0c087db0;
P_0c087db0: /* original f4f7, guest PC 0x0c087db0 */
if(!s->budget--) { s->failed_pc=0x0c087db0u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c087db2;
P_0c087db2: /* original 7008, guest PC 0x0c087db2 */
if(!s->budget--) { s->failed_pc=0x0c087db2u; return 0; }
r[0]+=0x00000008u;
goto P_0c087db4;
P_0c087db4: /* original 0566, guest PC 0x0c087db4 */
if(!s->budget--) { s->failed_pc=0x0c087db4u; return 0; }
write(ram,r[5]+r[0],r[6],4);
goto P_0c087db6;
P_0c087db6: /* original 0466, guest PC 0x0c087db6 */
if(!s->budget--) { s->failed_pc=0x0c087db6u; return 0; }
write(ram,r[4]+r[0],r[6],4);
goto P_0c087db8;
P_0c087db8: /* original fef9, guest PC 0x0c087db8 */
if(!s->budget--) { s->failed_pc=0x0c087db8u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087dba;
P_0c087dba: /* original fff9, guest PC 0x0c087dba */
if(!s->budget--) { s->failed_pc=0x0c087dbau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c087dbc;
P_0c087dbc: /* original 68f6, guest PC 0x0c087dbc */
if(!s->budget--) { s->failed_pc=0x0c087dbcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c087dbe;
P_0c087dbe: /* original 69f6, guest PC 0x0c087dbe */
if(!s->budget--) { s->failed_pc=0x0c087dbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c087dc0;
P_0c087dc0: /* original 6af6, guest PC 0x0c087dc0 */
if(!s->budget--) { s->failed_pc=0x0c087dc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c087dc2;
P_0c087dc2: /* original 6bf6, guest PC 0x0c087dc2 */
if(!s->budget--) { s->failed_pc=0x0c087dc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c087dc4;
P_0c087dc4: /* original 6cf6, guest PC 0x0c087dc4 */
if(!s->budget--) { s->failed_pc=0x0c087dc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c087dc6;
P_0c087dc6: /* original 6df6, guest PC 0x0c087dc6 */
if(!s->budget--) { s->failed_pc=0x0c087dc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c087dc8;
P_0c087dc8: /* original 000b, guest PC 0x0c087dc8 */
if(!s->budget--) { s->failed_pc=0x0c087dc8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c087dca: /* original 6ef6, guest PC 0x0c087dca */
if(!s->budget--) { s->failed_pc=0x0c087dcau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c087dccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c087dccu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
