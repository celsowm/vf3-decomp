/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_seventh_c13_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0703f2u: goto P_0c0703f2;
case 0x0c0703f4u: goto P_0c0703f4;
case 0x0c0703f6u: goto P_0c0703f6;
case 0x0c0703f8u: goto P_0c0703f8;
case 0x0c070996u: goto P_0c070996;
case 0x0c070998u: goto P_0c070998;
case 0x0c07099au: goto P_0c07099a;
case 0x0c07099cu: goto P_0c07099c;
case 0x0c070b6au: goto P_0c070b6a;
case 0x0c070b6cu: goto P_0c070b6c;
case 0x0c070b6eu: goto P_0c070b6e;
case 0x0c070b70u: goto P_0c070b70;
case 0x0c070dceu: goto P_0c070dce;
case 0x0c070dd0u: goto P_0c070dd0;
case 0x0c070dd2u: goto P_0c070dd2;
case 0x0c070dd4u: goto P_0c070dd4;
case 0x0c070f9eu: goto P_0c070f9e;
case 0x0c070fa0u: goto P_0c070fa0;
case 0x0c070fa2u: goto P_0c070fa2;
case 0x0c070fa4u: goto P_0c070fa4;
case 0x0c092c36u: goto P_0c092c36;
case 0x0c092c38u: goto P_0c092c38;
case 0x0c092c3au: goto P_0c092c3a;
case 0x0c092c3cu: goto P_0c092c3c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0703f2: /* original f40b, guest PC 0x0c0703f2 */
if(!s->budget--) { s->failed_pc=0x0c0703f2u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c0703f4;
P_0c0703f4: /* original d306, guest PC 0x0c0703f4 */
if(!s->budget--) { s->failed_pc=0x0c0703f4u; return 0; }
r[3]=read(ram,0x0c070410u,4);
goto P_0c0703f6;
P_0c0703f6: /* original 432b, guest PC 0x0c0703f6 */
if(!s->budget--) { s->failed_pc=0x0c0703f6u; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c0703f8: /* original 0009, guest PC 0x0c0703f8 */
if(!s->budget--) { s->failed_pc=0x0c0703f8u; return 0; }
return vf3_matrix_family(0x0c0703fau,s,ram);
P_0c070996: /* original f40b, guest PC 0x0c070996 */
if(!s->budget--) { s->failed_pc=0x0c070996u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070998;
P_0c070998: /* original d306, guest PC 0x0c070998 */
if(!s->budget--) { s->failed_pc=0x0c070998u; return 0; }
r[3]=read(ram,0x0c0709b4u,4);
goto P_0c07099a;
P_0c07099a: /* original 432b, guest PC 0x0c07099a */
if(!s->budget--) { s->failed_pc=0x0c07099au; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c07099c: /* original 0009, guest PC 0x0c07099c */
if(!s->budget--) { s->failed_pc=0x0c07099cu; return 0; }
return vf3_matrix_family(0x0c07099eu,s,ram);
P_0c070b6a: /* original f40b, guest PC 0x0c070b6a */
if(!s->budget--) { s->failed_pc=0x0c070b6au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070b6c;
P_0c070b6c: /* original d306, guest PC 0x0c070b6c */
if(!s->budget--) { s->failed_pc=0x0c070b6cu; return 0; }
r[3]=read(ram,0x0c070b88u,4);
goto P_0c070b6e;
P_0c070b6e: /* original 432b, guest PC 0x0c070b6e */
if(!s->budget--) { s->failed_pc=0x0c070b6eu; return 0; }
target=r[3];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070b70: /* original 0009, guest PC 0x0c070b70 */
if(!s->budget--) { s->failed_pc=0x0c070b70u; return 0; }
return vf3_matrix_family(0x0c070b72u,s,ram);
P_0c070dce: /* original f40b, guest PC 0x0c070dce */
if(!s->budget--) { s->failed_pc=0x0c070dceu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070dd0;
P_0c070dd0: /* original d206, guest PC 0x0c070dd0 */
if(!s->budget--) { s->failed_pc=0x0c070dd0u; return 0; }
r[2]=read(ram,0x0c070decu,4);
goto P_0c070dd2;
P_0c070dd2: /* original 422b, guest PC 0x0c070dd2 */
if(!s->budget--) { s->failed_pc=0x0c070dd2u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070dd4: /* original 0009, guest PC 0x0c070dd4 */
if(!s->budget--) { s->failed_pc=0x0c070dd4u; return 0; }
return vf3_matrix_family(0x0c070dd6u,s,ram);
P_0c070f9e: /* original f40b, guest PC 0x0c070f9e */
if(!s->budget--) { s->failed_pc=0x0c070f9eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c070fa0;
P_0c070fa0: /* original d206, guest PC 0x0c070fa0 */
if(!s->budget--) { s->failed_pc=0x0c070fa0u; return 0; }
r[2]=read(ram,0x0c070fbcu,4);
goto P_0c070fa2;
P_0c070fa2: /* original 422b, guest PC 0x0c070fa2 */
if(!s->budget--) { s->failed_pc=0x0c070fa2u; return 0; }
target=r[2];
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c070fa4: /* original 0009, guest PC 0x0c070fa4 */
if(!s->budget--) { s->failed_pc=0x0c070fa4u; return 0; }
return vf3_matrix_family(0x0c070fa6u,s,ram);
P_0c092c36: /* original f40b, guest PC 0x0c092c36 */
if(!s->budget--) { s->failed_pc=0x0c092c36u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c092c38;
P_0c092c38: /* original 7f18, guest PC 0x0c092c38 */
if(!s->budget--) { s->failed_pc=0x0c092c38u; return 0; }
r[15]+=0x00000018u;
goto P_0c092c3a;
P_0c092c3a: /* original 000b, guest PC 0x0c092c3a */
if(!s->budget--) { s->failed_pc=0x0c092c3au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c092c3c: /* original 6ef6, guest PC 0x0c092c3c */
if(!s->budget--) { s->failed_pc=0x0c092c3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c092c3eu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0703f2u,0x0c0703f4u,0x0c0703f6u,0x0c0703f8u,0x0c070996u,0x0c070998u,0x0c07099au,0x0c07099cu,0x0c070b6au,0x0c070b6cu,0x0c070b6eu,0x0c070b70u,0x0c070dceu,0x0c070dd0u,0x0c070dd2u,0x0c070dd4u,
0x0c070f9eu,0x0c070fa0u,0x0c070fa2u,0x0c070fa4u,0x0c092c36u,0x0c092c38u,0x0c092c3au,0x0c092c3cu,
};
int vf3_seventh_c13_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
