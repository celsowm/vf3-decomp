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
int vf3_away_batch27_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c035a20u: goto P_0c035a20;
case 0x0c035a22u: goto P_0c035a22;
case 0x0c035a24u: goto P_0c035a24;
case 0x0c035a26u: goto P_0c035a26;
case 0x0c035a28u: goto P_0c035a28;
case 0x0c035a2au: goto P_0c035a2a;
case 0x0c035a2cu: goto P_0c035a2c;
case 0x0c035a2eu: goto P_0c035a2e;
case 0x0c035a30u: goto P_0c035a30;
case 0x0c035a32u: goto P_0c035a32;
case 0x0c035a34u: goto P_0c035a34;
case 0x0c035a36u: goto P_0c035a36;
case 0x0c035b1cu: goto P_0c035b1c;
case 0x0c035b1eu: goto P_0c035b1e;
case 0x0c035b20u: goto P_0c035b20;
case 0x0c035b22u: goto P_0c035b22;
case 0x0c035b24u: goto P_0c035b24;
case 0x0c035b26u: goto P_0c035b26;
case 0x0c035b28u: goto P_0c035b28;
case 0x0c035b2au: goto P_0c035b2a;
case 0x0c035b2cu: goto P_0c035b2c;
case 0x0c035b2eu: goto P_0c035b2e;
case 0x0c035b30u: goto P_0c035b30;
case 0x0c035b32u: goto P_0c035b32;
case 0x0c035b34u: goto P_0c035b34;
case 0x0c035b36u: goto P_0c035b36;
case 0x0c035b38u: goto P_0c035b38;
case 0x0c035b3au: goto P_0c035b3a;
case 0x0c035b3cu: goto P_0c035b3c;
case 0x0c035b3eu: goto P_0c035b3e;
case 0x0c035b40u: goto P_0c035b40;
case 0x0c035b42u: goto P_0c035b42;
case 0x0c035b44u: goto P_0c035b44;
case 0x0c035b46u: goto P_0c035b46;
default: return vf3_matrix_family(target,s,ram);
}
P_0c035a20: /* original 2448, guest PC 0x0c035a20 */
if(!s->budget--) { s->failed_pc=0x0c035a20u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c035a22;
P_0c035a22: /* original 8903, guest PC 0x0c035a22 */
if(!s->budget--) { s->failed_pc=0x0c035a22u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035a2c; }
goto P_0c035a24;
P_0c035a24: /* original e048, guest PC 0x0c035a24 */
if(!s->budget--) { s->failed_pc=0x0c035a24u; return 0; }
r[0]=0x00000048u;
goto P_0c035a26;
P_0c035a26: /* original 024d, guest PC 0x0c035a26 */
if(!s->budget--) { s->failed_pc=0x0c035a26u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c035a28;
P_0c035a28: /* original 2228, guest PC 0x0c035a28 */
if(!s->budget--) { s->failed_pc=0x0c035a28u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c035a2a;
P_0c035a2a: /* original 8b01, guest PC 0x0c035a2a */
if(!s->budget--) { s->failed_pc=0x0c035a2au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c035a30; }
goto P_0c035a2c;
P_0c035a2c: /* original 000b, guest PC 0x0c035a2c */
if(!s->budget--) { s->failed_pc=0x0c035a2cu; return 0; }
target=r[16];
r[0]=0xfffffff6u;
s->pc=target; return ram->oob==0;
P_0c035a2e: /* original e0f6, guest PC 0x0c035a2e */
if(!s->budget--) { s->failed_pc=0x0c035a2eu; return 0; }
r[0]=0xfffffff6u;
goto P_0c035a30;
P_0c035a30: /* original e04c, guest PC 0x0c035a30 */
if(!s->budget--) { s->failed_pc=0x0c035a30u; return 0; }
r[0]=0x0000004cu;
goto P_0c035a32;
P_0c035a32: /* original 004d, guest PC 0x0c035a32 */
if(!s->budget--) { s->failed_pc=0x0c035a32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c035a34;
P_0c035a34: /* original 000b, guest PC 0x0c035a34 */
if(!s->budget--) { s->failed_pc=0x0c035a34u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c035a36: /* original 0009, guest PC 0x0c035a36 */
if(!s->budget--) { s->failed_pc=0x0c035a36u; return 0; }
if(!vf3_matrix_family(0x0c035a38u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035a38u; return 0; } return 1;
P_0c035b1c: /* original 2fe6, guest PC 0x0c035b1c */
if(!s->budget--) { s->failed_pc=0x0c035b1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035b1e;
P_0c035b1e: /* original d390, guest PC 0x0c035b1e */
if(!s->budget--) { s->failed_pc=0x0c035b1eu; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035b20;
P_0c035b20: /* original 6e32, guest PC 0x0c035b20 */
if(!s->budget--) { s->failed_pc=0x0c035b20u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c035b22;
P_0c035b22: /* original 2ee8, guest PC 0x0c035b22 */
if(!s->budget--) { s->failed_pc=0x0c035b22u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035b24;
P_0c035b24: /* original 8902, guest PC 0x0c035b24 */
if(!s->budget--) { s->failed_pc=0x0c035b24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035b2c; }
goto P_0c035b26;
P_0c035b26: /* original 50e7, guest PC 0x0c035b26 */
if(!s->budget--) { s->failed_pc=0x0c035b26u; return 0; }
r[0]=read(ram,r[14]+28,4);
goto P_0c035b28;
P_0c035b28: /* original 402b, guest PC 0x0c035b28 */
if(!s->budget--) { s->failed_pc=0x0c035b28u; return 0; }
target=r[0];
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
P_0c035b2a: /* original 6ef6, guest PC 0x0c035b2a */
if(!s->budget--) { s->failed_pc=0x0c035b2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035b2c;
P_0c035b2c: /* original e000, guest PC 0x0c035b2c */
if(!s->budget--) { s->failed_pc=0x0c035b2cu; return 0; }
r[0]=0x00000000u;
goto P_0c035b2e;
P_0c035b2e: /* original 000b, guest PC 0x0c035b2e */
if(!s->budget--) { s->failed_pc=0x0c035b2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035b30: /* original 6ef6, guest PC 0x0c035b30 */
if(!s->budget--) { s->failed_pc=0x0c035b30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035b32;
P_0c035b32: /* original 2fe6, guest PC 0x0c035b32 */
if(!s->budget--) { s->failed_pc=0x0c035b32u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c035b34;
P_0c035b34: /* original d38a, guest PC 0x0c035b34 */
if(!s->budget--) { s->failed_pc=0x0c035b34u; return 0; }
r[3]=read(ram,0x0c035d60u,4);
goto P_0c035b36;
P_0c035b36: /* original 6e32, guest PC 0x0c035b36 */
if(!s->budget--) { s->failed_pc=0x0c035b36u; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c035b38;
P_0c035b38: /* original 2ee8, guest PC 0x0c035b38 */
if(!s->budget--) { s->failed_pc=0x0c035b38u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c035b3a;
P_0c035b3a: /* original 8902, guest PC 0x0c035b3a */
if(!s->budget--) { s->failed_pc=0x0c035b3au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c035b42; }
goto P_0c035b3c;
P_0c035b3c: /* original 50e6, guest PC 0x0c035b3c */
if(!s->budget--) { s->failed_pc=0x0c035b3cu; return 0; }
r[0]=read(ram,r[14]+24,4);
goto P_0c035b3e;
P_0c035b3e: /* original 402b, guest PC 0x0c035b3e */
if(!s->budget--) { s->failed_pc=0x0c035b3eu; return 0; }
target=r[0];
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
P_0c035b40: /* original 6ef6, guest PC 0x0c035b40 */
if(!s->budget--) { s->failed_pc=0x0c035b40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c035b42;
P_0c035b42: /* original e000, guest PC 0x0c035b42 */
if(!s->budget--) { s->failed_pc=0x0c035b42u; return 0; }
r[0]=0x00000000u;
goto P_0c035b44;
P_0c035b44: /* original 000b, guest PC 0x0c035b44 */
if(!s->budget--) { s->failed_pc=0x0c035b44u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c035b46: /* original 6ef6, guest PC 0x0c035b46 */
if(!s->budget--) { s->failed_pc=0x0c035b46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c035b48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c035b48u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
