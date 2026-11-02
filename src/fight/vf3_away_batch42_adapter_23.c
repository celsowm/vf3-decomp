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
int vf3_away_batch42_adapter_23(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0caf5eu: goto P_0c0caf5e;
case 0x0c0caf60u: goto P_0c0caf60;
case 0x0c0caf62u: goto P_0c0caf62;
case 0x0c0caf64u: goto P_0c0caf64;
case 0x0c0caf66u: goto P_0c0caf66;
case 0x0c0caf68u: goto P_0c0caf68;
case 0x0c0caf6au: goto P_0c0caf6a;
case 0x0c0caf6cu: goto P_0c0caf6c;
case 0x0c0caf6eu: goto P_0c0caf6e;
case 0x0c0caf70u: goto P_0c0caf70;
case 0x0c0caf72u: goto P_0c0caf72;
case 0x0c0caf74u: goto P_0c0caf74;
case 0x0c0caf76u: goto P_0c0caf76;
case 0x0c0caf78u: goto P_0c0caf78;
case 0x0c0caf7au: goto P_0c0caf7a;
case 0x0c0caf7cu: goto P_0c0caf7c;
case 0x0c0caf7eu: goto P_0c0caf7e;
case 0x0c0caf80u: goto P_0c0caf80;
case 0x0c0caf82u: goto P_0c0caf82;
case 0x0c0caf84u: goto P_0c0caf84;
case 0x0c0caf86u: goto P_0c0caf86;
case 0x0c0caf88u: goto P_0c0caf88;
case 0x0c0caf8au: goto P_0c0caf8a;
case 0x0c0caf8cu: goto P_0c0caf8c;
case 0x0c0caf8eu: goto P_0c0caf8e;
case 0x0c0caf90u: goto P_0c0caf90;
case 0x0c0caf92u: goto P_0c0caf92;
case 0x0c0caf94u: goto P_0c0caf94;
case 0x0c0caf96u: goto P_0c0caf96;
case 0x0c0caf98u: goto P_0c0caf98;
case 0x0c0caf9au: goto P_0c0caf9a;
case 0x0c0caf9cu: goto P_0c0caf9c;
case 0x0c0caf9eu: goto P_0c0caf9e;
case 0x0c0cafa0u: goto P_0c0cafa0;
case 0x0c0cafa2u: goto P_0c0cafa2;
case 0x0c0cafa4u: goto P_0c0cafa4;
case 0x0c0cafa6u: goto P_0c0cafa6;
case 0x0c0cafa8u: goto P_0c0cafa8;
case 0x0c0cafaau: goto P_0c0cafaa;
case 0x0c0cafacu: goto P_0c0cafac;
case 0x0c0cafaeu: goto P_0c0cafae;
case 0x0c0cafb0u: goto P_0c0cafb0;
case 0x0c0cafb2u: goto P_0c0cafb2;
case 0x0c0cafb4u: goto P_0c0cafb4;
case 0x0c0cafb6u: goto P_0c0cafb6;
case 0x0c0cafb8u: goto P_0c0cafb8;
case 0x0c0cafbau: goto P_0c0cafba;
case 0x0c0cafbcu: goto P_0c0cafbc;
case 0x0c0cafbeu: goto P_0c0cafbe;
case 0x0c0cafc0u: goto P_0c0cafc0;
case 0x0c0cafc2u: goto P_0c0cafc2;
case 0x0c0cafc4u: goto P_0c0cafc4;
case 0x0c0cafc6u: goto P_0c0cafc6;
case 0x0c0cafc8u: goto P_0c0cafc8;
case 0x0c0cafcau: goto P_0c0cafca;
case 0x0c0cafccu: goto P_0c0cafcc;
case 0x0c0cafceu: goto P_0c0cafce;
case 0x0c0cafd0u: goto P_0c0cafd0;
case 0x0c0cafd2u: goto P_0c0cafd2;
case 0x0c0cafd4u: goto P_0c0cafd4;
case 0x0c0cafd6u: goto P_0c0cafd6;
case 0x0c0cafd8u: goto P_0c0cafd8;
case 0x0c0cafdau: goto P_0c0cafda;
case 0x0c0cafdcu: goto P_0c0cafdc;
case 0x0c0cafdeu: goto P_0c0cafde;
case 0x0c0cafe0u: goto P_0c0cafe0;
case 0x0c0cafe2u: goto P_0c0cafe2;
case 0x0c0cafe4u: goto P_0c0cafe4;
case 0x0c0cafe6u: goto P_0c0cafe6;
case 0x0c0cafe8u: goto P_0c0cafe8;
case 0x0c0cafeau: goto P_0c0cafea;
case 0x0c0cafecu: goto P_0c0cafec;
case 0x0c0cafeeu: goto P_0c0cafee;
case 0x0c0caff0u: goto P_0c0caff0;
case 0x0c0caff2u: goto P_0c0caff2;
case 0x0c0caff4u: goto P_0c0caff4;
case 0x0c0caff6u: goto P_0c0caff6;
case 0x0c0caff8u: goto P_0c0caff8;
case 0x0c0caffau: goto P_0c0caffa;
case 0x0c0caffcu: goto P_0c0caffc;
case 0x0c0caffeu: goto P_0c0caffe;
case 0x0c0cb000u: goto P_0c0cb000;
case 0x0c0cb002u: goto P_0c0cb002;
case 0x0c0cb004u: goto P_0c0cb004;
case 0x0c0cb006u: goto P_0c0cb006;
case 0x0c0cb008u: goto P_0c0cb008;
case 0x0c0cb00au: goto P_0c0cb00a;
case 0x0c0cb00cu: goto P_0c0cb00c;
case 0x0c0cb00eu: goto P_0c0cb00e;
case 0x0c0cb010u: goto P_0c0cb010;
case 0x0c0cb012u: goto P_0c0cb012;
case 0x0c0cb014u: goto P_0c0cb014;
case 0x0c0cb016u: goto P_0c0cb016;
case 0x0c0cb018u: goto P_0c0cb018;
case 0x0c0cb01au: goto P_0c0cb01a;
case 0x0c0cb01cu: goto P_0c0cb01c;
case 0x0c0cb01eu: goto P_0c0cb01e;
case 0x0c0cb020u: goto P_0c0cb020;
case 0x0c0cb022u: goto P_0c0cb022;
case 0x0c0cb024u: goto P_0c0cb024;
case 0x0c0cb026u: goto P_0c0cb026;
case 0x0c0cb028u: goto P_0c0cb028;
case 0x0c0cb02au: goto P_0c0cb02a;
case 0x0c0cb02cu: goto P_0c0cb02c;
case 0x0c0cb02eu: goto P_0c0cb02e;
case 0x0c0cb050u: goto P_0c0cb050;
case 0x0c0cb052u: goto P_0c0cb052;
case 0x0c0cb054u: goto P_0c0cb054;
case 0x0c0cb056u: goto P_0c0cb056;
case 0x0c0cb058u: goto P_0c0cb058;
case 0x0c0cb05au: goto P_0c0cb05a;
case 0x0c0cb05cu: goto P_0c0cb05c;
case 0x0c0cb05eu: goto P_0c0cb05e;
case 0x0c0cb060u: goto P_0c0cb060;
case 0x0c0cb062u: goto P_0c0cb062;
case 0x0c0cb064u: goto P_0c0cb064;
case 0x0c0cb066u: goto P_0c0cb066;
case 0x0c0cb068u: goto P_0c0cb068;
case 0x0c0cb06au: goto P_0c0cb06a;
case 0x0c0cb06cu: goto P_0c0cb06c;
case 0x0c0cb06eu: goto P_0c0cb06e;
case 0x0c0cb070u: goto P_0c0cb070;
case 0x0c0cb072u: goto P_0c0cb072;
case 0x0c0cb074u: goto P_0c0cb074;
case 0x0c0cb076u: goto P_0c0cb076;
case 0x0c0cb078u: goto P_0c0cb078;
case 0x0c0cb07au: goto P_0c0cb07a;
case 0x0c0cb07cu: goto P_0c0cb07c;
case 0x0c0cb07eu: goto P_0c0cb07e;
case 0x0c0cb080u: goto P_0c0cb080;
case 0x0c0cb082u: goto P_0c0cb082;
case 0x0c0cb084u: goto P_0c0cb084;
case 0x0c0cb086u: goto P_0c0cb086;
case 0x0c0cb088u: goto P_0c0cb088;
case 0x0c0cb08au: goto P_0c0cb08a;
case 0x0c0cb08cu: goto P_0c0cb08c;
case 0x0c0cb08eu: goto P_0c0cb08e;
case 0x0c0cb090u: goto P_0c0cb090;
case 0x0c0cb092u: goto P_0c0cb092;
case 0x0c0cb094u: goto P_0c0cb094;
case 0x0c0cb096u: goto P_0c0cb096;
case 0x0c0cb098u: goto P_0c0cb098;
case 0x0c0cb09au: goto P_0c0cb09a;
case 0x0c0cb09cu: goto P_0c0cb09c;
case 0x0c0cb09eu: goto P_0c0cb09e;
case 0x0c0cb0a0u: goto P_0c0cb0a0;
case 0x0c0cb0a2u: goto P_0c0cb0a2;
case 0x0c0cb0a4u: goto P_0c0cb0a4;
case 0x0c0cb0a6u: goto P_0c0cb0a6;
case 0x0c0cb0a8u: goto P_0c0cb0a8;
case 0x0c0cb0aau: goto P_0c0cb0aa;
case 0x0c0cb0acu: goto P_0c0cb0ac;
case 0x0c0cb0aeu: goto P_0c0cb0ae;
case 0x0c0cb0b0u: goto P_0c0cb0b0;
case 0x0c0cb0b2u: goto P_0c0cb0b2;
case 0x0c0cb0b4u: goto P_0c0cb0b4;
case 0x0c0cb0b6u: goto P_0c0cb0b6;
case 0x0c0cb0b8u: goto P_0c0cb0b8;
case 0x0c0cb0bau: goto P_0c0cb0ba;
case 0x0c0cb0bcu: goto P_0c0cb0bc;
case 0x0c0cb0beu: goto P_0c0cb0be;
case 0x0c0cb0c0u: goto P_0c0cb0c0;
case 0x0c0cb0c2u: goto P_0c0cb0c2;
case 0x0c0cb0c4u: goto P_0c0cb0c4;
case 0x0c0cb0c6u: goto P_0c0cb0c6;
case 0x0c0cb0c8u: goto P_0c0cb0c8;
case 0x0c0cb0cau: goto P_0c0cb0ca;
case 0x0c0cb0ccu: goto P_0c0cb0cc;
case 0x0c0cb0ceu: goto P_0c0cb0ce;
case 0x0c0cb0d0u: goto P_0c0cb0d0;
case 0x0c0cb0d2u: goto P_0c0cb0d2;
case 0x0c0cb0d4u: goto P_0c0cb0d4;
case 0x0c0cb0d6u: goto P_0c0cb0d6;
case 0x0c0cb0d8u: goto P_0c0cb0d8;
case 0x0c0cb0dau: goto P_0c0cb0da;
case 0x0c0cb0dcu: goto P_0c0cb0dc;
case 0x0c0cb0deu: goto P_0c0cb0de;
case 0x0c0cb0e0u: goto P_0c0cb0e0;
case 0x0c0cb0e2u: goto P_0c0cb0e2;
case 0x0c0cb0e4u: goto P_0c0cb0e4;
case 0x0c0cb0e6u: goto P_0c0cb0e6;
case 0x0c0cb0e8u: goto P_0c0cb0e8;
case 0x0c0cb0eau: goto P_0c0cb0ea;
case 0x0c0cb114u: goto P_0c0cb114;
case 0x0c0cb116u: goto P_0c0cb116;
case 0x0c0cb118u: goto P_0c0cb118;
case 0x0c0cb11au: goto P_0c0cb11a;
case 0x0c0cb11cu: goto P_0c0cb11c;
case 0x0c0cb11eu: goto P_0c0cb11e;
case 0x0c0cb120u: goto P_0c0cb120;
case 0x0c0cb122u: goto P_0c0cb122;
case 0x0c0cb124u: goto P_0c0cb124;
case 0x0c0cb126u: goto P_0c0cb126;
case 0x0c0cb128u: goto P_0c0cb128;
case 0x0c0cb12au: goto P_0c0cb12a;
case 0x0c0cb12cu: goto P_0c0cb12c;
case 0x0c0cb12eu: goto P_0c0cb12e;
case 0x0c0cb130u: goto P_0c0cb130;
case 0x0c0cb132u: goto P_0c0cb132;
case 0x0c0cb134u: goto P_0c0cb134;
case 0x0c0cb136u: goto P_0c0cb136;
case 0x0c0cb138u: goto P_0c0cb138;
case 0x0c0cb13au: goto P_0c0cb13a;
case 0x0c0cb13cu: goto P_0c0cb13c;
case 0x0c0cb13eu: goto P_0c0cb13e;
case 0x0c0cb140u: goto P_0c0cb140;
case 0x0c0cb142u: goto P_0c0cb142;
case 0x0c0cb144u: goto P_0c0cb144;
case 0x0c0cb146u: goto P_0c0cb146;
case 0x0c0cb148u: goto P_0c0cb148;
case 0x0c0cb14au: goto P_0c0cb14a;
case 0x0c0cb14cu: goto P_0c0cb14c;
case 0x0c0cb14eu: goto P_0c0cb14e;
case 0x0c0cb150u: goto P_0c0cb150;
case 0x0c0cb152u: goto P_0c0cb152;
case 0x0c0cb154u: goto P_0c0cb154;
case 0x0c0cb156u: goto P_0c0cb156;
case 0x0c0cb158u: goto P_0c0cb158;
case 0x0c0cb15au: goto P_0c0cb15a;
case 0x0c0cb15cu: goto P_0c0cb15c;
case 0x0c0cb15eu: goto P_0c0cb15e;
case 0x0c0cb160u: goto P_0c0cb160;
case 0x0c0cb162u: goto P_0c0cb162;
case 0x0c0cb164u: goto P_0c0cb164;
case 0x0c0cb166u: goto P_0c0cb166;
case 0x0c0cb168u: goto P_0c0cb168;
case 0x0c0cb16au: goto P_0c0cb16a;
case 0x0c0cb16cu: goto P_0c0cb16c;
case 0x0c0cb16eu: goto P_0c0cb16e;
case 0x0c0cb170u: goto P_0c0cb170;
case 0x0c0cb172u: goto P_0c0cb172;
case 0x0c0cb174u: goto P_0c0cb174;
case 0x0c0cb176u: goto P_0c0cb176;
case 0x0c0cb178u: goto P_0c0cb178;
case 0x0c0cb17au: goto P_0c0cb17a;
case 0x0c0cb17cu: goto P_0c0cb17c;
case 0x0c0cb17eu: goto P_0c0cb17e;
case 0x0c0cb180u: goto P_0c0cb180;
case 0x0c0cb182u: goto P_0c0cb182;
case 0x0c0cb184u: goto P_0c0cb184;
case 0x0c0cb186u: goto P_0c0cb186;
case 0x0c0cb188u: goto P_0c0cb188;
case 0x0c0cb18au: goto P_0c0cb18a;
case 0x0c0cb18cu: goto P_0c0cb18c;
case 0x0c0cb18eu: goto P_0c0cb18e;
case 0x0c0cb190u: goto P_0c0cb190;
case 0x0c0cb192u: goto P_0c0cb192;
case 0x0c0cb194u: goto P_0c0cb194;
case 0x0c0cb196u: goto P_0c0cb196;
case 0x0c0cb198u: goto P_0c0cb198;
case 0x0c0cb19au: goto P_0c0cb19a;
case 0x0c0cb19cu: goto P_0c0cb19c;
case 0x0c0cb19eu: goto P_0c0cb19e;
case 0x0c0cb1a0u: goto P_0c0cb1a0;
case 0x0c0cb1a2u: goto P_0c0cb1a2;
case 0x0c0cb1a4u: goto P_0c0cb1a4;
case 0x0c0cb1a6u: goto P_0c0cb1a6;
case 0x0c0cb1a8u: goto P_0c0cb1a8;
case 0x0c0cb1aau: goto P_0c0cb1aa;
case 0x0c0cb1acu: goto P_0c0cb1ac;
case 0x0c0cb1aeu: goto P_0c0cb1ae;
case 0x0c0cb1b0u: goto P_0c0cb1b0;
case 0x0c0cb1b2u: goto P_0c0cb1b2;
case 0x0c0cb1b4u: goto P_0c0cb1b4;
case 0x0c0cb1b6u: goto P_0c0cb1b6;
case 0x0c0cb1b8u: goto P_0c0cb1b8;
case 0x0c0cb1bau: goto P_0c0cb1ba;
case 0x0c0cb1bcu: goto P_0c0cb1bc;
case 0x0c0cb1beu: goto P_0c0cb1be;
case 0x0c0cb1c0u: goto P_0c0cb1c0;
case 0x0c0cb1c2u: goto P_0c0cb1c2;
case 0x0c0cb1c4u: goto P_0c0cb1c4;
case 0x0c0cb1c6u: goto P_0c0cb1c6;
case 0x0c0cb1c8u: goto P_0c0cb1c8;
case 0x0c0cb1cau: goto P_0c0cb1ca;
case 0x0c0cb1ccu: goto P_0c0cb1cc;
case 0x0c0cb1ceu: goto P_0c0cb1ce;
case 0x0c0cb1d0u: goto P_0c0cb1d0;
case 0x0c0cb1d2u: goto P_0c0cb1d2;
case 0x0c0cb1d4u: goto P_0c0cb1d4;
case 0x0c0cb1d6u: goto P_0c0cb1d6;
case 0x0c0cb1d8u: goto P_0c0cb1d8;
case 0x0c0cb1dau: goto P_0c0cb1da;
case 0x0c0cb1dcu: goto P_0c0cb1dc;
case 0x0c0cb1deu: goto P_0c0cb1de;
case 0x0c0cb1e0u: goto P_0c0cb1e0;
case 0x0c0cb1e2u: goto P_0c0cb1e2;
case 0x0c0cb1e4u: goto P_0c0cb1e4;
case 0x0c0cb1e6u: goto P_0c0cb1e6;
case 0x0c0cb1e8u: goto P_0c0cb1e8;
case 0x0c0cb1eau: goto P_0c0cb1ea;
case 0x0c0cb1ecu: goto P_0c0cb1ec;
case 0x0c0cb1eeu: goto P_0c0cb1ee;
case 0x0c0cb1f0u: goto P_0c0cb1f0;
case 0x0c0cb1f2u: goto P_0c0cb1f2;
case 0x0c0cb1f4u: goto P_0c0cb1f4;
case 0x0c0cb1f6u: goto P_0c0cb1f6;
case 0x0c0cb1f8u: goto P_0c0cb1f8;
case 0x0c0cb1fau: goto P_0c0cb1fa;
case 0x0c0cb1fcu: goto P_0c0cb1fc;
case 0x0c0cb1feu: goto P_0c0cb1fe;
case 0x0c0cb200u: goto P_0c0cb200;
case 0x0c0cb202u: goto P_0c0cb202;
case 0x0c0cb204u: goto P_0c0cb204;
case 0x0c0cb206u: goto P_0c0cb206;
case 0x0c0cb208u: goto P_0c0cb208;
case 0x0c0cb20au: goto P_0c0cb20a;
case 0x0c0cb20cu: goto P_0c0cb20c;
case 0x0c0cb20eu: goto P_0c0cb20e;
case 0x0c0cb210u: goto P_0c0cb210;
case 0x0c0cb212u: goto P_0c0cb212;
case 0x0c0cb214u: goto P_0c0cb214;
case 0x0c0cb216u: goto P_0c0cb216;
case 0x0c0cb218u: goto P_0c0cb218;
case 0x0c0cb244u: goto P_0c0cb244;
case 0x0c0cb246u: goto P_0c0cb246;
case 0x0c0cb248u: goto P_0c0cb248;
case 0x0c0cb24au: goto P_0c0cb24a;
case 0x0c0cb24cu: goto P_0c0cb24c;
case 0x0c0cb24eu: goto P_0c0cb24e;
case 0x0c0cb250u: goto P_0c0cb250;
case 0x0c0cb252u: goto P_0c0cb252;
case 0x0c0cb254u: goto P_0c0cb254;
case 0x0c0cb256u: goto P_0c0cb256;
case 0x0c0cb258u: goto P_0c0cb258;
case 0x0c0cb25au: goto P_0c0cb25a;
case 0x0c0cb25cu: goto P_0c0cb25c;
case 0x0c0cb25eu: goto P_0c0cb25e;
case 0x0c0cb260u: goto P_0c0cb260;
case 0x0c0cb262u: goto P_0c0cb262;
case 0x0c0cb264u: goto P_0c0cb264;
case 0x0c0cb266u: goto P_0c0cb266;
case 0x0c0cb268u: goto P_0c0cb268;
case 0x0c0cb26au: goto P_0c0cb26a;
case 0x0c0cb26cu: goto P_0c0cb26c;
case 0x0c0cb26eu: goto P_0c0cb26e;
case 0x0c0cb270u: goto P_0c0cb270;
case 0x0c0cb272u: goto P_0c0cb272;
case 0x0c0cb274u: goto P_0c0cb274;
case 0x0c0cb276u: goto P_0c0cb276;
case 0x0c0cb278u: goto P_0c0cb278;
case 0x0c0cb27au: goto P_0c0cb27a;
case 0x0c0cb27cu: goto P_0c0cb27c;
case 0x0c0cb27eu: goto P_0c0cb27e;
case 0x0c0cb280u: goto P_0c0cb280;
case 0x0c0cb282u: goto P_0c0cb282;
case 0x0c0cb284u: goto P_0c0cb284;
case 0x0c0cb286u: goto P_0c0cb286;
case 0x0c0cb288u: goto P_0c0cb288;
case 0x0c0cb28au: goto P_0c0cb28a;
case 0x0c0cb28cu: goto P_0c0cb28c;
case 0x0c0cb28eu: goto P_0c0cb28e;
case 0x0c0cb290u: goto P_0c0cb290;
case 0x0c0cb292u: goto P_0c0cb292;
case 0x0c0cb294u: goto P_0c0cb294;
case 0x0c0cb296u: goto P_0c0cb296;
case 0x0c0cb298u: goto P_0c0cb298;
case 0x0c0cb29au: goto P_0c0cb29a;
case 0x0c0cb29cu: goto P_0c0cb29c;
case 0x0c0cb29eu: goto P_0c0cb29e;
case 0x0c0cb2a0u: goto P_0c0cb2a0;
case 0x0c0cb2a2u: goto P_0c0cb2a2;
case 0x0c0cb2a4u: goto P_0c0cb2a4;
case 0x0c0cb2a6u: goto P_0c0cb2a6;
case 0x0c0cb2a8u: goto P_0c0cb2a8;
case 0x0c0cb2aau: goto P_0c0cb2aa;
case 0x0c0cb2acu: goto P_0c0cb2ac;
case 0x0c0cb2aeu: goto P_0c0cb2ae;
case 0x0c0cb2b0u: goto P_0c0cb2b0;
case 0x0c0cb2b2u: goto P_0c0cb2b2;
case 0x0c0cb2b4u: goto P_0c0cb2b4;
case 0x0c0cb2b6u: goto P_0c0cb2b6;
case 0x0c0cb2b8u: goto P_0c0cb2b8;
case 0x0c0cb2bau: goto P_0c0cb2ba;
case 0x0c0cb2bcu: goto P_0c0cb2bc;
case 0x0c0cb2beu: goto P_0c0cb2be;
case 0x0c0cb2c0u: goto P_0c0cb2c0;
case 0x0c0cb2c2u: goto P_0c0cb2c2;
case 0x0c0cb2c4u: goto P_0c0cb2c4;
case 0x0c0cb2c6u: goto P_0c0cb2c6;
case 0x0c0cb2c8u: goto P_0c0cb2c8;
case 0x0c0cb2cau: goto P_0c0cb2ca;
case 0x0c0cb2ccu: goto P_0c0cb2cc;
case 0x0c0cb2ceu: goto P_0c0cb2ce;
case 0x0c0cb2d0u: goto P_0c0cb2d0;
case 0x0c0cb2d2u: goto P_0c0cb2d2;
case 0x0c0cb2d4u: goto P_0c0cb2d4;
case 0x0c0cb2d6u: goto P_0c0cb2d6;
case 0x0c0cb2d8u: goto P_0c0cb2d8;
case 0x0c0cb2dau: goto P_0c0cb2da;
case 0x0c0cb2dcu: goto P_0c0cb2dc;
case 0x0c0cb2deu: goto P_0c0cb2de;
case 0x0c0cb2e0u: goto P_0c0cb2e0;
case 0x0c0cb2e2u: goto P_0c0cb2e2;
case 0x0c0cb2e4u: goto P_0c0cb2e4;
case 0x0c0cb2e6u: goto P_0c0cb2e6;
case 0x0c0cb2e8u: goto P_0c0cb2e8;
case 0x0c0cb2eau: goto P_0c0cb2ea;
case 0x0c0cb2ecu: goto P_0c0cb2ec;
case 0x0c0cb2eeu: goto P_0c0cb2ee;
case 0x0c0cb2f0u: goto P_0c0cb2f0;
case 0x0c0cb2f2u: goto P_0c0cb2f2;
case 0x0c0cb2f4u: goto P_0c0cb2f4;
case 0x0c0cb2f6u: goto P_0c0cb2f6;
case 0x0c0cb2f8u: goto P_0c0cb2f8;
case 0x0c0cb2fau: goto P_0c0cb2fa;
case 0x0c0cb2fcu: goto P_0c0cb2fc;
case 0x0c0cb2feu: goto P_0c0cb2fe;
case 0x0c0cb300u: goto P_0c0cb300;
case 0x0c0cb302u: goto P_0c0cb302;
case 0x0c0cb304u: goto P_0c0cb304;
case 0x0c0cb306u: goto P_0c0cb306;
case 0x0c0cb308u: goto P_0c0cb308;
case 0x0c0cb30au: goto P_0c0cb30a;
case 0x0c0cb30cu: goto P_0c0cb30c;
case 0x0c0cb30eu: goto P_0c0cb30e;
case 0x0c0cb310u: goto P_0c0cb310;
case 0x0c0cb312u: goto P_0c0cb312;
case 0x0c0cb314u: goto P_0c0cb314;
case 0x0c0cb316u: goto P_0c0cb316;
case 0x0c0cb318u: goto P_0c0cb318;
case 0x0c0cb31au: goto P_0c0cb31a;
case 0x0c0cb31cu: goto P_0c0cb31c;
case 0x0c0cb31eu: goto P_0c0cb31e;
case 0x0c0cb320u: goto P_0c0cb320;
case 0x0c0cb322u: goto P_0c0cb322;
case 0x0c0cb324u: goto P_0c0cb324;
case 0x0c0cb326u: goto P_0c0cb326;
case 0x0c0cb328u: goto P_0c0cb328;
case 0x0c0cb32au: goto P_0c0cb32a;
case 0x0c0cb32cu: goto P_0c0cb32c;
case 0x0c0cb32eu: goto P_0c0cb32e;
case 0x0c0cb330u: goto P_0c0cb330;
case 0x0c0cb332u: goto P_0c0cb332;
case 0x0c0cb334u: goto P_0c0cb334;
case 0x0c0cb336u: goto P_0c0cb336;
case 0x0c0cb338u: goto P_0c0cb338;
case 0x0c0cb34cu: goto P_0c0cb34c;
case 0x0c0cb34eu: goto P_0c0cb34e;
case 0x0c0cb350u: goto P_0c0cb350;
case 0x0c0cb352u: goto P_0c0cb352;
case 0x0c0cb354u: goto P_0c0cb354;
case 0x0c0cb356u: goto P_0c0cb356;
case 0x0c0cb358u: goto P_0c0cb358;
case 0x0c0cb35au: goto P_0c0cb35a;
case 0x0c0cb35cu: goto P_0c0cb35c;
case 0x0c0cb35eu: goto P_0c0cb35e;
case 0x0c0cb360u: goto P_0c0cb360;
case 0x0c0cb362u: goto P_0c0cb362;
case 0x0c0cb364u: goto P_0c0cb364;
case 0x0c0cb366u: goto P_0c0cb366;
case 0x0c0cb368u: goto P_0c0cb368;
case 0x0c0cb36au: goto P_0c0cb36a;
case 0x0c0cb36cu: goto P_0c0cb36c;
case 0x0c0cb36eu: goto P_0c0cb36e;
case 0x0c0cb370u: goto P_0c0cb370;
case 0x0c0cb372u: goto P_0c0cb372;
case 0x0c0cb374u: goto P_0c0cb374;
case 0x0c0cb376u: goto P_0c0cb376;
case 0x0c0cb378u: goto P_0c0cb378;
case 0x0c0cb37au: goto P_0c0cb37a;
case 0x0c0cb37cu: goto P_0c0cb37c;
case 0x0c0cb37eu: goto P_0c0cb37e;
case 0x0c0cb380u: goto P_0c0cb380;
case 0x0c0cb382u: goto P_0c0cb382;
case 0x0c0cb384u: goto P_0c0cb384;
case 0x0c0cb386u: goto P_0c0cb386;
case 0x0c0cb388u: goto P_0c0cb388;
case 0x0c0cb38au: goto P_0c0cb38a;
case 0x0c0cb38cu: goto P_0c0cb38c;
case 0x0c0cb38eu: goto P_0c0cb38e;
case 0x0c0cb390u: goto P_0c0cb390;
case 0x0c0cb392u: goto P_0c0cb392;
case 0x0c0cb394u: goto P_0c0cb394;
case 0x0c0cb396u: goto P_0c0cb396;
case 0x0c0cb398u: goto P_0c0cb398;
case 0x0c0cb39au: goto P_0c0cb39a;
case 0x0c0cb39cu: goto P_0c0cb39c;
case 0x0c0cb39eu: goto P_0c0cb39e;
case 0x0c0cb3a0u: goto P_0c0cb3a0;
case 0x0c0cb3a2u: goto P_0c0cb3a2;
case 0x0c0cb3a4u: goto P_0c0cb3a4;
case 0x0c0cb3a6u: goto P_0c0cb3a6;
case 0x0c0cb3a8u: goto P_0c0cb3a8;
case 0x0c0cb3aau: goto P_0c0cb3aa;
case 0x0c0cb3acu: goto P_0c0cb3ac;
case 0x0c0cb3aeu: goto P_0c0cb3ae;
case 0x0c0cb3b0u: goto P_0c0cb3b0;
case 0x0c0cb3b2u: goto P_0c0cb3b2;
case 0x0c0cb3b4u: goto P_0c0cb3b4;
case 0x0c0cb3b6u: goto P_0c0cb3b6;
case 0x0c0cb3b8u: goto P_0c0cb3b8;
case 0x0c0cb3bau: goto P_0c0cb3ba;
case 0x0c0cb3bcu: goto P_0c0cb3bc;
case 0x0c0cb3beu: goto P_0c0cb3be;
case 0x0c0cb3c0u: goto P_0c0cb3c0;
case 0x0c0cb3c2u: goto P_0c0cb3c2;
case 0x0c0cb3c4u: goto P_0c0cb3c4;
case 0x0c0cb3c6u: goto P_0c0cb3c6;
case 0x0c0cb3c8u: goto P_0c0cb3c8;
case 0x0c0cb3cau: goto P_0c0cb3ca;
case 0x0c0cb3ccu: goto P_0c0cb3cc;
case 0x0c0cb3ceu: goto P_0c0cb3ce;
case 0x0c0cb3d0u: goto P_0c0cb3d0;
case 0x0c0cb3d2u: goto P_0c0cb3d2;
case 0x0c0cb3d4u: goto P_0c0cb3d4;
case 0x0c0cb3d6u: goto P_0c0cb3d6;
case 0x0c0cb3d8u: goto P_0c0cb3d8;
case 0x0c0cb3dau: goto P_0c0cb3da;
case 0x0c0cb3dcu: goto P_0c0cb3dc;
case 0x0c0cb3deu: goto P_0c0cb3de;
case 0x0c0cb3e0u: goto P_0c0cb3e0;
case 0x0c0cb3e2u: goto P_0c0cb3e2;
case 0x0c0cb3e4u: goto P_0c0cb3e4;
case 0x0c0cb3e6u: goto P_0c0cb3e6;
case 0x0c0cb3e8u: goto P_0c0cb3e8;
case 0x0c0cb3eau: goto P_0c0cb3ea;
case 0x0c0cb3ecu: goto P_0c0cb3ec;
case 0x0c0cb3eeu: goto P_0c0cb3ee;
case 0x0c0cb3f0u: goto P_0c0cb3f0;
case 0x0c0cb3f2u: goto P_0c0cb3f2;
case 0x0c0cb3f4u: goto P_0c0cb3f4;
case 0x0c0cb3f6u: goto P_0c0cb3f6;
case 0x0c0cb3f8u: goto P_0c0cb3f8;
case 0x0c0cb3fau: goto P_0c0cb3fa;
case 0x0c0cb3fcu: goto P_0c0cb3fc;
case 0x0c0cb3feu: goto P_0c0cb3fe;
case 0x0c0cb400u: goto P_0c0cb400;
case 0x0c0cb402u: goto P_0c0cb402;
case 0x0c0cb404u: goto P_0c0cb404;
case 0x0c0cb406u: goto P_0c0cb406;
case 0x0c0cb408u: goto P_0c0cb408;
case 0x0c0cb40au: goto P_0c0cb40a;
case 0x0c0cb40cu: goto P_0c0cb40c;
case 0x0c0cb40eu: goto P_0c0cb40e;
case 0x0c0cb410u: goto P_0c0cb410;
case 0x0c0cb412u: goto P_0c0cb412;
case 0x0c0cb414u: goto P_0c0cb414;
case 0x0c0cb416u: goto P_0c0cb416;
case 0x0c0cb418u: goto P_0c0cb418;
case 0x0c0cb41au: goto P_0c0cb41a;
case 0x0c0cb41cu: goto P_0c0cb41c;
case 0x0c0cb41eu: goto P_0c0cb41e;
case 0x0c0cb420u: goto P_0c0cb420;
case 0x0c0cb422u: goto P_0c0cb422;
case 0x0c0cb424u: goto P_0c0cb424;
case 0x0c0cb426u: goto P_0c0cb426;
case 0x0c0cb428u: goto P_0c0cb428;
case 0x0c0cb42au: goto P_0c0cb42a;
case 0x0c0cb42cu: goto P_0c0cb42c;
case 0x0c0cb42eu: goto P_0c0cb42e;
case 0x0c0cb430u: goto P_0c0cb430;
case 0x0c0cb432u: goto P_0c0cb432;
case 0x0c0cb434u: goto P_0c0cb434;
case 0x0c0cb436u: goto P_0c0cb436;
case 0x0c0cb438u: goto P_0c0cb438;
case 0x0c0cb43au: goto P_0c0cb43a;
case 0x0c0cb43cu: goto P_0c0cb43c;
case 0x0c0cb43eu: goto P_0c0cb43e;
case 0x0c0cb440u: goto P_0c0cb440;
case 0x0c0cb442u: goto P_0c0cb442;
case 0x0c0cb444u: goto P_0c0cb444;
case 0x0c0cb446u: goto P_0c0cb446;
case 0x0c0cb448u: goto P_0c0cb448;
case 0x0c0cb44au: goto P_0c0cb44a;
case 0x0c0cb44cu: goto P_0c0cb44c;
case 0x0c0cb44eu: goto P_0c0cb44e;
case 0x0c0cb450u: goto P_0c0cb450;
case 0x0c0cb452u: goto P_0c0cb452;
case 0x0c0cb454u: goto P_0c0cb454;
case 0x0c0cb456u: goto P_0c0cb456;
case 0x0c0cb458u: goto P_0c0cb458;
case 0x0c0cb45au: goto P_0c0cb45a;
case 0x0c0cb45cu: goto P_0c0cb45c;
case 0x0c0cb48cu: goto P_0c0cb48c;
case 0x0c0cb48eu: goto P_0c0cb48e;
case 0x0c0cb490u: goto P_0c0cb490;
case 0x0c0cb492u: goto P_0c0cb492;
case 0x0c0cb494u: goto P_0c0cb494;
case 0x0c0cb496u: goto P_0c0cb496;
case 0x0c0cb498u: goto P_0c0cb498;
case 0x0c0cb49au: goto P_0c0cb49a;
case 0x0c0cb49cu: goto P_0c0cb49c;
case 0x0c0cb49eu: goto P_0c0cb49e;
case 0x0c0cb4a0u: goto P_0c0cb4a0;
case 0x0c0cb4a2u: goto P_0c0cb4a2;
case 0x0c0cb4a4u: goto P_0c0cb4a4;
case 0x0c0cb4a6u: goto P_0c0cb4a6;
case 0x0c0cb4a8u: goto P_0c0cb4a8;
case 0x0c0cb4aau: goto P_0c0cb4aa;
case 0x0c0cb4acu: goto P_0c0cb4ac;
case 0x0c0cb4aeu: goto P_0c0cb4ae;
case 0x0c0cb4b0u: goto P_0c0cb4b0;
case 0x0c0cb4b2u: goto P_0c0cb4b2;
case 0x0c0cb4b4u: goto P_0c0cb4b4;
case 0x0c0cb4b6u: goto P_0c0cb4b6;
case 0x0c0cb4b8u: goto P_0c0cb4b8;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0caf5e: /* original 2fe6, guest PC 0x0c0caf5e */
if(!s->budget--) { s->failed_pc=0x0c0caf5eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caf60;
P_0c0caf60: /* original 6e53, guest PC 0x0c0caf60 */
if(!s->budget--) { s->failed_pc=0x0c0caf60u; return 0; }
r[14]=r[5];
goto P_0c0caf62;
P_0c0caf62: /* original 2fd6, guest PC 0x0c0caf62 */
if(!s->budget--) { s->failed_pc=0x0c0caf62u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caf64;
P_0c0caf64: /* original 4f22, guest PC 0x0c0caf64 */
if(!s->budget--) { s->failed_pc=0x0c0caf64u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0caf66;
P_0c0caf66: /* original 7ffc, guest PC 0x0c0caf66 */
if(!s->budget--) { s->failed_pc=0x0c0caf66u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0caf68;
P_0c0caf68: /* original 2f42, guest PC 0x0c0caf68 */
if(!s->budget--) { s->failed_pc=0x0c0caf68u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c0caf6a;
P_0c0caf6a: /* original d135, guest PC 0x0c0caf6a */
if(!s->budget--) { s->failed_pc=0x0c0caf6au; return 0; }
r[1]=read(ram,0x0c0cb040u,4);
goto P_0c0caf6c;
P_0c0caf6c: /* original d333, guest PC 0x0c0caf6c */
if(!s->budget--) { s->failed_pc=0x0c0caf6cu; return 0; }
r[3]=read(ram,0x0c0cb03cu,4);
goto P_0c0caf6e;
P_0c0caf6e: /* original 6212, guest PC 0x0c0caf6e */
if(!s->budget--) { s->failed_pc=0x0c0caf6eu; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c0caf70;
P_0c0caf70: /* original 2238, guest PC 0x0c0caf70 */
if(!s->budget--) { s->failed_pc=0x0c0caf70u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0caf72;
P_0c0caf72: /* original 8f36, guest PC 0x0c0caf72 */
if(!s->budget--) { s->failed_pc=0x0c0caf72u; return 0; }
cond=r[17]&1u;
r[13]=r[6];
if(!cond) { goto P_0c0cafe2; }
goto P_0c0caf76;
P_0c0caf74: /* original 6d63, guest PC 0x0c0caf74 */
if(!s->budget--) { s->failed_pc=0x0c0caf74u; return 0; }
r[13]=r[6];
goto P_0c0caf76;
P_0c0caf76: /* original b039, guest PC 0x0c0caf76 */
if(!s->budget--) { s->failed_pc=0x0c0caf76u; return 0; }
target=code_base|0x0c0cafecu; r[16]=code_base|0x0c0caf7au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0caf7au) { target=s->pc; goto dispatch; }
goto P_0c0caf7a;
P_0c0caf78: /* original 64e3, guest PC 0x0c0caf78 */
if(!s->budget--) { s->failed_pc=0x0c0caf78u; return 0; }
r[4]=r[14];
goto P_0c0caf7a;
P_0c0caf7a: /* original b037, guest PC 0x0c0caf7a */
if(!s->budget--) { s->failed_pc=0x0c0caf7au; return 0; }
target=code_base|0x0c0cafecu; r[16]=code_base|0x0c0caf7eu;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0caf7eu) { target=s->pc; goto dispatch; }
goto P_0c0caf7e;
P_0c0caf7c: /* original 64d3, guest PC 0x0c0caf7c */
if(!s->budget--) { s->failed_pc=0x0c0caf7cu; return 0; }
r[4]=r[13];
goto P_0c0caf7e;
P_0c0caf7e: /* original e048, guest PC 0x0c0caf7e */
if(!s->budget--) { s->failed_pc=0x0c0caf7eu; return 0; }
r[0]=0x00000048u;
goto P_0c0caf80;
P_0c0caf80: /* original 9358, guest PC 0x0c0caf80 */
if(!s->budget--) { s->failed_pc=0x0c0caf80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb034u,2);
goto P_0c0caf82;
P_0c0caf82: /* original 05de, guest PC 0x0c0caf82 */
if(!s->budget--) { s->failed_pc=0x0c0caf82u; return 0; }
r[5]=read(ram,r[13]+r[0],4);
goto P_0c0caf84;
P_0c0caf84: /* original 04ee, guest PC 0x0c0caf84 */
if(!s->budget--) { s->failed_pc=0x0c0caf84u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0caf86;
P_0c0caf86: /* original 245b, guest PC 0x0c0caf86 */
if(!s->budget--) { s->failed_pc=0x0c0caf86u; return 0; }
r[4]|=r[5];
goto P_0c0caf88;
P_0c0caf88: /* original 2438, guest PC 0x0c0caf88 */
if(!s->budget--) { s->failed_pc=0x0c0caf88u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0caf8a;
P_0c0caf8a: /* original 892a, guest PC 0x0c0caf8a */
if(!s->budget--) { s->failed_pc=0x0c0caf8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cafe2; }
goto P_0c0caf8c;
P_0c0caf8c: /* original 62f2, guest PC 0x0c0caf8c */
if(!s->budget--) { s->failed_pc=0x0c0caf8cu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0caf8e;
P_0c0caf8e: /* original e034, guest PC 0x0c0caf8e */
if(!s->budget--) { s->failed_pc=0x0c0caf8eu; return 0; }
r[0]=0x00000034u;
goto P_0c0caf90;
P_0c0caf90: /* original 032c, guest PC 0x0c0caf90 */
if(!s->budget--) { s->failed_pc=0x0c0caf90u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c0caf92;
P_0c0caf92: /* original 2338, guest PC 0x0c0caf92 */
if(!s->budget--) { s->failed_pc=0x0c0caf92u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0caf94;
P_0c0caf94: /* original 8925, guest PC 0x0c0caf94 */
if(!s->budget--) { s->failed_pc=0x0c0caf94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cafe2; }
goto P_0c0caf96;
P_0c0caf96: /* original 904c, guest PC 0x0c0caf96 */
if(!s->budget--) { s->failed_pc=0x0c0caf96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0caf98;
P_0c0caf98: /* original f38d, guest PC 0x0c0caf98 */
if(!s->budget--) { s->failed_pc=0x0c0caf98u; return 0; }
fr[3]=0;
goto P_0c0caf9a;
P_0c0caf9a: /* original f6e6, guest PC 0x0c0caf9a */
if(!s->budget--) { s->failed_pc=0x0c0caf9au; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0caf9c;
P_0c0caf9c: /* original 7008, guest PC 0x0c0caf9c */
if(!s->budget--) { s->failed_pc=0x0c0caf9cu; return 0; }
r[0]+=0x00000008u;
goto P_0c0caf9e;
P_0c0caf9e: /* original f7e6, guest PC 0x0c0caf9e */
if(!s->budget--) { s->failed_pc=0x0c0caf9eu; return 0; }
vf3_matrix_load(s,ram,7,r[14]+r[0]);
goto P_0c0cafa0;
P_0c0cafa0: /* original 70f8, guest PC 0x0c0cafa0 */
if(!s->budget--) { s->failed_pc=0x0c0cafa0u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cafa2;
P_0c0cafa2: /* original f8d6, guest PC 0x0c0cafa2 */
if(!s->budget--) { s->failed_pc=0x0c0cafa2u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0cafa4;
P_0c0cafa4: /* original 7008, guest PC 0x0c0cafa4 */
if(!s->budget--) { s->failed_pc=0x0c0cafa4u; return 0; }
r[0]+=0x00000008u;
goto P_0c0cafa6;
P_0c0cafa6: /* original f46c, guest PC 0x0c0cafa6 */
if(!s->budget--) { s->failed_pc=0x0c0cafa6u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cafa8;
P_0c0cafa8: /* original fb8c, guest PC 0x0c0cafa8 */
if(!s->budget--) { s->failed_pc=0x0c0cafa8u; return 0; }
vf3_matrix_move(s,11,8);
goto P_0c0cafaa;
P_0c0cafaa: /* original fb5d, guest PC 0x0c0cafaa */
if(!s->budget--) { s->failed_pc=0x0c0cafaau; return 0; }
fr[11]&=0x7fffffffu;
goto P_0c0cafac;
P_0c0cafac: /* original f45d, guest PC 0x0c0cafac */
if(!s->budget--) { s->failed_pc=0x0c0cafacu; return 0; }
fr[4]&=0x7fffffffu;
goto P_0c0cafae;
P_0c0cafae: /* original f4b1, guest PC 0x0c0cafae */
if(!s->budget--) { s->failed_pc=0x0c0cafaeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[11],r[18],'-');
goto P_0c0cafb0;
P_0c0cafb0: /* original f9d6, guest PC 0x0c0cafb0 */
if(!s->budget--) { s->failed_pc=0x0c0cafb0u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0cafb2;
P_0c0cafb2: /* original f57c, guest PC 0x0c0cafb2 */
if(!s->budget--) { s->failed_pc=0x0c0cafb2u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cafb4;
P_0c0cafb4: /* original fa9c, guest PC 0x0c0cafb4 */
if(!s->budget--) { s->failed_pc=0x0c0cafb4u; return 0; }
vf3_matrix_move(s,10,9);
goto P_0c0cafb6;
P_0c0cafb6: /* original f345, guest PC 0x0c0cafb6 */
if(!s->budget--) { s->failed_pc=0x0c0cafb6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0cafb8;
P_0c0cafb8: /* original fa5d, guest PC 0x0c0cafb8 */
if(!s->budget--) { s->failed_pc=0x0c0cafb8u; return 0; }
fr[10]&=0x7fffffffu;
goto P_0c0cafba;
P_0c0cafba: /* original f55d, guest PC 0x0c0cafba */
if(!s->budget--) { s->failed_pc=0x0c0cafbau; return 0; }
fr[5]&=0x7fffffffu;
goto P_0c0cafbc;
P_0c0cafbc: /* original 8d02, guest PC 0x0c0cafbc */
if(!s->budget--) { s->failed_pc=0x0c0cafbcu; return 0; }
cond=r[17]&1u;
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
if(cond) { goto P_0c0cafc4; }
goto P_0c0cafc0;
P_0c0cafbe: /* original f5a1, guest PC 0x0c0cafbe */
if(!s->budget--) { s->failed_pc=0x0c0cafbeu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[10],r[18],'-');
goto P_0c0cafc0;
P_0c0cafc0: /* original a001, guest PC 0x0c0cafc0 */
if(!s->budget--) { s->failed_pc=0x0c0cafc0u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cafc6;
P_0c0cafc2: /* original f46c, guest PC 0x0c0cafc2 */
if(!s->budget--) { s->failed_pc=0x0c0cafc2u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cafc4;
P_0c0cafc4: /* original f48c, guest PC 0x0c0cafc4 */
if(!s->budget--) { s->failed_pc=0x0c0cafc4u; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0cafc6;
P_0c0cafc6: /* original f38d, guest PC 0x0c0cafc6 */
if(!s->budget--) { s->failed_pc=0x0c0cafc6u; return 0; }
fr[3]=0;
goto P_0c0cafc8;
P_0c0cafc8: /* original f355, guest PC 0x0c0cafc8 */
if(!s->budget--) { s->failed_pc=0x0c0cafc8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0cafca;
P_0c0cafca: /* original 8901, guest PC 0x0c0cafca */
if(!s->budget--) { s->failed_pc=0x0c0cafcau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cafd0; }
goto P_0c0cafcc;
P_0c0cafcc: /* original a001, guest PC 0x0c0cafcc */
if(!s->budget--) { s->failed_pc=0x0c0cafccu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cafd2;
P_0c0cafce: /* original f57c, guest PC 0x0c0cafce */
if(!s->budget--) { s->failed_pc=0x0c0cafceu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cafd0;
P_0c0cafd0: /* original f59c, guest PC 0x0c0cafd0 */
if(!s->budget--) { s->failed_pc=0x0c0cafd0u; return 0; }
vf3_matrix_move(s,5,9);
goto P_0c0cafd2;
P_0c0cafd2: /* original 902e, guest PC 0x0c0cafd2 */
if(!s->budget--) { s->failed_pc=0x0c0cafd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb032u,2);
goto P_0c0cafd4;
P_0c0cafd4: /* original fe47, guest PC 0x0c0cafd4 */
if(!s->budget--) { s->failed_pc=0x0c0cafd4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0cafd6;
P_0c0cafd6: /* original 7008, guest PC 0x0c0cafd6 */
if(!s->budget--) { s->failed_pc=0x0c0cafd6u; return 0; }
r[0]+=0x00000008u;
goto P_0c0cafd8;
P_0c0cafd8: /* original fe57, guest PC 0x0c0cafd8 */
if(!s->budget--) { s->failed_pc=0x0c0cafd8u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0cafda;
P_0c0cafda: /* original 70f8, guest PC 0x0c0cafda */
if(!s->budget--) { s->failed_pc=0x0c0cafdau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cafdc;
P_0c0cafdc: /* original fd47, guest PC 0x0c0cafdc */
if(!s->budget--) { s->failed_pc=0x0c0cafdcu; return 0; }
vf3_matrix_store(s,ram,4,r[13]+r[0]);
goto P_0c0cafde;
P_0c0cafde: /* original 7008, guest PC 0x0c0cafde */
if(!s->budget--) { s->failed_pc=0x0c0cafdeu; return 0; }
r[0]+=0x00000008u;
goto P_0c0cafe0;
P_0c0cafe0: /* original fd57, guest PC 0x0c0cafe0 */
if(!s->budget--) { s->failed_pc=0x0c0cafe0u; return 0; }
vf3_matrix_store(s,ram,5,r[13]+r[0]);
goto P_0c0cafe2;
P_0c0cafe2: /* original 7f04, guest PC 0x0c0cafe2 */
if(!s->budget--) { s->failed_pc=0x0c0cafe2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0cafe4;
P_0c0cafe4: /* original 4f26, guest PC 0x0c0cafe4 */
if(!s->budget--) { s->failed_pc=0x0c0cafe4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cafe6;
P_0c0cafe6: /* original 6df6, guest PC 0x0c0cafe6 */
if(!s->budget--) { s->failed_pc=0x0c0cafe6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cafe8;
P_0c0cafe8: /* original 000b, guest PC 0x0c0cafe8 */
if(!s->budget--) { s->failed_pc=0x0c0cafe8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cafea: /* original 6ef6, guest PC 0x0c0cafea */
if(!s->budget--) { s->failed_pc=0x0c0cafeau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0cafec;
P_0c0cafec: /* original 2fe6, guest PC 0x0c0cafec */
if(!s->budget--) { s->failed_pc=0x0c0cafecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cafee;
P_0c0cafee: /* original e368, guest PC 0x0c0cafee */
if(!s->budget--) { s->failed_pc=0x0c0cafeeu; return 0; }
r[3]=0x00000068u;
goto P_0c0caff0;
P_0c0caff0: /* original 2fd6, guest PC 0x0c0caff0 */
if(!s->budget--) { s->failed_pc=0x0c0caff0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caff2;
P_0c0caff2: /* original e040, guest PC 0x0c0caff2 */
if(!s->budget--) { s->failed_pc=0x0c0caff2u; return 0; }
r[0]=0x00000040u;
goto P_0c0caff4;
P_0c0caff4: /* original 2fc6, guest PC 0x0c0caff4 */
if(!s->budget--) { s->failed_pc=0x0c0caff4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caff6;
P_0c0caff6: /* original 6e43, guest PC 0x0c0caff6 */
if(!s->budget--) { s->failed_pc=0x0c0caff6u; return 0; }
r[14]=r[4];
goto P_0c0caff8;
P_0c0caff8: /* original 2fb6, guest PC 0x0c0caff8 */
if(!s->budget--) { s->failed_pc=0x0c0caff8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caffa;
P_0c0caffa: /* original 2fa6, guest PC 0x0c0caffa */
if(!s->budget--) { s->failed_pc=0x0c0caffau; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caffc;
P_0c0caffc: /* original 2f96, guest PC 0x0c0caffc */
if(!s->budget--) { s->failed_pc=0x0c0caffcu; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0caffe;
P_0c0caffe: /* original 2f86, guest PC 0x0c0caffe */
if(!s->budget--) { s->failed_pc=0x0c0caffeu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb000;
P_0c0cb000: /* original fffb, guest PC 0x0c0cb000 */
if(!s->budget--) { s->failed_pc=0x0c0cb000u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c0cb002;
P_0c0cb002: /* original ffeb, guest PC 0x0c0cb002 */
if(!s->budget--) { s->failed_pc=0x0c0cb002u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c0cb004;
P_0c0cb004: /* original ffdb, guest PC 0x0c0cb004 */
if(!s->budget--) { s->failed_pc=0x0c0cb004u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,13,r[15]);
goto P_0c0cb006;
P_0c0cb006: /* original ffcb, guest PC 0x0c0cb006 */
if(!s->budget--) { s->failed_pc=0x0c0cb006u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,12,r[15]);
goto P_0c0cb008;
P_0c0cb008: /* original 4f22, guest PC 0x0c0cb008 */
if(!s->budget--) { s->failed_pc=0x0c0cb008u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cb00a;
P_0c0cb00a: /* original d40e, guest PC 0x0c0cb00a */
if(!s->budget--) { s->failed_pc=0x0c0cb00au; return 0; }
r[4]=read(ram,0x0c0cb044u,4);
goto P_0c0cb00c;
P_0c0cb00c: /* original 7f8c, guest PC 0x0c0cb00c */
if(!s->budget--) { s->failed_pc=0x0c0cb00cu; return 0; }
r[15]+=0xffffff8cu;
goto P_0c0cb00e;
P_0c0cb00e: /* original 0f36, guest PC 0x0c0cb00e */
if(!s->budget--) { s->failed_pc=0x0c0cb00eu; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0cb010;
P_0c0cb010: /* original e048, guest PC 0x0c0cb010 */
if(!s->budget--) { s->failed_pc=0x0c0cb010u; return 0; }
r[0]=0x00000048u;
goto P_0c0cb012;
P_0c0cb012: /* original 0cee, guest PC 0x0c0cb012 */
if(!s->budget--) { s->failed_pc=0x0c0cb012u; return 0; }
r[12]=read(ram,r[14]+r[0],4);
goto P_0c0cb014;
P_0c0cb014: /* original e05c, guest PC 0x0c0cb014 */
if(!s->budget--) { s->failed_pc=0x0c0cb014u; return 0; }
r[0]=0x0000005cu;
goto P_0c0cb016;
P_0c0cb016: /* original d30c, guest PC 0x0c0cb016 */
if(!s->budget--) { s->failed_pc=0x0c0cb016u; return 0; }
r[3]=read(ram,0x0c0cb048u,4);
goto P_0c0cb018;
P_0c0cb018: /* original 6de2, guest PC 0x0c0cb018 */
if(!s->budget--) { s->failed_pc=0x0c0cb018u; return 0; }
tmp=read(ram,r[14],4);
r[13]=tmp;
goto P_0c0cb01a;
P_0c0cb01a: /* original 0f36, guest PC 0x0c0cb01a */
if(!s->budget--) { s->failed_pc=0x0c0cb01au; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0cb01c;
P_0c0cb01c: /* original d20b, guest PC 0x0c0cb01c */
if(!s->budget--) { s->failed_pc=0x0c0cb01cu; return 0; }
r[2]=read(ram,0x0c0cb04cu,4);
goto P_0c0cb01e;
P_0c0cb01e: /* original 6020, guest PC 0x0c0cb01e */
if(!s->budget--) { s->failed_pc=0x0c0cb01eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0cb020;
P_0c0cb020: /* original 600c, guest PC 0x0c0cb020 */
if(!s->budget--) { s->failed_pc=0x0c0cb020u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb022;
P_0c0cb022: /* original c90f, guest PC 0x0c0cb022 */
if(!s->budget--) { s->failed_pc=0x0c0cb022u; return 0; }
r[0]&=15u;
goto P_0c0cb024;
P_0c0cb024: /* original 880d, guest PC 0x0c0cb024 */
if(!s->budget--) { s->failed_pc=0x0c0cb024u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0cb026;
P_0c0cb026: /* original 8b13, guest PC 0x0c0cb026 */
if(!s->budget--) { s->failed_pc=0x0c0cb026u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb050; }
goto P_0c0cb028;
P_0c0cb028: /* original b279, guest PC 0x0c0cb028 */
if(!s->budget--) { s->failed_pc=0x0c0cb028u; return 0; }
target=code_base|0x0c0cb51eu; r[16]=code_base|0x0c0cb02cu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb02cu) { target=s->pc; goto dispatch; }
goto P_0c0cb02c;
P_0c0cb02a: /* original 64e3, guest PC 0x0c0cb02a */
if(!s->budget--) { s->failed_pc=0x0c0cb02au; return 0; }
r[4]=r[14];
goto P_0c0cb02c;
P_0c0cb02c: /* original a237, guest PC 0x0c0cb02c */
if(!s->budget--) { s->failed_pc=0x0c0cb02cu; return 0; }
goto P_0c0cb49e;
P_0c0cb02e: /* original 0009, guest PC 0x0c0cb02e */
if(!s->budget--) { s->failed_pc=0x0c0cb02eu; return 0; }
if(!vf3_matrix_family(0x0c0cb030u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb030u; return 0; } return 1;
P_0c0cb050: /* original 904c, guest PC 0x0c0cb050 */
if(!s->budget--) { s->failed_pc=0x0c0cb050u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0ecu,2);
goto P_0c0cb052;
P_0c0cb052: /* original d32a, guest PC 0x0c0cb052 */
if(!s->budget--) { s->failed_pc=0x0c0cb052u; return 0; }
r[3]=read(ram,0x0c0cb0fcu,4);
goto P_0c0cb054;
P_0c0cb054: /* original 024e, guest PC 0x0c0cb054 */
if(!s->budget--) { s->failed_pc=0x0c0cb054u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0cb056;
P_0c0cb056: /* original d928, guest PC 0x0c0cb056 */
if(!s->budget--) { s->failed_pc=0x0c0cb056u; return 0; }
r[9]=read(ram,0x0c0cb0f8u,4);
goto P_0c0cb058;
P_0c0cb058: /* original 2238, guest PC 0x0c0cb058 */
if(!s->budget--) { s->failed_pc=0x0c0cb058u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cb05a;
P_0c0cb05a: /* original 8d5b, guest PC 0x0c0cb05a */
if(!s->budget--) { s->failed_pc=0x0c0cb05au; return 0; }
cond=r[17]&1u;
r[9]&=r[12];
if(cond) { goto P_0c0cb114; }
goto P_0c0cb05e;
P_0c0cb05c: /* original 29c9, guest PC 0x0c0cb05c */
if(!s->budget--) { s->failed_pc=0x0c0cb05cu; return 0; }
r[9]&=r[12];
goto P_0c0cb05e;
P_0c0cb05e: /* original 9146, guest PC 0x0c0cb05e */
if(!s->budget--) { s->failed_pc=0x0c0cb05eu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0eeu,2);
goto P_0c0cb060;
P_0c0cb060: /* original 21c8, guest PC 0x0c0cb060 */
if(!s->budget--) { s->failed_pc=0x0c0cb060u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[12])==0)!=0);
goto P_0c0cb062;
P_0c0cb062: /* original 8b57, guest PC 0x0c0cb062 */
if(!s->budget--) { s->failed_pc=0x0c0cb062u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb114; }
goto P_0c0cb064;
P_0c0cb064: /* original 2998, guest PC 0x0c0cb064 */
if(!s->budget--) { s->failed_pc=0x0c0cb064u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0cb066;
P_0c0cb066: /* original 8b02, guest PC 0x0c0cb066 */
if(!s->budget--) { s->failed_pc=0x0c0cb066u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb06e; }
goto P_0c0cb068;
P_0c0cb068: /* original d325, guest PC 0x0c0cb068 */
if(!s->budget--) { s->failed_pc=0x0c0cb068u; return 0; }
r[3]=read(ram,0x0c0cb100u,4);
goto P_0c0cb06a;
P_0c0cb06a: /* original 23c8, guest PC 0x0c0cb06a */
if(!s->budget--) { s->failed_pc=0x0c0cb06au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0cb06c;
P_0c0cb06c: /* original 8952, guest PC 0x0c0cb06c */
if(!s->budget--) { s->failed_pc=0x0c0cb06cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb114; }
goto P_0c0cb06e;
P_0c0cb06e: /* original e03c, guest PC 0x0c0cb06e */
if(!s->budget--) { s->failed_pc=0x0c0cb06eu; return 0; }
r[0]=0x0000003cu;
goto P_0c0cb070;
P_0c0cb070: /* original 933e, guest PC 0x0c0cb070 */
if(!s->budget--) { s->failed_pc=0x0c0cb070u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0f0u,2);
goto P_0c0cb072;
P_0c0cb072: /* original 02ed, guest PC 0x0c0cb072 */
if(!s->budget--) { s->failed_pc=0x0c0cb072u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0cb074;
P_0c0cb074: /* original 622d, guest PC 0x0c0cb074 */
if(!s->budget--) { s->failed_pc=0x0c0cb074u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0cb076;
P_0c0cb076: /* original 3230, guest PC 0x0c0cb076 */
if(!s->budget--) { s->failed_pc=0x0c0cb076u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0cb078;
P_0c0cb078: /* original 8d4c, guest PC 0x0c0cb078 */
if(!s->budget--) { s->failed_pc=0x0c0cb078u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[2],4);
if(cond) { goto P_0c0cb114; }
goto P_0c0cb07c;
P_0c0cb07a: /* original 1f22, guest PC 0x0c0cb07a */
if(!s->budget--) { s->failed_pc=0x0c0cb07au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cb07c;
P_0c0cb07c: /* original 9039, guest PC 0x0c0cb07c */
if(!s->budget--) { s->failed_pc=0x0c0cb07cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0f2u,2);
goto P_0c0cb07e;
P_0c0cb07e: /* original 3200, guest PC 0x0c0cb07e */
if(!s->budget--) { s->failed_pc=0x0c0cb07eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[0])!=0);
goto P_0c0cb080;
P_0c0cb080: /* original 8948, guest PC 0x0c0cb080 */
if(!s->budget--) { s->failed_pc=0x0c0cb080u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb114; }
goto P_0c0cb082;
P_0c0cb082: /* original 63f3, guest PC 0x0c0cb082 */
if(!s->budget--) { s->failed_pc=0x0c0cb082u; return 0; }
r[3]=r[15];
goto P_0c0cb084;
P_0c0cb084: /* original 7308, guest PC 0x0c0cb084 */
if(!s->budget--) { s->failed_pc=0x0c0cb084u; return 0; }
r[3]+=0x00000008u;
goto P_0c0cb086;
P_0c0cb086: /* original 2f36, guest PC 0x0c0cb086 */
if(!s->budget--) { s->failed_pc=0x0c0cb086u; return 0; }
tmp=r[3]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0cb088;
P_0c0cb088: /* original 66f3, guest PC 0x0c0cb088 */
if(!s->budget--) { s->failed_pc=0x0c0cb088u; return 0; }
r[6]=r[15];
goto P_0c0cb08a;
P_0c0cb08a: /* original 65f3, guest PC 0x0c0cb08a */
if(!s->budget--) { s->failed_pc=0x0c0cb08au; return 0; }
r[5]=r[15];
goto P_0c0cb08c;
P_0c0cb08c: /* original 67f3, guest PC 0x0c0cb08c */
if(!s->budget--) { s->failed_pc=0x0c0cb08cu; return 0; }
r[7]=r[15];
goto P_0c0cb08e;
P_0c0cb08e: /* original d21d, guest PC 0x0c0cb08e */
if(!s->budget--) { s->failed_pc=0x0c0cb08eu; return 0; }
r[2]=read(ram,0x0c0cb104u,4);
goto P_0c0cb090;
P_0c0cb090: /* original 7504, guest PC 0x0c0cb090 */
if(!s->budget--) { s->failed_pc=0x0c0cb090u; return 0; }
r[5]+=0x00000004u;
goto P_0c0cb092;
P_0c0cb092: /* original 7710, guest PC 0x0c0cb092 */
if(!s->budget--) { s->failed_pc=0x0c0cb092u; return 0; }
r[7]+=0x00000010u;
goto P_0c0cb094;
P_0c0cb094: /* original 7608, guest PC 0x0c0cb094 */
if(!s->budget--) { s->failed_pc=0x0c0cb094u; return 0; }
r[6]+=0x00000008u;
goto P_0c0cb096;
P_0c0cb096: /* original 420b, guest PC 0x0c0cb096 */
if(!s->budget--) { s->failed_pc=0x0c0cb096u; return 0; }
target=r[2];
r[16]=code_base|0x0c0cb09au;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb09au) { target=s->pc; goto dispatch; }
goto P_0c0cb09a;
P_0c0cb098: /* original 64e3, guest PC 0x0c0cb098 */
if(!s->budget--) { s->failed_pc=0x0c0cb098u; return 0; }
r[4]=r[14];
goto P_0c0cb09a;
P_0c0cb09a: /* original 7f04, guest PC 0x0c0cb09a */
if(!s->budget--) { s->failed_pc=0x0c0cb09au; return 0; }
r[15]+=0x00000004u;
goto P_0c0cb09c;
P_0c0cb09c: /* original f3f8, guest PC 0x0c0cb09c */
if(!s->budget--) { s->failed_pc=0x0c0cb09cu; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb09e;
P_0c0cb09e: /* original e03c, guest PC 0x0c0cb09e */
if(!s->budget--) { s->failed_pc=0x0c0cb09eu; return 0; }
r[0]=0x0000003cu;
goto P_0c0cb0a0;
P_0c0cb0a0: /* original ff37, guest PC 0x0c0cb0a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb0a2;
P_0c0cb0a2: /* original 54f2, guest PC 0x0c0cb0a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a2u; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cb0a4;
P_0c0cb0a4: /* original d318, guest PC 0x0c0cb0a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a4u; return 0; }
r[3]=read(ram,0x0c0cb108u,4);
goto P_0c0cb0a6;
P_0c0cb0a6: /* original 430b, guest PC 0x0c0cb0a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cb0aau;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb0aau) { target=s->pc; goto dispatch; }
goto P_0c0cb0aa;
P_0c0cb0a8: /* original 644f, guest PC 0x0c0cb0a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0a8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0cb0aa;
P_0c0cb0aa: /* original ff0a, guest PC 0x0c0cb0aa */
if(!s->budget--) { s->failed_pc=0x0c0cb0aau; return 0; }
vf3_matrix_store(s,ram,0,r[15]);
goto P_0c0cb0ac;
P_0c0cb0ac: /* original d317, guest PC 0x0c0cb0ac */
if(!s->budget--) { s->failed_pc=0x0c0cb0acu; return 0; }
r[3]=read(ram,0x0c0cb10cu,4);
goto P_0c0cb0ae;
P_0c0cb0ae: /* original 54f2, guest PC 0x0c0cb0ae */
if(!s->budget--) { s->failed_pc=0x0c0cb0aeu; return 0; }
r[4]=read(ram,r[15]+8,4);
goto P_0c0cb0b0;
P_0c0cb0b0: /* original 430b, guest PC 0x0c0cb0b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b0u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cb0b4u;
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb0b4u) { target=s->pc; goto dispatch; }
goto P_0c0cb0b4;
P_0c0cb0b2: /* original 644f, guest PC 0x0c0cb0b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0cb0b4;
P_0c0cb0b4: /* original c716, guest PC 0x0c0cb0b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b4u; return 0; }
r[0]=code_base|0x000cb110u;
goto P_0c0cb0b6;
P_0c0cb0b6: /* original f70c, guest PC 0x0c0cb0b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b6u; return 0; }
vf3_matrix_move(s,7,0);
goto P_0c0cb0b8;
P_0c0cb0b8: /* original f308, guest PC 0x0c0cb0b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0b8u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb0ba;
P_0c0cb0ba: /* original e00c, guest PC 0x0c0cb0ba */
if(!s->budget--) { s->failed_pc=0x0c0cb0bau; return 0; }
r[0]=0x0000000cu;
goto P_0c0cb0bc;
P_0c0cb0bc: /* original ff37, guest PC 0x0c0cb0bc */
if(!s->budget--) { s->failed_pc=0x0c0cb0bcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb0be;
P_0c0cb0be: /* original e00c, guest PC 0x0c0cb0be */
if(!s->budget--) { s->failed_pc=0x0c0cb0beu; return 0; }
r[0]=0x0000000cu;
goto P_0c0cb0c0;
P_0c0cb0c0: /* original f3f8, guest PC 0x0c0cb0c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c0u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb0c2;
P_0c0cb0c2: /* original f34d, guest PC 0x0c0cb0c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c2u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cb0c4;
P_0c0cb0c4: /* original ff3a, guest PC 0x0c0cb0c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c4u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb0c6;
P_0c0cb0c6: /* original f2f6, guest PC 0x0c0cb0c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c6u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb0c8;
P_0c0cb0c8: /* original e03c, guest PC 0x0c0cb0c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0c8u; return 0; }
r[0]=0x0000003cu;
goto P_0c0cb0ca;
P_0c0cb0ca: /* original f1f6, guest PC 0x0c0cb0ca */
if(!s->budget--) { s->failed_pc=0x0c0cb0cau; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb0cc;
P_0c0cb0cc: /* original e004, guest PC 0x0c0cb0cc */
if(!s->budget--) { s->failed_pc=0x0c0cb0ccu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb0ce;
P_0c0cb0ce: /* original f63c, guest PC 0x0c0cb0ce */
if(!s->budget--) { s->failed_pc=0x0c0cb0ceu; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0cb0d0;
P_0c0cb0d0: /* original f622, guest PC 0x0c0cb0d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[2],r[18],'*');
goto P_0c0cb0d2;
P_0c0cb0d2: /* original f722, guest PC 0x0c0cb0d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d2u; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c0cb0d4;
P_0c0cb0d4: /* original ff1a, guest PC 0x0c0cb0d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d4u; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0cb0d6;
P_0c0cb0d6: /* original f5f6, guest PC 0x0c0cb0d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d6u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0cb0d8;
P_0c0cb0d8: /* original f54d, guest PC 0x0c0cb0d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0d8u; return 0; }
fr[5]^=0x80000000u;
goto P_0c0cb0da;
P_0c0cb0da: /* original b1ee, guest PC 0x0c0cb0da */
if(!s->budget--) { s->failed_pc=0x0c0cb0dau; return 0; }
target=code_base|0x0c0cb4bau; r[16]=code_base|0x0c0cb0deu;
vf3_matrix_move(s,4,1);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb0deu) { target=s->pc; goto dispatch; }
goto P_0c0cb0de;
P_0c0cb0dc: /* original f41c, guest PC 0x0c0cb0dc */
if(!s->budget--) { s->failed_pc=0x0c0cb0dcu; return 0; }
vf3_matrix_move(s,4,1);
goto P_0c0cb0de;
P_0c0cb0de: /* original e014, guest PC 0x0c0cb0de */
if(!s->budget--) { s->failed_pc=0x0c0cb0deu; return 0; }
r[0]=0x00000014u;
goto P_0c0cb0e0;
P_0c0cb0e0: /* original f40c, guest PC 0x0c0cb0e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e0u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb0e2;
P_0c0cb0e2: /* original ff47, guest PC 0x0c0cb0e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e2u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0cb0e4;
P_0c0cb0e4: /* original 9006, guest PC 0x0c0cb0e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb0f4u,2);
goto P_0c0cb0e6;
P_0c0cb0e6: /* original f34c, guest PC 0x0c0cb0e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e6u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb0e8;
P_0c0cb0e8: /* original a018, guest PC 0x0c0cb0e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb0e8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb11c;
P_0c0cb0ea: /* original fe37, guest PC 0x0c0cb0ea */
if(!s->budget--) { s->failed_pc=0x0c0cb0eau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
if(!vf3_matrix_family(0x0c0cb0ecu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb0ecu; return 0; } return 1;
P_0c0cb114: /* original c743, guest PC 0x0c0cb114 */
if(!s->budget--) { s->failed_pc=0x0c0cb114u; return 0; }
r[0]=code_base|0x000cb224u;
goto P_0c0cb116;
P_0c0cb116: /* original f308, guest PC 0x0c0cb116 */
if(!s->budget--) { s->failed_pc=0x0c0cb116u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb118;
P_0c0cb118: /* original e014, guest PC 0x0c0cb118 */
if(!s->budget--) { s->failed_pc=0x0c0cb118u; return 0; }
r[0]=0x00000014u;
goto P_0c0cb11a;
P_0c0cb11a: /* original ff37, guest PC 0x0c0cb11a */
if(!s->budget--) { s->failed_pc=0x0c0cb11au; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb11c;
P_0c0cb11c: /* original d342, guest PC 0x0c0cb11c */
if(!s->budget--) { s->failed_pc=0x0c0cb11cu; return 0; }
r[3]=read(ram,0x0c0cb228u,4);
goto P_0c0cb11e;
P_0c0cb11e: /* original 430b, guest PC 0x0c0cb11e */
if(!s->budget--) { s->failed_pc=0x0c0cb11eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0cb122u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb122u) { target=s->pc; goto dispatch; }
goto P_0c0cb122;
P_0c0cb120: /* original 64e3, guest PC 0x0c0cb120 */
if(!s->budget--) { s->failed_pc=0x0c0cb120u; return 0; }
r[4]=r[14];
goto P_0c0cb122;
P_0c0cb122: /* original e206, guest PC 0x0c0cb122 */
if(!s->budget--) { s->failed_pc=0x0c0cb122u; return 0; }
r[2]=0x00000006u;
goto P_0c0cb124;
P_0c0cb124: /* original 1f2d, guest PC 0x0c0cb124 */
if(!s->budget--) { s->failed_pc=0x0c0cb124u; return 0; }
write(ram,r[15]+52,r[2],4);
goto P_0c0cb126;
P_0c0cb126: /* original ea00, guest PC 0x0c0cb126 */
if(!s->budget--) { s->failed_pc=0x0c0cb126u; return 0; }
r[10]=0x00000000u;
goto P_0c0cb128;
P_0c0cb128: /* original 9077, guest PC 0x0c0cb128 */
if(!s->budget--) { s->failed_pc=0x0c0cb128u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb21au,2);
goto P_0c0cb12a;
P_0c0cb12a: /* original 9377, guest PC 0x0c0cb12a */
if(!s->budget--) { s->failed_pc=0x0c0cb12au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb21cu,2);
goto P_0c0cb12c;
P_0c0cb12c: /* original 08ee, guest PC 0x0c0cb12c */
if(!s->budget--) { s->failed_pc=0x0c0cb12cu; return 0; }
r[8]=read(ram,r[14]+r[0],4);
goto P_0c0cb12e;
P_0c0cb12e: /* original e054, guest PC 0x0c0cb12e */
if(!s->budget--) { s->failed_pc=0x0c0cb12eu; return 0; }
r[0]=0x00000054u;
goto P_0c0cb130;
P_0c0cb130: /* original 33ec, guest PC 0x0c0cb130 */
if(!s->budget--) { s->failed_pc=0x0c0cb130u; return 0; }
r[3]+=r[14];
goto P_0c0cb132;
P_0c0cb132: /* original 0f36, guest PC 0x0c0cb132 */
if(!s->budget--) { s->failed_pc=0x0c0cb132u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0cb134;
P_0c0cb134: /* original c73e, guest PC 0x0c0cb134 */
if(!s->budget--) { s->failed_pc=0x0c0cb134u; return 0; }
r[0]=code_base|0x000cb230u;
goto P_0c0cb136;
P_0c0cb136: /* original 9272, guest PC 0x0c0cb136 */
if(!s->budget--) { s->failed_pc=0x0c0cb136u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb21eu,2);
goto P_0c0cb138;
P_0c0cb138: /* original 32ec, guest PC 0x0c0cb138 */
if(!s->budget--) { s->failed_pc=0x0c0cb138u; return 0; }
r[2]+=r[14];
goto P_0c0cb13a;
P_0c0cb13a: /* original 1f2c, guest PC 0x0c0cb13a */
if(!s->budget--) { s->failed_pc=0x0c0cb13au; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c0cb13c;
P_0c0cb13c: /* original d33b, guest PC 0x0c0cb13c */
if(!s->budget--) { s->failed_pc=0x0c0cb13cu; return 0; }
r[3]=read(ram,0x0c0cb22cu,4);
goto P_0c0cb13e;
P_0c0cb13e: /* original 1f3e, guest PC 0x0c0cb13e */
if(!s->budget--) { s->failed_pc=0x0c0cb13eu; return 0; }
write(ram,r[15]+56,r[3],4);
goto P_0c0cb140;
P_0c0cb140: /* original f308, guest PC 0x0c0cb140 */
if(!s->budget--) { s->failed_pc=0x0c0cb140u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb142;
P_0c0cb142: /* original e02c, guest PC 0x0c0cb142 */
if(!s->budget--) { s->failed_pc=0x0c0cb142u; return 0; }
r[0]=0x0000002cu;
goto P_0c0cb144;
P_0c0cb144: /* original ff37, guest PC 0x0c0cb144 */
if(!s->budget--) { s->failed_pc=0x0c0cb144u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb146;
P_0c0cb146: /* original c73b, guest PC 0x0c0cb146 */
if(!s->budget--) { s->failed_pc=0x0c0cb146u; return 0; }
r[0]=code_base|0x000cb234u;
goto P_0c0cb148;
P_0c0cb148: /* original f308, guest PC 0x0c0cb148 */
if(!s->budget--) { s->failed_pc=0x0c0cb148u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb14a;
P_0c0cb14a: /* original e028, guest PC 0x0c0cb14a */
if(!s->budget--) { s->failed_pc=0x0c0cb14au; return 0; }
r[0]=0x00000028u;
goto P_0c0cb14c;
P_0c0cb14c: /* original ff37, guest PC 0x0c0cb14c */
if(!s->budget--) { s->failed_pc=0x0c0cb14cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb14e;
P_0c0cb14e: /* original e010, guest PC 0x0c0cb14e */
if(!s->budget--) { s->failed_pc=0x0c0cb14eu; return 0; }
r[0]=0x00000010u;
goto P_0c0cb150;
P_0c0cb150: /* original fc8d, guest PC 0x0c0cb150 */
if(!s->budget--) { s->failed_pc=0x0c0cb150u; return 0; }
fr[12]=0;
goto P_0c0cb152;
P_0c0cb152: /* original 5bfd, guest PC 0x0c0cb152 */
if(!s->budget--) { s->failed_pc=0x0c0cb152u; return 0; }
r[11]=read(ram,r[15]+52,4);
goto P_0c0cb154;
P_0c0cb154: /* original ffc7, guest PC 0x0c0cb154 */
if(!s->budget--) { s->failed_pc=0x0c0cb154u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0cb156;
P_0c0cb156: /* original e060, guest PC 0x0c0cb156 */
if(!s->budget--) { s->failed_pc=0x0c0cb156u; return 0; }
r[0]=0x00000060u;
goto P_0c0cb158;
P_0c0cb158: /* original ffc7, guest PC 0x0c0cb158 */
if(!s->budget--) { s->failed_pc=0x0c0cb158u; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0cb15a;
P_0c0cb15a: /* original e064, guest PC 0x0c0cb15a */
if(!s->budget--) { s->failed_pc=0x0c0cb15au; return 0; }
r[0]=0x00000064u;
goto P_0c0cb15c;
P_0c0cb15c: /* original ffc7, guest PC 0x0c0cb15c */
if(!s->budget--) { s->failed_pc=0x0c0cb15cu; return 0; }
vf3_matrix_store(s,ram,12,r[15]+r[0]);
goto P_0c0cb15e;
P_0c0cb15e: /* original d336, guest PC 0x0c0cb15e */
if(!s->budget--) { s->failed_pc=0x0c0cb15eu; return 0; }
r[3]=read(ram,0x0c0cb238u,4);
goto P_0c0cb160;
P_0c0cb160: /* original 6030, guest PC 0x0c0cb160 */
if(!s->budget--) { s->failed_pc=0x0c0cb160u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0cb162;
P_0c0cb162: /* original 61f3, guest PC 0x0c0cb162 */
if(!s->budget--) { s->failed_pc=0x0c0cb162u; return 0; }
r[1]=r[15];
goto P_0c0cb164;
P_0c0cb164: /* original 600c, guest PC 0x0c0cb164 */
if(!s->budget--) { s->failed_pc=0x0c0cb164u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb166;
P_0c0cb166: /* original 7158, guest PC 0x0c0cb166 */
if(!s->budget--) { s->failed_pc=0x0c0cb166u; return 0; }
r[1]+=0x00000058u;
goto P_0c0cb168;
P_0c0cb168: /* original c90f, guest PC 0x0c0cb168 */
if(!s->budget--) { s->failed_pc=0x0c0cb168u; return 0; }
r[0]&=15u;
goto P_0c0cb16a;
P_0c0cb16a: /* original 2102, guest PC 0x0c0cb16a */
if(!s->budget--) { s->failed_pc=0x0c0cb16au; return 0; }
write(ram,r[1],r[0],4);
goto P_0c0cb16c;
P_0c0cb16c: /* original 53fd, guest PC 0x0c0cb16c */
if(!s->budget--) { s->failed_pc=0x0c0cb16cu; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c0cb16e;
P_0c0cb16e: /* original 33b8, guest PC 0x0c0cb16e */
if(!s->budget--) { s->failed_pc=0x0c0cb16eu; return 0; }
r[3]-=r[11];
goto P_0c0cb170;
P_0c0cb170: /* original 1f32, guest PC 0x0c0cb170 */
if(!s->budget--) { s->failed_pc=0x0c0cb170u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cb172;
P_0c0cb172: /* original 54fe, guest PC 0x0c0cb172 */
if(!s->budget--) { s->failed_pc=0x0c0cb172u; return 0; }
r[4]=read(ram,r[15]+56,4);
goto P_0c0cb174;
P_0c0cb174: /* original d231, guest PC 0x0c0cb174 */
if(!s->budget--) { s->failed_pc=0x0c0cb174u; return 0; }
r[2]=read(ram,0x0c0cb23cu,4);
goto P_0c0cb176;
P_0c0cb176: /* original 343c, guest PC 0x0c0cb176 */
if(!s->budget--) { s->failed_pc=0x0c0cb176u; return 0; }
r[4]+=r[3];
goto P_0c0cb178;
P_0c0cb178: /* original 6140, guest PC 0x0c0cb178 */
if(!s->budget--) { s->failed_pc=0x0c0cb178u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[1]=tmp;
goto P_0c0cb17a;
P_0c0cb17a: /* original 420b, guest PC 0x0c0cb17a */
if(!s->budget--) { s->failed_pc=0x0c0cb17au; return 0; }
target=r[2];
r[16]=code_base|0x0c0cb17eu;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb17eu) { target=s->pc; goto dispatch; }
goto P_0c0cb17e;
P_0c0cb17c: /* original e004, guest PC 0x0c0cb17c */
if(!s->budget--) { s->failed_pc=0x0c0cb17cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb17e;
P_0c0cb17e: /* original 6403, guest PC 0x0c0cb17e */
if(!s->budget--) { s->failed_pc=0x0c0cb17eu; return 0; }
r[4]=r[0];
goto P_0c0cb180;
P_0c0cb180: /* original e054, guest PC 0x0c0cb180 */
if(!s->budget--) { s->failed_pc=0x0c0cb180u; return 0; }
r[0]=0x00000054u;
goto P_0c0cb182;
P_0c0cb182: /* original 654e, guest PC 0x0c0cb182 */
if(!s->budget--) { s->failed_pc=0x0c0cb182u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb184;
P_0c0cb184: /* original 02fe, guest PC 0x0c0cb184 */
if(!s->budget--) { s->failed_pc=0x0c0cb184u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cb186;
P_0c0cb186: /* original 4500, guest PC 0x0c0cb186 */
if(!s->budget--) { s->failed_pc=0x0c0cb186u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0cb188;
P_0c0cb188: /* original 4508, guest PC 0x0c0cb188 */
if(!s->budget--) { s->failed_pc=0x0c0cb188u; return 0; }
r[5]<<=2;
goto P_0c0cb18a;
P_0c0cb18a: /* original 352c, guest PC 0x0c0cb18a */
if(!s->budget--) { s->failed_pc=0x0c0cb18au; return 0; }
r[5]+=r[2];
goto P_0c0cb18c;
P_0c0cb18c: /* original 634e, guest PC 0x0c0cb18c */
if(!s->budget--) { s->failed_pc=0x0c0cb18cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb18e;
P_0c0cb18e: /* original ff58, guest PC 0x0c0cb18e */
if(!s->budget--) { s->failed_pc=0x0c0cb18eu; return 0; }
vf3_matrix_load(s,ram,15,r[5]);
goto P_0c0cb190;
P_0c0cb190: /* original 4308, guest PC 0x0c0cb190 */
if(!s->budget--) { s->failed_pc=0x0c0cb190u; return 0; }
r[3]<<=2;
goto P_0c0cb192;
P_0c0cb192: /* original e004, guest PC 0x0c0cb192 */
if(!s->budget--) { s->failed_pc=0x0c0cb192u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb194;
P_0c0cb194: /* original fe56, guest PC 0x0c0cb194 */
if(!s->budget--) { s->failed_pc=0x0c0cb194u; return 0; }
vf3_matrix_load(s,ram,14,r[5]+r[0]);
goto P_0c0cb196;
P_0c0cb196: /* original 654e, guest PC 0x0c0cb196 */
if(!s->budget--) { s->failed_pc=0x0c0cb196u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[4];
goto P_0c0cb198;
P_0c0cb198: /* original 1f36, guest PC 0x0c0cb198 */
if(!s->budget--) { s->failed_pc=0x0c0cb198u; return 0; }
write(ram,r[15]+24,r[3],4);
goto P_0c0cb19a;
P_0c0cb19a: /* original e020, guest PC 0x0c0cb19a */
if(!s->budget--) { s->failed_pc=0x0c0cb19au; return 0; }
r[0]=0x00000020u;
goto P_0c0cb19c;
P_0c0cb19c: /* original 9240, guest PC 0x0c0cb19c */
if(!s->budget--) { s->failed_pc=0x0c0cb19cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb220u,2);
goto P_0c0cb19e;
P_0c0cb19e: /* original 32ec, guest PC 0x0c0cb19e */
if(!s->budget--) { s->failed_pc=0x0c0cb19eu; return 0; }
r[2]+=r[14];
goto P_0c0cb1a0;
P_0c0cb1a0: /* original 332c, guest PC 0x0c0cb1a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a0u; return 0; }
r[3]+=r[2];
goto P_0c0cb1a2;
P_0c0cb1a2: /* original f638, guest PC 0x0c0cb1a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a2u; return 0; }
vf3_matrix_load(s,ram,6,r[3]);
goto P_0c0cb1a4;
P_0c0cb1a4: /* original 6353, guest PC 0x0c0cb1a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a4u; return 0; }
r[3]=r[5];
goto P_0c0cb1a6;
P_0c0cb1a6: /* original 4500, guest PC 0x0c0cb1a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a6u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0cb1a8;
P_0c0cb1a8: /* original 353c, guest PC 0x0c0cb1a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1a8u; return 0; }
r[5]+=r[3];
goto P_0c0cb1aa;
P_0c0cb1aa: /* original 4508, guest PC 0x0c0cb1aa */
if(!s->budget--) { s->failed_pc=0x0c0cb1aau; return 0; }
r[5]<<=2;
goto P_0c0cb1ac;
P_0c0cb1ac: /* original 358c, guest PC 0x0c0cb1ac */
if(!s->budget--) { s->failed_pc=0x0c0cb1acu; return 0; }
r[5]+=r[8];
goto P_0c0cb1ae;
P_0c0cb1ae: /* original f358, guest PC 0x0c0cb1ae */
if(!s->budget--) { s->failed_pc=0x0c0cb1aeu; return 0; }
vf3_matrix_load(s,ram,3,r[5]);
goto P_0c0cb1b0;
P_0c0cb1b0: /* original ff37, guest PC 0x0c0cb1b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb1b2;
P_0c0cb1b2: /* original e004, guest PC 0x0c0cb1b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b2u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb1b4;
P_0c0cb1b4: /* original f356, guest PC 0x0c0cb1b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b4u; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cb1b6;
P_0c0cb1b6: /* original e008, guest PC 0x0c0cb1b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b6u; return 0; }
r[0]=0x00000008u;
goto P_0c0cb1b8;
P_0c0cb1b8: /* original ff3a, guest PC 0x0c0cb1b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb1ba;
P_0c0cb1ba: /* original f356, guest PC 0x0c0cb1ba */
if(!s->budget--) { s->failed_pc=0x0c0cb1bau; return 0; }
vf3_matrix_load(s,ram,3,r[5]+r[0]);
goto P_0c0cb1bc;
P_0c0cb1bc: /* original e01c, guest PC 0x0c0cb1bc */
if(!s->budget--) { s->failed_pc=0x0c0cb1bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cb1be;
P_0c0cb1be: /* original ff37, guest PC 0x0c0cb1be */
if(!s->budget--) { s->failed_pc=0x0c0cb1beu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb1c0;
P_0c0cb1c0: /* original f5fc, guest PC 0x0c0cb1c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c0u; return 0; }
vf3_matrix_move(s,5,15);
goto P_0c0cb1c2;
P_0c0cb1c2: /* original f4fc, guest PC 0x0c0cb1c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c2u; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c0cb1c4;
P_0c0cb1c4: /* original f542, guest PC 0x0c0cb1c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cb1c6;
P_0c0cb1c6: /* original f0ec, guest PC 0x0c0cb1c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c6u; return 0; }
vf3_matrix_move(s,0,14);
goto P_0c0cb1c8;
P_0c0cb1c8: /* original fdec, guest PC 0x0c0cb1c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1c8u; return 0; }
vf3_matrix_move(s,13,14);
goto P_0c0cb1ca;
P_0c0cb1ca: /* original 50f6, guest PC 0x0c0cb1ca */
if(!s->budget--) { s->failed_pc=0x0c0cb1cau; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0cb1cc;
P_0c0cb1cc: /* original f35c, guest PC 0x0c0cb1cc */
if(!s->budget--) { s->failed_pc=0x0c0cb1ccu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cb1ce;
P_0c0cb1ce: /* original f3de, guest PC 0x0c0cb1ce */
if(!s->budget--) { s->failed_pc=0x0c0cb1ceu; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[13],fr[3],r[18]);
goto P_0c0cb1d0;
P_0c0cb1d0: /* original 53fc, guest PC 0x0c0cb1d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d0u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c0cb1d2;
P_0c0cb1d2: /* original f53c, guest PC 0x0c0cb1d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d2u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cb1d4;
P_0c0cb1d4: /* original f357, guest PC 0x0c0cb1d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d4u; return 0; }
vf3_matrix_store(s,ram,5,r[3]+r[0]);
goto P_0c0cb1d6;
P_0c0cb1d6: /* original e014, guest PC 0x0c0cb1d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d6u; return 0; }
r[0]=0x00000014u;
goto P_0c0cb1d8;
P_0c0cb1d8: /* original f3f8, guest PC 0x0c0cb1d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1d8u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0cb1da;
P_0c0cb1da: /* original f361, guest PC 0x0c0cb1da */
if(!s->budget--) { s->failed_pc=0x0c0cb1dau; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'-');
goto P_0c0cb1dc;
P_0c0cb1dc: /* original ff3a, guest PC 0x0c0cb1dc */
if(!s->budget--) { s->failed_pc=0x0c0cb1dcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb1de;
P_0c0cb1de: /* original f2f6, guest PC 0x0c0cb1de */
if(!s->budget--) { s->failed_pc=0x0c0cb1deu; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb1e0;
P_0c0cb1e0: /* original f325, guest PC 0x0c0cb1e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0cb1e2;
P_0c0cb1e2: /* original 8b01, guest PC 0x0c0cb1e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb1e8; }
goto P_0c0cb1e4;
P_0c0cb1e4: /* original a0b6, guest PC 0x0c0cb1e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e4u; return 0; }
goto P_0c0cb354;
P_0c0cb1e6: /* original 0009, guest PC 0x0c0cb1e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e6u; return 0; }
goto P_0c0cb1e8;
P_0c0cb1e8: /* original e02c, guest PC 0x0c0cb1e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1e8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0cb1ea;
P_0c0cb1ea: /* original f3f6, guest PC 0x0c0cb1ea */
if(!s->budget--) { s->failed_pc=0x0c0cb1eau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb1ec;
P_0c0cb1ec: /* original f3f5, guest PC 0x0c0cb1ec */
if(!s->budget--) { s->failed_pc=0x0c0cb1ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[15]))!=0);
goto P_0c0cb1ee;
P_0c0cb1ee: /* original 8b0d, guest PC 0x0c0cb1ee */
if(!s->budget--) { s->failed_pc=0x0c0cb1eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb1f0;
P_0c0cb1f0: /* original e028, guest PC 0x0c0cb1f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f0u; return 0; }
r[0]=0x00000028u;
goto P_0c0cb1f2;
P_0c0cb1f2: /* original f3f6, guest PC 0x0c0cb1f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f2u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb1f4;
P_0c0cb1f4: /* original ff35, guest PC 0x0c0cb1f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0cb1f6;
P_0c0cb1f6: /* original 8b09, guest PC 0x0c0cb1f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb1f8;
P_0c0cb1f8: /* original e02c, guest PC 0x0c0cb1f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb1f8u; return 0; }
r[0]=0x0000002cu;
goto P_0c0cb1fa;
P_0c0cb1fa: /* original f3f6, guest PC 0x0c0cb1fa */
if(!s->budget--) { s->failed_pc=0x0c0cb1fau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb1fc;
P_0c0cb1fc: /* original f3e5, guest PC 0x0c0cb1fc */
if(!s->budget--) { s->failed_pc=0x0c0cb1fcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c0cb1fe;
P_0c0cb1fe: /* original 8b05, guest PC 0x0c0cb1fe */
if(!s->budget--) { s->failed_pc=0x0c0cb1feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb200;
P_0c0cb200: /* original e028, guest PC 0x0c0cb200 */
if(!s->budget--) { s->failed_pc=0x0c0cb200u; return 0; }
r[0]=0x00000028u;
goto P_0c0cb202;
P_0c0cb202: /* original f3f6, guest PC 0x0c0cb202 */
if(!s->budget--) { s->failed_pc=0x0c0cb202u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb204;
P_0c0cb204: /* original fe35, guest PC 0x0c0cb204 */
if(!s->budget--) { s->failed_pc=0x0c0cb204u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[14])>as_float(fr[3]))!=0);
goto P_0c0cb206;
P_0c0cb206: /* original 8b01, guest PC 0x0c0cb206 */
if(!s->budget--) { s->failed_pc=0x0c0cb206u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb20c; }
goto P_0c0cb208;
P_0c0cb208: /* original a0a4, guest PC 0x0c0cb208 */
if(!s->budget--) { s->failed_pc=0x0c0cb208u; return 0; }
goto P_0c0cb354;
P_0c0cb20a: /* original 0009, guest PC 0x0c0cb20a */
if(!s->budget--) { s->failed_pc=0x0c0cb20au; return 0; }
goto P_0c0cb20c;
P_0c0cb20c: /* original c70c, guest PC 0x0c0cb20c */
if(!s->budget--) { s->failed_pc=0x0c0cb20cu; return 0; }
r[0]=code_base|0x000cb240u;
goto P_0c0cb20e;
P_0c0cb20e: /* original f308, guest PC 0x0c0cb20e */
if(!s->budget--) { s->failed_pc=0x0c0cb20eu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb210;
P_0c0cb210: /* original f355, guest PC 0x0c0cb210 */
if(!s->budget--) { s->failed_pc=0x0c0cb210u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0cb212;
P_0c0cb212: /* original 8f17, guest PC 0x0c0cb212 */
if(!s->budget--) { s->failed_pc=0x0c0cb212u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,3,4);
if(!cond) { goto P_0c0cb244; }
goto P_0c0cb216;
P_0c0cb214: /* original f34c, guest PC 0x0c0cb214 */
if(!s->budget--) { s->failed_pc=0x0c0cb214u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cb216;
P_0c0cb216: /* original a016, guest PC 0x0c0cb216 */
if(!s->budget--) { s->failed_pc=0x0c0cb216u; return 0; }
fr[5]=0;
goto P_0c0cb246;
P_0c0cb218: /* original f58d, guest PC 0x0c0cb218 */
if(!s->budget--) { s->failed_pc=0x0c0cb218u; return 0; }
fr[5]=0;
if(!vf3_matrix_family(0x0c0cb21au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb21au; return 0; } return 1;
P_0c0cb244: /* original f57d, guest PC 0x0c0cb244 */
if(!s->budget--) { s->failed_pc=0x0c0cb244u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cb246;
P_0c0cb246: /* original f45c, guest PC 0x0c0cb246 */
if(!s->budget--) { s->failed_pc=0x0c0cb246u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cb248;
P_0c0cb248: /* original f432, guest PC 0x0c0cb248 */
if(!s->budget--) { s->failed_pc=0x0c0cb248u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'*');
goto P_0c0cb24a;
P_0c0cb24a: /* original e024, guest PC 0x0c0cb24a */
if(!s->budget--) { s->failed_pc=0x0c0cb24au; return 0; }
r[0]=0x00000024u;
goto P_0c0cb24c;
P_0c0cb24c: /* original f3dc, guest PC 0x0c0cb24c */
if(!s->budget--) { s->failed_pc=0x0c0cb24cu; return 0; }
vf3_matrix_move(s,3,13);
goto P_0c0cb24e;
P_0c0cb24e: /* original fd5c, guest PC 0x0c0cb24e */
if(!s->budget--) { s->failed_pc=0x0c0cb24eu; return 0; }
vf3_matrix_move(s,13,5);
goto P_0c0cb250;
P_0c0cb250: /* original fd32, guest PC 0x0c0cb250 */
if(!s->budget--) { s->failed_pc=0x0c0cb250u; return 0; }
fr[13]=vf3_fpu_binary(fr[13],fr[3],r[18],'*');
goto P_0c0cb252;
P_0c0cb252: /* original f44d, guest PC 0x0c0cb252 */
if(!s->budget--) { s->failed_pc=0x0c0cb252u; return 0; }
fr[4]^=0x80000000u;
goto P_0c0cb254;
P_0c0cb254: /* original ff47, guest PC 0x0c0cb254 */
if(!s->budget--) { s->failed_pc=0x0c0cb254u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0cb256;
P_0c0cb256: /* original e020, guest PC 0x0c0cb256 */
if(!s->budget--) { s->failed_pc=0x0c0cb256u; return 0; }
r[0]=0x00000020u;
goto P_0c0cb258;
P_0c0cb258: /* original f3f6, guest PC 0x0c0cb258 */
if(!s->budget--) { s->failed_pc=0x0c0cb258u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb25a;
P_0c0cb25a: /* original e01c, guest PC 0x0c0cb25a */
if(!s->budget--) { s->failed_pc=0x0c0cb25au; return 0; }
r[0]=0x0000001cu;
goto P_0c0cb25c;
P_0c0cb25c: /* original f06c, guest PC 0x0c0cb25c */
if(!s->budget--) { s->failed_pc=0x0c0cb25cu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0cb25e;
P_0c0cb25e: /* original f24c, guest PC 0x0c0cb25e */
if(!s->budget--) { s->failed_pc=0x0c0cb25eu; return 0; }
vf3_matrix_move(s,2,4);
goto P_0c0cb260;
P_0c0cb260: /* original f32e, guest PC 0x0c0cb260 */
if(!s->budget--) { s->failed_pc=0x0c0cb260u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0cb262;
P_0c0cb262: /* original ff3a, guest PC 0x0c0cb262 */
if(!s->budget--) { s->failed_pc=0x0c0cb262u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb264;
P_0c0cb264: /* original f2f6, guest PC 0x0c0cb264 */
if(!s->budget--) { s->failed_pc=0x0c0cb264u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb266;
P_0c0cb266: /* original e004, guest PC 0x0c0cb266 */
if(!s->budget--) { s->failed_pc=0x0c0cb266u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb268;
P_0c0cb268: /* original f2de, guest PC 0x0c0cb268 */
if(!s->budget--) { s->failed_pc=0x0c0cb268u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[13],fr[2],r[18]);
goto P_0c0cb26a;
P_0c0cb26a: /* original ff27, guest PC 0x0c0cb26a */
if(!s->budget--) { s->failed_pc=0x0c0cb26au; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb26c;
P_0c0cb26c: /* original d333, guest PC 0x0c0cb26c */
if(!s->budget--) { s->failed_pc=0x0c0cb26cu; return 0; }
r[3]=read(ram,0x0c0cb33cu,4);
goto P_0c0cb26e;
P_0c0cb26e: /* original 6030, guest PC 0x0c0cb26e */
if(!s->budget--) { s->failed_pc=0x0c0cb26eu; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0cb270;
P_0c0cb270: /* original 600c, guest PC 0x0c0cb270 */
if(!s->budget--) { s->failed_pc=0x0c0cb270u; return 0; }
r[0]=r[0]&255u;
goto P_0c0cb272;
P_0c0cb272: /* original c90f, guest PC 0x0c0cb272 */
if(!s->budget--) { s->failed_pc=0x0c0cb272u; return 0; }
r[0]&=15u;
goto P_0c0cb274;
P_0c0cb274: /* original 8809, guest PC 0x0c0cb274 */
if(!s->budget--) { s->failed_pc=0x0c0cb274u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0cb276;
P_0c0cb276: /* original 8b11, guest PC 0x0c0cb276 */
if(!s->budget--) { s->failed_pc=0x0c0cb276u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb29c; }
goto P_0c0cb278;
P_0c0cb278: /* original c731, guest PC 0x0c0cb278 */
if(!s->budget--) { s->failed_pc=0x0c0cb278u; return 0; }
r[0]=code_base|0x000cb340u;
goto P_0c0cb27a;
P_0c0cb27a: /* original f308, guest PC 0x0c0cb27a */
if(!s->budget--) { s->failed_pc=0x0c0cb27au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb27c;
P_0c0cb27c: /* original 905d, guest PC 0x0c0cb27c */
if(!s->budget--) { s->failed_pc=0x0c0cb27cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb33au,2);
goto P_0c0cb27e;
P_0c0cb27e: /* original f2e6, guest PC 0x0c0cb27e */
if(!s->budget--) { s->failed_pc=0x0c0cb27eu; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cb280;
P_0c0cb280: /* original f235, guest PC 0x0c0cb280 */
if(!s->budget--) { s->failed_pc=0x0c0cb280u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0cb282;
P_0c0cb282: /* original 8b0b, guest PC 0x0c0cb282 */
if(!s->budget--) { s->failed_pc=0x0c0cb282u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb29c; }
goto P_0c0cb284;
P_0c0cb284: /* original c72f, guest PC 0x0c0cb284 */
if(!s->budget--) { s->failed_pc=0x0c0cb284u; return 0; }
r[0]=code_base|0x000cb344u;
goto P_0c0cb286;
P_0c0cb286: /* original d330, guest PC 0x0c0cb286 */
if(!s->budget--) { s->failed_pc=0x0c0cb286u; return 0; }
r[3]=read(ram,0x0c0cb348u,4);
goto P_0c0cb288;
P_0c0cb288: /* original f308, guest PC 0x0c0cb288 */
if(!s->budget--) { s->failed_pc=0x0c0cb288u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb28a;
P_0c0cb28a: /* original e004, guest PC 0x0c0cb28a */
if(!s->budget--) { s->failed_pc=0x0c0cb28au; return 0; }
r[0]=0x00000004u;
goto P_0c0cb28c;
P_0c0cb28c: /* original f5f6, guest PC 0x0c0cb28c */
if(!s->budget--) { s->failed_pc=0x0c0cb28cu; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0cb28e;
P_0c0cb28e: /* original 64f3, guest PC 0x0c0cb28e */
if(!s->budget--) { s->failed_pc=0x0c0cb28eu; return 0; }
r[4]=r[15];
goto P_0c0cb290;
P_0c0cb290: /* original 7468, guest PC 0x0c0cb290 */
if(!s->budget--) { s->failed_pc=0x0c0cb290u; return 0; }
r[4]+=0x00000068u;
goto P_0c0cb292;
P_0c0cb292: /* original f530, guest PC 0x0c0cb292 */
if(!s->budget--) { s->failed_pc=0x0c0cb292u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0cb294;
P_0c0cb294: /* original 430b, guest PC 0x0c0cb294 */
if(!s->budget--) { s->failed_pc=0x0c0cb294u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cb298u;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb298u) { target=s->pc; goto dispatch; }
goto P_0c0cb298;
P_0c0cb296: /* original f4f8, guest PC 0x0c0cb296 */
if(!s->budget--) { s->failed_pc=0x0c0cb296u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cb298;
P_0c0cb298: /* original a007, guest PC 0x0c0cb298 */
if(!s->budget--) { s->failed_pc=0x0c0cb298u; return 0; }
goto P_0c0cb2aa;
P_0c0cb29a: /* original 0009, guest PC 0x0c0cb29a */
if(!s->budget--) { s->failed_pc=0x0c0cb29au; return 0; }
goto P_0c0cb29c;
P_0c0cb29c: /* original e004, guest PC 0x0c0cb29c */
if(!s->budget--) { s->failed_pc=0x0c0cb29cu; return 0; }
r[0]=0x00000004u;
goto P_0c0cb29e;
P_0c0cb29e: /* original d32a, guest PC 0x0c0cb29e */
if(!s->budget--) { s->failed_pc=0x0c0cb29eu; return 0; }
r[3]=read(ram,0x0c0cb348u,4);
goto P_0c0cb2a0;
P_0c0cb2a0: /* original f5f6, guest PC 0x0c0cb2a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a0u; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0cb2a2;
P_0c0cb2a2: /* original 64f3, guest PC 0x0c0cb2a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a2u; return 0; }
r[4]=r[15];
goto P_0c0cb2a4;
P_0c0cb2a4: /* original 7468, guest PC 0x0c0cb2a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a4u; return 0; }
r[4]+=0x00000068u;
goto P_0c0cb2a6;
P_0c0cb2a6: /* original 430b, guest PC 0x0c0cb2a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0cb2aau;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb2aau) { target=s->pc; goto dispatch; }
goto P_0c0cb2aa;
P_0c0cb2a8: /* original f4f8, guest PC 0x0c0cb2a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2a8u; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cb2aa;
P_0c0cb2aa: /* original 6303, guest PC 0x0c0cb2aa */
if(!s->budget--) { s->failed_pc=0x0c0cb2aau; return 0; }
r[3]=r[0];
goto P_0c0cb2ac;
P_0c0cb2ac: /* original 1f02, guest PC 0x0c0cb2ac */
if(!s->budget--) { s->failed_pc=0x0c0cb2acu; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0cb2ae;
P_0c0cb2ae: /* original e040, guest PC 0x0c0cb2ae */
if(!s->budget--) { s->failed_pc=0x0c0cb2aeu; return 0; }
r[0]=0x00000040u;
goto P_0c0cb2b0;
P_0c0cb2b0: /* original 02fe, guest PC 0x0c0cb2b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b0u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cb2b2;
P_0c0cb2b2: /* original 2238, guest PC 0x0c0cb2b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0cb2b4;
P_0c0cb2b4: /* original 8b04, guest PC 0x0c0cb2b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb2c0; }
goto P_0c0cb2b6;
P_0c0cb2b6: /* original 50f6, guest PC 0x0c0cb2b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b6u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c0cb2b8;
P_0c0cb2b8: /* original 51fc, guest PC 0x0c0cb2b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2b8u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c0cb2ba;
P_0c0cb2ba: /* original f38d, guest PC 0x0c0cb2ba */
if(!s->budget--) { s->failed_pc=0x0c0cb2bau; return 0; }
fr[3]=0;
goto P_0c0cb2bc;
P_0c0cb2bc: /* original a04a, guest PC 0x0c0cb2bc */
if(!s->budget--) { s->failed_pc=0x0c0cb2bcu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c0cb354;
P_0c0cb2be: /* original f137, guest PC 0x0c0cb2be */
if(!s->budget--) { s->failed_pc=0x0c0cb2beu; return 0; }
vf3_matrix_store(s,ram,3,r[1]+r[0]);
goto P_0c0cb2c0;
P_0c0cb2c0: /* original e004, guest PC 0x0c0cb2c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c0u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb2c2;
P_0c0cb2c2: /* original f3fc, guest PC 0x0c0cb2c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c2u; return 0; }
vf3_matrix_move(s,3,15);
goto P_0c0cb2c4;
P_0c0cb2c4: /* original f35d, guest PC 0x0c0cb2c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c4u; return 0; }
fr[3]&=0x7fffffffu;
goto P_0c0cb2c6;
P_0c0cb2c6: /* original ff3a, guest PC 0x0c0cb2c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c6u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb2c8;
P_0c0cb2c8: /* original f2ec, guest PC 0x0c0cb2c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2c8u; return 0; }
vf3_matrix_move(s,2,14);
goto P_0c0cb2ca;
P_0c0cb2ca: /* original f25d, guest PC 0x0c0cb2ca */
if(!s->budget--) { s->failed_pc=0x0c0cb2cau; return 0; }
fr[2]&=0x7fffffffu;
goto P_0c0cb2cc;
P_0c0cb2cc: /* original ff27, guest PC 0x0c0cb2cc */
if(!s->budget--) { s->failed_pc=0x0c0cb2ccu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb2ce;
P_0c0cb2ce: /* original e064, guest PC 0x0c0cb2ce */
if(!s->budget--) { s->failed_pc=0x0c0cb2ceu; return 0; }
r[0]=0x00000064u;
goto P_0c0cb2d0;
P_0c0cb2d0: /* original f1f6, guest PC 0x0c0cb2d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d0u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb2d2;
P_0c0cb2d2: /* original e060, guest PC 0x0c0cb2d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d2u; return 0; }
r[0]=0x00000060u;
goto P_0c0cb2d4;
P_0c0cb2d4: /* original f43c, guest PC 0x0c0cb2d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d4u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0cb2d6;
P_0c0cb2d6: /* original f411, guest PC 0x0c0cb2d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d6u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[1],r[18],'-');
goto P_0c0cb2d8;
P_0c0cb2d8: /* original f1f6, guest PC 0x0c0cb2d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2d8u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb2da;
P_0c0cb2da: /* original f52c, guest PC 0x0c0cb2da */
if(!s->budget--) { s->failed_pc=0x0c0cb2dau; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0cb2dc;
P_0c0cb2dc: /* original f511, guest PC 0x0c0cb2dc */
if(!s->budget--) { s->failed_pc=0x0c0cb2dcu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[1],r[18],'-');
goto P_0c0cb2de;
P_0c0cb2de: /* original f18d, guest PC 0x0c0cb2de */
if(!s->budget--) { s->failed_pc=0x0c0cb2deu; return 0; }
fr[1]=0;
goto P_0c0cb2e0;
P_0c0cb2e0: /* original f415, guest PC 0x0c0cb2e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[1]))!=0);
goto P_0c0cb2e2;
P_0c0cb2e2: /* original 8b02, guest PC 0x0c0cb2e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb2ea; }
goto P_0c0cb2e4;
P_0c0cb2e4: /* original e064, guest PC 0x0c0cb2e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e4u; return 0; }
r[0]=0x00000064u;
goto P_0c0cb2e6;
P_0c0cb2e6: /* original fcfc, guest PC 0x0c0cb2e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e6u; return 0; }
vf3_matrix_move(s,12,15);
goto P_0c0cb2e8;
P_0c0cb2e8: /* original ff37, guest PC 0x0c0cb2e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2e8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb2ea;
P_0c0cb2ea: /* original f38d, guest PC 0x0c0cb2ea */
if(!s->budget--) { s->failed_pc=0x0c0cb2eau; return 0; }
fr[3]=0;
goto P_0c0cb2ec;
P_0c0cb2ec: /* original f535, guest PC 0x0c0cb2ec */
if(!s->budget--) { s->failed_pc=0x0c0cb2ecu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cb2ee;
P_0c0cb2ee: /* original 8b05, guest PC 0x0c0cb2ee */
if(!s->budget--) { s->failed_pc=0x0c0cb2eeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb2fc; }
goto P_0c0cb2f0;
P_0c0cb2f0: /* original e010, guest PC 0x0c0cb2f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f0u; return 0; }
r[0]=0x00000010u;
goto P_0c0cb2f2;
P_0c0cb2f2: /* original ffe7, guest PC 0x0c0cb2f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f2u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0cb2f4;
P_0c0cb2f4: /* original e004, guest PC 0x0c0cb2f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb2f6;
P_0c0cb2f6: /* original f3f6, guest PC 0x0c0cb2f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f6u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb2f8;
P_0c0cb2f8: /* original e060, guest PC 0x0c0cb2f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb2f8u; return 0; }
r[0]=0x00000060u;
goto P_0c0cb2fa;
P_0c0cb2fa: /* original ff37, guest PC 0x0c0cb2fa */
if(!s->budget--) { s->failed_pc=0x0c0cb2fau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb2fc;
P_0c0cb2fc: /* original f38d, guest PC 0x0c0cb2fc */
if(!s->budget--) { s->failed_pc=0x0c0cb2fcu; return 0; }
fr[3]=0;
goto P_0c0cb2fe;
P_0c0cb2fe: /* original f435, guest PC 0x0c0cb2fe */
if(!s->budget--) { s->failed_pc=0x0c0cb2feu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[3]))!=0);
goto P_0c0cb300;
P_0c0cb300: /* original 8902, guest PC 0x0c0cb300 */
if(!s->budget--) { s->failed_pc=0x0c0cb300u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb308; }
goto P_0c0cb302;
P_0c0cb302: /* original f38d, guest PC 0x0c0cb302 */
if(!s->budget--) { s->failed_pc=0x0c0cb302u; return 0; }
fr[3]=0;
goto P_0c0cb304;
P_0c0cb304: /* original f535, guest PC 0x0c0cb304 */
if(!s->budget--) { s->failed_pc=0x0c0cb304u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[3]))!=0);
goto P_0c0cb306;
P_0c0cb306: /* original 8b25, guest PC 0x0c0cb306 */
if(!s->budget--) { s->failed_pc=0x0c0cb306u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb354; }
goto P_0c0cb308;
P_0c0cb308: /* original e024, guest PC 0x0c0cb308 */
if(!s->budget--) { s->failed_pc=0x0c0cb308u; return 0; }
r[0]=0x00000024u;
goto P_0c0cb30a;
P_0c0cb30a: /* original f3f6, guest PC 0x0c0cb30a */
if(!s->budget--) { s->failed_pc=0x0c0cb30au; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb30c;
P_0c0cb30c: /* original e050, guest PC 0x0c0cb30c */
if(!s->budget--) { s->failed_pc=0x0c0cb30cu; return 0; }
r[0]=0x00000050u;
goto P_0c0cb30e;
P_0c0cb30e: /* original ff37, guest PC 0x0c0cb30e */
if(!s->budget--) { s->failed_pc=0x0c0cb30eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0cb310;
P_0c0cb310: /* original e020, guest PC 0x0c0cb310 */
if(!s->budget--) { s->failed_pc=0x0c0cb310u; return 0; }
r[0]=0x00000020u;
goto P_0c0cb312;
P_0c0cb312: /* original f3f6, guest PC 0x0c0cb312 */
if(!s->budget--) { s->failed_pc=0x0c0cb312u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb314;
P_0c0cb314: /* original e048, guest PC 0x0c0cb314 */
if(!s->budget--) { s->failed_pc=0x0c0cb314u; return 0; }
r[0]=0x00000048u;
goto P_0c0cb316;
P_0c0cb316: /* original ff30, guest PC 0x0c0cb316 */
if(!s->budget--) { s->failed_pc=0x0c0cb316u; return 0; }
fr[15]=vf3_fpu_binary(fr[15],fr[3],r[18],'+');
goto P_0c0cb318;
P_0c0cb318: /* original fff7, guest PC 0x0c0cb318 */
if(!s->budget--) { s->failed_pc=0x0c0cb318u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c0cb31a;
P_0c0cb31a: /* original e04c, guest PC 0x0c0cb31a */
if(!s->budget--) { s->failed_pc=0x0c0cb31au; return 0; }
r[0]=0x0000004cu;
goto P_0c0cb31c;
P_0c0cb31c: /* original ffd7, guest PC 0x0c0cb31c */
if(!s->budget--) { s->failed_pc=0x0c0cb31cu; return 0; }
vf3_matrix_store(s,ram,13,r[15]+r[0]);
goto P_0c0cb31e;
P_0c0cb31e: /* original e01c, guest PC 0x0c0cb31e */
if(!s->budget--) { s->failed_pc=0x0c0cb31eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cb320;
P_0c0cb320: /* original f2f6, guest PC 0x0c0cb320 */
if(!s->budget--) { s->failed_pc=0x0c0cb320u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb322;
P_0c0cb322: /* original e044, guest PC 0x0c0cb322 */
if(!s->budget--) { s->failed_pc=0x0c0cb322u; return 0; }
r[0]=0x00000044u;
goto P_0c0cb324;
P_0c0cb324: /* original fe20, guest PC 0x0c0cb324 */
if(!s->budget--) { s->failed_pc=0x0c0cb324u; return 0; }
fr[14]=vf3_fpu_binary(fr[14],fr[2],r[18],'+');
goto P_0c0cb326;
P_0c0cb326: /* original ffe7, guest PC 0x0c0cb326 */
if(!s->budget--) { s->failed_pc=0x0c0cb326u; return 0; }
vf3_matrix_store(s,ram,14,r[15]+r[0]);
goto P_0c0cb328;
P_0c0cb328: /* original e058, guest PC 0x0c0cb328 */
if(!s->budget--) { s->failed_pc=0x0c0cb328u; return 0; }
r[0]=0x00000058u;
goto P_0c0cb32a;
P_0c0cb32a: /* original 00fe, guest PC 0x0c0cb32a */
if(!s->budget--) { s->failed_pc=0x0c0cb32au; return 0; }
r[0]=read(ram,r[15]+r[0],4);
goto P_0c0cb32c;
P_0c0cb32c: /* original 8806, guest PC 0x0c0cb32c */
if(!s->budget--) { s->failed_pc=0x0c0cb32cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0cb32e;
P_0c0cb32e: /* original 890d, guest PC 0x0c0cb32e */
if(!s->budget--) { s->failed_pc=0x0c0cb32eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb34c; }
goto P_0c0cb330;
P_0c0cb330: /* original 50f2, guest PC 0x0c0cb330 */
if(!s->budget--) { s->failed_pc=0x0c0cb330u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c0cb332;
P_0c0cb332: /* original c848, guest PC 0x0c0cb332 */
if(!s->budget--) { s->failed_pc=0x0c0cb332u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&72u)==0)!=0);
goto P_0c0cb334;
P_0c0cb334: /* original 8b0a, guest PC 0x0c0cb334 */
if(!s->budget--) { s->failed_pc=0x0c0cb334u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb34c; }
goto P_0c0cb336;
P_0c0cb336: /* original a00a, guest PC 0x0c0cb336 */
if(!s->budget--) { s->failed_pc=0x0c0cb336u; return 0; }
r[10]=0x00000001u;
goto P_0c0cb34e;
P_0c0cb338: /* original ea01, guest PC 0x0c0cb338 */
if(!s->budget--) { s->failed_pc=0x0c0cb338u; return 0; }
r[10]=0x00000001u;
if(!vf3_matrix_family(0x0c0cb33au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb33au; return 0; } return 1;
P_0c0cb34c: /* original ea00, guest PC 0x0c0cb34c */
if(!s->budget--) { s->failed_pc=0x0c0cb34cu; return 0; }
r[10]=0x00000000u;
goto P_0c0cb34e;
P_0c0cb34e: /* original e05c, guest PC 0x0c0cb34e */
if(!s->budget--) { s->failed_pc=0x0c0cb34eu; return 0; }
r[0]=0x0000005cu;
goto P_0c0cb350;
P_0c0cb350: /* original 02fe, guest PC 0x0c0cb350 */
if(!s->budget--) { s->failed_pc=0x0c0cb350u; return 0; }
r[2]=read(ram,r[15]+r[0],4);
goto P_0c0cb352;
P_0c0cb352: /* original 2d2b, guest PC 0x0c0cb352 */
if(!s->budget--) { s->failed_pc=0x0c0cb352u; return 0; }
r[13]|=r[2];
goto P_0c0cb354;
P_0c0cb354: /* original 4b10, guest PC 0x0c0cb354 */
if(!s->budget--) { s->failed_pc=0x0c0cb354u; return 0; }
--r[11];
r[17]=(r[17]&~1u)|((r[11]==0)!=0);
goto P_0c0cb356;
P_0c0cb356: /* original 8901, guest PC 0x0c0cb356 */
if(!s->budget--) { s->failed_pc=0x0c0cb356u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb35c; }
goto P_0c0cb358;
P_0c0cb358: /* original af08, guest PC 0x0c0cb358 */
if(!s->budget--) { s->failed_pc=0x0c0cb358u; return 0; }
goto P_0c0cb16c;
P_0c0cb35a: /* original 0009, guest PC 0x0c0cb35a */
if(!s->budget--) { s->failed_pc=0x0c0cb35au; return 0; }
goto P_0c0cb35c;
P_0c0cb35c: /* original 907f, guest PC 0x0c0cb35c */
if(!s->budget--) { s->failed_pc=0x0c0cb35cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb45eu,2);
goto P_0c0cb35e;
P_0c0cb35e: /* original fec7, guest PC 0x0c0cb35e */
if(!s->budget--) { s->failed_pc=0x0c0cb35eu; return 0; }
vf3_matrix_store(s,ram,12,r[14]+r[0]);
goto P_0c0cb360;
P_0c0cb360: /* original e010, guest PC 0x0c0cb360 */
if(!s->budget--) { s->failed_pc=0x0c0cb360u; return 0; }
r[0]=0x00000010u;
goto P_0c0cb362;
P_0c0cb362: /* original f3f6, guest PC 0x0c0cb362 */
if(!s->budget--) { s->failed_pc=0x0c0cb362u; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb364;
P_0c0cb364: /* original 907c, guest PC 0x0c0cb364 */
if(!s->budget--) { s->failed_pc=0x0c0cb364u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb460u,2);
goto P_0c0cb366;
P_0c0cb366: /* original f34d, guest PC 0x0c0cb366 */
if(!s->budget--) { s->failed_pc=0x0c0cb366u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0cb368;
P_0c0cb368: /* original fe37, guest PC 0x0c0cb368 */
if(!s->budget--) { s->failed_pc=0x0c0cb368u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb36a;
P_0c0cb36a: /* original c741, guest PC 0x0c0cb36a */
if(!s->budget--) { s->failed_pc=0x0c0cb36au; return 0; }
r[0]=code_base|0x000cb470u;
goto P_0c0cb36c;
P_0c0cb36c: /* original f308, guest PC 0x0c0cb36c */
if(!s->budget--) { s->failed_pc=0x0c0cb36cu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb36e;
P_0c0cb36e: /* original e014, guest PC 0x0c0cb36e */
if(!s->budget--) { s->failed_pc=0x0c0cb36eu; return 0; }
r[0]=0x00000014u;
goto P_0c0cb370;
P_0c0cb370: /* original f2f6, guest PC 0x0c0cb370 */
if(!s->budget--) { s->failed_pc=0x0c0cb370u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb372;
P_0c0cb372: /* original f325, guest PC 0x0c0cb372 */
if(!s->budget--) { s->failed_pc=0x0c0cb372u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0cb374;
P_0c0cb374: /* original 8901, guest PC 0x0c0cb374 */
if(!s->budget--) { s->failed_pc=0x0c0cb374u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb37a; }
goto P_0c0cb376;
P_0c0cb376: /* original a091, guest PC 0x0c0cb376 */
if(!s->budget--) { s->failed_pc=0x0c0cb376u; return 0; }
goto P_0c0cb49c;
P_0c0cb378: /* original 0009, guest PC 0x0c0cb378 */
if(!s->budget--) { s->failed_pc=0x0c0cb378u; return 0; }
goto P_0c0cb37a;
P_0c0cb37a: /* original d33e, guest PC 0x0c0cb37a */
if(!s->budget--) { s->failed_pc=0x0c0cb37au; return 0; }
r[3]=read(ram,0x0c0cb474u,4);
goto P_0c0cb37c;
P_0c0cb37c: /* original 9471, guest PC 0x0c0cb37c */
if(!s->budget--) { s->failed_pc=0x0c0cb37cu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb462u,2);
goto P_0c0cb37e;
P_0c0cb37e: /* original 23c8, guest PC 0x0c0cb37e */
if(!s->budget--) { s->failed_pc=0x0c0cb37eu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0cb380;
P_0c0cb380: /* original 891b, guest PC 0x0c0cb380 */
if(!s->budget--) { s->failed_pc=0x0c0cb380u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb3ba; }
goto P_0c0cb382;
P_0c0cb382: /* original 906f, guest PC 0x0c0cb382 */
if(!s->budget--) { s->failed_pc=0x0c0cb382u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb464u,2);
goto P_0c0cb384;
P_0c0cb384: /* original 02ee, guest PC 0x0c0cb384 */
if(!s->budget--) { s->failed_pc=0x0c0cb384u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0cb386;
P_0c0cb386: /* original 6023, guest PC 0x0c0cb386 */
if(!s->budget--) { s->failed_pc=0x0c0cb386u; return 0; }
r[0]=r[2];
goto P_0c0cb388;
P_0c0cb388: /* original c820, guest PC 0x0c0cb388 */
if(!s->budget--) { s->failed_pc=0x0c0cb388u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c0cb38a;
P_0c0cb38a: /* original 1f22, guest PC 0x0c0cb38a */
if(!s->budget--) { s->failed_pc=0x0c0cb38au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0cb38c;
P_0c0cb38c: /* original 8915, guest PC 0x0c0cb38c */
if(!s->budget--) { s->failed_pc=0x0c0cb38cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb3ba; }
goto P_0c0cb38e;
P_0c0cb38e: /* original 906a, guest PC 0x0c0cb38e */
if(!s->budget--) { s->failed_pc=0x0c0cb38eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb466u,2);
goto P_0c0cb390;
P_0c0cb390: /* original f3e6, guest PC 0x0c0cb390 */
if(!s->budget--) { s->failed_pc=0x0c0cb390u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cb392;
P_0c0cb392: /* original e004, guest PC 0x0c0cb392 */
if(!s->budget--) { s->failed_pc=0x0c0cb392u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb394;
P_0c0cb394: /* original f23c, guest PC 0x0c0cb394 */
if(!s->budget--) { s->failed_pc=0x0c0cb394u; return 0; }
vf3_matrix_move(s,2,3);
goto P_0c0cb396;
P_0c0cb396: /* original f232, guest PC 0x0c0cb396 */
if(!s->budget--) { s->failed_pc=0x0c0cb396u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0cb398;
P_0c0cb398: /* original ff27, guest PC 0x0c0cb398 */
if(!s->budget--) { s->failed_pc=0x0c0cb398u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb39a;
P_0c0cb39a: /* original e010, guest PC 0x0c0cb39a */
if(!s->budget--) { s->failed_pc=0x0c0cb39au; return 0; }
r[0]=0x00000010u;
goto P_0c0cb39c;
P_0c0cb39c: /* original f3cc, guest PC 0x0c0cb39c */
if(!s->budget--) { s->failed_pc=0x0c0cb39cu; return 0; }
vf3_matrix_move(s,3,12);
goto P_0c0cb39e;
P_0c0cb39e: /* original f3c2, guest PC 0x0c0cb39e */
if(!s->budget--) { s->failed_pc=0x0c0cb39eu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[12],r[18],'*');
goto P_0c0cb3a0;
P_0c0cb3a0: /* original ff3a, guest PC 0x0c0cb3a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a0u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb3a2;
P_0c0cb3a2: /* original f1f6, guest PC 0x0c0cb3a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a2u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb3a4;
P_0c0cb3a4: /* original e004, guest PC 0x0c0cb3a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb3a6;
P_0c0cb3a6: /* original f01c, guest PC 0x0c0cb3a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a6u; return 0; }
vf3_matrix_move(s,0,1);
goto P_0c0cb3a8;
P_0c0cb3a8: /* original f31e, guest PC 0x0c0cb3a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3a8u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[1],fr[3],r[18]);
goto P_0c0cb3aa;
P_0c0cb3aa: /* original f231, guest PC 0x0c0cb3aa */
if(!s->budget--) { s->failed_pc=0x0c0cb3aau; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cb3ac;
P_0c0cb3ac: /* original ff3a, guest PC 0x0c0cb3ac */
if(!s->budget--) { s->failed_pc=0x0c0cb3acu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb3ae;
P_0c0cb3ae: /* original ff27, guest PC 0x0c0cb3ae */
if(!s->budget--) { s->failed_pc=0x0c0cb3aeu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0cb3b0;
P_0c0cb3b0: /* original c731, guest PC 0x0c0cb3b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b0u; return 0; }
r[0]=code_base|0x000cb478u;
goto P_0c0cb3b2;
P_0c0cb3b2: /* original f308, guest PC 0x0c0cb3b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b2u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb3b4;
P_0c0cb3b4: /* original f325, guest PC 0x0c0cb3b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[2]))!=0);
goto P_0c0cb3b6;
P_0c0cb3b6: /* original 8900, guest PC 0x0c0cb3b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb3ba; }
goto P_0c0cb3b8;
P_0c0cb3b8: /* original 2d4b, guest PC 0x0c0cb3b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3b8u; return 0; }
r[13]|=r[4];
goto P_0c0cb3ba;
P_0c0cb3ba: /* original 9055, guest PC 0x0c0cb3ba */
if(!s->budget--) { s->failed_pc=0x0c0cb3bau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb468u,2);
goto P_0c0cb3bc;
P_0c0cb3bc: /* original 05ee, guest PC 0x0c0cb3bc */
if(!s->budget--) { s->failed_pc=0x0c0cb3bcu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0cb3be;
P_0c0cb3be: /* original 60a3, guest PC 0x0c0cb3be */
if(!s->budget--) { s->failed_pc=0x0c0cb3beu; return 0; }
r[0]=r[10];
goto P_0c0cb3c0;
P_0c0cb3c0: /* original 8801, guest PC 0x0c0cb3c0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0cb3c2;
P_0c0cb3c2: /* original 8b6b, guest PC 0x0c0cb3c2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb49c; }
goto P_0c0cb3c4;
P_0c0cb3c4: /* original 2998, guest PC 0x0c0cb3c4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c4u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0cb3c6;
P_0c0cb3c6: /* original 8b02, guest PC 0x0c0cb3c6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb3ce; }
goto P_0c0cb3c8;
P_0c0cb3c8: /* original d32a, guest PC 0x0c0cb3c8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3c8u; return 0; }
r[3]=read(ram,0x0c0cb474u,4);
goto P_0c0cb3ca;
P_0c0cb3ca: /* original 23c8, guest PC 0x0c0cb3ca */
if(!s->budget--) { s->failed_pc=0x0c0cb3cau; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c0cb3cc;
P_0c0cb3cc: /* original 8966, guest PC 0x0c0cb3cc */
if(!s->budget--) { s->failed_pc=0x0c0cb3ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb49c; }
goto P_0c0cb3ce;
P_0c0cb3ce: /* original d22b, guest PC 0x0c0cb3ce */
if(!s->budget--) { s->failed_pc=0x0c0cb3ceu; return 0; }
r[2]=read(ram,0x0c0cb47cu,4);
goto P_0c0cb3d0;
P_0c0cb3d0: /* original 2528, guest PC 0x0c0cb3d0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0cb3d2;
P_0c0cb3d2: /* original 8b63, guest PC 0x0c0cb3d2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb49c; }
goto P_0c0cb3d4;
P_0c0cb3d4: /* original d32a, guest PC 0x0c0cb3d4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d4u; return 0; }
r[3]=read(ram,0x0c0cb480u,4);
goto P_0c0cb3d6;
P_0c0cb3d6: /* original 23d8, guest PC 0x0c0cb3d6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0cb3d8;
P_0c0cb3d8: /* original 8b59, guest PC 0x0c0cb3d8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3d8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb48e; }
goto P_0c0cb3da;
P_0c0cb3da: /* original 24d8, guest PC 0x0c0cb3da */
if(!s->budget--) { s->failed_pc=0x0c0cb3dau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[13])==0)!=0);
goto P_0c0cb3dc;
P_0c0cb3dc: /* original 8b57, guest PC 0x0c0cb3dc */
if(!s->budget--) { s->failed_pc=0x0c0cb3dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb48e; }
goto P_0c0cb3de;
P_0c0cb3de: /* original 9344, guest PC 0x0c0cb3de */
if(!s->budget--) { s->failed_pc=0x0c0cb3deu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb46au,2);
goto P_0c0cb3e0;
P_0c0cb3e0: /* original 2c38, guest PC 0x0c0cb3e0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c0cb3e2;
P_0c0cb3e2: /* original 8b54, guest PC 0x0c0cb3e2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb48e; }
goto P_0c0cb3e4;
P_0c0cb3e4: /* original c727, guest PC 0x0c0cb3e4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e4u; return 0; }
r[0]=code_base|0x000cb484u;
goto P_0c0cb3e6;
P_0c0cb3e6: /* original f308, guest PC 0x0c0cb3e6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0cb3e8;
P_0c0cb3e8: /* original e050, guest PC 0x0c0cb3e8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3e8u; return 0; }
r[0]=0x00000050u;
goto P_0c0cb3ea;
P_0c0cb3ea: /* original ff3a, guest PC 0x0c0cb3ea */
if(!s->budget--) { s->failed_pc=0x0c0cb3eau; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb3ec;
P_0c0cb3ec: /* original f3f6, guest PC 0x0c0cb3ec */
if(!s->budget--) { s->failed_pc=0x0c0cb3ecu; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0cb3ee;
P_0c0cb3ee: /* original e04c, guest PC 0x0c0cb3ee */
if(!s->budget--) { s->failed_pc=0x0c0cb3eeu; return 0; }
r[0]=0x0000004cu;
goto P_0c0cb3f0;
P_0c0cb3f0: /* original f2f6, guest PC 0x0c0cb3f0 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f0u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0cb3f2;
P_0c0cb3f2: /* original e048, guest PC 0x0c0cb3f2 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f2u; return 0; }
r[0]=0x00000048u;
goto P_0c0cb3f4;
P_0c0cb3f4: /* original f1f6, guest PC 0x0c0cb3f4 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f4u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb3f6;
P_0c0cb3f6: /* original e044, guest PC 0x0c0cb3f6 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f6u; return 0; }
r[0]=0x00000044u;
goto P_0c0cb3f8;
P_0c0cb3f8: /* original f7f8, guest PC 0x0c0cb3f8 */
if(!s->budget--) { s->failed_pc=0x0c0cb3f8u; return 0; }
vf3_matrix_load(s,ram,7,r[15]);
goto P_0c0cb3fa;
P_0c0cb3fa: /* original f6f8, guest PC 0x0c0cb3fa */
if(!s->budget--) { s->failed_pc=0x0c0cb3fau; return 0; }
vf3_matrix_load(s,ram,6,r[15]);
goto P_0c0cb3fc;
P_0c0cb3fc: /* original ff1a, guest PC 0x0c0cb3fc */
if(!s->budget--) { s->failed_pc=0x0c0cb3fcu; return 0; }
vf3_matrix_store(s,ram,1,r[15]);
goto P_0c0cb3fe;
P_0c0cb3fe: /* original f722, guest PC 0x0c0cb3fe */
if(!s->budget--) { s->failed_pc=0x0c0cb3feu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c0cb400;
P_0c0cb400: /* original f632, guest PC 0x0c0cb400 */
if(!s->budget--) { s->failed_pc=0x0c0cb400u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c0cb402;
P_0c0cb402: /* original f1f6, guest PC 0x0c0cb402 */
if(!s->budget--) { s->failed_pc=0x0c0cb402u; return 0; }
vf3_matrix_load(s,ram,1,r[15]+r[0]);
goto P_0c0cb404;
P_0c0cb404: /* original e004, guest PC 0x0c0cb404 */
if(!s->budget--) { s->failed_pc=0x0c0cb404u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb406;
P_0c0cb406: /* original ff17, guest PC 0x0c0cb406 */
if(!s->budget--) { s->failed_pc=0x0c0cb406u; return 0; }
vf3_matrix_store(s,ram,1,r[15]+r[0]);
goto P_0c0cb408;
P_0c0cb408: /* original f51c, guest PC 0x0c0cb408 */
if(!s->budget--) { s->failed_pc=0x0c0cb408u; return 0; }
vf3_matrix_move(s,5,1);
goto P_0c0cb40a;
P_0c0cb40a: /* original b056, guest PC 0x0c0cb40a */
if(!s->budget--) { s->failed_pc=0x0c0cb40au; return 0; }
target=code_base|0x0c0cb4bau; r[16]=code_base|0x0c0cb40eu;
vf3_matrix_load(s,ram,4,r[15]);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb40eu) { target=s->pc; goto dispatch; }
goto P_0c0cb40e;
P_0c0cb40c: /* original f4f8, guest PC 0x0c0cb40c */
if(!s->budget--) { s->failed_pc=0x0c0cb40cu; return 0; }
vf3_matrix_load(s,ram,4,r[15]);
goto P_0c0cb40e;
P_0c0cb40e: /* original 902d, guest PC 0x0c0cb40e */
if(!s->budget--) { s->failed_pc=0x0c0cb40eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb46cu,2);
goto P_0c0cb410;
P_0c0cb410: /* original e406, guest PC 0x0c0cb410 */
if(!s->budget--) { s->failed_pc=0x0c0cb410u; return 0; }
r[4]=0x00000006u;
goto P_0c0cb412;
P_0c0cb412: /* original f40c, guest PC 0x0c0cb412 */
if(!s->budget--) { s->failed_pc=0x0c0cb412u; return 0; }
vf3_matrix_move(s,4,0);
goto P_0c0cb414;
P_0c0cb414: /* original e600, guest PC 0x0c0cb414 */
if(!s->budget--) { s->failed_pc=0x0c0cb414u; return 0; }
r[6]=0x00000000u;
goto P_0c0cb416;
P_0c0cb416: /* original fe47, guest PC 0x0c0cb416 */
if(!s->budget--) { s->failed_pc=0x0c0cb416u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0cb418;
P_0c0cb418: /* original 6343, guest PC 0x0c0cb418 */
if(!s->budget--) { s->failed_pc=0x0c0cb418u; return 0; }
r[3]=r[4];
goto P_0c0cb41a;
P_0c0cb41a: /* original 33b8, guest PC 0x0c0cb41a */
if(!s->budget--) { s->failed_pc=0x0c0cb41au; return 0; }
r[3]-=r[11];
goto P_0c0cb41c;
P_0c0cb41c: /* original 1f32, guest PC 0x0c0cb41c */
if(!s->budget--) { s->failed_pc=0x0c0cb41cu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0cb41e;
P_0c0cb41e: /* original 55fe, guest PC 0x0c0cb41e */
if(!s->budget--) { s->failed_pc=0x0c0cb41eu; return 0; }
r[5]=read(ram,r[15]+56,4);
goto P_0c0cb420;
P_0c0cb420: /* original d219, guest PC 0x0c0cb420 */
if(!s->budget--) { s->failed_pc=0x0c0cb420u; return 0; }
r[2]=read(ram,0x0c0cb488u,4);
goto P_0c0cb422;
P_0c0cb422: /* original 353c, guest PC 0x0c0cb422 */
if(!s->budget--) { s->failed_pc=0x0c0cb422u; return 0; }
r[5]+=r[3];
goto P_0c0cb424;
P_0c0cb424: /* original 6150, guest PC 0x0c0cb424 */
if(!s->budget--) { s->failed_pc=0x0c0cb424u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[5],1);
r[1]=tmp;
goto P_0c0cb426;
P_0c0cb426: /* original 420b, guest PC 0x0c0cb426 */
if(!s->budget--) { s->failed_pc=0x0c0cb426u; return 0; }
target=r[2];
r[16]=code_base|0x0c0cb42au;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0cb42au) { target=s->pc; goto dispatch; }
goto P_0c0cb42a;
P_0c0cb428: /* original e004, guest PC 0x0c0cb428 */
if(!s->budget--) { s->failed_pc=0x0c0cb428u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb42a;
P_0c0cb42a: /* original 9220, guest PC 0x0c0cb42a */
if(!s->budget--) { s->failed_pc=0x0c0cb42au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb46eu,2);
goto P_0c0cb42c;
P_0c0cb42c: /* original 6503, guest PC 0x0c0cb42c */
if(!s->budget--) { s->failed_pc=0x0c0cb42cu; return 0; }
r[5]=r[0];
goto P_0c0cb42e;
P_0c0cb42e: /* original 635e, guest PC 0x0c0cb42e */
if(!s->budget--) { s->failed_pc=0x0c0cb42eu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb430;
P_0c0cb430: /* original 32ec, guest PC 0x0c0cb430 */
if(!s->budget--) { s->failed_pc=0x0c0cb430u; return 0; }
r[2]+=r[14];
goto P_0c0cb432;
P_0c0cb432: /* original 4308, guest PC 0x0c0cb432 */
if(!s->budget--) { s->failed_pc=0x0c0cb432u; return 0; }
r[3]<<=2;
goto P_0c0cb434;
P_0c0cb434: /* original 332c, guest PC 0x0c0cb434 */
if(!s->budget--) { s->failed_pc=0x0c0cb434u; return 0; }
r[3]+=r[2];
goto P_0c0cb436;
P_0c0cb436: /* original 655e, guest PC 0x0c0cb436 */
if(!s->budget--) { s->failed_pc=0x0c0cb436u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)r[5];
goto P_0c0cb438;
P_0c0cb438: /* original f338, guest PC 0x0c0cb438 */
if(!s->budget--) { s->failed_pc=0x0c0cb438u; return 0; }
vf3_matrix_load(s,ram,3,r[3]);
goto P_0c0cb43a;
P_0c0cb43a: /* original 6353, guest PC 0x0c0cb43a */
if(!s->budget--) { s->failed_pc=0x0c0cb43au; return 0; }
r[3]=r[5];
goto P_0c0cb43c;
P_0c0cb43c: /* original 4500, guest PC 0x0c0cb43c */
if(!s->budget--) { s->failed_pc=0x0c0cb43cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0cb43e;
P_0c0cb43e: /* original 353c, guest PC 0x0c0cb43e */
if(!s->budget--) { s->failed_pc=0x0c0cb43eu; return 0; }
r[5]+=r[3];
goto P_0c0cb440;
P_0c0cb440: /* original ff3a, guest PC 0x0c0cb440 */
if(!s->budget--) { s->failed_pc=0x0c0cb440u; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0cb442;
P_0c0cb442: /* original 4508, guest PC 0x0c0cb442 */
if(!s->budget--) { s->failed_pc=0x0c0cb442u; return 0; }
r[5]<<=2;
goto P_0c0cb444;
P_0c0cb444: /* original e004, guest PC 0x0c0cb444 */
if(!s->budget--) { s->failed_pc=0x0c0cb444u; return 0; }
r[0]=0x00000004u;
goto P_0c0cb446;
P_0c0cb446: /* original 358c, guest PC 0x0c0cb446 */
if(!s->budget--) { s->failed_pc=0x0c0cb446u; return 0; }
r[5]+=r[8];
goto P_0c0cb448;
P_0c0cb448: /* original f556, guest PC 0x0c0cb448 */
if(!s->budget--) { s->failed_pc=0x0c0cb448u; return 0; }
vf3_matrix_load(s,ram,5,r[5]+r[0]);
goto P_0c0cb44a;
P_0c0cb44a: /* original f531, guest PC 0x0c0cb44a */
if(!s->budget--) { s->failed_pc=0x0c0cb44au; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0cb44c;
P_0c0cb44c: /* original f545, guest PC 0x0c0cb44c */
if(!s->budget--) { s->failed_pc=0x0c0cb44cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0cb44e;
P_0c0cb44e: /* original 8900, guest PC 0x0c0cb44e */
if(!s->budget--) { s->failed_pc=0x0c0cb44eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cb452; }
goto P_0c0cb450;
P_0c0cb450: /* original e601, guest PC 0x0c0cb450 */
if(!s->budget--) { s->failed_pc=0x0c0cb450u; return 0; }
r[6]=0x00000001u;
goto P_0c0cb452;
P_0c0cb452: /* original 4410, guest PC 0x0c0cb452 */
if(!s->budget--) { s->failed_pc=0x0c0cb452u; return 0; }
--r[4];
r[17]=(r[17]&~1u)|((r[4]==0)!=0);
goto P_0c0cb454;
P_0c0cb454: /* original 8be0, guest PC 0x0c0cb454 */
if(!s->budget--) { s->failed_pc=0x0c0cb454u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb418; }
goto P_0c0cb456;
P_0c0cb456: /* original e301, guest PC 0x0c0cb456 */
if(!s->budget--) { s->failed_pc=0x0c0cb456u; return 0; }
r[3]=0x00000001u;
goto P_0c0cb458;
P_0c0cb458: /* original 2638, guest PC 0x0c0cb458 */
if(!s->budget--) { s->failed_pc=0x0c0cb458u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0cb45a;
P_0c0cb45a: /* original a017, guest PC 0x0c0cb45a */
if(!s->budget--) { s->failed_pc=0x0c0cb45au; return 0; }
goto P_0c0cb48c;
P_0c0cb45c: /* original 0009, guest PC 0x0c0cb45c */
if(!s->budget--) { s->failed_pc=0x0c0cb45cu; return 0; }
if(!vf3_matrix_family(0x0c0cb45eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0cb45eu; return 0; } return 1;
P_0c0cb48c: /* original 8b06, guest PC 0x0c0cb48c */
if(!s->budget--) { s->failed_pc=0x0c0cb48cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cb49c; }
goto P_0c0cb48e;
P_0c0cb48e: /* original 9062, guest PC 0x0c0cb48e */
if(!s->budget--) { s->failed_pc=0x0c0cb48eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0cb556u,2);
goto P_0c0cb490;
P_0c0cb490: /* original f38d, guest PC 0x0c0cb490 */
if(!s->budget--) { s->failed_pc=0x0c0cb490u; return 0; }
fr[3]=0;
goto P_0c0cb492;
P_0c0cb492: /* original fe37, guest PC 0x0c0cb492 */
if(!s->budget--) { s->failed_pc=0x0c0cb492u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb494;
P_0c0cb494: /* original 70f8, guest PC 0x0c0cb494 */
if(!s->budget--) { s->failed_pc=0x0c0cb494u; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0cb496;
P_0c0cb496: /* original fe37, guest PC 0x0c0cb496 */
if(!s->budget--) { s->failed_pc=0x0c0cb496u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cb498;
P_0c0cb498: /* original d330, guest PC 0x0c0cb498 */
if(!s->budget--) { s->failed_pc=0x0c0cb498u; return 0; }
r[3]=read(ram,0x0c0cb55cu,4);
goto P_0c0cb49a;
P_0c0cb49a: /* original 2d39, guest PC 0x0c0cb49a */
if(!s->budget--) { s->failed_pc=0x0c0cb49au; return 0; }
r[13]&=r[3];
goto P_0c0cb49c;
P_0c0cb49c: /* original 2ed2, guest PC 0x0c0cb49c */
if(!s->budget--) { s->failed_pc=0x0c0cb49cu; return 0; }
write(ram,r[14],r[13],4);
goto P_0c0cb49e;
P_0c0cb49e: /* original 7f74, guest PC 0x0c0cb49e */
if(!s->budget--) { s->failed_pc=0x0c0cb49eu; return 0; }
r[15]+=0x00000074u;
goto P_0c0cb4a0;
P_0c0cb4a0: /* original 4f26, guest PC 0x0c0cb4a0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cb4a2;
P_0c0cb4a2: /* original fcf9, guest PC 0x0c0cb4a2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a2u; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4a4;
P_0c0cb4a4: /* original fdf9, guest PC 0x0c0cb4a4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a4u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4a6;
P_0c0cb4a6: /* original fef9, guest PC 0x0c0cb4a6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a6u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4a8;
P_0c0cb4a8: /* original fff9, guest PC 0x0c0cb4a8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4a8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0cb4aa;
P_0c0cb4aa: /* original 68f6, guest PC 0x0c0cb4aa */
if(!s->budget--) { s->failed_pc=0x0c0cb4aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0cb4ac;
P_0c0cb4ac: /* original 69f6, guest PC 0x0c0cb4ac */
if(!s->budget--) { s->failed_pc=0x0c0cb4acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0cb4ae;
P_0c0cb4ae: /* original 6af6, guest PC 0x0c0cb4ae */
if(!s->budget--) { s->failed_pc=0x0c0cb4aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0cb4b0;
P_0c0cb4b0: /* original 6bf6, guest PC 0x0c0cb4b0 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0cb4b2;
P_0c0cb4b2: /* original 6cf6, guest PC 0x0c0cb4b2 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0cb4b4;
P_0c0cb4b4: /* original 6df6, guest PC 0x0c0cb4b4 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0cb4b6;
P_0c0cb4b6: /* original 000b, guest PC 0x0c0cb4b6 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b6u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cb4b8: /* original 6ef6, guest PC 0x0c0cb4b8 */
if(!s->budget--) { s->failed_pc=0x0c0cb4b8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cb4bau,s,ram);
unsupported: s->failed_pc=target; return 0;
}
