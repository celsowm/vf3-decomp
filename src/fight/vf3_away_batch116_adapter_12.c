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
int vf3_away_batch116_adapter_12(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c05f0b8u: goto P_0c05f0b8;
case 0x0c05f0bau: goto P_0c05f0ba;
case 0x0c05f0bcu: goto P_0c05f0bc;
case 0x0c05f0beu: goto P_0c05f0be;
case 0x0c05f0c0u: goto P_0c05f0c0;
case 0x0c05f0c2u: goto P_0c05f0c2;
case 0x0c05f0c4u: goto P_0c05f0c4;
case 0x0c05f0c6u: goto P_0c05f0c6;
case 0x0c05f0c8u: goto P_0c05f0c8;
case 0x0c05f0cau: goto P_0c05f0ca;
case 0x0c05f0ccu: goto P_0c05f0cc;
case 0x0c05f0ceu: goto P_0c05f0ce;
case 0x0c05f0d0u: goto P_0c05f0d0;
case 0x0c05f0d2u: goto P_0c05f0d2;
case 0x0c05f0d4u: goto P_0c05f0d4;
case 0x0c05f0d6u: goto P_0c05f0d6;
case 0x0c05f0d8u: goto P_0c05f0d8;
case 0x0c05f0dau: goto P_0c05f0da;
case 0x0c05f0dcu: goto P_0c05f0dc;
case 0x0c05f0deu: goto P_0c05f0de;
case 0x0c05f0e0u: goto P_0c05f0e0;
case 0x0c05f0e2u: goto P_0c05f0e2;
case 0x0c05f0e4u: goto P_0c05f0e4;
case 0x0c05f0e6u: goto P_0c05f0e6;
case 0x0c05f0e8u: goto P_0c05f0e8;
case 0x0c05f0eau: goto P_0c05f0ea;
case 0x0c05f0ecu: goto P_0c05f0ec;
case 0x0c05f0eeu: goto P_0c05f0ee;
case 0x0c05f0f0u: goto P_0c05f0f0;
case 0x0c05f0f2u: goto P_0c05f0f2;
case 0x0c05f0f4u: goto P_0c05f0f4;
case 0x0c05f0f6u: goto P_0c05f0f6;
case 0x0c05f0f8u: goto P_0c05f0f8;
case 0x0c05f0fau: goto P_0c05f0fa;
case 0x0c05f0fcu: goto P_0c05f0fc;
case 0x0c05f0feu: goto P_0c05f0fe;
case 0x0c05f100u: goto P_0c05f100;
case 0x0c05f102u: goto P_0c05f102;
case 0x0c05f104u: goto P_0c05f104;
case 0x0c05f106u: goto P_0c05f106;
case 0x0c05f108u: goto P_0c05f108;
case 0x0c05f10au: goto P_0c05f10a;
case 0x0c05f10cu: goto P_0c05f10c;
case 0x0c05f10eu: goto P_0c05f10e;
case 0x0c05f110u: goto P_0c05f110;
case 0x0c05f112u: goto P_0c05f112;
case 0x0c05f114u: goto P_0c05f114;
case 0x0c05f116u: goto P_0c05f116;
case 0x0c05f118u: goto P_0c05f118;
case 0x0c05f11au: goto P_0c05f11a;
case 0x0c05f11cu: goto P_0c05f11c;
case 0x0c05f11eu: goto P_0c05f11e;
case 0x0c05f120u: goto P_0c05f120;
case 0x0c05f122u: goto P_0c05f122;
case 0x0c05f124u: goto P_0c05f124;
case 0x0c05f126u: goto P_0c05f126;
case 0x0c05f128u: goto P_0c05f128;
case 0x0c05f12au: goto P_0c05f12a;
case 0x0c05f12cu: goto P_0c05f12c;
case 0x0c05f12eu: goto P_0c05f12e;
case 0x0c05f130u: goto P_0c05f130;
case 0x0c05f132u: goto P_0c05f132;
case 0x0c05f134u: goto P_0c05f134;
case 0x0c05f136u: goto P_0c05f136;
case 0x0c05f138u: goto P_0c05f138;
case 0x0c05f13au: goto P_0c05f13a;
case 0x0c05f13cu: goto P_0c05f13c;
case 0x0c05f13eu: goto P_0c05f13e;
case 0x0c05f140u: goto P_0c05f140;
case 0x0c05f142u: goto P_0c05f142;
case 0x0c05f144u: goto P_0c05f144;
case 0x0c05f146u: goto P_0c05f146;
case 0x0c05f148u: goto P_0c05f148;
case 0x0c05f14au: goto P_0c05f14a;
case 0x0c05f14cu: goto P_0c05f14c;
case 0x0c05f14eu: goto P_0c05f14e;
case 0x0c05f150u: goto P_0c05f150;
case 0x0c05f152u: goto P_0c05f152;
case 0x0c05f154u: goto P_0c05f154;
case 0x0c05f156u: goto P_0c05f156;
case 0x0c05f158u: goto P_0c05f158;
case 0x0c05f15au: goto P_0c05f15a;
case 0x0c05f15cu: goto P_0c05f15c;
case 0x0c05f15eu: goto P_0c05f15e;
case 0x0c05f160u: goto P_0c05f160;
case 0x0c05f162u: goto P_0c05f162;
case 0x0c05f164u: goto P_0c05f164;
case 0x0c05f166u: goto P_0c05f166;
case 0x0c05f168u: goto P_0c05f168;
case 0x0c05f16au: goto P_0c05f16a;
case 0x0c05f16cu: goto P_0c05f16c;
case 0x0c05f16eu: goto P_0c05f16e;
case 0x0c05f170u: goto P_0c05f170;
case 0x0c05f172u: goto P_0c05f172;
case 0x0c05f174u: goto P_0c05f174;
case 0x0c05f176u: goto P_0c05f176;
case 0x0c05f178u: goto P_0c05f178;
case 0x0c05f17au: goto P_0c05f17a;
case 0x0c05f17cu: goto P_0c05f17c;
case 0x0c05f17eu: goto P_0c05f17e;
case 0x0c05f180u: goto P_0c05f180;
case 0x0c05f18au: goto P_0c05f18a;
case 0x0c05f18cu: goto P_0c05f18c;
case 0x0c05f18eu: goto P_0c05f18e;
case 0x0c05f190u: goto P_0c05f190;
case 0x0c05f192u: goto P_0c05f192;
case 0x0c05f194u: goto P_0c05f194;
case 0x0c05f196u: goto P_0c05f196;
case 0x0c05f198u: goto P_0c05f198;
case 0x0c05f19au: goto P_0c05f19a;
case 0x0c05f19cu: goto P_0c05f19c;
case 0x0c05f19eu: goto P_0c05f19e;
case 0x0c05f1a0u: goto P_0c05f1a0;
case 0x0c05f1a2u: goto P_0c05f1a2;
case 0x0c05f1a4u: goto P_0c05f1a4;
case 0x0c05f1a6u: goto P_0c05f1a6;
case 0x0c05f1a8u: goto P_0c05f1a8;
case 0x0c05f1aau: goto P_0c05f1aa;
case 0x0c05f1acu: goto P_0c05f1ac;
case 0x0c05f1aeu: goto P_0c05f1ae;
case 0x0c05f1b0u: goto P_0c05f1b0;
case 0x0c05f1b2u: goto P_0c05f1b2;
case 0x0c05f1b4u: goto P_0c05f1b4;
case 0x0c05f1b6u: goto P_0c05f1b6;
case 0x0c05f1b8u: goto P_0c05f1b8;
case 0x0c05f1bau: goto P_0c05f1ba;
case 0x0c05f1bcu: goto P_0c05f1bc;
case 0x0c05f1beu: goto P_0c05f1be;
case 0x0c05f1c0u: goto P_0c05f1c0;
case 0x0c05f1c2u: goto P_0c05f1c2;
case 0x0c05f1c4u: goto P_0c05f1c4;
case 0x0c05f1c6u: goto P_0c05f1c6;
case 0x0c05f1c8u: goto P_0c05f1c8;
case 0x0c05f1cau: goto P_0c05f1ca;
case 0x0c05f1ccu: goto P_0c05f1cc;
case 0x0c05f1ceu: goto P_0c05f1ce;
case 0x0c05f1d0u: goto P_0c05f1d0;
case 0x0c05f1d2u: goto P_0c05f1d2;
case 0x0c05f1d4u: goto P_0c05f1d4;
case 0x0c05f1d6u: goto P_0c05f1d6;
case 0x0c05f1d8u: goto P_0c05f1d8;
case 0x0c05f1dau: goto P_0c05f1da;
case 0x0c05f1dcu: goto P_0c05f1dc;
case 0x0c05f1deu: goto P_0c05f1de;
case 0x0c05f1e0u: goto P_0c05f1e0;
case 0x0c05f1e2u: goto P_0c05f1e2;
case 0x0c05f1e4u: goto P_0c05f1e4;
case 0x0c05f1e6u: goto P_0c05f1e6;
case 0x0c05f1e8u: goto P_0c05f1e8;
case 0x0c05f1eau: goto P_0c05f1ea;
case 0x0c05f1ecu: goto P_0c05f1ec;
case 0x0c05f1eeu: goto P_0c05f1ee;
case 0x0c05f1f0u: goto P_0c05f1f0;
case 0x0c05f1f2u: goto P_0c05f1f2;
case 0x0c05f1f4u: goto P_0c05f1f4;
case 0x0c05f1f6u: goto P_0c05f1f6;
case 0x0c05f1f8u: goto P_0c05f1f8;
case 0x0c05f1fau: goto P_0c05f1fa;
case 0x0c05f1fcu: goto P_0c05f1fc;
case 0x0c05f1feu: goto P_0c05f1fe;
case 0x0c05f200u: goto P_0c05f200;
case 0x0c05f202u: goto P_0c05f202;
case 0x0c05f204u: goto P_0c05f204;
case 0x0c05f206u: goto P_0c05f206;
case 0x0c05f208u: goto P_0c05f208;
case 0x0c05f20au: goto P_0c05f20a;
case 0x0c05f20cu: goto P_0c05f20c;
case 0x0c05f20eu: goto P_0c05f20e;
case 0x0c05f210u: goto P_0c05f210;
case 0x0c05f212u: goto P_0c05f212;
case 0x0c05f214u: goto P_0c05f214;
case 0x0c05f216u: goto P_0c05f216;
case 0x0c05f218u: goto P_0c05f218;
case 0x0c05f21au: goto P_0c05f21a;
case 0x0c05f21cu: goto P_0c05f21c;
case 0x0c05f21eu: goto P_0c05f21e;
case 0x0c05f220u: goto P_0c05f220;
case 0x0c05f222u: goto P_0c05f222;
case 0x0c05f224u: goto P_0c05f224;
case 0x0c05f226u: goto P_0c05f226;
case 0x0c05f228u: goto P_0c05f228;
case 0x0c05f22au: goto P_0c05f22a;
case 0x0c05f22cu: goto P_0c05f22c;
case 0x0c05f22eu: goto P_0c05f22e;
case 0x0c05f230u: goto P_0c05f230;
case 0x0c05f232u: goto P_0c05f232;
case 0x0c05f234u: goto P_0c05f234;
case 0x0c05f236u: goto P_0c05f236;
case 0x0c05f238u: goto P_0c05f238;
case 0x0c05f23au: goto P_0c05f23a;
case 0x0c05f23cu: goto P_0c05f23c;
case 0x0c05f23eu: goto P_0c05f23e;
case 0x0c05f240u: goto P_0c05f240;
case 0x0c05f242u: goto P_0c05f242;
case 0x0c05f244u: goto P_0c05f244;
case 0x0c05f246u: goto P_0c05f246;
case 0x0c05f248u: goto P_0c05f248;
case 0x0c05f24au: goto P_0c05f24a;
case 0x0c05f24cu: goto P_0c05f24c;
case 0x0c05f24eu: goto P_0c05f24e;
case 0x0c05f250u: goto P_0c05f250;
case 0x0c05f252u: goto P_0c05f252;
case 0x0c05f254u: goto P_0c05f254;
case 0x0c05f256u: goto P_0c05f256;
case 0x0c05f258u: goto P_0c05f258;
case 0x0c05f25cu: goto P_0c05f25c;
case 0x0c05f25eu: goto P_0c05f25e;
case 0x0c05f260u: goto P_0c05f260;
case 0x0c05f262u: goto P_0c05f262;
case 0x0c05f264u: goto P_0c05f264;
case 0x0c05f266u: goto P_0c05f266;
case 0x0c05f268u: goto P_0c05f268;
case 0x0c05f26au: goto P_0c05f26a;
case 0x0c05f26cu: goto P_0c05f26c;
case 0x0c05f26eu: goto P_0c05f26e;
case 0x0c05f270u: goto P_0c05f270;
case 0x0c05f272u: goto P_0c05f272;
case 0x0c05f274u: goto P_0c05f274;
case 0x0c05f276u: goto P_0c05f276;
case 0x0c05f278u: goto P_0c05f278;
case 0x0c05f27au: goto P_0c05f27a;
case 0x0c05f27cu: goto P_0c05f27c;
case 0x0c05f27eu: goto P_0c05f27e;
case 0x0c05f280u: goto P_0c05f280;
case 0x0c05f282u: goto P_0c05f282;
case 0x0c05f284u: goto P_0c05f284;
case 0x0c05f286u: goto P_0c05f286;
case 0x0c05f288u: goto P_0c05f288;
default: return vf3_matrix_family(target,s,ram);
}
P_0c05f0b8: /* original 3453, guest PC 0x0c05f0b8 */
if(!s->budget--) { s->failed_pc=0x0c05f0b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[5])!=0);
goto P_0c05f0ba;
P_0c05f0ba: /* original 8b00, guest PC 0x0c05f0ba */
if(!s->budget--) { s->failed_pc=0x0c05f0bau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f0be; }
goto P_0c05f0bc;
P_0c05f0bc: /* original 6453, guest PC 0x0c05f0bc */
if(!s->budget--) { s->failed_pc=0x0c05f0bcu; return 0; }
r[4]=r[5];
goto P_0c05f0be;
P_0c05f0be: /* original 6043, guest PC 0x0c05f0be */
if(!s->budget--) { s->failed_pc=0x0c05f0beu; return 0; }
r[0]=r[4];
goto P_0c05f0c0;
P_0c05f0c0: /* original 0009, guest PC 0x0c05f0c0 */
if(!s->budget--) { s->failed_pc=0x0c05f0c0u; return 0; }
goto P_0c05f0c2;
P_0c05f0c2: /* original 8801, guest PC 0x0c05f0c2 */
if(!s->budget--) { s->failed_pc=0x0c05f0c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05f0c4;
P_0c05f0c4: /* original 8919, guest PC 0x0c05f0c4 */
if(!s->budget--) { s->failed_pc=0x0c05f0c4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f0fa; }
goto P_0c05f0c6;
P_0c05f0c6: /* original 8802, guest PC 0x0c05f0c6 */
if(!s->budget--) { s->failed_pc=0x0c05f0c6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c05f0c8;
P_0c05f0c8: /* original 8919, guest PC 0x0c05f0c8 */
if(!s->budget--) { s->failed_pc=0x0c05f0c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f0fe; }
goto P_0c05f0ca;
P_0c05f0ca: /* original 8804, guest PC 0x0c05f0ca */
if(!s->budget--) { s->failed_pc=0x0c05f0cau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c05f0cc;
P_0c05f0cc: /* original 8919, guest PC 0x0c05f0cc */
if(!s->budget--) { s->failed_pc=0x0c05f0ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f102; }
goto P_0c05f0ce;
P_0c05f0ce: /* original 8808, guest PC 0x0c05f0ce */
if(!s->budget--) { s->failed_pc=0x0c05f0ceu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05f0d0;
P_0c05f0d0: /* original 8927, guest PC 0x0c05f0d0 */
if(!s->budget--) { s->failed_pc=0x0c05f0d0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f122; }
goto P_0c05f0d2;
P_0c05f0d2: /* original 8810, guest PC 0x0c05f0d2 */
if(!s->budget--) { s->failed_pc=0x0c05f0d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000010u)!=0);
goto P_0c05f0d4;
P_0c05f0d4: /* original 8917, guest PC 0x0c05f0d4 */
if(!s->budget--) { s->failed_pc=0x0c05f0d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f106; }
goto P_0c05f0d6;
P_0c05f0d6: /* original 8820, guest PC 0x0c05f0d6 */
if(!s->budget--) { s->failed_pc=0x0c05f0d6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000020u)!=0);
goto P_0c05f0d8;
P_0c05f0d8: /* original 8917, guest PC 0x0c05f0d8 */
if(!s->budget--) { s->failed_pc=0x0c05f0d8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f10a; }
goto P_0c05f0da;
P_0c05f0da: /* original 8840, guest PC 0x0c05f0da */
if(!s->budget--) { s->failed_pc=0x0c05f0dau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000040u)!=0);
goto P_0c05f0dc;
P_0c05f0dc: /* original 8917, guest PC 0x0c05f0dc */
if(!s->budget--) { s->failed_pc=0x0c05f0dcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f10e; }
goto P_0c05f0de;
P_0c05f0de: /* original 9150, guest PC 0x0c05f0de */
if(!s->budget--) { s->failed_pc=0x0c05f0deu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f182u,2);
goto P_0c05f0e0;
P_0c05f0e0: /* original 3010, guest PC 0x0c05f0e0 */
if(!s->budget--) { s->failed_pc=0x0c05f0e0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05f0e2;
P_0c05f0e2: /* original 8916, guest PC 0x0c05f0e2 */
if(!s->budget--) { s->failed_pc=0x0c05f0e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f112; }
goto P_0c05f0e4;
P_0c05f0e4: /* original 914e, guest PC 0x0c05f0e4 */
if(!s->budget--) { s->failed_pc=0x0c05f0e4u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f184u,2);
goto P_0c05f0e6;
P_0c05f0e6: /* original 3010, guest PC 0x0c05f0e6 */
if(!s->budget--) { s->failed_pc=0x0c05f0e6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05f0e8;
P_0c05f0e8: /* original 8915, guest PC 0x0c05f0e8 */
if(!s->budget--) { s->failed_pc=0x0c05f0e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f116; }
goto P_0c05f0ea;
P_0c05f0ea: /* original 914c, guest PC 0x0c05f0ea */
if(!s->budget--) { s->failed_pc=0x0c05f0eau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f186u,2);
goto P_0c05f0ec;
P_0c05f0ec: /* original 3010, guest PC 0x0c05f0ec */
if(!s->budget--) { s->failed_pc=0x0c05f0ecu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05f0ee;
P_0c05f0ee: /* original 8914, guest PC 0x0c05f0ee */
if(!s->budget--) { s->failed_pc=0x0c05f0eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f11a; }
goto P_0c05f0f0;
P_0c05f0f0: /* original 914a, guest PC 0x0c05f0f0 */
if(!s->budget--) { s->failed_pc=0x0c05f0f0u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f188u,2);
goto P_0c05f0f2;
P_0c05f0f2: /* original 3010, guest PC 0x0c05f0f2 */
if(!s->budget--) { s->failed_pc=0x0c05f0f2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==r[1])!=0);
goto P_0c05f0f4;
P_0c05f0f4: /* original 8913, guest PC 0x0c05f0f4 */
if(!s->budget--) { s->failed_pc=0x0c05f0f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f11e; }
goto P_0c05f0f6;
P_0c05f0f6: /* original a014, guest PC 0x0c05f0f6 */
if(!s->budget--) { s->failed_pc=0x0c05f0f6u; return 0; }
goto P_0c05f122;
P_0c05f0f8: /* original 0009, guest PC 0x0c05f0f8 */
if(!s->budget--) { s->failed_pc=0x0c05f0f8u; return 0; }
goto P_0c05f0fa;
P_0c05f0fa: /* original 000b, guest PC 0x0c05f0fa */
if(!s->budget--) { s->failed_pc=0x0c05f0fau; return 0; }
target=r[16];
r[0]=0x00000000u;
s->pc=target; return ram->oob==0;
P_0c05f0fc: /* original e000, guest PC 0x0c05f0fc */
if(!s->budget--) { s->failed_pc=0x0c05f0fcu; return 0; }
r[0]=0x00000000u;
goto P_0c05f0fe;
P_0c05f0fe: /* original 000b, guest PC 0x0c05f0fe */
if(!s->budget--) { s->failed_pc=0x0c05f0feu; return 0; }
target=r[16];
r[0]=0x00000001u;
s->pc=target; return ram->oob==0;
P_0c05f100: /* original e001, guest PC 0x0c05f100 */
if(!s->budget--) { s->failed_pc=0x0c05f100u; return 0; }
r[0]=0x00000001u;
goto P_0c05f102;
P_0c05f102: /* original 000b, guest PC 0x0c05f102 */
if(!s->budget--) { s->failed_pc=0x0c05f102u; return 0; }
target=r[16];
r[0]=0x00000002u;
s->pc=target; return ram->oob==0;
P_0c05f104: /* original e002, guest PC 0x0c05f104 */
if(!s->budget--) { s->failed_pc=0x0c05f104u; return 0; }
r[0]=0x00000002u;
goto P_0c05f106;
P_0c05f106: /* original 000b, guest PC 0x0c05f106 */
if(!s->budget--) { s->failed_pc=0x0c05f106u; return 0; }
target=r[16];
r[0]=0x00000004u;
s->pc=target; return ram->oob==0;
P_0c05f108: /* original e004, guest PC 0x0c05f108 */
if(!s->budget--) { s->failed_pc=0x0c05f108u; return 0; }
r[0]=0x00000004u;
goto P_0c05f10a;
P_0c05f10a: /* original 000b, guest PC 0x0c05f10a */
if(!s->budget--) { s->failed_pc=0x0c05f10au; return 0; }
target=r[16];
r[0]=0x00000005u;
s->pc=target; return ram->oob==0;
P_0c05f10c: /* original e005, guest PC 0x0c05f10c */
if(!s->budget--) { s->failed_pc=0x0c05f10cu; return 0; }
r[0]=0x00000005u;
goto P_0c05f10e;
P_0c05f10e: /* original 000b, guest PC 0x0c05f10e */
if(!s->budget--) { s->failed_pc=0x0c05f10eu; return 0; }
target=r[16];
r[0]=0x00000006u;
s->pc=target; return ram->oob==0;
P_0c05f110: /* original e006, guest PC 0x0c05f110 */
if(!s->budget--) { s->failed_pc=0x0c05f110u; return 0; }
r[0]=0x00000006u;
goto P_0c05f112;
P_0c05f112: /* original 000b, guest PC 0x0c05f112 */
if(!s->budget--) { s->failed_pc=0x0c05f112u; return 0; }
target=r[16];
r[0]=0x00000007u;
s->pc=target; return ram->oob==0;
P_0c05f114: /* original e007, guest PC 0x0c05f114 */
if(!s->budget--) { s->failed_pc=0x0c05f114u; return 0; }
r[0]=0x00000007u;
goto P_0c05f116;
P_0c05f116: /* original 000b, guest PC 0x0c05f116 */
if(!s->budget--) { s->failed_pc=0x0c05f116u; return 0; }
target=r[16];
r[0]=0x00000008u;
s->pc=target; return ram->oob==0;
P_0c05f118: /* original e008, guest PC 0x0c05f118 */
if(!s->budget--) { s->failed_pc=0x0c05f118u; return 0; }
r[0]=0x00000008u;
goto P_0c05f11a;
P_0c05f11a: /* original 000b, guest PC 0x0c05f11a */
if(!s->budget--) { s->failed_pc=0x0c05f11au; return 0; }
target=r[16];
r[0]=0x00000009u;
s->pc=target; return ram->oob==0;
P_0c05f11c: /* original e009, guest PC 0x0c05f11c */
if(!s->budget--) { s->failed_pc=0x0c05f11cu; return 0; }
r[0]=0x00000009u;
goto P_0c05f11e;
P_0c05f11e: /* original 000b, guest PC 0x0c05f11e */
if(!s->budget--) { s->failed_pc=0x0c05f11eu; return 0; }
target=r[16];
r[0]=0x0000000au;
s->pc=target; return ram->oob==0;
P_0c05f120: /* original e00a, guest PC 0x0c05f120 */
if(!s->budget--) { s->failed_pc=0x0c05f120u; return 0; }
r[0]=0x0000000au;
goto P_0c05f122;
P_0c05f122: /* original e003, guest PC 0x0c05f122 */
if(!s->budget--) { s->failed_pc=0x0c05f122u; return 0; }
r[0]=0x00000003u;
goto P_0c05f124;
P_0c05f124: /* original 000b, guest PC 0x0c05f124 */
if(!s->budget--) { s->failed_pc=0x0c05f124u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c05f126: /* original 0009, guest PC 0x0c05f126 */
if(!s->budget--) { s->failed_pc=0x0c05f126u; return 0; }
goto P_0c05f128;
P_0c05f128: /* original 2fe6, guest PC 0x0c05f128 */
if(!s->budget--) { s->failed_pc=0x0c05f128u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c05f12a;
P_0c05f12a: /* original 6e43, guest PC 0x0c05f12a */
if(!s->budget--) { s->failed_pc=0x0c05f12au; return 0; }
r[14]=r[4];
goto P_0c05f12c;
P_0c05f12c: /* original 4f22, guest PC 0x0c05f12c */
if(!s->budget--) { s->failed_pc=0x0c05f12cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c05f12e;
P_0c05f12e: /* original 60e2, guest PC 0x0c05f12e */
if(!s->budget--) { s->failed_pc=0x0c05f12eu; return 0; }
tmp=read(ram,r[14],4);
r[0]=tmp;
goto P_0c05f130;
P_0c05f130: /* original 600d, guest PC 0x0c05f130 */
if(!s->budget--) { s->failed_pc=0x0c05f130u; return 0; }
r[0]=r[0]&65535u;
goto P_0c05f132;
P_0c05f132: /* original 8803, guest PC 0x0c05f132 */
if(!s->budget--) { s->failed_pc=0x0c05f132u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c05f134;
P_0c05f134: /* original 8b03, guest PC 0x0c05f134 */
if(!s->budget--) { s->failed_pc=0x0c05f134u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f13e; }
goto P_0c05f136;
P_0c05f136: /* original b0a8, guest PC 0x0c05f136 */
if(!s->budget--) { s->failed_pc=0x0c05f136u; return 0; }
target=code_base|0x0c05f28au; r[16]=code_base|0x0c05f13au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f13au) { target=s->pc; goto dispatch; }
goto P_0c05f13a;
P_0c05f138: /* original 64e3, guest PC 0x0c05f138 */
if(!s->budget--) { s->failed_pc=0x0c05f138u; return 0; }
r[4]=r[14];
goto P_0c05f13a;
P_0c05f13a: /* original a005, guest PC 0x0c05f13a */
if(!s->budget--) { s->failed_pc=0x0c05f13au; return 0; }
goto P_0c05f148;
P_0c05f13c: /* original 0009, guest PC 0x0c05f13c */
if(!s->budget--) { s->failed_pc=0x0c05f13cu; return 0; }
goto P_0c05f13e;
P_0c05f13e: /* original 50e6, guest PC 0x0c05f13e */
if(!s->budget--) { s->failed_pc=0x0c05f13eu; return 0; }
r[0]=read(ram,r[14]+24,4);
goto P_0c05f140;
P_0c05f140: /* original c808, guest PC 0x0c05f140 */
if(!s->budget--) { s->failed_pc=0x0c05f140u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c05f142;
P_0c05f142: /* original 8903, guest PC 0x0c05f142 */
if(!s->budget--) { s->failed_pc=0x0c05f142u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f14c; }
goto P_0c05f144;
P_0c05f144: /* original b03c, guest PC 0x0c05f144 */
if(!s->budget--) { s->failed_pc=0x0c05f144u; return 0; }
target=code_base|0x0c05f1c0u; r[16]=code_base|0x0c05f148u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f148u) { target=s->pc; goto dispatch; }
goto P_0c05f148;
P_0c05f146: /* original 64e3, guest PC 0x0c05f146 */
if(!s->budget--) { s->failed_pc=0x0c05f146u; return 0; }
r[4]=r[14];
goto P_0c05f148;
P_0c05f148: /* original a009, guest PC 0x0c05f148 */
if(!s->budget--) { s->failed_pc=0x0c05f148u; return 0; }
r[4]=r[0];
goto P_0c05f15e;
P_0c05f14a: /* original 6403, guest PC 0x0c05f14a */
if(!s->budget--) { s->failed_pc=0x0c05f14au; return 0; }
r[4]=r[0];
goto P_0c05f14c;
P_0c05f14c: /* original c820, guest PC 0x0c05f14c */
if(!s->budget--) { s->failed_pc=0x0c05f14cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05f14e;
P_0c05f14e: /* original 8903, guest PC 0x0c05f14e */
if(!s->budget--) { s->failed_pc=0x0c05f14eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f158; }
goto P_0c05f150;
P_0c05f150: /* original b065, guest PC 0x0c05f150 */
if(!s->budget--) { s->failed_pc=0x0c05f150u; return 0; }
target=code_base|0x0c05f21eu; r[16]=code_base|0x0c05f154u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f154u) { target=s->pc; goto dispatch; }
goto P_0c05f154;
P_0c05f152: /* original 64e3, guest PC 0x0c05f152 */
if(!s->budget--) { s->failed_pc=0x0c05f152u; return 0; }
r[4]=r[14];
goto P_0c05f154;
P_0c05f154: /* original a002, guest PC 0x0c05f154 */
if(!s->budget--) { s->failed_pc=0x0c05f154u; return 0; }
goto P_0c05f15c;
P_0c05f156: /* original 0009, guest PC 0x0c05f156 */
if(!s->budget--) { s->failed_pc=0x0c05f156u; return 0; }
goto P_0c05f158;
P_0c05f158: /* original b005, guest PC 0x0c05f158 */
if(!s->budget--) { s->failed_pc=0x0c05f158u; return 0; }
target=code_base|0x0c05f166u; r[16]=code_base|0x0c05f15cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05f15cu) { target=s->pc; goto dispatch; }
goto P_0c05f15c;
P_0c05f15a: /* original 64e3, guest PC 0x0c05f15a */
if(!s->budget--) { s->failed_pc=0x0c05f15au; return 0; }
r[4]=r[14];
goto P_0c05f15c;
P_0c05f15c: /* original 6403, guest PC 0x0c05f15c */
if(!s->budget--) { s->failed_pc=0x0c05f15cu; return 0; }
r[4]=r[0];
goto P_0c05f15e;
P_0c05f15e: /* original 1e45, guest PC 0x0c05f15e */
if(!s->budget--) { s->failed_pc=0x0c05f15eu; return 0; }
write(ram,r[14]+20,r[4],4);
goto P_0c05f160;
P_0c05f160: /* original 4f26, guest PC 0x0c05f160 */
if(!s->budget--) { s->failed_pc=0x0c05f160u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05f162;
P_0c05f162: /* original 000b, guest PC 0x0c05f162 */
if(!s->budget--) { s->failed_pc=0x0c05f162u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05f164: /* original 6ef6, guest PC 0x0c05f164 */
if(!s->budget--) { s->failed_pc=0x0c05f164u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c05f166;
P_0c05f166: /* original e101, guest PC 0x0c05f166 */
if(!s->budget--) { s->failed_pc=0x0c05f166u; return 0; }
r[1]=0x00000001u;
goto P_0c05f168;
P_0c05f168: /* original 5346, guest PC 0x0c05f168 */
if(!s->budget--) { s->failed_pc=0x0c05f168u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c05f16a;
P_0c05f16a: /* original 5643, guest PC 0x0c05f16a */
if(!s->budget--) { s->failed_pc=0x0c05f16au; return 0; }
r[6]=read(ram,r[4]+12,4);
goto P_0c05f16c;
P_0c05f16c: /* original 5544, guest PC 0x0c05f16c */
if(!s->budget--) { s->failed_pc=0x0c05f16cu; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c05f16e;
P_0c05f16e: /* original 2318, guest PC 0x0c05f16e */
if(!s->budget--) { s->failed_pc=0x0c05f16eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c05f170;
P_0c05f170: /* original 0657, guest PC 0x0c05f170 */
if(!s->budget--) { s->failed_pc=0x0c05f170u; return 0; }
r[19]=r[6]*r[5];
goto P_0c05f172;
P_0c05f172: /* original 8d1d, guest PC 0x0c05f172 */
if(!s->budget--) { s->failed_pc=0x0c05f172u; return 0; }
cond=r[17]&1u;
r[7]=r[19];
if(cond) { goto P_0c05f1b0; }
goto P_0c05f176;
P_0c05f174: /* original 071a, guest PC 0x0c05f174 */
if(!s->budget--) { s->failed_pc=0x0c05f174u; return 0; }
r[7]=r[19];
goto P_0c05f176;
P_0c05f176: /* original 4601, guest PC 0x0c05f176 */
if(!s->budget--) { s->failed_pc=0x0c05f176u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f178;
P_0c05f178: /* original 4501, guest PC 0x0c05f178 */
if(!s->budget--) { s->failed_pc=0x0c05f178u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f17a;
P_0c05f17a: /* original 3652, guest PC 0x0c05f17a */
if(!s->budget--) { s->failed_pc=0x0c05f17au; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[5])!=0);
goto P_0c05f17c;
P_0c05f17c: /* original 8905, guest PC 0x0c05f17c */
if(!s->budget--) { s->failed_pc=0x0c05f17cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f18a; }
goto P_0c05f17e;
P_0c05f17e: /* original a006, guest PC 0x0c05f17e */
if(!s->budget--) { s->failed_pc=0x0c05f17eu; return 0; }
r[0]=r[6];
goto P_0c05f18e;
P_0c05f180: /* original 6063, guest PC 0x0c05f180 */
if(!s->budget--) { s->failed_pc=0x0c05f180u; return 0; }
r[0]=r[6];
if(!vf3_matrix_family(0x0c05f182u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f182u; return 0; } return 1;
P_0c05f18a: /* original 6053, guest PC 0x0c05f18a */
if(!s->budget--) { s->failed_pc=0x0c05f18au; return 0; }
r[0]=r[5];
goto P_0c05f18c;
P_0c05f18c: /* original 0009, guest PC 0x0c05f18c */
if(!s->budget--) { s->failed_pc=0x0c05f18cu; return 0; }
goto P_0c05f18e;
P_0c05f18e: /* original 3016, guest PC 0x0c05f18e */
if(!s->budget--) { s->failed_pc=0x0c05f18eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[1])!=0);
goto P_0c05f190;
P_0c05f190: /* original 8b07, guest PC 0x0c05f190 */
if(!s->budget--) { s->failed_pc=0x0c05f190u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f1a2; }
goto P_0c05f192;
P_0c05f192: /* original 0657, guest PC 0x0c05f192 */
if(!s->budget--) { s->failed_pc=0x0c05f192u; return 0; }
r[19]=r[6]*r[5];
goto P_0c05f194;
P_0c05f194: /* original 031a, guest PC 0x0c05f194 */
if(!s->budget--) { s->failed_pc=0x0c05f194u; return 0; }
r[3]=r[19];
goto P_0c05f196;
P_0c05f196: /* original 4601, guest PC 0x0c05f196 */
if(!s->budget--) { s->failed_pc=0x0c05f196u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f198;
P_0c05f198: /* original 4501, guest PC 0x0c05f198 */
if(!s->budget--) { s->failed_pc=0x0c05f198u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f19a;
P_0c05f19a: /* original 4001, guest PC 0x0c05f19a */
if(!s->budget--) { s->failed_pc=0x0c05f19au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05f19c;
P_0c05f19c: /* original 3016, guest PC 0x0c05f19c */
if(!s->budget--) { s->failed_pc=0x0c05f19cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[1])!=0);
goto P_0c05f19e;
P_0c05f19e: /* original 8df8, guest PC 0x0c05f19e */
if(!s->budget--) { s->failed_pc=0x0c05f19eu; return 0; }
cond=r[17]&1u;
r[7]+=r[3];
if(cond) { goto P_0c05f192; }
goto P_0c05f1a2;
P_0c05f1a0: /* original 373c, guest PC 0x0c05f1a0 */
if(!s->budget--) { s->failed_pc=0x0c05f1a0u; return 0; }
r[7]+=r[3];
goto P_0c05f1a2;
P_0c05f1a2: /* original 3650, guest PC 0x0c05f1a2 */
if(!s->budget--) { s->failed_pc=0x0c05f1a2u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c05f1a4;
P_0c05f1a4: /* original 8b01, guest PC 0x0c05f1a4 */
if(!s->budget--) { s->failed_pc=0x0c05f1a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f1aa; }
goto P_0c05f1a6;
P_0c05f1a6: /* original a003, guest PC 0x0c05f1a6 */
if(!s->budget--) { s->failed_pc=0x0c05f1a6u; return 0; }
r[7]+=0x00000004u;
goto P_0c05f1b0;
P_0c05f1a8: /* original 7704, guest PC 0x0c05f1a8 */
if(!s->budget--) { s->failed_pc=0x0c05f1a8u; return 0; }
r[7]+=0x00000004u;
goto P_0c05f1aa;
P_0c05f1aa: /* original 0657, guest PC 0x0c05f1aa */
if(!s->budget--) { s->failed_pc=0x0c05f1aau; return 0; }
r[19]=r[6]*r[5];
goto P_0c05f1ac;
P_0c05f1ac: /* original 061a, guest PC 0x0c05f1ac */
if(!s->budget--) { s->failed_pc=0x0c05f1acu; return 0; }
r[6]=r[19];
goto P_0c05f1ae;
P_0c05f1ae: /* original 376c, guest PC 0x0c05f1ae */
if(!s->budget--) { s->failed_pc=0x0c05f1aeu; return 0; }
r[7]+=r[6];
goto P_0c05f1b0;
P_0c05f1b0: /* original 5041, guest PC 0x0c05f1b0 */
if(!s->budget--) { s->failed_pc=0x0c05f1b0u; return 0; }
r[0]=read(ram,r[4]+4,4);
goto P_0c05f1b2;
P_0c05f1b2: /* original 8801, guest PC 0x0c05f1b2 */
if(!s->budget--) { s->failed_pc=0x0c05f1b2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05f1b4;
P_0c05f1b4: /* original 8b01, guest PC 0x0c05f1b4 */
if(!s->budget--) { s->failed_pc=0x0c05f1b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f1ba; }
goto P_0c05f1b6;
P_0c05f1b6: /* original a001, guest PC 0x0c05f1b6 */
if(!s->budget--) { s->failed_pc=0x0c05f1b6u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c05f1bc;
P_0c05f1b8: /* original 4700, guest PC 0x0c05f1b8 */
if(!s->budget--) { s->failed_pc=0x0c05f1b8u; return 0; }
r[17]=(r[17]&~1u)|((r[7]>>31)!=0);
r[7]<<=1;
goto P_0c05f1ba;
P_0c05f1ba: /* original 4708, guest PC 0x0c05f1ba */
if(!s->budget--) { s->failed_pc=0x0c05f1bau; return 0; }
r[7]<<=2;
goto P_0c05f1bc;
P_0c05f1bc: /* original 000b, guest PC 0x0c05f1bc */
if(!s->budget--) { s->failed_pc=0x0c05f1bcu; return 0; }
target=r[16];
r[0]=r[7];
s->pc=target; return ram->oob==0;
P_0c05f1be: /* original 6073, guest PC 0x0c05f1be */
if(!s->budget--) { s->failed_pc=0x0c05f1beu; return 0; }
r[0]=r[7];
goto P_0c05f1c0;
P_0c05f1c0: /* original 5643, guest PC 0x0c05f1c0 */
if(!s->budget--) { s->failed_pc=0x0c05f1c0u; return 0; }
r[6]=read(ram,r[4]+12,4);
goto P_0c05f1c2;
P_0c05f1c2: /* original e001, guest PC 0x0c05f1c2 */
if(!s->budget--) { s->failed_pc=0x0c05f1c2u; return 0; }
r[0]=0x00000001u;
goto P_0c05f1c4;
P_0c05f1c4: /* original 5346, guest PC 0x0c05f1c4 */
if(!s->budget--) { s->failed_pc=0x0c05f1c4u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c05f1c6;
P_0c05f1c6: /* original 4601, guest PC 0x0c05f1c6 */
if(!s->budget--) { s->failed_pc=0x0c05f1c6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f1c8;
P_0c05f1c8: /* original 5544, guest PC 0x0c05f1c8 */
if(!s->budget--) { s->failed_pc=0x0c05f1c8u; return 0; }
r[5]=read(ram,r[4]+16,4);
goto P_0c05f1ca;
P_0c05f1ca: /* original 4501, guest PC 0x0c05f1ca */
if(!s->budget--) { s->failed_pc=0x0c05f1cau; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f1cc;
P_0c05f1cc: /* original 0657, guest PC 0x0c05f1cc */
if(!s->budget--) { s->failed_pc=0x0c05f1ccu; return 0; }
r[19]=r[6]*r[5];
goto P_0c05f1ce;
P_0c05f1ce: /* original 2308, guest PC 0x0c05f1ce */
if(!s->budget--) { s->failed_pc=0x0c05f1ceu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[0])==0)!=0);
goto P_0c05f1d0;
P_0c05f1d0: /* original 8d1a, guest PC 0x0c05f1d0 */
if(!s->budget--) { s->failed_pc=0x0c05f1d0u; return 0; }
cond=r[17]&1u;
r[7]=r[19];
if(cond) { goto P_0c05f208; }
goto P_0c05f1d4;
P_0c05f1d2: /* original 071a, guest PC 0x0c05f1d2 */
if(!s->budget--) { s->failed_pc=0x0c05f1d2u; return 0; }
r[7]=r[19];
goto P_0c05f1d4;
P_0c05f1d4: /* original 4601, guest PC 0x0c05f1d4 */
if(!s->budget--) { s->failed_pc=0x0c05f1d4u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f1d6;
P_0c05f1d6: /* original 4501, guest PC 0x0c05f1d6 */
if(!s->budget--) { s->failed_pc=0x0c05f1d6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f1d8;
P_0c05f1d8: /* original 3652, guest PC 0x0c05f1d8 */
if(!s->budget--) { s->failed_pc=0x0c05f1d8u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[5])!=0);
goto P_0c05f1da;
P_0c05f1da: /* original 8901, guest PC 0x0c05f1da */
if(!s->budget--) { s->failed_pc=0x0c05f1dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f1e0; }
goto P_0c05f1dc;
P_0c05f1dc: /* original a001, guest PC 0x0c05f1dc */
if(!s->budget--) { s->failed_pc=0x0c05f1dcu; return 0; }
r[4]=r[6];
goto P_0c05f1e2;
P_0c05f1de: /* original 6463, guest PC 0x0c05f1de */
if(!s->budget--) { s->failed_pc=0x0c05f1deu; return 0; }
r[4]=r[6];
goto P_0c05f1e0;
P_0c05f1e0: /* original 6453, guest PC 0x0c05f1e0 */
if(!s->budget--) { s->failed_pc=0x0c05f1e0u; return 0; }
r[4]=r[5];
goto P_0c05f1e2;
P_0c05f1e2: /* original 3406, guest PC 0x0c05f1e2 */
if(!s->budget--) { s->failed_pc=0x0c05f1e2u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[0])!=0);
goto P_0c05f1e4;
P_0c05f1e4: /* original 8b07, guest PC 0x0c05f1e4 */
if(!s->budget--) { s->failed_pc=0x0c05f1e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f1f6; }
goto P_0c05f1e6;
P_0c05f1e6: /* original 0657, guest PC 0x0c05f1e6 */
if(!s->budget--) { s->failed_pc=0x0c05f1e6u; return 0; }
r[19]=r[6]*r[5];
goto P_0c05f1e8;
P_0c05f1e8: /* original 031a, guest PC 0x0c05f1e8 */
if(!s->budget--) { s->failed_pc=0x0c05f1e8u; return 0; }
r[3]=r[19];
goto P_0c05f1ea;
P_0c05f1ea: /* original 4601, guest PC 0x0c05f1ea */
if(!s->budget--) { s->failed_pc=0x0c05f1eau; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f1ec;
P_0c05f1ec: /* original 4501, guest PC 0x0c05f1ec */
if(!s->budget--) { s->failed_pc=0x0c05f1ecu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f1ee;
P_0c05f1ee: /* original 4401, guest PC 0x0c05f1ee */
if(!s->budget--) { s->failed_pc=0x0c05f1eeu; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]>>=1;
goto P_0c05f1f0;
P_0c05f1f0: /* original 3406, guest PC 0x0c05f1f0 */
if(!s->budget--) { s->failed_pc=0x0c05f1f0u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[0])!=0);
goto P_0c05f1f2;
P_0c05f1f2: /* original 8df8, guest PC 0x0c05f1f2 */
if(!s->budget--) { s->failed_pc=0x0c05f1f2u; return 0; }
cond=r[17]&1u;
r[7]+=r[3];
if(cond) { goto P_0c05f1e6; }
goto P_0c05f1f6;
P_0c05f1f4: /* original 373c, guest PC 0x0c05f1f4 */
if(!s->budget--) { s->failed_pc=0x0c05f1f4u; return 0; }
r[7]+=r[3];
goto P_0c05f1f6;
P_0c05f1f6: /* original 3650, guest PC 0x0c05f1f6 */
if(!s->budget--) { s->failed_pc=0x0c05f1f6u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[5])!=0);
goto P_0c05f1f8;
P_0c05f1f8: /* original 8b01, guest PC 0x0c05f1f8 */
if(!s->budget--) { s->failed_pc=0x0c05f1f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f1fe; }
goto P_0c05f1fa;
P_0c05f1fa: /* original a003, guest PC 0x0c05f1fa */
if(!s->budget--) { s->failed_pc=0x0c05f1fau; return 0; }
r[7]+=0x00000002u;
goto P_0c05f204;
P_0c05f1fc: /* original 7702, guest PC 0x0c05f1fc */
if(!s->budget--) { s->failed_pc=0x0c05f1fcu; return 0; }
r[7]+=0x00000002u;
goto P_0c05f1fe;
P_0c05f1fe: /* original 0657, guest PC 0x0c05f1fe */
if(!s->budget--) { s->failed_pc=0x0c05f1feu; return 0; }
r[19]=r[6]*r[5];
goto P_0c05f200;
P_0c05f200: /* original 061a, guest PC 0x0c05f200 */
if(!s->budget--) { s->failed_pc=0x0c05f200u; return 0; }
r[6]=r[19];
goto P_0c05f202;
P_0c05f202: /* original 376c, guest PC 0x0c05f202 */
if(!s->budget--) { s->failed_pc=0x0c05f202u; return 0; }
r[7]+=r[6];
goto P_0c05f204;
P_0c05f204: /* original a007, guest PC 0x0c05f204 */
if(!s->budget--) { s->failed_pc=0x0c05f204u; return 0; }
r[7]+=0x0000000au;
goto P_0c05f216;
P_0c05f206: /* original 770a, guest PC 0x0c05f206 */
if(!s->budget--) { s->failed_pc=0x0c05f206u; return 0; }
r[7]+=0x0000000au;
goto P_0c05f208;
P_0c05f208: /* original 5043, guest PC 0x0c05f208 */
if(!s->budget--) { s->failed_pc=0x0c05f208u; return 0; }
r[0]=read(ram,r[4]+12,4);
goto P_0c05f20a;
P_0c05f20a: /* original 8808, guest PC 0x0c05f20a */
if(!s->budget--) { s->failed_pc=0x0c05f20au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05f20c;
P_0c05f20c: /* original 8b03, guest PC 0x0c05f20c */
if(!s->budget--) { s->failed_pc=0x0c05f20cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f216; }
goto P_0c05f20e;
P_0c05f20e: /* original 5044, guest PC 0x0c05f20e */
if(!s->budget--) { s->failed_pc=0x0c05f20eu; return 0; }
r[0]=read(ram,r[4]+16,4);
goto P_0c05f210;
P_0c05f210: /* original 8808, guest PC 0x0c05f210 */
if(!s->budget--) { s->failed_pc=0x0c05f210u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c05f212;
P_0c05f212: /* original 8b00, guest PC 0x0c05f212 */
if(!s->budget--) { s->failed_pc=0x0c05f212u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f216; }
goto P_0c05f214;
P_0c05f214: /* original 7710, guest PC 0x0c05f214 */
if(!s->budget--) { s->failed_pc=0x0c05f214u; return 0; }
r[7]+=0x00000010u;
goto P_0c05f216;
P_0c05f216: /* original 9220, guest PC 0x0c05f216 */
if(!s->budget--) { s->failed_pc=0x0c05f216u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c05f25au,2);
goto P_0c05f218;
P_0c05f218: /* original 372c, guest PC 0x0c05f218 */
if(!s->budget--) { s->failed_pc=0x0c05f218u; return 0; }
r[7]+=r[2];
goto P_0c05f21a;
P_0c05f21a: /* original 000b, guest PC 0x0c05f21a */
if(!s->budget--) { s->failed_pc=0x0c05f21au; return 0; }
target=r[16];
r[0]=r[7];
s->pc=target; return ram->oob==0;
P_0c05f21c: /* original 6073, guest PC 0x0c05f21c */
if(!s->budget--) { s->failed_pc=0x0c05f21cu; return 0; }
r[0]=r[7];
goto P_0c05f21e;
P_0c05f21e: /* original e101, guest PC 0x0c05f21e */
if(!s->budget--) { s->failed_pc=0x0c05f21eu; return 0; }
r[1]=0x00000001u;
goto P_0c05f220;
P_0c05f220: /* original 5346, guest PC 0x0c05f220 */
if(!s->budget--) { s->failed_pc=0x0c05f220u; return 0; }
r[3]=read(ram,r[4]+24,4);
goto P_0c05f222;
P_0c05f222: /* original 5643, guest PC 0x0c05f222 */
if(!s->budget--) { s->failed_pc=0x0c05f222u; return 0; }
r[6]=read(ram,r[4]+12,4);
goto P_0c05f224;
P_0c05f224: /* original 5744, guest PC 0x0c05f224 */
if(!s->budget--) { s->failed_pc=0x0c05f224u; return 0; }
r[7]=read(ram,r[4]+16,4);
goto P_0c05f226;
P_0c05f226: /* original 2318, guest PC 0x0c05f226 */
if(!s->budget--) { s->failed_pc=0x0c05f226u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c05f228;
P_0c05f228: /* original 0677, guest PC 0x0c05f228 */
if(!s->budget--) { s->failed_pc=0x0c05f228u; return 0; }
r[19]=r[6]*r[7];
goto P_0c05f22a;
P_0c05f22a: /* original 8d21, guest PC 0x0c05f22a */
if(!s->budget--) { s->failed_pc=0x0c05f22au; return 0; }
cond=r[17]&1u;
r[5]=r[19];
if(cond) { goto P_0c05f270; }
goto P_0c05f22e;
P_0c05f22c: /* original 051a, guest PC 0x0c05f22c */
if(!s->budget--) { s->failed_pc=0x0c05f22cu; return 0; }
r[5]=r[19];
goto P_0c05f22e;
P_0c05f22e: /* original 4601, guest PC 0x0c05f22e */
if(!s->budget--) { s->failed_pc=0x0c05f22eu; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f230;
P_0c05f230: /* original 4701, guest PC 0x0c05f230 */
if(!s->budget--) { s->failed_pc=0x0c05f230u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]>>=1;
goto P_0c05f232;
P_0c05f232: /* original 3672, guest PC 0x0c05f232 */
if(!s->budget--) { s->failed_pc=0x0c05f232u; return 0; }
r[17]=(r[17]&~1u)|((r[6]>=r[7])!=0);
goto P_0c05f234;
P_0c05f234: /* original 8901, guest PC 0x0c05f234 */
if(!s->budget--) { s->failed_pc=0x0c05f234u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05f23a; }
goto P_0c05f236;
P_0c05f236: /* original a002, guest PC 0x0c05f236 */
if(!s->budget--) { s->failed_pc=0x0c05f236u; return 0; }
r[0]=r[6];
goto P_0c05f23e;
P_0c05f238: /* original 6063, guest PC 0x0c05f238 */
if(!s->budget--) { s->failed_pc=0x0c05f238u; return 0; }
r[0]=r[6];
goto P_0c05f23a;
P_0c05f23a: /* original 6073, guest PC 0x0c05f23a */
if(!s->budget--) { s->failed_pc=0x0c05f23au; return 0; }
r[0]=r[7];
goto P_0c05f23c;
P_0c05f23c: /* original 0009, guest PC 0x0c05f23c */
if(!s->budget--) { s->failed_pc=0x0c05f23cu; return 0; }
goto P_0c05f23e;
P_0c05f23e: /* original 3016, guest PC 0x0c05f23e */
if(!s->budget--) { s->failed_pc=0x0c05f23eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[1])!=0);
goto P_0c05f240;
P_0c05f240: /* original 8b07, guest PC 0x0c05f240 */
if(!s->budget--) { s->failed_pc=0x0c05f240u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f252; }
goto P_0c05f242;
P_0c05f242: /* original 0677, guest PC 0x0c05f242 */
if(!s->budget--) { s->failed_pc=0x0c05f242u; return 0; }
r[19]=r[6]*r[7];
goto P_0c05f244;
P_0c05f244: /* original 031a, guest PC 0x0c05f244 */
if(!s->budget--) { s->failed_pc=0x0c05f244u; return 0; }
r[3]=r[19];
goto P_0c05f246;
P_0c05f246: /* original 4601, guest PC 0x0c05f246 */
if(!s->budget--) { s->failed_pc=0x0c05f246u; return 0; }
r[17]=(r[17]&~1u)|((r[6]&1)!=0);
r[6]>>=1;
goto P_0c05f248;
P_0c05f248: /* original 4701, guest PC 0x0c05f248 */
if(!s->budget--) { s->failed_pc=0x0c05f248u; return 0; }
r[17]=(r[17]&~1u)|((r[7]&1)!=0);
r[7]>>=1;
goto P_0c05f24a;
P_0c05f24a: /* original 4001, guest PC 0x0c05f24a */
if(!s->budget--) { s->failed_pc=0x0c05f24au; return 0; }
r[17]=(r[17]&~1u)|((r[0]&1)!=0);
r[0]>>=1;
goto P_0c05f24c;
P_0c05f24c: /* original 3016, guest PC 0x0c05f24c */
if(!s->budget--) { s->failed_pc=0x0c05f24cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>r[1])!=0);
goto P_0c05f24e;
P_0c05f24e: /* original 8df8, guest PC 0x0c05f24e */
if(!s->budget--) { s->failed_pc=0x0c05f24eu; return 0; }
cond=r[17]&1u;
r[5]+=r[3];
if(cond) { goto P_0c05f242; }
goto P_0c05f252;
P_0c05f250: /* original 353c, guest PC 0x0c05f250 */
if(!s->budget--) { s->failed_pc=0x0c05f250u; return 0; }
r[5]+=r[3];
goto P_0c05f252;
P_0c05f252: /* original 3670, guest PC 0x0c05f252 */
if(!s->budget--) { s->failed_pc=0x0c05f252u; return 0; }
r[17]=(r[17]&~1u)|((r[6]==r[7])!=0);
goto P_0c05f254;
P_0c05f254: /* original 8b02, guest PC 0x0c05f254 */
if(!s->budget--) { s->failed_pc=0x0c05f254u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f25c; }
goto P_0c05f256;
P_0c05f256: /* original a004, guest PC 0x0c05f256 */
if(!s->budget--) { s->failed_pc=0x0c05f256u; return 0; }
r[5]+=0x00000001u;
goto P_0c05f262;
P_0c05f258: /* original 7501, guest PC 0x0c05f258 */
if(!s->budget--) { s->failed_pc=0x0c05f258u; return 0; }
r[5]+=0x00000001u;
if(!vf3_matrix_family(0x0c05f25au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05f25au; return 0; } return 1;
P_0c05f25c: /* original 0677, guest PC 0x0c05f25c */
if(!s->budget--) { s->failed_pc=0x0c05f25cu; return 0; }
r[19]=r[6]*r[7];
goto P_0c05f25e;
P_0c05f25e: /* original 061a, guest PC 0x0c05f25e */
if(!s->budget--) { s->failed_pc=0x0c05f25eu; return 0; }
r[6]=r[19];
goto P_0c05f260;
P_0c05f260: /* original 356c, guest PC 0x0c05f260 */
if(!s->budget--) { s->failed_pc=0x0c05f260u; return 0; }
r[5]+=r[6];
goto P_0c05f262;
P_0c05f262: /* original d34c, guest PC 0x0c05f262 */
if(!s->budget--) { s->failed_pc=0x0c05f262u; return 0; }
r[3]=read(ram,0x0c05f394u,4);
goto P_0c05f264;
P_0c05f264: /* original 5242, guest PC 0x0c05f264 */
if(!s->budget--) { s->failed_pc=0x0c05f264u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c05f266;
P_0c05f266: /* original 3230, guest PC 0x0c05f266 */
if(!s->budget--) { s->failed_pc=0x0c05f266u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c05f268;
P_0c05f268: /* original 8b01, guest PC 0x0c05f268 */
if(!s->budget--) { s->failed_pc=0x0c05f268u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f26e; }
goto P_0c05f26a;
P_0c05f26a: /* original a001, guest PC 0x0c05f26a */
if(!s->budget--) { s->failed_pc=0x0c05f26au; return 0; }
r[5]+=0x0000002bu;
goto P_0c05f270;
P_0c05f26c: /* original 752b, guest PC 0x0c05f26c */
if(!s->budget--) { s->failed_pc=0x0c05f26cu; return 0; }
r[5]+=0x0000002bu;
goto P_0c05f26e;
P_0c05f26e: /* original 750b, guest PC 0x0c05f26e */
if(!s->budget--) { s->failed_pc=0x0c05f26eu; return 0; }
r[5]+=0x0000000bu;
goto P_0c05f270;
P_0c05f270: /* original d348, guest PC 0x0c05f270 */
if(!s->budget--) { s->failed_pc=0x0c05f270u; return 0; }
r[3]=read(ram,0x0c05f394u,4);
goto P_0c05f272;
P_0c05f272: /* original 5242, guest PC 0x0c05f272 */
if(!s->budget--) { s->failed_pc=0x0c05f272u; return 0; }
r[2]=read(ram,r[4]+8,4);
goto P_0c05f274;
P_0c05f274: /* original 3230, guest PC 0x0c05f274 */
if(!s->budget--) { s->failed_pc=0x0c05f274u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c05f276;
P_0c05f276: /* original 8b06, guest PC 0x0c05f276 */
if(!s->budget--) { s->failed_pc=0x0c05f276u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f286; }
goto P_0c05f278;
P_0c05f278: /* original 6053, guest PC 0x0c05f278 */
if(!s->budget--) { s->failed_pc=0x0c05f278u; return 0; }
r[0]=r[5];
goto P_0c05f27a;
P_0c05f27a: /* original 0009, guest PC 0x0c05f27a */
if(!s->budget--) { s->failed_pc=0x0c05f27au; return 0; }
goto P_0c05f27c;
P_0c05f27c: /* original 8801, guest PC 0x0c05f27c */
if(!s->budget--) { s->failed_pc=0x0c05f27cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c05f27e;
P_0c05f27e: /* original 8b01, guest PC 0x0c05f27e */
if(!s->budget--) { s->failed_pc=0x0c05f27eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05f284; }
goto P_0c05f280;
P_0c05f280: /* original a001, guest PC 0x0c05f280 */
if(!s->budget--) { s->failed_pc=0x0c05f280u; return 0; }
r[5]=0x00000001u;
goto P_0c05f286;
P_0c05f282: /* original e501, guest PC 0x0c05f282 */
if(!s->budget--) { s->failed_pc=0x0c05f282u; return 0; }
r[5]=0x00000001u;
goto P_0c05f284;
P_0c05f284: /* original 4501, guest PC 0x0c05f284 */
if(!s->budget--) { s->failed_pc=0x0c05f284u; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]>>=1;
goto P_0c05f286;
P_0c05f286: /* original 000b, guest PC 0x0c05f286 */
if(!s->budget--) { s->failed_pc=0x0c05f286u; return 0; }
target=r[16];
r[0]=r[5];
s->pc=target; return ram->oob==0;
P_0c05f288: /* original 6053, guest PC 0x0c05f288 */
if(!s->budget--) { s->failed_pc=0x0c05f288u; return 0; }
r[0]=r[5];
return vf3_matrix_family(0x0c05f28au,s,ram);
unsupported: s->failed_pc=target; return 0;
}
