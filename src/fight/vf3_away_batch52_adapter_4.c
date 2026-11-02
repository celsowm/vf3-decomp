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
int vf3_away_batch52_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c085c28u: goto P_0c085c28;
case 0x0c085c2au: goto P_0c085c2a;
case 0x0c085c2cu: goto P_0c085c2c;
case 0x0c085c2eu: goto P_0c085c2e;
case 0x0c085c30u: goto P_0c085c30;
case 0x0c085c32u: goto P_0c085c32;
case 0x0c085c34u: goto P_0c085c34;
case 0x0c085c36u: goto P_0c085c36;
case 0x0c085c38u: goto P_0c085c38;
case 0x0c085c3au: goto P_0c085c3a;
case 0x0c085c3cu: goto P_0c085c3c;
case 0x0c085c3eu: goto P_0c085c3e;
case 0x0c085c40u: goto P_0c085c40;
case 0x0c085c42u: goto P_0c085c42;
case 0x0c085c44u: goto P_0c085c44;
case 0x0c085c46u: goto P_0c085c46;
case 0x0c085c48u: goto P_0c085c48;
case 0x0c085c4au: goto P_0c085c4a;
case 0x0c085c4cu: goto P_0c085c4c;
case 0x0c085c4eu: goto P_0c085c4e;
case 0x0c085c50u: goto P_0c085c50;
case 0x0c085c52u: goto P_0c085c52;
case 0x0c085c54u: goto P_0c085c54;
case 0x0c085c56u: goto P_0c085c56;
case 0x0c085c58u: goto P_0c085c58;
case 0x0c085c5au: goto P_0c085c5a;
case 0x0c085c5cu: goto P_0c085c5c;
case 0x0c085c5eu: goto P_0c085c5e;
case 0x0c085c60u: goto P_0c085c60;
case 0x0c085c62u: goto P_0c085c62;
case 0x0c085c64u: goto P_0c085c64;
case 0x0c085c66u: goto P_0c085c66;
case 0x0c085c68u: goto P_0c085c68;
case 0x0c085c6au: goto P_0c085c6a;
case 0x0c085c6cu: goto P_0c085c6c;
case 0x0c085c6eu: goto P_0c085c6e;
case 0x0c085c70u: goto P_0c085c70;
case 0x0c085c72u: goto P_0c085c72;
case 0x0c085c74u: goto P_0c085c74;
case 0x0c085c76u: goto P_0c085c76;
case 0x0c085c78u: goto P_0c085c78;
case 0x0c085c7au: goto P_0c085c7a;
case 0x0c0955b0u: goto P_0c0955b0;
case 0x0c0955b2u: goto P_0c0955b2;
case 0x0c0955b4u: goto P_0c0955b4;
case 0x0c0955b6u: goto P_0c0955b6;
case 0x0c0955b8u: goto P_0c0955b8;
case 0x0c0955bau: goto P_0c0955ba;
case 0x0c0955bcu: goto P_0c0955bc;
case 0x0c0955beu: goto P_0c0955be;
case 0x0c0955c0u: goto P_0c0955c0;
case 0x0c0955c2u: goto P_0c0955c2;
case 0x0c0955c4u: goto P_0c0955c4;
case 0x0c0955c6u: goto P_0c0955c6;
case 0x0c0955c8u: goto P_0c0955c8;
case 0x0c0955cau: goto P_0c0955ca;
case 0x0c0955ccu: goto P_0c0955cc;
case 0x0c0955ceu: goto P_0c0955ce;
case 0x0c0955d0u: goto P_0c0955d0;
case 0x0c0955d2u: goto P_0c0955d2;
case 0x0c0955d4u: goto P_0c0955d4;
case 0x0c0955d6u: goto P_0c0955d6;
case 0x0c0955d8u: goto P_0c0955d8;
case 0x0c0955dau: goto P_0c0955da;
case 0x0c0955dcu: goto P_0c0955dc;
case 0x0c0955deu: goto P_0c0955de;
case 0x0c0955e0u: goto P_0c0955e0;
case 0x0c0955e2u: goto P_0c0955e2;
case 0x0c0955e4u: goto P_0c0955e4;
case 0x0c0955e6u: goto P_0c0955e6;
case 0x0c0955e8u: goto P_0c0955e8;
case 0x0c0955eau: goto P_0c0955ea;
case 0x0c0955ecu: goto P_0c0955ec;
case 0x0c0955eeu: goto P_0c0955ee;
case 0x0c0955f0u: goto P_0c0955f0;
case 0x0c0955f2u: goto P_0c0955f2;
case 0x0c0955f4u: goto P_0c0955f4;
case 0x0c0955f6u: goto P_0c0955f6;
case 0x0c0955f8u: goto P_0c0955f8;
case 0x0c0955fau: goto P_0c0955fa;
case 0x0c0955fcu: goto P_0c0955fc;
case 0x0c0955feu: goto P_0c0955fe;
case 0x0c095600u: goto P_0c095600;
case 0x0c095602u: goto P_0c095602;
case 0x0c0a7250u: goto P_0c0a7250;
case 0x0c0a7252u: goto P_0c0a7252;
case 0x0c0a7254u: goto P_0c0a7254;
case 0x0c0a7256u: goto P_0c0a7256;
case 0x0c0a7258u: goto P_0c0a7258;
case 0x0c0a725au: goto P_0c0a725a;
case 0x0c0a725cu: goto P_0c0a725c;
case 0x0c0a725eu: goto P_0c0a725e;
case 0x0c0a7260u: goto P_0c0a7260;
case 0x0c0a7262u: goto P_0c0a7262;
case 0x0c0a7442u: goto P_0c0a7442;
case 0x0c0a7444u: goto P_0c0a7444;
case 0x0c0a7446u: goto P_0c0a7446;
case 0x0c0a7448u: goto P_0c0a7448;
case 0x0c0a744au: goto P_0c0a744a;
case 0x0c0a744cu: goto P_0c0a744c;
case 0x0c0a744eu: goto P_0c0a744e;
case 0x0c0c9cc0u: goto P_0c0c9cc0;
case 0x0c0c9cc2u: goto P_0c0c9cc2;
case 0x0c0c9cc4u: goto P_0c0c9cc4;
case 0x0c0c9cc6u: goto P_0c0c9cc6;
case 0x0c0c9cc8u: goto P_0c0c9cc8;
case 0x0c0c9ccau: goto P_0c0c9cca;
case 0x0c0c9cccu: goto P_0c0c9ccc;
case 0x0c0c9cceu: goto P_0c0c9cce;
case 0x0c0c9cd0u: goto P_0c0c9cd0;
case 0x0c0c9cd2u: goto P_0c0c9cd2;
case 0x0c0c9cd4u: goto P_0c0c9cd4;
case 0x0c0c9cd6u: goto P_0c0c9cd6;
case 0x0c0c9cd8u: goto P_0c0c9cd8;
case 0x0c0c9cdau: goto P_0c0c9cda;
case 0x0c0c9cdcu: goto P_0c0c9cdc;
case 0x0c0c9cdeu: goto P_0c0c9cde;
case 0x0c0c9ce0u: goto P_0c0c9ce0;
case 0x0c0c9ce2u: goto P_0c0c9ce2;
case 0x0c0c9ce4u: goto P_0c0c9ce4;
case 0x0c0ca326u: goto P_0c0ca326;
case 0x0c0ca328u: goto P_0c0ca328;
default: return vf3_matrix_family(target,s,ram);
}
P_0c085c28: /* original 2fe6, guest PC 0x0c085c28 */
if(!s->budget--) { s->failed_pc=0x0c085c28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c2a;
P_0c085c2a: /* original 6e43, guest PC 0x0c085c2a */
if(!s->budget--) { s->failed_pc=0x0c085c2au; return 0; }
r[14]=r[4];
goto P_0c085c2c;
P_0c085c2c: /* original 2fd6, guest PC 0x0c085c2c */
if(!s->budget--) { s->failed_pc=0x0c085c2cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c2e;
P_0c085c2e: /* original 2fc6, guest PC 0x0c085c2e */
if(!s->budget--) { s->failed_pc=0x0c085c2eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c30;
P_0c085c30: /* original 2fb6, guest PC 0x0c085c30 */
if(!s->budget--) { s->failed_pc=0x0c085c30u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c32;
P_0c085c32: /* original 2fa6, guest PC 0x0c085c32 */
if(!s->budget--) { s->failed_pc=0x0c085c32u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c34;
P_0c085c34: /* original 2f96, guest PC 0x0c085c34 */
if(!s->budget--) { s->failed_pc=0x0c085c34u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c36;
P_0c085c36: /* original 2f86, guest PC 0x0c085c36 */
if(!s->budget--) { s->failed_pc=0x0c085c36u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c085c38;
P_0c085c38: /* original 4f22, guest PC 0x0c085c38 */
if(!s->budget--) { s->failed_pc=0x0c085c38u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c085c3a;
P_0c085c3a: /* original db13, guest PC 0x0c085c3a */
if(!s->budget--) { s->failed_pc=0x0c085c3au; return 0; }
r[11]=read(ram,0x0c085c88u,4);
goto P_0c085c3c;
P_0c085c3c: /* original d313, guest PC 0x0c085c3c */
if(!s->budget--) { s->failed_pc=0x0c085c3cu; return 0; }
r[3]=read(ram,0x0c085c8cu,4);
goto P_0c085c3e;
P_0c085c3e: /* original 430b, guest PC 0x0c085c3e */
if(!s->budget--) { s->failed_pc=0x0c085c3eu; return 0; }
target=r[3];
r[16]=code_base|0x0c085c42u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085c42u) { target=s->pc; goto dispatch; }
goto P_0c085c42;
P_0c085c40: /* original e400, guest PC 0x0c085c40 */
if(!s->budget--) { s->failed_pc=0x0c085c40u; return 0; }
r[4]=0x00000000u;
goto P_0c085c42;
P_0c085c42: /* original d213, guest PC 0x0c085c42 */
if(!s->budget--) { s->failed_pc=0x0c085c42u; return 0; }
r[2]=read(ram,0x0c085c90u,4);
goto P_0c085c44;
P_0c085c44: /* original 420b, guest PC 0x0c085c44 */
if(!s->budget--) { s->failed_pc=0x0c085c44u; return 0; }
target=r[2];
r[16]=code_base|0x0c085c48u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085c48u) { target=s->pc; goto dispatch; }
goto P_0c085c48;
P_0c085c46: /* original 0009, guest PC 0x0c085c46 */
if(!s->budget--) { s->failed_pc=0x0c085c46u; return 0; }
goto P_0c085c48;
P_0c085c48: /* original da14, guest PC 0x0c085c48 */
if(!s->budget--) { s->failed_pc=0x0c085c48u; return 0; }
r[10]=read(ram,0x0c085c9cu,4);
goto P_0c085c4a;
P_0c085c4a: /* original ed08, guest PC 0x0c085c4a */
if(!s->budget--) { s->failed_pc=0x0c085c4au; return 0; }
r[13]=0x00000008u;
goto P_0c085c4c;
P_0c085c4c: /* original d912, guest PC 0x0c085c4c */
if(!s->budget--) { s->failed_pc=0x0c085c4cu; return 0; }
r[9]=read(ram,0x0c085c98u,4);
goto P_0c085c4e;
P_0c085c4e: /* original d811, guest PC 0x0c085c4e */
if(!s->budget--) { s->failed_pc=0x0c085c4eu; return 0; }
r[8]=read(ram,0x0c085c94u,4);
goto P_0c085c50;
P_0c085c50: /* original 60e1, guest PC 0x0c085c50 */
if(!s->budget--) { s->failed_pc=0x0c085c50u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[0]=tmp;
goto P_0c085c52;
P_0c085c52: /* original 64b3, guest PC 0x0c085c52 */
if(!s->budget--) { s->failed_pc=0x0c085c52u; return 0; }
r[4]=r[11];
goto P_0c085c54;
P_0c085c54: /* original 4000, guest PC 0x0c085c54 */
if(!s->budget--) { s->failed_pc=0x0c085c54u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c085c56;
P_0c085c56: /* original 0cad, guest PC 0x0c085c56 */
if(!s->budget--) { s->failed_pc=0x0c085c56u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+r[0],2);
goto P_0c085c58;
P_0c085c58: /* original 490b, guest PC 0x0c085c58 */
if(!s->budget--) { s->failed_pc=0x0c085c58u; return 0; }
target=r[9];
r[16]=code_base|0x0c085c5cu;
r[11]+=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085c5cu) { target=s->pc; goto dispatch; }
goto P_0c085c5c;
P_0c085c5a: /* original 7b0c, guest PC 0x0c085c5a */
if(!s->budget--) { s->failed_pc=0x0c085c5au; return 0; }
r[11]+=0x0000000cu;
goto P_0c085c5c;
P_0c085c5c: /* original 480b, guest PC 0x0c085c5c */
if(!s->budget--) { s->failed_pc=0x0c085c5cu; return 0; }
target=r[8];
r[16]=code_base|0x0c085c60u;
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c085c60u) { target=s->pc; goto dispatch; }
goto P_0c085c60;
P_0c085c5e: /* original 64cf, guest PC 0x0c085c5e */
if(!s->budget--) { s->failed_pc=0x0c085c5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[12];
goto P_0c085c60;
P_0c085c60: /* original 4d10, guest PC 0x0c085c60 */
if(!s->budget--) { s->failed_pc=0x0c085c60u; return 0; }
--r[13];
r[17]=(r[17]&~1u)|((r[13]==0)!=0);
goto P_0c085c62;
P_0c085c62: /* original 8ff5, guest PC 0x0c085c62 */
if(!s->budget--) { s->failed_pc=0x0c085c62u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000004u;
if(!cond) { goto P_0c085c50; }
goto P_0c085c66;
P_0c085c64: /* original 7e04, guest PC 0x0c085c64 */
if(!s->budget--) { s->failed_pc=0x0c085c64u; return 0; }
r[14]+=0x00000004u;
goto P_0c085c66;
P_0c085c66: /* original 4f26, guest PC 0x0c085c66 */
if(!s->budget--) { s->failed_pc=0x0c085c66u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c085c68;
P_0c085c68: /* original d20d, guest PC 0x0c085c68 */
if(!s->budget--) { s->failed_pc=0x0c085c68u; return 0; }
r[2]=read(ram,0x0c085ca0u,4);
goto P_0c085c6a;
P_0c085c6a: /* original e401, guest PC 0x0c085c6a */
if(!s->budget--) { s->failed_pc=0x0c085c6au; return 0; }
r[4]=0x00000001u;
goto P_0c085c6c;
P_0c085c6c: /* original 68f6, guest PC 0x0c085c6c */
if(!s->budget--) { s->failed_pc=0x0c085c6cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c085c6e;
P_0c085c6e: /* original 69f6, guest PC 0x0c085c6e */
if(!s->budget--) { s->failed_pc=0x0c085c6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c085c70;
P_0c085c70: /* original 6af6, guest PC 0x0c085c70 */
if(!s->budget--) { s->failed_pc=0x0c085c70u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c085c72;
P_0c085c72: /* original 6bf6, guest PC 0x0c085c72 */
if(!s->budget--) { s->failed_pc=0x0c085c72u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c085c74;
P_0c085c74: /* original 6cf6, guest PC 0x0c085c74 */
if(!s->budget--) { s->failed_pc=0x0c085c74u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c085c76;
P_0c085c76: /* original 6df6, guest PC 0x0c085c76 */
if(!s->budget--) { s->failed_pc=0x0c085c76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c085c78;
P_0c085c78: /* original 422b, guest PC 0x0c085c78 */
if(!s->budget--) { s->failed_pc=0x0c085c78u; return 0; }
target=r[2];
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
P_0c085c7a: /* original 6ef6, guest PC 0x0c085c7a */
if(!s->budget--) { s->failed_pc=0x0c085c7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c085c7cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c085c7cu; return 0; } return 1;
P_0c0955b0: /* original 4f22, guest PC 0x0c0955b0 */
if(!s->budget--) { s->failed_pc=0x0c0955b0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0955b2;
P_0c0955b2: /* original 7ff0, guest PC 0x0c0955b2 */
if(!s->budget--) { s->failed_pc=0x0c0955b2u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0955b4;
P_0c0955b4: /* original 1f42, guest PC 0x0c0955b4 */
if(!s->budget--) { s->failed_pc=0x0c0955b4u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c0955b6;
P_0c0955b6: /* original 1f51, guest PC 0x0c0955b6 */
if(!s->budget--) { s->failed_pc=0x0c0955b6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c0955b8;
P_0c0955b8: /* original 2f62, guest PC 0x0c0955b8 */
if(!s->budget--) { s->failed_pc=0x0c0955b8u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0955ba;
P_0c0955ba: /* original 1f73, guest PC 0x0c0955ba */
if(!s->budget--) { s->failed_pc=0x0c0955bau; return 0; }
write(ram,r[15]+12,r[7],4);
goto P_0c0955bc;
P_0c0955bc: /* original d34e, guest PC 0x0c0955bc */
if(!s->budget--) { s->failed_pc=0x0c0955bcu; return 0; }
r[3]=read(ram,0x0c0956f8u,4);
goto P_0c0955be;
P_0c0955be: /* original 430b, guest PC 0x0c0955be */
if(!s->budget--) { s->failed_pc=0x0c0955beu; return 0; }
target=r[3];
r[16]=code_base|0x0c0955c2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c2u) { target=s->pc; goto dispatch; }
goto P_0c0955c2;
P_0c0955c0: /* original e400, guest PC 0x0c0955c0 */
if(!s->budget--) { s->failed_pc=0x0c0955c0u; return 0; }
r[4]=0x00000000u;
goto P_0c0955c2;
P_0c0955c2: /* original d24e, guest PC 0x0c0955c2 */
if(!s->budget--) { s->failed_pc=0x0c0955c2u; return 0; }
r[2]=read(ram,0x0c0956fcu,4);
goto P_0c0955c4;
P_0c0955c4: /* original 420b, guest PC 0x0c0955c4 */
if(!s->budget--) { s->failed_pc=0x0c0955c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0955c8u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955c8u) { target=s->pc; goto dispatch; }
goto P_0c0955c8;
P_0c0955c6: /* original 0009, guest PC 0x0c0955c6 */
if(!s->budget--) { s->failed_pc=0x0c0955c6u; return 0; }
goto P_0c0955c8;
P_0c0955c8: /* original d34d, guest PC 0x0c0955c8 */
if(!s->budget--) { s->failed_pc=0x0c0955c8u; return 0; }
r[3]=read(ram,0x0c095700u,4);
goto P_0c0955ca;
P_0c0955ca: /* original 430b, guest PC 0x0c0955ca */
if(!s->budget--) { s->failed_pc=0x0c0955cau; return 0; }
target=r[3];
r[16]=code_base|0x0c0955ceu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955ceu) { target=s->pc; goto dispatch; }
goto P_0c0955ce;
P_0c0955cc: /* original 54f6, guest PC 0x0c0955cc */
if(!s->budget--) { s->failed_pc=0x0c0955ccu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c0955ce;
P_0c0955ce: /* original d34d, guest PC 0x0c0955ce */
if(!s->budget--) { s->failed_pc=0x0c0955ceu; return 0; }
r[3]=read(ram,0x0c095704u,4);
goto P_0c0955d0;
P_0c0955d0: /* original 430b, guest PC 0x0c0955d0 */
if(!s->budget--) { s->failed_pc=0x0c0955d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955d4u;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955d4u) { target=s->pc; goto dispatch; }
goto P_0c0955d4;
P_0c0955d2: /* original 54f5, guest PC 0x0c0955d2 */
if(!s->budget--) { s->failed_pc=0x0c0955d2u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0955d4;
P_0c0955d4: /* original d34c, guest PC 0x0c0955d4 */
if(!s->budget--) { s->failed_pc=0x0c0955d4u; return 0; }
r[3]=read(ram,0x0c095708u,4);
goto P_0c0955d6;
P_0c0955d6: /* original 430b, guest PC 0x0c0955d6 */
if(!s->budget--) { s->failed_pc=0x0c0955d6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0955dau;
r[4]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955dau) { target=s->pc; goto dispatch; }
goto P_0c0955da;
P_0c0955d8: /* original 54f3, guest PC 0x0c0955d8 */
if(!s->budget--) { s->failed_pc=0x0c0955d8u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c0955da;
P_0c0955da: /* original d24c, guest PC 0x0c0955da */
if(!s->budget--) { s->failed_pc=0x0c0955dau; return 0; }
r[2]=read(ram,0x0c09570cu,4);
goto P_0c0955dc;
P_0c0955dc: /* original 420b, guest PC 0x0c0955dc */
if(!s->budget--) { s->failed_pc=0x0c0955dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0955e0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0955e0u) { target=s->pc; goto dispatch; }
goto P_0c0955e0;
P_0c0955de: /* original e400, guest PC 0x0c0955de */
if(!s->budget--) { s->failed_pc=0x0c0955deu; return 0; }
r[4]=0x00000000u;
goto P_0c0955e0;
P_0c0955e0: /* original 6403, guest PC 0x0c0955e0 */
if(!s->budget--) { s->failed_pc=0x0c0955e0u; return 0; }
r[4]=r[0];
goto P_0c0955e2;
P_0c0955e2: /* original e020, guest PC 0x0c0955e2 */
if(!s->budget--) { s->failed_pc=0x0c0955e2u; return 0; }
r[0]=0x00000020u;
goto P_0c0955e4;
P_0c0955e4: /* original f346, guest PC 0x0c0955e4 */
if(!s->budget--) { s->failed_pc=0x0c0955e4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955e6;
P_0c0955e6: /* original e024, guest PC 0x0c0955e6 */
if(!s->budget--) { s->failed_pc=0x0c0955e6u; return 0; }
r[0]=0x00000024u;
goto P_0c0955e8;
P_0c0955e8: /* original 53f2, guest PC 0x0c0955e8 */
if(!s->budget--) { s->failed_pc=0x0c0955e8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0955ea;
P_0c0955ea: /* original f33a, guest PC 0x0c0955ea */
if(!s->budget--) { s->failed_pc=0x0c0955eau; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955ec;
P_0c0955ec: /* original f346, guest PC 0x0c0955ec */
if(!s->budget--) { s->failed_pc=0x0c0955ecu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955ee;
P_0c0955ee: /* original e028, guest PC 0x0c0955ee */
if(!s->budget--) { s->failed_pc=0x0c0955eeu; return 0; }
r[0]=0x00000028u;
goto P_0c0955f0;
P_0c0955f0: /* original 53f1, guest PC 0x0c0955f0 */
if(!s->budget--) { s->failed_pc=0x0c0955f0u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0955f2;
P_0c0955f2: /* original f33a, guest PC 0x0c0955f2 */
if(!s->budget--) { s->failed_pc=0x0c0955f2u; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955f4;
P_0c0955f4: /* original f346, guest PC 0x0c0955f4 */
if(!s->budget--) { s->failed_pc=0x0c0955f4u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0955f6;
P_0c0955f6: /* original e401, guest PC 0x0c0955f6 */
if(!s->budget--) { s->failed_pc=0x0c0955f6u; return 0; }
r[4]=0x00000001u;
goto P_0c0955f8;
P_0c0955f8: /* original 63f2, guest PC 0x0c0955f8 */
if(!s->budget--) { s->failed_pc=0x0c0955f8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0955fa;
P_0c0955fa: /* original 7f10, guest PC 0x0c0955fa */
if(!s->budget--) { s->failed_pc=0x0c0955fau; return 0; }
r[15]+=0x00000010u;
goto P_0c0955fc;
P_0c0955fc: /* original f33a, guest PC 0x0c0955fc */
if(!s->budget--) { s->failed_pc=0x0c0955fcu; return 0; }
vf3_matrix_store(s,ram,3,r[3]);
goto P_0c0955fe;
P_0c0955fe: /* original d344, guest PC 0x0c0955fe */
if(!s->budget--) { s->failed_pc=0x0c0955feu; return 0; }
r[3]=read(ram,0x0c095710u,4);
goto P_0c095600;
P_0c095600: /* original 432b, guest PC 0x0c095600 */
if(!s->budget--) { s->failed_pc=0x0c095600u; return 0; }
target=r[3];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c095602: /* original 4f26, guest PC 0x0c095602 */
if(!s->budget--) { s->failed_pc=0x0c095602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c095604u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c095604u; return 0; } return 1;
P_0c0a7250: /* original 4615, guest PC 0x0c0a7250 */
if(!s->budget--) { s->failed_pc=0x0c0a7250u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0a7252;
P_0c0a7252: /* original 8b05, guest PC 0x0c0a7252 */
if(!s->budget--) { s->failed_pc=0x0c0a7252u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a7260; }
goto P_0c0a7254;
P_0c0a7254: /* original 6756, guest PC 0x0c0a7254 */
if(!s->budget--) { s->failed_pc=0x0c0a7254u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[7]=tmp;
goto P_0c0a7256;
P_0c0a7256: /* original 76ff, guest PC 0x0c0a7256 */
if(!s->budget--) { s->failed_pc=0x0c0a7256u; return 0; }
r[6]+=0xffffffffu;
goto P_0c0a7258;
P_0c0a7258: /* original 4615, guest PC 0x0c0a7258 */
if(!s->budget--) { s->failed_pc=0x0c0a7258u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c0a725a;
P_0c0a725a: /* original 2472, guest PC 0x0c0a725a */
if(!s->budget--) { s->failed_pc=0x0c0a725au; return 0; }
write(ram,r[4],r[7],4);
goto P_0c0a725c;
P_0c0a725c: /* original 8dfa, guest PC 0x0c0a725c */
if(!s->budget--) { s->failed_pc=0x0c0a725cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(cond) { goto P_0c0a7254; }
goto P_0c0a7260;
P_0c0a725e: /* original 7404, guest PC 0x0c0a725e */
if(!s->budget--) { s->failed_pc=0x0c0a725eu; return 0; }
r[4]+=0x00000004u;
goto P_0c0a7260;
P_0c0a7260: /* original 000b, guest PC 0x0c0a7260 */
if(!s->budget--) { s->failed_pc=0x0c0a7260u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a7262: /* original 0009, guest PC 0x0c0a7262 */
if(!s->budget--) { s->failed_pc=0x0c0a7262u; return 0; }
if(!vf3_matrix_family(0x0c0a7264u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7264u; return 0; } return 1;
P_0c0a7442: /* original d024, guest PC 0x0c0a7442 */
if(!s->budget--) { s->failed_pc=0x0c0a7442u; return 0; }
r[0]=read(ram,0x0c0a74d4u,4);
goto P_0c0a7444;
P_0c0a7444: /* original 7ffc, guest PC 0x0c0a7444 */
if(!s->budget--) { s->failed_pc=0x0c0a7444u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7446;
P_0c0a7446: /* original e635, guest PC 0x0c0a7446 */
if(!s->budget--) { s->failed_pc=0x0c0a7446u; return 0; }
r[6]=0x00000035u;
goto P_0c0a7448;
P_0c0a7448: /* original 6503, guest PC 0x0c0a7448 */
if(!s->budget--) { s->failed_pc=0x0c0a7448u; return 0; }
r[5]=r[0];
goto P_0c0a744a;
P_0c0a744a: /* original 2f02, guest PC 0x0c0a744a */
if(!s->budget--) { s->failed_pc=0x0c0a744au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0a744c;
P_0c0a744c: /* original af00, guest PC 0x0c0a744c */
if(!s->budget--) { s->failed_pc=0x0c0a744cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0a7250;
P_0c0a744e: /* original 7f04, guest PC 0x0c0a744e */
if(!s->budget--) { s->failed_pc=0x0c0a744eu; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0a7450u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7450u; return 0; } return 1;
P_0c0c9cc0: /* original 9031, guest PC 0x0c0c9cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d26u,2);
goto P_0c0c9cc2;
P_0c0c9cc2: /* original d41c, guest PC 0x0c0c9cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc2u; return 0; }
r[4]=read(ram,0x0c0c9d34u,4);
goto P_0c0c9cc4;
P_0c0c9cc4: /* original 4f12, guest PC 0x0c0c9cc4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c9cc6;
P_0c0c9cc6: /* original 034e, guest PC 0x0c0c9cc6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc6u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c9cc8;
P_0c0c9cc8: /* original 70fc, guest PC 0x0c0c9cc8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cc8u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0c9cca;
P_0c0c9cca: /* original 024e, guest PC 0x0c0c9cca */
if(!s->budget--) { s->failed_pc=0x0c0c9ccau; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0c9ccc;
P_0c0c9ccc: /* original 7008, guest PC 0x0c0c9ccc */
if(!s->budget--) { s->failed_pc=0x0c0c9cccu; return 0; }
r[0]+=0x00000008u;
goto P_0c0c9cce;
P_0c0c9cce: /* original 014d, guest PC 0x0c0c9cce */
if(!s->budget--) { s->failed_pc=0x0c0c9cceu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0c9cd0;
P_0c0c9cd0: /* original 70f8, guest PC 0x0c0c9cd0 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd0u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0c9cd2;
P_0c0c9cd2: /* original 0237, guest PC 0x0c0c9cd2 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd2u; return 0; }
r[19]=r[2]*r[3];
goto P_0c0c9cd4;
P_0c0c9cd4: /* original 051a, guest PC 0x0c0c9cd4 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd4u; return 0; }
r[5]=r[19];
goto P_0c0c9cd6;
P_0c0c9cd6: /* original 351c, guest PC 0x0c0c9cd6 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd6u; return 0; }
r[5]+=r[1];
goto P_0c0c9cd8;
P_0c0c9cd8: /* original 0456, guest PC 0x0c0c9cd8 */
if(!s->budget--) { s->failed_pc=0x0c0c9cd8u; return 0; }
write(ram,r[4]+r[0],r[5],4);
goto P_0c0c9cda;
P_0c0c9cda: /* original 4529, guest PC 0x0c0c9cda */
if(!s->budget--) { s->failed_pc=0x0c0c9cdau; return 0; }
r[5]>>=16;
goto P_0c0c9cdc;
P_0c0c9cdc: /* original 9421, guest PC 0x0c0c9cdc */
if(!s->budget--) { s->failed_pc=0x0c0c9cdcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9d22u,2);
goto P_0c0c9cde;
P_0c0c9cde: /* original 2459, guest PC 0x0c0c9cde */
if(!s->budget--) { s->failed_pc=0x0c0c9cdeu; return 0; }
r[4]&=r[5];
goto P_0c0c9ce0;
P_0c0c9ce0: /* original 6043, guest PC 0x0c0c9ce0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce0u; return 0; }
r[0]=r[4];
goto P_0c0c9ce2;
P_0c0c9ce2: /* original 000b, guest PC 0x0c0c9ce2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce2u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c0c9ce4: /* original 4f16, guest PC 0x0c0c9ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ce4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0c9ce6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c9ce6u; return 0; } return 1;
P_0c0ca326: /* original 000b, guest PC 0x0c0ca326 */
if(!s->budget--) { s->failed_pc=0x0c0ca326u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ca328: /* original 0009, guest PC 0x0c0ca328 */
if(!s->budget--) { s->failed_pc=0x0c0ca328u; return 0; }
if(!vf3_matrix_family(0x0c0ca32au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ca32au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
