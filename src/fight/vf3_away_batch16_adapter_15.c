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
int vf3_away_batch16_adapter_15(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c08f11cu: goto P_0c08f11c;
case 0x0c08f11eu: goto P_0c08f11e;
case 0x0c08f120u: goto P_0c08f120;
case 0x0c08f122u: goto P_0c08f122;
case 0x0c08f124u: goto P_0c08f124;
case 0x0c08f126u: goto P_0c08f126;
case 0x0c08f128u: goto P_0c08f128;
case 0x0c08f12au: goto P_0c08f12a;
case 0x0c08f12cu: goto P_0c08f12c;
case 0x0c08f12eu: goto P_0c08f12e;
case 0x0c08f130u: goto P_0c08f130;
case 0x0c08f132u: goto P_0c08f132;
case 0x0c08f134u: goto P_0c08f134;
case 0x0c08f136u: goto P_0c08f136;
case 0x0c08f138u: goto P_0c08f138;
case 0x0c08f13au: goto P_0c08f13a;
case 0x0c08f13cu: goto P_0c08f13c;
case 0x0c08f13eu: goto P_0c08f13e;
case 0x0c08f140u: goto P_0c08f140;
case 0x0c08f142u: goto P_0c08f142;
case 0x0c08f144u: goto P_0c08f144;
case 0x0c08f146u: goto P_0c08f146;
case 0x0c08f148u: goto P_0c08f148;
case 0x0c08f14au: goto P_0c08f14a;
case 0x0c08f14cu: goto P_0c08f14c;
case 0x0c08f14eu: goto P_0c08f14e;
case 0x0c08f150u: goto P_0c08f150;
case 0x0c08f152u: goto P_0c08f152;
case 0x0c08f154u: goto P_0c08f154;
case 0x0c08f156u: goto P_0c08f156;
case 0x0c08f158u: goto P_0c08f158;
case 0x0c08f15au: goto P_0c08f15a;
case 0x0c08f15cu: goto P_0c08f15c;
case 0x0c08f15eu: goto P_0c08f15e;
case 0x0c08f160u: goto P_0c08f160;
case 0x0c08f162u: goto P_0c08f162;
case 0x0c08f164u: goto P_0c08f164;
case 0x0c08f166u: goto P_0c08f166;
case 0x0c08f168u: goto P_0c08f168;
case 0x0c08f16au: goto P_0c08f16a;
case 0x0c08f16cu: goto P_0c08f16c;
case 0x0c08f16eu: goto P_0c08f16e;
case 0x0c08f170u: goto P_0c08f170;
case 0x0c08f172u: goto P_0c08f172;
case 0x0c08f174u: goto P_0c08f174;
case 0x0c08f176u: goto P_0c08f176;
case 0x0c08f178u: goto P_0c08f178;
case 0x0c08f17au: goto P_0c08f17a;
case 0x0c08f17cu: goto P_0c08f17c;
case 0x0c08f17eu: goto P_0c08f17e;
case 0x0c08f180u: goto P_0c08f180;
case 0x0c08f182u: goto P_0c08f182;
case 0x0c08f184u: goto P_0c08f184;
case 0x0c08f186u: goto P_0c08f186;
case 0x0c08f188u: goto P_0c08f188;
case 0x0c08f18au: goto P_0c08f18a;
case 0x0c08f18cu: goto P_0c08f18c;
case 0x0c08f18eu: goto P_0c08f18e;
case 0x0c08f190u: goto P_0c08f190;
case 0x0c08f192u: goto P_0c08f192;
case 0x0c08f194u: goto P_0c08f194;
case 0x0c08f196u: goto P_0c08f196;
case 0x0c08f198u: goto P_0c08f198;
case 0x0c08f19au: goto P_0c08f19a;
case 0x0c08f19cu: goto P_0c08f19c;
case 0x0c08f19eu: goto P_0c08f19e;
case 0x0c08f1a0u: goto P_0c08f1a0;
case 0x0c08f1a2u: goto P_0c08f1a2;
case 0x0c08f1a4u: goto P_0c08f1a4;
case 0x0c08f1a6u: goto P_0c08f1a6;
case 0x0c08f1a8u: goto P_0c08f1a8;
case 0x0c08f1aau: goto P_0c08f1aa;
case 0x0c08f1acu: goto P_0c08f1ac;
case 0x0c08f1aeu: goto P_0c08f1ae;
case 0x0c08f1b0u: goto P_0c08f1b0;
case 0x0c08f1b2u: goto P_0c08f1b2;
case 0x0c08f1b4u: goto P_0c08f1b4;
case 0x0c08f1b6u: goto P_0c08f1b6;
case 0x0c08f1b8u: goto P_0c08f1b8;
case 0x0c08f1bau: goto P_0c08f1ba;
case 0x0c08f1bcu: goto P_0c08f1bc;
case 0x0c08f1beu: goto P_0c08f1be;
case 0x0c08f1c0u: goto P_0c08f1c0;
case 0x0c08f1c2u: goto P_0c08f1c2;
case 0x0c08f1c4u: goto P_0c08f1c4;
case 0x0c08f1c6u: goto P_0c08f1c6;
case 0x0c08f1c8u: goto P_0c08f1c8;
case 0x0c08f1cau: goto P_0c08f1ca;
case 0x0c08f1ccu: goto P_0c08f1cc;
case 0x0c08f1ceu: goto P_0c08f1ce;
case 0x0c08f1d0u: goto P_0c08f1d0;
case 0x0c08f1d2u: goto P_0c08f1d2;
case 0x0c08f1d4u: goto P_0c08f1d4;
case 0x0c08f1d6u: goto P_0c08f1d6;
case 0x0c08f1d8u: goto P_0c08f1d8;
case 0x0c08f1dau: goto P_0c08f1da;
case 0x0c08f1dcu: goto P_0c08f1dc;
case 0x0c08f1deu: goto P_0c08f1de;
case 0x0c08f1e0u: goto P_0c08f1e0;
case 0x0c08f1e2u: goto P_0c08f1e2;
case 0x0c08f1e4u: goto P_0c08f1e4;
case 0x0c08f1e6u: goto P_0c08f1e6;
case 0x0c08f1e8u: goto P_0c08f1e8;
case 0x0c08f1eau: goto P_0c08f1ea;
case 0x0c08f1ecu: goto P_0c08f1ec;
case 0x0c08f1eeu: goto P_0c08f1ee;
case 0x0c08f1f0u: goto P_0c08f1f0;
case 0x0c08f1f2u: goto P_0c08f1f2;
case 0x0c08f1f4u: goto P_0c08f1f4;
case 0x0c08f1f6u: goto P_0c08f1f6;
case 0x0c08f1f8u: goto P_0c08f1f8;
case 0x0c08f1fau: goto P_0c08f1fa;
case 0x0c08f1fcu: goto P_0c08f1fc;
case 0x0c08f1feu: goto P_0c08f1fe;
case 0x0c08f200u: goto P_0c08f200;
case 0x0c08f202u: goto P_0c08f202;
case 0x0c08f204u: goto P_0c08f204;
case 0x0c08f206u: goto P_0c08f206;
case 0x0c08f208u: goto P_0c08f208;
case 0x0c08f20au: goto P_0c08f20a;
case 0x0c08f20cu: goto P_0c08f20c;
case 0x0c08f20eu: goto P_0c08f20e;
case 0x0c08f210u: goto P_0c08f210;
case 0x0c08f212u: goto P_0c08f212;
case 0x0c08f214u: goto P_0c08f214;
case 0x0c08f216u: goto P_0c08f216;
case 0x0c08f218u: goto P_0c08f218;
case 0x0c08f21au: goto P_0c08f21a;
case 0x0c08f21cu: goto P_0c08f21c;
case 0x0c08f21eu: goto P_0c08f21e;
case 0x0c08f220u: goto P_0c08f220;
case 0x0c08f222u: goto P_0c08f222;
case 0x0c08f224u: goto P_0c08f224;
case 0x0c08f226u: goto P_0c08f226;
case 0x0c08f228u: goto P_0c08f228;
case 0x0c08f22au: goto P_0c08f22a;
case 0x0c08f22cu: goto P_0c08f22c;
case 0x0c08f22eu: goto P_0c08f22e;
case 0x0c08f230u: goto P_0c08f230;
case 0x0c08f232u: goto P_0c08f232;
case 0x0c08f234u: goto P_0c08f234;
case 0x0c08f24cu: goto P_0c08f24c;
case 0x0c08f24eu: goto P_0c08f24e;
case 0x0c08f250u: goto P_0c08f250;
case 0x0c08f252u: goto P_0c08f252;
case 0x0c08f254u: goto P_0c08f254;
case 0x0c08f256u: goto P_0c08f256;
case 0x0c08f258u: goto P_0c08f258;
case 0x0c08f25au: goto P_0c08f25a;
case 0x0c08f25cu: goto P_0c08f25c;
case 0x0c08f25eu: goto P_0c08f25e;
case 0x0c08f260u: goto P_0c08f260;
case 0x0c08f262u: goto P_0c08f262;
case 0x0c08f264u: goto P_0c08f264;
case 0x0c08f266u: goto P_0c08f266;
case 0x0c08f268u: goto P_0c08f268;
case 0x0c08f26au: goto P_0c08f26a;
case 0x0c08f26cu: goto P_0c08f26c;
case 0x0c08f26eu: goto P_0c08f26e;
case 0x0c08f270u: goto P_0c08f270;
case 0x0c08f272u: goto P_0c08f272;
case 0x0c08f274u: goto P_0c08f274;
case 0x0c08f276u: goto P_0c08f276;
case 0x0c08f278u: goto P_0c08f278;
case 0x0c08f27au: goto P_0c08f27a;
case 0x0c08f27cu: goto P_0c08f27c;
case 0x0c08f27eu: goto P_0c08f27e;
case 0x0c08f280u: goto P_0c08f280;
case 0x0c08f282u: goto P_0c08f282;
case 0x0c08f284u: goto P_0c08f284;
case 0x0c08f286u: goto P_0c08f286;
case 0x0c08f288u: goto P_0c08f288;
case 0x0c08f28au: goto P_0c08f28a;
case 0x0c08f28cu: goto P_0c08f28c;
case 0x0c08f28eu: goto P_0c08f28e;
case 0x0c08f290u: goto P_0c08f290;
case 0x0c08f292u: goto P_0c08f292;
case 0x0c08f294u: goto P_0c08f294;
case 0x0c08f296u: goto P_0c08f296;
case 0x0c08f298u: goto P_0c08f298;
case 0x0c08f29au: goto P_0c08f29a;
case 0x0c08f29cu: goto P_0c08f29c;
case 0x0c08f29eu: goto P_0c08f29e;
case 0x0c08f2a0u: goto P_0c08f2a0;
case 0x0c08f2a2u: goto P_0c08f2a2;
case 0x0c08f2a4u: goto P_0c08f2a4;
case 0x0c08f2a6u: goto P_0c08f2a6;
case 0x0c08f2a8u: goto P_0c08f2a8;
case 0x0c08f2aau: goto P_0c08f2aa;
case 0x0c08f2acu: goto P_0c08f2ac;
case 0x0c08f2aeu: goto P_0c08f2ae;
case 0x0c08f2b0u: goto P_0c08f2b0;
case 0x0c08f2b2u: goto P_0c08f2b2;
case 0x0c08f2b4u: goto P_0c08f2b4;
case 0x0c08f2b6u: goto P_0c08f2b6;
case 0x0c08f2b8u: goto P_0c08f2b8;
case 0x0c08f2bau: goto P_0c08f2ba;
case 0x0c08f2bcu: goto P_0c08f2bc;
case 0x0c08f2beu: goto P_0c08f2be;
case 0x0c08f2c0u: goto P_0c08f2c0;
case 0x0c08f2c2u: goto P_0c08f2c2;
case 0x0c08f2c4u: goto P_0c08f2c4;
case 0x0c08f2c6u: goto P_0c08f2c6;
case 0x0c08f2c8u: goto P_0c08f2c8;
case 0x0c08f2cau: goto P_0c08f2ca;
case 0x0c08f2ccu: goto P_0c08f2cc;
case 0x0c08f2ceu: goto P_0c08f2ce;
case 0x0c08f2d0u: goto P_0c08f2d0;
case 0x0c08f2d2u: goto P_0c08f2d2;
case 0x0c08f2d4u: goto P_0c08f2d4;
case 0x0c08f2d6u: goto P_0c08f2d6;
case 0x0c08f2d8u: goto P_0c08f2d8;
case 0x0c08f2dau: goto P_0c08f2da;
case 0x0c08f2dcu: goto P_0c08f2dc;
case 0x0c08f2deu: goto P_0c08f2de;
case 0x0c08f2e0u: goto P_0c08f2e0;
case 0x0c08f2e2u: goto P_0c08f2e2;
case 0x0c08f2e4u: goto P_0c08f2e4;
case 0x0c08f2e6u: goto P_0c08f2e6;
case 0x0c08f2e8u: goto P_0c08f2e8;
case 0x0c08f2eau: goto P_0c08f2ea;
case 0x0c08f2ecu: goto P_0c08f2ec;
case 0x0c08f2eeu: goto P_0c08f2ee;
case 0x0c08f2f0u: goto P_0c08f2f0;
case 0x0c08f2f2u: goto P_0c08f2f2;
case 0x0c08f2f4u: goto P_0c08f2f4;
case 0x0c08f2f6u: goto P_0c08f2f6;
case 0x0c08f2f8u: goto P_0c08f2f8;
case 0x0c08f2fau: goto P_0c08f2fa;
case 0x0c08f2fcu: goto P_0c08f2fc;
case 0x0c08f2feu: goto P_0c08f2fe;
case 0x0c08f300u: goto P_0c08f300;
case 0x0c08f302u: goto P_0c08f302;
case 0x0c08f304u: goto P_0c08f304;
case 0x0c08f306u: goto P_0c08f306;
case 0x0c08f308u: goto P_0c08f308;
case 0x0c08f30au: goto P_0c08f30a;
case 0x0c08f30cu: goto P_0c08f30c;
case 0x0c08f30eu: goto P_0c08f30e;
case 0x0c08f310u: goto P_0c08f310;
case 0x0c08f312u: goto P_0c08f312;
case 0x0c08f314u: goto P_0c08f314;
case 0x0c08f316u: goto P_0c08f316;
case 0x0c08f318u: goto P_0c08f318;
case 0x0c08f31au: goto P_0c08f31a;
case 0x0c08f31cu: goto P_0c08f31c;
case 0x0c08f31eu: goto P_0c08f31e;
case 0x0c08f320u: goto P_0c08f320;
case 0x0c08f322u: goto P_0c08f322;
case 0x0c08f324u: goto P_0c08f324;
case 0x0c08f326u: goto P_0c08f326;
case 0x0c08f328u: goto P_0c08f328;
case 0x0c08f32au: goto P_0c08f32a;
case 0x0c08f32cu: goto P_0c08f32c;
case 0x0c08f32eu: goto P_0c08f32e;
case 0x0c08f4aeu: goto P_0c08f4ae;
case 0x0c08f4b0u: goto P_0c08f4b0;
case 0x0c08f4b2u: goto P_0c08f4b2;
case 0x0c08f4b4u: goto P_0c08f4b4;
case 0x0c08f4b6u: goto P_0c08f4b6;
case 0x0c08f4b8u: goto P_0c08f4b8;
case 0x0c08f4bau: goto P_0c08f4ba;
case 0x0c08f4bcu: goto P_0c08f4bc;
case 0x0c08f4beu: goto P_0c08f4be;
case 0x0c08f4c0u: goto P_0c08f4c0;
default: return vf3_matrix_family(target,s,ram);
}
P_0c08f11c: /* original 2fe6, guest PC 0x0c08f11c */
if(!s->budget--) { s->failed_pc=0x0c08f11cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f11e;
P_0c08f11e: /* original 6e43, guest PC 0x0c08f11e */
if(!s->budget--) { s->failed_pc=0x0c08f11eu; return 0; }
r[14]=r[4];
goto P_0c08f120;
P_0c08f120: /* original e05c, guest PC 0x0c08f120 */
if(!s->budget--) { s->failed_pc=0x0c08f120u; return 0; }
r[0]=0x0000005cu;
goto P_0c08f122;
P_0c08f122: /* original 2fd6, guest PC 0x0c08f122 */
if(!s->budget--) { s->failed_pc=0x0c08f122u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08f124;
P_0c08f124: /* original fffb, guest PC 0x0c08f124 */
if(!s->budget--) { s->failed_pc=0x0c08f124u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08f126;
P_0c08f126: /* original ffeb, guest PC 0x0c08f126 */
if(!s->budget--) { s->failed_pc=0x0c08f126u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c08f128;
P_0c08f128: /* original ffdb, guest PC 0x0c08f128 */
if(!s->budget--) { s->failed_pc=0x0c08f128u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c08f12a;
P_0c08f12a: /* original ffcb, guest PC 0x0c08f12a */
if(!s->budget--) { s->failed_pc=0x0c08f12au; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c08f12c;
P_0c08f12c: /* original f8e6, guest PC 0x0c08f12c */
if(!s->budget--) { s->failed_pc=0x0c08f12cu; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c08f12e;
P_0c08f12e: /* original e060, guest PC 0x0c08f12e */
if(!s->budget--) { s->failed_pc=0x0c08f12eu; return 0; }
r[0]=0x00000060u;
goto P_0c08f130;
P_0c08f130: /* original f5e6, guest PC 0x0c08f130 */
if(!s->budget--) { s->failed_pc=0x0c08f130u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f132;
P_0c08f132: /* original e064, guest PC 0x0c08f132 */
if(!s->budget--) { s->failed_pc=0x0c08f132u; return 0; }
r[0]=0x00000064u;
goto P_0c08f134;
P_0c08f134: /* original f6e6, guest PC 0x0c08f134 */
if(!s->budget--) { s->failed_pc=0x0c08f134u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f136;
P_0c08f136: /* original e068, guest PC 0x0c08f136 */
if(!s->budget--) { s->failed_pc=0x0c08f136u; return 0; }
r[0]=0x00000068u;
goto P_0c08f138;
P_0c08f138: /* original f4e6, guest PC 0x0c08f138 */
if(!s->budget--) { s->failed_pc=0x0c08f138u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f13a;
P_0c08f13a: /* original e06c, guest PC 0x0c08f13a */
if(!s->budget--) { s->failed_pc=0x0c08f13au; return 0; }
r[0]=0x0000006cu;
goto P_0c08f13c;
P_0c08f13c: /* original f7e6, guest PC 0x0c08f13c */
if(!s->budget--) { s->failed_pc=0x0c08f13cu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f13e;
P_0c08f13e: /* original 4f22, guest PC 0x0c08f13e */
if(!s->budget--) { s->failed_pc=0x0c08f13eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08f140;
P_0c08f140: /* original f875, guest PC 0x0c08f140 */
if(!s->budget--) { s->failed_pc=0x0c08f140u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[8])>as_float(fr[7]))!=0);
goto P_0c08f142;
P_0c08f142: /* original 7ff0, guest PC 0x0c08f142 */
if(!s->budget--) { s->failed_pc=0x0c08f142u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c08f144;
P_0c08f144: /* original 8b00, guest PC 0x0c08f144 */
if(!s->budget--) { s->failed_pc=0x0c08f144u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f148; }
goto P_0c08f146;
P_0c08f146: /* original f78c, guest PC 0x0c08f146 */
if(!s->budget--) { s->failed_pc=0x0c08f146u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c08f148;
P_0c08f148: /* original f575, guest PC 0x0c08f148 */
if(!s->budget--) { s->failed_pc=0x0c08f148u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[7]))!=0);
goto P_0c08f14a;
P_0c08f14a: /* original 8b00, guest PC 0x0c08f14a */
if(!s->budget--) { s->failed_pc=0x0c08f14au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f14e; }
goto P_0c08f14c;
P_0c08f14c: /* original f57c, guest PC 0x0c08f14c */
if(!s->budget--) { s->failed_pc=0x0c08f14cu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c08f14e;
P_0c08f14e: /* original dd3d, guest PC 0x0c08f14e */
if(!s->budget--) { s->failed_pc=0x0c08f14eu; return 0; }
r[13]=read(ram,0x0c08f244u,4);
goto P_0c08f150;
P_0c08f150: /* original f35c, guest PC 0x0c08f150 */
if(!s->budget--) { s->failed_pc=0x0c08f150u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f152;
P_0c08f152: /* original f56c, guest PC 0x0c08f152 */
if(!s->budget--) { s->failed_pc=0x0c08f152u; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c08f154;
P_0c08f154: /* original 4d0b, guest PC 0x0c08f154 */
if(!s->budget--) { s->failed_pc=0x0c08f154u; return 0; }
target=r[13];
r[16]=code_base|0x0c08f158u;
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f158u) { target=s->pc; goto dispatch; }
goto P_0c08f158;
P_0c08f156: /* original f530, guest PC 0x0c08f156 */
if(!s->budget--) { s->failed_pc=0x0c08f156u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c08f158;
P_0c08f158: /* original 640f, guest PC 0x0c08f158 */
if(!s->budget--) { s->failed_pc=0x0c08f158u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08f15a;
P_0c08f15a: /* original 906c, guest PC 0x0c08f15a */
if(!s->budget--) { s->failed_pc=0x0c08f15au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f236u,2);
goto P_0c08f15c;
P_0c08f15c: /* original 4400, guest PC 0x0c08f15c */
if(!s->budget--) { s->failed_pc=0x0c08f15cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c08f15e;
P_0c08f15e: /* original 05ec, guest PC 0x0c08f15e */
if(!s->budget--) { s->failed_pc=0x0c08f15eu; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c08f160;
P_0c08f160: /* original 75ff, guest PC 0x0c08f160 */
if(!s->budget--) { s->failed_pc=0x0c08f160u; return 0; }
r[5]+=0xffffffffu;
goto P_0c08f162;
P_0c08f162: /* original 4511, guest PC 0x0c08f162 */
if(!s->budget--) { s->failed_pc=0x0c08f162u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>=0)!=0);
goto P_0c08f164;
P_0c08f164: /* original 8b0b, guest PC 0x0c08f164 */
if(!s->budget--) { s->failed_pc=0x0c08f164u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f17e; }
goto P_0c08f166;
P_0c08f166: /* original 0e54, guest PC 0x0c08f166 */
if(!s->budget--) { s->failed_pc=0x0c08f166u; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c08f168;
P_0c08f168: /* original e3fc, guest PC 0x0c08f168 */
if(!s->budget--) { s->failed_pc=0x0c08f168u; return 0; }
r[3]=0xfffffffcu;
goto P_0c08f16a;
P_0c08f16a: /* original 9065, guest PC 0x0c08f16a */
if(!s->budget--) { s->failed_pc=0x0c08f16au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f238u,2);
goto P_0c08f16c;
P_0c08f16c: /* original 05ed, guest PC 0x0c08f16c */
if(!s->budget--) { s->failed_pc=0x0c08f16cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c08f16e;
P_0c08f16e: /* original 3458, guest PC 0x0c08f16e */
if(!s->budget--) { s->failed_pc=0x0c08f16eu; return 0; }
r[4]-=r[5];
goto P_0c08f170;
P_0c08f170: /* original 6643, guest PC 0x0c08f170 */
if(!s->budget--) { s->failed_pc=0x0c08f170u; return 0; }
r[6]=r[4];
goto P_0c08f172;
P_0c08f172: /* original 4421, guest PC 0x0c08f172 */
if(!s->budget--) { s->failed_pc=0x0c08f172u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c08f174;
P_0c08f174: /* original 4421, guest PC 0x0c08f174 */
if(!s->budget--) { s->failed_pc=0x0c08f174u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c08f176;
P_0c08f176: /* original 4421, guest PC 0x0c08f176 */
if(!s->budget--) { s->failed_pc=0x0c08f176u; return 0; }
r[17]=(r[17]&~1u)|((r[4]&1)!=0);
r[4]=(uint32_t)((int32_t)r[4]>>1);
goto P_0c08f178;
P_0c08f178: /* original 463c, guest PC 0x0c08f178 */
if(!s->budget--) { s->failed_pc=0x0c08f178u; return 0; }
r[6]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[6]>>((-r[3])&31u)):((int32_t)r[6]<0?0xffffffffu:0)):r[6]<<(r[3]&31u);
goto P_0c08f17a;
P_0c08f17a: /* original 346c, guest PC 0x0c08f17a */
if(!s->budget--) { s->failed_pc=0x0c08f17au; return 0; }
r[4]+=r[6];
goto P_0c08f17c;
P_0c08f17c: /* original 345c, guest PC 0x0c08f17c */
if(!s->budget--) { s->failed_pc=0x0c08f17cu; return 0; }
r[4]+=r[5];
goto P_0c08f17e;
P_0c08f17e: /* original 905b, guest PC 0x0c08f17e */
if(!s->budget--) { s->failed_pc=0x0c08f17eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f238u,2);
goto P_0c08f180;
P_0c08f180: /* original e502, guest PC 0x0c08f180 */
if(!s->budget--) { s->failed_pc=0x0c08f180u; return 0; }
r[5]=0x00000002u;
goto P_0c08f182;
P_0c08f182: /* original 0e45, guest PC 0x0c08f182 */
if(!s->budget--) { s->failed_pc=0x0c08f182u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c08f184;
P_0c08f184: /* original 9059, guest PC 0x0c08f184 */
if(!s->budget--) { s->failed_pc=0x0c08f184u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f23au,2);
goto P_0c08f186;
P_0c08f186: /* original 54ec, guest PC 0x0c08f186 */
if(!s->budget--) { s->failed_pc=0x0c08f186u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c08f188;
P_0c08f188: /* original f4e6, guest PC 0x0c08f188 */
if(!s->budget--) { s->failed_pc=0x0c08f188u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f18a;
P_0c08f18a: /* original 7004, guest PC 0x0c08f18a */
if(!s->budget--) { s->failed_pc=0x0c08f18au; return 0; }
r[0]+=0x00000004u;
goto P_0c08f18c;
P_0c08f18c: /* original f5e6, guest PC 0x0c08f18c */
if(!s->budget--) { s->failed_pc=0x0c08f18cu; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f18e;
P_0c08f18e: /* original 7004, guest PC 0x0c08f18e */
if(!s->budget--) { s->failed_pc=0x0c08f18eu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f190;
P_0c08f190: /* original 6343, guest PC 0x0c08f190 */
if(!s->budget--) { s->failed_pc=0x0c08f190u; return 0; }
r[3]=r[4];
goto P_0c08f192;
P_0c08f192: /* original f6e6, guest PC 0x0c08f192 */
if(!s->budget--) { s->failed_pc=0x0c08f192u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f194;
P_0c08f194: /* original 2358, guest PC 0x0c08f194 */
if(!s->budget--) { s->failed_pc=0x0c08f194u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c08f196;
P_0c08f196: /* original c72c, guest PC 0x0c08f196 */
if(!s->budget--) { s->failed_pc=0x0c08f196u; return 0; }
r[0]=code_base|0x0008f248u;
goto P_0c08f198;
P_0c08f198: /* original 8d04, guest PC 0x0c08f198 */
if(!s->budget--) { s->failed_pc=0x0c08f198u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,10,r[0]);
if(cond) { goto P_0c08f1a4; }
goto P_0c08f19c;
P_0c08f19a: /* original fa08, guest PC 0x0c08f19a */
if(!s->budget--) { s->failed_pc=0x0c08f19au; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08f19c;
P_0c08f19c: /* original fd5c, guest PC 0x0c08f19c */
if(!s->budget--) { s->failed_pc=0x0c08f19cu; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c08f19e;
P_0c08f19e: /* original fc4c, guest PC 0x0c08f19e */
if(!s->budget--) { s->failed_pc=0x0c08f19eu; return 0; }
vf3_matrix_move(s,12,4);
goto P_0c08f1a0;
P_0c08f1a0: /* original a037, guest PC 0x0c08f1a0 */
if(!s->budget--) { s->failed_pc=0x0c08f1a0u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c08f212;
P_0c08f1a2: /* original fe6c, guest PC 0x0c08f1a2 */
if(!s->budget--) { s->failed_pc=0x0c08f1a2u; return 0; }
vf3_matrix_move(s,14,6);
goto P_0c08f1a4;
P_0c08f1a4: /* original 904a, guest PC 0x0c08f1a4 */
if(!s->budget--) { s->failed_pc=0x0c08f1a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f23cu,2);
goto P_0c08f1a6;
P_0c08f1a6: /* original fce6, guest PC 0x0c08f1a6 */
if(!s->budget--) { s->failed_pc=0x0c08f1a6u; return 0; }
vf3_matrix_load(s,ram,12,r[14]+r[0]);
goto P_0c08f1a8;
P_0c08f1a8: /* original 7004, guest PC 0x0c08f1a8 */
if(!s->budget--) { s->failed_pc=0x0c08f1a8u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f1aa;
P_0c08f1aa: /* original fde6, guest PC 0x0c08f1aa */
if(!s->budget--) { s->failed_pc=0x0c08f1aau; return 0; }
vf3_matrix_load(s,ram,13,r[14]+r[0]);
goto P_0c08f1ac;
P_0c08f1ac: /* original 7004, guest PC 0x0c08f1ac */
if(!s->budget--) { s->failed_pc=0x0c08f1acu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f1ae;
P_0c08f1ae: /* original f7cc, guest PC 0x0c08f1ae */
if(!s->budget--) { s->failed_pc=0x0c08f1aeu; return 0; }
vf3_matrix_move(s,7,12);
goto P_0c08f1b0;
P_0c08f1b0: /* original f741, guest PC 0x0c08f1b0 */
if(!s->budget--) { s->failed_pc=0x0c08f1b0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'-');
goto P_0c08f1b2;
P_0c08f1b2: /* original f8dc, guest PC 0x0c08f1b2 */
if(!s->budget--) { s->failed_pc=0x0c08f1b2u; return 0; }
vf3_matrix_move(s,8,13);
goto P_0c08f1b4;
P_0c08f1b4: /* original f851, guest PC 0x0c08f1b4 */
if(!s->budget--) { s->failed_pc=0x0c08f1b4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'-');
goto P_0c08f1b6;
P_0c08f1b6: /* original fee6, guest PC 0x0c08f1b6 */
if(!s->budget--) { s->failed_pc=0x0c08f1b6u; return 0; }
vf3_matrix_load(s,ram,14,r[14]+r[0]);
goto P_0c08f1b8;
P_0c08f1b8: /* original 9041, guest PC 0x0c08f1b8 */
if(!s->budget--) { s->failed_pc=0x0c08f1b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f23eu,2);
goto P_0c08f1ba;
P_0c08f1ba: /* original f37c, guest PC 0x0c08f1ba */
if(!s->budget--) { s->failed_pc=0x0c08f1bau; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08f1bc;
P_0c08f1bc: /* original f732, guest PC 0x0c08f1bc */
if(!s->budget--) { s->failed_pc=0x0c08f1bcu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08f1be;
P_0c08f1be: /* original f08c, guest PC 0x0c08f1be */
if(!s->budget--) { s->failed_pc=0x0c08f1beu; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c08f1c0;
P_0c08f1c0: /* original fbe6, guest PC 0x0c08f1c0 */
if(!s->budget--) { s->failed_pc=0x0c08f1c0u; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c08f1c2;
P_0c08f1c2: /* original 7008, guest PC 0x0c08f1c2 */
if(!s->budget--) { s->failed_pc=0x0c08f1c2u; return 0; }
r[0]+=0x00000008u;
goto P_0c08f1c4;
P_0c08f1c4: /* original f27c, guest PC 0x0c08f1c4 */
if(!s->budget--) { s->failed_pc=0x0c08f1c4u; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c08f1c6;
P_0c08f1c6: /* original f28e, guest PC 0x0c08f1c6 */
if(!s->budget--) { s->failed_pc=0x0c08f1c6u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c08f1c8;
P_0c08f1c8: /* original f8ec, guest PC 0x0c08f1c8 */
if(!s->budget--) { s->failed_pc=0x0c08f1c8u; return 0; }
vf3_matrix_move(s,8,14);
goto P_0c08f1ca;
P_0c08f1ca: /* original f861, guest PC 0x0c08f1ca */
if(!s->budget--) { s->failed_pc=0x0c08f1cau; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c08f1cc;
P_0c08f1cc: /* original f72c, guest PC 0x0c08f1cc */
if(!s->budget--) { s->failed_pc=0x0c08f1ccu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c08f1ce;
P_0c08f1ce: /* original f08c, guest PC 0x0c08f1ce */
if(!s->budget--) { s->failed_pc=0x0c08f1ceu; return 0; }
vf3_matrix_move(s,0,8);
goto P_0c08f1d0;
P_0c08f1d0: /* original f78e, guest PC 0x0c08f1d0 */
if(!s->budget--) { s->failed_pc=0x0c08f1d0u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[8],fr[7],r[18]);
goto P_0c08f1d2;
P_0c08f1d2: /* original fa75, guest PC 0x0c08f1d2 */
if(!s->budget--) { s->failed_pc=0x0c08f1d2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[7]))!=0);
goto P_0c08f1d4;
P_0c08f1d4: /* original 8f02, guest PC 0x0c08f1d4 */
if(!s->budget--) { s->failed_pc=0x0c08f1d4u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[14]+r[0]);
if(!cond) { goto P_0c08f1dc; }
goto P_0c08f1d8;
P_0c08f1d6: /* original f9e6, guest PC 0x0c08f1d6 */
if(!s->budget--) { s->failed_pc=0x0c08f1d6u; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c08f1d8;
P_0c08f1d8: /* original a002, guest PC 0x0c08f1d8 */
if(!s->budget--) { s->failed_pc=0x0c08f1d8u; return 0; }
fr[3]=0;
goto P_0c08f1e0;
P_0c08f1da: /* original f38d, guest PC 0x0c08f1da */
if(!s->budget--) { s->failed_pc=0x0c08f1dau; return 0; }
fr[3]=0;
goto P_0c08f1dc;
P_0c08f1dc: /* original f37c, guest PC 0x0c08f1dc */
if(!s->budget--) { s->failed_pc=0x0c08f1dcu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08f1de;
P_0c08f1de: /* original f37d, guest PC 0x0c08f1de */
if(!s->budget--) { s->failed_pc=0x0c08f1deu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08f1e0;
P_0c08f1e0: /* original f732, guest PC 0x0c08f1e0 */
if(!s->budget--) { s->failed_pc=0x0c08f1e0u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08f1e2;
P_0c08f1e2: /* original 902d, guest PC 0x0c08f1e2 */
if(!s->budget--) { s->failed_pc=0x0c08f1e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f240u,2);
goto P_0c08f1e4;
P_0c08f1e4: /* original f28d, guest PC 0x0c08f1e4 */
if(!s->budget--) { s->failed_pc=0x0c08f1e4u; return 0; }
fr[2]=0;
goto P_0c08f1e6;
P_0c08f1e6: /* original f07c, guest PC 0x0c08f1e6 */
if(!s->budget--) { s->failed_pc=0x0c08f1e6u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08f1e8;
P_0c08f1e8: /* original f9be, guest PC 0x0c08f1e8 */
if(!s->budget--) { s->failed_pc=0x0c08f1e8u; return 0; }
fr[9]=vf3_fpu_mac(fr[0],fr[11],fr[9],r[18]);
goto P_0c08f1ea;
P_0c08f1ea: /* original f7e6, guest PC 0x0c08f1ea */
if(!s->budget--) { s->failed_pc=0x0c08f1eau; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c08f1ec;
P_0c08f1ec: /* original f39c, guest PC 0x0c08f1ec */
if(!s->budget--) { s->failed_pc=0x0c08f1ecu; return 0; }
vf3_matrix_move(s,3,9);
goto P_0c08f1ee;
P_0c08f1ee: /* original f371, guest PC 0x0c08f1ee */
if(!s->budget--) { s->failed_pc=0x0c08f1eeu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[7],r[18],'-');
goto P_0c08f1f0;
P_0c08f1f0: /* original f235, guest PC 0x0c08f1f0 */
if(!s->budget--) { s->failed_pc=0x0c08f1f0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08f1f2;
P_0c08f1f2: /* original 8d01, guest PC 0x0c08f1f2 */
if(!s->budget--) { s->failed_pc=0x0c08f1f2u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,8,9);
if(cond) { goto P_0c08f1f8; }
goto P_0c08f1f6;
P_0c08f1f4: /* original f89c, guest PC 0x0c08f1f4 */
if(!s->budget--) { s->failed_pc=0x0c08f1f4u; return 0; }
vf3_matrix_move(s,8,9);
goto P_0c08f1f6;
P_0c08f1f6: /* original f78c, guest PC 0x0c08f1f6 */
if(!s->budget--) { s->failed_pc=0x0c08f1f6u; return 0; }
vf3_matrix_move(s,7,8);
goto P_0c08f1f8;
P_0c08f1f8: /* original f4c1, guest PC 0x0c08f1f8 */
if(!s->budget--) { s->failed_pc=0x0c08f1f8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[12],r[18],'-');
goto P_0c08f1fa;
P_0c08f1fa: /* original f07c, guest PC 0x0c08f1fa */
if(!s->budget--) { s->failed_pc=0x0c08f1fau; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08f1fc;
P_0c08f1fc: /* original f3cc, guest PC 0x0c08f1fc */
if(!s->budget--) { s->failed_pc=0x0c08f1fcu; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c08f1fe;
P_0c08f1fe: /* original f5d1, guest PC 0x0c08f1fe */
if(!s->budget--) { s->failed_pc=0x0c08f1feu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[13],r[18],'-');
goto P_0c08f200;
P_0c08f200: /* original f6e1, guest PC 0x0c08f200 */
if(!s->budget--) { s->failed_pc=0x0c08f200u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[14],r[18],'-');
goto P_0c08f202;
P_0c08f202: /* original f2dc, guest PC 0x0c08f202 */
if(!s->budget--) { s->failed_pc=0x0c08f202u; return 0; }
vf3_matrix_move(s,2,13);
goto P_0c08f204;
P_0c08f204: /* original f34e, guest PC 0x0c08f204 */
if(!s->budget--) { s->failed_pc=0x0c08f204u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[4],fr[3],r[18]);
goto P_0c08f206;
P_0c08f206: /* original f25e, guest PC 0x0c08f206 */
if(!s->budget--) { s->failed_pc=0x0c08f206u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c08f208;
P_0c08f208: /* original fc3c, guest PC 0x0c08f208 */
if(!s->budget--) { s->failed_pc=0x0c08f208u; return 0; }
vf3_matrix_move(s,12,3);
goto P_0c08f20a;
P_0c08f20a: /* original f3ec, guest PC 0x0c08f20a */
if(!s->budget--) { s->failed_pc=0x0c08f20au; return 0; }
vf3_matrix_move(s,3,14);
goto P_0c08f20c;
P_0c08f20c: /* original f36e, guest PC 0x0c08f20c */
if(!s->budget--) { s->failed_pc=0x0c08f20cu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[6],fr[3],r[18]);
goto P_0c08f20e;
P_0c08f20e: /* original fd2c, guest PC 0x0c08f20e */
if(!s->budget--) { s->failed_pc=0x0c08f20eu; return 0; }
vf3_matrix_move(s,13,2);
goto P_0c08f210;
P_0c08f210: /* original fe3c, guest PC 0x0c08f210 */
if(!s->budget--) { s->failed_pc=0x0c08f210u; return 0; }
vf3_matrix_move(s,14,3);
goto P_0c08f212;
P_0c08f212: /* original 9013, guest PC 0x0c08f212 */
if(!s->budget--) { s->failed_pc=0x0c08f212u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f23cu,2);
goto P_0c08f214;
P_0c08f214: /* original 2548, guest PC 0x0c08f214 */
if(!s->budget--) { s->failed_pc=0x0c08f214u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[4])==0)!=0);
goto P_0c08f216;
P_0c08f216: /* original fec7, guest PC 0x0c08f216 */
if(!s->budget--) { s->failed_pc=0x0c08f216u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c08f218;
P_0c08f218: /* original 7004, guest PC 0x0c08f218 */
if(!s->budget--) { s->failed_pc=0x0c08f218u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f21a;
P_0c08f21a: /* original fed7, guest PC 0x0c08f21a */
if(!s->budget--) { s->failed_pc=0x0c08f21au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08f21c;
P_0c08f21c: /* original 7004, guest PC 0x0c08f21c */
if(!s->budget--) { s->failed_pc=0x0c08f21cu; return 0; }
r[0]+=0x00000004u;
goto P_0c08f21e;
P_0c08f21e: /* original fee7, guest PC 0x0c08f21e */
if(!s->budget--) { s->failed_pc=0x0c08f21eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08f220;
P_0c08f220: /* original 7058, guest PC 0x0c08f220 */
if(!s->budget--) { s->failed_pc=0x0c08f220u; return 0; }
r[0]+=0x00000058u;
goto P_0c08f222;
P_0c08f222: /* original f8e6, guest PC 0x0c08f222 */
if(!s->budget--) { s->failed_pc=0x0c08f222u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c08f224;
P_0c08f224: /* original 7004, guest PC 0x0c08f224 */
if(!s->budget--) { s->failed_pc=0x0c08f224u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f226;
P_0c08f226: /* original f5e6, guest PC 0x0c08f226 */
if(!s->budget--) { s->failed_pc=0x0c08f226u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c08f228;
P_0c08f228: /* original 7004, guest PC 0x0c08f228 */
if(!s->budget--) { s->failed_pc=0x0c08f228u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f22a;
P_0c08f22a: /* original 8d0f, guest PC 0x0c08f22a */
if(!s->budget--) { s->failed_pc=0x0c08f22au; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,9,r[14]+r[0]);
if(cond) { goto P_0c08f24c; }
goto P_0c08f22e;
P_0c08f22c: /* original f9e6, guest PC 0x0c08f22c */
if(!s->budget--) { s->failed_pc=0x0c08f22cu; return 0; }
vf3_matrix_load(s,ram,9,r[14]+r[0]);
goto P_0c08f22e;
P_0c08f22e: /* original f45c, guest PC 0x0c08f22e */
if(!s->budget--) { s->failed_pc=0x0c08f22eu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c08f230;
P_0c08f230: /* original f68c, guest PC 0x0c08f230 */
if(!s->budget--) { s->failed_pc=0x0c08f230u; return 0; }
vf3_matrix_move(s,6,8);
goto P_0c08f232;
P_0c08f232: /* original a049, guest PC 0x0c08f232 */
if(!s->budget--) { s->failed_pc=0x0c08f232u; return 0; }
vf3_matrix_move(s,15,9);
goto P_0c08f2c8;
P_0c08f234: /* original ff9c, guest PC 0x0c08f234 */
if(!s->budget--) { s->failed_pc=0x0c08f234u; return 0; }
vf3_matrix_move(s,15,9);
if(!vf3_matrix_family(0x0c08f236u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f236u; return 0; } return 1;
P_0c08f24c: /* original 90b3, guest PC 0x0c08f24c */
if(!s->budget--) { s->failed_pc=0x0c08f24cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f3b6u,2);
goto P_0c08f24e;
P_0c08f24e: /* original f6e6, guest PC 0x0c08f24e */
if(!s->budget--) { s->failed_pc=0x0c08f24eu; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c08f250;
P_0c08f250: /* original 7004, guest PC 0x0c08f250 */
if(!s->budget--) { s->failed_pc=0x0c08f250u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f252;
P_0c08f252: /* original f4e6, guest PC 0x0c08f252 */
if(!s->budget--) { s->failed_pc=0x0c08f252u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c08f254;
P_0c08f254: /* original 7004, guest PC 0x0c08f254 */
if(!s->budget--) { s->failed_pc=0x0c08f254u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f256;
P_0c08f256: /* original ffe6, guest PC 0x0c08f256 */
if(!s->budget--) { s->failed_pc=0x0c08f256u; return 0; }
vf3_matrix_load(s,ram,15,r[14]+r[0]);
goto P_0c08f258;
P_0c08f258: /* original 7044, guest PC 0x0c08f258 */
if(!s->budget--) { s->failed_pc=0x0c08f258u; return 0; }
r[0]+=0x00000044u;
goto P_0c08f25a;
P_0c08f25a: /* original f3e6, guest PC 0x0c08f25a */
if(!s->budget--) { s->failed_pc=0x0c08f25au; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f25c;
P_0c08f25c: /* original e00c, guest PC 0x0c08f25c */
if(!s->budget--) { s->failed_pc=0x0c08f25cu; return 0; }
r[0]=0x0000000cu;
goto P_0c08f25e;
P_0c08f25e: /* original ff37, guest PC 0x0c08f25e */
if(!s->budget--) { s->failed_pc=0x0c08f25eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f260;
P_0c08f260: /* original 90aa, guest PC 0x0c08f260 */
if(!s->budget--) { s->failed_pc=0x0c08f260u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f3b8u,2);
goto P_0c08f262;
P_0c08f262: /* original f3e6, guest PC 0x0c08f262 */
if(!s->budget--) { s->failed_pc=0x0c08f262u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c08f264;
P_0c08f264: /* original e008, guest PC 0x0c08f264 */
if(!s->budget--) { s->failed_pc=0x0c08f264u; return 0; }
r[0]=0x00000008u;
goto P_0c08f266;
P_0c08f266: /* original ff37, guest PC 0x0c08f266 */
if(!s->budget--) { s->failed_pc=0x0c08f266u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08f268;
P_0c08f268: /* original f76c, guest PC 0x0c08f268 */
if(!s->budget--) { s->failed_pc=0x0c08f268u; return 0; }
vf3_matrix_move(s,7,6);
goto P_0c08f26a;
P_0c08f26a: /* original f781, guest PC 0x0c08f26a */
if(!s->budget--) { s->failed_pc=0x0c08f26au; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[8],r[18],'-');
goto P_0c08f26c;
P_0c08f26c: /* original fb4c, guest PC 0x0c08f26c */
if(!s->budget--) { s->failed_pc=0x0c08f26cu; return 0; }
vf3_matrix_move(s,11,4);
goto P_0c08f26e;
P_0c08f26e: /* original fb51, guest PC 0x0c08f26e */
if(!s->budget--) { s->failed_pc=0x0c08f26eu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[5],r[18],'-');
goto P_0c08f270;
P_0c08f270: /* original f37c, guest PC 0x0c08f270 */
if(!s->budget--) { s->failed_pc=0x0c08f270u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08f272;
P_0c08f272: /* original f732, guest PC 0x0c08f272 */
if(!s->budget--) { s->failed_pc=0x0c08f272u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08f274;
P_0c08f274: /* original f0bc, guest PC 0x0c08f274 */
if(!s->budget--) { s->failed_pc=0x0c08f274u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c08f276;
P_0c08f276: /* original f27c, guest PC 0x0c08f276 */
if(!s->budget--) { s->failed_pc=0x0c08f276u; return 0; }
vf3_matrix_move(s,2,7);
goto P_0c08f278;
P_0c08f278: /* original f2be, guest PC 0x0c08f278 */
if(!s->budget--) { s->failed_pc=0x0c08f278u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[11],fr[2],r[18]);
goto P_0c08f27a;
P_0c08f27a: /* original fbfc, guest PC 0x0c08f27a */
if(!s->budget--) { s->failed_pc=0x0c08f27au; return 0; }
vf3_matrix_move(s,11,15);
goto P_0c08f27c;
P_0c08f27c: /* original fb91, guest PC 0x0c08f27c */
if(!s->budget--) { s->failed_pc=0x0c08f27cu; return 0; }
fr[11]=vf3_fpu_binary(fr[11],fr[9],r[18],'-');
goto P_0c08f27e;
P_0c08f27e: /* original f72c, guest PC 0x0c08f27e */
if(!s->budget--) { s->failed_pc=0x0c08f27eu; return 0; }
vf3_matrix_move(s,7,2);
goto P_0c08f280;
P_0c08f280: /* original f0bc, guest PC 0x0c08f280 */
if(!s->budget--) { s->failed_pc=0x0c08f280u; return 0; }
vf3_matrix_move(s,0,11);
goto P_0c08f282;
P_0c08f282: /* original f7be, guest PC 0x0c08f282 */
if(!s->budget--) { s->failed_pc=0x0c08f282u; return 0; }
fr[7]=vf3_fpu_mac(fr[0],fr[11],fr[7],r[18]);
goto P_0c08f284;
P_0c08f284: /* original fa75, guest PC 0x0c08f284 */
if(!s->budget--) { s->failed_pc=0x0c08f284u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[7]))!=0);
goto P_0c08f286;
P_0c08f286: /* original 8b01, guest PC 0x0c08f286 */
if(!s->budget--) { s->failed_pc=0x0c08f286u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c08f28c; }
goto P_0c08f288;
P_0c08f288: /* original a002, guest PC 0x0c08f288 */
if(!s->budget--) { s->failed_pc=0x0c08f288u; return 0; }
fr[3]=0;
goto P_0c08f290;
P_0c08f28a: /* original f38d, guest PC 0x0c08f28a */
if(!s->budget--) { s->failed_pc=0x0c08f28au; return 0; }
fr[3]=0;
goto P_0c08f28c;
P_0c08f28c: /* original f37c, guest PC 0x0c08f28c */
if(!s->budget--) { s->failed_pc=0x0c08f28cu; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c08f28e;
P_0c08f28e: /* original f37d, guest PC 0x0c08f28e */
if(!s->budget--) { s->failed_pc=0x0c08f28eu; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08f290;
P_0c08f290: /* original e008, guest PC 0x0c08f290 */
if(!s->budget--) { s->failed_pc=0x0c08f290u; return 0; }
r[0]=0x00000008u;
goto P_0c08f292;
P_0c08f292: /* original f732, guest PC 0x0c08f292 */
if(!s->budget--) { s->failed_pc=0x0c08f292u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[3],r[18],'*');
goto P_0c08f294;
P_0c08f294: /* original f3f6, guest PC 0x0c08f294 */
if(!s->budget--) { s->failed_pc=0x0c08f294u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c08f296;
P_0c08f296: /* original e00c, guest PC 0x0c08f296 */
if(!s->budget--) { s->failed_pc=0x0c08f296u; return 0; }
r[0]=0x0000000cu;
goto P_0c08f298;
P_0c08f298: /* original f2f6, guest PC 0x0c08f298 */
if(!s->budget--) { s->failed_pc=0x0c08f298u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c08f29a;
P_0c08f29a: /* original 908e, guest PC 0x0c08f29a */
if(!s->budget--) { s->failed_pc=0x0c08f29au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f3bau,2);
goto P_0c08f29c;
P_0c08f29c: /* original f07c, guest PC 0x0c08f29c */
if(!s->budget--) { s->failed_pc=0x0c08f29cu; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08f29e;
P_0c08f29e: /* original f32e, guest PC 0x0c08f29e */
if(!s->budget--) { s->failed_pc=0x0c08f29eu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c08f2a0;
P_0c08f2a0: /* original fbe6, guest PC 0x0c08f2a0 */
if(!s->budget--) { s->failed_pc=0x0c08f2a0u; return 0; }
vf3_matrix_load(s,ram,11,r[14]+r[0]);
goto P_0c08f2a2;
P_0c08f2a2: /* original f28d, guest PC 0x0c08f2a2 */
if(!s->budget--) { s->failed_pc=0x0c08f2a2u; return 0; }
fr[2]=0;
goto P_0c08f2a4;
P_0c08f2a4: /* original f73c, guest PC 0x0c08f2a4 */
if(!s->budget--) { s->failed_pc=0x0c08f2a4u; return 0; }
vf3_matrix_move(s,7,3);
goto P_0c08f2a6;
P_0c08f2a6: /* original f3b1, guest PC 0x0c08f2a6 */
if(!s->budget--) { s->failed_pc=0x0c08f2a6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[11],r[18],'-');
goto P_0c08f2a8;
P_0c08f2a8: /* original f235, guest PC 0x0c08f2a8 */
if(!s->budget--) { s->failed_pc=0x0c08f2a8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c08f2aa;
P_0c08f2aa: /* original 8f01, guest PC 0x0c08f2aa */
if(!s->budget--) { s->failed_pc=0x0c08f2aau; return 0; }
cond=r[17]&1u;
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
if(!cond) { goto P_0c08f2b0; }
goto P_0c08f2ae;
P_0c08f2ac: /* original f861, guest PC 0x0c08f2ac */
if(!s->budget--) { s->failed_pc=0x0c08f2acu; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c08f2ae;
P_0c08f2ae: /* original f7bc, guest PC 0x0c08f2ae */
if(!s->budget--) { s->failed_pc=0x0c08f2aeu; return 0; }
vf3_matrix_move(s,7,11);
goto P_0c08f2b0;
P_0c08f2b0: /* original f36c, guest PC 0x0c08f2b0 */
if(!s->budget--) { s->failed_pc=0x0c08f2b0u; return 0; }
vf3_matrix_move(s,3,6);
goto P_0c08f2b2;
P_0c08f2b2: /* original f541, guest PC 0x0c08f2b2 */
if(!s->budget--) { s->failed_pc=0x0c08f2b2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'-');
goto P_0c08f2b4;
P_0c08f2b4: /* original f07c, guest PC 0x0c08f2b4 */
if(!s->budget--) { s->failed_pc=0x0c08f2b4u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c08f2b6;
P_0c08f2b6: /* original f38e, guest PC 0x0c08f2b6 */
if(!s->budget--) { s->failed_pc=0x0c08f2b6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[8],fr[3],r[18]);
goto P_0c08f2b8;
P_0c08f2b8: /* original f9f1, guest PC 0x0c08f2b8 */
if(!s->budget--) { s->failed_pc=0x0c08f2b8u; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[15],r[18],'-');
goto P_0c08f2ba;
P_0c08f2ba: /* original f24c, guest PC 0x0c08f2ba */
if(!s->budget--) { s->failed_pc=0x0c08f2bau; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c08f2bc;
P_0c08f2bc: /* original f25e, guest PC 0x0c08f2bc */
if(!s->budget--) { s->failed_pc=0x0c08f2bcu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[5],fr[2],r[18]);
goto P_0c08f2be;
P_0c08f2be: /* original f63c, guest PC 0x0c08f2be */
if(!s->budget--) { s->failed_pc=0x0c08f2beu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c08f2c0;
P_0c08f2c0: /* original f3fc, guest PC 0x0c08f2c0 */
if(!s->budget--) { s->failed_pc=0x0c08f2c0u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c08f2c2;
P_0c08f2c2: /* original f39e, guest PC 0x0c08f2c2 */
if(!s->budget--) { s->failed_pc=0x0c08f2c2u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c08f2c4;
P_0c08f2c4: /* original f42c, guest PC 0x0c08f2c4 */
if(!s->budget--) { s->failed_pc=0x0c08f2c4u; return 0; }
vf3_matrix_move(s,4,2);
goto P_0c08f2c6;
P_0c08f2c6: /* original ff3c, guest PC 0x0c08f2c6 */
if(!s->budget--) { s->failed_pc=0x0c08f2c6u; return 0; }
vf3_matrix_move(s,15,3);
goto P_0c08f2c8;
P_0c08f2c8: /* original 9075, guest PC 0x0c08f2c8 */
if(!s->budget--) { s->failed_pc=0x0c08f2c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08f3b6u,2);
goto P_0c08f2ca;
P_0c08f2ca: /* original e3fc, guest PC 0x0c08f2ca */
if(!s->budget--) { s->failed_pc=0x0c08f2cau; return 0; }
r[3]=0xfffffffcu;
goto P_0c08f2cc;
P_0c08f2cc: /* original 2439, guest PC 0x0c08f2cc */
if(!s->budget--) { s->failed_pc=0x0c08f2ccu; return 0; }
r[4]&=r[3];
goto P_0c08f2ce;
P_0c08f2ce: /* original fe67, guest PC 0x0c08f2ce */
if(!s->budget--) { s->failed_pc=0x0c08f2ceu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08f2d0;
P_0c08f2d0: /* original f6c1, guest PC 0x0c08f2d0 */
if(!s->budget--) { s->failed_pc=0x0c08f2d0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[12],r[18],'-');
goto P_0c08f2d2;
P_0c08f2d2: /* original 7004, guest PC 0x0c08f2d2 */
if(!s->budget--) { s->failed_pc=0x0c08f2d2u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f2d4;
P_0c08f2d4: /* original fe47, guest PC 0x0c08f2d4 */
if(!s->budget--) { s->failed_pc=0x0c08f2d4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08f2d6;
P_0c08f2d6: /* original 7004, guest PC 0x0c08f2d6 */
if(!s->budget--) { s->failed_pc=0x0c08f2d6u; return 0; }
r[0]+=0x00000004u;
goto P_0c08f2d8;
P_0c08f2d8: /* original fef7, guest PC 0x0c08f2d8 */
if(!s->budget--) { s->failed_pc=0x0c08f2d8u; return 0; }
vf3_matrix_store(s,ram,15,r[14]+r[0]);
goto P_0c08f2da;
P_0c08f2da: /* original ffe1, guest PC 0x0c08f2da */
if(!s->budget--) { s->failed_pc=0x0c08f2dau; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[14],r[18],'-');
goto P_0c08f2dc;
P_0c08f2dc: /* original 1e4c, guest PC 0x0c08f2dc */
if(!s->budget--) { s->failed_pc=0x0c08f2dcu; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c08f2de;
P_0c08f2de: /* original f56c, guest PC 0x0c08f2de */
if(!s->budget--) { s->failed_pc=0x0c08f2deu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c08f2e0;
P_0c08f2e0: /* original f562, guest PC 0x0c08f2e0 */
if(!s->budget--) { s->failed_pc=0x0c08f2e0u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'*');
goto P_0c08f2e2;
P_0c08f2e2: /* original f0fc, guest PC 0x0c08f2e2 */
if(!s->budget--) { s->failed_pc=0x0c08f2e2u; return 0; }
vf3_matrix_move(s,0,15);
goto P_0c08f2e4;
P_0c08f2e4: /* original f5fe, guest PC 0x0c08f2e4 */
if(!s->budget--) { s->failed_pc=0x0c08f2e4u; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[15],fr[5],r[18]);
goto P_0c08f2e6;
P_0c08f2e6: /* original fa55, guest PC 0x0c08f2e6 */
if(!s->budget--) { s->failed_pc=0x0c08f2e6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[10])>as_float(fr[5]))!=0);
goto P_0c08f2e8;
P_0c08f2e8: /* original 8f02, guest PC 0x0c08f2e8 */
if(!s->budget--) { s->failed_pc=0x0c08f2e8u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
if(!cond) { goto P_0c08f2f0; }
goto P_0c08f2ec;
P_0c08f2ea: /* original f4d1, guest PC 0x0c08f2ea */
if(!s->budget--) { s->failed_pc=0x0c08f2eau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[13],r[18],'-');
goto P_0c08f2ec;
P_0c08f2ec: /* original a002, guest PC 0x0c08f2ec */
if(!s->budget--) { s->failed_pc=0x0c08f2ecu; return 0; }
fr[3]=0;
goto P_0c08f2f4;
P_0c08f2ee: /* original f38d, guest PC 0x0c08f2ee */
if(!s->budget--) { s->failed_pc=0x0c08f2eeu; return 0; }
fr[3]=0;
goto P_0c08f2f0;
P_0c08f2f0: /* original f35c, guest PC 0x0c08f2f0 */
if(!s->budget--) { s->failed_pc=0x0c08f2f0u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c08f2f2;
P_0c08f2f2: /* original f37d, guest PC 0x0c08f2f2 */
if(!s->budget--) { s->failed_pc=0x0c08f2f2u; return 0; }
if(!vf3_fpu_fsrra(fr[3],r[18],&fr[3])) goto unsupported;
goto P_0c08f2f4;
P_0c08f2f4: /* original f532, guest PC 0x0c08f2f4 */
if(!s->budget--) { s->failed_pc=0x0c08f2f4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c08f2f6;
P_0c08f2f6: /* original f64d, guest PC 0x0c08f2f6 */
if(!s->budget--) { s->failed_pc=0x0c08f2f6u; return 0; }
fr[6]^=0x80000000u;
goto P_0c08f2f8;
P_0c08f2f8: /* original 4d0b, guest PC 0x0c08f2f8 */
if(!s->budget--) { s->failed_pc=0x0c08f2f8u; return 0; }
target=r[13];
r[16]=code_base|0x0c08f2fcu;
vf3_matrix_store(s,ram,6,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f2fcu) { target=s->pc; goto dispatch; }
goto P_0c08f2fc;
P_0c08f2fa: /* original ff6a, guest PC 0x0c08f2fa */
if(!s->budget--) { s->failed_pc=0x0c08f2fau; return 0; }
vf3_matrix_store(s,ram,6,r[15]);
goto P_0c08f2fc;
P_0c08f2fc: /* original 600f, guest PC 0x0c08f2fc */
if(!s->budget--) { s->failed_pc=0x0c08f2fcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08f2fe;
P_0c08f2fe: /* original 81f2, guest PC 0x0c08f2fe */
if(!s->budget--) { s->failed_pc=0x0c08f2feu; return 0; }
write(ram,r[15]+4,r[0],2);
goto P_0c08f300;
P_0c08f300: /* original f5fc, guest PC 0x0c08f300 */
if(!s->budget--) { s->failed_pc=0x0c08f300u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c08f302;
P_0c08f302: /* original 4d0b, guest PC 0x0c08f302 */
if(!s->budget--) { s->failed_pc=0x0c08f302u; return 0; }
target=r[13];
r[16]=code_base|0x0c08f306u;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08f306u) { target=s->pc; goto dispatch; }
goto P_0c08f306;
P_0c08f304: /* original f4f8, guest PC 0x0c08f304 */
if(!s->budget--) { s->failed_pc=0x0c08f304u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c08f306;
P_0c08f306: /* original 640f, guest PC 0x0c08f306 */
if(!s->budget--) { s->failed_pc=0x0c08f306u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[0];
goto P_0c08f308;
P_0c08f308: /* original 85f2, guest PC 0x0c08f308 */
if(!s->budget--) { s->failed_pc=0x0c08f308u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[15]+4,2);
goto P_0c08f30a;
P_0c08f30a: /* original 7f10, guest PC 0x0c08f30a */
if(!s->budget--) { s->failed_pc=0x0c08f30au; return 0; }
r[15]+=0x00000010u;
goto P_0c08f30c;
P_0c08f30c: /* original 81ee, guest PC 0x0c08f30c */
if(!s->budget--) { s->failed_pc=0x0c08f30cu; return 0; }
write(ram,r[14]+28,r[0],2);
goto P_0c08f30e;
P_0c08f30e: /* original 6043, guest PC 0x0c08f30e */
if(!s->budget--) { s->failed_pc=0x0c08f30eu; return 0; }
r[0]=r[4];
goto P_0c08f310;
P_0c08f310: /* original 4f26, guest PC 0x0c08f310 */
if(!s->budget--) { s->failed_pc=0x0c08f310u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08f312;
P_0c08f312: /* original 81ef, guest PC 0x0c08f312 */
if(!s->budget--) { s->failed_pc=0x0c08f312u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c08f314;
P_0c08f314: /* original e010, guest PC 0x0c08f314 */
if(!s->budget--) { s->failed_pc=0x0c08f314u; return 0; }
r[0]=0x00000010u;
goto P_0c08f316;
P_0c08f316: /* original fec7, guest PC 0x0c08f316 */
if(!s->budget--) { s->failed_pc=0x0c08f316u; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c08f318;
P_0c08f318: /* original e014, guest PC 0x0c08f318 */
if(!s->budget--) { s->failed_pc=0x0c08f318u; return 0; }
r[0]=0x00000014u;
goto P_0c08f31a;
P_0c08f31a: /* original fed7, guest PC 0x0c08f31a */
if(!s->budget--) { s->failed_pc=0x0c08f31au; return 0; }
vf3_matrix_store(s,ram,13,r[14]+r[0]);
goto P_0c08f31c;
P_0c08f31c: /* original e018, guest PC 0x0c08f31c */
if(!s->budget--) { s->failed_pc=0x0c08f31cu; return 0; }
r[0]=0x00000018u;
goto P_0c08f31e;
P_0c08f31e: /* original fee7, guest PC 0x0c08f31e */
if(!s->budget--) { s->failed_pc=0x0c08f31eu; return 0; }
vf3_matrix_store(s,ram,14,r[14]+r[0]);
goto P_0c08f320;
P_0c08f320: /* original fcf9, guest PC 0x0c08f320 */
if(!s->budget--) { s->failed_pc=0x0c08f320u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f322;
P_0c08f322: /* original d326, guest PC 0x0c08f322 */
if(!s->budget--) { s->failed_pc=0x0c08f322u; return 0; }
r[3]=read(ram,0x0c08f3bcu,4);
goto P_0c08f324;
P_0c08f324: /* original fdf9, guest PC 0x0c08f324 */
if(!s->budget--) { s->failed_pc=0x0c08f324u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f326;
P_0c08f326: /* original fef9, guest PC 0x0c08f326 */
if(!s->budget--) { s->failed_pc=0x0c08f326u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f328;
P_0c08f328: /* original fff9, guest PC 0x0c08f328 */
if(!s->budget--) { s->failed_pc=0x0c08f328u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08f32a;
P_0c08f32a: /* original 6df6, guest PC 0x0c08f32a */
if(!s->budget--) { s->failed_pc=0x0c08f32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08f32c;
P_0c08f32c: /* original 432b, guest PC 0x0c08f32c */
if(!s->budget--) { s->failed_pc=0x0c08f32cu; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03b450u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c08f32e: /* original 6ef6, guest PC 0x0c08f32e */
if(!s->budget--) { s->failed_pc=0x0c08f32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08f330u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f330u; return 0; } return 1;
P_0c08f4ae: /* original 5641, guest PC 0x0c08f4ae */
if(!s->budget--) { s->failed_pc=0x0c08f4aeu; return 0; }
r[6]=read(ram,r[4]+4,4);
goto P_0c08f4b0;
P_0c08f4b0: /* original 6752, guest PC 0x0c08f4b0 */
if(!s->budget--) { s->failed_pc=0x0c08f4b0u; return 0; }
tmp=read(ram,r[5],4);
r[7]=tmp;
goto P_0c08f4b2;
P_0c08f4b2: /* original 5061, guest PC 0x0c08f4b2 */
if(!s->budget--) { s->failed_pc=0x0c08f4b2u; return 0; }
r[0]=read(ram,r[6]+4,4);
goto P_0c08f4b4;
P_0c08f4b4: /* original 2672, guest PC 0x0c08f4b4 */
if(!s->budget--) { s->failed_pc=0x0c08f4b4u; return 0; }
write(ram,r[6],r[7],4);
goto P_0c08f4b6;
P_0c08f4b6: /* original 1651, guest PC 0x0c08f4b6 */
if(!s->budget--) { s->failed_pc=0x0c08f4b6u; return 0; }
write(ram,r[6]+4,r[5],4);
goto P_0c08f4b8;
P_0c08f4b8: /* original 2042, guest PC 0x0c08f4b8 */
if(!s->budget--) { s->failed_pc=0x0c08f4b8u; return 0; }
write(ram,r[0],r[4],4);
goto P_0c08f4ba;
P_0c08f4ba: /* original 1401, guest PC 0x0c08f4ba */
if(!s->budget--) { s->failed_pc=0x0c08f4bau; return 0; }
write(ram,r[4]+4,r[0],4);
goto P_0c08f4bc;
P_0c08f4bc: /* original 2562, guest PC 0x0c08f4bc */
if(!s->budget--) { s->failed_pc=0x0c08f4bcu; return 0; }
write(ram,r[5],r[6],4);
goto P_0c08f4be;
P_0c08f4be: /* original 000b, guest PC 0x0c08f4be */
if(!s->budget--) { s->failed_pc=0x0c08f4beu; return 0; }
target=r[16];
write(ram,r[7]+4,r[6],4);
s->pc=target; return ram->oob==0;
P_0c08f4c0: /* original 1761, guest PC 0x0c08f4c0 */
if(!s->budget--) { s->failed_pc=0x0c08f4c0u; return 0; }
write(ram,r[7]+4,r[6],4);
if(!vf3_matrix_family(0x0c08f4c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08f4c2u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
