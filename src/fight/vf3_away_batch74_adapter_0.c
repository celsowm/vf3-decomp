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
int vf3_away_batch74_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c09af6cu: goto P_0c09af6c;
case 0x0c09af6eu: goto P_0c09af6e;
case 0x0c09af70u: goto P_0c09af70;
case 0x0c09af72u: goto P_0c09af72;
case 0x0c09af74u: goto P_0c09af74;
case 0x0c09af76u: goto P_0c09af76;
case 0x0c09af78u: goto P_0c09af78;
case 0x0c09af7au: goto P_0c09af7a;
case 0x0c09af7cu: goto P_0c09af7c;
case 0x0c09af7eu: goto P_0c09af7e;
case 0x0c09af80u: goto P_0c09af80;
case 0x0c09af82u: goto P_0c09af82;
case 0x0c09af84u: goto P_0c09af84;
case 0x0c09af86u: goto P_0c09af86;
case 0x0c09af88u: goto P_0c09af88;
case 0x0c09af8au: goto P_0c09af8a;
case 0x0c09af8cu: goto P_0c09af8c;
case 0x0c09af8eu: goto P_0c09af8e;
case 0x0c09af90u: goto P_0c09af90;
case 0x0c09af92u: goto P_0c09af92;
case 0x0c09af94u: goto P_0c09af94;
case 0x0c09af96u: goto P_0c09af96;
case 0x0c09af98u: goto P_0c09af98;
case 0x0c09af9au: goto P_0c09af9a;
case 0x0c09af9cu: goto P_0c09af9c;
case 0x0c09af9eu: goto P_0c09af9e;
case 0x0c09afa0u: goto P_0c09afa0;
case 0x0c09afa2u: goto P_0c09afa2;
case 0x0c09afa4u: goto P_0c09afa4;
case 0x0c09afa6u: goto P_0c09afa6;
case 0x0c09afa8u: goto P_0c09afa8;
case 0x0c09afaau: goto P_0c09afaa;
case 0x0c09afacu: goto P_0c09afac;
case 0x0c09afaeu: goto P_0c09afae;
case 0x0c09afb0u: goto P_0c09afb0;
case 0x0c09afb2u: goto P_0c09afb2;
case 0x0c09afb4u: goto P_0c09afb4;
case 0x0c09afb6u: goto P_0c09afb6;
case 0x0c09afb8u: goto P_0c09afb8;
case 0x0c09afbau: goto P_0c09afba;
case 0x0c09afbcu: goto P_0c09afbc;
case 0x0c09afbeu: goto P_0c09afbe;
case 0x0c09ce8cu: goto P_0c09ce8c;
case 0x0c09ce8eu: goto P_0c09ce8e;
case 0x0c09ce90u: goto P_0c09ce90;
case 0x0c09ce92u: goto P_0c09ce92;
case 0x0c09ce94u: goto P_0c09ce94;
case 0x0c09ce96u: goto P_0c09ce96;
case 0x0c09ce98u: goto P_0c09ce98;
case 0x0c09ce9au: goto P_0c09ce9a;
case 0x0c09ce9cu: goto P_0c09ce9c;
case 0x0c09ce9eu: goto P_0c09ce9e;
case 0x0c09cea0u: goto P_0c09cea0;
case 0x0c09cea2u: goto P_0c09cea2;
case 0x0c09cea4u: goto P_0c09cea4;
case 0x0c09cea6u: goto P_0c09cea6;
case 0x0c09cea8u: goto P_0c09cea8;
case 0x0c09ceaau: goto P_0c09ceaa;
case 0x0c09ceacu: goto P_0c09ceac;
case 0x0c09ceaeu: goto P_0c09ceae;
case 0x0c09ceb0u: goto P_0c09ceb0;
case 0x0c09ceb2u: goto P_0c09ceb2;
case 0x0c09ceb4u: goto P_0c09ceb4;
case 0x0c09ceb6u: goto P_0c09ceb6;
case 0x0c09ceb8u: goto P_0c09ceb8;
case 0x0c09cebau: goto P_0c09ceba;
case 0x0c09cebcu: goto P_0c09cebc;
case 0x0c09cebeu: goto P_0c09cebe;
case 0x0c09cec0u: goto P_0c09cec0;
case 0x0c09cec2u: goto P_0c09cec2;
case 0x0c09cec4u: goto P_0c09cec4;
case 0x0c09cec6u: goto P_0c09cec6;
case 0x0c09cec8u: goto P_0c09cec8;
case 0x0c09cecau: goto P_0c09ceca;
case 0x0c09ceccu: goto P_0c09cecc;
case 0x0c09ceceu: goto P_0c09cece;
case 0x0c09ced0u: goto P_0c09ced0;
case 0x0c09ced2u: goto P_0c09ced2;
case 0x0c09ced4u: goto P_0c09ced4;
case 0x0c09ced6u: goto P_0c09ced6;
case 0x0c09ced8u: goto P_0c09ced8;
case 0x0c09cedau: goto P_0c09ceda;
case 0x0c09cedcu: goto P_0c09cedc;
case 0x0c09cedeu: goto P_0c09cede;
case 0x0c09cee0u: goto P_0c09cee0;
case 0x0c09cee2u: goto P_0c09cee2;
case 0x0c09cee4u: goto P_0c09cee4;
case 0x0c09cee6u: goto P_0c09cee6;
case 0x0c09cee8u: goto P_0c09cee8;
case 0x0c09ceeau: goto P_0c09ceea;
case 0x0c09ceecu: goto P_0c09ceec;
case 0x0c09ceeeu: goto P_0c09ceee;
case 0x0c09cef0u: goto P_0c09cef0;
case 0x0c09cef2u: goto P_0c09cef2;
case 0x0c09cef4u: goto P_0c09cef4;
case 0x0c09cef6u: goto P_0c09cef6;
case 0x0c09cef8u: goto P_0c09cef8;
case 0x0c09cefau: goto P_0c09cefa;
case 0x0c09cefcu: goto P_0c09cefc;
case 0x0c09cefeu: goto P_0c09cefe;
case 0x0c09cf00u: goto P_0c09cf00;
case 0x0c09cf02u: goto P_0c09cf02;
case 0x0c09cf04u: goto P_0c09cf04;
case 0x0c09cf06u: goto P_0c09cf06;
case 0x0c09cf08u: goto P_0c09cf08;
case 0x0c09cf0au: goto P_0c09cf0a;
case 0x0c09cf0cu: goto P_0c09cf0c;
case 0x0c09cf0eu: goto P_0c09cf0e;
case 0x0c09cf10u: goto P_0c09cf10;
case 0x0c09cf12u: goto P_0c09cf12;
case 0x0c09cf14u: goto P_0c09cf14;
case 0x0c09cf16u: goto P_0c09cf16;
case 0x0c09cf18u: goto P_0c09cf18;
case 0x0c09cf1au: goto P_0c09cf1a;
case 0x0c09cf1cu: goto P_0c09cf1c;
case 0x0c09cf1eu: goto P_0c09cf1e;
case 0x0c09cf20u: goto P_0c09cf20;
case 0x0c09cf22u: goto P_0c09cf22;
case 0x0c09cf24u: goto P_0c09cf24;
case 0x0c09cf26u: goto P_0c09cf26;
case 0x0c09cf28u: goto P_0c09cf28;
case 0x0c09cf2au: goto P_0c09cf2a;
case 0x0c09cf2cu: goto P_0c09cf2c;
case 0x0c09cf2eu: goto P_0c09cf2e;
case 0x0c09cf30u: goto P_0c09cf30;
case 0x0c09cf32u: goto P_0c09cf32;
case 0x0c09cf34u: goto P_0c09cf34;
case 0x0c09cf36u: goto P_0c09cf36;
case 0x0c09cf38u: goto P_0c09cf38;
case 0x0c09cf3au: goto P_0c09cf3a;
case 0x0c09cf3cu: goto P_0c09cf3c;
case 0x0c09cf3eu: goto P_0c09cf3e;
case 0x0c09cf40u: goto P_0c09cf40;
case 0x0c09cf42u: goto P_0c09cf42;
case 0x0c09cf44u: goto P_0c09cf44;
case 0x0c09cf46u: goto P_0c09cf46;
case 0x0c09cf48u: goto P_0c09cf48;
case 0x0c09cf4au: goto P_0c09cf4a;
case 0x0c09cf4cu: goto P_0c09cf4c;
case 0x0c09cf4eu: goto P_0c09cf4e;
case 0x0c09cf50u: goto P_0c09cf50;
case 0x0c09cf52u: goto P_0c09cf52;
case 0x0c09cf54u: goto P_0c09cf54;
case 0x0c09cf56u: goto P_0c09cf56;
case 0x0c09cf58u: goto P_0c09cf58;
case 0x0c09cf5au: goto P_0c09cf5a;
case 0x0c09cf5cu: goto P_0c09cf5c;
case 0x0c09cfacu: goto P_0c09cfac;
case 0x0c09cfaeu: goto P_0c09cfae;
case 0x0c09cfb0u: goto P_0c09cfb0;
case 0x0c09cfb2u: goto P_0c09cfb2;
case 0x0c09cfb4u: goto P_0c09cfb4;
case 0x0c09cfb6u: goto P_0c09cfb6;
case 0x0c09cfb8u: goto P_0c09cfb8;
case 0x0c09cfbau: goto P_0c09cfba;
case 0x0c09cfbcu: goto P_0c09cfbc;
case 0x0c09cfbeu: goto P_0c09cfbe;
case 0x0c09cfc0u: goto P_0c09cfc0;
case 0x0c09cfc2u: goto P_0c09cfc2;
case 0x0c09cfc4u: goto P_0c09cfc4;
case 0x0c09cfc6u: goto P_0c09cfc6;
case 0x0c09cfc8u: goto P_0c09cfc8;
case 0x0c09cfcau: goto P_0c09cfca;
case 0x0c09cfccu: goto P_0c09cfcc;
case 0x0c09cfceu: goto P_0c09cfce;
case 0x0c09cfd0u: goto P_0c09cfd0;
case 0x0c09cfd2u: goto P_0c09cfd2;
case 0x0c09cfd4u: goto P_0c09cfd4;
case 0x0c09cfd6u: goto P_0c09cfd6;
case 0x0c09cfd8u: goto P_0c09cfd8;
case 0x0c09cfdau: goto P_0c09cfda;
case 0x0c09cfdcu: goto P_0c09cfdc;
case 0x0c09cfdeu: goto P_0c09cfde;
case 0x0c09cfe0u: goto P_0c09cfe0;
case 0x0c09cfe2u: goto P_0c09cfe2;
case 0x0c09cfe4u: goto P_0c09cfe4;
case 0x0c09cfe6u: goto P_0c09cfe6;
case 0x0c09cfe8u: goto P_0c09cfe8;
case 0x0c09cfeau: goto P_0c09cfea;
case 0x0c09cfecu: goto P_0c09cfec;
case 0x0c09cfeeu: goto P_0c09cfee;
case 0x0c09cff0u: goto P_0c09cff0;
case 0x0c09cff2u: goto P_0c09cff2;
case 0x0c09cff4u: goto P_0c09cff4;
case 0x0c09cff6u: goto P_0c09cff6;
case 0x0c09cff8u: goto P_0c09cff8;
case 0x0c09cffau: goto P_0c09cffa;
case 0x0c09cffcu: goto P_0c09cffc;
case 0x0c09cffeu: goto P_0c09cffe;
case 0x0c09d000u: goto P_0c09d000;
case 0x0c09d002u: goto P_0c09d002;
case 0x0c09d004u: goto P_0c09d004;
case 0x0c09d006u: goto P_0c09d006;
case 0x0c09d008u: goto P_0c09d008;
case 0x0c09d00au: goto P_0c09d00a;
case 0x0c09d00cu: goto P_0c09d00c;
case 0x0c09d00eu: goto P_0c09d00e;
case 0x0c09d010u: goto P_0c09d010;
case 0x0c09d012u: goto P_0c09d012;
case 0x0c09d014u: goto P_0c09d014;
case 0x0c09d016u: goto P_0c09d016;
case 0x0c09d018u: goto P_0c09d018;
case 0x0c09d01au: goto P_0c09d01a;
case 0x0c09d01cu: goto P_0c09d01c;
case 0x0c09d01eu: goto P_0c09d01e;
case 0x0c09d020u: goto P_0c09d020;
case 0x0c09d022u: goto P_0c09d022;
case 0x0c09d024u: goto P_0c09d024;
case 0x0c09d026u: goto P_0c09d026;
case 0x0c09d028u: goto P_0c09d028;
case 0x0c09d02au: goto P_0c09d02a;
case 0x0c09d02cu: goto P_0c09d02c;
case 0x0c09d02eu: goto P_0c09d02e;
case 0x0c09d030u: goto P_0c09d030;
case 0x0c09d032u: goto P_0c09d032;
case 0x0c09d034u: goto P_0c09d034;
case 0x0c09d036u: goto P_0c09d036;
case 0x0c09d038u: goto P_0c09d038;
case 0x0c09d03au: goto P_0c09d03a;
case 0x0c09d03cu: goto P_0c09d03c;
case 0x0c09d03eu: goto P_0c09d03e;
case 0x0c09d040u: goto P_0c09d040;
case 0x0c09d042u: goto P_0c09d042;
case 0x0c09d044u: goto P_0c09d044;
case 0x0c09d046u: goto P_0c09d046;
case 0x0c09d048u: goto P_0c09d048;
case 0x0c09d04au: goto P_0c09d04a;
case 0x0c09d04cu: goto P_0c09d04c;
case 0x0c09d04eu: goto P_0c09d04e;
case 0x0c09d050u: goto P_0c09d050;
case 0x0c09d052u: goto P_0c09d052;
case 0x0c09d054u: goto P_0c09d054;
case 0x0c09d056u: goto P_0c09d056;
case 0x0c09d058u: goto P_0c09d058;
case 0x0c09d05au: goto P_0c09d05a;
case 0x0c09d05cu: goto P_0c09d05c;
case 0x0c09d05eu: goto P_0c09d05e;
case 0x0c09d060u: goto P_0c09d060;
case 0x0c09d062u: goto P_0c09d062;
case 0x0c09d064u: goto P_0c09d064;
case 0x0c09d066u: goto P_0c09d066;
case 0x0c09d068u: goto P_0c09d068;
case 0x0c09d06au: goto P_0c09d06a;
case 0x0c09d06cu: goto P_0c09d06c;
case 0x0c09d06eu: goto P_0c09d06e;
case 0x0c09d070u: goto P_0c09d070;
case 0x0c09d072u: goto P_0c09d072;
case 0x0c09d074u: goto P_0c09d074;
case 0x0c09d076u: goto P_0c09d076;
case 0x0c09d078u: goto P_0c09d078;
case 0x0c09d07au: goto P_0c09d07a;
case 0x0c09d07cu: goto P_0c09d07c;
default: return vf3_matrix_family(target,s,ram);
}
P_0c09af6c: /* original 2fe6, guest PC 0x0c09af6c */
if(!s->budget--) { s->failed_pc=0x0c09af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af6e;
P_0c09af6e: /* original 2fd6, guest PC 0x0c09af6e */
if(!s->budget--) { s->failed_pc=0x0c09af6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af70;
P_0c09af70: /* original 2fc6, guest PC 0x0c09af70 */
if(!s->budget--) { s->failed_pc=0x0c09af70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af72;
P_0c09af72: /* original 4f22, guest PC 0x0c09af72 */
if(!s->budget--) { s->failed_pc=0x0c09af72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09af74;
P_0c09af74: /* original d32c, guest PC 0x0c09af74 */
if(!s->budget--) { s->failed_pc=0x0c09af74u; return 0; }
r[3]=read(ram,0x0c09b028u,4);
goto P_0c09af76;
P_0c09af76: /* original 7ffc, guest PC 0x0c09af76 */
if(!s->budget--) { s->failed_pc=0x0c09af76u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09af78;
P_0c09af78: /* original 2f32, guest PC 0x0c09af78 */
if(!s->budget--) { s->failed_pc=0x0c09af78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09af7a;
P_0c09af7a: /* original dc2c, guest PC 0x0c09af7a */
if(!s->budget--) { s->failed_pc=0x0c09af7au; return 0; }
r[12]=read(ram,0x0c09b02cu,4);
goto P_0c09af7c;
P_0c09af7c: /* original dd2c, guest PC 0x0c09af7c */
if(!s->budget--) { s->failed_pc=0x0c09af7cu; return 0; }
r[13]=read(ram,0x0c09b030u,4);
goto P_0c09af7e;
P_0c09af7e: /* original 4d0b, guest PC 0x0c09af7e */
if(!s->budget--) { s->failed_pc=0x0c09af7eu; return 0; }
target=r[13];
r[16]=code_base|0x0c09af82u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af82u) { target=s->pc; goto dispatch; }
goto P_0c09af82;
P_0c09af80: /* original e400, guest PC 0x0c09af80 */
if(!s->budget--) { s->failed_pc=0x0c09af80u; return 0; }
r[4]=0x00000000u;
goto P_0c09af82;
P_0c09af82: /* original 6403, guest PC 0x0c09af82 */
if(!s->budget--) { s->failed_pc=0x0c09af82u; return 0; }
r[4]=r[0];
goto P_0c09af84;
P_0c09af84: /* original 5e42, guest PC 0x0c09af84 */
if(!s->budget--) { s->failed_pc=0x0c09af84u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09af86;
P_0c09af86: /* original 53c2, guest PC 0x0c09af86 */
if(!s->budget--) { s->failed_pc=0x0c09af86u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09af88;
P_0c09af88: /* original d42a, guest PC 0x0c09af88 */
if(!s->budget--) { s->failed_pc=0x0c09af88u; return 0; }
r[4]=read(ram,0x0c09b034u,4);
goto P_0c09af8a;
P_0c09af8a: /* original 2349, guest PC 0x0c09af8a */
if(!s->budget--) { s->failed_pc=0x0c09af8au; return 0; }
r[3]&=r[4];
goto P_0c09af8c;
P_0c09af8c: /* original 3340, guest PC 0x0c09af8c */
if(!s->budget--) { s->failed_pc=0x0c09af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c09af8e;
P_0c09af8e: /* original 8b05, guest PC 0x0c09af8e */
if(!s->budget--) { s->failed_pc=0x0c09af8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09af9c; }
goto P_0c09af90;
P_0c09af90: /* original 4d0b, guest PC 0x0c09af90 */
if(!s->budget--) { s->failed_pc=0x0c09af90u; return 0; }
target=r[13];
r[16]=code_base|0x0c09af94u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af94u) { target=s->pc; goto dispatch; }
goto P_0c09af94;
P_0c09af92: /* original e401, guest PC 0x0c09af92 */
if(!s->budget--) { s->failed_pc=0x0c09af92u; return 0; }
r[4]=0x00000001u;
goto P_0c09af94;
P_0c09af94: /* original 6403, guest PC 0x0c09af94 */
if(!s->budget--) { s->failed_pc=0x0c09af94u; return 0; }
r[4]=r[0];
goto P_0c09af96;
P_0c09af96: /* original 5342, guest PC 0x0c09af96 */
if(!s->budget--) { s->failed_pc=0x0c09af96u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09af98;
P_0c09af98: /* original a008, guest PC 0x0c09af98 */
if(!s->budget--) { s->failed_pc=0x0c09af98u; return 0; }
r[14]|=r[3];
goto P_0c09afac;
P_0c09af9a: /* original 2e3b, guest PC 0x0c09af9a */
if(!s->budget--) { s->failed_pc=0x0c09af9au; return 0; }
r[14]|=r[3];
goto P_0c09af9c;
P_0c09af9c: /* original 52c2, guest PC 0x0c09af9c */
if(!s->budget--) { s->failed_pc=0x0c09af9cu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09af9e;
P_0c09af9e: /* original d326, guest PC 0x0c09af9e */
if(!s->budget--) { s->failed_pc=0x0c09af9eu; return 0; }
r[3]=read(ram,0x0c09b038u,4);
goto P_0c09afa0;
P_0c09afa0: /* original 2238, guest PC 0x0c09afa0 */
if(!s->budget--) { s->failed_pc=0x0c09afa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09afa2;
P_0c09afa2: /* original 8903, guest PC 0x0c09afa2 */
if(!s->budget--) { s->failed_pc=0x0c09afa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09afac; }
goto P_0c09afa4;
P_0c09afa4: /* original 4d0b, guest PC 0x0c09afa4 */
if(!s->budget--) { s->failed_pc=0x0c09afa4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09afa8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09afa8u) { target=s->pc; goto dispatch; }
goto P_0c09afa8;
P_0c09afa6: /* original e401, guest PC 0x0c09afa6 */
if(!s->budget--) { s->failed_pc=0x0c09afa6u; return 0; }
r[4]=0x00000001u;
goto P_0c09afa8;
P_0c09afa8: /* original 6403, guest PC 0x0c09afa8 */
if(!s->budget--) { s->failed_pc=0x0c09afa8u; return 0; }
r[4]=r[0];
goto P_0c09afaa;
P_0c09afaa: /* original 5e42, guest PC 0x0c09afaa */
if(!s->budget--) { s->failed_pc=0x0c09afaau; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09afac;
P_0c09afac: /* original 63f2, guest PC 0x0c09afac */
if(!s->budget--) { s->failed_pc=0x0c09afacu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09afae;
P_0c09afae: /* original 7f04, guest PC 0x0c09afae */
if(!s->budget--) { s->failed_pc=0x0c09afaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c09afb0;
P_0c09afb0: /* original 4f26, guest PC 0x0c09afb0 */
if(!s->budget--) { s->failed_pc=0x0c09afb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09afb2;
P_0c09afb2: /* original 9038, guest PC 0x0c09afb2 */
if(!s->budget--) { s->failed_pc=0x0c09afb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b026u,2);
goto P_0c09afb4;
P_0c09afb4: /* original 03e6, guest PC 0x0c09afb4 */
if(!s->budget--) { s->failed_pc=0x0c09afb4u; return 0; }
write(ram,r[3]+r[0],r[14],4);
goto P_0c09afb6;
P_0c09afb6: /* original 60e3, guest PC 0x0c09afb6 */
if(!s->budget--) { s->failed_pc=0x0c09afb6u; return 0; }
r[0]=r[14];
goto P_0c09afb8;
P_0c09afb8: /* original 6cf6, guest PC 0x0c09afb8 */
if(!s->budget--) { s->failed_pc=0x0c09afb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09afba;
P_0c09afba: /* original 6df6, guest PC 0x0c09afba */
if(!s->budget--) { s->failed_pc=0x0c09afbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09afbc;
P_0c09afbc: /* original 000b, guest PC 0x0c09afbc */
if(!s->budget--) { s->failed_pc=0x0c09afbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09afbe: /* original 6ef6, guest PC 0x0c09afbe */
if(!s->budget--) { s->failed_pc=0x0c09afbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09afc0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09afc0u; return 0; } return 1;
P_0c09ce8c: /* original 2fe6, guest PC 0x0c09ce8c */
if(!s->budget--) { s->failed_pc=0x0c09ce8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce8e;
P_0c09ce8e: /* original 2fd6, guest PC 0x0c09ce8e */
if(!s->budget--) { s->failed_pc=0x0c09ce8eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce90;
P_0c09ce90: /* original 2fc6, guest PC 0x0c09ce90 */
if(!s->budget--) { s->failed_pc=0x0c09ce90u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce92;
P_0c09ce92: /* original 2fb6, guest PC 0x0c09ce92 */
if(!s->budget--) { s->failed_pc=0x0c09ce92u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce94;
P_0c09ce94: /* original 2fa6, guest PC 0x0c09ce94 */
if(!s->budget--) { s->failed_pc=0x0c09ce94u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09ce96;
P_0c09ce96: /* original 4f22, guest PC 0x0c09ce96 */
if(!s->budget--) { s->failed_pc=0x0c09ce96u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09ce98;
P_0c09ce98: /* original d342, guest PC 0x0c09ce98 */
if(!s->budget--) { s->failed_pc=0x0c09ce98u; return 0; }
r[3]=read(ram,0x0c09cfa4u,4);
goto P_0c09ce9a;
P_0c09ce9a: /* original de41, guest PC 0x0c09ce9a */
if(!s->budget--) { s->failed_pc=0x0c09ce9au; return 0; }
r[14]=read(ram,0x0c09cfa0u,4);
goto P_0c09ce9c;
P_0c09ce9c: /* original 430b, guest PC 0x0c09ce9c */
if(!s->budget--) { s->failed_pc=0x0c09ce9cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09cea0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cea0u) { target=s->pc; goto dispatch; }
goto P_0c09cea0;
P_0c09ce9e: /* original 0009, guest PC 0x0c09ce9e */
if(!s->budget--) { s->failed_pc=0x0c09ce9eu; return 0; }
goto P_0c09cea0;
P_0c09cea0: /* original 6d03, guest PC 0x0c09cea0 */
if(!s->budget--) { s->failed_pc=0x0c09cea0u; return 0; }
r[13]=r[0];
goto P_0c09cea2;
P_0c09cea2: /* original e07d, guest PC 0x0c09cea2 */
if(!s->budget--) { s->failed_pc=0x0c09cea2u; return 0; }
r[0]=0x0000007du;
goto P_0c09cea4;
P_0c09cea4: /* original e310, guest PC 0x0c09cea4 */
if(!s->budget--) { s->failed_pc=0x0c09cea4u; return 0; }
r[3]=0x00000010u;
goto P_0c09cea6;
P_0c09cea6: /* original eb00, guest PC 0x0c09cea6 */
if(!s->budget--) { s->failed_pc=0x0c09cea6u; return 0; }
r[11]=0x00000000u;
goto P_0c09cea8;
P_0c09cea8: /* original e240, guest PC 0x0c09cea8 */
if(!s->budget--) { s->failed_pc=0x0c09cea8u; return 0; }
r[2]=0x00000040u;
goto P_0c09ceaa;
P_0c09ceaa: /* original 23d8, guest PC 0x0c09ceaa */
if(!s->budget--) { s->failed_pc=0x0c09ceaau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ceac;
P_0c09ceac: /* original 1e23, guest PC 0x0c09ceac */
if(!s->budget--) { s->failed_pc=0x0c09ceacu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09ceae;
P_0c09ceae: /* original 1eb6, guest PC 0x0c09ceae */
if(!s->budget--) { s->failed_pc=0x0c09ceaeu; return 0; }
write(ram,r[14]+24,r[11],4);
goto P_0c09ceb0;
P_0c09ceb0: /* original 0eb4, guest PC 0x0c09ceb0 */
if(!s->budget--) { s->failed_pc=0x0c09ceb0u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09ceb2;
P_0c09ceb2: /* original 9a6e, guest PC 0x0c09ceb2 */
if(!s->budget--) { s->failed_pc=0x0c09ceb2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf92u,2);
goto P_0c09ceb4;
P_0c09ceb4: /* original dc3c, guest PC 0x0c09ceb4 */
if(!s->budget--) { s->failed_pc=0x0c09ceb4u; return 0; }
r[12]=read(ram,0x0c09cfa8u,4);
goto P_0c09ceb6;
P_0c09ceb6: /* original 8d0b, guest PC 0x0c09ceb6 */
if(!s->budget--) { s->failed_pc=0x0c09ceb6u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[11],4);
if(cond) { goto P_0c09ced0; }
goto P_0c09ceba;
P_0c09ceb8: /* original 1eb5, guest PC 0x0c09ceb8 */
if(!s->budget--) { s->failed_pc=0x0c09ceb8u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c09ceba;
P_0c09ceba: /* original 4c0b, guest PC 0x0c09ceba */
if(!s->budget--) { s->failed_pc=0x0c09cebau; return 0; }
target=r[12];
r[16]=code_base|0x0c09cebeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cebeu) { target=s->pc; goto dispatch; }
goto P_0c09cebe;
P_0c09cebc: /* original 64a3, guest PC 0x0c09cebc */
if(!s->budget--) { s->failed_pc=0x0c09cebcu; return 0; }
r[4]=r[10];
goto P_0c09cebe;
P_0c09cebe: /* original 9069, guest PC 0x0c09cebe */
if(!s->budget--) { s->failed_pc=0x0c09cebeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf94u,2);
goto P_0c09cec0;
P_0c09cec0: /* original 03ee, guest PC 0x0c09cec0 */
if(!s->budget--) { s->failed_pc=0x0c09cec0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cec2;
P_0c09cec2: /* original 73ff, guest PC 0x0c09cec2 */
if(!s->budget--) { s->failed_pc=0x0c09cec2u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cec4;
P_0c09cec4: /* original 0e36, guest PC 0x0c09cec4 */
if(!s->budget--) { s->failed_pc=0x0c09cec4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cec6;
P_0c09cec6: /* original 02ee, guest PC 0x0c09cec6 */
if(!s->budget--) { s->failed_pc=0x0c09cec6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cec8;
P_0c09cec8: /* original 4211, guest PC 0x0c09cec8 */
if(!s->budget--) { s->failed_pc=0x0c09cec8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09ceca;
P_0c09ceca: /* original 8901, guest PC 0x0c09ceca */
if(!s->budget--) { s->failed_pc=0x0c09cecau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ced0; }
goto P_0c09cecc;
P_0c09cecc: /* original e103, guest PC 0x0c09cecc */
if(!s->budget--) { s->failed_pc=0x0c09ceccu; return 0; }
r[1]=0x00000003u;
goto P_0c09cece;
P_0c09cece: /* original 0e16, guest PC 0x0c09cece */
if(!s->budget--) { s->failed_pc=0x0c09ceceu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09ced0;
P_0c09ced0: /* original e320, guest PC 0x0c09ced0 */
if(!s->budget--) { s->failed_pc=0x0c09ced0u; return 0; }
r[3]=0x00000020u;
goto P_0c09ced2;
P_0c09ced2: /* original 23d8, guest PC 0x0c09ced2 */
if(!s->budget--) { s->failed_pc=0x0c09ced2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09ced4;
P_0c09ced4: /* original 890a, guest PC 0x0c09ced4 */
if(!s->budget--) { s->failed_pc=0x0c09ced4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09ceec; }
goto P_0c09ced6;
P_0c09ced6: /* original 4c0b, guest PC 0x0c09ced6 */
if(!s->budget--) { s->failed_pc=0x0c09ced6u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cedau;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cedau) { target=s->pc; goto dispatch; }
goto P_0c09ceda;
P_0c09ced8: /* original 64a3, guest PC 0x0c09ced8 */
if(!s->budget--) { s->failed_pc=0x0c09ced8u; return 0; }
r[4]=r[10];
goto P_0c09ceda;
P_0c09ceda: /* original 905b, guest PC 0x0c09ceda */
if(!s->budget--) { s->failed_pc=0x0c09cedau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf94u,2);
goto P_0c09cedc;
P_0c09cedc: /* original e203, guest PC 0x0c09cedc */
if(!s->budget--) { s->failed_pc=0x0c09cedcu; return 0; }
r[2]=0x00000003u;
goto P_0c09cede;
P_0c09cede: /* original 03ee, guest PC 0x0c09cede */
if(!s->budget--) { s->failed_pc=0x0c09cedeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cee0;
P_0c09cee0: /* original 7301, guest PC 0x0c09cee0 */
if(!s->budget--) { s->failed_pc=0x0c09cee0u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cee2;
P_0c09cee2: /* original 0e36, guest PC 0x0c09cee2 */
if(!s->budget--) { s->failed_pc=0x0c09cee2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cee4;
P_0c09cee4: /* original 01ee, guest PC 0x0c09cee4 */
if(!s->budget--) { s->failed_pc=0x0c09cee4u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09cee6;
P_0c09cee6: /* original 3123, guest PC 0x0c09cee6 */
if(!s->budget--) { s->failed_pc=0x0c09cee6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09cee8;
P_0c09cee8: /* original 8b00, guest PC 0x0c09cee8 */
if(!s->budget--) { s->failed_pc=0x0c09cee8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09ceec; }
goto P_0c09ceea;
P_0c09ceea: /* original 0eb6, guest PC 0x0c09ceea */
if(!s->budget--) { s->failed_pc=0x0c09ceeau; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09ceec;
P_0c09ceec: /* original e340, guest PC 0x0c09ceec */
if(!s->budget--) { s->failed_pc=0x0c09ceecu; return 0; }
r[3]=0x00000040u;
goto P_0c09ceee;
P_0c09ceee: /* original 23d8, guest PC 0x0c09ceee */
if(!s->budget--) { s->failed_pc=0x0c09ceeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cef0;
P_0c09cef0: /* original 8909, guest PC 0x0c09cef0 */
if(!s->budget--) { s->failed_pc=0x0c09cef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf06; }
goto P_0c09cef2;
P_0c09cef2: /* original 4c0b, guest PC 0x0c09cef2 */
if(!s->budget--) { s->failed_pc=0x0c09cef2u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cef6u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cef6u) { target=s->pc; goto dispatch; }
goto P_0c09cef6;
P_0c09cef4: /* original 64a3, guest PC 0x0c09cef4 */
if(!s->budget--) { s->failed_pc=0x0c09cef4u; return 0; }
r[4]=r[10];
goto P_0c09cef6;
P_0c09cef6: /* original 904e, guest PC 0x0c09cef6 */
if(!s->budget--) { s->failed_pc=0x0c09cef6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf96u,2);
goto P_0c09cef8;
P_0c09cef8: /* original 03ee, guest PC 0x0c09cef8 */
if(!s->budget--) { s->failed_pc=0x0c09cef8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cefa;
P_0c09cefa: /* original 73ff, guest PC 0x0c09cefa */
if(!s->budget--) { s->failed_pc=0x0c09cefau; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cefc;
P_0c09cefc: /* original 0e36, guest PC 0x0c09cefc */
if(!s->budget--) { s->failed_pc=0x0c09cefcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cefe;
P_0c09cefe: /* original 02ee, guest PC 0x0c09cefe */
if(!s->budget--) { s->failed_pc=0x0c09cefeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cf00;
P_0c09cf00: /* original 4211, guest PC 0x0c09cf00 */
if(!s->budget--) { s->failed_pc=0x0c09cf00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cf02;
P_0c09cf02: /* original 8900, guest PC 0x0c09cf02 */
if(!s->budget--) { s->failed_pc=0x0c09cf02u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf06; }
goto P_0c09cf04;
P_0c09cf04: /* original 0eb6, guest PC 0x0c09cf04 */
if(!s->budget--) { s->failed_pc=0x0c09cf04u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09cf06;
P_0c09cf06: /* original 9347, guest PC 0x0c09cf06 */
if(!s->budget--) { s->failed_pc=0x0c09cf06u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf98u,2);
goto P_0c09cf08;
P_0c09cf08: /* original 23d8, guest PC 0x0c09cf08 */
if(!s->budget--) { s->failed_pc=0x0c09cf08u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cf0a;
P_0c09cf0a: /* original 890a, guest PC 0x0c09cf0a */
if(!s->budget--) { s->failed_pc=0x0c09cf0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf22; }
goto P_0c09cf0c;
P_0c09cf0c: /* original 4c0b, guest PC 0x0c09cf0c */
if(!s->budget--) { s->failed_pc=0x0c09cf0cu; return 0; }
target=r[12];
r[16]=code_base|0x0c09cf10u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cf10u) { target=s->pc; goto dispatch; }
goto P_0c09cf10;
P_0c09cf0e: /* original 64a3, guest PC 0x0c09cf0e */
if(!s->budget--) { s->failed_pc=0x0c09cf0eu; return 0; }
r[4]=r[10];
goto P_0c09cf10;
P_0c09cf10: /* original 9041, guest PC 0x0c09cf10 */
if(!s->budget--) { s->failed_pc=0x0c09cf10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf96u,2);
goto P_0c09cf12;
P_0c09cf12: /* original e401, guest PC 0x0c09cf12 */
if(!s->budget--) { s->failed_pc=0x0c09cf12u; return 0; }
r[4]=0x00000001u;
goto P_0c09cf14;
P_0c09cf14: /* original 03ee, guest PC 0x0c09cf14 */
if(!s->budget--) { s->failed_pc=0x0c09cf14u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cf16;
P_0c09cf16: /* original 7301, guest PC 0x0c09cf16 */
if(!s->budget--) { s->failed_pc=0x0c09cf16u; return 0; }
r[3]+=0x00000001u;
goto P_0c09cf18;
P_0c09cf18: /* original 0e36, guest PC 0x0c09cf18 */
if(!s->budget--) { s->failed_pc=0x0c09cf18u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cf1a;
P_0c09cf1a: /* original 02ee, guest PC 0x0c09cf1a */
if(!s->budget--) { s->failed_pc=0x0c09cf1au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cf1c;
P_0c09cf1c: /* original 3243, guest PC 0x0c09cf1c */
if(!s->budget--) { s->failed_pc=0x0c09cf1cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c09cf1e;
P_0c09cf1e: /* original 8b00, guest PC 0x0c09cf1e */
if(!s->budget--) { s->failed_pc=0x0c09cf1eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09cf22; }
goto P_0c09cf20;
P_0c09cf20: /* original 0e46, guest PC 0x0c09cf20 */
if(!s->budget--) { s->failed_pc=0x0c09cf20u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09cf22;
P_0c09cf22: /* original e304, guest PC 0x0c09cf22 */
if(!s->budget--) { s->failed_pc=0x0c09cf22u; return 0; }
r[3]=0x00000004u;
goto P_0c09cf24;
P_0c09cf24: /* original 23d8, guest PC 0x0c09cf24 */
if(!s->budget--) { s->failed_pc=0x0c09cf24u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cf26;
P_0c09cf26: /* original 8902, guest PC 0x0c09cf26 */
if(!s->budget--) { s->failed_pc=0x0c09cf26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf2e; }
goto P_0c09cf28;
P_0c09cf28: /* original 9437, guest PC 0x0c09cf28 */
if(!s->budget--) { s->failed_pc=0x0c09cf28u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9au,2);
goto P_0c09cf2a;
P_0c09cf2a: /* original 4c0b, guest PC 0x0c09cf2a */
if(!s->budget--) { s->failed_pc=0x0c09cf2au; return 0; }
target=r[12];
r[16]=code_base|0x0c09cf2eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cf2eu) { target=s->pc; goto dispatch; }
goto P_0c09cf2e;
P_0c09cf2c: /* original 0009, guest PC 0x0c09cf2c */
if(!s->budget--) { s->failed_pc=0x0c09cf2cu; return 0; }
goto P_0c09cf2e;
P_0c09cf2e: /* original e30a, guest PC 0x0c09cf2e */
if(!s->budget--) { s->failed_pc=0x0c09cf2eu; return 0; }
r[3]=0x0000000au;
goto P_0c09cf30;
P_0c09cf30: /* original 23d8, guest PC 0x0c09cf30 */
if(!s->budget--) { s->failed_pc=0x0c09cf30u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cf32;
P_0c09cf32: /* original 890d, guest PC 0x0c09cf32 */
if(!s->budget--) { s->failed_pc=0x0c09cf32u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf50; }
goto P_0c09cf34;
P_0c09cf34: /* original e108, guest PC 0x0c09cf34 */
if(!s->budget--) { s->failed_pc=0x0c09cf34u; return 0; }
r[1]=0x00000008u;
goto P_0c09cf36;
P_0c09cf36: /* original 2d18, guest PC 0x0c09cf36 */
if(!s->budget--) { s->failed_pc=0x0c09cf36u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[1])==0)!=0);
goto P_0c09cf38;
P_0c09cf38: /* original 8902, guest PC 0x0c09cf38 */
if(!s->budget--) { s->failed_pc=0x0c09cf38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cf40; }
goto P_0c09cf3a;
P_0c09cf3a: /* original 942e, guest PC 0x0c09cf3a */
if(!s->budget--) { s->failed_pc=0x0c09cf3au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9au,2);
goto P_0c09cf3c;
P_0c09cf3c: /* original a001, guest PC 0x0c09cf3c */
if(!s->budget--) { s->failed_pc=0x0c09cf3cu; return 0; }
goto P_0c09cf42;
P_0c09cf3e: /* original 0009, guest PC 0x0c09cf3e */
if(!s->budget--) { s->failed_pc=0x0c09cf3eu; return 0; }
goto P_0c09cf40;
P_0c09cf40: /* original 942c, guest PC 0x0c09cf40 */
if(!s->budget--) { s->failed_pc=0x0c09cf40u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09cf9cu,2);
goto P_0c09cf42;
P_0c09cf42: /* original 4c0b, guest PC 0x0c09cf42 */
if(!s->budget--) { s->failed_pc=0x0c09cf42u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cf46u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cf46u) { target=s->pc; goto dispatch; }
goto P_0c09cf46;
P_0c09cf44: /* original 0009, guest PC 0x0c09cf44 */
if(!s->budget--) { s->failed_pc=0x0c09cf44u; return 0; }
goto P_0c09cf46;
P_0c09cf46: /* original e005, guest PC 0x0c09cf46 */
if(!s->budget--) { s->failed_pc=0x0c09cf46u; return 0; }
r[0]=0x00000005u;
goto P_0c09cf48;
P_0c09cf48: /* original 80eb, guest PC 0x0c09cf48 */
if(!s->budget--) { s->failed_pc=0x0c09cf48u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09cf4a;
P_0c09cf4a: /* original e010, guest PC 0x0c09cf4a */
if(!s->budget--) { s->failed_pc=0x0c09cf4au; return 0; }
r[0]=0x00000010u;
goto P_0c09cf4c;
P_0c09cf4c: /* original e374, guest PC 0x0c09cf4c */
if(!s->budget--) { s->failed_pc=0x0c09cf4cu; return 0; }
r[3]=0x00000074u;
goto P_0c09cf4e;
P_0c09cf4e: /* original 0e34, guest PC 0x0c09cf4e */
if(!s->budget--) { s->failed_pc=0x0c09cf4eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09cf50;
P_0c09cf50: /* original 4f26, guest PC 0x0c09cf50 */
if(!s->budget--) { s->failed_pc=0x0c09cf50u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09cf52;
P_0c09cf52: /* original 6af6, guest PC 0x0c09cf52 */
if(!s->budget--) { s->failed_pc=0x0c09cf52u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09cf54;
P_0c09cf54: /* original 6bf6, guest PC 0x0c09cf54 */
if(!s->budget--) { s->failed_pc=0x0c09cf54u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09cf56;
P_0c09cf56: /* original 6cf6, guest PC 0x0c09cf56 */
if(!s->budget--) { s->failed_pc=0x0c09cf56u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09cf58;
P_0c09cf58: /* original 6df6, guest PC 0x0c09cf58 */
if(!s->budget--) { s->failed_pc=0x0c09cf58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09cf5a;
P_0c09cf5a: /* original 000b, guest PC 0x0c09cf5a */
if(!s->budget--) { s->failed_pc=0x0c09cf5au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09cf5c: /* original 6ef6, guest PC 0x0c09cf5c */
if(!s->budget--) { s->failed_pc=0x0c09cf5cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09cf5eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09cf5eu; return 0; } return 1;
P_0c09cfac: /* original 2fe6, guest PC 0x0c09cfac */
if(!s->budget--) { s->failed_pc=0x0c09cfacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfae;
P_0c09cfae: /* original 2fd6, guest PC 0x0c09cfae */
if(!s->budget--) { s->failed_pc=0x0c09cfaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb0;
P_0c09cfb0: /* original 2fc6, guest PC 0x0c09cfb0 */
if(!s->budget--) { s->failed_pc=0x0c09cfb0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb2;
P_0c09cfb2: /* original 2fb6, guest PC 0x0c09cfb2 */
if(!s->budget--) { s->failed_pc=0x0c09cfb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb4;
P_0c09cfb4: /* original 2fa6, guest PC 0x0c09cfb4 */
if(!s->budget--) { s->failed_pc=0x0c09cfb4u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09cfb6;
P_0c09cfb6: /* original 4f22, guest PC 0x0c09cfb6 */
if(!s->budget--) { s->failed_pc=0x0c09cfb6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09cfb8;
P_0c09cfb8: /* original d335, guest PC 0x0c09cfb8 */
if(!s->budget--) { s->failed_pc=0x0c09cfb8u; return 0; }
r[3]=read(ram,0x0c09d090u,4);
goto P_0c09cfba;
P_0c09cfba: /* original de34, guest PC 0x0c09cfba */
if(!s->budget--) { s->failed_pc=0x0c09cfbau; return 0; }
r[14]=read(ram,0x0c09d08cu,4);
goto P_0c09cfbc;
P_0c09cfbc: /* original 430b, guest PC 0x0c09cfbc */
if(!s->budget--) { s->failed_pc=0x0c09cfbcu; return 0; }
target=r[3];
r[16]=code_base|0x0c09cfc0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cfc0u) { target=s->pc; goto dispatch; }
goto P_0c09cfc0;
P_0c09cfbe: /* original 0009, guest PC 0x0c09cfbe */
if(!s->budget--) { s->failed_pc=0x0c09cfbeu; return 0; }
goto P_0c09cfc0;
P_0c09cfc0: /* original 6d03, guest PC 0x0c09cfc0 */
if(!s->budget--) { s->failed_pc=0x0c09cfc0u; return 0; }
r[13]=r[0];
goto P_0c09cfc2;
P_0c09cfc2: /* original e07d, guest PC 0x0c09cfc2 */
if(!s->budget--) { s->failed_pc=0x0c09cfc2u; return 0; }
r[0]=0x0000007du;
goto P_0c09cfc4;
P_0c09cfc4: /* original e310, guest PC 0x0c09cfc4 */
if(!s->budget--) { s->failed_pc=0x0c09cfc4u; return 0; }
r[3]=0x00000010u;
goto P_0c09cfc6;
P_0c09cfc6: /* original eb00, guest PC 0x0c09cfc6 */
if(!s->budget--) { s->failed_pc=0x0c09cfc6u; return 0; }
r[11]=0x00000000u;
goto P_0c09cfc8;
P_0c09cfc8: /* original e240, guest PC 0x0c09cfc8 */
if(!s->budget--) { s->failed_pc=0x0c09cfc8u; return 0; }
r[2]=0x00000040u;
goto P_0c09cfca;
P_0c09cfca: /* original 23d8, guest PC 0x0c09cfca */
if(!s->budget--) { s->failed_pc=0x0c09cfcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cfcc;
P_0c09cfcc: /* original 1e23, guest PC 0x0c09cfcc */
if(!s->budget--) { s->failed_pc=0x0c09cfccu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c09cfce;
P_0c09cfce: /* original 1eb6, guest PC 0x0c09cfce */
if(!s->budget--) { s->failed_pc=0x0c09cfceu; return 0; }
write(ram,r[14]+24,r[11],4);
goto P_0c09cfd0;
P_0c09cfd0: /* original 0eb4, guest PC 0x0c09cfd0 */
if(!s->budget--) { s->failed_pc=0x0c09cfd0u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09cfd2;
P_0c09cfd2: /* original 9a54, guest PC 0x0c09cfd2 */
if(!s->budget--) { s->failed_pc=0x0c09cfd2u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d07eu,2);
goto P_0c09cfd4;
P_0c09cfd4: /* original dc2f, guest PC 0x0c09cfd4 */
if(!s->budget--) { s->failed_pc=0x0c09cfd4u; return 0; }
r[12]=read(ram,0x0c09d094u,4);
goto P_0c09cfd6;
P_0c09cfd6: /* original 8d0b, guest PC 0x0c09cfd6 */
if(!s->budget--) { s->failed_pc=0x0c09cfd6u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+20,r[11],4);
if(cond) { goto P_0c09cff0; }
goto P_0c09cfda;
P_0c09cfd8: /* original 1eb5, guest PC 0x0c09cfd8 */
if(!s->budget--) { s->failed_pc=0x0c09cfd8u; return 0; }
write(ram,r[14]+20,r[11],4);
goto P_0c09cfda;
P_0c09cfda: /* original 4c0b, guest PC 0x0c09cfda */
if(!s->budget--) { s->failed_pc=0x0c09cfdau; return 0; }
target=r[12];
r[16]=code_base|0x0c09cfdeu;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cfdeu) { target=s->pc; goto dispatch; }
goto P_0c09cfde;
P_0c09cfdc: /* original 64a3, guest PC 0x0c09cfdc */
if(!s->budget--) { s->failed_pc=0x0c09cfdcu; return 0; }
r[4]=r[10];
goto P_0c09cfde;
P_0c09cfde: /* original 904f, guest PC 0x0c09cfde */
if(!s->budget--) { s->failed_pc=0x0c09cfdeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d080u,2);
goto P_0c09cfe0;
P_0c09cfe0: /* original 03ee, guest PC 0x0c09cfe0 */
if(!s->budget--) { s->failed_pc=0x0c09cfe0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09cfe2;
P_0c09cfe2: /* original 73ff, guest PC 0x0c09cfe2 */
if(!s->budget--) { s->failed_pc=0x0c09cfe2u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09cfe4;
P_0c09cfe4: /* original 0e36, guest PC 0x0c09cfe4 */
if(!s->budget--) { s->failed_pc=0x0c09cfe4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09cfe6;
P_0c09cfe6: /* original 02ee, guest PC 0x0c09cfe6 */
if(!s->budget--) { s->failed_pc=0x0c09cfe6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09cfe8;
P_0c09cfe8: /* original 4211, guest PC 0x0c09cfe8 */
if(!s->budget--) { s->failed_pc=0x0c09cfe8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09cfea;
P_0c09cfea: /* original 8901, guest PC 0x0c09cfea */
if(!s->budget--) { s->failed_pc=0x0c09cfeau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09cff0; }
goto P_0c09cfec;
P_0c09cfec: /* original e103, guest PC 0x0c09cfec */
if(!s->budget--) { s->failed_pc=0x0c09cfecu; return 0; }
r[1]=0x00000003u;
goto P_0c09cfee;
P_0c09cfee: /* original 0e16, guest PC 0x0c09cfee */
if(!s->budget--) { s->failed_pc=0x0c09cfeeu; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09cff0;
P_0c09cff0: /* original e320, guest PC 0x0c09cff0 */
if(!s->budget--) { s->failed_pc=0x0c09cff0u; return 0; }
r[3]=0x00000020u;
goto P_0c09cff2;
P_0c09cff2: /* original 23d8, guest PC 0x0c09cff2 */
if(!s->budget--) { s->failed_pc=0x0c09cff2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09cff4;
P_0c09cff4: /* original 890a, guest PC 0x0c09cff4 */
if(!s->budget--) { s->failed_pc=0x0c09cff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d00c; }
goto P_0c09cff6;
P_0c09cff6: /* original 4c0b, guest PC 0x0c09cff6 */
if(!s->budget--) { s->failed_pc=0x0c09cff6u; return 0; }
target=r[12];
r[16]=code_base|0x0c09cffau;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09cffau) { target=s->pc; goto dispatch; }
goto P_0c09cffa;
P_0c09cff8: /* original 64a3, guest PC 0x0c09cff8 */
if(!s->budget--) { s->failed_pc=0x0c09cff8u; return 0; }
r[4]=r[10];
goto P_0c09cffa;
P_0c09cffa: /* original 9041, guest PC 0x0c09cffa */
if(!s->budget--) { s->failed_pc=0x0c09cffau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d080u,2);
goto P_0c09cffc;
P_0c09cffc: /* original e203, guest PC 0x0c09cffc */
if(!s->budget--) { s->failed_pc=0x0c09cffcu; return 0; }
r[2]=0x00000003u;
goto P_0c09cffe;
P_0c09cffe: /* original 03ee, guest PC 0x0c09cffe */
if(!s->budget--) { s->failed_pc=0x0c09cffeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d000;
P_0c09d000: /* original 7301, guest PC 0x0c09d000 */
if(!s->budget--) { s->failed_pc=0x0c09d000u; return 0; }
r[3]+=0x00000001u;
goto P_0c09d002;
P_0c09d002: /* original 0e36, guest PC 0x0c09d002 */
if(!s->budget--) { s->failed_pc=0x0c09d002u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d004;
P_0c09d004: /* original 01ee, guest PC 0x0c09d004 */
if(!s->budget--) { s->failed_pc=0x0c09d004u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09d006;
P_0c09d006: /* original 3123, guest PC 0x0c09d006 */
if(!s->budget--) { s->failed_pc=0x0c09d006u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c09d008;
P_0c09d008: /* original 8b00, guest PC 0x0c09d008 */
if(!s->budget--) { s->failed_pc=0x0c09d008u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d00c; }
goto P_0c09d00a;
P_0c09d00a: /* original 0eb6, guest PC 0x0c09d00a */
if(!s->budget--) { s->failed_pc=0x0c09d00au; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09d00c;
P_0c09d00c: /* original e340, guest PC 0x0c09d00c */
if(!s->budget--) { s->failed_pc=0x0c09d00cu; return 0; }
r[3]=0x00000040u;
goto P_0c09d00e;
P_0c09d00e: /* original 23d8, guest PC 0x0c09d00e */
if(!s->budget--) { s->failed_pc=0x0c09d00eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d010;
P_0c09d010: /* original 8909, guest PC 0x0c09d010 */
if(!s->budget--) { s->failed_pc=0x0c09d010u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d026; }
goto P_0c09d012;
P_0c09d012: /* original 4c0b, guest PC 0x0c09d012 */
if(!s->budget--) { s->failed_pc=0x0c09d012u; return 0; }
target=r[12];
r[16]=code_base|0x0c09d016u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d016u) { target=s->pc; goto dispatch; }
goto P_0c09d016;
P_0c09d014: /* original 64a3, guest PC 0x0c09d014 */
if(!s->budget--) { s->failed_pc=0x0c09d014u; return 0; }
r[4]=r[10];
goto P_0c09d016;
P_0c09d016: /* original 9034, guest PC 0x0c09d016 */
if(!s->budget--) { s->failed_pc=0x0c09d016u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d082u,2);
goto P_0c09d018;
P_0c09d018: /* original 03ee, guest PC 0x0c09d018 */
if(!s->budget--) { s->failed_pc=0x0c09d018u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d01a;
P_0c09d01a: /* original 73ff, guest PC 0x0c09d01a */
if(!s->budget--) { s->failed_pc=0x0c09d01au; return 0; }
r[3]+=0xffffffffu;
goto P_0c09d01c;
P_0c09d01c: /* original 0e36, guest PC 0x0c09d01c */
if(!s->budget--) { s->failed_pc=0x0c09d01cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d01e;
P_0c09d01e: /* original 02ee, guest PC 0x0c09d01e */
if(!s->budget--) { s->failed_pc=0x0c09d01eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09d020;
P_0c09d020: /* original 4211, guest PC 0x0c09d020 */
if(!s->budget--) { s->failed_pc=0x0c09d020u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09d022;
P_0c09d022: /* original 8900, guest PC 0x0c09d022 */
if(!s->budget--) { s->failed_pc=0x0c09d022u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d026; }
goto P_0c09d024;
P_0c09d024: /* original 0eb6, guest PC 0x0c09d024 */
if(!s->budget--) { s->failed_pc=0x0c09d024u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09d026;
P_0c09d026: /* original 932d, guest PC 0x0c09d026 */
if(!s->budget--) { s->failed_pc=0x0c09d026u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d084u,2);
goto P_0c09d028;
P_0c09d028: /* original 23d8, guest PC 0x0c09d028 */
if(!s->budget--) { s->failed_pc=0x0c09d028u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d02a;
P_0c09d02a: /* original 890a, guest PC 0x0c09d02a */
if(!s->budget--) { s->failed_pc=0x0c09d02au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d042; }
goto P_0c09d02c;
P_0c09d02c: /* original 4c0b, guest PC 0x0c09d02c */
if(!s->budget--) { s->failed_pc=0x0c09d02cu; return 0; }
target=r[12];
r[16]=code_base|0x0c09d030u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d030u) { target=s->pc; goto dispatch; }
goto P_0c09d030;
P_0c09d02e: /* original 64a3, guest PC 0x0c09d02e */
if(!s->budget--) { s->failed_pc=0x0c09d02eu; return 0; }
r[4]=r[10];
goto P_0c09d030;
P_0c09d030: /* original 9027, guest PC 0x0c09d030 */
if(!s->budget--) { s->failed_pc=0x0c09d030u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d082u,2);
goto P_0c09d032;
P_0c09d032: /* original e401, guest PC 0x0c09d032 */
if(!s->budget--) { s->failed_pc=0x0c09d032u; return 0; }
r[4]=0x00000001u;
goto P_0c09d034;
P_0c09d034: /* original 03ee, guest PC 0x0c09d034 */
if(!s->budget--) { s->failed_pc=0x0c09d034u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09d036;
P_0c09d036: /* original 7301, guest PC 0x0c09d036 */
if(!s->budget--) { s->failed_pc=0x0c09d036u; return 0; }
r[3]+=0x00000001u;
goto P_0c09d038;
P_0c09d038: /* original 0e36, guest PC 0x0c09d038 */
if(!s->budget--) { s->failed_pc=0x0c09d038u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09d03a;
P_0c09d03a: /* original 02ee, guest PC 0x0c09d03a */
if(!s->budget--) { s->failed_pc=0x0c09d03au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09d03c;
P_0c09d03c: /* original 3243, guest PC 0x0c09d03c */
if(!s->budget--) { s->failed_pc=0x0c09d03cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[4])!=0);
goto P_0c09d03e;
P_0c09d03e: /* original 8b00, guest PC 0x0c09d03e */
if(!s->budget--) { s->failed_pc=0x0c09d03eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09d042; }
goto P_0c09d040;
P_0c09d040: /* original 0e46, guest PC 0x0c09d040 */
if(!s->budget--) { s->failed_pc=0x0c09d040u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09d042;
P_0c09d042: /* original e304, guest PC 0x0c09d042 */
if(!s->budget--) { s->failed_pc=0x0c09d042u; return 0; }
r[3]=0x00000004u;
goto P_0c09d044;
P_0c09d044: /* original 23d8, guest PC 0x0c09d044 */
if(!s->budget--) { s->failed_pc=0x0c09d044u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d046;
P_0c09d046: /* original 8902, guest PC 0x0c09d046 */
if(!s->budget--) { s->failed_pc=0x0c09d046u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d04e; }
goto P_0c09d048;
P_0c09d048: /* original 941d, guest PC 0x0c09d048 */
if(!s->budget--) { s->failed_pc=0x0c09d048u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d086u,2);
goto P_0c09d04a;
P_0c09d04a: /* original 4c0b, guest PC 0x0c09d04a */
if(!s->budget--) { s->failed_pc=0x0c09d04au; return 0; }
target=r[12];
r[16]=code_base|0x0c09d04eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d04eu) { target=s->pc; goto dispatch; }
goto P_0c09d04e;
P_0c09d04c: /* original 0009, guest PC 0x0c09d04c */
if(!s->budget--) { s->failed_pc=0x0c09d04cu; return 0; }
goto P_0c09d04e;
P_0c09d04e: /* original e30a, guest PC 0x0c09d04e */
if(!s->budget--) { s->failed_pc=0x0c09d04eu; return 0; }
r[3]=0x0000000au;
goto P_0c09d050;
P_0c09d050: /* original 23d8, guest PC 0x0c09d050 */
if(!s->budget--) { s->failed_pc=0x0c09d050u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c09d052;
P_0c09d052: /* original 890d, guest PC 0x0c09d052 */
if(!s->budget--) { s->failed_pc=0x0c09d052u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d070; }
goto P_0c09d054;
P_0c09d054: /* original e108, guest PC 0x0c09d054 */
if(!s->budget--) { s->failed_pc=0x0c09d054u; return 0; }
r[1]=0x00000008u;
goto P_0c09d056;
P_0c09d056: /* original 2d18, guest PC 0x0c09d056 */
if(!s->budget--) { s->failed_pc=0x0c09d056u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[1])==0)!=0);
goto P_0c09d058;
P_0c09d058: /* original 8902, guest PC 0x0c09d058 */
if(!s->budget--) { s->failed_pc=0x0c09d058u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09d060; }
goto P_0c09d05a;
P_0c09d05a: /* original 9414, guest PC 0x0c09d05a */
if(!s->budget--) { s->failed_pc=0x0c09d05au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d086u,2);
goto P_0c09d05c;
P_0c09d05c: /* original a001, guest PC 0x0c09d05c */
if(!s->budget--) { s->failed_pc=0x0c09d05cu; return 0; }
goto P_0c09d062;
P_0c09d05e: /* original 0009, guest PC 0x0c09d05e */
if(!s->budget--) { s->failed_pc=0x0c09d05eu; return 0; }
goto P_0c09d060;
P_0c09d060: /* original 9412, guest PC 0x0c09d060 */
if(!s->budget--) { s->failed_pc=0x0c09d060u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09d088u,2);
goto P_0c09d062;
P_0c09d062: /* original 4c0b, guest PC 0x0c09d062 */
if(!s->budget--) { s->failed_pc=0x0c09d062u; return 0; }
target=r[12];
r[16]=code_base|0x0c09d066u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09d066u) { target=s->pc; goto dispatch; }
goto P_0c09d066;
P_0c09d064: /* original 0009, guest PC 0x0c09d064 */
if(!s->budget--) { s->failed_pc=0x0c09d064u; return 0; }
goto P_0c09d066;
P_0c09d066: /* original e005, guest PC 0x0c09d066 */
if(!s->budget--) { s->failed_pc=0x0c09d066u; return 0; }
r[0]=0x00000005u;
goto P_0c09d068;
P_0c09d068: /* original 80eb, guest PC 0x0c09d068 */
if(!s->budget--) { s->failed_pc=0x0c09d068u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09d06a;
P_0c09d06a: /* original e010, guest PC 0x0c09d06a */
if(!s->budget--) { s->failed_pc=0x0c09d06au; return 0; }
r[0]=0x00000010u;
goto P_0c09d06c;
P_0c09d06c: /* original e374, guest PC 0x0c09d06c */
if(!s->budget--) { s->failed_pc=0x0c09d06cu; return 0; }
r[3]=0x00000074u;
goto P_0c09d06e;
P_0c09d06e: /* original 0e34, guest PC 0x0c09d06e */
if(!s->budget--) { s->failed_pc=0x0c09d06eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c09d070;
P_0c09d070: /* original 4f26, guest PC 0x0c09d070 */
if(!s->budget--) { s->failed_pc=0x0c09d070u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09d072;
P_0c09d072: /* original 6af6, guest PC 0x0c09d072 */
if(!s->budget--) { s->failed_pc=0x0c09d072u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09d074;
P_0c09d074: /* original 6bf6, guest PC 0x0c09d074 */
if(!s->budget--) { s->failed_pc=0x0c09d074u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09d076;
P_0c09d076: /* original 6cf6, guest PC 0x0c09d076 */
if(!s->budget--) { s->failed_pc=0x0c09d076u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09d078;
P_0c09d078: /* original 6df6, guest PC 0x0c09d078 */
if(!s->budget--) { s->failed_pc=0x0c09d078u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09d07a;
P_0c09d07a: /* original 000b, guest PC 0x0c09d07a */
if(!s->budget--) { s->failed_pc=0x0c09d07au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09d07c: /* original 6ef6, guest PC 0x0c09d07c */
if(!s->budget--) { s->failed_pc=0x0c09d07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09d07eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09d07eu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
