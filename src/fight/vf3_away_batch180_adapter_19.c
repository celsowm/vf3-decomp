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
int vf3_away_batch180_adapter_19(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07aaacu: goto P_0c07aaac;
case 0x0c07aaaeu: goto P_0c07aaae;
case 0x0c07aab0u: goto P_0c07aab0;
case 0x0c07aab2u: goto P_0c07aab2;
case 0x0c07aab4u: goto P_0c07aab4;
case 0x0c07aab6u: goto P_0c07aab6;
case 0x0c07aab8u: goto P_0c07aab8;
case 0x0c07aabau: goto P_0c07aaba;
case 0x0c07aabcu: goto P_0c07aabc;
case 0x0c07aabeu: goto P_0c07aabe;
case 0x0c07aac0u: goto P_0c07aac0;
case 0x0c07aac2u: goto P_0c07aac2;
case 0x0c07aac4u: goto P_0c07aac4;
case 0x0c07aac6u: goto P_0c07aac6;
case 0x0c07aac8u: goto P_0c07aac8;
case 0x0c07aacau: goto P_0c07aaca;
case 0x0c07aaccu: goto P_0c07aacc;
case 0x0c07aaceu: goto P_0c07aace;
case 0x0c07aad0u: goto P_0c07aad0;
case 0x0c07aad2u: goto P_0c07aad2;
case 0x0c07aad4u: goto P_0c07aad4;
case 0x0c07aad6u: goto P_0c07aad6;
case 0x0c07aad8u: goto P_0c07aad8;
case 0x0c07aadau: goto P_0c07aada;
case 0x0c07aadcu: goto P_0c07aadc;
case 0x0c07aadeu: goto P_0c07aade;
case 0x0c07aae0u: goto P_0c07aae0;
case 0x0c07aae2u: goto P_0c07aae2;
case 0x0c07aae4u: goto P_0c07aae4;
case 0x0c07aae6u: goto P_0c07aae6;
case 0x0c07aae8u: goto P_0c07aae8;
case 0x0c07aaeau: goto P_0c07aaea;
case 0x0c07aaecu: goto P_0c07aaec;
case 0x0c07aaeeu: goto P_0c07aaee;
case 0x0c07aaf0u: goto P_0c07aaf0;
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
case 0x0c07b204u: goto P_0c07b204;
case 0x0c07b206u: goto P_0c07b206;
case 0x0c07b208u: goto P_0c07b208;
case 0x0c07b20au: goto P_0c07b20a;
case 0x0c07b20cu: goto P_0c07b20c;
case 0x0c07b20eu: goto P_0c07b20e;
case 0x0c07b210u: goto P_0c07b210;
case 0x0c07b212u: goto P_0c07b212;
case 0x0c07b214u: goto P_0c07b214;
case 0x0c07b216u: goto P_0c07b216;
case 0x0c07b218u: goto P_0c07b218;
case 0x0c07b21au: goto P_0c07b21a;
case 0x0c07b21cu: goto P_0c07b21c;
case 0x0c07b21eu: goto P_0c07b21e;
case 0x0c07b220u: goto P_0c07b220;
case 0x0c07b222u: goto P_0c07b222;
case 0x0c07b224u: goto P_0c07b224;
case 0x0c07b226u: goto P_0c07b226;
case 0x0c07b228u: goto P_0c07b228;
case 0x0c07b22au: goto P_0c07b22a;
case 0x0c07b22cu: goto P_0c07b22c;
case 0x0c07b22eu: goto P_0c07b22e;
case 0x0c07b230u: goto P_0c07b230;
case 0x0c07b232u: goto P_0c07b232;
case 0x0c07b234u: goto P_0c07b234;
case 0x0c07b236u: goto P_0c07b236;
case 0x0c07b238u: goto P_0c07b238;
case 0x0c07b23au: goto P_0c07b23a;
case 0x0c07b23cu: goto P_0c07b23c;
case 0x0c07b23eu: goto P_0c07b23e;
case 0x0c07b240u: goto P_0c07b240;
case 0x0c07b242u: goto P_0c07b242;
case 0x0c07b244u: goto P_0c07b244;
case 0x0c07b246u: goto P_0c07b246;
case 0x0c07b248u: goto P_0c07b248;
case 0x0c07b24au: goto P_0c07b24a;
case 0x0c07b24cu: goto P_0c07b24c;
case 0x0c07b24eu: goto P_0c07b24e;
case 0x0c07b250u: goto P_0c07b250;
case 0x0c07b252u: goto P_0c07b252;
case 0x0c07b254u: goto P_0c07b254;
case 0x0c07b256u: goto P_0c07b256;
case 0x0c07b258u: goto P_0c07b258;
case 0x0c07b25au: goto P_0c07b25a;
case 0x0c07b25cu: goto P_0c07b25c;
case 0x0c07b25eu: goto P_0c07b25e;
case 0x0c07b260u: goto P_0c07b260;
case 0x0c07b262u: goto P_0c07b262;
case 0x0c07b264u: goto P_0c07b264;
case 0x0c07b266u: goto P_0c07b266;
case 0x0c07b268u: goto P_0c07b268;
case 0x0c07b26au: goto P_0c07b26a;
case 0x0c07b26cu: goto P_0c07b26c;
case 0x0c07b26eu: goto P_0c07b26e;
case 0x0c07b270u: goto P_0c07b270;
case 0x0c07b272u: goto P_0c07b272;
case 0x0c07b274u: goto P_0c07b274;
case 0x0c07b276u: goto P_0c07b276;
case 0x0c07b278u: goto P_0c07b278;
case 0x0c07b27au: goto P_0c07b27a;
case 0x0c07b27cu: goto P_0c07b27c;
case 0x0c07b27eu: goto P_0c07b27e;
case 0x0c07b280u: goto P_0c07b280;
case 0x0c07b282u: goto P_0c07b282;
case 0x0c07b284u: goto P_0c07b284;
case 0x0c07b286u: goto P_0c07b286;
case 0x0c07b288u: goto P_0c07b288;
case 0x0c07b28au: goto P_0c07b28a;
case 0x0c07b28cu: goto P_0c07b28c;
case 0x0c07b28eu: goto P_0c07b28e;
case 0x0c07b290u: goto P_0c07b290;
case 0x0c07b292u: goto P_0c07b292;
case 0x0c07b294u: goto P_0c07b294;
case 0x0c07b296u: goto P_0c07b296;
case 0x0c07b298u: goto P_0c07b298;
case 0x0c07b29au: goto P_0c07b29a;
case 0x0c07b29cu: goto P_0c07b29c;
case 0x0c07b29eu: goto P_0c07b29e;
case 0x0c07b2a0u: goto P_0c07b2a0;
case 0x0c07b2a2u: goto P_0c07b2a2;
case 0x0c07b2a4u: goto P_0c07b2a4;
case 0x0c07b2a6u: goto P_0c07b2a6;
case 0x0c07b2a8u: goto P_0c07b2a8;
case 0x0c07b2aau: goto P_0c07b2aa;
case 0x0c07b2acu: goto P_0c07b2ac;
case 0x0c07b2aeu: goto P_0c07b2ae;
case 0x0c07b2b0u: goto P_0c07b2b0;
case 0x0c07b2b2u: goto P_0c07b2b2;
case 0x0c07b2b4u: goto P_0c07b2b4;
case 0x0c07b2b6u: goto P_0c07b2b6;
case 0x0c07b2b8u: goto P_0c07b2b8;
case 0x0c07b2bau: goto P_0c07b2ba;
case 0x0c07b2bcu: goto P_0c07b2bc;
case 0x0c07b5b0u: goto P_0c07b5b0;
case 0x0c07b5b2u: goto P_0c07b5b2;
case 0x0c07b5b4u: goto P_0c07b5b4;
case 0x0c07b5b6u: goto P_0c07b5b6;
case 0x0c07b5b8u: goto P_0c07b5b8;
case 0x0c07b5bau: goto P_0c07b5ba;
case 0x0c07b5bcu: goto P_0c07b5bc;
case 0x0c07b5beu: goto P_0c07b5be;
case 0x0c07b5c0u: goto P_0c07b5c0;
case 0x0c07b5c2u: goto P_0c07b5c2;
case 0x0c07b5c4u: goto P_0c07b5c4;
case 0x0c07b5c6u: goto P_0c07b5c6;
case 0x0c07b5c8u: goto P_0c07b5c8;
case 0x0c07b5cau: goto P_0c07b5ca;
case 0x0c07b5ccu: goto P_0c07b5cc;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07aaac: /* original 2fe6, guest PC 0x0c07aaac */
if(!s->budget--) { s->failed_pc=0x0c07aaacu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07aaae;
P_0c07aaae: /* original 2fd6, guest PC 0x0c07aaae */
if(!s->budget--) { s->failed_pc=0x0c07aaaeu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07aab0;
P_0c07aab0: /* original 4f22, guest PC 0x0c07aab0 */
if(!s->budget--) { s->failed_pc=0x0c07aab0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07aab2;
P_0c07aab2: /* original d314, guest PC 0x0c07aab2 */
if(!s->budget--) { s->failed_pc=0x0c07aab2u; return 0; }
r[3]=read(ram,0x0c07ab04u,4);
goto P_0c07aab4;
P_0c07aab4: /* original b57c, guest PC 0x0c07aab4 */
if(!s->budget--) { s->failed_pc=0x0c07aab4u; return 0; }
target=code_base|0x0c07b5b0u; r[16]=code_base|0x0c07aab8u;
tmp=read(ram,r[3],4);
r[13]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aab8u) { target=s->pc; goto dispatch; }
goto P_0c07aab8;
P_0c07aab6: /* original 6d32, guest PC 0x0c07aab6 */
if(!s->budget--) { s->failed_pc=0x0c07aab6u; return 0; }
tmp=read(ram,r[3],4);
r[13]=tmp;
goto P_0c07aab8;
P_0c07aab8: /* original 6e03, guest PC 0x0c07aab8 */
if(!s->budget--) { s->failed_pc=0x0c07aab8u; return 0; }
r[14]=r[0];
goto P_0c07aaba;
P_0c07aaba: /* original d00e, guest PC 0x0c07aaba */
if(!s->budget--) { s->failed_pc=0x0c07aabau; return 0; }
r[0]=read(ram,0x0c07aaf4u,4);
goto P_0c07aabc;
P_0c07aabc: /* original 64ed, guest PC 0x0c07aabc */
if(!s->budget--) { s->failed_pc=0x0c07aabcu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aabe;
P_0c07aabe: /* original 4400, guest PC 0x0c07aabe */
if(!s->budget--) { s->failed_pc=0x0c07aabeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07aac0;
P_0c07aac0: /* original 044d, guest PC 0x0c07aac0 */
if(!s->budget--) { s->failed_pc=0x0c07aac0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07aac2;
P_0c07aac2: /* original 644d, guest PC 0x0c07aac2 */
if(!s->budget--) { s->failed_pc=0x0c07aac2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07aac4;
P_0c07aac4: /* original 2448, guest PC 0x0c07aac4 */
if(!s->budget--) { s->failed_pc=0x0c07aac4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07aac6;
P_0c07aac6: /* original 8902, guest PC 0x0c07aac6 */
if(!s->budget--) { s->failed_pc=0x0c07aac6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07aace; }
goto P_0c07aac8;
P_0c07aac8: /* original d20b, guest PC 0x0c07aac8 */
if(!s->budget--) { s->failed_pc=0x0c07aac8u; return 0; }
r[2]=read(ram,0x0c07aaf8u,4);
goto P_0c07aaca;
P_0c07aaca: /* original 3420, guest PC 0x0c07aaca */
if(!s->budget--) { s->failed_pc=0x0c07aacau; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07aacc;
P_0c07aacc: /* original 8b0d, guest PC 0x0c07aacc */
if(!s->budget--) { s->failed_pc=0x0c07aaccu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07aaea; }
goto P_0c07aace;
P_0c07aace: /* original 64ed, guest PC 0x0c07aace */
if(!s->budget--) { s->failed_pc=0x0c07aaceu; return 0; }
r[4]=r[14]&65535u;
goto P_0c07aad0;
P_0c07aad0: /* original d00d, guest PC 0x0c07aad0 */
if(!s->budget--) { s->failed_pc=0x0c07aad0u; return 0; }
r[0]=read(ram,0x0c07ab08u,4);
goto P_0c07aad2;
P_0c07aad2: /* original d30f, guest PC 0x0c07aad2 */
if(!s->budget--) { s->failed_pc=0x0c07aad2u; return 0; }
r[3]=read(ram,0x0c07ab10u,4);
goto P_0c07aad4;
P_0c07aad4: /* original 74f8, guest PC 0x0c07aad4 */
if(!s->budget--) { s->failed_pc=0x0c07aad4u; return 0; }
r[4]+=0xfffffff8u;
goto P_0c07aad6;
P_0c07aad6: /* original 65d3, guest PC 0x0c07aad6 */
if(!s->budget--) { s->failed_pc=0x0c07aad6u; return 0; }
r[5]=r[13];
goto P_0c07aad8;
P_0c07aad8: /* original 4408, guest PC 0x0c07aad8 */
if(!s->budget--) { s->failed_pc=0x0c07aad8u; return 0; }
r[4]<<=2;
goto P_0c07aada;
P_0c07aada: /* original 430b, guest PC 0x0c07aada */
if(!s->budget--) { s->failed_pc=0x0c07aadau; return 0; }
target=r[3];
r[16]=code_base|0x0c07aadeu;
r[4]=read(ram,r[4]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07aadeu) { target=s->pc; goto dispatch; }
goto P_0c07aade;
P_0c07aadc: /* original 044e, guest PC 0x0c07aadc */
if(!s->budget--) { s->failed_pc=0x0c07aadcu; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c07aade;
P_0c07aade: /* original 4f26, guest PC 0x0c07aade */
if(!s->budget--) { s->failed_pc=0x0c07aadeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aae0;
P_0c07aae0: /* original 65d3, guest PC 0x0c07aae0 */
if(!s->budget--) { s->failed_pc=0x0c07aae0u; return 0; }
r[5]=r[13];
goto P_0c07aae2;
P_0c07aae2: /* original 64e3, guest PC 0x0c07aae2 */
if(!s->budget--) { s->failed_pc=0x0c07aae2u; return 0; }
r[4]=r[14];
goto P_0c07aae4;
P_0c07aae4: /* original 6df6, guest PC 0x0c07aae4 */
if(!s->budget--) { s->failed_pc=0x0c07aae4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aae6;
P_0c07aae6: /* original aead, guest PC 0x0c07aae6 */
if(!s->budget--) { s->failed_pc=0x0c07aae6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07a844u,s,ram);
P_0c07aae8: /* original 6ef6, guest PC 0x0c07aae8 */
if(!s->budget--) { s->failed_pc=0x0c07aae8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07aaea;
P_0c07aaea: /* original 4f26, guest PC 0x0c07aaea */
if(!s->budget--) { s->failed_pc=0x0c07aaeau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07aaec;
P_0c07aaec: /* original 6df6, guest PC 0x0c07aaec */
if(!s->budget--) { s->failed_pc=0x0c07aaecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07aaee;
P_0c07aaee: /* original 000b, guest PC 0x0c07aaee */
if(!s->budget--) { s->failed_pc=0x0c07aaeeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07aaf0: /* original 6ef6, guest PC 0x0c07aaf0 */
if(!s->budget--) { s->failed_pc=0x0c07aaf0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07aaf2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07aaf2u; return 0; } return 1;
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
P_0c07b204: /* original 2fe6, guest PC 0x0c07b204 */
if(!s->budget--) { s->failed_pc=0x0c07b204u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b206;
P_0c07b206: /* original e400, guest PC 0x0c07b206 */
if(!s->budget--) { s->failed_pc=0x0c07b206u; return 0; }
r[4]=0x00000000u;
goto P_0c07b208;
P_0c07b208: /* original 2fd6, guest PC 0x0c07b208 */
if(!s->budget--) { s->failed_pc=0x0c07b208u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b20a;
P_0c07b20a: /* original e654, guest PC 0x0c07b20a */
if(!s->budget--) { s->failed_pc=0x0c07b20au; return 0; }
r[6]=0x00000054u;
goto P_0c07b20c;
P_0c07b20c: /* original 2fc6, guest PC 0x0c07b20c */
if(!s->budget--) { s->failed_pc=0x0c07b20cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b20e;
P_0c07b20e: /* original 2fb6, guest PC 0x0c07b20e */
if(!s->budget--) { s->failed_pc=0x0c07b20eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b210;
P_0c07b210: /* original eb00, guest PC 0x0c07b210 */
if(!s->budget--) { s->failed_pc=0x0c07b210u; return 0; }
r[11]=0x00000000u;
goto P_0c07b212;
P_0c07b212: /* original 2fa6, guest PC 0x0c07b212 */
if(!s->budget--) { s->failed_pc=0x0c07b212u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b214;
P_0c07b214: /* original 65b3, guest PC 0x0c07b214 */
if(!s->budget--) { s->failed_pc=0x0c07b214u; return 0; }
r[5]=r[11];
goto P_0c07b216;
P_0c07b216: /* original 4f22, guest PC 0x0c07b216 */
if(!s->budget--) { s->failed_pc=0x0c07b216u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b218;
P_0c07b218: /* original d348, guest PC 0x0c07b218 */
if(!s->budget--) { s->failed_pc=0x0c07b218u; return 0; }
r[3]=read(ram,0x0c07b33cu,4);
goto P_0c07b21a;
P_0c07b21a: /* original d249, guest PC 0x0c07b21a */
if(!s->budget--) { s->failed_pc=0x0c07b21au; return 0; }
r[2]=read(ram,0x0c07b340u,4);
goto P_0c07b21c;
P_0c07b21c: /* original 6e32, guest PC 0x0c07b21c */
if(!s->budget--) { s->failed_pc=0x0c07b21cu; return 0; }
tmp=read(ram,r[3],4);
r[14]=tmp;
goto P_0c07b21e;
P_0c07b21e: /* original 7ffc, guest PC 0x0c07b21e */
if(!s->budget--) { s->failed_pc=0x0c07b21eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b220;
P_0c07b220: /* original 2f22, guest PC 0x0c07b220 */
if(!s->budget--) { s->failed_pc=0x0c07b220u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07b222;
P_0c07b222: /* original dd48, guest PC 0x0c07b222 */
if(!s->budget--) { s->failed_pc=0x0c07b222u; return 0; }
r[13]=read(ram,0x0c07b344u,4);
goto P_0c07b224;
P_0c07b224: /* original 34dc, guest PC 0x0c07b224 */
if(!s->budget--) { s->failed_pc=0x0c07b224u; return 0; }
r[4]+=r[13];
goto P_0c07b226;
P_0c07b226: /* original 7501, guest PC 0x0c07b226 */
if(!s->budget--) { s->failed_pc=0x0c07b226u; return 0; }
r[5]+=0x00000001u;
goto P_0c07b228;
P_0c07b228: /* original 24b1, guest PC 0x0c07b228 */
if(!s->budget--) { s->failed_pc=0x0c07b228u; return 0; }
write(ram,r[4],r[11],2);
goto P_0c07b22a;
P_0c07b22a: /* original 3563, guest PC 0x0c07b22a */
if(!s->budget--) { s->failed_pc=0x0c07b22au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=(int32_t)r[6])!=0);
goto P_0c07b22c;
P_0c07b22c: /* original 8ffb, guest PC 0x0c07b22c */
if(!s->budget--) { s->failed_pc=0x0c07b22cu; return 0; }
cond=r[17]&1u;
r[4]+=0x00000002u;
if(!cond) { goto P_0c07b226; }
goto P_0c07b230;
P_0c07b22e: /* original 7402, guest PC 0x0c07b22e */
if(!s->budget--) { s->failed_pc=0x0c07b22eu; return 0; }
r[4]+=0x00000002u;
goto P_0c07b230;
P_0c07b230: /* original d245, guest PC 0x0c07b230 */
if(!s->budget--) { s->failed_pc=0x0c07b230u; return 0; }
r[2]=read(ram,0x0c07b348u,4);
goto P_0c07b232;
P_0c07b232: /* original 65e3, guest PC 0x0c07b232 */
if(!s->budget--) { s->failed_pc=0x0c07b232u; return 0; }
r[5]=r[14];
goto P_0c07b234;
P_0c07b234: /* original 420b, guest PC 0x0c07b234 */
if(!s->budget--) { s->failed_pc=0x0c07b234u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b238u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b238u) { target=s->pc; goto dispatch; }
goto P_0c07b238;
P_0c07b236: /* original e401, guest PC 0x0c07b236 */
if(!s->budget--) { s->failed_pc=0x0c07b236u; return 0; }
r[4]=0x00000001u;
goto P_0c07b238;
P_0c07b238: /* original dc44, guest PC 0x0c07b238 */
if(!s->budget--) { s->failed_pc=0x0c07b238u; return 0; }
r[12]=read(ram,0x0c07b34cu,4);
goto P_0c07b23a;
P_0c07b23a: /* original 4c0b, guest PC 0x0c07b23a */
if(!s->budget--) { s->failed_pc=0x0c07b23au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b23eu;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b23eu) { target=s->pc; goto dispatch; }
goto P_0c07b23e;
P_0c07b23c: /* original e400, guest PC 0x0c07b23c */
if(!s->budget--) { s->failed_pc=0x0c07b23cu; return 0; }
r[4]=0x00000000u;
goto P_0c07b23e;
P_0c07b23e: /* original da44, guest PC 0x0c07b23e */
if(!s->budget--) { s->failed_pc=0x0c07b23eu; return 0; }
r[10]=read(ram,0x0c07b350u,4);
goto P_0c07b240;
P_0c07b240: /* original 65e3, guest PC 0x0c07b240 */
if(!s->budget--) { s->failed_pc=0x0c07b240u; return 0; }
r[5]=r[14];
goto P_0c07b242;
P_0c07b242: /* original bad1, guest PC 0x0c07b242 */
if(!s->budget--) { s->failed_pc=0x0c07b242u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b246u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b246u) { target=s->pc; goto dispatch; }
goto P_0c07b246;
P_0c07b244: /* original 64a3, guest PC 0x0c07b244 */
if(!s->budget--) { s->failed_pc=0x0c07b244u; return 0; }
r[4]=r[10];
goto P_0c07b246;
P_0c07b246: /* original 4c0b, guest PC 0x0c07b246 */
if(!s->budget--) { s->failed_pc=0x0c07b246u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b24au;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b24au) { target=s->pc; goto dispatch; }
goto P_0c07b24a;
P_0c07b248: /* original e401, guest PC 0x0c07b248 */
if(!s->budget--) { s->failed_pc=0x0c07b248u; return 0; }
r[4]=0x00000001u;
goto P_0c07b24a;
P_0c07b24a: /* original 64a3, guest PC 0x0c07b24a */
if(!s->budget--) { s->failed_pc=0x0c07b24au; return 0; }
r[4]=r[10];
goto P_0c07b24c;
P_0c07b24c: /* original 65e3, guest PC 0x0c07b24c */
if(!s->budget--) { s->failed_pc=0x0c07b24cu; return 0; }
r[5]=r[14];
goto P_0c07b24e;
P_0c07b24e: /* original bacb, guest PC 0x0c07b24e */
if(!s->budget--) { s->failed_pc=0x0c07b24eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b252u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b252u) { target=s->pc; goto dispatch; }
goto P_0c07b252;
P_0c07b250: /* original 7410, guest PC 0x0c07b250 */
if(!s->budget--) { s->failed_pc=0x0c07b250u; return 0; }
r[4]+=0x00000010u;
goto P_0c07b252;
P_0c07b252: /* original 4c0b, guest PC 0x0c07b252 */
if(!s->budget--) { s->failed_pc=0x0c07b252u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b256u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b256u) { target=s->pc; goto dispatch; }
goto P_0c07b256;
P_0c07b254: /* original e402, guest PC 0x0c07b254 */
if(!s->budget--) { s->failed_pc=0x0c07b254u; return 0; }
r[4]=0x00000002u;
goto P_0c07b256;
P_0c07b256: /* original 64a3, guest PC 0x0c07b256 */
if(!s->budget--) { s->failed_pc=0x0c07b256u; return 0; }
r[4]=r[10];
goto P_0c07b258;
P_0c07b258: /* original 65e3, guest PC 0x0c07b258 */
if(!s->budget--) { s->failed_pc=0x0c07b258u; return 0; }
r[5]=r[14];
goto P_0c07b25a;
P_0c07b25a: /* original bac5, guest PC 0x0c07b25a */
if(!s->budget--) { s->failed_pc=0x0c07b25au; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b25eu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b25eu) { target=s->pc; goto dispatch; }
goto P_0c07b25e;
P_0c07b25c: /* original 7420, guest PC 0x0c07b25c */
if(!s->budget--) { s->failed_pc=0x0c07b25cu; return 0; }
r[4]+=0x00000020u;
goto P_0c07b25e;
P_0c07b25e: /* original 4c0b, guest PC 0x0c07b25e */
if(!s->budget--) { s->failed_pc=0x0c07b25eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b262u;
r[4]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b262u) { target=s->pc; goto dispatch; }
goto P_0c07b262;
P_0c07b260: /* original e403, guest PC 0x0c07b260 */
if(!s->budget--) { s->failed_pc=0x0c07b260u; return 0; }
r[4]=0x00000003u;
goto P_0c07b262;
P_0c07b262: /* original 64a3, guest PC 0x0c07b262 */
if(!s->budget--) { s->failed_pc=0x0c07b262u; return 0; }
r[4]=r[10];
goto P_0c07b264;
P_0c07b264: /* original 65e3, guest PC 0x0c07b264 */
if(!s->budget--) { s->failed_pc=0x0c07b264u; return 0; }
r[5]=r[14];
goto P_0c07b266;
P_0c07b266: /* original babf, guest PC 0x0c07b266 */
if(!s->budget--) { s->failed_pc=0x0c07b266u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b26au;
r[4]+=0x00000030u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b26au) { target=s->pc; goto dispatch; }
goto P_0c07b26a;
P_0c07b268: /* original 7430, guest PC 0x0c07b268 */
if(!s->budget--) { s->failed_pc=0x0c07b268u; return 0; }
r[4]+=0x00000030u;
goto P_0c07b26a;
P_0c07b26a: /* original 4c0b, guest PC 0x0c07b26a */
if(!s->budget--) { s->failed_pc=0x0c07b26au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b26eu;
r[4]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b26eu) { target=s->pc; goto dispatch; }
goto P_0c07b26e;
P_0c07b26c: /* original e404, guest PC 0x0c07b26c */
if(!s->budget--) { s->failed_pc=0x0c07b26cu; return 0; }
r[4]=0x00000004u;
goto P_0c07b26e;
P_0c07b26e: /* original 64a3, guest PC 0x0c07b26e */
if(!s->budget--) { s->failed_pc=0x0c07b26eu; return 0; }
r[4]=r[10];
goto P_0c07b270;
P_0c07b270: /* original 65e3, guest PC 0x0c07b270 */
if(!s->budget--) { s->failed_pc=0x0c07b270u; return 0; }
r[5]=r[14];
goto P_0c07b272;
P_0c07b272: /* original bab9, guest PC 0x0c07b272 */
if(!s->budget--) { s->failed_pc=0x0c07b272u; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b276u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b276u) { target=s->pc; goto dispatch; }
goto P_0c07b276;
P_0c07b274: /* original 7440, guest PC 0x0c07b274 */
if(!s->budget--) { s->failed_pc=0x0c07b274u; return 0; }
r[4]+=0x00000040u;
goto P_0c07b276;
P_0c07b276: /* original 4c0b, guest PC 0x0c07b276 */
if(!s->budget--) { s->failed_pc=0x0c07b276u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b27au;
r[4]=0x00000053u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b27au) { target=s->pc; goto dispatch; }
goto P_0c07b27a;
P_0c07b278: /* original e453, guest PC 0x0c07b278 */
if(!s->budget--) { s->failed_pc=0x0c07b278u; return 0; }
r[4]=0x00000053u;
goto P_0c07b27a;
P_0c07b27a: /* original 64a3, guest PC 0x0c07b27a */
if(!s->budget--) { s->failed_pc=0x0c07b27au; return 0; }
r[4]=r[10];
goto P_0c07b27c;
P_0c07b27c: /* original 65e3, guest PC 0x0c07b27c */
if(!s->budget--) { s->failed_pc=0x0c07b27cu; return 0; }
r[5]=r[14];
goto P_0c07b27e;
P_0c07b27e: /* original bab3, guest PC 0x0c07b27e */
if(!s->budget--) { s->failed_pc=0x0c07b27eu; return 0; }
target=code_base|0x0c07a7e8u; r[16]=code_base|0x0c07b282u;
r[4]+=0x00000050u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b282u) { target=s->pc; goto dispatch; }
goto P_0c07b282;
P_0c07b280: /* original 7450, guest PC 0x0c07b280 */
if(!s->budget--) { s->failed_pc=0x0c07b280u; return 0; }
r[4]+=0x00000050u;
goto P_0c07b282;
P_0c07b282: /* original e001, guest PC 0x0c07b282 */
if(!s->budget--) { s->failed_pc=0x0c07b282u; return 0; }
r[0]=0x00000001u;
goto P_0c07b284;
P_0c07b284: /* original 2db1, guest PC 0x0c07b284 */
if(!s->budget--) { s->failed_pc=0x0c07b284u; return 0; }
write(ram,r[13],r[11],2);
goto P_0c07b286;
P_0c07b286: /* original 81d1, guest PC 0x0c07b286 */
if(!s->budget--) { s->failed_pc=0x0c07b286u; return 0; }
write(ram,r[13]+2,r[0],2);
goto P_0c07b288;
P_0c07b288: /* original e002, guest PC 0x0c07b288 */
if(!s->budget--) { s->failed_pc=0x0c07b288u; return 0; }
r[0]=0x00000002u;
goto P_0c07b28a;
P_0c07b28a: /* original 81d2, guest PC 0x0c07b28a */
if(!s->budget--) { s->failed_pc=0x0c07b28au; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c07b28c;
P_0c07b28c: /* original e003, guest PC 0x0c07b28c */
if(!s->budget--) { s->failed_pc=0x0c07b28cu; return 0; }
r[0]=0x00000003u;
goto P_0c07b28e;
P_0c07b28e: /* original 81d3, guest PC 0x0c07b28e */
if(!s->budget--) { s->failed_pc=0x0c07b28eu; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c07b290;
P_0c07b290: /* original e004, guest PC 0x0c07b290 */
if(!s->budget--) { s->failed_pc=0x0c07b290u; return 0; }
r[0]=0x00000004u;
goto P_0c07b292;
P_0c07b292: /* original 81d4, guest PC 0x0c07b292 */
if(!s->budget--) { s->failed_pc=0x0c07b292u; return 0; }
write(ram,r[13]+8,r[0],2);
goto P_0c07b294;
P_0c07b294: /* original e353, guest PC 0x0c07b294 */
if(!s->budget--) { s->failed_pc=0x0c07b294u; return 0; }
r[3]=0x00000053u;
goto P_0c07b296;
P_0c07b296: /* original 904e, guest PC 0x0c07b296 */
if(!s->budget--) { s->failed_pc=0x0c07b296u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b336u,2);
goto P_0c07b298;
P_0c07b298: /* original 0d35, guest PC 0x0c07b298 */
if(!s->budget--) { s->failed_pc=0x0c07b298u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b29a;
P_0c07b29a: /* original d32e, guest PC 0x0c07b29a */
if(!s->budget--) { s->failed_pc=0x0c07b29au; return 0; }
r[3]=read(ram,0x0c07b354u,4);
goto P_0c07b29c;
P_0c07b29c: /* original 64f2, guest PC 0x0c07b29c */
if(!s->budget--) { s->failed_pc=0x0c07b29cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c07b29e;
P_0c07b29e: /* original 430b, guest PC 0x0c07b29e */
if(!s->budget--) { s->failed_pc=0x0c07b29eu; return 0; }
target=r[3];
r[16]=code_base|0x0c07b2a2u;
r[4]+=0x00000012u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b2a2u) { target=s->pc; goto dispatch; }
goto P_0c07b2a2;
P_0c07b2a0: /* original 7412, guest PC 0x0c07b2a0 */
if(!s->budget--) { s->failed_pc=0x0c07b2a0u; return 0; }
r[4]+=0x00000012u;
goto P_0c07b2a2;
P_0c07b2a2: /* original 600c, guest PC 0x0c07b2a2 */
if(!s->budget--) { s->failed_pc=0x0c07b2a2u; return 0; }
r[0]=r[0]&255u;
goto P_0c07b2a4;
P_0c07b2a4: /* original 2008, guest PC 0x0c07b2a4 */
if(!s->budget--) { s->failed_pc=0x0c07b2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b2a6;
P_0c07b2a6: /* original 8d02, guest PC 0x0c07b2a6 */
if(!s->budget--) { s->failed_pc=0x0c07b2a6u; return 0; }
cond=r[17]&1u;
r[15]+=0x00000004u;
if(cond) { goto P_0c07b2ae; }
goto P_0c07b2aa;
P_0c07b2a8: /* original 7f04, guest PC 0x0c07b2a8 */
if(!s->budget--) { s->failed_pc=0x0c07b2a8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07b2aa;
P_0c07b2aa: /* original a001, guest PC 0x0c07b2aa */
if(!s->budget--) { s->failed_pc=0x0c07b2aau; return 0; }
r[4]=0x00000008u;
goto P_0c07b2b0;
P_0c07b2ac: /* original e408, guest PC 0x0c07b2ac */
if(!s->budget--) { s->failed_pc=0x0c07b2acu; return 0; }
r[4]=0x00000008u;
goto P_0c07b2ae;
P_0c07b2ae: /* original e409, guest PC 0x0c07b2ae */
if(!s->budget--) { s->failed_pc=0x0c07b2aeu; return 0; }
r[4]=0x00000009u;
goto P_0c07b2b0;
P_0c07b2b0: /* original 4f26, guest PC 0x0c07b2b0 */
if(!s->budget--) { s->failed_pc=0x0c07b2b0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b2b2;
P_0c07b2b2: /* original 6af6, guest PC 0x0c07b2b2 */
if(!s->budget--) { s->failed_pc=0x0c07b2b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07b2b4;
P_0c07b2b4: /* original 6bf6, guest PC 0x0c07b2b4 */
if(!s->budget--) { s->failed_pc=0x0c07b2b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07b2b6;
P_0c07b2b6: /* original 6cf6, guest PC 0x0c07b2b6 */
if(!s->budget--) { s->failed_pc=0x0c07b2b6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b2b8;
P_0c07b2b8: /* original 6df6, guest PC 0x0c07b2b8 */
if(!s->budget--) { s->failed_pc=0x0c07b2b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b2ba;
P_0c07b2ba: /* original abf7, guest PC 0x0c07b2ba */
if(!s->budget--) { s->failed_pc=0x0c07b2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c07aaac;
P_0c07b2bc: /* original 6ef6, guest PC 0x0c07b2bc */
if(!s->budget--) { s->failed_pc=0x0c07b2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b2beu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b2beu; return 0; } return 1;
P_0c07b5b0: /* original 920d, guest PC 0x0c07b5b0 */
if(!s->budget--) { s->failed_pc=0x0c07b5b0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5ceu,2);
goto P_0c07b5b2;
P_0c07b5b2: /* original 634d, guest PC 0x0c07b5b2 */
if(!s->budget--) { s->failed_pc=0x0c07b5b2u; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5b4;
P_0c07b5b4: /* original 2328, guest PC 0x0c07b5b4 */
if(!s->budget--) { s->failed_pc=0x0c07b5b4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c07b5b6;
P_0c07b5b6: /* original 8908, guest PC 0x0c07b5b6 */
if(!s->budget--) { s->failed_pc=0x0c07b5b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b5ca; }
goto P_0c07b5b8;
P_0c07b5b8: /* original 900a, guest PC 0x0c07b5b8 */
if(!s->budget--) { s->failed_pc=0x0c07b5b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b5d0u,2);
goto P_0c07b5ba;
P_0c07b5ba: /* original 2409, guest PC 0x0c07b5ba */
if(!s->budget--) { s->failed_pc=0x0c07b5bau; return 0; }
r[4]&=r[0];
goto P_0c07b5bc;
P_0c07b5bc: /* original d005, guest PC 0x0c07b5bc */
if(!s->budget--) { s->failed_pc=0x0c07b5bcu; return 0; }
r[0]=read(ram,0x0c07b5d4u,4);
goto P_0c07b5be;
P_0c07b5be: /* original 634d, guest PC 0x0c07b5be */
if(!s->budget--) { s->failed_pc=0x0c07b5beu; return 0; }
r[3]=r[4]&65535u;
goto P_0c07b5c0;
P_0c07b5c0: /* original 6133, guest PC 0x0c07b5c0 */
if(!s->budget--) { s->failed_pc=0x0c07b5c0u; return 0; }
r[1]=r[3];
goto P_0c07b5c2;
P_0c07b5c2: /* original 4108, guest PC 0x0c07b5c2 */
if(!s->budget--) { s->failed_pc=0x0c07b5c2u; return 0; }
r[1]<<=2;
goto P_0c07b5c4;
P_0c07b5c4: /* original 4300, guest PC 0x0c07b5c4 */
if(!s->budget--) { s->failed_pc=0x0c07b5c4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07b5c6;
P_0c07b5c6: /* original 331c, guest PC 0x0c07b5c6 */
if(!s->budget--) { s->failed_pc=0x0c07b5c6u; return 0; }
r[3]+=r[1];
goto P_0c07b5c8;
P_0c07b5c8: /* original 043d, guest PC 0x0c07b5c8 */
if(!s->budget--) { s->failed_pc=0x0c07b5c8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07b5ca;
P_0c07b5ca: /* original 000b, guest PC 0x0c07b5ca */
if(!s->budget--) { s->failed_pc=0x0c07b5cau; return 0; }
target=r[16];
r[0]=r[4];
s->pc=target; return ram->oob==0;
P_0c07b5cc: /* original 6043, guest PC 0x0c07b5cc */
if(!s->budget--) { s->failed_pc=0x0c07b5ccu; return 0; }
r[0]=r[4];
if(!vf3_matrix_family(0x0c07b5ceu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b5ceu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
