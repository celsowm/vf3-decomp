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
int vf3_away_batch146_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0af91cu: goto P_0c0af91c;
case 0x0c0af91eu: goto P_0c0af91e;
case 0x0c0af920u: goto P_0c0af920;
case 0x0c0af922u: goto P_0c0af922;
case 0x0c0af924u: goto P_0c0af924;
case 0x0c0af926u: goto P_0c0af926;
case 0x0c0af928u: goto P_0c0af928;
case 0x0c0af92au: goto P_0c0af92a;
case 0x0c0af92cu: goto P_0c0af92c;
case 0x0c0af92eu: goto P_0c0af92e;
case 0x0c0af930u: goto P_0c0af930;
case 0x0c0af932u: goto P_0c0af932;
case 0x0c0af934u: goto P_0c0af934;
case 0x0c0af936u: goto P_0c0af936;
case 0x0c0af938u: goto P_0c0af938;
case 0x0c0af93au: goto P_0c0af93a;
case 0x0c0af93cu: goto P_0c0af93c;
case 0x0c0af958u: goto P_0c0af958;
case 0x0c0af95au: goto P_0c0af95a;
case 0x0c0af95cu: goto P_0c0af95c;
case 0x0c0af95eu: goto P_0c0af95e;
case 0x0c0af960u: goto P_0c0af960;
case 0x0c0af962u: goto P_0c0af962;
case 0x0c0af964u: goto P_0c0af964;
case 0x0c0af966u: goto P_0c0af966;
case 0x0c0af968u: goto P_0c0af968;
case 0x0c0af96au: goto P_0c0af96a;
case 0x0c0af96cu: goto P_0c0af96c;
case 0x0c0af96eu: goto P_0c0af96e;
case 0x0c0af970u: goto P_0c0af970;
case 0x0c0af972u: goto P_0c0af972;
case 0x0c0af974u: goto P_0c0af974;
case 0x0c0af976u: goto P_0c0af976;
case 0x0c0af978u: goto P_0c0af978;
case 0x0c0af97au: goto P_0c0af97a;
case 0x0c0af97cu: goto P_0c0af97c;
case 0x0c0af99cu: goto P_0c0af99c;
case 0x0c0af99eu: goto P_0c0af99e;
case 0x0c0af9a0u: goto P_0c0af9a0;
case 0x0c0af9a2u: goto P_0c0af9a2;
case 0x0c0af9a4u: goto P_0c0af9a4;
case 0x0c0af9a6u: goto P_0c0af9a6;
case 0x0c0af9a8u: goto P_0c0af9a8;
case 0x0c0af9aau: goto P_0c0af9aa;
case 0x0c0af9acu: goto P_0c0af9ac;
case 0x0c0af9aeu: goto P_0c0af9ae;
case 0x0c0af9b0u: goto P_0c0af9b0;
case 0x0c0af9b2u: goto P_0c0af9b2;
case 0x0c0af9b4u: goto P_0c0af9b4;
case 0x0c0af9b6u: goto P_0c0af9b6;
case 0x0c0af9b8u: goto P_0c0af9b8;
case 0x0c0af9bau: goto P_0c0af9ba;
case 0x0c0af9bcu: goto P_0c0af9bc;
case 0x0c0af9beu: goto P_0c0af9be;
case 0x0c0af9c0u: goto P_0c0af9c0;
case 0x0c0af9c2u: goto P_0c0af9c2;
case 0x0c0af9c4u: goto P_0c0af9c4;
case 0x0c0af9c6u: goto P_0c0af9c6;
case 0x0c0af9c8u: goto P_0c0af9c8;
case 0x0c0af9cau: goto P_0c0af9ca;
case 0x0c0af9ccu: goto P_0c0af9cc;
case 0x0c0af9ceu: goto P_0c0af9ce;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0af91c: /* original 2fe6, guest PC 0x0c0af91c */
if(!s->budget--) { s->failed_pc=0x0c0af91cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af91e;
P_0c0af91e: /* original 2fd6, guest PC 0x0c0af91e */
if(!s->budget--) { s->failed_pc=0x0c0af91eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af920;
P_0c0af920: /* original 9031, guest PC 0x0c0af920 */
if(!s->budget--) { s->failed_pc=0x0c0af920u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af986u,2);
goto P_0c0af922;
P_0c0af922: /* original 0d4d, guest PC 0x0c0af922 */
if(!s->budget--) { s->failed_pc=0x0c0af922u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0af924;
P_0c0af924: /* original e03e, guest PC 0x0c0af924 */
if(!s->budget--) { s->failed_pc=0x0c0af924u; return 0; }
r[0]=0x0000003eu;
goto P_0c0af926;
P_0c0af926: /* original 0e4d, guest PC 0x0c0af926 */
if(!s->budget--) { s->failed_pc=0x0c0af926u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0af928;
P_0c0af928: /* original 6ddd, guest PC 0x0c0af928 */
if(!s->budget--) { s->failed_pc=0x0c0af928u; return 0; }
r[13]=r[13]&65535u;
goto P_0c0af92a;
P_0c0af92a: /* original 63d3, guest PC 0x0c0af92a */
if(!s->budget--) { s->failed_pc=0x0c0af92au; return 0; }
r[3]=r[13];
goto P_0c0af92c;
P_0c0af92c: /* original 6eed, guest PC 0x0c0af92c */
if(!s->budget--) { s->failed_pc=0x0c0af92cu; return 0; }
r[14]=r[14]&65535u;
goto P_0c0af92e;
P_0c0af92e: /* original 33e8, guest PC 0x0c0af92e */
if(!s->budget--) { s->failed_pc=0x0c0af92eu; return 0; }
r[3]-=r[14];
goto P_0c0af930;
P_0c0af930: /* original 66d3, guest PC 0x0c0af930 */
if(!s->budget--) { s->failed_pc=0x0c0af930u; return 0; }
r[6]=r[13];
goto P_0c0af932;
P_0c0af932: /* original 6e33, guest PC 0x0c0af932 */
if(!s->budget--) { s->failed_pc=0x0c0af932u; return 0; }
r[14]=r[3];
goto P_0c0af934;
P_0c0af934: /* original 6df6, guest PC 0x0c0af934 */
if(!s->budget--) { s->failed_pc=0x0c0af934u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0af936;
P_0c0af936: /* original 7e02, guest PC 0x0c0af936 */
if(!s->budget--) { s->failed_pc=0x0c0af936u; return 0; }
r[14]+=0x00000002u;
goto P_0c0af938;
P_0c0af938: /* original 67e3, guest PC 0x0c0af938 */
if(!s->budget--) { s->failed_pc=0x0c0af938u; return 0; }
r[7]=r[14];
goto P_0c0af93a;
P_0c0af93a: /* original a00d, guest PC 0x0c0af93a */
if(!s->budget--) { s->failed_pc=0x0c0af93au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0af958;
P_0c0af93c: /* original 6ef6, guest PC 0x0c0af93c */
if(!s->budget--) { s->failed_pc=0x0c0af93cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af93eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af93eu; return 0; } return 1;
P_0c0af958: /* original 2fe6, guest PC 0x0c0af958 */
if(!s->budget--) { s->failed_pc=0x0c0af958u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0af95a;
P_0c0af95a: /* original 6e43, guest PC 0x0c0af95a */
if(!s->budget--) { s->failed_pc=0x0c0af95au; return 0; }
r[14]=r[4];
goto P_0c0af95c;
P_0c0af95c: /* original 4f22, guest PC 0x0c0af95c */
if(!s->budget--) { s->failed_pc=0x0c0af95cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af95e;
P_0c0af95e: /* original 4f12, guest PC 0x0c0af95e */
if(!s->budget--) { s->failed_pc=0x0c0af95eu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0af960;
P_0c0af960: /* original 7ff8, guest PC 0x0c0af960 */
if(!s->budget--) { s->failed_pc=0x0c0af960u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af962;
P_0c0af962: /* original 2f62, guest PC 0x0c0af962 */
if(!s->budget--) { s->failed_pc=0x0c0af962u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0af964;
P_0c0af964: /* original 1f71, guest PC 0x0c0af964 */
if(!s->budget--) { s->failed_pc=0x0c0af964u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c0af966;
P_0c0af966: /* original 900f, guest PC 0x0c0af966 */
if(!s->budget--) { s->failed_pc=0x0c0af966u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0af988u,2);
goto P_0c0af968;
P_0c0af968: /* original d30b, guest PC 0x0c0af968 */
if(!s->budget--) { s->failed_pc=0x0c0af968u; return 0; }
r[3]=read(ram,0x0c0af998u,4);
goto P_0c0af96a;
P_0c0af96a: /* original 02ee, guest PC 0x0c0af96a */
if(!s->budget--) { s->failed_pc=0x0c0af96au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0af96c;
P_0c0af96c: /* original 2238, guest PC 0x0c0af96c */
if(!s->budget--) { s->failed_pc=0x0c0af96cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0af96e;
P_0c0af96e: /* original 8915, guest PC 0x0c0af96e */
if(!s->budget--) { s->failed_pc=0x0c0af96eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0af99c; }
goto P_0c0af970;
P_0c0af970: /* original 7f08, guest PC 0x0c0af970 */
if(!s->budget--) { s->failed_pc=0x0c0af970u; return 0; }
r[15]+=0x00000008u;
goto P_0c0af972;
P_0c0af972: /* original d208, guest PC 0x0c0af972 */
if(!s->budget--) { s->failed_pc=0x0c0af972u; return 0; }
r[2]=read(ram,0x0c0af994u,4);
goto P_0c0af974;
P_0c0af974: /* original 4f16, guest PC 0x0c0af974 */
if(!s->budget--) { s->failed_pc=0x0c0af974u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af976;
P_0c0af976: /* original 64e3, guest PC 0x0c0af976 */
if(!s->budget--) { s->failed_pc=0x0c0af976u; return 0; }
r[4]=r[14];
goto P_0c0af978;
P_0c0af978: /* original 4f26, guest PC 0x0c0af978 */
if(!s->budget--) { s->failed_pc=0x0c0af978u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af97a;
P_0c0af97a: /* original 422b, guest PC 0x0c0af97a */
if(!s->budget--) { s->failed_pc=0x0c0af97au; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c0af97c: /* original 6ef6, guest PC 0x0c0af97c */
if(!s->budget--) { s->failed_pc=0x0c0af97cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af97eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af97eu; return 0; } return 1;
P_0c0af99c: /* original e048, guest PC 0x0c0af99c */
if(!s->budget--) { s->failed_pc=0x0c0af99cu; return 0; }
r[0]=0x00000048u;
goto P_0c0af99e;
P_0c0af99e: /* original d349, guest PC 0x0c0af99e */
if(!s->budget--) { s->failed_pc=0x0c0af99eu; return 0; }
r[3]=read(ram,0x0c0afac4u,4);
goto P_0c0af9a0;
P_0c0af9a0: /* original 02ee, guest PC 0x0c0af9a0 */
if(!s->budget--) { s->failed_pc=0x0c0af9a0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0af9a2;
P_0c0af9a2: /* original 223b, guest PC 0x0c0af9a2 */
if(!s->budget--) { s->failed_pc=0x0c0af9a2u; return 0; }
r[2]|=r[3];
goto P_0c0af9a4;
P_0c0af9a4: /* original 0e26, guest PC 0x0c0af9a4 */
if(!s->budget--) { s->failed_pc=0x0c0af9a4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0af9a6;
P_0c0af9a6: /* original d148, guest PC 0x0c0af9a6 */
if(!s->budget--) { s->failed_pc=0x0c0af9a6u; return 0; }
r[1]=read(ram,0x0c0afac8u,4);
goto P_0c0af9a8;
P_0c0af9a8: /* original 410b, guest PC 0x0c0af9a8 */
if(!s->budget--) { s->failed_pc=0x0c0af9a8u; return 0; }
target=r[1];
r[16]=code_base|0x0c0af9acu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af9acu) { target=s->pc; goto dispatch; }
goto P_0c0af9ac;
P_0c0af9aa: /* original 64e3, guest PC 0x0c0af9aa */
if(!s->budget--) { s->failed_pc=0x0c0af9aau; return 0; }
r[4]=r[14];
goto P_0c0af9ac;
P_0c0af9ac: /* original 9084, guest PC 0x0c0af9ac */
if(!s->budget--) { s->failed_pc=0x0c0af9acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afab8u,2);
goto P_0c0af9ae;
P_0c0af9ae: /* original 53f1, guest PC 0x0c0af9ae */
if(!s->budget--) { s->failed_pc=0x0c0af9aeu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0af9b0;
P_0c0af9b0: /* original 04ed, guest PC 0x0c0af9b0 */
if(!s->budget--) { s->failed_pc=0x0c0af9b0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0af9b2;
P_0c0af9b2: /* original d246, guest PC 0x0c0af9b2 */
if(!s->budget--) { s->failed_pc=0x0c0af9b2u; return 0; }
r[2]=read(ram,0x0c0afaccu,4);
goto P_0c0af9b4;
P_0c0af9b4: /* original 644d, guest PC 0x0c0af9b4 */
if(!s->budget--) { s->failed_pc=0x0c0af9b4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0af9b6;
P_0c0af9b6: /* original 60f2, guest PC 0x0c0af9b6 */
if(!s->budget--) { s->failed_pc=0x0c0af9b6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0af9b8;
P_0c0af9b8: /* original 0347, guest PC 0x0c0af9b8 */
if(!s->budget--) { s->failed_pc=0x0c0af9b8u; return 0; }
r[19]=r[3]*r[4];
goto P_0c0af9ba;
P_0c0af9ba: /* original 041a, guest PC 0x0c0af9ba */
if(!s->budget--) { s->failed_pc=0x0c0af9bau; return 0; }
r[4]=r[19];
goto P_0c0af9bc;
P_0c0af9bc: /* original 420b, guest PC 0x0c0af9bc */
if(!s->budget--) { s->failed_pc=0x0c0af9bcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0af9c0u;
r[1]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0af9c0u) { target=s->pc; goto dispatch; }
goto P_0c0af9c0;
P_0c0af9be: /* original 6143, guest PC 0x0c0af9be */
if(!s->budget--) { s->failed_pc=0x0c0af9beu; return 0; }
r[1]=r[4];
goto P_0c0af9c0;
P_0c0af9c0: /* original 7f08, guest PC 0x0c0af9c0 */
if(!s->budget--) { s->failed_pc=0x0c0af9c0u; return 0; }
r[15]+=0x00000008u;
goto P_0c0af9c2;
P_0c0af9c2: /* original 6403, guest PC 0x0c0af9c2 */
if(!s->budget--) { s->failed_pc=0x0c0af9c2u; return 0; }
r[4]=r[0];
goto P_0c0af9c4;
P_0c0af9c4: /* original 4f16, guest PC 0x0c0af9c4 */
if(!s->budget--) { s->failed_pc=0x0c0af9c4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af9c6;
P_0c0af9c6: /* original e03e, guest PC 0x0c0af9c6 */
if(!s->budget--) { s->failed_pc=0x0c0af9c6u; return 0; }
r[0]=0x0000003eu;
goto P_0c0af9c8;
P_0c0af9c8: /* original 0e45, guest PC 0x0c0af9c8 */
if(!s->budget--) { s->failed_pc=0x0c0af9c8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0af9ca;
P_0c0af9ca: /* original 4f26, guest PC 0x0c0af9ca */
if(!s->budget--) { s->failed_pc=0x0c0af9cau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0af9cc;
P_0c0af9cc: /* original 000b, guest PC 0x0c0af9cc */
if(!s->budget--) { s->failed_pc=0x0c0af9ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0af9ce: /* original 6ef6, guest PC 0x0c0af9ce */
if(!s->budget--) { s->failed_pc=0x0c0af9ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0af9d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0af9d0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
