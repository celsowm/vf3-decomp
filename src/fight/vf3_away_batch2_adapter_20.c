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
int vf3_away_batch2_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c062bfau: goto P_0c062bfa;
case 0x0c062bfcu: goto P_0c062bfc;
case 0x0c062bfeu: goto P_0c062bfe;
case 0x0c062c00u: goto P_0c062c00;
case 0x0c062c02u: goto P_0c062c02;
case 0x0c062c04u: goto P_0c062c04;
case 0x0c062c06u: goto P_0c062c06;
case 0x0c062c08u: goto P_0c062c08;
case 0x0c062c0au: goto P_0c062c0a;
case 0x0c062c0cu: goto P_0c062c0c;
case 0x0c062c0eu: goto P_0c062c0e;
case 0x0c062c10u: goto P_0c062c10;
case 0x0c062c12u: goto P_0c062c12;
case 0x0c062c14u: goto P_0c062c14;
case 0x0c062c16u: goto P_0c062c16;
case 0x0c062c18u: goto P_0c062c18;
case 0x0c062c1au: goto P_0c062c1a;
case 0x0c062c1cu: goto P_0c062c1c;
case 0x0c062c1eu: goto P_0c062c1e;
case 0x0c062c20u: goto P_0c062c20;
case 0x0c062c22u: goto P_0c062c22;
case 0x0c062c24u: goto P_0c062c24;
case 0x0c062c26u: goto P_0c062c26;
case 0x0c062c28u: goto P_0c062c28;
case 0x0c062c2au: goto P_0c062c2a;
case 0x0c062c2cu: goto P_0c062c2c;
case 0x0c062c2eu: goto P_0c062c2e;
case 0x0c062c30u: goto P_0c062c30;
case 0x0c062c32u: goto P_0c062c32;
case 0x0c062c34u: goto P_0c062c34;
case 0x0c062c36u: goto P_0c062c36;
case 0x0c062c38u: goto P_0c062c38;
case 0x0c062c3au: goto P_0c062c3a;
case 0x0c062c3cu: goto P_0c062c3c;
case 0x0c062c3eu: goto P_0c062c3e;
case 0x0c062c40u: goto P_0c062c40;
case 0x0c062c42u: goto P_0c062c42;
case 0x0c062c44u: goto P_0c062c44;
case 0x0c062c46u: goto P_0c062c46;
case 0x0c062c48u: goto P_0c062c48;
case 0x0c062c4au: goto P_0c062c4a;
case 0x0c062c4cu: goto P_0c062c4c;
case 0x0c062c4eu: goto P_0c062c4e;
case 0x0c062c50u: goto P_0c062c50;
case 0x0c062c52u: goto P_0c062c52;
case 0x0c062c54u: goto P_0c062c54;
case 0x0c062c56u: goto P_0c062c56;
case 0x0c062c58u: goto P_0c062c58;
case 0x0c062c5au: goto P_0c062c5a;
case 0x0c062c5cu: goto P_0c062c5c;
case 0x0c062c5eu: goto P_0c062c5e;
case 0x0c062c60u: goto P_0c062c60;
case 0x0c0644bcu: goto P_0c0644bc;
case 0x0c0644beu: goto P_0c0644be;
case 0x0c0644c0u: goto P_0c0644c0;
case 0x0c0644c2u: goto P_0c0644c2;
case 0x0c0644c4u: goto P_0c0644c4;
case 0x0c0644c6u: goto P_0c0644c6;
case 0x0c0644c8u: goto P_0c0644c8;
case 0x0c0644cau: goto P_0c0644ca;
case 0x0c0644ccu: goto P_0c0644cc;
case 0x0c0644ceu: goto P_0c0644ce;
case 0x0c0644d0u: goto P_0c0644d0;
case 0x0c0644d2u: goto P_0c0644d2;
case 0x0c0644d4u: goto P_0c0644d4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c062bfa: /* original e700, guest PC 0x0c062bfa */
if(!s->budget--) { s->failed_pc=0x0c062bfau; return 0; }
r[7]=0x00000000u;
goto P_0c062bfc;
P_0c062bfc: /* original d526, guest PC 0x0c062bfc */
if(!s->budget--) { s->failed_pc=0x0c062bfcu; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062bfe;
P_0c062bfe: /* original 6453, guest PC 0x0c062bfe */
if(!s->budget--) { s->failed_pc=0x0c062bfeu; return 0; }
r[4]=r[5];
goto P_0c062c00;
P_0c062c00: /* original 9047, guest PC 0x0c062c00 */
if(!s->budget--) { s->failed_pc=0x0c062c00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c02;
P_0c062c02: /* original 6653, guest PC 0x0c062c02 */
if(!s->budget--) { s->failed_pc=0x0c062c02u; return 0; }
r[6]=r[5];
goto P_0c062c04;
P_0c062c04: /* original e501, guest PC 0x0c062c04 */
if(!s->budget--) { s->failed_pc=0x0c062c04u; return 0; }
r[5]=0x00000001u;
goto P_0c062c06;
P_0c062c06: /* original 6361, guest PC 0x0c062c06 */
if(!s->budget--) { s->failed_pc=0x0c062c06u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[6],2);
r[3]=tmp;
goto P_0c062c08;
P_0c062c08: /* original 633d, guest PC 0x0c062c08 */
if(!s->budget--) { s->failed_pc=0x0c062c08u; return 0; }
r[3]=r[3]&65535u;
goto P_0c062c0a;
P_0c062c0a: /* original 2358, guest PC 0x0c062c0a */
if(!s->budget--) { s->failed_pc=0x0c062c0au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c062c0c;
P_0c062c0c: /* original 8b02, guest PC 0x0c062c0c */
if(!s->budget--) { s->failed_pc=0x0c062c0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c14; }
goto P_0c062c0e;
P_0c062c0e: /* original 2451, guest PC 0x0c062c0e */
if(!s->budget--) { s->failed_pc=0x0c062c0eu; return 0; }
write(ram,r[4],r[5],2);
goto P_0c062c10;
P_0c062c10: /* original 000b, guest PC 0x0c062c10 */
if(!s->budget--) { s->failed_pc=0x0c062c10u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c062c12: /* original 6043, guest PC 0x0c062c12 */
if(!s->budget--) { s->failed_pc=0x0c062c12u; return 0; }
r[0]=r[4];
goto P_0c062c14;
P_0c062c14: /* original 7701, guest PC 0x0c062c14 */
if(!s->budget--) { s->failed_pc=0x0c062c14u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c16;
P_0c062c16: /* original 744c, guest PC 0x0c062c16 */
if(!s->budget--) { s->failed_pc=0x0c062c16u; return 0; }
r[4]+=0x0000004cu;
goto P_0c062c18;
P_0c062c18: /* original 3703, guest PC 0x0c062c18 */
if(!s->budget--) { s->failed_pc=0x0c062c18u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[0])!=0);
goto P_0c062c1a;
P_0c062c1a: /* original 8ff4, guest PC 0x0c062c1a */
if(!s->budget--) { s->failed_pc=0x0c062c1au; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c06; }
goto P_0c062c1e;
P_0c062c1c: /* original 764c, guest PC 0x0c062c1c */
if(!s->budget--) { s->failed_pc=0x0c062c1cu; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c1e;
P_0c062c1e: /* original e000, guest PC 0x0c062c1e */
if(!s->budget--) { s->failed_pc=0x0c062c1eu; return 0; }
r[0]=0x00000000u;
goto P_0c062c20;
P_0c062c20: /* original 000b, guest PC 0x0c062c20 */
if(!s->budget--) { s->failed_pc=0x0c062c20u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062c22: /* original 0009, guest PC 0x0c062c22 */
if(!s->budget--) { s->failed_pc=0x0c062c22u; return 0; }
goto P_0c062c24;
P_0c062c24: /* original 2fd6, guest PC 0x0c062c24 */
if(!s->budget--) { s->failed_pc=0x0c062c24u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c062c26;
P_0c062c26: /* original e700, guest PC 0x0c062c26 */
if(!s->budget--) { s->failed_pc=0x0c062c26u; return 0; }
r[7]=0x00000000u;
goto P_0c062c28;
P_0c062c28: /* original d51b, guest PC 0x0c062c28 */
if(!s->budget--) { s->failed_pc=0x0c062c28u; return 0; }
r[5]=read(ram,0x0c062c98u,4);
goto P_0c062c2a;
P_0c062c2a: /* original 7ffc, guest PC 0x0c062c2a */
if(!s->budget--) { s->failed_pc=0x0c062c2au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c062c2c;
P_0c062c2c: /* original dd1b, guest PC 0x0c062c2c */
if(!s->budget--) { s->failed_pc=0x0c062c2cu; return 0; }
r[13]=read(ram,0x0c062c9cu,4);
goto P_0c062c2e;
P_0c062c2e: /* original 6653, guest PC 0x0c062c2e */
if(!s->budget--) { s->failed_pc=0x0c062c2eu; return 0; }
r[6]=r[5];
goto P_0c062c30;
P_0c062c30: /* original 912f, guest PC 0x0c062c30 */
if(!s->budget--) { s->failed_pc=0x0c062c30u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c062c92u,2);
goto P_0c062c32;
P_0c062c32: /* original 2f52, guest PC 0x0c062c32 */
if(!s->budget--) { s->failed_pc=0x0c062c32u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c062c34;
P_0c062c34: /* original 3640, guest PC 0x0c062c34 */
if(!s->budget--) { s->failed_pc=0x0c062c34u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[4])!=0);
goto P_0c062c36;
P_0c062c36: /* original 8f03, guest PC 0x0c062c36 */
if(!s->budget--) { s->failed_pc=0x0c062c36u; return 0; }
cond=r[17]&1u;
r[7]+=0x00000001u;
if(!cond) { goto P_0c062c40; }
goto P_0c062c3a;
P_0c062c38: /* original 7701, guest PC 0x0c062c38 */
if(!s->budget--) { s->failed_pc=0x0c062c38u; return 0; }
r[7]+=0x00000001u;
goto P_0c062c3a;
P_0c062c3a: /* original 6251, guest PC 0x0c062c3a */
if(!s->budget--) { s->failed_pc=0x0c062c3au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c062c3c;
P_0c062c3c: /* original 22d9, guest PC 0x0c062c3c */
if(!s->budget--) { s->failed_pc=0x0c062c3cu; return 0; }
r[2]&=r[13];
goto P_0c062c3e;
P_0c062c3e: /* original 2521, guest PC 0x0c062c3e */
if(!s->budget--) { s->failed_pc=0x0c062c3eu; return 0; }
write(ram,r[5],r[2],2);
goto P_0c062c40;
P_0c062c40: /* original 754c, guest PC 0x0c062c40 */
if(!s->budget--) { s->failed_pc=0x0c062c40u; return 0; }
r[5]+=0x0000004cu;
goto P_0c062c42;
P_0c062c42: /* original 3713, guest PC 0x0c062c42 */
if(!s->budget--) { s->failed_pc=0x0c062c42u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[1])!=0);
goto P_0c062c44;
P_0c062c44: /* original 8ff6, guest PC 0x0c062c44 */
if(!s->budget--) { s->failed_pc=0x0c062c44u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000004cu;
if(!cond) { goto P_0c062c34; }
goto P_0c062c48;
P_0c062c46: /* original 764c, guest PC 0x0c062c46 */
if(!s->budget--) { s->failed_pc=0x0c062c46u; return 0; }
r[6]+=0x0000004cu;
goto P_0c062c48;
P_0c062c48: /* original 7f04, guest PC 0x0c062c48 */
if(!s->budget--) { s->failed_pc=0x0c062c48u; return 0; }
r[15]+=0x00000004u;
goto P_0c062c4a;
P_0c062c4a: /* original 000b, guest PC 0x0c062c4a */
if(!s->budget--) { s->failed_pc=0x0c062c4au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c062c4c: /* original 6df6, guest PC 0x0c062c4c */
if(!s->budget--) { s->failed_pc=0x0c062c4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c062c4e;
P_0c062c4e: /* original 6342, guest PC 0x0c062c4e */
if(!s->budget--) { s->failed_pc=0x0c062c4eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c062c50;
P_0c062c50: /* original 2338, guest PC 0x0c062c50 */
if(!s->budget--) { s->failed_pc=0x0c062c50u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c062c52;
P_0c062c52: /* original 8b02, guest PC 0x0c062c52 */
if(!s->budget--) { s->failed_pc=0x0c062c52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c062c5a; }
goto P_0c062c54;
P_0c062c54: /* original e300, guest PC 0x0c062c54 */
if(!s->budget--) { s->failed_pc=0x0c062c54u; return 0; }
r[3]=0x00000000u;
goto P_0c062c56;
P_0c062c56: /* original a002, guest PC 0x0c062c56 */
if(!s->budget--) { s->failed_pc=0x0c062c56u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5e;
P_0c062c58: /* original 1531, guest PC 0x0c062c58 */
if(!s->budget--) { s->failed_pc=0x0c062c58u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c062c5a;
P_0c062c5a: /* original 6242, guest PC 0x0c062c5a */
if(!s->budget--) { s->failed_pc=0x0c062c5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c062c5c;
P_0c062c5c: /* original 1521, guest PC 0x0c062c5c */
if(!s->budget--) { s->failed_pc=0x0c062c5cu; return 0; }
write(ram,r[5]+4,r[2],4);
goto P_0c062c5e;
P_0c062c5e: /* original 000b, guest PC 0x0c062c5e */
if(!s->budget--) { s->failed_pc=0x0c062c5eu; return 0; }
target=r[16];
write(ram,r[4],r[5],4);
s->pc=target; return ram->oob==0;
P_0c062c60: /* original 2452, guest PC 0x0c062c60 */
if(!s->budget--) { s->failed_pc=0x0c062c60u; return 0; }
write(ram,r[4],r[5],4);
if(!vf3_matrix_family(0x0c062c62u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062c62u; return 0; } return 1;
P_0c0644bc: /* original d009, guest PC 0x0c0644bc */
if(!s->budget--) { s->failed_pc=0x0c0644bcu; return 0; }
r[0]=read(ram,0x0c0644e4u,4);
goto P_0c0644be;
P_0c0644be: /* original 7ff8, guest PC 0x0c0644be */
if(!s->budget--) { s->failed_pc=0x0c0644beu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0644c0;
P_0c0644c0: /* original 2f42, guest PC 0x0c0644c0 */
if(!s->budget--) { s->failed_pc=0x0c0644c0u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0644c2;
P_0c0644c2: /* original 6343, guest PC 0x0c0644c2 */
if(!s->budget--) { s->failed_pc=0x0c0644c2u; return 0; }
r[3]=r[4];
goto P_0c0644c4;
P_0c0644c4: /* original 4308, guest PC 0x0c0644c4 */
if(!s->budget--) { s->failed_pc=0x0c0644c4u; return 0; }
r[3]<<=2;
goto P_0c0644c6;
P_0c0644c6: /* original 4300, guest PC 0x0c0644c6 */
if(!s->budget--) { s->failed_pc=0x0c0644c6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c0644c8;
P_0c0644c8: /* original 1f31, guest PC 0x0c0644c8 */
if(!s->budget--) { s->failed_pc=0x0c0644c8u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0644ca;
P_0c0644ca: /* original 023e, guest PC 0x0c0644ca */
if(!s->budget--) { s->failed_pc=0x0c0644cau; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0644cc;
P_0c0644cc: /* original 6403, guest PC 0x0c0644cc */
if(!s->budget--) { s->failed_pc=0x0c0644ccu; return 0; }
r[4]=r[0];
goto P_0c0644ce;
P_0c0644ce: /* original 343c, guest PC 0x0c0644ce */
if(!s->budget--) { s->failed_pc=0x0c0644ceu; return 0; }
r[4]+=r[3];
goto P_0c0644d0;
P_0c0644d0: /* original 5441, guest PC 0x0c0644d0 */
if(!s->budget--) { s->failed_pc=0x0c0644d0u; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c0644d2;
P_0c0644d2: /* original 422b, guest PC 0x0c0644d2 */
if(!s->budget--) { s->failed_pc=0x0c0644d2u; return 0; }
target=r[2];
r[15]+=0x00000008u;
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
P_0c0644d4: /* original 7f08, guest PC 0x0c0644d4 */
if(!s->budget--) { s->failed_pc=0x0c0644d4u; return 0; }
r[15]+=0x00000008u;
if(!vf3_matrix_family(0x0c0644d6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0644d6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
