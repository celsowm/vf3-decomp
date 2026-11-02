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
int vf3_offinv_b04_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* The code base is the mirror the code runs under: 0x0c, 0x8c or 0xac.  A call hands the callee the mirror it jumped to (the router masks the entry PC to 29 bits, which loses it); a direct entry falls back to the alias the caller left in the link register. */
uint32_t code_base=(vf3_matrix_call_alias_pc==(entry&0x1fffffffu))?vf3_matrix_call_alias:(((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u));
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0597bau: goto P_0c0597ba;
case 0x0c0597bcu: goto P_0c0597bc;
default: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!s->lost_pc) s->lost_pc=target; if(!vf3_matrix_family(target,s,ram)) return 0; return 1;
}
P_0c0597ba: /* original 000b, guest PC 0x0c0597ba */
if(!s->budget--) { s->failed_pc=0x0c0597bau; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0597bc: /* original 0009, guest PC 0x0c0597bc */
if(!s->budget--) { s->failed_pc=0x0c0597bcu; return 0; }
if(!vf3_matrix_family(0x0c0597beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0597beu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0597bau,0x0c0597bcu,
};
static const uint32_t claim_pcs[]={
0x0c0597bau,0x0c0597bcu,
};
int vf3_offinv_b04_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(claim_pcs)/sizeof(claim_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(claim_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(claim_pcs)/sizeof(claim_pcs[0]) && claim_pcs[lo]==pc;
}
