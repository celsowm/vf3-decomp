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
int vf3_away_batch71_adapter_25(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c07b5f0u: goto P_0c07b5f0;
case 0x0c07b5f2u: goto P_0c07b5f2;
case 0x0c07b5f4u: goto P_0c07b5f4;
case 0x0c07b5f6u: goto P_0c07b5f6;
case 0x0c07b5f8u: goto P_0c07b5f8;
case 0x0c07b5fau: goto P_0c07b5fa;
case 0x0c07b5fcu: goto P_0c07b5fc;
case 0x0c07b5feu: goto P_0c07b5fe;
case 0x0c07b600u: goto P_0c07b600;
case 0x0c07b602u: goto P_0c07b602;
case 0x0c07b604u: goto P_0c07b604;
case 0x0c07b606u: goto P_0c07b606;
case 0x0c07b608u: goto P_0c07b608;
case 0x0c07b60au: goto P_0c07b60a;
case 0x0c07b60cu: goto P_0c07b60c;
case 0x0c07b60eu: goto P_0c07b60e;
case 0x0c07b610u: goto P_0c07b610;
case 0x0c07b612u: goto P_0c07b612;
case 0x0c07b614u: goto P_0c07b614;
case 0x0c07b616u: goto P_0c07b616;
case 0x0c07b618u: goto P_0c07b618;
case 0x0c07b61au: goto P_0c07b61a;
case 0x0c07b61cu: goto P_0c07b61c;
case 0x0c07b61eu: goto P_0c07b61e;
case 0x0c07b620u: goto P_0c07b620;
case 0x0c07b622u: goto P_0c07b622;
case 0x0c07b624u: goto P_0c07b624;
case 0x0c07b626u: goto P_0c07b626;
case 0x0c07b628u: goto P_0c07b628;
case 0x0c07b62au: goto P_0c07b62a;
case 0x0c07b62cu: goto P_0c07b62c;
case 0x0c07b62eu: goto P_0c07b62e;
case 0x0c07b630u: goto P_0c07b630;
case 0x0c07b632u: goto P_0c07b632;
case 0x0c07b634u: goto P_0c07b634;
case 0x0c07b636u: goto P_0c07b636;
case 0x0c07b638u: goto P_0c07b638;
case 0x0c07b63au: goto P_0c07b63a;
case 0x0c07b63cu: goto P_0c07b63c;
case 0x0c07b63eu: goto P_0c07b63e;
case 0x0c07b640u: goto P_0c07b640;
case 0x0c07b642u: goto P_0c07b642;
case 0x0c07b644u: goto P_0c07b644;
case 0x0c07b646u: goto P_0c07b646;
case 0x0c07b648u: goto P_0c07b648;
case 0x0c07b64au: goto P_0c07b64a;
case 0x0c07b64cu: goto P_0c07b64c;
case 0x0c07b64eu: goto P_0c07b64e;
case 0x0c07b650u: goto P_0c07b650;
case 0x0c07b652u: goto P_0c07b652;
case 0x0c07b654u: goto P_0c07b654;
case 0x0c07b656u: goto P_0c07b656;
case 0x0c07b658u: goto P_0c07b658;
case 0x0c07b65au: goto P_0c07b65a;
case 0x0c07b65cu: goto P_0c07b65c;
case 0x0c07b65eu: goto P_0c07b65e;
case 0x0c07b660u: goto P_0c07b660;
case 0x0c07b662u: goto P_0c07b662;
case 0x0c07b664u: goto P_0c07b664;
case 0x0c07b666u: goto P_0c07b666;
case 0x0c07b668u: goto P_0c07b668;
case 0x0c07b66au: goto P_0c07b66a;
case 0x0c07b66cu: goto P_0c07b66c;
case 0x0c08a068u: goto P_0c08a068;
case 0x0c08a06au: goto P_0c08a06a;
case 0x0c08a06cu: goto P_0c08a06c;
case 0x0c08a06eu: goto P_0c08a06e;
case 0x0c08a070u: goto P_0c08a070;
case 0x0c08a072u: goto P_0c08a072;
case 0x0c08a074u: goto P_0c08a074;
case 0x0c08a076u: goto P_0c08a076;
case 0x0c08a078u: goto P_0c08a078;
case 0x0c08a07au: goto P_0c08a07a;
case 0x0c08a07cu: goto P_0c08a07c;
case 0x0c08a07eu: goto P_0c08a07e;
case 0x0c08a080u: goto P_0c08a080;
case 0x0c08a082u: goto P_0c08a082;
case 0x0c08a084u: goto P_0c08a084;
case 0x0c08a086u: goto P_0c08a086;
case 0x0c08a088u: goto P_0c08a088;
case 0x0c08a08au: goto P_0c08a08a;
case 0x0c08a08cu: goto P_0c08a08c;
case 0x0c08a08eu: goto P_0c08a08e;
case 0x0c08a090u: goto P_0c08a090;
case 0x0c08a092u: goto P_0c08a092;
case 0x0c08a094u: goto P_0c08a094;
case 0x0c08a096u: goto P_0c08a096;
case 0x0c08a098u: goto P_0c08a098;
case 0x0c08a09au: goto P_0c08a09a;
case 0x0c08a09cu: goto P_0c08a09c;
case 0x0c08a09eu: goto P_0c08a09e;
case 0x0c08a0a0u: goto P_0c08a0a0;
case 0x0c08a0a2u: goto P_0c08a0a2;
case 0x0c08a0a4u: goto P_0c08a0a4;
case 0x0c08a0a6u: goto P_0c08a0a6;
case 0x0c08a0a8u: goto P_0c08a0a8;
case 0x0c08a0aau: goto P_0c08a0aa;
case 0x0c08a0acu: goto P_0c08a0ac;
case 0x0c08a0aeu: goto P_0c08a0ae;
case 0x0c08a0b0u: goto P_0c08a0b0;
case 0x0c08a0b2u: goto P_0c08a0b2;
case 0x0c08a0b4u: goto P_0c08a0b4;
case 0x0c08a0b6u: goto P_0c08a0b6;
case 0x0c08a0b8u: goto P_0c08a0b8;
case 0x0c08a0bau: goto P_0c08a0ba;
case 0x0c08a0bcu: goto P_0c08a0bc;
case 0x0c08a0beu: goto P_0c08a0be;
case 0x0c08a0c0u: goto P_0c08a0c0;
case 0x0c08a0c2u: goto P_0c08a0c2;
case 0x0c08a0c4u: goto P_0c08a0c4;
case 0x0c08a0c6u: goto P_0c08a0c6;
case 0x0c08a0c8u: goto P_0c08a0c8;
case 0x0c08a0cau: goto P_0c08a0ca;
case 0x0c08a0ccu: goto P_0c08a0cc;
case 0x0c08a0ceu: goto P_0c08a0ce;
case 0x0c08a0d0u: goto P_0c08a0d0;
case 0x0c08a0d2u: goto P_0c08a0d2;
case 0x0c08a0d4u: goto P_0c08a0d4;
case 0x0c08a0d6u: goto P_0c08a0d6;
case 0x0c08a0d8u: goto P_0c08a0d8;
case 0x0c08a0dau: goto P_0c08a0da;
case 0x0c08a0dcu: goto P_0c08a0dc;
case 0x0c08a0deu: goto P_0c08a0de;
case 0x0c08a0e0u: goto P_0c08a0e0;
case 0x0c08a0e2u: goto P_0c08a0e2;
case 0x0c08a0e4u: goto P_0c08a0e4;
case 0x0c08a0e6u: goto P_0c08a0e6;
case 0x0c08a0e8u: goto P_0c08a0e8;
case 0x0c08a0eau: goto P_0c08a0ea;
case 0x0c08a0ecu: goto P_0c08a0ec;
case 0x0c08a0eeu: goto P_0c08a0ee;
case 0x0c08a0f0u: goto P_0c08a0f0;
case 0x0c08a0f2u: goto P_0c08a0f2;
case 0x0c08a0f4u: goto P_0c08a0f4;
case 0x0c08a0f6u: goto P_0c08a0f6;
case 0x0c08a0f8u: goto P_0c08a0f8;
case 0x0c08a0fau: goto P_0c08a0fa;
case 0x0c08a0fcu: goto P_0c08a0fc;
case 0x0c08a0feu: goto P_0c08a0fe;
case 0x0c08a100u: goto P_0c08a100;
case 0x0c08a102u: goto P_0c08a102;
case 0x0c08a104u: goto P_0c08a104;
case 0x0c08a106u: goto P_0c08a106;
case 0x0c08a108u: goto P_0c08a108;
case 0x0c08a10au: goto P_0c08a10a;
case 0x0c08a10cu: goto P_0c08a10c;
case 0x0c08a10eu: goto P_0c08a10e;
case 0x0c08a110u: goto P_0c08a110;
case 0x0c08a112u: goto P_0c08a112;
case 0x0c08a114u: goto P_0c08a114;
case 0x0c08a116u: goto P_0c08a116;
case 0x0c08a118u: goto P_0c08a118;
case 0x0c08a11au: goto P_0c08a11a;
case 0x0c08a11cu: goto P_0c08a11c;
case 0x0c08a11eu: goto P_0c08a11e;
case 0x0c08a120u: goto P_0c08a120;
case 0x0c08a122u: goto P_0c08a122;
case 0x0c08a124u: goto P_0c08a124;
case 0x0c08a126u: goto P_0c08a126;
case 0x0c08a128u: goto P_0c08a128;
case 0x0c08a12au: goto P_0c08a12a;
case 0x0c08a12cu: goto P_0c08a12c;
case 0x0c08a12eu: goto P_0c08a12e;
case 0x0c08a130u: goto P_0c08a130;
case 0x0c08a132u: goto P_0c08a132;
case 0x0c08a134u: goto P_0c08a134;
case 0x0c08a136u: goto P_0c08a136;
case 0x0c08a138u: goto P_0c08a138;
case 0x0c08a13au: goto P_0c08a13a;
case 0x0c08a13cu: goto P_0c08a13c;
case 0x0c08a13eu: goto P_0c08a13e;
case 0x0c08a140u: goto P_0c08a140;
case 0x0c08a142u: goto P_0c08a142;
case 0x0c08a144u: goto P_0c08a144;
case 0x0c08a146u: goto P_0c08a146;
case 0x0c08a148u: goto P_0c08a148;
case 0x0c08a14au: goto P_0c08a14a;
case 0x0c08a14cu: goto P_0c08a14c;
case 0x0c08a14eu: goto P_0c08a14e;
case 0x0c08a150u: goto P_0c08a150;
case 0x0c08a152u: goto P_0c08a152;
case 0x0c08a154u: goto P_0c08a154;
case 0x0c08a156u: goto P_0c08a156;
case 0x0c08a158u: goto P_0c08a158;
case 0x0c08a15au: goto P_0c08a15a;
case 0x0c08a15cu: goto P_0c08a15c;
case 0x0c08a15eu: goto P_0c08a15e;
case 0x0c08a160u: goto P_0c08a160;
case 0x0c08a162u: goto P_0c08a162;
case 0x0c08a164u: goto P_0c08a164;
case 0x0c08a166u: goto P_0c08a166;
case 0x0c08a168u: goto P_0c08a168;
case 0x0c08a16au: goto P_0c08a16a;
case 0x0c08a16cu: goto P_0c08a16c;
case 0x0c08a16eu: goto P_0c08a16e;
case 0x0c08a170u: goto P_0c08a170;
case 0x0c08a172u: goto P_0c08a172;
case 0x0c08a174u: goto P_0c08a174;
case 0x0c08a176u: goto P_0c08a176;
case 0x0c08a178u: goto P_0c08a178;
case 0x0c08a17au: goto P_0c08a17a;
case 0x0c08a17cu: goto P_0c08a17c;
case 0x0c08a17eu: goto P_0c08a17e;
case 0x0c08a180u: goto P_0c08a180;
case 0x0c08a182u: goto P_0c08a182;
case 0x0c08a184u: goto P_0c08a184;
case 0x0c08a186u: goto P_0c08a186;
case 0x0c08a188u: goto P_0c08a188;
case 0x0c08a18au: goto P_0c08a18a;
case 0x0c08a18cu: goto P_0c08a18c;
case 0x0c08a18eu: goto P_0c08a18e;
case 0x0c08a190u: goto P_0c08a190;
case 0x0c08a192u: goto P_0c08a192;
case 0x0c08a194u: goto P_0c08a194;
case 0x0c08a196u: goto P_0c08a196;
case 0x0c08a198u: goto P_0c08a198;
case 0x0c08a19au: goto P_0c08a19a;
case 0x0c08a19cu: goto P_0c08a19c;
case 0x0c08a19eu: goto P_0c08a19e;
case 0x0c08a1a0u: goto P_0c08a1a0;
case 0x0c08a1a2u: goto P_0c08a1a2;
case 0x0c08a1a4u: goto P_0c08a1a4;
case 0x0c08a1a6u: goto P_0c08a1a6;
case 0x0c08a1a8u: goto P_0c08a1a8;
case 0x0c08a1aau: goto P_0c08a1aa;
case 0x0c08a1acu: goto P_0c08a1ac;
case 0x0c08a1aeu: goto P_0c08a1ae;
case 0x0c08a1b0u: goto P_0c08a1b0;
case 0x0c08a1b2u: goto P_0c08a1b2;
case 0x0c08a1b4u: goto P_0c08a1b4;
case 0x0c08a1b6u: goto P_0c08a1b6;
case 0x0c08a1b8u: goto P_0c08a1b8;
case 0x0c08a1bau: goto P_0c08a1ba;
case 0x0c08a1bcu: goto P_0c08a1bc;
case 0x0c08a1beu: goto P_0c08a1be;
case 0x0c08a1c0u: goto P_0c08a1c0;
case 0x0c08a1c2u: goto P_0c08a1c2;
case 0x0c08a1c4u: goto P_0c08a1c4;
case 0x0c08a1c6u: goto P_0c08a1c6;
case 0x0c08a1c8u: goto P_0c08a1c8;
case 0x0c08a1cau: goto P_0c08a1ca;
case 0x0c08a1ccu: goto P_0c08a1cc;
case 0x0c08a1ceu: goto P_0c08a1ce;
case 0x0c08a1d0u: goto P_0c08a1d0;
case 0x0c08a1d2u: goto P_0c08a1d2;
case 0x0c08a1d4u: goto P_0c08a1d4;
case 0x0c08a1d6u: goto P_0c08a1d6;
case 0x0c08a1d8u: goto P_0c08a1d8;
case 0x0c08a1dau: goto P_0c08a1da;
case 0x0c08a1dcu: goto P_0c08a1dc;
case 0x0c08a23cu: goto P_0c08a23c;
case 0x0c08a23eu: goto P_0c08a23e;
case 0x0c08a240u: goto P_0c08a240;
case 0x0c08a242u: goto P_0c08a242;
case 0x0c08a244u: goto P_0c08a244;
case 0x0c08a246u: goto P_0c08a246;
case 0x0c08a248u: goto P_0c08a248;
case 0x0c08a24au: goto P_0c08a24a;
case 0x0c08a24cu: goto P_0c08a24c;
case 0x0c08a24eu: goto P_0c08a24e;
case 0x0c08a250u: goto P_0c08a250;
case 0x0c08a252u: goto P_0c08a252;
case 0x0c08a254u: goto P_0c08a254;
case 0x0c08a256u: goto P_0c08a256;
case 0x0c08a258u: goto P_0c08a258;
case 0x0c08a25au: goto P_0c08a25a;
case 0x0c08a25cu: goto P_0c08a25c;
case 0x0c08a25eu: goto P_0c08a25e;
case 0x0c08a260u: goto P_0c08a260;
case 0x0c08a262u: goto P_0c08a262;
case 0x0c08a264u: goto P_0c08a264;
case 0x0c08a266u: goto P_0c08a266;
case 0x0c08a268u: goto P_0c08a268;
case 0x0c08a26au: goto P_0c08a26a;
case 0x0c08a26cu: goto P_0c08a26c;
case 0x0c08a26eu: goto P_0c08a26e;
case 0x0c08a270u: goto P_0c08a270;
case 0x0c08a272u: goto P_0c08a272;
case 0x0c08a274u: goto P_0c08a274;
case 0x0c08a276u: goto P_0c08a276;
case 0x0c08a278u: goto P_0c08a278;
case 0x0c08a27au: goto P_0c08a27a;
case 0x0c08a27cu: goto P_0c08a27c;
case 0x0c08a27eu: goto P_0c08a27e;
case 0x0c08a280u: goto P_0c08a280;
case 0x0c08a282u: goto P_0c08a282;
case 0x0c08a284u: goto P_0c08a284;
case 0x0c08a286u: goto P_0c08a286;
case 0x0c08a288u: goto P_0c08a288;
case 0x0c08a28au: goto P_0c08a28a;
case 0x0c08a28cu: goto P_0c08a28c;
case 0x0c08a28eu: goto P_0c08a28e;
case 0x0c08a290u: goto P_0c08a290;
case 0x0c08a292u: goto P_0c08a292;
case 0x0c08a294u: goto P_0c08a294;
case 0x0c08a296u: goto P_0c08a296;
case 0x0c08a298u: goto P_0c08a298;
case 0x0c08a29au: goto P_0c08a29a;
case 0x0c08a29cu: goto P_0c08a29c;
case 0x0c08a29eu: goto P_0c08a29e;
case 0x0c08a2a0u: goto P_0c08a2a0;
case 0x0c08a2a2u: goto P_0c08a2a2;
case 0x0c08a2a4u: goto P_0c08a2a4;
case 0x0c08a2a6u: goto P_0c08a2a6;
case 0x0c08a2a8u: goto P_0c08a2a8;
case 0x0c08a2aau: goto P_0c08a2aa;
case 0x0c08a2acu: goto P_0c08a2ac;
case 0x0c08a2aeu: goto P_0c08a2ae;
case 0x0c08a2b0u: goto P_0c08a2b0;
case 0x0c08a2b2u: goto P_0c08a2b2;
case 0x0c08a2b4u: goto P_0c08a2b4;
case 0x0c08a2b6u: goto P_0c08a2b6;
case 0x0c08a2b8u: goto P_0c08a2b8;
case 0x0c08a2bau: goto P_0c08a2ba;
case 0x0c08a2bcu: goto P_0c08a2bc;
case 0x0c08a2beu: goto P_0c08a2be;
case 0x0c08a2c0u: goto P_0c08a2c0;
case 0x0c08a2c2u: goto P_0c08a2c2;
case 0x0c08a2c4u: goto P_0c08a2c4;
case 0x0c08a2c6u: goto P_0c08a2c6;
case 0x0c08a2c8u: goto P_0c08a2c8;
case 0x0c08a2cau: goto P_0c08a2ca;
default: return vf3_matrix_family(target,s,ram);
}
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
return vf3_matrix_family(0x0c07aaacu,s,ram);
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
P_0c07b5f0: /* original 2fe6, guest PC 0x0c07b5f0 */
if(!s->budget--) { s->failed_pc=0x0c07b5f0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f2;
P_0c07b5f2: /* original 2fd6, guest PC 0x0c07b5f2 */
if(!s->budget--) { s->failed_pc=0x0c07b5f2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f4;
P_0c07b5f4: /* original 6d43, guest PC 0x0c07b5f4 */
if(!s->budget--) { s->failed_pc=0x0c07b5f4u; return 0; }
r[13]=r[4];
goto P_0c07b5f6;
P_0c07b5f6: /* original 2fc6, guest PC 0x0c07b5f6 */
if(!s->budget--) { s->failed_pc=0x0c07b5f6u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b5f8;
P_0c07b5f8: /* original 4f22, guest PC 0x0c07b5f8 */
if(!s->budget--) { s->failed_pc=0x0c07b5f8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b5fa;
P_0c07b5fa: /* original d22a, guest PC 0x0c07b5fa */
if(!s->budget--) { s->failed_pc=0x0c07b5fau; return 0; }
r[2]=read(ram,0x0c07b6a4u,4);
goto P_0c07b5fc;
P_0c07b5fc: /* original d32a, guest PC 0x0c07b5fc */
if(!s->budget--) { s->failed_pc=0x0c07b5fcu; return 0; }
r[3]=read(ram,0x0c07b6a8u,4);
goto P_0c07b5fe;
P_0c07b5fe: /* original 7fe0, guest PC 0x0c07b5fe */
if(!s->budget--) { s->failed_pc=0x0c07b5feu; return 0; }
r[15]+=0xffffffe0u;
goto P_0c07b600;
P_0c07b600: /* original 61f3, guest PC 0x0c07b600 */
if(!s->budget--) { s->failed_pc=0x0c07b600u; return 0; }
r[1]=r[15];
goto P_0c07b602;
P_0c07b602: /* original 430b, guest PC 0x0c07b602 */
if(!s->budget--) { s->failed_pc=0x0c07b602u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b606u;
r[0]=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b606u) { target=s->pc; goto dispatch; }
goto P_0c07b606;
P_0c07b604: /* original e020, guest PC 0x0c07b604 */
if(!s->budget--) { s->failed_pc=0x0c07b604u; return 0; }
r[0]=0x00000020u;
goto P_0c07b606;
P_0c07b606: /* original 9149, guest PC 0x0c07b606 */
if(!s->budget--) { s->failed_pc=0x0c07b606u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69cu,2);
goto P_0c07b608;
P_0c07b608: /* original 6edd, guest PC 0x0c07b608 */
if(!s->budget--) { s->failed_pc=0x0c07b608u; return 0; }
r[14]=r[13]&65535u;
goto P_0c07b60a;
P_0c07b60a: /* original 21e8, guest PC 0x0c07b60a */
if(!s->budget--) { s->failed_pc=0x0c07b60au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[14])==0)!=0);
goto P_0c07b60c;
P_0c07b60c: /* original 8b29, guest PC 0x0c07b60c */
if(!s->budget--) { s->failed_pc=0x0c07b60cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b60e;
P_0c07b60e: /* original d227, guest PC 0x0c07b60e */
if(!s->budget--) { s->failed_pc=0x0c07b60eu; return 0; }
r[2]=read(ram,0x0c07b6acu,4);
goto P_0c07b610;
P_0c07b610: /* original 22e8, guest PC 0x0c07b610 */
if(!s->budget--) { s->failed_pc=0x0c07b610u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[14])==0)!=0);
goto P_0c07b612;
P_0c07b612: /* original 8b26, guest PC 0x0c07b612 */
if(!s->budget--) { s->failed_pc=0x0c07b612u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b662; }
goto P_0c07b614;
P_0c07b614: /* original 60e3, guest PC 0x0c07b614 */
if(!s->budget--) { s->failed_pc=0x0c07b614u; return 0; }
r[0]=r[14];
goto P_0c07b616;
P_0c07b616: /* original dc26, guest PC 0x0c07b616 */
if(!s->budget--) { s->failed_pc=0x0c07b616u; return 0; }
r[12]=read(ram,0x0c07b6b0u,4);
goto P_0c07b618;
P_0c07b618: /* original 8807, guest PC 0x0c07b618 */
if(!s->budget--) { s->failed_pc=0x0c07b618u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c07b61a;
P_0c07b61a: /* original 8b02, guest PC 0x0c07b61a */
if(!s->budget--) { s->failed_pc=0x0c07b61au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b622; }
goto P_0c07b61c;
P_0c07b61c: /* original 953f, guest PC 0x0c07b61c */
if(!s->budget--) { s->failed_pc=0x0c07b61cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b61e;
P_0c07b61e: /* original 4c0b, guest PC 0x0c07b61e */
if(!s->budget--) { s->failed_pc=0x0c07b61eu; return 0; }
target=r[12];
r[16]=code_base|0x0c07b622u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b622u) { target=s->pc; goto dispatch; }
goto P_0c07b622;
P_0c07b620: /* original e401, guest PC 0x0c07b620 */
if(!s->budget--) { s->failed_pc=0x0c07b620u; return 0; }
r[4]=0x00000001u;
goto P_0c07b622;
P_0c07b622: /* original 60e3, guest PC 0x0c07b622 */
if(!s->budget--) { s->failed_pc=0x0c07b622u; return 0; }
r[0]=r[14];
goto P_0c07b624;
P_0c07b624: /* original 8805, guest PC 0x0c07b624 */
if(!s->budget--) { s->failed_pc=0x0c07b624u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c07b626;
P_0c07b626: /* original 8b02, guest PC 0x0c07b626 */
if(!s->budget--) { s->failed_pc=0x0c07b626u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07b62e; }
goto P_0c07b628;
P_0c07b628: /* original 953a, guest PC 0x0c07b628 */
if(!s->budget--) { s->failed_pc=0x0c07b628u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b6a0u,2);
goto P_0c07b62a;
P_0c07b62a: /* original 4c0b, guest PC 0x0c07b62a */
if(!s->budget--) { s->failed_pc=0x0c07b62au; return 0; }
target=r[12];
r[16]=code_base|0x0c07b62eu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b62eu) { target=s->pc; goto dispatch; }
goto P_0c07b62e;
P_0c07b62c: /* original e401, guest PC 0x0c07b62c */
if(!s->budget--) { s->failed_pc=0x0c07b62cu; return 0; }
r[4]=0x00000001u;
goto P_0c07b62e;
P_0c07b62e: /* original d021, guest PC 0x0c07b62e */
if(!s->budget--) { s->failed_pc=0x0c07b62eu; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b630;
P_0c07b630: /* original 64dd, guest PC 0x0c07b630 */
if(!s->budget--) { s->failed_pc=0x0c07b630u; return 0; }
r[4]=r[13]&65535u;
goto P_0c07b632;
P_0c07b632: /* original 4400, guest PC 0x0c07b632 */
if(!s->budget--) { s->failed_pc=0x0c07b632u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07b634;
P_0c07b634: /* original 044d, guest PC 0x0c07b634 */
if(!s->budget--) { s->failed_pc=0x0c07b634u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c07b636;
P_0c07b636: /* original 644d, guest PC 0x0c07b636 */
if(!s->budget--) { s->failed_pc=0x0c07b636u; return 0; }
r[4]=r[4]&65535u;
goto P_0c07b638;
P_0c07b638: /* original 2448, guest PC 0x0c07b638 */
if(!s->budget--) { s->failed_pc=0x0c07b638u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b63a;
P_0c07b63a: /* original 8912, guest PC 0x0c07b63a */
if(!s->budget--) { s->failed_pc=0x0c07b63au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b63c;
P_0c07b63c: /* original d21e, guest PC 0x0c07b63c */
if(!s->budget--) { s->failed_pc=0x0c07b63cu; return 0; }
r[2]=read(ram,0x0c07b6b8u,4);
goto P_0c07b63e;
P_0c07b63e: /* original 3420, guest PC 0x0c07b63e */
if(!s->budget--) { s->failed_pc=0x0c07b63eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[2])!=0);
goto P_0c07b640;
P_0c07b640: /* original 890f, guest PC 0x0c07b640 */
if(!s->budget--) { s->failed_pc=0x0c07b640u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b662; }
goto P_0c07b642;
P_0c07b642: /* original d21e, guest PC 0x0c07b642 */
if(!s->budget--) { s->failed_pc=0x0c07b642u; return 0; }
r[2]=read(ram,0x0c07b6bcu,4);
goto P_0c07b644;
P_0c07b644: /* original 420b, guest PC 0x0c07b644 */
if(!s->budget--) { s->failed_pc=0x0c07b644u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b648u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b648u) { target=s->pc; goto dispatch; }
goto P_0c07b648;
P_0c07b646: /* original 0009, guest PC 0x0c07b646 */
if(!s->budget--) { s->failed_pc=0x0c07b646u; return 0; }
goto P_0c07b648;
P_0c07b648: /* original d31d, guest PC 0x0c07b648 */
if(!s->budget--) { s->failed_pc=0x0c07b648u; return 0; }
r[3]=read(ram,0x0c07b6c0u,4);
goto P_0c07b64a;
P_0c07b64a: /* original 430b, guest PC 0x0c07b64a */
if(!s->budget--) { s->failed_pc=0x0c07b64au; return 0; }
target=r[3];
r[16]=code_base|0x0c07b64eu;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b64eu) { target=s->pc; goto dispatch; }
goto P_0c07b64e;
P_0c07b64c: /* original 64f3, guest PC 0x0c07b64c */
if(!s->budget--) { s->failed_pc=0x0c07b64cu; return 0; }
r[4]=r[15];
goto P_0c07b64e;
P_0c07b64e: /* original 2008, guest PC 0x0c07b64e */
if(!s->budget--) { s->failed_pc=0x0c07b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c07b650;
P_0c07b650: /* original 8902, guest PC 0x0c07b650 */
if(!s->budget--) { s->failed_pc=0x0c07b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b658; }
goto P_0c07b652;
P_0c07b652: /* original 9524, guest PC 0x0c07b652 */
if(!s->budget--) { s->failed_pc=0x0c07b652u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07b69eu,2);
goto P_0c07b654;
P_0c07b654: /* original 4c0b, guest PC 0x0c07b654 */
if(!s->budget--) { s->failed_pc=0x0c07b654u; return 0; }
target=r[12];
r[16]=code_base|0x0c07b658u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b658u) { target=s->pc; goto dispatch; }
goto P_0c07b658;
P_0c07b656: /* original e401, guest PC 0x0c07b656 */
if(!s->budget--) { s->failed_pc=0x0c07b656u; return 0; }
r[4]=0x00000001u;
goto P_0c07b658;
P_0c07b658: /* original d016, guest PC 0x0c07b658 */
if(!s->budget--) { s->failed_pc=0x0c07b658u; return 0; }
r[0]=read(ram,0x0c07b6b4u,4);
goto P_0c07b65a;
P_0c07b65a: /* original 6ddd, guest PC 0x0c07b65a */
if(!s->budget--) { s->failed_pc=0x0c07b65au; return 0; }
r[13]=r[13]&65535u;
goto P_0c07b65c;
P_0c07b65c: /* original e300, guest PC 0x0c07b65c */
if(!s->budget--) { s->failed_pc=0x0c07b65cu; return 0; }
r[3]=0x00000000u;
goto P_0c07b65e;
P_0c07b65e: /* original 4d00, guest PC 0x0c07b65e */
if(!s->budget--) { s->failed_pc=0x0c07b65eu; return 0; }
r[17]=(r[17]&~1u)|((r[13]>>31)!=0);
r[13]<<=1;
goto P_0c07b660;
P_0c07b660: /* original 0d35, guest PC 0x0c07b660 */
if(!s->budget--) { s->failed_pc=0x0c07b660u; return 0; }
write(ram,r[13]+r[0],r[3],2);
goto P_0c07b662;
P_0c07b662: /* original 7f20, guest PC 0x0c07b662 */
if(!s->budget--) { s->failed_pc=0x0c07b662u; return 0; }
r[15]+=0x00000020u;
goto P_0c07b664;
P_0c07b664: /* original 4f26, guest PC 0x0c07b664 */
if(!s->budget--) { s->failed_pc=0x0c07b664u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07b666;
P_0c07b666: /* original 6cf6, guest PC 0x0c07b666 */
if(!s->budget--) { s->failed_pc=0x0c07b666u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07b668;
P_0c07b668: /* original 6df6, guest PC 0x0c07b668 */
if(!s->budget--) { s->failed_pc=0x0c07b668u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07b66a;
P_0c07b66a: /* original 000b, guest PC 0x0c07b66a */
if(!s->budget--) { s->failed_pc=0x0c07b66au; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07b66c: /* original 6ef6, guest PC 0x0c07b66c */
if(!s->budget--) { s->failed_pc=0x0c07b66cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07b66eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07b66eu; return 0; } return 1;
P_0c08a068: /* original 2fe6, guest PC 0x0c08a068 */
if(!s->budget--) { s->failed_pc=0x0c08a068u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a06a;
P_0c08a06a: /* original e200, guest PC 0x0c08a06a */
if(!s->budget--) { s->failed_pc=0x0c08a06au; return 0; }
r[2]=0x00000000u;
goto P_0c08a06c;
P_0c08a06c: /* original 2fd6, guest PC 0x0c08a06c */
if(!s->budget--) { s->failed_pc=0x0c08a06cu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a06e;
P_0c08a06e: /* original 2fc6, guest PC 0x0c08a06e */
if(!s->budget--) { s->failed_pc=0x0c08a06eu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a070;
P_0c08a070: /* original 2fb6, guest PC 0x0c08a070 */
if(!s->budget--) { s->failed_pc=0x0c08a070u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c08a072;
P_0c08a072: /* original fffb, guest PC 0x0c08a072 */
if(!s->budget--) { s->failed_pc=0x0c08a072u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c08a074;
P_0c08a074: /* original d35f, guest PC 0x0c08a074 */
if(!s->budget--) { s->failed_pc=0x0c08a074u; return 0; }
r[3]=read(ram,0x0c08a1f4u,4);
goto P_0c08a076;
P_0c08a076: /* original 4f22, guest PC 0x0c08a076 */
if(!s->budget--) { s->failed_pc=0x0c08a076u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c08a078;
P_0c08a078: /* original 6432, guest PC 0x0c08a078 */
if(!s->budget--) { s->failed_pc=0x0c08a078u; return 0; }
tmp=read(ram,r[3],4);
r[4]=tmp;
goto P_0c08a07a;
P_0c08a07a: /* original dd5d, guest PC 0x0c08a07a */
if(!s->budget--) { s->failed_pc=0x0c08a07au; return 0; }
r[13]=read(ram,0x0c08a1f0u,4);
goto P_0c08a07c;
P_0c08a07c: /* original 1425, guest PC 0x0c08a07c */
if(!s->budget--) { s->failed_pc=0x0c08a07cu; return 0; }
write(ram,r[4]+20,r[2],4);
goto P_0c08a07e;
P_0c08a07e: /* original 7fc0, guest PC 0x0c08a07e */
if(!s->budget--) { s->failed_pc=0x0c08a07eu; return 0; }
r[15]+=0xffffffc0u;
goto P_0c08a080;
P_0c08a080: /* original d15d, guest PC 0x0c08a080 */
if(!s->budget--) { s->failed_pc=0x0c08a080u; return 0; }
r[1]=read(ram,0x0c08a1f8u,4);
goto P_0c08a082;
P_0c08a082: /* original 410b, guest PC 0x0c08a082 */
if(!s->budget--) { s->failed_pc=0x0c08a082u; return 0; }
target=r[1];
r[16]=code_base|0x0c08a086u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a086u) { target=s->pc; goto dispatch; }
goto P_0c08a086;
P_0c08a084: /* original 6423, guest PC 0x0c08a084 */
if(!s->budget--) { s->failed_pc=0x0c08a084u; return 0; }
r[4]=r[2];
goto P_0c08a086;
P_0c08a086: /* original 90aa, guest PC 0x0c08a086 */
if(!s->budget--) { s->failed_pc=0x0c08a086u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1deu,2);
goto P_0c08a088;
P_0c08a088: /* original e302, guest PC 0x0c08a088 */
if(!s->budget--) { s->failed_pc=0x0c08a088u; return 0; }
r[3]=0x00000002u;
goto P_0c08a08a;
P_0c08a08a: /* original 0d34, guest PC 0x0c08a08a */
if(!s->budget--) { s->failed_pc=0x0c08a08au; return 0; }
write(ram,r[13]+r[0],r[3],1);
goto P_0c08a08c;
P_0c08a08c: /* original d25b, guest PC 0x0c08a08c */
if(!s->budget--) { s->failed_pc=0x0c08a08cu; return 0; }
r[2]=read(ram,0x0c08a1fcu,4);
goto P_0c08a08e;
P_0c08a08e: /* original 90a7, guest PC 0x0c08a08e */
if(!s->budget--) { s->failed_pc=0x0c08a08eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e0u,2);
goto P_0c08a090;
P_0c08a090: /* original 6422, guest PC 0x0c08a090 */
if(!s->budget--) { s->failed_pc=0x0c08a090u; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c08a092;
P_0c08a092: /* original 95a8, guest PC 0x0c08a092 */
if(!s->budget--) { s->failed_pc=0x0c08a092u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e6u,2);
goto P_0c08a094;
P_0c08a094: /* original 044e, guest PC 0x0c08a094 */
if(!s->budget--) { s->failed_pc=0x0c08a094u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c08a096;
P_0c08a096: /* original 90a5, guest PC 0x0c08a096 */
if(!s->budget--) { s->failed_pc=0x0c08a096u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e4u,2);
goto P_0c08a098;
P_0c08a098: /* original 9ea3, guest PC 0x0c08a098 */
if(!s->budget--) { s->failed_pc=0x0c08a098u; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e2u,2);
goto P_0c08a09a;
P_0c08a09a: /* original 6c43, guest PC 0x0c08a09a */
if(!s->budget--) { s->failed_pc=0x0c08a09au; return 0; }
r[12]=r[4];
goto P_0c08a09c;
P_0c08a09c: /* original 0bde, guest PC 0x0c08a09c */
if(!s->budget--) { s->failed_pc=0x0c08a09cu; return 0; }
r[11]=read(ram,r[13]+r[0],4);
goto P_0c08a09e;
P_0c08a09e: /* original d358, guest PC 0x0c08a09e */
if(!s->budget--) { s->failed_pc=0x0c08a09eu; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0a0;
P_0c08a0a0: /* original 3e4c, guest PC 0x0c08a0a0 */
if(!s->budget--) { s->failed_pc=0x0c08a0a0u; return 0; }
r[14]+=r[4];
goto P_0c08a0a2;
P_0c08a0a2: /* original 35bc, guest PC 0x0c08a0a2 */
if(!s->budget--) { s->failed_pc=0x0c08a0a2u; return 0; }
r[5]+=r[11];
goto P_0c08a0a4;
P_0c08a0a4: /* original 430b, guest PC 0x0c08a0a4 */
if(!s->budget--) { s->failed_pc=0x0c08a0a4u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a0a8u;
r[4]=r[15];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a0a8u) { target=s->pc; goto dispatch; }
goto P_0c08a0a8;
P_0c08a0a6: /* original 64f3, guest PC 0x0c08a0a6 */
if(!s->budget--) { s->failed_pc=0x0c08a0a6u; return 0; }
r[4]=r[15];
goto P_0c08a0a8;
P_0c08a0a8: /* original c756, guest PC 0x0c08a0a8 */
if(!s->budget--) { s->failed_pc=0x0c08a0a8u; return 0; }
r[0]=code_base|0x0008a204u;
goto P_0c08a0aa;
P_0c08a0aa: /* original 64e3, guest PC 0x0c08a0aa */
if(!s->budget--) { s->failed_pc=0x0c08a0aau; return 0; }
r[4]=r[14];
goto P_0c08a0ac;
P_0c08a0ac: /* original f408, guest PC 0x0c08a0ac */
if(!s->budget--) { s->failed_pc=0x0c08a0acu; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c08a0ae;
P_0c08a0ae: /* original 65f3, guest PC 0x0c08a0ae */
if(!s->budget--) { s->failed_pc=0x0c08a0aeu; return 0; }
r[5]=r[15];
goto P_0c08a0b0;
P_0c08a0b0: /* original 909a, guest PC 0x0c08a0b0 */
if(!s->budget--) { s->failed_pc=0x0c08a0b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1e8u,2);
goto P_0c08a0b2;
P_0c08a0b2: /* original f3b6, guest PC 0x0c08a0b2 */
if(!s->budget--) { s->failed_pc=0x0c08a0b2u; return 0; }
vf3_matrix_load(s,ram,3,r[11]+r[0]);
goto P_0c08a0b4;
P_0c08a0b4: /* original e034, guest PC 0x0c08a0b4 */
if(!s->budget--) { s->failed_pc=0x0c08a0b4u; return 0; }
r[0]=0x00000034u;
goto P_0c08a0b6;
P_0c08a0b6: /* original f340, guest PC 0x0c08a0b6 */
if(!s->budget--) { s->failed_pc=0x0c08a0b6u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[4],r[18],'+');
goto P_0c08a0b8;
P_0c08a0b8: /* original ff37, guest PC 0x0c08a0b8 */
if(!s->budget--) { s->failed_pc=0x0c08a0b8u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c08a0ba;
P_0c08a0ba: /* original e004, guest PC 0x0c08a0ba */
if(!s->budget--) { s->failed_pc=0x0c08a0bau; return 0; }
r[0]=0x00000004u;
goto P_0c08a0bc;
P_0c08a0bc: /* original f49d, guest PC 0x0c08a0bc */
if(!s->budget--) { s->failed_pc=0x0c08a0bcu; return 0; }
fr[4]=0x3f800000u;
goto P_0c08a0be;
P_0c08a0be: /* original ff4a, guest PC 0x0c08a0be */
if(!s->budget--) { s->failed_pc=0x0c08a0beu; return 0; }
vf3_matrix_store(s,ram,4,r[15]);
goto P_0c08a0c0;
P_0c08a0c0: /* original ff8d, guest PC 0x0c08a0c0 */
if(!s->budget--) { s->failed_pc=0x0c08a0c0u; return 0; }
fr[15]=0;
goto P_0c08a0c2;
P_0c08a0c2: /* original fff7, guest PC 0x0c08a0c2 */
if(!s->budget--) { s->failed_pc=0x0c08a0c2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c4;
P_0c08a0c4: /* original e008, guest PC 0x0c08a0c4 */
if(!s->budget--) { s->failed_pc=0x0c08a0c4u; return 0; }
r[0]=0x00000008u;
goto P_0c08a0c6;
P_0c08a0c6: /* original fff7, guest PC 0x0c08a0c6 */
if(!s->budget--) { s->failed_pc=0x0c08a0c6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0c8;
P_0c08a0c8: /* original e010, guest PC 0x0c08a0c8 */
if(!s->budget--) { s->failed_pc=0x0c08a0c8u; return 0; }
r[0]=0x00000010u;
goto P_0c08a0ca;
P_0c08a0ca: /* original fff7, guest PC 0x0c08a0ca */
if(!s->budget--) { s->failed_pc=0x0c08a0cau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0cc;
P_0c08a0cc: /* original e014, guest PC 0x0c08a0cc */
if(!s->budget--) { s->failed_pc=0x0c08a0ccu; return 0; }
r[0]=0x00000014u;
goto P_0c08a0ce;
P_0c08a0ce: /* original ff47, guest PC 0x0c08a0ce */
if(!s->budget--) { s->failed_pc=0x0c08a0ceu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0d0;
P_0c08a0d0: /* original e018, guest PC 0x0c08a0d0 */
if(!s->budget--) { s->failed_pc=0x0c08a0d0u; return 0; }
r[0]=0x00000018u;
goto P_0c08a0d2;
P_0c08a0d2: /* original fff7, guest PC 0x0c08a0d2 */
if(!s->budget--) { s->failed_pc=0x0c08a0d2u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d4;
P_0c08a0d4: /* original e020, guest PC 0x0c08a0d4 */
if(!s->budget--) { s->failed_pc=0x0c08a0d4u; return 0; }
r[0]=0x00000020u;
goto P_0c08a0d6;
P_0c08a0d6: /* original fff7, guest PC 0x0c08a0d6 */
if(!s->budget--) { s->failed_pc=0x0c08a0d6u; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0d8;
P_0c08a0d8: /* original e024, guest PC 0x0c08a0d8 */
if(!s->budget--) { s->failed_pc=0x0c08a0d8u; return 0; }
r[0]=0x00000024u;
goto P_0c08a0da;
P_0c08a0da: /* original fff7, guest PC 0x0c08a0da */
if(!s->budget--) { s->failed_pc=0x0c08a0dau; return 0; }
vf3_matrix_store(s,ram,15,r[15]+r[0]);
goto P_0c08a0dc;
P_0c08a0dc: /* original e028, guest PC 0x0c08a0dc */
if(!s->budget--) { s->failed_pc=0x0c08a0dcu; return 0; }
r[0]=0x00000028u;
goto P_0c08a0de;
P_0c08a0de: /* original ff47, guest PC 0x0c08a0de */
if(!s->budget--) { s->failed_pc=0x0c08a0deu; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c08a0e0;
P_0c08a0e0: /* original d347, guest PC 0x0c08a0e0 */
if(!s->budget--) { s->failed_pc=0x0c08a0e0u; return 0; }
r[3]=read(ram,0x0c08a200u,4);
goto P_0c08a0e2;
P_0c08a0e2: /* original 430b, guest PC 0x0c08a0e2 */
if(!s->budget--) { s->failed_pc=0x0c08a0e2u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a0e6u;
r[4]+=0x00000010u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a0e6u) { target=s->pc; goto dispatch; }
goto P_0c08a0e6;
P_0c08a0e4: /* original 7410, guest PC 0x0c08a0e4 */
if(!s->budget--) { s->failed_pc=0x0c08a0e4u; return 0; }
r[4]+=0x00000010u;
goto P_0c08a0e6;
P_0c08a0e6: /* original c748, guest PC 0x0c08a0e6 */
if(!s->budget--) { s->failed_pc=0x0c08a0e6u; return 0; }
r[0]=code_base|0x0008a208u;
goto P_0c08a0e8;
P_0c08a0e8: /* original f5d8, guest PC 0x0c08a0e8 */
if(!s->budget--) { s->failed_pc=0x0c08a0e8u; return 0; }
vf3_matrix_load(s,ram,5,r[13]);
goto P_0c08a0ea;
P_0c08a0ea: /* original f708, guest PC 0x0c08a0ea */
if(!s->budget--) { s->failed_pc=0x0c08a0eau; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a0ec;
P_0c08a0ec: /* original c747, guest PC 0x0c08a0ec */
if(!s->budget--) { s->failed_pc=0x0c08a0ecu; return 0; }
r[0]=code_base|0x0008a20cu;
goto P_0c08a0ee;
P_0c08a0ee: /* original fb08, guest PC 0x0c08a0ee */
if(!s->budget--) { s->failed_pc=0x0c08a0eeu; return 0; }
vf3_matrix_load(s,ram,11,r[0]);
goto P_0c08a0f0;
P_0c08a0f0: /* original c747, guest PC 0x0c08a0f0 */
if(!s->budget--) { s->failed_pc=0x0c08a0f0u; return 0; }
r[0]=code_base|0x0008a210u;
goto P_0c08a0f2;
P_0c08a0f2: /* original f808, guest PC 0x0c08a0f2 */
if(!s->budget--) { s->failed_pc=0x0c08a0f2u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a0f4;
P_0c08a0f4: /* original c747, guest PC 0x0c08a0f4 */
if(!s->budget--) { s->failed_pc=0x0c08a0f4u; return 0; }
r[0]=code_base|0x0008a214u;
goto P_0c08a0f6;
P_0c08a0f6: /* original f908, guest PC 0x0c08a0f6 */
if(!s->budget--) { s->failed_pc=0x0c08a0f6u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a0f8;
P_0c08a0f8: /* original e300, guest PC 0x0c08a0f8 */
if(!s->budget--) { s->failed_pc=0x0c08a0f8u; return 0; }
r[3]=0x00000000u;
goto P_0c08a0fa;
P_0c08a0fa: /* original 9076, guest PC 0x0c08a0fa */
if(!s->budget--) { s->failed_pc=0x0c08a0fau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1eau,2);
goto P_0c08a0fc;
P_0c08a0fc: /* original fa8c, guest PC 0x0c08a0fc */
if(!s->budget--) { s->failed_pc=0x0c08a0fcu; return 0; }
vf3_matrix_move(s,10,8);
goto P_0c08a0fe;
P_0c08a0fe: /* original f4fc, guest PC 0x0c08a0fe */
if(!s->budget--) { s->failed_pc=0x0c08a0feu; return 0; }
vf3_matrix_move(s,4,15);
goto P_0c08a100;
P_0c08a100: /* original f54d, guest PC 0x0c08a100 */
if(!s->budget--) { s->failed_pc=0x0c08a100u; return 0; }
fr[5]^=0x80000000u;
goto P_0c08a102;
P_0c08a102: /* original f67c, guest PC 0x0c08a102 */
if(!s->budget--) { s->failed_pc=0x0c08a102u; return 0; }
vf3_matrix_move(s,6,7);
goto P_0c08a104;
P_0c08a104: /* original 0e35, guest PC 0x0c08a104 */
if(!s->budget--) { s->failed_pc=0x0c08a104u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c08a106;
P_0c08a106: /* original e004, guest PC 0x0c08a106 */
if(!s->budget--) { s->failed_pc=0x0c08a106u; return 0; }
r[0]=0x00000004u;
goto P_0c08a108;
P_0c08a108: /* original feba, guest PC 0x0c08a108 */
if(!s->budget--) { s->failed_pc=0x0c08a108u; return 0; }
vf3_matrix_store(s,ram,11,r[14]);
goto P_0c08a10a;
P_0c08a10a: /* original fea7, guest PC 0x0c08a10a */
if(!s->budget--) { s->failed_pc=0x0c08a10au; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a10c;
P_0c08a10c: /* original e008, guest PC 0x0c08a10c */
if(!s->budget--) { s->failed_pc=0x0c08a10cu; return 0; }
r[0]=0x00000008u;
goto P_0c08a10e;
P_0c08a10e: /* original fe97, guest PC 0x0c08a10e */
if(!s->budget--) { s->failed_pc=0x0c08a10eu; return 0; }
vf3_matrix_store(s,ram,9,r[14]+r[0]);
goto P_0c08a110;
P_0c08a110: /* original e00c, guest PC 0x0c08a110 */
if(!s->budget--) { s->failed_pc=0x0c08a110u; return 0; }
r[0]=0x0000000cu;
goto P_0c08a112;
P_0c08a112: /* original fea7, guest PC 0x0c08a112 */
if(!s->budget--) { s->failed_pc=0x0c08a112u; return 0; }
vf3_matrix_store(s,ram,10,r[14]+r[0]);
goto P_0c08a114;
P_0c08a114: /* original e068, guest PC 0x0c08a114 */
if(!s->budget--) { s->failed_pc=0x0c08a114u; return 0; }
r[0]=0x00000068u;
goto P_0c08a116;
P_0c08a116: /* original fe47, guest PC 0x0c08a116 */
if(!s->budget--) { s->failed_pc=0x0c08a116u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a118;
P_0c08a118: /* original e06c, guest PC 0x0c08a118 */
if(!s->budget--) { s->failed_pc=0x0c08a118u; return 0; }
r[0]=0x0000006cu;
goto P_0c08a11a;
P_0c08a11a: /* original fe57, guest PC 0x0c08a11a */
if(!s->budget--) { s->failed_pc=0x0c08a11au; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a11c;
P_0c08a11c: /* original e070, guest PC 0x0c08a11c */
if(!s->budget--) { s->failed_pc=0x0c08a11cu; return 0; }
r[0]=0x00000070u;
goto P_0c08a11e;
P_0c08a11e: /* original fe47, guest PC 0x0c08a11e */
if(!s->budget--) { s->failed_pc=0x0c08a11eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a120;
P_0c08a120: /* original e074, guest PC 0x0c08a120 */
if(!s->budget--) { s->failed_pc=0x0c08a120u; return 0; }
r[0]=0x00000074u;
goto P_0c08a122;
P_0c08a122: /* original fe67, guest PC 0x0c08a122 */
if(!s->budget--) { s->failed_pc=0x0c08a122u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a124;
P_0c08a124: /* original e078, guest PC 0x0c08a124 */
if(!s->budget--) { s->failed_pc=0x0c08a124u; return 0; }
r[0]=0x00000078u;
goto P_0c08a126;
P_0c08a126: /* original fe67, guest PC 0x0c08a126 */
if(!s->budget--) { s->failed_pc=0x0c08a126u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a128;
P_0c08a128: /* original c73b, guest PC 0x0c08a128 */
if(!s->budget--) { s->failed_pc=0x0c08a128u; return 0; }
r[0]=code_base|0x0008a218u;
goto P_0c08a12a;
P_0c08a12a: /* original f508, guest PC 0x0c08a12a */
if(!s->budget--) { s->failed_pc=0x0c08a12au; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a12c;
P_0c08a12c: /* original c73b, guest PC 0x0c08a12c */
if(!s->budget--) { s->failed_pc=0x0c08a12cu; return 0; }
r[0]=code_base|0x0008a21cu;
goto P_0c08a12e;
P_0c08a12e: /* original f608, guest PC 0x0c08a12e */
if(!s->budget--) { s->failed_pc=0x0c08a12eu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a130;
P_0c08a130: /* original c73b, guest PC 0x0c08a130 */
if(!s->budget--) { s->failed_pc=0x0c08a130u; return 0; }
r[0]=code_base|0x0008a220u;
goto P_0c08a132;
P_0c08a132: /* original f708, guest PC 0x0c08a132 */
if(!s->budget--) { s->failed_pc=0x0c08a132u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a134;
P_0c08a134: /* original e05c, guest PC 0x0c08a134 */
if(!s->budget--) { s->failed_pc=0x0c08a134u; return 0; }
r[0]=0x0000005cu;
goto P_0c08a136;
P_0c08a136: /* original fe47, guest PC 0x0c08a136 */
if(!s->budget--) { s->failed_pc=0x0c08a136u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a138;
P_0c08a138: /* original e060, guest PC 0x0c08a138 */
if(!s->budget--) { s->failed_pc=0x0c08a138u; return 0; }
r[0]=0x00000060u;
goto P_0c08a13a;
P_0c08a13a: /* original fe47, guest PC 0x0c08a13a */
if(!s->budget--) { s->failed_pc=0x0c08a13au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a13c;
P_0c08a13c: /* original e064, guest PC 0x0c08a13c */
if(!s->budget--) { s->failed_pc=0x0c08a13cu; return 0; }
r[0]=0x00000064u;
goto P_0c08a13e;
P_0c08a13e: /* original fe47, guest PC 0x0c08a13e */
if(!s->budget--) { s->failed_pc=0x0c08a13eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a140;
P_0c08a140: /* original e050, guest PC 0x0c08a140 */
if(!s->budget--) { s->failed_pc=0x0c08a140u; return 0; }
r[0]=0x00000050u;
goto P_0c08a142;
P_0c08a142: /* original fe57, guest PC 0x0c08a142 */
if(!s->budget--) { s->failed_pc=0x0c08a142u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c08a144;
P_0c08a144: /* original e054, guest PC 0x0c08a144 */
if(!s->budget--) { s->failed_pc=0x0c08a144u; return 0; }
r[0]=0x00000054u;
goto P_0c08a146;
P_0c08a146: /* original fe67, guest PC 0x0c08a146 */
if(!s->budget--) { s->failed_pc=0x0c08a146u; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c08a148;
P_0c08a148: /* original e058, guest PC 0x0c08a148 */
if(!s->budget--) { s->failed_pc=0x0c08a148u; return 0; }
r[0]=0x00000058u;
goto P_0c08a14a;
P_0c08a14a: /* original fe77, guest PC 0x0c08a14a */
if(!s->budget--) { s->failed_pc=0x0c08a14au; return 0; }
vf3_matrix_store(s,ram,7,r[14]+r[0]);
goto P_0c08a14c;
P_0c08a14c: /* original e07c, guest PC 0x0c08a14c */
if(!s->budget--) { s->failed_pc=0x0c08a14cu; return 0; }
r[0]=0x0000007cu;
goto P_0c08a14e;
P_0c08a14e: /* original fe47, guest PC 0x0c08a14e */
if(!s->budget--) { s->failed_pc=0x0c08a14eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a150;
P_0c08a150: /* original 7004, guest PC 0x0c08a150 */
if(!s->budget--) { s->failed_pc=0x0c08a150u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a152;
P_0c08a152: /* original fe47, guest PC 0x0c08a152 */
if(!s->budget--) { s->failed_pc=0x0c08a152u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a154;
P_0c08a154: /* original 7004, guest PC 0x0c08a154 */
if(!s->budget--) { s->failed_pc=0x0c08a154u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a156;
P_0c08a156: /* original fe47, guest PC 0x0c08a156 */
if(!s->budget--) { s->failed_pc=0x0c08a156u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a158;
P_0c08a158: /* original 7004, guest PC 0x0c08a158 */
if(!s->budget--) { s->failed_pc=0x0c08a158u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a15a;
P_0c08a15a: /* original fe47, guest PC 0x0c08a15a */
if(!s->budget--) { s->failed_pc=0x0c08a15au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a15c;
P_0c08a15c: /* original c731, guest PC 0x0c08a15c */
if(!s->budget--) { s->failed_pc=0x0c08a15cu; return 0; }
r[0]=code_base|0x0008a224u;
goto P_0c08a15e;
P_0c08a15e: /* original f808, guest PC 0x0c08a15e */
if(!s->budget--) { s->failed_pc=0x0c08a15eu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c08a160;
P_0c08a160: /* original 9044, guest PC 0x0c08a160 */
if(!s->budget--) { s->failed_pc=0x0c08a160u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c08a1ecu,2);
goto P_0c08a162;
P_0c08a162: /* original fe87, guest PC 0x0c08a162 */
if(!s->budget--) { s->failed_pc=0x0c08a162u; return 0; }
vf3_matrix_store(s,ram,8,r[14]+r[0]);
goto P_0c08a164;
P_0c08a164: /* original 7004, guest PC 0x0c08a164 */
if(!s->budget--) { s->failed_pc=0x0c08a164u; return 0; }
r[0]+=0x00000004u;
goto P_0c08a166;
P_0c08a166: /* original fe47, guest PC 0x0c08a166 */
if(!s->budget--) { s->failed_pc=0x0c08a166u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c08a168;
P_0c08a168: /* original c72f, guest PC 0x0c08a168 */
if(!s->budget--) { s->failed_pc=0x0c08a168u; return 0; }
r[0]=code_base|0x0008a228u;
goto P_0c08a16a;
P_0c08a16a: /* original 64c3, guest PC 0x0c08a16a */
if(!s->budget--) { s->failed_pc=0x0c08a16au; return 0; }
r[4]=r[12];
goto P_0c08a16c;
P_0c08a16c: /* original 7404, guest PC 0x0c08a16c */
if(!s->budget--) { s->failed_pc=0x0c08a16cu; return 0; }
r[4]+=0x00000004u;
goto P_0c08a16e;
P_0c08a16e: /* original e310, guest PC 0x0c08a16e */
if(!s->budget--) { s->failed_pc=0x0c08a16eu; return 0; }
r[3]=0x00000010u;
goto P_0c08a170;
P_0c08a170: /* original 2c32, guest PC 0x0c08a170 */
if(!s->budget--) { s->failed_pc=0x0c08a170u; return 0; }
write(ram,r[12],r[3],4);
goto P_0c08a172;
P_0c08a172: /* original f908, guest PC 0x0c08a172 */
if(!s->budget--) { s->failed_pc=0x0c08a172u; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a174;
P_0c08a174: /* original c72d, guest PC 0x0c08a174 */
if(!s->budget--) { s->failed_pc=0x0c08a174u; return 0; }
r[0]=code_base|0x0008a22cu;
goto P_0c08a176;
P_0c08a176: /* original fa08, guest PC 0x0c08a176 */
if(!s->budget--) { s->failed_pc=0x0c08a176u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a178;
P_0c08a178: /* original c72d, guest PC 0x0c08a178 */
if(!s->budget--) { s->failed_pc=0x0c08a178u; return 0; }
r[0]=code_base|0x0008a230u;
goto P_0c08a17a;
P_0c08a17a: /* original f608, guest PC 0x0c08a17a */
if(!s->budget--) { s->failed_pc=0x0c08a17au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a17c;
P_0c08a17c: /* original c72d, guest PC 0x0c08a17c */
if(!s->budget--) { s->failed_pc=0x0c08a17cu; return 0; }
r[0]=code_base|0x0008a234u;
goto P_0c08a17e;
P_0c08a17e: /* original f708, guest PC 0x0c08a17e */
if(!s->budget--) { s->failed_pc=0x0c08a17eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a180;
P_0c08a180: /* original c72d, guest PC 0x0c08a180 */
if(!s->budget--) { s->failed_pc=0x0c08a180u; return 0; }
r[0]=code_base|0x0008a238u;
goto P_0c08a182;
P_0c08a182: /* original f508, guest PC 0x0c08a182 */
if(!s->budget--) { s->failed_pc=0x0c08a182u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c08a184;
P_0c08a184: /* original e004, guest PC 0x0c08a184 */
if(!s->budget--) { s->failed_pc=0x0c08a184u; return 0; }
r[0]=0x00000004u;
goto P_0c08a186;
P_0c08a186: /* original f49a, guest PC 0x0c08a186 */
if(!s->budget--) { s->failed_pc=0x0c08a186u; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a188;
P_0c08a188: /* original f457, guest PC 0x0c08a188 */
if(!s->budget--) { s->failed_pc=0x0c08a188u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a18a;
P_0c08a18a: /* original e008, guest PC 0x0c08a18a */
if(!s->budget--) { s->failed_pc=0x0c08a18au; return 0; }
r[0]=0x00000008u;
goto P_0c08a18c;
P_0c08a18c: /* original f447, guest PC 0x0c08a18c */
if(!s->budget--) { s->failed_pc=0x0c08a18cu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a18e;
P_0c08a18e: /* original 740c, guest PC 0x0c08a18e */
if(!s->budget--) { s->failed_pc=0x0c08a18eu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a190;
P_0c08a190: /* original e004, guest PC 0x0c08a190 */
if(!s->budget--) { s->failed_pc=0x0c08a190u; return 0; }
r[0]=0x00000004u;
goto P_0c08a192;
P_0c08a192: /* original f46a, guest PC 0x0c08a192 */
if(!s->budget--) { s->failed_pc=0x0c08a192u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a194;
P_0c08a194: /* original f457, guest PC 0x0c08a194 */
if(!s->budget--) { s->failed_pc=0x0c08a194u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a196;
P_0c08a196: /* original e008, guest PC 0x0c08a196 */
if(!s->budget--) { s->failed_pc=0x0c08a196u; return 0; }
r[0]=0x00000008u;
goto P_0c08a198;
P_0c08a198: /* original f467, guest PC 0x0c08a198 */
if(!s->budget--) { s->failed_pc=0x0c08a198u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a19a;
P_0c08a19a: /* original 740c, guest PC 0x0c08a19a */
if(!s->budget--) { s->failed_pc=0x0c08a19au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a19c;
P_0c08a19c: /* original e004, guest PC 0x0c08a19c */
if(!s->budget--) { s->failed_pc=0x0c08a19cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a19e;
P_0c08a19e: /* original f44a, guest PC 0x0c08a19e */
if(!s->budget--) { s->failed_pc=0x0c08a19eu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1a0;
P_0c08a1a0: /* original f457, guest PC 0x0c08a1a0 */
if(!s->budget--) { s->failed_pc=0x0c08a1a0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1a2;
P_0c08a1a2: /* original e008, guest PC 0x0c08a1a2 */
if(!s->budget--) { s->failed_pc=0x0c08a1a2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1a4;
P_0c08a1a4: /* original f497, guest PC 0x0c08a1a4 */
if(!s->budget--) { s->failed_pc=0x0c08a1a4u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a1a6;
P_0c08a1a6: /* original e004, guest PC 0x0c08a1a6 */
if(!s->budget--) { s->failed_pc=0x0c08a1a6u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1a8;
P_0c08a1a8: /* original 740c, guest PC 0x0c08a1a8 */
if(!s->budget--) { s->failed_pc=0x0c08a1a8u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1aa;
P_0c08a1aa: /* original f47a, guest PC 0x0c08a1aa */
if(!s->budget--) { s->failed_pc=0x0c08a1aau; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1ac;
P_0c08a1ac: /* original f457, guest PC 0x0c08a1ac */
if(!s->budget--) { s->failed_pc=0x0c08a1acu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ae;
P_0c08a1ae: /* original e008, guest PC 0x0c08a1ae */
if(!s->budget--) { s->failed_pc=0x0c08a1aeu; return 0; }
r[0]=0x00000008u;
goto P_0c08a1b0;
P_0c08a1b0: /* original f467, guest PC 0x0c08a1b0 */
if(!s->budget--) { s->failed_pc=0x0c08a1b0u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a1b2;
P_0c08a1b2: /* original e004, guest PC 0x0c08a1b2 */
if(!s->budget--) { s->failed_pc=0x0c08a1b2u; return 0; }
r[0]=0x00000004u;
goto P_0c08a1b4;
P_0c08a1b4: /* original 740c, guest PC 0x0c08a1b4 */
if(!s->budget--) { s->failed_pc=0x0c08a1b4u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1b6;
P_0c08a1b6: /* original f4aa, guest PC 0x0c08a1b6 */
if(!s->budget--) { s->failed_pc=0x0c08a1b6u; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a1b8;
P_0c08a1b8: /* original f457, guest PC 0x0c08a1b8 */
if(!s->budget--) { s->failed_pc=0x0c08a1b8u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1ba;
P_0c08a1ba: /* original e008, guest PC 0x0c08a1ba */
if(!s->budget--) { s->failed_pc=0x0c08a1bau; return 0; }
r[0]=0x00000008u;
goto P_0c08a1bc;
P_0c08a1bc: /* original f447, guest PC 0x0c08a1bc */
if(!s->budget--) { s->failed_pc=0x0c08a1bcu; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a1be;
P_0c08a1be: /* original e004, guest PC 0x0c08a1be */
if(!s->budget--) { s->failed_pc=0x0c08a1beu; return 0; }
r[0]=0x00000004u;
goto P_0c08a1c0;
P_0c08a1c0: /* original 740c, guest PC 0x0c08a1c0 */
if(!s->budget--) { s->failed_pc=0x0c08a1c0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1c2;
P_0c08a1c2: /* original f47a, guest PC 0x0c08a1c2 */
if(!s->budget--) { s->failed_pc=0x0c08a1c2u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a1c4;
P_0c08a1c4: /* original f457, guest PC 0x0c08a1c4 */
if(!s->budget--) { s->failed_pc=0x0c08a1c4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1c6;
P_0c08a1c6: /* original e008, guest PC 0x0c08a1c6 */
if(!s->budget--) { s->failed_pc=0x0c08a1c6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1c8;
P_0c08a1c8: /* original f477, guest PC 0x0c08a1c8 */
if(!s->budget--) { s->failed_pc=0x0c08a1c8u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a1ca;
P_0c08a1ca: /* original e004, guest PC 0x0c08a1ca */
if(!s->budget--) { s->failed_pc=0x0c08a1cau; return 0; }
r[0]=0x00000004u;
goto P_0c08a1cc;
P_0c08a1cc: /* original 740c, guest PC 0x0c08a1cc */
if(!s->budget--) { s->failed_pc=0x0c08a1ccu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1ce;
P_0c08a1ce: /* original f44a, guest PC 0x0c08a1ce */
if(!s->budget--) { s->failed_pc=0x0c08a1ceu; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a1d0;
P_0c08a1d0: /* original f457, guest PC 0x0c08a1d0 */
if(!s->budget--) { s->failed_pc=0x0c08a1d0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a1d2;
P_0c08a1d2: /* original e008, guest PC 0x0c08a1d2 */
if(!s->budget--) { s->failed_pc=0x0c08a1d2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a1d4;
P_0c08a1d4: /* original f4a7, guest PC 0x0c08a1d4 */
if(!s->budget--) { s->failed_pc=0x0c08a1d4u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a1d6;
P_0c08a1d6: /* original 740c, guest PC 0x0c08a1d6 */
if(!s->budget--) { s->failed_pc=0x0c08a1d6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a1d8;
P_0c08a1d8: /* original f46a, guest PC 0x0c08a1d8 */
if(!s->budget--) { s->failed_pc=0x0c08a1d8u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a1da;
P_0c08a1da: /* original a02f, guest PC 0x0c08a1da */
if(!s->budget--) { s->failed_pc=0x0c08a1dau; return 0; }
goto P_0c08a23c;
P_0c08a1dc: /* original 0009, guest PC 0x0c08a1dc */
if(!s->budget--) { s->failed_pc=0x0c08a1dcu; return 0; }
if(!vf3_matrix_family(0x0c08a1deu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a1deu; return 0; } return 1;
P_0c08a23c: /* original e004, guest PC 0x0c08a23c */
if(!s->budget--) { s->failed_pc=0x0c08a23cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a23e;
P_0c08a23e: /* original f457, guest PC 0x0c08a23e */
if(!s->budget--) { s->failed_pc=0x0c08a23eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a240;
P_0c08a240: /* original e008, guest PC 0x0c08a240 */
if(!s->budget--) { s->failed_pc=0x0c08a240u; return 0; }
r[0]=0x00000008u;
goto P_0c08a242;
P_0c08a242: /* original f477, guest PC 0x0c08a242 */
if(!s->budget--) { s->failed_pc=0x0c08a242u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a244;
P_0c08a244: /* original c751, guest PC 0x0c08a244 */
if(!s->budget--) { s->failed_pc=0x0c08a244u; return 0; }
r[0]=code_base|0x0008a38cu;
goto P_0c08a246;
P_0c08a246: /* original fa08, guest PC 0x0c08a246 */
if(!s->budget--) { s->failed_pc=0x0c08a246u; return 0; }
vf3_matrix_load(s,ram,10,r[0]);
goto P_0c08a248;
P_0c08a248: /* original c751, guest PC 0x0c08a248 */
if(!s->budget--) { s->failed_pc=0x0c08a248u; return 0; }
r[0]=code_base|0x0008a390u;
goto P_0c08a24a;
P_0c08a24a: /* original f908, guest PC 0x0c08a24a */
if(!s->budget--) { s->failed_pc=0x0c08a24au; return 0; }
vf3_matrix_load(s,ram,9,r[0]);
goto P_0c08a24c;
P_0c08a24c: /* original c751, guest PC 0x0c08a24c */
if(!s->budget--) { s->failed_pc=0x0c08a24cu; return 0; }
r[0]=code_base|0x0008a394u;
goto P_0c08a24e;
P_0c08a24e: /* original f708, guest PC 0x0c08a24e */
if(!s->budget--) { s->failed_pc=0x0c08a24eu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c08a250;
P_0c08a250: /* original c751, guest PC 0x0c08a250 */
if(!s->budget--) { s->failed_pc=0x0c08a250u; return 0; }
r[0]=code_base|0x0008a398u;
goto P_0c08a252;
P_0c08a252: /* original f608, guest PC 0x0c08a252 */
if(!s->budget--) { s->failed_pc=0x0c08a252u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c08a254;
P_0c08a254: /* original e004, guest PC 0x0c08a254 */
if(!s->budget--) { s->failed_pc=0x0c08a254u; return 0; }
r[0]=0x00000004u;
goto P_0c08a256;
P_0c08a256: /* original 740c, guest PC 0x0c08a256 */
if(!s->budget--) { s->failed_pc=0x0c08a256u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a258;
P_0c08a258: /* original f58c, guest PC 0x0c08a258 */
if(!s->budget--) { s->failed_pc=0x0c08a258u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c08a25a;
P_0c08a25a: /* original f4aa, guest PC 0x0c08a25a */
if(!s->budget--) { s->failed_pc=0x0c08a25au; return 0; }
vf3_matrix_store(s,ram,10,r[4]);
goto P_0c08a25c;
P_0c08a25c: /* original f457, guest PC 0x0c08a25c */
if(!s->budget--) { s->failed_pc=0x0c08a25cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a25e;
P_0c08a25e: /* original e008, guest PC 0x0c08a25e */
if(!s->budget--) { s->failed_pc=0x0c08a25eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a260;
P_0c08a260: /* original f447, guest PC 0x0c08a260 */
if(!s->budget--) { s->failed_pc=0x0c08a260u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a262;
P_0c08a262: /* original e004, guest PC 0x0c08a262 */
if(!s->budget--) { s->failed_pc=0x0c08a262u; return 0; }
r[0]=0x00000004u;
goto P_0c08a264;
P_0c08a264: /* original 740c, guest PC 0x0c08a264 */
if(!s->budget--) { s->failed_pc=0x0c08a264u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a266;
P_0c08a266: /* original f47a, guest PC 0x0c08a266 */
if(!s->budget--) { s->failed_pc=0x0c08a266u; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a268;
P_0c08a268: /* original f457, guest PC 0x0c08a268 */
if(!s->budget--) { s->failed_pc=0x0c08a268u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a26a;
P_0c08a26a: /* original e008, guest PC 0x0c08a26a */
if(!s->budget--) { s->failed_pc=0x0c08a26au; return 0; }
r[0]=0x00000008u;
goto P_0c08a26c;
P_0c08a26c: /* original f477, guest PC 0x0c08a26c */
if(!s->budget--) { s->failed_pc=0x0c08a26cu; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a26e;
P_0c08a26e: /* original e004, guest PC 0x0c08a26e */
if(!s->budget--) { s->failed_pc=0x0c08a26eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a270;
P_0c08a270: /* original 740c, guest PC 0x0c08a270 */
if(!s->budget--) { s->failed_pc=0x0c08a270u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a272;
P_0c08a272: /* original f44a, guest PC 0x0c08a272 */
if(!s->budget--) { s->failed_pc=0x0c08a272u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a274;
P_0c08a274: /* original f457, guest PC 0x0c08a274 */
if(!s->budget--) { s->failed_pc=0x0c08a274u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a276;
P_0c08a276: /* original e008, guest PC 0x0c08a276 */
if(!s->budget--) { s->failed_pc=0x0c08a276u; return 0; }
r[0]=0x00000008u;
goto P_0c08a278;
P_0c08a278: /* original f4a7, guest PC 0x0c08a278 */
if(!s->budget--) { s->failed_pc=0x0c08a278u; return 0; }
vf3_matrix_store(s,ram,10,r[4]+r[0]);
goto P_0c08a27a;
P_0c08a27a: /* original 740c, guest PC 0x0c08a27a */
if(!s->budget--) { s->failed_pc=0x0c08a27au; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a27c;
P_0c08a27c: /* original e004, guest PC 0x0c08a27c */
if(!s->budget--) { s->failed_pc=0x0c08a27cu; return 0; }
r[0]=0x00000004u;
goto P_0c08a27e;
P_0c08a27e: /* original f46a, guest PC 0x0c08a27e */
if(!s->budget--) { s->failed_pc=0x0c08a27eu; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a280;
P_0c08a280: /* original f457, guest PC 0x0c08a280 */
if(!s->budget--) { s->failed_pc=0x0c08a280u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a282;
P_0c08a282: /* original e008, guest PC 0x0c08a282 */
if(!s->budget--) { s->failed_pc=0x0c08a282u; return 0; }
r[0]=0x00000008u;
goto P_0c08a284;
P_0c08a284: /* original f477, guest PC 0x0c08a284 */
if(!s->budget--) { s->failed_pc=0x0c08a284u; return 0; }
vf3_matrix_store(s,ram,7,r[4]+r[0]);
goto P_0c08a286;
P_0c08a286: /* original e004, guest PC 0x0c08a286 */
if(!s->budget--) { s->failed_pc=0x0c08a286u; return 0; }
r[0]=0x00000004u;
goto P_0c08a288;
P_0c08a288: /* original 740c, guest PC 0x0c08a288 */
if(!s->budget--) { s->failed_pc=0x0c08a288u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a28a;
P_0c08a28a: /* original f49a, guest PC 0x0c08a28a */
if(!s->budget--) { s->failed_pc=0x0c08a28au; return 0; }
vf3_matrix_store(s,ram,9,r[4]);
goto P_0c08a28c;
P_0c08a28c: /* original f457, guest PC 0x0c08a28c */
if(!s->budget--) { s->failed_pc=0x0c08a28cu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a28e;
P_0c08a28e: /* original e008, guest PC 0x0c08a28e */
if(!s->budget--) { s->failed_pc=0x0c08a28eu; return 0; }
r[0]=0x00000008u;
goto P_0c08a290;
P_0c08a290: /* original f447, guest PC 0x0c08a290 */
if(!s->budget--) { s->failed_pc=0x0c08a290u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c08a292;
P_0c08a292: /* original e004, guest PC 0x0c08a292 */
if(!s->budget--) { s->failed_pc=0x0c08a292u; return 0; }
r[0]=0x00000004u;
goto P_0c08a294;
P_0c08a294: /* original 740c, guest PC 0x0c08a294 */
if(!s->budget--) { s->failed_pc=0x0c08a294u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a296;
P_0c08a296: /* original f46a, guest PC 0x0c08a296 */
if(!s->budget--) { s->failed_pc=0x0c08a296u; return 0; }
vf3_matrix_store(s,ram,6,r[4]);
goto P_0c08a298;
P_0c08a298: /* original f457, guest PC 0x0c08a298 */
if(!s->budget--) { s->failed_pc=0x0c08a298u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a29a;
P_0c08a29a: /* original e008, guest PC 0x0c08a29a */
if(!s->budget--) { s->failed_pc=0x0c08a29au; return 0; }
r[0]=0x00000008u;
goto P_0c08a29c;
P_0c08a29c: /* original f467, guest PC 0x0c08a29c */
if(!s->budget--) { s->failed_pc=0x0c08a29cu; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a29e;
P_0c08a29e: /* original e004, guest PC 0x0c08a29e */
if(!s->budget--) { s->failed_pc=0x0c08a29eu; return 0; }
r[0]=0x00000004u;
goto P_0c08a2a0;
P_0c08a2a0: /* original 740c, guest PC 0x0c08a2a0 */
if(!s->budget--) { s->failed_pc=0x0c08a2a0u; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2a2;
P_0c08a2a2: /* original f44a, guest PC 0x0c08a2a2 */
if(!s->budget--) { s->failed_pc=0x0c08a2a2u; return 0; }
vf3_matrix_store(s,ram,4,r[4]);
goto P_0c08a2a4;
P_0c08a2a4: /* original f457, guest PC 0x0c08a2a4 */
if(!s->budget--) { s->failed_pc=0x0c08a2a4u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2a6;
P_0c08a2a6: /* original e008, guest PC 0x0c08a2a6 */
if(!s->budget--) { s->failed_pc=0x0c08a2a6u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2a8;
P_0c08a2a8: /* original f497, guest PC 0x0c08a2a8 */
if(!s->budget--) { s->failed_pc=0x0c08a2a8u; return 0; }
vf3_matrix_store(s,ram,9,r[4]+r[0]);
goto P_0c08a2aa;
P_0c08a2aa: /* original e004, guest PC 0x0c08a2aa */
if(!s->budget--) { s->failed_pc=0x0c08a2aau; return 0; }
r[0]=0x00000004u;
goto P_0c08a2ac;
P_0c08a2ac: /* original 740c, guest PC 0x0c08a2ac */
if(!s->budget--) { s->failed_pc=0x0c08a2acu; return 0; }
r[4]+=0x0000000cu;
goto P_0c08a2ae;
P_0c08a2ae: /* original f47a, guest PC 0x0c08a2ae */
if(!s->budget--) { s->failed_pc=0x0c08a2aeu; return 0; }
vf3_matrix_store(s,ram,7,r[4]);
goto P_0c08a2b0;
P_0c08a2b0: /* original f457, guest PC 0x0c08a2b0 */
if(!s->budget--) { s->failed_pc=0x0c08a2b0u; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c08a2b2;
P_0c08a2b2: /* original e008, guest PC 0x0c08a2b2 */
if(!s->budget--) { s->failed_pc=0x0c08a2b2u; return 0; }
r[0]=0x00000008u;
goto P_0c08a2b4;
P_0c08a2b4: /* original f467, guest PC 0x0c08a2b4 */
if(!s->budget--) { s->failed_pc=0x0c08a2b4u; return 0; }
vf3_matrix_store(s,ram,6,r[4]+r[0]);
goto P_0c08a2b6;
P_0c08a2b6: /* original d339, guest PC 0x0c08a2b6 */
if(!s->budget--) { s->failed_pc=0x0c08a2b6u; return 0; }
r[3]=read(ram,0x0c08a39cu,4);
goto P_0c08a2b8;
P_0c08a2b8: /* original 430b, guest PC 0x0c08a2b8 */
if(!s->budget--) { s->failed_pc=0x0c08a2b8u; return 0; }
target=r[3];
r[16]=code_base|0x0c08a2bcu;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c08a2bcu) { target=s->pc; goto dispatch; }
goto P_0c08a2bc;
P_0c08a2ba: /* original e401, guest PC 0x0c08a2ba */
if(!s->budget--) { s->failed_pc=0x0c08a2bau; return 0; }
r[4]=0x00000001u;
goto P_0c08a2bc;
P_0c08a2bc: /* original 7f40, guest PC 0x0c08a2bc */
if(!s->budget--) { s->failed_pc=0x0c08a2bcu; return 0; }
r[15]+=0x00000040u;
goto P_0c08a2be;
P_0c08a2be: /* original 4f26, guest PC 0x0c08a2be */
if(!s->budget--) { s->failed_pc=0x0c08a2beu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c08a2c0;
P_0c08a2c0: /* original fff9, guest PC 0x0c08a2c0 */
if(!s->budget--) { s->failed_pc=0x0c08a2c0u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c08a2c2;
P_0c08a2c2: /* original 6bf6, guest PC 0x0c08a2c2 */
if(!s->budget--) { s->failed_pc=0x0c08a2c2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c08a2c4;
P_0c08a2c4: /* original 6cf6, guest PC 0x0c08a2c4 */
if(!s->budget--) { s->failed_pc=0x0c08a2c4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c08a2c6;
P_0c08a2c6: /* original 6df6, guest PC 0x0c08a2c6 */
if(!s->budget--) { s->failed_pc=0x0c08a2c6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c08a2c8;
P_0c08a2c8: /* original 000b, guest PC 0x0c08a2c8 */
if(!s->budget--) { s->failed_pc=0x0c08a2c8u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c08a2ca: /* original 6ef6, guest PC 0x0c08a2ca */
if(!s->budget--) { s->failed_pc=0x0c08a2cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c08a2ccu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c08a2ccu; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
