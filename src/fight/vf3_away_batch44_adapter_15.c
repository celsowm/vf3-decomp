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
int vf3_away_batch44_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c06c5c8u: goto P_0c06c5c8;
case 0x0c06c5cau: goto P_0c06c5ca;
case 0x0c06c5ccu: goto P_0c06c5cc;
case 0x0c06c5ceu: goto P_0c06c5ce;
case 0x0c06c5d0u: goto P_0c06c5d0;
case 0x0c06c5d2u: goto P_0c06c5d2;
case 0x0c06c5d4u: goto P_0c06c5d4;
case 0x0c06c5d6u: goto P_0c06c5d6;
case 0x0c06c5d8u: goto P_0c06c5d8;
case 0x0c06c5dau: goto P_0c06c5da;
case 0x0c06c5dcu: goto P_0c06c5dc;
case 0x0c06c5deu: goto P_0c06c5de;
case 0x0c06c5e0u: goto P_0c06c5e0;
case 0x0c06c5e2u: goto P_0c06c5e2;
case 0x0c06c5e4u: goto P_0c06c5e4;
case 0x0c06c5e6u: goto P_0c06c5e6;
case 0x0c06c5e8u: goto P_0c06c5e8;
case 0x0c06c5eau: goto P_0c06c5ea;
case 0x0c06c5ecu: goto P_0c06c5ec;
case 0x0c06c5eeu: goto P_0c06c5ee;
case 0x0c06c5f0u: goto P_0c06c5f0;
case 0x0c06c5f2u: goto P_0c06c5f2;
case 0x0c06c5f4u: goto P_0c06c5f4;
case 0x0c06c5f6u: goto P_0c06c5f6;
case 0x0c06c5f8u: goto P_0c06c5f8;
case 0x0c06c5fau: goto P_0c06c5fa;
case 0x0c06c5fcu: goto P_0c06c5fc;
case 0x0c06c5feu: goto P_0c06c5fe;
case 0x0c06c600u: goto P_0c06c600;
case 0x0c06c602u: goto P_0c06c602;
case 0x0c06c604u: goto P_0c06c604;
case 0x0c06c606u: goto P_0c06c606;
case 0x0c06c608u: goto P_0c06c608;
case 0x0c06c60au: goto P_0c06c60a;
case 0x0c06c60cu: goto P_0c06c60c;
case 0x0c06c60eu: goto P_0c06c60e;
case 0x0c06c610u: goto P_0c06c610;
case 0x0c06c612u: goto P_0c06c612;
case 0x0c06c614u: goto P_0c06c614;
case 0x0c06c616u: goto P_0c06c616;
case 0x0c06c618u: goto P_0c06c618;
case 0x0c06c61au: goto P_0c06c61a;
case 0x0c06c61cu: goto P_0c06c61c;
case 0x0c06c61eu: goto P_0c06c61e;
case 0x0c06c620u: goto P_0c06c620;
case 0x0c06c622u: goto P_0c06c622;
case 0x0c06c624u: goto P_0c06c624;
case 0x0c06c626u: goto P_0c06c626;
case 0x0c06c628u: goto P_0c06c628;
case 0x0c06c62au: goto P_0c06c62a;
case 0x0c06c62cu: goto P_0c06c62c;
case 0x0c06c62eu: goto P_0c06c62e;
case 0x0c06c630u: goto P_0c06c630;
case 0x0c06c632u: goto P_0c06c632;
case 0x0c06c634u: goto P_0c06c634;
case 0x0c06c636u: goto P_0c06c636;
case 0x0c06c638u: goto P_0c06c638;
case 0x0c06c63au: goto P_0c06c63a;
case 0x0c06c63cu: goto P_0c06c63c;
case 0x0c06c63eu: goto P_0c06c63e;
case 0x0c06c640u: goto P_0c06c640;
case 0x0c06c642u: goto P_0c06c642;
case 0x0c06c644u: goto P_0c06c644;
case 0x0c06c646u: goto P_0c06c646;
case 0x0c06c648u: goto P_0c06c648;
case 0x0c06c64au: goto P_0c06c64a;
case 0x0c06c64cu: goto P_0c06c64c;
case 0x0c06c64eu: goto P_0c06c64e;
case 0x0c06c650u: goto P_0c06c650;
case 0x0c06c652u: goto P_0c06c652;
case 0x0c06c654u: goto P_0c06c654;
case 0x0c06c656u: goto P_0c06c656;
case 0x0c06c658u: goto P_0c06c658;
case 0x0c06c65au: goto P_0c06c65a;
case 0x0c06c65cu: goto P_0c06c65c;
case 0x0c06c65eu: goto P_0c06c65e;
case 0x0c06c660u: goto P_0c06c660;
case 0x0c06c662u: goto P_0c06c662;
case 0x0c06c664u: goto P_0c06c664;
case 0x0c06c666u: goto P_0c06c666;
case 0x0c06c668u: goto P_0c06c668;
case 0x0c06c66au: goto P_0c06c66a;
case 0x0c06c66cu: goto P_0c06c66c;
case 0x0c06c66eu: goto P_0c06c66e;
case 0x0c06c670u: goto P_0c06c670;
case 0x0c06c672u: goto P_0c06c672;
case 0x0c06c674u: goto P_0c06c674;
case 0x0c06c676u: goto P_0c06c676;
case 0x0c06c678u: goto P_0c06c678;
case 0x0c06c67au: goto P_0c06c67a;
case 0x0c06c67cu: goto P_0c06c67c;
case 0x0c06c67eu: goto P_0c06c67e;
case 0x0c06c680u: goto P_0c06c680;
case 0x0c06c682u: goto P_0c06c682;
case 0x0c06c684u: goto P_0c06c684;
case 0x0c06c686u: goto P_0c06c686;
case 0x0c06c688u: goto P_0c06c688;
case 0x0c06c68au: goto P_0c06c68a;
case 0x0c06c68cu: goto P_0c06c68c;
case 0x0c06c68eu: goto P_0c06c68e;
case 0x0c06c690u: goto P_0c06c690;
case 0x0c06c692u: goto P_0c06c692;
case 0x0c06c694u: goto P_0c06c694;
case 0x0c06c696u: goto P_0c06c696;
case 0x0c06c698u: goto P_0c06c698;
case 0x0c06c69au: goto P_0c06c69a;
case 0x0c06c69cu: goto P_0c06c69c;
case 0x0c06c69eu: goto P_0c06c69e;
case 0x0c06c6a0u: goto P_0c06c6a0;
case 0x0c06c6a2u: goto P_0c06c6a2;
case 0x0c06c6a4u: goto P_0c06c6a4;
case 0x0c06c6a6u: goto P_0c06c6a6;
case 0x0c06c6a8u: goto P_0c06c6a8;
case 0x0c06c6aau: goto P_0c06c6aa;
case 0x0c06c6acu: goto P_0c06c6ac;
case 0x0c06c6aeu: goto P_0c06c6ae;
case 0x0c06c6b0u: goto P_0c06c6b0;
case 0x0c06c6b2u: goto P_0c06c6b2;
case 0x0c06c6b4u: goto P_0c06c6b4;
case 0x0c06c6b6u: goto P_0c06c6b6;
case 0x0c06c6b8u: goto P_0c06c6b8;
case 0x0c06c6bau: goto P_0c06c6ba;
case 0x0c06c6bcu: goto P_0c06c6bc;
case 0x0c06c6beu: goto P_0c06c6be;
case 0x0c06c6c0u: goto P_0c06c6c0;
case 0x0c06c6c2u: goto P_0c06c6c2;
case 0x0c06c6c4u: goto P_0c06c6c4;
case 0x0c06c6c6u: goto P_0c06c6c6;
case 0x0c06c6c8u: goto P_0c06c6c8;
case 0x0c06c6cau: goto P_0c06c6ca;
case 0x0c06c6ccu: goto P_0c06c6cc;
case 0x0c06c6ceu: goto P_0c06c6ce;
case 0x0c06c6d0u: goto P_0c06c6d0;
case 0x0c06c6d2u: goto P_0c06c6d2;
case 0x0c06c6d4u: goto P_0c06c6d4;
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
P_0c06c5c8: /* original 2fe6, guest PC 0x0c06c5c8 */
if(!s->budget--) { s->failed_pc=0x0c06c5c8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c5ca;
P_0c06c5ca: /* original d346, guest PC 0x0c06c5ca */
if(!s->budget--) { s->failed_pc=0x0c06c5cau; return 0; }
r[3]=read(ram,0x0c06c6e4u,4);
goto P_0c06c5cc;
P_0c06c5cc: /* original d246, guest PC 0x0c06c5cc */
if(!s->budget--) { s->failed_pc=0x0c06c5ccu; return 0; }
r[2]=read(ram,0x0c06c6e8u,4);
goto P_0c06c5ce;
P_0c06c5ce: /* original 6530, guest PC 0x0c06c5ce */
if(!s->budget--) { s->failed_pc=0x0c06c5ceu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[5]=tmp;
goto P_0c06c5d0;
P_0c06c5d0: /* original 4f22, guest PC 0x0c06c5d0 */
if(!s->budget--) { s->failed_pc=0x0c06c5d0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c5d2;
P_0c06c5d2: /* original 6422, guest PC 0x0c06c5d2 */
if(!s->budget--) { s->failed_pc=0x0c06c5d2u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c5d4;
P_0c06c5d4: /* original 655c, guest PC 0x0c06c5d4 */
if(!s->budget--) { s->failed_pc=0x0c06c5d4u; return 0; }
r[5]=r[5]&255u;
goto P_0c06c5d6;
P_0c06c5d6: /* original de42, guest PC 0x0c06c5d6 */
if(!s->budget--) { s->failed_pc=0x0c06c5d6u; return 0; }
r[14]=read(ram,0x0c06c6e0u,4);
goto P_0c06c5d8;
P_0c06c5d8: /* original 2558, guest PC 0x0c06c5d8 */
if(!s->budget--) { s->failed_pc=0x0c06c5d8u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c06c5da;
P_0c06c5da: /* original 8d0f, guest PC 0x0c06c5da */
if(!s->budget--) { s->failed_pc=0x0c06c5dau; return 0; }
cond=r[17]&1u;
r[4]+=0x00000001u;
if(cond) { goto P_0c06c5fc; }
goto P_0c06c5de;
P_0c06c5dc: /* original 7401, guest PC 0x0c06c5dc */
if(!s->budget--) { s->failed_pc=0x0c06c5dcu; return 0; }
r[4]+=0x00000001u;
goto P_0c06c5de;
P_0c06c5de: /* original 6053, guest PC 0x0c06c5de */
if(!s->budget--) { s->failed_pc=0x0c06c5deu; return 0; }
r[0]=r[5];
goto P_0c06c5e0;
P_0c06c5e0: /* original 8801, guest PC 0x0c06c5e0 */
if(!s->budget--) { s->failed_pc=0x0c06c5e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06c5e2;
P_0c06c5e2: /* original 8b05, guest PC 0x0c06c5e2 */
if(!s->budget--) { s->failed_pc=0x0c06c5e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c5f0; }
goto P_0c06c5e4;
P_0c06c5e4: /* original 4f26, guest PC 0x0c06c5e4 */
if(!s->budget--) { s->failed_pc=0x0c06c5e4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5e6;
P_0c06c5e6: /* original 6543, guest PC 0x0c06c5e6 */
if(!s->budget--) { s->failed_pc=0x0c06c5e6u; return 0; }
r[5]=r[4];
goto P_0c06c5e8;
P_0c06c5e8: /* original e404, guest PC 0x0c06c5e8 */
if(!s->budget--) { s->failed_pc=0x0c06c5e8u; return 0; }
r[4]=0x00000004u;
goto P_0c06c5ea;
P_0c06c5ea: /* original e627, guest PC 0x0c06c5ea */
if(!s->budget--) { s->failed_pc=0x0c06c5eau; return 0; }
r[6]=0x00000027u;
goto P_0c06c5ec;
P_0c06c5ec: /* original a023, guest PC 0x0c06c5ec */
if(!s->budget--) { s->failed_pc=0x0c06c5ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c636;
P_0c06c5ee: /* original 6ef6, guest PC 0x0c06c5ee */
if(!s->budget--) { s->failed_pc=0x0c06c5eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5f0;
P_0c06c5f0: /* original 4f26, guest PC 0x0c06c5f0 */
if(!s->budget--) { s->failed_pc=0x0c06c5f0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c5f2;
P_0c06c5f2: /* original 6543, guest PC 0x0c06c5f2 */
if(!s->budget--) { s->failed_pc=0x0c06c5f2u; return 0; }
r[5]=r[4];
goto P_0c06c5f4;
P_0c06c5f4: /* original e427, guest PC 0x0c06c5f4 */
if(!s->budget--) { s->failed_pc=0x0c06c5f4u; return 0; }
r[4]=0x00000027u;
goto P_0c06c5f6;
P_0c06c5f6: /* original e604, guest PC 0x0c06c5f6 */
if(!s->budget--) { s->failed_pc=0x0c06c5f6u; return 0; }
r[6]=0x00000004u;
goto P_0c06c5f8;
P_0c06c5f8: /* original a01d, guest PC 0x0c06c5f8 */
if(!s->budget--) { s->failed_pc=0x0c06c5f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c636;
P_0c06c5fa: /* original 6ef6, guest PC 0x0c06c5fa */
if(!s->budget--) { s->failed_pc=0x0c06c5fau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c5fc;
P_0c06c5fc: /* original e307, guest PC 0x0c06c5fc */
if(!s->budget--) { s->failed_pc=0x0c06c5fcu; return 0; }
r[3]=0x00000007u;
goto P_0c06c5fe;
P_0c06c5fe: /* original e220, guest PC 0x0c06c5fe */
if(!s->budget--) { s->failed_pc=0x0c06c5feu; return 0; }
r[2]=0x00000020u;
goto P_0c06c600;
P_0c06c600: /* original e508, guest PC 0x0c06c600 */
if(!s->budget--) { s->failed_pc=0x0c06c600u; return 0; }
r[5]=0x00000008u;
goto P_0c06c602;
P_0c06c602: /* original 2f26, guest PC 0x0c06c602 */
if(!s->budget--) { s->failed_pc=0x0c06c602u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c604;
P_0c06c604: /* original d139, guest PC 0x0c06c604 */
if(!s->budget--) { s->failed_pc=0x0c06c604u; return 0; }
r[1]=read(ram,0x0c06c6ecu,4);
goto P_0c06c606;
P_0c06c606: /* original 443c, guest PC 0x0c06c606 */
if(!s->budget--) { s->failed_pc=0x0c06c606u; return 0; }
r[4]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[4]>>((-r[3])&31u)):((int32_t)r[4]<0?0xffffffffu:0)):r[4]<<(r[3]&31u);
goto P_0c06c608;
P_0c06c608: /* original e615, guest PC 0x0c06c608 */
if(!s->budget--) { s->failed_pc=0x0c06c608u; return 0; }
r[6]=0x00000015u;
goto P_0c06c60a;
P_0c06c60a: /* original e701, guest PC 0x0c06c60a */
if(!s->budget--) { s->failed_pc=0x0c06c60au; return 0; }
r[7]=0x00000001u;
goto P_0c06c60c;
P_0c06c60c: /* original 254b, guest PC 0x0c06c60c */
if(!s->budget--) { s->failed_pc=0x0c06c60cu; return 0; }
r[5]|=r[4];
goto P_0c06c60e;
P_0c06c60e: /* original 410b, guest PC 0x0c06c60e */
if(!s->budget--) { s->failed_pc=0x0c06c60eu; return 0; }
target=r[1];
r[16]=code_base|0x0c06c612u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c612u) { target=s->pc; goto dispatch; }
goto P_0c06c612;
P_0c06c610: /* original 64e3, guest PC 0x0c06c610 */
if(!s->budget--) { s->failed_pc=0x0c06c610u; return 0; }
r[4]=r[14];
goto P_0c06c612;
P_0c06c612: /* original d335, guest PC 0x0c06c612 */
if(!s->budget--) { s->failed_pc=0x0c06c612u; return 0; }
r[3]=read(ram,0x0c06c6e8u,4);
goto P_0c06c614;
P_0c06c614: /* original e207, guest PC 0x0c06c614 */
if(!s->budget--) { s->failed_pc=0x0c06c614u; return 0; }
r[2]=0x00000007u;
goto P_0c06c616;
P_0c06c616: /* original e120, guest PC 0x0c06c616 */
if(!s->budget--) { s->failed_pc=0x0c06c616u; return 0; }
r[1]=0x00000020u;
goto P_0c06c618;
P_0c06c618: /* original 6032, guest PC 0x0c06c618 */
if(!s->budget--) { s->failed_pc=0x0c06c618u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c06c61a;
P_0c06c61a: /* original e54e, guest PC 0x0c06c61a */
if(!s->budget--) { s->failed_pc=0x0c06c61au; return 0; }
r[5]=0x0000004eu;
goto P_0c06c61c;
P_0c06c61c: /* original e615, guest PC 0x0c06c61c */
if(!s->budget--) { s->failed_pc=0x0c06c61cu; return 0; }
r[6]=0x00000015u;
goto P_0c06c61e;
P_0c06c61e: /* original 2f16, guest PC 0x0c06c61e */
if(!s->budget--) { s->failed_pc=0x0c06c61eu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c620;
P_0c06c620: /* original 7001, guest PC 0x0c06c620 */
if(!s->budget--) { s->failed_pc=0x0c06c620u; return 0; }
r[0]+=0x00000001u;
goto P_0c06c622;
P_0c06c622: /* original d332, guest PC 0x0c06c622 */
if(!s->budget--) { s->failed_pc=0x0c06c622u; return 0; }
r[3]=read(ram,0x0c06c6ecu,4);
goto P_0c06c624;
P_0c06c624: /* original 402c, guest PC 0x0c06c624 */
if(!s->budget--) { s->failed_pc=0x0c06c624u; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c06c626;
P_0c06c626: /* original e701, guest PC 0x0c06c626 */
if(!s->budget--) { s->failed_pc=0x0c06c626u; return 0; }
r[7]=0x00000001u;
goto P_0c06c628;
P_0c06c628: /* original 250b, guest PC 0x0c06c628 */
if(!s->budget--) { s->failed_pc=0x0c06c628u; return 0; }
r[5]|=r[0];
goto P_0c06c62a;
P_0c06c62a: /* original 430b, guest PC 0x0c06c62a */
if(!s->budget--) { s->failed_pc=0x0c06c62au; return 0; }
target=r[3];
r[16]=code_base|0x0c06c62eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c62eu) { target=s->pc; goto dispatch; }
goto P_0c06c62e;
P_0c06c62c: /* original 64e3, guest PC 0x0c06c62c */
if(!s->budget--) { s->failed_pc=0x0c06c62cu; return 0; }
r[4]=r[14];
goto P_0c06c62e;
P_0c06c62e: /* original 7f08, guest PC 0x0c06c62e */
if(!s->budget--) { s->failed_pc=0x0c06c62eu; return 0; }
r[15]+=0x00000008u;
goto P_0c06c630;
P_0c06c630: /* original 4f26, guest PC 0x0c06c630 */
if(!s->budget--) { s->failed_pc=0x0c06c630u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c632;
P_0c06c632: /* original 000b, guest PC 0x0c06c632 */
if(!s->budget--) { s->failed_pc=0x0c06c632u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c634: /* original 6ef6, guest PC 0x0c06c634 */
if(!s->budget--) { s->failed_pc=0x0c06c634u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c636;
P_0c06c636: /* original 2fe6, guest PC 0x0c06c636 */
if(!s->budget--) { s->failed_pc=0x0c06c636u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c638;
P_0c06c638: /* original 4400, guest PC 0x0c06c638 */
if(!s->budget--) { s->failed_pc=0x0c06c638u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c63a;
P_0c06c63a: /* original 4f22, guest PC 0x0c06c63a */
if(!s->budget--) { s->failed_pc=0x0c06c63au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c63c;
P_0c06c63c: /* original e101, guest PC 0x0c06c63c */
if(!s->budget--) { s->failed_pc=0x0c06c63cu; return 0; }
r[1]=0x00000001u;
goto P_0c06c63e;
P_0c06c63e: /* original 6e53, guest PC 0x0c06c63e */
if(!s->budget--) { s->failed_pc=0x0c06c63eu; return 0; }
r[14]=r[5];
goto P_0c06c640;
P_0c06c640: /* original 7ff8, guest PC 0x0c06c640 */
if(!s->budget--) { s->failed_pc=0x0c06c640u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06c642;
P_0c06c642: /* original 2f62, guest PC 0x0c06c642 */
if(!s->budget--) { s->failed_pc=0x0c06c642u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c644;
P_0c06c644: /* original 6643, guest PC 0x0c06c644 */
if(!s->budget--) { s->failed_pc=0x0c06c644u; return 0; }
r[6]=r[4];
goto P_0c06c646;
P_0c06c646: /* original d326, guest PC 0x0c06c646 */
if(!s->budget--) { s->failed_pc=0x0c06c646u; return 0; }
r[3]=read(ram,0x0c06c6e0u,4);
goto P_0c06c648;
P_0c06c648: /* original 1f31, guest PC 0x0c06c648 */
if(!s->budget--) { s->failed_pc=0x0c06c648u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c06c64a;
P_0c06c64a: /* original e307, guest PC 0x0c06c64a */
if(!s->budget--) { s->failed_pc=0x0c06c64au; return 0; }
r[3]=0x00000007u;
goto P_0c06c64c;
P_0c06c64c: /* original d228, guest PC 0x0c06c64c */
if(!s->budget--) { s->failed_pc=0x0c06c64cu; return 0; }
r[2]=read(ram,0x0c06c6f0u,4);
goto P_0c06c64e;
P_0c06c64e: /* original 4e3d, guest PC 0x0c06c64e */
if(!s->budget--) { s->failed_pc=0x0c06c64eu; return 0; }
r[14]=(r[3]&0x80000000u)?((r[3]&31u)?r[14]>>((-r[3])&31u):0):r[14]<<(r[3]&31u);
goto P_0c06c650;
P_0c06c650: /* original 6422, guest PC 0x0c06c650 */
if(!s->budget--) { s->failed_pc=0x0c06c650u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c652;
P_0c06c652: /* original 3416, guest PC 0x0c06c652 */
if(!s->budget--) { s->failed_pc=0x0c06c652u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[1])!=0);
goto P_0c06c654;
P_0c06c654: /* original 8d03, guest PC 0x0c06c654 */
if(!s->budget--) { s->failed_pc=0x0c06c654u; return 0; }
cond=r[17]&1u;
r[6]|=r[14];
if(cond) { goto P_0c06c65e; }
goto P_0c06c658;
P_0c06c656: /* original 26eb, guest PC 0x0c06c656 */
if(!s->budget--) { s->failed_pc=0x0c06c656u; return 0; }
r[6]|=r[14];
goto P_0c06c658;
P_0c06c658: /* original d526, guest PC 0x0c06c658 */
if(!s->budget--) { s->failed_pc=0x0c06c658u; return 0; }
r[5]=read(ram,0x0c06c6f4u,4);
goto P_0c06c65a;
P_0c06c65a: /* original a001, guest PC 0x0c06c65a */
if(!s->budget--) { s->failed_pc=0x0c06c65au; return 0; }
goto P_0c06c660;
P_0c06c65c: /* original 0009, guest PC 0x0c06c65c */
if(!s->budget--) { s->failed_pc=0x0c06c65cu; return 0; }
goto P_0c06c65e;
P_0c06c65e: /* original d526, guest PC 0x0c06c65e */
if(!s->budget--) { s->failed_pc=0x0c06c65eu; return 0; }
r[5]=read(ram,0x0c06c6f8u,4);
goto P_0c06c660;
P_0c06c660: /* original b023, guest PC 0x0c06c660 */
if(!s->budget--) { s->failed_pc=0x0c06c660u; return 0; }
target=code_base|0x0c06c6aau; r[16]=code_base|0x0c06c664u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c664u) { target=s->pc; goto dispatch; }
goto P_0c06c664;
P_0c06c662: /* original 0009, guest PC 0x0c06c662 */
if(!s->budget--) { s->failed_pc=0x0c06c662u; return 0; }
goto P_0c06c664;
P_0c06c664: /* original d225, guest PC 0x0c06c664 */
if(!s->budget--) { s->failed_pc=0x0c06c664u; return 0; }
r[2]=read(ram,0x0c06c6fcu,4);
goto P_0c06c666;
P_0c06c666: /* original d326, guest PC 0x0c06c666 */
if(!s->budget--) { s->failed_pc=0x0c06c666u; return 0; }
r[3]=read(ram,0x0c06c700u,4);
goto P_0c06c668;
P_0c06c668: /* original 6422, guest PC 0x0c06c668 */
if(!s->budget--) { s->failed_pc=0x0c06c668u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c06c66a;
P_0c06c66a: /* original 2438, guest PC 0x0c06c66a */
if(!s->budget--) { s->failed_pc=0x0c06c66au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c06c66c;
P_0c06c66c: /* original 8b0e, guest PC 0x0c06c66c */
if(!s->budget--) { s->failed_pc=0x0c06c66cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c68c; }
goto P_0c06c66e;
P_0c06c66e: /* original d125, guest PC 0x0c06c66e */
if(!s->budget--) { s->failed_pc=0x0c06c66eu; return 0; }
r[1]=read(ram,0x0c06c704u,4);
goto P_0c06c670;
P_0c06c670: /* original 6010, guest PC 0x0c06c670 */
if(!s->budget--) { s->failed_pc=0x0c06c670u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[0]=tmp;
goto P_0c06c672;
P_0c06c672: /* original 600c, guest PC 0x0c06c672 */
if(!s->budget--) { s->failed_pc=0x0c06c672u; return 0; }
r[0]=r[0]&255u;
goto P_0c06c674;
P_0c06c674: /* original 8803, guest PC 0x0c06c674 */
if(!s->budget--) { s->failed_pc=0x0c06c674u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c06c676;
P_0c06c676: /* original 8b14, guest PC 0x0c06c676 */
if(!s->budget--) { s->failed_pc=0x0c06c676u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06c6a2; }
goto P_0c06c678;
P_0c06c678: /* original 64f2, guest PC 0x0c06c678 */
if(!s->budget--) { s->failed_pc=0x0c06c678u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06c67a;
P_0c06c67a: /* original d523, guest PC 0x0c06c67a */
if(!s->budget--) { s->failed_pc=0x0c06c67au; return 0; }
r[5]=read(ram,0x0c06c708u,4);
goto P_0c06c67c;
P_0c06c67c: /* original 7403, guest PC 0x0c06c67c */
if(!s->budget--) { s->failed_pc=0x0c06c67cu; return 0; }
r[4]+=0x00000003u;
goto P_0c06c67e;
P_0c06c67e: /* original d223, guest PC 0x0c06c67e */
if(!s->budget--) { s->failed_pc=0x0c06c67eu; return 0; }
r[2]=read(ram,0x0c06c70cu,4);
goto P_0c06c680;
P_0c06c680: /* original 4400, guest PC 0x0c06c680 */
if(!s->budget--) { s->failed_pc=0x0c06c680u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06c682;
P_0c06c682: /* original 24eb, guest PC 0x0c06c682 */
if(!s->budget--) { s->failed_pc=0x0c06c682u; return 0; }
r[4]|=r[14];
goto P_0c06c684;
P_0c06c684: /* original 420b, guest PC 0x0c06c684 */
if(!s->budget--) { s->failed_pc=0x0c06c684u; return 0; }
target=r[2];
r[16]=code_base|0x0c06c688u;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c688u) { target=s->pc; goto dispatch; }
goto P_0c06c688;
P_0c06c686: /* original e601, guest PC 0x0c06c686 */
if(!s->budget--) { s->failed_pc=0x0c06c686u; return 0; }
r[6]=0x00000001u;
goto P_0c06c688;
P_0c06c688: /* original a00b, guest PC 0x0c06c688 */
if(!s->budget--) { s->failed_pc=0x0c06c688u; return 0; }
goto P_0c06c6a2;
P_0c06c68a: /* original 0009, guest PC 0x0c06c68a */
if(!s->budget--) { s->failed_pc=0x0c06c68au; return 0; }
goto P_0c06c68c;
P_0c06c68c: /* original 65f2, guest PC 0x0c06c68c */
if(!s->budget--) { s->failed_pc=0x0c06c68cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c06c68e;
P_0c06c68e: /* original e120, guest PC 0x0c06c68e */
if(!s->budget--) { s->failed_pc=0x0c06c68eu; return 0; }
r[1]=0x00000020u;
goto P_0c06c690;
P_0c06c690: /* original e615, guest PC 0x0c06c690 */
if(!s->budget--) { s->failed_pc=0x0c06c690u; return 0; }
r[6]=0x00000015u;
goto P_0c06c692;
P_0c06c692: /* original 2f16, guest PC 0x0c06c692 */
if(!s->budget--) { s->failed_pc=0x0c06c692u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c694;
P_0c06c694: /* original d215, guest PC 0x0c06c694 */
if(!s->budget--) { s->failed_pc=0x0c06c694u; return 0; }
r[2]=read(ram,0x0c06c6ecu,4);
goto P_0c06c696;
P_0c06c696: /* original 4500, guest PC 0x0c06c696 */
if(!s->budget--) { s->failed_pc=0x0c06c696u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c06c698;
P_0c06c698: /* original e701, guest PC 0x0c06c698 */
if(!s->budget--) { s->failed_pc=0x0c06c698u; return 0; }
r[7]=0x00000001u;
goto P_0c06c69a;
P_0c06c69a: /* original 25eb, guest PC 0x0c06c69a */
if(!s->budget--) { s->failed_pc=0x0c06c69au; return 0; }
r[5]|=r[14];
goto P_0c06c69c;
P_0c06c69c: /* original 420b, guest PC 0x0c06c69c */
if(!s->budget--) { s->failed_pc=0x0c06c69cu; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6a0u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6a0u) { target=s->pc; goto dispatch; }
goto P_0c06c6a0;
P_0c06c69e: /* original 54f2, guest PC 0x0c06c69e */
if(!s->budget--) { s->failed_pc=0x0c06c69eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c06c6a0;
P_0c06c6a0: /* original 7f04, guest PC 0x0c06c6a0 */
if(!s->budget--) { s->failed_pc=0x0c06c6a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c06c6a2;
P_0c06c6a2: /* original 7f08, guest PC 0x0c06c6a2 */
if(!s->budget--) { s->failed_pc=0x0c06c6a2u; return 0; }
r[15]+=0x00000008u;
goto P_0c06c6a4;
P_0c06c6a4: /* original 4f26, guest PC 0x0c06c6a4 */
if(!s->budget--) { s->failed_pc=0x0c06c6a4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6a6;
P_0c06c6a6: /* original 000b, guest PC 0x0c06c6a6 */
if(!s->budget--) { s->failed_pc=0x0c06c6a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06c6a8: /* original 6ef6, guest PC 0x0c06c6a8 */
if(!s->budget--) { s->failed_pc=0x0c06c6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06c6aa;
P_0c06c6aa: /* original 4f22, guest PC 0x0c06c6aa */
if(!s->budget--) { s->failed_pc=0x0c06c6aau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06c6ac;
P_0c06c6ac: /* original 7ff4, guest PC 0x0c06c6ac */
if(!s->budget--) { s->failed_pc=0x0c06c6acu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c06c6ae;
P_0c06c6ae: /* original 1f41, guest PC 0x0c06c6ae */
if(!s->budget--) { s->failed_pc=0x0c06c6aeu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c06c6b0;
P_0c06c6b0: /* original 1f52, guest PC 0x0c06c6b0 */
if(!s->budget--) { s->failed_pc=0x0c06c6b0u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c06c6b2;
P_0c06c6b2: /* original 2f62, guest PC 0x0c06c6b2 */
if(!s->budget--) { s->failed_pc=0x0c06c6b2u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c06c6b4;
P_0c06c6b4: /* original 53f2, guest PC 0x0c06c6b4 */
if(!s->budget--) { s->failed_pc=0x0c06c6b4u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c06c6b6;
P_0c06c6b6: /* original 2f36, guest PC 0x0c06c6b6 */
if(!s->budget--) { s->failed_pc=0x0c06c6b6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6b8;
P_0c06c6b8: /* original d215, guest PC 0x0c06c6b8 */
if(!s->budget--) { s->failed_pc=0x0c06c6b8u; return 0; }
r[2]=read(ram,0x0c06c710u,4);
goto P_0c06c6ba;
P_0c06c6ba: /* original 2f26, guest PC 0x0c06c6ba */
if(!s->budget--) { s->failed_pc=0x0c06c6bau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6bc;
P_0c06c6bc: /* original 53f3, guest PC 0x0c06c6bc */
if(!s->budget--) { s->failed_pc=0x0c06c6bcu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06c6be;
P_0c06c6be: /* original 2f36, guest PC 0x0c06c6be */
if(!s->budget--) { s->failed_pc=0x0c06c6beu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c0;
P_0c06c6c0: /* original d114, guest PC 0x0c06c6c0 */
if(!s->budget--) { s->failed_pc=0x0c06c6c0u; return 0; }
r[1]=read(ram,0x0c06c714u,4);
goto P_0c06c6c2;
P_0c06c6c2: /* original 2f16, guest PC 0x0c06c6c2 */
if(!s->budget--) { s->failed_pc=0x0c06c6c2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c4;
P_0c06c6c4: /* original d314, guest PC 0x0c06c6c4 */
if(!s->budget--) { s->failed_pc=0x0c06c6c4u; return 0; }
r[3]=read(ram,0x0c06c718u,4);
goto P_0c06c6c6;
P_0c06c6c6: /* original 2f36, guest PC 0x0c06c6c6 */
if(!s->budget--) { s->failed_pc=0x0c06c6c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06c6c8;
P_0c06c6c8: /* original d214, guest PC 0x0c06c6c8 */
if(!s->budget--) { s->failed_pc=0x0c06c6c8u; return 0; }
r[2]=read(ram,0x0c06c71cu,4);
goto P_0c06c6ca;
P_0c06c6ca: /* original 420b, guest PC 0x0c06c6ca */
if(!s->budget--) { s->failed_pc=0x0c06c6cau; return 0; }
target=r[2];
r[16]=code_base|0x0c06c6ceu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06c6ceu) { target=s->pc; goto dispatch; }
goto P_0c06c6ce;
P_0c06c6cc: /* original 54f5, guest PC 0x0c06c6cc */
if(!s->budget--) { s->failed_pc=0x0c06c6ccu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c06c6ce;
P_0c06c6ce: /* original 7f20, guest PC 0x0c06c6ce */
if(!s->budget--) { s->failed_pc=0x0c06c6ceu; return 0; }
r[15]+=0x00000020u;
goto P_0c06c6d0;
P_0c06c6d0: /* original 4f26, guest PC 0x0c06c6d0 */
if(!s->budget--) { s->failed_pc=0x0c06c6d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06c6d2;
P_0c06c6d2: /* original 000b, guest PC 0x0c06c6d2 */
if(!s->budget--) { s->failed_pc=0x0c06c6d2u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06c6d4: /* original 0009, guest PC 0x0c06c6d4 */
if(!s->budget--) { s->failed_pc=0x0c06c6d4u; return 0; }
return vf3_matrix_family(0x0c06c6d6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
