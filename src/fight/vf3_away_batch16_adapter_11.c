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
int vf3_away_batch16_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08dcb0u: goto P_0c08dcb0;
case 0x0c08dcb2u: goto P_0c08dcb2;
case 0x0c08dcb4u: goto P_0c08dcb4;
case 0x0c08dcb6u: goto P_0c08dcb6;
case 0x0c08dcb8u: goto P_0c08dcb8;
case 0x0c08dcbau: goto P_0c08dcba;
case 0x0c08dcbcu: goto P_0c08dcbc;
case 0x0c08dcbeu: goto P_0c08dcbe;
case 0x0c08dcc0u: goto P_0c08dcc0;
case 0x0c08dcc2u: goto P_0c08dcc2;
case 0x0c08dcc4u: goto P_0c08dcc4;
case 0x0c08dcc6u: goto P_0c08dcc6;
case 0x0c08dcc8u: goto P_0c08dcc8;
case 0x0c08dccau: goto P_0c08dcca;
case 0x0c08dcccu: goto P_0c08dccc;
case 0x0c08dcceu: goto P_0c08dcce;
case 0x0c08dcd0u: goto P_0c08dcd0;
case 0x0c08dcd2u: goto P_0c08dcd2;
case 0x0c08dcd4u: goto P_0c08dcd4;
case 0x0c08dcd6u: goto P_0c08dcd6;
case 0x0c08dcd8u: goto P_0c08dcd8;
case 0x0c08dcdau: goto P_0c08dcda;
case 0x0c08dcdcu: goto P_0c08dcdc;
case 0x0c08dcdeu: goto P_0c08dcde;
case 0x0c08dce0u: goto P_0c08dce0;
case 0x0c08dce2u: goto P_0c08dce2;
case 0x0c08dce4u: goto P_0c08dce4;
case 0x0c08dce6u: goto P_0c08dce6;
case 0x0c08dce8u: goto P_0c08dce8;
case 0x0c08dceau: goto P_0c08dcea;
case 0x0c08dcecu: goto P_0c08dcec;
case 0x0c08dceeu: goto P_0c08dcee;
case 0x0c08dcf0u: goto P_0c08dcf0;
case 0x0c08dcf2u: goto P_0c08dcf2;
case 0x0c08dcf4u: goto P_0c08dcf4;
case 0x0c08dcf6u: goto P_0c08dcf6;
case 0x0c08dcf8u: goto P_0c08dcf8;
case 0x0c08dcfau: goto P_0c08dcfa;
case 0x0c08dcfcu: goto P_0c08dcfc;
case 0x0c08dcfeu: goto P_0c08dcfe;
case 0x0c08dd00u: goto P_0c08dd00;
case 0x0c08dd02u: goto P_0c08dd02;
case 0x0c08dd04u: goto P_0c08dd04;
case 0x0c08dd06u: goto P_0c08dd06;
case 0x0c08dd08u: goto P_0c08dd08;
case 0x0c08dd0au: goto P_0c08dd0a;
case 0x0c08dd0cu: goto P_0c08dd0c;
case 0x0c08dd0eu: goto P_0c08dd0e;
case 0x0c08dd10u: goto P_0c08dd10;
case 0x0c08dd12u: goto P_0c08dd12;
case 0x0c08dd14u: goto P_0c08dd14;
case 0x0c08dd16u: goto P_0c08dd16;
case 0x0c08dd18u: goto P_0c08dd18;
case 0x0c08dd1au: goto P_0c08dd1a;
case 0x0c08dd1cu: goto P_0c08dd1c;
case 0x0c08dd1eu: goto P_0c08dd1e;
case 0x0c08dd20u: goto P_0c08dd20;
case 0x0c08dd22u: goto P_0c08dd22;
case 0x0c08dd24u: goto P_0c08dd24;
case 0x0c08dd26u: goto P_0c08dd26;
case 0x0c08dd28u: goto P_0c08dd28;
case 0x0c08dd2au: goto P_0c08dd2a;
case 0x0c08dd2cu: goto P_0c08dd2c;
case 0x0c08dd2eu: goto P_0c08dd2e;
case 0x0c08dd30u: goto P_0c08dd30;
case 0x0c08dd32u: goto P_0c08dd32;
case 0x0c08dd34u: goto P_0c08dd34;
case 0x0c08dd36u: goto P_0c08dd36;
case 0x0c08dd38u: goto P_0c08dd38;
case 0x0c08dd3au: goto P_0c08dd3a;
case 0x0c08dd3cu: goto P_0c08dd3c;
case 0x0c08dd3eu: goto P_0c08dd3e;
case 0x0c08dd40u: goto P_0c08dd40;
case 0x0c08dd42u: goto P_0c08dd42;
case 0x0c08dd44u: goto P_0c08dd44;
case 0x0c08dd5cu: goto P_0c08dd5c;
case 0x0c08dd5eu: goto P_0c08dd5e;
case 0x0c08dd60u: goto P_0c08dd60;
case 0x0c08dd62u: goto P_0c08dd62;
case 0x0c08dd64u: goto P_0c08dd64;
case 0x0c08dd66u: goto P_0c08dd66;
case 0x0c08dd68u: goto P_0c08dd68;
case 0x0c08dd6au: goto P_0c08dd6a;
case 0x0c08dd6cu: goto P_0c08dd6c;
case 0x0c08dd6eu: goto P_0c08dd6e;
case 0x0c08dd70u: goto P_0c08dd70;
case 0x0c08dd72u: goto P_0c08dd72;
case 0x0c08dd74u: goto P_0c08dd74;
case 0x0c08dd76u: goto P_0c08dd76;
case 0x0c08dd78u: goto P_0c08dd78;
case 0x0c08dd7au: goto P_0c08dd7a;
case 0x0c08dd7cu: goto P_0c08dd7c;
case 0x0c08dd7eu: goto P_0c08dd7e;
case 0x0c08dd80u: goto P_0c08dd80;
case 0x0c08dd82u: goto P_0c08dd82;
case 0x0c08dd84u: goto P_0c08dd84;
case 0x0c08dd86u: goto P_0c08dd86;
case 0x0c08dd88u: goto P_0c08dd88;
case 0x0c08dd8au: goto P_0c08dd8a;
case 0x0c08dd8cu: goto P_0c08dd8c;
case 0x0c08dd8eu: goto P_0c08dd8e;
case 0x0c08dd90u: goto P_0c08dd90;
case 0x0c08dd92u: goto P_0c08dd92;
case 0x0c08dd94u: goto P_0c08dd94;
case 0x0c08dd96u: goto P_0c08dd96;
case 0x0c08dd98u: goto P_0c08dd98;
case 0x0c08dd9au: goto P_0c08dd9a;
case 0x0c08dd9cu: goto P_0c08dd9c;
case 0x0c08dd9eu: goto P_0c08dd9e;
case 0x0c08dda0u: goto P_0c08dda0;
case 0x0c08dda2u: goto P_0c08dda2;
case 0x0c08dda4u: goto P_0c08dda4;
case 0x0c08dda6u: goto P_0c08dda6;
case 0x0c08dda8u: goto P_0c08dda8;
case 0x0c08ddaau: goto P_0c08ddaa;
case 0x0c08ddacu: goto P_0c08ddac;
case 0x0c08ddaeu: goto P_0c08ddae;
case 0x0c08ddb0u: goto P_0c08ddb0;
case 0x0c08ddb2u: goto P_0c08ddb2;
case 0x0c08ddb4u: goto P_0c08ddb4;
case 0x0c08ddb6u: goto P_0c08ddb6;
case 0x0c08ddb8u: goto P_0c08ddb8;
case 0x0c08ddbau: goto P_0c08ddba;
case 0x0c08ddbcu: goto P_0c08ddbc;
case 0x0c08ddbeu: goto P_0c08ddbe;
case 0x0c08ddc0u: goto P_0c08ddc0;
case 0x0c08ddc2u: goto P_0c08ddc2;
case 0x0c08ddc4u: goto P_0c08ddc4;
case 0x0c08ddc6u: goto P_0c08ddc6;
case 0x0c08ddd0u: goto P_0c08ddd0;
case 0x0c08ddd2u: goto P_0c08ddd2;
case 0x0c08ddd4u: goto P_0c08ddd4;
case 0x0c08ddd6u: goto P_0c08ddd6;
case 0x0c08ddd8u: goto P_0c08ddd8;
case 0x0c08dddau: goto P_0c08ddda;
case 0x0c08dddcu: goto P_0c08dddc;
case 0x0c08dddeu: goto P_0c08ddde;
case 0x0c08dde0u: goto P_0c08dde0;
case 0x0c08dde2u: goto P_0c08dde2;
case 0x0c08dde4u: goto P_0c08dde4;
case 0x0c08dde6u: goto P_0c08dde6;
case 0x0c08dde8u: goto P_0c08dde8;
case 0x0c08ddeau: goto P_0c08ddea;
case 0x0c08ddecu: goto P_0c08ddec;
case 0x0c08ddeeu: goto P_0c08ddee;
case 0x0c08ddf0u: goto P_0c08ddf0;
case 0x0c08ddf2u: goto P_0c08ddf2;
case 0x0c08ddf4u: goto P_0c08ddf4;
case 0x0c08ddf6u: goto P_0c08ddf6;
case 0x0c08ddf8u: goto P_0c08ddf8;
case 0x0c08ddfau: goto P_0c08ddfa;
case 0x0c08ddfcu: goto P_0c08ddfc;
case 0x0c08ddfeu: goto P_0c08ddfe;
case 0x0c08de00u: goto P_0c08de00;
case 0x0c08de02u: goto P_0c08de02;
case 0x0c08de04u: goto P_0c08de04;
case 0x0c08de06u: goto P_0c08de06;
case 0x0c08de08u: goto P_0c08de08;
case 0x0c08de0au: goto P_0c08de0a;
case 0x0c08de0cu: goto P_0c08de0c;
case 0x0c08de0eu: goto P_0c08de0e;
case 0x0c08de10u: goto P_0c08de10;
case 0x0c08de12u: goto P_0c08de12;
case 0x0c08de14u: goto P_0c08de14;
case 0x0c08de16u: goto P_0c08de16;
case 0x0c08de18u: goto P_0c08de18;
case 0x0c08de1au: goto P_0c08de1a;
case 0x0c08de1cu: goto P_0c08de1c;
case 0x0c08de1eu: goto P_0c08de1e;
case 0x0c08de20u: goto P_0c08de20;
case 0x0c08de22u: goto P_0c08de22;
case 0x0c08de24u: goto P_0c08de24;
case 0x0c08de26u: goto P_0c08de26;
case 0x0c08de28u: goto P_0c08de28;
case 0x0c08de2au: goto P_0c08de2a;
case 0x0c08de2cu: goto P_0c08de2c;
case 0x0c08de2eu: goto P_0c08de2e;
case 0x0c08de30u: goto P_0c08de30;
case 0x0c08de32u: goto P_0c08de32;
case 0x0c08de34u: goto P_0c08de34;
case 0x0c08de36u: goto P_0c08de36;
case 0x0c08de38u: goto P_0c08de38;
case 0x0c08de3au: goto P_0c08de3a;
case 0x0c08de3cu: goto P_0c08de3c;
case 0x0c08de3eu: goto P_0c08de3e;
case 0x0c08de40u: goto P_0c08de40;
case 0x0c08de42u: goto P_0c08de42;
case 0x0c08de44u: goto P_0c08de44;
case 0x0c08de46u: goto P_0c08de46;
case 0x0c08de48u: goto P_0c08de48;
case 0x0c08de4au: goto P_0c08de4a;
case 0x0c08de4cu: goto P_0c08de4c;
case 0x0c08de4eu: goto P_0c08de4e;
case 0x0c08de50u: goto P_0c08de50;
case 0x0c08de52u: goto P_0c08de52;
case 0x0c08de54u: goto P_0c08de54;
case 0x0c08de56u: goto P_0c08de56;
case 0x0c08de58u: goto P_0c08de58;
case 0x0c08de5au: goto P_0c08de5a;
case 0x0c08de5cu: goto P_0c08de5c;
case 0x0c08de5eu: goto P_0c08de5e;
case 0x0c08de60u: goto P_0c08de60;
case 0x0c08de62u: goto P_0c08de62;
case 0x0c08de64u: goto P_0c08de64;
case 0x0c08de66u: goto P_0c08de66;
case 0x0c08de68u: goto P_0c08de68;
case 0x0c08de6au: goto P_0c08de6a;
case 0x0c08de6cu: goto P_0c08de6c;
case 0x0c08de6eu: goto P_0c08de6e;
case 0x0c08de70u: goto P_0c08de70;
case 0x0c08de72u: goto P_0c08de72;
case 0x0c08de74u: goto P_0c08de74;
case 0x0c08de76u: goto P_0c08de76;
case 0x0c08de78u: goto P_0c08de78;
case 0x0c08de7au: goto P_0c08de7a;
case 0x0c08de7cu: goto P_0c08de7c;
case 0x0c08de7eu: goto P_0c08de7e;
case 0x0c08de80u: goto P_0c08de80;
case 0x0c08de82u: goto P_0c08de82;
case 0x0c08de84u: goto P_0c08de84;
case 0x0c08de86u: goto P_0c08de86;
case 0x0c08de88u: goto P_0c08de88;
case 0x0c08de8au: goto P_0c08de8a;
case 0x0c08de8cu: goto P_0c08de8c;
case 0x0c08de8eu: goto P_0c08de8e;
case 0x0c08de90u: goto P_0c08de90;
case 0x0c08de92u: goto P_0c08de92;
case 0x0c08de94u: goto P_0c08de94;
case 0x0c08de96u: goto P_0c08de96;
case 0x0c08de98u: goto P_0c08de98;
case 0x0c08de9au: goto P_0c08de9a;
case 0x0c08de9cu: goto P_0c08de9c;
case 0x0c08de9eu: goto P_0c08de9e;
case 0x0c08dea0u: goto P_0c08dea0;
case 0x0c08dea2u: goto P_0c08dea2;
case 0x0c08dea4u: goto P_0c08dea4;
case 0x0c08dea6u: goto P_0c08dea6;
case 0x0c08dea8u: goto P_0c08dea8;
case 0x0c08deaau: goto P_0c08deaa;
case 0x0c08deacu: goto P_0c08deac;
case 0x0c08deaeu: goto P_0c08deae;
case 0x0c08deb0u: goto P_0c08deb0;
case 0x0c08deb2u: goto P_0c08deb2;
case 0x0c08deb4u: goto P_0c08deb4;
case 0x0c08deb6u: goto P_0c08deb6;
case 0x0c08deb8u: goto P_0c08deb8;
case 0x0c08debau: goto P_0c08deba;
case 0x0c08debcu: goto P_0c08debc;
case 0x0c08debeu: goto P_0c08debe;
case 0x0c08dec0u: goto P_0c08dec0;
case 0x0c08dec2u: goto P_0c08dec2;
case 0x0c08dec4u: goto P_0c08dec4;
case 0x0c08dec6u: goto P_0c08dec6;
case 0x0c08dec8u: goto P_0c08dec8;
case 0x0c08decau: goto P_0c08deca;
case 0x0c08deccu: goto P_0c08decc;
case 0x0c08deceu: goto P_0c08dece;
case 0x0c08ded0u: goto P_0c08ded0;
case 0x0c08ded2u: goto P_0c08ded2;
case 0x0c08ded4u: goto P_0c08ded4;
case 0x0c08ded6u: goto P_0c08ded6;
case 0x0c08ded8u: goto P_0c08ded8;
case 0x0c08dedau: goto P_0c08deda;
case 0x0c08dedcu: goto P_0c08dedc;
case 0x0c08dedeu: goto P_0c08dede;
case 0x0c08dee0u: goto P_0c08dee0;
case 0x0c08dee2u: goto P_0c08dee2;
case 0x0c08dee4u: goto P_0c08dee4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08dcb0: /* original 2fe6, guest PC 0x0c08dcb0 */
if(!s->budget--) { s->failed_pc=0x0c08dcb0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dcb2;
P_0c08dcb2: /* original 6143, guest PC 0x0c08dcb2 */
if(!s->budget--) { s->failed_pc=0x0c08dcb2u; return 0; }
r[1]=r[4];
goto P_0c08dcb4;
P_0c08dcb4: /* original 2fd6, guest PC 0x0c08dcb4 */
if(!s->budget--) { s->failed_pc=0x0c08dcb4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dcb6;
P_0c08dcb6: /* original 6d43, guest PC 0x0c08dcb6 */
if(!s->budget--) { s->failed_pc=0x0c08dcb6u; return 0; }
r[13]=r[4];
goto P_0c08dcb8;
P_0c08dcb8: /* original 9046, guest PC 0x0c08dcb8 */
if(!s->budget--) { s->failed_pc=0x0c08dcb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd48u,2);
goto P_0c08dcba;
P_0c08dcba: /* original 6453, guest PC 0x0c08dcba */
if(!s->budget--) { s->failed_pc=0x0c08dcbau; return 0; }
r[4]=r[5];
goto P_0c08dcbc;
P_0c08dcbc: /* original 6e53, guest PC 0x0c08dcbc */
if(!s->budget--) { s->failed_pc=0x0c08dcbcu; return 0; }
r[14]=r[5];
goto P_0c08dcbe;
P_0c08dcbe: /* original 9544, guest PC 0x0c08dcbe */
if(!s->budget--) { s->failed_pc=0x0c08dcbeu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd4au,2);
goto P_0c08dcc0;
P_0c08dcc0: /* original 3d03, guest PC 0x0c08dcc0 */
if(!s->budget--) { s->failed_pc=0x0c08dcc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=(int32_t)r[0])!=0);
goto P_0c08dcc2;
P_0c08dcc2: /* original 8901, guest PC 0x0c08dcc2 */
if(!s->budget--) { s->failed_pc=0x0c08dcc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08dcc8; }
goto P_0c08dcc4;
P_0c08dcc4: /* original a003, guest PC 0x0c08dcc4 */
if(!s->budget--) { s->failed_pc=0x0c08dcc4u; return 0; }
r[13]=r[0];
goto P_0c08dcce;
P_0c08dcc6: /* original 6d03, guest PC 0x0c08dcc6 */
if(!s->budget--) { s->failed_pc=0x0c08dcc6u; return 0; }
r[13]=r[0];
goto P_0c08dcc8;
P_0c08dcc8: /* original 3d57, guest PC 0x0c08dcc8 */
if(!s->budget--) { s->failed_pc=0x0c08dcc8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>(int32_t)r[5])!=0);
goto P_0c08dcca;
P_0c08dcca: /* original 8b00, guest PC 0x0c08dcca */
if(!s->budget--) { s->failed_pc=0x0c08dccau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08dcce; }
goto P_0c08dccc;
P_0c08dccc: /* original 6d53, guest PC 0x0c08dccc */
if(!s->budget--) { s->failed_pc=0x0c08dcccu; return 0; }
r[13]=r[5];
goto P_0c08dcce;
P_0c08dcce: /* original 953d, guest PC 0x0c08dcce */
if(!s->budget--) { s->failed_pc=0x0c08dcceu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd4cu,2);
goto P_0c08dcd0;
P_0c08dcd0: /* original 903d, guest PC 0x0c08dcd0 */
if(!s->budget--) { s->failed_pc=0x0c08dcd0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd4eu,2);
goto P_0c08dcd2;
P_0c08dcd2: /* original 3e53, guest PC 0x0c08dcd2 */
if(!s->budget--) { s->failed_pc=0x0c08dcd2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=(int32_t)r[5])!=0);
goto P_0c08dcd4;
P_0c08dcd4: /* original 8901, guest PC 0x0c08dcd4 */
if(!s->budget--) { s->failed_pc=0x0c08dcd4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08dcda; }
goto P_0c08dcd6;
P_0c08dcd6: /* original a003, guest PC 0x0c08dcd6 */
if(!s->budget--) { s->failed_pc=0x0c08dcd6u; return 0; }
r[14]=r[5];
goto P_0c08dce0;
P_0c08dcd8: /* original 6e53, guest PC 0x0c08dcd8 */
if(!s->budget--) { s->failed_pc=0x0c08dcd8u; return 0; }
r[14]=r[5];
goto P_0c08dcda;
P_0c08dcda: /* original 3e07, guest PC 0x0c08dcda */
if(!s->budget--) { s->failed_pc=0x0c08dcdau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[0])!=0);
goto P_0c08dcdc;
P_0c08dcdc: /* original 8b00, guest PC 0x0c08dcdc */
if(!s->budget--) { s->failed_pc=0x0c08dcdcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08dce0; }
goto P_0c08dcde;
P_0c08dcde: /* original 6e03, guest PC 0x0c08dcde */
if(!s->budget--) { s->failed_pc=0x0c08dcdeu; return 0; }
r[14]=r[0];
goto P_0c08dce0;
P_0c08dce0: /* original 9532, guest PC 0x0c08dce0 */
if(!s->budget--) { s->failed_pc=0x0c08dce0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd48u,2);
goto P_0c08dce2;
P_0c08dce2: /* original 9032, guest PC 0x0c08dce2 */
if(!s->budget--) { s->failed_pc=0x0c08dce2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd4au,2);
goto P_0c08dce4;
P_0c08dce4: /* original 3153, guest PC 0x0c08dce4 */
if(!s->budget--) { s->failed_pc=0x0c08dce4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[5])!=0);
goto P_0c08dce6;
P_0c08dce6: /* original 8901, guest PC 0x0c08dce6 */
if(!s->budget--) { s->failed_pc=0x0c08dce6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08dcec; }
goto P_0c08dce8;
P_0c08dce8: /* original a003, guest PC 0x0c08dce8 */
if(!s->budget--) { s->failed_pc=0x0c08dce8u; return 0; }
r[1]=r[5];
goto P_0c08dcf2;
P_0c08dcea: /* original 6153, guest PC 0x0c08dcea */
if(!s->budget--) { s->failed_pc=0x0c08dceau; return 0; }
r[1]=r[5];
goto P_0c08dcec;
P_0c08dcec: /* original 3107, guest PC 0x0c08dcec */
if(!s->budget--) { s->failed_pc=0x0c08dcecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[0])!=0);
goto P_0c08dcee;
P_0c08dcee: /* original 8b00, guest PC 0x0c08dcee */
if(!s->budget--) { s->failed_pc=0x0c08dceeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08dcf2; }
goto P_0c08dcf0;
P_0c08dcf0: /* original 6103, guest PC 0x0c08dcf0 */
if(!s->budget--) { s->failed_pc=0x0c08dcf0u; return 0; }
r[1]=r[0];
goto P_0c08dcf2;
P_0c08dcf2: /* original 952d, guest PC 0x0c08dcf2 */
if(!s->budget--) { s->failed_pc=0x0c08dcf2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd50u,2);
goto P_0c08dcf4;
P_0c08dcf4: /* original 902d, guest PC 0x0c08dcf4 */
if(!s->budget--) { s->failed_pc=0x0c08dcf4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd52u,2);
goto P_0c08dcf6;
P_0c08dcf6: /* original 3453, guest PC 0x0c08dcf6 */
if(!s->budget--) { s->failed_pc=0x0c08dcf6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c08dcf8;
P_0c08dcf8: /* original 8901, guest PC 0x0c08dcf8 */
if(!s->budget--) { s->failed_pc=0x0c08dcf8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08dcfe; }
goto P_0c08dcfa;
P_0c08dcfa: /* original a003, guest PC 0x0c08dcfa */
if(!s->budget--) { s->failed_pc=0x0c08dcfau; return 0; }
r[4]=r[5];
goto P_0c08dd04;
P_0c08dcfc: /* original 6453, guest PC 0x0c08dcfc */
if(!s->budget--) { s->failed_pc=0x0c08dcfcu; return 0; }
r[4]=r[5];
goto P_0c08dcfe;
P_0c08dcfe: /* original 3407, guest PC 0x0c08dcfe */
if(!s->budget--) { s->failed_pc=0x0c08dcfeu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[0])!=0);
goto P_0c08dd00;
P_0c08dd00: /* original 8b00, guest PC 0x0c08dd00 */
if(!s->budget--) { s->failed_pc=0x0c08dd00u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08dd04; }
goto P_0c08dd02;
P_0c08dd02: /* original 6403, guest PC 0x0c08dd02 */
if(!s->budget--) { s->failed_pc=0x0c08dd02u; return 0; }
r[4]=r[0];
goto P_0c08dd04;
P_0c08dd04: /* original 26d2, guest PC 0x0c08dd04 */
if(!s->budget--) { s->failed_pc=0x0c08dd04u; return 0; }
write(ram,r[6],r[13],4);
goto P_0c08dd06;
P_0c08dd06: /* original 27e2, guest PC 0x0c08dd06 */
if(!s->budget--) { s->failed_pc=0x0c08dd06u; return 0; }
write(ram,r[7],r[14],4);
goto P_0c08dd08;
P_0c08dd08: /* original 53f2, guest PC 0x0c08dd08 */
if(!s->budget--) { s->failed_pc=0x0c08dd08u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c08dd0a;
P_0c08dd0a: /* original 2312, guest PC 0x0c08dd0a */
if(!s->budget--) { s->failed_pc=0x0c08dd0au; return 0; }
write(ram,r[3],r[1],4);
goto P_0c08dd0c;
P_0c08dd0c: /* original 53f3, guest PC 0x0c08dd0c */
if(!s->budget--) { s->failed_pc=0x0c08dd0cu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c08dd0e;
P_0c08dd0e: /* original 2342, guest PC 0x0c08dd0e */
if(!s->budget--) { s->failed_pc=0x0c08dd0eu; return 0; }
write(ram,r[3],r[4],4);
goto P_0c08dd10;
P_0c08dd10: /* original 6df6, guest PC 0x0c08dd10 */
if(!s->budget--) { s->failed_pc=0x0c08dd10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dd12;
P_0c08dd12: /* original 000b, guest PC 0x0c08dd12 */
if(!s->budget--) { s->failed_pc=0x0c08dd12u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dd14: /* original 6ef6, guest PC 0x0c08dd14 */
if(!s->budget--) { s->failed_pc=0x0c08dd14u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08dd16;
P_0c08dd16: /* original 2fe6, guest PC 0x0c08dd16 */
if(!s->budget--) { s->failed_pc=0x0c08dd16u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dd18;
P_0c08dd18: /* original 6e43, guest PC 0x0c08dd18 */
if(!s->budget--) { s->failed_pc=0x0c08dd18u; return 0; }
r[14]=r[4];
goto P_0c08dd1a;
P_0c08dd1a: /* original 4f22, guest PC 0x0c08dd1a */
if(!s->budget--) { s->failed_pc=0x0c08dd1au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08dd1c;
P_0c08dd1c: /* original 7ff4, guest PC 0x0c08dd1c */
if(!s->budget--) { s->failed_pc=0x0c08dd1cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08dd1e;
P_0c08dd1e: /* original 2f52, guest PC 0x0c08dd1e */
if(!s->budget--) { s->failed_pc=0x0c08dd1eu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c08dd20;
P_0c08dd20: /* original 1f62, guest PC 0x0c08dd20 */
if(!s->budget--) { s->failed_pc=0x0c08dd20u; return 0; }
write(ram,r[15]+8,r[6],4);
goto P_0c08dd22;
P_0c08dd22: /* original 1f71, guest PC 0x0c08dd22 */
if(!s->budget--) { s->failed_pc=0x0c08dd22u; return 0; }
write(ram,r[15]+4,r[7],4);
goto P_0c08dd24;
P_0c08dd24: /* original 9016, guest PC 0x0c08dd24 */
if(!s->budget--) { s->failed_pc=0x0c08dd24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd54u,2);
goto P_0c08dd26;
P_0c08dd26: /* original 57f5, guest PC 0x0c08dd26 */
if(!s->budget--) { s->failed_pc=0x0c08dd26u; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08dd28;
P_0c08dd28: /* original 04ed, guest PC 0x0c08dd28 */
if(!s->budget--) { s->failed_pc=0x0c08dd28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dd2a;
P_0c08dd2a: /* original 7002, guest PC 0x0c08dd2a */
if(!s->budget--) { s->failed_pc=0x0c08dd2au; return 0; }
r[0]+=0x00000002u;
goto P_0c08dd2c;
P_0c08dd2c: /* original 05ed, guest PC 0x0c08dd2c */
if(!s->budget--) { s->failed_pc=0x0c08dd2cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dd2e;
P_0c08dd2e: /* original b015, guest PC 0x0c08dd2e */
if(!s->budget--) { s->failed_pc=0x0c08dd2eu; return 0; }
target=code_base|0x0c08dd5cu; r[16]=code_base|0x0c08dd32u;
r[6]=read(ram,r[15]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dd32u) { target=s->pc; goto dispatch; }
goto P_0c08dd32;
P_0c08dd30: /* original 56f1, guest PC 0x0c08dd30 */
if(!s->budget--) { s->failed_pc=0x0c08dd30u; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c08dd32;
P_0c08dd32: /* original 9010, guest PC 0x0c08dd32 */
if(!s->budget--) { s->failed_pc=0x0c08dd32u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd56u,2);
goto P_0c08dd34;
P_0c08dd34: /* original 66f2, guest PC 0x0c08dd34 */
if(!s->budget--) { s->failed_pc=0x0c08dd34u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c08dd36;
P_0c08dd36: /* original 57f2, guest PC 0x0c08dd36 */
if(!s->budget--) { s->failed_pc=0x0c08dd36u; return 0; }
r[7]=read(ram,r[15]+8,4);
goto P_0c08dd38;
P_0c08dd38: /* original 7f0c, guest PC 0x0c08dd38 */
if(!s->budget--) { s->failed_pc=0x0c08dd38u; return 0; }
r[15]+=0x0000000cu;
goto P_0c08dd3a;
P_0c08dd3a: /* original 04ed, guest PC 0x0c08dd3a */
if(!s->budget--) { s->failed_pc=0x0c08dd3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dd3c;
P_0c08dd3c: /* original 7002, guest PC 0x0c08dd3c */
if(!s->budget--) { s->failed_pc=0x0c08dd3cu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dd3e;
P_0c08dd3e: /* original 4f26, guest PC 0x0c08dd3e */
if(!s->budget--) { s->failed_pc=0x0c08dd3eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dd40;
P_0c08dd40: /* original 05ed, guest PC 0x0c08dd40 */
if(!s->budget--) { s->failed_pc=0x0c08dd40u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dd42;
P_0c08dd42: /* original a00b, guest PC 0x0c08dd42 */
if(!s->budget--) { s->failed_pc=0x0c08dd42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08dd5c;
P_0c08dd44: /* original 6ef6, guest PC 0x0c08dd44 */
if(!s->budget--) { s->failed_pc=0x0c08dd44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08dd46u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08dd46u; return 0; } return 1;
P_0c08dd5c: /* original 2fe6, guest PC 0x0c08dd5c */
if(!s->budget--) { s->failed_pc=0x0c08dd5cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dd5e;
P_0c08dd5e: /* original c71a, guest PC 0x0c08dd5e */
if(!s->budget--) { s->failed_pc=0x0c08dd5eu; return 0; }
r[0]=code_base|0x0008ddc8u;
goto P_0c08dd60;
P_0c08dd60: /* original 7ff8, guest PC 0x0c08dd60 */
if(!s->budget--) { s->failed_pc=0x0c08dd60u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c08dd62;
P_0c08dd62: /* original 6362, guest PC 0x0c08dd62 */
if(!s->budget--) { s->failed_pc=0x0c08dd62u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c08dd64;
P_0c08dd64: /* original 1f31, guest PC 0x0c08dd64 */
if(!s->budget--) { s->failed_pc=0x0c08dd64u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c08dd66;
P_0c08dd66: /* original 6272, guest PC 0x0c08dd66 */
if(!s->budget--) { s->failed_pc=0x0c08dd66u; return 0; }
tmp=read(ram,r[7],4);
r[2]=tmp;
goto P_0c08dd68;
P_0c08dd68: /* original 6123, guest PC 0x0c08dd68 */
if(!s->budget--) { s->failed_pc=0x0c08dd68u; return 0; }
r[1]=r[2];
goto P_0c08dd6a;
P_0c08dd6a: /* original 3158, guest PC 0x0c08dd6a */
if(!s->budget--) { s->failed_pc=0x0c08dd6au; return 0; }
r[1]-=r[5];
goto P_0c08dd6c;
P_0c08dd6c: /* original 2f22, guest PC 0x0c08dd6c */
if(!s->budget--) { s->failed_pc=0x0c08dd6cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c08dd6e;
P_0c08dd6e: /* original 5ef1, guest PC 0x0c08dd6e */
if(!s->budget--) { s->failed_pc=0x0c08dd6eu; return 0; }
r[14]=read(ram,r[15]+4,4);
goto P_0c08dd70;
P_0c08dd70: /* original 3e48, guest PC 0x0c08dd70 */
if(!s->budget--) { s->failed_pc=0x0c08dd70u; return 0; }
r[14]-=r[4];
goto P_0c08dd72;
P_0c08dd72: /* original 4e5a, guest PC 0x0c08dd72 */
if(!s->budget--) { s->failed_pc=0x0c08dd72u; return 0; }
r[53]=r[14];
goto P_0c08dd74;
P_0c08dd74: /* original f32d, guest PC 0x0c08dd74 */
if(!s->budget--) { s->failed_pc=0x0c08dd74u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c08dd76;
P_0c08dd76: /* original 415a, guest PC 0x0c08dd76 */
if(!s->budget--) { s->failed_pc=0x0c08dd76u; return 0; }
r[53]=r[1];
goto P_0c08dd78;
P_0c08dd78: /* original f22d, guest PC 0x0c08dd78 */
if(!s->budget--) { s->failed_pc=0x0c08dd78u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c08dd7a;
P_0c08dd7a: /* original f43c, guest PC 0x0c08dd7a */
if(!s->budget--) { s->failed_pc=0x0c08dd7au; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c08dd7c;
P_0c08dd7c: /* original f53c, guest PC 0x0c08dd7c */
if(!s->budget--) { s->failed_pc=0x0c08dd7cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08dd7e;
P_0c08dd7e: /* original f452, guest PC 0x0c08dd7e */
if(!s->budget--) { s->failed_pc=0x0c08dd7eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c08dd80;
P_0c08dd80: /* original f308, guest PC 0x0c08dd80 */
if(!s->budget--) { s->failed_pc=0x0c08dd80u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08dd82;
P_0c08dd82: /* original f02c, guest PC 0x0c08dd82 */
if(!s->budget--) { s->failed_pc=0x0c08dd82u; return 0; }
vf3_matrix_move(s,0,2);
goto P_0c08dd84;
P_0c08dd84: /* original f62c, guest PC 0x0c08dd84 */
if(!s->budget--) { s->failed_pc=0x0c08dd84u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c08dd86;
P_0c08dd86: /* original f46e, guest PC 0x0c08dd86 */
if(!s->budget--) { s->failed_pc=0x0c08dd86u; return 0; }
fr[4]=vf3_fpu_mac(fr[0],fr[6],fr[4],r[18]);
goto P_0c08dd88;
P_0c08dd88: /* original f74c, guest PC 0x0c08dd88 */
if(!s->budget--) { s->failed_pc=0x0c08dd88u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c08dd8a;
P_0c08dd8a: /* original f375, guest PC 0x0c08dd8a */
if(!s->budget--) { s->failed_pc=0x0c08dd8au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c08dd8c;
P_0c08dd8c: /* original 8b01, guest PC 0x0c08dd8c */
if(!s->budget--) { s->failed_pc=0x0c08dd8cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08dd92; }
goto P_0c08dd8e;
P_0c08dd8e: /* original a001, guest PC 0x0c08dd8e */
if(!s->budget--) { s->failed_pc=0x0c08dd8eu; return 0; }
fr[7]=0;
goto P_0c08dd94;
P_0c08dd90: /* original f78d, guest PC 0x0c08dd90 */
if(!s->budget--) { s->failed_pc=0x0c08dd90u; return 0; }
fr[7]=0;
goto P_0c08dd92;
P_0c08dd92: /* original f77d, guest PC 0x0c08dd92 */
if(!s->budget--) { s->failed_pc=0x0c08dd92u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c08dd94;
P_0c08dd94: /* original f472, guest PC 0x0c08dd94 */
if(!s->budget--) { s->failed_pc=0x0c08dd94u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c08dd96;
P_0c08dd96: /* original c70d, guest PC 0x0c08dd96 */
if(!s->budget--) { s->failed_pc=0x0c08dd96u; return 0; }
r[0]=code_base|0x0008ddccu;
goto P_0c08dd98;
P_0c08dd98: /* original f708, guest PC 0x0c08dd98 */
if(!s->budget--) { s->failed_pc=0x0c08dd98u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08dd9a;
P_0c08dd9a: /* original f34c, guest PC 0x0c08dd9a */
if(!s->budget--) { s->failed_pc=0x0c08dd9au; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08dd9c;
P_0c08dd9c: /* original f47c, guest PC 0x0c08dd9c */
if(!s->budget--) { s->failed_pc=0x0c08dd9cu; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c08dd9e;
P_0c08dd9e: /* original f433, guest PC 0x0c08dd9e */
if(!s->budget--) { s->failed_pc=0x0c08dd9eu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'/');
goto P_0c08dda0;
P_0c08dda0: /* original f79d, guest PC 0x0c08dda0 */
if(!s->budget--) { s->failed_pc=0x0c08dda0u; return 0; }
fr[7]=0x3f800000u;
goto P_0c08dda2;
P_0c08dda2: /* original f45d, guest PC 0x0c08dda2 */
if(!s->budget--) { s->failed_pc=0x0c08dda2u; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c08dda4;
P_0c08dda4: /* original f745, guest PC 0x0c08dda4 */
if(!s->budget--) { s->failed_pc=0x0c08dda4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c08dda6;
P_0c08dda6: /* original 8b05, guest PC 0x0c08dda6 */
if(!s->budget--) { s->failed_pc=0x0c08dda6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08ddb4; }
goto P_0c08dda8;
P_0c08dda8: /* original f542, guest PC 0x0c08dda8 */
if(!s->budget--) { s->failed_pc=0x0c08dda8u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c08ddaa;
P_0c08ddaa: /* original f642, guest PC 0x0c08ddaa */
if(!s->budget--) { s->failed_pc=0x0c08ddaau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c08ddac;
P_0c08ddac: /* original f53d, guest PC 0x0c08ddac */
if(!s->budget--) { s->failed_pc=0x0c08ddacu; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c08ddae;
P_0c08ddae: /* original 0e5a, guest PC 0x0c08ddae */
if(!s->budget--) { s->failed_pc=0x0c08ddaeu; return 0; }
r[14]=r[53];
goto P_0c08ddb0;
P_0c08ddb0: /* original f63d, guest PC 0x0c08ddb0 */
if(!s->budget--) { s->failed_pc=0x0c08ddb0u; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c08ddb2;
P_0c08ddb2: /* original 015a, guest PC 0x0c08ddb2 */
if(!s->budget--) { s->failed_pc=0x0c08ddb2u; return 0; }
r[1]=r[53];
goto P_0c08ddb4;
P_0c08ddb4: /* original 34ec, guest PC 0x0c08ddb4 */
if(!s->budget--) { s->failed_pc=0x0c08ddb4u; return 0; }
r[4]+=r[14];
goto P_0c08ddb6;
P_0c08ddb6: /* original 2f42, guest PC 0x0c08ddb6 */
if(!s->budget--) { s->failed_pc=0x0c08ddb6u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c08ddb8;
P_0c08ddb8: /* original 6453, guest PC 0x0c08ddb8 */
if(!s->budget--) { s->failed_pc=0x0c08ddb8u; return 0; }
r[4]=r[5];
goto P_0c08ddba;
P_0c08ddba: /* original 63f2, guest PC 0x0c08ddba */
if(!s->budget--) { s->failed_pc=0x0c08ddbau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c08ddbc;
P_0c08ddbc: /* original 341c, guest PC 0x0c08ddbc */
if(!s->budget--) { s->failed_pc=0x0c08ddbcu; return 0; }
r[4]+=r[1];
goto P_0c08ddbe;
P_0c08ddbe: /* original 7f08, guest PC 0x0c08ddbe */
if(!s->budget--) { s->failed_pc=0x0c08ddbeu; return 0; }
r[15]+=0x00000008u;
goto P_0c08ddc0;
P_0c08ddc0: /* original 2632, guest PC 0x0c08ddc0 */
if(!s->budget--) { s->failed_pc=0x0c08ddc0u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c08ddc2;
P_0c08ddc2: /* original 2742, guest PC 0x0c08ddc2 */
if(!s->budget--) { s->failed_pc=0x0c08ddc2u; return 0; }
write(ram,r[7],r[4],4);
goto P_0c08ddc4;
P_0c08ddc4: /* original 000b, guest PC 0x0c08ddc4 */
if(!s->budget--) { s->failed_pc=0x0c08ddc4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08ddc6: /* original 6ef6, guest PC 0x0c08ddc6 */
if(!s->budget--) { s->failed_pc=0x0c08ddc6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08ddc8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08ddc8u; return 0; } return 1;
P_0c08ddd0: /* original 2fe6, guest PC 0x0c08ddd0 */
if(!s->budget--) { s->failed_pc=0x0c08ddd0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ddd2;
P_0c08ddd2: /* original 6e43, guest PC 0x0c08ddd2 */
if(!s->budget--) { s->failed_pc=0x0c08ddd2u; return 0; }
r[14]=r[4];
goto P_0c08ddd4;
P_0c08ddd4: /* original 2fd6, guest PC 0x0c08ddd4 */
if(!s->budget--) { s->failed_pc=0x0c08ddd4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08ddd6;
P_0c08ddd6: /* original fffb, guest PC 0x0c08ddd6 */
if(!s->budget--) { s->failed_pc=0x0c08ddd6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08ddd8;
P_0c08ddd8: /* original ffeb, guest PC 0x0c08ddd8 */
if(!s->budget--) { s->failed_pc=0x0c08ddd8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08ddda;
P_0c08ddda: /* original ffdb, guest PC 0x0c08ddda */
if(!s->budget--) { s->failed_pc=0x0c08dddau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08dddc;
P_0c08dddc: /* original 4f22, guest PC 0x0c08dddc */
if(!s->budget--) { s->failed_pc=0x0c08dddcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08ddde;
P_0c08ddde: /* original 90ab, guest PC 0x0c08ddde */
if(!s->budget--) { s->failed_pc=0x0c08dddeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08df38u,2);
goto P_0c08dde0;
P_0c08dde0: /* original 3f0c, guest PC 0x0c08dde0 */
if(!s->budget--) { s->failed_pc=0x0c08dde0u; return 0; }
r[15]+=r[0];
goto P_0c08dde2;
P_0c08dde2: /* original e060, guest PC 0x0c08dde2 */
if(!s->budget--) { s->failed_pc=0x0c08dde2u; return 0; }
r[0]=0x00000060u;
goto P_0c08dde4;
P_0c08dde4: /* original ff5a, guest PC 0x0c08dde4 */
if(!s->budget--) { s->failed_pc=0x0c08dde4u; return 0; }
vf3_matrix_store(s,ram,5,r[15]);
goto P_0c08dde6;
P_0c08dde6: /* original 1f52, guest PC 0x0c08dde6 */
if(!s->budget--) { s->failed_pc=0x0c08dde6u; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c08dde8;
P_0c08dde8: /* original 1f63, guest PC 0x0c08dde8 */
if(!s->budget--) { s->failed_pc=0x0c08dde8u; return 0; }
write(ram,r[15]+12,r[6],4);
goto P_0c08ddea;
P_0c08ddea: /* original 04ec, guest PC 0x0c08ddea */
if(!s->budget--) { s->failed_pc=0x0c08ddeau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08ddec;
P_0c08ddec: /* original e024, guest PC 0x0c08ddec */
if(!s->budget--) { s->failed_pc=0x0c08ddecu; return 0; }
r[0]=0x00000024u;
goto P_0c08ddee;
P_0c08ddee: /* original d255, guest PC 0x0c08ddee */
if(!s->budget--) { s->failed_pc=0x0c08ddeeu; return 0; }
r[2]=read(ram,0x0c08df44u,4);
goto P_0c08ddf0;
P_0c08ddf0: /* original 644c, guest PC 0x0c08ddf0 */
if(!s->budget--) { s->failed_pc=0x0c08ddf0u; return 0; }
r[4]=r[4]&255u;
goto P_0c08ddf2;
P_0c08ddf2: /* original f38d, guest PC 0x0c08ddf2 */
if(!s->budget--) { s->failed_pc=0x0c08ddf2u; return 0; }
fr[3]=0;
goto P_0c08ddf4;
P_0c08ddf4: /* original 6343, guest PC 0x0c08ddf4 */
if(!s->budget--) { s->failed_pc=0x0c08ddf4u; return 0; }
r[3]=r[4];
goto P_0c08ddf6;
P_0c08ddf6: /* original 4400, guest PC 0x0c08ddf6 */
if(!s->budget--) { s->failed_pc=0x0c08ddf6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08ddf8;
P_0c08ddf8: /* original 343c, guest PC 0x0c08ddf8 */
if(!s->budget--) { s->failed_pc=0x0c08ddf8u; return 0; }
r[4]+=r[3];
goto P_0c08ddfa;
P_0c08ddfa: /* original 4408, guest PC 0x0c08ddfa */
if(!s->budget--) { s->failed_pc=0x0c08ddfau; return 0; }
r[4]<<=2;
goto P_0c08ddfc;
P_0c08ddfc: /* original 644f, guest PC 0x0c08ddfc */
if(!s->budget--) { s->failed_pc=0x0c08ddfcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c08ddfe;
P_0c08ddfe: /* original 342c, guest PC 0x0c08ddfe */
if(!s->budget--) { s->failed_pc=0x0c08ddfeu; return 0; }
r[4]+=r[2];
goto P_0c08de00;
P_0c08de00: /* original ff48, guest PC 0x0c08de00 */
if(!s->budget--) { s->failed_pc=0x0c08de00u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
goto P_0c08de02;
P_0c08de02: /* original ff37, guest PC 0x0c08de02 */
if(!s->budget--) { s->failed_pc=0x0c08de02u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de04;
P_0c08de04: /* original e008, guest PC 0x0c08de04 */
if(!s->budget--) { s->failed_pc=0x0c08de04u; return 0; }
r[0]=0x00000008u;
goto P_0c08de06;
P_0c08de06: /* original f346, guest PC 0x0c08de06 */
if(!s->budget--) { s->failed_pc=0x0c08de06u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c08de08;
P_0c08de08: /* original e004, guest PC 0x0c08de08 */
if(!s->budget--) { s->failed_pc=0x0c08de08u; return 0; }
r[0]=0x00000004u;
goto P_0c08de0a;
P_0c08de0a: /* original ff37, guest PC 0x0c08de0a */
if(!s->budget--) { s->failed_pc=0x0c08de0au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de0c;
P_0c08de0c: /* original e02c, guest PC 0x0c08de0c */
if(!s->budget--) { s->failed_pc=0x0c08de0cu; return 0; }
r[0]=0x0000002cu;
goto P_0c08de0e;
P_0c08de0e: /* original ff47, guest PC 0x0c08de0e */
if(!s->budget--) { s->failed_pc=0x0c08de0eu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08de10;
P_0c08de10: /* original f3f8, guest PC 0x0c08de10 */
if(!s->budget--) { s->failed_pc=0x0c08de10u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08de12;
P_0c08de12: /* original e028, guest PC 0x0c08de12 */
if(!s->budget--) { s->failed_pc=0x0c08de12u; return 0; }
r[0]=0x00000028u;
goto P_0c08de14;
P_0c08de14: /* original ff37, guest PC 0x0c08de14 */
if(!s->budget--) { s->failed_pc=0x0c08de14u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de16;
P_0c08de16: /* original e010, guest PC 0x0c08de16 */
if(!s->budget--) { s->failed_pc=0x0c08de16u; return 0; }
r[0]=0x00000010u;
goto P_0c08de18;
P_0c08de18: /* original ff67, guest PC 0x0c08de18 */
if(!s->budget--) { s->failed_pc=0x0c08de18u; return 0; }
vf3_matrix_store(s,ram,6,r[15]+r[0]);
goto P_0c08de1a;
P_0c08de1a: /* original d34b, guest PC 0x0c08de1a */
if(!s->budget--) { s->failed_pc=0x0c08de1au; return 0; }
r[3]=read(ram,0x0c08df48u,4);
goto P_0c08de1c;
P_0c08de1c: /* original 430b, guest PC 0x0c08de1c */
if(!s->budget--) { s->failed_pc=0x0c08de1cu; return 0; }
target=r[3];
r[16]=code_base|0x0c08de20u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08de20u) { target=s->pc; goto dispatch; }
goto P_0c08de20;
P_0c08de1e: /* original e400, guest PC 0x0c08de1e */
if(!s->budget--) { s->failed_pc=0x0c08de1eu; return 0; }
r[4]=0x00000000u;
goto P_0c08de20;
P_0c08de20: /* original d24a, guest PC 0x0c08de20 */
if(!s->budget--) { s->failed_pc=0x0c08de20u; return 0; }
r[2]=read(ram,0x0c08df4cu,4);
goto P_0c08de22;
P_0c08de22: /* original 420b, guest PC 0x0c08de22 */
if(!s->budget--) { s->failed_pc=0x0c08de22u; return 0; }
target=r[2];
r[16]=code_base|0x0c08de26u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08de26u) { target=s->pc; goto dispatch; }
goto P_0c08de26;
P_0c08de24: /* original 0009, guest PC 0x0c08de24 */
if(!s->budget--) { s->failed_pc=0x0c08de24u; return 0; }
goto P_0c08de26;
P_0c08de26: /* original e02c, guest PC 0x0c08de26 */
if(!s->budget--) { s->failed_pc=0x0c08de26u; return 0; }
r[0]=0x0000002cu;
goto P_0c08de28;
P_0c08de28: /* original 65f3, guest PC 0x0c08de28 */
if(!s->budget--) { s->failed_pc=0x0c08de28u; return 0; }
r[5]=r[15];
goto P_0c08de2a;
P_0c08de2a: /* original f3f6, guest PC 0x0c08de2a */
if(!s->budget--) { s->failed_pc=0x0c08de2au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de2c;
P_0c08de2c: /* original e07c, guest PC 0x0c08de2c */
if(!s->budget--) { s->failed_pc=0x0c08de2cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08de2e;
P_0c08de2e: /* original 64f3, guest PC 0x0c08de2e */
if(!s->budget--) { s->failed_pc=0x0c08de2eu; return 0; }
r[4]=r[15];
goto P_0c08de30;
P_0c08de30: /* original 7570, guest PC 0x0c08de30 */
if(!s->budget--) { s->failed_pc=0x0c08de30u; return 0; }
r[5]+=0x00000070u;
goto P_0c08de32;
P_0c08de32: /* original ff37, guest PC 0x0c08de32 */
if(!s->budget--) { s->failed_pc=0x0c08de32u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de34;
P_0c08de34: /* original e028, guest PC 0x0c08de34 */
if(!s->budget--) { s->failed_pc=0x0c08de34u; return 0; }
r[0]=0x00000028u;
goto P_0c08de36;
P_0c08de36: /* original f3f6, guest PC 0x0c08de36 */
if(!s->budget--) { s->failed_pc=0x0c08de36u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de38;
P_0c08de38: /* original 907f, guest PC 0x0c08de38 */
if(!s->budget--) { s->failed_pc=0x0c08de38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08df3au,2);
goto P_0c08de3a;
P_0c08de3a: /* original ff37, guest PC 0x0c08de3a */
if(!s->budget--) { s->failed_pc=0x0c08de3au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de3c;
P_0c08de3c: /* original e010, guest PC 0x0c08de3c */
if(!s->budget--) { s->failed_pc=0x0c08de3cu; return 0; }
r[0]=0x00000010u;
goto P_0c08de3e;
P_0c08de3e: /* original f3f6, guest PC 0x0c08de3e */
if(!s->budget--) { s->failed_pc=0x0c08de3eu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de40;
P_0c08de40: /* original 907c, guest PC 0x0c08de40 */
if(!s->budget--) { s->failed_pc=0x0c08de40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08df3cu,2);
goto P_0c08de42;
P_0c08de42: /* original ff37, guest PC 0x0c08de42 */
if(!s->budget--) { s->failed_pc=0x0c08de42u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de44;
P_0c08de44: /* original d342, guest PC 0x0c08de44 */
if(!s->budget--) { s->failed_pc=0x0c08de44u; return 0; }
r[3]=read(ram,0x0c08df50u,4);
goto P_0c08de46;
P_0c08de46: /* original 430b, guest PC 0x0c08de46 */
if(!s->budget--) { s->failed_pc=0x0c08de46u; return 0; }
target=r[3];
r[16]=code_base|0x0c08de4au;
r[4]+=0x0000007cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08de4au) { target=s->pc; goto dispatch; }
goto P_0c08de4a;
P_0c08de48: /* original 747c, guest PC 0x0c08de48 */
if(!s->budget--) { s->failed_pc=0x0c08de48u; return 0; }
r[4]+=0x0000007cu;
goto P_0c08de4a;
P_0c08de4a: /* original e070, guest PC 0x0c08de4a */
if(!s->budget--) { s->failed_pc=0x0c08de4au; return 0; }
r[0]=0x00000070u;
goto P_0c08de4c;
P_0c08de4c: /* original fdf6, guest PC 0x0c08de4c */
if(!s->budget--) { s->failed_pc=0x0c08de4cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]+r[0]);
goto P_0c08de4e;
P_0c08de4e: /* original e074, guest PC 0x0c08de4e */
if(!s->budget--) { s->failed_pc=0x0c08de4eu; return 0; }
r[0]=0x00000074u;
goto P_0c08de50;
P_0c08de50: /* original f3f6, guest PC 0x0c08de50 */
if(!s->budget--) { s->failed_pc=0x0c08de50u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de52;
P_0c08de52: /* original e020, guest PC 0x0c08de52 */
if(!s->budget--) { s->failed_pc=0x0c08de52u; return 0; }
r[0]=0x00000020u;
goto P_0c08de54;
P_0c08de54: /* original ff37, guest PC 0x0c08de54 */
if(!s->budget--) { s->failed_pc=0x0c08de54u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de56;
P_0c08de56: /* original e078, guest PC 0x0c08de56 */
if(!s->budget--) { s->failed_pc=0x0c08de56u; return 0; }
r[0]=0x00000078u;
goto P_0c08de58;
P_0c08de58: /* original f3f6, guest PC 0x0c08de58 */
if(!s->budget--) { s->failed_pc=0x0c08de58u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de5a;
P_0c08de5a: /* original e018, guest PC 0x0c08de5a */
if(!s->budget--) { s->failed_pc=0x0c08de5au; return 0; }
r[0]=0x00000018u;
goto P_0c08de5c;
P_0c08de5c: /* original ff37, guest PC 0x0c08de5c */
if(!s->budget--) { s->failed_pc=0x0c08de5cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de5e;
P_0c08de5e: /* original d33d, guest PC 0x0c08de5e */
if(!s->budget--) { s->failed_pc=0x0c08de5eu; return 0; }
r[3]=read(ram,0x0c08df54u,4);
goto P_0c08de60;
P_0c08de60: /* original 430b, guest PC 0x0c08de60 */
if(!s->budget--) { s->failed_pc=0x0c08de60u; return 0; }
target=r[3];
r[16]=code_base|0x0c08de64u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08de64u) { target=s->pc; goto dispatch; }
goto P_0c08de64;
P_0c08de62: /* original e401, guest PC 0x0c08de62 */
if(!s->budget--) { s->failed_pc=0x0c08de62u; return 0; }
r[4]=0x00000001u;
goto P_0c08de64;
P_0c08de64: /* original e018, guest PC 0x0c08de64 */
if(!s->budget--) { s->failed_pc=0x0c08de64u; return 0; }
r[0]=0x00000018u;
goto P_0c08de66;
P_0c08de66: /* original f3f6, guest PC 0x0c08de66 */
if(!s->budget--) { s->failed_pc=0x0c08de66u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de68;
P_0c08de68: /* original e014, guest PC 0x0c08de68 */
if(!s->budget--) { s->failed_pc=0x0c08de68u; return 0; }
r[0]=0x00000014u;
goto P_0c08de6a;
P_0c08de6a: /* original f34d, guest PC 0x0c08de6a */
if(!s->budget--) { s->failed_pc=0x0c08de6au; return 0; }
fr[3]^=0x80000000u;
goto P_0c08de6c;
P_0c08de6c: /* original ff37, guest PC 0x0c08de6c */
if(!s->budget--) { s->failed_pc=0x0c08de6cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08de6e;
P_0c08de6e: /* original e020, guest PC 0x0c08de6e */
if(!s->budget--) { s->failed_pc=0x0c08de6eu; return 0; }
r[0]=0x00000020u;
goto P_0c08de70;
P_0c08de70: /* original f2f6, guest PC 0x0c08de70 */
if(!s->budget--) { s->failed_pc=0x0c08de70u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08de72;
P_0c08de72: /* original e024, guest PC 0x0c08de72 */
if(!s->budget--) { s->failed_pc=0x0c08de72u; return 0; }
r[0]=0x00000024u;
goto P_0c08de74;
P_0c08de74: /* original fef6, guest PC 0x0c08de74 */
if(!s->budget--) { s->failed_pc=0x0c08de74u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c08de76;
P_0c08de76: /* original f5dc, guest PC 0x0c08de76 */
if(!s->budget--) { s->failed_pc=0x0c08de76u; return 0; }
vf3_matrix_move(s,5,13);
goto P_0c08de78;
P_0c08de78: /* original f5f1, guest PC 0x0c08de78 */
if(!s->budget--) { s->failed_pc=0x0c08de78u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'-');
goto P_0c08de7a;
P_0c08de7a: /* original fe21, guest PC 0x0c08de7a */
if(!s->budget--) { s->failed_pc=0x0c08de7au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'-');
goto P_0c08de7c;
P_0c08de7c: /* original dd36, guest PC 0x0c08de7c */
if(!s->budget--) { s->failed_pc=0x0c08de7cu; return 0; }
r[13]=read(ram,0x0c08df58u,4);
goto P_0c08de7e;
P_0c08de7e: /* original 4d0b, guest PC 0x0c08de7e */
if(!s->budget--) { s->failed_pc=0x0c08de7eu; return 0; }
target=r[13];
r[16]=code_base|0x0c08de82u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08de82u) { target=s->pc; goto dispatch; }
goto P_0c08de82;
P_0c08de80: /* original f4ec, guest PC 0x0c08de80 */
if(!s->budget--) { s->failed_pc=0x0c08de80u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c08de82;
P_0c08de82: /* original 600f, guest PC 0x0c08de82 */
if(!s->budget--) { s->failed_pc=0x0c08de82u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08de84;
P_0c08de84: /* original 1f07, guest PC 0x0c08de84 */
if(!s->budget--) { s->failed_pc=0x0c08de84u; return 0; }
write(ram,r[15]+28,r[0],4);
goto P_0c08de86;
P_0c08de86: /* original e004, guest PC 0x0c08de86 */
if(!s->budget--) { s->failed_pc=0x0c08de86u; return 0; }
r[0]=0x00000004u;
goto P_0c08de88;
P_0c08de88: /* original f4fc, guest PC 0x0c08de88 */
if(!s->budget--) { s->failed_pc=0x0c08de88u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08de8a;
P_0c08de8a: /* original f4d1, guest PC 0x0c08de8a */
if(!s->budget--) { s->failed_pc=0x0c08de8au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c08de8c;
P_0c08de8c: /* original f0ec, guest PC 0x0c08de8c */
if(!s->budget--) { s->failed_pc=0x0c08de8cu; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c08de8e;
P_0c08de8e: /* original f34c, guest PC 0x0c08de8e */
if(!s->budget--) { s->failed_pc=0x0c08de8eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c08de90;
P_0c08de90: /* original f342, guest PC 0x0c08de90 */
if(!s->budget--) { s->failed_pc=0x0c08de90u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c08de92;
P_0c08de92: /* original f3ee, guest PC 0x0c08de92 */
if(!s->budget--) { s->failed_pc=0x0c08de92u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[14],fr[3],r[18]);
goto P_0c08de94;
P_0c08de94: /* original f36d, guest PC 0x0c08de94 */
if(!s->budget--) { s->failed_pc=0x0c08de94u; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c08de96;
P_0c08de96: /* original f53c, guest PC 0x0c08de96 */
if(!s->budget--) { s->failed_pc=0x0c08de96u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08de98;
P_0c08de98: /* original ff3c, guest PC 0x0c08de98 */
if(!s->budget--) { s->failed_pc=0x0c08de98u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c08de9a;
P_0c08de9a: /* original f3f6, guest PC 0x0c08de9a */
if(!s->budget--) { s->failed_pc=0x0c08de9au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08de9c;
P_0c08de9c: /* original e014, guest PC 0x0c08de9c */
if(!s->budget--) { s->failed_pc=0x0c08de9cu; return 0; }
r[0]=0x00000014u;
goto P_0c08de9e;
P_0c08de9e: /* original f4f6, guest PC 0x0c08de9e */
if(!s->budget--) { s->failed_pc=0x0c08de9eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08dea0;
P_0c08dea0: /* original 4d0b, guest PC 0x0c08dea0 */
if(!s->budget--) { s->failed_pc=0x0c08dea0u; return 0; }
target=r[13];
r[16]=code_base|0x0c08dea4u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dea4u) { target=s->pc; goto dispatch; }
goto P_0c08dea4;
P_0c08dea2: /* original f431, guest PC 0x0c08dea2 */
if(!s->budget--) { s->failed_pc=0x0c08dea2u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c08dea4;
P_0c08dea4: /* original 904b, guest PC 0x0c08dea4 */
if(!s->budget--) { s->failed_pc=0x0c08dea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08df3eu,2);
goto P_0c08dea6;
P_0c08dea6: /* original f3f8, guest PC 0x0c08dea6 */
if(!s->budget--) { s->failed_pc=0x0c08dea6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c08dea8;
P_0c08dea8: /* original f4e6, guest PC 0x0c08dea8 */
if(!s->budget--) { s->failed_pc=0x0c08dea8u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08deaa;
P_0c08deaa: /* original f5fc, guest PC 0x0c08deaa */
if(!s->budget--) { s->failed_pc=0x0c08deaau; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08deac;
P_0c08deac: /* original 4d0b, guest PC 0x0c08deac */
if(!s->budget--) { s->failed_pc=0x0c08deacu; return 0; }
target=r[13];
r[16]=code_base|0x0c08deb0u;
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08deb0u) { target=s->pc; goto dispatch; }
goto P_0c08deb0;
P_0c08deae: /* original f431, guest PC 0x0c08deae */
if(!s->budget--) { s->failed_pc=0x0c08deaeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c08deb0;
P_0c08deb0: /* original 640f, guest PC 0x0c08deb0 */
if(!s->budget--) { s->failed_pc=0x0c08deb0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08deb2;
P_0c08deb2: /* original 9345, guest PC 0x0c08deb2 */
if(!s->budget--) { s->failed_pc=0x0c08deb2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08df40u,2);
goto P_0c08deb4;
P_0c08deb4: /* original e060, guest PC 0x0c08deb4 */
if(!s->budget--) { s->failed_pc=0x0c08deb4u; return 0; }
r[0]=0x00000060u;
goto P_0c08deb6;
P_0c08deb6: /* original 02ec, guest PC 0x0c08deb6 */
if(!s->budget--) { s->failed_pc=0x0c08deb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08deb8;
P_0c08deb8: /* original 2228, guest PC 0x0c08deb8 */
if(!s->budget--) { s->failed_pc=0x0c08deb8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c08deba;
P_0c08deba: /* original 8f06, guest PC 0x0c08deba */
if(!s->budget--) { s->failed_pc=0x0c08debau; return 0; }
cond=r[17]&1u;
r[4]+=r[3];
if(!cond) { goto P_0c08deca; }
goto P_0c08debe;
P_0c08debc: /* original 343c, guest PC 0x0c08debc */
if(!s->budget--) { s->failed_pc=0x0c08debcu; return 0; }
r[4]+=r[3];
goto P_0c08debe;
P_0c08debe: /* original d328, guest PC 0x0c08debe */
if(!s->budget--) { s->failed_pc=0x0c08debeu; return 0; }
r[3]=read(ram,0x0c08df60u,4);
goto P_0c08dec0;
P_0c08dec0: /* original d226, guest PC 0x0c08dec0 */
if(!s->budget--) { s->failed_pc=0x0c08dec0u; return 0; }
r[2]=read(ram,0x0c08df5cu,4);
goto P_0c08dec2;
P_0c08dec2: /* original 6132, guest PC 0x0c08dec2 */
if(!s->budget--) { s->failed_pc=0x0c08dec2u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c08dec4;
P_0c08dec4: /* original 2128, guest PC 0x0c08dec4 */
if(!s->budget--) { s->failed_pc=0x0c08dec4u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c08dec6;
P_0c08dec6: /* original 8900, guest PC 0x0c08dec6 */
if(!s->budget--) { s->failed_pc=0x0c08dec6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08deca; }
goto P_0c08dec8;
P_0c08dec8: /* original e400, guest PC 0x0c08dec8 */
if(!s->budget--) { s->failed_pc=0x0c08dec8u; return 0; }
r[4]=0x00000000u;
goto P_0c08deca;
P_0c08deca: /* original 52f2, guest PC 0x0c08deca */
if(!s->budget--) { s->failed_pc=0x0c08decau; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c08decc;
P_0c08decc: /* original 2242, guest PC 0x0c08decc */
if(!s->budget--) { s->failed_pc=0x0c08deccu; return 0; }
write(ram,r[2],r[4],4);
goto P_0c08dece;
P_0c08dece: /* original 52f7, guest PC 0x0c08dece */
if(!s->budget--) { s->failed_pc=0x0c08deceu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c08ded0;
P_0c08ded0: /* original 53f3, guest PC 0x0c08ded0 */
if(!s->budget--) { s->failed_pc=0x0c08ded0u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c08ded2;
P_0c08ded2: /* original 2322, guest PC 0x0c08ded2 */
if(!s->budget--) { s->failed_pc=0x0c08ded2u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c08ded4;
P_0c08ded4: /* original 9135, guest PC 0x0c08ded4 */
if(!s->budget--) { s->failed_pc=0x0c08ded4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08df42u,2);
goto P_0c08ded6;
P_0c08ded6: /* original 3f1c, guest PC 0x0c08ded6 */
if(!s->budget--) { s->failed_pc=0x0c08ded6u; return 0; }
r[15]+=r[1];
goto P_0c08ded8;
P_0c08ded8: /* original 4f26, guest PC 0x0c08ded8 */
if(!s->budget--) { s->failed_pc=0x0c08ded8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08deda;
P_0c08deda: /* original fdf9, guest PC 0x0c08deda */
if(!s->budget--) { s->failed_pc=0x0c08dedau; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08dedc;
P_0c08dedc: /* original fef9, guest PC 0x0c08dedc */
if(!s->budget--) { s->failed_pc=0x0c08dedcu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08dede;
P_0c08dede: /* original fff9, guest PC 0x0c08dede */
if(!s->budget--) { s->failed_pc=0x0c08dedeu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08dee0;
P_0c08dee0: /* original 6df6, guest PC 0x0c08dee0 */
if(!s->budget--) { s->failed_pc=0x0c08dee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dee2;
P_0c08dee2: /* original 000b, guest PC 0x0c08dee2 */
if(!s->budget--) { s->failed_pc=0x0c08dee2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dee4: /* original 6ef6, guest PC 0x0c08dee4 */
if(!s->budget--) { s->failed_pc=0x0c08dee4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c08dee6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
