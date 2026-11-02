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
int vf3_away_batch59_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08cc3eu: goto P_0c08cc3e;
case 0x0c08cc40u: goto P_0c08cc40;
case 0x0c08cc42u: goto P_0c08cc42;
case 0x0c08cc44u: goto P_0c08cc44;
case 0x0c08cc46u: goto P_0c08cc46;
case 0x0c08cc48u: goto P_0c08cc48;
case 0x0c08cc4au: goto P_0c08cc4a;
case 0x0c08cc4cu: goto P_0c08cc4c;
case 0x0c08cc4eu: goto P_0c08cc4e;
case 0x0c08cc50u: goto P_0c08cc50;
case 0x0c08cc52u: goto P_0c08cc52;
case 0x0c08cc54u: goto P_0c08cc54;
case 0x0c08cc56u: goto P_0c08cc56;
case 0x0c08cc58u: goto P_0c08cc58;
case 0x0c08cc5au: goto P_0c08cc5a;
case 0x0c08cc5cu: goto P_0c08cc5c;
case 0x0c08cc5eu: goto P_0c08cc5e;
case 0x0c08cc60u: goto P_0c08cc60;
case 0x0c08cc62u: goto P_0c08cc62;
case 0x0c08cc64u: goto P_0c08cc64;
case 0x0c08cc66u: goto P_0c08cc66;
case 0x0c08cc68u: goto P_0c08cc68;
case 0x0c08cc6au: goto P_0c08cc6a;
case 0x0c08cc6cu: goto P_0c08cc6c;
case 0x0c08cc6eu: goto P_0c08cc6e;
case 0x0c08cc70u: goto P_0c08cc70;
case 0x0c08cc72u: goto P_0c08cc72;
case 0x0c08cc74u: goto P_0c08cc74;
case 0x0c08cc76u: goto P_0c08cc76;
case 0x0c08cc78u: goto P_0c08cc78;
case 0x0c08cc7au: goto P_0c08cc7a;
case 0x0c08cc7cu: goto P_0c08cc7c;
case 0x0c08cc7eu: goto P_0c08cc7e;
case 0x0c08cc80u: goto P_0c08cc80;
case 0x0c08cc82u: goto P_0c08cc82;
case 0x0c08cc84u: goto P_0c08cc84;
case 0x0c08cc86u: goto P_0c08cc86;
case 0x0c08cc88u: goto P_0c08cc88;
case 0x0c08cc8au: goto P_0c08cc8a;
case 0x0c08cc8cu: goto P_0c08cc8c;
case 0x0c08cc8eu: goto P_0c08cc8e;
case 0x0c08cc90u: goto P_0c08cc90;
case 0x0c08cc92u: goto P_0c08cc92;
case 0x0c08cc94u: goto P_0c08cc94;
case 0x0c08cc96u: goto P_0c08cc96;
case 0x0c08cc98u: goto P_0c08cc98;
case 0x0c08cc9au: goto P_0c08cc9a;
case 0x0c08cc9cu: goto P_0c08cc9c;
case 0x0c08cc9eu: goto P_0c08cc9e;
case 0x0c08cca0u: goto P_0c08cca0;
case 0x0c08cca2u: goto P_0c08cca2;
case 0x0c08cca4u: goto P_0c08cca4;
case 0x0c08cca6u: goto P_0c08cca6;
case 0x0c08cca8u: goto P_0c08cca8;
case 0x0c08ccaau: goto P_0c08ccaa;
case 0x0c08ccacu: goto P_0c08ccac;
case 0x0c08ccaeu: goto P_0c08ccae;
case 0x0c08ccb0u: goto P_0c08ccb0;
case 0x0c08ccb2u: goto P_0c08ccb2;
case 0x0c08ccb4u: goto P_0c08ccb4;
case 0x0c08ccb6u: goto P_0c08ccb6;
case 0x0c08ccb8u: goto P_0c08ccb8;
case 0x0c08ccbau: goto P_0c08ccba;
case 0x0c08ccbcu: goto P_0c08ccbc;
case 0x0c08ccbeu: goto P_0c08ccbe;
case 0x0c08ccc0u: goto P_0c08ccc0;
case 0x0c08ccc2u: goto P_0c08ccc2;
case 0x0c08ccc4u: goto P_0c08ccc4;
case 0x0c08ccc6u: goto P_0c08ccc6;
case 0x0c08ccc8u: goto P_0c08ccc8;
case 0x0c08cccau: goto P_0c08ccca;
case 0x0c08ccccu: goto P_0c08cccc;
case 0x0c08ccceu: goto P_0c08ccce;
case 0x0c08ccd0u: goto P_0c08ccd0;
case 0x0c08ccd2u: goto P_0c08ccd2;
case 0x0c08ccd4u: goto P_0c08ccd4;
case 0x0c08ccd6u: goto P_0c08ccd6;
case 0x0c08ccd8u: goto P_0c08ccd8;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c08cc3e: /* original 2fe6, guest PC 0x0c08cc3e */
if(!s->budget--) { s->failed_pc=0x0c08cc3eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc40;
P_0c08cc40: /* original 6e43, guest PC 0x0c08cc40 */
if(!s->budget--) { s->failed_pc=0x0c08cc40u; return 0; }
r[14]=r[4];
goto P_0c08cc42;
P_0c08cc42: /* original e048, guest PC 0x0c08cc42 */
if(!s->budget--) { s->failed_pc=0x0c08cc42u; return 0; }
r[0]=0x00000048u;
goto P_0c08cc44;
P_0c08cc44: /* original 2fd6, guest PC 0x0c08cc44 */
if(!s->budget--) { s->failed_pc=0x0c08cc44u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc46;
P_0c08cc46: /* original 00ec, guest PC 0x0c08cc46 */
if(!s->budget--) { s->failed_pc=0x0c08cc46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cc48;
P_0c08cc48: /* original 4f22, guest PC 0x0c08cc48 */
if(!s->budget--) { s->failed_pc=0x0c08cc48u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cc4a;
P_0c08cc4a: /* original 8801, guest PC 0x0c08cc4a */
if(!s->budget--) { s->failed_pc=0x0c08cc4au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cc4c;
P_0c08cc4c: /* original 8d1b, guest PC 0x0c08cc4c */
if(!s->budget--) { s->failed_pc=0x0c08cc4cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08cc86; }
goto P_0c08cc50;
P_0c08cc4e: /* original 6d53, guest PC 0x0c08cc4e */
if(!s->budget--) { s->failed_pc=0x0c08cc4eu; return 0; }
r[13]=r[5];
goto P_0c08cc50;
P_0c08cc50: /* original 60d2, guest PC 0x0c08cc50 */
if(!s->budget--) { s->failed_pc=0x0c08cc50u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cc52;
P_0c08cc52: /* original e500, guest PC 0x0c08cc52 */
if(!s->budget--) { s->failed_pc=0x0c08cc52u; return 0; }
r[5]=0x00000000u;
goto P_0c08cc54;
P_0c08cc54: /* original cb01, guest PC 0x0c08cc54 */
if(!s->budget--) { s->failed_pc=0x0c08cc54u; return 0; }
r[0]|=1u;
goto P_0c08cc56;
P_0c08cc56: /* original 2d02, guest PC 0x0c08cc56 */
if(!s->budget--) { s->failed_pc=0x0c08cc56u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cc58;
P_0c08cc58: /* original e028, guest PC 0x0c08cc58 */
if(!s->budget--) { s->failed_pc=0x0c08cc58u; return 0; }
r[0]=0x00000028u;
goto P_0c08cc5a;
P_0c08cc5a: /* original 943f, guest PC 0x0c08cc5a */
if(!s->budget--) { s->failed_pc=0x0c08cc5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ccdcu,2);
goto P_0c08cc5c;
P_0c08cc5c: /* original 0e45, guest PC 0x0c08cc5c */
if(!s->budget--) { s->failed_pc=0x0c08cc5cu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cc5e;
P_0c08cc5e: /* original e040, guest PC 0x0c08cc5e */
if(!s->budget--) { s->failed_pc=0x0c08cc5eu; return 0; }
r[0]=0x00000040u;
goto P_0c08cc60;
P_0c08cc60: /* original 1d4d, guest PC 0x0c08cc60 */
if(!s->budget--) { s->failed_pc=0x0c08cc60u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cc62;
P_0c08cc62: /* original 0d56, guest PC 0x0c08cc62 */
if(!s->budget--) { s->failed_pc=0x0c08cc62u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cc64;
P_0c08cc64: /* original b278, guest PC 0x0c08cc64 */
if(!s->budget--) { s->failed_pc=0x0c08cc64u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cc68u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cc68u) { target=s->pc; goto dispatch; }
goto P_0c08cc68;
P_0c08cc66: /* original 64d3, guest PC 0x0c08cc66 */
if(!s->budget--) { s->failed_pc=0x0c08cc66u; return 0; }
r[4]=r[13];
goto P_0c08cc68;
P_0c08cc68: /* original e200, guest PC 0x0c08cc68 */
if(!s->budget--) { s->failed_pc=0x0c08cc68u; return 0; }
r[2]=0x00000000u;
goto P_0c08cc6a;
P_0c08cc6a: /* original 54de, guest PC 0x0c08cc6a */
if(!s->budget--) { s->failed_pc=0x0c08cc6au; return 0; }
r[4]=read(ram,r[13]+56,4);
goto P_0c08cc6c;
P_0c08cc6c: /* original e02c, guest PC 0x0c08cc6c */
if(!s->budget--) { s->failed_pc=0x0c08cc6cu; return 0; }
r[0]=0x0000002cu;
goto P_0c08cc6e;
P_0c08cc6e: /* original 55df, guest PC 0x0c08cc6e */
if(!s->budget--) { s->failed_pc=0x0c08cc6eu; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c08cc70;
P_0c08cc70: /* original 0e24, guest PC 0x0c08cc70 */
if(!s->budget--) { s->failed_pc=0x0c08cc70u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08cc72;
P_0c08cc72: /* original e02d, guest PC 0x0c08cc72 */
if(!s->budget--) { s->failed_pc=0x0c08cc72u; return 0; }
r[0]=0x0000002du;
goto P_0c08cc74;
P_0c08cc74: /* original 0e44, guest PC 0x0c08cc74 */
if(!s->budget--) { s->failed_pc=0x0c08cc74u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c08cc76;
P_0c08cc76: /* original 6053, guest PC 0x0c08cc76 */
if(!s->budget--) { s->failed_pc=0x0c08cc76u; return 0; }
r[0]=r[5];
goto P_0c08cc78;
P_0c08cc78: /* original 81ea, guest PC 0x0c08cc78 */
if(!s->budget--) { s->failed_pc=0x0c08cc78u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08cc7a;
P_0c08cc7a: /* original e010, guest PC 0x0c08cc7a */
if(!s->budget--) { s->failed_pc=0x0c08cc7au; return 0; }
r[0]=0x00000010u;
goto P_0c08cc7c;
P_0c08cc7c: /* original 81ef, guest PC 0x0c08cc7c */
if(!s->budget--) { s->failed_pc=0x0c08cc7cu; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c08cc7e;
P_0c08cc7e: /* original e048, guest PC 0x0c08cc7e */
if(!s->budget--) { s->failed_pc=0x0c08cc7eu; return 0; }
r[0]=0x00000048u;
goto P_0c08cc80;
P_0c08cc80: /* original 03ec, guest PC 0x0c08cc80 */
if(!s->budget--) { s->failed_pc=0x0c08cc80u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cc82;
P_0c08cc82: /* original 7301, guest PC 0x0c08cc82 */
if(!s->budget--) { s->failed_pc=0x0c08cc82u; return 0; }
r[3]+=0x00000001u;
goto P_0c08cc84;
P_0c08cc84: /* original 0e34, guest PC 0x0c08cc84 */
if(!s->budget--) { s->failed_pc=0x0c08cc84u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08cc86;
P_0c08cc86: /* original 4f26, guest PC 0x0c08cc86 */
if(!s->budget--) { s->failed_pc=0x0c08cc86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cc88;
P_0c08cc88: /* original 6df6, guest PC 0x0c08cc88 */
if(!s->budget--) { s->failed_pc=0x0c08cc88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cc8a;
P_0c08cc8a: /* original 000b, guest PC 0x0c08cc8a */
if(!s->budget--) { s->failed_pc=0x0c08cc8au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cc8c: /* original 6ef6, guest PC 0x0c08cc8c */
if(!s->budget--) { s->failed_pc=0x0c08cc8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08cc8e;
P_0c08cc8e: /* original 2fe6, guest PC 0x0c08cc8e */
if(!s->budget--) { s->failed_pc=0x0c08cc8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc90;
P_0c08cc90: /* original 6e43, guest PC 0x0c08cc90 */
if(!s->budget--) { s->failed_pc=0x0c08cc90u; return 0; }
r[14]=r[4];
goto P_0c08cc92;
P_0c08cc92: /* original e048, guest PC 0x0c08cc92 */
if(!s->budget--) { s->failed_pc=0x0c08cc92u; return 0; }
r[0]=0x00000048u;
goto P_0c08cc94;
P_0c08cc94: /* original 2fd6, guest PC 0x0c08cc94 */
if(!s->budget--) { s->failed_pc=0x0c08cc94u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cc96;
P_0c08cc96: /* original 00ec, guest PC 0x0c08cc96 */
if(!s->budget--) { s->failed_pc=0x0c08cc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cc98;
P_0c08cc98: /* original 4f22, guest PC 0x0c08cc98 */
if(!s->budget--) { s->failed_pc=0x0c08cc98u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cc9a;
P_0c08cc9a: /* original 8801, guest PC 0x0c08cc9a */
if(!s->budget--) { s->failed_pc=0x0c08cc9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cc9c;
P_0c08cc9c: /* original 8d19, guest PC 0x0c08cc9c */
if(!s->budget--) { s->failed_pc=0x0c08cc9cu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08ccd2; }
goto P_0c08cca0;
P_0c08cc9e: /* original 6d53, guest PC 0x0c08cc9e */
if(!s->budget--) { s->failed_pc=0x0c08cc9eu; return 0; }
r[13]=r[5];
goto P_0c08cca0;
P_0c08cca0: /* original 60d2, guest PC 0x0c08cca0 */
if(!s->budget--) { s->failed_pc=0x0c08cca0u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cca2;
P_0c08cca2: /* original e500, guest PC 0x0c08cca2 */
if(!s->budget--) { s->failed_pc=0x0c08cca2u; return 0; }
r[5]=0x00000000u;
goto P_0c08cca4;
P_0c08cca4: /* original cb01, guest PC 0x0c08cca4 */
if(!s->budget--) { s->failed_pc=0x0c08cca4u; return 0; }
r[0]|=1u;
goto P_0c08cca6;
P_0c08cca6: /* original 2d02, guest PC 0x0c08cca6 */
if(!s->budget--) { s->failed_pc=0x0c08cca6u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cca8;
P_0c08cca8: /* original e028, guest PC 0x0c08cca8 */
if(!s->budget--) { s->failed_pc=0x0c08cca8u; return 0; }
r[0]=0x00000028u;
goto P_0c08ccaa;
P_0c08ccaa: /* original 9418, guest PC 0x0c08ccaa */
if(!s->budget--) { s->failed_pc=0x0c08ccaau; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08ccdeu,2);
goto P_0c08ccac;
P_0c08ccac: /* original 0e45, guest PC 0x0c08ccac */
if(!s->budget--) { s->failed_pc=0x0c08ccacu; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08ccae;
P_0c08ccae: /* original e040, guest PC 0x0c08ccae */
if(!s->budget--) { s->failed_pc=0x0c08ccaeu; return 0; }
r[0]=0x00000040u;
goto P_0c08ccb0;
P_0c08ccb0: /* original 1d4d, guest PC 0x0c08ccb0 */
if(!s->budget--) { s->failed_pc=0x0c08ccb0u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08ccb2;
P_0c08ccb2: /* original 0d56, guest PC 0x0c08ccb2 */
if(!s->budget--) { s->failed_pc=0x0c08ccb2u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08ccb4;
P_0c08ccb4: /* original b250, guest PC 0x0c08ccb4 */
if(!s->budget--) { s->failed_pc=0x0c08ccb4u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08ccb8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08ccb8u) { target=s->pc; goto dispatch; }
goto P_0c08ccb8;
P_0c08ccb6: /* original 64d3, guest PC 0x0c08ccb6 */
if(!s->budget--) { s->failed_pc=0x0c08ccb6u; return 0; }
r[4]=r[13];
goto P_0c08ccb8;
P_0c08ccb8: /* original e200, guest PC 0x0c08ccb8 */
if(!s->budget--) { s->failed_pc=0x0c08ccb8u; return 0; }
r[2]=0x00000000u;
goto P_0c08ccba;
P_0c08ccba: /* original 55de, guest PC 0x0c08ccba */
if(!s->budget--) { s->failed_pc=0x0c08ccbau; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08ccbc;
P_0c08ccbc: /* original e02c, guest PC 0x0c08ccbc */
if(!s->budget--) { s->failed_pc=0x0c08ccbcu; return 0; }
r[0]=0x0000002cu;
goto P_0c08ccbe;
P_0c08ccbe: /* original 54df, guest PC 0x0c08ccbe */
if(!s->budget--) { s->failed_pc=0x0c08ccbeu; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08ccc0;
P_0c08ccc0: /* original 0e24, guest PC 0x0c08ccc0 */
if(!s->budget--) { s->failed_pc=0x0c08ccc0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08ccc2;
P_0c08ccc2: /* original e02d, guest PC 0x0c08ccc2 */
if(!s->budget--) { s->failed_pc=0x0c08ccc2u; return 0; }
r[0]=0x0000002du;
goto P_0c08ccc4;
P_0c08ccc4: /* original 0e54, guest PC 0x0c08ccc4 */
if(!s->budget--) { s->failed_pc=0x0c08ccc4u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08ccc6;
P_0c08ccc6: /* original 6043, guest PC 0x0c08ccc6 */
if(!s->budget--) { s->failed_pc=0x0c08ccc6u; return 0; }
r[0]=r[4];
goto P_0c08ccc8;
P_0c08ccc8: /* original 81ea, guest PC 0x0c08ccc8 */
if(!s->budget--) { s->failed_pc=0x0c08ccc8u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08ccca;
P_0c08ccca: /* original e048, guest PC 0x0c08ccca */
if(!s->budget--) { s->failed_pc=0x0c08cccau; return 0; }
r[0]=0x00000048u;
goto P_0c08cccc;
P_0c08cccc: /* original 03ec, guest PC 0x0c08cccc */
if(!s->budget--) { s->failed_pc=0x0c08ccccu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ccce;
P_0c08ccce: /* original 7301, guest PC 0x0c08ccce */
if(!s->budget--) { s->failed_pc=0x0c08ccceu; return 0; }
r[3]+=0x00000001u;
goto P_0c08ccd0;
P_0c08ccd0: /* original 0e34, guest PC 0x0c08ccd0 */
if(!s->budget--) { s->failed_pc=0x0c08ccd0u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08ccd2;
P_0c08ccd2: /* original 4f26, guest PC 0x0c08ccd2 */
if(!s->budget--) { s->failed_pc=0x0c08ccd2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08ccd4;
P_0c08ccd4: /* original 6df6, guest PC 0x0c08ccd4 */
if(!s->budget--) { s->failed_pc=0x0c08ccd4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08ccd6;
P_0c08ccd6: /* original 000b, guest PC 0x0c08ccd6 */
if(!s->budget--) { s->failed_pc=0x0c08ccd6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ccd8: /* original 6ef6, guest PC 0x0c08ccd8 */
if(!s->budget--) { s->failed_pc=0x0c08ccd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08ccdau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ccdau; return 0; } return 1;
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
if(!vf3_matrix_family(0x0c08ce66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ce66u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
