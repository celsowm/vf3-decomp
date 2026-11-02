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
int vf3_away_batch14_adapter_26(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a7750u: goto P_0c0a7750;
case 0x0c0a7752u: goto P_0c0a7752;
case 0x0c0a7754u: goto P_0c0a7754;
case 0x0c0a7756u: goto P_0c0a7756;
case 0x0c0a7758u: goto P_0c0a7758;
case 0x0c0a775au: goto P_0c0a775a;
case 0x0c0a775cu: goto P_0c0a775c;
case 0x0c0a775eu: goto P_0c0a775e;
case 0x0c0a7760u: goto P_0c0a7760;
case 0x0c0a7762u: goto P_0c0a7762;
case 0x0c0a7764u: goto P_0c0a7764;
case 0x0c0a7766u: goto P_0c0a7766;
case 0x0c0a7768u: goto P_0c0a7768;
case 0x0c0a776au: goto P_0c0a776a;
case 0x0c0a776cu: goto P_0c0a776c;
case 0x0c0a776eu: goto P_0c0a776e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a7750: /* original 4f22, guest PC 0x0c0a7750 */
if(!s->budget--) { s->failed_pc=0x0c0a7750u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a7752;
P_0c0a7752: /* original 7ffc, guest PC 0x0c0a7752 */
if(!s->budget--) { s->failed_pc=0x0c0a7752u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0a7754;
P_0c0a7754: /* original 2f42, guest PC 0x0c0a7754 */
if(!s->budget--) { s->failed_pc=0x0c0a7754u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a7756;
P_0c0a7756: /* original d333, guest PC 0x0c0a7756 */
if(!s->budget--) { s->failed_pc=0x0c0a7756u; return 0; }
r[3]=read(ram,0x0c0a7824u,4);
goto P_0c0a7758;
P_0c0a7758: /* original 430b, guest PC 0x0c0a7758 */
if(!s->budget--) { s->failed_pc=0x0c0a7758u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a775cu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a775cu) { target=s->pc; goto dispatch; }
goto P_0c0a775c;
P_0c0a775a: /* original e400, guest PC 0x0c0a775a */
if(!s->budget--) { s->failed_pc=0x0c0a775au; return 0; }
r[4]=0x00000000u;
goto P_0c0a775c;
P_0c0a775c: /* original d239, guest PC 0x0c0a775c */
if(!s->budget--) { s->failed_pc=0x0c0a775cu; return 0; }
r[2]=read(ram,0x0c0a7844u,4);
goto P_0c0a775e;
P_0c0a775e: /* original 420b, guest PC 0x0c0a775e */
if(!s->budget--) { s->failed_pc=0x0c0a775eu; return 0; }
target=r[2];
r[16]=code_base|0x0c0a7762u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7762u) { target=s->pc; goto dispatch; }
goto P_0c0a7762;
P_0c0a7760: /* original 0009, guest PC 0x0c0a7760 */
if(!s->budget--) { s->failed_pc=0x0c0a7760u; return 0; }
goto P_0c0a7762;
P_0c0a7762: /* original bf7e, guest PC 0x0c0a7762 */
if(!s->budget--) { s->failed_pc=0x0c0a7762u; return 0; }
target=code_base|0x0c0a7662u; r[16]=code_base|0x0c0a7766u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a7766u) { target=s->pc; goto dispatch; }
goto P_0c0a7766;
P_0c0a7764: /* original 64f2, guest PC 0x0c0a7764 */
if(!s->budget--) { s->failed_pc=0x0c0a7764u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0a7766;
P_0c0a7766: /* original d236, guest PC 0x0c0a7766 */
if(!s->budget--) { s->failed_pc=0x0c0a7766u; return 0; }
r[2]=read(ram,0x0c0a7840u,4);
goto P_0c0a7768;
P_0c0a7768: /* original 7f04, guest PC 0x0c0a7768 */
if(!s->budget--) { s->failed_pc=0x0c0a7768u; return 0; }
r[15]+=0x00000004u;
goto P_0c0a776a;
P_0c0a776a: /* original e401, guest PC 0x0c0a776a */
if(!s->budget--) { s->failed_pc=0x0c0a776au; return 0; }
r[4]=0x00000001u;
goto P_0c0a776c;
P_0c0a776c: /* original 422b, guest PC 0x0c0a776c */
if(!s->budget--) { s->failed_pc=0x0c0a776cu; return 0; }
target=r[2];
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
P_0c0a776e: /* original 4f26, guest PC 0x0c0a776e */
if(!s->budget--) { s->failed_pc=0x0c0a776eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c0a7770u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a7770u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
