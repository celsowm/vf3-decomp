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
int vf3_away_batch4_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04be44u: goto P_0c04be44;
case 0x0c04be46u: goto P_0c04be46;
case 0x0c04be48u: goto P_0c04be48;
case 0x0c04be4au: goto P_0c04be4a;
case 0x0c04be4cu: goto P_0c04be4c;
case 0x0c04be4eu: goto P_0c04be4e;
case 0x0c04be50u: goto P_0c04be50;
case 0x0c04be52u: goto P_0c04be52;
case 0x0c04be54u: goto P_0c04be54;
case 0x0c04be56u: goto P_0c04be56;
case 0x0c04be58u: goto P_0c04be58;
case 0x0c04be5au: goto P_0c04be5a;
case 0x0c04be5cu: goto P_0c04be5c;
case 0x0c04be5eu: goto P_0c04be5e;
case 0x0c04be60u: goto P_0c04be60;
case 0x0c04be62u: goto P_0c04be62;
case 0x0c04be64u: goto P_0c04be64;
case 0x0c04be66u: goto P_0c04be66;
case 0x0c04be68u: goto P_0c04be68;
case 0x0c04be6au: goto P_0c04be6a;
case 0x0c04be6cu: goto P_0c04be6c;
case 0x0c04be6eu: goto P_0c04be6e;
case 0x0c04be70u: goto P_0c04be70;
case 0x0c04be72u: goto P_0c04be72;
case 0x0c04be74u: goto P_0c04be74;
case 0x0c04be76u: goto P_0c04be76;
case 0x0c04be78u: goto P_0c04be78;
case 0x0c04be7au: goto P_0c04be7a;
case 0x0c04be7cu: goto P_0c04be7c;
case 0x0c04be7eu: goto P_0c04be7e;
case 0x0c04be80u: goto P_0c04be80;
case 0x0c04be82u: goto P_0c04be82;
case 0x0c04be84u: goto P_0c04be84;
case 0x0c04be86u: goto P_0c04be86;
case 0x0c04be88u: goto P_0c04be88;
case 0x0c04be8au: goto P_0c04be8a;
case 0x0c04be8cu: goto P_0c04be8c;
case 0x0c04be8eu: goto P_0c04be8e;
case 0x0c04be90u: goto P_0c04be90;
case 0x0c04be92u: goto P_0c04be92;
case 0x0c04be94u: goto P_0c04be94;
case 0x0c04be96u: goto P_0c04be96;
case 0x0c04be98u: goto P_0c04be98;
case 0x0c04be9au: goto P_0c04be9a;
case 0x0c04be9cu: goto P_0c04be9c;
case 0x0c04be9eu: goto P_0c04be9e;
case 0x0c04bea0u: goto P_0c04bea0;
case 0x0c04bea2u: goto P_0c04bea2;
case 0x0c04bea4u: goto P_0c04bea4;
case 0x0c04bea6u: goto P_0c04bea6;
case 0x0c04bea8u: goto P_0c04bea8;
case 0x0c04beaau: goto P_0c04beaa;
case 0x0c04beacu: goto P_0c04beac;
case 0x0c04beaeu: goto P_0c04beae;
case 0x0c04beb0u: goto P_0c04beb0;
case 0x0c04beb2u: goto P_0c04beb2;
case 0x0c04beb4u: goto P_0c04beb4;
case 0x0c04beb6u: goto P_0c04beb6;
case 0x0c04beb8u: goto P_0c04beb8;
case 0x0c04bebau: goto P_0c04beba;
case 0x0c04bebcu: goto P_0c04bebc;
case 0x0c04bebeu: goto P_0c04bebe;
case 0x0c04bec0u: goto P_0c04bec0;
case 0x0c04bec2u: goto P_0c04bec2;
case 0x0c04bec4u: goto P_0c04bec4;
case 0x0c04bec6u: goto P_0c04bec6;
case 0x0c04bec8u: goto P_0c04bec8;
case 0x0c04becau: goto P_0c04beca;
case 0x0c04beccu: goto P_0c04becc;
case 0x0c04beceu: goto P_0c04bece;
case 0x0c04bed0u: goto P_0c04bed0;
case 0x0c04bed2u: goto P_0c04bed2;
case 0x0c04bed4u: goto P_0c04bed4;
case 0x0c04bed6u: goto P_0c04bed6;
case 0x0c04bed8u: goto P_0c04bed8;
case 0x0c04bedau: goto P_0c04beda;
case 0x0c04bedcu: goto P_0c04bedc;
case 0x0c04bedeu: goto P_0c04bede;
case 0x0c04bee0u: goto P_0c04bee0;
case 0x0c04bee2u: goto P_0c04bee2;
case 0x0c04bee4u: goto P_0c04bee4;
case 0x0c04bee6u: goto P_0c04bee6;
case 0x0c04bee8u: goto P_0c04bee8;
case 0x0c04beeau: goto P_0c04beea;
case 0x0c04beecu: goto P_0c04beec;
case 0x0c04beeeu: goto P_0c04beee;
case 0x0c04bef0u: goto P_0c04bef0;
case 0x0c04bef2u: goto P_0c04bef2;
case 0x0c04bef4u: goto P_0c04bef4;
case 0x0c04bef6u: goto P_0c04bef6;
case 0x0c04bef8u: goto P_0c04bef8;
case 0x0c04befau: goto P_0c04befa;
case 0x0c04befcu: goto P_0c04befc;
case 0x0c04bf28u: goto P_0c04bf28;
case 0x0c04bf2au: goto P_0c04bf2a;
case 0x0c04bf2cu: goto P_0c04bf2c;
case 0x0c04bf2eu: goto P_0c04bf2e;
case 0x0c04bf30u: goto P_0c04bf30;
case 0x0c04bf32u: goto P_0c04bf32;
case 0x0c04bf34u: goto P_0c04bf34;
case 0x0c04bf36u: goto P_0c04bf36;
case 0x0c04bf38u: goto P_0c04bf38;
case 0x0c04bf3au: goto P_0c04bf3a;
case 0x0c04bf3cu: goto P_0c04bf3c;
case 0x0c04bf3eu: goto P_0c04bf3e;
case 0x0c04bf40u: goto P_0c04bf40;
case 0x0c04bf42u: goto P_0c04bf42;
case 0x0c04bf44u: goto P_0c04bf44;
case 0x0c04bf46u: goto P_0c04bf46;
case 0x0c04bf48u: goto P_0c04bf48;
case 0x0c04bf4au: goto P_0c04bf4a;
case 0x0c04bf4cu: goto P_0c04bf4c;
case 0x0c04bf4eu: goto P_0c04bf4e;
case 0x0c04bf50u: goto P_0c04bf50;
case 0x0c04bf52u: goto P_0c04bf52;
case 0x0c04bf54u: goto P_0c04bf54;
case 0x0c04bf56u: goto P_0c04bf56;
case 0x0c04bf58u: goto P_0c04bf58;
case 0x0c04bf5au: goto P_0c04bf5a;
case 0x0c04bf5cu: goto P_0c04bf5c;
case 0x0c04bf5eu: goto P_0c04bf5e;
case 0x0c04bf60u: goto P_0c04bf60;
case 0x0c04bf62u: goto P_0c04bf62;
case 0x0c04bf64u: goto P_0c04bf64;
case 0x0c04bf66u: goto P_0c04bf66;
case 0x0c04bf68u: goto P_0c04bf68;
case 0x0c04bf6au: goto P_0c04bf6a;
case 0x0c04bf6cu: goto P_0c04bf6c;
case 0x0c04bf6eu: goto P_0c04bf6e;
case 0x0c04bf70u: goto P_0c04bf70;
case 0x0c04bf72u: goto P_0c04bf72;
case 0x0c04bf74u: goto P_0c04bf74;
case 0x0c04bf76u: goto P_0c04bf76;
case 0x0c04bf78u: goto P_0c04bf78;
case 0x0c04bf7au: goto P_0c04bf7a;
case 0x0c04bf7cu: goto P_0c04bf7c;
case 0x0c04bf7eu: goto P_0c04bf7e;
case 0x0c04bf80u: goto P_0c04bf80;
case 0x0c04bf82u: goto P_0c04bf82;
case 0x0c04bf84u: goto P_0c04bf84;
case 0x0c04bf86u: goto P_0c04bf86;
case 0x0c04bf88u: goto P_0c04bf88;
case 0x0c04bf8au: goto P_0c04bf8a;
case 0x0c04bf8cu: goto P_0c04bf8c;
case 0x0c04bf8eu: goto P_0c04bf8e;
case 0x0c04bf90u: goto P_0c04bf90;
case 0x0c04bf92u: goto P_0c04bf92;
case 0x0c04bf94u: goto P_0c04bf94;
case 0x0c04bf96u: goto P_0c04bf96;
case 0x0c04bf98u: goto P_0c04bf98;
case 0x0c04bf9au: goto P_0c04bf9a;
case 0x0c04bf9cu: goto P_0c04bf9c;
case 0x0c04bf9eu: goto P_0c04bf9e;
case 0x0c04bfa0u: goto P_0c04bfa0;
case 0x0c04bfa2u: goto P_0c04bfa2;
case 0x0c04bfa4u: goto P_0c04bfa4;
case 0x0c04bfa6u: goto P_0c04bfa6;
case 0x0c04bfa8u: goto P_0c04bfa8;
case 0x0c04bfaau: goto P_0c04bfaa;
case 0x0c04bfacu: goto P_0c04bfac;
case 0x0c04bfaeu: goto P_0c04bfae;
case 0x0c04bfb0u: goto P_0c04bfb0;
case 0x0c04bfb2u: goto P_0c04bfb2;
case 0x0c04bfb4u: goto P_0c04bfb4;
case 0x0c04bfb6u: goto P_0c04bfb6;
case 0x0c04bfb8u: goto P_0c04bfb8;
case 0x0c04bfbau: goto P_0c04bfba;
case 0x0c04bfbcu: goto P_0c04bfbc;
case 0x0c04bfbeu: goto P_0c04bfbe;
case 0x0c04bfc0u: goto P_0c04bfc0;
case 0x0c04bfc2u: goto P_0c04bfc2;
case 0x0c04bfc4u: goto P_0c04bfc4;
case 0x0c04bfc6u: goto P_0c04bfc6;
case 0x0c04bfc8u: goto P_0c04bfc8;
case 0x0c04bfcau: goto P_0c04bfca;
case 0x0c04bfccu: goto P_0c04bfcc;
case 0x0c04bfceu: goto P_0c04bfce;
case 0x0c04bfd0u: goto P_0c04bfd0;
case 0x0c04bfd2u: goto P_0c04bfd2;
case 0x0c04bfd4u: goto P_0c04bfd4;
case 0x0c04bfd6u: goto P_0c04bfd6;
case 0x0c04bfd8u: goto P_0c04bfd8;
case 0x0c04bfdau: goto P_0c04bfda;
case 0x0c04bfdcu: goto P_0c04bfdc;
case 0x0c04bfdeu: goto P_0c04bfde;
case 0x0c04bfe0u: goto P_0c04bfe0;
case 0x0c04bfe2u: goto P_0c04bfe2;
case 0x0c04bfe4u: goto P_0c04bfe4;
case 0x0c04bfe6u: goto P_0c04bfe6;
case 0x0c04c010u: goto P_0c04c010;
case 0x0c04c012u: goto P_0c04c012;
case 0x0c04c014u: goto P_0c04c014;
case 0x0c04c016u: goto P_0c04c016;
case 0x0c04c018u: goto P_0c04c018;
case 0x0c04c01au: goto P_0c04c01a;
case 0x0c04c01cu: goto P_0c04c01c;
case 0x0c04c01eu: goto P_0c04c01e;
case 0x0c04c020u: goto P_0c04c020;
case 0x0c04c022u: goto P_0c04c022;
case 0x0c04c024u: goto P_0c04c024;
case 0x0c04c026u: goto P_0c04c026;
case 0x0c04c028u: goto P_0c04c028;
case 0x0c04c02au: goto P_0c04c02a;
case 0x0c04c02cu: goto P_0c04c02c;
case 0x0c04c02eu: goto P_0c04c02e;
case 0x0c04c030u: goto P_0c04c030;
case 0x0c04c032u: goto P_0c04c032;
case 0x0c04c034u: goto P_0c04c034;
case 0x0c04c036u: goto P_0c04c036;
case 0x0c04c038u: goto P_0c04c038;
case 0x0c04c03au: goto P_0c04c03a;
case 0x0c04c03cu: goto P_0c04c03c;
case 0x0c04c03eu: goto P_0c04c03e;
case 0x0c04c040u: goto P_0c04c040;
case 0x0c04c042u: goto P_0c04c042;
case 0x0c04c044u: goto P_0c04c044;
case 0x0c04c046u: goto P_0c04c046;
case 0x0c04c048u: goto P_0c04c048;
case 0x0c04c04au: goto P_0c04c04a;
case 0x0c04c04cu: goto P_0c04c04c;
case 0x0c04c04eu: goto P_0c04c04e;
case 0x0c04c050u: goto P_0c04c050;
case 0x0c04c052u: goto P_0c04c052;
case 0x0c04c054u: goto P_0c04c054;
case 0x0c04c056u: goto P_0c04c056;
case 0x0c04c058u: goto P_0c04c058;
case 0x0c04c05au: goto P_0c04c05a;
case 0x0c04c05cu: goto P_0c04c05c;
case 0x0c04c05eu: goto P_0c04c05e;
case 0x0c04c060u: goto P_0c04c060;
case 0x0c04c062u: goto P_0c04c062;
case 0x0c04c064u: goto P_0c04c064;
case 0x0c04c066u: goto P_0c04c066;
case 0x0c04c068u: goto P_0c04c068;
case 0x0c04c06au: goto P_0c04c06a;
case 0x0c04c06cu: goto P_0c04c06c;
case 0x0c04c06eu: goto P_0c04c06e;
case 0x0c04c070u: goto P_0c04c070;
case 0x0c04c072u: goto P_0c04c072;
case 0x0c04c074u: goto P_0c04c074;
case 0x0c04c076u: goto P_0c04c076;
case 0x0c04c078u: goto P_0c04c078;
case 0x0c04c07au: goto P_0c04c07a;
case 0x0c04c07cu: goto P_0c04c07c;
case 0x0c04c07eu: goto P_0c04c07e;
case 0x0c04c080u: goto P_0c04c080;
case 0x0c04c082u: goto P_0c04c082;
case 0x0c04c084u: goto P_0c04c084;
case 0x0c04c086u: goto P_0c04c086;
case 0x0c04c088u: goto P_0c04c088;
case 0x0c04c08au: goto P_0c04c08a;
case 0x0c04c08cu: goto P_0c04c08c;
case 0x0c04c08eu: goto P_0c04c08e;
case 0x0c04c090u: goto P_0c04c090;
case 0x0c04c092u: goto P_0c04c092;
case 0x0c04c094u: goto P_0c04c094;
case 0x0c04c096u: goto P_0c04c096;
case 0x0c04c098u: goto P_0c04c098;
case 0x0c04c09au: goto P_0c04c09a;
case 0x0c04c09cu: goto P_0c04c09c;
case 0x0c04c09eu: goto P_0c04c09e;
case 0x0c04c0a0u: goto P_0c04c0a0;
case 0x0c04c0a2u: goto P_0c04c0a2;
case 0x0c04c0a4u: goto P_0c04c0a4;
case 0x0c04c0a6u: goto P_0c04c0a6;
case 0x0c04c0a8u: goto P_0c04c0a8;
case 0x0c04c0aau: goto P_0c04c0aa;
case 0x0c04c0acu: goto P_0c04c0ac;
case 0x0c04c0aeu: goto P_0c04c0ae;
case 0x0c04c0b0u: goto P_0c04c0b0;
case 0x0c04c0b2u: goto P_0c04c0b2;
case 0x0c04c0b4u: goto P_0c04c0b4;
case 0x0c04c0b6u: goto P_0c04c0b6;
case 0x0c04c0b8u: goto P_0c04c0b8;
case 0x0c04c0bau: goto P_0c04c0ba;
case 0x0c04c0bcu: goto P_0c04c0bc;
case 0x0c04c0beu: goto P_0c04c0be;
case 0x0c04c0c0u: goto P_0c04c0c0;
case 0x0c04c0c2u: goto P_0c04c0c2;
case 0x0c04c0c4u: goto P_0c04c0c4;
case 0x0c04c0c6u: goto P_0c04c0c6;
case 0x0c04c0c8u: goto P_0c04c0c8;
case 0x0c04c0cau: goto P_0c04c0ca;
case 0x0c04c0ccu: goto P_0c04c0cc;
case 0x0c04c0ceu: goto P_0c04c0ce;
case 0x0c04c0d0u: goto P_0c04c0d0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04be44: /* original 2fe6, guest PC 0x0c04be44 */
if(!s->budget--) { s->failed_pc=0x0c04be44u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be46;
P_0c04be46: /* original 6e43, guest PC 0x0c04be46 */
if(!s->budget--) { s->failed_pc=0x0c04be46u; return 0; }
r[14]=r[4];
goto P_0c04be48;
P_0c04be48: /* original 2fd6, guest PC 0x0c04be48 */
if(!s->budget--) { s->failed_pc=0x0c04be48u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be4a;
P_0c04be4a: /* original 2fc6, guest PC 0x0c04be4a */
if(!s->budget--) { s->failed_pc=0x0c04be4au; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be4c;
P_0c04be4c: /* original 2fb6, guest PC 0x0c04be4c */
if(!s->budget--) { s->failed_pc=0x0c04be4cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be4e;
P_0c04be4e: /* original 2fa6, guest PC 0x0c04be4e */
if(!s->budget--) { s->failed_pc=0x0c04be4eu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be50;
P_0c04be50: /* original 2f96, guest PC 0x0c04be50 */
if(!s->budget--) { s->failed_pc=0x0c04be50u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be52;
P_0c04be52: /* original 6953, guest PC 0x0c04be52 */
if(!s->budget--) { s->failed_pc=0x0c04be52u; return 0; }
r[9]=r[5];
goto P_0c04be54;
P_0c04be54: /* original 2f86, guest PC 0x0c04be54 */
if(!s->budget--) { s->failed_pc=0x0c04be54u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be56;
P_0c04be56: /* original 4f22, guest PC 0x0c04be56 */
if(!s->budget--) { s->failed_pc=0x0c04be56u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04be58;
P_0c04be58: /* original d32a, guest PC 0x0c04be58 */
if(!s->budget--) { s->failed_pc=0x0c04be58u; return 0; }
r[3]=read(ram,0x0c04bf04u,4);
goto P_0c04be5a;
P_0c04be5a: /* original da2b, guest PC 0x0c04be5a */
if(!s->budget--) { s->failed_pc=0x0c04be5au; return 0; }
r[10]=read(ram,0x0c04bf08u,4);
goto P_0c04be5c;
P_0c04be5c: /* original 4f12, guest PC 0x0c04be5c */
if(!s->budget--) { s->failed_pc=0x0c04be5cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04be5e;
P_0c04be5e: /* original 6d32, guest PC 0x0c04be5e */
if(!s->budget--) { s->failed_pc=0x0c04be5eu; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c04be60;
P_0c04be60: /* original 7ffc, guest PC 0x0c04be60 */
if(!s->budget--) { s->failed_pc=0x0c04be60u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04be62;
P_0c04be62: /* original 2f56, guest PC 0x0c04be62 */
if(!s->budget--) { s->failed_pc=0x0c04be62u; return 0; }
tmp=r[5]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be64;
P_0c04be64: /* original 2fe6, guest PC 0x0c04be64 */
if(!s->budget--) { s->failed_pc=0x0c04be64u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be66;
P_0c04be66: /* original d229, guest PC 0x0c04be66 */
if(!s->budget--) { s->failed_pc=0x0c04be66u; return 0; }
r[2]=read(ram,0x0c04bf0cu,4);
goto P_0c04be68;
P_0c04be68: /* original 4a0b, guest PC 0x0c04be68 */
if(!s->budget--) { s->failed_pc=0x0c04be68u; return 0; }
target=r[10];
r[16]=code_base|0x0c04be6cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04be6cu) { target=s->pc; goto dispatch; }
goto P_0c04be6c;
P_0c04be6a: /* original 2f26, guest PC 0x0c04be6a */
if(!s->budget--) { s->failed_pc=0x0c04be6au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be6c;
P_0c04be6c: /* original 9b47, guest PC 0x0c04be6c */
if(!s->budget--) { s->failed_pc=0x0c04be6cu; return 0; }
r[11]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04befeu,2);
goto P_0c04be6e;
P_0c04be6e: /* original 7f0c, guest PC 0x0c04be6e */
if(!s->budget--) { s->failed_pc=0x0c04be6eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c04be70;
P_0c04be70: /* original 0eb7, guest PC 0x0c04be70 */
if(!s->budget--) { s->failed_pc=0x0c04be70u; return 0; }
r[19]=r[14]*r[11];
goto P_0c04be72;
P_0c04be72: /* original 0b1a, guest PC 0x0c04be72 */
if(!s->budget--) { s->failed_pc=0x0c04be72u; return 0; }
r[11]=r[19];
goto P_0c04be74;
P_0c04be74: /* original 2fb2, guest PC 0x0c04be74 */
if(!s->budget--) { s->failed_pc=0x0c04be74u; return 0; }
write(ram,r[15],r[11],4);
goto P_0c04be76;
P_0c04be76: /* original d326, guest PC 0x0c04be76 */
if(!s->budget--) { s->failed_pc=0x0c04be76u; return 0; }
r[3]=read(ram,0x0c04bf10u,4);
goto P_0c04be78;
P_0c04be78: /* original d826, guest PC 0x0c04be78 */
if(!s->budget--) { s->failed_pc=0x0c04be78u; return 0; }
r[8]=read(ram,0x0c04bf14u,4);
goto P_0c04be7a;
P_0c04be7a: /* original 3b3c, guest PC 0x0c04be7a */
if(!s->budget--) { s->failed_pc=0x0c04be7au; return 0; }
r[11]+=r[3];
goto P_0c04be7c;
P_0c04be7c: /* original 2fd6, guest PC 0x0c04be7c */
if(!s->budget--) { s->failed_pc=0x0c04be7cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be7e;
P_0c04be7e: /* original 4a0b, guest PC 0x0c04be7e */
if(!s->budget--) { s->failed_pc=0x0c04be7eu; return 0; }
target=r[10];
r[16]=code_base|0x0c04be82u;
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04be82u) { target=s->pc; goto dispatch; }
goto P_0c04be82;
P_0c04be80: /* original 2f86, guest PC 0x0c04be80 */
if(!s->budget--) { s->failed_pc=0x0c04be80u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04be82;
P_0c04be82: /* original d225, guest PC 0x0c04be82 */
if(!s->budget--) { s->failed_pc=0x0c04be82u; return 0; }
r[2]=read(ram,0x0c04bf18u,4);
goto P_0c04be84;
P_0c04be84: /* original 6593, guest PC 0x0c04be84 */
if(!s->budget--) { s->failed_pc=0x0c04be84u; return 0; }
r[5]=r[9];
goto P_0c04be86;
P_0c04be86: /* original 7f08, guest PC 0x0c04be86 */
if(!s->budget--) { s->failed_pc=0x0c04be86u; return 0; }
r[15]+=0x00000008u;
goto P_0c04be88;
P_0c04be88: /* original 420b, guest PC 0x0c04be88 */
if(!s->budget--) { s->failed_pc=0x0c04be88u; return 0; }
target=r[2];
r[16]=code_base|0x0c04be8cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04be8cu) { target=s->pc; goto dispatch; }
goto P_0c04be8c;
P_0c04be8a: /* original 64e3, guest PC 0x0c04be8a */
if(!s->budget--) { s->failed_pc=0x0c04be8au; return 0; }
r[4]=r[14];
goto P_0c04be8c;
P_0c04be8c: /* original 6c03, guest PC 0x0c04be8c */
if(!s->budget--) { s->failed_pc=0x0c04be8cu; return 0; }
r[12]=r[0];
goto P_0c04be8e;
P_0c04be8e: /* original 2cc8, guest PC 0x0c04be8e */
if(!s->budget--) { s->failed_pc=0x0c04be8eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04be90;
P_0c04be90: /* original 8909, guest PC 0x0c04be90 */
if(!s->budget--) { s->failed_pc=0x0c04be90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bea6; }
goto P_0c04be92;
P_0c04be92: /* original 53bd, guest PC 0x0c04be92 */
if(!s->budget--) { s->failed_pc=0x0c04be92u; return 0; }
r[3]=read(ram,r[11]+52,4);
goto P_0c04be94;
P_0c04be94: /* original 2dd8, guest PC 0x0c04be94 */
if(!s->budget--) { s->failed_pc=0x0c04be94u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c04be96;
P_0c04be96: /* original 7301, guest PC 0x0c04be96 */
if(!s->budget--) { s->failed_pc=0x0c04be96u; return 0; }
r[3]+=0x00000001u;
goto P_0c04be98;
P_0c04be98: /* original 1b3d, guest PC 0x0c04be98 */
if(!s->budget--) { s->failed_pc=0x0c04be98u; return 0; }
write(ram,r[11]+52,r[3],4);
goto P_0c04be9a;
P_0c04be9a: /* original 8fef, guest PC 0x0c04be9a */
if(!s->budget--) { s->failed_pc=0x0c04be9au; return 0; }
cond=r[17]&1u;
r[13]+=0xffffffffu;
if(!cond) { goto P_0c04be7c; }
goto P_0c04be9e;
P_0c04be9c: /* original 7dff, guest PC 0x0c04be9c */
if(!s->budget--) { s->failed_pc=0x0c04be9cu; return 0; }
r[13]+=0xffffffffu;
goto P_0c04be9e;
P_0c04be9e: /* original d119, guest PC 0x0c04be9e */
if(!s->budget--) { s->failed_pc=0x0c04be9eu; return 0; }
r[1]=read(ram,0x0c04bf04u,4);
goto P_0c04bea0;
P_0c04bea0: /* original 6012, guest PC 0x0c04bea0 */
if(!s->budget--) { s->failed_pc=0x0c04bea0u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04bea2;
P_0c04bea2: /* original 88ff, guest PC 0x0c04bea2 */
if(!s->budget--) { s->failed_pc=0x0c04bea2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04bea4;
P_0c04bea4: /* original 89ea, guest PC 0x0c04bea4 */
if(!s->budget--) { s->failed_pc=0x0c04bea4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04be7c; }
goto P_0c04bea6;
P_0c04bea6: /* original 6df2, guest PC 0x0c04bea6 */
if(!s->budget--) { s->failed_pc=0x0c04bea6u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c04bea8;
P_0c04bea8: /* original 62e3, guest PC 0x0c04bea8 */
if(!s->budget--) { s->failed_pc=0x0c04bea8u; return 0; }
r[2]=r[14];
goto P_0c04beaa;
P_0c04beaa: /* original d319, guest PC 0x0c04beaa */
if(!s->budget--) { s->failed_pc=0x0c04beaau; return 0; }
r[3]=read(ram,0x0c04bf10u,4);
goto P_0c04beac;
P_0c04beac: /* original 4208, guest PC 0x0c04beac */
if(!s->budget--) { s->failed_pc=0x0c04beacu; return 0; }
r[2]<<=2;
goto P_0c04beae;
P_0c04beae: /* original 4208, guest PC 0x0c04beae */
if(!s->budget--) { s->failed_pc=0x0c04beaeu; return 0; }
r[2]<<=2;
goto P_0c04beb0;
P_0c04beb0: /* original d11a, guest PC 0x0c04beb0 */
if(!s->budget--) { s->failed_pc=0x0c04beb0u; return 0; }
r[1]=read(ram,0x0c04bf1cu,4);
goto P_0c04beb2;
P_0c04beb2: /* original 3d3c, guest PC 0x0c04beb2 */
if(!s->budget--) { s->failed_pc=0x0c04beb2u; return 0; }
r[13]+=r[3];
goto P_0c04beb4;
P_0c04beb4: /* original 4208, guest PC 0x0c04beb4 */
if(!s->budget--) { s->failed_pc=0x0c04beb4u; return 0; }
r[2]<<=2;
goto P_0c04beb6;
P_0c04beb6: /* original 4200, guest PC 0x0c04beb6 */
if(!s->budget--) { s->failed_pc=0x0c04beb6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04beb8;
P_0c04beb8: /* original 321c, guest PC 0x0c04beb8 */
if(!s->budget--) { s->failed_pc=0x0c04beb8u; return 0; }
r[2]+=r[1];
goto P_0c04beba;
P_0c04beba: /* original 2f22, guest PC 0x0c04beba */
if(!s->budget--) { s->failed_pc=0x0c04bebau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04bebc;
P_0c04bebc: /* original 56dc, guest PC 0x0c04bebc */
if(!s->budget--) { s->failed_pc=0x0c04bebcu; return 0; }
r[6]=read(ram,r[13]+48,4);
goto P_0c04bebe;
P_0c04bebe: /* original 57dd, guest PC 0x0c04bebe */
if(!s->budget--) { s->failed_pc=0x0c04bebeu; return 0; }
r[7]=read(ram,r[13]+52,4);
goto P_0c04bec0;
P_0c04bec0: /* original 7601, guest PC 0x0c04bec0 */
if(!s->budget--) { s->failed_pc=0x0c04bec0u; return 0; }
r[6]+=0x00000001u;
goto P_0c04bec2;
P_0c04bec2: /* original 1d6c, guest PC 0x0c04bec2 */
if(!s->budget--) { s->failed_pc=0x0c04bec2u; return 0; }
write(ram,r[13]+48,r[6],4);
goto P_0c04bec4;
P_0c04bec4: /* original 76ff, guest PC 0x0c04bec4 */
if(!s->budget--) { s->failed_pc=0x0c04bec4u; return 0; }
r[6]+=0xffffffffu;
goto P_0c04bec6;
P_0c04bec6: /* original 65f2, guest PC 0x0c04bec6 */
if(!s->budget--) { s->failed_pc=0x0c04bec6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04bec8;
P_0c04bec8: /* original d315, guest PC 0x0c04bec8 */
if(!s->budget--) { s->failed_pc=0x0c04bec8u; return 0; }
r[3]=read(ram,0x0c04bf20u,4);
goto P_0c04beca;
P_0c04beca: /* original 5552, guest PC 0x0c04beca */
if(!s->budget--) { s->failed_pc=0x0c04becau; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04becc;
P_0c04becc: /* original 430b, guest PC 0x0c04becc */
if(!s->budget--) { s->failed_pc=0x0c04beccu; return 0; }
target=r[3];
r[16]=code_base|0x0c04bed0u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bed0u) { target=s->pc; goto dispatch; }
goto P_0c04bed0;
P_0c04bece: /* original 64e3, guest PC 0x0c04bece */
if(!s->budget--) { s->failed_pc=0x0c04beceu; return 0; }
r[4]=r[14];
goto P_0c04bed0;
P_0c04bed0: /* original 9116, guest PC 0x0c04bed0 */
if(!s->budget--) { s->failed_pc=0x0c04bed0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bf00u,2);
goto P_0c04bed2;
P_0c04bed2: /* original 60c3, guest PC 0x0c04bed2 */
if(!s->budget--) { s->failed_pc=0x0c04bed2u; return 0; }
r[0]=r[12];
goto P_0c04bed4;
P_0c04bed4: /* original 3010, guest PC 0x0c04bed4 */
if(!s->budget--) { s->failed_pc=0x0c04bed4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04bed6;
P_0c04bed6: /* original 8903, guest PC 0x0c04bed6 */
if(!s->budget--) { s->failed_pc=0x0c04bed6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bee0; }
goto P_0c04bed8;
P_0c04bed8: /* original 8800, guest PC 0x0c04bed8 */
if(!s->budget--) { s->failed_pc=0x0c04bed8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04beda;
P_0c04beda: /* original 8b04, guest PC 0x0c04beda */
if(!s->budget--) { s->failed_pc=0x0c04bedau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bee6; }
goto P_0c04bedc;
P_0c04bedc: /* original a004, guest PC 0x0c04bedc */
if(!s->budget--) { s->failed_pc=0x0c04bedcu; return 0; }
r[0]=0x00000000u;
goto P_0c04bee8;
P_0c04bede: /* original e000, guest PC 0x0c04bede */
if(!s->budget--) { s->failed_pc=0x0c04bedeu; return 0; }
r[0]=0x00000000u;
goto P_0c04bee0;
P_0c04bee0: /* original 900e, guest PC 0x0c04bee0 */
if(!s->budget--) { s->failed_pc=0x0c04bee0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bf00u,2);
goto P_0c04bee2;
P_0c04bee2: /* original a001, guest PC 0x0c04bee2 */
if(!s->budget--) { s->failed_pc=0x0c04bee2u; return 0; }
goto P_0c04bee8;
P_0c04bee4: /* original 0009, guest PC 0x0c04bee4 */
if(!s->budget--) { s->failed_pc=0x0c04bee4u; return 0; }
goto P_0c04bee6;
P_0c04bee6: /* original d00f, guest PC 0x0c04bee6 */
if(!s->budget--) { s->failed_pc=0x0c04bee6u; return 0; }
r[0]=read(ram,0x0c04bf24u,4);
goto P_0c04bee8;
P_0c04bee8: /* original 7f04, guest PC 0x0c04bee8 */
if(!s->budget--) { s->failed_pc=0x0c04bee8u; return 0; }
r[15]+=0x00000004u;
goto P_0c04beea;
P_0c04beea: /* original 4f16, guest PC 0x0c04beea */
if(!s->budget--) { s->failed_pc=0x0c04beeau; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04beec;
P_0c04beec: /* original 4f26, guest PC 0x0c04beec */
if(!s->budget--) { s->failed_pc=0x0c04beecu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04beee;
P_0c04beee: /* original 68f6, guest PC 0x0c04beee */
if(!s->budget--) { s->failed_pc=0x0c04beeeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04bef0;
P_0c04bef0: /* original 69f6, guest PC 0x0c04bef0 */
if(!s->budget--) { s->failed_pc=0x0c04bef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04bef2;
P_0c04bef2: /* original 6af6, guest PC 0x0c04bef2 */
if(!s->budget--) { s->failed_pc=0x0c04bef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04bef4;
P_0c04bef4: /* original 6bf6, guest PC 0x0c04bef4 */
if(!s->budget--) { s->failed_pc=0x0c04bef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04bef6;
P_0c04bef6: /* original 6cf6, guest PC 0x0c04bef6 */
if(!s->budget--) { s->failed_pc=0x0c04bef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bef8;
P_0c04bef8: /* original 6df6, guest PC 0x0c04bef8 */
if(!s->budget--) { s->failed_pc=0x0c04bef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04befa;
P_0c04befa: /* original 000b, guest PC 0x0c04befa */
if(!s->budget--) { s->failed_pc=0x0c04befau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04befc: /* original 6ef6, guest PC 0x0c04befc */
if(!s->budget--) { s->failed_pc=0x0c04befcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04befeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04befeu; return 0; } return 1;
P_0c04bf28: /* original 2fe6, guest PC 0x0c04bf28 */
if(!s->budget--) { s->failed_pc=0x0c04bf28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf2a;
P_0c04bf2a: /* original 6e43, guest PC 0x0c04bf2a */
if(!s->budget--) { s->failed_pc=0x0c04bf2au; return 0; }
r[14]=r[4];
goto P_0c04bf2c;
P_0c04bf2c: /* original 2fd6, guest PC 0x0c04bf2c */
if(!s->budget--) { s->failed_pc=0x0c04bf2cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf2e;
P_0c04bf2e: /* original 2fc6, guest PC 0x0c04bf2e */
if(!s->budget--) { s->failed_pc=0x0c04bf2eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf30;
P_0c04bf30: /* original 2fb6, guest PC 0x0c04bf30 */
if(!s->budget--) { s->failed_pc=0x0c04bf30u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf32;
P_0c04bf32: /* original 2fa6, guest PC 0x0c04bf32 */
if(!s->budget--) { s->failed_pc=0x0c04bf32u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf34;
P_0c04bf34: /* original 2f96, guest PC 0x0c04bf34 */
if(!s->budget--) { s->failed_pc=0x0c04bf34u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf36;
P_0c04bf36: /* original 6963, guest PC 0x0c04bf36 */
if(!s->budget--) { s->failed_pc=0x0c04bf36u; return 0; }
r[9]=r[6];
goto P_0c04bf38;
P_0c04bf38: /* original 2f86, guest PC 0x0c04bf38 */
if(!s->budget--) { s->failed_pc=0x0c04bf38u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf3a;
P_0c04bf3a: /* original 6853, guest PC 0x0c04bf3a */
if(!s->budget--) { s->failed_pc=0x0c04bf3au; return 0; }
r[8]=r[5];
goto P_0c04bf3c;
P_0c04bf3c: /* original 4f22, guest PC 0x0c04bf3c */
if(!s->budget--) { s->failed_pc=0x0c04bf3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04bf3e;
P_0c04bf3e: /* original d32b, guest PC 0x0c04bf3e */
if(!s->budget--) { s->failed_pc=0x0c04bf3eu; return 0; }
r[3]=read(ram,0x0c04bfecu,4);
goto P_0c04bf40;
P_0c04bf40: /* original da2b, guest PC 0x0c04bf40 */
if(!s->budget--) { s->failed_pc=0x0c04bf40u; return 0; }
r[10]=read(ram,0x0c04bff0u,4);
goto P_0c04bf42;
P_0c04bf42: /* original 4f12, guest PC 0x0c04bf42 */
if(!s->budget--) { s->failed_pc=0x0c04bf42u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04bf44;
P_0c04bf44: /* original 6c32, guest PC 0x0c04bf44 */
if(!s->budget--) { s->failed_pc=0x0c04bf44u; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c04bf46;
P_0c04bf46: /* original 7ffc, guest PC 0x0c04bf46 */
if(!s->budget--) { s->failed_pc=0x0c04bf46u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04bf48;
P_0c04bf48: /* original 2f66, guest PC 0x0c04bf48 */
if(!s->budget--) { s->failed_pc=0x0c04bf48u; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf4a;
P_0c04bf4a: /* original 2f86, guest PC 0x0c04bf4a */
if(!s->budget--) { s->failed_pc=0x0c04bf4au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf4c;
P_0c04bf4c: /* original 2fe6, guest PC 0x0c04bf4c */
if(!s->budget--) { s->failed_pc=0x0c04bf4cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf4e;
P_0c04bf4e: /* original d229, guest PC 0x0c04bf4e */
if(!s->budget--) { s->failed_pc=0x0c04bf4eu; return 0; }
r[2]=read(ram,0x0c04bff4u,4);
goto P_0c04bf50;
P_0c04bf50: /* original 4a0b, guest PC 0x0c04bf50 */
if(!s->budget--) { s->failed_pc=0x0c04bf50u; return 0; }
target=r[10];
r[16]=code_base|0x0c04bf54u;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bf54u) { target=s->pc; goto dispatch; }
goto P_0c04bf54;
P_0c04bf52: /* original 2f26, guest PC 0x0c04bf52 */
if(!s->budget--) { s->failed_pc=0x0c04bf52u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf54;
P_0c04bf54: /* original 9d48, guest PC 0x0c04bf54 */
if(!s->budget--) { s->failed_pc=0x0c04bf54u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bfe8u,2);
goto P_0c04bf56;
P_0c04bf56: /* original 7f10, guest PC 0x0c04bf56 */
if(!s->budget--) { s->failed_pc=0x0c04bf56u; return 0; }
r[15]+=0x00000010u;
goto P_0c04bf58;
P_0c04bf58: /* original 0ed7, guest PC 0x0c04bf58 */
if(!s->budget--) { s->failed_pc=0x0c04bf58u; return 0; }
r[19]=r[14]*r[13];
goto P_0c04bf5a;
P_0c04bf5a: /* original 0d1a, guest PC 0x0c04bf5a */
if(!s->budget--) { s->failed_pc=0x0c04bf5au; return 0; }
r[13]=r[19];
goto P_0c04bf5c;
P_0c04bf5c: /* original 2fd2, guest PC 0x0c04bf5c */
if(!s->budget--) { s->failed_pc=0x0c04bf5cu; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04bf5e;
P_0c04bf5e: /* original d326, guest PC 0x0c04bf5e */
if(!s->budget--) { s->failed_pc=0x0c04bf5eu; return 0; }
r[3]=read(ram,0x0c04bff8u,4);
goto P_0c04bf60;
P_0c04bf60: /* original 3d3c, guest PC 0x0c04bf60 */
if(!s->budget--) { s->failed_pc=0x0c04bf60u; return 0; }
r[13]+=r[3];
goto P_0c04bf62;
P_0c04bf62: /* original 2fc6, guest PC 0x0c04bf62 */
if(!s->budget--) { s->failed_pc=0x0c04bf62u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf64;
P_0c04bf64: /* original d225, guest PC 0x0c04bf64 */
if(!s->budget--) { s->failed_pc=0x0c04bf64u; return 0; }
r[2]=read(ram,0x0c04bffcu,4);
goto P_0c04bf66;
P_0c04bf66: /* original 4a0b, guest PC 0x0c04bf66 */
if(!s->budget--) { s->failed_pc=0x0c04bf66u; return 0; }
target=r[10];
r[16]=code_base|0x0c04bf6au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bf6au) { target=s->pc; goto dispatch; }
goto P_0c04bf6a;
P_0c04bf68: /* original 2f26, guest PC 0x0c04bf68 */
if(!s->budget--) { s->failed_pc=0x0c04bf68u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04bf6a;
P_0c04bf6a: /* original d325, guest PC 0x0c04bf6a */
if(!s->budget--) { s->failed_pc=0x0c04bf6au; return 0; }
r[3]=read(ram,0x0c04c000u,4);
goto P_0c04bf6c;
P_0c04bf6c: /* original 6583, guest PC 0x0c04bf6c */
if(!s->budget--) { s->failed_pc=0x0c04bf6cu; return 0; }
r[5]=r[8];
goto P_0c04bf6e;
P_0c04bf6e: /* original 7f08, guest PC 0x0c04bf6e */
if(!s->budget--) { s->failed_pc=0x0c04bf6eu; return 0; }
r[15]+=0x00000008u;
goto P_0c04bf70;
P_0c04bf70: /* original 6693, guest PC 0x0c04bf70 */
if(!s->budget--) { s->failed_pc=0x0c04bf70u; return 0; }
r[6]=r[9];
goto P_0c04bf72;
P_0c04bf72: /* original 430b, guest PC 0x0c04bf72 */
if(!s->budget--) { s->failed_pc=0x0c04bf72u; return 0; }
target=r[3];
r[16]=code_base|0x0c04bf76u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bf76u) { target=s->pc; goto dispatch; }
goto P_0c04bf76;
P_0c04bf74: /* original 64e3, guest PC 0x0c04bf74 */
if(!s->budget--) { s->failed_pc=0x0c04bf74u; return 0; }
r[4]=r[14];
goto P_0c04bf76;
P_0c04bf76: /* original 6b03, guest PC 0x0c04bf76 */
if(!s->budget--) { s->failed_pc=0x0c04bf76u; return 0; }
r[11]=r[0];
goto P_0c04bf78;
P_0c04bf78: /* original 2bb8, guest PC 0x0c04bf78 */
if(!s->budget--) { s->failed_pc=0x0c04bf78u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[11])==0)!=0);
goto P_0c04bf7a;
P_0c04bf7a: /* original 8909, guest PC 0x0c04bf7a */
if(!s->budget--) { s->failed_pc=0x0c04bf7au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bf90; }
goto P_0c04bf7c;
P_0c04bf7c: /* original 52dd, guest PC 0x0c04bf7c */
if(!s->budget--) { s->failed_pc=0x0c04bf7cu; return 0; }
r[2]=read(ram,r[13]+52,4);
goto P_0c04bf7e;
P_0c04bf7e: /* original 2cc8, guest PC 0x0c04bf7e */
if(!s->budget--) { s->failed_pc=0x0c04bf7eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04bf80;
P_0c04bf80: /* original 7201, guest PC 0x0c04bf80 */
if(!s->budget--) { s->failed_pc=0x0c04bf80u; return 0; }
r[2]+=0x00000001u;
goto P_0c04bf82;
P_0c04bf82: /* original 1d2d, guest PC 0x0c04bf82 */
if(!s->budget--) { s->failed_pc=0x0c04bf82u; return 0; }
write(ram,r[13]+52,r[2],4);
goto P_0c04bf84;
P_0c04bf84: /* original 8fed, guest PC 0x0c04bf84 */
if(!s->budget--) { s->failed_pc=0x0c04bf84u; return 0; }
cond=r[17]&1u;
r[12]+=0xffffffffu;
if(!cond) { goto P_0c04bf62; }
goto P_0c04bf88;
P_0c04bf86: /* original 7cff, guest PC 0x0c04bf86 */
if(!s->budget--) { s->failed_pc=0x0c04bf86u; return 0; }
r[12]+=0xffffffffu;
goto P_0c04bf88;
P_0c04bf88: /* original d118, guest PC 0x0c04bf88 */
if(!s->budget--) { s->failed_pc=0x0c04bf88u; return 0; }
r[1]=read(ram,0x0c04bfecu,4);
goto P_0c04bf8a;
P_0c04bf8a: /* original 6012, guest PC 0x0c04bf8a */
if(!s->budget--) { s->failed_pc=0x0c04bf8au; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04bf8c;
P_0c04bf8c: /* original 88ff, guest PC 0x0c04bf8c */
if(!s->budget--) { s->failed_pc=0x0c04bf8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04bf8e;
P_0c04bf8e: /* original 89e8, guest PC 0x0c04bf8e */
if(!s->budget--) { s->failed_pc=0x0c04bf8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bf62; }
goto P_0c04bf90;
P_0c04bf90: /* original 6df2, guest PC 0x0c04bf90 */
if(!s->budget--) { s->failed_pc=0x0c04bf90u; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c04bf92;
P_0c04bf92: /* original 62e3, guest PC 0x0c04bf92 */
if(!s->budget--) { s->failed_pc=0x0c04bf92u; return 0; }
r[2]=r[14];
goto P_0c04bf94;
P_0c04bf94: /* original d318, guest PC 0x0c04bf94 */
if(!s->budget--) { s->failed_pc=0x0c04bf94u; return 0; }
r[3]=read(ram,0x0c04bff8u,4);
goto P_0c04bf96;
P_0c04bf96: /* original 4208, guest PC 0x0c04bf96 */
if(!s->budget--) { s->failed_pc=0x0c04bf96u; return 0; }
r[2]<<=2;
goto P_0c04bf98;
P_0c04bf98: /* original 4208, guest PC 0x0c04bf98 */
if(!s->budget--) { s->failed_pc=0x0c04bf98u; return 0; }
r[2]<<=2;
goto P_0c04bf9a;
P_0c04bf9a: /* original d11a, guest PC 0x0c04bf9a */
if(!s->budget--) { s->failed_pc=0x0c04bf9au; return 0; }
r[1]=read(ram,0x0c04c004u,4);
goto P_0c04bf9c;
P_0c04bf9c: /* original 3d3c, guest PC 0x0c04bf9c */
if(!s->budget--) { s->failed_pc=0x0c04bf9cu; return 0; }
r[13]+=r[3];
goto P_0c04bf9e;
P_0c04bf9e: /* original 4208, guest PC 0x0c04bf9e */
if(!s->budget--) { s->failed_pc=0x0c04bf9eu; return 0; }
r[2]<<=2;
goto P_0c04bfa0;
P_0c04bfa0: /* original 4200, guest PC 0x0c04bfa0 */
if(!s->budget--) { s->failed_pc=0x0c04bfa0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04bfa2;
P_0c04bfa2: /* original 321c, guest PC 0x0c04bfa2 */
if(!s->budget--) { s->failed_pc=0x0c04bfa2u; return 0; }
r[2]+=r[1];
goto P_0c04bfa4;
P_0c04bfa4: /* original 2f22, guest PC 0x0c04bfa4 */
if(!s->budget--) { s->failed_pc=0x0c04bfa4u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04bfa6;
P_0c04bfa6: /* original 56dc, guest PC 0x0c04bfa6 */
if(!s->budget--) { s->failed_pc=0x0c04bfa6u; return 0; }
r[6]=read(ram,r[13]+48,4);
goto P_0c04bfa8;
P_0c04bfa8: /* original 57dd, guest PC 0x0c04bfa8 */
if(!s->budget--) { s->failed_pc=0x0c04bfa8u; return 0; }
r[7]=read(ram,r[13]+52,4);
goto P_0c04bfaa;
P_0c04bfaa: /* original 7601, guest PC 0x0c04bfaa */
if(!s->budget--) { s->failed_pc=0x0c04bfaau; return 0; }
r[6]+=0x00000001u;
goto P_0c04bfac;
P_0c04bfac: /* original 1d6c, guest PC 0x0c04bfac */
if(!s->budget--) { s->failed_pc=0x0c04bfacu; return 0; }
write(ram,r[13]+48,r[6],4);
goto P_0c04bfae;
P_0c04bfae: /* original 76ff, guest PC 0x0c04bfae */
if(!s->budget--) { s->failed_pc=0x0c04bfaeu; return 0; }
r[6]+=0xffffffffu;
goto P_0c04bfb0;
P_0c04bfb0: /* original 65f2, guest PC 0x0c04bfb0 */
if(!s->budget--) { s->failed_pc=0x0c04bfb0u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04bfb2;
P_0c04bfb2: /* original d315, guest PC 0x0c04bfb2 */
if(!s->budget--) { s->failed_pc=0x0c04bfb2u; return 0; }
r[3]=read(ram,0x0c04c008u,4);
goto P_0c04bfb4;
P_0c04bfb4: /* original 5552, guest PC 0x0c04bfb4 */
if(!s->budget--) { s->failed_pc=0x0c04bfb4u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04bfb6;
P_0c04bfb6: /* original 430b, guest PC 0x0c04bfb6 */
if(!s->budget--) { s->failed_pc=0x0c04bfb6u; return 0; }
target=r[3];
r[16]=code_base|0x0c04bfbau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04bfbau) { target=s->pc; goto dispatch; }
goto P_0c04bfba;
P_0c04bfb8: /* original 64e3, guest PC 0x0c04bfb8 */
if(!s->budget--) { s->failed_pc=0x0c04bfb8u; return 0; }
r[4]=r[14];
goto P_0c04bfba;
P_0c04bfba: /* original 9116, guest PC 0x0c04bfba */
if(!s->budget--) { s->failed_pc=0x0c04bfbau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bfeau,2);
goto P_0c04bfbc;
P_0c04bfbc: /* original 60b3, guest PC 0x0c04bfbc */
if(!s->budget--) { s->failed_pc=0x0c04bfbcu; return 0; }
r[0]=r[11];
goto P_0c04bfbe;
P_0c04bfbe: /* original 3010, guest PC 0x0c04bfbe */
if(!s->budget--) { s->failed_pc=0x0c04bfbeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04bfc0;
P_0c04bfc0: /* original 8903, guest PC 0x0c04bfc0 */
if(!s->budget--) { s->failed_pc=0x0c04bfc0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04bfca; }
goto P_0c04bfc2;
P_0c04bfc2: /* original 8800, guest PC 0x0c04bfc2 */
if(!s->budget--) { s->failed_pc=0x0c04bfc2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04bfc4;
P_0c04bfc4: /* original 8b04, guest PC 0x0c04bfc4 */
if(!s->budget--) { s->failed_pc=0x0c04bfc4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04bfd0; }
goto P_0c04bfc6;
P_0c04bfc6: /* original a004, guest PC 0x0c04bfc6 */
if(!s->budget--) { s->failed_pc=0x0c04bfc6u; return 0; }
r[0]=0x00000000u;
goto P_0c04bfd2;
P_0c04bfc8: /* original e000, guest PC 0x0c04bfc8 */
if(!s->budget--) { s->failed_pc=0x0c04bfc8u; return 0; }
r[0]=0x00000000u;
goto P_0c04bfca;
P_0c04bfca: /* original 900e, guest PC 0x0c04bfca */
if(!s->budget--) { s->failed_pc=0x0c04bfcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04bfeau,2);
goto P_0c04bfcc;
P_0c04bfcc: /* original a001, guest PC 0x0c04bfcc */
if(!s->budget--) { s->failed_pc=0x0c04bfccu; return 0; }
goto P_0c04bfd2;
P_0c04bfce: /* original 0009, guest PC 0x0c04bfce */
if(!s->budget--) { s->failed_pc=0x0c04bfceu; return 0; }
goto P_0c04bfd0;
P_0c04bfd0: /* original d00e, guest PC 0x0c04bfd0 */
if(!s->budget--) { s->failed_pc=0x0c04bfd0u; return 0; }
r[0]=read(ram,0x0c04c00cu,4);
goto P_0c04bfd2;
P_0c04bfd2: /* original 7f04, guest PC 0x0c04bfd2 */
if(!s->budget--) { s->failed_pc=0x0c04bfd2u; return 0; }
r[15]+=0x00000004u;
goto P_0c04bfd4;
P_0c04bfd4: /* original 4f16, guest PC 0x0c04bfd4 */
if(!s->budget--) { s->failed_pc=0x0c04bfd4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bfd6;
P_0c04bfd6: /* original 4f26, guest PC 0x0c04bfd6 */
if(!s->budget--) { s->failed_pc=0x0c04bfd6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04bfd8;
P_0c04bfd8: /* original 68f6, guest PC 0x0c04bfd8 */
if(!s->budget--) { s->failed_pc=0x0c04bfd8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04bfda;
P_0c04bfda: /* original 69f6, guest PC 0x0c04bfda */
if(!s->budget--) { s->failed_pc=0x0c04bfdau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04bfdc;
P_0c04bfdc: /* original 6af6, guest PC 0x0c04bfdc */
if(!s->budget--) { s->failed_pc=0x0c04bfdcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04bfde;
P_0c04bfde: /* original 6bf6, guest PC 0x0c04bfde */
if(!s->budget--) { s->failed_pc=0x0c04bfdeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04bfe0;
P_0c04bfe0: /* original 6cf6, guest PC 0x0c04bfe0 */
if(!s->budget--) { s->failed_pc=0x0c04bfe0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04bfe2;
P_0c04bfe2: /* original 6df6, guest PC 0x0c04bfe2 */
if(!s->budget--) { s->failed_pc=0x0c04bfe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04bfe4;
P_0c04bfe4: /* original 000b, guest PC 0x0c04bfe4 */
if(!s->budget--) { s->failed_pc=0x0c04bfe4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04bfe6: /* original 6ef6, guest PC 0x0c04bfe6 */
if(!s->budget--) { s->failed_pc=0x0c04bfe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04bfe8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04bfe8u; return 0; } return 1;
P_0c04c010: /* original 2fe6, guest PC 0x0c04c010 */
if(!s->budget--) { s->failed_pc=0x0c04c010u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c012;
P_0c04c012: /* original 6e43, guest PC 0x0c04c012 */
if(!s->budget--) { s->failed_pc=0x0c04c012u; return 0; }
r[14]=r[4];
goto P_0c04c014;
P_0c04c014: /* original 2fd6, guest PC 0x0c04c014 */
if(!s->budget--) { s->failed_pc=0x0c04c014u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c016;
P_0c04c016: /* original 2fc6, guest PC 0x0c04c016 */
if(!s->budget--) { s->failed_pc=0x0c04c016u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c018;
P_0c04c018: /* original 2fb6, guest PC 0x0c04c018 */
if(!s->budget--) { s->failed_pc=0x0c04c018u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c01a;
P_0c04c01a: /* original 6b63, guest PC 0x0c04c01a */
if(!s->budget--) { s->failed_pc=0x0c04c01au; return 0; }
r[11]=r[6];
goto P_0c04c01c;
P_0c04c01c: /* original 2fa6, guest PC 0x0c04c01c */
if(!s->budget--) { s->failed_pc=0x0c04c01cu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c01e;
P_0c04c01e: /* original 6a53, guest PC 0x0c04c01e */
if(!s->budget--) { s->failed_pc=0x0c04c01eu; return 0; }
r[10]=r[5];
goto P_0c04c020;
P_0c04c020: /* original 2f96, guest PC 0x0c04c020 */
if(!s->budget--) { s->failed_pc=0x0c04c020u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c022;
P_0c04c022: /* original 2f86, guest PC 0x0c04c022 */
if(!s->budget--) { s->failed_pc=0x0c04c022u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c024;
P_0c04c024: /* original 4f22, guest PC 0x0c04c024 */
if(!s->budget--) { s->failed_pc=0x0c04c024u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04c026;
P_0c04c026: /* original d32c, guest PC 0x0c04c026 */
if(!s->budget--) { s->failed_pc=0x0c04c026u; return 0; }
r[3]=read(ram,0x0c04c0d8u,4);
goto P_0c04c028;
P_0c04c028: /* original 4f12, guest PC 0x0c04c028 */
if(!s->budget--) { s->failed_pc=0x0c04c028u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04c02a;
P_0c04c02a: /* original 6932, guest PC 0x0c04c02a */
if(!s->budget--) { s->failed_pc=0x0c04c02au; return 0; }
tmp=read(ram,r[3],4);
r[9]=tmp;
goto P_0c04c02c;
P_0c04c02c: /* original 7ffc, guest PC 0x0c04c02c */
if(!s->budget--) { s->failed_pc=0x0c04c02cu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c04c02e;
P_0c04c02e: /* original 2f66, guest PC 0x0c04c02e */
if(!s->budget--) { s->failed_pc=0x0c04c02eu; return 0; }
tmp=r[6]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c030;
P_0c04c030: /* original 2fa6, guest PC 0x0c04c030 */
if(!s->budget--) { s->failed_pc=0x0c04c030u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c032;
P_0c04c032: /* original 2fe6, guest PC 0x0c04c032 */
if(!s->budget--) { s->failed_pc=0x0c04c032u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c034;
P_0c04c034: /* original d12a, guest PC 0x0c04c034 */
if(!s->budget--) { s->failed_pc=0x0c04c034u; return 0; }
r[1]=read(ram,0x0c04c0e0u,4);
goto P_0c04c036;
P_0c04c036: /* original d229, guest PC 0x0c04c036 */
if(!s->budget--) { s->failed_pc=0x0c04c036u; return 0; }
r[2]=read(ram,0x0c04c0dcu,4);
goto P_0c04c038;
P_0c04c038: /* original 410b, guest PC 0x0c04c038 */
if(!s->budget--) { s->failed_pc=0x0c04c038u; return 0; }
target=r[1];
r[16]=code_base|0x0c04c03cu;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c03cu) { target=s->pc; goto dispatch; }
goto P_0c04c03c;
P_0c04c03a: /* original 2f26, guest PC 0x0c04c03a */
if(!s->budget--) { s->failed_pc=0x0c04c03au; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04c03c;
P_0c04c03c: /* original 9d49, guest PC 0x0c04c03c */
if(!s->budget--) { s->failed_pc=0x0c04c03cu; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d2u,2);
goto P_0c04c03e;
P_0c04c03e: /* original 7f10, guest PC 0x0c04c03e */
if(!s->budget--) { s->failed_pc=0x0c04c03eu; return 0; }
r[15]+=0x00000010u;
goto P_0c04c040;
P_0c04c040: /* original 0ed7, guest PC 0x0c04c040 */
if(!s->budget--) { s->failed_pc=0x0c04c040u; return 0; }
r[19]=r[14]*r[13];
goto P_0c04c042;
P_0c04c042: /* original 0d1a, guest PC 0x0c04c042 */
if(!s->budget--) { s->failed_pc=0x0c04c042u; return 0; }
r[13]=r[19];
goto P_0c04c044;
P_0c04c044: /* original 2fd2, guest PC 0x0c04c044 */
if(!s->budget--) { s->failed_pc=0x0c04c044u; return 0; }
write(ram,r[15],r[13],4);
goto P_0c04c046;
P_0c04c046: /* original d327, guest PC 0x0c04c046 */
if(!s->budget--) { s->failed_pc=0x0c04c046u; return 0; }
r[3]=read(ram,0x0c04c0e4u,4);
goto P_0c04c048;
P_0c04c048: /* original d827, guest PC 0x0c04c048 */
if(!s->budget--) { s->failed_pc=0x0c04c048u; return 0; }
r[8]=read(ram,0x0c04c0e8u,4);
goto P_0c04c04a;
P_0c04c04a: /* original 3d3c, guest PC 0x0c04c04a */
if(!s->budget--) { s->failed_pc=0x0c04c04au; return 0; }
r[13]+=r[3];
goto P_0c04c04c;
P_0c04c04c: /* original 65a3, guest PC 0x0c04c04c */
if(!s->budget--) { s->failed_pc=0x0c04c04cu; return 0; }
r[5]=r[10];
goto P_0c04c04e;
P_0c04c04e: /* original 66b3, guest PC 0x0c04c04e */
if(!s->budget--) { s->failed_pc=0x0c04c04eu; return 0; }
r[6]=r[11];
goto P_0c04c050;
P_0c04c050: /* original 480b, guest PC 0x0c04c050 */
if(!s->budget--) { s->failed_pc=0x0c04c050u; return 0; }
target=r[8];
r[16]=code_base|0x0c04c054u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c054u) { target=s->pc; goto dispatch; }
goto P_0c04c054;
P_0c04c052: /* original 64e3, guest PC 0x0c04c052 */
if(!s->budget--) { s->failed_pc=0x0c04c052u; return 0; }
r[4]=r[14];
goto P_0c04c054;
P_0c04c054: /* original 6c03, guest PC 0x0c04c054 */
if(!s->budget--) { s->failed_pc=0x0c04c054u; return 0; }
r[12]=r[0];
goto P_0c04c056;
P_0c04c056: /* original 2cc8, guest PC 0x0c04c056 */
if(!s->budget--) { s->failed_pc=0x0c04c056u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c04c058;
P_0c04c058: /* original 8909, guest PC 0x0c04c058 */
if(!s->budget--) { s->failed_pc=0x0c04c058u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c06e; }
goto P_0c04c05a;
P_0c04c05a: /* original 52dd, guest PC 0x0c04c05a */
if(!s->budget--) { s->failed_pc=0x0c04c05au; return 0; }
r[2]=read(ram,r[13]+52,4);
goto P_0c04c05c;
P_0c04c05c: /* original 2998, guest PC 0x0c04c05c */
if(!s->budget--) { s->failed_pc=0x0c04c05cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c04c05e;
P_0c04c05e: /* original 7201, guest PC 0x0c04c05e */
if(!s->budget--) { s->failed_pc=0x0c04c05eu; return 0; }
r[2]+=0x00000001u;
goto P_0c04c060;
P_0c04c060: /* original 1d2d, guest PC 0x0c04c060 */
if(!s->budget--) { s->failed_pc=0x0c04c060u; return 0; }
write(ram,r[13]+52,r[2],4);
goto P_0c04c062;
P_0c04c062: /* original 8ff3, guest PC 0x0c04c062 */
if(!s->budget--) { s->failed_pc=0x0c04c062u; return 0; }
cond=r[17]&1u;
r[9]+=0xffffffffu;
if(!cond) { goto P_0c04c04c; }
goto P_0c04c066;
P_0c04c064: /* original 79ff, guest PC 0x0c04c064 */
if(!s->budget--) { s->failed_pc=0x0c04c064u; return 0; }
r[9]+=0xffffffffu;
goto P_0c04c066;
P_0c04c066: /* original d11c, guest PC 0x0c04c066 */
if(!s->budget--) { s->failed_pc=0x0c04c066u; return 0; }
r[1]=read(ram,0x0c04c0d8u,4);
goto P_0c04c068;
P_0c04c068: /* original 6012, guest PC 0x0c04c068 */
if(!s->budget--) { s->failed_pc=0x0c04c068u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c04c06a;
P_0c04c06a: /* original 88ff, guest PC 0x0c04c06a */
if(!s->budget--) { s->failed_pc=0x0c04c06au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c04c06c;
P_0c04c06c: /* original 89ee, guest PC 0x0c04c06c */
if(!s->budget--) { s->failed_pc=0x0c04c06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c04c; }
goto P_0c04c06e;
P_0c04c06e: /* original 6df2, guest PC 0x0c04c06e */
if(!s->budget--) { s->failed_pc=0x0c04c06eu; return 0; }
tmp=read(ram,r[15],4);
r[13]=tmp;
goto P_0c04c070;
P_0c04c070: /* original 62e3, guest PC 0x0c04c070 */
if(!s->budget--) { s->failed_pc=0x0c04c070u; return 0; }
r[2]=r[14];
goto P_0c04c072;
P_0c04c072: /* original d31c, guest PC 0x0c04c072 */
if(!s->budget--) { s->failed_pc=0x0c04c072u; return 0; }
r[3]=read(ram,0x0c04c0e4u,4);
goto P_0c04c074;
P_0c04c074: /* original 4208, guest PC 0x0c04c074 */
if(!s->budget--) { s->failed_pc=0x0c04c074u; return 0; }
r[2]<<=2;
goto P_0c04c076;
P_0c04c076: /* original 4208, guest PC 0x0c04c076 */
if(!s->budget--) { s->failed_pc=0x0c04c076u; return 0; }
r[2]<<=2;
goto P_0c04c078;
P_0c04c078: /* original d11c, guest PC 0x0c04c078 */
if(!s->budget--) { s->failed_pc=0x0c04c078u; return 0; }
r[1]=read(ram,0x0c04c0ecu,4);
goto P_0c04c07a;
P_0c04c07a: /* original 3d3c, guest PC 0x0c04c07a */
if(!s->budget--) { s->failed_pc=0x0c04c07au; return 0; }
r[13]+=r[3];
goto P_0c04c07c;
P_0c04c07c: /* original 4208, guest PC 0x0c04c07c */
if(!s->budget--) { s->failed_pc=0x0c04c07cu; return 0; }
r[2]<<=2;
goto P_0c04c07e;
P_0c04c07e: /* original 4200, guest PC 0x0c04c07e */
if(!s->budget--) { s->failed_pc=0x0c04c07eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c04c080;
P_0c04c080: /* original 321c, guest PC 0x0c04c080 */
if(!s->budget--) { s->failed_pc=0x0c04c080u; return 0; }
r[2]+=r[1];
goto P_0c04c082;
P_0c04c082: /* original 2f22, guest PC 0x0c04c082 */
if(!s->budget--) { s->failed_pc=0x0c04c082u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c04c084;
P_0c04c084: /* original 56dc, guest PC 0x0c04c084 */
if(!s->budget--) { s->failed_pc=0x0c04c084u; return 0; }
r[6]=read(ram,r[13]+48,4);
goto P_0c04c086;
P_0c04c086: /* original 57dd, guest PC 0x0c04c086 */
if(!s->budget--) { s->failed_pc=0x0c04c086u; return 0; }
r[7]=read(ram,r[13]+52,4);
goto P_0c04c088;
P_0c04c088: /* original 7601, guest PC 0x0c04c088 */
if(!s->budget--) { s->failed_pc=0x0c04c088u; return 0; }
r[6]+=0x00000001u;
goto P_0c04c08a;
P_0c04c08a: /* original 1d6c, guest PC 0x0c04c08a */
if(!s->budget--) { s->failed_pc=0x0c04c08au; return 0; }
write(ram,r[13]+48,r[6],4);
goto P_0c04c08c;
P_0c04c08c: /* original 76ff, guest PC 0x0c04c08c */
if(!s->budget--) { s->failed_pc=0x0c04c08cu; return 0; }
r[6]+=0xffffffffu;
goto P_0c04c08e;
P_0c04c08e: /* original 65f2, guest PC 0x0c04c08e */
if(!s->budget--) { s->failed_pc=0x0c04c08eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c04c090;
P_0c04c090: /* original d317, guest PC 0x0c04c090 */
if(!s->budget--) { s->failed_pc=0x0c04c090u; return 0; }
r[3]=read(ram,0x0c04c0f0u,4);
goto P_0c04c092;
P_0c04c092: /* original 5552, guest PC 0x0c04c092 */
if(!s->budget--) { s->failed_pc=0x0c04c092u; return 0; }
r[5]=read(ram,r[5]+8,4);
goto P_0c04c094;
P_0c04c094: /* original 430b, guest PC 0x0c04c094 */
if(!s->budget--) { s->failed_pc=0x0c04c094u; return 0; }
target=r[3];
r[16]=code_base|0x0c04c098u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04c098u) { target=s->pc; goto dispatch; }
goto P_0c04c098;
P_0c04c096: /* original 64e3, guest PC 0x0c04c096 */
if(!s->budget--) { s->failed_pc=0x0c04c096u; return 0; }
r[4]=r[14];
goto P_0c04c098;
P_0c04c098: /* original 911c, guest PC 0x0c04c098 */
if(!s->budget--) { s->failed_pc=0x0c04c098u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d4u,2);
goto P_0c04c09a;
P_0c04c09a: /* original 60c3, guest PC 0x0c04c09a */
if(!s->budget--) { s->failed_pc=0x0c04c09au; return 0; }
r[0]=r[12];
goto P_0c04c09c;
P_0c04c09c: /* original 3010, guest PC 0x0c04c09c */
if(!s->budget--) { s->failed_pc=0x0c04c09cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04c09e;
P_0c04c09e: /* original 8906, guest PC 0x0c04c09e */
if(!s->budget--) { s->failed_pc=0x0c04c09eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c0ae; }
goto P_0c04c0a0;
P_0c04c0a0: /* original 9119, guest PC 0x0c04c0a0 */
if(!s->budget--) { s->failed_pc=0x0c04c0a0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d6u,2);
goto P_0c04c0a2;
P_0c04c0a2: /* original 3010, guest PC 0x0c04c0a2 */
if(!s->budget--) { s->failed_pc=0x0c04c0a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c04c0a4;
P_0c04c0a4: /* original 8906, guest PC 0x0c04c0a4 */
if(!s->budget--) { s->failed_pc=0x0c04c0a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04c0b4; }
goto P_0c04c0a6;
P_0c04c0a6: /* original 8800, guest PC 0x0c04c0a6 */
if(!s->budget--) { s->failed_pc=0x0c04c0a6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c04c0a8;
P_0c04c0a8: /* original 8b07, guest PC 0x0c04c0a8 */
if(!s->budget--) { s->failed_pc=0x0c04c0a8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04c0ba; }
goto P_0c04c0aa;
P_0c04c0aa: /* original a007, guest PC 0x0c04c0aa */
if(!s->budget--) { s->failed_pc=0x0c04c0aau; return 0; }
r[0]=0x00000000u;
goto P_0c04c0bc;
P_0c04c0ac: /* original e000, guest PC 0x0c04c0ac */
if(!s->budget--) { s->failed_pc=0x0c04c0acu; return 0; }
r[0]=0x00000000u;
goto P_0c04c0ae;
P_0c04c0ae: /* original 9011, guest PC 0x0c04c0ae */
if(!s->budget--) { s->failed_pc=0x0c04c0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d4u,2);
goto P_0c04c0b0;
P_0c04c0b0: /* original a004, guest PC 0x0c04c0b0 */
if(!s->budget--) { s->failed_pc=0x0c04c0b0u; return 0; }
goto P_0c04c0bc;
P_0c04c0b2: /* original 0009, guest PC 0x0c04c0b2 */
if(!s->budget--) { s->failed_pc=0x0c04c0b2u; return 0; }
goto P_0c04c0b4;
P_0c04c0b4: /* original 900f, guest PC 0x0c04c0b4 */
if(!s->budget--) { s->failed_pc=0x0c04c0b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04c0d6u,2);
goto P_0c04c0b6;
P_0c04c0b6: /* original a001, guest PC 0x0c04c0b6 */
if(!s->budget--) { s->failed_pc=0x0c04c0b6u; return 0; }
goto P_0c04c0bc;
P_0c04c0b8: /* original 0009, guest PC 0x0c04c0b8 */
if(!s->budget--) { s->failed_pc=0x0c04c0b8u; return 0; }
goto P_0c04c0ba;
P_0c04c0ba: /* original d00e, guest PC 0x0c04c0ba */
if(!s->budget--) { s->failed_pc=0x0c04c0bau; return 0; }
r[0]=read(ram,0x0c04c0f4u,4);
goto P_0c04c0bc;
P_0c04c0bc: /* original 7f04, guest PC 0x0c04c0bc */
if(!s->budget--) { s->failed_pc=0x0c04c0bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c04c0be;
P_0c04c0be: /* original 4f16, guest PC 0x0c04c0be */
if(!s->budget--) { s->failed_pc=0x0c04c0beu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c0c0;
P_0c04c0c0: /* original 4f26, guest PC 0x0c04c0c0 */
if(!s->budget--) { s->failed_pc=0x0c04c0c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04c0c2;
P_0c04c0c2: /* original 68f6, guest PC 0x0c04c0c2 */
if(!s->budget--) { s->failed_pc=0x0c04c0c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04c0c4;
P_0c04c0c4: /* original 69f6, guest PC 0x0c04c0c4 */
if(!s->budget--) { s->failed_pc=0x0c04c0c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04c0c6;
P_0c04c0c6: /* original 6af6, guest PC 0x0c04c0c6 */
if(!s->budget--) { s->failed_pc=0x0c04c0c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04c0c8;
P_0c04c0c8: /* original 6bf6, guest PC 0x0c04c0c8 */
if(!s->budget--) { s->failed_pc=0x0c04c0c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04c0ca;
P_0c04c0ca: /* original 6cf6, guest PC 0x0c04c0ca */
if(!s->budget--) { s->failed_pc=0x0c04c0cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04c0cc;
P_0c04c0cc: /* original 6df6, guest PC 0x0c04c0cc */
if(!s->budget--) { s->failed_pc=0x0c04c0ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04c0ce;
P_0c04c0ce: /* original 000b, guest PC 0x0c04c0ce */
if(!s->budget--) { s->failed_pc=0x0c04c0ceu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04c0d0: /* original 6ef6, guest PC 0x0c04c0d0 */
if(!s->budget--) { s->failed_pc=0x0c04c0d0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c04c0d2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04c0d2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
