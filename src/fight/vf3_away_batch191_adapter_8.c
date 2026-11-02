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
int vf3_away_batch191_adapter_8(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a65c8u: goto P_0c0a65c8;
case 0x0c0a65cau: goto P_0c0a65ca;
case 0x0c0a65ccu: goto P_0c0a65cc;
case 0x0c0a65ceu: goto P_0c0a65ce;
case 0x0c0a65d0u: goto P_0c0a65d0;
case 0x0c0a65d2u: goto P_0c0a65d2;
case 0x0c0a65d4u: goto P_0c0a65d4;
case 0x0c0a65d6u: goto P_0c0a65d6;
case 0x0c0a65d8u: goto P_0c0a65d8;
case 0x0c0a65dau: goto P_0c0a65da;
case 0x0c0a65dcu: goto P_0c0a65dc;
case 0x0c0a65deu: goto P_0c0a65de;
case 0x0c0a65e0u: goto P_0c0a65e0;
case 0x0c0a65e2u: goto P_0c0a65e2;
case 0x0c0a65e4u: goto P_0c0a65e4;
case 0x0c0a65e6u: goto P_0c0a65e6;
case 0x0c0a65e8u: goto P_0c0a65e8;
case 0x0c0a65eau: goto P_0c0a65ea;
case 0x0c0a65ecu: goto P_0c0a65ec;
case 0x0c0a65eeu: goto P_0c0a65ee;
case 0x0c0a65f0u: goto P_0c0a65f0;
case 0x0c0a65f2u: goto P_0c0a65f2;
case 0x0c0a65f4u: goto P_0c0a65f4;
case 0x0c0a65f6u: goto P_0c0a65f6;
case 0x0c0a65f8u: goto P_0c0a65f8;
case 0x0c0a65fau: goto P_0c0a65fa;
case 0x0c0a65fcu: goto P_0c0a65fc;
case 0x0c0a65feu: goto P_0c0a65fe;
case 0x0c0a6600u: goto P_0c0a6600;
case 0x0c0a6602u: goto P_0c0a6602;
case 0x0c0a6604u: goto P_0c0a6604;
case 0x0c0a6606u: goto P_0c0a6606;
case 0x0c0a6608u: goto P_0c0a6608;
case 0x0c0a660au: goto P_0c0a660a;
case 0x0c0a660cu: goto P_0c0a660c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a65c8: /* original 2fe6, guest PC 0x0c0a65c8 */
if(!s->budget--) { s->failed_pc=0x0c0a65c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65ca;
P_0c0a65ca: /* original 6e53, guest PC 0x0c0a65ca */
if(!s->budget--) { s->failed_pc=0x0c0a65cau; return 0; }
r[14]=r[5];
goto P_0c0a65cc;
P_0c0a65cc: /* original 2fd6, guest PC 0x0c0a65cc */
if(!s->budget--) { s->failed_pc=0x0c0a65ccu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65ce;
P_0c0a65ce: /* original 2fc6, guest PC 0x0c0a65ce */
if(!s->budget--) { s->failed_pc=0x0c0a65ceu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65d0;
P_0c0a65d0: /* original 6c63, guest PC 0x0c0a65d0 */
if(!s->budget--) { s->failed_pc=0x0c0a65d0u; return 0; }
r[12]=r[6];
goto P_0c0a65d2;
P_0c0a65d2: /* original 2fb6, guest PC 0x0c0a65d2 */
if(!s->budget--) { s->failed_pc=0x0c0a65d2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a65d4;
P_0c0a65d4: /* original 4f22, guest PC 0x0c0a65d4 */
if(!s->budget--) { s->failed_pc=0x0c0a65d4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a65d6;
P_0c0a65d6: /* original 7ff0, guest PC 0x0c0a65d6 */
if(!s->budget--) { s->failed_pc=0x0c0a65d6u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a65d8;
P_0c0a65d8: /* original 2f42, guest PC 0x0c0a65d8 */
if(!s->budget--) { s->failed_pc=0x0c0a65d8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0a65da;
P_0c0a65da: /* original d312, guest PC 0x0c0a65da */
if(!s->budget--) { s->failed_pc=0x0c0a65dau; return 0; }
r[3]=read(ram,0x0c0a6624u,4);
goto P_0c0a65dc;
P_0c0a65dc: /* original 430b, guest PC 0x0c0a65dc */
if(!s->budget--) { s->failed_pc=0x0c0a65dcu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a65e0u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a65e0u) { target=s->pc; goto dispatch; }
goto P_0c0a65e0;
P_0c0a65de: /* original 7410, guest PC 0x0c0a65de */
if(!s->budget--) { s->failed_pc=0x0c0a65deu; return 0; }
r[4]+=0x00000010u;
goto P_0c0a65e0;
P_0c0a65e0: /* original 64e2, guest PC 0x0c0a65e0 */
if(!s->budget--) { s->failed_pc=0x0c0a65e0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0a65e2;
P_0c0a65e2: /* original 6be3, guest PC 0x0c0a65e2 */
if(!s->budget--) { s->failed_pc=0x0c0a65e2u; return 0; }
r[11]=r[14];
goto P_0c0a65e4;
P_0c0a65e4: /* original 6ec3, guest PC 0x0c0a65e4 */
if(!s->budget--) { s->failed_pc=0x0c0a65e4u; return 0; }
r[14]=r[12];
goto P_0c0a65e6;
P_0c0a65e6: /* original 7e04, guest PC 0x0c0a65e6 */
if(!s->budget--) { s->failed_pc=0x0c0a65e6u; return 0; }
r[14]+=0x00000004u;
goto P_0c0a65e8;
P_0c0a65e8: /* original 6d4c, guest PC 0x0c0a65e8 */
if(!s->budget--) { s->failed_pc=0x0c0a65e8u; return 0; }
r[13]=r[4]&255u;
goto P_0c0a65ea;
P_0c0a65ea: /* original 2cd2, guest PC 0x0c0a65ea */
if(!s->budget--) { s->failed_pc=0x0c0a65eau; return 0; }
write(ram,r[12],r[13],4);
goto P_0c0a65ec;
P_0c0a65ec: /* original 7b04, guest PC 0x0c0a65ec */
if(!s->budget--) { s->failed_pc=0x0c0a65ecu; return 0; }
r[11]+=0x00000004u;
goto P_0c0a65ee;
P_0c0a65ee: /* original d20e, guest PC 0x0c0a65ee */
if(!s->budget--) { s->failed_pc=0x0c0a65eeu; return 0; }
r[2]=read(ram,0x0c0a6628u,4);
goto P_0c0a65f0;
P_0c0a65f0: /* original 65e3, guest PC 0x0c0a65f0 */
if(!s->budget--) { s->failed_pc=0x0c0a65f0u; return 0; }
r[5]=r[14];
goto P_0c0a65f2;
P_0c0a65f2: /* original 420b, guest PC 0x0c0a65f2 */
if(!s->budget--) { s->failed_pc=0x0c0a65f2u; return 0; }
target=r[2];
r[16]=code_base|0x0c0a65f6u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a65f6u) { target=s->pc; goto dispatch; }
goto P_0c0a65f6;
P_0c0a65f4: /* original 64b3, guest PC 0x0c0a65f4 */
if(!s->budget--) { s->failed_pc=0x0c0a65f4u; return 0; }
r[4]=r[11];
goto P_0c0a65f6;
P_0c0a65f6: /* original 7dff, guest PC 0x0c0a65f6 */
if(!s->budget--) { s->failed_pc=0x0c0a65f6u; return 0; }
r[13]+=0xffffffffu;
goto P_0c0a65f8;
P_0c0a65f8: /* original 4d15, guest PC 0x0c0a65f8 */
if(!s->budget--) { s->failed_pc=0x0c0a65f8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>0)!=0);
goto P_0c0a65fa;
P_0c0a65fa: /* original 7b0c, guest PC 0x0c0a65fa */
if(!s->budget--) { s->failed_pc=0x0c0a65fau; return 0; }
r[11]+=0x0000000cu;
goto P_0c0a65fc;
P_0c0a65fc: /* original 8df7, guest PC 0x0c0a65fc */
if(!s->budget--) { s->failed_pc=0x0c0a65fcu; return 0; }
cond=r[17]&1u;
r[14]+=0x0000000cu;
if(cond) { goto P_0c0a65ee; }
goto P_0c0a6600;
P_0c0a65fe: /* original 7e0c, guest PC 0x0c0a65fe */
if(!s->budget--) { s->failed_pc=0x0c0a65feu; return 0; }
r[14]+=0x0000000cu;
goto P_0c0a6600;
P_0c0a6600: /* original 7f10, guest PC 0x0c0a6600 */
if(!s->budget--) { s->failed_pc=0x0c0a6600u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a6602;
P_0c0a6602: /* original 4f26, guest PC 0x0c0a6602 */
if(!s->budget--) { s->failed_pc=0x0c0a6602u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a6604;
P_0c0a6604: /* original 6bf6, guest PC 0x0c0a6604 */
if(!s->budget--) { s->failed_pc=0x0c0a6604u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0a6606;
P_0c0a6606: /* original 6cf6, guest PC 0x0c0a6606 */
if(!s->budget--) { s->failed_pc=0x0c0a6606u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a6608;
P_0c0a6608: /* original 6df6, guest PC 0x0c0a6608 */
if(!s->budget--) { s->failed_pc=0x0c0a6608u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a660a;
P_0c0a660a: /* original 000b, guest PC 0x0c0a660a */
if(!s->budget--) { s->failed_pc=0x0c0a660au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a660c: /* original 6ef6, guest PC 0x0c0a660c */
if(!s->budget--) { s->failed_pc=0x0c0a660cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0a660eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a660eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
