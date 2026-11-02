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
int vf3_away_batch184_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a1282u: goto P_0c0a1282;
case 0x0c0a1284u: goto P_0c0a1284;
case 0x0c0a1286u: goto P_0c0a1286;
case 0x0c0a1288u: goto P_0c0a1288;
case 0x0c0a128au: goto P_0c0a128a;
case 0x0c0a128cu: goto P_0c0a128c;
case 0x0c0a128eu: goto P_0c0a128e;
case 0x0c0a1290u: goto P_0c0a1290;
case 0x0c0a1292u: goto P_0c0a1292;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a1282: /* original 6043, guest PC 0x0c0a1282 */
if(!s->budget--) { s->failed_pc=0x0c0a1282u; return 0; }
r[0]=r[4];
goto P_0c0a1284;
P_0c0a1284: /* original 4008, guest PC 0x0c0a1284 */
if(!s->budget--) { s->failed_pc=0x0c0a1284u; return 0; }
r[0]<<=2;
goto P_0c0a1286;
P_0c0a1286: /* original 6343, guest PC 0x0c0a1286 */
if(!s->budget--) { s->failed_pc=0x0c0a1286u; return 0; }
r[3]=r[4];
goto P_0c0a1288;
P_0c0a1288: /* original 303c, guest PC 0x0c0a1288 */
if(!s->budget--) { s->failed_pc=0x0c0a1288u; return 0; }
r[0]+=r[3];
goto P_0c0a128a;
P_0c0a128a: /* original d21d, guest PC 0x0c0a128a */
if(!s->budget--) { s->failed_pc=0x0c0a128au; return 0; }
r[2]=read(ram,0x0c0a1300u,4);
goto P_0c0a128c;
P_0c0a128c: /* original 4008, guest PC 0x0c0a128c */
if(!s->budget--) { s->failed_pc=0x0c0a128cu; return 0; }
r[0]<<=2;
goto P_0c0a128e;
P_0c0a128e: /* original 600e, guest PC 0x0c0a128e */
if(!s->budget--) { s->failed_pc=0x0c0a128eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)r[0];
goto P_0c0a1290;
P_0c0a1290: /* original 000b, guest PC 0x0c0a1290 */
if(!s->budget--) { s->failed_pc=0x0c0a1290u; return 0; }
target=r[16];
r[0]+=r[2];
s->pc=target; return ram->oob==0;
P_0c0a1292: /* original 302c, guest PC 0x0c0a1292 */
if(!s->budget--) { s->failed_pc=0x0c0a1292u; return 0; }
r[0]+=r[2];
if(!vf3_matrix_family(0x0c0a1294u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a1294u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
