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
int vf3_away_batch100_adapter_29(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
