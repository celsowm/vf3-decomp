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
int vf3_away_batch50_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c66ccu: goto P_0c0c66cc;
case 0x0c0c66ceu: goto P_0c0c66ce;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c66cc: /* original 000b, guest PC 0x0c0c66cc */
if(!s->budget--) { s->failed_pc=0x0c0c66ccu; return 0; }
target=r[16];
vf3_matrix_load(s,ram,0,r[4]);
s->pc=target; return ram->oob==0;
P_0c0c66ce: /* original f048, guest PC 0x0c0c66ce */
if(!s->budget--) { s->failed_pc=0x0c0c66ceu; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
if(!vf3_matrix_family(0x0c0c66d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0c66d0u; return 0; } return 1;
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
unsupported: s->failed_pc=target; return 0;
}
