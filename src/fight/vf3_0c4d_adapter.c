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
int vf3_0c4d_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0c4dc0u: goto P_0c0c4dc0;
case 0x0c0c4dc2u: goto P_0c0c4dc2;
case 0x0c0c4dc4u: goto P_0c0c4dc4;
case 0x0c0c4dc6u: goto P_0c0c4dc6;
case 0x0c0c4dc8u: goto P_0c0c4dc8;
case 0x0c0c4dcau: goto P_0c0c4dca;
case 0x0c0c4dccu: goto P_0c0c4dcc;
case 0x0c0c4dceu: goto P_0c0c4dce;
case 0x0c0c4dd0u: goto P_0c0c4dd0;
case 0x0c0c4dd2u: goto P_0c0c4dd2;
case 0x0c0c4dd4u: goto P_0c0c4dd4;
case 0x0c0c4dd6u: goto P_0c0c4dd6;
case 0x0c0c4dd8u: goto P_0c0c4dd8;
case 0x0c0c4ddau: goto P_0c0c4dda;
case 0x0c0c4ddcu: goto P_0c0c4ddc;
case 0x0c0c4ddeu: goto P_0c0c4dde;
case 0x0c0c4de0u: goto P_0c0c4de0;
case 0x0c0c4de2u: goto P_0c0c4de2;
case 0x0c0c4de4u: goto P_0c0c4de4;
case 0x0c0c4de6u: goto P_0c0c4de6;
case 0x0c0c4de8u: goto P_0c0c4de8;
case 0x0c0c4deau: goto P_0c0c4dea;
case 0x0c0c4decu: goto P_0c0c4dec;
case 0x0c0c4deeu: goto P_0c0c4dee;
case 0x0c0c4df0u: goto P_0c0c4df0;
case 0x0c0c4df2u: goto P_0c0c4df2;
case 0x0c0c4df4u: goto P_0c0c4df4;
case 0x0c0c4df6u: goto P_0c0c4df6;
case 0x0c0c4df8u: goto P_0c0c4df8;
case 0x0c0c4dfau: goto P_0c0c4dfa;
case 0x0c0c4dfcu: goto P_0c0c4dfc;
case 0x0c0c4dfeu: goto P_0c0c4dfe;
case 0x0c0c4e00u: goto P_0c0c4e00;
case 0x0c0c4e02u: goto P_0c0c4e02;
case 0x0c0c4e04u: goto P_0c0c4e04;
case 0x0c0c4e06u: goto P_0c0c4e06;
case 0x0c0c4e08u: goto P_0c0c4e08;
case 0x0c0c4e0au: goto P_0c0c4e0a;
case 0x0c0c4e0cu: goto P_0c0c4e0c;
case 0x0c0c4e0eu: goto P_0c0c4e0e;
case 0x0c0c4e10u: goto P_0c0c4e10;
case 0x0c0c4e12u: goto P_0c0c4e12;
case 0x0c0c4e14u: goto P_0c0c4e14;
case 0x0c0c4e16u: goto P_0c0c4e16;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0c4dc0: /* original 4f22, guest PC 0x0c0c4dc0 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c4dc2;
P_0c0c4dc2: /* original c80a, guest PC 0x0c0c4dc2 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&10u)==0)!=0);
goto P_0c0c4dc4;
P_0c0c4dc4: /* original 8b1f, guest PC 0x0c0c4dc4 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e06; }
goto P_0c0c4dc6;
P_0c0c4dc6: /* original e051, guest PC 0x0c0c4dc6 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc6u; return 0; }
r[0]=0x00000051u;
goto P_0c0c4dc8;
P_0c0c4dc8: /* original 04ec, guest PC 0x0c0c4dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c4dc8u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dca;
P_0c0c4dca: /* original 634c, guest PC 0x0c0c4dca */
if(!s->budget--) { s->failed_pc=0x0c0c4dcau; return 0; }
r[3]=r[4]&255u;
goto P_0c0c4dcc;
P_0c0c4dcc: /* original 2338, guest PC 0x0c0c4dcc */
if(!s->budget--) { s->failed_pc=0x0c0c4dccu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c4dce;
P_0c0c4dce: /* original 8b1a, guest PC 0x0c0c4dce */
if(!s->budget--) { s->failed_pc=0x0c0c4dceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e06; }
goto P_0c0c4dd0;
P_0c0c4dd0: /* original e052, guest PC 0x0c0c4dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd0u; return 0; }
r[0]=0x00000052u;
goto P_0c0c4dd2;
P_0c0c4dd2: /* original 03ec, guest PC 0x0c0c4dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dd4;
P_0c0c4dd4: /* original 04ec, guest PC 0x0c0c4dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0c4dd6;
P_0c0c4dd6: /* original 7302, guest PC 0x0c0c4dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd6u; return 0; }
r[3]+=0x00000002u;
goto P_0c0c4dd8;
P_0c0c4dd8: /* original 4401, guest PC 0x0c0c4dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c4dd8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c0c4dda;
P_0c0c4dda: /* original 0e34, guest PC 0x0c0c4dda */
if(!s->budget--) { s->failed_pc=0x0c0c4ddau; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0c4ddc;
P_0c0c4ddc: /* original 6043, guest PC 0x0c0c4ddc */
if(!s->budget--) { s->failed_pc=0x0c0c4ddcu; return 0; }
r[0]=r[4];
goto P_0c0c4dde;
P_0c0c4dde: /* original 4000, guest PC 0x0c0c4dde */
if(!s->budget--) { s->failed_pc=0x0c0c4ddeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c4de0;
P_0c0c4de0: /* original 03dd, guest PC 0x0c0c4de0 */
if(!s->budget--) { s->failed_pc=0x0c0c4de0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0c4de2;
P_0c0c4de2: /* original 643f, guest PC 0x0c0c4de2 */
if(!s->budget--) { s->failed_pc=0x0c0c4de2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c0c4de4;
P_0c0c4de4: /* original 6043, guest PC 0x0c0c4de4 */
if(!s->budget--) { s->failed_pc=0x0c0c4de4u; return 0; }
r[0]=r[4];
goto P_0c0c4de6;
P_0c0c4de6: /* original 88ff, guest PC 0x0c0c4de6 */
if(!s->budget--) { s->failed_pc=0x0c0c4de6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c4de8;
P_0c0c4de8: /* original 8b11, guest PC 0x0c0c4de8 */
if(!s->budget--) { s->failed_pc=0x0c0c4de8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c4e0e; }
goto P_0c0c4dea;
P_0c0c4dea: /* original d311, guest PC 0x0c0c4dea */
if(!s->budget--) { s->failed_pc=0x0c0c4deau; return 0; }
r[3]=read(ram,0x0c0c4e30u,4);
goto P_0c0c4dec;
P_0c0c4dec: /* original e052, guest PC 0x0c0c4dec */
if(!s->budget--) { s->failed_pc=0x0c0c4decu; return 0; }
r[0]=0x00000052u;
goto P_0c0c4dee;
P_0c0c4dee: /* original e200, guest PC 0x0c0c4dee */
if(!s->budget--) { s->failed_pc=0x0c0c4deeu; return 0; }
r[2]=0x00000000u;
goto P_0c0c4df0;
P_0c0c4df0: /* original 430b, guest PC 0x0c0c4df0 */
if(!s->budget--) { s->failed_pc=0x0c0c4df0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0c4df4u;
write(ram,r[14]+r[0],r[2],1);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c4df4u) { target=s->pc; goto dispatch; }
goto P_0c0c4df4;
P_0c0c4df2: /* original 0e24, guest PC 0x0c0c4df2 */
if(!s->budget--) { s->failed_pc=0x0c0c4df2u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0c4df4;
P_0c0c4df4: /* original e47f, guest PC 0x0c0c4df4 */
if(!s->budget--) { s->failed_pc=0x0c0c4df4u; return 0; }
r[4]=0x0000007fu;
goto P_0c0c4df6;
P_0c0c4df6: /* original 6503, guest PC 0x0c0c4df6 */
if(!s->budget--) { s->failed_pc=0x0c0c4df6u; return 0; }
r[5]=r[0];
goto P_0c0c4df8;
P_0c0c4df8: /* original 2459, guest PC 0x0c0c4df8 */
if(!s->budget--) { s->failed_pc=0x0c0c4df8u; return 0; }
r[4]&=r[5];
goto P_0c0c4dfa;
P_0c0c4dfa: /* original e320, guest PC 0x0c0c4dfa */
if(!s->budget--) { s->failed_pc=0x0c0c4dfau; return 0; }
r[3]=0x00000020u;
goto P_0c0c4dfc;
P_0c0c4dfc: /* original 624c, guest PC 0x0c0c4dfc */
if(!s->budget--) { s->failed_pc=0x0c0c4dfcu; return 0; }
r[2]=r[4]&255u;
goto P_0c0c4dfe;
P_0c0c4dfe: /* original 3237, guest PC 0x0c0c4dfe */
if(!s->budget--) { s->failed_pc=0x0c0c4dfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[3])!=0);
goto P_0c0c4e00;
P_0c0c4e00: /* original 8901, guest PC 0x0c0c4e00 */
if(!s->budget--) { s->failed_pc=0x0c0c4e00u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c4e06; }
goto P_0c0c4e02;
P_0c0c4e02: /* original 6453, guest PC 0x0c0c4e02 */
if(!s->budget--) { s->failed_pc=0x0c0c4e02u; return 0; }
r[4]=r[5];
goto P_0c0c4e04;
P_0c0c4e04: /* original 7420, guest PC 0x0c0c4e04 */
if(!s->budget--) { s->failed_pc=0x0c0c4e04u; return 0; }
r[4]+=0x00000020u;
goto P_0c0c4e06;
P_0c0c4e06: /* original e051, guest PC 0x0c0c4e06 */
if(!s->budget--) { s->failed_pc=0x0c0c4e06u; return 0; }
r[0]=0x00000051u;
goto P_0c0c4e08;
P_0c0c4e08: /* original 74ff, guest PC 0x0c0c4e08 */
if(!s->budget--) { s->failed_pc=0x0c0c4e08u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0c4e0a;
P_0c0c4e0a: /* original 0e44, guest PC 0x0c0c4e0a */
if(!s->budget--) { s->failed_pc=0x0c0c4e0au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0c4e0c;
P_0c0c4e0c: /* original 64d1, guest PC 0x0c0c4e0c */
if(!s->budget--) { s->failed_pc=0x0c0c4e0cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[4]=tmp;
goto P_0c0c4e0e;
P_0c0c4e0e: /* original 4f26, guest PC 0x0c0c4e0e */
if(!s->budget--) { s->failed_pc=0x0c0c4e0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c4e10;
P_0c0c4e10: /* original d306, guest PC 0x0c0c4e10 */
if(!s->budget--) { s->failed_pc=0x0c0c4e10u; return 0; }
r[3]=read(ram,0x0c0c4e2cu,4);
goto P_0c0c4e12;
P_0c0c4e12: /* original 6df6, guest PC 0x0c0c4e12 */
if(!s->budget--) { s->failed_pc=0x0c0c4e12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c4e14;
P_0c0c4e14: /* original 432b, guest PC 0x0c0c4e14 */
if(!s->budget--) { s->failed_pc=0x0c0c4e14u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0c4e16: /* original 6ef6, guest PC 0x0c0c4e16 */
if(!s->budget--) { s->failed_pc=0x0c0c4e16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c4e18u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c0c4dc0u,0x0c0c4dc2u,0x0c0c4dc4u,0x0c0c4dc6u,0x0c0c4dc8u,0x0c0c4dcau,0x0c0c4dccu,0x0c0c4dceu,0x0c0c4dd0u,0x0c0c4dd2u,0x0c0c4dd4u,0x0c0c4dd6u,0x0c0c4dd8u,0x0c0c4ddau,0x0c0c4ddcu,0x0c0c4ddeu,
0x0c0c4de0u,0x0c0c4de2u,0x0c0c4de4u,0x0c0c4de6u,0x0c0c4de8u,0x0c0c4deau,0x0c0c4decu,0x0c0c4deeu,0x0c0c4df0u,0x0c0c4df2u,0x0c0c4df4u,0x0c0c4df6u,0x0c0c4df8u,0x0c0c4dfau,0x0c0c4dfcu,0x0c0c4dfeu,
0x0c0c4e00u,0x0c0c4e02u,0x0c0c4e04u,0x0c0c4e06u,0x0c0c4e08u,0x0c0c4e0au,0x0c0c4e0cu,0x0c0c4e0eu,0x0c0c4e10u,0x0c0c4e12u,0x0c0c4e14u,0x0c0c4e16u,
};
int vf3_0c4d_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
