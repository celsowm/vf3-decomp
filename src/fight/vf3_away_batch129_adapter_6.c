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
int vf3_away_batch129_adapter_6(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c059d72u: goto P_0c059d72;
case 0x0c059d74u: goto P_0c059d74;
case 0x0c059d76u: goto P_0c059d76;
case 0x0c059d78u: goto P_0c059d78;
case 0x0c059d7au: goto P_0c059d7a;
case 0x0c059d7cu: goto P_0c059d7c;
case 0x0c059f7cu: goto P_0c059f7c;
case 0x0c059f7eu: goto P_0c059f7e;
case 0x0c059f80u: goto P_0c059f80;
case 0x0c059f82u: goto P_0c059f82;
case 0x0c059f84u: goto P_0c059f84;
case 0x0c059f86u: goto P_0c059f86;
case 0x0c059f88u: goto P_0c059f88;
case 0x0c059f8au: goto P_0c059f8a;
case 0x0c059f8cu: goto P_0c059f8c;
case 0x0c059f8eu: goto P_0c059f8e;
case 0x0c059f90u: goto P_0c059f90;
case 0x0c059f92u: goto P_0c059f92;
case 0x0c059f94u: goto P_0c059f94;
case 0x0c059f96u: goto P_0c059f96;
case 0x0c059f98u: goto P_0c059f98;
case 0x0c059f9au: goto P_0c059f9a;
case 0x0c059f9cu: goto P_0c059f9c;
case 0x0c059f9eu: goto P_0c059f9e;
case 0x0c059fa0u: goto P_0c059fa0;
case 0x0c059fa2u: goto P_0c059fa2;
case 0x0c059fa4u: goto P_0c059fa4;
case 0x0c059fa6u: goto P_0c059fa6;
case 0x0c059fa8u: goto P_0c059fa8;
case 0x0c059faau: goto P_0c059faa;
case 0x0c059facu: goto P_0c059fac;
case 0x0c059faeu: goto P_0c059fae;
case 0x0c059fb0u: goto P_0c059fb0;
case 0x0c059fb2u: goto P_0c059fb2;
case 0x0c059fb4u: goto P_0c059fb4;
case 0x0c059fb6u: goto P_0c059fb6;
case 0x0c059fb8u: goto P_0c059fb8;
case 0x0c059fbau: goto P_0c059fba;
case 0x0c059fbcu: goto P_0c059fbc;
case 0x0c059fbeu: goto P_0c059fbe;
case 0x0c059fc0u: goto P_0c059fc0;
case 0x0c059fc2u: goto P_0c059fc2;
case 0x0c059fc4u: goto P_0c059fc4;
case 0x0c059fc6u: goto P_0c059fc6;
case 0x0c059fc8u: goto P_0c059fc8;
case 0x0c059fcau: goto P_0c059fca;
case 0x0c059fccu: goto P_0c059fcc;
case 0x0c059fceu: goto P_0c059fce;
case 0x0c059fd0u: goto P_0c059fd0;
case 0x0c059fd2u: goto P_0c059fd2;
case 0x0c059fd4u: goto P_0c059fd4;
case 0x0c059fd6u: goto P_0c059fd6;
case 0x0c059fd8u: goto P_0c059fd8;
case 0x0c059fdau: goto P_0c059fda;
case 0x0c059fdcu: goto P_0c059fdc;
case 0x0c059fdeu: goto P_0c059fde;
case 0x0c059fe0u: goto P_0c059fe0;
case 0x0c059fe2u: goto P_0c059fe2;
case 0x0c059fe4u: goto P_0c059fe4;
case 0x0c059fe6u: goto P_0c059fe6;
case 0x0c059fe8u: goto P_0c059fe8;
case 0x0c059feau: goto P_0c059fea;
case 0x0c059fecu: goto P_0c059fec;
case 0x0c059feeu: goto P_0c059fee;
case 0x0c059ff0u: goto P_0c059ff0;
case 0x0c059ff2u: goto P_0c059ff2;
case 0x0c059ff4u: goto P_0c059ff4;
case 0x0c059ff6u: goto P_0c059ff6;
case 0x0c059ff8u: goto P_0c059ff8;
case 0x0c059ffau: goto P_0c059ffa;
case 0x0c059ffcu: goto P_0c059ffc;
case 0x0c059ffeu: goto P_0c059ffe;
case 0x0c05a000u: goto P_0c05a000;
case 0x0c05a002u: goto P_0c05a002;
case 0x0c05a004u: goto P_0c05a004;
case 0x0c05a006u: goto P_0c05a006;
case 0x0c05a008u: goto P_0c05a008;
case 0x0c05a00au: goto P_0c05a00a;
case 0x0c05a00cu: goto P_0c05a00c;
case 0x0c05a00eu: goto P_0c05a00e;
case 0x0c05a010u: goto P_0c05a010;
case 0x0c05a012u: goto P_0c05a012;
case 0x0c05a014u: goto P_0c05a014;
case 0x0c05a016u: goto P_0c05a016;
case 0x0c05a018u: goto P_0c05a018;
case 0x0c05a01au: goto P_0c05a01a;
case 0x0c05a01cu: goto P_0c05a01c;
case 0x0c05a01eu: goto P_0c05a01e;
case 0x0c05a020u: goto P_0c05a020;
case 0x0c05a022u: goto P_0c05a022;
case 0x0c05a024u: goto P_0c05a024;
case 0x0c05a026u: goto P_0c05a026;
case 0x0c05a028u: goto P_0c05a028;
case 0x0c05a02au: goto P_0c05a02a;
case 0x0c05a02cu: goto P_0c05a02c;
case 0x0c05a02eu: goto P_0c05a02e;
case 0x0c05a030u: goto P_0c05a030;
case 0x0c05a032u: goto P_0c05a032;
case 0x0c05a034u: goto P_0c05a034;
case 0x0c05a036u: goto P_0c05a036;
case 0x0c05a038u: goto P_0c05a038;
case 0x0c05a03au: goto P_0c05a03a;
case 0x0c05a03cu: goto P_0c05a03c;
case 0x0c05a03eu: goto P_0c05a03e;
case 0x0c05a040u: goto P_0c05a040;
case 0x0c05a042u: goto P_0c05a042;
case 0x0c05a044u: goto P_0c05a044;
case 0x0c05a046u: goto P_0c05a046;
case 0x0c05a048u: goto P_0c05a048;
case 0x0c05a04au: goto P_0c05a04a;
case 0x0c05a04cu: goto P_0c05a04c;
case 0x0c05a04eu: goto P_0c05a04e;
case 0x0c05a050u: goto P_0c05a050;
case 0x0c05a052u: goto P_0c05a052;
case 0x0c05a054u: goto P_0c05a054;
case 0x0c05a056u: goto P_0c05a056;
case 0x0c05a058u: goto P_0c05a058;
case 0x0c05a05au: goto P_0c05a05a;
case 0x0c05a05cu: goto P_0c05a05c;
case 0x0c05a05eu: goto P_0c05a05e;
case 0x0c05a060u: goto P_0c05a060;
case 0x0c05a062u: goto P_0c05a062;
case 0x0c05a064u: goto P_0c05a064;
case 0x0c05a066u: goto P_0c05a066;
case 0x0c05a068u: goto P_0c05a068;
case 0x0c05a06au: goto P_0c05a06a;
case 0x0c05a06cu: goto P_0c05a06c;
case 0x0c05a06eu: goto P_0c05a06e;
case 0x0c05a070u: goto P_0c05a070;
case 0x0c05a072u: goto P_0c05a072;
case 0x0c05a074u: goto P_0c05a074;
case 0x0c05a076u: goto P_0c05a076;
case 0x0c05a078u: goto P_0c05a078;
case 0x0c05a07au: goto P_0c05a07a;
case 0x0c05a07cu: goto P_0c05a07c;
case 0x0c05a07eu: goto P_0c05a07e;
case 0x0c05a080u: goto P_0c05a080;
case 0x0c05a082u: goto P_0c05a082;
case 0x0c05a084u: goto P_0c05a084;
case 0x0c05a086u: goto P_0c05a086;
case 0x0c05a088u: goto P_0c05a088;
case 0x0c05a08au: goto P_0c05a08a;
case 0x0c05a08cu: goto P_0c05a08c;
case 0x0c05a08eu: goto P_0c05a08e;
case 0x0c05a090u: goto P_0c05a090;
case 0x0c05a092u: goto P_0c05a092;
case 0x0c05a094u: goto P_0c05a094;
case 0x0c05a096u: goto P_0c05a096;
case 0x0c05a098u: goto P_0c05a098;
case 0x0c05a09au: goto P_0c05a09a;
case 0x0c05a09cu: goto P_0c05a09c;
case 0x0c05a09eu: goto P_0c05a09e;
case 0x0c05a0a0u: goto P_0c05a0a0;
case 0x0c05a0a2u: goto P_0c05a0a2;
case 0x0c05a0a4u: goto P_0c05a0a4;
case 0x0c05a0a6u: goto P_0c05a0a6;
case 0x0c05a0a8u: goto P_0c05a0a8;
case 0x0c05a0aau: goto P_0c05a0aa;
case 0x0c05a0acu: goto P_0c05a0ac;
case 0x0c05a0aeu: goto P_0c05a0ae;
case 0x0c05a0b0u: goto P_0c05a0b0;
case 0x0c05a0b2u: goto P_0c05a0b2;
case 0x0c05a0b4u: goto P_0c05a0b4;
case 0x0c05a0b6u: goto P_0c05a0b6;
case 0x0c05a0b8u: goto P_0c05a0b8;
case 0x0c05a0bau: goto P_0c05a0ba;
case 0x0c05a0bcu: goto P_0c05a0bc;
case 0x0c05a0beu: goto P_0c05a0be;
case 0x0c05a0c0u: goto P_0c05a0c0;
case 0x0c05a0c2u: goto P_0c05a0c2;
case 0x0c05a0c4u: goto P_0c05a0c4;
case 0x0c05a0c6u: goto P_0c05a0c6;
case 0x0c05a0c8u: goto P_0c05a0c8;
case 0x0c05a0cau: goto P_0c05a0ca;
case 0x0c05a0ccu: goto P_0c05a0cc;
case 0x0c05a0ceu: goto P_0c05a0ce;
case 0x0c05a0d0u: goto P_0c05a0d0;
case 0x0c05a0d2u: goto P_0c05a0d2;
case 0x0c05a0d4u: goto P_0c05a0d4;
case 0x0c05a0d6u: goto P_0c05a0d6;
case 0x0c05a0d8u: goto P_0c05a0d8;
case 0x0c05a0dau: goto P_0c05a0da;
case 0x0c05a0dcu: goto P_0c05a0dc;
case 0x0c05a0deu: goto P_0c05a0de;
case 0x0c05a0e0u: goto P_0c05a0e0;
case 0x0c05a0e2u: goto P_0c05a0e2;
case 0x0c05a0e4u: goto P_0c05a0e4;
case 0x0c05a0e6u: goto P_0c05a0e6;
case 0x0c05a0e8u: goto P_0c05a0e8;
case 0x0c05a0eau: goto P_0c05a0ea;
case 0x0c05a0ecu: goto P_0c05a0ec;
case 0x0c05a0eeu: goto P_0c05a0ee;
case 0x0c05a0f0u: goto P_0c05a0f0;
case 0x0c05a0f2u: goto P_0c05a0f2;
case 0x0c05a0f4u: goto P_0c05a0f4;
case 0x0c05a0f6u: goto P_0c05a0f6;
case 0x0c05a0f8u: goto P_0c05a0f8;
case 0x0c05a0fau: goto P_0c05a0fa;
case 0x0c05a0fcu: goto P_0c05a0fc;
case 0x0c05a0feu: goto P_0c05a0fe;
case 0x0c05a100u: goto P_0c05a100;
case 0x0c05a102u: goto P_0c05a102;
case 0x0c05a104u: goto P_0c05a104;
case 0x0c05a106u: goto P_0c05a106;
case 0x0c05a108u: goto P_0c05a108;
case 0x0c05a10au: goto P_0c05a10a;
case 0x0c05a10cu: goto P_0c05a10c;
case 0x0c05a10eu: goto P_0c05a10e;
case 0x0c05a110u: goto P_0c05a110;
case 0x0c05a112u: goto P_0c05a112;
case 0x0c05a114u: goto P_0c05a114;
case 0x0c05a116u: goto P_0c05a116;
case 0x0c05a118u: goto P_0c05a118;
case 0x0c05a11au: goto P_0c05a11a;
case 0x0c05a11cu: goto P_0c05a11c;
case 0x0c05a11eu: goto P_0c05a11e;
case 0x0c05a120u: goto P_0c05a120;
case 0x0c05a122u: goto P_0c05a122;
case 0x0c05a124u: goto P_0c05a124;
case 0x0c05a126u: goto P_0c05a126;
case 0x0c05a128u: goto P_0c05a128;
case 0x0c05a12au: goto P_0c05a12a;
case 0x0c05a12cu: goto P_0c05a12c;
case 0x0c05a12eu: goto P_0c05a12e;
case 0x0c05a130u: goto P_0c05a130;
case 0x0c05a132u: goto P_0c05a132;
case 0x0c05a134u: goto P_0c05a134;
case 0x0c05a136u: goto P_0c05a136;
case 0x0c05a138u: goto P_0c05a138;
case 0x0c05a13au: goto P_0c05a13a;
case 0x0c05a13cu: goto P_0c05a13c;
case 0x0c05a13eu: goto P_0c05a13e;
case 0x0c05a140u: goto P_0c05a140;
case 0x0c05a142u: goto P_0c05a142;
case 0x0c05a144u: goto P_0c05a144;
case 0x0c05a146u: goto P_0c05a146;
case 0x0c05a148u: goto P_0c05a148;
case 0x0c05a14au: goto P_0c05a14a;
case 0x0c05a14cu: goto P_0c05a14c;
case 0x0c05a14eu: goto P_0c05a14e;
case 0x0c05a150u: goto P_0c05a150;
case 0x0c05a152u: goto P_0c05a152;
case 0x0c05a154u: goto P_0c05a154;
case 0x0c05a156u: goto P_0c05a156;
case 0x0c05a158u: goto P_0c05a158;
case 0x0c05a15au: goto P_0c05a15a;
case 0x0c05a15cu: goto P_0c05a15c;
case 0x0c05a15eu: goto P_0c05a15e;
case 0x0c05a160u: goto P_0c05a160;
case 0x0c05a162u: goto P_0c05a162;
case 0x0c05a164u: goto P_0c05a164;
case 0x0c05a166u: goto P_0c05a166;
case 0x0c05a168u: goto P_0c05a168;
case 0x0c05a16au: goto P_0c05a16a;
case 0x0c05a16cu: goto P_0c05a16c;
case 0x0c05a16eu: goto P_0c05a16e;
case 0x0c05a170u: goto P_0c05a170;
case 0x0c05a172u: goto P_0c05a172;
case 0x0c05a174u: goto P_0c05a174;
case 0x0c05a176u: goto P_0c05a176;
case 0x0c05a178u: goto P_0c05a178;
case 0x0c05a17au: goto P_0c05a17a;
case 0x0c05a17cu: goto P_0c05a17c;
case 0x0c05a17eu: goto P_0c05a17e;
case 0x0c05a180u: goto P_0c05a180;
case 0x0c05a182u: goto P_0c05a182;
case 0x0c05a184u: goto P_0c05a184;
case 0x0c05a186u: goto P_0c05a186;
case 0x0c05a188u: goto P_0c05a188;
case 0x0c05a18au: goto P_0c05a18a;
case 0x0c05a20cu: goto P_0c05a20c;
case 0x0c05a20eu: goto P_0c05a20e;
case 0x0c05a210u: goto P_0c05a210;
case 0x0c05a212u: goto P_0c05a212;
case 0x0c05a214u: goto P_0c05a214;
case 0x0c05a216u: goto P_0c05a216;
case 0x0c05a218u: goto P_0c05a218;
case 0x0c05a21au: goto P_0c05a21a;
case 0x0c05a21cu: goto P_0c05a21c;
case 0x0c05a21eu: goto P_0c05a21e;
case 0x0c05a220u: goto P_0c05a220;
case 0x0c05a222u: goto P_0c05a222;
case 0x0c05a224u: goto P_0c05a224;
case 0x0c05a226u: goto P_0c05a226;
case 0x0c05a228u: goto P_0c05a228;
case 0x0c05a22au: goto P_0c05a22a;
case 0x0c05a22cu: goto P_0c05a22c;
case 0x0c05a22eu: goto P_0c05a22e;
case 0x0c05a230u: goto P_0c05a230;
case 0x0c05a232u: goto P_0c05a232;
case 0x0c05a234u: goto P_0c05a234;
case 0x0c05a236u: goto P_0c05a236;
case 0x0c05a238u: goto P_0c05a238;
case 0x0c05a23au: goto P_0c05a23a;
case 0x0c05a23cu: goto P_0c05a23c;
case 0x0c05a23eu: goto P_0c05a23e;
case 0x0c05a240u: goto P_0c05a240;
case 0x0c05a242u: goto P_0c05a242;
case 0x0c05a244u: goto P_0c05a244;
case 0x0c05a246u: goto P_0c05a246;
case 0x0c05a248u: goto P_0c05a248;
case 0x0c05a24au: goto P_0c05a24a;
case 0x0c05a24cu: goto P_0c05a24c;
case 0x0c05a24eu: goto P_0c05a24e;
case 0x0c05a250u: goto P_0c05a250;
case 0x0c05a252u: goto P_0c05a252;
case 0x0c05a254u: goto P_0c05a254;
case 0x0c05a256u: goto P_0c05a256;
case 0x0c05a258u: goto P_0c05a258;
case 0x0c05a25au: goto P_0c05a25a;
case 0x0c05a25cu: goto P_0c05a25c;
case 0x0c05a25eu: goto P_0c05a25e;
case 0x0c05a260u: goto P_0c05a260;
case 0x0c05a262u: goto P_0c05a262;
case 0x0c05a264u: goto P_0c05a264;
case 0x0c05a266u: goto P_0c05a266;
case 0x0c05a268u: goto P_0c05a268;
case 0x0c05a26au: goto P_0c05a26a;
case 0x0c05a26cu: goto P_0c05a26c;
case 0x0c05a26eu: goto P_0c05a26e;
case 0x0c05a270u: goto P_0c05a270;
case 0x0c05a272u: goto P_0c05a272;
case 0x0c05a274u: goto P_0c05a274;
case 0x0c05a276u: goto P_0c05a276;
case 0x0c05a278u: goto P_0c05a278;
case 0x0c05a27au: goto P_0c05a27a;
case 0x0c05a27cu: goto P_0c05a27c;
case 0x0c05a27eu: goto P_0c05a27e;
case 0x0c05a280u: goto P_0c05a280;
case 0x0c05a282u: goto P_0c05a282;
case 0x0c05a284u: goto P_0c05a284;
case 0x0c05a286u: goto P_0c05a286;
case 0x0c05a288u: goto P_0c05a288;
case 0x0c05a28au: goto P_0c05a28a;
case 0x0c05a28cu: goto P_0c05a28c;
case 0x0c05a28eu: goto P_0c05a28e;
case 0x0c05a290u: goto P_0c05a290;
case 0x0c05a292u: goto P_0c05a292;
case 0x0c05a294u: goto P_0c05a294;
case 0x0c05a296u: goto P_0c05a296;
case 0x0c05a298u: goto P_0c05a298;
case 0x0c05a29au: goto P_0c05a29a;
case 0x0c05a29cu: goto P_0c05a29c;
case 0x0c05a29eu: goto P_0c05a29e;
case 0x0c05a2a0u: goto P_0c05a2a0;
case 0x0c05a2a2u: goto P_0c05a2a2;
case 0x0c05a2a4u: goto P_0c05a2a4;
case 0x0c05a2a6u: goto P_0c05a2a6;
case 0x0c05a2a8u: goto P_0c05a2a8;
case 0x0c05a2aau: goto P_0c05a2aa;
case 0x0c05a2acu: goto P_0c05a2ac;
case 0x0c05a2aeu: goto P_0c05a2ae;
case 0x0c05a2b0u: goto P_0c05a2b0;
case 0x0c05a2b2u: goto P_0c05a2b2;
case 0x0c05a2b4u: goto P_0c05a2b4;
case 0x0c05a2b6u: goto P_0c05a2b6;
case 0x0c05a2b8u: goto P_0c05a2b8;
case 0x0c05a2bau: goto P_0c05a2ba;
case 0x0c05a2bcu: goto P_0c05a2bc;
case 0x0c05a2beu: goto P_0c05a2be;
case 0x0c05a2c0u: goto P_0c05a2c0;
case 0x0c05a2c2u: goto P_0c05a2c2;
case 0x0c05a2c4u: goto P_0c05a2c4;
case 0x0c05a2c6u: goto P_0c05a2c6;
case 0x0c05a2c8u: goto P_0c05a2c8;
case 0x0c05a2cau: goto P_0c05a2ca;
case 0x0c05a2ccu: goto P_0c05a2cc;
case 0x0c05a2ceu: goto P_0c05a2ce;
case 0x0c05a2d0u: goto P_0c05a2d0;
case 0x0c05a2d2u: goto P_0c05a2d2;
case 0x0c05a2d4u: goto P_0c05a2d4;
case 0x0c05a2d6u: goto P_0c05a2d6;
case 0x0c05a2d8u: goto P_0c05a2d8;
case 0x0c05a2dau: goto P_0c05a2da;
case 0x0c05a2dcu: goto P_0c05a2dc;
case 0x0c05a2deu: goto P_0c05a2de;
case 0x0c05a2e0u: goto P_0c05a2e0;
case 0x0c05a2e2u: goto P_0c05a2e2;
case 0x0c05a2e4u: goto P_0c05a2e4;
case 0x0c05a2e6u: goto P_0c05a2e6;
case 0x0c05a2e8u: goto P_0c05a2e8;
case 0x0c05a2eau: goto P_0c05a2ea;
case 0x0c05a2ecu: goto P_0c05a2ec;
case 0x0c05a2eeu: goto P_0c05a2ee;
case 0x0c05a2f0u: goto P_0c05a2f0;
case 0x0c05a2f2u: goto P_0c05a2f2;
case 0x0c05a2f4u: goto P_0c05a2f4;
case 0x0c05a2f6u: goto P_0c05a2f6;
case 0x0c05a2f8u: goto P_0c05a2f8;
case 0x0c05a2fau: goto P_0c05a2fa;
case 0x0c05a2fcu: goto P_0c05a2fc;
case 0x0c05a2feu: goto P_0c05a2fe;
case 0x0c05a300u: goto P_0c05a300;
case 0x0c05a302u: goto P_0c05a302;
case 0x0c05a304u: goto P_0c05a304;
case 0x0c05a306u: goto P_0c05a306;
case 0x0c05a308u: goto P_0c05a308;
case 0x0c05a30au: goto P_0c05a30a;
case 0x0c05a30cu: goto P_0c05a30c;
case 0x0c05a30eu: goto P_0c05a30e;
case 0x0c05a310u: goto P_0c05a310;
case 0x0c05a312u: goto P_0c05a312;
case 0x0c05a314u: goto P_0c05a314;
case 0x0c05a316u: goto P_0c05a316;
case 0x0c05a318u: goto P_0c05a318;
case 0x0c05a31au: goto P_0c05a31a;
case 0x0c05a31cu: goto P_0c05a31c;
case 0x0c05a31eu: goto P_0c05a31e;
case 0x0c05a320u: goto P_0c05a320;
case 0x0c05a322u: goto P_0c05a322;
case 0x0c05a324u: goto P_0c05a324;
case 0x0c05a326u: goto P_0c05a326;
case 0x0c05a328u: goto P_0c05a328;
case 0x0c05a32au: goto P_0c05a32a;
case 0x0c05a32cu: goto P_0c05a32c;
case 0x0c05a32eu: goto P_0c05a32e;
case 0x0c05a330u: goto P_0c05a330;
case 0x0c05a332u: goto P_0c05a332;
case 0x0c05a334u: goto P_0c05a334;
case 0x0c05a336u: goto P_0c05a336;
case 0x0c05a338u: goto P_0c05a338;
case 0x0c05a33au: goto P_0c05a33a;
case 0x0c05a33cu: goto P_0c05a33c;
case 0x0c05a33eu: goto P_0c05a33e;
case 0x0c05a340u: goto P_0c05a340;
case 0x0c05a342u: goto P_0c05a342;
case 0x0c05a344u: goto P_0c05a344;
case 0x0c05a346u: goto P_0c05a346;
case 0x0c05a348u: goto P_0c05a348;
case 0x0c05a34au: goto P_0c05a34a;
case 0x0c05a34cu: goto P_0c05a34c;
case 0x0c05a34eu: goto P_0c05a34e;
case 0x0c05a350u: goto P_0c05a350;
case 0x0c05a352u: goto P_0c05a352;
case 0x0c05a354u: goto P_0c05a354;
case 0x0c05a356u: goto P_0c05a356;
case 0x0c05a358u: goto P_0c05a358;
case 0x0c05a35au: goto P_0c05a35a;
case 0x0c05a35cu: goto P_0c05a35c;
case 0x0c05a35eu: goto P_0c05a35e;
case 0x0c05a360u: goto P_0c05a360;
case 0x0c05a362u: goto P_0c05a362;
case 0x0c05a364u: goto P_0c05a364;
case 0x0c05a366u: goto P_0c05a366;
case 0x0c05a368u: goto P_0c05a368;
case 0x0c05a36au: goto P_0c05a36a;
case 0x0c05a36cu: goto P_0c05a36c;
case 0x0c05a36eu: goto P_0c05a36e;
case 0x0c05a370u: goto P_0c05a370;
case 0x0c05a372u: goto P_0c05a372;
case 0x0c05a374u: goto P_0c05a374;
case 0x0c05a376u: goto P_0c05a376;
case 0x0c05a378u: goto P_0c05a378;
case 0x0c05a37au: goto P_0c05a37a;
case 0x0c05a37cu: goto P_0c05a37c;
case 0x0c05a37eu: goto P_0c05a37e;
case 0x0c05a380u: goto P_0c05a380;
case 0x0c05a382u: goto P_0c05a382;
case 0x0c05a384u: goto P_0c05a384;
case 0x0c05a386u: goto P_0c05a386;
case 0x0c05a388u: goto P_0c05a388;
case 0x0c05a38au: goto P_0c05a38a;
case 0x0c05a38cu: goto P_0c05a38c;
case 0x0c05a38eu: goto P_0c05a38e;
case 0x0c05a390u: goto P_0c05a390;
case 0x0c05a392u: goto P_0c05a392;
case 0x0c05a394u: goto P_0c05a394;
case 0x0c05a396u: goto P_0c05a396;
case 0x0c05a398u: goto P_0c05a398;
case 0x0c05a39au: goto P_0c05a39a;
case 0x0c05a39cu: goto P_0c05a39c;
case 0x0c05a39eu: goto P_0c05a39e;
case 0x0c05a3a0u: goto P_0c05a3a0;
case 0x0c05a3a2u: goto P_0c05a3a2;
case 0x0c05a3a4u: goto P_0c05a3a4;
case 0x0c05a3a6u: goto P_0c05a3a6;
case 0x0c05a3a8u: goto P_0c05a3a8;
case 0x0c05a3aau: goto P_0c05a3aa;
case 0x0c05a3acu: goto P_0c05a3ac;
case 0x0c05a3aeu: goto P_0c05a3ae;
case 0x0c05a3b0u: goto P_0c05a3b0;
case 0x0c05a3b2u: goto P_0c05a3b2;
case 0x0c05a3b4u: goto P_0c05a3b4;
case 0x0c05a3b6u: goto P_0c05a3b6;
case 0x0c05a3b8u: goto P_0c05a3b8;
case 0x0c05a3bau: goto P_0c05a3ba;
case 0x0c05a3bcu: goto P_0c05a3bc;
case 0x0c05a3beu: goto P_0c05a3be;
case 0x0c05a3c0u: goto P_0c05a3c0;
case 0x0c05a3c2u: goto P_0c05a3c2;
case 0x0c05a3c4u: goto P_0c05a3c4;
case 0x0c05a3c6u: goto P_0c05a3c6;
case 0x0c05a3c8u: goto P_0c05a3c8;
case 0x0c05a3cau: goto P_0c05a3ca;
case 0x0c05a3ccu: goto P_0c05a3cc;
case 0x0c05a3ceu: goto P_0c05a3ce;
case 0x0c05a3d0u: goto P_0c05a3d0;
case 0x0c05a3d2u: goto P_0c05a3d2;
case 0x0c05a3d4u: goto P_0c05a3d4;
case 0x0c05a3d6u: goto P_0c05a3d6;
case 0x0c05a3d8u: goto P_0c05a3d8;
case 0x0c05a3dau: goto P_0c05a3da;
case 0x0c05a3dcu: goto P_0c05a3dc;
case 0x0c05a3deu: goto P_0c05a3de;
case 0x0c05a3e0u: goto P_0c05a3e0;
case 0x0c05a3e2u: goto P_0c05a3e2;
case 0x0c05a3e4u: goto P_0c05a3e4;
case 0x0c05a3e6u: goto P_0c05a3e6;
case 0x0c05a3e8u: goto P_0c05a3e8;
case 0x0c05a3eau: goto P_0c05a3ea;
case 0x0c05a3ecu: goto P_0c05a3ec;
case 0x0c05a3eeu: goto P_0c05a3ee;
case 0x0c05a3f0u: goto P_0c05a3f0;
case 0x0c05a3f2u: goto P_0c05a3f2;
case 0x0c05a3f4u: goto P_0c05a3f4;
case 0x0c05a3f6u: goto P_0c05a3f6;
case 0x0c05a3f8u: goto P_0c05a3f8;
case 0x0c05a3fau: goto P_0c05a3fa;
case 0x0c05a3fcu: goto P_0c05a3fc;
case 0x0c05a3feu: goto P_0c05a3fe;
case 0x0c05a400u: goto P_0c05a400;
case 0x0c05a402u: goto P_0c05a402;
case 0x0c05a404u: goto P_0c05a404;
case 0x0c05a406u: goto P_0c05a406;
case 0x0c05a408u: goto P_0c05a408;
case 0x0c05a40au: goto P_0c05a40a;
case 0x0c05a40cu: goto P_0c05a40c;
case 0x0c05a40eu: goto P_0c05a40e;
case 0x0c05a410u: goto P_0c05a410;
case 0x0c05a412u: goto P_0c05a412;
case 0x0c05a414u: goto P_0c05a414;
case 0x0c05a416u: goto P_0c05a416;
case 0x0c05a418u: goto P_0c05a418;
case 0x0c05a41au: goto P_0c05a41a;
case 0x0c05a41cu: goto P_0c05a41c;
case 0x0c05a41eu: goto P_0c05a41e;
case 0x0c05a420u: goto P_0c05a420;
case 0x0c05a422u: goto P_0c05a422;
case 0x0c05a424u: goto P_0c05a424;
case 0x0c05a426u: goto P_0c05a426;
case 0x0c05a428u: goto P_0c05a428;
case 0x0c05a42au: goto P_0c05a42a;
case 0x0c05a42cu: goto P_0c05a42c;
case 0x0c05a42eu: goto P_0c05a42e;
case 0x0c05a430u: goto P_0c05a430;
case 0x0c05a432u: goto P_0c05a432;
case 0x0c05a434u: goto P_0c05a434;
case 0x0c05a436u: goto P_0c05a436;
case 0x0c05a438u: goto P_0c05a438;
case 0x0c05a43au: goto P_0c05a43a;
case 0x0c05a43cu: goto P_0c05a43c;
case 0x0c05a43eu: goto P_0c05a43e;
case 0x0c05a440u: goto P_0c05a440;
case 0x0c05a442u: goto P_0c05a442;
case 0x0c05a444u: goto P_0c05a444;
case 0x0c05a446u: goto P_0c05a446;
case 0x0c05a448u: goto P_0c05a448;
case 0x0c05a44au: goto P_0c05a44a;
case 0x0c05a44cu: goto P_0c05a44c;
case 0x0c05a44eu: goto P_0c05a44e;
case 0x0c05a450u: goto P_0c05a450;
case 0x0c05a452u: goto P_0c05a452;
case 0x0c05a454u: goto P_0c05a454;
case 0x0c05a456u: goto P_0c05a456;
case 0x0c05a458u: goto P_0c05a458;
case 0x0c05a45au: goto P_0c05a45a;
case 0x0c05a45cu: goto P_0c05a45c;
case 0x0c05a45eu: goto P_0c05a45e;
case 0x0c05a460u: goto P_0c05a460;
case 0x0c05a462u: goto P_0c05a462;
case 0x0c05a464u: goto P_0c05a464;
case 0x0c05a466u: goto P_0c05a466;
case 0x0c05a468u: goto P_0c05a468;
case 0x0c05a46au: goto P_0c05a46a;
case 0x0c05a46cu: goto P_0c05a46c;
case 0x0c05a46eu: goto P_0c05a46e;
case 0x0c05a470u: goto P_0c05a470;
case 0x0c05a472u: goto P_0c05a472;
case 0x0c05a474u: goto P_0c05a474;
case 0x0c05a476u: goto P_0c05a476;
case 0x0c05a478u: goto P_0c05a478;
case 0x0c05a47au: goto P_0c05a47a;
case 0x0c05a47cu: goto P_0c05a47c;
case 0x0c05a47eu: goto P_0c05a47e;
case 0x0c05a480u: goto P_0c05a480;
case 0x0c05a482u: goto P_0c05a482;
case 0x0c05a484u: goto P_0c05a484;
case 0x0c05a486u: goto P_0c05a486;
case 0x0c05a488u: goto P_0c05a488;
case 0x0c05a48au: goto P_0c05a48a;
case 0x0c05a48cu: goto P_0c05a48c;
case 0x0c05a48eu: goto P_0c05a48e;
case 0x0c05a490u: goto P_0c05a490;
case 0x0c05a492u: goto P_0c05a492;
case 0x0c05a494u: goto P_0c05a494;
case 0x0c05a496u: goto P_0c05a496;
case 0x0c05a498u: goto P_0c05a498;
case 0x0c05a49au: goto P_0c05a49a;
case 0x0c05a49cu: goto P_0c05a49c;
case 0x0c05a49eu: goto P_0c05a49e;
case 0x0c05a4a0u: goto P_0c05a4a0;
case 0x0c05a4a2u: goto P_0c05a4a2;
case 0x0c05a4a4u: goto P_0c05a4a4;
case 0x0c05a4a6u: goto P_0c05a4a6;
case 0x0c05a4a8u: goto P_0c05a4a8;
case 0x0c05a4aau: goto P_0c05a4aa;
case 0x0c05a4acu: goto P_0c05a4ac;
case 0x0c05a4aeu: goto P_0c05a4ae;
case 0x0c05a4e4u: goto P_0c05a4e4;
case 0x0c05a4e6u: goto P_0c05a4e6;
case 0x0c05a4e8u: goto P_0c05a4e8;
case 0x0c05a4eau: goto P_0c05a4ea;
case 0x0c05a4ecu: goto P_0c05a4ec;
case 0x0c05a4eeu: goto P_0c05a4ee;
case 0x0c05a4f0u: goto P_0c05a4f0;
case 0x0c05a4f2u: goto P_0c05a4f2;
case 0x0c05a4f4u: goto P_0c05a4f4;
case 0x0c05a4f6u: goto P_0c05a4f6;
case 0x0c05a4f8u: goto P_0c05a4f8;
case 0x0c05a4fau: goto P_0c05a4fa;
case 0x0c05a4fcu: goto P_0c05a4fc;
case 0x0c05a4feu: goto P_0c05a4fe;
case 0x0c05a500u: goto P_0c05a500;
case 0x0c05a502u: goto P_0c05a502;
case 0x0c05a504u: goto P_0c05a504;
case 0x0c05a506u: goto P_0c05a506;
case 0x0c05a508u: goto P_0c05a508;
case 0x0c05a50au: goto P_0c05a50a;
case 0x0c05a50cu: goto P_0c05a50c;
case 0x0c05a50eu: goto P_0c05a50e;
case 0x0c05a510u: goto P_0c05a510;
case 0x0c05a512u: goto P_0c05a512;
case 0x0c05a514u: goto P_0c05a514;
case 0x0c05a516u: goto P_0c05a516;
default: return vf3_matrix_family(target,s,ram);
}
P_0c059d72: /* original d41b, guest PC 0x0c059d72 */
if(!s->budget--) { s->failed_pc=0x0c059d72u; return 0; }
r[4]=read(ram,0x0c059de0u,4);
goto P_0c059d74;
P_0c059d74: /* original 6042, guest PC 0x0c059d74 */
if(!s->budget--) { s->failed_pc=0x0c059d74u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c059d76;
P_0c059d76: /* original 7001, guest PC 0x0c059d76 */
if(!s->budget--) { s->failed_pc=0x0c059d76u; return 0; }
r[0]+=0x00000001u;
goto P_0c059d78;
P_0c059d78: /* original c901, guest PC 0x0c059d78 */
if(!s->budget--) { s->failed_pc=0x0c059d78u; return 0; }
r[0]&=1u;
goto P_0c059d7a;
P_0c059d7a: /* original 000b, guest PC 0x0c059d7a */
if(!s->budget--) { s->failed_pc=0x0c059d7au; return 0; }
target=r[16];
write(ram,r[4],r[0],4);
s->pc=target; return ram->oob==0;
P_0c059d7c: /* original 2402, guest PC 0x0c059d7c */
if(!s->budget--) { s->failed_pc=0x0c059d7cu; return 0; }
write(ram,r[4],r[0],4);
if(!vf3_matrix_family(0x0c059d7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c059d7eu; return 0; } return 1;
P_0c059f7c: /* original 2fe6, guest PC 0x0c059f7c */
if(!s->budget--) { s->failed_pc=0x0c059f7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f7e;
P_0c059f7e: /* original 2fd6, guest PC 0x0c059f7e */
if(!s->budget--) { s->failed_pc=0x0c059f7eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f80;
P_0c059f80: /* original 2fc6, guest PC 0x0c059f80 */
if(!s->budget--) { s->failed_pc=0x0c059f80u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f82;
P_0c059f82: /* original 2fb6, guest PC 0x0c059f82 */
if(!s->budget--) { s->failed_pc=0x0c059f82u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f84;
P_0c059f84: /* original 2fa6, guest PC 0x0c059f84 */
if(!s->budget--) { s->failed_pc=0x0c059f84u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f86;
P_0c059f86: /* original 2f96, guest PC 0x0c059f86 */
if(!s->budget--) { s->failed_pc=0x0c059f86u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f88;
P_0c059f88: /* original 2f86, guest PC 0x0c059f88 */
if(!s->budget--) { s->failed_pc=0x0c059f88u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c059f8a;
P_0c059f8a: /* original 4f22, guest PC 0x0c059f8a */
if(!s->budget--) { s->failed_pc=0x0c059f8au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c059f8c;
P_0c059f8c: /* original d284, guest PC 0x0c059f8c */
if(!s->budget--) { s->failed_pc=0x0c059f8cu; return 0; }
r[2]=read(ram,0x0c05a1a0u,4);
goto P_0c059f8e;
P_0c059f8e: /* original 7fa8, guest PC 0x0c059f8e */
if(!s->budget--) { s->failed_pc=0x0c059f8eu; return 0; }
r[15]+=0xffffffa8u;
goto P_0c059f90;
P_0c059f90: /* original d384, guest PC 0x0c059f90 */
if(!s->budget--) { s->failed_pc=0x0c059f90u; return 0; }
r[3]=read(ram,0x0c05a1a4u,4);
goto P_0c059f92;
P_0c059f92: /* original 61f3, guest PC 0x0c059f92 */
if(!s->budget--) { s->failed_pc=0x0c059f92u; return 0; }
r[1]=r[15];
goto P_0c059f94;
P_0c059f94: /* original 7110, guest PC 0x0c059f94 */
if(!s->budget--) { s->failed_pc=0x0c059f94u; return 0; }
r[1]+=0x00000010u;
goto P_0c059f96;
P_0c059f96: /* original 430b, guest PC 0x0c059f96 */
if(!s->budget--) { s->failed_pc=0x0c059f96u; return 0; }
target=r[3];
r[16]=code_base|0x0c059f9au;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059f9au) { target=s->pc; goto dispatch; }
goto P_0c059f9a;
P_0c059f98: /* original e020, guest PC 0x0c059f98 */
if(!s->budget--) { s->failed_pc=0x0c059f98u; return 0; }
r[0]=0x00000020u;
goto P_0c059f9a;
P_0c059f9a: /* original d183, guest PC 0x0c059f9a */
if(!s->budget--) { s->failed_pc=0x0c059f9au; return 0; }
r[1]=read(ram,0x0c05a1a8u,4);
goto P_0c059f9c;
P_0c059f9c: /* original 6012, guest PC 0x0c059f9c */
if(!s->budget--) { s->failed_pc=0x0c059f9cu; return 0; }
tmp=read(ram,r[1],4);
r[0]=tmp;
goto P_0c059f9e;
P_0c059f9e: /* original c840, guest PC 0x0c059f9e */
if(!s->budget--) { s->failed_pc=0x0c059f9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c059fa0;
P_0c059fa0: /* original 890d, guest PC 0x0c059fa0 */
if(!s->budget--) { s->failed_pc=0x0c059fa0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059fbe; }
goto P_0c059fa2;
P_0c059fa2: /* original d082, guest PC 0x0c059fa2 */
if(!s->budget--) { s->failed_pc=0x0c059fa2u; return 0; }
r[0]=read(ram,0x0c05a1acu,4);
goto P_0c059fa4;
P_0c059fa4: /* original 6302, guest PC 0x0c059fa4 */
if(!s->budget--) { s->failed_pc=0x0c059fa4u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c059fa6;
P_0c059fa6: /* original 2338, guest PC 0x0c059fa6 */
if(!s->budget--) { s->failed_pc=0x0c059fa6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059fa8;
P_0c059fa8: /* original 8909, guest PC 0x0c059fa8 */
if(!s->budget--) { s->failed_pc=0x0c059fa8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059fbe; }
goto P_0c059faa;
P_0c059faa: /* original d281, guest PC 0x0c059faa */
if(!s->budget--) { s->failed_pc=0x0c059faau; return 0; }
r[2]=read(ram,0x0c05a1b0u,4);
goto P_0c059fac;
P_0c059fac: /* original 6322, guest PC 0x0c059fac */
if(!s->budget--) { s->failed_pc=0x0c059facu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c059fae;
P_0c059fae: /* original 2338, guest PC 0x0c059fae */
if(!s->budget--) { s->failed_pc=0x0c059faeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059fb0;
P_0c059fb0: /* original 8905, guest PC 0x0c059fb0 */
if(!s->budget--) { s->failed_pc=0x0c059fb0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059fbe; }
goto P_0c059fb2;
P_0c059fb2: /* original d180, guest PC 0x0c059fb2 */
if(!s->budget--) { s->failed_pc=0x0c059fb2u; return 0; }
r[1]=read(ram,0x0c05a1b4u,4);
goto P_0c059fb4;
P_0c059fb4: /* original 6312, guest PC 0x0c059fb4 */
if(!s->budget--) { s->failed_pc=0x0c059fb4u; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c059fb6;
P_0c059fb6: /* original 2338, guest PC 0x0c059fb6 */
if(!s->budget--) { s->failed_pc=0x0c059fb6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c059fb8;
P_0c059fb8: /* original 8901, guest PC 0x0c059fb8 */
if(!s->budget--) { s->failed_pc=0x0c059fb8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c059fbe; }
goto P_0c059fba;
P_0c059fba: /* original bc41, guest PC 0x0c059fba */
if(!s->budget--) { s->failed_pc=0x0c059fbau; return 0; }
target=code_base|0x0c059840u; r[16]=code_base|0x0c059fbeu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c059fbeu) { target=s->pc; goto dispatch; }
goto P_0c059fbe;
P_0c059fbc: /* original 0009, guest PC 0x0c059fbc */
if(!s->budget--) { s->failed_pc=0x0c059fbcu; return 0; }
goto P_0c059fbe;
P_0c059fbe: /* original d27e, guest PC 0x0c059fbe */
if(!s->budget--) { s->failed_pc=0x0c059fbeu; return 0; }
r[2]=read(ram,0x0c05a1b8u,4);
goto P_0c059fc0;
P_0c059fc0: /* original 6d22, guest PC 0x0c059fc0 */
if(!s->budget--) { s->failed_pc=0x0c059fc0u; return 0; }
tmp=read(ram,r[2],4);
r[13]=tmp;
goto P_0c059fc2;
P_0c059fc2: /* original 63f3, guest PC 0x0c059fc2 */
if(!s->budget--) { s->failed_pc=0x0c059fc2u; return 0; }
r[3]=r[15];
goto P_0c059fc4;
P_0c059fc4: /* original d17d, guest PC 0x0c059fc4 */
if(!s->budget--) { s->failed_pc=0x0c059fc4u; return 0; }
r[1]=read(ram,0x0c05a1bcu,4);
goto P_0c059fc6;
P_0c059fc6: /* original 66f3, guest PC 0x0c059fc6 */
if(!s->budget--) { s->failed_pc=0x0c059fc6u; return 0; }
r[6]=r[15];
goto P_0c059fc8;
P_0c059fc8: /* original 7344, guest PC 0x0c059fc8 */
if(!s->budget--) { s->failed_pc=0x0c059fc8u; return 0; }
r[3]+=0x00000044u;
goto P_0c059fca;
P_0c059fca: /* original 4d08, guest PC 0x0c059fca */
if(!s->budget--) { s->failed_pc=0x0c059fcau; return 0; }
r[13]<<=2;
goto P_0c059fcc;
P_0c059fcc: /* original 1f32, guest PC 0x0c059fcc */
if(!s->budget--) { s->failed_pc=0x0c059fccu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c059fce;
P_0c059fce: /* original 7648, guest PC 0x0c059fce */
if(!s->budget--) { s->failed_pc=0x0c059fceu; return 0; }
r[6]+=0x00000048u;
goto P_0c059fd0;
P_0c059fd0: /* original 31dc, guest PC 0x0c059fd0 */
if(!s->budget--) { s->failed_pc=0x0c059fd0u; return 0; }
r[1]+=r[13];
goto P_0c059fd2;
P_0c059fd2: /* original 65f3, guest PC 0x0c059fd2 */
if(!s->budget--) { s->failed_pc=0x0c059fd2u; return 0; }
r[5]=r[15];
goto P_0c059fd4;
P_0c059fd4: /* original 2312, guest PC 0x0c059fd4 */
if(!s->budget--) { s->failed_pc=0x0c059fd4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c059fd6;
P_0c059fd6: /* original 67f3, guest PC 0x0c059fd6 */
if(!s->budget--) { s->failed_pc=0x0c059fd6u; return 0; }
r[7]=r[15];
goto P_0c059fd8;
P_0c059fd8: /* original d379, guest PC 0x0c059fd8 */
if(!s->budget--) { s->failed_pc=0x0c059fd8u; return 0; }
r[3]=read(ram,0x0c05a1c0u,4);
goto P_0c059fda;
P_0c059fda: /* original 61f3, guest PC 0x0c059fda */
if(!s->budget--) { s->failed_pc=0x0c059fdau; return 0; }
r[1]=r[15];
goto P_0c059fdc;
P_0c059fdc: /* original 33dc, guest PC 0x0c059fdc */
if(!s->budget--) { s->failed_pc=0x0c059fdcu; return 0; }
r[3]+=r[13];
goto P_0c059fde;
P_0c059fde: /* original 714c, guest PC 0x0c059fde */
if(!s->budget--) { s->failed_pc=0x0c059fdeu; return 0; }
r[1]+=0x0000004cu;
goto P_0c059fe0;
P_0c059fe0: /* original 2632, guest PC 0x0c059fe0 */
if(!s->budget--) { s->failed_pc=0x0c059fe0u; return 0; }
write(ram,r[6],r[3],4);
goto P_0c059fe2;
P_0c059fe2: /* original 7550, guest PC 0x0c059fe2 */
if(!s->budget--) { s->failed_pc=0x0c059fe2u; return 0; }
r[5]+=0x00000050u;
goto P_0c059fe4;
P_0c059fe4: /* original 2f12, guest PC 0x0c059fe4 */
if(!s->budget--) { s->failed_pc=0x0c059fe4u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c059fe6;
P_0c059fe6: /* original 7754, guest PC 0x0c059fe6 */
if(!s->budget--) { s->failed_pc=0x0c059fe6u; return 0; }
r[7]+=0x00000054u;
goto P_0c059fe8;
P_0c059fe8: /* original d376, guest PC 0x0c059fe8 */
if(!s->budget--) { s->failed_pc=0x0c059fe8u; return 0; }
r[3]=read(ram,0x0c05a1c4u,4);
goto P_0c059fea;
P_0c059fea: /* original 6ef3, guest PC 0x0c059fea */
if(!s->budget--) { s->failed_pc=0x0c059feau; return 0; }
r[14]=r[15];
goto P_0c059fec;
P_0c059fec: /* original 33dc, guest PC 0x0c059fec */
if(!s->budget--) { s->failed_pc=0x0c059fecu; return 0; }
r[3]+=r[13];
goto P_0c059fee;
P_0c059fee: /* original 2132, guest PC 0x0c059fee */
if(!s->budget--) { s->failed_pc=0x0c059feeu; return 0; }
write(ram,r[1],r[3],4);
goto P_0c059ff0;
P_0c059ff0: /* original d175, guest PC 0x0c059ff0 */
if(!s->budget--) { s->failed_pc=0x0c059ff0u; return 0; }
r[1]=read(ram,0x0c05a1c8u,4);
goto P_0c059ff2;
P_0c059ff2: /* original 31dc, guest PC 0x0c059ff2 */
if(!s->budget--) { s->failed_pc=0x0c059ff2u; return 0; }
r[1]+=r[13];
goto P_0c059ff4;
P_0c059ff4: /* original 2512, guest PC 0x0c059ff4 */
if(!s->budget--) { s->failed_pc=0x0c059ff4u; return 0; }
write(ram,r[5],r[1],4);
goto P_0c059ff6;
P_0c059ff6: /* original d375, guest PC 0x0c059ff6 */
if(!s->budget--) { s->failed_pc=0x0c059ff6u; return 0; }
r[3]=read(ram,0x0c05a1ccu,4);
goto P_0c059ff8;
P_0c059ff8: /* original 33dc, guest PC 0x0c059ff8 */
if(!s->budget--) { s->failed_pc=0x0c059ff8u; return 0; }
r[3]+=r[13];
goto P_0c059ffa;
P_0c059ffa: /* original 2732, guest PC 0x0c059ffa */
if(!s->budget--) { s->failed_pc=0x0c059ffau; return 0; }
write(ram,r[7],r[3],4);
goto P_0c059ffc;
P_0c059ffc: /* original d174, guest PC 0x0c059ffc */
if(!s->budget--) { s->failed_pc=0x0c059ffcu; return 0; }
r[1]=read(ram,0x0c05a1d0u,4);
goto P_0c059ffe;
P_0c059ffe: /* original 7e30, guest PC 0x0c059ffe */
if(!s->budget--) { s->failed_pc=0x0c059ffeu; return 0; }
r[14]+=0x00000030u;
goto P_0c05a000;
P_0c05a000: /* original d374, guest PC 0x0c05a000 */
if(!s->budget--) { s->failed_pc=0x0c05a000u; return 0; }
r[3]=read(ram,0x0c05a1d4u,4);
goto P_0c05a002;
P_0c05a002: /* original 31dc, guest PC 0x0c05a002 */
if(!s->budget--) { s->failed_pc=0x0c05a002u; return 0; }
r[1]+=r[13];
goto P_0c05a004;
P_0c05a004: /* original d477, guest PC 0x0c05a004 */
if(!s->budget--) { s->failed_pc=0x0c05a004u; return 0; }
r[4]=read(ram,0x0c05a1e4u,4);
goto P_0c05a006;
P_0c05a006: /* original 33dc, guest PC 0x0c05a006 */
if(!s->budget--) { s->failed_pc=0x0c05a006u; return 0; }
r[3]+=r[13];
goto P_0c05a008;
P_0c05a008: /* original 2e12, guest PC 0x0c05a008 */
if(!s->budget--) { s->failed_pc=0x0c05a008u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c05a00a;
P_0c05a00a: /* original 1e31, guest PC 0x0c05a00a */
if(!s->budget--) { s->failed_pc=0x0c05a00au; return 0; }
write(ram,r[14]+4,r[3],4);
goto P_0c05a00c;
P_0c05a00c: /* original d172, guest PC 0x0c05a00c */
if(!s->budget--) { s->failed_pc=0x0c05a00cu; return 0; }
r[1]=read(ram,0x0c05a1d8u,4);
goto P_0c05a00e;
P_0c05a00e: /* original 31dc, guest PC 0x0c05a00e */
if(!s->budget--) { s->failed_pc=0x0c05a00eu; return 0; }
r[1]+=r[13];
goto P_0c05a010;
P_0c05a010: /* original 1e12, guest PC 0x0c05a010 */
if(!s->budget--) { s->failed_pc=0x0c05a010u; return 0; }
write(ram,r[14]+8,r[1],4);
goto P_0c05a012;
P_0c05a012: /* original d372, guest PC 0x0c05a012 */
if(!s->budget--) { s->failed_pc=0x0c05a012u; return 0; }
r[3]=read(ram,0x0c05a1dcu,4);
goto P_0c05a014;
P_0c05a014: /* original d172, guest PC 0x0c05a014 */
if(!s->budget--) { s->failed_pc=0x0c05a014u; return 0; }
r[1]=read(ram,0x0c05a1e0u,4);
goto P_0c05a016;
P_0c05a016: /* original 33dc, guest PC 0x0c05a016 */
if(!s->budget--) { s->failed_pc=0x0c05a016u; return 0; }
r[3]+=r[13];
goto P_0c05a018;
P_0c05a018: /* original 1e33, guest PC 0x0c05a018 */
if(!s->budget--) { s->failed_pc=0x0c05a018u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c05a01a;
P_0c05a01a: /* original 3d1c, guest PC 0x0c05a01a */
if(!s->budget--) { s->failed_pc=0x0c05a01au; return 0; }
r[13]+=r[1];
goto P_0c05a01c;
P_0c05a01c: /* original 1ed4, guest PC 0x0c05a01c */
if(!s->budget--) { s->failed_pc=0x0c05a01cu; return 0; }
write(ram,r[14]+16,r[13],4);
goto P_0c05a01e;
P_0c05a01e: /* original 53f2, guest PC 0x0c05a01e */
if(!s->budget--) { s->failed_pc=0x0c05a01eu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05a020;
P_0c05a020: /* original 6042, guest PC 0x0c05a020 */
if(!s->budget--) { s->failed_pc=0x0c05a020u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c05a022;
P_0c05a022: /* original 6332, guest PC 0x0c05a022 */
if(!s->budget--) { s->failed_pc=0x0c05a022u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a024;
P_0c05a024: /* original 6002, guest PC 0x0c05a024 */
if(!s->budget--) { s->failed_pc=0x0c05a024u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c05a026;
P_0c05a026: /* original 2302, guest PC 0x0c05a026 */
if(!s->budget--) { s->failed_pc=0x0c05a026u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a028;
P_0c05a028: /* original 6362, guest PC 0x0c05a028 */
if(!s->budget--) { s->failed_pc=0x0c05a028u; return 0; }
tmp=read(ram,r[6],4);
r[3]=tmp;
goto P_0c05a02a;
P_0c05a02a: /* original 6042, guest PC 0x0c05a02a */
if(!s->budget--) { s->failed_pc=0x0c05a02au; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c05a02c;
P_0c05a02c: /* original 5001, guest PC 0x0c05a02c */
if(!s->budget--) { s->failed_pc=0x0c05a02cu; return 0; }
r[0]=read(ram,r[0]+4,4);
goto P_0c05a02e;
P_0c05a02e: /* original 2302, guest PC 0x0c05a02e */
if(!s->budget--) { s->failed_pc=0x0c05a02eu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a030;
P_0c05a030: /* original 63f2, guest PC 0x0c05a030 */
if(!s->budget--) { s->failed_pc=0x0c05a030u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05a032;
P_0c05a032: /* original 6332, guest PC 0x0c05a032 */
if(!s->budget--) { s->failed_pc=0x0c05a032u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a034;
P_0c05a034: /* original 6042, guest PC 0x0c05a034 */
if(!s->budget--) { s->failed_pc=0x0c05a034u; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c05a036;
P_0c05a036: /* original 5002, guest PC 0x0c05a036 */
if(!s->budget--) { s->failed_pc=0x0c05a036u; return 0; }
r[0]=read(ram,r[0]+8,4);
goto P_0c05a038;
P_0c05a038: /* original 2302, guest PC 0x0c05a038 */
if(!s->budget--) { s->failed_pc=0x0c05a038u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a03a;
P_0c05a03a: /* original 6352, guest PC 0x0c05a03a */
if(!s->budget--) { s->failed_pc=0x0c05a03au; return 0; }
tmp=read(ram,r[5],4);
r[3]=tmp;
goto P_0c05a03c;
P_0c05a03c: /* original 6042, guest PC 0x0c05a03c */
if(!s->budget--) { s->failed_pc=0x0c05a03cu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c05a03e;
P_0c05a03e: /* original e900, guest PC 0x0c05a03e */
if(!s->budget--) { s->failed_pc=0x0c05a03eu; return 0; }
r[9]=0x00000000u;
goto P_0c05a040;
P_0c05a040: /* original da6a, guest PC 0x0c05a040 */
if(!s->budget--) { s->failed_pc=0x0c05a040u; return 0; }
r[10]=read(ram,0x0c05a1ecu,4);
goto P_0c05a042;
P_0c05a042: /* original eb01, guest PC 0x0c05a042 */
if(!s->budget--) { s->failed_pc=0x0c05a042u; return 0; }
r[11]=0x00000001u;
goto P_0c05a044;
P_0c05a044: /* original dd6a, guest PC 0x0c05a044 */
if(!s->budget--) { s->failed_pc=0x0c05a044u; return 0; }
r[13]=read(ram,0x0c05a1f0u,4);
goto P_0c05a046;
P_0c05a046: /* original 5003, guest PC 0x0c05a046 */
if(!s->budget--) { s->failed_pc=0x0c05a046u; return 0; }
r[0]=read(ram,r[0]+12,4);
goto P_0c05a048;
P_0c05a048: /* original d867, guest PC 0x0c05a048 */
if(!s->budget--) { s->failed_pc=0x0c05a048u; return 0; }
r[8]=read(ram,0x0c05a1e8u,4);
goto P_0c05a04a;
P_0c05a04a: /* original 2302, guest PC 0x0c05a04a */
if(!s->budget--) { s->failed_pc=0x0c05a04au; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a04c;
P_0c05a04c: /* original 6372, guest PC 0x0c05a04c */
if(!s->budget--) { s->failed_pc=0x0c05a04cu; return 0; }
tmp=read(ram,r[7],4);
r[3]=tmp;
goto P_0c05a04e;
P_0c05a04e: /* original 6042, guest PC 0x0c05a04e */
if(!s->budget--) { s->failed_pc=0x0c05a04eu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c05a050;
P_0c05a050: /* original 5004, guest PC 0x0c05a050 */
if(!s->budget--) { s->failed_pc=0x0c05a050u; return 0; }
r[0]=read(ram,r[0]+16,4);
goto P_0c05a052;
P_0c05a052: /* original 2302, guest PC 0x0c05a052 */
if(!s->budget--) { s->failed_pc=0x0c05a052u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a054;
P_0c05a054: /* original d067, guest PC 0x0c05a054 */
if(!s->budget--) { s->failed_pc=0x0c05a054u; return 0; }
r[0]=read(ram,0x0c05a1f4u,4);
goto P_0c05a056;
P_0c05a056: /* original 6302, guest PC 0x0c05a056 */
if(!s->budget--) { s->failed_pc=0x0c05a056u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c05a058;
P_0c05a058: /* original 2338, guest PC 0x0c05a058 */
if(!s->budget--) { s->failed_pc=0x0c05a058u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c05a05a;
P_0c05a05a: /* original 8d02, guest PC 0x0c05a05a */
if(!s->budget--) { s->failed_pc=0x0c05a05au; return 0; }
cond=r[17]&1u;
r[12]=0x00000005u;
if(cond) { goto P_0c05a062; }
goto P_0c05a05e;
P_0c05a05c: /* original ec05, guest PC 0x0c05a05c */
if(!s->budget--) { s->failed_pc=0x0c05a05cu; return 0; }
r[12]=0x00000005u;
goto P_0c05a05e;
P_0c05a05e: /* original a0d5, guest PC 0x0c05a05e */
if(!s->budget--) { s->failed_pc=0x0c05a05eu; return 0; }
goto P_0c05a20c;
P_0c05a060: /* original 0009, guest PC 0x0c05a060 */
if(!s->budget--) { s->failed_pc=0x0c05a060u; return 0; }
goto P_0c05a062;
P_0c05a062: /* original e300, guest PC 0x0c05a062 */
if(!s->budget--) { s->failed_pc=0x0c05a062u; return 0; }
r[3]=0x00000000u;
goto P_0c05a064;
P_0c05a064: /* original 1f32, guest PC 0x0c05a064 */
if(!s->budget--) { s->failed_pc=0x0c05a064u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05a066;
P_0c05a066: /* original 62b3, guest PC 0x0c05a066 */
if(!s->budget--) { s->failed_pc=0x0c05a066u; return 0; }
r[2]=r[11];
goto P_0c05a068;
P_0c05a068: /* original d063, guest PC 0x0c05a068 */
if(!s->budget--) { s->failed_pc=0x0c05a068u; return 0; }
r[0]=read(ram,0x0c05a1f8u,4);
goto P_0c05a06a;
P_0c05a06a: /* original 53f2, guest PC 0x0c05a06a */
if(!s->budget--) { s->failed_pc=0x0c05a06au; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05a06c;
P_0c05a06c: /* original 423c, guest PC 0x0c05a06c */
if(!s->budget--) { s->failed_pc=0x0c05a06cu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c05a06e;
P_0c05a06e: /* original 6102, guest PC 0x0c05a06e */
if(!s->budget--) { s->failed_pc=0x0c05a06eu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05a070;
P_0c05a070: /* original 2218, guest PC 0x0c05a070 */
if(!s->budget--) { s->failed_pc=0x0c05a070u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[1])==0)!=0);
goto P_0c05a072;
P_0c05a072: /* original 891c, guest PC 0x0c05a072 */
if(!s->budget--) { s->failed_pc=0x0c05a072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a0ae; }
goto P_0c05a074;
P_0c05a074: /* original 6033, guest PC 0x0c05a074 */
if(!s->budget--) { s->failed_pc=0x0c05a074u; return 0; }
r[0]=r[3];
goto P_0c05a076;
P_0c05a076: /* original 0009, guest PC 0x0c05a076 */
if(!s->budget--) { s->failed_pc=0x0c05a076u; return 0; }
goto P_0c05a078;
P_0c05a078: /* original 4008, guest PC 0x0c05a078 */
if(!s->budget--) { s->failed_pc=0x0c05a078u; return 0; }
r[0]<<=2;
goto P_0c05a07a;
P_0c05a07a: /* original 2f02, guest PC 0x0c05a07a */
if(!s->budget--) { s->failed_pc=0x0c05a07au; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05a07c;
P_0c05a07c: /* original 02ee, guest PC 0x0c05a07c */
if(!s->budget--) { s->failed_pc=0x0c05a07cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05a07e;
P_0c05a07e: /* original 61a2, guest PC 0x0c05a07e */
if(!s->budget--) { s->failed_pc=0x0c05a07eu; return 0; }
tmp=read(ram,r[10],4);
r[1]=tmp;
goto P_0c05a080;
P_0c05a080: /* original 63f2, guest PC 0x0c05a080 */
if(!s->budget--) { s->failed_pc=0x0c05a080u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05a082;
P_0c05a082: /* original 011e, guest PC 0x0c05a082 */
if(!s->budget--) { s->failed_pc=0x0c05a082u; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c05a084;
P_0c05a084: /* original 60f3, guest PC 0x0c05a084 */
if(!s->budget--) { s->failed_pc=0x0c05a084u; return 0; }
r[0]=r[15];
goto P_0c05a086;
P_0c05a086: /* original 7044, guest PC 0x0c05a086 */
if(!s->budget--) { s->failed_pc=0x0c05a086u; return 0; }
r[0]+=0x00000044u;
goto P_0c05a088;
P_0c05a088: /* original 033e, guest PC 0x0c05a088 */
if(!s->budget--) { s->failed_pc=0x0c05a088u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c05a08a;
P_0c05a08a: /* original 6032, guest PC 0x0c05a08a */
if(!s->budget--) { s->failed_pc=0x0c05a08au; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05a08c;
P_0c05a08c: /* original d35b, guest PC 0x0c05a08c */
if(!s->budget--) { s->failed_pc=0x0c05a08cu; return 0; }
r[3]=read(ram,0x0c05a1fcu,4);
goto P_0c05a08e;
P_0c05a08e: /* original 3108, guest PC 0x0c05a08e */
if(!s->budget--) { s->failed_pc=0x0c05a08eu; return 0; }
r[1]-=r[0];
goto P_0c05a090;
P_0c05a090: /* original 430b, guest PC 0x0c05a090 */
if(!s->budget--) { s->failed_pc=0x0c05a090u; return 0; }
target=r[3];
r[16]=code_base|0x0c05a094u;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a094u) { target=s->pc; goto dispatch; }
goto P_0c05a094;
P_0c05a092: /* original e004, guest PC 0x0c05a092 */
if(!s->budget--) { s->failed_pc=0x0c05a092u; return 0; }
r[0]=0x00000004u;
goto P_0c05a094;
P_0c05a094: /* original d55a, guest PC 0x0c05a094 */
if(!s->budget--) { s->failed_pc=0x0c05a094u; return 0; }
r[5]=read(ram,0x0c05a200u,4);
goto P_0c05a096;
P_0c05a096: /* original 4008, guest PC 0x0c05a096 */
if(!s->budget--) { s->failed_pc=0x0c05a096u; return 0; }
r[0]<<=2;
goto P_0c05a098;
P_0c05a098: /* original 2202, guest PC 0x0c05a098 */
if(!s->budget--) { s->failed_pc=0x0c05a098u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c05a09a;
P_0c05a09a: /* original e604, guest PC 0x0c05a09a */
if(!s->budget--) { s->failed_pc=0x0c05a09au; return 0; }
r[6]=0x00000004u;
goto P_0c05a09c;
P_0c05a09c: /* original 62a2, guest PC 0x0c05a09c */
if(!s->budget--) { s->failed_pc=0x0c05a09cu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c05a09e;
P_0c05a09e: /* original 60f2, guest PC 0x0c05a09e */
if(!s->budget--) { s->failed_pc=0x0c05a09eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a0a0;
P_0c05a0a0: /* original 4d0b, guest PC 0x0c05a0a0 */
if(!s->budget--) { s->failed_pc=0x0c05a0a0u; return 0; }
target=r[13];
r[16]=code_base|0x0c05a0a4u;
r[4]=read(ram,r[2]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a0a4u) { target=s->pc; goto dispatch; }
goto P_0c05a0a4;
P_0c05a0a2: /* original 042e, guest PC 0x0c05a0a2 */
if(!s->budget--) { s->failed_pc=0x0c05a0a2u; return 0; }
r[4]=read(ram,r[2]+r[0],4);
goto P_0c05a0a4;
P_0c05a0a4: /* original 63a2, guest PC 0x0c05a0a4 */
if(!s->budget--) { s->failed_pc=0x0c05a0a4u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c05a0a6;
P_0c05a0a6: /* original 60f2, guest PC 0x0c05a0a6 */
if(!s->budget--) { s->failed_pc=0x0c05a0a6u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a0a8;
P_0c05a0a8: /* original 023e, guest PC 0x0c05a0a8 */
if(!s->budget--) { s->failed_pc=0x0c05a0a8u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05a0aa;
P_0c05a0aa: /* original 7220, guest PC 0x0c05a0aa */
if(!s->budget--) { s->failed_pc=0x0c05a0aau; return 0; }
r[2]+=0x00000020u;
goto P_0c05a0ac;
P_0c05a0ac: /* original 0326, guest PC 0x0c05a0ac */
if(!s->budget--) { s->failed_pc=0x0c05a0acu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05a0ae;
P_0c05a0ae: /* original 53f2, guest PC 0x0c05a0ae */
if(!s->budget--) { s->failed_pc=0x0c05a0aeu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05a0b0;
P_0c05a0b0: /* original 7301, guest PC 0x0c05a0b0 */
if(!s->budget--) { s->failed_pc=0x0c05a0b0u; return 0; }
r[3]+=0x00000001u;
goto P_0c05a0b2;
P_0c05a0b2: /* original 33c3, guest PC 0x0c05a0b2 */
if(!s->budget--) { s->failed_pc=0x0c05a0b2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c05a0b4;
P_0c05a0b4: /* original 8fd7, guest PC 0x0c05a0b4 */
if(!s->budget--) { s->failed_pc=0x0c05a0b4u; return 0; }
cond=r[17]&1u;
write(ram,r[15]+8,r[3],4);
if(!cond) { goto P_0c05a066; }
goto P_0c05a0b8;
P_0c05a0b6: /* original 1f32, guest PC 0x0c05a0b6 */
if(!s->budget--) { s->failed_pc=0x0c05a0b6u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05a0b8;
P_0c05a0b8: /* original e400, guest PC 0x0c05a0b8 */
if(!s->budget--) { s->failed_pc=0x0c05a0b8u; return 0; }
r[4]=0x00000000u;
goto P_0c05a0ba;
P_0c05a0ba: /* original 63b3, guest PC 0x0c05a0ba */
if(!s->budget--) { s->failed_pc=0x0c05a0bau; return 0; }
r[3]=r[11];
goto P_0c05a0bc;
P_0c05a0bc: /* original d14e, guest PC 0x0c05a0bc */
if(!s->budget--) { s->failed_pc=0x0c05a0bcu; return 0; }
r[1]=read(ram,0x0c05a1f8u,4);
goto P_0c05a0be;
P_0c05a0be: /* original 434c, guest PC 0x0c05a0be */
if(!s->budget--) { s->failed_pc=0x0c05a0beu; return 0; }
r[3]=(r[4]&0x80000000u)?((r[4]&31u)?(uint32_t)((int32_t)r[3]>>((-r[4])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[4]&31u);
goto P_0c05a0c0;
P_0c05a0c0: /* original 6212, guest PC 0x0c05a0c0 */
if(!s->budget--) { s->failed_pc=0x0c05a0c0u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05a0c2;
P_0c05a0c2: /* original 2328, guest PC 0x0c05a0c2 */
if(!s->budget--) { s->failed_pc=0x0c05a0c2u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[2])==0)!=0);
goto P_0c05a0c4;
P_0c05a0c4: /* original 8b04, guest PC 0x0c05a0c4 */
if(!s->budget--) { s->failed_pc=0x0c05a0c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a0d0; }
goto P_0c05a0c6;
P_0c05a0c6: /* original 6043, guest PC 0x0c05a0c6 */
if(!s->budget--) { s->failed_pc=0x0c05a0c6u; return 0; }
r[0]=r[4];
goto P_0c05a0c8;
P_0c05a0c8: /* original 0009, guest PC 0x0c05a0c8 */
if(!s->budget--) { s->failed_pc=0x0c05a0c8u; return 0; }
goto P_0c05a0ca;
P_0c05a0ca: /* original 4008, guest PC 0x0c05a0ca */
if(!s->budget--) { s->failed_pc=0x0c05a0cau; return 0; }
r[0]<<=2;
goto P_0c05a0cc;
P_0c05a0cc: /* original 03ee, guest PC 0x0c05a0cc */
if(!s->budget--) { s->failed_pc=0x0c05a0ccu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a0ce;
P_0c05a0ce: /* original 2392, guest PC 0x0c05a0ce */
if(!s->budget--) { s->failed_pc=0x0c05a0ceu; return 0; }
write(ram,r[3],r[9],4);
goto P_0c05a0d0;
P_0c05a0d0: /* original 7401, guest PC 0x0c05a0d0 */
if(!s->budget--) { s->failed_pc=0x0c05a0d0u; return 0; }
r[4]+=0x00000001u;
goto P_0c05a0d2;
P_0c05a0d2: /* original 34c3, guest PC 0x0c05a0d2 */
if(!s->budget--) { s->failed_pc=0x0c05a0d2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c05a0d4;
P_0c05a0d4: /* original 8bf1, guest PC 0x0c05a0d4 */
if(!s->budget--) { s->failed_pc=0x0c05a0d4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a0ba; }
goto P_0c05a0d6;
P_0c05a0d6: /* original e400, guest PC 0x0c05a0d6 */
if(!s->budget--) { s->failed_pc=0x0c05a0d6u; return 0; }
r[4]=0x00000000u;
goto P_0c05a0d8;
P_0c05a0d8: /* original 63f3, guest PC 0x0c05a0d8 */
if(!s->budget--) { s->failed_pc=0x0c05a0d8u; return 0; }
r[3]=r[15];
goto P_0c05a0da;
P_0c05a0da: /* original 7310, guest PC 0x0c05a0da */
if(!s->budget--) { s->failed_pc=0x0c05a0dau; return 0; }
r[3]+=0x00000010u;
goto P_0c05a0dc;
P_0c05a0dc: /* original a052, guest PC 0x0c05a0dc */
if(!s->budget--) { s->failed_pc=0x0c05a0dcu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05a184;
P_0c05a0de: /* original 2f32, guest PC 0x0c05a0de */
if(!s->budget--) { s->failed_pc=0x0c05a0deu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05a0e0;
P_0c05a0e0: /* original d245, guest PC 0x0c05a0e0 */
if(!s->budget--) { s->failed_pc=0x0c05a0e0u; return 0; }
r[2]=read(ram,0x0c05a1f8u,4);
goto P_0c05a0e2;
P_0c05a0e2: /* original 61b3, guest PC 0x0c05a0e2 */
if(!s->budget--) { s->failed_pc=0x0c05a0e2u; return 0; }
r[1]=r[11];
goto P_0c05a0e4;
P_0c05a0e4: /* original 414c, guest PC 0x0c05a0e4 */
if(!s->budget--) { s->failed_pc=0x0c05a0e4u; return 0; }
r[1]=(r[4]&0x80000000u)?((r[4]&31u)?(uint32_t)((int32_t)r[1]>>((-r[4])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[4]&31u);
goto P_0c05a0e6;
P_0c05a0e6: /* original 6322, guest PC 0x0c05a0e6 */
if(!s->budget--) { s->failed_pc=0x0c05a0e6u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05a0e8;
P_0c05a0e8: /* original 2138, guest PC 0x0c05a0e8 */
if(!s->budget--) { s->failed_pc=0x0c05a0e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c05a0ea;
P_0c05a0ea: /* original 894a, guest PC 0x0c05a0ea */
if(!s->budget--) { s->failed_pc=0x0c05a0eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a182; }
goto P_0c05a0ec;
P_0c05a0ec: /* original 6543, guest PC 0x0c05a0ec */
if(!s->budget--) { s->failed_pc=0x0c05a0ecu; return 0; }
r[5]=r[4];
goto P_0c05a0ee;
P_0c05a0ee: /* original 4508, guest PC 0x0c05a0ee */
if(!s->budget--) { s->failed_pc=0x0c05a0eeu; return 0; }
r[5]<<=2;
goto P_0c05a0f0;
P_0c05a0f0: /* original 6053, guest PC 0x0c05a0f0 */
if(!s->budget--) { s->failed_pc=0x0c05a0f0u; return 0; }
r[0]=r[5];
goto P_0c05a0f2;
P_0c05a0f2: /* original 0009, guest PC 0x0c05a0f2 */
if(!s->budget--) { s->failed_pc=0x0c05a0f2u; return 0; }
goto P_0c05a0f4;
P_0c05a0f4: /* original 03ee, guest PC 0x0c05a0f4 */
if(!s->budget--) { s->failed_pc=0x0c05a0f4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a0f6;
P_0c05a0f6: /* original d143, guest PC 0x0c05a0f6 */
if(!s->budget--) { s->failed_pc=0x0c05a0f6u; return 0; }
r[1]=read(ram,0x0c05a204u,4);
goto P_0c05a0f8;
P_0c05a0f8: /* original 6332, guest PC 0x0c05a0f8 */
if(!s->budget--) { s->failed_pc=0x0c05a0f8u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a0fa;
P_0c05a0fa: /* original 011e, guest PC 0x0c05a0fa */
if(!s->budget--) { s->failed_pc=0x0c05a0fau; return 0; }
r[1]=read(ram,r[1]+r[0],4);
goto P_0c05a0fc;
P_0c05a0fc: /* original 3316, guest PC 0x0c05a0fc */
if(!s->budget--) { s->failed_pc=0x0c05a0fcu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c05a0fe;
P_0c05a0fe: /* original 8b08, guest PC 0x0c05a0fe */
if(!s->budget--) { s->failed_pc=0x0c05a0feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a112; }
goto P_0c05a100;
P_0c05a100: /* original d140, guest PC 0x0c05a100 */
if(!s->budget--) { s->failed_pc=0x0c05a100u; return 0; }
r[1]=read(ram,0x0c05a204u,4);
goto P_0c05a102;
P_0c05a102: /* original 6543, guest PC 0x0c05a102 */
if(!s->budget--) { s->failed_pc=0x0c05a102u; return 0; }
r[5]=r[4];
goto P_0c05a104;
P_0c05a104: /* original 4508, guest PC 0x0c05a104 */
if(!s->budget--) { s->failed_pc=0x0c05a104u; return 0; }
r[5]<<=2;
goto P_0c05a106;
P_0c05a106: /* original 315c, guest PC 0x0c05a106 */
if(!s->budget--) { s->failed_pc=0x0c05a106u; return 0; }
r[1]+=r[5];
goto P_0c05a108;
P_0c05a108: /* original 6053, guest PC 0x0c05a108 */
if(!s->budget--) { s->failed_pc=0x0c05a108u; return 0; }
r[0]=r[5];
goto P_0c05a10a;
P_0c05a10a: /* original 0009, guest PC 0x0c05a10a */
if(!s->budget--) { s->failed_pc=0x0c05a10au; return 0; }
goto P_0c05a10c;
P_0c05a10c: /* original 03ee, guest PC 0x0c05a10c */
if(!s->budget--) { s->failed_pc=0x0c05a10cu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a10e;
P_0c05a10e: /* original 6332, guest PC 0x0c05a10e */
if(!s->budget--) { s->failed_pc=0x0c05a10eu; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a110;
P_0c05a110: /* original 2132, guest PC 0x0c05a110 */
if(!s->budget--) { s->failed_pc=0x0c05a110u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c05a112;
P_0c05a112: /* original 6543, guest PC 0x0c05a112 */
if(!s->budget--) { s->failed_pc=0x0c05a112u; return 0; }
r[5]=r[4];
goto P_0c05a114;
P_0c05a114: /* original 4508, guest PC 0x0c05a114 */
if(!s->budget--) { s->failed_pc=0x0c05a114u; return 0; }
r[5]<<=2;
goto P_0c05a116;
P_0c05a116: /* original 6053, guest PC 0x0c05a116 */
if(!s->budget--) { s->failed_pc=0x0c05a116u; return 0; }
r[0]=r[5];
goto P_0c05a118;
P_0c05a118: /* original 0009, guest PC 0x0c05a118 */
if(!s->budget--) { s->failed_pc=0x0c05a118u; return 0; }
goto P_0c05a11a;
P_0c05a11a: /* original 03ee, guest PC 0x0c05a11a */
if(!s->budget--) { s->failed_pc=0x0c05a11au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a11c;
P_0c05a11c: /* original d23a, guest PC 0x0c05a11c */
if(!s->budget--) { s->failed_pc=0x0c05a11cu; return 0; }
r[2]=read(ram,0x0c05a208u,4);
goto P_0c05a11e;
P_0c05a11e: /* original 022e, guest PC 0x0c05a11e */
if(!s->budget--) { s->failed_pc=0x0c05a11eu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c05a120;
P_0c05a120: /* original 6332, guest PC 0x0c05a120 */
if(!s->budget--) { s->failed_pc=0x0c05a120u; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a122;
P_0c05a122: /* original 3326, guest PC 0x0c05a122 */
if(!s->budget--) { s->failed_pc=0x0c05a122u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c05a124;
P_0c05a124: /* original 8b2d, guest PC 0x0c05a124 */
if(!s->budget--) { s->failed_pc=0x0c05a124u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a182; }
goto P_0c05a126;
P_0c05a126: /* original ea00, guest PC 0x0c05a126 */
if(!s->budget--) { s->failed_pc=0x0c05a126u; return 0; }
r[10]=0x00000000u;
goto P_0c05a128;
P_0c05a128: /* original d133, guest PC 0x0c05a128 */
if(!s->budget--) { s->failed_pc=0x0c05a128u; return 0; }
r[1]=read(ram,0x0c05a1f8u,4);
goto P_0c05a12a;
P_0c05a12a: /* original 62b3, guest PC 0x0c05a12a */
if(!s->budget--) { s->failed_pc=0x0c05a12au; return 0; }
r[2]=r[11];
goto P_0c05a12c;
P_0c05a12c: /* original 42ac, guest PC 0x0c05a12c */
if(!s->budget--) { s->failed_pc=0x0c05a12cu; return 0; }
r[2]=(r[10]&0x80000000u)?((r[10]&31u)?(uint32_t)((int32_t)r[2]>>((-r[10])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[10]&31u);
goto P_0c05a12e;
P_0c05a12e: /* original 6312, guest PC 0x0c05a12e */
if(!s->budget--) { s->failed_pc=0x0c05a12eu; return 0; }
tmp=read(ram,r[1],4);
r[3]=tmp;
goto P_0c05a130;
P_0c05a130: /* original 2238, guest PC 0x0c05a130 */
if(!s->budget--) { s->failed_pc=0x0c05a130u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c05a132;
P_0c05a132: /* original 8921, guest PC 0x0c05a132 */
if(!s->budget--) { s->failed_pc=0x0c05a132u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a178; }
goto P_0c05a134;
P_0c05a134: /* original 63f2, guest PC 0x0c05a134 */
if(!s->budget--) { s->failed_pc=0x0c05a134u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05a136;
P_0c05a136: /* original 6233, guest PC 0x0c05a136 */
if(!s->budget--) { s->failed_pc=0x0c05a136u; return 0; }
r[2]=r[3];
goto P_0c05a138;
P_0c05a138: /* original 6222, guest PC 0x0c05a138 */
if(!s->budget--) { s->failed_pc=0x0c05a138u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c05a13a;
P_0c05a13a: /* original 2289, guest PC 0x0c05a13a */
if(!s->budget--) { s->failed_pc=0x0c05a13au; return 0; }
r[2]&=r[8];
goto P_0c05a13c;
P_0c05a13c: /* original 60a3, guest PC 0x0c05a13c */
if(!s->budget--) { s->failed_pc=0x0c05a13cu; return 0; }
r[0]=r[10];
goto P_0c05a13e;
P_0c05a13e: /* original 0009, guest PC 0x0c05a13e */
if(!s->budget--) { s->failed_pc=0x0c05a13eu; return 0; }
goto P_0c05a140;
P_0c05a140: /* original 4028, guest PC 0x0c05a140 */
if(!s->budget--) { s->failed_pc=0x0c05a140u; return 0; }
r[0]<<=16;
goto P_0c05a142;
P_0c05a142: /* original 4018, guest PC 0x0c05a142 */
if(!s->budget--) { s->failed_pc=0x0c05a142u; return 0; }
r[0]<<=8;
goto P_0c05a144;
P_0c05a144: /* original 220b, guest PC 0x0c05a144 */
if(!s->budget--) { s->failed_pc=0x0c05a144u; return 0; }
r[2]|=r[0];
goto P_0c05a146;
P_0c05a146: /* original e620, guest PC 0x0c05a146 */
if(!s->budget--) { s->failed_pc=0x0c05a146u; return 0; }
r[6]=0x00000020u;
goto P_0c05a148;
P_0c05a148: /* original 2322, guest PC 0x0c05a148 */
if(!s->budget--) { s->failed_pc=0x0c05a148u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05a14a;
P_0c05a14a: /* original 65f3, guest PC 0x0c05a14a */
if(!s->budget--) { s->failed_pc=0x0c05a14au; return 0; }
r[5]=r[15];
goto P_0c05a14c;
P_0c05a14c: /* original 7510, guest PC 0x0c05a14c */
if(!s->budget--) { s->failed_pc=0x0c05a14cu; return 0; }
r[5]+=0x00000010u;
goto P_0c05a14e;
P_0c05a14e: /* original 64a3, guest PC 0x0c05a14e */
if(!s->budget--) { s->failed_pc=0x0c05a14eu; return 0; }
r[4]=r[10];
goto P_0c05a150;
P_0c05a150: /* original 4408, guest PC 0x0c05a150 */
if(!s->budget--) { s->failed_pc=0x0c05a150u; return 0; }
r[4]<<=2;
goto P_0c05a152;
P_0c05a152: /* original 63f3, guest PC 0x0c05a152 */
if(!s->budget--) { s->failed_pc=0x0c05a152u; return 0; }
r[3]=r[15];
goto P_0c05a154;
P_0c05a154: /* original 1f42, guest PC 0x0c05a154 */
if(!s->budget--) { s->failed_pc=0x0c05a154u; return 0; }
write(ram,r[15]+8,r[4],4);
goto P_0c05a156;
P_0c05a156: /* original 7344, guest PC 0x0c05a156 */
if(!s->budget--) { s->failed_pc=0x0c05a156u; return 0; }
r[3]+=0x00000044u;
goto P_0c05a158;
P_0c05a158: /* original 343c, guest PC 0x0c05a158 */
if(!s->budget--) { s->failed_pc=0x0c05a158u; return 0; }
r[4]+=r[3];
goto P_0c05a15a;
P_0c05a15a: /* original 1f41, guest PC 0x0c05a15a */
if(!s->budget--) { s->failed_pc=0x0c05a15au; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05a15c;
P_0c05a15c: /* original 6442, guest PC 0x0c05a15c */
if(!s->budget--) { s->failed_pc=0x0c05a15cu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a15e;
P_0c05a15e: /* original 4d0b, guest PC 0x0c05a15e */
if(!s->budget--) { s->failed_pc=0x0c05a15eu; return 0; }
target=r[13];
r[16]=code_base|0x0c05a162u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a162u) { target=s->pc; goto dispatch; }
goto P_0c05a162;
P_0c05a160: /* original 6442, guest PC 0x0c05a160 */
if(!s->budget--) { s->failed_pc=0x0c05a160u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a162;
P_0c05a162: /* original e604, guest PC 0x0c05a162 */
if(!s->budget--) { s->failed_pc=0x0c05a162u; return 0; }
r[6]=0x00000004u;
goto P_0c05a164;
P_0c05a164: /* original d526, guest PC 0x0c05a164 */
if(!s->budget--) { s->failed_pc=0x0c05a164u; return 0; }
r[5]=read(ram,0x0c05a200u,4);
goto P_0c05a166;
P_0c05a166: /* original 54f1, guest PC 0x0c05a166 */
if(!s->budget--) { s->failed_pc=0x0c05a166u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05a168;
P_0c05a168: /* original 6442, guest PC 0x0c05a168 */
if(!s->budget--) { s->failed_pc=0x0c05a168u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a16a;
P_0c05a16a: /* original 6442, guest PC 0x0c05a16a */
if(!s->budget--) { s->failed_pc=0x0c05a16au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a16c;
P_0c05a16c: /* original 4d0b, guest PC 0x0c05a16c */
if(!s->budget--) { s->failed_pc=0x0c05a16cu; return 0; }
target=r[13];
r[16]=code_base|0x0c05a170u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a170u) { target=s->pc; goto dispatch; }
goto P_0c05a170;
P_0c05a16e: /* original 7420, guest PC 0x0c05a16e */
if(!s->budget--) { s->failed_pc=0x0c05a16eu; return 0; }
r[4]+=0x00000020u;
goto P_0c05a170;
P_0c05a170: /* original 50f2, guest PC 0x0c05a170 */
if(!s->budget--) { s->failed_pc=0x0c05a170u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c05a172;
P_0c05a172: /* original e220, guest PC 0x0c05a172 */
if(!s->budget--) { s->failed_pc=0x0c05a172u; return 0; }
r[2]=0x00000020u;
goto P_0c05a174;
P_0c05a174: /* original 03ee, guest PC 0x0c05a174 */
if(!s->budget--) { s->failed_pc=0x0c05a174u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a176;
P_0c05a176: /* original 2322, guest PC 0x0c05a176 */
if(!s->budget--) { s->failed_pc=0x0c05a176u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05a178;
P_0c05a178: /* original 7a01, guest PC 0x0c05a178 */
if(!s->budget--) { s->failed_pc=0x0c05a178u; return 0; }
r[10]+=0x00000001u;
goto P_0c05a17a;
P_0c05a17a: /* original 3ac3, guest PC 0x0c05a17a */
if(!s->budget--) { s->failed_pc=0x0c05a17au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[12])!=0);
goto P_0c05a17c;
P_0c05a17c: /* original 8bd4, guest PC 0x0c05a17c */
if(!s->budget--) { s->failed_pc=0x0c05a17cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a128; }
goto P_0c05a17e;
P_0c05a17e: /* original a192, guest PC 0x0c05a17e */
if(!s->budget--) { s->failed_pc=0x0c05a17eu; return 0; }
goto P_0c05a4a6;
P_0c05a180: /* original 0009, guest PC 0x0c05a180 */
if(!s->budget--) { s->failed_pc=0x0c05a180u; return 0; }
goto P_0c05a182;
P_0c05a182: /* original 7401, guest PC 0x0c05a182 */
if(!s->budget--) { s->failed_pc=0x0c05a182u; return 0; }
r[4]+=0x00000001u;
goto P_0c05a184;
P_0c05a184: /* original 34c3, guest PC 0x0c05a184 */
if(!s->budget--) { s->failed_pc=0x0c05a184u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[4]>=(int32_t)r[12])!=0);
goto P_0c05a186;
P_0c05a186: /* original 8bab, guest PC 0x0c05a186 */
if(!s->budget--) { s->failed_pc=0x0c05a186u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a0e0; }
goto P_0c05a188;
P_0c05a188: /* original a1b4, guest PC 0x0c05a188 */
if(!s->budget--) { s->failed_pc=0x0c05a188u; return 0; }
goto P_0c05a4f4;
P_0c05a18a: /* original 0009, guest PC 0x0c05a18a */
if(!s->budget--) { s->failed_pc=0x0c05a18au; return 0; }
if(!vf3_matrix_family(0x0c05a18cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05a18cu; return 0; } return 1;
P_0c05a20c: /* original d2a8, guest PC 0x0c05a20c */
if(!s->budget--) { s->failed_pc=0x0c05a20cu; return 0; }
r[2]=read(ram,0x0c05a4b0u,4);
goto P_0c05a20e;
P_0c05a20e: /* original 6022, guest PC 0x0c05a20e */
if(!s->budget--) { s->failed_pc=0x0c05a20eu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05a210;
P_0c05a210: /* original c820, guest PC 0x0c05a210 */
if(!s->budget--) { s->failed_pc=0x0c05a210u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c05a212;
P_0c05a212: /* original 8b01, guest PC 0x0c05a212 */
if(!s->budget--) { s->failed_pc=0x0c05a212u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a218; }
goto P_0c05a214;
P_0c05a214: /* original a0c9, guest PC 0x0c05a214 */
if(!s->budget--) { s->failed_pc=0x0c05a214u; return 0; }
goto P_0c05a3aa;
P_0c05a216: /* original 0009, guest PC 0x0c05a216 */
if(!s->budget--) { s->failed_pc=0x0c05a216u; return 0; }
goto P_0c05a218;
P_0c05a218: /* original e300, guest PC 0x0c05a218 */
if(!s->budget--) { s->failed_pc=0x0c05a218u; return 0; }
r[3]=0x00000000u;
goto P_0c05a21a;
P_0c05a21a: /* original 2f32, guest PC 0x0c05a21a */
if(!s->budget--) { s->failed_pc=0x0c05a21au; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05a21c;
P_0c05a21c: /* original 63f3, guest PC 0x0c05a21c */
if(!s->budget--) { s->failed_pc=0x0c05a21cu; return 0; }
r[3]=r[15];
goto P_0c05a21e;
P_0c05a21e: /* original 7310, guest PC 0x0c05a21e */
if(!s->budget--) { s->failed_pc=0x0c05a21eu; return 0; }
r[3]+=0x00000010u;
goto P_0c05a220;
P_0c05a220: /* original 1f32, guest PC 0x0c05a220 */
if(!s->budget--) { s->failed_pc=0x0c05a220u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05a222;
P_0c05a222: /* original a08a, guest PC 0x0c05a222 */
if(!s->budget--) { s->failed_pc=0x0c05a222u; return 0; }
goto P_0c05a33a;
P_0c05a224: /* original 0009, guest PC 0x0c05a224 */
if(!s->budget--) { s->failed_pc=0x0c05a224u; return 0; }
goto P_0c05a226;
P_0c05a226: /* original d3a3, guest PC 0x0c05a226 */
if(!s->budget--) { s->failed_pc=0x0c05a226u; return 0; }
r[3]=read(ram,0x0c05a4b4u,4);
goto P_0c05a228;
P_0c05a228: /* original 6232, guest PC 0x0c05a228 */
if(!s->budget--) { s->failed_pc=0x0c05a228u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05a22a;
P_0c05a22a: /* original 61f2, guest PC 0x0c05a22a */
if(!s->budget--) { s->failed_pc=0x0c05a22au; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05a22c;
P_0c05a22c: /* original 3120, guest PC 0x0c05a22c */
if(!s->budget--) { s->failed_pc=0x0c05a22cu; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c05a22e;
P_0c05a22e: /* original 8b01, guest PC 0x0c05a22e */
if(!s->budget--) { s->failed_pc=0x0c05a22eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a234; }
goto P_0c05a230;
P_0c05a230: /* original a080, guest PC 0x0c05a230 */
if(!s->budget--) { s->failed_pc=0x0c05a230u; return 0; }
goto P_0c05a334;
P_0c05a232: /* original 0009, guest PC 0x0c05a232 */
if(!s->budget--) { s->failed_pc=0x0c05a232u; return 0; }
goto P_0c05a234;
P_0c05a234: /* original 62f2, guest PC 0x0c05a234 */
if(!s->budget--) { s->failed_pc=0x0c05a234u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05a236;
P_0c05a236: /* original 61b3, guest PC 0x0c05a236 */
if(!s->budget--) { s->failed_pc=0x0c05a236u; return 0; }
r[1]=r[11];
goto P_0c05a238;
P_0c05a238: /* original d39f, guest PC 0x0c05a238 */
if(!s->budget--) { s->failed_pc=0x0c05a238u; return 0; }
r[3]=read(ram,0x0c05a4b8u,4);
goto P_0c05a23a;
P_0c05a23a: /* original 412c, guest PC 0x0c05a23a */
if(!s->budget--) { s->failed_pc=0x0c05a23au; return 0; }
r[1]=(r[2]&0x80000000u)?((r[2]&31u)?(uint32_t)((int32_t)r[1]>>((-r[2])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[2]&31u);
goto P_0c05a23c;
P_0c05a23c: /* original 6032, guest PC 0x0c05a23c */
if(!s->budget--) { s->failed_pc=0x0c05a23cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c05a23e;
P_0c05a23e: /* original 2108, guest PC 0x0c05a23e */
if(!s->budget--) { s->failed_pc=0x0c05a23eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[0])==0)!=0);
goto P_0c05a240;
P_0c05a240: /* original 8973, guest PC 0x0c05a240 */
if(!s->budget--) { s->failed_pc=0x0c05a240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a32a; }
goto P_0c05a242;
P_0c05a242: /* original 4208, guest PC 0x0c05a242 */
if(!s->budget--) { s->failed_pc=0x0c05a242u; return 0; }
r[2]<<=2;
goto P_0c05a244;
P_0c05a244: /* original 1f21, guest PC 0x0c05a244 */
if(!s->budget--) { s->failed_pc=0x0c05a244u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c05a246;
P_0c05a246: /* original 32ec, guest PC 0x0c05a246 */
if(!s->budget--) { s->failed_pc=0x0c05a246u; return 0; }
r[2]+=r[14];
goto P_0c05a248;
P_0c05a248: /* original 1f23, guest PC 0x0c05a248 */
if(!s->budget--) { s->failed_pc=0x0c05a248u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c05a24a;
P_0c05a24a: /* original 6322, guest PC 0x0c05a24a */
if(!s->budget--) { s->failed_pc=0x0c05a24au; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c05a24c;
P_0c05a24c: /* original 62a2, guest PC 0x0c05a24c */
if(!s->budget--) { s->failed_pc=0x0c05a24cu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c05a24e;
P_0c05a24e: /* original 50f1, guest PC 0x0c05a24e */
if(!s->budget--) { s->failed_pc=0x0c05a24eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05a250;
P_0c05a250: /* original 012e, guest PC 0x0c05a250 */
if(!s->budget--) { s->failed_pc=0x0c05a250u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c05a252;
P_0c05a252: /* original 62f3, guest PC 0x0c05a252 */
if(!s->budget--) { s->failed_pc=0x0c05a252u; return 0; }
r[2]=r[15];
goto P_0c05a254;
P_0c05a254: /* original 50f1, guest PC 0x0c05a254 */
if(!s->budget--) { s->failed_pc=0x0c05a254u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05a256;
P_0c05a256: /* original 7244, guest PC 0x0c05a256 */
if(!s->budget--) { s->failed_pc=0x0c05a256u; return 0; }
r[2]+=0x00000044u;
goto P_0c05a258;
P_0c05a258: /* original 022e, guest PC 0x0c05a258 */
if(!s->budget--) { s->failed_pc=0x0c05a258u; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c05a25a;
P_0c05a25a: /* original 6222, guest PC 0x0c05a25a */
if(!s->budget--) { s->failed_pc=0x0c05a25au; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c05a25c;
P_0c05a25c: /* original 3128, guest PC 0x0c05a25c */
if(!s->budget--) { s->failed_pc=0x0c05a25cu; return 0; }
r[1]-=r[2];
goto P_0c05a25e;
P_0c05a25e: /* original d297, guest PC 0x0c05a25e */
if(!s->budget--) { s->failed_pc=0x0c05a25eu; return 0; }
r[2]=read(ram,0x0c05a4bcu,4);
goto P_0c05a260;
P_0c05a260: /* original 420b, guest PC 0x0c05a260 */
if(!s->budget--) { s->failed_pc=0x0c05a260u; return 0; }
target=r[2];
r[16]=code_base|0x0c05a264u;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a264u) { target=s->pc; goto dispatch; }
goto P_0c05a264;
P_0c05a262: /* original e004, guest PC 0x0c05a262 */
if(!s->budget--) { s->failed_pc=0x0c05a262u; return 0; }
r[0]=0x00000004u;
goto P_0c05a264;
P_0c05a264: /* original d596, guest PC 0x0c05a264 */
if(!s->budget--) { s->failed_pc=0x0c05a264u; return 0; }
r[5]=read(ram,0x0c05a4c0u,4);
goto P_0c05a266;
P_0c05a266: /* original 4008, guest PC 0x0c05a266 */
if(!s->budget--) { s->failed_pc=0x0c05a266u; return 0; }
r[0]<<=2;
goto P_0c05a268;
P_0c05a268: /* original 2302, guest PC 0x0c05a268 */
if(!s->budget--) { s->failed_pc=0x0c05a268u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a26a;
P_0c05a26a: /* original e604, guest PC 0x0c05a26a */
if(!s->budget--) { s->failed_pc=0x0c05a26au; return 0; }
r[6]=0x00000004u;
goto P_0c05a26c;
P_0c05a26c: /* original 62a2, guest PC 0x0c05a26c */
if(!s->budget--) { s->failed_pc=0x0c05a26cu; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c05a26e;
P_0c05a26e: /* original 50f1, guest PC 0x0c05a26e */
if(!s->budget--) { s->failed_pc=0x0c05a26eu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05a270;
P_0c05a270: /* original 4d0b, guest PC 0x0c05a270 */
if(!s->budget--) { s->failed_pc=0x0c05a270u; return 0; }
target=r[13];
r[16]=code_base|0x0c05a274u;
r[4]=read(ram,r[2]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a274u) { target=s->pc; goto dispatch; }
goto P_0c05a274;
P_0c05a272: /* original 042e, guest PC 0x0c05a272 */
if(!s->budget--) { s->failed_pc=0x0c05a272u; return 0; }
r[4]=read(ram,r[2]+r[0],4);
goto P_0c05a274;
P_0c05a274: /* original 63a2, guest PC 0x0c05a274 */
if(!s->budget--) { s->failed_pc=0x0c05a274u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c05a276;
P_0c05a276: /* original 50f1, guest PC 0x0c05a276 */
if(!s->budget--) { s->failed_pc=0x0c05a276u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05a278;
P_0c05a278: /* original 023e, guest PC 0x0c05a278 */
if(!s->budget--) { s->failed_pc=0x0c05a278u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05a27a;
P_0c05a27a: /* original 7220, guest PC 0x0c05a27a */
if(!s->budget--) { s->failed_pc=0x0c05a27au; return 0; }
r[2]+=0x00000020u;
goto P_0c05a27c;
P_0c05a27c: /* original 0326, guest PC 0x0c05a27c */
if(!s->budget--) { s->failed_pc=0x0c05a27cu; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05a27e;
P_0c05a27e: /* original 53f3, guest PC 0x0c05a27e */
if(!s->budget--) { s->failed_pc=0x0c05a27eu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c05a280;
P_0c05a280: /* original 51f1, guest PC 0x0c05a280 */
if(!s->budget--) { s->failed_pc=0x0c05a280u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c05a282;
P_0c05a282: /* original 6232, guest PC 0x0c05a282 */
if(!s->budget--) { s->failed_pc=0x0c05a282u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05a284;
P_0c05a284: /* original d08f, guest PC 0x0c05a284 */
if(!s->budget--) { s->failed_pc=0x0c05a284u; return 0; }
r[0]=read(ram,0x0c05a4c4u,4);
goto P_0c05a286;
P_0c05a286: /* original 031e, guest PC 0x0c05a286 */
if(!s->budget--) { s->failed_pc=0x0c05a286u; return 0; }
r[3]=read(ram,r[1]+r[0],4);
goto P_0c05a288;
P_0c05a288: /* original 6222, guest PC 0x0c05a288 */
if(!s->budget--) { s->failed_pc=0x0c05a288u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c05a28a;
P_0c05a28a: /* original 3236, guest PC 0x0c05a28a */
if(!s->budget--) { s->failed_pc=0x0c05a28au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c05a28c;
P_0c05a28c: /* original 8b08, guest PC 0x0c05a28c */
if(!s->budget--) { s->failed_pc=0x0c05a28cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a2a0; }
goto P_0c05a28e;
P_0c05a28e: /* original 6203, guest PC 0x0c05a28e */
if(!s->budget--) { s->failed_pc=0x0c05a28eu; return 0; }
r[2]=r[0];
goto P_0c05a290;
P_0c05a290: /* original 64f2, guest PC 0x0c05a290 */
if(!s->budget--) { s->failed_pc=0x0c05a290u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05a292;
P_0c05a292: /* original 4408, guest PC 0x0c05a292 */
if(!s->budget--) { s->failed_pc=0x0c05a292u; return 0; }
r[4]<<=2;
goto P_0c05a294;
P_0c05a294: /* original 324c, guest PC 0x0c05a294 */
if(!s->budget--) { s->failed_pc=0x0c05a294u; return 0; }
r[2]+=r[4];
goto P_0c05a296;
P_0c05a296: /* original 6043, guest PC 0x0c05a296 */
if(!s->budget--) { s->failed_pc=0x0c05a296u; return 0; }
r[0]=r[4];
goto P_0c05a298;
P_0c05a298: /* original 0009, guest PC 0x0c05a298 */
if(!s->budget--) { s->failed_pc=0x0c05a298u; return 0; }
goto P_0c05a29a;
P_0c05a29a: /* original 03ee, guest PC 0x0c05a29a */
if(!s->budget--) { s->failed_pc=0x0c05a29au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a29c;
P_0c05a29c: /* original 6332, guest PC 0x0c05a29c */
if(!s->budget--) { s->failed_pc=0x0c05a29cu; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a29e;
P_0c05a29e: /* original 2232, guest PC 0x0c05a29e */
if(!s->budget--) { s->failed_pc=0x0c05a29eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c05a2a0;
P_0c05a2a0: /* original 64f2, guest PC 0x0c05a2a0 */
if(!s->budget--) { s->failed_pc=0x0c05a2a0u; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05a2a2;
P_0c05a2a2: /* original 4408, guest PC 0x0c05a2a2 */
if(!s->budget--) { s->failed_pc=0x0c05a2a2u; return 0; }
r[4]<<=2;
goto P_0c05a2a4;
P_0c05a2a4: /* original 6043, guest PC 0x0c05a2a4 */
if(!s->budget--) { s->failed_pc=0x0c05a2a4u; return 0; }
r[0]=r[4];
goto P_0c05a2a6;
P_0c05a2a6: /* original 0009, guest PC 0x0c05a2a6 */
if(!s->budget--) { s->failed_pc=0x0c05a2a6u; return 0; }
goto P_0c05a2a8;
P_0c05a2a8: /* original 03ee, guest PC 0x0c05a2a8 */
if(!s->budget--) { s->failed_pc=0x0c05a2a8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a2aa;
P_0c05a2aa: /* original d287, guest PC 0x0c05a2aa */
if(!s->budget--) { s->failed_pc=0x0c05a2aau; return 0; }
r[2]=read(ram,0x0c05a4c8u,4);
goto P_0c05a2ac;
P_0c05a2ac: /* original 6332, guest PC 0x0c05a2ac */
if(!s->budget--) { s->failed_pc=0x0c05a2acu; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a2ae;
P_0c05a2ae: /* original 022e, guest PC 0x0c05a2ae */
if(!s->budget--) { s->failed_pc=0x0c05a2aeu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c05a2b0;
P_0c05a2b0: /* original 3326, guest PC 0x0c05a2b0 */
if(!s->budget--) { s->failed_pc=0x0c05a2b0u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[2])!=0);
goto P_0c05a2b2;
P_0c05a2b2: /* original 8b3f, guest PC 0x0c05a2b2 */
if(!s->budget--) { s->failed_pc=0x0c05a2b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a334; }
goto P_0c05a2b4;
P_0c05a2b4: /* original eb00, guest PC 0x0c05a2b4 */
if(!s->budget--) { s->failed_pc=0x0c05a2b4u; return 0; }
r[11]=0x00000000u;
goto P_0c05a2b6;
P_0c05a2b6: /* original d37f, guest PC 0x0c05a2b6 */
if(!s->budget--) { s->failed_pc=0x0c05a2b6u; return 0; }
r[3]=read(ram,0x0c05a4b4u,4);
goto P_0c05a2b8;
P_0c05a2b8: /* original 6232, guest PC 0x0c05a2b8 */
if(!s->budget--) { s->failed_pc=0x0c05a2b8u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c05a2ba;
P_0c05a2ba: /* original 3b20, guest PC 0x0c05a2ba */
if(!s->budget--) { s->failed_pc=0x0c05a2bau; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[2])!=0);
goto P_0c05a2bc;
P_0c05a2bc: /* original 8928, guest PC 0x0c05a2bc */
if(!s->budget--) { s->failed_pc=0x0c05a2bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a310; }
goto P_0c05a2be;
P_0c05a2be: /* original e001, guest PC 0x0c05a2be */
if(!s->budget--) { s->failed_pc=0x0c05a2beu; return 0; }
r[0]=0x00000001u;
goto P_0c05a2c0;
P_0c05a2c0: /* original d17d, guest PC 0x0c05a2c0 */
if(!s->budget--) { s->failed_pc=0x0c05a2c0u; return 0; }
r[1]=read(ram,0x0c05a4b8u,4);
goto P_0c05a2c2;
P_0c05a2c2: /* original 40bc, guest PC 0x0c05a2c2 */
if(!s->budget--) { s->failed_pc=0x0c05a2c2u; return 0; }
r[0]=(r[11]&0x80000000u)?((r[11]&31u)?(uint32_t)((int32_t)r[0]>>((-r[11])&31u)):((int32_t)r[0]<0?0xffffffffu:0)):r[0]<<(r[11]&31u);
goto P_0c05a2c4;
P_0c05a2c4: /* original 6212, guest PC 0x0c05a2c4 */
if(!s->budget--) { s->failed_pc=0x0c05a2c4u; return 0; }
tmp=read(ram,r[1],4);
r[2]=tmp;
goto P_0c05a2c6;
P_0c05a2c6: /* original 2028, guest PC 0x0c05a2c6 */
if(!s->budget--) { s->failed_pc=0x0c05a2c6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[2])==0)!=0);
goto P_0c05a2c8;
P_0c05a2c8: /* original 8922, guest PC 0x0c05a2c8 */
if(!s->budget--) { s->failed_pc=0x0c05a2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a310; }
goto P_0c05a2ca;
P_0c05a2ca: /* original e620, guest PC 0x0c05a2ca */
if(!s->budget--) { s->failed_pc=0x0c05a2cau; return 0; }
r[6]=0x00000020u;
goto P_0c05a2cc;
P_0c05a2cc: /* original 53f2, guest PC 0x0c05a2cc */
if(!s->budget--) { s->failed_pc=0x0c05a2ccu; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05a2ce;
P_0c05a2ce: /* original 65f3, guest PC 0x0c05a2ce */
if(!s->budget--) { s->failed_pc=0x0c05a2ceu; return 0; }
r[5]=r[15];
goto P_0c05a2d0;
P_0c05a2d0: /* original 6233, guest PC 0x0c05a2d0 */
if(!s->budget--) { s->failed_pc=0x0c05a2d0u; return 0; }
r[2]=r[3];
goto P_0c05a2d2;
P_0c05a2d2: /* original 7510, guest PC 0x0c05a2d2 */
if(!s->budget--) { s->failed_pc=0x0c05a2d2u; return 0; }
r[5]+=0x00000010u;
goto P_0c05a2d4;
P_0c05a2d4: /* original 6122, guest PC 0x0c05a2d4 */
if(!s->budget--) { s->failed_pc=0x0c05a2d4u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05a2d6;
P_0c05a2d6: /* original 64b3, guest PC 0x0c05a2d6 */
if(!s->budget--) { s->failed_pc=0x0c05a2d6u; return 0; }
r[4]=r[11];
goto P_0c05a2d8;
P_0c05a2d8: /* original 2189, guest PC 0x0c05a2d8 */
if(!s->budget--) { s->failed_pc=0x0c05a2d8u; return 0; }
r[1]&=r[8];
goto P_0c05a2da;
P_0c05a2da: /* original 62b3, guest PC 0x0c05a2da */
if(!s->budget--) { s->failed_pc=0x0c05a2dau; return 0; }
r[2]=r[11];
goto P_0c05a2dc;
P_0c05a2dc: /* original 4228, guest PC 0x0c05a2dc */
if(!s->budget--) { s->failed_pc=0x0c05a2dcu; return 0; }
r[2]<<=16;
goto P_0c05a2de;
P_0c05a2de: /* original 4218, guest PC 0x0c05a2de */
if(!s->budget--) { s->failed_pc=0x0c05a2deu; return 0; }
r[2]<<=8;
goto P_0c05a2e0;
P_0c05a2e0: /* original 212b, guest PC 0x0c05a2e0 */
if(!s->budget--) { s->failed_pc=0x0c05a2e0u; return 0; }
r[1]|=r[2];
goto P_0c05a2e2;
P_0c05a2e2: /* original 4408, guest PC 0x0c05a2e2 */
if(!s->budget--) { s->failed_pc=0x0c05a2e2u; return 0; }
r[4]<<=2;
goto P_0c05a2e4;
P_0c05a2e4: /* original 2312, guest PC 0x0c05a2e4 */
if(!s->budget--) { s->failed_pc=0x0c05a2e4u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05a2e6;
P_0c05a2e6: /* original 63f3, guest PC 0x0c05a2e6 */
if(!s->budget--) { s->failed_pc=0x0c05a2e6u; return 0; }
r[3]=r[15];
goto P_0c05a2e8;
P_0c05a2e8: /* original 2f42, guest PC 0x0c05a2e8 */
if(!s->budget--) { s->failed_pc=0x0c05a2e8u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c05a2ea;
P_0c05a2ea: /* original 7344, guest PC 0x0c05a2ea */
if(!s->budget--) { s->failed_pc=0x0c05a2eau; return 0; }
r[3]+=0x00000044u;
goto P_0c05a2ec;
P_0c05a2ec: /* original 343c, guest PC 0x0c05a2ec */
if(!s->budget--) { s->failed_pc=0x0c05a2ecu; return 0; }
r[4]+=r[3];
goto P_0c05a2ee;
P_0c05a2ee: /* original 1f41, guest PC 0x0c05a2ee */
if(!s->budget--) { s->failed_pc=0x0c05a2eeu; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05a2f0;
P_0c05a2f0: /* original 6442, guest PC 0x0c05a2f0 */
if(!s->budget--) { s->failed_pc=0x0c05a2f0u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a2f2;
P_0c05a2f2: /* original 4d0b, guest PC 0x0c05a2f2 */
if(!s->budget--) { s->failed_pc=0x0c05a2f2u; return 0; }
target=r[13];
r[16]=code_base|0x0c05a2f6u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a2f6u) { target=s->pc; goto dispatch; }
goto P_0c05a2f6;
P_0c05a2f4: /* original 6442, guest PC 0x0c05a2f4 */
if(!s->budget--) { s->failed_pc=0x0c05a2f4u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a2f6;
P_0c05a2f6: /* original e604, guest PC 0x0c05a2f6 */
if(!s->budget--) { s->failed_pc=0x0c05a2f6u; return 0; }
r[6]=0x00000004u;
goto P_0c05a2f8;
P_0c05a2f8: /* original d571, guest PC 0x0c05a2f8 */
if(!s->budget--) { s->failed_pc=0x0c05a2f8u; return 0; }
r[5]=read(ram,0x0c05a4c0u,4);
goto P_0c05a2fa;
P_0c05a2fa: /* original 54f1, guest PC 0x0c05a2fa */
if(!s->budget--) { s->failed_pc=0x0c05a2fau; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05a2fc;
P_0c05a2fc: /* original 6442, guest PC 0x0c05a2fc */
if(!s->budget--) { s->failed_pc=0x0c05a2fcu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a2fe;
P_0c05a2fe: /* original 6442, guest PC 0x0c05a2fe */
if(!s->budget--) { s->failed_pc=0x0c05a2feu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a300;
P_0c05a300: /* original 4d0b, guest PC 0x0c05a300 */
if(!s->budget--) { s->failed_pc=0x0c05a300u; return 0; }
target=r[13];
r[16]=code_base|0x0c05a304u;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a304u) { target=s->pc; goto dispatch; }
goto P_0c05a304;
P_0c05a302: /* original 7420, guest PC 0x0c05a302 */
if(!s->budget--) { s->failed_pc=0x0c05a302u; return 0; }
r[4]+=0x00000020u;
goto P_0c05a304;
P_0c05a304: /* original 60f2, guest PC 0x0c05a304 */
if(!s->budget--) { s->failed_pc=0x0c05a304u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a306;
P_0c05a306: /* original e220, guest PC 0x0c05a306 */
if(!s->budget--) { s->failed_pc=0x0c05a306u; return 0; }
r[2]=0x00000020u;
goto P_0c05a308;
P_0c05a308: /* original 03ee, guest PC 0x0c05a308 */
if(!s->budget--) { s->failed_pc=0x0c05a308u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a30a;
P_0c05a30a: /* original 2322, guest PC 0x0c05a30a */
if(!s->budget--) { s->failed_pc=0x0c05a30au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05a30c;
P_0c05a30c: /* original a005, guest PC 0x0c05a30c */
if(!s->budget--) { s->failed_pc=0x0c05a30cu; return 0; }
goto P_0c05a31a;
P_0c05a30e: /* original 0009, guest PC 0x0c05a30e */
if(!s->budget--) { s->failed_pc=0x0c05a30eu; return 0; }
goto P_0c05a310;
P_0c05a310: /* original 60b3, guest PC 0x0c05a310 */
if(!s->budget--) { s->failed_pc=0x0c05a310u; return 0; }
r[0]=r[11];
goto P_0c05a312;
P_0c05a312: /* original 0009, guest PC 0x0c05a312 */
if(!s->budget--) { s->failed_pc=0x0c05a312u; return 0; }
goto P_0c05a314;
P_0c05a314: /* original 4008, guest PC 0x0c05a314 */
if(!s->budget--) { s->failed_pc=0x0c05a314u; return 0; }
r[0]<<=2;
goto P_0c05a316;
P_0c05a316: /* original 03ee, guest PC 0x0c05a316 */
if(!s->budget--) { s->failed_pc=0x0c05a316u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a318;
P_0c05a318: /* original 2392, guest PC 0x0c05a318 */
if(!s->budget--) { s->failed_pc=0x0c05a318u; return 0; }
write(ram,r[3],r[9],4);
goto P_0c05a31a;
P_0c05a31a: /* original 7b01, guest PC 0x0c05a31a */
if(!s->budget--) { s->failed_pc=0x0c05a31au; return 0; }
r[11]+=0x00000001u;
goto P_0c05a31c;
P_0c05a31c: /* original 3bc3, guest PC 0x0c05a31c */
if(!s->budget--) { s->failed_pc=0x0c05a31cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[11]>=(int32_t)r[12])!=0);
goto P_0c05a31e;
P_0c05a31e: /* original 8bca, guest PC 0x0c05a31e */
if(!s->budget--) { s->failed_pc=0x0c05a31eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a2b6; }
goto P_0c05a320;
P_0c05a320: /* original d36a, guest PC 0x0c05a320 */
if(!s->budget--) { s->failed_pc=0x0c05a320u; return 0; }
r[3]=read(ram,0x0c05a4ccu,4);
goto P_0c05a322;
P_0c05a322: /* original 430b, guest PC 0x0c05a322 */
if(!s->budget--) { s->failed_pc=0x0c05a322u; return 0; }
target=r[3];
r[16]=code_base|0x0c05a326u;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a326u) { target=s->pc; goto dispatch; }
goto P_0c05a326;
P_0c05a324: /* original e402, guest PC 0x0c05a324 */
if(!s->budget--) { s->failed_pc=0x0c05a324u; return 0; }
r[4]=0x00000002u;
goto P_0c05a326;
P_0c05a326: /* original a00d, guest PC 0x0c05a326 */
if(!s->budget--) { s->failed_pc=0x0c05a326u; return 0; }
goto P_0c05a344;
P_0c05a328: /* original 0009, guest PC 0x0c05a328 */
if(!s->budget--) { s->failed_pc=0x0c05a328u; return 0; }
goto P_0c05a32a;
P_0c05a32a: /* original 6023, guest PC 0x0c05a32a */
if(!s->budget--) { s->failed_pc=0x0c05a32au; return 0; }
r[0]=r[2];
goto P_0c05a32c;
P_0c05a32c: /* original 0009, guest PC 0x0c05a32c */
if(!s->budget--) { s->failed_pc=0x0c05a32cu; return 0; }
goto P_0c05a32e;
P_0c05a32e: /* original 4008, guest PC 0x0c05a32e */
if(!s->budget--) { s->failed_pc=0x0c05a32eu; return 0; }
r[0]<<=2;
goto P_0c05a330;
P_0c05a330: /* original 01ee, guest PC 0x0c05a330 */
if(!s->budget--) { s->failed_pc=0x0c05a330u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c05a332;
P_0c05a332: /* original 2192, guest PC 0x0c05a332 */
if(!s->budget--) { s->failed_pc=0x0c05a332u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05a334;
P_0c05a334: /* original 63f2, guest PC 0x0c05a334 */
if(!s->budget--) { s->failed_pc=0x0c05a334u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05a336;
P_0c05a336: /* original 7301, guest PC 0x0c05a336 */
if(!s->budget--) { s->failed_pc=0x0c05a336u; return 0; }
r[3]+=0x00000001u;
goto P_0c05a338;
P_0c05a338: /* original 2f32, guest PC 0x0c05a338 */
if(!s->budget--) { s->failed_pc=0x0c05a338u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c05a33a;
P_0c05a33a: /* original 62f2, guest PC 0x0c05a33a */
if(!s->budget--) { s->failed_pc=0x0c05a33au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05a33c;
P_0c05a33c: /* original 32c3, guest PC 0x0c05a33c */
if(!s->budget--) { s->failed_pc=0x0c05a33cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[12])!=0);
goto P_0c05a33e;
P_0c05a33e: /* original 8901, guest PC 0x0c05a33e */
if(!s->budget--) { s->failed_pc=0x0c05a33eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a344; }
goto P_0c05a340;
P_0c05a340: /* original af71, guest PC 0x0c05a340 */
if(!s->budget--) { s->failed_pc=0x0c05a340u; return 0; }
goto P_0c05a226;
P_0c05a342: /* original 0009, guest PC 0x0c05a342 */
if(!s->budget--) { s->failed_pc=0x0c05a342u; return 0; }
goto P_0c05a344;
P_0c05a344: /* original d35b, guest PC 0x0c05a344 */
if(!s->budget--) { s->failed_pc=0x0c05a344u; return 0; }
r[3]=read(ram,0x0c05a4b4u,4);
goto P_0c05a346;
P_0c05a346: /* original 6132, guest PC 0x0c05a346 */
if(!s->budget--) { s->failed_pc=0x0c05a346u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c05a348;
P_0c05a348: /* original 4108, guest PC 0x0c05a348 */
if(!s->budget--) { s->failed_pc=0x0c05a348u; return 0; }
r[1]<<=2;
goto P_0c05a34a;
P_0c05a34a: /* original 60a2, guest PC 0x0c05a34a */
if(!s->budget--) { s->failed_pc=0x0c05a34au; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c05a34c;
P_0c05a34c: /* original 021e, guest PC 0x0c05a34c */
if(!s->budget--) { s->failed_pc=0x0c05a34cu; return 0; }
r[2]=read(ram,r[1]+r[0],4);
goto P_0c05a34e;
P_0c05a34e: /* original 6033, guest PC 0x0c05a34e */
if(!s->budget--) { s->failed_pc=0x0c05a34eu; return 0; }
r[0]=r[3];
goto P_0c05a350;
P_0c05a350: /* original 0009, guest PC 0x0c05a350 */
if(!s->budget--) { s->failed_pc=0x0c05a350u; return 0; }
goto P_0c05a352;
P_0c05a352: /* original 6102, guest PC 0x0c05a352 */
if(!s->budget--) { s->failed_pc=0x0c05a352u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05a354;
P_0c05a354: /* original 4108, guest PC 0x0c05a354 */
if(!s->budget--) { s->failed_pc=0x0c05a354u; return 0; }
r[1]<<=2;
goto P_0c05a356;
P_0c05a356: /* original 63f3, guest PC 0x0c05a356 */
if(!s->budget--) { s->failed_pc=0x0c05a356u; return 0; }
r[3]=r[15];
goto P_0c05a358;
P_0c05a358: /* original 7344, guest PC 0x0c05a358 */
if(!s->budget--) { s->failed_pc=0x0c05a358u; return 0; }
r[3]+=0x00000044u;
goto P_0c05a35a;
P_0c05a35a: /* original 313c, guest PC 0x0c05a35a */
if(!s->budget--) { s->failed_pc=0x0c05a35au; return 0; }
r[1]+=r[3];
goto P_0c05a35c;
P_0c05a35c: /* original 6112, guest PC 0x0c05a35c */
if(!s->budget--) { s->failed_pc=0x0c05a35cu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05a35e;
P_0c05a35e: /* original 6112, guest PC 0x0c05a35e */
if(!s->budget--) { s->failed_pc=0x0c05a35eu; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05a360;
P_0c05a360: /* original 3210, guest PC 0x0c05a360 */
if(!s->budget--) { s->failed_pc=0x0c05a360u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c05a362;
P_0c05a362: /* original 8901, guest PC 0x0c05a362 */
if(!s->budget--) { s->failed_pc=0x0c05a362u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a368; }
goto P_0c05a364;
P_0c05a364: /* original a0c6, guest PC 0x0c05a364 */
if(!s->budget--) { s->failed_pc=0x0c05a364u; return 0; }
goto P_0c05a4f4;
P_0c05a366: /* original 0009, guest PC 0x0c05a366 */
if(!s->budget--) { s->failed_pc=0x0c05a366u; return 0; }
goto P_0c05a368;
P_0c05a368: /* original d159, guest PC 0x0c05a368 */
if(!s->budget--) { s->failed_pc=0x0c05a368u; return 0; }
r[1]=read(ram,0x0c05a4d0u,4);
goto P_0c05a36a;
P_0c05a36a: /* original e410, guest PC 0x0c05a36a */
if(!s->budget--) { s->failed_pc=0x0c05a36au; return 0; }
r[4]=0x00000010u;
goto P_0c05a36c;
P_0c05a36c: /* original 2142, guest PC 0x0c05a36c */
if(!s->budget--) { s->failed_pc=0x0c05a36cu; return 0; }
write(ram,r[1],r[4],4);
goto P_0c05a36e;
P_0c05a36e: /* original d359, guest PC 0x0c05a36e */
if(!s->budget--) { s->failed_pc=0x0c05a36eu; return 0; }
r[3]=read(ram,0x0c05a4d4u,4);
goto P_0c05a370;
P_0c05a370: /* original 2342, guest PC 0x0c05a370 */
if(!s->budget--) { s->failed_pc=0x0c05a370u; return 0; }
write(ram,r[3],r[4],4);
goto P_0c05a372;
P_0c05a372: /* original 64f3, guest PC 0x0c05a372 */
if(!s->budget--) { s->failed_pc=0x0c05a372u; return 0; }
r[4]=r[15];
goto P_0c05a374;
P_0c05a374: /* original 7410, guest PC 0x0c05a374 */
if(!s->budget--) { s->failed_pc=0x0c05a374u; return 0; }
r[4]+=0x00000010u;
goto P_0c05a376;
P_0c05a376: /* original 6242, guest PC 0x0c05a376 */
if(!s->budget--) { s->failed_pc=0x0c05a376u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c05a378;
P_0c05a378: /* original 2829, guest PC 0x0c05a378 */
if(!s->budget--) { s->failed_pc=0x0c05a378u; return 0; }
r[8]&=r[2];
goto P_0c05a37a;
P_0c05a37a: /* original d24e, guest PC 0x0c05a37a */
if(!s->budget--) { s->failed_pc=0x0c05a37au; return 0; }
r[2]=read(ram,0x0c05a4b4u,4);
goto P_0c05a37c;
P_0c05a37c: /* original 6022, guest PC 0x0c05a37c */
if(!s->budget--) { s->failed_pc=0x0c05a37cu; return 0; }
tmp=read(ram,r[2],4);
r[0]=tmp;
goto P_0c05a37e;
P_0c05a37e: /* original c907, guest PC 0x0c05a37e */
if(!s->budget--) { s->failed_pc=0x0c05a37eu; return 0; }
r[0]&=7u;
goto P_0c05a380;
P_0c05a380: /* original 4028, guest PC 0x0c05a380 */
if(!s->budget--) { s->failed_pc=0x0c05a380u; return 0; }
r[0]<<=16;
goto P_0c05a382;
P_0c05a382: /* original 4018, guest PC 0x0c05a382 */
if(!s->budget--) { s->failed_pc=0x0c05a382u; return 0; }
r[0]<<=8;
goto P_0c05a384;
P_0c05a384: /* original 280b, guest PC 0x0c05a384 */
if(!s->budget--) { s->failed_pc=0x0c05a384u; return 0; }
r[8]|=r[0];
goto P_0c05a386;
P_0c05a386: /* original 6123, guest PC 0x0c05a386 */
if(!s->budget--) { s->failed_pc=0x0c05a386u; return 0; }
r[1]=r[2];
goto P_0c05a388;
P_0c05a388: /* original 2482, guest PC 0x0c05a388 */
if(!s->budget--) { s->failed_pc=0x0c05a388u; return 0; }
write(ram,r[4],r[8],4);
goto P_0c05a38a;
P_0c05a38a: /* original 6e12, guest PC 0x0c05a38a */
if(!s->budget--) { s->failed_pc=0x0c05a38au; return 0; }
tmp=read(ram,r[1],4);
r[14]=tmp;
goto P_0c05a38c;
P_0c05a38c: /* original 4e08, guest PC 0x0c05a38c */
if(!s->budget--) { s->failed_pc=0x0c05a38cu; return 0; }
r[14]<<=2;
goto P_0c05a38e;
P_0c05a38e: /* original e620, guest PC 0x0c05a38e */
if(!s->budget--) { s->failed_pc=0x0c05a38eu; return 0; }
r[6]=0x00000020u;
goto P_0c05a390;
P_0c05a390: /* original 60a2, guest PC 0x0c05a390 */
if(!s->budget--) { s->failed_pc=0x0c05a390u; return 0; }
tmp=read(ram,r[10],4);
r[0]=tmp;
goto P_0c05a392;
P_0c05a392: /* original 65f3, guest PC 0x0c05a392 */
if(!s->budget--) { s->failed_pc=0x0c05a392u; return 0; }
r[5]=r[15];
goto P_0c05a394;
P_0c05a394: /* original d350, guest PC 0x0c05a394 */
if(!s->budget--) { s->failed_pc=0x0c05a394u; return 0; }
r[3]=read(ram,0x0c05a4d8u,4);
goto P_0c05a396;
P_0c05a396: /* original 7510, guest PC 0x0c05a396 */
if(!s->budget--) { s->failed_pc=0x0c05a396u; return 0; }
r[5]+=0x00000010u;
goto P_0c05a398;
P_0c05a398: /* original 0eee, guest PC 0x0c05a398 */
if(!s->budget--) { s->failed_pc=0x0c05a398u; return 0; }
r[14]=read(ram,r[14]+r[0],4);
goto P_0c05a39a;
P_0c05a39a: /* original 2e39, guest PC 0x0c05a39a */
if(!s->budget--) { s->failed_pc=0x0c05a39au; return 0; }
r[14]&=r[3];
goto P_0c05a39c;
P_0c05a39c: /* original d24f, guest PC 0x0c05a39c */
if(!s->budget--) { s->failed_pc=0x0c05a39cu; return 0; }
r[2]=read(ram,0x0c05a4dcu,4);
goto P_0c05a39e;
P_0c05a39e: /* original 2e2b, guest PC 0x0c05a39e */
if(!s->budget--) { s->failed_pc=0x0c05a39eu; return 0; }
r[14]|=r[2];
goto P_0c05a3a0;
P_0c05a3a0: /* original 4d0b, guest PC 0x0c05a3a0 */
if(!s->budget--) { s->failed_pc=0x0c05a3a0u; return 0; }
target=r[13];
r[16]=code_base|0x0c05a3a4u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a3a4u) { target=s->pc; goto dispatch; }
goto P_0c05a3a4;
P_0c05a3a2: /* original 64e3, guest PC 0x0c05a3a2 */
if(!s->budget--) { s->failed_pc=0x0c05a3a2u; return 0; }
r[4]=r[14];
goto P_0c05a3a4;
P_0c05a3a4: /* original 0e83, guest PC 0x0c05a3a4 */
if(!s->budget--) { s->failed_pc=0x0c05a3a4u; return 0; }
if((r[14]&0xFC000000u)==0xE0000000u) pref(ram,r[14]);
goto P_0c05a3a6;
P_0c05a3a6: /* original a0a5, guest PC 0x0c05a3a6 */
if(!s->budget--) { s->failed_pc=0x0c05a3a6u; return 0; }
goto P_0c05a4f4;
P_0c05a3a8: /* original 0009, guest PC 0x0c05a3a8 */
if(!s->budget--) { s->failed_pc=0x0c05a3a8u; return 0; }
goto P_0c05a3aa;
P_0c05a3aa: /* original d34d, guest PC 0x0c05a3aa */
if(!s->budget--) { s->failed_pc=0x0c05a3aau; return 0; }
r[3]=read(ram,0x0c05a4e0u,4);
goto P_0c05a3ac;
P_0c05a3ac: /* original 430b, guest PC 0x0c05a3ac */
if(!s->budget--) { s->failed_pc=0x0c05a3acu; return 0; }
target=r[3];
r[16]=code_base|0x0c05a3b0u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a3b0u) { target=s->pc; goto dispatch; }
goto P_0c05a3b0;
P_0c05a3ae: /* original 0009, guest PC 0x0c05a3ae */
if(!s->budget--) { s->failed_pc=0x0c05a3aeu; return 0; }
goto P_0c05a3b0;
P_0c05a3b0: /* original e200, guest PC 0x0c05a3b0 */
if(!s->budget--) { s->failed_pc=0x0c05a3b0u; return 0; }
r[2]=0x00000000u;
goto P_0c05a3b2;
P_0c05a3b2: /* original 63f3, guest PC 0x0c05a3b2 */
if(!s->budget--) { s->failed_pc=0x0c05a3b2u; return 0; }
r[3]=r[15];
goto P_0c05a3b4;
P_0c05a3b4: /* original 1f21, guest PC 0x0c05a3b4 */
if(!s->budget--) { s->failed_pc=0x0c05a3b4u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c05a3b6;
P_0c05a3b6: /* original 7310, guest PC 0x0c05a3b6 */
if(!s->budget--) { s->failed_pc=0x0c05a3b6u; return 0; }
r[3]+=0x00000010u;
goto P_0c05a3b8;
P_0c05a3b8: /* original a097, guest PC 0x0c05a3b8 */
if(!s->budget--) { s->failed_pc=0x0c05a3b8u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05a4ea;
P_0c05a3ba: /* original 1f32, guest PC 0x0c05a3ba */
if(!s->budget--) { s->failed_pc=0x0c05a3bau; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c05a3bc;
P_0c05a3bc: /* original 50f1, guest PC 0x0c05a3bc */
if(!s->budget--) { s->failed_pc=0x0c05a3bcu; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c05a3be;
P_0c05a3be: /* original 4008, guest PC 0x0c05a3be */
if(!s->budget--) { s->failed_pc=0x0c05a3beu; return 0; }
r[0]<<=2;
goto P_0c05a3c0;
P_0c05a3c0: /* original 2f02, guest PC 0x0c05a3c0 */
if(!s->budget--) { s->failed_pc=0x0c05a3c0u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c05a3c2;
P_0c05a3c2: /* original 03ee, guest PC 0x0c05a3c2 */
if(!s->budget--) { s->failed_pc=0x0c05a3c2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a3c4;
P_0c05a3c4: /* original 62a2, guest PC 0x0c05a3c4 */
if(!s->budget--) { s->failed_pc=0x0c05a3c4u; return 0; }
tmp=read(ram,r[10],4);
r[2]=tmp;
goto P_0c05a3c6;
P_0c05a3c6: /* original 012e, guest PC 0x0c05a3c6 */
if(!s->budget--) { s->failed_pc=0x0c05a3c6u; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c05a3c8;
P_0c05a3c8: /* original 62f3, guest PC 0x0c05a3c8 */
if(!s->budget--) { s->failed_pc=0x0c05a3c8u; return 0; }
r[2]=r[15];
goto P_0c05a3ca;
P_0c05a3ca: /* original 7244, guest PC 0x0c05a3ca */
if(!s->budget--) { s->failed_pc=0x0c05a3cau; return 0; }
r[2]+=0x00000044u;
goto P_0c05a3cc;
P_0c05a3cc: /* original 022e, guest PC 0x0c05a3cc */
if(!s->budget--) { s->failed_pc=0x0c05a3ccu; return 0; }
r[2]=read(ram,r[2]+r[0],4);
goto P_0c05a3ce;
P_0c05a3ce: /* original 6222, guest PC 0x0c05a3ce */
if(!s->budget--) { s->failed_pc=0x0c05a3ceu; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c05a3d0;
P_0c05a3d0: /* original 3128, guest PC 0x0c05a3d0 */
if(!s->budget--) { s->failed_pc=0x0c05a3d0u; return 0; }
r[1]-=r[2];
goto P_0c05a3d2;
P_0c05a3d2: /* original d23a, guest PC 0x0c05a3d2 */
if(!s->budget--) { s->failed_pc=0x0c05a3d2u; return 0; }
r[2]=read(ram,0x0c05a4bcu,4);
goto P_0c05a3d4;
P_0c05a3d4: /* original 420b, guest PC 0x0c05a3d4 */
if(!s->budget--) { s->failed_pc=0x0c05a3d4u; return 0; }
target=r[2];
r[16]=code_base|0x0c05a3d8u;
r[0]=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a3d8u) { target=s->pc; goto dispatch; }
goto P_0c05a3d8;
P_0c05a3d6: /* original e004, guest PC 0x0c05a3d6 */
if(!s->budget--) { s->failed_pc=0x0c05a3d6u; return 0; }
r[0]=0x00000004u;
goto P_0c05a3d8;
P_0c05a3d8: /* original d539, guest PC 0x0c05a3d8 */
if(!s->budget--) { s->failed_pc=0x0c05a3d8u; return 0; }
r[5]=read(ram,0x0c05a4c0u,4);
goto P_0c05a3da;
P_0c05a3da: /* original 4008, guest PC 0x0c05a3da */
if(!s->budget--) { s->failed_pc=0x0c05a3dau; return 0; }
r[0]<<=2;
goto P_0c05a3dc;
P_0c05a3dc: /* original 2302, guest PC 0x0c05a3dc */
if(!s->budget--) { s->failed_pc=0x0c05a3dcu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c05a3de;
P_0c05a3de: /* original e604, guest PC 0x0c05a3de */
if(!s->budget--) { s->failed_pc=0x0c05a3deu; return 0; }
r[6]=0x00000004u;
goto P_0c05a3e0;
P_0c05a3e0: /* original 63a2, guest PC 0x0c05a3e0 */
if(!s->budget--) { s->failed_pc=0x0c05a3e0u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c05a3e2;
P_0c05a3e2: /* original 60f2, guest PC 0x0c05a3e2 */
if(!s->budget--) { s->failed_pc=0x0c05a3e2u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a3e4;
P_0c05a3e4: /* original 4d0b, guest PC 0x0c05a3e4 */
if(!s->budget--) { s->failed_pc=0x0c05a3e4u; return 0; }
target=r[13];
r[16]=code_base|0x0c05a3e8u;
r[4]=read(ram,r[3]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a3e8u) { target=s->pc; goto dispatch; }
goto P_0c05a3e8;
P_0c05a3e6: /* original 043e, guest PC 0x0c05a3e6 */
if(!s->budget--) { s->failed_pc=0x0c05a3e6u; return 0; }
r[4]=read(ram,r[3]+r[0],4);
goto P_0c05a3e8;
P_0c05a3e8: /* original 63a2, guest PC 0x0c05a3e8 */
if(!s->budget--) { s->failed_pc=0x0c05a3e8u; return 0; }
tmp=read(ram,r[10],4);
r[3]=tmp;
goto P_0c05a3ea;
P_0c05a3ea: /* original 61b3, guest PC 0x0c05a3ea */
if(!s->budget--) { s->failed_pc=0x0c05a3eau; return 0; }
r[1]=r[11];
goto P_0c05a3ec;
P_0c05a3ec: /* original 60f2, guest PC 0x0c05a3ec */
if(!s->budget--) { s->failed_pc=0x0c05a3ecu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a3ee;
P_0c05a3ee: /* original 023e, guest PC 0x0c05a3ee */
if(!s->budget--) { s->failed_pc=0x0c05a3eeu; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c05a3f0;
P_0c05a3f0: /* original 7220, guest PC 0x0c05a3f0 */
if(!s->budget--) { s->failed_pc=0x0c05a3f0u; return 0; }
r[2]+=0x00000020u;
goto P_0c05a3f2;
P_0c05a3f2: /* original 0326, guest PC 0x0c05a3f2 */
if(!s->budget--) { s->failed_pc=0x0c05a3f2u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05a3f4;
P_0c05a3f4: /* original 53f1, guest PC 0x0c05a3f4 */
if(!s->budget--) { s->failed_pc=0x0c05a3f4u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05a3f6;
P_0c05a3f6: /* original 413c, guest PC 0x0c05a3f6 */
if(!s->budget--) { s->failed_pc=0x0c05a3f6u; return 0; }
r[1]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[1]>>((-r[3])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[3]&31u);
goto P_0c05a3f8;
P_0c05a3f8: /* original d02f, guest PC 0x0c05a3f8 */
if(!s->budget--) { s->failed_pc=0x0c05a3f8u; return 0; }
r[0]=read(ram,0x0c05a4b8u,4);
goto P_0c05a3fa;
P_0c05a3fa: /* original 6202, guest PC 0x0c05a3fa */
if(!s->budget--) { s->failed_pc=0x0c05a3fau; return 0; }
tmp=read(ram,r[0],4);
r[2]=tmp;
goto P_0c05a3fc;
P_0c05a3fc: /* original 2128, guest PC 0x0c05a3fc */
if(!s->budget--) { s->failed_pc=0x0c05a3fcu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c05a3fe;
P_0c05a3fe: /* original 8b02, guest PC 0x0c05a3fe */
if(!s->budget--) { s->failed_pc=0x0c05a3feu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a406; }
goto P_0c05a400;
P_0c05a400: /* original 60f2, guest PC 0x0c05a400 */
if(!s->budget--) { s->failed_pc=0x0c05a400u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a402;
P_0c05a402: /* original 02ee, guest PC 0x0c05a402 */
if(!s->budget--) { s->failed_pc=0x0c05a402u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05a404;
P_0c05a404: /* original 2292, guest PC 0x0c05a404 */
if(!s->budget--) { s->failed_pc=0x0c05a404u; return 0; }
write(ram,r[2],r[9],4);
goto P_0c05a406;
P_0c05a406: /* original 62b3, guest PC 0x0c05a406 */
if(!s->budget--) { s->failed_pc=0x0c05a406u; return 0; }
r[2]=r[11];
goto P_0c05a408;
P_0c05a408: /* original d02b, guest PC 0x0c05a408 */
if(!s->budget--) { s->failed_pc=0x0c05a408u; return 0; }
r[0]=read(ram,0x0c05a4b8u,4);
goto P_0c05a40a;
P_0c05a40a: /* original 53f1, guest PC 0x0c05a40a */
if(!s->budget--) { s->failed_pc=0x0c05a40au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05a40c;
P_0c05a40c: /* original 423c, guest PC 0x0c05a40c */
if(!s->budget--) { s->failed_pc=0x0c05a40cu; return 0; }
r[2]=(r[3]&0x80000000u)?((r[3]&31u)?(uint32_t)((int32_t)r[2]>>((-r[3])&31u)):((int32_t)r[2]<0?0xffffffffu:0)):r[2]<<(r[3]&31u);
goto P_0c05a40e;
P_0c05a40e: /* original 6102, guest PC 0x0c05a40e */
if(!s->budget--) { s->failed_pc=0x0c05a40eu; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05a410;
P_0c05a410: /* original 2218, guest PC 0x0c05a410 */
if(!s->budget--) { s->failed_pc=0x0c05a410u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[1])==0)!=0);
goto P_0c05a412;
P_0c05a412: /* original 8967, guest PC 0x0c05a412 */
if(!s->budget--) { s->failed_pc=0x0c05a412u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a4e4; }
goto P_0c05a414;
P_0c05a414: /* original 60f2, guest PC 0x0c05a414 */
if(!s->budget--) { s->failed_pc=0x0c05a414u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a416;
P_0c05a416: /* original 02ee, guest PC 0x0c05a416 */
if(!s->budget--) { s->failed_pc=0x0c05a416u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05a418;
P_0c05a418: /* original 61f2, guest PC 0x0c05a418 */
if(!s->budget--) { s->failed_pc=0x0c05a418u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c05a41a;
P_0c05a41a: /* original d02a, guest PC 0x0c05a41a */
if(!s->budget--) { s->failed_pc=0x0c05a41au; return 0; }
r[0]=read(ram,0x0c05a4c4u,4);
goto P_0c05a41c;
P_0c05a41c: /* original 6222, guest PC 0x0c05a41c */
if(!s->budget--) { s->failed_pc=0x0c05a41cu; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c05a41e;
P_0c05a41e: /* original 001e, guest PC 0x0c05a41e */
if(!s->budget--) { s->failed_pc=0x0c05a41eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c05a420;
P_0c05a420: /* original 3206, guest PC 0x0c05a420 */
if(!s->budget--) { s->failed_pc=0x0c05a420u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[0])!=0);
goto P_0c05a422;
P_0c05a422: /* original 8b06, guest PC 0x0c05a422 */
if(!s->budget--) { s->failed_pc=0x0c05a422u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a432; }
goto P_0c05a424;
P_0c05a424: /* original 63f2, guest PC 0x0c05a424 */
if(!s->budget--) { s->failed_pc=0x0c05a424u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c05a426;
P_0c05a426: /* original 6033, guest PC 0x0c05a426 */
if(!s->budget--) { s->failed_pc=0x0c05a426u; return 0; }
r[0]=r[3];
goto P_0c05a428;
P_0c05a428: /* original 0009, guest PC 0x0c05a428 */
if(!s->budget--) { s->failed_pc=0x0c05a428u; return 0; }
goto P_0c05a42a;
P_0c05a42a: /* original 02ee, guest PC 0x0c05a42a */
if(!s->budget--) { s->failed_pc=0x0c05a42au; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c05a42c;
P_0c05a42c: /* original d025, guest PC 0x0c05a42c */
if(!s->budget--) { s->failed_pc=0x0c05a42cu; return 0; }
r[0]=read(ram,0x0c05a4c4u,4);
goto P_0c05a42e;
P_0c05a42e: /* original 6222, guest PC 0x0c05a42e */
if(!s->budget--) { s->failed_pc=0x0c05a42eu; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c05a430;
P_0c05a430: /* original 0326, guest PC 0x0c05a430 */
if(!s->budget--) { s->failed_pc=0x0c05a430u; return 0; }
write(ram,r[3]+r[0],r[2],4);
goto P_0c05a432;
P_0c05a432: /* original 60f2, guest PC 0x0c05a432 */
if(!s->budget--) { s->failed_pc=0x0c05a432u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a434;
P_0c05a434: /* original 62f2, guest PC 0x0c05a434 */
if(!s->budget--) { s->failed_pc=0x0c05a434u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c05a436;
P_0c05a436: /* original 03ee, guest PC 0x0c05a436 */
if(!s->budget--) { s->failed_pc=0x0c05a436u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a438;
P_0c05a438: /* original d023, guest PC 0x0c05a438 */
if(!s->budget--) { s->failed_pc=0x0c05a438u; return 0; }
r[0]=read(ram,0x0c05a4c8u,4);
goto P_0c05a43a;
P_0c05a43a: /* original 012e, guest PC 0x0c05a43a */
if(!s->budget--) { s->failed_pc=0x0c05a43au; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c05a43c;
P_0c05a43c: /* original 6332, guest PC 0x0c05a43c */
if(!s->budget--) { s->failed_pc=0x0c05a43cu; return 0; }
tmp=read(ram,r[3],4);
r[3]=tmp;
goto P_0c05a43e;
P_0c05a43e: /* original 3316, guest PC 0x0c05a43e */
if(!s->budget--) { s->failed_pc=0x0c05a43eu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[1])!=0);
goto P_0c05a440;
P_0c05a440: /* original 8b50, guest PC 0x0c05a440 */
if(!s->budget--) { s->failed_pc=0x0c05a440u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a4e4; }
goto P_0c05a442;
P_0c05a442: /* original ea00, guest PC 0x0c05a442 */
if(!s->budget--) { s->failed_pc=0x0c05a442u; return 0; }
r[10]=0x00000000u;
goto P_0c05a444;
P_0c05a444: /* original d01c, guest PC 0x0c05a444 */
if(!s->budget--) { s->failed_pc=0x0c05a444u; return 0; }
r[0]=read(ram,0x0c05a4b8u,4);
goto P_0c05a446;
P_0c05a446: /* original 62a3, guest PC 0x0c05a446 */
if(!s->budget--) { s->failed_pc=0x0c05a446u; return 0; }
r[2]=r[10];
goto P_0c05a448;
P_0c05a448: /* original 4208, guest PC 0x0c05a448 */
if(!s->budget--) { s->failed_pc=0x0c05a448u; return 0; }
r[2]<<=2;
goto P_0c05a44a;
P_0c05a44a: /* original 63b3, guest PC 0x0c05a44a */
if(!s->budget--) { s->failed_pc=0x0c05a44au; return 0; }
r[3]=r[11];
goto P_0c05a44c;
P_0c05a44c: /* original 2f22, guest PC 0x0c05a44c */
if(!s->budget--) { s->failed_pc=0x0c05a44cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c05a44e;
P_0c05a44e: /* original 43ac, guest PC 0x0c05a44e */
if(!s->budget--) { s->failed_pc=0x0c05a44eu; return 0; }
r[3]=(r[10]&0x80000000u)?((r[10]&31u)?(uint32_t)((int32_t)r[3]>>((-r[10])&31u)):((int32_t)r[3]<0?0xffffffffu:0)):r[3]<<(r[10]&31u);
goto P_0c05a450;
P_0c05a450: /* original 6102, guest PC 0x0c05a450 */
if(!s->budget--) { s->failed_pc=0x0c05a450u; return 0; }
tmp=read(ram,r[0],4);
r[1]=tmp;
goto P_0c05a452;
P_0c05a452: /* original 2318, guest PC 0x0c05a452 */
if(!s->budget--) { s->failed_pc=0x0c05a452u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[1])==0)!=0);
goto P_0c05a454;
P_0c05a454: /* original 8921, guest PC 0x0c05a454 */
if(!s->budget--) { s->failed_pc=0x0c05a454u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a49a; }
goto P_0c05a456;
P_0c05a456: /* original 53f2, guest PC 0x0c05a456 */
if(!s->budget--) { s->failed_pc=0x0c05a456u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c05a458;
P_0c05a458: /* original 6133, guest PC 0x0c05a458 */
if(!s->budget--) { s->failed_pc=0x0c05a458u; return 0; }
r[1]=r[3];
goto P_0c05a45a;
P_0c05a45a: /* original 6112, guest PC 0x0c05a45a */
if(!s->budget--) { s->failed_pc=0x0c05a45au; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c05a45c;
P_0c05a45c: /* original 2189, guest PC 0x0c05a45c */
if(!s->budget--) { s->failed_pc=0x0c05a45cu; return 0; }
r[1]&=r[8];
goto P_0c05a45e;
P_0c05a45e: /* original 60a3, guest PC 0x0c05a45e */
if(!s->budget--) { s->failed_pc=0x0c05a45eu; return 0; }
r[0]=r[10];
goto P_0c05a460;
P_0c05a460: /* original 0009, guest PC 0x0c05a460 */
if(!s->budget--) { s->failed_pc=0x0c05a460u; return 0; }
goto P_0c05a462;
P_0c05a462: /* original 4028, guest PC 0x0c05a462 */
if(!s->budget--) { s->failed_pc=0x0c05a462u; return 0; }
r[0]<<=16;
goto P_0c05a464;
P_0c05a464: /* original 4018, guest PC 0x0c05a464 */
if(!s->budget--) { s->failed_pc=0x0c05a464u; return 0; }
r[0]<<=8;
goto P_0c05a466;
P_0c05a466: /* original 210b, guest PC 0x0c05a466 */
if(!s->budget--) { s->failed_pc=0x0c05a466u; return 0; }
r[1]|=r[0];
goto P_0c05a468;
P_0c05a468: /* original 2312, guest PC 0x0c05a468 */
if(!s->budget--) { s->failed_pc=0x0c05a468u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c05a46a;
P_0c05a46a: /* original e620, guest PC 0x0c05a46a */
if(!s->budget--) { s->failed_pc=0x0c05a46au; return 0; }
r[6]=0x00000020u;
goto P_0c05a46c;
P_0c05a46c: /* original 64f2, guest PC 0x0c05a46c */
if(!s->budget--) { s->failed_pc=0x0c05a46cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c05a46e;
P_0c05a46e: /* original 65f3, guest PC 0x0c05a46e */
if(!s->budget--) { s->failed_pc=0x0c05a46eu; return 0; }
r[5]=r[15];
goto P_0c05a470;
P_0c05a470: /* original 7510, guest PC 0x0c05a470 */
if(!s->budget--) { s->failed_pc=0x0c05a470u; return 0; }
r[5]+=0x00000010u;
goto P_0c05a472;
P_0c05a472: /* original 63f3, guest PC 0x0c05a472 */
if(!s->budget--) { s->failed_pc=0x0c05a472u; return 0; }
r[3]=r[15];
goto P_0c05a474;
P_0c05a474: /* original 7344, guest PC 0x0c05a474 */
if(!s->budget--) { s->failed_pc=0x0c05a474u; return 0; }
r[3]+=0x00000044u;
goto P_0c05a476;
P_0c05a476: /* original 343c, guest PC 0x0c05a476 */
if(!s->budget--) { s->failed_pc=0x0c05a476u; return 0; }
r[4]+=r[3];
goto P_0c05a478;
P_0c05a478: /* original 1f41, guest PC 0x0c05a478 */
if(!s->budget--) { s->failed_pc=0x0c05a478u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c05a47a;
P_0c05a47a: /* original 6442, guest PC 0x0c05a47a */
if(!s->budget--) { s->failed_pc=0x0c05a47au; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a47c;
P_0c05a47c: /* original 4d0b, guest PC 0x0c05a47c */
if(!s->budget--) { s->failed_pc=0x0c05a47cu; return 0; }
target=r[13];
r[16]=code_base|0x0c05a480u;
tmp=read(ram,r[4],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a480u) { target=s->pc; goto dispatch; }
goto P_0c05a480;
P_0c05a47e: /* original 6442, guest PC 0x0c05a47e */
if(!s->budget--) { s->failed_pc=0x0c05a47eu; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a480;
P_0c05a480: /* original d50f, guest PC 0x0c05a480 */
if(!s->budget--) { s->failed_pc=0x0c05a480u; return 0; }
r[5]=read(ram,0x0c05a4c0u,4);
goto P_0c05a482;
P_0c05a482: /* original e604, guest PC 0x0c05a482 */
if(!s->budget--) { s->failed_pc=0x0c05a482u; return 0; }
r[6]=0x00000004u;
goto P_0c05a484;
P_0c05a484: /* original 54f1, guest PC 0x0c05a484 */
if(!s->budget--) { s->failed_pc=0x0c05a484u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c05a486;
P_0c05a486: /* original 6442, guest PC 0x0c05a486 */
if(!s->budget--) { s->failed_pc=0x0c05a486u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a488;
P_0c05a488: /* original 6442, guest PC 0x0c05a488 */
if(!s->budget--) { s->failed_pc=0x0c05a488u; return 0; }
tmp=read(ram,r[4],4);
r[4]=tmp;
goto P_0c05a48a;
P_0c05a48a: /* original 4d0b, guest PC 0x0c05a48a */
if(!s->budget--) { s->failed_pc=0x0c05a48au; return 0; }
target=r[13];
r[16]=code_base|0x0c05a48eu;
r[4]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a48eu) { target=s->pc; goto dispatch; }
goto P_0c05a48e;
P_0c05a48c: /* original 7420, guest PC 0x0c05a48c */
if(!s->budget--) { s->failed_pc=0x0c05a48cu; return 0; }
r[4]+=0x00000020u;
goto P_0c05a48e;
P_0c05a48e: /* original e220, guest PC 0x0c05a48e */
if(!s->budget--) { s->failed_pc=0x0c05a48eu; return 0; }
r[2]=0x00000020u;
goto P_0c05a490;
P_0c05a490: /* original 60f2, guest PC 0x0c05a490 */
if(!s->budget--) { s->failed_pc=0x0c05a490u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c05a492;
P_0c05a492: /* original 03ee, guest PC 0x0c05a492 */
if(!s->budget--) { s->failed_pc=0x0c05a492u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c05a494;
P_0c05a494: /* original 2322, guest PC 0x0c05a494 */
if(!s->budget--) { s->failed_pc=0x0c05a494u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c05a496;
P_0c05a496: /* original a003, guest PC 0x0c05a496 */
if(!s->budget--) { s->failed_pc=0x0c05a496u; return 0; }
goto P_0c05a4a0;
P_0c05a498: /* original 0009, guest PC 0x0c05a498 */
if(!s->budget--) { s->failed_pc=0x0c05a498u; return 0; }
goto P_0c05a49a;
P_0c05a49a: /* original 32ec, guest PC 0x0c05a49a */
if(!s->budget--) { s->failed_pc=0x0c05a49au; return 0; }
r[2]+=r[14];
goto P_0c05a49c;
P_0c05a49c: /* original 6122, guest PC 0x0c05a49c */
if(!s->budget--) { s->failed_pc=0x0c05a49cu; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c05a49e;
P_0c05a49e: /* original 2192, guest PC 0x0c05a49e */
if(!s->budget--) { s->failed_pc=0x0c05a49eu; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05a4a0;
P_0c05a4a0: /* original 7a01, guest PC 0x0c05a4a0 */
if(!s->budget--) { s->failed_pc=0x0c05a4a0u; return 0; }
r[10]+=0x00000001u;
goto P_0c05a4a2;
P_0c05a4a2: /* original 3ac3, guest PC 0x0c05a4a2 */
if(!s->budget--) { s->failed_pc=0x0c05a4a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[10]>=(int32_t)r[12])!=0);
goto P_0c05a4a4;
P_0c05a4a4: /* original 8bce, guest PC 0x0c05a4a4 */
if(!s->budget--) { s->failed_pc=0x0c05a4a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c05a444; }
goto P_0c05a4a6;
P_0c05a4a6: /* original d209, guest PC 0x0c05a4a6 */
if(!s->budget--) { s->failed_pc=0x0c05a4a6u; return 0; }
r[2]=read(ram,0x0c05a4ccu,4);
goto P_0c05a4a8;
P_0c05a4a8: /* original 420b, guest PC 0x0c05a4a8 */
if(!s->budget--) { s->failed_pc=0x0c05a4a8u; return 0; }
target=r[2];
r[16]=code_base|0x0c05a4acu;
r[4]=0x00000002u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a4acu) { target=s->pc; goto dispatch; }
goto P_0c05a4ac;
P_0c05a4aa: /* original e402, guest PC 0x0c05a4aa */
if(!s->budget--) { s->failed_pc=0x0c05a4aau; return 0; }
r[4]=0x00000002u;
goto P_0c05a4ac;
P_0c05a4ac: /* original a022, guest PC 0x0c05a4ac */
if(!s->budget--) { s->failed_pc=0x0c05a4acu; return 0; }
goto P_0c05a4f4;
P_0c05a4ae: /* original 0009, guest PC 0x0c05a4ae */
if(!s->budget--) { s->failed_pc=0x0c05a4aeu; return 0; }
if(!vf3_matrix_family(0x0c05a4b0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05a4b0u; return 0; } return 1;
P_0c05a4e4: /* original 52f1, guest PC 0x0c05a4e4 */
if(!s->budget--) { s->failed_pc=0x0c05a4e4u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c05a4e6;
P_0c05a4e6: /* original 7201, guest PC 0x0c05a4e6 */
if(!s->budget--) { s->failed_pc=0x0c05a4e6u; return 0; }
r[2]+=0x00000001u;
goto P_0c05a4e8;
P_0c05a4e8: /* original 1f21, guest PC 0x0c05a4e8 */
if(!s->budget--) { s->failed_pc=0x0c05a4e8u; return 0; }
write(ram,r[15]+4,r[2],4);
goto P_0c05a4ea;
P_0c05a4ea: /* original 53f1, guest PC 0x0c05a4ea */
if(!s->budget--) { s->failed_pc=0x0c05a4eau; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c05a4ec;
P_0c05a4ec: /* original 33c3, guest PC 0x0c05a4ec */
if(!s->budget--) { s->failed_pc=0x0c05a4ecu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[12])!=0);
goto P_0c05a4ee;
P_0c05a4ee: /* original 8901, guest PC 0x0c05a4ee */
if(!s->budget--) { s->failed_pc=0x0c05a4eeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c05a4f4; }
goto P_0c05a4f0;
P_0c05a4f0: /* original af64, guest PC 0x0c05a4f0 */
if(!s->budget--) { s->failed_pc=0x0c05a4f0u; return 0; }
goto P_0c05a3bc;
P_0c05a4f2: /* original 0009, guest PC 0x0c05a4f2 */
if(!s->budget--) { s->failed_pc=0x0c05a4f2u; return 0; }
goto P_0c05a4f4;
P_0c05a4f4: /* original d161, guest PC 0x0c05a4f4 */
if(!s->budget--) { s->failed_pc=0x0c05a4f4u; return 0; }
r[1]=read(ram,0x0c05a67cu,4);
goto P_0c05a4f6;
P_0c05a4f6: /* original bc3c, guest PC 0x0c05a4f6 */
if(!s->budget--) { s->failed_pc=0x0c05a4f6u; return 0; }
target=code_base|0x0c059d72u; r[16]=code_base|0x0c05a4fau;
write(ram,r[1],r[9],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a4fau) { target=s->pc; goto dispatch; }
goto P_0c05a4fa;
P_0c05a4f8: /* original 2192, guest PC 0x0c05a4f8 */
if(!s->budget--) { s->failed_pc=0x0c05a4f8u; return 0; }
write(ram,r[1],r[9],4);
goto P_0c05a4fa;
P_0c05a4fa: /* original d261, guest PC 0x0c05a4fa */
if(!s->budget--) { s->failed_pc=0x0c05a4fau; return 0; }
r[2]=read(ram,0x0c05a680u,4);
goto P_0c05a4fc;
P_0c05a4fc: /* original d361, guest PC 0x0c05a4fc */
if(!s->budget--) { s->failed_pc=0x0c05a4fcu; return 0; }
r[3]=read(ram,0x0c05a684u,4);
goto P_0c05a4fe;
P_0c05a4fe: /* original 430b, guest PC 0x0c05a4fe */
if(!s->budget--) { s->failed_pc=0x0c05a4feu; return 0; }
target=r[3];
r[16]=code_base|0x0c05a502u;
tmp=read(ram,r[2],4);
r[4]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c05a502u) { target=s->pc; goto dispatch; }
goto P_0c05a502;
P_0c05a500: /* original 6422, guest PC 0x0c05a500 */
if(!s->budget--) { s->failed_pc=0x0c05a500u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c05a502;
P_0c05a502: /* original e000, guest PC 0x0c05a502 */
if(!s->budget--) { s->failed_pc=0x0c05a502u; return 0; }
r[0]=0x00000000u;
goto P_0c05a504;
P_0c05a504: /* original 7f58, guest PC 0x0c05a504 */
if(!s->budget--) { s->failed_pc=0x0c05a504u; return 0; }
r[15]+=0x00000058u;
goto P_0c05a506;
P_0c05a506: /* original 4f26, guest PC 0x0c05a506 */
if(!s->budget--) { s->failed_pc=0x0c05a506u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c05a508;
P_0c05a508: /* original 68f6, guest PC 0x0c05a508 */
if(!s->budget--) { s->failed_pc=0x0c05a508u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c05a50a;
P_0c05a50a: /* original 69f6, guest PC 0x0c05a50a */
if(!s->budget--) { s->failed_pc=0x0c05a50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c05a50c;
P_0c05a50c: /* original 6af6, guest PC 0x0c05a50c */
if(!s->budget--) { s->failed_pc=0x0c05a50cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c05a50e;
P_0c05a50e: /* original 6bf6, guest PC 0x0c05a50e */
if(!s->budget--) { s->failed_pc=0x0c05a50eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c05a510;
P_0c05a510: /* original 6cf6, guest PC 0x0c05a510 */
if(!s->budget--) { s->failed_pc=0x0c05a510u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c05a512;
P_0c05a512: /* original 6df6, guest PC 0x0c05a512 */
if(!s->budget--) { s->failed_pc=0x0c05a512u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c05a514;
P_0c05a514: /* original 000b, guest PC 0x0c05a514 */
if(!s->budget--) { s->failed_pc=0x0c05a514u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c05a516: /* original 6ef6, guest PC 0x0c05a516 */
if(!s->budget--) { s->failed_pc=0x0c05a516u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c05a518u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c05a518u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
