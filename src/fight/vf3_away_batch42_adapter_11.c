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
int vf3_away_batch42_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0747d8u: goto P_0c0747d8;
case 0x0c0747dau: goto P_0c0747da;
case 0x0c0747dcu: goto P_0c0747dc;
case 0x0c0747deu: goto P_0c0747de;
case 0x0c0747e0u: goto P_0c0747e0;
case 0x0c0747e2u: goto P_0c0747e2;
case 0x0c0747e4u: goto P_0c0747e4;
case 0x0c0747e6u: goto P_0c0747e6;
case 0x0c0747e8u: goto P_0c0747e8;
case 0x0c0747eau: goto P_0c0747ea;
case 0x0c0747ecu: goto P_0c0747ec;
case 0x0c0747eeu: goto P_0c0747ee;
case 0x0c0747f0u: goto P_0c0747f0;
case 0x0c0747f2u: goto P_0c0747f2;
case 0x0c0747f4u: goto P_0c0747f4;
case 0x0c0747f6u: goto P_0c0747f6;
case 0x0c0747f8u: goto P_0c0747f8;
case 0x0c0747fau: goto P_0c0747fa;
case 0x0c0747fcu: goto P_0c0747fc;
case 0x0c0747feu: goto P_0c0747fe;
case 0x0c074800u: goto P_0c074800;
case 0x0c074802u: goto P_0c074802;
case 0x0c074804u: goto P_0c074804;
case 0x0c074806u: goto P_0c074806;
case 0x0c074808u: goto P_0c074808;
case 0x0c07480au: goto P_0c07480a;
case 0x0c07480cu: goto P_0c07480c;
case 0x0c07480eu: goto P_0c07480e;
case 0x0c074810u: goto P_0c074810;
case 0x0c074812u: goto P_0c074812;
case 0x0c074814u: goto P_0c074814;
case 0x0c074816u: goto P_0c074816;
case 0x0c074818u: goto P_0c074818;
case 0x0c07481au: goto P_0c07481a;
case 0x0c07481cu: goto P_0c07481c;
case 0x0c07481eu: goto P_0c07481e;
case 0x0c074820u: goto P_0c074820;
case 0x0c074822u: goto P_0c074822;
case 0x0c074824u: goto P_0c074824;
case 0x0c074826u: goto P_0c074826;
case 0x0c074828u: goto P_0c074828;
case 0x0c07482au: goto P_0c07482a;
case 0x0c07482cu: goto P_0c07482c;
case 0x0c07482eu: goto P_0c07482e;
case 0x0c074830u: goto P_0c074830;
case 0x0c074832u: goto P_0c074832;
case 0x0c074834u: goto P_0c074834;
case 0x0c074836u: goto P_0c074836;
case 0x0c074838u: goto P_0c074838;
case 0x0c07483au: goto P_0c07483a;
case 0x0c07483cu: goto P_0c07483c;
case 0x0c07483eu: goto P_0c07483e;
case 0x0c074840u: goto P_0c074840;
case 0x0c074842u: goto P_0c074842;
case 0x0c074844u: goto P_0c074844;
case 0x0c074846u: goto P_0c074846;
case 0x0c074848u: goto P_0c074848;
case 0x0c07484au: goto P_0c07484a;
case 0x0c07484cu: goto P_0c07484c;
case 0x0c07484eu: goto P_0c07484e;
case 0x0c074850u: goto P_0c074850;
case 0x0c074852u: goto P_0c074852;
case 0x0c074854u: goto P_0c074854;
case 0x0c074856u: goto P_0c074856;
case 0x0c074858u: goto P_0c074858;
case 0x0c07485au: goto P_0c07485a;
case 0x0c07485cu: goto P_0c07485c;
case 0x0c07485eu: goto P_0c07485e;
case 0x0c074860u: goto P_0c074860;
case 0x0c074862u: goto P_0c074862;
case 0x0c074864u: goto P_0c074864;
case 0x0c074866u: goto P_0c074866;
case 0x0c074868u: goto P_0c074868;
case 0x0c07486au: goto P_0c07486a;
case 0x0c07486cu: goto P_0c07486c;
case 0x0c07486eu: goto P_0c07486e;
case 0x0c074870u: goto P_0c074870;
case 0x0c074872u: goto P_0c074872;
case 0x0c074874u: goto P_0c074874;
case 0x0c074876u: goto P_0c074876;
case 0x0c074878u: goto P_0c074878;
case 0x0c07487au: goto P_0c07487a;
case 0x0c07487cu: goto P_0c07487c;
case 0x0c07487eu: goto P_0c07487e;
case 0x0c074880u: goto P_0c074880;
case 0x0c074882u: goto P_0c074882;
case 0x0c074884u: goto P_0c074884;
case 0x0c074886u: goto P_0c074886;
case 0x0c074888u: goto P_0c074888;
case 0x0c07488au: goto P_0c07488a;
case 0x0c07488cu: goto P_0c07488c;
case 0x0c07488eu: goto P_0c07488e;
case 0x0c074890u: goto P_0c074890;
case 0x0c074892u: goto P_0c074892;
case 0x0c074894u: goto P_0c074894;
case 0x0c074896u: goto P_0c074896;
case 0x0c074898u: goto P_0c074898;
case 0x0c07489au: goto P_0c07489a;
case 0x0c07489cu: goto P_0c07489c;
case 0x0c07489eu: goto P_0c07489e;
case 0x0c0748a0u: goto P_0c0748a0;
case 0x0c0748a2u: goto P_0c0748a2;
case 0x0c0748a4u: goto P_0c0748a4;
case 0x0c0748a6u: goto P_0c0748a6;
case 0x0c0748c0u: goto P_0c0748c0;
case 0x0c0748c2u: goto P_0c0748c2;
case 0x0c0748c4u: goto P_0c0748c4;
case 0x0c0748c6u: goto P_0c0748c6;
case 0x0c0748c8u: goto P_0c0748c8;
case 0x0c0748cau: goto P_0c0748ca;
case 0x0c0748ccu: goto P_0c0748cc;
case 0x0c0748ceu: goto P_0c0748ce;
case 0x0c0748d0u: goto P_0c0748d0;
case 0x0c0748d2u: goto P_0c0748d2;
case 0x0c0748d4u: goto P_0c0748d4;
case 0x0c0748d6u: goto P_0c0748d6;
case 0x0c0748d8u: goto P_0c0748d8;
case 0x0c0748dau: goto P_0c0748da;
case 0x0c0748dcu: goto P_0c0748dc;
case 0x0c0748deu: goto P_0c0748de;
case 0x0c0748e0u: goto P_0c0748e0;
case 0x0c0748e2u: goto P_0c0748e2;
case 0x0c0748e4u: goto P_0c0748e4;
case 0x0c0748e6u: goto P_0c0748e6;
case 0x0c0748e8u: goto P_0c0748e8;
case 0x0c0748eau: goto P_0c0748ea;
case 0x0c0748ecu: goto P_0c0748ec;
case 0x0c0748eeu: goto P_0c0748ee;
case 0x0c0748f0u: goto P_0c0748f0;
case 0x0c0748f2u: goto P_0c0748f2;
case 0x0c0748f4u: goto P_0c0748f4;
case 0x0c0748f6u: goto P_0c0748f6;
case 0x0c0748f8u: goto P_0c0748f8;
case 0x0c0748fau: goto P_0c0748fa;
case 0x0c0748fcu: goto P_0c0748fc;
case 0x0c0748feu: goto P_0c0748fe;
case 0x0c074900u: goto P_0c074900;
case 0x0c074902u: goto P_0c074902;
case 0x0c074904u: goto P_0c074904;
case 0x0c074906u: goto P_0c074906;
case 0x0c074908u: goto P_0c074908;
case 0x0c07490au: goto P_0c07490a;
case 0x0c07490cu: goto P_0c07490c;
case 0x0c07490eu: goto P_0c07490e;
case 0x0c074910u: goto P_0c074910;
case 0x0c074912u: goto P_0c074912;
case 0x0c074914u: goto P_0c074914;
case 0x0c074916u: goto P_0c074916;
case 0x0c074918u: goto P_0c074918;
case 0x0c07491au: goto P_0c07491a;
case 0x0c07491cu: goto P_0c07491c;
case 0x0c07491eu: goto P_0c07491e;
case 0x0c074920u: goto P_0c074920;
case 0x0c074922u: goto P_0c074922;
case 0x0c074924u: goto P_0c074924;
case 0x0c074926u: goto P_0c074926;
case 0x0c074928u: goto P_0c074928;
case 0x0c07492au: goto P_0c07492a;
case 0x0c07492cu: goto P_0c07492c;
case 0x0c07492eu: goto P_0c07492e;
case 0x0c07a7a8u: goto P_0c07a7a8;
case 0x0c07a7aau: goto P_0c07a7aa;
case 0x0c07a7acu: goto P_0c07a7ac;
case 0x0c07a7aeu: goto P_0c07a7ae;
case 0x0c07a7b0u: goto P_0c07a7b0;
case 0x0c07a7b2u: goto P_0c07a7b2;
case 0x0c07a7b4u: goto P_0c07a7b4;
case 0x0c07a7b6u: goto P_0c07a7b6;
case 0x0c07a7b8u: goto P_0c07a7b8;
case 0x0c07a7bau: goto P_0c07a7ba;
case 0x0c07a7bcu: goto P_0c07a7bc;
case 0x0c07a7beu: goto P_0c07a7be;
case 0x0c07a7c0u: goto P_0c07a7c0;
case 0x0c07a7c2u: goto P_0c07a7c2;
case 0x0c07a7c4u: goto P_0c07a7c4;
case 0x0c07a7c6u: goto P_0c07a7c6;
case 0x0c07a7c8u: goto P_0c07a7c8;
case 0x0c07a7cau: goto P_0c07a7ca;
case 0x0c07a7ccu: goto P_0c07a7cc;
case 0x0c07a7ceu: goto P_0c07a7ce;
case 0x0c07a7d0u: goto P_0c07a7d0;
case 0x0c07a7d2u: goto P_0c07a7d2;
case 0x0c07a7d4u: goto P_0c07a7d4;
case 0x0c07a7d6u: goto P_0c07a7d6;
case 0x0c07a7d8u: goto P_0c07a7d8;
case 0x0c07a7dau: goto P_0c07a7da;
case 0x0c07a7dcu: goto P_0c07a7dc;
case 0x0c07a7deu: goto P_0c07a7de;
case 0x0c07a7e0u: goto P_0c07a7e0;
case 0x0c07a7e2u: goto P_0c07a7e2;
case 0x0c07a7e4u: goto P_0c07a7e4;
case 0x0c07a7e6u: goto P_0c07a7e6;
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
P_0c0747d8: /* original 9169, guest PC 0x0c0747d8 */
if(!s->budget--) { s->failed_pc=0x0c0747d8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748aeu,2);
goto P_0c0747da;
P_0c0747da: /* original e010, guest PC 0x0c0747da */
if(!s->budget--) { s->failed_pc=0x0c0747dau; return 0; }
r[0]=0x00000010u;
goto P_0c0747dc;
P_0c0747dc: /* original f246, guest PC 0x0c0747dc */
if(!s->budget--) { s->failed_pc=0x0c0747dcu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0747de;
P_0c0747de: /* original 314c, guest PC 0x0c0747de */
if(!s->budget--) { s->failed_pc=0x0c0747deu; return 0; }
r[1]+=r[4];
goto P_0c0747e0;
P_0c0747e0: /* original f318, guest PC 0x0c0747e0 */
if(!s->budget--) { s->failed_pc=0x0c0747e0u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0747e2;
P_0c0747e2: /* original f230, guest PC 0x0c0747e2 */
if(!s->budget--) { s->failed_pc=0x0c0747e2u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0747e4;
P_0c0747e4: /* original f427, guest PC 0x0c0747e4 */
if(!s->budget--) { s->failed_pc=0x0c0747e4u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0747e6;
P_0c0747e6: /* original e018, guest PC 0x0c0747e6 */
if(!s->budget--) { s->failed_pc=0x0c0747e6u; return 0; }
r[0]=0x00000018u;
goto P_0c0747e8;
P_0c0747e8: /* original 9162, guest PC 0x0c0747e8 */
if(!s->budget--) { s->failed_pc=0x0c0747e8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b0u,2);
goto P_0c0747ea;
P_0c0747ea: /* original f246, guest PC 0x0c0747ea */
if(!s->budget--) { s->failed_pc=0x0c0747eau; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c0747ec;
P_0c0747ec: /* original 314c, guest PC 0x0c0747ec */
if(!s->budget--) { s->failed_pc=0x0c0747ecu; return 0; }
r[1]+=r[4];
goto P_0c0747ee;
P_0c0747ee: /* original f318, guest PC 0x0c0747ee */
if(!s->budget--) { s->failed_pc=0x0c0747eeu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c0747f0;
P_0c0747f0: /* original f230, guest PC 0x0c0747f0 */
if(!s->budget--) { s->failed_pc=0x0c0747f0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0747f2;
P_0c0747f2: /* original f427, guest PC 0x0c0747f2 */
if(!s->budget--) { s->failed_pc=0x0c0747f2u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0747f4;
P_0c0747f4: /* original 905d, guest PC 0x0c0747f4 */
if(!s->budget--) { s->failed_pc=0x0c0747f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b2u,2);
goto P_0c0747f6;
P_0c0747f6: /* original f48d, guest PC 0x0c0747f6 */
if(!s->budget--) { s->failed_pc=0x0c0747f6u; return 0; }
fr[4]=0;
goto P_0c0747f8;
P_0c0747f8: /* original f447, guest PC 0x0c0747f8 */
if(!s->budget--) { s->failed_pc=0x0c0747f8u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0747fa;
P_0c0747fa: /* original 7008, guest PC 0x0c0747fa */
if(!s->budget--) { s->failed_pc=0x0c0747fau; return 0; }
r[0]+=0x00000008u;
goto P_0c0747fc;
P_0c0747fc: /* original 000b, guest PC 0x0c0747fc */
if(!s->budget--) { s->failed_pc=0x0c0747fcu; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c0747fe: /* original f447, guest PC 0x0c0747fe */
if(!s->budget--) { s->failed_pc=0x0c0747feu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c074800;
P_0c074800: /* original d12e, guest PC 0x0c074800 */
if(!s->budget--) { s->failed_pc=0x0c074800u; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c074802;
P_0c074802: /* original d32d, guest PC 0x0c074802 */
if(!s->budget--) { s->failed_pc=0x0c074802u; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c074804;
P_0c074804: /* original 6212, guest PC 0x0c074804 */
if(!s->budget--) { s->failed_pc=0x0c074804u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c074806;
P_0c074806: /* original 2238, guest PC 0x0c074806 */
if(!s->budget--) { s->failed_pc=0x0c074806u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c074808;
P_0c074808: /* original 8b0f, guest PC 0x0c074808 */
if(!s->budget--) { s->failed_pc=0x0c074808u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07482a; }
goto P_0c07480a;
P_0c07480a: /* original 914d, guest PC 0x0c07480a */
if(!s->budget--) { s->failed_pc=0x0c07480au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748a8u,2);
goto P_0c07480c;
P_0c07480c: /* original e014, guest PC 0x0c07480c */
if(!s->budget--) { s->failed_pc=0x0c07480cu; return 0; }
r[0]=0x00000014u;
goto P_0c07480e;
P_0c07480e: /* original f246, guest PC 0x0c07480e */
if(!s->budget--) { s->failed_pc=0x0c07480eu; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074810;
P_0c074810: /* original 314c, guest PC 0x0c074810 */
if(!s->budget--) { s->failed_pc=0x0c074810u; return 0; }
r[1]+=r[4];
goto P_0c074812;
P_0c074812: /* original f318, guest PC 0x0c074812 */
if(!s->budget--) { s->failed_pc=0x0c074812u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c074814;
P_0c074814: /* original f230, guest PC 0x0c074814 */
if(!s->budget--) { s->failed_pc=0x0c074814u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c074816;
P_0c074816: /* original f427, guest PC 0x0c074816 */
if(!s->budget--) { s->failed_pc=0x0c074816u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074818;
P_0c074818: /* original 9146, guest PC 0x0c074818 */
if(!s->budget--) { s->failed_pc=0x0c074818u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748a8u,2);
goto P_0c07481a;
P_0c07481a: /* original f256, guest PC 0x0c07481a */
if(!s->budget--) { s->failed_pc=0x0c07481au; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c07481c;
P_0c07481c: /* original 315c, guest PC 0x0c07481c */
if(!s->budget--) { s->failed_pc=0x0c07481cu; return 0; }
r[1]+=r[5];
goto P_0c07481e;
P_0c07481e: /* original f318, guest PC 0x0c07481e */
if(!s->budget--) { s->failed_pc=0x0c07481eu; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c074820;
P_0c074820: /* original f230, guest PC 0x0c074820 */
if(!s->budget--) { s->failed_pc=0x0c074820u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c074822;
P_0c074822: /* original f527, guest PC 0x0c074822 */
if(!s->budget--) { s->failed_pc=0x0c074822u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074824;
P_0c074824: /* original 9042, guest PC 0x0c074824 */
if(!s->budget--) { s->failed_pc=0x0c074824u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748acu,2);
goto P_0c074826;
P_0c074826: /* original f38d, guest PC 0x0c074826 */
if(!s->budget--) { s->failed_pc=0x0c074826u; return 0; }
fr[3]=0;
goto P_0c074828;
P_0c074828: /* original f437, guest PC 0x0c074828 */
if(!s->budget--) { s->failed_pc=0x0c074828u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c07482a;
P_0c07482a: /* original 000b, guest PC 0x0c07482a */
if(!s->budget--) { s->failed_pc=0x0c07482au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07482c: /* original 0009, guest PC 0x0c07482c */
if(!s->budget--) { s->failed_pc=0x0c07482cu; return 0; }
goto P_0c07482e;
P_0c07482e: /* original 4f22, guest PC 0x0c07482e */
if(!s->budget--) { s->failed_pc=0x0c07482eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c074830;
P_0c074830: /* original 7ff8, guest PC 0x0c074830 */
if(!s->budget--) { s->failed_pc=0x0c074830u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c074832;
P_0c074832: /* original 2f42, guest PC 0x0c074832 */
if(!s->budget--) { s->failed_pc=0x0c074832u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c074834;
P_0c074834: /* original 1f51, guest PC 0x0c074834 */
if(!s->budget--) { s->failed_pc=0x0c074834u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c074836;
P_0c074836: /* original d121, guest PC 0x0c074836 */
if(!s->budget--) { s->failed_pc=0x0c074836u; return 0; }
r[1]=read(ram,0x0c0748bcu,4);
goto P_0c074838;
P_0c074838: /* original d31f, guest PC 0x0c074838 */
if(!s->budget--) { s->failed_pc=0x0c074838u; return 0; }
r[3]=read(ram,0x0c0748b8u,4);
goto P_0c07483a;
P_0c07483a: /* original 6212, guest PC 0x0c07483a */
if(!s->budget--) { s->failed_pc=0x0c07483au; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c07483c;
P_0c07483c: /* original 2238, guest PC 0x0c07483c */
if(!s->budget--) { s->failed_pc=0x0c07483cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07483e;
P_0c07483e: /* original 8b05, guest PC 0x0c07483e */
if(!s->budget--) { s->failed_pc=0x0c07483eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07484c; }
goto P_0c074840;
P_0c074840: /* original 55f1, guest PC 0x0c074840 */
if(!s->budget--) { s->failed_pc=0x0c074840u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c074842;
P_0c074842: /* original b007, guest PC 0x0c074842 */
if(!s->budget--) { s->failed_pc=0x0c074842u; return 0; }
target=code_base|0x0c074854u; r[16]=code_base|0x0c074846u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c074846u) { target=s->pc; goto dispatch; }
goto P_0c074846;
P_0c074844: /* original 64f2, guest PC 0x0c074844 */
if(!s->budget--) { s->failed_pc=0x0c074844u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c074846;
P_0c074846: /* original 65f2, guest PC 0x0c074846 */
if(!s->budget--) { s->failed_pc=0x0c074846u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c074848;
P_0c074848: /* original b004, guest PC 0x0c074848 */
if(!s->budget--) { s->failed_pc=0x0c074848u; return 0; }
target=code_base|0x0c074854u; r[16]=code_base|0x0c07484cu;
r[4]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07484cu) { target=s->pc; goto dispatch; }
goto P_0c07484c;
P_0c07484a: /* original 54f1, guest PC 0x0c07484a */
if(!s->budget--) { s->failed_pc=0x0c07484au; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07484c;
P_0c07484c: /* original 7f08, guest PC 0x0c07484c */
if(!s->budget--) { s->failed_pc=0x0c07484cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07484e;
P_0c07484e: /* original 4f26, guest PC 0x0c07484e */
if(!s->budget--) { s->failed_pc=0x0c07484eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c074850;
P_0c074850: /* original 000b, guest PC 0x0c074850 */
if(!s->budget--) { s->failed_pc=0x0c074850u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c074852: /* original 0009, guest PC 0x0c074852 */
if(!s->budget--) { s->failed_pc=0x0c074852u; return 0; }
goto P_0c074854;
P_0c074854: /* original 902d, guest PC 0x0c074854 */
if(!s->budget--) { s->failed_pc=0x0c074854u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b2u,2);
goto P_0c074856;
P_0c074856: /* original 7ff4, guest PC 0x0c074856 */
if(!s->budget--) { s->failed_pc=0x0c074856u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c074858;
P_0c074858: /* original 952c, guest PC 0x0c074858 */
if(!s->budget--) { s->failed_pc=0x0c074858u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b4u,2);
goto P_0c07485a;
P_0c07485a: /* original f446, guest PC 0x0c07485a */
if(!s->budget--) { s->failed_pc=0x0c07485au; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c07485c;
P_0c07485c: /* original 7004, guest PC 0x0c07485c */
if(!s->budget--) { s->failed_pc=0x0c07485cu; return 0; }
r[0]+=0x00000004u;
goto P_0c07485e;
P_0c07485e: /* original f546, guest PC 0x0c07485e */
if(!s->budget--) { s->failed_pc=0x0c07485eu; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c074860;
P_0c074860: /* original 7004, guest PC 0x0c074860 */
if(!s->budget--) { s->failed_pc=0x0c074860u; return 0; }
r[0]+=0x00000004u;
goto P_0c074862;
P_0c074862: /* original f646, guest PC 0x0c074862 */
if(!s->budget--) { s->failed_pc=0x0c074862u; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c074864;
P_0c074864: /* original e010, guest PC 0x0c074864 */
if(!s->budget--) { s->failed_pc=0x0c074864u; return 0; }
r[0]=0x00000010u;
goto P_0c074866;
P_0c074866: /* original f346, guest PC 0x0c074866 */
if(!s->budget--) { s->failed_pc=0x0c074866u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074868;
P_0c074868: /* original 354c, guest PC 0x0c074868 */
if(!s->budget--) { s->failed_pc=0x0c074868u; return 0; }
r[5]+=r[4];
goto P_0c07486a;
P_0c07486a: /* original 9624, guest PC 0x0c07486a */
if(!s->budget--) { s->failed_pc=0x0c07486au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0748b6u,2);
goto P_0c07486c;
P_0c07486c: /* original f340, guest PC 0x0c07486c */
if(!s->budget--) { s->failed_pc=0x0c07486cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07486e;
P_0c07486e: /* original 365c, guest PC 0x0c07486e */
if(!s->budget--) { s->failed_pc=0x0c07486eu; return 0; }
r[6]+=r[5];
goto P_0c074870;
P_0c074870: /* original 3560, guest PC 0x0c074870 */
if(!s->budget--) { s->failed_pc=0x0c074870u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c074872;
P_0c074872: /* original f437, guest PC 0x0c074872 */
if(!s->budget--) { s->failed_pc=0x0c074872u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074874;
P_0c074874: /* original e014, guest PC 0x0c074874 */
if(!s->budget--) { s->failed_pc=0x0c074874u; return 0; }
r[0]=0x00000014u;
goto P_0c074876;
P_0c074876: /* original f246, guest PC 0x0c074876 */
if(!s->budget--) { s->failed_pc=0x0c074876u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074878;
P_0c074878: /* original f250, guest PC 0x0c074878 */
if(!s->budget--) { s->failed_pc=0x0c074878u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07487a;
P_0c07487a: /* original f427, guest PC 0x0c07487a */
if(!s->budget--) { s->failed_pc=0x0c07487au; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c07487c;
P_0c07487c: /* original e018, guest PC 0x0c07487c */
if(!s->budget--) { s->failed_pc=0x0c07487cu; return 0; }
r[0]=0x00000018u;
goto P_0c07487e;
P_0c07487e: /* original f346, guest PC 0x0c07487e */
if(!s->budget--) { s->failed_pc=0x0c07487eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c074880;
P_0c074880: /* original f360, guest PC 0x0c074880 */
if(!s->budget--) { s->failed_pc=0x0c074880u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c074882;
P_0c074882: /* original 8d0f, guest PC 0x0c074882 */
if(!s->budget--) { s->failed_pc=0x0c074882u; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(cond) { goto P_0c0748a4; }
goto P_0c074886;
P_0c074884: /* original f437, guest PC 0x0c074884 */
if(!s->budget--) { s->failed_pc=0x0c074884u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074886;
P_0c074886: /* original e030, guest PC 0x0c074886 */
if(!s->budget--) { s->failed_pc=0x0c074886u; return 0; }
r[0]=0x00000030u;
goto P_0c074888;
P_0c074888: /* original f356, guest PC 0x0c074888 */
if(!s->budget--) { s->failed_pc=0x0c074888u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c07488a;
P_0c07488a: /* original f340, guest PC 0x0c07488a */
if(!s->budget--) { s->failed_pc=0x0c07488au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c07488c;
P_0c07488c: /* original f537, guest PC 0x0c07488c */
if(!s->budget--) { s->failed_pc=0x0c07488cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c07488e;
P_0c07488e: /* original e034, guest PC 0x0c07488e */
if(!s->budget--) { s->failed_pc=0x0c07488eu; return 0; }
r[0]=0x00000034u;
goto P_0c074890;
P_0c074890: /* original f256, guest PC 0x0c074890 */
if(!s->budget--) { s->failed_pc=0x0c074890u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c074892;
P_0c074892: /* original f250, guest PC 0x0c074892 */
if(!s->budget--) { s->failed_pc=0x0c074892u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074894;
P_0c074894: /* original f527, guest PC 0x0c074894 */
if(!s->budget--) { s->failed_pc=0x0c074894u; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c074896;
P_0c074896: /* original e038, guest PC 0x0c074896 */
if(!s->budget--) { s->failed_pc=0x0c074896u; return 0; }
r[0]=0x00000038u;
goto P_0c074898;
P_0c074898: /* original f356, guest PC 0x0c074898 */
if(!s->budget--) { s->failed_pc=0x0c074898u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c07489a;
P_0c07489a: /* original f360, guest PC 0x0c07489a */
if(!s->budget--) { s->failed_pc=0x0c07489au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c07489c;
P_0c07489c: /* original f537, guest PC 0x0c07489c */
if(!s->budget--) { s->failed_pc=0x0c07489cu; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c07489e;
P_0c07489e: /* original 7540, guest PC 0x0c07489e */
if(!s->budget--) { s->failed_pc=0x0c07489eu; return 0; }
r[5]+=0x00000040u;
goto P_0c0748a0;
P_0c0748a0: /* original 3560, guest PC 0x0c0748a0 */
if(!s->budget--) { s->failed_pc=0x0c0748a0u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0748a2;
P_0c0748a2: /* original 8bf0, guest PC 0x0c0748a2 */
if(!s->budget--) { s->failed_pc=0x0c0748a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074886; }
goto P_0c0748a4;
P_0c0748a4: /* original 000b, guest PC 0x0c0748a4 */
if(!s->budget--) { s->failed_pc=0x0c0748a4u; return 0; }
target=r[16];
r[15]+=0x0000000cu;
s->pc=target; return ram->oob==0;
P_0c0748a6: /* original 7f0c, guest PC 0x0c0748a6 */
if(!s->budget--) { s->failed_pc=0x0c0748a6u; return 0; }
r[15]+=0x0000000cu;
if(!vf3_matrix_family(0x0c0748a8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0748a8u; return 0; } return 1;
P_0c0748c0: /* original 4f22, guest PC 0x0c0748c0 */
if(!s->budget--) { s->failed_pc=0x0c0748c0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0748c2;
P_0c0748c2: /* original 7ffc, guest PC 0x0c0748c2 */
if(!s->budget--) { s->failed_pc=0x0c0748c2u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0748c4;
P_0c0748c4: /* original 2f52, guest PC 0x0c0748c4 */
if(!s->budget--) { s->failed_pc=0x0c0748c4u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0748c6;
P_0c0748c6: /* original d13a, guest PC 0x0c0748c6 */
if(!s->budget--) { s->failed_pc=0x0c0748c6u; return 0; }
r[1]=read(ram,0x0c0749b0u,4);
goto P_0c0748c8;
P_0c0748c8: /* original d338, guest PC 0x0c0748c8 */
if(!s->budget--) { s->failed_pc=0x0c0748c8u; return 0; }
r[3]=read(ram,0x0c0749acu,4);
goto P_0c0748ca;
P_0c0748ca: /* original 6212, guest PC 0x0c0748ca */
if(!s->budget--) { s->failed_pc=0x0c0748cau; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0748cc;
P_0c0748cc: /* original 2238, guest PC 0x0c0748cc */
if(!s->budget--) { s->failed_pc=0x0c0748ccu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0748ce;
P_0c0748ce: /* original 8b03, guest PC 0x0c0748ce */
if(!s->budget--) { s->failed_pc=0x0c0748ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0748d8; }
goto P_0c0748d0;
P_0c0748d0: /* original b006, guest PC 0x0c0748d0 */
if(!s->budget--) { s->failed_pc=0x0c0748d0u; return 0; }
target=code_base|0x0c0748e0u; r[16]=code_base|0x0c0748d4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0748d4u) { target=s->pc; goto dispatch; }
goto P_0c0748d4;
P_0c0748d2: /* original 0009, guest PC 0x0c0748d2 */
if(!s->budget--) { s->failed_pc=0x0c0748d2u; return 0; }
goto P_0c0748d4;
P_0c0748d4: /* original b004, guest PC 0x0c0748d4 */
if(!s->budget--) { s->failed_pc=0x0c0748d4u; return 0; }
target=code_base|0x0c0748e0u; r[16]=code_base|0x0c0748d8u;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0748d8u) { target=s->pc; goto dispatch; }
goto P_0c0748d8;
P_0c0748d6: /* original 64f2, guest PC 0x0c0748d6 */
if(!s->budget--) { s->failed_pc=0x0c0748d6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0748d8;
P_0c0748d8: /* original 7f04, guest PC 0x0c0748d8 */
if(!s->budget--) { s->failed_pc=0x0c0748d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0748da;
P_0c0748da: /* original 4f26, guest PC 0x0c0748da */
if(!s->budget--) { s->failed_pc=0x0c0748dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0748dc;
P_0c0748dc: /* original 000b, guest PC 0x0c0748dc */
if(!s->budget--) { s->failed_pc=0x0c0748dcu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0748de: /* original 0009, guest PC 0x0c0748de */
if(!s->budget--) { s->failed_pc=0x0c0748deu; return 0; }
goto P_0c0748e0;
P_0c0748e0: /* original 905e, guest PC 0x0c0748e0 */
if(!s->budget--) { s->failed_pc=0x0c0748e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a0u,2);
goto P_0c0748e2;
P_0c0748e2: /* original 965e, guest PC 0x0c0748e2 */
if(!s->budget--) { s->failed_pc=0x0c0748e2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a2u,2);
goto P_0c0748e4;
P_0c0748e4: /* original f446, guest PC 0x0c0748e4 */
if(!s->budget--) { s->failed_pc=0x0c0748e4u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0748e6;
P_0c0748e6: /* original 7004, guest PC 0x0c0748e6 */
if(!s->budget--) { s->failed_pc=0x0c0748e6u; return 0; }
r[0]+=0x00000004u;
goto P_0c0748e8;
P_0c0748e8: /* original f546, guest PC 0x0c0748e8 */
if(!s->budget--) { s->failed_pc=0x0c0748e8u; return 0; }
vf3_matrix_load(s,ram,5,r[4]+r[0]);
goto P_0c0748ea;
P_0c0748ea: /* original 7004, guest PC 0x0c0748ea */
if(!s->budget--) { s->failed_pc=0x0c0748eau; return 0; }
r[0]+=0x00000004u;
goto P_0c0748ec;
P_0c0748ec: /* original f646, guest PC 0x0c0748ec */
if(!s->budget--) { s->failed_pc=0x0c0748ecu; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c0748ee;
P_0c0748ee: /* original 70dc, guest PC 0x0c0748ee */
if(!s->budget--) { s->failed_pc=0x0c0748eeu; return 0; }
r[0]+=0xffffffdcu;
goto P_0c0748f0;
P_0c0748f0: /* original 054e, guest PC 0x0c0748f0 */
if(!s->budget--) { s->failed_pc=0x0c0748f0u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0748f2;
P_0c0748f2: /* original 9057, guest PC 0x0c0748f2 */
if(!s->budget--) { s->failed_pc=0x0c0748f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0749a4u,2);
goto P_0c0748f4;
P_0c0748f4: /* original 365c, guest PC 0x0c0748f4 */
if(!s->budget--) { s->failed_pc=0x0c0748f4u; return 0; }
r[6]+=r[5];
goto P_0c0748f6;
P_0c0748f6: /* original f346, guest PC 0x0c0748f6 */
if(!s->budget--) { s->failed_pc=0x0c0748f6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0748f8;
P_0c0748f8: /* original 3560, guest PC 0x0c0748f8 */
if(!s->budget--) { s->failed_pc=0x0c0748f8u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0748fa;
P_0c0748fa: /* original f340, guest PC 0x0c0748fa */
if(!s->budget--) { s->failed_pc=0x0c0748fau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c0748fc;
P_0c0748fc: /* original f437, guest PC 0x0c0748fc */
if(!s->budget--) { s->failed_pc=0x0c0748fcu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0748fe;
P_0c0748fe: /* original 7004, guest PC 0x0c0748fe */
if(!s->budget--) { s->failed_pc=0x0c0748feu; return 0; }
r[0]+=0x00000004u;
goto P_0c074900;
P_0c074900: /* original f246, guest PC 0x0c074900 */
if(!s->budget--) { s->failed_pc=0x0c074900u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c074902;
P_0c074902: /* original f250, guest PC 0x0c074902 */
if(!s->budget--) { s->failed_pc=0x0c074902u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c074904;
P_0c074904: /* original f427, guest PC 0x0c074904 */
if(!s->budget--) { s->failed_pc=0x0c074904u; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c074906;
P_0c074906: /* original 7004, guest PC 0x0c074906 */
if(!s->budget--) { s->failed_pc=0x0c074906u; return 0; }
r[0]+=0x00000004u;
goto P_0c074908;
P_0c074908: /* original f346, guest PC 0x0c074908 */
if(!s->budget--) { s->failed_pc=0x0c074908u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c07490a;
P_0c07490a: /* original f360, guest PC 0x0c07490a */
if(!s->budget--) { s->failed_pc=0x0c07490au; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c07490c;
P_0c07490c: /* original 8d0e, guest PC 0x0c07490c */
if(!s->budget--) { s->failed_pc=0x0c07490cu; return 0; }
cond=r[17]&1u;
vf3_matrix_store(s,ram,3,r[4]+r[0]);
if(cond) { goto P_0c07492c; }
goto P_0c074910;
P_0c07490e: /* original f437, guest PC 0x0c07490e */
if(!s->budget--) { s->failed_pc=0x0c07490eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c074910;
P_0c074910: /* original e004, guest PC 0x0c074910 */
if(!s->budget--) { s->failed_pc=0x0c074910u; return 0; }
r[0]=0x00000004u;
goto P_0c074912;
P_0c074912: /* original f358, guest PC 0x0c074912 */
if(!s->budget--) { s->failed_pc=0x0c074912u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c074914;
P_0c074914: /* original f340, guest PC 0x0c074914 */
if(!s->budget--) { s->failed_pc=0x0c074914u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c074916;
P_0c074916: /* original f53a, guest PC 0x0c074916 */
if(!s->budget--) { s->failed_pc=0x0c074916u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c074918;
P_0c074918: /* original f256, guest PC 0x0c074918 */
if(!s->budget--) { s->failed_pc=0x0c074918u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c07491a;
P_0c07491a: /* original f250, guest PC 0x0c07491a */
if(!s->budget--) { s->failed_pc=0x0c07491au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[5],r[18],'+');
goto P_0c07491c;
P_0c07491c: /* original f527, guest PC 0x0c07491c */
if(!s->budget--) { s->failed_pc=0x0c07491cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c07491e;
P_0c07491e: /* original e008, guest PC 0x0c07491e */
if(!s->budget--) { s->failed_pc=0x0c07491eu; return 0; }
r[0]=0x00000008u;
goto P_0c074920;
P_0c074920: /* original f356, guest PC 0x0c074920 */
if(!s->budget--) { s->failed_pc=0x0c074920u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c074922;
P_0c074922: /* original f360, guest PC 0x0c074922 */
if(!s->budget--) { s->failed_pc=0x0c074922u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'+');
goto P_0c074924;
P_0c074924: /* original f537, guest PC 0x0c074924 */
if(!s->budget--) { s->failed_pc=0x0c074924u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c074926;
P_0c074926: /* original 750c, guest PC 0x0c074926 */
if(!s->budget--) { s->failed_pc=0x0c074926u; return 0; }
r[5]+=0x0000000cu;
goto P_0c074928;
P_0c074928: /* original 3560, guest PC 0x0c074928 */
if(!s->budget--) { s->failed_pc=0x0c074928u; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c07492a;
P_0c07492a: /* original 8bf1, guest PC 0x0c07492a */
if(!s->budget--) { s->failed_pc=0x0c07492au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c074910; }
goto P_0c07492c;
P_0c07492c: /* original 000b, guest PC 0x0c07492c */
if(!s->budget--) { s->failed_pc=0x0c07492cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c07492e: /* original 0009, guest PC 0x0c07492e */
if(!s->budget--) { s->failed_pc=0x0c07492eu; return 0; }
if(!vf3_matrix_family(0x0c074930u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c074930u; return 0; } return 1;
P_0c07a7a8: /* original 2fe6, guest PC 0x0c07a7a8 */
if(!s->budget--) { s->failed_pc=0x0c07a7a8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7aa;
P_0c07a7aa: /* original 2fd6, guest PC 0x0c07a7aa */
if(!s->budget--) { s->failed_pc=0x0c07a7aau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7ac;
P_0c07a7ac: /* original 2fc6, guest PC 0x0c07a7ac */
if(!s->budget--) { s->failed_pc=0x0c07a7acu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7ae;
P_0c07a7ae: /* original 2fb6, guest PC 0x0c07a7ae */
if(!s->budget--) { s->failed_pc=0x0c07a7aeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7b0;
P_0c07a7b0: /* original 2fa6, guest PC 0x0c07a7b0 */
if(!s->budget--) { s->failed_pc=0x0c07a7b0u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07a7b2;
P_0c07a7b2: /* original 4f22, guest PC 0x0c07a7b2 */
if(!s->budget--) { s->failed_pc=0x0c07a7b2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07a7b4;
P_0c07a7b4: /* original d27f, guest PC 0x0c07a7b4 */
if(!s->budget--) { s->failed_pc=0x0c07a7b4u; return 0; }
r[2]=read(ram,0x0c07a9b4u,4);
goto P_0c07a7b6;
P_0c07a7b6: /* original d380, guest PC 0x0c07a7b6 */
if(!s->budget--) { s->failed_pc=0x0c07a7b6u; return 0; }
r[3]=read(ram,0x0c07a9b8u,4);
goto P_0c07a7b8;
P_0c07a7b8: /* original 7fe0, guest PC 0x0c07a7b8 */
if(!s->budget--) { s->failed_pc=0x0c07a7b8u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07a7ba;
P_0c07a7ba: /* original 6df3, guest PC 0x0c07a7ba */
if(!s->budget--) { s->failed_pc=0x0c07a7bau; return 0; }
r[13]=r[15];
goto P_0c07a7bc;
P_0c07a7bc: /* original 61f3, guest PC 0x0c07a7bc */
if(!s->budget--) { s->failed_pc=0x0c07a7bcu; return 0; }
r[1]=r[15];
goto P_0c07a7be;
P_0c07a7be: /* original 430b, guest PC 0x0c07a7be */
if(!s->budget--) { s->failed_pc=0x0c07a7beu; return 0; }
target=r[3];
r[16]=code_base|0x0c07a7c2u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a7c2u) { target=s->pc; goto dispatch; }
goto P_0c07a7c2;
P_0c07a7c0: /* original e020, guest PC 0x0c07a7c0 */
if(!s->budget--) { s->failed_pc=0x0c07a7c0u; return 0; }
r[0]=0x00000020u;
goto P_0c07a7c2;
P_0c07a7c2: /* original db7f, guest PC 0x0c07a7c2 */
if(!s->budget--) { s->failed_pc=0x0c07a7c2u; return 0; }
r[11]=read(ram,0x0c07a9c0u,4);
goto P_0c07a7c4;
P_0c07a7c4: /* original ee00, guest PC 0x0c07a7c4 */
if(!s->budget--) { s->failed_pc=0x0c07a7c4u; return 0; }
r[14]=0x00000000u;
goto P_0c07a7c6;
P_0c07a7c6: /* original da7d, guest PC 0x0c07a7c6 */
if(!s->budget--) { s->failed_pc=0x0c07a7c6u; return 0; }
r[10]=read(ram,0x0c07a9bcu,4);
goto P_0c07a7c8;
P_0c07a7c8: /* original ec54, guest PC 0x0c07a7c8 */
if(!s->budget--) { s->failed_pc=0x0c07a7c8u; return 0; }
r[12]=0x00000054u;
goto P_0c07a7ca;
P_0c07a7ca: /* original 4b0b, guest PC 0x0c07a7ca */
if(!s->budget--) { s->failed_pc=0x0c07a7cau; return 0; }
target=r[11];
r[16]=code_base|0x0c07a7ceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a7ceu) { target=s->pc; goto dispatch; }
goto P_0c07a7ce;
P_0c07a7cc: /* original 64e3, guest PC 0x0c07a7cc */
if(!s->budget--) { s->failed_pc=0x0c07a7ccu; return 0; }
r[4]=r[14];
goto P_0c07a7ce;
P_0c07a7ce: /* original 4a0b, guest PC 0x0c07a7ce */
if(!s->budget--) { s->failed_pc=0x0c07a7ceu; return 0; }
target=r[10];
r[16]=code_base|0x0c07a7d2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07a7d2u) { target=s->pc; goto dispatch; }
goto P_0c07a7d2;
P_0c07a7d0: /* original 64d3, guest PC 0x0c07a7d0 */
if(!s->budget--) { s->failed_pc=0x0c07a7d0u; return 0; }
r[4]=r[13];
goto P_0c07a7d2;
P_0c07a7d2: /* original 7e01, guest PC 0x0c07a7d2 */
if(!s->budget--) { s->failed_pc=0x0c07a7d2u; return 0; }
r[14]+=0x00000001u;
goto P_0c07a7d4;
P_0c07a7d4: /* original 3ec3, guest PC 0x0c07a7d4 */
if(!s->budget--) { s->failed_pc=0x0c07a7d4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[12])!=0);
goto P_0c07a7d6;
P_0c07a7d6: /* original 8bf8, guest PC 0x0c07a7d6 */
if(!s->budget--) { s->failed_pc=0x0c07a7d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07a7ca; }
goto P_0c07a7d8;
P_0c07a7d8: /* original 7f20, guest PC 0x0c07a7d8 */
if(!s->budget--) { s->failed_pc=0x0c07a7d8u; return 0; }
r[15]+=0x00000020u;
goto P_0c07a7da;
P_0c07a7da: /* original 4f26, guest PC 0x0c07a7da */
if(!s->budget--) { s->failed_pc=0x0c07a7dau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07a7dc;
P_0c07a7dc: /* original 6af6, guest PC 0x0c07a7dc */
if(!s->budget--) { s->failed_pc=0x0c07a7dcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07a7de;
P_0c07a7de: /* original 6bf6, guest PC 0x0c07a7de */
if(!s->budget--) { s->failed_pc=0x0c07a7deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07a7e0;
P_0c07a7e0: /* original 6cf6, guest PC 0x0c07a7e0 */
if(!s->budget--) { s->failed_pc=0x0c07a7e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07a7e2;
P_0c07a7e2: /* original 6df6, guest PC 0x0c07a7e2 */
if(!s->budget--) { s->failed_pc=0x0c07a7e2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07a7e4;
P_0c07a7e4: /* original 000b, guest PC 0x0c07a7e4 */
if(!s->budget--) { s->failed_pc=0x0c07a7e4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07a7e6: /* original 6ef6, guest PC 0x0c07a7e6 */
if(!s->budget--) { s->failed_pc=0x0c07a7e6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07a7e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07a7e8u; return 0; } return 1;
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
