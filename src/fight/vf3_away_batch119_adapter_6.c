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
int vf3_away_batch119_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a7f5au: goto P_0c0a7f5a;
case 0x0c0a7f5cu: goto P_0c0a7f5c;
case 0x0c0a7f5eu: goto P_0c0a7f5e;
case 0x0c0a7f60u: goto P_0c0a7f60;
case 0x0c0a7f62u: goto P_0c0a7f62;
case 0x0c0a7f64u: goto P_0c0a7f64;
case 0x0c0a7f66u: goto P_0c0a7f66;
case 0x0c0a7f68u: goto P_0c0a7f68;
case 0x0c0a7f6au: goto P_0c0a7f6a;
case 0x0c0a7f6cu: goto P_0c0a7f6c;
case 0x0c0a7f6eu: goto P_0c0a7f6e;
case 0x0c0a7f70u: goto P_0c0a7f70;
case 0x0c0a7f72u: goto P_0c0a7f72;
case 0x0c0a7f74u: goto P_0c0a7f74;
case 0x0c0a7f76u: goto P_0c0a7f76;
case 0x0c0a7f78u: goto P_0c0a7f78;
case 0x0c0a7f7au: goto P_0c0a7f7a;
case 0x0c0a7f7cu: goto P_0c0a7f7c;
case 0x0c0a7f7eu: goto P_0c0a7f7e;
case 0x0c0a7f80u: goto P_0c0a7f80;
case 0x0c0a7f82u: goto P_0c0a7f82;
case 0x0c0a7f84u: goto P_0c0a7f84;
case 0x0c0a7f86u: goto P_0c0a7f86;
case 0x0c0a7f88u: goto P_0c0a7f88;
case 0x0c0a7f8au: goto P_0c0a7f8a;
case 0x0c0a7f8cu: goto P_0c0a7f8c;
case 0x0c0a7f8eu: goto P_0c0a7f8e;
case 0x0c0a7f90u: goto P_0c0a7f90;
case 0x0c0a7f92u: goto P_0c0a7f92;
case 0x0c0a7f94u: goto P_0c0a7f94;
case 0x0c0a7f96u: goto P_0c0a7f96;
case 0x0c0a7f98u: goto P_0c0a7f98;
case 0x0c0a7f9au: goto P_0c0a7f9a;
case 0x0c0a7f9cu: goto P_0c0a7f9c;
case 0x0c0a7f9eu: goto P_0c0a7f9e;
case 0x0c0a7fa0u: goto P_0c0a7fa0;
case 0x0c0a7fa2u: goto P_0c0a7fa2;
case 0x0c0a7fa4u: goto P_0c0a7fa4;
case 0x0c0a7fc0u: goto P_0c0a7fc0;
case 0x0c0a7fc2u: goto P_0c0a7fc2;
case 0x0c0a7fc4u: goto P_0c0a7fc4;
case 0x0c0a7fc6u: goto P_0c0a7fc6;
case 0x0c0a7fc8u: goto P_0c0a7fc8;
case 0x0c0a7fcau: goto P_0c0a7fca;
case 0x0c0a7fccu: goto P_0c0a7fcc;
case 0x0c0a7fceu: goto P_0c0a7fce;
case 0x0c0a7fd0u: goto P_0c0a7fd0;
case 0x0c0a7fd2u: goto P_0c0a7fd2;
case 0x0c0a7fd4u: goto P_0c0a7fd4;
case 0x0c0a7fd6u: goto P_0c0a7fd6;
case 0x0c0a7fd8u: goto P_0c0a7fd8;
case 0x0c0a7fdau: goto P_0c0a7fda;
case 0x0c0a7fdcu: goto P_0c0a7fdc;
case 0x0c0a7fdeu: goto P_0c0a7fde;
case 0x0c0a7fe0u: goto P_0c0a7fe0;
case 0x0c0a7fe2u: goto P_0c0a7fe2;
case 0x0c0a7fe4u: goto P_0c0a7fe4;
case 0x0c0a7fe6u: goto P_0c0a7fe6;
case 0x0c0a7fe8u: goto P_0c0a7fe8;
case 0x0c0a7feau: goto P_0c0a7fea;
case 0x0c0a7fecu: goto P_0c0a7fec;
case 0x0c0a7feeu: goto P_0c0a7fee;
case 0x0c0a7ff0u: goto P_0c0a7ff0;
case 0x0c0a7ff2u: goto P_0c0a7ff2;
case 0x0c0a7ff4u: goto P_0c0a7ff4;
case 0x0c0a7ff6u: goto P_0c0a7ff6;
case 0x0c0a7ff8u: goto P_0c0a7ff8;
case 0x0c0a7ffau: goto P_0c0a7ffa;
case 0x0c0a7ffcu: goto P_0c0a7ffc;
case 0x0c0a7ffeu: goto P_0c0a7ffe;
case 0x0c0a8000u: goto P_0c0a8000;
case 0x0c0a8002u: goto P_0c0a8002;
case 0x0c0a8004u: goto P_0c0a8004;
case 0x0c0a8006u: goto P_0c0a8006;
case 0x0c0a8008u: goto P_0c0a8008;
case 0x0c0a800au: goto P_0c0a800a;
case 0x0c0a800cu: goto P_0c0a800c;
case 0x0c0a800eu: goto P_0c0a800e;
case 0x0c0a8010u: goto P_0c0a8010;
case 0x0c0a8012u: goto P_0c0a8012;
case 0x0c0a8014u: goto P_0c0a8014;
case 0x0c0a8016u: goto P_0c0a8016;
case 0x0c0a8018u: goto P_0c0a8018;
case 0x0c0a801au: goto P_0c0a801a;
case 0x0c0a801cu: goto P_0c0a801c;
case 0x0c0a801eu: goto P_0c0a801e;
case 0x0c0a8020u: goto P_0c0a8020;
case 0x0c0a8022u: goto P_0c0a8022;
case 0x0c0a8024u: goto P_0c0a8024;
case 0x0c0a8026u: goto P_0c0a8026;
case 0x0c0a8028u: goto P_0c0a8028;
case 0x0c0a802au: goto P_0c0a802a;
case 0x0c0a802cu: goto P_0c0a802c;
case 0x0c0a802eu: goto P_0c0a802e;
case 0x0c0a8030u: goto P_0c0a8030;
case 0x0c0a8032u: goto P_0c0a8032;
case 0x0c0a8034u: goto P_0c0a8034;
case 0x0c0a8036u: goto P_0c0a8036;
case 0x0c0a8038u: goto P_0c0a8038;
case 0x0c0a803au: goto P_0c0a803a;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a7f5a: /* original 2fe6, guest PC 0x0c0a7f5a */
if(!s->budget--) { s->failed_pc=0x0c0a7f5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5c;
P_0c0a7f5c: /* original 2fd6, guest PC 0x0c0a7f5c */
if(!s->budget--) { s->failed_pc=0x0c0a7f5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f5e;
P_0c0a7f5e: /* original 2fc6, guest PC 0x0c0a7f5e */
if(!s->budget--) { s->failed_pc=0x0c0a7f5eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f60;
P_0c0a7f60: /* original 2fb6, guest PC 0x0c0a7f60 */
if(!s->budget--) { s->failed_pc=0x0c0a7f60u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f62;
P_0c0a7f62: /* original 6b43, guest PC 0x0c0a7f62 */
if(!s->budget--) { s->failed_pc=0x0c0a7f62u; return 0; }
r[11]=r[4];
goto P_0c0a7f64;
P_0c0a7f64: /* original 2fa6, guest PC 0x0c0a7f64 */
if(!s->budget--) { s->failed_pc=0x0c0a7f64u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a7f66;
P_0c0a7f66: /* original e400, guest PC 0x0c0a7f66 */
if(!s->budget--) { s->failed_pc=0x0c0a7f66u; return 0; }
r[4]=0x00000000u;
goto P_0c0a7f68;
P_0c0a7f68: /* original 4f22, guest PC 0x0c0a7f68 */
if(!s->budget--) { s->failed_pc=0x0c0a7f68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7f6a;
P_0c0a7f6a: /* original 6e43, guest PC 0x0c0a7f6a */
if(!s->budget--) { s->failed_pc=0x0c0a7f6au; return 0; }
r[14]=r[4];
goto P_0c0a7f6c;
P_0c0a7f6c: /* original 7ff4, guest PC 0x0c0a7f6c */
if(!s->budget--) { s->failed_pc=0x0c0a7f6cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0a7f6e;
P_0c0a7f6e: /* original 1f52, guest PC 0x0c0a7f6e */
if(!s->budget--) { s->failed_pc=0x0c0a7f6eu; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c0a7f70;
P_0c0a7f70: /* original 9319, guest PC 0x0c0a7f70 */
if(!s->budget--) { s->failed_pc=0x0c0a7f70u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a7fa6u,2);
goto P_0c0a7f72;
P_0c0a7f72: /* original 3b33, guest PC 0x0c0a7f72 */
if(!s->budget--) { s->failed_pc=0x0c0a7f72u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c0a7f74;
P_0c0a7f74: /* original 8f03, guest PC 0x0c0a7f74 */
if(!s->budget--) { s->failed_pc=0x0c0a7f74u; return 0; }
cond=r[17]&1u;
r[10]=r[14];
if(!cond) { goto P_0c0a7f7e; }
goto P_0c0a7f78;
P_0c0a7f76: /* original 6ae3, guest PC 0x0c0a7f76 */
if(!s->budget--) { s->failed_pc=0x0c0a7f76u; return 0; }
r[10]=r[14];
goto P_0c0a7f78;
P_0c0a7f78: /* original de0d, guest PC 0x0c0a7f78 */
if(!s->budget--) { s->failed_pc=0x0c0a7f78u; return 0; }
r[14]=read(ram,0x0c0a7fb0u,4);
goto P_0c0a7f7a;
P_0c0a7f7a: /* original a056, guest PC 0x0c0a7f7a */
if(!s->budget--) { s->failed_pc=0x0c0a7f7au; return 0; }
goto P_0c0a802a;
P_0c0a7f7c: /* original 0009, guest PC 0x0c0a7f7c */
if(!s->budget--) { s->failed_pc=0x0c0a7f7cu; return 0; }
goto P_0c0a7f7e;
P_0c0a7f7e: /* original d00d, guest PC 0x0c0a7f7e */
if(!s->budget--) { s->failed_pc=0x0c0a7f7eu; return 0; }
r[0]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f80;
P_0c0a7f80: /* original 63b3, guest PC 0x0c0a7f80 */
if(!s->budget--) { s->failed_pc=0x0c0a7f80u; return 0; }
r[3]=r[11];
goto P_0c0a7f82;
P_0c0a7f82: /* original 4308, guest PC 0x0c0a7f82 */
if(!s->budget--) { s->failed_pc=0x0c0a7f82u; return 0; }
r[3]<<=2;
goto P_0c0a7f84;
P_0c0a7f84: /* original 023e, guest PC 0x0c0a7f84 */
if(!s->budget--) { s->failed_pc=0x0c0a7f84u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a7f86;
P_0c0a7f86: /* original 1f21, guest PC 0x0c0a7f86 */
if(!s->budget--) { s->failed_pc=0x0c0a7f86u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0a7f88;
P_0c0a7f88: /* original d30b, guest PC 0x0c0a7f88 */
if(!s->budget--) { s->failed_pc=0x0c0a7f88u; return 0; }
r[3]=read(ram,0x0c0a7fb8u,4);
goto P_0c0a7f8a;
P_0c0a7f8a: /* original e500, guest PC 0x0c0a7f8a */
if(!s->budget--) { s->failed_pc=0x0c0a7f8au; return 0; }
r[5]=0x00000000u;
goto P_0c0a7f8c;
P_0c0a7f8c: /* original 430b, guest PC 0x0c0a7f8c */
if(!s->budget--) { s->failed_pc=0x0c0a7f8cu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7f90u;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7f90u) { target=s->pc; goto dispatch; }
goto P_0c0a7f90;
P_0c0a7f8e: /* original 54f1, guest PC 0x0c0a7f8e */
if(!s->budget--) { s->failed_pc=0x0c0a7f8eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0a7f90;
P_0c0a7f90: /* original dc0a, guest PC 0x0c0a7f90 */
if(!s->budget--) { s->failed_pc=0x0c0a7f90u; return 0; }
r[12]=read(ram,0x0c0a7fbcu,4);
goto P_0c0a7f92;
P_0c0a7f92: /* original 6d03, guest PC 0x0c0a7f92 */
if(!s->budget--) { s->failed_pc=0x0c0a7f92u; return 0; }
r[13]=r[0];
goto P_0c0a7f94;
P_0c0a7f94: /* original 2dd8, guest PC 0x0c0a7f94 */
if(!s->budget--) { s->failed_pc=0x0c0a7f94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0a7f96;
P_0c0a7f96: /* original 8b13, guest PC 0x0c0a7f96 */
if(!s->budget--) { s->failed_pc=0x0c0a7f96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fc0; }
goto P_0c0a7f98;
P_0c0a7f98: /* original 64b3, guest PC 0x0c0a7f98 */
if(!s->budget--) { s->failed_pc=0x0c0a7f98u; return 0; }
r[4]=r[11];
goto P_0c0a7f9a;
P_0c0a7f9a: /* original d306, guest PC 0x0c0a7f9a */
if(!s->budget--) { s->failed_pc=0x0c0a7f9au; return 0; }
r[3]=read(ram,0x0c0a7fb4u,4);
goto P_0c0a7f9c;
P_0c0a7f9c: /* original eeff, guest PC 0x0c0a7f9c */
if(!s->budget--) { s->failed_pc=0x0c0a7f9cu; return 0; }
r[14]=0xffffffffu;
goto P_0c0a7f9e;
P_0c0a7f9e: /* original 4408, guest PC 0x0c0a7f9e */
if(!s->budget--) { s->failed_pc=0x0c0a7f9eu; return 0; }
r[4]<<=2;
goto P_0c0a7fa0;
P_0c0a7fa0: /* original e570, guest PC 0x0c0a7fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa0u; return 0; }
r[5]=0x00000070u;
goto P_0c0a7fa2;
P_0c0a7fa2: /* original a016, guest PC 0x0c0a7fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa2u; return 0; }
r[4]+=r[3];
goto P_0c0a7fd2;
P_0c0a7fa4: /* original 343c, guest PC 0x0c0a7fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fa4u; return 0; }
r[4]+=r[3];
if(!vf3_matrix_family(0x0c0a7fa6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7fa6u; return 0; } return 1;
P_0c0a7fc0: /* original d234, guest PC 0x0c0a7fc0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc0u; return 0; }
r[2]=read(ram,0x0c0a8094u,4);
goto P_0c0a7fc2;
P_0c0a7fc2: /* original 65f3, guest PC 0x0c0a7fc2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc2u; return 0; }
r[5]=r[15];
goto P_0c0a7fc4;
P_0c0a7fc4: /* original 420b, guest PC 0x0c0a7fc4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7fc8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fc8u) { target=s->pc; goto dispatch; }
goto P_0c0a7fc8;
P_0c0a7fc6: /* original 64d3, guest PC 0x0c0a7fc6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc6u; return 0; }
r[4]=r[13];
goto P_0c0a7fc8;
P_0c0a7fc8: /* original 63f2, guest PC 0x0c0a7fc8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fc8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0a7fca;
P_0c0a7fca: /* original 2338, guest PC 0x0c0a7fca */
if(!s->budget--) { s->failed_pc=0x0c0a7fcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0a7fcc;
P_0c0a7fcc: /* original 8b05, guest PC 0x0c0a7fcc */
if(!s->budget--) { s->failed_pc=0x0c0a7fccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7fda; }
goto P_0c0a7fce;
P_0c0a7fce: /* original e400, guest PC 0x0c0a7fce */
if(!s->budget--) { s->failed_pc=0x0c0a7fceu; return 0; }
r[4]=0x00000000u;
goto P_0c0a7fd0;
P_0c0a7fd0: /* original e571, guest PC 0x0c0a7fd0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd0u; return 0; }
r[5]=0x00000071u;
goto P_0c0a7fd2;
P_0c0a7fd2: /* original 4c0b, guest PC 0x0c0a7fd2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd2u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a7fd6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7fd6u) { target=s->pc; goto dispatch; }
goto P_0c0a7fd6;
P_0c0a7fd4: /* original 0009, guest PC 0x0c0a7fd4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd4u; return 0; }
goto P_0c0a7fd6;
P_0c0a7fd6: /* original a028, guest PC 0x0c0a7fd6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd6u; return 0; }
goto P_0c0a802a;
P_0c0a7fd8: /* original 0009, guest PC 0x0c0a7fd8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fd8u; return 0; }
goto P_0c0a7fda;
P_0c0a7fda: /* original 62f2, guest PC 0x0c0a7fda */
if(!s->budget--) { s->failed_pc=0x0c0a7fdau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0a7fdc;
P_0c0a7fdc: /* original 9356, guest PC 0x0c0a7fdc */
if(!s->budget--) { s->failed_pc=0x0c0a7fdcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808cu,2);
goto P_0c0a7fde;
P_0c0a7fde: /* original 9156, guest PC 0x0c0a7fde */
if(!s->budget--) { s->failed_pc=0x0c0a7fdeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a808eu,2);
goto P_0c0a7fe0;
P_0c0a7fe0: /* original 323c, guest PC 0x0c0a7fe0 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe0u; return 0; }
r[2]+=r[3];
goto P_0c0a7fe2;
P_0c0a7fe2: /* original 2219, guest PC 0x0c0a7fe2 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe2u; return 0; }
r[2]&=r[1];
goto P_0c0a7fe4;
P_0c0a7fe4: /* original 6523, guest PC 0x0c0a7fe4 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe4u; return 0; }
r[5]=r[2];
goto P_0c0a7fe6;
P_0c0a7fe6: /* original 4519, guest PC 0x0c0a7fe6 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe6u; return 0; }
r[5]>>=8;
goto P_0c0a7fe8;
P_0c0a7fe8: /* original 4509, guest PC 0x0c0a7fe8 */
if(!s->budget--) { s->failed_pc=0x0c0a7fe8u; return 0; }
r[5]>>=2;
goto P_0c0a7fea;
P_0c0a7fea: /* original 2f22, guest PC 0x0c0a7fea */
if(!s->budget--) { s->failed_pc=0x0c0a7feau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a7fec;
P_0c0a7fec: /* original 56f2, guest PC 0x0c0a7fec */
if(!s->budget--) { s->failed_pc=0x0c0a7fecu; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c0a7fee;
P_0c0a7fee: /* original 4501, guest PC 0x0c0a7fee */
if(!s->budget--) { s->failed_pc=0x0c0a7feeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c0a7ff0;
P_0c0a7ff0: /* original d329, guest PC 0x0c0a7ff0 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff0u; return 0; }
r[3]=read(ram,0x0c0a8098u,4);
goto P_0c0a7ff2;
P_0c0a7ff2: /* original 430b, guest PC 0x0c0a7ff2 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a7ff6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7ff6u) { target=s->pc; goto dispatch; }
goto P_0c0a7ff6;
P_0c0a7ff4: /* original 64d3, guest PC 0x0c0a7ff4 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff4u; return 0; }
r[4]=r[13];
goto P_0c0a7ff6;
P_0c0a7ff6: /* original 6403, guest PC 0x0c0a7ff6 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff6u; return 0; }
r[4]=r[0];
goto P_0c0a7ff8;
P_0c0a7ff8: /* original 4415, guest PC 0x0c0a7ff8 */
if(!s->budget--) { s->failed_pc=0x0c0a7ff8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>0)!=0);
goto P_0c0a7ffa;
P_0c0a7ffa: /* original 8901, guest PC 0x0c0a7ffa */
if(!s->budget--) { s->failed_pc=0x0c0a7ffau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8000; }
goto P_0c0a7ffc;
P_0c0a7ffc: /* original 4c0b, guest PC 0x0c0a7ffc */
if(!s->budget--) { s->failed_pc=0x0c0a7ffcu; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8000u;
r[5]=0x00000072u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8000u) { target=s->pc; goto dispatch; }
goto P_0c0a8000;
P_0c0a7ffe: /* original e572, guest PC 0x0c0a7ffe */
if(!s->budget--) { s->failed_pc=0x0c0a7ffeu; return 0; }
r[5]=0x00000072u;
goto P_0c0a8000;
P_0c0a8000: /* original d326, guest PC 0x0c0a8000 */
if(!s->budget--) { s->failed_pc=0x0c0a8000u; return 0; }
r[3]=read(ram,0x0c0a809cu,4);
goto P_0c0a8002;
P_0c0a8002: /* original 430b, guest PC 0x0c0a8002 */
if(!s->budget--) { s->failed_pc=0x0c0a8002u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a8006u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8006u) { target=s->pc; goto dispatch; }
goto P_0c0a8006;
P_0c0a8004: /* original 64d3, guest PC 0x0c0a8004 */
if(!s->budget--) { s->failed_pc=0x0c0a8004u; return 0; }
r[4]=r[13];
goto P_0c0a8006;
P_0c0a8006: /* original 6e03, guest PC 0x0c0a8006 */
if(!s->budget--) { s->failed_pc=0x0c0a8006u; return 0; }
r[14]=r[0];
goto P_0c0a8008;
P_0c0a8008: /* original 2ee8, guest PC 0x0c0a8008 */
if(!s->budget--) { s->failed_pc=0x0c0a8008u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0a800a;
P_0c0a800a: /* original 890b, guest PC 0x0c0a800a */
if(!s->budget--) { s->failed_pc=0x0c0a800au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a8024; }
goto P_0c0a800c;
P_0c0a800c: /* original e30a, guest PC 0x0c0a800c */
if(!s->budget--) { s->failed_pc=0x0c0a800cu; return 0; }
r[3]=0x0000000au;
goto P_0c0a800e;
P_0c0a800e: /* original 3a33, guest PC 0x0c0a800e */
if(!s->budget--) { s->failed_pc=0x0c0a800eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[3])!=0);
goto P_0c0a8010;
P_0c0a8010: /* original 8905, guest PC 0x0c0a8010 */
if(!s->budget--) { s->failed_pc=0x0c0a8010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a801e; }
goto P_0c0a8012;
P_0c0a8012: /* original d123, guest PC 0x0c0a8012 */
if(!s->budget--) { s->failed_pc=0x0c0a8012u; return 0; }
r[1]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8014;
P_0c0a8014: /* original 7a01, guest PC 0x0c0a8014 */
if(!s->budget--) { s->failed_pc=0x0c0a8014u; return 0; }
r[10]+=0x00000001u;
goto P_0c0a8016;
P_0c0a8016: /* original 410b, guest PC 0x0c0a8016 */
if(!s->budget--) { s->failed_pc=0x0c0a8016u; return 0; }
target=r[1];
r[16]=code_base|0x0c0a801au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a801au) { target=s->pc; goto dispatch; }
goto P_0c0a801a;
P_0c0a8018: /* original 64d3, guest PC 0x0c0a8018 */
if(!s->budget--) { s->failed_pc=0x0c0a8018u; return 0; }
r[4]=r[13];
goto P_0c0a801a;
P_0c0a801a: /* original afb5, guest PC 0x0c0a801a */
if(!s->budget--) { s->failed_pc=0x0c0a801au; return 0; }
goto P_0c0a7f88;
P_0c0a801c: /* original 0009, guest PC 0x0c0a801c */
if(!s->budget--) { s->failed_pc=0x0c0a801cu; return 0; }
goto P_0c0a801e;
P_0c0a801e: /* original e573, guest PC 0x0c0a801e */
if(!s->budget--) { s->failed_pc=0x0c0a801eu; return 0; }
r[5]=0x00000073u;
goto P_0c0a8020;
P_0c0a8020: /* original 4c0b, guest PC 0x0c0a8020 */
if(!s->budget--) { s->failed_pc=0x0c0a8020u; return 0; }
target=r[12];
r[16]=code_base|0x0c0a8024u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a8024u) { target=s->pc; goto dispatch; }
goto P_0c0a8024;
P_0c0a8022: /* original 64e3, guest PC 0x0c0a8022 */
if(!s->budget--) { s->failed_pc=0x0c0a8022u; return 0; }
r[4]=r[14];
goto P_0c0a8024;
P_0c0a8024: /* original d21e, guest PC 0x0c0a8024 */
if(!s->budget--) { s->failed_pc=0x0c0a8024u; return 0; }
r[2]=read(ram,0x0c0a80a0u,4);
goto P_0c0a8026;
P_0c0a8026: /* original 420b, guest PC 0x0c0a8026 */
if(!s->budget--) { s->failed_pc=0x0c0a8026u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a802au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a802au) { target=s->pc; goto dispatch; }
goto P_0c0a802a;
P_0c0a8028: /* original 64d3, guest PC 0x0c0a8028 */
if(!s->budget--) { s->failed_pc=0x0c0a8028u; return 0; }
r[4]=r[13];
goto P_0c0a802a;
P_0c0a802a: /* original 7f0c, guest PC 0x0c0a802a */
if(!s->budget--) { s->failed_pc=0x0c0a802au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0a802c;
P_0c0a802c: /* original 60e3, guest PC 0x0c0a802c */
if(!s->budget--) { s->failed_pc=0x0c0a802cu; return 0; }
r[0]=r[14];
goto P_0c0a802e;
P_0c0a802e: /* original 4f26, guest PC 0x0c0a802e */
if(!s->budget--) { s->failed_pc=0x0c0a802eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a8030;
P_0c0a8030: /* original 6af6, guest PC 0x0c0a8030 */
if(!s->budget--) { s->failed_pc=0x0c0a8030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0a8032;
P_0c0a8032: /* original 6bf6, guest PC 0x0c0a8032 */
if(!s->budget--) { s->failed_pc=0x0c0a8032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a8034;
P_0c0a8034: /* original 6cf6, guest PC 0x0c0a8034 */
if(!s->budget--) { s->failed_pc=0x0c0a8034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a8036;
P_0c0a8036: /* original 6df6, guest PC 0x0c0a8036 */
if(!s->budget--) { s->failed_pc=0x0c0a8036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a8038;
P_0c0a8038: /* original 000b, guest PC 0x0c0a8038 */
if(!s->budget--) { s->failed_pc=0x0c0a8038u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a803a: /* original 6ef6, guest PC 0x0c0a803a */
if(!s->budget--) { s->failed_pc=0x0c0a803au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a803cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a803cu; return 0; } return 1;
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
goto P_0c0c5d86;
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
return vf3_matrix_family(0x0c0c5dbau,s,ram);
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
return vf3_matrix_family(0x0c0c5dbau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
