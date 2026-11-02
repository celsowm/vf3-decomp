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
int vf3_away_batch15_adapter_10(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08ccf0u: goto P_0c08ccf0;
case 0x0c08ccf2u: goto P_0c08ccf2;
case 0x0c08ccf4u: goto P_0c08ccf4;
case 0x0c08ccf6u: goto P_0c08ccf6;
case 0x0c08ccf8u: goto P_0c08ccf8;
case 0x0c08ccfau: goto P_0c08ccfa;
case 0x0c08ccfcu: goto P_0c08ccfc;
case 0x0c08ccfeu: goto P_0c08ccfe;
case 0x0c08cd00u: goto P_0c08cd00;
case 0x0c08cd02u: goto P_0c08cd02;
case 0x0c08cd04u: goto P_0c08cd04;
case 0x0c08cd06u: goto P_0c08cd06;
case 0x0c08cd08u: goto P_0c08cd08;
case 0x0c08cd0au: goto P_0c08cd0a;
case 0x0c08cd0cu: goto P_0c08cd0c;
case 0x0c08cd0eu: goto P_0c08cd0e;
case 0x0c08cd10u: goto P_0c08cd10;
case 0x0c08cd12u: goto P_0c08cd12;
case 0x0c08cd14u: goto P_0c08cd14;
case 0x0c08cd16u: goto P_0c08cd16;
case 0x0c08cd18u: goto P_0c08cd18;
case 0x0c08cd1au: goto P_0c08cd1a;
case 0x0c08cd1cu: goto P_0c08cd1c;
case 0x0c08cd1eu: goto P_0c08cd1e;
case 0x0c08cd20u: goto P_0c08cd20;
case 0x0c08cd22u: goto P_0c08cd22;
case 0x0c08cd24u: goto P_0c08cd24;
case 0x0c08cd26u: goto P_0c08cd26;
case 0x0c08cd28u: goto P_0c08cd28;
case 0x0c08cd2au: goto P_0c08cd2a;
case 0x0c08cd2cu: goto P_0c08cd2c;
case 0x0c08cd2eu: goto P_0c08cd2e;
case 0x0c08cd30u: goto P_0c08cd30;
case 0x0c08cd32u: goto P_0c08cd32;
case 0x0c08cd34u: goto P_0c08cd34;
case 0x0c08cd36u: goto P_0c08cd36;
case 0x0c08cd38u: goto P_0c08cd38;
case 0x0c08cd3au: goto P_0c08cd3a;
case 0x0c08cd3cu: goto P_0c08cd3c;
case 0x0c08cd3eu: goto P_0c08cd3e;
case 0x0c08cd40u: goto P_0c08cd40;
case 0x0c08cd42u: goto P_0c08cd42;
case 0x0c08cd44u: goto P_0c08cd44;
case 0x0c08cd46u: goto P_0c08cd46;
case 0x0c08cd48u: goto P_0c08cd48;
case 0x0c08cd4au: goto P_0c08cd4a;
case 0x0c08cd4cu: goto P_0c08cd4c;
case 0x0c08cd4eu: goto P_0c08cd4e;
case 0x0c08cd50u: goto P_0c08cd50;
case 0x0c08cd52u: goto P_0c08cd52;
case 0x0c08cd54u: goto P_0c08cd54;
case 0x0c08cd56u: goto P_0c08cd56;
case 0x0c08cd58u: goto P_0c08cd58;
case 0x0c08cd5au: goto P_0c08cd5a;
case 0x0c08cd5cu: goto P_0c08cd5c;
case 0x0c08cd5eu: goto P_0c08cd5e;
case 0x0c08cd60u: goto P_0c08cd60;
case 0x0c08cd62u: goto P_0c08cd62;
case 0x0c08cd64u: goto P_0c08cd64;
case 0x0c08cd66u: goto P_0c08cd66;
case 0x0c08cd68u: goto P_0c08cd68;
case 0x0c08cd6au: goto P_0c08cd6a;
case 0x0c08cd6cu: goto P_0c08cd6c;
case 0x0c08cd6eu: goto P_0c08cd6e;
case 0x0c08cd70u: goto P_0c08cd70;
case 0x0c08cd72u: goto P_0c08cd72;
case 0x0c08cd74u: goto P_0c08cd74;
case 0x0c08cd76u: goto P_0c08cd76;
case 0x0c08cd78u: goto P_0c08cd78;
case 0x0c08cd7au: goto P_0c08cd7a;
case 0x0c08cd7cu: goto P_0c08cd7c;
case 0x0c08cd7eu: goto P_0c08cd7e;
case 0x0c08cd80u: goto P_0c08cd80;
case 0x0c08cd82u: goto P_0c08cd82;
case 0x0c08cd84u: goto P_0c08cd84;
case 0x0c08cd86u: goto P_0c08cd86;
case 0x0c08cd88u: goto P_0c08cd88;
case 0x0c08cd8au: goto P_0c08cd8a;
case 0x0c08cd8cu: goto P_0c08cd8c;
case 0x0c08cd8eu: goto P_0c08cd8e;
case 0x0c08cd90u: goto P_0c08cd90;
case 0x0c08cd92u: goto P_0c08cd92;
case 0x0c08cd94u: goto P_0c08cd94;
case 0x0c08cd96u: goto P_0c08cd96;
case 0x0c08cd98u: goto P_0c08cd98;
case 0x0c08cd9au: goto P_0c08cd9a;
case 0x0c08cdb4u: goto P_0c08cdb4;
case 0x0c08cdb6u: goto P_0c08cdb6;
case 0x0c08cdb8u: goto P_0c08cdb8;
case 0x0c08cdbau: goto P_0c08cdba;
case 0x0c08cdbcu: goto P_0c08cdbc;
case 0x0c08cdbeu: goto P_0c08cdbe;
case 0x0c08cdc0u: goto P_0c08cdc0;
case 0x0c08cdc2u: goto P_0c08cdc2;
case 0x0c08cdc4u: goto P_0c08cdc4;
case 0x0c08cdc6u: goto P_0c08cdc6;
case 0x0c08cdc8u: goto P_0c08cdc8;
case 0x0c08cdcau: goto P_0c08cdca;
case 0x0c08cdccu: goto P_0c08cdcc;
case 0x0c08cdceu: goto P_0c08cdce;
case 0x0c08cdd0u: goto P_0c08cdd0;
case 0x0c08cdd2u: goto P_0c08cdd2;
case 0x0c08cdd4u: goto P_0c08cdd4;
case 0x0c08cdd6u: goto P_0c08cdd6;
case 0x0c08cdd8u: goto P_0c08cdd8;
case 0x0c08cddau: goto P_0c08cdda;
case 0x0c08cddcu: goto P_0c08cddc;
case 0x0c08cddeu: goto P_0c08cdde;
case 0x0c08cde0u: goto P_0c08cde0;
case 0x0c08cde2u: goto P_0c08cde2;
case 0x0c08cde4u: goto P_0c08cde4;
case 0x0c08cde6u: goto P_0c08cde6;
case 0x0c08cde8u: goto P_0c08cde8;
case 0x0c08cdeau: goto P_0c08cdea;
case 0x0c08cdecu: goto P_0c08cdec;
case 0x0c08cdeeu: goto P_0c08cdee;
case 0x0c08cdf0u: goto P_0c08cdf0;
case 0x0c08cdf2u: goto P_0c08cdf2;
case 0x0c08cdf4u: goto P_0c08cdf4;
case 0x0c08cdf6u: goto P_0c08cdf6;
case 0x0c08cdf8u: goto P_0c08cdf8;
case 0x0c08cdfau: goto P_0c08cdfa;
case 0x0c08cdfcu: goto P_0c08cdfc;
case 0x0c08cdfeu: goto P_0c08cdfe;
case 0x0c08ce00u: goto P_0c08ce00;
case 0x0c08ce02u: goto P_0c08ce02;
case 0x0c08ce04u: goto P_0c08ce04;
case 0x0c08ce06u: goto P_0c08ce06;
case 0x0c08ce08u: goto P_0c08ce08;
case 0x0c08ce0au: goto P_0c08ce0a;
case 0x0c08ce0cu: goto P_0c08ce0c;
case 0x0c08ce0eu: goto P_0c08ce0e;
case 0x0c08ce10u: goto P_0c08ce10;
case 0x0c08ce12u: goto P_0c08ce12;
case 0x0c08ce14u: goto P_0c08ce14;
case 0x0c08ce16u: goto P_0c08ce16;
case 0x0c08ce18u: goto P_0c08ce18;
case 0x0c08ce1au: goto P_0c08ce1a;
case 0x0c08ce1cu: goto P_0c08ce1c;
case 0x0c08ce1eu: goto P_0c08ce1e;
case 0x0c08ce20u: goto P_0c08ce20;
case 0x0c08ce22u: goto P_0c08ce22;
case 0x0c08ce24u: goto P_0c08ce24;
case 0x0c08ce26u: goto P_0c08ce26;
case 0x0c08ce28u: goto P_0c08ce28;
case 0x0c08ce2au: goto P_0c08ce2a;
case 0x0c08ce2cu: goto P_0c08ce2c;
case 0x0c08ce2eu: goto P_0c08ce2e;
case 0x0c08ce30u: goto P_0c08ce30;
case 0x0c08ce32u: goto P_0c08ce32;
case 0x0c08ce34u: goto P_0c08ce34;
case 0x0c08ce36u: goto P_0c08ce36;
case 0x0c08ce38u: goto P_0c08ce38;
case 0x0c08ce3au: goto P_0c08ce3a;
case 0x0c08ce3cu: goto P_0c08ce3c;
case 0x0c08ce3eu: goto P_0c08ce3e;
case 0x0c08ce40u: goto P_0c08ce40;
case 0x0c08ce42u: goto P_0c08ce42;
case 0x0c08ce44u: goto P_0c08ce44;
case 0x0c08ce46u: goto P_0c08ce46;
case 0x0c08ce48u: goto P_0c08ce48;
case 0x0c08ce4au: goto P_0c08ce4a;
case 0x0c08ce4cu: goto P_0c08ce4c;
case 0x0c08ce4eu: goto P_0c08ce4e;
case 0x0c08ce50u: goto P_0c08ce50;
case 0x0c08ce52u: goto P_0c08ce52;
case 0x0c08ce54u: goto P_0c08ce54;
case 0x0c08ce56u: goto P_0c08ce56;
case 0x0c08ce58u: goto P_0c08ce58;
case 0x0c08ce5au: goto P_0c08ce5a;
case 0x0c08ce5cu: goto P_0c08ce5c;
case 0x0c08ce5eu: goto P_0c08ce5e;
case 0x0c08ce60u: goto P_0c08ce60;
case 0x0c08ce62u: goto P_0c08ce62;
case 0x0c08ce64u: goto P_0c08ce64;
case 0x0c08ce66u: goto P_0c08ce66;
case 0x0c08ce68u: goto P_0c08ce68;
case 0x0c08ce6au: goto P_0c08ce6a;
case 0x0c08ce6cu: goto P_0c08ce6c;
case 0x0c08ce6eu: goto P_0c08ce6e;
case 0x0c08ce70u: goto P_0c08ce70;
case 0x0c08ce72u: goto P_0c08ce72;
case 0x0c08ce74u: goto P_0c08ce74;
case 0x0c08ce76u: goto P_0c08ce76;
case 0x0c08ce78u: goto P_0c08ce78;
case 0x0c08ce7au: goto P_0c08ce7a;
case 0x0c08ce7cu: goto P_0c08ce7c;
case 0x0c08ce7eu: goto P_0c08ce7e;
case 0x0c08ce80u: goto P_0c08ce80;
case 0x0c08ce82u: goto P_0c08ce82;
case 0x0c08ce84u: goto P_0c08ce84;
case 0x0c08ce86u: goto P_0c08ce86;
case 0x0c08ce88u: goto P_0c08ce88;
case 0x0c08ce8au: goto P_0c08ce8a;
case 0x0c08ce8cu: goto P_0c08ce8c;
case 0x0c08ce8eu: goto P_0c08ce8e;
case 0x0c08ce90u: goto P_0c08ce90;
case 0x0c08ce92u: goto P_0c08ce92;
case 0x0c08ce94u: goto P_0c08ce94;
case 0x0c08ce96u: goto P_0c08ce96;
case 0x0c08ce98u: goto P_0c08ce98;
case 0x0c08ce9au: goto P_0c08ce9a;
case 0x0c08ce9cu: goto P_0c08ce9c;
case 0x0c08ce9eu: goto P_0c08ce9e;
case 0x0c08cea0u: goto P_0c08cea0;
case 0x0c08cea2u: goto P_0c08cea2;
case 0x0c08cebcu: goto P_0c08cebc;
case 0x0c08cebeu: goto P_0c08cebe;
case 0x0c08cec0u: goto P_0c08cec0;
case 0x0c08cec2u: goto P_0c08cec2;
case 0x0c08cec4u: goto P_0c08cec4;
case 0x0c08cec6u: goto P_0c08cec6;
case 0x0c08cec8u: goto P_0c08cec8;
case 0x0c08cecau: goto P_0c08ceca;
case 0x0c08ceccu: goto P_0c08cecc;
case 0x0c08ceceu: goto P_0c08cece;
case 0x0c08ced0u: goto P_0c08ced0;
case 0x0c08ced2u: goto P_0c08ced2;
case 0x0c08ced4u: goto P_0c08ced4;
case 0x0c08ced6u: goto P_0c08ced6;
case 0x0c08ced8u: goto P_0c08ced8;
case 0x0c08cedau: goto P_0c08ceda;
case 0x0c08cedcu: goto P_0c08cedc;
case 0x0c08cedeu: goto P_0c08cede;
case 0x0c08cee0u: goto P_0c08cee0;
case 0x0c08cee2u: goto P_0c08cee2;
case 0x0c08cee4u: goto P_0c08cee4;
case 0x0c08cee6u: goto P_0c08cee6;
case 0x0c08cee8u: goto P_0c08cee8;
case 0x0c08ceeau: goto P_0c08ceea;
case 0x0c08ceecu: goto P_0c08ceec;
case 0x0c08ceeeu: goto P_0c08ceee;
case 0x0c08cef0u: goto P_0c08cef0;
case 0x0c08cef2u: goto P_0c08cef2;
case 0x0c08cef4u: goto P_0c08cef4;
case 0x0c08cef6u: goto P_0c08cef6;
case 0x0c08cef8u: goto P_0c08cef8;
case 0x0c08cefau: goto P_0c08cefa;
case 0x0c08cefcu: goto P_0c08cefc;
case 0x0c08cefeu: goto P_0c08cefe;
case 0x0c08cf00u: goto P_0c08cf00;
case 0x0c08cf02u: goto P_0c08cf02;
case 0x0c08cf04u: goto P_0c08cf04;
case 0x0c08cf06u: goto P_0c08cf06;
case 0x0c08cf08u: goto P_0c08cf08;
case 0x0c08cf0au: goto P_0c08cf0a;
case 0x0c08cf0cu: goto P_0c08cf0c;
case 0x0c08cf0eu: goto P_0c08cf0e;
case 0x0c08cf10u: goto P_0c08cf10;
case 0x0c08cf12u: goto P_0c08cf12;
case 0x0c08cf14u: goto P_0c08cf14;
case 0x0c08cf16u: goto P_0c08cf16;
case 0x0c08cf18u: goto P_0c08cf18;
case 0x0c08cf1au: goto P_0c08cf1a;
case 0x0c08cf1cu: goto P_0c08cf1c;
case 0x0c08cf1eu: goto P_0c08cf1e;
case 0x0c08cf20u: goto P_0c08cf20;
case 0x0c08cf22u: goto P_0c08cf22;
case 0x0c08cf24u: goto P_0c08cf24;
case 0x0c08cf26u: goto P_0c08cf26;
case 0x0c08cf28u: goto P_0c08cf28;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08ccf0: /* original 2fe6, guest PC 0x0c08ccf0 */
if(!s->budget--) { s->failed_pc=0x0c08ccf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ccf2;
P_0c08ccf2: /* original e048, guest PC 0x0c08ccf2 */
if(!s->budget--) { s->failed_pc=0x0c08ccf2u; return 0; }
r[0]=0x00000048u;
goto P_0c08ccf4;
P_0c08ccf4: /* original 2fd6, guest PC 0x0c08ccf4 */
if(!s->budget--) { s->failed_pc=0x0c08ccf4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ccf6;
P_0c08ccf6: /* original 6d43, guest PC 0x0c08ccf6 */
if(!s->budget--) { s->failed_pc=0x0c08ccf6u; return 0; }
r[13]=r[4];
goto P_0c08ccf8;
P_0c08ccf8: /* original 2fc6, guest PC 0x0c08ccf8 */
if(!s->budget--) { s->failed_pc=0x0c08ccf8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ccfa;
P_0c08ccfa: /* original 00dc, guest PC 0x0c08ccfa */
if(!s->budget--) { s->failed_pc=0x0c08ccfau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08ccfc;
P_0c08ccfc: /* original 4f22, guest PC 0x0c08ccfc */
if(!s->budget--) { s->failed_pc=0x0c08ccfcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ccfe;
P_0c08ccfe: /* original 8801, guest PC 0x0c08ccfe */
if(!s->budget--) { s->failed_pc=0x0c08ccfeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cd00;
P_0c08cd00: /* original 8d47, guest PC 0x0c08cd00 */
if(!s->budget--) { s->failed_pc=0x0c08cd00u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08cd92; }
goto P_0c08cd04;
P_0c08cd02: /* original 6e53, guest PC 0x0c08cd02 */
if(!s->budget--) { s->failed_pc=0x0c08cd02u; return 0; }
r[14]=r[5];
goto P_0c08cd04;
P_0c08cd04: /* original 60e2, guest PC 0x0c08cd04 */
if(!s->budget--) { s->failed_pc=0x0c08cd04u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08cd06;
P_0c08cd06: /* original cb01, guest PC 0x0c08cd06 */
if(!s->budget--) { s->failed_pc=0x0c08cd06u; return 0; }
r[0]|=1u;
goto P_0c08cd08;
P_0c08cd08: /* original 2e02, guest PC 0x0c08cd08 */
if(!s->budget--) { s->failed_pc=0x0c08cd08u; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08cd0a;
P_0c08cd0a: /* original e04c, guest PC 0x0c08cd0a */
if(!s->budget--) { s->failed_pc=0x0c08cd0au; return 0; }
r[0]=0x0000004cu;
goto P_0c08cd0c;
P_0c08cd0c: /* original 05ee, guest PC 0x0c08cd0c */
if(!s->budget--) { s->failed_pc=0x0c08cd0cu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c08cd0e;
P_0c08cd0e: /* original e066, guest PC 0x0c08cd0e */
if(!s->budget--) { s->failed_pc=0x0c08cd0eu; return 0; }
r[0]=0x00000066u;
goto P_0c08cd10;
P_0c08cd10: /* original 045d, guest PC 0x0c08cd10 */
if(!s->budget--) { s->failed_pc=0x0c08cd10u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c08cd12;
P_0c08cd12: /* original e064, guest PC 0x0c08cd12 */
if(!s->budget--) { s->failed_pc=0x0c08cd12u; return 0; }
r[0]=0x00000064u;
goto P_0c08cd14;
P_0c08cd14: /* original 055d, guest PC 0x0c08cd14 */
if(!s->budget--) { s->failed_pc=0x0c08cd14u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c08cd16;
P_0c08cd16: /* original 84e8, guest PC 0x0c08cd16 */
if(!s->budget--) { s->failed_pc=0x0c08cd16u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd18;
P_0c08cd18: /* original 655d, guest PC 0x0c08cd18 */
if(!s->budget--) { s->failed_pc=0x0c08cd18u; return 0; }
r[5]=r[5]&65535u;
goto P_0c08cd1a;
P_0c08cd1a: /* original 600c, guest PC 0x0c08cd1a */
if(!s->budget--) { s->failed_pc=0x0c08cd1au; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd1c;
P_0c08cd1c: /* original 880c, guest PC 0x0c08cd1c */
if(!s->budget--) { s->failed_pc=0x0c08cd1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c08cd1e;
P_0c08cd1e: /* original 345c, guest PC 0x0c08cd1e */
if(!s->budget--) { s->failed_pc=0x0c08cd1eu; return 0; }
r[4]+=r[5];
goto P_0c08cd20;
P_0c08cd20: /* original 8f01, guest PC 0x0c08cd20 */
if(!s->budget--) { s->failed_pc=0x0c08cd20u; return 0; }
cond=r[17]&1u;
r[5]=0x0000001eu;
if(!cond) { goto P_0c08cd26; }
goto P_0c08cd24;
P_0c08cd22: /* original e51e, guest PC 0x0c08cd22 */
if(!s->budget--) { s->failed_pc=0x0c08cd22u; return 0; }
r[5]=0x0000001eu;
goto P_0c08cd24;
P_0c08cd24: /* original e523, guest PC 0x0c08cd24 */
if(!s->budget--) { s->failed_pc=0x0c08cd24u; return 0; }
r[5]=0x00000023u;
goto P_0c08cd26;
P_0c08cd26: /* original 52e4, guest PC 0x0c08cd26 */
if(!s->budget--) { s->failed_pc=0x0c08cd26u; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c08cd28;
P_0c08cd28: /* original d31c, guest PC 0x0c08cd28 */
if(!s->budget--) { s->failed_pc=0x0c08cd28u; return 0; }
r[3]=read(ram,0x0c08cd9cu,4);
goto P_0c08cd2a;
P_0c08cd2a: /* original 2238, guest PC 0x0c08cd2a */
if(!s->budget--) { s->failed_pc=0x0c08cd2au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c08cd2c;
P_0c08cd2c: /* original 8d01, guest PC 0x0c08cd2c */
if(!s->budget--) { s->failed_pc=0x0c08cd2cu; return 0; }
cond=r[17]&1u;
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
if(cond) { goto P_0c08cd32; }
goto P_0c08cd30;
P_0c08cd2e: /* original 84e8, guest PC 0x0c08cd2e */
if(!s->budget--) { s->failed_pc=0x0c08cd2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd30;
P_0c08cd30: /* original 75f1, guest PC 0x0c08cd30 */
if(!s->budget--) { s->failed_pc=0x0c08cd30u; return 0; }
r[5]+=0xfffffff1u;
goto P_0c08cd32;
P_0c08cd32: /* original d11b, guest PC 0x0c08cd32 */
if(!s->budget--) { s->failed_pc=0x0c08cd32u; return 0; }
r[1]=read(ram,0x0c08cda0u,4);
goto P_0c08cd34;
P_0c08cd34: /* original 600c, guest PC 0x0c08cd34 */
if(!s->budget--) { s->failed_pc=0x0c08cd34u; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd36;
P_0c08cd36: /* original 3452, guest PC 0x0c08cd36 */
if(!s->budget--) { s->failed_pc=0x0c08cd36u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c08cd38;
P_0c08cd38: /* original 0c1c, guest PC 0x0c08cd38 */
if(!s->budget--) { s->failed_pc=0x0c08cd38u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08cd3a;
P_0c08cd3a: /* original 8f05, guest PC 0x0c08cd3a */
if(!s->budget--) { s->failed_pc=0x0c08cd3au; return 0; }
cond=r[17]&1u;
r[12]=r[12]&255u;
if(!cond) { goto P_0c08cd48; }
goto P_0c08cd3e;
P_0c08cd3c: /* original 6ccc, guest PC 0x0c08cd3c */
if(!s->budget--) { s->failed_pc=0x0c08cd3cu; return 0; }
r[12]=r[12]&255u;
goto P_0c08cd3e;
P_0c08cd3e: /* original 84e8, guest PC 0x0c08cd3e */
if(!s->budget--) { s->failed_pc=0x0c08cd3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd40;
P_0c08cd40: /* original d218, guest PC 0x0c08cd40 */
if(!s->budget--) { s->failed_pc=0x0c08cd40u; return 0; }
r[2]=read(ram,0x0c08cda4u,4);
goto P_0c08cd42;
P_0c08cd42: /* original 600c, guest PC 0x0c08cd42 */
if(!s->budget--) { s->failed_pc=0x0c08cd42u; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd44;
P_0c08cd44: /* original 0c2c, guest PC 0x0c08cd44 */
if(!s->budget--) { s->failed_pc=0x0c08cd44u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c08cd46;
P_0c08cd46: /* original 6ccc, guest PC 0x0c08cd46 */
if(!s->budget--) { s->failed_pc=0x0c08cd46u; return 0; }
r[12]=r[12]&255u;
goto P_0c08cd48;
P_0c08cd48: /* original d317, guest PC 0x0c08cd48 */
if(!s->budget--) { s->failed_pc=0x0c08cd48u; return 0; }
r[3]=read(ram,0x0c08cda8u,4);
goto P_0c08cd4a;
P_0c08cd4a: /* original 430b, guest PC 0x0c08cd4a */
if(!s->budget--) { s->failed_pc=0x0c08cd4au; return 0; }
target=r[3];
r[16]=code_base|0x0c08cd4eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cd4eu) { target=s->pc; goto dispatch; }
goto P_0c08cd4e;
P_0c08cd4c: /* original 0009, guest PC 0x0c08cd4c */
if(!s->budget--) { s->failed_pc=0x0c08cd4cu; return 0; }
goto P_0c08cd4e;
P_0c08cd4e: /* original d217, guest PC 0x0c08cd4e */
if(!s->budget--) { s->failed_pc=0x0c08cd4eu; return 0; }
r[2]=read(ram,0x0c08cdacu,4);
goto P_0c08cd50;
P_0c08cd50: /* original 6103, guest PC 0x0c08cd50 */
if(!s->budget--) { s->failed_pc=0x0c08cd50u; return 0; }
r[1]=r[0];
goto P_0c08cd52;
P_0c08cd52: /* original 420b, guest PC 0x0c08cd52 */
if(!s->budget--) { s->failed_pc=0x0c08cd52u; return 0; }
target=r[2];
r[16]=code_base|0x0c08cd56u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cd56u) { target=s->pc; goto dispatch; }
goto P_0c08cd56;
P_0c08cd54: /* original 60c3, guest PC 0x0c08cd54 */
if(!s->budget--) { s->failed_pc=0x0c08cd54u; return 0; }
r[0]=r[12];
goto P_0c08cd56;
P_0c08cd56: /* original 6403, guest PC 0x0c08cd56 */
if(!s->budget--) { s->failed_pc=0x0c08cd56u; return 0; }
r[4]=r[0];
goto P_0c08cd58;
P_0c08cd58: /* original 84e8, guest PC 0x0c08cd58 */
if(!s->budget--) { s->failed_pc=0x0c08cd58u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+8,1);
goto P_0c08cd5a;
P_0c08cd5a: /* original d115, guest PC 0x0c08cd5a */
if(!s->budget--) { s->failed_pc=0x0c08cd5au; return 0; }
r[1]=read(ram,0x0c08cdb0u,4);
goto P_0c08cd5c;
P_0c08cd5c: /* original 4400, guest PC 0x0c08cd5c */
if(!s->budget--) { s->failed_pc=0x0c08cd5cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cd5e;
P_0c08cd5e: /* original 600c, guest PC 0x0c08cd5e */
if(!s->budget--) { s->failed_pc=0x0c08cd5eu; return 0; }
r[0]=r[0]&255u;
goto P_0c08cd60;
P_0c08cd60: /* original 4008, guest PC 0x0c08cd60 */
if(!s->budget--) { s->failed_pc=0x0c08cd60u; return 0; }
r[0]<<=2;
goto P_0c08cd62;
P_0c08cd62: /* original 001e, guest PC 0x0c08cd62 */
if(!s->budget--) { s->failed_pc=0x0c08cd62u; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c08cd64;
P_0c08cd64: /* original e500, guest PC 0x0c08cd64 */
if(!s->budget--) { s->failed_pc=0x0c08cd64u; return 0; }
r[5]=0x00000000u;
goto P_0c08cd66;
P_0c08cd66: /* original 044d, guest PC 0x0c08cd66 */
if(!s->budget--) { s->failed_pc=0x0c08cd66u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cd68;
P_0c08cd68: /* original e028, guest PC 0x0c08cd68 */
if(!s->budget--) { s->failed_pc=0x0c08cd68u; return 0; }
r[0]=0x00000028u;
goto P_0c08cd6a;
P_0c08cd6a: /* original 644d, guest PC 0x0c08cd6a */
if(!s->budget--) { s->failed_pc=0x0c08cd6au; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cd6c;
P_0c08cd6c: /* original 0d45, guest PC 0x0c08cd6c */
if(!s->budget--) { s->failed_pc=0x0c08cd6cu; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08cd6e;
P_0c08cd6e: /* original e040, guest PC 0x0c08cd6e */
if(!s->budget--) { s->failed_pc=0x0c08cd6eu; return 0; }
r[0]=0x00000040u;
goto P_0c08cd70;
P_0c08cd70: /* original 1e4d, guest PC 0x0c08cd70 */
if(!s->budget--) { s->failed_pc=0x0c08cd70u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08cd72;
P_0c08cd72: /* original 0e56, guest PC 0x0c08cd72 */
if(!s->budget--) { s->failed_pc=0x0c08cd72u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08cd74;
P_0c08cd74: /* original b1f0, guest PC 0x0c08cd74 */
if(!s->budget--) { s->failed_pc=0x0c08cd74u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cd78u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cd78u) { target=s->pc; goto dispatch; }
goto P_0c08cd78;
P_0c08cd76: /* original 64e3, guest PC 0x0c08cd76 */
if(!s->budget--) { s->failed_pc=0x0c08cd76u; return 0; }
r[4]=r[14];
goto P_0c08cd78;
P_0c08cd78: /* original e200, guest PC 0x0c08cd78 */
if(!s->budget--) { s->failed_pc=0x0c08cd78u; return 0; }
r[2]=0x00000000u;
goto P_0c08cd7a;
P_0c08cd7a: /* original 55ee, guest PC 0x0c08cd7a */
if(!s->budget--) { s->failed_pc=0x0c08cd7au; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08cd7c;
P_0c08cd7c: /* original e02c, guest PC 0x0c08cd7c */
if(!s->budget--) { s->failed_pc=0x0c08cd7cu; return 0; }
r[0]=0x0000002cu;
goto P_0c08cd7e;
P_0c08cd7e: /* original 54ef, guest PC 0x0c08cd7e */
if(!s->budget--) { s->failed_pc=0x0c08cd7eu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08cd80;
P_0c08cd80: /* original 0d24, guest PC 0x0c08cd80 */
if(!s->budget--) { s->failed_pc=0x0c08cd80u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08cd82;
P_0c08cd82: /* original e02d, guest PC 0x0c08cd82 */
if(!s->budget--) { s->failed_pc=0x0c08cd82u; return 0; }
r[0]=0x0000002du;
goto P_0c08cd84;
P_0c08cd84: /* original 0d54, guest PC 0x0c08cd84 */
if(!s->budget--) { s->failed_pc=0x0c08cd84u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08cd86;
P_0c08cd86: /* original 6043, guest PC 0x0c08cd86 */
if(!s->budget--) { s->failed_pc=0x0c08cd86u; return 0; }
r[0]=r[4];
goto P_0c08cd88;
P_0c08cd88: /* original 81da, guest PC 0x0c08cd88 */
if(!s->budget--) { s->failed_pc=0x0c08cd88u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08cd8a;
P_0c08cd8a: /* original e048, guest PC 0x0c08cd8a */
if(!s->budget--) { s->failed_pc=0x0c08cd8au; return 0; }
r[0]=0x00000048u;
goto P_0c08cd8c;
P_0c08cd8c: /* original 03dc, guest PC 0x0c08cd8c */
if(!s->budget--) { s->failed_pc=0x0c08cd8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08cd8e;
P_0c08cd8e: /* original 7301, guest PC 0x0c08cd8e */
if(!s->budget--) { s->failed_pc=0x0c08cd8eu; return 0; }
r[3]+=0x00000001u;
goto P_0c08cd90;
P_0c08cd90: /* original 0d34, guest PC 0x0c08cd90 */
if(!s->budget--) { s->failed_pc=0x0c08cd90u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08cd92;
P_0c08cd92: /* original 4f26, guest PC 0x0c08cd92 */
if(!s->budget--) { s->failed_pc=0x0c08cd92u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cd94;
P_0c08cd94: /* original 6cf6, guest PC 0x0c08cd94 */
if(!s->budget--) { s->failed_pc=0x0c08cd94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cd96;
P_0c08cd96: /* original 6df6, guest PC 0x0c08cd96 */
if(!s->budget--) { s->failed_pc=0x0c08cd96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cd98;
P_0c08cd98: /* original 000b, guest PC 0x0c08cd98 */
if(!s->budget--) { s->failed_pc=0x0c08cd98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cd9a: /* original 6ef6, guest PC 0x0c08cd9a */
if(!s->budget--) { s->failed_pc=0x0c08cd9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08cd9cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08cd9cu; return 0; } return 1;
P_0c08cdb4: /* original 2fe6, guest PC 0x0c08cdb4 */
if(!s->budget--) { s->failed_pc=0x0c08cdb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cdb6;
P_0c08cdb6: /* original e048, guest PC 0x0c08cdb6 */
if(!s->budget--) { s->failed_pc=0x0c08cdb6u; return 0; }
r[0]=0x00000048u;
goto P_0c08cdb8;
P_0c08cdb8: /* original 2fd6, guest PC 0x0c08cdb8 */
if(!s->budget--) { s->failed_pc=0x0c08cdb8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cdba;
P_0c08cdba: /* original 6e43, guest PC 0x0c08cdba */
if(!s->budget--) { s->failed_pc=0x0c08cdbau; return 0; }
r[14]=r[4];
goto P_0c08cdbc;
P_0c08cdbc: /* original 2fc6, guest PC 0x0c08cdbc */
if(!s->budget--) { s->failed_pc=0x0c08cdbcu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cdbe;
P_0c08cdbe: /* original 6d53, guest PC 0x0c08cdbe */
if(!s->budget--) { s->failed_pc=0x0c08cdbeu; return 0; }
r[13]=r[5];
goto P_0c08cdc0;
P_0c08cdc0: /* original 2fb6, guest PC 0x0c08cdc0 */
if(!s->budget--) { s->failed_pc=0x0c08cdc0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cdc2;
P_0c08cdc2: /* original 04ec, guest PC 0x0c08cdc2 */
if(!s->budget--) { s->failed_pc=0x0c08cdc2u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cdc4;
P_0c08cdc4: /* original 4f22, guest PC 0x0c08cdc4 */
if(!s->budget--) { s->failed_pc=0x0c08cdc4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cdc6;
P_0c08cdc6: /* original 6043, guest PC 0x0c08cdc6 */
if(!s->budget--) { s->failed_pc=0x0c08cdc6u; return 0; }
r[0]=r[4];
goto P_0c08cdc8;
P_0c08cdc8: /* original 8801, guest PC 0x0c08cdc8 */
if(!s->budget--) { s->failed_pc=0x0c08cdc8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cdca;
P_0c08cdca: /* original 8d25, guest PC 0x0c08cdca */
if(!s->budget--) { s->failed_pc=0x0c08cdcau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c08ce18; }
goto P_0c08cdce;
P_0c08cdcc: /* original ec00, guest PC 0x0c08cdcc */
if(!s->budget--) { s->failed_pc=0x0c08cdccu; return 0; }
r[12]=0x00000000u;
goto P_0c08cdce;
P_0c08cdce: /* original 6043, guest PC 0x0c08cdce */
if(!s->budget--) { s->failed_pc=0x0c08cdceu; return 0; }
r[0]=r[4];
goto P_0c08cdd0;
P_0c08cdd0: /* original 8802, guest PC 0x0c08cdd0 */
if(!s->budget--) { s->failed_pc=0x0c08cdd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c08cdd2;
P_0c08cdd2: /* original 8942, guest PC 0x0c08cdd2 */
if(!s->budget--) { s->failed_pc=0x0c08cdd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ce5a; }
goto P_0c08cdd4;
P_0c08cdd4: /* original 60d2, guest PC 0x0c08cdd4 */
if(!s->budget--) { s->failed_pc=0x0c08cdd4u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cdd6;
P_0c08cdd6: /* original d235, guest PC 0x0c08cdd6 */
if(!s->budget--) { s->failed_pc=0x0c08cdd6u; return 0; }
r[2]=read(ram,0x0c08ceacu,4);
goto P_0c08cdd8;
P_0c08cdd8: /* original cb01, guest PC 0x0c08cdd8 */
if(!s->budget--) { s->failed_pc=0x0c08cdd8u; return 0; }
r[0]|=1u;
goto P_0c08cdda;
P_0c08cdda: /* original 420b, guest PC 0x0c08cdda */
if(!s->budget--) { s->failed_pc=0x0c08cddau; return 0; }
target=r[2];
r[16]=code_base|0x0c08cddeu;
write(ram,r[13],r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cddeu) { target=s->pc; goto dispatch; }
goto P_0c08cdde;
P_0c08cddc: /* original 2d02, guest PC 0x0c08cddc */
if(!s->budget--) { s->failed_pc=0x0c08cddcu; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cdde;
P_0c08cdde: /* original d334, guest PC 0x0c08cdde */
if(!s->budget--) { s->failed_pc=0x0c08cddeu; return 0; }
r[3]=read(ram,0x0c08ceb0u,4);
goto P_0c08cde0;
P_0c08cde0: /* original 6103, guest PC 0x0c08cde0 */
if(!s->budget--) { s->failed_pc=0x0c08cde0u; return 0; }
r[1]=r[0];
goto P_0c08cde2;
P_0c08cde2: /* original 430b, guest PC 0x0c08cde2 */
if(!s->budget--) { s->failed_pc=0x0c08cde2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08cde6u;
r[0]=0x00000009u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cde6u) { target=s->pc; goto dispatch; }
goto P_0c08cde6;
P_0c08cde4: /* original e009, guest PC 0x0c08cde4 */
if(!s->budget--) { s->failed_pc=0x0c08cde4u; return 0; }
r[0]=0x00000009u;
goto P_0c08cde6;
P_0c08cde6: /* original 6503, guest PC 0x0c08cde6 */
if(!s->budget--) { s->failed_pc=0x0c08cde6u; return 0; }
r[5]=r[0];
goto P_0c08cde8;
P_0c08cde8: /* original e04c, guest PC 0x0c08cde8 */
if(!s->budget--) { s->failed_pc=0x0c08cde8u; return 0; }
r[0]=0x0000004cu;
goto P_0c08cdea;
P_0c08cdea: /* original 0e55, guest PC 0x0c08cdea */
if(!s->budget--) { s->failed_pc=0x0c08cdeau; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c08cdec;
P_0c08cdec: /* original e028, guest PC 0x0c08cdec */
if(!s->budget--) { s->failed_pc=0x0c08cdecu; return 0; }
r[0]=0x00000028u;
goto P_0c08cdee;
P_0c08cdee: /* original 9459, guest PC 0x0c08cdee */
if(!s->budget--) { s->failed_pc=0x0c08cdeeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cea4u,2);
goto P_0c08cdf0;
P_0c08cdf0: /* original 345c, guest PC 0x0c08cdf0 */
if(!s->budget--) { s->failed_pc=0x0c08cdf0u; return 0; }
r[4]+=r[5];
goto P_0c08cdf2;
P_0c08cdf2: /* original 65c3, guest PC 0x0c08cdf2 */
if(!s->budget--) { s->failed_pc=0x0c08cdf2u; return 0; }
r[5]=r[12];
goto P_0c08cdf4;
P_0c08cdf4: /* original 0e45, guest PC 0x0c08cdf4 */
if(!s->budget--) { s->failed_pc=0x0c08cdf4u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cdf6;
P_0c08cdf6: /* original e040, guest PC 0x0c08cdf6 */
if(!s->budget--) { s->failed_pc=0x0c08cdf6u; return 0; }
r[0]=0x00000040u;
goto P_0c08cdf8;
P_0c08cdf8: /* original 1d4d, guest PC 0x0c08cdf8 */
if(!s->budget--) { s->failed_pc=0x0c08cdf8u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cdfa;
P_0c08cdfa: /* original 0d56, guest PC 0x0c08cdfa */
if(!s->budget--) { s->failed_pc=0x0c08cdfau; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cdfc;
P_0c08cdfc: /* original b1ac, guest PC 0x0c08cdfc */
if(!s->budget--) { s->failed_pc=0x0c08cdfcu; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08ce00u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ce00u) { target=s->pc; goto dispatch; }
goto P_0c08ce00;
P_0c08cdfe: /* original 64d3, guest PC 0x0c08cdfe */
if(!s->budget--) { s->failed_pc=0x0c08cdfeu; return 0; }
r[4]=r[13];
goto P_0c08ce00;
P_0c08ce00: /* original e02c, guest PC 0x0c08ce00 */
if(!s->budget--) { s->failed_pc=0x0c08ce00u; return 0; }
r[0]=0x0000002cu;
goto P_0c08ce02;
P_0c08ce02: /* original 54de, guest PC 0x0c08ce02 */
if(!s->budget--) { s->failed_pc=0x0c08ce02u; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08ce04;
P_0c08ce04: /* original 55df, guest PC 0x0c08ce04 */
if(!s->budget--) { s->failed_pc=0x0c08ce04u; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08ce06;
P_0c08ce06: /* original 0ec4, guest PC 0x0c08ce06 */
if(!s->budget--) { s->failed_pc=0x0c08ce06u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c08ce08;
P_0c08ce08: /* original e02d, guest PC 0x0c08ce08 */
if(!s->budget--) { s->failed_pc=0x0c08ce08u; return 0; }
r[0]=0x0000002du;
goto P_0c08ce0a;
P_0c08ce0a: /* original 0e44, guest PC 0x0c08ce0a */
if(!s->budget--) { s->failed_pc=0x0c08ce0au; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08ce0c;
P_0c08ce0c: /* original 6053, guest PC 0x0c08ce0c */
if(!s->budget--) { s->failed_pc=0x0c08ce0cu; return 0; }
r[0]=r[5];
goto P_0c08ce0e;
P_0c08ce0e: /* original 81ea, guest PC 0x0c08ce0e */
if(!s->budget--) { s->failed_pc=0x0c08ce0eu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08ce10;
P_0c08ce10: /* original e048, guest PC 0x0c08ce10 */
if(!s->budget--) { s->failed_pc=0x0c08ce10u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce12;
P_0c08ce12: /* original 03ec, guest PC 0x0c08ce12 */
if(!s->budget--) { s->failed_pc=0x0c08ce12u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ce14;
P_0c08ce14: /* original 7301, guest PC 0x0c08ce14 */
if(!s->budget--) { s->failed_pc=0x0c08ce14u; return 0; }
r[3]+=0x00000001u;
goto P_0c08ce16;
P_0c08ce16: /* original 0e34, guest PC 0x0c08ce16 */
if(!s->budget--) { s->failed_pc=0x0c08ce16u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08ce18;
P_0c08ce18: /* original 50d5, guest PC 0x0c08ce18 */
if(!s->budget--) { s->failed_pc=0x0c08ce18u; return 0; }
r[0]=read(ram,r[13]+20,4);
goto P_0c08ce1a;
P_0c08ce1a: /* original c808, guest PC 0x0c08ce1a */
if(!s->budget--) { s->failed_pc=0x0c08ce1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c08ce1c;
P_0c08ce1c: /* original 891d, guest PC 0x0c08ce1c */
if(!s->budget--) { s->failed_pc=0x0c08ce1cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08ce5a; }
goto P_0c08ce1e;
P_0c08ce1e: /* original d223, guest PC 0x0c08ce1e */
if(!s->budget--) { s->failed_pc=0x0c08ce1eu; return 0; }
r[2]=read(ram,0x0c08ceacu,4);
goto P_0c08ce20;
P_0c08ce20: /* original 9b41, guest PC 0x0c08ce20 */
if(!s->budget--) { s->failed_pc=0x0c08ce20u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cea6u,2);
goto P_0c08ce22;
P_0c08ce22: /* original 420b, guest PC 0x0c08ce22 */
if(!s->budget--) { s->failed_pc=0x0c08ce22u; return 0; }
target=r[2];
r[16]=code_base|0x0c08ce26u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ce26u) { target=s->pc; goto dispatch; }
goto P_0c08ce26;
P_0c08ce24: /* original 0009, guest PC 0x0c08ce24 */
if(!s->budget--) { s->failed_pc=0x0c08ce24u; return 0; }
goto P_0c08ce26;
P_0c08ce26: /* original e301, guest PC 0x0c08ce26 */
if(!s->budget--) { s->failed_pc=0x0c08ce26u; return 0; }
r[3]=0x00000001u;
goto P_0c08ce28;
P_0c08ce28: /* original 6403, guest PC 0x0c08ce28 */
if(!s->budget--) { s->failed_pc=0x0c08ce28u; return 0; }
r[4]=r[0];
goto P_0c08ce2a;
P_0c08ce2a: /* original 2439, guest PC 0x0c08ce2a */
if(!s->budget--) { s->failed_pc=0x0c08ce2au; return 0; }
r[4]&=r[3];
goto P_0c08ce2c;
P_0c08ce2c: /* original 2448, guest PC 0x0c08ce2c */
if(!s->budget--) { s->failed_pc=0x0c08ce2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c08ce2e;
P_0c08ce2e: /* original 8d01, guest PC 0x0c08ce2e */
if(!s->budget--) { s->failed_pc=0x0c08ce2eu; return 0; }
cond=r[17]&1u;
r[4]=r[12];
if(cond) { goto P_0c08ce34; }
goto P_0c08ce32;
P_0c08ce30: /* original 64c3, guest PC 0x0c08ce30 */
if(!s->budget--) { s->failed_pc=0x0c08ce30u; return 0; }
r[4]=r[12];
goto P_0c08ce32;
P_0c08ce32: /* original 9b39, guest PC 0x0c08ce32 */
if(!s->budget--) { s->failed_pc=0x0c08ce32u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cea8u,2);
goto P_0c08ce34;
P_0c08ce34: /* original e028, guest PC 0x0c08ce34 */
if(!s->budget--) { s->failed_pc=0x0c08ce34u; return 0; }
r[0]=0x00000028u;
goto P_0c08ce36;
P_0c08ce36: /* original 0eb5, guest PC 0x0c08ce36 */
if(!s->budget--) { s->failed_pc=0x0c08ce36u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c08ce38;
P_0c08ce38: /* original e040, guest PC 0x0c08ce38 */
if(!s->budget--) { s->failed_pc=0x0c08ce38u; return 0; }
r[0]=0x00000040u;
goto P_0c08ce3a;
P_0c08ce3a: /* original 1dbd, guest PC 0x0c08ce3a */
if(!s->budget--) { s->failed_pc=0x0c08ce3au; return 0; }
write(ram,r[13]+52,r[11],4);
goto P_0c08ce3c;
P_0c08ce3c: /* original 0d46, guest PC 0x0c08ce3c */
if(!s->budget--) { s->failed_pc=0x0c08ce3cu; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c08ce3e;
P_0c08ce3e: /* original b18b, guest PC 0x0c08ce3e */
if(!s->budget--) { s->failed_pc=0x0c08ce3eu; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08ce42u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ce42u) { target=s->pc; goto dispatch; }
goto P_0c08ce42;
P_0c08ce40: /* original 64d3, guest PC 0x0c08ce40 */
if(!s->budget--) { s->failed_pc=0x0c08ce40u; return 0; }
r[4]=r[13];
goto P_0c08ce42;
P_0c08ce42: /* original e02c, guest PC 0x0c08ce42 */
if(!s->budget--) { s->failed_pc=0x0c08ce42u; return 0; }
r[0]=0x0000002cu;
goto P_0c08ce44;
P_0c08ce44: /* original 55de, guest PC 0x0c08ce44 */
if(!s->budget--) { s->failed_pc=0x0c08ce44u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08ce46;
P_0c08ce46: /* original 54df, guest PC 0x0c08ce46 */
if(!s->budget--) { s->failed_pc=0x0c08ce46u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08ce48;
P_0c08ce48: /* original 0ec4, guest PC 0x0c08ce48 */
if(!s->budget--) { s->failed_pc=0x0c08ce48u; return 0; }
write(ram,r[14]+r[0],r[12],1);
goto P_0c08ce4a;
P_0c08ce4a: /* original e02d, guest PC 0x0c08ce4a */
if(!s->budget--) { s->failed_pc=0x0c08ce4au; return 0; }
r[0]=0x0000002du;
goto P_0c08ce4c;
P_0c08ce4c: /* original 0e54, guest PC 0x0c08ce4c */
if(!s->budget--) { s->failed_pc=0x0c08ce4cu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08ce4e;
P_0c08ce4e: /* original 6043, guest PC 0x0c08ce4e */
if(!s->budget--) { s->failed_pc=0x0c08ce4eu; return 0; }
r[0]=r[4];
goto P_0c08ce50;
P_0c08ce50: /* original 81ea, guest PC 0x0c08ce50 */
if(!s->budget--) { s->failed_pc=0x0c08ce50u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08ce52;
P_0c08ce52: /* original e048, guest PC 0x0c08ce52 */
if(!s->budget--) { s->failed_pc=0x0c08ce52u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce54;
P_0c08ce54: /* original 03ec, guest PC 0x0c08ce54 */
if(!s->budget--) { s->failed_pc=0x0c08ce54u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ce56;
P_0c08ce56: /* original 7301, guest PC 0x0c08ce56 */
if(!s->budget--) { s->failed_pc=0x0c08ce56u; return 0; }
r[3]+=0x00000001u;
goto P_0c08ce58;
P_0c08ce58: /* original 0e34, guest PC 0x0c08ce58 */
if(!s->budget--) { s->failed_pc=0x0c08ce58u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08ce5a;
P_0c08ce5a: /* original 4f26, guest PC 0x0c08ce5a */
if(!s->budget--) { s->failed_pc=0x0c08ce5au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ce5c;
P_0c08ce5c: /* original 6bf6, guest PC 0x0c08ce5c */
if(!s->budget--) { s->failed_pc=0x0c08ce5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08ce5e;
P_0c08ce5e: /* original 6cf6, guest PC 0x0c08ce5e */
if(!s->budget--) { s->failed_pc=0x0c08ce5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08ce60;
P_0c08ce60: /* original 6df6, guest PC 0x0c08ce60 */
if(!s->budget--) { s->failed_pc=0x0c08ce60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ce62;
P_0c08ce62: /* original 000b, guest PC 0x0c08ce62 */
if(!s->budget--) { s->failed_pc=0x0c08ce62u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ce64: /* original 6ef6, guest PC 0x0c08ce64 */
if(!s->budget--) { s->failed_pc=0x0c08ce64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08ce66;
P_0c08ce66: /* original 2fe6, guest PC 0x0c08ce66 */
if(!s->budget--) { s->failed_pc=0x0c08ce66u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ce68;
P_0c08ce68: /* original e048, guest PC 0x0c08ce68 */
if(!s->budget--) { s->failed_pc=0x0c08ce68u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce6a;
P_0c08ce6a: /* original 2fd6, guest PC 0x0c08ce6a */
if(!s->budget--) { s->failed_pc=0x0c08ce6au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ce6c;
P_0c08ce6c: /* original 6d43, guest PC 0x0c08ce6c */
if(!s->budget--) { s->failed_pc=0x0c08ce6cu; return 0; }
r[13]=r[4];
goto P_0c08ce6e;
P_0c08ce6e: /* original 2fc6, guest PC 0x0c08ce6e */
if(!s->budget--) { s->failed_pc=0x0c08ce6eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ce70;
P_0c08ce70: /* original 00dc, guest PC 0x0c08ce70 */
if(!s->budget--) { s->failed_pc=0x0c08ce70u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08ce72;
P_0c08ce72: /* original 4f22, guest PC 0x0c08ce72 */
if(!s->budget--) { s->failed_pc=0x0c08ce72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ce74;
P_0c08ce74: /* original 8801, guest PC 0x0c08ce74 */
if(!s->budget--) { s->failed_pc=0x0c08ce74u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08ce76;
P_0c08ce76: /* original 8d53, guest PC 0x0c08ce76 */
if(!s->budget--) { s->failed_pc=0x0c08ce76u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08cf20; }
goto P_0c08ce7a;
P_0c08ce78: /* original 6e53, guest PC 0x0c08ce78 */
if(!s->budget--) { s->failed_pc=0x0c08ce78u; return 0; }
r[14]=r[5];
goto P_0c08ce7a;
P_0c08ce7a: /* original 60e2, guest PC 0x0c08ce7a */
if(!s->budget--) { s->failed_pc=0x0c08ce7au; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08ce7c;
P_0c08ce7c: /* original cb01, guest PC 0x0c08ce7c */
if(!s->budget--) { s->failed_pc=0x0c08ce7cu; return 0; }
r[0]|=1u;
goto P_0c08ce7e;
P_0c08ce7e: /* original 2e02, guest PC 0x0c08ce7e */
if(!s->budget--) { s->failed_pc=0x0c08ce7eu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08ce80;
P_0c08ce80: /* original e048, guest PC 0x0c08ce80 */
if(!s->budget--) { s->failed_pc=0x0c08ce80u; return 0; }
r[0]=0x00000048u;
goto P_0c08ce82;
P_0c08ce82: /* original 04ee, guest PC 0x0c08ce82 */
if(!s->budget--) { s->failed_pc=0x0c08ce82u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c08ce84;
P_0c08ce84: /* original 9011, guest PC 0x0c08ce84 */
if(!s->budget--) { s->failed_pc=0x0c08ce84u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ceaau,2);
goto P_0c08ce86;
P_0c08ce86: /* original d30b, guest PC 0x0c08ce86 */
if(!s->budget--) { s->failed_pc=0x0c08ce86u; return 0; }
r[3]=read(ram,0x0c08ceb4u,4);
goto P_0c08ce88;
P_0c08ce88: /* original 044e, guest PC 0x0c08ce88 */
if(!s->budget--) { s->failed_pc=0x0c08ce88u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08ce8a;
P_0c08ce8a: /* original 2438, guest PC 0x0c08ce8a */
if(!s->budget--) { s->failed_pc=0x0c08ce8au; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08ce8c;
P_0c08ce8c: /* original 8916, guest PC 0x0c08ce8c */
if(!s->budget--) { s->failed_pc=0x0c08ce8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08cebc; }
goto P_0c08ce8e;
P_0c08ce8e: /* original d107, guest PC 0x0c08ce8e */
if(!s->budget--) { s->failed_pc=0x0c08ce8eu; return 0; }
r[1]=read(ram,0x0c08ceacu,4);
goto P_0c08ce90;
P_0c08ce90: /* original 410b, guest PC 0x0c08ce90 */
if(!s->budget--) { s->failed_pc=0x0c08ce90u; return 0; }
target=r[1];
r[16]=code_base|0x0c08ce94u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ce94u) { target=s->pc; goto dispatch; }
goto P_0c08ce94;
P_0c08ce92: /* original 0009, guest PC 0x0c08ce92 */
if(!s->budget--) { s->failed_pc=0x0c08ce92u; return 0; }
goto P_0c08ce94;
P_0c08ce94: /* original e503, guest PC 0x0c08ce94 */
if(!s->budget--) { s->failed_pc=0x0c08ce94u; return 0; }
r[5]=0x00000003u;
goto P_0c08ce96;
P_0c08ce96: /* original 6403, guest PC 0x0c08ce96 */
if(!s->budget--) { s->failed_pc=0x0c08ce96u; return 0; }
r[4]=r[0];
goto P_0c08ce98;
P_0c08ce98: /* original 2549, guest PC 0x0c08ce98 */
if(!s->budget--) { s->failed_pc=0x0c08ce98u; return 0; }
r[5]&=r[4];
goto P_0c08ce9a;
P_0c08ce9a: /* original d007, guest PC 0x0c08ce9a */
if(!s->budget--) { s->failed_pc=0x0c08ce9au; return 0; }
r[0]=read(ram,0x0c08ceb8u,4);
goto P_0c08ce9c;
P_0c08ce9c: /* original 6453, guest PC 0x0c08ce9c */
if(!s->budget--) { s->failed_pc=0x0c08ce9cu; return 0; }
r[4]=r[5];
goto P_0c08ce9e;
P_0c08ce9e: /* original 4400, guest PC 0x0c08ce9e */
if(!s->budget--) { s->failed_pc=0x0c08ce9eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cea0;
P_0c08cea0: /* original a028, guest PC 0x0c08cea0 */
if(!s->budget--) { s->failed_pc=0x0c08cea0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cef4;
P_0c08cea2: /* original 044d, guest PC 0x0c08cea2 */
if(!s->budget--) { s->failed_pc=0x0c08cea2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
if(!vf3_matrix_family(0x0c08cea4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08cea4u; return 0; } return 1;
P_0c08cebc: /* original e04c, guest PC 0x0c08cebc */
if(!s->budget--) { s->failed_pc=0x0c08cebcu; return 0; }
r[0]=0x0000004cu;
goto P_0c08cebe;
P_0c08cebe: /* original d24c, guest PC 0x0c08cebe */
if(!s->budget--) { s->failed_pc=0x0c08cebeu; return 0; }
r[2]=read(ram,0x0c08cff0u,4);
goto P_0c08cec0;
P_0c08cec0: /* original 0cee, guest PC 0x0c08cec0 */
if(!s->budget--) { s->failed_pc=0x0c08cec0u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c08cec2;
P_0c08cec2: /* original e061, guest PC 0x0c08cec2 */
if(!s->budget--) { s->failed_pc=0x0c08cec2u; return 0; }
r[0]=0x00000061u;
goto P_0c08cec4;
P_0c08cec4: /* original 0ccc, guest PC 0x0c08cec4 */
if(!s->budget--) { s->failed_pc=0x0c08cec4u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08cec6;
P_0c08cec6: /* original d049, guest PC 0x0c08cec6 */
if(!s->budget--) { s->failed_pc=0x0c08cec6u; return 0; }
r[0]=read(ram,0x0c08cfecu,4);
goto P_0c08cec8;
P_0c08cec8: /* original 6ccc, guest PC 0x0c08cec8 */
if(!s->budget--) { s->failed_pc=0x0c08cec8u; return 0; }
r[12]=r[12]&255u;
goto P_0c08ceca;
P_0c08ceca: /* original 0ccc, guest PC 0x0c08ceca */
if(!s->budget--) { s->failed_pc=0x0c08cecau; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c08cecc;
P_0c08cecc: /* original 420b, guest PC 0x0c08cecc */
if(!s->budget--) { s->failed_pc=0x0c08ceccu; return 0; }
target=r[2];
r[16]=code_base|0x0c08ced0u;
r[12]=r[12]&255u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ced0u) { target=s->pc; goto dispatch; }
goto P_0c08ced0;
P_0c08cece: /* original 6ccc, guest PC 0x0c08cece */
if(!s->budget--) { s->failed_pc=0x0c08ceceu; return 0; }
r[12]=r[12]&255u;
goto P_0c08ced0;
P_0c08ced0: /* original d348, guest PC 0x0c08ced0 */
if(!s->budget--) { s->failed_pc=0x0c08ced0u; return 0; }
r[3]=read(ram,0x0c08cff4u,4);
goto P_0c08ced2;
P_0c08ced2: /* original 6103, guest PC 0x0c08ced2 */
if(!s->budget--) { s->failed_pc=0x0c08ced2u; return 0; }
r[1]=r[0];
goto P_0c08ced4;
P_0c08ced4: /* original 430b, guest PC 0x0c08ced4 */
if(!s->budget--) { s->failed_pc=0x0c08ced4u; return 0; }
target=r[3];
r[16]=code_base|0x0c08ced8u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ced8u) { target=s->pc; goto dispatch; }
goto P_0c08ced8;
P_0c08ced6: /* original 60c3, guest PC 0x0c08ced6 */
if(!s->budget--) { s->failed_pc=0x0c08ced6u; return 0; }
r[0]=r[12];
goto P_0c08ced8;
P_0c08ced8: /* original 6c03, guest PC 0x0c08ced8 */
if(!s->budget--) { s->failed_pc=0x0c08ced8u; return 0; }
r[12]=r[0];
goto P_0c08ceda;
P_0c08ceda: /* original e04c, guest PC 0x0c08ceda */
if(!s->budget--) { s->failed_pc=0x0c08cedau; return 0; }
r[0]=0x0000004cu;
goto P_0c08cedc;
P_0c08cedc: /* original 00ee, guest PC 0x0c08cedc */
if(!s->budget--) { s->failed_pc=0x0c08cedcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c08cede;
P_0c08cede: /* original e161, guest PC 0x0c08cede */
if(!s->budget--) { s->failed_pc=0x0c08cedeu; return 0; }
r[1]=0x00000061u;
goto P_0c08cee0;
P_0c08cee0: /* original d345, guest PC 0x0c08cee0 */
if(!s->budget--) { s->failed_pc=0x0c08cee0u; return 0; }
r[3]=read(ram,0x0c08cff8u,4);
goto P_0c08cee2;
P_0c08cee2: /* original 64c3, guest PC 0x0c08cee2 */
if(!s->budget--) { s->failed_pc=0x0c08cee2u; return 0; }
r[4]=r[12];
goto P_0c08cee4;
P_0c08cee4: /* original 001c, guest PC 0x0c08cee4 */
if(!s->budget--) { s->failed_pc=0x0c08cee4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c08cee6;
P_0c08cee6: /* original 4400, guest PC 0x0c08cee6 */
if(!s->budget--) { s->failed_pc=0x0c08cee6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cee8;
P_0c08cee8: /* original 600c, guest PC 0x0c08cee8 */
if(!s->budget--) { s->failed_pc=0x0c08cee8u; return 0; }
r[0]=r[0]&255u;
goto P_0c08ceea;
P_0c08ceea: /* original 4008, guest PC 0x0c08ceea */
if(!s->budget--) { s->failed_pc=0x0c08ceeau; return 0; }
r[0]<<=2;
goto P_0c08ceec;
P_0c08ceec: /* original 4008, guest PC 0x0c08ceec */
if(!s->budget--) { s->failed_pc=0x0c08ceecu; return 0; }
r[0]<<=2;
goto P_0c08ceee;
P_0c08ceee: /* original 330c, guest PC 0x0c08ceee */
if(!s->budget--) { s->failed_pc=0x0c08ceeeu; return 0; }
r[3]+=r[0];
goto P_0c08cef0;
P_0c08cef0: /* original 343c, guest PC 0x0c08cef0 */
if(!s->budget--) { s->failed_pc=0x0c08cef0u; return 0; }
r[4]+=r[3];
goto P_0c08cef2;
P_0c08cef2: /* original 6441, guest PC 0x0c08cef2 */
if(!s->budget--) { s->failed_pc=0x0c08cef2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[4]=tmp;
goto P_0c08cef4;
P_0c08cef4: /* original e028, guest PC 0x0c08cef4 */
if(!s->budget--) { s->failed_pc=0x0c08cef4u; return 0; }
r[0]=0x00000028u;
goto P_0c08cef6;
P_0c08cef6: /* original 644d, guest PC 0x0c08cef6 */
if(!s->budget--) { s->failed_pc=0x0c08cef6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cef8;
P_0c08cef8: /* original 0d45, guest PC 0x0c08cef8 */
if(!s->budget--) { s->failed_pc=0x0c08cef8u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08cefa;
P_0c08cefa: /* original e040, guest PC 0x0c08cefa */
if(!s->budget--) { s->failed_pc=0x0c08cefau; return 0; }
r[0]=0x00000040u;
goto P_0c08cefc;
P_0c08cefc: /* original e500, guest PC 0x0c08cefc */
if(!s->budget--) { s->failed_pc=0x0c08cefcu; return 0; }
r[5]=0x00000000u;
goto P_0c08cefe;
P_0c08cefe: /* original 1e4d, guest PC 0x0c08cefe */
if(!s->budget--) { s->failed_pc=0x0c08cefeu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08cf00;
P_0c08cf00: /* original 0e56, guest PC 0x0c08cf00 */
if(!s->budget--) { s->failed_pc=0x0c08cf00u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08cf02;
P_0c08cf02: /* original b129, guest PC 0x0c08cf02 */
if(!s->budget--) { s->failed_pc=0x0c08cf02u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cf06u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf06u) { target=s->pc; goto dispatch; }
goto P_0c08cf06;
P_0c08cf04: /* original 64e3, guest PC 0x0c08cf04 */
if(!s->budget--) { s->failed_pc=0x0c08cf04u; return 0; }
r[4]=r[14];
goto P_0c08cf06;
P_0c08cf06: /* original e200, guest PC 0x0c08cf06 */
if(!s->budget--) { s->failed_pc=0x0c08cf06u; return 0; }
r[2]=0x00000000u;
goto P_0c08cf08;
P_0c08cf08: /* original 55ee, guest PC 0x0c08cf08 */
if(!s->budget--) { s->failed_pc=0x0c08cf08u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08cf0a;
P_0c08cf0a: /* original e02c, guest PC 0x0c08cf0a */
if(!s->budget--) { s->failed_pc=0x0c08cf0au; return 0; }
r[0]=0x0000002cu;
goto P_0c08cf0c;
P_0c08cf0c: /* original 54ef, guest PC 0x0c08cf0c */
if(!s->budget--) { s->failed_pc=0x0c08cf0cu; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08cf0e;
P_0c08cf0e: /* original 0d24, guest PC 0x0c08cf0e */
if(!s->budget--) { s->failed_pc=0x0c08cf0eu; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08cf10;
P_0c08cf10: /* original e02d, guest PC 0x0c08cf10 */
if(!s->budget--) { s->failed_pc=0x0c08cf10u; return 0; }
r[0]=0x0000002du;
goto P_0c08cf12;
P_0c08cf12: /* original 0d54, guest PC 0x0c08cf12 */
if(!s->budget--) { s->failed_pc=0x0c08cf12u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08cf14;
P_0c08cf14: /* original 6043, guest PC 0x0c08cf14 */
if(!s->budget--) { s->failed_pc=0x0c08cf14u; return 0; }
r[0]=r[4];
goto P_0c08cf16;
P_0c08cf16: /* original 81da, guest PC 0x0c08cf16 */
if(!s->budget--) { s->failed_pc=0x0c08cf16u; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08cf18;
P_0c08cf18: /* original e048, guest PC 0x0c08cf18 */
if(!s->budget--) { s->failed_pc=0x0c08cf18u; return 0; }
r[0]=0x00000048u;
goto P_0c08cf1a;
P_0c08cf1a: /* original 03dc, guest PC 0x0c08cf1a */
if(!s->budget--) { s->failed_pc=0x0c08cf1au; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08cf1c;
P_0c08cf1c: /* original 7301, guest PC 0x0c08cf1c */
if(!s->budget--) { s->failed_pc=0x0c08cf1cu; return 0; }
r[3]+=0x00000001u;
goto P_0c08cf1e;
P_0c08cf1e: /* original 0d34, guest PC 0x0c08cf1e */
if(!s->budget--) { s->failed_pc=0x0c08cf1eu; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08cf20;
P_0c08cf20: /* original 4f26, guest PC 0x0c08cf20 */
if(!s->budget--) { s->failed_pc=0x0c08cf20u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cf22;
P_0c08cf22: /* original 6cf6, guest PC 0x0c08cf22 */
if(!s->budget--) { s->failed_pc=0x0c08cf22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cf24;
P_0c08cf24: /* original 6df6, guest PC 0x0c08cf24 */
if(!s->budget--) { s->failed_pc=0x0c08cf24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cf26;
P_0c08cf26: /* original 000b, guest PC 0x0c08cf26 */
if(!s->budget--) { s->failed_pc=0x0c08cf26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cf28: /* original 6ef6, guest PC 0x0c08cf28 */
if(!s->budget--) { s->failed_pc=0x0c08cf28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08cf2au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
