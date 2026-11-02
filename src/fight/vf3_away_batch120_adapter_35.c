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
int vf3_away_batch120_adapter_35(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c7c50u: goto P_0c0c7c50;
case 0x0c0c7c52u: goto P_0c0c7c52;
case 0x0c0c7c54u: goto P_0c0c7c54;
case 0x0c0c7c56u: goto P_0c0c7c56;
case 0x0c0c7c58u: goto P_0c0c7c58;
case 0x0c0c7c5au: goto P_0c0c7c5a;
case 0x0c0c7c5cu: goto P_0c0c7c5c;
case 0x0c0c7c5eu: goto P_0c0c7c5e;
case 0x0c0c7c60u: goto P_0c0c7c60;
case 0x0c0c7c62u: goto P_0c0c7c62;
case 0x0c0c7c64u: goto P_0c0c7c64;
case 0x0c0c7c66u: goto P_0c0c7c66;
case 0x0c0c7c68u: goto P_0c0c7c68;
case 0x0c0c7c6au: goto P_0c0c7c6a;
case 0x0c0c7c6cu: goto P_0c0c7c6c;
case 0x0c0c7c6eu: goto P_0c0c7c6e;
case 0x0c0c7c70u: goto P_0c0c7c70;
case 0x0c0c7c72u: goto P_0c0c7c72;
case 0x0c0c7c74u: goto P_0c0c7c74;
case 0x0c0c7c76u: goto P_0c0c7c76;
case 0x0c0c7c78u: goto P_0c0c7c78;
case 0x0c0c7c7au: goto P_0c0c7c7a;
case 0x0c0c7c7cu: goto P_0c0c7c7c;
case 0x0c0c7c7eu: goto P_0c0c7c7e;
case 0x0c0c7c80u: goto P_0c0c7c80;
case 0x0c0c7c82u: goto P_0c0c7c82;
case 0x0c0c7c84u: goto P_0c0c7c84;
case 0x0c0c7c86u: goto P_0c0c7c86;
case 0x0c0c7c88u: goto P_0c0c7c88;
case 0x0c0c7c8au: goto P_0c0c7c8a;
case 0x0c0c7c8cu: goto P_0c0c7c8c;
case 0x0c0c7c8eu: goto P_0c0c7c8e;
case 0x0c0c7c90u: goto P_0c0c7c90;
case 0x0c0c7c92u: goto P_0c0c7c92;
case 0x0c0c7c94u: goto P_0c0c7c94;
case 0x0c0c7c96u: goto P_0c0c7c96;
case 0x0c0c7c98u: goto P_0c0c7c98;
case 0x0c0c7c9au: goto P_0c0c7c9a;
case 0x0c0c7c9cu: goto P_0c0c7c9c;
case 0x0c0c7c9eu: goto P_0c0c7c9e;
case 0x0c0c7ca0u: goto P_0c0c7ca0;
case 0x0c0c7ca2u: goto P_0c0c7ca2;
case 0x0c0c7ca4u: goto P_0c0c7ca4;
case 0x0c0c7ca6u: goto P_0c0c7ca6;
case 0x0c0c7ca8u: goto P_0c0c7ca8;
case 0x0c0c7caau: goto P_0c0c7caa;
case 0x0c0c7cacu: goto P_0c0c7cac;
case 0x0c0c7caeu: goto P_0c0c7cae;
case 0x0c0c7cb0u: goto P_0c0c7cb0;
case 0x0c0c7cb2u: goto P_0c0c7cb2;
case 0x0c0c7cb4u: goto P_0c0c7cb4;
case 0x0c0c7cb6u: goto P_0c0c7cb6;
case 0x0c0c7cb8u: goto P_0c0c7cb8;
case 0x0c0c7cbau: goto P_0c0c7cba;
case 0x0c0c7cbcu: goto P_0c0c7cbc;
case 0x0c0c7cbeu: goto P_0c0c7cbe;
case 0x0c0c7cc0u: goto P_0c0c7cc0;
case 0x0c0c7cc2u: goto P_0c0c7cc2;
case 0x0c0c7cc4u: goto P_0c0c7cc4;
case 0x0c0c7cc6u: goto P_0c0c7cc6;
case 0x0c0c7cc8u: goto P_0c0c7cc8;
case 0x0c0c7ccau: goto P_0c0c7cca;
case 0x0c0c7cccu: goto P_0c0c7ccc;
case 0x0c0c7cceu: goto P_0c0c7cce;
case 0x0c0c7cd0u: goto P_0c0c7cd0;
case 0x0c0c7cd2u: goto P_0c0c7cd2;
case 0x0c0c7cd4u: goto P_0c0c7cd4;
case 0x0c0c7cd6u: goto P_0c0c7cd6;
case 0x0c0c7cd8u: goto P_0c0c7cd8;
case 0x0c0c7cdau: goto P_0c0c7cda;
case 0x0c0c7cdcu: goto P_0c0c7cdc;
case 0x0c0c7cdeu: goto P_0c0c7cde;
case 0x0c0c7ce0u: goto P_0c0c7ce0;
case 0x0c0c7ce2u: goto P_0c0c7ce2;
case 0x0c0c7ce4u: goto P_0c0c7ce4;
case 0x0c0c7ce6u: goto P_0c0c7ce6;
case 0x0c0c7ce8u: goto P_0c0c7ce8;
case 0x0c0c7ceau: goto P_0c0c7cea;
case 0x0c0c7cecu: goto P_0c0c7cec;
case 0x0c0c7ceeu: goto P_0c0c7cee;
case 0x0c0c7cf0u: goto P_0c0c7cf0;
case 0x0c0c7cf2u: goto P_0c0c7cf2;
case 0x0c0c7cf4u: goto P_0c0c7cf4;
case 0x0c0c7cf6u: goto P_0c0c7cf6;
case 0x0c0c7cf8u: goto P_0c0c7cf8;
case 0x0c0c7cfau: goto P_0c0c7cfa;
case 0x0c0c7cfcu: goto P_0c0c7cfc;
case 0x0c0c7cfeu: goto P_0c0c7cfe;
case 0x0c0c7d00u: goto P_0c0c7d00;
case 0x0c0c7d02u: goto P_0c0c7d02;
case 0x0c0c7d04u: goto P_0c0c7d04;
case 0x0c0c7d06u: goto P_0c0c7d06;
case 0x0c0c7d08u: goto P_0c0c7d08;
case 0x0c0c7d0au: goto P_0c0c7d0a;
case 0x0c0c7d0cu: goto P_0c0c7d0c;
case 0x0c0c7d0eu: goto P_0c0c7d0e;
case 0x0c0c7d10u: goto P_0c0c7d10;
case 0x0c0c7d12u: goto P_0c0c7d12;
case 0x0c0c7d14u: goto P_0c0c7d14;
case 0x0c0c7d16u: goto P_0c0c7d16;
case 0x0c0c7d18u: goto P_0c0c7d18;
case 0x0c0c7d1au: goto P_0c0c7d1a;
case 0x0c0c7d1cu: goto P_0c0c7d1c;
case 0x0c0c7d1eu: goto P_0c0c7d1e;
case 0x0c0c7d20u: goto P_0c0c7d20;
case 0x0c0c7d22u: goto P_0c0c7d22;
case 0x0c0c7d24u: goto P_0c0c7d24;
case 0x0c0c7d26u: goto P_0c0c7d26;
case 0x0c0c7d28u: goto P_0c0c7d28;
case 0x0c0c7d2au: goto P_0c0c7d2a;
case 0x0c0c7d2cu: goto P_0c0c7d2c;
case 0x0c0c7d2eu: goto P_0c0c7d2e;
case 0x0c0c7d30u: goto P_0c0c7d30;
case 0x0c0c7d32u: goto P_0c0c7d32;
case 0x0c0c7d34u: goto P_0c0c7d34;
case 0x0c0c7d36u: goto P_0c0c7d36;
case 0x0c0c7d38u: goto P_0c0c7d38;
case 0x0c0c7d3au: goto P_0c0c7d3a;
case 0x0c0c7d3cu: goto P_0c0c7d3c;
case 0x0c0c7d3eu: goto P_0c0c7d3e;
case 0x0c0c7d40u: goto P_0c0c7d40;
case 0x0c0c7d42u: goto P_0c0c7d42;
case 0x0c0c7d44u: goto P_0c0c7d44;
case 0x0c0c7d46u: goto P_0c0c7d46;
case 0x0c0c7d48u: goto P_0c0c7d48;
case 0x0c0c7d4au: goto P_0c0c7d4a;
case 0x0c0c7d4cu: goto P_0c0c7d4c;
case 0x0c0c7d4eu: goto P_0c0c7d4e;
case 0x0c0c7d50u: goto P_0c0c7d50;
case 0x0c0c7d52u: goto P_0c0c7d52;
case 0x0c0c7d54u: goto P_0c0c7d54;
case 0x0c0c7d56u: goto P_0c0c7d56;
case 0x0c0c7d58u: goto P_0c0c7d58;
case 0x0c0c7d5au: goto P_0c0c7d5a;
case 0x0c0c7d5cu: goto P_0c0c7d5c;
case 0x0c0c7d5eu: goto P_0c0c7d5e;
case 0x0c0c7d60u: goto P_0c0c7d60;
case 0x0c0c7d62u: goto P_0c0c7d62;
case 0x0c0c7d64u: goto P_0c0c7d64;
case 0x0c0c7d66u: goto P_0c0c7d66;
case 0x0c0c7d68u: goto P_0c0c7d68;
case 0x0c0c7d6au: goto P_0c0c7d6a;
case 0x0c0c7d6cu: goto P_0c0c7d6c;
case 0x0c0c7d6eu: goto P_0c0c7d6e;
case 0x0c0c7d70u: goto P_0c0c7d70;
case 0x0c0c7d72u: goto P_0c0c7d72;
case 0x0c0c7d74u: goto P_0c0c7d74;
case 0x0c0c7d76u: goto P_0c0c7d76;
case 0x0c0c7d78u: goto P_0c0c7d78;
case 0x0c0c7de0u: goto P_0c0c7de0;
case 0x0c0c7de2u: goto P_0c0c7de2;
case 0x0c0c7de4u: goto P_0c0c7de4;
case 0x0c0c7de6u: goto P_0c0c7de6;
case 0x0c0ca234u: goto P_0c0ca234;
case 0x0c0ca236u: goto P_0c0ca236;
case 0x0c0ca238u: goto P_0c0ca238;
case 0x0c0ca23au: goto P_0c0ca23a;
case 0x0c0ca23cu: goto P_0c0ca23c;
case 0x0c0ca23eu: goto P_0c0ca23e;
case 0x0c0ca240u: goto P_0c0ca240;
case 0x0c0ca242u: goto P_0c0ca242;
case 0x0c0ca244u: goto P_0c0ca244;
case 0x0c0ca246u: goto P_0c0ca246;
case 0x0c0ca248u: goto P_0c0ca248;
case 0x0c0ca24au: goto P_0c0ca24a;
case 0x0c0ca24cu: goto P_0c0ca24c;
case 0x0c0ca24eu: goto P_0c0ca24e;
case 0x0c0ca250u: goto P_0c0ca250;
case 0x0c0ca252u: goto P_0c0ca252;
case 0x0c0ca254u: goto P_0c0ca254;
case 0x0c0ca256u: goto P_0c0ca256;
case 0x0c0ca258u: goto P_0c0ca258;
case 0x0c0ca25au: goto P_0c0ca25a;
case 0x0c0ca25cu: goto P_0c0ca25c;
case 0x0c0ca25eu: goto P_0c0ca25e;
case 0x0c0ca260u: goto P_0c0ca260;
case 0x0c0ca262u: goto P_0c0ca262;
case 0x0c0ca264u: goto P_0c0ca264;
case 0x0c0ca266u: goto P_0c0ca266;
case 0x0c0ca268u: goto P_0c0ca268;
case 0x0c0ca26au: goto P_0c0ca26a;
case 0x0c0ca26cu: goto P_0c0ca26c;
case 0x0c0ca26eu: goto P_0c0ca26e;
case 0x0c0ca270u: goto P_0c0ca270;
case 0x0c0ca272u: goto P_0c0ca272;
case 0x0c0ca274u: goto P_0c0ca274;
case 0x0c0ca276u: goto P_0c0ca276;
case 0x0c0ca278u: goto P_0c0ca278;
case 0x0c0ca27au: goto P_0c0ca27a;
case 0x0c0ca27cu: goto P_0c0ca27c;
case 0x0c0ca27eu: goto P_0c0ca27e;
case 0x0c0ca280u: goto P_0c0ca280;
case 0x0c0ca322u: goto P_0c0ca322;
case 0x0c0ca324u: goto P_0c0ca324;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c7c50: /* original 2fe6, guest PC 0x0c0c7c50 */
if(!s->budget--) { s->failed_pc=0x0c0c7c50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c52;
P_0c0c7c52: /* original e201, guest PC 0x0c0c7c52 */
if(!s->budget--) { s->failed_pc=0x0c0c7c52u; return 0; }
r[2]=0x00000001u;
goto P_0c0c7c54;
P_0c0c7c54: /* original 2fd6, guest PC 0x0c0c7c54 */
if(!s->budget--) { s->failed_pc=0x0c0c7c54u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c56;
P_0c0c7c56: /* original e07f, guest PC 0x0c0c7c56 */
if(!s->budget--) { s->failed_pc=0x0c0c7c56u; return 0; }
r[0]=0x0000007fu;
goto P_0c0c7c58;
P_0c0c7c58: /* original 2fc6, guest PC 0x0c0c7c58 */
if(!s->budget--) { s->failed_pc=0x0c0c7c58u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c5a;
P_0c0c7c5a: /* original ec34, guest PC 0x0c0c7c5a */
if(!s->budget--) { s->failed_pc=0x0c0c7c5au; return 0; }
r[12]=0x00000034u;
goto P_0c0c7c5c;
P_0c0c7c5c: /* original 2fb6, guest PC 0x0c0c7c5c */
if(!s->budget--) { s->failed_pc=0x0c0c7c5cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c5e;
P_0c0c7c5e: /* original 2fa6, guest PC 0x0c0c7c5e */
if(!s->budget--) { s->failed_pc=0x0c0c7c5eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c60;
P_0c0c7c60: /* original 2f96, guest PC 0x0c0c7c60 */
if(!s->budget--) { s->failed_pc=0x0c0c7c60u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7c62;
P_0c0c7c62: /* original d94b, guest PC 0x0c0c7c62 */
if(!s->budget--) { s->failed_pc=0x0c0c7c62u; return 0; }
r[9]=read(ram,0x0c0c7d90u,4);
goto P_0c0c7c64;
P_0c0c7c64: /* original 4f22, guest PC 0x0c0c7c64 */
if(!s->budget--) { s->failed_pc=0x0c0c7c64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7c66;
P_0c0c7c66: /* original d34c, guest PC 0x0c0c7c66 */
if(!s->budget--) { s->failed_pc=0x0c0c7c66u; return 0; }
r[3]=read(ram,0x0c0c7d98u,4);
goto P_0c0c7c68;
P_0c0c7c68: /* original db4a, guest PC 0x0c0c7c68 */
if(!s->budget--) { s->failed_pc=0x0c0c7c68u; return 0; }
r[11]=read(ram,0x0c0c7d94u,4);
goto P_0c0c7c6a;
P_0c0c7c6a: /* original 4f12, guest PC 0x0c0c7c6a */
if(!s->budget--) { s->failed_pc=0x0c0c7c6au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c7c6c;
P_0c0c7c6c: /* original 7ffc, guest PC 0x0c0c7c6c */
if(!s->budget--) { s->failed_pc=0x0c0c7c6cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0c7c6e;
P_0c0c7c6e: /* original 2f32, guest PC 0x0c0c7c6e */
if(!s->budget--) { s->failed_pc=0x0c0c7c6eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c7c70;
P_0c0c7c70: /* original 0924, guest PC 0x0c0c7c70 */
if(!s->budget--) { s->failed_pc=0x0c0c7c70u; return 0; }
write(ram,r[9]+r[0],r[2],1);
goto P_0c0c7c72;
P_0c0c7c72: /* original e01c, guest PC 0x0c0c7c72 */
if(!s->budget--) { s->failed_pc=0x0c0c7c72u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7c74;
P_0c0c7c74: /* original 0a9c, guest PC 0x0c0c7c74 */
if(!s->budget--) { s->failed_pc=0x0c0c7c74u; return 0; }
r[10]=(uint32_t)(int32_t)(int8_t)read(ram,r[9]+r[0],1);
goto P_0c0c7c76;
P_0c0c7c76: /* original d24a, guest PC 0x0c0c7c76 */
if(!s->budget--) { s->failed_pc=0x0c0c7c76u; return 0; }
r[2]=read(ram,0x0c0c7da0u,4);
goto P_0c0c7c78;
P_0c0c7c78: /* original 6aac, guest PC 0x0c0c7c78 */
if(!s->budget--) { s->failed_pc=0x0c0c7c78u; return 0; }
r[10]=r[10]&255u;
goto P_0c0c7c7a;
P_0c0c7c7a: /* original d348, guest PC 0x0c0c7c7a */
if(!s->budget--) { s->failed_pc=0x0c0c7c7au; return 0; }
r[3]=read(ram,0x0c0c7d9cu,4);
goto P_0c0c7c7c;
P_0c0c7c7c: /* original 2acf, guest PC 0x0c0c7c7c */
if(!s->budget--) { s->failed_pc=0x0c0c7c7cu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[10]*(int32_t)(int16_t)r[12]);
goto P_0c0c7c7e;
P_0c0c7c7e: /* original 6ea3, guest PC 0x0c0c7c7e */
if(!s->budget--) { s->failed_pc=0x0c0c7c7eu; return 0; }
r[14]=r[10];
goto P_0c0c7c80;
P_0c0c7c80: /* original 4e08, guest PC 0x0c0c7c80 */
if(!s->budget--) { s->failed_pc=0x0c0c7c80u; return 0; }
r[14]<<=2;
goto P_0c0c7c82;
P_0c0c7c82: /* original 4e08, guest PC 0x0c0c7c82 */
if(!s->budget--) { s->failed_pc=0x0c0c7c82u; return 0; }
r[14]<<=2;
goto P_0c0c7c84;
P_0c0c7c84: /* original 9079, guest PC 0x0c0c7c84 */
if(!s->budget--) { s->failed_pc=0x0c0c7c84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7au,2);
goto P_0c0c7c86;
P_0c0c7c86: /* original 4e08, guest PC 0x0c0c7c86 */
if(!s->budget--) { s->failed_pc=0x0c0c7c86u; return 0; }
r[14]<<=2;
goto P_0c0c7c88;
P_0c0c7c88: /* original 0c1a, guest PC 0x0c0c7c88 */
if(!s->budget--) { s->failed_pc=0x0c0c7c88u; return 0; }
r[12]=r[19];
goto P_0c0c7c8a;
P_0c0c7c8a: /* original 3e3c, guest PC 0x0c0c7c8a */
if(!s->budget--) { s->failed_pc=0x0c0c7c8au; return 0; }
r[14]+=r[3];
goto P_0c0c7c8c;
P_0c0c7c8c: /* original 6ccf, guest PC 0x0c0c7c8c */
if(!s->budget--) { s->failed_pc=0x0c0c7c8cu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c0c7c8e;
P_0c0c7c8e: /* original 3c2c, guest PC 0x0c0c7c8e */
if(!s->budget--) { s->failed_pc=0x0c0c7c8eu; return 0; }
r[12]+=r[2];
goto P_0c0c7c90;
P_0c0c7c90: /* original 0be6, guest PC 0x0c0c7c90 */
if(!s->budget--) { s->failed_pc=0x0c0c7c90u; return 0; }
write(ram,r[11]+r[0],r[14],4);
goto P_0c0c7c92;
P_0c0c7c92: /* original 7004, guest PC 0x0c0c7c92 */
if(!s->budget--) { s->failed_pc=0x0c0c7c92u; return 0; }
r[0]+=0x00000004u;
goto P_0c0c7c94;
P_0c0c7c94: /* original 65c3, guest PC 0x0c0c7c94 */
if(!s->budget--) { s->failed_pc=0x0c0c7c94u; return 0; }
r[5]=r[12];
goto P_0c0c7c96;
P_0c0c7c96: /* original 0bc6, guest PC 0x0c0c7c96 */
if(!s->budget--) { s->failed_pc=0x0c0c7c96u; return 0; }
write(ram,r[11]+r[0],r[12],4);
goto P_0c0c7c98;
P_0c0c7c98: /* original d342, guest PC 0x0c0c7c98 */
if(!s->budget--) { s->failed_pc=0x0c0c7c98u; return 0; }
r[3]=read(ram,0x0c0c7da4u,4);
goto P_0c0c7c9a;
P_0c0c7c9a: /* original 430b, guest PC 0x0c0c7c9a */
if(!s->budget--) { s->failed_pc=0x0c0c7c9au; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7c9eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7c9eu) { target=s->pc; goto dispatch; }
goto P_0c0c7c9e;
P_0c0c7c9c: /* original 64e3, guest PC 0x0c0c7c9c */
if(!s->budget--) { s->failed_pc=0x0c0c7c9cu; return 0; }
r[4]=r[14];
goto P_0c0c7c9e;
P_0c0c7c9e: /* original 63e2, guest PC 0x0c0c7c9e */
if(!s->budget--) { s->failed_pc=0x0c0c7c9eu; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0c7ca0;
P_0c0c7ca0: /* original 906c, guest PC 0x0c0c7ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7cu,2);
goto P_0c0c7ca2;
P_0c0c7ca2: /* original d241, guest PC 0x0c0c7ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca2u; return 0; }
r[2]=read(ram,0x0c0c7da8u,4);
goto P_0c0c7ca4;
P_0c0c7ca4: /* original 6d22, guest PC 0x0c0c7ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca4u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c0c7ca6;
P_0c0c7ca6: /* original 0b36, guest PC 0x0c0c7ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca6u; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c0c7ca8;
P_0c0c7ca8: /* original 6192, guest PC 0x0c0c7ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ca8u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c0c7caa;
P_0c0c7caa: /* original d340, guest PC 0x0c0c7caa */
if(!s->budget--) { s->failed_pc=0x0c0c7caau; return 0; }
r[3]=read(ram,0x0c0c7dacu,4);
goto P_0c0c7cac;
P_0c0c7cac: /* original 2138, guest PC 0x0c0c7cac */
if(!s->budget--) { s->failed_pc=0x0c0c7cacu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7cae;
P_0c0c7cae: /* original 8b03, guest PC 0x0c0c7cae */
if(!s->budget--) { s->failed_pc=0x0c0c7caeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7cb8; }
goto P_0c0c7cb0;
P_0c0c7cb0: /* original d23f, guest PC 0x0c0c7cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb0u; return 0; }
r[2]=read(ram,0x0c0c7db0u,4);
goto P_0c0c7cb2;
P_0c0c7cb2: /* original e034, guest PC 0x0c0c7cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb2u; return 0; }
r[0]=0x00000034u;
goto P_0c0c7cb4;
P_0c0c7cb4: /* original 420b, guest PC 0x0c0c7cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7cb8u;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7cb8u) { target=s->pc; goto dispatch; }
goto P_0c0c7cb8;
P_0c0c7cb6: /* original 04ed, guest PC 0x0c0c7cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c7cb8;
P_0c0c7cb8: /* original e036, guest PC 0x0c0c7cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cb8u; return 0; }
r[0]=0x00000036u;
goto P_0c0c7cba;
P_0c0c7cba: /* original 03ed, guest PC 0x0c0c7cba */
if(!s->budget--) { s->failed_pc=0x0c0c7cbau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0c7cbc;
P_0c0c7cbc: /* original e731, guest PC 0x0c0c7cbc */
if(!s->budget--) { s->failed_pc=0x0c0c7cbcu; return 0; }
r[7]=0x00000031u;
goto P_0c0c7cbe;
P_0c0c7cbe: /* original 905e, guest PC 0x0c0c7cbe */
if(!s->budget--) { s->failed_pc=0x0c0c7cbeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d7eu,2);
goto P_0c0c7cc0;
P_0c0c7cc0: /* original 6273, guest PC 0x0c0c7cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc0u; return 0; }
r[2]=r[7];
goto P_0c0c7cc2;
P_0c0c7cc2: /* original 7253, guest PC 0x0c0c7cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc2u; return 0; }
r[2]+=0x00000053u;
goto P_0c0c7cc4;
P_0c0c7cc4: /* original 0b35, guest PC 0x0c0c7cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc4u; return 0; }
write(ram,r[11]+r[0],r[3],2);
goto P_0c0c7cc6;
P_0c0c7cc6: /* original e300, guest PC 0x0c0c7cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc6u; return 0; }
r[3]=0x00000000u;
goto P_0c0c7cc8;
P_0c0c7cc8: /* original 915a, guest PC 0x0c0c7cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cc8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d80u,2);
goto P_0c0c7cca;
P_0c0c7cca: /* original e640, guest PC 0x0c0c7cca */
if(!s->budget--) { s->failed_pc=0x0c0c7ccau; return 0; }
r[6]=0x00000040u;
goto P_0c0c7ccc;
P_0c0c7ccc: /* original 85c6, guest PC 0x0c0c7ccc */
if(!s->budget--) { s->failed_pc=0x0c0c7cccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[12]+12,2);
goto P_0c0c7cce;
P_0c0c7cce: /* original 6533, guest PC 0x0c0c7cce */
if(!s->budget--) { s->failed_pc=0x0c0c7cceu; return 0; }
r[5]=r[3];
goto P_0c0c7cd0;
P_0c0c7cd0: /* original 31bc, guest PC 0x0c0c7cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd0u; return 0; }
r[1]+=r[11];
goto P_0c0c7cd2;
P_0c0c7cd2: /* original 2101, guest PC 0x0c0c7cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd2u; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0c7cd4;
P_0c0c7cd4: /* original 2f36, guest PC 0x0c0c7cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd4u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0c7cd6;
P_0c0c7cd6: /* original 54f1, guest PC 0x0c0c7cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd6u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0c7cd8;
P_0c0c7cd8: /* original d136, guest PC 0x0c0c7cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cd8u; return 0; }
r[1]=read(ram,0x0c0c7db4u,4);
goto P_0c0c7cda;
P_0c0c7cda: /* original 410b, guest PC 0x0c0c7cda */
if(!s->budget--) { s->failed_pc=0x0c0c7cdau; return 0; }
target=r[1];
r[16]=code_base|0x0c0c7cdeu;
r[4]+=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7cdeu) { target=s->pc; goto dispatch; }
goto P_0c0c7cde;
P_0c0c7cdc: /* original 342c, guest PC 0x0c0c7cdc */
if(!s->budget--) { s->failed_pc=0x0c0c7cdcu; return 0; }
r[4]+=r[2];
goto P_0c0c7cde;
P_0c0c7cde: /* original d336, guest PC 0x0c0c7cde */
if(!s->budget--) { s->failed_pc=0x0c0c7cdeu; return 0; }
r[3]=read(ram,0x0c0c7db8u,4);
goto P_0c0c7ce0;
P_0c0c7ce0: /* original 7f04, guest PC 0x0c0c7ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7ce2;
P_0c0c7ce2: /* original 430b, guest PC 0x0c0c7ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce2u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7ce6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7ce6u) { target=s->pc; goto dispatch; }
goto P_0c0c7ce6;
P_0c0c7ce4: /* original 64d3, guest PC 0x0c0c7ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce4u; return 0; }
r[4]=r[13];
goto P_0c0c7ce6;
P_0c0c7ce6: /* original e024, guest PC 0x0c0c7ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce6u; return 0; }
r[0]=0x00000024u;
goto P_0c0c7ce8;
P_0c0c7ce8: /* original f3c6, guest PC 0x0c0c7ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c7ce8u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7cea;
P_0c0c7cea: /* original e300, guest PC 0x0c0c7cea */
if(!s->budget--) { s->failed_pc=0x0c0c7ceau; return 0; }
r[3]=0x00000000u;
goto P_0c0c7cec;
P_0c0c7cec: /* original 9049, guest PC 0x0c0c7cec */
if(!s->budget--) { s->failed_pc=0x0c0c7cecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d82u,2);
goto P_0c0c7cee;
P_0c0c7cee: /* original fd37, guest PC 0x0c0c7cee */
if(!s->budget--) { s->failed_pc=0x0c0c7ceeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7cf0;
P_0c0c7cf0: /* original e028, guest PC 0x0c0c7cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf0u; return 0; }
r[0]=0x00000028u;
goto P_0c0c7cf2;
P_0c0c7cf2: /* original f3c6, guest PC 0x0c0c7cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf2u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7cf4;
P_0c0c7cf4: /* original 9046, guest PC 0x0c0c7cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d84u,2);
goto P_0c0c7cf6;
P_0c0c7cf6: /* original fd37, guest PC 0x0c0c7cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf6u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7cf8;
P_0c0c7cf8: /* original 9045, guest PC 0x0c0c7cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c7cf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d86u,2);
goto P_0c0c7cfa;
P_0c0c7cfa: /* original 0b36, guest PC 0x0c0c7cfa */
if(!s->budget--) { s->failed_pc=0x0c0c7cfau; return 0; }
write(ram,r[11]+r[0],r[3],4);
goto P_0c0c7cfc;
P_0c0c7cfc: /* original e02c, guest PC 0x0c0c7cfc */
if(!s->budget--) { s->failed_pc=0x0c0c7cfcu; return 0; }
r[0]=0x0000002cu;
goto P_0c0c7cfe;
P_0c0c7cfe: /* original f3c6, guest PC 0x0c0c7cfe */
if(!s->budget--) { s->failed_pc=0x0c0c7cfeu; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7d00;
P_0c0c7d00: /* original 9042, guest PC 0x0c0c7d00 */
if(!s->budget--) { s->failed_pc=0x0c0c7d00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d88u,2);
goto P_0c0c7d02;
P_0c0c7d02: /* original fd37, guest PC 0x0c0c7d02 */
if(!s->budget--) { s->failed_pc=0x0c0c7d02u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7d04;
P_0c0c7d04: /* original e030, guest PC 0x0c0c7d04 */
if(!s->budget--) { s->failed_pc=0x0c0c7d04u; return 0; }
r[0]=0x00000030u;
goto P_0c0c7d06;
P_0c0c7d06: /* original f3c6, guest PC 0x0c0c7d06 */
if(!s->budget--) { s->failed_pc=0x0c0c7d06u; return 0; }
vf3_matrix_load(s,ram,3,r[12]+r[0]);
goto P_0c0c7d08;
P_0c0c7d08: /* original 903f, guest PC 0x0c0c7d08 */
if(!s->budget--) { s->failed_pc=0x0c0c7d08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d8au,2);
goto P_0c0c7d0a;
P_0c0c7d0a: /* original fd37, guest PC 0x0c0c7d0a */
if(!s->budget--) { s->failed_pc=0x0c0c7d0au; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c0c7d0c;
P_0c0c7d0c: /* original d22b, guest PC 0x0c0c7d0c */
if(!s->budget--) { s->failed_pc=0x0c0c7d0cu; return 0; }
r[2]=read(ram,0x0c0c7dbcu,4);
goto P_0c0c7d0e;
P_0c0c7d0e: /* original 6322, guest PC 0x0c0c7d0e */
if(!s->budget--) { s->failed_pc=0x0c0c7d0eu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0c7d10;
P_0c0c7d10: /* original 3a30, guest PC 0x0c0c7d10 */
if(!s->budget--) { s->failed_pc=0x0c0c7d10u; return 0; }
r[17]=(r[17]&~1u)|((r[10]==r[3])!=0);
goto P_0c0c7d12;
P_0c0c7d12: /* original 890d, guest PC 0x0c0c7d12 */
if(!s->budget--) { s->failed_pc=0x0c0c7d12u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7d30; }
goto P_0c0c7d14;
P_0c0c7d14: /* original bc98, guest PC 0x0c0c7d14 */
if(!s->budget--) { s->failed_pc=0x0c0c7d14u; return 0; }
target=code_base|0x0c0c7648u; r[16]=code_base|0x0c0c7d18u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d18u) { target=s->pc; goto dispatch; }
goto P_0c0c7d18;
P_0c0c7d16: /* original 0009, guest PC 0x0c0c7d16 */
if(!s->budget--) { s->failed_pc=0x0c0c7d16u; return 0; }
goto P_0c0c7d18;
P_0c0c7d18: /* original 6192, guest PC 0x0c0c7d18 */
if(!s->budget--) { s->failed_pc=0x0c0c7d18u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c0c7d1a;
P_0c0c7d1a: /* original d324, guest PC 0x0c0c7d1a */
if(!s->budget--) { s->failed_pc=0x0c0c7d1au; return 0; }
r[3]=read(ram,0x0c0c7dacu,4);
goto P_0c0c7d1c;
P_0c0c7d1c: /* original 2138, guest PC 0x0c0c7d1c */
if(!s->budget--) { s->failed_pc=0x0c0c7d1cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0c7d1e;
P_0c0c7d1e: /* original 8b07, guest PC 0x0c0c7d1e */
if(!s->budget--) { s->failed_pc=0x0c0c7d1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7d30; }
goto P_0c0c7d20;
P_0c0c7d20: /* original d227, guest PC 0x0c0c7d20 */
if(!s->budget--) { s->failed_pc=0x0c0c7d20u; return 0; }
r[2]=read(ram,0x0c0c7dc0u,4);
goto P_0c0c7d22;
P_0c0c7d22: /* original 420b, guest PC 0x0c0c7d22 */
if(!s->budget--) { s->failed_pc=0x0c0c7d22u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d26u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d26u) { target=s->pc; goto dispatch; }
goto P_0c0c7d26;
P_0c0c7d24: /* original 0009, guest PC 0x0c0c7d24 */
if(!s->budget--) { s->failed_pc=0x0c0c7d24u; return 0; }
goto P_0c0c7d26;
P_0c0c7d26: /* original bccb, guest PC 0x0c0c7d26 */
if(!s->budget--) { s->failed_pc=0x0c0c7d26u; return 0; }
target=code_base|0x0c0c76c0u; r[16]=code_base|0x0c0c7d2au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d2au) { target=s->pc; goto dispatch; }
goto P_0c0c7d2a;
P_0c0c7d28: /* original 0009, guest PC 0x0c0c7d28 */
if(!s->budget--) { s->failed_pc=0x0c0c7d28u; return 0; }
goto P_0c0c7d2a;
P_0c0c7d2a: /* original d226, guest PC 0x0c0c7d2a */
if(!s->budget--) { s->failed_pc=0x0c0c7d2au; return 0; }
r[2]=read(ram,0x0c0c7dc4u,4);
goto P_0c0c7d2c;
P_0c0c7d2c: /* original 420b, guest PC 0x0c0c7d2c */
if(!s->budget--) { s->failed_pc=0x0c0c7d2cu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d30u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d30u) { target=s->pc; goto dispatch; }
goto P_0c0c7d30;
P_0c0c7d2e: /* original 64a3, guest PC 0x0c0c7d2e */
if(!s->budget--) { s->failed_pc=0x0c0c7d2eu; return 0; }
r[4]=r[10];
goto P_0c0c7d30;
P_0c0c7d30: /* original 902c, guest PC 0x0c0c7d30 */
if(!s->budget--) { s->failed_pc=0x0c0c7d30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c7d8cu,2);
goto P_0c0c7d32;
P_0c0c7d32: /* original 0da4, guest PC 0x0c0c7d32 */
if(!s->budget--) { s->failed_pc=0x0c0c7d32u; return 0; }
write(ram,r[13]+r[0],r[10],1);
goto P_0c0c7d34;
P_0c0c7d34: /* original e031, guest PC 0x0c0c7d34 */
if(!s->budget--) { s->failed_pc=0x0c0c7d34u; return 0; }
r[0]=0x00000031u;
goto P_0c0c7d36;
P_0c0c7d36: /* original 03ec, guest PC 0x0c0c7d36 */
if(!s->budget--) { s->failed_pc=0x0c0c7d36u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c7d38;
P_0c0c7d38: /* original 2338, guest PC 0x0c0c7d38 */
if(!s->budget--) { s->failed_pc=0x0c0c7d38u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c7d3a;
P_0c0c7d3a: /* original 8904, guest PC 0x0c0c7d3a */
if(!s->budget--) { s->failed_pc=0x0c0c7d3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7d46; }
goto P_0c0c7d3c;
P_0c0c7d3c: /* original d322, guest PC 0x0c0c7d3c */
if(!s->budget--) { s->failed_pc=0x0c0c7d3cu; return 0; }
r[3]=read(ram,0x0c0c7dc8u,4);
goto P_0c0c7d3e;
P_0c0c7d3e: /* original 65a3, guest PC 0x0c0c7d3e */
if(!s->budget--) { s->failed_pc=0x0c0c7d3eu; return 0; }
r[5]=r[10];
goto P_0c0c7d40;
P_0c0c7d40: /* original 84e4, guest PC 0x0c0c7d40 */
if(!s->budget--) { s->failed_pc=0x0c0c7d40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c0c7d42;
P_0c0c7d42: /* original 430b, guest PC 0x0c0c7d42 */
if(!s->budget--) { s->failed_pc=0x0c0c7d42u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d46u;
r[4]=r[0]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d46u) { target=s->pc; goto dispatch; }
goto P_0c0c7d46;
P_0c0c7d44: /* original 640c, guest PC 0x0c0c7d44 */
if(!s->budget--) { s->failed_pc=0x0c0c7d44u; return 0; }
r[4]=r[0]&255u;
goto P_0c0c7d46;
P_0c0c7d46: /* original d321, guest PC 0x0c0c7d46 */
if(!s->budget--) { s->failed_pc=0x0c0c7d46u; return 0; }
r[3]=read(ram,0x0c0c7dccu,4);
goto P_0c0c7d48;
P_0c0c7d48: /* original 430b, guest PC 0x0c0c7d48 */
if(!s->budget--) { s->failed_pc=0x0c0c7d48u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d4cu) { target=s->pc; goto dispatch; }
goto P_0c0c7d4c;
P_0c0c7d4a: /* original 0009, guest PC 0x0c0c7d4a */
if(!s->budget--) { s->failed_pc=0x0c0c7d4au; return 0; }
goto P_0c0c7d4c;
P_0c0c7d4c: /* original d220, guest PC 0x0c0c7d4c */
if(!s->budget--) { s->failed_pc=0x0c0c7d4cu; return 0; }
r[2]=read(ram,0x0c0c7dd0u,4);
goto P_0c0c7d4e;
P_0c0c7d4e: /* original 420b, guest PC 0x0c0c7d4e */
if(!s->budget--) { s->failed_pc=0x0c0c7d4eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d52u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d52u) { target=s->pc; goto dispatch; }
goto P_0c0c7d52;
P_0c0c7d50: /* original 0009, guest PC 0x0c0c7d50 */
if(!s->budget--) { s->failed_pc=0x0c0c7d50u; return 0; }
goto P_0c0c7d52;
P_0c0c7d52: /* original 60d2, guest PC 0x0c0c7d52 */
if(!s->budget--) { s->failed_pc=0x0c0c7d52u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c0c7d54;
P_0c0c7d54: /* original c810, guest PC 0x0c0c7d54 */
if(!s->budget--) { s->failed_pc=0x0c0c7d54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c0c7d56;
P_0c0c7d56: /* original 8b02, guest PC 0x0c0c7d56 */
if(!s->budget--) { s->failed_pc=0x0c0c7d56u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7d5e; }
goto P_0c0c7d58;
P_0c0c7d58: /* original d21e, guest PC 0x0c0c7d58 */
if(!s->budget--) { s->failed_pc=0x0c0c7d58u; return 0; }
r[2]=read(ram,0x0c0c7dd4u,4);
goto P_0c0c7d5a;
P_0c0c7d5a: /* original 420b, guest PC 0x0c0c7d5a */
if(!s->budget--) { s->failed_pc=0x0c0c7d5au; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d5eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d5eu) { target=s->pc; goto dispatch; }
goto P_0c0c7d5e;
P_0c0c7d5c: /* original 0009, guest PC 0x0c0c7d5c */
if(!s->budget--) { s->failed_pc=0x0c0c7d5cu; return 0; }
goto P_0c0c7d5e;
P_0c0c7d5e: /* original d31e, guest PC 0x0c0c7d5e */
if(!s->budget--) { s->failed_pc=0x0c0c7d5eu; return 0; }
r[3]=read(ram,0x0c0c7dd8u,4);
goto P_0c0c7d60;
P_0c0c7d60: /* original 430b, guest PC 0x0c0c7d60 */
if(!s->budget--) { s->failed_pc=0x0c0c7d60u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c7d64u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d64u) { target=s->pc; goto dispatch; }
goto P_0c0c7d64;
P_0c0c7d62: /* original 0009, guest PC 0x0c0c7d62 */
if(!s->budget--) { s->failed_pc=0x0c0c7d62u; return 0; }
goto P_0c0c7d64;
P_0c0c7d64: /* original d21d, guest PC 0x0c0c7d64 */
if(!s->budget--) { s->failed_pc=0x0c0c7d64u; return 0; }
r[2]=read(ram,0x0c0c7ddcu,4);
goto P_0c0c7d66;
P_0c0c7d66: /* original 420b, guest PC 0x0c0c7d66 */
if(!s->budget--) { s->failed_pc=0x0c0c7d66u; return 0; }
target=r[2];
r[16]=code_base|0x0c0c7d6au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0c7d6au) { target=s->pc; goto dispatch; }
goto P_0c0c7d6a;
P_0c0c7d68: /* original 0009, guest PC 0x0c0c7d68 */
if(!s->budget--) { s->failed_pc=0x0c0c7d68u; return 0; }
goto P_0c0c7d6a;
P_0c0c7d6a: /* original 7f04, guest PC 0x0c0c7d6a */
if(!s->budget--) { s->failed_pc=0x0c0c7d6au; return 0; }
r[15]+=0x00000004u;
goto P_0c0c7d6c;
P_0c0c7d6c: /* original 4f16, guest PC 0x0c0c7d6c */
if(!s->budget--) { s->failed_pc=0x0c0c7d6cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7d6e;
P_0c0c7d6e: /* original 4f26, guest PC 0x0c0c7d6e */
if(!s->budget--) { s->failed_pc=0x0c0c7d6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c7d70;
P_0c0c7d70: /* original 69f6, guest PC 0x0c0c7d70 */
if(!s->budget--) { s->failed_pc=0x0c0c7d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7d72;
P_0c0c7d72: /* original 6af6, guest PC 0x0c0c7d72 */
if(!s->budget--) { s->failed_pc=0x0c0c7d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7d74;
P_0c0c7d74: /* original 6bf6, guest PC 0x0c0c7d74 */
if(!s->budget--) { s->failed_pc=0x0c0c7d74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7d76;
P_0c0c7d76: /* original a033, guest PC 0x0c0c7d76 */
if(!s->budget--) { s->failed_pc=0x0c0c7d76u; return 0; }
goto P_0c0c7de0;
P_0c0c7d78: /* original 0009, guest PC 0x0c0c7d78 */
if(!s->budget--) { s->failed_pc=0x0c0c7d78u; return 0; }
if(!vf3_matrix_family(0x0c0c7d7au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7d7au; return 0; } return 1;
P_0c0c7de0: /* original 6cf6, guest PC 0x0c0c7de0 */
if(!s->budget--) { s->failed_pc=0x0c0c7de0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7de2;
P_0c0c7de2: /* original 6df6, guest PC 0x0c0c7de2 */
if(!s->budget--) { s->failed_pc=0x0c0c7de2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7de4;
P_0c0c7de4: /* original a95e, guest PC 0x0c0c7de4 */
if(!s->budget--) { s->failed_pc=0x0c0c7de4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c70a4u,s,ram);
P_0c0c7de6: /* original 6ef6, guest PC 0x0c0c7de6 */
if(!s->budget--) { s->failed_pc=0x0c0c7de6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0c7de8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c7de8u; return 0; } return 1;
P_0c0ca234: /* original d52a, guest PC 0x0c0ca234 */
if(!s->budget--) { s->failed_pc=0x0c0ca234u; return 0; }
r[5]=read(ram,0x0c0ca2e0u,4);
goto P_0c0ca236;
P_0c0ca236: /* original e01c, guest PC 0x0c0ca236 */
if(!s->budget--) { s->failed_pc=0x0c0ca236u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ca238;
P_0c0ca238: /* original d42a, guest PC 0x0c0ca238 */
if(!s->budget--) { s->failed_pc=0x0c0ca238u; return 0; }
r[4]=read(ram,0x0c0ca2e4u,4);
goto P_0c0ca23a;
P_0c0ca23a: /* original e3fe, guest PC 0x0c0ca23a */
if(!s->budget--) { s->failed_pc=0x0c0ca23au; return 0; }
r[3]=0xfffffffeu;
goto P_0c0ca23c;
P_0c0ca23c: /* original 5251, guest PC 0x0c0ca23c */
if(!s->budget--) { s->failed_pc=0x0c0ca23cu; return 0; }
r[2]=read(ram,r[5]+4,4);
goto P_0c0ca23e;
P_0c0ca23e: /* original e70f, guest PC 0x0c0ca23e */
if(!s->budget--) { s->failed_pc=0x0c0ca23eu; return 0; }
r[7]=0x0000000fu;
goto P_0c0ca240;
P_0c0ca240: /* original 4f22, guest PC 0x0c0ca240 */
if(!s->budget--) { s->failed_pc=0x0c0ca240u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ca242;
P_0c0ca242: /* original 2239, guest PC 0x0c0ca242 */
if(!s->budget--) { s->failed_pc=0x0c0ca242u; return 0; }
r[2]&=r[3];
goto P_0c0ca244;
P_0c0ca244: /* original 1521, guest PC 0x0c0ca244 */
if(!s->budget--) { s->failed_pc=0x0c0ca244u; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c0ca246;
P_0c0ca246: /* original 004c, guest PC 0x0c0ca246 */
if(!s->budget--) { s->failed_pc=0x0c0ca246u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ca248;
P_0c0ca248: /* original 7ffc, guest PC 0x0c0ca248 */
if(!s->budget--) { s->failed_pc=0x0c0ca248u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ca24a;
P_0c0ca24a: /* original d427, guest PC 0x0c0ca24a */
if(!s->budget--) { s->failed_pc=0x0c0ca24au; return 0; }
r[4]=read(ram,0x0c0ca2e8u,4);
goto P_0c0ca24c;
P_0c0ca24c: /* original 600c, guest PC 0x0c0ca24c */
if(!s->budget--) { s->failed_pc=0x0c0ca24cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ca24e;
P_0c0ca24e: /* original 2709, guest PC 0x0c0ca24e */
if(!s->budget--) { s->failed_pc=0x0c0ca24eu; return 0; }
r[7]&=r[0];
goto P_0c0ca250;
P_0c0ca250: /* original 5341, guest PC 0x0c0ca250 */
if(!s->budget--) { s->failed_pc=0x0c0ca250u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c0ca252;
P_0c0ca252: /* original 6642, guest PC 0x0c0ca252 */
if(!s->budget--) { s->failed_pc=0x0c0ca252u; return 0; }
tmp=read(ram,r[4],4);
r[6]=tmp;
goto P_0c0ca254;
P_0c0ca254: /* original 2f32, guest PC 0x0c0ca254 */
if(!s->budget--) { s->failed_pc=0x0c0ca254u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ca256;
P_0c0ca256: /* original 3760, guest PC 0x0c0ca256 */
if(!s->budget--) { s->failed_pc=0x0c0ca256u; return 0; }
r[17]=(r[17]&~1u)|((r[7]==r[6])!=0);
goto P_0c0ca258;
P_0c0ca258: /* original 8d0c, guest PC 0x0c0ca258 */
if(!s->budget--) { s->failed_pc=0x0c0ca258u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000008u;
if(cond) { goto P_0c0ca274; }
goto P_0c0ca25c;
P_0c0ca25a: /* original 7408, guest PC 0x0c0ca25a */
if(!s->budget--) { s->failed_pc=0x0c0ca25au; return 0; }
r[4]+=0x00000008u;
goto P_0c0ca25c;
P_0c0ca25c: /* original 6063, guest PC 0x0c0ca25c */
if(!s->budget--) { s->failed_pc=0x0c0ca25cu; return 0; }
r[0]=r[6];
goto P_0c0ca25e;
P_0c0ca25e: /* original 88ff, guest PC 0x0c0ca25e */
if(!s->budget--) { s->failed_pc=0x0c0ca25eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0ca260;
P_0c0ca260: /* original 8bf6, guest PC 0x0c0ca260 */
if(!s->budget--) { s->failed_pc=0x0c0ca260u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ca250; }
goto P_0c0ca262;
P_0c0ca262: /* original e000, guest PC 0x0c0ca262 */
if(!s->budget--) { s->failed_pc=0x0c0ca262u; return 0; }
r[0]=0x00000000u;
goto P_0c0ca264;
P_0c0ca264: /* original 8051, guest PC 0x0c0ca264 */
if(!s->budget--) { s->failed_pc=0x0c0ca264u; return 0; }
write(ram,r[5]+1,r[0],1);
goto P_0c0ca266;
P_0c0ca266: /* original d421, guest PC 0x0c0ca266 */
if(!s->budget--) { s->failed_pc=0x0c0ca266u; return 0; }
r[4]=read(ram,0x0c0ca2ecu,4);
goto P_0c0ca268;
P_0c0ca268: /* original b05b, guest PC 0x0c0ca268 */
if(!s->budget--) { s->failed_pc=0x0c0ca268u; return 0; }
target=code_base|0x0c0ca322u; r[16]=code_base|0x0c0ca26cu;
r[5]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca26cu) { target=s->pc; goto dispatch; }
goto P_0c0ca26c;
P_0c0ca26a: /* original e501, guest PC 0x0c0ca26a */
if(!s->budget--) { s->failed_pc=0x0c0ca26au; return 0; }
r[5]=0x00000001u;
goto P_0c0ca26c;
P_0c0ca26c: /* original 7f04, guest PC 0x0c0ca26c */
if(!s->budget--) { s->failed_pc=0x0c0ca26cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ca26e;
P_0c0ca26e: /* original 4f26, guest PC 0x0c0ca26e */
if(!s->budget--) { s->failed_pc=0x0c0ca26eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca270;
P_0c0ca270: /* original 000b, guest PC 0x0c0ca270 */
if(!s->budget--) { s->failed_pc=0x0c0ca270u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca272: /* original 0009, guest PC 0x0c0ca272 */
if(!s->budget--) { s->failed_pc=0x0c0ca272u; return 0; }
goto P_0c0ca274;
P_0c0ca274: /* original 63f2, guest PC 0x0c0ca274 */
if(!s->budget--) { s->failed_pc=0x0c0ca274u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0ca276;
P_0c0ca276: /* original 430b, guest PC 0x0c0ca276 */
if(!s->budget--) { s->failed_pc=0x0c0ca276u; return 0; }
target=r[3];
r[16]=code_base|0x0c0ca27au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ca27au) { target=s->pc; goto dispatch; }
goto P_0c0ca27a;
P_0c0ca278: /* original 0009, guest PC 0x0c0ca278 */
if(!s->budget--) { s->failed_pc=0x0c0ca278u; return 0; }
goto P_0c0ca27a;
P_0c0ca27a: /* original 7f04, guest PC 0x0c0ca27a */
if(!s->budget--) { s->failed_pc=0x0c0ca27au; return 0; }
r[15]+=0x00000004u;
goto P_0c0ca27c;
P_0c0ca27c: /* original 4f26, guest PC 0x0c0ca27c */
if(!s->budget--) { s->failed_pc=0x0c0ca27cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ca27e;
P_0c0ca27e: /* original 000b, guest PC 0x0c0ca27e */
if(!s->budget--) { s->failed_pc=0x0c0ca27eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca280: /* original 0009, guest PC 0x0c0ca280 */
if(!s->budget--) { s->failed_pc=0x0c0ca280u; return 0; }
if(!vf3_matrix_family(0x0c0ca282u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca282u; return 0; } return 1;
P_0c0ca322: /* original 000b, guest PC 0x0c0ca322 */
if(!s->budget--) { s->failed_pc=0x0c0ca322u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca324: /* original 0009, guest PC 0x0c0ca324 */
if(!s->budget--) { s->failed_pc=0x0c0ca324u; return 0; }
if(!vf3_matrix_family(0x0c0ca326u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca326u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
