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
int vf3_away_batch134_adapter_7(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09dbc0u: goto P_0c09dbc0;
case 0x0c09dbc2u: goto P_0c09dbc2;
case 0x0c09dbc4u: goto P_0c09dbc4;
case 0x0c09dbc6u: goto P_0c09dbc6;
case 0x0c09dbc8u: goto P_0c09dbc8;
case 0x0c09dbcau: goto P_0c09dbca;
case 0x0c09dbccu: goto P_0c09dbcc;
case 0x0c09dbceu: goto P_0c09dbce;
case 0x0c09dbd0u: goto P_0c09dbd0;
case 0x0c09dbd2u: goto P_0c09dbd2;
case 0x0c09dbd4u: goto P_0c09dbd4;
case 0x0c09dbd6u: goto P_0c09dbd6;
case 0x0c09dbd8u: goto P_0c09dbd8;
case 0x0c09dbdau: goto P_0c09dbda;
case 0x0c09dbdcu: goto P_0c09dbdc;
case 0x0c09dbdeu: goto P_0c09dbde;
case 0x0c09dbe0u: goto P_0c09dbe0;
case 0x0c09dbe2u: goto P_0c09dbe2;
case 0x0c09dbe4u: goto P_0c09dbe4;
case 0x0c09dc34u: goto P_0c09dc34;
case 0x0c09dc36u: goto P_0c09dc36;
case 0x0c09dc38u: goto P_0c09dc38;
case 0x0c09dc3au: goto P_0c09dc3a;
case 0x0c09dc3cu: goto P_0c09dc3c;
case 0x0c09dc3eu: goto P_0c09dc3e;
case 0x0c09dc40u: goto P_0c09dc40;
case 0x0c09dc42u: goto P_0c09dc42;
case 0x0c09dc44u: goto P_0c09dc44;
case 0x0c09dc46u: goto P_0c09dc46;
case 0x0c09dc48u: goto P_0c09dc48;
case 0x0c09dc4au: goto P_0c09dc4a;
case 0x0c09dc4cu: goto P_0c09dc4c;
case 0x0c09dc4eu: goto P_0c09dc4e;
case 0x0c09dc50u: goto P_0c09dc50;
case 0x0c09dc52u: goto P_0c09dc52;
case 0x0c09dc54u: goto P_0c09dc54;
case 0x0c09dc56u: goto P_0c09dc56;
case 0x0c09dc58u: goto P_0c09dc58;
case 0x0c09dc5au: goto P_0c09dc5a;
case 0x0c09dc5cu: goto P_0c09dc5c;
case 0x0c09dc5eu: goto P_0c09dc5e;
case 0x0c09dc60u: goto P_0c09dc60;
case 0x0c09dc62u: goto P_0c09dc62;
case 0x0c09dc64u: goto P_0c09dc64;
case 0x0c09dc66u: goto P_0c09dc66;
case 0x0c09dc68u: goto P_0c09dc68;
case 0x0c09dc6au: goto P_0c09dc6a;
case 0x0c09dc6cu: goto P_0c09dc6c;
case 0x0c09dc6eu: goto P_0c09dc6e;
case 0x0c09dc70u: goto P_0c09dc70;
case 0x0c09dc72u: goto P_0c09dc72;
case 0x0c09dc74u: goto P_0c09dc74;
case 0x0c09dc76u: goto P_0c09dc76;
case 0x0c09dc78u: goto P_0c09dc78;
case 0x0c09dc7au: goto P_0c09dc7a;
case 0x0c09dc7cu: goto P_0c09dc7c;
case 0x0c09dc7eu: goto P_0c09dc7e;
case 0x0c09dc80u: goto P_0c09dc80;
case 0x0c09dc82u: goto P_0c09dc82;
case 0x0c09dc84u: goto P_0c09dc84;
case 0x0c09dc86u: goto P_0c09dc86;
case 0x0c09dc88u: goto P_0c09dc88;
case 0x0c09dc8au: goto P_0c09dc8a;
case 0x0c09dc8cu: goto P_0c09dc8c;
case 0x0c09dc8eu: goto P_0c09dc8e;
case 0x0c09dc90u: goto P_0c09dc90;
case 0x0c09dc92u: goto P_0c09dc92;
case 0x0c09dc94u: goto P_0c09dc94;
case 0x0c09dc96u: goto P_0c09dc96;
case 0x0c09dc98u: goto P_0c09dc98;
case 0x0c09dc9au: goto P_0c09dc9a;
case 0x0c09dc9cu: goto P_0c09dc9c;
case 0x0c09dc9eu: goto P_0c09dc9e;
case 0x0c09dca0u: goto P_0c09dca0;
case 0x0c09dca2u: goto P_0c09dca2;
case 0x0c09dca4u: goto P_0c09dca4;
case 0x0c09dca6u: goto P_0c09dca6;
case 0x0c09dca8u: goto P_0c09dca8;
case 0x0c09dcaau: goto P_0c09dcaa;
case 0x0c09dcacu: goto P_0c09dcac;
case 0x0c09dcaeu: goto P_0c09dcae;
case 0x0c09dcb0u: goto P_0c09dcb0;
case 0x0c09dcb2u: goto P_0c09dcb2;
case 0x0c09dcb4u: goto P_0c09dcb4;
case 0x0c09dcb6u: goto P_0c09dcb6;
case 0x0c09dcb8u: goto P_0c09dcb8;
case 0x0c09dcbau: goto P_0c09dcba;
case 0x0c09dcbcu: goto P_0c09dcbc;
case 0x0c09dcbeu: goto P_0c09dcbe;
case 0x0c09dcc0u: goto P_0c09dcc0;
case 0x0c09dcc2u: goto P_0c09dcc2;
case 0x0c09dcc4u: goto P_0c09dcc4;
case 0x0c09dcc6u: goto P_0c09dcc6;
case 0x0c09dcc8u: goto P_0c09dcc8;
case 0x0c09dccau: goto P_0c09dcca;
case 0x0c09dcccu: goto P_0c09dccc;
case 0x0c09dcceu: goto P_0c09dcce;
case 0x0c09dcd0u: goto P_0c09dcd0;
case 0x0c09dcd2u: goto P_0c09dcd2;
case 0x0c09dcd4u: goto P_0c09dcd4;
case 0x0c09dcd6u: goto P_0c09dcd6;
case 0x0c09dcd8u: goto P_0c09dcd8;
case 0x0c09dcdau: goto P_0c09dcda;
case 0x0c09dcdcu: goto P_0c09dcdc;
case 0x0c09dcdeu: goto P_0c09dcde;
case 0x0c09dce0u: goto P_0c09dce0;
case 0x0c09dce2u: goto P_0c09dce2;
case 0x0c09dce4u: goto P_0c09dce4;
case 0x0c09dce6u: goto P_0c09dce6;
case 0x0c09dce8u: goto P_0c09dce8;
case 0x0c09dceau: goto P_0c09dcea;
case 0x0c09dcecu: goto P_0c09dcec;
case 0x0c09dceeu: goto P_0c09dcee;
case 0x0c09dcf0u: goto P_0c09dcf0;
case 0x0c09dcf2u: goto P_0c09dcf2;
case 0x0c09dcf4u: goto P_0c09dcf4;
case 0x0c09dcf6u: goto P_0c09dcf6;
case 0x0c09dcf8u: goto P_0c09dcf8;
case 0x0c09dcfau: goto P_0c09dcfa;
case 0x0c09dcfcu: goto P_0c09dcfc;
case 0x0c09dcfeu: goto P_0c09dcfe;
case 0x0c09dd00u: goto P_0c09dd00;
case 0x0c09dd02u: goto P_0c09dd02;
case 0x0c09dd04u: goto P_0c09dd04;
case 0x0c09dd06u: goto P_0c09dd06;
case 0x0c09dd08u: goto P_0c09dd08;
case 0x0c09dd0au: goto P_0c09dd0a;
case 0x0c09dd0cu: goto P_0c09dd0c;
case 0x0c09dd0eu: goto P_0c09dd0e;
case 0x0c09dd10u: goto P_0c09dd10;
case 0x0c09dd12u: goto P_0c09dd12;
case 0x0c09dd14u: goto P_0c09dd14;
case 0x0c09dd16u: goto P_0c09dd16;
case 0x0c09dd18u: goto P_0c09dd18;
case 0x0c09dd1au: goto P_0c09dd1a;
case 0x0c09dd1cu: goto P_0c09dd1c;
case 0x0c09dd1eu: goto P_0c09dd1e;
case 0x0c09dd20u: goto P_0c09dd20;
case 0x0c09dd22u: goto P_0c09dd22;
case 0x0c09dd24u: goto P_0c09dd24;
case 0x0c09dd26u: goto P_0c09dd26;
case 0x0c09dd28u: goto P_0c09dd28;
case 0x0c09dd2au: goto P_0c09dd2a;
case 0x0c09dd2cu: goto P_0c09dd2c;
case 0x0c09dd2eu: goto P_0c09dd2e;
case 0x0c09dd30u: goto P_0c09dd30;
case 0x0c09dd32u: goto P_0c09dd32;
case 0x0c09dd34u: goto P_0c09dd34;
case 0x0c09dd36u: goto P_0c09dd36;
case 0x0c09dd38u: goto P_0c09dd38;
case 0x0c09dd3au: goto P_0c09dd3a;
case 0x0c09dd3cu: goto P_0c09dd3c;
case 0x0c09dd3eu: goto P_0c09dd3e;
case 0x0c09dd40u: goto P_0c09dd40;
case 0x0c09dd42u: goto P_0c09dd42;
case 0x0c09dd44u: goto P_0c09dd44;
case 0x0c09dd46u: goto P_0c09dd46;
case 0x0c09dd48u: goto P_0c09dd48;
case 0x0c09dd7cu: goto P_0c09dd7c;
case 0x0c09dd7eu: goto P_0c09dd7e;
case 0x0c09dd80u: goto P_0c09dd80;
case 0x0c09dd82u: goto P_0c09dd82;
case 0x0c09dd84u: goto P_0c09dd84;
case 0x0c09dd86u: goto P_0c09dd86;
case 0x0c09dd88u: goto P_0c09dd88;
case 0x0c09dd8au: goto P_0c09dd8a;
case 0x0c09dd8cu: goto P_0c09dd8c;
case 0x0c09dd8eu: goto P_0c09dd8e;
case 0x0c09dd90u: goto P_0c09dd90;
case 0x0c09dd92u: goto P_0c09dd92;
case 0x0c09dd94u: goto P_0c09dd94;
case 0x0c09dd96u: goto P_0c09dd96;
case 0x0c09dd98u: goto P_0c09dd98;
case 0x0c09dd9au: goto P_0c09dd9a;
case 0x0c09dd9cu: goto P_0c09dd9c;
case 0x0c09dd9eu: goto P_0c09dd9e;
case 0x0c09dda0u: goto P_0c09dda0;
case 0x0c09dda2u: goto P_0c09dda2;
case 0x0c09dda4u: goto P_0c09dda4;
case 0x0c09dda6u: goto P_0c09dda6;
case 0x0c09dda8u: goto P_0c09dda8;
case 0x0c09ddaau: goto P_0c09ddaa;
case 0x0c09ddacu: goto P_0c09ddac;
case 0x0c09ddaeu: goto P_0c09ddae;
case 0x0c09ddb0u: goto P_0c09ddb0;
case 0x0c09ddb2u: goto P_0c09ddb2;
case 0x0c09ddb4u: goto P_0c09ddb4;
case 0x0c09ddb6u: goto P_0c09ddb6;
case 0x0c09ddb8u: goto P_0c09ddb8;
case 0x0c09ddbau: goto P_0c09ddba;
case 0x0c09ddbcu: goto P_0c09ddbc;
case 0x0c09ddbeu: goto P_0c09ddbe;
case 0x0c09ddc0u: goto P_0c09ddc0;
case 0x0c09ddc2u: goto P_0c09ddc2;
case 0x0c09ddc4u: goto P_0c09ddc4;
case 0x0c09ddc6u: goto P_0c09ddc6;
case 0x0c09ddc8u: goto P_0c09ddc8;
case 0x0c09ddcau: goto P_0c09ddca;
case 0x0c09ddccu: goto P_0c09ddcc;
case 0x0c09ddceu: goto P_0c09ddce;
case 0x0c09ddd0u: goto P_0c09ddd0;
case 0x0c09ddd2u: goto P_0c09ddd2;
case 0x0c09ddd4u: goto P_0c09ddd4;
case 0x0c09ddd6u: goto P_0c09ddd6;
case 0x0c09ddd8u: goto P_0c09ddd8;
case 0x0c09dddau: goto P_0c09ddda;
case 0x0c09dddcu: goto P_0c09dddc;
case 0x0c09dddeu: goto P_0c09ddde;
case 0x0c09dde0u: goto P_0c09dde0;
case 0x0c09dde2u: goto P_0c09dde2;
case 0x0c09dde4u: goto P_0c09dde4;
case 0x0c09dde6u: goto P_0c09dde6;
case 0x0c09dde8u: goto P_0c09dde8;
case 0x0c09ddeau: goto P_0c09ddea;
case 0x0c09ddecu: goto P_0c09ddec;
case 0x0c09ddeeu: goto P_0c09ddee;
case 0x0c09ddf0u: goto P_0c09ddf0;
case 0x0c09ddf2u: goto P_0c09ddf2;
case 0x0c09ddf4u: goto P_0c09ddf4;
case 0x0c09ddf6u: goto P_0c09ddf6;
case 0x0c09ddf8u: goto P_0c09ddf8;
case 0x0c09ddfau: goto P_0c09ddfa;
case 0x0c09ddfcu: goto P_0c09ddfc;
case 0x0c09ddfeu: goto P_0c09ddfe;
case 0x0c09de00u: goto P_0c09de00;
case 0x0c09de02u: goto P_0c09de02;
case 0x0c09de04u: goto P_0c09de04;
case 0x0c09de06u: goto P_0c09de06;
case 0x0c09de08u: goto P_0c09de08;
case 0x0c09de0au: goto P_0c09de0a;
case 0x0c09de0cu: goto P_0c09de0c;
case 0x0c09de0eu: goto P_0c09de0e;
case 0x0c09de10u: goto P_0c09de10;
case 0x0c09de12u: goto P_0c09de12;
case 0x0c09de14u: goto P_0c09de14;
case 0x0c09de16u: goto P_0c09de16;
case 0x0c09de18u: goto P_0c09de18;
case 0x0c09de1au: goto P_0c09de1a;
case 0x0c09de1cu: goto P_0c09de1c;
case 0x0c09de1eu: goto P_0c09de1e;
case 0x0c09de20u: goto P_0c09de20;
case 0x0c09de22u: goto P_0c09de22;
case 0x0c09de24u: goto P_0c09de24;
case 0x0c09de26u: goto P_0c09de26;
case 0x0c09de28u: goto P_0c09de28;
case 0x0c09de2au: goto P_0c09de2a;
case 0x0c09de2cu: goto P_0c09de2c;
case 0x0c09de2eu: goto P_0c09de2e;
case 0x0c09de30u: goto P_0c09de30;
case 0x0c09de32u: goto P_0c09de32;
case 0x0c09de34u: goto P_0c09de34;
case 0x0c09de36u: goto P_0c09de36;
case 0x0c09de38u: goto P_0c09de38;
case 0x0c09de3au: goto P_0c09de3a;
case 0x0c09de3cu: goto P_0c09de3c;
case 0x0c09de3eu: goto P_0c09de3e;
case 0x0c09de40u: goto P_0c09de40;
case 0x0c09de42u: goto P_0c09de42;
case 0x0c09de44u: goto P_0c09de44;
case 0x0c09de46u: goto P_0c09de46;
case 0x0c09de48u: goto P_0c09de48;
case 0x0c09de4au: goto P_0c09de4a;
case 0x0c09de4cu: goto P_0c09de4c;
case 0x0c09de4eu: goto P_0c09de4e;
case 0x0c09de50u: goto P_0c09de50;
case 0x0c09de52u: goto P_0c09de52;
case 0x0c09de54u: goto P_0c09de54;
case 0x0c09de56u: goto P_0c09de56;
case 0x0c09de58u: goto P_0c09de58;
case 0x0c09de5au: goto P_0c09de5a;
case 0x0c09de5cu: goto P_0c09de5c;
case 0x0c09de5eu: goto P_0c09de5e;
case 0x0c09de60u: goto P_0c09de60;
case 0x0c09de62u: goto P_0c09de62;
case 0x0c09de64u: goto P_0c09de64;
case 0x0c09de66u: goto P_0c09de66;
case 0x0c09de68u: goto P_0c09de68;
case 0x0c09de6au: goto P_0c09de6a;
case 0x0c09de6cu: goto P_0c09de6c;
case 0x0c09de6eu: goto P_0c09de6e;
case 0x0c09de70u: goto P_0c09de70;
case 0x0c09de72u: goto P_0c09de72;
case 0x0c09de74u: goto P_0c09de74;
case 0x0c09de76u: goto P_0c09de76;
case 0x0c09de78u: goto P_0c09de78;
case 0x0c09de7au: goto P_0c09de7a;
case 0x0c09de7cu: goto P_0c09de7c;
case 0x0c09de7eu: goto P_0c09de7e;
case 0x0c09de80u: goto P_0c09de80;
case 0x0c09de82u: goto P_0c09de82;
case 0x0c09de84u: goto P_0c09de84;
case 0x0c09de86u: goto P_0c09de86;
case 0x0c09de88u: goto P_0c09de88;
case 0x0c09de8au: goto P_0c09de8a;
case 0x0c09de8cu: goto P_0c09de8c;
case 0x0c09de8eu: goto P_0c09de8e;
case 0x0c09de90u: goto P_0c09de90;
case 0x0c09de92u: goto P_0c09de92;
case 0x0c09de94u: goto P_0c09de94;
case 0x0c09de96u: goto P_0c09de96;
case 0x0c09de98u: goto P_0c09de98;
case 0x0c09de9au: goto P_0c09de9a;
case 0x0c09de9cu: goto P_0c09de9c;
case 0x0c09ded4u: goto P_0c09ded4;
case 0x0c09ded6u: goto P_0c09ded6;
case 0x0c09ded8u: goto P_0c09ded8;
case 0x0c09dedau: goto P_0c09deda;
case 0x0c09dedcu: goto P_0c09dedc;
case 0x0c09dedeu: goto P_0c09dede;
case 0x0c09dee0u: goto P_0c09dee0;
case 0x0c09dee2u: goto P_0c09dee2;
case 0x0c09dee4u: goto P_0c09dee4;
case 0x0c09dee6u: goto P_0c09dee6;
case 0x0c09dee8u: goto P_0c09dee8;
case 0x0c09deeau: goto P_0c09deea;
case 0x0c09deecu: goto P_0c09deec;
case 0x0c09deeeu: goto P_0c09deee;
case 0x0c09def0u: goto P_0c09def0;
case 0x0c09def2u: goto P_0c09def2;
case 0x0c09def4u: goto P_0c09def4;
case 0x0c09def6u: goto P_0c09def6;
case 0x0c09def8u: goto P_0c09def8;
case 0x0c09defau: goto P_0c09defa;
case 0x0c09defcu: goto P_0c09defc;
case 0x0c09defeu: goto P_0c09defe;
case 0x0c09df00u: goto P_0c09df00;
case 0x0c09df02u: goto P_0c09df02;
case 0x0c09df04u: goto P_0c09df04;
case 0x0c09df06u: goto P_0c09df06;
case 0x0c09df08u: goto P_0c09df08;
case 0x0c09df0au: goto P_0c09df0a;
case 0x0c09df0cu: goto P_0c09df0c;
case 0x0c09df0eu: goto P_0c09df0e;
case 0x0c09df10u: goto P_0c09df10;
case 0x0c09df12u: goto P_0c09df12;
case 0x0c09df14u: goto P_0c09df14;
case 0x0c09df16u: goto P_0c09df16;
case 0x0c09df18u: goto P_0c09df18;
case 0x0c09df1au: goto P_0c09df1a;
case 0x0c09df1cu: goto P_0c09df1c;
case 0x0c09df1eu: goto P_0c09df1e;
case 0x0c09df20u: goto P_0c09df20;
case 0x0c09df22u: goto P_0c09df22;
case 0x0c09df24u: goto P_0c09df24;
case 0x0c09df26u: goto P_0c09df26;
case 0x0c09df28u: goto P_0c09df28;
case 0x0c09df2au: goto P_0c09df2a;
case 0x0c09df2cu: goto P_0c09df2c;
case 0x0c09df2eu: goto P_0c09df2e;
case 0x0c09df30u: goto P_0c09df30;
case 0x0c09df32u: goto P_0c09df32;
case 0x0c09df34u: goto P_0c09df34;
case 0x0c09df36u: goto P_0c09df36;
case 0x0c09df38u: goto P_0c09df38;
case 0x0c09df3au: goto P_0c09df3a;
case 0x0c09df3cu: goto P_0c09df3c;
case 0x0c09df3eu: goto P_0c09df3e;
case 0x0c09df40u: goto P_0c09df40;
case 0x0c09df42u: goto P_0c09df42;
case 0x0c09df44u: goto P_0c09df44;
case 0x0c09df46u: goto P_0c09df46;
case 0x0c09df48u: goto P_0c09df48;
case 0x0c09df4au: goto P_0c09df4a;
case 0x0c09df4cu: goto P_0c09df4c;
case 0x0c09df4eu: goto P_0c09df4e;
case 0x0c09df50u: goto P_0c09df50;
case 0x0c09df52u: goto P_0c09df52;
case 0x0c09df54u: goto P_0c09df54;
case 0x0c09df56u: goto P_0c09df56;
case 0x0c09df58u: goto P_0c09df58;
case 0x0c09df5au: goto P_0c09df5a;
case 0x0c09df5cu: goto P_0c09df5c;
case 0x0c09df5eu: goto P_0c09df5e;
case 0x0c09df60u: goto P_0c09df60;
case 0x0c09df62u: goto P_0c09df62;
case 0x0c09df64u: goto P_0c09df64;
case 0x0c09df66u: goto P_0c09df66;
case 0x0c09df68u: goto P_0c09df68;
case 0x0c09df6au: goto P_0c09df6a;
case 0x0c09df6cu: goto P_0c09df6c;
case 0x0c09df6eu: goto P_0c09df6e;
case 0x0c09df70u: goto P_0c09df70;
case 0x0c09df94u: goto P_0c09df94;
case 0x0c09df96u: goto P_0c09df96;
case 0x0c09df98u: goto P_0c09df98;
case 0x0c09df9au: goto P_0c09df9a;
case 0x0c09df9cu: goto P_0c09df9c;
case 0x0c09df9eu: goto P_0c09df9e;
case 0x0c09dfa0u: goto P_0c09dfa0;
case 0x0c09dfa2u: goto P_0c09dfa2;
case 0x0c09dfa4u: goto P_0c09dfa4;
case 0x0c09dfa6u: goto P_0c09dfa6;
case 0x0c09dfa8u: goto P_0c09dfa8;
case 0x0c09dfaau: goto P_0c09dfaa;
case 0x0c09dfacu: goto P_0c09dfac;
case 0x0c09dfaeu: goto P_0c09dfae;
case 0x0c09dfb0u: goto P_0c09dfb0;
case 0x0c09dfb2u: goto P_0c09dfb2;
case 0x0c09dfb4u: goto P_0c09dfb4;
case 0x0c09dfb6u: goto P_0c09dfb6;
case 0x0c09dfb8u: goto P_0c09dfb8;
case 0x0c09dfbau: goto P_0c09dfba;
case 0x0c09dfbcu: goto P_0c09dfbc;
case 0x0c09dfbeu: goto P_0c09dfbe;
case 0x0c09dfc0u: goto P_0c09dfc0;
case 0x0c09dfc2u: goto P_0c09dfc2;
case 0x0c09dfc4u: goto P_0c09dfc4;
case 0x0c09dfc6u: goto P_0c09dfc6;
case 0x0c09dfc8u: goto P_0c09dfc8;
case 0x0c09dfcau: goto P_0c09dfca;
case 0x0c09dfccu: goto P_0c09dfcc;
case 0x0c09dfceu: goto P_0c09dfce;
case 0x0c09dfd0u: goto P_0c09dfd0;
case 0x0c09dfd2u: goto P_0c09dfd2;
case 0x0c09dfd4u: goto P_0c09dfd4;
case 0x0c09dfd6u: goto P_0c09dfd6;
case 0x0c09dfd8u: goto P_0c09dfd8;
case 0x0c09dfdau: goto P_0c09dfda;
case 0x0c09dfdcu: goto P_0c09dfdc;
case 0x0c09dfdeu: goto P_0c09dfde;
case 0x0c09dfe0u: goto P_0c09dfe0;
case 0x0c09dfe2u: goto P_0c09dfe2;
case 0x0c09dfe4u: goto P_0c09dfe4;
case 0x0c09dfe6u: goto P_0c09dfe6;
case 0x0c09dfe8u: goto P_0c09dfe8;
case 0x0c09dfeau: goto P_0c09dfea;
case 0x0c09dfecu: goto P_0c09dfec;
case 0x0c09dfeeu: goto P_0c09dfee;
case 0x0c09dff0u: goto P_0c09dff0;
case 0x0c09dff2u: goto P_0c09dff2;
case 0x0c09dff4u: goto P_0c09dff4;
case 0x0c09dff6u: goto P_0c09dff6;
case 0x0c09dff8u: goto P_0c09dff8;
case 0x0c09dffau: goto P_0c09dffa;
case 0x0c09dffcu: goto P_0c09dffc;
case 0x0c09dffeu: goto P_0c09dffe;
case 0x0c09e000u: goto P_0c09e000;
case 0x0c09e002u: goto P_0c09e002;
case 0x0c09e004u: goto P_0c09e004;
case 0x0c09e006u: goto P_0c09e006;
case 0x0c09e008u: goto P_0c09e008;
case 0x0c09e00au: goto P_0c09e00a;
case 0x0c09e00cu: goto P_0c09e00c;
case 0x0c09e00eu: goto P_0c09e00e;
case 0x0c09e010u: goto P_0c09e010;
case 0x0c09e012u: goto P_0c09e012;
case 0x0c09e014u: goto P_0c09e014;
case 0x0c09e016u: goto P_0c09e016;
case 0x0c09e018u: goto P_0c09e018;
case 0x0c09e01au: goto P_0c09e01a;
case 0x0c09e01cu: goto P_0c09e01c;
case 0x0c09e01eu: goto P_0c09e01e;
case 0x0c09e020u: goto P_0c09e020;
case 0x0c09e022u: goto P_0c09e022;
case 0x0c09e024u: goto P_0c09e024;
case 0x0c09e026u: goto P_0c09e026;
case 0x0c09e028u: goto P_0c09e028;
case 0x0c09e02au: goto P_0c09e02a;
case 0x0c09e02cu: goto P_0c09e02c;
case 0x0c09e02eu: goto P_0c09e02e;
case 0x0c09e030u: goto P_0c09e030;
case 0x0c09e032u: goto P_0c09e032;
case 0x0c09e034u: goto P_0c09e034;
case 0x0c09e036u: goto P_0c09e036;
case 0x0c09e038u: goto P_0c09e038;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09dbc0: /* original 4f22, guest PC 0x0c09dbc0 */
if(!s->budget--) { s->failed_pc=0x0c09dbc0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09dbc2;
P_0c09dbc2: /* original 7fb8, guest PC 0x0c09dbc2 */
if(!s->budget--) { s->failed_pc=0x0c09dbc2u; return 0; }
r[15]+=0xffffffb8u;
goto P_0c09dbc4;
P_0c09dbc4: /* original 2f42, guest PC 0x0c09dbc4 */
if(!s->budget--) { s->failed_pc=0x0c09dbc4u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c09dbc6;
P_0c09dbc6: /* original 1f51, guest PC 0x0c09dbc6 */
if(!s->budget--) { s->failed_pc=0x0c09dbc6u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09dbc8;
P_0c09dbc8: /* original d30e, guest PC 0x0c09dbc8 */
if(!s->budget--) { s->failed_pc=0x0c09dbc8u; return 0; }
r[3]=read(ram,0x0c09dc04u,4);
goto P_0c09dbca;
P_0c09dbca: /* original 430b, guest PC 0x0c09dbca */
if(!s->budget--) { s->failed_pc=0x0c09dbcau; return 0; }
target=r[3];
r[16]=code_base|0x0c09dbceu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dbceu) { target=s->pc; goto dispatch; }
goto P_0c09dbce;
P_0c09dbcc: /* original e400, guest PC 0x0c09dbcc */
if(!s->budget--) { s->failed_pc=0x0c09dbccu; return 0; }
r[4]=0x00000000u;
goto P_0c09dbce;
P_0c09dbce: /* original d218, guest PC 0x0c09dbce */
if(!s->budget--) { s->failed_pc=0x0c09dbceu; return 0; }
r[2]=read(ram,0x0c09dc30u,4);
goto P_0c09dbd0;
P_0c09dbd0: /* original 420b, guest PC 0x0c09dbd0 */
if(!s->budget--) { s->failed_pc=0x0c09dbd0u; return 0; }
target=r[2];
r[16]=code_base|0x0c09dbd4u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dbd4u) { target=s->pc; goto dispatch; }
goto P_0c09dbd4;
P_0c09dbd2: /* original 0009, guest PC 0x0c09dbd2 */
if(!s->budget--) { s->failed_pc=0x0c09dbd2u; return 0; }
goto P_0c09dbd4;
P_0c09dbd4: /* original d314, guest PC 0x0c09dbd4 */
if(!s->budget--) { s->failed_pc=0x0c09dbd4u; return 0; }
r[3]=read(ram,0x0c09dc28u,4);
goto P_0c09dbd6;
P_0c09dbd6: /* original 55f1, guest PC 0x0c09dbd6 */
if(!s->budget--) { s->failed_pc=0x0c09dbd6u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c09dbd8;
P_0c09dbd8: /* original 430b, guest PC 0x0c09dbd8 */
if(!s->budget--) { s->failed_pc=0x0c09dbd8u; return 0; }
target=r[3];
r[16]=code_base|0x0c09dbdcu;
tmp=read(ram,r[15],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dbdcu) { target=s->pc; goto dispatch; }
goto P_0c09dbdc;
P_0c09dbda: /* original 64f2, guest PC 0x0c09dbda */
if(!s->budget--) { s->failed_pc=0x0c09dbdau; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c09dbdc;
P_0c09dbdc: /* original d213, guest PC 0x0c09dbdc */
if(!s->budget--) { s->failed_pc=0x0c09dbdcu; return 0; }
r[2]=read(ram,0x0c09dc2cu,4);
goto P_0c09dbde;
P_0c09dbde: /* original 7f48, guest PC 0x0c09dbde */
if(!s->budget--) { s->failed_pc=0x0c09dbdeu; return 0; }
r[15]+=0x00000048u;
goto P_0c09dbe0;
P_0c09dbe0: /* original e401, guest PC 0x0c09dbe0 */
if(!s->budget--) { s->failed_pc=0x0c09dbe0u; return 0; }
r[4]=0x00000001u;
goto P_0c09dbe2;
P_0c09dbe2: /* original 422b, guest PC 0x0c09dbe2 */
if(!s->budget--) { s->failed_pc=0x0c09dbe2u; return 0; }
target=r[2];
r[16]=read(ram,r[15],4); r[15]+=4;
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
P_0c09dbe4: /* original 4f26, guest PC 0x0c09dbe4 */
if(!s->budget--) { s->failed_pc=0x0c09dbe4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c09dbe6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09dbe6u; return 0; } return 1;
P_0c09dc34: /* original fffb, guest PC 0x0c09dc34 */
if(!s->budget--) { s->failed_pc=0x0c09dc34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09dc36;
P_0c09dc36: /* original ffeb, guest PC 0x0c09dc36 */
if(!s->budget--) { s->failed_pc=0x0c09dc36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c09dc38;
P_0c09dc38: /* original ffdb, guest PC 0x0c09dc38 */
if(!s->budget--) { s->failed_pc=0x0c09dc38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c09dc3a;
P_0c09dc3a: /* original ffcb, guest PC 0x0c09dc3a */
if(!s->budget--) { s->failed_pc=0x0c09dc3au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c09dc3c;
P_0c09dc3c: /* original 4f22, guest PC 0x0c09dc3c */
if(!s->budget--) { s->failed_pc=0x0c09dc3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09dc3e;
P_0c09dc3e: /* original 7fec, guest PC 0x0c09dc3e */
if(!s->budget--) { s->failed_pc=0x0c09dc3eu; return 0; }
r[15]+=0xffffffecu;
goto P_0c09dc40;
P_0c09dc40: /* original 1f51, guest PC 0x0c09dc40 */
if(!s->budget--) { s->failed_pc=0x0c09dc40u; return 0; }
write(ram,r[15]+4,r[5],4);
goto P_0c09dc42;
P_0c09dc42: /* original 65f3, guest PC 0x0c09dc42 */
if(!s->budget--) { s->failed_pc=0x0c09dc42u; return 0; }
r[5]=r[15];
goto P_0c09dc44;
P_0c09dc44: /* original 2f62, guest PC 0x0c09dc44 */
if(!s->budget--) { s->failed_pc=0x0c09dc44u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c09dc46;
P_0c09dc46: /* original bfbb, guest PC 0x0c09dc46 */
if(!s->budget--) { s->failed_pc=0x0c09dc46u; return 0; }
target=code_base|0x0c09dbc0u; r[16]=code_base|0x0c09dc4au;
r[5]+=0x00000008u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dc4au) { target=s->pc; goto dispatch; }
goto P_0c09dc4a;
P_0c09dc48: /* original 7508, guest PC 0x0c09dc48 */
if(!s->budget--) { s->failed_pc=0x0c09dc48u; return 0; }
r[5]+=0x00000008u;
goto P_0c09dc4a;
P_0c09dc4a: /* original e008, guest PC 0x0c09dc4a */
if(!s->budget--) { s->failed_pc=0x0c09dc4au; return 0; }
r[0]=0x00000008u;
goto P_0c09dc4c;
P_0c09dc4c: /* original f5f6, guest PC 0x0c09dc4c */
if(!s->budget--) { s->failed_pc=0x0c09dc4cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09dc4e;
P_0c09dc4e: /* original e00c, guest PC 0x0c09dc4e */
if(!s->budget--) { s->failed_pc=0x0c09dc4eu; return 0; }
r[0]=0x0000000cu;
goto P_0c09dc50;
P_0c09dc50: /* original f4f6, guest PC 0x0c09dc50 */
if(!s->budget--) { s->failed_pc=0x0c09dc50u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09dc52;
P_0c09dc52: /* original e010, guest PC 0x0c09dc52 */
if(!s->budget--) { s->failed_pc=0x0c09dc52u; return 0; }
r[0]=0x00000010u;
goto P_0c09dc54;
P_0c09dc54: /* original f05c, guest PC 0x0c09dc54 */
if(!s->budget--) { s->failed_pc=0x0c09dc54u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09dc56;
P_0c09dc56: /* original f34c, guest PC 0x0c09dc56 */
if(!s->budget--) { s->failed_pc=0x0c09dc56u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09dc58;
P_0c09dc58: /* original f342, guest PC 0x0c09dc58 */
if(!s->budget--) { s->failed_pc=0x0c09dc58u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c09dc5a;
P_0c09dc5a: /* original fcf6, guest PC 0x0c09dc5a */
if(!s->budget--) { s->failed_pc=0x0c09dc5au; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c09dc5c;
P_0c09dc5c: /* original c73f, guest PC 0x0c09dc5c */
if(!s->budget--) { s->failed_pc=0x0c09dc5cu; return 0; }
r[0]=code_base|0x0009dd5cu;
goto P_0c09dc5e;
P_0c09dc5e: /* original f208, guest PC 0x0c09dc5e */
if(!s->budget--) { s->failed_pc=0x0c09dc5eu; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c09dc60;
P_0c09dc60: /* original f35e, guest PC 0x0c09dc60 */
if(!s->budget--) { s->failed_pc=0x0c09dc60u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c09dc62;
P_0c09dc62: /* original ff3c, guest PC 0x0c09dc62 */
if(!s->budget--) { s->failed_pc=0x0c09dc62u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c09dc64;
P_0c09dc64: /* original f2f5, guest PC 0x0c09dc64 */
if(!s->budget--) { s->failed_pc=0x0c09dc64u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[15]))!=0);
goto P_0c09dc66;
P_0c09dc66: /* original 8f02, guest PC 0x0c09dc66 */
if(!s->budget--) { s->failed_pc=0x0c09dc66u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,14,15);
if(!cond) { goto P_0c09dc6e; }
goto P_0c09dc6a;
P_0c09dc68: /* original fefc, guest PC 0x0c09dc68 */
if(!s->budget--) { s->failed_pc=0x0c09dc68u; return 0; }
vf3_matrix_move(s,14,15);
goto P_0c09dc6a;
P_0c09dc6a: /* original a002, guest PC 0x0c09dc6a */
if(!s->budget--) { s->failed_pc=0x0c09dc6au; return 0; }
fr[6]=0;
goto P_0c09dc72;
P_0c09dc6c: /* original f68d, guest PC 0x0c09dc6c */
if(!s->budget--) { s->failed_pc=0x0c09dc6cu; return 0; }
fr[6]=0;
goto P_0c09dc6e;
P_0c09dc6e: /* original f6fc, guest PC 0x0c09dc6e */
if(!s->budget--) { s->failed_pc=0x0c09dc6eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c09dc70;
P_0c09dc70: /* original f67d, guest PC 0x0c09dc70 */
if(!s->budget--) { s->failed_pc=0x0c09dc70u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c09dc72;
P_0c09dc72: /* original f0cc, guest PC 0x0c09dc72 */
if(!s->budget--) { s->failed_pc=0x0c09dc72u; return 0; }
vf3_matrix_move(s,0,12);
goto P_0c09dc74;
P_0c09dc74: /* original fece, guest PC 0x0c09dc74 */
if(!s->budget--) { s->failed_pc=0x0c09dc74u; return 0; }
fr[14]=vf3_fpu_mac(fr[0],fr[12],fr[14],r[18]);
goto P_0c09dc76;
P_0c09dc76: /* original c739, guest PC 0x0c09dc76 */
if(!s->budget--) { s->failed_pc=0x0c09dc76u; return 0; }
r[0]=code_base|0x0009dd5cu;
goto P_0c09dc78;
P_0c09dc78: /* original f308, guest PC 0x0c09dc78 */
if(!s->budget--) { s->failed_pc=0x0c09dc78u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09dc7a;
P_0c09dc7a: /* original f3e5, guest PC 0x0c09dc7a */
if(!s->budget--) { s->failed_pc=0x0c09dc7au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c09dc7c;
P_0c09dc7c: /* original 8f02, guest PC 0x0c09dc7c */
if(!s->budget--) { s->failed_pc=0x0c09dc7cu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,4);
if(!cond) { goto P_0c09dc84; }
goto P_0c09dc80;
P_0c09dc7e: /* original f34c, guest PC 0x0c09dc7e */
if(!s->budget--) { s->failed_pc=0x0c09dc7eu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09dc80;
P_0c09dc80: /* original a002, guest PC 0x0c09dc80 */
if(!s->budget--) { s->failed_pc=0x0c09dc80u; return 0; }
fr[13]=0;
goto P_0c09dc88;
P_0c09dc82: /* original fd8d, guest PC 0x0c09dc82 */
if(!s->budget--) { s->failed_pc=0x0c09dc82u; return 0; }
fr[13]=0;
goto P_0c09dc84;
P_0c09dc84: /* original fdec, guest PC 0x0c09dc84 */
if(!s->budget--) { s->failed_pc=0x0c09dc84u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c09dc86;
P_0c09dc86: /* original fd7d, guest PC 0x0c09dc86 */
if(!s->budget--) { s->failed_pc=0x0c09dc86u; return 0; }
if(!vf3_fpu_fsrra(fr[13],r[18],&fr[13])) goto unsupported;
goto P_0c09dc88;
P_0c09dc88: /* original f46c, guest PC 0x0c09dc88 */
if(!s->budget--) { s->failed_pc=0x0c09dc88u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c09dc8a;
P_0c09dc8a: /* original f432, guest PC 0x0c09dc8a */
if(!s->budget--) { s->failed_pc=0x0c09dc8au; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c09dc8c;
P_0c09dc8c: /* original d334, guest PC 0x0c09dc8c */
if(!s->budget--) { s->failed_pc=0x0c09dc8cu; return 0; }
r[3]=read(ram,0x0c09dd60u,4);
goto P_0c09dc8e;
P_0c09dc8e: /* original f35c, guest PC 0x0c09dc8e */
if(!s->budget--) { s->failed_pc=0x0c09dc8eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c09dc90;
P_0c09dc90: /* original f56c, guest PC 0x0c09dc90 */
if(!s->budget--) { s->failed_pc=0x0c09dc90u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c09dc92;
P_0c09dc92: /* original 430b, guest PC 0x0c09dc92 */
if(!s->budget--) { s->failed_pc=0x0c09dc92u; return 0; }
target=r[3];
r[16]=code_base|0x0c09dc96u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dc96u) { target=s->pc; goto dispatch; }
goto P_0c09dc96;
P_0c09dc94: /* original f532, guest PC 0x0c09dc94 */
if(!s->budget--) { s->failed_pc=0x0c09dc94u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c09dc96;
P_0c09dc96: /* original f3dc, guest PC 0x0c09dc96 */
if(!s->budget--) { s->failed_pc=0x0c09dc96u; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c09dc98;
P_0c09dc98: /* original f3c2, guest PC 0x0c09dc98 */
if(!s->budget--) { s->failed_pc=0x0c09dc98u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c09dc9a;
P_0c09dc9a: /* original c730, guest PC 0x0c09dc9a */
if(!s->budget--) { s->failed_pc=0x0c09dc9au; return 0; }
r[0]=code_base|0x0009dd5cu;
goto P_0c09dc9c;
P_0c09dc9c: /* original f43c, guest PC 0x0c09dc9c */
if(!s->budget--) { s->failed_pc=0x0c09dc9cu; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09dc9e;
P_0c09dc9e: /* original f308, guest PC 0x0c09dc9e */
if(!s->budget--) { s->failed_pc=0x0c09dc9eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c09dca0;
P_0c09dca0: /* original f3f5, guest PC 0x0c09dca0 */
if(!s->budget--) { s->failed_pc=0x0c09dca0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c09dca2;
P_0c09dca2: /* original 8f02, guest PC 0x0c09dca2 */
if(!s->budget--) { s->failed_pc=0x0c09dca2u; return 0; }
cond=r[17]&1u;
fr[4]^=0x80000000u;
if(!cond) { goto P_0c09dcaa; }
goto P_0c09dca6;
P_0c09dca4: /* original f44d, guest PC 0x0c09dca4 */
if(!s->budget--) { s->failed_pc=0x0c09dca4u; return 0; }
fr[4]^=0x80000000u;
goto P_0c09dca6;
P_0c09dca6: /* original a002, guest PC 0x0c09dca6 */
if(!s->budget--) { s->failed_pc=0x0c09dca6u; return 0; }
fr[2]=0;
goto P_0c09dcae;
P_0c09dca8: /* original f28d, guest PC 0x0c09dca8 */
if(!s->budget--) { s->failed_pc=0x0c09dca8u; return 0; }
fr[2]=0;
goto P_0c09dcaa;
P_0c09dcaa: /* original f2fc, guest PC 0x0c09dcaa */
if(!s->budget--) { s->failed_pc=0x0c09dcaau; return 0; }
vf3_matrix_move(s,2,15);
goto P_0c09dcac;
P_0c09dcac: /* original f26d, guest PC 0x0c09dcac */
if(!s->budget--) { s->failed_pc=0x0c09dcacu; return 0; }
fr[2]=vf3_fpu_sqrt(fr[2],r[18]);
goto P_0c09dcae;
P_0c09dcae: /* original d32d, guest PC 0x0c09dcae */
if(!s->budget--) { s->failed_pc=0x0c09dcaeu; return 0; }
r[3]=read(ram,0x0c09dd64u,4);
goto P_0c09dcb0;
P_0c09dcb0: /* original f52c, guest PC 0x0c09dcb0 */
if(!s->budget--) { s->failed_pc=0x0c09dcb0u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c09dcb2;
P_0c09dcb2: /* original 430b, guest PC 0x0c09dcb2 */
if(!s->budget--) { s->failed_pc=0x0c09dcb2u; return 0; }
target=r[3];
r[16]=code_base|0x0c09dcb6u;
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'*');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dcb6u) { target=s->pc; goto dispatch; }
goto P_0c09dcb6;
P_0c09dcb4: /* original f5d2, guest PC 0x0c09dcb4 */
if(!s->budget--) { s->failed_pc=0x0c09dcb4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'*');
goto P_0c09dcb6;
P_0c09dcb6: /* original c729, guest PC 0x0c09dcb6 */
if(!s->budget--) { s->failed_pc=0x0c09dcb6u; return 0; }
r[0]=code_base|0x0009dd5cu;
goto P_0c09dcb8;
P_0c09dcb8: /* original 52f1, guest PC 0x0c09dcb8 */
if(!s->budget--) { s->failed_pc=0x0c09dcb8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c09dcba;
P_0c09dcba: /* original f208, guest PC 0x0c09dcba */
if(!s->budget--) { s->failed_pc=0x0c09dcbau; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c09dcbc;
P_0c09dcbc: /* original f2e5, guest PC 0x0c09dcbc */
if(!s->budget--) { s->failed_pc=0x0c09dcbcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[14]))!=0);
goto P_0c09dcbe;
P_0c09dcbe: /* original 8b01, guest PC 0x0c09dcbe */
if(!s->budget--) { s->failed_pc=0x0c09dcbeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dcc4; }
goto P_0c09dcc0;
P_0c09dcc0: /* original a002, guest PC 0x0c09dcc0 */
if(!s->budget--) { s->failed_pc=0x0c09dcc0u; return 0; }
fr[3]=0;
goto P_0c09dcc8;
P_0c09dcc2: /* original f38d, guest PC 0x0c09dcc2 */
if(!s->budget--) { s->failed_pc=0x0c09dcc2u; return 0; }
fr[3]=0;
goto P_0c09dcc4;
P_0c09dcc4: /* original f3ec, guest PC 0x0c09dcc4 */
if(!s->budget--) { s->failed_pc=0x0c09dcc4u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c09dcc6;
P_0c09dcc6: /* original f36d, guest PC 0x0c09dcc6 */
if(!s->budget--) { s->failed_pc=0x0c09dcc6u; return 0; }
fr[3]=vf3_fpu_sqrt(fr[3],r[18]);
goto P_0c09dcc8;
P_0c09dcc8: /* original f23a, guest PC 0x0c09dcc8 */
if(!s->budget--) { s->failed_pc=0x0c09dcc8u; return 0; }
vf3_matrix_store(s,ram,3,r[2]);
goto P_0c09dcca;
P_0c09dcca: /* original 63f2, guest PC 0x0c09dcca */
if(!s->budget--) { s->failed_pc=0x0c09dccau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09dccc;
P_0c09dccc: /* original 7f14, guest PC 0x0c09dccc */
if(!s->budget--) { s->failed_pc=0x0c09dcccu; return 0; }
r[15]+=0x00000014u;
goto P_0c09dcce;
P_0c09dcce: /* original 4f26, guest PC 0x0c09dcce */
if(!s->budget--) { s->failed_pc=0x0c09dcceu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09dcd0;
P_0c09dcd0: /* original f3da, guest PC 0x0c09dcd0 */
if(!s->budget--) { s->failed_pc=0x0c09dcd0u; return 0; }
vf3_matrix_store(s,ram,13,r[3]);
goto P_0c09dcd2;
P_0c09dcd2: /* original fcf9, guest PC 0x0c09dcd2 */
if(!s->budget--) { s->failed_pc=0x0c09dcd2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09dcd4;
P_0c09dcd4: /* original fdf9, guest PC 0x0c09dcd4 */
if(!s->budget--) { s->failed_pc=0x0c09dcd4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09dcd6;
P_0c09dcd6: /* original fef9, guest PC 0x0c09dcd6 */
if(!s->budget--) { s->failed_pc=0x0c09dcd6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09dcd8;
P_0c09dcd8: /* original 000b, guest PC 0x0c09dcd8 */
if(!s->budget--) { s->failed_pc=0x0c09dcd8u; return 0; }
target=r[16];
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
s->pc=target; return ram->oob==0;
P_0c09dcda: /* original fff9, guest PC 0x0c09dcda */
if(!s->budget--) { s->failed_pc=0x0c09dcdau; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09dcdc;
P_0c09dcdc: /* original 2fe6, guest PC 0x0c09dcdc */
if(!s->budget--) { s->failed_pc=0x0c09dcdcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09dcde;
P_0c09dcde: /* original 6e43, guest PC 0x0c09dcde */
if(!s->budget--) { s->failed_pc=0x0c09dcdeu; return 0; }
r[14]=r[4];
goto P_0c09dce0;
P_0c09dce0: /* original 2fd6, guest PC 0x0c09dce0 */
if(!s->budget--) { s->failed_pc=0x0c09dce0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09dce2;
P_0c09dce2: /* original 2fc6, guest PC 0x0c09dce2 */
if(!s->budget--) { s->failed_pc=0x0c09dce2u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09dce4;
P_0c09dce4: /* original 2fb6, guest PC 0x0c09dce4 */
if(!s->budget--) { s->failed_pc=0x0c09dce4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09dce6;
P_0c09dce6: /* original 2fa6, guest PC 0x0c09dce6 */
if(!s->budget--) { s->failed_pc=0x0c09dce6u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09dce8;
P_0c09dce8: /* original fffb, guest PC 0x0c09dce8 */
if(!s->budget--) { s->failed_pc=0x0c09dce8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c09dcea;
P_0c09dcea: /* original 4f22, guest PC 0x0c09dcea */
if(!s->budget--) { s->failed_pc=0x0c09dceau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09dcec;
P_0c09dcec: /* original 902d, guest PC 0x0c09dcec */
if(!s->budget--) { s->failed_pc=0x0c09dcecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd4au,2);
goto P_0c09dcee;
P_0c09dcee: /* original 3f0c, guest PC 0x0c09dcee */
if(!s->budget--) { s->failed_pc=0x0c09dceeu; return 0; }
r[15]+=r[0];
goto P_0c09dcf0;
P_0c09dcf0: /* original 2f52, guest PC 0x0c09dcf0 */
if(!s->budget--) { s->failed_pc=0x0c09dcf0u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c09dcf2;
P_0c09dcf2: /* original 84e4, guest PC 0x0c09dcf2 */
if(!s->budget--) { s->failed_pc=0x0c09dcf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c09dcf4;
P_0c09dcf4: /* original d41c, guest PC 0x0c09dcf4 */
if(!s->budget--) { s->failed_pc=0x0c09dcf4u; return 0; }
r[4]=read(ram,0x0c09dd68u,4);
goto P_0c09dcf6;
P_0c09dcf6: /* original 2008, guest PC 0x0c09dcf6 */
if(!s->budget--) { s->failed_pc=0x0c09dcf6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c09dcf8;
P_0c09dcf8: /* original 8b01, guest PC 0x0c09dcf8 */
if(!s->budget--) { s->failed_pc=0x0c09dcf8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dcfe; }
goto P_0c09dcfa;
P_0c09dcfa: /* original a001, guest PC 0x0c09dcfa */
if(!s->budget--) { s->failed_pc=0x0c09dcfau; return 0; }
r[11]=read(ram,r[4]+20,4);
goto P_0c09dd00;
P_0c09dcfc: /* original 5b45, guest PC 0x0c09dcfc */
if(!s->budget--) { s->failed_pc=0x0c09dcfcu; return 0; }
r[11]=read(ram,r[4]+20,4);
goto P_0c09dcfe;
P_0c09dcfe: /* original 5b44, guest PC 0x0c09dcfe */
if(!s->budget--) { s->failed_pc=0x0c09dcfeu; return 0; }
r[11]=read(ram,r[4]+16,4);
goto P_0c09dd00;
P_0c09dd00: /* original d31a, guest PC 0x0c09dd00 */
if(!s->budget--) { s->failed_pc=0x0c09dd00u; return 0; }
r[3]=read(ram,0x0c09dd6cu,4);
goto P_0c09dd02;
P_0c09dd02: /* original 430b, guest PC 0x0c09dd02 */
if(!s->budget--) { s->failed_pc=0x0c09dd02u; return 0; }
target=r[3];
r[16]=code_base|0x0c09dd06u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dd06u) { target=s->pc; goto dispatch; }
goto P_0c09dd06;
P_0c09dd04: /* original e400, guest PC 0x0c09dd04 */
if(!s->budget--) { s->failed_pc=0x0c09dd04u; return 0; }
r[4]=0x00000000u;
goto P_0c09dd06;
P_0c09dd06: /* original d21a, guest PC 0x0c09dd06 */
if(!s->budget--) { s->failed_pc=0x0c09dd06u; return 0; }
r[2]=read(ram,0x0c09dd70u,4);
goto P_0c09dd08;
P_0c09dd08: /* original 420b, guest PC 0x0c09dd08 */
if(!s->budget--) { s->failed_pc=0x0c09dd08u; return 0; }
target=r[2];
r[16]=code_base|0x0c09dd0cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dd0cu) { target=s->pc; goto dispatch; }
goto P_0c09dd0c;
P_0c09dd0a: /* original 0009, guest PC 0x0c09dd0a */
if(!s->budget--) { s->failed_pc=0x0c09dd0au; return 0; }
goto P_0c09dd0c;
P_0c09dd0c: /* original d319, guest PC 0x0c09dd0c */
if(!s->budget--) { s->failed_pc=0x0c09dd0cu; return 0; }
r[3]=read(ram,0x0c09dd74u,4);
goto P_0c09dd0e;
P_0c09dd0e: /* original 64f3, guest PC 0x0c09dd0e */
if(!s->budget--) { s->failed_pc=0x0c09dd0eu; return 0; }
r[4]=r[15];
goto P_0c09dd10;
P_0c09dd10: /* original 430b, guest PC 0x0c09dd10 */
if(!s->budget--) { s->failed_pc=0x0c09dd10u; return 0; }
target=r[3];
r[16]=code_base|0x0c09dd14u;
r[4]+=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dd14u) { target=s->pc; goto dispatch; }
goto P_0c09dd14;
P_0c09dd12: /* original 7444, guest PC 0x0c09dd12 */
if(!s->budget--) { s->failed_pc=0x0c09dd12u; return 0; }
r[4]+=0x00000044u;
goto P_0c09dd14;
P_0c09dd14: /* original d218, guest PC 0x0c09dd14 */
if(!s->budget--) { s->failed_pc=0x0c09dd14u; return 0; }
r[2]=read(ram,0x0c09dd78u,4);
goto P_0c09dd16;
P_0c09dd16: /* original 420b, guest PC 0x0c09dd16 */
if(!s->budget--) { s->failed_pc=0x0c09dd16u; return 0; }
target=r[2];
r[16]=code_base|0x0c09dd1au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dd1au) { target=s->pc; goto dispatch; }
goto P_0c09dd1a;
P_0c09dd18: /* original e401, guest PC 0x0c09dd18 */
if(!s->budget--) { s->failed_pc=0x0c09dd18u; return 0; }
r[4]=0x00000001u;
goto P_0c09dd1a;
P_0c09dd1a: /* original 9018, guest PC 0x0c09dd1a */
if(!s->budget--) { s->failed_pc=0x0c09dd1au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd4eu,2);
goto P_0c09dd1c;
P_0c09dd1c: /* original 9416, guest PC 0x0c09dd1c */
if(!s->budget--) { s->failed_pc=0x0c09dd1cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd4cu,2);
goto P_0c09dd1e;
P_0c09dd1e: /* original f3e6, guest PC 0x0c09dd1e */
if(!s->budget--) { s->failed_pc=0x0c09dd1eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09dd20;
P_0c09dd20: /* original 34fc, guest PC 0x0c09dd20 */
if(!s->budget--) { s->failed_pc=0x0c09dd20u; return 0; }
r[4]+=r[15];
goto P_0c09dd22;
P_0c09dd22: /* original f43a, guest PC 0x0c09dd22 */
if(!s->budget--) { s->failed_pc=0x0c09dd22u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09dd24;
P_0c09dd24: /* original 9014, guest PC 0x0c09dd24 */
if(!s->budget--) { s->failed_pc=0x0c09dd24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd50u,2);
goto P_0c09dd26;
P_0c09dd26: /* original f3e6, guest PC 0x0c09dd26 */
if(!s->budget--) { s->failed_pc=0x0c09dd26u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09dd28;
P_0c09dd28: /* original e004, guest PC 0x0c09dd28 */
if(!s->budget--) { s->failed_pc=0x0c09dd28u; return 0; }
r[0]=0x00000004u;
goto P_0c09dd2a;
P_0c09dd2a: /* original f437, guest PC 0x0c09dd2a */
if(!s->budget--) { s->failed_pc=0x0c09dd2au; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09dd2c;
P_0c09dd2c: /* original 9011, guest PC 0x0c09dd2c */
if(!s->budget--) { s->failed_pc=0x0c09dd2cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd52u,2);
goto P_0c09dd2e;
P_0c09dd2e: /* original f3e6, guest PC 0x0c09dd2e */
if(!s->budget--) { s->failed_pc=0x0c09dd2eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09dd30;
P_0c09dd30: /* original e008, guest PC 0x0c09dd30 */
if(!s->budget--) { s->failed_pc=0x0c09dd30u; return 0; }
r[0]=0x00000008u;
goto P_0c09dd32;
P_0c09dd32: /* original f437, guest PC 0x0c09dd32 */
if(!s->budget--) { s->failed_pc=0x0c09dd32u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09dd34;
P_0c09dd34: /* original 930e, guest PC 0x0c09dd34 */
if(!s->budget--) { s->failed_pc=0x0c09dd34u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd54u,2);
goto P_0c09dd36;
P_0c09dd36: /* original 6ce2, guest PC 0x0c09dd36 */
if(!s->budget--) { s->failed_pc=0x0c09dd36u; return 0; }
tmp=read(ram,r[14],4);
r[12]=tmp;
goto P_0c09dd38;
P_0c09dd38: /* original 9a0d, guest PC 0x0c09dd38 */
if(!s->budget--) { s->failed_pc=0x0c09dd38u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd56u,2);
goto P_0c09dd3a;
P_0c09dd3a: /* original 2c39, guest PC 0x0c09dd3a */
if(!s->budget--) { s->failed_pc=0x0c09dd3au; return 0; }
r[12]&=r[3];
goto P_0c09dd3c;
P_0c09dd3c: /* original 2cc8, guest PC 0x0c09dd3c */
if(!s->budget--) { s->failed_pc=0x0c09dd3cu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09dd3e;
P_0c09dd3e: /* original 891d, guest PC 0x0c09dd3e */
if(!s->budget--) { s->failed_pc=0x0c09dd3eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09dd7c; }
goto P_0c09dd40;
P_0c09dd40: /* original 61e2, guest PC 0x0c09dd40 */
if(!s->budget--) { s->failed_pc=0x0c09dd40u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c09dd42;
P_0c09dd42: /* original 9209, guest PC 0x0c09dd42 */
if(!s->budget--) { s->failed_pc=0x0c09dd42u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dd58u,2);
goto P_0c09dd44;
P_0c09dd44: /* original 2129, guest PC 0x0c09dd44 */
if(!s->budget--) { s->failed_pc=0x0c09dd44u; return 0; }
r[1]&=r[2];
goto P_0c09dd46;
P_0c09dd46: /* original a05b, guest PC 0x0c09dd46 */
if(!s->budget--) { s->failed_pc=0x0c09dd46u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c09de00;
P_0c09dd48: /* original 2e12, guest PC 0x0c09dd48 */
if(!s->budget--) { s->failed_pc=0x0c09dd48u; return 0; }
write(ram,r[14],r[1],4);
if(!vf3_matrix_family(0x0c09dd4au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09dd4au; return 0; } return 1;
P_0c09dd7c: /* original 62e2, guest PC 0x0c09dd7c */
if(!s->budget--) { s->failed_pc=0x0c09dd7cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c09dd7e;
P_0c09dd7e: /* original 22a8, guest PC 0x0c09dd7e */
if(!s->budget--) { s->failed_pc=0x0c09dd7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[10])==0)!=0);
goto P_0c09dd80;
P_0c09dd80: /* original 8b3e, guest PC 0x0c09dd80 */
if(!s->budget--) { s->failed_pc=0x0c09dd80u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09de00; }
goto P_0c09dd82;
P_0c09dd82: /* original d64f, guest PC 0x0c09dd82 */
if(!s->budget--) { s->failed_pc=0x0c09dd82u; return 0; }
r[6]=read(ram,0x0c09dec0u,4);
goto P_0c09dd84;
P_0c09dd84: /* original e048, guest PC 0x0c09dd84 */
if(!s->budget--) { s->failed_pc=0x0c09dd84u; return 0; }
r[0]=0x00000048u;
goto P_0c09dd86;
P_0c09dd86: /* original 05ee, guest PC 0x0c09dd86 */
if(!s->budget--) { s->failed_pc=0x0c09dd86u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c09dd88;
P_0c09dd88: /* original 6d63, guest PC 0x0c09dd88 */
if(!s->budget--) { s->failed_pc=0x0c09dd88u; return 0; }
r[13]=r[6];
goto P_0c09dd8a;
P_0c09dd8a: /* original 2d59, guest PC 0x0c09dd8a */
if(!s->budget--) { s->failed_pc=0x0c09dd8au; return 0; }
r[13]&=r[5];
goto P_0c09dd8c;
P_0c09dd8c: /* original 2dd8, guest PC 0x0c09dd8c */
if(!s->budget--) { s->failed_pc=0x0c09dd8cu; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c09dd8e;
P_0c09dd8e: /* original 8907, guest PC 0x0c09dd8e */
if(!s->budget--) { s->failed_pc=0x0c09dd8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09dda0; }
goto P_0c09dd90;
P_0c09dd90: /* original 9185, guest PC 0x0c09dd90 */
if(!s->budget--) { s->failed_pc=0x0c09dd90u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09de9eu,2);
goto P_0c09dd92;
P_0c09dd92: /* original e004, guest PC 0x0c09dd92 */
if(!s->budget--) { s->failed_pc=0x0c09dd92u; return 0; }
r[0]=0x00000004u;
goto P_0c09dd94;
P_0c09dd94: /* original f246, guest PC 0x0c09dd94 */
if(!s->budget--) { s->failed_pc=0x0c09dd94u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c09dd96;
P_0c09dd96: /* original 31ec, guest PC 0x0c09dd96 */
if(!s->budget--) { s->failed_pc=0x0c09dd96u; return 0; }
r[1]+=r[14];
goto P_0c09dd98;
P_0c09dd98: /* original f318, guest PC 0x0c09dd98 */
if(!s->budget--) { s->failed_pc=0x0c09dd98u; return 0; }
vf3_matrix_load(s,ram,3,r[1]);
goto P_0c09dd9a;
P_0c09dd9a: /* original f230, guest PC 0x0c09dd9a */
if(!s->budget--) { s->failed_pc=0x0c09dd9au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c09dd9c;
P_0c09dd9c: /* original a030, guest PC 0x0c09dd9c */
if(!s->budget--) { s->failed_pc=0x0c09dd9cu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c09de00;
P_0c09dd9e: /* original f427, guest PC 0x0c09dd9e */
if(!s->budget--) { s->failed_pc=0x0c09dd9eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c09dda0;
P_0c09dda0: /* original 907f, guest PC 0x0c09dda0 */
if(!s->budget--) { s->failed_pc=0x0c09dda0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea2u,2);
goto P_0c09dda2;
P_0c09dda2: /* original 967d, guest PC 0x0c09dda2 */
if(!s->budget--) { s->failed_pc=0x0c09dda2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea0u,2);
goto P_0c09dda4;
P_0c09dda4: /* original f3b6, guest PC 0x0c09dda4 */
if(!s->budget--) { s->failed_pc=0x0c09dda4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c09dda6;
P_0c09dda6: /* original 7004, guest PC 0x0c09dda6 */
if(!s->budget--) { s->failed_pc=0x0c09dda6u; return 0; }
r[0]+=0x00000004u;
goto P_0c09dda8;
P_0c09dda8: /* original 36fc, guest PC 0x0c09dda8 */
if(!s->budget--) { s->failed_pc=0x0c09dda8u; return 0; }
r[6]+=r[15];
goto P_0c09ddaa;
P_0c09ddaa: /* original f63a, guest PC 0x0c09ddaa */
if(!s->budget--) { s->failed_pc=0x0c09ddaau; return 0; }
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c09ddac;
P_0c09ddac: /* original f3b6, guest PC 0x0c09ddac */
if(!s->budget--) { s->failed_pc=0x0c09ddacu; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c09ddae;
P_0c09ddae: /* original e004, guest PC 0x0c09ddae */
if(!s->budget--) { s->failed_pc=0x0c09ddaeu; return 0; }
r[0]=0x00000004u;
goto P_0c09ddb0;
P_0c09ddb0: /* original f637, guest PC 0x0c09ddb0 */
if(!s->budget--) { s->failed_pc=0x0c09ddb0u; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c09ddb2;
P_0c09ddb2: /* original 9077, guest PC 0x0c09ddb2 */
if(!s->budget--) { s->failed_pc=0x0c09ddb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea4u,2);
goto P_0c09ddb4;
P_0c09ddb4: /* original f3b6, guest PC 0x0c09ddb4 */
if(!s->budget--) { s->failed_pc=0x0c09ddb4u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c09ddb6;
P_0c09ddb6: /* original e008, guest PC 0x0c09ddb6 */
if(!s->budget--) { s->failed_pc=0x0c09ddb6u; return 0; }
r[0]=0x00000008u;
goto P_0c09ddb8;
P_0c09ddb8: /* original f637, guest PC 0x0c09ddb8 */
if(!s->budget--) { s->failed_pc=0x0c09ddb8u; return 0; }
vf3_matrix_store(s,ram,3,r[6]+r[0]);
goto P_0c09ddba;
P_0c09ddba: /* original 9075, guest PC 0x0c09ddba */
if(!s->budget--) { s->failed_pc=0x0c09ddbau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea8u,2);
goto P_0c09ddbc;
P_0c09ddbc: /* original 9573, guest PC 0x0c09ddbc */
if(!s->budget--) { s->failed_pc=0x0c09ddbcu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea6u,2);
goto P_0c09ddbe;
P_0c09ddbe: /* original f3e6, guest PC 0x0c09ddbe */
if(!s->budget--) { s->failed_pc=0x0c09ddbeu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09ddc0;
P_0c09ddc0: /* original 7004, guest PC 0x0c09ddc0 */
if(!s->budget--) { s->failed_pc=0x0c09ddc0u; return 0; }
r[0]+=0x00000004u;
goto P_0c09ddc2;
P_0c09ddc2: /* original 35fc, guest PC 0x0c09ddc2 */
if(!s->budget--) { s->failed_pc=0x0c09ddc2u; return 0; }
r[5]+=r[15];
goto P_0c09ddc4;
P_0c09ddc4: /* original f53a, guest PC 0x0c09ddc4 */
if(!s->budget--) { s->failed_pc=0x0c09ddc4u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c09ddc6;
P_0c09ddc6: /* original f3e6, guest PC 0x0c09ddc6 */
if(!s->budget--) { s->failed_pc=0x0c09ddc6u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09ddc8;
P_0c09ddc8: /* original e004, guest PC 0x0c09ddc8 */
if(!s->budget--) { s->failed_pc=0x0c09ddc8u; return 0; }
r[0]=0x00000004u;
goto P_0c09ddca;
P_0c09ddca: /* original f537, guest PC 0x0c09ddca */
if(!s->budget--) { s->failed_pc=0x0c09ddcau; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c09ddcc;
P_0c09ddcc: /* original 906d, guest PC 0x0c09ddcc */
if(!s->budget--) { s->failed_pc=0x0c09ddccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deaau,2);
goto P_0c09ddce;
P_0c09ddce: /* original f3e6, guest PC 0x0c09ddce */
if(!s->budget--) { s->failed_pc=0x0c09ddceu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09ddd0;
P_0c09ddd0: /* original e008, guest PC 0x0c09ddd0 */
if(!s->budget--) { s->failed_pc=0x0c09ddd0u; return 0; }
r[0]=0x00000008u;
goto P_0c09ddd2;
P_0c09ddd2: /* original f537, guest PC 0x0c09ddd2 */
if(!s->budget--) { s->failed_pc=0x0c09ddd2u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c09ddd4;
P_0c09ddd4: /* original c73b, guest PC 0x0c09ddd4 */
if(!s->budget--) { s->failed_pc=0x0c09ddd4u; return 0; }
r[0]=code_base|0x0009dec4u;
goto P_0c09ddd6;
P_0c09ddd6: /* original f508, guest PC 0x0c09ddd6 */
if(!s->budget--) { s->failed_pc=0x0c09ddd6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c09ddd8;
P_0c09ddd8: /* original c73b, guest PC 0x0c09ddd8 */
if(!s->budget--) { s->failed_pc=0x0c09ddd8u; return 0; }
r[0]=code_base|0x0009dec8u;
goto P_0c09ddda;
P_0c09ddda: /* original f408, guest PC 0x0c09ddda */
if(!s->budget--) { s->failed_pc=0x0c09dddau; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c09dddc;
P_0c09dddc: /* original f368, guest PC 0x0c09dddc */
if(!s->budget--) { s->failed_pc=0x0c09dddcu; return 0; }
vf3_matrix_load(s,ram,3,r[6]);
goto P_0c09ddde;
P_0c09ddde: /* original f04c, guest PC 0x0c09ddde */
if(!s->budget--) { s->failed_pc=0x0c09dddeu; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c09dde0;
P_0c09dde0: /* original f258, guest PC 0x0c09dde0 */
if(!s->budget--) { s->failed_pc=0x0c09dde0u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
goto P_0c09dde2;
P_0c09dde2: /* original e004, guest PC 0x0c09dde2 */
if(!s->budget--) { s->failed_pc=0x0c09dde2u; return 0; }
r[0]=0x00000004u;
goto P_0c09dde4;
P_0c09dde4: /* original f32e, guest PC 0x0c09dde4 */
if(!s->budget--) { s->failed_pc=0x0c09dde4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09dde6;
P_0c09dde6: /* original f352, guest PC 0x0c09dde6 */
if(!s->budget--) { s->failed_pc=0x0c09dde6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c09dde8;
P_0c09dde8: /* original f43a, guest PC 0x0c09dde8 */
if(!s->budget--) { s->failed_pc=0x0c09dde8u; return 0; }
vf3_matrix_store(s,ram,3,r[4]);
goto P_0c09ddea;
P_0c09ddea: /* original f256, guest PC 0x0c09ddea */
if(!s->budget--) { s->failed_pc=0x0c09ddeau; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c09ddec;
P_0c09ddec: /* original f366, guest PC 0x0c09ddec */
if(!s->budget--) { s->failed_pc=0x0c09ddecu; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c09ddee;
P_0c09ddee: /* original f32e, guest PC 0x0c09ddee */
if(!s->budget--) { s->failed_pc=0x0c09ddeeu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09ddf0;
P_0c09ddf0: /* original f352, guest PC 0x0c09ddf0 */
if(!s->budget--) { s->failed_pc=0x0c09ddf0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c09ddf2;
P_0c09ddf2: /* original f437, guest PC 0x0c09ddf2 */
if(!s->budget--) { s->failed_pc=0x0c09ddf2u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09ddf4;
P_0c09ddf4: /* original e008, guest PC 0x0c09ddf4 */
if(!s->budget--) { s->failed_pc=0x0c09ddf4u; return 0; }
r[0]=0x00000008u;
goto P_0c09ddf6;
P_0c09ddf6: /* original f256, guest PC 0x0c09ddf6 */
if(!s->budget--) { s->failed_pc=0x0c09ddf6u; return 0; }
vf3_matrix_load(s,ram,2,r[5]+r[0]);
goto P_0c09ddf8;
P_0c09ddf8: /* original f366, guest PC 0x0c09ddf8 */
if(!s->budget--) { s->failed_pc=0x0c09ddf8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c09ddfa;
P_0c09ddfa: /* original f32e, guest PC 0x0c09ddfa */
if(!s->budget--) { s->failed_pc=0x0c09ddfau; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09ddfc;
P_0c09ddfc: /* original f352, guest PC 0x0c09ddfc */
if(!s->budget--) { s->failed_pc=0x0c09ddfcu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[5],r[18],'*');
goto P_0c09ddfe;
P_0c09ddfe: /* original f437, guest PC 0x0c09ddfe */
if(!s->budget--) { s->failed_pc=0x0c09ddfeu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c09de00;
P_0c09de00: /* original 9052, guest PC 0x0c09de00 */
if(!s->budget--) { s->failed_pc=0x0c09de00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea8u,2);
goto P_0c09de02;
P_0c09de02: /* original f348, guest PC 0x0c09de02 */
if(!s->budget--) { s->failed_pc=0x0c09de02u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c09de04;
P_0c09de04: /* original fe37, guest PC 0x0c09de04 */
if(!s->budget--) { s->failed_pc=0x0c09de04u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09de06;
P_0c09de06: /* original e004, guest PC 0x0c09de06 */
if(!s->budget--) { s->failed_pc=0x0c09de06u; return 0; }
r[0]=0x00000004u;
goto P_0c09de08;
P_0c09de08: /* original f346, guest PC 0x0c09de08 */
if(!s->budget--) { s->failed_pc=0x0c09de08u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09de0a;
P_0c09de0a: /* original 904f, guest PC 0x0c09de0a */
if(!s->budget--) { s->failed_pc=0x0c09de0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deacu,2);
goto P_0c09de0c;
P_0c09de0c: /* original fe37, guest PC 0x0c09de0c */
if(!s->budget--) { s->failed_pc=0x0c09de0cu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09de0e;
P_0c09de0e: /* original e008, guest PC 0x0c09de0e */
if(!s->budget--) { s->failed_pc=0x0c09de0eu; return 0; }
r[0]=0x00000008u;
goto P_0c09de10;
P_0c09de10: /* original f346, guest PC 0x0c09de10 */
if(!s->budget--) { s->failed_pc=0x0c09de10u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c09de12;
P_0c09de12: /* original 64f3, guest PC 0x0c09de12 */
if(!s->budget--) { s->failed_pc=0x0c09de12u; return 0; }
r[4]=r[15];
goto P_0c09de14;
P_0c09de14: /* original 9049, guest PC 0x0c09de14 */
if(!s->budget--) { s->failed_pc=0x0c09de14u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deaau,2);
goto P_0c09de16;
P_0c09de16: /* original fe37, guest PC 0x0c09de16 */
if(!s->budget--) { s->failed_pc=0x0c09de16u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c09de18;
P_0c09de18: /* original 9049, guest PC 0x0c09de18 */
if(!s->budget--) { s->failed_pc=0x0c09de18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deaeu,2);
goto P_0c09de1a;
P_0c09de1a: /* original d32c, guest PC 0x0c09de1a */
if(!s->budget--) { s->failed_pc=0x0c09de1au; return 0; }
r[3]=read(ram,0x0c09deccu,4);
goto P_0c09de1c;
P_0c09de1c: /* original ffe6, guest PC 0x0c09de1c */
if(!s->budget--) { s->failed_pc=0x0c09de1cu; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c09de1e;
P_0c09de1e: /* original 430b, guest PC 0x0c09de1e */
if(!s->budget--) { s->failed_pc=0x0c09de1eu; return 0; }
target=r[3];
r[16]=code_base|0x0c09de22u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09de22u) { target=s->pc; goto dispatch; }
goto P_0c09de22;
P_0c09de20: /* original 7404, guest PC 0x0c09de20 */
if(!s->budget--) { s->failed_pc=0x0c09de20u; return 0; }
r[4]+=0x00000004u;
goto P_0c09de22;
P_0c09de22: /* original e034, guest PC 0x0c09de22 */
if(!s->budget--) { s->failed_pc=0x0c09de22u; return 0; }
r[0]=0x00000034u;
goto P_0c09de24;
P_0c09de24: /* original f0fc, guest PC 0x0c09de24 */
if(!s->budget--) { s->failed_pc=0x0c09de24u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c09de26;
P_0c09de26: /* original f3f6, guest PC 0x0c09de26 */
if(!s->budget--) { s->failed_pc=0x0c09de26u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09de28;
P_0c09de28: /* original e004, guest PC 0x0c09de28 */
if(!s->budget--) { s->failed_pc=0x0c09de28u; return 0; }
r[0]=0x00000004u;
goto P_0c09de2a;
P_0c09de2a: /* original f2f6, guest PC 0x0c09de2a */
if(!s->budget--) { s->failed_pc=0x0c09de2au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09de2c;
P_0c09de2c: /* original e074, guest PC 0x0c09de2c */
if(!s->budget--) { s->failed_pc=0x0c09de2cu; return 0; }
r[0]=0x00000074u;
goto P_0c09de2e;
P_0c09de2e: /* original f32e, guest PC 0x0c09de2e */
if(!s->budget--) { s->failed_pc=0x0c09de2eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09de30;
P_0c09de30: /* original ff37, guest PC 0x0c09de30 */
if(!s->budget--) { s->failed_pc=0x0c09de30u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09de32;
P_0c09de32: /* original e038, guest PC 0x0c09de32 */
if(!s->budget--) { s->failed_pc=0x0c09de32u; return 0; }
r[0]=0x00000038u;
goto P_0c09de34;
P_0c09de34: /* original f3f6, guest PC 0x0c09de34 */
if(!s->budget--) { s->failed_pc=0x0c09de34u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09de36;
P_0c09de36: /* original e008, guest PC 0x0c09de36 */
if(!s->budget--) { s->failed_pc=0x0c09de36u; return 0; }
r[0]=0x00000008u;
goto P_0c09de38;
P_0c09de38: /* original f2f6, guest PC 0x0c09de38 */
if(!s->budget--) { s->failed_pc=0x0c09de38u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09de3a;
P_0c09de3a: /* original e078, guest PC 0x0c09de3a */
if(!s->budget--) { s->failed_pc=0x0c09de3au; return 0; }
r[0]=0x00000078u;
goto P_0c09de3c;
P_0c09de3c: /* original f32e, guest PC 0x0c09de3c */
if(!s->budget--) { s->failed_pc=0x0c09de3cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09de3e;
P_0c09de3e: /* original ff37, guest PC 0x0c09de3e */
if(!s->budget--) { s->failed_pc=0x0c09de3eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09de40;
P_0c09de40: /* original e03c, guest PC 0x0c09de40 */
if(!s->budget--) { s->failed_pc=0x0c09de40u; return 0; }
r[0]=0x0000003cu;
goto P_0c09de42;
P_0c09de42: /* original f3f6, guest PC 0x0c09de42 */
if(!s->budget--) { s->failed_pc=0x0c09de42u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c09de44;
P_0c09de44: /* original e00c, guest PC 0x0c09de44 */
if(!s->budget--) { s->failed_pc=0x0c09de44u; return 0; }
r[0]=0x0000000cu;
goto P_0c09de46;
P_0c09de46: /* original f2f6, guest PC 0x0c09de46 */
if(!s->budget--) { s->failed_pc=0x0c09de46u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c09de48;
P_0c09de48: /* original e07c, guest PC 0x0c09de48 */
if(!s->budget--) { s->failed_pc=0x0c09de48u; return 0; }
r[0]=0x0000007cu;
goto P_0c09de4a;
P_0c09de4a: /* original f32e, guest PC 0x0c09de4a */
if(!s->budget--) { s->failed_pc=0x0c09de4au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c09de4c;
P_0c09de4c: /* original ff37, guest PC 0x0c09de4c */
if(!s->budget--) { s->failed_pc=0x0c09de4cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09de4e;
P_0c09de4e: /* original 63f2, guest PC 0x0c09de4e */
if(!s->budget--) { s->failed_pc=0x0c09de4eu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09de50;
P_0c09de50: /* original f68d, guest PC 0x0c09de50 */
if(!s->budget--) { s->failed_pc=0x0c09de50u; return 0; }
fr[6]=0;
goto P_0c09de52;
P_0c09de52: /* original f438, guest PC 0x0c09de52 */
if(!s->budget--) { s->failed_pc=0x0c09de52u; return 0; }
vf3_matrix_load(s,ram,4,r[3]);
goto P_0c09de54;
P_0c09de54: /* original d31e, guest PC 0x0c09de54 */
if(!s->budget--) { s->failed_pc=0x0c09de54u; return 0; }
r[3]=read(ram,0x0c09ded0u,4);
goto P_0c09de56;
P_0c09de56: /* original 430b, guest PC 0x0c09de56 */
if(!s->budget--) { s->failed_pc=0x0c09de56u; return 0; }
target=r[3];
r[16]=code_base|0x0c09de5au;
fr[5]=0;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09de5au) { target=s->pc; goto dispatch; }
goto P_0c09de5a;
P_0c09de58: /* original f58d, guest PC 0x0c09de58 */
if(!s->budget--) { s->failed_pc=0x0c09de58u; return 0; }
fr[5]=0;
goto P_0c09de5a;
P_0c09de5a: /* original 9429, guest PC 0x0c09de5a */
if(!s->budget--) { s->failed_pc=0x0c09de5au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deb0u,2);
goto P_0c09de5c;
P_0c09de5c: /* original bb10, guest PC 0x0c09de5c */
if(!s->budget--) { s->failed_pc=0x0c09de5cu; return 0; }
target=code_base|0x0c09d480u; r[16]=code_base|0x0c09de60u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09de60u) { target=s->pc; goto dispatch; }
goto P_0c09de60;
P_0c09de5e: /* original 34ec, guest PC 0x0c09de5e */
if(!s->budget--) { s->failed_pc=0x0c09de5eu; return 0; }
r[4]+=r[14];
goto P_0c09de60;
P_0c09de60: /* original 9022, guest PC 0x0c09de60 */
if(!s->budget--) { s->failed_pc=0x0c09de60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09dea8u,2);
goto P_0c09de62;
P_0c09de62: /* original f3e6, guest PC 0x0c09de62 */
if(!s->budget--) { s->failed_pc=0x0c09de62u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09de64;
P_0c09de64: /* original 9025, guest PC 0x0c09de64 */
if(!s->budget--) { s->failed_pc=0x0c09de64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deb2u,2);
goto P_0c09de66;
P_0c09de66: /* original ff37, guest PC 0x0c09de66 */
if(!s->budget--) { s->failed_pc=0x0c09de66u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09de68;
P_0c09de68: /* original 9020, guest PC 0x0c09de68 */
if(!s->budget--) { s->failed_pc=0x0c09de68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deacu,2);
goto P_0c09de6a;
P_0c09de6a: /* original f3e6, guest PC 0x0c09de6a */
if(!s->budget--) { s->failed_pc=0x0c09de6au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09de6c;
P_0c09de6c: /* original 9022, guest PC 0x0c09de6c */
if(!s->budget--) { s->failed_pc=0x0c09de6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deb4u,2);
goto P_0c09de6e;
P_0c09de6e: /* original ff37, guest PC 0x0c09de6e */
if(!s->budget--) { s->failed_pc=0x0c09de6eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09de70;
P_0c09de70: /* original 901b, guest PC 0x0c09de70 */
if(!s->budget--) { s->failed_pc=0x0c09de70u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deaau,2);
goto P_0c09de72;
P_0c09de72: /* original f3e6, guest PC 0x0c09de72 */
if(!s->budget--) { s->failed_pc=0x0c09de72u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c09de74;
P_0c09de74: /* original 901f, guest PC 0x0c09de74 */
if(!s->budget--) { s->failed_pc=0x0c09de74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deb6u,2);
goto P_0c09de76;
P_0c09de76: /* original ff37, guest PC 0x0c09de76 */
if(!s->budget--) { s->failed_pc=0x0c09de76u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c09de78;
P_0c09de78: /* original 951e, guest PC 0x0c09de78 */
if(!s->budget--) { s->failed_pc=0x0c09de78u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deb8u,2);
goto P_0c09de7a;
P_0c09de7a: /* original 941a, guest PC 0x0c09de7a */
if(!s->budget--) { s->failed_pc=0x0c09de7au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09deb2u,2);
goto P_0c09de7c;
P_0c09de7c: /* original 35fc, guest PC 0x0c09de7c */
if(!s->budget--) { s->failed_pc=0x0c09de7cu; return 0; }
r[5]+=r[15];
goto P_0c09de7e;
P_0c09de7e: /* original be9f, guest PC 0x0c09de7e */
if(!s->budget--) { s->failed_pc=0x0c09de7eu; return 0; }
target=code_base|0x0c09dbc0u; r[16]=code_base|0x0c09de82u;
r[4]+=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09de82u) { target=s->pc; goto dispatch; }
goto P_0c09de82;
P_0c09de80: /* original 34fc, guest PC 0x0c09de80 */
if(!s->budget--) { s->failed_pc=0x0c09de80u; return 0; }
r[4]+=r[15];
goto P_0c09de82;
P_0c09de82: /* original e03c, guest PC 0x0c09de82 */
if(!s->budget--) { s->failed_pc=0x0c09de82u; return 0; }
r[0]=0x0000003cu;
goto P_0c09de84;
P_0c09de84: /* original 9119, guest PC 0x0c09de84 */
if(!s->budget--) { s->failed_pc=0x0c09de84u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09debau,2);
goto P_0c09de86;
P_0c09de86: /* original 04ed, guest PC 0x0c09de86 */
if(!s->budget--) { s->failed_pc=0x0c09de86u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09de88;
P_0c09de88: /* original 644d, guest PC 0x0c09de88 */
if(!s->budget--) { s->failed_pc=0x0c09de88u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09de8a;
P_0c09de8a: /* original 6043, guest PC 0x0c09de8a */
if(!s->budget--) { s->failed_pc=0x0c09de8au; return 0; }
r[0]=r[4];
goto P_0c09de8c;
P_0c09de8c: /* original 3010, guest PC 0x0c09de8c */
if(!s->budget--) { s->failed_pc=0x0c09de8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c09de8e;
P_0c09de8e: /* original 8904, guest PC 0x0c09de8e */
if(!s->budget--) { s->failed_pc=0x0c09de8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09de9a; }
goto P_0c09de90;
P_0c09de90: /* original 9114, guest PC 0x0c09de90 */
if(!s->budget--) { s->failed_pc=0x0c09de90u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09debcu,2);
goto P_0c09de92;
P_0c09de92: /* original 3010, guest PC 0x0c09de92 */
if(!s->budget--) { s->failed_pc=0x0c09de92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c09de94;
P_0c09de94: /* original 8901, guest PC 0x0c09de94 */
if(!s->budget--) { s->failed_pc=0x0c09de94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09de9a; }
goto P_0c09de96;
P_0c09de96: /* original a01d, guest PC 0x0c09de96 */
if(!s->budget--) { s->failed_pc=0x0c09de96u; return 0; }
goto P_0c09ded4;
P_0c09de98: /* original 0009, guest PC 0x0c09de98 */
if(!s->budget--) { s->failed_pc=0x0c09de98u; return 0; }
goto P_0c09de9a;
P_0c09de9a: /* original a01c, guest PC 0x0c09de9a */
if(!s->budget--) { s->failed_pc=0x0c09de9au; return 0; }
r[11]=0x00000000u;
goto P_0c09ded6;
P_0c09de9c: /* original eb00, guest PC 0x0c09de9c */
if(!s->budget--) { s->failed_pc=0x0c09de9cu; return 0; }
r[11]=0x00000000u;
if(!vf3_matrix_family(0x0c09de9eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09de9eu; return 0; } return 1;
P_0c09ded4: /* original eb01, guest PC 0x0c09ded4 */
if(!s->budget--) { s->failed_pc=0x0c09ded4u; return 0; }
r[11]=0x00000001u;
goto P_0c09ded6;
P_0c09ded6: /* original 904c, guest PC 0x0c09ded6 */
if(!s->budget--) { s->failed_pc=0x0c09ded6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df72u,2);
goto P_0c09ded8;
P_0c09ded8: /* original d32a, guest PC 0x0c09ded8 */
if(!s->budget--) { s->failed_pc=0x0c09ded8u; return 0; }
r[3]=read(ram,0x0c09df84u,4);
goto P_0c09deda;
P_0c09deda: /* original f5f6, guest PC 0x0c09deda */
if(!s->budget--) { s->failed_pc=0x0c09dedau; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09dedc;
P_0c09dedc: /* original 904a, guest PC 0x0c09dedc */
if(!s->budget--) { s->failed_pc=0x0c09dedcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df74u,2);
goto P_0c09dede;
P_0c09dede: /* original 430b, guest PC 0x0c09dede */
if(!s->budget--) { s->failed_pc=0x0c09dedeu; return 0; }
target=r[3];
r[16]=code_base|0x0c09dee2u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dee2u) { target=s->pc; goto dispatch; }
goto P_0c09dee2;
P_0c09dee0: /* original f4f6, guest PC 0x0c09dee0 */
if(!s->budget--) { s->failed_pc=0x0c09dee0u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09dee2;
P_0c09dee2: /* original 2bb8, guest PC 0x0c09dee2 */
if(!s->budget--) { s->failed_pc=0x0c09dee2u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c09dee4;
P_0c09dee4: /* original 8d23, guest PC 0x0c09dee4 */
if(!s->budget--) { s->failed_pc=0x0c09dee4u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
if(cond) { goto P_0c09df2e; }
goto P_0c09dee8;
P_0c09dee6: /* original 640f, guest PC 0x0c09dee6 */
if(!s->budget--) { s->failed_pc=0x0c09dee6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c09dee8;
P_0c09dee8: /* original 2dd8, guest PC 0x0c09dee8 */
if(!s->budget--) { s->failed_pc=0x0c09dee8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c09deea;
P_0c09deea: /* original 890a, guest PC 0x0c09deea */
if(!s->budget--) { s->failed_pc=0x0c09deeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09df02; }
goto P_0c09deec;
P_0c09deec: /* original e03c, guest PC 0x0c09deec */
if(!s->budget--) { s->failed_pc=0x0c09deecu; return 0; }
r[0]=0x0000003cu;
goto P_0c09deee;
P_0c09deee: /* original 00ed, guest PC 0x0c09deee */
if(!s->budget--) { s->failed_pc=0x0c09deeeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c09def0;
P_0c09def0: /* original 600d, guest PC 0x0c09def0 */
if(!s->budget--) { s->failed_pc=0x0c09def0u; return 0; }
r[0]=r[0]&65535u;
goto P_0c09def2;
P_0c09def2: /* original 8848, guest PC 0x0c09def2 */
if(!s->budget--) { s->failed_pc=0x0c09def2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000048u)!=0);
goto P_0c09def4;
P_0c09def4: /* original 8b05, guest PC 0x0c09def4 */
if(!s->budget--) { s->failed_pc=0x0c09def4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df02; }
goto P_0c09def6;
P_0c09def6: /* original 4411, guest PC 0x0c09def6 */
if(!s->budget--) { s->failed_pc=0x0c09def6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c09def8;
P_0c09def8: /* original 8b02, guest PC 0x0c09def8 */
if(!s->budget--) { s->failed_pc=0x0c09def8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df00; }
goto P_0c09defa;
P_0c09defa: /* original d323, guest PC 0x0c09defa */
if(!s->budget--) { s->failed_pc=0x0c09defau; return 0; }
r[3]=read(ram,0x0c09df88u,4);
goto P_0c09defc;
P_0c09defc: /* original 3437, guest PC 0x0c09defc */
if(!s->budget--) { s->failed_pc=0x0c09defcu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[3])!=0);
goto P_0c09defe;
P_0c09defe: /* original 8b00, guest PC 0x0c09defe */
if(!s->budget--) { s->failed_pc=0x0c09defeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df02; }
goto P_0c09df00;
P_0c09df00: /* original 9439, guest PC 0x0c09df00 */
if(!s->budget--) { s->failed_pc=0x0c09df00u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df76u,2);
goto P_0c09df02;
P_0c09df02: /* original 2bb8, guest PC 0x0c09df02 */
if(!s->budget--) { s->failed_pc=0x0c09df02u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c09df04;
P_0c09df04: /* original 8913, guest PC 0x0c09df04 */
if(!s->budget--) { s->failed_pc=0x0c09df04u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09df2e; }
goto P_0c09df06;
P_0c09df06: /* original e061, guest PC 0x0c09df06 */
if(!s->budget--) { s->failed_pc=0x0c09df06u; return 0; }
r[0]=0x00000061u;
goto P_0c09df08;
P_0c09df08: /* original d620, guest PC 0x0c09df08 */
if(!s->budget--) { s->failed_pc=0x0c09df08u; return 0; }
r[6]=read(ram,0x0c09df8cu,4);
goto P_0c09df0a;
P_0c09df0a: /* original 00ec, guest PC 0x0c09df0a */
if(!s->budget--) { s->failed_pc=0x0c09df0au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09df0c;
P_0c09df0c: /* original 346c, guest PC 0x0c09df0c */
if(!s->budget--) { s->failed_pc=0x0c09df0cu; return 0; }
r[4]+=r[6];
goto P_0c09df0e;
P_0c09df0e: /* original 600c, guest PC 0x0c09df0e */
if(!s->budget--) { s->failed_pc=0x0c09df0eu; return 0; }
r[0]=r[0]&255u;
goto P_0c09df10;
P_0c09df10: /* original 880c, guest PC 0x0c09df10 */
if(!s->budget--) { s->failed_pc=0x0c09df10u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c09df12;
P_0c09df12: /* original 8f03, guest PC 0x0c09df12 */
if(!s->budget--) { s->failed_pc=0x0c09df12u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!cond) { goto P_0c09df1c; }
goto P_0c09df16;
P_0c09df14: /* original 644f, guest PC 0x0c09df14 */
if(!s->budget--) { s->failed_pc=0x0c09df14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09df16;
P_0c09df16: /* original 952f, guest PC 0x0c09df16 */
if(!s->budget--) { s->failed_pc=0x0c09df16u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df78u,2);
goto P_0c09df18;
P_0c09df18: /* original a001, guest PC 0x0c09df18 */
if(!s->budget--) { s->failed_pc=0x0c09df18u; return 0; }
goto P_0c09df1e;
P_0c09df1a: /* original 0009, guest PC 0x0c09df1a */
if(!s->budget--) { s->failed_pc=0x0c09df1au; return 0; }
goto P_0c09df1c;
P_0c09df1c: /* original 952d, guest PC 0x0c09df1c */
if(!s->budget--) { s->failed_pc=0x0c09df1cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df7au,2);
goto P_0c09df1e;
P_0c09df1e: /* original 3457, guest PC 0x0c09df1e */
if(!s->budget--) { s->failed_pc=0x0c09df1eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c09df20;
P_0c09df20: /* original 8b00, guest PC 0x0c09df20 */
if(!s->budget--) { s->failed_pc=0x0c09df20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df24; }
goto P_0c09df22;
P_0c09df22: /* original 6453, guest PC 0x0c09df22 */
if(!s->budget--) { s->failed_pc=0x0c09df22u; return 0; }
r[4]=r[5];
goto P_0c09df24;
P_0c09df24: /* original 655b, guest PC 0x0c09df24 */
if(!s->budget--) { s->failed_pc=0x0c09df24u; return 0; }
r[5]=0u-r[5];
goto P_0c09df26;
P_0c09df26: /* original 3453, guest PC 0x0c09df26 */
if(!s->budget--) { s->failed_pc=0x0c09df26u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c09df28;
P_0c09df28: /* original 8900, guest PC 0x0c09df28 */
if(!s->budget--) { s->failed_pc=0x0c09df28u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09df2c; }
goto P_0c09df2a;
P_0c09df2a: /* original 6453, guest PC 0x0c09df2a */
if(!s->budget--) { s->failed_pc=0x0c09df2au; return 0; }
r[4]=r[5];
goto P_0c09df2c;
P_0c09df2c: /* original 3468, guest PC 0x0c09df2c */
if(!s->budget--) { s->failed_pc=0x0c09df2cu; return 0; }
r[4]-=r[6];
goto P_0c09df2e;
P_0c09df2e: /* original 9025, guest PC 0x0c09df2e */
if(!s->budget--) { s->failed_pc=0x0c09df2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df7cu,2);
goto P_0c09df30;
P_0c09df30: /* original 2cc8, guest PC 0x0c09df30 */
if(!s->budget--) { s->failed_pc=0x0c09df30u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09df32;
P_0c09df32: /* original 03ee, guest PC 0x0c09df32 */
if(!s->budget--) { s->failed_pc=0x0c09df32u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09df34;
P_0c09df34: /* original 3438, guest PC 0x0c09df34 */
if(!s->budget--) { s->failed_pc=0x0c09df34u; return 0; }
r[4]-=r[3];
goto P_0c09df36;
P_0c09df36: /* original 8f0a, guest PC 0x0c09df36 */
if(!s->budget--) { s->failed_pc=0x0c09df36u; return 0; }
cond=r[17]&1u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
if(!cond) { goto P_0c09df4e; }
goto P_0c09df3a;
P_0c09df38: /* original 644f, guest PC 0x0c09df38 */
if(!s->budget--) { s->failed_pc=0x0c09df38u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c09df3a;
P_0c09df3a: /* original 2dd8, guest PC 0x0c09df3a */
if(!s->budget--) { s->failed_pc=0x0c09df3au; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c09df3c;
P_0c09df3c: /* original 8b07, guest PC 0x0c09df3c */
if(!s->budget--) { s->failed_pc=0x0c09df3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df4e; }
goto P_0c09df3e;
P_0c09df3e: /* original 951e, guest PC 0x0c09df3e */
if(!s->budget--) { s->failed_pc=0x0c09df3eu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df7eu,2);
goto P_0c09df40;
P_0c09df40: /* original 3457, guest PC 0x0c09df40 */
if(!s->budget--) { s->failed_pc=0x0c09df40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c09df42;
P_0c09df42: /* original 8b00, guest PC 0x0c09df42 */
if(!s->budget--) { s->failed_pc=0x0c09df42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df46; }
goto P_0c09df44;
P_0c09df44: /* original 6453, guest PC 0x0c09df44 */
if(!s->budget--) { s->failed_pc=0x0c09df44u; return 0; }
r[4]=r[5];
goto P_0c09df46;
P_0c09df46: /* original 951b, guest PC 0x0c09df46 */
if(!s->budget--) { s->failed_pc=0x0c09df46u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df80u,2);
goto P_0c09df48;
P_0c09df48: /* original 3453, guest PC 0x0c09df48 */
if(!s->budget--) { s->failed_pc=0x0c09df48u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c09df4a;
P_0c09df4a: /* original 8900, guest PC 0x0c09df4a */
if(!s->budget--) { s->failed_pc=0x0c09df4au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09df4e; }
goto P_0c09df4c;
P_0c09df4c: /* original 6453, guest PC 0x0c09df4c */
if(!s->budget--) { s->failed_pc=0x0c09df4cu; return 0; }
r[4]=r[5];
goto P_0c09df4e;
P_0c09df4e: /* original 03ee, guest PC 0x0c09df4e */
if(!s->budget--) { s->failed_pc=0x0c09df4eu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09df50;
P_0c09df50: /* original 343c, guest PC 0x0c09df50 */
if(!s->budget--) { s->failed_pc=0x0c09df50u; return 0; }
r[4]+=r[3];
goto P_0c09df52;
P_0c09df52: /* original 0e46, guest PC 0x0c09df52 */
if(!s->budget--) { s->failed_pc=0x0c09df52u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09df54;
P_0c09df54: /* original 900d, guest PC 0x0c09df54 */
if(!s->budget--) { s->failed_pc=0x0c09df54u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df72u,2);
goto P_0c09df56;
P_0c09df56: /* original f5f6, guest PC 0x0c09df56 */
if(!s->budget--) { s->failed_pc=0x0c09df56u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c09df58;
P_0c09df58: /* original 900c, guest PC 0x0c09df58 */
if(!s->budget--) { s->failed_pc=0x0c09df58u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09df74u,2);
goto P_0c09df5a;
P_0c09df5a: /* original f05c, guest PC 0x0c09df5a */
if(!s->budget--) { s->failed_pc=0x0c09df5au; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c09df5c;
P_0c09df5c: /* original f4f6, guest PC 0x0c09df5c */
if(!s->budget--) { s->failed_pc=0x0c09df5cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09df5e;
P_0c09df5e: /* original c70c, guest PC 0x0c09df5e */
if(!s->budget--) { s->failed_pc=0x0c09df5eu; return 0; }
r[0]=code_base|0x0009df90u;
goto P_0c09df60;
P_0c09df60: /* original f208, guest PC 0x0c09df60 */
if(!s->budget--) { s->failed_pc=0x0c09df60u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c09df62;
P_0c09df62: /* original f34c, guest PC 0x0c09df62 */
if(!s->budget--) { s->failed_pc=0x0c09df62u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c09df64;
P_0c09df64: /* original f342, guest PC 0x0c09df64 */
if(!s->budget--) { s->failed_pc=0x0c09df64u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'*');
goto P_0c09df66;
P_0c09df66: /* original f35e, guest PC 0x0c09df66 */
if(!s->budget--) { s->failed_pc=0x0c09df66u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c09df68;
P_0c09df68: /* original f43c, guest PC 0x0c09df68 */
if(!s->budget--) { s->failed_pc=0x0c09df68u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c09df6a;
P_0c09df6a: /* original f245, guest PC 0x0c09df6a */
if(!s->budget--) { s->failed_pc=0x0c09df6au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[4]))!=0);
goto P_0c09df6c;
P_0c09df6c: /* original 8b12, guest PC 0x0c09df6c */
if(!s->budget--) { s->failed_pc=0x0c09df6cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09df94; }
goto P_0c09df6e;
P_0c09df6e: /* original a013, guest PC 0x0c09df6e */
if(!s->budget--) { s->failed_pc=0x0c09df6eu; return 0; }
fr[5]=0;
goto P_0c09df98;
P_0c09df70: /* original f58d, guest PC 0x0c09df70 */
if(!s->budget--) { s->failed_pc=0x0c09df70u; return 0; }
fr[5]=0;
if(!vf3_matrix_family(0x0c09df72u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09df72u; return 0; } return 1;
P_0c09df94: /* original f54c, guest PC 0x0c09df94 */
if(!s->budget--) { s->failed_pc=0x0c09df94u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c09df96;
P_0c09df96: /* original f56d, guest PC 0x0c09df96 */
if(!s->budget--) { s->failed_pc=0x0c09df96u; return 0; }
fr[5]=vf3_fpu_sqrt(fr[5],r[18]);
goto P_0c09df98;
P_0c09df98: /* original d32c, guest PC 0x0c09df98 */
if(!s->budget--) { s->failed_pc=0x0c09df98u; return 0; }
r[3]=read(ram,0x0c09e04cu,4);
goto P_0c09df9a;
P_0c09df9a: /* original 904e, guest PC 0x0c09df9a */
if(!s->budget--) { s->failed_pc=0x0c09df9au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e03au,2);
goto P_0c09df9c;
P_0c09df9c: /* original 430b, guest PC 0x0c09df9c */
if(!s->budget--) { s->failed_pc=0x0c09df9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09dfa0u;
vf3_matrix_load(s,ram,4,r[15]+r[0]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09dfa0u) { target=s->pc; goto dispatch; }
goto P_0c09dfa0;
P_0c09df9e: /* original f4f6, guest PC 0x0c09df9e */
if(!s->budget--) { s->failed_pc=0x0c09df9eu; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c09dfa0;
P_0c09dfa0: /* original 2cc8, guest PC 0x0c09dfa0 */
if(!s->budget--) { s->failed_pc=0x0c09dfa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09dfa2;
P_0c09dfa2: /* original 600f, guest PC 0x0c09dfa2 */
if(!s->budget--) { s->failed_pc=0x0c09dfa2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c09dfa4;
P_0c09dfa4: /* original 8f0a, guest PC 0x0c09dfa4 */
if(!s->budget--) { s->failed_pc=0x0c09dfa4u; return 0; }
cond=r[17]&1u;
r[5]=0u-r[0];
if(!cond) { goto P_0c09dfbc; }
goto P_0c09dfa8;
P_0c09dfa6: /* original 650b, guest PC 0x0c09dfa6 */
if(!s->budget--) { s->failed_pc=0x0c09dfa6u; return 0; }
r[5]=0u-r[0];
goto P_0c09dfa8;
P_0c09dfa8: /* original 2dd8, guest PC 0x0c09dfa8 */
if(!s->budget--) { s->failed_pc=0x0c09dfa8u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c09dfaa;
P_0c09dfaa: /* original 8b07, guest PC 0x0c09dfaa */
if(!s->budget--) { s->failed_pc=0x0c09dfaau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dfbc; }
goto P_0c09dfac;
P_0c09dfac: /* original e061, guest PC 0x0c09dfac */
if(!s->budget--) { s->failed_pc=0x0c09dfacu; return 0; }
r[0]=0x00000061u;
goto P_0c09dfae;
P_0c09dfae: /* original 04ec, guest PC 0x0c09dfae */
if(!s->budget--) { s->failed_pc=0x0c09dfaeu; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09dfb0;
P_0c09dfb0: /* original d027, guest PC 0x0c09dfb0 */
if(!s->budget--) { s->failed_pc=0x0c09dfb0u; return 0; }
r[0]=read(ram,0x0c09e050u,4);
goto P_0c09dfb2;
P_0c09dfb2: /* original 644c, guest PC 0x0c09dfb2 */
if(!s->budget--) { s->failed_pc=0x0c09dfb2u; return 0; }
r[4]=r[4]&255u;
goto P_0c09dfb4;
P_0c09dfb4: /* original 4400, guest PC 0x0c09dfb4 */
if(!s->budget--) { s->failed_pc=0x0c09dfb4u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c09dfb6;
P_0c09dfb6: /* original 044d, guest PC 0x0c09dfb6 */
if(!s->budget--) { s->failed_pc=0x0c09dfb6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c09dfb8;
P_0c09dfb8: /* original 644d, guest PC 0x0c09dfb8 */
if(!s->budget--) { s->failed_pc=0x0c09dfb8u; return 0; }
r[4]=r[4]&65535u;
goto P_0c09dfba;
P_0c09dfba: /* original 354c, guest PC 0x0c09dfba */
if(!s->budget--) { s->failed_pc=0x0c09dfbau; return 0; }
r[5]+=r[4];
goto P_0c09dfbc;
P_0c09dfbc: /* original 903e, guest PC 0x0c09dfbc */
if(!s->budget--) { s->failed_pc=0x0c09dfbcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e03cu,2);
goto P_0c09dfbe;
P_0c09dfbe: /* original 2cc8, guest PC 0x0c09dfbe */
if(!s->budget--) { s->failed_pc=0x0c09dfbeu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c09dfc0;
P_0c09dfc0: /* original 04ee, guest PC 0x0c09dfc0 */
if(!s->budget--) { s->failed_pc=0x0c09dfc0u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09dfc2;
P_0c09dfc2: /* original 8f0a, guest PC 0x0c09dfc2 */
if(!s->budget--) { s->failed_pc=0x0c09dfc2u; return 0; }
cond=r[17]&1u;
r[5]-=r[4];
if(!cond) { goto P_0c09dfda; }
goto P_0c09dfc6;
P_0c09dfc4: /* original 3548, guest PC 0x0c09dfc4 */
if(!s->budget--) { s->failed_pc=0x0c09dfc4u; return 0; }
r[5]-=r[4];
goto P_0c09dfc6;
P_0c09dfc6: /* original 2dd8, guest PC 0x0c09dfc6 */
if(!s->budget--) { s->failed_pc=0x0c09dfc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c09dfc8;
P_0c09dfc8: /* original 8b07, guest PC 0x0c09dfc8 */
if(!s->budget--) { s->failed_pc=0x0c09dfc8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dfda; }
goto P_0c09dfca;
P_0c09dfca: /* original 35a7, guest PC 0x0c09dfca */
if(!s->budget--) { s->failed_pc=0x0c09dfcau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[10])!=0);
goto P_0c09dfcc;
P_0c09dfcc: /* original 8b01, guest PC 0x0c09dfcc */
if(!s->budget--) { s->failed_pc=0x0c09dfccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dfd2; }
goto P_0c09dfce;
P_0c09dfce: /* original a004, guest PC 0x0c09dfce */
if(!s->budget--) { s->failed_pc=0x0c09dfceu; return 0; }
r[5]=r[10];
goto P_0c09dfda;
P_0c09dfd0: /* original 65a3, guest PC 0x0c09dfd0 */
if(!s->budget--) { s->failed_pc=0x0c09dfd0u; return 0; }
r[5]=r[10];
goto P_0c09dfd2;
P_0c09dfd2: /* original 9634, guest PC 0x0c09dfd2 */
if(!s->budget--) { s->failed_pc=0x0c09dfd2u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e03eu,2);
goto P_0c09dfd4;
P_0c09dfd4: /* original 3563, guest PC 0x0c09dfd4 */
if(!s->budget--) { s->failed_pc=0x0c09dfd4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c09dfd6;
P_0c09dfd6: /* original 8900, guest PC 0x0c09dfd6 */
if(!s->budget--) { s->failed_pc=0x0c09dfd6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09dfda; }
goto P_0c09dfd8;
P_0c09dfd8: /* original 6563, guest PC 0x0c09dfd8 */
if(!s->budget--) { s->failed_pc=0x0c09dfd8u; return 0; }
r[5]=r[6];
goto P_0c09dfda;
P_0c09dfda: /* original 2bb8, guest PC 0x0c09dfda */
if(!s->budget--) { s->failed_pc=0x0c09dfdau; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c09dfdc;
P_0c09dfdc: /* original 8d10, guest PC 0x0c09dfdc */
if(!s->budget--) { s->failed_pc=0x0c09dfdcu; return 0; }
cond=r[17]&1u;
r[4]+=r[5];
if(cond) { goto P_0c09e000; }
goto P_0c09dfe0;
P_0c09dfde: /* original 345c, guest PC 0x0c09dfde */
if(!s->budget--) { s->failed_pc=0x0c09dfdeu; return 0; }
r[4]+=r[5];
goto P_0c09dfe0;
P_0c09dfe0: /* original e061, guest PC 0x0c09dfe0 */
if(!s->budget--) { s->failed_pc=0x0c09dfe0u; return 0; }
r[0]=0x00000061u;
goto P_0c09dfe2;
P_0c09dfe2: /* original 00ec, guest PC 0x0c09dfe2 */
if(!s->budget--) { s->failed_pc=0x0c09dfe2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c09dfe4;
P_0c09dfe4: /* original 600c, guest PC 0x0c09dfe4 */
if(!s->budget--) { s->failed_pc=0x0c09dfe4u; return 0; }
r[0]=r[0]&255u;
goto P_0c09dfe6;
P_0c09dfe6: /* original 880c, guest PC 0x0c09dfe6 */
if(!s->budget--) { s->failed_pc=0x0c09dfe6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c09dfe8;
P_0c09dfe8: /* original 8b02, guest PC 0x0c09dfe8 */
if(!s->budget--) { s->failed_pc=0x0c09dfe8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dff0; }
goto P_0c09dfea;
P_0c09dfea: /* original 9529, guest PC 0x0c09dfea */
if(!s->budget--) { s->failed_pc=0x0c09dfeau; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e040u,2);
goto P_0c09dfec;
P_0c09dfec: /* original a001, guest PC 0x0c09dfec */
if(!s->budget--) { s->failed_pc=0x0c09dfecu; return 0; }
goto P_0c09dff2;
P_0c09dfee: /* original 0009, guest PC 0x0c09dfee */
if(!s->budget--) { s->failed_pc=0x0c09dfeeu; return 0; }
goto P_0c09dff0;
P_0c09dff0: /* original 9527, guest PC 0x0c09dff0 */
if(!s->budget--) { s->failed_pc=0x0c09dff0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e042u,2);
goto P_0c09dff2;
P_0c09dff2: /* original 3457, guest PC 0x0c09dff2 */
if(!s->budget--) { s->failed_pc=0x0c09dff2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>(int32_t)r[5])!=0);
goto P_0c09dff4;
P_0c09dff4: /* original 8b00, guest PC 0x0c09dff4 */
if(!s->budget--) { s->failed_pc=0x0c09dff4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09dff8; }
goto P_0c09dff6;
P_0c09dff6: /* original 6453, guest PC 0x0c09dff6 */
if(!s->budget--) { s->failed_pc=0x0c09dff6u; return 0; }
r[4]=r[5];
goto P_0c09dff8;
P_0c09dff8: /* original 9524, guest PC 0x0c09dff8 */
if(!s->budget--) { s->failed_pc=0x0c09dff8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e044u,2);
goto P_0c09dffa;
P_0c09dffa: /* original 3453, guest PC 0x0c09dffa */
if(!s->budget--) { s->failed_pc=0x0c09dffau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c09dffc;
P_0c09dffc: /* original 8900, guest PC 0x0c09dffc */
if(!s->budget--) { s->failed_pc=0x0c09dffcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09e000; }
goto P_0c09dffe;
P_0c09dffe: /* original 6453, guest PC 0x0c09dffe */
if(!s->budget--) { s->failed_pc=0x0c09dffeu; return 0; }
r[4]=r[5];
goto P_0c09e000;
P_0c09e000: /* original 901c, guest PC 0x0c09e000 */
if(!s->budget--) { s->failed_pc=0x0c09e000u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e03cu,2);
goto P_0c09e002;
P_0c09e002: /* original 0e46, guest PC 0x0c09e002 */
if(!s->budget--) { s->failed_pc=0x0c09e002u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09e004;
P_0c09e004: /* original 70fc, guest PC 0x0c09e004 */
if(!s->budget--) { s->failed_pc=0x0c09e004u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09e006;
P_0c09e006: /* original d313, guest PC 0x0c09e006 */
if(!s->budget--) { s->failed_pc=0x0c09e006u; return 0; }
r[3]=read(ram,0x0c09e054u,4);
goto P_0c09e008;
P_0c09e008: /* original 430b, guest PC 0x0c09e008 */
if(!s->budget--) { s->failed_pc=0x0c09e008u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e00cu;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e00cu) { target=s->pc; goto dispatch; }
goto P_0c09e00c;
P_0c09e00a: /* original 04ee, guest PC 0x0c09e00a */
if(!s->budget--) { s->failed_pc=0x0c09e00au; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09e00c;
P_0c09e00c: /* original d312, guest PC 0x0c09e00c */
if(!s->budget--) { s->failed_pc=0x0c09e00cu; return 0; }
r[3]=read(ram,0x0c09e058u,4);
goto P_0c09e00e;
P_0c09e00e: /* original 9015, guest PC 0x0c09e00e */
if(!s->budget--) { s->failed_pc=0x0c09e00eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e03cu,2);
goto P_0c09e010;
P_0c09e010: /* original 430b, guest PC 0x0c09e010 */
if(!s->budget--) { s->failed_pc=0x0c09e010u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e014u;
r[4]=read(ram,r[14]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e014u) { target=s->pc; goto dispatch; }
goto P_0c09e014;
P_0c09e012: /* original 04ee, guest PC 0x0c09e012 */
if(!s->budget--) { s->failed_pc=0x0c09e012u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09e014;
P_0c09e014: /* original 64f3, guest PC 0x0c09e014 */
if(!s->budget--) { s->failed_pc=0x0c09e014u; return 0; }
r[4]=r[15];
goto P_0c09e016;
P_0c09e016: /* original ba66, guest PC 0x0c09e016 */
if(!s->budget--) { s->failed_pc=0x0c09e016u; return 0; }
target=code_base|0x0c09d4e6u; r[16]=code_base|0x0c09e01au;
r[4]+=0x00000044u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e01au) { target=s->pc; goto dispatch; }
goto P_0c09e01a;
P_0c09e018: /* original 7444, guest PC 0x0c09e018 */
if(!s->budget--) { s->failed_pc=0x0c09e018u; return 0; }
r[4]+=0x00000044u;
goto P_0c09e01a;
P_0c09e01a: /* original 9414, guest PC 0x0c09e01a */
if(!s->budget--) { s->failed_pc=0x0c09e01au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e046u,2);
goto P_0c09e01c;
P_0c09e01c: /* original 65f3, guest PC 0x0c09e01c */
if(!s->budget--) { s->failed_pc=0x0c09e01cu; return 0; }
r[5]=r[15];
goto P_0c09e01e;
P_0c09e01e: /* original d30f, guest PC 0x0c09e01e */
if(!s->budget--) { s->failed_pc=0x0c09e01eu; return 0; }
r[3]=read(ram,0x0c09e05cu,4);
goto P_0c09e020;
P_0c09e020: /* original 7544, guest PC 0x0c09e020 */
if(!s->budget--) { s->failed_pc=0x0c09e020u; return 0; }
r[5]+=0x00000044u;
goto P_0c09e022;
P_0c09e022: /* original 430b, guest PC 0x0c09e022 */
if(!s->budget--) { s->failed_pc=0x0c09e022u; return 0; }
target=r[3];
r[16]=code_base|0x0c09e026u;
r[4]+=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09e026u) { target=s->pc; goto dispatch; }
goto P_0c09e026;
P_0c09e024: /* original 34ec, guest PC 0x0c09e024 */
if(!s->budget--) { s->failed_pc=0x0c09e024u; return 0; }
r[4]+=r[14];
goto P_0c09e026;
P_0c09e026: /* original 910f, guest PC 0x0c09e026 */
if(!s->budget--) { s->failed_pc=0x0c09e026u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09e048u,2);
goto P_0c09e028;
P_0c09e028: /* original 3f1c, guest PC 0x0c09e028 */
if(!s->budget--) { s->failed_pc=0x0c09e028u; return 0; }
r[15]+=r[1];
goto P_0c09e02a;
P_0c09e02a: /* original 4f26, guest PC 0x0c09e02a */
if(!s->budget--) { s->failed_pc=0x0c09e02au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09e02c;
P_0c09e02c: /* original fff9, guest PC 0x0c09e02c */
if(!s->budget--) { s->failed_pc=0x0c09e02cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c09e02e;
P_0c09e02e: /* original 6af6, guest PC 0x0c09e02e */
if(!s->budget--) { s->failed_pc=0x0c09e02eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09e030;
P_0c09e030: /* original 6bf6, guest PC 0x0c09e030 */
if(!s->budget--) { s->failed_pc=0x0c09e030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09e032;
P_0c09e032: /* original 6cf6, guest PC 0x0c09e032 */
if(!s->budget--) { s->failed_pc=0x0c09e032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09e034;
P_0c09e034: /* original 6df6, guest PC 0x0c09e034 */
if(!s->budget--) { s->failed_pc=0x0c09e034u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09e036;
P_0c09e036: /* original 000b, guest PC 0x0c09e036 */
if(!s->budget--) { s->failed_pc=0x0c09e036u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09e038: /* original 6ef6, guest PC 0x0c09e038 */
if(!s->budget--) { s->failed_pc=0x0c09e038u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09e03au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09e03au; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
