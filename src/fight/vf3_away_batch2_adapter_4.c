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
int vf3_away_batch2_adapter_4(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03a9c0u: goto P_0c03a9c0;
case 0x0c03a9c2u: goto P_0c03a9c2;
case 0x0c03a9c4u: goto P_0c03a9c4;
case 0x0c03a9c6u: goto P_0c03a9c6;
case 0x0c03a9c8u: goto P_0c03a9c8;
case 0x0c03a9cau: goto P_0c03a9ca;
case 0x0c03a9ccu: goto P_0c03a9cc;
case 0x0c03a9d0u: goto P_0c03a9d0;
case 0x0c03a9d2u: goto P_0c03a9d2;
case 0x0c03a9d4u: goto P_0c03a9d4;
case 0x0c03a9d6u: goto P_0c03a9d6;
case 0x0c03ac40u: goto P_0c03ac40;
case 0x0c03ac42u: goto P_0c03ac42;
case 0x0c03ac44u: goto P_0c03ac44;
case 0x0c03ac46u: goto P_0c03ac46;
case 0x0c03ac48u: goto P_0c03ac48;
case 0x0c03ac4au: goto P_0c03ac4a;
case 0x0c03ac4cu: goto P_0c03ac4c;
case 0x0c03ac4eu: goto P_0c03ac4e;
case 0x0c03ac50u: goto P_0c03ac50;
case 0x0c03ac52u: goto P_0c03ac52;
case 0x0c03ac54u: goto P_0c03ac54;
case 0x0c03ac56u: goto P_0c03ac56;
case 0x0c03ac58u: goto P_0c03ac58;
case 0x0c03ac5au: goto P_0c03ac5a;
case 0x0c03ac5cu: goto P_0c03ac5c;
case 0x0c03ac5eu: goto P_0c03ac5e;
case 0x0c03ac60u: goto P_0c03ac60;
case 0x0c03ac62u: goto P_0c03ac62;
case 0x0c03ac64u: goto P_0c03ac64;
case 0x0c03ac66u: goto P_0c03ac66;
case 0x0c03ac68u: goto P_0c03ac68;
case 0x0c03ac6au: goto P_0c03ac6a;
case 0x0c03ac6cu: goto P_0c03ac6c;
case 0x0c03ac6eu: goto P_0c03ac6e;
case 0x0c03ac70u: goto P_0c03ac70;
case 0x0c03ac72u: goto P_0c03ac72;
case 0x0c03ac74u: goto P_0c03ac74;
case 0x0c03ac76u: goto P_0c03ac76;
case 0x0c03ac78u: goto P_0c03ac78;
case 0x0c03ac7au: goto P_0c03ac7a;
case 0x0c03ac7cu: goto P_0c03ac7c;
case 0x0c03ac7eu: goto P_0c03ac7e;
case 0x0c03ac80u: goto P_0c03ac80;
case 0x0c03ac82u: goto P_0c03ac82;
case 0x0c03ac84u: goto P_0c03ac84;
case 0x0c03ac86u: goto P_0c03ac86;
case 0x0c03ac88u: goto P_0c03ac88;
case 0x0c03ac8au: goto P_0c03ac8a;
case 0x0c03ac8cu: goto P_0c03ac8c;
case 0x0c03ac8eu: goto P_0c03ac8e;
case 0x0c03ac90u: goto P_0c03ac90;
case 0x0c03ac92u: goto P_0c03ac92;
case 0x0c03ac94u: goto P_0c03ac94;
case 0x0c03ac96u: goto P_0c03ac96;
case 0x0c03ac98u: goto P_0c03ac98;
case 0x0c03ac9au: goto P_0c03ac9a;
case 0x0c03ac9cu: goto P_0c03ac9c;
case 0x0c03ac9eu: goto P_0c03ac9e;
case 0x0c03aca0u: goto P_0c03aca0;
case 0x0c03aca2u: goto P_0c03aca2;
case 0x0c03aca4u: goto P_0c03aca4;
case 0x0c03aca6u: goto P_0c03aca6;
case 0x0c03aca8u: goto P_0c03aca8;
case 0x0c03acaau: goto P_0c03acaa;
case 0x0c03acacu: goto P_0c03acac;
case 0x0c03acaeu: goto P_0c03acae;
case 0x0c03acb0u: goto P_0c03acb0;
case 0x0c03acb2u: goto P_0c03acb2;
case 0x0c03acb4u: goto P_0c03acb4;
case 0x0c03acb6u: goto P_0c03acb6;
case 0x0c03acb8u: goto P_0c03acb8;
case 0x0c03acbau: goto P_0c03acba;
case 0x0c03acbcu: goto P_0c03acbc;
case 0x0c03acbeu: goto P_0c03acbe;
case 0x0c03acc0u: goto P_0c03acc0;
case 0x0c03acc2u: goto P_0c03acc2;
case 0x0c03acc4u: goto P_0c03acc4;
case 0x0c03acc6u: goto P_0c03acc6;
case 0x0c03acc8u: goto P_0c03acc8;
case 0x0c03accau: goto P_0c03acca;
case 0x0c03acccu: goto P_0c03accc;
case 0x0c03acceu: goto P_0c03acce;
case 0x0c03acd0u: goto P_0c03acd0;
case 0x0c03acd2u: goto P_0c03acd2;
case 0x0c03b110u: goto P_0c03b110;
case 0x0c03b112u: goto P_0c03b112;
case 0x0c03b114u: goto P_0c03b114;
case 0x0c03b116u: goto P_0c03b116;
case 0x0c03b118u: goto P_0c03b118;
case 0x0c03b11au: goto P_0c03b11a;
case 0x0c03b11cu: goto P_0c03b11c;
case 0x0c03b11eu: goto P_0c03b11e;
case 0x0c03b120u: goto P_0c03b120;
case 0x0c03b122u: goto P_0c03b122;
case 0x0c03b124u: goto P_0c03b124;
case 0x0c03b126u: goto P_0c03b126;
case 0x0c03b128u: goto P_0c03b128;
case 0x0c03b12au: goto P_0c03b12a;
case 0x0c03b130u: goto P_0c03b130;
case 0x0c03b132u: goto P_0c03b132;
case 0x0c03b134u: goto P_0c03b134;
case 0x0c03b136u: goto P_0c03b136;
case 0x0c03b138u: goto P_0c03b138;
case 0x0c03b13au: goto P_0c03b13a;
case 0x0c03b13cu: goto P_0c03b13c;
case 0x0c03b13eu: goto P_0c03b13e;
case 0x0c03b140u: goto P_0c03b140;
case 0x0c03b142u: goto P_0c03b142;
case 0x0c03b144u: goto P_0c03b144;
case 0x0c03b146u: goto P_0c03b146;
case 0x0c03b148u: goto P_0c03b148;
case 0x0c03b14au: goto P_0c03b14a;
case 0x0c03b14cu: goto P_0c03b14c;
case 0x0c03b14eu: goto P_0c03b14e;
case 0x0c03b150u: goto P_0c03b150;
case 0x0c03b152u: goto P_0c03b152;
case 0x0c03b154u: goto P_0c03b154;
case 0x0c03b156u: goto P_0c03b156;
case 0x0c03b158u: goto P_0c03b158;
case 0x0c03b15au: goto P_0c03b15a;
case 0x0c03b15cu: goto P_0c03b15c;
case 0x0c03b15eu: goto P_0c03b15e;
case 0x0c03b160u: goto P_0c03b160;
case 0x0c03b162u: goto P_0c03b162;
case 0x0c03b164u: goto P_0c03b164;
case 0x0c03b166u: goto P_0c03b166;
case 0x0c03b168u: goto P_0c03b168;
case 0x0c03b16au: goto P_0c03b16a;
case 0x0c03b16cu: goto P_0c03b16c;
case 0x0c03b16eu: goto P_0c03b16e;
case 0x0c03b170u: goto P_0c03b170;
case 0x0c03b172u: goto P_0c03b172;
case 0x0c03b174u: goto P_0c03b174;
case 0x0c03b176u: goto P_0c03b176;
case 0x0c03b178u: goto P_0c03b178;
case 0x0c03b17au: goto P_0c03b17a;
case 0x0c03b180u: goto P_0c03b180;
case 0x0c03b182u: goto P_0c03b182;
case 0x0c03b184u: goto P_0c03b184;
case 0x0c03b186u: goto P_0c03b186;
case 0x0c03b188u: goto P_0c03b188;
case 0x0c03b18au: goto P_0c03b18a;
case 0x0c03b18cu: goto P_0c03b18c;
case 0x0c03b18eu: goto P_0c03b18e;
case 0x0c03b190u: goto P_0c03b190;
case 0x0c03b192u: goto P_0c03b192;
case 0x0c03b194u: goto P_0c03b194;
case 0x0c03b196u: goto P_0c03b196;
case 0x0c03b198u: goto P_0c03b198;
case 0x0c03b19au: goto P_0c03b19a;
case 0x0c03b19cu: goto P_0c03b19c;
case 0x0c03b19eu: goto P_0c03b19e;
case 0x0c03b1a0u: goto P_0c03b1a0;
case 0x0c03b1b0u: goto P_0c03b1b0;
case 0x0c03b1b2u: goto P_0c03b1b2;
case 0x0c03b1b4u: goto P_0c03b1b4;
case 0x0c03b1b6u: goto P_0c03b1b6;
case 0x0c03b1b8u: goto P_0c03b1b8;
case 0x0c03b1bau: goto P_0c03b1ba;
case 0x0c03b1bcu: goto P_0c03b1bc;
case 0x0c03b1c0u: goto P_0c03b1c0;
case 0x0c03b1c2u: goto P_0c03b1c2;
case 0x0c03b1c4u: goto P_0c03b1c4;
case 0x0c03b1c6u: goto P_0c03b1c6;
case 0x0c03b1c8u: goto P_0c03b1c8;
case 0x0c03b1cau: goto P_0c03b1ca;
case 0x0c03b1ccu: goto P_0c03b1cc;
case 0x0c03b1ceu: goto P_0c03b1ce;
case 0x0c03b1d0u: goto P_0c03b1d0;
case 0x0c03b1d2u: goto P_0c03b1d2;
case 0x0c03b1d4u: goto P_0c03b1d4;
case 0x0c03b1d6u: goto P_0c03b1d6;
case 0x0c03b1d8u: goto P_0c03b1d8;
case 0x0c03b1dau: goto P_0c03b1da;
case 0x0c03b1dcu: goto P_0c03b1dc;
case 0x0c03b1deu: goto P_0c03b1de;
case 0x0c03b1e0u: goto P_0c03b1e0;
case 0x0c03b1e2u: goto P_0c03b1e2;
case 0x0c03b1e4u: goto P_0c03b1e4;
case 0x0c03b1e6u: goto P_0c03b1e6;
case 0x0c03b1e8u: goto P_0c03b1e8;
case 0x0c03b1eau: goto P_0c03b1ea;
case 0x0c03b1ecu: goto P_0c03b1ec;
case 0x0c03b1eeu: goto P_0c03b1ee;
case 0x0c03b1f0u: goto P_0c03b1f0;
case 0x0c03b1f2u: goto P_0c03b1f2;
case 0x0c03b1f4u: goto P_0c03b1f4;
case 0x0c03b1f6u: goto P_0c03b1f6;
case 0x0c03b1f8u: goto P_0c03b1f8;
case 0x0c03b1fau: goto P_0c03b1fa;
case 0x0c03b1fcu: goto P_0c03b1fc;
case 0x0c03b1feu: goto P_0c03b1fe;
case 0x0c03b200u: goto P_0c03b200;
case 0x0c03b202u: goto P_0c03b202;
case 0x0c03b204u: goto P_0c03b204;
case 0x0c03b206u: goto P_0c03b206;
case 0x0c03b5c0u: goto P_0c03b5c0;
case 0x0c03b5c2u: goto P_0c03b5c2;
case 0x0c03b5c4u: goto P_0c03b5c4;
case 0x0c03b5c6u: goto P_0c03b5c6;
case 0x0c03b5c8u: goto P_0c03b5c8;
case 0x0c03b5cau: goto P_0c03b5ca;
case 0x0c03b5ccu: goto P_0c03b5cc;
case 0x0c03b5ceu: goto P_0c03b5ce;
case 0x0c03b5d0u: goto P_0c03b5d0;
case 0x0c03b5d2u: goto P_0c03b5d2;
case 0x0c03b5d4u: goto P_0c03b5d4;
case 0x0c03b5d6u: goto P_0c03b5d6;
case 0x0c03b5d8u: goto P_0c03b5d8;
case 0x0c03b5dau: goto P_0c03b5da;
case 0x0c03b5dcu: goto P_0c03b5dc;
case 0x0c03b5deu: goto P_0c03b5de;
case 0x0c03b5e0u: goto P_0c03b5e0;
case 0x0c03b5e2u: goto P_0c03b5e2;
case 0x0c03b5e4u: goto P_0c03b5e4;
case 0x0c03b5e6u: goto P_0c03b5e6;
case 0x0c03b5e8u: goto P_0c03b5e8;
case 0x0c03b5eau: goto P_0c03b5ea;
case 0x0c03b5ecu: goto P_0c03b5ec;
case 0x0c03b5eeu: goto P_0c03b5ee;
case 0x0c03b5f0u: goto P_0c03b5f0;
case 0x0c03b5f2u: goto P_0c03b5f2;
case 0x0c03b5f4u: goto P_0c03b5f4;
case 0x0c03b5f6u: goto P_0c03b5f6;
case 0x0c03b5f8u: goto P_0c03b5f8;
case 0x0c03b5fau: goto P_0c03b5fa;
case 0x0c03b5fcu: goto P_0c03b5fc;
case 0x0c03b5feu: goto P_0c03b5fe;
case 0x0c03b600u: goto P_0c03b600;
case 0x0c03b602u: goto P_0c03b602;
case 0x0c03b604u: goto P_0c03b604;
case 0x0c03b606u: goto P_0c03b606;
case 0x0c03b608u: goto P_0c03b608;
case 0x0c03b60au: goto P_0c03b60a;
case 0x0c03b60cu: goto P_0c03b60c;
case 0x0c03b60eu: goto P_0c03b60e;
case 0x0c03b610u: goto P_0c03b610;
case 0x0c03b612u: goto P_0c03b612;
case 0x0c03b614u: goto P_0c03b614;
case 0x0c03b616u: goto P_0c03b616;
case 0x0c03b618u: goto P_0c03b618;
case 0x0c03b61au: goto P_0c03b61a;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03a9c0: /* original f38d, guest PC 0x0c03a9c0 */
if(!s->budget--) { s->failed_pc=0x0c03a9c0u; return 0; }
fr[3]=0;
goto P_0c03a9c2;
P_0c03a9c2: /* original f434, guest PC 0x0c03a9c2 */
if(!s->budget--) { s->failed_pc=0x0c03a9c2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])==as_float(fr[3]))!=0);
goto P_0c03a9c4;
P_0c03a9c4: /* original 8904, guest PC 0x0c03a9c4 */
if(!s->budget--) { s->failed_pc=0x0c03a9c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03a9d0; }
goto P_0c03a9c6;
P_0c03a9c6: /* original c724, guest PC 0x0c03a9c6 */
if(!s->budget--) { s->failed_pc=0x0c03a9c6u; return 0; }
r[0]=code_base|0x0003aa58u;
goto P_0c03a9c8;
P_0c03a9c8: /* original f008, guest PC 0x0c03a9c8 */
if(!s->budget--) { s->failed_pc=0x0c03a9c8u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a9ca;
P_0c03a9ca: /* original 000b, guest PC 0x0c03a9ca */
if(!s->budget--) { s->failed_pc=0x0c03a9cau; return 0; }
target=r[16];
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'/');
s->pc=target; return ram->oob==0;
P_0c03a9cc: /* original f043, guest PC 0x0c03a9cc */
if(!s->budget--) { s->failed_pc=0x0c03a9ccu; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[4],r[18],'/');
if(!vf3_matrix_family(0x0c03a9ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a9ceu; return 0; } return 1;
P_0c03a9d0: /* original c722, guest PC 0x0c03a9d0 */
if(!s->budget--) { s->failed_pc=0x0c03a9d0u; return 0; }
r[0]=code_base|0x0003aa5cu;
goto P_0c03a9d2;
P_0c03a9d2: /* original f008, guest PC 0x0c03a9d2 */
if(!s->budget--) { s->failed_pc=0x0c03a9d2u; return 0; }
vf3_matrix_load(s,ram,0,r[0]);
goto P_0c03a9d4;
P_0c03a9d4: /* original 000b, guest PC 0x0c03a9d4 */
if(!s->budget--) { s->failed_pc=0x0c03a9d4u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03a9d6: /* original 0009, guest PC 0x0c03a9d6 */
if(!s->budget--) { s->failed_pc=0x0c03a9d6u; return 0; }
if(!vf3_matrix_family(0x0c03a9d8u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03a9d8u; return 0; } return 1;
P_0c03ac40: /* original d290, guest PC 0x0c03ac40 */
if(!s->budget--) { s->failed_pc=0x0c03ac40u; return 0; }
r[2]=read(ram,0x0c03ae84u,4);
goto P_0c03ac42;
P_0c03ac42: /* original 445a, guest PC 0x0c03ac42 */
if(!s->budget--) { s->failed_pc=0x0c03ac42u; return 0; }
r[53]=r[4];
goto P_0c03ac44;
P_0c03ac44: /* original 6322, guest PC 0x0c03ac44 */
if(!s->budget--) { s->failed_pc=0x0c03ac44u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03ac46;
P_0c03ac46: /* original e2ff, guest PC 0x0c03ac46 */
if(!s->budget--) { s->failed_pc=0x0c03ac46u; return 0; }
r[2]=0xffffffffu;
goto P_0c03ac48;
P_0c03ac48: /* original d18f, guest PC 0x0c03ac48 */
if(!s->budget--) { s->failed_pc=0x0c03ac48u; return 0; }
r[1]=read(ram,0x0c03ae88u,4);
goto P_0c03ac4a;
P_0c03ac4a: /* original f32d, guest PC 0x0c03ac4a */
if(!s->budget--) { s->failed_pc=0x0c03ac4au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03ac4c;
P_0c03ac4c: /* original 435a, guest PC 0x0c03ac4c */
if(!s->budget--) { s->failed_pc=0x0c03ac4cu; return 0; }
r[53]=r[3];
goto P_0c03ac4e;
P_0c03ac4e: /* original 6312, guest PC 0x0c03ac4e */
if(!s->budget--) { s->failed_pc=0x0c03ac4eu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c03ac50;
P_0c03ac50: /* original f22d, guest PC 0x0c03ac50 */
if(!s->budget--) { s->failed_pc=0x0c03ac50u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03ac52;
P_0c03ac52: /* original 455a, guest PC 0x0c03ac52 */
if(!s->budget--) { s->failed_pc=0x0c03ac52u; return 0; }
r[53]=r[5];
goto P_0c03ac54;
P_0c03ac54: /* original 656e, guest PC 0x0c03ac54 */
if(!s->budget--) { s->failed_pc=0x0c03ac54u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c03ac56;
P_0c03ac56: /* original f63c, guest PC 0x0c03ac56 */
if(!s->budget--) { s->failed_pc=0x0c03ac56u; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c03ac58;
P_0c03ac58: /* original 4500, guest PC 0x0c03ac58 */
if(!s->budget--) { s->failed_pc=0x0c03ac58u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c03ac5a;
P_0c03ac5a: /* original f73c, guest PC 0x0c03ac5a */
if(!s->budget--) { s->failed_pc=0x0c03ac5au; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c03ac5c;
P_0c03ac5c: /* original f32d, guest PC 0x0c03ac5c */
if(!s->budget--) { s->failed_pc=0x0c03ac5cu; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c03ac5e;
P_0c03ac5e: /* original 435a, guest PC 0x0c03ac5e */
if(!s->budget--) { s->failed_pc=0x0c03ac5eu; return 0; }
r[53]=r[3];
goto P_0c03ac60;
P_0c03ac60: /* original d38a, guest PC 0x0c03ac60 */
if(!s->budget--) { s->failed_pc=0x0c03ac60u; return 0; }
r[3]=read(ram,0x0c03ae8cu,4);
goto P_0c03ac62;
P_0c03ac62: /* original f620, guest PC 0x0c03ac62 */
if(!s->budget--) { s->failed_pc=0x0c03ac62u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'+');
goto P_0c03ac64;
P_0c03ac64: /* original 353c, guest PC 0x0c03ac64 */
if(!s->budget--) { s->failed_pc=0x0c03ac64u; return 0; }
r[5]+=r[3];
goto P_0c03ac66;
P_0c03ac66: /* original f22d, guest PC 0x0c03ac66 */
if(!s->budget--) { s->failed_pc=0x0c03ac66u; return 0; }
fr[2]=vf3_fpu_float(r[53],r[18]);
goto P_0c03ac68;
P_0c03ac68: /* original 8551, guest PC 0x0c03ac68 */
if(!s->budget--) { s->failed_pc=0x0c03ac68u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+2,2);
goto P_0c03ac6a;
P_0c03ac6a: /* original 6451, guest PC 0x0c03ac6a */
if(!s->budget--) { s->failed_pc=0x0c03ac6au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[4]=tmp;
goto P_0c03ac6c;
P_0c03ac6c: /* original 6503, guest PC 0x0c03ac6c */
if(!s->budget--) { s->failed_pc=0x0c03ac6cu; return 0; }
r[5]=r[0];
goto P_0c03ac6e;
P_0c03ac6e: /* original f53c, guest PC 0x0c03ac6e */
if(!s->budget--) { s->failed_pc=0x0c03ac6eu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c03ac70;
P_0c03ac70: /* original e004, guest PC 0x0c03ac70 */
if(!s->budget--) { s->failed_pc=0x0c03ac70u; return 0; }
r[0]=0x00000004u;
goto P_0c03ac72;
P_0c03ac72: /* original f43c, guest PC 0x0c03ac72 */
if(!s->budget--) { s->failed_pc=0x0c03ac72u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c03ac74;
P_0c03ac74: /* original f520, guest PC 0x0c03ac74 */
if(!s->budget--) { s->failed_pc=0x0c03ac74u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'+');
goto P_0c03ac76;
P_0c03ac76: /* original 2722, guest PC 0x0c03ac76 */
if(!s->budget--) { s->failed_pc=0x0c03ac76u; return 0; }
write(ram,r[7],r[2],4);
goto P_0c03ac78;
P_0c03ac78: /* original f777, guest PC 0x0c03ac78 */
if(!s->budget--) { s->failed_pc=0x0c03ac78u; return 0; }
vf3_matrix_store(s,ram,7,r[7]+r[0]);
goto P_0c03ac7a;
P_0c03ac7a: /* original e008, guest PC 0x0c03ac7a */
if(!s->budget--) { s->failed_pc=0x0c03ac7au; return 0; }
r[0]=0x00000008u;
goto P_0c03ac7c;
P_0c03ac7c: /* original f747, guest PC 0x0c03ac7c */
if(!s->budget--) { s->failed_pc=0x0c03ac7cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]+r[0]);
goto P_0c03ac7e;
P_0c03ac7e: /* original c784, guest PC 0x0c03ac7e */
if(!s->budget--) { s->failed_pc=0x0c03ac7eu; return 0; }
r[0]=code_base|0x0003ae90u;
goto P_0c03ac80;
P_0c03ac80: /* original f808, guest PC 0x0c03ac80 */
if(!s->budget--) { s->failed_pc=0x0c03ac80u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c03ac82;
P_0c03ac82: /* original e00c, guest PC 0x0c03ac82 */
if(!s->budget--) { s->failed_pc=0x0c03ac82u; return 0; }
r[0]=0x0000000cu;
goto P_0c03ac84;
P_0c03ac84: /* original f787, guest PC 0x0c03ac84 */
if(!s->budget--) { s->failed_pc=0x0c03ac84u; return 0; }
vf3_matrix_store(s,ram,8,r[7]+r[0]);
goto P_0c03ac86;
P_0c03ac86: /* original e010, guest PC 0x0c03ac86 */
if(!s->budget--) { s->failed_pc=0x0c03ac86u; return 0; }
r[0]=0x00000010u;
goto P_0c03ac88;
P_0c03ac88: /* original f767, guest PC 0x0c03ac88 */
if(!s->budget--) { s->failed_pc=0x0c03ac88u; return 0; }
vf3_matrix_store(s,ram,6,r[7]+r[0]);
goto P_0c03ac8a;
P_0c03ac8a: /* original e014, guest PC 0x0c03ac8a */
if(!s->budget--) { s->failed_pc=0x0c03ac8au; return 0; }
r[0]=0x00000014u;
goto P_0c03ac8c;
P_0c03ac8c: /* original f747, guest PC 0x0c03ac8c */
if(!s->budget--) { s->failed_pc=0x0c03ac8cu; return 0; }
vf3_matrix_store(s,ram,4,r[7]+r[0]);
goto P_0c03ac8e;
P_0c03ac8e: /* original e018, guest PC 0x0c03ac8e */
if(!s->budget--) { s->failed_pc=0x0c03ac8eu; return 0; }
r[0]=0x00000018u;
goto P_0c03ac90;
P_0c03ac90: /* original f787, guest PC 0x0c03ac90 */
if(!s->budget--) { s->failed_pc=0x0c03ac90u; return 0; }
vf3_matrix_store(s,ram,8,r[7]+r[0]);
goto P_0c03ac92;
P_0c03ac92: /* original e01c, guest PC 0x0c03ac92 */
if(!s->budget--) { s->failed_pc=0x0c03ac92u; return 0; }
r[0]=0x0000001cu;
goto P_0c03ac94;
P_0c03ac94: /* original f767, guest PC 0x0c03ac94 */
if(!s->budget--) { s->failed_pc=0x0c03ac94u; return 0; }
vf3_matrix_store(s,ram,6,r[7]+r[0]);
goto P_0c03ac96;
P_0c03ac96: /* original 0783, guest PC 0x0c03ac96 */
if(!s->budget--) { s->failed_pc=0x0c03ac96u; return 0; }
if((r[7]&0xFC000000u)==0xE0000000u) pref(ram,r[7]);
goto P_0c03ac98;
P_0c03ac98: /* original e004, guest PC 0x0c03ac98 */
if(!s->budget--) { s->failed_pc=0x0c03ac98u; return 0; }
r[0]=0x00000004u;
goto P_0c03ac9a;
P_0c03ac9a: /* original 7720, guest PC 0x0c03ac9a */
if(!s->budget--) { s->failed_pc=0x0c03ac9au; return 0; }
r[7]+=0x00000020u;
goto P_0c03ac9c;
P_0c03ac9c: /* original 616e, guest PC 0x0c03ac9c */
if(!s->budget--) { s->failed_pc=0x0c03ac9cu; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)r[6];
goto P_0c03ac9e;
P_0c03ac9e: /* original f75a, guest PC 0x0c03ac9e */
if(!s->budget--) { s->failed_pc=0x0c03ac9eu; return 0; }
vf3_matrix_store(s,ram,5,r[7]);
goto P_0c03aca0;
P_0c03aca0: /* original f787, guest PC 0x0c03aca0 */
if(!s->budget--) { s->failed_pc=0x0c03aca0u; return 0; }
vf3_matrix_store(s,ram,8,r[7]+r[0]);
goto P_0c03aca2;
P_0c03aca2: /* original e008, guest PC 0x0c03aca2 */
if(!s->budget--) { s->failed_pc=0x0c03aca2u; return 0; }
r[0]=0x00000008u;
goto P_0c03aca4;
P_0c03aca4: /* original f777, guest PC 0x0c03aca4 */
if(!s->budget--) { s->failed_pc=0x0c03aca4u; return 0; }
vf3_matrix_store(s,ram,7,r[7]+r[0]);
goto P_0c03aca6;
P_0c03aca6: /* original e00c, guest PC 0x0c03aca6 */
if(!s->budget--) { s->failed_pc=0x0c03aca6u; return 0; }
r[0]=0x0000000cu;
goto P_0c03aca8;
P_0c03aca8: /* original 6213, guest PC 0x0c03aca8 */
if(!s->budget--) { s->failed_pc=0x0c03aca8u; return 0; }
r[2]=r[1];
goto P_0c03acaa;
P_0c03acaa: /* original f757, guest PC 0x0c03acaa */
if(!s->budget--) { s->failed_pc=0x0c03acaau; return 0; }
vf3_matrix_store(s,ram,5,r[7]+r[0]);
goto P_0c03acac;
P_0c03acac: /* original 6013, guest PC 0x0c03acac */
if(!s->budget--) { s->failed_pc=0x0c03acacu; return 0; }
r[0]=r[1];
goto P_0c03acae;
P_0c03acae: /* original 4228, guest PC 0x0c03acae */
if(!s->budget--) { s->failed_pc=0x0c03acaeu; return 0; }
r[2]<<=16;
goto P_0c03acb0;
P_0c03acb0: /* original 4028, guest PC 0x0c03acb0 */
if(!s->budget--) { s->failed_pc=0x0c03acb0u; return 0; }
r[0]<<=16;
goto P_0c03acb2;
P_0c03acb2: /* original 4218, guest PC 0x0c03acb2 */
if(!s->budget--) { s->failed_pc=0x0c03acb2u; return 0; }
r[2]<<=8;
goto P_0c03acb4;
P_0c03acb4: /* original 220b, guest PC 0x0c03acb4 */
if(!s->budget--) { s->failed_pc=0x0c03acb4u; return 0; }
r[2]|=r[0];
goto P_0c03acb6;
P_0c03acb6: /* original 6013, guest PC 0x0c03acb6 */
if(!s->budget--) { s->failed_pc=0x0c03acb6u; return 0; }
r[0]=r[1];
goto P_0c03acb8;
P_0c03acb8: /* original 4018, guest PC 0x0c03acb8 */
if(!s->budget--) { s->failed_pc=0x0c03acb8u; return 0; }
r[0]<<=8;
goto P_0c03acba;
P_0c03acba: /* original 220b, guest PC 0x0c03acba */
if(!s->budget--) { s->failed_pc=0x0c03acbau; return 0; }
r[2]|=r[0];
goto P_0c03acbc;
P_0c03acbc: /* original 221b, guest PC 0x0c03acbc */
if(!s->budget--) { s->failed_pc=0x0c03acbcu; return 0; }
r[2]|=r[1];
goto P_0c03acbe;
P_0c03acbe: /* original 1724, guest PC 0x0c03acbe */
if(!s->budget--) { s->failed_pc=0x0c03acbeu; return 0; }
write(ram,r[7]+16,r[2],4);
goto P_0c03acc0;
P_0c03acc0: /* original 1745, guest PC 0x0c03acc0 */
if(!s->budget--) { s->failed_pc=0x0c03acc0u; return 0; }
write(ram,r[7]+20,r[4],4);
goto P_0c03acc2;
P_0c03acc2: /* original d674, guest PC 0x0c03acc2 */
if(!s->budget--) { s->failed_pc=0x0c03acc2u; return 0; }
r[6]=read(ram,0x0c03ae94u,4);
goto P_0c03acc4;
P_0c03acc4: /* original 256b, guest PC 0x0c03acc4 */
if(!s->budget--) { s->failed_pc=0x0c03acc4u; return 0; }
r[5]|=r[6];
goto P_0c03acc6;
P_0c03acc6: /* original 246b, guest PC 0x0c03acc6 */
if(!s->budget--) { s->failed_pc=0x0c03acc6u; return 0; }
r[4]|=r[6];
goto P_0c03acc8;
P_0c03acc8: /* original 1746, guest PC 0x0c03acc8 */
if(!s->budget--) { s->failed_pc=0x0c03acc8u; return 0; }
write(ram,r[7]+24,r[4],4);
goto P_0c03acca;
P_0c03acca: /* original 1757, guest PC 0x0c03acca */
if(!s->budget--) { s->failed_pc=0x0c03accau; return 0; }
write(ram,r[7]+28,r[5],4);
goto P_0c03accc;
P_0c03accc: /* original 0783, guest PC 0x0c03accc */
if(!s->budget--) { s->failed_pc=0x0c03acccu; return 0; }
if((r[7]&0xFC000000u)==0xE0000000u) pref(ram,r[7]);
goto P_0c03acce;
P_0c03acce: /* original 7720, guest PC 0x0c03acce */
if(!s->budget--) { s->failed_pc=0x0c03acceu; return 0; }
r[7]+=0x00000020u;
goto P_0c03acd0;
P_0c03acd0: /* original 000b, guest PC 0x0c03acd0 */
if(!s->budget--) { s->failed_pc=0x0c03acd0u; return 0; }
target=r[16];
r[0]=r[7];
s->pc=target; return ram->oob==0;
P_0c03acd2: /* original 6073, guest PC 0x0c03acd2 */
if(!s->budget--) { s->failed_pc=0x0c03acd2u; return 0; }
r[0]=r[7];
if(!vf3_matrix_family(0x0c03acd4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03acd4u; return 0; } return 1;
P_0c03b110: /* original 2fe6, guest PC 0x0c03b110 */
if(!s->budget--) { s->failed_pc=0x0c03b110u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b112;
P_0c03b112: /* original 2fd6, guest PC 0x0c03b112 */
if(!s->budget--) { s->failed_pc=0x0c03b112u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b114;
P_0c03b114: /* original 2fc6, guest PC 0x0c03b114 */
if(!s->budget--) { s->failed_pc=0x0c03b114u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b116;
P_0c03b116: /* original 6c43, guest PC 0x0c03b116 */
if(!s->budget--) { s->failed_pc=0x0c03b116u; return 0; }
r[12]=r[4];
goto P_0c03b118;
P_0c03b118: /* original 2fb6, guest PC 0x0c03b118 */
if(!s->budget--) { s->failed_pc=0x0c03b118u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b11a;
P_0c03b11a: /* original 2fa6, guest PC 0x0c03b11a */
if(!s->budget--) { s->failed_pc=0x0c03b11au; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03b11c;
P_0c03b11c: /* original d45e, guest PC 0x0c03b11c */
if(!s->budget--) { s->failed_pc=0x0c03b11cu; return 0; }
r[4]=read(ram,0x0c03b298u,4);
goto P_0c03b11e;
P_0c03b11e: /* original 4f22, guest PC 0x0c03b11e */
if(!s->budget--) { s->failed_pc=0x0c03b11eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03b120;
P_0c03b120: /* original 5345, guest PC 0x0c03b120 */
if(!s->budget--) { s->failed_pc=0x0c03b120u; return 0; }
r[3]=read(ram,r[4]+20,4);
goto P_0c03b122;
P_0c03b122: /* original 2338, guest PC 0x0c03b122 */
if(!s->budget--) { s->failed_pc=0x0c03b122u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03b124;
P_0c03b124: /* original 7ffc, guest PC 0x0c03b124 */
if(!s->budget--) { s->failed_pc=0x0c03b124u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c03b126;
P_0c03b126: /* original 8903, guest PC 0x0c03b126 */
if(!s->budget--) { s->failed_pc=0x0c03b126u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b130; }
goto P_0c03b128;
P_0c03b128: /* original a003, guest PC 0x0c03b128 */
if(!s->budget--) { s->failed_pc=0x0c03b128u; return 0; }
r[5]=0x00000000u;
goto P_0c03b132;
P_0c03b12a: /* original e500, guest PC 0x0c03b12a */
if(!s->budget--) { s->failed_pc=0x0c03b12au; return 0; }
r[5]=0x00000000u;
if(!vf3_matrix_family(0x0c03b12cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b12cu; return 0; } return 1;
P_0c03b130: /* original e502, guest PC 0x0c03b130 */
if(!s->budget--) { s->failed_pc=0x0c03b130u; return 0; }
r[5]=0x00000002u;
goto P_0c03b132;
P_0c03b132: /* original 4508, guest PC 0x0c03b132 */
if(!s->budget--) { s->failed_pc=0x0c03b132u; return 0; }
r[5]<<=2;
goto P_0c03b134;
P_0c03b134: /* original 2f52, guest PC 0x0c03b134 */
if(!s->budget--) { s->failed_pc=0x0c03b134u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c03b136;
P_0c03b136: /* original d359, guest PC 0x0c03b136 */
if(!s->budget--) { s->failed_pc=0x0c03b136u; return 0; }
r[3]=read(ram,0x0c03b29cu,4);
goto P_0c03b138;
P_0c03b138: /* original d154, guest PC 0x0c03b138 */
if(!s->budget--) { s->failed_pc=0x0c03b138u; return 0; }
r[1]=read(ram,0x0c03b28cu,4);
goto P_0c03b13a;
P_0c03b13a: /* original 6032, guest PC 0x0c03b13a */
if(!s->budget--) { s->failed_pc=0x0c03b13au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c03b13c;
P_0c03b13c: /* original d258, guest PC 0x0c03b13c */
if(!s->budget--) { s->failed_pc=0x0c03b13cu; return 0; }
r[2]=read(ram,0x0c03b2a0u,4);
goto P_0c03b13e;
P_0c03b13e: /* original 055e, guest PC 0x0c03b13e */
if(!s->budget--) { s->failed_pc=0x0c03b13eu; return 0; }
r[5]=read(ram,r[5]+r[0],4);
goto P_0c03b140;
P_0c03b140: /* original 6012, guest PC 0x0c03b140 */
if(!s->budget--) { s->failed_pc=0x0c03b140u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03b142;
P_0c03b142: /* original d358, guest PC 0x0c03b142 */
if(!s->budget--) { s->failed_pc=0x0c03b142u; return 0; }
r[3]=read(ram,0x0c03b2a4u,4);
goto P_0c03b144;
P_0c03b144: /* original c901, guest PC 0x0c03b144 */
if(!s->budget--) { s->failed_pc=0x0c03b144u; return 0; }
r[0]&=1u;
goto P_0c03b146;
P_0c03b146: /* original 6e22, guest PC 0x0c03b146 */
if(!s->budget--) { s->failed_pc=0x0c03b146u; return 0; }
tmp=read(ram,r[2],4);
r[14]=tmp;
goto P_0c03b148;
P_0c03b148: /* original 6253, guest PC 0x0c03b148 */
if(!s->budget--) { s->failed_pc=0x0c03b148u; return 0; }
r[2]=r[5];
goto P_0c03b14a;
P_0c03b14a: /* original 6a03, guest PC 0x0c03b14a */
if(!s->budget--) { s->failed_pc=0x0c03b14au; return 0; }
r[10]=r[0];
goto P_0c03b14c;
P_0c03b14c: /* original 6b32, guest PC 0x0c03b14c */
if(!s->budget--) { s->failed_pc=0x0c03b14cu; return 0; }
tmp=read(ram,r[3],4);
r[11]=tmp;
goto P_0c03b14e;
P_0c03b14e: /* original 4229, guest PC 0x0c03b14e */
if(!s->budget--) { s->failed_pc=0x0c03b14eu; return 0; }
r[2]>>=16;
goto P_0c03b150;
P_0c03b150: /* original d055, guest PC 0x0c03b150 */
if(!s->budget--) { s->failed_pc=0x0c03b150u; return 0; }
r[0]=read(ram,0x0c03b2a8u,4);
goto P_0c03b152;
P_0c03b152: /* original 4219, guest PC 0x0c03b152 */
if(!s->budget--) { s->failed_pc=0x0c03b152u; return 0; }
r[2]>>=8;
goto P_0c03b154;
P_0c03b154: /* original 2022, guest PC 0x0c03b154 */
if(!s->budget--) { s->failed_pc=0x0c03b154u; return 0; }
write(ram,r[0],r[2],4);
goto P_0c03b156;
P_0c03b156: /* original d355, guest PC 0x0c03b156 */
if(!s->budget--) { s->failed_pc=0x0c03b156u; return 0; }
r[3]=read(ram,0x0c03b2acu,4);
goto P_0c03b158;
P_0c03b158: /* original 2322, guest PC 0x0c03b158 */
if(!s->budget--) { s->failed_pc=0x0c03b158u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c03b15a;
P_0c03b15a: /* original dd55, guest PC 0x0c03b15a */
if(!s->budget--) { s->failed_pc=0x0c03b15au; return 0; }
r[13]=read(ram,0x0c03b2b0u,4);
goto P_0c03b15c;
P_0c03b15c: /* original d255, guest PC 0x0c03b15c */
if(!s->budget--) { s->failed_pc=0x0c03b15cu; return 0; }
r[2]=read(ram,0x0c03b2b4u,4);
goto P_0c03b15e;
P_0c03b15e: /* original 6342, guest PC 0x0c03b15e */
if(!s->budget--) { s->failed_pc=0x0c03b15eu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03b160;
P_0c03b160: /* original 2d59, guest PC 0x0c03b160 */
if(!s->budget--) { s->failed_pc=0x0c03b160u; return 0; }
r[13]&=r[5];
goto P_0c03b162;
P_0c03b162: /* original 2d2b, guest PC 0x0c03b162 */
if(!s->budget--) { s->failed_pc=0x0c03b162u; return 0; }
r[13]|=r[2];
goto P_0c03b164;
P_0c03b164: /* original 2d32, guest PC 0x0c03b164 */
if(!s->budget--) { s->failed_pc=0x0c03b164u; return 0; }
write(ram,r[13],r[3],4);
goto P_0c03b166;
P_0c03b166: /* original 5141, guest PC 0x0c03b166 */
if(!s->budget--) { s->failed_pc=0x0c03b166u; return 0; }
r[1]=read(ram,r[4]+4,4);
goto P_0c03b168;
P_0c03b168: /* original 1d11, guest PC 0x0c03b168 */
if(!s->budget--) { s->failed_pc=0x0c03b168u; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c03b16a;
P_0c03b16a: /* original 5342, guest PC 0x0c03b16a */
if(!s->budget--) { s->failed_pc=0x0c03b16au; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c03b16c;
P_0c03b16c: /* original 1d32, guest PC 0x0c03b16c */
if(!s->budget--) { s->failed_pc=0x0c03b16cu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c03b16e;
P_0c03b16e: /* original 5143, guest PC 0x0c03b16e */
if(!s->budget--) { s->failed_pc=0x0c03b16eu; return 0; }
r[1]=read(ram,r[4]+12,4);
goto P_0c03b170;
P_0c03b170: /* original 1d13, guest PC 0x0c03b170 */
if(!s->budget--) { s->failed_pc=0x0c03b170u; return 0; }
write(ram,r[13]+12,r[1],4);
goto P_0c03b172;
P_0c03b172: /* original 5344, guest PC 0x0c03b172 */
if(!s->budget--) { s->failed_pc=0x0c03b172u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c03b174;
P_0c03b174: /* original 1d34, guest PC 0x0c03b174 */
if(!s->budget--) { s->failed_pc=0x0c03b174u; return 0; }
write(ram,r[13]+16,r[3],4);
goto P_0c03b176;
P_0c03b176: /* original 0d83, guest PC 0x0c03b176 */
if(!s->budget--) { s->failed_pc=0x0c03b176u; return 0; }
if((r[13]&0xFC000000u)==0xE0000000u) pref(ram,r[13]);
goto P_0c03b178;
P_0c03b178: /* original a02c, guest PC 0x0c03b178 */
if(!s->budget--) { s->failed_pc=0x0c03b178u; return 0; }
r[13]+=0x00000020u;
goto P_0c03b1d4;
P_0c03b17a: /* original 7d20, guest PC 0x0c03b17a */
if(!s->budget--) { s->failed_pc=0x0c03b17au; return 0; }
r[13]+=0x00000020u;
if(!vf3_matrix_family(0x0c03b17cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b17cu; return 0; } return 1;
P_0c03b180: /* original 60c0, guest PC 0x0c03b180 */
if(!s->budget--) { s->failed_pc=0x0c03b180u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[0]=tmp;
goto P_0c03b182;
P_0c03b182: /* original 8820, guest PC 0x0c03b182 */
if(!s->budget--) { s->failed_pc=0x0c03b182u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c03b184;
P_0c03b184: /* original 8922, guest PC 0x0c03b184 */
if(!s->budget--) { s->failed_pc=0x0c03b184u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03b1cc; }
goto P_0c03b186;
P_0c03b186: /* original 60c0, guest PC 0x0c03b186 */
if(!s->budget--) { s->failed_pc=0x0c03b186u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[0]=tmp;
goto P_0c03b188;
P_0c03b188: /* original e400, guest PC 0x0c03b188 */
if(!s->budget--) { s->failed_pc=0x0c03b188u; return 0; }
r[4]=0x00000000u;
goto P_0c03b18a;
P_0c03b18a: /* original d64b, guest PC 0x0c03b18a */
if(!s->budget--) { s->failed_pc=0x0c03b18au; return 0; }
r[6]=read(ram,0x0c03b2b8u,4);
goto P_0c03b18c;
P_0c03b18c: /* original 880a, guest PC 0x0c03b18c */
if(!s->budget--) { s->failed_pc=0x0c03b18cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c03b18e;
P_0c03b18e: /* original 8f0f, guest PC 0x0c03b18e */
if(!s->budget--) { s->failed_pc=0x0c03b18eu; return 0; }
cond=r[17]&1u;
tmp=read(ram,r[6],4);
r[5]=tmp;
if(!cond) { goto P_0c03b1b0; }
goto P_0c03b192;
P_0c03b190: /* original 6562, guest PC 0x0c03b190 */
if(!s->budget--) { s->failed_pc=0x0c03b190u; return 0; }
tmp=read(ram,r[6],4);
r[5]=tmp;
goto P_0c03b192;
P_0c03b192: /* original 2aa8, guest PC 0x0c03b192 */
if(!s->budget--) { s->failed_pc=0x0c03b192u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c03b194;
P_0c03b194: /* original 8d01, guest PC 0x0c03b194 */
if(!s->budget--) { s->failed_pc=0x0c03b194u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c03b19a; }
goto P_0c03b198;
P_0c03b196: /* original 6e43, guest PC 0x0c03b196 */
if(!s->budget--) { s->failed_pc=0x0c03b196u; return 0; }
r[14]=r[4];
goto P_0c03b198;
P_0c03b198: /* original 6e53, guest PC 0x0c03b198 */
if(!s->budget--) { s->failed_pc=0x0c03b198u; return 0; }
r[14]=r[5];
goto P_0c03b19a;
P_0c03b19a: /* original d43e, guest PC 0x0c03b19a */
if(!s->budget--) { s->failed_pc=0x0c03b19au; return 0; }
r[4]=read(ram,0x0c03b294u,4);
goto P_0c03b19c;
P_0c03b19c: /* original 6342, guest PC 0x0c03b19c */
if(!s->budget--) { s->failed_pc=0x0c03b19cu; return 0; }
tmp=read(ram,r[4],4);
r[3]=tmp;
goto P_0c03b19e;
P_0c03b19e: /* original a018, guest PC 0x0c03b19e */
if(!s->budget--) { s->failed_pc=0x0c03b19eu; return 0; }
r[11]+=r[3];
goto P_0c03b1d2;
P_0c03b1a0: /* original 3b3c, guest PC 0x0c03b1a0 */
if(!s->budget--) { s->failed_pc=0x0c03b1a0u; return 0; }
r[11]+=r[3];
if(!vf3_matrix_family(0x0c03b1a2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b1a2u; return 0; } return 1;
P_0c03b1b0: /* original 880d, guest PC 0x0c03b1b0 */
if(!s->budget--) { s->failed_pc=0x0c03b1b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c03b1b2;
P_0c03b1b2: /* original 8b05, guest PC 0x0c03b1b2 */
if(!s->budget--) { s->failed_pc=0x0c03b1b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03b1c0; }
goto P_0c03b1b4;
P_0c03b1b4: /* original 2aa8, guest PC 0x0c03b1b4 */
if(!s->budget--) { s->failed_pc=0x0c03b1b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c03b1b6;
P_0c03b1b6: /* original 8d0c, guest PC 0x0c03b1b6 */
if(!s->budget--) { s->failed_pc=0x0c03b1b6u; return 0; }
cond=r[17]&1u;
r[14]=r[4];
if(cond) { goto P_0c03b1d2; }
goto P_0c03b1ba;
P_0c03b1b8: /* original 6e43, guest PC 0x0c03b1b8 */
if(!s->budget--) { s->failed_pc=0x0c03b1b8u; return 0; }
r[14]=r[4];
goto P_0c03b1ba;
P_0c03b1ba: /* original a00a, guest PC 0x0c03b1ba */
if(!s->budget--) { s->failed_pc=0x0c03b1bau; return 0; }
r[14]=r[5];
goto P_0c03b1d2;
P_0c03b1bc: /* original 6e53, guest PC 0x0c03b1bc */
if(!s->budget--) { s->failed_pc=0x0c03b1bcu; return 0; }
r[14]=r[5];
if(!vf3_matrix_family(0x0c03b1beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b1beu; return 0; } return 1;
P_0c03b1c0: /* original 66c0, guest PC 0x0c03b1c0 */
if(!s->budget--) { s->failed_pc=0x0c03b1c0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[6]=tmp;
goto P_0c03b1c2;
P_0c03b1c2: /* original 65b3, guest PC 0x0c03b1c2 */
if(!s->budget--) { s->failed_pc=0x0c03b1c2u; return 0; }
r[5]=r[11];
goto P_0c03b1c4;
P_0c03b1c4: /* original 67d3, guest PC 0x0c03b1c4 */
if(!s->budget--) { s->failed_pc=0x0c03b1c4u; return 0; }
r[7]=r[13];
goto P_0c03b1c6;
P_0c03b1c6: /* original bd3b, guest PC 0x0c03b1c6 */
if(!s->budget--) { s->failed_pc=0x0c03b1c6u; return 0; }
target=code_base|0x0c03ac40u; r[16]=code_base|0x0c03b1cau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03b1cau) { target=s->pc; goto dispatch; }
goto P_0c03b1ca;
P_0c03b1c8: /* original 64e3, guest PC 0x0c03b1c8 */
if(!s->budget--) { s->failed_pc=0x0c03b1c8u; return 0; }
r[4]=r[14];
goto P_0c03b1ca;
P_0c03b1ca: /* original 6d03, guest PC 0x0c03b1ca */
if(!s->budget--) { s->failed_pc=0x0c03b1cau; return 0; }
r[13]=r[0];
goto P_0c03b1cc;
P_0c03b1cc: /* original d430, guest PC 0x0c03b1cc */
if(!s->budget--) { s->failed_pc=0x0c03b1ccu; return 0; }
r[4]=read(ram,0x0c03b290u,4);
goto P_0c03b1ce;
P_0c03b1ce: /* original 6242, guest PC 0x0c03b1ce */
if(!s->budget--) { s->failed_pc=0x0c03b1ceu; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c03b1d0;
P_0c03b1d0: /* original 3e2c, guest PC 0x0c03b1d0 */
if(!s->budget--) { s->failed_pc=0x0c03b1d0u; return 0; }
r[14]+=r[2];
goto P_0c03b1d2;
P_0c03b1d2: /* original 7c01, guest PC 0x0c03b1d2 */
if(!s->budget--) { s->failed_pc=0x0c03b1d2u; return 0; }
r[12]+=0x00000001u;
goto P_0c03b1d4;
P_0c03b1d4: /* original 63c0, guest PC 0x0c03b1d4 */
if(!s->budget--) { s->failed_pc=0x0c03b1d4u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[12],1);
r[3]=tmp;
goto P_0c03b1d6;
P_0c03b1d6: /* original 2338, guest PC 0x0c03b1d6 */
if(!s->budget--) { s->failed_pc=0x0c03b1d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c03b1d8;
P_0c03b1d8: /* original 8bd2, guest PC 0x0c03b1d8 */
if(!s->budget--) { s->failed_pc=0x0c03b1d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03b180; }
goto P_0c03b1da;
P_0c03b1da: /* original d331, guest PC 0x0c03b1da */
if(!s->budget--) { s->failed_pc=0x0c03b1dau; return 0; }
r[3]=read(ram,0x0c03b2a0u,4);
goto P_0c03b1dc;
P_0c03b1dc: /* original 23e2, guest PC 0x0c03b1dc */
if(!s->budget--) { s->failed_pc=0x0c03b1dcu; return 0; }
write(ram,r[3],r[14],4);
goto P_0c03b1de;
P_0c03b1de: /* original d231, guest PC 0x0c03b1de */
if(!s->budget--) { s->failed_pc=0x0c03b1deu; return 0; }
r[2]=read(ram,0x0c03b2a4u,4);
goto P_0c03b1e0;
P_0c03b1e0: /* original 22b2, guest PC 0x0c03b1e0 */
if(!s->budget--) { s->failed_pc=0x0c03b1e0u; return 0; }
write(ram,r[2],r[11],4);
goto P_0c03b1e2;
P_0c03b1e2: /* original 64f2, guest PC 0x0c03b1e2 */
if(!s->budget--) { s->failed_pc=0x0c03b1e2u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c03b1e4;
P_0c03b1e4: /* original 7f04, guest PC 0x0c03b1e4 */
if(!s->budget--) { s->failed_pc=0x0c03b1e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c03b1e6;
P_0c03b1e6: /* original d02d, guest PC 0x0c03b1e6 */
if(!s->budget--) { s->failed_pc=0x0c03b1e6u; return 0; }
r[0]=read(ram,0x0c03b29cu,4);
goto P_0c03b1e8;
P_0c03b1e8: /* original 4f26, guest PC 0x0c03b1e8 */
if(!s->budget--) { s->failed_pc=0x0c03b1e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03b1ea;
P_0c03b1ea: /* original 6102, guest PC 0x0c03b1ea */
if(!s->budget--) { s->failed_pc=0x0c03b1eau; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c03b1ec;
P_0c03b1ec: /* original d333, guest PC 0x0c03b1ec */
if(!s->budget--) { s->failed_pc=0x0c03b1ecu; return 0; }
r[3]=read(ram,0x0c03b2bcu,4);
goto P_0c03b1ee;
P_0c03b1ee: /* original 341c, guest PC 0x0c03b1ee */
if(!s->budget--) { s->failed_pc=0x0c03b1eeu; return 0; }
r[4]+=r[1];
goto P_0c03b1f0;
P_0c03b1f0: /* original d22f, guest PC 0x0c03b1f0 */
if(!s->budget--) { s->failed_pc=0x0c03b1f0u; return 0; }
r[2]=read(ram,0x0c03b2b0u,4);
goto P_0c03b1f2;
P_0c03b1f2: /* original 6042, guest PC 0x0c03b1f2 */
if(!s->budget--) { s->failed_pc=0x0c03b1f2u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c03b1f4;
P_0c03b1f4: /* original 2d29, guest PC 0x0c03b1f4 */
if(!s->budget--) { s->failed_pc=0x0c03b1f4u; return 0; }
r[13]&=r[2];
goto P_0c03b1f6;
P_0c03b1f6: /* original 2039, guest PC 0x0c03b1f6 */
if(!s->budget--) { s->failed_pc=0x0c03b1f6u; return 0; }
r[0]&=r[3];
goto P_0c03b1f8;
P_0c03b1f8: /* original 20db, guest PC 0x0c03b1f8 */
if(!s->budget--) { s->failed_pc=0x0c03b1f8u; return 0; }
r[0]|=r[13];
goto P_0c03b1fa;
P_0c03b1fa: /* original 2402, guest PC 0x0c03b1fa */
if(!s->budget--) { s->failed_pc=0x0c03b1fau; return 0; }
write(ram,r[4],r[0],4);
goto P_0c03b1fc;
P_0c03b1fc: /* original 6af6, guest PC 0x0c03b1fc */
if(!s->budget--) { s->failed_pc=0x0c03b1fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03b1fe;
P_0c03b1fe: /* original 6bf6, guest PC 0x0c03b1fe */
if(!s->budget--) { s->failed_pc=0x0c03b1feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03b200;
P_0c03b200: /* original 6cf6, guest PC 0x0c03b200 */
if(!s->budget--) { s->failed_pc=0x0c03b200u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03b202;
P_0c03b202: /* original 6df6, guest PC 0x0c03b202 */
if(!s->budget--) { s->failed_pc=0x0c03b202u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03b204;
P_0c03b204: /* original 000b, guest PC 0x0c03b204 */
if(!s->budget--) { s->failed_pc=0x0c03b204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03b206: /* original 6ef6, guest PC 0x0c03b206 */
if(!s->budget--) { s->failed_pc=0x0c03b206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03b208u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b208u; return 0; } return 1;
P_0c03b5c0: /* original fbfd, guest PC 0x0c03b5c0 */
if(!s->budget--) { s->failed_pc=0x0c03b5c0u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b5c2;
P_0c03b5c2: /* original f3ed, guest PC 0x0c03b5c2 */
if(!s->budget--) { s->failed_pc=0x0c03b5c2u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03b5c4;
P_0c03b5c4: /* original f7ed, guest PC 0x0c03b5c4 */
if(!s->budget--) { s->failed_pc=0x0c03b5c4u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03b5c6;
P_0c03b5c6: /* original fbed, guest PC 0x0c03b5c6 */
if(!s->budget--) { s->failed_pc=0x0c03b5c6u; return 0; }
if(!vf3_fpu_fipr(fr+12,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03b5c8;
P_0c03b5c8: /* original fc3c, guest PC 0x0c03b5c8 */
if(!s->budget--) { s->failed_pc=0x0c03b5c8u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c03b5ca;
P_0c03b5ca: /* original f331, guest PC 0x0c03b5ca */
if(!s->budget--) { s->failed_pc=0x0c03b5cau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[3],r[18],'-');
goto P_0c03b5cc;
P_0c03b5cc: /* original fd7c, guest PC 0x0c03b5cc */
if(!s->budget--) { s->failed_pc=0x0c03b5ccu; return 0; }
vf3_matrix_move(s,13,7);
goto P_0c03b5ce;
P_0c03b5ce: /* original f771, guest PC 0x0c03b5ce */
if(!s->budget--) { s->failed_pc=0x0c03b5ceu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03b5d0;
P_0c03b5d0: /* original febc, guest PC 0x0c03b5d0 */
if(!s->budget--) { s->failed_pc=0x0c03b5d0u; return 0; }
vf3_matrix_move(s,14,11);
goto P_0c03b5d2;
P_0c03b5d2: /* original fbb1, guest PC 0x0c03b5d2 */
if(!s->budget--) { s->failed_pc=0x0c03b5d2u; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[11],r[18],'-');
goto P_0c03b5d4;
P_0c03b5d4: /* original f0ed, guest PC 0x0c03b5d4 */
if(!s->budget--) { s->failed_pc=0x0c03b5d4u; return 0; }
if(!vf3_fpu_fipr(fr+0,fr+0,r[18],fr+3)) goto unsupported;
goto P_0c03b5d6;
P_0c03b5d6: /* original fc4d, guest PC 0x0c03b5d6 */
if(!s->budget--) { s->failed_pc=0x0c03b5d6u; return 0; }
fr[12]^=0x80000000u;
goto P_0c03b5d8;
P_0c03b5d8: /* original f5ed, guest PC 0x0c03b5d8 */
if(!s->budget--) { s->failed_pc=0x0c03b5d8u; return 0; }
if(!vf3_fpu_fipr(fr+4,fr+4,r[18],fr+7)) goto unsupported;
goto P_0c03b5da;
P_0c03b5da: /* original fd4d, guest PC 0x0c03b5da */
if(!s->budget--) { s->failed_pc=0x0c03b5dau; return 0; }
fr[13]^=0x80000000u;
goto P_0c03b5dc;
P_0c03b5dc: /* original faed, guest PC 0x0c03b5dc */
if(!s->budget--) { s->failed_pc=0x0c03b5dcu; return 0; }
if(!vf3_fpu_fipr(fr+8,fr+8,r[18],fr+11)) goto unsupported;
goto P_0c03b5de;
P_0c03b5de: /* original fe4d, guest PC 0x0c03b5de */
if(!s->budget--) { s->failed_pc=0x0c03b5deu; return 0; }
fr[14]^=0x80000000u;
goto P_0c03b5e0;
P_0c03b5e0: /* original f37d, guest PC 0x0c03b5e0 */
if(!s->budget--) { s->failed_pc=0x0c03b5e0u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c03b5e2;
P_0c03b5e2: /* original f77d, guest PC 0x0c03b5e2 */
if(!s->budget--) { s->failed_pc=0x0c03b5e2u; return 0; }
if(!vf3_fpu_fsrra(fr[7],r[18],&fr[7])) goto unsupported;
goto P_0c03b5e4;
P_0c03b5e4: /* original fb7d, guest PC 0x0c03b5e4 */
if(!s->budget--) { s->failed_pc=0x0c03b5e4u; return 0; }
if(!vf3_fpu_fsrra(fr[11],r[18],&fr[11])) goto unsupported;
goto P_0c03b5e6;
P_0c03b5e6: /* original f132, guest PC 0x0c03b5e6 */
if(!s->budget--) { s->failed_pc=0x0c03b5e6u; return 0; }
fr[1]=vf3_fpu_binary(fr[1],fr[3],r[18],'*');
goto P_0c03b5e8;
P_0c03b5e8: /* original f472, guest PC 0x0c03b5e8 */
if(!s->budget--) { s->failed_pc=0x0c03b5e8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'*');
goto P_0c03b5ea;
P_0c03b5ea: /* original f232, guest PC 0x0c03b5ea */
if(!s->budget--) { s->failed_pc=0x0c03b5eau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c03b5ec;
P_0c03b5ec: /* original f11d, guest PC 0x0c03b5ec */
if(!s->budget--) { s->failed_pc=0x0c03b5ecu; return 0; }
r[53]=fr[1];
goto P_0c03b5ee;
P_0c03b5ee: /* original f8b2, guest PC 0x0c03b5ee */
if(!s->budget--) { s->failed_pc=0x0c03b5eeu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[11],r[18],'*');
goto P_0c03b5f0;
P_0c03b5f0: /* original f14c, guest PC 0x0c03b5f0 */
if(!s->budget--) { s->failed_pc=0x0c03b5f0u; return 0; }
vf3_matrix_move(s,1,4);
goto P_0c03b5f2;
P_0c03b5f2: /* original f672, guest PC 0x0c03b5f2 */
if(!s->budget--) { s->failed_pc=0x0c03b5f2u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c03b5f4;
P_0c03b5f4: /* original f40d, guest PC 0x0c03b5f4 */
if(!s->budget--) { s->failed_pc=0x0c03b5f4u; return 0; }
fr[4]=r[53];
goto P_0c03b5f6;
P_0c03b5f6: /* original f9b2, guest PC 0x0c03b5f6 */
if(!s->budget--) { s->failed_pc=0x0c03b5f6u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[11],r[18],'*');
goto P_0c03b5f8;
P_0c03b5f8: /* original f21d, guest PC 0x0c03b5f8 */
if(!s->budget--) { s->failed_pc=0x0c03b5f8u; return 0; }
r[53]=fr[2];
goto P_0c03b5fa;
P_0c03b5fa: /* original f032, guest PC 0x0c03b5fa */
if(!s->budget--) { s->failed_pc=0x0c03b5fau; return 0; }
fr[0]=vf3_fpu_binary(fr[0],fr[3],r[18],'*');
goto P_0c03b5fc;
P_0c03b5fc: /* original f28c, guest PC 0x0c03b5fc */
if(!s->budget--) { s->failed_pc=0x0c03b5fcu; return 0; }
vf3_matrix_move(s,2,8);
goto P_0c03b5fe;
P_0c03b5fe: /* original f572, guest PC 0x0c03b5fe */
if(!s->budget--) { s->failed_pc=0x0c03b5feu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[7],r[18],'*');
goto P_0c03b600;
P_0c03b600: /* original f80d, guest PC 0x0c03b600 */
if(!s->budget--) { s->failed_pc=0x0c03b600u; return 0; }
fr[8]=r[53];
goto P_0c03b602;
P_0c03b602: /* original fab2, guest PC 0x0c03b602 */
if(!s->budget--) { s->failed_pc=0x0c03b602u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[11],r[18],'*');
goto P_0c03b604;
P_0c03b604: /* original f61d, guest PC 0x0c03b604 */
if(!s->budget--) { s->failed_pc=0x0c03b604u; return 0; }
r[53]=fr[6];
goto P_0c03b606;
P_0c03b606: /* original fc32, guest PC 0x0c03b606 */
if(!s->budget--) { s->failed_pc=0x0c03b606u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'*');
goto P_0c03b608;
P_0c03b608: /* original f69c, guest PC 0x0c03b608 */
if(!s->budget--) { s->failed_pc=0x0c03b608u; return 0; }
vf3_matrix_move(s,6,9);
goto P_0c03b60a;
P_0c03b60a: /* original fd72, guest PC 0x0c03b60a */
if(!s->budget--) { s->failed_pc=0x0c03b60au; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[7],r[18],'*');
goto P_0c03b60c;
P_0c03b60c: /* original f90d, guest PC 0x0c03b60c */
if(!s->budget--) { s->failed_pc=0x0c03b60cu; return 0; }
fr[9]=r[53];
goto P_0c03b60e;
P_0c03b60e: /* original feb2, guest PC 0x0c03b60e */
if(!s->budget--) { s->failed_pc=0x0c03b60eu; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[11],r[18],'*');
goto P_0c03b610;
P_0c03b610: /* original f38d, guest PC 0x0c03b610 */
if(!s->budget--) { s->failed_pc=0x0c03b610u; return 0; }
fr[3]=0;
goto P_0c03b612;
P_0c03b612: /* original f771, guest PC 0x0c03b612 */
if(!s->budget--) { s->failed_pc=0x0c03b612u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[7],r[18],'-');
goto P_0c03b614;
P_0c03b614: /* original fb8d, guest PC 0x0c03b614 */
if(!s->budget--) { s->failed_pc=0x0c03b614u; return 0; }
fr[11]=0;
goto P_0c03b616;
P_0c03b616: /* original fbfd, guest PC 0x0c03b616 */
if(!s->budget--) { s->failed_pc=0x0c03b616u; return 0; }
vf3_matrix_swap(s);
goto P_0c03b618;
P_0c03b618: /* original 000b, guest PC 0x0c03b618 */
if(!s->budget--) { s->failed_pc=0x0c03b618u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c03b61a: /* original 0009, guest PC 0x0c03b61a */
if(!s->budget--) { s->failed_pc=0x0c03b61au; return 0; }
if(!vf3_matrix_family(0x0c03b61cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03b61cu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
