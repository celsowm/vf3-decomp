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
int vf3_away_batch10_adapter_17(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06cae6u: goto P_0c06cae6;
case 0x0c06cae8u: goto P_0c06cae8;
case 0x0c06caeau: goto P_0c06caea;
case 0x0c06caecu: goto P_0c06caec;
case 0x0c06caeeu: goto P_0c06caee;
case 0x0c06caf0u: goto P_0c06caf0;
case 0x0c06caf2u: goto P_0c06caf2;
case 0x0c06caf4u: goto P_0c06caf4;
case 0x0c06caf6u: goto P_0c06caf6;
case 0x0c06caf8u: goto P_0c06caf8;
case 0x0c06cafau: goto P_0c06cafa;
case 0x0c06cafcu: goto P_0c06cafc;
case 0x0c06cafeu: goto P_0c06cafe;
case 0x0c06cb00u: goto P_0c06cb00;
case 0x0c06cb02u: goto P_0c06cb02;
case 0x0c06cb04u: goto P_0c06cb04;
case 0x0c06cb06u: goto P_0c06cb06;
case 0x0c06cb08u: goto P_0c06cb08;
case 0x0c06cb0au: goto P_0c06cb0a;
case 0x0c06cb0cu: goto P_0c06cb0c;
case 0x0c06cb0eu: goto P_0c06cb0e;
case 0x0c06cb10u: goto P_0c06cb10;
case 0x0c06cb12u: goto P_0c06cb12;
case 0x0c06cb14u: goto P_0c06cb14;
case 0x0c06cb16u: goto P_0c06cb16;
case 0x0c06cb18u: goto P_0c06cb18;
case 0x0c06cb1au: goto P_0c06cb1a;
case 0x0c06cb1cu: goto P_0c06cb1c;
case 0x0c06cb1eu: goto P_0c06cb1e;
case 0x0c06cb20u: goto P_0c06cb20;
case 0x0c06cb22u: goto P_0c06cb22;
case 0x0c06cb24u: goto P_0c06cb24;
case 0x0c06cb26u: goto P_0c06cb26;
case 0x0c06cb28u: goto P_0c06cb28;
case 0x0c06cb2au: goto P_0c06cb2a;
case 0x0c06cb2cu: goto P_0c06cb2c;
case 0x0c06cb2eu: goto P_0c06cb2e;
case 0x0c06cb30u: goto P_0c06cb30;
case 0x0c06cb32u: goto P_0c06cb32;
case 0x0c06cb34u: goto P_0c06cb34;
case 0x0c06cb36u: goto P_0c06cb36;
case 0x0c06cb38u: goto P_0c06cb38;
case 0x0c06cb60u: goto P_0c06cb60;
case 0x0c06cb62u: goto P_0c06cb62;
case 0x0c06cb64u: goto P_0c06cb64;
case 0x0c06cb66u: goto P_0c06cb66;
case 0x0c06cb68u: goto P_0c06cb68;
case 0x0c06cb6au: goto P_0c06cb6a;
case 0x0c06cb6cu: goto P_0c06cb6c;
case 0x0c06cb6eu: goto P_0c06cb6e;
case 0x0c06cb70u: goto P_0c06cb70;
case 0x0c06cb72u: goto P_0c06cb72;
case 0x0c06cb74u: goto P_0c06cb74;
case 0x0c06cb76u: goto P_0c06cb76;
case 0x0c06cb78u: goto P_0c06cb78;
case 0x0c06cb7au: goto P_0c06cb7a;
case 0x0c06cb7cu: goto P_0c06cb7c;
case 0x0c06cb7eu: goto P_0c06cb7e;
case 0x0c06cb80u: goto P_0c06cb80;
case 0x0c06cb82u: goto P_0c06cb82;
case 0x0c06cb84u: goto P_0c06cb84;
case 0x0c06cb86u: goto P_0c06cb86;
case 0x0c06cb88u: goto P_0c06cb88;
case 0x0c06cb8au: goto P_0c06cb8a;
case 0x0c06cb8cu: goto P_0c06cb8c;
case 0x0c06cb8eu: goto P_0c06cb8e;
case 0x0c06cb90u: goto P_0c06cb90;
case 0x0c06cb92u: goto P_0c06cb92;
case 0x0c06cb94u: goto P_0c06cb94;
case 0x0c06cb96u: goto P_0c06cb96;
case 0x0c06cb98u: goto P_0c06cb98;
case 0x0c06cb9au: goto P_0c06cb9a;
case 0x0c06cb9cu: goto P_0c06cb9c;
case 0x0c06cb9eu: goto P_0c06cb9e;
case 0x0c06cba0u: goto P_0c06cba0;
case 0x0c06cba2u: goto P_0c06cba2;
case 0x0c06cba4u: goto P_0c06cba4;
case 0x0c06cba6u: goto P_0c06cba6;
case 0x0c06cba8u: goto P_0c06cba8;
case 0x0c06cbaau: goto P_0c06cbaa;
case 0x0c06cbacu: goto P_0c06cbac;
case 0x0c06cbaeu: goto P_0c06cbae;
case 0x0c06cbb0u: goto P_0c06cbb0;
case 0x0c06cbb2u: goto P_0c06cbb2;
case 0x0c06cbb4u: goto P_0c06cbb4;
case 0x0c06cbb6u: goto P_0c06cbb6;
case 0x0c06cbb8u: goto P_0c06cbb8;
case 0x0c06cbbau: goto P_0c06cbba;
case 0x0c06cbbcu: goto P_0c06cbbc;
case 0x0c06cbbeu: goto P_0c06cbbe;
case 0x0c06cbc0u: goto P_0c06cbc0;
case 0x0c06cbc2u: goto P_0c06cbc2;
case 0x0c06cbc4u: goto P_0c06cbc4;
case 0x0c06cbc6u: goto P_0c06cbc6;
case 0x0c06cbc8u: goto P_0c06cbc8;
case 0x0c06cbcau: goto P_0c06cbca;
case 0x0c06cbccu: goto P_0c06cbcc;
case 0x0c06cbceu: goto P_0c06cbce;
case 0x0c06cbd0u: goto P_0c06cbd0;
case 0x0c06cbd2u: goto P_0c06cbd2;
case 0x0c06cbd4u: goto P_0c06cbd4;
case 0x0c06cbd6u: goto P_0c06cbd6;
case 0x0c06cbd8u: goto P_0c06cbd8;
case 0x0c06cbdau: goto P_0c06cbda;
case 0x0c06cbdcu: goto P_0c06cbdc;
case 0x0c06cbdeu: goto P_0c06cbde;
case 0x0c06cbe0u: goto P_0c06cbe0;
case 0x0c06cbe2u: goto P_0c06cbe2;
case 0x0c06cbe4u: goto P_0c06cbe4;
case 0x0c06cbe6u: goto P_0c06cbe6;
case 0x0c06cbe8u: goto P_0c06cbe8;
case 0x0c06cbeau: goto P_0c06cbea;
case 0x0c06cbecu: goto P_0c06cbec;
case 0x0c06cbeeu: goto P_0c06cbee;
case 0x0c06cbf0u: goto P_0c06cbf0;
case 0x0c06cbf2u: goto P_0c06cbf2;
case 0x0c06cbf4u: goto P_0c06cbf4;
case 0x0c06cbf6u: goto P_0c06cbf6;
case 0x0c06cbf8u: goto P_0c06cbf8;
case 0x0c06cbfau: goto P_0c06cbfa;
case 0x0c06cbfcu: goto P_0c06cbfc;
case 0x0c06cbfeu: goto P_0c06cbfe;
case 0x0c06cc00u: goto P_0c06cc00;
case 0x0c06cc02u: goto P_0c06cc02;
case 0x0c06cc04u: goto P_0c06cc04;
case 0x0c06cc06u: goto P_0c06cc06;
case 0x0c06cc08u: goto P_0c06cc08;
case 0x0c06cc0au: goto P_0c06cc0a;
case 0x0c06cc0cu: goto P_0c06cc0c;
case 0x0c06cc0eu: goto P_0c06cc0e;
case 0x0c06cc10u: goto P_0c06cc10;
case 0x0c06cc12u: goto P_0c06cc12;
case 0x0c06cc14u: goto P_0c06cc14;
case 0x0c06cc16u: goto P_0c06cc16;
case 0x0c06cc18u: goto P_0c06cc18;
case 0x0c06cc1au: goto P_0c06cc1a;
case 0x0c06cc1cu: goto P_0c06cc1c;
case 0x0c06cdf2u: goto P_0c06cdf2;
case 0x0c06cdf4u: goto P_0c06cdf4;
case 0x0c06cdf6u: goto P_0c06cdf6;
case 0x0c06cdf8u: goto P_0c06cdf8;
case 0x0c06cdfau: goto P_0c06cdfa;
case 0x0c06cdfcu: goto P_0c06cdfc;
case 0x0c06cdfeu: goto P_0c06cdfe;
case 0x0c06ce00u: goto P_0c06ce00;
case 0x0c06ce02u: goto P_0c06ce02;
case 0x0c06ce04u: goto P_0c06ce04;
case 0x0c06ce06u: goto P_0c06ce06;
case 0x0c06ce08u: goto P_0c06ce08;
case 0x0c06ce0au: goto P_0c06ce0a;
case 0x0c06ce0cu: goto P_0c06ce0c;
case 0x0c06ce0eu: goto P_0c06ce0e;
case 0x0c06ce10u: goto P_0c06ce10;
case 0x0c06ce12u: goto P_0c06ce12;
case 0x0c06ce14u: goto P_0c06ce14;
case 0x0c06ce16u: goto P_0c06ce16;
case 0x0c06ce18u: goto P_0c06ce18;
case 0x0c06ce1au: goto P_0c06ce1a;
case 0x0c06ce1cu: goto P_0c06ce1c;
case 0x0c06ce1eu: goto P_0c06ce1e;
case 0x0c06ce20u: goto P_0c06ce20;
case 0x0c06ce22u: goto P_0c06ce22;
case 0x0c06ce24u: goto P_0c06ce24;
case 0x0c06ce26u: goto P_0c06ce26;
case 0x0c06ce28u: goto P_0c06ce28;
case 0x0c06ce2au: goto P_0c06ce2a;
case 0x0c06ce54u: goto P_0c06ce54;
case 0x0c06ce56u: goto P_0c06ce56;
case 0x0c06ce58u: goto P_0c06ce58;
case 0x0c06ce5au: goto P_0c06ce5a;
case 0x0c06ce5cu: goto P_0c06ce5c;
case 0x0c06ce5eu: goto P_0c06ce5e;
case 0x0c06ce60u: goto P_0c06ce60;
case 0x0c06ce62u: goto P_0c06ce62;
case 0x0c06ce64u: goto P_0c06ce64;
case 0x0c06ce66u: goto P_0c06ce66;
case 0x0c06ce68u: goto P_0c06ce68;
case 0x0c06ce6au: goto P_0c06ce6a;
case 0x0c06ce6cu: goto P_0c06ce6c;
case 0x0c06ce6eu: goto P_0c06ce6e;
case 0x0c06ce70u: goto P_0c06ce70;
case 0x0c06ce72u: goto P_0c06ce72;
case 0x0c06ce74u: goto P_0c06ce74;
case 0x0c06ce76u: goto P_0c06ce76;
case 0x0c06ce78u: goto P_0c06ce78;
case 0x0c06ce7au: goto P_0c06ce7a;
case 0x0c06ce7cu: goto P_0c06ce7c;
case 0x0c06ce7eu: goto P_0c06ce7e;
case 0x0c06ce80u: goto P_0c06ce80;
case 0x0c06ce82u: goto P_0c06ce82;
case 0x0c06ce84u: goto P_0c06ce84;
case 0x0c06ce86u: goto P_0c06ce86;
case 0x0c06ce88u: goto P_0c06ce88;
case 0x0c06ce8au: goto P_0c06ce8a;
case 0x0c06ce8cu: goto P_0c06ce8c;
case 0x0c06ce8eu: goto P_0c06ce8e;
case 0x0c06ce90u: goto P_0c06ce90;
case 0x0c06ce92u: goto P_0c06ce92;
case 0x0c06ce94u: goto P_0c06ce94;
case 0x0c06ce96u: goto P_0c06ce96;
case 0x0c06ce98u: goto P_0c06ce98;
case 0x0c06ce9au: goto P_0c06ce9a;
case 0x0c06ce9cu: goto P_0c06ce9c;
case 0x0c06ce9eu: goto P_0c06ce9e;
case 0x0c06cea0u: goto P_0c06cea0;
case 0x0c06cea2u: goto P_0c06cea2;
case 0x0c06cea4u: goto P_0c06cea4;
case 0x0c06cea6u: goto P_0c06cea6;
case 0x0c06cea8u: goto P_0c06cea8;
case 0x0c06ceaau: goto P_0c06ceaa;
case 0x0c06ceacu: goto P_0c06ceac;
case 0x0c06ceaeu: goto P_0c06ceae;
case 0x0c06ceb0u: goto P_0c06ceb0;
case 0x0c06ceb2u: goto P_0c06ceb2;
case 0x0c06ceb4u: goto P_0c06ceb4;
case 0x0c06ceb6u: goto P_0c06ceb6;
case 0x0c06ceb8u: goto P_0c06ceb8;
case 0x0c06cebau: goto P_0c06ceba;
case 0x0c06cebcu: goto P_0c06cebc;
case 0x0c06cebeu: goto P_0c06cebe;
case 0x0c06cec0u: goto P_0c06cec0;
case 0x0c06cec2u: goto P_0c06cec2;
case 0x0c06cec4u: goto P_0c06cec4;
case 0x0c06cec6u: goto P_0c06cec6;
case 0x0c06cec8u: goto P_0c06cec8;
case 0x0c06cecau: goto P_0c06ceca;
case 0x0c06ceccu: goto P_0c06cecc;
case 0x0c06ceceu: goto P_0c06cece;
case 0x0c06ced0u: goto P_0c06ced0;
case 0x0c06ced2u: goto P_0c06ced2;
case 0x0c06ced4u: goto P_0c06ced4;
case 0x0c06ced6u: goto P_0c06ced6;
case 0x0c06ced8u: goto P_0c06ced8;
case 0x0c06cedau: goto P_0c06ceda;
case 0x0c06cedcu: goto P_0c06cedc;
case 0x0c06cedeu: goto P_0c06cede;
case 0x0c06cee0u: goto P_0c06cee0;
case 0x0c06cee2u: goto P_0c06cee2;
case 0x0c06cee4u: goto P_0c06cee4;
case 0x0c06cee6u: goto P_0c06cee6;
case 0x0c06cee8u: goto P_0c06cee8;
case 0x0c06ceeau: goto P_0c06ceea;
case 0x0c06ceecu: goto P_0c06ceec;
case 0x0c06ceeeu: goto P_0c06ceee;
case 0x0c06cef0u: goto P_0c06cef0;
case 0x0c06cef2u: goto P_0c06cef2;
case 0x0c06cef4u: goto P_0c06cef4;
case 0x0c06cef6u: goto P_0c06cef6;
case 0x0c06cef8u: goto P_0c06cef8;
case 0x0c06cefau: goto P_0c06cefa;
case 0x0c06cefcu: goto P_0c06cefc;
case 0x0c06cefeu: goto P_0c06cefe;
case 0x0c06cf00u: goto P_0c06cf00;
case 0x0c06cf02u: goto P_0c06cf02;
case 0x0c06cf04u: goto P_0c06cf04;
case 0x0c06cf06u: goto P_0c06cf06;
case 0x0c06cf08u: goto P_0c06cf08;
case 0x0c06cf0au: goto P_0c06cf0a;
case 0x0c06cf0cu: goto P_0c06cf0c;
case 0x0c06cf0eu: goto P_0c06cf0e;
case 0x0c06cf10u: goto P_0c06cf10;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06cae6: /* original 2fe6, guest PC 0x0c06cae6 */
if(!s->budget--) { s->failed_pc=0x0c06cae6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cae8;
P_0c06cae8: /* original 4400, guest PC 0x0c06cae8 */
if(!s->budget--) { s->failed_pc=0x0c06cae8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06caea;
P_0c06caea: /* original 2fd6, guest PC 0x0c06caea */
if(!s->budget--) { s->failed_pc=0x0c06caeau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caec;
P_0c06caec: /* original e307, guest PC 0x0c06caec */
if(!s->budget--) { s->failed_pc=0x0c06caecu; return 0; }
r[3]=0x00000007u;
goto P_0c06caee;
P_0c06caee: /* original 2fc6, guest PC 0x0c06caee */
if(!s->budget--) { s->failed_pc=0x0c06caeeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf0;
P_0c06caf0: /* original 6d43, guest PC 0x0c06caf0 */
if(!s->budget--) { s->failed_pc=0x0c06caf0u; return 0; }
r[13]=r[4];
goto P_0c06caf2;
P_0c06caf2: /* original 2fb6, guest PC 0x0c06caf2 */
if(!s->budget--) { s->failed_pc=0x0c06caf2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf4;
P_0c06caf4: /* original 453d, guest PC 0x0c06caf4 */
if(!s->budget--) { s->failed_pc=0x0c06caf4u; return 0; }
r[5]=(r[3]&0x80000000u)?((r[3]&31u)?r[5]>>((-r[3])&31u):0):r[5]<<(r[3]&31u);
goto P_0c06caf6;
P_0c06caf6: /* original 2fa6, guest PC 0x0c06caf6 */
if(!s->budget--) { s->failed_pc=0x0c06caf6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06caf8;
P_0c06caf8: /* original 2d5b, guest PC 0x0c06caf8 */
if(!s->budget--) { s->failed_pc=0x0c06caf8u; return 0; }
r[13]|=r[5];
goto P_0c06cafa;
P_0c06cafa: /* original 2f96, guest PC 0x0c06cafa */
if(!s->budget--) { s->failed_pc=0x0c06cafau; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cafc;
P_0c06cafc: /* original 6e63, guest PC 0x0c06cafc */
if(!s->budget--) { s->failed_pc=0x0c06cafcu; return 0; }
r[14]=r[6];
goto P_0c06cafe;
P_0c06cafe: /* original d514, guest PC 0x0c06cafe */
if(!s->budget--) { s->failed_pc=0x0c06cafeu; return 0; }
r[5]=read(ram,0x0c06cb50u,4);
goto P_0c06cb00;
P_0c06cb00: /* original 901f, guest PC 0x0c06cb00 */
if(!s->budget--) { s->failed_pc=0x0c06cb00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb42u,2);
goto P_0c06cb02;
P_0c06cb02: /* original 4f22, guest PC 0x0c06cb02 */
if(!s->budget--) { s->failed_pc=0x0c06cb02u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cb04;
P_0c06cb04: /* original 045c, guest PC 0x0c06cb04 */
if(!s->budget--) { s->failed_pc=0x0c06cb04u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb06;
P_0c06cb06: /* original da13, guest PC 0x0c06cb06 */
if(!s->budget--) { s->failed_pc=0x0c06cb06u; return 0; }
r[10]=read(ram,0x0c06cb54u,4);
goto P_0c06cb08;
P_0c06cb08: /* original 6043, guest PC 0x0c06cb08 */
if(!s->budget--) { s->failed_pc=0x0c06cb08u; return 0; }
r[0]=r[4];
goto P_0c06cb0a;
P_0c06cb0a: /* original 5bf7, guest PC 0x0c06cb0a */
if(!s->budget--) { s->failed_pc=0x0c06cb0au; return 0; }
r[11]=read(ram,r[15]+28,4);
goto P_0c06cb0c;
P_0c06cb0c: /* original 8801, guest PC 0x0c06cb0c */
if(!s->budget--) { s->failed_pc=0x0c06cb0cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb0e;
P_0c06cb0e: /* original 8d2e, guest PC 0x0c06cb0e */
if(!s->budget--) { s->failed_pc=0x0c06cb0eu; return 0; }
cond=r[17]&1u;
r[9]=r[7];
if(cond) { goto P_0c06cb6e; }
goto P_0c06cb12;
P_0c06cb10: /* original 6973, guest PC 0x0c06cb10 */
if(!s->budget--) { s->failed_pc=0x0c06cb10u; return 0; }
r[9]=r[7];
goto P_0c06cb12;
P_0c06cb12: /* original 9017, guest PC 0x0c06cb12 */
if(!s->budget--) { s->failed_pc=0x0c06cb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cb44u,2);
goto P_0c06cb14;
P_0c06cb14: /* original d411, guest PC 0x0c06cb14 */
if(!s->budget--) { s->failed_pc=0x0c06cb14u; return 0; }
r[4]=read(ram,0x0c06cb5cu,4);
goto P_0c06cb16;
P_0c06cb16: /* original 0c5c, guest PC 0x0c06cb16 */
if(!s->budget--) { s->failed_pc=0x0c06cb16u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c06cb18;
P_0c06cb18: /* original d50f, guest PC 0x0c06cb18 */
if(!s->budget--) { s->failed_pc=0x0c06cb18u; return 0; }
r[5]=read(ram,0x0c06cb58u,4);
goto P_0c06cb1a;
P_0c06cb1a: /* original 60c3, guest PC 0x0c06cb1a */
if(!s->budget--) { s->failed_pc=0x0c06cb1au; return 0; }
r[0]=r[12];
goto P_0c06cb1c;
P_0c06cb1c: /* original 8801, guest PC 0x0c06cb1c */
if(!s->budget--) { s->failed_pc=0x0c06cb1cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb1e;
P_0c06cb1e: /* original 8d04, guest PC 0x0c06cb1e */
if(!s->budget--) { s->failed_pc=0x0c06cb1eu; return 0; }
cond=r[17]&1u;
r[6]=0x00000001u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb22;
P_0c06cb20: /* original e601, guest PC 0x0c06cb20 */
if(!s->budget--) { s->failed_pc=0x0c06cb20u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb22;
P_0c06cb22: /* original 3c90, guest PC 0x0c06cb22 */
if(!s->budget--) { s->failed_pc=0x0c06cb22u; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[9])!=0);
goto P_0c06cb24;
P_0c06cb24: /* original 8901, guest PC 0x0c06cb24 */
if(!s->budget--) { s->failed_pc=0x0c06cb24u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb2a; }
goto P_0c06cb26;
P_0c06cb26: /* original 2998, guest PC 0x0c06cb26 */
if(!s->budget--) { s->failed_pc=0x0c06cb26u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c06cb28;
P_0c06cb28: /* original 8b37, guest PC 0x0c06cb28 */
if(!s->budget--) { s->failed_pc=0x0c06cb28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06cb9a; }
goto P_0c06cb2a;
P_0c06cb2a: /* original 60b3, guest PC 0x0c06cb2a */
if(!s->budget--) { s->failed_pc=0x0c06cb2au; return 0; }
r[0]=r[11];
goto P_0c06cb2c;
P_0c06cb2c: /* original 8801, guest PC 0x0c06cb2c */
if(!s->budget--) { s->failed_pc=0x0c06cb2cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cb2e;
P_0c06cb2e: /* original 8925, guest PC 0x0c06cb2e */
if(!s->budget--) { s->failed_pc=0x0c06cb2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cb7c; }
goto P_0c06cb30;
P_0c06cb30: /* original 3e66, guest PC 0x0c06cb30 */
if(!s->budget--) { s->failed_pc=0x0c06cb30u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb32;
P_0c06cb32: /* original 8d15, guest PC 0x0c06cb32 */
if(!s->budget--) { s->failed_pc=0x0c06cb32u; return 0; }
cond=r[17]&1u;
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cb60; }
goto P_0c06cb36;
P_0c06cb34: /* original 2fb6, guest PC 0x0c06cb34 */
if(!s->budget--) { s->failed_pc=0x0c06cb34u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb36;
P_0c06cb36: /* original a014, guest PC 0x0c06cb36 */
if(!s->budget--) { s->failed_pc=0x0c06cb36u; return 0; }
r[6]=r[5];
goto P_0c06cb62;
P_0c06cb38: /* original 6653, guest PC 0x0c06cb38 */
if(!s->budget--) { s->failed_pc=0x0c06cb38u; return 0; }
r[6]=r[5];
if(!vf3_matrix_family(0x0c06cb3au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cb3au; return 0; } return 1;
P_0c06cb60: /* original 6643, guest PC 0x0c06cb60 */
if(!s->budget--) { s->failed_pc=0x0c06cb60u; return 0; }
r[6]=r[4];
goto P_0c06cb62;
P_0c06cb62: /* original 65a3, guest PC 0x0c06cb62 */
if(!s->budget--) { s->failed_pc=0x0c06cb62u; return 0; }
r[5]=r[10];
goto P_0c06cb64;
P_0c06cb64: /* original 67e3, guest PC 0x0c06cb64 */
if(!s->budget--) { s->failed_pc=0x0c06cb64u; return 0; }
r[7]=r[14];
goto P_0c06cb66;
P_0c06cb66: /* original bc4e, guest PC 0x0c06cb66 */
if(!s->budget--) { s->failed_pc=0x0c06cb66u; return 0; }
target=code_base|0x0c06c406u; r[16]=code_base|0x0c06cb6au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb6au) { target=s->pc; goto dispatch; }
goto P_0c06cb6a;
P_0c06cb68: /* original 64d3, guest PC 0x0c06cb68 */
if(!s->budget--) { s->failed_pc=0x0c06cb68u; return 0; }
r[4]=r[13];
goto P_0c06cb6a;
P_0c06cb6a: /* original a033, guest PC 0x0c06cb6a */
if(!s->budget--) { s->failed_pc=0x0c06cb6au; return 0; }
r[15]+=0x00000004u;
goto P_0c06cbd4;
P_0c06cb6c: /* original 7f04, guest PC 0x0c06cb6c */
if(!s->budget--) { s->failed_pc=0x0c06cb6cu; return 0; }
r[15]+=0x00000004u;
goto P_0c06cb6e;
P_0c06cb6e: /* original d23c, guest PC 0x0c06cb6e */
if(!s->budget--) { s->failed_pc=0x0c06cb6eu; return 0; }
r[2]=read(ram,0x0c06cc60u,4);
goto P_0c06cb70;
P_0c06cb70: /* original e601, guest PC 0x0c06cb70 */
if(!s->budget--) { s->failed_pc=0x0c06cb70u; return 0; }
r[6]=0x00000001u;
goto P_0c06cb72;
P_0c06cb72: /* original d53a, guest PC 0x0c06cb72 */
if(!s->budget--) { s->failed_pc=0x0c06cb72u; return 0; }
r[5]=read(ram,0x0c06cc5cu,4);
goto P_0c06cb74;
P_0c06cb74: /* original 420b, guest PC 0x0c06cb74 */
if(!s->budget--) { s->failed_pc=0x0c06cb74u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cb78u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb78u) { target=s->pc; goto dispatch; }
goto P_0c06cb78;
P_0c06cb76: /* original 64d3, guest PC 0x0c06cb76 */
if(!s->budget--) { s->failed_pc=0x0c06cb76u; return 0; }
r[4]=r[13];
goto P_0c06cb78;
P_0c06cb78: /* original a02c, guest PC 0x0c06cb78 */
if(!s->budget--) { s->failed_pc=0x0c06cb78u; return 0; }
goto P_0c06cbd4;
P_0c06cb7a: /* original 0009, guest PC 0x0c06cb7a */
if(!s->budget--) { s->failed_pc=0x0c06cb7au; return 0; }
goto P_0c06cb7c;
P_0c06cb7c: /* original 3e66, guest PC 0x0c06cb7c */
if(!s->budget--) { s->failed_pc=0x0c06cb7cu; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cb7e;
P_0c06cb7e: /* original 8f02, guest PC 0x0c06cb7e */
if(!s->budget--) { s->failed_pc=0x0c06cb7eu; return 0; }
cond=r[17]&1u;
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
if(!cond) { goto P_0c06cb86; }
goto P_0c06cb82;
P_0c06cb80: /* original 2fe6, guest PC 0x0c06cb80 */
if(!s->budget--) { s->failed_pc=0x0c06cb80u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb82;
P_0c06cb82: /* original a001, guest PC 0x0c06cb82 */
if(!s->budget--) { s->failed_pc=0x0c06cb82u; return 0; }
r[6]=r[4];
goto P_0c06cb88;
P_0c06cb84: /* original 6643, guest PC 0x0c06cb84 */
if(!s->budget--) { s->failed_pc=0x0c06cb84u; return 0; }
r[6]=r[4];
goto P_0c06cb86;
P_0c06cb86: /* original 6653, guest PC 0x0c06cb86 */
if(!s->budget--) { s->failed_pc=0x0c06cb86u; return 0; }
r[6]=r[5];
goto P_0c06cb88;
P_0c06cb88: /* original 2f66, guest PC 0x0c06cb88 */
if(!s->budget--) { s->failed_pc=0x0c06cb88u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8a;
P_0c06cb8a: /* original 2fa6, guest PC 0x0c06cb8a */
if(!s->budget--) { s->failed_pc=0x0c06cb8au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb8c;
P_0c06cb8c: /* original d335, guest PC 0x0c06cb8c */
if(!s->budget--) { s->failed_pc=0x0c06cb8cu; return 0; }
r[3]=read(ram,0x0c06cc64u,4);
goto P_0c06cb8e;
P_0c06cb8e: /* original 2f36, guest PC 0x0c06cb8e */
if(!s->budget--) { s->failed_pc=0x0c06cb8eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cb90;
P_0c06cb90: /* original d235, guest PC 0x0c06cb90 */
if(!s->budget--) { s->failed_pc=0x0c06cb90u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cb92;
P_0c06cb92: /* original 420b, guest PC 0x0c06cb92 */
if(!s->budget--) { s->failed_pc=0x0c06cb92u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cb96u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cb96u) { target=s->pc; goto dispatch; }
goto P_0c06cb96;
P_0c06cb94: /* original 64d3, guest PC 0x0c06cb94 */
if(!s->budget--) { s->failed_pc=0x0c06cb94u; return 0; }
r[4]=r[13];
goto P_0c06cb96;
P_0c06cb96: /* original a010, guest PC 0x0c06cb96 */
if(!s->budget--) { s->failed_pc=0x0c06cb96u; return 0; }
goto P_0c06cbba;
P_0c06cb98: /* original 0009, guest PC 0x0c06cb98 */
if(!s->budget--) { s->failed_pc=0x0c06cb98u; return 0; }
goto P_0c06cb9a;
P_0c06cb9a: /* original 60b3, guest PC 0x0c06cb9a */
if(!s->budget--) { s->failed_pc=0x0c06cb9au; return 0; }
r[0]=r[11];
goto P_0c06cb9c;
P_0c06cb9c: /* original d733, guest PC 0x0c06cb9c */
if(!s->budget--) { s->failed_pc=0x0c06cb9cu; return 0; }
r[7]=read(ram,0x0c06cc6cu,4);
goto P_0c06cb9e;
P_0c06cb9e: /* original 8801, guest PC 0x0c06cb9e */
if(!s->budget--) { s->failed_pc=0x0c06cb9eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cba0;
P_0c06cba0: /* original 890d, guest PC 0x0c06cba0 */
if(!s->budget--) { s->failed_pc=0x0c06cba0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cbbe; }
goto P_0c06cba2;
P_0c06cba2: /* original 3e66, guest PC 0x0c06cba2 */
if(!s->budget--) { s->failed_pc=0x0c06cba2u; return 0; }
r[17]=(r[17]&~1u)|((r[14]>r[6])!=0);
goto P_0c06cba4;
P_0c06cba4: /* original 8d02, guest PC 0x0c06cba4 */
if(!s->budget--) { s->failed_pc=0x0c06cba4u; return 0; }
cond=r[17]&1u;
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
if(cond) { goto P_0c06cbac; }
goto P_0c06cba8;
P_0c06cba6: /* original 2fc6, guest PC 0x0c06cba6 */
if(!s->budget--) { s->failed_pc=0x0c06cba6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cba8;
P_0c06cba8: /* original a001, guest PC 0x0c06cba8 */
if(!s->budget--) { s->failed_pc=0x0c06cba8u; return 0; }
r[6]=r[5];
goto P_0c06cbae;
P_0c06cbaa: /* original 6653, guest PC 0x0c06cbaa */
if(!s->budget--) { s->failed_pc=0x0c06cbaau; return 0; }
r[6]=r[5];
goto P_0c06cbac;
P_0c06cbac: /* original 6643, guest PC 0x0c06cbac */
if(!s->budget--) { s->failed_pc=0x0c06cbacu; return 0; }
r[6]=r[4];
goto P_0c06cbae;
P_0c06cbae: /* original 2f96, guest PC 0x0c06cbae */
if(!s->budget--) { s->failed_pc=0x0c06cbaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb0;
P_0c06cbb0: /* original 65a3, guest PC 0x0c06cbb0 */
if(!s->budget--) { s->failed_pc=0x0c06cbb0u; return 0; }
r[5]=r[10];
goto P_0c06cbb2;
P_0c06cbb2: /* original 2fb6, guest PC 0x0c06cbb2 */
if(!s->budget--) { s->failed_pc=0x0c06cbb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb4;
P_0c06cbb4: /* original 2fe6, guest PC 0x0c06cbb4 */
if(!s->budget--) { s->failed_pc=0x0c06cbb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbb6;
P_0c06cbb6: /* original b015, guest PC 0x0c06cbb6 */
if(!s->budget--) { s->failed_pc=0x0c06cbb6u; return 0; }
target=code_base|0x0c06cbe4u; r[16]=code_base|0x0c06cbbau;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cbbau) { target=s->pc; goto dispatch; }
goto P_0c06cbba;
P_0c06cbb8: /* original 64d3, guest PC 0x0c06cbb8 */
if(!s->budget--) { s->failed_pc=0x0c06cbb8u; return 0; }
r[4]=r[13];
goto P_0c06cbba;
P_0c06cbba: /* original a00b, guest PC 0x0c06cbba */
if(!s->budget--) { s->failed_pc=0x0c06cbbau; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbd4;
P_0c06cbbc: /* original 7f10, guest PC 0x0c06cbbc */
if(!s->budget--) { s->failed_pc=0x0c06cbbcu; return 0; }
r[15]+=0x00000010u;
goto P_0c06cbbe;
P_0c06cbbe: /* original 2fc6, guest PC 0x0c06cbbe */
if(!s->budget--) { s->failed_pc=0x0c06cbbeu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc0;
P_0c06cbc0: /* original 2f96, guest PC 0x0c06cbc0 */
if(!s->budget--) { s->failed_pc=0x0c06cbc0u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc2;
P_0c06cbc2: /* original 2f76, guest PC 0x0c06cbc2 */
if(!s->budget--) { s->failed_pc=0x0c06cbc2u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc4;
P_0c06cbc4: /* original 2fe6, guest PC 0x0c06cbc4 */
if(!s->budget--) { s->failed_pc=0x0c06cbc4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc6;
P_0c06cbc6: /* original 2fa6, guest PC 0x0c06cbc6 */
if(!s->budget--) { s->failed_pc=0x0c06cbc6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbc8;
P_0c06cbc8: /* original d229, guest PC 0x0c06cbc8 */
if(!s->budget--) { s->failed_pc=0x0c06cbc8u; return 0; }
r[2]=read(ram,0x0c06cc70u,4);
goto P_0c06cbca;
P_0c06cbca: /* original 2f26, guest PC 0x0c06cbca */
if(!s->budget--) { s->failed_pc=0x0c06cbcau; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbcc;
P_0c06cbcc: /* original d326, guest PC 0x0c06cbcc */
if(!s->budget--) { s->failed_pc=0x0c06cbccu; return 0; }
r[3]=read(ram,0x0c06cc68u,4);
goto P_0c06cbce;
P_0c06cbce: /* original 430b, guest PC 0x0c06cbce */
if(!s->budget--) { s->failed_pc=0x0c06cbceu; return 0; }
target=r[3];
r[16]=code_base|0x0c06cbd2u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cbd2u) { target=s->pc; goto dispatch; }
goto P_0c06cbd2;
P_0c06cbd0: /* original 64d3, guest PC 0x0c06cbd0 */
if(!s->budget--) { s->failed_pc=0x0c06cbd0u; return 0; }
r[4]=r[13];
goto P_0c06cbd2;
P_0c06cbd2: /* original 7f18, guest PC 0x0c06cbd2 */
if(!s->budget--) { s->failed_pc=0x0c06cbd2u; return 0; }
r[15]+=0x00000018u;
goto P_0c06cbd4;
P_0c06cbd4: /* original 4f26, guest PC 0x0c06cbd4 */
if(!s->budget--) { s->failed_pc=0x0c06cbd4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cbd6;
P_0c06cbd6: /* original 69f6, guest PC 0x0c06cbd6 */
if(!s->budget--) { s->failed_pc=0x0c06cbd6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06cbd8;
P_0c06cbd8: /* original 6af6, guest PC 0x0c06cbd8 */
if(!s->budget--) { s->failed_pc=0x0c06cbd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06cbda;
P_0c06cbda: /* original 6bf6, guest PC 0x0c06cbda */
if(!s->budget--) { s->failed_pc=0x0c06cbdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cbdc;
P_0c06cbdc: /* original 6cf6, guest PC 0x0c06cbdc */
if(!s->budget--) { s->failed_pc=0x0c06cbdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cbde;
P_0c06cbde: /* original 6df6, guest PC 0x0c06cbde */
if(!s->budget--) { s->failed_pc=0x0c06cbdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cbe0;
P_0c06cbe0: /* original 000b, guest PC 0x0c06cbe0 */
if(!s->budget--) { s->failed_pc=0x0c06cbe0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cbe2: /* original 6ef6, guest PC 0x0c06cbe2 */
if(!s->budget--) { s->failed_pc=0x0c06cbe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06cbe4;
P_0c06cbe4: /* original 4f22, guest PC 0x0c06cbe4 */
if(!s->budget--) { s->failed_pc=0x0c06cbe4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cbe6;
P_0c06cbe6: /* original e018, guest PC 0x0c06cbe6 */
if(!s->budget--) { s->failed_pc=0x0c06cbe6u; return 0; }
r[0]=0x00000018u;
goto P_0c06cbe8;
P_0c06cbe8: /* original 7ff8, guest PC 0x0c06cbe8 */
if(!s->budget--) { s->failed_pc=0x0c06cbe8u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c06cbea;
P_0c06cbea: /* original 2f42, guest PC 0x0c06cbea */
if(!s->budget--) { s->failed_pc=0x0c06cbeau; return 0; }
write(ram,r[15],r[4],4);
goto P_0c06cbec;
P_0c06cbec: /* original 1f71, guest PC 0x0c06cbec */
if(!s->budget--) { s->failed_pc=0x0c06cbecu; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c06cbee;
P_0c06cbee: /* original 03fc, guest PC 0x0c06cbee */
if(!s->budget--) { s->failed_pc=0x0c06cbeeu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cbf0;
P_0c06cbf0: /* original e018, guest PC 0x0c06cbf0 */
if(!s->budget--) { s->failed_pc=0x0c06cbf0u; return 0; }
r[0]=0x00000018u;
goto P_0c06cbf2;
P_0c06cbf2: /* original 2f36, guest PC 0x0c06cbf2 */
if(!s->budget--) { s->failed_pc=0x0c06cbf2u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbf4;
P_0c06cbf4: /* original 02fc, guest PC 0x0c06cbf4 */
if(!s->budget--) { s->failed_pc=0x0c06cbf4u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cbf6;
P_0c06cbf6: /* original e01c, guest PC 0x0c06cbf6 */
if(!s->budget--) { s->failed_pc=0x0c06cbf6u; return 0; }
r[0]=0x0000001cu;
goto P_0c06cbf8;
P_0c06cbf8: /* original 2f26, guest PC 0x0c06cbf8 */
if(!s->budget--) { s->failed_pc=0x0c06cbf8u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbfa;
P_0c06cbfa: /* original 53f3, guest PC 0x0c06cbfa */
if(!s->budget--) { s->failed_pc=0x0c06cbfau; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c06cbfc;
P_0c06cbfc: /* original 2f36, guest PC 0x0c06cbfc */
if(!s->budget--) { s->failed_pc=0x0c06cbfcu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cbfe;
P_0c06cbfe: /* original 02fc, guest PC 0x0c06cbfe */
if(!s->budget--) { s->failed_pc=0x0c06cbfeu; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cc00;
P_0c06cc00: /* original e01c, guest PC 0x0c06cc00 */
if(!s->budget--) { s->failed_pc=0x0c06cc00u; return 0; }
r[0]=0x0000001cu;
goto P_0c06cc02;
P_0c06cc02: /* original 2f26, guest PC 0x0c06cc02 */
if(!s->budget--) { s->failed_pc=0x0c06cc02u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc04;
P_0c06cc04: /* original 00fc, guest PC 0x0c06cc04 */
if(!s->budget--) { s->failed_pc=0x0c06cc04u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[15]+r[0],1);
goto P_0c06cc06;
P_0c06cc06: /* original 2f06, guest PC 0x0c06cc06 */
if(!s->budget--) { s->failed_pc=0x0c06cc06u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc08;
P_0c06cc08: /* original 2f66, guest PC 0x0c06cc08 */
if(!s->budget--) { s->failed_pc=0x0c06cc08u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc0a;
P_0c06cc0a: /* original 2f56, guest PC 0x0c06cc0a */
if(!s->budget--) { s->failed_pc=0x0c06cc0au; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc0c;
P_0c06cc0c: /* original d319, guest PC 0x0c06cc0c */
if(!s->budget--) { s->failed_pc=0x0c06cc0cu; return 0; }
r[3]=read(ram,0x0c06cc74u,4);
goto P_0c06cc0e;
P_0c06cc0e: /* original 2f36, guest PC 0x0c06cc0e */
if(!s->budget--) { s->failed_pc=0x0c06cc0eu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cc10;
P_0c06cc10: /* original d215, guest PC 0x0c06cc10 */
if(!s->budget--) { s->failed_pc=0x0c06cc10u; return 0; }
r[2]=read(ram,0x0c06cc68u,4);
goto P_0c06cc12;
P_0c06cc12: /* original 420b, guest PC 0x0c06cc12 */
if(!s->budget--) { s->failed_pc=0x0c06cc12u; return 0; }
target=r[2];
r[16]=code_base|0x0c06cc16u;
r[4]=read(ram,r[15]+32,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cc16u) { target=s->pc; goto dispatch; }
goto P_0c06cc16;
P_0c06cc14: /* original 54f8, guest PC 0x0c06cc14 */
if(!s->budget--) { s->failed_pc=0x0c06cc14u; return 0; }
r[4]=read(ram,r[15]+32,4);
goto P_0c06cc16;
P_0c06cc16: /* original 7f28, guest PC 0x0c06cc16 */
if(!s->budget--) { s->failed_pc=0x0c06cc16u; return 0; }
r[15]+=0x00000028u;
goto P_0c06cc18;
P_0c06cc18: /* original 4f26, guest PC 0x0c06cc18 */
if(!s->budget--) { s->failed_pc=0x0c06cc18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cc1a;
P_0c06cc1a: /* original 000b, guest PC 0x0c06cc1a */
if(!s->budget--) { s->failed_pc=0x0c06cc1au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c06cc1c: /* original 0009, guest PC 0x0c06cc1c */
if(!s->budget--) { s->failed_pc=0x0c06cc1cu; return 0; }
if(!vf3_matrix_family(0x0c06cc1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cc1eu; return 0; } return 1;
P_0c06cdf2: /* original 2fe6, guest PC 0x0c06cdf2 */
if(!s->budget--) { s->failed_pc=0x0c06cdf2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdf4;
P_0c06cdf4: /* original 2fd6, guest PC 0x0c06cdf4 */
if(!s->budget--) { s->failed_pc=0x0c06cdf4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdf6;
P_0c06cdf6: /* original 2fc6, guest PC 0x0c06cdf6 */
if(!s->budget--) { s->failed_pc=0x0c06cdf6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdf8;
P_0c06cdf8: /* original 2fb6, guest PC 0x0c06cdf8 */
if(!s->budget--) { s->failed_pc=0x0c06cdf8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cdfa;
P_0c06cdfa: /* original 901a, guest PC 0x0c06cdfa */
if(!s->budget--) { s->failed_pc=0x0c06cdfau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce32u,2);
goto P_0c06cdfc;
P_0c06cdfc: /* original d414, guest PC 0x0c06cdfc */
if(!s->budget--) { s->failed_pc=0x0c06cdfcu; return 0; }
r[4]=read(ram,0x0c06ce50u,4);
goto P_0c06cdfe;
P_0c06cdfe: /* original 4f22, guest PC 0x0c06cdfe */
if(!s->budget--) { s->failed_pc=0x0c06cdfeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ce00;
P_0c06ce00: /* original 034c, guest PC 0x0c06ce00 */
if(!s->budget--) { s->failed_pc=0x0c06ce00u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce02;
P_0c06ce02: /* original 7ffc, guest PC 0x0c06ce02 */
if(!s->budget--) { s->failed_pc=0x0c06ce02u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06ce04;
P_0c06ce04: /* original 2f32, guest PC 0x0c06ce04 */
if(!s->budget--) { s->failed_pc=0x0c06ce04u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ce06;
P_0c06ce06: /* original 9012, guest PC 0x0c06ce06 */
if(!s->budget--) { s->failed_pc=0x0c06ce06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce2eu,2);
goto P_0c06ce08;
P_0c06ce08: /* original 0b4c, guest PC 0x0c06ce08 */
if(!s->budget--) { s->failed_pc=0x0c06ce08u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce0a;
P_0c06ce0a: /* original 9013, guest PC 0x0c06ce0a */
if(!s->budget--) { s->failed_pc=0x0c06ce0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ce34u,2);
goto P_0c06ce0c;
P_0c06ce0c: /* original 064c, guest PC 0x0c06ce0c */
if(!s->budget--) { s->failed_pc=0x0c06ce0cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce0e;
P_0c06ce0e: /* original 7001, guest PC 0x0c06ce0e */
if(!s->budget--) { s->failed_pc=0x0c06ce0eu; return 0; }
r[0]+=0x00000001u;
goto P_0c06ce10;
P_0c06ce10: /* original 074c, guest PC 0x0c06ce10 */
if(!s->budget--) { s->failed_pc=0x0c06ce10u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce12;
P_0c06ce12: /* original 700e, guest PC 0x0c06ce12 */
if(!s->budget--) { s->failed_pc=0x0c06ce12u; return 0; }
r[0]+=0x0000000eu;
goto P_0c06ce14;
P_0c06ce14: /* original 054c, guest PC 0x0c06ce14 */
if(!s->budget--) { s->failed_pc=0x0c06ce14u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce16;
P_0c06ce16: /* original 6033, guest PC 0x0c06ce16 */
if(!s->budget--) { s->failed_pc=0x0c06ce16u; return 0; }
r[0]=r[3];
goto P_0c06ce18;
P_0c06ce18: /* original 8801, guest PC 0x0c06ce18 */
if(!s->budget--) { s->failed_pc=0x0c06ce18u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ce1a;
P_0c06ce1a: /* original 891b, guest PC 0x0c06ce1a */
if(!s->budget--) { s->failed_pc=0x0c06ce1au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ce54; }
goto P_0c06ce1c;
P_0c06ce1c: /* original 60b3, guest PC 0x0c06ce1c */
if(!s->budget--) { s->failed_pc=0x0c06ce1cu; return 0; }
r[0]=r[11];
goto P_0c06ce1e;
P_0c06ce1e: /* original 8801, guest PC 0x0c06ce1e */
if(!s->budget--) { s->failed_pc=0x0c06ce1eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ce20;
P_0c06ce20: /* original 8f01, guest PC 0x0c06ce20 */
if(!s->budget--) { s->failed_pc=0x0c06ce20u; return 0; }
cond=r[17]&1u;
r[14]=0x00000027u;
if(!cond) { goto P_0c06ce26; }
goto P_0c06ce24;
P_0c06ce22: /* original ee27, guest PC 0x0c06ce22 */
if(!s->budget--) { s->failed_pc=0x0c06ce22u; return 0; }
r[14]=0x00000027u;
goto P_0c06ce24;
P_0c06ce24: /* original ee05, guest PC 0x0c06ce24 */
if(!s->budget--) { s->failed_pc=0x0c06ce24u; return 0; }
r[14]=0x00000005u;
goto P_0c06ce26;
P_0c06ce26: /* original 6d63, guest PC 0x0c06ce26 */
if(!s->budget--) { s->failed_pc=0x0c06ce26u; return 0; }
r[13]=r[6];
goto P_0c06ce28;
P_0c06ce28: /* original a01f, guest PC 0x0c06ce28 */
if(!s->budget--) { s->failed_pc=0x0c06ce28u; return 0; }
r[12]=r[7];
goto P_0c06ce6a;
P_0c06ce2a: /* original 6c73, guest PC 0x0c06ce2a */
if(!s->budget--) { s->failed_pc=0x0c06ce2au; return 0; }
r[12]=r[7];
if(!vf3_matrix_family(0x0c06ce2cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06ce2cu; return 0; } return 1;
P_0c06ce54: /* original 905d, guest PC 0x0c06ce54 */
if(!s->budget--) { s->failed_pc=0x0c06ce54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf12u,2);
goto P_0c06ce56;
P_0c06ce56: /* original 0d4c, guest PC 0x0c06ce56 */
if(!s->budget--) { s->failed_pc=0x0c06ce56u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce58;
P_0c06ce58: /* original 7001, guest PC 0x0c06ce58 */
if(!s->budget--) { s->failed_pc=0x0c06ce58u; return 0; }
r[0]+=0x00000001u;
goto P_0c06ce5a;
P_0c06ce5a: /* original 0c4c, guest PC 0x0c06ce5a */
if(!s->budget--) { s->failed_pc=0x0c06ce5au; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ce5c;
P_0c06ce5c: /* original 60b3, guest PC 0x0c06ce5c */
if(!s->budget--) { s->failed_pc=0x0c06ce5cu; return 0; }
r[0]=r[11];
goto P_0c06ce5e;
P_0c06ce5e: /* original 8801, guest PC 0x0c06ce5e */
if(!s->budget--) { s->failed_pc=0x0c06ce5eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ce60;
P_0c06ce60: /* original 8f03, guest PC 0x0c06ce60 */
if(!s->budget--) { s->failed_pc=0x0c06ce60u; return 0; }
cond=r[17]&1u;
r[14]=0x00000027u;
if(!cond) { goto P_0c06ce6a; }
goto P_0c06ce64;
P_0c06ce62: /* original ee27, guest PC 0x0c06ce62 */
if(!s->budget--) { s->failed_pc=0x0c06ce62u; return 0; }
r[14]=0x00000027u;
goto P_0c06ce64;
P_0c06ce64: /* original 6c73, guest PC 0x0c06ce64 */
if(!s->budget--) { s->failed_pc=0x0c06ce64u; return 0; }
r[12]=r[7];
goto P_0c06ce66;
P_0c06ce66: /* original 6d63, guest PC 0x0c06ce66 */
if(!s->budget--) { s->failed_pc=0x0c06ce66u; return 0; }
r[13]=r[6];
goto P_0c06ce68;
P_0c06ce68: /* original ee05, guest PC 0x0c06ce68 */
if(!s->budget--) { s->failed_pc=0x0c06ce68u; return 0; }
r[14]=0x00000005u;
goto P_0c06ce6a;
P_0c06ce6a: /* original 9353, guest PC 0x0c06ce6a */
if(!s->budget--) { s->failed_pc=0x0c06ce6au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf14u,2);
goto P_0c06ce6c;
P_0c06ce6c: /* original 64e3, guest PC 0x0c06ce6c */
if(!s->budget--) { s->failed_pc=0x0c06ce6cu; return 0; }
r[4]=r[14];
goto P_0c06ce6e;
P_0c06ce6e: /* original 6b53, guest PC 0x0c06ce6e */
if(!s->budget--) { s->failed_pc=0x0c06ce6eu; return 0; }
r[11]=r[5];
goto P_0c06ce70;
P_0c06ce70: /* original 4400, guest PC 0x0c06ce70 */
if(!s->budget--) { s->failed_pc=0x0c06ce70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ce72;
P_0c06ce72: /* original ba75, guest PC 0x0c06ce72 */
if(!s->budget--) { s->failed_pc=0x0c06ce72u; return 0; }
target=code_base|0x0c06c360u; r[16]=code_base|0x0c06ce76u;
r[4]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ce76u) { target=s->pc; goto dispatch; }
goto P_0c06ce76;
P_0c06ce74: /* original 243b, guest PC 0x0c06ce74 */
if(!s->budget--) { s->failed_pc=0x0c06ce74u; return 0; }
r[4]|=r[3];
goto P_0c06ce76;
P_0c06ce76: /* original 2008, guest PC 0x0c06ce76 */
if(!s->budget--) { s->failed_pc=0x0c06ce76u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ce78;
P_0c06ce78: /* original 8906, guest PC 0x0c06ce78 */
if(!s->budget--) { s->failed_pc=0x0c06ce78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ce88; }
goto P_0c06ce7a;
P_0c06ce7a: /* original 66d3, guest PC 0x0c06ce7a */
if(!s->budget--) { s->failed_pc=0x0c06ce7au; return 0; }
r[6]=r[13];
goto P_0c06ce7c;
P_0c06ce7c: /* original e52e, guest PC 0x0c06ce7c */
if(!s->budget--) { s->failed_pc=0x0c06ce7cu; return 0; }
r[5]=0x0000002eu;
goto P_0c06ce7e;
P_0c06ce7e: /* original 2fb6, guest PC 0x0c06ce7e */
if(!s->budget--) { s->failed_pc=0x0c06ce7eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce80;
P_0c06ce80: /* original 67c3, guest PC 0x0c06ce80 */
if(!s->budget--) { s->failed_pc=0x0c06ce80u; return 0; }
r[7]=r[12];
goto P_0c06ce82;
P_0c06ce82: /* original be30, guest PC 0x0c06ce82 */
if(!s->budget--) { s->failed_pc=0x0c06ce82u; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06ce86u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ce86u) { target=s->pc; goto dispatch; }
goto P_0c06ce86;
P_0c06ce84: /* original 64e3, guest PC 0x0c06ce84 */
if(!s->budget--) { s->failed_pc=0x0c06ce84u; return 0; }
r[4]=r[14];
goto P_0c06ce86;
P_0c06ce86: /* original 7f04, guest PC 0x0c06ce86 */
if(!s->budget--) { s->failed_pc=0x0c06ce86u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ce88;
P_0c06ce88: /* original 7f04, guest PC 0x0c06ce88 */
if(!s->budget--) { s->failed_pc=0x0c06ce88u; return 0; }
r[15]+=0x00000004u;
goto P_0c06ce8a;
P_0c06ce8a: /* original 4f26, guest PC 0x0c06ce8a */
if(!s->budget--) { s->failed_pc=0x0c06ce8au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06ce8c;
P_0c06ce8c: /* original 6bf6, guest PC 0x0c06ce8c */
if(!s->budget--) { s->failed_pc=0x0c06ce8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06ce8e;
P_0c06ce8e: /* original 6cf6, guest PC 0x0c06ce8e */
if(!s->budget--) { s->failed_pc=0x0c06ce8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06ce90;
P_0c06ce90: /* original 6df6, guest PC 0x0c06ce90 */
if(!s->budget--) { s->failed_pc=0x0c06ce90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06ce92;
P_0c06ce92: /* original 000b, guest PC 0x0c06ce92 */
if(!s->budget--) { s->failed_pc=0x0c06ce92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06ce94: /* original 6ef6, guest PC 0x0c06ce94 */
if(!s->budget--) { s->failed_pc=0x0c06ce94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06ce96;
P_0c06ce96: /* original 2fe6, guest PC 0x0c06ce96 */
if(!s->budget--) { s->failed_pc=0x0c06ce96u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce98;
P_0c06ce98: /* original 2fd6, guest PC 0x0c06ce98 */
if(!s->budget--) { s->failed_pc=0x0c06ce98u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce9a;
P_0c06ce9a: /* original 2fc6, guest PC 0x0c06ce9a */
if(!s->budget--) { s->failed_pc=0x0c06ce9au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce9c;
P_0c06ce9c: /* original 2fb6, guest PC 0x0c06ce9c */
if(!s->budget--) { s->failed_pc=0x0c06ce9cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ce9e;
P_0c06ce9e: /* original 903a, guest PC 0x0c06ce9e */
if(!s->budget--) { s->failed_pc=0x0c06ce9eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf16u,2);
goto P_0c06cea0;
P_0c06cea0: /* original d41e, guest PC 0x0c06cea0 */
if(!s->budget--) { s->failed_pc=0x0c06cea0u; return 0; }
r[4]=read(ram,0x0c06cf1cu,4);
goto P_0c06cea2;
P_0c06cea2: /* original 4f22, guest PC 0x0c06cea2 */
if(!s->budget--) { s->failed_pc=0x0c06cea2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06cea4;
P_0c06cea4: /* original 034c, guest PC 0x0c06cea4 */
if(!s->budget--) { s->failed_pc=0x0c06cea4u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06cea6;
P_0c06cea6: /* original 7ffc, guest PC 0x0c06cea6 */
if(!s->budget--) { s->failed_pc=0x0c06cea6u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06cea8;
P_0c06cea8: /* original 2f32, guest PC 0x0c06cea8 */
if(!s->budget--) { s->failed_pc=0x0c06cea8u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06ceaa;
P_0c06ceaa: /* original 9035, guest PC 0x0c06ceaa */
if(!s->budget--) { s->failed_pc=0x0c06ceaau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf18u,2);
goto P_0c06ceac;
P_0c06ceac: /* original 0b4c, guest PC 0x0c06ceac */
if(!s->budget--) { s->failed_pc=0x0c06ceacu; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceae;
P_0c06ceae: /* original 9034, guest PC 0x0c06ceae */
if(!s->budget--) { s->failed_pc=0x0c06ceaeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf1au,2);
goto P_0c06ceb0;
P_0c06ceb0: /* original 064c, guest PC 0x0c06ceb0 */
if(!s->budget--) { s->failed_pc=0x0c06ceb0u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceb2;
P_0c06ceb2: /* original 7001, guest PC 0x0c06ceb2 */
if(!s->budget--) { s->failed_pc=0x0c06ceb2u; return 0; }
r[0]+=0x00000001u;
goto P_0c06ceb4;
P_0c06ceb4: /* original 074c, guest PC 0x0c06ceb4 */
if(!s->budget--) { s->failed_pc=0x0c06ceb4u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceb6;
P_0c06ceb6: /* original 700f, guest PC 0x0c06ceb6 */
if(!s->budget--) { s->failed_pc=0x0c06ceb6u; return 0; }
r[0]+=0x0000000fu;
goto P_0c06ceb8;
P_0c06ceb8: /* original 054c, guest PC 0x0c06ceb8 */
if(!s->budget--) { s->failed_pc=0x0c06ceb8u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06ceba;
P_0c06ceba: /* original 6033, guest PC 0x0c06ceba */
if(!s->budget--) { s->failed_pc=0x0c06cebau; return 0; }
r[0]=r[3];
goto P_0c06cebc;
P_0c06cebc: /* original 8801, guest PC 0x0c06cebc */
if(!s->budget--) { s->failed_pc=0x0c06cebcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cebe;
P_0c06cebe: /* original 8907, guest PC 0x0c06cebe */
if(!s->budget--) { s->failed_pc=0x0c06cebeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06ced0; }
goto P_0c06cec0;
P_0c06cec0: /* original 60b3, guest PC 0x0c06cec0 */
if(!s->budget--) { s->failed_pc=0x0c06cec0u; return 0; }
r[0]=r[11];
goto P_0c06cec2;
P_0c06cec2: /* original 8801, guest PC 0x0c06cec2 */
if(!s->budget--) { s->failed_pc=0x0c06cec2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06cec4;
P_0c06cec4: /* original 8f01, guest PC 0x0c06cec4 */
if(!s->budget--) { s->failed_pc=0x0c06cec4u; return 0; }
cond=r[17]&1u;
r[14]=0x00000005u;
if(!cond) { goto P_0c06ceca; }
goto P_0c06cec8;
P_0c06cec6: /* original ee05, guest PC 0x0c06cec6 */
if(!s->budget--) { s->failed_pc=0x0c06cec6u; return 0; }
r[14]=0x00000005u;
goto P_0c06cec8;
P_0c06cec8: /* original ee27, guest PC 0x0c06cec8 */
if(!s->budget--) { s->failed_pc=0x0c06cec8u; return 0; }
r[14]=0x00000027u;
goto P_0c06ceca;
P_0c06ceca: /* original 6d63, guest PC 0x0c06ceca */
if(!s->budget--) { s->failed_pc=0x0c06cecau; return 0; }
r[13]=r[6];
goto P_0c06cecc;
P_0c06cecc: /* original a00b, guest PC 0x0c06cecc */
if(!s->budget--) { s->failed_pc=0x0c06ceccu; return 0; }
r[12]=r[7];
goto P_0c06cee6;
P_0c06cece: /* original 6c73, guest PC 0x0c06cece */
if(!s->budget--) { s->failed_pc=0x0c06ceceu; return 0; }
r[12]=r[7];
goto P_0c06ced0;
P_0c06ced0: /* original 60b3, guest PC 0x0c06ced0 */
if(!s->budget--) { s->failed_pc=0x0c06ced0u; return 0; }
r[0]=r[11];
goto P_0c06ced2;
P_0c06ced2: /* original 8801, guest PC 0x0c06ced2 */
if(!s->budget--) { s->failed_pc=0x0c06ced2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c06ced4;
P_0c06ced4: /* original ee05, guest PC 0x0c06ced4 */
if(!s->budget--) { s->failed_pc=0x0c06ced4u; return 0; }
r[14]=0x00000005u;
goto P_0c06ced6;
P_0c06ced6: /* original 6d63, guest PC 0x0c06ced6 */
if(!s->budget--) { s->failed_pc=0x0c06ced6u; return 0; }
r[13]=r[6];
goto P_0c06ced8;
P_0c06ced8: /* original 8f05, guest PC 0x0c06ced8 */
if(!s->budget--) { s->failed_pc=0x0c06ced8u; return 0; }
cond=r[17]&1u;
r[12]=r[7];
if(!cond) { goto P_0c06cee6; }
goto P_0c06cedc;
P_0c06ceda: /* original 6c73, guest PC 0x0c06ceda */
if(!s->budget--) { s->failed_pc=0x0c06cedau; return 0; }
r[12]=r[7];
goto P_0c06cedc;
P_0c06cedc: /* original 9019, guest PC 0x0c06cedc */
if(!s->budget--) { s->failed_pc=0x0c06cedcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf12u,2);
goto P_0c06cede;
P_0c06cede: /* original ee27, guest PC 0x0c06cede */
if(!s->budget--) { s->failed_pc=0x0c06cedeu; return 0; }
r[14]=0x00000027u;
goto P_0c06cee0;
P_0c06cee0: /* original 0d4c, guest PC 0x0c06cee0 */
if(!s->budget--) { s->failed_pc=0x0c06cee0u; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06cee2;
P_0c06cee2: /* original 7001, guest PC 0x0c06cee2 */
if(!s->budget--) { s->failed_pc=0x0c06cee2u; return 0; }
r[0]+=0x00000001u;
goto P_0c06cee4;
P_0c06cee4: /* original 0c4c, guest PC 0x0c06cee4 */
if(!s->budget--) { s->failed_pc=0x0c06cee4u; return 0; }
r[12]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c06cee6;
P_0c06cee6: /* original 9315, guest PC 0x0c06cee6 */
if(!s->budget--) { s->failed_pc=0x0c06cee6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06cf14u,2);
goto P_0c06cee8;
P_0c06cee8: /* original 64e3, guest PC 0x0c06cee8 */
if(!s->budget--) { s->failed_pc=0x0c06cee8u; return 0; }
r[4]=r[14];
goto P_0c06ceea;
P_0c06ceea: /* original 6b53, guest PC 0x0c06ceea */
if(!s->budget--) { s->failed_pc=0x0c06ceeau; return 0; }
r[11]=r[5];
goto P_0c06ceec;
P_0c06ceec: /* original 4400, guest PC 0x0c06ceec */
if(!s->budget--) { s->failed_pc=0x0c06ceecu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06ceee;
P_0c06ceee: /* original ba37, guest PC 0x0c06ceee */
if(!s->budget--) { s->failed_pc=0x0c06ceeeu; return 0; }
target=code_base|0x0c06c360u; r[16]=code_base|0x0c06cef2u;
r[4]|=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cef2u) { target=s->pc; goto dispatch; }
goto P_0c06cef2;
P_0c06cef0: /* original 243b, guest PC 0x0c06cef0 */
if(!s->budget--) { s->failed_pc=0x0c06cef0u; return 0; }
r[4]|=r[3];
goto P_0c06cef2;
P_0c06cef2: /* original 2008, guest PC 0x0c06cef2 */
if(!s->budget--) { s->failed_pc=0x0c06cef2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06cef4;
P_0c06cef4: /* original 8906, guest PC 0x0c06cef4 */
if(!s->budget--) { s->failed_pc=0x0c06cef4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06cf04; }
goto P_0c06cef6;
P_0c06cef6: /* original 66d3, guest PC 0x0c06cef6 */
if(!s->budget--) { s->failed_pc=0x0c06cef6u; return 0; }
r[6]=r[13];
goto P_0c06cef8;
P_0c06cef8: /* original e52e, guest PC 0x0c06cef8 */
if(!s->budget--) { s->failed_pc=0x0c06cef8u; return 0; }
r[5]=0x0000002eu;
goto P_0c06cefa;
P_0c06cefa: /* original 2fb6, guest PC 0x0c06cefa */
if(!s->budget--) { s->failed_pc=0x0c06cefau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06cefc;
P_0c06cefc: /* original 67c3, guest PC 0x0c06cefc */
if(!s->budget--) { s->failed_pc=0x0c06cefcu; return 0; }
r[7]=r[12];
goto P_0c06cefe;
P_0c06cefe: /* original bdf2, guest PC 0x0c06cefe */
if(!s->budget--) { s->failed_pc=0x0c06cefeu; return 0; }
target=code_base|0x0c06cae6u; r[16]=code_base|0x0c06cf02u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06cf02u) { target=s->pc; goto dispatch; }
goto P_0c06cf02;
P_0c06cf00: /* original 64e3, guest PC 0x0c06cf00 */
if(!s->budget--) { s->failed_pc=0x0c06cf00u; return 0; }
r[4]=r[14];
goto P_0c06cf02;
P_0c06cf02: /* original 7f04, guest PC 0x0c06cf02 */
if(!s->budget--) { s->failed_pc=0x0c06cf02u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cf04;
P_0c06cf04: /* original 7f04, guest PC 0x0c06cf04 */
if(!s->budget--) { s->failed_pc=0x0c06cf04u; return 0; }
r[15]+=0x00000004u;
goto P_0c06cf06;
P_0c06cf06: /* original 4f26, guest PC 0x0c06cf06 */
if(!s->budget--) { s->failed_pc=0x0c06cf06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06cf08;
P_0c06cf08: /* original 6bf6, guest PC 0x0c06cf08 */
if(!s->budget--) { s->failed_pc=0x0c06cf08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06cf0a;
P_0c06cf0a: /* original 6cf6, guest PC 0x0c06cf0a */
if(!s->budget--) { s->failed_pc=0x0c06cf0au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06cf0c;
P_0c06cf0c: /* original 6df6, guest PC 0x0c06cf0c */
if(!s->budget--) { s->failed_pc=0x0c06cf0cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06cf0e;
P_0c06cf0e: /* original 000b, guest PC 0x0c06cf0e */
if(!s->budget--) { s->failed_pc=0x0c06cf0eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06cf10: /* original 6ef6, guest PC 0x0c06cf10 */
if(!s->budget--) { s->failed_pc=0x0c06cf10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06cf12u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06cf12u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
