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
int vf3_away_batch71_adapter_29(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c09d408u: goto P_0c09d408;
case 0x0c09d40au: goto P_0c09d40a;
case 0x0c09d40cu: goto P_0c09d40c;
case 0x0c09d40eu: goto P_0c09d40e;
case 0x0c09d410u: goto P_0c09d410;
case 0x0c09d412u: goto P_0c09d412;
case 0x0c09d414u: goto P_0c09d414;
case 0x0c09d416u: goto P_0c09d416;
case 0x0c09d418u: goto P_0c09d418;
case 0x0c09d41au: goto P_0c09d41a;
case 0x0c09d41cu: goto P_0c09d41c;
case 0x0c09d41eu: goto P_0c09d41e;
case 0x0c09d420u: goto P_0c09d420;
case 0x0c09d422u: goto P_0c09d422;
case 0x0c09d424u: goto P_0c09d424;
case 0x0c09d426u: goto P_0c09d426;
case 0x0c09d428u: goto P_0c09d428;
case 0x0c09d42au: goto P_0c09d42a;
case 0x0c09d5aeu: goto P_0c09d5ae;
case 0x0c09d5b0u: goto P_0c09d5b0;
case 0x0c09d5b2u: goto P_0c09d5b2;
case 0x0c09d5b4u: goto P_0c09d5b4;
case 0x0c09d5b6u: goto P_0c09d5b6;
case 0x0c09d5b8u: goto P_0c09d5b8;
case 0x0c09d5bau: goto P_0c09d5ba;
case 0x0c09d5bcu: goto P_0c09d5bc;
case 0x0c09d5beu: goto P_0c09d5be;
case 0x0c09d5c0u: goto P_0c09d5c0;
case 0x0c09d5c2u: goto P_0c09d5c2;
case 0x0c09d5c4u: goto P_0c09d5c4;
case 0x0c09d5c6u: goto P_0c09d5c6;
case 0x0c09d5c8u: goto P_0c09d5c8;
case 0x0c09d5cau: goto P_0c09d5ca;
case 0x0c09d5ccu: goto P_0c09d5cc;
case 0x0c09d5ceu: goto P_0c09d5ce;
case 0x0c09d5d0u: goto P_0c09d5d0;
case 0x0c09d5d2u: goto P_0c09d5d2;
case 0x0c09d5d4u: goto P_0c09d5d4;
case 0x0c09d5d6u: goto P_0c09d5d6;
case 0x0c09d5d8u: goto P_0c09d5d8;
case 0x0c09d5dau: goto P_0c09d5da;
case 0x0c09d5dcu: goto P_0c09d5dc;
case 0x0c09d5deu: goto P_0c09d5de;
case 0x0c09d5e0u: goto P_0c09d5e0;
case 0x0c09d5e2u: goto P_0c09d5e2;
case 0x0c09d5e4u: goto P_0c09d5e4;
case 0x0c09d5e6u: goto P_0c09d5e6;
case 0x0c09d5e8u: goto P_0c09d5e8;
case 0x0c09d5eau: goto P_0c09d5ea;
case 0x0c09d5ecu: goto P_0c09d5ec;
case 0x0c09d5eeu: goto P_0c09d5ee;
case 0x0c09d5f0u: goto P_0c09d5f0;
case 0x0c09d5f2u: goto P_0c09d5f2;
case 0x0c09d5f4u: goto P_0c09d5f4;
case 0x0c09d5f6u: goto P_0c09d5f6;
case 0x0c09d5f8u: goto P_0c09d5f8;
case 0x0c09d5fau: goto P_0c09d5fa;
case 0x0c09d5fcu: goto P_0c09d5fc;
case 0x0c09d5feu: goto P_0c09d5fe;
case 0x0c09d600u: goto P_0c09d600;
case 0x0c09d602u: goto P_0c09d602;
case 0x0c09d604u: goto P_0c09d604;
case 0x0c09d606u: goto P_0c09d606;
case 0x0c09d608u: goto P_0c09d608;
case 0x0c09d60au: goto P_0c09d60a;
case 0x0c09d60cu: goto P_0c09d60c;
case 0x0c09d60eu: goto P_0c09d60e;
case 0x0c09d610u: goto P_0c09d610;
case 0x0c09d612u: goto P_0c09d612;
case 0x0c09d614u: goto P_0c09d614;
case 0x0c09d616u: goto P_0c09d616;
case 0x0c09d618u: goto P_0c09d618;
case 0x0c09d61au: goto P_0c09d61a;
case 0x0c09d61cu: goto P_0c09d61c;
case 0x0c09d61eu: goto P_0c09d61e;
case 0x0c09d620u: goto P_0c09d620;
case 0x0c09d622u: goto P_0c09d622;
case 0x0c09d624u: goto P_0c09d624;
case 0x0c09d626u: goto P_0c09d626;
case 0x0c09d628u: goto P_0c09d628;
case 0x0c09d62au: goto P_0c09d62a;
case 0x0c09d62cu: goto P_0c09d62c;
case 0x0c09d62eu: goto P_0c09d62e;
case 0x0c09d630u: goto P_0c09d630;
case 0x0c09d632u: goto P_0c09d632;
case 0x0c09d634u: goto P_0c09d634;
case 0x0c09d636u: goto P_0c09d636;
case 0x0c09d638u: goto P_0c09d638;
case 0x0c09d63au: goto P_0c09d63a;
case 0x0c09d63cu: goto P_0c09d63c;
case 0x0c09d63eu: goto P_0c09d63e;
case 0x0c09d640u: goto P_0c09d640;
case 0x0c09d642u: goto P_0c09d642;
case 0x0c09d644u: goto P_0c09d644;
case 0x0c09d646u: goto P_0c09d646;
case 0x0c09d648u: goto P_0c09d648;
case 0x0c09d64au: goto P_0c09d64a;
case 0x0c09d64cu: goto P_0c09d64c;
case 0x0c09d64eu: goto P_0c09d64e;
case 0x0c09d650u: goto P_0c09d650;
case 0x0c09d652u: goto P_0c09d652;
case 0x0c09d654u: goto P_0c09d654;
case 0x0c09d656u: goto P_0c09d656;
case 0x0c09d658u: goto P_0c09d658;
case 0x0c09d65au: goto P_0c09d65a;
case 0x0c09d65cu: goto P_0c09d65c;
case 0x0c09d65eu: goto P_0c09d65e;
case 0x0c09d660u: goto P_0c09d660;
case 0x0c09d662u: goto P_0c09d662;
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
P_0c09d408: /* original e507, guest PC 0x0c09d408 */
if(!s->budget--) { s->failed_pc=0x0c09d408u; return 0; }
r[5]=0x00000007u;
goto P_0c09d40a;
P_0c09d40a: /* original 7408, guest PC 0x0c09d40a */
if(!s->budget--) { s->failed_pc=0x0c09d40au; return 0; }
r[4]+=0x00000008u;
goto P_0c09d40c;
P_0c09d40c: /* original f348, guest PC 0x0c09d40c */
if(!s->budget--) { s->failed_pc=0x0c09d40cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09d40e;
P_0c09d40e: /* original 4510, guest PC 0x0c09d40e */
if(!s->budget--) { s->failed_pc=0x0c09d40eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09d410;
P_0c09d410: /* original f34d, guest PC 0x0c09d410 */
if(!s->budget--) { s->failed_pc=0x0c09d410u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09d412;
P_0c09d412: /* original f43a, guest PC 0x0c09d412 */
if(!s->budget--) { s->failed_pc=0x0c09d412u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09d414;
P_0c09d414: /* original 8ffa, guest PC 0x0c09d414 */
if(!s->budget--) { s->failed_pc=0x0c09d414u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09d40c; }
goto P_0c09d418;
P_0c09d416: /* original 740c, guest PC 0x0c09d416 */
if(!s->budget--) { s->failed_pc=0x0c09d416u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09d418;
P_0c09d418: /* original e50e, guest PC 0x0c09d418 */
if(!s->budget--) { s->failed_pc=0x0c09d418u; return 0; }
r[5]=0x0000000eu;
goto P_0c09d41a;
P_0c09d41a: /* original 74f8, guest PC 0x0c09d41a */
if(!s->budget--) { s->failed_pc=0x0c09d41au; return 0; }
r[4]+=0xfffffff8u;
goto P_0c09d41c;
P_0c09d41c: /* original f348, guest PC 0x0c09d41c */
if(!s->budget--) { s->failed_pc=0x0c09d41cu; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09d41e;
P_0c09d41e: /* original 4510, guest PC 0x0c09d41e */
if(!s->budget--) { s->failed_pc=0x0c09d41eu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c09d420;
P_0c09d420: /* original f34d, guest PC 0x0c09d420 */
if(!s->budget--) { s->failed_pc=0x0c09d420u; return 0; }
fr[3]^=0x80000000u;
goto P_0c09d422;
P_0c09d422: /* original f43a, guest PC 0x0c09d422 */
if(!s->budget--) { s->failed_pc=0x0c09d422u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09d424;
P_0c09d424: /* original 8ffa, guest PC 0x0c09d424 */
if(!s->budget--) { s->failed_pc=0x0c09d424u; return 0; }
cond=r[17]&1u;
r[4]+=0x0000000cu;
if(!cond) { goto P_0c09d41c; }
goto P_0c09d428;
P_0c09d426: /* original 740c, guest PC 0x0c09d426 */
if(!s->budget--) { s->failed_pc=0x0c09d426u; return 0; }
r[4]+=0x0000000cu;
goto P_0c09d428;
P_0c09d428: /* original 000b, guest PC 0x0c09d428 */
if(!s->budget--) { s->failed_pc=0x0c09d428u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09d42a: /* original 0009, guest PC 0x0c09d42a */
if(!s->budget--) { s->failed_pc=0x0c09d42au; return 0; }
if(!vf3_matrix_family(0x0c09d42cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d42cu; return 0; } return 1;
P_0c09d5ae: /* original 6543, guest PC 0x0c09d5ae */
if(!s->budget--) { s->failed_pc=0x0c09d5aeu; return 0; }
r[5]=r[4];
goto P_0c09d5b0;
P_0c09d5b0: /* original e03c, guest PC 0x0c09d5b0 */
if(!s->budget--) { s->failed_pc=0x0c09d5b0u; return 0; }
r[0]=0x0000003cu;
goto P_0c09d5b2;
P_0c09d5b2: /* original 7ffc, guest PC 0x0c09d5b2 */
if(!s->budget--) { s->failed_pc=0x0c09d5b2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09d5b4;
P_0c09d5b4: /* original 2f42, guest PC 0x0c09d5b4 */
if(!s->budget--) { s->failed_pc=0x0c09d5b4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09d5b6;
P_0c09d5b6: /* original 055d, guest PC 0x0c09d5b6 */
if(!s->budget--) { s->failed_pc=0x0c09d5b6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c09d5b8;
P_0c09d5b8: /* original 655d, guest PC 0x0c09d5b8 */
if(!s->budget--) { s->failed_pc=0x0c09d5b8u; return 0; }
r[5]=r[5]&65535u;
goto P_0c09d5ba;
P_0c09d5ba: /* original a000, guest PC 0x0c09d5ba */
if(!s->budget--) { s->failed_pc=0x0c09d5bau; return 0; }
r[15]+=0x00000004u;
goto P_0c09d5be;
P_0c09d5bc: /* original 7f04, guest PC 0x0c09d5bc */
if(!s->budget--) { s->failed_pc=0x0c09d5bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c09d5be;
P_0c09d5be: /* original 75ff, guest PC 0x0c09d5be */
if(!s->budget--) { s->failed_pc=0x0c09d5beu; return 0; }
r[5]+=0xffffffffu;
goto P_0c09d5c0;
P_0c09d5c0: /* original d346, guest PC 0x0c09d5c0 */
if(!s->budget--) { s->failed_pc=0x0c09d5c0u; return 0; }
r[3]=read(ram,0x0c09d6dcu,4);
goto P_0c09d5c2;
P_0c09d5c2: /* original 6253, guest PC 0x0c09d5c2 */
if(!s->budget--) { s->failed_pc=0x0c09d5c2u; return 0; }
r[2]=r[5];
goto P_0c09d5c4;
P_0c09d5c4: /* original 4500, guest PC 0x0c09d5c4 */
if(!s->budget--) { s->failed_pc=0x0c09d5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c09d5c6;
P_0c09d5c6: /* original 6632, guest PC 0x0c09d5c6 */
if(!s->budget--) { s->failed_pc=0x0c09d5c6u; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c09d5c8;
P_0c09d5c8: /* original 352c, guest PC 0x0c09d5c8 */
if(!s->budget--) { s->failed_pc=0x0c09d5c8u; return 0; }
r[5]+=r[2];
goto P_0c09d5ca;
P_0c09d5ca: /* original 4508, guest PC 0x0c09d5ca */
if(!s->budget--) { s->failed_pc=0x0c09d5cau; return 0; }
r[5]<<=2;
goto P_0c09d5cc;
P_0c09d5cc: /* original 356c, guest PC 0x0c09d5cc */
if(!s->budget--) { s->failed_pc=0x0c09d5ccu; return 0; }
r[5]+=r[6];
goto P_0c09d5ce;
P_0c09d5ce: /* original 5151, guest PC 0x0c09d5ce */
if(!s->budget--) { s->failed_pc=0x0c09d5ceu; return 0; }
r[1]=read(ram,r[5]+4,4);
goto P_0c09d5d0;
P_0c09d5d0: /* original 7ff8, guest PC 0x0c09d5d0 */
if(!s->budget--) { s->failed_pc=0x0c09d5d0u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09d5d2;
P_0c09d5d2: /* original 6752, guest PC 0x0c09d5d2 */
if(!s->budget--) { s->failed_pc=0x0c09d5d2u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c09d5d4;
P_0c09d5d4: /* original 316c, guest PC 0x0c09d5d4 */
if(!s->budget--) { s->failed_pc=0x0c09d5d4u; return 0; }
r[1]+=r[6];
goto P_0c09d5d6;
P_0c09d5d6: /* original 376c, guest PC 0x0c09d5d6 */
if(!s->budget--) { s->failed_pc=0x0c09d5d6u; return 0; }
r[7]+=r[6];
goto P_0c09d5d8;
P_0c09d5d8: /* original 2f12, guest PC 0x0c09d5d8 */
if(!s->budget--) { s->failed_pc=0x0c09d5d8u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c09d5da;
P_0c09d5da: /* original 5252, guest PC 0x0c09d5da */
if(!s->budget--) { s->failed_pc=0x0c09d5dau; return 0; }
r[2]=read(ram,r[5]+8,4);
goto P_0c09d5dc;
P_0c09d5dc: /* original e104, guest PC 0x0c09d5dc */
if(!s->budget--) { s->failed_pc=0x0c09d5dcu; return 0; }
r[1]=0x00000004u;
goto P_0c09d5de;
P_0c09d5de: /* original 362c, guest PC 0x0c09d5de */
if(!s->budget--) { s->failed_pc=0x0c09d5deu; return 0; }
r[6]+=r[2];
goto P_0c09d5e0;
P_0c09d5e0: /* original 1f61, guest PC 0x0c09d5e0 */
if(!s->budget--) { s->failed_pc=0x0c09d5e0u; return 0; }
write(ram,r[15]+4,r[6],4);
goto P_0c09d5e2;
P_0c09d5e2: /* original 6673, guest PC 0x0c09d5e2 */
if(!s->budget--) { s->failed_pc=0x0c09d5e2u; return 0; }
r[6]=r[7];
goto P_0c09d5e4;
P_0c09d5e4: /* original 9073, guest PC 0x0c09d5e4 */
if(!s->budget--) { s->failed_pc=0x0c09d5e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6ceu,2);
goto P_0c09d5e6;
P_0c09d5e6: /* original 7602, guest PC 0x0c09d5e6 */
if(!s->budget--) { s->failed_pc=0x0c09d5e6u; return 0; }
r[6]+=0x00000002u;
goto P_0c09d5e8;
P_0c09d5e8: /* original 6571, guest PC 0x0c09d5e8 */
if(!s->budget--) { s->failed_pc=0x0c09d5e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[7],2);
r[5]=tmp;
goto P_0c09d5ea;
P_0c09d5ea: /* original 024c, guest PC 0x0c09d5ea */
if(!s->budget--) { s->failed_pc=0x0c09d5eau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09d5ec;
P_0c09d5ec: /* original 701d, guest PC 0x0c09d5ec */
if(!s->budget--) { s->failed_pc=0x0c09d5ecu; return 0; }
r[0]+=0x0000001du;
goto P_0c09d5ee;
P_0c09d5ee: /* original 655d, guest PC 0x0c09d5ee */
if(!s->budget--) { s->failed_pc=0x0c09d5eeu; return 0; }
r[5]=r[5]&65535u;
goto P_0c09d5f0;
P_0c09d5f0: /* original 0424, guest PC 0x0c09d5f0 */
if(!s->budget--) { s->failed_pc=0x0c09d5f0u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c09d5f2;
P_0c09d5f2: /* original e2f4, guest PC 0x0c09d5f2 */
if(!s->budget--) { s->failed_pc=0x0c09d5f2u; return 0; }
r[2]=0xfffffff4u;
goto P_0c09d5f4;
P_0c09d5f4: /* original 452c, guest PC 0x0c09d5f4 */
if(!s->budget--) { s->failed_pc=0x0c09d5f4u; return 0; }
r[5]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[5]>>((-r[2])&31u)):((int32_t)r[5]<0?0xffffffffu:0)):r[5]<<(r[2]&31u);
goto P_0c09d5f6;
P_0c09d5f6: /* original 70e3, guest PC 0x0c09d5f6 */
if(!s->budget--) { s->failed_pc=0x0c09d5f6u; return 0; }
r[0]+=0xffffffe3u;
goto P_0c09d5f8;
P_0c09d5f8: /* original 2519, guest PC 0x0c09d5f8 */
if(!s->budget--) { s->failed_pc=0x0c09d5f8u; return 0; }
r[5]&=r[1];
goto P_0c09d5fa;
P_0c09d5fa: /* original 0454, guest PC 0x0c09d5fa */
if(!s->budget--) { s->failed_pc=0x0c09d5fau; return 0; }
write(ram,r[4]+r[0],r[5],1);
goto P_0c09d5fc;
P_0c09d5fc: /* original 9068, guest PC 0x0c09d5fc */
if(!s->budget--) { s->failed_pc=0x0c09d5fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d6d0u,2);
goto P_0c09d5fe;
P_0c09d5fe: /* original 044e, guest PC 0x0c09d5fe */
if(!s->budget--) { s->failed_pc=0x0c09d5feu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09d600;
P_0c09d600: /* original 6563, guest PC 0x0c09d600 */
if(!s->budget--) { s->failed_pc=0x0c09d600u; return 0; }
r[5]=r[6];
goto P_0c09d602;
P_0c09d602: /* original 750f, guest PC 0x0c09d602 */
if(!s->budget--) { s->failed_pc=0x0c09d602u; return 0; }
r[5]+=0x0000000fu;
goto P_0c09d604;
P_0c09d604: /* original 53f1, guest PC 0x0c09d604 */
if(!s->budget--) { s->failed_pc=0x0c09d604u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c09d606;
P_0c09d606: /* original e110, guest PC 0x0c09d606 */
if(!s->budget--) { s->failed_pc=0x0c09d606u; return 0; }
r[1]=0x00000010u;
goto P_0c09d608;
P_0c09d608: /* original 1432, guest PC 0x0c09d608 */
if(!s->budget--) { s->failed_pc=0x0c09d608u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c09d60a;
P_0c09d60a: /* original 62f2, guest PC 0x0c09d60a */
if(!s->budget--) { s->failed_pc=0x0c09d60au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c09d60c;
P_0c09d60c: /* original 1421, guest PC 0x0c09d60c */
if(!s->budget--) { s->failed_pc=0x0c09d60cu; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c09d60e;
P_0c09d60e: /* original 6263, guest PC 0x0c09d60e */
if(!s->budget--) { s->failed_pc=0x0c09d60eu; return 0; }
r[2]=r[6];
goto P_0c09d610;
P_0c09d610: /* original e600, guest PC 0x0c09d610 */
if(!s->budget--) { s->failed_pc=0x0c09d610u; return 0; }
r[6]=0x00000000u;
goto P_0c09d612;
P_0c09d612: /* original 2452, guest PC 0x0c09d612 */
if(!s->budget--) { s->failed_pc=0x0c09d612u; return 0; }
write(ram,r[4],r[5],4);
goto P_0c09d614;
P_0c09d614: /* original 6563, guest PC 0x0c09d614 */
if(!s->budget--) { s->failed_pc=0x0c09d614u; return 0; }
r[5]=r[6];
goto P_0c09d616;
P_0c09d616: /* original 6763, guest PC 0x0c09d616 */
if(!s->budget--) { s->failed_pc=0x0c09d616u; return 0; }
r[7]=r[6];
goto P_0c09d618;
P_0c09d618: /* original 6624, guest PC 0x0c09d618 */
if(!s->budget--) { s->failed_pc=0x0c09d618u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]+=1;
r[6]=tmp;
goto P_0c09d61a;
P_0c09d61a: /* original 6343, guest PC 0x0c09d61a */
if(!s->budget--) { s->failed_pc=0x0c09d61au; return 0; }
r[3]=r[4];
goto P_0c09d61c;
P_0c09d61c: /* original 730c, guest PC 0x0c09d61c */
if(!s->budget--) { s->failed_pc=0x0c09d61cu; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d61e;
P_0c09d61e: /* original 666c, guest PC 0x0c09d61e */
if(!s->budget--) { s->failed_pc=0x0c09d61eu; return 0; }
r[6]=r[6]&255u;
goto P_0c09d620;
P_0c09d620: /* original 6063, guest PC 0x0c09d620 */
if(!s->budget--) { s->failed_pc=0x0c09d620u; return 0; }
r[0]=r[6];
goto P_0c09d622;
P_0c09d622: /* original 4009, guest PC 0x0c09d622 */
if(!s->budget--) { s->failed_pc=0x0c09d622u; return 0; }
r[0]>>=2;
goto P_0c09d624;
P_0c09d624: /* original 4009, guest PC 0x0c09d624 */
if(!s->budget--) { s->failed_pc=0x0c09d624u; return 0; }
r[0]>>=2;
goto P_0c09d626;
P_0c09d626: /* original 4009, guest PC 0x0c09d626 */
if(!s->budget--) { s->failed_pc=0x0c09d626u; return 0; }
r[0]>>=2;
goto P_0c09d628;
P_0c09d628: /* original c903, guest PC 0x0c09d628 */
if(!s->budget--) { s->failed_pc=0x0c09d628u; return 0; }
r[0]&=3u;
goto P_0c09d62a;
P_0c09d62a: /* original 335c, guest PC 0x0c09d62a */
if(!s->budget--) { s->failed_pc=0x0c09d62au; return 0; }
r[3]+=r[5];
goto P_0c09d62c;
P_0c09d62c: /* original 2300, guest PC 0x0c09d62c */
if(!s->budget--) { s->failed_pc=0x0c09d62cu; return 0; }
write(ram,r[3],r[0],1);
goto P_0c09d62e;
P_0c09d62e: /* original 6063, guest PC 0x0c09d62e */
if(!s->budget--) { s->failed_pc=0x0c09d62eu; return 0; }
r[0]=r[6];
goto P_0c09d630;
P_0c09d630: /* original 4009, guest PC 0x0c09d630 */
if(!s->budget--) { s->failed_pc=0x0c09d630u; return 0; }
r[0]>>=2;
goto P_0c09d632;
P_0c09d632: /* original 6343, guest PC 0x0c09d632 */
if(!s->budget--) { s->failed_pc=0x0c09d632u; return 0; }
r[3]=r[4];
goto P_0c09d634;
P_0c09d634: /* original 4009, guest PC 0x0c09d634 */
if(!s->budget--) { s->failed_pc=0x0c09d634u; return 0; }
r[0]>>=2;
goto P_0c09d636;
P_0c09d636: /* original 730c, guest PC 0x0c09d636 */
if(!s->budget--) { s->failed_pc=0x0c09d636u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d638;
P_0c09d638: /* original c903, guest PC 0x0c09d638 */
if(!s->budget--) { s->failed_pc=0x0c09d638u; return 0; }
r[0]&=3u;
goto P_0c09d63a;
P_0c09d63a: /* original 335c, guest PC 0x0c09d63a */
if(!s->budget--) { s->failed_pc=0x0c09d63au; return 0; }
r[3]+=r[5];
goto P_0c09d63c;
P_0c09d63c: /* original 8031, guest PC 0x0c09d63c */
if(!s->budget--) { s->failed_pc=0x0c09d63cu; return 0; }
write(ram,r[3]+1,r[0],1);
goto P_0c09d63e;
P_0c09d63e: /* original 6063, guest PC 0x0c09d63e */
if(!s->budget--) { s->failed_pc=0x0c09d63eu; return 0; }
r[0]=r[6];
goto P_0c09d640;
P_0c09d640: /* original 6343, guest PC 0x0c09d640 */
if(!s->budget--) { s->failed_pc=0x0c09d640u; return 0; }
r[3]=r[4];
goto P_0c09d642;
P_0c09d642: /* original 4009, guest PC 0x0c09d642 */
if(!s->budget--) { s->failed_pc=0x0c09d642u; return 0; }
r[0]>>=2;
goto P_0c09d644;
P_0c09d644: /* original 730c, guest PC 0x0c09d644 */
if(!s->budget--) { s->failed_pc=0x0c09d644u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d646;
P_0c09d646: /* original c903, guest PC 0x0c09d646 */
if(!s->budget--) { s->failed_pc=0x0c09d646u; return 0; }
r[0]&=3u;
goto P_0c09d648;
P_0c09d648: /* original 335c, guest PC 0x0c09d648 */
if(!s->budget--) { s->failed_pc=0x0c09d648u; return 0; }
r[3]+=r[5];
goto P_0c09d64a;
P_0c09d64a: /* original 8032, guest PC 0x0c09d64a */
if(!s->budget--) { s->failed_pc=0x0c09d64au; return 0; }
write(ram,r[3]+2,r[0],1);
goto P_0c09d64c;
P_0c09d64c: /* original 6343, guest PC 0x0c09d64c */
if(!s->budget--) { s->failed_pc=0x0c09d64cu; return 0; }
r[3]=r[4];
goto P_0c09d64e;
P_0c09d64e: /* original e003, guest PC 0x0c09d64e */
if(!s->budget--) { s->failed_pc=0x0c09d64eu; return 0; }
r[0]=0x00000003u;
goto P_0c09d650;
P_0c09d650: /* original 730c, guest PC 0x0c09d650 */
if(!s->budget--) { s->failed_pc=0x0c09d650u; return 0; }
r[3]+=0x0000000cu;
goto P_0c09d652;
P_0c09d652: /* original 2069, guest PC 0x0c09d652 */
if(!s->budget--) { s->failed_pc=0x0c09d652u; return 0; }
r[0]&=r[6];
goto P_0c09d654;
P_0c09d654: /* original 335c, guest PC 0x0c09d654 */
if(!s->budget--) { s->failed_pc=0x0c09d654u; return 0; }
r[3]+=r[5];
goto P_0c09d656;
P_0c09d656: /* original 8033, guest PC 0x0c09d656 */
if(!s->budget--) { s->failed_pc=0x0c09d656u; return 0; }
write(ram,r[3]+3,r[0],1);
goto P_0c09d658;
P_0c09d658: /* original 7701, guest PC 0x0c09d658 */
if(!s->budget--) { s->failed_pc=0x0c09d658u; return 0; }
r[7]+=0x00000001u;
goto P_0c09d65a;
P_0c09d65a: /* original 3712, guest PC 0x0c09d65a */
if(!s->budget--) { s->failed_pc=0x0c09d65au; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[1])!=0);
goto P_0c09d65c;
P_0c09d65c: /* original 8fdc, guest PC 0x0c09d65c */
if(!s->budget--) { s->failed_pc=0x0c09d65cu; return 0; }
cond=r[17]&1u;
r[5]+=0x00000004u;
if(!cond) { goto P_0c09d618; }
goto P_0c09d660;
P_0c09d65e: /* original 7504, guest PC 0x0c09d65e */
if(!s->budget--) { s->failed_pc=0x0c09d65eu; return 0; }
r[5]+=0x00000004u;
goto P_0c09d660;
P_0c09d660: /* original 000b, guest PC 0x0c09d660 */
if(!s->budget--) { s->failed_pc=0x0c09d660u; return 0; }
target=r[16];
r[15]+=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09d662: /* original 7f08, guest PC 0x0c09d662 */
if(!s->budget--) { s->failed_pc=0x0c09d662u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c09d664u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d664u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
