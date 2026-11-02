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
int vf3_away_batch29_adapter_5(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05da2eu: goto P_0c05da2e;
case 0x0c05da30u: goto P_0c05da30;
case 0x0c05da32u: goto P_0c05da32;
case 0x0c05da34u: goto P_0c05da34;
case 0x0c05da36u: goto P_0c05da36;
case 0x0c05da38u: goto P_0c05da38;
case 0x0c05da3au: goto P_0c05da3a;
case 0x0c05da3cu: goto P_0c05da3c;
case 0x0c05da3eu: goto P_0c05da3e;
case 0x0c05da40u: goto P_0c05da40;
case 0x0c05daa0u: goto P_0c05daa0;
case 0x0c05daa2u: goto P_0c05daa2;
case 0x0c05daa4u: goto P_0c05daa4;
case 0x0c05daa6u: goto P_0c05daa6;
case 0x0c05daa8u: goto P_0c05daa8;
case 0x0c05daaau: goto P_0c05daaa;
case 0x0c05daacu: goto P_0c05daac;
case 0x0c05daaeu: goto P_0c05daae;
case 0x0c05dab0u: goto P_0c05dab0;
case 0x0c05dab2u: goto P_0c05dab2;
case 0x0c05dab4u: goto P_0c05dab4;
case 0x0c05dab6u: goto P_0c05dab6;
case 0x0c05dab8u: goto P_0c05dab8;
case 0x0c05dabau: goto P_0c05daba;
case 0x0c05dabcu: goto P_0c05dabc;
case 0x0c05dabeu: goto P_0c05dabe;
case 0x0c05dac0u: goto P_0c05dac0;
case 0x0c05dac2u: goto P_0c05dac2;
case 0x0c05dac4u: goto P_0c05dac4;
case 0x0c05dac6u: goto P_0c05dac6;
case 0x0c05dac8u: goto P_0c05dac8;
case 0x0c05dacau: goto P_0c05daca;
case 0x0c05daccu: goto P_0c05dacc;
case 0x0c05daceu: goto P_0c05dace;
case 0x0c05dad0u: goto P_0c05dad0;
case 0x0c05dad2u: goto P_0c05dad2;
case 0x0c05dad4u: goto P_0c05dad4;
case 0x0c05dad6u: goto P_0c05dad6;
case 0x0c05dad8u: goto P_0c05dad8;
case 0x0c05dadau: goto P_0c05dada;
case 0x0c05dadcu: goto P_0c05dadc;
case 0x0c05dadeu: goto P_0c05dade;
case 0x0c05dae0u: goto P_0c05dae0;
case 0x0c05dae2u: goto P_0c05dae2;
case 0x0c05dae4u: goto P_0c05dae4;
case 0x0c05dae6u: goto P_0c05dae6;
case 0x0c05dae8u: goto P_0c05dae8;
case 0x0c05daeau: goto P_0c05daea;
case 0x0c05daecu: goto P_0c05daec;
case 0x0c05daeeu: goto P_0c05daee;
case 0x0c05daf0u: goto P_0c05daf0;
case 0x0c05daf2u: goto P_0c05daf2;
case 0x0c05daf4u: goto P_0c05daf4;
case 0x0c05daf6u: goto P_0c05daf6;
case 0x0c05daf8u: goto P_0c05daf8;
case 0x0c05dafau: goto P_0c05dafa;
case 0x0c05dafcu: goto P_0c05dafc;
case 0x0c05dafeu: goto P_0c05dafe;
case 0x0c05db00u: goto P_0c05db00;
case 0x0c05db02u: goto P_0c05db02;
case 0x0c05db04u: goto P_0c05db04;
case 0x0c05db06u: goto P_0c05db06;
case 0x0c05db08u: goto P_0c05db08;
case 0x0c05db0au: goto P_0c05db0a;
case 0x0c05db0cu: goto P_0c05db0c;
case 0x0c05db0eu: goto P_0c05db0e;
case 0x0c05db10u: goto P_0c05db10;
case 0x0c05db12u: goto P_0c05db12;
case 0x0c05db14u: goto P_0c05db14;
case 0x0c05db16u: goto P_0c05db16;
case 0x0c05db18u: goto P_0c05db18;
case 0x0c05db1au: goto P_0c05db1a;
case 0x0c05db1cu: goto P_0c05db1c;
case 0x0c05db40u: goto P_0c05db40;
case 0x0c05db42u: goto P_0c05db42;
case 0x0c05db44u: goto P_0c05db44;
case 0x0c05db46u: goto P_0c05db46;
case 0x0c05db48u: goto P_0c05db48;
case 0x0c05db4au: goto P_0c05db4a;
case 0x0c05db4cu: goto P_0c05db4c;
case 0x0c05db4eu: goto P_0c05db4e;
case 0x0c05db50u: goto P_0c05db50;
case 0x0c05db52u: goto P_0c05db52;
case 0x0c05db54u: goto P_0c05db54;
case 0x0c05db56u: goto P_0c05db56;
case 0x0c05db58u: goto P_0c05db58;
case 0x0c05db5au: goto P_0c05db5a;
case 0x0c05db5cu: goto P_0c05db5c;
case 0x0c05db5eu: goto P_0c05db5e;
case 0x0c05db60u: goto P_0c05db60;
case 0x0c05db62u: goto P_0c05db62;
case 0x0c05db64u: goto P_0c05db64;
case 0x0c05db66u: goto P_0c05db66;
case 0x0c05db68u: goto P_0c05db68;
case 0x0c05db6au: goto P_0c05db6a;
case 0x0c05db6cu: goto P_0c05db6c;
case 0x0c05db6eu: goto P_0c05db6e;
case 0x0c05db70u: goto P_0c05db70;
case 0x0c05db72u: goto P_0c05db72;
case 0x0c05db74u: goto P_0c05db74;
case 0x0c05db76u: goto P_0c05db76;
case 0x0c05db78u: goto P_0c05db78;
case 0x0c05db7au: goto P_0c05db7a;
case 0x0c05db7cu: goto P_0c05db7c;
case 0x0c05db7eu: goto P_0c05db7e;
case 0x0c05db80u: goto P_0c05db80;
case 0x0c05db82u: goto P_0c05db82;
case 0x0c05db84u: goto P_0c05db84;
case 0x0c05db86u: goto P_0c05db86;
case 0x0c05db88u: goto P_0c05db88;
case 0x0c05db8au: goto P_0c05db8a;
case 0x0c05db8cu: goto P_0c05db8c;
case 0x0c05db8eu: goto P_0c05db8e;
case 0x0c05db90u: goto P_0c05db90;
case 0x0c05db92u: goto P_0c05db92;
case 0x0c05db94u: goto P_0c05db94;
case 0x0c05db96u: goto P_0c05db96;
case 0x0c05db98u: goto P_0c05db98;
case 0x0c05db9au: goto P_0c05db9a;
case 0x0c05db9cu: goto P_0c05db9c;
case 0x0c05db9eu: goto P_0c05db9e;
case 0x0c05dba0u: goto P_0c05dba0;
case 0x0c05dba2u: goto P_0c05dba2;
case 0x0c05dba4u: goto P_0c05dba4;
case 0x0c05dba6u: goto P_0c05dba6;
case 0x0c05dba8u: goto P_0c05dba8;
case 0x0c05dbaau: goto P_0c05dbaa;
case 0x0c05dc30u: goto P_0c05dc30;
case 0x0c05dc32u: goto P_0c05dc32;
case 0x0c05dc34u: goto P_0c05dc34;
case 0x0c05dc36u: goto P_0c05dc36;
case 0x0c05dc38u: goto P_0c05dc38;
case 0x0c05dc3au: goto P_0c05dc3a;
case 0x0c05dc3cu: goto P_0c05dc3c;
case 0x0c05dc3eu: goto P_0c05dc3e;
case 0x0c05dc40u: goto P_0c05dc40;
case 0x0c05dc42u: goto P_0c05dc42;
case 0x0c05dc44u: goto P_0c05dc44;
case 0x0c05dc46u: goto P_0c05dc46;
case 0x0c05dc48u: goto P_0c05dc48;
case 0x0c05dc4au: goto P_0c05dc4a;
case 0x0c05dc4cu: goto P_0c05dc4c;
case 0x0c05dc4eu: goto P_0c05dc4e;
case 0x0c05dc50u: goto P_0c05dc50;
case 0x0c05dc52u: goto P_0c05dc52;
case 0x0c05dc54u: goto P_0c05dc54;
case 0x0c05dc56u: goto P_0c05dc56;
case 0x0c05dc58u: goto P_0c05dc58;
case 0x0c05dc5au: goto P_0c05dc5a;
case 0x0c05dc5cu: goto P_0c05dc5c;
case 0x0c05dc5eu: goto P_0c05dc5e;
case 0x0c05dc60u: goto P_0c05dc60;
case 0x0c05dc62u: goto P_0c05dc62;
case 0x0c05dc64u: goto P_0c05dc64;
case 0x0c05dc66u: goto P_0c05dc66;
case 0x0c05dc68u: goto P_0c05dc68;
case 0x0c05dc6au: goto P_0c05dc6a;
case 0x0c05dc6cu: goto P_0c05dc6c;
case 0x0c05dc6eu: goto P_0c05dc6e;
case 0x0c05dc70u: goto P_0c05dc70;
case 0x0c05dc72u: goto P_0c05dc72;
case 0x0c05dc74u: goto P_0c05dc74;
case 0x0c05dc76u: goto P_0c05dc76;
case 0x0c05dc78u: goto P_0c05dc78;
case 0x0c05dc7au: goto P_0c05dc7a;
case 0x0c05dc7cu: goto P_0c05dc7c;
case 0x0c05dc7eu: goto P_0c05dc7e;
case 0x0c05dc80u: goto P_0c05dc80;
case 0x0c05dc82u: goto P_0c05dc82;
case 0x0c05dc84u: goto P_0c05dc84;
case 0x0c05dc86u: goto P_0c05dc86;
case 0x0c05dc88u: goto P_0c05dc88;
case 0x0c05dc8au: goto P_0c05dc8a;
case 0x0c05dc8cu: goto P_0c05dc8c;
case 0x0c05dc8eu: goto P_0c05dc8e;
case 0x0c05dc90u: goto P_0c05dc90;
case 0x0c05dc92u: goto P_0c05dc92;
case 0x0c05dc94u: goto P_0c05dc94;
case 0x0c05dc96u: goto P_0c05dc96;
case 0x0c05dc98u: goto P_0c05dc98;
case 0x0c05dc9au: goto P_0c05dc9a;
case 0x0c05dc9cu: goto P_0c05dc9c;
case 0x0c05dc9eu: goto P_0c05dc9e;
case 0x0c05dca0u: goto P_0c05dca0;
case 0x0c05dca2u: goto P_0c05dca2;
case 0x0c05dca4u: goto P_0c05dca4;
case 0x0c05dca6u: goto P_0c05dca6;
case 0x0c05dca8u: goto P_0c05dca8;
case 0x0c05dcaau: goto P_0c05dcaa;
case 0x0c05dcacu: goto P_0c05dcac;
case 0x0c05dcaeu: goto P_0c05dcae;
case 0x0c05dcb0u: goto P_0c05dcb0;
case 0x0c05dcb2u: goto P_0c05dcb2;
case 0x0c05dcb4u: goto P_0c05dcb4;
case 0x0c05dcb6u: goto P_0c05dcb6;
case 0x0c05dcb8u: goto P_0c05dcb8;
case 0x0c05dcbau: goto P_0c05dcba;
case 0x0c05dcbcu: goto P_0c05dcbc;
case 0x0c05dcbeu: goto P_0c05dcbe;
case 0x0c05dcc0u: goto P_0c05dcc0;
case 0x0c05dcc2u: goto P_0c05dcc2;
case 0x0c05dcc4u: goto P_0c05dcc4;
case 0x0c05dcc6u: goto P_0c05dcc6;
case 0x0c05dcc8u: goto P_0c05dcc8;
case 0x0c05dccau: goto P_0c05dcca;
case 0x0c05dcccu: goto P_0c05dccc;
case 0x0c05dcceu: goto P_0c05dcce;
case 0x0c05dcd0u: goto P_0c05dcd0;
case 0x0c05dcd2u: goto P_0c05dcd2;
case 0x0c05dcd4u: goto P_0c05dcd4;
case 0x0c05dcd6u: goto P_0c05dcd6;
case 0x0c05dcd8u: goto P_0c05dcd8;
case 0x0c05dcdau: goto P_0c05dcda;
case 0x0c05dcdcu: goto P_0c05dcdc;
case 0x0c05dcdeu: goto P_0c05dcde;
case 0x0c05dce0u: goto P_0c05dce0;
case 0x0c05dce2u: goto P_0c05dce2;
case 0x0c05dce4u: goto P_0c05dce4;
case 0x0c05dce6u: goto P_0c05dce6;
case 0x0c05dce8u: goto P_0c05dce8;
case 0x0c05dceau: goto P_0c05dcea;
case 0x0c05dcecu: goto P_0c05dcec;
case 0x0c05dceeu: goto P_0c05dcee;
case 0x0c05dcf0u: goto P_0c05dcf0;
case 0x0c05dcf2u: goto P_0c05dcf2;
case 0x0c05dcf4u: goto P_0c05dcf4;
case 0x0c05dcf6u: goto P_0c05dcf6;
case 0x0c05dcf8u: goto P_0c05dcf8;
case 0x0c05dcfau: goto P_0c05dcfa;
case 0x0c05dcfcu: goto P_0c05dcfc;
case 0x0c05dd30u: goto P_0c05dd30;
case 0x0c05dd32u: goto P_0c05dd32;
case 0x0c05dd34u: goto P_0c05dd34;
case 0x0c05dd36u: goto P_0c05dd36;
case 0x0c05dd38u: goto P_0c05dd38;
case 0x0c05dd3au: goto P_0c05dd3a;
case 0x0c05dd3cu: goto P_0c05dd3c;
case 0x0c05dd3eu: goto P_0c05dd3e;
case 0x0c05dd40u: goto P_0c05dd40;
case 0x0c05dd42u: goto P_0c05dd42;
case 0x0c05dd44u: goto P_0c05dd44;
case 0x0c05dd46u: goto P_0c05dd46;
case 0x0c05dd48u: goto P_0c05dd48;
case 0x0c05dd4au: goto P_0c05dd4a;
case 0x0c05dd4cu: goto P_0c05dd4c;
case 0x0c05dd4eu: goto P_0c05dd4e;
case 0x0c05dd50u: goto P_0c05dd50;
case 0x0c05dd52u: goto P_0c05dd52;
case 0x0c05dd54u: goto P_0c05dd54;
case 0x0c05dd56u: goto P_0c05dd56;
case 0x0c05dd58u: goto P_0c05dd58;
case 0x0c05dd5au: goto P_0c05dd5a;
case 0x0c05dd5cu: goto P_0c05dd5c;
case 0x0c05dd5eu: goto P_0c05dd5e;
case 0x0c05dd60u: goto P_0c05dd60;
case 0x0c05dd62u: goto P_0c05dd62;
case 0x0c05dd64u: goto P_0c05dd64;
case 0x0c05dd66u: goto P_0c05dd66;
case 0x0c05dd68u: goto P_0c05dd68;
case 0x0c05dd6au: goto P_0c05dd6a;
case 0x0c05dd6cu: goto P_0c05dd6c;
case 0x0c05dd6eu: goto P_0c05dd6e;
case 0x0c05dd70u: goto P_0c05dd70;
case 0x0c05dd72u: goto P_0c05dd72;
case 0x0c05dd74u: goto P_0c05dd74;
case 0x0c05dd76u: goto P_0c05dd76;
case 0x0c05dd78u: goto P_0c05dd78;
case 0x0c05dd7au: goto P_0c05dd7a;
case 0x0c05dd7cu: goto P_0c05dd7c;
case 0x0c05dd7eu: goto P_0c05dd7e;
case 0x0c05dd80u: goto P_0c05dd80;
case 0x0c05dd82u: goto P_0c05dd82;
case 0x0c05dd84u: goto P_0c05dd84;
case 0x0c05dd86u: goto P_0c05dd86;
case 0x0c05dd88u: goto P_0c05dd88;
case 0x0c05dd8au: goto P_0c05dd8a;
case 0x0c05dd8cu: goto P_0c05dd8c;
case 0x0c05dd8eu: goto P_0c05dd8e;
case 0x0c05dd90u: goto P_0c05dd90;
case 0x0c05dd92u: goto P_0c05dd92;
case 0x0c05dd94u: goto P_0c05dd94;
case 0x0c05dd96u: goto P_0c05dd96;
case 0x0c05dd98u: goto P_0c05dd98;
case 0x0c05dd9au: goto P_0c05dd9a;
case 0x0c05dd9cu: goto P_0c05dd9c;
case 0x0c05dd9eu: goto P_0c05dd9e;
case 0x0c05dda0u: goto P_0c05dda0;
case 0x0c05dda2u: goto P_0c05dda2;
case 0x0c05dda4u: goto P_0c05dda4;
case 0x0c05dda6u: goto P_0c05dda6;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05da2e: /* original d51b, guest PC 0x0c05da2e */
if(!s->budget--) { s->failed_pc=0x0c05da2eu; return 0; }
r[5]=read(ram,0x0c05da9cu,4);
goto P_0c05da30;
P_0c05da30: /* original 6352, guest PC 0x0c05da30 */
if(!s->budget--) { s->failed_pc=0x0c05da30u; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05da32;
P_0c05da32: /* original 234b, guest PC 0x0c05da32 */
if(!s->budget--) { s->failed_pc=0x0c05da32u; return 0; }
r[3]|=r[4];
goto P_0c05da34;
P_0c05da34: /* original 2532, guest PC 0x0c05da34 */
if(!s->budget--) { s->failed_pc=0x0c05da34u; return 0; }
write(ram,r[5],r[3],4);
goto P_0c05da36;
P_0c05da36: /* original 000b, guest PC 0x0c05da36 */
if(!s->budget--) { s->failed_pc=0x0c05da36u; return 0; }
target=r[16];
r[0]=r[3];
s->pc=target; return ram->oob==0;
P_0c05da38: /* original 6033, guest PC 0x0c05da38 */
if(!s->budget--) { s->failed_pc=0x0c05da38u; return 0; }
r[0]=r[3];
goto P_0c05da3a;
P_0c05da3a: /* original d518, guest PC 0x0c05da3a */
if(!s->budget--) { s->failed_pc=0x0c05da3au; return 0; }
r[5]=read(ram,0x0c05da9cu,4);
goto P_0c05da3c;
P_0c05da3c: /* original 2542, guest PC 0x0c05da3c */
if(!s->budget--) { s->failed_pc=0x0c05da3cu; return 0; }
write(ram,r[5],r[4],4);
goto P_0c05da3e;
P_0c05da3e: /* original 000b, guest PC 0x0c05da3e */
if(!s->budget--) { s->failed_pc=0x0c05da3eu; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c05da40: /* original 6043, guest PC 0x0c05da40 */
if(!s->budget--) { s->failed_pc=0x0c05da40u; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c05da42u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05da42u; return 0; } return 1;
P_0c05daa0: /* original 2fe6, guest PC 0x0c05daa0 */
if(!s->budget--) { s->failed_pc=0x0c05daa0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05daa2;
P_0c05daa2: /* original ee00, guest PC 0x0c05daa2 */
if(!s->budget--) { s->failed_pc=0x0c05daa2u; return 0; }
r[14]=0x00000000u;
goto P_0c05daa4;
P_0c05daa4: /* original d31e, guest PC 0x0c05daa4 */
if(!s->budget--) { s->failed_pc=0x0c05daa4u; return 0; }
r[3]=read(ram,0x0c05db20u,4);
goto P_0c05daa6;
P_0c05daa6: /* original 2fd6, guest PC 0x0c05daa6 */
if(!s->budget--) { s->failed_pc=0x0c05daa6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05daa8;
P_0c05daa8: /* original 4f22, guest PC 0x0c05daa8 */
if(!s->budget--) { s->failed_pc=0x0c05daa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05daaa;
P_0c05daaa: /* original 23e2, guest PC 0x0c05daaa */
if(!s->budget--) { s->failed_pc=0x0c05daaau; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05daac;
P_0c05daac: /* original d21d, guest PC 0x0c05daac */
if(!s->budget--) { s->failed_pc=0x0c05daacu; return 0; }
r[2]=read(ram,0x0c05db24u,4);
goto P_0c05daae;
P_0c05daae: /* original e4ff, guest PC 0x0c05daae */
if(!s->budget--) { s->failed_pc=0x0c05daaeu; return 0; }
r[4]=0xffffffffu;
goto P_0c05dab0;
P_0c05dab0: /* original 2242, guest PC 0x0c05dab0 */
if(!s->budget--) { s->failed_pc=0x0c05dab0u; return 0; }
write(ram,r[2],r[4],4);
goto P_0c05dab2;
P_0c05dab2: /* original d11d, guest PC 0x0c05dab2 */
if(!s->budget--) { s->failed_pc=0x0c05dab2u; return 0; }
r[1]=read(ram,0x0c05db28u,4);
goto P_0c05dab4;
P_0c05dab4: /* original 2142, guest PC 0x0c05dab4 */
if(!s->budget--) { s->failed_pc=0x0c05dab4u; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05dab6;
P_0c05dab6: /* original 730c, guest PC 0x0c05dab6 */
if(!s->budget--) { s->failed_pc=0x0c05dab6u; return 0; }
r[3]+=0x0000000cu;
goto P_0c05dab8;
P_0c05dab8: /* original 2342, guest PC 0x0c05dab8 */
if(!s->budget--) { s->failed_pc=0x0c05dab8u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05daba;
P_0c05daba: /* original 720c, guest PC 0x0c05daba */
if(!s->budget--) { s->failed_pc=0x0c05dabau; return 0; }
r[2]+=0x0000000cu;
goto P_0c05dabc;
P_0c05dabc: /* original 22e2, guest PC 0x0c05dabc */
if(!s->budget--) { s->failed_pc=0x0c05dabcu; return 0; }
write(ram,r[2],r[14],4);
goto P_0c05dabe;
P_0c05dabe: /* original 710c, guest PC 0x0c05dabe */
if(!s->budget--) { s->failed_pc=0x0c05dabeu; return 0; }
r[1]+=0x0000000cu;
goto P_0c05dac0;
P_0c05dac0: /* original 21e2, guest PC 0x0c05dac0 */
if(!s->budget--) { s->failed_pc=0x0c05dac0u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05dac2;
P_0c05dac2: /* original 730c, guest PC 0x0c05dac2 */
if(!s->budget--) { s->failed_pc=0x0c05dac2u; return 0; }
r[3]+=0x0000000cu;
goto P_0c05dac4;
P_0c05dac4: /* original 23e2, guest PC 0x0c05dac4 */
if(!s->budget--) { s->failed_pc=0x0c05dac4u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05dac6;
P_0c05dac6: /* original 62e3, guest PC 0x0c05dac6 */
if(!s->budget--) { s->failed_pc=0x0c05dac6u; return 0; }
r[2]=r[14];
goto P_0c05dac8;
P_0c05dac8: /* original d018, guest PC 0x0c05dac8 */
if(!s->budget--) { s->failed_pc=0x0c05dac8u; return 0; }
r[0]=read(ram,0x0c05db2cu,4);
goto P_0c05daca;
P_0c05daca: /* original 20e2, guest PC 0x0c05daca */
if(!s->budget--) { s->failed_pc=0x0c05dacau; return 0; }
write(ram,r[0],r[14],4);
goto P_0c05dacc;
P_0c05dacc: /* original a008, guest PC 0x0c05dacc */
if(!s->budget--) { s->failed_pc=0x0c05daccu; return 0; }
r[13]=0x0000000au;
goto P_0c05dae0;
P_0c05dace: /* original ed0a, guest PC 0x0c05dace */
if(!s->budget--) { s->failed_pc=0x0c05daceu; return 0; }
r[13]=0x0000000au;
goto P_0c05dad0;
P_0c05dad0: /* original d317, guest PC 0x0c05dad0 */
if(!s->budget--) { s->failed_pc=0x0c05dad0u; return 0; }
r[3]=read(ram,0x0c05db30u,4);
goto P_0c05dad2;
P_0c05dad2: /* original 6232, guest PC 0x0c05dad2 */
if(!s->budget--) { s->failed_pc=0x0c05dad2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05dad4;
P_0c05dad4: /* original 420b, guest PC 0x0c05dad4 */
if(!s->budget--) { s->failed_pc=0x0c05dad4u; return 0; }
target=r[2];
r[16]=code_base|0x0c05dad8u;
r[4]=read(ram,r[3]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dad8u) { target=s->pc; goto dispatch; }
goto P_0c05dad8;
P_0c05dad6: /* original 5431, guest PC 0x0c05dad6 */
if(!s->budget--) { s->failed_pc=0x0c05dad6u; return 0; }
r[4]=read(ram,r[3]+4,4);
goto P_0c05dad8;
P_0c05dad8: /* original d214, guest PC 0x0c05dad8 */
if(!s->budget--) { s->failed_pc=0x0c05dad8u; return 0; }
r[2]=read(ram,0x0c05db2cu,4);
goto P_0c05dada;
P_0c05dada: /* original 6122, guest PC 0x0c05dada */
if(!s->budget--) { s->failed_pc=0x0c05dadau; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05dadc;
P_0c05dadc: /* original 31d6, guest PC 0x0c05dadc */
if(!s->budget--) { s->failed_pc=0x0c05dadcu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>r[13])!=0);
goto P_0c05dade;
P_0c05dade: /* original 8903, guest PC 0x0c05dade */
if(!s->budget--) { s->failed_pc=0x0c05dadeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dae8; }
goto P_0c05dae0;
P_0c05dae0: /* original d014, guest PC 0x0c05dae0 */
if(!s->budget--) { s->failed_pc=0x0c05dae0u; return 0; }
r[0]=read(ram,0x0c05db34u,4);
goto P_0c05dae2;
P_0c05dae2: /* original 6302, guest PC 0x0c05dae2 */
if(!s->budget--) { s->failed_pc=0x0c05dae2u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05dae4;
P_0c05dae4: /* original 2338, guest PC 0x0c05dae4 */
if(!s->budget--) { s->failed_pc=0x0c05dae4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05dae6;
P_0c05dae6: /* original 8bf3, guest PC 0x0c05dae6 */
if(!s->budget--) { s->failed_pc=0x0c05dae6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05dad0; }
goto P_0c05dae8;
P_0c05dae8: /* original d013, guest PC 0x0c05dae8 */
if(!s->budget--) { s->failed_pc=0x0c05dae8u; return 0; }
r[0]=read(ram,0x0c05db38u,4);
goto P_0c05daea;
P_0c05daea: /* original 6302, guest PC 0x0c05daea */
if(!s->budget--) { s->failed_pc=0x0c05daeau; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05daec;
P_0c05daec: /* original 2338, guest PC 0x0c05daec */
if(!s->budget--) { s->failed_pc=0x0c05daecu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05daee;
P_0c05daee: /* original 8b0e, guest PC 0x0c05daee */
if(!s->budget--) { s->failed_pc=0x0c05daeeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05db0e; }
goto P_0c05daf0;
P_0c05daf0: /* original d30e, guest PC 0x0c05daf0 */
if(!s->budget--) { s->failed_pc=0x0c05daf0u; return 0; }
r[3]=read(ram,0x0c05db2cu,4);
goto P_0c05daf2;
P_0c05daf2: /* original a008, guest PC 0x0c05daf2 */
if(!s->budget--) { s->failed_pc=0x0c05daf2u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05db06;
P_0c05daf4: /* original 23e2, guest PC 0x0c05daf4 */
if(!s->budget--) { s->failed_pc=0x0c05daf4u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05daf6;
P_0c05daf6: /* original d10e, guest PC 0x0c05daf6 */
if(!s->budget--) { s->failed_pc=0x0c05daf6u; return 0; }
r[1]=read(ram,0x0c05db30u,4);
goto P_0c05daf8;
P_0c05daf8: /* original 6312, guest PC 0x0c05daf8 */
if(!s->budget--) { s->failed_pc=0x0c05daf8u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05dafa;
P_0c05dafa: /* original 430b, guest PC 0x0c05dafa */
if(!s->budget--) { s->failed_pc=0x0c05dafau; return 0; }
target=r[3];
r[16]=code_base|0x0c05dafeu;
r[4]=read(ram,r[1]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dafeu) { target=s->pc; goto dispatch; }
goto P_0c05dafe;
P_0c05dafc: /* original 5411, guest PC 0x0c05dafc */
if(!s->budget--) { s->failed_pc=0x0c05dafcu; return 0; }
r[4]=read(ram,r[1]+4,4);
goto P_0c05dafe;
P_0c05dafe: /* original d30b, guest PC 0x0c05dafe */
if(!s->budget--) { s->failed_pc=0x0c05dafeu; return 0; }
r[3]=read(ram,0x0c05db2cu,4);
goto P_0c05db00;
P_0c05db00: /* original 6232, guest PC 0x0c05db00 */
if(!s->budget--) { s->failed_pc=0x0c05db00u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05db02;
P_0c05db02: /* original 32d6, guest PC 0x0c05db02 */
if(!s->budget--) { s->failed_pc=0x0c05db02u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[13])!=0);
goto P_0c05db04;
P_0c05db04: /* original 8903, guest PC 0x0c05db04 */
if(!s->budget--) { s->failed_pc=0x0c05db04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05db0e; }
goto P_0c05db06;
P_0c05db06: /* original d00d, guest PC 0x0c05db06 */
if(!s->budget--) { s->failed_pc=0x0c05db06u; return 0; }
r[0]=read(ram,0x0c05db3cu,4);
goto P_0c05db08;
P_0c05db08: /* original 6102, guest PC 0x0c05db08 */
if(!s->budget--) { s->failed_pc=0x0c05db08u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05db0a;
P_0c05db0a: /* original 2118, guest PC 0x0c05db0a */
if(!s->budget--) { s->failed_pc=0x0c05db0au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c05db0c;
P_0c05db0c: /* original 8bf3, guest PC 0x0c05db0c */
if(!s->budget--) { s->failed_pc=0x0c05db0cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05daf6; }
goto P_0c05db0e;
P_0c05db0e: /* original d10b, guest PC 0x0c05db0e */
if(!s->budget--) { s->failed_pc=0x0c05db0eu; return 0; }
r[1]=read(ram,0x0c05db3cu,4);
goto P_0c05db10;
P_0c05db10: /* original 21e2, guest PC 0x0c05db10 */
if(!s->budget--) { s->failed_pc=0x0c05db10u; return 0; }
write(ram,r[1],r[14],4);
goto P_0c05db12;
P_0c05db12: /* original d308, guest PC 0x0c05db12 */
if(!s->budget--) { s->failed_pc=0x0c05db12u; return 0; }
r[3]=read(ram,0x0c05db34u,4);
goto P_0c05db14;
P_0c05db14: /* original 23e2, guest PC 0x0c05db14 */
if(!s->budget--) { s->failed_pc=0x0c05db14u; return 0; }
write(ram,r[3],r[14],4);
goto P_0c05db16;
P_0c05db16: /* original 4f26, guest PC 0x0c05db16 */
if(!s->budget--) { s->failed_pc=0x0c05db16u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05db18;
P_0c05db18: /* original 6df6, guest PC 0x0c05db18 */
if(!s->budget--) { s->failed_pc=0x0c05db18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05db1a;
P_0c05db1a: /* original 000b, guest PC 0x0c05db1a */
if(!s->budget--) { s->failed_pc=0x0c05db1au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05db1c: /* original 6ef6, guest PC 0x0c05db1c */
if(!s->budget--) { s->failed_pc=0x0c05db1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05db1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05db1eu; return 0; } return 1;
P_0c05db40: /* original 2fe6, guest PC 0x0c05db40 */
if(!s->budget--) { s->failed_pc=0x0c05db40u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05db42;
P_0c05db42: /* original 4f22, guest PC 0x0c05db42 */
if(!s->budget--) { s->failed_pc=0x0c05db42u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05db44;
P_0c05db44: /* original de29, guest PC 0x0c05db44 */
if(!s->budget--) { s->failed_pc=0x0c05db44u; return 0; }
r[14]=read(ram,0x0c05dbecu,4);
goto P_0c05db46;
P_0c05db46: /* original d32a, guest PC 0x0c05db46 */
if(!s->budget--) { s->failed_pc=0x0c05db46u; return 0; }
r[3]=read(ram,0x0c05dbf0u,4);
goto P_0c05db48;
P_0c05db48: /* original 6532, guest PC 0x0c05db48 */
if(!s->budget--) { s->failed_pc=0x0c05db48u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db4a;
P_0c05db4a: /* original 4e0b, guest PC 0x0c05db4a */
if(!s->budget--) { s->failed_pc=0x0c05db4au; return 0; }
target=r[14];
r[16]=code_base|0x0c05db4eu;
r[4]=0x00000068u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db4eu) { target=s->pc; goto dispatch; }
goto P_0c05db4e;
P_0c05db4c: /* original e468, guest PC 0x0c05db4c */
if(!s->budget--) { s->failed_pc=0x0c05db4cu; return 0; }
r[4]=0x00000068u;
goto P_0c05db4e;
P_0c05db4e: /* original d229, guest PC 0x0c05db4e */
if(!s->budget--) { s->failed_pc=0x0c05db4eu; return 0; }
r[2]=read(ram,0x0c05dbf4u,4);
goto P_0c05db50;
P_0c05db50: /* original 6522, guest PC 0x0c05db50 */
if(!s->budget--) { s->failed_pc=0x0c05db50u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db52;
P_0c05db52: /* original 4e0b, guest PC 0x0c05db52 */
if(!s->budget--) { s->failed_pc=0x0c05db52u; return 0; }
target=r[14];
r[16]=code_base|0x0c05db56u;
r[4]=0x0000006cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db56u) { target=s->pc; goto dispatch; }
goto P_0c05db56;
P_0c05db54: /* original e46c, guest PC 0x0c05db54 */
if(!s->budget--) { s->failed_pc=0x0c05db54u; return 0; }
r[4]=0x0000006cu;
goto P_0c05db56;
P_0c05db56: /* original d328, guest PC 0x0c05db56 */
if(!s->budget--) { s->failed_pc=0x0c05db56u; return 0; }
r[3]=read(ram,0x0c05dbf8u,4);
goto P_0c05db58;
P_0c05db58: /* original 6532, guest PC 0x0c05db58 */
if(!s->budget--) { s->failed_pc=0x0c05db58u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db5a;
P_0c05db5a: /* original 4e0b, guest PC 0x0c05db5a */
if(!s->budget--) { s->failed_pc=0x0c05db5au; return 0; }
target=r[14];
r[16]=code_base|0x0c05db5eu;
r[4]=0x0000005cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db5eu) { target=s->pc; goto dispatch; }
goto P_0c05db5e;
P_0c05db5c: /* original e45c, guest PC 0x0c05db5c */
if(!s->budget--) { s->failed_pc=0x0c05db5cu; return 0; }
r[4]=0x0000005cu;
goto P_0c05db5e;
P_0c05db5e: /* original d227, guest PC 0x0c05db5e */
if(!s->budget--) { s->failed_pc=0x0c05db5eu; return 0; }
r[2]=read(ram,0x0c05dbfcu,4);
goto P_0c05db60;
P_0c05db60: /* original 6522, guest PC 0x0c05db60 */
if(!s->budget--) { s->failed_pc=0x0c05db60u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db62;
P_0c05db62: /* original 4e0b, guest PC 0x0c05db62 */
if(!s->budget--) { s->failed_pc=0x0c05db62u; return 0; }
target=r[14];
r[16]=code_base|0x0c05db66u;
r[4]=0x0000004cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db66u) { target=s->pc; goto dispatch; }
goto P_0c05db66;
P_0c05db64: /* original e44c, guest PC 0x0c05db64 */
if(!s->budget--) { s->failed_pc=0x0c05db64u; return 0; }
r[4]=0x0000004cu;
goto P_0c05db66;
P_0c05db66: /* original d326, guest PC 0x0c05db66 */
if(!s->budget--) { s->failed_pc=0x0c05db66u; return 0; }
r[3]=read(ram,0x0c05dc00u,4);
goto P_0c05db68;
P_0c05db68: /* original 943c, guest PC 0x0c05db68 */
if(!s->budget--) { s->failed_pc=0x0c05db68u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dbe4u,2);
goto P_0c05db6a;
P_0c05db6a: /* original 4e0b, guest PC 0x0c05db6a */
if(!s->budget--) { s->failed_pc=0x0c05db6au; return 0; }
target=r[14];
r[16]=code_base|0x0c05db6eu;
tmp=read(ram,r[3],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db6eu) { target=s->pc; goto dispatch; }
goto P_0c05db6e;
P_0c05db6c: /* original 6532, guest PC 0x0c05db6c */
if(!s->budget--) { s->failed_pc=0x0c05db6cu; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db6e;
P_0c05db6e: /* original d225, guest PC 0x0c05db6e */
if(!s->budget--) { s->failed_pc=0x0c05db6eu; return 0; }
r[2]=read(ram,0x0c05dc04u,4);
goto P_0c05db70;
P_0c05db70: /* original 9439, guest PC 0x0c05db70 */
if(!s->budget--) { s->failed_pc=0x0c05db70u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dbe6u,2);
goto P_0c05db72;
P_0c05db72: /* original 4e0b, guest PC 0x0c05db72 */
if(!s->budget--) { s->failed_pc=0x0c05db72u; return 0; }
target=r[14];
r[16]=code_base|0x0c05db76u;
tmp=read(ram,r[2],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db76u) { target=s->pc; goto dispatch; }
goto P_0c05db76;
P_0c05db74: /* original 6522, guest PC 0x0c05db74 */
if(!s->budget--) { s->failed_pc=0x0c05db74u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db76;
P_0c05db76: /* original d324, guest PC 0x0c05db76 */
if(!s->budget--) { s->failed_pc=0x0c05db76u; return 0; }
r[3]=read(ram,0x0c05dc08u,4);
goto P_0c05db78;
P_0c05db78: /* original 6532, guest PC 0x0c05db78 */
if(!s->budget--) { s->failed_pc=0x0c05db78u; return 0; }
tmp=read(ram,r[3],4);
r[5]=tmp;
goto P_0c05db7a;
P_0c05db7a: /* original 4e0b, guest PC 0x0c05db7a */
if(!s->budget--) { s->failed_pc=0x0c05db7au; return 0; }
target=r[14];
r[16]=code_base|0x0c05db7eu;
r[4]=0x00000048u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db7eu) { target=s->pc; goto dispatch; }
goto P_0c05db7e;
P_0c05db7c: /* original e448, guest PC 0x0c05db7c */
if(!s->budget--) { s->failed_pc=0x0c05db7cu; return 0; }
r[4]=0x00000048u;
goto P_0c05db7e;
P_0c05db7e: /* original e3fe, guest PC 0x0c05db7e */
if(!s->budget--) { s->failed_pc=0x0c05db7eu; return 0; }
r[3]=0xfffffffeu;
goto P_0c05db80;
P_0c05db80: /* original d222, guest PC 0x0c05db80 */
if(!s->budget--) { s->failed_pc=0x0c05db80u; return 0; }
r[2]=read(ram,0x0c05dc0cu,4);
goto P_0c05db82;
P_0c05db82: /* original 6522, guest PC 0x0c05db82 */
if(!s->budget--) { s->failed_pc=0x0c05db82u; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c05db84;
P_0c05db84: /* original 2539, guest PC 0x0c05db84 */
if(!s->budget--) { s->failed_pc=0x0c05db84u; return 0; }
r[5]&=r[3];
goto P_0c05db86;
P_0c05db86: /* original 4e0b, guest PC 0x0c05db86 */
if(!s->budget--) { s->failed_pc=0x0c05db86u; return 0; }
target=r[14];
r[16]=code_base|0x0c05db8au;
r[4]=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db8au) { target=s->pc; goto dispatch; }
goto P_0c05db8a;
P_0c05db88: /* original e444, guest PC 0x0c05db88 */
if(!s->budget--) { s->failed_pc=0x0c05db88u; return 0; }
r[4]=0x00000044u;
goto P_0c05db8a;
P_0c05db8a: /* original d321, guest PC 0x0c05db8a */
if(!s->budget--) { s->failed_pc=0x0c05db8au; return 0; }
r[3]=read(ram,0x0c05dc10u,4);
goto P_0c05db8c;
P_0c05db8c: /* original 6032, guest PC 0x0c05db8c */
if(!s->budget--) { s->failed_pc=0x0c05db8cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05db8e;
P_0c05db8e: /* original cb08, guest PC 0x0c05db8e */
if(!s->budget--) { s->failed_pc=0x0c05db8eu; return 0; }
r[0]|=8u;
goto P_0c05db90;
P_0c05db90: /* original 942a, guest PC 0x0c05db90 */
if(!s->budget--) { s->failed_pc=0x0c05db90u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dbe8u,2);
goto P_0c05db92;
P_0c05db92: /* original 4e0b, guest PC 0x0c05db92 */
if(!s->budget--) { s->failed_pc=0x0c05db92u; return 0; }
target=r[14];
r[16]=code_base|0x0c05db96u;
r[5]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05db96u) { target=s->pc; goto dispatch; }
goto P_0c05db96;
P_0c05db94: /* original 6503, guest PC 0x0c05db94 */
if(!s->budget--) { s->failed_pc=0x0c05db94u; return 0; }
r[5]=r[0];
goto P_0c05db96;
P_0c05db96: /* original 4f26, guest PC 0x0c05db96 */
if(!s->budget--) { s->failed_pc=0x0c05db96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05db98;
P_0c05db98: /* original 000b, guest PC 0x0c05db98 */
if(!s->budget--) { s->failed_pc=0x0c05db98u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05db9a: /* original 6ef6, guest PC 0x0c05db9a */
if(!s->budget--) { s->failed_pc=0x0c05db9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05db9c;
P_0c05db9c: /* original d31d, guest PC 0x0c05db9c */
if(!s->budget--) { s->failed_pc=0x0c05db9cu; return 0; }
r[3]=read(ram,0x0c05dc14u,4);
goto P_0c05db9e;
P_0c05db9e: /* original 6432, guest PC 0x0c05db9e */
if(!s->budget--) { s->failed_pc=0x0c05db9eu; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c05dba0;
P_0c05dba0: /* original d21c, guest PC 0x0c05dba0 */
if(!s->budget--) { s->failed_pc=0x0c05dba0u; return 0; }
r[2]=read(ram,0x0c05dc14u,4);
goto P_0c05dba2;
P_0c05dba2: /* original 6122, guest PC 0x0c05dba2 */
if(!s->budget--) { s->failed_pc=0x0c05dba2u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05dba4;
P_0c05dba4: /* original 3410, guest PC 0x0c05dba4 */
if(!s->budget--) { s->failed_pc=0x0c05dba4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[1])!=0);
goto P_0c05dba6;
P_0c05dba6: /* original 89fb, guest PC 0x0c05dba6 */
if(!s->budget--) { s->failed_pc=0x0c05dba6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dba0; }
goto P_0c05dba8;
P_0c05dba8: /* original 000b, guest PC 0x0c05dba8 */
if(!s->budget--) { s->failed_pc=0x0c05dba8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05dbaa: /* original 0009, guest PC 0x0c05dbaa */
if(!s->budget--) { s->failed_pc=0x0c05dbaau; return 0; }
if(!vf3_matrix_family(0x0c05dbacu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05dbacu; return 0; } return 1;
P_0c05dc30: /* original 2fe6, guest PC 0x0c05dc30 */
if(!s->budget--) { s->failed_pc=0x0c05dc30u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc32;
P_0c05dc32: /* original 2fd6, guest PC 0x0c05dc32 */
if(!s->budget--) { s->failed_pc=0x0c05dc32u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc34;
P_0c05dc34: /* original 2fc6, guest PC 0x0c05dc34 */
if(!s->budget--) { s->failed_pc=0x0c05dc34u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc36;
P_0c05dc36: /* original 2fb6, guest PC 0x0c05dc36 */
if(!s->budget--) { s->failed_pc=0x0c05dc36u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc38;
P_0c05dc38: /* original 2fa6, guest PC 0x0c05dc38 */
if(!s->budget--) { s->failed_pc=0x0c05dc38u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc3a;
P_0c05dc3a: /* original 2f96, guest PC 0x0c05dc3a */
if(!s->budget--) { s->failed_pc=0x0c05dc3au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc3c;
P_0c05dc3c: /* original 2f86, guest PC 0x0c05dc3c */
if(!s->budget--) { s->failed_pc=0x0c05dc3cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dc3e;
P_0c05dc3e: /* original 6853, guest PC 0x0c05dc3e */
if(!s->budget--) { s->failed_pc=0x0c05dc3eu; return 0; }
r[8]=r[5];
goto P_0c05dc40;
P_0c05dc40: /* original d330, guest PC 0x0c05dc40 */
if(!s->budget--) { s->failed_pc=0x0c05dc40u; return 0; }
r[3]=read(ram,0x0c05dd04u,4);
goto P_0c05dc42;
P_0c05dc42: /* original 4f22, guest PC 0x0c05dc42 */
if(!s->budget--) { s->failed_pc=0x0c05dc42u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05dc44;
P_0c05dc44: /* original 7ff4, guest PC 0x0c05dc44 */
if(!s->budget--) { s->failed_pc=0x0c05dc44u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c05dc46;
P_0c05dc46: /* original 2f42, guest PC 0x0c05dc46 */
if(!s->budget--) { s->failed_pc=0x0c05dc46u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05dc48;
P_0c05dc48: /* original 1f62, guest PC 0x0c05dc48 */
if(!s->budget--) { s->failed_pc=0x0c05dc48u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c05dc4a;
P_0c05dc4a: /* original 1f71, guest PC 0x0c05dc4a */
if(!s->budget--) { s->failed_pc=0x0c05dc4au; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c05dc4c;
P_0c05dc4c: /* original 430b, guest PC 0x0c05dc4c */
if(!s->budget--) { s->failed_pc=0x0c05dc4cu; return 0; }
target=r[3];
r[16]=code_base|0x0c05dc50u;
r[14]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dc50u) { target=s->pc; goto dispatch; }
goto P_0c05dc50;
P_0c05dc4e: /* original ee00, guest PC 0x0c05dc4e */
if(!s->budget--) { s->failed_pc=0x0c05dc4eu; return 0; }
r[14]=0x00000000u;
goto P_0c05dc50;
P_0c05dc50: /* original dc2d, guest PC 0x0c05dc50 */
if(!s->budget--) { s->failed_pc=0x0c05dc50u; return 0; }
r[12]=read(ram,0x0c05dd08u,4);
goto P_0c05dc52;
P_0c05dc52: /* original dd2e, guest PC 0x0c05dc52 */
if(!s->budget--) { s->failed_pc=0x0c05dc52u; return 0; }
r[13]=read(ram,0x0c05dd0cu,4);
goto P_0c05dc54;
P_0c05dc54: /* original 66f2, guest PC 0x0c05dc54 */
if(!s->budget--) { s->failed_pc=0x0c05dc54u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c05dc56;
P_0c05dc56: /* original d52e, guest PC 0x0c05dc56 */
if(!s->budget--) { s->failed_pc=0x0c05dc56u; return 0; }
r[5]=read(ram,0x0c05dd10u,4);
goto P_0c05dc58;
P_0c05dc58: /* original 4c0b, guest PC 0x0c05dc58 */
if(!s->budget--) { s->failed_pc=0x0c05dc58u; return 0; }
target=r[12];
r[16]=code_base|0x0c05dc5cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dc5cu) { target=s->pc; goto dispatch; }
goto P_0c05dc5c;
P_0c05dc5a: /* original 64d3, guest PC 0x0c05dc5a */
if(!s->budget--) { s->failed_pc=0x0c05dc5au; return 0; }
r[4]=r[13];
goto P_0c05dc5c;
P_0c05dc5c: /* original 56f1, guest PC 0x0c05dc5c */
if(!s->budget--) { s->failed_pc=0x0c05dc5cu; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c05dc5e;
P_0c05dc5e: /* original 6b03, guest PC 0x0c05dc5e */
if(!s->budget--) { s->failed_pc=0x0c05dc5eu; return 0; }
r[11]=r[0];
goto P_0c05dc60;
P_0c05dc60: /* original d52c, guest PC 0x0c05dc60 */
if(!s->budget--) { s->failed_pc=0x0c05dc60u; return 0; }
r[5]=read(ram,0x0c05dd14u,4);
goto P_0c05dc62;
P_0c05dc62: /* original 4c0b, guest PC 0x0c05dc62 */
if(!s->budget--) { s->failed_pc=0x0c05dc62u; return 0; }
target=r[12];
r[16]=code_base|0x0c05dc66u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dc66u) { target=s->pc; goto dispatch; }
goto P_0c05dc66;
P_0c05dc64: /* original 64d3, guest PC 0x0c05dc64 */
if(!s->budget--) { s->failed_pc=0x0c05dc64u; return 0; }
r[4]=r[13];
goto P_0c05dc66;
P_0c05dc66: /* original 2f02, guest PC 0x0c05dc66 */
if(!s->budget--) { s->failed_pc=0x0c05dc66u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05dc68;
P_0c05dc68: /* original 56f2, guest PC 0x0c05dc68 */
if(!s->budget--) { s->failed_pc=0x0c05dc68u; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c05dc6a;
P_0c05dc6a: /* original d52b, guest PC 0x0c05dc6a */
if(!s->budget--) { s->failed_pc=0x0c05dc6au; return 0; }
r[5]=read(ram,0x0c05dd18u,4);
goto P_0c05dc6c;
P_0c05dc6c: /* original 4c0b, guest PC 0x0c05dc6c */
if(!s->budget--) { s->failed_pc=0x0c05dc6cu; return 0; }
target=r[12];
r[16]=code_base|0x0c05dc70u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dc70u) { target=s->pc; goto dispatch; }
goto P_0c05dc70;
P_0c05dc6e: /* original 64d3, guest PC 0x0c05dc6e */
if(!s->budget--) { s->failed_pc=0x0c05dc6eu; return 0; }
r[4]=r[13];
goto P_0c05dc70;
P_0c05dc70: /* original d22a, guest PC 0x0c05dc70 */
if(!s->budget--) { s->failed_pc=0x0c05dc70u; return 0; }
r[2]=read(ram,0x0c05dd1cu,4);
goto P_0c05dc72;
P_0c05dc72: /* original 6603, guest PC 0x0c05dc72 */
if(!s->budget--) { s->failed_pc=0x0c05dc72u; return 0; }
r[6]=r[0];
goto P_0c05dc74;
P_0c05dc74: /* original e303, guest PC 0x0c05dc74 */
if(!s->budget--) { s->failed_pc=0x0c05dc74u; return 0; }
r[3]=0x00000003u;
goto P_0c05dc76;
P_0c05dc76: /* original 23b9, guest PC 0x0c05dc76 */
if(!s->budget--) { s->failed_pc=0x0c05dc76u; return 0; }
r[3]&=r[11];
goto P_0c05dc78;
P_0c05dc78: /* original 6083, guest PC 0x0c05dc78 */
if(!s->budget--) { s->failed_pc=0x0c05dc78u; return 0; }
r[0]=r[8];
goto P_0c05dc7a;
P_0c05dc7a: /* original 0009, guest PC 0x0c05dc7a */
if(!s->budget--) { s->failed_pc=0x0c05dc7au; return 0; }
goto P_0c05dc7c;
P_0c05dc7c: /* original 8800, guest PC 0x0c05dc7c */
if(!s->budget--) { s->failed_pc=0x0c05dc7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05dc7e;
P_0c05dc7e: /* original 8d09, guest PC 0x0c05dc7e */
if(!s->budget--) { s->failed_pc=0x0c05dc7eu; return 0; }
cond=r[17]&1u;
write(ram,r[2],r[3],4);
if(cond) { goto P_0c05dc94; }
goto P_0c05dc82;
P_0c05dc80: /* original 2232, guest PC 0x0c05dc80 */
if(!s->budget--) { s->failed_pc=0x0c05dc80u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05dc82;
P_0c05dc82: /* original 8801, guest PC 0x0c05dc82 */
if(!s->budget--) { s->failed_pc=0x0c05dc82u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05dc84;
P_0c05dc84: /* original 8906, guest PC 0x0c05dc84 */
if(!s->budget--) { s->failed_pc=0x0c05dc84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dc94; }
goto P_0c05dc86;
P_0c05dc86: /* original 8803, guest PC 0x0c05dc86 */
if(!s->budget--) { s->failed_pc=0x0c05dc86u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05dc88;
P_0c05dc88: /* original 8904, guest PC 0x0c05dc88 */
if(!s->budget--) { s->failed_pc=0x0c05dc88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dc94; }
goto P_0c05dc8a;
P_0c05dc8a: /* original 8804, guest PC 0x0c05dc8a */
if(!s->budget--) { s->failed_pc=0x0c05dc8au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05dc8c;
P_0c05dc8c: /* original 8902, guest PC 0x0c05dc8c */
if(!s->budget--) { s->failed_pc=0x0c05dc8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dc94; }
goto P_0c05dc8e;
P_0c05dc8e: /* original 8805, guest PC 0x0c05dc8e */
if(!s->budget--) { s->failed_pc=0x0c05dc8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c05dc90;
P_0c05dc90: /* original 8900, guest PC 0x0c05dc90 */
if(!s->budget--) { s->failed_pc=0x0c05dc90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dc94; }
goto P_0c05dc92;
P_0c05dc92: /* original ee01, guest PC 0x0c05dc92 */
if(!s->budget--) { s->failed_pc=0x0c05dc92u; return 0; }
r[14]=0x00000001u;
goto P_0c05dc94;
P_0c05dc94: /* original 63f2, guest PC 0x0c05dc94 */
if(!s->budget--) { s->failed_pc=0x0c05dc94u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05dc96;
P_0c05dc96: /* original 2338, guest PC 0x0c05dc96 */
if(!s->budget--) { s->failed_pc=0x0c05dc96u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05dc98;
P_0c05dc98: /* original 8901, guest PC 0x0c05dc98 */
if(!s->budget--) { s->failed_pc=0x0c05dc98u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dc9e; }
goto P_0c05dc9a;
P_0c05dc9a: /* original a001, guest PC 0x0c05dc9a */
if(!s->budget--) { s->failed_pc=0x0c05dc9au; return 0; }
r[12]=0x00000001u;
goto P_0c05dca0;
P_0c05dc9c: /* original ec01, guest PC 0x0c05dc9c */
if(!s->budget--) { s->failed_pc=0x0c05dc9cu; return 0; }
r[12]=0x00000001u;
goto P_0c05dc9e;
P_0c05dc9e: /* original ec00, guest PC 0x0c05dc9e */
if(!s->budget--) { s->failed_pc=0x0c05dc9eu; return 0; }
r[12]=0x00000000u;
goto P_0c05dca0;
P_0c05dca0: /* original 2668, guest PC 0x0c05dca0 */
if(!s->budget--) { s->failed_pc=0x0c05dca0u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c05dca2;
P_0c05dca2: /* original 8901, guest PC 0x0c05dca2 */
if(!s->budget--) { s->failed_pc=0x0c05dca2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dca8; }
goto P_0c05dca4;
P_0c05dca4: /* original a001, guest PC 0x0c05dca4 */
if(!s->budget--) { s->failed_pc=0x0c05dca4u; return 0; }
r[9]=0x00000001u;
goto P_0c05dcaa;
P_0c05dca6: /* original e901, guest PC 0x0c05dca6 */
if(!s->budget--) { s->failed_pc=0x0c05dca6u; return 0; }
r[9]=0x00000001u;
goto P_0c05dca8;
P_0c05dca8: /* original e900, guest PC 0x0c05dca8 */
if(!s->budget--) { s->failed_pc=0x0c05dca8u; return 0; }
r[9]=0x00000000u;
goto P_0c05dcaa;
P_0c05dcaa: /* original 2ee8, guest PC 0x0c05dcaa */
if(!s->budget--) { s->failed_pc=0x0c05dcaau; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c05dcac;
P_0c05dcac: /* original 8b70, guest PC 0x0c05dcac */
if(!s->budget--) { s->failed_pc=0x0c05dcacu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05dd90; }
goto P_0c05dcae;
P_0c05dcae: /* original d31c, guest PC 0x0c05dcae */
if(!s->budget--) { s->failed_pc=0x0c05dcaeu; return 0; }
r[3]=read(ram,0x0c05dd20u,4);
goto P_0c05dcb0;
P_0c05dcb0: /* original 23b2, guest PC 0x0c05dcb0 */
if(!s->budget--) { s->failed_pc=0x0c05dcb0u; return 0; }
write(ram,r[3],r[11],4);
goto P_0c05dcb2;
P_0c05dcb2: /* original d21c, guest PC 0x0c05dcb2 */
if(!s->budget--) { s->failed_pc=0x0c05dcb2u; return 0; }
r[2]=read(ram,0x0c05dd24u,4);
goto P_0c05dcb4;
P_0c05dcb4: /* original 2282, guest PC 0x0c05dcb4 */
if(!s->budget--) { s->failed_pc=0x0c05dcb4u; return 0; }
write(ram,r[2],r[8],4);
goto P_0c05dcb6;
P_0c05dcb6: /* original d11c, guest PC 0x0c05dcb6 */
if(!s->budget--) { s->failed_pc=0x0c05dcb6u; return 0; }
r[1]=read(ram,0x0c05dd28u,4);
goto P_0c05dcb8;
P_0c05dcb8: /* original 2192, guest PC 0x0c05dcb8 */
if(!s->budget--) { s->failed_pc=0x0c05dcb8u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05dcba;
P_0c05dcba: /* original 730c, guest PC 0x0c05dcba */
if(!s->budget--) { s->failed_pc=0x0c05dcbau; return 0; }
r[3]+=0x0000000cu;
goto P_0c05dcbc;
P_0c05dcbc: /* original 23c2, guest PC 0x0c05dcbc */
if(!s->budget--) { s->failed_pc=0x0c05dcbcu; return 0; }
write(ram,r[3],r[12],4);
goto P_0c05dcbe;
P_0c05dcbe: /* original 72fc, guest PC 0x0c05dcbe */
if(!s->budget--) { s->failed_pc=0x0c05dcbeu; return 0; }
r[2]+=0xfffffffcu;
goto P_0c05dcc0;
P_0c05dcc0: /* original 6022, guest PC 0x0c05dcc0 */
if(!s->budget--) { s->failed_pc=0x0c05dcc0u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05dcc2;
P_0c05dcc2: /* original 8801, guest PC 0x0c05dcc2 */
if(!s->budget--) { s->failed_pc=0x0c05dcc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05dcc4;
P_0c05dcc4: /* original 8b05, guest PC 0x0c05dcc4 */
if(!s->budget--) { s->failed_pc=0x0c05dcc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05dcd2; }
goto P_0c05dcc6;
P_0c05dcc6: /* original ea00, guest PC 0x0c05dcc6 */
if(!s->budget--) { s->failed_pc=0x0c05dcc6u; return 0; }
r[10]=0x00000000u;
goto P_0c05dcc8;
P_0c05dcc8: /* original d018, guest PC 0x0c05dcc8 */
if(!s->budget--) { s->failed_pc=0x0c05dcc8u; return 0; }
r[0]=read(ram,0x0c05dd2cu,4);
goto P_0c05dcca;
P_0c05dcca: /* original 9b18, guest PC 0x0c05dcca */
if(!s->budget--) { s->failed_pc=0x0c05dccau; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dcfeu,2);
goto P_0c05dccc;
P_0c05dccc: /* original 9d18, guest PC 0x0c05dccc */
if(!s->budget--) { s->failed_pc=0x0c05dcccu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dd00u,2);
goto P_0c05dcce;
P_0c05dcce: /* original a03b, guest PC 0x0c05dcce */
if(!s->budget--) { s->failed_pc=0x0c05dcceu; return 0; }
write(ram,r[0],r[13],4);
goto P_0c05dd48;
P_0c05dcd0: /* original 20d2, guest PC 0x0c05dcd0 */
if(!s->budget--) { s->failed_pc=0x0c05dcd0u; return 0; }
write(ram,r[0],r[13],4);
goto P_0c05dcd2;
P_0c05dcd2: /* original e401, guest PC 0x0c05dcd2 */
if(!s->budget--) { s->failed_pc=0x0c05dcd2u; return 0; }
r[4]=0x00000001u;
goto P_0c05dcd4;
P_0c05dcd4: /* original d112, guest PC 0x0c05dcd4 */
if(!s->budget--) { s->failed_pc=0x0c05dcd4u; return 0; }
r[1]=read(ram,0x0c05dd20u,4);
goto P_0c05dcd6;
P_0c05dcd6: /* original 6012, guest PC 0x0c05dcd6 */
if(!s->budget--) { s->failed_pc=0x0c05dcd6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05dcd8;
P_0c05dcd8: /* original 2049, guest PC 0x0c05dcd8 */
if(!s->budget--) { s->failed_pc=0x0c05dcd8u; return 0; }
r[0]&=r[4];
goto P_0c05dcda;
P_0c05dcda: /* original 8801, guest PC 0x0c05dcda */
if(!s->budget--) { s->failed_pc=0x0c05dcdau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05dcdc;
P_0c05dcdc: /* original 8907, guest PC 0x0c05dcdc */
if(!s->budget--) { s->failed_pc=0x0c05dcdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dcee; }
goto P_0c05dcde;
P_0c05dcde: /* original d310, guest PC 0x0c05dcde */
if(!s->budget--) { s->failed_pc=0x0c05dcdeu; return 0; }
r[3]=read(ram,0x0c05dd20u,4);
goto P_0c05dce0;
P_0c05dce0: /* original 6032, guest PC 0x0c05dce0 */
if(!s->budget--) { s->failed_pc=0x0c05dce0u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05dce2;
P_0c05dce2: /* original c82c, guest PC 0x0c05dce2 */
if(!s->budget--) { s->failed_pc=0x0c05dce2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&44u)==0)!=0);
goto P_0c05dce4;
P_0c05dce4: /* original 8903, guest PC 0x0c05dce4 */
if(!s->budget--) { s->failed_pc=0x0c05dce4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dcee; }
goto P_0c05dce6;
P_0c05dce6: /* original 2448, guest PC 0x0c05dce6 */
if(!s->budget--) { s->failed_pc=0x0c05dce6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c05dce8;
P_0c05dce8: /* original 8901, guest PC 0x0c05dce8 */
if(!s->budget--) { s->failed_pc=0x0c05dce8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dcee; }
goto P_0c05dcea;
P_0c05dcea: /* original a001, guest PC 0x0c05dcea */
if(!s->budget--) { s->failed_pc=0x0c05dceau; return 0; }
r[10]=0x00000001u;
goto P_0c05dcf0;
P_0c05dcec: /* original ea01, guest PC 0x0c05dcec */
if(!s->budget--) { s->failed_pc=0x0c05dcecu; return 0; }
r[10]=0x00000001u;
goto P_0c05dcee;
P_0c05dcee: /* original ea00, guest PC 0x0c05dcee */
if(!s->budget--) { s->failed_pc=0x0c05dceeu; return 0; }
r[10]=0x00000000u;
goto P_0c05dcf0;
P_0c05dcf0: /* original d20b, guest PC 0x0c05dcf0 */
if(!s->budget--) { s->failed_pc=0x0c05dcf0u; return 0; }
r[2]=read(ram,0x0c05dd20u,4);
goto P_0c05dcf2;
P_0c05dcf2: /* original 6022, guest PC 0x0c05dcf2 */
if(!s->budget--) { s->failed_pc=0x0c05dcf2u; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05dcf4;
P_0c05dcf4: /* original c810, guest PC 0x0c05dcf4 */
if(!s->budget--) { s->failed_pc=0x0c05dcf4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c05dcf6;
P_0c05dcf6: /* original 891b, guest PC 0x0c05dcf6 */
if(!s->budget--) { s->failed_pc=0x0c05dcf6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dd30; }
goto P_0c05dcf8;
P_0c05dcf8: /* original 9b01, guest PC 0x0c05dcf8 */
if(!s->budget--) { s->failed_pc=0x0c05dcf8u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05dcfeu,2);
goto P_0c05dcfa;
P_0c05dcfa: /* original a01a, guest PC 0x0c05dcfa */
if(!s->budget--) { s->failed_pc=0x0c05dcfau; return 0; }
goto P_0c05dd32;
P_0c05dcfc: /* original 0009, guest PC 0x0c05dcfc */
if(!s->budget--) { s->failed_pc=0x0c05dcfcu; return 0; }
if(!vf3_matrix_family(0x0c05dcfeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05dcfeu; return 0; } return 1;
P_0c05dd30: /* original 9b7d, guest PC 0x0c05dd30 */
if(!s->budget--) { s->failed_pc=0x0c05dd30u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05de2eu,2);
goto P_0c05dd32;
P_0c05dd32: /* original d341, guest PC 0x0c05dd32 */
if(!s->budget--) { s->failed_pc=0x0c05dd32u; return 0; }
r[3]=read(ram,0x0c05de38u,4);
goto P_0c05dd34;
P_0c05dd34: /* original 6032, guest PC 0x0c05dd34 */
if(!s->budget--) { s->failed_pc=0x0c05dd34u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05dd36;
P_0c05dd36: /* original c820, guest PC 0x0c05dd36 */
if(!s->budget--) { s->failed_pc=0x0c05dd36u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05dd38;
P_0c05dd38: /* original 8902, guest PC 0x0c05dd38 */
if(!s->budget--) { s->failed_pc=0x0c05dd38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dd40; }
goto P_0c05dd3a;
P_0c05dd3a: /* original 9d79, guest PC 0x0c05dd3a */
if(!s->budget--) { s->failed_pc=0x0c05dd3au; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05de30u,2);
goto P_0c05dd3c;
P_0c05dd3c: /* original a001, guest PC 0x0c05dd3c */
if(!s->budget--) { s->failed_pc=0x0c05dd3cu; return 0; }
goto P_0c05dd42;
P_0c05dd3e: /* original 0009, guest PC 0x0c05dd3e */
if(!s->budget--) { s->failed_pc=0x0c05dd3eu; return 0; }
goto P_0c05dd40;
P_0c05dd40: /* original 9d77, guest PC 0x0c05dd40 */
if(!s->budget--) { s->failed_pc=0x0c05dd40u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05de32u,2);
goto P_0c05dd42;
P_0c05dd42: /* original 9376, guest PC 0x0c05dd42 */
if(!s->budget--) { s->failed_pc=0x0c05dd42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05de32u,2);
goto P_0c05dd44;
P_0c05dd44: /* original d23d, guest PC 0x0c05dd44 */
if(!s->budget--) { s->failed_pc=0x0c05dd44u; return 0; }
r[2]=read(ram,0x0c05de3cu,4);
goto P_0c05dd46;
P_0c05dd46: /* original 2232, guest PC 0x0c05dd46 */
if(!s->budget--) { s->failed_pc=0x0c05dd46u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05dd48;
P_0c05dd48: /* original d13d, guest PC 0x0c05dd48 */
if(!s->budget--) { s->failed_pc=0x0c05dd48u; return 0; }
r[1]=read(ram,0x0c05de40u,4);
goto P_0c05dd4a;
P_0c05dd4a: /* original 6012, guest PC 0x0c05dd4a */
if(!s->budget--) { s->failed_pc=0x0c05dd4au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c05dd4c;
P_0c05dd4c: /* original 8800, guest PC 0x0c05dd4c */
if(!s->budget--) { s->failed_pc=0x0c05dd4cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c05dd4e;
P_0c05dd4e: /* original 890a, guest PC 0x0c05dd4e */
if(!s->budget--) { s->failed_pc=0x0c05dd4eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dd66; }
goto P_0c05dd50;
P_0c05dd50: /* original 8801, guest PC 0x0c05dd50 */
if(!s->budget--) { s->failed_pc=0x0c05dd50u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05dd52;
P_0c05dd52: /* original 8903, guest PC 0x0c05dd52 */
if(!s->budget--) { s->failed_pc=0x0c05dd52u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dd5c; }
goto P_0c05dd54;
P_0c05dd54: /* original 8802, guest PC 0x0c05dd54 */
if(!s->budget--) { s->failed_pc=0x0c05dd54u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05dd56;
P_0c05dd56: /* original 890b, guest PC 0x0c05dd56 */
if(!s->budget--) { s->failed_pc=0x0c05dd56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05dd70; }
goto P_0c05dd58;
P_0c05dd58: /* original a00f, guest PC 0x0c05dd58 */
if(!s->budget--) { s->failed_pc=0x0c05dd58u; return 0; }
goto P_0c05dd7a;
P_0c05dd5a: /* original 0009, guest PC 0x0c05dd5a */
if(!s->budget--) { s->failed_pc=0x0c05dd5au; return 0; }
goto P_0c05dd5c;
P_0c05dd5c: /* original d339, guest PC 0x0c05dd5c */
if(!s->budget--) { s->failed_pc=0x0c05dd5cu; return 0; }
r[3]=read(ram,0x0c05de44u,4);
goto P_0c05dd5e;
P_0c05dd5e: /* original 430b, guest PC 0x0c05dd5e */
if(!s->budget--) { s->failed_pc=0x0c05dd5eu; return 0; }
target=r[3];
r[16]=code_base|0x0c05dd62u;
r[14]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dd62u) { target=s->pc; goto dispatch; }
goto P_0c05dd62;
P_0c05dd60: /* original ee00, guest PC 0x0c05dd60 */
if(!s->budget--) { s->failed_pc=0x0c05dd60u; return 0; }
r[14]=0x00000000u;
goto P_0c05dd62;
P_0c05dd62: /* original a00b, guest PC 0x0c05dd62 */
if(!s->budget--) { s->failed_pc=0x0c05dd62u; return 0; }
goto P_0c05dd7c;
P_0c05dd64: /* original 0009, guest PC 0x0c05dd64 */
if(!s->budget--) { s->failed_pc=0x0c05dd64u; return 0; }
goto P_0c05dd66;
P_0c05dd66: /* original d338, guest PC 0x0c05dd66 */
if(!s->budget--) { s->failed_pc=0x0c05dd66u; return 0; }
r[3]=read(ram,0x0c05de48u,4);
goto P_0c05dd68;
P_0c05dd68: /* original 430b, guest PC 0x0c05dd68 */
if(!s->budget--) { s->failed_pc=0x0c05dd68u; return 0; }
target=r[3];
r[16]=code_base|0x0c05dd6cu;
r[14]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dd6cu) { target=s->pc; goto dispatch; }
goto P_0c05dd6c;
P_0c05dd6a: /* original ee00, guest PC 0x0c05dd6a */
if(!s->budget--) { s->failed_pc=0x0c05dd6au; return 0; }
r[14]=0x00000000u;
goto P_0c05dd6c;
P_0c05dd6c: /* original a006, guest PC 0x0c05dd6c */
if(!s->budget--) { s->failed_pc=0x0c05dd6cu; return 0; }
goto P_0c05dd7c;
P_0c05dd6e: /* original 0009, guest PC 0x0c05dd6e */
if(!s->budget--) { s->failed_pc=0x0c05dd6eu; return 0; }
goto P_0c05dd70;
P_0c05dd70: /* original d336, guest PC 0x0c05dd70 */
if(!s->budget--) { s->failed_pc=0x0c05dd70u; return 0; }
r[3]=read(ram,0x0c05de4cu,4);
goto P_0c05dd72;
P_0c05dd72: /* original 430b, guest PC 0x0c05dd72 */
if(!s->budget--) { s->failed_pc=0x0c05dd72u; return 0; }
target=r[3];
r[16]=code_base|0x0c05dd76u;
r[14]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dd76u) { target=s->pc; goto dispatch; }
goto P_0c05dd76;
P_0c05dd74: /* original ee00, guest PC 0x0c05dd74 */
if(!s->budget--) { s->failed_pc=0x0c05dd74u; return 0; }
r[14]=0x00000000u;
goto P_0c05dd76;
P_0c05dd76: /* original a001, guest PC 0x0c05dd76 */
if(!s->budget--) { s->failed_pc=0x0c05dd76u; return 0; }
goto P_0c05dd7c;
P_0c05dd78: /* original 0009, guest PC 0x0c05dd78 */
if(!s->budget--) { s->failed_pc=0x0c05dd78u; return 0; }
goto P_0c05dd7a;
P_0c05dd7a: /* original ee01, guest PC 0x0c05dd7a */
if(!s->budget--) { s->failed_pc=0x0c05dd7au; return 0; }
r[14]=0x00000001u;
goto P_0c05dd7c;
P_0c05dd7c: /* original 2fc6, guest PC 0x0c05dd7c */
if(!s->budget--) { s->failed_pc=0x0c05dd7cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dd7e;
P_0c05dd7e: /* original 67a3, guest PC 0x0c05dd7e */
if(!s->budget--) { s->failed_pc=0x0c05dd7eu; return 0; }
r[7]=r[10];
goto P_0c05dd80;
P_0c05dd80: /* original d233, guest PC 0x0c05dd80 */
if(!s->budget--) { s->failed_pc=0x0c05dd80u; return 0; }
r[2]=read(ram,0x0c05de50u,4);
goto P_0c05dd82;
P_0c05dd82: /* original 6683, guest PC 0x0c05dd82 */
if(!s->budget--) { s->failed_pc=0x0c05dd82u; return 0; }
r[6]=r[8];
goto P_0c05dd84;
P_0c05dd84: /* original 2f96, guest PC 0x0c05dd84 */
if(!s->budget--) { s->failed_pc=0x0c05dd84u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05dd86;
P_0c05dd86: /* original 65d3, guest PC 0x0c05dd86 */
if(!s->budget--) { s->failed_pc=0x0c05dd86u; return 0; }
r[5]=r[13];
goto P_0c05dd88;
P_0c05dd88: /* original 420b, guest PC 0x0c05dd88 */
if(!s->budget--) { s->failed_pc=0x0c05dd88u; return 0; }
target=r[2];
r[16]=code_base|0x0c05dd8cu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dd8cu) { target=s->pc; goto dispatch; }
goto P_0c05dd8c;
P_0c05dd8a: /* original 64b3, guest PC 0x0c05dd8a */
if(!s->budget--) { s->failed_pc=0x0c05dd8au; return 0; }
r[4]=r[11];
goto P_0c05dd8c;
P_0c05dd8c: /* original bed8, guest PC 0x0c05dd8c */
if(!s->budget--) { s->failed_pc=0x0c05dd8cu; return 0; }
target=code_base|0x0c05db40u; r[16]=code_base|0x0c05dd90u;
r[15]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05dd90u) { target=s->pc; goto dispatch; }
goto P_0c05dd90;
P_0c05dd8e: /* original 7f08, guest PC 0x0c05dd8e */
if(!s->budget--) { s->failed_pc=0x0c05dd8eu; return 0; }
r[15]+=0x00000008u;
goto P_0c05dd90;
P_0c05dd90: /* original 60e3, guest PC 0x0c05dd90 */
if(!s->budget--) { s->failed_pc=0x0c05dd90u; return 0; }
r[0]=r[14];
goto P_0c05dd92;
P_0c05dd92: /* original 0009, guest PC 0x0c05dd92 */
if(!s->budget--) { s->failed_pc=0x0c05dd92u; return 0; }
goto P_0c05dd94;
P_0c05dd94: /* original 7f0c, guest PC 0x0c05dd94 */
if(!s->budget--) { s->failed_pc=0x0c05dd94u; return 0; }
r[15]+=0x0000000cu;
goto P_0c05dd96;
P_0c05dd96: /* original 4f26, guest PC 0x0c05dd96 */
if(!s->budget--) { s->failed_pc=0x0c05dd96u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05dd98;
P_0c05dd98: /* original 68f6, guest PC 0x0c05dd98 */
if(!s->budget--) { s->failed_pc=0x0c05dd98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05dd9a;
P_0c05dd9a: /* original 69f6, guest PC 0x0c05dd9a */
if(!s->budget--) { s->failed_pc=0x0c05dd9au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05dd9c;
P_0c05dd9c: /* original 6af6, guest PC 0x0c05dd9c */
if(!s->budget--) { s->failed_pc=0x0c05dd9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05dd9e;
P_0c05dd9e: /* original 6bf6, guest PC 0x0c05dd9e */
if(!s->budget--) { s->failed_pc=0x0c05dd9eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05dda0;
P_0c05dda0: /* original 6cf6, guest PC 0x0c05dda0 */
if(!s->budget--) { s->failed_pc=0x0c05dda0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05dda2;
P_0c05dda2: /* original 6df6, guest PC 0x0c05dda2 */
if(!s->budget--) { s->failed_pc=0x0c05dda2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05dda4;
P_0c05dda4: /* original 000b, guest PC 0x0c05dda4 */
if(!s->budget--) { s->failed_pc=0x0c05dda4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05dda6: /* original 6ef6, guest PC 0x0c05dda6 */
if(!s->budget--) { s->failed_pc=0x0c05dda6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05dda8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05dda8u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
