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
int vf3_away_batch5_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c053cdau: goto P_0c053cda;
case 0x0c053cdcu: goto P_0c053cdc;
case 0x0c053cdeu: goto P_0c053cde;
case 0x0c053ce0u: goto P_0c053ce0;
case 0x0c053ce2u: goto P_0c053ce2;
case 0x0c053ce4u: goto P_0c053ce4;
case 0x0c053ce6u: goto P_0c053ce6;
case 0x0c053ce8u: goto P_0c053ce8;
case 0x0c053ceau: goto P_0c053cea;
case 0x0c053cecu: goto P_0c053cec;
case 0x0c053ceeu: goto P_0c053cee;
case 0x0c053cf0u: goto P_0c053cf0;
case 0x0c053cf2u: goto P_0c053cf2;
case 0x0c053cf4u: goto P_0c053cf4;
case 0x0c053cf6u: goto P_0c053cf6;
case 0x0c053cf8u: goto P_0c053cf8;
case 0x0c053cfau: goto P_0c053cfa;
case 0x0c053cfcu: goto P_0c053cfc;
case 0x0c053cfeu: goto P_0c053cfe;
case 0x0c053d00u: goto P_0c053d00;
case 0x0c053d02u: goto P_0c053d02;
case 0x0c053d04u: goto P_0c053d04;
case 0x0c053d06u: goto P_0c053d06;
case 0x0c053d08u: goto P_0c053d08;
case 0x0c053d0au: goto P_0c053d0a;
case 0x0c053d0cu: goto P_0c053d0c;
case 0x0c053d0eu: goto P_0c053d0e;
case 0x0c053d10u: goto P_0c053d10;
case 0x0c053d12u: goto P_0c053d12;
case 0x0c053d14u: goto P_0c053d14;
case 0x0c053d16u: goto P_0c053d16;
case 0x0c053d18u: goto P_0c053d18;
case 0x0c053d1au: goto P_0c053d1a;
case 0x0c053d1cu: goto P_0c053d1c;
case 0x0c053d1eu: goto P_0c053d1e;
case 0x0c053d20u: goto P_0c053d20;
case 0x0c053d22u: goto P_0c053d22;
case 0x0c053d24u: goto P_0c053d24;
case 0x0c053d26u: goto P_0c053d26;
case 0x0c053d28u: goto P_0c053d28;
case 0x0c053d2au: goto P_0c053d2a;
case 0x0c053d2cu: goto P_0c053d2c;
case 0x0c053d2eu: goto P_0c053d2e;
case 0x0c060f14u: goto P_0c060f14;
case 0x0c060f16u: goto P_0c060f16;
case 0x0c060f18u: goto P_0c060f18;
case 0x0c060f1au: goto P_0c060f1a;
case 0x0c060f1cu: goto P_0c060f1c;
case 0x0c060f1eu: goto P_0c060f1e;
case 0x0c060f20u: goto P_0c060f20;
case 0x0c060f22u: goto P_0c060f22;
case 0x0c060f24u: goto P_0c060f24;
case 0x0c060f26u: goto P_0c060f26;
default: return vf3_matrix_family(target,s,ram);
}
P_0c053cda: /* original e001, guest PC 0x0c053cda */
if(!s->budget--) { s->failed_pc=0x0c053cdau; return 0; }
r[0]=0x00000001u;
goto P_0c053cdc;
P_0c053cdc: /* original 7f04, guest PC 0x0c053cdc */
if(!s->budget--) { s->failed_pc=0x0c053cdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c053cde;
P_0c053cde: /* original 4f26, guest PC 0x0c053cde */
if(!s->budget--) { s->failed_pc=0x0c053cdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053ce0;
P_0c053ce0: /* original 000b, guest PC 0x0c053ce0 */
if(!s->budget--) { s->failed_pc=0x0c053ce0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053ce2: /* original 6ef6, guest PC 0x0c053ce2 */
if(!s->budget--) { s->failed_pc=0x0c053ce2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053ce4;
P_0c053ce4: /* original 2fe6, guest PC 0x0c053ce4 */
if(!s->budget--) { s->failed_pc=0x0c053ce4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c053ce6;
P_0c053ce6: /* original 6e43, guest PC 0x0c053ce6 */
if(!s->budget--) { s->failed_pc=0x0c053ce6u; return 0; }
r[14]=r[4];
goto P_0c053ce8;
P_0c053ce8: /* original d016, guest PC 0x0c053ce8 */
if(!s->budget--) { s->failed_pc=0x0c053ce8u; return 0; }
r[0]=read(ram,0x0c053d44u,4);
goto P_0c053cea;
P_0c053cea: /* original 4e08, guest PC 0x0c053cea */
if(!s->budget--) { s->failed_pc=0x0c053ceau; return 0; }
r[14]<<=2;
goto P_0c053cec;
P_0c053cec: /* original 4f22, guest PC 0x0c053cec */
if(!s->budget--) { s->failed_pc=0x0c053cecu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c053cee;
P_0c053cee: /* original 0eee, guest PC 0x0c053cee */
if(!s->budget--) { s->failed_pc=0x0c053ceeu; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c053cf0;
P_0c053cf0: /* original d315, guest PC 0x0c053cf0 */
if(!s->budget--) { s->failed_pc=0x0c053cf0u; return 0; }
r[3]=read(ram,0x0c053d48u,4);
goto P_0c053cf2;
P_0c053cf2: /* original 7ff8, guest PC 0x0c053cf2 */
if(!s->budget--) { s->failed_pc=0x0c053cf2u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c053cf4;
P_0c053cf4: /* original 430b, guest PC 0x0c053cf4 */
if(!s->budget--) { s->failed_pc=0x0c053cf4u; return 0; }
target=r[3];
r[16]=code_base|0x0c053cf8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053cf8u) { target=s->pc; goto dispatch; }
goto P_0c053cf8;
P_0c053cf6: /* original 64e3, guest PC 0x0c053cf6 */
if(!s->budget--) { s->failed_pc=0x0c053cf6u; return 0; }
r[4]=r[14];
goto P_0c053cf8;
P_0c053cf8: /* original 1f01, guest PC 0x0c053cf8 */
if(!s->budget--) { s->failed_pc=0x0c053cf8u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c053cfa;
P_0c053cfa: /* original d314, guest PC 0x0c053cfa */
if(!s->budget--) { s->failed_pc=0x0c053cfau; return 0; }
r[3]=read(ram,0x0c053d4cu,4);
goto P_0c053cfc;
P_0c053cfc: /* original 430b, guest PC 0x0c053cfc */
if(!s->budget--) { s->failed_pc=0x0c053cfcu; return 0; }
target=r[3];
r[16]=code_base|0x0c053d00u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053d00u) { target=s->pc; goto dispatch; }
goto P_0c053d00;
P_0c053cfe: /* original 64e3, guest PC 0x0c053cfe */
if(!s->budget--) { s->failed_pc=0x0c053cfeu; return 0; }
r[4]=r[14];
goto P_0c053d00;
P_0c053d00: /* original 2f02, guest PC 0x0c053d00 */
if(!s->budget--) { s->failed_pc=0x0c053d00u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c053d02;
P_0c053d02: /* original 53f1, guest PC 0x0c053d02 */
if(!s->budget--) { s->failed_pc=0x0c053d02u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c053d04;
P_0c053d04: /* original 6230, guest PC 0x0c053d04 */
if(!s->budget--) { s->failed_pc=0x0c053d04u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c053d06;
P_0c053d06: /* original 2228, guest PC 0x0c053d06 */
if(!s->budget--) { s->failed_pc=0x0c053d06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c053d08;
P_0c053d08: /* original 8908, guest PC 0x0c053d08 */
if(!s->budget--) { s->failed_pc=0x0c053d08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c053d1c; }
goto P_0c053d0a;
P_0c053d0a: /* original d311, guest PC 0x0c053d0a */
if(!s->budget--) { s->failed_pc=0x0c053d0au; return 0; }
r[3]=read(ram,0x0c053d50u,4);
goto P_0c053d0c;
P_0c053d0c: /* original 430b, guest PC 0x0c053d0c */
if(!s->budget--) { s->failed_pc=0x0c053d0cu; return 0; }
target=r[3];
r[16]=code_base|0x0c053d10u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c053d10u) { target=s->pc; goto dispatch; }
goto P_0c053d10;
P_0c053d0e: /* original 64e3, guest PC 0x0c053d0e */
if(!s->budget--) { s->failed_pc=0x0c053d0eu; return 0; }
r[4]=r[14];
goto P_0c053d10;
P_0c053d10: /* original 2008, guest PC 0x0c053d10 */
if(!s->budget--) { s->failed_pc=0x0c053d10u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c053d12;
P_0c053d12: /* original 8b03, guest PC 0x0c053d12 */
if(!s->budget--) { s->failed_pc=0x0c053d12u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053d1c; }
goto P_0c053d14;
P_0c053d14: /* original 60f2, guest PC 0x0c053d14 */
if(!s->budget--) { s->failed_pc=0x0c053d14u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c053d16;
P_0c053d16: /* original 6002, guest PC 0x0c053d16 */
if(!s->budget--) { s->failed_pc=0x0c053d16u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c053d18;
P_0c053d18: /* original c802, guest PC 0x0c053d18 */
if(!s->budget--) { s->failed_pc=0x0c053d18u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c053d1a;
P_0c053d1a: /* original 8b04, guest PC 0x0c053d1a */
if(!s->budget--) { s->failed_pc=0x0c053d1au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c053d26; }
goto P_0c053d1c;
P_0c053d1c: /* original 7f08, guest PC 0x0c053d1c */
if(!s->budget--) { s->failed_pc=0x0c053d1cu; return 0; }
r[15]+=0x00000008u;
goto P_0c053d1e;
P_0c053d1e: /* original 4f26, guest PC 0x0c053d1e */
if(!s->budget--) { s->failed_pc=0x0c053d1eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053d20;
P_0c053d20: /* original e000, guest PC 0x0c053d20 */
if(!s->budget--) { s->failed_pc=0x0c053d20u; return 0; }
r[0]=0x00000000u;
goto P_0c053d22;
P_0c053d22: /* original 000b, guest PC 0x0c053d22 */
if(!s->budget--) { s->failed_pc=0x0c053d22u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053d24: /* original 6ef6, guest PC 0x0c053d24 */
if(!s->budget--) { s->failed_pc=0x0c053d24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c053d26;
P_0c053d26: /* original e001, guest PC 0x0c053d26 */
if(!s->budget--) { s->failed_pc=0x0c053d26u; return 0; }
r[0]=0x00000001u;
goto P_0c053d28;
P_0c053d28: /* original 7f08, guest PC 0x0c053d28 */
if(!s->budget--) { s->failed_pc=0x0c053d28u; return 0; }
r[15]+=0x00000008u;
goto P_0c053d2a;
P_0c053d2a: /* original 4f26, guest PC 0x0c053d2a */
if(!s->budget--) { s->failed_pc=0x0c053d2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c053d2c;
P_0c053d2c: /* original 000b, guest PC 0x0c053d2c */
if(!s->budget--) { s->failed_pc=0x0c053d2cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c053d2e: /* original 6ef6, guest PC 0x0c053d2e */
if(!s->budget--) { s->failed_pc=0x0c053d2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c053d30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c053d30u; return 0; } return 1;
P_0c060f14: /* original 6042, guest PC 0x0c060f14 */
if(!s->budget--) { s->failed_pc=0x0c060f14u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c060f16;
P_0c060f16: /* original 6108, guest PC 0x0c060f16 */
if(!s->budget--) { s->failed_pc=0x0c060f16u; return 0; }
r[1]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c060f18;
P_0c060f18: /* original 6019, guest PC 0x0c060f18 */
if(!s->budget--) { s->failed_pc=0x0c060f18u; return 0; }
r[0]=(r[1]<<16)|(r[1]>>16);
goto P_0c060f1a;
P_0c060f1a: /* original 6108, guest PC 0x0c060f1a */
if(!s->budget--) { s->failed_pc=0x0c060f1au; return 0; }
r[1]=(r[0]&0xffff0000u)|((r[0]&255u)<<8)|((r[0]>>8)&255u);
goto P_0c060f1c;
P_0c060f1c: /* original 4510, guest PC 0x0c060f1c */
if(!s->budget--) { s->failed_pc=0x0c060f1cu; return 0; }
--r[5];
r[17]=(r[17]&~1u)|((r[5]==0)!=0);
goto P_0c060f1e;
P_0c060f1e: /* original 2412, guest PC 0x0c060f1e */
if(!s->budget--) { s->failed_pc=0x0c060f1eu; return 0; }
write(ram,r[4],r[1],4);
goto P_0c060f20;
P_0c060f20: /* original 8ff8, guest PC 0x0c060f20 */
if(!s->budget--) { s->failed_pc=0x0c060f20u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c060f14; }
goto P_0c060f24;
P_0c060f22: /* original 7404, guest PC 0x0c060f22 */
if(!s->budget--) { s->failed_pc=0x0c060f22u; return 0; }
r[4]+=0x00000004u;
goto P_0c060f24;
P_0c060f24: /* original 000b, guest PC 0x0c060f24 */
if(!s->budget--) { s->failed_pc=0x0c060f24u; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c060f26: /* original e000, guest PC 0x0c060f26 */
if(!s->budget--) { s->failed_pc=0x0c060f26u; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c060f28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c060f28u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
