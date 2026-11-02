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
int vf3_away_batch17_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03cac0u: goto P_0c03cac0;
case 0x0c03cac2u: goto P_0c03cac2;
case 0x0c03cac4u: goto P_0c03cac4;
case 0x0c03cac6u: goto P_0c03cac6;
case 0x0c03cac8u: goto P_0c03cac8;
case 0x0c03cacau: goto P_0c03caca;
case 0x0c03caccu: goto P_0c03cacc;
case 0x0c03caceu: goto P_0c03cace;
case 0x0c03cad0u: goto P_0c03cad0;
case 0x0c03cad2u: goto P_0c03cad2;
case 0x0c03cad4u: goto P_0c03cad4;
case 0x0c03cad6u: goto P_0c03cad6;
case 0x0c03cad8u: goto P_0c03cad8;
case 0x0c03cadau: goto P_0c03cada;
case 0x0c03cadcu: goto P_0c03cadc;
case 0x0c03cadeu: goto P_0c03cade;
case 0x0c03cae0u: goto P_0c03cae0;
case 0x0c03cae2u: goto P_0c03cae2;
case 0x0c03cae4u: goto P_0c03cae4;
case 0x0c03cae6u: goto P_0c03cae6;
case 0x0c03cae8u: goto P_0c03cae8;
case 0x0c03caeau: goto P_0c03caea;
case 0x0c03caecu: goto P_0c03caec;
case 0x0c03caeeu: goto P_0c03caee;
case 0x0c03caf0u: goto P_0c03caf0;
case 0x0c03caf2u: goto P_0c03caf2;
case 0x0c03caf4u: goto P_0c03caf4;
case 0x0c03caf6u: goto P_0c03caf6;
case 0x0c03caf8u: goto P_0c03caf8;
case 0x0c03cafau: goto P_0c03cafa;
case 0x0c03cafcu: goto P_0c03cafc;
case 0x0c03cb00u: goto P_0c03cb00;
case 0x0c03cb02u: goto P_0c03cb02;
case 0x0c03cb04u: goto P_0c03cb04;
case 0x0c03cb06u: goto P_0c03cb06;
case 0x0c03cb08u: goto P_0c03cb08;
case 0x0c03cb0au: goto P_0c03cb0a;
case 0x0c03cb0cu: goto P_0c03cb0c;
case 0x0c03cb0eu: goto P_0c03cb0e;
case 0x0c03cb10u: goto P_0c03cb10;
case 0x0c03cb12u: goto P_0c03cb12;
case 0x0c03cb14u: goto P_0c03cb14;
case 0x0c03cb16u: goto P_0c03cb16;
case 0x0c03cb18u: goto P_0c03cb18;
case 0x0c03cb1au: goto P_0c03cb1a;
case 0x0c03cb1cu: goto P_0c03cb1c;
case 0x0c03cb1eu: goto P_0c03cb1e;
case 0x0c03cb20u: goto P_0c03cb20;
case 0x0c03cb22u: goto P_0c03cb22;
case 0x0c03cb24u: goto P_0c03cb24;
case 0x0c03cb26u: goto P_0c03cb26;
case 0x0c03cb28u: goto P_0c03cb28;
case 0x0c03cb2au: goto P_0c03cb2a;
case 0x0c03cb2cu: goto P_0c03cb2c;
case 0x0c03cb2eu: goto P_0c03cb2e;
case 0x0c03cb30u: goto P_0c03cb30;
case 0x0c03cba0u: goto P_0c03cba0;
case 0x0c03cba2u: goto P_0c03cba2;
case 0x0c03cba4u: goto P_0c03cba4;
case 0x0c03cba6u: goto P_0c03cba6;
case 0x0c03cba8u: goto P_0c03cba8;
case 0x0c03cbaau: goto P_0c03cbaa;
case 0x0c03cbacu: goto P_0c03cbac;
case 0x0c03cbaeu: goto P_0c03cbae;
case 0x0c03cbb0u: goto P_0c03cbb0;
case 0x0c03cbb2u: goto P_0c03cbb2;
case 0x0c03cbb4u: goto P_0c03cbb4;
case 0x0c03cbb6u: goto P_0c03cbb6;
case 0x0c03cbb8u: goto P_0c03cbb8;
case 0x0c03cbbau: goto P_0c03cbba;
case 0x0c03cbbcu: goto P_0c03cbbc;
case 0x0c03cbbeu: goto P_0c03cbbe;
case 0x0c03cbc0u: goto P_0c03cbc0;
case 0x0c03cbc2u: goto P_0c03cbc2;
case 0x0c03cbc4u: goto P_0c03cbc4;
case 0x0c03cbc6u: goto P_0c03cbc6;
case 0x0c03cbc8u: goto P_0c03cbc8;
case 0x0c03cbcau: goto P_0c03cbca;
case 0x0c03cd70u: goto P_0c03cd70;
case 0x0c03cd72u: goto P_0c03cd72;
case 0x0c03cd74u: goto P_0c03cd74;
case 0x0c03cd76u: goto P_0c03cd76;
case 0x0c03cd78u: goto P_0c03cd78;
case 0x0c03cd7au: goto P_0c03cd7a;
case 0x0c03cd7cu: goto P_0c03cd7c;
case 0x0c03cd7eu: goto P_0c03cd7e;
case 0x0c03cd80u: goto P_0c03cd80;
case 0x0c03cd82u: goto P_0c03cd82;
case 0x0c03cd84u: goto P_0c03cd84;
case 0x0c03cd86u: goto P_0c03cd86;
case 0x0c03cdb0u: goto P_0c03cdb0;
case 0x0c03cdb2u: goto P_0c03cdb2;
case 0x0c03cdb4u: goto P_0c03cdb4;
case 0x0c03cdb6u: goto P_0c03cdb6;
case 0x0c03cdb8u: goto P_0c03cdb8;
case 0x0c03cdbau: goto P_0c03cdba;
case 0x0c03cdbcu: goto P_0c03cdbc;
case 0x0c03cdbeu: goto P_0c03cdbe;
case 0x0c03cdc0u: goto P_0c03cdc0;
case 0x0c03cdc2u: goto P_0c03cdc2;
case 0x0c03cdc4u: goto P_0c03cdc4;
case 0x0c03cdc6u: goto P_0c03cdc6;
case 0x0c03cdc8u: goto P_0c03cdc8;
case 0x0c03cdcau: goto P_0c03cdca;
case 0x0c03cdccu: goto P_0c03cdcc;
case 0x0c03cdceu: goto P_0c03cdce;
case 0x0c03cdd0u: goto P_0c03cdd0;
case 0x0c03cdd2u: goto P_0c03cdd2;
case 0x0c03cdd4u: goto P_0c03cdd4;
case 0x0c03cdd6u: goto P_0c03cdd6;
case 0x0c03cdd8u: goto P_0c03cdd8;
case 0x0c03cddau: goto P_0c03cdda;
case 0x0c03cddcu: goto P_0c03cddc;
case 0x0c03cddeu: goto P_0c03cdde;
case 0x0c03cde0u: goto P_0c03cde0;
case 0x0c03cde2u: goto P_0c03cde2;
case 0x0c03d040u: goto P_0c03d040;
case 0x0c03d042u: goto P_0c03d042;
case 0x0c03d044u: goto P_0c03d044;
case 0x0c03d046u: goto P_0c03d046;
case 0x0c03d048u: goto P_0c03d048;
case 0x0c03d060u: goto P_0c03d060;
case 0x0c03d062u: goto P_0c03d062;
case 0x0c03d064u: goto P_0c03d064;
case 0x0c03d066u: goto P_0c03d066;
case 0x0c03d068u: goto P_0c03d068;
case 0x0c03d06au: goto P_0c03d06a;
case 0x0c03d06cu: goto P_0c03d06c;
case 0x0c03d06eu: goto P_0c03d06e;
case 0x0c03d070u: goto P_0c03d070;
case 0x0c03d072u: goto P_0c03d072;
case 0x0c03d074u: goto P_0c03d074;
case 0x0c03d076u: goto P_0c03d076;
case 0x0c03d078u: goto P_0c03d078;
case 0x0c03d07au: goto P_0c03d07a;
case 0x0c03d07cu: goto P_0c03d07c;
case 0x0c03d07eu: goto P_0c03d07e;
case 0x0c03d080u: goto P_0c03d080;
case 0x0c03d082u: goto P_0c03d082;
case 0x0c03d260u: goto P_0c03d260;
case 0x0c03d262u: goto P_0c03d262;
case 0x0c03d264u: goto P_0c03d264;
case 0x0c03d266u: goto P_0c03d266;
case 0x0c03d268u: goto P_0c03d268;
case 0x0c03d26au: goto P_0c03d26a;
case 0x0c03d26cu: goto P_0c03d26c;
case 0x0c03d26eu: goto P_0c03d26e;
case 0x0c03d270u: goto P_0c03d270;
case 0x0c03d272u: goto P_0c03d272;
case 0x0c03d274u: goto P_0c03d274;
case 0x0c03d276u: goto P_0c03d276;
case 0x0c03d278u: goto P_0c03d278;
case 0x0c03d27au: goto P_0c03d27a;
case 0x0c03d27cu: goto P_0c03d27c;
case 0x0c03d27eu: goto P_0c03d27e;
case 0x0c03dd00u: goto P_0c03dd00;
case 0x0c03dd02u: goto P_0c03dd02;
case 0x0c03dd04u: goto P_0c03dd04;
case 0x0c03dd06u: goto P_0c03dd06;
case 0x0c03dd08u: goto P_0c03dd08;
case 0x0c03dd30u: goto P_0c03dd30;
case 0x0c03dd32u: goto P_0c03dd32;
case 0x0c03dd34u: goto P_0c03dd34;
case 0x0c03dd36u: goto P_0c03dd36;
case 0x0c03dd38u: goto P_0c03dd38;
case 0x0c03dd3au: goto P_0c03dd3a;
case 0x0c03dd3cu: goto P_0c03dd3c;
case 0x0c03dd3eu: goto P_0c03dd3e;
case 0x0c03dd40u: goto P_0c03dd40;
case 0x0c03dd42u: goto P_0c03dd42;
case 0x0c03dd44u: goto P_0c03dd44;
case 0x0c03dd46u: goto P_0c03dd46;
case 0x0c03dd48u: goto P_0c03dd48;
case 0x0c03dd4au: goto P_0c03dd4a;
case 0x0c03dd4cu: goto P_0c03dd4c;
case 0x0c03dd4eu: goto P_0c03dd4e;
case 0x0c03dd50u: goto P_0c03dd50;
case 0x0c03dd52u: goto P_0c03dd52;
case 0x0c03dd54u: goto P_0c03dd54;
case 0x0c03dd56u: goto P_0c03dd56;
case 0x0c03dd58u: goto P_0c03dd58;
case 0x0c03dd5au: goto P_0c03dd5a;
case 0x0c03dd5cu: goto P_0c03dd5c;
case 0x0c03dd5eu: goto P_0c03dd5e;
case 0x0c03dd60u: goto P_0c03dd60;
case 0x0c03dd62u: goto P_0c03dd62;
case 0x0c03dd64u: goto P_0c03dd64;
case 0x0c03dd66u: goto P_0c03dd66;
case 0x0c03dd68u: goto P_0c03dd68;
case 0x0c03dd6au: goto P_0c03dd6a;
case 0x0c03dd6cu: goto P_0c03dd6c;
case 0x0c03dd6eu: goto P_0c03dd6e;
case 0x0c03dd70u: goto P_0c03dd70;
case 0x0c03dd72u: goto P_0c03dd72;
case 0x0c03dd74u: goto P_0c03dd74;
case 0x0c03dd76u: goto P_0c03dd76;
case 0x0c03dd78u: goto P_0c03dd78;
case 0x0c03dd7au: goto P_0c03dd7a;
case 0x0c03dd7cu: goto P_0c03dd7c;
case 0x0c03dd7eu: goto P_0c03dd7e;
case 0x0c03dd80u: goto P_0c03dd80;
case 0x0c03dd82u: goto P_0c03dd82;
case 0x0c03dd84u: goto P_0c03dd84;
case 0x0c03dd86u: goto P_0c03dd86;
case 0x0c03dd88u: goto P_0c03dd88;
case 0x0c03dd8au: goto P_0c03dd8a;
case 0x0c03dd8cu: goto P_0c03dd8c;
case 0x0c03dd8eu: goto P_0c03dd8e;
case 0x0c03dd90u: goto P_0c03dd90;
case 0x0c03dd92u: goto P_0c03dd92;
case 0x0c03dd94u: goto P_0c03dd94;
case 0x0c03dd96u: goto P_0c03dd96;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03cac0: /* original 2fe6, guest PC 0x0c03cac0 */
if(!s->budget--) { s->failed_pc=0x0c03cac0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03cac2;
P_0c03cac2: /* original 6e43, guest PC 0x0c03cac2 */
if(!s->budget--) { s->failed_pc=0x0c03cac2u; return 0; }
r[14]=r[4];
goto P_0c03cac4;
P_0c03cac4: /* original fffb, guest PC 0x0c03cac4 */
if(!s->budget--) { s->failed_pc=0x0c03cac4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03cac6;
P_0c03cac6: /* original 4f22, guest PC 0x0c03cac6 */
if(!s->budget--) { s->failed_pc=0x0c03cac6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03cac8;
P_0c03cac8: /* original 7ff0, guest PC 0x0c03cac8 */
if(!s->budget--) { s->failed_pc=0x0c03cac8u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03caca;
P_0c03caca: /* original 66f3, guest PC 0x0c03caca */
if(!s->budget--) { s->failed_pc=0x0c03cacau; return 0; }
r[6]=r[15];
goto P_0c03cacc;
P_0c03cacc: /* original 7604, guest PC 0x0c03cacc */
if(!s->budget--) { s->failed_pc=0x0c03caccu; return 0; }
r[6]+=0x00000004u;
goto P_0c03cace;
P_0c03cace: /* original 2f52, guest PC 0x0c03cace */
if(!s->budget--) { s->failed_pc=0x0c03caceu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03cad0;
P_0c03cad0: /* original d320, guest PC 0x0c03cad0 */
if(!s->budget--) { s->failed_pc=0x0c03cad0u; return 0; }
r[3]=read(ram,0x0c03cb54u,4);
goto P_0c03cad2;
P_0c03cad2: /* original 430b, guest PC 0x0c03cad2 */
if(!s->budget--) { s->failed_pc=0x0c03cad2u; return 0; }
target=r[3];
r[16]=code_base|0x0c03cad6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cad6u) { target=s->pc; goto dispatch; }
goto P_0c03cad6;
P_0c03cad4: /* original 64e3, guest PC 0x0c03cad4 */
if(!s->budget--) { s->failed_pc=0x0c03cad4u; return 0; }
r[4]=r[14];
goto P_0c03cad6;
P_0c03cad6: /* original d220, guest PC 0x0c03cad6 */
if(!s->budget--) { s->failed_pc=0x0c03cad6u; return 0; }
r[2]=read(ram,0x0c03cb58u,4);
goto P_0c03cad8;
P_0c03cad8: /* original 64f3, guest PC 0x0c03cad8 */
if(!s->budget--) { s->failed_pc=0x0c03cad8u; return 0; }
r[4]=r[15];
goto P_0c03cada;
P_0c03cada: /* original 420b, guest PC 0x0c03cada */
if(!s->budget--) { s->failed_pc=0x0c03cadau; return 0; }
target=r[2];
r[16]=code_base|0x0c03cadeu;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cadeu) { target=s->pc; goto dispatch; }
goto P_0c03cade;
P_0c03cadc: /* original 7404, guest PC 0x0c03cadc */
if(!s->budget--) { s->failed_pc=0x0c03cadcu; return 0; }
r[4]+=0x00000004u;
goto P_0c03cade;
P_0c03cade: /* original d31f, guest PC 0x0c03cade */
if(!s->budget--) { s->failed_pc=0x0c03cadeu; return 0; }
r[3]=read(ram,0x0c03cb5cu,4);
goto P_0c03cae0;
P_0c03cae0: /* original 65f2, guest PC 0x0c03cae0 */
if(!s->budget--) { s->failed_pc=0x0c03cae0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03cae2;
P_0c03cae2: /* original ff0c, guest PC 0x0c03cae2 */
if(!s->budget--) { s->failed_pc=0x0c03cae2u; return 0; }
vf3_matrix_move(s,15,0);
goto P_0c03cae4;
P_0c03cae4: /* original 430b, guest PC 0x0c03cae4 */
if(!s->budget--) { s->failed_pc=0x0c03cae4u; return 0; }
target=r[3];
r[16]=code_base|0x0c03cae8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cae8u) { target=s->pc; goto dispatch; }
goto P_0c03cae8;
P_0c03cae6: /* original 64e3, guest PC 0x0c03cae6 */
if(!s->budget--) { s->failed_pc=0x0c03cae6u; return 0; }
r[4]=r[14];
goto P_0c03cae8;
P_0c03cae8: /* original f38d, guest PC 0x0c03cae8 */
if(!s->budget--) { s->failed_pc=0x0c03cae8u; return 0; }
fr[3]=0;
goto P_0c03caea;
P_0c03caea: /* original ff34, guest PC 0x0c03caea */
if(!s->budget--) { s->failed_pc=0x0c03caeau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])==as_float(fr[3]))!=0);
goto P_0c03caec;
P_0c03caec: /* original 8d08, guest PC 0x0c03caec */
if(!s->budget--) { s->failed_pc=0x0c03caecu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,0);
if(cond) { goto P_0c03cb00; }
goto P_0c03caf0;
P_0c03caee: /* original f50c, guest PC 0x0c03caee */
if(!s->budget--) { s->failed_pc=0x0c03caeeu; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c03caf0;
P_0c03caf0: /* original d21b, guest PC 0x0c03caf0 */
if(!s->budget--) { s->failed_pc=0x0c03caf0u; return 0; }
r[2]=read(ram,0x0c03cb60u,4);
goto P_0c03caf2;
P_0c03caf2: /* original 64f3, guest PC 0x0c03caf2 */
if(!s->budget--) { s->failed_pc=0x0c03caf2u; return 0; }
r[4]=r[15];
goto P_0c03caf4;
P_0c03caf4: /* original f4fc, guest PC 0x0c03caf4 */
if(!s->budget--) { s->failed_pc=0x0c03caf4u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c03caf6;
P_0c03caf6: /* original 420b, guest PC 0x0c03caf6 */
if(!s->budget--) { s->failed_pc=0x0c03caf6u; return 0; }
target=r[2];
r[16]=code_base|0x0c03cafau;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cafau) { target=s->pc; goto dispatch; }
goto P_0c03cafa;
P_0c03caf8: /* original 7404, guest PC 0x0c03caf8 */
if(!s->budget--) { s->failed_pc=0x0c03caf8u; return 0; }
r[4]+=0x00000004u;
goto P_0c03cafa;
P_0c03cafa: /* original a015, guest PC 0x0c03cafa */
if(!s->budget--) { s->failed_pc=0x0c03cafau; return 0; }
goto P_0c03cb28;
P_0c03cafc: /* original 0009, guest PC 0x0c03cafc */
if(!s->budget--) { s->failed_pc=0x0c03cafcu; return 0; }
if(!vf3_matrix_family(0x0c03cafeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cafeu; return 0; } return 1;
P_0c03cb00: /* original f355, guest PC 0x0c03cb00 */
if(!s->budget--) { s->failed_pc=0x0c03cb00u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c03cb02;
P_0c03cb02: /* original 8b11, guest PC 0x0c03cb02 */
if(!s->budget--) { s->failed_pc=0x0c03cb02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03cb28; }
goto P_0c03cb04;
P_0c03cb04: /* original e004, guest PC 0x0c03cb04 */
if(!s->budget--) { s->failed_pc=0x0c03cb04u; return 0; }
r[0]=0x00000004u;
goto P_0c03cb06;
P_0c03cb06: /* original 64f3, guest PC 0x0c03cb06 */
if(!s->budget--) { s->failed_pc=0x0c03cb06u; return 0; }
r[4]=r[15];
goto P_0c03cb08;
P_0c03cb08: /* original f3e6, guest PC 0x0c03cb08 */
if(!s->budget--) { s->failed_pc=0x0c03cb08u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03cb0a;
P_0c03cb0a: /* original e004, guest PC 0x0c03cb0a */
if(!s->budget--) { s->failed_pc=0x0c03cb0au; return 0; }
r[0]=0x00000004u;
goto P_0c03cb0c;
P_0c03cb0c: /* original ff37, guest PC 0x0c03cb0c */
if(!s->budget--) { s->failed_pc=0x0c03cb0cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03cb0e;
P_0c03cb0e: /* original e008, guest PC 0x0c03cb0e */
if(!s->budget--) { s->failed_pc=0x0c03cb0eu; return 0; }
r[0]=0x00000008u;
goto P_0c03cb10;
P_0c03cb10: /* original f3e6, guest PC 0x0c03cb10 */
if(!s->budget--) { s->failed_pc=0x0c03cb10u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c03cb12;
P_0c03cb12: /* original e008, guest PC 0x0c03cb12 */
if(!s->budget--) { s->failed_pc=0x0c03cb12u; return 0; }
r[0]=0x00000008u;
goto P_0c03cb14;
P_0c03cb14: /* original ff37, guest PC 0x0c03cb14 */
if(!s->budget--) { s->failed_pc=0x0c03cb14u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03cb16;
P_0c03cb16: /* original e00c, guest PC 0x0c03cb16 */
if(!s->budget--) { s->failed_pc=0x0c03cb16u; return 0; }
r[0]=0x0000000cu;
goto P_0c03cb18;
P_0c03cb18: /* original f3e8, guest PC 0x0c03cb18 */
if(!s->budget--) { s->failed_pc=0x0c03cb18u; return 0; }
vf3_matrix_load(s,ram,3,r[14]);
goto P_0c03cb1a;
P_0c03cb1a: /* original ff37, guest PC 0x0c03cb1a */
if(!s->budget--) { s->failed_pc=0x0c03cb1au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c03cb1c;
P_0c03cb1c: /* original c711, guest PC 0x0c03cb1c */
if(!s->budget--) { s->failed_pc=0x0c03cb1cu; return 0; }
r[0]=code_base|0x0003cb64u;
goto P_0c03cb1e;
P_0c03cb1e: /* original d310, guest PC 0x0c03cb1e */
if(!s->budget--) { s->failed_pc=0x0c03cb1eu; return 0; }
r[3]=read(ram,0x0c03cb60u,4);
goto P_0c03cb20;
P_0c03cb20: /* original f508, guest PC 0x0c03cb20 */
if(!s->budget--) { s->failed_pc=0x0c03cb20u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c03cb22;
P_0c03cb22: /* original f48d, guest PC 0x0c03cb22 */
if(!s->budget--) { s->failed_pc=0x0c03cb22u; return 0; }
fr[4]=0;
goto P_0c03cb24;
P_0c03cb24: /* original 430b, guest PC 0x0c03cb24 */
if(!s->budget--) { s->failed_pc=0x0c03cb24u; return 0; }
target=r[3];
r[16]=code_base|0x0c03cb28u;
r[4]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03cb28u) { target=s->pc; goto dispatch; }
goto P_0c03cb28;
P_0c03cb26: /* original 7404, guest PC 0x0c03cb26 */
if(!s->budget--) { s->failed_pc=0x0c03cb26u; return 0; }
r[4]+=0x00000004u;
goto P_0c03cb28;
P_0c03cb28: /* original 7f10, guest PC 0x0c03cb28 */
if(!s->budget--) { s->failed_pc=0x0c03cb28u; return 0; }
r[15]+=0x00000010u;
goto P_0c03cb2a;
P_0c03cb2a: /* original 4f26, guest PC 0x0c03cb2a */
if(!s->budget--) { s->failed_pc=0x0c03cb2au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03cb2c;
P_0c03cb2c: /* original fff9, guest PC 0x0c03cb2c */
if(!s->budget--) { s->failed_pc=0x0c03cb2cu; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03cb2e;
P_0c03cb2e: /* original 000b, guest PC 0x0c03cb2e */
if(!s->budget--) { s->failed_pc=0x0c03cb2eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03cb30: /* original 6ef6, guest PC 0x0c03cb30 */
if(!s->budget--) { s->failed_pc=0x0c03cb30u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03cb32u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cb32u; return 0; } return 1;
P_0c03cba0: /* original fbfd, guest PC 0x0c03cba0 */
if(!s->budget--) { s->failed_pc=0x0c03cba0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03cba2;
P_0c03cba2: /* original ff1d, guest PC 0x0c03cba2 */
if(!s->budget--) { s->failed_pc=0x0c03cba2u; return 0; }
r[53]=fr[15];
goto P_0c03cba4;
P_0c03cba4: /* original ff49, guest PC 0x0c03cba4 */
if(!s->budget--) { s->failed_pc=0x0c03cba4u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cba6;
P_0c03cba6: /* original f0f2, guest PC 0x0c03cba6 */
if(!s->budget--) { s->failed_pc=0x0c03cba6u; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[15],r[18],'*');
goto P_0c03cba8;
P_0c03cba8: /* original f1f2, guest PC 0x0c03cba8 */
if(!s->budget--) { s->failed_pc=0x0c03cba8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[15],r[18],'*');
goto P_0c03cbaa;
P_0c03cbaa: /* original f2f2, guest PC 0x0c03cbaa */
if(!s->budget--) { s->failed_pc=0x0c03cbaau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[15],r[18],'*');
goto P_0c03cbac;
P_0c03cbac: /* original f3f2, guest PC 0x0c03cbac */
if(!s->budget--) { s->failed_pc=0x0c03cbacu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'*');
goto P_0c03cbae;
P_0c03cbae: /* original ff49, guest PC 0x0c03cbae */
if(!s->budget--) { s->failed_pc=0x0c03cbaeu; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cbb0;
P_0c03cbb0: /* original f4f2, guest PC 0x0c03cbb0 */
if(!s->budget--) { s->failed_pc=0x0c03cbb0u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[15],r[18],'*');
goto P_0c03cbb2;
P_0c03cbb2: /* original f5f2, guest PC 0x0c03cbb2 */
if(!s->budget--) { s->failed_pc=0x0c03cbb2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[15],r[18],'*');
goto P_0c03cbb4;
P_0c03cbb4: /* original f6f2, guest PC 0x0c03cbb4 */
if(!s->budget--) { s->failed_pc=0x0c03cbb4u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c03cbb6;
P_0c03cbb6: /* original f7f2, guest PC 0x0c03cbb6 */
if(!s->budget--) { s->failed_pc=0x0c03cbb6u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[15],r[18],'*');
goto P_0c03cbb8;
P_0c03cbb8: /* original ff49, guest PC 0x0c03cbb8 */
if(!s->budget--) { s->failed_pc=0x0c03cbb8u; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cbba;
P_0c03cbba: /* original f8f2, guest PC 0x0c03cbba */
if(!s->budget--) { s->failed_pc=0x0c03cbbau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[15],r[18],'*');
goto P_0c03cbbc;
P_0c03cbbc: /* original f9f2, guest PC 0x0c03cbbc */
if(!s->budget--) { s->failed_pc=0x0c03cbbcu; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[15],r[18],'*');
goto P_0c03cbbe;
P_0c03cbbe: /* original faf2, guest PC 0x0c03cbbe */
if(!s->budget--) { s->failed_pc=0x0c03cbbeu; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[15],r[18],'*');
goto P_0c03cbc0;
P_0c03cbc0: /* original fbf2, guest PC 0x0c03cbc0 */
if(!s->budget--) { s->failed_pc=0x0c03cbc0u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[15],r[18],'*');
goto P_0c03cbc2;
P_0c03cbc2: /* original ff0d, guest PC 0x0c03cbc2 */
if(!s->budget--) { s->failed_pc=0x0c03cbc2u; return 0; }
fr[15]=r[53];
goto P_0c03cbc4;
P_0c03cbc4: /* original fbfd, guest PC 0x0c03cbc4 */
if(!s->budget--) { s->failed_pc=0x0c03cbc4u; return 0; }
vf3_matrix_swap(s);
goto P_0c03cbc6;
P_0c03cbc6: /* original 0009, guest PC 0x0c03cbc6 */
if(!s->budget--) { s->failed_pc=0x0c03cbc6u; return 0; }
goto P_0c03cbc8;
P_0c03cbc8: /* original 000b, guest PC 0x0c03cbc8 */
if(!s->budget--) { s->failed_pc=0x0c03cbc8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cbca: /* original 0009, guest PC 0x0c03cbca */
if(!s->budget--) { s->failed_pc=0x0c03cbcau; return 0; }
if(!vf3_matrix_family(0x0c03cbccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cbccu; return 0; } return 1;
P_0c03cd70: /* original f049, guest PC 0x0c03cd70 */
if(!s->budget--) { s->failed_pc=0x0c03cd70u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd72;
P_0c03cd72: /* original f149, guest PC 0x0c03cd72 */
if(!s->budget--) { s->failed_pc=0x0c03cd72u; return 0; }
vf3_matrix_load(s,ram,1,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd74;
P_0c03cd74: /* original f249, guest PC 0x0c03cd74 */
if(!s->budget--) { s->failed_pc=0x0c03cd74u; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd76;
P_0c03cd76: /* original f38d, guest PC 0x0c03cd76 */
if(!s->budget--) { s->failed_pc=0x0c03cd76u; return 0; }
fr[3]=0;
goto P_0c03cd78;
P_0c03cd78: /* original f459, guest PC 0x0c03cd78 */
if(!s->budget--) { s->failed_pc=0x0c03cd78u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd7a;
P_0c03cd7a: /* original f559, guest PC 0x0c03cd7a */
if(!s->budget--) { s->failed_pc=0x0c03cd7au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd7c;
P_0c03cd7c: /* original f659, guest PC 0x0c03cd7c */
if(!s->budget--) { s->failed_pc=0x0c03cd7cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cd7e;
P_0c03cd7e: /* original f78d, guest PC 0x0c03cd7e */
if(!s->budget--) { s->failed_pc=0x0c03cd7eu; return 0; }
fr[7]=0;
goto P_0c03cd80;
P_0c03cd80: /* original f4ed, guest PC 0x0c03cd80 */
if(!s->budget--) { s->failed_pc=0x0c03cd80u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03cd82;
P_0c03cd82: /* original f07c, guest PC 0x0c03cd82 */
if(!s->budget--) { s->failed_pc=0x0c03cd82u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03cd84;
P_0c03cd84: /* original 000b, guest PC 0x0c03cd84 */
if(!s->budget--) { s->failed_pc=0x0c03cd84u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cd86: /* original 0009, guest PC 0x0c03cd86 */
if(!s->budget--) { s->failed_pc=0x0c03cd86u; return 0; }
if(!vf3_matrix_family(0x0c03cd88u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cd88u; return 0; } return 1;
P_0c03cdb0: /* original f049, guest PC 0x0c03cdb0 */
if(!s->budget--) { s->failed_pc=0x0c03cdb0u; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdb2;
P_0c03cdb2: /* original f549, guest PC 0x0c03cdb2 */
if(!s->budget--) { s->failed_pc=0x0c03cdb2u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdb4;
P_0c03cdb4: /* original f648, guest PC 0x0c03cdb4 */
if(!s->budget--) { s->failed_pc=0x0c03cdb4u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c03cdb6;
P_0c03cdb6: /* original f859, guest PC 0x0c03cdb6 */
if(!s->budget--) { s->failed_pc=0x0c03cdb6u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdb8;
P_0c03cdb8: /* original f959, guest PC 0x0c03cdb8 */
if(!s->budget--) { s->failed_pc=0x0c03cdb8u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03cdba;
P_0c03cdba: /* original fa58, guest PC 0x0c03cdba */
if(!s->budget--) { s->failed_pc=0x0c03cdbau; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
goto P_0c03cdbc;
P_0c03cdbc: /* original 760c, guest PC 0x0c03cdbc */
if(!s->budget--) { s->failed_pc=0x0c03cdbcu; return 0; }
r[6]+=0x0000000cu;
goto P_0c03cdbe;
P_0c03cdbe: /* original f35c, guest PC 0x0c03cdbe */
if(!s->budget--) { s->failed_pc=0x0c03cdbeu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c03cdc0;
P_0c03cdc0: /* original f382, guest PC 0x0c03cdc0 */
if(!s->budget--) { s->failed_pc=0x0c03cdc0u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[8],r[18],'*');
goto P_0c03cdc2;
P_0c03cdc2: /* original f20c, guest PC 0x0c03cdc2 */
if(!s->budget--) { s->failed_pc=0x0c03cdc2u; return 0; }
vf3_matrix_move(s,2,0);
goto P_0c03cdc4;
P_0c03cdc4: /* original f2a2, guest PC 0x0c03cdc4 */
if(!s->budget--) { s->failed_pc=0x0c03cdc4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[10],r[18],'*');
goto P_0c03cdc6;
P_0c03cdc6: /* original f16c, guest PC 0x0c03cdc6 */
if(!s->budget--) { s->failed_pc=0x0c03cdc6u; return 0; }
vf3_matrix_move(s,1,6);
goto P_0c03cdc8;
P_0c03cdc8: /* original f192, guest PC 0x0c03cdc8 */
if(!s->budget--) { s->failed_pc=0x0c03cdc8u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[9],r[18],'*');
goto P_0c03cdca;
P_0c03cdca: /* original f34d, guest PC 0x0c03cdca */
if(!s->budget--) { s->failed_pc=0x0c03cdcau; return 0; }
fr[3]^=0x80000000u;
goto P_0c03cdcc;
P_0c03cdcc: /* original f39e, guest PC 0x0c03cdcc */
if(!s->budget--) { s->failed_pc=0x0c03cdccu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c03cdce;
P_0c03cdce: /* original f24d, guest PC 0x0c03cdce */
if(!s->budget--) { s->failed_pc=0x0c03cdceu; return 0; }
fr[2]^=0x80000000u;
goto P_0c03cdd0;
P_0c03cdd0: /* original f06c, guest PC 0x0c03cdd0 */
if(!s->budget--) { s->failed_pc=0x0c03cdd0u; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c03cdd2;
P_0c03cdd2: /* original f28e, guest PC 0x0c03cdd2 */
if(!s->budget--) { s->failed_pc=0x0c03cdd2u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c03cdd4;
P_0c03cdd4: /* original f14d, guest PC 0x0c03cdd4 */
if(!s->budget--) { s->failed_pc=0x0c03cdd4u; return 0; }
fr[1]^=0x80000000u;
goto P_0c03cdd6;
P_0c03cdd6: /* original f63b, guest PC 0x0c03cdd6 */
if(!s->budget--) { s->failed_pc=0x0c03cdd6u; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,3,r[6]);
goto P_0c03cdd8;
P_0c03cdd8: /* original f05c, guest PC 0x0c03cdd8 */
if(!s->budget--) { s->failed_pc=0x0c03cdd8u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c03cdda;
P_0c03cdda: /* original f1ae, guest PC 0x0c03cdda */
if(!s->budget--) { s->failed_pc=0x0c03cddau; return 0; }
fr[1]=vf3_fpu_mac(fr[0],fr[10],fr[1],r[18]);
goto P_0c03cddc;
P_0c03cddc: /* original f62b, guest PC 0x0c03cddc */
if(!s->budget--) { s->failed_pc=0x0c03cddcu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,2,r[6]);
goto P_0c03cdde;
P_0c03cdde: /* original f61b, guest PC 0x0c03cdde */
if(!s->budget--) { s->failed_pc=0x0c03cddeu; return 0; }
r[6]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,1,r[6]);
goto P_0c03cde0;
P_0c03cde0: /* original 000b, guest PC 0x0c03cde0 */
if(!s->budget--) { s->failed_pc=0x0c03cde0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03cde2: /* original 0009, guest PC 0x0c03cde2 */
if(!s->budget--) { s->failed_pc=0x0c03cde2u; return 0; }
if(!vf3_matrix_family(0x0c03cde4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03cde4u; return 0; } return 1;
P_0c03d040: /* original 7ffc, guest PC 0x0c03d040 */
if(!s->budget--) { s->failed_pc=0x0c03d040u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03d042;
P_0c03d042: /* original 6543, guest PC 0x0c03d042 */
if(!s->budget--) { s->failed_pc=0x0c03d042u; return 0; }
r[5]=r[4];
goto P_0c03d044;
P_0c03d044: /* original 2f42, guest PC 0x0c03d044 */
if(!s->budget--) { s->failed_pc=0x0c03d044u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c03d046;
P_0c03d046: /* original a00b, guest PC 0x0c03d046 */
if(!s->budget--) { s->failed_pc=0x0c03d046u; return 0; }
goto P_0c03d060;
P_0c03d048: /* original 0009, guest PC 0x0c03d048 */
if(!s->budget--) { s->failed_pc=0x0c03d048u; return 0; }
if(!vf3_matrix_family(0x0c03d04au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d04au; return 0; } return 1;
P_0c03d060: /* original f449, guest PC 0x0c03d060 */
if(!s->budget--) { s->failed_pc=0x0c03d060u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d062;
P_0c03d062: /* original f549, guest PC 0x0c03d062 */
if(!s->budget--) { s->failed_pc=0x0c03d062u; return 0; }
vf3_matrix_load(s,ram,5,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d064;
P_0c03d064: /* original f649, guest PC 0x0c03d064 */
if(!s->budget--) { s->failed_pc=0x0c03d064u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03d066;
P_0c03d066: /* original f78d, guest PC 0x0c03d066 */
if(!s->budget--) { s->failed_pc=0x0c03d066u; return 0; }
fr[7]=0;
goto P_0c03d068;
P_0c03d068: /* original 750c, guest PC 0x0c03d068 */
if(!s->budget--) { s->failed_pc=0x0c03d068u; return 0; }
r[5]+=0x0000000cu;
goto P_0c03d06a;
P_0c03d06a: /* original f5ed, guest PC 0x0c03d06a */
if(!s->budget--) { s->failed_pc=0x0c03d06au; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03d06c;
P_0c03d06c: /* original f07c, guest PC 0x0c03d06c */
if(!s->budget--) { s->failed_pc=0x0c03d06cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c03d06e;
P_0c03d06e: /* original f06d, guest PC 0x0c03d06e */
if(!s->budget--) { s->failed_pc=0x0c03d06eu; return 0; }
fr[0]=vf3_fpu_sqrt(fr[0],r[18]);
goto P_0c03d070;
P_0c03d070: /* original f77d, guest PC 0x0c03d070 */
if(!s->budget--) { s->failed_pc=0x0c03d070u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03d072;
P_0c03d072: /* original f672, guest PC 0x0c03d072 */
if(!s->budget--) { s->failed_pc=0x0c03d072u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03d074;
P_0c03d074: /* original f572, guest PC 0x0c03d074 */
if(!s->budget--) { s->failed_pc=0x0c03d074u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03d076;
P_0c03d076: /* original f472, guest PC 0x0c03d076 */
if(!s->budget--) { s->failed_pc=0x0c03d076u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03d078;
P_0c03d078: /* original f56b, guest PC 0x0c03d078 */
if(!s->budget--) { s->failed_pc=0x0c03d078u; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,6,r[5]);
goto P_0c03d07a;
P_0c03d07a: /* original f55b, guest PC 0x0c03d07a */
if(!s->budget--) { s->failed_pc=0x0c03d07au; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,5,r[5]);
goto P_0c03d07c;
P_0c03d07c: /* original f54b, guest PC 0x0c03d07c */
if(!s->budget--) { s->failed_pc=0x0c03d07cu; return 0; }
r[5]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,4,r[5]);
goto P_0c03d07e;
P_0c03d07e: /* original 0009, guest PC 0x0c03d07e */
if(!s->budget--) { s->failed_pc=0x0c03d07eu; return 0; }
goto P_0c03d080;
P_0c03d080: /* original 000b, guest PC 0x0c03d080 */
if(!s->budget--) { s->failed_pc=0x0c03d080u; return 0; }
target=r[16];
r[15]+=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c03d082: /* original 7f04, guest PC 0x0c03d082 */
if(!s->budget--) { s->failed_pc=0x0c03d082u; return 0; }
r[15]+=0x00000004u;
if(!vf3_matrix_family(0x0c03d084u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d084u; return 0; } return 1;
P_0c03d260: /* original 4f22, guest PC 0x0c03d260 */
if(!s->budget--) { s->failed_pc=0x0c03d260u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03d262;
P_0c03d262: /* original d347, guest PC 0x0c03d262 */
if(!s->budget--) { s->failed_pc=0x0c03d262u; return 0; }
r[3]=read(ram,0x0c03d380u,4);
goto P_0c03d264;
P_0c03d264: /* original d445, guest PC 0x0c03d264 */
if(!s->budget--) { s->failed_pc=0x0c03d264u; return 0; }
r[4]=read(ram,0x0c03d37cu,4);
goto P_0c03d266;
P_0c03d266: /* original 430b, guest PC 0x0c03d266 */
if(!s->budget--) { s->failed_pc=0x0c03d266u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d26au;
r[4]=read(ram,r[4]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d26au) { target=s->pc; goto dispatch; }
goto P_0c03d26a;
P_0c03d268: /* original 5442, guest PC 0x0c03d268 */
if(!s->budget--) { s->failed_pc=0x0c03d268u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03d26a;
P_0c03d26a: /* original d246, guest PC 0x0c03d26a */
if(!s->budget--) { s->failed_pc=0x0c03d26au; return 0; }
r[2]=read(ram,0x0c03d384u,4);
goto P_0c03d26c;
P_0c03d26c: /* original 420b, guest PC 0x0c03d26c */
if(!s->budget--) { s->failed_pc=0x0c03d26cu; return 0; }
target=r[2];
r[16]=code_base|0x0c03d270u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d270u) { target=s->pc; goto dispatch; }
goto P_0c03d270;
P_0c03d26e: /* original 0009, guest PC 0x0c03d26e */
if(!s->budget--) { s->failed_pc=0x0c03d26eu; return 0; }
goto P_0c03d270;
P_0c03d270: /* original d346, guest PC 0x0c03d270 */
if(!s->budget--) { s->failed_pc=0x0c03d270u; return 0; }
r[3]=read(ram,0x0c03d38cu,4);
goto P_0c03d272;
P_0c03d272: /* original d445, guest PC 0x0c03d272 */
if(!s->budget--) { s->failed_pc=0x0c03d272u; return 0; }
r[4]=read(ram,0x0c03d388u,4);
goto P_0c03d274;
P_0c03d274: /* original 430b, guest PC 0x0c03d274 */
if(!s->budget--) { s->failed_pc=0x0c03d274u; return 0; }
target=r[3];
r[16]=code_base|0x0c03d278u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03d278u) { target=s->pc; goto dispatch; }
goto P_0c03d278;
P_0c03d276: /* original 0009, guest PC 0x0c03d276 */
if(!s->budget--) { s->failed_pc=0x0c03d276u; return 0; }
goto P_0c03d278;
P_0c03d278: /* original d245, guest PC 0x0c03d278 */
if(!s->budget--) { s->failed_pc=0x0c03d278u; return 0; }
r[2]=read(ram,0x0c03d390u,4);
goto P_0c03d27a;
P_0c03d27a: /* original e401, guest PC 0x0c03d27a */
if(!s->budget--) { s->failed_pc=0x0c03d27au; return 0; }
r[4]=0x00000001u;
goto P_0c03d27c;
P_0c03d27c: /* original 422b, guest PC 0x0c03d27c */
if(!s->budget--) { s->failed_pc=0x0c03d27cu; return 0; }
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
P_0c03d27e: /* original 4f26, guest PC 0x0c03d27e */
if(!s->budget--) { s->failed_pc=0x0c03d27eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03d280u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03d280u; return 0; } return 1;
P_0c03dd00: /* original d407, guest PC 0x0c03dd00 */
if(!s->budget--) { s->failed_pc=0x0c03dd00u; return 0; }
r[4]=read(ram,0x0c03dd20u,4);
goto P_0c03dd02;
P_0c03dd02: /* original d502, guest PC 0x0c03dd02 */
if(!s->budget--) { s->failed_pc=0x0c03dd02u; return 0; }
r[5]=read(ram,0x0c03dd0cu,4);
goto P_0c03dd04;
P_0c03dd04: /* original 5442, guest PC 0x0c03dd04 */
if(!s->budget--) { s->failed_pc=0x0c03dd04u; return 0; }
r[4]=read(ram,r[4]+8,4);
goto P_0c03dd06;
P_0c03dd06: /* original a013, guest PC 0x0c03dd06 */
if(!s->budget--) { s->failed_pc=0x0c03dd06u; return 0; }
goto P_0c03dd30;
P_0c03dd08: /* original 0009, guest PC 0x0c03dd08 */
if(!s->budget--) { s->failed_pc=0x0c03dd08u; return 0; }
if(!vf3_matrix_family(0x0c03dd0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd0au; return 0; } return 1;
P_0c03dd30: /* original fffb, guest PC 0x0c03dd30 */
if(!s->budget--) { s->failed_pc=0x0c03dd30u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03dd32;
P_0c03dd32: /* original ffeb, guest PC 0x0c03dd32 */
if(!s->budget--) { s->failed_pc=0x0c03dd32u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c03dd34;
P_0c03dd34: /* original ffdb, guest PC 0x0c03dd34 */
if(!s->budget--) { s->failed_pc=0x0c03dd34u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c03dd36;
P_0c03dd36: /* original ffcb, guest PC 0x0c03dd36 */
if(!s->budget--) { s->failed_pc=0x0c03dd36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c03dd38;
P_0c03dd38: /* original f3fd, guest PC 0x0c03dd38 */
if(!s->budget--) { s->failed_pc=0x0c03dd38u; return 0; }
r[18]^=0x100000u;
goto P_0c03dd3a;
P_0c03dd3a: /* original f049, guest PC 0x0c03dd3a */
if(!s->budget--) { s->failed_pc=0x0c03dd3au; return 0; }
vf3_matrix_load(s,ram,0,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3c;
P_0c03dd3c: /* original f249, guest PC 0x0c03dd3c */
if(!s->budget--) { s->failed_pc=0x0c03dd3cu; return 0; }
vf3_matrix_load(s,ram,2,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd3e;
P_0c03dd3e: /* original f449, guest PC 0x0c03dd3e */
if(!s->budget--) { s->failed_pc=0x0c03dd3eu; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd40;
P_0c03dd40: /* original f649, guest PC 0x0c03dd40 */
if(!s->budget--) { s->failed_pc=0x0c03dd40u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd42;
P_0c03dd42: /* original f849, guest PC 0x0c03dd42 */
if(!s->budget--) { s->failed_pc=0x0c03dd42u; return 0; }
vf3_matrix_load(s,ram,8,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd44;
P_0c03dd44: /* original fa49, guest PC 0x0c03dd44 */
if(!s->budget--) { s->failed_pc=0x0c03dd44u; return 0; }
vf3_matrix_load(s,ram,10,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd46;
P_0c03dd46: /* original fc49, guest PC 0x0c03dd46 */
if(!s->budget--) { s->failed_pc=0x0c03dd46u; return 0; }
vf3_matrix_load(s,ram,12,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd48;
P_0c03dd48: /* original fe49, guest PC 0x0c03dd48 */
if(!s->budget--) { s->failed_pc=0x0c03dd48u; return 0; }
vf3_matrix_load(s,ram,14,r[4]);
r[4]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd4a;
P_0c03dd4a: /* original f3fd, guest PC 0x0c03dd4a */
if(!s->budget--) { s->failed_pc=0x0c03dd4au; return 0; }
r[18]^=0x100000u;
goto P_0c03dd4c;
P_0c03dd4c: /* original fbfd, guest PC 0x0c03dd4c */
if(!s->budget--) { s->failed_pc=0x0c03dd4cu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd4e;
P_0c03dd4e: /* original 6453, guest PC 0x0c03dd4e */
if(!s->budget--) { s->failed_pc=0x0c03dd4eu; return 0; }
r[4]=r[5];
goto P_0c03dd50;
P_0c03dd50: /* original 0483, guest PC 0x0c03dd50 */
if(!s->budget--) { s->failed_pc=0x0c03dd50u; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd52;
P_0c03dd52: /* original f1fd, guest PC 0x0c03dd52 */
if(!s->budget--) { s->failed_pc=0x0c03dd52u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd54;
P_0c03dd54: /* original 7420, guest PC 0x0c03dd54 */
if(!s->budget--) { s->failed_pc=0x0c03dd54u; return 0; }
r[4]+=0x00000020u;
goto P_0c03dd56;
P_0c03dd56: /* original f5fd, guest PC 0x0c03dd56 */
if(!s->budget--) { s->failed_pc=0x0c03dd56u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd58;
P_0c03dd58: /* original f9fd, guest PC 0x0c03dd58 */
if(!s->budget--) { s->failed_pc=0x0c03dd58u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd5a;
P_0c03dd5a: /* original fdfd, guest PC 0x0c03dd5a */
if(!s->budget--) { s->failed_pc=0x0c03dd5au; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd5c;
P_0c03dd5c: /* original 0483, guest PC 0x0c03dd5c */
if(!s->budget--) { s->failed_pc=0x0c03dd5cu; return 0; }
if((r[4]&0xFC000000u)==0xE0000000u) pref(ram,r[4]);
goto P_0c03dd5e;
P_0c03dd5e: /* original fbfd, guest PC 0x0c03dd5e */
if(!s->budget--) { s->failed_pc=0x0c03dd5eu; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd60;
P_0c03dd60: /* original f059, guest PC 0x0c03dd60 */
if(!s->budget--) { s->failed_pc=0x0c03dd60u; return 0; }
vf3_matrix_load(s,ram,0,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd62;
P_0c03dd62: /* original f159, guest PC 0x0c03dd62 */
if(!s->budget--) { s->failed_pc=0x0c03dd62u; return 0; }
vf3_matrix_load(s,ram,1,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd64;
P_0c03dd64: /* original f259, guest PC 0x0c03dd64 */
if(!s->budget--) { s->failed_pc=0x0c03dd64u; return 0; }
vf3_matrix_load(s,ram,2,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd66;
P_0c03dd66: /* original f359, guest PC 0x0c03dd66 */
if(!s->budget--) { s->failed_pc=0x0c03dd66u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd68;
P_0c03dd68: /* original f459, guest PC 0x0c03dd68 */
if(!s->budget--) { s->failed_pc=0x0c03dd68u; return 0; }
vf3_matrix_load(s,ram,4,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6a;
P_0c03dd6a: /* original f559, guest PC 0x0c03dd6a */
if(!s->budget--) { s->failed_pc=0x0c03dd6au; return 0; }
vf3_matrix_load(s,ram,5,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6c;
P_0c03dd6c: /* original f659, guest PC 0x0c03dd6c */
if(!s->budget--) { s->failed_pc=0x0c03dd6cu; return 0; }
vf3_matrix_load(s,ram,6,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd6e;
P_0c03dd6e: /* original f759, guest PC 0x0c03dd6e */
if(!s->budget--) { s->failed_pc=0x0c03dd6eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd70;
P_0c03dd70: /* original f859, guest PC 0x0c03dd70 */
if(!s->budget--) { s->failed_pc=0x0c03dd70u; return 0; }
vf3_matrix_load(s,ram,8,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd72;
P_0c03dd72: /* original f959, guest PC 0x0c03dd72 */
if(!s->budget--) { s->failed_pc=0x0c03dd72u; return 0; }
vf3_matrix_load(s,ram,9,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd74;
P_0c03dd74: /* original fa59, guest PC 0x0c03dd74 */
if(!s->budget--) { s->failed_pc=0x0c03dd74u; return 0; }
vf3_matrix_load(s,ram,10,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd76;
P_0c03dd76: /* original fb59, guest PC 0x0c03dd76 */
if(!s->budget--) { s->failed_pc=0x0c03dd76u; return 0; }
vf3_matrix_load(s,ram,11,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd78;
P_0c03dd78: /* original fc59, guest PC 0x0c03dd78 */
if(!s->budget--) { s->failed_pc=0x0c03dd78u; return 0; }
vf3_matrix_load(s,ram,12,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7a;
P_0c03dd7a: /* original fd59, guest PC 0x0c03dd7a */
if(!s->budget--) { s->failed_pc=0x0c03dd7au; return 0; }
vf3_matrix_load(s,ram,13,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7c;
P_0c03dd7c: /* original fe59, guest PC 0x0c03dd7c */
if(!s->budget--) { s->failed_pc=0x0c03dd7cu; return 0; }
vf3_matrix_load(s,ram,14,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd7e;
P_0c03dd7e: /* original ff59, guest PC 0x0c03dd7e */
if(!s->budget--) { s->failed_pc=0x0c03dd7eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd80;
P_0c03dd80: /* original fbfd, guest PC 0x0c03dd80 */
if(!s->budget--) { s->failed_pc=0x0c03dd80u; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd82;
P_0c03dd82: /* original f1fd, guest PC 0x0c03dd82 */
if(!s->budget--) { s->failed_pc=0x0c03dd82u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+0,r[18],fr+0)) goto unsupported;
goto P_0c03dd84;
P_0c03dd84: /* original f5fd, guest PC 0x0c03dd84 */
if(!s->budget--) { s->failed_pc=0x0c03dd84u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+4,r[18],fr+4)) goto unsupported;
goto P_0c03dd86;
P_0c03dd86: /* original f9fd, guest PC 0x0c03dd86 */
if(!s->budget--) { s->failed_pc=0x0c03dd86u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+8,r[18],fr+8)) goto unsupported;
goto P_0c03dd88;
P_0c03dd88: /* original fdfd, guest PC 0x0c03dd88 */
if(!s->budget--) { s->failed_pc=0x0c03dd88u; return 0; }
if(!vf3_fpu_ftrv(xf,fr+12,r[18],fr+12)) goto unsupported;
goto P_0c03dd8a;
P_0c03dd8a: /* original fbfd, guest PC 0x0c03dd8a */
if(!s->budget--) { s->failed_pc=0x0c03dd8au; return 0; }
vf3_matrix_swap(s);
goto P_0c03dd8c;
P_0c03dd8c: /* original fcf9, guest PC 0x0c03dd8c */
if(!s->budget--) { s->failed_pc=0x0c03dd8cu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd8e;
P_0c03dd8e: /* original fdf9, guest PC 0x0c03dd8e */
if(!s->budget--) { s->failed_pc=0x0c03dd8eu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd90;
P_0c03dd90: /* original fef9, guest PC 0x0c03dd90 */
if(!s->budget--) { s->failed_pc=0x0c03dd90u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd92;
P_0c03dd92: /* original fff9, guest PC 0x0c03dd92 */
if(!s->budget--) { s->failed_pc=0x0c03dd92u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03dd94;
P_0c03dd94: /* original 000b, guest PC 0x0c03dd94 */
if(!s->budget--) { s->failed_pc=0x0c03dd94u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03dd96: /* original 0009, guest PC 0x0c03dd96 */
if(!s->budget--) { s->failed_pc=0x0c03dd96u; return 0; }
if(!vf3_matrix_family(0x0c03dd98u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03dd98u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
