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
int vf3_away_batch11_adapter_33(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07aaacu: goto P_0c07aaac;
case 0x0c07aaaeu: goto P_0c07aaae;
case 0x0c07aab0u: goto P_0c07aab0;
case 0x0c07aab2u: goto P_0c07aab2;
case 0x0c07aab4u: goto P_0c07aab4;
case 0x0c07aab6u: goto P_0c07aab6;
case 0x0c07aab8u: goto P_0c07aab8;
case 0x0c07aabau: goto P_0c07aaba;
case 0x0c07aabcu: goto P_0c07aabc;
case 0x0c07aabeu: goto P_0c07aabe;
case 0x0c07aac0u: goto P_0c07aac0;
case 0x0c07aac2u: goto P_0c07aac2;
case 0x0c07aac4u: goto P_0c07aac4;
case 0x0c07aac6u: goto P_0c07aac6;
case 0x0c07aac8u: goto P_0c07aac8;
case 0x0c07aacau: goto P_0c07aaca;
case 0x0c07aaccu: goto P_0c07aacc;
case 0x0c07aaceu: goto P_0c07aace;
case 0x0c07aad0u: goto P_0c07aad0;
case 0x0c07aad2u: goto P_0c07aad2;
case 0x0c07aad4u: goto P_0c07aad4;
case 0x0c07aad6u: goto P_0c07aad6;
case 0x0c07aad8u: goto P_0c07aad8;
case 0x0c07aadau: goto P_0c07aada;
case 0x0c07aadcu: goto P_0c07aadc;
case 0x0c07aadeu: goto P_0c07aade;
case 0x0c07aae0u: goto P_0c07aae0;
case 0x0c07aae2u: goto P_0c07aae2;
case 0x0c07aae4u: goto P_0c07aae4;
case 0x0c07aae6u: goto P_0c07aae6;
case 0x0c07aae8u: goto P_0c07aae8;
case 0x0c07aaeau: goto P_0c07aaea;
case 0x0c07aaecu: goto P_0c07aaec;
case 0x0c07aaeeu: goto P_0c07aaee;
case 0x0c07aaf0u: goto P_0c07aaf0;
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
case 0x0c07ac28u: goto P_0c07ac28;
case 0x0c07ac2au: goto P_0c07ac2a;
case 0x0c07ac2cu: goto P_0c07ac2c;
case 0x0c07ac2eu: goto P_0c07ac2e;
case 0x0c07ac30u: goto P_0c07ac30;
case 0x0c07ac32u: goto P_0c07ac32;
case 0x0c07ac34u: goto P_0c07ac34;
case 0x0c07ac36u: goto P_0c07ac36;
case 0x0c07ac38u: goto P_0c07ac38;
case 0x0c07ac3au: goto P_0c07ac3a;
case 0x0c07ac3cu: goto P_0c07ac3c;
case 0x0c07ac3eu: goto P_0c07ac3e;
case 0x0c07ac40u: goto P_0c07ac40;
case 0x0c07ac42u: goto P_0c07ac42;
case 0x0c07ac44u: goto P_0c07ac44;
case 0x0c07ac46u: goto P_0c07ac46;
case 0x0c07ac48u: goto P_0c07ac48;
case 0x0c07ac4au: goto P_0c07ac4a;
case 0x0c07ac4cu: goto P_0c07ac4c;
case 0x0c07ac4eu: goto P_0c07ac4e;
case 0x0c07ac50u: goto P_0c07ac50;
case 0x0c07ac52u: goto P_0c07ac52;
case 0x0c07ac54u: goto P_0c07ac54;
case 0x0c07ac56u: goto P_0c07ac56;
case 0x0c07ac58u: goto P_0c07ac58;
case 0x0c07ac5au: goto P_0c07ac5a;
case 0x0c07ac5cu: goto P_0c07ac5c;
case 0x0c07ac5eu: goto P_0c07ac5e;
case 0x0c07ac60u: goto P_0c07ac60;
case 0x0c07ac62u: goto P_0c07ac62;
case 0x0c07ac64u: goto P_0c07ac64;
case 0x0c07ac66u: goto P_0c07ac66;
case 0x0c07ac68u: goto P_0c07ac68;
case 0x0c07ad10u: goto P_0c07ad10;
case 0x0c07ad12u: goto P_0c07ad12;
case 0x0c07ad14u: goto P_0c07ad14;
case 0x0c07ad16u: goto P_0c07ad16;
case 0x0c07ad18u: goto P_0c07ad18;
case 0x0c07ad1au: goto P_0c07ad1a;
case 0x0c07ad1cu: goto P_0c07ad1c;
case 0x0c07ad1eu: goto P_0c07ad1e;
case 0x0c07ad20u: goto P_0c07ad20;
case 0x0c07ad22u: goto P_0c07ad22;
case 0x0c07ad24u: goto P_0c07ad24;
case 0x0c07ad26u: goto P_0c07ad26;
case 0x0c07ad28u: goto P_0c07ad28;
case 0x0c07ad2au: goto P_0c07ad2a;
case 0x0c07ad2cu: goto P_0c07ad2c;
case 0x0c07ad2eu: goto P_0c07ad2e;
case 0x0c07ad30u: goto P_0c07ad30;
case 0x0c07ad32u: goto P_0c07ad32;
case 0x0c07ad34u: goto P_0c07ad34;
case 0x0c07ad36u: goto P_0c07ad36;
case 0x0c07ad38u: goto P_0c07ad38;
case 0x0c07ad3au: goto P_0c07ad3a;
case 0x0c07ad3cu: goto P_0c07ad3c;
case 0x0c07ad3eu: goto P_0c07ad3e;
case 0x0c07ad40u: goto P_0c07ad40;
case 0x0c07ad42u: goto P_0c07ad42;
case 0x0c07ad44u: goto P_0c07ad44;
case 0x0c07ad46u: goto P_0c07ad46;
case 0x0c07ad48u: goto P_0c07ad48;
case 0x0c07ad4au: goto P_0c07ad4a;
case 0x0c07ad4cu: goto P_0c07ad4c;
case 0x0c07ad4eu: goto P_0c07ad4e;
case 0x0c07ad50u: goto P_0c07ad50;
case 0x0c07ad52u: goto P_0c07ad52;
case 0x0c07ad54u: goto P_0c07ad54;
case 0x0c07ad56u: goto P_0c07ad56;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07aaac: /* original 2fe6, guest PC 0x0c07aaac */
if(!s->budget--) { s->failed_pc=0x0c07aaacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07aaae;
P_0c07aaae: /* original 2fd6, guest PC 0x0c07aaae */
if(!s->budget--) { s->failed_pc=0x0c07aaaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07aab0;
P_0c07aab0: /* original 4f22, guest PC 0x0c07aab0 */
if(!s->budget--) { s->failed_pc=0x0c07aab0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07aab2;
P_0c07aab2: /* original d314, guest PC 0x0c07aab2 */
if(!s->budget--) { s->failed_pc=0x0c07aab2u; return 0; }
r[3]=read(ram,0x0c07ab04u,4);
goto P_0c07aab4;
P_0c07aab4: /* original b57c, guest PC 0x0c07aab4 */
if(!s->budget--) { s->failed_pc=0x0c07aab4u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07aab8u;
tmp=read(ram,r[3],4);
r[13]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aab8u) { target=s->pc; goto dispatch; }
goto P_0c07aab8;
P_0c07aab6: /* original 6d32, guest PC 0x0c07aab6 */
if(!s->budget--) { s->failed_pc=0x0c07aab6u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c07aab8;
P_0c07aab8: /* original 6e03, guest PC 0x0c07aab8 */
if(!s->budget--) { s->failed_pc=0x0c07aab8u; return 0; }
r[14]=r[0];
goto P_0c07aaba;
P_0c07aaba: /* original d00e, guest PC 0x0c07aaba */
if(!s->budget--) { s->failed_pc=0x0c07aabau; return 0; }
r[0]=read(ram,0x0c07aaf4u,4);
goto P_0c07aabc;
P_0c07aabc: /* original 64ed, guest PC 0x0c07aabc */
if(!s->budget--) { s->failed_pc=0x0c07aabcu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aabe;
P_0c07aabe: /* original 4400, guest PC 0x0c07aabe */
if(!s->budget--) { s->failed_pc=0x0c07aabeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07aac0;
P_0c07aac0: /* original 044d, guest PC 0x0c07aac0 */
if(!s->budget--) { s->failed_pc=0x0c07aac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07aac2;
P_0c07aac2: /* original 644d, guest PC 0x0c07aac2 */
if(!s->budget--) { s->failed_pc=0x0c07aac2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07aac4;
P_0c07aac4: /* original 2448, guest PC 0x0c07aac4 */
if(!s->budget--) { s->failed_pc=0x0c07aac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07aac6;
P_0c07aac6: /* original 8902, guest PC 0x0c07aac6 */
if(!s->budget--) { s->failed_pc=0x0c07aac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07aace; }
goto P_0c07aac8;
P_0c07aac8: /* original d20b, guest PC 0x0c07aac8 */
if(!s->budget--) { s->failed_pc=0x0c07aac8u; return 0; }
r[2]=read(ram,0x0c07aaf8u,4);
goto P_0c07aaca;
P_0c07aaca: /* original 3420, guest PC 0x0c07aaca */
if(!s->budget--) { s->failed_pc=0x0c07aacau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07aacc;
P_0c07aacc: /* original 8b0d, guest PC 0x0c07aacc */
if(!s->budget--) { s->failed_pc=0x0c07aaccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07aaea; }
goto P_0c07aace;
P_0c07aace: /* original 64ed, guest PC 0x0c07aace */
if(!s->budget--) { s->failed_pc=0x0c07aaceu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aad0;
P_0c07aad0: /* original d00d, guest PC 0x0c07aad0 */
if(!s->budget--) { s->failed_pc=0x0c07aad0u; return 0; }
r[0]=read(ram,0x0c07ab08u,4);
goto P_0c07aad2;
P_0c07aad2: /* original d30f, guest PC 0x0c07aad2 */
if(!s->budget--) { s->failed_pc=0x0c07aad2u; return 0; }
r[3]=read(ram,0x0c07ab10u,4);
goto P_0c07aad4;
P_0c07aad4: /* original 74f8, guest PC 0x0c07aad4 */
if(!s->budget--) { s->failed_pc=0x0c07aad4u; return 0; }
r[4]+=0xfffffff8u;
goto P_0c07aad6;
P_0c07aad6: /* original 65d3, guest PC 0x0c07aad6 */
if(!s->budget--) { s->failed_pc=0x0c07aad6u; return 0; }
r[5]=r[13];
goto P_0c07aad8;
P_0c07aad8: /* original 4408, guest PC 0x0c07aad8 */
if(!s->budget--) { s->failed_pc=0x0c07aad8u; return 0; }
r[4]<<=2;
goto P_0c07aada;
P_0c07aada: /* original 430b, guest PC 0x0c07aada */
if(!s->budget--) { s->failed_pc=0x0c07aadau; return 0; }
target=r[3];
r[16]=code_base|0x0c07aadeu;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aadeu) { target=s->pc; goto dispatch; }
goto P_0c07aade;
P_0c07aadc: /* original 044e, guest PC 0x0c07aadc */
if(!s->budget--) { s->failed_pc=0x0c07aadcu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07aade;
P_0c07aade: /* original 4f26, guest PC 0x0c07aade */
if(!s->budget--) { s->failed_pc=0x0c07aadeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aae0;
P_0c07aae0: /* original 65d3, guest PC 0x0c07aae0 */
if(!s->budget--) { s->failed_pc=0x0c07aae0u; return 0; }
r[5]=r[13];
goto P_0c07aae2;
P_0c07aae2: /* original 64e3, guest PC 0x0c07aae2 */
if(!s->budget--) { s->failed_pc=0x0c07aae2u; return 0; }
r[4]=r[14];
goto P_0c07aae4;
P_0c07aae4: /* original 6df6, guest PC 0x0c07aae4 */
if(!s->budget--) { s->failed_pc=0x0c07aae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aae6;
P_0c07aae6: /* original aead, guest PC 0x0c07aae6 */
if(!s->budget--) { s->failed_pc=0x0c07aae6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07a844u,s,ram);
P_0c07aae8: /* original 6ef6, guest PC 0x0c07aae8 */
if(!s->budget--) { s->failed_pc=0x0c07aae8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07aaea;
P_0c07aaea: /* original 4f26, guest PC 0x0c07aaea */
if(!s->budget--) { s->failed_pc=0x0c07aaeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aaec;
P_0c07aaec: /* original 6df6, guest PC 0x0c07aaec */
if(!s->budget--) { s->failed_pc=0x0c07aaecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aaee;
P_0c07aaee: /* original 000b, guest PC 0x0c07aaee */
if(!s->budget--) { s->failed_pc=0x0c07aaeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aaf0: /* original 6ef6, guest PC 0x0c07aaf0 */
if(!s->budget--) { s->failed_pc=0x0c07aaf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07aaf2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07aaf2u; return 0; } return 1;
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
P_0c07ac28: /* original 2fe6, guest PC 0x0c07ac28 */
if(!s->budget--) { s->failed_pc=0x0c07ac28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac2a;
P_0c07ac2a: /* original 2fd6, guest PC 0x0c07ac2a */
if(!s->budget--) { s->failed_pc=0x0c07ac2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ac2c;
P_0c07ac2c: /* original 6d53, guest PC 0x0c07ac2c */
if(!s->budget--) { s->failed_pc=0x0c07ac2cu; return 0; }
r[13]=r[5];
goto P_0c07ac2e;
P_0c07ac2e: /* original 4f22, guest PC 0x0c07ac2e */
if(!s->budget--) { s->failed_pc=0x0c07ac2eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ac30;
P_0c07ac30: /* original 7ffc, guest PC 0x0c07ac30 */
if(!s->budget--) { s->failed_pc=0x0c07ac30u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07ac32;
P_0c07ac32: /* original 2f41, guest PC 0x0c07ac32 */
if(!s->budget--) { s->failed_pc=0x0c07ac32u; return 0; }
write(ram,r[15],r[4],2);
goto P_0c07ac34;
P_0c07ac34: /* original 6ef1, guest PC 0x0c07ac34 */
if(!s->budget--) { s->failed_pc=0x0c07ac34u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[14]=tmp;
goto P_0c07ac36;
P_0c07ac36: /* original d32e, guest PC 0x0c07ac36 */
if(!s->budget--) { s->failed_pc=0x0c07ac36u; return 0; }
r[3]=read(ram,0x0c07acf0u,4);
goto P_0c07ac38;
P_0c07ac38: /* original 6eed, guest PC 0x0c07ac38 */
if(!s->budget--) { s->failed_pc=0x0c07ac38u; return 0; }
r[14]=r[14]&65535u;
goto P_0c07ac3a;
P_0c07ac3a: /* original 430b, guest PC 0x0c07ac3a */
if(!s->budget--) { s->failed_pc=0x0c07ac3au; return 0; }
target=r[3];
r[16]=code_base|0x0c07ac3eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ac3eu) { target=s->pc; goto dispatch; }
goto P_0c07ac3e;
P_0c07ac3c: /* original 64e3, guest PC 0x0c07ac3c */
if(!s->budget--) { s->failed_pc=0x0c07ac3cu; return 0; }
r[4]=r[14];
goto P_0c07ac3e;
P_0c07ac3e: /* original 60e3, guest PC 0x0c07ac3e */
if(!s->budget--) { s->failed_pc=0x0c07ac3eu; return 0; }
r[0]=r[14];
goto P_0c07ac40;
P_0c07ac40: /* original 8838, guest PC 0x0c07ac40 */
if(!s->budget--) { s->failed_pc=0x0c07ac40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000038u)!=0);
goto P_0c07ac42;
P_0c07ac42: /* original 8b02, guest PC 0x0c07ac42 */
if(!s->budget--) { s->failed_pc=0x0c07ac42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ac4a; }
goto P_0c07ac44;
P_0c07ac44: /* original d42b, guest PC 0x0c07ac44 */
if(!s->budget--) { s->failed_pc=0x0c07ac44u; return 0; }
r[4]=read(ram,0x0c07acf4u,4);
goto P_0c07ac46;
P_0c07ac46: /* original a002, guest PC 0x0c07ac46 */
if(!s->budget--) { s->failed_pc=0x0c07ac46u; return 0; }
r[5]=r[13];
goto P_0c07ac4e;
P_0c07ac48: /* original 65d3, guest PC 0x0c07ac48 */
if(!s->budget--) { s->failed_pc=0x0c07ac48u; return 0; }
r[5]=r[13];
goto P_0c07ac4a;
P_0c07ac4a: /* original d42b, guest PC 0x0c07ac4a */
if(!s->budget--) { s->failed_pc=0x0c07ac4au; return 0; }
r[4]=read(ram,0x0c07acf8u,4);
goto P_0c07ac4c;
P_0c07ac4c: /* original 65d3, guest PC 0x0c07ac4c */
if(!s->budget--) { s->failed_pc=0x0c07ac4cu; return 0; }
r[5]=r[13];
goto P_0c07ac4e;
P_0c07ac4e: /* original bdda, guest PC 0x0c07ac4e */
if(!s->budget--) { s->failed_pc=0x0c07ac4eu; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07ac52u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ac52u) { target=s->pc; goto dispatch; }
goto P_0c07ac52;
P_0c07ac50: /* original 0009, guest PC 0x0c07ac50 */
if(!s->budget--) { s->failed_pc=0x0c07ac50u; return 0; }
goto P_0c07ac52;
P_0c07ac52: /* original 60f1, guest PC 0x0c07ac52 */
if(!s->budget--) { s->failed_pc=0x0c07ac52u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[0]=tmp;
goto P_0c07ac54;
P_0c07ac54: /* original 7f04, guest PC 0x0c07ac54 */
if(!s->budget--) { s->failed_pc=0x0c07ac54u; return 0; }
r[15]+=0x00000004u;
goto P_0c07ac56;
P_0c07ac56: /* original 4f26, guest PC 0x0c07ac56 */
if(!s->budget--) { s->failed_pc=0x0c07ac56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ac58;
P_0c07ac58: /* original d423, guest PC 0x0c07ac58 */
if(!s->budget--) { s->failed_pc=0x0c07ac58u; return 0; }
r[4]=read(ram,0x0c07ace8u,4);
goto P_0c07ac5a;
P_0c07ac5a: /* original 600d, guest PC 0x0c07ac5a */
if(!s->budget--) { s->failed_pc=0x0c07ac5au; return 0; }
r[0]=r[0]&65535u;
goto P_0c07ac5c;
P_0c07ac5c: /* original 4000, guest PC 0x0c07ac5c */
if(!s->budget--) { s->failed_pc=0x0c07ac5cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07ac5e;
P_0c07ac5e: /* original 04e5, guest PC 0x0c07ac5e */
if(!s->budget--) { s->failed_pc=0x0c07ac5eu; return 0; }
write(ram,r[4]+r[0],r[14],2);
goto P_0c07ac60;
P_0c07ac60: /* original 60e3, guest PC 0x0c07ac60 */
if(!s->budget--) { s->failed_pc=0x0c07ac60u; return 0; }
r[0]=r[14];
goto P_0c07ac62;
P_0c07ac62: /* original 8147, guest PC 0x0c07ac62 */
if(!s->budget--) { s->failed_pc=0x0c07ac62u; return 0; }
write(ram,r[4]+14,r[0],2);
goto P_0c07ac64;
P_0c07ac64: /* original 6df6, guest PC 0x0c07ac64 */
if(!s->budget--) { s->failed_pc=0x0c07ac64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ac66;
P_0c07ac66: /* original 000b, guest PC 0x0c07ac66 */
if(!s->budget--) { s->failed_pc=0x0c07ac66u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ac68: /* original 6ef6, guest PC 0x0c07ac68 */
if(!s->budget--) { s->failed_pc=0x0c07ac68u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ac6au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ac6au; return 0; } return 1;
P_0c07ad10: /* original 2fe6, guest PC 0x0c07ad10 */
if(!s->budget--) { s->failed_pc=0x0c07ad10u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad12;
P_0c07ad12: /* original 4f22, guest PC 0x0c07ad12 */
if(!s->budget--) { s->failed_pc=0x0c07ad12u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ad14;
P_0c07ad14: /* original 7ff8, guest PC 0x0c07ad14 */
if(!s->budget--) { s->failed_pc=0x0c07ad14u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c07ad16;
P_0c07ad16: /* original 2f51, guest PC 0x0c07ad16 */
if(!s->budget--) { s->failed_pc=0x0c07ad16u; return 0; }
write(ram,r[15],r[5],2);
goto P_0c07ad18;
P_0c07ad18: /* original d23d, guest PC 0x0c07ad18 */
if(!s->budget--) { s->failed_pc=0x0c07ad18u; return 0; }
r[2]=read(ram,0x0c07ae10u,4);
goto P_0c07ad1a;
P_0c07ad1a: /* original 6322, guest PC 0x0c07ad1a */
if(!s->budget--) { s->failed_pc=0x0c07ad1au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ad1c;
P_0c07ad1c: /* original 1f31, guest PC 0x0c07ad1c */
if(!s->budget--) { s->failed_pc=0x0c07ad1cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07ad1e;
P_0c07ad1e: /* original b447, guest PC 0x0c07ad1e */
if(!s->budget--) { s->failed_pc=0x0c07ad1eu; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07ad22u;
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ad22u) { target=s->pc; goto dispatch; }
goto P_0c07ad22;
P_0c07ad20: /* original 64f1, guest PC 0x0c07ad20 */
if(!s->budget--) { s->failed_pc=0x0c07ad20u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[15],2);
r[4]=tmp;
goto P_0c07ad22;
P_0c07ad22: /* original 6e03, guest PC 0x0c07ad22 */
if(!s->budget--) { s->failed_pc=0x0c07ad22u; return 0; }
r[14]=r[0];
goto P_0c07ad24;
P_0c07ad24: /* original d03b, guest PC 0x0c07ad24 */
if(!s->budget--) { s->failed_pc=0x0c07ad24u; return 0; }
r[0]=read(ram,0x0c07ae14u,4);
goto P_0c07ad26;
P_0c07ad26: /* original 62ed, guest PC 0x0c07ad26 */
if(!s->budget--) { s->failed_pc=0x0c07ad26u; return 0; }
r[2]=r[14]&65535u;
goto P_0c07ad28;
P_0c07ad28: /* original 4200, guest PC 0x0c07ad28 */
if(!s->budget--) { s->failed_pc=0x0c07ad28u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07ad2a;
P_0c07ad2a: /* original 032d, guest PC 0x0c07ad2a */
if(!s->budget--) { s->failed_pc=0x0c07ad2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07ad2c;
P_0c07ad2c: /* original 633d, guest PC 0x0c07ad2c */
if(!s->budget--) { s->failed_pc=0x0c07ad2cu; return 0; }
r[3]=r[3]&65535u;
goto P_0c07ad2e;
P_0c07ad2e: /* original 2338, guest PC 0x0c07ad2e */
if(!s->budget--) { s->failed_pc=0x0c07ad2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07ad30;
P_0c07ad30: /* original 8b0e, guest PC 0x0c07ad30 */
if(!s->budget--) { s->failed_pc=0x0c07ad30u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad50; }
goto P_0c07ad32;
P_0c07ad32: /* original d137, guest PC 0x0c07ad32 */
if(!s->budget--) { s->failed_pc=0x0c07ad32u; return 0; }
r[1]=read(ram,0x0c07ae10u,4);
goto P_0c07ad34;
P_0c07ad34: /* original 64ed, guest PC 0x0c07ad34 */
if(!s->budget--) { s->failed_pc=0x0c07ad34u; return 0; }
r[4]=r[14]&65535u;
goto P_0c07ad36;
P_0c07ad36: /* original d038, guest PC 0x0c07ad36 */
if(!s->budget--) { s->failed_pc=0x0c07ad36u; return 0; }
r[0]=read(ram,0x0c07ae18u,4);
goto P_0c07ad38;
P_0c07ad38: /* original 74c8, guest PC 0x0c07ad38 */
if(!s->budget--) { s->failed_pc=0x0c07ad38u; return 0; }
r[4]+=0xffffffc8u;
goto P_0c07ad3a;
P_0c07ad3a: /* original d338, guest PC 0x0c07ad3a */
if(!s->budget--) { s->failed_pc=0x0c07ad3au; return 0; }
r[3]=read(ram,0x0c07ae1cu,4);
goto P_0c07ad3c;
P_0c07ad3c: /* original 4408, guest PC 0x0c07ad3c */
if(!s->budget--) { s->failed_pc=0x0c07ad3cu; return 0; }
r[4]<<=2;
goto P_0c07ad3e;
P_0c07ad3e: /* original 6512, guest PC 0x0c07ad3e */
if(!s->budget--) { s->failed_pc=0x0c07ad3eu; return 0; }
tmp=read(ram,r[1],4);
r[5]=tmp;
goto P_0c07ad40;
P_0c07ad40: /* original 430b, guest PC 0x0c07ad40 */
if(!s->budget--) { s->failed_pc=0x0c07ad40u; return 0; }
target=r[3];
r[16]=code_base|0x0c07ad44u;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ad44u) { target=s->pc; goto dispatch; }
goto P_0c07ad44;
P_0c07ad42: /* original 044e, guest PC 0x0c07ad42 */
if(!s->budget--) { s->failed_pc=0x0c07ad42u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07ad44;
P_0c07ad44: /* original 55f1, guest PC 0x0c07ad44 */
if(!s->budget--) { s->failed_pc=0x0c07ad44u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07ad46;
P_0c07ad46: /* original 7f08, guest PC 0x0c07ad46 */
if(!s->budget--) { s->failed_pc=0x0c07ad46u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ad48;
P_0c07ad48: /* original 4f26, guest PC 0x0c07ad48 */
if(!s->budget--) { s->failed_pc=0x0c07ad48u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad4a;
P_0c07ad4a: /* original 64e3, guest PC 0x0c07ad4a */
if(!s->budget--) { s->failed_pc=0x0c07ad4au; return 0; }
r[4]=r[14];
goto P_0c07ad4c;
P_0c07ad4c: /* original af6c, guest PC 0x0c07ad4c */
if(!s->budget--) { s->failed_pc=0x0c07ad4cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ac28;
P_0c07ad4e: /* original 6ef6, guest PC 0x0c07ad4e */
if(!s->budget--) { s->failed_pc=0x0c07ad4eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07ad50;
P_0c07ad50: /* original 7f08, guest PC 0x0c07ad50 */
if(!s->budget--) { s->failed_pc=0x0c07ad50u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ad52;
P_0c07ad52: /* original 4f26, guest PC 0x0c07ad52 */
if(!s->budget--) { s->failed_pc=0x0c07ad52u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad54;
P_0c07ad54: /* original 000b, guest PC 0x0c07ad54 */
if(!s->budget--) { s->failed_pc=0x0c07ad54u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ad56: /* original 6ef6, guest PC 0x0c07ad56 */
if(!s->budget--) { s->failed_pc=0x0c07ad56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07ad58u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
