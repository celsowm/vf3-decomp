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
int vf3_away_batch174_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
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
case 0x0c062e7eu: goto P_0c062e7e;
case 0x0c062e80u: goto P_0c062e80;
case 0x0c062e82u: goto P_0c062e82;
case 0x0c062e84u: goto P_0c062e84;
case 0x0c062e86u: goto P_0c062e86;
case 0x0c062e88u: goto P_0c062e88;
case 0x0c062e8au: goto P_0c062e8a;
case 0x0c062e8cu: goto P_0c062e8c;
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
case 0x0c07a7e8u: goto P_0c07a7e8;
case 0x0c07a7eau: goto P_0c07a7ea;
case 0x0c07a7ecu: goto P_0c07a7ec;
case 0x0c07a7eeu: goto P_0c07a7ee;
case 0x0c07a7f0u: goto P_0c07a7f0;
case 0x0c07a7f2u: goto P_0c07a7f2;
case 0x0c07a7f4u: goto P_0c07a7f4;
case 0x0c07a7f6u: goto P_0c07a7f6;
case 0x0c07a7f8u: goto P_0c07a7f8;
case 0x0c07a7fau: goto P_0c07a7fa;
case 0x0c07a7fcu: goto P_0c07a7fc;
case 0x0c07a7feu: goto P_0c07a7fe;
case 0x0c07a800u: goto P_0c07a800;
case 0x0c07a802u: goto P_0c07a802;
case 0x0c07a804u: goto P_0c07a804;
case 0x0c07a806u: goto P_0c07a806;
case 0x0c07a808u: goto P_0c07a808;
case 0x0c07a80au: goto P_0c07a80a;
case 0x0c07a80cu: goto P_0c07a80c;
case 0x0c07a80eu: goto P_0c07a80e;
case 0x0c07a810u: goto P_0c07a810;
case 0x0c07a812u: goto P_0c07a812;
case 0x0c07a814u: goto P_0c07a814;
case 0x0c07a816u: goto P_0c07a816;
case 0x0c07a818u: goto P_0c07a818;
case 0x0c07a81au: goto P_0c07a81a;
case 0x0c07a81cu: goto P_0c07a81c;
case 0x0c07a81eu: goto P_0c07a81e;
case 0x0c07a820u: goto P_0c07a820;
case 0x0c07a822u: goto P_0c07a822;
case 0x0c07a824u: goto P_0c07a824;
case 0x0c07a826u: goto P_0c07a826;
case 0x0c07a828u: goto P_0c07a828;
case 0x0c07a82au: goto P_0c07a82a;
case 0x0c07a82cu: goto P_0c07a82c;
case 0x0c07a82eu: goto P_0c07a82e;
case 0x0c07a830u: goto P_0c07a830;
case 0x0c07a832u: goto P_0c07a832;
case 0x0c07a834u: goto P_0c07a834;
case 0x0c07a836u: goto P_0c07a836;
case 0x0c07a838u: goto P_0c07a838;
case 0x0c07a83au: goto P_0c07a83a;
case 0x0c07a83cu: goto P_0c07a83c;
case 0x0c07a83eu: goto P_0c07a83e;
case 0x0c07a840u: goto P_0c07a840;
case 0x0c07a842u: goto P_0c07a842;
case 0x0c07ab14u: goto P_0c07ab14;
case 0x0c07ab16u: goto P_0c07ab16;
case 0x0c07ab18u: goto P_0c07ab18;
case 0x0c07ab1au: goto P_0c07ab1a;
case 0x0c07ab1cu: goto P_0c07ab1c;
case 0x0c07ab1eu: goto P_0c07ab1e;
case 0x0c07ab20u: goto P_0c07ab20;
case 0x0c07ab22u: goto P_0c07ab22;
case 0x0c07ab24u: goto P_0c07ab24;
case 0x0c07ab26u: goto P_0c07ab26;
case 0x0c07ab28u: goto P_0c07ab28;
case 0x0c07ab2au: goto P_0c07ab2a;
case 0x0c07ab2cu: goto P_0c07ab2c;
case 0x0c07ab2eu: goto P_0c07ab2e;
case 0x0c07ab30u: goto P_0c07ab30;
case 0x0c07ab32u: goto P_0c07ab32;
case 0x0c07ab34u: goto P_0c07ab34;
case 0x0c07ab36u: goto P_0c07ab36;
case 0x0c07ab38u: goto P_0c07ab38;
case 0x0c07ab3au: goto P_0c07ab3a;
case 0x0c07ab3cu: goto P_0c07ab3c;
case 0x0c07ab3eu: goto P_0c07ab3e;
case 0x0c07ab40u: goto P_0c07ab40;
case 0x0c07ab42u: goto P_0c07ab42;
case 0x0c07ab44u: goto P_0c07ab44;
case 0x0c07ab46u: goto P_0c07ab46;
case 0x0c07ab48u: goto P_0c07ab48;
case 0x0c07ab4au: goto P_0c07ab4a;
case 0x0c07ab4cu: goto P_0c07ab4c;
case 0x0c07ab4eu: goto P_0c07ab4e;
case 0x0c07ab50u: goto P_0c07ab50;
case 0x0c07ab52u: goto P_0c07ab52;
case 0x0c07ab54u: goto P_0c07ab54;
case 0x0c07ab56u: goto P_0c07ab56;
case 0x0c07ab58u: goto P_0c07ab58;
case 0x0c07ab5au: goto P_0c07ab5a;
case 0x0c07ab5cu: goto P_0c07ab5c;
case 0x0c07ab5eu: goto P_0c07ab5e;
case 0x0c07ab60u: goto P_0c07ab60;
case 0x0c07ab62u: goto P_0c07ab62;
case 0x0c07ab64u: goto P_0c07ab64;
case 0x0c07ab66u: goto P_0c07ab66;
case 0x0c07ab68u: goto P_0c07ab68;
case 0x0c07ab6au: goto P_0c07ab6a;
case 0x0c07ab6cu: goto P_0c07ab6c;
case 0x0c07ab6eu: goto P_0c07ab6e;
case 0x0c07ab70u: goto P_0c07ab70;
case 0x0c07ab72u: goto P_0c07ab72;
case 0x0c07ab74u: goto P_0c07ab74;
case 0x0c07ab76u: goto P_0c07ab76;
case 0x0c07ab78u: goto P_0c07ab78;
case 0x0c07ab7au: goto P_0c07ab7a;
case 0x0c07ab7cu: goto P_0c07ab7c;
case 0x0c07ab7eu: goto P_0c07ab7e;
case 0x0c07ab80u: goto P_0c07ab80;
case 0x0c07ab82u: goto P_0c07ab82;
case 0x0c07ab84u: goto P_0c07ab84;
case 0x0c07ab86u: goto P_0c07ab86;
case 0x0c07ab88u: goto P_0c07ab88;
case 0x0c07ab8au: goto P_0c07ab8a;
case 0x0c07ab8cu: goto P_0c07ab8c;
case 0x0c07ab8eu: goto P_0c07ab8e;
case 0x0c07ab90u: goto P_0c07ab90;
case 0x0c07ab92u: goto P_0c07ab92;
case 0x0c07ab94u: goto P_0c07ab94;
case 0x0c07ab96u: goto P_0c07ab96;
case 0x0c07ab98u: goto P_0c07ab98;
case 0x0c07ab9au: goto P_0c07ab9a;
case 0x0c07ab9cu: goto P_0c07ab9c;
case 0x0c07ab9eu: goto P_0c07ab9e;
case 0x0c07aba0u: goto P_0c07aba0;
case 0x0c07aba2u: goto P_0c07aba2;
case 0x0c07aba4u: goto P_0c07aba4;
case 0x0c07aba6u: goto P_0c07aba6;
case 0x0c07aba8u: goto P_0c07aba8;
case 0x0c07abaau: goto P_0c07abaa;
case 0x0c07abacu: goto P_0c07abac;
case 0x0c07abaeu: goto P_0c07abae;
case 0x0c07abb0u: goto P_0c07abb0;
case 0x0c07abb2u: goto P_0c07abb2;
case 0x0c07abb4u: goto P_0c07abb4;
case 0x0c07abb6u: goto P_0c07abb6;
case 0x0c07abb8u: goto P_0c07abb8;
case 0x0c07abbau: goto P_0c07abba;
case 0x0c07abbcu: goto P_0c07abbc;
case 0x0c07abbeu: goto P_0c07abbe;
case 0x0c07abc0u: goto P_0c07abc0;
case 0x0c07abc2u: goto P_0c07abc2;
case 0x0c07abc4u: goto P_0c07abc4;
case 0x0c07abc6u: goto P_0c07abc6;
case 0x0c07abc8u: goto P_0c07abc8;
case 0x0c07abcau: goto P_0c07abca;
case 0x0c07abccu: goto P_0c07abcc;
case 0x0c07abceu: goto P_0c07abce;
case 0x0c07abd0u: goto P_0c07abd0;
case 0x0c07abd2u: goto P_0c07abd2;
case 0x0c07abd4u: goto P_0c07abd4;
case 0x0c07abd6u: goto P_0c07abd6;
case 0x0c07abd8u: goto P_0c07abd8;
case 0x0c07abdau: goto P_0c07abda;
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
P_0c062e7e: /* original 4609, guest PC 0x0c062e7e */
if(!s->budget--) { s->failed_pc=0x0c062e7eu; return 0; }
r[6]>>=2;
goto P_0c062e80;
P_0c062e80: /* original 6056, guest PC 0x0c062e80 */
if(!s->budget--) { s->failed_pc=0x0c062e80u; return 0; }
tmp=read(ram,r[5],4);
r[5]+=4;
r[0]=tmp;
goto P_0c062e82;
P_0c062e82: /* original 4610, guest PC 0x0c062e82 */
if(!s->budget--) { s->failed_pc=0x0c062e82u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c062e84;
P_0c062e84: /* original 2402, guest PC 0x0c062e84 */
if(!s->budget--) { s->failed_pc=0x0c062e84u; return 0; }
write(ram,r[4],r[0],4);
goto P_0c062e86;
P_0c062e86: /* original 8ffb, guest PC 0x0c062e86 */
if(!s->budget--) { s->failed_pc=0x0c062e86u; return 0; }
cond=r[17]&1u;
r[4]+=0x00000004u;
if(!cond) { goto P_0c062e80; }
goto P_0c062e8a;
P_0c062e88: /* original 7404, guest PC 0x0c062e88 */
if(!s->budget--) { s->failed_pc=0x0c062e88u; return 0; }
r[4]+=0x00000004u;
goto P_0c062e8a;
P_0c062e8a: /* original 000b, guest PC 0x0c062e8a */
if(!s->budget--) { s->failed_pc=0x0c062e8au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c062e8c: /* original 0009, guest PC 0x0c062e8c */
if(!s->budget--) { s->failed_pc=0x0c062e8cu; return 0; }
if(!vf3_matrix_family(0x0c062e8eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c062e8eu; return 0; } return 1;
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
P_0c07a7e8: /* original 6341, guest PC 0x0c07a7e8 */
if(!s->budget--) { s->failed_pc=0x0c07a7e8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07a7ea;
P_0c07a7ea: /* original d676, guest PC 0x0c07a7ea */
if(!s->budget--) { s->failed_pc=0x0c07a7eau; return 0; }
r[6]=read(ram,0x0c07a9c4u,4);
goto P_0c07a7ec;
P_0c07a7ec: /* original 2631, guest PC 0x0c07a7ec */
if(!s->budget--) { s->failed_pc=0x0c07a7ecu; return 0; }
write(ram,r[6],r[3],2);
goto P_0c07a7ee;
P_0c07a7ee: /* original 8541, guest PC 0x0c07a7ee */
if(!s->budget--) { s->failed_pc=0x0c07a7eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+2,2);
goto P_0c07a7f0;
P_0c07a7f0: /* original 8161, guest PC 0x0c07a7f0 */
if(!s->budget--) { s->failed_pc=0x0c07a7f0u; return 0; }
write(ram,r[6]+2,r[0],2);
goto P_0c07a7f2;
P_0c07a7f2: /* original 5341, guest PC 0x0c07a7f2 */
if(!s->budget--) { s->failed_pc=0x0c07a7f2u; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c07a7f4;
P_0c07a7f4: /* original 1631, guest PC 0x0c07a7f4 */
if(!s->budget--) { s->failed_pc=0x0c07a7f4u; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c07a7f6;
P_0c07a7f6: /* original 5242, guest PC 0x0c07a7f6 */
if(!s->budget--) { s->failed_pc=0x0c07a7f6u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a7f8;
P_0c07a7f8: /* original 352c, guest PC 0x0c07a7f8 */
if(!s->budget--) { s->failed_pc=0x0c07a7f8u; return 0; }
r[5]+=r[2];
goto P_0c07a7fa;
P_0c07a7fa: /* original 1652, guest PC 0x0c07a7fa */
if(!s->budget--) { s->failed_pc=0x0c07a7fau; return 0; }
write(ram,r[6]+8,r[5],4);
goto P_0c07a7fc;
P_0c07a7fc: /* original 5343, guest PC 0x0c07a7fc */
if(!s->budget--) { s->failed_pc=0x0c07a7fcu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c07a7fe;
P_0c07a7fe: /* original 1633, guest PC 0x0c07a7fe */
if(!s->budget--) { s->failed_pc=0x0c07a7feu; return 0; }
write(ram,r[6]+12,r[3],4);
goto P_0c07a800;
P_0c07a800: /* original d271, guest PC 0x0c07a800 */
if(!s->budget--) { s->failed_pc=0x0c07a800u; return 0; }
r[2]=read(ram,0x0c07a9c8u,4);
goto P_0c07a802;
P_0c07a802: /* original 422b, guest PC 0x0c07a802 */
if(!s->budget--) { s->failed_pc=0x0c07a802u; return 0; }
target=r[2];
r[4]=r[6];
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03f5a0u: return vf3_matrix_family(0x0c03f5a0u,s,ram);
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
P_0c07a804: /* original 6463, guest PC 0x0c07a804 */
if(!s->budget--) { s->failed_pc=0x0c07a804u; return 0; }
r[4]=r[6];
goto P_0c07a806;
P_0c07a806: /* original 2fe6, guest PC 0x0c07a806 */
if(!s->budget--) { s->failed_pc=0x0c07a806u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a808;
P_0c07a808: /* original 6e53, guest PC 0x0c07a808 */
if(!s->budget--) { s->failed_pc=0x0c07a808u; return 0; }
r[14]=r[5];
goto P_0c07a80a;
P_0c07a80a: /* original 2fd6, guest PC 0x0c07a80a */
if(!s->budget--) { s->failed_pc=0x0c07a80au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a80c;
P_0c07a80c: /* original 6d43, guest PC 0x0c07a80c */
if(!s->budget--) { s->failed_pc=0x0c07a80cu; return 0; }
r[13]=r[4];
goto P_0c07a80e;
P_0c07a80e: /* original 4f22, guest PC 0x0c07a80e */
if(!s->budget--) { s->failed_pc=0x0c07a80eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a810;
P_0c07a810: /* original 5041, guest PC 0x0c07a810 */
if(!s->budget--) { s->failed_pc=0x0c07a810u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a812;
P_0c07a812: /* original 88ff, guest PC 0x0c07a812 */
if(!s->budget--) { s->failed_pc=0x0c07a812u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a814;
P_0c07a814: /* original 8904, guest PC 0x0c07a814 */
if(!s->budget--) { s->failed_pc=0x0c07a814u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a820; }
goto P_0c07a816;
P_0c07a816: /* original 5242, guest PC 0x0c07a816 */
if(!s->budget--) { s->failed_pc=0x0c07a816u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c07a818;
P_0c07a818: /* original 32ec, guest PC 0x0c07a818 */
if(!s->budget--) { s->failed_pc=0x0c07a818u; return 0; }
r[2]+=r[14];
goto P_0c07a81a;
P_0c07a81a: /* original 1422, guest PC 0x0c07a81a */
if(!s->budget--) { s->failed_pc=0x0c07a81au; return 0; }
write(ram,r[4]+8,r[2],4);
goto P_0c07a81c;
P_0c07a81c: /* original aff8, guest PC 0x0c07a81c */
if(!s->budget--) { s->failed_pc=0x0c07a81cu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a810;
P_0c07a81e: /* original 7410, guest PC 0x0c07a81e */
if(!s->budget--) { s->failed_pc=0x0c07a81eu; return 0; }
r[4]+=0x00000010u;
goto P_0c07a820;
P_0c07a820: /* original d369, guest PC 0x0c07a820 */
if(!s->budget--) { s->failed_pc=0x0c07a820u; return 0; }
r[3]=read(ram,0x0c07a9c8u,4);
goto P_0c07a822;
P_0c07a822: /* original 430b, guest PC 0x0c07a822 */
if(!s->budget--) { s->failed_pc=0x0c07a822u; return 0; }
target=r[3];
r[16]=code_base|0x0c07a826u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a826u) { target=s->pc; goto dispatch; }
goto P_0c07a826;
P_0c07a824: /* original 64d3, guest PC 0x0c07a824 */
if(!s->budget--) { s->failed_pc=0x0c07a824u; return 0; }
r[4]=r[13];
goto P_0c07a826;
P_0c07a826: /* original 64d3, guest PC 0x0c07a826 */
if(!s->budget--) { s->failed_pc=0x0c07a826u; return 0; }
r[4]=r[13];
goto P_0c07a828;
P_0c07a828: /* original 6503, guest PC 0x0c07a828 */
if(!s->budget--) { s->failed_pc=0x0c07a828u; return 0; }
r[5]=r[0];
goto P_0c07a82a;
P_0c07a82a: /* original 5041, guest PC 0x0c07a82a */
if(!s->budget--) { s->failed_pc=0x0c07a82au; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c07a82c;
P_0c07a82c: /* original 88ff, guest PC 0x0c07a82c */
if(!s->budget--) { s->failed_pc=0x0c07a82cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c07a82e;
P_0c07a82e: /* original 8904, guest PC 0x0c07a82e */
if(!s->budget--) { s->failed_pc=0x0c07a82eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07a83a; }
goto P_0c07a830;
P_0c07a830: /* original 5342, guest PC 0x0c07a830 */
if(!s->budget--) { s->failed_pc=0x0c07a830u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c07a832;
P_0c07a832: /* original 33e8, guest PC 0x0c07a832 */
if(!s->budget--) { s->failed_pc=0x0c07a832u; return 0; }
r[3]-=r[14];
goto P_0c07a834;
P_0c07a834: /* original 1432, guest PC 0x0c07a834 */
if(!s->budget--) { s->failed_pc=0x0c07a834u; return 0; }
write(ram,r[4]+8,r[3],4);
goto P_0c07a836;
P_0c07a836: /* original aff8, guest PC 0x0c07a836 */
if(!s->budget--) { s->failed_pc=0x0c07a836u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a82a;
P_0c07a838: /* original 7410, guest PC 0x0c07a838 */
if(!s->budget--) { s->failed_pc=0x0c07a838u; return 0; }
r[4]+=0x00000010u;
goto P_0c07a83a;
P_0c07a83a: /* original 4f26, guest PC 0x0c07a83a */
if(!s->budget--) { s->failed_pc=0x0c07a83au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a83c;
P_0c07a83c: /* original 6053, guest PC 0x0c07a83c */
if(!s->budget--) { s->failed_pc=0x0c07a83cu; return 0; }
r[0]=r[5];
goto P_0c07a83e;
P_0c07a83e: /* original 6df6, guest PC 0x0c07a83e */
if(!s->budget--) { s->failed_pc=0x0c07a83eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a840;
P_0c07a840: /* original 000b, guest PC 0x0c07a840 */
if(!s->budget--) { s->failed_pc=0x0c07a840u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a842: /* original 6ef6, guest PC 0x0c07a842 */
if(!s->budget--) { s->failed_pc=0x0c07a842u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07a844u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07a844u; return 0; } return 1;
P_0c07ab14: /* original 4f22, guest PC 0x0c07ab14 */
if(!s->budget--) { s->failed_pc=0x0c07ab14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ab16;
P_0c07ab16: /* original b54b, guest PC 0x0c07ab16 */
if(!s->budget--) { s->failed_pc=0x0c07ab16u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07ab1au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab1au) { target=s->pc; goto dispatch; }
goto P_0c07ab1a;
P_0c07ab18: /* original 0009, guest PC 0x0c07ab18 */
if(!s->budget--) { s->failed_pc=0x0c07ab18u; return 0; }
goto P_0c07ab1a;
P_0c07ab1a: /* original 6403, guest PC 0x0c07ab1a */
if(!s->budget--) { s->failed_pc=0x0c07ab1au; return 0; }
r[4]=r[0];
goto P_0c07ab1c;
P_0c07ab1c: /* original 614d, guest PC 0x0c07ab1c */
if(!s->budget--) { s->failed_pc=0x0c07ab1cu; return 0; }
r[1]=r[4]&65535u;
goto P_0c07ab1e;
P_0c07ab1e: /* original 6013, guest PC 0x0c07ab1e */
if(!s->budget--) { s->failed_pc=0x0c07ab1eu; return 0; }
r[0]=r[1];
goto P_0c07ab20;
P_0c07ab20: /* original 880f, guest PC 0x0c07ab20 */
if(!s->budget--) { s->failed_pc=0x0c07ab20u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000fu)!=0);
goto P_0c07ab22;
P_0c07ab22: /* original 8b03, guest PC 0x0c07ab22 */
if(!s->budget--) { s->failed_pc=0x0c07ab22u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab2c; }
goto P_0c07ab24;
P_0c07ab24: /* original b564, guest PC 0x0c07ab24 */
if(!s->budget--) { s->failed_pc=0x0c07ab24u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab28u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab28u) { target=s->pc; goto dispatch; }
goto P_0c07ab28;
P_0c07ab26: /* original 0009, guest PC 0x0c07ab26 */
if(!s->budget--) { s->failed_pc=0x0c07ab26u; return 0; }
goto P_0c07ab28;
P_0c07ab28: /* original a024, guest PC 0x0c07ab28 */
if(!s->budget--) { s->failed_pc=0x0c07ab28u; return 0; }
r[4]=0x00000024u;
goto P_0c07ab74;
P_0c07ab2a: /* original e424, guest PC 0x0c07ab2a */
if(!s->budget--) { s->failed_pc=0x0c07ab2au; return 0; }
r[4]=0x00000024u;
goto P_0c07ab2c;
P_0c07ab2c: /* original 8808, guest PC 0x0c07ab2c */
if(!s->budget--) { s->failed_pc=0x0c07ab2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07ab2e;
P_0c07ab2e: /* original 8902, guest PC 0x0c07ab2e */
if(!s->budget--) { s->failed_pc=0x0c07ab2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ab36; }
goto P_0c07ab30;
P_0c07ab30: /* original 6013, guest PC 0x0c07ab30 */
if(!s->budget--) { s->failed_pc=0x0c07ab30u; return 0; }
r[0]=r[1];
goto P_0c07ab32;
P_0c07ab32: /* original 8809, guest PC 0x0c07ab32 */
if(!s->budget--) { s->failed_pc=0x0c07ab32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07ab34;
P_0c07ab34: /* original 8b03, guest PC 0x0c07ab34 */
if(!s->budget--) { s->failed_pc=0x0c07ab34u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab3e; }
goto P_0c07ab36;
P_0c07ab36: /* original b55b, guest PC 0x0c07ab36 */
if(!s->budget--) { s->failed_pc=0x0c07ab36u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab3au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab3au) { target=s->pc; goto dispatch; }
goto P_0c07ab3a;
P_0c07ab38: /* original 0009, guest PC 0x0c07ab38 */
if(!s->budget--) { s->failed_pc=0x0c07ab38u; return 0; }
goto P_0c07ab3a;
P_0c07ab3a: /* original a011, guest PC 0x0c07ab3a */
if(!s->budget--) { s->failed_pc=0x0c07ab3au; return 0; }
r[4]=0x00000005u;
goto P_0c07ab60;
P_0c07ab3c: /* original e405, guest PC 0x0c07ab3c */
if(!s->budget--) { s->failed_pc=0x0c07ab3cu; return 0; }
r[4]=0x00000005u;
goto P_0c07ab3e;
P_0c07ab3e: /* original 880a, guest PC 0x0c07ab3e */
if(!s->budget--) { s->failed_pc=0x0c07ab3eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c07ab40;
P_0c07ab40: /* original 8902, guest PC 0x0c07ab40 */
if(!s->budget--) { s->failed_pc=0x0c07ab40u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ab48; }
goto P_0c07ab42;
P_0c07ab42: /* original 6013, guest PC 0x0c07ab42 */
if(!s->budget--) { s->failed_pc=0x0c07ab42u; return 0; }
r[0]=r[1];
goto P_0c07ab44;
P_0c07ab44: /* original 880b, guest PC 0x0c07ab44 */
if(!s->budget--) { s->failed_pc=0x0c07ab44u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c07ab46;
P_0c07ab46: /* original 8b04, guest PC 0x0c07ab46 */
if(!s->budget--) { s->failed_pc=0x0c07ab46u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab52; }
goto P_0c07ab48;
P_0c07ab48: /* original b552, guest PC 0x0c07ab48 */
if(!s->budget--) { s->failed_pc=0x0c07ab48u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab4cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab4cu) { target=s->pc; goto dispatch; }
goto P_0c07ab4c;
P_0c07ab4a: /* original 0009, guest PC 0x0c07ab4a */
if(!s->budget--) { s->failed_pc=0x0c07ab4au; return 0; }
goto P_0c07ab4c;
P_0c07ab4c: /* original e406, guest PC 0x0c07ab4c */
if(!s->budget--) { s->failed_pc=0x0c07ab4cu; return 0; }
r[4]=0x00000006u;
goto P_0c07ab4e;
P_0c07ab4e: /* original a011, guest PC 0x0c07ab4e */
if(!s->budget--) { s->failed_pc=0x0c07ab4eu; return 0; }
goto P_0c07ab74;
P_0c07ab50: /* original 0009, guest PC 0x0c07ab50 */
if(!s->budget--) { s->failed_pc=0x0c07ab50u; return 0; }
goto P_0c07ab52;
P_0c07ab52: /* original 8812, guest PC 0x0c07ab52 */
if(!s->budget--) { s->failed_pc=0x0c07ab52u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000012u)!=0);
goto P_0c07ab54;
P_0c07ab54: /* original 8b06, guest PC 0x0c07ab54 */
if(!s->budget--) { s->failed_pc=0x0c07ab54u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab64; }
goto P_0c07ab56;
P_0c07ab56: /* original b54b, guest PC 0x0c07ab56 */
if(!s->budget--) { s->failed_pc=0x0c07ab56u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab5au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab5au) { target=s->pc; goto dispatch; }
goto P_0c07ab5a;
P_0c07ab58: /* original 0009, guest PC 0x0c07ab58 */
if(!s->budget--) { s->failed_pc=0x0c07ab58u; return 0; }
goto P_0c07ab5a;
P_0c07ab5a: /* original b549, guest PC 0x0c07ab5a */
if(!s->budget--) { s->failed_pc=0x0c07ab5au; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab5eu;
r[4]=0x00000023u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab5eu) { target=s->pc; goto dispatch; }
goto P_0c07ab5e;
P_0c07ab5c: /* original e423, guest PC 0x0c07ab5c */
if(!s->budget--) { s->failed_pc=0x0c07ab5cu; return 0; }
r[4]=0x00000023u;
goto P_0c07ab5e;
P_0c07ab5e: /* original 943d, guest PC 0x0c07ab5e */
if(!s->budget--) { s->failed_pc=0x0c07ab5eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07abdcu,2);
goto P_0c07ab60;
P_0c07ab60: /* original a546, guest PC 0x0c07ab60 */
if(!s->budget--) { s->failed_pc=0x0c07ab60u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07b5f0u,s,ram);
P_0c07ab62: /* original 4f26, guest PC 0x0c07ab62 */
if(!s->budget--) { s->failed_pc=0x0c07ab62u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab64;
P_0c07ab64: /* original 6013, guest PC 0x0c07ab64 */
if(!s->budget--) { s->failed_pc=0x0c07ab64u; return 0; }
r[0]=r[1];
goto P_0c07ab66;
P_0c07ab66: /* original 8813, guest PC 0x0c07ab66 */
if(!s->budget--) { s->failed_pc=0x0c07ab66u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000013u)!=0);
goto P_0c07ab68;
P_0c07ab68: /* original 8b06, guest PC 0x0c07ab68 */
if(!s->budget--) { s->failed_pc=0x0c07ab68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab78; }
goto P_0c07ab6a;
P_0c07ab6a: /* original b541, guest PC 0x0c07ab6a */
if(!s->budget--) { s->failed_pc=0x0c07ab6au; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab6eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab6eu) { target=s->pc; goto dispatch; }
goto P_0c07ab6e;
P_0c07ab6c: /* original 0009, guest PC 0x0c07ab6c */
if(!s->budget--) { s->failed_pc=0x0c07ab6cu; return 0; }
goto P_0c07ab6e;
P_0c07ab6e: /* original b53f, guest PC 0x0c07ab6e */
if(!s->budget--) { s->failed_pc=0x0c07ab6eu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab72u;
r[4]=0x00000023u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab72u) { target=s->pc; goto dispatch; }
goto P_0c07ab72;
P_0c07ab70: /* original e423, guest PC 0x0c07ab70 */
if(!s->budget--) { s->failed_pc=0x0c07ab70u; return 0; }
r[4]=0x00000023u;
goto P_0c07ab72;
P_0c07ab72: /* original e418, guest PC 0x0c07ab72 */
if(!s->budget--) { s->failed_pc=0x0c07ab72u; return 0; }
r[4]=0x00000018u;
goto P_0c07ab74;
P_0c07ab74: /* original a53c, guest PC 0x0c07ab74 */
if(!s->budget--) { s->failed_pc=0x0c07ab74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07b5f0u,s,ram);
P_0c07ab76: /* original 4f26, guest PC 0x0c07ab76 */
if(!s->budget--) { s->failed_pc=0x0c07ab76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab78;
P_0c07ab78: /* original 8814, guest PC 0x0c07ab78 */
if(!s->budget--) { s->failed_pc=0x0c07ab78u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000014u)!=0);
goto P_0c07ab7a;
P_0c07ab7a: /* original 8b02, guest PC 0x0c07ab7a */
if(!s->budget--) { s->failed_pc=0x0c07ab7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab82; }
goto P_0c07ab7c;
P_0c07ab7c: /* original b538, guest PC 0x0c07ab7c */
if(!s->budget--) { s->failed_pc=0x0c07ab7cu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ab80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ab80u) { target=s->pc; goto dispatch; }
goto P_0c07ab80;
P_0c07ab7e: /* original 0009, guest PC 0x0c07ab7e */
if(!s->budget--) { s->failed_pc=0x0c07ab7eu; return 0; }
goto P_0c07ab80;
P_0c07ab80: /* original e422, guest PC 0x0c07ab80 */
if(!s->budget--) { s->failed_pc=0x0c07ab80u; return 0; }
r[4]=0x00000022u;
goto P_0c07ab82;
P_0c07ab82: /* original a535, guest PC 0x0c07ab82 */
if(!s->budget--) { s->failed_pc=0x0c07ab82u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c07b5f0u,s,ram);
P_0c07ab84: /* original 4f26, guest PC 0x0c07ab84 */
if(!s->budget--) { s->failed_pc=0x0c07ab84u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ab86;
P_0c07ab86: /* original 2fe6, guest PC 0x0c07ab86 */
if(!s->budget--) { s->failed_pc=0x0c07ab86u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ab88;
P_0c07ab88: /* original 2fd6, guest PC 0x0c07ab88 */
if(!s->budget--) { s->failed_pc=0x0c07ab88u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ab8a;
P_0c07ab8a: /* original ed00, guest PC 0x0c07ab8a */
if(!s->budget--) { s->failed_pc=0x0c07ab8au; return 0; }
r[13]=0x00000000u;
goto P_0c07ab8c;
P_0c07ab8c: /* original 2fc6, guest PC 0x0c07ab8c */
if(!s->budget--) { s->failed_pc=0x0c07ab8cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ab8e;
P_0c07ab8e: /* original 2fb6, guest PC 0x0c07ab8e */
if(!s->budget--) { s->failed_pc=0x0c07ab8eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ab90;
P_0c07ab90: /* original eb17, guest PC 0x0c07ab90 */
if(!s->budget--) { s->failed_pc=0x0c07ab90u; return 0; }
r[11]=0x00000017u;
goto P_0c07ab92;
P_0c07ab92: /* original 2fa6, guest PC 0x0c07ab92 */
if(!s->budget--) { s->failed_pc=0x0c07ab92u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ab94;
P_0c07ab94: /* original 4f22, guest PC 0x0c07ab94 */
if(!s->budget--) { s->failed_pc=0x0c07ab94u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ab96;
P_0c07ab96: /* original dc13, guest PC 0x0c07ab96 */
if(!s->budget--) { s->failed_pc=0x0c07ab96u; return 0; }
r[12]=read(ram,0x0c07abe4u,4);
goto P_0c07ab98;
P_0c07ab98: /* original da11, guest PC 0x0c07ab98 */
if(!s->budget--) { s->failed_pc=0x0c07ab98u; return 0; }
r[10]=read(ram,0x0c07abe0u,4);
goto P_0c07ab9a;
P_0c07ab9a: /* original a015, guest PC 0x0c07ab9a */
if(!s->budget--) { s->failed_pc=0x0c07ab9au; return 0; }
r[14]=0x0000000au;
goto P_0c07abc8;
P_0c07ab9c: /* original ee0a, guest PC 0x0c07ab9c */
if(!s->budget--) { s->failed_pc=0x0c07ab9cu; return 0; }
r[14]=0x0000000au;
goto P_0c07ab9e;
P_0c07ab9e: /* original 64ed, guest PC 0x0c07ab9e */
if(!s->budget--) { s->failed_pc=0x0c07ab9eu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aba0;
P_0c07aba0: /* original 6043, guest PC 0x0c07aba0 */
if(!s->budget--) { s->failed_pc=0x0c07aba0u; return 0; }
r[0]=r[4];
goto P_0c07aba2;
P_0c07aba2: /* original 8805, guest PC 0x0c07aba2 */
if(!s->budget--) { s->failed_pc=0x0c07aba2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07aba4;
P_0c07aba4: /* original 890f, guest PC 0x0c07aba4 */
if(!s->budget--) { s->failed_pc=0x0c07aba4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07abc6; }
goto P_0c07aba6;
P_0c07aba6: /* original 6043, guest PC 0x0c07aba6 */
if(!s->budget--) { s->failed_pc=0x0c07aba6u; return 0; }
r[0]=r[4];
goto P_0c07aba8;
P_0c07aba8: /* original 8808, guest PC 0x0c07aba8 */
if(!s->budget--) { s->failed_pc=0x0c07aba8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c07abaa;
P_0c07abaa: /* original 890c, guest PC 0x0c07abaa */
if(!s->budget--) { s->failed_pc=0x0c07abaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07abc6; }
goto P_0c07abac;
P_0c07abac: /* original 6043, guest PC 0x0c07abac */
if(!s->budget--) { s->failed_pc=0x0c07abacu; return 0; }
r[0]=r[4];
goto P_0c07abae;
P_0c07abae: /* original 8809, guest PC 0x0c07abae */
if(!s->budget--) { s->failed_pc=0x0c07abaeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c07abb0;
P_0c07abb0: /* original 8909, guest PC 0x0c07abb0 */
if(!s->budget--) { s->failed_pc=0x0c07abb0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07abc6; }
goto P_0c07abb2;
P_0c07abb2: /* original 64ed, guest PC 0x0c07abb2 */
if(!s->budget--) { s->failed_pc=0x0c07abb2u; return 0; }
r[4]=r[14]&65535u;
goto P_0c07abb4;
P_0c07abb4: /* original 4400, guest PC 0x0c07abb4 */
if(!s->budget--) { s->failed_pc=0x0c07abb4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07abb6;
P_0c07abb6: /* original 34ac, guest PC 0x0c07abb6 */
if(!s->budget--) { s->failed_pc=0x0c07abb6u; return 0; }
r[4]+=r[10];
goto P_0c07abb8;
P_0c07abb8: /* original 6341, guest PC 0x0c07abb8 */
if(!s->budget--) { s->failed_pc=0x0c07abb8u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07abba;
P_0c07abba: /* original 633d, guest PC 0x0c07abba */
if(!s->budget--) { s->failed_pc=0x0c07abbau; return 0; }
r[3]=r[3]&65535u;
goto P_0c07abbc;
P_0c07abbc: /* original 33c0, guest PC 0x0c07abbc */
if(!s->budget--) { s->failed_pc=0x0c07abbcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c07abbe;
P_0c07abbe: /* original 8b00, guest PC 0x0c07abbe */
if(!s->budget--) { s->failed_pc=0x0c07abbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07abc2; }
goto P_0c07abc0;
P_0c07abc0: /* original 24d1, guest PC 0x0c07abc0 */
if(!s->budget--) { s->failed_pc=0x0c07abc0u; return 0; }
write(ram,r[4],r[13],2);
goto P_0c07abc2;
P_0c07abc2: /* original bfa7, guest PC 0x0c07abc2 */
if(!s->budget--) { s->failed_pc=0x0c07abc2u; return 0; }
target=code_base|0x0c07ab14u; r[16]=code_base|0x0c07abc6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07abc6u) { target=s->pc; goto dispatch; }
goto P_0c07abc6;
P_0c07abc4: /* original 64e3, guest PC 0x0c07abc4 */
if(!s->budget--) { s->failed_pc=0x0c07abc4u; return 0; }
r[4]=r[14];
goto P_0c07abc6;
P_0c07abc6: /* original 7e01, guest PC 0x0c07abc6 */
if(!s->budget--) { s->failed_pc=0x0c07abc6u; return 0; }
r[14]+=0x00000001u;
goto P_0c07abc8;
P_0c07abc8: /* original 62ed, guest PC 0x0c07abc8 */
if(!s->budget--) { s->failed_pc=0x0c07abc8u; return 0; }
r[2]=r[14]&65535u;
goto P_0c07abca;
P_0c07abca: /* original 32b7, guest PC 0x0c07abca */
if(!s->budget--) { s->failed_pc=0x0c07abcau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c07abcc;
P_0c07abcc: /* original 8be7, guest PC 0x0c07abcc */
if(!s->budget--) { s->failed_pc=0x0c07abccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ab9e; }
goto P_0c07abce;
P_0c07abce: /* original 4f26, guest PC 0x0c07abce */
if(!s->budget--) { s->failed_pc=0x0c07abceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07abd0;
P_0c07abd0: /* original 6af6, guest PC 0x0c07abd0 */
if(!s->budget--) { s->failed_pc=0x0c07abd0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07abd2;
P_0c07abd2: /* original 6bf6, guest PC 0x0c07abd2 */
if(!s->budget--) { s->failed_pc=0x0c07abd2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07abd4;
P_0c07abd4: /* original 6cf6, guest PC 0x0c07abd4 */
if(!s->budget--) { s->failed_pc=0x0c07abd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07abd6;
P_0c07abd6: /* original 6df6, guest PC 0x0c07abd6 */
if(!s->budget--) { s->failed_pc=0x0c07abd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07abd8;
P_0c07abd8: /* original 000b, guest PC 0x0c07abd8 */
if(!s->budget--) { s->failed_pc=0x0c07abd8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07abda: /* original 6ef6, guest PC 0x0c07abda */
if(!s->budget--) { s->failed_pc=0x0c07abdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07abdcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07abdcu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
