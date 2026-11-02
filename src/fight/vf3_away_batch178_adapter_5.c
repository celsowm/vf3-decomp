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
int vf3_away_batch178_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c099c42u: goto P_0c099c42;
case 0x0c099c44u: goto P_0c099c44;
case 0x0c099c46u: goto P_0c099c46;
case 0x0c099c48u: goto P_0c099c48;
case 0x0c099c4au: goto P_0c099c4a;
case 0x0c099c4cu: goto P_0c099c4c;
case 0x0c099c4eu: goto P_0c099c4e;
case 0x0c099c50u: goto P_0c099c50;
case 0x0c099c52u: goto P_0c099c52;
case 0x0c099c54u: goto P_0c099c54;
case 0x0c099c56u: goto P_0c099c56;
case 0x0c099c58u: goto P_0c099c58;
case 0x0c099c5au: goto P_0c099c5a;
case 0x0c099c5cu: goto P_0c099c5c;
case 0x0c099c5eu: goto P_0c099c5e;
case 0x0c099c60u: goto P_0c099c60;
case 0x0c099c62u: goto P_0c099c62;
case 0x0c099c64u: goto P_0c099c64;
case 0x0c099c66u: goto P_0c099c66;
case 0x0c099c68u: goto P_0c099c68;
case 0x0c099c6au: goto P_0c099c6a;
case 0x0c099c6cu: goto P_0c099c6c;
case 0x0c099c6eu: goto P_0c099c6e;
case 0x0c099c70u: goto P_0c099c70;
case 0x0c099c72u: goto P_0c099c72;
case 0x0c099c74u: goto P_0c099c74;
case 0x0c099c76u: goto P_0c099c76;
case 0x0c099c78u: goto P_0c099c78;
case 0x0c099c7au: goto P_0c099c7a;
case 0x0c099c7cu: goto P_0c099c7c;
case 0x0c099c7eu: goto P_0c099c7e;
case 0x0c099c80u: goto P_0c099c80;
case 0x0c099c82u: goto P_0c099c82;
case 0x0c099cb0u: goto P_0c099cb0;
case 0x0c099cb2u: goto P_0c099cb2;
case 0x0c099cb4u: goto P_0c099cb4;
case 0x0c099cb6u: goto P_0c099cb6;
case 0x0c099cb8u: goto P_0c099cb8;
case 0x0c099cbau: goto P_0c099cba;
case 0x0c099cbcu: goto P_0c099cbc;
case 0x0c099cbeu: goto P_0c099cbe;
case 0x0c099cc0u: goto P_0c099cc0;
case 0x0c099cc2u: goto P_0c099cc2;
case 0x0c099cc4u: goto P_0c099cc4;
case 0x0c099cc6u: goto P_0c099cc6;
case 0x0c099cc8u: goto P_0c099cc8;
case 0x0c099ccau: goto P_0c099cca;
case 0x0c099cccu: goto P_0c099ccc;
case 0x0c099cceu: goto P_0c099cce;
case 0x0c099cd0u: goto P_0c099cd0;
case 0x0c099cd2u: goto P_0c099cd2;
case 0x0c099cd4u: goto P_0c099cd4;
case 0x0c099cd6u: goto P_0c099cd6;
case 0x0c099cd8u: goto P_0c099cd8;
case 0x0c099cdau: goto P_0c099cda;
case 0x0c099cdcu: goto P_0c099cdc;
case 0x0c099cdeu: goto P_0c099cde;
case 0x0c099ce0u: goto P_0c099ce0;
case 0x0c099ce2u: goto P_0c099ce2;
case 0x0c099ce4u: goto P_0c099ce4;
case 0x0c099ce6u: goto P_0c099ce6;
case 0x0c099ce8u: goto P_0c099ce8;
case 0x0c099ceau: goto P_0c099cea;
case 0x0c099cecu: goto P_0c099cec;
case 0x0c099ceeu: goto P_0c099cee;
case 0x0c099cf0u: goto P_0c099cf0;
case 0x0c099cf2u: goto P_0c099cf2;
case 0x0c099cf4u: goto P_0c099cf4;
case 0x0c099cf6u: goto P_0c099cf6;
case 0x0c099cf8u: goto P_0c099cf8;
case 0x0c099cfau: goto P_0c099cfa;
case 0x0c099cfcu: goto P_0c099cfc;
case 0x0c099cfeu: goto P_0c099cfe;
case 0x0c099d00u: goto P_0c099d00;
case 0x0c099d02u: goto P_0c099d02;
case 0x0c099d04u: goto P_0c099d04;
case 0x0c099d06u: goto P_0c099d06;
case 0x0c099d08u: goto P_0c099d08;
case 0x0c099d0au: goto P_0c099d0a;
case 0x0c099d0cu: goto P_0c099d0c;
case 0x0c099d0eu: goto P_0c099d0e;
case 0x0c099d10u: goto P_0c099d10;
case 0x0c099d12u: goto P_0c099d12;
case 0x0c099d14u: goto P_0c099d14;
case 0x0c099d16u: goto P_0c099d16;
case 0x0c099d18u: goto P_0c099d18;
case 0x0c099d1au: goto P_0c099d1a;
case 0x0c099d1cu: goto P_0c099d1c;
case 0x0c099d1eu: goto P_0c099d1e;
case 0x0c099d20u: goto P_0c099d20;
case 0x0c099d22u: goto P_0c099d22;
case 0x0c099d24u: goto P_0c099d24;
case 0x0c099d26u: goto P_0c099d26;
case 0x0c099d28u: goto P_0c099d28;
case 0x0c099d2au: goto P_0c099d2a;
case 0x0c099d2cu: goto P_0c099d2c;
case 0x0c099d2eu: goto P_0c099d2e;
case 0x0c099d30u: goto P_0c099d30;
case 0x0c099d32u: goto P_0c099d32;
case 0x0c099d34u: goto P_0c099d34;
case 0x0c099d36u: goto P_0c099d36;
case 0x0c099d38u: goto P_0c099d38;
case 0x0c099d3au: goto P_0c099d3a;
case 0x0c099d3cu: goto P_0c099d3c;
case 0x0c099d3eu: goto P_0c099d3e;
case 0x0c099d40u: goto P_0c099d40;
case 0x0c099d42u: goto P_0c099d42;
case 0x0c099d44u: goto P_0c099d44;
case 0x0c099d46u: goto P_0c099d46;
case 0x0c099d48u: goto P_0c099d48;
case 0x0c099d4au: goto P_0c099d4a;
case 0x0c099d4cu: goto P_0c099d4c;
case 0x0c099d4eu: goto P_0c099d4e;
case 0x0c099d50u: goto P_0c099d50;
case 0x0c099d52u: goto P_0c099d52;
case 0x0c099d54u: goto P_0c099d54;
case 0x0c099d56u: goto P_0c099d56;
case 0x0c099d58u: goto P_0c099d58;
case 0x0c099d5au: goto P_0c099d5a;
case 0x0c099d5cu: goto P_0c099d5c;
case 0x0c099d5eu: goto P_0c099d5e;
case 0x0c099d60u: goto P_0c099d60;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c099c42: /* original 2fe6, guest PC 0x0c099c42 */
if(!s->budget--) { s->failed_pc=0x0c099c42u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c44;
P_0c099c44: /* original 2fd6, guest PC 0x0c099c44 */
if(!s->budget--) { s->failed_pc=0x0c099c44u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c46;
P_0c099c46: /* original 2fc6, guest PC 0x0c099c46 */
if(!s->budget--) { s->failed_pc=0x0c099c46u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c48;
P_0c099c48: /* original 2fb6, guest PC 0x0c099c48 */
if(!s->budget--) { s->failed_pc=0x0c099c48u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099c4a;
P_0c099c4a: /* original dd14, guest PC 0x0c099c4a */
if(!s->budget--) { s->failed_pc=0x0c099c4au; return 0; }
r[13]=read(ram,0x0c099c9cu,4);
goto P_0c099c4c;
P_0c099c4c: /* original 4f22, guest PC 0x0c099c4c */
if(!s->budget--) { s->failed_pc=0x0c099c4cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099c4e;
P_0c099c4e: /* original d315, guest PC 0x0c099c4e */
if(!s->budget--) { s->failed_pc=0x0c099c4eu; return 0; }
r[3]=read(ram,0x0c099ca4u,4);
goto P_0c099c50;
P_0c099c50: /* original de13, guest PC 0x0c099c50 */
if(!s->budget--) { s->failed_pc=0x0c099c50u; return 0; }
r[14]=read(ram,0x0c099ca0u,4);
goto P_0c099c52;
P_0c099c52: /* original 7ffc, guest PC 0x0c099c52 */
if(!s->budget--) { s->failed_pc=0x0c099c52u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c099c54;
P_0c099c54: /* original 2f32, guest PC 0x0c099c54 */
if(!s->budget--) { s->failed_pc=0x0c099c54u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099c56;
P_0c099c56: /* original 9018, guest PC 0x0c099c56 */
if(!s->budget--) { s->failed_pc=0x0c099c56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c8au,2);
goto P_0c099c58;
P_0c099c58: /* original 0cde, guest PC 0x0c099c58 */
if(!s->budget--) { s->failed_pc=0x0c099c58u; return 0; }
r[12]=read(ram,r[13]+r[0],4);
goto P_0c099c5a;
P_0c099c5a: /* original 9017, guest PC 0x0c099c5a */
if(!s->budget--) { s->failed_pc=0x0c099c5au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c8cu,2);
goto P_0c099c5c;
P_0c099c5c: /* original 00ce, guest PC 0x0c099c5c */
if(!s->budget--) { s->failed_pc=0x0c099c5cu; return 0; }
r[0]=read(ram,r[12]+r[0],4);
goto P_0c099c5e;
P_0c099c5e: /* original c808, guest PC 0x0c099c5e */
if(!s->budget--) { s->failed_pc=0x0c099c5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c099c60;
P_0c099c60: /* original 8926, guest PC 0x0c099c60 */
if(!s->budget--) { s->failed_pc=0x0c099c60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099cb0; }
goto P_0c099c62;
P_0c099c62: /* original 53e3, guest PC 0x0c099c62 */
if(!s->budget--) { s->failed_pc=0x0c099c62u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c099c64;
P_0c099c64: /* original 9413, guest PC 0x0c099c64 */
if(!s->budget--) { s->failed_pc=0x0c099c64u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099c8eu,2);
goto P_0c099c66;
P_0c099c66: /* original 3347, guest PC 0x0c099c66 */
if(!s->budget--) { s->failed_pc=0x0c099c66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[4])!=0);
goto P_0c099c68;
P_0c099c68: /* original 893e, guest PC 0x0c099c68 */
if(!s->budget--) { s->failed_pc=0x0c099c68u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ce8; }
goto P_0c099c6a;
P_0c099c6a: /* original 52e3, guest PC 0x0c099c6a */
if(!s->budget--) { s->failed_pc=0x0c099c6au; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c099c6c;
P_0c099c6c: /* original 3243, guest PC 0x0c099c6c */
if(!s->budget--) { s->failed_pc=0x0c099c6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c099c6e;
P_0c099c6e: /* original 8b04, guest PC 0x0c099c6e */
if(!s->budget--) { s->failed_pc=0x0c099c6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099c7a; }
goto P_0c099c70;
P_0c099c70: /* original d30d, guest PC 0x0c099c70 */
if(!s->budget--) { s->failed_pc=0x0c099c70u; return 0; }
r[3]=read(ram,0x0c099ca8u,4);
goto P_0c099c72;
P_0c099c72: /* original 430b, guest PC 0x0c099c72 */
if(!s->budget--) { s->failed_pc=0x0c099c72u; return 0; }
target=r[3];
r[16]=code_base|0x0c099c76u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099c76u) { target=s->pc; goto dispatch; }
goto P_0c099c76;
P_0c099c74: /* original 0009, guest PC 0x0c099c74 */
if(!s->budget--) { s->failed_pc=0x0c099c74u; return 0; }
goto P_0c099c76;
P_0c099c76: /* original a037, guest PC 0x0c099c76 */
if(!s->budget--) { s->failed_pc=0x0c099c76u; return 0; }
goto P_0c099ce8;
P_0c099c78: /* original 0009, guest PC 0x0c099c78 */
if(!s->budget--) { s->failed_pc=0x0c099c78u; return 0; }
goto P_0c099c7a;
P_0c099c7a: /* original d30c, guest PC 0x0c099c7a */
if(!s->budget--) { s->failed_pc=0x0c099c7au; return 0; }
r[3]=read(ram,0x0c099cacu,4);
goto P_0c099c7c;
P_0c099c7c: /* original 430b, guest PC 0x0c099c7c */
if(!s->budget--) { s->failed_pc=0x0c099c7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c099c80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099c80u) { target=s->pc; goto dispatch; }
goto P_0c099c80;
P_0c099c7e: /* original 0009, guest PC 0x0c099c7e */
if(!s->budget--) { s->failed_pc=0x0c099c7eu; return 0; }
goto P_0c099c80;
P_0c099c80: /* original a032, guest PC 0x0c099c80 */
if(!s->budget--) { s->failed_pc=0x0c099c80u; return 0; }
goto P_0c099ce8;
P_0c099c82: /* original 0009, guest PC 0x0c099c82 */
if(!s->budget--) { s->failed_pc=0x0c099c82u; return 0; }
if(!vf3_matrix_family(0x0c099c84u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099c84u; return 0; } return 1;
P_0c099cb0: /* original d03e, guest PC 0x0c099cb0 */
if(!s->budget--) { s->failed_pc=0x0c099cb0u; return 0; }
r[0]=read(ram,0x0c099dacu,4);
goto P_0c099cb2;
P_0c099cb2: /* original d33d, guest PC 0x0c099cb2 */
if(!s->budget--) { s->failed_pc=0x0c099cb2u; return 0; }
r[3]=read(ram,0x0c099da8u,4);
goto P_0c099cb4;
P_0c099cb4: /* original 6102, guest PC 0x0c099cb4 */
if(!s->budget--) { s->failed_pc=0x0c099cb4u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c099cb6;
P_0c099cb6: /* original 2138, guest PC 0x0c099cb6 */
if(!s->budget--) { s->failed_pc=0x0c099cb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c099cb8;
P_0c099cb8: /* original 8b19, guest PC 0x0c099cb8 */
if(!s->budget--) { s->failed_pc=0x0c099cb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099cee; }
goto P_0c099cba;
P_0c099cba: /* original d33d, guest PC 0x0c099cba */
if(!s->budget--) { s->failed_pc=0x0c099cbau; return 0; }
r[3]=read(ram,0x0c099db0u,4);
goto P_0c099cbc;
P_0c099cbc: /* original 64f2, guest PC 0x0c099cbc */
if(!s->budget--) { s->failed_pc=0x0c099cbcu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c099cbe;
P_0c099cbe: /* original 5bd2, guest PC 0x0c099cbe */
if(!s->budget--) { s->failed_pc=0x0c099cbeu; return 0; }
r[11]=read(ram,r[13]+8,4);
goto P_0c099cc0;
P_0c099cc0: /* original 430b, guest PC 0x0c099cc0 */
if(!s->budget--) { s->failed_pc=0x0c099cc0u; return 0; }
target=r[3];
r[16]=code_base|0x0c099cc4u;
r[4]+=0x00000013u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099cc4u) { target=s->pc; goto dispatch; }
goto P_0c099cc4;
P_0c099cc2: /* original 7413, guest PC 0x0c099cc2 */
if(!s->budget--) { s->failed_pc=0x0c099cc2u; return 0; }
r[4]+=0x00000013u;
goto P_0c099cc4;
P_0c099cc4: /* original 640c, guest PC 0x0c099cc4 */
if(!s->budget--) { s->failed_pc=0x0c099cc4u; return 0; }
r[4]=r[0]&255u;
goto P_0c099cc6;
P_0c099cc6: /* original e029, guest PC 0x0c099cc6 */
if(!s->budget--) { s->failed_pc=0x0c099cc6u; return 0; }
r[0]=0x00000029u;
goto P_0c099cc8;
P_0c099cc8: /* original 00dc, guest PC 0x0c099cc8 */
if(!s->budget--) { s->failed_pc=0x0c099cc8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c099cca;
P_0c099cca: /* original 600c, guest PC 0x0c099cca */
if(!s->budget--) { s->failed_pc=0x0c099ccau; return 0; }
r[0]=r[0]&255u;
goto P_0c099ccc;
P_0c099ccc: /* original 8803, guest PC 0x0c099ccc */
if(!s->budget--) { s->failed_pc=0x0c099cccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c099cce;
P_0c099cce: /* original 8b07, guest PC 0x0c099cce */
if(!s->budget--) { s->failed_pc=0x0c099cceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ce0; }
goto P_0c099cd0;
P_0c099cd0: /* original 2448, guest PC 0x0c099cd0 */
if(!s->budget--) { s->failed_pc=0x0c099cd0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c099cd2;
P_0c099cd2: /* original 8905, guest PC 0x0c099cd2 */
if(!s->budget--) { s->failed_pc=0x0c099cd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c099ce0; }
goto P_0c099cd4;
P_0c099cd4: /* original d337, guest PC 0x0c099cd4 */
if(!s->budget--) { s->failed_pc=0x0c099cd4u; return 0; }
r[3]=read(ram,0x0c099db4u,4);
goto P_0c099cd6;
P_0c099cd6: /* original 23b8, guest PC 0x0c099cd6 */
if(!s->budget--) { s->failed_pc=0x0c099cd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c099cd8;
P_0c099cd8: /* original 8b02, guest PC 0x0c099cd8 */
if(!s->budget--) { s->failed_pc=0x0c099cd8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ce0; }
goto P_0c099cda;
P_0c099cda: /* original e204, guest PC 0x0c099cda */
if(!s->budget--) { s->failed_pc=0x0c099cdau; return 0; }
r[2]=0x00000004u;
goto P_0c099cdc;
P_0c099cdc: /* original 2b28, guest PC 0x0c099cdc */
if(!s->budget--) { s->failed_pc=0x0c099cdcu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[2])==0)!=0);
goto P_0c099cde;
P_0c099cde: /* original 8b03, guest PC 0x0c099cde */
if(!s->budget--) { s->failed_pc=0x0c099cdeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099ce8; }
goto P_0c099ce0;
P_0c099ce0: /* original 905e, guest PC 0x0c099ce0 */
if(!s->budget--) { s->failed_pc=0x0c099ce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da0u,2);
goto P_0c099ce2;
P_0c099ce2: /* original 00ee, guest PC 0x0c099ce2 */
if(!s->budget--) { s->failed_pc=0x0c099ce2u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c099ce4;
P_0c099ce4: /* original c830, guest PC 0x0c099ce4 */
if(!s->budget--) { s->failed_pc=0x0c099ce4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&48u)==0)!=0);
goto P_0c099ce6;
P_0c099ce6: /* original 8b0a, guest PC 0x0c099ce6 */
if(!s->budget--) { s->failed_pc=0x0c099ce6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099cfe; }
goto P_0c099ce8;
P_0c099ce8: /* original 53e3, guest PC 0x0c099ce8 */
if(!s->budget--) { s->failed_pc=0x0c099ce8u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c099cea;
P_0c099cea: /* original 4315, guest PC 0x0c099cea */
if(!s->budget--) { s->failed_pc=0x0c099ceau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c099cec;
P_0c099cec: /* original 8b07, guest PC 0x0c099cec */
if(!s->budget--) { s->failed_pc=0x0c099cecu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c099cfe; }
goto P_0c099cee;
P_0c099cee: /* original 7f04, guest PC 0x0c099cee */
if(!s->budget--) { s->failed_pc=0x0c099ceeu; return 0; }
r[15]+=0x00000004u;
goto P_0c099cf0;
P_0c099cf0: /* original d131, guest PC 0x0c099cf0 */
if(!s->budget--) { s->failed_pc=0x0c099cf0u; return 0; }
r[1]=read(ram,0x0c099db8u,4);
goto P_0c099cf2;
P_0c099cf2: /* original 4f26, guest PC 0x0c099cf2 */
if(!s->budget--) { s->failed_pc=0x0c099cf2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099cf4;
P_0c099cf4: /* original 6bf6, guest PC 0x0c099cf4 */
if(!s->budget--) { s->failed_pc=0x0c099cf4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099cf6;
P_0c099cf6: /* original 6cf6, guest PC 0x0c099cf6 */
if(!s->budget--) { s->failed_pc=0x0c099cf6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099cf8;
P_0c099cf8: /* original 6df6, guest PC 0x0c099cf8 */
if(!s->budget--) { s->failed_pc=0x0c099cf8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099cfa;
P_0c099cfa: /* original 412b, guest PC 0x0c099cfa */
if(!s->budget--) { s->failed_pc=0x0c099cfau; return 0; }
target=r[1];
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
P_0c099cfc: /* original 6ef6, guest PC 0x0c099cfc */
if(!s->budget--) { s->failed_pc=0x0c099cfcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099cfe;
P_0c099cfe: /* original 7f04, guest PC 0x0c099cfe */
if(!s->budget--) { s->failed_pc=0x0c099cfeu; return 0; }
r[15]+=0x00000004u;
goto P_0c099d00;
P_0c099d00: /* original 64c3, guest PC 0x0c099d00 */
if(!s->budget--) { s->failed_pc=0x0c099d00u; return 0; }
r[4]=r[12];
goto P_0c099d02;
P_0c099d02: /* original 4f26, guest PC 0x0c099d02 */
if(!s->budget--) { s->failed_pc=0x0c099d02u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099d04;
P_0c099d04: /* original 6bf6, guest PC 0x0c099d04 */
if(!s->budget--) { s->failed_pc=0x0c099d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c099d06;
P_0c099d06: /* original 6cf6, guest PC 0x0c099d06 */
if(!s->budget--) { s->failed_pc=0x0c099d06u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c099d08;
P_0c099d08: /* original 6df6, guest PC 0x0c099d08 */
if(!s->budget--) { s->failed_pc=0x0c099d08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099d0a;
P_0c099d0a: /* original a000, guest PC 0x0c099d0a */
if(!s->budget--) { s->failed_pc=0x0c099d0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099d0e;
P_0c099d0c: /* original 6ef6, guest PC 0x0c099d0c */
if(!s->budget--) { s->failed_pc=0x0c099d0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c099d0e;
P_0c099d0e: /* original 2fe6, guest PC 0x0c099d0e */
if(!s->budget--) { s->failed_pc=0x0c099d0eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d10;
P_0c099d10: /* original 2fd6, guest PC 0x0c099d10 */
if(!s->budget--) { s->failed_pc=0x0c099d10u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c099d12;
P_0c099d12: /* original 4f22, guest PC 0x0c099d12 */
if(!s->budget--) { s->failed_pc=0x0c099d12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c099d14;
P_0c099d14: /* original d32a, guest PC 0x0c099d14 */
if(!s->budget--) { s->failed_pc=0x0c099d14u; return 0; }
r[3]=read(ram,0x0c099dc0u,4);
goto P_0c099d16;
P_0c099d16: /* original dd29, guest PC 0x0c099d16 */
if(!s->budget--) { s->failed_pc=0x0c099d16u; return 0; }
r[13]=read(ram,0x0c099dbcu,4);
goto P_0c099d18;
P_0c099d18: /* original 7ffc, guest PC 0x0c099d18 */
if(!s->budget--) { s->failed_pc=0x0c099d18u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c099d1a;
P_0c099d1a: /* original 2f32, guest PC 0x0c099d1a */
if(!s->budget--) { s->failed_pc=0x0c099d1au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c099d1c;
P_0c099d1c: /* original e3f7, guest PC 0x0c099d1c */
if(!s->budget--) { s->failed_pc=0x0c099d1cu; return 0; }
r[3]=0xfffffff7u;
goto P_0c099d1e;
P_0c099d1e: /* original 9040, guest PC 0x0c099d1e */
if(!s->budget--) { s->failed_pc=0x0c099d1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da2u,2);
goto P_0c099d20;
P_0c099d20: /* original 024e, guest PC 0x0c099d20 */
if(!s->budget--) { s->failed_pc=0x0c099d20u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c099d22;
P_0c099d22: /* original 2239, guest PC 0x0c099d22 */
if(!s->budget--) { s->failed_pc=0x0c099d22u; return 0; }
r[2]&=r[3];
goto P_0c099d24;
P_0c099d24: /* original 0426, guest PC 0x0c099d24 */
if(!s->budget--) { s->failed_pc=0x0c099d24u; return 0; }
write(ram,r[4]+r[0],r[2],4);
goto P_0c099d26;
P_0c099d26: /* original d128, guest PC 0x0c099d26 */
if(!s->budget--) { s->failed_pc=0x0c099d26u; return 0; }
r[1]=read(ram,0x0c099dc8u,4);
goto P_0c099d28;
P_0c099d28: /* original d426, guest PC 0x0c099d28 */
if(!s->budget--) { s->failed_pc=0x0c099d28u; return 0; }
r[4]=read(ram,0x0c099dc4u,4);
goto P_0c099d2a;
P_0c099d2a: /* original 410b, guest PC 0x0c099d2a */
if(!s->budget--) { s->failed_pc=0x0c099d2au; return 0; }
target=r[1];
r[16]=code_base|0x0c099d2eu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099d2eu) { target=s->pc; goto dispatch; }
goto P_0c099d2e;
P_0c099d2c: /* original e500, guest PC 0x0c099d2c */
if(!s->budget--) { s->failed_pc=0x0c099d2cu; return 0; }
r[5]=0x00000000u;
goto P_0c099d2e;
P_0c099d2e: /* original d328, guest PC 0x0c099d2e */
if(!s->budget--) { s->failed_pc=0x0c099d2eu; return 0; }
r[3]=read(ram,0x0c099dd0u,4);
goto P_0c099d30;
P_0c099d30: /* original de26, guest PC 0x0c099d30 */
if(!s->budget--) { s->failed_pc=0x0c099d30u; return 0; }
r[14]=read(ram,0x0c099dccu,4);
goto P_0c099d32;
P_0c099d32: /* original 430b, guest PC 0x0c099d32 */
if(!s->budget--) { s->failed_pc=0x0c099d32u; return 0; }
target=r[3];
r[16]=code_base|0x0c099d36u;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099d36u) { target=s->pc; goto dispatch; }
goto P_0c099d36;
P_0c099d34: /* original 54e4, guest PC 0x0c099d34 */
if(!s->budget--) { s->failed_pc=0x0c099d34u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c099d36;
P_0c099d36: /* original d226, guest PC 0x0c099d36 */
if(!s->budget--) { s->failed_pc=0x0c099d36u; return 0; }
r[2]=read(ram,0x0c099dd0u,4);
goto P_0c099d38;
P_0c099d38: /* original 420b, guest PC 0x0c099d38 */
if(!s->budget--) { s->failed_pc=0x0c099d38u; return 0; }
target=r[2];
r[16]=code_base|0x0c099d3cu;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c099d3cu) { target=s->pc; goto dispatch; }
goto P_0c099d3c;
P_0c099d3a: /* original 54e5, guest PC 0x0c099d3a */
if(!s->budget--) { s->failed_pc=0x0c099d3au; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c099d3c;
P_0c099d3c: /* original 9032, guest PC 0x0c099d3c */
if(!s->budget--) { s->failed_pc=0x0c099d3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c099da4u,2);
goto P_0c099d3e;
P_0c099d3e: /* original e400, guest PC 0x0c099d3e */
if(!s->budget--) { s->failed_pc=0x0c099d3eu; return 0; }
r[4]=0x00000000u;
goto P_0c099d40;
P_0c099d40: /* original 0d44, guest PC 0x0c099d40 */
if(!s->budget--) { s->failed_pc=0x0c099d40u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c099d42;
P_0c099d42: /* original 7003, guest PC 0x0c099d42 */
if(!s->budget--) { s->failed_pc=0x0c099d42u; return 0; }
r[0]+=0x00000003u;
goto P_0c099d44;
P_0c099d44: /* original 0d44, guest PC 0x0c099d44 */
if(!s->budget--) { s->failed_pc=0x0c099d44u; return 0; }
write(ram,r[13]+r[0],r[4],1);
goto P_0c099d46;
P_0c099d46: /* original 7089, guest PC 0x0c099d46 */
if(!s->budget--) { s->failed_pc=0x0c099d46u; return 0; }
r[0]+=0xffffff89u;
goto P_0c099d48;
P_0c099d48: /* original d322, guest PC 0x0c099d48 */
if(!s->budget--) { s->failed_pc=0x0c099d48u; return 0; }
r[3]=read(ram,0x0c099dd4u,4);
goto P_0c099d4a;
P_0c099d4a: /* original 54ec, guest PC 0x0c099d4a */
if(!s->budget--) { s->failed_pc=0x0c099d4au; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c099d4c;
P_0c099d4c: /* original 0436, guest PC 0x0c099d4c */
if(!s->budget--) { s->failed_pc=0x0c099d4cu; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c099d4e;
P_0c099d4e: /* original 62f2, guest PC 0x0c099d4e */
if(!s->budget--) { s->failed_pc=0x0c099d4eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c099d50;
P_0c099d50: /* original 7f04, guest PC 0x0c099d50 */
if(!s->budget--) { s->failed_pc=0x0c099d50u; return 0; }
r[15]+=0x00000004u;
goto P_0c099d52;
P_0c099d52: /* original 4f26, guest PC 0x0c099d52 */
if(!s->budget--) { s->failed_pc=0x0c099d52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c099d54;
P_0c099d54: /* original 842b, guest PC 0x0c099d54 */
if(!s->budget--) { s->failed_pc=0x0c099d54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+11,1);
goto P_0c099d56;
P_0c099d56: /* original 7001, guest PC 0x0c099d56 */
if(!s->budget--) { s->failed_pc=0x0c099d56u; return 0; }
r[0]+=0x00000001u;
goto P_0c099d58;
P_0c099d58: /* original 802b, guest PC 0x0c099d58 */
if(!s->budget--) { s->failed_pc=0x0c099d58u; return 0; }
write(ram,r[2]+11,r[0],1);
goto P_0c099d5a;
P_0c099d5a: /* original 6df6, guest PC 0x0c099d5a */
if(!s->budget--) { s->failed_pc=0x0c099d5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c099d5c;
P_0c099d5c: /* original d316, guest PC 0x0c099d5c */
if(!s->budget--) { s->failed_pc=0x0c099d5cu; return 0; }
r[3]=read(ram,0x0c099db8u,4);
goto P_0c099d5e;
P_0c099d5e: /* original 432b, guest PC 0x0c099d5e */
if(!s->budget--) { s->failed_pc=0x0c099d5eu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c097ff4u: return vf3_matrix_family(0x0c097ff4u,s,ram);
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
P_0c099d60: /* original 6ef6, guest PC 0x0c099d60 */
if(!s->budget--) { s->failed_pc=0x0c099d60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c099d62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c099d62u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
