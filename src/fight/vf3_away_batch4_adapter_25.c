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
int vf3_away_batch4_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c0544c8u: goto P_0c0544c8;
case 0x0c0544cau: goto P_0c0544ca;
case 0x0c0544ccu: goto P_0c0544cc;
case 0x0c0544ceu: goto P_0c0544ce;
case 0x0c0544d0u: goto P_0c0544d0;
case 0x0c0544d2u: goto P_0c0544d2;
case 0x0c0544d4u: goto P_0c0544d4;
case 0x0c0544d6u: goto P_0c0544d6;
case 0x0c0544d8u: goto P_0c0544d8;
case 0x0c0544dau: goto P_0c0544da;
case 0x0c0544dcu: goto P_0c0544dc;
case 0x0c0544deu: goto P_0c0544de;
case 0x0c0544e0u: goto P_0c0544e0;
case 0x0c0544e2u: goto P_0c0544e2;
case 0x0c0544e4u: goto P_0c0544e4;
case 0x0c0544e6u: goto P_0c0544e6;
case 0x0c0544e8u: goto P_0c0544e8;
case 0x0c0544eau: goto P_0c0544ea;
case 0x0c0544ecu: goto P_0c0544ec;
case 0x0c0544eeu: goto P_0c0544ee;
case 0x0c0544f0u: goto P_0c0544f0;
case 0x0c0544f2u: goto P_0c0544f2;
case 0x0c0544f4u: goto P_0c0544f4;
case 0x0c0544f6u: goto P_0c0544f6;
case 0x0c0544f8u: goto P_0c0544f8;
case 0x0c0544fau: goto P_0c0544fa;
case 0x0c0544fcu: goto P_0c0544fc;
case 0x0c0544feu: goto P_0c0544fe;
case 0x0c054500u: goto P_0c054500;
case 0x0c054502u: goto P_0c054502;
case 0x0c054504u: goto P_0c054504;
case 0x0c054506u: goto P_0c054506;
case 0x0c054508u: goto P_0c054508;
case 0x0c05450au: goto P_0c05450a;
case 0x0c05450cu: goto P_0c05450c;
case 0x0c05450eu: goto P_0c05450e;
case 0x0c054510u: goto P_0c054510;
case 0x0c054512u: goto P_0c054512;
case 0x0c054514u: goto P_0c054514;
case 0x0c054516u: goto P_0c054516;
case 0x0c054518u: goto P_0c054518;
case 0x0c05451au: goto P_0c05451a;
case 0x0c05451cu: goto P_0c05451c;
case 0x0c05451eu: goto P_0c05451e;
case 0x0c054520u: goto P_0c054520;
case 0x0c054522u: goto P_0c054522;
case 0x0c054524u: goto P_0c054524;
case 0x0c054526u: goto P_0c054526;
case 0x0c054528u: goto P_0c054528;
case 0x0c05452au: goto P_0c05452a;
case 0x0c05452cu: goto P_0c05452c;
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
P_0c0544c8: /* original 24f2, guest PC 0x0c0544c8 */
if(!s->budget--) { s->failed_pc=0x0c0544c8u; return 0; }
write(ram,r[4],r[15],4);
goto P_0c0544ca;
P_0c0544ca: /* original 14e1, guest PC 0x0c0544ca */
if(!s->budget--) { s->failed_pc=0x0c0544cau; return 0; }
write(ram,r[4]+4,r[14],4);
goto P_0c0544cc;
P_0c0544cc: /* original 0e2a, guest PC 0x0c0544cc */
if(!s->budget--) { s->failed_pc=0x0c0544ccu; return 0; }
r[14]=r[16];
goto P_0c0544ce;
P_0c0544ce: /* original 14e2, guest PC 0x0c0544ce */
if(!s->budget--) { s->failed_pc=0x0c0544ceu; return 0; }
write(ram,r[4]+8,r[14],4);
goto P_0c0544d0;
P_0c0544d0: /* original 5e41, guest PC 0x0c0544d0 */
if(!s->budget--) { s->failed_pc=0x0c0544d0u; return 0; }
r[14]=read(ram,r[4]+4,4);
goto P_0c0544d2;
P_0c0544d2: /* original 14d3, guest PC 0x0c0544d2 */
if(!s->budget--) { s->failed_pc=0x0c0544d2u; return 0; }
write(ram,r[4]+12,r[13],4);
goto P_0c0544d4;
P_0c0544d4: /* original 14c4, guest PC 0x0c0544d4 */
if(!s->budget--) { s->failed_pc=0x0c0544d4u; return 0; }
write(ram,r[4]+16,r[12],4);
goto P_0c0544d6;
P_0c0544d6: /* original 14b5, guest PC 0x0c0544d6 */
if(!s->budget--) { s->failed_pc=0x0c0544d6u; return 0; }
write(ram,r[4]+20,r[11],4);
goto P_0c0544d8;
P_0c0544d8: /* original 14a6, guest PC 0x0c0544d8 */
if(!s->budget--) { s->failed_pc=0x0c0544d8u; return 0; }
write(ram,r[4]+24,r[10],4);
goto P_0c0544da;
P_0c0544da: /* original 1497, guest PC 0x0c0544da */
if(!s->budget--) { s->failed_pc=0x0c0544dau; return 0; }
write(ram,r[4]+28,r[9],4);
goto P_0c0544dc;
P_0c0544dc: /* original 1488, guest PC 0x0c0544dc */
if(!s->budget--) { s->failed_pc=0x0c0544dcu; return 0; }
write(ram,r[4]+32,r[8],4);
goto P_0c0544de;
P_0c0544de: /* original 1479, guest PC 0x0c0544de */
if(!s->budget--) { s->failed_pc=0x0c0544deu; return 0; }
write(ram,r[4]+36,r[7],4);
goto P_0c0544e0;
P_0c0544e0: /* original 146a, guest PC 0x0c0544e0 */
if(!s->budget--) { s->failed_pc=0x0c0544e0u; return 0; }
write(ram,r[4]+40,r[6],4);
goto P_0c0544e2;
P_0c0544e2: /* original 145b, guest PC 0x0c0544e2 */
if(!s->budget--) { s->failed_pc=0x0c0544e2u; return 0; }
write(ram,r[4]+44,r[5],4);
goto P_0c0544e4;
P_0c0544e4: /* original 144c, guest PC 0x0c0544e4 */
if(!s->budget--) { s->failed_pc=0x0c0544e4u; return 0; }
write(ram,r[4]+48,r[4],4);
goto P_0c0544e6;
P_0c0544e6: /* original 7430, guest PC 0x0c0544e6 */
if(!s->budget--) { s->failed_pc=0x0c0544e6u; return 0; }
r[4]+=0x00000030u;
goto P_0c0544e8;
P_0c0544e8: /* original 1431, guest PC 0x0c0544e8 */
if(!s->budget--) { s->failed_pc=0x0c0544e8u; return 0; }
write(ram,r[4]+4,r[3],4);
goto P_0c0544ea;
P_0c0544ea: /* original 1422, guest PC 0x0c0544ea */
if(!s->budget--) { s->failed_pc=0x0c0544eau; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c0544ec;
P_0c0544ec: /* original 1413, guest PC 0x0c0544ec */
if(!s->budget--) { s->failed_pc=0x0c0544ecu; return 0; }
write(ram,r[4]+12,r[1],4);
goto P_0c0544ee;
P_0c0544ee: /* original 1404, guest PC 0x0c0544ee */
if(!s->budget--) { s->failed_pc=0x0c0544eeu; return 0; }
write(ram,r[4]+16,r[0],4);
goto P_0c0544f0;
P_0c0544f0: /* original 000a, guest PC 0x0c0544f0 */
if(!s->budget--) { s->failed_pc=0x0c0544f0u; return 0; }
r[0]=r[20];
goto P_0c0544f2;
P_0c0544f2: /* original 1405, guest PC 0x0c0544f2 */
if(!s->budget--) { s->failed_pc=0x0c0544f2u; return 0; }
write(ram,r[4]+20,r[0],4);
goto P_0c0544f4;
P_0c0544f4: /* original 001a, guest PC 0x0c0544f4 */
if(!s->budget--) { s->failed_pc=0x0c0544f4u; return 0; }
r[0]=r[19];
goto P_0c0544f6;
P_0c0544f6: /* original 1406, guest PC 0x0c0544f6 */
if(!s->budget--) { s->failed_pc=0x0c0544f6u; return 0; }
write(ram,r[4]+24,r[0],4);
goto P_0c0544f8;
P_0c0544f8: /* original 0012, guest PC 0x0c0544f8 */
if(!s->budget--) { s->failed_pc=0x0c0544f8u; return 0; }
if(!s->gbr_known) goto unsupported;
r[0]=s->gbr;
goto P_0c0544fa;
P_0c0544fa: /* original 1407, guest PC 0x0c0544fa */
if(!s->budget--) { s->failed_pc=0x0c0544fau; return 0; }
write(ram,r[4]+28,r[0],4);
goto P_0c0544fc;
P_0c0544fc: /* original 745c, guest PC 0x0c0544fc */
if(!s->budget--) { s->failed_pc=0x0c0544fcu; return 0; }
r[4]+=0x0000005cu;
goto P_0c0544fe;
P_0c0544fe: /* original 006a, guest PC 0x0c0544fe */
if(!s->budget--) { s->failed_pc=0x0c0544feu; return 0; }
r[0]=r[18];
goto P_0c054500;
P_0c054500: /* original 1402, guest PC 0x0c054500 */
if(!s->budget--) { s->failed_pc=0x0c054500u; return 0; }
write(ram,r[4]+8,r[0],4);
goto P_0c054502;
P_0c054502: /* original 005a, guest PC 0x0c054502 */
if(!s->budget--) { s->failed_pc=0x0c054502u; return 0; }
r[0]=r[53];
goto P_0c054504;
P_0c054504: /* original 1401, guest PC 0x0c054504 */
if(!s->budget--) { s->failed_pc=0x0c054504u; return 0; }
write(ram,r[4]+4,r[0],4);
goto P_0c054506;
P_0c054506: /* original f4fa, guest PC 0x0c054506 */
if(!s->budget--) { s->failed_pc=0x0c054506u; return 0; }
vf3_matrix_store(s,ram,15,r[4]);
goto P_0c054508;
P_0c054508: /* original f4eb, guest PC 0x0c054508 */
if(!s->budget--) { s->failed_pc=0x0c054508u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[4]);
goto P_0c05450a;
P_0c05450a: /* original f4db, guest PC 0x0c05450a */
if(!s->budget--) { s->failed_pc=0x0c05450au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[4]);
goto P_0c05450c;
P_0c05450c: /* original f4cb, guest PC 0x0c05450c */
if(!s->budget--) { s->failed_pc=0x0c05450cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[4]);
goto P_0c05450e;
P_0c05450e: /* original f4bb, guest PC 0x0c05450e */
if(!s->budget--) { s->failed_pc=0x0c05450eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,11,r[4]);
goto P_0c054510;
P_0c054510: /* original f4ab, guest PC 0x0c054510 */
if(!s->budget--) { s->failed_pc=0x0c054510u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c054512;
P_0c054512: /* original f49b, guest PC 0x0c054512 */
if(!s->budget--) { s->failed_pc=0x0c054512u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c054514;
P_0c054514: /* original f48b, guest PC 0x0c054514 */
if(!s->budget--) { s->failed_pc=0x0c054514u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,8,r[4]);
goto P_0c054516;
P_0c054516: /* original f47b, guest PC 0x0c054516 */
if(!s->budget--) { s->failed_pc=0x0c054516u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c054518;
P_0c054518: /* original f46b, guest PC 0x0c054518 */
if(!s->budget--) { s->failed_pc=0x0c054518u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c05451a;
P_0c05451a: /* original f43b, guest PC 0x0c05451a */
if(!s->budget--) { s->failed_pc=0x0c05451au; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c05451c;
P_0c05451c: /* original f44b, guest PC 0x0c05451c */
if(!s->budget--) { s->failed_pc=0x0c05451cu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c05451e;
P_0c05451e: /* original f45b, guest PC 0x0c05451e */
if(!s->budget--) { s->failed_pc=0x0c05451eu; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[4]);
goto P_0c054520;
P_0c054520: /* original f42b, guest PC 0x0c054520 */
if(!s->budget--) { s->failed_pc=0x0c054520u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[4]);
goto P_0c054522;
P_0c054522: /* original f41b, guest PC 0x0c054522 */
if(!s->budget--) { s->failed_pc=0x0c054522u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[4]);
goto P_0c054524;
P_0c054524: /* original f40b, guest PC 0x0c054524 */
if(!s->budget--) { s->failed_pc=0x0c054524u; return 0; }
r[4]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,0,r[4]);
goto P_0c054526;
P_0c054526: /* original 74e0, guest PC 0x0c054526 */
if(!s->budget--) { s->failed_pc=0x0c054526u; return 0; }
r[4]+=0xffffffe0u;
goto P_0c054528;
P_0c054528: /* original 6442, guest PC 0x0c054528 */
if(!s->budget--) { s->failed_pc=0x0c054528u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05452a;
P_0c05452a: /* original 000b, guest PC 0x0c05452a */
if(!s->budget--) { s->failed_pc=0x0c05452au; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05452c: /* original e000, guest PC 0x0c05452c */
if(!s->budget--) { s->failed_pc=0x0c05452cu; return 0; }
r[0]=0x00000000u;
if(!vf3_matrix_family(0x0c05452eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05452eu; return 0; } return 1;
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
