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
int vf3_away_batch5_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c04df5au: goto P_0c04df5a;
case 0x0c04df5cu: goto P_0c04df5c;
case 0x0c04df5eu: goto P_0c04df5e;
case 0x0c04df60u: goto P_0c04df60;
case 0x0c04df62u: goto P_0c04df62;
case 0x0c04df64u: goto P_0c04df64;
case 0x0c04df66u: goto P_0c04df66;
case 0x0c04df68u: goto P_0c04df68;
case 0x0c04df6au: goto P_0c04df6a;
case 0x0c04df6cu: goto P_0c04df6c;
case 0x0c04df6eu: goto P_0c04df6e;
case 0x0c04df70u: goto P_0c04df70;
case 0x0c04df72u: goto P_0c04df72;
case 0x0c04df74u: goto P_0c04df74;
case 0x0c04df76u: goto P_0c04df76;
case 0x0c04df78u: goto P_0c04df78;
case 0x0c04df7au: goto P_0c04df7a;
case 0x0c04df7cu: goto P_0c04df7c;
case 0x0c04df7eu: goto P_0c04df7e;
case 0x0c04df80u: goto P_0c04df80;
case 0x0c04df82u: goto P_0c04df82;
case 0x0c04df84u: goto P_0c04df84;
case 0x0c04df86u: goto P_0c04df86;
case 0x0c04df88u: goto P_0c04df88;
case 0x0c04df8au: goto P_0c04df8a;
case 0x0c04df8cu: goto P_0c04df8c;
case 0x0c04df8eu: goto P_0c04df8e;
case 0x0c04df90u: goto P_0c04df90;
case 0x0c04df92u: goto P_0c04df92;
case 0x0c04df94u: goto P_0c04df94;
case 0x0c04df96u: goto P_0c04df96;
case 0x0c04df98u: goto P_0c04df98;
case 0x0c04df9au: goto P_0c04df9a;
case 0x0c04df9cu: goto P_0c04df9c;
case 0x0c04df9eu: goto P_0c04df9e;
case 0x0c04dfa0u: goto P_0c04dfa0;
case 0x0c04dfa2u: goto P_0c04dfa2;
case 0x0c04dfa4u: goto P_0c04dfa4;
case 0x0c04dfa6u: goto P_0c04dfa6;
case 0x0c04dfa8u: goto P_0c04dfa8;
case 0x0c04dfaau: goto P_0c04dfaa;
case 0x0c04dfacu: goto P_0c04dfac;
case 0x0c04dfaeu: goto P_0c04dfae;
case 0x0c04dfb0u: goto P_0c04dfb0;
case 0x0c04dfb2u: goto P_0c04dfb2;
case 0x0c04dfb4u: goto P_0c04dfb4;
case 0x0c04dfb6u: goto P_0c04dfb6;
case 0x0c04dfb8u: goto P_0c04dfb8;
case 0x0c04dfbau: goto P_0c04dfba;
case 0x0c04dfbcu: goto P_0c04dfbc;
case 0x0c04dfbeu: goto P_0c04dfbe;
case 0x0c04dfc0u: goto P_0c04dfc0;
case 0x0c04dfc2u: goto P_0c04dfc2;
case 0x0c04dfc4u: goto P_0c04dfc4;
case 0x0c04dfc6u: goto P_0c04dfc6;
case 0x0c04dfc8u: goto P_0c04dfc8;
case 0x0c04dfcau: goto P_0c04dfca;
case 0x0c04dfccu: goto P_0c04dfcc;
case 0x0c04dfceu: goto P_0c04dfce;
case 0x0c04dfd0u: goto P_0c04dfd0;
case 0x0c04dfd2u: goto P_0c04dfd2;
case 0x0c04dfd4u: goto P_0c04dfd4;
case 0x0c04dfd6u: goto P_0c04dfd6;
case 0x0c04dfd8u: goto P_0c04dfd8;
case 0x0c04dfdau: goto P_0c04dfda;
case 0x0c04dfdcu: goto P_0c04dfdc;
case 0x0c04e010u: goto P_0c04e010;
case 0x0c04e012u: goto P_0c04e012;
case 0x0c04e014u: goto P_0c04e014;
case 0x0c04e016u: goto P_0c04e016;
case 0x0c04e018u: goto P_0c04e018;
case 0x0c04e01au: goto P_0c04e01a;
case 0x0c04e01cu: goto P_0c04e01c;
case 0x0c04e01eu: goto P_0c04e01e;
case 0x0c04e020u: goto P_0c04e020;
case 0x0c04e022u: goto P_0c04e022;
case 0x0c04e024u: goto P_0c04e024;
case 0x0c04e026u: goto P_0c04e026;
case 0x0c04e028u: goto P_0c04e028;
case 0x0c04e02au: goto P_0c04e02a;
case 0x0c04e02cu: goto P_0c04e02c;
case 0x0c04e02eu: goto P_0c04e02e;
case 0x0c04e030u: goto P_0c04e030;
case 0x0c04e032u: goto P_0c04e032;
case 0x0c04e034u: goto P_0c04e034;
case 0x0c04e036u: goto P_0c04e036;
case 0x0c04e038u: goto P_0c04e038;
case 0x0c04e03au: goto P_0c04e03a;
case 0x0c04e03cu: goto P_0c04e03c;
case 0x0c04e03eu: goto P_0c04e03e;
case 0x0c04e040u: goto P_0c04e040;
case 0x0c04e042u: goto P_0c04e042;
case 0x0c04e044u: goto P_0c04e044;
case 0x0c04e046u: goto P_0c04e046;
case 0x0c04e048u: goto P_0c04e048;
case 0x0c04e04au: goto P_0c04e04a;
case 0x0c04e04cu: goto P_0c04e04c;
case 0x0c04e04eu: goto P_0c04e04e;
case 0x0c04e050u: goto P_0c04e050;
case 0x0c04e052u: goto P_0c04e052;
case 0x0c04e054u: goto P_0c04e054;
case 0x0c04e056u: goto P_0c04e056;
case 0x0c04e058u: goto P_0c04e058;
case 0x0c04e05au: goto P_0c04e05a;
case 0x0c04e05cu: goto P_0c04e05c;
case 0x0c04e05eu: goto P_0c04e05e;
case 0x0c04e060u: goto P_0c04e060;
case 0x0c04e062u: goto P_0c04e062;
case 0x0c04e064u: goto P_0c04e064;
case 0x0c04e066u: goto P_0c04e066;
case 0x0c04e068u: goto P_0c04e068;
case 0x0c04e06au: goto P_0c04e06a;
case 0x0c04e06cu: goto P_0c04e06c;
case 0x0c04e06eu: goto P_0c04e06e;
case 0x0c04e070u: goto P_0c04e070;
case 0x0c04e072u: goto P_0c04e072;
case 0x0c04e074u: goto P_0c04e074;
case 0x0c04e076u: goto P_0c04e076;
case 0x0c04e078u: goto P_0c04e078;
case 0x0c04e07au: goto P_0c04e07a;
case 0x0c04e07cu: goto P_0c04e07c;
case 0x0c04e07eu: goto P_0c04e07e;
case 0x0c04e080u: goto P_0c04e080;
case 0x0c04e082u: goto P_0c04e082;
case 0x0c04e084u: goto P_0c04e084;
case 0x0c04e086u: goto P_0c04e086;
case 0x0c04e088u: goto P_0c04e088;
case 0x0c04e08au: goto P_0c04e08a;
case 0x0c04e08cu: goto P_0c04e08c;
case 0x0c04e08eu: goto P_0c04e08e;
case 0x0c04e090u: goto P_0c04e090;
case 0x0c04e092u: goto P_0c04e092;
case 0x0c04e094u: goto P_0c04e094;
case 0x0c04e096u: goto P_0c04e096;
case 0x0c04e098u: goto P_0c04e098;
case 0x0c04e09au: goto P_0c04e09a;
case 0x0c04e09cu: goto P_0c04e09c;
case 0x0c04e09eu: goto P_0c04e09e;
case 0x0c04e0a0u: goto P_0c04e0a0;
case 0x0c04e0a2u: goto P_0c04e0a2;
case 0x0c04e0a4u: goto P_0c04e0a4;
case 0x0c04e0a6u: goto P_0c04e0a6;
case 0x0c04e0a8u: goto P_0c04e0a8;
case 0x0c04e0aau: goto P_0c04e0aa;
case 0x0c04e0acu: goto P_0c04e0ac;
case 0x0c04e0aeu: goto P_0c04e0ae;
case 0x0c04e0b0u: goto P_0c04e0b0;
case 0x0c04e0b2u: goto P_0c04e0b2;
case 0x0c04e0b4u: goto P_0c04e0b4;
case 0x0c04e0b6u: goto P_0c04e0b6;
case 0x0c04e0b8u: goto P_0c04e0b8;
case 0x0c04e0bau: goto P_0c04e0ba;
case 0x0c04e0bcu: goto P_0c04e0bc;
case 0x0c04e0beu: goto P_0c04e0be;
case 0x0c04e0c0u: goto P_0c04e0c0;
case 0x0c04e0c2u: goto P_0c04e0c2;
case 0x0c04e0c4u: goto P_0c04e0c4;
case 0x0c04e0c6u: goto P_0c04e0c6;
case 0x0c04e0c8u: goto P_0c04e0c8;
case 0x0c04e0cau: goto P_0c04e0ca;
case 0x0c04e0ccu: goto P_0c04e0cc;
case 0x0c04e0ceu: goto P_0c04e0ce;
case 0x0c04e0d0u: goto P_0c04e0d0;
case 0x0c04e0d2u: goto P_0c04e0d2;
case 0x0c04e0d4u: goto P_0c04e0d4;
case 0x0c04e0d6u: goto P_0c04e0d6;
case 0x0c04e0d8u: goto P_0c04e0d8;
case 0x0c04e0dau: goto P_0c04e0da;
case 0x0c04e0dcu: goto P_0c04e0dc;
case 0x0c04e0deu: goto P_0c04e0de;
case 0x0c04e0e0u: goto P_0c04e0e0;
case 0x0c04e0e2u: goto P_0c04e0e2;
case 0x0c04e0e4u: goto P_0c04e0e4;
case 0x0c04e0e6u: goto P_0c04e0e6;
case 0x0c04e124u: goto P_0c04e124;
case 0x0c04e126u: goto P_0c04e126;
case 0x0c04e128u: goto P_0c04e128;
case 0x0c04e12au: goto P_0c04e12a;
case 0x0c04e12cu: goto P_0c04e12c;
case 0x0c04e12eu: goto P_0c04e12e;
case 0x0c04e130u: goto P_0c04e130;
case 0x0c04e132u: goto P_0c04e132;
case 0x0c04e134u: goto P_0c04e134;
case 0x0c04e136u: goto P_0c04e136;
case 0x0c04e138u: goto P_0c04e138;
case 0x0c04e13au: goto P_0c04e13a;
case 0x0c04e13cu: goto P_0c04e13c;
case 0x0c04e13eu: goto P_0c04e13e;
case 0x0c04e140u: goto P_0c04e140;
case 0x0c04e142u: goto P_0c04e142;
case 0x0c04e144u: goto P_0c04e144;
case 0x0c04e146u: goto P_0c04e146;
case 0x0c04e148u: goto P_0c04e148;
case 0x0c04e14au: goto P_0c04e14a;
case 0x0c04e14cu: goto P_0c04e14c;
case 0x0c04e14eu: goto P_0c04e14e;
case 0x0c04e150u: goto P_0c04e150;
case 0x0c04e152u: goto P_0c04e152;
case 0x0c04e154u: goto P_0c04e154;
case 0x0c04e156u: goto P_0c04e156;
case 0x0c04e158u: goto P_0c04e158;
case 0x0c04e15au: goto P_0c04e15a;
case 0x0c04e15cu: goto P_0c04e15c;
case 0x0c04e15eu: goto P_0c04e15e;
case 0x0c04e160u: goto P_0c04e160;
case 0x0c04e162u: goto P_0c04e162;
case 0x0c04e164u: goto P_0c04e164;
case 0x0c04e166u: goto P_0c04e166;
case 0x0c04e168u: goto P_0c04e168;
case 0x0c04e16au: goto P_0c04e16a;
case 0x0c04e16cu: goto P_0c04e16c;
case 0x0c04e16eu: goto P_0c04e16e;
default: return vf3_matrix_family(target,s,ram);
}
P_0c04df5a: /* original 2fe6, guest PC 0x0c04df5a */
if(!s->budget--) { s->failed_pc=0x0c04df5au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df5c;
P_0c04df5c: /* original 6e43, guest PC 0x0c04df5c */
if(!s->budget--) { s->failed_pc=0x0c04df5cu; return 0; }
r[14]=r[4];
goto P_0c04df5e;
P_0c04df5e: /* original 2fd6, guest PC 0x0c04df5e */
if(!s->budget--) { s->failed_pc=0x0c04df5eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df60;
P_0c04df60: /* original 2ee8, guest PC 0x0c04df60 */
if(!s->budget--) { s->failed_pc=0x0c04df60u; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c04df62;
P_0c04df62: /* original 2fc6, guest PC 0x0c04df62 */
if(!s->budget--) { s->failed_pc=0x0c04df62u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df64;
P_0c04df64: /* original 2fb6, guest PC 0x0c04df64 */
if(!s->budget--) { s->failed_pc=0x0c04df64u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df66;
P_0c04df66: /* original 2fa6, guest PC 0x0c04df66 */
if(!s->budget--) { s->failed_pc=0x0c04df66u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df68;
P_0c04df68: /* original 2f96, guest PC 0x0c04df68 */
if(!s->budget--) { s->failed_pc=0x0c04df68u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04df6a;
P_0c04df6a: /* original 4f22, guest PC 0x0c04df6a */
if(!s->budget--) { s->failed_pc=0x0c04df6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04df6c;
P_0c04df6c: /* original 4f12, guest PC 0x0c04df6c */
if(!s->budget--) { s->failed_pc=0x0c04df6cu; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04df6e;
P_0c04df6e: /* original 8f03, guest PC 0x0c04df6e */
if(!s->budget--) { s->failed_pc=0x0c04df6eu; return 0; }
cond=r[17]&1u;
r[11]=r[6];
if(!cond) { goto P_0c04df78; }
goto P_0c04df72;
P_0c04df70: /* original 6b63, guest PC 0x0c04df70 */
if(!s->budget--) { s->failed_pc=0x0c04df70u; return 0; }
r[11]=r[6];
goto P_0c04df72;
P_0c04df72: /* original 9034, guest PC 0x0c04df72 */
if(!s->budget--) { s->failed_pc=0x0c04df72u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfdeu,2);
goto P_0c04df74;
P_0c04df74: /* original a051, guest PC 0x0c04df74 */
if(!s->budget--) { s->failed_pc=0x0c04df74u; return 0; }
goto P_0c04e01a;
P_0c04df76: /* original 0009, guest PC 0x0c04df76 */
if(!s->budget--) { s->failed_pc=0x0c04df76u; return 0; }
goto P_0c04df78;
P_0c04df78: /* original 9332, guest PC 0x0c04df78 */
if(!s->budget--) { s->failed_pc=0x0c04df78u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe0u,2);
goto P_0c04df7a;
P_0c04df7a: /* original 52ea, guest PC 0x0c04df7a */
if(!s->budget--) { s->failed_pc=0x0c04df7au; return 0; }
r[2]=read(ram,r[14]+40,4);
goto P_0c04df7c;
P_0c04df7c: /* original d421, guest PC 0x0c04df7c */
if(!s->budget--) { s->failed_pc=0x0c04df7cu; return 0; }
r[4]=read(ram,0x0c04e004u,4);
goto P_0c04df7e;
P_0c04df7e: /* original 223f, guest PC 0x0c04df7e */
if(!s->budget--) { s->failed_pc=0x0c04df7eu; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[2]*(int32_t)(int16_t)r[3]);
goto P_0c04df80;
P_0c04df80: /* original 021a, guest PC 0x0c04df80 */
if(!s->budget--) { s->failed_pc=0x0c04df80u; return 0; }
r[2]=r[19];
goto P_0c04df82;
P_0c04df82: /* original 622f, guest PC 0x0c04df82 */
if(!s->budget--) { s->failed_pc=0x0c04df82u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)r[2];
goto P_0c04df84;
P_0c04df84: /* original 324c, guest PC 0x0c04df84 */
if(!s->budget--) { s->failed_pc=0x0c04df84u; return 0; }
r[2]+=r[4];
goto P_0c04df86;
P_0c04df86: /* original 8422, guest PC 0x0c04df86 */
if(!s->budget--) { s->failed_pc=0x0c04df86u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+2,1);
goto P_0c04df88;
P_0c04df88: /* original 2008, guest PC 0x0c04df88 */
if(!s->budget--) { s->failed_pc=0x0c04df88u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04df8a;
P_0c04df8a: /* original 8b02, guest PC 0x0c04df8a */
if(!s->budget--) { s->failed_pc=0x0c04df8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04df92; }
goto P_0c04df8c;
P_0c04df8c: /* original 9029, guest PC 0x0c04df8c */
if(!s->budget--) { s->failed_pc=0x0c04df8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe2u,2);
goto P_0c04df8e;
P_0c04df8e: /* original a044, guest PC 0x0c04df8e */
if(!s->budget--) { s->failed_pc=0x0c04df8eu; return 0; }
goto P_0c04e01a;
P_0c04df90: /* original 0009, guest PC 0x0c04df90 */
if(!s->budget--) { s->failed_pc=0x0c04df90u; return 0; }
goto P_0c04df92;
P_0c04df92: /* original 50e1, guest PC 0x0c04df92 */
if(!s->budget--) { s->failed_pc=0x0c04df92u; return 0; }
r[0]=read(ram,r[14]+4,4);
goto P_0c04df94;
P_0c04df94: /* original 8801, guest PC 0x0c04df94 */
if(!s->budget--) { s->failed_pc=0x0c04df94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c04df96;
P_0c04df96: /* original 8903, guest PC 0x0c04df96 */
if(!s->budget--) { s->failed_pc=0x0c04df96u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dfa0; }
goto P_0c04df98;
P_0c04df98: /* original 8802, guest PC 0x0c04df98 */
if(!s->budget--) { s->failed_pc=0x0c04df98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c04df9a;
P_0c04df9a: /* original 8904, guest PC 0x0c04df9a */
if(!s->budget--) { s->failed_pc=0x0c04df9au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04dfa6; }
goto P_0c04df9c;
P_0c04df9c: /* original a006, guest PC 0x0c04df9c */
if(!s->budget--) { s->failed_pc=0x0c04df9cu; return 0; }
goto P_0c04dfac;
P_0c04df9e: /* original 0009, guest PC 0x0c04df9e */
if(!s->budget--) { s->failed_pc=0x0c04df9eu; return 0; }
goto P_0c04dfa0;
P_0c04dfa0: /* original da19, guest PC 0x0c04dfa0 */
if(!s->budget--) { s->failed_pc=0x0c04dfa0u; return 0; }
r[10]=read(ram,0x0c04e008u,4);
goto P_0c04dfa2;
P_0c04dfa2: /* original a006, guest PC 0x0c04dfa2 */
if(!s->budget--) { s->failed_pc=0x0c04dfa2u; return 0; }
goto P_0c04dfb2;
P_0c04dfa4: /* original 0009, guest PC 0x0c04dfa4 */
if(!s->budget--) { s->failed_pc=0x0c04dfa4u; return 0; }
goto P_0c04dfa6;
P_0c04dfa6: /* original da19, guest PC 0x0c04dfa6 */
if(!s->budget--) { s->failed_pc=0x0c04dfa6u; return 0; }
r[10]=read(ram,0x0c04e00cu,4);
goto P_0c04dfa8;
P_0c04dfa8: /* original a003, guest PC 0x0c04dfa8 */
if(!s->budget--) { s->failed_pc=0x0c04dfa8u; return 0; }
goto P_0c04dfb2;
P_0c04dfaa: /* original 0009, guest PC 0x0c04dfaa */
if(!s->budget--) { s->failed_pc=0x0c04dfaau; return 0; }
goto P_0c04dfac;
P_0c04dfac: /* original 901a, guest PC 0x0c04dfac */
if(!s->budget--) { s->failed_pc=0x0c04dfacu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe4u,2);
goto P_0c04dfae;
P_0c04dfae: /* original a034, guest PC 0x0c04dfae */
if(!s->budget--) { s->failed_pc=0x0c04dfaeu; return 0; }
goto P_0c04e01a;
P_0c04dfb0: /* original 0009, guest PC 0x0c04dfb0 */
if(!s->budget--) { s->failed_pc=0x0c04dfb0u; return 0; }
goto P_0c04dfb2;
P_0c04dfb2: /* original 9215, guest PC 0x0c04dfb2 */
if(!s->budget--) { s->failed_pc=0x0c04dfb2u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe0u,2);
goto P_0c04dfb4;
P_0c04dfb4: /* original 4b15, guest PC 0x0c04dfb4 */
if(!s->budget--) { s->failed_pc=0x0c04dfb4u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>0)!=0);
goto P_0c04dfb6;
P_0c04dfb6: /* original 53ea, guest PC 0x0c04dfb6 */
if(!s->budget--) { s->failed_pc=0x0c04dfb6u; return 0; }
r[3]=read(ram,r[14]+40,4);
goto P_0c04dfb8;
P_0c04dfb8: /* original 6d53, guest PC 0x0c04dfb8 */
if(!s->budget--) { s->failed_pc=0x0c04dfb8u; return 0; }
r[13]=r[5];
goto P_0c04dfba;
P_0c04dfba: /* original 232f, guest PC 0x0c04dfba */
if(!s->budget--) { s->failed_pc=0x0c04dfbau; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04dfbc;
P_0c04dfbc: /* original 031a, guest PC 0x0c04dfbc */
if(!s->budget--) { s->failed_pc=0x0c04dfbcu; return 0; }
r[3]=r[19];
goto P_0c04dfbe;
P_0c04dfbe: /* original 633f, guest PC 0x0c04dfbe */
if(!s->budget--) { s->failed_pc=0x0c04dfbeu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04dfc0;
P_0c04dfc0: /* original 343c, guest PC 0x0c04dfc0 */
if(!s->budget--) { s->failed_pc=0x0c04dfc0u; return 0; }
r[4]+=r[3];
goto P_0c04dfc2;
P_0c04dfc2: /* original e301, guest PC 0x0c04dfc2 */
if(!s->budget--) { s->failed_pc=0x0c04dfc2u; return 0; }
r[3]=0x00000001u;
goto P_0c04dfc4;
P_0c04dfc4: /* original 143c, guest PC 0x0c04dfc4 */
if(!s->budget--) { s->failed_pc=0x0c04dfc4u; return 0; }
write(ram,r[4]+48,r[3],4);
goto P_0c04dfc6;
P_0c04dfc6: /* original 14bd, guest PC 0x0c04dfc6 */
if(!s->budget--) { s->failed_pc=0x0c04dfc6u; return 0; }
write(ram,r[4]+52,r[11],4);
goto P_0c04dfc8;
P_0c04dfc8: /* original 990d, guest PC 0x0c04dfc8 */
if(!s->budget--) { s->failed_pc=0x0c04dfc8u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04dfe6u,2);
goto P_0c04dfca;
P_0c04dfca: /* original 8f25, guest PC 0x0c04dfca */
if(!s->budget--) { s->failed_pc=0x0c04dfcau; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(!cond) { goto P_0c04e018; }
goto P_0c04dfce;
P_0c04dfcc: /* original ec00, guest PC 0x0c04dfcc */
if(!s->budget--) { s->failed_pc=0x0c04dfccu; return 0; }
r[12]=0x00000000u;
goto P_0c04dfce;
P_0c04dfce: /* original 65d3, guest PC 0x0c04dfce */
if(!s->budget--) { s->failed_pc=0x0c04dfceu; return 0; }
r[5]=r[13];
goto P_0c04dfd0;
P_0c04dfd0: /* original 4a0b, guest PC 0x0c04dfd0 */
if(!s->budget--) { s->failed_pc=0x0c04dfd0u; return 0; }
target=r[10];
r[16]=code_base|0x0c04dfd4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04dfd4u) { target=s->pc; goto dispatch; }
goto P_0c04dfd4;
P_0c04dfd2: /* original 64e3, guest PC 0x0c04dfd2 */
if(!s->budget--) { s->failed_pc=0x0c04dfd2u; return 0; }
r[4]=r[14];
goto P_0c04dfd4;
P_0c04dfd4: /* original 6403, guest PC 0x0c04dfd4 */
if(!s->budget--) { s->failed_pc=0x0c04dfd4u; return 0; }
r[4]=r[0];
goto P_0c04dfd6;
P_0c04dfd6: /* original 4411, guest PC 0x0c04dfd6 */
if(!s->budget--) { s->failed_pc=0x0c04dfd6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04dfd8;
P_0c04dfd8: /* original 891a, guest PC 0x0c04dfd8 */
if(!s->budget--) { s->failed_pc=0x0c04dfd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e010; }
goto P_0c04dfda;
P_0c04dfda: /* original a01e, guest PC 0x0c04dfda */
if(!s->budget--) { s->failed_pc=0x0c04dfdau; return 0; }
r[0]=r[4];
goto P_0c04e01a;
P_0c04dfdc: /* original 6043, guest PC 0x0c04dfdc */
if(!s->budget--) { s->failed_pc=0x0c04dfdcu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c04dfdeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04dfdeu; return 0; } return 1;
P_0c04e010: /* original 7c01, guest PC 0x0c04e010 */
if(!s->budget--) { s->failed_pc=0x0c04e010u; return 0; }
r[12]+=0x00000001u;
goto P_0c04e012;
P_0c04e012: /* original 3cb3, guest PC 0x0c04e012 */
if(!s->budget--) { s->failed_pc=0x0c04e012u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[11])!=0);
goto P_0c04e014;
P_0c04e014: /* original 8fdb, guest PC 0x0c04e014 */
if(!s->budget--) { s->failed_pc=0x0c04e014u; return 0; }
cond=r[17]&1u;
r[13]+=r[9];
if(!cond) { goto P_0c04dfce; }
goto P_0c04e018;
P_0c04e016: /* original 3d9c, guest PC 0x0c04e016 */
if(!s->budget--) { s->failed_pc=0x0c04e016u; return 0; }
r[13]+=r[9];
goto P_0c04e018;
P_0c04e018: /* original e000, guest PC 0x0c04e018 */
if(!s->budget--) { s->failed_pc=0x0c04e018u; return 0; }
r[0]=0x00000000u;
goto P_0c04e01a;
P_0c04e01a: /* original 4f16, guest PC 0x0c04e01a */
if(!s->budget--) { s->failed_pc=0x0c04e01au; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e01c;
P_0c04e01c: /* original 4f26, guest PC 0x0c04e01c */
if(!s->budget--) { s->failed_pc=0x0c04e01cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e01e;
P_0c04e01e: /* original 69f6, guest PC 0x0c04e01e */
if(!s->budget--) { s->failed_pc=0x0c04e01eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e020;
P_0c04e020: /* original 6af6, guest PC 0x0c04e020 */
if(!s->budget--) { s->failed_pc=0x0c04e020u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e022;
P_0c04e022: /* original 6bf6, guest PC 0x0c04e022 */
if(!s->budget--) { s->failed_pc=0x0c04e022u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e024;
P_0c04e024: /* original 6cf6, guest PC 0x0c04e024 */
if(!s->budget--) { s->failed_pc=0x0c04e024u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e026;
P_0c04e026: /* original 6df6, guest PC 0x0c04e026 */
if(!s->budget--) { s->failed_pc=0x0c04e026u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e028;
P_0c04e028: /* original 000b, guest PC 0x0c04e028 */
if(!s->budget--) { s->failed_pc=0x0c04e028u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e02a: /* original 6ef6, guest PC 0x0c04e02a */
if(!s->budget--) { s->failed_pc=0x0c04e02au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c04e02c;
P_0c04e02c: /* original 2fe6, guest PC 0x0c04e02c */
if(!s->budget--) { s->failed_pc=0x0c04e02cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e02e;
P_0c04e02e: /* original 2fd6, guest PC 0x0c04e02e */
if(!s->budget--) { s->failed_pc=0x0c04e02eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e030;
P_0c04e030: /* original 6d43, guest PC 0x0c04e030 */
if(!s->budget--) { s->failed_pc=0x0c04e030u; return 0; }
r[13]=r[4];
goto P_0c04e032;
P_0c04e032: /* original 2fc6, guest PC 0x0c04e032 */
if(!s->budget--) { s->failed_pc=0x0c04e032u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e034;
P_0c04e034: /* original 2fb6, guest PC 0x0c04e034 */
if(!s->budget--) { s->failed_pc=0x0c04e034u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e036;
P_0c04e036: /* original 2fa6, guest PC 0x0c04e036 */
if(!s->budget--) { s->failed_pc=0x0c04e036u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e038;
P_0c04e038: /* original 2f96, guest PC 0x0c04e038 */
if(!s->budget--) { s->failed_pc=0x0c04e038u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e03a;
P_0c04e03a: /* original 2f86, guest PC 0x0c04e03a */
if(!s->budget--) { s->failed_pc=0x0c04e03au; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e03c;
P_0c04e03c: /* original 6853, guest PC 0x0c04e03c */
if(!s->budget--) { s->failed_pc=0x0c04e03cu; return 0; }
r[8]=r[5];
goto P_0c04e03e;
P_0c04e03e: /* original 4f22, guest PC 0x0c04e03e */
if(!s->budget--) { s->failed_pc=0x0c04e03eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c04e040;
P_0c04e040: /* original d32b, guest PC 0x0c04e040 */
if(!s->budget--) { s->failed_pc=0x0c04e040u; return 0; }
r[3]=read(ram,0x0c04e0f0u,4);
goto P_0c04e042;
P_0c04e042: /* original d22c, guest PC 0x0c04e042 */
if(!s->budget--) { s->failed_pc=0x0c04e042u; return 0; }
r[2]=read(ram,0x0c04e0f4u,4);
goto P_0c04e044;
P_0c04e044: /* original 4f12, guest PC 0x0c04e044 */
if(!s->budget--) { s->failed_pc=0x0c04e044u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c04e046;
P_0c04e046: /* original 420b, guest PC 0x0c04e046 */
if(!s->budget--) { s->failed_pc=0x0c04e046u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e04au;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e04au) { target=s->pc; goto dispatch; }
goto P_0c04e04a;
P_0c04e048: /* original 2f36, guest PC 0x0c04e048 */
if(!s->budget--) { s->failed_pc=0x0c04e048u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e04a;
P_0c04e04a: /* original d32b, guest PC 0x0c04e04a */
if(!s->budget--) { s->failed_pc=0x0c04e04au; return 0; }
r[3]=read(ram,0x0c04e0f8u,4);
goto P_0c04e04c;
P_0c04e04c: /* original 7f04, guest PC 0x0c04e04c */
if(!s->budget--) { s->failed_pc=0x0c04e04cu; return 0; }
r[15]+=0x00000004u;
goto P_0c04e04e;
P_0c04e04e: /* original 430b, guest PC 0x0c04e04e */
if(!s->budget--) { s->failed_pc=0x0c04e04eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e052u;
r[4]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e052u) { target=s->pc; goto dispatch; }
goto P_0c04e052;
P_0c04e050: /* original 54da, guest PC 0x0c04e050 */
if(!s->budget--) { s->failed_pc=0x0c04e050u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e052;
P_0c04e052: /* original 2008, guest PC 0x0c04e052 */
if(!s->budget--) { s->failed_pc=0x0c04e052u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e054;
P_0c04e054: /* original 8b04, guest PC 0x0c04e054 */
if(!s->budget--) { s->failed_pc=0x0c04e054u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e060; }
goto P_0c04e056;
P_0c04e056: /* original d329, guest PC 0x0c04e056 */
if(!s->budget--) { s->failed_pc=0x0c04e056u; return 0; }
r[3]=read(ram,0x0c04e0fcu,4);
goto P_0c04e058;
P_0c04e058: /* original 430b, guest PC 0x0c04e058 */
if(!s->budget--) { s->failed_pc=0x0c04e058u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e05cu;
r[4]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e05cu) { target=s->pc; goto dispatch; }
goto P_0c04e05c;
P_0c04e05a: /* original 54da, guest PC 0x0c04e05a */
if(!s->budget--) { s->failed_pc=0x0c04e05au; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e05c;
P_0c04e05c: /* original a00e, guest PC 0x0c04e05c */
if(!s->budget--) { s->failed_pc=0x0c04e05cu; return 0; }
goto P_0c04e07c;
P_0c04e05e: /* original 0009, guest PC 0x0c04e05e */
if(!s->budget--) { s->failed_pc=0x0c04e05eu; return 0; }
goto P_0c04e060;
P_0c04e060: /* original d227, guest PC 0x0c04e060 */
if(!s->budget--) { s->failed_pc=0x0c04e060u; return 0; }
r[2]=read(ram,0x0c04e100u,4);
goto P_0c04e062;
P_0c04e062: /* original 420b, guest PC 0x0c04e062 */
if(!s->budget--) { s->failed_pc=0x0c04e062u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e066u;
r[4]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e066u) { target=s->pc; goto dispatch; }
goto P_0c04e066;
P_0c04e064: /* original 54da, guest PC 0x0c04e064 */
if(!s->budget--) { s->failed_pc=0x0c04e064u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e066;
P_0c04e066: /* original 2008, guest PC 0x0c04e066 */
if(!s->budget--) { s->failed_pc=0x0c04e066u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c04e068;
P_0c04e068: /* original 8908, guest PC 0x0c04e068 */
if(!s->budget--) { s->failed_pc=0x0c04e068u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e07c; }
goto P_0c04e06a;
P_0c04e06a: /* original 923d, guest PC 0x0c04e06a */
if(!s->budget--) { s->failed_pc=0x0c04e06au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0e8u,2);
goto P_0c04e06c;
P_0c04e06c: /* original 53da, guest PC 0x0c04e06c */
if(!s->budget--) { s->failed_pc=0x0c04e06cu; return 0; }
r[3]=read(ram,r[13]+40,4);
goto P_0c04e06e;
P_0c04e06e: /* original d025, guest PC 0x0c04e06e */
if(!s->budget--) { s->failed_pc=0x0c04e06eu; return 0; }
r[0]=read(ram,0x0c04e104u,4);
goto P_0c04e070;
P_0c04e070: /* original 232f, guest PC 0x0c04e070 */
if(!s->budget--) { s->failed_pc=0x0c04e070u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[3]*(int32_t)(int16_t)r[2]);
goto P_0c04e072;
P_0c04e072: /* original 031a, guest PC 0x0c04e072 */
if(!s->budget--) { s->failed_pc=0x0c04e072u; return 0; }
r[3]=r[19];
goto P_0c04e074;
P_0c04e074: /* original 633f, guest PC 0x0c04e074 */
if(!s->budget--) { s->failed_pc=0x0c04e074u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)r[3];
goto P_0c04e076;
P_0c04e076: /* original 013c, guest PC 0x0c04e076 */
if(!s->budget--) { s->failed_pc=0x0c04e076u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c04e078;
P_0c04e078: /* original 2118, guest PC 0x0c04e078 */
if(!s->budget--) { s->failed_pc=0x0c04e078u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c04e07a;
P_0c04e07a: /* original 8b02, guest PC 0x0c04e07a */
if(!s->budget--) { s->failed_pc=0x0c04e07au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e082; }
goto P_0c04e07c;
P_0c04e07c: /* original 9035, guest PC 0x0c04e07c */
if(!s->budget--) { s->failed_pc=0x0c04e07cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0eau,2);
goto P_0c04e07e;
P_0c04e07e: /* original a06d, guest PC 0x0c04e07e */
if(!s->budget--) { s->failed_pc=0x0c04e07eu; return 0; }
goto P_0c04e15c;
P_0c04e080: /* original 0009, guest PC 0x0c04e080 */
if(!s->budget--) { s->failed_pc=0x0c04e080u; return 0; }
goto P_0c04e082;
P_0c04e082: /* original d321, guest PC 0x0c04e082 */
if(!s->budget--) { s->failed_pc=0x0c04e082u; return 0; }
r[3]=read(ram,0x0c04e108u,4);
goto P_0c04e084;
P_0c04e084: /* original 430b, guest PC 0x0c04e084 */
if(!s->budget--) { s->failed_pc=0x0c04e084u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e088u;
r[4]=read(ram,r[13]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e088u) { target=s->pc; goto dispatch; }
goto P_0c04e088;
P_0c04e086: /* original 54da, guest PC 0x0c04e086 */
if(!s->budget--) { s->failed_pc=0x0c04e086u; return 0; }
r[4]=read(ram,r[13]+40,4);
goto P_0c04e088;
P_0c04e088: /* original 4011, guest PC 0x0c04e088 */
if(!s->budget--) { s->failed_pc=0x0c04e088u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=0)!=0);
goto P_0c04e08a;
P_0c04e08a: /* original 8902, guest PC 0x0c04e08a */
if(!s->budget--) { s->failed_pc=0x0c04e08au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e092; }
goto P_0c04e08c;
P_0c04e08c: /* original 902e, guest PC 0x0c04e08c */
if(!s->budget--) { s->failed_pc=0x0c04e08cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0ecu,2);
goto P_0c04e08e;
P_0c04e08e: /* original a065, guest PC 0x0c04e08e */
if(!s->budget--) { s->failed_pc=0x0c04e08eu; return 0; }
goto P_0c04e15c;
P_0c04e090: /* original 0009, guest PC 0x0c04e090 */
if(!s->budget--) { s->failed_pc=0x0c04e090u; return 0; }
goto P_0c04e092;
P_0c04e092: /* original da1e, guest PC 0x0c04e092 */
if(!s->budget--) { s->failed_pc=0x0c04e092u; return 0; }
r[10]=read(ram,0x0c04e10cu,4);
goto P_0c04e094;
P_0c04e094: /* original d31e, guest PC 0x0c04e094 */
if(!s->budget--) { s->failed_pc=0x0c04e094u; return 0; }
r[3]=read(ram,0x0c04e110u,4);
goto P_0c04e096;
P_0c04e096: /* original 5cda, guest PC 0x0c04e096 */
if(!s->budget--) { s->failed_pc=0x0c04e096u; return 0; }
r[12]=read(ram,r[13]+40,4);
goto P_0c04e098;
P_0c04e098: /* original 65a3, guest PC 0x0c04e098 */
if(!s->budget--) { s->failed_pc=0x0c04e098u; return 0; }
r[5]=r[10];
goto P_0c04e09a;
P_0c04e09a: /* original 430b, guest PC 0x0c04e09a */
if(!s->budget--) { s->failed_pc=0x0c04e09au; return 0; }
target=r[3];
r[16]=code_base|0x0c04e09eu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e09eu) { target=s->pc; goto dispatch; }
goto P_0c04e09e;
P_0c04e09c: /* original 64c3, guest PC 0x0c04e09c */
if(!s->budget--) { s->failed_pc=0x0c04e09cu; return 0; }
r[4]=r[12];
goto P_0c04e09e;
P_0c04e09e: /* original 6e03, guest PC 0x0c04e09e */
if(!s->budget--) { s->failed_pc=0x0c04e09eu; return 0; }
r[14]=r[0];
goto P_0c04e0a0;
P_0c04e0a0: /* original 4e11, guest PC 0x0c04e0a0 */
if(!s->budget--) { s->failed_pc=0x0c04e0a0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c04e0a2;
P_0c04e0a2: /* original 8b1e, guest PC 0x0c04e0a2 */
if(!s->budget--) { s->failed_pc=0x0c04e0a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e0e2; }
goto P_0c04e0a4;
P_0c04e0a4: /* original d91b, guest PC 0x0c04e0a4 */
if(!s->budget--) { s->failed_pc=0x0c04e0a4u; return 0; }
r[9]=read(ram,0x0c04e114u,4);
goto P_0c04e0a6;
P_0c04e0a6: /* original 65e3, guest PC 0x0c04e0a6 */
if(!s->budget--) { s->failed_pc=0x0c04e0a6u; return 0; }
r[5]=r[14];
goto P_0c04e0a8;
P_0c04e0a8: /* original 6683, guest PC 0x0c04e0a8 */
if(!s->budget--) { s->failed_pc=0x0c04e0a8u; return 0; }
r[6]=r[8];
goto P_0c04e0aa;
P_0c04e0aa: /* original 490b, guest PC 0x0c04e0aa */
if(!s->budget--) { s->failed_pc=0x0c04e0aau; return 0; }
target=r[9];
r[16]=code_base|0x0c04e0aeu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e0aeu) { target=s->pc; goto dispatch; }
goto P_0c04e0ae;
P_0c04e0ac: /* original 64c3, guest PC 0x0c04e0ac */
if(!s->budget--) { s->failed_pc=0x0c04e0acu; return 0; }
r[4]=r[12];
goto P_0c04e0ae;
P_0c04e0ae: /* original db1a, guest PC 0x0c04e0ae */
if(!s->budget--) { s->failed_pc=0x0c04e0aeu; return 0; }
r[11]=read(ram,0x0c04e118u,4);
goto P_0c04e0b0;
P_0c04e0b0: /* original 6403, guest PC 0x0c04e0b0 */
if(!s->budget--) { s->failed_pc=0x0c04e0b0u; return 0; }
r[4]=r[0];
goto P_0c04e0b2;
P_0c04e0b2: /* original 4411, guest PC 0x0c04e0b2 */
if(!s->budget--) { s->failed_pc=0x0c04e0b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=0)!=0);
goto P_0c04e0b4;
P_0c04e0b4: /* original 893d, guest PC 0x0c04e0b4 */
if(!s->budget--) { s->failed_pc=0x0c04e0b4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e132; }
goto P_0c04e0b6;
P_0c04e0b6: /* original 9318, guest PC 0x0c04e0b6 */
if(!s->budget--) { s->failed_pc=0x0c04e0b6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0eau,2);
goto P_0c04e0b8;
P_0c04e0b8: /* original 3430, guest PC 0x0c04e0b8 */
if(!s->budget--) { s->failed_pc=0x0c04e0b8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[3])!=0);
goto P_0c04e0ba;
P_0c04e0ba: /* original 8b01, guest PC 0x0c04e0ba */
if(!s->budget--) { s->failed_pc=0x0c04e0bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e0c0; }
goto P_0c04e0bc;
P_0c04e0bc: /* original a04e, guest PC 0x0c04e0bc */
if(!s->budget--) { s->failed_pc=0x0c04e0bcu; return 0; }
r[0]=r[4];
goto P_0c04e15c;
P_0c04e0be: /* original 6043, guest PC 0x0c04e0be */
if(!s->budget--) { s->failed_pc=0x0c04e0beu; return 0; }
r[0]=r[4];
goto P_0c04e0c0;
P_0c04e0c0: /* original d20c, guest PC 0x0c04e0c0 */
if(!s->budget--) { s->failed_pc=0x0c04e0c0u; return 0; }
r[2]=read(ram,0x0c04e0f4u,4);
goto P_0c04e0c2;
P_0c04e0c2: /* original d316, guest PC 0x0c04e0c2 */
if(!s->budget--) { s->failed_pc=0x0c04e0c2u; return 0; }
r[3]=read(ram,0x0c04e11cu,4);
goto P_0c04e0c4;
P_0c04e0c4: /* original 420b, guest PC 0x0c04e0c4 */
if(!s->budget--) { s->failed_pc=0x0c04e0c4u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e0c8u;
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e0c8u) { target=s->pc; goto dispatch; }
goto P_0c04e0c8;
P_0c04e0c6: /* original 2f36, guest PC 0x0c04e0c6 */
if(!s->budget--) { s->failed_pc=0x0c04e0c6u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c04e0c8;
P_0c04e0c8: /* original 7f04, guest PC 0x0c04e0c8 */
if(!s->budget--) { s->failed_pc=0x0c04e0c8u; return 0; }
r[15]+=0x00000004u;
goto P_0c04e0ca;
P_0c04e0ca: /* original d315, guest PC 0x0c04e0ca */
if(!s->budget--) { s->failed_pc=0x0c04e0cau; return 0; }
r[3]=read(ram,0x0c04e120u,4);
goto P_0c04e0cc;
P_0c04e0cc: /* original 65e3, guest PC 0x0c04e0cc */
if(!s->budget--) { s->failed_pc=0x0c04e0ccu; return 0; }
r[5]=r[14];
goto P_0c04e0ce;
P_0c04e0ce: /* original 66b3, guest PC 0x0c04e0ce */
if(!s->budget--) { s->failed_pc=0x0c04e0ceu; return 0; }
r[6]=r[11];
goto P_0c04e0d0;
P_0c04e0d0: /* original 430b, guest PC 0x0c04e0d0 */
if(!s->budget--) { s->failed_pc=0x0c04e0d0u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e0d4u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e0d4u) { target=s->pc; goto dispatch; }
goto P_0c04e0d4;
P_0c04e0d2: /* original 64c3, guest PC 0x0c04e0d2 */
if(!s->budget--) { s->failed_pc=0x0c04e0d2u; return 0; }
r[4]=r[12];
goto P_0c04e0d4;
P_0c04e0d4: /* original d20e, guest PC 0x0c04e0d4 */
if(!s->budget--) { s->failed_pc=0x0c04e0d4u; return 0; }
r[2]=read(ram,0x0c04e110u,4);
goto P_0c04e0d6;
P_0c04e0d6: /* original 65a3, guest PC 0x0c04e0d6 */
if(!s->budget--) { s->failed_pc=0x0c04e0d6u; return 0; }
r[5]=r[10];
goto P_0c04e0d8;
P_0c04e0d8: /* original 420b, guest PC 0x0c04e0d8 */
if(!s->budget--) { s->failed_pc=0x0c04e0d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c04e0dcu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e0dcu) { target=s->pc; goto dispatch; }
goto P_0c04e0dc;
P_0c04e0da: /* original 64c3, guest PC 0x0c04e0da */
if(!s->budget--) { s->failed_pc=0x0c04e0dau; return 0; }
r[4]=r[12];
goto P_0c04e0dc;
P_0c04e0dc: /* original 6e03, guest PC 0x0c04e0dc */
if(!s->budget--) { s->failed_pc=0x0c04e0dcu; return 0; }
r[14]=r[0];
goto P_0c04e0de;
P_0c04e0de: /* original 4e11, guest PC 0x0c04e0de */
if(!s->budget--) { s->failed_pc=0x0c04e0deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>=0)!=0);
goto P_0c04e0e0;
P_0c04e0e0: /* original 8920, guest PC 0x0c04e0e0 */
if(!s->budget--) { s->failed_pc=0x0c04e0e0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c04e124; }
goto P_0c04e0e2;
P_0c04e0e2: /* original 9004, guest PC 0x0c04e0e2 */
if(!s->budget--) { s->failed_pc=0x0c04e0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c04e0eeu,2);
goto P_0c04e0e4;
P_0c04e0e4: /* original a03a, guest PC 0x0c04e0e4 */
if(!s->budget--) { s->failed_pc=0x0c04e0e4u; return 0; }
goto P_0c04e15c;
P_0c04e0e6: /* original 0009, guest PC 0x0c04e0e6 */
if(!s->budget--) { s->failed_pc=0x0c04e0e6u; return 0; }
if(!vf3_matrix_family(0x0c04e0e8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c04e0e8u; return 0; } return 1;
P_0c04e124: /* original 65e3, guest PC 0x0c04e124 */
if(!s->budget--) { s->failed_pc=0x0c04e124u; return 0; }
r[5]=r[14];
goto P_0c04e126;
P_0c04e126: /* original 6683, guest PC 0x0c04e126 */
if(!s->budget--) { s->failed_pc=0x0c04e126u; return 0; }
r[6]=r[8];
goto P_0c04e128;
P_0c04e128: /* original 490b, guest PC 0x0c04e128 */
if(!s->budget--) { s->failed_pc=0x0c04e128u; return 0; }
target=r[9];
r[16]=code_base|0x0c04e12cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e12cu) { target=s->pc; goto dispatch; }
goto P_0c04e12c;
P_0c04e12a: /* original 64c3, guest PC 0x0c04e12a */
if(!s->budget--) { s->failed_pc=0x0c04e12au; return 0; }
r[4]=r[12];
goto P_0c04e12c;
P_0c04e12c: /* original 6403, guest PC 0x0c04e12c */
if(!s->budget--) { s->failed_pc=0x0c04e12cu; return 0; }
r[4]=r[0];
goto P_0c04e12e;
P_0c04e12e: /* original 2448, guest PC 0x0c04e12e */
if(!s->budget--) { s->failed_pc=0x0c04e12eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c04e130;
P_0c04e130: /* original 8bcb, guest PC 0x0c04e130 */
if(!s->budget--) { s->failed_pc=0x0c04e130u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c04e0ca; }
goto P_0c04e132;
P_0c04e132: /* original d33d, guest PC 0x0c04e132 */
if(!s->budget--) { s->failed_pc=0x0c04e132u; return 0; }
r[3]=read(ram,0x0c04e228u,4);
goto P_0c04e134;
P_0c04e134: /* original 65e3, guest PC 0x0c04e134 */
if(!s->budget--) { s->failed_pc=0x0c04e134u; return 0; }
r[5]=r[14];
goto P_0c04e136;
P_0c04e136: /* original d63b, guest PC 0x0c04e136 */
if(!s->budget--) { s->failed_pc=0x0c04e136u; return 0; }
r[6]=read(ram,0x0c04e224u,4);
goto P_0c04e138;
P_0c04e138: /* original 430b, guest PC 0x0c04e138 */
if(!s->budget--) { s->failed_pc=0x0c04e138u; return 0; }
target=r[3];
r[16]=code_base|0x0c04e13cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e13cu) { target=s->pc; goto dispatch; }
goto P_0c04e13c;
P_0c04e13a: /* original 64c3, guest PC 0x0c04e13a */
if(!s->budget--) { s->failed_pc=0x0c04e13au; return 0; }
r[4]=r[12];
goto P_0c04e13c;
P_0c04e13c: /* original 52de, guest PC 0x0c04e13c */
if(!s->budget--) { s->failed_pc=0x0c04e13cu; return 0; }
r[2]=read(ram,r[13]+56,4);
goto P_0c04e13e;
P_0c04e13e: /* original 32b0, guest PC 0x0c04e13e */
if(!s->budget--) { s->failed_pc=0x0c04e13eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[11])!=0);
goto P_0c04e140;
P_0c04e140: /* original 8f02, guest PC 0x0c04e140 */
if(!s->budget--) { s->failed_pc=0x0c04e140u; return 0; }
cond=r[17]&1u;
r[10]=(uint32_t)(int32_t)(int16_t)r[14];
if(!cond) { goto P_0c04e148; }
goto P_0c04e144;
P_0c04e142: /* original 6aef, guest PC 0x0c04e142 */
if(!s->budget--) { s->failed_pc=0x0c04e142u; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c04e144;
P_0c04e144: /* original a005, guest PC 0x0c04e144 */
if(!s->budget--) { s->failed_pc=0x0c04e144u; return 0; }
write(ram,r[13]+56,r[10],4);
goto P_0c04e152;
P_0c04e146: /* original 1dae, guest PC 0x0c04e146 */
if(!s->budget--) { s->failed_pc=0x0c04e146u; return 0; }
write(ram,r[13]+56,r[10],4);
goto P_0c04e148;
P_0c04e148: /* original d337, guest PC 0x0c04e148 */
if(!s->budget--) { s->failed_pc=0x0c04e148u; return 0; }
r[3]=read(ram,0x0c04e228u,4);
goto P_0c04e14a;
P_0c04e14a: /* original 66e3, guest PC 0x0c04e14a */
if(!s->budget--) { s->failed_pc=0x0c04e14au; return 0; }
r[6]=r[14];
goto P_0c04e14c;
P_0c04e14c: /* original 55df, guest PC 0x0c04e14c */
if(!s->budget--) { s->failed_pc=0x0c04e14cu; return 0; }
r[5]=read(ram,r[13]+60,4);
goto P_0c04e14e;
P_0c04e14e: /* original 430b, guest PC 0x0c04e14e */
if(!s->budget--) { s->failed_pc=0x0c04e14eu; return 0; }
target=r[3];
r[16]=code_base|0x0c04e152u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c04e152u) { target=s->pc; goto dispatch; }
goto P_0c04e152;
P_0c04e150: /* original 64c3, guest PC 0x0c04e150 */
if(!s->budget--) { s->failed_pc=0x0c04e150u; return 0; }
r[4]=r[12];
goto P_0c04e152;
P_0c04e152: /* original e000, guest PC 0x0c04e152 */
if(!s->budget--) { s->failed_pc=0x0c04e152u; return 0; }
r[0]=0x00000000u;
goto P_0c04e154;
P_0c04e154: /* original 1daf, guest PC 0x0c04e154 */
if(!s->budget--) { s->failed_pc=0x0c04e154u; return 0; }
write(ram,r[13]+60,r[10],4);
goto P_0c04e156;
P_0c04e156: /* original 52dc, guest PC 0x0c04e156 */
if(!s->budget--) { s->failed_pc=0x0c04e156u; return 0; }
r[2]=read(ram,r[13]+48,4);
goto P_0c04e158;
P_0c04e158: /* original 7201, guest PC 0x0c04e158 */
if(!s->budget--) { s->failed_pc=0x0c04e158u; return 0; }
r[2]+=0x00000001u;
goto P_0c04e15a;
P_0c04e15a: /* original 1d2c, guest PC 0x0c04e15a */
if(!s->budget--) { s->failed_pc=0x0c04e15au; return 0; }
write(ram,r[13]+48,r[2],4);
goto P_0c04e15c;
P_0c04e15c: /* original 4f16, guest PC 0x0c04e15c */
if(!s->budget--) { s->failed_pc=0x0c04e15cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e15e;
P_0c04e15e: /* original 4f26, guest PC 0x0c04e15e */
if(!s->budget--) { s->failed_pc=0x0c04e15eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c04e160;
P_0c04e160: /* original 68f6, guest PC 0x0c04e160 */
if(!s->budget--) { s->failed_pc=0x0c04e160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c04e162;
P_0c04e162: /* original 69f6, guest PC 0x0c04e162 */
if(!s->budget--) { s->failed_pc=0x0c04e162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c04e164;
P_0c04e164: /* original 6af6, guest PC 0x0c04e164 */
if(!s->budget--) { s->failed_pc=0x0c04e164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c04e166;
P_0c04e166: /* original 6bf6, guest PC 0x0c04e166 */
if(!s->budget--) { s->failed_pc=0x0c04e166u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c04e168;
P_0c04e168: /* original 6cf6, guest PC 0x0c04e168 */
if(!s->budget--) { s->failed_pc=0x0c04e168u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c04e16a;
P_0c04e16a: /* original 6df6, guest PC 0x0c04e16a */
if(!s->budget--) { s->failed_pc=0x0c04e16au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c04e16c;
P_0c04e16c: /* original 000b, guest PC 0x0c04e16c */
if(!s->budget--) { s->failed_pc=0x0c04e16cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c04e16e: /* original 6ef6, guest PC 0x0c04e16e */
if(!s->budget--) { s->failed_pc=0x0c04e16eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c04e170u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
