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
int vf3_away_batch5_adapter_9(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c045bcau: goto P_0c045bca;
case 0x0c045bccu: goto P_0c045bcc;
case 0x0c045bceu: goto P_0c045bce;
case 0x0c045bd0u: goto P_0c045bd0;
case 0x0c045bd2u: goto P_0c045bd2;
case 0x0c045bd4u: goto P_0c045bd4;
case 0x0c045bd6u: goto P_0c045bd6;
case 0x0c045bd8u: goto P_0c045bd8;
case 0x0c045bdau: goto P_0c045bda;
case 0x0c045bdcu: goto P_0c045bdc;
case 0x0c045bdeu: goto P_0c045bde;
case 0x0c045be0u: goto P_0c045be0;
case 0x0c045be2u: goto P_0c045be2;
case 0x0c045be4u: goto P_0c045be4;
case 0x0c045be6u: goto P_0c045be6;
case 0x0c045be8u: goto P_0c045be8;
case 0x0c045beau: goto P_0c045bea;
case 0x0c045becu: goto P_0c045bec;
case 0x0c045beeu: goto P_0c045bee;
case 0x0c045bf0u: goto P_0c045bf0;
case 0x0c045bf2u: goto P_0c045bf2;
case 0x0c045bf4u: goto P_0c045bf4;
case 0x0c045bf6u: goto P_0c045bf6;
case 0x0c045bf8u: goto P_0c045bf8;
case 0x0c045bfau: goto P_0c045bfa;
case 0x0c045bfcu: goto P_0c045bfc;
case 0x0c045bfeu: goto P_0c045bfe;
case 0x0c045c00u: goto P_0c045c00;
case 0x0c045c02u: goto P_0c045c02;
case 0x0c045c04u: goto P_0c045c04;
case 0x0c045c06u: goto P_0c045c06;
case 0x0c045c08u: goto P_0c045c08;
case 0x0c045c0au: goto P_0c045c0a;
case 0x0c045c0cu: goto P_0c045c0c;
case 0x0c045c0eu: goto P_0c045c0e;
case 0x0c045c10u: goto P_0c045c10;
case 0x0c045c12u: goto P_0c045c12;
case 0x0c045c14u: goto P_0c045c14;
case 0x0c045c16u: goto P_0c045c16;
case 0x0c045c18u: goto P_0c045c18;
case 0x0c045c1au: goto P_0c045c1a;
case 0x0c045c1cu: goto P_0c045c1c;
case 0x0c045c1eu: goto P_0c045c1e;
case 0x0c045c20u: goto P_0c045c20;
case 0x0c045c22u: goto P_0c045c22;
case 0x0c045c24u: goto P_0c045c24;
case 0x0c045c26u: goto P_0c045c26;
case 0x0c045c28u: goto P_0c045c28;
case 0x0c045ef4u: goto P_0c045ef4;
case 0x0c045ef6u: goto P_0c045ef6;
case 0x0c045ef8u: goto P_0c045ef8;
case 0x0c045efau: goto P_0c045efa;
case 0x0c045efcu: goto P_0c045efc;
case 0x0c045efeu: goto P_0c045efe;
case 0x0c045f00u: goto P_0c045f00;
case 0x0c045f02u: goto P_0c045f02;
case 0x0c045f04u: goto P_0c045f04;
case 0x0c045f06u: goto P_0c045f06;
case 0x0c045f08u: goto P_0c045f08;
case 0x0c04b9e4u: goto P_0c04b9e4;
case 0x0c04b9e6u: goto P_0c04b9e6;
case 0x0c04b9e8u: goto P_0c04b9e8;
case 0x0c04b9eau: goto P_0c04b9ea;
case 0x0c04b9ecu: goto P_0c04b9ec;
case 0x0c04b9eeu: goto P_0c04b9ee;
case 0x0c04b9f0u: goto P_0c04b9f0;
case 0x0c04b9f2u: goto P_0c04b9f2;
case 0x0c04b9f4u: goto P_0c04b9f4;
case 0x0c04b9f6u: goto P_0c04b9f6;
case 0x0c04b9f8u: goto P_0c04b9f8;
case 0x0c04b9fau: goto P_0c04b9fa;
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
P_0c045bca: /* original d328, guest PC 0x0c045bca */
if(!s->budget--) { s->failed_pc=0x0c045bcau; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045bcc;
P_0c045bcc: /* original 4f22, guest PC 0x0c045bcc */
if(!s->budget--) { s->failed_pc=0x0c045bccu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045bce;
P_0c045bce: /* original 6032, guest PC 0x0c045bce */
if(!s->budget--) { s->failed_pc=0x0c045bceu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c045bd0;
P_0c045bd0: /* original 401b, guest PC 0x0c045bd0 */
if(!s->budget--) { s->failed_pc=0x0c045bd0u; return 0; }
tmp=read(ram,r[0],1);
r[17]=(r[17]&~1u)|((tmp==0)!=0);
write(ram,r[0],tmp|0x80u,1);
goto P_0c045bd2;
P_0c045bd2: /* original 8907, guest PC 0x0c045bd2 */
if(!s->budget--) { s->failed_pc=0x0c045bd2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c045be4; }
goto P_0c045bd4;
P_0c045bd4: /* original d224, guest PC 0x0c045bd4 */
if(!s->budget--) { s->failed_pc=0x0c045bd4u; return 0; }
r[2]=read(ram,0x0c045c68u,4);
goto P_0c045bd6;
P_0c045bd6: /* original d126, guest PC 0x0c045bd6 */
if(!s->budget--) { s->failed_pc=0x0c045bd6u; return 0; }
r[1]=read(ram,0x0c045c70u,4);
goto P_0c045bd8;
P_0c045bd8: /* original 420b, guest PC 0x0c045bd8 */
if(!s->budget--) { s->failed_pc=0x0c045bd8u; return 0; }
target=r[2];
r[16]=code_base|0x0c045bdcu;
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045bdcu) { target=s->pc; goto dispatch; }
goto P_0c045bdc;
P_0c045bda: /* original 2f16, guest PC 0x0c045bda */
if(!s->budget--) { s->failed_pc=0x0c045bdau; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045bdc;
P_0c045bdc: /* original 7f04, guest PC 0x0c045bdc */
if(!s->budget--) { s->failed_pc=0x0c045bdcu; return 0; }
r[15]+=0x00000004u;
goto P_0c045bde;
P_0c045bde: /* original 4f26, guest PC 0x0c045bde */
if(!s->budget--) { s->failed_pc=0x0c045bdeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045be0;
P_0c045be0: /* original 000b, guest PC 0x0c045be0 */
if(!s->budget--) { s->failed_pc=0x0c045be0u; return 0; }
target=r[16];
r[0]=0xfffffffeu;
s->pc=target; return ram->oob==0;
P_0c045be2: /* original e0fe, guest PC 0x0c045be2 */
if(!s->budget--) { s->failed_pc=0x0c045be2u; return 0; }
r[0]=0xfffffffeu;
goto P_0c045be4;
P_0c045be4: /* original 53f1, guest PC 0x0c045be4 */
if(!s->budget--) { s->failed_pc=0x0c045be4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c045be6;
P_0c045be6: /* original 2f36, guest PC 0x0c045be6 */
if(!s->budget--) { s->failed_pc=0x0c045be6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045be8;
P_0c045be8: /* original b008, guest PC 0x0c045be8 */
if(!s->budget--) { s->failed_pc=0x0c045be8u; return 0; }
target=code_base|0x0c045bfcu; r[16]=code_base|0x0c045becu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045becu) { target=s->pc; goto dispatch; }
goto P_0c045bec;
P_0c045bea: /* original 0009, guest PC 0x0c045bea */
if(!s->budget--) { s->failed_pc=0x0c045beau; return 0; }
goto P_0c045bec;
P_0c045bec: /* original d31f, guest PC 0x0c045bec */
if(!s->budget--) { s->failed_pc=0x0c045becu; return 0; }
r[3]=read(ram,0x0c045c6cu,4);
goto P_0c045bee;
P_0c045bee: /* original e100, guest PC 0x0c045bee */
if(!s->budget--) { s->failed_pc=0x0c045beeu; return 0; }
r[1]=0x00000000u;
goto P_0c045bf0;
P_0c045bf0: /* original 7f04, guest PC 0x0c045bf0 */
if(!s->budget--) { s->failed_pc=0x0c045bf0u; return 0; }
r[15]+=0x00000004u;
goto P_0c045bf2;
P_0c045bf2: /* original 6232, guest PC 0x0c045bf2 */
if(!s->budget--) { s->failed_pc=0x0c045bf2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c045bf4;
P_0c045bf4: /* original 2210, guest PC 0x0c045bf4 */
if(!s->budget--) { s->failed_pc=0x0c045bf4u; return 0; }
write(ram,r[2],r[1],1);
goto P_0c045bf6;
P_0c045bf6: /* original 4f26, guest PC 0x0c045bf6 */
if(!s->budget--) { s->failed_pc=0x0c045bf6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045bf8;
P_0c045bf8: /* original 000b, guest PC 0x0c045bf8 */
if(!s->budget--) { s->failed_pc=0x0c045bf8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c045bfa: /* original 0009, guest PC 0x0c045bfa */
if(!s->budget--) { s->failed_pc=0x0c045bfau; return 0; }
goto P_0c045bfc;
P_0c045bfc: /* original 2fe6, guest PC 0x0c045bfc */
if(!s->budget--) { s->failed_pc=0x0c045bfcu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045bfe;
P_0c045bfe: /* original 4628, guest PC 0x0c045bfe */
if(!s->budget--) { s->failed_pc=0x0c045bfeu; return 0; }
r[6]<<=16;
goto P_0c045c00;
P_0c045c00: /* original 4f22, guest PC 0x0c045c00 */
if(!s->budget--) { s->failed_pc=0x0c045c00u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c045c02;
P_0c045c02: /* original 4618, guest PC 0x0c045c02 */
if(!s->budget--) { s->failed_pc=0x0c045c02u; return 0; }
r[6]<<=8;
goto P_0c045c04;
P_0c045c04: /* original 4728, guest PC 0x0c045c04 */
if(!s->budget--) { s->failed_pc=0x0c045c04u; return 0; }
r[7]<<=16;
goto P_0c045c06;
P_0c045c06: /* original 7ff8, guest PC 0x0c045c06 */
if(!s->budget--) { s->failed_pc=0x0c045c06u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c045c08;
P_0c045c08: /* original 267b, guest PC 0x0c045c08 */
if(!s->budget--) { s->failed_pc=0x0c045c08u; return 0; }
r[6]|=r[7];
goto P_0c045c0a;
P_0c045c0a: /* original 6ef3, guest PC 0x0c045c0a */
if(!s->budget--) { s->failed_pc=0x0c045c0au; return 0; }
r[14]=r[15];
goto P_0c045c0c;
P_0c045c0c: /* original e702, guest PC 0x0c045c0c */
if(!s->budget--) { s->failed_pc=0x0c045c0cu; return 0; }
r[7]=0x00000002u;
goto P_0c045c0e;
P_0c045c0e: /* original 2e52, guest PC 0x0c045c0e */
if(!s->budget--) { s->failed_pc=0x0c045c0eu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c045c10;
P_0c045c10: /* original 53f4, guest PC 0x0c045c10 */
if(!s->budget--) { s->failed_pc=0x0c045c10u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c045c12;
P_0c045c12: /* original 263b, guest PC 0x0c045c12 */
if(!s->budget--) { s->failed_pc=0x0c045c12u; return 0; }
r[6]|=r[3];
goto P_0c045c14;
P_0c045c14: /* original e300, guest PC 0x0c045c14 */
if(!s->budget--) { s->failed_pc=0x0c045c14u; return 0; }
r[3]=0x00000000u;
goto P_0c045c16;
P_0c045c16: /* original 1e61, guest PC 0x0c045c16 */
if(!s->budget--) { s->failed_pc=0x0c045c16u; return 0; }
write(ram,r[14]+4,r[6],4);
goto P_0c045c18;
P_0c045c18: /* original 2f36, guest PC 0x0c045c18 */
if(!s->budget--) { s->failed_pc=0x0c045c18u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c1a;
P_0c045c1a: /* original 66e3, guest PC 0x0c045c1a */
if(!s->budget--) { s->failed_pc=0x0c045c1au; return 0; }
r[6]=r[14];
goto P_0c045c1c;
P_0c045c1c: /* original 2f36, guest PC 0x0c045c1c */
if(!s->budget--) { s->failed_pc=0x0c045c1cu; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c045c1e;
P_0c045c1e: /* original b84f, guest PC 0x0c045c1e */
if(!s->budget--) { s->failed_pc=0x0c045c1eu; return 0; }
target=code_base|0x0c044cc0u; r[16]=code_base|0x0c045c22u;
r[5]=0x0000000bu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c045c22u) { target=s->pc; goto dispatch; }
goto P_0c045c22;
P_0c045c20: /* original e50b, guest PC 0x0c045c20 */
if(!s->budget--) { s->failed_pc=0x0c045c20u; return 0; }
r[5]=0x0000000bu;
goto P_0c045c22;
P_0c045c22: /* original 7f10, guest PC 0x0c045c22 */
if(!s->budget--) { s->failed_pc=0x0c045c22u; return 0; }
r[15]+=0x00000010u;
goto P_0c045c24;
P_0c045c24: /* original 4f26, guest PC 0x0c045c24 */
if(!s->budget--) { s->failed_pc=0x0c045c24u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c045c26;
P_0c045c26: /* original 000b, guest PC 0x0c045c26 */
if(!s->budget--) { s->failed_pc=0x0c045c26u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c045c28: /* original 6ef6, guest PC 0x0c045c28 */
if(!s->budget--) { s->failed_pc=0x0c045c28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c045c2au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045c2au; return 0; } return 1;
P_0c045ef4: /* original 4615, guest PC 0x0c045ef4 */
if(!s->budget--) { s->failed_pc=0x0c045ef4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[6]>0)!=0);
goto P_0c045ef6;
P_0c045ef6: /* original e700, guest PC 0x0c045ef6 */
if(!s->budget--) { s->failed_pc=0x0c045ef6u; return 0; }
r[7]=0x00000000u;
goto P_0c045ef8;
P_0c045ef8: /* original 8f05, guest PC 0x0c045ef8 */
if(!s->budget--) { s->failed_pc=0x0c045ef8u; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(!cond) { goto P_0c045f06; }
goto P_0c045efc;
P_0c045efa: /* original 6043, guest PC 0x0c045efa */
if(!s->budget--) { s->failed_pc=0x0c045efau; return 0; }
r[0]=r[4];
goto P_0c045efc;
P_0c045efc: /* original 7701, guest PC 0x0c045efc */
if(!s->budget--) { s->failed_pc=0x0c045efcu; return 0; }
r[7]+=0x00000001u;
goto P_0c045efe;
P_0c045efe: /* original 2052, guest PC 0x0c045efe */
if(!s->budget--) { s->failed_pc=0x0c045efeu; return 0; }
write(ram,r[0],r[5],4);
goto P_0c045f00;
P_0c045f00: /* original 3763, guest PC 0x0c045f00 */
if(!s->budget--) { s->failed_pc=0x0c045f00u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[7]>=(int32_t)r[6])!=0);
goto P_0c045f02;
P_0c045f02: /* original 8ffb, guest PC 0x0c045f02 */
if(!s->budget--) { s->failed_pc=0x0c045f02u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000004u;
if(!cond) { goto P_0c045efc; }
goto P_0c045f06;
P_0c045f04: /* original 7004, guest PC 0x0c045f04 */
if(!s->budget--) { s->failed_pc=0x0c045f04u; return 0; }
r[0]+=0x00000004u;
goto P_0c045f06;
P_0c045f06: /* original 000b, guest PC 0x0c045f06 */
if(!s->budget--) { s->failed_pc=0x0c045f06u; return 0; }
target=r[16];
r[0]=r[6];
s->pc=target; return ram->oob==0;
P_0c045f08: /* original 6063, guest PC 0x0c045f08 */
if(!s->budget--) { s->failed_pc=0x0c045f08u; return 0; }
r[0]=r[6];
if(!vf3_matrix_family(0x0c045f0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c045f0au; return 0; } return 1;
P_0c04b9e4: /* original e700, guest PC 0x0c04b9e4 */
if(!s->budget--) { s->failed_pc=0x0c04b9e4u; return 0; }
r[7]=0x00000000u;
goto P_0c04b9e6;
P_0c04b9e6: /* original 6373, guest PC 0x0c04b9e6 */
if(!s->budget--) { s->failed_pc=0x0c04b9e6u; return 0; }
r[3]=r[7];
goto P_0c04b9e8;
P_0c04b9e8: /* original 3362, guest PC 0x0c04b9e8 */
if(!s->budget--) { s->failed_pc=0x0c04b9e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[6])!=0);
goto P_0c04b9ea;
P_0c04b9ea: /* original 8d05, guest PC 0x0c04b9ea */
if(!s->budget--) { s->failed_pc=0x0c04b9eau; return 0; }
cond=r[17]&1u;
r[0]=r[4];
if(cond) { goto P_0c04b9f8; }
goto P_0c04b9ee;
P_0c04b9ec: /* original 6043, guest PC 0x0c04b9ec */
if(!s->budget--) { s->failed_pc=0x0c04b9ecu; return 0; }
r[0]=r[4];
goto P_0c04b9ee;
P_0c04b9ee: /* original 7701, guest PC 0x0c04b9ee */
if(!s->budget--) { s->failed_pc=0x0c04b9eeu; return 0; }
r[7]+=0x00000001u;
goto P_0c04b9f0;
P_0c04b9f0: /* original 2050, guest PC 0x0c04b9f0 */
if(!s->budget--) { s->failed_pc=0x0c04b9f0u; return 0; }
write(ram,r[0],r[5],1);
goto P_0c04b9f2;
P_0c04b9f2: /* original 3762, guest PC 0x0c04b9f2 */
if(!s->budget--) { s->failed_pc=0x0c04b9f2u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>=r[6])!=0);
goto P_0c04b9f4;
P_0c04b9f4: /* original 8ffb, guest PC 0x0c04b9f4 */
if(!s->budget--) { s->failed_pc=0x0c04b9f4u; return 0; }
cond=r[17]&1u;
r[0]+=0x00000001u;
if(!cond) { goto P_0c04b9ee; }
goto P_0c04b9f8;
P_0c04b9f6: /* original 7001, guest PC 0x0c04b9f6 */
if(!s->budget--) { s->failed_pc=0x0c04b9f6u; return 0; }
r[0]+=0x00000001u;
goto P_0c04b9f8;
P_0c04b9f8: /* original 000b, guest PC 0x0c04b9f8 */
if(!s->budget--) { s->failed_pc=0x0c04b9f8u; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c04b9fa: /* original 6043, guest PC 0x0c04b9fa */
if(!s->budget--) { s->failed_pc=0x0c04b9fau; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04b9fcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04b9fcu; return 0; } return 1;
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
