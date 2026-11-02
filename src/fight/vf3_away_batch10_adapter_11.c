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
int vf3_away_batch10_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c06b56cu: goto P_0c06b56c;
case 0x0c06b56eu: goto P_0c06b56e;
case 0x0c06b570u: goto P_0c06b570;
case 0x0c06b572u: goto P_0c06b572;
case 0x0c06b574u: goto P_0c06b574;
case 0x0c06b576u: goto P_0c06b576;
case 0x0c06b578u: goto P_0c06b578;
case 0x0c06b57au: goto P_0c06b57a;
case 0x0c06b57cu: goto P_0c06b57c;
case 0x0c06b57eu: goto P_0c06b57e;
case 0x0c06b580u: goto P_0c06b580;
case 0x0c06b582u: goto P_0c06b582;
case 0x0c06b584u: goto P_0c06b584;
case 0x0c06b586u: goto P_0c06b586;
case 0x0c06b588u: goto P_0c06b588;
case 0x0c06b58au: goto P_0c06b58a;
case 0x0c06b58cu: goto P_0c06b58c;
case 0x0c06b58eu: goto P_0c06b58e;
case 0x0c06b590u: goto P_0c06b590;
case 0x0c06b592u: goto P_0c06b592;
case 0x0c06b594u: goto P_0c06b594;
case 0x0c06b596u: goto P_0c06b596;
case 0x0c06b598u: goto P_0c06b598;
case 0x0c06b59au: goto P_0c06b59a;
case 0x0c06b59cu: goto P_0c06b59c;
case 0x0c06b59eu: goto P_0c06b59e;
case 0x0c06b5a0u: goto P_0c06b5a0;
case 0x0c06b5a2u: goto P_0c06b5a2;
case 0x0c06b5a4u: goto P_0c06b5a4;
case 0x0c06b5a6u: goto P_0c06b5a6;
case 0x0c06b5a8u: goto P_0c06b5a8;
case 0x0c06b5aau: goto P_0c06b5aa;
case 0x0c06b5acu: goto P_0c06b5ac;
case 0x0c06b5aeu: goto P_0c06b5ae;
case 0x0c06b5b0u: goto P_0c06b5b0;
case 0x0c06b5b2u: goto P_0c06b5b2;
case 0x0c06b5b4u: goto P_0c06b5b4;
case 0x0c06b5b6u: goto P_0c06b5b6;
case 0x0c06b5b8u: goto P_0c06b5b8;
case 0x0c06b5bau: goto P_0c06b5ba;
case 0x0c06b5bcu: goto P_0c06b5bc;
case 0x0c06b5beu: goto P_0c06b5be;
case 0x0c06b5c0u: goto P_0c06b5c0;
case 0x0c06b5c2u: goto P_0c06b5c2;
case 0x0c06b5c4u: goto P_0c06b5c4;
case 0x0c06b5c6u: goto P_0c06b5c6;
case 0x0c06b5c8u: goto P_0c06b5c8;
case 0x0c06b5cau: goto P_0c06b5ca;
case 0x0c06b5ccu: goto P_0c06b5cc;
case 0x0c06b5ceu: goto P_0c06b5ce;
case 0x0c06b5d0u: goto P_0c06b5d0;
case 0x0c06b5d2u: goto P_0c06b5d2;
case 0x0c06b5d4u: goto P_0c06b5d4;
case 0x0c06b5d6u: goto P_0c06b5d6;
case 0x0c06b5d8u: goto P_0c06b5d8;
case 0x0c06b5dau: goto P_0c06b5da;
case 0x0c06b5dcu: goto P_0c06b5dc;
case 0x0c06b5deu: goto P_0c06b5de;
case 0x0c06b5e0u: goto P_0c06b5e0;
case 0x0c06b5e2u: goto P_0c06b5e2;
case 0x0c06b5e4u: goto P_0c06b5e4;
case 0x0c06b5e6u: goto P_0c06b5e6;
case 0x0c06b5e8u: goto P_0c06b5e8;
case 0x0c06b5eau: goto P_0c06b5ea;
case 0x0c06b5ecu: goto P_0c06b5ec;
case 0x0c06b5eeu: goto P_0c06b5ee;
case 0x0c06b5f0u: goto P_0c06b5f0;
case 0x0c06b5f2u: goto P_0c06b5f2;
case 0x0c06b5f4u: goto P_0c06b5f4;
case 0x0c06b5f6u: goto P_0c06b5f6;
case 0x0c06b5f8u: goto P_0c06b5f8;
case 0x0c06b5fau: goto P_0c06b5fa;
case 0x0c06b5fcu: goto P_0c06b5fc;
case 0x0c06b5feu: goto P_0c06b5fe;
case 0x0c06b600u: goto P_0c06b600;
case 0x0c06b602u: goto P_0c06b602;
case 0x0c06b604u: goto P_0c06b604;
case 0x0c06b606u: goto P_0c06b606;
case 0x0c06b608u: goto P_0c06b608;
case 0x0c06b60au: goto P_0c06b60a;
case 0x0c06b60cu: goto P_0c06b60c;
case 0x0c06b60eu: goto P_0c06b60e;
case 0x0c06b610u: goto P_0c06b610;
case 0x0c06b612u: goto P_0c06b612;
case 0x0c06b614u: goto P_0c06b614;
case 0x0c06b616u: goto P_0c06b616;
case 0x0c06b618u: goto P_0c06b618;
case 0x0c06b61au: goto P_0c06b61a;
case 0x0c06b61cu: goto P_0c06b61c;
case 0x0c06b61eu: goto P_0c06b61e;
case 0x0c06b620u: goto P_0c06b620;
case 0x0c06b622u: goto P_0c06b622;
case 0x0c06b624u: goto P_0c06b624;
case 0x0c06b626u: goto P_0c06b626;
case 0x0c06b628u: goto P_0c06b628;
case 0x0c06b62au: goto P_0c06b62a;
case 0x0c06b62cu: goto P_0c06b62c;
case 0x0c06b62eu: goto P_0c06b62e;
case 0x0c06b630u: goto P_0c06b630;
case 0x0c06b632u: goto P_0c06b632;
case 0x0c06b634u: goto P_0c06b634;
case 0x0c06b636u: goto P_0c06b636;
case 0x0c06b638u: goto P_0c06b638;
case 0x0c06b63au: goto P_0c06b63a;
case 0x0c06b63cu: goto P_0c06b63c;
case 0x0c06b63eu: goto P_0c06b63e;
case 0x0c06b640u: goto P_0c06b640;
case 0x0c06b642u: goto P_0c06b642;
case 0x0c06b644u: goto P_0c06b644;
case 0x0c06b646u: goto P_0c06b646;
case 0x0c06b648u: goto P_0c06b648;
case 0x0c06b64au: goto P_0c06b64a;
case 0x0c06b64cu: goto P_0c06b64c;
case 0x0c06b64eu: goto P_0c06b64e;
case 0x0c06b650u: goto P_0c06b650;
case 0x0c06b652u: goto P_0c06b652;
case 0x0c06b654u: goto P_0c06b654;
case 0x0c06b656u: goto P_0c06b656;
case 0x0c06b658u: goto P_0c06b658;
case 0x0c06b65au: goto P_0c06b65a;
case 0x0c06b65cu: goto P_0c06b65c;
case 0x0c06b65eu: goto P_0c06b65e;
case 0x0c06b660u: goto P_0c06b660;
case 0x0c06b662u: goto P_0c06b662;
case 0x0c06b664u: goto P_0c06b664;
case 0x0c06b666u: goto P_0c06b666;
case 0x0c06b668u: goto P_0c06b668;
case 0x0c06b66au: goto P_0c06b66a;
case 0x0c06b66cu: goto P_0c06b66c;
case 0x0c06b66eu: goto P_0c06b66e;
case 0x0c06b670u: goto P_0c06b670;
case 0x0c06b672u: goto P_0c06b672;
case 0x0c06b674u: goto P_0c06b674;
case 0x0c06b676u: goto P_0c06b676;
case 0x0c06b678u: goto P_0c06b678;
case 0x0c06b67au: goto P_0c06b67a;
case 0x0c06b67cu: goto P_0c06b67c;
case 0x0c06b67eu: goto P_0c06b67e;
case 0x0c06b680u: goto P_0c06b680;
case 0x0c06b682u: goto P_0c06b682;
case 0x0c06b684u: goto P_0c06b684;
case 0x0c06b686u: goto P_0c06b686;
case 0x0c06b688u: goto P_0c06b688;
case 0x0c06b68au: goto P_0c06b68a;
case 0x0c06b68cu: goto P_0c06b68c;
case 0x0c06b68eu: goto P_0c06b68e;
case 0x0c06b690u: goto P_0c06b690;
case 0x0c06b692u: goto P_0c06b692;
case 0x0c06b694u: goto P_0c06b694;
case 0x0c06b696u: goto P_0c06b696;
case 0x0c06b698u: goto P_0c06b698;
case 0x0c06b69au: goto P_0c06b69a;
case 0x0c06b69cu: goto P_0c06b69c;
case 0x0c06b69eu: goto P_0c06b69e;
case 0x0c06b6a0u: goto P_0c06b6a0;
case 0x0c06b6a2u: goto P_0c06b6a2;
case 0x0c06b6a4u: goto P_0c06b6a4;
case 0x0c06b6a6u: goto P_0c06b6a6;
case 0x0c06b6a8u: goto P_0c06b6a8;
case 0x0c06b6aau: goto P_0c06b6aa;
case 0x0c06b6acu: goto P_0c06b6ac;
case 0x0c06b6aeu: goto P_0c06b6ae;
case 0x0c06b6b0u: goto P_0c06b6b0;
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
P_0c06b56c: /* original 2fe6, guest PC 0x0c06b56c */
if(!s->budget--) { s->failed_pc=0x0c06b56cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b56e;
P_0c06b56e: /* original 2fd6, guest PC 0x0c06b56e */
if(!s->budget--) { s->failed_pc=0x0c06b56eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b570;
P_0c06b570: /* original 2fc6, guest PC 0x0c06b570 */
if(!s->budget--) { s->failed_pc=0x0c06b570u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b572;
P_0c06b572: /* original 2fb6, guest PC 0x0c06b572 */
if(!s->budget--) { s->failed_pc=0x0c06b572u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b574;
P_0c06b574: /* original 2fa6, guest PC 0x0c06b574 */
if(!s->budget--) { s->failed_pc=0x0c06b574u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06b576;
P_0c06b576: /* original dd55, guest PC 0x0c06b576 */
if(!s->budget--) { s->failed_pc=0x0c06b576u; return 0; }
r[13]=read(ram,0x0c06b6ccu,4);
goto P_0c06b578;
P_0c06b578: /* original 4f22, guest PC 0x0c06b578 */
if(!s->budget--) { s->failed_pc=0x0c06b578u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06b57a;
P_0c06b57a: /* original dc55, guest PC 0x0c06b57a */
if(!s->budget--) { s->failed_pc=0x0c06b57au; return 0; }
r[12]=read(ram,0x0c06b6d0u,4);
goto P_0c06b57c;
P_0c06b57c: /* original 64d3, guest PC 0x0c06b57c */
if(!s->budget--) { s->failed_pc=0x0c06b57cu; return 0; }
r[4]=r[13];
goto P_0c06b57e;
P_0c06b57e: /* original 4c0b, guest PC 0x0c06b57e */
if(!s->budget--) { s->failed_pc=0x0c06b57eu; return 0; }
target=r[12];
r[16]=code_base|0x0c06b582u;
r[4]+=0x00000017u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b582u) { target=s->pc; goto dispatch; }
goto P_0c06b582;
P_0c06b580: /* original 7417, guest PC 0x0c06b580 */
if(!s->budget--) { s->failed_pc=0x0c06b580u; return 0; }
r[4]+=0x00000017u;
goto P_0c06b582;
P_0c06b582: /* original 6b0c, guest PC 0x0c06b582 */
if(!s->budget--) { s->failed_pc=0x0c06b582u; return 0; }
r[11]=r[0]&255u;
goto P_0c06b584;
P_0c06b584: /* original 9095, guest PC 0x0c06b584 */
if(!s->budget--) { s->failed_pc=0x0c06b584u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b2u,2);
goto P_0c06b586;
P_0c06b586: /* original de53, guest PC 0x0c06b586 */
if(!s->budget--) { s->failed_pc=0x0c06b586u; return 0; }
r[14]=read(ram,0x0c06b6d4u,4);
goto P_0c06b588;
P_0c06b588: /* original 64d3, guest PC 0x0c06b588 */
if(!s->budget--) { s->failed_pc=0x0c06b588u; return 0; }
r[4]=r[13];
goto P_0c06b58a;
P_0c06b58a: /* original 0eb4, guest PC 0x0c06b58a */
if(!s->budget--) { s->failed_pc=0x0c06b58au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b58c;
P_0c06b58c: /* original 4c0b, guest PC 0x0c06b58c */
if(!s->budget--) { s->failed_pc=0x0c06b58cu; return 0; }
target=r[12];
r[16]=code_base|0x0c06b590u;
r[4]+=0x0000001cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b590u) { target=s->pc; goto dispatch; }
goto P_0c06b590;
P_0c06b58e: /* original 741c, guest PC 0x0c06b58e */
if(!s->budget--) { s->failed_pc=0x0c06b58eu; return 0; }
r[4]+=0x0000001cu;
goto P_0c06b590;
P_0c06b590: /* original 640c, guest PC 0x0c06b590 */
if(!s->budget--) { s->failed_pc=0x0c06b590u; return 0; }
r[4]=r[0]&255u;
goto P_0c06b592;
P_0c06b592: /* original 6043, guest PC 0x0c06b592 */
if(!s->budget--) { s->failed_pc=0x0c06b592u; return 0; }
r[0]=r[4];
goto P_0c06b594;
P_0c06b594: /* original 8801, guest PC 0x0c06b594 */
if(!s->budget--) { s->failed_pc=0x0c06b594u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b596;
P_0c06b596: /* original 8917, guest PC 0x0c06b596 */
if(!s->budget--) { s->failed_pc=0x0c06b596u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b5c8; }
goto P_0c06b598;
P_0c06b598: /* original 64d3, guest PC 0x0c06b598 */
if(!s->budget--) { s->failed_pc=0x0c06b598u; return 0; }
r[4]=r[13];
goto P_0c06b59a;
P_0c06b59a: /* original 4c0b, guest PC 0x0c06b59a */
if(!s->budget--) { s->failed_pc=0x0c06b59au; return 0; }
target=r[12];
r[16]=code_base|0x0c06b59eu;
r[4]+=0x0000001eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b59eu) { target=s->pc; goto dispatch; }
goto P_0c06b59e;
P_0c06b59c: /* original 741e, guest PC 0x0c06b59c */
if(!s->budget--) { s->failed_pc=0x0c06b59cu; return 0; }
r[4]+=0x0000001eu;
goto P_0c06b59e;
P_0c06b59e: /* original 640c, guest PC 0x0c06b59e */
if(!s->budget--) { s->failed_pc=0x0c06b59eu; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5a0;
P_0c06b5a0: /* original 9088, guest PC 0x0c06b5a0 */
if(!s->budget--) { s->failed_pc=0x0c06b5a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b4u,2);
goto P_0c06b5a2;
P_0c06b5a2: /* original 0e44, guest PC 0x0c06b5a2 */
if(!s->budget--) { s->failed_pc=0x0c06b5a2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b5a4;
P_0c06b5a4: /* original 64d3, guest PC 0x0c06b5a4 */
if(!s->budget--) { s->failed_pc=0x0c06b5a4u; return 0; }
r[4]=r[13];
goto P_0c06b5a6;
P_0c06b5a6: /* original 4c0b, guest PC 0x0c06b5a6 */
if(!s->budget--) { s->failed_pc=0x0c06b5a6u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b5aau;
r[4]+=0x0000001fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b5aau) { target=s->pc; goto dispatch; }
goto P_0c06b5aa;
P_0c06b5a8: /* original 741f, guest PC 0x0c06b5a8 */
if(!s->budget--) { s->failed_pc=0x0c06b5a8u; return 0; }
r[4]+=0x0000001fu;
goto P_0c06b5aa;
P_0c06b5aa: /* original 640c, guest PC 0x0c06b5aa */
if(!s->budget--) { s->failed_pc=0x0c06b5aau; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5ac;
P_0c06b5ac: /* original 9083, guest PC 0x0c06b5ac */
if(!s->budget--) { s->failed_pc=0x0c06b5acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b6u,2);
goto P_0c06b5ae;
P_0c06b5ae: /* original 0e44, guest PC 0x0c06b5ae */
if(!s->budget--) { s->failed_pc=0x0c06b5aeu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b5b0;
P_0c06b5b0: /* original 60b3, guest PC 0x0c06b5b0 */
if(!s->budget--) { s->failed_pc=0x0c06b5b0u; return 0; }
r[0]=r[11];
goto P_0c06b5b2;
P_0c06b5b2: /* original 8801, guest PC 0x0c06b5b2 */
if(!s->budget--) { s->failed_pc=0x0c06b5b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b5b4;
P_0c06b5b4: /* original 8903, guest PC 0x0c06b5b4 */
if(!s->budget--) { s->failed_pc=0x0c06b5b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b5be; }
goto P_0c06b5b6;
P_0c06b5b6: /* original 64d3, guest PC 0x0c06b5b6 */
if(!s->budget--) { s->failed_pc=0x0c06b5b6u; return 0; }
r[4]=r[13];
goto P_0c06b5b8;
P_0c06b5b8: /* original 4c0b, guest PC 0x0c06b5b8 */
if(!s->budget--) { s->failed_pc=0x0c06b5b8u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b5bcu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b5bcu) { target=s->pc; goto dispatch; }
goto P_0c06b5bc;
P_0c06b5ba: /* original 7420, guest PC 0x0c06b5ba */
if(!s->budget--) { s->failed_pc=0x0c06b5bau; return 0; }
r[4]+=0x00000020u;
goto P_0c06b5bc;
P_0c06b5bc: /* original 640c, guest PC 0x0c06b5bc */
if(!s->budget--) { s->failed_pc=0x0c06b5bcu; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5be;
P_0c06b5be: /* original 907b, guest PC 0x0c06b5be */
if(!s->budget--) { s->failed_pc=0x0c06b5beu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b8u,2);
goto P_0c06b5c0;
P_0c06b5c0: /* original 0e44, guest PC 0x0c06b5c0 */
if(!s->budget--) { s->failed_pc=0x0c06b5c0u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b5c2;
P_0c06b5c2: /* original 64d3, guest PC 0x0c06b5c2 */
if(!s->budget--) { s->failed_pc=0x0c06b5c2u; return 0; }
r[4]=r[13];
goto P_0c06b5c4;
P_0c06b5c4: /* original a017, guest PC 0x0c06b5c4 */
if(!s->budget--) { s->failed_pc=0x0c06b5c4u; return 0; }
r[4]+=0x00000021u;
goto P_0c06b5f6;
P_0c06b5c6: /* original 7421, guest PC 0x0c06b5c6 */
if(!s->budget--) { s->failed_pc=0x0c06b5c6u; return 0; }
r[4]+=0x00000021u;
goto P_0c06b5c8;
P_0c06b5c8: /* original 64d3, guest PC 0x0c06b5c8 */
if(!s->budget--) { s->failed_pc=0x0c06b5c8u; return 0; }
r[4]=r[13];
goto P_0c06b5ca;
P_0c06b5ca: /* original 4c0b, guest PC 0x0c06b5ca */
if(!s->budget--) { s->failed_pc=0x0c06b5cau; return 0; }
target=r[12];
r[16]=code_base|0x0c06b5ceu;
r[4]+=0x00000022u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b5ceu) { target=s->pc; goto dispatch; }
goto P_0c06b5ce;
P_0c06b5cc: /* original 7422, guest PC 0x0c06b5cc */
if(!s->budget--) { s->failed_pc=0x0c06b5ccu; return 0; }
r[4]+=0x00000022u;
goto P_0c06b5ce;
P_0c06b5ce: /* original 640c, guest PC 0x0c06b5ce */
if(!s->budget--) { s->failed_pc=0x0c06b5ceu; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5d0;
P_0c06b5d0: /* original 9070, guest PC 0x0c06b5d0 */
if(!s->budget--) { s->failed_pc=0x0c06b5d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b4u,2);
goto P_0c06b5d2;
P_0c06b5d2: /* original 0e44, guest PC 0x0c06b5d2 */
if(!s->budget--) { s->failed_pc=0x0c06b5d2u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b5d4;
P_0c06b5d4: /* original 64d3, guest PC 0x0c06b5d4 */
if(!s->budget--) { s->failed_pc=0x0c06b5d4u; return 0; }
r[4]=r[13];
goto P_0c06b5d6;
P_0c06b5d6: /* original 4c0b, guest PC 0x0c06b5d6 */
if(!s->budget--) { s->failed_pc=0x0c06b5d6u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b5dau;
r[4]+=0x00000023u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b5dau) { target=s->pc; goto dispatch; }
goto P_0c06b5da;
P_0c06b5d8: /* original 7423, guest PC 0x0c06b5d8 */
if(!s->budget--) { s->failed_pc=0x0c06b5d8u; return 0; }
r[4]+=0x00000023u;
goto P_0c06b5da;
P_0c06b5da: /* original 640c, guest PC 0x0c06b5da */
if(!s->budget--) { s->failed_pc=0x0c06b5dau; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5dc;
P_0c06b5dc: /* original 906b, guest PC 0x0c06b5dc */
if(!s->budget--) { s->failed_pc=0x0c06b5dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b6u,2);
goto P_0c06b5de;
P_0c06b5de: /* original 0e44, guest PC 0x0c06b5de */
if(!s->budget--) { s->failed_pc=0x0c06b5deu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b5e0;
P_0c06b5e0: /* original 60b3, guest PC 0x0c06b5e0 */
if(!s->budget--) { s->failed_pc=0x0c06b5e0u; return 0; }
r[0]=r[11];
goto P_0c06b5e2;
P_0c06b5e2: /* original 8801, guest PC 0x0c06b5e2 */
if(!s->budget--) { s->failed_pc=0x0c06b5e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b5e4;
P_0c06b5e4: /* original 8903, guest PC 0x0c06b5e4 */
if(!s->budget--) { s->failed_pc=0x0c06b5e4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b5ee; }
goto P_0c06b5e6;
P_0c06b5e6: /* original 64d3, guest PC 0x0c06b5e6 */
if(!s->budget--) { s->failed_pc=0x0c06b5e6u; return 0; }
r[4]=r[13];
goto P_0c06b5e8;
P_0c06b5e8: /* original 4c0b, guest PC 0x0c06b5e8 */
if(!s->budget--) { s->failed_pc=0x0c06b5e8u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b5ecu;
r[4]+=0x00000024u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b5ecu) { target=s->pc; goto dispatch; }
goto P_0c06b5ec;
P_0c06b5ea: /* original 7424, guest PC 0x0c06b5ea */
if(!s->budget--) { s->failed_pc=0x0c06b5eau; return 0; }
r[4]+=0x00000024u;
goto P_0c06b5ec;
P_0c06b5ec: /* original 640c, guest PC 0x0c06b5ec */
if(!s->budget--) { s->failed_pc=0x0c06b5ecu; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5ee;
P_0c06b5ee: /* original 9063, guest PC 0x0c06b5ee */
if(!s->budget--) { s->failed_pc=0x0c06b5eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6b8u,2);
goto P_0c06b5f0;
P_0c06b5f0: /* original 0e44, guest PC 0x0c06b5f0 */
if(!s->budget--) { s->failed_pc=0x0c06b5f0u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b5f2;
P_0c06b5f2: /* original 64d3, guest PC 0x0c06b5f2 */
if(!s->budget--) { s->failed_pc=0x0c06b5f2u; return 0; }
r[4]=r[13];
goto P_0c06b5f4;
P_0c06b5f4: /* original 7425, guest PC 0x0c06b5f4 */
if(!s->budget--) { s->failed_pc=0x0c06b5f4u; return 0; }
r[4]+=0x00000025u;
goto P_0c06b5f6;
P_0c06b5f6: /* original 4c0b, guest PC 0x0c06b5f6 */
if(!s->budget--) { s->failed_pc=0x0c06b5f6u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b5fau;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b5fau) { target=s->pc; goto dispatch; }
goto P_0c06b5fa;
P_0c06b5f8: /* original 0009, guest PC 0x0c06b5f8 */
if(!s->budget--) { s->failed_pc=0x0c06b5f8u; return 0; }
goto P_0c06b5fa;
P_0c06b5fa: /* original 640c, guest PC 0x0c06b5fa */
if(!s->budget--) { s->failed_pc=0x0c06b5fau; return 0; }
r[4]=r[0]&255u;
goto P_0c06b5fc;
P_0c06b5fc: /* original 905d, guest PC 0x0c06b5fc */
if(!s->budget--) { s->failed_pc=0x0c06b5fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6bau,2);
goto P_0c06b5fe;
P_0c06b5fe: /* original 0e44, guest PC 0x0c06b5fe */
if(!s->budget--) { s->failed_pc=0x0c06b5feu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b600;
P_0c06b600: /* original 64d3, guest PC 0x0c06b600 */
if(!s->budget--) { s->failed_pc=0x0c06b600u; return 0; }
r[4]=r[13];
goto P_0c06b602;
P_0c06b602: /* original 4c0b, guest PC 0x0c06b602 */
if(!s->budget--) { s->failed_pc=0x0c06b602u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b606u;
r[4]+=0x00000026u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b606u) { target=s->pc; goto dispatch; }
goto P_0c06b606;
P_0c06b604: /* original 7426, guest PC 0x0c06b604 */
if(!s->budget--) { s->failed_pc=0x0c06b604u; return 0; }
r[4]+=0x00000026u;
goto P_0c06b606;
P_0c06b606: /* original 640c, guest PC 0x0c06b606 */
if(!s->budget--) { s->failed_pc=0x0c06b606u; return 0; }
r[4]=r[0]&255u;
goto P_0c06b608;
P_0c06b608: /* original 9058, guest PC 0x0c06b608 */
if(!s->budget--) { s->failed_pc=0x0c06b608u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6bcu,2);
goto P_0c06b60a;
P_0c06b60a: /* original 0e44, guest PC 0x0c06b60a */
if(!s->budget--) { s->failed_pc=0x0c06b60au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b60c;
P_0c06b60c: /* original 64d3, guest PC 0x0c06b60c */
if(!s->budget--) { s->failed_pc=0x0c06b60cu; return 0; }
r[4]=r[13];
goto P_0c06b60e;
P_0c06b60e: /* original 4c0b, guest PC 0x0c06b60e */
if(!s->budget--) { s->failed_pc=0x0c06b60eu; return 0; }
target=r[12];
r[16]=code_base|0x0c06b612u;
r[4]+=0x00000029u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b612u) { target=s->pc; goto dispatch; }
goto P_0c06b612;
P_0c06b610: /* original 7429, guest PC 0x0c06b610 */
if(!s->budget--) { s->failed_pc=0x0c06b610u; return 0; }
r[4]+=0x00000029u;
goto P_0c06b612;
P_0c06b612: /* original 640c, guest PC 0x0c06b612 */
if(!s->budget--) { s->failed_pc=0x0c06b612u; return 0; }
r[4]=r[0]&255u;
goto P_0c06b614;
P_0c06b614: /* original 9053, guest PC 0x0c06b614 */
if(!s->budget--) { s->failed_pc=0x0c06b614u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6beu,2);
goto P_0c06b616;
P_0c06b616: /* original eb00, guest PC 0x0c06b616 */
if(!s->budget--) { s->failed_pc=0x0c06b616u; return 0; }
r[11]=0x00000000u;
goto P_0c06b618;
P_0c06b618: /* original 0e44, guest PC 0x0c06b618 */
if(!s->budget--) { s->failed_pc=0x0c06b618u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b61a;
P_0c06b61a: /* original 70ff, guest PC 0x0c06b61a */
if(!s->budget--) { s->failed_pc=0x0c06b61au; return 0; }
r[0]+=0xffffffffu;
goto P_0c06b61c;
P_0c06b61c: /* original 0eb4, guest PC 0x0c06b61c */
if(!s->budget--) { s->failed_pc=0x0c06b61cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b61e;
P_0c06b61e: /* original 7004, guest PC 0x0c06b61e */
if(!s->budget--) { s->failed_pc=0x0c06b61eu; return 0; }
r[0]+=0x00000004u;
goto P_0c06b620;
P_0c06b620: /* original 0eb4, guest PC 0x0c06b620 */
if(!s->budget--) { s->failed_pc=0x0c06b620u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b622;
P_0c06b622: /* original 70fa, guest PC 0x0c06b622 */
if(!s->budget--) { s->failed_pc=0x0c06b622u; return 0; }
r[0]+=0xfffffffau;
goto P_0c06b624;
P_0c06b624: /* original 0eb4, guest PC 0x0c06b624 */
if(!s->budget--) { s->failed_pc=0x0c06b624u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b626;
P_0c06b626: /* original 7001, guest PC 0x0c06b626 */
if(!s->budget--) { s->failed_pc=0x0c06b626u; return 0; }
r[0]+=0x00000001u;
goto P_0c06b628;
P_0c06b628: /* original 0eb4, guest PC 0x0c06b628 */
if(!s->budget--) { s->failed_pc=0x0c06b628u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b62a;
P_0c06b62a: /* original 7003, guest PC 0x0c06b62a */
if(!s->budget--) { s->failed_pc=0x0c06b62au; return 0; }
r[0]+=0x00000003u;
goto P_0c06b62c;
P_0c06b62c: /* original 0eb4, guest PC 0x0c06b62c */
if(!s->budget--) { s->failed_pc=0x0c06b62cu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b62e;
P_0c06b62e: /* original 7001, guest PC 0x0c06b62e */
if(!s->budget--) { s->failed_pc=0x0c06b62eu; return 0; }
r[0]+=0x00000001u;
goto P_0c06b630;
P_0c06b630: /* original 64d3, guest PC 0x0c06b630 */
if(!s->budget--) { s->failed_pc=0x0c06b630u; return 0; }
r[4]=r[13];
goto P_0c06b632;
P_0c06b632: /* original 65b3, guest PC 0x0c06b632 */
if(!s->budget--) { s->failed_pc=0x0c06b632u; return 0; }
r[5]=r[11];
goto P_0c06b634;
P_0c06b634: /* original 0eb4, guest PC 0x0c06b634 */
if(!s->budget--) { s->failed_pc=0x0c06b634u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b636;
P_0c06b636: /* original da28, guest PC 0x0c06b636 */
if(!s->budget--) { s->failed_pc=0x0c06b636u; return 0; }
r[10]=read(ram,0x0c06b6d8u,4);
goto P_0c06b638;
P_0c06b638: /* original 4a0b, guest PC 0x0c06b638 */
if(!s->budget--) { s->failed_pc=0x0c06b638u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b63cu;
r[4]+=0x00000027u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b63cu) { target=s->pc; goto dispatch; }
goto P_0c06b63c;
P_0c06b63a: /* original 7427, guest PC 0x0c06b63a */
if(!s->budget--) { s->failed_pc=0x0c06b63au; return 0; }
r[4]+=0x00000027u;
goto P_0c06b63c;
P_0c06b63c: /* original 64d3, guest PC 0x0c06b63c */
if(!s->budget--) { s->failed_pc=0x0c06b63cu; return 0; }
r[4]=r[13];
goto P_0c06b63e;
P_0c06b63e: /* original 65b3, guest PC 0x0c06b63e */
if(!s->budget--) { s->failed_pc=0x0c06b63eu; return 0; }
r[5]=r[11];
goto P_0c06b640;
P_0c06b640: /* original 4a0b, guest PC 0x0c06b640 */
if(!s->budget--) { s->failed_pc=0x0c06b640u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b644u;
r[4]+=0x00000028u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b644u) { target=s->pc; goto dispatch; }
goto P_0c06b644;
P_0c06b642: /* original 7428, guest PC 0x0c06b642 */
if(!s->budget--) { s->failed_pc=0x0c06b642u; return 0; }
r[4]+=0x00000028u;
goto P_0c06b644;
P_0c06b644: /* original 64d3, guest PC 0x0c06b644 */
if(!s->budget--) { s->failed_pc=0x0c06b644u; return 0; }
r[4]=r[13];
goto P_0c06b646;
P_0c06b646: /* original 65b3, guest PC 0x0c06b646 */
if(!s->budget--) { s->failed_pc=0x0c06b646u; return 0; }
r[5]=r[11];
goto P_0c06b648;
P_0c06b648: /* original 4a0b, guest PC 0x0c06b648 */
if(!s->budget--) { s->failed_pc=0x0c06b648u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b64cu;
r[4]+=0x0000002au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b64cu) { target=s->pc; goto dispatch; }
goto P_0c06b64c;
P_0c06b64a: /* original 742a, guest PC 0x0c06b64a */
if(!s->budget--) { s->failed_pc=0x0c06b64au; return 0; }
r[4]+=0x0000002au;
goto P_0c06b64c;
P_0c06b64c: /* original 64d3, guest PC 0x0c06b64c */
if(!s->budget--) { s->failed_pc=0x0c06b64cu; return 0; }
r[4]=r[13];
goto P_0c06b64e;
P_0c06b64e: /* original 65b3, guest PC 0x0c06b64e */
if(!s->budget--) { s->failed_pc=0x0c06b64eu; return 0; }
r[5]=r[11];
goto P_0c06b650;
P_0c06b650: /* original 4a0b, guest PC 0x0c06b650 */
if(!s->budget--) { s->failed_pc=0x0c06b650u; return 0; }
target=r[10];
r[16]=code_base|0x0c06b654u;
r[4]+=0x0000002bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b654u) { target=s->pc; goto dispatch; }
goto P_0c06b654;
P_0c06b652: /* original 742b, guest PC 0x0c06b652 */
if(!s->budget--) { s->failed_pc=0x0c06b652u; return 0; }
r[4]+=0x0000002bu;
goto P_0c06b654;
P_0c06b654: /* original 9034, guest PC 0x0c06b654 */
if(!s->budget--) { s->failed_pc=0x0c06b654u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6c0u,2);
goto P_0c06b656;
P_0c06b656: /* original 64d3, guest PC 0x0c06b656 */
if(!s->budget--) { s->failed_pc=0x0c06b656u; return 0; }
r[4]=r[13];
goto P_0c06b658;
P_0c06b658: /* original 0eb4, guest PC 0x0c06b658 */
if(!s->budget--) { s->failed_pc=0x0c06b658u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c06b65a;
P_0c06b65a: /* original 4c0b, guest PC 0x0c06b65a */
if(!s->budget--) { s->failed_pc=0x0c06b65au; return 0; }
target=r[12];
r[16]=code_base|0x0c06b65eu;
r[4]+=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b65eu) { target=s->pc; goto dispatch; }
goto P_0c06b65e;
P_0c06b65c: /* original 7418, guest PC 0x0c06b65c */
if(!s->budget--) { s->failed_pc=0x0c06b65cu; return 0; }
r[4]+=0x00000018u;
goto P_0c06b65e;
P_0c06b65e: /* original 640c, guest PC 0x0c06b65e */
if(!s->budget--) { s->failed_pc=0x0c06b65eu; return 0; }
r[4]=r[0]&255u;
goto P_0c06b660;
P_0c06b660: /* original 902f, guest PC 0x0c06b660 */
if(!s->budget--) { s->failed_pc=0x0c06b660u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6c2u,2);
goto P_0c06b662;
P_0c06b662: /* original 0e44, guest PC 0x0c06b662 */
if(!s->budget--) { s->failed_pc=0x0c06b662u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b664;
P_0c06b664: /* original 64d3, guest PC 0x0c06b664 */
if(!s->budget--) { s->failed_pc=0x0c06b664u; return 0; }
r[4]=r[13];
goto P_0c06b666;
P_0c06b666: /* original 4c0b, guest PC 0x0c06b666 */
if(!s->budget--) { s->failed_pc=0x0c06b666u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b66au;
r[4]+=0x0000001au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b66au) { target=s->pc; goto dispatch; }
goto P_0c06b66a;
P_0c06b668: /* original 741a, guest PC 0x0c06b668 */
if(!s->budget--) { s->failed_pc=0x0c06b668u; return 0; }
r[4]+=0x0000001au;
goto P_0c06b66a;
P_0c06b66a: /* original 640c, guest PC 0x0c06b66a */
if(!s->budget--) { s->failed_pc=0x0c06b66au; return 0; }
r[4]=r[0]&255u;
goto P_0c06b66c;
P_0c06b66c: /* original 902a, guest PC 0x0c06b66c */
if(!s->budget--) { s->failed_pc=0x0c06b66cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6c4u,2);
goto P_0c06b66e;
P_0c06b66e: /* original 0e44, guest PC 0x0c06b66e */
if(!s->budget--) { s->failed_pc=0x0c06b66eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b670;
P_0c06b670: /* original 64d3, guest PC 0x0c06b670 */
if(!s->budget--) { s->failed_pc=0x0c06b670u; return 0; }
r[4]=r[13];
goto P_0c06b672;
P_0c06b672: /* original 4c0b, guest PC 0x0c06b672 */
if(!s->budget--) { s->failed_pc=0x0c06b672u; return 0; }
target=r[12];
r[16]=code_base|0x0c06b676u;
r[4]+=0x00000019u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b676u) { target=s->pc; goto dispatch; }
goto P_0c06b676;
P_0c06b674: /* original 7419, guest PC 0x0c06b674 */
if(!s->budget--) { s->failed_pc=0x0c06b674u; return 0; }
r[4]+=0x00000019u;
goto P_0c06b676;
P_0c06b676: /* original 640c, guest PC 0x0c06b676 */
if(!s->budget--) { s->failed_pc=0x0c06b676u; return 0; }
r[4]=r[0]&255u;
goto P_0c06b678;
P_0c06b678: /* original 9025, guest PC 0x0c06b678 */
if(!s->budget--) { s->failed_pc=0x0c06b678u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6c6u,2);
goto P_0c06b67a;
P_0c06b67a: /* original 0e44, guest PC 0x0c06b67a */
if(!s->budget--) { s->failed_pc=0x0c06b67au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b67c;
P_0c06b67c: /* original 64d3, guest PC 0x0c06b67c */
if(!s->budget--) { s->failed_pc=0x0c06b67cu; return 0; }
r[4]=r[13];
goto P_0c06b67e;
P_0c06b67e: /* original 4c0b, guest PC 0x0c06b67e */
if(!s->budget--) { s->failed_pc=0x0c06b67eu; return 0; }
target=r[12];
r[16]=code_base|0x0c06b682u;
r[4]+=0x0000001bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b682u) { target=s->pc; goto dispatch; }
goto P_0c06b682;
P_0c06b680: /* original 741b, guest PC 0x0c06b680 */
if(!s->budget--) { s->failed_pc=0x0c06b680u; return 0; }
r[4]+=0x0000001bu;
goto P_0c06b682;
P_0c06b682: /* original 640c, guest PC 0x0c06b682 */
if(!s->budget--) { s->failed_pc=0x0c06b682u; return 0; }
r[4]=r[0]&255u;
goto P_0c06b684;
P_0c06b684: /* original 9020, guest PC 0x0c06b684 */
if(!s->budget--) { s->failed_pc=0x0c06b684u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6c8u,2);
goto P_0c06b686;
P_0c06b686: /* original 0e44, guest PC 0x0c06b686 */
if(!s->budget--) { s->failed_pc=0x0c06b686u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c06b688;
P_0c06b688: /* original 64d3, guest PC 0x0c06b688 */
if(!s->budget--) { s->failed_pc=0x0c06b688u; return 0; }
r[4]=r[13];
goto P_0c06b68a;
P_0c06b68a: /* original 4c0b, guest PC 0x0c06b68a */
if(!s->budget--) { s->failed_pc=0x0c06b68au; return 0; }
target=r[12];
r[16]=code_base|0x0c06b68eu;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06b68eu) { target=s->pc; goto dispatch; }
goto P_0c06b68e;
P_0c06b68c: /* original 7412, guest PC 0x0c06b68c */
if(!s->budget--) { s->failed_pc=0x0c06b68cu; return 0; }
r[4]+=0x00000012u;
goto P_0c06b68e;
P_0c06b68e: /* original 640c, guest PC 0x0c06b68e */
if(!s->budget--) { s->failed_pc=0x0c06b68eu; return 0; }
r[4]=r[0]&255u;
goto P_0c06b690;
P_0c06b690: /* original 6043, guest PC 0x0c06b690 */
if(!s->budget--) { s->failed_pc=0x0c06b690u; return 0; }
r[0]=r[4];
goto P_0c06b692;
P_0c06b692: /* original 8801, guest PC 0x0c06b692 */
if(!s->budget--) { s->failed_pc=0x0c06b692u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06b694;
P_0c06b694: /* original 8903, guest PC 0x0c06b694 */
if(!s->budget--) { s->failed_pc=0x0c06b694u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06b69e; }
goto P_0c06b696;
P_0c06b696: /* original 9018, guest PC 0x0c06b696 */
if(!s->budget--) { s->failed_pc=0x0c06b696u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6cau,2);
goto P_0c06b698;
P_0c06b698: /* original e309, guest PC 0x0c06b698 */
if(!s->budget--) { s->failed_pc=0x0c06b698u; return 0; }
r[3]=0x00000009u;
goto P_0c06b69a;
P_0c06b69a: /* original a003, guest PC 0x0c06b69a */
if(!s->budget--) { s->failed_pc=0x0c06b69au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b6a4;
P_0c06b69c: /* original 0e34, guest PC 0x0c06b69c */
if(!s->budget--) { s->failed_pc=0x0c06b69cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c06b69e;
P_0c06b69e: /* original 9014, guest PC 0x0c06b69e */
if(!s->budget--) { s->failed_pc=0x0c06b69eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06b6cau,2);
goto P_0c06b6a0;
P_0c06b6a0: /* original e118, guest PC 0x0c06b6a0 */
if(!s->budget--) { s->failed_pc=0x0c06b6a0u; return 0; }
r[1]=0x00000018u;
goto P_0c06b6a2;
P_0c06b6a2: /* original 0e14, guest PC 0x0c06b6a2 */
if(!s->budget--) { s->failed_pc=0x0c06b6a2u; return 0; }
write(ram,r[14]+r[0],r[1],1);
goto P_0c06b6a4;
P_0c06b6a4: /* original 4f26, guest PC 0x0c06b6a4 */
if(!s->budget--) { s->failed_pc=0x0c06b6a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06b6a6;
P_0c06b6a6: /* original 6af6, guest PC 0x0c06b6a6 */
if(!s->budget--) { s->failed_pc=0x0c06b6a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06b6a8;
P_0c06b6a8: /* original 6bf6, guest PC 0x0c06b6a8 */
if(!s->budget--) { s->failed_pc=0x0c06b6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06b6aa;
P_0c06b6aa: /* original 6cf6, guest PC 0x0c06b6aa */
if(!s->budget--) { s->failed_pc=0x0c06b6aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06b6ac;
P_0c06b6ac: /* original 6df6, guest PC 0x0c06b6ac */
if(!s->budget--) { s->failed_pc=0x0c06b6acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06b6ae;
P_0c06b6ae: /* original 000b, guest PC 0x0c06b6ae */
if(!s->budget--) { s->failed_pc=0x0c06b6aeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06b6b0: /* original 6ef6, guest PC 0x0c06b6b0 */
if(!s->budget--) { s->failed_pc=0x0c06b6b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06b6b2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06b6b2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
