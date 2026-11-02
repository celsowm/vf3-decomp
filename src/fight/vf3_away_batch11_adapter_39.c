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
int vf3_away_batch11_adapter_39(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07dcf0u: goto P_0c07dcf0;
case 0x0c07dcf2u: goto P_0c07dcf2;
case 0x0c07dcf4u: goto P_0c07dcf4;
case 0x0c07dcf6u: goto P_0c07dcf6;
case 0x0c07dcf8u: goto P_0c07dcf8;
case 0x0c07dcfau: goto P_0c07dcfa;
case 0x0c07dcfcu: goto P_0c07dcfc;
case 0x0c07dcfeu: goto P_0c07dcfe;
case 0x0c07dd00u: goto P_0c07dd00;
case 0x0c07dd02u: goto P_0c07dd02;
case 0x0c07dd04u: goto P_0c07dd04;
case 0x0c07dd06u: goto P_0c07dd06;
case 0x0c07dd08u: goto P_0c07dd08;
case 0x0c07dd0au: goto P_0c07dd0a;
case 0x0c07dd0cu: goto P_0c07dd0c;
case 0x0c07dd0eu: goto P_0c07dd0e;
case 0x0c07dd10u: goto P_0c07dd10;
case 0x0c07dd12u: goto P_0c07dd12;
case 0x0c07dd14u: goto P_0c07dd14;
case 0x0c07dd16u: goto P_0c07dd16;
case 0x0c07dd18u: goto P_0c07dd18;
case 0x0c07dd1au: goto P_0c07dd1a;
case 0x0c07dd1cu: goto P_0c07dd1c;
case 0x0c07dd1eu: goto P_0c07dd1e;
case 0x0c07dd20u: goto P_0c07dd20;
case 0x0c07dd22u: goto P_0c07dd22;
case 0x0c07dd24u: goto P_0c07dd24;
case 0x0c07dd26u: goto P_0c07dd26;
case 0x0c07dd28u: goto P_0c07dd28;
case 0x0c07dd2au: goto P_0c07dd2a;
case 0x0c07dd2cu: goto P_0c07dd2c;
case 0x0c07dd2eu: goto P_0c07dd2e;
case 0x0c07dd30u: goto P_0c07dd30;
case 0x0c07dd32u: goto P_0c07dd32;
case 0x0c07dd34u: goto P_0c07dd34;
case 0x0c07dd36u: goto P_0c07dd36;
case 0x0c07dd38u: goto P_0c07dd38;
case 0x0c07dd3au: goto P_0c07dd3a;
case 0x0c07dd3cu: goto P_0c07dd3c;
case 0x0c07dd3eu: goto P_0c07dd3e;
case 0x0c07dd40u: goto P_0c07dd40;
case 0x0c07dd42u: goto P_0c07dd42;
case 0x0c07dd44u: goto P_0c07dd44;
case 0x0c07dd46u: goto P_0c07dd46;
case 0x0c07dd48u: goto P_0c07dd48;
case 0x0c07dd4au: goto P_0c07dd4a;
case 0x0c07dd4cu: goto P_0c07dd4c;
case 0x0c07dd4eu: goto P_0c07dd4e;
case 0x0c07dd50u: goto P_0c07dd50;
case 0x0c07dd52u: goto P_0c07dd52;
case 0x0c07dd54u: goto P_0c07dd54;
case 0x0c07dd56u: goto P_0c07dd56;
case 0x0c07dd58u: goto P_0c07dd58;
case 0x0c07dd5au: goto P_0c07dd5a;
case 0x0c07dd5cu: goto P_0c07dd5c;
case 0x0c07dd5eu: goto P_0c07dd5e;
case 0x0c07dd60u: goto P_0c07dd60;
case 0x0c07dd62u: goto P_0c07dd62;
case 0x0c07dd64u: goto P_0c07dd64;
case 0x0c07dd66u: goto P_0c07dd66;
case 0x0c07dd68u: goto P_0c07dd68;
case 0x0c07dd6au: goto P_0c07dd6a;
case 0x0c07dd6cu: goto P_0c07dd6c;
case 0x0c07dd6eu: goto P_0c07dd6e;
case 0x0c07dd70u: goto P_0c07dd70;
case 0x0c07dd72u: goto P_0c07dd72;
case 0x0c07dd74u: goto P_0c07dd74;
case 0x0c07dd76u: goto P_0c07dd76;
case 0x0c07dd78u: goto P_0c07dd78;
case 0x0c07dd7au: goto P_0c07dd7a;
case 0x0c07dd7cu: goto P_0c07dd7c;
case 0x0c07dd7eu: goto P_0c07dd7e;
case 0x0c07dd80u: goto P_0c07dd80;
case 0x0c07dd82u: goto P_0c07dd82;
case 0x0c07dd84u: goto P_0c07dd84;
case 0x0c07dd86u: goto P_0c07dd86;
case 0x0c07dd88u: goto P_0c07dd88;
case 0x0c07dd8au: goto P_0c07dd8a;
case 0x0c07dd8cu: goto P_0c07dd8c;
case 0x0c07dd8eu: goto P_0c07dd8e;
case 0x0c07dd90u: goto P_0c07dd90;
case 0x0c07dd92u: goto P_0c07dd92;
case 0x0c07dd94u: goto P_0c07dd94;
case 0x0c07dd96u: goto P_0c07dd96;
case 0x0c07dd98u: goto P_0c07dd98;
case 0x0c07dd9au: goto P_0c07dd9a;
case 0x0c07dd9cu: goto P_0c07dd9c;
case 0x0c07dd9eu: goto P_0c07dd9e;
case 0x0c07dda0u: goto P_0c07dda0;
case 0x0c07dda2u: goto P_0c07dda2;
case 0x0c07dda4u: goto P_0c07dda4;
case 0x0c07dda6u: goto P_0c07dda6;
case 0x0c07dda8u: goto P_0c07dda8;
case 0x0c07ddaau: goto P_0c07ddaa;
case 0x0c07ddacu: goto P_0c07ddac;
case 0x0c07ddaeu: goto P_0c07ddae;
case 0x0c07ddb0u: goto P_0c07ddb0;
case 0x0c07ddb2u: goto P_0c07ddb2;
case 0x0c07ddb4u: goto P_0c07ddb4;
case 0x0c07ddb6u: goto P_0c07ddb6;
case 0x0c07ddb8u: goto P_0c07ddb8;
case 0x0c07ddbau: goto P_0c07ddba;
case 0x0c07ddbcu: goto P_0c07ddbc;
case 0x0c07ddbeu: goto P_0c07ddbe;
case 0x0c07ddc0u: goto P_0c07ddc0;
case 0x0c07ddc2u: goto P_0c07ddc2;
case 0x0c07ddc4u: goto P_0c07ddc4;
case 0x0c07ddc6u: goto P_0c07ddc6;
case 0x0c07ddc8u: goto P_0c07ddc8;
case 0x0c07ddcau: goto P_0c07ddca;
case 0x0c07ddccu: goto P_0c07ddcc;
case 0x0c07ddceu: goto P_0c07ddce;
case 0x0c07ddd0u: goto P_0c07ddd0;
case 0x0c07ddd2u: goto P_0c07ddd2;
case 0x0c07ddd4u: goto P_0c07ddd4;
case 0x0c07ddd6u: goto P_0c07ddd6;
case 0x0c07ddd8u: goto P_0c07ddd8;
case 0x0c07dddau: goto P_0c07ddda;
case 0x0c07dddcu: goto P_0c07dddc;
case 0x0c07dddeu: goto P_0c07ddde;
case 0x0c07dde0u: goto P_0c07dde0;
case 0x0c07dde2u: goto P_0c07dde2;
case 0x0c07dde4u: goto P_0c07dde4;
case 0x0c07dde6u: goto P_0c07dde6;
case 0x0c07dde8u: goto P_0c07dde8;
case 0x0c07ddeau: goto P_0c07ddea;
case 0x0c07ddecu: goto P_0c07ddec;
case 0x0c07ddeeu: goto P_0c07ddee;
case 0x0c07ddf0u: goto P_0c07ddf0;
case 0x0c07ddf2u: goto P_0c07ddf2;
case 0x0c07ddf4u: goto P_0c07ddf4;
case 0x0c07ddf6u: goto P_0c07ddf6;
case 0x0c07de14u: goto P_0c07de14;
case 0x0c07de16u: goto P_0c07de16;
case 0x0c07de18u: goto P_0c07de18;
case 0x0c07de1au: goto P_0c07de1a;
case 0x0c07de1cu: goto P_0c07de1c;
case 0x0c07de1eu: goto P_0c07de1e;
case 0x0c07de20u: goto P_0c07de20;
case 0x0c07de22u: goto P_0c07de22;
case 0x0c07de24u: goto P_0c07de24;
case 0x0c07de26u: goto P_0c07de26;
case 0x0c07de28u: goto P_0c07de28;
case 0x0c07de2au: goto P_0c07de2a;
case 0x0c07de2cu: goto P_0c07de2c;
case 0x0c07de2eu: goto P_0c07de2e;
case 0x0c07de30u: goto P_0c07de30;
case 0x0c07de32u: goto P_0c07de32;
case 0x0c07de34u: goto P_0c07de34;
case 0x0c07de36u: goto P_0c07de36;
case 0x0c07de38u: goto P_0c07de38;
case 0x0c07de3au: goto P_0c07de3a;
case 0x0c07de3cu: goto P_0c07de3c;
case 0x0c07de3eu: goto P_0c07de3e;
case 0x0c07de40u: goto P_0c07de40;
case 0x0c07de42u: goto P_0c07de42;
case 0x0c07de44u: goto P_0c07de44;
case 0x0c07de46u: goto P_0c07de46;
case 0x0c07de48u: goto P_0c07de48;
case 0x0c07de4au: goto P_0c07de4a;
case 0x0c07de4cu: goto P_0c07de4c;
case 0x0c07de4eu: goto P_0c07de4e;
case 0x0c07de50u: goto P_0c07de50;
case 0x0c07de52u: goto P_0c07de52;
case 0x0c07de54u: goto P_0c07de54;
case 0x0c07de56u: goto P_0c07de56;
case 0x0c07de58u: goto P_0c07de58;
case 0x0c07de5au: goto P_0c07de5a;
case 0x0c07de5cu: goto P_0c07de5c;
case 0x0c07de5eu: goto P_0c07de5e;
case 0x0c07de60u: goto P_0c07de60;
case 0x0c07de62u: goto P_0c07de62;
case 0x0c07de64u: goto P_0c07de64;
case 0x0c07de66u: goto P_0c07de66;
case 0x0c07de68u: goto P_0c07de68;
case 0x0c07de6au: goto P_0c07de6a;
case 0x0c07de6cu: goto P_0c07de6c;
case 0x0c07de6eu: goto P_0c07de6e;
case 0x0c07de70u: goto P_0c07de70;
case 0x0c07de72u: goto P_0c07de72;
case 0x0c07de74u: goto P_0c07de74;
case 0x0c07de76u: goto P_0c07de76;
case 0x0c07de78u: goto P_0c07de78;
case 0x0c07de7au: goto P_0c07de7a;
case 0x0c07de7cu: goto P_0c07de7c;
case 0x0c07de7eu: goto P_0c07de7e;
case 0x0c07de80u: goto P_0c07de80;
case 0x0c07de82u: goto P_0c07de82;
case 0x0c07de84u: goto P_0c07de84;
case 0x0c07de86u: goto P_0c07de86;
case 0x0c07de88u: goto P_0c07de88;
case 0x0c07de8au: goto P_0c07de8a;
case 0x0c07de8cu: goto P_0c07de8c;
case 0x0c07de8eu: goto P_0c07de8e;
case 0x0c07de90u: goto P_0c07de90;
case 0x0c07de92u: goto P_0c07de92;
case 0x0c07de94u: goto P_0c07de94;
case 0x0c07de96u: goto P_0c07de96;
case 0x0c07de98u: goto P_0c07de98;
case 0x0c07de9au: goto P_0c07de9a;
case 0x0c07de9cu: goto P_0c07de9c;
case 0x0c07de9eu: goto P_0c07de9e;
case 0x0c07dea0u: goto P_0c07dea0;
case 0x0c07dea2u: goto P_0c07dea2;
case 0x0c07dea4u: goto P_0c07dea4;
case 0x0c07dea6u: goto P_0c07dea6;
case 0x0c07dea8u: goto P_0c07dea8;
case 0x0c07deaau: goto P_0c07deaa;
case 0x0c07deacu: goto P_0c07deac;
case 0x0c07deaeu: goto P_0c07deae;
case 0x0c07deb0u: goto P_0c07deb0;
case 0x0c07deb2u: goto P_0c07deb2;
case 0x0c07deb4u: goto P_0c07deb4;
case 0x0c07deb6u: goto P_0c07deb6;
case 0x0c07deb8u: goto P_0c07deb8;
case 0x0c07debau: goto P_0c07deba;
case 0x0c07debcu: goto P_0c07debc;
case 0x0c07debeu: goto P_0c07debe;
case 0x0c07dec0u: goto P_0c07dec0;
case 0x0c07dec2u: goto P_0c07dec2;
case 0x0c07dec4u: goto P_0c07dec4;
case 0x0c07dec6u: goto P_0c07dec6;
case 0x0c07dec8u: goto P_0c07dec8;
case 0x0c07decau: goto P_0c07deca;
case 0x0c07deccu: goto P_0c07decc;
case 0x0c07deceu: goto P_0c07dece;
case 0x0c07ded0u: goto P_0c07ded0;
case 0x0c07ded2u: goto P_0c07ded2;
case 0x0c07ded4u: goto P_0c07ded4;
case 0x0c07ded6u: goto P_0c07ded6;
case 0x0c07ded8u: goto P_0c07ded8;
case 0x0c07dedau: goto P_0c07deda;
case 0x0c07dedcu: goto P_0c07dedc;
case 0x0c07dedeu: goto P_0c07dede;
case 0x0c07dee0u: goto P_0c07dee0;
case 0x0c07dee2u: goto P_0c07dee2;
case 0x0c07dee4u: goto P_0c07dee4;
case 0x0c07dee6u: goto P_0c07dee6;
case 0x0c07dee8u: goto P_0c07dee8;
case 0x0c07deeau: goto P_0c07deea;
case 0x0c07deecu: goto P_0c07deec;
case 0x0c07deeeu: goto P_0c07deee;
case 0x0c07def0u: goto P_0c07def0;
case 0x0c07def2u: goto P_0c07def2;
case 0x0c07def4u: goto P_0c07def4;
case 0x0c07def6u: goto P_0c07def6;
case 0x0c07def8u: goto P_0c07def8;
case 0x0c07defau: goto P_0c07defa;
case 0x0c07defcu: goto P_0c07defc;
case 0x0c07defeu: goto P_0c07defe;
case 0x0c07df00u: goto P_0c07df00;
case 0x0c07df02u: goto P_0c07df02;
case 0x0c07df04u: goto P_0c07df04;
case 0x0c07df06u: goto P_0c07df06;
case 0x0c07df08u: goto P_0c07df08;
case 0x0c07df0au: goto P_0c07df0a;
case 0x0c07df0cu: goto P_0c07df0c;
case 0x0c07df0eu: goto P_0c07df0e;
case 0x0c07df10u: goto P_0c07df10;
case 0x0c07df12u: goto P_0c07df12;
case 0x0c07df14u: goto P_0c07df14;
case 0x0c07df16u: goto P_0c07df16;
case 0x0c07df18u: goto P_0c07df18;
case 0x0c07df1au: goto P_0c07df1a;
case 0x0c07df1cu: goto P_0c07df1c;
case 0x0c07df1eu: goto P_0c07df1e;
case 0x0c07df20u: goto P_0c07df20;
case 0x0c07df22u: goto P_0c07df22;
case 0x0c07df24u: goto P_0c07df24;
case 0x0c07df26u: goto P_0c07df26;
case 0x0c07df28u: goto P_0c07df28;
case 0x0c07df2au: goto P_0c07df2a;
case 0x0c07df2cu: goto P_0c07df2c;
case 0x0c07df2eu: goto P_0c07df2e;
case 0x0c07df50u: goto P_0c07df50;
case 0x0c07df52u: goto P_0c07df52;
case 0x0c07df54u: goto P_0c07df54;
case 0x0c07df56u: goto P_0c07df56;
case 0x0c07df58u: goto P_0c07df58;
case 0x0c07df5au: goto P_0c07df5a;
case 0x0c07df5cu: goto P_0c07df5c;
case 0x0c07df5eu: goto P_0c07df5e;
case 0x0c07df60u: goto P_0c07df60;
case 0x0c07df62u: goto P_0c07df62;
case 0x0c07df64u: goto P_0c07df64;
case 0x0c07df66u: goto P_0c07df66;
case 0x0c07df68u: goto P_0c07df68;
case 0x0c07df6au: goto P_0c07df6a;
case 0x0c07df6cu: goto P_0c07df6c;
case 0x0c07df6eu: goto P_0c07df6e;
case 0x0c07df70u: goto P_0c07df70;
case 0x0c07df72u: goto P_0c07df72;
case 0x0c07df74u: goto P_0c07df74;
case 0x0c07df76u: goto P_0c07df76;
case 0x0c07df78u: goto P_0c07df78;
case 0x0c07df7au: goto P_0c07df7a;
case 0x0c07df7cu: goto P_0c07df7c;
case 0x0c07df7eu: goto P_0c07df7e;
case 0x0c07df80u: goto P_0c07df80;
case 0x0c07df82u: goto P_0c07df82;
case 0x0c07df84u: goto P_0c07df84;
case 0x0c07df86u: goto P_0c07df86;
case 0x0c07df88u: goto P_0c07df88;
case 0x0c07df8au: goto P_0c07df8a;
case 0x0c07df8cu: goto P_0c07df8c;
case 0x0c07df8eu: goto P_0c07df8e;
case 0x0c07df90u: goto P_0c07df90;
case 0x0c07df92u: goto P_0c07df92;
case 0x0c07df94u: goto P_0c07df94;
case 0x0c07df96u: goto P_0c07df96;
case 0x0c07df98u: goto P_0c07df98;
case 0x0c07df9au: goto P_0c07df9a;
case 0x0c07df9cu: goto P_0c07df9c;
case 0x0c07df9eu: goto P_0c07df9e;
case 0x0c07dfa0u: goto P_0c07dfa0;
case 0x0c07dfa2u: goto P_0c07dfa2;
case 0x0c07dfa4u: goto P_0c07dfa4;
case 0x0c07dfa6u: goto P_0c07dfa6;
case 0x0c07dfa8u: goto P_0c07dfa8;
case 0x0c07dfaau: goto P_0c07dfaa;
case 0x0c07dfacu: goto P_0c07dfac;
case 0x0c07dfaeu: goto P_0c07dfae;
case 0x0c07dfb0u: goto P_0c07dfb0;
case 0x0c07dfb2u: goto P_0c07dfb2;
case 0x0c07dfb4u: goto P_0c07dfb4;
case 0x0c07dfb6u: goto P_0c07dfb6;
case 0x0c07dfb8u: goto P_0c07dfb8;
case 0x0c07dfbau: goto P_0c07dfba;
case 0x0c07dfbcu: goto P_0c07dfbc;
case 0x0c07dfbeu: goto P_0c07dfbe;
case 0x0c07dfc0u: goto P_0c07dfc0;
case 0x0c07dfc2u: goto P_0c07dfc2;
case 0x0c07dfc4u: goto P_0c07dfc4;
case 0x0c07dfc6u: goto P_0c07dfc6;
case 0x0c07dfc8u: goto P_0c07dfc8;
case 0x0c07dfcau: goto P_0c07dfca;
case 0x0c07dfccu: goto P_0c07dfcc;
case 0x0c07dfceu: goto P_0c07dfce;
case 0x0c07dfd0u: goto P_0c07dfd0;
case 0x0c07dfd2u: goto P_0c07dfd2;
case 0x0c07dfd4u: goto P_0c07dfd4;
case 0x0c07dfd6u: goto P_0c07dfd6;
case 0x0c07dfd8u: goto P_0c07dfd8;
case 0x0c07dfdau: goto P_0c07dfda;
case 0x0c07dfdcu: goto P_0c07dfdc;
case 0x0c07dfdeu: goto P_0c07dfde;
case 0x0c07dfe0u: goto P_0c07dfe0;
case 0x0c07dfe2u: goto P_0c07dfe2;
case 0x0c07dfe4u: goto P_0c07dfe4;
case 0x0c07dfe6u: goto P_0c07dfe6;
case 0x0c07dfe8u: goto P_0c07dfe8;
case 0x0c07dfeau: goto P_0c07dfea;
case 0x0c07dfecu: goto P_0c07dfec;
case 0x0c07dfeeu: goto P_0c07dfee;
case 0x0c07dff0u: goto P_0c07dff0;
case 0x0c07dff2u: goto P_0c07dff2;
case 0x0c07dff4u: goto P_0c07dff4;
case 0x0c07dff6u: goto P_0c07dff6;
case 0x0c07dff8u: goto P_0c07dff8;
case 0x0c07dffau: goto P_0c07dffa;
case 0x0c07dffcu: goto P_0c07dffc;
case 0x0c07dffeu: goto P_0c07dffe;
case 0x0c07e000u: goto P_0c07e000;
case 0x0c07e002u: goto P_0c07e002;
case 0x0c07e004u: goto P_0c07e004;
case 0x0c07e006u: goto P_0c07e006;
case 0x0c07e008u: goto P_0c07e008;
case 0x0c07e00au: goto P_0c07e00a;
case 0x0c07e00cu: goto P_0c07e00c;
case 0x0c07e00eu: goto P_0c07e00e;
case 0x0c07e010u: goto P_0c07e010;
case 0x0c07e012u: goto P_0c07e012;
case 0x0c07e014u: goto P_0c07e014;
case 0x0c07e016u: goto P_0c07e016;
case 0x0c07e018u: goto P_0c07e018;
case 0x0c07e01au: goto P_0c07e01a;
case 0x0c07e01cu: goto P_0c07e01c;
case 0x0c07e01eu: goto P_0c07e01e;
case 0x0c07e020u: goto P_0c07e020;
case 0x0c07e022u: goto P_0c07e022;
case 0x0c07e024u: goto P_0c07e024;
case 0x0c07e026u: goto P_0c07e026;
case 0x0c07e028u: goto P_0c07e028;
case 0x0c07e02au: goto P_0c07e02a;
case 0x0c07e02cu: goto P_0c07e02c;
case 0x0c07e02eu: goto P_0c07e02e;
case 0x0c07e030u: goto P_0c07e030;
case 0x0c07e032u: goto P_0c07e032;
case 0x0c07e034u: goto P_0c07e034;
case 0x0c07e036u: goto P_0c07e036;
case 0x0c07e038u: goto P_0c07e038;
case 0x0c07e060u: goto P_0c07e060;
case 0x0c07e062u: goto P_0c07e062;
case 0x0c07e064u: goto P_0c07e064;
case 0x0c07e066u: goto P_0c07e066;
case 0x0c07e068u: goto P_0c07e068;
case 0x0c07e06au: goto P_0c07e06a;
case 0x0c07e06cu: goto P_0c07e06c;
case 0x0c07e06eu: goto P_0c07e06e;
case 0x0c07e070u: goto P_0c07e070;
case 0x0c07e072u: goto P_0c07e072;
case 0x0c07e074u: goto P_0c07e074;
case 0x0c07e076u: goto P_0c07e076;
case 0x0c07e078u: goto P_0c07e078;
case 0x0c07e07au: goto P_0c07e07a;
case 0x0c07e07cu: goto P_0c07e07c;
case 0x0c07e07eu: goto P_0c07e07e;
case 0x0c07e080u: goto P_0c07e080;
case 0x0c07e082u: goto P_0c07e082;
case 0x0c07e084u: goto P_0c07e084;
case 0x0c07e086u: goto P_0c07e086;
case 0x0c07e088u: goto P_0c07e088;
case 0x0c07e08au: goto P_0c07e08a;
case 0x0c07e08cu: goto P_0c07e08c;
case 0x0c07e08eu: goto P_0c07e08e;
case 0x0c07e090u: goto P_0c07e090;
case 0x0c07e092u: goto P_0c07e092;
case 0x0c07e094u: goto P_0c07e094;
case 0x0c07e096u: goto P_0c07e096;
case 0x0c07e098u: goto P_0c07e098;
case 0x0c07e09au: goto P_0c07e09a;
case 0x0c07e09cu: goto P_0c07e09c;
case 0x0c07e09eu: goto P_0c07e09e;
case 0x0c07e0a0u: goto P_0c07e0a0;
case 0x0c07e0a2u: goto P_0c07e0a2;
case 0x0c07e0a4u: goto P_0c07e0a4;
case 0x0c07e0a6u: goto P_0c07e0a6;
case 0x0c07e0a8u: goto P_0c07e0a8;
case 0x0c07e0aau: goto P_0c07e0aa;
case 0x0c07e0acu: goto P_0c07e0ac;
case 0x0c07e0aeu: goto P_0c07e0ae;
case 0x0c07e0b0u: goto P_0c07e0b0;
case 0x0c07e0b2u: goto P_0c07e0b2;
case 0x0c07e0b4u: goto P_0c07e0b4;
case 0x0c07e0b6u: goto P_0c07e0b6;
case 0x0c07e0b8u: goto P_0c07e0b8;
case 0x0c07e0bau: goto P_0c07e0ba;
case 0x0c07e0bcu: goto P_0c07e0bc;
case 0x0c07e0beu: goto P_0c07e0be;
case 0x0c07e0c0u: goto P_0c07e0c0;
case 0x0c07e0c2u: goto P_0c07e0c2;
case 0x0c07e0c4u: goto P_0c07e0c4;
case 0x0c07e0c6u: goto P_0c07e0c6;
case 0x0c07e0c8u: goto P_0c07e0c8;
case 0x0c07e0cau: goto P_0c07e0ca;
case 0x0c07e0ccu: goto P_0c07e0cc;
case 0x0c07e0ceu: goto P_0c07e0ce;
case 0x0c07e0d0u: goto P_0c07e0d0;
case 0x0c07e0d2u: goto P_0c07e0d2;
case 0x0c07e0d4u: goto P_0c07e0d4;
case 0x0c07e0d6u: goto P_0c07e0d6;
case 0x0c07e0d8u: goto P_0c07e0d8;
case 0x0c07e0dau: goto P_0c07e0da;
case 0x0c07e0dcu: goto P_0c07e0dc;
case 0x0c07e0deu: goto P_0c07e0de;
case 0x0c07e0e0u: goto P_0c07e0e0;
case 0x0c07e0e2u: goto P_0c07e0e2;
case 0x0c07e0e4u: goto P_0c07e0e4;
case 0x0c07e0e6u: goto P_0c07e0e6;
case 0x0c07e0e8u: goto P_0c07e0e8;
case 0x0c07e0eau: goto P_0c07e0ea;
case 0x0c07e0ecu: goto P_0c07e0ec;
case 0x0c07e0eeu: goto P_0c07e0ee;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07dcf0: /* original 2fe6, guest PC 0x0c07dcf0 */
if(!s->budget--) { s->failed_pc=0x0c07dcf0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dcf2;
P_0c07dcf2: /* original 6e43, guest PC 0x0c07dcf2 */
if(!s->budget--) { s->failed_pc=0x0c07dcf2u; return 0; }
r[14]=r[4];
goto P_0c07dcf4;
P_0c07dcf4: /* original 2fd6, guest PC 0x0c07dcf4 */
if(!s->budget--) { s->failed_pc=0x0c07dcf4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dcf6;
P_0c07dcf6: /* original e034, guest PC 0x0c07dcf6 */
if(!s->budget--) { s->failed_pc=0x0c07dcf6u; return 0; }
r[0]=0x00000034u;
goto P_0c07dcf8;
P_0c07dcf8: /* original 2fc6, guest PC 0x0c07dcf8 */
if(!s->budget--) { s->failed_pc=0x0c07dcf8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dcfa;
P_0c07dcfa: /* original 2fb6, guest PC 0x0c07dcfa */
if(!s->budget--) { s->failed_pc=0x0c07dcfau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dcfc;
P_0c07dcfc: /* original 2fa6, guest PC 0x0c07dcfc */
if(!s->budget--) { s->failed_pc=0x0c07dcfcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dcfe;
P_0c07dcfe: /* original 6a53, guest PC 0x0c07dcfe */
if(!s->budget--) { s->failed_pc=0x0c07dcfeu; return 0; }
r[10]=r[5];
goto P_0c07dd00;
P_0c07dd00: /* original 2f96, guest PC 0x0c07dd00 */
if(!s->budget--) { s->failed_pc=0x0c07dd00u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dd02;
P_0c07dd02: /* original 2f86, guest PC 0x0c07dd02 */
if(!s->budget--) { s->failed_pc=0x0c07dd02u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dd04;
P_0c07dd04: /* original 4f22, guest PC 0x0c07dd04 */
if(!s->budget--) { s->failed_pc=0x0c07dd04u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07dd06;
P_0c07dd06: /* original 4f12, guest PC 0x0c07dd06 */
if(!s->budget--) { s->failed_pc=0x0c07dd06u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07dd08;
P_0c07dd08: /* original 7fe4, guest PC 0x0c07dd08 */
if(!s->budget--) { s->failed_pc=0x0c07dd08u; return 0; }
r[15]+=0xffffffe4u;
goto P_0c07dd0a;
P_0c07dd0a: /* original 1f44, guest PC 0x0c07dd0a */
if(!s->budget--) { s->failed_pc=0x0c07dd0au; return 0; }
write(ram,r[15]+16,r[4],4);
goto P_0c07dd0c;
P_0c07dd0c: /* original 03ed, guest PC 0x0c07dd0c */
if(!s->budget--) { s->failed_pc=0x0c07dd0cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07dd0e;
P_0c07dd0e: /* original e036, guest PC 0x0c07dd0e */
if(!s->budget--) { s->failed_pc=0x0c07dd0eu; return 0; }
r[0]=0x00000036u;
goto P_0c07dd10;
P_0c07dd10: /* original 57e9, guest PC 0x0c07dd10 */
if(!s->budget--) { s->failed_pc=0x0c07dd10u; return 0; }
r[7]=read(ram,r[14]+36,4);
goto P_0c07dd12;
P_0c07dd12: /* original 633d, guest PC 0x0c07dd12 */
if(!s->budget--) { s->failed_pc=0x0c07dd12u; return 0; }
r[3]=r[3]&65535u;
goto P_0c07dd14;
P_0c07dd14: /* original dd3b, guest PC 0x0c07dd14 */
if(!s->budget--) { s->failed_pc=0x0c07dd14u; return 0; }
r[13]=read(ram,0x0c07de04u,4);
goto P_0c07dd16;
P_0c07dd16: /* original 1f31, guest PC 0x0c07dd16 */
if(!s->budget--) { s->failed_pc=0x0c07dd16u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07dd18;
P_0c07dd18: /* original 63e3, guest PC 0x0c07dd18 */
if(!s->budget--) { s->failed_pc=0x0c07dd18u; return 0; }
r[3]=r[14];
goto P_0c07dd1a;
P_0c07dd1a: /* original 02ed, guest PC 0x0c07dd1a */
if(!s->budget--) { s->failed_pc=0x0c07dd1au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07dd1c;
P_0c07dd1c: /* original 7328, guest PC 0x0c07dd1c */
if(!s->budget--) { s->failed_pc=0x0c07dd1cu; return 0; }
r[3]+=0x00000028u;
goto P_0c07dd1e;
P_0c07dd1e: /* original 622d, guest PC 0x0c07dd1e */
if(!s->budget--) { s->failed_pc=0x0c07dd1eu; return 0; }
r[2]=r[2]&65535u;
goto P_0c07dd20;
P_0c07dd20: /* original 1f26, guest PC 0x0c07dd20 */
if(!s->budget--) { s->failed_pc=0x0c07dd20u; return 0; }
write(ram,r[15]+24,r[2],4);
goto P_0c07dd22;
P_0c07dd22: /* original 6231, guest PC 0x0c07dd22 */
if(!s->budget--) { s->failed_pc=0x0c07dd22u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c07dd24;
P_0c07dd24: /* original 622d, guest PC 0x0c07dd24 */
if(!s->budget--) { s->failed_pc=0x0c07dd24u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07dd26;
P_0c07dd26: /* original 1f22, guest PC 0x0c07dd26 */
if(!s->budget--) { s->failed_pc=0x0c07dd26u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c07dd28;
P_0c07dd28: /* original 9066, guest PC 0x0c07dd28 */
if(!s->budget--) { s->failed_pc=0x0c07dd28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddf8u,2);
goto P_0c07dd2a;
P_0c07dd2a: /* original d637, guest PC 0x0c07dd2a */
if(!s->budget--) { s->failed_pc=0x0c07dd2au; return 0; }
r[6]=read(ram,0x0c07de08u,4);
goto P_0c07dd2c;
P_0c07dd2c: /* original 04ee, guest PC 0x0c07dd2c */
if(!s->budget--) { s->failed_pc=0x0c07dd2cu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c07dd2e;
P_0c07dd2e: /* original 2448, guest PC 0x0c07dd2e */
if(!s->budget--) { s->failed_pc=0x0c07dd2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07dd30;
P_0c07dd30: /* original 8d0e, guest PC 0x0c07dd30 */
if(!s->budget--) { s->failed_pc=0x0c07dd30u; return 0; }
cond=r[17]&1u;
r[9]=r[13];
if(cond) { goto P_0c07dd50; }
goto P_0c07dd34;
P_0c07dd32: /* original 69d3, guest PC 0x0c07dd32 */
if(!s->budget--) { s->failed_pc=0x0c07dd32u; return 0; }
r[9]=r[13];
goto P_0c07dd34;
P_0c07dd34: /* original 6043, guest PC 0x0c07dd34 */
if(!s->budget--) { s->failed_pc=0x0c07dd34u; return 0; }
r[0]=r[4];
goto P_0c07dd36;
P_0c07dd36: /* original 88e0, guest PC 0x0c07dd36 */
if(!s->budget--) { s->failed_pc=0x0c07dd36u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffe0u)!=0);
goto P_0c07dd38;
P_0c07dd38: /* original 890a, guest PC 0x0c07dd38 */
if(!s->budget--) { s->failed_pc=0x0c07dd38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dd50; }
goto P_0c07dd3a;
P_0c07dd3a: /* original 935e, guest PC 0x0c07dd3a */
if(!s->budget--) { s->failed_pc=0x0c07dd3au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddfau,2);
goto P_0c07dd3c;
P_0c07dd3c: /* original 6543, guest PC 0x0c07dd3c */
if(!s->budget--) { s->failed_pc=0x0c07dd3cu; return 0; }
r[5]=r[4];
goto P_0c07dd3e;
P_0c07dd3e: /* original 4508, guest PC 0x0c07dd3e */
if(!s->budget--) { s->failed_pc=0x0c07dd3eu; return 0; }
r[5]<<=2;
goto P_0c07dd40;
P_0c07dd40: /* original 905a, guest PC 0x0c07dd40 */
if(!s->budget--) { s->failed_pc=0x0c07dd40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddf8u,2);
goto P_0c07dd42;
P_0c07dd42: /* original 2539, guest PC 0x0c07dd42 */
if(!s->budget--) { s->failed_pc=0x0c07dd42u; return 0; }
r[5]&=r[3];
goto P_0c07dd44;
P_0c07dd44: /* original 0567, guest PC 0x0c07dd44 */
if(!s->budget--) { s->failed_pc=0x0c07dd44u; return 0; }
r[19]=r[5]*r[6];
goto P_0c07dd46;
P_0c07dd46: /* original 74ff, guest PC 0x0c07dd46 */
if(!s->budget--) { s->failed_pc=0x0c07dd46u; return 0; }
r[4]+=0xffffffffu;
goto P_0c07dd48;
P_0c07dd48: /* original 0e46, guest PC 0x0c07dd48 */
if(!s->budget--) { s->failed_pc=0x0c07dd48u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c07dd4a;
P_0c07dd4a: /* original 9057, guest PC 0x0c07dd4a */
if(!s->budget--) { s->failed_pc=0x0c07dd4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddfcu,2);
goto P_0c07dd4c;
P_0c07dd4c: /* original 051a, guest PC 0x0c07dd4c */
if(!s->budget--) { s->failed_pc=0x0c07dd4cu; return 0; }
r[5]=r[19];
goto P_0c07dd4e;
P_0c07dd4e: /* original 0d56, guest PC 0x0c07dd4e */
if(!s->budget--) { s->failed_pc=0x0c07dd4eu; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c07dd50;
P_0c07dd50: /* original 9055, guest PC 0x0c07dd50 */
if(!s->budget--) { s->failed_pc=0x0c07dd50u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddfeu,2);
goto P_0c07dd52;
P_0c07dd52: /* original e801, guest PC 0x0c07dd52 */
if(!s->budget--) { s->failed_pc=0x0c07dd52u; return 0; }
r[8]=0x00000001u;
goto P_0c07dd54;
P_0c07dd54: /* original 04ee, guest PC 0x0c07dd54 */
if(!s->budget--) { s->failed_pc=0x0c07dd54u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c07dd56;
P_0c07dd56: /* original e032, guest PC 0x0c07dd56 */
if(!s->budget--) { s->failed_pc=0x0c07dd56u; return 0; }
r[0]=0x00000032u;
goto P_0c07dd58;
P_0c07dd58: /* original 03ec, guest PC 0x0c07dd58 */
if(!s->budget--) { s->failed_pc=0x0c07dd58u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07dd5a;
P_0c07dd5a: /* original e033, guest PC 0x0c07dd5a */
if(!s->budget--) { s->failed_pc=0x0c07dd5au; return 0; }
r[0]=0x00000033u;
goto P_0c07dd5c;
P_0c07dd5c: /* original 633c, guest PC 0x0c07dd5c */
if(!s->budget--) { s->failed_pc=0x0c07dd5cu; return 0; }
r[3]=r[3]&255u;
goto P_0c07dd5e;
P_0c07dd5e: /* original 2338, guest PC 0x0c07dd5e */
if(!s->budget--) { s->failed_pc=0x0c07dd5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07dd60;
P_0c07dd60: /* original 2f32, guest PC 0x0c07dd60 */
if(!s->budget--) { s->failed_pc=0x0c07dd60u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07dd62;
P_0c07dd62: /* original 0bec, guest PC 0x0c07dd62 */
if(!s->budget--) { s->failed_pc=0x0c07dd62u; return 0; }
r[11]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c07dd64;
P_0c07dd64: /* original 6bbc, guest PC 0x0c07dd64 */
if(!s->budget--) { s->failed_pc=0x0c07dd64u; return 0; }
r[11]=r[11]&255u;
goto P_0c07dd66;
P_0c07dd66: /* original 8d55, guest PC 0x0c07dd66 */
if(!s->budget--) { s->failed_pc=0x0c07dd66u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c07de14; }
goto P_0c07dd6a;
P_0c07dd68: /* original ec00, guest PC 0x0c07dd68 */
if(!s->budget--) { s->failed_pc=0x0c07dd68u; return 0; }
r[12]=0x00000000u;
goto P_0c07dd6a;
P_0c07dd6a: /* original 64b3, guest PC 0x0c07dd6a */
if(!s->budget--) { s->failed_pc=0x0c07dd6au; return 0; }
r[4]=r[11];
goto P_0c07dd6c;
P_0c07dd6c: /* original 9345, guest PC 0x0c07dd6c */
if(!s->budget--) { s->failed_pc=0x0c07dd6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddfau,2);
goto P_0c07dd6e;
P_0c07dd6e: /* original 74f8, guest PC 0x0c07dd6e */
if(!s->budget--) { s->failed_pc=0x0c07dd6eu; return 0; }
r[4]+=0xfffffff8u;
goto P_0c07dd70;
P_0c07dd70: /* original 9046, guest PC 0x0c07dd70 */
if(!s->budget--) { s->failed_pc=0x0c07dd70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07de00u,2);
goto P_0c07dd72;
P_0c07dd72: /* original 4408, guest PC 0x0c07dd72 */
if(!s->budget--) { s->failed_pc=0x0c07dd72u; return 0; }
r[4]<<=2;
goto P_0c07dd74;
P_0c07dd74: /* original 2439, guest PC 0x0c07dd74 */
if(!s->budget--) { s->failed_pc=0x0c07dd74u; return 0; }
r[4]&=r[3];
goto P_0c07dd76;
P_0c07dd76: /* original 0467, guest PC 0x0c07dd76 */
if(!s->budget--) { s->failed_pc=0x0c07dd76u; return 0; }
r[19]=r[4]*r[6];
goto P_0c07dd78;
P_0c07dd78: /* original 041a, guest PC 0x0c07dd78 */
if(!s->budget--) { s->failed_pc=0x0c07dd78u; return 0; }
r[4]=r[19];
goto P_0c07dd7a;
P_0c07dd7a: /* original 0d46, guest PC 0x0c07dd7a */
if(!s->budget--) { s->failed_pc=0x0c07dd7au; return 0; }
write(ram,r[13]+r[0],r[4],4);
goto P_0c07dd7c;
P_0c07dd7c: /* original 64b3, guest PC 0x0c07dd7c */
if(!s->budget--) { s->failed_pc=0x0c07dd7cu; return 0; }
r[4]=r[11];
goto P_0c07dd7e;
P_0c07dd7e: /* original 7403, guest PC 0x0c07dd7e */
if(!s->budget--) { s->failed_pc=0x0c07dd7eu; return 0; }
r[4]+=0x00000003u;
goto P_0c07dd80;
P_0c07dd80: /* original 0447, guest PC 0x0c07dd80 */
if(!s->budget--) { s->failed_pc=0x0c07dd80u; return 0; }
r[19]=r[4]*r[4];
goto P_0c07dd82;
P_0c07dd82: /* original 041a, guest PC 0x0c07dd82 */
if(!s->budget--) { s->failed_pc=0x0c07dd82u; return 0; }
r[4]=r[19];
goto P_0c07dd84;
P_0c07dd84: /* original 4421, guest PC 0x0c07dd84 */
if(!s->budget--) { s->failed_pc=0x0c07dd84u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c07dd86;
P_0c07dd86: /* original 4421, guest PC 0x0c07dd86 */
if(!s->budget--) { s->failed_pc=0x0c07dd86u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c07dd88;
P_0c07dd88: /* original 2788, guest PC 0x0c07dd88 */
if(!s->budget--) { s->failed_pc=0x0c07dd88u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[8])==0)!=0);
goto P_0c07dd8a;
P_0c07dd8a: /* original 8b00, guest PC 0x0c07dd8a */
if(!s->budget--) { s->failed_pc=0x0c07dd8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dd8e; }
goto P_0c07dd8c;
P_0c07dd8c: /* original 644b, guest PC 0x0c07dd8c */
if(!s->budget--) { s->failed_pc=0x0c07dd8cu; return 0; }
r[4]=0u-r[4];
goto P_0c07dd8e;
P_0c07dd8e: /* original 69f2, guest PC 0x0c07dd8e */
if(!s->budget--) { s->failed_pc=0x0c07dd8eu; return 0; }
tmp=read(ram,r[15],4);
r[9]=tmp;
goto P_0c07dd90;
P_0c07dd90: /* original 63e3, guest PC 0x0c07dd90 */
if(!s->budget--) { s->failed_pc=0x0c07dd90u; return 0; }
r[3]=r[14];
goto P_0c07dd92;
P_0c07dd92: /* original 7328, guest PC 0x0c07dd92 */
if(!s->budget--) { s->failed_pc=0x0c07dd92u; return 0; }
r[3]+=0x00000028u;
goto P_0c07dd94;
P_0c07dd94: /* original 4900, guest PC 0x0c07dd94 */
if(!s->budget--) { s->failed_pc=0x0c07dd94u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>>31)!=0);
r[9]<<=1;
goto P_0c07dd96;
P_0c07dd96: /* original 393c, guest PC 0x0c07dd96 */
if(!s->budget--) { s->failed_pc=0x0c07dd96u; return 0; }
r[9]+=r[3];
goto P_0c07dd98;
P_0c07dd98: /* original 6991, guest PC 0x0c07dd98 */
if(!s->budget--) { s->failed_pc=0x0c07dd98u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[9],2);
r[9]=tmp;
goto P_0c07dd9a;
P_0c07dd9a: /* original 7bff, guest PC 0x0c07dd9a */
if(!s->budget--) { s->failed_pc=0x0c07dd9au; return 0; }
r[11]+=0xffffffffu;
goto P_0c07dd9c;
P_0c07dd9c: /* original 2bb8, guest PC 0x0c07dd9c */
if(!s->budget--) { s->failed_pc=0x0c07dd9cu; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c07dd9e;
P_0c07dd9e: /* original 674d, guest PC 0x0c07dd9e */
if(!s->budget--) { s->failed_pc=0x0c07dd9eu; return 0; }
r[7]=r[4]&65535u;
goto P_0c07dda0;
P_0c07dda0: /* original 699d, guest PC 0x0c07dda0 */
if(!s->budget--) { s->failed_pc=0x0c07dda0u; return 0; }
r[9]=r[9]&65535u;
goto P_0c07dda2;
P_0c07dda2: /* original 8f1b, guest PC 0x0c07dda2 */
if(!s->budget--) { s->failed_pc=0x0c07dda2u; return 0; }
cond=r[17]&1u;
r[10]=r[12];
if(!cond) { goto P_0c07dddc; }
goto P_0c07dda6;
P_0c07dda4: /* original 6ac3, guest PC 0x0c07dda4 */
if(!s->budget--) { s->failed_pc=0x0c07dda4u; return 0; }
r[10]=r[12];
goto P_0c07dda6;
P_0c07dda6: /* original e2f8, guest PC 0x0c07dda6 */
if(!s->budget--) { s->failed_pc=0x0c07dda6u; return 0; }
r[2]=0xfffffff8u;
goto P_0c07dda8;
P_0c07dda8: /* original 63f2, guest PC 0x0c07dda8 */
if(!s->budget--) { s->failed_pc=0x0c07dda8u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07ddaa;
P_0c07ddaa: /* original 66d3, guest PC 0x0c07ddaa */
if(!s->budget--) { s->failed_pc=0x0c07ddaau; return 0; }
r[6]=r[13];
goto P_0c07ddac;
P_0c07ddac: /* original 6593, guest PC 0x0c07ddac */
if(!s->budget--) { s->failed_pc=0x0c07ddacu; return 0; }
r[5]=r[9];
goto P_0c07ddae;
P_0c07ddae: /* original 73ff, guest PC 0x0c07ddae */
if(!s->budget--) { s->failed_pc=0x0c07ddaeu; return 0; }
r[3]+=0xffffffffu;
goto P_0c07ddb0;
P_0c07ddb0: /* original 2f32, guest PC 0x0c07ddb0 */
if(!s->budget--) { s->failed_pc=0x0c07ddb0u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07ddb2;
P_0c07ddb2: /* original eb0a, guest PC 0x0c07ddb2 */
if(!s->budget--) { s->failed_pc=0x0c07ddb2u; return 0; }
r[11]=0x0000000au;
goto P_0c07ddb4;
P_0c07ddb4: /* original 9020, guest PC 0x0c07ddb4 */
if(!s->budget--) { s->failed_pc=0x0c07ddb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ddf8u,2);
goto P_0c07ddb6;
P_0c07ddb6: /* original 7658, guest PC 0x0c07ddb6 */
if(!s->budget--) { s->failed_pc=0x0c07ddb6u; return 0; }
r[6]+=0x00000058u;
goto P_0c07ddb8;
P_0c07ddb8: /* original 0e26, guest PC 0x0c07ddb8 */
if(!s->budget--) { s->failed_pc=0x0c07ddb8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c07ddba;
P_0c07ddba: /* original 9021, guest PC 0x0c07ddba */
if(!s->budget--) { s->failed_pc=0x0c07ddbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07de00u,2);
goto P_0c07ddbc;
P_0c07ddbc: /* original 03de, guest PC 0x0c07ddbc */
if(!s->budget--) { s->failed_pc=0x0c07ddbcu; return 0; }
r[3]=read(ram,r[13]+r[0],4);
goto P_0c07ddbe;
P_0c07ddbe: /* original 7004, guest PC 0x0c07ddbe */
if(!s->budget--) { s->failed_pc=0x0c07ddbeu; return 0; }
r[0]+=0x00000004u;
goto P_0c07ddc0;
P_0c07ddc0: /* original 0d36, guest PC 0x0c07ddc0 */
if(!s->budget--) { s->failed_pc=0x0c07ddc0u; return 0; }
write(ram,r[13]+r[0],r[3],4);
goto P_0c07ddc2;
P_0c07ddc2: /* original 70fc, guest PC 0x0c07ddc2 */
if(!s->budget--) { s->failed_pc=0x0c07ddc2u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c07ddc4;
P_0c07ddc4: /* original 0dc6, guest PC 0x0c07ddc4 */
if(!s->budget--) { s->failed_pc=0x0c07ddc4u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c07ddc6;
P_0c07ddc6: /* original 2f86, guest PC 0x0c07ddc6 */
if(!s->budget--) { s->failed_pc=0x0c07ddc6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ddc8;
P_0c07ddc8: /* original 2fc6, guest PC 0x0c07ddc8 */
if(!s->budget--) { s->failed_pc=0x0c07ddc8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ddca;
P_0c07ddca: /* original d310, guest PC 0x0c07ddca */
if(!s->budget--) { s->failed_pc=0x0c07ddcau; return 0; }
r[3]=read(ram,0x0c07de0cu,4);
goto P_0c07ddcc;
P_0c07ddcc: /* original 430b, guest PC 0x0c07ddcc */
if(!s->budget--) { s->failed_pc=0x0c07ddccu; return 0; }
target=r[3];
r[16]=code_base|0x0c07ddd0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ddd0u) { target=s->pc; goto dispatch; }
goto P_0c07ddd0;
P_0c07ddce: /* original e400, guest PC 0x0c07ddce */
if(!s->budget--) { s->failed_pc=0x0c07ddceu; return 0; }
r[4]=0x00000000u;
goto P_0c07ddd0;
P_0c07ddd0: /* original d20f, guest PC 0x0c07ddd0 */
if(!s->budget--) { s->failed_pc=0x0c07ddd0u; return 0; }
r[2]=read(ram,0x0c07de10u,4);
goto P_0c07ddd2;
P_0c07ddd2: /* original 7f08, guest PC 0x0c07ddd2 */
if(!s->budget--) { s->failed_pc=0x0c07ddd2u; return 0; }
r[15]+=0x00000008u;
goto P_0c07ddd4;
P_0c07ddd4: /* original 420b, guest PC 0x0c07ddd4 */
if(!s->budget--) { s->failed_pc=0x0c07ddd4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ddd8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ddd8u) { target=s->pc; goto dispatch; }
goto P_0c07ddd8;
P_0c07ddd6: /* original 64d3, guest PC 0x0c07ddd6 */
if(!s->budget--) { s->failed_pc=0x0c07ddd6u; return 0; }
r[4]=r[13];
goto P_0c07ddd8;
P_0c07ddd8: /* original a008, guest PC 0x0c07ddd8 */
if(!s->budget--) { s->failed_pc=0x0c07ddd8u; return 0; }
goto P_0c07ddec;
P_0c07ddda: /* original 0009, guest PC 0x0c07ddda */
if(!s->budget--) { s->failed_pc=0x0c07dddau; return 0; }
goto P_0c07dddc;
P_0c07dddc: /* original 2f86, guest PC 0x0c07dddc */
if(!s->budget--) { s->failed_pc=0x0c07dddcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ddde;
P_0c07ddde: /* original 6593, guest PC 0x0c07ddde */
if(!s->budget--) { s->failed_pc=0x0c07dddeu; return 0; }
r[5]=r[9];
goto P_0c07dde0;
P_0c07dde0: /* original 66d3, guest PC 0x0c07dde0 */
if(!s->budget--) { s->failed_pc=0x0c07dde0u; return 0; }
r[6]=r[13];
goto P_0c07dde2;
P_0c07dde2: /* original 2fc6, guest PC 0x0c07dde2 */
if(!s->budget--) { s->failed_pc=0x0c07dde2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dde4;
P_0c07dde4: /* original d209, guest PC 0x0c07dde4 */
if(!s->budget--) { s->failed_pc=0x0c07dde4u; return 0; }
r[2]=read(ram,0x0c07de0cu,4);
goto P_0c07dde6;
P_0c07dde6: /* original 420b, guest PC 0x0c07dde6 */
if(!s->budget--) { s->failed_pc=0x0c07dde6u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ddeau;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ddeau) { target=s->pc; goto dispatch; }
goto P_0c07ddea;
P_0c07dde8: /* original e400, guest PC 0x0c07dde8 */
if(!s->budget--) { s->failed_pc=0x0c07dde8u; return 0; }
r[4]=0x00000000u;
goto P_0c07ddea;
P_0c07ddea: /* original 7f08, guest PC 0x0c07ddea */
if(!s->budget--) { s->failed_pc=0x0c07ddeau; return 0; }
r[15]+=0x00000008u;
goto P_0c07ddec;
P_0c07ddec: /* original e033, guest PC 0x0c07ddec */
if(!s->budget--) { s->failed_pc=0x0c07ddecu; return 0; }
r[0]=0x00000033u;
goto P_0c07ddee;
P_0c07ddee: /* original 0eb4, guest PC 0x0c07ddee */
if(!s->budget--) { s->failed_pc=0x0c07ddeeu; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c07ddf0;
P_0c07ddf0: /* original e032, guest PC 0x0c07ddf0 */
if(!s->budget--) { s->failed_pc=0x0c07ddf0u; return 0; }
r[0]=0x00000032u;
goto P_0c07ddf2;
P_0c07ddf2: /* original 63f2, guest PC 0x0c07ddf2 */
if(!s->budget--) { s->failed_pc=0x0c07ddf2u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07ddf4;
P_0c07ddf4: /* original a0fb, guest PC 0x0c07ddf4 */
if(!s->budget--) { s->failed_pc=0x0c07ddf4u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c07dfee;
P_0c07ddf6: /* original 0e34, guest PC 0x0c07ddf6 */
if(!s->budget--) { s->failed_pc=0x0c07ddf6u; return 0; }
write(ram,r[14]+r[0],r[3],1);
if(!vf3_matrix_family(0x0c07ddf8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ddf8u; return 0; } return 1;
P_0c07de14: /* original 2448, guest PC 0x0c07de14 */
if(!s->budget--) { s->failed_pc=0x0c07de14u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07de16;
P_0c07de16: /* original 8925, guest PC 0x0c07de16 */
if(!s->budget--) { s->failed_pc=0x0c07de16u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07de64; }
goto P_0c07de18;
P_0c07de18: /* original 6043, guest PC 0x0c07de18 */
if(!s->budget--) { s->failed_pc=0x0c07de18u; return 0; }
r[0]=r[4];
goto P_0c07de1a;
P_0c07de1a: /* original 8801, guest PC 0x0c07de1a */
if(!s->budget--) { s->failed_pc=0x0c07de1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07de1c;
P_0c07de1c: /* original 8b1d, guest PC 0x0c07de1c */
if(!s->budget--) { s->failed_pc=0x0c07de1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07de5a; }
goto P_0c07de1e;
P_0c07de1e: /* original d247, guest PC 0x0c07de1e */
if(!s->budget--) { s->failed_pc=0x0c07de1eu; return 0; }
r[2]=read(ram,0x0c07df3cu,4);
goto P_0c07de20;
P_0c07de20: /* original 420b, guest PC 0x0c07de20 */
if(!s->budget--) { s->failed_pc=0x0c07de20u; return 0; }
target=r[2];
r[16]=code_base|0x0c07de24u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07de24u) { target=s->pc; goto dispatch; }
goto P_0c07de24;
P_0c07de22: /* original 64d3, guest PC 0x0c07de22 */
if(!s->budget--) { s->failed_pc=0x0c07de22u; return 0; }
r[4]=r[13];
goto P_0c07de24;
P_0c07de24: /* original d345, guest PC 0x0c07de24 */
if(!s->budget--) { s->failed_pc=0x0c07de24u; return 0; }
r[3]=read(ram,0x0c07df3cu,4);
goto P_0c07de26;
P_0c07de26: /* original 6bd3, guest PC 0x0c07de26 */
if(!s->budget--) { s->failed_pc=0x0c07de26u; return 0; }
r[11]=r[13];
goto P_0c07de28;
P_0c07de28: /* original 7b58, guest PC 0x0c07de28 */
if(!s->budget--) { s->failed_pc=0x0c07de28u; return 0; }
r[11]+=0x00000058u;
goto P_0c07de2a;
P_0c07de2a: /* original 430b, guest PC 0x0c07de2a */
if(!s->budget--) { s->failed_pc=0x0c07de2au; return 0; }
target=r[3];
r[16]=code_base|0x0c07de2eu;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07de2eu) { target=s->pc; goto dispatch; }
goto P_0c07de2e;
P_0c07de2c: /* original 64b3, guest PC 0x0c07de2c */
if(!s->budget--) { s->failed_pc=0x0c07de2cu; return 0; }
r[4]=r[11];
goto P_0c07de2e;
P_0c07de2e: /* original 947f, guest PC 0x0c07de2e */
if(!s->budget--) { s->failed_pc=0x0c07de2eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07df30u,2);
goto P_0c07de30;
P_0c07de30: /* original 66d3, guest PC 0x0c07de30 */
if(!s->budget--) { s->failed_pc=0x0c07de30u; return 0; }
r[6]=r[13];
goto P_0c07de32;
P_0c07de32: /* original d243, guest PC 0x0c07de32 */
if(!s->budget--) { s->failed_pc=0x0c07de32u; return 0; }
r[2]=read(ram,0x0c07df40u,4);
goto P_0c07de34;
P_0c07de34: /* original 7658, guest PC 0x0c07de34 */
if(!s->budget--) { s->failed_pc=0x0c07de34u; return 0; }
r[6]+=0x00000058u;
goto P_0c07de36;
P_0c07de36: /* original 420b, guest PC 0x0c07de36 */
if(!s->budget--) { s->failed_pc=0x0c07de36u; return 0; }
target=r[2];
r[16]=code_base|0x0c07de3au;
r[5]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07de3au) { target=s->pc; goto dispatch; }
goto P_0c07de3a;
P_0c07de38: /* original 65d3, guest PC 0x0c07de38 */
if(!s->budget--) { s->failed_pc=0x0c07de38u; return 0; }
r[5]=r[13];
goto P_0c07de3a;
P_0c07de3a: /* original 907a, guest PC 0x0c07de3a */
if(!s->budget--) { s->failed_pc=0x0c07de3au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07df32u,2);
goto P_0c07de3c;
P_0c07de3c: /* original 66b3, guest PC 0x0c07de3c */
if(!s->budget--) { s->failed_pc=0x0c07de3cu; return 0; }
r[6]=r[11];
goto P_0c07de3e;
P_0c07de3e: /* original 6ac3, guest PC 0x0c07de3e */
if(!s->budget--) { s->failed_pc=0x0c07de3eu; return 0; }
r[10]=r[12];
goto P_0c07de40;
P_0c07de40: /* original e700, guest PC 0x0c07de40 */
if(!s->budget--) { s->failed_pc=0x0c07de40u; return 0; }
r[7]=0x00000000u;
goto P_0c07de42;
P_0c07de42: /* original 0dc6, guest PC 0x0c07de42 */
if(!s->budget--) { s->failed_pc=0x0c07de42u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c07de44;
P_0c07de44: /* original 7004, guest PC 0x0c07de44 */
if(!s->budget--) { s->failed_pc=0x0c07de44u; return 0; }
r[0]+=0x00000004u;
goto P_0c07de46;
P_0c07de46: /* original 0dc6, guest PC 0x0c07de46 */
if(!s->budget--) { s->failed_pc=0x0c07de46u; return 0; }
write(ram,r[13]+r[0],r[12],4);
goto P_0c07de48;
P_0c07de48: /* original 9074, guest PC 0x0c07de48 */
if(!s->budget--) { s->failed_pc=0x0c07de48u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07df34u,2);
goto P_0c07de4a;
P_0c07de4a: /* original 0ec6, guest PC 0x0c07de4a */
if(!s->budget--) { s->failed_pc=0x0c07de4au; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c07de4c;
P_0c07de4c: /* original 2f86, guest PC 0x0c07de4c */
if(!s->budget--) { s->failed_pc=0x0c07de4cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07de4e;
P_0c07de4e: /* original 55f3, guest PC 0x0c07de4e */
if(!s->budget--) { s->failed_pc=0x0c07de4eu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07de50;
P_0c07de50: /* original d33c, guest PC 0x0c07de50 */
if(!s->budget--) { s->failed_pc=0x0c07de50u; return 0; }
r[3]=read(ram,0x0c07df44u,4);
goto P_0c07de52;
P_0c07de52: /* original 430b, guest PC 0x0c07de52 */
if(!s->budget--) { s->failed_pc=0x0c07de52u; return 0; }
target=r[3];
r[16]=code_base|0x0c07de56u;
r[4]=r[7];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07de56u) { target=s->pc; goto dispatch; }
goto P_0c07de56;
P_0c07de54: /* original 6473, guest PC 0x0c07de54 */
if(!s->budget--) { s->failed_pc=0x0c07de54u; return 0; }
r[4]=r[7];
goto P_0c07de56;
P_0c07de56: /* original a0c9, guest PC 0x0c07de56 */
if(!s->budget--) { s->failed_pc=0x0c07de56u; return 0; }
goto P_0c07dfec;
P_0c07de58: /* original 0009, guest PC 0x0c07de58 */
if(!s->budget--) { s->failed_pc=0x0c07de58u; return 0; }
goto P_0c07de5a;
P_0c07de5a: /* original 65a3, guest PC 0x0c07de5a */
if(!s->budget--) { s->failed_pc=0x0c07de5au; return 0; }
r[5]=r[10];
goto P_0c07de5c;
P_0c07de5c: /* original b148, guest PC 0x0c07de5c */
if(!s->budget--) { s->failed_pc=0x0c07de5cu; return 0; }
target=code_base|0x0c07e0f0u; r[16]=code_base|0x0c07de60u;
r[4]=read(ram,r[15]+16,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07de60u) { target=s->pc; goto dispatch; }
goto P_0c07de60;
P_0c07de5e: /* original 54f4, guest PC 0x0c07de5e */
if(!s->budget--) { s->failed_pc=0x0c07de5eu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07de60;
P_0c07de60: /* original a0c5, guest PC 0x0c07de60 */
if(!s->budget--) { s->failed_pc=0x0c07de60u; return 0; }
goto P_0c07dfee;
P_0c07de62: /* original 0009, guest PC 0x0c07de62 */
if(!s->budget--) { s->failed_pc=0x0c07de62u; return 0; }
goto P_0c07de64;
P_0c07de64: /* original e038, guest PC 0x0c07de64 */
if(!s->budget--) { s->failed_pc=0x0c07de64u; return 0; }
r[0]=0x00000038u;
goto P_0c07de66;
P_0c07de66: /* original 6693, guest PC 0x0c07de66 */
if(!s->budget--) { s->failed_pc=0x0c07de66u; return 0; }
r[6]=r[9];
goto P_0c07de68;
P_0c07de68: /* original 0bed, guest PC 0x0c07de68 */
if(!s->budget--) { s->failed_pc=0x0c07de68u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07de6a;
P_0c07de6a: /* original e03a, guest PC 0x0c07de6a */
if(!s->budget--) { s->failed_pc=0x0c07de6au; return 0; }
r[0]=0x0000003au;
goto P_0c07de6c;
P_0c07de6c: /* original 03ed, guest PC 0x0c07de6c */
if(!s->budget--) { s->failed_pc=0x0c07de6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07de6e;
P_0c07de6e: /* original e040, guest PC 0x0c07de6e */
if(!s->budget--) { s->failed_pc=0x0c07de6eu; return 0; }
r[0]=0x00000040u;
goto P_0c07de70;
P_0c07de70: /* original e700, guest PC 0x0c07de70 */
if(!s->budget--) { s->failed_pc=0x0c07de70u; return 0; }
r[7]=0x00000000u;
goto P_0c07de72;
P_0c07de72: /* original 1f33, guest PC 0x0c07de72 */
if(!s->budget--) { s->failed_pc=0x0c07de72u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07de74;
P_0c07de74: /* original 63b3, guest PC 0x0c07de74 */
if(!s->budget--) { s->failed_pc=0x0c07de74u; return 0; }
r[3]=r[11];
goto P_0c07de76;
P_0c07de76: /* original 02ed, guest PC 0x0c07de76 */
if(!s->budget--) { s->failed_pc=0x0c07de76u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07de78;
P_0c07de78: /* original 4300, guest PC 0x0c07de78 */
if(!s->budget--) { s->failed_pc=0x0c07de78u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07de7a;
P_0c07de7a: /* original e042, guest PC 0x0c07de7a */
if(!s->budget--) { s->failed_pc=0x0c07de7au; return 0; }
r[0]=0x00000042u;
goto P_0c07de7c;
P_0c07de7c: /* original 2f22, guest PC 0x0c07de7c */
if(!s->budget--) { s->failed_pc=0x0c07de7cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07de7e;
P_0c07de7e: /* original e207, guest PC 0x0c07de7e */
if(!s->budget--) { s->failed_pc=0x0c07de7eu; return 0; }
r[2]=0x00000007u;
goto P_0c07de80;
P_0c07de80: /* original 51f3, guest PC 0x0c07de80 */
if(!s->budget--) { s->failed_pc=0x0c07de80u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07de82;
P_0c07de82: /* original 0aed, guest PC 0x0c07de82 */
if(!s->budget--) { s->failed_pc=0x0c07de82u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07de84;
P_0c07de84: /* original 412c, guest PC 0x0c07de84 */
if(!s->budget--) { s->failed_pc=0x0c07de84u; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c07de86;
P_0c07de86: /* original 231b, guest PC 0x0c07de86 */
if(!s->budget--) { s->failed_pc=0x0c07de86u; return 0; }
r[3]|=r[1];
goto P_0c07de88;
P_0c07de88: /* original 1f12, guest PC 0x0c07de88 */
if(!s->budget--) { s->failed_pc=0x0c07de88u; return 0; }
write(ram,r[15]+8,r[1],4);
goto P_0c07de8a;
P_0c07de8a: /* original 1f35, guest PC 0x0c07de8a */
if(!s->budget--) { s->failed_pc=0x0c07de8au; return 0; }
write(ram,r[15]+20,r[3],4);
goto P_0c07de8c;
P_0c07de8c: /* original 2fc6, guest PC 0x0c07de8c */
if(!s->budget--) { s->failed_pc=0x0c07de8cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07de8e;
P_0c07de8e: /* original 55f2, guest PC 0x0c07de8e */
if(!s->budget--) { s->failed_pc=0x0c07de8eu; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c07de90;
P_0c07de90: /* original d22d, guest PC 0x0c07de90 */
if(!s->budget--) { s->failed_pc=0x0c07de90u; return 0; }
r[2]=read(ram,0x0c07df48u,4);
goto P_0c07de92;
P_0c07de92: /* original 420b, guest PC 0x0c07de92 */
if(!s->budget--) { s->failed_pc=0x0c07de92u; return 0; }
target=r[2];
r[16]=code_base|0x0c07de96u;
r[4]=r[3];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07de96u) { target=s->pc; goto dispatch; }
goto P_0c07de96;
P_0c07de94: /* original 6433, guest PC 0x0c07de94 */
if(!s->budget--) { s->failed_pc=0x0c07de94u; return 0; }
r[4]=r[3];
goto P_0c07de96;
P_0c07de96: /* original 7f04, guest PC 0x0c07de96 */
if(!s->budget--) { s->failed_pc=0x0c07de96u; return 0; }
r[15]+=0x00000004u;
goto P_0c07de98;
P_0c07de98: /* original 934d, guest PC 0x0c07de98 */
if(!s->budget--) { s->failed_pc=0x0c07de98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07df36u,2);
goto P_0c07de9a;
P_0c07de9a: /* original 52f1, guest PC 0x0c07de9a */
if(!s->budget--) { s->failed_pc=0x0c07de9au; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07de9c;
P_0c07de9c: /* original 3230, guest PC 0x0c07de9c */
if(!s->budget--) { s->failed_pc=0x0c07de9cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c07de9e;
P_0c07de9e: /* original 8b01, guest PC 0x0c07de9e */
if(!s->budget--) { s->failed_pc=0x0c07de9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dea4; }
goto P_0c07dea0;
P_0c07dea0: /* original a001, guest PC 0x0c07dea0 */
if(!s->budget--) { s->failed_pc=0x0c07dea0u; return 0; }
r[4]=0x0000000du;
goto P_0c07dea6;
P_0c07dea2: /* original e40d, guest PC 0x0c07dea2 */
if(!s->budget--) { s->failed_pc=0x0c07dea2u; return 0; }
r[4]=0x0000000du;
goto P_0c07dea4;
P_0c07dea4: /* original e40f, guest PC 0x0c07dea4 */
if(!s->budget--) { s->failed_pc=0x0c07dea4u; return 0; }
r[4]=0x0000000fu;
goto P_0c07dea6;
P_0c07dea6: /* original 53f2, guest PC 0x0c07dea6 */
if(!s->budget--) { s->failed_pc=0x0c07dea6u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07dea8;
P_0c07dea8: /* original 34bc, guest PC 0x0c07dea8 */
if(!s->budget--) { s->failed_pc=0x0c07dea8u; return 0; }
r[4]+=r[11];
goto P_0c07deaa;
P_0c07deaa: /* original 4400, guest PC 0x0c07deaa */
if(!s->budget--) { s->failed_pc=0x0c07deaau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07deac;
P_0c07deac: /* original 6693, guest PC 0x0c07deac */
if(!s->budget--) { s->failed_pc=0x0c07deacu; return 0; }
r[6]=r[9];
goto P_0c07deae;
P_0c07deae: /* original 243b, guest PC 0x0c07deae */
if(!s->budget--) { s->failed_pc=0x0c07deaeu; return 0; }
r[4]|=r[3];
goto P_0c07deb0;
P_0c07deb0: /* original 1f45, guest PC 0x0c07deb0 */
if(!s->budget--) { s->failed_pc=0x0c07deb0u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c07deb2;
P_0c07deb2: /* original e700, guest PC 0x0c07deb2 */
if(!s->budget--) { s->failed_pc=0x0c07deb2u; return 0; }
r[7]=0x00000000u;
goto P_0c07deb4;
P_0c07deb4: /* original 2fc6, guest PC 0x0c07deb4 */
if(!s->budget--) { s->failed_pc=0x0c07deb4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07deb6;
P_0c07deb6: /* original 953f, guest PC 0x0c07deb6 */
if(!s->budget--) { s->failed_pc=0x0c07deb6u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07df38u,2);
goto P_0c07deb8;
P_0c07deb8: /* original d323, guest PC 0x0c07deb8 */
if(!s->budget--) { s->failed_pc=0x0c07deb8u; return 0; }
r[3]=read(ram,0x0c07df48u,4);
goto P_0c07deba;
P_0c07deba: /* original 430b, guest PC 0x0c07deba */
if(!s->budget--) { s->failed_pc=0x0c07debau; return 0; }
target=r[3];
r[16]=code_base|0x0c07debeu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07debeu) { target=s->pc; goto dispatch; }
goto P_0c07debe;
P_0c07debc: /* original 54f6, guest PC 0x0c07debc */
if(!s->budget--) { s->failed_pc=0x0c07debcu; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c07debe;
P_0c07debe: /* original 55f1, guest PC 0x0c07debe */
if(!s->budget--) { s->failed_pc=0x0c07debeu; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c07dec0;
P_0c07dec0: /* original 62a3, guest PC 0x0c07dec0 */
if(!s->budget--) { s->failed_pc=0x0c07dec0u; return 0; }
r[2]=r[10];
goto P_0c07dec2;
P_0c07dec2: /* original e307, guest PC 0x0c07dec2 */
if(!s->budget--) { s->failed_pc=0x0c07dec2u; return 0; }
r[3]=0x00000007u;
goto P_0c07dec4;
P_0c07dec4: /* original 423c, guest PC 0x0c07dec4 */
if(!s->budget--) { s->failed_pc=0x0c07dec4u; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c07dec6;
P_0c07dec6: /* original 4500, guest PC 0x0c07dec6 */
if(!s->budget--) { s->failed_pc=0x0c07dec6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07dec8;
P_0c07dec8: /* original 252b, guest PC 0x0c07dec8 */
if(!s->budget--) { s->failed_pc=0x0c07dec8u; return 0; }
r[5]|=r[2];
goto P_0c07deca;
P_0c07deca: /* original e120, guest PC 0x0c07deca */
if(!s->budget--) { s->failed_pc=0x0c07decau; return 0; }
r[1]=0x00000020u;
goto P_0c07decc;
P_0c07decc: /* original e628, guest PC 0x0c07decc */
if(!s->budget--) { s->failed_pc=0x0c07deccu; return 0; }
r[6]=0x00000028u;
goto P_0c07dece;
P_0c07dece: /* original 2f16, guest PC 0x0c07dece */
if(!s->budget--) { s->failed_pc=0x0c07deceu; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ded0;
P_0c07ded0: /* original d21e, guest PC 0x0c07ded0 */
if(!s->budget--) { s->failed_pc=0x0c07ded0u; return 0; }
r[2]=read(ram,0x0c07df4cu,4);
goto P_0c07ded2;
P_0c07ded2: /* original e705, guest PC 0x0c07ded2 */
if(!s->budget--) { s->failed_pc=0x0c07ded2u; return 0; }
r[7]=0x00000005u;
goto P_0c07ded4;
P_0c07ded4: /* original 420b, guest PC 0x0c07ded4 */
if(!s->budget--) { s->failed_pc=0x0c07ded4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07ded8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ded8u) { target=s->pc; goto dispatch; }
goto P_0c07ded8;
P_0c07ded6: /* original 64d3, guest PC 0x0c07ded6 */
if(!s->budget--) { s->failed_pc=0x0c07ded6u; return 0; }
r[4]=r[13];
goto P_0c07ded8;
P_0c07ded8: /* original e402, guest PC 0x0c07ded8 */
if(!s->budget--) { s->failed_pc=0x0c07ded8u; return 0; }
r[4]=0x00000002u;
goto P_0c07deda;
P_0c07deda: /* original 7bfc, guest PC 0x0c07deda */
if(!s->budget--) { s->failed_pc=0x0c07dedau; return 0; }
r[11]+=0xfffffffcu;
goto P_0c07dedc;
P_0c07dedc: /* original 3b43, guest PC 0x0c07dedc */
if(!s->budget--) { s->failed_pc=0x0c07dedcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[4])!=0);
goto P_0c07dede;
P_0c07dede: /* original 7f08, guest PC 0x0c07dede */
if(!s->budget--) { s->failed_pc=0x0c07dedeu; return 0; }
r[15]+=0x00000008u;
goto P_0c07dee0;
P_0c07dee0: /* original 8d01, guest PC 0x0c07dee0 */
if(!s->budget--) { s->failed_pc=0x0c07dee0u; return 0; }
cond=r[17]&1u;
r[10]+=0x00000004u;
if(cond) { goto P_0c07dee6; }
goto P_0c07dee4;
P_0c07dee2: /* original 7a04, guest PC 0x0c07dee2 */
if(!s->budget--) { s->failed_pc=0x0c07dee2u; return 0; }
r[10]+=0x00000004u;
goto P_0c07dee4;
P_0c07dee4: /* original 6b43, guest PC 0x0c07dee4 */
if(!s->budget--) { s->failed_pc=0x0c07dee4u; return 0; }
r[11]=r[4];
goto P_0c07dee6;
P_0c07dee6: /* original e42b, guest PC 0x0c07dee6 */
if(!s->budget--) { s->failed_pc=0x0c07dee6u; return 0; }
r[4]=0x0000002bu;
goto P_0c07dee8;
P_0c07dee8: /* original 3a47, guest PC 0x0c07dee8 */
if(!s->budget--) { s->failed_pc=0x0c07dee8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>(int32_t)r[4])!=0);
goto P_0c07deea;
P_0c07deea: /* original 8f01, guest PC 0x0c07deea */
if(!s->budget--) { s->failed_pc=0x0c07deeau; return 0; }
cond=r[17]&1u;
r[0]=0x00000038u;
if(!cond) { goto P_0c07def0; }
goto P_0c07deee;
P_0c07deec: /* original e038, guest PC 0x0c07deec */
if(!s->budget--) { s->failed_pc=0x0c07deecu; return 0; }
r[0]=0x00000038u;
goto P_0c07deee;
P_0c07deee: /* original 6a43, guest PC 0x0c07deee */
if(!s->budget--) { s->failed_pc=0x0c07deeeu; return 0; }
r[10]=r[4];
goto P_0c07def0;
P_0c07def0: /* original 0eb5, guest PC 0x0c07def0 */
if(!s->budget--) { s->failed_pc=0x0c07def0u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c07def2;
P_0c07def2: /* original e03a, guest PC 0x0c07def2 */
if(!s->budget--) { s->failed_pc=0x0c07def2u; return 0; }
r[0]=0x0000003au;
goto P_0c07def4;
P_0c07def4: /* original 53f3, guest PC 0x0c07def4 */
if(!s->budget--) { s->failed_pc=0x0c07def4u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c07def6;
P_0c07def6: /* original 0e35, guest PC 0x0c07def6 */
if(!s->budget--) { s->failed_pc=0x0c07def6u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c07def8;
P_0c07def8: /* original e040, guest PC 0x0c07def8 */
if(!s->budget--) { s->failed_pc=0x0c07def8u; return 0; }
r[0]=0x00000040u;
goto P_0c07defa;
P_0c07defa: /* original 62f2, guest PC 0x0c07defa */
if(!s->budget--) { s->failed_pc=0x0c07defau; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07defc;
P_0c07defc: /* original e33e, guest PC 0x0c07defc */
if(!s->budget--) { s->failed_pc=0x0c07defcu; return 0; }
r[3]=0x0000003eu;
goto P_0c07defe;
P_0c07defe: /* original 3b33, guest PC 0x0c07defe */
if(!s->budget--) { s->failed_pc=0x0c07defeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[3])!=0);
goto P_0c07df00;
P_0c07df00: /* original 0e25, guest PC 0x0c07df00 */
if(!s->budget--) { s->failed_pc=0x0c07df00u; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07df02;
P_0c07df02: /* original e042, guest PC 0x0c07df02 */
if(!s->budget--) { s->failed_pc=0x0c07df02u; return 0; }
r[0]=0x00000042u;
goto P_0c07df04;
P_0c07df04: /* original 8d35, guest PC 0x0c07df04 */
if(!s->budget--) { s->failed_pc=0x0c07df04u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[10],2);
if(cond) { goto P_0c07df72; }
goto P_0c07df08;
P_0c07df06: /* original 0ea5, guest PC 0x0c07df06 */
if(!s->budget--) { s->failed_pc=0x0c07df06u; return 0; }
write(ram,r[14]+r[0],r[10],2);
goto P_0c07df08;
P_0c07df08: /* original 52f2, guest PC 0x0c07df08 */
if(!s->budget--) { s->failed_pc=0x0c07df08u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07df0a;
P_0c07df0a: /* original 61b3, guest PC 0x0c07df0a */
if(!s->budget--) { s->failed_pc=0x0c07df0au; return 0; }
r[1]=r[11];
goto P_0c07df0c;
P_0c07df0c: /* original 4100, guest PC 0x0c07df0c */
if(!s->budget--) { s->failed_pc=0x0c07df0cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07df0e;
P_0c07df0e: /* original 6693, guest PC 0x0c07df0e */
if(!s->budget--) { s->failed_pc=0x0c07df0eu; return 0; }
r[6]=r[9];
goto P_0c07df10;
P_0c07df10: /* original 212b, guest PC 0x0c07df10 */
if(!s->budget--) { s->failed_pc=0x0c07df10u; return 0; }
r[1]|=r[2];
goto P_0c07df12;
P_0c07df12: /* original 1f13, guest PC 0x0c07df12 */
if(!s->budget--) { s->failed_pc=0x0c07df12u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07df14;
P_0c07df14: /* original e700, guest PC 0x0c07df14 */
if(!s->budget--) { s->failed_pc=0x0c07df14u; return 0; }
r[7]=0x00000000u;
goto P_0c07df16;
P_0c07df16: /* original 2fc6, guest PC 0x0c07df16 */
if(!s->budget--) { s->failed_pc=0x0c07df16u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07df18;
P_0c07df18: /* original 55f2, guest PC 0x0c07df18 */
if(!s->budget--) { s->failed_pc=0x0c07df18u; return 0; }
r[5]=read(ram,r[15]+8,4);
goto P_0c07df1a;
P_0c07df1a: /* original d30a, guest PC 0x0c07df1a */
if(!s->budget--) { s->failed_pc=0x0c07df1au; return 0; }
r[3]=read(ram,0x0c07df44u,4);
goto P_0c07df1c;
P_0c07df1c: /* original 430b, guest PC 0x0c07df1c */
if(!s->budget--) { s->failed_pc=0x0c07df1cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07df20u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07df20u) { target=s->pc; goto dispatch; }
goto P_0c07df20;
P_0c07df1e: /* original 6413, guest PC 0x0c07df1e */
if(!s->budget--) { s->failed_pc=0x0c07df1eu; return 0; }
r[4]=r[1];
goto P_0c07df20;
P_0c07df20: /* original 7f04, guest PC 0x0c07df20 */
if(!s->budget--) { s->failed_pc=0x0c07df20u; return 0; }
r[15]+=0x00000004u;
goto P_0c07df22;
P_0c07df22: /* original 9208, guest PC 0x0c07df22 */
if(!s->budget--) { s->failed_pc=0x0c07df22u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07df36u,2);
goto P_0c07df24;
P_0c07df24: /* original 53f1, guest PC 0x0c07df24 */
if(!s->budget--) { s->failed_pc=0x0c07df24u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07df26;
P_0c07df26: /* original 3320, guest PC 0x0c07df26 */
if(!s->budget--) { s->failed_pc=0x0c07df26u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07df28;
P_0c07df28: /* original 8f12, guest PC 0x0c07df28 */
if(!s->budget--) { s->failed_pc=0x0c07df28u; return 0; }
cond=r[17]&1u;
r[5]=r[11];
if(!cond) { goto P_0c07df50; }
goto P_0c07df2c;
P_0c07df2a: /* original 65b3, guest PC 0x0c07df2a */
if(!s->budget--) { s->failed_pc=0x0c07df2au; return 0; }
r[5]=r[11];
goto P_0c07df2c;
P_0c07df2c: /* original a011, guest PC 0x0c07df2c */
if(!s->budget--) { s->failed_pc=0x0c07df2cu; return 0; }
r[4]=0x0000000du;
goto P_0c07df52;
P_0c07df2e: /* original e40d, guest PC 0x0c07df2e */
if(!s->budget--) { s->failed_pc=0x0c07df2eu; return 0; }
r[4]=0x0000000du;
if(!vf3_matrix_family(0x0c07df30u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07df30u; return 0; } return 1;
P_0c07df50: /* original e40f, guest PC 0x0c07df50 */
if(!s->budget--) { s->failed_pc=0x0c07df50u; return 0; }
r[4]=0x0000000fu;
goto P_0c07df52;
P_0c07df52: /* original e23e, guest PC 0x0c07df52 */
if(!s->budget--) { s->failed_pc=0x0c07df52u; return 0; }
r[2]=0x0000003eu;
goto P_0c07df54;
P_0c07df54: /* original 354c, guest PC 0x0c07df54 */
if(!s->budget--) { s->failed_pc=0x0c07df54u; return 0; }
r[5]+=r[4];
goto P_0c07df56;
P_0c07df56: /* original 3522, guest PC 0x0c07df56 */
if(!s->budget--) { s->failed_pc=0x0c07df56u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>=r[2])!=0);
goto P_0c07df58;
P_0c07df58: /* original 890b, guest PC 0x0c07df58 */
if(!s->budget--) { s->failed_pc=0x0c07df58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07df72; }
goto P_0c07df5a;
P_0c07df5a: /* original 51f2, guest PC 0x0c07df5a */
if(!s->budget--) { s->failed_pc=0x0c07df5au; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07df5c;
P_0c07df5c: /* original 4500, guest PC 0x0c07df5c */
if(!s->budget--) { s->failed_pc=0x0c07df5cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c07df5e;
P_0c07df5e: /* original 6693, guest PC 0x0c07df5e */
if(!s->budget--) { s->failed_pc=0x0c07df5eu; return 0; }
r[6]=r[9];
goto P_0c07df60;
P_0c07df60: /* original e700, guest PC 0x0c07df60 */
if(!s->budget--) { s->failed_pc=0x0c07df60u; return 0; }
r[7]=0x00000000u;
goto P_0c07df62;
P_0c07df62: /* original 251b, guest PC 0x0c07df62 */
if(!s->budget--) { s->failed_pc=0x0c07df62u; return 0; }
r[5]|=r[1];
goto P_0c07df64;
P_0c07df64: /* original 1f51, guest PC 0x0c07df64 */
if(!s->budget--) { s->failed_pc=0x0c07df64u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c07df66;
P_0c07df66: /* original 2fc6, guest PC 0x0c07df66 */
if(!s->budget--) { s->failed_pc=0x0c07df66u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07df68;
P_0c07df68: /* original 9567, guest PC 0x0c07df68 */
if(!s->budget--) { s->failed_pc=0x0c07df68u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e03au,2);
goto P_0c07df6a;
P_0c07df6a: /* original d335, guest PC 0x0c07df6a */
if(!s->budget--) { s->failed_pc=0x0c07df6au; return 0; }
r[3]=read(ram,0x0c07e040u,4);
goto P_0c07df6c;
P_0c07df6c: /* original 430b, guest PC 0x0c07df6c */
if(!s->budget--) { s->failed_pc=0x0c07df6cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07df70u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07df70u) { target=s->pc; goto dispatch; }
goto P_0c07df70;
P_0c07df6e: /* original 54f2, guest PC 0x0c07df6e */
if(!s->budget--) { s->failed_pc=0x0c07df6eu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07df70;
P_0c07df70: /* original 7f04, guest PC 0x0c07df70 */
if(!s->budget--) { s->failed_pc=0x0c07df70u; return 0; }
r[15]+=0x00000004u;
goto P_0c07df72;
P_0c07df72: /* original 62f2, guest PC 0x0c07df72 */
if(!s->budget--) { s->failed_pc=0x0c07df72u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07df74;
P_0c07df74: /* original e307, guest PC 0x0c07df74 */
if(!s->budget--) { s->failed_pc=0x0c07df74u; return 0; }
r[3]=0x00000007u;
goto P_0c07df76;
P_0c07df76: /* original 4a3c, guest PC 0x0c07df76 */
if(!s->budget--) { s->failed_pc=0x0c07df76u; return 0; }
r[10]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[10]>>((-r[3])&31u)):((int32_t)r[10]<0?0xffffffffu:0)):r[10]<<(r[3]&31u);
goto P_0c07df78;
P_0c07df78: /* original 4200, guest PC 0x0c07df78 */
if(!s->budget--) { s->failed_pc=0x0c07df78u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07df7a;
P_0c07df7a: /* original 1fa2, guest PC 0x0c07df7a */
if(!s->budget--) { s->failed_pc=0x0c07df7au; return 0; }
write(ram,r[15]+8,r[10],4);
goto P_0c07df7c;
P_0c07df7c: /* original 22ab, guest PC 0x0c07df7c */
if(!s->budget--) { s->failed_pc=0x0c07df7cu; return 0; }
r[2]|=r[10];
goto P_0c07df7e;
P_0c07df7e: /* original 1f21, guest PC 0x0c07df7e */
if(!s->budget--) { s->failed_pc=0x0c07df7eu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c07df80;
P_0c07df80: /* original e204, guest PC 0x0c07df80 */
if(!s->budget--) { s->failed_pc=0x0c07df80u; return 0; }
r[2]=0x00000004u;
goto P_0c07df82;
P_0c07df82: /* original d530, guest PC 0x0c07df82 */
if(!s->budget--) { s->failed_pc=0x0c07df82u; return 0; }
r[5]=read(ram,0x0c07e044u,4);
goto P_0c07df84;
P_0c07df84: /* original 5452, guest PC 0x0c07df84 */
if(!s->budget--) { s->failed_pc=0x0c07df84u; return 0; }
r[4]=read(ram,r[5]+8,4);
goto P_0c07df86;
P_0c07df86: /* original 2428, guest PC 0x0c07df86 */
if(!s->budget--) { s->failed_pc=0x0c07df86u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c07df88;
P_0c07df88: /* original 891c, guest PC 0x0c07df88 */
if(!s->budget--) { s->failed_pc=0x0c07df88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dfc4; }
goto P_0c07df8a;
P_0c07df8a: /* original e01c, guest PC 0x0c07df8a */
if(!s->budget--) { s->failed_pc=0x0c07df8au; return 0; }
r[0]=0x0000001cu;
goto P_0c07df8c;
P_0c07df8c: /* original 065c, guest PC 0x0c07df8c */
if(!s->budget--) { s->failed_pc=0x0c07df8cu; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07df8e;
P_0c07df8e: /* original e019, guest PC 0x0c07df8e */
if(!s->budget--) { s->failed_pc=0x0c07df8eu; return 0; }
r[0]=0x00000019u;
goto P_0c07df90;
P_0c07df90: /* original 045c, guest PC 0x0c07df90 */
if(!s->budget--) { s->failed_pc=0x0c07df90u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07df92;
P_0c07df92: /* original e029, guest PC 0x0c07df92 */
if(!s->budget--) { s->failed_pc=0x0c07df92u; return 0; }
r[0]=0x00000029u;
goto P_0c07df94;
P_0c07df94: /* original 055c, guest PC 0x0c07df94 */
if(!s->budget--) { s->failed_pc=0x0c07df94u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07df96;
P_0c07df96: /* original 666c, guest PC 0x0c07df96 */
if(!s->budget--) { s->failed_pc=0x0c07df96u; return 0; }
r[6]=r[6]&255u;
goto P_0c07df98;
P_0c07df98: /* original 6063, guest PC 0x0c07df98 */
if(!s->budget--) { s->failed_pc=0x0c07df98u; return 0; }
r[0]=r[6];
goto P_0c07df9a;
P_0c07df9a: /* original 8801, guest PC 0x0c07df9a */
if(!s->budget--) { s->failed_pc=0x0c07df9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07df9c;
P_0c07df9c: /* original 644c, guest PC 0x0c07df9c */
if(!s->budget--) { s->failed_pc=0x0c07df9cu; return 0; }
r[4]=r[4]&255u;
goto P_0c07df9e;
P_0c07df9e: /* original 8d11, guest PC 0x0c07df9e */
if(!s->budget--) { s->failed_pc=0x0c07df9eu; return 0; }
cond=r[17]&1u;
r[5]=r[5]&255u;
if(cond) { goto P_0c07dfc4; }
goto P_0c07dfa2;
P_0c07dfa0: /* original 655c, guest PC 0x0c07dfa0 */
if(!s->budget--) { s->failed_pc=0x0c07dfa0u; return 0; }
r[5]=r[5]&255u;
goto P_0c07dfa2;
P_0c07dfa2: /* original 6053, guest PC 0x0c07dfa2 */
if(!s->budget--) { s->failed_pc=0x0c07dfa2u; return 0; }
r[0]=r[5];
goto P_0c07dfa4;
P_0c07dfa4: /* original 8802, guest PC 0x0c07dfa4 */
if(!s->budget--) { s->failed_pc=0x0c07dfa4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07dfa6;
P_0c07dfa6: /* original 8b02, guest PC 0x0c07dfa6 */
if(!s->budget--) { s->failed_pc=0x0c07dfa6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dfae; }
goto P_0c07dfa8;
P_0c07dfa8: /* original 6043, guest PC 0x0c07dfa8 */
if(!s->budget--) { s->failed_pc=0x0c07dfa8u; return 0; }
r[0]=r[4];
goto P_0c07dfaa;
P_0c07dfaa: /* original 8802, guest PC 0x0c07dfaa */
if(!s->budget--) { s->failed_pc=0x0c07dfaau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07dfac;
P_0c07dfac: /* original 8912, guest PC 0x0c07dfac */
if(!s->budget--) { s->failed_pc=0x0c07dfacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dfd4; }
goto P_0c07dfae;
P_0c07dfae: /* original 6053, guest PC 0x0c07dfae */
if(!s->budget--) { s->failed_pc=0x0c07dfaeu; return 0; }
r[0]=r[5];
goto P_0c07dfb0;
P_0c07dfb0: /* original 8801, guest PC 0x0c07dfb0 */
if(!s->budget--) { s->failed_pc=0x0c07dfb0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07dfb2;
P_0c07dfb2: /* original 8b02, guest PC 0x0c07dfb2 */
if(!s->budget--) { s->failed_pc=0x0c07dfb2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dfba; }
goto P_0c07dfb4;
P_0c07dfb4: /* original 6043, guest PC 0x0c07dfb4 */
if(!s->budget--) { s->failed_pc=0x0c07dfb4u; return 0; }
r[0]=r[4];
goto P_0c07dfb6;
P_0c07dfb6: /* original 8801, guest PC 0x0c07dfb6 */
if(!s->budget--) { s->failed_pc=0x0c07dfb6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07dfb8;
P_0c07dfb8: /* original 890c, guest PC 0x0c07dfb8 */
if(!s->budget--) { s->failed_pc=0x0c07dfb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dfd4; }
goto P_0c07dfba;
P_0c07dfba: /* original 6053, guest PC 0x0c07dfba */
if(!s->budget--) { s->failed_pc=0x0c07dfbau; return 0; }
r[0]=r[5];
goto P_0c07dfbc;
P_0c07dfbc: /* original 8802, guest PC 0x0c07dfbc */
if(!s->budget--) { s->failed_pc=0x0c07dfbcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07dfbe;
P_0c07dfbe: /* original 8b01, guest PC 0x0c07dfbe */
if(!s->budget--) { s->failed_pc=0x0c07dfbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07dfc4; }
goto P_0c07dfc0;
P_0c07dfc0: /* original 2448, guest PC 0x0c07dfc0 */
if(!s->budget--) { s->failed_pc=0x0c07dfc0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07dfc2;
P_0c07dfc2: /* original 8907, guest PC 0x0c07dfc2 */
if(!s->budget--) { s->failed_pc=0x0c07dfc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07dfd4; }
goto P_0c07dfc4;
P_0c07dfc4: /* original 66d3, guest PC 0x0c07dfc4 */
if(!s->budget--) { s->failed_pc=0x0c07dfc4u; return 0; }
r[6]=r[13];
goto P_0c07dfc6;
P_0c07dfc6: /* original 2f86, guest PC 0x0c07dfc6 */
if(!s->budget--) { s->failed_pc=0x0c07dfc6u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dfc8;
P_0c07dfc8: /* original 9538, guest PC 0x0c07dfc8 */
if(!s->budget--) { s->failed_pc=0x0c07dfc8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07e03cu,2);
goto P_0c07dfca;
P_0c07dfca: /* original e700, guest PC 0x0c07dfca */
if(!s->budget--) { s->failed_pc=0x0c07dfcau; return 0; }
r[7]=0x00000000u;
goto P_0c07dfcc;
P_0c07dfcc: /* original d31c, guest PC 0x0c07dfcc */
if(!s->budget--) { s->failed_pc=0x0c07dfccu; return 0; }
r[3]=read(ram,0x0c07e040u,4);
goto P_0c07dfce;
P_0c07dfce: /* original 430b, guest PC 0x0c07dfce */
if(!s->budget--) { s->failed_pc=0x0c07dfceu; return 0; }
target=r[3];
r[16]=code_base|0x0c07dfd2u;
r[4]=read(ram,r[15]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dfd2u) { target=s->pc; goto dispatch; }
goto P_0c07dfd2;
P_0c07dfd0: /* original 54f2, guest PC 0x0c07dfd0 */
if(!s->budget--) { s->failed_pc=0x0c07dfd0u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c07dfd2;
P_0c07dfd2: /* original 7f04, guest PC 0x0c07dfd2 */
if(!s->budget--) { s->failed_pc=0x0c07dfd2u; return 0; }
r[15]+=0x00000004u;
goto P_0c07dfd4;
P_0c07dfd4: /* original 6af2, guest PC 0x0c07dfd4 */
if(!s->budget--) { s->failed_pc=0x0c07dfd4u; return 0; }
tmp=read(ram,r[15],4);
r[10]=tmp;
goto P_0c07dfd6;
P_0c07dfd6: /* original 6693, guest PC 0x0c07dfd6 */
if(!s->budget--) { s->failed_pc=0x0c07dfd6u; return 0; }
r[6]=r[9];
goto P_0c07dfd8;
P_0c07dfd8: /* original 53f2, guest PC 0x0c07dfd8 */
if(!s->budget--) { s->failed_pc=0x0c07dfd8u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07dfda;
P_0c07dfda: /* original e700, guest PC 0x0c07dfda */
if(!s->budget--) { s->failed_pc=0x0c07dfdau; return 0; }
r[7]=0x00000000u;
goto P_0c07dfdc;
P_0c07dfdc: /* original 2f86, guest PC 0x0c07dfdc */
if(!s->budget--) { s->failed_pc=0x0c07dfdcu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07dfde;
P_0c07dfde: /* original 7a08, guest PC 0x0c07dfde */
if(!s->budget--) { s->failed_pc=0x0c07dfdeu; return 0; }
r[10]+=0x00000008u;
goto P_0c07dfe0;
P_0c07dfe0: /* original 55f7, guest PC 0x0c07dfe0 */
if(!s->budget--) { s->failed_pc=0x0c07dfe0u; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c07dfe2;
P_0c07dfe2: /* original 4a00, guest PC 0x0c07dfe2 */
if(!s->budget--) { s->failed_pc=0x0c07dfe2u; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c07dfe4;
P_0c07dfe4: /* original d216, guest PC 0x0c07dfe4 */
if(!s->budget--) { s->failed_pc=0x0c07dfe4u; return 0; }
r[2]=read(ram,0x0c07e040u,4);
goto P_0c07dfe6;
P_0c07dfe6: /* original 2a3b, guest PC 0x0c07dfe6 */
if(!s->budget--) { s->failed_pc=0x0c07dfe6u; return 0; }
r[10]|=r[3];
goto P_0c07dfe8;
P_0c07dfe8: /* original 420b, guest PC 0x0c07dfe8 */
if(!s->budget--) { s->failed_pc=0x0c07dfe8u; return 0; }
target=r[2];
r[16]=code_base|0x0c07dfecu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07dfecu) { target=s->pc; goto dispatch; }
goto P_0c07dfec;
P_0c07dfea: /* original 64a3, guest PC 0x0c07dfea */
if(!s->budget--) { s->failed_pc=0x0c07dfeau; return 0; }
r[4]=r[10];
goto P_0c07dfec;
P_0c07dfec: /* original 7f04, guest PC 0x0c07dfec */
if(!s->budget--) { s->failed_pc=0x0c07dfecu; return 0; }
r[15]+=0x00000004u;
goto P_0c07dfee;
P_0c07dfee: /* original 54f4, guest PC 0x0c07dfee */
if(!s->budget--) { s->failed_pc=0x0c07dfeeu; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c07dff0;
P_0c07dff0: /* original 7f1c, guest PC 0x0c07dff0 */
if(!s->budget--) { s->failed_pc=0x0c07dff0u; return 0; }
r[15]+=0x0000001cu;
goto P_0c07dff2;
P_0c07dff2: /* original 4f16, guest PC 0x0c07dff2 */
if(!s->budget--) { s->failed_pc=0x0c07dff2u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07dff4;
P_0c07dff4: /* original 65a3, guest PC 0x0c07dff4 */
if(!s->budget--) { s->failed_pc=0x0c07dff4u; return 0; }
r[5]=r[10];
goto P_0c07dff6;
P_0c07dff6: /* original d314, guest PC 0x0c07dff6 */
if(!s->budget--) { s->failed_pc=0x0c07dff6u; return 0; }
r[3]=read(ram,0x0c07e048u,4);
goto P_0c07dff8;
P_0c07dff8: /* original 4f26, guest PC 0x0c07dff8 */
if(!s->budget--) { s->failed_pc=0x0c07dff8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07dffa;
P_0c07dffa: /* original 68f6, guest PC 0x0c07dffa */
if(!s->budget--) { s->failed_pc=0x0c07dffau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07dffc;
P_0c07dffc: /* original 69f6, guest PC 0x0c07dffc */
if(!s->budget--) { s->failed_pc=0x0c07dffcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07dffe;
P_0c07dffe: /* original 6af6, guest PC 0x0c07dffe */
if(!s->budget--) { s->failed_pc=0x0c07dffeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07e000;
P_0c07e000: /* original 6bf6, guest PC 0x0c07e000 */
if(!s->budget--) { s->failed_pc=0x0c07e000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07e002;
P_0c07e002: /* original 6cf6, guest PC 0x0c07e002 */
if(!s->budget--) { s->failed_pc=0x0c07e002u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07e004;
P_0c07e004: /* original 6df6, guest PC 0x0c07e004 */
if(!s->budget--) { s->failed_pc=0x0c07e004u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07e006;
P_0c07e006: /* original 432b, guest PC 0x0c07e006 */
if(!s->budget--) { s->failed_pc=0x0c07e006u; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
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
P_0c07e008: /* original 6ef6, guest PC 0x0c07e008 */
if(!s->budget--) { s->failed_pc=0x0c07e008u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07e00a;
P_0c07e00a: /* original c710, guest PC 0x0c07e00a */
if(!s->budget--) { s->failed_pc=0x0c07e00au; return 0; }
r[0]=code_base|0x0007e04cu;
goto P_0c07e00c;
P_0c07e00c: /* original 2fd6, guest PC 0x0c07e00c */
if(!s->budget--) { s->failed_pc=0x0c07e00cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07e00e;
P_0c07e00e: /* original f508, guest PC 0x0c07e00e */
if(!s->budget--) { s->failed_pc=0x0c07e00eu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c07e010;
P_0c07e010: /* original c70f, guest PC 0x0c07e010 */
if(!s->budget--) { s->failed_pc=0x0c07e010u; return 0; }
r[0]=code_base|0x0007e050u;
goto P_0c07e012;
P_0c07e012: /* original f908, guest PC 0x0c07e012 */
if(!s->budget--) { s->failed_pc=0x0c07e012u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c07e014;
P_0c07e014: /* original c70f, guest PC 0x0c07e014 */
if(!s->budget--) { s->failed_pc=0x0c07e014u; return 0; }
r[0]=code_base|0x0007e054u;
goto P_0c07e016;
P_0c07e016: /* original f708, guest PC 0x0c07e016 */
if(!s->budget--) { s->failed_pc=0x0c07e016u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c07e018;
P_0c07e018: /* original e302, guest PC 0x0c07e018 */
if(!s->budget--) { s->failed_pc=0x0c07e018u; return 0; }
r[3]=0x00000002u;
goto P_0c07e01a;
P_0c07e01a: /* original 6d43, guest PC 0x0c07e01a */
if(!s->budget--) { s->failed_pc=0x0c07e01au; return 0; }
r[13]=r[4];
goto P_0c07e01c;
P_0c07e01c: /* original 2358, guest PC 0x0c07e01c */
if(!s->budget--) { s->failed_pc=0x0c07e01cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c07e01e;
P_0c07e01e: /* original 7444, guest PC 0x0c07e01e */
if(!s->budget--) { s->failed_pc=0x0c07e01eu; return 0; }
r[4]+=0x00000044u;
goto P_0c07e020;
P_0c07e020: /* original e701, guest PC 0x0c07e020 */
if(!s->budget--) { s->failed_pc=0x0c07e020u; return 0; }
r[7]=0x00000001u;
goto P_0c07e022;
P_0c07e022: /* original 8f1d, guest PC 0x0c07e022 */
if(!s->budget--) { s->failed_pc=0x0c07e022u; return 0; }
cond=r[17]&1u;
r[7]&=r[5];
if(!cond) { goto P_0c07e060; }
goto P_0c07e026;
P_0c07e024: /* original 2759, guest PC 0x0c07e024 */
if(!s->budget--) { s->failed_pc=0x0c07e024u; return 0; }
r[7]&=r[5];
goto P_0c07e026;
P_0c07e026: /* original 2778, guest PC 0x0c07e026 */
if(!s->budget--) { s->failed_pc=0x0c07e026u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c07e028;
P_0c07e028: /* original c70b, guest PC 0x0c07e028 */
if(!s->budget--) { s->failed_pc=0x0c07e028u; return 0; }
r[0]=code_base|0x0007e058u;
goto P_0c07e02a;
P_0c07e02a: /* original 8d01, guest PC 0x0c07e02a */
if(!s->budget--) { s->failed_pc=0x0c07e02au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c07e030; }
goto P_0c07e02e;
P_0c07e02c: /* original f408, guest PC 0x0c07e02c */
if(!s->budget--) { s->failed_pc=0x0c07e02cu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c07e02e;
P_0c07e02e: /* original f45c, guest PC 0x0c07e02e */
if(!s->budget--) { s->failed_pc=0x0c07e02eu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c07e030;
P_0c07e030: /* original c70a, guest PC 0x0c07e030 */
if(!s->budget--) { s->failed_pc=0x0c07e030u; return 0; }
r[0]=code_base|0x0007e05cu;
goto P_0c07e032;
P_0c07e032: /* original f67c, guest PC 0x0c07e032 */
if(!s->budget--) { s->failed_pc=0x0c07e032u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c07e034;
P_0c07e034: /* original f508, guest PC 0x0c07e034 */
if(!s->budget--) { s->failed_pc=0x0c07e034u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c07e036;
P_0c07e036: /* original a01e, guest PC 0x0c07e036 */
if(!s->budget--) { s->failed_pc=0x0c07e036u; return 0; }
vf3_matrix_move(s,11,9);
goto P_0c07e076;
P_0c07e038: /* original fb9c, guest PC 0x0c07e038 */
if(!s->budget--) { s->failed_pc=0x0c07e038u; return 0; }
vf3_matrix_move(s,11,9);
if(!vf3_matrix_family(0x0c07e03au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07e03au; return 0; } return 1;
P_0c07e060: /* original 2778, guest PC 0x0c07e060 */
if(!s->budget--) { s->failed_pc=0x0c07e060u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c07e062;
P_0c07e062: /* original c74e, guest PC 0x0c07e062 */
if(!s->budget--) { s->failed_pc=0x0c07e062u; return 0; }
r[0]=code_base|0x0007e19cu;
goto P_0c07e064;
P_0c07e064: /* original 8d01, guest PC 0x0c07e064 */
if(!s->budget--) { s->failed_pc=0x0c07e064u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,4,r[0]);
if(cond) { goto P_0c07e06a; }
goto P_0c07e068;
P_0c07e066: /* original f408, guest PC 0x0c07e066 */
if(!s->budget--) { s->failed_pc=0x0c07e066u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c07e068;
P_0c07e068: /* original f45c, guest PC 0x0c07e068 */
if(!s->budget--) { s->failed_pc=0x0c07e068u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c07e06a;
P_0c07e06a: /* original c74d, guest PC 0x0c07e06a */
if(!s->budget--) { s->failed_pc=0x0c07e06au; return 0; }
r[0]=code_base|0x0007e1a0u;
goto P_0c07e06c;
P_0c07e06c: /* original f508, guest PC 0x0c07e06c */
if(!s->budget--) { s->failed_pc=0x0c07e06cu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c07e06e;
P_0c07e06e: /* original c74d, guest PC 0x0c07e06e */
if(!s->budget--) { s->failed_pc=0x0c07e06eu; return 0; }
r[0]=code_base|0x0007e1a4u;
goto P_0c07e070;
P_0c07e070: /* original f608, guest PC 0x0c07e070 */
if(!s->budget--) { s->failed_pc=0x0c07e070u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c07e072;
P_0c07e072: /* original c74d, guest PC 0x0c07e072 */
if(!s->budget--) { s->failed_pc=0x0c07e072u; return 0; }
r[0]=code_base|0x0007e1a8u;
goto P_0c07e074;
P_0c07e074: /* original fb08, guest PC 0x0c07e074 */
if(!s->budget--) { s->failed_pc=0x0c07e074u; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c07e076;
P_0c07e076: /* original c74d, guest PC 0x0c07e076 */
if(!s->budget--) { s->failed_pc=0x0c07e076u; return 0; }
r[0]=code_base|0x0007e1acu;
goto P_0c07e078;
P_0c07e078: /* original e504, guest PC 0x0c07e078 */
if(!s->budget--) { s->failed_pc=0x0c07e078u; return 0; }
r[5]=0x00000004u;
goto P_0c07e07a;
P_0c07e07a: /* original fa08, guest PC 0x0c07e07a */
if(!s->budget--) { s->failed_pc=0x0c07e07au; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c07e07c;
P_0c07e07c: /* original 6153, guest PC 0x0c07e07c */
if(!s->budget--) { s->failed_pc=0x0c07e07cu; return 0; }
r[1]=r[5];
goto P_0c07e07e;
P_0c07e07e: /* original 6753, guest PC 0x0c07e07e */
if(!s->budget--) { s->failed_pc=0x0c07e07eu; return 0; }
r[7]=r[5];
goto P_0c07e080;
P_0c07e080: /* original e004, guest PC 0x0c07e080 */
if(!s->budget--) { s->failed_pc=0x0c07e080u; return 0; }
r[0]=0x00000004u;
goto P_0c07e082;
P_0c07e082: /* original f44a, guest PC 0x0c07e082 */
if(!s->budget--) { s->failed_pc=0x0c07e082u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c07e084;
P_0c07e084: /* original f457, guest PC 0x0c07e084 */
if(!s->budget--) { s->failed_pc=0x0c07e084u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c07e086;
P_0c07e086: /* original 4710, guest PC 0x0c07e086 */
if(!s->budget--) { s->failed_pc=0x0c07e086u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c07e088;
P_0c07e088: /* original 7410, guest PC 0x0c07e088 */
if(!s->budget--) { s->failed_pc=0x0c07e088u; return 0; }
r[4]+=0x00000010u;
goto P_0c07e08a;
P_0c07e08a: /* original 8ff9, guest PC 0x0c07e08a */
if(!s->budget--) { s->failed_pc=0x0c07e08au; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
if(!cond) { goto P_0c07e080; }
goto P_0c07e08e;
P_0c07e08c: /* original f460, guest PC 0x0c07e08c */
if(!s->budget--) { s->failed_pc=0x0c07e08cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'+');
goto P_0c07e08e;
P_0c07e08e: /* original f0ac, guest PC 0x0c07e08e */
if(!s->budget--) { s->failed_pc=0x0c07e08eu; return 0; }
vf3_matrix_move(s,0,10);
goto P_0c07e090;
P_0c07e090: /* original 4110, guest PC 0x0c07e090 */
if(!s->budget--) { s->failed_pc=0x0c07e090u; return 0; }
--r[1];
r[17]=(r[17]&~1u)|((r[1]==0)!=0);
goto P_0c07e092;
P_0c07e092: /* original f34c, guest PC 0x0c07e092 */
if(!s->budget--) { s->failed_pc=0x0c07e092u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c07e094;
P_0c07e094: /* original f36e, guest PC 0x0c07e094 */
if(!s->budget--) { s->failed_pc=0x0c07e094u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c07e096;
P_0c07e096: /* original f8ac, guest PC 0x0c07e096 */
if(!s->budget--) { s->failed_pc=0x0c07e096u; return 0; }
vf3_matrix_move(s,8,10);
goto P_0c07e098;
P_0c07e098: /* original f43c, guest PC 0x0c07e098 */
if(!s->budget--) { s->failed_pc=0x0c07e098u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c07e09a;
P_0c07e09a: /* original 8ff0, guest PC 0x0c07e09a */
if(!s->budget--) { s->failed_pc=0x0c07e09au; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
if(!cond) { goto P_0c07e07e; }
goto P_0c07e09e;
P_0c07e09c: /* original f5b0, guest PC 0x0c07e09c */
if(!s->budget--) { s->failed_pc=0x0c07e09cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[11],r[18],'+');
goto P_0c07e09e;
P_0c07e09e: /* original 465a, guest PC 0x0c07e09e */
if(!s->budget--) { s->failed_pc=0x0c07e09eu; return 0; }
r[53]=r[6];
goto P_0c07e0a0;
P_0c07e0a0: /* original 64d3, guest PC 0x0c07e0a0 */
if(!s->budget--) { s->failed_pc=0x0c07e0a0u; return 0; }
r[4]=r[13];
goto P_0c07e0a2;
P_0c07e0a2: /* original 4611, guest PC 0x0c07e0a2 */
if(!s->budget--) { s->failed_pc=0x0c07e0a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>=0)!=0);
goto P_0c07e0a4;
P_0c07e0a4: /* original 7444, guest PC 0x0c07e0a4 */
if(!s->budget--) { s->failed_pc=0x0c07e0a4u; return 0; }
r[4]+=0x00000044u;
goto P_0c07e0a6;
P_0c07e0a6: /* original 8d04, guest PC 0x0c07e0a6 */
if(!s->budget--) { s->failed_pc=0x0c07e0a6u; return 0; }
cond=r[17]&1u;
fr[3]=vf3_fpu_float(r[53],r[18]);
if(cond) { goto P_0c07e0b2; }
goto P_0c07e0aa;
P_0c07e0a8: /* original f32d, guest PC 0x0c07e0a8 */
if(!s->budget--) { s->failed_pc=0x0c07e0a8u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c07e0aa;
P_0c07e0aa: /* original d241, guest PC 0x0c07e0aa */
if(!s->budget--) { s->failed_pc=0x0c07e0aau; return 0; }
r[2]=read(ram,0x0c07e1b0u,4);
goto P_0c07e0ac;
P_0c07e0ac: /* original 425a, guest PC 0x0c07e0ac */
if(!s->budget--) { s->failed_pc=0x0c07e0acu; return 0; }
r[53]=r[2];
goto P_0c07e0ae;
P_0c07e0ae: /* original f20d, guest PC 0x0c07e0ae */
if(!s->budget--) { s->failed_pc=0x0c07e0aeu; return 0; }
fr[2]=r[53];
goto P_0c07e0b0;
P_0c07e0b0: /* original f320, guest PC 0x0c07e0b0 */
if(!s->budget--) { s->failed_pc=0x0c07e0b0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'+');
goto P_0c07e0b2;
P_0c07e0b2: /* original f59d, guest PC 0x0c07e0b2 */
if(!s->budget--) { s->failed_pc=0x0c07e0b2u; return 0; }
fr[5]=0x3f800000u;
goto P_0c07e0b4;
P_0c07e0b4: /* original f533, guest PC 0x0c07e0b4 */
if(!s->budget--) { s->failed_pc=0x0c07e0b4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'/');
goto P_0c07e0b6;
P_0c07e0b6: /* original fb8d, guest PC 0x0c07e0b6 */
if(!s->budget--) { s->failed_pc=0x0c07e0b6u; return 0; }
fr[11]=0;
goto P_0c07e0b8;
P_0c07e0b8: /* original 6753, guest PC 0x0c07e0b8 */
if(!s->budget--) { s->failed_pc=0x0c07e0b8u; return 0; }
r[7]=r[5];
goto P_0c07e0ba;
P_0c07e0ba: /* original fabc, guest PC 0x0c07e0ba */
if(!s->budget--) { s->failed_pc=0x0c07e0bau; return 0; }
vf3_matrix_move(s,10,11);
goto P_0c07e0bc;
P_0c07e0bc: /* original 6653, guest PC 0x0c07e0bc */
if(!s->budget--) { s->failed_pc=0x0c07e0bcu; return 0; }
r[6]=r[5];
goto P_0c07e0be;
P_0c07e0be: /* original f4bc, guest PC 0x0c07e0be */
if(!s->budget--) { s->failed_pc=0x0c07e0beu; return 0; }
vf3_matrix_move(s,4,11);
goto P_0c07e0c0;
P_0c07e0c0: /* original f848, guest PC 0x0c07e0c0 */
if(!s->budget--) { s->failed_pc=0x0c07e0c0u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
goto P_0c07e0c2;
P_0c07e0c2: /* original e004, guest PC 0x0c07e0c2 */
if(!s->budget--) { s->failed_pc=0x0c07e0c2u; return 0; }
r[0]=0x00000004u;
goto P_0c07e0c4;
P_0c07e0c4: /* original f34c, guest PC 0x0c07e0c4 */
if(!s->budget--) { s->failed_pc=0x0c07e0c4u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c07e0c6;
P_0c07e0c6: /* original 4610, guest PC 0x0c07e0c6 */
if(!s->budget--) { s->failed_pc=0x0c07e0c6u; return 0; }
--r[6];
r[17]=(r[17]&~1u)|((r[6]==0)!=0);
goto P_0c07e0c8;
P_0c07e0c8: /* original f381, guest PC 0x0c07e0c8 */
if(!s->budget--) { s->failed_pc=0x0c07e0c8u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'-');
goto P_0c07e0ca;
P_0c07e0ca: /* original f646, guest PC 0x0c07e0ca */
if(!s->budget--) { s->failed_pc=0x0c07e0cau; return 0; }
vf3_matrix_load(s,ram,6,r[4]+r[0]);
goto P_0c07e0cc;
P_0c07e0cc: /* original f2ac, guest PC 0x0c07e0cc */
if(!s->budget--) { s->failed_pc=0x0c07e0ccu; return 0; }
vf3_matrix_move(s,2,10);
goto P_0c07e0ce;
P_0c07e0ce: /* original e008, guest PC 0x0c07e0ce */
if(!s->budget--) { s->failed_pc=0x0c07e0ceu; return 0; }
r[0]=0x00000008u;
goto P_0c07e0d0;
P_0c07e0d0: /* original f261, guest PC 0x0c07e0d0 */
if(!s->budget--) { s->failed_pc=0x0c07e0d0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'-');
goto P_0c07e0d2;
P_0c07e0d2: /* original f83c, guest PC 0x0c07e0d2 */
if(!s->budget--) { s->failed_pc=0x0c07e0d2u; return 0; }
vf3_matrix_move(s,8,3);
goto P_0c07e0d4;
P_0c07e0d4: /* original f852, guest PC 0x0c07e0d4 */
if(!s->budget--) { s->failed_pc=0x0c07e0d4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c07e0d6;
P_0c07e0d6: /* original f62c, guest PC 0x0c07e0d6 */
if(!s->budget--) { s->failed_pc=0x0c07e0d6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c07e0d8;
P_0c07e0d8: /* original f652, guest PC 0x0c07e0d8 */
if(!s->budget--) { s->failed_pc=0x0c07e0d8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'*');
goto P_0c07e0da;
P_0c07e0da: /* original f487, guest PC 0x0c07e0da */
if(!s->budget--) { s->failed_pc=0x0c07e0dau; return 0; }
vf3_matrix_store(s,ram,8,r[4]+r[0]);
goto P_0c07e0dc;
P_0c07e0dc: /* original e00c, guest PC 0x0c07e0dc */
if(!s->budget--) { s->failed_pc=0x0c07e0dcu; return 0; }
r[0]=0x0000000cu;
goto P_0c07e0de;
P_0c07e0de: /* original f467, guest PC 0x0c07e0de */
if(!s->budget--) { s->failed_pc=0x0c07e0deu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c07e0e0;
P_0c07e0e0: /* original 7410, guest PC 0x0c07e0e0 */
if(!s->budget--) { s->failed_pc=0x0c07e0e0u; return 0; }
r[4]+=0x00000010u;
goto P_0c07e0e2;
P_0c07e0e2: /* original 8fed, guest PC 0x0c07e0e2 */
if(!s->budget--) { s->failed_pc=0x0c07e0e2u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
if(!cond) { goto P_0c07e0c0; }
goto P_0c07e0e6;
P_0c07e0e4: /* original f470, guest PC 0x0c07e0e4 */
if(!s->budget--) { s->failed_pc=0x0c07e0e4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'+');
goto P_0c07e0e6;
P_0c07e0e6: /* original 4710, guest PC 0x0c07e0e6 */
if(!s->budget--) { s->failed_pc=0x0c07e0e6u; return 0; }
--r[7];
r[17]=(r[17]&~1u)|((r[7]==0)!=0);
goto P_0c07e0e8;
P_0c07e0e8: /* original 8fe8, guest PC 0x0c07e0e8 */
if(!s->budget--) { s->failed_pc=0x0c07e0e8u; return 0; }
cond=r[17]&1u;
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'+');
if(!cond) { goto P_0c07e0bc; }
goto P_0c07e0ec;
P_0c07e0ea: /* original fa90, guest PC 0x0c07e0ea */
if(!s->budget--) { s->failed_pc=0x0c07e0eau; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[9],r[18],'+');
goto P_0c07e0ec;
P_0c07e0ec: /* original 000b, guest PC 0x0c07e0ec */
if(!s->budget--) { s->failed_pc=0x0c07e0ecu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
s->pc=target; return ram->oob==0;
P_0c07e0ee: /* original 6df6, guest PC 0x0c07e0ee */
if(!s->budget--) { s->failed_pc=0x0c07e0eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
return vf3_matrix_family(0x0c07e0f0u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
