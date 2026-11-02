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
int vf3_away_batch183_adapter_1(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c096718u: goto P_0c096718;
case 0x0c09671au: goto P_0c09671a;
case 0x0c09671cu: goto P_0c09671c;
case 0x0c09671eu: goto P_0c09671e;
case 0x0c096720u: goto P_0c096720;
case 0x0c096722u: goto P_0c096722;
case 0x0c096724u: goto P_0c096724;
case 0x0c096726u: goto P_0c096726;
case 0x0c096728u: goto P_0c096728;
case 0x0c09672au: goto P_0c09672a;
case 0x0c09672cu: goto P_0c09672c;
case 0x0c09672eu: goto P_0c09672e;
case 0x0c096730u: goto P_0c096730;
case 0x0c096732u: goto P_0c096732;
case 0x0c096734u: goto P_0c096734;
case 0x0c096736u: goto P_0c096736;
case 0x0c096738u: goto P_0c096738;
case 0x0c09673au: goto P_0c09673a;
case 0x0c09673cu: goto P_0c09673c;
case 0x0c09673eu: goto P_0c09673e;
case 0x0c096740u: goto P_0c096740;
case 0x0c096742u: goto P_0c096742;
case 0x0c096744u: goto P_0c096744;
case 0x0c096746u: goto P_0c096746;
case 0x0c0967e8u: goto P_0c0967e8;
case 0x0c0967eau: goto P_0c0967ea;
case 0x0c0967ecu: goto P_0c0967ec;
case 0x0c0967eeu: goto P_0c0967ee;
case 0x0c0967f0u: goto P_0c0967f0;
case 0x0c0967f2u: goto P_0c0967f2;
case 0x0c0967f4u: goto P_0c0967f4;
case 0x0c0967f6u: goto P_0c0967f6;
case 0x0c0967f8u: goto P_0c0967f8;
case 0x0c0967fau: goto P_0c0967fa;
case 0x0c0967fcu: goto P_0c0967fc;
case 0x0c0967feu: goto P_0c0967fe;
case 0x0c096800u: goto P_0c096800;
case 0x0c096802u: goto P_0c096802;
case 0x0c096804u: goto P_0c096804;
case 0x0c096806u: goto P_0c096806;
case 0x0c096808u: goto P_0c096808;
case 0x0c09680au: goto P_0c09680a;
case 0x0c09680cu: goto P_0c09680c;
case 0x0c09680eu: goto P_0c09680e;
case 0x0c096810u: goto P_0c096810;
case 0x0c096812u: goto P_0c096812;
case 0x0c096814u: goto P_0c096814;
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
case 0x0c09b006u: goto P_0c09b006;
case 0x0c09b008u: goto P_0c09b008;
case 0x0c09b00au: goto P_0c09b00a;
case 0x0c09b00cu: goto P_0c09b00c;
case 0x0c09b00eu: goto P_0c09b00e;
case 0x0c09b010u: goto P_0c09b010;
case 0x0c09b012u: goto P_0c09b012;
case 0x0c09b014u: goto P_0c09b014;
case 0x0c09b016u: goto P_0c09b016;
case 0x0c09b018u: goto P_0c09b018;
case 0x0c09b01au: goto P_0c09b01a;
case 0x0c09b01cu: goto P_0c09b01c;
case 0x0c09b01eu: goto P_0c09b01e;
case 0x0c09b020u: goto P_0c09b020;
case 0x0c09b022u: goto P_0c09b022;
case 0x0c09b024u: goto P_0c09b024;
case 0x0c09befcu: goto P_0c09befc;
case 0x0c09befeu: goto P_0c09befe;
case 0x0c09bf00u: goto P_0c09bf00;
case 0x0c09bf02u: goto P_0c09bf02;
case 0x0c09bf04u: goto P_0c09bf04;
case 0x0c09bf06u: goto P_0c09bf06;
case 0x0c09bf08u: goto P_0c09bf08;
case 0x0c09bf0au: goto P_0c09bf0a;
case 0x0c09bf0cu: goto P_0c09bf0c;
case 0x0c09bf0eu: goto P_0c09bf0e;
case 0x0c09bf10u: goto P_0c09bf10;
case 0x0c09bf12u: goto P_0c09bf12;
case 0x0c09bf14u: goto P_0c09bf14;
case 0x0c09bf16u: goto P_0c09bf16;
case 0x0c09bf18u: goto P_0c09bf18;
case 0x0c09bf1au: goto P_0c09bf1a;
case 0x0c09bf1cu: goto P_0c09bf1c;
case 0x0c09bf1eu: goto P_0c09bf1e;
case 0x0c09bf20u: goto P_0c09bf20;
case 0x0c09bf22u: goto P_0c09bf22;
case 0x0c09bf24u: goto P_0c09bf24;
case 0x0c09bf26u: goto P_0c09bf26;
case 0x0c09bf28u: goto P_0c09bf28;
case 0x0c09bf2au: goto P_0c09bf2a;
case 0x0c09bf2cu: goto P_0c09bf2c;
case 0x0c09bf2eu: goto P_0c09bf2e;
case 0x0c09bf30u: goto P_0c09bf30;
case 0x0c09bf32u: goto P_0c09bf32;
case 0x0c09bf34u: goto P_0c09bf34;
case 0x0c09bf36u: goto P_0c09bf36;
case 0x0c09bf38u: goto P_0c09bf38;
case 0x0c09bf3au: goto P_0c09bf3a;
case 0x0c09bf3cu: goto P_0c09bf3c;
case 0x0c09bf3eu: goto P_0c09bf3e;
case 0x0c09bf40u: goto P_0c09bf40;
case 0x0c09bf42u: goto P_0c09bf42;
case 0x0c09bf44u: goto P_0c09bf44;
case 0x0c09bf46u: goto P_0c09bf46;
case 0x0c09bf48u: goto P_0c09bf48;
case 0x0c09bf4au: goto P_0c09bf4a;
case 0x0c09bf4cu: goto P_0c09bf4c;
case 0x0c09bf4eu: goto P_0c09bf4e;
case 0x0c09bf50u: goto P_0c09bf50;
case 0x0c09bf52u: goto P_0c09bf52;
case 0x0c09bf54u: goto P_0c09bf54;
case 0x0c09bf56u: goto P_0c09bf56;
case 0x0c09bf58u: goto P_0c09bf58;
case 0x0c09bf5au: goto P_0c09bf5a;
case 0x0c09bf5cu: goto P_0c09bf5c;
case 0x0c09bf5eu: goto P_0c09bf5e;
case 0x0c09bf60u: goto P_0c09bf60;
case 0x0c09bf62u: goto P_0c09bf62;
case 0x0c09bf64u: goto P_0c09bf64;
case 0x0c09bf66u: goto P_0c09bf66;
case 0x0c09bf68u: goto P_0c09bf68;
case 0x0c09bf6au: goto P_0c09bf6a;
case 0x0c09bf6cu: goto P_0c09bf6c;
case 0x0c09bf6eu: goto P_0c09bf6e;
case 0x0c09bf70u: goto P_0c09bf70;
case 0x0c09bf72u: goto P_0c09bf72;
case 0x0c09bf74u: goto P_0c09bf74;
case 0x0c09bf76u: goto P_0c09bf76;
case 0x0c09bf78u: goto P_0c09bf78;
case 0x0c09bf7au: goto P_0c09bf7a;
case 0x0c09bf7cu: goto P_0c09bf7c;
case 0x0c09bf7eu: goto P_0c09bf7e;
case 0x0c09bf80u: goto P_0c09bf80;
case 0x0c09bf82u: goto P_0c09bf82;
case 0x0c09bf84u: goto P_0c09bf84;
case 0x0c09bf86u: goto P_0c09bf86;
case 0x0c09bf88u: goto P_0c09bf88;
case 0x0c09bf8au: goto P_0c09bf8a;
case 0x0c09bf8cu: goto P_0c09bf8c;
case 0x0c09bf8eu: goto P_0c09bf8e;
case 0x0c09bf90u: goto P_0c09bf90;
case 0x0c09bf92u: goto P_0c09bf92;
case 0x0c09bfa8u: goto P_0c09bfa8;
case 0x0c09bfaau: goto P_0c09bfaa;
case 0x0c09bfacu: goto P_0c09bfac;
case 0x0c09bfaeu: goto P_0c09bfae;
case 0x0c09bfb0u: goto P_0c09bfb0;
case 0x0c09bfb2u: goto P_0c09bfb2;
case 0x0c09bfb4u: goto P_0c09bfb4;
case 0x0c09bfb6u: goto P_0c09bfb6;
case 0x0c09bfb8u: goto P_0c09bfb8;
case 0x0c09bfbau: goto P_0c09bfba;
case 0x0c09bfbcu: goto P_0c09bfbc;
case 0x0c09bfbeu: goto P_0c09bfbe;
case 0x0c09bfc0u: goto P_0c09bfc0;
case 0x0c09bfc2u: goto P_0c09bfc2;
case 0x0c09bfc4u: goto P_0c09bfc4;
case 0x0c09bfc6u: goto P_0c09bfc6;
case 0x0c09bfc8u: goto P_0c09bfc8;
case 0x0c09bfcau: goto P_0c09bfca;
case 0x0c09bfccu: goto P_0c09bfcc;
case 0x0c09bfceu: goto P_0c09bfce;
case 0x0c09bfd0u: goto P_0c09bfd0;
case 0x0c09bfd2u: goto P_0c09bfd2;
case 0x0c09bfd4u: goto P_0c09bfd4;
case 0x0c09bfd6u: goto P_0c09bfd6;
case 0x0c09bfd8u: goto P_0c09bfd8;
case 0x0c09bfdau: goto P_0c09bfda;
case 0x0c09bfdcu: goto P_0c09bfdc;
case 0x0c09bfdeu: goto P_0c09bfde;
case 0x0c09bfe0u: goto P_0c09bfe0;
case 0x0c09bfe2u: goto P_0c09bfe2;
case 0x0c09bfe4u: goto P_0c09bfe4;
case 0x0c09bfe6u: goto P_0c09bfe6;
case 0x0c09bfe8u: goto P_0c09bfe8;
case 0x0c09bfeau: goto P_0c09bfea;
case 0x0c09bfecu: goto P_0c09bfec;
case 0x0c09bfeeu: goto P_0c09bfee;
case 0x0c09bff0u: goto P_0c09bff0;
case 0x0c09bff2u: goto P_0c09bff2;
case 0x0c09bff4u: goto P_0c09bff4;
case 0x0c09bff6u: goto P_0c09bff6;
case 0x0c09bff8u: goto P_0c09bff8;
case 0x0c09bffau: goto P_0c09bffa;
case 0x0c09bffcu: goto P_0c09bffc;
case 0x0c09bffeu: goto P_0c09bffe;
case 0x0c09c000u: goto P_0c09c000;
case 0x0c09c002u: goto P_0c09c002;
case 0x0c09c004u: goto P_0c09c004;
case 0x0c09c006u: goto P_0c09c006;
case 0x0c09c008u: goto P_0c09c008;
case 0x0c09c00au: goto P_0c09c00a;
case 0x0c09c00cu: goto P_0c09c00c;
case 0x0c09c00eu: goto P_0c09c00e;
case 0x0c09c010u: goto P_0c09c010;
case 0x0c09c012u: goto P_0c09c012;
case 0x0c09c014u: goto P_0c09c014;
case 0x0c09c016u: goto P_0c09c016;
case 0x0c09c018u: goto P_0c09c018;
case 0x0c09c01au: goto P_0c09c01a;
case 0x0c09c01cu: goto P_0c09c01c;
case 0x0c09c01eu: goto P_0c09c01e;
case 0x0c09c020u: goto P_0c09c020;
case 0x0c09c022u: goto P_0c09c022;
case 0x0c09c024u: goto P_0c09c024;
case 0x0c09c026u: goto P_0c09c026;
case 0x0c09c028u: goto P_0c09c028;
case 0x0c09c02au: goto P_0c09c02a;
case 0x0c09c02cu: goto P_0c09c02c;
case 0x0c09c02eu: goto P_0c09c02e;
case 0x0c09c030u: goto P_0c09c030;
case 0x0c09c032u: goto P_0c09c032;
case 0x0c09c034u: goto P_0c09c034;
default: return vf3_matrix_family(target,s,ram);
}
P_0c096718: /* original 4f22, guest PC 0x0c096718 */
if(!s->budget--) { s->failed_pc=0x0c096718u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09671a;
P_0c09671a: /* original d340, guest PC 0x0c09671a */
if(!s->budget--) { s->failed_pc=0x0c09671au; return 0; }
r[3]=read(ram,0x0c09681cu,4);
goto P_0c09671c;
P_0c09671c: /* original 430b, guest PC 0x0c09671c */
if(!s->budget--) { s->failed_pc=0x0c09671cu; return 0; }
target=r[3];
r[16]=code_base|0x0c096720u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096720u) { target=s->pc; goto dispatch; }
goto P_0c096720;
P_0c09671e: /* original 0009, guest PC 0x0c09671e */
if(!s->budget--) { s->failed_pc=0x0c09671eu; return 0; }
goto P_0c096720;
P_0c096720: /* original d23f, guest PC 0x0c096720 */
if(!s->budget--) { s->failed_pc=0x0c096720u; return 0; }
r[2]=read(ram,0x0c096820u,4);
goto P_0c096722;
P_0c096722: /* original 420b, guest PC 0x0c096722 */
if(!s->budget--) { s->failed_pc=0x0c096722u; return 0; }
target=r[2];
r[16]=code_base|0x0c096726u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096726u) { target=s->pc; goto dispatch; }
goto P_0c096726;
P_0c096724: /* original 0009, guest PC 0x0c096724 */
if(!s->budget--) { s->failed_pc=0x0c096724u; return 0; }
goto P_0c096726;
P_0c096726: /* original d33f, guest PC 0x0c096726 */
if(!s->budget--) { s->failed_pc=0x0c096726u; return 0; }
r[3]=read(ram,0x0c096824u,4);
goto P_0c096728;
P_0c096728: /* original 430b, guest PC 0x0c096728 */
if(!s->budget--) { s->failed_pc=0x0c096728u; return 0; }
target=r[3];
r[16]=code_base|0x0c09672cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09672cu) { target=s->pc; goto dispatch; }
goto P_0c09672c;
P_0c09672a: /* original 0009, guest PC 0x0c09672a */
if(!s->budget--) { s->failed_pc=0x0c09672au; return 0; }
goto P_0c09672c;
P_0c09672c: /* original d23e, guest PC 0x0c09672c */
if(!s->budget--) { s->failed_pc=0x0c09672cu; return 0; }
r[2]=read(ram,0x0c096828u,4);
goto P_0c09672e;
P_0c09672e: /* original 420b, guest PC 0x0c09672e */
if(!s->budget--) { s->failed_pc=0x0c09672eu; return 0; }
target=r[2];
r[16]=code_base|0x0c096732u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096732u) { target=s->pc; goto dispatch; }
goto P_0c096732;
P_0c096730: /* original 0009, guest PC 0x0c096730 */
if(!s->budget--) { s->failed_pc=0x0c096730u; return 0; }
goto P_0c096732;
P_0c096732: /* original d33e, guest PC 0x0c096732 */
if(!s->budget--) { s->failed_pc=0x0c096732u; return 0; }
r[3]=read(ram,0x0c09682cu,4);
goto P_0c096734;
P_0c096734: /* original 430b, guest PC 0x0c096734 */
if(!s->budget--) { s->failed_pc=0x0c096734u; return 0; }
target=r[3];
r[16]=code_base|0x0c096738u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096738u) { target=s->pc; goto dispatch; }
goto P_0c096738;
P_0c096736: /* original 0009, guest PC 0x0c096736 */
if(!s->budget--) { s->failed_pc=0x0c096736u; return 0; }
goto P_0c096738;
P_0c096738: /* original d23d, guest PC 0x0c096738 */
if(!s->budget--) { s->failed_pc=0x0c096738u; return 0; }
r[2]=read(ram,0x0c096830u,4);
goto P_0c09673a;
P_0c09673a: /* original 420b, guest PC 0x0c09673a */
if(!s->budget--) { s->failed_pc=0x0c09673au; return 0; }
target=r[2];
r[16]=code_base|0x0c09673eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09673eu) { target=s->pc; goto dispatch; }
goto P_0c09673e;
P_0c09673c: /* original e400, guest PC 0x0c09673c */
if(!s->budget--) { s->failed_pc=0x0c09673cu; return 0; }
r[4]=0x00000000u;
goto P_0c09673e;
P_0c09673e: /* original d33d, guest PC 0x0c09673e */
if(!s->budget--) { s->failed_pc=0x0c09673eu; return 0; }
r[3]=read(ram,0x0c096834u,4);
goto P_0c096740;
P_0c096740: /* original 430b, guest PC 0x0c096740 */
if(!s->budget--) { s->failed_pc=0x0c096740u; return 0; }
target=r[3];
r[16]=code_base|0x0c096744u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096744u) { target=s->pc; goto dispatch; }
goto P_0c096744;
P_0c096742: /* original 0009, guest PC 0x0c096742 */
if(!s->budget--) { s->failed_pc=0x0c096742u; return 0; }
goto P_0c096744;
P_0c096744: /* original a050, guest PC 0x0c096744 */
if(!s->budget--) { s->failed_pc=0x0c096744u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0967e8;
P_0c096746: /* original 4f26, guest PC 0x0c096746 */
if(!s->budget--) { s->failed_pc=0x0c096746u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c096748u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096748u; return 0; } return 1;
P_0c0967e8: /* original 2fe6, guest PC 0x0c0967e8 */
if(!s->budget--) { s->failed_pc=0x0c0967e8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ea;
P_0c0967ea: /* original 2fd6, guest PC 0x0c0967ea */
if(!s->budget--) { s->failed_pc=0x0c0967eau; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0967ec;
P_0c0967ec: /* original de18, guest PC 0x0c0967ec */
if(!s->budget--) { s->failed_pc=0x0c0967ecu; return 0; }
r[14]=read(ram,0x0c096850u,4);
goto P_0c0967ee;
P_0c0967ee: /* original 4f22, guest PC 0x0c0967ee */
if(!s->budget--) { s->failed_pc=0x0c0967eeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0967f0;
P_0c0967f0: /* original dd19, guest PC 0x0c0967f0 */
if(!s->budget--) { s->failed_pc=0x0c0967f0u; return 0; }
r[13]=read(ram,0x0c096858u,4);
goto P_0c0967f2;
P_0c0967f2: /* original 64e3, guest PC 0x0c0967f2 */
if(!s->budget--) { s->failed_pc=0x0c0967f2u; return 0; }
r[4]=r[14];
goto P_0c0967f4;
P_0c0967f4: /* original d517, guest PC 0x0c0967f4 */
if(!s->budget--) { s->failed_pc=0x0c0967f4u; return 0; }
r[5]=read(ram,0x0c096854u,4);
goto P_0c0967f6;
P_0c0967f6: /* original 4d0b, guest PC 0x0c0967f6 */
if(!s->budget--) { s->failed_pc=0x0c0967f6u; return 0; }
target=r[13];
r[16]=code_base|0x0c0967fau;
r[4]+=0x0000002cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0967fau) { target=s->pc; goto dispatch; }
goto P_0c0967fa;
P_0c0967f8: /* original 742c, guest PC 0x0c0967f8 */
if(!s->budget--) { s->failed_pc=0x0c0967f8u; return 0; }
r[4]+=0x0000002cu;
goto P_0c0967fa;
P_0c0967fa: /* original d518, guest PC 0x0c0967fa */
if(!s->budget--) { s->failed_pc=0x0c0967fau; return 0; }
r[5]=read(ram,0x0c09685cu,4);
goto P_0c0967fc;
P_0c0967fc: /* original 64e3, guest PC 0x0c0967fc */
if(!s->budget--) { s->failed_pc=0x0c0967fcu; return 0; }
r[4]=r[14];
goto P_0c0967fe;
P_0c0967fe: /* original 6552, guest PC 0x0c0967fe */
if(!s->budget--) { s->failed_pc=0x0c0967feu; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c096800;
P_0c096800: /* original 4d0b, guest PC 0x0c096800 */
if(!s->budget--) { s->failed_pc=0x0c096800u; return 0; }
target=r[13];
r[16]=code_base|0x0c096804u;
r[4]+=0x00000034u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c096804u) { target=s->pc; goto dispatch; }
goto P_0c096804;
P_0c096802: /* original 7434, guest PC 0x0c096802 */
if(!s->budget--) { s->failed_pc=0x0c096802u; return 0; }
r[4]+=0x00000034u;
goto P_0c096804;
P_0c096804: /* original d516, guest PC 0x0c096804 */
if(!s->budget--) { s->failed_pc=0x0c096804u; return 0; }
r[5]=read(ram,0x0c096860u,4);
goto P_0c096806;
P_0c096806: /* original 64e3, guest PC 0x0c096806 */
if(!s->budget--) { s->failed_pc=0x0c096806u; return 0; }
r[4]=r[14];
goto P_0c096808;
P_0c096808: /* original 6552, guest PC 0x0c096808 */
if(!s->budget--) { s->failed_pc=0x0c096808u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c09680a;
P_0c09680a: /* original 4d0b, guest PC 0x0c09680a */
if(!s->budget--) { s->failed_pc=0x0c09680au; return 0; }
target=r[13];
r[16]=code_base|0x0c09680eu;
r[4]+=0x00000038u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09680eu) { target=s->pc; goto dispatch; }
goto P_0c09680e;
P_0c09680c: /* original 7438, guest PC 0x0c09680c */
if(!s->budget--) { s->failed_pc=0x0c09680cu; return 0; }
r[4]+=0x00000038u;
goto P_0c09680e;
P_0c09680e: /* original 4f26, guest PC 0x0c09680e */
if(!s->budget--) { s->failed_pc=0x0c09680eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c096810;
P_0c096810: /* original 6df6, guest PC 0x0c096810 */
if(!s->budget--) { s->failed_pc=0x0c096810u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c096812;
P_0c096812: /* original 000b, guest PC 0x0c096812 */
if(!s->budget--) { s->failed_pc=0x0c096812u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c096814: /* original 6ef6, guest PC 0x0c096814 */
if(!s->budget--) { s->failed_pc=0x0c096814u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c096816u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c096816u; return 0; } return 1;
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
P_0c09b006: /* original 4f22, guest PC 0x0c09b006 */
if(!s->budget--) { s->failed_pc=0x0c09b006u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b008;
P_0c09b008: /* original d309, guest PC 0x0c09b008 */
if(!s->budget--) { s->failed_pc=0x0c09b008u; return 0; }
r[3]=read(ram,0x0c09b030u,4);
goto P_0c09b00a;
P_0c09b00a: /* original 430b, guest PC 0x0c09b00a */
if(!s->budget--) { s->failed_pc=0x0c09b00au; return 0; }
target=r[3];
r[16]=code_base|0x0c09b00eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b00eu) { target=s->pc; goto dispatch; }
goto P_0c09b00e;
P_0c09b00c: /* original 0009, guest PC 0x0c09b00c */
if(!s->budget--) { s->failed_pc=0x0c09b00cu; return 0; }
goto P_0c09b00e;
P_0c09b00e: /* original 6403, guest PC 0x0c09b00e */
if(!s->budget--) { s->failed_pc=0x0c09b00eu; return 0; }
r[4]=r[0];
goto P_0c09b010;
P_0c09b010: /* original 6042, guest PC 0x0c09b010 */
if(!s->budget--) { s->failed_pc=0x0c09b010u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09b012;
P_0c09b012: /* original 88fe, guest PC 0x0c09b012 */
if(!s->budget--) { s->failed_pc=0x0c09b012u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09b014;
P_0c09b014: /* original 8b03, guest PC 0x0c09b014 */
if(!s->budget--) { s->failed_pc=0x0c09b014u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b01e; }
goto P_0c09b016;
P_0c09b016: /* original 4f26, guest PC 0x0c09b016 */
if(!s->budget--) { s->failed_pc=0x0c09b016u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b018;
P_0c09b018: /* original d008, guest PC 0x0c09b018 */
if(!s->budget--) { s->failed_pc=0x0c09b018u; return 0; }
r[0]=read(ram,0x0c09b03cu,4);
goto P_0c09b01a;
P_0c09b01a: /* original 000b, guest PC 0x0c09b01a */
if(!s->budget--) { s->failed_pc=0x0c09b01au; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09b01c: /* original 0009, guest PC 0x0c09b01c */
if(!s->budget--) { s->failed_pc=0x0c09b01cu; return 0; }
goto P_0c09b01e;
P_0c09b01e: /* original 5042, guest PC 0x0c09b01e */
if(!s->budget--) { s->failed_pc=0x0c09b01eu; return 0; }
r[0]=read(ram,r[4]+8,4);
goto P_0c09b020;
P_0c09b020: /* original 4f26, guest PC 0x0c09b020 */
if(!s->budget--) { s->failed_pc=0x0c09b020u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b022;
P_0c09b022: /* original 000b, guest PC 0x0c09b022 */
if(!s->budget--) { s->failed_pc=0x0c09b022u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09b024: /* original 0009, guest PC 0x0c09b024 */
if(!s->budget--) { s->failed_pc=0x0c09b024u; return 0; }
if(!vf3_matrix_family(0x0c09b026u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b026u; return 0; } return 1;
P_0c09befc: /* original 6242, guest PC 0x0c09befc */
if(!s->budget--) { s->failed_pc=0x0c09befcu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09befe;
P_0c09befe: /* original 5341, guest PC 0x0c09befe */
if(!s->budget--) { s->failed_pc=0x0c09befeu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09bf00;
P_0c09bf00: /* original 5142, guest PC 0x0c09bf00 */
if(!s->budget--) { s->failed_pc=0x0c09bf00u; return 0; }
r[1]=read(ram,r[4]+8,4);
goto P_0c09bf02;
P_0c09bf02: /* original 2239, guest PC 0x0c09bf02 */
if(!s->budget--) { s->failed_pc=0x0c09bf02u; return 0; }
r[2]&=r[3];
goto P_0c09bf04;
P_0c09bf04: /* original 2219, guest PC 0x0c09bf04 */
if(!s->budget--) { s->failed_pc=0x0c09bf04u; return 0; }
r[2]&=r[1];
goto P_0c09bf06;
P_0c09bf06: /* original 2258, guest PC 0x0c09bf06 */
if(!s->budget--) { s->failed_pc=0x0c09bf06u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf08;
P_0c09bf08: /* original 8902, guest PC 0x0c09bf08 */
if(!s->budget--) { s->failed_pc=0x0c09bf08u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf10; }
goto P_0c09bf0a;
P_0c09bf0a: /* original 9044, guest PC 0x0c09bf0a */
if(!s->budget--) { s->failed_pc=0x0c09bf0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf96u,2);
goto P_0c09bf0c;
P_0c09bf0c: /* original 000b, guest PC 0x0c09bf0c */
if(!s->budget--) { s->failed_pc=0x0c09bf0cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf0e: /* original 0009, guest PC 0x0c09bf0e */
if(!s->budget--) { s->failed_pc=0x0c09bf0eu; return 0; }
goto P_0c09bf10;
P_0c09bf10: /* original 6242, guest PC 0x0c09bf10 */
if(!s->budget--) { s->failed_pc=0x0c09bf10u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf12;
P_0c09bf12: /* original 5342, guest PC 0x0c09bf12 */
if(!s->budget--) { s->failed_pc=0x0c09bf12u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09bf14;
P_0c09bf14: /* original 2239, guest PC 0x0c09bf14 */
if(!s->budget--) { s->failed_pc=0x0c09bf14u; return 0; }
r[2]&=r[3];
goto P_0c09bf16;
P_0c09bf16: /* original 2258, guest PC 0x0c09bf16 */
if(!s->budget--) { s->failed_pc=0x0c09bf16u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf18;
P_0c09bf18: /* original 8901, guest PC 0x0c09bf18 */
if(!s->budget--) { s->failed_pc=0x0c09bf18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf1e; }
goto P_0c09bf1a;
P_0c09bf1a: /* original 000b, guest PC 0x0c09bf1a */
if(!s->budget--) { s->failed_pc=0x0c09bf1au; return 0; }
target=r[16];
r[0]=0x00000020u;
s->pc=target; return ram->oob==0;
P_0c09bf1c: /* original e020, guest PC 0x0c09bf1c */
if(!s->budget--) { s->failed_pc=0x0c09bf1cu; return 0; }
r[0]=0x00000020u;
goto P_0c09bf1e;
P_0c09bf1e: /* original 6242, guest PC 0x0c09bf1e */
if(!s->budget--) { s->failed_pc=0x0c09bf1eu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf20;
P_0c09bf20: /* original 5343, guest PC 0x0c09bf20 */
if(!s->budget--) { s->failed_pc=0x0c09bf20u; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c09bf22;
P_0c09bf22: /* original 2239, guest PC 0x0c09bf22 */
if(!s->budget--) { s->failed_pc=0x0c09bf22u; return 0; }
r[2]&=r[3];
goto P_0c09bf24;
P_0c09bf24: /* original 2258, guest PC 0x0c09bf24 */
if(!s->budget--) { s->failed_pc=0x0c09bf24u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf26;
P_0c09bf26: /* original 8901, guest PC 0x0c09bf26 */
if(!s->budget--) { s->failed_pc=0x0c09bf26u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf2c; }
goto P_0c09bf28;
P_0c09bf28: /* original 000b, guest PC 0x0c09bf28 */
if(!s->budget--) { s->failed_pc=0x0c09bf28u; return 0; }
target=r[16];
r[0]=0x00000040u;
s->pc=target; return ram->oob==0;
P_0c09bf2a: /* original e040, guest PC 0x0c09bf2a */
if(!s->budget--) { s->failed_pc=0x0c09bf2au; return 0; }
r[0]=0x00000040u;
goto P_0c09bf2c;
P_0c09bf2c: /* original 5241, guest PC 0x0c09bf2c */
if(!s->budget--) { s->failed_pc=0x0c09bf2cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf2e;
P_0c09bf2e: /* original 5342, guest PC 0x0c09bf2e */
if(!s->budget--) { s->failed_pc=0x0c09bf2eu; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09bf30;
P_0c09bf30: /* original 2239, guest PC 0x0c09bf30 */
if(!s->budget--) { s->failed_pc=0x0c09bf30u; return 0; }
r[2]&=r[3];
goto P_0c09bf32;
P_0c09bf32: /* original 2258, guest PC 0x0c09bf32 */
if(!s->budget--) { s->failed_pc=0x0c09bf32u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf34;
P_0c09bf34: /* original 8902, guest PC 0x0c09bf34 */
if(!s->budget--) { s->failed_pc=0x0c09bf34u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf3c; }
goto P_0c09bf36;
P_0c09bf36: /* original 902f, guest PC 0x0c09bf36 */
if(!s->budget--) { s->failed_pc=0x0c09bf36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf98u,2);
goto P_0c09bf38;
P_0c09bf38: /* original 000b, guest PC 0x0c09bf38 */
if(!s->budget--) { s->failed_pc=0x0c09bf38u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf3a: /* original 0009, guest PC 0x0c09bf3a */
if(!s->budget--) { s->failed_pc=0x0c09bf3au; return 0; }
goto P_0c09bf3c;
P_0c09bf3c: /* original 5241, guest PC 0x0c09bf3c */
if(!s->budget--) { s->failed_pc=0x0c09bf3cu; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf3e;
P_0c09bf3e: /* original 5343, guest PC 0x0c09bf3e */
if(!s->budget--) { s->failed_pc=0x0c09bf3eu; return 0; }
r[3]=read(ram,r[4]+12,4);
goto P_0c09bf40;
P_0c09bf40: /* original 2239, guest PC 0x0c09bf40 */
if(!s->budget--) { s->failed_pc=0x0c09bf40u; return 0; }
r[2]&=r[3];
goto P_0c09bf42;
P_0c09bf42: /* original 2258, guest PC 0x0c09bf42 */
if(!s->budget--) { s->failed_pc=0x0c09bf42u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf44;
P_0c09bf44: /* original 8902, guest PC 0x0c09bf44 */
if(!s->budget--) { s->failed_pc=0x0c09bf44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf4c; }
goto P_0c09bf46;
P_0c09bf46: /* original 9028, guest PC 0x0c09bf46 */
if(!s->budget--) { s->failed_pc=0x0c09bf46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf9au,2);
goto P_0c09bf48;
P_0c09bf48: /* original 000b, guest PC 0x0c09bf48 */
if(!s->budget--) { s->failed_pc=0x0c09bf48u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf4a: /* original 0009, guest PC 0x0c09bf4a */
if(!s->budget--) { s->failed_pc=0x0c09bf4au; return 0; }
goto P_0c09bf4c;
P_0c09bf4c: /* original 6242, guest PC 0x0c09bf4c */
if(!s->budget--) { s->failed_pc=0x0c09bf4cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf4e;
P_0c09bf4e: /* original 5341, guest PC 0x0c09bf4e */
if(!s->budget--) { s->failed_pc=0x0c09bf4eu; return 0; }
r[3]=read(ram,r[4]+4,4);
goto P_0c09bf50;
P_0c09bf50: /* original 2239, guest PC 0x0c09bf50 */
if(!s->budget--) { s->failed_pc=0x0c09bf50u; return 0; }
r[2]&=r[3];
goto P_0c09bf52;
P_0c09bf52: /* original 2258, guest PC 0x0c09bf52 */
if(!s->budget--) { s->failed_pc=0x0c09bf52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf54;
P_0c09bf54: /* original 8902, guest PC 0x0c09bf54 */
if(!s->budget--) { s->failed_pc=0x0c09bf54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf5c; }
goto P_0c09bf56;
P_0c09bf56: /* original 9021, guest PC 0x0c09bf56 */
if(!s->budget--) { s->failed_pc=0x0c09bf56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09bf9cu,2);
goto P_0c09bf58;
P_0c09bf58: /* original 000b, guest PC 0x0c09bf58 */
if(!s->budget--) { s->failed_pc=0x0c09bf58u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf5a: /* original 0009, guest PC 0x0c09bf5a */
if(!s->budget--) { s->failed_pc=0x0c09bf5au; return 0; }
goto P_0c09bf5c;
P_0c09bf5c: /* original 6242, guest PC 0x0c09bf5c */
if(!s->budget--) { s->failed_pc=0x0c09bf5cu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c09bf5e;
P_0c09bf5e: /* original 2258, guest PC 0x0c09bf5e */
if(!s->budget--) { s->failed_pc=0x0c09bf5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf60;
P_0c09bf60: /* original 8901, guest PC 0x0c09bf60 */
if(!s->budget--) { s->failed_pc=0x0c09bf60u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf66; }
goto P_0c09bf62;
P_0c09bf62: /* original 000b, guest PC 0x0c09bf62 */
if(!s->budget--) { s->failed_pc=0x0c09bf62u; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c09bf64: /* original e001, guest PC 0x0c09bf64 */
if(!s->budget--) { s->failed_pc=0x0c09bf64u; return 0; }
r[0]=0x00000001u;
goto P_0c09bf66;
P_0c09bf66: /* original 5241, guest PC 0x0c09bf66 */
if(!s->budget--) { s->failed_pc=0x0c09bf66u; return 0; }
r[2]=read(ram,r[4]+4,4);
goto P_0c09bf68;
P_0c09bf68: /* original 2258, guest PC 0x0c09bf68 */
if(!s->budget--) { s->failed_pc=0x0c09bf68u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf6a;
P_0c09bf6a: /* original 8901, guest PC 0x0c09bf6a */
if(!s->budget--) { s->failed_pc=0x0c09bf6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf70; }
goto P_0c09bf6c;
P_0c09bf6c: /* original 000b, guest PC 0x0c09bf6c */
if(!s->budget--) { s->failed_pc=0x0c09bf6cu; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c09bf6e: /* original e002, guest PC 0x0c09bf6e */
if(!s->budget--) { s->failed_pc=0x0c09bf6eu; return 0; }
r[0]=0x00000002u;
goto P_0c09bf70;
P_0c09bf70: /* original 5242, guest PC 0x0c09bf70 */
if(!s->budget--) { s->failed_pc=0x0c09bf70u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c09bf72;
P_0c09bf72: /* original 2258, guest PC 0x0c09bf72 */
if(!s->budget--) { s->failed_pc=0x0c09bf72u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf74;
P_0c09bf74: /* original 8901, guest PC 0x0c09bf74 */
if(!s->budget--) { s->failed_pc=0x0c09bf74u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf7a; }
goto P_0c09bf76;
P_0c09bf76: /* original 000b, guest PC 0x0c09bf76 */
if(!s->budget--) { s->failed_pc=0x0c09bf76u; return 0; }
target=r[16];
r[0]=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c09bf78: /* original e004, guest PC 0x0c09bf78 */
if(!s->budget--) { s->failed_pc=0x0c09bf78u; return 0; }
r[0]=0x00000004u;
goto P_0c09bf7a;
P_0c09bf7a: /* original 5243, guest PC 0x0c09bf7a */
if(!s->budget--) { s->failed_pc=0x0c09bf7au; return 0; }
r[2]=read(ram,r[4]+12,4);
goto P_0c09bf7c;
P_0c09bf7c: /* original 2258, guest PC 0x0c09bf7c */
if(!s->budget--) { s->failed_pc=0x0c09bf7cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bf7e;
P_0c09bf7e: /* original 8901, guest PC 0x0c09bf7e */
if(!s->budget--) { s->failed_pc=0x0c09bf7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf84; }
goto P_0c09bf80;
P_0c09bf80: /* original 000b, guest PC 0x0c09bf80 */
if(!s->budget--) { s->failed_pc=0x0c09bf80u; return 0; }
target=r[16];
r[0]=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c09bf82: /* original e008, guest PC 0x0c09bf82 */
if(!s->budget--) { s->failed_pc=0x0c09bf82u; return 0; }
r[0]=0x00000008u;
goto P_0c09bf84;
P_0c09bf84: /* original 5244, guest PC 0x0c09bf84 */
if(!s->budget--) { s->failed_pc=0x0c09bf84u; return 0; }
r[2]=read(ram,r[4]+16,4);
goto P_0c09bf86;
P_0c09bf86: /* original 2528, guest PC 0x0c09bf86 */
if(!s->budget--) { s->failed_pc=0x0c09bf86u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09bf88;
P_0c09bf88: /* original 8901, guest PC 0x0c09bf88 */
if(!s->budget--) { s->failed_pc=0x0c09bf88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bf8e; }
goto P_0c09bf8a;
P_0c09bf8a: /* original 000b, guest PC 0x0c09bf8a */
if(!s->budget--) { s->failed_pc=0x0c09bf8au; return 0; }
target=r[16];
r[0]=0x00000010u;
s->pc=target; return ram->oob==0;
P_0c09bf8c: /* original e010, guest PC 0x0c09bf8c */
if(!s->budget--) { s->failed_pc=0x0c09bf8cu; return 0; }
r[0]=0x00000010u;
goto P_0c09bf8e;
P_0c09bf8e: /* original e000, guest PC 0x0c09bf8e */
if(!s->budget--) { s->failed_pc=0x0c09bf8eu; return 0; }
r[0]=0x00000000u;
goto P_0c09bf90;
P_0c09bf90: /* original 000b, guest PC 0x0c09bf90 */
if(!s->budget--) { s->failed_pc=0x0c09bf90u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c09bf92: /* original 0009, guest PC 0x0c09bf92 */
if(!s->budget--) { s->failed_pc=0x0c09bf92u; return 0; }
if(!vf3_matrix_family(0x0c09bf94u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09bf94u; return 0; } return 1;
P_0c09bfa8: /* original 6043, guest PC 0x0c09bfa8 */
if(!s->budget--) { s->failed_pc=0x0c09bfa8u; return 0; }
r[0]=r[4];
goto P_0c09bfaa;
P_0c09bfaa: /* original 9384, guest PC 0x0c09bfaa */
if(!s->budget--) { s->failed_pc=0x0c09bfaau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfac;
P_0c09bfac: /* original 4008, guest PC 0x0c09bfac */
if(!s->budget--) { s->failed_pc=0x0c09bfacu; return 0; }
r[0]<<=2;
goto P_0c09bfae;
P_0c09bfae: /* original d746, guest PC 0x0c09bfae */
if(!s->budget--) { s->failed_pc=0x0c09bfaeu; return 0; }
r[7]=read(ram,0x0c09c0c8u,4);
goto P_0c09bfb0;
P_0c09bfb0: /* original 4008, guest PC 0x0c09bfb0 */
if(!s->budget--) { s->failed_pc=0x0c09bfb0u; return 0; }
r[0]<<=2;
goto P_0c09bfb2;
P_0c09bfb2: /* original 337c, guest PC 0x0c09bfb2 */
if(!s->budget--) { s->failed_pc=0x0c09bfb2u; return 0; }
r[3]+=r[7];
goto P_0c09bfb4;
P_0c09bfb4: /* original 4008, guest PC 0x0c09bfb4 */
if(!s->budget--) { s->failed_pc=0x0c09bfb4u; return 0; }
r[0]<<=2;
goto P_0c09bfb6;
P_0c09bfb6: /* original 330c, guest PC 0x0c09bfb6 */
if(!s->budget--) { s->failed_pc=0x0c09bfb6u; return 0; }
r[3]+=r[0];
goto P_0c09bfb8;
P_0c09bfb8: /* original 5231, guest PC 0x0c09bfb8 */
if(!s->budget--) { s->failed_pc=0x0c09bfb8u; return 0; }
r[2]=read(ram,r[3]+4,4);
goto P_0c09bfba;
P_0c09bfba: /* original 2258, guest PC 0x0c09bfba */
if(!s->budget--) { s->failed_pc=0x0c09bfbau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bfbc;
P_0c09bfbc: /* original 8d01, guest PC 0x0c09bfbc */
if(!s->budget--) { s->failed_pc=0x0c09bfbcu; return 0; }
cond=r[17]&1u;
r[6]=0x00000000u;
if(cond) { goto P_0c09bfc2; }
goto P_0c09bfc0;
P_0c09bfbe: /* original e600, guest PC 0x0c09bfbe */
if(!s->budget--) { s->failed_pc=0x0c09bfbeu; return 0; }
r[6]=0x00000000u;
goto P_0c09bfc0;
P_0c09bfc0: /* original e604, guest PC 0x0c09bfc0 */
if(!s->budget--) { s->failed_pc=0x0c09bfc0u; return 0; }
r[6]=0x00000004u;
goto P_0c09bfc2;
P_0c09bfc2: /* original 9278, guest PC 0x0c09bfc2 */
if(!s->budget--) { s->failed_pc=0x0c09bfc2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfc4;
P_0c09bfc4: /* original 327c, guest PC 0x0c09bfc4 */
if(!s->budget--) { s->failed_pc=0x0c09bfc4u; return 0; }
r[2]+=r[7];
goto P_0c09bfc6;
P_0c09bfc6: /* original 320c, guest PC 0x0c09bfc6 */
if(!s->budget--) { s->failed_pc=0x0c09bfc6u; return 0; }
r[2]+=r[0];
goto P_0c09bfc8;
P_0c09bfc8: /* original 5322, guest PC 0x0c09bfc8 */
if(!s->budget--) { s->failed_pc=0x0c09bfc8u; return 0; }
r[3]=read(ram,r[2]+8,4);
goto P_0c09bfca;
P_0c09bfca: /* original 2358, guest PC 0x0c09bfca */
if(!s->budget--) { s->failed_pc=0x0c09bfcau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c09bfcc;
P_0c09bfcc: /* original 8901, guest PC 0x0c09bfcc */
if(!s->budget--) { s->failed_pc=0x0c09bfccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bfd2; }
goto P_0c09bfce;
P_0c09bfce: /* original e102, guest PC 0x0c09bfce */
if(!s->budget--) { s->failed_pc=0x0c09bfceu; return 0; }
r[1]=0x00000002u;
goto P_0c09bfd0;
P_0c09bfd0: /* original 261b, guest PC 0x0c09bfd0 */
if(!s->budget--) { s->failed_pc=0x0c09bfd0u; return 0; }
r[6]|=r[1];
goto P_0c09bfd2;
P_0c09bfd2: /* original 9370, guest PC 0x0c09bfd2 */
if(!s->budget--) { s->failed_pc=0x0c09bfd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfd4;
P_0c09bfd4: /* original 337c, guest PC 0x0c09bfd4 */
if(!s->budget--) { s->failed_pc=0x0c09bfd4u; return 0; }
r[3]+=r[7];
goto P_0c09bfd6;
P_0c09bfd6: /* original 330c, guest PC 0x0c09bfd6 */
if(!s->budget--) { s->failed_pc=0x0c09bfd6u; return 0; }
r[3]+=r[0];
goto P_0c09bfd8;
P_0c09bfd8: /* original 5233, guest PC 0x0c09bfd8 */
if(!s->budget--) { s->failed_pc=0x0c09bfd8u; return 0; }
r[2]=read(ram,r[3]+12,4);
goto P_0c09bfda;
P_0c09bfda: /* original 2258, guest PC 0x0c09bfda */
if(!s->budget--) { s->failed_pc=0x0c09bfdau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bfdc;
P_0c09bfdc: /* original 8901, guest PC 0x0c09bfdc */
if(!s->budget--) { s->failed_pc=0x0c09bfdcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bfe2; }
goto P_0c09bfde;
P_0c09bfde: /* original e101, guest PC 0x0c09bfde */
if(!s->budget--) { s->failed_pc=0x0c09bfdeu; return 0; }
r[1]=0x00000001u;
goto P_0c09bfe0;
P_0c09bfe0: /* original 261b, guest PC 0x0c09bfe0 */
if(!s->budget--) { s->failed_pc=0x0c09bfe0u; return 0; }
r[6]|=r[1];
goto P_0c09bfe2;
P_0c09bfe2: /* original 9368, guest PC 0x0c09bfe2 */
if(!s->budget--) { s->failed_pc=0x0c09bfe2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bfe4;
P_0c09bfe4: /* original 337c, guest PC 0x0c09bfe4 */
if(!s->budget--) { s->failed_pc=0x0c09bfe4u; return 0; }
r[3]+=r[7];
goto P_0c09bfe6;
P_0c09bfe6: /* original 330c, guest PC 0x0c09bfe6 */
if(!s->budget--) { s->failed_pc=0x0c09bfe6u; return 0; }
r[3]+=r[0];
goto P_0c09bfe8;
P_0c09bfe8: /* original 5234, guest PC 0x0c09bfe8 */
if(!s->budget--) { s->failed_pc=0x0c09bfe8u; return 0; }
r[2]=read(ram,r[3]+16,4);
goto P_0c09bfea;
P_0c09bfea: /* original 2258, guest PC 0x0c09bfea */
if(!s->budget--) { s->failed_pc=0x0c09bfeau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bfec;
P_0c09bfec: /* original 8901, guest PC 0x0c09bfec */
if(!s->budget--) { s->failed_pc=0x0c09bfecu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09bff2; }
goto P_0c09bfee;
P_0c09bfee: /* original 9163, guest PC 0x0c09bfee */
if(!s->budget--) { s->failed_pc=0x0c09bfeeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b8u,2);
goto P_0c09bff0;
P_0c09bff0: /* original 261b, guest PC 0x0c09bff0 */
if(!s->budget--) { s->failed_pc=0x0c09bff0u; return 0; }
r[6]|=r[1];
goto P_0c09bff2;
P_0c09bff2: /* original 9360, guest PC 0x0c09bff2 */
if(!s->budget--) { s->failed_pc=0x0c09bff2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09bff4;
P_0c09bff4: /* original 337c, guest PC 0x0c09bff4 */
if(!s->budget--) { s->failed_pc=0x0c09bff4u; return 0; }
r[3]+=r[7];
goto P_0c09bff6;
P_0c09bff6: /* original 330c, guest PC 0x0c09bff6 */
if(!s->budget--) { s->failed_pc=0x0c09bff6u; return 0; }
r[3]+=r[0];
goto P_0c09bff8;
P_0c09bff8: /* original 5235, guest PC 0x0c09bff8 */
if(!s->budget--) { s->failed_pc=0x0c09bff8u; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c09bffa;
P_0c09bffa: /* original 2258, guest PC 0x0c09bffa */
if(!s->budget--) { s->failed_pc=0x0c09bffau; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09bffc;
P_0c09bffc: /* original 8901, guest PC 0x0c09bffc */
if(!s->budget--) { s->failed_pc=0x0c09bffcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c002; }
goto P_0c09bffe;
P_0c09bffe: /* original 915c, guest PC 0x0c09bffe */
if(!s->budget--) { s->failed_pc=0x0c09bffeu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0bau,2);
goto P_0c09c000;
P_0c09c000: /* original 261b, guest PC 0x0c09c000 */
if(!s->budget--) { s->failed_pc=0x0c09c000u; return 0; }
r[6]|=r[1];
goto P_0c09c002;
P_0c09c002: /* original 9358, guest PC 0x0c09c002 */
if(!s->budget--) { s->failed_pc=0x0c09c002u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09c004;
P_0c09c004: /* original 337c, guest PC 0x0c09c004 */
if(!s->budget--) { s->failed_pc=0x0c09c004u; return 0; }
r[3]+=r[7];
goto P_0c09c006;
P_0c09c006: /* original 330c, guest PC 0x0c09c006 */
if(!s->budget--) { s->failed_pc=0x0c09c006u; return 0; }
r[3]+=r[0];
goto P_0c09c008;
P_0c09c008: /* original 5236, guest PC 0x0c09c008 */
if(!s->budget--) { s->failed_pc=0x0c09c008u; return 0; }
r[2]=read(ram,r[3]+24,4);
goto P_0c09c00a;
P_0c09c00a: /* original 2258, guest PC 0x0c09c00a */
if(!s->budget--) { s->failed_pc=0x0c09c00au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09c00c;
P_0c09c00c: /* original 8901, guest PC 0x0c09c00c */
if(!s->budget--) { s->failed_pc=0x0c09c00cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c012; }
goto P_0c09c00e;
P_0c09c00e: /* original 9155, guest PC 0x0c09c00e */
if(!s->budget--) { s->failed_pc=0x0c09c00eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0bcu,2);
goto P_0c09c010;
P_0c09c010: /* original 261b, guest PC 0x0c09c010 */
if(!s->budget--) { s->failed_pc=0x0c09c010u; return 0; }
r[6]|=r[1];
goto P_0c09c012;
P_0c09c012: /* original 9350, guest PC 0x0c09c012 */
if(!s->budget--) { s->failed_pc=0x0c09c012u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09c014;
P_0c09c014: /* original 337c, guest PC 0x0c09c014 */
if(!s->budget--) { s->failed_pc=0x0c09c014u; return 0; }
r[3]+=r[7];
goto P_0c09c016;
P_0c09c016: /* original 330c, guest PC 0x0c09c016 */
if(!s->budget--) { s->failed_pc=0x0c09c016u; return 0; }
r[3]+=r[0];
goto P_0c09c018;
P_0c09c018: /* original 5237, guest PC 0x0c09c018 */
if(!s->budget--) { s->failed_pc=0x0c09c018u; return 0; }
r[2]=read(ram,r[3]+28,4);
goto P_0c09c01a;
P_0c09c01a: /* original 2258, guest PC 0x0c09c01a */
if(!s->budget--) { s->failed_pc=0x0c09c01au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[5])==0)!=0);
goto P_0c09c01c;
P_0c09c01c: /* original 8901, guest PC 0x0c09c01c */
if(!s->budget--) { s->failed_pc=0x0c09c01cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c022; }
goto P_0c09c01e;
P_0c09c01e: /* original d12b, guest PC 0x0c09c01e */
if(!s->budget--) { s->failed_pc=0x0c09c01eu; return 0; }
r[1]=read(ram,0x0c09c0ccu,4);
goto P_0c09c020;
P_0c09c020: /* original 261b, guest PC 0x0c09c020 */
if(!s->budget--) { s->failed_pc=0x0c09c020u; return 0; }
r[6]|=r[1];
goto P_0c09c022;
P_0c09c022: /* original 9348, guest PC 0x0c09c022 */
if(!s->budget--) { s->failed_pc=0x0c09c022u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09c0b6u,2);
goto P_0c09c024;
P_0c09c024: /* original 337c, guest PC 0x0c09c024 */
if(!s->budget--) { s->failed_pc=0x0c09c024u; return 0; }
r[3]+=r[7];
goto P_0c09c026;
P_0c09c026: /* original 303c, guest PC 0x0c09c026 */
if(!s->budget--) { s->failed_pc=0x0c09c026u; return 0; }
r[0]+=r[3];
goto P_0c09c028;
P_0c09c028: /* original 5208, guest PC 0x0c09c028 */
if(!s->budget--) { s->failed_pc=0x0c09c028u; return 0; }
r[2]=read(ram,r[0]+32,4);
goto P_0c09c02a;
P_0c09c02a: /* original 2528, guest PC 0x0c09c02a */
if(!s->budget--) { s->failed_pc=0x0c09c02au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c09c02c;
P_0c09c02c: /* original 8901, guest PC 0x0c09c02c */
if(!s->budget--) { s->failed_pc=0x0c09c02cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09c032; }
goto P_0c09c02e;
P_0c09c02e: /* original d128, guest PC 0x0c09c02e */
if(!s->budget--) { s->failed_pc=0x0c09c02eu; return 0; }
r[1]=read(ram,0x0c09c0d0u,4);
goto P_0c09c030;
P_0c09c030: /* original 261b, guest PC 0x0c09c030 */
if(!s->budget--) { s->failed_pc=0x0c09c030u; return 0; }
r[6]|=r[1];
goto P_0c09c032;
P_0c09c032: /* original 000b, guest PC 0x0c09c032 */
if(!s->budget--) { s->failed_pc=0x0c09c032u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c09c034: /* original 6063, guest PC 0x0c09c034 */
if(!s->budget--) { s->failed_pc=0x0c09c034u; return 0; }
r[0]=r[6];
return vf3_matrix_family(0x0c09c036u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
