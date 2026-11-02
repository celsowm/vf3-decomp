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
int vf3_offinv_b02_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07ac6au: goto P_0c07ac6a;
case 0x0c07ac6cu: goto P_0c07ac6c;
case 0x0c07ac6eu: goto P_0c07ac6e;
case 0x0c07ac70u: goto P_0c07ac70;
case 0x0c07ac72u: goto P_0c07ac72;
case 0x0c07ac74u: goto P_0c07ac74;
case 0x0c07ac76u: goto P_0c07ac76;
case 0x0c07ac78u: goto P_0c07ac78;
case 0x0c07ac7au: goto P_0c07ac7a;
case 0x0c07ac7cu: goto P_0c07ac7c;
case 0x0c07ac7eu: goto P_0c07ac7e;
case 0x0c07ac80u: goto P_0c07ac80;
case 0x0c07ac82u: goto P_0c07ac82;
case 0x0c07ac84u: goto P_0c07ac84;
case 0x0c07ac86u: goto P_0c07ac86;
case 0x0c07ac88u: goto P_0c07ac88;
case 0x0c07ac8au: goto P_0c07ac8a;
case 0x0c07ac8cu: goto P_0c07ac8c;
case 0x0c07ac8eu: goto P_0c07ac8e;
case 0x0c07ac90u: goto P_0c07ac90;
case 0x0c07ac92u: goto P_0c07ac92;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c07ac6a: /* original 2fe6, guest PC 0x0c07ac6a */
if(!s->budget--) { s->failed_pc=0x0c07ac6au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac6c;
P_0c07ac6c: /* original 4511, guest PC 0x0c07ac6c */
if(!s->budget--) { s->failed_pc=0x0c07ac6cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c07ac6e;
P_0c07ac6e: /* original 4f22, guest PC 0x0c07ac6e */
if(!s->budget--) { s->failed_pc=0x0c07ac6eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ac70;
P_0c07ac70: /* original 5341, guest PC 0x0c07ac70 */
if(!s->budget--) { s->failed_pc=0x0c07ac70u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07ac72;
P_0c07ac72: /* original 7ffc, guest PC 0x0c07ac72 */
if(!s->budget--) { s->failed_pc=0x0c07ac72u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ac74;
P_0c07ac74: /* original 2f32, guest PC 0x0c07ac74 */
if(!s->budget--) { s->failed_pc=0x0c07ac74u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07ac76;
P_0c07ac76: /* original 8d05, guest PC 0x0c07ac76 */
if(!s->budget--) { s->failed_pc=0x0c07ac76u; return 0; }
cond=r[17]&1u;
r[14]=read(ram,r[4]+24,4);
if(cond) { goto P_0c07ac84; }
goto P_0c07ac7a;
P_0c07ac78: /* original 5e46, guest PC 0x0c07ac78 */
if(!s->budget--) { s->failed_pc=0x0c07ac78u; return 0; }
r[14]=read(ram,r[4]+24,4);
goto P_0c07ac7a;
P_0c07ac7a: /* original d01b, guest PC 0x0c07ac7a */
if(!s->budget--) { s->failed_pc=0x0c07ac7au; return 0; }
r[0]=read(ram,0x0c07ace8u,4);
goto P_0c07ac7c;
P_0c07ac7c: /* original e200, guest PC 0x0c07ac7c */
if(!s->budget--) { s->failed_pc=0x0c07ac7cu; return 0; }
r[2]=0x00000000u;
goto P_0c07ac7e;
P_0c07ac7e: /* original 4e00, guest PC 0x0c07ac7e */
if(!s->budget--) { s->failed_pc=0x0c07ac7eu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>>31)!=0);
r[14]<<=1;
goto P_0c07ac80;
P_0c07ac80: /* original a003, guest PC 0x0c07ac80 */
if(!s->budget--) { s->failed_pc=0x0c07ac80u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07ac8a;
P_0c07ac82: /* original 0e25, guest PC 0x0c07ac82 */
if(!s->budget--) { s->failed_pc=0x0c07ac82u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07ac84;
P_0c07ac84: /* original 65f2, guest PC 0x0c07ac84 */
if(!s->budget--) { s->failed_pc=0x0c07ac84u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c07ac86;
P_0c07ac86: /* original bfcf, guest PC 0x0c07ac86 */
if(!s->budget--) { s->failed_pc=0x0c07ac86u; return 0; }
target=code_base|0x0c07ac28u; r[16]=code_base|0x0c07ac8au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ac8au) { target=s->pc; goto dispatch; }
goto P_0c07ac8a;
P_0c07ac88: /* original 64e3, guest PC 0x0c07ac88 */
if(!s->budget--) { s->failed_pc=0x0c07ac88u; return 0; }
r[4]=r[14];
goto P_0c07ac8a;
P_0c07ac8a: /* original 7f04, guest PC 0x0c07ac8a */
if(!s->budget--) { s->failed_pc=0x0c07ac8au; return 0; }
r[15]+=0x00000004u;
goto P_0c07ac8c;
P_0c07ac8c: /* original 4f26, guest PC 0x0c07ac8c */
if(!s->budget--) { s->failed_pc=0x0c07ac8cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ac8e;
P_0c07ac8e: /* original e000, guest PC 0x0c07ac8e */
if(!s->budget--) { s->failed_pc=0x0c07ac8eu; return 0; }
r[0]=0x00000000u;
goto P_0c07ac90;
P_0c07ac90: /* original 000b, guest PC 0x0c07ac90 */
if(!s->budget--) { s->failed_pc=0x0c07ac90u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ac92: /* original 6ef6, guest PC 0x0c07ac92 */
if(!s->budget--) { s->failed_pc=0x0c07ac92u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ac94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ac94u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c07ac6au,0x0c07ac6cu,0x0c07ac6eu,0x0c07ac70u,0x0c07ac72u,0x0c07ac74u,0x0c07ac76u,0x0c07ac78u,0x0c07ac7au,0x0c07ac7cu,0x0c07ac7eu,0x0c07ac80u,0x0c07ac82u,0x0c07ac84u,0x0c07ac86u,0x0c07ac88u,
0x0c07ac8au,0x0c07ac8cu,0x0c07ac8eu,0x0c07ac90u,0x0c07ac92u,
};
static const uint32_t claim_pcs[]={
0x0c07ac6au,
};
int vf3_offinv_b02_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
