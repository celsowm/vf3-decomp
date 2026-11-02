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
int vf3_away_batch10_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c06eaa4u: goto P_0c06eaa4;
case 0x0c06eaa6u: goto P_0c06eaa6;
case 0x0c06eaa8u: goto P_0c06eaa8;
case 0x0c06eaaau: goto P_0c06eaaa;
case 0x0c06eaacu: goto P_0c06eaac;
case 0x0c06eaaeu: goto P_0c06eaae;
case 0x0c06eab0u: goto P_0c06eab0;
case 0x0c06eab2u: goto P_0c06eab2;
case 0x0c06eab4u: goto P_0c06eab4;
case 0x0c06eab6u: goto P_0c06eab6;
case 0x0c06eab8u: goto P_0c06eab8;
case 0x0c06eabau: goto P_0c06eaba;
case 0x0c06eabcu: goto P_0c06eabc;
case 0x0c06eabeu: goto P_0c06eabe;
case 0x0c06eac0u: goto P_0c06eac0;
case 0x0c06eac2u: goto P_0c06eac2;
case 0x0c06eac4u: goto P_0c06eac4;
case 0x0c06eac6u: goto P_0c06eac6;
case 0x0c06eac8u: goto P_0c06eac8;
case 0x0c06eacau: goto P_0c06eaca;
case 0x0c06eaccu: goto P_0c06eacc;
case 0x0c06eaceu: goto P_0c06eace;
case 0x0c06ead0u: goto P_0c06ead0;
case 0x0c06ead2u: goto P_0c06ead2;
case 0x0c06ead4u: goto P_0c06ead4;
case 0x0c06ead6u: goto P_0c06ead6;
case 0x0c06ead8u: goto P_0c06ead8;
case 0x0c06eadau: goto P_0c06eada;
case 0x0c06eadcu: goto P_0c06eadc;
case 0x0c06eadeu: goto P_0c06eade;
case 0x0c06eae0u: goto P_0c06eae0;
case 0x0c06eae2u: goto P_0c06eae2;
case 0x0c06eae4u: goto P_0c06eae4;
case 0x0c06eae6u: goto P_0c06eae6;
case 0x0c06eae8u: goto P_0c06eae8;
case 0x0c06eaeau: goto P_0c06eaea;
case 0x0c06eaecu: goto P_0c06eaec;
case 0x0c06eaeeu: goto P_0c06eaee;
case 0x0c06eaf0u: goto P_0c06eaf0;
case 0x0c06eaf2u: goto P_0c06eaf2;
case 0x0c06eaf4u: goto P_0c06eaf4;
case 0x0c06eaf6u: goto P_0c06eaf6;
case 0x0c06eaf8u: goto P_0c06eaf8;
case 0x0c06eafau: goto P_0c06eafa;
case 0x0c06eafcu: goto P_0c06eafc;
case 0x0c06eafeu: goto P_0c06eafe;
case 0x0c06eb00u: goto P_0c06eb00;
case 0x0c06eb02u: goto P_0c06eb02;
case 0x0c06eb04u: goto P_0c06eb04;
case 0x0c06eb06u: goto P_0c06eb06;
case 0x0c06eb08u: goto P_0c06eb08;
case 0x0c06eb0au: goto P_0c06eb0a;
case 0x0c06eb0cu: goto P_0c06eb0c;
case 0x0c06eb0eu: goto P_0c06eb0e;
case 0x0c06eb10u: goto P_0c06eb10;
case 0x0c06eb12u: goto P_0c06eb12;
case 0x0c06eb14u: goto P_0c06eb14;
case 0x0c06eb16u: goto P_0c06eb16;
case 0x0c06eb18u: goto P_0c06eb18;
case 0x0c06eb1au: goto P_0c06eb1a;
case 0x0c06eb1cu: goto P_0c06eb1c;
case 0x0c06eb1eu: goto P_0c06eb1e;
case 0x0c06eb20u: goto P_0c06eb20;
case 0x0c06eb22u: goto P_0c06eb22;
case 0x0c06eb24u: goto P_0c06eb24;
case 0x0c06eb26u: goto P_0c06eb26;
case 0x0c06eb28u: goto P_0c06eb28;
case 0x0c06eb2au: goto P_0c06eb2a;
case 0x0c06eb2cu: goto P_0c06eb2c;
case 0x0c06eb2eu: goto P_0c06eb2e;
case 0x0c06eb30u: goto P_0c06eb30;
case 0x0c06eb32u: goto P_0c06eb32;
case 0x0c06eb34u: goto P_0c06eb34;
case 0x0c06eb36u: goto P_0c06eb36;
case 0x0c06eb38u: goto P_0c06eb38;
case 0x0c06eb3au: goto P_0c06eb3a;
case 0x0c06eb3cu: goto P_0c06eb3c;
case 0x0c06eb3eu: goto P_0c06eb3e;
case 0x0c06eb40u: goto P_0c06eb40;
case 0x0c06eb42u: goto P_0c06eb42;
case 0x0c06eb44u: goto P_0c06eb44;
case 0x0c06eb46u: goto P_0c06eb46;
case 0x0c06eb48u: goto P_0c06eb48;
case 0x0c06eb4au: goto P_0c06eb4a;
case 0x0c06eb4cu: goto P_0c06eb4c;
case 0x0c06eb4eu: goto P_0c06eb4e;
case 0x0c06eb50u: goto P_0c06eb50;
case 0x0c06eb52u: goto P_0c06eb52;
case 0x0c06eb54u: goto P_0c06eb54;
case 0x0c06eb56u: goto P_0c06eb56;
case 0x0c06eb58u: goto P_0c06eb58;
case 0x0c06eb5au: goto P_0c06eb5a;
case 0x0c06eb5cu: goto P_0c06eb5c;
case 0x0c06eb5eu: goto P_0c06eb5e;
case 0x0c06eb60u: goto P_0c06eb60;
case 0x0c06eb62u: goto P_0c06eb62;
case 0x0c06eb64u: goto P_0c06eb64;
case 0x0c06ef3cu: goto P_0c06ef3c;
case 0x0c06ef3eu: goto P_0c06ef3e;
case 0x0c06ef40u: goto P_0c06ef40;
case 0x0c06ef42u: goto P_0c06ef42;
case 0x0c06ef44u: goto P_0c06ef44;
case 0x0c06ef46u: goto P_0c06ef46;
case 0x0c06ef48u: goto P_0c06ef48;
case 0x0c06ef4au: goto P_0c06ef4a;
case 0x0c06ef4cu: goto P_0c06ef4c;
case 0x0c06ef4eu: goto P_0c06ef4e;
case 0x0c06ef50u: goto P_0c06ef50;
case 0x0c06ef52u: goto P_0c06ef52;
case 0x0c06ef54u: goto P_0c06ef54;
case 0x0c06ef56u: goto P_0c06ef56;
case 0x0c06ef58u: goto P_0c06ef58;
case 0x0c06ef5au: goto P_0c06ef5a;
case 0x0c06ef5cu: goto P_0c06ef5c;
case 0x0c06ef5eu: goto P_0c06ef5e;
case 0x0c06ef60u: goto P_0c06ef60;
case 0x0c06ef62u: goto P_0c06ef62;
case 0x0c06ef64u: goto P_0c06ef64;
case 0x0c06ef66u: goto P_0c06ef66;
case 0x0c06ef68u: goto P_0c06ef68;
case 0x0c06ef6au: goto P_0c06ef6a;
case 0x0c06ef6cu: goto P_0c06ef6c;
case 0x0c06ef6eu: goto P_0c06ef6e;
case 0x0c06ef70u: goto P_0c06ef70;
case 0x0c06ef72u: goto P_0c06ef72;
case 0x0c06ef74u: goto P_0c06ef74;
case 0x0c06ef76u: goto P_0c06ef76;
case 0x0c06ef78u: goto P_0c06ef78;
case 0x0c06ef7au: goto P_0c06ef7a;
case 0x0c06ef7cu: goto P_0c06ef7c;
case 0x0c06ef7eu: goto P_0c06ef7e;
case 0x0c06ef80u: goto P_0c06ef80;
case 0x0c06ef82u: goto P_0c06ef82;
case 0x0c06ef84u: goto P_0c06ef84;
case 0x0c06ef86u: goto P_0c06ef86;
case 0x0c06ef88u: goto P_0c06ef88;
case 0x0c06ef8au: goto P_0c06ef8a;
case 0x0c06ef8cu: goto P_0c06ef8c;
case 0x0c06ef8eu: goto P_0c06ef8e;
case 0x0c06ef90u: goto P_0c06ef90;
case 0x0c06ef92u: goto P_0c06ef92;
case 0x0c06ef94u: goto P_0c06ef94;
case 0x0c06ef96u: goto P_0c06ef96;
case 0x0c06ef98u: goto P_0c06ef98;
case 0x0c06ef9au: goto P_0c06ef9a;
case 0x0c06ef9cu: goto P_0c06ef9c;
case 0x0c06ef9eu: goto P_0c06ef9e;
case 0x0c06efa0u: goto P_0c06efa0;
case 0x0c06efa2u: goto P_0c06efa2;
case 0x0c06efa4u: goto P_0c06efa4;
case 0x0c06efa6u: goto P_0c06efa6;
case 0x0c06efa8u: goto P_0c06efa8;
case 0x0c06efaau: goto P_0c06efaa;
case 0x0c06efacu: goto P_0c06efac;
case 0x0c06efaeu: goto P_0c06efae;
case 0x0c06efb0u: goto P_0c06efb0;
case 0x0c06efb2u: goto P_0c06efb2;
case 0x0c06efb4u: goto P_0c06efb4;
case 0x0c06efb6u: goto P_0c06efb6;
case 0x0c06efb8u: goto P_0c06efb8;
case 0x0c06efbau: goto P_0c06efba;
case 0x0c06efbcu: goto P_0c06efbc;
case 0x0c06efbeu: goto P_0c06efbe;
case 0x0c06efc0u: goto P_0c06efc0;
case 0x0c06efc2u: goto P_0c06efc2;
case 0x0c06efc4u: goto P_0c06efc4;
case 0x0c06efc6u: goto P_0c06efc6;
case 0x0c06efc8u: goto P_0c06efc8;
case 0x0c06efcau: goto P_0c06efca;
case 0x0c06efccu: goto P_0c06efcc;
case 0x0c06efceu: goto P_0c06efce;
case 0x0c06efd0u: goto P_0c06efd0;
case 0x0c06efd2u: goto P_0c06efd2;
case 0x0c06efd4u: goto P_0c06efd4;
case 0x0c06efd6u: goto P_0c06efd6;
case 0x0c06efd8u: goto P_0c06efd8;
case 0x0c06efdau: goto P_0c06efda;
case 0x0c06efdcu: goto P_0c06efdc;
case 0x0c06efdeu: goto P_0c06efde;
case 0x0c06efe0u: goto P_0c06efe0;
case 0x0c06efe2u: goto P_0c06efe2;
case 0x0c06efe4u: goto P_0c06efe4;
case 0x0c06efe6u: goto P_0c06efe6;
case 0x0c06efe8u: goto P_0c06efe8;
case 0x0c06efeau: goto P_0c06efea;
case 0x0c06efecu: goto P_0c06efec;
case 0x0c06efeeu: goto P_0c06efee;
case 0x0c06eff0u: goto P_0c06eff0;
case 0x0c06eff2u: goto P_0c06eff2;
case 0x0c06eff4u: goto P_0c06eff4;
case 0x0c06eff6u: goto P_0c06eff6;
case 0x0c06eff8u: goto P_0c06eff8;
case 0x0c06effau: goto P_0c06effa;
case 0x0c06effcu: goto P_0c06effc;
case 0x0c06effeu: goto P_0c06effe;
case 0x0c06f000u: goto P_0c06f000;
case 0x0c06f002u: goto P_0c06f002;
case 0x0c06f004u: goto P_0c06f004;
case 0x0c06f006u: goto P_0c06f006;
case 0x0c06f008u: goto P_0c06f008;
case 0x0c06f00au: goto P_0c06f00a;
case 0x0c06f00cu: goto P_0c06f00c;
case 0x0c06f00eu: goto P_0c06f00e;
case 0x0c06f010u: goto P_0c06f010;
case 0x0c06f012u: goto P_0c06f012;
case 0x0c06f014u: goto P_0c06f014;
case 0x0c06f016u: goto P_0c06f016;
case 0x0c06f018u: goto P_0c06f018;
case 0x0c06f01au: goto P_0c06f01a;
case 0x0c06f01cu: goto P_0c06f01c;
case 0x0c06f01eu: goto P_0c06f01e;
case 0x0c06f020u: goto P_0c06f020;
case 0x0c06f022u: goto P_0c06f022;
case 0x0c06f024u: goto P_0c06f024;
case 0x0c06f026u: goto P_0c06f026;
case 0x0c06f028u: goto P_0c06f028;
case 0x0c06f02au: goto P_0c06f02a;
case 0x0c06f02cu: goto P_0c06f02c;
case 0x0c06f02eu: goto P_0c06f02e;
case 0x0c06f030u: goto P_0c06f030;
case 0x0c06f032u: goto P_0c06f032;
case 0x0c06f034u: goto P_0c06f034;
case 0x0c06f036u: goto P_0c06f036;
default: return vf3_matrix_family(target,s,ram);
}
P_0c06eaa4: /* original 2fe6, guest PC 0x0c06eaa4 */
if(!s->budget--) { s->failed_pc=0x0c06eaa4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eaa6;
P_0c06eaa6: /* original 2fd6, guest PC 0x0c06eaa6 */
if(!s->budget--) { s->failed_pc=0x0c06eaa6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eaa8;
P_0c06eaa8: /* original 2fc6, guest PC 0x0c06eaa8 */
if(!s->budget--) { s->failed_pc=0x0c06eaa8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eaaa;
P_0c06eaaa: /* original 2fb6, guest PC 0x0c06eaaa */
if(!s->budget--) { s->failed_pc=0x0c06eaaau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eaac;
P_0c06eaac: /* original 2fa6, guest PC 0x0c06eaac */
if(!s->budget--) { s->failed_pc=0x0c06eaacu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eaae;
P_0c06eaae: /* original 2f96, guest PC 0x0c06eaae */
if(!s->budget--) { s->failed_pc=0x0c06eaaeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eab0;
P_0c06eab0: /* original 2f86, guest PC 0x0c06eab0 */
if(!s->budget--) { s->failed_pc=0x0c06eab0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06eab2;
P_0c06eab2: /* original fffb, guest PC 0x0c06eab2 */
if(!s->budget--) { s->failed_pc=0x0c06eab2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c06eab4;
P_0c06eab4: /* original ffeb, guest PC 0x0c06eab4 */
if(!s->budget--) { s->failed_pc=0x0c06eab4u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c06eab6;
P_0c06eab6: /* original ffdb, guest PC 0x0c06eab6 */
if(!s->budget--) { s->failed_pc=0x0c06eab6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c06eab8;
P_0c06eab8: /* original ffcb, guest PC 0x0c06eab8 */
if(!s->budget--) { s->failed_pc=0x0c06eab8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c06eaba;
P_0c06eaba: /* original d240, guest PC 0x0c06eaba */
if(!s->budget--) { s->failed_pc=0x0c06eabau; return 0; }
r[2]=read(ram,0x0c06ebbcu,4);
goto P_0c06eabc;
P_0c06eabc: /* original 4f22, guest PC 0x0c06eabc */
if(!s->budget--) { s->failed_pc=0x0c06eabcu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06eabe;
P_0c06eabe: /* original 6322, guest PC 0x0c06eabe */
if(!s->budget--) { s->failed_pc=0x0c06eabeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c06eac0;
P_0c06eac0: /* original 7ffc, guest PC 0x0c06eac0 */
if(!s->budget--) { s->failed_pc=0x0c06eac0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c06eac2;
P_0c06eac2: /* original 2f32, guest PC 0x0c06eac2 */
if(!s->budget--) { s->failed_pc=0x0c06eac2u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c06eac4;
P_0c06eac4: /* original d13e, guest PC 0x0c06eac4 */
if(!s->budget--) { s->failed_pc=0x0c06eac4u; return 0; }
r[1]=read(ram,0x0c06ebc0u,4);
goto P_0c06eac6;
P_0c06eac6: /* original 6012, guest PC 0x0c06eac6 */
if(!s->budget--) { s->failed_pc=0x0c06eac6u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c06eac8;
P_0c06eac8: /* original c804, guest PC 0x0c06eac8 */
if(!s->budget--) { s->failed_pc=0x0c06eac8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&4u)==0)!=0);
goto P_0c06eaca;
P_0c06eaca: /* original 893e, guest PC 0x0c06eaca */
if(!s->budget--) { s->failed_pc=0x0c06eacau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06eb4a; }
goto P_0c06eacc;
P_0c06eacc: /* original d23d, guest PC 0x0c06eacc */
if(!s->budget--) { s->failed_pc=0x0c06eaccu; return 0; }
r[2]=read(ram,0x0c06ebc4u,4);
goto P_0c06eace;
P_0c06eace: /* original 420b, guest PC 0x0c06eace */
if(!s->budget--) { s->failed_pc=0x0c06eaceu; return 0; }
target=r[2];
r[16]=code_base|0x0c06ead2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ead2u) { target=s->pc; goto dispatch; }
goto P_0c06ead2;
P_0c06ead0: /* original e400, guest PC 0x0c06ead0 */
if(!s->budget--) { s->failed_pc=0x0c06ead0u; return 0; }
r[4]=0x00000000u;
goto P_0c06ead2;
P_0c06ead2: /* original 9071, guest PC 0x0c06ead2 */
if(!s->budget--) { s->failed_pc=0x0c06ead2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ebb8u,2);
goto P_0c06ead4;
P_0c06ead4: /* original ec0a, guest PC 0x0c06ead4 */
if(!s->budget--) { s->failed_pc=0x0c06ead4u; return 0; }
r[12]=0x0000000au;
goto P_0c06ead6;
P_0c06ead6: /* original 64f2, guest PC 0x0c06ead6 */
if(!s->budget--) { s->failed_pc=0x0c06ead6u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c06ead8;
P_0c06ead8: /* original d93d, guest PC 0x0c06ead8 */
if(!s->budget--) { s->failed_pc=0x0c06ead8u; return 0; }
r[9]=read(ram,0x0c06ebd0u,4);
goto P_0c06eada;
P_0c06eada: /* original 044e, guest PC 0x0c06eada */
if(!s->budget--) { s->failed_pc=0x0c06eadau; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c06eadc;
P_0c06eadc: /* original c73a, guest PC 0x0c06eadc */
if(!s->budget--) { s->failed_pc=0x0c06eadcu; return 0; }
r[0]=code_base|0x0006ebc8u;
goto P_0c06eade;
P_0c06eade: /* original d83b, guest PC 0x0c06eade */
if(!s->budget--) { s->failed_pc=0x0c06eadeu; return 0; }
r[8]=read(ram,0x0c06ebccu,4);
goto P_0c06eae0;
P_0c06eae0: /* original 9b6b, guest PC 0x0c06eae0 */
if(!s->budget--) { s->failed_pc=0x0c06eae0u; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06ebbau,2);
goto P_0c06eae2;
P_0c06eae2: /* original 6d43, guest PC 0x0c06eae2 */
if(!s->budget--) { s->failed_pc=0x0c06eae2u; return 0; }
r[13]=r[4];
goto P_0c06eae4;
P_0c06eae4: /* original da3b, guest PC 0x0c06eae4 */
if(!s->budget--) { s->failed_pc=0x0c06eae4u; return 0; }
r[10]=read(ram,0x0c06ebd4u,4);
goto P_0c06eae6;
P_0c06eae6: /* original 7d04, guest PC 0x0c06eae6 */
if(!s->budget--) { s->failed_pc=0x0c06eae6u; return 0; }
r[13]+=0x00000004u;
goto P_0c06eae8;
P_0c06eae8: /* original 6e42, guest PC 0x0c06eae8 */
if(!s->budget--) { s->failed_pc=0x0c06eae8u; return 0; }
tmp=read(ram,r[4],4);
r[14]=tmp;
goto P_0c06eaea;
P_0c06eaea: /* original fd08, guest PC 0x0c06eaea */
if(!s->budget--) { s->failed_pc=0x0c06eaeau; return 0; }
vf3_matrix_load(s,ram,13,r[0]);
goto P_0c06eaec;
P_0c06eaec: /* original c73a, guest PC 0x0c06eaec */
if(!s->budget--) { s->failed_pc=0x0c06eaecu; return 0; }
r[0]=code_base|0x0006ebd8u;
goto P_0c06eaee;
P_0c06eaee: /* original a01a, guest PC 0x0c06eaee */
if(!s->budget--) { s->failed_pc=0x0c06eaeeu; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c06eb26;
P_0c06eaf0: /* original fc08, guest PC 0x0c06eaf0 */
if(!s->budget--) { s->failed_pc=0x0c06eaf0u; return 0; }
vf3_matrix_load(s,ram,12,r[0]);
goto P_0c06eaf2;
P_0c06eaf2: /* original fed9, guest PC 0x0c06eaf2 */
if(!s->budget--) { s->failed_pc=0x0c06eaf2u; return 0; }
vf3_matrix_load(s,ram,14,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06eaf4;
P_0c06eaf4: /* original 4a0b, guest PC 0x0c06eaf4 */
if(!s->budget--) { s->failed_pc=0x0c06eaf4u; return 0; }
target=r[10];
r[16]=code_base|0x0c06eaf8u;
vf3_matrix_load(s,ram,15,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06eaf8u) { target=s->pc; goto dispatch; }
goto P_0c06eaf8;
P_0c06eaf6: /* original ffd9, guest PC 0x0c06eaf6 */
if(!s->budget--) { s->failed_pc=0x0c06eaf6u; return 0; }
vf3_matrix_load(s,ram,15,r[13]);
r[13]+=(r[18]&0x100000u)?8:4;
goto P_0c06eaf8;
P_0c06eaf8: /* original f5fc, guest PC 0x0c06eaf8 */
if(!s->budget--) { s->failed_pc=0x0c06eaf8u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c06eafa;
P_0c06eafa: /* original 480b, guest PC 0x0c06eafa */
if(!s->budget--) { s->failed_pc=0x0c06eafau; return 0; }
target=r[8];
r[16]=code_base|0x0c06eafeu;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06eafeu) { target=s->pc; goto dispatch; }
goto P_0c06eafe;
P_0c06eafc: /* original f4ec, guest PC 0x0c06eafc */
if(!s->budget--) { s->failed_pc=0x0c06eafcu; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06eafe;
P_0c06eafe: /* original f6fc, guest PC 0x0c06eafe */
if(!s->budget--) { s->failed_pc=0x0c06eafeu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c06eb00;
P_0c06eb00: /* original f64d, guest PC 0x0c06eb00 */
if(!s->budget--) { s->failed_pc=0x0c06eb00u; return 0; }
fr[6]^=0x80000000u;
goto P_0c06eb02;
P_0c06eb02: /* original f50c, guest PC 0x0c06eb02 */
if(!s->budget--) { s->failed_pc=0x0c06eb02u; return 0; }
vf3_matrix_move(s,5,0);
goto P_0c06eb04;
P_0c06eb04: /* original 490b, guest PC 0x0c06eb04 */
if(!s->budget--) { s->failed_pc=0x0c06eb04u; return 0; }
target=r[9];
r[16]=code_base|0x0c06eb08u;
vf3_matrix_move(s,4,14);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06eb08u) { target=s->pc; goto dispatch; }
goto P_0c06eb08;
P_0c06eb06: /* original f4ec, guest PC 0x0c06eb06 */
if(!s->budget--) { s->failed_pc=0x0c06eb06u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c06eb08;
P_0c06eb08: /* original d334, guest PC 0x0c06eb08 */
if(!s->budget--) { s->failed_pc=0x0c06eb08u; return 0; }
r[3]=read(ram,0x0c06ebdcu,4);
goto P_0c06eb0a;
P_0c06eb0a: /* original f5cc, guest PC 0x0c06eb0a */
if(!s->budget--) { s->failed_pc=0x0c06eb0au; return 0; }
vf3_matrix_move(s,5,12);
goto P_0c06eb0c;
P_0c06eb0c: /* original f6dc, guest PC 0x0c06eb0c */
if(!s->budget--) { s->failed_pc=0x0c06eb0cu; return 0; }
vf3_matrix_move(s,6,13);
goto P_0c06eb0e;
P_0c06eb0e: /* original 430b, guest PC 0x0c06eb0e */
if(!s->budget--) { s->failed_pc=0x0c06eb0eu; return 0; }
target=r[3];
r[16]=code_base|0x0c06eb12u;
vf3_matrix_move(s,4,13);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06eb12u) { target=s->pc; goto dispatch; }
goto P_0c06eb12;
P_0c06eb10: /* original f4dc, guest PC 0x0c06eb10 */
if(!s->budget--) { s->failed_pc=0x0c06eb10u; return 0; }
vf3_matrix_move(s,4,13);
goto P_0c06eb12;
P_0c06eb12: /* original d333, guest PC 0x0c06eb12 */
if(!s->budget--) { s->failed_pc=0x0c06eb12u; return 0; }
r[3]=read(ram,0x0c06ebe0u,4);
goto P_0c06eb14;
P_0c06eb14: /* original 61e3, guest PC 0x0c06eb14 */
if(!s->budget--) { s->failed_pc=0x0c06eb14u; return 0; }
r[1]=r[14];
goto P_0c06eb16;
P_0c06eb16: /* original 71ff, guest PC 0x0c06eb16 */
if(!s->budget--) { s->failed_pc=0x0c06eb16u; return 0; }
r[1]+=0xffffffffu;
goto P_0c06eb18;
P_0c06eb18: /* original 430b, guest PC 0x0c06eb18 */
if(!s->budget--) { s->failed_pc=0x0c06eb18u; return 0; }
target=r[3];
r[16]=code_base|0x0c06eb1cu;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06eb1cu) { target=s->pc; goto dispatch; }
goto P_0c06eb1c;
P_0c06eb1a: /* original 60c3, guest PC 0x0c06eb1a */
if(!s->budget--) { s->failed_pc=0x0c06eb1au; return 0; }
r[0]=r[12];
goto P_0c06eb1c;
P_0c06eb1c: /* original d231, guest PC 0x0c06eb1c */
if(!s->budget--) { s->failed_pc=0x0c06eb1cu; return 0; }
r[2]=read(ram,0x0c06ebe4u,4);
goto P_0c06eb1e;
P_0c06eb1e: /* original 6403, guest PC 0x0c06eb1e */
if(!s->budget--) { s->failed_pc=0x0c06eb1eu; return 0; }
r[4]=r[0];
goto P_0c06eb20;
P_0c06eb20: /* original 420b, guest PC 0x0c06eb20 */
if(!s->budget--) { s->failed_pc=0x0c06eb20u; return 0; }
target=r[2];
r[16]=code_base|0x0c06eb24u;
r[4]+=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06eb24u) { target=s->pc; goto dispatch; }
goto P_0c06eb24;
P_0c06eb22: /* original 34bc, guest PC 0x0c06eb22 */
if(!s->budget--) { s->failed_pc=0x0c06eb22u; return 0; }
r[4]+=r[11];
goto P_0c06eb24;
P_0c06eb24: /* original 7eff, guest PC 0x0c06eb24 */
if(!s->budget--) { s->failed_pc=0x0c06eb24u; return 0; }
r[14]+=0xffffffffu;
goto P_0c06eb26;
P_0c06eb26: /* original 2ee8, guest PC 0x0c06eb26 */
if(!s->budget--) { s->failed_pc=0x0c06eb26u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c06eb28;
P_0c06eb28: /* original 8be3, guest PC 0x0c06eb28 */
if(!s->budget--) { s->failed_pc=0x0c06eb28u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06eaf2; }
goto P_0c06eb2a;
P_0c06eb2a: /* original 7f04, guest PC 0x0c06eb2a */
if(!s->budget--) { s->failed_pc=0x0c06eb2au; return 0; }
r[15]+=0x00000004u;
goto P_0c06eb2c;
P_0c06eb2c: /* original d22e, guest PC 0x0c06eb2c */
if(!s->budget--) { s->failed_pc=0x0c06eb2cu; return 0; }
r[2]=read(ram,0x0c06ebe8u,4);
goto P_0c06eb2e;
P_0c06eb2e: /* original 4f26, guest PC 0x0c06eb2e */
if(!s->budget--) { s->failed_pc=0x0c06eb2eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06eb30;
P_0c06eb30: /* original e401, guest PC 0x0c06eb30 */
if(!s->budget--) { s->failed_pc=0x0c06eb30u; return 0; }
r[4]=0x00000001u;
goto P_0c06eb32;
P_0c06eb32: /* original fcf9, guest PC 0x0c06eb32 */
if(!s->budget--) { s->failed_pc=0x0c06eb32u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb34;
P_0c06eb34: /* original fdf9, guest PC 0x0c06eb34 */
if(!s->budget--) { s->failed_pc=0x0c06eb34u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb36;
P_0c06eb36: /* original fef9, guest PC 0x0c06eb36 */
if(!s->budget--) { s->failed_pc=0x0c06eb36u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb38;
P_0c06eb38: /* original fff9, guest PC 0x0c06eb38 */
if(!s->budget--) { s->failed_pc=0x0c06eb38u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb3a;
P_0c06eb3a: /* original 68f6, guest PC 0x0c06eb3a */
if(!s->budget--) { s->failed_pc=0x0c06eb3au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06eb3c;
P_0c06eb3c: /* original 69f6, guest PC 0x0c06eb3c */
if(!s->budget--) { s->failed_pc=0x0c06eb3cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06eb3e;
P_0c06eb3e: /* original 6af6, guest PC 0x0c06eb3e */
if(!s->budget--) { s->failed_pc=0x0c06eb3eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06eb40;
P_0c06eb40: /* original 6bf6, guest PC 0x0c06eb40 */
if(!s->budget--) { s->failed_pc=0x0c06eb40u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06eb42;
P_0c06eb42: /* original 6cf6, guest PC 0x0c06eb42 */
if(!s->budget--) { s->failed_pc=0x0c06eb42u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06eb44;
P_0c06eb44: /* original 6df6, guest PC 0x0c06eb44 */
if(!s->budget--) { s->failed_pc=0x0c06eb44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06eb46;
P_0c06eb46: /* original 422b, guest PC 0x0c06eb46 */
if(!s->budget--) { s->failed_pc=0x0c06eb46u; return 0; }
target=r[2];
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
P_0c06eb48: /* original 6ef6, guest PC 0x0c06eb48 */
if(!s->budget--) { s->failed_pc=0x0c06eb48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c06eb4a;
P_0c06eb4a: /* original 7f04, guest PC 0x0c06eb4a */
if(!s->budget--) { s->failed_pc=0x0c06eb4au; return 0; }
r[15]+=0x00000004u;
goto P_0c06eb4c;
P_0c06eb4c: /* original 4f26, guest PC 0x0c06eb4c */
if(!s->budget--) { s->failed_pc=0x0c06eb4cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06eb4e;
P_0c06eb4e: /* original fcf9, guest PC 0x0c06eb4e */
if(!s->budget--) { s->failed_pc=0x0c06eb4eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb50;
P_0c06eb50: /* original fdf9, guest PC 0x0c06eb50 */
if(!s->budget--) { s->failed_pc=0x0c06eb50u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb52;
P_0c06eb52: /* original fef9, guest PC 0x0c06eb52 */
if(!s->budget--) { s->failed_pc=0x0c06eb52u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb54;
P_0c06eb54: /* original fff9, guest PC 0x0c06eb54 */
if(!s->budget--) { s->failed_pc=0x0c06eb54u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c06eb56;
P_0c06eb56: /* original 68f6, guest PC 0x0c06eb56 */
if(!s->budget--) { s->failed_pc=0x0c06eb56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06eb58;
P_0c06eb58: /* original 69f6, guest PC 0x0c06eb58 */
if(!s->budget--) { s->failed_pc=0x0c06eb58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06eb5a;
P_0c06eb5a: /* original 6af6, guest PC 0x0c06eb5a */
if(!s->budget--) { s->failed_pc=0x0c06eb5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06eb5c;
P_0c06eb5c: /* original 6bf6, guest PC 0x0c06eb5c */
if(!s->budget--) { s->failed_pc=0x0c06eb5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06eb5e;
P_0c06eb5e: /* original 6cf6, guest PC 0x0c06eb5e */
if(!s->budget--) { s->failed_pc=0x0c06eb5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06eb60;
P_0c06eb60: /* original 6df6, guest PC 0x0c06eb60 */
if(!s->budget--) { s->failed_pc=0x0c06eb60u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06eb62;
P_0c06eb62: /* original 000b, guest PC 0x0c06eb62 */
if(!s->budget--) { s->failed_pc=0x0c06eb62u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06eb64: /* original 6ef6, guest PC 0x0c06eb64 */
if(!s->budget--) { s->failed_pc=0x0c06eb64u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06eb66u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06eb66u; return 0; } return 1;
P_0c06ef3c: /* original 2fe6, guest PC 0x0c06ef3c */
if(!s->budget--) { s->failed_pc=0x0c06ef3cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef3e;
P_0c06ef3e: /* original 2fd6, guest PC 0x0c06ef3e */
if(!s->budget--) { s->failed_pc=0x0c06ef3eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef40;
P_0c06ef40: /* original 2fc6, guest PC 0x0c06ef40 */
if(!s->budget--) { s->failed_pc=0x0c06ef40u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef42;
P_0c06ef42: /* original 2fb6, guest PC 0x0c06ef42 */
if(!s->budget--) { s->failed_pc=0x0c06ef42u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef44;
P_0c06ef44: /* original 2fa6, guest PC 0x0c06ef44 */
if(!s->budget--) { s->failed_pc=0x0c06ef44u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef46;
P_0c06ef46: /* original 2f96, guest PC 0x0c06ef46 */
if(!s->budget--) { s->failed_pc=0x0c06ef46u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef48;
P_0c06ef48: /* original 2f86, guest PC 0x0c06ef48 */
if(!s->budget--) { s->failed_pc=0x0c06ef48u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c06ef4a;
P_0c06ef4a: /* original 4f22, guest PC 0x0c06ef4a */
if(!s->budget--) { s->failed_pc=0x0c06ef4au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c06ef4c;
P_0c06ef4c: /* original d33d, guest PC 0x0c06ef4c */
if(!s->budget--) { s->failed_pc=0x0c06ef4cu; return 0; }
r[3]=read(ram,0x0c06f044u,4);
goto P_0c06ef4e;
P_0c06ef4e: /* original dd3c, guest PC 0x0c06ef4e */
if(!s->budget--) { s->failed_pc=0x0c06ef4eu; return 0; }
r[13]=read(ram,0x0c06f040u,4);
goto P_0c06ef50;
P_0c06ef50: /* original 4f12, guest PC 0x0c06ef50 */
if(!s->budget--) { s->failed_pc=0x0c06ef50u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c06ef52;
P_0c06ef52: /* original 430b, guest PC 0x0c06ef52 */
if(!s->budget--) { s->failed_pc=0x0c06ef52u; return 0; }
target=r[3];
r[16]=code_base|0x0c06ef56u;
r[14]=r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06ef56u) { target=s->pc; goto dispatch; }
goto P_0c06ef56;
P_0c06ef54: /* original 6e43, guest PC 0x0c06ef54 */
if(!s->budget--) { s->failed_pc=0x0c06ef54u; return 0; }
r[14]=r[4];
goto P_0c06ef56;
P_0c06ef56: /* original 2008, guest PC 0x0c06ef56 */
if(!s->budget--) { s->failed_pc=0x0c06ef56u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ef58;
P_0c06ef58: /* original 8964, guest PC 0x0c06ef58 */
if(!s->budget--) { s->failed_pc=0x0c06ef58u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f024; }
goto P_0c06ef5a;
P_0c06ef5a: /* original 84e4, guest PC 0x0c06ef5a */
if(!s->budget--) { s->failed_pc=0x0c06ef5au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+4,1);
goto P_0c06ef5c;
P_0c06ef5c: /* original d43a, guest PC 0x0c06ef5c */
if(!s->budget--) { s->failed_pc=0x0c06ef5cu; return 0; }
r[4]=read(ram,0x0c06f048u,4);
goto P_0c06ef5e;
P_0c06ef5e: /* original 2008, guest PC 0x0c06ef5e */
if(!s->budget--) { s->failed_pc=0x0c06ef5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c06ef60;
P_0c06ef60: /* original 8b01, guest PC 0x0c06ef60 */
if(!s->budget--) { s->failed_pc=0x0c06ef60u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ef66; }
goto P_0c06ef62;
P_0c06ef62: /* original a001, guest PC 0x0c06ef62 */
if(!s->budget--) { s->failed_pc=0x0c06ef62u; return 0; }
r[11]=read(ram,r[4]+16,4);
goto P_0c06ef68;
P_0c06ef64: /* original 5b44, guest PC 0x0c06ef64 */
if(!s->budget--) { s->failed_pc=0x0c06ef64u; return 0; }
r[11]=read(ram,r[4]+16,4);
goto P_0c06ef66;
P_0c06ef66: /* original 5b45, guest PC 0x0c06ef66 */
if(!s->budget--) { s->failed_pc=0x0c06ef66u; return 0; }
r[11]=read(ram,r[4]+20,4);
goto P_0c06ef68;
P_0c06ef68: /* original 62b2, guest PC 0x0c06ef68 */
if(!s->budget--) { s->failed_pc=0x0c06ef68u; return 0; }
tmp=read(ram,r[11],4);
r[2]=tmp;
goto P_0c06ef6a;
P_0c06ef6a: /* original d338, guest PC 0x0c06ef6a */
if(!s->budget--) { s->failed_pc=0x0c06ef6au; return 0; }
r[3]=read(ram,0x0c06f04cu,4);
goto P_0c06ef6c;
P_0c06ef6c: /* original 2238, guest PC 0x0c06ef6c */
if(!s->budget--) { s->failed_pc=0x0c06ef6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c06ef6e;
P_0c06ef6e: /* original 8b05, guest PC 0x0c06ef6e */
if(!s->budget--) { s->failed_pc=0x0c06ef6eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06ef7c; }
goto P_0c06ef70;
P_0c06ef70: /* original 61e2, guest PC 0x0c06ef70 */
if(!s->budget--) { s->failed_pc=0x0c06ef70u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c06ef72;
P_0c06ef72: /* original d237, guest PC 0x0c06ef72 */
if(!s->budget--) { s->failed_pc=0x0c06ef72u; return 0; }
r[2]=read(ram,0x0c06f050u,4);
goto P_0c06ef74;
P_0c06ef74: /* original 2129, guest PC 0x0c06ef74 */
if(!s->budget--) { s->failed_pc=0x0c06ef74u; return 0; }
r[1]&=r[2];
goto P_0c06ef76;
P_0c06ef76: /* original 2e12, guest PC 0x0c06ef76 */
if(!s->budget--) { s->failed_pc=0x0c06ef76u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c06ef78;
P_0c06ef78: /* original a054, guest PC 0x0c06ef78 */
if(!s->budget--) { s->failed_pc=0x0c06ef78u; return 0; }
goto P_0c06f024;
P_0c06ef7a: /* original 0009, guest PC 0x0c06ef7a */
if(!s->budget--) { s->failed_pc=0x0c06ef7au; return 0; }
goto P_0c06ef7c;
P_0c06ef7c: /* original d335, guest PC 0x0c06ef7c */
if(!s->budget--) { s->failed_pc=0x0c06ef7cu; return 0; }
r[3]=read(ram,0x0c06f054u,4);
goto P_0c06ef7e;
P_0c06ef7e: /* original e060, guest PC 0x0c06ef7e */
if(!s->budget--) { s->failed_pc=0x0c06ef7eu; return 0; }
r[0]=0x00000060u;
goto P_0c06ef80;
P_0c06ef80: /* original 1e33, guest PC 0x0c06ef80 */
if(!s->budget--) { s->failed_pc=0x0c06ef80u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c06ef82;
P_0c06ef82: /* original d335, guest PC 0x0c06ef82 */
if(!s->budget--) { s->failed_pc=0x0c06ef82u; return 0; }
r[3]=read(ram,0x0c06f058u,4);
goto P_0c06ef84;
P_0c06ef84: /* original 62e2, guest PC 0x0c06ef84 */
if(!s->budget--) { s->failed_pc=0x0c06ef84u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c06ef86;
P_0c06ef86: /* original 223b, guest PC 0x0c06ef86 */
if(!s->budget--) { s->failed_pc=0x0c06ef86u; return 0; }
r[2]|=r[3];
goto P_0c06ef88;
P_0c06ef88: /* original 2e22, guest PC 0x0c06ef88 */
if(!s->budget--) { s->failed_pc=0x0c06ef88u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c06ef8a;
P_0c06ef8a: /* original 04bc, guest PC 0x0c06ef8a */
if(!s->budget--) { s->failed_pc=0x0c06ef8au; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c06ef8c;
P_0c06ef8c: /* original 604c, guest PC 0x0c06ef8c */
if(!s->budget--) { s->failed_pc=0x0c06ef8cu; return 0; }
r[0]=r[4]&255u;
goto P_0c06ef8e;
P_0c06ef8e: /* original 880b, guest PC 0x0c06ef8e */
if(!s->budget--) { s->failed_pc=0x0c06ef8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c06ef90;
P_0c06ef90: /* original 8f06, guest PC 0x0c06ef90 */
if(!s->budget--) { s->failed_pc=0x0c06ef90u; return 0; }
cond=r[17]&1u;
r[4]=r[0];
if(!cond) { goto P_0c06efa0; }
goto P_0c06ef94;
P_0c06ef92: /* original 6403, guest PC 0x0c06ef92 */
if(!s->budget--) { s->failed_pc=0x0c06ef92u; return 0; }
r[4]=r[0];
goto P_0c06ef94;
P_0c06ef94: /* original 9050, guest PC 0x0c06ef94 */
if(!s->budget--) { s->failed_pc=0x0c06ef94u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f038u,2);
goto P_0c06ef96;
P_0c06ef96: /* original 01dc, guest PC 0x0c06ef96 */
if(!s->budget--) { s->failed_pc=0x0c06ef96u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06ef98;
P_0c06ef98: /* original 2118, guest PC 0x0c06ef98 */
if(!s->budget--) { s->failed_pc=0x0c06ef98u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c06ef9a;
P_0c06ef9a: /* original 8911, guest PC 0x0c06ef9a */
if(!s->budget--) { s->failed_pc=0x0c06ef9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06efc0; }
goto P_0c06ef9c;
P_0c06ef9c: /* original a010, guest PC 0x0c06ef9c */
if(!s->budget--) { s->failed_pc=0x0c06ef9cu; return 0; }
r[4]=0x0000001au;
goto P_0c06efc0;
P_0c06ef9e: /* original e41a, guest PC 0x0c06ef9e */
if(!s->budget--) { s->failed_pc=0x0c06ef9eu; return 0; }
r[4]=0x0000001au;
goto P_0c06efa0;
P_0c06efa0: /* original 6043, guest PC 0x0c06efa0 */
if(!s->budget--) { s->failed_pc=0x0c06efa0u; return 0; }
r[0]=r[4];
goto P_0c06efa2;
P_0c06efa2: /* original 8818, guest PC 0x0c06efa2 */
if(!s->budget--) { s->failed_pc=0x0c06efa2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000018u)!=0);
goto P_0c06efa4;
P_0c06efa4: /* original 8b05, guest PC 0x0c06efa4 */
if(!s->budget--) { s->failed_pc=0x0c06efa4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06efb2; }
goto P_0c06efa6;
P_0c06efa6: /* original 9047, guest PC 0x0c06efa6 */
if(!s->budget--) { s->failed_pc=0x0c06efa6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f038u,2);
goto P_0c06efa8;
P_0c06efa8: /* original 01dc, guest PC 0x0c06efa8 */
if(!s->budget--) { s->failed_pc=0x0c06efa8u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06efaa;
P_0c06efaa: /* original 2118, guest PC 0x0c06efaa */
if(!s->budget--) { s->failed_pc=0x0c06efaau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c06efac;
P_0c06efac: /* original 8908, guest PC 0x0c06efac */
if(!s->budget--) { s->failed_pc=0x0c06efacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06efc0; }
goto P_0c06efae;
P_0c06efae: /* original a007, guest PC 0x0c06efae */
if(!s->budget--) { s->failed_pc=0x0c06efaeu; return 0; }
r[4]=0x0000001bu;
goto P_0c06efc0;
P_0c06efb0: /* original e41b, guest PC 0x0c06efb0 */
if(!s->budget--) { s->failed_pc=0x0c06efb0u; return 0; }
r[4]=0x0000001bu;
goto P_0c06efb2;
P_0c06efb2: /* original 880c, guest PC 0x0c06efb2 */
if(!s->budget--) { s->failed_pc=0x0c06efb2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c06efb4;
P_0c06efb4: /* original 8b04, guest PC 0x0c06efb4 */
if(!s->budget--) { s->failed_pc=0x0c06efb4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06efc0; }
goto P_0c06efb6;
P_0c06efb6: /* original 9040, guest PC 0x0c06efb6 */
if(!s->budget--) { s->failed_pc=0x0c06efb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f03au,2);
goto P_0c06efb8;
P_0c06efb8: /* original 01dc, guest PC 0x0c06efb8 */
if(!s->budget--) { s->failed_pc=0x0c06efb8u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c06efba;
P_0c06efba: /* original 2118, guest PC 0x0c06efba */
if(!s->budget--) { s->failed_pc=0x0c06efbau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c06efbc;
P_0c06efbc: /* original 8900, guest PC 0x0c06efbc */
if(!s->budget--) { s->failed_pc=0x0c06efbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06efc0; }
goto P_0c06efbe;
P_0c06efbe: /* original e41c, guest PC 0x0c06efbe */
if(!s->budget--) { s->failed_pc=0x0c06efbeu; return 0; }
r[4]=0x0000001cu;
goto P_0c06efc0;
P_0c06efc0: /* original d326, guest PC 0x0c06efc0 */
if(!s->budget--) { s->failed_pc=0x0c06efc0u; return 0; }
r[3]=read(ram,0x0c06f05cu,4);
goto P_0c06efc2;
P_0c06efc2: /* original 4400, guest PC 0x0c06efc2 */
if(!s->budget--) { s->failed_pc=0x0c06efc2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c06efc4;
P_0c06efc4: /* original 4408, guest PC 0x0c06efc4 */
if(!s->budget--) { s->failed_pc=0x0c06efc4u; return 0; }
r[4]<<=2;
goto P_0c06efc6;
P_0c06efc6: /* original 343c, guest PC 0x0c06efc6 */
if(!s->budget--) { s->failed_pc=0x0c06efc6u; return 0; }
r[4]+=r[3];
goto P_0c06efc8;
P_0c06efc8: /* original 6c42, guest PC 0x0c06efc8 */
if(!s->budget--) { s->failed_pc=0x0c06efc8u; return 0; }
tmp=read(ram,r[4],4);
r[12]=tmp;
goto P_0c06efca;
P_0c06efca: /* original 2cc8, guest PC 0x0c06efca */
if(!s->budget--) { s->failed_pc=0x0c06efcau; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c06efcc;
P_0c06efcc: /* original 892a, guest PC 0x0c06efcc */
if(!s->budget--) { s->failed_pc=0x0c06efccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c06f024; }
goto P_0c06efce;
P_0c06efce: /* original 84b4, guest PC 0x0c06efce */
if(!s->budget--) { s->failed_pc=0x0c06efceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+4,1);
goto P_0c06efd0;
P_0c06efd0: /* original 9534, guest PC 0x0c06efd0 */
if(!s->budget--) { s->failed_pc=0x0c06efd0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f03cu,2);
goto P_0c06efd2;
P_0c06efd2: /* original 600c, guest PC 0x0c06efd2 */
if(!s->budget--) { s->failed_pc=0x0c06efd2u; return 0; }
r[0]=r[0]&255u;
goto P_0c06efd4;
P_0c06efd4: /* original d822, guest PC 0x0c06efd4 */
if(!s->budget--) { s->failed_pc=0x0c06efd4u; return 0; }
r[8]=read(ram,0x0c06f060u,4);
goto P_0c06efd6;
P_0c06efd6: /* original 205f, guest PC 0x0c06efd6 */
if(!s->budget--) { s->failed_pc=0x0c06efd6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[0]*(int32_t)(int16_t)r[5]);
goto P_0c06efd8;
P_0c06efd8: /* original da22, guest PC 0x0c06efd8 */
if(!s->budget--) { s->failed_pc=0x0c06efd8u; return 0; }
r[10]=read(ram,0x0c06f064u,4);
goto P_0c06efda;
P_0c06efda: /* original 5441, guest PC 0x0c06efda */
if(!s->budget--) { s->failed_pc=0x0c06efdau; return 0; }
r[4]=read(ram,r[4]+4,4);
goto P_0c06efdc;
P_0c06efdc: /* original 051a, guest PC 0x0c06efdc */
if(!s->budget--) { s->failed_pc=0x0c06efdcu; return 0; }
r[5]=r[19];
goto P_0c06efde;
P_0c06efde: /* original 1e44, guest PC 0x0c06efde */
if(!s->budget--) { s->failed_pc=0x0c06efdeu; return 0; }
write(ram,r[14]+16,r[4],4);
goto P_0c06efe0;
P_0c06efe0: /* original 655f, guest PC 0x0c06efe0 */
if(!s->budget--) { s->failed_pc=0x0c06efe0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)r[5];
goto P_0c06efe2;
P_0c06efe2: /* original 3a5c, guest PC 0x0c06efe2 */
if(!s->budget--) { s->failed_pc=0x0c06efe2u; return 0; }
r[10]+=r[5];
goto P_0c06efe4;
P_0c06efe4: /* original 385c, guest PC 0x0c06efe4 */
if(!s->budget--) { s->failed_pc=0x0c06efe4u; return 0; }
r[8]+=r[5];
goto P_0c06efe6;
P_0c06efe6: /* original a01a, guest PC 0x0c06efe6 */
if(!s->budget--) { s->failed_pc=0x0c06efe6u; return 0; }
r[9]=0x00000000u;
goto P_0c06f01e;
P_0c06efe8: /* original e900, guest PC 0x0c06efe8 */
if(!s->budget--) { s->failed_pc=0x0c06efe8u; return 0; }
r[9]=0x00000000u;
goto P_0c06efea;
P_0c06efea: /* original 9d28, guest PC 0x0c06efea */
if(!s->budget--) { s->failed_pc=0x0c06efeau; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c06f03eu,2);
goto P_0c06efec;
P_0c06efec: /* original 63e3, guest PC 0x0c06efec */
if(!s->budget--) { s->failed_pc=0x0c06efecu; return 0; }
r[3]=r[14];
goto P_0c06efee;
P_0c06efee: /* original 62c2, guest PC 0x0c06efee */
if(!s->budget--) { s->failed_pc=0x0c06efeeu; return 0; }
tmp=read(ram,r[12],4);
r[2]=tmp;
goto P_0c06eff0;
P_0c06eff0: /* original 7314, guest PC 0x0c06eff0 */
if(!s->budget--) { s->failed_pc=0x0c06eff0u; return 0; }
r[3]+=0x00000014u;
goto P_0c06eff2;
P_0c06eff2: /* original 29df, guest PC 0x0c06eff2 */
if(!s->budget--) { s->failed_pc=0x0c06eff2u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[9]*(int32_t)(int16_t)r[13]);
goto P_0c06eff4;
P_0c06eff4: /* original e068, guest PC 0x0c06eff4 */
if(!s->budget--) { s->failed_pc=0x0c06eff4u; return 0; }
r[0]=0x00000068u;
goto P_0c06eff6;
P_0c06eff6: /* original 56c1, guest PC 0x0c06eff6 */
if(!s->budget--) { s->failed_pc=0x0c06eff6u; return 0; }
r[6]=read(ram,r[12]+4,4);
goto P_0c06eff8;
P_0c06eff8: /* original 6783, guest PC 0x0c06eff8 */
if(!s->budget--) { s->failed_pc=0x0c06eff8u; return 0; }
r[7]=r[8];
goto P_0c06effa;
P_0c06effa: /* original 0d1a, guest PC 0x0c06effa */
if(!s->budget--) { s->failed_pc=0x0c06effau; return 0; }
r[13]=r[19];
goto P_0c06effc;
P_0c06effc: /* original 6ddf, guest PC 0x0c06effc */
if(!s->budget--) { s->failed_pc=0x0c06effcu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)r[13];
goto P_0c06effe;
P_0c06effe: /* original 3d3c, guest PC 0x0c06effe */
if(!s->budget--) { s->failed_pc=0x0c06effeu; return 0; }
r[13]+=r[3];
goto P_0c06f000;
P_0c06f000: /* original 65d3, guest PC 0x0c06f000 */
if(!s->budget--) { s->failed_pc=0x0c06f000u; return 0; }
r[5]=r[13];
goto P_0c06f002;
P_0c06f002: /* original 0d26, guest PC 0x0c06f002 */
if(!s->budget--) { s->failed_pc=0x0c06f002u; return 0; }
write(ram,r[13]+r[0],r[2],4);
goto P_0c06f004;
P_0c06f004: /* original b030, guest PC 0x0c06f004 */
if(!s->budget--) { s->failed_pc=0x0c06f004u; return 0; }
target=code_base|0x0c06f068u; r[16]=code_base|0x0c06f008u;
r[4]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c06f008u) { target=s->pc; goto dispatch; }
goto P_0c06f008;
P_0c06f006: /* original 64b3, guest PC 0x0c06f006 */
if(!s->budget--) { s->failed_pc=0x0c06f006u; return 0; }
r[4]=r[11];
goto P_0c06f008;
P_0c06f008: /* original 1da2, guest PC 0x0c06f008 */
if(!s->budget--) { s->failed_pc=0x0c06f008u; return 0; }
write(ram,r[13]+8,r[10],4);
goto P_0c06f00a;
P_0c06f00a: /* original 7c0c, guest PC 0x0c06f00a */
if(!s->budget--) { s->failed_pc=0x0c06f00au; return 0; }
r[12]+=0x0000000cu;
goto P_0c06f00c;
P_0c06f00c: /* original 62d2, guest PC 0x0c06f00c */
if(!s->budget--) { s->failed_pc=0x0c06f00cu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c06f00e;
P_0c06f00e: /* original 7901, guest PC 0x0c06f00e */
if(!s->budget--) { s->failed_pc=0x0c06f00eu; return 0; }
r[9]+=0x00000001u;
goto P_0c06f010;
P_0c06f010: /* original 6803, guest PC 0x0c06f010 */
if(!s->budget--) { s->failed_pc=0x0c06f010u; return 0; }
r[8]=r[0];
goto P_0c06f012;
P_0c06f012: /* original 6323, guest PC 0x0c06f012 */
if(!s->budget--) { s->failed_pc=0x0c06f012u; return 0; }
r[3]=r[2];
goto P_0c06f014;
P_0c06f014: /* original 4200, guest PC 0x0c06f014 */
if(!s->budget--) { s->failed_pc=0x0c06f014u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c06f016;
P_0c06f016: /* original 323c, guest PC 0x0c06f016 */
if(!s->budget--) { s->failed_pc=0x0c06f016u; return 0; }
r[2]+=r[3];
goto P_0c06f018;
P_0c06f018: /* original 4208, guest PC 0x0c06f018 */
if(!s->budget--) { s->failed_pc=0x0c06f018u; return 0; }
r[2]<<=2;
goto P_0c06f01a;
P_0c06f01a: /* original 4200, guest PC 0x0c06f01a */
if(!s->budget--) { s->failed_pc=0x0c06f01au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c06f01c;
P_0c06f01c: /* original 3a2c, guest PC 0x0c06f01c */
if(!s->budget--) { s->failed_pc=0x0c06f01cu; return 0; }
r[10]+=r[2];
goto P_0c06f01e;
P_0c06f01e: /* original 52e4, guest PC 0x0c06f01e */
if(!s->budget--) { s->failed_pc=0x0c06f01eu; return 0; }
r[2]=read(ram,r[14]+16,4);
goto P_0c06f020;
P_0c06f020: /* original 3923, guest PC 0x0c06f020 */
if(!s->budget--) { s->failed_pc=0x0c06f020u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[9]>=(int32_t)r[2])!=0);
goto P_0c06f022;
P_0c06f022: /* original 8be2, guest PC 0x0c06f022 */
if(!s->budget--) { s->failed_pc=0x0c06f022u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c06efea; }
goto P_0c06f024;
P_0c06f024: /* original 4f16, guest PC 0x0c06f024 */
if(!s->budget--) { s->failed_pc=0x0c06f024u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f026;
P_0c06f026: /* original 4f26, guest PC 0x0c06f026 */
if(!s->budget--) { s->failed_pc=0x0c06f026u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c06f028;
P_0c06f028: /* original 68f6, guest PC 0x0c06f028 */
if(!s->budget--) { s->failed_pc=0x0c06f028u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c06f02a;
P_0c06f02a: /* original 69f6, guest PC 0x0c06f02a */
if(!s->budget--) { s->failed_pc=0x0c06f02au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c06f02c;
P_0c06f02c: /* original 6af6, guest PC 0x0c06f02c */
if(!s->budget--) { s->failed_pc=0x0c06f02cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c06f02e;
P_0c06f02e: /* original 6bf6, guest PC 0x0c06f02e */
if(!s->budget--) { s->failed_pc=0x0c06f02eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c06f030;
P_0c06f030: /* original 6cf6, guest PC 0x0c06f030 */
if(!s->budget--) { s->failed_pc=0x0c06f030u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c06f032;
P_0c06f032: /* original 6df6, guest PC 0x0c06f032 */
if(!s->budget--) { s->failed_pc=0x0c06f032u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c06f034;
P_0c06f034: /* original 000b, guest PC 0x0c06f034 */
if(!s->budget--) { s->failed_pc=0x0c06f034u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c06f036: /* original 6ef6, guest PC 0x0c06f036 */
if(!s->budget--) { s->failed_pc=0x0c06f036u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c06f038u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c06f038u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
