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
int vf3_away_batch11_adapter_55(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c2c70u: goto P_0c0c2c70;
case 0x0c0c2c72u: goto P_0c0c2c72;
case 0x0c0c2c74u: goto P_0c0c2c74;
case 0x0c0c2c76u: goto P_0c0c2c76;
case 0x0c0c2c78u: goto P_0c0c2c78;
case 0x0c0c2c7au: goto P_0c0c2c7a;
case 0x0c0c2c7cu: goto P_0c0c2c7c;
case 0x0c0c2c7eu: goto P_0c0c2c7e;
case 0x0c0c2c80u: goto P_0c0c2c80;
case 0x0c0c2c82u: goto P_0c0c2c82;
case 0x0c0c2c84u: goto P_0c0c2c84;
case 0x0c0c2c86u: goto P_0c0c2c86;
case 0x0c0c2c88u: goto P_0c0c2c88;
case 0x0c0c2c8au: goto P_0c0c2c8a;
case 0x0c0c2c8cu: goto P_0c0c2c8c;
case 0x0c0c2c8eu: goto P_0c0c2c8e;
case 0x0c0c2c90u: goto P_0c0c2c90;
case 0x0c0c2c92u: goto P_0c0c2c92;
case 0x0c0c2c94u: goto P_0c0c2c94;
case 0x0c0c2c96u: goto P_0c0c2c96;
case 0x0c0c2c98u: goto P_0c0c2c98;
case 0x0c0c2c9au: goto P_0c0c2c9a;
case 0x0c0c2c9cu: goto P_0c0c2c9c;
case 0x0c0c2c9eu: goto P_0c0c2c9e;
case 0x0c0c2ca0u: goto P_0c0c2ca0;
case 0x0c0c2ca2u: goto P_0c0c2ca2;
case 0x0c0c2ca4u: goto P_0c0c2ca4;
case 0x0c0c2ca6u: goto P_0c0c2ca6;
case 0x0c0c2ca8u: goto P_0c0c2ca8;
case 0x0c0c2caau: goto P_0c0c2caa;
case 0x0c0c2cacu: goto P_0c0c2cac;
case 0x0c0c2caeu: goto P_0c0c2cae;
case 0x0c0c2cb0u: goto P_0c0c2cb0;
case 0x0c0c2cb2u: goto P_0c0c2cb2;
case 0x0c0c2cb4u: goto P_0c0c2cb4;
case 0x0c0c2cb6u: goto P_0c0c2cb6;
case 0x0c0c2cb8u: goto P_0c0c2cb8;
case 0x0c0c2cbau: goto P_0c0c2cba;
case 0x0c0c2cbcu: goto P_0c0c2cbc;
case 0x0c0c2cbeu: goto P_0c0c2cbe;
case 0x0c0c2cc0u: goto P_0c0c2cc0;
case 0x0c0c2cc2u: goto P_0c0c2cc2;
case 0x0c0c2cc4u: goto P_0c0c2cc4;
case 0x0c0c2cc6u: goto P_0c0c2cc6;
case 0x0c0c2cc8u: goto P_0c0c2cc8;
case 0x0c0c2ccau: goto P_0c0c2cca;
case 0x0c0c2cccu: goto P_0c0c2ccc;
case 0x0c0c2cceu: goto P_0c0c2cce;
case 0x0c0c2cd0u: goto P_0c0c2cd0;
case 0x0c0c2cd2u: goto P_0c0c2cd2;
case 0x0c0c2cd4u: goto P_0c0c2cd4;
case 0x0c0c2cd6u: goto P_0c0c2cd6;
case 0x0c0c2cd8u: goto P_0c0c2cd8;
case 0x0c0c2cdau: goto P_0c0c2cda;
case 0x0c0c2cdcu: goto P_0c0c2cdc;
case 0x0c0c2cdeu: goto P_0c0c2cde;
case 0x0c0c2ce0u: goto P_0c0c2ce0;
case 0x0c0c2ce2u: goto P_0c0c2ce2;
case 0x0c0c2ce4u: goto P_0c0c2ce4;
case 0x0c0c2ce6u: goto P_0c0c2ce6;
case 0x0c0c2ce8u: goto P_0c0c2ce8;
case 0x0c0c2ceau: goto P_0c0c2cea;
case 0x0c0c2cecu: goto P_0c0c2cec;
case 0x0c0c2ceeu: goto P_0c0c2cee;
case 0x0c0c2cf0u: goto P_0c0c2cf0;
case 0x0c0c2cf2u: goto P_0c0c2cf2;
case 0x0c0c2cf4u: goto P_0c0c2cf4;
case 0x0c0c2cf6u: goto P_0c0c2cf6;
case 0x0c0c2cf8u: goto P_0c0c2cf8;
case 0x0c0c2cfau: goto P_0c0c2cfa;
case 0x0c0c2cfcu: goto P_0c0c2cfc;
case 0x0c0c2cfeu: goto P_0c0c2cfe;
case 0x0c0c2d00u: goto P_0c0c2d00;
case 0x0c0c2d02u: goto P_0c0c2d02;
case 0x0c0c2d04u: goto P_0c0c2d04;
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
case 0x0c0c61a8u: goto P_0c0c61a8;
case 0x0c0c61aau: goto P_0c0c61aa;
case 0x0c0c61acu: goto P_0c0c61ac;
case 0x0c0c61aeu: goto P_0c0c61ae;
case 0x0c0c61b0u: goto P_0c0c61b0;
case 0x0c0c61b2u: goto P_0c0c61b2;
case 0x0c0c61b4u: goto P_0c0c61b4;
case 0x0c0c61b6u: goto P_0c0c61b6;
case 0x0c0c61b8u: goto P_0c0c61b8;
case 0x0c0c61bau: goto P_0c0c61ba;
case 0x0c0c61bcu: goto P_0c0c61bc;
case 0x0c0c61beu: goto P_0c0c61be;
case 0x0c0c61c0u: goto P_0c0c61c0;
case 0x0c0c61c2u: goto P_0c0c61c2;
case 0x0c0c61c4u: goto P_0c0c61c4;
case 0x0c0c61c6u: goto P_0c0c61c6;
case 0x0c0c61c8u: goto P_0c0c61c8;
case 0x0c0c61cau: goto P_0c0c61ca;
case 0x0c0c61ccu: goto P_0c0c61cc;
case 0x0c0c61ceu: goto P_0c0c61ce;
case 0x0c0c61d0u: goto P_0c0c61d0;
case 0x0c0c61d2u: goto P_0c0c61d2;
case 0x0c0c61d4u: goto P_0c0c61d4;
case 0x0c0c61d6u: goto P_0c0c61d6;
case 0x0c0c61d8u: goto P_0c0c61d8;
case 0x0c0c61dau: goto P_0c0c61da;
case 0x0c0c61dcu: goto P_0c0c61dc;
case 0x0c0c61deu: goto P_0c0c61de;
case 0x0c0c61e0u: goto P_0c0c61e0;
case 0x0c0c61e2u: goto P_0c0c61e2;
case 0x0c0c61e4u: goto P_0c0c61e4;
case 0x0c0c61e6u: goto P_0c0c61e6;
case 0x0c0c61e8u: goto P_0c0c61e8;
case 0x0c0c61eau: goto P_0c0c61ea;
case 0x0c0c61ecu: goto P_0c0c61ec;
case 0x0c0c61eeu: goto P_0c0c61ee;
case 0x0c0c61f0u: goto P_0c0c61f0;
case 0x0c0c61f2u: goto P_0c0c61f2;
case 0x0c0c61f4u: goto P_0c0c61f4;
case 0x0c0c61f6u: goto P_0c0c61f6;
case 0x0c0c61f8u: goto P_0c0c61f8;
case 0x0c0c61fau: goto P_0c0c61fa;
case 0x0c0c61fcu: goto P_0c0c61fc;
case 0x0c0c61feu: goto P_0c0c61fe;
case 0x0c0c6200u: goto P_0c0c6200;
case 0x0c0c6202u: goto P_0c0c6202;
case 0x0c0c6204u: goto P_0c0c6204;
case 0x0c0c6206u: goto P_0c0c6206;
case 0x0c0c6208u: goto P_0c0c6208;
case 0x0c0c620au: goto P_0c0c620a;
case 0x0c0c620cu: goto P_0c0c620c;
case 0x0c0c620eu: goto P_0c0c620e;
case 0x0c0c6210u: goto P_0c0c6210;
case 0x0c0c6212u: goto P_0c0c6212;
case 0x0c0c6214u: goto P_0c0c6214;
case 0x0c0c6216u: goto P_0c0c6216;
case 0x0c0c6218u: goto P_0c0c6218;
case 0x0c0c621au: goto P_0c0c621a;
case 0x0c0c621cu: goto P_0c0c621c;
case 0x0c0c621eu: goto P_0c0c621e;
case 0x0c0c6220u: goto P_0c0c6220;
case 0x0c0c6222u: goto P_0c0c6222;
case 0x0c0c6224u: goto P_0c0c6224;
case 0x0c0c6226u: goto P_0c0c6226;
case 0x0c0c6228u: goto P_0c0c6228;
case 0x0c0c622au: goto P_0c0c622a;
case 0x0c0c622cu: goto P_0c0c622c;
case 0x0c0c622eu: goto P_0c0c622e;
case 0x0c0c6230u: goto P_0c0c6230;
case 0x0c0c6232u: goto P_0c0c6232;
case 0x0c0c6234u: goto P_0c0c6234;
case 0x0c0c6236u: goto P_0c0c6236;
case 0x0c0c6238u: goto P_0c0c6238;
case 0x0c0c623au: goto P_0c0c623a;
case 0x0c0c623cu: goto P_0c0c623c;
case 0x0c0c623eu: goto P_0c0c623e;
case 0x0c0c6240u: goto P_0c0c6240;
case 0x0c0c6242u: goto P_0c0c6242;
case 0x0c0c6244u: goto P_0c0c6244;
case 0x0c0c6246u: goto P_0c0c6246;
case 0x0c0c6248u: goto P_0c0c6248;
case 0x0c0c624au: goto P_0c0c624a;
case 0x0c0c624cu: goto P_0c0c624c;
case 0x0c0c624eu: goto P_0c0c624e;
case 0x0c0c6250u: goto P_0c0c6250;
case 0x0c0c6252u: goto P_0c0c6252;
case 0x0c0c6254u: goto P_0c0c6254;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c2c70: /* original 2fe6, guest PC 0x0c0c2c70 */
if(!s->budget--) { s->failed_pc=0x0c0c2c70u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2c72;
P_0c0c2c72: /* original e500, guest PC 0x0c0c2c72 */
if(!s->budget--) { s->failed_pc=0x0c0c2c72u; return 0; }
r[5]=0x00000000u;
goto P_0c0c2c74;
P_0c0c2c74: /* original 2fd6, guest PC 0x0c0c2c74 */
if(!s->budget--) { s->failed_pc=0x0c0c2c74u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2c76;
P_0c0c2c76: /* original 6e53, guest PC 0x0c0c2c76 */
if(!s->budget--) { s->failed_pc=0x0c0c2c76u; return 0; }
r[14]=r[5];
goto P_0c0c2c78;
P_0c0c2c78: /* original 2fc6, guest PC 0x0c0c2c78 */
if(!s->budget--) { s->failed_pc=0x0c0c2c78u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2c7a;
P_0c0c2c7a: /* original 2fb6, guest PC 0x0c0c2c7a */
if(!s->budget--) { s->failed_pc=0x0c0c2c7au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2c7c;
P_0c0c2c7c: /* original 6b43, guest PC 0x0c0c2c7c */
if(!s->budget--) { s->failed_pc=0x0c0c2c7cu; return 0; }
r[11]=r[4];
goto P_0c0c2c7e;
P_0c0c2c7e: /* original 2fa6, guest PC 0x0c0c2c7e */
if(!s->budget--) { s->failed_pc=0x0c0c2c7eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2c80;
P_0c0c2c80: /* original 7bfc, guest PC 0x0c0c2c80 */
if(!s->budget--) { s->failed_pc=0x0c0c2c80u; return 0; }
r[11]+=0xfffffffcu;
goto P_0c0c2c82;
P_0c0c2c82: /* original fffb, guest PC 0x0c0c2c82 */
if(!s->budget--) { s->failed_pc=0x0c0c2c82u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0c2c84;
P_0c0c2c84: /* original ffeb, guest PC 0x0c0c2c84 */
if(!s->budget--) { s->failed_pc=0x0c0c2c84u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0c2c86;
P_0c0c2c86: /* original 907f, guest PC 0x0c0c2c86 */
if(!s->budget--) { s->failed_pc=0x0c0c2c86u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d88u,2);
goto P_0c0c2c88;
P_0c0c2c88: /* original 4f22, guest PC 0x0c0c2c88 */
if(!s->budget--) { s->failed_pc=0x0c0c2c88u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2c8a;
P_0c0c2c8a: /* original 0456, guest PC 0x0c0c2c8a */
if(!s->budget--) { s->failed_pc=0x0c0c2c8au; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c2c8c;
P_0c0c2c8c: /* original c741, guest PC 0x0c0c2c8c */
if(!s->budget--) { s->failed_pc=0x0c0c2c8cu; return 0; }
r[0]=code_base|0x000c2d94u;
goto P_0c0c2c8e;
P_0c0c2c8e: /* original ff08, guest PC 0x0c0c2c8e */
if(!s->budget--) { s->failed_pc=0x0c0c2c8eu; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c0c2c90;
P_0c0c2c90: /* original c741, guest PC 0x0c0c2c90 */
if(!s->budget--) { s->failed_pc=0x0c0c2c90u; return 0; }
r[0]=code_base|0x000c2d98u;
goto P_0c0c2c92;
P_0c0c2c92: /* original da42, guest PC 0x0c0c2c92 */
if(!s->budget--) { s->failed_pc=0x0c0c2c92u; return 0; }
r[10]=read(ram,0x0c0c2d9cu,4);
goto P_0c0c2c94;
P_0c0c2c94: /* original fe08, guest PC 0x0c0c2c94 */
if(!s->budget--) { s->failed_pc=0x0c0c2c94u; return 0; }
vf3_matrix_load(s,ram,14,r[0]);
goto P_0c0c2c96;
P_0c0c2c96: /* original 9d79, guest PC 0x0c0c2c96 */
if(!s->budget--) { s->failed_pc=0x0c0c2c96u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8cu,2);
goto P_0c0c2c98;
P_0c0c2c98: /* original 9c77, guest PC 0x0c0c2c98 */
if(!s->budget--) { s->failed_pc=0x0c0c2c98u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8au,2);
goto P_0c0c2c9a;
P_0c0c2c9a: /* original 4a0b, guest PC 0x0c0c2c9a */
if(!s->budget--) { s->failed_pc=0x0c0c2c9au; return 0; }
target=r[10];
r[16]=code_base|0x0c0c2c9eu;
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2c9eu) { target=s->pc; goto dispatch; }
goto P_0c0c2c9e;
P_0c0c2c9c: /* original 64ef, guest PC 0x0c0c2c9c */
if(!s->budget--) { s->failed_pc=0x0c0c2c9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c0c2c9e;
P_0c0c2c9e: /* original f40c, guest PC 0x0c0c2c9e */
if(!s->budget--) { s->failed_pc=0x0c0c2c9eu; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0c2ca0;
P_0c0c2ca0: /* original 7b04, guest PC 0x0c0c2ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca0u; return 0; }
r[11]+=0x00000004u;
goto P_0c0c2ca2;
P_0c0c2ca2: /* original f0fc, guest PC 0x0c0c2ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c0c2ca4;
P_0c0c2ca4: /* original 4d10, guest PC 0x0c0c2ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca4u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c0c2ca6;
P_0c0c2ca6: /* original f3ec, guest PC 0x0c0c2ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca6u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0c2ca8;
P_0c0c2ca8: /* original f34e, guest PC 0x0c0c2ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ca8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c0c2caa;
P_0c0c2caa: /* original 3ecc, guest PC 0x0c0c2caa */
if(!s->budget--) { s->failed_pc=0x0c0c2caau; return 0; }
r[14]+=r[12];
goto P_0c0c2cac;
P_0c0c2cac: /* original f43c, guest PC 0x0c0c2cac */
if(!s->budget--) { s->failed_pc=0x0c0c2cacu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0c2cae;
P_0c0c2cae: /* original f43d, guest PC 0x0c0c2cae */
if(!s->budget--) { s->failed_pc=0x0c0c2caeu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0c2cb0;
P_0c0c2cb0: /* original 035a, guest PC 0x0c0c2cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb0u; return 0; }
r[3]=r[53];
goto P_0c0c2cb2;
P_0c0c2cb2: /* original 2b32, guest PC 0x0c0c2cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb2u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c0c2cb4;
P_0c0c2cb4: /* original 8ff1, guest PC 0x0c0c2cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb4u; return 0; }
cond=r[17]&1u;
r[14]=r[14]&65535u;
if(!cond) { goto P_0c0c2c9a; }
goto P_0c0c2cb8;
P_0c0c2cb6: /* original 6eed, guest PC 0x0c0c2cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb6u; return 0; }
r[14]=r[14]&65535u;
goto P_0c0c2cb8;
P_0c0c2cb8: /* original 4f26, guest PC 0x0c0c2cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c2cb8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2cba;
P_0c0c2cba: /* original fef9, guest PC 0x0c0c2cba */
if(!s->budget--) { s->failed_pc=0x0c0c2cbau; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2cbc;
P_0c0c2cbc: /* original fff9, guest PC 0x0c0c2cbc */
if(!s->budget--) { s->failed_pc=0x0c0c2cbcu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c2cbe;
P_0c0c2cbe: /* original 6af6, guest PC 0x0c0c2cbe */
if(!s->budget--) { s->failed_pc=0x0c0c2cbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c2cc0;
P_0c0c2cc0: /* original 6bf6, guest PC 0x0c0c2cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c2cc2;
P_0c0c2cc2: /* original 6cf6, guest PC 0x0c0c2cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c2cc4;
P_0c0c2cc4: /* original 6df6, guest PC 0x0c0c2cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c2cc6;
P_0c0c2cc6: /* original 000b, guest PC 0x0c0c2cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2cc8: /* original 6ef6, guest PC 0x0c0c2cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c2cc8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c2cca;
P_0c0c2cca: /* original 2fe6, guest PC 0x0c0c2cca */
if(!s->budget--) { s->failed_pc=0x0c0c2ccau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c2ccc;
P_0c0c2ccc: /* original e71f, guest PC 0x0c0c2ccc */
if(!s->budget--) { s->failed_pc=0x0c0c2cccu; return 0; }
r[7]=0x0000001fu;
goto P_0c0c2cce;
P_0c0c2cce: /* original 4f22, guest PC 0x0c0c2cce */
if(!s->budget--) { s->failed_pc=0x0c0c2cceu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c2cd0;
P_0c0c2cd0: /* original 945d, guest PC 0x0c0c2cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c2cd0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d8eu,2);
goto P_0c0c2cd2;
P_0c0c2cd2: /* original 6673, guest PC 0x0c0c2cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c2cd2u; return 0; }
r[6]=r[7];
goto P_0c0c2cd4;
P_0c0c2cd4: /* original d333, guest PC 0x0c0c2cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c2cd4u; return 0; }
r[3]=read(ram,0x0c0c2da4u,4);
goto P_0c0c2cd6;
P_0c0c2cd6: /* original 6573, guest PC 0x0c0c2cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c2cd6u; return 0; }
r[5]=r[7];
goto P_0c0c2cd8;
P_0c0c2cd8: /* original de31, guest PC 0x0c0c2cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c2cd8u; return 0; }
r[14]=read(ram,0x0c0c2da0u,4);
goto P_0c0c2cda;
P_0c0c2cda: /* original 430b, guest PC 0x0c0c2cda */
if(!s->budget--) { s->failed_pc=0x0c0c2cdau; return 0; }
target=r[3];
r[16]=code_base|0x0c0c2cdeu;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2cdeu) { target=s->pc; goto dispatch; }
goto P_0c0c2cde;
P_0c0c2cdc: /* original 34ec, guest PC 0x0c0c2cdc */
if(!s->budget--) { s->failed_pc=0x0c0c2cdcu; return 0; }
r[4]+=r[14];
goto P_0c0c2cde;
P_0c0c2cde: /* original 9457, guest PC 0x0c0c2cde */
if(!s->budget--) { s->failed_pc=0x0c0c2cdeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c2d90u,2);
goto P_0c0c2ce0;
P_0c0c2ce0: /* original 66e3, guest PC 0x0c0c2ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c2ce0u; return 0; }
r[6]=r[14];
goto P_0c0c2ce2;
P_0c0c2ce2: /* original d231, guest PC 0x0c0c2ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c2ce2u; return 0; }
r[2]=read(ram,0x0c0c2da8u,4);
goto P_0c0c2ce4;
P_0c0c2ce4: /* original 7658, guest PC 0x0c0c2ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c2ce4u; return 0; }
r[6]+=0x00000058u;
goto P_0c0c2ce6;
P_0c0c2ce6: /* original 420b, guest PC 0x0c0c2ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c2ce6u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c2ceau;
r[5]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2ceau) { target=s->pc; goto dispatch; }
goto P_0c0c2cea;
P_0c0c2ce8: /* original 65e3, guest PC 0x0c0c2ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c2ce8u; return 0; }
r[5]=r[14];
goto P_0c0c2cea;
P_0c0c2cea: /* original de30, guest PC 0x0c0c2cea */
if(!s->budget--) { s->failed_pc=0x0c0c2ceau; return 0; }
r[14]=read(ram,0x0c0c2dacu,4);
goto P_0c0c2cec;
P_0c0c2cec: /* original 64e3, guest PC 0x0c0c2cec */
if(!s->budget--) { s->failed_pc=0x0c0c2cecu; return 0; }
r[4]=r[14];
goto P_0c0c2cee;
P_0c0c2cee: /* original bfbf, guest PC 0x0c0c2cee */
if(!s->budget--) { s->failed_pc=0x0c0c2ceeu; return 0; }
target=code_base|0x0c0c2c70u; r[16]=code_base|0x0c0c2cf2u;
r[4]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c2cf2u) { target=s->pc; goto dispatch; }
goto P_0c0c2cf2;
P_0c0c2cf0: /* original 740c, guest PC 0x0c0c2cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c2cf0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0c2cf2;
P_0c0c2cf2: /* original c72f, guest PC 0x0c0c2cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c2cf2u; return 0; }
r[0]=code_base|0x000c2db0u;
goto P_0c0c2cf4;
P_0c0c2cf4: /* original 4f26, guest PC 0x0c0c2cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c2cf4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c2cf6;
P_0c0c2cf6: /* original f308, guest PC 0x0c0c2cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c2cf6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c2cf8;
P_0c0c2cf8: /* original e200, guest PC 0x0c0c2cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c2cf8u; return 0; }
r[2]=0x00000000u;
goto P_0c0c2cfa;
P_0c0c2cfa: /* original e30f, guest PC 0x0c0c2cfa */
if(!s->budget--) { s->failed_pc=0x0c0c2cfau; return 0; }
r[3]=0x0000000fu;
goto P_0c0c2cfc;
P_0c0c2cfc: /* original fe3a, guest PC 0x0c0c2cfc */
if(!s->budget--) { s->failed_pc=0x0c0c2cfcu; return 0; }
vf3_matrix_store(s,ram,3,r[14]);
goto P_0c0c2cfe;
P_0c0c2cfe: /* original 1e31, guest PC 0x0c0c2cfe */
if(!s->budget--) { s->failed_pc=0x0c0c2cfeu; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c0c2d00;
P_0c0c2d00: /* original 1e22, guest PC 0x0c0c2d00 */
if(!s->budget--) { s->failed_pc=0x0c0c2d00u; return 0; }
write(ram,r[14]+8,r[2],4);
goto P_0c0c2d02;
P_0c0c2d02: /* original 000b, guest PC 0x0c0c2d02 */
if(!s->budget--) { s->failed_pc=0x0c0c2d02u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c2d04: /* original 6ef6, guest PC 0x0c0c2d04 */
if(!s->budget--) { s->failed_pc=0x0c0c2d04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c2d06u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c2d06u; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c0c5d86u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c5d86u; return 0; } return 1;
P_0c0c61a8: /* original 2fe6, guest PC 0x0c0c61a8 */
if(!s->budget--) { s->failed_pc=0x0c0c61a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61aa;
P_0c0c61aa: /* original 4411, guest PC 0x0c0c61aa */
if(!s->budget--) { s->failed_pc=0x0c0c61aau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c0c61ac;
P_0c0c61ac: /* original 2fd6, guest PC 0x0c0c61ac */
if(!s->budget--) { s->failed_pc=0x0c0c61acu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61ae;
P_0c0c61ae: /* original 2fc6, guest PC 0x0c0c61ae */
if(!s->budget--) { s->failed_pc=0x0c0c61aeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b0;
P_0c0c61b0: /* original 2fb6, guest PC 0x0c0c61b0 */
if(!s->budget--) { s->failed_pc=0x0c0c61b0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b2;
P_0c0c61b2: /* original 2fa6, guest PC 0x0c0c61b2 */
if(!s->budget--) { s->failed_pc=0x0c0c61b2u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b4;
P_0c0c61b4: /* original 2f96, guest PC 0x0c0c61b4 */
if(!s->budget--) { s->failed_pc=0x0c0c61b4u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b6;
P_0c0c61b6: /* original 2f86, guest PC 0x0c0c61b6 */
if(!s->budget--) { s->failed_pc=0x0c0c61b6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c61b8;
P_0c0c61b8: /* original 4f22, guest PC 0x0c0c61b8 */
if(!s->budget--) { s->failed_pc=0x0c0c61b8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c61ba;
P_0c0c61ba: /* original 7ffc, guest PC 0x0c0c61ba */
if(!s->budget--) { s->failed_pc=0x0c0c61bau; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c61bc;
P_0c0c61bc: /* original 8b41, guest PC 0x0c0c61bc */
if(!s->budget--) { s->failed_pc=0x0c0c61bcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61be;
P_0c0c61be: /* original 924a, guest PC 0x0c0c61be */
if(!s->budget--) { s->failed_pc=0x0c0c61beu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6256u,2);
goto P_0c0c61c0;
P_0c0c61c0: /* original 3423, guest PC 0x0c0c61c0 */
if(!s->budget--) { s->failed_pc=0x0c0c61c0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c0c61c2;
P_0c0c61c2: /* original 893e, guest PC 0x0c0c61c2 */
if(!s->budget--) { s->failed_pc=0x0c0c61c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61c4;
P_0c0c61c4: /* original d325, guest PC 0x0c0c61c4 */
if(!s->budget--) { s->failed_pc=0x0c0c61c4u; return 0; }
r[3]=read(ram,0x0c0c625cu,4);
goto P_0c0c61c6;
P_0c0c61c6: /* original 6143, guest PC 0x0c0c61c6 */
if(!s->budget--) { s->failed_pc=0x0c0c61c6u; return 0; }
r[1]=r[4];
goto P_0c0c61c8;
P_0c0c61c8: /* original 4108, guest PC 0x0c0c61c8 */
if(!s->budget--) { s->failed_pc=0x0c0c61c8u; return 0; }
r[1]<<=2;
goto P_0c0c61ca;
P_0c0c61ca: /* original 313c, guest PC 0x0c0c61ca */
if(!s->budget--) { s->failed_pc=0x0c0c61cau; return 0; }
r[1]+=r[3];
goto P_0c0c61cc;
P_0c0c61cc: /* original 2f12, guest PC 0x0c0c61cc */
if(!s->budget--) { s->failed_pc=0x0c0c61ccu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0c61ce;
P_0c0c61ce: /* original 6212, guest PC 0x0c0c61ce */
if(!s->budget--) { s->failed_pc=0x0c0c61ceu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0c61d0;
P_0c0c61d0: /* original 4211, guest PC 0x0c0c61d0 */
if(!s->budget--) { s->failed_pc=0x0c0c61d0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c0c61d2;
P_0c0c61d2: /* original 8b36, guest PC 0x0c0c61d2 */
if(!s->budget--) { s->failed_pc=0x0c0c61d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c6242; }
goto P_0c0c61d4;
P_0c0c61d4: /* original da23, guest PC 0x0c0c61d4 */
if(!s->budget--) { s->failed_pc=0x0c0c61d4u; return 0; }
r[10]=read(ram,0x0c0c6264u,4);
goto P_0c0c61d6;
P_0c0c61d6: /* original ec00, guest PC 0x0c0c61d6 */
if(!s->budget--) { s->failed_pc=0x0c0c61d6u; return 0; }
r[12]=0x00000000u;
goto P_0c0c61d8;
P_0c0c61d8: /* original db23, guest PC 0x0c0c61d8 */
if(!s->budget--) { s->failed_pc=0x0c0c61d8u; return 0; }
r[11]=read(ram,0x0c0c6268u,4);
goto P_0c0c61da;
P_0c0c61da: /* original dd24, guest PC 0x0c0c61da */
if(!s->budget--) { s->failed_pc=0x0c0c61dau; return 0; }
r[13]=read(ram,0x0c0c626cu,4);
goto P_0c0c61dc;
P_0c0c61dc: /* original d920, guest PC 0x0c0c61dc */
if(!s->budget--) { s->failed_pc=0x0c0c61dcu; return 0; }
r[9]=read(ram,0x0c0c6260u,4);
goto P_0c0c61de;
P_0c0c61de: /* original 983b, guest PC 0x0c0c61de */
if(!s->budget--) { s->failed_pc=0x0c0c61deu; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c6258u,2);
goto P_0c0c61e0;
P_0c0c61e0: /* original 6ec3, guest PC 0x0c0c61e0 */
if(!s->budget--) { s->failed_pc=0x0c0c61e0u; return 0; }
r[14]=r[12];
goto P_0c0c61e2;
P_0c0c61e2: /* original 4e08, guest PC 0x0c0c61e2 */
if(!s->budget--) { s->failed_pc=0x0c0c61e2u; return 0; }
r[14]<<=2;
goto P_0c0c61e4;
P_0c0c61e4: /* original 4e00, guest PC 0x0c0c61e4 */
if(!s->budget--) { s->failed_pc=0x0c0c61e4u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c0c61e6;
P_0c0c61e6: /* original 3ebc, guest PC 0x0c0c61e6 */
if(!s->budget--) { s->failed_pc=0x0c0c61e6u; return 0; }
r[14]+=r[11];
goto P_0c0c61e8;
P_0c0c61e8: /* original 53e1, guest PC 0x0c0c61e8 */
if(!s->budget--) { s->failed_pc=0x0c0c61e8u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0c61ea;
P_0c0c61ea: /* original 2338, guest PC 0x0c0c61ea */
if(!s->budget--) { s->failed_pc=0x0c0c61eau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c61ec;
P_0c0c61ec: /* original 8929, guest PC 0x0c0c61ec */
if(!s->budget--) { s->failed_pc=0x0c0c61ecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6242; }
goto P_0c0c61ee;
P_0c0c61ee: /* original 52e1, guest PC 0x0c0c61ee */
if(!s->budget--) { s->failed_pc=0x0c0c61eeu; return 0; }
r[2]=read(ram,r[14]+4,4);
goto P_0c0c61f0;
P_0c0c61f0: /* original 3420, guest PC 0x0c0c61f0 */
if(!s->budget--) { s->failed_pc=0x0c0c61f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c0c61f2;
P_0c0c61f2: /* original 8b24, guest PC 0x0c0c61f2 */
if(!s->budget--) { s->failed_pc=0x0c0c61f2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c623e; }
goto P_0c0c61f4;
P_0c0c61f4: /* original 6392, guest PC 0x0c0c61f4 */
if(!s->budget--) { s->failed_pc=0x0c0c61f4u; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c0c61f6;
P_0c0c61f6: /* original 61e2, guest PC 0x0c0c61f6 */
if(!s->budget--) { s->failed_pc=0x0c0c61f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0c61f8;
P_0c0c61f8: /* original 3310, guest PC 0x0c0c61f8 */
if(!s->budget--) { s->failed_pc=0x0c0c61f8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c0c61fa;
P_0c0c61fa: /* original 891a, guest PC 0x0c0c61fa */
if(!s->budget--) { s->failed_pc=0x0c0c61fau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6232; }
goto P_0c0c61fc;
P_0c0c61fc: /* original 65a2, guest PC 0x0c0c61fc */
if(!s->budget--) { s->failed_pc=0x0c0c61fcu; return 0; }
tmp=read(ram,r[10],4);
r[5]=tmp;
goto P_0c0c61fe;
P_0c0c61fe: /* original d31c, guest PC 0x0c0c61fe */
if(!s->budget--) { s->failed_pc=0x0c0c61feu; return 0; }
r[3]=read(ram,0x0c0c6270u,4);
goto P_0c0c6200;
P_0c0c6200: /* original 35dc, guest PC 0x0c0c6200 */
if(!s->budget--) { s->failed_pc=0x0c0c6200u; return 0; }
r[5]+=r[13];
goto P_0c0c6202;
P_0c0c6202: /* original 430b, guest PC 0x0c0c6202 */
if(!s->budget--) { s->failed_pc=0x0c0c6202u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6206u;
tmp=read(ram,r[14],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6206u) { target=s->pc; goto dispatch; }
goto P_0c0c6206;
P_0c0c6204: /* original 64e2, guest PC 0x0c0c6204 */
if(!s->budget--) { s->failed_pc=0x0c0c6204u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0c6206;
P_0c0c6206: /* original d41b, guest PC 0x0c0c6206 */
if(!s->budget--) { s->failed_pc=0x0c0c6206u; return 0; }
r[4]=read(ram,0x0c0c6274u,4);
goto P_0c0c6208;
P_0c0c6208: /* original bd44, guest PC 0x0c0c6208 */
if(!s->budget--) { s->failed_pc=0x0c0c6208u; return 0; }
target=code_base|0x0c0c5c94u; r[16]=code_base|0x0c0c620cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c620cu) { target=s->pc; goto dispatch; }
goto P_0c0c620c;
P_0c0c620a: /* original e500, guest PC 0x0c0c620a */
if(!s->budget--) { s->failed_pc=0x0c0c620au; return 0; }
r[5]=0x00000000u;
goto P_0c0c620c;
P_0c0c620c: /* original d31a, guest PC 0x0c0c620c */
if(!s->budget--) { s->failed_pc=0x0c0c620cu; return 0; }
r[3]=read(ram,0x0c0c6278u,4);
goto P_0c0c620e;
P_0c0c620e: /* original 430b, guest PC 0x0c0c620e */
if(!s->budget--) { s->failed_pc=0x0c0c620eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0c6212u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6212u) { target=s->pc; goto dispatch; }
goto P_0c0c6212;
P_0c0c6210: /* original e403, guest PC 0x0c0c6210 */
if(!s->budget--) { s->failed_pc=0x0c0c6210u; return 0; }
r[4]=0x00000003u;
goto P_0c0c6212;
P_0c0c6212: /* original d21a, guest PC 0x0c0c6212 */
if(!s->budget--) { s->failed_pc=0x0c0c6212u; return 0; }
r[2]=read(ram,0x0c0c627cu,4);
goto P_0c0c6214;
P_0c0c6214: /* original e503, guest PC 0x0c0c6214 */
if(!s->budget--) { s->failed_pc=0x0c0c6214u; return 0; }
r[5]=0x00000003u;
goto P_0c0c6216;
P_0c0c6216: /* original 64a2, guest PC 0x0c0c6216 */
if(!s->budget--) { s->failed_pc=0x0c0c6216u; return 0; }
tmp=read(ram,r[10],4);
r[4]=tmp;
goto P_0c0c6218;
P_0c0c6218: /* original 420b, guest PC 0x0c0c6218 */
if(!s->budget--) { s->failed_pc=0x0c0c6218u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c621cu;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c621cu) { target=s->pc; goto dispatch; }
goto P_0c0c621c;
P_0c0c621a: /* original 34dc, guest PC 0x0c0c621a */
if(!s->budget--) { s->failed_pc=0x0c0c621au; return 0; }
r[4]+=r[13];
goto P_0c0c621c;
P_0c0c621c: /* original 2008, guest PC 0x0c0c621c */
if(!s->budget--) { s->failed_pc=0x0c0c621cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0c621e;
P_0c0c621e: /* original 8903, guest PC 0x0c0c621e */
if(!s->budget--) { s->failed_pc=0x0c0c621eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c6228; }
goto P_0c0c6220;
P_0c0c6220: /* original d217, guest PC 0x0c0c6220 */
if(!s->budget--) { s->failed_pc=0x0c0c6220u; return 0; }
r[2]=read(ram,0x0c0c6280u,4);
goto P_0c0c6222;
P_0c0c6222: /* original 6583, guest PC 0x0c0c6222 */
if(!s->budget--) { s->failed_pc=0x0c0c6222u; return 0; }
r[5]=r[8];
goto P_0c0c6224;
P_0c0c6224: /* original 420b, guest PC 0x0c0c6224 */
if(!s->budget--) { s->failed_pc=0x0c0c6224u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c6228u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c6228u) { target=s->pc; goto dispatch; }
goto P_0c0c6228;
P_0c0c6226: /* original e401, guest PC 0x0c0c6226 */
if(!s->budget--) { s->failed_pc=0x0c0c6226u; return 0; }
r[4]=0x00000001u;
goto P_0c0c6228;
P_0c0c6228: /* original 4c08, guest PC 0x0c0c6228 */
if(!s->budget--) { s->failed_pc=0x0c0c6228u; return 0; }
r[12]<<=2;
goto P_0c0c622a;
P_0c0c622a: /* original 4c00, guest PC 0x0c0c622a */
if(!s->budget--) { s->failed_pc=0x0c0c622au; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c0c622c;
P_0c0c622c: /* original 3cbc, guest PC 0x0c0c622c */
if(!s->budget--) { s->failed_pc=0x0c0c622cu; return 0; }
r[12]+=r[11];
goto P_0c0c622e;
P_0c0c622e: /* original 63c2, guest PC 0x0c0c622e */
if(!s->budget--) { s->failed_pc=0x0c0c622eu; return 0; }
tmp=read(ram,r[12],4);
r[3]=tmp;
goto P_0c0c6230;
P_0c0c6230: /* original 2932, guest PC 0x0c0c6230 */
if(!s->budget--) { s->failed_pc=0x0c0c6230u; return 0; }
write(ram,r[9],r[3],4);
goto P_0c0c6232;
P_0c0c6232: /* original d314, guest PC 0x0c0c6232 */
if(!s->budget--) { s->failed_pc=0x0c0c6232u; return 0; }
r[3]=read(ram,0x0c0c6284u,4);
goto P_0c0c6234;
P_0c0c6234: /* original 64f2, guest PC 0x0c0c6234 */
if(!s->budget--) { s->failed_pc=0x0c0c6234u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0c6236;
P_0c0c6236: /* original 430b, guest PC 0x0c0c6236 */
if(!s->budget--) { s->failed_pc=0x0c0c6236u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c623au;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c623au) { target=s->pc; goto dispatch; }
goto P_0c0c623a;
P_0c0c6238: /* original 6442, guest PC 0x0c0c6238 */
if(!s->budget--) { s->failed_pc=0x0c0c6238u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c0c623a;
P_0c0c623a: /* original a002, guest PC 0x0c0c623a */
if(!s->budget--) { s->failed_pc=0x0c0c623au; return 0; }
goto P_0c0c6242;
P_0c0c623c: /* original 0009, guest PC 0x0c0c623c */
if(!s->budget--) { s->failed_pc=0x0c0c623cu; return 0; }
goto P_0c0c623e;
P_0c0c623e: /* original afcf, guest PC 0x0c0c623e */
if(!s->budget--) { s->failed_pc=0x0c0c623eu; return 0; }
r[12]+=0x00000001u;
goto P_0c0c61e0;
P_0c0c6240: /* original 7c01, guest PC 0x0c0c6240 */
if(!s->budget--) { s->failed_pc=0x0c0c6240u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c6242;
P_0c0c6242: /* original 7f04, guest PC 0x0c0c6242 */
if(!s->budget--) { s->failed_pc=0x0c0c6242u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c6244;
P_0c0c6244: /* original 4f26, guest PC 0x0c0c6244 */
if(!s->budget--) { s->failed_pc=0x0c0c6244u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c6246;
P_0c0c6246: /* original 68f6, guest PC 0x0c0c6246 */
if(!s->budget--) { s->failed_pc=0x0c0c6246u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c6248;
P_0c0c6248: /* original 69f6, guest PC 0x0c0c6248 */
if(!s->budget--) { s->failed_pc=0x0c0c6248u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c624a;
P_0c0c624a: /* original 6af6, guest PC 0x0c0c624a */
if(!s->budget--) { s->failed_pc=0x0c0c624au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c624c;
P_0c0c624c: /* original 6bf6, guest PC 0x0c0c624c */
if(!s->budget--) { s->failed_pc=0x0c0c624cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c624e;
P_0c0c624e: /* original 6cf6, guest PC 0x0c0c624e */
if(!s->budget--) { s->failed_pc=0x0c0c624eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c6250;
P_0c0c6250: /* original 6df6, guest PC 0x0c0c6250 */
if(!s->budget--) { s->failed_pc=0x0c0c6250u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c6252;
P_0c0c6252: /* original 000b, guest PC 0x0c0c6252 */
if(!s->budget--) { s->failed_pc=0x0c0c6252u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c6254: /* original 6ef6, guest PC 0x0c0c6254 */
if(!s->budget--) { s->failed_pc=0x0c0c6254u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c6256u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c6256u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
