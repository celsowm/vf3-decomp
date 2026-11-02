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
int vf3_away_batch62_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08daa2u: goto P_0c08daa2;
case 0x0c08daa4u: goto P_0c08daa4;
case 0x0c08daa6u: goto P_0c08daa6;
case 0x0c08daa8u: goto P_0c08daa8;
case 0x0c08daaau: goto P_0c08daaa;
case 0x0c08daacu: goto P_0c08daac;
case 0x0c08daaeu: goto P_0c08daae;
case 0x0c08dab0u: goto P_0c08dab0;
case 0x0c08dab2u: goto P_0c08dab2;
case 0x0c08dab4u: goto P_0c08dab4;
case 0x0c08dab6u: goto P_0c08dab6;
case 0x0c08dab8u: goto P_0c08dab8;
case 0x0c08dabau: goto P_0c08daba;
case 0x0c08dabcu: goto P_0c08dabc;
case 0x0c08dabeu: goto P_0c08dabe;
case 0x0c08dac0u: goto P_0c08dac0;
case 0x0c08dac2u: goto P_0c08dac2;
case 0x0c08dac4u: goto P_0c08dac4;
case 0x0c08dac6u: goto P_0c08dac6;
case 0x0c08dac8u: goto P_0c08dac8;
case 0x0c08dacau: goto P_0c08daca;
case 0x0c08daccu: goto P_0c08dacc;
case 0x0c08daceu: goto P_0c08dace;
case 0x0c08dad0u: goto P_0c08dad0;
case 0x0c08dad2u: goto P_0c08dad2;
case 0x0c08dad4u: goto P_0c08dad4;
case 0x0c08dad6u: goto P_0c08dad6;
case 0x0c08dad8u: goto P_0c08dad8;
case 0x0c08daf4u: goto P_0c08daf4;
case 0x0c08daf6u: goto P_0c08daf6;
case 0x0c08daf8u: goto P_0c08daf8;
case 0x0c08dafau: goto P_0c08dafa;
case 0x0c08dafcu: goto P_0c08dafc;
case 0x0c08dafeu: goto P_0c08dafe;
case 0x0c08db00u: goto P_0c08db00;
case 0x0c08db02u: goto P_0c08db02;
case 0x0c08db04u: goto P_0c08db04;
case 0x0c08db06u: goto P_0c08db06;
case 0x0c08db08u: goto P_0c08db08;
case 0x0c08db0au: goto P_0c08db0a;
case 0x0c08db0cu: goto P_0c08db0c;
case 0x0c08db0eu: goto P_0c08db0e;
case 0x0c08db10u: goto P_0c08db10;
case 0x0c08db12u: goto P_0c08db12;
case 0x0c08db14u: goto P_0c08db14;
case 0x0c08db16u: goto P_0c08db16;
case 0x0c08db18u: goto P_0c08db18;
case 0x0c08db1au: goto P_0c08db1a;
case 0x0c08db1cu: goto P_0c08db1c;
case 0x0c08db1eu: goto P_0c08db1e;
case 0x0c08db20u: goto P_0c08db20;
case 0x0c08db22u: goto P_0c08db22;
case 0x0c08db24u: goto P_0c08db24;
case 0x0c08db26u: goto P_0c08db26;
case 0x0c08db28u: goto P_0c08db28;
case 0x0c08db2au: goto P_0c08db2a;
case 0x0c08db2cu: goto P_0c08db2c;
case 0x0c08db2eu: goto P_0c08db2e;
case 0x0c08db30u: goto P_0c08db30;
case 0x0c08db32u: goto P_0c08db32;
case 0x0c08db34u: goto P_0c08db34;
case 0x0c08db36u: goto P_0c08db36;
case 0x0c08db38u: goto P_0c08db38;
case 0x0c08db3au: goto P_0c08db3a;
case 0x0c08db3cu: goto P_0c08db3c;
case 0x0c08db3eu: goto P_0c08db3e;
case 0x0c08db40u: goto P_0c08db40;
case 0x0c08db42u: goto P_0c08db42;
case 0x0c08db44u: goto P_0c08db44;
case 0x0c08db46u: goto P_0c08db46;
case 0x0c08db48u: goto P_0c08db48;
case 0x0c08db4au: goto P_0c08db4a;
case 0x0c08db4cu: goto P_0c08db4c;
case 0x0c08db4eu: goto P_0c08db4e;
case 0x0c08db50u: goto P_0c08db50;
case 0x0c08db52u: goto P_0c08db52;
case 0x0c08db54u: goto P_0c08db54;
case 0x0c08db56u: goto P_0c08db56;
case 0x0c08db58u: goto P_0c08db58;
case 0x0c08db5au: goto P_0c08db5a;
case 0x0c08db5cu: goto P_0c08db5c;
case 0x0c08db5eu: goto P_0c08db5e;
case 0x0c08db60u: goto P_0c08db60;
case 0x0c08db62u: goto P_0c08db62;
case 0x0c08db64u: goto P_0c08db64;
case 0x0c08db66u: goto P_0c08db66;
case 0x0c08db68u: goto P_0c08db68;
case 0x0c08db6au: goto P_0c08db6a;
case 0x0c08db6cu: goto P_0c08db6c;
case 0x0c08db6eu: goto P_0c08db6e;
case 0x0c08dbe4u: goto P_0c08dbe4;
case 0x0c08dbe6u: goto P_0c08dbe6;
case 0x0c08dbe8u: goto P_0c08dbe8;
case 0x0c08dbeau: goto P_0c08dbea;
case 0x0c08dbecu: goto P_0c08dbec;
case 0x0c08dbeeu: goto P_0c08dbee;
case 0x0c08dbf0u: goto P_0c08dbf0;
case 0x0c08dbf2u: goto P_0c08dbf2;
case 0x0c08dbf4u: goto P_0c08dbf4;
case 0x0c08dbf6u: goto P_0c08dbf6;
case 0x0c08dbf8u: goto P_0c08dbf8;
case 0x0c08dbfau: goto P_0c08dbfa;
case 0x0c08dbfcu: goto P_0c08dbfc;
case 0x0c08dbfeu: goto P_0c08dbfe;
case 0x0c08dc00u: goto P_0c08dc00;
case 0x0c08dc02u: goto P_0c08dc02;
case 0x0c08dc04u: goto P_0c08dc04;
case 0x0c08dc06u: goto P_0c08dc06;
case 0x0c08dc08u: goto P_0c08dc08;
case 0x0c08dc0au: goto P_0c08dc0a;
case 0x0c08dc0cu: goto P_0c08dc0c;
case 0x0c08dc0eu: goto P_0c08dc0e;
case 0x0c08dc10u: goto P_0c08dc10;
case 0x0c08dc12u: goto P_0c08dc12;
case 0x0c08dc14u: goto P_0c08dc14;
case 0x0c08dc16u: goto P_0c08dc16;
case 0x0c08dc18u: goto P_0c08dc18;
case 0x0c08dc1au: goto P_0c08dc1a;
case 0x0c08dc1cu: goto P_0c08dc1c;
case 0x0c08dc1eu: goto P_0c08dc1e;
case 0x0c08dc20u: goto P_0c08dc20;
case 0x0c08dc22u: goto P_0c08dc22;
case 0x0c08dc24u: goto P_0c08dc24;
case 0x0c08dc26u: goto P_0c08dc26;
case 0x0c08dc28u: goto P_0c08dc28;
case 0x0c08dc2au: goto P_0c08dc2a;
case 0x0c08dc2cu: goto P_0c08dc2c;
case 0x0c08dc2eu: goto P_0c08dc2e;
case 0x0c08dc30u: goto P_0c08dc30;
case 0x0c08dc32u: goto P_0c08dc32;
case 0x0c08dc34u: goto P_0c08dc34;
case 0x0c08dc36u: goto P_0c08dc36;
case 0x0c08dc38u: goto P_0c08dc38;
case 0x0c08dc3au: goto P_0c08dc3a;
case 0x0c08dc3cu: goto P_0c08dc3c;
case 0x0c08dc4cu: goto P_0c08dc4c;
case 0x0c08dc4eu: goto P_0c08dc4e;
case 0x0c08dc50u: goto P_0c08dc50;
case 0x0c08dc52u: goto P_0c08dc52;
case 0x0c08dc54u: goto P_0c08dc54;
case 0x0c08dc56u: goto P_0c08dc56;
case 0x0c08dc58u: goto P_0c08dc58;
case 0x0c08dc5au: goto P_0c08dc5a;
case 0x0c08dc5cu: goto P_0c08dc5c;
case 0x0c08dc5eu: goto P_0c08dc5e;
case 0x0c08dc60u: goto P_0c08dc60;
case 0x0c08dc62u: goto P_0c08dc62;
case 0x0c08dc64u: goto P_0c08dc64;
case 0x0c08dc66u: goto P_0c08dc66;
case 0x0c08dc68u: goto P_0c08dc68;
case 0x0c08dc6au: goto P_0c08dc6a;
case 0x0c08dc6cu: goto P_0c08dc6c;
case 0x0c08dc6eu: goto P_0c08dc6e;
case 0x0c08dc70u: goto P_0c08dc70;
case 0x0c08dc72u: goto P_0c08dc72;
case 0x0c08dc74u: goto P_0c08dc74;
case 0x0c08dc76u: goto P_0c08dc76;
case 0x0c08dc78u: goto P_0c08dc78;
case 0x0c08dc7au: goto P_0c08dc7a;
case 0x0c08dc7cu: goto P_0c08dc7c;
case 0x0c08dc7eu: goto P_0c08dc7e;
case 0x0c08dc80u: goto P_0c08dc80;
case 0x0c08dc82u: goto P_0c08dc82;
case 0x0c08dc84u: goto P_0c08dc84;
case 0x0c08dc86u: goto P_0c08dc86;
case 0x0c08dc88u: goto P_0c08dc88;
case 0x0c08dc8au: goto P_0c08dc8a;
case 0x0c08dc8cu: goto P_0c08dc8c;
case 0x0c08dc8eu: goto P_0c08dc8e;
case 0x0c08dc90u: goto P_0c08dc90;
case 0x0c08dc92u: goto P_0c08dc92;
case 0x0c08dc94u: goto P_0c08dc94;
case 0x0c08dc96u: goto P_0c08dc96;
case 0x0c08dc98u: goto P_0c08dc98;
case 0x0c08dc9au: goto P_0c08dc9a;
case 0x0c08dc9cu: goto P_0c08dc9c;
case 0x0c08dc9eu: goto P_0c08dc9e;
case 0x0c08dca0u: goto P_0c08dca0;
case 0x0c08dca2u: goto P_0c08dca2;
case 0x0c08dca4u: goto P_0c08dca4;
case 0x0c08dca6u: goto P_0c08dca6;
case 0x0c08dca8u: goto P_0c08dca8;
case 0x0c08dcaau: goto P_0c08dcaa;
case 0x0c08dcacu: goto P_0c08dcac;
case 0x0c08dcaeu: goto P_0c08dcae;
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
default: return vf3_matrix_family(target,s,ram);
}
P_0c08daa2: /* original 901c, guest PC 0x0c08daa2 */
if(!s->budget--) { s->failed_pc=0x0c08daa2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dadeu,2);
goto P_0c08daa4;
P_0c08daa4: /* original 4f22, guest PC 0x0c08daa4 */
if(!s->budget--) { s->failed_pc=0x0c08daa4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08daa6;
P_0c08daa6: /* original 034d, guest PC 0x0c08daa6 */
if(!s->budget--) { s->failed_pc=0x0c08daa6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08daa8;
P_0c08daa8: /* original 7ff4, guest PC 0x0c08daa8 */
if(!s->budget--) { s->failed_pc=0x0c08daa8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c08daaa;
P_0c08daaa: /* original 2f32, guest PC 0x0c08daaa */
if(!s->budget--) { s->failed_pc=0x0c08daaau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c08daac;
P_0c08daac: /* original 9018, guest PC 0x0c08daac */
if(!s->budget--) { s->failed_pc=0x0c08daacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dae0u,2);
goto P_0c08daae;
P_0c08daae: /* original 024d, guest PC 0x0c08daae */
if(!s->budget--) { s->failed_pc=0x0c08daaeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dab0;
P_0c08dab0: /* original 1f21, guest PC 0x0c08dab0 */
if(!s->budget--) { s->failed_pc=0x0c08dab0u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c08dab2;
P_0c08dab2: /* original 9016, guest PC 0x0c08dab2 */
if(!s->budget--) { s->failed_pc=0x0c08dab2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dae2u,2);
goto P_0c08dab4;
P_0c08dab4: /* original 034d, guest PC 0x0c08dab4 */
if(!s->budget--) { s->failed_pc=0x0c08dab4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dab6;
P_0c08dab6: /* original 1f32, guest PC 0x0c08dab6 */
if(!s->budget--) { s->failed_pc=0x0c08dab6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c08dab8;
P_0c08dab8: /* original 9014, guest PC 0x0c08dab8 */
if(!s->budget--) { s->failed_pc=0x0c08dab8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dae4u,2);
goto P_0c08daba;
P_0c08daba: /* original 074d, guest PC 0x0c08daba */
if(!s->budget--) { s->failed_pc=0x0c08dabau; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dabc;
P_0c08dabc: /* original 7002, guest PC 0x0c08dabc */
if(!s->budget--) { s->failed_pc=0x0c08dabcu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dabe;
P_0c08dabe: /* original 064d, guest PC 0x0c08dabe */
if(!s->budget--) { s->failed_pc=0x0c08dabeu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dac0;
P_0c08dac0: /* original 7002, guest PC 0x0c08dac0 */
if(!s->budget--) { s->failed_pc=0x0c08dac0u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dac2;
P_0c08dac2: /* original 054d, guest PC 0x0c08dac2 */
if(!s->budget--) { s->failed_pc=0x0c08dac2u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08dac4;
P_0c08dac4: /* original 2f56, guest PC 0x0c08dac4 */
if(!s->budget--) { s->failed_pc=0x0c08dac4u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dac6;
P_0c08dac6: /* original 2f66, guest PC 0x0c08dac6 */
if(!s->budget--) { s->failed_pc=0x0c08dac6u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dac8;
P_0c08dac8: /* original 2f76, guest PC 0x0c08dac8 */
if(!s->budget--) { s->failed_pc=0x0c08dac8u; return 0; }
tmp=r[7]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08daca;
P_0c08daca: /* original 56f4, guest PC 0x0c08daca */
if(!s->budget--) { s->failed_pc=0x0c08dacau; return 0; }
r[6]=read(ram,r[15]+16,4);
goto P_0c08dacc;
P_0c08dacc: /* original 57f5, guest PC 0x0c08dacc */
if(!s->budget--) { s->failed_pc=0x0c08daccu; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08dace;
P_0c08dace: /* original b20a, guest PC 0x0c08dace */
if(!s->budget--) { s->failed_pc=0x0c08daceu; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08dad2u;
r[5]=read(ram,r[15]+12,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dad2u) { target=s->pc; goto dispatch; }
goto P_0c08dad2;
P_0c08dad0: /* original 55f3, guest PC 0x0c08dad0 */
if(!s->budget--) { s->failed_pc=0x0c08dad0u; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c08dad2;
P_0c08dad2: /* original 7f18, guest PC 0x0c08dad2 */
if(!s->budget--) { s->failed_pc=0x0c08dad2u; return 0; }
r[15]+=0x00000018u;
goto P_0c08dad4;
P_0c08dad4: /* original 4f26, guest PC 0x0c08dad4 */
if(!s->budget--) { s->failed_pc=0x0c08dad4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dad6;
P_0c08dad6: /* original 000b, guest PC 0x0c08dad6 */
if(!s->budget--) { s->failed_pc=0x0c08dad6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c08dad8: /* original 0009, guest PC 0x0c08dad8 */
if(!s->budget--) { s->failed_pc=0x0c08dad8u; return 0; }
if(!vf3_matrix_family(0x0c08dadau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08dadau; return 0; } return 1;
P_0c08daf4: /* original 2fe6, guest PC 0x0c08daf4 */
if(!s->budget--) { s->failed_pc=0x0c08daf4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08daf6;
P_0c08daf6: /* original 6e43, guest PC 0x0c08daf6 */
if(!s->budget--) { s->failed_pc=0x0c08daf6u; return 0; }
r[14]=r[4];
goto P_0c08daf8;
P_0c08daf8: /* original 90a1, guest PC 0x0c08daf8 */
if(!s->budget--) { s->failed_pc=0x0c08daf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc3eu,2);
goto P_0c08dafa;
P_0c08dafa: /* original 4f22, guest PC 0x0c08dafa */
if(!s->budget--) { s->failed_pc=0x0c08dafau; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08dafc;
P_0c08dafc: /* original f356, guest PC 0x0c08dafc */
if(!s->budget--) { s->failed_pc=0x0c08dafcu; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08dafe;
P_0c08dafe: /* original e01c, guest PC 0x0c08dafe */
if(!s->budget--) { s->failed_pc=0x0c08dafeu; return 0; }
r[0]=0x0000001cu;
goto P_0c08db00;
P_0c08db00: /* original 7fe0, guest PC 0x0c08db00 */
if(!s->budget--) { s->failed_pc=0x0c08db00u; return 0; }
r[15]+=0xffffffe0u;
goto P_0c08db02;
P_0c08db02: /* original ff37, guest PC 0x0c08db02 */
if(!s->budget--) { s->failed_pc=0x0c08db02u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08db04;
P_0c08db04: /* original 66f3, guest PC 0x0c08db04 */
if(!s->budget--) { s->failed_pc=0x0c08db04u; return 0; }
r[6]=r[15];
goto P_0c08db06;
P_0c08db06: /* original 909b, guest PC 0x0c08db06 */
if(!s->budget--) { s->failed_pc=0x0c08db06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc40u,2);
goto P_0c08db08;
P_0c08db08: /* original 7614, guest PC 0x0c08db08 */
if(!s->budget--) { s->failed_pc=0x0c08db08u; return 0; }
r[6]+=0x00000014u;
goto P_0c08db0a;
P_0c08db0a: /* original f356, guest PC 0x0c08db0a */
if(!s->budget--) { s->failed_pc=0x0c08db0au; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c08db0c;
P_0c08db0c: /* original e018, guest PC 0x0c08db0c */
if(!s->budget--) { s->failed_pc=0x0c08db0cu; return 0; }
r[0]=0x00000018u;
goto P_0c08db0e;
P_0c08db0e: /* original ff37, guest PC 0x0c08db0e */
if(!s->budget--) { s->failed_pc=0x0c08db0eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08db10;
P_0c08db10: /* original 9097, guest PC 0x0c08db10 */
if(!s->budget--) { s->failed_pc=0x0c08db10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc42u,2);
goto P_0c08db12;
P_0c08db12: /* original f53c, guest PC 0x0c08db12 */
if(!s->budget--) { s->failed_pc=0x0c08db12u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c08db14;
P_0c08db14: /* original f656, guest PC 0x0c08db14 */
if(!s->budget--) { s->failed_pc=0x0c08db14u; return 0; }
vf3_matrix_load(s,ram,6,r[5]+r[0]);
goto P_0c08db16;
P_0c08db16: /* original e01c, guest PC 0x0c08db16 */
if(!s->budget--) { s->failed_pc=0x0c08db16u; return 0; }
r[0]=0x0000001cu;
goto P_0c08db18;
P_0c08db18: /* original 65f3, guest PC 0x0c08db18 */
if(!s->budget--) { s->failed_pc=0x0c08db18u; return 0; }
r[5]=r[15];
goto P_0c08db1a;
P_0c08db1a: /* original f4f6, guest PC 0x0c08db1a */
if(!s->budget--) { s->failed_pc=0x0c08db1au; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c08db1c;
P_0c08db1c: /* original 7510, guest PC 0x0c08db1c */
if(!s->budget--) { s->failed_pc=0x0c08db1cu; return 0; }
r[5]+=0x00000010u;
goto P_0c08db1e;
P_0c08db1e: /* original b157, guest PC 0x0c08db1e */
if(!s->budget--) { s->failed_pc=0x0c08db1eu; return 0; }
target=code_base|0x0c08ddd0u; r[16]=code_base|0x0c08db22u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db22u) { target=s->pc; goto dispatch; }
goto P_0c08db22;
P_0c08db20: /* original 64e3, guest PC 0x0c08db20 */
if(!s->budget--) { s->failed_pc=0x0c08db20u; return 0; }
r[4]=r[14];
goto P_0c08db22;
P_0c08db22: /* original 62f3, guest PC 0x0c08db22 */
if(!s->budget--) { s->failed_pc=0x0c08db22u; return 0; }
r[2]=r[15];
goto P_0c08db24;
P_0c08db24: /* original 720c, guest PC 0x0c08db24 */
if(!s->budget--) { s->failed_pc=0x0c08db24u; return 0; }
r[2]+=0x0000000cu;
goto P_0c08db26;
P_0c08db26: /* original 2f26, guest PC 0x0c08db26 */
if(!s->budget--) { s->failed_pc=0x0c08db26u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db28;
P_0c08db28: /* original 63f3, guest PC 0x0c08db28 */
if(!s->budget--) { s->failed_pc=0x0c08db28u; return 0; }
r[3]=r[15];
goto P_0c08db2a;
P_0c08db2a: /* original 730c, guest PC 0x0c08db2a */
if(!s->budget--) { s->failed_pc=0x0c08db2au; return 0; }
r[3]+=0x0000000cu;
goto P_0c08db2c;
P_0c08db2c: /* original 2f36, guest PC 0x0c08db2c */
if(!s->budget--) { s->failed_pc=0x0c08db2cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db2e;
P_0c08db2e: /* original 66f3, guest PC 0x0c08db2e */
if(!s->budget--) { s->failed_pc=0x0c08db2eu; return 0; }
r[6]=r[15];
goto P_0c08db30;
P_0c08db30: /* original 55f7, guest PC 0x0c08db30 */
if(!s->budget--) { s->failed_pc=0x0c08db30u; return 0; }
r[5]=read(ram,r[15]+28,4);
goto P_0c08db32;
P_0c08db32: /* original 67f3, guest PC 0x0c08db32 */
if(!s->budget--) { s->failed_pc=0x0c08db32u; return 0; }
r[7]=r[15];
goto P_0c08db34;
P_0c08db34: /* original 7608, guest PC 0x0c08db34 */
if(!s->budget--) { s->failed_pc=0x0c08db34u; return 0; }
r[6]+=0x00000008u;
goto P_0c08db36;
P_0c08db36: /* original 770c, guest PC 0x0c08db36 */
if(!s->budget--) { s->failed_pc=0x0c08db36u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08db38;
P_0c08db38: /* original b0ba, guest PC 0x0c08db38 */
if(!s->budget--) { s->failed_pc=0x0c08db38u; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08db3cu;
r[4]=read(ram,r[15]+24,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db3cu) { target=s->pc; goto dispatch; }
goto P_0c08db3c;
P_0c08db3a: /* original 54f6, guest PC 0x0c08db3a */
if(!s->budget--) { s->failed_pc=0x0c08db3au; return 0; }
r[4]=read(ram,r[15]+24,4);
goto P_0c08db3c;
P_0c08db3c: /* original 62f3, guest PC 0x0c08db3c */
if(!s->budget--) { s->failed_pc=0x0c08db3cu; return 0; }
r[2]=r[15];
goto P_0c08db3e;
P_0c08db3e: /* original 7214, guest PC 0x0c08db3e */
if(!s->budget--) { s->failed_pc=0x0c08db3eu; return 0; }
r[2]+=0x00000014u;
goto P_0c08db40;
P_0c08db40: /* original 2f26, guest PC 0x0c08db40 */
if(!s->budget--) { s->failed_pc=0x0c08db40u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db42;
P_0c08db42: /* original 66f3, guest PC 0x0c08db42 */
if(!s->budget--) { s->failed_pc=0x0c08db42u; return 0; }
r[6]=r[15];
goto P_0c08db44;
P_0c08db44: /* original 65f3, guest PC 0x0c08db44 */
if(!s->budget--) { s->failed_pc=0x0c08db44u; return 0; }
r[5]=r[15];
goto P_0c08db46;
P_0c08db46: /* original 67f3, guest PC 0x0c08db46 */
if(!s->budget--) { s->failed_pc=0x0c08db46u; return 0; }
r[7]=r[15];
goto P_0c08db48;
P_0c08db48: /* original 750c, guest PC 0x0c08db48 */
if(!s->budget--) { s->failed_pc=0x0c08db48u; return 0; }
r[5]+=0x0000000cu;
goto P_0c08db4a;
P_0c08db4a: /* original 7714, guest PC 0x0c08db4a */
if(!s->budget--) { s->failed_pc=0x0c08db4au; return 0; }
r[7]+=0x00000014u;
goto P_0c08db4c;
P_0c08db4c: /* original 7610, guest PC 0x0c08db4c */
if(!s->budget--) { s->failed_pc=0x0c08db4cu; return 0; }
r[6]+=0x00000010u;
goto P_0c08db4e;
P_0c08db4e: /* original b0e2, guest PC 0x0c08db4e */
if(!s->budget--) { s->failed_pc=0x0c08db4eu; return 0; }
target=code_base|0x0c08dd16u; r[16]=code_base|0x0c08db52u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db52u) { target=s->pc; goto dispatch; }
goto P_0c08db52;
P_0c08db50: /* original 64e3, guest PC 0x0c08db50 */
if(!s->budget--) { s->failed_pc=0x0c08db50u; return 0; }
r[4]=r[14];
goto P_0c08db52;
P_0c08db52: /* original 52f6, guest PC 0x0c08db52 */
if(!s->budget--) { s->failed_pc=0x0c08db52u; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08db54;
P_0c08db54: /* original 2f26, guest PC 0x0c08db54 */
if(!s->budget--) { s->failed_pc=0x0c08db54u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db56;
P_0c08db56: /* original 53f6, guest PC 0x0c08db56 */
if(!s->budget--) { s->failed_pc=0x0c08db56u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c08db58;
P_0c08db58: /* original 2f36, guest PC 0x0c08db58 */
if(!s->budget--) { s->failed_pc=0x0c08db58u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db5a;
P_0c08db5a: /* original 52f6, guest PC 0x0c08db5a */
if(!s->budget--) { s->failed_pc=0x0c08db5au; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c08db5c;
P_0c08db5c: /* original 2f26, guest PC 0x0c08db5c */
if(!s->budget--) { s->failed_pc=0x0c08db5cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08db5e;
P_0c08db5e: /* original 55fa, guest PC 0x0c08db5e */
if(!s->budget--) { s->failed_pc=0x0c08db5eu; return 0; }
r[5]=read(ram,r[15]+40,4);
goto P_0c08db60;
P_0c08db60: /* original 56fb, guest PC 0x0c08db60 */
if(!s->budget--) { s->failed_pc=0x0c08db60u; return 0; }
r[6]=read(ram,r[15]+44,4);
goto P_0c08db62;
P_0c08db62: /* original 57f6, guest PC 0x0c08db62 */
if(!s->budget--) { s->failed_pc=0x0c08db62u; return 0; }
r[7]=read(ram,r[15]+24,4);
goto P_0c08db64;
P_0c08db64: /* original b1bf, guest PC 0x0c08db64 */
if(!s->budget--) { s->failed_pc=0x0c08db64u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08db68u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08db68u) { target=s->pc; goto dispatch; }
goto P_0c08db68;
P_0c08db66: /* original 64e3, guest PC 0x0c08db66 */
if(!s->budget--) { s->failed_pc=0x0c08db66u; return 0; }
r[4]=r[14];
goto P_0c08db68;
P_0c08db68: /* original 7f38, guest PC 0x0c08db68 */
if(!s->budget--) { s->failed_pc=0x0c08db68u; return 0; }
r[15]+=0x00000038u;
goto P_0c08db6a;
P_0c08db6a: /* original 4f26, guest PC 0x0c08db6a */
if(!s->budget--) { s->failed_pc=0x0c08db6au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08db6c;
P_0c08db6c: /* original 000b, guest PC 0x0c08db6c */
if(!s->budget--) { s->failed_pc=0x0c08db6cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08db6e: /* original 6ef6, guest PC 0x0c08db6e */
if(!s->budget--) { s->failed_pc=0x0c08db6eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08db70u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08db70u; return 0; } return 1;
P_0c08dbe4: /* original 2fe6, guest PC 0x0c08dbe4 */
if(!s->budget--) { s->failed_pc=0x0c08dbe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dbe6;
P_0c08dbe6: /* original 6e43, guest PC 0x0c08dbe6 */
if(!s->budget--) { s->failed_pc=0x0c08dbe6u; return 0; }
r[14]=r[4];
goto P_0c08dbe8;
P_0c08dbe8: /* original 2fd6, guest PC 0x0c08dbe8 */
if(!s->budget--) { s->failed_pc=0x0c08dbe8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dbea;
P_0c08dbea: /* original 2fc6, guest PC 0x0c08dbea */
if(!s->budget--) { s->failed_pc=0x0c08dbeau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dbec;
P_0c08dbec: /* original 902a, guest PC 0x0c08dbec */
if(!s->budget--) { s->failed_pc=0x0c08dbecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc44u,2);
goto P_0c08dbee;
P_0c08dbee: /* original 4f22, guest PC 0x0c08dbee */
if(!s->budget--) { s->failed_pc=0x0c08dbeeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08dbf0;
P_0c08dbf0: /* original 06ed, guest PC 0x0c08dbf0 */
if(!s->budget--) { s->failed_pc=0x0c08dbf0u; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbf2;
P_0c08dbf2: /* original 7002, guest PC 0x0c08dbf2 */
if(!s->budget--) { s->failed_pc=0x0c08dbf2u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dbf4;
P_0c08dbf4: /* original 05ed, guest PC 0x0c08dbf4 */
if(!s->budget--) { s->failed_pc=0x0c08dbf4u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbf6;
P_0c08dbf6: /* original 70fc, guest PC 0x0c08dbf6 */
if(!s->budget--) { s->failed_pc=0x0c08dbf6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08dbf8;
P_0c08dbf8: /* original 04ed, guest PC 0x0c08dbf8 */
if(!s->budget--) { s->failed_pc=0x0c08dbf8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbfa;
P_0c08dbfa: /* original 7006, guest PC 0x0c08dbfa */
if(!s->budget--) { s->failed_pc=0x0c08dbfau; return 0; }
r[0]+=0x00000006u;
goto P_0c08dbfc;
P_0c08dbfc: /* original 0ded, guest PC 0x0c08dbfc */
if(!s->budget--) { s->failed_pc=0x0c08dbfcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dbfe;
P_0c08dbfe: /* original 7002, guest PC 0x0c08dbfe */
if(!s->budget--) { s->failed_pc=0x0c08dbfeu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc00;
P_0c08dc00: /* original 4410, guest PC 0x0c08dc00 */
if(!s->budget--) { s->failed_pc=0x0c08dc00u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c08dc02;
P_0c08dc02: /* original 7ff0, guest PC 0x0c08dc02 */
if(!s->budget--) { s->failed_pc=0x0c08dc02u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08dc04;
P_0c08dc04: /* original 8f22, guest PC 0x0c08dc04 */
if(!s->budget--) { s->failed_pc=0x0c08dc04u; return 0; }
cond=r[17]&1u;
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
if(!cond) { goto P_0c08dc4c; }
goto P_0c08dc08;
P_0c08dc06: /* original 0ced, guest PC 0x0c08dc06 */
if(!s->budget--) { s->failed_pc=0x0c08dc06u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08dc08;
P_0c08dc08: /* original 901c, guest PC 0x0c08dc08 */
if(!s->budget--) { s->failed_pc=0x0c08dc08u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dc44u,2);
goto P_0c08dc0a;
P_0c08dc0a: /* original e400, guest PC 0x0c08dc0a */
if(!s->budget--) { s->failed_pc=0x0c08dc0au; return 0; }
r[4]=0x00000000u;
goto P_0c08dc0c;
P_0c08dc0c: /* original 62f3, guest PC 0x0c08dc0c */
if(!s->budget--) { s->failed_pc=0x0c08dc0cu; return 0; }
r[2]=r[15];
goto P_0c08dc0e;
P_0c08dc0e: /* original e301, guest PC 0x0c08dc0e */
if(!s->budget--) { s->failed_pc=0x0c08dc0eu; return 0; }
r[3]=0x00000001u;
goto P_0c08dc10;
P_0c08dc10: /* original 0e45, guest PC 0x0c08dc10 */
if(!s->budget--) { s->failed_pc=0x0c08dc10u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc12;
P_0c08dc12: /* original 7002, guest PC 0x0c08dc12 */
if(!s->budget--) { s->failed_pc=0x0c08dc12u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc14;
P_0c08dc14: /* original 0e45, guest PC 0x0c08dc14 */
if(!s->budget--) { s->failed_pc=0x0c08dc14u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc16;
P_0c08dc16: /* original 70fc, guest PC 0x0c08dc16 */
if(!s->budget--) { s->failed_pc=0x0c08dc16u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c08dc18;
P_0c08dc18: /* original 0e45, guest PC 0x0c08dc18 */
if(!s->budget--) { s->failed_pc=0x0c08dc18u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc1a;
P_0c08dc1a: /* original 70fe, guest PC 0x0c08dc1a */
if(!s->budget--) { s->failed_pc=0x0c08dc1au; return 0; }
r[0]+=0xfffffffeu;
goto P_0c08dc1c;
P_0c08dc1c: /* original 720c, guest PC 0x0c08dc1c */
if(!s->budget--) { s->failed_pc=0x0c08dc1cu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dc1e;
P_0c08dc1e: /* original 0e34, guest PC 0x0c08dc1e */
if(!s->budget--) { s->failed_pc=0x0c08dc1eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08dc20;
P_0c08dc20: /* original 2f26, guest PC 0x0c08dc20 */
if(!s->budget--) { s->failed_pc=0x0c08dc20u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc22;
P_0c08dc22: /* original 3d6c, guest PC 0x0c08dc22 */
if(!s->budget--) { s->failed_pc=0x0c08dc22u; return 0; }
r[13]+=r[6];
goto P_0c08dc24;
P_0c08dc24: /* original 63f3, guest PC 0x0c08dc24 */
if(!s->budget--) { s->failed_pc=0x0c08dc24u; return 0; }
r[3]=r[15];
goto P_0c08dc26;
P_0c08dc26: /* original 730c, guest PC 0x0c08dc26 */
if(!s->budget--) { s->failed_pc=0x0c08dc26u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08dc28;
P_0c08dc28: /* original 2f36, guest PC 0x0c08dc28 */
if(!s->budget--) { s->failed_pc=0x0c08dc28u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc2a;
P_0c08dc2a: /* original 3c5c, guest PC 0x0c08dc2a */
if(!s->budget--) { s->failed_pc=0x0c08dc2au; return 0; }
r[12]+=r[5];
goto P_0c08dc2c;
P_0c08dc2c: /* original 66f3, guest PC 0x0c08dc2c */
if(!s->budget--) { s->failed_pc=0x0c08dc2cu; return 0; }
r[6]=r[15];
goto P_0c08dc2e;
P_0c08dc2e: /* original 67f3, guest PC 0x0c08dc2e */
if(!s->budget--) { s->failed_pc=0x0c08dc2eu; return 0; }
r[7]=r[15];
goto P_0c08dc30;
P_0c08dc30: /* original 65c3, guest PC 0x0c08dc30 */
if(!s->budget--) { s->failed_pc=0x0c08dc30u; return 0; }
r[5]=r[12];
goto P_0c08dc32;
P_0c08dc32: /* original 7608, guest PC 0x0c08dc32 */
if(!s->budget--) { s->failed_pc=0x0c08dc32u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dc34;
P_0c08dc34: /* original 770c, guest PC 0x0c08dc34 */
if(!s->budget--) { s->failed_pc=0x0c08dc34u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dc36;
P_0c08dc36: /* original b03b, guest PC 0x0c08dc36 */
if(!s->budget--) { s->failed_pc=0x0c08dc36u; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08dc3au;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc3au) { target=s->pc; goto dispatch; }
goto P_0c08dc3a;
P_0c08dc38: /* original 64d3, guest PC 0x0c08dc38 */
if(!s->budget--) { s->failed_pc=0x0c08dc38u; return 0; }
r[4]=r[13];
goto P_0c08dc3a;
P_0c08dc3a: /* original a028, guest PC 0x0c08dc3a */
if(!s->budget--) { s->failed_pc=0x0c08dc3au; return 0; }
goto P_0c08dc8e;
P_0c08dc3c: /* original 0009, guest PC 0x0c08dc3c */
if(!s->budget--) { s->failed_pc=0x0c08dc3cu; return 0; }
if(!vf3_matrix_family(0x0c08dc3eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08dc3eu; return 0; } return 1;
P_0c08dc4c: /* original d242, guest PC 0x0c08dc4c */
if(!s->budget--) { s->failed_pc=0x0c08dc4cu; return 0; }
r[2]=read(ram,0x0c08dd58u,4);
goto P_0c08dc4e;
P_0c08dc4e: /* original 6163, guest PC 0x0c08dc4e */
if(!s->budget--) { s->failed_pc=0x0c08dc4eu; return 0; }
r[1]=r[6];
goto P_0c08dc50;
P_0c08dc50: /* original 420b, guest PC 0x0c08dc50 */
if(!s->budget--) { s->failed_pc=0x0c08dc50u; return 0; }
target=r[2];
r[16]=code_base|0x0c08dc54u;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc54u) { target=s->pc; goto dispatch; }
goto P_0c08dc54;
P_0c08dc52: /* original 6043, guest PC 0x0c08dc52 */
if(!s->budget--) { s->failed_pc=0x0c08dc52u; return 0; }
r[0]=r[4];
goto P_0c08dc54;
P_0c08dc54: /* original d340, guest PC 0x0c08dc54 */
if(!s->budget--) { s->failed_pc=0x0c08dc54u; return 0; }
r[3]=read(ram,0x0c08dd58u,4);
goto P_0c08dc56;
P_0c08dc56: /* original 6153, guest PC 0x0c08dc56 */
if(!s->budget--) { s->failed_pc=0x0c08dc56u; return 0; }
r[1]=r[5];
goto P_0c08dc58;
P_0c08dc58: /* original 6703, guest PC 0x0c08dc58 */
if(!s->budget--) { s->failed_pc=0x0c08dc58u; return 0; }
r[7]=r[0];
goto P_0c08dc5a;
P_0c08dc5a: /* original 430b, guest PC 0x0c08dc5a */
if(!s->budget--) { s->failed_pc=0x0c08dc5au; return 0; }
target=r[3];
r[16]=code_base|0x0c08dc5eu;
r[0]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc5eu) { target=s->pc; goto dispatch; }
goto P_0c08dc5e;
P_0c08dc5c: /* original 6043, guest PC 0x0c08dc5c */
if(!s->budget--) { s->failed_pc=0x0c08dc5cu; return 0; }
r[0]=r[4];
goto P_0c08dc5e;
P_0c08dc5e: /* original 6203, guest PC 0x0c08dc5e */
if(!s->budget--) { s->failed_pc=0x0c08dc5eu; return 0; }
r[2]=r[0];
goto P_0c08dc60;
P_0c08dc60: /* original 9071, guest PC 0x0c08dc60 */
if(!s->budget--) { s->failed_pc=0x0c08dc60u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08dd46u,2);
goto P_0c08dc62;
P_0c08dc62: /* original 63f3, guest PC 0x0c08dc62 */
if(!s->budget--) { s->failed_pc=0x0c08dc62u; return 0; }
r[3]=r[15];
goto P_0c08dc64;
P_0c08dc64: /* original 730c, guest PC 0x0c08dc64 */
if(!s->budget--) { s->failed_pc=0x0c08dc64u; return 0; }
r[3]+=0x0000000cu;
goto P_0c08dc66;
P_0c08dc66: /* original 0e45, guest PC 0x0c08dc66 */
if(!s->budget--) { s->failed_pc=0x0c08dc66u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08dc68;
P_0c08dc68: /* original 3528, guest PC 0x0c08dc68 */
if(!s->budget--) { s->failed_pc=0x0c08dc68u; return 0; }
r[5]-=r[2];
goto P_0c08dc6a;
P_0c08dc6a: /* original 3c2c, guest PC 0x0c08dc6a */
if(!s->budget--) { s->failed_pc=0x0c08dc6au; return 0; }
r[12]+=r[2];
goto P_0c08dc6c;
P_0c08dc6c: /* original 3678, guest PC 0x0c08dc6c */
if(!s->budget--) { s->failed_pc=0x0c08dc6cu; return 0; }
r[6]-=r[7];
goto P_0c08dc6e;
P_0c08dc6e: /* original 7002, guest PC 0x0c08dc6e */
if(!s->budget--) { s->failed_pc=0x0c08dc6eu; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc70;
P_0c08dc70: /* original 0e65, guest PC 0x0c08dc70 */
if(!s->budget--) { s->failed_pc=0x0c08dc70u; return 0; }
write(ram,r[14]+r[0],r[6],2);
goto P_0c08dc72;
P_0c08dc72: /* original 3d7c, guest PC 0x0c08dc72 */
if(!s->budget--) { s->failed_pc=0x0c08dc72u; return 0; }
r[13]+=r[7];
goto P_0c08dc74;
P_0c08dc74: /* original 7002, guest PC 0x0c08dc74 */
if(!s->budget--) { s->failed_pc=0x0c08dc74u; return 0; }
r[0]+=0x00000002u;
goto P_0c08dc76;
P_0c08dc76: /* original 0e55, guest PC 0x0c08dc76 */
if(!s->budget--) { s->failed_pc=0x0c08dc76u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c08dc78;
P_0c08dc78: /* original 65c3, guest PC 0x0c08dc78 */
if(!s->budget--) { s->failed_pc=0x0c08dc78u; return 0; }
r[5]=r[12];
goto P_0c08dc7a;
P_0c08dc7a: /* original 2f36, guest PC 0x0c08dc7a */
if(!s->budget--) { s->failed_pc=0x0c08dc7au; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc7c;
P_0c08dc7c: /* original 62f3, guest PC 0x0c08dc7c */
if(!s->budget--) { s->failed_pc=0x0c08dc7cu; return 0; }
r[2]=r[15];
goto P_0c08dc7e;
P_0c08dc7e: /* original 720c, guest PC 0x0c08dc7e */
if(!s->budget--) { s->failed_pc=0x0c08dc7eu; return 0; }
r[2]+=0x0000000cu;
goto P_0c08dc80;
P_0c08dc80: /* original 2f26, guest PC 0x0c08dc80 */
if(!s->budget--) { s->failed_pc=0x0c08dc80u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc82;
P_0c08dc82: /* original 66f3, guest PC 0x0c08dc82 */
if(!s->budget--) { s->failed_pc=0x0c08dc82u; return 0; }
r[6]=r[15];
goto P_0c08dc84;
P_0c08dc84: /* original 67f3, guest PC 0x0c08dc84 */
if(!s->budget--) { s->failed_pc=0x0c08dc84u; return 0; }
r[7]=r[15];
goto P_0c08dc86;
P_0c08dc86: /* original 7608, guest PC 0x0c08dc86 */
if(!s->budget--) { s->failed_pc=0x0c08dc86u; return 0; }
r[6]+=0x00000008u;
goto P_0c08dc88;
P_0c08dc88: /* original 770c, guest PC 0x0c08dc88 */
if(!s->budget--) { s->failed_pc=0x0c08dc88u; return 0; }
r[7]+=0x0000000cu;
goto P_0c08dc8a;
P_0c08dc8a: /* original b011, guest PC 0x0c08dc8a */
if(!s->budget--) { s->failed_pc=0x0c08dc8au; return 0; }
target=code_base|0x0c08dcb0u; r[16]=code_base|0x0c08dc8eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dc8eu) { target=s->pc; goto dispatch; }
goto P_0c08dc8e;
P_0c08dc8c: /* original 64d3, guest PC 0x0c08dc8c */
if(!s->budget--) { s->failed_pc=0x0c08dc8cu; return 0; }
r[4]=r[13];
goto P_0c08dc8e;
P_0c08dc8e: /* original 52f5, guest PC 0x0c08dc8e */
if(!s->budget--) { s->failed_pc=0x0c08dc8eu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08dc90;
P_0c08dc90: /* original 65d3, guest PC 0x0c08dc90 */
if(!s->budget--) { s->failed_pc=0x0c08dc90u; return 0; }
r[5]=r[13];
goto P_0c08dc92;
P_0c08dc92: /* original 66c3, guest PC 0x0c08dc92 */
if(!s->budget--) { s->failed_pc=0x0c08dc92u; return 0; }
r[6]=r[12];
goto P_0c08dc94;
P_0c08dc94: /* original 2f26, guest PC 0x0c08dc94 */
if(!s->budget--) { s->failed_pc=0x0c08dc94u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc96;
P_0c08dc96: /* original 53f5, guest PC 0x0c08dc96 */
if(!s->budget--) { s->failed_pc=0x0c08dc96u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c08dc98;
P_0c08dc98: /* original 2f36, guest PC 0x0c08dc98 */
if(!s->budget--) { s->failed_pc=0x0c08dc98u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc9a;
P_0c08dc9a: /* original 52f5, guest PC 0x0c08dc9a */
if(!s->budget--) { s->failed_pc=0x0c08dc9au; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c08dc9c;
P_0c08dc9c: /* original 2f26, guest PC 0x0c08dc9c */
if(!s->budget--) { s->failed_pc=0x0c08dc9cu; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08dc9e;
P_0c08dc9e: /* original 57f5, guest PC 0x0c08dc9e */
if(!s->budget--) { s->failed_pc=0x0c08dc9eu; return 0; }
r[7]=read(ram,r[15]+20,4);
goto P_0c08dca0;
P_0c08dca0: /* original b121, guest PC 0x0c08dca0 */
if(!s->budget--) { s->failed_pc=0x0c08dca0u; return 0; }
target=code_base|0x0c08dee6u; r[16]=code_base|0x0c08dca4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08dca4u) { target=s->pc; goto dispatch; }
goto P_0c08dca4;
P_0c08dca2: /* original 64e3, guest PC 0x0c08dca2 */
if(!s->budget--) { s->failed_pc=0x0c08dca2u; return 0; }
r[4]=r[14];
goto P_0c08dca4;
P_0c08dca4: /* original 7f24, guest PC 0x0c08dca4 */
if(!s->budget--) { s->failed_pc=0x0c08dca4u; return 0; }
r[15]+=0x00000024u;
goto P_0c08dca6;
P_0c08dca6: /* original 4f26, guest PC 0x0c08dca6 */
if(!s->budget--) { s->failed_pc=0x0c08dca6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08dca8;
P_0c08dca8: /* original 6cf6, guest PC 0x0c08dca8 */
if(!s->budget--) { s->failed_pc=0x0c08dca8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08dcaa;
P_0c08dcaa: /* original 6df6, guest PC 0x0c08dcaa */
if(!s->budget--) { s->failed_pc=0x0c08dcaau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08dcac;
P_0c08dcac: /* original 000b, guest PC 0x0c08dcac */
if(!s->budget--) { s->failed_pc=0x0c08dcacu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08dcae: /* original 6ef6, guest PC 0x0c08dcae */
if(!s->budget--) { s->failed_pc=0x0c08dcaeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08dcb0;
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
return vf3_matrix_family(0x0c08dd16u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
