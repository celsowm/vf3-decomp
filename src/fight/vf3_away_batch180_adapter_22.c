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
int vf3_away_batch180_adapter_22(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09a750u: goto P_0c09a750;
case 0x0c09a752u: goto P_0c09a752;
case 0x0c09a754u: goto P_0c09a754;
case 0x0c09a756u: goto P_0c09a756;
case 0x0c09a758u: goto P_0c09a758;
case 0x0c09a75au: goto P_0c09a75a;
case 0x0c09a75cu: goto P_0c09a75c;
case 0x0c09a75eu: goto P_0c09a75e;
case 0x0c09a760u: goto P_0c09a760;
case 0x0c09a762u: goto P_0c09a762;
case 0x0c09a764u: goto P_0c09a764;
case 0x0c09a766u: goto P_0c09a766;
case 0x0c09a768u: goto P_0c09a768;
case 0x0c09a76au: goto P_0c09a76a;
case 0x0c09a76cu: goto P_0c09a76c;
case 0x0c09a76eu: goto P_0c09a76e;
case 0x0c09a770u: goto P_0c09a770;
case 0x0c09a772u: goto P_0c09a772;
case 0x0c09a774u: goto P_0c09a774;
case 0x0c09a776u: goto P_0c09a776;
case 0x0c09a778u: goto P_0c09a778;
case 0x0c09a77au: goto P_0c09a77a;
case 0x0c09a77cu: goto P_0c09a77c;
case 0x0c09a77eu: goto P_0c09a77e;
case 0x0c09a780u: goto P_0c09a780;
case 0x0c09a782u: goto P_0c09a782;
case 0x0c09a784u: goto P_0c09a784;
case 0x0c09a786u: goto P_0c09a786;
case 0x0c09a788u: goto P_0c09a788;
case 0x0c09a78au: goto P_0c09a78a;
case 0x0c09a78cu: goto P_0c09a78c;
case 0x0c09a78eu: goto P_0c09a78e;
case 0x0c09a790u: goto P_0c09a790;
case 0x0c09a792u: goto P_0c09a792;
case 0x0c09a794u: goto P_0c09a794;
case 0x0c09a796u: goto P_0c09a796;
case 0x0c09a798u: goto P_0c09a798;
case 0x0c09a79au: goto P_0c09a79a;
case 0x0c09aa04u: goto P_0c09aa04;
case 0x0c09aa06u: goto P_0c09aa06;
case 0x0c09aa08u: goto P_0c09aa08;
case 0x0c09aa0au: goto P_0c09aa0a;
case 0x0c09aa0cu: goto P_0c09aa0c;
case 0x0c09aa0eu: goto P_0c09aa0e;
case 0x0c09aa10u: goto P_0c09aa10;
case 0x0c09aa12u: goto P_0c09aa12;
case 0x0c09aa14u: goto P_0c09aa14;
case 0x0c09aa16u: goto P_0c09aa16;
case 0x0c09aa18u: goto P_0c09aa18;
case 0x0c09aa1au: goto P_0c09aa1a;
case 0x0c09aa1cu: goto P_0c09aa1c;
case 0x0c09aa1eu: goto P_0c09aa1e;
case 0x0c09aa20u: goto P_0c09aa20;
case 0x0c09aa22u: goto P_0c09aa22;
case 0x0c09aa24u: goto P_0c09aa24;
case 0x0c09aa26u: goto P_0c09aa26;
case 0x0c09aa28u: goto P_0c09aa28;
case 0x0c09aa2au: goto P_0c09aa2a;
case 0x0c09aa2cu: goto P_0c09aa2c;
case 0x0c09aa2eu: goto P_0c09aa2e;
case 0x0c09aa30u: goto P_0c09aa30;
case 0x0c09aa32u: goto P_0c09aa32;
case 0x0c09aa34u: goto P_0c09aa34;
case 0x0c09aa36u: goto P_0c09aa36;
case 0x0c09aa38u: goto P_0c09aa38;
case 0x0c09aa3au: goto P_0c09aa3a;
case 0x0c09aa3cu: goto P_0c09aa3c;
case 0x0c09aa3eu: goto P_0c09aa3e;
case 0x0c09aa40u: goto P_0c09aa40;
case 0x0c09aa42u: goto P_0c09aa42;
case 0x0c09aa44u: goto P_0c09aa44;
case 0x0c09aa46u: goto P_0c09aa46;
case 0x0c09aa48u: goto P_0c09aa48;
case 0x0c09aa4au: goto P_0c09aa4a;
case 0x0c09aa4cu: goto P_0c09aa4c;
case 0x0c09aa4eu: goto P_0c09aa4e;
case 0x0c09aa50u: goto P_0c09aa50;
case 0x0c09aa52u: goto P_0c09aa52;
case 0x0c09aa54u: goto P_0c09aa54;
case 0x0c09aa56u: goto P_0c09aa56;
case 0x0c09aa58u: goto P_0c09aa58;
case 0x0c09aa5au: goto P_0c09aa5a;
case 0x0c09aa5cu: goto P_0c09aa5c;
case 0x0c09aa5eu: goto P_0c09aa5e;
case 0x0c09aa60u: goto P_0c09aa60;
case 0x0c09aa62u: goto P_0c09aa62;
case 0x0c09aa64u: goto P_0c09aa64;
case 0x0c09aa66u: goto P_0c09aa66;
case 0x0c09aa68u: goto P_0c09aa68;
case 0x0c09aa6au: goto P_0c09aa6a;
case 0x0c09aa6cu: goto P_0c09aa6c;
case 0x0c09aa6eu: goto P_0c09aa6e;
case 0x0c09aa70u: goto P_0c09aa70;
case 0x0c09aa72u: goto P_0c09aa72;
case 0x0c09aa74u: goto P_0c09aa74;
case 0x0c09aa76u: goto P_0c09aa76;
case 0x0c09aa78u: goto P_0c09aa78;
case 0x0c09aa7au: goto P_0c09aa7a;
case 0x0c09aa7cu: goto P_0c09aa7c;
case 0x0c09aa7eu: goto P_0c09aa7e;
case 0x0c09aa80u: goto P_0c09aa80;
case 0x0c09aa82u: goto P_0c09aa82;
case 0x0c09aa84u: goto P_0c09aa84;
case 0x0c09aa86u: goto P_0c09aa86;
case 0x0c09aa88u: goto P_0c09aa88;
case 0x0c09aa8au: goto P_0c09aa8a;
case 0x0c09aa8cu: goto P_0c09aa8c;
case 0x0c09aa8eu: goto P_0c09aa8e;
case 0x0c09aa90u: goto P_0c09aa90;
case 0x0c09aa92u: goto P_0c09aa92;
case 0x0c09aa94u: goto P_0c09aa94;
case 0x0c09aa96u: goto P_0c09aa96;
case 0x0c09aa98u: goto P_0c09aa98;
case 0x0c09aa9au: goto P_0c09aa9a;
case 0x0c09aa9cu: goto P_0c09aa9c;
case 0x0c09aa9eu: goto P_0c09aa9e;
case 0x0c09aaa0u: goto P_0c09aaa0;
case 0x0c09aaa2u: goto P_0c09aaa2;
case 0x0c09aaa4u: goto P_0c09aaa4;
case 0x0c09aaa6u: goto P_0c09aaa6;
case 0x0c09aaa8u: goto P_0c09aaa8;
case 0x0c09aaaau: goto P_0c09aaaa;
case 0x0c09aaacu: goto P_0c09aaac;
case 0x0c09aaaeu: goto P_0c09aaae;
case 0x0c09aab0u: goto P_0c09aab0;
case 0x0c09aab2u: goto P_0c09aab2;
case 0x0c09aab4u: goto P_0c09aab4;
case 0x0c09aab6u: goto P_0c09aab6;
case 0x0c09aab8u: goto P_0c09aab8;
case 0x0c09aabau: goto P_0c09aaba;
case 0x0c09aabcu: goto P_0c09aabc;
case 0x0c09aabeu: goto P_0c09aabe;
case 0x0c09aac0u: goto P_0c09aac0;
case 0x0c09aac2u: goto P_0c09aac2;
case 0x0c09aac4u: goto P_0c09aac4;
case 0x0c09aac6u: goto P_0c09aac6;
case 0x0c09aac8u: goto P_0c09aac8;
case 0x0c09aacau: goto P_0c09aaca;
case 0x0c09aaccu: goto P_0c09aacc;
case 0x0c09aaceu: goto P_0c09aace;
case 0x0c09aad0u: goto P_0c09aad0;
case 0x0c09aad2u: goto P_0c09aad2;
case 0x0c09aad4u: goto P_0c09aad4;
case 0x0c09aad6u: goto P_0c09aad6;
case 0x0c09aad8u: goto P_0c09aad8;
case 0x0c09aadau: goto P_0c09aada;
case 0x0c09aadcu: goto P_0c09aadc;
case 0x0c09aadeu: goto P_0c09aade;
case 0x0c09aae0u: goto P_0c09aae0;
case 0x0c09aae2u: goto P_0c09aae2;
case 0x0c09aae4u: goto P_0c09aae4;
case 0x0c09aae6u: goto P_0c09aae6;
case 0x0c09aae8u: goto P_0c09aae8;
case 0x0c09aaeau: goto P_0c09aaea;
case 0x0c09aaecu: goto P_0c09aaec;
case 0x0c09aaeeu: goto P_0c09aaee;
case 0x0c09aaf0u: goto P_0c09aaf0;
case 0x0c09aaf2u: goto P_0c09aaf2;
case 0x0c09aaf4u: goto P_0c09aaf4;
case 0x0c09aaf6u: goto P_0c09aaf6;
case 0x0c09aaf8u: goto P_0c09aaf8;
case 0x0c09aafau: goto P_0c09aafa;
case 0x0c09aafcu: goto P_0c09aafc;
case 0x0c09aafeu: goto P_0c09aafe;
case 0x0c09ab00u: goto P_0c09ab00;
case 0x0c09ab02u: goto P_0c09ab02;
case 0x0c09ab04u: goto P_0c09ab04;
case 0x0c09ab06u: goto P_0c09ab06;
case 0x0c09ab08u: goto P_0c09ab08;
case 0x0c09ab0au: goto P_0c09ab0a;
case 0x0c09ab0cu: goto P_0c09ab0c;
case 0x0c09ab0eu: goto P_0c09ab0e;
case 0x0c09ab10u: goto P_0c09ab10;
case 0x0c09ab12u: goto P_0c09ab12;
case 0x0c09ab14u: goto P_0c09ab14;
case 0x0c09ab16u: goto P_0c09ab16;
case 0x0c09ab18u: goto P_0c09ab18;
case 0x0c09ab1au: goto P_0c09ab1a;
case 0x0c09ab1cu: goto P_0c09ab1c;
case 0x0c09ab1eu: goto P_0c09ab1e;
case 0x0c09ab20u: goto P_0c09ab20;
case 0x0c09ab22u: goto P_0c09ab22;
case 0x0c09ab24u: goto P_0c09ab24;
case 0x0c09ab26u: goto P_0c09ab26;
case 0x0c09ab28u: goto P_0c09ab28;
case 0x0c09ab2au: goto P_0c09ab2a;
case 0x0c09ab2cu: goto P_0c09ab2c;
case 0x0c09ab2eu: goto P_0c09ab2e;
case 0x0c09ab30u: goto P_0c09ab30;
case 0x0c09ab32u: goto P_0c09ab32;
case 0x0c09ab34u: goto P_0c09ab34;
case 0x0c09ab36u: goto P_0c09ab36;
case 0x0c09ab38u: goto P_0c09ab38;
case 0x0c09ab3au: goto P_0c09ab3a;
case 0x0c09ab3cu: goto P_0c09ab3c;
case 0x0c09ab3eu: goto P_0c09ab3e;
case 0x0c09ab40u: goto P_0c09ab40;
case 0x0c09ab42u: goto P_0c09ab42;
case 0x0c09ab44u: goto P_0c09ab44;
case 0x0c09ab46u: goto P_0c09ab46;
case 0x0c09ab48u: goto P_0c09ab48;
case 0x0c09ab4au: goto P_0c09ab4a;
case 0x0c09ab4cu: goto P_0c09ab4c;
case 0x0c09ab4eu: goto P_0c09ab4e;
case 0x0c09ab50u: goto P_0c09ab50;
case 0x0c09ab52u: goto P_0c09ab52;
case 0x0c09ab54u: goto P_0c09ab54;
case 0x0c09ab56u: goto P_0c09ab56;
case 0x0c09ab58u: goto P_0c09ab58;
case 0x0c09ab5au: goto P_0c09ab5a;
case 0x0c09ab5cu: goto P_0c09ab5c;
case 0x0c09ab5eu: goto P_0c09ab5e;
case 0x0c09ab60u: goto P_0c09ab60;
case 0x0c09ab62u: goto P_0c09ab62;
case 0x0c09efceu: goto P_0c09efce;
case 0x0c09efd0u: goto P_0c09efd0;
case 0x0c09efd2u: goto P_0c09efd2;
case 0x0c09efd4u: goto P_0c09efd4;
case 0x0c09efd6u: goto P_0c09efd6;
case 0x0c09efd8u: goto P_0c09efd8;
case 0x0c09efdau: goto P_0c09efda;
case 0x0c09efdcu: goto P_0c09efdc;
case 0x0c09efdeu: goto P_0c09efde;
case 0x0c09efe0u: goto P_0c09efe0;
case 0x0c09efe2u: goto P_0c09efe2;
case 0x0c09efe4u: goto P_0c09efe4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09a750: /* original 2fe6, guest PC 0x0c09a750 */
if(!s->budget--) { s->failed_pc=0x0c09a750u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a752;
P_0c09a752: /* original 2fd6, guest PC 0x0c09a752 */
if(!s->budget--) { s->failed_pc=0x0c09a752u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09a754;
P_0c09a754: /* original 9062, guest PC 0x0c09a754 */
if(!s->budget--) { s->failed_pc=0x0c09a754u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a81cu,2);
goto P_0c09a756;
P_0c09a756: /* original dd34, guest PC 0x0c09a756 */
if(!s->budget--) { s->failed_pc=0x0c09a756u; return 0; }
r[13]=read(ram,0x0c09a828u,4);
goto P_0c09a758;
P_0c09a758: /* original 4f22, guest PC 0x0c09a758 */
if(!s->budget--) { s->failed_pc=0x0c09a758u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09a75a;
P_0c09a75a: /* original 00dc, guest PC 0x0c09a75a */
if(!s->budget--) { s->failed_pc=0x0c09a75au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c09a75c;
P_0c09a75c: /* original de33, guest PC 0x0c09a75c */
if(!s->budget--) { s->failed_pc=0x0c09a75cu; return 0; }
r[14]=read(ram,0x0c09a82cu,4);
goto P_0c09a75e;
P_0c09a75e: /* original 8801, guest PC 0x0c09a75e */
if(!s->budget--) { s->failed_pc=0x0c09a75eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09a760;
P_0c09a760: /* original 890d, guest PC 0x0c09a760 */
if(!s->budget--) { s->failed_pc=0x0c09a760u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a77e; }
goto P_0c09a762;
P_0c09a762: /* original d333, guest PC 0x0c09a762 */
if(!s->budget--) { s->failed_pc=0x0c09a762u; return 0; }
r[3]=read(ram,0x0c09a830u,4);
goto P_0c09a764;
P_0c09a764: /* original 430b, guest PC 0x0c09a764 */
if(!s->budget--) { s->failed_pc=0x0c09a764u; return 0; }
target=r[3];
r[16]=code_base|0x0c09a768u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09a768u) { target=s->pc; goto dispatch; }
goto P_0c09a768;
P_0c09a766: /* original 0009, guest PC 0x0c09a766 */
if(!s->budget--) { s->failed_pc=0x0c09a766u; return 0; }
goto P_0c09a768;
P_0c09a768: /* original 52e3, guest PC 0x0c09a768 */
if(!s->budget--) { s->failed_pc=0x0c09a768u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c09a76a;
P_0c09a76a: /* original 4215, guest PC 0x0c09a76a */
if(!s->budget--) { s->failed_pc=0x0c09a76au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c09a76c;
P_0c09a76c: /* original 8912, guest PC 0x0c09a76c */
if(!s->budget--) { s->failed_pc=0x0c09a76cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a794; }
goto P_0c09a76e;
P_0c09a76e: /* original 9055, guest PC 0x0c09a76e */
if(!s->budget--) { s->failed_pc=0x0c09a76eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a81cu,2);
goto P_0c09a770;
P_0c09a770: /* original e101, guest PC 0x0c09a770 */
if(!s->budget--) { s->failed_pc=0x0c09a770u; return 0; }
r[1]=0x00000001u;
goto P_0c09a772;
P_0c09a772: /* original e22d, guest PC 0x0c09a772 */
if(!s->budget--) { s->failed_pc=0x0c09a772u; return 0; }
r[2]=0x0000002du;
goto P_0c09a774;
P_0c09a774: /* original 0d14, guest PC 0x0c09a774 */
if(!s->budget--) { s->failed_pc=0x0c09a774u; return 0; }
write(ram,r[13]+r[0],r[1],1);
goto P_0c09a776;
P_0c09a776: /* original e010, guest PC 0x0c09a776 */
if(!s->budget--) { s->failed_pc=0x0c09a776u; return 0; }
r[0]=0x00000010u;
goto P_0c09a778;
P_0c09a778: /* original 9351, guest PC 0x0c09a778 */
if(!s->budget--) { s->failed_pc=0x0c09a778u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09a81eu,2);
goto P_0c09a77a;
P_0c09a77a: /* original 1e33, guest PC 0x0c09a77a */
if(!s->budget--) { s->failed_pc=0x0c09a77au; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c09a77c;
P_0c09a77c: /* original 0e24, guest PC 0x0c09a77c */
if(!s->budget--) { s->failed_pc=0x0c09a77cu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09a77e;
P_0c09a77e: /* original 53e3, guest PC 0x0c09a77e */
if(!s->budget--) { s->failed_pc=0x0c09a77eu; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c09a780;
P_0c09a780: /* original 4315, guest PC 0x0c09a780 */
if(!s->budget--) { s->failed_pc=0x0c09a780u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09a782;
P_0c09a782: /* original 8907, guest PC 0x0c09a782 */
if(!s->budget--) { s->failed_pc=0x0c09a782u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a794; }
goto P_0c09a784;
P_0c09a784: /* original 50d2, guest PC 0x0c09a784 */
if(!s->budget--) { s->failed_pc=0x0c09a784u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c09a786;
P_0c09a786: /* original c804, guest PC 0x0c09a786 */
if(!s->budget--) { s->failed_pc=0x0c09a786u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c09a788;
P_0c09a788: /* original 8901, guest PC 0x0c09a788 */
if(!s->budget--) { s->failed_pc=0x0c09a788u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09a78e; }
goto P_0c09a78a;
P_0c09a78a: /* original a002, guest PC 0x0c09a78a */
if(!s->budget--) { s->failed_pc=0x0c09a78au; return 0; }
r[0]=0x00000012u;
goto P_0c09a792;
P_0c09a78c: /* original e012, guest PC 0x0c09a78c */
if(!s->budget--) { s->failed_pc=0x0c09a78cu; return 0; }
r[0]=0x00000012u;
goto P_0c09a78e;
P_0c09a78e: /* original 84ea, guest PC 0x0c09a78e */
if(!s->budget--) { s->failed_pc=0x0c09a78eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+10,1);
goto P_0c09a790;
P_0c09a790: /* original 7001, guest PC 0x0c09a790 */
if(!s->budget--) { s->failed_pc=0x0c09a790u; return 0; }
r[0]+=0x00000001u;
goto P_0c09a792;
P_0c09a792: /* original 80ea, guest PC 0x0c09a792 */
if(!s->budget--) { s->failed_pc=0x0c09a792u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09a794;
P_0c09a794: /* original 4f26, guest PC 0x0c09a794 */
if(!s->budget--) { s->failed_pc=0x0c09a794u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09a796;
P_0c09a796: /* original 6df6, guest PC 0x0c09a796 */
if(!s->budget--) { s->failed_pc=0x0c09a796u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09a798;
P_0c09a798: /* original 000b, guest PC 0x0c09a798 */
if(!s->budget--) { s->failed_pc=0x0c09a798u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09a79a: /* original 6ef6, guest PC 0x0c09a79a */
if(!s->budget--) { s->failed_pc=0x0c09a79au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09a79cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09a79cu; return 0; } return 1;
P_0c09aa04: /* original 2fe6, guest PC 0x0c09aa04 */
if(!s->budget--) { s->failed_pc=0x0c09aa04u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aa06;
P_0c09aa06: /* original e5ff, guest PC 0x0c09aa06 */
if(!s->budget--) { s->failed_pc=0x0c09aa06u; return 0; }
r[5]=0xffffffffu;
goto P_0c09aa08;
P_0c09aa08: /* original 2fd6, guest PC 0x0c09aa08 */
if(!s->budget--) { s->failed_pc=0x0c09aa08u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aa0a;
P_0c09aa0a: /* original 2fc6, guest PC 0x0c09aa0a */
if(!s->budget--) { s->failed_pc=0x0c09aa0au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aa0c;
P_0c09aa0c: /* original 2fb6, guest PC 0x0c09aa0c */
if(!s->budget--) { s->failed_pc=0x0c09aa0cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aa0e;
P_0c09aa0e: /* original eb00, guest PC 0x0c09aa0e */
if(!s->budget--) { s->failed_pc=0x0c09aa0eu; return 0; }
r[11]=0x00000000u;
goto P_0c09aa10;
P_0c09aa10: /* original 2fa6, guest PC 0x0c09aa10 */
if(!s->budget--) { s->failed_pc=0x0c09aa10u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aa12;
P_0c09aa12: /* original 2f96, guest PC 0x0c09aa12 */
if(!s->budget--) { s->failed_pc=0x0c09aa12u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09aa14;
P_0c09aa14: /* original 4f22, guest PC 0x0c09aa14 */
if(!s->budget--) { s->failed_pc=0x0c09aa14u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09aa16;
P_0c09aa16: /* original d35d, guest PC 0x0c09aa16 */
if(!s->budget--) { s->failed_pc=0x0c09aa16u; return 0; }
r[3]=read(ram,0x0c09ab8cu,4);
goto P_0c09aa18;
P_0c09aa18: /* original dc5b, guest PC 0x0c09aa18 */
if(!s->budget--) { s->failed_pc=0x0c09aa18u; return 0; }
r[12]=read(ram,0x0c09ab88u,4);
goto P_0c09aa1a;
P_0c09aa1a: /* original 7ffc, guest PC 0x0c09aa1a */
if(!s->budget--) { s->failed_pc=0x0c09aa1au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09aa1c;
P_0c09aa1c: /* original 6433, guest PC 0x0c09aa1c */
if(!s->budget--) { s->failed_pc=0x0c09aa1cu; return 0; }
r[4]=r[3];
goto P_0c09aa1e;
P_0c09aa1e: /* original d958, guest PC 0x0c09aa1e */
if(!s->budget--) { s->failed_pc=0x0c09aa1eu; return 0; }
r[9]=read(ram,0x0c09ab80u,4);
goto P_0c09aa20;
P_0c09aa20: /* original da58, guest PC 0x0c09aa20 */
if(!s->budget--) { s->failed_pc=0x0c09aa20u; return 0; }
r[10]=read(ram,0x0c09ab84u,4);
goto P_0c09aa22;
P_0c09aa22: /* original 2f32, guest PC 0x0c09aa22 */
if(!s->budget--) { s->failed_pc=0x0c09aa22u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09aa24;
P_0c09aa24: /* original d35a, guest PC 0x0c09aa24 */
if(!s->budget--) { s->failed_pc=0x0c09aa24u; return 0; }
r[3]=read(ram,0x0c09ab90u,4);
goto P_0c09aa26;
P_0c09aa26: /* original 430b, guest PC 0x0c09aa26 */
if(!s->budget--) { s->failed_pc=0x0c09aa26u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa2au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa2au) { target=s->pc; goto dispatch; }
goto P_0c09aa2a;
P_0c09aa28: /* original 7430, guest PC 0x0c09aa28 */
if(!s->budget--) { s->failed_pc=0x0c09aa28u; return 0; }
r[4]+=0x00000030u;
goto P_0c09aa2a;
P_0c09aa2a: /* original d25b, guest PC 0x0c09aa2a */
if(!s->budget--) { s->failed_pc=0x0c09aa2au; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa2c;
P_0c09aa2c: /* original de59, guest PC 0x0c09aa2c */
if(!s->budget--) { s->failed_pc=0x0c09aa2cu; return 0; }
r[14]=read(ram,0x0c09ab94u,4);
goto P_0c09aa2e;
P_0c09aa2e: /* original 420b, guest PC 0x0c09aa2e */
if(!s->budget--) { s->failed_pc=0x0c09aa2eu; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa32u;
r[4]=read(ram,r[14]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa32u) { target=s->pc; goto dispatch; }
goto P_0c09aa32;
P_0c09aa30: /* original 54e6, guest PC 0x0c09aa30 */
if(!s->budget--) { s->failed_pc=0x0c09aa30u; return 0; }
r[4]=read(ram,r[14]+24,4);
goto P_0c09aa32;
P_0c09aa32: /* original d359, guest PC 0x0c09aa32 */
if(!s->budget--) { s->failed_pc=0x0c09aa32u; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa34;
P_0c09aa34: /* original 430b, guest PC 0x0c09aa34 */
if(!s->budget--) { s->failed_pc=0x0c09aa34u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa38u;
r[4]=read(ram,r[14]+28,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa38u) { target=s->pc; goto dispatch; }
goto P_0c09aa38;
P_0c09aa36: /* original 54e7, guest PC 0x0c09aa36 */
if(!s->budget--) { s->failed_pc=0x0c09aa36u; return 0; }
r[4]=read(ram,r[14]+28,4);
goto P_0c09aa38;
P_0c09aa38: /* original d257, guest PC 0x0c09aa38 */
if(!s->budget--) { s->failed_pc=0x0c09aa38u; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa3a;
P_0c09aa3a: /* original 420b, guest PC 0x0c09aa3a */
if(!s->budget--) { s->failed_pc=0x0c09aa3au; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa3eu;
r[4]=read(ram,r[14]+60,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa3eu) { target=s->pc; goto dispatch; }
goto P_0c09aa3e;
P_0c09aa3c: /* original 54ef, guest PC 0x0c09aa3c */
if(!s->budget--) { s->failed_pc=0x0c09aa3cu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c09aa3e;
P_0c09aa3e: /* original d356, guest PC 0x0c09aa3e */
if(!s->budget--) { s->failed_pc=0x0c09aa3eu; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa40;
P_0c09aa40: /* original e040, guest PC 0x0c09aa40 */
if(!s->budget--) { s->failed_pc=0x0c09aa40u; return 0; }
r[0]=0x00000040u;
goto P_0c09aa42;
P_0c09aa42: /* original 430b, guest PC 0x0c09aa42 */
if(!s->budget--) { s->failed_pc=0x0c09aa42u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa46u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa46u) { target=s->pc; goto dispatch; }
goto P_0c09aa46;
P_0c09aa44: /* original 04ee, guest PC 0x0c09aa44 */
if(!s->budget--) { s->failed_pc=0x0c09aa44u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aa46;
P_0c09aa46: /* original d254, guest PC 0x0c09aa46 */
if(!s->budget--) { s->failed_pc=0x0c09aa46u; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa48;
P_0c09aa48: /* original 420b, guest PC 0x0c09aa48 */
if(!s->budget--) { s->failed_pc=0x0c09aa48u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa4cu;
r[4]=read(ram,r[14]+52,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa4cu) { target=s->pc; goto dispatch; }
goto P_0c09aa4c;
P_0c09aa4a: /* original 54ed, guest PC 0x0c09aa4a */
if(!s->budget--) { s->failed_pc=0x0c09aa4au; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c09aa4c;
P_0c09aa4c: /* original d352, guest PC 0x0c09aa4c */
if(!s->budget--) { s->failed_pc=0x0c09aa4cu; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa4e;
P_0c09aa4e: /* original 430b, guest PC 0x0c09aa4e */
if(!s->budget--) { s->failed_pc=0x0c09aa4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa52u;
r[4]=read(ram,r[14]+56,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa52u) { target=s->pc; goto dispatch; }
goto P_0c09aa52;
P_0c09aa50: /* original 54ee, guest PC 0x0c09aa50 */
if(!s->budget--) { s->failed_pc=0x0c09aa50u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c09aa52;
P_0c09aa52: /* original d251, guest PC 0x0c09aa52 */
if(!s->budget--) { s->failed_pc=0x0c09aa52u; return 0; }
r[2]=read(ram,0x0c09ab98u,4);
goto P_0c09aa54;
P_0c09aa54: /* original 420b, guest PC 0x0c09aa54 */
if(!s->budget--) { s->failed_pc=0x0c09aa54u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa58u;
r[4]=read(ram,r[14]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa58u) { target=s->pc; goto dispatch; }
goto P_0c09aa58;
P_0c09aa56: /* original 54ea, guest PC 0x0c09aa56 */
if(!s->budget--) { s->failed_pc=0x0c09aa56u; return 0; }
r[4]=read(ram,r[14]+40,4);
goto P_0c09aa58;
P_0c09aa58: /* original d34f, guest PC 0x0c09aa58 */
if(!s->budget--) { s->failed_pc=0x0c09aa58u; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa5a;
P_0c09aa5a: /* original 430b, guest PC 0x0c09aa5a */
if(!s->budget--) { s->failed_pc=0x0c09aa5au; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa5eu;
r[4]=read(ram,r[14]+44,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa5eu) { target=s->pc; goto dispatch; }
goto P_0c09aa5e;
P_0c09aa5c: /* original 54eb, guest PC 0x0c09aa5c */
if(!s->budget--) { s->failed_pc=0x0c09aa5cu; return 0; }
r[4]=read(ram,r[14]+44,4);
goto P_0c09aa5e;
P_0c09aa5e: /* original d34e, guest PC 0x0c09aa5e */
if(!s->budget--) { s->failed_pc=0x0c09aa5eu; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa60;
P_0c09aa60: /* original e050, guest PC 0x0c09aa60 */
if(!s->budget--) { s->failed_pc=0x0c09aa60u; return 0; }
r[0]=0x00000050u;
goto P_0c09aa62;
P_0c09aa62: /* original 430b, guest PC 0x0c09aa62 */
if(!s->budget--) { s->failed_pc=0x0c09aa62u; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa66u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa66u) { target=s->pc; goto dispatch; }
goto P_0c09aa66;
P_0c09aa64: /* original 04ee, guest PC 0x0c09aa64 */
if(!s->budget--) { s->failed_pc=0x0c09aa64u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aa66;
P_0c09aa66: /* original d34c, guest PC 0x0c09aa66 */
if(!s->budget--) { s->failed_pc=0x0c09aa66u; return 0; }
r[3]=read(ram,0x0c09ab98u,4);
goto P_0c09aa68;
P_0c09aa68: /* original e054, guest PC 0x0c09aa68 */
if(!s->budget--) { s->failed_pc=0x0c09aa68u; return 0; }
r[0]=0x00000054u;
goto P_0c09aa6a;
P_0c09aa6a: /* original 430b, guest PC 0x0c09aa6a */
if(!s->budget--) { s->failed_pc=0x0c09aa6au; return 0; }
target=r[3];
r[16]=code_base|0x0c09aa6eu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa6eu) { target=s->pc; goto dispatch; }
goto P_0c09aa6e;
P_0c09aa6c: /* original 04ee, guest PC 0x0c09aa6c */
if(!s->budget--) { s->failed_pc=0x0c09aa6cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09aa6e;
P_0c09aa6e: /* original c74b, guest PC 0x0c09aa6e */
if(!s->budget--) { s->failed_pc=0x0c09aa6eu; return 0; }
r[0]=code_base|0x0009ab9cu;
goto P_0c09aa70;
P_0c09aa70: /* original f308, guest PC 0x0c09aa70 */
if(!s->budget--) { s->failed_pc=0x0c09aa70u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09aa72;
P_0c09aa72: /* original e102, guest PC 0x0c09aa72 */
if(!s->budget--) { s->failed_pc=0x0c09aa72u; return 0; }
r[1]=0x00000002u;
goto P_0c09aa74;
P_0c09aa74: /* original f93a, guest PC 0x0c09aa74 */
if(!s->budget--) { s->failed_pc=0x0c09aa74u; return 0; }
vf3_matrix_store(s,ram,3,r[9]);
goto P_0c09aa76;
P_0c09aa76: /* original 9375, guest PC 0x0c09aa76 */
if(!s->budget--) { s->failed_pc=0x0c09aa76u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab64u,2);
goto P_0c09aa78;
P_0c09aa78: /* original 5292, guest PC 0x0c09aa78 */
if(!s->budget--) { s->failed_pc=0x0c09aa78u; return 0; }
r[2]=read(ram,r[9]+8,4);
goto P_0c09aa7a;
P_0c09aa7a: /* original 2239, guest PC 0x0c09aa7a */
if(!s->budget--) { s->failed_pc=0x0c09aa7au; return 0; }
r[2]&=r[3];
goto P_0c09aa7c;
P_0c09aa7c: /* original 1922, guest PC 0x0c09aa7c */
if(!s->budget--) { s->failed_pc=0x0c09aa7cu; return 0; }
write(ram,r[9]+8,r[2],4);
goto P_0c09aa7e;
P_0c09aa7e: /* original 5de8, guest PC 0x0c09aa7e */
if(!s->budget--) { s->failed_pc=0x0c09aa7eu; return 0; }
r[13]=read(ram,r[14]+32,4);
goto P_0c09aa80;
P_0c09aa80: /* original 9071, guest PC 0x0c09aa80 */
if(!s->budget--) { s->failed_pc=0x0c09aa80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab66u,2);
goto P_0c09aa82;
P_0c09aa82: /* original 0d14, guest PC 0x0c09aa82 */
if(!s->budget--) { s->failed_pc=0x0c09aa82u; return 0; }
write(ram,r[13]+r[0],r[1],1);
goto P_0c09aa84;
P_0c09aa84: /* original 7017, guest PC 0x0c09aa84 */
if(!s->budget--) { s->failed_pc=0x0c09aa84u; return 0; }
r[0]+=0x00000017u;
goto P_0c09aa86;
P_0c09aa86: /* original d246, guest PC 0x0c09aa86 */
if(!s->budget--) { s->failed_pc=0x0c09aa86u; return 0; }
r[2]=read(ram,0x0c09aba0u,4);
goto P_0c09aa88;
P_0c09aa88: /* original 420b, guest PC 0x0c09aa88 */
if(!s->budget--) { s->failed_pc=0x0c09aa88u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aa8cu;
write(ram,r[13]+r[0],r[11],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aa8cu) { target=s->pc; goto dispatch; }
goto P_0c09aa8c;
P_0c09aa8a: /* original 0db4, guest PC 0x0c09aa8a */
if(!s->budget--) { s->failed_pc=0x0c09aa8au; return 0; }
write(ram,r[13]+r[0],r[11],1);
goto P_0c09aa8c;
P_0c09aa8c: /* original 906c, guest PC 0x0c09aa8c */
if(!s->budget--) { s->failed_pc=0x0c09aa8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab68u,2);
goto P_0c09aa8e;
P_0c09aa8e: /* original 63b3, guest PC 0x0c09aa8e */
if(!s->budget--) { s->failed_pc=0x0c09aa8eu; return 0; }
r[3]=r[11];
goto P_0c09aa90;
P_0c09aa90: /* original 0cb6, guest PC 0x0c09aa90 */
if(!s->budget--) { s->failed_pc=0x0c09aa90u; return 0; }
write(ram,r[12]+r[0],r[11],4);
goto P_0c09aa92;
P_0c09aa92: /* original 70fc, guest PC 0x0c09aa92 */
if(!s->budget--) { s->failed_pc=0x0c09aa92u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09aa94;
P_0c09aa94: /* original 0c36, guest PC 0x0c09aa94 */
if(!s->budget--) { s->failed_pc=0x0c09aa94u; return 0; }
write(ram,r[12]+r[0],r[3],4);
goto P_0c09aa96;
P_0c09aa96: /* original 9068, guest PC 0x0c09aa96 */
if(!s->budget--) { s->failed_pc=0x0c09aa96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab6au,2);
goto P_0c09aa98;
P_0c09aa98: /* original 0a34, guest PC 0x0c09aa98 */
if(!s->budget--) { s->failed_pc=0x0c09aa98u; return 0; }
write(ram,r[10]+r[0],r[3],1);
goto P_0c09aa9a;
P_0c09aa9a: /* original d342, guest PC 0x0c09aa9a */
if(!s->budget--) { s->failed_pc=0x0c09aa9au; return 0; }
r[3]=read(ram,0x0c09aba4u,4);
goto P_0c09aa9c;
P_0c09aa9c: /* original 430b, guest PC 0x0c09aa9c */
if(!s->budget--) { s->failed_pc=0x0c09aa9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09aaa0u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aaa0u) { target=s->pc; goto dispatch; }
goto P_0c09aaa0;
P_0c09aa9e: /* original 64c3, guest PC 0x0c09aa9e */
if(!s->budget--) { s->failed_pc=0x0c09aa9eu; return 0; }
r[4]=r[12];
goto P_0c09aaa0;
P_0c09aaa0: /* original d240, guest PC 0x0c09aaa0 */
if(!s->budget--) { s->failed_pc=0x0c09aaa0u; return 0; }
r[2]=read(ram,0x0c09aba4u,4);
goto P_0c09aaa2;
P_0c09aaa2: /* original 64c3, guest PC 0x0c09aaa2 */
if(!s->budget--) { s->failed_pc=0x0c09aaa2u; return 0; }
r[4]=r[12];
goto P_0c09aaa4;
P_0c09aaa4: /* original 420b, guest PC 0x0c09aaa4 */
if(!s->budget--) { s->failed_pc=0x0c09aaa4u; return 0; }
target=r[2];
r[16]=code_base|0x0c09aaa8u;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aaa8u) { target=s->pc; goto dispatch; }
goto P_0c09aaa8;
P_0c09aaa6: /* original 742c, guest PC 0x0c09aaa6 */
if(!s->budget--) { s->failed_pc=0x0c09aaa6u; return 0; }
r[4]+=0x0000002cu;
goto P_0c09aaa8;
P_0c09aaa8: /* original 9060, guest PC 0x0c09aaa8 */
if(!s->budget--) { s->failed_pc=0x0c09aaa8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab6cu,2);
goto P_0c09aaaa;
P_0c09aaaa: /* original e40f, guest PC 0x0c09aaaa */
if(!s->budget--) { s->failed_pc=0x0c09aaaau; return 0; }
r[4]=0x0000000fu;
goto P_0c09aaac;
P_0c09aaac: /* original f38d, guest PC 0x0c09aaac */
if(!s->budget--) { s->failed_pc=0x0c09aaacu; return 0; }
fr[3]=0;
goto P_0c09aaae;
P_0c09aaae: /* original fd37, guest PC 0x0c09aaae */
if(!s->budget--) { s->failed_pc=0x0c09aaaeu; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aab0;
P_0c09aab0: /* original 709f, guest PC 0x0c09aab0 */
if(!s->budget--) { s->failed_pc=0x0c09aab0u; return 0; }
r[0]+=0xffffff9fu;
goto P_0c09aab2;
P_0c09aab2: /* original 0db4, guest PC 0x0c09aab2 */
if(!s->budget--) { s->failed_pc=0x0c09aab2u; return 0; }
write(ram,r[13]+r[0],r[11],1);
goto P_0c09aab4;
P_0c09aab4: /* original 60d2, guest PC 0x0c09aab4 */
if(!s->budget--) { s->failed_pc=0x0c09aab4u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c09aab6;
P_0c09aab6: /* original c901, guest PC 0x0c09aab6 */
if(!s->budget--) { s->failed_pc=0x0c09aab6u; return 0; }
r[0]&=1u;
goto P_0c09aab8;
P_0c09aab8: /* original 2d02, guest PC 0x0c09aab8 */
if(!s->budget--) { s->failed_pc=0x0c09aab8u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c09aaba;
P_0c09aaba: /* original e01c, guest PC 0x0c09aaba */
if(!s->budget--) { s->failed_pc=0x0c09aabau; return 0; }
r[0]=0x0000001cu;
goto P_0c09aabc;
P_0c09aabc: /* original 00ac, guest PC 0x0c09aabc */
if(!s->budget--) { s->failed_pc=0x0c09aabcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c09aabe;
P_0c09aabe: /* original d33a, guest PC 0x0c09aabe */
if(!s->budget--) { s->failed_pc=0x0c09aabeu; return 0; }
r[3]=read(ram,0x0c09aba8u,4);
goto P_0c09aac0;
P_0c09aac0: /* original 600c, guest PC 0x0c09aac0 */
if(!s->budget--) { s->failed_pc=0x0c09aac0u; return 0; }
r[0]=r[0]&255u;
goto P_0c09aac2;
P_0c09aac2: /* original 9154, guest PC 0x0c09aac2 */
if(!s->budget--) { s->failed_pc=0x0c09aac2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab6eu,2);
goto P_0c09aac4;
P_0c09aac4: /* original 2409, guest PC 0x0c09aac4 */
if(!s->budget--) { s->failed_pc=0x0c09aac4u; return 0; }
r[4]&=r[0];
goto P_0c09aac6;
P_0c09aac6: /* original 4408, guest PC 0x0c09aac6 */
if(!s->budget--) { s->failed_pc=0x0c09aac6u; return 0; }
r[4]<<=2;
goto P_0c09aac8;
P_0c09aac8: /* original 4408, guest PC 0x0c09aac8 */
if(!s->budget--) { s->failed_pc=0x0c09aac8u; return 0; }
r[4]<<=2;
goto P_0c09aaca;
P_0c09aaca: /* original 4408, guest PC 0x0c09aaca */
if(!s->budget--) { s->failed_pc=0x0c09aacau; return 0; }
r[4]<<=2;
goto P_0c09aacc;
P_0c09aacc: /* original 343c, guest PC 0x0c09aacc */
if(!s->budget--) { s->failed_pc=0x0c09aaccu; return 0; }
r[4]+=r[3];
goto P_0c09aace;
P_0c09aace: /* original 8445, guest PC 0x0c09aace */
if(!s->budget--) { s->failed_pc=0x0c09aaceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c09aad0;
P_0c09aad0: /* original 31dc, guest PC 0x0c09aad0 */
if(!s->budget--) { s->failed_pc=0x0c09aad0u; return 0; }
r[1]+=r[13];
goto P_0c09aad2;
P_0c09aad2: /* original 2100, guest PC 0x0c09aad2 */
if(!s->budget--) { s->failed_pc=0x0c09aad2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09aad4;
P_0c09aad4: /* original 924c, guest PC 0x0c09aad4 */
if(!s->budget--) { s->failed_pc=0x0c09aad4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab70u,2);
goto P_0c09aad6;
P_0c09aad6: /* original 8446, guest PC 0x0c09aad6 */
if(!s->budget--) { s->failed_pc=0x0c09aad6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c09aad8;
P_0c09aad8: /* original 32dc, guest PC 0x0c09aad8 */
if(!s->budget--) { s->failed_pc=0x0c09aad8u; return 0; }
r[2]+=r[13];
goto P_0c09aada;
P_0c09aada: /* original 2200, guest PC 0x0c09aada */
if(!s->budget--) { s->failed_pc=0x0c09aadau; return 0; }
write(ram,r[2],r[0],1);
goto P_0c09aadc;
P_0c09aadc: /* original 9149, guest PC 0x0c09aadc */
if(!s->budget--) { s->failed_pc=0x0c09aadcu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab72u,2);
goto P_0c09aade;
P_0c09aade: /* original 8447, guest PC 0x0c09aade */
if(!s->budget--) { s->failed_pc=0x0c09aadeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+7,1);
goto P_0c09aae0;
P_0c09aae0: /* original 31dc, guest PC 0x0c09aae0 */
if(!s->budget--) { s->failed_pc=0x0c09aae0u; return 0; }
r[1]+=r[13];
goto P_0c09aae2;
P_0c09aae2: /* original 2100, guest PC 0x0c09aae2 */
if(!s->budget--) { s->failed_pc=0x0c09aae2u; return 0; }
write(ram,r[1],r[0],1);
goto P_0c09aae4;
P_0c09aae4: /* original e01c, guest PC 0x0c09aae4 */
if(!s->budget--) { s->failed_pc=0x0c09aae4u; return 0; }
r[0]=0x0000001cu;
goto P_0c09aae6;
P_0c09aae6: /* original f346, guest PC 0x0c09aae6 */
if(!s->budget--) { s->failed_pc=0x0c09aae6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09aae8;
P_0c09aae8: /* original 9044, guest PC 0x0c09aae8 */
if(!s->budget--) { s->failed_pc=0x0c09aae8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab74u,2);
goto P_0c09aaea;
P_0c09aaea: /* original fd37, guest PC 0x0c09aaea */
if(!s->budget--) { s->failed_pc=0x0c09aaeau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aaec;
P_0c09aaec: /* original e020, guest PC 0x0c09aaec */
if(!s->budget--) { s->failed_pc=0x0c09aaecu; return 0; }
r[0]=0x00000020u;
goto P_0c09aaee;
P_0c09aaee: /* original f346, guest PC 0x0c09aaee */
if(!s->budget--) { s->failed_pc=0x0c09aaeeu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09aaf0;
P_0c09aaf0: /* original 9041, guest PC 0x0c09aaf0 */
if(!s->budget--) { s->failed_pc=0x0c09aaf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab76u,2);
goto P_0c09aaf2;
P_0c09aaf2: /* original fd37, guest PC 0x0c09aaf2 */
if(!s->budget--) { s->failed_pc=0x0c09aaf2u; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aaf4;
P_0c09aaf4: /* original e024, guest PC 0x0c09aaf4 */
if(!s->budget--) { s->failed_pc=0x0c09aaf4u; return 0; }
r[0]=0x00000024u;
goto P_0c09aaf6;
P_0c09aaf6: /* original f346, guest PC 0x0c09aaf6 */
if(!s->budget--) { s->failed_pc=0x0c09aaf6u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09aaf8;
P_0c09aaf8: /* original 903e, guest PC 0x0c09aaf8 */
if(!s->budget--) { s->failed_pc=0x0c09aaf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab78u,2);
goto P_0c09aafa;
P_0c09aafa: /* original fd37, guest PC 0x0c09aafa */
if(!s->budget--) { s->failed_pc=0x0c09aafau; return 0; }
vf3_matrix_store(s,ram,3,r[13]+r[0]);
goto P_0c09aafc;
P_0c09aafc: /* original 963d, guest PC 0x0c09aafc */
if(!s->budget--) { s->failed_pc=0x0c09aafcu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab7au,2);
goto P_0c09aafe;
P_0c09aafe: /* original 943d, guest PC 0x0c09aafe */
if(!s->budget--) { s->failed_pc=0x0c09aafeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09ab7cu,2);
goto P_0c09ab00;
P_0c09ab00: /* original d22a, guest PC 0x0c09ab00 */
if(!s->budget--) { s->failed_pc=0x0c09ab00u; return 0; }
r[2]=read(ram,0x0c09abacu,4);
goto P_0c09ab02;
P_0c09ab02: /* original 36cc, guest PC 0x0c09ab02 */
if(!s->budget--) { s->failed_pc=0x0c09ab02u; return 0; }
r[6]+=r[12];
goto P_0c09ab04;
P_0c09ab04: /* original 420b, guest PC 0x0c09ab04 */
if(!s->budget--) { s->failed_pc=0x0c09ab04u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ab08u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ab08u) { target=s->pc; goto dispatch; }
goto P_0c09ab08;
P_0c09ab06: /* original 65c3, guest PC 0x0c09ab06 */
if(!s->budget--) { s->failed_pc=0x0c09ab06u; return 0; }
r[5]=r[12];
goto P_0c09ab08;
P_0c09ab08: /* original d329, guest PC 0x0c09ab08 */
if(!s->budget--) { s->failed_pc=0x0c09ab08u; return 0; }
r[3]=read(ram,0x0c09abb0u,4);
goto P_0c09ab0a;
P_0c09ab0a: /* original 430b, guest PC 0x0c09ab0a */
if(!s->budget--) { s->failed_pc=0x0c09ab0au; return 0; }
target=r[3];
r[16]=code_base|0x0c09ab0eu;
r[4]=read(ram,r[14]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ab0eu) { target=s->pc; goto dispatch; }
goto P_0c09ab0e;
P_0c09ab0c: /* original 54e4, guest PC 0x0c09ab0c */
if(!s->budget--) { s->failed_pc=0x0c09ab0cu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c09ab0e;
P_0c09ab0e: /* original d228, guest PC 0x0c09ab0e */
if(!s->budget--) { s->failed_pc=0x0c09ab0eu; return 0; }
r[2]=read(ram,0x0c09abb0u,4);
goto P_0c09ab10;
P_0c09ab10: /* original 420b, guest PC 0x0c09ab10 */
if(!s->budget--) { s->failed_pc=0x0c09ab10u; return 0; }
target=r[2];
r[16]=code_base|0x0c09ab14u;
r[4]=read(ram,r[14]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ab14u) { target=s->pc; goto dispatch; }
goto P_0c09ab14;
P_0c09ab12: /* original 54e5, guest PC 0x0c09ab12 */
if(!s->budget--) { s->failed_pc=0x0c09ab12u; return 0; }
r[4]=read(ram,r[14]+20,4);
goto P_0c09ab14;
P_0c09ab14: /* original d328, guest PC 0x0c09ab14 */
if(!s->budget--) { s->failed_pc=0x0c09ab14u; return 0; }
r[3]=read(ram,0x0c09abb8u,4);
goto P_0c09ab16;
P_0c09ab16: /* original d427, guest PC 0x0c09ab16 */
if(!s->budget--) { s->failed_pc=0x0c09ab16u; return 0; }
r[4]=read(ram,0x0c09abb4u,4);
goto P_0c09ab18;
P_0c09ab18: /* original 430b, guest PC 0x0c09ab18 */
if(!s->budget--) { s->failed_pc=0x0c09ab18u; return 0; }
target=r[3];
r[16]=code_base|0x0c09ab1cu;
r[5]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09ab1cu) { target=s->pc; goto dispatch; }
goto P_0c09ab1c;
P_0c09ab1a: /* original e500, guest PC 0x0c09ab1a */
if(!s->budget--) { s->failed_pc=0x0c09ab1au; return 0; }
r[5]=0x00000000u;
goto P_0c09ab1c;
P_0c09ab1c: /* original 60b3, guest PC 0x0c09ab1c */
if(!s->budget--) { s->failed_pc=0x0c09ab1cu; return 0; }
r[0]=r[11];
goto P_0c09ab1e;
P_0c09ab1e: /* original 80ab, guest PC 0x0c09ab1e */
if(!s->budget--) { s->failed_pc=0x0c09ab1eu; return 0; }
write(ram,r[10]+11,r[0],1);
goto P_0c09ab20;
P_0c09ab20: /* original e043, guest PC 0x0c09ab20 */
if(!s->budget--) { s->failed_pc=0x0c09ab20u; return 0; }
r[0]=0x00000043u;
goto P_0c09ab22;
P_0c09ab22: /* original e30f, guest PC 0x0c09ab22 */
if(!s->budget--) { s->failed_pc=0x0c09ab22u; return 0; }
r[3]=0x0000000fu;
goto P_0c09ab24;
P_0c09ab24: /* original 0934, guest PC 0x0c09ab24 */
if(!s->budget--) { s->failed_pc=0x0c09ab24u; return 0; }
write(ram,r[9]+r[0],r[3],1);
goto P_0c09ab26;
P_0c09ab26: /* original 7f04, guest PC 0x0c09ab26 */
if(!s->budget--) { s->failed_pc=0x0c09ab26u; return 0; }
r[15]+=0x00000004u;
goto P_0c09ab28;
P_0c09ab28: /* original e044, guest PC 0x0c09ab28 */
if(!s->budget--) { s->failed_pc=0x0c09ab28u; return 0; }
r[0]=0x00000044u;
goto P_0c09ab2a;
P_0c09ab2a: /* original 4f26, guest PC 0x0c09ab2a */
if(!s->budget--) { s->failed_pc=0x0c09ab2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09ab2c;
P_0c09ab2c: /* original 09b6, guest PC 0x0c09ab2c */
if(!s->budget--) { s->failed_pc=0x0c09ab2cu; return 0; }
write(ram,r[9]+r[0],r[11],4);
goto P_0c09ab2e;
P_0c09ab2e: /* original 84aa, guest PC 0x0c09ab2e */
if(!s->budget--) { s->failed_pc=0x0c09ab2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+10,1);
goto P_0c09ab30;
P_0c09ab30: /* original 7001, guest PC 0x0c09ab30 */
if(!s->budget--) { s->failed_pc=0x0c09ab30u; return 0; }
r[0]+=0x00000001u;
goto P_0c09ab32;
P_0c09ab32: /* original 80aa, guest PC 0x0c09ab32 */
if(!s->budget--) { s->failed_pc=0x0c09ab32u; return 0; }
write(ram,r[10]+10,r[0],1);
goto P_0c09ab34;
P_0c09ab34: /* original 69f6, guest PC 0x0c09ab34 */
if(!s->budget--) { s->failed_pc=0x0c09ab34u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09ab36;
P_0c09ab36: /* original 6af6, guest PC 0x0c09ab36 */
if(!s->budget--) { s->failed_pc=0x0c09ab36u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09ab38;
P_0c09ab38: /* original 6bf6, guest PC 0x0c09ab38 */
if(!s->budget--) { s->failed_pc=0x0c09ab38u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09ab3a;
P_0c09ab3a: /* original 6cf6, guest PC 0x0c09ab3a */
if(!s->budget--) { s->failed_pc=0x0c09ab3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09ab3c;
P_0c09ab3c: /* original 6df6, guest PC 0x0c09ab3c */
if(!s->budget--) { s->failed_pc=0x0c09ab3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09ab3e;
P_0c09ab3e: /* original a000, guest PC 0x0c09ab3e */
if(!s->budget--) { s->failed_pc=0x0c09ab3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09ab42;
P_0c09ab40: /* original 6ef6, guest PC 0x0c09ab40 */
if(!s->budget--) { s->failed_pc=0x0c09ab40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09ab42;
P_0c09ab42: /* original d410, guest PC 0x0c09ab42 */
if(!s->budget--) { s->failed_pc=0x0c09ab42u; return 0; }
r[4]=read(ram,0x0c09ab84u,4);
goto P_0c09ab44;
P_0c09ab44: /* original 7ffc, guest PC 0x0c09ab44 */
if(!s->budget--) { s->failed_pc=0x0c09ab44u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09ab46;
P_0c09ab46: /* original 844b, guest PC 0x0c09ab46 */
if(!s->budget--) { s->failed_pc=0x0c09ab46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+11,1);
goto P_0c09ab48;
P_0c09ab48: /* original 650c, guest PC 0x0c09ab48 */
if(!s->budget--) { s->failed_pc=0x0c09ab48u; return 0; }
r[5]=r[0]&255u;
goto P_0c09ab4a;
P_0c09ab4a: /* original 6053, guest PC 0x0c09ab4a */
if(!s->budget--) { s->failed_pc=0x0c09ab4au; return 0; }
r[0]=r[5];
goto P_0c09ab4c;
P_0c09ab4c: /* original 8049, guest PC 0x0c09ab4c */
if(!s->budget--) { s->failed_pc=0x0c09ab4cu; return 0; }
write(ram,r[4]+9,r[0],1);
goto P_0c09ab4e;
P_0c09ab4e: /* original d21b, guest PC 0x0c09ab4e */
if(!s->budget--) { s->failed_pc=0x0c09ab4eu; return 0; }
r[2]=read(ram,0x0c09abbcu,4);
goto P_0c09ab50;
P_0c09ab50: /* original 635b, guest PC 0x0c09ab50 */
if(!s->budget--) { s->failed_pc=0x0c09ab50u; return 0; }
r[3]=0u-r[5];
goto P_0c09ab52;
P_0c09ab52: /* original 4508, guest PC 0x0c09ab52 */
if(!s->budget--) { s->failed_pc=0x0c09ab52u; return 0; }
r[5]<<=2;
goto P_0c09ab54;
P_0c09ab54: /* original 423d, guest PC 0x0c09ab54 */
if(!s->budget--) { s->failed_pc=0x0c09ab54u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?r[2]>>((-r[3])&31u):0):r[2]<<(r[3]&31u);
goto P_0c09ab56;
P_0c09ab56: /* original 1421, guest PC 0x0c09ab56 */
if(!s->budget--) { s->failed_pc=0x0c09ab56u; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c09ab58;
P_0c09ab58: /* original d019, guest PC 0x0c09ab58 */
if(!s->budget--) { s->failed_pc=0x0c09ab58u; return 0; }
r[0]=read(ram,0x0c09abc0u,4);
goto P_0c09ab5a;
P_0c09ab5a: /* original 035e, guest PC 0x0c09ab5a */
if(!s->budget--) { s->failed_pc=0x0c09ab5au; return 0; }
r[3]=read(ram,r[5]+r[0],4);
goto P_0c09ab5c;
P_0c09ab5c: /* original 6233, guest PC 0x0c09ab5c */
if(!s->budget--) { s->failed_pc=0x0c09ab5cu; return 0; }
r[2]=r[3];
goto P_0c09ab5e;
P_0c09ab5e: /* original 2f32, guest PC 0x0c09ab5e */
if(!s->budget--) { s->failed_pc=0x0c09ab5eu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09ab60;
P_0c09ab60: /* original 422b, guest PC 0x0c09ab60 */
if(!s->budget--) { s->failed_pc=0x0c09ab60u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c09ab62: /* original 7f04, guest PC 0x0c09ab62 */
if(!s->budget--) { s->failed_pc=0x0c09ab62u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c09ab64u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09ab64u; return 0; } return 1;
P_0c09efce: /* original 933f, guest PC 0x0c09efce */
if(!s->budget--) { s->failed_pc=0x0c09efceu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09f050u,2);
goto P_0c09efd0;
P_0c09efd0: /* original e042, guest PC 0x0c09efd0 */
if(!s->budget--) { s->failed_pc=0x0c09efd0u; return 0; }
r[0]=0x00000042u;
goto P_0c09efd2;
P_0c09efd2: /* original 0435, guest PC 0x0c09efd2 */
if(!s->budget--) { s->failed_pc=0x0c09efd2u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efd4;
P_0c09efd4: /* original a000, guest PC 0x0c09efd4 */
if(!s->budget--) { s->failed_pc=0x0c09efd4u; return 0; }
goto P_0c09efd8;
P_0c09efd6: /* original 0009, guest PC 0x0c09efd6 */
if(!s->budget--) { s->failed_pc=0x0c09efd6u; return 0; }
goto P_0c09efd8;
P_0c09efd8: /* original e03e, guest PC 0x0c09efd8 */
if(!s->budget--) { s->failed_pc=0x0c09efd8u; return 0; }
r[0]=0x0000003eu;
goto P_0c09efda;
P_0c09efda: /* original e301, guest PC 0x0c09efda */
if(!s->budget--) { s->failed_pc=0x0c09efdau; return 0; }
r[3]=0x00000001u;
goto P_0c09efdc;
P_0c09efdc: /* original 0435, guest PC 0x0c09efdc */
if(!s->budget--) { s->failed_pc=0x0c09efdcu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c09efde;
P_0c09efde: /* original e040, guest PC 0x0c09efde */
if(!s->budget--) { s->failed_pc=0x0c09efdeu; return 0; }
r[0]=0x00000040u;
goto P_0c09efe0;
P_0c09efe0: /* original e200, guest PC 0x0c09efe0 */
if(!s->budget--) { s->failed_pc=0x0c09efe0u; return 0; }
r[2]=0x00000000u;
goto P_0c09efe2;
P_0c09efe2: /* original 000b, guest PC 0x0c09efe2 */
if(!s->budget--) { s->failed_pc=0x0c09efe2u; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[2],2);
s->pc=target; return ram->oob==0;
P_0c09efe4: /* original 0425, guest PC 0x0c09efe4 */
if(!s->budget--) { s->failed_pc=0x0c09efe4u; return 0; }
write(ram,r[4]+r[0],r[2],2);
if(!vf3_matrix_family(0x0c09efe6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09efe6u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
