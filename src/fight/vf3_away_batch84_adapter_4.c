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
int vf3_away_batch84_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0abea8u: goto P_0c0abea8;
case 0x0c0abeaau: goto P_0c0abeaa;
case 0x0c0abeacu: goto P_0c0abeac;
case 0x0c0abeaeu: goto P_0c0abeae;
case 0x0c0abeb0u: goto P_0c0abeb0;
case 0x0c0abeb2u: goto P_0c0abeb2;
case 0x0c0abeb4u: goto P_0c0abeb4;
case 0x0c0abeb6u: goto P_0c0abeb6;
case 0x0c0abeb8u: goto P_0c0abeb8;
case 0x0c0abebau: goto P_0c0abeba;
case 0x0c0abebcu: goto P_0c0abebc;
case 0x0c0abebeu: goto P_0c0abebe;
case 0x0c0abec0u: goto P_0c0abec0;
case 0x0c0abec2u: goto P_0c0abec2;
case 0x0c0abec4u: goto P_0c0abec4;
case 0x0c0abec6u: goto P_0c0abec6;
case 0x0c0abec8u: goto P_0c0abec8;
case 0x0c0abecau: goto P_0c0abeca;
case 0x0c0abeccu: goto P_0c0abecc;
case 0x0c0abeceu: goto P_0c0abece;
case 0x0c0abed0u: goto P_0c0abed0;
case 0x0c0abed2u: goto P_0c0abed2;
case 0x0c0abed4u: goto P_0c0abed4;
case 0x0c0abed6u: goto P_0c0abed6;
case 0x0c0abed8u: goto P_0c0abed8;
case 0x0c0abedau: goto P_0c0abeda;
case 0x0c0abedcu: goto P_0c0abedc;
case 0x0c0abedeu: goto P_0c0abede;
case 0x0c0abee0u: goto P_0c0abee0;
case 0x0c0abee2u: goto P_0c0abee2;
case 0x0c0abee4u: goto P_0c0abee4;
case 0x0c0abee6u: goto P_0c0abee6;
case 0x0c0abee8u: goto P_0c0abee8;
case 0x0c0abeeau: goto P_0c0abeea;
case 0x0c0abeecu: goto P_0c0abeec;
case 0x0c0abeeeu: goto P_0c0abeee;
case 0x0c0abef0u: goto P_0c0abef0;
case 0x0c0abef2u: goto P_0c0abef2;
case 0x0c0abef4u: goto P_0c0abef4;
case 0x0c0abef6u: goto P_0c0abef6;
case 0x0c0abef8u: goto P_0c0abef8;
case 0x0c0abefau: goto P_0c0abefa;
case 0x0c0abefcu: goto P_0c0abefc;
case 0x0c0abefeu: goto P_0c0abefe;
case 0x0c0abf00u: goto P_0c0abf00;
case 0x0c0abf02u: goto P_0c0abf02;
case 0x0c0abf04u: goto P_0c0abf04;
case 0x0c0abf06u: goto P_0c0abf06;
case 0x0c0abf08u: goto P_0c0abf08;
case 0x0c0abf0au: goto P_0c0abf0a;
case 0x0c0abf0cu: goto P_0c0abf0c;
case 0x0c0abf0eu: goto P_0c0abf0e;
case 0x0c0abf10u: goto P_0c0abf10;
case 0x0c0abf12u: goto P_0c0abf12;
case 0x0c0abf14u: goto P_0c0abf14;
case 0x0c0abf16u: goto P_0c0abf16;
case 0x0c0abf18u: goto P_0c0abf18;
case 0x0c0abf1au: goto P_0c0abf1a;
case 0x0c0abf1cu: goto P_0c0abf1c;
case 0x0c0abf48u: goto P_0c0abf48;
case 0x0c0abf4au: goto P_0c0abf4a;
case 0x0c0abf4cu: goto P_0c0abf4c;
case 0x0c0abf4eu: goto P_0c0abf4e;
case 0x0c0abf50u: goto P_0c0abf50;
case 0x0c0abf52u: goto P_0c0abf52;
case 0x0c0abf54u: goto P_0c0abf54;
case 0x0c0abf56u: goto P_0c0abf56;
case 0x0c0abf58u: goto P_0c0abf58;
case 0x0c0abf5au: goto P_0c0abf5a;
case 0x0c0abf5cu: goto P_0c0abf5c;
case 0x0c0abf5eu: goto P_0c0abf5e;
case 0x0c0abf60u: goto P_0c0abf60;
case 0x0c0abf62u: goto P_0c0abf62;
case 0x0c0abf64u: goto P_0c0abf64;
case 0x0c0abf66u: goto P_0c0abf66;
case 0x0c0abf68u: goto P_0c0abf68;
case 0x0c0abf6au: goto P_0c0abf6a;
case 0x0c0abf6cu: goto P_0c0abf6c;
case 0x0c0abf6eu: goto P_0c0abf6e;
case 0x0c0abf70u: goto P_0c0abf70;
case 0x0c0abf72u: goto P_0c0abf72;
case 0x0c0abf74u: goto P_0c0abf74;
case 0x0c0abf76u: goto P_0c0abf76;
case 0x0c0abf78u: goto P_0c0abf78;
case 0x0c0abf7au: goto P_0c0abf7a;
case 0x0c0abf7cu: goto P_0c0abf7c;
case 0x0c0abf7eu: goto P_0c0abf7e;
case 0x0c0abf80u: goto P_0c0abf80;
case 0x0c0abf82u: goto P_0c0abf82;
case 0x0c0abf84u: goto P_0c0abf84;
case 0x0c0abf86u: goto P_0c0abf86;
case 0x0c0abf88u: goto P_0c0abf88;
case 0x0c0abf8au: goto P_0c0abf8a;
case 0x0c0abf8cu: goto P_0c0abf8c;
case 0x0c0abf8eu: goto P_0c0abf8e;
case 0x0c0abf90u: goto P_0c0abf90;
case 0x0c0abf92u: goto P_0c0abf92;
case 0x0c0abf94u: goto P_0c0abf94;
case 0x0c0abf96u: goto P_0c0abf96;
case 0x0c0abf98u: goto P_0c0abf98;
case 0x0c0abf9au: goto P_0c0abf9a;
case 0x0c0abf9cu: goto P_0c0abf9c;
case 0x0c0abf9eu: goto P_0c0abf9e;
case 0x0c0abfa0u: goto P_0c0abfa0;
case 0x0c0abfa2u: goto P_0c0abfa2;
case 0x0c0abfa4u: goto P_0c0abfa4;
case 0x0c0abfa6u: goto P_0c0abfa6;
case 0x0c0abfa8u: goto P_0c0abfa8;
case 0x0c0abfaau: goto P_0c0abfaa;
case 0x0c0abfacu: goto P_0c0abfac;
case 0x0c0abfaeu: goto P_0c0abfae;
case 0x0c0abfb0u: goto P_0c0abfb0;
case 0x0c0abfb2u: goto P_0c0abfb2;
case 0x0c0abfb4u: goto P_0c0abfb4;
case 0x0c0abfb6u: goto P_0c0abfb6;
case 0x0c0abfb8u: goto P_0c0abfb8;
case 0x0c0abfbau: goto P_0c0abfba;
case 0x0c0abfbcu: goto P_0c0abfbc;
case 0x0c0abfbeu: goto P_0c0abfbe;
case 0x0c0abfc0u: goto P_0c0abfc0;
case 0x0c0abfc2u: goto P_0c0abfc2;
case 0x0c0abfc4u: goto P_0c0abfc4;
case 0x0c0abfc6u: goto P_0c0abfc6;
case 0x0c0abfc8u: goto P_0c0abfc8;
case 0x0c0abfcau: goto P_0c0abfca;
case 0x0c0abfccu: goto P_0c0abfcc;
case 0x0c0abfceu: goto P_0c0abfce;
case 0x0c0abfd0u: goto P_0c0abfd0;
case 0x0c0abfd2u: goto P_0c0abfd2;
case 0x0c0abfd4u: goto P_0c0abfd4;
case 0x0c0abfd6u: goto P_0c0abfd6;
case 0x0c0abfd8u: goto P_0c0abfd8;
case 0x0c0abfdau: goto P_0c0abfda;
case 0x0c0abfdcu: goto P_0c0abfdc;
case 0x0c0abfdeu: goto P_0c0abfde;
case 0x0c0abfe0u: goto P_0c0abfe0;
case 0x0c0abfe2u: goto P_0c0abfe2;
case 0x0c0abfe4u: goto P_0c0abfe4;
case 0x0c0abfe6u: goto P_0c0abfe6;
case 0x0c0abfe8u: goto P_0c0abfe8;
case 0x0c0abfeau: goto P_0c0abfea;
case 0x0c0abfecu: goto P_0c0abfec;
case 0x0c0abfeeu: goto P_0c0abfee;
case 0x0c0abff0u: goto P_0c0abff0;
case 0x0c0abff2u: goto P_0c0abff2;
case 0x0c0abff4u: goto P_0c0abff4;
case 0x0c0abff6u: goto P_0c0abff6;
case 0x0c0abff8u: goto P_0c0abff8;
case 0x0c0abffau: goto P_0c0abffa;
case 0x0c0abffcu: goto P_0c0abffc;
case 0x0c0abffeu: goto P_0c0abffe;
case 0x0c0ac000u: goto P_0c0ac000;
case 0x0c0ac002u: goto P_0c0ac002;
case 0x0c0ac004u: goto P_0c0ac004;
case 0x0c0ac006u: goto P_0c0ac006;
case 0x0c0ac008u: goto P_0c0ac008;
case 0x0c0ac00au: goto P_0c0ac00a;
case 0x0c0ac00cu: goto P_0c0ac00c;
case 0x0c0ac00eu: goto P_0c0ac00e;
case 0x0c0ac010u: goto P_0c0ac010;
case 0x0c0ac012u: goto P_0c0ac012;
case 0x0c0ac014u: goto P_0c0ac014;
case 0x0c0ac016u: goto P_0c0ac016;
case 0x0c0ac018u: goto P_0c0ac018;
case 0x0c0ac01au: goto P_0c0ac01a;
case 0x0c0ac01cu: goto P_0c0ac01c;
case 0x0c0ac01eu: goto P_0c0ac01e;
case 0x0c0ac020u: goto P_0c0ac020;
case 0x0c0ac022u: goto P_0c0ac022;
case 0x0c0ac024u: goto P_0c0ac024;
case 0x0c0ac026u: goto P_0c0ac026;
case 0x0c0ac028u: goto P_0c0ac028;
case 0x0c0ac02au: goto P_0c0ac02a;
case 0x0c0ac02cu: goto P_0c0ac02c;
case 0x0c0ac02eu: goto P_0c0ac02e;
case 0x0c0ac030u: goto P_0c0ac030;
case 0x0c0ac032u: goto P_0c0ac032;
case 0x0c0ac034u: goto P_0c0ac034;
case 0x0c0ac036u: goto P_0c0ac036;
case 0x0c0ac038u: goto P_0c0ac038;
case 0x0c0ac03au: goto P_0c0ac03a;
case 0x0c0ac03cu: goto P_0c0ac03c;
case 0x0c0ac03eu: goto P_0c0ac03e;
case 0x0c0ac040u: goto P_0c0ac040;
case 0x0c0ac042u: goto P_0c0ac042;
case 0x0c0ac044u: goto P_0c0ac044;
case 0x0c0ac046u: goto P_0c0ac046;
case 0x0c0ac048u: goto P_0c0ac048;
case 0x0c0ac04au: goto P_0c0ac04a;
case 0x0c0ac04cu: goto P_0c0ac04c;
case 0x0c0ac04eu: goto P_0c0ac04e;
case 0x0c0ac050u: goto P_0c0ac050;
case 0x0c0ac052u: goto P_0c0ac052;
case 0x0c0ac054u: goto P_0c0ac054;
case 0x0c0ac078u: goto P_0c0ac078;
case 0x0c0ac07au: goto P_0c0ac07a;
case 0x0c0ac07cu: goto P_0c0ac07c;
case 0x0c0ac07eu: goto P_0c0ac07e;
case 0x0c0ac080u: goto P_0c0ac080;
case 0x0c0ac082u: goto P_0c0ac082;
case 0x0c0ac084u: goto P_0c0ac084;
case 0x0c0ac086u: goto P_0c0ac086;
case 0x0c0ac088u: goto P_0c0ac088;
case 0x0c0ac08au: goto P_0c0ac08a;
case 0x0c0ac08cu: goto P_0c0ac08c;
case 0x0c0ac08eu: goto P_0c0ac08e;
case 0x0c0ac090u: goto P_0c0ac090;
case 0x0c0ac092u: goto P_0c0ac092;
case 0x0c0ac094u: goto P_0c0ac094;
case 0x0c0ac096u: goto P_0c0ac096;
case 0x0c0ac098u: goto P_0c0ac098;
case 0x0c0ac09au: goto P_0c0ac09a;
case 0x0c0ac09cu: goto P_0c0ac09c;
case 0x0c0ac09eu: goto P_0c0ac09e;
case 0x0c0ac0a0u: goto P_0c0ac0a0;
case 0x0c0ac0a2u: goto P_0c0ac0a2;
case 0x0c0ac0a4u: goto P_0c0ac0a4;
case 0x0c0ac0a6u: goto P_0c0ac0a6;
case 0x0c0ac0a8u: goto P_0c0ac0a8;
case 0x0c0ac0aau: goto P_0c0ac0aa;
case 0x0c0ac0acu: goto P_0c0ac0ac;
case 0x0c0ac0aeu: goto P_0c0ac0ae;
case 0x0c0ac0b0u: goto P_0c0ac0b0;
case 0x0c0ac0b2u: goto P_0c0ac0b2;
case 0x0c0ac0b4u: goto P_0c0ac0b4;
case 0x0c0ac0b6u: goto P_0c0ac0b6;
case 0x0c0ac0b8u: goto P_0c0ac0b8;
case 0x0c0ac0bau: goto P_0c0ac0ba;
case 0x0c0ac0bcu: goto P_0c0ac0bc;
case 0x0c0ac0beu: goto P_0c0ac0be;
case 0x0c0ac0c0u: goto P_0c0ac0c0;
case 0x0c0ac0c2u: goto P_0c0ac0c2;
case 0x0c0ac0c4u: goto P_0c0ac0c4;
case 0x0c0ac0c6u: goto P_0c0ac0c6;
case 0x0c0ac0c8u: goto P_0c0ac0c8;
case 0x0c0ac0cau: goto P_0c0ac0ca;
case 0x0c0ac0ccu: goto P_0c0ac0cc;
case 0x0c0ac0ceu: goto P_0c0ac0ce;
case 0x0c0ac0d0u: goto P_0c0ac0d0;
case 0x0c0ac0d2u: goto P_0c0ac0d2;
case 0x0c0ac0d4u: goto P_0c0ac0d4;
case 0x0c0ac0d6u: goto P_0c0ac0d6;
case 0x0c0ac0d8u: goto P_0c0ac0d8;
case 0x0c0ac0dau: goto P_0c0ac0da;
case 0x0c0ac0dcu: goto P_0c0ac0dc;
case 0x0c0ac0deu: goto P_0c0ac0de;
case 0x0c0ac0e0u: goto P_0c0ac0e0;
case 0x0c0ac0e2u: goto P_0c0ac0e2;
case 0x0c0ac0e4u: goto P_0c0ac0e4;
case 0x0c0ac0e6u: goto P_0c0ac0e6;
case 0x0c0ac0e8u: goto P_0c0ac0e8;
case 0x0c0ac0eau: goto P_0c0ac0ea;
case 0x0c0ac0ecu: goto P_0c0ac0ec;
case 0x0c0ac0eeu: goto P_0c0ac0ee;
case 0x0c0ac0f0u: goto P_0c0ac0f0;
case 0x0c0ac0f2u: goto P_0c0ac0f2;
case 0x0c0ac0f4u: goto P_0c0ac0f4;
case 0x0c0ac0f6u: goto P_0c0ac0f6;
case 0x0c0ac0f8u: goto P_0c0ac0f8;
case 0x0c0ac0fau: goto P_0c0ac0fa;
case 0x0c0ac0fcu: goto P_0c0ac0fc;
case 0x0c0ac0feu: goto P_0c0ac0fe;
case 0x0c0ac100u: goto P_0c0ac100;
case 0x0c0ac102u: goto P_0c0ac102;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0abea8: /* original 2fe6, guest PC 0x0c0abea8 */
if(!s->budget--) { s->failed_pc=0x0c0abea8u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abeaa;
P_0c0abeaa: /* original 6e43, guest PC 0x0c0abeaa */
if(!s->budget--) { s->failed_pc=0x0c0abeaau; return 0; }
r[14]=r[4];
goto P_0c0abeac;
P_0c0abeac: /* original 2fd6, guest PC 0x0c0abeac */
if(!s->budget--) { s->failed_pc=0x0c0abeacu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abeae;
P_0c0abeae: /* original 6d53, guest PC 0x0c0abeae */
if(!s->budget--) { s->failed_pc=0x0c0abeaeu; return 0; }
r[13]=r[5];
goto P_0c0abeb0;
P_0c0abeb0: /* original 2fc6, guest PC 0x0c0abeb0 */
if(!s->budget--) { s->failed_pc=0x0c0abeb0u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abeb2;
P_0c0abeb2: /* original e028, guest PC 0x0c0abeb2 */
if(!s->budget--) { s->failed_pc=0x0c0abeb2u; return 0; }
r[0]=0x00000028u;
goto P_0c0abeb4;
P_0c0abeb4: /* original d322, guest PC 0x0c0abeb4 */
if(!s->budget--) { s->failed_pc=0x0c0abeb4u; return 0; }
r[3]=read(ram,0x0c0abf40u,4);
goto P_0c0abeb6;
P_0c0abeb6: /* original 62e2, guest PC 0x0c0abeb6 */
if(!s->budget--) { s->failed_pc=0x0c0abeb6u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0abeb8;
P_0c0abeb8: /* original 4f22, guest PC 0x0c0abeb8 */
if(!s->budget--) { s->failed_pc=0x0c0abeb8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abeba;
P_0c0abeba: /* original 223b, guest PC 0x0c0abeba */
if(!s->budget--) { s->failed_pc=0x0c0abebau; return 0; }
r[2]|=r[3];
goto P_0c0abebc;
P_0c0abebc: /* original 2e22, guest PC 0x0c0abebc */
if(!s->budget--) { s->failed_pc=0x0c0abebcu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abebe;
P_0c0abebe: /* original f38d, guest PC 0x0c0abebe */
if(!s->budget--) { s->failed_pc=0x0c0abebeu; return 0; }
fr[3]=0;
goto P_0c0abec0;
P_0c0abec0: /* original 7ffc, guest PC 0x0c0abec0 */
if(!s->budget--) { s->failed_pc=0x0c0abec0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0abec2;
P_0c0abec2: /* original fe37, guest PC 0x0c0abec2 */
if(!s->budget--) { s->failed_pc=0x0c0abec2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abec4;
P_0c0abec4: /* original 64d2, guest PC 0x0c0abec4 */
if(!s->budget--) { s->failed_pc=0x0c0abec4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0abec6;
P_0c0abec6: /* original 624d, guest PC 0x0c0abec6 */
if(!s->budget--) { s->failed_pc=0x0c0abec6u; return 0; }
r[2]=r[4]&65535u;
goto P_0c0abec8;
P_0c0abec8: /* original 4429, guest PC 0x0c0abec8 */
if(!s->budget--) { s->failed_pc=0x0c0abec8u; return 0; }
r[4]>>=16;
goto P_0c0abeca;
P_0c0abeca: /* original 2f22, guest PC 0x0c0abeca */
if(!s->budget--) { s->failed_pc=0x0c0abecau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0abecc;
P_0c0abecc: /* original 6c4c, guest PC 0x0c0abecc */
if(!s->budget--) { s->failed_pc=0x0c0abeccu; return 0; }
r[12]=r[4]&255u;
goto P_0c0abece;
P_0c0abece: /* original 60c3, guest PC 0x0c0abece */
if(!s->budget--) { s->failed_pc=0x0c0abeceu; return 0; }
r[0]=r[12];
goto P_0c0abed0;
P_0c0abed0: /* original 8801, guest PC 0x0c0abed0 */
if(!s->budget--) { s->failed_pc=0x0c0abed0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abed2;
P_0c0abed2: /* original 8b07, guest PC 0x0c0abed2 */
if(!s->budget--) { s->failed_pc=0x0c0abed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abee4; }
goto P_0c0abed4;
P_0c0abed4: /* original 7f04, guest PC 0x0c0abed4 */
if(!s->budget--) { s->failed_pc=0x0c0abed4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abed6;
P_0c0abed6: /* original 65d3, guest PC 0x0c0abed6 */
if(!s->budget--) { s->failed_pc=0x0c0abed6u; return 0; }
r[5]=r[13];
goto P_0c0abed8;
P_0c0abed8: /* original 4f26, guest PC 0x0c0abed8 */
if(!s->budget--) { s->failed_pc=0x0c0abed8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abeda;
P_0c0abeda: /* original 64e3, guest PC 0x0c0abeda */
if(!s->budget--) { s->failed_pc=0x0c0abedau; return 0; }
r[4]=r[14];
goto P_0c0abedc;
P_0c0abedc: /* original 6cf6, guest PC 0x0c0abedc */
if(!s->budget--) { s->failed_pc=0x0c0abedcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abede;
P_0c0abede: /* original 6df6, guest PC 0x0c0abede */
if(!s->budget--) { s->failed_pc=0x0c0abedeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abee0;
P_0c0abee0: /* original a154, guest PC 0x0c0abee0 */
if(!s->budget--) { s->failed_pc=0x0c0abee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac18cu,s,ram);
P_0c0abee2: /* original 6ef6, guest PC 0x0c0abee2 */
if(!s->budget--) { s->failed_pc=0x0c0abee2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abee4;
P_0c0abee4: /* original d317, guest PC 0x0c0abee4 */
if(!s->budget--) { s->failed_pc=0x0c0abee4u; return 0; }
r[3]=read(ram,0x0c0abf44u,4);
goto P_0c0abee6;
P_0c0abee6: /* original 65f2, guest PC 0x0c0abee6 */
if(!s->budget--) { s->failed_pc=0x0c0abee6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0abee8;
P_0c0abee8: /* original 430b, guest PC 0x0c0abee8 */
if(!s->budget--) { s->failed_pc=0x0c0abee8u; return 0; }
target=r[3];
r[16]=code_base|0x0c0abeecu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abeecu) { target=s->pc; goto dispatch; }
goto P_0c0abeec;
P_0c0abeea: /* original 64e3, guest PC 0x0c0abeea */
if(!s->budget--) { s->failed_pc=0x0c0abeeau; return 0; }
r[4]=r[14];
goto P_0c0abeec;
P_0c0abeec: /* original 60c3, guest PC 0x0c0abeec */
if(!s->budget--) { s->failed_pc=0x0c0abeecu; return 0; }
r[0]=r[12];
goto P_0c0abeee;
P_0c0abeee: /* original 8802, guest PC 0x0c0abeee */
if(!s->budget--) { s->failed_pc=0x0c0abeeeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0abef0;
P_0c0abef0: /* original 8b07, guest PC 0x0c0abef0 */
if(!s->budget--) { s->failed_pc=0x0c0abef0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abf02; }
goto P_0c0abef2;
P_0c0abef2: /* original 7f04, guest PC 0x0c0abef2 */
if(!s->budget--) { s->failed_pc=0x0c0abef2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abef4;
P_0c0abef4: /* original 65d3, guest PC 0x0c0abef4 */
if(!s->budget--) { s->failed_pc=0x0c0abef4u; return 0; }
r[5]=r[13];
goto P_0c0abef6;
P_0c0abef6: /* original 4f26, guest PC 0x0c0abef6 */
if(!s->budget--) { s->failed_pc=0x0c0abef6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abef8;
P_0c0abef8: /* original 64e3, guest PC 0x0c0abef8 */
if(!s->budget--) { s->failed_pc=0x0c0abef8u; return 0; }
r[4]=r[14];
goto P_0c0abefa;
P_0c0abefa: /* original 6cf6, guest PC 0x0c0abefa */
if(!s->budget--) { s->failed_pc=0x0c0abefau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abefc;
P_0c0abefc: /* original 6df6, guest PC 0x0c0abefc */
if(!s->budget--) { s->failed_pc=0x0c0abefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abefe;
P_0c0abefe: /* original a101, guest PC 0x0c0abefe */
if(!s->budget--) { s->failed_pc=0x0c0abefeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac104u,s,ram);
P_0c0abf00: /* original 6ef6, guest PC 0x0c0abf00 */
if(!s->budget--) { s->failed_pc=0x0c0abf00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf02;
P_0c0abf02: /* original 7f04, guest PC 0x0c0abf02 */
if(!s->budget--) { s->failed_pc=0x0c0abf02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abf04;
P_0c0abf04: /* original 52d1, guest PC 0x0c0abf04 */
if(!s->budget--) { s->failed_pc=0x0c0abf04u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0abf06;
P_0c0abf06: /* original 4f26, guest PC 0x0c0abf06 */
if(!s->budget--) { s->failed_pc=0x0c0abf06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf08;
P_0c0abf08: /* original 7201, guest PC 0x0c0abf08 */
if(!s->budget--) { s->failed_pc=0x0c0abf08u; return 0; }
r[2]+=0x00000001u;
goto P_0c0abf0a;
P_0c0abf0a: /* original 65d3, guest PC 0x0c0abf0a */
if(!s->budget--) { s->failed_pc=0x0c0abf0au; return 0; }
r[5]=r[13];
goto P_0c0abf0c;
P_0c0abf0c: /* original 1d21, guest PC 0x0c0abf0c */
if(!s->budget--) { s->failed_pc=0x0c0abf0cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0abf0e;
P_0c0abf0e: /* original 6323, guest PC 0x0c0abf0e */
if(!s->budget--) { s->failed_pc=0x0c0abf0eu; return 0; }
r[3]=r[2];
goto P_0c0abf10;
P_0c0abf10: /* original e062, guest PC 0x0c0abf10 */
if(!s->budget--) { s->failed_pc=0x0c0abf10u; return 0; }
r[0]=0x00000062u;
goto P_0c0abf12;
P_0c0abf12: /* original 64e3, guest PC 0x0c0abf12 */
if(!s->budget--) { s->failed_pc=0x0c0abf12u; return 0; }
r[4]=r[14];
goto P_0c0abf14;
P_0c0abf14: /* original 0e34, guest PC 0x0c0abf14 */
if(!s->budget--) { s->failed_pc=0x0c0abf14u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abf16;
P_0c0abf16: /* original 6cf6, guest PC 0x0c0abf16 */
if(!s->budget--) { s->failed_pc=0x0c0abf16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abf18;
P_0c0abf18: /* original 6df6, guest PC 0x0c0abf18 */
if(!s->budget--) { s->failed_pc=0x0c0abf18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf1a;
P_0c0abf1a: /* original a015, guest PC 0x0c0abf1a */
if(!s->budget--) { s->failed_pc=0x0c0abf1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf48;
P_0c0abf1c: /* original 6ef6, guest PC 0x0c0abf1c */
if(!s->budget--) { s->failed_pc=0x0c0abf1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0abf1eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0abf1eu; return 0; } return 1;
P_0c0abf48: /* original 2fe6, guest PC 0x0c0abf48 */
if(!s->budget--) { s->failed_pc=0x0c0abf48u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abf4a;
P_0c0abf4a: /* original 6e43, guest PC 0x0c0abf4a */
if(!s->budget--) { s->failed_pc=0x0c0abf4au; return 0; }
r[14]=r[4];
goto P_0c0abf4c;
P_0c0abf4c: /* original e03e, guest PC 0x0c0abf4c */
if(!s->budget--) { s->failed_pc=0x0c0abf4cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abf4e;
P_0c0abf4e: /* original 2fd6, guest PC 0x0c0abf4e */
if(!s->budget--) { s->failed_pc=0x0c0abf4eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abf50;
P_0c0abf50: /* original 03ed, guest PC 0x0c0abf50 */
if(!s->budget--) { s->failed_pc=0x0c0abf50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abf52;
P_0c0abf52: /* original 9080, guest PC 0x0c0abf52 */
if(!s->budget--) { s->failed_pc=0x0c0abf52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac056u,2);
goto P_0c0abf54;
P_0c0abf54: /* original 4f22, guest PC 0x0c0abf54 */
if(!s->budget--) { s->failed_pc=0x0c0abf54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abf56;
P_0c0abf56: /* original 02ed, guest PC 0x0c0abf56 */
if(!s->budget--) { s->failed_pc=0x0c0abf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abf58;
P_0c0abf58: /* original 3322, guest PC 0x0c0abf58 */
if(!s->budget--) { s->failed_pc=0x0c0abf58u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0abf5a;
P_0c0abf5a: /* original 8f1e, guest PC 0x0c0abf5a */
if(!s->budget--) { s->failed_pc=0x0c0abf5au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0abf9a; }
goto P_0c0abf5e;
P_0c0abf5c: /* original 6d53, guest PC 0x0c0abf5c */
if(!s->budget--) { s->failed_pc=0x0c0abf5cu; return 0; }
r[13]=r[5];
goto P_0c0abf5e;
P_0c0abf5e: /* original 907b, guest PC 0x0c0abf5e */
if(!s->budget--) { s->failed_pc=0x0c0abf5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac058u,2);
goto P_0c0abf60;
P_0c0abf60: /* original 66e3, guest PC 0x0c0abf60 */
if(!s->budget--) { s->failed_pc=0x0c0abf60u; return 0; }
r[6]=r[14];
goto P_0c0abf62;
P_0c0abf62: /* original 65e3, guest PC 0x0c0abf62 */
if(!s->budget--) { s->failed_pc=0x0c0abf62u; return 0; }
r[5]=r[14];
goto P_0c0abf64;
P_0c0abf64: /* original 7648, guest PC 0x0c0abf64 */
if(!s->budget--) { s->failed_pc=0x0c0abf64u; return 0; }
r[6]+=0x00000048u;
goto P_0c0abf66;
P_0c0abf66: /* original f3e6, guest PC 0x0c0abf66 */
if(!s->budget--) { s->failed_pc=0x0c0abf66u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf68;
P_0c0abf68: /* original e024, guest PC 0x0c0abf68 */
if(!s->budget--) { s->failed_pc=0x0c0abf68u; return 0; }
r[0]=0x00000024u;
goto P_0c0abf6a;
P_0c0abf6a: /* original fe37, guest PC 0x0c0abf6a */
if(!s->budget--) { s->failed_pc=0x0c0abf6au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf6c;
P_0c0abf6c: /* original 9075, guest PC 0x0c0abf6c */
if(!s->budget--) { s->failed_pc=0x0c0abf6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05au,2);
goto P_0c0abf6e;
P_0c0abf6e: /* original f3e6, guest PC 0x0c0abf6e */
if(!s->budget--) { s->failed_pc=0x0c0abf6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf70;
P_0c0abf70: /* original e028, guest PC 0x0c0abf70 */
if(!s->budget--) { s->failed_pc=0x0c0abf70u; return 0; }
r[0]=0x00000028u;
goto P_0c0abf72;
P_0c0abf72: /* original fe37, guest PC 0x0c0abf72 */
if(!s->budget--) { s->failed_pc=0x0c0abf72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf74;
P_0c0abf74: /* original 9072, guest PC 0x0c0abf74 */
if(!s->budget--) { s->failed_pc=0x0c0abf74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05cu,2);
goto P_0c0abf76;
P_0c0abf76: /* original f3e6, guest PC 0x0c0abf76 */
if(!s->budget--) { s->failed_pc=0x0c0abf76u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf78;
P_0c0abf78: /* original e02c, guest PC 0x0c0abf78 */
if(!s->budget--) { s->failed_pc=0x0c0abf78u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abf7a;
P_0c0abf7a: /* original fe37, guest PC 0x0c0abf7a */
if(!s->budget--) { s->failed_pc=0x0c0abf7au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf7c;
P_0c0abf7c: /* original d339, guest PC 0x0c0abf7c */
if(!s->budget--) { s->failed_pc=0x0c0abf7cu; return 0; }
r[3]=read(ram,0x0c0ac064u,4);
goto P_0c0abf7e;
P_0c0abf7e: /* original 430b, guest PC 0x0c0abf7e */
if(!s->budget--) { s->failed_pc=0x0c0abf7eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0abf82u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abf82u) { target=s->pc; goto dispatch; }
goto P_0c0abf82;
P_0c0abf80: /* original 64e3, guest PC 0x0c0abf80 */
if(!s->budget--) { s->failed_pc=0x0c0abf80u; return 0; }
r[4]=r[14];
goto P_0c0abf82;
P_0c0abf82: /* original 52d1, guest PC 0x0c0abf82 */
if(!s->budget--) { s->failed_pc=0x0c0abf82u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0abf84;
P_0c0abf84: /* original 65d3, guest PC 0x0c0abf84 */
if(!s->budget--) { s->failed_pc=0x0c0abf84u; return 0; }
r[5]=r[13];
goto P_0c0abf86;
P_0c0abf86: /* original 4f26, guest PC 0x0c0abf86 */
if(!s->budget--) { s->failed_pc=0x0c0abf86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf88;
P_0c0abf88: /* original 7201, guest PC 0x0c0abf88 */
if(!s->budget--) { s->failed_pc=0x0c0abf88u; return 0; }
r[2]+=0x00000001u;
goto P_0c0abf8a;
P_0c0abf8a: /* original 64e3, guest PC 0x0c0abf8a */
if(!s->budget--) { s->failed_pc=0x0c0abf8au; return 0; }
r[4]=r[14];
goto P_0c0abf8c;
P_0c0abf8c: /* original 1d21, guest PC 0x0c0abf8c */
if(!s->budget--) { s->failed_pc=0x0c0abf8cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0abf8e;
P_0c0abf8e: /* original e062, guest PC 0x0c0abf8e */
if(!s->budget--) { s->failed_pc=0x0c0abf8eu; return 0; }
r[0]=0x00000062u;
goto P_0c0abf90;
P_0c0abf90: /* original 6323, guest PC 0x0c0abf90 */
if(!s->budget--) { s->failed_pc=0x0c0abf90u; return 0; }
r[3]=r[2];
goto P_0c0abf92;
P_0c0abf92: /* original 0e34, guest PC 0x0c0abf92 */
if(!s->budget--) { s->failed_pc=0x0c0abf92u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abf94;
P_0c0abf94: /* original 6df6, guest PC 0x0c0abf94 */
if(!s->budget--) { s->failed_pc=0x0c0abf94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf96;
P_0c0abf96: /* original a06f, guest PC 0x0c0abf96 */
if(!s->budget--) { s->failed_pc=0x0c0abf96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac078;
P_0c0abf98: /* original 6ef6, guest PC 0x0c0abf98 */
if(!s->budget--) { s->failed_pc=0x0c0abf98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf9a;
P_0c0abf9a: /* original 4f26, guest PC 0x0c0abf9a */
if(!s->budget--) { s->failed_pc=0x0c0abf9au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf9c;
P_0c0abf9c: /* original 6df6, guest PC 0x0c0abf9c */
if(!s->budget--) { s->failed_pc=0x0c0abf9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf9e;
P_0c0abf9e: /* original 000b, guest PC 0x0c0abf9e */
if(!s->budget--) { s->failed_pc=0x0c0abf9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abfa0: /* original 6ef6, guest PC 0x0c0abfa0 */
if(!s->budget--) { s->failed_pc=0x0c0abfa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abfa2;
P_0c0abfa2: /* original 2fe6, guest PC 0x0c0abfa2 */
if(!s->budget--) { s->failed_pc=0x0c0abfa2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0abfa4;
P_0c0abfa4: /* original 6e43, guest PC 0x0c0abfa4 */
if(!s->budget--) { s->failed_pc=0x0c0abfa4u; return 0; }
r[14]=r[4];
goto P_0c0abfa6;
P_0c0abfa6: /* original fffb, guest PC 0x0c0abfa6 */
if(!s->budget--) { s->failed_pc=0x0c0abfa6u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0abfa8;
P_0c0abfa8: /* original ffeb, guest PC 0x0c0abfa8 */
if(!s->budget--) { s->failed_pc=0x0c0abfa8u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0abfaa;
P_0c0abfaa: /* original ffdb, guest PC 0x0c0abfaa */
if(!s->budget--) { s->failed_pc=0x0c0abfaau; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0abfac;
P_0c0abfac: /* original ffcb, guest PC 0x0c0abfac */
if(!s->budget--) { s->failed_pc=0x0c0abfacu; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0abfae;
P_0c0abfae: /* original 4f22, guest PC 0x0c0abfae */
if(!s->budget--) { s->failed_pc=0x0c0abfaeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abfb0;
P_0c0abfb0: /* original 7fe8, guest PC 0x0c0abfb0 */
if(!s->budget--) { s->failed_pc=0x0c0abfb0u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0abfb2;
P_0c0abfb2: /* original 1f55, guest PC 0x0c0abfb2 */
if(!s->budget--) { s->failed_pc=0x0c0abfb2u; return 0; }
write(ram,r[15]+20,r[5],4);
goto P_0c0abfb4;
P_0c0abfb4: /* original 65f3, guest PC 0x0c0abfb4 */
if(!s->budget--) { s->failed_pc=0x0c0abfb4u; return 0; }
r[5]=r[15];
goto P_0c0abfb6;
P_0c0abfb6: /* original 9052, guest PC 0x0c0abfb6 */
if(!s->budget--) { s->failed_pc=0x0c0abfb6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05eu,2);
goto P_0c0abfb8;
P_0c0abfb8: /* original 66f3, guest PC 0x0c0abfb8 */
if(!s->budget--) { s->failed_pc=0x0c0abfb8u; return 0; }
r[6]=r[15];
goto P_0c0abfba;
P_0c0abfba: /* original d32b, guest PC 0x0c0abfba */
if(!s->budget--) { s->failed_pc=0x0c0abfbau; return 0; }
r[3]=read(ram,0x0c0ac068u,4);
goto P_0c0abfbc;
P_0c0abfbc: /* original 67f3, guest PC 0x0c0abfbc */
if(!s->budget--) { s->failed_pc=0x0c0abfbcu; return 0; }
r[7]=r[15];
goto P_0c0abfbe;
P_0c0abfbe: /* original 04ee, guest PC 0x0c0abfbe */
if(!s->budget--) { s->failed_pc=0x0c0abfbeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0abfc0;
P_0c0abfc0: /* original e008, guest PC 0x0c0abfc0 */
if(!s->budget--) { s->failed_pc=0x0c0abfc0u; return 0; }
r[0]=0x00000008u;
goto P_0c0abfc2;
P_0c0abfc2: /* original 7610, guest PC 0x0c0abfc2 */
if(!s->budget--) { s->failed_pc=0x0c0abfc2u; return 0; }
r[6]+=0x00000010u;
goto P_0c0abfc4;
P_0c0abfc4: /* original 7418, guest PC 0x0c0abfc4 */
if(!s->budget--) { s->failed_pc=0x0c0abfc4u; return 0; }
r[4]+=0x00000018u;
goto P_0c0abfc6;
P_0c0abfc6: /* original fe46, guest PC 0x0c0abfc6 */
if(!s->budget--) { s->failed_pc=0x0c0abfc6u; return 0; }
vf3_matrix_load(s,ram,14,r[4]+r[0]);
goto P_0c0abfc8;
P_0c0abfc8: /* original 7704, guest PC 0x0c0abfc8 */
if(!s->budget--) { s->failed_pc=0x0c0abfc8u; return 0; }
r[7]+=0x00000004u;
goto P_0c0abfca;
P_0c0abfca: /* original ff48, guest PC 0x0c0abfca */
if(!s->budget--) { s->failed_pc=0x0c0abfcau; return 0; }
vf3_matrix_load(s,ram,15,r[4]);
goto P_0c0abfcc;
P_0c0abfcc: /* original 64f3, guest PC 0x0c0abfcc */
if(!s->budget--) { s->failed_pc=0x0c0abfccu; return 0; }
r[4]=r[15];
goto P_0c0abfce;
P_0c0abfce: /* original f5ec, guest PC 0x0c0abfce */
if(!s->budget--) { s->failed_pc=0x0c0abfceu; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c0abfd0;
P_0c0abfd0: /* original 7508, guest PC 0x0c0abfd0 */
if(!s->budget--) { s->failed_pc=0x0c0abfd0u; return 0; }
r[5]+=0x00000008u;
goto P_0c0abfd2;
P_0c0abfd2: /* original f54d, guest PC 0x0c0abfd2 */
if(!s->budget--) { s->failed_pc=0x0c0abfd2u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0abfd4;
P_0c0abfd4: /* original 430b, guest PC 0x0c0abfd4 */
if(!s->budget--) { s->failed_pc=0x0c0abfd4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0abfd8u;
vf3_matrix_move(s,4,15);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abfd8u) { target=s->pc; goto dispatch; }
goto P_0c0abfd8;
P_0c0abfd6: /* original f4fc, guest PC 0x0c0abfd6 */
if(!s->budget--) { s->failed_pc=0x0c0abfd6u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0abfd8;
P_0c0abfd8: /* original 52f1, guest PC 0x0c0abfd8 */
if(!s->budget--) { s->failed_pc=0x0c0abfd8u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0abfda;
P_0c0abfda: /* original d324, guest PC 0x0c0abfda */
if(!s->budget--) { s->failed_pc=0x0c0abfdau; return 0; }
r[3]=read(ram,0x0c0ac06cu,4);
goto P_0c0abfdc;
P_0c0abfdc: /* original 223a, guest PC 0x0c0abfdc */
if(!s->budget--) { s->failed_pc=0x0c0abfdcu; return 0; }
r[2]^=r[3];
goto P_0c0abfde;
P_0c0abfde: /* original 1f21, guest PC 0x0c0abfde */
if(!s->budget--) { s->failed_pc=0x0c0abfdeu; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c0abfe0;
P_0c0abfe0: /* original 903e, guest PC 0x0c0abfe0 */
if(!s->budget--) { s->failed_pc=0x0c0abfe0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac060u,2);
goto P_0c0abfe2;
P_0c0abfe2: /* original f3e6, guest PC 0x0c0abfe2 */
if(!s->budget--) { s->failed_pc=0x0c0abfe2u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abfe4;
P_0c0abfe4: /* original e00c, guest PC 0x0c0abfe4 */
if(!s->budget--) { s->failed_pc=0x0c0abfe4u; return 0; }
r[0]=0x0000000cu;
goto P_0c0abfe6;
P_0c0abfe6: /* original ff37, guest PC 0x0c0abfe6 */
if(!s->budget--) { s->failed_pc=0x0c0abfe6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0abfe8;
P_0c0abfe8: /* original e008, guest PC 0x0c0abfe8 */
if(!s->budget--) { s->failed_pc=0x0c0abfe8u; return 0; }
r[0]=0x00000008u;
goto P_0c0abfea;
P_0c0abfea: /* original fcf6, guest PC 0x0c0abfea */
if(!s->budget--) { s->failed_pc=0x0c0abfeau; return 0; }
vf3_matrix_load(s,ram,12,r[15]+r[0]);
goto P_0c0abfec;
P_0c0abfec: /* original 54f1, guest PC 0x0c0abfec */
if(!s->budget--) { s->failed_pc=0x0c0abfecu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0abfee;
P_0c0abfee: /* original d220, guest PC 0x0c0abfee */
if(!s->budget--) { s->failed_pc=0x0c0abfeeu; return 0; }
r[2]=read(ram,0x0c0ac070u,4);
goto P_0c0abff0;
P_0c0abff0: /* original fdf8, guest PC 0x0c0abff0 */
if(!s->budget--) { s->failed_pc=0x0c0abff0u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
goto P_0c0abff2;
P_0c0abff2: /* original fc4d, guest PC 0x0c0abff2 */
if(!s->budget--) { s->failed_pc=0x0c0abff2u; return 0; }
fr[12]^=0x80000000u;
goto P_0c0abff4;
P_0c0abff4: /* original 420b, guest PC 0x0c0abff4 */
if(!s->budget--) { s->failed_pc=0x0c0abff4u; return 0; }
target=r[2];
r[16]=code_base|0x0c0abff8u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0abff8u) { target=s->pc; goto dispatch; }
goto P_0c0abff8;
P_0c0abff6: /* original 644f, guest PC 0x0c0abff6 */
if(!s->budget--) { s->failed_pc=0x0c0abff6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0abff8;
P_0c0abff8: /* original ff0a, guest PC 0x0c0abff8 */
if(!s->budget--) { s->failed_pc=0x0c0abff8u; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0abffa;
P_0c0abffa: /* original d31e, guest PC 0x0c0abffa */
if(!s->budget--) { s->failed_pc=0x0c0abffau; return 0; }
r[3]=read(ram,0x0c0ac074u,4);
goto P_0c0abffc;
P_0c0abffc: /* original 54f1, guest PC 0x0c0abffc */
if(!s->budget--) { s->failed_pc=0x0c0abffcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0abffe;
P_0c0abffe: /* original 430b, guest PC 0x0c0abffe */
if(!s->budget--) { s->failed_pc=0x0c0abffeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0ac002u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac002u) { target=s->pc; goto dispatch; }
goto P_0c0ac002;
P_0c0ac000: /* original 644f, guest PC 0x0c0ac000 */
if(!s->budget--) { s->failed_pc=0x0c0ac000u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0ac002;
P_0c0ac002: /* original e00c, guest PC 0x0c0ac002 */
if(!s->budget--) { s->failed_pc=0x0c0ac002u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac004;
P_0c0ac004: /* original f3f8, guest PC 0x0c0ac004 */
if(!s->budget--) { s->failed_pc=0x0c0ac004u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0ac006;
P_0c0ac006: /* original f2f6, guest PC 0x0c0ac006 */
if(!s->budget--) { s->failed_pc=0x0c0ac006u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0ac008;
P_0c0ac008: /* original e00c, guest PC 0x0c0ac008 */
if(!s->budget--) { s->failed_pc=0x0c0ac008u; return 0; }
r[0]=0x0000000cu;
goto P_0c0ac00a;
P_0c0ac00a: /* original f40c, guest PC 0x0c0ac00a */
if(!s->budget--) { s->failed_pc=0x0c0ac00au; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0ac00c;
P_0c0ac00c: /* original f232, guest PC 0x0c0ac00c */
if(!s->budget--) { s->failed_pc=0x0c0ac00cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0ac00e;
P_0c0ac00e: /* original fd20, guest PC 0x0c0ac00e */
if(!s->budget--) { s->failed_pc=0x0c0ac00eu; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[2],r[18],'+');
goto P_0c0ac010;
P_0c0ac010: /* original ff2a, guest PC 0x0c0ac010 */
if(!s->budget--) { s->failed_pc=0x0c0ac010u; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0ac012;
P_0c0ac012: /* original f34c, guest PC 0x0c0ac012 */
if(!s->budget--) { s->failed_pc=0x0c0ac012u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ac014;
P_0c0ac014: /* original f4f6, guest PC 0x0c0ac014 */
if(!s->budget--) { s->failed_pc=0x0c0ac014u; return 0; }
vf3_matrix_load(s,ram,4,r[15]+r[0]);
goto P_0c0ac016;
P_0c0ac016: /* original e010, guest PC 0x0c0ac016 */
if(!s->budget--) { s->failed_pc=0x0c0ac016u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac018;
P_0c0ac018: /* original f2e6, guest PC 0x0c0ac018 */
if(!s->budget--) { s->failed_pc=0x0c0ac018u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac01a;
P_0c0ac01a: /* original e018, guest PC 0x0c0ac01a */
if(!s->budget--) { s->failed_pc=0x0c0ac01au; return 0; }
r[0]=0x00000018u;
goto P_0c0ac01c;
P_0c0ac01c: /* original f432, guest PC 0x0c0ac01c */
if(!s->budget--) { s->failed_pc=0x0c0ac01cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0ac01e;
P_0c0ac01e: /* original f3fc, guest PC 0x0c0ac01e */
if(!s->budget--) { s->failed_pc=0x0c0ac01eu; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0ac020;
P_0c0ac020: /* original ffdc, guest PC 0x0c0ac020 */
if(!s->budget--) { s->failed_pc=0x0c0ac020u; return 0; }
vf3_matrix_move(s,15,13);
goto P_0c0ac022;
P_0c0ac022: /* original ff31, guest PC 0x0c0ac022 */
if(!s->budget--) { s->failed_pc=0x0c0ac022u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'-');
goto P_0c0ac024;
P_0c0ac024: /* original f3ec, guest PC 0x0c0ac024 */
if(!s->budget--) { s->failed_pc=0x0c0ac024u; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c0ac026;
P_0c0ac026: /* original fc40, guest PC 0x0c0ac026 */
if(!s->budget--) { s->failed_pc=0x0c0ac026u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[4],r[18],'+');
goto P_0c0ac028;
P_0c0ac028: /* original fecc, guest PC 0x0c0ac028 */
if(!s->budget--) { s->failed_pc=0x0c0ac028u; return 0; }
vf3_matrix_move(s,14,12);
goto P_0c0ac02a;
P_0c0ac02a: /* original fe31, guest PC 0x0c0ac02a */
if(!s->budget--) { s->failed_pc=0x0c0ac02au; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[3],r[18],'-');
goto P_0c0ac02c;
P_0c0ac02c: /* original ff2a, guest PC 0x0c0ac02c */
if(!s->budget--) { s->failed_pc=0x0c0ac02cu; return 0; }
vf3_matrix_store(s,ram,2,r[15]);
goto P_0c0ac02e;
P_0c0ac02e: /* original f32c, guest PC 0x0c0ac02e */
if(!s->budget--) { s->failed_pc=0x0c0ac02eu; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0ac030;
P_0c0ac030: /* original f3f0, guest PC 0x0c0ac030 */
if(!s->budget--) { s->failed_pc=0x0c0ac030u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[15],r[18],'+');
goto P_0c0ac032;
P_0c0ac032: /* original f4e6, guest PC 0x0c0ac032 */
if(!s->budget--) { s->failed_pc=0x0c0ac032u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0ac034;
P_0c0ac034: /* original e010, guest PC 0x0c0ac034 */
if(!s->budget--) { s->failed_pc=0x0c0ac034u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac036;
P_0c0ac036: /* original f4e0, guest PC 0x0c0ac036 */
if(!s->budget--) { s->failed_pc=0x0c0ac036u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[14],r[18],'+');
goto P_0c0ac038;
P_0c0ac038: /* original ff3a, guest PC 0x0c0ac038 */
if(!s->budget--) { s->failed_pc=0x0c0ac038u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0ac03a;
P_0c0ac03a: /* original fe37, guest PC 0x0c0ac03a */
if(!s->budget--) { s->failed_pc=0x0c0ac03au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac03c;
P_0c0ac03c: /* original e018, guest PC 0x0c0ac03c */
if(!s->budget--) { s->failed_pc=0x0c0ac03cu; return 0; }
r[0]=0x00000018u;
goto P_0c0ac03e;
P_0c0ac03e: /* original fe47, guest PC 0x0c0ac03e */
if(!s->budget--) { s->failed_pc=0x0c0ac03eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ac040;
P_0c0ac040: /* original 55f5, guest PC 0x0c0ac040 */
if(!s->budget--) { s->failed_pc=0x0c0ac040u; return 0; }
r[5]=read(ram,r[15]+20,4);
goto P_0c0ac042;
P_0c0ac042: /* original b04a, guest PC 0x0c0ac042 */
if(!s->budget--) { s->failed_pc=0x0c0ac042u; return 0; }
target=code_base|0x0c0ac0dau; r[16]=code_base|0x0c0ac046u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac046u) { target=s->pc; goto dispatch; }
goto P_0c0ac046;
P_0c0ac044: /* original 64e3, guest PC 0x0c0ac044 */
if(!s->budget--) { s->failed_pc=0x0c0ac044u; return 0; }
r[4]=r[14];
goto P_0c0ac046;
P_0c0ac046: /* original 7f18, guest PC 0x0c0ac046 */
if(!s->budget--) { s->failed_pc=0x0c0ac046u; return 0; }
r[15]+=0x00000018u;
goto P_0c0ac048;
P_0c0ac048: /* original 4f26, guest PC 0x0c0ac048 */
if(!s->budget--) { s->failed_pc=0x0c0ac048u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac04a;
P_0c0ac04a: /* original fcf9, guest PC 0x0c0ac04a */
if(!s->budget--) { s->failed_pc=0x0c0ac04au; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac04c;
P_0c0ac04c: /* original fdf9, guest PC 0x0c0ac04c */
if(!s->budget--) { s->failed_pc=0x0c0ac04cu; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac04e;
P_0c0ac04e: /* original fef9, guest PC 0x0c0ac04e */
if(!s->budget--) { s->failed_pc=0x0c0ac04eu; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac050;
P_0c0ac050: /* original fff9, guest PC 0x0c0ac050 */
if(!s->budget--) { s->failed_pc=0x0c0ac050u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0ac052;
P_0c0ac052: /* original 000b, guest PC 0x0c0ac052 */
if(!s->budget--) { s->failed_pc=0x0c0ac052u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac054: /* original 6ef6, guest PC 0x0c0ac054 */
if(!s->budget--) { s->failed_pc=0x0c0ac054u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0ac056u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0ac056u; return 0; } return 1;
P_0c0ac078: /* original 2fe6, guest PC 0x0c0ac078 */
if(!s->budget--) { s->failed_pc=0x0c0ac078u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac07a;
P_0c0ac07a: /* original 6e43, guest PC 0x0c0ac07a */
if(!s->budget--) { s->failed_pc=0x0c0ac07au; return 0; }
r[14]=r[4];
goto P_0c0ac07c;
P_0c0ac07c: /* original 2fd6, guest PC 0x0c0ac07c */
if(!s->budget--) { s->failed_pc=0x0c0ac07cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0ac07e;
P_0c0ac07e: /* original 9071, guest PC 0x0c0ac07e */
if(!s->budget--) { s->failed_pc=0x0c0ac07eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac164u,2);
goto P_0c0ac080;
P_0c0ac080: /* original 4f22, guest PC 0x0c0ac080 */
if(!s->budget--) { s->failed_pc=0x0c0ac080u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac082;
P_0c0ac082: /* original 00ec, guest PC 0x0c0ac082 */
if(!s->budget--) { s->failed_pc=0x0c0ac082u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ac084;
P_0c0ac084: /* original 600c, guest PC 0x0c0ac084 */
if(!s->budget--) { s->failed_pc=0x0c0ac084u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ac086;
P_0c0ac086: /* original c840, guest PC 0x0c0ac086 */
if(!s->budget--) { s->failed_pc=0x0c0ac086u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ac088;
P_0c0ac088: /* original 8d16, guest PC 0x0c0ac088 */
if(!s->budget--) { s->failed_pc=0x0c0ac088u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0ac0b8; }
goto P_0c0ac08c;
P_0c0ac08a: /* original 6d53, guest PC 0x0c0ac08a */
if(!s->budget--) { s->failed_pc=0x0c0ac08au; return 0; }
r[13]=r[5];
goto P_0c0ac08c;
P_0c0ac08c: /* original 906c, guest PC 0x0c0ac08c */
if(!s->budget--) { s->failed_pc=0x0c0ac08cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac08e;
P_0c0ac08e: /* original 936a, guest PC 0x0c0ac08e */
if(!s->budget--) { s->failed_pc=0x0c0ac08eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac166u,2);
goto P_0c0ac090;
P_0c0ac090: /* original 02ee, guest PC 0x0c0ac090 */
if(!s->budget--) { s->failed_pc=0x0c0ac090u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac092;
P_0c0ac092: /* original 2238, guest PC 0x0c0ac092 */
if(!s->budget--) { s->failed_pc=0x0c0ac092u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac094;
P_0c0ac094: /* original 8910, guest PC 0x0c0ac094 */
if(!s->budget--) { s->failed_pc=0x0c0ac094u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0b8; }
goto P_0c0ac096;
P_0c0ac096: /* original c737, guest PC 0x0c0ac096 */
if(!s->budget--) { s->failed_pc=0x0c0ac096u; return 0; }
r[0]=code_base|0x000ac174u;
goto P_0c0ac098;
P_0c0ac098: /* original f408, guest PC 0x0c0ac098 */
if(!s->budget--) { s->failed_pc=0x0c0ac098u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ac09a;
P_0c0ac09a: /* original e024, guest PC 0x0c0ac09a */
if(!s->budget--) { s->failed_pc=0x0c0ac09au; return 0; }
r[0]=0x00000024u;
goto P_0c0ac09c;
P_0c0ac09c: /* original f3e6, guest PC 0x0c0ac09c */
if(!s->budget--) { s->failed_pc=0x0c0ac09cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac09e;
P_0c0ac09e: /* original 9064, guest PC 0x0c0ac09e */
if(!s->budget--) { s->failed_pc=0x0c0ac09eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16au,2);
goto P_0c0ac0a0;
P_0c0ac0a0: /* original f04c, guest PC 0x0c0ac0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a0u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ac0a2;
P_0c0ac0a2: /* original f2e6, guest PC 0x0c0ac0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a2u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac0a4;
P_0c0ac0a4: /* original e024, guest PC 0x0c0ac0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a4u; return 0; }
r[0]=0x00000024u;
goto P_0c0ac0a6;
P_0c0ac0a6: /* original f32e, guest PC 0x0c0ac0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ac0a8;
P_0c0ac0a8: /* original fe37, guest PC 0x0c0ac0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac0aa;
P_0c0ac0aa: /* original e02c, guest PC 0x0c0ac0aa */
if(!s->budget--) { s->failed_pc=0x0c0ac0aau; return 0; }
r[0]=0x0000002cu;
goto P_0c0ac0ac;
P_0c0ac0ac: /* original f3e6, guest PC 0x0c0ac0ac */
if(!s->budget--) { s->failed_pc=0x0c0ac0acu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac0ae;
P_0c0ac0ae: /* original 905d, guest PC 0x0c0ac0ae */
if(!s->budget--) { s->failed_pc=0x0c0ac0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16cu,2);
goto P_0c0ac0b0;
P_0c0ac0b0: /* original f2e6, guest PC 0x0c0ac0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac0b2;
P_0c0ac0b2: /* original e02c, guest PC 0x0c0ac0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b2u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ac0b4;
P_0c0ac0b4: /* original f32e, guest PC 0x0c0ac0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ac0b6;
P_0c0ac0b6: /* original fe37, guest PC 0x0c0ac0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac0b8;
P_0c0ac0b8: /* original d32f, guest PC 0x0c0ac0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b8u; return 0; }
r[3]=read(ram,0x0c0ac178u,4);
goto P_0c0ac0ba;
P_0c0ac0ba: /* original 430b, guest PC 0x0c0ac0ba */
if(!s->budget--) { s->failed_pc=0x0c0ac0bau; return 0; }
target=r[3];
r[16]=code_base|0x0c0ac0beu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0ac0beu) { target=s->pc; goto dispatch; }
goto P_0c0ac0be;
P_0c0ac0bc: /* original 64e3, guest PC 0x0c0ac0bc */
if(!s->budget--) { s->failed_pc=0x0c0ac0bcu; return 0; }
r[4]=r[14];
goto P_0c0ac0be;
P_0c0ac0be: /* original 6403, guest PC 0x0c0ac0be */
if(!s->budget--) { s->failed_pc=0x0c0ac0beu; return 0; }
r[4]=r[0];
goto P_0c0ac0c0;
P_0c0ac0c0: /* original 2448, guest PC 0x0c0ac0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ac0c2;
P_0c0ac0c2: /* original 8d05, guest PC 0x0c0ac0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c2u; return 0; }
cond=r[17]&1u;
r[5]=r[13];
if(cond) { goto P_0c0ac0d0; }
goto P_0c0ac0c6;
P_0c0ac0c4: /* original 65d3, guest PC 0x0c0ac0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c4u; return 0; }
r[5]=r[13];
goto P_0c0ac0c6;
P_0c0ac0c6: /* original e205, guest PC 0x0c0ac0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c6u; return 0; }
r[2]=0x00000005u;
goto P_0c0ac0c8;
P_0c0ac0c8: /* original e062, guest PC 0x0c0ac0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c8u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac0ca;
P_0c0ac0ca: /* original 6323, guest PC 0x0c0ac0ca */
if(!s->budget--) { s->failed_pc=0x0c0ac0cau; return 0; }
r[3]=r[2];
goto P_0c0ac0cc;
P_0c0ac0cc: /* original 1d21, guest PC 0x0c0ac0cc */
if(!s->budget--) { s->failed_pc=0x0c0ac0ccu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ac0ce;
P_0c0ac0ce: /* original 0e34, guest PC 0x0c0ac0ce */
if(!s->budget--) { s->failed_pc=0x0c0ac0ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac0d0;
P_0c0ac0d0: /* original 4f26, guest PC 0x0c0ac0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac0d2;
P_0c0ac0d2: /* original 64e3, guest PC 0x0c0ac0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d2u; return 0; }
r[4]=r[14];
goto P_0c0ac0d4;
P_0c0ac0d4: /* original 6df6, guest PC 0x0c0ac0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ac0d6;
P_0c0ac0d6: /* original a000, guest PC 0x0c0ac0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac0da;
P_0c0ac0d8: /* original 6ef6, guest PC 0x0c0ac0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac0da;
P_0c0ac0da: /* original 6242, guest PC 0x0c0ac0da */
if(!s->budget--) { s->failed_pc=0x0c0ac0dau; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ac0dc;
P_0c0ac0dc: /* original d327, guest PC 0x0c0ac0dc */
if(!s->budget--) { s->failed_pc=0x0c0ac0dcu; return 0; }
r[3]=read(ram,0x0c0ac17cu,4);
goto P_0c0ac0de;
P_0c0ac0de: /* original 2238, guest PC 0x0c0ac0de */
if(!s->budget--) { s->failed_pc=0x0c0ac0deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac0e0;
P_0c0ac0e0: /* original 8b0e, guest PC 0x0c0ac0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac100; }
goto P_0c0ac0e2;
P_0c0ac0e2: /* original 9044, guest PC 0x0c0ac0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16eu,2);
goto P_0c0ac0e4;
P_0c0ac0e4: /* original e13e, guest PC 0x0c0ac0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e4u; return 0; }
r[1]=0x0000003eu;
goto P_0c0ac0e6;
P_0c0ac0e6: /* original 314c, guest PC 0x0c0ac0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e6u; return 0; }
r[1]+=r[4];
goto P_0c0ac0e8;
P_0c0ac0e8: /* original 004d, guest PC 0x0c0ac0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ac0ea;
P_0c0ac0ea: /* original 2101, guest PC 0x0c0ac0ea */
if(!s->budget--) { s->failed_pc=0x0c0ac0eau; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0ac0ec;
P_0c0ac0ec: /* original 903c, guest PC 0x0c0ac0ec */
if(!s->budget--) { s->failed_pc=0x0c0ac0ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac0ee;
P_0c0ac0ee: /* original d624, guest PC 0x0c0ac0ee */
if(!s->budget--) { s->failed_pc=0x0c0ac0eeu; return 0; }
r[6]=read(ram,0x0c0ac180u,4);
goto P_0c0ac0f0;
P_0c0ac0f0: /* original 034e, guest PC 0x0c0ac0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0ac0f2;
P_0c0ac0f2: /* original 2638, guest PC 0x0c0ac0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0ac0f4;
P_0c0ac0f4: /* original 8902, guest PC 0x0c0ac0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0fc; }
goto P_0c0ac0f6;
P_0c0ac0f6: /* original 903b, guest PC 0x0c0ac0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac170u,2);
goto P_0c0ac0f8;
P_0c0ac0f8: /* original e101, guest PC 0x0c0ac0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f8u; return 0; }
r[1]=0x00000001u;
goto P_0c0ac0fa;
P_0c0ac0fa: /* original 0414, guest PC 0x0c0ac0fa */
if(!s->budget--) { s->failed_pc=0x0c0ac0fau; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0ac0fc;
P_0c0ac0fc: /* original a020, guest PC 0x0c0ac0fc */
if(!s->budget--) { s->failed_pc=0x0c0ac0fcu; return 0; }
return vf3_matrix_family(0x0c0ac140u,s,ram);
P_0c0ac0fe: /* original 0009, guest PC 0x0c0ac0fe */
if(!s->budget--) { s->failed_pc=0x0c0ac0feu; return 0; }
goto P_0c0ac100;
P_0c0ac100: /* original 000b, guest PC 0x0c0ac100 */
if(!s->budget--) { s->failed_pc=0x0c0ac100u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ac102: /* original 0009, guest PC 0x0c0ac102 */
if(!s->budget--) { s->failed_pc=0x0c0ac102u; return 0; }
return vf3_matrix_family(0x0c0ac104u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
