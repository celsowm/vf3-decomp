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
int vf3_offinv_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0ae97eu: goto P_0c0ae97e;
case 0x0c0ae980u: goto P_0c0ae980;
case 0x0c0ae982u: goto P_0c0ae982;
case 0x0c0ae984u: goto P_0c0ae984;
case 0x0c0ae986u: goto P_0c0ae986;
case 0x0c0ae988u: goto P_0c0ae988;
case 0x0c0ae98au: goto P_0c0ae98a;
case 0x0c0ae98cu: goto P_0c0ae98c;
case 0x0c0ae98eu: goto P_0c0ae98e;
case 0x0c0ae990u: goto P_0c0ae990;
case 0x0c0ae992u: goto P_0c0ae992;
case 0x0c0ae994u: goto P_0c0ae994;
case 0x0c0ae996u: goto P_0c0ae996;
case 0x0c0ae998u: goto P_0c0ae998;
case 0x0c0ae99au: goto P_0c0ae99a;
case 0x0c0ae99cu: goto P_0c0ae99c;
case 0x0c0ae99eu: goto P_0c0ae99e;
case 0x0c0ae9a0u: goto P_0c0ae9a0;
case 0x0c0ae9a2u: goto P_0c0ae9a2;
case 0x0c0ae9a4u: goto P_0c0ae9a4;
case 0x0c0ae9a6u: goto P_0c0ae9a6;
case 0x0c0ae9a8u: goto P_0c0ae9a8;
case 0x0c0ae9aau: goto P_0c0ae9aa;
case 0x0c0ae9acu: goto P_0c0ae9ac;
case 0x0c0ae9aeu: goto P_0c0ae9ae;
case 0x0c0ae9b0u: goto P_0c0ae9b0;
case 0x0c0ae9b2u: goto P_0c0ae9b2;
case 0x0c0ae9b4u: goto P_0c0ae9b4;
case 0x0c0ae9b6u: goto P_0c0ae9b6;
case 0x0c0ae9b8u: goto P_0c0ae9b8;
case 0x0c0ae9bau: goto P_0c0ae9ba;
case 0x0c0ae9bcu: goto P_0c0ae9bc;
case 0x0c0ae9beu: goto P_0c0ae9be;
case 0x0c0ae9c0u: goto P_0c0ae9c0;
case 0x0c0ae9c2u: goto P_0c0ae9c2;
case 0x0c0ae9c4u: goto P_0c0ae9c4;
case 0x0c0ae9c6u: goto P_0c0ae9c6;
case 0x0c0ae9c8u: goto P_0c0ae9c8;
case 0x0c0ae9cau: goto P_0c0ae9ca;
case 0x0c0ae9ccu: goto P_0c0ae9cc;
case 0x0c0ae9ceu: goto P_0c0ae9ce;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c0af728u: if(!vf3_matrix_family(0x0c0af728u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af728u; return 0; } return 1;
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c0ae2dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae2dcu; return 0; } return 1;
P_0c0ae97e: /* original 6262, guest PC 0x0c0ae97e */
if(!s->budget--) { s->failed_pc=0x0c0ae97eu; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae980;
P_0c0ae980: /* original 7ff8, guest PC 0x0c0ae980 */
if(!s->budget--) { s->failed_pc=0x0c0ae980u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0ae982;
P_0c0ae982: /* original 5361, guest PC 0x0c0ae982 */
if(!s->budget--) { s->failed_pc=0x0c0ae982u; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c0ae984;
P_0c0ae984: /* original 3230, guest PC 0x0c0ae984 */
if(!s->budget--) { s->failed_pc=0x0c0ae984u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0ae986;
P_0c0ae986: /* original 8b1e, guest PC 0x0c0ae986 */
if(!s->budget--) { s->failed_pc=0x0c0ae986u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae9c6; }
goto P_0c0ae988;
P_0c0ae988: /* original d015, guest PC 0x0c0ae988 */
if(!s->budget--) { s->failed_pc=0x0c0ae988u; return 0; }
r[0]=read(ram,0x0c0ae9e0u,4);
goto P_0c0ae98a;
P_0c0ae98a: /* original 6102, guest PC 0x0c0ae98a */
if(!s->budget--) { s->failed_pc=0x0c0ae98au; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c0ae98c;
P_0c0ae98c: /* original 1f11, guest PC 0x0c0ae98c */
if(!s->budget--) { s->failed_pc=0x0c0ae98cu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0ae98e;
P_0c0ae98e: /* original 5762, guest PC 0x0c0ae98e */
if(!s->budget--) { s->failed_pc=0x0c0ae98eu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae990;
P_0c0ae990: /* original d314, guest PC 0x0c0ae990 */
if(!s->budget--) { s->failed_pc=0x0c0ae990u; return 0; }
r[3]=read(ram,0x0c0ae9e4u,4);
goto P_0c0ae992;
P_0c0ae992: /* original 8476, guest PC 0x0c0ae992 */
if(!s->budget--) { s->failed_pc=0x0c0ae992u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+6,1);
goto P_0c0ae994;
P_0c0ae994: /* original d214, guest PC 0x0c0ae994 */
if(!s->budget--) { s->failed_pc=0x0c0ae994u; return 0; }
r[2]=read(ram,0x0c0ae9e8u,4);
goto P_0c0ae996;
P_0c0ae996: /* original 600c, guest PC 0x0c0ae996 */
if(!s->budget--) { s->failed_pc=0x0c0ae996u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae998;
P_0c0ae998: /* original 4028, guest PC 0x0c0ae998 */
if(!s->budget--) { s->failed_pc=0x0c0ae998u; return 0; }
r[0]<<=16;
goto P_0c0ae99a;
P_0c0ae99a: /* original 4018, guest PC 0x0c0ae99a */
if(!s->budget--) { s->failed_pc=0x0c0ae99au; return 0; }
r[0]<<=8;
goto P_0c0ae99c;
P_0c0ae99c: /* original 2039, guest PC 0x0c0ae99c */
if(!s->budget--) { s->failed_pc=0x0c0ae99cu; return 0; }
r[0]&=r[3];
goto P_0c0ae99e;
P_0c0ae99e: /* original 6103, guest PC 0x0c0ae99e */
if(!s->budget--) { s->failed_pc=0x0c0ae99eu; return 0; }
r[1]=r[0];
goto P_0c0ae9a0;
P_0c0ae9a0: /* original 8475, guest PC 0x0c0ae9a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae9a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+5,1);
goto P_0c0ae9a2;
P_0c0ae9a2: /* original 4329, guest PC 0x0c0ae9a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae9a2u; return 0; }
r[3]>>=16;
goto P_0c0ae9a4;
P_0c0ae9a4: /* original 600c, guest PC 0x0c0ae9a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae9a4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae9a6;
P_0c0ae9a6: /* original 4028, guest PC 0x0c0ae9a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae9a6u; return 0; }
r[0]<<=16;
goto P_0c0ae9a8;
P_0c0ae9a8: /* original 2029, guest PC 0x0c0ae9a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae9a8u; return 0; }
r[0]&=r[2];
goto P_0c0ae9aa;
P_0c0ae9aa: /* original 210b, guest PC 0x0c0ae9aa */
if(!s->budget--) { s->failed_pc=0x0c0ae9aau; return 0; }
r[1]|=r[0];
goto P_0c0ae9ac;
P_0c0ae9ac: /* original 8474, guest PC 0x0c0ae9ac */
if(!s->budget--) { s->failed_pc=0x0c0ae9acu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+4,1);
goto P_0c0ae9ae;
P_0c0ae9ae: /* original 600c, guest PC 0x0c0ae9ae */
if(!s->budget--) { s->failed_pc=0x0c0ae9aeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae9b0;
P_0c0ae9b0: /* original 4018, guest PC 0x0c0ae9b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae9b0u; return 0; }
r[0]<<=8;
goto P_0c0ae9b2;
P_0c0ae9b2: /* original 2039, guest PC 0x0c0ae9b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae9b2u; return 0; }
r[0]&=r[3];
goto P_0c0ae9b4;
P_0c0ae9b4: /* original 210b, guest PC 0x0c0ae9b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae9b4u; return 0; }
r[1]|=r[0];
goto P_0c0ae9b6;
P_0c0ae9b6: /* original 8473, guest PC 0x0c0ae9b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae9b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[7]+3,1);
goto P_0c0ae9b8;
P_0c0ae9b8: /* original 600c, guest PC 0x0c0ae9b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae9b8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae9ba;
P_0c0ae9ba: /* original 210b, guest PC 0x0c0ae9ba */
if(!s->budget--) { s->failed_pc=0x0c0ae9bau; return 0; }
r[1]|=r[0];
goto P_0c0ae9bc;
P_0c0ae9bc: /* original 2f12, guest PC 0x0c0ae9bc */
if(!s->budget--) { s->failed_pc=0x0c0ae9bcu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ae9be;
P_0c0ae9be: /* original 57f1, guest PC 0x0c0ae9be */
if(!s->budget--) { s->failed_pc=0x0c0ae9beu; return 0; }
r[7]=read(ram,r[15]+4,4);
goto P_0c0ae9c0;
P_0c0ae9c0: /* original 930b, guest PC 0x0c0ae9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae9c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae9dau,2);
goto P_0c0ae9c2;
P_0c0ae9c2: /* original 373c, guest PC 0x0c0ae9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae9c2u; return 0; }
r[7]+=r[3];
goto P_0c0ae9c4;
P_0c0ae9c4: /* original 2712, guest PC 0x0c0ae9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae9c4u; return 0; }
write(ram,r[7],r[1],4);
goto P_0c0ae9c6;
P_0c0ae9c6: /* original 5362, guest PC 0x0c0ae9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae9c6u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae9c8;
P_0c0ae9c8: /* original 7307, guest PC 0x0c0ae9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae9c8u; return 0; }
r[3]+=0x00000007u;
goto P_0c0ae9ca;
P_0c0ae9ca: /* original 1632, guest PC 0x0c0ae9ca */
if(!s->budget--) { s->failed_pc=0x0c0ae9cau; return 0; }
write(ram,r[6]+8,r[3],4);
goto P_0c0ae9cc;
P_0c0ae9cc: /* original ac66, guest PC 0x0c0ae9cc */
if(!s->budget--) { s->failed_pc=0x0c0ae9ccu; return 0; }
r[15]+=0x00000008u;
goto P_0c0ae29c;
P_0c0ae9ce: /* original 7f08, guest PC 0x0c0ae9ce */
if(!s->budget--) { s->failed_pc=0x0c0ae9ceu; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0ae9d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ae9d0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0ae29cu,0x0c0ae29eu,0x0c0ae2a0u,0x0c0ae2a2u,0x0c0ae2a4u,0x0c0ae2a6u,0x0c0ae2a8u,0x0c0ae2aau,0x0c0ae2acu,0x0c0ae2aeu,0x0c0ae2b0u,0x0c0ae2b2u,0x0c0ae2b4u,0x0c0ae2b6u,0x0c0ae2b8u,0x0c0ae2bau,
0x0c0ae2bcu,0x0c0ae2beu,0x0c0ae2c0u,0x0c0ae2c2u,0x0c0ae2c4u,0x0c0ae2c6u,0x0c0ae2c8u,0x0c0ae2cau,0x0c0ae2ccu,0x0c0ae2ceu,0x0c0ae2d0u,0x0c0ae2d2u,0x0c0ae2d4u,0x0c0ae2d6u,0x0c0ae2d8u,0x0c0ae2dau,
0x0c0ae97eu,0x0c0ae980u,0x0c0ae982u,0x0c0ae984u,0x0c0ae986u,0x0c0ae988u,0x0c0ae98au,0x0c0ae98cu,0x0c0ae98eu,0x0c0ae990u,0x0c0ae992u,0x0c0ae994u,0x0c0ae996u,0x0c0ae998u,0x0c0ae99au,0x0c0ae99cu,
0x0c0ae99eu,0x0c0ae9a0u,0x0c0ae9a2u,0x0c0ae9a4u,0x0c0ae9a6u,0x0c0ae9a8u,0x0c0ae9aau,0x0c0ae9acu,0x0c0ae9aeu,0x0c0ae9b0u,0x0c0ae9b2u,0x0c0ae9b4u,0x0c0ae9b6u,0x0c0ae9b8u,0x0c0ae9bau,0x0c0ae9bcu,
0x0c0ae9beu,0x0c0ae9c0u,0x0c0ae9c2u,0x0c0ae9c4u,0x0c0ae9c6u,0x0c0ae9c8u,0x0c0ae9cau,0x0c0ae9ccu,0x0c0ae9ceu,
};
static const uint32_t claim_pcs[]={
0x0c0ae97eu,
};
int vf3_offinv_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
