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
int vf3_away_batch31_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c064c1cu: goto P_0c064c1c;
case 0x0c064c1eu: goto P_0c064c1e;
case 0x0c064c20u: goto P_0c064c20;
case 0x0c064c22u: goto P_0c064c22;
case 0x0c064c24u: goto P_0c064c24;
case 0x0c064c26u: goto P_0c064c26;
case 0x0c064c28u: goto P_0c064c28;
case 0x0c064c2au: goto P_0c064c2a;
case 0x0c064c2cu: goto P_0c064c2c;
case 0x0c064c2eu: goto P_0c064c2e;
case 0x0c064c30u: goto P_0c064c30;
case 0x0c064c32u: goto P_0c064c32;
case 0x0c064c34u: goto P_0c064c34;
case 0x0c064c36u: goto P_0c064c36;
case 0x0c064c38u: goto P_0c064c38;
case 0x0c064c3au: goto P_0c064c3a;
case 0x0c064c3cu: goto P_0c064c3c;
case 0x0c064c3eu: goto P_0c064c3e;
case 0x0c064c40u: goto P_0c064c40;
case 0x0c064c42u: goto P_0c064c42;
case 0x0c064c44u: goto P_0c064c44;
case 0x0c064c46u: goto P_0c064c46;
case 0x0c064c48u: goto P_0c064c48;
case 0x0c064c4au: goto P_0c064c4a;
case 0x0c064c4cu: goto P_0c064c4c;
case 0x0c064c4eu: goto P_0c064c4e;
case 0x0c064c50u: goto P_0c064c50;
case 0x0c064c52u: goto P_0c064c52;
case 0x0c064c54u: goto P_0c064c54;
case 0x0c064c56u: goto P_0c064c56;
case 0x0c064c58u: goto P_0c064c58;
case 0x0c064c5au: goto P_0c064c5a;
case 0x0c064c5cu: goto P_0c064c5c;
case 0x0c064c5eu: goto P_0c064c5e;
case 0x0c064c60u: goto P_0c064c60;
case 0x0c064c62u: goto P_0c064c62;
case 0x0c064c64u: goto P_0c064c64;
case 0x0c064c66u: goto P_0c064c66;
case 0x0c064c68u: goto P_0c064c68;
case 0x0c064c6au: goto P_0c064c6a;
case 0x0c064c6cu: goto P_0c064c6c;
case 0x0c064c6eu: goto P_0c064c6e;
case 0x0c064c70u: goto P_0c064c70;
case 0x0c064c72u: goto P_0c064c72;
case 0x0c064c74u: goto P_0c064c74;
case 0x0c064c76u: goto P_0c064c76;
case 0x0c064c78u: goto P_0c064c78;
case 0x0c064c7au: goto P_0c064c7a;
case 0x0c064c7cu: goto P_0c064c7c;
case 0x0c064c7eu: goto P_0c064c7e;
case 0x0c064c80u: goto P_0c064c80;
case 0x0c064c82u: goto P_0c064c82;
case 0x0c064c84u: goto P_0c064c84;
case 0x0c064c86u: goto P_0c064c86;
case 0x0c064c88u: goto P_0c064c88;
case 0x0c064c8au: goto P_0c064c8a;
case 0x0c064c8cu: goto P_0c064c8c;
case 0x0c064c8eu: goto P_0c064c8e;
case 0x0c064c90u: goto P_0c064c90;
case 0x0c064c92u: goto P_0c064c92;
case 0x0c064c94u: goto P_0c064c94;
case 0x0c064c96u: goto P_0c064c96;
case 0x0c064c98u: goto P_0c064c98;
case 0x0c064c9au: goto P_0c064c9a;
case 0x0c064c9cu: goto P_0c064c9c;
case 0x0c064c9eu: goto P_0c064c9e;
case 0x0c064ca0u: goto P_0c064ca0;
case 0x0c064ca2u: goto P_0c064ca2;
case 0x0c064ca4u: goto P_0c064ca4;
case 0x0c064ca6u: goto P_0c064ca6;
case 0x0c064ca8u: goto P_0c064ca8;
case 0x0c064caau: goto P_0c064caa;
case 0x0c064cacu: goto P_0c064cac;
case 0x0c064caeu: goto P_0c064cae;
case 0x0c064cb0u: goto P_0c064cb0;
case 0x0c064cb2u: goto P_0c064cb2;
case 0x0c064cb4u: goto P_0c064cb4;
case 0x0c064cb6u: goto P_0c064cb6;
case 0x0c064cb8u: goto P_0c064cb8;
case 0x0c064cbau: goto P_0c064cba;
case 0x0c064cbcu: goto P_0c064cbc;
case 0x0c064cbeu: goto P_0c064cbe;
case 0x0c064cc0u: goto P_0c064cc0;
case 0x0c064cc2u: goto P_0c064cc2;
case 0x0c064cc4u: goto P_0c064cc4;
case 0x0c064cc6u: goto P_0c064cc6;
case 0x0c064cc8u: goto P_0c064cc8;
case 0x0c064ccau: goto P_0c064cca;
case 0x0c064cccu: goto P_0c064ccc;
case 0x0c064cceu: goto P_0c064cce;
case 0x0c064cd0u: goto P_0c064cd0;
case 0x0c064cd2u: goto P_0c064cd2;
case 0x0c064cd4u: goto P_0c064cd4;
case 0x0c064cd6u: goto P_0c064cd6;
case 0x0c064cd8u: goto P_0c064cd8;
case 0x0c064cdau: goto P_0c064cda;
case 0x0c064cdcu: goto P_0c064cdc;
case 0x0c064cdeu: goto P_0c064cde;
case 0x0c064ce0u: goto P_0c064ce0;
case 0x0c064ce2u: goto P_0c064ce2;
case 0x0c064ce4u: goto P_0c064ce4;
case 0x0c064ce6u: goto P_0c064ce6;
case 0x0c064ce8u: goto P_0c064ce8;
case 0x0c064ceau: goto P_0c064cea;
case 0x0c064cecu: goto P_0c064cec;
case 0x0c064ceeu: goto P_0c064cee;
case 0x0c064cf0u: goto P_0c064cf0;
case 0x0c064cf2u: goto P_0c064cf2;
case 0x0c064cf4u: goto P_0c064cf4;
case 0x0c064cf6u: goto P_0c064cf6;
case 0x0c064cf8u: goto P_0c064cf8;
case 0x0c064cfau: goto P_0c064cfa;
case 0x0c064cfcu: goto P_0c064cfc;
case 0x0c064cfeu: goto P_0c064cfe;
case 0x0c064d00u: goto P_0c064d00;
case 0x0c064d02u: goto P_0c064d02;
case 0x0c064d04u: goto P_0c064d04;
case 0x0c064d06u: goto P_0c064d06;
case 0x0c064d08u: goto P_0c064d08;
case 0x0c064d0au: goto P_0c064d0a;
case 0x0c064d0cu: goto P_0c064d0c;
case 0x0c064d0eu: goto P_0c064d0e;
case 0x0c064d10u: goto P_0c064d10;
case 0x0c064d12u: goto P_0c064d12;
case 0x0c064d14u: goto P_0c064d14;
case 0x0c064d16u: goto P_0c064d16;
case 0x0c064d18u: goto P_0c064d18;
case 0x0c064d1au: goto P_0c064d1a;
case 0x0c064d1cu: goto P_0c064d1c;
case 0x0c064d1eu: goto P_0c064d1e;
case 0x0c064d20u: goto P_0c064d20;
case 0x0c064d22u: goto P_0c064d22;
case 0x0c064d24u: goto P_0c064d24;
case 0x0c064d26u: goto P_0c064d26;
case 0x0c064d28u: goto P_0c064d28;
case 0x0c064d2au: goto P_0c064d2a;
case 0x0c064d2cu: goto P_0c064d2c;
case 0x0c064d2eu: goto P_0c064d2e;
case 0x0c064d30u: goto P_0c064d30;
case 0x0c064d32u: goto P_0c064d32;
case 0x0c064d34u: goto P_0c064d34;
case 0x0c064d36u: goto P_0c064d36;
case 0x0c064d38u: goto P_0c064d38;
case 0x0c064d3au: goto P_0c064d3a;
case 0x0c064d3cu: goto P_0c064d3c;
case 0x0c064d3eu: goto P_0c064d3e;
case 0x0c064d40u: goto P_0c064d40;
case 0x0c064d42u: goto P_0c064d42;
case 0x0c064d44u: goto P_0c064d44;
case 0x0c064d46u: goto P_0c064d46;
case 0x0c064d48u: goto P_0c064d48;
case 0x0c064d4au: goto P_0c064d4a;
case 0x0c064d4cu: goto P_0c064d4c;
case 0x0c064d4eu: goto P_0c064d4e;
case 0x0c064d50u: goto P_0c064d50;
case 0x0c064d52u: goto P_0c064d52;
case 0x0c064d54u: goto P_0c064d54;
case 0x0c064d56u: goto P_0c064d56;
case 0x0c064d58u: goto P_0c064d58;
case 0x0c064d5au: goto P_0c064d5a;
case 0x0c064d5cu: goto P_0c064d5c;
case 0x0c064d5eu: goto P_0c064d5e;
case 0x0c064d60u: goto P_0c064d60;
case 0x0c064d62u: goto P_0c064d62;
case 0x0c064d64u: goto P_0c064d64;
case 0x0c064d66u: goto P_0c064d66;
case 0x0c064d68u: goto P_0c064d68;
case 0x0c064d6au: goto P_0c064d6a;
case 0x0c064d6cu: goto P_0c064d6c;
case 0x0c064d6eu: goto P_0c064d6e;
case 0x0c064d70u: goto P_0c064d70;
case 0x0c064d72u: goto P_0c064d72;
case 0x0c064d74u: goto P_0c064d74;
case 0x0c064d76u: goto P_0c064d76;
case 0x0c0662d8u: goto P_0c0662d8;
case 0x0c0662dau: goto P_0c0662da;
case 0x0c0662dcu: goto P_0c0662dc;
case 0x0c0662deu: goto P_0c0662de;
case 0x0c0662e0u: goto P_0c0662e0;
case 0x0c0662e2u: goto P_0c0662e2;
case 0x0c0662e4u: goto P_0c0662e4;
case 0x0c0662e6u: goto P_0c0662e6;
case 0x0c0662e8u: goto P_0c0662e8;
case 0x0c0662eau: goto P_0c0662ea;
case 0x0c0662ecu: goto P_0c0662ec;
case 0x0c0662eeu: goto P_0c0662ee;
case 0x0c0662f0u: goto P_0c0662f0;
case 0x0c0662f2u: goto P_0c0662f2;
case 0x0c0662f4u: goto P_0c0662f4;
case 0x0c0662f6u: goto P_0c0662f6;
case 0x0c0662f8u: goto P_0c0662f8;
case 0x0c0662fau: goto P_0c0662fa;
case 0x0c0662fcu: goto P_0c0662fc;
case 0x0c0662feu: goto P_0c0662fe;
case 0x0c066300u: goto P_0c066300;
case 0x0c066302u: goto P_0c066302;
case 0x0c066304u: goto P_0c066304;
case 0x0c066306u: goto P_0c066306;
case 0x0c066308u: goto P_0c066308;
case 0x0c06630au: goto P_0c06630a;
case 0x0c06630cu: goto P_0c06630c;
case 0x0c06630eu: goto P_0c06630e;
case 0x0c066310u: goto P_0c066310;
case 0x0c066312u: goto P_0c066312;
case 0x0c066314u: goto P_0c066314;
case 0x0c066316u: goto P_0c066316;
case 0x0c066318u: goto P_0c066318;
case 0x0c06631au: goto P_0c06631a;
case 0x0c06631cu: goto P_0c06631c;
case 0x0c06631eu: goto P_0c06631e;
case 0x0c066320u: goto P_0c066320;
case 0x0c066322u: goto P_0c066322;
case 0x0c066324u: goto P_0c066324;
case 0x0c066326u: goto P_0c066326;
case 0x0c066328u: goto P_0c066328;
case 0x0c06632au: goto P_0c06632a;
case 0x0c06632cu: goto P_0c06632c;
case 0x0c06632eu: goto P_0c06632e;
case 0x0c066330u: goto P_0c066330;
case 0x0c066332u: goto P_0c066332;
case 0x0c066334u: goto P_0c066334;
case 0x0c066336u: goto P_0c066336;
case 0x0c066338u: goto P_0c066338;
case 0x0c06633au: goto P_0c06633a;
case 0x0c06633cu: goto P_0c06633c;
case 0x0c06633eu: goto P_0c06633e;
case 0x0c066340u: goto P_0c066340;
case 0x0c066342u: goto P_0c066342;
case 0x0c066344u: goto P_0c066344;
case 0x0c066346u: goto P_0c066346;
case 0x0c066348u: goto P_0c066348;
case 0x0c06634au: goto P_0c06634a;
case 0x0c06634cu: goto P_0c06634c;
case 0x0c06634eu: goto P_0c06634e;
case 0x0c066350u: goto P_0c066350;
case 0x0c066352u: goto P_0c066352;
case 0x0c066354u: goto P_0c066354;
case 0x0c066356u: goto P_0c066356;
case 0x0c066358u: goto P_0c066358;
case 0x0c06635au: goto P_0c06635a;
case 0x0c06635cu: goto P_0c06635c;
case 0x0c06635eu: goto P_0c06635e;
case 0x0c066360u: goto P_0c066360;
case 0x0c066362u: goto P_0c066362;
case 0x0c066364u: goto P_0c066364;
case 0x0c066366u: goto P_0c066366;
case 0x0c066368u: goto P_0c066368;
case 0x0c06636au: goto P_0c06636a;
case 0x0c06636cu: goto P_0c06636c;
case 0x0c06636eu: goto P_0c06636e;
case 0x0c066370u: goto P_0c066370;
case 0x0c066372u: goto P_0c066372;
case 0x0c066374u: goto P_0c066374;
case 0x0c066376u: goto P_0c066376;
case 0x0c066378u: goto P_0c066378;
case 0x0c06637au: goto P_0c06637a;
case 0x0c06637cu: goto P_0c06637c;
case 0x0c06637eu: goto P_0c06637e;
case 0x0c066380u: goto P_0c066380;
case 0x0c066382u: goto P_0c066382;
case 0x0c066384u: goto P_0c066384;
case 0x0c066386u: goto P_0c066386;
case 0x0c066388u: goto P_0c066388;
case 0x0c06638au: goto P_0c06638a;
case 0x0c06638cu: goto P_0c06638c;
case 0x0c06638eu: goto P_0c06638e;
case 0x0c066390u: goto P_0c066390;
default: return vf3_matrix_family(target,s,ram);
}
P_0c064c1c: /* original 2fe6, guest PC 0x0c064c1c */
if(!s->budget--) { s->failed_pc=0x0c064c1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064c1e;
P_0c064c1e: /* original 2fd6, guest PC 0x0c064c1e */
if(!s->budget--) { s->failed_pc=0x0c064c1eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064c20;
P_0c064c20: /* original 2fc6, guest PC 0x0c064c20 */
if(!s->budget--) { s->failed_pc=0x0c064c20u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064c22;
P_0c064c22: /* original ec00, guest PC 0x0c064c22 */
if(!s->budget--) { s->failed_pc=0x0c064c22u; return 0; }
r[12]=0x00000000u;
goto P_0c064c24;
P_0c064c24: /* original 2fb6, guest PC 0x0c064c24 */
if(!s->budget--) { s->failed_pc=0x0c064c24u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064c26;
P_0c064c26: /* original 2fa6, guest PC 0x0c064c26 */
if(!s->budget--) { s->failed_pc=0x0c064c26u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c064c28;
P_0c064c28: /* original 4f22, guest PC 0x0c064c28 */
if(!s->budget--) { s->failed_pc=0x0c064c28u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c064c2a;
P_0c064c2a: /* original 7ff4, guest PC 0x0c064c2a */
if(!s->budget--) { s->failed_pc=0x0c064c2au; return 0; }
r[15]+=0xfffffff4u;
goto P_0c064c2c;
P_0c064c2c: /* original 6342, guest PC 0x0c064c2c */
if(!s->budget--) { s->failed_pc=0x0c064c2cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c064c2e;
P_0c064c2e: /* original 65f3, guest PC 0x0c064c2e */
if(!s->budget--) { s->failed_pc=0x0c064c2eu; return 0; }
r[5]=r[15];
goto P_0c064c30;
P_0c064c30: /* original 6e53, guest PC 0x0c064c30 */
if(!s->budget--) { s->failed_pc=0x0c064c30u; return 0; }
r[14]=r[5];
goto P_0c064c32;
P_0c064c32: /* original 6ae3, guest PC 0x0c064c32 */
if(!s->budget--) { s->failed_pc=0x0c064c32u; return 0; }
r[10]=r[14];
goto P_0c064c34;
P_0c064c34: /* original 2e32, guest PC 0x0c064c34 */
if(!s->budget--) { s->failed_pc=0x0c064c34u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c064c36;
P_0c064c36: /* original 6be3, guest PC 0x0c064c36 */
if(!s->budget--) { s->failed_pc=0x0c064c36u; return 0; }
r[11]=r[14];
goto P_0c064c38;
P_0c064c38: /* original 5241, guest PC 0x0c064c38 */
if(!s->budget--) { s->failed_pc=0x0c064c38u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c064c3a;
P_0c064c3a: /* original 7a04, guest PC 0x0c064c3a */
if(!s->budget--) { s->failed_pc=0x0c064c3au; return 0; }
r[10]+=0x00000004u;
goto P_0c064c3c;
P_0c064c3c: /* original 2a22, guest PC 0x0c064c3c */
if(!s->budget--) { s->failed_pc=0x0c064c3cu; return 0; }
write(ram,r[10],r[2],4);
goto P_0c064c3e;
P_0c064c3e: /* original 7b08, guest PC 0x0c064c3e */
if(!s->budget--) { s->failed_pc=0x0c064c3eu; return 0; }
r[11]+=0x00000008u;
goto P_0c064c40;
P_0c064c40: /* original 5342, guest PC 0x0c064c40 */
if(!s->budget--) { s->failed_pc=0x0c064c40u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c064c42;
P_0c064c42: /* original 2b32, guest PC 0x0c064c42 */
if(!s->budget--) { s->failed_pc=0x0c064c42u; return 0; }
write(ram,r[11],r[3],4);
goto P_0c064c44;
P_0c064c44: /* original d24c, guest PC 0x0c064c44 */
if(!s->budget--) { s->failed_pc=0x0c064c44u; return 0; }
r[2]=read(ram,0x0c064d78u,4);
goto P_0c064c46;
P_0c064c46: /* original 6d22, guest PC 0x0c064c46 */
if(!s->budget--) { s->failed_pc=0x0c064c46u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c064c48;
P_0c064c48: /* original d34c, guest PC 0x0c064c48 */
if(!s->budget--) { s->failed_pc=0x0c064c48u; return 0; }
r[3]=read(ram,0x0c064d7cu,4);
goto P_0c064c4a;
P_0c064c4a: /* original 6432, guest PC 0x0c064c4a */
if(!s->budget--) { s->failed_pc=0x0c064c4au; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c064c4c;
P_0c064c4c: /* original d14c, guest PC 0x0c064c4c */
if(!s->budget--) { s->failed_pc=0x0c064c4cu; return 0; }
r[1]=read(ram,0x0c064d80u,4);
goto P_0c064c4e;
P_0c064c4e: /* original 6512, guest PC 0x0c064c4e */
if(!s->budget--) { s->failed_pc=0x0c064c4eu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c064c50;
P_0c064c50: /* original d04c, guest PC 0x0c064c50 */
if(!s->budget--) { s->failed_pc=0x0c064c50u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064c52;
P_0c064c52: /* original 62c3, guest PC 0x0c064c52 */
if(!s->budget--) { s->failed_pc=0x0c064c52u; return 0; }
r[2]=r[12];
goto P_0c064c54;
P_0c064c54: /* original 7c01, guest PC 0x0c064c54 */
if(!s->budget--) { s->failed_pc=0x0c064c54u; return 0; }
r[12]+=0x00000001u;
goto P_0c064c56;
P_0c064c56: /* original 4208, guest PC 0x0c064c56 */
if(!s->budget--) { s->failed_pc=0x0c064c56u; return 0; }
r[2]<<=2;
goto P_0c064c58;
P_0c064c58: /* original 02d6, guest PC 0x0c064c58 */
if(!s->budget--) { s->failed_pc=0x0c064c58u; return 0; }
write(ram,r[2]+r[0],r[13],4);
goto P_0c064c5a;
P_0c064c5a: /* original 63c3, guest PC 0x0c064c5a */
if(!s->budget--) { s->failed_pc=0x0c064c5au; return 0; }
r[3]=r[12];
goto P_0c064c5c;
P_0c064c5c: /* original 7c01, guest PC 0x0c064c5c */
if(!s->budget--) { s->failed_pc=0x0c064c5cu; return 0; }
r[12]+=0x00000001u;
goto P_0c064c5e;
P_0c064c5e: /* original 4308, guest PC 0x0c064c5e */
if(!s->budget--) { s->failed_pc=0x0c064c5eu; return 0; }
r[3]<<=2;
goto P_0c064c60;
P_0c064c60: /* original 0346, guest PC 0x0c064c60 */
if(!s->budget--) { s->failed_pc=0x0c064c60u; return 0; }
write(ram,r[3]+r[0],r[4],4);
goto P_0c064c62;
P_0c064c62: /* original 62c3, guest PC 0x0c064c62 */
if(!s->budget--) { s->failed_pc=0x0c064c62u; return 0; }
r[2]=r[12];
goto P_0c064c64;
P_0c064c64: /* original 7c01, guest PC 0x0c064c64 */
if(!s->budget--) { s->failed_pc=0x0c064c64u; return 0; }
r[12]+=0x00000001u;
goto P_0c064c66;
P_0c064c66: /* original 4208, guest PC 0x0c064c66 */
if(!s->budget--) { s->failed_pc=0x0c064c66u; return 0; }
r[2]<<=2;
goto P_0c064c68;
P_0c064c68: /* original 0256, guest PC 0x0c064c68 */
if(!s->budget--) { s->failed_pc=0x0c064c68u; return 0; }
write(ram,r[2]+r[0],r[5],4);
goto P_0c064c6a;
P_0c064c6a: /* original 63c3, guest PC 0x0c064c6a */
if(!s->budget--) { s->failed_pc=0x0c064c6au; return 0; }
r[3]=r[12];
goto P_0c064c6c;
P_0c064c6c: /* original 62e2, guest PC 0x0c064c6c */
if(!s->budget--) { s->failed_pc=0x0c064c6cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064c6e;
P_0c064c6e: /* original 7c01, guest PC 0x0c064c6e */
if(!s->budget--) { s->failed_pc=0x0c064c6eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064c70;
P_0c064c70: /* original 5221, guest PC 0x0c064c70 */
if(!s->budget--) { s->failed_pc=0x0c064c70u; return 0; }
r[2]=read(ram,r[2]+4,4);
goto P_0c064c72;
P_0c064c72: /* original 4308, guest PC 0x0c064c72 */
if(!s->budget--) { s->failed_pc=0x0c064c72u; return 0; }
r[3]<<=2;
goto P_0c064c74;
P_0c064c74: /* original 0326, guest PC 0x0c064c74 */
if(!s->budget--) { s->failed_pc=0x0c064c74u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064c76;
P_0c064c76: /* original 63c3, guest PC 0x0c064c76 */
if(!s->budget--) { s->failed_pc=0x0c064c76u; return 0; }
r[3]=r[12];
goto P_0c064c78;
P_0c064c78: /* original 62e2, guest PC 0x0c064c78 */
if(!s->budget--) { s->failed_pc=0x0c064c78u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064c7a;
P_0c064c7a: /* original 7c01, guest PC 0x0c064c7a */
if(!s->budget--) { s->failed_pc=0x0c064c7au; return 0; }
r[12]+=0x00000001u;
goto P_0c064c7c;
P_0c064c7c: /* original 5222, guest PC 0x0c064c7c */
if(!s->budget--) { s->failed_pc=0x0c064c7cu; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c064c7e;
P_0c064c7e: /* original 4308, guest PC 0x0c064c7e */
if(!s->budget--) { s->failed_pc=0x0c064c7eu; return 0; }
r[3]<<=2;
goto P_0c064c80;
P_0c064c80: /* original 0326, guest PC 0x0c064c80 */
if(!s->budget--) { s->failed_pc=0x0c064c80u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064c82;
P_0c064c82: /* original 63c3, guest PC 0x0c064c82 */
if(!s->budget--) { s->failed_pc=0x0c064c82u; return 0; }
r[3]=r[12];
goto P_0c064c84;
P_0c064c84: /* original 62e2, guest PC 0x0c064c84 */
if(!s->budget--) { s->failed_pc=0x0c064c84u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064c86;
P_0c064c86: /* original 7c01, guest PC 0x0c064c86 */
if(!s->budget--) { s->failed_pc=0x0c064c86u; return 0; }
r[12]+=0x00000001u;
goto P_0c064c88;
P_0c064c88: /* original 5223, guest PC 0x0c064c88 */
if(!s->budget--) { s->failed_pc=0x0c064c88u; return 0; }
r[2]=read(ram,r[2]+12,4);
goto P_0c064c8a;
P_0c064c8a: /* original 4308, guest PC 0x0c064c8a */
if(!s->budget--) { s->failed_pc=0x0c064c8au; return 0; }
r[3]<<=2;
goto P_0c064c8c;
P_0c064c8c: /* original 0326, guest PC 0x0c064c8c */
if(!s->budget--) { s->failed_pc=0x0c064c8cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c064c8e;
P_0c064c8e: /* original 65c3, guest PC 0x0c064c8e */
if(!s->budget--) { s->failed_pc=0x0c064c8eu; return 0; }
r[5]=r[12];
goto P_0c064c90;
P_0c064c90: /* original 66e2, guest PC 0x0c064c90 */
if(!s->budget--) { s->failed_pc=0x0c064c90u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064c92;
P_0c064c92: /* original 5664, guest PC 0x0c064c92 */
if(!s->budget--) { s->failed_pc=0x0c064c92u; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064c94;
P_0c064c94: /* original bc56, guest PC 0x0c064c94 */
if(!s->budget--) { s->failed_pc=0x0c064c94u; return 0; }
target=code_base|0x0c064544u; r[16]=code_base|0x0c064c98u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064c98u) { target=s->pc; goto dispatch; }
goto P_0c064c98;
P_0c064c96: /* original 64d3, guest PC 0x0c064c96 */
if(!s->budget--) { s->failed_pc=0x0c064c96u; return 0; }
r[4]=r[13];
goto P_0c064c98;
P_0c064c98: /* original 63e2, guest PC 0x0c064c98 */
if(!s->budget--) { s->failed_pc=0x0c064c98u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c064c9a;
P_0c064c9a: /* original 6c03, guest PC 0x0c064c9a */
if(!s->budget--) { s->failed_pc=0x0c064c9au; return 0; }
r[12]=r[0];
goto P_0c064c9c;
P_0c064c9c: /* original 5136, guest PC 0x0c064c9c */
if(!s->budget--) { s->failed_pc=0x0c064c9cu; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064c9e;
P_0c064c9e: /* original 62c3, guest PC 0x0c064c9e */
if(!s->budget--) { s->failed_pc=0x0c064c9eu; return 0; }
r[2]=r[12];
goto P_0c064ca0;
P_0c064ca0: /* original d038, guest PC 0x0c064ca0 */
if(!s->budget--) { s->failed_pc=0x0c064ca0u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064ca2;
P_0c064ca2: /* original 7c01, guest PC 0x0c064ca2 */
if(!s->budget--) { s->failed_pc=0x0c064ca2u; return 0; }
r[12]+=0x00000001u;
goto P_0c064ca4;
P_0c064ca4: /* original 4208, guest PC 0x0c064ca4 */
if(!s->budget--) { s->failed_pc=0x0c064ca4u; return 0; }
r[2]<<=2;
goto P_0c064ca6;
P_0c064ca6: /* original 0216, guest PC 0x0c064ca6 */
if(!s->budget--) { s->failed_pc=0x0c064ca6u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064ca8;
P_0c064ca8: /* original 66e2, guest PC 0x0c064ca8 */
if(!s->budget--) { s->failed_pc=0x0c064ca8u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064caa;
P_0c064caa: /* original 65c3, guest PC 0x0c064caa */
if(!s->budget--) { s->failed_pc=0x0c064caau; return 0; }
r[5]=r[12];
goto P_0c064cac;
P_0c064cac: /* original 5667, guest PC 0x0c064cac */
if(!s->budget--) { s->failed_pc=0x0c064cacu; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064cae;
P_0c064cae: /* original bc3f, guest PC 0x0c064cae */
if(!s->budget--) { s->failed_pc=0x0c064caeu; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064cb2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064cb2u) { target=s->pc; goto dispatch; }
goto P_0c064cb2;
P_0c064cb0: /* original 64d3, guest PC 0x0c064cb0 */
if(!s->budget--) { s->failed_pc=0x0c064cb0u; return 0; }
r[4]=r[13];
goto P_0c064cb2;
P_0c064cb2: /* original 6c03, guest PC 0x0c064cb2 */
if(!s->budget--) { s->failed_pc=0x0c064cb2u; return 0; }
r[12]=r[0];
goto P_0c064cb4;
P_0c064cb4: /* original 61a2, guest PC 0x0c064cb4 */
if(!s->budget--) { s->failed_pc=0x0c064cb4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064cb6;
P_0c064cb6: /* original 62c3, guest PC 0x0c064cb6 */
if(!s->budget--) { s->failed_pc=0x0c064cb6u; return 0; }
r[2]=r[12];
goto P_0c064cb8;
P_0c064cb8: /* original d032, guest PC 0x0c064cb8 */
if(!s->budget--) { s->failed_pc=0x0c064cb8u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064cba;
P_0c064cba: /* original 7c01, guest PC 0x0c064cba */
if(!s->budget--) { s->failed_pc=0x0c064cbau; return 0; }
r[12]+=0x00000001u;
goto P_0c064cbc;
P_0c064cbc: /* original 5311, guest PC 0x0c064cbc */
if(!s->budget--) { s->failed_pc=0x0c064cbcu; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064cbe;
P_0c064cbe: /* original 4208, guest PC 0x0c064cbe */
if(!s->budget--) { s->failed_pc=0x0c064cbeu; return 0; }
r[2]<<=2;
goto P_0c064cc0;
P_0c064cc0: /* original 0236, guest PC 0x0c064cc0 */
if(!s->budget--) { s->failed_pc=0x0c064cc0u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064cc2;
P_0c064cc2: /* original 62c3, guest PC 0x0c064cc2 */
if(!s->budget--) { s->failed_pc=0x0c064cc2u; return 0; }
r[2]=r[12];
goto P_0c064cc4;
P_0c064cc4: /* original 61a2, guest PC 0x0c064cc4 */
if(!s->budget--) { s->failed_pc=0x0c064cc4u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064cc6;
P_0c064cc6: /* original 7c01, guest PC 0x0c064cc6 */
if(!s->budget--) { s->failed_pc=0x0c064cc6u; return 0; }
r[12]+=0x00000001u;
goto P_0c064cc8;
P_0c064cc8: /* original 5312, guest PC 0x0c064cc8 */
if(!s->budget--) { s->failed_pc=0x0c064cc8u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064cca;
P_0c064cca: /* original 4208, guest PC 0x0c064cca */
if(!s->budget--) { s->failed_pc=0x0c064ccau; return 0; }
r[2]<<=2;
goto P_0c064ccc;
P_0c064ccc: /* original 0236, guest PC 0x0c064ccc */
if(!s->budget--) { s->failed_pc=0x0c064cccu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064cce;
P_0c064cce: /* original 62c3, guest PC 0x0c064cce */
if(!s->budget--) { s->failed_pc=0x0c064cceu; return 0; }
r[2]=r[12];
goto P_0c064cd0;
P_0c064cd0: /* original 61a2, guest PC 0x0c064cd0 */
if(!s->budget--) { s->failed_pc=0x0c064cd0u; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c064cd2;
P_0c064cd2: /* original 7c01, guest PC 0x0c064cd2 */
if(!s->budget--) { s->failed_pc=0x0c064cd2u; return 0; }
r[12]+=0x00000001u;
goto P_0c064cd4;
P_0c064cd4: /* original 5313, guest PC 0x0c064cd4 */
if(!s->budget--) { s->failed_pc=0x0c064cd4u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064cd6;
P_0c064cd6: /* original 4208, guest PC 0x0c064cd6 */
if(!s->budget--) { s->failed_pc=0x0c064cd6u; return 0; }
r[2]<<=2;
goto P_0c064cd8;
P_0c064cd8: /* original 0236, guest PC 0x0c064cd8 */
if(!s->budget--) { s->failed_pc=0x0c064cd8u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064cda;
P_0c064cda: /* original 65c3, guest PC 0x0c064cda */
if(!s->budget--) { s->failed_pc=0x0c064cdau; return 0; }
r[5]=r[12];
goto P_0c064cdc;
P_0c064cdc: /* original 66a2, guest PC 0x0c064cdc */
if(!s->budget--) { s->failed_pc=0x0c064cdcu; return 0; }
tmp=read(ram,r[10],4);
r[6]=tmp;
goto P_0c064cde;
P_0c064cde: /* original 5664, guest PC 0x0c064cde */
if(!s->budget--) { s->failed_pc=0x0c064cdeu; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064ce0;
P_0c064ce0: /* original bc30, guest PC 0x0c064ce0 */
if(!s->budget--) { s->failed_pc=0x0c064ce0u; return 0; }
target=code_base|0x0c064544u; r[16]=code_base|0x0c064ce4u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064ce4u) { target=s->pc; goto dispatch; }
goto P_0c064ce4;
P_0c064ce2: /* original 64d3, guest PC 0x0c064ce2 */
if(!s->budget--) { s->failed_pc=0x0c064ce2u; return 0; }
r[4]=r[13];
goto P_0c064ce4;
P_0c064ce4: /* original 63a2, guest PC 0x0c064ce4 */
if(!s->budget--) { s->failed_pc=0x0c064ce4u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c064ce6;
P_0c064ce6: /* original 6c03, guest PC 0x0c064ce6 */
if(!s->budget--) { s->failed_pc=0x0c064ce6u; return 0; }
r[12]=r[0];
goto P_0c064ce8;
P_0c064ce8: /* original 5136, guest PC 0x0c064ce8 */
if(!s->budget--) { s->failed_pc=0x0c064ce8u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064cea;
P_0c064cea: /* original 62c3, guest PC 0x0c064cea */
if(!s->budget--) { s->failed_pc=0x0c064ceau; return 0; }
r[2]=r[12];
goto P_0c064cec;
P_0c064cec: /* original d025, guest PC 0x0c064cec */
if(!s->budget--) { s->failed_pc=0x0c064cecu; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064cee;
P_0c064cee: /* original 7c01, guest PC 0x0c064cee */
if(!s->budget--) { s->failed_pc=0x0c064ceeu; return 0; }
r[12]+=0x00000001u;
goto P_0c064cf0;
P_0c064cf0: /* original 4208, guest PC 0x0c064cf0 */
if(!s->budget--) { s->failed_pc=0x0c064cf0u; return 0; }
r[2]<<=2;
goto P_0c064cf2;
P_0c064cf2: /* original 0216, guest PC 0x0c064cf2 */
if(!s->budget--) { s->failed_pc=0x0c064cf2u; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064cf4;
P_0c064cf4: /* original 66e2, guest PC 0x0c064cf4 */
if(!s->budget--) { s->failed_pc=0x0c064cf4u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064cf6;
P_0c064cf6: /* original 65c3, guest PC 0x0c064cf6 */
if(!s->budget--) { s->failed_pc=0x0c064cf6u; return 0; }
r[5]=r[12];
goto P_0c064cf8;
P_0c064cf8: /* original 5667, guest PC 0x0c064cf8 */
if(!s->budget--) { s->failed_pc=0x0c064cf8u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064cfa;
P_0c064cfa: /* original bc19, guest PC 0x0c064cfa */
if(!s->budget--) { s->failed_pc=0x0c064cfau; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064cfeu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064cfeu) { target=s->pc; goto dispatch; }
goto P_0c064cfe;
P_0c064cfc: /* original 64d3, guest PC 0x0c064cfc */
if(!s->budget--) { s->failed_pc=0x0c064cfcu; return 0; }
r[4]=r[13];
goto P_0c064cfe;
P_0c064cfe: /* original 6c03, guest PC 0x0c064cfe */
if(!s->budget--) { s->failed_pc=0x0c064cfeu; return 0; }
r[12]=r[0];
goto P_0c064d00;
P_0c064d00: /* original 61b2, guest PC 0x0c064d00 */
if(!s->budget--) { s->failed_pc=0x0c064d00u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064d02;
P_0c064d02: /* original 62c3, guest PC 0x0c064d02 */
if(!s->budget--) { s->failed_pc=0x0c064d02u; return 0; }
r[2]=r[12];
goto P_0c064d04;
P_0c064d04: /* original d01f, guest PC 0x0c064d04 */
if(!s->budget--) { s->failed_pc=0x0c064d04u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064d06;
P_0c064d06: /* original 7c01, guest PC 0x0c064d06 */
if(!s->budget--) { s->failed_pc=0x0c064d06u; return 0; }
r[12]+=0x00000001u;
goto P_0c064d08;
P_0c064d08: /* original 5311, guest PC 0x0c064d08 */
if(!s->budget--) { s->failed_pc=0x0c064d08u; return 0; }
r[3]=read(ram,r[1]+4,4);
goto P_0c064d0a;
P_0c064d0a: /* original 4208, guest PC 0x0c064d0a */
if(!s->budget--) { s->failed_pc=0x0c064d0au; return 0; }
r[2]<<=2;
goto P_0c064d0c;
P_0c064d0c: /* original 0236, guest PC 0x0c064d0c */
if(!s->budget--) { s->failed_pc=0x0c064d0cu; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064d0e;
P_0c064d0e: /* original 62c3, guest PC 0x0c064d0e */
if(!s->budget--) { s->failed_pc=0x0c064d0eu; return 0; }
r[2]=r[12];
goto P_0c064d10;
P_0c064d10: /* original 61b2, guest PC 0x0c064d10 */
if(!s->budget--) { s->failed_pc=0x0c064d10u; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064d12;
P_0c064d12: /* original 7c01, guest PC 0x0c064d12 */
if(!s->budget--) { s->failed_pc=0x0c064d12u; return 0; }
r[12]+=0x00000001u;
goto P_0c064d14;
P_0c064d14: /* original 5312, guest PC 0x0c064d14 */
if(!s->budget--) { s->failed_pc=0x0c064d14u; return 0; }
r[3]=read(ram,r[1]+8,4);
goto P_0c064d16;
P_0c064d16: /* original 4208, guest PC 0x0c064d16 */
if(!s->budget--) { s->failed_pc=0x0c064d16u; return 0; }
r[2]<<=2;
goto P_0c064d18;
P_0c064d18: /* original 0236, guest PC 0x0c064d18 */
if(!s->budget--) { s->failed_pc=0x0c064d18u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064d1a;
P_0c064d1a: /* original 62c3, guest PC 0x0c064d1a */
if(!s->budget--) { s->failed_pc=0x0c064d1au; return 0; }
r[2]=r[12];
goto P_0c064d1c;
P_0c064d1c: /* original 61b2, guest PC 0x0c064d1c */
if(!s->budget--) { s->failed_pc=0x0c064d1cu; return 0; }
tmp=read(ram,r[11],4);
r[1]=tmp;
goto P_0c064d1e;
P_0c064d1e: /* original 7c01, guest PC 0x0c064d1e */
if(!s->budget--) { s->failed_pc=0x0c064d1eu; return 0; }
r[12]+=0x00000001u;
goto P_0c064d20;
P_0c064d20: /* original 5313, guest PC 0x0c064d20 */
if(!s->budget--) { s->failed_pc=0x0c064d20u; return 0; }
r[3]=read(ram,r[1]+12,4);
goto P_0c064d22;
P_0c064d22: /* original 4208, guest PC 0x0c064d22 */
if(!s->budget--) { s->failed_pc=0x0c064d22u; return 0; }
r[2]<<=2;
goto P_0c064d24;
P_0c064d24: /* original 0236, guest PC 0x0c064d24 */
if(!s->budget--) { s->failed_pc=0x0c064d24u; return 0; }
write(ram,r[2]+r[0],r[3],4);
goto P_0c064d26;
P_0c064d26: /* original 65c3, guest PC 0x0c064d26 */
if(!s->budget--) { s->failed_pc=0x0c064d26u; return 0; }
r[5]=r[12];
goto P_0c064d28;
P_0c064d28: /* original 66b2, guest PC 0x0c064d28 */
if(!s->budget--) { s->failed_pc=0x0c064d28u; return 0; }
tmp=read(ram,r[11],4);
r[6]=tmp;
goto P_0c064d2a;
P_0c064d2a: /* original 5664, guest PC 0x0c064d2a */
if(!s->budget--) { s->failed_pc=0x0c064d2au; return 0; }
r[6]=read(ram,r[6]+16,4);
goto P_0c064d2c;
P_0c064d2c: /* original bc0a, guest PC 0x0c064d2c */
if(!s->budget--) { s->failed_pc=0x0c064d2cu; return 0; }
target=code_base|0x0c064544u; r[16]=code_base|0x0c064d30u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064d30u) { target=s->pc; goto dispatch; }
goto P_0c064d30;
P_0c064d2e: /* original 64d3, guest PC 0x0c064d2e */
if(!s->budget--) { s->failed_pc=0x0c064d2eu; return 0; }
r[4]=r[13];
goto P_0c064d30;
P_0c064d30: /* original 63b2, guest PC 0x0c064d30 */
if(!s->budget--) { s->failed_pc=0x0c064d30u; return 0; }
tmp=read(ram,r[11],4);
r[3]=tmp;
goto P_0c064d32;
P_0c064d32: /* original 6c03, guest PC 0x0c064d32 */
if(!s->budget--) { s->failed_pc=0x0c064d32u; return 0; }
r[12]=r[0];
goto P_0c064d34;
P_0c064d34: /* original 5136, guest PC 0x0c064d34 */
if(!s->budget--) { s->failed_pc=0x0c064d34u; return 0; }
r[1]=read(ram,r[3]+24,4);
goto P_0c064d36;
P_0c064d36: /* original 62c3, guest PC 0x0c064d36 */
if(!s->budget--) { s->failed_pc=0x0c064d36u; return 0; }
r[2]=r[12];
goto P_0c064d38;
P_0c064d38: /* original d012, guest PC 0x0c064d38 */
if(!s->budget--) { s->failed_pc=0x0c064d38u; return 0; }
r[0]=read(ram,0x0c064d84u,4);
goto P_0c064d3a;
P_0c064d3a: /* original 7c01, guest PC 0x0c064d3a */
if(!s->budget--) { s->failed_pc=0x0c064d3au; return 0; }
r[12]+=0x00000001u;
goto P_0c064d3c;
P_0c064d3c: /* original 4208, guest PC 0x0c064d3c */
if(!s->budget--) { s->failed_pc=0x0c064d3cu; return 0; }
r[2]<<=2;
goto P_0c064d3e;
P_0c064d3e: /* original 0216, guest PC 0x0c064d3e */
if(!s->budget--) { s->failed_pc=0x0c064d3eu; return 0; }
write(ram,r[2]+r[0],r[1],4);
goto P_0c064d40;
P_0c064d40: /* original 66e2, guest PC 0x0c064d40 */
if(!s->budget--) { s->failed_pc=0x0c064d40u; return 0; }
tmp=read(ram,r[14],4);
r[6]=tmp;
goto P_0c064d42;
P_0c064d42: /* original 65c3, guest PC 0x0c064d42 */
if(!s->budget--) { s->failed_pc=0x0c064d42u; return 0; }
r[5]=r[12];
goto P_0c064d44;
P_0c064d44: /* original 5667, guest PC 0x0c064d44 */
if(!s->budget--) { s->failed_pc=0x0c064d44u; return 0; }
r[6]=read(ram,r[6]+28,4);
goto P_0c064d46;
P_0c064d46: /* original bbf3, guest PC 0x0c064d46 */
if(!s->budget--) { s->failed_pc=0x0c064d46u; return 0; }
target=code_base|0x0c064530u; r[16]=code_base|0x0c064d4au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064d4au) { target=s->pc; goto dispatch; }
goto P_0c064d4a;
P_0c064d48: /* original 64d3, guest PC 0x0c064d48 */
if(!s->budget--) { s->failed_pc=0x0c064d48u; return 0; }
r[4]=r[13];
goto P_0c064d4a;
P_0c064d4a: /* original 6403, guest PC 0x0c064d4a */
if(!s->budget--) { s->failed_pc=0x0c064d4au; return 0; }
r[4]=r[0];
goto P_0c064d4c;
P_0c064d4c: /* original d20e, guest PC 0x0c064d4c */
if(!s->budget--) { s->failed_pc=0x0c064d4cu; return 0; }
r[2]=read(ram,0x0c064d88u,4);
goto P_0c064d4e;
P_0c064d4e: /* original 4408, guest PC 0x0c064d4e */
if(!s->budget--) { s->failed_pc=0x0c064d4eu; return 0; }
r[4]<<=2;
goto P_0c064d50;
P_0c064d50: /* original 2242, guest PC 0x0c064d50 */
if(!s->budget--) { s->failed_pc=0x0c064d50u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c064d52;
P_0c064d52: /* original bbde, guest PC 0x0c064d52 */
if(!s->budget--) { s->failed_pc=0x0c064d52u; return 0; }
target=code_base|0x0c064512u; r[16]=code_base|0x0c064d56u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064d56u) { target=s->pc; goto dispatch; }
goto P_0c064d56;
P_0c064d54: /* original 64d3, guest PC 0x0c064d54 */
if(!s->budget--) { s->failed_pc=0x0c064d54u; return 0; }
r[4]=r[13];
goto P_0c064d56;
P_0c064d56: /* original 6403, guest PC 0x0c064d56 */
if(!s->budget--) { s->failed_pc=0x0c064d56u; return 0; }
r[4]=r[0];
goto P_0c064d58;
P_0c064d58: /* original e500, guest PC 0x0c064d58 */
if(!s->budget--) { s->failed_pc=0x0c064d58u; return 0; }
r[5]=0x00000000u;
goto P_0c064d5a;
P_0c064d5a: /* original bbc5, guest PC 0x0c064d5a */
if(!s->budget--) { s->failed_pc=0x0c064d5au; return 0; }
target=code_base|0x0c0644e8u; r[16]=code_base|0x0c064d5eu;
r[6]=r[5];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c064d5eu) { target=s->pc; goto dispatch; }
goto P_0c064d5e;
P_0c064d5c: /* original 6653, guest PC 0x0c064d5c */
if(!s->budget--) { s->failed_pc=0x0c064d5cu; return 0; }
r[6]=r[5];
goto P_0c064d5e;
P_0c064d5e: /* original 62e2, guest PC 0x0c064d5e */
if(!s->budget--) { s->failed_pc=0x0c064d5eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c064d60;
P_0c064d60: /* original d10a, guest PC 0x0c064d60 */
if(!s->budget--) { s->failed_pc=0x0c064d60u; return 0; }
r[1]=read(ram,0x0c064d8cu,4);
goto P_0c064d62;
P_0c064d62: /* original 5323, guest PC 0x0c064d62 */
if(!s->budget--) { s->failed_pc=0x0c064d62u; return 0; }
r[3]=read(ram,r[2]+12,4);
goto P_0c064d64;
P_0c064d64: /* original 2132, guest PC 0x0c064d64 */
if(!s->budget--) { s->failed_pc=0x0c064d64u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c064d66;
P_0c064d66: /* original e000, guest PC 0x0c064d66 */
if(!s->budget--) { s->failed_pc=0x0c064d66u; return 0; }
r[0]=0x00000000u;
goto P_0c064d68;
P_0c064d68: /* original 7f0c, guest PC 0x0c064d68 */
if(!s->budget--) { s->failed_pc=0x0c064d68u; return 0; }
r[15]+=0x0000000cu;
goto P_0c064d6a;
P_0c064d6a: /* original 4f26, guest PC 0x0c064d6a */
if(!s->budget--) { s->failed_pc=0x0c064d6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c064d6c;
P_0c064d6c: /* original 6af6, guest PC 0x0c064d6c */
if(!s->budget--) { s->failed_pc=0x0c064d6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c064d6e;
P_0c064d6e: /* original 6bf6, guest PC 0x0c064d6e */
if(!s->budget--) { s->failed_pc=0x0c064d6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c064d70;
P_0c064d70: /* original 6cf6, guest PC 0x0c064d70 */
if(!s->budget--) { s->failed_pc=0x0c064d70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c064d72;
P_0c064d72: /* original 6df6, guest PC 0x0c064d72 */
if(!s->budget--) { s->failed_pc=0x0c064d72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c064d74;
P_0c064d74: /* original 000b, guest PC 0x0c064d74 */
if(!s->budget--) { s->failed_pc=0x0c064d74u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c064d76: /* original 6ef6, guest PC 0x0c064d76 */
if(!s->budget--) { s->failed_pc=0x0c064d76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c064d78u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c064d78u; return 0; } return 1;
P_0c0662d8: /* original 2fe6, guest PC 0x0c0662d8 */
if(!s->budget--) { s->failed_pc=0x0c0662d8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0662da;
P_0c0662da: /* original 2fd6, guest PC 0x0c0662da */
if(!s->budget--) { s->failed_pc=0x0c0662dau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0662dc;
P_0c0662dc: /* original 4f22, guest PC 0x0c0662dc */
if(!s->budget--) { s->failed_pc=0x0c0662dcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0662de;
P_0c0662de: /* original 6d63, guest PC 0x0c0662de */
if(!s->budget--) { s->failed_pc=0x0c0662deu; return 0; }
r[13]=r[6];
goto P_0c0662e0;
P_0c0662e0: /* original d033, guest PC 0x0c0662e0 */
if(!s->budget--) { s->failed_pc=0x0c0662e0u; return 0; }
r[0]=read(ram,0x0c0663b0u,4);
goto P_0c0662e2;
P_0c0662e2: /* original 7ff4, guest PC 0x0c0662e2 */
if(!s->budget--) { s->failed_pc=0x0c0662e2u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0662e4;
P_0c0662e4: /* original de31, guest PC 0x0c0662e4 */
if(!s->budget--) { s->failed_pc=0x0c0662e4u; return 0; }
r[14]=read(ram,0x0c0663acu,4);
goto P_0c0662e6;
P_0c0662e6: /* original 4d08, guest PC 0x0c0662e6 */
if(!s->budget--) { s->failed_pc=0x0c0662e6u; return 0; }
r[13]<<=2;
goto P_0c0662e8;
P_0c0662e8: /* original 2f42, guest PC 0x0c0662e8 */
if(!s->budget--) { s->failed_pc=0x0c0662e8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0662ea;
P_0c0662ea: /* original 4d08, guest PC 0x0c0662ea */
if(!s->budget--) { s->failed_pc=0x0c0662eau; return 0; }
r[13]<<=2;
goto P_0c0662ec;
P_0c0662ec: /* original 1f51, guest PC 0x0c0662ec */
if(!s->budget--) { s->failed_pc=0x0c0662ecu; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0662ee;
P_0c0662ee: /* original 4d00, guest PC 0x0c0662ee */
if(!s->budget--) { s->failed_pc=0x0c0662eeu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c0662f0;
P_0c0662f0: /* original 944f, guest PC 0x0c0662f0 */
if(!s->budget--) { s->failed_pc=0x0c0662f0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066392u,2);
goto P_0c0662f2;
P_0c0662f2: /* original 1f62, guest PC 0x0c0662f2 */
if(!s->budget--) { s->failed_pc=0x0c0662f2u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c0662f4;
P_0c0662f4: /* original 4e0b, guest PC 0x0c0662f4 */
if(!s->budget--) { s->failed_pc=0x0c0662f4u; return 0; }
target=r[14];
r[16]=code_base|0x0c0662f8u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0662f8u) { target=s->pc; goto dispatch; }
goto P_0c0662f8;
P_0c0662f6: /* original 05de, guest PC 0x0c0662f6 */
if(!s->budget--) { s->failed_pc=0x0c0662f6u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0662f8;
P_0c0662f8: /* original d02e, guest PC 0x0c0662f8 */
if(!s->budget--) { s->failed_pc=0x0c0662f8u; return 0; }
r[0]=read(ram,0x0c0663b4u,4);
goto P_0c0662fa;
P_0c0662fa: /* original 944b, guest PC 0x0c0662fa */
if(!s->budget--) { s->failed_pc=0x0c0662fau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066394u,2);
goto P_0c0662fc;
P_0c0662fc: /* original 4e0b, guest PC 0x0c0662fc */
if(!s->budget--) { s->failed_pc=0x0c0662fcu; return 0; }
target=r[14];
r[16]=code_base|0x0c066300u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066300u) { target=s->pc; goto dispatch; }
goto P_0c066300;
P_0c0662fe: /* original 05de, guest PC 0x0c0662fe */
if(!s->budget--) { s->failed_pc=0x0c0662feu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c066300;
P_0c066300: /* original d02d, guest PC 0x0c066300 */
if(!s->budget--) { s->failed_pc=0x0c066300u; return 0; }
r[0]=read(ram,0x0c0663b8u,4);
goto P_0c066302;
P_0c066302: /* original 9448, guest PC 0x0c066302 */
if(!s->budget--) { s->failed_pc=0x0c066302u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066396u,2);
goto P_0c066304;
P_0c066304: /* original 4e0b, guest PC 0x0c066304 */
if(!s->budget--) { s->failed_pc=0x0c066304u; return 0; }
target=r[14];
r[16]=code_base|0x0c066308u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066308u) { target=s->pc; goto dispatch; }
goto P_0c066308;
P_0c066306: /* original 05de, guest PC 0x0c066306 */
if(!s->budget--) { s->failed_pc=0x0c066306u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c066308;
P_0c066308: /* original d02c, guest PC 0x0c066308 */
if(!s->budget--) { s->failed_pc=0x0c066308u; return 0; }
r[0]=read(ram,0x0c0663bcu,4);
goto P_0c06630a;
P_0c06630a: /* original 9445, guest PC 0x0c06630a */
if(!s->budget--) { s->failed_pc=0x0c06630au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c066398u,2);
goto P_0c06630c;
P_0c06630c: /* original 4e0b, guest PC 0x0c06630c */
if(!s->budget--) { s->failed_pc=0x0c06630cu; return 0; }
target=r[14];
r[16]=code_base|0x0c066310u;
r[5]=read(ram,r[13]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066310u) { target=s->pc; goto dispatch; }
goto P_0c066310;
P_0c06630e: /* original 05de, guest PC 0x0c06630e */
if(!s->budget--) { s->failed_pc=0x0c06630eu; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c066310;
P_0c066310: /* original 55f1, guest PC 0x0c066310 */
if(!s->budget--) { s->failed_pc=0x0c066310u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c066312;
P_0c066312: /* original 75ff, guest PC 0x0c066312 */
if(!s->budget--) { s->failed_pc=0x0c066312u; return 0; }
r[5]+=0xffffffffu;
goto P_0c066314;
P_0c066314: /* original 63f2, guest PC 0x0c066314 */
if(!s->budget--) { s->failed_pc=0x0c066314u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c066316;
P_0c066316: /* original 4528, guest PC 0x0c066316 */
if(!s->budget--) { s->failed_pc=0x0c066316u; return 0; }
r[5]<<=16;
goto P_0c066318;
P_0c066318: /* original 943f, guest PC 0x0c066318 */
if(!s->budget--) { s->failed_pc=0x0c066318u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06639au,2);
goto P_0c06631a;
P_0c06631a: /* original 353c, guest PC 0x0c06631a */
if(!s->budget--) { s->failed_pc=0x0c06631au; return 0; }
r[5]+=r[3];
goto P_0c06631c;
P_0c06631c: /* original 4e0b, guest PC 0x0c06631c */
if(!s->budget--) { s->failed_pc=0x0c06631cu; return 0; }
target=r[14];
r[16]=code_base|0x0c066320u;
r[5]+=0xffffffffu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066320u) { target=s->pc; goto dispatch; }
goto P_0c066320;
P_0c06631e: /* original 75ff, guest PC 0x0c06631e */
if(!s->budget--) { s->failed_pc=0x0c06631eu; return 0; }
r[5]+=0xffffffffu;
goto P_0c066320;
P_0c066320: /* original d320, guest PC 0x0c066320 */
if(!s->budget--) { s->failed_pc=0x0c066320u; return 0; }
r[3]=read(ram,0x0c0663a4u,4);
goto P_0c066322;
P_0c066322: /* original e403, guest PC 0x0c066322 */
if(!s->budget--) { s->failed_pc=0x0c066322u; return 0; }
r[4]=0x00000003u;
goto P_0c066324;
P_0c066324: /* original 6532, guest PC 0x0c066324 */
if(!s->budget--) { s->failed_pc=0x0c066324u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c066326;
P_0c066326: /* original 2549, guest PC 0x0c066326 */
if(!s->budget--) { s->failed_pc=0x0c066326u; return 0; }
r[5]&=r[4];
goto P_0c066328;
P_0c066328: /* original d11f, guest PC 0x0c066328 */
if(!s->budget--) { s->failed_pc=0x0c066328u; return 0; }
r[1]=read(ram,0x0c0663a8u,4);
goto P_0c06632a;
P_0c06632a: /* original 6212, guest PC 0x0c06632a */
if(!s->budget--) { s->failed_pc=0x0c06632au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c06632c;
P_0c06632c: /* original 2249, guest PC 0x0c06632c */
if(!s->budget--) { s->failed_pc=0x0c06632cu; return 0; }
r[2]&=r[4];
goto P_0c06632e;
P_0c06632e: /* original 4208, guest PC 0x0c06632e */
if(!s->budget--) { s->failed_pc=0x0c06632eu; return 0; }
r[2]<<=2;
goto P_0c066330;
P_0c066330: /* original d023, guest PC 0x0c066330 */
if(!s->budget--) { s->failed_pc=0x0c066330u; return 0; }
r[0]=read(ram,0x0c0663c0u,4);
goto P_0c066332;
P_0c066332: /* original 4208, guest PC 0x0c066332 */
if(!s->budget--) { s->failed_pc=0x0c066332u; return 0; }
r[2]<<=2;
goto P_0c066334;
P_0c066334: /* original 252b, guest PC 0x0c066334 */
if(!s->budget--) { s->failed_pc=0x0c066334u; return 0; }
r[5]|=r[2];
goto P_0c066336;
P_0c066336: /* original 6202, guest PC 0x0c066336 */
if(!s->budget--) { s->failed_pc=0x0c066336u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c066338;
P_0c066338: /* original 2249, guest PC 0x0c066338 */
if(!s->budget--) { s->failed_pc=0x0c066338u; return 0; }
r[2]&=r[4];
goto P_0c06633a;
P_0c06633a: /* original 4218, guest PC 0x0c06633a */
if(!s->budget--) { s->failed_pc=0x0c06633au; return 0; }
r[2]<<=8;
goto P_0c06633c;
P_0c06633c: /* original 252b, guest PC 0x0c06633c */
if(!s->budget--) { s->failed_pc=0x0c06633cu; return 0; }
r[5]|=r[2];
goto P_0c06633e;
P_0c06633e: /* original d221, guest PC 0x0c06633e */
if(!s->budget--) { s->failed_pc=0x0c06633eu; return 0; }
r[2]=read(ram,0x0c0663c4u,4);
goto P_0c066340;
P_0c066340: /* original 6322, guest PC 0x0c066340 */
if(!s->budget--) { s->failed_pc=0x0c066340u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c066342;
P_0c066342: /* original 2349, guest PC 0x0c066342 */
if(!s->budget--) { s->failed_pc=0x0c066342u; return 0; }
r[3]&=r[4];
goto P_0c066344;
P_0c066344: /* original 4318, guest PC 0x0c066344 */
if(!s->budget--) { s->failed_pc=0x0c066344u; return 0; }
r[3]<<=8;
goto P_0c066346;
P_0c066346: /* original 4308, guest PC 0x0c066346 */
if(!s->budget--) { s->failed_pc=0x0c066346u; return 0; }
r[3]<<=2;
goto P_0c066348;
P_0c066348: /* original 4308, guest PC 0x0c066348 */
if(!s->budget--) { s->failed_pc=0x0c066348u; return 0; }
r[3]<<=2;
goto P_0c06634a;
P_0c06634a: /* original 253b, guest PC 0x0c06634a */
if(!s->budget--) { s->failed_pc=0x0c06634au; return 0; }
r[5]|=r[3];
goto P_0c06634c;
P_0c06634c: /* original d31e, guest PC 0x0c06634c */
if(!s->budget--) { s->failed_pc=0x0c06634cu; return 0; }
r[3]=read(ram,0x0c0663c8u,4);
goto P_0c06634e;
P_0c06634e: /* original 6032, guest PC 0x0c06634e */
if(!s->budget--) { s->failed_pc=0x0c06634eu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c066350;
P_0c066350: /* original 8806, guest PC 0x0c066350 */
if(!s->budget--) { s->failed_pc=0x0c066350u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c066352;
P_0c066352: /* original 8f0d, guest PC 0x0c066352 */
if(!s->budget--) { s->failed_pc=0x0c066352u; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(!cond) { goto P_0c066370; }
goto P_0c066356;
P_0c066354: /* original e601, guest PC 0x0c066354 */
if(!s->budget--) { s->failed_pc=0x0c066354u; return 0; }
r[6]=0x00000001u;
goto P_0c066356;
P_0c066356: /* original d11d, guest PC 0x0c066356 */
if(!s->budget--) { s->failed_pc=0x0c066356u; return 0; }
r[1]=read(ram,0x0c0663ccu,4);
goto P_0c066358;
P_0c066358: /* original 6012, guest PC 0x0c066358 */
if(!s->budget--) { s->failed_pc=0x0c066358u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c06635a;
P_0c06635a: /* original 2609, guest PC 0x0c06635a */
if(!s->budget--) { s->failed_pc=0x0c06635au; return 0; }
r[6]&=r[0];
goto P_0c06635c;
P_0c06635c: /* original d01c, guest PC 0x0c06635c */
if(!s->budget--) { s->failed_pc=0x0c06635cu; return 0; }
r[0]=read(ram,0x0c0663d0u,4);
goto P_0c06635e;
P_0c06635e: /* original 4628, guest PC 0x0c06635e */
if(!s->budget--) { s->failed_pc=0x0c06635eu; return 0; }
r[6]<<=16;
goto P_0c066360;
P_0c066360: /* original 4608, guest PC 0x0c066360 */
if(!s->budget--) { s->failed_pc=0x0c066360u; return 0; }
r[6]<<=2;
goto P_0c066362;
P_0c066362: /* original 4608, guest PC 0x0c066362 */
if(!s->budget--) { s->failed_pc=0x0c066362u; return 0; }
r[6]<<=2;
goto P_0c066364;
P_0c066364: /* original 256b, guest PC 0x0c066364 */
if(!s->budget--) { s->failed_pc=0x0c066364u; return 0; }
r[5]|=r[6];
goto P_0c066366;
P_0c066366: /* original 6202, guest PC 0x0c066366 */
if(!s->budget--) { s->failed_pc=0x0c066366u; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c066368;
P_0c066368: /* original 2429, guest PC 0x0c066368 */
if(!s->budget--) { s->failed_pc=0x0c066368u; return 0; }
r[4]&=r[2];
goto P_0c06636a;
P_0c06636a: /* original 4428, guest PC 0x0c06636a */
if(!s->budget--) { s->failed_pc=0x0c06636au; return 0; }
r[4]<<=16;
goto P_0c06636c;
P_0c06636c: /* original a005, guest PC 0x0c06636c */
if(!s->budget--) { s->failed_pc=0x0c06636cu; return 0; }
r[5]|=r[4];
goto P_0c06637a;
P_0c06636e: /* original 254b, guest PC 0x0c06636e */
if(!s->budget--) { s->failed_pc=0x0c06636eu; return 0; }
r[5]|=r[4];
goto P_0c066370;
P_0c066370: /* original d016, guest PC 0x0c066370 */
if(!s->budget--) { s->failed_pc=0x0c066370u; return 0; }
r[0]=read(ram,0x0c0663ccu,4);
goto P_0c066372;
P_0c066372: /* original 6102, guest PC 0x0c066372 */
if(!s->budget--) { s->failed_pc=0x0c066372u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c066374;
P_0c066374: /* original 2619, guest PC 0x0c066374 */
if(!s->budget--) { s->failed_pc=0x0c066374u; return 0; }
r[6]&=r[1];
goto P_0c066376;
P_0c066376: /* original 4628, guest PC 0x0c066376 */
if(!s->budget--) { s->failed_pc=0x0c066376u; return 0; }
r[6]<<=16;
goto P_0c066378;
P_0c066378: /* original 256b, guest PC 0x0c066378 */
if(!s->budget--) { s->failed_pc=0x0c066378u; return 0; }
r[5]|=r[6];
goto P_0c06637a;
P_0c06637a: /* original 940f, guest PC 0x0c06637a */
if(!s->budget--) { s->failed_pc=0x0c06637au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06639cu,2);
goto P_0c06637c;
P_0c06637c: /* original 4e0b, guest PC 0x0c06637c */
if(!s->budget--) { s->failed_pc=0x0c06637cu; return 0; }
target=r[14];
r[16]=code_base|0x0c066380u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066380u) { target=s->pc; goto dispatch; }
goto P_0c066380;
P_0c06637e: /* original 0009, guest PC 0x0c06637e */
if(!s->budget--) { s->failed_pc=0x0c06637eu; return 0; }
goto P_0c066380;
P_0c066380: /* original d514, guest PC 0x0c066380 */
if(!s->budget--) { s->failed_pc=0x0c066380u; return 0; }
r[5]=read(ram,0x0c0663d4u,4);
goto P_0c066382;
P_0c066382: /* original 940c, guest PC 0x0c066382 */
if(!s->budget--) { s->failed_pc=0x0c066382u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06639eu,2);
goto P_0c066384;
P_0c066384: /* original 4e0b, guest PC 0x0c066384 */
if(!s->budget--) { s->failed_pc=0x0c066384u; return 0; }
target=r[14];
r[16]=code_base|0x0c066388u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c066388u) { target=s->pc; goto dispatch; }
goto P_0c066388;
P_0c066386: /* original 0009, guest PC 0x0c066386 */
if(!s->budget--) { s->failed_pc=0x0c066386u; return 0; }
goto P_0c066388;
P_0c066388: /* original 7f0c, guest PC 0x0c066388 */
if(!s->budget--) { s->failed_pc=0x0c066388u; return 0; }
r[15]+=0x0000000cu;
goto P_0c06638a;
P_0c06638a: /* original 4f26, guest PC 0x0c06638a */
if(!s->budget--) { s->failed_pc=0x0c06638au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06638c;
P_0c06638c: /* original 6df6, guest PC 0x0c06638c */
if(!s->budget--) { s->failed_pc=0x0c06638cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06638e;
P_0c06638e: /* original 000b, guest PC 0x0c06638e */
if(!s->budget--) { s->failed_pc=0x0c06638eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c066390: /* original 6ef6, guest PC 0x0c066390 */
if(!s->budget--) { s->failed_pc=0x0c066390u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c066392u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c066392u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
