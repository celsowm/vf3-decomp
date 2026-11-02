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
int vf3_away_batch11_adapter_34(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07ad58u: goto P_0c07ad58;
case 0x0c07ad5au: goto P_0c07ad5a;
case 0x0c07ad5cu: goto P_0c07ad5c;
case 0x0c07ad5eu: goto P_0c07ad5e;
case 0x0c07ad60u: goto P_0c07ad60;
case 0x0c07ad62u: goto P_0c07ad62;
case 0x0c07ad64u: goto P_0c07ad64;
case 0x0c07ad66u: goto P_0c07ad66;
case 0x0c07ad68u: goto P_0c07ad68;
case 0x0c07ad6au: goto P_0c07ad6a;
case 0x0c07ad6cu: goto P_0c07ad6c;
case 0x0c07ad6eu: goto P_0c07ad6e;
case 0x0c07ad70u: goto P_0c07ad70;
case 0x0c07ad72u: goto P_0c07ad72;
case 0x0c07ad74u: goto P_0c07ad74;
case 0x0c07ad76u: goto P_0c07ad76;
case 0x0c07ad78u: goto P_0c07ad78;
case 0x0c07ad7au: goto P_0c07ad7a;
case 0x0c07ad7cu: goto P_0c07ad7c;
case 0x0c07ad7eu: goto P_0c07ad7e;
case 0x0c07ad80u: goto P_0c07ad80;
case 0x0c07ad82u: goto P_0c07ad82;
case 0x0c07ad84u: goto P_0c07ad84;
case 0x0c07ad86u: goto P_0c07ad86;
case 0x0c07ad88u: goto P_0c07ad88;
case 0x0c07ad8au: goto P_0c07ad8a;
case 0x0c07ad8cu: goto P_0c07ad8c;
case 0x0c07ad8eu: goto P_0c07ad8e;
case 0x0c07ad90u: goto P_0c07ad90;
case 0x0c07ad92u: goto P_0c07ad92;
case 0x0c07ad94u: goto P_0c07ad94;
case 0x0c07af6cu: goto P_0c07af6c;
case 0x0c07af6eu: goto P_0c07af6e;
case 0x0c07af70u: goto P_0c07af70;
case 0x0c07af72u: goto P_0c07af72;
case 0x0c07af74u: goto P_0c07af74;
case 0x0c07af76u: goto P_0c07af76;
case 0x0c07af78u: goto P_0c07af78;
case 0x0c07af7au: goto P_0c07af7a;
case 0x0c07af7cu: goto P_0c07af7c;
case 0x0c07af7eu: goto P_0c07af7e;
case 0x0c07af80u: goto P_0c07af80;
case 0x0c07af82u: goto P_0c07af82;
case 0x0c07af84u: goto P_0c07af84;
case 0x0c07af86u: goto P_0c07af86;
case 0x0c07af88u: goto P_0c07af88;
case 0x0c07af8au: goto P_0c07af8a;
case 0x0c07af8cu: goto P_0c07af8c;
case 0x0c07af8eu: goto P_0c07af8e;
case 0x0c07af90u: goto P_0c07af90;
case 0x0c07af92u: goto P_0c07af92;
case 0x0c07af94u: goto P_0c07af94;
case 0x0c07af96u: goto P_0c07af96;
case 0x0c07af98u: goto P_0c07af98;
case 0x0c07af9au: goto P_0c07af9a;
case 0x0c07af9cu: goto P_0c07af9c;
case 0x0c07af9eu: goto P_0c07af9e;
case 0x0c07afa0u: goto P_0c07afa0;
case 0x0c07afa2u: goto P_0c07afa2;
case 0x0c07afa4u: goto P_0c07afa4;
case 0x0c07afa6u: goto P_0c07afa6;
case 0x0c07afa8u: goto P_0c07afa8;
case 0x0c07afaau: goto P_0c07afaa;
case 0x0c07afacu: goto P_0c07afac;
case 0x0c07afaeu: goto P_0c07afae;
case 0x0c07afb0u: goto P_0c07afb0;
case 0x0c07afb2u: goto P_0c07afb2;
case 0x0c07afb4u: goto P_0c07afb4;
case 0x0c07afb6u: goto P_0c07afb6;
case 0x0c07afb8u: goto P_0c07afb8;
case 0x0c07afbau: goto P_0c07afba;
case 0x0c07afbcu: goto P_0c07afbc;
case 0x0c07afbeu: goto P_0c07afbe;
case 0x0c07afc0u: goto P_0c07afc0;
case 0x0c07afc2u: goto P_0c07afc2;
case 0x0c07afc4u: goto P_0c07afc4;
case 0x0c07afc6u: goto P_0c07afc6;
case 0x0c07afc8u: goto P_0c07afc8;
case 0x0c07afcau: goto P_0c07afca;
case 0x0c07afccu: goto P_0c07afcc;
case 0x0c07afceu: goto P_0c07afce;
case 0x0c07afd0u: goto P_0c07afd0;
case 0x0c07afd2u: goto P_0c07afd2;
case 0x0c07afd4u: goto P_0c07afd4;
case 0x0c07afd6u: goto P_0c07afd6;
case 0x0c07afd8u: goto P_0c07afd8;
case 0x0c07afdau: goto P_0c07afda;
case 0x0c07afdcu: goto P_0c07afdc;
case 0x0c07afdeu: goto P_0c07afde;
case 0x0c07afe0u: goto P_0c07afe0;
case 0x0c07afe2u: goto P_0c07afe2;
case 0x0c07afe4u: goto P_0c07afe4;
case 0x0c07afe6u: goto P_0c07afe6;
case 0x0c07afe8u: goto P_0c07afe8;
case 0x0c07afeau: goto P_0c07afea;
case 0x0c07afecu: goto P_0c07afec;
case 0x0c07afeeu: goto P_0c07afee;
case 0x0c07aff0u: goto P_0c07aff0;
case 0x0c07aff2u: goto P_0c07aff2;
case 0x0c07aff4u: goto P_0c07aff4;
case 0x0c07aff6u: goto P_0c07aff6;
case 0x0c07aff8u: goto P_0c07aff8;
case 0x0c07affau: goto P_0c07affa;
case 0x0c07affcu: goto P_0c07affc;
case 0x0c07affeu: goto P_0c07affe;
case 0x0c07b0f4u: goto P_0c07b0f4;
case 0x0c07b0f6u: goto P_0c07b0f6;
case 0x0c07b0f8u: goto P_0c07b0f8;
case 0x0c07b0fau: goto P_0c07b0fa;
case 0x0c07b0fcu: goto P_0c07b0fc;
case 0x0c07b0feu: goto P_0c07b0fe;
case 0x0c07b100u: goto P_0c07b100;
case 0x0c07b102u: goto P_0c07b102;
case 0x0c07b104u: goto P_0c07b104;
case 0x0c07b106u: goto P_0c07b106;
case 0x0c07b108u: goto P_0c07b108;
case 0x0c07b10au: goto P_0c07b10a;
case 0x0c07b10cu: goto P_0c07b10c;
case 0x0c07b10eu: goto P_0c07b10e;
case 0x0c07b110u: goto P_0c07b110;
case 0x0c07b112u: goto P_0c07b112;
case 0x0c07b114u: goto P_0c07b114;
case 0x0c07b116u: goto P_0c07b116;
case 0x0c07b118u: goto P_0c07b118;
case 0x0c07b11au: goto P_0c07b11a;
case 0x0c07b11cu: goto P_0c07b11c;
case 0x0c07b11eu: goto P_0c07b11e;
case 0x0c07b120u: goto P_0c07b120;
case 0x0c07b122u: goto P_0c07b122;
case 0x0c07b124u: goto P_0c07b124;
case 0x0c07b126u: goto P_0c07b126;
case 0x0c07b128u: goto P_0c07b128;
case 0x0c07b12au: goto P_0c07b12a;
case 0x0c07b12cu: goto P_0c07b12c;
case 0x0c07b12eu: goto P_0c07b12e;
case 0x0c07b130u: goto P_0c07b130;
case 0x0c07b132u: goto P_0c07b132;
case 0x0c07b134u: goto P_0c07b134;
case 0x0c07b136u: goto P_0c07b136;
case 0x0c07b138u: goto P_0c07b138;
case 0x0c07b13au: goto P_0c07b13a;
case 0x0c07b13cu: goto P_0c07b13c;
case 0x0c07b13eu: goto P_0c07b13e;
case 0x0c07b140u: goto P_0c07b140;
case 0x0c07b142u: goto P_0c07b142;
case 0x0c07b144u: goto P_0c07b144;
case 0x0c07b146u: goto P_0c07b146;
case 0x0c07b148u: goto P_0c07b148;
case 0x0c07b14au: goto P_0c07b14a;
case 0x0c07b14cu: goto P_0c07b14c;
case 0x0c07b14eu: goto P_0c07b14e;
case 0x0c07b150u: goto P_0c07b150;
case 0x0c07b152u: goto P_0c07b152;
case 0x0c07b154u: goto P_0c07b154;
case 0x0c07b156u: goto P_0c07b156;
case 0x0c07b158u: goto P_0c07b158;
case 0x0c07b15au: goto P_0c07b15a;
case 0x0c07b15cu: goto P_0c07b15c;
case 0x0c07b15eu: goto P_0c07b15e;
case 0x0c07b160u: goto P_0c07b160;
case 0x0c07b162u: goto P_0c07b162;
case 0x0c07b164u: goto P_0c07b164;
case 0x0c07b166u: goto P_0c07b166;
case 0x0c07b168u: goto P_0c07b168;
case 0x0c07b16au: goto P_0c07b16a;
case 0x0c07b16cu: goto P_0c07b16c;
case 0x0c07b16eu: goto P_0c07b16e;
case 0x0c07b170u: goto P_0c07b170;
case 0x0c07b172u: goto P_0c07b172;
case 0x0c07b174u: goto P_0c07b174;
case 0x0c07b176u: goto P_0c07b176;
case 0x0c07b178u: goto P_0c07b178;
case 0x0c07b17au: goto P_0c07b17a;
case 0x0c07b17cu: goto P_0c07b17c;
case 0x0c07b17eu: goto P_0c07b17e;
case 0x0c07b180u: goto P_0c07b180;
case 0x0c07b182u: goto P_0c07b182;
case 0x0c07b184u: goto P_0c07b184;
case 0x0c07b186u: goto P_0c07b186;
case 0x0c07b188u: goto P_0c07b188;
case 0x0c07b18au: goto P_0c07b18a;
case 0x0c07b18cu: goto P_0c07b18c;
case 0x0c07b18eu: goto P_0c07b18e;
case 0x0c07b190u: goto P_0c07b190;
case 0x0c07b192u: goto P_0c07b192;
case 0x0c07b194u: goto P_0c07b194;
case 0x0c07b196u: goto P_0c07b196;
case 0x0c07b198u: goto P_0c07b198;
case 0x0c07b19au: goto P_0c07b19a;
case 0x0c07b19cu: goto P_0c07b19c;
case 0x0c07b19eu: goto P_0c07b19e;
case 0x0c07b1a0u: goto P_0c07b1a0;
case 0x0c07b1a2u: goto P_0c07b1a2;
case 0x0c07b1a4u: goto P_0c07b1a4;
case 0x0c07b1a6u: goto P_0c07b1a6;
case 0x0c07b1a8u: goto P_0c07b1a8;
case 0x0c07b1aau: goto P_0c07b1aa;
case 0x0c07b1acu: goto P_0c07b1ac;
case 0x0c07b1aeu: goto P_0c07b1ae;
case 0x0c07b1b0u: goto P_0c07b1b0;
case 0x0c07b1b2u: goto P_0c07b1b2;
case 0x0c07b1b4u: goto P_0c07b1b4;
case 0x0c07b1b6u: goto P_0c07b1b6;
case 0x0c07b1b8u: goto P_0c07b1b8;
case 0x0c07b1bau: goto P_0c07b1ba;
case 0x0c07b1bcu: goto P_0c07b1bc;
case 0x0c07b1beu: goto P_0c07b1be;
case 0x0c07b1c0u: goto P_0c07b1c0;
case 0x0c07b1c2u: goto P_0c07b1c2;
case 0x0c07b1c4u: goto P_0c07b1c4;
case 0x0c07b1c6u: goto P_0c07b1c6;
case 0x0c07b1c8u: goto P_0c07b1c8;
case 0x0c07b1cau: goto P_0c07b1ca;
case 0x0c07b1ccu: goto P_0c07b1cc;
case 0x0c07b1ceu: goto P_0c07b1ce;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07ad58: /* original 2fe6, guest PC 0x0c07ad58 */
if(!s->budget--) { s->failed_pc=0x0c07ad58u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad5a;
P_0c07ad5a: /* original ee38, guest PC 0x0c07ad5a */
if(!s->budget--) { s->failed_pc=0x0c07ad5au; return 0; }
r[14]=0x00000038u;
goto P_0c07ad5c;
P_0c07ad5c: /* original 2fd6, guest PC 0x0c07ad5c */
if(!s->budget--) { s->failed_pc=0x0c07ad5cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad5e;
P_0c07ad5e: /* original ed00, guest PC 0x0c07ad5e */
if(!s->budget--) { s->failed_pc=0x0c07ad5eu; return 0; }
r[13]=0x00000000u;
goto P_0c07ad60;
P_0c07ad60: /* original 2fc6, guest PC 0x0c07ad60 */
if(!s->budget--) { s->failed_pc=0x0c07ad60u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad62;
P_0c07ad62: /* original 2fb6, guest PC 0x0c07ad62 */
if(!s->budget--) { s->failed_pc=0x0c07ad62u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad64;
P_0c07ad64: /* original eb44, guest PC 0x0c07ad64 */
if(!s->budget--) { s->failed_pc=0x0c07ad64u; return 0; }
r[11]=0x00000044u;
goto P_0c07ad66;
P_0c07ad66: /* original 2fa6, guest PC 0x0c07ad66 */
if(!s->budget--) { s->failed_pc=0x0c07ad66u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ad68;
P_0c07ad68: /* original 4f22, guest PC 0x0c07ad68 */
if(!s->budget--) { s->failed_pc=0x0c07ad68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ad6a;
P_0c07ad6a: /* original dc2d, guest PC 0x0c07ad6a */
if(!s->budget--) { s->failed_pc=0x0c07ad6au; return 0; }
r[12]=read(ram,0x0c07ae20u,4);
goto P_0c07ad6c;
P_0c07ad6c: /* original da29, guest PC 0x0c07ad6c */
if(!s->budget--) { s->failed_pc=0x0c07ad6cu; return 0; }
r[10]=read(ram,0x0c07ae14u,4);
goto P_0c07ad6e;
P_0c07ad6e: /* original 64e3, guest PC 0x0c07ad6e */
if(!s->budget--) { s->failed_pc=0x0c07ad6eu; return 0; }
r[4]=r[14];
goto P_0c07ad70;
P_0c07ad70: /* original 4400, guest PC 0x0c07ad70 */
if(!s->budget--) { s->failed_pc=0x0c07ad70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07ad72;
P_0c07ad72: /* original 34ac, guest PC 0x0c07ad72 */
if(!s->budget--) { s->failed_pc=0x0c07ad72u; return 0; }
r[4]+=r[10];
goto P_0c07ad74;
P_0c07ad74: /* original 6341, guest PC 0x0c07ad74 */
if(!s->budget--) { s->failed_pc=0x0c07ad74u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[4],2);
r[3]=tmp;
goto P_0c07ad76;
P_0c07ad76: /* original 633d, guest PC 0x0c07ad76 */
if(!s->budget--) { s->failed_pc=0x0c07ad76u; return 0; }
r[3]=r[3]&65535u;
goto P_0c07ad78;
P_0c07ad78: /* original 33c0, guest PC 0x0c07ad78 */
if(!s->budget--) { s->failed_pc=0x0c07ad78u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[12])!=0);
goto P_0c07ad7a;
P_0c07ad7a: /* original 8b00, guest PC 0x0c07ad7a */
if(!s->budget--) { s->failed_pc=0x0c07ad7au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad7e; }
goto P_0c07ad7c;
P_0c07ad7c: /* original 24d1, guest PC 0x0c07ad7c */
if(!s->budget--) { s->failed_pc=0x0c07ad7cu; return 0; }
write(ram,r[4],r[13],2);
goto P_0c07ad7e;
P_0c07ad7e: /* original b437, guest PC 0x0c07ad7e */
if(!s->budget--) { s->failed_pc=0x0c07ad7eu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07ad82u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ad82u) { target=s->pc; goto dispatch; }
goto P_0c07ad82;
P_0c07ad80: /* original 64e3, guest PC 0x0c07ad80 */
if(!s->budget--) { s->failed_pc=0x0c07ad80u; return 0; }
r[4]=r[14];
goto P_0c07ad82;
P_0c07ad82: /* original 7e01, guest PC 0x0c07ad82 */
if(!s->budget--) { s->failed_pc=0x0c07ad82u; return 0; }
r[14]+=0x00000001u;
goto P_0c07ad84;
P_0c07ad84: /* original 3eb7, guest PC 0x0c07ad84 */
if(!s->budget--) { s->failed_pc=0x0c07ad84u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[14]>(int32_t)r[11])!=0);
goto P_0c07ad86;
P_0c07ad86: /* original 8bf2, guest PC 0x0c07ad86 */
if(!s->budget--) { s->failed_pc=0x0c07ad86u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07ad6e; }
goto P_0c07ad88;
P_0c07ad88: /* original 4f26, guest PC 0x0c07ad88 */
if(!s->budget--) { s->failed_pc=0x0c07ad88u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ad8a;
P_0c07ad8a: /* original 6af6, guest PC 0x0c07ad8a */
if(!s->budget--) { s->failed_pc=0x0c07ad8au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07ad8c;
P_0c07ad8c: /* original 6bf6, guest PC 0x0c07ad8c */
if(!s->budget--) { s->failed_pc=0x0c07ad8cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07ad8e;
P_0c07ad8e: /* original 6cf6, guest PC 0x0c07ad8e */
if(!s->budget--) { s->failed_pc=0x0c07ad8eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ad90;
P_0c07ad90: /* original 6df6, guest PC 0x0c07ad90 */
if(!s->budget--) { s->failed_pc=0x0c07ad90u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ad92;
P_0c07ad92: /* original 000b, guest PC 0x0c07ad92 */
if(!s->budget--) { s->failed_pc=0x0c07ad92u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07ad94: /* original 6ef6, guest PC 0x0c07ad94 */
if(!s->budget--) { s->failed_pc=0x0c07ad94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ad96u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ad96u; return 0; } return 1;
P_0c07af6c: /* original 2fe6, guest PC 0x0c07af6c */
if(!s->budget--) { s->failed_pc=0x0c07af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af6e;
P_0c07af6e: /* original 4511, guest PC 0x0c07af6e */
if(!s->budget--) { s->failed_pc=0x0c07af6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c07af70;
P_0c07af70: /* original 2fd6, guest PC 0x0c07af70 */
if(!s->budget--) { s->failed_pc=0x0c07af70u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af72;
P_0c07af72: /* original 2fc6, guest PC 0x0c07af72 */
if(!s->budget--) { s->failed_pc=0x0c07af72u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af74;
P_0c07af74: /* original 2fb6, guest PC 0x0c07af74 */
if(!s->budget--) { s->failed_pc=0x0c07af74u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af76;
P_0c07af76: /* original 2fa6, guest PC 0x0c07af76 */
if(!s->budget--) { s->failed_pc=0x0c07af76u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07af78;
P_0c07af78: /* original 4f22, guest PC 0x0c07af78 */
if(!s->budget--) { s->failed_pc=0x0c07af78u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07af7a;
P_0c07af7a: /* original d323, guest PC 0x0c07af7a */
if(!s->budget--) { s->failed_pc=0x0c07af7au; return 0; }
r[3]=read(ram,0x0c07b008u,4);
goto P_0c07af7c;
P_0c07af7c: /* original dd21, guest PC 0x0c07af7c */
if(!s->budget--) { s->failed_pc=0x0c07af7cu; return 0; }
r[13]=read(ram,0x0c07b004u,4);
goto P_0c07af7e;
P_0c07af7e: /* original 7ffc, guest PC 0x0c07af7e */
if(!s->budget--) { s->failed_pc=0x0c07af7eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07af80;
P_0c07af80: /* original 2f32, guest PC 0x0c07af80 */
if(!s->budget--) { s->failed_pc=0x0c07af80u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07af82;
P_0c07af82: /* original 5e46, guest PC 0x0c07af82 */
if(!s->budget--) { s->failed_pc=0x0c07af82u; return 0; }
r[14]=read(ram,r[4]+24,4);
goto P_0c07af84;
P_0c07af84: /* original 6ce3, guest PC 0x0c07af84 */
if(!s->budget--) { s->failed_pc=0x0c07af84u; return 0; }
r[12]=r[14];
goto P_0c07af86;
P_0c07af86: /* original 8d0f, guest PC 0x0c07af86 */
if(!s->budget--) { s->failed_pc=0x0c07af86u; return 0; }
cond=r[17]&1u;
r[12]+=0x00000001u;
if(cond) { goto P_0c07afa8; }
goto P_0c07af8a;
P_0c07af88: /* original 7c01, guest PC 0x0c07af88 */
if(!s->budget--) { s->failed_pc=0x0c07af88u; return 0; }
r[12]+=0x00000001u;
goto P_0c07af8a;
P_0c07af8a: /* original 60e3, guest PC 0x0c07af8a */
if(!s->budget--) { s->failed_pc=0x0c07af8au; return 0; }
r[0]=r[14];
goto P_0c07af8c;
P_0c07af8c: /* original 882c, guest PC 0x0c07af8c */
if(!s->budget--) { s->failed_pc=0x0c07af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07af8e;
P_0c07af8e: /* original 8902, guest PC 0x0c07af8e */
if(!s->budget--) { s->failed_pc=0x0c07af8eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07af96; }
goto P_0c07af90;
P_0c07af90: /* original 60e3, guest PC 0x0c07af90 */
if(!s->budget--) { s->failed_pc=0x0c07af90u; return 0; }
r[0]=r[14];
goto P_0c07af92;
P_0c07af92: /* original 8834, guest PC 0x0c07af92 */
if(!s->budget--) { s->failed_pc=0x0c07af92u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07af94;
P_0c07af94: /* original 8b03, guest PC 0x0c07af94 */
if(!s->budget--) { s->failed_pc=0x0c07af94u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07af9e; }
goto P_0c07af96;
P_0c07af96: /* original 60c3, guest PC 0x0c07af96 */
if(!s->budget--) { s->failed_pc=0x0c07af96u; return 0; }
r[0]=r[12];
goto P_0c07af98;
P_0c07af98: /* original e300, guest PC 0x0c07af98 */
if(!s->budget--) { s->failed_pc=0x0c07af98u; return 0; }
r[3]=0x00000000u;
goto P_0c07af9a;
P_0c07af9a: /* original 4000, guest PC 0x0c07af9a */
if(!s->budget--) { s->failed_pc=0x0c07af9au; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07af9c;
P_0c07af9c: /* original 0d35, guest PC 0x0c07af9c */
if(!s->budget--) { s->failed_pc=0x0c07af9cu; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07af9e;
P_0c07af9e: /* original 60e3, guest PC 0x0c07af9e */
if(!s->budget--) { s->failed_pc=0x0c07af9eu; return 0; }
r[0]=r[14];
goto P_0c07afa0;
P_0c07afa0: /* original e300, guest PC 0x0c07afa0 */
if(!s->budget--) { s->failed_pc=0x0c07afa0u; return 0; }
r[3]=0x00000000u;
goto P_0c07afa2;
P_0c07afa2: /* original 4000, guest PC 0x0c07afa2 */
if(!s->budget--) { s->failed_pc=0x0c07afa2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07afa4;
P_0c07afa4: /* original a01f, guest PC 0x0c07afa4 */
if(!s->budget--) { s->failed_pc=0x0c07afa4u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07afe6;
P_0c07afa6: /* original 0d35, guest PC 0x0c07afa6 */
if(!s->budget--) { s->failed_pc=0x0c07afa6u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07afa8;
P_0c07afa8: /* original 60e3, guest PC 0x0c07afa8 */
if(!s->budget--) { s->failed_pc=0x0c07afa8u; return 0; }
r[0]=r[14];
goto P_0c07afaa;
P_0c07afaa: /* original db19, guest PC 0x0c07afaa */
if(!s->budget--) { s->failed_pc=0x0c07afaau; return 0; }
r[11]=read(ram,0x0c07b010u,4);
goto P_0c07afac;
P_0c07afac: /* original da17, guest PC 0x0c07afac */
if(!s->budget--) { s->failed_pc=0x0c07afacu; return 0; }
r[10]=read(ram,0x0c07b00cu,4);
goto P_0c07afae;
P_0c07afae: /* original 882c, guest PC 0x0c07afae */
if(!s->budget--) { s->failed_pc=0x0c07afaeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07afb0;
P_0c07afb0: /* original 8b06, guest PC 0x0c07afb0 */
if(!s->budget--) { s->failed_pc=0x0c07afb0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07afc0; }
goto P_0c07afb2;
P_0c07afb2: /* original 4a0b, guest PC 0x0c07afb2 */
if(!s->budget--) { s->failed_pc=0x0c07afb2u; return 0; }
target=r[10];
r[16]=code_base|0x0c07afb6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afb6u) { target=s->pc; goto dispatch; }
goto P_0c07afb6;
P_0c07afb4: /* original 64e3, guest PC 0x0c07afb4 */
if(!s->budget--) { s->failed_pc=0x0c07afb4u; return 0; }
r[4]=r[14];
goto P_0c07afb6;
P_0c07afb6: /* original d417, guest PC 0x0c07afb6 */
if(!s->budget--) { s->failed_pc=0x0c07afb6u; return 0; }
r[4]=read(ram,0x0c07b014u,4);
goto P_0c07afb8;
P_0c07afb8: /* original bc25, guest PC 0x0c07afb8 */
if(!s->budget--) { s->failed_pc=0x0c07afb8u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07afbcu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afbcu) { target=s->pc; goto dispatch; }
goto P_0c07afbc;
P_0c07afba: /* original 65b2, guest PC 0x0c07afba */
if(!s->budget--) { s->failed_pc=0x0c07afbau; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c07afbc;
P_0c07afbc: /* original a007, guest PC 0x0c07afbc */
if(!s->budget--) { s->failed_pc=0x0c07afbcu; return 0; }
goto P_0c07afce;
P_0c07afbe: /* original 0009, guest PC 0x0c07afbe */
if(!s->budget--) { s->failed_pc=0x0c07afbeu; return 0; }
goto P_0c07afc0;
P_0c07afc0: /* original 8834, guest PC 0x0c07afc0 */
if(!s->budget--) { s->failed_pc=0x0c07afc0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07afc2;
P_0c07afc2: /* original 8b08, guest PC 0x0c07afc2 */
if(!s->budget--) { s->failed_pc=0x0c07afc2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07afd6; }
goto P_0c07afc4;
P_0c07afc4: /* original 4a0b, guest PC 0x0c07afc4 */
if(!s->budget--) { s->failed_pc=0x0c07afc4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07afc8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afc8u) { target=s->pc; goto dispatch; }
goto P_0c07afc8;
P_0c07afc6: /* original 64e3, guest PC 0x0c07afc6 */
if(!s->budget--) { s->failed_pc=0x0c07afc6u; return 0; }
r[4]=r[14];
goto P_0c07afc8;
P_0c07afc8: /* original d413, guest PC 0x0c07afc8 */
if(!s->budget--) { s->failed_pc=0x0c07afc8u; return 0; }
r[4]=read(ram,0x0c07b018u,4);
goto P_0c07afca;
P_0c07afca: /* original bc1c, guest PC 0x0c07afca */
if(!s->budget--) { s->failed_pc=0x0c07afcau; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07afceu;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afceu) { target=s->pc; goto dispatch; }
goto P_0c07afce;
P_0c07afcc: /* original 65b2, guest PC 0x0c07afcc */
if(!s->budget--) { s->failed_pc=0x0c07afccu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c07afce;
P_0c07afce: /* original 60c3, guest PC 0x0c07afce */
if(!s->budget--) { s->failed_pc=0x0c07afceu; return 0; }
r[0]=r[12];
goto P_0c07afd0;
P_0c07afd0: /* original 4000, guest PC 0x0c07afd0 */
if(!s->budget--) { s->failed_pc=0x0c07afd0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07afd2;
P_0c07afd2: /* original a005, guest PC 0x0c07afd2 */
if(!s->budget--) { s->failed_pc=0x0c07afd2u; return 0; }
write(ram,r[13]+r[0],r[12],2);
goto P_0c07afe0;
P_0c07afd4: /* original 0dc5, guest PC 0x0c07afd4 */
if(!s->budget--) { s->failed_pc=0x0c07afd4u; return 0; }
write(ram,r[13]+r[0],r[12],2);
goto P_0c07afd6;
P_0c07afd6: /* original 4a0b, guest PC 0x0c07afd6 */
if(!s->budget--) { s->failed_pc=0x0c07afd6u; return 0; }
target=r[10];
r[16]=code_base|0x0c07afdau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afdau) { target=s->pc; goto dispatch; }
goto P_0c07afda;
P_0c07afd8: /* original 64e3, guest PC 0x0c07afd8 */
if(!s->budget--) { s->failed_pc=0x0c07afd8u; return 0; }
r[4]=r[14];
goto P_0c07afda;
P_0c07afda: /* original d410, guest PC 0x0c07afda */
if(!s->budget--) { s->failed_pc=0x0c07afdau; return 0; }
r[4]=read(ram,0x0c07b01cu,4);
goto P_0c07afdc;
P_0c07afdc: /* original bc04, guest PC 0x0c07afdc */
if(!s->budget--) { s->failed_pc=0x0c07afdcu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07afe0u;
tmp=read(ram,r[11],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07afe0u) { target=s->pc; goto dispatch; }
goto P_0c07afe0;
P_0c07afde: /* original 65b2, guest PC 0x0c07afde */
if(!s->budget--) { s->failed_pc=0x0c07afdeu; return 0; }
tmp=read(ram,r[11],4);
r[5]=tmp;
goto P_0c07afe0;
P_0c07afe0: /* original 60e3, guest PC 0x0c07afe0 */
if(!s->budget--) { s->failed_pc=0x0c07afe0u; return 0; }
r[0]=r[14];
goto P_0c07afe2;
P_0c07afe2: /* original 4000, guest PC 0x0c07afe2 */
if(!s->budget--) { s->failed_pc=0x0c07afe2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c07afe4;
P_0c07afe4: /* original 0de5, guest PC 0x0c07afe4 */
if(!s->budget--) { s->failed_pc=0x0c07afe4u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c07afe6;
P_0c07afe6: /* original 63f2, guest PC 0x0c07afe6 */
if(!s->budget--) { s->failed_pc=0x0c07afe6u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07afe8;
P_0c07afe8: /* original 7f04, guest PC 0x0c07afe8 */
if(!s->budget--) { s->failed_pc=0x0c07afe8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07afea;
P_0c07afea: /* original 4f26, guest PC 0x0c07afea */
if(!s->budget--) { s->failed_pc=0x0c07afeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07afec;
P_0c07afec: /* original 9008, guest PC 0x0c07afec */
if(!s->budget--) { s->failed_pc=0x0c07afecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b000u,2);
goto P_0c07afee;
P_0c07afee: /* original e2ff, guest PC 0x0c07afee */
if(!s->budget--) { s->failed_pc=0x0c07afeeu; return 0; }
r[2]=0xffffffffu;
goto P_0c07aff0;
P_0c07aff0: /* original 0326, guest PC 0x0c07aff0 */
if(!s->budget--) { s->failed_pc=0x0c07aff0u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c07aff2;
P_0c07aff2: /* original e000, guest PC 0x0c07aff2 */
if(!s->budget--) { s->failed_pc=0x0c07aff2u; return 0; }
r[0]=0x00000000u;
goto P_0c07aff4;
P_0c07aff4: /* original 6af6, guest PC 0x0c07aff4 */
if(!s->budget--) { s->failed_pc=0x0c07aff4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07aff6;
P_0c07aff6: /* original 6bf6, guest PC 0x0c07aff6 */
if(!s->budget--) { s->failed_pc=0x0c07aff6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07aff8;
P_0c07aff8: /* original 6cf6, guest PC 0x0c07aff8 */
if(!s->budget--) { s->failed_pc=0x0c07aff8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07affa;
P_0c07affa: /* original 6df6, guest PC 0x0c07affa */
if(!s->budget--) { s->failed_pc=0x0c07affau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07affc;
P_0c07affc: /* original 000b, guest PC 0x0c07affc */
if(!s->budget--) { s->failed_pc=0x0c07affcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07affe: /* original 6ef6, guest PC 0x0c07affe */
if(!s->budget--) { s->failed_pc=0x0c07affeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b000u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b000u; return 0; } return 1;
P_0c07b0f4: /* original 2fe6, guest PC 0x0c07b0f4 */
if(!s->budget--) { s->failed_pc=0x0c07b0f4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0f6;
P_0c07b0f6: /* original 2fd6, guest PC 0x0c07b0f6 */
if(!s->budget--) { s->failed_pc=0x0c07b0f6u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0f8;
P_0c07b0f8: /* original 2fc6, guest PC 0x0c07b0f8 */
if(!s->budget--) { s->failed_pc=0x0c07b0f8u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fa;
P_0c07b0fa: /* original 2fb6, guest PC 0x0c07b0fa */
if(!s->budget--) { s->failed_pc=0x0c07b0fau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fc;
P_0c07b0fc: /* original 2fa6, guest PC 0x0c07b0fc */
if(!s->budget--) { s->failed_pc=0x0c07b0fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b0fe;
P_0c07b0fe: /* original 2f96, guest PC 0x0c07b0fe */
if(!s->budget--) { s->failed_pc=0x0c07b0feu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b100;
P_0c07b100: /* original de35, guest PC 0x0c07b100 */
if(!s->budget--) { s->failed_pc=0x0c07b100u; return 0; }
r[14]=read(ram,0x0c07b1d8u,4);
goto P_0c07b102;
P_0c07b102: /* original 4f22, guest PC 0x0c07b102 */
if(!s->budget--) { s->failed_pc=0x0c07b102u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b104;
P_0c07b104: /* original d933, guest PC 0x0c07b104 */
if(!s->budget--) { s->failed_pc=0x0c07b104u; return 0; }
r[9]=read(ram,0x0c07b1d4u,4);
goto P_0c07b106;
P_0c07b106: /* original d335, guest PC 0x0c07b106 */
if(!s->budget--) { s->failed_pc=0x0c07b106u; return 0; }
r[3]=read(ram,0x0c07b1dcu,4);
goto P_0c07b108;
P_0c07b108: /* original 7ffc, guest PC 0x0c07b108 */
if(!s->budget--) { s->failed_pc=0x0c07b108u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b10a;
P_0c07b10a: /* original 6b92, guest PC 0x0c07b10a */
if(!s->budget--) { s->failed_pc=0x0c07b10au; return 0; }
tmp=read(ram,r[9],4);
r[11]=tmp;
goto P_0c07b10c;
P_0c07b10c: /* original 2f32, guest PC 0x0c07b10c */
if(!s->budget--) { s->failed_pc=0x0c07b10cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07b10e;
P_0c07b10e: /* original 905f, guest PC 0x0c07b10e */
if(!s->budget--) { s->failed_pc=0x0c07b10eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b110;
P_0c07b110: /* original 02ed, guest PC 0x0c07b110 */
if(!s->budget--) { s->failed_pc=0x0c07b110u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b112;
P_0c07b112: /* original 4211, guest PC 0x0c07b112 */
if(!s->budget--) { s->failed_pc=0x0c07b112u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c07b114;
P_0c07b114: /* original 8f0f, guest PC 0x0c07b114 */
if(!s->budget--) { s->failed_pc=0x0c07b114u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c07b136; }
goto P_0c07b118;
P_0c07b116: /* original 6c43, guest PC 0x0c07b116 */
if(!s->budget--) { s->failed_pc=0x0c07b116u; return 0; }
r[12]=r[4];
goto P_0c07b118;
P_0c07b118: /* original b24a, guest PC 0x0c07b118 */
if(!s->budget--) { s->failed_pc=0x0c07b118u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b11cu;
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b11cu) { target=s->pc; goto dispatch; }
goto P_0c07b11c;
P_0c07b11a: /* original 04ed, guest PC 0x0c07b11a */
if(!s->budget--) { s->failed_pc=0x0c07b11au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c07b11c;
P_0c07b11c: /* original 6d03, guest PC 0x0c07b11c */
if(!s->budget--) { s->failed_pc=0x0c07b11cu; return 0; }
r[13]=r[0];
goto P_0c07b11e;
P_0c07b11e: /* original b267, guest PC 0x0c07b11e */
if(!s->budget--) { s->failed_pc=0x0c07b11eu; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07b122u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b122u) { target=s->pc; goto dispatch; }
goto P_0c07b122;
P_0c07b120: /* original 6403, guest PC 0x0c07b120 */
if(!s->budget--) { s->failed_pc=0x0c07b120u; return 0; }
r[4]=r[0];
goto P_0c07b122;
P_0c07b122: /* original 64dd, guest PC 0x0c07b122 */
if(!s->budget--) { s->failed_pc=0x0c07b122u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b124;
P_0c07b124: /* original 6043, guest PC 0x0c07b124 */
if(!s->budget--) { s->failed_pc=0x0c07b124u; return 0; }
r[0]=r[4];
goto P_0c07b126;
P_0c07b126: /* original 882c, guest PC 0x0c07b126 */
if(!s->budget--) { s->failed_pc=0x0c07b126u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b128;
P_0c07b128: /* original 8902, guest PC 0x0c07b128 */
if(!s->budget--) { s->failed_pc=0x0c07b128u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b130; }
goto P_0c07b12a;
P_0c07b12a: /* original 6043, guest PC 0x0c07b12a */
if(!s->budget--) { s->failed_pc=0x0c07b12au; return 0; }
r[0]=r[4];
goto P_0c07b12c;
P_0c07b12c: /* original 8834, guest PC 0x0c07b12c */
if(!s->budget--) { s->failed_pc=0x0c07b12cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b12e;
P_0c07b12e: /* original 8b02, guest PC 0x0c07b12e */
if(!s->budget--) { s->failed_pc=0x0c07b12eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b136; }
goto P_0c07b130;
P_0c07b130: /* original 64d3, guest PC 0x0c07b130 */
if(!s->budget--) { s->failed_pc=0x0c07b130u; return 0; }
r[4]=r[13];
goto P_0c07b132;
P_0c07b132: /* original b25d, guest PC 0x0c07b132 */
if(!s->budget--) { s->failed_pc=0x0c07b132u; return 0; }
target=code_base|0x0c07b5f0u; r[16]=code_base|0x0c07b136u;
r[4]+=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b136u) { target=s->pc; goto dispatch; }
goto P_0c07b136;
P_0c07b134: /* original 7401, guest PC 0x0c07b134 */
if(!s->budget--) { s->failed_pc=0x0c07b134u; return 0; }
r[4]+=0x00000001u;
goto P_0c07b136;
P_0c07b136: /* original 904b, guest PC 0x0c07b136 */
if(!s->budget--) { s->failed_pc=0x0c07b136u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b138;
P_0c07b138: /* original e2ff, guest PC 0x0c07b138 */
if(!s->budget--) { s->failed_pc=0x0c07b138u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b13a;
P_0c07b13a: /* original 0e25, guest PC 0x0c07b13a */
if(!s->budget--) { s->failed_pc=0x0c07b13au; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c07b13c;
P_0c07b13c: /* original d227, guest PC 0x0c07b13c */
if(!s->budget--) { s->failed_pc=0x0c07b13cu; return 0; }
r[2]=read(ram,0x0c07b1dcu,4);
goto P_0c07b13e;
P_0c07b13e: /* original d328, guest PC 0x0c07b13e */
if(!s->budget--) { s->failed_pc=0x0c07b13eu; return 0; }
r[3]=read(ram,0x0c07b1e0u,4);
goto P_0c07b140;
P_0c07b140: /* original 6122, guest PC 0x0c07b140 */
if(!s->budget--) { s->failed_pc=0x0c07b140u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07b142;
P_0c07b142: /* original 2138, guest PC 0x0c07b142 */
if(!s->budget--) { s->failed_pc=0x0c07b142u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07b144;
P_0c07b144: /* original 8b37, guest PC 0x0c07b144 */
if(!s->budget--) { s->failed_pc=0x0c07b144u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b1b6; }
goto P_0c07b146;
P_0c07b146: /* original d227, guest PC 0x0c07b146 */
if(!s->budget--) { s->failed_pc=0x0c07b146u; return 0; }
r[2]=read(ram,0x0c07b1e4u,4);
goto P_0c07b148;
P_0c07b148: /* original 63cd, guest PC 0x0c07b148 */
if(!s->budget--) { s->failed_pc=0x0c07b148u; return 0; }
r[3]=r[12]&65535u;
goto P_0c07b14a;
P_0c07b14a: /* original 9041, guest PC 0x0c07b14a */
if(!s->budget--) { s->failed_pc=0x0c07b14au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d0u,2);
goto P_0c07b14c;
P_0c07b14c: /* original 3320, guest PC 0x0c07b14c */
if(!s->budget--) { s->failed_pc=0x0c07b14cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c07b14e;
P_0c07b14e: /* original 8d32, guest PC 0x0c07b14e */
if(!s->budget--) { s->failed_pc=0x0c07b14eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[12],2);
if(cond) { goto P_0c07b1b6; }
goto P_0c07b152;
P_0c07b150: /* original 0ec5, guest PC 0x0c07b150 */
if(!s->budget--) { s->failed_pc=0x0c07b150u; return 0; }
write(ram,r[14]+r[0],r[12],2);
goto P_0c07b152;
P_0c07b152: /* original b22d, guest PC 0x0c07b152 */
if(!s->budget--) { s->failed_pc=0x0c07b152u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07b156u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b156u) { target=s->pc; goto dispatch; }
goto P_0c07b156;
P_0c07b154: /* original 64c3, guest PC 0x0c07b154 */
if(!s->budget--) { s->failed_pc=0x0c07b154u; return 0; }
r[4]=r[12];
goto P_0c07b156;
P_0c07b156: /* original 6d03, guest PC 0x0c07b156 */
if(!s->budget--) { s->failed_pc=0x0c07b156u; return 0; }
r[13]=r[0];
goto P_0c07b158;
P_0c07b158: /* original 6cdd, guest PC 0x0c07b158 */
if(!s->budget--) { s->failed_pc=0x0c07b158u; return 0; }
r[12]=r[13]&65535u;
goto P_0c07b15a;
P_0c07b15a: /* original d023, guest PC 0x0c07b15a */
if(!s->budget--) { s->failed_pc=0x0c07b15au; return 0; }
r[0]=read(ram,0x0c07b1e8u,4);
goto P_0c07b15c;
P_0c07b15c: /* original 62c3, guest PC 0x0c07b15c */
if(!s->budget--) { s->failed_pc=0x0c07b15cu; return 0; }
r[2]=r[12];
goto P_0c07b15e;
P_0c07b15e: /* original 72db, guest PC 0x0c07b15e */
if(!s->budget--) { s->failed_pc=0x0c07b15eu; return 0; }
r[2]+=0xffffffdbu;
goto P_0c07b160;
P_0c07b160: /* original 032c, guest PC 0x0c07b160 */
if(!s->budget--) { s->failed_pc=0x0c07b160u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07b162;
P_0c07b162: /* original 2338, guest PC 0x0c07b162 */
if(!s->budget--) { s->failed_pc=0x0c07b162u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c07b164;
P_0c07b164: /* original 892b, guest PC 0x0c07b164 */
if(!s->budget--) { s->failed_pc=0x0c07b164u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b1be; }
goto P_0c07b166;
P_0c07b166: /* original d321, guest PC 0x0c07b166 */
if(!s->budget--) { s->failed_pc=0x0c07b166u; return 0; }
r[3]=read(ram,0x0c07b1ecu,4);
goto P_0c07b168;
P_0c07b168: /* original 64c3, guest PC 0x0c07b168 */
if(!s->budget--) { s->failed_pc=0x0c07b168u; return 0; }
r[4]=r[12];
goto P_0c07b16a;
P_0c07b16a: /* original 65b3, guest PC 0x0c07b16a */
if(!s->budget--) { s->failed_pc=0x0c07b16au; return 0; }
r[5]=r[11];
goto P_0c07b16c;
P_0c07b16c: /* original 74db, guest PC 0x0c07b16c */
if(!s->budget--) { s->failed_pc=0x0c07b16cu; return 0; }
r[4]+=0xffffffdbu;
goto P_0c07b16e;
P_0c07b16e: /* original 430b, guest PC 0x0c07b16e */
if(!s->budget--) { s->failed_pc=0x0c07b16eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07b172u;
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b172u) { target=s->pc; goto dispatch; }
goto P_0c07b172;
P_0c07b170: /* original 044c, guest PC 0x0c07b170 */
if(!s->budget--) { s->failed_pc=0x0c07b170u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c07b172;
P_0c07b172: /* original 6edd, guest PC 0x0c07b172 */
if(!s->budget--) { s->failed_pc=0x0c07b172u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b174;
P_0c07b174: /* original da1e, guest PC 0x0c07b174 */
if(!s->budget--) { s->failed_pc=0x0c07b174u; return 0; }
r[10]=read(ram,0x0c07b1f0u,4);
goto P_0c07b176;
P_0c07b176: /* original 60e3, guest PC 0x0c07b176 */
if(!s->budget--) { s->failed_pc=0x0c07b176u; return 0; }
r[0]=r[14];
goto P_0c07b178;
P_0c07b178: /* original 882c, guest PC 0x0c07b178 */
if(!s->budget--) { s->failed_pc=0x0c07b178u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000002cu)!=0);
goto P_0c07b17a;
P_0c07b17a: /* original 8b04, guest PC 0x0c07b17a */
if(!s->budget--) { s->failed_pc=0x0c07b17au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b186; }
goto P_0c07b17c;
P_0c07b17c: /* original 4a0b, guest PC 0x0c07b17c */
if(!s->budget--) { s->failed_pc=0x0c07b17cu; return 0; }
target=r[10];
r[16]=code_base|0x0c07b180u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b180u) { target=s->pc; goto dispatch; }
goto P_0c07b180;
P_0c07b17e: /* original 64e3, guest PC 0x0c07b17e */
if(!s->budget--) { s->failed_pc=0x0c07b17eu; return 0; }
r[4]=r[14];
goto P_0c07b180;
P_0c07b180: /* original d41c, guest PC 0x0c07b180 */
if(!s->budget--) { s->failed_pc=0x0c07b180u; return 0; }
r[4]=read(ram,0x0c07b1f4u,4);
goto P_0c07b182;
P_0c07b182: /* original a006, guest PC 0x0c07b182 */
if(!s->budget--) { s->failed_pc=0x0c07b182u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b192;
P_0c07b184: /* original 6592, guest PC 0x0c07b184 */
if(!s->budget--) { s->failed_pc=0x0c07b184u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b186;
P_0c07b186: /* original 8834, guest PC 0x0c07b186 */
if(!s->budget--) { s->failed_pc=0x0c07b186u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000034u)!=0);
goto P_0c07b188;
P_0c07b188: /* original 8b0c, guest PC 0x0c07b188 */
if(!s->budget--) { s->failed_pc=0x0c07b188u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b1a4; }
goto P_0c07b18a;
P_0c07b18a: /* original 4a0b, guest PC 0x0c07b18a */
if(!s->budget--) { s->failed_pc=0x0c07b18au; return 0; }
target=r[10];
r[16]=code_base|0x0c07b18eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b18eu) { target=s->pc; goto dispatch; }
goto P_0c07b18e;
P_0c07b18c: /* original 64e3, guest PC 0x0c07b18c */
if(!s->budget--) { s->failed_pc=0x0c07b18cu; return 0; }
r[4]=r[14];
goto P_0c07b18e;
P_0c07b18e: /* original d41a, guest PC 0x0c07b18e */
if(!s->budget--) { s->failed_pc=0x0c07b18eu; return 0; }
r[4]=read(ram,0x0c07b1f8u,4);
goto P_0c07b190;
P_0c07b190: /* original 6592, guest PC 0x0c07b190 */
if(!s->budget--) { s->failed_pc=0x0c07b190u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c07b192;
P_0c07b192: /* original bb38, guest PC 0x0c07b192 */
if(!s->budget--) { s->failed_pc=0x0c07b192u; return 0; }
target=code_base|0x0c07a806u; r[16]=code_base|0x0c07b196u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b196u) { target=s->pc; goto dispatch; }
goto P_0c07b196;
P_0c07b194: /* original 0009, guest PC 0x0c07b194 */
if(!s->budget--) { s->failed_pc=0x0c07b194u; return 0; }
goto P_0c07b196;
P_0c07b196: /* original d019, guest PC 0x0c07b196 */
if(!s->budget--) { s->failed_pc=0x0c07b196u; return 0; }
r[0]=read(ram,0x0c07b1fcu,4);
goto P_0c07b198;
P_0c07b198: /* original 62e3, guest PC 0x0c07b198 */
if(!s->budget--) { s->failed_pc=0x0c07b198u; return 0; }
r[2]=r[14];
goto P_0c07b19a;
P_0c07b19a: /* original 7c01, guest PC 0x0c07b19a */
if(!s->budget--) { s->failed_pc=0x0c07b19au; return 0; }
r[12]+=0x00000001u;
goto P_0c07b19c;
P_0c07b19c: /* original 7201, guest PC 0x0c07b19c */
if(!s->budget--) { s->failed_pc=0x0c07b19cu; return 0; }
r[2]+=0x00000001u;
goto P_0c07b19e;
P_0c07b19e: /* original 4c00, guest PC 0x0c07b19e */
if(!s->budget--) { s->failed_pc=0x0c07b19eu; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c07b1a0;
P_0c07b1a0: /* original a005, guest PC 0x0c07b1a0 */
if(!s->budget--) { s->failed_pc=0x0c07b1a0u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c07b1ae;
P_0c07b1a2: /* original 0c25, guest PC 0x0c07b1a2 */
if(!s->budget--) { s->failed_pc=0x0c07b1a2u; return 0; }
write(ram,r[12]+r[0],r[2],2);
goto P_0c07b1a4;
P_0c07b1a4: /* original 4a0b, guest PC 0x0c07b1a4 */
if(!s->budget--) { s->failed_pc=0x0c07b1a4u; return 0; }
target=r[10];
r[16]=code_base|0x0c07b1a8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b1a8u) { target=s->pc; goto dispatch; }
goto P_0c07b1a8;
P_0c07b1a6: /* original 64e3, guest PC 0x0c07b1a6 */
if(!s->budget--) { s->failed_pc=0x0c07b1a6u; return 0; }
r[4]=r[14];
goto P_0c07b1a8;
P_0c07b1a8: /* original d415, guest PC 0x0c07b1a8 */
if(!s->budget--) { s->failed_pc=0x0c07b1a8u; return 0; }
r[4]=read(ram,0x0c07b200u,4);
goto P_0c07b1aa;
P_0c07b1aa: /* original bb1d, guest PC 0x0c07b1aa */
if(!s->budget--) { s->failed_pc=0x0c07b1aau; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b1aeu;
r[5]=r[11];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b1aeu) { target=s->pc; goto dispatch; }
goto P_0c07b1ae;
P_0c07b1ac: /* original 65b3, guest PC 0x0c07b1ac */
if(!s->budget--) { s->failed_pc=0x0c07b1acu; return 0; }
r[5]=r[11];
goto P_0c07b1ae;
P_0c07b1ae: /* original d013, guest PC 0x0c07b1ae */
if(!s->budget--) { s->failed_pc=0x0c07b1aeu; return 0; }
r[0]=read(ram,0x0c07b1fcu,4);
goto P_0c07b1b0;
P_0c07b1b0: /* original 6ddd, guest PC 0x0c07b1b0 */
if(!s->budget--) { s->failed_pc=0x0c07b1b0u; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b1b2;
P_0c07b1b2: /* original 4d00, guest PC 0x0c07b1b2 */
if(!s->budget--) { s->failed_pc=0x0c07b1b2u; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b1b4;
P_0c07b1b4: /* original 0de5, guest PC 0x0c07b1b4 */
if(!s->budget--) { s->failed_pc=0x0c07b1b4u; return 0; }
write(ram,r[13]+r[0],r[14],2);
goto P_0c07b1b6;
P_0c07b1b6: /* original 900c, guest PC 0x0c07b1b6 */
if(!s->budget--) { s->failed_pc=0x0c07b1b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b1d2u,2);
goto P_0c07b1b8;
P_0c07b1b8: /* original e2ff, guest PC 0x0c07b1b8 */
if(!s->budget--) { s->failed_pc=0x0c07b1b8u; return 0; }
r[2]=0xffffffffu;
goto P_0c07b1ba;
P_0c07b1ba: /* original 63f2, guest PC 0x0c07b1ba */
if(!s->budget--) { s->failed_pc=0x0c07b1bau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07b1bc;
P_0c07b1bc: /* original 0326, guest PC 0x0c07b1bc */
if(!s->budget--) { s->failed_pc=0x0c07b1bcu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c07b1be;
P_0c07b1be: /* original 7f04, guest PC 0x0c07b1be */
if(!s->budget--) { s->failed_pc=0x0c07b1beu; return 0; }
r[15]+=0x00000004u;
goto P_0c07b1c0;
P_0c07b1c0: /* original 4f26, guest PC 0x0c07b1c0 */
if(!s->budget--) { s->failed_pc=0x0c07b1c0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b1c2;
P_0c07b1c2: /* original 69f6, guest PC 0x0c07b1c2 */
if(!s->budget--) { s->failed_pc=0x0c07b1c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07b1c4;
P_0c07b1c4: /* original 6af6, guest PC 0x0c07b1c4 */
if(!s->budget--) { s->failed_pc=0x0c07b1c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b1c6;
P_0c07b1c6: /* original 6bf6, guest PC 0x0c07b1c6 */
if(!s->budget--) { s->failed_pc=0x0c07b1c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b1c8;
P_0c07b1c8: /* original 6cf6, guest PC 0x0c07b1c8 */
if(!s->budget--) { s->failed_pc=0x0c07b1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b1ca;
P_0c07b1ca: /* original 6df6, guest PC 0x0c07b1ca */
if(!s->budget--) { s->failed_pc=0x0c07b1cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b1cc;
P_0c07b1cc: /* original 000b, guest PC 0x0c07b1cc */
if(!s->budget--) { s->failed_pc=0x0c07b1ccu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b1ce: /* original 6ef6, guest PC 0x0c07b1ce */
if(!s->budget--) { s->failed_pc=0x0c07b1ceu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b1d0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b1d0u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
