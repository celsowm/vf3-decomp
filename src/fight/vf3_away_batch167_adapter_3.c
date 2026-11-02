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
int vf3_away_batch167_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c03e680u: goto P_0c03e680;
case 0x0c03e682u: goto P_0c03e682;
case 0x0c03e684u: goto P_0c03e684;
case 0x0c03e686u: goto P_0c03e686;
case 0x0c03e688u: goto P_0c03e688;
case 0x0c03e68au: goto P_0c03e68a;
case 0x0c03e68cu: goto P_0c03e68c;
case 0x0c03e68eu: goto P_0c03e68e;
case 0x0c03e690u: goto P_0c03e690;
case 0x0c03e692u: goto P_0c03e692;
case 0x0c03e694u: goto P_0c03e694;
case 0x0c03e696u: goto P_0c03e696;
case 0x0c03e698u: goto P_0c03e698;
case 0x0c03e69au: goto P_0c03e69a;
case 0x0c03e69cu: goto P_0c03e69c;
case 0x0c03e69eu: goto P_0c03e69e;
case 0x0c03e6a0u: goto P_0c03e6a0;
case 0x0c03e6a2u: goto P_0c03e6a2;
case 0x0c03e6a4u: goto P_0c03e6a4;
case 0x0c03e6a6u: goto P_0c03e6a6;
case 0x0c03e6a8u: goto P_0c03e6a8;
case 0x0c03e7f0u: goto P_0c03e7f0;
case 0x0c03e7f2u: goto P_0c03e7f2;
case 0x0c03e7f4u: goto P_0c03e7f4;
case 0x0c03e7f6u: goto P_0c03e7f6;
case 0x0c03e7f8u: goto P_0c03e7f8;
case 0x0c03e7fau: goto P_0c03e7fa;
case 0x0c03e7fcu: goto P_0c03e7fc;
case 0x0c03e7feu: goto P_0c03e7fe;
case 0x0c03e800u: goto P_0c03e800;
case 0x0c03e802u: goto P_0c03e802;
case 0x0c03e804u: goto P_0c03e804;
case 0x0c03e860u: goto P_0c03e860;
case 0x0c03e862u: goto P_0c03e862;
case 0x0c03e864u: goto P_0c03e864;
case 0x0c03e866u: goto P_0c03e866;
case 0x0c03e868u: goto P_0c03e868;
case 0x0c03e86au: goto P_0c03e86a;
case 0x0c03e86cu: goto P_0c03e86c;
case 0x0c03e86eu: goto P_0c03e86e;
case 0x0c03e870u: goto P_0c03e870;
case 0x0c03e872u: goto P_0c03e872;
case 0x0c03e874u: goto P_0c03e874;
case 0x0c03e876u: goto P_0c03e876;
case 0x0c03e878u: goto P_0c03e878;
case 0x0c03e87au: goto P_0c03e87a;
case 0x0c03e87cu: goto P_0c03e87c;
case 0x0c03e87eu: goto P_0c03e87e;
case 0x0c03e880u: goto P_0c03e880;
case 0x0c03e882u: goto P_0c03e882;
case 0x0c03e884u: goto P_0c03e884;
case 0x0c03e886u: goto P_0c03e886;
case 0x0c03e888u: goto P_0c03e888;
case 0x0c03ed50u: goto P_0c03ed50;
case 0x0c03ed52u: goto P_0c03ed52;
case 0x0c03ed54u: goto P_0c03ed54;
case 0x0c03ed56u: goto P_0c03ed56;
case 0x0c03ed58u: goto P_0c03ed58;
case 0x0c03ed60u: goto P_0c03ed60;
case 0x0c03ed62u: goto P_0c03ed62;
case 0x0c03ed64u: goto P_0c03ed64;
case 0x0c03ed66u: goto P_0c03ed66;
case 0x0c03ed68u: goto P_0c03ed68;
case 0x0c03ed6au: goto P_0c03ed6a;
case 0x0c03ed6cu: goto P_0c03ed6c;
case 0x0c03ed6eu: goto P_0c03ed6e;
case 0x0c03ed70u: goto P_0c03ed70;
case 0x0c03ed72u: goto P_0c03ed72;
case 0x0c03ed74u: goto P_0c03ed74;
case 0x0c03ed76u: goto P_0c03ed76;
case 0x0c03ed78u: goto P_0c03ed78;
case 0x0c03ed7au: goto P_0c03ed7a;
case 0x0c03ed7cu: goto P_0c03ed7c;
case 0x0c03eda0u: goto P_0c03eda0;
case 0x0c03eda2u: goto P_0c03eda2;
case 0x0c03eda4u: goto P_0c03eda4;
case 0x0c03eda6u: goto P_0c03eda6;
case 0x0c03eda8u: goto P_0c03eda8;
case 0x0c03edaau: goto P_0c03edaa;
case 0x0c03edacu: goto P_0c03edac;
case 0x0c03f0e0u: goto P_0c03f0e0;
case 0x0c03f0e2u: goto P_0c03f0e2;
case 0x0c03f0e4u: goto P_0c03f0e4;
case 0x0c03f0e6u: goto P_0c03f0e6;
case 0x0c03f0e8u: goto P_0c03f0e8;
case 0x0c03f0eau: goto P_0c03f0ea;
case 0x0c03f0ecu: goto P_0c03f0ec;
case 0x0c03f0eeu: goto P_0c03f0ee;
case 0x0c03f0f0u: goto P_0c03f0f0;
case 0x0c03f0f2u: goto P_0c03f0f2;
case 0x0c03f0f4u: goto P_0c03f0f4;
case 0x0c03f0f6u: goto P_0c03f0f6;
case 0x0c03f0f8u: goto P_0c03f0f8;
case 0x0c03f0fau: goto P_0c03f0fa;
case 0x0c03f0fcu: goto P_0c03f0fc;
case 0x0c03f0feu: goto P_0c03f0fe;
case 0x0c03f100u: goto P_0c03f100;
case 0x0c03f102u: goto P_0c03f102;
case 0x0c03f104u: goto P_0c03f104;
case 0x0c03f106u: goto P_0c03f106;
case 0x0c03f108u: goto P_0c03f108;
case 0x0c03f10au: goto P_0c03f10a;
case 0x0c03f10cu: goto P_0c03f10c;
case 0x0c03f10eu: goto P_0c03f10e;
case 0x0c03f110u: goto P_0c03f110;
case 0x0c03f112u: goto P_0c03f112;
case 0x0c03f114u: goto P_0c03f114;
case 0x0c03f116u: goto P_0c03f116;
case 0x0c03f118u: goto P_0c03f118;
case 0x0c03f11au: goto P_0c03f11a;
case 0x0c03f11cu: goto P_0c03f11c;
case 0x0c03f11eu: goto P_0c03f11e;
case 0x0c03f120u: goto P_0c03f120;
case 0x0c03f122u: goto P_0c03f122;
case 0x0c03f124u: goto P_0c03f124;
case 0x0c03f126u: goto P_0c03f126;
case 0x0c03f128u: goto P_0c03f128;
case 0x0c03f12au: goto P_0c03f12a;
case 0x0c03f12cu: goto P_0c03f12c;
case 0x0c03f12eu: goto P_0c03f12e;
case 0x0c03f130u: goto P_0c03f130;
case 0x0c03f132u: goto P_0c03f132;
case 0x0c03f134u: goto P_0c03f134;
case 0x0c03f136u: goto P_0c03f136;
case 0x0c03f138u: goto P_0c03f138;
case 0x0c03f13au: goto P_0c03f13a;
case 0x0c03f13cu: goto P_0c03f13c;
case 0x0c03f13eu: goto P_0c03f13e;
case 0x0c03f140u: goto P_0c03f140;
case 0x0c03f142u: goto P_0c03f142;
case 0x0c03f144u: goto P_0c03f144;
case 0x0c03f146u: goto P_0c03f146;
case 0x0c03f148u: goto P_0c03f148;
case 0x0c03f14au: goto P_0c03f14a;
case 0x0c03f14cu: goto P_0c03f14c;
case 0x0c03f14eu: goto P_0c03f14e;
case 0x0c03f150u: goto P_0c03f150;
case 0x0c03f152u: goto P_0c03f152;
case 0x0c03f154u: goto P_0c03f154;
case 0x0c03f156u: goto P_0c03f156;
case 0x0c03f158u: goto P_0c03f158;
case 0x0c03f15au: goto P_0c03f15a;
case 0x0c03f15cu: goto P_0c03f15c;
case 0x0c03f15eu: goto P_0c03f15e;
case 0x0c03f160u: goto P_0c03f160;
case 0x0c03f162u: goto P_0c03f162;
case 0x0c03f164u: goto P_0c03f164;
case 0x0c03f166u: goto P_0c03f166;
case 0x0c03f168u: goto P_0c03f168;
case 0x0c03f16au: goto P_0c03f16a;
case 0x0c03f16cu: goto P_0c03f16c;
case 0x0c03f16eu: goto P_0c03f16e;
case 0x0c03f170u: goto P_0c03f170;
case 0x0c03f172u: goto P_0c03f172;
case 0x0c03f174u: goto P_0c03f174;
case 0x0c03f176u: goto P_0c03f176;
case 0x0c03f178u: goto P_0c03f178;
case 0x0c03f17au: goto P_0c03f17a;
case 0x0c03f17cu: goto P_0c03f17c;
case 0x0c03f17eu: goto P_0c03f17e;
case 0x0c03f180u: goto P_0c03f180;
case 0x0c03f182u: goto P_0c03f182;
case 0x0c03f184u: goto P_0c03f184;
case 0x0c03f186u: goto P_0c03f186;
case 0x0c03f188u: goto P_0c03f188;
case 0x0c03f18au: goto P_0c03f18a;
case 0x0c03f18cu: goto P_0c03f18c;
case 0x0c03f18eu: goto P_0c03f18e;
case 0x0c03f190u: goto P_0c03f190;
case 0x0c03f192u: goto P_0c03f192;
case 0x0c03f194u: goto P_0c03f194;
case 0x0c03f196u: goto P_0c03f196;
case 0x0c03f198u: goto P_0c03f198;
case 0x0c03f19au: goto P_0c03f19a;
case 0x0c03f19cu: goto P_0c03f19c;
case 0x0c03f19eu: goto P_0c03f19e;
case 0x0c03f1a0u: goto P_0c03f1a0;
case 0x0c03f1a2u: goto P_0c03f1a2;
case 0x0c03f1a4u: goto P_0c03f1a4;
case 0x0c03f1a6u: goto P_0c03f1a6;
case 0x0c03f1a8u: goto P_0c03f1a8;
case 0x0c03f1aau: goto P_0c03f1aa;
case 0x0c03f1acu: goto P_0c03f1ac;
case 0x0c03f1aeu: goto P_0c03f1ae;
case 0x0c03f1b0u: goto P_0c03f1b0;
case 0x0c03f1b2u: goto P_0c03f1b2;
case 0x0c03f1b4u: goto P_0c03f1b4;
case 0x0c03f1b6u: goto P_0c03f1b6;
case 0x0c03f1b8u: goto P_0c03f1b8;
case 0x0c03f1bau: goto P_0c03f1ba;
case 0x0c03f1bcu: goto P_0c03f1bc;
case 0x0c03f1beu: goto P_0c03f1be;
case 0x0c03f1c0u: goto P_0c03f1c0;
case 0x0c03f1c2u: goto P_0c03f1c2;
case 0x0c03f1c4u: goto P_0c03f1c4;
case 0x0c03f1c6u: goto P_0c03f1c6;
case 0x0c03f1c8u: goto P_0c03f1c8;
case 0x0c03f1cau: goto P_0c03f1ca;
case 0x0c03f1ccu: goto P_0c03f1cc;
case 0x0c03f1ceu: goto P_0c03f1ce;
case 0x0c03f1d0u: goto P_0c03f1d0;
case 0x0c03f1d2u: goto P_0c03f1d2;
case 0x0c03f1d4u: goto P_0c03f1d4;
case 0x0c03f1d6u: goto P_0c03f1d6;
case 0x0c03f1d8u: goto P_0c03f1d8;
case 0x0c03f1dau: goto P_0c03f1da;
case 0x0c03f1e0u: goto P_0c03f1e0;
case 0x0c03f1e2u: goto P_0c03f1e2;
case 0x0c03f1e4u: goto P_0c03f1e4;
case 0x0c03f1e6u: goto P_0c03f1e6;
case 0x0c03f1e8u: goto P_0c03f1e8;
case 0x0c03f1eau: goto P_0c03f1ea;
case 0x0c03f1ecu: goto P_0c03f1ec;
case 0x0c03f1eeu: goto P_0c03f1ee;
case 0x0c03f1f0u: goto P_0c03f1f0;
case 0x0c03f1f2u: goto P_0c03f1f2;
case 0x0c03f1f4u: goto P_0c03f1f4;
case 0x0c03f1f6u: goto P_0c03f1f6;
case 0x0c03f1f8u: goto P_0c03f1f8;
case 0x0c03f1fau: goto P_0c03f1fa;
case 0x0c03f1fcu: goto P_0c03f1fc;
case 0x0c03f1feu: goto P_0c03f1fe;
case 0x0c03f200u: goto P_0c03f200;
case 0x0c03f202u: goto P_0c03f202;
case 0x0c03f204u: goto P_0c03f204;
case 0x0c03f206u: goto P_0c03f206;
case 0x0c03f208u: goto P_0c03f208;
case 0x0c03f20au: goto P_0c03f20a;
case 0x0c03f20cu: goto P_0c03f20c;
case 0x0c03f20eu: goto P_0c03f20e;
case 0x0c03f210u: goto P_0c03f210;
case 0x0c03f212u: goto P_0c03f212;
case 0x0c03f214u: goto P_0c03f214;
case 0x0c03f216u: goto P_0c03f216;
case 0x0c03f218u: goto P_0c03f218;
case 0x0c03f21au: goto P_0c03f21a;
case 0x0c03f21cu: goto P_0c03f21c;
case 0x0c03f21eu: goto P_0c03f21e;
case 0x0c03f220u: goto P_0c03f220;
case 0x0c03f222u: goto P_0c03f222;
case 0x0c03f224u: goto P_0c03f224;
case 0x0c03f226u: goto P_0c03f226;
case 0x0c03f228u: goto P_0c03f228;
case 0x0c03f22au: goto P_0c03f22a;
case 0x0c03f22cu: goto P_0c03f22c;
case 0x0c03f22eu: goto P_0c03f22e;
case 0x0c03f230u: goto P_0c03f230;
case 0x0c03f232u: goto P_0c03f232;
case 0x0c03f234u: goto P_0c03f234;
case 0x0c03f240u: goto P_0c03f240;
case 0x0c03f242u: goto P_0c03f242;
case 0x0c03f244u: goto P_0c03f244;
case 0x0c03f246u: goto P_0c03f246;
case 0x0c03f248u: goto P_0c03f248;
case 0x0c03f24au: goto P_0c03f24a;
case 0x0c03f24cu: goto P_0c03f24c;
case 0x0c03f24eu: goto P_0c03f24e;
case 0x0c03f250u: goto P_0c03f250;
case 0x0c03f252u: goto P_0c03f252;
case 0x0c03f254u: goto P_0c03f254;
case 0x0c03f256u: goto P_0c03f256;
case 0x0c03f258u: goto P_0c03f258;
case 0x0c03f25au: goto P_0c03f25a;
case 0x0c03f25cu: goto P_0c03f25c;
case 0x0c03f25eu: goto P_0c03f25e;
case 0x0c03f260u: goto P_0c03f260;
case 0x0c03f262u: goto P_0c03f262;
case 0x0c03f264u: goto P_0c03f264;
case 0x0c03f266u: goto P_0c03f266;
case 0x0c03f268u: goto P_0c03f268;
case 0x0c03f26au: goto P_0c03f26a;
case 0x0c03f26cu: goto P_0c03f26c;
case 0x0c03f26eu: goto P_0c03f26e;
case 0x0c03f270u: goto P_0c03f270;
case 0x0c03f272u: goto P_0c03f272;
case 0x0c03f274u: goto P_0c03f274;
case 0x0c03f276u: goto P_0c03f276;
case 0x0c03f278u: goto P_0c03f278;
case 0x0c03f27au: goto P_0c03f27a;
case 0x0c03f27cu: goto P_0c03f27c;
case 0x0c03f27eu: goto P_0c03f27e;
case 0x0c03f280u: goto P_0c03f280;
case 0x0c03f282u: goto P_0c03f282;
case 0x0c03f284u: goto P_0c03f284;
case 0x0c03f290u: goto P_0c03f290;
case 0x0c03f292u: goto P_0c03f292;
case 0x0c03f294u: goto P_0c03f294;
case 0x0c03f296u: goto P_0c03f296;
case 0x0c03f298u: goto P_0c03f298;
case 0x0c03f29au: goto P_0c03f29a;
case 0x0c03f29cu: goto P_0c03f29c;
case 0x0c03f29eu: goto P_0c03f29e;
case 0x0c03f2a0u: goto P_0c03f2a0;
case 0x0c03f2a2u: goto P_0c03f2a2;
case 0x0c03f2a4u: goto P_0c03f2a4;
case 0x0c03f2a6u: goto P_0c03f2a6;
case 0x0c03f2a8u: goto P_0c03f2a8;
case 0x0c03f2aau: goto P_0c03f2aa;
case 0x0c03f2acu: goto P_0c03f2ac;
case 0x0c03f2aeu: goto P_0c03f2ae;
case 0x0c03f2b0u: goto P_0c03f2b0;
case 0x0c03f2b2u: goto P_0c03f2b2;
case 0x0c03f2b4u: goto P_0c03f2b4;
case 0x0c03f2b6u: goto P_0c03f2b6;
case 0x0c03f2b8u: goto P_0c03f2b8;
case 0x0c03f2bau: goto P_0c03f2ba;
case 0x0c03f2bcu: goto P_0c03f2bc;
case 0x0c03f2beu: goto P_0c03f2be;
case 0x0c03f2c0u: goto P_0c03f2c0;
case 0x0c03f2c2u: goto P_0c03f2c2;
case 0x0c03f2c4u: goto P_0c03f2c4;
case 0x0c03f2c6u: goto P_0c03f2c6;
case 0x0c03f2c8u: goto P_0c03f2c8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c03e680: /* original 2fe6, guest PC 0x0c03e680 */
if(!s->budget--) { s->failed_pc=0x0c03e680u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03e682;
P_0c03e682: /* original e044, guest PC 0x0c03e682 */
if(!s->budget--) { s->failed_pc=0x0c03e682u; return 0; }
r[0]=0x00000044u;
goto P_0c03e684;
P_0c03e684: /* original 9e57, guest PC 0x0c03e684 */
if(!s->budget--) { s->failed_pc=0x0c03e684u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e736u,2);
goto P_0c03e686;
P_0c03e686: /* original 4f12, guest PC 0x0c03e686 */
if(!s->budget--) { s->failed_pc=0x0c03e686u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e688;
P_0c03e688: /* original 24ef, guest PC 0x0c03e688 */
if(!s->budget--) { s->failed_pc=0x0c03e688u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[14]);
goto P_0c03e68a;
P_0c03e68a: /* original d32c, guest PC 0x0c03e68a */
if(!s->budget--) { s->failed_pc=0x0c03e68au; return 0; }
r[3]=read(ram,0x0c03e73cu,4);
goto P_0c03e68c;
P_0c03e68c: /* original 0e1a, guest PC 0x0c03e68c */
if(!s->budget--) { s->failed_pc=0x0c03e68cu; return 0; }
r[14]=r[19];
goto P_0c03e68e;
P_0c03e68e: /* original 4f16, guest PC 0x0c03e68e */
if(!s->budget--) { s->failed_pc=0x0c03e68eu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03e690;
P_0c03e690: /* original 6eef, guest PC 0x0c03e690 */
if(!s->budget--) { s->failed_pc=0x0c03e690u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)r[14];
goto P_0c03e692;
P_0c03e692: /* original 3e3c, guest PC 0x0c03e692 */
if(!s->budget--) { s->failed_pc=0x0c03e692u; return 0; }
r[14]+=r[3];
goto P_0c03e694;
P_0c03e694: /* original 62e3, guest PC 0x0c03e694 */
if(!s->budget--) { s->failed_pc=0x0c03e694u; return 0; }
r[2]=r[14];
goto P_0c03e696;
P_0c03e696: /* original 7240, guest PC 0x0c03e696 */
if(!s->budget--) { s->failed_pc=0x0c03e696u; return 0; }
r[2]+=0x00000040u;
goto P_0c03e698;
P_0c03e698: /* original f24a, guest PC 0x0c03e698 */
if(!s->budget--) { s->failed_pc=0x0c03e698u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
goto P_0c03e69a;
P_0c03e69a: /* original 64e3, guest PC 0x0c03e69a */
if(!s->budget--) { s->failed_pc=0x0c03e69au; return 0; }
r[4]=r[14];
goto P_0c03e69c;
P_0c03e69c: /* original fe57, guest PC 0x0c03e69c */
if(!s->budget--) { s->failed_pc=0x0c03e69cu; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c03e69e;
P_0c03e69e: /* original e048, guest PC 0x0c03e69e */
if(!s->budget--) { s->failed_pc=0x0c03e69eu; return 0; }
r[0]=0x00000048u;
goto P_0c03e6a0;
P_0c03e6a0: /* original fe67, guest PC 0x0c03e6a0 */
if(!s->budget--) { s->failed_pc=0x0c03e6a0u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c03e6a2;
P_0c03e6a2: /* original 7440, guest PC 0x0c03e6a2 */
if(!s->budget--) { s->failed_pc=0x0c03e6a2u; return 0; }
r[4]+=0x00000040u;
goto P_0c03e6a4;
P_0c03e6a4: /* original d22a, guest PC 0x0c03e6a4 */
if(!s->budget--) { s->failed_pc=0x0c03e6a4u; return 0; }
r[2]=read(ram,0x0c03e750u,4);
goto P_0c03e6a6;
P_0c03e6a6: /* original 422b, guest PC 0x0c03e6a6 */
if(!s->budget--) { s->failed_pc=0x0c03e6a6u; return 0; }
target=r[2];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
code_base=target&0xff000000u;
switch(target&0x1fffffffu) {
case 0x0c03d040u: return vf3_matrix_family(0x0c03d040u,s,ram);
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
P_0c03e6a8: /* original 6ef6, guest PC 0x0c03e6a8 */
if(!s->budget--) { s->failed_pc=0x0c03e6a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03e6aau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e6aau; return 0; } return 1;
P_0c03e7f0: /* original 934b, guest PC 0x0c03e7f0 */
if(!s->budget--) { s->failed_pc=0x0c03e7f0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e7f2;
P_0c03e7f2: /* original 6053, guest PC 0x0c03e7f2 */
if(!s->budget--) { s->failed_pc=0x0c03e7f2u; return 0; }
r[0]=r[5];
goto P_0c03e7f4;
P_0c03e7f4: /* original 4f12, guest PC 0x0c03e7f4 */
if(!s->budget--) { s->failed_pc=0x0c03e7f4u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e7f6;
P_0c03e7f6: /* original 243f, guest PC 0x0c03e7f6 */
if(!s->budget--) { s->failed_pc=0x0c03e7f6u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e7f8;
P_0c03e7f8: /* original d225, guest PC 0x0c03e7f8 */
if(!s->budget--) { s->failed_pc=0x0c03e7f8u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e7fa;
P_0c03e7fa: /* original 041a, guest PC 0x0c03e7fa */
if(!s->budget--) { s->failed_pc=0x0c03e7fau; return 0; }
r[4]=r[19];
goto P_0c03e7fc;
P_0c03e7fc: /* original 644f, guest PC 0x0c03e7fc */
if(!s->budget--) { s->failed_pc=0x0c03e7fcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e7fe;
P_0c03e7fe: /* original 342c, guest PC 0x0c03e7fe */
if(!s->budget--) { s->failed_pc=0x0c03e7feu; return 0; }
r[4]+=r[2];
goto P_0c03e800;
P_0c03e800: /* original 8141, guest PC 0x0c03e800 */
if(!s->budget--) { s->failed_pc=0x0c03e800u; return 0; }
write(ram,r[4]+2,r[0],2);
goto P_0c03e802;
P_0c03e802: /* original 000b, guest PC 0x0c03e802 */
if(!s->budget--) { s->failed_pc=0x0c03e802u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e804: /* original 4f16, guest PC 0x0c03e804 */
if(!s->budget--) { s->failed_pc=0x0c03e804u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03e806u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e806u; return 0; } return 1;
P_0c03e860: /* original 9313, guest PC 0x0c03e860 */
if(!s->budget--) { s->failed_pc=0x0c03e860u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c03e88au,2);
goto P_0c03e862;
P_0c03e862: /* original e014, guest PC 0x0c03e862 */
if(!s->budget--) { s->failed_pc=0x0c03e862u; return 0; }
r[0]=0x00000014u;
goto P_0c03e864;
P_0c03e864: /* original 4f12, guest PC 0x0c03e864 */
if(!s->budget--) { s->failed_pc=0x0c03e864u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03e866;
P_0c03e866: /* original 243f, guest PC 0x0c03e866 */
if(!s->budget--) { s->failed_pc=0x0c03e866u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c03e868;
P_0c03e868: /* original d209, guest PC 0x0c03e868 */
if(!s->budget--) { s->failed_pc=0x0c03e868u; return 0; }
r[2]=read(ram,0x0c03e890u,4);
goto P_0c03e86a;
P_0c03e86a: /* original f359, guest PC 0x0c03e86a */
if(!s->budget--) { s->failed_pc=0x0c03e86au; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e86c;
P_0c03e86c: /* original 041a, guest PC 0x0c03e86c */
if(!s->budget--) { s->failed_pc=0x0c03e86cu; return 0; }
r[4]=r[19];
goto P_0c03e86e;
P_0c03e86e: /* original 644f, guest PC 0x0c03e86e */
if(!s->budget--) { s->failed_pc=0x0c03e86eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c03e870;
P_0c03e870: /* original 342c, guest PC 0x0c03e870 */
if(!s->budget--) { s->failed_pc=0x0c03e870u; return 0; }
r[4]+=r[2];
goto P_0c03e872;
P_0c03e872: /* original f437, guest PC 0x0c03e872 */
if(!s->budget--) { s->failed_pc=0x0c03e872u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e874;
P_0c03e874: /* original e018, guest PC 0x0c03e874 */
if(!s->budget--) { s->failed_pc=0x0c03e874u; return 0; }
r[0]=0x00000018u;
goto P_0c03e876;
P_0c03e876: /* original f359, guest PC 0x0c03e876 */
if(!s->budget--) { s->failed_pc=0x0c03e876u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e878;
P_0c03e878: /* original f437, guest PC 0x0c03e878 */
if(!s->budget--) { s->failed_pc=0x0c03e878u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e87a;
P_0c03e87a: /* original e01c, guest PC 0x0c03e87a */
if(!s->budget--) { s->failed_pc=0x0c03e87au; return 0; }
r[0]=0x0000001cu;
goto P_0c03e87c;
P_0c03e87c: /* original f359, guest PC 0x0c03e87c */
if(!s->budget--) { s->failed_pc=0x0c03e87cu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
r[5]+=(r[18]&0x100000u)?8:4;
goto P_0c03e87e;
P_0c03e87e: /* original f437, guest PC 0x0c03e87e */
if(!s->budget--) { s->failed_pc=0x0c03e87eu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e880;
P_0c03e880: /* original e020, guest PC 0x0c03e880 */
if(!s->budget--) { s->failed_pc=0x0c03e880u; return 0; }
r[0]=0x00000020u;
goto P_0c03e882;
P_0c03e882: /* original f358, guest PC 0x0c03e882 */
if(!s->budget--) { s->failed_pc=0x0c03e882u; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c03e884;
P_0c03e884: /* original f437, guest PC 0x0c03e884 */
if(!s->budget--) { s->failed_pc=0x0c03e884u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c03e886;
P_0c03e886: /* original 000b, guest PC 0x0c03e886 */
if(!s->budget--) { s->failed_pc=0x0c03e886u; return 0; }
target=r[16];
r[19]=read(ram,r[15],4); r[15]+=4;
s->pc=target; return ram->oob==0;
P_0c03e888: /* original 4f16, guest PC 0x0c03e888 */
if(!s->budget--) { s->failed_pc=0x0c03e888u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
if(!vf3_matrix_family(0x0c03e88au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03e88au; return 0; } return 1;
P_0c03ed50: /* original d33d, guest PC 0x0c03ed50 */
if(!s->budget--) { s->failed_pc=0x0c03ed50u; return 0; }
r[3]=read(ram,0x0c03ee48u,4);
goto P_0c03ed52;
P_0c03ed52: /* original f34a, guest PC 0x0c03ed52 */
if(!s->budget--) { s->failed_pc=0x0c03ed52u; return 0; }
vf3_matrix_store(s,ram,4,r[3]);
goto P_0c03ed54;
P_0c03ed54: /* original d23d, guest PC 0x0c03ed54 */
if(!s->budget--) { s->failed_pc=0x0c03ed54u; return 0; }
r[2]=read(ram,0x0c03ee4cu,4);
goto P_0c03ed56;
P_0c03ed56: /* original 000b, guest PC 0x0c03ed56 */
if(!s->budget--) { s->failed_pc=0x0c03ed56u; return 0; }
target=r[16];
vf3_matrix_store(s,ram,4,r[2]);
s->pc=target; return ram->oob==0;
P_0c03ed58: /* original f24a, guest PC 0x0c03ed58 */
if(!s->budget--) { s->failed_pc=0x0c03ed58u; return 0; }
vf3_matrix_store(s,ram,4,r[2]);
if(!vf3_matrix_family(0x0c03ed5au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ed5au; return 0; } return 1;
P_0c03ed60: /* original e004, guest PC 0x0c03ed60 */
if(!s->budget--) { s->failed_pc=0x0c03ed60u; return 0; }
r[0]=0x00000004u;
goto P_0c03ed62;
P_0c03ed62: /* original d540, guest PC 0x0c03ed62 */
if(!s->budget--) { s->failed_pc=0x0c03ed62u; return 0; }
r[5]=read(ram,0x0c03ee64u,4);
goto P_0c03ed64;
P_0c03ed64: /* original f348, guest PC 0x0c03ed64 */
if(!s->budget--) { s->failed_pc=0x0c03ed64u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c03ed66;
P_0c03ed66: /* original f53a, guest PC 0x0c03ed66 */
if(!s->budget--) { s->failed_pc=0x0c03ed66u; return 0; }
vf3_matrix_store(s,ram,3,r[5]);
goto P_0c03ed68;
P_0c03ed68: /* original f246, guest PC 0x0c03ed68 */
if(!s->budget--) { s->failed_pc=0x0c03ed68u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c03ed6a;
P_0c03ed6a: /* original f527, guest PC 0x0c03ed6a */
if(!s->budget--) { s->failed_pc=0x0c03ed6au; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
goto P_0c03ed6c;
P_0c03ed6c: /* original e008, guest PC 0x0c03ed6c */
if(!s->budget--) { s->failed_pc=0x0c03ed6cu; return 0; }
r[0]=0x00000008u;
goto P_0c03ed6e;
P_0c03ed6e: /* original f346, guest PC 0x0c03ed6e */
if(!s->budget--) { s->failed_pc=0x0c03ed6eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c03ed70;
P_0c03ed70: /* original f537, guest PC 0x0c03ed70 */
if(!s->budget--) { s->failed_pc=0x0c03ed70u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c03ed72;
P_0c03ed72: /* original f246, guest PC 0x0c03ed72 */
if(!s->budget--) { s->failed_pc=0x0c03ed72u; return 0; }
vf3_matrix_load(s,ram,2,r[4]+r[0]);
goto P_0c03ed74;
P_0c03ed74: /* original e00c, guest PC 0x0c03ed74 */
if(!s->budget--) { s->failed_pc=0x0c03ed74u; return 0; }
r[0]=0x0000000cu;
goto P_0c03ed76;
P_0c03ed76: /* original f39d, guest PC 0x0c03ed76 */
if(!s->budget--) { s->failed_pc=0x0c03ed76u; return 0; }
fr[3]=0x3f800000u;
goto P_0c03ed78;
P_0c03ed78: /* original f230, guest PC 0x0c03ed78 */
if(!s->budget--) { s->failed_pc=0x0c03ed78u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c03ed7a;
P_0c03ed7a: /* original 000b, guest PC 0x0c03ed7a */
if(!s->budget--) { s->failed_pc=0x0c03ed7au; return 0; }
target=r[16];
vf3_matrix_store(s,ram,2,r[5]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03ed7c: /* original f527, guest PC 0x0c03ed7c */
if(!s->budget--) { s->failed_pc=0x0c03ed7cu; return 0; }
vf3_matrix_store(s,ram,2,r[5]+r[0]);
if(!vf3_matrix_family(0x0c03ed7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03ed7eu; return 0; } return 1;
P_0c03eda0: /* original d431, guest PC 0x0c03eda0 */
if(!s->budget--) { s->failed_pc=0x0c03eda0u; return 0; }
r[4]=read(ram,0x0c03ee68u,4);
goto P_0c03eda2;
P_0c03eda2: /* original e004, guest PC 0x0c03eda2 */
if(!s->budget--) { s->failed_pc=0x0c03eda2u; return 0; }
r[0]=0x00000004u;
goto P_0c03eda4;
P_0c03eda4: /* original f44a, guest PC 0x0c03eda4 */
if(!s->budget--) { s->failed_pc=0x0c03eda4u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c03eda6;
P_0c03eda6: /* original f457, guest PC 0x0c03eda6 */
if(!s->budget--) { s->failed_pc=0x0c03eda6u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c03eda8;
P_0c03eda8: /* original e008, guest PC 0x0c03eda8 */
if(!s->budget--) { s->failed_pc=0x0c03eda8u; return 0; }
r[0]=0x00000008u;
goto P_0c03edaa;
P_0c03edaa: /* original 000b, guest PC 0x0c03edaa */
if(!s->budget--) { s->failed_pc=0x0c03edaau; return 0; }
target=r[16];
vf3_matrix_store(s,ram,6,r[4]+r[0]);
s->pc=target; return ram->oob==0;
P_0c03edac: /* original f467, guest PC 0x0c03edac */
if(!s->budget--) { s->failed_pc=0x0c03edacu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
if(!vf3_matrix_family(0x0c03edaeu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03edaeu; return 0; } return 1;
P_0c03f0e0: /* original 2fe6, guest PC 0x0c03f0e0 */
if(!s->budget--) { s->failed_pc=0x0c03f0e0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0e2;
P_0c03f0e2: /* original e300, guest PC 0x0c03f0e2 */
if(!s->budget--) { s->failed_pc=0x0c03f0e2u; return 0; }
r[3]=0x00000000u;
goto P_0c03f0e4;
P_0c03f0e4: /* original 2fd6, guest PC 0x0c03f0e4 */
if(!s->budget--) { s->failed_pc=0x0c03f0e4u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0e6;
P_0c03f0e6: /* original 2fc6, guest PC 0x0c03f0e6 */
if(!s->budget--) { s->failed_pc=0x0c03f0e6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0e8;
P_0c03f0e8: /* original 2fb6, guest PC 0x0c03f0e8 */
if(!s->budget--) { s->failed_pc=0x0c03f0e8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0ea;
P_0c03f0ea: /* original eb01, guest PC 0x0c03f0ea */
if(!s->budget--) { s->failed_pc=0x0c03f0eau; return 0; }
r[11]=0x00000001u;
goto P_0c03f0ec;
P_0c03f0ec: /* original 2fa6, guest PC 0x0c03f0ec */
if(!s->budget--) { s->failed_pc=0x0c03f0ecu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0ee;
P_0c03f0ee: /* original 2f96, guest PC 0x0c03f0ee */
if(!s->budget--) { s->failed_pc=0x0c03f0eeu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0f0;
P_0c03f0f0: /* original 2f86, guest PC 0x0c03f0f0 */
if(!s->budget--) { s->failed_pc=0x0c03f0f0u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f0f2;
P_0c03f0f2: /* original fffb, guest PC 0x0c03f0f2 */
if(!s->budget--) { s->failed_pc=0x0c03f0f2u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c03f0f4;
P_0c03f0f4: /* original 4f22, guest PC 0x0c03f0f4 */
if(!s->budget--) { s->failed_pc=0x0c03f0f4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c03f0f6;
P_0c03f0f6: /* original 4f12, guest PC 0x0c03f0f6 */
if(!s->budget--) { s->failed_pc=0x0c03f0f6u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c03f0f8;
P_0c03f0f8: /* original 7ff0, guest PC 0x0c03f0f8 */
if(!s->budget--) { s->failed_pc=0x0c03f0f8u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c03f0fa;
P_0c03f0fa: /* original 1f52, guest PC 0x0c03f0fa */
if(!s->budget--) { s->failed_pc=0x0c03f0fau; return 0; }
write(ram,r[15]+8,r[5],4);
goto P_0c03f0fc;
P_0c03f0fc: /* original 1fb3, guest PC 0x0c03f0fc */
if(!s->budget--) { s->failed_pc=0x0c03f0fcu; return 0; }
write(ram,r[15]+12,r[11],4);
goto P_0c03f0fe;
P_0c03f0fe: /* original 1f31, guest PC 0x0c03f0fe */
if(!s->budget--) { s->failed_pc=0x0c03f0feu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c03f100;
P_0c03f100: /* original 6242, guest PC 0x0c03f100 */
if(!s->budget--) { s->failed_pc=0x0c03f100u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c03f102;
P_0c03f102: /* original 4211, guest PC 0x0c03f102 */
if(!s->budget--) { s->failed_pc=0x0c03f102u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c03f104;
P_0c03f104: /* original 8b02, guest PC 0x0c03f104 */
if(!s->budget--) { s->failed_pc=0x0c03f104u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f10c; }
goto P_0c03f106;
P_0c03f106: /* original 5146, guest PC 0x0c03f106 */
if(!s->budget--) { s->failed_pc=0x0c03f106u; return 0; }
r[1]=read(ram,r[4]+24,4);
goto P_0c03f108;
P_0c03f108: /* original 2118, guest PC 0x0c03f108 */
if(!s->budget--) { s->failed_pc=0x0c03f108u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f10a;
P_0c03f10a: /* original 8b01, guest PC 0x0c03f10a */
if(!s->budget--) { s->failed_pc=0x0c03f10au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f110; }
goto P_0c03f10c;
P_0c03f10c: /* original a0d1, guest PC 0x0c03f10c */
if(!s->budget--) { s->failed_pc=0x0c03f10cu; return 0; }
r[0]=0x00000000u;
goto P_0c03f2b2;
P_0c03f10e: /* original e000, guest PC 0x0c03f10e */
if(!s->budget--) { s->failed_pc=0x0c03f10eu; return 0; }
r[0]=0x00000000u;
goto P_0c03f110;
P_0c03f110: /* original c77a, guest PC 0x0c03f110 */
if(!s->budget--) { s->failed_pc=0x0c03f110u; return 0; }
r[0]=code_base|0x0003f2fcu;
goto P_0c03f112;
P_0c03f112: /* original d97b, guest PC 0x0c03f112 */
if(!s->budget--) { s->failed_pc=0x0c03f112u; return 0; }
r[9]=read(ram,0x0c03f300u,4);
goto P_0c03f114;
P_0c03f114: /* original ff08, guest PC 0x0c03f114 */
if(!s->budget--) { s->failed_pc=0x0c03f114u; return 0; }
vf3_matrix_load(s,ram,15,r[0]);
goto P_0c03f116;
P_0c03f116: /* original 6843, guest PC 0x0c03f116 */
if(!s->budget--) { s->failed_pc=0x0c03f116u; return 0; }
r[8]=r[4];
goto P_0c03f118;
P_0c03f118: /* original 7818, guest PC 0x0c03f118 */
if(!s->budget--) { s->failed_pc=0x0c03f118u; return 0; }
r[8]+=0x00000018u;
goto P_0c03f11a;
P_0c03f11a: /* original 6e83, guest PC 0x0c03f11a */
if(!s->budget--) { s->failed_pc=0x0c03f11au; return 0; }
r[14]=r[8];
goto P_0c03f11c;
P_0c03f11c: /* original 5ae8, guest PC 0x0c03f11c */
if(!s->budget--) { s->failed_pc=0x0c03f11cu; return 0; }
r[10]=read(ram,r[14]+32,4);
goto P_0c03f11e;
P_0c03f11e: /* original 6da3, guest PC 0x0c03f11e */
if(!s->budget--) { s->failed_pc=0x0c03f11eu; return 0; }
r[13]=r[10];
goto P_0c03f120;
P_0c03f120: /* original 4d11, guest PC 0x0c03f120 */
if(!s->budget--) { s->failed_pc=0x0c03f120u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c03f122;
P_0c03f122: /* original 8f3a, guest PC 0x0c03f122 */
if(!s->budget--) { s->failed_pc=0x0c03f122u; return 0; }
cond=r[17]&1u;
r[8]+=0x00000050u;
if(!cond) { goto P_0c03f19a; }
goto P_0c03f126;
P_0c03f124: /* original 7850, guest PC 0x0c03f124 */
if(!s->budget--) { s->failed_pc=0x0c03f124u; return 0; }
r[8]+=0x00000050u;
goto P_0c03f126;
P_0c03f126: /* original d273, guest PC 0x0c03f126 */
if(!s->budget--) { s->failed_pc=0x0c03f126u; return 0; }
r[2]=read(ram,0x0c03f2f4u,4);
goto P_0c03f128;
P_0c03f128: /* original 6192, guest PC 0x0c03f128 */
if(!s->budget--) { s->failed_pc=0x0c03f128u; return 0; }
tmp=read(ram,r[9],4);
r[1]=tmp;
goto P_0c03f12a;
P_0c03f12a: /* original 6322, guest PC 0x0c03f12a */
if(!s->budget--) { s->failed_pc=0x0c03f12au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f12c;
P_0c03f12c: /* original 3d3c, guest PC 0x0c03f12c */
if(!s->budget--) { s->failed_pc=0x0c03f12cu; return 0; }
r[13]+=r[3];
goto P_0c03f12e;
P_0c03f12e: /* original 6cd3, guest PC 0x0c03f12e */
if(!s->budget--) { s->failed_pc=0x0c03f12eu; return 0; }
r[12]=r[13];
goto P_0c03f130;
P_0c03f130: /* original 4c08, guest PC 0x0c03f130 */
if(!s->budget--) { s->failed_pc=0x0c03f130u; return 0; }
r[12]<<=2;
goto P_0c03f132;
P_0c03f132: /* original 4c00, guest PC 0x0c03f132 */
if(!s->budget--) { s->failed_pc=0x0c03f132u; return 0; }
r[17]=(r[17]&~1u)|((r[12]>>31)!=0);
r[12]<<=1;
goto P_0c03f134;
P_0c03f134: /* original 31cc, guest PC 0x0c03f134 */
if(!s->budget--) { s->failed_pc=0x0c03f134u; return 0; }
r[1]+=r[12];
goto P_0c03f136;
P_0c03f136: /* original 6012, guest PC 0x0c03f136 */
if(!s->budget--) { s->failed_pc=0x0c03f136u; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c03f138;
P_0c03f138: /* original 2008, guest PC 0x0c03f138 */
if(!s->budget--) { s->failed_pc=0x0c03f138u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f13a;
P_0c03f13a: /* original 8b08, guest PC 0x0c03f13a */
if(!s->budget--) { s->failed_pc=0x0c03f13au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f14e; }
goto P_0c03f13c;
P_0c03f13c: /* original 6392, guest PC 0x0c03f13c */
if(!s->budget--) { s->failed_pc=0x0c03f13cu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f13e;
P_0c03f13e: /* original e204, guest PC 0x0c03f13e */
if(!s->budget--) { s->failed_pc=0x0c03f13eu; return 0; }
r[2]=0x00000004u;
goto P_0c03f140;
P_0c03f140: /* original d170, guest PC 0x0c03f140 */
if(!s->budget--) { s->failed_pc=0x0c03f140u; return 0; }
r[1]=read(ram,0x0c03f304u,4);
goto P_0c03f142;
P_0c03f142: /* original 33cc, guest PC 0x0c03f142 */
if(!s->budget--) { s->failed_pc=0x0c03f142u; return 0; }
r[3]+=r[12];
goto P_0c03f144;
P_0c03f144: /* original 323c, guest PC 0x0c03f144 */
if(!s->budget--) { s->failed_pc=0x0c03f144u; return 0; }
r[2]+=r[3];
goto P_0c03f146;
P_0c03f146: /* original 410b, guest PC 0x0c03f146 */
if(!s->budget--) { s->failed_pc=0x0c03f146u; return 0; }
target=r[1];
r[16]=code_base|0x0c03f14au;
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f14au) { target=s->pc; goto dispatch; }
goto P_0c03f14a;
P_0c03f148: /* original 2f26, guest PC 0x0c03f148 */
if(!s->budget--) { s->failed_pc=0x0c03f148u; return 0; }
tmp=r[2]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c03f14a;
P_0c03f14a: /* original 61f6, guest PC 0x0c03f14a */
if(!s->budget--) { s->failed_pc=0x0c03f14au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c03f14c;
P_0c03f14c: /* original 2102, guest PC 0x0c03f14c */
if(!s->budget--) { s->failed_pc=0x0c03f14cu; return 0; }
write(ram,r[1],r[0],4);
goto P_0c03f14e;
P_0c03f14e: /* original 6392, guest PC 0x0c03f14e */
if(!s->budget--) { s->failed_pc=0x0c03f14eu; return 0; }
tmp=read(ram,r[9],4);
r[3]=tmp;
goto P_0c03f150;
P_0c03f150: /* original 33cc, guest PC 0x0c03f150 */
if(!s->budget--) { s->failed_pc=0x0c03f150u; return 0; }
r[3]+=r[12];
goto P_0c03f152;
P_0c03f152: /* original 6232, guest PC 0x0c03f152 */
if(!s->budget--) { s->failed_pc=0x0c03f152u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c03f154;
P_0c03f154: /* original 7201, guest PC 0x0c03f154 */
if(!s->budget--) { s->failed_pc=0x0c03f154u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f156;
P_0c03f156: /* original 2322, guest PC 0x0c03f156 */
if(!s->budget--) { s->failed_pc=0x0c03f156u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c03f158;
P_0c03f158: /* original 6d92, guest PC 0x0c03f158 */
if(!s->budget--) { s->failed_pc=0x0c03f158u; return 0; }
tmp=read(ram,r[9],4);
r[13]=tmp;
goto P_0c03f15a;
P_0c03f15a: /* original d26b, guest PC 0x0c03f15a */
if(!s->budget--) { s->failed_pc=0x0c03f15au; return 0; }
r[2]=read(ram,0x0c03f308u,4);
goto P_0c03f15c;
P_0c03f15c: /* original 3dcc, guest PC 0x0c03f15c */
if(!s->budget--) { s->failed_pc=0x0c03f15cu; return 0; }
r[13]+=r[12];
goto P_0c03f15e;
P_0c03f15e: /* original 5dd1, guest PC 0x0c03f15e */
if(!s->budget--) { s->failed_pc=0x0c03f15eu; return 0; }
r[13]=read(ram,r[13]+4,4);
goto P_0c03f160;
P_0c03f160: /* original ec3c, guest PC 0x0c03f160 */
if(!s->budget--) { s->failed_pc=0x0c03f160u; return 0; }
r[12]=0x0000003cu;
goto P_0c03f162;
P_0c03f162: /* original 6322, guest PC 0x0c03f162 */
if(!s->budget--) { s->failed_pc=0x0c03f162u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c03f164;
P_0c03f164: /* original 0dc7, guest PC 0x0c03f164 */
if(!s->budget--) { s->failed_pc=0x0c03f164u; return 0; }
r[19]=r[13]*r[12];
goto P_0c03f166;
P_0c03f166: /* original 0c1a, guest PC 0x0c03f166 */
if(!s->budget--) { s->failed_pc=0x0c03f166u; return 0; }
r[12]=r[19];
goto P_0c03f168;
P_0c03f168: /* original 3c3c, guest PC 0x0c03f168 */
if(!s->budget--) { s->failed_pc=0x0c03f168u; return 0; }
r[12]+=r[3];
goto P_0c03f16a;
P_0c03f16a: /* original 51cb, guest PC 0x0c03f16a */
if(!s->budget--) { s->failed_pc=0x0c03f16au; return 0; }
r[1]=read(ram,r[12]+44,4);
goto P_0c03f16c;
P_0c03f16c: /* original 2118, guest PC 0x0c03f16c */
if(!s->budget--) { s->failed_pc=0x0c03f16cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c03f16e;
P_0c03f16e: /* original 8b11, guest PC 0x0c03f16e */
if(!s->budget--) { s->failed_pc=0x0c03f16eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f194; }
goto P_0c03f170;
P_0c03f170: /* original 61a3, guest PC 0x0c03f170 */
if(!s->budget--) { s->failed_pc=0x0c03f170u; return 0; }
r[1]=r[10];
goto P_0c03f172;
P_0c03f172: /* original 53f2, guest PC 0x0c03f172 */
if(!s->budget--) { s->failed_pc=0x0c03f172u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c03f174;
P_0c03f174: /* original 4108, guest PC 0x0c03f174 */
if(!s->budget--) { s->failed_pc=0x0c03f174u; return 0; }
r[1]<<=2;
goto P_0c03f176;
P_0c03f176: /* original 65d3, guest PC 0x0c03f176 */
if(!s->budget--) { s->failed_pc=0x0c03f176u; return 0; }
r[5]=r[13];
goto P_0c03f178;
P_0c03f178: /* original 4108, guest PC 0x0c03f178 */
if(!s->budget--) { s->failed_pc=0x0c03f178u; return 0; }
r[1]<<=2;
goto P_0c03f17a;
P_0c03f17a: /* original 313c, guest PC 0x0c03f17a */
if(!s->budget--) { s->failed_pc=0x0c03f17au; return 0; }
r[1]+=r[3];
goto P_0c03f17c;
P_0c03f17c: /* original 2f12, guest PC 0x0c03f17c */
if(!s->budget--) { s->failed_pc=0x0c03f17cu; return 0; }
write(ram,r[15],r[1],4);
goto P_0c03f17e;
P_0c03f17e: /* original d363, guest PC 0x0c03f17e */
if(!s->budget--) { s->failed_pc=0x0c03f17eu; return 0; }
r[3]=read(ram,0x0c03f30cu,4);
goto P_0c03f180;
P_0c03f180: /* original 5612, guest PC 0x0c03f180 */
if(!s->budget--) { s->failed_pc=0x0c03f180u; return 0; }
r[6]=read(ram,r[1]+8,4);
goto P_0c03f182;
P_0c03f182: /* original 430b, guest PC 0x0c03f182 */
if(!s->budget--) { s->failed_pc=0x0c03f182u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f186u;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f186u) { target=s->pc; goto dispatch; }
goto P_0c03f186;
P_0c03f184: /* original 6413, guest PC 0x0c03f184 */
if(!s->budget--) { s->failed_pc=0x0c03f184u; return 0; }
r[4]=r[1];
goto P_0c03f186;
P_0c03f186: /* original 52f1, guest PC 0x0c03f186 */
if(!s->budget--) { s->failed_pc=0x0c03f186u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c03f188;
P_0c03f188: /* original 220b, guest PC 0x0c03f188 */
if(!s->budget--) { s->failed_pc=0x0c03f188u; return 0; }
r[2]|=r[0];
goto P_0c03f18a;
P_0c03f18a: /* original 1f21, guest PC 0x0c03f18a */
if(!s->budget--) { s->failed_pc=0x0c03f18au; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c03f18c;
P_0c03f18c: /* original d360, guest PC 0x0c03f18c */
if(!s->budget--) { s->failed_pc=0x0c03f18cu; return 0; }
r[3]=read(ram,0x0c03f310u,4);
goto P_0c03f18e;
P_0c03f18e: /* original 430b, guest PC 0x0c03f18e */
if(!s->budget--) { s->failed_pc=0x0c03f18eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f192u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f192u) { target=s->pc; goto dispatch; }
goto P_0c03f192;
P_0c03f190: /* original 64d3, guest PC 0x0c03f190 */
if(!s->budget--) { s->failed_pc=0x0c03f190u; return 0; }
r[4]=r[13];
goto P_0c03f192;
P_0c03f192: /* original 1cde, guest PC 0x0c03f192 */
if(!s->budget--) { s->failed_pc=0x0c03f192u; return 0; }
write(ram,r[12]+56,r[13],4);
goto P_0c03f194;
P_0c03f194: /* original 52cb, guest PC 0x0c03f194 */
if(!s->budget--) { s->failed_pc=0x0c03f194u; return 0; }
r[2]=read(ram,r[12]+44,4);
goto P_0c03f196;
P_0c03f196: /* original 7201, guest PC 0x0c03f196 */
if(!s->budget--) { s->failed_pc=0x0c03f196u; return 0; }
r[2]+=0x00000001u;
goto P_0c03f198;
P_0c03f198: /* original 1c2b, guest PC 0x0c03f198 */
if(!s->budget--) { s->failed_pc=0x0c03f198u; return 0; }
write(ram,r[12]+44,r[2],4);
goto P_0c03f19a;
P_0c03f19a: /* original 4a11, guest PC 0x0c03f19a */
if(!s->budget--) { s->failed_pc=0x0c03f19au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=0)!=0);
goto P_0c03f19c;
P_0c03f19c: /* original 8906, guest PC 0x0c03f19c */
if(!s->budget--) { s->failed_pc=0x0c03f19cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f1ac; }
goto P_0c03f19e;
P_0c03f19e: /* original 62e2, guest PC 0x0c03f19e */
if(!s->budget--) { s->failed_pc=0x0c03f19eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c03f1a0;
P_0c03f1a0: /* original 22bb, guest PC 0x0c03f1a0 */
if(!s->budget--) { s->failed_pc=0x0c03f1a0u; return 0; }
r[2]|=r[11];
goto P_0c03f1a2;
P_0c03f1a2: /* original 2e22, guest PC 0x0c03f1a2 */
if(!s->budget--) { s->failed_pc=0x0c03f1a2u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c03f1a4;
P_0c03f1a4: /* original d35b, guest PC 0x0c03f1a4 */
if(!s->budget--) { s->failed_pc=0x0c03f1a4u; return 0; }
r[3]=read(ram,0x0c03f314u,4);
goto P_0c03f1a6;
P_0c03f1a6: /* original 51e1, guest PC 0x0c03f1a6 */
if(!s->budget--) { s->failed_pc=0x0c03f1a6u; return 0; }
r[1]=read(ram,r[14]+4,4);
goto P_0c03f1a8;
P_0c03f1a8: /* original 213b, guest PC 0x0c03f1a8 */
if(!s->budget--) { s->failed_pc=0x0c03f1a8u; return 0; }
r[1]|=r[3];
goto P_0c03f1aa;
P_0c03f1aa: /* original 1e11, guest PC 0x0c03f1aa */
if(!s->budget--) { s->failed_pc=0x0c03f1aau; return 0; }
write(ram,r[14]+4,r[1],4);
goto P_0c03f1ac;
P_0c03f1ac: /* original 52f3, guest PC 0x0c03f1ac */
if(!s->budget--) { s->failed_pc=0x0c03f1acu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c03f1ae;
P_0c03f1ae: /* original 22bb, guest PC 0x0c03f1ae */
if(!s->budget--) { s->failed_pc=0x0c03f1aeu; return 0; }
r[2]|=r[11];
goto P_0c03f1b0;
P_0c03f1b0: /* original 2228, guest PC 0x0c03f1b0 */
if(!s->budget--) { s->failed_pc=0x0c03f1b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c03f1b2;
P_0c03f1b2: /* original 890b, guest PC 0x0c03f1b2 */
if(!s->budget--) { s->failed_pc=0x0c03f1b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f1cc; }
goto P_0c03f1b4;
P_0c03f1b4: /* original d059, guest PC 0x0c03f1b4 */
if(!s->budget--) { s->failed_pc=0x0c03f1b4u; return 0; }
r[0]=read(ram,0x0c03f31cu,4);
goto P_0c03f1b6;
P_0c03f1b6: /* original 61e2, guest PC 0x0c03f1b6 */
if(!s->budget--) { s->failed_pc=0x0c03f1b6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c03f1b8;
P_0c03f1b8: /* original d357, guest PC 0x0c03f1b8 */
if(!s->budget--) { s->failed_pc=0x0c03f1b8u; return 0; }
r[3]=read(ram,0x0c03f318u,4);
goto P_0c03f1ba;
P_0c03f1ba: /* original 6202, guest PC 0x0c03f1ba */
if(!s->budget--) { s->failed_pc=0x0c03f1bau; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c03f1bc;
P_0c03f1bc: /* original 2139, guest PC 0x0c03f1bc */
if(!s->budget--) { s->failed_pc=0x0c03f1bcu; return 0; }
r[1]&=r[3];
goto P_0c03f1be;
P_0c03f1be: /* original d358, guest PC 0x0c03f1be */
if(!s->budget--) { s->failed_pc=0x0c03f1beu; return 0; }
r[3]=read(ram,0x0c03f320u,4);
goto P_0c03f1c0;
P_0c03f1c0: /* original 4228, guest PC 0x0c03f1c0 */
if(!s->budget--) { s->failed_pc=0x0c03f1c0u; return 0; }
r[2]<<=16;
goto P_0c03f1c2;
P_0c03f1c2: /* original 223b, guest PC 0x0c03f1c2 */
if(!s->budget--) { s->failed_pc=0x0c03f1c2u; return 0; }
r[2]|=r[3];
goto P_0c03f1c4;
P_0c03f1c4: /* original 212b, guest PC 0x0c03f1c4 */
if(!s->budget--) { s->failed_pc=0x0c03f1c4u; return 0; }
r[1]|=r[2];
goto P_0c03f1c6;
P_0c03f1c6: /* original e200, guest PC 0x0c03f1c6 */
if(!s->budget--) { s->failed_pc=0x0c03f1c6u; return 0; }
r[2]=0x00000000u;
goto P_0c03f1c8;
P_0c03f1c8: /* original 2e12, guest PC 0x0c03f1c8 */
if(!s->budget--) { s->failed_pc=0x0c03f1c8u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c03f1ca;
P_0c03f1ca: /* original 1f23, guest PC 0x0c03f1ca */
if(!s->budget--) { s->failed_pc=0x0c03f1cau; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c03f1cc;
P_0c03f1cc: /* original 4d11, guest PC 0x0c03f1cc */
if(!s->budget--) { s->failed_pc=0x0c03f1ccu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[13]>=0)!=0);
goto P_0c03f1ce;
P_0c03f1ce: /* original 8b07, guest PC 0x0c03f1ce */
if(!s->budget--) { s->failed_pc=0x0c03f1ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f1e0; }
goto P_0c03f1d0;
P_0c03f1d0: /* original d254, guest PC 0x0c03f1d0 */
if(!s->budget--) { s->failed_pc=0x0c03f1d0u; return 0; }
r[2]=read(ram,0x0c03f324u,4);
goto P_0c03f1d2;
P_0c03f1d2: /* original 65d3, guest PC 0x0c03f1d2 */
if(!s->budget--) { s->failed_pc=0x0c03f1d2u; return 0; }
r[5]=r[13];
goto P_0c03f1d4;
P_0c03f1d4: /* original 420b, guest PC 0x0c03f1d4 */
if(!s->budget--) { s->failed_pc=0x0c03f1d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c03f1d8u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f1d8u) { target=s->pc; goto dispatch; }
goto P_0c03f1d8;
P_0c03f1d6: /* original 64e3, guest PC 0x0c03f1d6 */
if(!s->budget--) { s->failed_pc=0x0c03f1d6u; return 0; }
r[4]=r[14];
goto P_0c03f1d8;
P_0c03f1d8: /* original a005, guest PC 0x0c03f1d8 */
if(!s->budget--) { s->failed_pc=0x0c03f1d8u; return 0; }
goto P_0c03f1e6;
P_0c03f1da: /* original 0009, guest PC 0x0c03f1da */
if(!s->budget--) { s->failed_pc=0x0c03f1dau; return 0; }
if(!vf3_matrix_family(0x0c03f1dcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f1dcu; return 0; } return 1;
P_0c03f1e0: /* original d251, guest PC 0x0c03f1e0 */
if(!s->budget--) { s->failed_pc=0x0c03f1e0u; return 0; }
r[2]=read(ram,0x0c03f328u,4);
goto P_0c03f1e2;
P_0c03f1e2: /* original 420b, guest PC 0x0c03f1e2 */
if(!s->budget--) { s->failed_pc=0x0c03f1e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c03f1e6u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f1e6u) { target=s->pc; goto dispatch; }
goto P_0c03f1e6;
P_0c03f1e4: /* original 64e3, guest PC 0x0c03f1e4 */
if(!s->budget--) { s->failed_pc=0x0c03f1e4u; return 0; }
r[4]=r[14];
goto P_0c03f1e6;
P_0c03f1e6: /* original d244, guest PC 0x0c03f1e6 */
if(!s->budget--) { s->failed_pc=0x0c03f1e6u; return 0; }
r[2]=read(ram,0x0c03f2f8u,4);
goto P_0c03f1e8;
P_0c03f1e8: /* original e3e5, guest PC 0x0c03f1e8 */
if(!s->budget--) { s->failed_pc=0x0c03f1e8u; return 0; }
r[3]=0xffffffe5u;
goto P_0c03f1ea;
P_0c03f1ea: /* original 50e3, guest PC 0x0c03f1ea */
if(!s->budget--) { s->failed_pc=0x0c03f1eau; return 0; }
r[0]=read(ram,r[14]+12,4);
goto P_0c03f1ec;
P_0c03f1ec: /* original e407, guest PC 0x0c03f1ec */
if(!s->budget--) { s->failed_pc=0x0c03f1ecu; return 0; }
r[4]=0x00000007u;
goto P_0c03f1ee;
P_0c03f1ee: /* original 6522, guest PC 0x0c03f1ee */
if(!s->budget--) { s->failed_pc=0x0c03f1eeu; return 0; }
tmp=read(ram,r[2],4);
r[5]=tmp;
goto P_0c03f1f0;
P_0c03f1f0: /* original 403d, guest PC 0x0c03f1f0 */
if(!s->budget--) { s->failed_pc=0x0c03f1f0u; return 0; }
r[0]=(r[3]&0x80000000u)?((r[3]&31u)?r[0]>>((-r[3])&31u):0):r[0]<<(r[3]&31u);
goto P_0c03f1f2;
P_0c03f1f2: /* original 2558, guest PC 0x0c03f1f2 */
if(!s->budget--) { s->failed_pc=0x0c03f1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c03f1f4;
P_0c03f1f4: /* original 8d54, guest PC 0x0c03f1f4 */
if(!s->budget--) { s->failed_pc=0x0c03f1f4u; return 0; }
cond=r[17]&1u;
r[4]&=r[0];
if(cond) { goto P_0c03f2a0; }
goto P_0c03f1f8;
P_0c03f1f6: /* original 2409, guest PC 0x0c03f1f6 */
if(!s->budget--) { s->failed_pc=0x0c03f1f6u; return 0; }
r[4]&=r[0];
goto P_0c03f1f8;
P_0c03f1f8: /* original 6043, guest PC 0x0c03f1f8 */
if(!s->budget--) { s->failed_pc=0x0c03f1f8u; return 0; }
r[0]=r[4];
goto P_0c03f1fa;
P_0c03f1fa: /* original 8805, guest PC 0x0c03f1fa */
if(!s->budget--) { s->failed_pc=0x0c03f1fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c03f1fc;
P_0c03f1fc: /* original 8902, guest PC 0x0c03f1fc */
if(!s->budget--) { s->failed_pc=0x0c03f1fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f204; }
goto P_0c03f1fe;
P_0c03f1fe: /* original 6043, guest PC 0x0c03f1fe */
if(!s->budget--) { s->failed_pc=0x0c03f1feu; return 0; }
r[0]=r[4];
goto P_0c03f200;
P_0c03f200: /* original 8806, guest PC 0x0c03f200 */
if(!s->budget--) { s->failed_pc=0x0c03f200u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c03f202;
P_0c03f202: /* original 8b4d, guest PC 0x0c03f202 */
if(!s->budget--) { s->failed_pc=0x0c03f202u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f2a0; }
goto P_0c03f204;
P_0c03f204: /* original d349, guest PC 0x0c03f204 */
if(!s->budget--) { s->failed_pc=0x0c03f204u; return 0; }
r[3]=read(ram,0x0c03f32cu,4);
goto P_0c03f206;
P_0c03f206: /* original 54ef, guest PC 0x0c03f206 */
if(!s->budget--) { s->failed_pc=0x0c03f206u; return 0; }
r[4]=read(ram,r[14]+60,4);
goto P_0c03f208;
P_0c03f208: /* original 6231, guest PC 0x0c03f208 */
if(!s->budget--) { s->failed_pc=0x0c03f208u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[3],2);
r[2]=tmp;
goto P_0c03f20a;
P_0c03f20a: /* original 3423, guest PC 0x0c03f20a */
if(!s->budget--) { s->failed_pc=0x0c03f20au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[2])!=0);
goto P_0c03f20c;
P_0c03f20c: /* original 8948, guest PC 0x0c03f20c */
if(!s->budget--) { s->failed_pc=0x0c03f20cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f2a0; }
goto P_0c03f20e;
P_0c03f20e: /* original d148, guest PC 0x0c03f20e */
if(!s->budget--) { s->failed_pc=0x0c03f20eu; return 0; }
r[1]=read(ram,0x0c03f330u,4);
goto P_0c03f210;
P_0c03f210: /* original 6043, guest PC 0x0c03f210 */
if(!s->budget--) { s->failed_pc=0x0c03f210u; return 0; }
r[0]=r[4];
goto P_0c03f212;
P_0c03f212: /* original 4008, guest PC 0x0c03f212 */
if(!s->budget--) { s->failed_pc=0x0c03f212u; return 0; }
r[0]<<=2;
goto P_0c03f214;
P_0c03f214: /* original 6a43, guest PC 0x0c03f214 */
if(!s->budget--) { s->failed_pc=0x0c03f214u; return 0; }
r[10]=r[4];
goto P_0c03f216;
P_0c03f216: /* original 6d12, guest PC 0x0c03f216 */
if(!s->budget--) { s->failed_pc=0x0c03f216u; return 0; }
tmp=read(ram,r[1],4);
r[13]=tmp;
goto P_0c03f218;
P_0c03f218: /* original 6243, guest PC 0x0c03f218 */
if(!s->budget--) { s->failed_pc=0x0c03f218u; return 0; }
r[2]=r[4];
goto P_0c03f21a;
P_0c03f21a: /* original 4a00, guest PC 0x0c03f21a */
if(!s->budget--) { s->failed_pc=0x0c03f21au; return 0; }
r[17]=(r[17]&~1u)|((r[10]>>31)!=0);
r[10]<<=1;
goto P_0c03f21c;
P_0c03f21c: /* original 4000, guest PC 0x0c03f21c */
if(!s->budget--) { s->failed_pc=0x0c03f21cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c03f21e;
P_0c03f21e: /* original 3d0c, guest PC 0x0c03f21e */
if(!s->budget--) { s->failed_pc=0x0c03f21eu; return 0; }
r[13]+=r[0];
goto P_0c03f220;
P_0c03f220: /* original 85d2, guest PC 0x0c03f220 */
if(!s->budget--) { s->failed_pc=0x0c03f220u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c03f222;
P_0c03f222: /* original 3a2c, guest PC 0x0c03f222 */
if(!s->budget--) { s->failed_pc=0x0c03f222u; return 0; }
r[10]+=r[2];
goto P_0c03f224;
P_0c03f224: /* original 4a08, guest PC 0x0c03f224 */
if(!s->budget--) { s->failed_pc=0x0c03f224u; return 0; }
r[10]<<=2;
goto P_0c03f226;
P_0c03f226: /* original 2008, guest PC 0x0c03f226 */
if(!s->budget--) { s->failed_pc=0x0c03f226u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c03f228;
P_0c03f228: /* original 8d0a, guest PC 0x0c03f228 */
if(!s->budget--) { s->failed_pc=0x0c03f228u; return 0; }
cond=r[17]&1u;
r[10]+=r[5];
if(cond) { goto P_0c03f240; }
goto P_0c03f22c;
P_0c03f22a: /* original 3a5c, guest PC 0x0c03f22a */
if(!s->budget--) { s->failed_pc=0x0c03f22au; return 0; }
r[10]+=r[5];
goto P_0c03f22c;
P_0c03f22c: /* original 85d2, guest PC 0x0c03f22c */
if(!s->budget--) { s->failed_pc=0x0c03f22cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+4,2);
goto P_0c03f22e;
P_0c03f22e: /* original 7001, guest PC 0x0c03f22e */
if(!s->budget--) { s->failed_pc=0x0c03f22eu; return 0; }
r[0]+=0x00000001u;
goto P_0c03f230;
P_0c03f230: /* original 81d2, guest PC 0x0c03f230 */
if(!s->budget--) { s->failed_pc=0x0c03f230u; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c03f232;
P_0c03f232: /* original a02e, guest PC 0x0c03f232 */
if(!s->budget--) { s->failed_pc=0x0c03f232u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
goto P_0c03f292;
P_0c03f234: /* original 6cd1, guest PC 0x0c03f234 */
if(!s->budget--) { s->failed_pc=0x0c03f234u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[13],2);
r[12]=tmp;
if(!vf3_matrix_family(0x0c03f236u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f236u; return 0; } return 1;
P_0c03f240: /* original 84a2, guest PC 0x0c03f240 */
if(!s->budget--) { s->failed_pc=0x0c03f240u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+2,1);
goto P_0c03f242;
P_0c03f242: /* original e2fc, guest PC 0x0c03f242 */
if(!s->budget--) { s->failed_pc=0x0c03f242u; return 0; }
r[2]=0xfffffffcu;
goto P_0c03f244;
P_0c03f244: /* original 80d2, guest PC 0x0c03f244 */
if(!s->budget--) { s->failed_pc=0x0c03f244u; return 0; }
write(ram,r[13]+2,r[0],1);
goto P_0c03f246;
P_0c03f246: /* original 50a2, guest PC 0x0c03f246 */
if(!s->budget--) { s->failed_pc=0x0c03f246u; return 0; }
r[0]=read(ram,r[10]+8,4);
goto P_0c03f248;
P_0c03f248: /* original 700f, guest PC 0x0c03f248 */
if(!s->budget--) { s->failed_pc=0x0c03f248u; return 0; }
r[0]+=0x0000000fu;
goto P_0c03f24a;
P_0c03f24a: /* original 402c, guest PC 0x0c03f24a */
if(!s->budget--) { s->failed_pc=0x0c03f24au; return 0; }
r[0]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[0]>>((-r[2])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[2]&31u);
goto P_0c03f24c;
P_0c03f24c: /* original 80d3, guest PC 0x0c03f24c */
if(!s->budget--) { s->failed_pc=0x0c03f24cu; return 0; }
write(ram,r[13]+3,r[0],1);
goto P_0c03f24e;
P_0c03f24e: /* original 60b3, guest PC 0x0c03f24e */
if(!s->budget--) { s->failed_pc=0x0c03f24eu; return 0; }
r[0]=r[11];
goto P_0c03f250;
P_0c03f250: /* original 81d2, guest PC 0x0c03f250 */
if(!s->budget--) { s->failed_pc=0x0c03f250u; return 0; }
write(ram,r[13]+4,r[0],2);
goto P_0c03f252;
P_0c03f252: /* original 6043, guest PC 0x0c03f252 */
if(!s->budget--) { s->failed_pc=0x0c03f252u; return 0; }
r[0]=r[4];
goto P_0c03f254;
P_0c03f254: /* original 81d3, guest PC 0x0c03f254 */
if(!s->budget--) { s->failed_pc=0x0c03f254u; return 0; }
write(ram,r[13]+6,r[0],2);
goto P_0c03f256;
P_0c03f256: /* original 52a2, guest PC 0x0c03f256 */
if(!s->budget--) { s->failed_pc=0x0c03f256u; return 0; }
r[2]=read(ram,r[10]+8,4);
goto P_0c03f258;
P_0c03f258: /* original 6523, guest PC 0x0c03f258 */
if(!s->budget--) { s->failed_pc=0x0c03f258u; return 0; }
r[5]=r[2];
goto P_0c03f25a;
P_0c03f25a: /* original 2f22, guest PC 0x0c03f25a */
if(!s->budget--) { s->failed_pc=0x0c03f25au; return 0; }
write(ram,r[15],r[2],4);
goto P_0c03f25c;
P_0c03f25c: /* original d235, guest PC 0x0c03f25c */
if(!s->budget--) { s->failed_pc=0x0c03f25cu; return 0; }
r[2]=read(ram,0x0c03f334u,4);
goto P_0c03f25e;
P_0c03f25e: /* original 85a1, guest PC 0x0c03f25e */
if(!s->budget--) { s->failed_pc=0x0c03f25eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+2,2);
goto P_0c03f260;
P_0c03f260: /* original 420b, guest PC 0x0c03f260 */
if(!s->budget--) { s->failed_pc=0x0c03f260u; return 0; }
target=r[2];
r[16]=code_base|0x0c03f264u;
r[4]=r[0];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f264u) { target=s->pc; goto dispatch; }
goto P_0c03f264;
P_0c03f262: /* original 6403, guest PC 0x0c03f262 */
if(!s->budget--) { s->failed_pc=0x0c03f262u; return 0; }
r[4]=r[0];
goto P_0c03f264;
P_0c03f264: /* original 6c03, guest PC 0x0c03f264 */
if(!s->budget--) { s->failed_pc=0x0c03f264u; return 0; }
r[12]=r[0];
goto P_0c03f266;
P_0c03f266: /* original 4c11, guest PC 0x0c03f266 */
if(!s->budget--) { s->failed_pc=0x0c03f266u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=0)!=0);
goto P_0c03f268;
P_0c03f268: /* original 8b12, guest PC 0x0c03f268 */
if(!s->budget--) { s->failed_pc=0x0c03f268u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c03f290; }
goto P_0c03f26a;
P_0c03f26a: /* original 2dc1, guest PC 0x0c03f26a */
if(!s->budget--) { s->failed_pc=0x0c03f26au; return 0; }
write(ram,r[13],r[12],2);
goto P_0c03f26c;
P_0c03f26c: /* original d332, guest PC 0x0c03f26c */
if(!s->budget--) { s->failed_pc=0x0c03f26cu; return 0; }
r[3]=read(ram,0x0c03f338u,4);
goto P_0c03f26e;
P_0c03f26e: /* original 65f2, guest PC 0x0c03f26e */
if(!s->budget--) { s->failed_pc=0x0c03f26eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c03f270;
P_0c03f270: /* original 430b, guest PC 0x0c03f270 */
if(!s->budget--) { s->failed_pc=0x0c03f270u; return 0; }
target=r[3];
r[16]=code_base|0x0c03f274u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f274u) { target=s->pc; goto dispatch; }
goto P_0c03f274;
P_0c03f272: /* original 64c3, guest PC 0x0c03f272 */
if(!s->budget--) { s->failed_pc=0x0c03f272u; return 0; }
r[4]=r[12];
goto P_0c03f274;
P_0c03f274: /* original 64c3, guest PC 0x0c03f274 */
if(!s->budget--) { s->failed_pc=0x0c03f274u; return 0; }
r[4]=r[12];
goto P_0c03f276;
P_0c03f276: /* original d331, guest PC 0x0c03f276 */
if(!s->budget--) { s->failed_pc=0x0c03f276u; return 0; }
r[3]=read(ram,0x0c03f33cu,4);
goto P_0c03f278;
P_0c03f278: /* original 66f2, guest PC 0x0c03f278 */
if(!s->budget--) { s->failed_pc=0x0c03f278u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c03f27a;
P_0c03f27a: /* original 4408, guest PC 0x0c03f27a */
if(!s->budget--) { s->failed_pc=0x0c03f27au; return 0; }
r[4]<<=2;
goto P_0c03f27c;
P_0c03f27c: /* original 55a1, guest PC 0x0c03f27c */
if(!s->budget--) { s->failed_pc=0x0c03f27cu; return 0; }
r[5]=read(ram,r[10]+4,4);
goto P_0c03f27e;
P_0c03f27e: /* original 430b, guest PC 0x0c03f27e */
if(!s->budget--) { s->failed_pc=0x0c03f27eu; return 0; }
target=r[3];
r[16]=code_base|0x0c03f282u;
r[4]<<=2;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c03f282u) { target=s->pc; goto dispatch; }
goto P_0c03f282;
P_0c03f280: /* original 4408, guest PC 0x0c03f280 */
if(!s->budget--) { s->failed_pc=0x0c03f280u; return 0; }
r[4]<<=2;
goto P_0c03f282;
P_0c03f282: /* original a006, guest PC 0x0c03f282 */
if(!s->budget--) { s->failed_pc=0x0c03f282u; return 0; }
goto P_0c03f292;
P_0c03f284: /* original 0009, guest PC 0x0c03f284 */
if(!s->budget--) { s->failed_pc=0x0c03f284u; return 0; }
if(!vf3_matrix_family(0x0c03f286u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f286u; return 0; } return 1;
P_0c03f290: /* original ec00, guest PC 0x0c03f290 */
if(!s->budget--) { s->failed_pc=0x0c03f290u; return 0; }
r[12]=0x00000000u;
goto P_0c03f292;
P_0c03f292: /* original 52e3, guest PC 0x0c03f292 */
if(!s->budget--) { s->failed_pc=0x0c03f292u; return 0; }
r[2]=read(ram,r[14]+12,4);
goto P_0c03f294;
P_0c03f294: /* original e115, guest PC 0x0c03f294 */
if(!s->budget--) { s->failed_pc=0x0c03f294u; return 0; }
r[1]=0x00000015u;
goto P_0c03f296;
P_0c03f296: /* original d32a, guest PC 0x0c03f296 */
if(!s->budget--) { s->failed_pc=0x0c03f296u; return 0; }
r[3]=read(ram,0x0c03f340u,4);
goto P_0c03f298;
P_0c03f298: /* original 4c1c, guest PC 0x0c03f298 */
if(!s->budget--) { s->failed_pc=0x0c03f298u; return 0; }
r[12]=(r[1]&0x80000000u)?((r[1]&31u)?(uint32_t)((int32_t)r[12]>>((-r[1])&31u)):((int32_t)r[12]<0?0xffffffffu:0)):r[12]<<(r[1]&31u);
goto P_0c03f29a;
P_0c03f29a: /* original 2239, guest PC 0x0c03f29a */
if(!s->budget--) { s->failed_pc=0x0c03f29au; return 0; }
r[2]&=r[3];
goto P_0c03f29c;
P_0c03f29c: /* original 22cb, guest PC 0x0c03f29c */
if(!s->budget--) { s->failed_pc=0x0c03f29cu; return 0; }
r[2]|=r[12];
goto P_0c03f29e;
P_0c03f29e: /* original 1e23, guest PC 0x0c03f29e */
if(!s->budget--) { s->failed_pc=0x0c03f29eu; return 0; }
write(ram,r[14]+12,r[2],4);
goto P_0c03f2a0;
P_0c03f2a0: /* original e04c, guest PC 0x0c03f2a0 */
if(!s->budget--) { s->failed_pc=0x0c03f2a0u; return 0; }
r[0]=0x0000004cu;
goto P_0c03f2a2;
P_0c03f2a2: /* original 03ee, guest PC 0x0c03f2a2 */
if(!s->budget--) { s->failed_pc=0x0c03f2a2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c03f2a4;
P_0c03f2a4: /* original 383c, guest PC 0x0c03f2a4 */
if(!s->budget--) { s->failed_pc=0x0c03f2a4u; return 0; }
r[8]+=r[3];
goto P_0c03f2a6;
P_0c03f2a6: /* original 6482, guest PC 0x0c03f2a6 */
if(!s->budget--) { s->failed_pc=0x0c03f2a6u; return 0; }
tmp=read(ram,r[8],4);
r[4]=tmp;
goto P_0c03f2a8;
P_0c03f2a8: /* original 2448, guest PC 0x0c03f2a8 */
if(!s->budget--) { s->failed_pc=0x0c03f2a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c03f2aa;
P_0c03f2aa: /* original 8901, guest PC 0x0c03f2aa */
if(!s->budget--) { s->failed_pc=0x0c03f2aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c03f2b0; }
goto P_0c03f2ac;
P_0c03f2ac: /* original af35, guest PC 0x0c03f2ac */
if(!s->budget--) { s->failed_pc=0x0c03f2acu; return 0; }
goto P_0c03f11a;
P_0c03f2ae: /* original 0009, guest PC 0x0c03f2ae */
if(!s->budget--) { s->failed_pc=0x0c03f2aeu; return 0; }
goto P_0c03f2b0;
P_0c03f2b0: /* original 50f1, guest PC 0x0c03f2b0 */
if(!s->budget--) { s->failed_pc=0x0c03f2b0u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c03f2b2;
P_0c03f2b2: /* original 7f10, guest PC 0x0c03f2b2 */
if(!s->budget--) { s->failed_pc=0x0c03f2b2u; return 0; }
r[15]+=0x00000010u;
goto P_0c03f2b4;
P_0c03f2b4: /* original 4f16, guest PC 0x0c03f2b4 */
if(!s->budget--) { s->failed_pc=0x0c03f2b4u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f2b6;
P_0c03f2b6: /* original 4f26, guest PC 0x0c03f2b6 */
if(!s->budget--) { s->failed_pc=0x0c03f2b6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c03f2b8;
P_0c03f2b8: /* original fff9, guest PC 0x0c03f2b8 */
if(!s->budget--) { s->failed_pc=0x0c03f2b8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c03f2ba;
P_0c03f2ba: /* original 68f6, guest PC 0x0c03f2ba */
if(!s->budget--) { s->failed_pc=0x0c03f2bau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c03f2bc;
P_0c03f2bc: /* original 69f6, guest PC 0x0c03f2bc */
if(!s->budget--) { s->failed_pc=0x0c03f2bcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c03f2be;
P_0c03f2be: /* original 6af6, guest PC 0x0c03f2be */
if(!s->budget--) { s->failed_pc=0x0c03f2beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c03f2c0;
P_0c03f2c0: /* original 6bf6, guest PC 0x0c03f2c0 */
if(!s->budget--) { s->failed_pc=0x0c03f2c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c03f2c2;
P_0c03f2c2: /* original 6cf6, guest PC 0x0c03f2c2 */
if(!s->budget--) { s->failed_pc=0x0c03f2c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c03f2c4;
P_0c03f2c4: /* original 6df6, guest PC 0x0c03f2c4 */
if(!s->budget--) { s->failed_pc=0x0c03f2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c03f2c6;
P_0c03f2c6: /* original 000b, guest PC 0x0c03f2c6 */
if(!s->budget--) { s->failed_pc=0x0c03f2c6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c03f2c8: /* original 6ef6, guest PC 0x0c03f2c8 */
if(!s->budget--) { s->failed_pc=0x0c03f2c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c03f2cau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c03f2cau; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
