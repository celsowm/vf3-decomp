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
int vf3_away_batch35_adapter_2(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06ab10u: goto P_0c06ab10;
case 0x0c06ab12u: goto P_0c06ab12;
case 0x0c06ab14u: goto P_0c06ab14;
case 0x0c06ab16u: goto P_0c06ab16;
case 0x0c06ab18u: goto P_0c06ab18;
case 0x0c06ab1au: goto P_0c06ab1a;
case 0x0c06ab1cu: goto P_0c06ab1c;
case 0x0c06ab1eu: goto P_0c06ab1e;
case 0x0c06ab20u: goto P_0c06ab20;
case 0x0c06ab22u: goto P_0c06ab22;
case 0x0c06ab24u: goto P_0c06ab24;
case 0x0c06ab26u: goto P_0c06ab26;
case 0x0c06ab28u: goto P_0c06ab28;
case 0x0c06ab2au: goto P_0c06ab2a;
case 0x0c06ab2cu: goto P_0c06ab2c;
case 0x0c06ab2eu: goto P_0c06ab2e;
case 0x0c06ab30u: goto P_0c06ab30;
case 0x0c06ab32u: goto P_0c06ab32;
case 0x0c06ab34u: goto P_0c06ab34;
case 0x0c06ab36u: goto P_0c06ab36;
case 0x0c06ab38u: goto P_0c06ab38;
case 0x0c06ab3au: goto P_0c06ab3a;
case 0x0c06ab3cu: goto P_0c06ab3c;
case 0x0c06ab3eu: goto P_0c06ab3e;
case 0x0c06ab40u: goto P_0c06ab40;
case 0x0c06ab42u: goto P_0c06ab42;
case 0x0c06ab44u: goto P_0c06ab44;
case 0x0c06ab46u: goto P_0c06ab46;
case 0x0c06ab48u: goto P_0c06ab48;
case 0x0c06ab4au: goto P_0c06ab4a;
case 0x0c06ab4cu: goto P_0c06ab4c;
case 0x0c06ab4eu: goto P_0c06ab4e;
case 0x0c06ab50u: goto P_0c06ab50;
case 0x0c06ab52u: goto P_0c06ab52;
case 0x0c06ab54u: goto P_0c06ab54;
case 0x0c06ab56u: goto P_0c06ab56;
case 0x0c06ab58u: goto P_0c06ab58;
case 0x0c06ab5au: goto P_0c06ab5a;
case 0x0c06ab5cu: goto P_0c06ab5c;
case 0x0c06ab5eu: goto P_0c06ab5e;
case 0x0c06ab60u: goto P_0c06ab60;
case 0x0c06ab62u: goto P_0c06ab62;
case 0x0c06ab64u: goto P_0c06ab64;
case 0x0c06ab66u: goto P_0c06ab66;
case 0x0c06ab68u: goto P_0c06ab68;
case 0x0c06ab6au: goto P_0c06ab6a;
case 0x0c06ab6cu: goto P_0c06ab6c;
case 0x0c06ab6eu: goto P_0c06ab6e;
case 0x0c06ab70u: goto P_0c06ab70;
case 0x0c06ab72u: goto P_0c06ab72;
case 0x0c06ab74u: goto P_0c06ab74;
case 0x0c06ab76u: goto P_0c06ab76;
case 0x0c06ab78u: goto P_0c06ab78;
case 0x0c06ab7au: goto P_0c06ab7a;
case 0x0c06ab7cu: goto P_0c06ab7c;
case 0x0c06ab7eu: goto P_0c06ab7e;
case 0x0c06ab80u: goto P_0c06ab80;
case 0x0c06ab82u: goto P_0c06ab82;
case 0x0c06ab84u: goto P_0c06ab84;
case 0x0c06ab86u: goto P_0c06ab86;
case 0x0c06ab88u: goto P_0c06ab88;
case 0x0c06ab8au: goto P_0c06ab8a;
case 0x0c06ab8cu: goto P_0c06ab8c;
case 0x0c06ab8eu: goto P_0c06ab8e;
case 0x0c06ab90u: goto P_0c06ab90;
case 0x0c06ab92u: goto P_0c06ab92;
case 0x0c06ab94u: goto P_0c06ab94;
case 0x0c06ab96u: goto P_0c06ab96;
case 0x0c06ab98u: goto P_0c06ab98;
case 0x0c06ab9au: goto P_0c06ab9a;
case 0x0c06ab9cu: goto P_0c06ab9c;
case 0x0c06ab9eu: goto P_0c06ab9e;
case 0x0c06aba0u: goto P_0c06aba0;
case 0x0c06aba2u: goto P_0c06aba2;
case 0x0c06aba4u: goto P_0c06aba4;
case 0x0c06aba6u: goto P_0c06aba6;
case 0x0c06aba8u: goto P_0c06aba8;
case 0x0c06abaau: goto P_0c06abaa;
case 0x0c06abacu: goto P_0c06abac;
case 0x0c06abaeu: goto P_0c06abae;
case 0x0c06abb0u: goto P_0c06abb0;
case 0x0c06abb2u: goto P_0c06abb2;
case 0x0c06abb4u: goto P_0c06abb4;
case 0x0c06abb6u: goto P_0c06abb6;
case 0x0c06abb8u: goto P_0c06abb8;
case 0x0c06abbau: goto P_0c06abba;
case 0x0c06abbcu: goto P_0c06abbc;
case 0x0c06abbeu: goto P_0c06abbe;
case 0x0c06abc0u: goto P_0c06abc0;
case 0x0c06abc2u: goto P_0c06abc2;
case 0x0c06abc4u: goto P_0c06abc4;
case 0x0c06abc6u: goto P_0c06abc6;
case 0x0c06abc8u: goto P_0c06abc8;
case 0x0c06abcau: goto P_0c06abca;
case 0x0c06abccu: goto P_0c06abcc;
case 0x0c06abceu: goto P_0c06abce;
case 0x0c06abd0u: goto P_0c06abd0;
case 0x0c06abd2u: goto P_0c06abd2;
case 0x0c06abd4u: goto P_0c06abd4;
case 0x0c06abd6u: goto P_0c06abd6;
case 0x0c06abd8u: goto P_0c06abd8;
case 0x0c06abdau: goto P_0c06abda;
case 0x0c06abdcu: goto P_0c06abdc;
case 0x0c06abdeu: goto P_0c06abde;
case 0x0c06abe0u: goto P_0c06abe0;
case 0x0c06abe2u: goto P_0c06abe2;
case 0x0c06abe4u: goto P_0c06abe4;
case 0x0c06abe6u: goto P_0c06abe6;
case 0x0c06abe8u: goto P_0c06abe8;
case 0x0c06abeau: goto P_0c06abea;
case 0x0c06abecu: goto P_0c06abec;
case 0x0c06abeeu: goto P_0c06abee;
case 0x0c06abf0u: goto P_0c06abf0;
case 0x0c06abf2u: goto P_0c06abf2;
case 0x0c06abf4u: goto P_0c06abf4;
case 0x0c06abf6u: goto P_0c06abf6;
case 0x0c06abf8u: goto P_0c06abf8;
case 0x0c06abfau: goto P_0c06abfa;
case 0x0c06abfcu: goto P_0c06abfc;
case 0x0c06abfeu: goto P_0c06abfe;
case 0x0c06ac00u: goto P_0c06ac00;
case 0x0c06ac02u: goto P_0c06ac02;
case 0x0c06ac04u: goto P_0c06ac04;
case 0x0c06ac06u: goto P_0c06ac06;
case 0x0c06ac08u: goto P_0c06ac08;
case 0x0c06ac0au: goto P_0c06ac0a;
case 0x0c06ac0cu: goto P_0c06ac0c;
case 0x0c06ac0eu: goto P_0c06ac0e;
case 0x0c06ac10u: goto P_0c06ac10;
case 0x0c06ac12u: goto P_0c06ac12;
case 0x0c06ac14u: goto P_0c06ac14;
case 0x0c06ac16u: goto P_0c06ac16;
case 0x0c06ac18u: goto P_0c06ac18;
case 0x0c06ac1au: goto P_0c06ac1a;
case 0x0c06ac1cu: goto P_0c06ac1c;
case 0x0c06ac1eu: goto P_0c06ac1e;
case 0x0c06ac20u: goto P_0c06ac20;
case 0x0c06ac22u: goto P_0c06ac22;
case 0x0c06ac24u: goto P_0c06ac24;
case 0x0c06ac26u: goto P_0c06ac26;
case 0x0c06ac70u: goto P_0c06ac70;
case 0x0c06ac72u: goto P_0c06ac72;
case 0x0c06ac74u: goto P_0c06ac74;
case 0x0c06ac76u: goto P_0c06ac76;
case 0x0c06ac78u: goto P_0c06ac78;
case 0x0c06ac7au: goto P_0c06ac7a;
case 0x0c06ac7cu: goto P_0c06ac7c;
case 0x0c06ac7eu: goto P_0c06ac7e;
case 0x0c06ac80u: goto P_0c06ac80;
case 0x0c06ac82u: goto P_0c06ac82;
case 0x0c06ac84u: goto P_0c06ac84;
case 0x0c06ac86u: goto P_0c06ac86;
case 0x0c06ac88u: goto P_0c06ac88;
case 0x0c06ac8au: goto P_0c06ac8a;
case 0x0c06ac8cu: goto P_0c06ac8c;
case 0x0c06ac8eu: goto P_0c06ac8e;
case 0x0c06ac90u: goto P_0c06ac90;
case 0x0c06ac92u: goto P_0c06ac92;
case 0x0c06ac94u: goto P_0c06ac94;
case 0x0c06ac96u: goto P_0c06ac96;
case 0x0c06ac98u: goto P_0c06ac98;
case 0x0c06ac9au: goto P_0c06ac9a;
case 0x0c06ac9cu: goto P_0c06ac9c;
case 0x0c06ac9eu: goto P_0c06ac9e;
case 0x0c06aca0u: goto P_0c06aca0;
case 0x0c06aca2u: goto P_0c06aca2;
case 0x0c06aca4u: goto P_0c06aca4;
case 0x0c06aca6u: goto P_0c06aca6;
case 0x0c06aca8u: goto P_0c06aca8;
case 0x0c06acaau: goto P_0c06acaa;
case 0x0c06acacu: goto P_0c06acac;
case 0x0c06acaeu: goto P_0c06acae;
case 0x0c06acb0u: goto P_0c06acb0;
case 0x0c06acb2u: goto P_0c06acb2;
case 0x0c06acb4u: goto P_0c06acb4;
case 0x0c06acb6u: goto P_0c06acb6;
case 0x0c06acb8u: goto P_0c06acb8;
case 0x0c06acbau: goto P_0c06acba;
case 0x0c06acbcu: goto P_0c06acbc;
case 0x0c06acbeu: goto P_0c06acbe;
case 0x0c06acc0u: goto P_0c06acc0;
case 0x0c06acc2u: goto P_0c06acc2;
case 0x0c06acc4u: goto P_0c06acc4;
case 0x0c06acc6u: goto P_0c06acc6;
case 0x0c06acc8u: goto P_0c06acc8;
case 0x0c06accau: goto P_0c06acca;
case 0x0c06acccu: goto P_0c06accc;
case 0x0c06acceu: goto P_0c06acce;
case 0x0c06acd0u: goto P_0c06acd0;
case 0x0c06acd2u: goto P_0c06acd2;
case 0x0c06acd4u: goto P_0c06acd4;
case 0x0c06acd6u: goto P_0c06acd6;
case 0x0c06acd8u: goto P_0c06acd8;
case 0x0c06acdau: goto P_0c06acda;
case 0x0c06acdcu: goto P_0c06acdc;
case 0x0c06acdeu: goto P_0c06acde;
case 0x0c06ace0u: goto P_0c06ace0;
case 0x0c06ace2u: goto P_0c06ace2;
case 0x0c06ace4u: goto P_0c06ace4;
case 0x0c06ace6u: goto P_0c06ace6;
case 0x0c06ace8u: goto P_0c06ace8;
case 0x0c06aceau: goto P_0c06acea;
case 0x0c06acecu: goto P_0c06acec;
case 0x0c06aceeu: goto P_0c06acee;
case 0x0c06acf0u: goto P_0c06acf0;
case 0x0c06acf2u: goto P_0c06acf2;
case 0x0c06acf4u: goto P_0c06acf4;
case 0x0c06acf6u: goto P_0c06acf6;
case 0x0c06acf8u: goto P_0c06acf8;
case 0x0c06acfau: goto P_0c06acfa;
case 0x0c06acfcu: goto P_0c06acfc;
case 0x0c06acfeu: goto P_0c06acfe;
case 0x0c06ad00u: goto P_0c06ad00;
case 0x0c06ad02u: goto P_0c06ad02;
case 0x0c06ad04u: goto P_0c06ad04;
case 0x0c06ad06u: goto P_0c06ad06;
case 0x0c06ad08u: goto P_0c06ad08;
case 0x0c06ad0au: goto P_0c06ad0a;
case 0x0c06ad0cu: goto P_0c06ad0c;
case 0x0c06ad0eu: goto P_0c06ad0e;
case 0x0c06ad10u: goto P_0c06ad10;
case 0x0c06ad12u: goto P_0c06ad12;
case 0x0c06ad14u: goto P_0c06ad14;
case 0x0c06ad16u: goto P_0c06ad16;
case 0x0c06ad18u: goto P_0c06ad18;
case 0x0c06ad1au: goto P_0c06ad1a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06ab10: /* original 2fe6, guest PC 0x0c06ab10 */
if(!s->budget--) { s->failed_pc=0x0c06ab10u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab12;
P_0c06ab12: /* original 2fd6, guest PC 0x0c06ab12 */
if(!s->budget--) { s->failed_pc=0x0c06ab12u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab14;
P_0c06ab14: /* original 2fc6, guest PC 0x0c06ab14 */
if(!s->budget--) { s->failed_pc=0x0c06ab14u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab16;
P_0c06ab16: /* original 2fb6, guest PC 0x0c06ab16 */
if(!s->budget--) { s->failed_pc=0x0c06ab16u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab18;
P_0c06ab18: /* original 2fa6, guest PC 0x0c06ab18 */
if(!s->budget--) { s->failed_pc=0x0c06ab18u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab1a;
P_0c06ab1a: /* original 2f96, guest PC 0x0c06ab1a */
if(!s->budget--) { s->failed_pc=0x0c06ab1au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab1c;
P_0c06ab1c: /* original 2f86, guest PC 0x0c06ab1c */
if(!s->budget--) { s->failed_pc=0x0c06ab1cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ab1e;
P_0c06ab1e: /* original 4f22, guest PC 0x0c06ab1e */
if(!s->budget--) { s->failed_pc=0x0c06ab1eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ab20;
P_0c06ab20: /* original 9482, guest PC 0x0c06ab20 */
if(!s->budget--) { s->failed_pc=0x0c06ab20u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac28u,2);
goto P_0c06ab22;
P_0c06ab22: /* original d34c, guest PC 0x0c06ab22 */
if(!s->budget--) { s->failed_pc=0x0c06ab22u; return 0; }
r[3]=read(ram,0x0c06ac54u,4);
goto P_0c06ab24;
P_0c06ab24: /* original d54a, guest PC 0x0c06ab24 */
if(!s->budget--) { s->failed_pc=0x0c06ab24u; return 0; }
r[5]=read(ram,0x0c06ac50u,4);
goto P_0c06ab26;
P_0c06ab26: /* original 7fe4, guest PC 0x0c06ab26 */
if(!s->budget--) { s->failed_pc=0x0c06ab26u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c06ab28;
P_0c06ab28: /* original dd48, guest PC 0x0c06ab28 */
if(!s->budget--) { s->failed_pc=0x0c06ab28u; return 0; }
r[13]=read(ram,0x0c06ac4cu,4);
goto P_0c06ab2a;
P_0c06ab2a: /* original 430b, guest PC 0x0c06ab2a */
if(!s->budget--) { s->failed_pc=0x0c06ab2au; return 0; }
target=r[3];
r[16]=code_base|0x0c06ab2eu;
r[6]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab2eu) { target=s->pc; goto dispatch; }
goto P_0c06ab2e;
P_0c06ab2c: /* original e601, guest PC 0x0c06ab2c */
if(!s->budget--) { s->failed_pc=0x0c06ab2cu; return 0; }
r[6]=0x00000001u;
goto P_0c06ab2e;
P_0c06ab2e: /* original 947c, guest PC 0x0c06ab2e */
if(!s->budget--) { s->failed_pc=0x0c06ab2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac2au,2);
goto P_0c06ab30;
P_0c06ab30: /* original de49, guest PC 0x0c06ab30 */
if(!s->budget--) { s->failed_pc=0x0c06ab30u; return 0; }
r[14]=read(ram,0x0c06ac58u,4);
goto P_0c06ab32;
P_0c06ab32: /* original 4e0b, guest PC 0x0c06ab32 */
if(!s->budget--) { s->failed_pc=0x0c06ab32u; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab36u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab36u) { target=s->pc; goto dispatch; }
goto P_0c06ab36;
P_0c06ab34: /* original 34dc, guest PC 0x0c06ab34 */
if(!s->budget--) { s->failed_pc=0x0c06ab34u; return 0; }
r[4]+=r[13];
goto P_0c06ab36;
P_0c06ab36: /* original 2f02, guest PC 0x0c06ab36 */
if(!s->budget--) { s->failed_pc=0x0c06ab36u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06ab38;
P_0c06ab38: /* original 9478, guest PC 0x0c06ab38 */
if(!s->budget--) { s->failed_pc=0x0c06ab38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac2cu,2);
goto P_0c06ab3a;
P_0c06ab3a: /* original b099, guest PC 0x0c06ab3a */
if(!s->budget--) { s->failed_pc=0x0c06ab3au; return 0; }
target=code_base|0x0c06ac70u; r[16]=code_base|0x0c06ab3eu;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab3eu) { target=s->pc; goto dispatch; }
goto P_0c06ab3e;
P_0c06ab3c: /* original 6503, guest PC 0x0c06ab3c */
if(!s->budget--) { s->failed_pc=0x0c06ab3cu; return 0; }
r[5]=r[0];
goto P_0c06ab3e;
P_0c06ab3e: /* original 2f02, guest PC 0x0c06ab3e */
if(!s->budget--) { s->failed_pc=0x0c06ab3eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06ab40;
P_0c06ab40: /* original e601, guest PC 0x0c06ab40 */
if(!s->budget--) { s->failed_pc=0x0c06ab40u; return 0; }
r[6]=0x00000001u;
goto P_0c06ab42;
P_0c06ab42: /* original d546, guest PC 0x0c06ab42 */
if(!s->budget--) { s->failed_pc=0x0c06ab42u; return 0; }
r[5]=read(ram,0x0c06ac5cu,4);
goto P_0c06ab44;
P_0c06ab44: /* original d343, guest PC 0x0c06ab44 */
if(!s->budget--) { s->failed_pc=0x0c06ab44u; return 0; }
r[3]=read(ram,0x0c06ac54u,4);
goto P_0c06ab46;
P_0c06ab46: /* original 430b, guest PC 0x0c06ab46 */
if(!s->budget--) { s->failed_pc=0x0c06ab46u; return 0; }
target=r[3];
r[16]=code_base|0x0c06ab4au;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab4au) { target=s->pc; goto dispatch; }
goto P_0c06ab4a;
P_0c06ab48: /* original 6403, guest PC 0x0c06ab48 */
if(!s->budget--) { s->failed_pc=0x0c06ab48u; return 0; }
r[4]=r[0];
goto P_0c06ab4a;
P_0c06ab4a: /* original 2f02, guest PC 0x0c06ab4a */
if(!s->budget--) { s->failed_pc=0x0c06ab4au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06ab4c;
P_0c06ab4c: /* original 946f, guest PC 0x0c06ab4c */
if(!s->budget--) { s->failed_pc=0x0c06ab4cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac2eu,2);
goto P_0c06ab4e;
P_0c06ab4e: /* original 4e0b, guest PC 0x0c06ab4e */
if(!s->budget--) { s->failed_pc=0x0c06ab4eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab52u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab52u) { target=s->pc; goto dispatch; }
goto P_0c06ab52;
P_0c06ab50: /* original 34dc, guest PC 0x0c06ab50 */
if(!s->budget--) { s->failed_pc=0x0c06ab50u; return 0; }
r[4]+=r[13];
goto P_0c06ab52;
P_0c06ab52: /* original 6503, guest PC 0x0c06ab52 */
if(!s->budget--) { s->failed_pc=0x0c06ab52u; return 0; }
r[5]=r[0];
goto P_0c06ab54;
P_0c06ab54: /* original 1f01, guest PC 0x0c06ab54 */
if(!s->budget--) { s->failed_pc=0x0c06ab54u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06ab56;
P_0c06ab56: /* original b0e1, guest PC 0x0c06ab56 */
if(!s->budget--) { s->failed_pc=0x0c06ab56u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06ab5au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab5au) { target=s->pc; goto dispatch; }
goto P_0c06ab5a;
P_0c06ab58: /* original 64f2, guest PC 0x0c06ab58 */
if(!s->budget--) { s->failed_pc=0x0c06ab58u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06ab5a;
P_0c06ab5a: /* original 2f02, guest PC 0x0c06ab5a */
if(!s->budget--) { s->failed_pc=0x0c06ab5au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06ab5c;
P_0c06ab5c: /* original 9468, guest PC 0x0c06ab5c */
if(!s->budget--) { s->failed_pc=0x0c06ab5cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac30u,2);
goto P_0c06ab5e;
P_0c06ab5e: /* original 4e0b, guest PC 0x0c06ab5e */
if(!s->budget--) { s->failed_pc=0x0c06ab5eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab62u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab62u) { target=s->pc; goto dispatch; }
goto P_0c06ab62;
P_0c06ab60: /* original 34dc, guest PC 0x0c06ab60 */
if(!s->budget--) { s->failed_pc=0x0c06ab60u; return 0; }
r[4]+=r[13];
goto P_0c06ab62;
P_0c06ab62: /* original 6503, guest PC 0x0c06ab62 */
if(!s->budget--) { s->failed_pc=0x0c06ab62u; return 0; }
r[5]=r[0];
goto P_0c06ab64;
P_0c06ab64: /* original 1f01, guest PC 0x0c06ab64 */
if(!s->budget--) { s->failed_pc=0x0c06ab64u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06ab66;
P_0c06ab66: /* original b0d9, guest PC 0x0c06ab66 */
if(!s->budget--) { s->failed_pc=0x0c06ab66u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06ab6au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab6au) { target=s->pc; goto dispatch; }
goto P_0c06ab6a;
P_0c06ab68: /* original 64f2, guest PC 0x0c06ab68 */
if(!s->budget--) { s->failed_pc=0x0c06ab68u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06ab6a;
P_0c06ab6a: /* original 2f02, guest PC 0x0c06ab6a */
if(!s->budget--) { s->failed_pc=0x0c06ab6au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06ab6c;
P_0c06ab6c: /* original 9461, guest PC 0x0c06ab6c */
if(!s->budget--) { s->failed_pc=0x0c06ab6cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac32u,2);
goto P_0c06ab6e;
P_0c06ab6e: /* original 4e0b, guest PC 0x0c06ab6e */
if(!s->budget--) { s->failed_pc=0x0c06ab6eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab72u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab72u) { target=s->pc; goto dispatch; }
goto P_0c06ab72;
P_0c06ab70: /* original 34dc, guest PC 0x0c06ab70 */
if(!s->budget--) { s->failed_pc=0x0c06ab70u; return 0; }
r[4]+=r[13];
goto P_0c06ab72;
P_0c06ab72: /* original 6503, guest PC 0x0c06ab72 */
if(!s->budget--) { s->failed_pc=0x0c06ab72u; return 0; }
r[5]=r[0];
goto P_0c06ab74;
P_0c06ab74: /* original 1f01, guest PC 0x0c06ab74 */
if(!s->budget--) { s->failed_pc=0x0c06ab74u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06ab76;
P_0c06ab76: /* original b0d1, guest PC 0x0c06ab76 */
if(!s->budget--) { s->failed_pc=0x0c06ab76u; return 0; }
target=code_base|0x0c06ad1cu; r[16]=code_base|0x0c06ab7au;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab7au) { target=s->pc; goto dispatch; }
goto P_0c06ab7a;
P_0c06ab78: /* original 64f2, guest PC 0x0c06ab78 */
if(!s->budget--) { s->failed_pc=0x0c06ab78u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06ab7a;
P_0c06ab7a: /* original 2f02, guest PC 0x0c06ab7a */
if(!s->budget--) { s->failed_pc=0x0c06ab7au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c06ab7c;
P_0c06ab7c: /* original 945a, guest PC 0x0c06ab7c */
if(!s->budget--) { s->failed_pc=0x0c06ab7cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac34u,2);
goto P_0c06ab7e;
P_0c06ab7e: /* original 4e0b, guest PC 0x0c06ab7e */
if(!s->budget--) { s->failed_pc=0x0c06ab7eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab82u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab82u) { target=s->pc; goto dispatch; }
goto P_0c06ab82;
P_0c06ab80: /* original 34dc, guest PC 0x0c06ab80 */
if(!s->budget--) { s->failed_pc=0x0c06ab80u; return 0; }
r[4]+=r[13];
goto P_0c06ab82;
P_0c06ab82: /* original 1f01, guest PC 0x0c06ab82 */
if(!s->budget--) { s->failed_pc=0x0c06ab82u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c06ab84;
P_0c06ab84: /* original 9457, guest PC 0x0c06ab84 */
if(!s->budget--) { s->failed_pc=0x0c06ab84u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac36u,2);
goto P_0c06ab86;
P_0c06ab86: /* original 4e0b, guest PC 0x0c06ab86 */
if(!s->budget--) { s->failed_pc=0x0c06ab86u; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab8au;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab8au) { target=s->pc; goto dispatch; }
goto P_0c06ab8a;
P_0c06ab88: /* original 34dc, guest PC 0x0c06ab88 */
if(!s->budget--) { s->failed_pc=0x0c06ab88u; return 0; }
r[4]+=r[13];
goto P_0c06ab8a;
P_0c06ab8a: /* original 1f06, guest PC 0x0c06ab8a */
if(!s->budget--) { s->failed_pc=0x0c06ab8au; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c06ab8c;
P_0c06ab8c: /* original 9454, guest PC 0x0c06ab8c */
if(!s->budget--) { s->failed_pc=0x0c06ab8cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac38u,2);
goto P_0c06ab8e;
P_0c06ab8e: /* original 4e0b, guest PC 0x0c06ab8e */
if(!s->budget--) { s->failed_pc=0x0c06ab8eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab92u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab92u) { target=s->pc; goto dispatch; }
goto P_0c06ab92;
P_0c06ab90: /* original 34dc, guest PC 0x0c06ab90 */
if(!s->budget--) { s->failed_pc=0x0c06ab90u; return 0; }
r[4]+=r[13];
goto P_0c06ab92;
P_0c06ab92: /* original 1f05, guest PC 0x0c06ab92 */
if(!s->budget--) { s->failed_pc=0x0c06ab92u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c06ab94;
P_0c06ab94: /* original 9451, guest PC 0x0c06ab94 */
if(!s->budget--) { s->failed_pc=0x0c06ab94u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac3au,2);
goto P_0c06ab96;
P_0c06ab96: /* original 4e0b, guest PC 0x0c06ab96 */
if(!s->budget--) { s->failed_pc=0x0c06ab96u; return 0; }
target=r[14];
r[16]=code_base|0x0c06ab9au;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ab9au) { target=s->pc; goto dispatch; }
goto P_0c06ab9a;
P_0c06ab98: /* original 34dc, guest PC 0x0c06ab98 */
if(!s->budget--) { s->failed_pc=0x0c06ab98u; return 0; }
r[4]+=r[13];
goto P_0c06ab9a;
P_0c06ab9a: /* original 1f04, guest PC 0x0c06ab9a */
if(!s->budget--) { s->failed_pc=0x0c06ab9au; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c06ab9c;
P_0c06ab9c: /* original 944e, guest PC 0x0c06ab9c */
if(!s->budget--) { s->failed_pc=0x0c06ab9cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac3cu,2);
goto P_0c06ab9e;
P_0c06ab9e: /* original 4e0b, guest PC 0x0c06ab9e */
if(!s->budget--) { s->failed_pc=0x0c06ab9eu; return 0; }
target=r[14];
r[16]=code_base|0x0c06aba2u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06aba2u) { target=s->pc; goto dispatch; }
goto P_0c06aba2;
P_0c06aba0: /* original 34dc, guest PC 0x0c06aba0 */
if(!s->budget--) { s->failed_pc=0x0c06aba0u; return 0; }
r[4]+=r[13];
goto P_0c06aba2;
P_0c06aba2: /* original 1f03, guest PC 0x0c06aba2 */
if(!s->budget--) { s->failed_pc=0x0c06aba2u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c06aba4;
P_0c06aba4: /* original 944b, guest PC 0x0c06aba4 */
if(!s->budget--) { s->failed_pc=0x0c06aba4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac3eu,2);
goto P_0c06aba6;
P_0c06aba6: /* original 4e0b, guest PC 0x0c06aba6 */
if(!s->budget--) { s->failed_pc=0x0c06aba6u; return 0; }
target=r[14];
r[16]=code_base|0x0c06abaau;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06abaau) { target=s->pc; goto dispatch; }
goto P_0c06abaa;
P_0c06aba8: /* original 34dc, guest PC 0x0c06aba8 */
if(!s->budget--) { s->failed_pc=0x0c06aba8u; return 0; }
r[4]+=r[13];
goto P_0c06abaa;
P_0c06abaa: /* original 1f02, guest PC 0x0c06abaa */
if(!s->budget--) { s->failed_pc=0x0c06abaau; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c06abac;
P_0c06abac: /* original 9448, guest PC 0x0c06abac */
if(!s->budget--) { s->failed_pc=0x0c06abacu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac40u,2);
goto P_0c06abae;
P_0c06abae: /* original 4e0b, guest PC 0x0c06abae */
if(!s->budget--) { s->failed_pc=0x0c06abaeu; return 0; }
target=r[14];
r[16]=code_base|0x0c06abb2u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06abb2u) { target=s->pc; goto dispatch; }
goto P_0c06abb2;
P_0c06abb0: /* original 34dc, guest PC 0x0c06abb0 */
if(!s->budget--) { s->failed_pc=0x0c06abb0u; return 0; }
r[4]+=r[13];
goto P_0c06abb2;
P_0c06abb2: /* original 53f1, guest PC 0x0c06abb2 */
if(!s->budget--) { s->failed_pc=0x0c06abb2u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c06abb4;
P_0c06abb4: /* original 6503, guest PC 0x0c06abb4 */
if(!s->budget--) { s->failed_pc=0x0c06abb4u; return 0; }
r[5]=r[0];
goto P_0c06abb6;
P_0c06abb6: /* original db2a, guest PC 0x0c06abb6 */
if(!s->budget--) { s->failed_pc=0x0c06abb6u; return 0; }
r[11]=read(ram,0x0c06ac60u,4);
goto P_0c06abb8;
P_0c06abb8: /* original 2f36, guest PC 0x0c06abb8 */
if(!s->budget--) { s->failed_pc=0x0c06abb8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abba;
P_0c06abba: /* original 52f7, guest PC 0x0c06abba */
if(!s->budget--) { s->failed_pc=0x0c06abbau; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c06abbc;
P_0c06abbc: /* original 2f26, guest PC 0x0c06abbc */
if(!s->budget--) { s->failed_pc=0x0c06abbcu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abbe;
P_0c06abbe: /* original 53f7, guest PC 0x0c06abbe */
if(!s->budget--) { s->failed_pc=0x0c06abbeu; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06abc0;
P_0c06abc0: /* original 2f36, guest PC 0x0c06abc0 */
if(!s->budget--) { s->failed_pc=0x0c06abc0u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abc2;
P_0c06abc2: /* original 52f7, guest PC 0x0c06abc2 */
if(!s->budget--) { s->failed_pc=0x0c06abc2u; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c06abc4;
P_0c06abc4: /* original 2f26, guest PC 0x0c06abc4 */
if(!s->budget--) { s->failed_pc=0x0c06abc4u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abc6;
P_0c06abc6: /* original 53f7, guest PC 0x0c06abc6 */
if(!s->budget--) { s->failed_pc=0x0c06abc6u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c06abc8;
P_0c06abc8: /* original 2f36, guest PC 0x0c06abc8 */
if(!s->budget--) { s->failed_pc=0x0c06abc8u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abca;
P_0c06abca: /* original 52f7, guest PC 0x0c06abca */
if(!s->budget--) { s->failed_pc=0x0c06abcau; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c06abcc;
P_0c06abcc: /* original 2f26, guest PC 0x0c06abcc */
if(!s->budget--) { s->failed_pc=0x0c06abccu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abce;
P_0c06abce: /* original 2f56, guest PC 0x0c06abce */
if(!s->budget--) { s->failed_pc=0x0c06abceu; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abd0;
P_0c06abd0: /* original d324, guest PC 0x0c06abd0 */
if(!s->budget--) { s->failed_pc=0x0c06abd0u; return 0; }
r[3]=read(ram,0x0c06ac64u,4);
goto P_0c06abd2;
P_0c06abd2: /* original 2f36, guest PC 0x0c06abd2 */
if(!s->budget--) { s->failed_pc=0x0c06abd2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abd4;
P_0c06abd4: /* original 4b0b, guest PC 0x0c06abd4 */
if(!s->budget--) { s->failed_pc=0x0c06abd4u; return 0; }
target=r[11];
r[16]=code_base|0x0c06abd8u;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06abd8u) { target=s->pc; goto dispatch; }
goto P_0c06abd8;
P_0c06abd6: /* original 54f8, guest PC 0x0c06abd6 */
if(!s->budget--) { s->failed_pc=0x0c06abd6u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c06abd8;
P_0c06abd8: /* original 1f08, guest PC 0x0c06abd8 */
if(!s->budget--) { s->failed_pc=0x0c06abd8u; return 0; }
write(ram,r[15]+32,r[0],4);
goto P_0c06abda;
P_0c06abda: /* original 9432, guest PC 0x0c06abda */
if(!s->budget--) { s->failed_pc=0x0c06abdau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac42u,2);
goto P_0c06abdc;
P_0c06abdc: /* original 4e0b, guest PC 0x0c06abdc */
if(!s->budget--) { s->failed_pc=0x0c06abdcu; return 0; }
target=r[14];
r[16]=code_base|0x0c06abe0u;
r[4]+=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06abe0u) { target=s->pc; goto dispatch; }
goto P_0c06abe0;
P_0c06abde: /* original 34dc, guest PC 0x0c06abde */
if(!s->budget--) { s->failed_pc=0x0c06abdeu; return 0; }
r[4]+=r[13];
goto P_0c06abe0;
P_0c06abe0: /* original 2f06, guest PC 0x0c06abe0 */
if(!s->budget--) { s->failed_pc=0x0c06abe0u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abe2;
P_0c06abe2: /* original 6503, guest PC 0x0c06abe2 */
if(!s->budget--) { s->failed_pc=0x0c06abe2u; return 0; }
r[5]=r[0];
goto P_0c06abe4;
P_0c06abe4: /* original d320, guest PC 0x0c06abe4 */
if(!s->budget--) { s->failed_pc=0x0c06abe4u; return 0; }
r[3]=read(ram,0x0c06ac68u,4);
goto P_0c06abe6;
P_0c06abe6: /* original 2f36, guest PC 0x0c06abe6 */
if(!s->budget--) { s->failed_pc=0x0c06abe6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abe8;
P_0c06abe8: /* original 4b0b, guest PC 0x0c06abe8 */
if(!s->budget--) { s->failed_pc=0x0c06abe8u; return 0; }
target=r[11];
r[16]=code_base|0x0c06abecu;
r[4]=read(ram,r[15]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06abecu) { target=s->pc; goto dispatch; }
goto P_0c06abec;
P_0c06abea: /* original 54fa, guest PC 0x0c06abea */
if(!s->budget--) { s->failed_pc=0x0c06abeau; return 0; }
r[4]=read(ram,r[15]+40,4);
goto P_0c06abec;
P_0c06abec: /* original 9c2b, guest PC 0x0c06abec */
if(!s->budget--) { s->failed_pc=0x0c06abecu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac46u,2);
goto P_0c06abee;
P_0c06abee: /* original e80d, guest PC 0x0c06abee */
if(!s->budget--) { s->failed_pc=0x0c06abeeu; return 0; }
r[8]=0x0000000du;
goto P_0c06abf0;
P_0c06abf0: /* original 9928, guest PC 0x0c06abf0 */
if(!s->budget--) { s->failed_pc=0x0c06abf0u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ac44u,2);
goto P_0c06abf2;
P_0c06abf2: /* original 7f28, guest PC 0x0c06abf2 */
if(!s->budget--) { s->failed_pc=0x0c06abf2u; return 0; }
r[15]+=0x00000028u;
goto P_0c06abf4;
P_0c06abf4: /* original 3cdc, guest PC 0x0c06abf4 */
if(!s->budget--) { s->failed_pc=0x0c06abf4u; return 0; }
r[12]+=r[13];
goto P_0c06abf6;
P_0c06abf6: /* original ea00, guest PC 0x0c06abf6 */
if(!s->budget--) { s->failed_pc=0x0c06abf6u; return 0; }
r[10]=0x00000000u;
goto P_0c06abf8;
P_0c06abf8: /* original 4e0b, guest PC 0x0c06abf8 */
if(!s->budget--) { s->failed_pc=0x0c06abf8u; return 0; }
target=r[14];
r[16]=code_base|0x0c06abfcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06abfcu) { target=s->pc; goto dispatch; }
goto P_0c06abfc;
P_0c06abfa: /* original 64c3, guest PC 0x0c06abfa */
if(!s->budget--) { s->failed_pc=0x0c06abfau; return 0; }
r[4]=r[12];
goto P_0c06abfc;
P_0c06abfc: /* original 2f06, guest PC 0x0c06abfc */
if(!s->budget--) { s->failed_pc=0x0c06abfcu; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06abfe;
P_0c06abfe: /* original 6503, guest PC 0x0c06abfe */
if(!s->budget--) { s->failed_pc=0x0c06abfeu; return 0; }
r[5]=r[0];
goto P_0c06ac00;
P_0c06ac00: /* original d31a, guest PC 0x0c06ac00 */
if(!s->budget--) { s->failed_pc=0x0c06ac00u; return 0; }
r[3]=read(ram,0x0c06ac6cu,4);
goto P_0c06ac02;
P_0c06ac02: /* original 2f36, guest PC 0x0c06ac02 */
if(!s->budget--) { s->failed_pc=0x0c06ac02u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ac04;
P_0c06ac04: /* original 4b0b, guest PC 0x0c06ac04 */
if(!s->budget--) { s->failed_pc=0x0c06ac04u; return 0; }
target=r[11];
r[16]=code_base|0x0c06ac08u;
r[4]=r[9];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ac08u) { target=s->pc; goto dispatch; }
goto P_0c06ac08;
P_0c06ac06: /* original 6493, guest PC 0x0c06ac06 */
if(!s->budget--) { s->failed_pc=0x0c06ac06u; return 0; }
r[4]=r[9];
goto P_0c06ac08;
P_0c06ac08: /* original 7a01, guest PC 0x0c06ac08 */
if(!s->budget--) { s->failed_pc=0x0c06ac08u; return 0; }
r[10]+=0x00000001u;
goto P_0c06ac0a;
P_0c06ac0a: /* original 6903, guest PC 0x0c06ac0a */
if(!s->budget--) { s->failed_pc=0x0c06ac0au; return 0; }
r[9]=r[0];
goto P_0c06ac0c;
P_0c06ac0c: /* original 3a83, guest PC 0x0c06ac0c */
if(!s->budget--) { s->failed_pc=0x0c06ac0cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[8])!=0);
goto P_0c06ac0e;
P_0c06ac0e: /* original 7f08, guest PC 0x0c06ac0e */
if(!s->budget--) { s->failed_pc=0x0c06ac0eu; return 0; }
r[15]+=0x00000008u;
goto P_0c06ac10;
P_0c06ac10: /* original 8ff2, guest PC 0x0c06ac10 */
if(!s->budget--) { s->failed_pc=0x0c06ac10u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000004u;
if(!cond) { goto P_0c06abf8; }
goto P_0c06ac14;
P_0c06ac12: /* original 7c04, guest PC 0x0c06ac12 */
if(!s->budget--) { s->failed_pc=0x0c06ac12u; return 0; }
r[12]+=0x00000004u;
goto P_0c06ac14;
P_0c06ac14: /* original 7f1c, guest PC 0x0c06ac14 */
if(!s->budget--) { s->failed_pc=0x0c06ac14u; return 0; }
r[15]+=0x0000001cu;
goto P_0c06ac16;
P_0c06ac16: /* original 4f26, guest PC 0x0c06ac16 */
if(!s->budget--) { s->failed_pc=0x0c06ac16u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ac18;
P_0c06ac18: /* original 68f6, guest PC 0x0c06ac18 */
if(!s->budget--) { s->failed_pc=0x0c06ac18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06ac1a;
P_0c06ac1a: /* original 69f6, guest PC 0x0c06ac1a */
if(!s->budget--) { s->failed_pc=0x0c06ac1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06ac1c;
P_0c06ac1c: /* original 6af6, guest PC 0x0c06ac1c */
if(!s->budget--) { s->failed_pc=0x0c06ac1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06ac1e;
P_0c06ac1e: /* original 6bf6, guest PC 0x0c06ac1e */
if(!s->budget--) { s->failed_pc=0x0c06ac1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06ac20;
P_0c06ac20: /* original 6cf6, guest PC 0x0c06ac20 */
if(!s->budget--) { s->failed_pc=0x0c06ac20u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ac22;
P_0c06ac22: /* original 6df6, guest PC 0x0c06ac22 */
if(!s->budget--) { s->failed_pc=0x0c06ac22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ac24;
P_0c06ac24: /* original 000b, guest PC 0x0c06ac24 */
if(!s->budget--) { s->failed_pc=0x0c06ac24u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ac26: /* original 6ef6, guest PC 0x0c06ac26 */
if(!s->budget--) { s->failed_pc=0x0c06ac26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06ac28u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06ac28u; return 0; } return 1;
P_0c06ac70: /* original 2fe6, guest PC 0x0c06ac70 */
if(!s->budget--) { s->failed_pc=0x0c06ac70u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ac72;
P_0c06ac72: /* original c758, guest PC 0x0c06ac72 */
if(!s->budget--) { s->failed_pc=0x0c06ac72u; return 0; }
r[0]=code_base|0x0006add4u;
goto P_0c06ac74;
P_0c06ac74: /* original 2fd6, guest PC 0x0c06ac74 */
if(!s->budget--) { s->failed_pc=0x0c06ac74u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ac76;
P_0c06ac76: /* original 2fc6, guest PC 0x0c06ac76 */
if(!s->budget--) { s->failed_pc=0x0c06ac76u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ac78;
P_0c06ac78: /* original 455a, guest PC 0x0c06ac78 */
if(!s->budget--) { s->failed_pc=0x0c06ac78u; return 0; }
r[53]=r[5];
goto P_0c06ac7a;
P_0c06ac7a: /* original 4f22, guest PC 0x0c06ac7a */
if(!s->budget--) { s->failed_pc=0x0c06ac7au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ac7c;
P_0c06ac7c: /* original f28d, guest PC 0x0c06ac7c */
if(!s->budget--) { s->failed_pc=0x0c06ac7cu; return 0; }
fr[2]=0;
goto P_0c06ac7e;
P_0c06ac7e: /* original f32d, guest PC 0x0c06ac7e */
if(!s->budget--) { s->failed_pc=0x0c06ac7eu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06ac80;
P_0c06ac80: /* original f508, guest PC 0x0c06ac80 */
if(!s->budget--) { s->failed_pc=0x0c06ac80u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c06ac82;
P_0c06ac82: /* original 4f12, guest PC 0x0c06ac82 */
if(!s->budget--) { s->failed_pc=0x0c06ac82u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06ac84;
P_0c06ac84: /* original 7ffc, guest PC 0x0c06ac84 */
if(!s->budget--) { s->failed_pc=0x0c06ac84u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06ac86;
P_0c06ac86: /* original f235, guest PC 0x0c06ac86 */
if(!s->budget--) { s->failed_pc=0x0c06ac86u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c06ac88;
P_0c06ac88: /* original 8f03, guest PC 0x0c06ac88 */
if(!s->budget--) { s->failed_pc=0x0c06ac88u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,4,3);
if(!cond) { goto P_0c06ac92; }
goto P_0c06ac8c;
P_0c06ac8a: /* original f43c, guest PC 0x0c06ac8a */
if(!s->budget--) { s->failed_pc=0x0c06ac8au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c06ac8c;
P_0c06ac8c: /* original c752, guest PC 0x0c06ac8c */
if(!s->budget--) { s->failed_pc=0x0c06ac8cu; return 0; }
r[0]=code_base|0x0006add8u;
goto P_0c06ac8e;
P_0c06ac8e: /* original f308, guest PC 0x0c06ac8e */
if(!s->budget--) { s->failed_pc=0x0c06ac8eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c06ac90;
P_0c06ac90: /* original f430, guest PC 0x0c06ac90 */
if(!s->budget--) { s->failed_pc=0x0c06ac90u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c06ac92;
P_0c06ac92: /* original f64c, guest PC 0x0c06ac92 */
if(!s->budget--) { s->failed_pc=0x0c06ac92u; return 0; }
vf3_matrix_move(s,6,4);
goto P_0c06ac94;
P_0c06ac94: /* original f653, guest PC 0x0c06ac94 */
if(!s->budget--) { s->failed_pc=0x0c06ac94u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c06ac96;
P_0c06ac96: /* original d351, guest PC 0x0c06ac96 */
if(!s->budget--) { s->failed_pc=0x0c06ac96u; return 0; }
r[3]=read(ram,0x0c06addcu,4);
goto P_0c06ac98;
P_0c06ac98: /* original e63c, guest PC 0x0c06ac98 */
if(!s->budget--) { s->failed_pc=0x0c06ac98u; return 0; }
r[6]=0x0000003cu;
goto P_0c06ac9a;
P_0c06ac9a: /* original f63d, guest PC 0x0c06ac9a */
if(!s->budget--) { s->failed_pc=0x0c06ac9au; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c06ac9c;
P_0c06ac9c: /* original 055a, guest PC 0x0c06ac9c */
if(!s->budget--) { s->failed_pc=0x0c06ac9cu; return 0; }
r[5]=r[53];
goto P_0c06ac9e;
P_0c06ac9e: /* original 455a, guest PC 0x0c06ac9e */
if(!s->budget--) { s->failed_pc=0x0c06ac9eu; return 0; }
r[53]=r[5];
goto P_0c06aca0;
P_0c06aca0: /* original f32d, guest PC 0x0c06aca0 */
if(!s->budget--) { s->failed_pc=0x0c06aca0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c06aca2;
P_0c06aca2: /* original f63c, guest PC 0x0c06aca2 */
if(!s->budget--) { s->failed_pc=0x0c06aca2u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c06aca4;
P_0c06aca4: /* original f562, guest PC 0x0c06aca4 */
if(!s->budget--) { s->failed_pc=0x0c06aca4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c06aca6;
P_0c06aca6: /* original f63d, guest PC 0x0c06aca6 */
if(!s->budget--) { s->failed_pc=0x0c06aca6u; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c06aca8;
P_0c06aca8: /* original f451, guest PC 0x0c06aca8 */
if(!s->budget--) { s->failed_pc=0x0c06aca8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'-');
goto P_0c06acaa;
P_0c06acaa: /* original 075a, guest PC 0x0c06acaa */
if(!s->budget--) { s->failed_pc=0x0c06acaau; return 0; }
r[7]=r[53];
goto P_0c06acac;
P_0c06acac: /* original f43d, guest PC 0x0c06acac */
if(!s->budget--) { s->failed_pc=0x0c06acacu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c06acae;
P_0c06acae: /* original 6173, guest PC 0x0c06acae */
if(!s->budget--) { s->failed_pc=0x0c06acaeu; return 0; }
r[1]=r[7];
goto P_0c06acb0;
P_0c06acb0: /* original 055a, guest PC 0x0c06acb0 */
if(!s->budget--) { s->failed_pc=0x0c06acb0u; return 0; }
r[5]=r[53];
goto P_0c06acb2;
P_0c06acb2: /* original 430b, guest PC 0x0c06acb2 */
if(!s->budget--) { s->failed_pc=0x0c06acb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c06acb6u;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06acb6u) { target=s->pc; goto dispatch; }
goto P_0c06acb6;
P_0c06acb4: /* original 6063, guest PC 0x0c06acb4 */
if(!s->budget--) { s->failed_pc=0x0c06acb4u; return 0; }
r[0]=r[6];
goto P_0c06acb6;
P_0c06acb6: /* original 6d03, guest PC 0x0c06acb6 */
if(!s->budget--) { s->failed_pc=0x0c06acb6u; return 0; }
r[13]=r[0];
goto P_0c06acb8;
P_0c06acb8: /* original 61d3, guest PC 0x0c06acb8 */
if(!s->budget--) { s->failed_pc=0x0c06acb8u; return 0; }
r[1]=r[13];
goto P_0c06acba;
P_0c06acba: /* original 0d67, guest PC 0x0c06acba */
if(!s->budget--) { s->failed_pc=0x0c06acbau; return 0; }
r[19]=r[13]*r[6];
goto P_0c06acbc;
P_0c06acbc: /* original 021a, guest PC 0x0c06acbc */
if(!s->budget--) { s->failed_pc=0x0c06acbcu; return 0; }
r[2]=r[19];
goto P_0c06acbe;
P_0c06acbe: /* original 2f22, guest PC 0x0c06acbe */
if(!s->budget--) { s->failed_pc=0x0c06acbeu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c06acc0;
P_0c06acc0: /* original 3728, guest PC 0x0c06acc0 */
if(!s->budget--) { s->failed_pc=0x0c06acc0u; return 0; }
r[7]-=r[2];
goto P_0c06acc2;
P_0c06acc2: /* original d346, guest PC 0x0c06acc2 */
if(!s->budget--) { s->failed_pc=0x0c06acc2u; return 0; }
r[3]=read(ram,0x0c06addcu,4);
goto P_0c06acc4;
P_0c06acc4: /* original 430b, guest PC 0x0c06acc4 */
if(!s->budget--) { s->failed_pc=0x0c06acc4u; return 0; }
target=r[3];
r[16]=code_base|0x0c06acc8u;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06acc8u) { target=s->pc; goto dispatch; }
goto P_0c06acc8;
P_0c06acc6: /* original 6063, guest PC 0x0c06acc6 */
if(!s->budget--) { s->failed_pc=0x0c06acc6u; return 0; }
r[0]=r[6];
goto P_0c06acc8;
P_0c06acc8: /* original 6e03, guest PC 0x0c06acc8 */
if(!s->budget--) { s->failed_pc=0x0c06acc8u; return 0; }
r[14]=r[0];
goto P_0c06acca;
P_0c06acca: /* original 0e67, guest PC 0x0c06acca */
if(!s->budget--) { s->failed_pc=0x0c06accau; return 0; }
r[19]=r[14]*r[6];
goto P_0c06accc;
P_0c06accc: /* original 011a, guest PC 0x0c06accc */
if(!s->budget--) { s->failed_pc=0x0c06acccu; return 0; }
r[1]=r[19];
goto P_0c06acce;
P_0c06acce: /* original 3d18, guest PC 0x0c06acce */
if(!s->budget--) { s->failed_pc=0x0c06acceu; return 0; }
r[13]-=r[1];
goto P_0c06acd0;
P_0c06acd0: /* original 2f12, guest PC 0x0c06acd0 */
if(!s->budget--) { s->failed_pc=0x0c06acd0u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06acd2;
P_0c06acd2: /* original d342, guest PC 0x0c06acd2 */
if(!s->budget--) { s->failed_pc=0x0c06acd2u; return 0; }
r[3]=read(ram,0x0c06addcu,4);
goto P_0c06acd4;
P_0c06acd4: /* original 61e3, guest PC 0x0c06acd4 */
if(!s->budget--) { s->failed_pc=0x0c06acd4u; return 0; }
r[1]=r[14];
goto P_0c06acd6;
P_0c06acd6: /* original 430b, guest PC 0x0c06acd6 */
if(!s->budget--) { s->failed_pc=0x0c06acd6u; return 0; }
target=r[3];
r[16]=code_base|0x0c06acdau;
r[0]=0x00000018u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06acdau) { target=s->pc; goto dispatch; }
goto P_0c06acda;
P_0c06acd8: /* original e018, guest PC 0x0c06acd8 */
if(!s->budget--) { s->failed_pc=0x0c06acd8u; return 0; }
r[0]=0x00000018u;
goto P_0c06acda;
P_0c06acda: /* original 6103, guest PC 0x0c06acda */
if(!s->budget--) { s->failed_pc=0x0c06acdau; return 0; }
r[1]=r[0];
goto P_0c06acdc;
P_0c06acdc: /* original 4100, guest PC 0x0c06acdc */
if(!s->budget--) { s->failed_pc=0x0c06acdcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c06acde;
P_0c06acde: /* original 6303, guest PC 0x0c06acde */
if(!s->budget--) { s->failed_pc=0x0c06acdeu; return 0; }
r[3]=r[0];
goto P_0c06ace0;
P_0c06ace0: /* original 313c, guest PC 0x0c06ace0 */
if(!s->budget--) { s->failed_pc=0x0c06ace0u; return 0; }
r[1]+=r[3];
goto P_0c06ace2;
P_0c06ace2: /* original e364, guest PC 0x0c06ace2 */
if(!s->budget--) { s->failed_pc=0x0c06ace2u; return 0; }
r[3]=0x00000064u;
goto P_0c06ace4;
P_0c06ace4: /* original 6c03, guest PC 0x0c06ace4 */
if(!s->budget--) { s->failed_pc=0x0c06ace4u; return 0; }
r[12]=r[0];
goto P_0c06ace6;
P_0c06ace6: /* original 0537, guest PC 0x0c06ace6 */
if(!s->budget--) { s->failed_pc=0x0c06ace6u; return 0; }
r[19]=r[5]*r[3];
goto P_0c06ace8;
P_0c06ace8: /* original 4108, guest PC 0x0c06ace8 */
if(!s->budget--) { s->failed_pc=0x0c06ace8u; return 0; }
r[1]<<=2;
goto P_0c06acea;
P_0c06acea: /* original 4100, guest PC 0x0c06acea */
if(!s->budget--) { s->failed_pc=0x0c06aceau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c06acec;
P_0c06acec: /* original 3e18, guest PC 0x0c06acec */
if(!s->budget--) { s->failed_pc=0x0c06acecu; return 0; }
r[14]-=r[1];
goto P_0c06acee;
P_0c06acee: /* original 2f12, guest PC 0x0c06acee */
if(!s->budget--) { s->failed_pc=0x0c06aceeu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c06acf0;
P_0c06acf0: /* original 051a, guest PC 0x0c06acf0 */
if(!s->budget--) { s->failed_pc=0x0c06acf0u; return 0; }
r[5]=r[19];
goto P_0c06acf2;
P_0c06acf2: /* original d23a, guest PC 0x0c06acf2 */
if(!s->budget--) { s->failed_pc=0x0c06acf2u; return 0; }
r[2]=read(ram,0x0c06addcu,4);
goto P_0c06acf4;
P_0c06acf4: /* original 6153, guest PC 0x0c06acf4 */
if(!s->budget--) { s->failed_pc=0x0c06acf4u; return 0; }
r[1]=r[5];
goto P_0c06acf6;
P_0c06acf6: /* original 420b, guest PC 0x0c06acf6 */
if(!s->budget--) { s->failed_pc=0x0c06acf6u; return 0; }
target=r[2];
r[16]=code_base|0x0c06acfau;
r[0]=r[6];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06acfau) { target=s->pc; goto dispatch; }
goto P_0c06acfa;
P_0c06acf8: /* original 6063, guest PC 0x0c06acf8 */
if(!s->budget--) { s->failed_pc=0x0c06acf8u; return 0; }
r[0]=r[6];
goto P_0c06acfa;
P_0c06acfa: /* original 2f06, guest PC 0x0c06acfa */
if(!s->budget--) { s->failed_pc=0x0c06acfau; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06acfc;
P_0c06acfc: /* original 6503, guest PC 0x0c06acfc */
if(!s->budget--) { s->failed_pc=0x0c06acfcu; return 0; }
r[5]=r[0];
goto P_0c06acfe;
P_0c06acfe: /* original 2f76, guest PC 0x0c06acfe */
if(!s->budget--) { s->failed_pc=0x0c06acfeu; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad00;
P_0c06ad00: /* original 2fd6, guest PC 0x0c06ad00 */
if(!s->budget--) { s->failed_pc=0x0c06ad00u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad02;
P_0c06ad02: /* original 2fe6, guest PC 0x0c06ad02 */
if(!s->budget--) { s->failed_pc=0x0c06ad02u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad04;
P_0c06ad04: /* original 2fc6, guest PC 0x0c06ad04 */
if(!s->budget--) { s->failed_pc=0x0c06ad04u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad06;
P_0c06ad06: /* original d136, guest PC 0x0c06ad06 */
if(!s->budget--) { s->failed_pc=0x0c06ad06u; return 0; }
r[1]=read(ram,0x0c06ade0u,4);
goto P_0c06ad08;
P_0c06ad08: /* original d236, guest PC 0x0c06ad08 */
if(!s->budget--) { s->failed_pc=0x0c06ad08u; return 0; }
r[2]=read(ram,0x0c06ade4u,4);
goto P_0c06ad0a;
P_0c06ad0a: /* original 420b, guest PC 0x0c06ad0a */
if(!s->budget--) { s->failed_pc=0x0c06ad0au; return 0; }
target=r[2];
r[16]=code_base|0x0c06ad0eu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ad0eu) { target=s->pc; goto dispatch; }
goto P_0c06ad0e;
P_0c06ad0c: /* original 2f16, guest PC 0x0c06ad0c */
if(!s->budget--) { s->failed_pc=0x0c06ad0cu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ad0e;
P_0c06ad0e: /* original 7f1c, guest PC 0x0c06ad0e */
if(!s->budget--) { s->failed_pc=0x0c06ad0eu; return 0; }
r[15]+=0x0000001cu;
goto P_0c06ad10;
P_0c06ad10: /* original 4f16, guest PC 0x0c06ad10 */
if(!s->budget--) { s->failed_pc=0x0c06ad10u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ad12;
P_0c06ad12: /* original 4f26, guest PC 0x0c06ad12 */
if(!s->budget--) { s->failed_pc=0x0c06ad12u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ad14;
P_0c06ad14: /* original 6cf6, guest PC 0x0c06ad14 */
if(!s->budget--) { s->failed_pc=0x0c06ad14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ad16;
P_0c06ad16: /* original 6df6, guest PC 0x0c06ad16 */
if(!s->budget--) { s->failed_pc=0x0c06ad16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ad18;
P_0c06ad18: /* original 000b, guest PC 0x0c06ad18 */
if(!s->budget--) { s->failed_pc=0x0c06ad18u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ad1a: /* original 6ef6, guest PC 0x0c06ad1a */
if(!s->budget--) { s->failed_pc=0x0c06ad1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c06ad1cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
