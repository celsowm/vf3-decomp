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
int vf3_away_batch15_adapter_11(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08cf2au: goto P_0c08cf2a;
case 0x0c08cf2cu: goto P_0c08cf2c;
case 0x0c08cf2eu: goto P_0c08cf2e;
case 0x0c08cf30u: goto P_0c08cf30;
case 0x0c08cf32u: goto P_0c08cf32;
case 0x0c08cf34u: goto P_0c08cf34;
case 0x0c08cf36u: goto P_0c08cf36;
case 0x0c08cf38u: goto P_0c08cf38;
case 0x0c08cf3au: goto P_0c08cf3a;
case 0x0c08cf3cu: goto P_0c08cf3c;
case 0x0c08cf3eu: goto P_0c08cf3e;
case 0x0c08cf40u: goto P_0c08cf40;
case 0x0c08cf42u: goto P_0c08cf42;
case 0x0c08cf44u: goto P_0c08cf44;
case 0x0c08cf46u: goto P_0c08cf46;
case 0x0c08cf48u: goto P_0c08cf48;
case 0x0c08cf4au: goto P_0c08cf4a;
case 0x0c08cf4cu: goto P_0c08cf4c;
case 0x0c08cf4eu: goto P_0c08cf4e;
case 0x0c08cf50u: goto P_0c08cf50;
case 0x0c08cf52u: goto P_0c08cf52;
case 0x0c08cf54u: goto P_0c08cf54;
case 0x0c08cf56u: goto P_0c08cf56;
case 0x0c08cf58u: goto P_0c08cf58;
case 0x0c08cf5au: goto P_0c08cf5a;
case 0x0c08cf5cu: goto P_0c08cf5c;
case 0x0c08cf5eu: goto P_0c08cf5e;
case 0x0c08cf60u: goto P_0c08cf60;
case 0x0c08cf62u: goto P_0c08cf62;
case 0x0c08cf64u: goto P_0c08cf64;
case 0x0c08cf66u: goto P_0c08cf66;
case 0x0c08cf68u: goto P_0c08cf68;
case 0x0c08cf6au: goto P_0c08cf6a;
case 0x0c08cf6cu: goto P_0c08cf6c;
case 0x0c08cf6eu: goto P_0c08cf6e;
case 0x0c08cf70u: goto P_0c08cf70;
case 0x0c08cf72u: goto P_0c08cf72;
case 0x0c08cf74u: goto P_0c08cf74;
case 0x0c08cf76u: goto P_0c08cf76;
case 0x0c08cf78u: goto P_0c08cf78;
case 0x0c08cf7au: goto P_0c08cf7a;
case 0x0c08cf7cu: goto P_0c08cf7c;
case 0x0c08cf7eu: goto P_0c08cf7e;
case 0x0c08cf80u: goto P_0c08cf80;
case 0x0c08cf82u: goto P_0c08cf82;
case 0x0c08cf84u: goto P_0c08cf84;
case 0x0c08cf86u: goto P_0c08cf86;
case 0x0c08cf88u: goto P_0c08cf88;
case 0x0c08cf8au: goto P_0c08cf8a;
case 0x0c08cf8cu: goto P_0c08cf8c;
case 0x0c08cf8eu: goto P_0c08cf8e;
case 0x0c08cf90u: goto P_0c08cf90;
case 0x0c08cf92u: goto P_0c08cf92;
case 0x0c08cf94u: goto P_0c08cf94;
case 0x0c08cf96u: goto P_0c08cf96;
case 0x0c08cf98u: goto P_0c08cf98;
case 0x0c08cf9au: goto P_0c08cf9a;
case 0x0c08cf9cu: goto P_0c08cf9c;
case 0x0c08cf9eu: goto P_0c08cf9e;
case 0x0c08cfa0u: goto P_0c08cfa0;
case 0x0c08cfa2u: goto P_0c08cfa2;
case 0x0c08cfa4u: goto P_0c08cfa4;
case 0x0c08cfa6u: goto P_0c08cfa6;
case 0x0c08cfa8u: goto P_0c08cfa8;
case 0x0c08cfaau: goto P_0c08cfaa;
case 0x0c08cfacu: goto P_0c08cfac;
case 0x0c08cfaeu: goto P_0c08cfae;
case 0x0c08cfb0u: goto P_0c08cfb0;
case 0x0c08cfb2u: goto P_0c08cfb2;
case 0x0c08cfb4u: goto P_0c08cfb4;
case 0x0c08cfb6u: goto P_0c08cfb6;
case 0x0c08cfb8u: goto P_0c08cfb8;
case 0x0c08cfbau: goto P_0c08cfba;
case 0x0c08cfbcu: goto P_0c08cfbc;
case 0x0c08cfbeu: goto P_0c08cfbe;
case 0x0c08cfc0u: goto P_0c08cfc0;
case 0x0c08cfc2u: goto P_0c08cfc2;
case 0x0c08cfc4u: goto P_0c08cfc4;
case 0x0c08cfc6u: goto P_0c08cfc6;
case 0x0c08cfc8u: goto P_0c08cfc8;
case 0x0c08cfcau: goto P_0c08cfca;
case 0x0c08cfccu: goto P_0c08cfcc;
case 0x0c08cfceu: goto P_0c08cfce;
case 0x0c08cfd0u: goto P_0c08cfd0;
case 0x0c08cfd2u: goto P_0c08cfd2;
case 0x0c08cfd4u: goto P_0c08cfd4;
case 0x0c08cfd6u: goto P_0c08cfd6;
case 0x0c08cfd8u: goto P_0c08cfd8;
case 0x0c08cfdau: goto P_0c08cfda;
case 0x0c08cfdcu: goto P_0c08cfdc;
case 0x0c08cfdeu: goto P_0c08cfde;
case 0x0c08cfe0u: goto P_0c08cfe0;
case 0x0c08cfe2u: goto P_0c08cfe2;
case 0x0c08cfe4u: goto P_0c08cfe4;
case 0x0c08cfe6u: goto P_0c08cfe6;
case 0x0c08d000u: goto P_0c08d000;
case 0x0c08d002u: goto P_0c08d002;
case 0x0c08d004u: goto P_0c08d004;
case 0x0c08d006u: goto P_0c08d006;
case 0x0c08d008u: goto P_0c08d008;
case 0x0c08d00au: goto P_0c08d00a;
case 0x0c08d00cu: goto P_0c08d00c;
case 0x0c08d00eu: goto P_0c08d00e;
case 0x0c08d010u: goto P_0c08d010;
case 0x0c08d012u: goto P_0c08d012;
case 0x0c08d014u: goto P_0c08d014;
case 0x0c08d016u: goto P_0c08d016;
case 0x0c08d018u: goto P_0c08d018;
case 0x0c08d01au: goto P_0c08d01a;
case 0x0c08d01cu: goto P_0c08d01c;
case 0x0c08d01eu: goto P_0c08d01e;
case 0x0c08d020u: goto P_0c08d020;
case 0x0c08d022u: goto P_0c08d022;
case 0x0c08d024u: goto P_0c08d024;
case 0x0c08d026u: goto P_0c08d026;
case 0x0c08d028u: goto P_0c08d028;
case 0x0c08d02au: goto P_0c08d02a;
case 0x0c08d02cu: goto P_0c08d02c;
case 0x0c08d02eu: goto P_0c08d02e;
case 0x0c08d030u: goto P_0c08d030;
case 0x0c08d032u: goto P_0c08d032;
case 0x0c08d034u: goto P_0c08d034;
case 0x0c08d036u: goto P_0c08d036;
case 0x0c08d038u: goto P_0c08d038;
case 0x0c08d03au: goto P_0c08d03a;
case 0x0c08d03cu: goto P_0c08d03c;
case 0x0c08d03eu: goto P_0c08d03e;
case 0x0c08d040u: goto P_0c08d040;
case 0x0c08d042u: goto P_0c08d042;
case 0x0c08d044u: goto P_0c08d044;
case 0x0c08d046u: goto P_0c08d046;
case 0x0c08d048u: goto P_0c08d048;
case 0x0c08d04au: goto P_0c08d04a;
case 0x0c08d04cu: goto P_0c08d04c;
case 0x0c08d04eu: goto P_0c08d04e;
case 0x0c08d050u: goto P_0c08d050;
case 0x0c08d052u: goto P_0c08d052;
case 0x0c08d054u: goto P_0c08d054;
case 0x0c08d056u: goto P_0c08d056;
case 0x0c08d058u: goto P_0c08d058;
case 0x0c08d05au: goto P_0c08d05a;
case 0x0c08d05cu: goto P_0c08d05c;
case 0x0c08d05eu: goto P_0c08d05e;
case 0x0c08d060u: goto P_0c08d060;
case 0x0c08d062u: goto P_0c08d062;
case 0x0c08d064u: goto P_0c08d064;
case 0x0c08d066u: goto P_0c08d066;
case 0x0c08d068u: goto P_0c08d068;
case 0x0c08d06au: goto P_0c08d06a;
case 0x0c08d06cu: goto P_0c08d06c;
case 0x0c08d06eu: goto P_0c08d06e;
case 0x0c08d070u: goto P_0c08d070;
case 0x0c08d072u: goto P_0c08d072;
case 0x0c08d074u: goto P_0c08d074;
case 0x0c08d076u: goto P_0c08d076;
case 0x0c08d078u: goto P_0c08d078;
case 0x0c08d07au: goto P_0c08d07a;
case 0x0c08d07cu: goto P_0c08d07c;
case 0x0c08d07eu: goto P_0c08d07e;
case 0x0c08d080u: goto P_0c08d080;
case 0x0c08d082u: goto P_0c08d082;
case 0x0c08d084u: goto P_0c08d084;
case 0x0c08d086u: goto P_0c08d086;
case 0x0c08d088u: goto P_0c08d088;
case 0x0c08d08au: goto P_0c08d08a;
case 0x0c08d08cu: goto P_0c08d08c;
case 0x0c08d08eu: goto P_0c08d08e;
case 0x0c08d090u: goto P_0c08d090;
case 0x0c08d092u: goto P_0c08d092;
case 0x0c08d094u: goto P_0c08d094;
case 0x0c08d096u: goto P_0c08d096;
case 0x0c08d098u: goto P_0c08d098;
case 0x0c08d09au: goto P_0c08d09a;
case 0x0c08d09cu: goto P_0c08d09c;
case 0x0c08d09eu: goto P_0c08d09e;
case 0x0c08d0a0u: goto P_0c08d0a0;
case 0x0c08d0a2u: goto P_0c08d0a2;
case 0x0c08d0a4u: goto P_0c08d0a4;
case 0x0c08d0a6u: goto P_0c08d0a6;
case 0x0c08d0a8u: goto P_0c08d0a8;
case 0x0c08d0aau: goto P_0c08d0aa;
case 0x0c08d0acu: goto P_0c08d0ac;
case 0x0c08d0aeu: goto P_0c08d0ae;
case 0x0c08d0b0u: goto P_0c08d0b0;
case 0x0c08d0b2u: goto P_0c08d0b2;
case 0x0c08d0b4u: goto P_0c08d0b4;
case 0x0c08d0b6u: goto P_0c08d0b6;
case 0x0c08d0b8u: goto P_0c08d0b8;
case 0x0c08d0bau: goto P_0c08d0ba;
case 0x0c08d0bcu: goto P_0c08d0bc;
case 0x0c08d0beu: goto P_0c08d0be;
case 0x0c08d0c0u: goto P_0c08d0c0;
case 0x0c08d0c2u: goto P_0c08d0c2;
case 0x0c08d0c4u: goto P_0c08d0c4;
case 0x0c08d0c6u: goto P_0c08d0c6;
case 0x0c08d0c8u: goto P_0c08d0c8;
case 0x0c08d0cau: goto P_0c08d0ca;
case 0x0c08d0ccu: goto P_0c08d0cc;
case 0x0c08d0ceu: goto P_0c08d0ce;
case 0x0c08d0d0u: goto P_0c08d0d0;
case 0x0c08d0d2u: goto P_0c08d0d2;
case 0x0c08d0d4u: goto P_0c08d0d4;
case 0x0c08d0d6u: goto P_0c08d0d6;
case 0x0c08d0d8u: goto P_0c08d0d8;
case 0x0c08d0dau: goto P_0c08d0da;
case 0x0c08d0dcu: goto P_0c08d0dc;
case 0x0c08d0deu: goto P_0c08d0de;
case 0x0c08d0e0u: goto P_0c08d0e0;
case 0x0c08d0e2u: goto P_0c08d0e2;
case 0x0c08d0e4u: goto P_0c08d0e4;
case 0x0c08d0e6u: goto P_0c08d0e6;
case 0x0c08d0e8u: goto P_0c08d0e8;
case 0x0c08d0eau: goto P_0c08d0ea;
case 0x0c08d0ecu: goto P_0c08d0ec;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08cf2a: /* original 2fe6, guest PC 0x0c08cf2a */
if(!s->budget--) { s->failed_pc=0x0c08cf2au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf2c;
P_0c08cf2c: /* original 6e43, guest PC 0x0c08cf2c */
if(!s->budget--) { s->failed_pc=0x0c08cf2cu; return 0; }
r[14]=r[4];
goto P_0c08cf2e;
P_0c08cf2e: /* original 2fd6, guest PC 0x0c08cf2e */
if(!s->budget--) { s->failed_pc=0x0c08cf2eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf30;
P_0c08cf30: /* original e048, guest PC 0x0c08cf30 */
if(!s->budget--) { s->failed_pc=0x0c08cf30u; return 0; }
r[0]=0x00000048u;
goto P_0c08cf32;
P_0c08cf32: /* original 2fc6, guest PC 0x0c08cf32 */
if(!s->budget--) { s->failed_pc=0x0c08cf32u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf34;
P_0c08cf34: /* original 00ec, guest PC 0x0c08cf34 */
if(!s->budget--) { s->failed_pc=0x0c08cf34u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cf36;
P_0c08cf36: /* original 4f22, guest PC 0x0c08cf36 */
if(!s->budget--) { s->failed_pc=0x0c08cf36u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cf38;
P_0c08cf38: /* original 8801, guest PC 0x0c08cf38 */
if(!s->budget--) { s->failed_pc=0x0c08cf38u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cf3a;
P_0c08cf3a: /* original 8d24, guest PC 0x0c08cf3a */
if(!s->budget--) { s->failed_pc=0x0c08cf3au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08cf86; }
goto P_0c08cf3e;
P_0c08cf3c: /* original 6d53, guest PC 0x0c08cf3c */
if(!s->budget--) { s->failed_pc=0x0c08cf3cu; return 0; }
r[13]=r[5];
goto P_0c08cf3e;
P_0c08cf3e: /* original 60d2, guest PC 0x0c08cf3e */
if(!s->budget--) { s->failed_pc=0x0c08cf3eu; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cf40;
P_0c08cf40: /* original cb01, guest PC 0x0c08cf40 */
if(!s->budget--) { s->failed_pc=0x0c08cf40u; return 0; }
r[0]|=1u;
goto P_0c08cf42;
P_0c08cf42: /* original 2d02, guest PC 0x0c08cf42 */
if(!s->budget--) { s->failed_pc=0x0c08cf42u; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cf44;
P_0c08cf44: /* original d22a, guest PC 0x0c08cf44 */
if(!s->budget--) { s->failed_pc=0x0c08cf44u; return 0; }
r[2]=read(ram,0x0c08cff0u,4);
goto P_0c08cf46;
P_0c08cf46: /* original 420b, guest PC 0x0c08cf46 */
if(!s->budget--) { s->failed_pc=0x0c08cf46u; return 0; }
target=r[2];
r[16]=code_base|0x0c08cf4au;
r[12]=0x0000000cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf4au) { target=s->pc; goto dispatch; }
goto P_0c08cf4a;
P_0c08cf48: /* original ec0c, guest PC 0x0c08cf48 */
if(!s->budget--) { s->failed_pc=0x0c08cf48u; return 0; }
r[12]=0x0000000cu;
goto P_0c08cf4a;
P_0c08cf4a: /* original d32a, guest PC 0x0c08cf4a */
if(!s->budget--) { s->failed_pc=0x0c08cf4au; return 0; }
r[3]=read(ram,0x0c08cff4u,4);
goto P_0c08cf4c;
P_0c08cf4c: /* original 6103, guest PC 0x0c08cf4c */
if(!s->budget--) { s->failed_pc=0x0c08cf4cu; return 0; }
r[1]=r[0];
goto P_0c08cf4e;
P_0c08cf4e: /* original 430b, guest PC 0x0c08cf4e */
if(!s->budget--) { s->failed_pc=0x0c08cf4eu; return 0; }
target=r[3];
r[16]=code_base|0x0c08cf52u;
r[0]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf52u) { target=s->pc; goto dispatch; }
goto P_0c08cf52;
P_0c08cf50: /* original 60c3, guest PC 0x0c08cf50 */
if(!s->budget--) { s->failed_pc=0x0c08cf50u; return 0; }
r[0]=r[12];
goto P_0c08cf52;
P_0c08cf52: /* original 6403, guest PC 0x0c08cf52 */
if(!s->budget--) { s->failed_pc=0x0c08cf52u; return 0; }
r[4]=r[0];
goto P_0c08cf54;
P_0c08cf54: /* original d029, guest PC 0x0c08cf54 */
if(!s->budget--) { s->failed_pc=0x0c08cf54u; return 0; }
r[0]=read(ram,0x0c08cffcu,4);
goto P_0c08cf56;
P_0c08cf56: /* original 4400, guest PC 0x0c08cf56 */
if(!s->budget--) { s->failed_pc=0x0c08cf56u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08cf58;
P_0c08cf58: /* original 044d, guest PC 0x0c08cf58 */
if(!s->budget--) { s->failed_pc=0x0c08cf58u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c08cf5a;
P_0c08cf5a: /* original e028, guest PC 0x0c08cf5a */
if(!s->budget--) { s->failed_pc=0x0c08cf5au; return 0; }
r[0]=0x00000028u;
goto P_0c08cf5c;
P_0c08cf5c: /* original e500, guest PC 0x0c08cf5c */
if(!s->budget--) { s->failed_pc=0x0c08cf5cu; return 0; }
r[5]=0x00000000u;
goto P_0c08cf5e;
P_0c08cf5e: /* original 644d, guest PC 0x0c08cf5e */
if(!s->budget--) { s->failed_pc=0x0c08cf5eu; return 0; }
r[4]=r[4]&65535u;
goto P_0c08cf60;
P_0c08cf60: /* original 0e45, guest PC 0x0c08cf60 */
if(!s->budget--) { s->failed_pc=0x0c08cf60u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cf62;
P_0c08cf62: /* original e040, guest PC 0x0c08cf62 */
if(!s->budget--) { s->failed_pc=0x0c08cf62u; return 0; }
r[0]=0x00000040u;
goto P_0c08cf64;
P_0c08cf64: /* original 1d4d, guest PC 0x0c08cf64 */
if(!s->budget--) { s->failed_pc=0x0c08cf64u; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cf66;
P_0c08cf66: /* original 0d56, guest PC 0x0c08cf66 */
if(!s->budget--) { s->failed_pc=0x0c08cf66u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cf68;
P_0c08cf68: /* original b0f6, guest PC 0x0c08cf68 */
if(!s->budget--) { s->failed_pc=0x0c08cf68u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cf6cu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cf6cu) { target=s->pc; goto dispatch; }
goto P_0c08cf6c;
P_0c08cf6a: /* original 64d3, guest PC 0x0c08cf6a */
if(!s->budget--) { s->failed_pc=0x0c08cf6au; return 0; }
r[4]=r[13];
goto P_0c08cf6c;
P_0c08cf6c: /* original e200, guest PC 0x0c08cf6c */
if(!s->budget--) { s->failed_pc=0x0c08cf6cu; return 0; }
r[2]=0x00000000u;
goto P_0c08cf6e;
P_0c08cf6e: /* original 55de, guest PC 0x0c08cf6e */
if(!s->budget--) { s->failed_pc=0x0c08cf6eu; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08cf70;
P_0c08cf70: /* original e02c, guest PC 0x0c08cf70 */
if(!s->budget--) { s->failed_pc=0x0c08cf70u; return 0; }
r[0]=0x0000002cu;
goto P_0c08cf72;
P_0c08cf72: /* original 54df, guest PC 0x0c08cf72 */
if(!s->budget--) { s->failed_pc=0x0c08cf72u; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08cf74;
P_0c08cf74: /* original 0e24, guest PC 0x0c08cf74 */
if(!s->budget--) { s->failed_pc=0x0c08cf74u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08cf76;
P_0c08cf76: /* original e02d, guest PC 0x0c08cf76 */
if(!s->budget--) { s->failed_pc=0x0c08cf76u; return 0; }
r[0]=0x0000002du;
goto P_0c08cf78;
P_0c08cf78: /* original 0e54, guest PC 0x0c08cf78 */
if(!s->budget--) { s->failed_pc=0x0c08cf78u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08cf7a;
P_0c08cf7a: /* original 6043, guest PC 0x0c08cf7a */
if(!s->budget--) { s->failed_pc=0x0c08cf7au; return 0; }
r[0]=r[4];
goto P_0c08cf7c;
P_0c08cf7c: /* original 81ea, guest PC 0x0c08cf7c */
if(!s->budget--) { s->failed_pc=0x0c08cf7cu; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08cf7e;
P_0c08cf7e: /* original e048, guest PC 0x0c08cf7e */
if(!s->budget--) { s->failed_pc=0x0c08cf7eu; return 0; }
r[0]=0x00000048u;
goto P_0c08cf80;
P_0c08cf80: /* original 03ec, guest PC 0x0c08cf80 */
if(!s->budget--) { s->failed_pc=0x0c08cf80u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cf82;
P_0c08cf82: /* original 7301, guest PC 0x0c08cf82 */
if(!s->budget--) { s->failed_pc=0x0c08cf82u; return 0; }
r[3]+=0x00000001u;
goto P_0c08cf84;
P_0c08cf84: /* original 0e34, guest PC 0x0c08cf84 */
if(!s->budget--) { s->failed_pc=0x0c08cf84u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08cf86;
P_0c08cf86: /* original 4f26, guest PC 0x0c08cf86 */
if(!s->budget--) { s->failed_pc=0x0c08cf86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cf88;
P_0c08cf88: /* original 6cf6, guest PC 0x0c08cf88 */
if(!s->budget--) { s->failed_pc=0x0c08cf88u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08cf8a;
P_0c08cf8a: /* original 6df6, guest PC 0x0c08cf8a */
if(!s->budget--) { s->failed_pc=0x0c08cf8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cf8c;
P_0c08cf8c: /* original 000b, guest PC 0x0c08cf8c */
if(!s->budget--) { s->failed_pc=0x0c08cf8cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cf8e: /* original 6ef6, guest PC 0x0c08cf8e */
if(!s->budget--) { s->failed_pc=0x0c08cf8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08cf90;
P_0c08cf90: /* original 2fe6, guest PC 0x0c08cf90 */
if(!s->budget--) { s->failed_pc=0x0c08cf90u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf92;
P_0c08cf92: /* original 6e43, guest PC 0x0c08cf92 */
if(!s->budget--) { s->failed_pc=0x0c08cf92u; return 0; }
r[14]=r[4];
goto P_0c08cf94;
P_0c08cf94: /* original e048, guest PC 0x0c08cf94 */
if(!s->budget--) { s->failed_pc=0x0c08cf94u; return 0; }
r[0]=0x00000048u;
goto P_0c08cf96;
P_0c08cf96: /* original 2fd6, guest PC 0x0c08cf96 */
if(!s->budget--) { s->failed_pc=0x0c08cf96u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08cf98;
P_0c08cf98: /* original 00ec, guest PC 0x0c08cf98 */
if(!s->budget--) { s->failed_pc=0x0c08cf98u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cf9a;
P_0c08cf9a: /* original 4f22, guest PC 0x0c08cf9a */
if(!s->budget--) { s->failed_pc=0x0c08cf9au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08cf9c;
P_0c08cf9c: /* original 8801, guest PC 0x0c08cf9c */
if(!s->budget--) { s->failed_pc=0x0c08cf9cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08cf9e;
P_0c08cf9e: /* original 8d1f, guest PC 0x0c08cf9e */
if(!s->budget--) { s->failed_pc=0x0c08cf9eu; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c08cfe0; }
goto P_0c08cfa2;
P_0c08cfa0: /* original 6d53, guest PC 0x0c08cfa0 */
if(!s->budget--) { s->failed_pc=0x0c08cfa0u; return 0; }
r[13]=r[5];
goto P_0c08cfa2;
P_0c08cfa2: /* original 60d2, guest PC 0x0c08cfa2 */
if(!s->budget--) { s->failed_pc=0x0c08cfa2u; return 0; }
tmp=read(ram,r[13],4);
r[0]=tmp;
goto P_0c08cfa4;
P_0c08cfa4: /* original d212, guest PC 0x0c08cfa4 */
if(!s->budget--) { s->failed_pc=0x0c08cfa4u; return 0; }
r[2]=read(ram,0x0c08cff0u,4);
goto P_0c08cfa6;
P_0c08cfa6: /* original cb01, guest PC 0x0c08cfa6 */
if(!s->budget--) { s->failed_pc=0x0c08cfa6u; return 0; }
r[0]|=1u;
goto P_0c08cfa8;
P_0c08cfa8: /* original 420b, guest PC 0x0c08cfa8 */
if(!s->budget--) { s->failed_pc=0x0c08cfa8u; return 0; }
target=r[2];
r[16]=code_base|0x0c08cfacu;
write(ram,r[13],r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cfacu) { target=s->pc; goto dispatch; }
goto P_0c08cfac;
P_0c08cfaa: /* original 2d02, guest PC 0x0c08cfaa */
if(!s->budget--) { s->failed_pc=0x0c08cfaau; return 0; }
write(ram,r[13],r[0],4);
goto P_0c08cfac;
P_0c08cfac: /* original 921c, guest PC 0x0c08cfac */
if(!s->budget--) { s->failed_pc=0x0c08cfacu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08cfe8u,2);
goto P_0c08cfae;
P_0c08cfae: /* original e301, guest PC 0x0c08cfae */
if(!s->budget--) { s->failed_pc=0x0c08cfaeu; return 0; }
r[3]=0x00000001u;
goto P_0c08cfb0;
P_0c08cfb0: /* original 6403, guest PC 0x0c08cfb0 */
if(!s->budget--) { s->failed_pc=0x0c08cfb0u; return 0; }
r[4]=r[0];
goto P_0c08cfb2;
P_0c08cfb2: /* original 2439, guest PC 0x0c08cfb2 */
if(!s->budget--) { s->failed_pc=0x0c08cfb2u; return 0; }
r[4]&=r[3];
goto P_0c08cfb4;
P_0c08cfb4: /* original e028, guest PC 0x0c08cfb4 */
if(!s->budget--) { s->failed_pc=0x0c08cfb4u; return 0; }
r[0]=0x00000028u;
goto P_0c08cfb6;
P_0c08cfb6: /* original 342c, guest PC 0x0c08cfb6 */
if(!s->budget--) { s->failed_pc=0x0c08cfb6u; return 0; }
r[4]+=r[2];
goto P_0c08cfb8;
P_0c08cfb8: /* original 0e45, guest PC 0x0c08cfb8 */
if(!s->budget--) { s->failed_pc=0x0c08cfb8u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08cfba;
P_0c08cfba: /* original e040, guest PC 0x0c08cfba */
if(!s->budget--) { s->failed_pc=0x0c08cfbau; return 0; }
r[0]=0x00000040u;
goto P_0c08cfbc;
P_0c08cfbc: /* original e500, guest PC 0x0c08cfbc */
if(!s->budget--) { s->failed_pc=0x0c08cfbcu; return 0; }
r[5]=0x00000000u;
goto P_0c08cfbe;
P_0c08cfbe: /* original 1d4d, guest PC 0x0c08cfbe */
if(!s->budget--) { s->failed_pc=0x0c08cfbeu; return 0; }
write(ram,r[13]+52,r[4],4);
goto P_0c08cfc0;
P_0c08cfc0: /* original 0d56, guest PC 0x0c08cfc0 */
if(!s->budget--) { s->failed_pc=0x0c08cfc0u; return 0; }
write(ram,r[13]+r[0],r[5],4);
goto P_0c08cfc2;
P_0c08cfc2: /* original b0c9, guest PC 0x0c08cfc2 */
if(!s->budget--) { s->failed_pc=0x0c08cfc2u; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08cfc6u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08cfc6u) { target=s->pc; goto dispatch; }
goto P_0c08cfc6;
P_0c08cfc4: /* original 64d3, guest PC 0x0c08cfc4 */
if(!s->budget--) { s->failed_pc=0x0c08cfc4u; return 0; }
r[4]=r[13];
goto P_0c08cfc6;
P_0c08cfc6: /* original e200, guest PC 0x0c08cfc6 */
if(!s->budget--) { s->failed_pc=0x0c08cfc6u; return 0; }
r[2]=0x00000000u;
goto P_0c08cfc8;
P_0c08cfc8: /* original 55de, guest PC 0x0c08cfc8 */
if(!s->budget--) { s->failed_pc=0x0c08cfc8u; return 0; }
r[5]=read(ram,r[13]+56,4);
goto P_0c08cfca;
P_0c08cfca: /* original e02c, guest PC 0x0c08cfca */
if(!s->budget--) { s->failed_pc=0x0c08cfcau; return 0; }
r[0]=0x0000002cu;
goto P_0c08cfcc;
P_0c08cfcc: /* original 54df, guest PC 0x0c08cfcc */
if(!s->budget--) { s->failed_pc=0x0c08cfccu; return 0; }
r[4]=read(ram,r[13]+60,4);
goto P_0c08cfce;
P_0c08cfce: /* original 0e24, guest PC 0x0c08cfce */
if(!s->budget--) { s->failed_pc=0x0c08cfceu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c08cfd0;
P_0c08cfd0: /* original e02d, guest PC 0x0c08cfd0 */
if(!s->budget--) { s->failed_pc=0x0c08cfd0u; return 0; }
r[0]=0x0000002du;
goto P_0c08cfd2;
P_0c08cfd2: /* original 0e54, guest PC 0x0c08cfd2 */
if(!s->budget--) { s->failed_pc=0x0c08cfd2u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08cfd4;
P_0c08cfd4: /* original 6043, guest PC 0x0c08cfd4 */
if(!s->budget--) { s->failed_pc=0x0c08cfd4u; return 0; }
r[0]=r[4];
goto P_0c08cfd6;
P_0c08cfd6: /* original 81ea, guest PC 0x0c08cfd6 */
if(!s->budget--) { s->failed_pc=0x0c08cfd6u; return 0; }
write(ram,r[14]+20,r[0],2);
goto P_0c08cfd8;
P_0c08cfd8: /* original e048, guest PC 0x0c08cfd8 */
if(!s->budget--) { s->failed_pc=0x0c08cfd8u; return 0; }
r[0]=0x00000048u;
goto P_0c08cfda;
P_0c08cfda: /* original 03ec, guest PC 0x0c08cfda */
if(!s->budget--) { s->failed_pc=0x0c08cfdau; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08cfdc;
P_0c08cfdc: /* original 7301, guest PC 0x0c08cfdc */
if(!s->budget--) { s->failed_pc=0x0c08cfdcu; return 0; }
r[3]+=0x00000001u;
goto P_0c08cfde;
P_0c08cfde: /* original 0e34, guest PC 0x0c08cfde */
if(!s->budget--) { s->failed_pc=0x0c08cfdeu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c08cfe0;
P_0c08cfe0: /* original 4f26, guest PC 0x0c08cfe0 */
if(!s->budget--) { s->failed_pc=0x0c08cfe0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08cfe2;
P_0c08cfe2: /* original 6df6, guest PC 0x0c08cfe2 */
if(!s->budget--) { s->failed_pc=0x0c08cfe2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08cfe4;
P_0c08cfe4: /* original 000b, guest PC 0x0c08cfe4 */
if(!s->budget--) { s->failed_pc=0x0c08cfe4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08cfe6: /* original 6ef6, guest PC 0x0c08cfe6 */
if(!s->budget--) { s->failed_pc=0x0c08cfe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08cfe8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08cfe8u; return 0; } return 1;
P_0c08d000: /* original 2fe6, guest PC 0x0c08d000 */
if(!s->budget--) { s->failed_pc=0x0c08d000u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d002;
P_0c08d002: /* original e048, guest PC 0x0c08d002 */
if(!s->budget--) { s->failed_pc=0x0c08d002u; return 0; }
r[0]=0x00000048u;
goto P_0c08d004;
P_0c08d004: /* original 2fd6, guest PC 0x0c08d004 */
if(!s->budget--) { s->failed_pc=0x0c08d004u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d006;
P_0c08d006: /* original 6d43, guest PC 0x0c08d006 */
if(!s->budget--) { s->failed_pc=0x0c08d006u; return 0; }
r[13]=r[4];
goto P_0c08d008;
P_0c08d008: /* original 2fc6, guest PC 0x0c08d008 */
if(!s->budget--) { s->failed_pc=0x0c08d008u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d00a;
P_0c08d00a: /* original 6e53, guest PC 0x0c08d00a */
if(!s->budget--) { s->failed_pc=0x0c08d00au; return 0; }
r[14]=r[5];
goto P_0c08d00c;
P_0c08d00c: /* original 00dc, guest PC 0x0c08d00c */
if(!s->budget--) { s->failed_pc=0x0c08d00cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d00e;
P_0c08d00e: /* original 4f22, guest PC 0x0c08d00e */
if(!s->budget--) { s->failed_pc=0x0c08d00eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d010;
P_0c08d010: /* original 8801, guest PC 0x0c08d010 */
if(!s->budget--) { s->failed_pc=0x0c08d010u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d012;
P_0c08d012: /* original 8d1a, guest PC 0x0c08d012 */
if(!s->budget--) { s->failed_pc=0x0c08d012u; return 0; }
cond=r[17]&1u;
r[12]=0x00000000u;
if(cond) { goto P_0c08d04a; }
goto P_0c08d016;
P_0c08d014: /* original ec00, guest PC 0x0c08d014 */
if(!s->budget--) { s->failed_pc=0x0c08d014u; return 0; }
r[12]=0x00000000u;
goto P_0c08d016;
P_0c08d016: /* original 60e2, guest PC 0x0c08d016 */
if(!s->budget--) { s->failed_pc=0x0c08d016u; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c08d018;
P_0c08d018: /* original 65c3, guest PC 0x0c08d018 */
if(!s->budget--) { s->failed_pc=0x0c08d018u; return 0; }
r[5]=r[12];
goto P_0c08d01a;
P_0c08d01a: /* original cb01, guest PC 0x0c08d01a */
if(!s->budget--) { s->failed_pc=0x0c08d01au; return 0; }
r[0]|=1u;
goto P_0c08d01c;
P_0c08d01c: /* original 2e02, guest PC 0x0c08d01c */
if(!s->budget--) { s->failed_pc=0x0c08d01cu; return 0; }
write(ram,r[14],r[0],4);
goto P_0c08d01e;
P_0c08d01e: /* original e028, guest PC 0x0c08d01e */
if(!s->budget--) { s->failed_pc=0x0c08d01eu; return 0; }
r[0]=0x00000028u;
goto P_0c08d020;
P_0c08d020: /* original 9485, guest PC 0x0c08d020 */
if(!s->budget--) { s->failed_pc=0x0c08d020u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d12eu,2);
goto P_0c08d022;
P_0c08d022: /* original 0d45, guest PC 0x0c08d022 */
if(!s->budget--) { s->failed_pc=0x0c08d022u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08d024;
P_0c08d024: /* original e040, guest PC 0x0c08d024 */
if(!s->budget--) { s->failed_pc=0x0c08d024u; return 0; }
r[0]=0x00000040u;
goto P_0c08d026;
P_0c08d026: /* original 1e4d, guest PC 0x0c08d026 */
if(!s->budget--) { s->failed_pc=0x0c08d026u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08d028;
P_0c08d028: /* original 0e56, guest PC 0x0c08d028 */
if(!s->budget--) { s->failed_pc=0x0c08d028u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08d02a;
P_0c08d02a: /* original b095, guest PC 0x0c08d02a */
if(!s->budget--) { s->failed_pc=0x0c08d02au; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d02eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d02eu) { target=s->pc; goto dispatch; }
goto P_0c08d02e;
P_0c08d02c: /* original 64e3, guest PC 0x0c08d02c */
if(!s->budget--) { s->failed_pc=0x0c08d02cu; return 0; }
r[4]=r[14];
goto P_0c08d02e;
P_0c08d02e: /* original e02c, guest PC 0x0c08d02e */
if(!s->budget--) { s->failed_pc=0x0c08d02eu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d030;
P_0c08d030: /* original 55ee, guest PC 0x0c08d030 */
if(!s->budget--) { s->failed_pc=0x0c08d030u; return 0; }
r[5]=read(ram,r[14]+56,4);
goto P_0c08d032;
P_0c08d032: /* original 54ef, guest PC 0x0c08d032 */
if(!s->budget--) { s->failed_pc=0x0c08d032u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c08d034;
P_0c08d034: /* original 0dc4, guest PC 0x0c08d034 */
if(!s->budget--) { s->failed_pc=0x0c08d034u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d036;
P_0c08d036: /* original e02d, guest PC 0x0c08d036 */
if(!s->budget--) { s->failed_pc=0x0c08d036u; return 0; }
r[0]=0x0000002du;
goto P_0c08d038;
P_0c08d038: /* original 0d54, guest PC 0x0c08d038 */
if(!s->budget--) { s->failed_pc=0x0c08d038u; return 0; }
write(ram,r[13]+r[0],r[5],1);
goto P_0c08d03a;
P_0c08d03a: /* original 6043, guest PC 0x0c08d03a */
if(!s->budget--) { s->failed_pc=0x0c08d03au; return 0; }
r[0]=r[4];
goto P_0c08d03c;
P_0c08d03c: /* original 81da, guest PC 0x0c08d03c */
if(!s->budget--) { s->failed_pc=0x0c08d03cu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d03e;
P_0c08d03e: /* original e010, guest PC 0x0c08d03e */
if(!s->budget--) { s->failed_pc=0x0c08d03eu; return 0; }
r[0]=0x00000010u;
goto P_0c08d040;
P_0c08d040: /* original 81df, guest PC 0x0c08d040 */
if(!s->budget--) { s->failed_pc=0x0c08d040u; return 0; }
write(ram,r[13]+30,r[0],2);
goto P_0c08d042;
P_0c08d042: /* original e048, guest PC 0x0c08d042 */
if(!s->budget--) { s->failed_pc=0x0c08d042u; return 0; }
r[0]=0x00000048u;
goto P_0c08d044;
P_0c08d044: /* original 03dc, guest PC 0x0c08d044 */
if(!s->budget--) { s->failed_pc=0x0c08d044u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d046;
P_0c08d046: /* original 7301, guest PC 0x0c08d046 */
if(!s->budget--) { s->failed_pc=0x0c08d046u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d048;
P_0c08d048: /* original 0d34, guest PC 0x0c08d048 */
if(!s->budget--) { s->failed_pc=0x0c08d048u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d04a;
P_0c08d04a: /* original e048, guest PC 0x0c08d04a */
if(!s->budget--) { s->failed_pc=0x0c08d04au; return 0; }
r[0]=0x00000048u;
goto P_0c08d04c;
P_0c08d04c: /* original 02ee, guest PC 0x0c08d04c */
if(!s->budget--) { s->failed_pc=0x0c08d04cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c08d04e;
P_0c08d04e: /* original 906f, guest PC 0x0c08d04e */
if(!s->budget--) { s->failed_pc=0x0c08d04eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d130u,2);
goto P_0c08d050;
P_0c08d050: /* original f526, guest PC 0x0c08d050 */
if(!s->budget--) { s->failed_pc=0x0c08d050u; return 0; }
vf3_matrix_load(s,ram,5,r[2]+r[0]);
goto P_0c08d052;
P_0c08d052: /* original c739, guest PC 0x0c08d052 */
if(!s->budget--) { s->failed_pc=0x0c08d052u; return 0; }
r[0]=code_base|0x0008d138u;
goto P_0c08d054;
P_0c08d054: /* original f408, guest PC 0x0c08d054 */
if(!s->budget--) { s->failed_pc=0x0c08d054u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08d056;
P_0c08d056: /* original f545, guest PC 0x0c08d056 */
if(!s->budget--) { s->failed_pc=0x0c08d056u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08d058;
P_0c08d058: /* original 8b15, guest PC 0x0c08d058 */
if(!s->budget--) { s->failed_pc=0x0c08d058u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d086; }
goto P_0c08d05a;
P_0c08d05a: /* original e024, guest PC 0x0c08d05a */
if(!s->budget--) { s->failed_pc=0x0c08d05au; return 0; }
r[0]=0x00000024u;
goto P_0c08d05c;
P_0c08d05c: /* original f5e6, guest PC 0x0c08d05c */
if(!s->budget--) { s->failed_pc=0x0c08d05cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08d05e;
P_0c08d05e: /* original f545, guest PC 0x0c08d05e */
if(!s->budget--) { s->failed_pc=0x0c08d05eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c08d060;
P_0c08d060: /* original 8b11, guest PC 0x0c08d060 */
if(!s->budget--) { s->failed_pc=0x0c08d060u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d086; }
goto P_0c08d062;
P_0c08d062: /* original c736, guest PC 0x0c08d062 */
if(!s->budget--) { s->failed_pc=0x0c08d062u; return 0; }
r[0]=code_base|0x0008d13cu;
goto P_0c08d064;
P_0c08d064: /* original f308, guest PC 0x0c08d064 */
if(!s->budget--) { s->failed_pc=0x0c08d064u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c08d066;
P_0c08d066: /* original f535, guest PC 0x0c08d066 */
if(!s->budget--) { s->failed_pc=0x0c08d066u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c08d068;
P_0c08d068: /* original 891a, guest PC 0x0c08d068 */
if(!s->budget--) { s->failed_pc=0x0c08d068u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d0a0; }
goto P_0c08d06a;
P_0c08d06a: /* original d535, guest PC 0x0c08d06a */
if(!s->budget--) { s->failed_pc=0x0c08d06au; return 0; }
r[5]=read(ram,0x0c08d140u,4);
goto P_0c08d06c;
P_0c08d06c: /* original 56e7, guest PC 0x0c08d06c */
if(!s->budget--) { s->failed_pc=0x0c08d06cu; return 0; }
r[6]=read(ram,r[14]+28,4);
goto P_0c08d06e;
P_0c08d06e: /* original 2658, guest PC 0x0c08d06e */
if(!s->budget--) { s->failed_pc=0x0c08d06eu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c08d070;
P_0c08d070: /* original 8f09, guest PC 0x0c08d070 */
if(!s->budget--) { s->failed_pc=0x0c08d070u; return 0; }
cond=r[17]&1u;
r[4]=read(ram,r[14]+16,4);
if(!cond) { goto P_0c08d086; }
goto P_0c08d074;
P_0c08d072: /* original 54e4, guest PC 0x0c08d072 */
if(!s->budget--) { s->failed_pc=0x0c08d072u; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c08d074;
P_0c08d074: /* original e04c, guest PC 0x0c08d074 */
if(!s->budget--) { s->failed_pc=0x0c08d074u; return 0; }
r[0]=0x0000004cu;
goto P_0c08d076;
P_0c08d076: /* original 06ee, guest PC 0x0c08d076 */
if(!s->budget--) { s->failed_pc=0x0c08d076u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c08d078;
P_0c08d078: /* original e050, guest PC 0x0c08d078 */
if(!s->budget--) { s->failed_pc=0x0c08d078u; return 0; }
r[0]=0x00000050u;
goto P_0c08d07a;
P_0c08d07a: /* original 066e, guest PC 0x0c08d07a */
if(!s->budget--) { s->failed_pc=0x0c08d07au; return 0; }
r[6]=read(ram,r[6]+r[0],4);
goto P_0c08d07c;
P_0c08d07c: /* original 2658, guest PC 0x0c08d07c */
if(!s->budget--) { s->failed_pc=0x0c08d07cu; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[5])==0)!=0);
goto P_0c08d07e;
P_0c08d07e: /* original 8b0f, guest PC 0x0c08d07e */
if(!s->budget--) { s->failed_pc=0x0c08d07eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08d0a0; }
goto P_0c08d080;
P_0c08d080: /* original d330, guest PC 0x0c08d080 */
if(!s->budget--) { s->failed_pc=0x0c08d080u; return 0; }
r[3]=read(ram,0x0c08d144u,4);
goto P_0c08d082;
P_0c08d082: /* original 2438, guest PC 0x0c08d082 */
if(!s->budget--) { s->failed_pc=0x0c08d082u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c08d084;
P_0c08d084: /* original 890c, guest PC 0x0c08d084 */
if(!s->budget--) { s->failed_pc=0x0c08d084u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c08d0a0; }
goto P_0c08d086;
P_0c08d086: /* original e040, guest PC 0x0c08d086 */
if(!s->budget--) { s->failed_pc=0x0c08d086u; return 0; }
r[0]=0x00000040u;
goto P_0c08d088;
P_0c08d088: /* original 62e2, guest PC 0x0c08d088 */
if(!s->budget--) { s->failed_pc=0x0c08d088u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c08d08a;
P_0c08d08a: /* original e3fe, guest PC 0x0c08d08a */
if(!s->budget--) { s->failed_pc=0x0c08d08au; return 0; }
r[3]=0xfffffffeu;
goto P_0c08d08c;
P_0c08d08c: /* original 2239, guest PC 0x0c08d08c */
if(!s->budget--) { s->failed_pc=0x0c08d08cu; return 0; }
r[2]&=r[3];
goto P_0c08d08e;
P_0c08d08e: /* original 2e22, guest PC 0x0c08d08e */
if(!s->budget--) { s->failed_pc=0x0c08d08eu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c08d090;
P_0c08d090: /* original 1ecb, guest PC 0x0c08d090 */
if(!s->budget--) { s->failed_pc=0x0c08d090u; return 0; }
write(ram,r[14]+44,r[12],4);
goto P_0c08d092;
P_0c08d092: /* original 0dc4, guest PC 0x0c08d092 */
if(!s->budget--) { s->failed_pc=0x0c08d092u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d094;
P_0c08d094: /* original e02c, guest PC 0x0c08d094 */
if(!s->budget--) { s->failed_pc=0x0c08d094u; return 0; }
r[0]=0x0000002cu;
goto P_0c08d096;
P_0c08d096: /* original 0dc4, guest PC 0x0c08d096 */
if(!s->budget--) { s->failed_pc=0x0c08d096u; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d098;
P_0c08d098: /* original e02d, guest PC 0x0c08d098 */
if(!s->budget--) { s->failed_pc=0x0c08d098u; return 0; }
r[0]=0x0000002du;
goto P_0c08d09a;
P_0c08d09a: /* original 0dc4, guest PC 0x0c08d09a */
if(!s->budget--) { s->failed_pc=0x0c08d09au; return 0; }
write(ram,r[13]+r[0],r[12],1);
goto P_0c08d09c;
P_0c08d09c: /* original 60c3, guest PC 0x0c08d09c */
if(!s->budget--) { s->failed_pc=0x0c08d09cu; return 0; }
r[0]=r[12];
goto P_0c08d09e;
P_0c08d09e: /* original 81da, guest PC 0x0c08d09e */
if(!s->budget--) { s->failed_pc=0x0c08d09eu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d0a0;
P_0c08d0a0: /* original 4f26, guest PC 0x0c08d0a0 */
if(!s->budget--) { s->failed_pc=0x0c08d0a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d0a2;
P_0c08d0a2: /* original 6cf6, guest PC 0x0c08d0a2 */
if(!s->budget--) { s->failed_pc=0x0c08d0a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08d0a4;
P_0c08d0a4: /* original 6df6, guest PC 0x0c08d0a4 */
if(!s->budget--) { s->failed_pc=0x0c08d0a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d0a6;
P_0c08d0a6: /* original 000b, guest PC 0x0c08d0a6 */
if(!s->budget--) { s->failed_pc=0x0c08d0a6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d0a8: /* original 6ef6, guest PC 0x0c08d0a8 */
if(!s->budget--) { s->failed_pc=0x0c08d0a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c08d0aa;
P_0c08d0aa: /* original 2fe6, guest PC 0x0c08d0aa */
if(!s->budget--) { s->failed_pc=0x0c08d0aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d0ac;
P_0c08d0ac: /* original e048, guest PC 0x0c08d0ac */
if(!s->budget--) { s->failed_pc=0x0c08d0acu; return 0; }
r[0]=0x00000048u;
goto P_0c08d0ae;
P_0c08d0ae: /* original 2fd6, guest PC 0x0c08d0ae */
if(!s->budget--) { s->failed_pc=0x0c08d0aeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08d0b0;
P_0c08d0b0: /* original 6d43, guest PC 0x0c08d0b0 */
if(!s->budget--) { s->failed_pc=0x0c08d0b0u; return 0; }
r[13]=r[4];
goto P_0c08d0b2;
P_0c08d0b2: /* original 00dc, guest PC 0x0c08d0b2 */
if(!s->budget--) { s->failed_pc=0x0c08d0b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d0b4;
P_0c08d0b4: /* original 4f22, guest PC 0x0c08d0b4 */
if(!s->budget--) { s->failed_pc=0x0c08d0b4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08d0b6;
P_0c08d0b6: /* original 8801, guest PC 0x0c08d0b6 */
if(!s->budget--) { s->failed_pc=0x0c08d0b6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c08d0b8;
P_0c08d0b8: /* original 8d15, guest PC 0x0c08d0b8 */
if(!s->budget--) { s->failed_pc=0x0c08d0b8u; return 0; }
cond=r[17]&1u;
r[14]=r[5];
if(cond) { goto P_0c08d0e6; }
goto P_0c08d0bc;
P_0c08d0ba: /* original 6e53, guest PC 0x0c08d0ba */
if(!s->budget--) { s->failed_pc=0x0c08d0bau; return 0; }
r[14]=r[5];
goto P_0c08d0bc;
P_0c08d0bc: /* original 9439, guest PC 0x0c08d0bc */
if(!s->budget--) { s->failed_pc=0x0c08d0bcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08d132u,2);
goto P_0c08d0be;
P_0c08d0be: /* original e028, guest PC 0x0c08d0be */
if(!s->budget--) { s->failed_pc=0x0c08d0beu; return 0; }
r[0]=0x00000028u;
goto P_0c08d0c0;
P_0c08d0c0: /* original e500, guest PC 0x0c08d0c0 */
if(!s->budget--) { s->failed_pc=0x0c08d0c0u; return 0; }
r[5]=0x00000000u;
goto P_0c08d0c2;
P_0c08d0c2: /* original 0d45, guest PC 0x0c08d0c2 */
if(!s->budget--) { s->failed_pc=0x0c08d0c2u; return 0; }
write(ram,r[13]+r[0],r[4],2);
goto P_0c08d0c4;
P_0c08d0c4: /* original e040, guest PC 0x0c08d0c4 */
if(!s->budget--) { s->failed_pc=0x0c08d0c4u; return 0; }
r[0]=0x00000040u;
goto P_0c08d0c6;
P_0c08d0c6: /* original 1e4d, guest PC 0x0c08d0c6 */
if(!s->budget--) { s->failed_pc=0x0c08d0c6u; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c08d0c8;
P_0c08d0c8: /* original 0e56, guest PC 0x0c08d0c8 */
if(!s->budget--) { s->failed_pc=0x0c08d0c8u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c08d0ca;
P_0c08d0ca: /* original b045, guest PC 0x0c08d0ca */
if(!s->budget--) { s->failed_pc=0x0c08d0cau; return 0; }
target=code_base|0x0c08d158u; r[16]=code_base|0x0c08d0ceu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08d0ceu) { target=s->pc; goto dispatch; }
goto P_0c08d0ce;
P_0c08d0cc: /* original 64e3, guest PC 0x0c08d0cc */
if(!s->budget--) { s->failed_pc=0x0c08d0ccu; return 0; }
r[4]=r[14];
goto P_0c08d0ce;
P_0c08d0ce: /* original e02c, guest PC 0x0c08d0ce */
if(!s->budget--) { s->failed_pc=0x0c08d0ceu; return 0; }
r[0]=0x0000002cu;
goto P_0c08d0d0;
P_0c08d0d0: /* original e200, guest PC 0x0c08d0d0 */
if(!s->budget--) { s->failed_pc=0x0c08d0d0u; return 0; }
r[2]=0x00000000u;
goto P_0c08d0d2;
P_0c08d0d2: /* original 0d24, guest PC 0x0c08d0d2 */
if(!s->budget--) { s->failed_pc=0x0c08d0d2u; return 0; }
write(ram,r[13]+r[0],r[2],1);
goto P_0c08d0d4;
P_0c08d0d4: /* original e02d, guest PC 0x0c08d0d4 */
if(!s->budget--) { s->failed_pc=0x0c08d0d4u; return 0; }
r[0]=0x0000002du;
goto P_0c08d0d6;
P_0c08d0d6: /* original 53ee, guest PC 0x0c08d0d6 */
if(!s->budget--) { s->failed_pc=0x0c08d0d6u; return 0; }
r[3]=read(ram,r[14]+56,4);
goto P_0c08d0d8;
P_0c08d0d8: /* original 0d34, guest PC 0x0c08d0d8 */
if(!s->budget--) { s->failed_pc=0x0c08d0d8u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d0da;
P_0c08d0da: /* original 50ef, guest PC 0x0c08d0da */
if(!s->budget--) { s->failed_pc=0x0c08d0dau; return 0; }
r[0]=read(ram,r[14]+60,4);
goto P_0c08d0dc;
P_0c08d0dc: /* original 81da, guest PC 0x0c08d0dc */
if(!s->budget--) { s->failed_pc=0x0c08d0dcu; return 0; }
write(ram,r[13]+20,r[0],2);
goto P_0c08d0de;
P_0c08d0de: /* original e048, guest PC 0x0c08d0de */
if(!s->budget--) { s->failed_pc=0x0c08d0deu; return 0; }
r[0]=0x00000048u;
goto P_0c08d0e0;
P_0c08d0e0: /* original 03dc, guest PC 0x0c08d0e0 */
if(!s->budget--) { s->failed_pc=0x0c08d0e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+r[0],1);
goto P_0c08d0e2;
P_0c08d0e2: /* original 7301, guest PC 0x0c08d0e2 */
if(!s->budget--) { s->failed_pc=0x0c08d0e2u; return 0; }
r[3]+=0x00000001u;
goto P_0c08d0e4;
P_0c08d0e4: /* original 0d34, guest PC 0x0c08d0e4 */
if(!s->budget--) { s->failed_pc=0x0c08d0e4u; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08d0e6;
P_0c08d0e6: /* original 4f26, guest PC 0x0c08d0e6 */
if(!s->budget--) { s->failed_pc=0x0c08d0e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08d0e8;
P_0c08d0e8: /* original 6df6, guest PC 0x0c08d0e8 */
if(!s->budget--) { s->failed_pc=0x0c08d0e8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08d0ea;
P_0c08d0ea: /* original 000b, guest PC 0x0c08d0ea */
if(!s->budget--) { s->failed_pc=0x0c08d0eau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08d0ec: /* original 6ef6, guest PC 0x0c08d0ec */
if(!s->budget--) { s->failed_pc=0x0c08d0ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08d0eeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08d0eeu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
