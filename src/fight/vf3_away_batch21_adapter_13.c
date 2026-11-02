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
int vf3_away_batch21_adapter_13(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0a9e60u: goto P_0c0a9e60;
case 0x0c0a9e62u: goto P_0c0a9e62;
case 0x0c0a9e64u: goto P_0c0a9e64;
case 0x0c0a9e66u: goto P_0c0a9e66;
case 0x0c0a9e68u: goto P_0c0a9e68;
case 0x0c0a9e6au: goto P_0c0a9e6a;
case 0x0c0a9e6cu: goto P_0c0a9e6c;
case 0x0c0a9e6eu: goto P_0c0a9e6e;
case 0x0c0a9e70u: goto P_0c0a9e70;
case 0x0c0a9e72u: goto P_0c0a9e72;
case 0x0c0a9e74u: goto P_0c0a9e74;
case 0x0c0a9e76u: goto P_0c0a9e76;
case 0x0c0a9e78u: goto P_0c0a9e78;
case 0x0c0a9e7au: goto P_0c0a9e7a;
case 0x0c0a9e7cu: goto P_0c0a9e7c;
case 0x0c0a9ea4u: goto P_0c0a9ea4;
case 0x0c0a9ea6u: goto P_0c0a9ea6;
case 0x0c0a9ea8u: goto P_0c0a9ea8;
case 0x0c0a9eaau: goto P_0c0a9eaa;
case 0x0c0a9eacu: goto P_0c0a9eac;
case 0x0c0a9eaeu: goto P_0c0a9eae;
case 0x0c0a9eb0u: goto P_0c0a9eb0;
case 0x0c0a9eb2u: goto P_0c0a9eb2;
case 0x0c0a9eb4u: goto P_0c0a9eb4;
case 0x0c0a9eb6u: goto P_0c0a9eb6;
case 0x0c0a9eb8u: goto P_0c0a9eb8;
case 0x0c0a9ebau: goto P_0c0a9eba;
case 0x0c0a9ebcu: goto P_0c0a9ebc;
case 0x0c0a9ebeu: goto P_0c0a9ebe;
case 0x0c0a9ec0u: goto P_0c0a9ec0;
case 0x0c0a9ec2u: goto P_0c0a9ec2;
case 0x0c0a9ec4u: goto P_0c0a9ec4;
case 0x0c0a9ec6u: goto P_0c0a9ec6;
case 0x0c0a9ec8u: goto P_0c0a9ec8;
case 0x0c0a9ecau: goto P_0c0a9eca;
case 0x0c0a9eccu: goto P_0c0a9ecc;
case 0x0c0a9eceu: goto P_0c0a9ece;
case 0x0c0a9ed0u: goto P_0c0a9ed0;
case 0x0c0a9ed2u: goto P_0c0a9ed2;
case 0x0c0a9ed4u: goto P_0c0a9ed4;
case 0x0c0a9ed6u: goto P_0c0a9ed6;
case 0x0c0a9ed8u: goto P_0c0a9ed8;
case 0x0c0a9edau: goto P_0c0a9eda;
case 0x0c0a9edcu: goto P_0c0a9edc;
case 0x0c0a9edeu: goto P_0c0a9ede;
case 0x0c0a9ee0u: goto P_0c0a9ee0;
case 0x0c0a9ee2u: goto P_0c0a9ee2;
case 0x0c0a9ee4u: goto P_0c0a9ee4;
case 0x0c0a9ee6u: goto P_0c0a9ee6;
case 0x0c0a9ee8u: goto P_0c0a9ee8;
case 0x0c0a9eeau: goto P_0c0a9eea;
case 0x0c0a9eecu: goto P_0c0a9eec;
case 0x0c0a9eeeu: goto P_0c0a9eee;
case 0x0c0a9ef0u: goto P_0c0a9ef0;
case 0x0c0a9ef2u: goto P_0c0a9ef2;
case 0x0c0a9ef4u: goto P_0c0a9ef4;
case 0x0c0a9ef6u: goto P_0c0a9ef6;
case 0x0c0a9ef8u: goto P_0c0a9ef8;
case 0x0c0a9efau: goto P_0c0a9efa;
case 0x0c0a9efcu: goto P_0c0a9efc;
case 0x0c0a9efeu: goto P_0c0a9efe;
case 0x0c0a9f00u: goto P_0c0a9f00;
case 0x0c0a9f02u: goto P_0c0a9f02;
case 0x0c0a9f04u: goto P_0c0a9f04;
case 0x0c0a9f06u: goto P_0c0a9f06;
case 0x0c0a9f08u: goto P_0c0a9f08;
case 0x0c0a9f0au: goto P_0c0a9f0a;
case 0x0c0a9f0cu: goto P_0c0a9f0c;
case 0x0c0a9f0eu: goto P_0c0a9f0e;
case 0x0c0a9f10u: goto P_0c0a9f10;
case 0x0c0a9f12u: goto P_0c0a9f12;
case 0x0c0a9f14u: goto P_0c0a9f14;
case 0x0c0a9f16u: goto P_0c0a9f16;
case 0x0c0a9f18u: goto P_0c0a9f18;
case 0x0c0a9f1au: goto P_0c0a9f1a;
case 0x0c0a9f1cu: goto P_0c0a9f1c;
case 0x0c0a9f1eu: goto P_0c0a9f1e;
case 0x0c0a9f20u: goto P_0c0a9f20;
case 0x0c0a9f22u: goto P_0c0a9f22;
case 0x0c0a9f24u: goto P_0c0a9f24;
case 0x0c0a9f26u: goto P_0c0a9f26;
case 0x0c0a9f28u: goto P_0c0a9f28;
case 0x0c0a9f2au: goto P_0c0a9f2a;
case 0x0c0a9f2cu: goto P_0c0a9f2c;
case 0x0c0a9f2eu: goto P_0c0a9f2e;
case 0x0c0a9f30u: goto P_0c0a9f30;
case 0x0c0a9f32u: goto P_0c0a9f32;
case 0x0c0a9f34u: goto P_0c0a9f34;
case 0x0c0a9f36u: goto P_0c0a9f36;
case 0x0c0a9f38u: goto P_0c0a9f38;
case 0x0c0a9f3au: goto P_0c0a9f3a;
case 0x0c0a9f3cu: goto P_0c0a9f3c;
case 0x0c0a9f3eu: goto P_0c0a9f3e;
case 0x0c0a9f40u: goto P_0c0a9f40;
case 0x0c0a9f42u: goto P_0c0a9f42;
case 0x0c0a9f44u: goto P_0c0a9f44;
case 0x0c0a9f46u: goto P_0c0a9f46;
case 0x0c0a9f48u: goto P_0c0a9f48;
case 0x0c0a9f4au: goto P_0c0a9f4a;
case 0x0c0a9f4cu: goto P_0c0a9f4c;
case 0x0c0a9f4eu: goto P_0c0a9f4e;
case 0x0c0a9f50u: goto P_0c0a9f50;
case 0x0c0a9f52u: goto P_0c0a9f52;
case 0x0c0a9f54u: goto P_0c0a9f54;
case 0x0c0a9f56u: goto P_0c0a9f56;
case 0x0c0a9f58u: goto P_0c0a9f58;
case 0x0c0a9f5au: goto P_0c0a9f5a;
case 0x0c0a9f5cu: goto P_0c0a9f5c;
case 0x0c0a9f5eu: goto P_0c0a9f5e;
case 0x0c0a9f60u: goto P_0c0a9f60;
case 0x0c0a9f62u: goto P_0c0a9f62;
case 0x0c0a9f64u: goto P_0c0a9f64;
case 0x0c0a9f66u: goto P_0c0a9f66;
case 0x0c0a9f68u: goto P_0c0a9f68;
case 0x0c0a9f6au: goto P_0c0a9f6a;
case 0x0c0a9f6cu: goto P_0c0a9f6c;
case 0x0c0a9f6eu: goto P_0c0a9f6e;
case 0x0c0a9f70u: goto P_0c0a9f70;
case 0x0c0a9f72u: goto P_0c0a9f72;
case 0x0c0a9f74u: goto P_0c0a9f74;
case 0x0c0a9f76u: goto P_0c0a9f76;
case 0x0c0a9f78u: goto P_0c0a9f78;
case 0x0c0a9f7au: goto P_0c0a9f7a;
case 0x0c0a9f7cu: goto P_0c0a9f7c;
case 0x0c0a9f7eu: goto P_0c0a9f7e;
case 0x0c0a9f80u: goto P_0c0a9f80;
case 0x0c0a9f82u: goto P_0c0a9f82;
case 0x0c0a9f84u: goto P_0c0a9f84;
case 0x0c0a9f86u: goto P_0c0a9f86;
case 0x0c0a9f88u: goto P_0c0a9f88;
case 0x0c0a9f8au: goto P_0c0a9f8a;
case 0x0c0a9f8cu: goto P_0c0a9f8c;
case 0x0c0a9f8eu: goto P_0c0a9f8e;
case 0x0c0a9f90u: goto P_0c0a9f90;
case 0x0c0a9f92u: goto P_0c0a9f92;
case 0x0c0a9f94u: goto P_0c0a9f94;
case 0x0c0a9f96u: goto P_0c0a9f96;
case 0x0c0a9f98u: goto P_0c0a9f98;
case 0x0c0a9f9au: goto P_0c0a9f9a;
case 0x0c0a9f9cu: goto P_0c0a9f9c;
case 0x0c0a9f9eu: goto P_0c0a9f9e;
case 0x0c0a9fa0u: goto P_0c0a9fa0;
case 0x0c0a9fa2u: goto P_0c0a9fa2;
case 0x0c0a9fa4u: goto P_0c0a9fa4;
case 0x0c0a9fa6u: goto P_0c0a9fa6;
case 0x0c0a9fa8u: goto P_0c0a9fa8;
case 0x0c0a9faau: goto P_0c0a9faa;
case 0x0c0a9facu: goto P_0c0a9fac;
case 0x0c0a9faeu: goto P_0c0a9fae;
case 0x0c0aa00au: goto P_0c0aa00a;
case 0x0c0aa00cu: goto P_0c0aa00c;
case 0x0c0aa00eu: goto P_0c0aa00e;
case 0x0c0aa010u: goto P_0c0aa010;
case 0x0c0aa012u: goto P_0c0aa012;
case 0x0c0aa014u: goto P_0c0aa014;
case 0x0c0aa016u: goto P_0c0aa016;
case 0x0c0aa018u: goto P_0c0aa018;
case 0x0c0aa01au: goto P_0c0aa01a;
case 0x0c0aa01cu: goto P_0c0aa01c;
case 0x0c0aa01eu: goto P_0c0aa01e;
case 0x0c0aa020u: goto P_0c0aa020;
case 0x0c0aa022u: goto P_0c0aa022;
case 0x0c0aa024u: goto P_0c0aa024;
case 0x0c0aa026u: goto P_0c0aa026;
case 0x0c0aa028u: goto P_0c0aa028;
case 0x0c0aa02au: goto P_0c0aa02a;
case 0x0c0aa02cu: goto P_0c0aa02c;
case 0x0c0aa02eu: goto P_0c0aa02e;
case 0x0c0aa030u: goto P_0c0aa030;
case 0x0c0aa032u: goto P_0c0aa032;
case 0x0c0aa034u: goto P_0c0aa034;
case 0x0c0aa036u: goto P_0c0aa036;
case 0x0c0aa038u: goto P_0c0aa038;
case 0x0c0aa03au: goto P_0c0aa03a;
case 0x0c0aa03cu: goto P_0c0aa03c;
case 0x0c0aa03eu: goto P_0c0aa03e;
case 0x0c0aa040u: goto P_0c0aa040;
case 0x0c0aa042u: goto P_0c0aa042;
case 0x0c0aa044u: goto P_0c0aa044;
case 0x0c0aa046u: goto P_0c0aa046;
case 0x0c0aa048u: goto P_0c0aa048;
case 0x0c0aa04au: goto P_0c0aa04a;
case 0x0c0aa04cu: goto P_0c0aa04c;
case 0x0c0aa04eu: goto P_0c0aa04e;
case 0x0c0aa050u: goto P_0c0aa050;
case 0x0c0aa052u: goto P_0c0aa052;
case 0x0c0aa054u: goto P_0c0aa054;
case 0x0c0aa056u: goto P_0c0aa056;
case 0x0c0aa058u: goto P_0c0aa058;
case 0x0c0aa05au: goto P_0c0aa05a;
case 0x0c0aa05cu: goto P_0c0aa05c;
case 0x0c0aa05eu: goto P_0c0aa05e;
case 0x0c0aa060u: goto P_0c0aa060;
case 0x0c0aa062u: goto P_0c0aa062;
case 0x0c0aa064u: goto P_0c0aa064;
case 0x0c0aa066u: goto P_0c0aa066;
case 0x0c0aa068u: goto P_0c0aa068;
case 0x0c0aa06au: goto P_0c0aa06a;
case 0x0c0aa06cu: goto P_0c0aa06c;
case 0x0c0aa06eu: goto P_0c0aa06e;
case 0x0c0aa070u: goto P_0c0aa070;
case 0x0c0aa072u: goto P_0c0aa072;
case 0x0c0aa074u: goto P_0c0aa074;
case 0x0c0aa076u: goto P_0c0aa076;
case 0x0c0aa078u: goto P_0c0aa078;
case 0x0c0aa07au: goto P_0c0aa07a;
case 0x0c0aa07cu: goto P_0c0aa07c;
case 0x0c0aa07eu: goto P_0c0aa07e;
case 0x0c0aa080u: goto P_0c0aa080;
case 0x0c0aa082u: goto P_0c0aa082;
case 0x0c0aa084u: goto P_0c0aa084;
case 0x0c0aa086u: goto P_0c0aa086;
case 0x0c0aa088u: goto P_0c0aa088;
case 0x0c0aa08au: goto P_0c0aa08a;
case 0x0c0aa08cu: goto P_0c0aa08c;
case 0x0c0aa08eu: goto P_0c0aa08e;
case 0x0c0aa090u: goto P_0c0aa090;
case 0x0c0aa092u: goto P_0c0aa092;
case 0x0c0aa094u: goto P_0c0aa094;
case 0x0c0aa096u: goto P_0c0aa096;
case 0x0c0aa098u: goto P_0c0aa098;
case 0x0c0aa09au: goto P_0c0aa09a;
case 0x0c0aa09cu: goto P_0c0aa09c;
case 0x0c0aa09eu: goto P_0c0aa09e;
case 0x0c0aa0a0u: goto P_0c0aa0a0;
case 0x0c0aa0a2u: goto P_0c0aa0a2;
case 0x0c0aa0a4u: goto P_0c0aa0a4;
case 0x0c0aa0a6u: goto P_0c0aa0a6;
case 0x0c0aa0a8u: goto P_0c0aa0a8;
case 0x0c0aa0aau: goto P_0c0aa0aa;
case 0x0c0aa0acu: goto P_0c0aa0ac;
case 0x0c0aa0aeu: goto P_0c0aa0ae;
case 0x0c0aa0b0u: goto P_0c0aa0b0;
case 0x0c0aa0b2u: goto P_0c0aa0b2;
case 0x0c0aa0b4u: goto P_0c0aa0b4;
case 0x0c0aa0b6u: goto P_0c0aa0b6;
case 0x0c0aa0b8u: goto P_0c0aa0b8;
case 0x0c0aa0bau: goto P_0c0aa0ba;
case 0x0c0aa0bcu: goto P_0c0aa0bc;
case 0x0c0aa0beu: goto P_0c0aa0be;
case 0x0c0aa0c0u: goto P_0c0aa0c0;
case 0x0c0aa0d0u: goto P_0c0aa0d0;
case 0x0c0aa0d2u: goto P_0c0aa0d2;
case 0x0c0aa0d4u: goto P_0c0aa0d4;
case 0x0c0aa0d6u: goto P_0c0aa0d6;
case 0x0c0aa0d8u: goto P_0c0aa0d8;
case 0x0c0aa0dau: goto P_0c0aa0da;
case 0x0c0aa0dcu: goto P_0c0aa0dc;
case 0x0c0aa0deu: goto P_0c0aa0de;
case 0x0c0aa0e0u: goto P_0c0aa0e0;
case 0x0c0aa0e2u: goto P_0c0aa0e2;
case 0x0c0aa0e4u: goto P_0c0aa0e4;
case 0x0c0aa0e6u: goto P_0c0aa0e6;
case 0x0c0aa0e8u: goto P_0c0aa0e8;
case 0x0c0aa0eau: goto P_0c0aa0ea;
case 0x0c0aa0ecu: goto P_0c0aa0ec;
case 0x0c0aa0eeu: goto P_0c0aa0ee;
case 0x0c0aa0f0u: goto P_0c0aa0f0;
case 0x0c0aa0f2u: goto P_0c0aa0f2;
case 0x0c0aa0f4u: goto P_0c0aa0f4;
case 0x0c0aa0f6u: goto P_0c0aa0f6;
case 0x0c0aa0f8u: goto P_0c0aa0f8;
case 0x0c0aa0fau: goto P_0c0aa0fa;
case 0x0c0aa0fcu: goto P_0c0aa0fc;
case 0x0c0aa0feu: goto P_0c0aa0fe;
case 0x0c0aa1ecu: goto P_0c0aa1ec;
case 0x0c0aa1eeu: goto P_0c0aa1ee;
case 0x0c0aa1f0u: goto P_0c0aa1f0;
case 0x0c0aa1f2u: goto P_0c0aa1f2;
case 0x0c0aa1f4u: goto P_0c0aa1f4;
case 0x0c0aa1f6u: goto P_0c0aa1f6;
case 0x0c0aa1f8u: goto P_0c0aa1f8;
case 0x0c0aa1fau: goto P_0c0aa1fa;
case 0x0c0aa1fcu: goto P_0c0aa1fc;
case 0x0c0aa1feu: goto P_0c0aa1fe;
case 0x0c0aa200u: goto P_0c0aa200;
case 0x0c0aa202u: goto P_0c0aa202;
case 0x0c0aa204u: goto P_0c0aa204;
case 0x0c0aa206u: goto P_0c0aa206;
case 0x0c0aa208u: goto P_0c0aa208;
case 0x0c0aa20au: goto P_0c0aa20a;
case 0x0c0aa20cu: goto P_0c0aa20c;
case 0x0c0aa20eu: goto P_0c0aa20e;
case 0x0c0aa210u: goto P_0c0aa210;
case 0x0c0aa212u: goto P_0c0aa212;
case 0x0c0aa214u: goto P_0c0aa214;
case 0x0c0aa216u: goto P_0c0aa216;
case 0x0c0aa218u: goto P_0c0aa218;
case 0x0c0aa21au: goto P_0c0aa21a;
case 0x0c0aa21cu: goto P_0c0aa21c;
case 0x0c0aa21eu: goto P_0c0aa21e;
case 0x0c0aa220u: goto P_0c0aa220;
case 0x0c0aa222u: goto P_0c0aa222;
case 0x0c0aa224u: goto P_0c0aa224;
case 0x0c0aa226u: goto P_0c0aa226;
case 0x0c0aa228u: goto P_0c0aa228;
case 0x0c0aa22au: goto P_0c0aa22a;
case 0x0c0aa22cu: goto P_0c0aa22c;
case 0x0c0aa22eu: goto P_0c0aa22e;
case 0x0c0aa230u: goto P_0c0aa230;
case 0x0c0aa232u: goto P_0c0aa232;
case 0x0c0aa234u: goto P_0c0aa234;
case 0x0c0aa236u: goto P_0c0aa236;
case 0x0c0aa238u: goto P_0c0aa238;
case 0x0c0aa23au: goto P_0c0aa23a;
case 0x0c0aa23cu: goto P_0c0aa23c;
case 0x0c0aa23eu: goto P_0c0aa23e;
case 0x0c0aa240u: goto P_0c0aa240;
case 0x0c0aa242u: goto P_0c0aa242;
case 0x0c0aa244u: goto P_0c0aa244;
case 0x0c0aa246u: goto P_0c0aa246;
case 0x0c0aa248u: goto P_0c0aa248;
case 0x0c0aa24au: goto P_0c0aa24a;
case 0x0c0aa24cu: goto P_0c0aa24c;
case 0x0c0aa24eu: goto P_0c0aa24e;
case 0x0c0aa250u: goto P_0c0aa250;
case 0x0c0aa252u: goto P_0c0aa252;
case 0x0c0aa254u: goto P_0c0aa254;
case 0x0c0aa256u: goto P_0c0aa256;
case 0x0c0aa258u: goto P_0c0aa258;
case 0x0c0aa25au: goto P_0c0aa25a;
case 0x0c0aa25cu: goto P_0c0aa25c;
case 0x0c0aa25eu: goto P_0c0aa25e;
case 0x0c0aa260u: goto P_0c0aa260;
case 0x0c0aa262u: goto P_0c0aa262;
case 0x0c0aa264u: goto P_0c0aa264;
case 0x0c0aa266u: goto P_0c0aa266;
case 0x0c0aa268u: goto P_0c0aa268;
case 0x0c0aa26au: goto P_0c0aa26a;
case 0x0c0aa26cu: goto P_0c0aa26c;
case 0x0c0aa26eu: goto P_0c0aa26e;
case 0x0c0aa270u: goto P_0c0aa270;
case 0x0c0aa272u: goto P_0c0aa272;
case 0x0c0aa274u: goto P_0c0aa274;
case 0x0c0aa276u: goto P_0c0aa276;
case 0x0c0aa278u: goto P_0c0aa278;
case 0x0c0aa27au: goto P_0c0aa27a;
case 0x0c0aa27cu: goto P_0c0aa27c;
case 0x0c0aa27eu: goto P_0c0aa27e;
case 0x0c0aa280u: goto P_0c0aa280;
case 0x0c0aa282u: goto P_0c0aa282;
case 0x0c0aa284u: goto P_0c0aa284;
case 0x0c0aa286u: goto P_0c0aa286;
case 0x0c0aa288u: goto P_0c0aa288;
case 0x0c0aa28au: goto P_0c0aa28a;
case 0x0c0aa28cu: goto P_0c0aa28c;
case 0x0c0aa28eu: goto P_0c0aa28e;
case 0x0c0aa290u: goto P_0c0aa290;
case 0x0c0aa292u: goto P_0c0aa292;
case 0x0c0aa294u: goto P_0c0aa294;
case 0x0c0aa296u: goto P_0c0aa296;
case 0x0c0aa298u: goto P_0c0aa298;
case 0x0c0aa29au: goto P_0c0aa29a;
case 0x0c0aa29cu: goto P_0c0aa29c;
case 0x0c0aa29eu: goto P_0c0aa29e;
case 0x0c0aa2a0u: goto P_0c0aa2a0;
case 0x0c0aa2a2u: goto P_0c0aa2a2;
case 0x0c0aa2c8u: goto P_0c0aa2c8;
case 0x0c0aa2cau: goto P_0c0aa2ca;
case 0x0c0aa2ccu: goto P_0c0aa2cc;
case 0x0c0aa2ceu: goto P_0c0aa2ce;
case 0x0c0aa2d0u: goto P_0c0aa2d0;
case 0x0c0aa2d2u: goto P_0c0aa2d2;
case 0x0c0aa2d4u: goto P_0c0aa2d4;
case 0x0c0aa2d6u: goto P_0c0aa2d6;
case 0x0c0aa2d8u: goto P_0c0aa2d8;
case 0x0c0aa2dau: goto P_0c0aa2da;
case 0x0c0aa2dcu: goto P_0c0aa2dc;
case 0x0c0aa2deu: goto P_0c0aa2de;
case 0x0c0aa2e0u: goto P_0c0aa2e0;
case 0x0c0aa2e2u: goto P_0c0aa2e2;
case 0x0c0aa2e4u: goto P_0c0aa2e4;
case 0x0c0aa2e6u: goto P_0c0aa2e6;
case 0x0c0aa2e8u: goto P_0c0aa2e8;
case 0x0c0aa2eau: goto P_0c0aa2ea;
case 0x0c0aa2ecu: goto P_0c0aa2ec;
case 0x0c0aa2eeu: goto P_0c0aa2ee;
case 0x0c0aa2f0u: goto P_0c0aa2f0;
case 0x0c0aa2f2u: goto P_0c0aa2f2;
case 0x0c0aa2f4u: goto P_0c0aa2f4;
case 0x0c0aa2f6u: goto P_0c0aa2f6;
case 0x0c0aa2f8u: goto P_0c0aa2f8;
case 0x0c0aa2fau: goto P_0c0aa2fa;
case 0x0c0aa2fcu: goto P_0c0aa2fc;
case 0x0c0aa2feu: goto P_0c0aa2fe;
case 0x0c0aa300u: goto P_0c0aa300;
case 0x0c0aa302u: goto P_0c0aa302;
case 0x0c0aa304u: goto P_0c0aa304;
case 0x0c0aa306u: goto P_0c0aa306;
case 0x0c0aa308u: goto P_0c0aa308;
case 0x0c0aa30au: goto P_0c0aa30a;
case 0x0c0aa30cu: goto P_0c0aa30c;
case 0x0c0aa30eu: goto P_0c0aa30e;
case 0x0c0aa310u: goto P_0c0aa310;
case 0x0c0aa312u: goto P_0c0aa312;
case 0x0c0aa314u: goto P_0c0aa314;
case 0x0c0aa316u: goto P_0c0aa316;
case 0x0c0aa318u: goto P_0c0aa318;
case 0x0c0aa31au: goto P_0c0aa31a;
case 0x0c0aa31cu: goto P_0c0aa31c;
case 0x0c0aa31eu: goto P_0c0aa31e;
case 0x0c0aa320u: goto P_0c0aa320;
case 0x0c0aa322u: goto P_0c0aa322;
case 0x0c0aa324u: goto P_0c0aa324;
case 0x0c0aa326u: goto P_0c0aa326;
case 0x0c0aa328u: goto P_0c0aa328;
case 0x0c0aa32au: goto P_0c0aa32a;
case 0x0c0aa32cu: goto P_0c0aa32c;
case 0x0c0aa32eu: goto P_0c0aa32e;
case 0x0c0aa330u: goto P_0c0aa330;
case 0x0c0aa332u: goto P_0c0aa332;
case 0x0c0aa334u: goto P_0c0aa334;
case 0x0c0aa336u: goto P_0c0aa336;
case 0x0c0aa338u: goto P_0c0aa338;
case 0x0c0aa33au: goto P_0c0aa33a;
case 0x0c0aa33cu: goto P_0c0aa33c;
case 0x0c0aa33eu: goto P_0c0aa33e;
case 0x0c0aa340u: goto P_0c0aa340;
case 0x0c0aa342u: goto P_0c0aa342;
case 0x0c0aa344u: goto P_0c0aa344;
case 0x0c0aa346u: goto P_0c0aa346;
case 0x0c0aa348u: goto P_0c0aa348;
case 0x0c0aa34au: goto P_0c0aa34a;
case 0x0c0aa34cu: goto P_0c0aa34c;
case 0x0c0aa34eu: goto P_0c0aa34e;
case 0x0c0aa350u: goto P_0c0aa350;
case 0x0c0aa352u: goto P_0c0aa352;
case 0x0c0aa354u: goto P_0c0aa354;
case 0x0c0aa356u: goto P_0c0aa356;
case 0x0c0aa358u: goto P_0c0aa358;
case 0x0c0aa35au: goto P_0c0aa35a;
case 0x0c0aa35cu: goto P_0c0aa35c;
case 0x0c0aa35eu: goto P_0c0aa35e;
case 0x0c0aa360u: goto P_0c0aa360;
case 0x0c0aa362u: goto P_0c0aa362;
case 0x0c0aa364u: goto P_0c0aa364;
case 0x0c0aa380u: goto P_0c0aa380;
case 0x0c0aa382u: goto P_0c0aa382;
case 0x0c0aa384u: goto P_0c0aa384;
case 0x0c0aa386u: goto P_0c0aa386;
case 0x0c0aa388u: goto P_0c0aa388;
case 0x0c0aa38au: goto P_0c0aa38a;
case 0x0c0aa38cu: goto P_0c0aa38c;
case 0x0c0aa38eu: goto P_0c0aa38e;
case 0x0c0aa390u: goto P_0c0aa390;
case 0x0c0aa392u: goto P_0c0aa392;
case 0x0c0aa394u: goto P_0c0aa394;
case 0x0c0aa396u: goto P_0c0aa396;
case 0x0c0aa398u: goto P_0c0aa398;
case 0x0c0aa39au: goto P_0c0aa39a;
case 0x0c0aa39cu: goto P_0c0aa39c;
case 0x0c0aa39eu: goto P_0c0aa39e;
case 0x0c0aa3a0u: goto P_0c0aa3a0;
case 0x0c0aa3a2u: goto P_0c0aa3a2;
case 0x0c0aa3a4u: goto P_0c0aa3a4;
case 0x0c0aa3a6u: goto P_0c0aa3a6;
case 0x0c0aa3a8u: goto P_0c0aa3a8;
case 0x0c0aa3aau: goto P_0c0aa3aa;
case 0x0c0aa3acu: goto P_0c0aa3ac;
case 0x0c0aa3aeu: goto P_0c0aa3ae;
case 0x0c0aa3b0u: goto P_0c0aa3b0;
case 0x0c0aa3b2u: goto P_0c0aa3b2;
case 0x0c0aa3b4u: goto P_0c0aa3b4;
case 0x0c0aa3b6u: goto P_0c0aa3b6;
case 0x0c0aa3b8u: goto P_0c0aa3b8;
case 0x0c0aa3bau: goto P_0c0aa3ba;
case 0x0c0aa3bcu: goto P_0c0aa3bc;
case 0x0c0aa3beu: goto P_0c0aa3be;
case 0x0c0aa3c0u: goto P_0c0aa3c0;
case 0x0c0aa3c2u: goto P_0c0aa3c2;
case 0x0c0aa3c4u: goto P_0c0aa3c4;
case 0x0c0aa3c6u: goto P_0c0aa3c6;
case 0x0c0aa3c8u: goto P_0c0aa3c8;
case 0x0c0aa3cau: goto P_0c0aa3ca;
case 0x0c0aa3ccu: goto P_0c0aa3cc;
case 0x0c0aa3ceu: goto P_0c0aa3ce;
case 0x0c0aa3d0u: goto P_0c0aa3d0;
case 0x0c0aa3d2u: goto P_0c0aa3d2;
case 0x0c0aa3d4u: goto P_0c0aa3d4;
case 0x0c0aa3d6u: goto P_0c0aa3d6;
case 0x0c0aa3d8u: goto P_0c0aa3d8;
case 0x0c0aa3dau: goto P_0c0aa3da;
case 0x0c0aa3dcu: goto P_0c0aa3dc;
case 0x0c0aa3deu: goto P_0c0aa3de;
case 0x0c0aa3e0u: goto P_0c0aa3e0;
case 0x0c0aa3e2u: goto P_0c0aa3e2;
case 0x0c0aa3e4u: goto P_0c0aa3e4;
case 0x0c0aa3e6u: goto P_0c0aa3e6;
case 0x0c0aa3e8u: goto P_0c0aa3e8;
case 0x0c0aa3eau: goto P_0c0aa3ea;
case 0x0c0aa3ecu: goto P_0c0aa3ec;
case 0x0c0aa3eeu: goto P_0c0aa3ee;
case 0x0c0aa3f0u: goto P_0c0aa3f0;
case 0x0c0aa3f2u: goto P_0c0aa3f2;
case 0x0c0aa3f4u: goto P_0c0aa3f4;
case 0x0c0aa3f6u: goto P_0c0aa3f6;
case 0x0c0aa3f8u: goto P_0c0aa3f8;
case 0x0c0aa444u: goto P_0c0aa444;
case 0x0c0aa446u: goto P_0c0aa446;
case 0x0c0aa448u: goto P_0c0aa448;
case 0x0c0aa44au: goto P_0c0aa44a;
case 0x0c0aa44cu: goto P_0c0aa44c;
case 0x0c0aa44eu: goto P_0c0aa44e;
case 0x0c0aa450u: goto P_0c0aa450;
case 0x0c0aa452u: goto P_0c0aa452;
case 0x0c0aa454u: goto P_0c0aa454;
case 0x0c0aa456u: goto P_0c0aa456;
case 0x0c0aa458u: goto P_0c0aa458;
case 0x0c0aa45au: goto P_0c0aa45a;
case 0x0c0aa45cu: goto P_0c0aa45c;
case 0x0c0aa45eu: goto P_0c0aa45e;
case 0x0c0aa460u: goto P_0c0aa460;
case 0x0c0aa462u: goto P_0c0aa462;
case 0x0c0aa464u: goto P_0c0aa464;
case 0x0c0aa466u: goto P_0c0aa466;
case 0x0c0aa468u: goto P_0c0aa468;
case 0x0c0aa46au: goto P_0c0aa46a;
case 0x0c0aa46cu: goto P_0c0aa46c;
case 0x0c0aa46eu: goto P_0c0aa46e;
case 0x0c0aa470u: goto P_0c0aa470;
case 0x0c0aa472u: goto P_0c0aa472;
case 0x0c0aa474u: goto P_0c0aa474;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0a9e60: /* original 2fe6, guest PC 0x0c0a9e60 */
if(!s->budget--) { s->failed_pc=0x0c0a9e60u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9e62;
P_0c0a9e62: /* original 6e43, guest PC 0x0c0a9e62 */
if(!s->budget--) { s->failed_pc=0x0c0a9e62u; return 0; }
r[14]=r[4];
goto P_0c0a9e64;
P_0c0a9e64: /* original 2fd6, guest PC 0x0c0a9e64 */
if(!s->budget--) { s->failed_pc=0x0c0a9e64u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9e66;
P_0c0a9e66: /* original 2fc6, guest PC 0x0c0a9e66 */
if(!s->budget--) { s->failed_pc=0x0c0a9e66u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0a9e68;
P_0c0a9e68: /* original 54ed, guest PC 0x0c0a9e68 */
if(!s->budget--) { s->failed_pc=0x0c0a9e68u; return 0; }
r[4]=read(ram,r[14]+52,4);
goto P_0c0a9e6a;
P_0c0a9e6a: /* original 4f22, guest PC 0x0c0a9e6a */
if(!s->budget--) { s->failed_pc=0x0c0a9e6au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9e6c;
P_0c0a9e6c: /* original 2448, guest PC 0x0c0a9e6c */
if(!s->budget--) { s->failed_pc=0x0c0a9e6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9e6e;
P_0c0a9e6e: /* original 8d19, guest PC 0x0c0a9e6e */
if(!s->budget--) { s->failed_pc=0x0c0a9e6eu; return 0; }
cond=r[17]&1u;
r[13]=0x00000000u;
if(cond) { goto P_0c0a9ea4; }
goto P_0c0a9e72;
P_0c0a9e70: /* original ed00, guest PC 0x0c0a9e70 */
if(!s->budget--) { s->failed_pc=0x0c0a9e70u; return 0; }
r[13]=0x00000000u;
goto P_0c0a9e72;
P_0c0a9e72: /* original 1e4c, guest PC 0x0c0a9e72 */
if(!s->budget--) { s->failed_pc=0x0c0a9e72u; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c0a9e74;
P_0c0a9e74: /* original 9008, guest PC 0x0c0a9e74 */
if(!s->budget--) { s->failed_pc=0x0c0a9e74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9e88u,2);
goto P_0c0a9e76;
P_0c0a9e76: /* original 0ed6, guest PC 0x0c0a9e76 */
if(!s->budget--) { s->failed_pc=0x0c0a9e76u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9e78;
P_0c0a9e78: /* original 7004, guest PC 0x0c0a9e78 */
if(!s->budget--) { s->failed_pc=0x0c0a9e78u; return 0; }
r[0]+=0x00000004u;
goto P_0c0a9e7a;
P_0c0a9e7a: /* original a06a, guest PC 0x0c0a9e7a */
if(!s->budget--) { s->failed_pc=0x0c0a9e7au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9f52;
P_0c0a9e7c: /* original 0ed6, guest PC 0x0c0a9e7c */
if(!s->budget--) { s->failed_pc=0x0c0a9e7cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
if(!vf3_matrix_family(0x0c0a9e7eu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9e7eu; return 0; } return 1;
P_0c0a9ea4: /* original 9084, guest PC 0x0c0a9ea4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ea4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb0u,2);
goto P_0c0a9ea6;
P_0c0a9ea6: /* original 04ee, guest PC 0x0c0a9ea6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ea6u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0a9ea8;
P_0c0a9ea8: /* original 2448, guest PC 0x0c0a9ea8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ea8u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0a9eaa;
P_0c0a9eaa: /* original 890a, guest PC 0x0c0a9eaa */
if(!s->budget--) { s->failed_pc=0x0c0a9eaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9ec2; }
goto P_0c0a9eac;
P_0c0a9eac: /* original e03e, guest PC 0x0c0a9eac */
if(!s->budget--) { s->failed_pc=0x0c0a9eacu; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9eae;
P_0c0a9eae: /* original 02ed, guest PC 0x0c0a9eae */
if(!s->budget--) { s->failed_pc=0x0c0a9eaeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9eb0;
P_0c0a9eb0: /* original 907f, guest PC 0x0c0a9eb0 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb2u,2);
goto P_0c0a9eb2;
P_0c0a9eb2: /* original 622d, guest PC 0x0c0a9eb2 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb2u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0a9eb4;
P_0c0a9eb4: /* original 03ed, guest PC 0x0c0a9eb4 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9eb6;
P_0c0a9eb6: /* original 3233, guest PC 0x0c0a9eb6 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c0a9eb8;
P_0c0a9eb8: /* original 8b03, guest PC 0x0c0a9eb8 */
if(!s->budget--) { s->failed_pc=0x0c0a9eb8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9ec2; }
goto P_0c0a9eba;
P_0c0a9eba: /* original 1e4c, guest PC 0x0c0a9eba */
if(!s->budget--) { s->failed_pc=0x0c0a9ebau; return 0; }
write(ram,r[14]+48,r[4],4);
goto P_0c0a9ebc;
P_0c0a9ebc: /* original 9078, guest PC 0x0c0a9ebc */
if(!s->budget--) { s->failed_pc=0x0c0a9ebcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb0u,2);
goto P_0c0a9ebe;
P_0c0a9ebe: /* original a04a, guest PC 0x0c0a9ebe */
if(!s->budget--) { s->failed_pc=0x0c0a9ebeu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9f56;
P_0c0a9ec0: /* original 0ed6, guest PC 0x0c0a9ec0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec0u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9ec2;
P_0c0a9ec2: /* original 5cec, guest PC 0x0c0a9ec2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec2u; return 0; }
r[12]=read(ram,r[14]+48,4);
goto P_0c0a9ec4;
P_0c0a9ec4: /* original 64c3, guest PC 0x0c0a9ec4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec4u; return 0; }
r[4]=r[12];
goto P_0c0a9ec6;
P_0c0a9ec6: /* original 4429, guest PC 0x0c0a9ec6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec6u; return 0; }
r[4]>>=16;
goto P_0c0a9ec8;
P_0c0a9ec8: /* original 4419, guest PC 0x0c0a9ec8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ec8u; return 0; }
r[4]>>=8;
goto P_0c0a9eca;
P_0c0a9eca: /* original 6043, guest PC 0x0c0a9eca */
if(!s->budget--) { s->failed_pc=0x0c0a9ecau; return 0; }
r[0]=r[4];
goto P_0c0a9ecc;
P_0c0a9ecc: /* original 8817, guest PC 0x0c0a9ecc */
if(!s->budget--) { s->failed_pc=0x0c0a9eccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0a9ece;
P_0c0a9ece: /* original 8b15, guest PC 0x0c0a9ece */
if(!s->budget--) { s->failed_pc=0x0c0a9eceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9efc; }
goto P_0c0a9ed0;
P_0c0a9ed0: /* original 54ec, guest PC 0x0c0a9ed0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed0u; return 0; }
r[4]=read(ram,r[14]+48,4);
goto P_0c0a9ed2;
P_0c0a9ed2: /* original d339, guest PC 0x0c0a9ed2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed2u; return 0; }
r[3]=read(ram,0x0c0a9fb8u,4);
goto P_0c0a9ed4;
P_0c0a9ed4: /* original 644d, guest PC 0x0c0a9ed4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed4u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9ed6;
P_0c0a9ed6: /* original 430b, guest PC 0x0c0a9ed6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed6u; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9edau;
r[5]=0x0000000fu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9edau) { target=s->pc; goto dispatch; }
goto P_0c0a9eda;
P_0c0a9ed8: /* original e50f, guest PC 0x0c0a9ed8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ed8u; return 0; }
r[5]=0x0000000fu;
goto P_0c0a9eda;
P_0c0a9eda: /* original 6403, guest PC 0x0c0a9eda */
if(!s->budget--) { s->failed_pc=0x0c0a9edau; return 0; }
r[4]=r[0];
goto P_0c0a9edc;
P_0c0a9edc: /* original 8442, guest PC 0x0c0a9edc */
if(!s->budget--) { s->failed_pc=0x0c0a9edcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0a9ede;
P_0c0a9ede: /* original d337, guest PC 0x0c0a9ede */
if(!s->budget--) { s->failed_pc=0x0c0a9edeu; return 0; }
r[3]=read(ram,0x0c0a9fbcu,4);
goto P_0c0a9ee0;
P_0c0a9ee0: /* original 600c, guest PC 0x0c0a9ee0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9ee2;
P_0c0a9ee2: /* original 4018, guest PC 0x0c0a9ee2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee2u; return 0; }
r[0]<<=8;
goto P_0c0a9ee4;
P_0c0a9ee4: /* original 2039, guest PC 0x0c0a9ee4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee4u; return 0; }
r[0]&=r[3];
goto P_0c0a9ee6;
P_0c0a9ee6: /* original 6203, guest PC 0x0c0a9ee6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee6u; return 0; }
r[2]=r[0];
goto P_0c0a9ee8;
P_0c0a9ee8: /* original 8441, guest PC 0x0c0a9ee8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ee8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0a9eea;
P_0c0a9eea: /* original 6423, guest PC 0x0c0a9eea */
if(!s->budget--) { s->failed_pc=0x0c0a9eeau; return 0; }
r[4]=r[2];
goto P_0c0a9eec;
P_0c0a9eec: /* original 600c, guest PC 0x0c0a9eec */
if(!s->budget--) { s->failed_pc=0x0c0a9eecu; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9eee;
P_0c0a9eee: /* original 240b, guest PC 0x0c0a9eee */
if(!s->budget--) { s->failed_pc=0x0c0a9eeeu; return 0; }
r[4]|=r[0];
goto P_0c0a9ef0;
P_0c0a9ef0: /* original 905f, guest PC 0x0c0a9ef0 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb2u,2);
goto P_0c0a9ef2;
P_0c0a9ef2: /* original 74ff, guest PC 0x0c0a9ef2 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef2u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0a9ef4;
P_0c0a9ef4: /* original 0e45, guest PC 0x0c0a9ef4 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef4u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9ef6;
P_0c0a9ef6: /* original 70fc, guest PC 0x0c0a9ef6 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef6u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0a9ef8;
P_0c0a9ef8: /* original a027, guest PC 0x0c0a9ef8 */
if(!s->budget--) { s->failed_pc=0x0c0a9ef8u; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0a9f4a;
P_0c0a9efa: /* original 0ec6, guest PC 0x0c0a9efa */
if(!s->budget--) { s->failed_pc=0x0c0a9efau; return 0; }
write(ram,r[14]+r[0],r[12],4);
goto P_0c0a9efc;
P_0c0a9efc: /* original 881b, guest PC 0x0c0a9efc */
if(!s->budget--) { s->failed_pc=0x0c0a9efcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001bu)!=0);
goto P_0c0a9efe;
P_0c0a9efe: /* original 8b1d, guest PC 0x0c0a9efe */
if(!s->budget--) { s->failed_pc=0x0c0a9efeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0a9f3c; }
goto P_0c0a9f00;
P_0c0a9f00: /* original e03e, guest PC 0x0c0a9f00 */
if(!s->budget--) { s->failed_pc=0x0c0a9f00u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9f02;
P_0c0a9f02: /* original 04ed, guest PC 0x0c0a9f02 */
if(!s->budget--) { s->failed_pc=0x0c0a9f02u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f04;
P_0c0a9f04: /* original e042, guest PC 0x0c0a9f04 */
if(!s->budget--) { s->failed_pc=0x0c0a9f04u; return 0; }
r[0]=0x00000042u;
goto P_0c0a9f06;
P_0c0a9f06: /* original 05ed, guest PC 0x0c0a9f06 */
if(!s->budget--) { s->failed_pc=0x0c0a9f06u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f08;
P_0c0a9f08: /* original e040, guest PC 0x0c0a9f08 */
if(!s->budget--) { s->failed_pc=0x0c0a9f08u; return 0; }
r[0]=0x00000040u;
goto P_0c0a9f0a;
P_0c0a9f0a: /* original 06ed, guest PC 0x0c0a9f0a */
if(!s->budget--) { s->failed_pc=0x0c0a9f0au; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f0c;
P_0c0a9f0c: /* original 644d, guest PC 0x0c0a9f0c */
if(!s->budget--) { s->failed_pc=0x0c0a9f0cu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0a9f0e;
P_0c0a9f0e: /* original 655d, guest PC 0x0c0a9f0e */
if(!s->budget--) { s->failed_pc=0x0c0a9f0eu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a9f10;
P_0c0a9f10: /* original 6353, guest PC 0x0c0a9f10 */
if(!s->budget--) { s->failed_pc=0x0c0a9f10u; return 0; }
r[3]=r[5];
goto P_0c0a9f12;
P_0c0a9f12: /* original 4500, guest PC 0x0c0a9f12 */
if(!s->budget--) { s->failed_pc=0x0c0a9f12u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>>31)!=0);
r[5]<<=1;
goto P_0c0a9f14;
P_0c0a9f14: /* original 4428, guest PC 0x0c0a9f14 */
if(!s->budget--) { s->failed_pc=0x0c0a9f14u; return 0; }
r[4]<<=16;
goto P_0c0a9f16;
P_0c0a9f16: /* original 353c, guest PC 0x0c0a9f16 */
if(!s->budget--) { s->failed_pc=0x0c0a9f16u; return 0; }
r[5]+=r[3];
goto P_0c0a9f18;
P_0c0a9f18: /* original 666d, guest PC 0x0c0a9f18 */
if(!s->budget--) { s->failed_pc=0x0c0a9f18u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0a9f1a;
P_0c0a9f1a: /* original 246b, guest PC 0x0c0a9f1a */
if(!s->budget--) { s->failed_pc=0x0c0a9f1au; return 0; }
r[4]|=r[6];
goto P_0c0a9f1c;
P_0c0a9f1c: /* original 4518, guest PC 0x0c0a9f1c */
if(!s->budget--) { s->failed_pc=0x0c0a9f1cu; return 0; }
r[5]<<=8;
goto P_0c0a9f1e;
P_0c0a9f1e: /* original 345c, guest PC 0x0c0a9f1e */
if(!s->budget--) { s->failed_pc=0x0c0a9f1eu; return 0; }
r[4]+=r[5];
goto P_0c0a9f20;
P_0c0a9f20: /* original 0e45, guest PC 0x0c0a9f20 */
if(!s->budget--) { s->failed_pc=0x0c0a9f20u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9f22;
P_0c0a9f22: /* original 4429, guest PC 0x0c0a9f22 */
if(!s->budget--) { s->failed_pc=0x0c0a9f22u; return 0; }
r[4]>>=16;
goto P_0c0a9f24;
P_0c0a9f24: /* original 9046, guest PC 0x0c0a9f24 */
if(!s->budget--) { s->failed_pc=0x0c0a9f24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb4u,2);
goto P_0c0a9f26;
P_0c0a9f26: /* original 05ed, guest PC 0x0c0a9f26 */
if(!s->budget--) { s->failed_pc=0x0c0a9f26u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0a9f28;
P_0c0a9f28: /* original 655d, guest PC 0x0c0a9f28 */
if(!s->budget--) { s->failed_pc=0x0c0a9f28u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0a9f2a;
P_0c0a9f2a: /* original 75ff, guest PC 0x0c0a9f2a */
if(!s->budget--) { s->failed_pc=0x0c0a9f2au; return 0; }
r[5]+=0xffffffffu;
goto P_0c0a9f2c;
P_0c0a9f2c: /* original 3452, guest PC 0x0c0a9f2c */
if(!s->budget--) { s->failed_pc=0x0c0a9f2cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[5])!=0);
goto P_0c0a9f2e;
P_0c0a9f2e: /* original 8902, guest PC 0x0c0a9f2e */
if(!s->budget--) { s->failed_pc=0x0c0a9f2eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f36; }
goto P_0c0a9f30;
P_0c0a9f30: /* original e03e, guest PC 0x0c0a9f30 */
if(!s->budget--) { s->failed_pc=0x0c0a9f30u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9f32;
P_0c0a9f32: /* original a00a, guest PC 0x0c0a9f32 */
if(!s->budget--) { s->failed_pc=0x0c0a9f32u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9f4a;
P_0c0a9f34: /* original 0e45, guest PC 0x0c0a9f34 */
if(!s->budget--) { s->failed_pc=0x0c0a9f34u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0a9f36;
P_0c0a9f36: /* original e03e, guest PC 0x0c0a9f36 */
if(!s->budget--) { s->failed_pc=0x0c0a9f36u; return 0; }
r[0]=0x0000003eu;
goto P_0c0a9f38;
P_0c0a9f38: /* original a007, guest PC 0x0c0a9f38 */
if(!s->budget--) { s->failed_pc=0x0c0a9f38u; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9f4a;
P_0c0a9f3a: /* original 0e55, guest PC 0x0c0a9f3a */
if(!s->budget--) { s->failed_pc=0x0c0a9f3au; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0a9f3c;
P_0c0a9f3c: /* original 62e2, guest PC 0x0c0a9f3c */
if(!s->budget--) { s->failed_pc=0x0c0a9f3cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0a9f3e;
P_0c0a9f3e: /* original d320, guest PC 0x0c0a9f3e */
if(!s->budget--) { s->failed_pc=0x0c0a9f3eu; return 0; }
r[3]=read(ram,0x0c0a9fc0u,4);
goto P_0c0a9f40;
P_0c0a9f40: /* original 2238, guest PC 0x0c0a9f40 */
if(!s->budget--) { s->failed_pc=0x0c0a9f40u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0a9f42;
P_0c0a9f42: /* original 8904, guest PC 0x0c0a9f42 */
if(!s->budget--) { s->failed_pc=0x0c0a9f42u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f4e; }
goto P_0c0a9f44;
P_0c0a9f44: /* original 6043, guest PC 0x0c0a9f44 */
if(!s->budget--) { s->failed_pc=0x0c0a9f44u; return 0; }
r[0]=r[4];
goto P_0c0a9f46;
P_0c0a9f46: /* original 880b, guest PC 0x0c0a9f46 */
if(!s->budget--) { s->failed_pc=0x0c0a9f46u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0a9f48;
P_0c0a9f48: /* original 8901, guest PC 0x0c0a9f48 */
if(!s->budget--) { s->failed_pc=0x0c0a9f48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f4e; }
goto P_0c0a9f4a;
P_0c0a9f4a: /* original a004, guest PC 0x0c0a9f4a */
if(!s->budget--) { s->failed_pc=0x0c0a9f4au; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c0a9f56;
P_0c0a9f4c: /* original 1edc, guest PC 0x0c0a9f4c */
if(!s->budget--) { s->failed_pc=0x0c0a9f4cu; return 0; }
write(ram,r[14]+48,r[13],4);
goto P_0c0a9f4e;
P_0c0a9f4e: /* original 2cc8, guest PC 0x0c0a9f4e */
if(!s->budget--) { s->failed_pc=0x0c0a9f4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0a9f50;
P_0c0a9f50: /* original 8901, guest PC 0x0c0a9f50 */
if(!s->budget--) { s->failed_pc=0x0c0a9f50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0a9f56; }
goto P_0c0a9f52;
P_0c0a9f52: /* original 902d, guest PC 0x0c0a9f52 */
if(!s->budget--) { s->failed_pc=0x0c0a9f52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0a9fb0u,2);
goto P_0c0a9f54;
P_0c0a9f54: /* original 0ed6, guest PC 0x0c0a9f54 */
if(!s->budget--) { s->failed_pc=0x0c0a9f54u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c0a9f56;
P_0c0a9f56: /* original 4f26, guest PC 0x0c0a9f56 */
if(!s->budget--) { s->failed_pc=0x0c0a9f56u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9f58;
P_0c0a9f58: /* original 6cf6, guest PC 0x0c0a9f58 */
if(!s->budget--) { s->failed_pc=0x0c0a9f58u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0a9f5a;
P_0c0a9f5a: /* original 6df6, guest PC 0x0c0a9f5a */
if(!s->budget--) { s->failed_pc=0x0c0a9f5au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0a9f5c;
P_0c0a9f5c: /* original 000b, guest PC 0x0c0a9f5c */
if(!s->budget--) { s->failed_pc=0x0c0a9f5cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0a9f5e: /* original 6ef6, guest PC 0x0c0a9f5e */
if(!s->budget--) { s->failed_pc=0x0c0a9f5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9f60;
P_0c0a9f60: /* original 534c, guest PC 0x0c0a9f60 */
if(!s->budget--) { s->failed_pc=0x0c0a9f60u; return 0; }
r[3]=read(ram,r[4]+48,4);
goto P_0c0a9f62;
P_0c0a9f62: /* original 4f22, guest PC 0x0c0a9f62 */
if(!s->budget--) { s->failed_pc=0x0c0a9f62u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0a9f64;
P_0c0a9f64: /* original 6233, guest PC 0x0c0a9f64 */
if(!s->budget--) { s->failed_pc=0x0c0a9f64u; return 0; }
r[2]=r[3];
goto P_0c0a9f66;
P_0c0a9f66: /* original 2228, guest PC 0x0c0a9f66 */
if(!s->budget--) { s->failed_pc=0x0c0a9f66u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0a9f68;
P_0c0a9f68: /* original 7ff0, guest PC 0x0c0a9f68 */
if(!s->budget--) { s->failed_pc=0x0c0a9f68u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0a9f6a;
P_0c0a9f6a: /* original 8f06, guest PC 0x0c0a9f6a */
if(!s->budget--) { s->failed_pc=0x0c0a9f6au; return 0; }
cond=r[17]&1u;
write(ram,r[15]+12,r[3],4);
if(!cond) { goto P_0c0a9f7a; }
goto P_0c0a9f6e;
P_0c0a9f6c: /* original 1f33, guest PC 0x0c0a9f6c */
if(!s->budget--) { s->failed_pc=0x0c0a9f6cu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c0a9f6e;
P_0c0a9f6e: /* original b01c, guest PC 0x0c0a9f6e */
if(!s->budget--) { s->failed_pc=0x0c0a9f6eu; return 0; }
target=code_base|0x0c0a9faau; r[16]=code_base|0x0c0a9f72u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9f72u) { target=s->pc; goto dispatch; }
goto P_0c0a9f72;
P_0c0a9f70: /* original 0009, guest PC 0x0c0a9f70 */
if(!s->budget--) { s->failed_pc=0x0c0a9f70u; return 0; }
goto P_0c0a9f72;
P_0c0a9f72: /* original 7f10, guest PC 0x0c0a9f72 */
if(!s->budget--) { s->failed_pc=0x0c0a9f72u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a9f74;
P_0c0a9f74: /* original 4f26, guest PC 0x0c0a9f74 */
if(!s->budget--) { s->failed_pc=0x0c0a9f74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9f76;
P_0c0a9f76: /* original 000b, guest PC 0x0c0a9f76 */
if(!s->budget--) { s->failed_pc=0x0c0a9f76u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9f78: /* original 0009, guest PC 0x0c0a9f78 */
if(!s->budget--) { s->failed_pc=0x0c0a9f78u; return 0; }
goto P_0c0a9f7a;
P_0c0a9f7a: /* original 6243, guest PC 0x0c0a9f7a */
if(!s->budget--) { s->failed_pc=0x0c0a9f7au; return 0; }
r[2]=r[4];
goto P_0c0a9f7c;
P_0c0a9f7c: /* original 7238, guest PC 0x0c0a9f7c */
if(!s->budget--) { s->failed_pc=0x0c0a9f7cu; return 0; }
r[2]+=0x00000038u;
goto P_0c0a9f7e;
P_0c0a9f7e: /* original 8423, guest PC 0x0c0a9f7e */
if(!s->budget--) { s->failed_pc=0x0c0a9f7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+3,1);
goto P_0c0a9f80;
P_0c0a9f80: /* original 66f3, guest PC 0x0c0a9f80 */
if(!s->budget--) { s->failed_pc=0x0c0a9f80u; return 0; }
r[6]=r[15];
goto P_0c0a9f82;
P_0c0a9f82: /* original 600c, guest PC 0x0c0a9f82 */
if(!s->budget--) { s->failed_pc=0x0c0a9f82u; return 0; }
r[0]=r[0]&255u;
goto P_0c0a9f84;
P_0c0a9f84: /* original 1f02, guest PC 0x0c0a9f84 */
if(!s->budget--) { s->failed_pc=0x0c0a9f84u; return 0; }
write(ram,r[15]+8,r[0],4);
goto P_0c0a9f86;
P_0c0a9f86: /* original 53f3, guest PC 0x0c0a9f86 */
if(!s->budget--) { s->failed_pc=0x0c0a9f86u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c0a9f88;
P_0c0a9f88: /* original 4329, guest PC 0x0c0a9f88 */
if(!s->budget--) { s->failed_pc=0x0c0a9f88u; return 0; }
r[3]>>=16;
goto P_0c0a9f8a;
P_0c0a9f8a: /* original 4319, guest PC 0x0c0a9f8a */
if(!s->budget--) { s->failed_pc=0x0c0a9f8au; return 0; }
r[3]>>=8;
goto P_0c0a9f8c;
P_0c0a9f8c: /* original 6033, guest PC 0x0c0a9f8c */
if(!s->budget--) { s->failed_pc=0x0c0a9f8cu; return 0; }
r[0]=r[3];
goto P_0c0a9f8e;
P_0c0a9f8e: /* original c9ff, guest PC 0x0c0a9f8e */
if(!s->budget--) { s->failed_pc=0x0c0a9f8eu; return 0; }
r[0]&=255u;
goto P_0c0a9f90;
P_0c0a9f90: /* original 6303, guest PC 0x0c0a9f90 */
if(!s->budget--) { s->failed_pc=0x0c0a9f90u; return 0; }
r[3]=r[0];
goto P_0c0a9f92;
P_0c0a9f92: /* original 1f01, guest PC 0x0c0a9f92 */
if(!s->budget--) { s->failed_pc=0x0c0a9f92u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c0a9f94;
P_0c0a9f94: /* original d00b, guest PC 0x0c0a9f94 */
if(!s->budget--) { s->failed_pc=0x0c0a9f94u; return 0; }
r[0]=read(ram,0x0c0a9fc4u,4);
goto P_0c0a9f96;
P_0c0a9f96: /* original 4308, guest PC 0x0c0a9f96 */
if(!s->budget--) { s->failed_pc=0x0c0a9f96u; return 0; }
r[3]<<=2;
goto P_0c0a9f98;
P_0c0a9f98: /* original 023e, guest PC 0x0c0a9f98 */
if(!s->budget--) { s->failed_pc=0x0c0a9f98u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0a9f9a;
P_0c0a9f9a: /* original 6323, guest PC 0x0c0a9f9a */
if(!s->budget--) { s->failed_pc=0x0c0a9f9au; return 0; }
r[3]=r[2];
goto P_0c0a9f9c;
P_0c0a9f9c: /* original 2f22, guest PC 0x0c0a9f9c */
if(!s->budget--) { s->failed_pc=0x0c0a9f9cu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0a9f9e;
P_0c0a9f9e: /* original 430b, guest PC 0x0c0a9f9e */
if(!s->budget--) { s->failed_pc=0x0c0a9f9eu; return 0; }
target=r[3];
r[16]=code_base|0x0c0a9fa2u;
r[6]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0a9fa2u) { target=s->pc; goto dispatch; }
goto P_0c0a9fa2;
P_0c0a9fa0: /* original 7604, guest PC 0x0c0a9fa0 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa0u; return 0; }
r[6]+=0x00000004u;
goto P_0c0a9fa2;
P_0c0a9fa2: /* original 7f10, guest PC 0x0c0a9fa2 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa2u; return 0; }
r[15]+=0x00000010u;
goto P_0c0a9fa4;
P_0c0a9fa4: /* original 4f26, guest PC 0x0c0a9fa4 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa4u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0a9fa6;
P_0c0a9fa6: /* original 000b, guest PC 0x0c0a9fa6 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa6u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0a9fa8: /* original 0009, guest PC 0x0c0a9fa8 */
if(!s->budget--) { s->failed_pc=0x0c0a9fa8u; return 0; }
goto P_0c0a9faa;
P_0c0a9faa: /* original e300, guest PC 0x0c0a9faa */
if(!s->budget--) { s->failed_pc=0x0c0a9faau; return 0; }
r[3]=0x00000000u;
goto P_0c0a9fac;
P_0c0a9fac: /* original 000b, guest PC 0x0c0a9fac */
if(!s->budget--) { s->failed_pc=0x0c0a9facu; return 0; }
target=r[16];
write(ram,r[4]+48,r[3],4);
s->pc=target; return ram->oob==0;
P_0c0a9fae: /* original 143c, guest PC 0x0c0a9fae */
if(!s->budget--) { s->failed_pc=0x0c0a9faeu; return 0; }
write(ram,r[4]+48,r[3],4);
if(!vf3_matrix_family(0x0c0a9fb0u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0a9fb0u; return 0; } return 1;
P_0c0aa00a: /* original 2fe6, guest PC 0x0c0aa00a */
if(!s->budget--) { s->failed_pc=0x0c0aa00au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa00c;
P_0c0aa00c: /* original e058, guest PC 0x0c0aa00c */
if(!s->budget--) { s->failed_pc=0x0c0aa00cu; return 0; }
r[0]=0x00000058u;
goto P_0c0aa00e;
P_0c0aa00e: /* original 7ffc, guest PC 0x0c0aa00e */
if(!s->budget--) { s->failed_pc=0x0c0aa00eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa010;
P_0c0aa010: /* original 2f62, guest PC 0x0c0aa010 */
if(!s->budget--) { s->failed_pc=0x0c0aa010u; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0aa012;
P_0c0aa012: /* original 064e, guest PC 0x0c0aa012 */
if(!s->budget--) { s->failed_pc=0x0c0aa012u; return 0; }
r[6]=read(ram,r[4]+r[0],4);
goto P_0c0aa014;
P_0c0aa014: /* original 9055, guest PC 0x0c0aa014 */
if(!s->budget--) { s->failed_pc=0x0c0aa014u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa0c2u,2);
goto P_0c0aa016;
P_0c0aa016: /* original 9355, guest PC 0x0c0aa016 */
if(!s->budget--) { s->failed_pc=0x0c0aa016u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa0c4u,2);
goto P_0c0aa018;
P_0c0aa018: /* original 054e, guest PC 0x0c0aa018 */
if(!s->budget--) { s->failed_pc=0x0c0aa018u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aa01a;
P_0c0aa01a: /* original 2358, guest PC 0x0c0aa01a */
if(!s->budget--) { s->failed_pc=0x0c0aa01au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0aa01c;
P_0c0aa01c: /* original 8b22, guest PC 0x0c0aa01c */
if(!s->budget--) { s->failed_pc=0x0c0aa01cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa064; }
goto P_0c0aa01e;
P_0c0aa01e: /* original e048, guest PC 0x0c0aa01e */
if(!s->budget--) { s->failed_pc=0x0c0aa01eu; return 0; }
r[0]=0x00000048u;
goto P_0c0aa020;
P_0c0aa020: /* original 4528, guest PC 0x0c0aa020 */
if(!s->budget--) { s->failed_pc=0x0c0aa020u; return 0; }
r[5]<<=16;
goto P_0c0aa022;
P_0c0aa022: /* original 074e, guest PC 0x0c0aa022 */
if(!s->budget--) { s->failed_pc=0x0c0aa022u; return 0; }
r[7]=read(ram,r[4]+r[0],4);
goto P_0c0aa024;
P_0c0aa024: /* original 4508, guest PC 0x0c0aa024 */
if(!s->budget--) { s->failed_pc=0x0c0aa024u; return 0; }
r[5]<<=2;
goto P_0c0aa026;
P_0c0aa026: /* original 2579, guest PC 0x0c0aa026 */
if(!s->budget--) { s->failed_pc=0x0c0aa026u; return 0; }
r[5]&=r[7];
goto P_0c0aa028;
P_0c0aa028: /* original d728, guest PC 0x0c0aa028 */
if(!s->budget--) { s->failed_pc=0x0c0aa028u; return 0; }
r[7]=read(ram,0x0c0aa0ccu,4);
goto P_0c0aa02a;
P_0c0aa02a: /* original 2578, guest PC 0x0c0aa02a */
if(!s->budget--) { s->failed_pc=0x0c0aa02au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[7])==0)!=0);
goto P_0c0aa02c;
P_0c0aa02c: /* original 8b1a, guest PC 0x0c0aa02c */
if(!s->budget--) { s->failed_pc=0x0c0aa02cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa064; }
goto P_0c0aa02e;
P_0c0aa02e: /* original 904b, guest PC 0x0c0aa02e */
if(!s->budget--) { s->failed_pc=0x0c0aa02eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa0c8u,2);
goto P_0c0aa030;
P_0c0aa030: /* original 6e63, guest PC 0x0c0aa030 */
if(!s->budget--) { s->failed_pc=0x0c0aa030u; return 0; }
r[14]=r[6];
goto P_0c0aa032;
P_0c0aa032: /* original 7e28, guest PC 0x0c0aa032 */
if(!s->budget--) { s->failed_pc=0x0c0aa032u; return 0; }
r[14]+=0x00000028u;
goto P_0c0aa034;
P_0c0aa034: /* original 054d, guest PC 0x0c0aa034 */
if(!s->budget--) { s->failed_pc=0x0c0aa034u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa036;
P_0c0aa036: /* original 6ee1, guest PC 0x0c0aa036 */
if(!s->budget--) { s->failed_pc=0x0c0aa036u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]=tmp;
goto P_0c0aa038;
P_0c0aa038: /* original 4515, guest PC 0x0c0aa038 */
if(!s->budget--) { s->failed_pc=0x0c0aa038u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>0)!=0);
goto P_0c0aa03a;
P_0c0aa03a: /* original 8f16, guest PC 0x0c0aa03a */
if(!s->budget--) { s->failed_pc=0x0c0aa03au; return 0; }
cond=r[17]&1u;
r[14]=r[14]&65535u;
if(!cond) { goto P_0c0aa06a; }
goto P_0c0aa03e;
P_0c0aa03c: /* original 6eed, guest PC 0x0c0aa03c */
if(!s->budget--) { s->failed_pc=0x0c0aa03cu; return 0; }
r[14]=r[14]&65535u;
goto P_0c0aa03e;
P_0c0aa03e: /* original e050, guest PC 0x0c0aa03e */
if(!s->budget--) { s->failed_pc=0x0c0aa03eu; return 0; }
r[0]=0x00000050u;
goto P_0c0aa040;
P_0c0aa040: /* original 024e, guest PC 0x0c0aa040 */
if(!s->budget--) { s->failed_pc=0x0c0aa040u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0aa042;
P_0c0aa042: /* original 2728, guest PC 0x0c0aa042 */
if(!s->budget--) { s->failed_pc=0x0c0aa042u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0aa044;
P_0c0aa044: /* original 8b0e, guest PC 0x0c0aa044 */
if(!s->budget--) { s->failed_pc=0x0c0aa044u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa064; }
goto P_0c0aa046;
P_0c0aa046: /* original 6e63, guest PC 0x0c0aa046 */
if(!s->budget--) { s->failed_pc=0x0c0aa046u; return 0; }
r[14]=r[6];
goto P_0c0aa048;
P_0c0aa048: /* original e03c, guest PC 0x0c0aa048 */
if(!s->budget--) { s->failed_pc=0x0c0aa048u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa04a;
P_0c0aa04a: /* original 7e2a, guest PC 0x0c0aa04a */
if(!s->budget--) { s->failed_pc=0x0c0aa04au; return 0; }
r[14]+=0x0000002au;
goto P_0c0aa04c;
P_0c0aa04c: /* original 064d, guest PC 0x0c0aa04c */
if(!s->budget--) { s->failed_pc=0x0c0aa04cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0aa04e;
P_0c0aa04e: /* original 6ee1, guest PC 0x0c0aa04e */
if(!s->budget--) { s->failed_pc=0x0c0aa04eu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[14]=tmp;
goto P_0c0aa050;
P_0c0aa050: /* original 666d, guest PC 0x0c0aa050 */
if(!s->budget--) { s->failed_pc=0x0c0aa050u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0aa052;
P_0c0aa052: /* original 6eed, guest PC 0x0c0aa052 */
if(!s->budget--) { s->failed_pc=0x0c0aa052u; return 0; }
r[14]=r[14]&65535u;
goto P_0c0aa054;
P_0c0aa054: /* original 3e60, guest PC 0x0c0aa054 */
if(!s->budget--) { s->failed_pc=0x0c0aa054u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[6])!=0);
goto P_0c0aa056;
P_0c0aa056: /* original 8b02, guest PC 0x0c0aa056 */
if(!s->budget--) { s->failed_pc=0x0c0aa056u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa05e; }
goto P_0c0aa058;
P_0c0aa058: /* original e20a, guest PC 0x0c0aa058 */
if(!s->budget--) { s->failed_pc=0x0c0aa058u; return 0; }
r[2]=0x0000000au;
goto P_0c0aa05a;
P_0c0aa05a: /* original 3527, guest PC 0x0c0aa05a */
if(!s->budget--) { s->failed_pc=0x0c0aa05au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[2])!=0);
goto P_0c0aa05c;
P_0c0aa05c: /* original 8902, guest PC 0x0c0aa05c */
if(!s->budget--) { s->failed_pc=0x0c0aa05cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa064; }
goto P_0c0aa05e;
P_0c0aa05e: /* original e310, guest PC 0x0c0aa05e */
if(!s->budget--) { s->failed_pc=0x0c0aa05eu; return 0; }
r[3]=0x00000010u;
goto P_0c0aa060;
P_0c0aa060: /* original 3537, guest PC 0x0c0aa060 */
if(!s->budget--) { s->failed_pc=0x0c0aa060u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[5]>(int32_t)r[3])!=0);
goto P_0c0aa062;
P_0c0aa062: /* original 8b02, guest PC 0x0c0aa062 */
if(!s->budget--) { s->failed_pc=0x0c0aa062u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa06a; }
goto P_0c0aa064;
P_0c0aa064: /* original 7f04, guest PC 0x0c0aa064 */
if(!s->budget--) { s->failed_pc=0x0c0aa064u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa066;
P_0c0aa066: /* original afa0, guest PC 0x0c0aa066 */
if(!s->budget--) { s->failed_pc=0x0c0aa066u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9faa;
P_0c0aa068: /* original 6ef6, guest PC 0x0c0aa068 */
if(!s->budget--) { s->failed_pc=0x0c0aa068u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa06a;
P_0c0aa06a: /* original 902d, guest PC 0x0c0aa06a */
if(!s->budget--) { s->failed_pc=0x0c0aa06au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa0c8u,2);
goto P_0c0aa06c;
P_0c0aa06c: /* original e522, guest PC 0x0c0aa06c */
if(!s->budget--) { s->failed_pc=0x0c0aa06cu; return 0; }
r[5]=0x00000022u;
goto P_0c0aa06e;
P_0c0aa06e: /* original 0455, guest PC 0x0c0aa06e */
if(!s->budget--) { s->failed_pc=0x0c0aa06eu; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0aa070;
P_0c0aa070: /* original 7002, guest PC 0x0c0aa070 */
if(!s->budget--) { s->failed_pc=0x0c0aa070u; return 0; }
r[0]+=0x00000002u;
goto P_0c0aa072;
P_0c0aa072: /* original 0455, guest PC 0x0c0aa072 */
if(!s->budget--) { s->failed_pc=0x0c0aa072u; return 0; }
write(ram,r[4]+r[0],r[5],2);
goto P_0c0aa074;
P_0c0aa074: /* original 65e3, guest PC 0x0c0aa074 */
if(!s->budget--) { s->failed_pc=0x0c0aa074u; return 0; }
r[5]=r[14];
goto P_0c0aa076;
P_0c0aa076: /* original 66f2, guest PC 0x0c0aa076 */
if(!s->budget--) { s->failed_pc=0x0c0aa076u; return 0; }
tmp=read(ram,r[15],4);
r[6]=tmp;
goto P_0c0aa078;
P_0c0aa078: /* original 7f04, guest PC 0x0c0aa078 */
if(!s->budget--) { s->failed_pc=0x0c0aa078u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa07a;
P_0c0aa07a: /* original 5662, guest PC 0x0c0aa07a */
if(!s->budget--) { s->failed_pc=0x0c0aa07au; return 0; }
r[6]=read(ram,r[6]+8,4);
goto P_0c0aa07c;
P_0c0aa07c: /* original a031, guest PC 0x0c0aa07c */
if(!s->budget--) { s->failed_pc=0x0c0aa07cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa07e: /* original 6ef6, guest PC 0x0c0aa07e */
if(!s->budget--) { s->failed_pc=0x0c0aa07eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa080;
P_0c0aa080: /* original 2fe6, guest PC 0x0c0aa080 */
if(!s->budget--) { s->failed_pc=0x0c0aa080u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa082;
P_0c0aa082: /* original 6e63, guest PC 0x0c0aa082 */
if(!s->budget--) { s->failed_pc=0x0c0aa082u; return 0; }
r[14]=r[6];
goto P_0c0aa084;
P_0c0aa084: /* original 53e1, guest PC 0x0c0aa084 */
if(!s->budget--) { s->failed_pc=0x0c0aa084u; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0aa086;
P_0c0aa086: /* original 7ffc, guest PC 0x0c0aa086 */
if(!s->budget--) { s->failed_pc=0x0c0aa086u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa088;
P_0c0aa088: /* original 62e2, guest PC 0x0c0aa088 */
if(!s->budget--) { s->failed_pc=0x0c0aa088u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aa08a;
P_0c0aa08a: /* original e058, guest PC 0x0c0aa08a */
if(!s->budget--) { s->failed_pc=0x0c0aa08au; return 0; }
r[0]=0x00000058u;
goto P_0c0aa08c;
P_0c0aa08c: /* original 3230, guest PC 0x0c0aa08c */
if(!s->budget--) { s->failed_pc=0x0c0aa08cu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0aa08e;
P_0c0aa08e: /* original 8f03, guest PC 0x0c0aa08e */
if(!s->budget--) { s->failed_pc=0x0c0aa08eu; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(!cond) { goto P_0c0aa098; }
goto P_0c0aa092;
P_0c0aa090: /* original 054e, guest PC 0x0c0aa090 */
if(!s->budget--) { s->failed_pc=0x0c0aa090u; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aa092;
P_0c0aa092: /* original 7f04, guest PC 0x0c0aa092 */
if(!s->budget--) { s->failed_pc=0x0c0aa092u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa094;
P_0c0aa094: /* original af89, guest PC 0x0c0aa094 */
if(!s->budget--) { s->failed_pc=0x0c0aa094u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9faa;
P_0c0aa096: /* original 6ef6, guest PC 0x0c0aa096 */
if(!s->budget--) { s->failed_pc=0x0c0aa096u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa098;
P_0c0aa098: /* original 752e, guest PC 0x0c0aa098 */
if(!s->budget--) { s->failed_pc=0x0c0aa098u; return 0; }
r[5]+=0x0000002eu;
goto P_0c0aa09a;
P_0c0aa09a: /* original 6251, guest PC 0x0c0aa09a */
if(!s->budget--) { s->failed_pc=0x0c0aa09au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0aa09c;
P_0c0aa09c: /* original 622d, guest PC 0x0c0aa09c */
if(!s->budget--) { s->failed_pc=0x0c0aa09cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aa09e;
P_0c0aa09e: /* original 2f22, guest PC 0x0c0aa09e */
if(!s->budget--) { s->failed_pc=0x0c0aa09eu; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aa0a0;
P_0c0aa0a0: /* original 7f04, guest PC 0x0c0aa0a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a0u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0a2;
P_0c0aa0a2: /* original 56e2, guest PC 0x0c0aa0a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a2u; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c0aa0a4;
P_0c0aa0a4: /* original 6523, guest PC 0x0c0aa0a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a4u; return 0; }
r[5]=r[2];
goto P_0c0aa0a6;
P_0c0aa0a6: /* original a01c, guest PC 0x0c0aa0a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa0a8: /* original 6ef6, guest PC 0x0c0aa0a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0aa;
P_0c0aa0aa: /* original 2fe6, guest PC 0x0c0aa0aa */
if(!s->budget--) { s->failed_pc=0x0c0aa0aau; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa0ac;
P_0c0aa0ac: /* original 6e63, guest PC 0x0c0aa0ac */
if(!s->budget--) { s->failed_pc=0x0c0aa0acu; return 0; }
r[14]=r[6];
goto P_0c0aa0ae;
P_0c0aa0ae: /* original 53e1, guest PC 0x0c0aa0ae */
if(!s->budget--) { s->failed_pc=0x0c0aa0aeu; return 0; }
r[3]=read(ram,r[14]+4,4);
goto P_0c0aa0b0;
P_0c0aa0b0: /* original 7ffc, guest PC 0x0c0aa0b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa0b2;
P_0c0aa0b2: /* original 62e2, guest PC 0x0c0aa0b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b2u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aa0b4;
P_0c0aa0b4: /* original e058, guest PC 0x0c0aa0b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b4u; return 0; }
r[0]=0x00000058u;
goto P_0c0aa0b6;
P_0c0aa0b6: /* original 3230, guest PC 0x0c0aa0b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0aa0b8;
P_0c0aa0b8: /* original 8f0a, guest PC 0x0c0aa0b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0b8u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[4]+r[0],4);
if(!cond) { goto P_0c0aa0d0; }
goto P_0c0aa0bc;
P_0c0aa0ba: /* original 054e, guest PC 0x0c0aa0ba */
if(!s->budget--) { s->failed_pc=0x0c0aa0bau; return 0; }
r[5]=read(ram,r[4]+r[0],4);
goto P_0c0aa0bc;
P_0c0aa0bc: /* original 7f04, guest PC 0x0c0aa0bc */
if(!s->budget--) { s->failed_pc=0x0c0aa0bcu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0be;
P_0c0aa0be: /* original af74, guest PC 0x0c0aa0be */
if(!s->budget--) { s->failed_pc=0x0c0aa0beu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9faa;
P_0c0aa0c0: /* original 6ef6, guest PC 0x0c0aa0c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0c0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa0c2u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa0c2u; return 0; } return 1;
P_0c0aa0d0: /* original 752c, guest PC 0x0c0aa0d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d0u; return 0; }
r[5]+=0x0000002cu;
goto P_0c0aa0d2;
P_0c0aa0d2: /* original 6251, guest PC 0x0c0aa0d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d2u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[5],2);
r[2]=tmp;
goto P_0c0aa0d4;
P_0c0aa0d4: /* original 622d, guest PC 0x0c0aa0d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d4u; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aa0d6;
P_0c0aa0d6: /* original 2f22, guest PC 0x0c0aa0d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0aa0d8;
P_0c0aa0d8: /* original 7f04, guest PC 0x0c0aa0d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0d8u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0da;
P_0c0aa0da: /* original 56e2, guest PC 0x0c0aa0da */
if(!s->budget--) { s->failed_pc=0x0c0aa0dau; return 0; }
r[6]=read(ram,r[14]+8,4);
goto P_0c0aa0dc;
P_0c0aa0dc: /* original 6523, guest PC 0x0c0aa0dc */
if(!s->budget--) { s->failed_pc=0x0c0aa0dcu; return 0; }
r[5]=r[2];
goto P_0c0aa0de;
P_0c0aa0de: /* original a000, guest PC 0x0c0aa0de */
if(!s->budget--) { s->failed_pc=0x0c0aa0deu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa0e0: /* original 6ef6, guest PC 0x0c0aa0e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aa0e2;
P_0c0aa0e2: /* original 2fe6, guest PC 0x0c0aa0e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa0e4;
P_0c0aa0e4: /* original 6e43, guest PC 0x0c0aa0e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e4u; return 0; }
r[14]=r[4];
goto P_0c0aa0e6;
P_0c0aa0e6: /* original 4f22, guest PC 0x0c0aa0e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa0e8;
P_0c0aa0e8: /* original 7ffc, guest PC 0x0c0aa0e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0e8u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa0ea;
P_0c0aa0ea: /* original 2f62, guest PC 0x0c0aa0ea */
if(!s->budget--) { s->failed_pc=0x0c0aa0eau; return 0; }
write(ram,r[15],r[6],4);
goto P_0c0aa0ec;
P_0c0aa0ec: /* original d333, guest PC 0x0c0aa0ec */
if(!s->budget--) { s->failed_pc=0x0c0aa0ecu; return 0; }
r[3]=read(ram,0x0c0aa1bcu,4);
goto P_0c0aa0ee;
P_0c0aa0ee: /* original 430b, guest PC 0x0c0aa0ee */
if(!s->budget--) { s->failed_pc=0x0c0aa0eeu; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa0f2u;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa0f2u) { target=s->pc; goto dispatch; }
goto P_0c0aa0f2;
P_0c0aa0f0: /* original 64e3, guest PC 0x0c0aa0f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f0u; return 0; }
r[4]=r[14];
goto P_0c0aa0f2;
P_0c0aa0f2: /* original 62f2, guest PC 0x0c0aa0f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f2u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0aa0f4;
P_0c0aa0f4: /* original 7f04, guest PC 0x0c0aa0f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa0f6;
P_0c0aa0f6: /* original 4f26, guest PC 0x0c0aa0f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa0f8;
P_0c0aa0f8: /* original 1e2e, guest PC 0x0c0aa0f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa0f8u; return 0; }
write(ram,r[14]+56,r[2],4);
goto P_0c0aa0fa;
P_0c0aa0fa: /* original 64e3, guest PC 0x0c0aa0fa */
if(!s->budget--) { s->failed_pc=0x0c0aa0fau; return 0; }
r[4]=r[14];
goto P_0c0aa0fc;
P_0c0aa0fc: /* original af55, guest PC 0x0c0aa0fc */
if(!s->budget--) { s->failed_pc=0x0c0aa0fcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9faa;
P_0c0aa0fe: /* original 6ef6, guest PC 0x0c0aa0fe */
if(!s->budget--) { s->failed_pc=0x0c0aa0feu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa100u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa100u; return 0; } return 1;
P_0c0aa1ec: /* original 2fe6, guest PC 0x0c0aa1ec */
if(!s->budget--) { s->failed_pc=0x0c0aa1ecu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1ee;
P_0c0aa1ee: /* original 6e43, guest PC 0x0c0aa1ee */
if(!s->budget--) { s->failed_pc=0x0c0aa1eeu; return 0; }
r[14]=r[4];
goto P_0c0aa1f0;
P_0c0aa1f0: /* original 2fd6, guest PC 0x0c0aa1f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f0u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1f2;
P_0c0aa1f2: /* original e058, guest PC 0x0c0aa1f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f2u; return 0; }
r[0]=0x00000058u;
goto P_0c0aa1f4;
P_0c0aa1f4: /* original 2fc6, guest PC 0x0c0aa1f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1f6;
P_0c0aa1f6: /* original 6d63, guest PC 0x0c0aa1f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f6u; return 0; }
r[13]=r[6];
goto P_0c0aa1f8;
P_0c0aa1f8: /* original 2fb6, guest PC 0x0c0aa1f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa1f8u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1fa;
P_0c0aa1fa: /* original 66e3, guest PC 0x0c0aa1fa */
if(!s->budget--) { s->failed_pc=0x0c0aa1fau; return 0; }
r[6]=r[14];
goto P_0c0aa1fc;
P_0c0aa1fc: /* original 2fa6, guest PC 0x0c0aa1fc */
if(!s->budget--) { s->failed_pc=0x0c0aa1fcu; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa1fe;
P_0c0aa1fe: /* original 7638, guest PC 0x0c0aa1fe */
if(!s->budget--) { s->failed_pc=0x0c0aa1feu; return 0; }
r[6]+=0x00000038u;
goto P_0c0aa200;
P_0c0aa200: /* original 2f96, guest PC 0x0c0aa200 */
if(!s->budget--) { s->failed_pc=0x0c0aa200u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa202;
P_0c0aa202: /* original e400, guest PC 0x0c0aa202 */
if(!s->budget--) { s->failed_pc=0x0c0aa202u; return 0; }
r[4]=0x00000000u;
goto P_0c0aa204;
P_0c0aa204: /* original 2f86, guest PC 0x0c0aa204 */
if(!s->budget--) { s->failed_pc=0x0c0aa204u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c0aa206;
P_0c0aa206: /* original 6b43, guest PC 0x0c0aa206 */
if(!s->budget--) { s->failed_pc=0x0c0aa206u; return 0; }
r[11]=r[4];
goto P_0c0aa208;
P_0c0aa208: /* original 4f22, guest PC 0x0c0aa208 */
if(!s->budget--) { s->failed_pc=0x0c0aa208u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa20a;
P_0c0aa20a: /* original 7ffc, guest PC 0x0c0aa20a */
if(!s->budget--) { s->failed_pc=0x0c0aa20au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aa20c;
P_0c0aa20c: /* original 2f52, guest PC 0x0c0aa20c */
if(!s->budget--) { s->failed_pc=0x0c0aa20cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aa20e;
P_0c0aa20e: /* original 09ee, guest PC 0x0c0aa20e */
if(!s->budget--) { s->failed_pc=0x0c0aa20eu; return 0; }
r[9]=read(ram,r[14]+r[0],4);
goto P_0c0aa210;
P_0c0aa210: /* original e048, guest PC 0x0c0aa210 */
if(!s->budget--) { s->failed_pc=0x0c0aa210u; return 0; }
r[0]=0x00000048u;
goto P_0c0aa212;
P_0c0aa212: /* original 07ee, guest PC 0x0c0aa212 */
if(!s->budget--) { s->failed_pc=0x0c0aa212u; return 0; }
r[7]=read(ram,r[14]+r[0],4);
goto P_0c0aa214;
P_0c0aa214: /* original 8463, guest PC 0x0c0aa214 */
if(!s->budget--) { s->failed_pc=0x0c0aa214u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0aa216;
P_0c0aa216: /* original 65d2, guest PC 0x0c0aa216 */
if(!s->budget--) { s->failed_pc=0x0c0aa216u; return 0; }
tmp=read(ram,r[13],4);
r[5]=tmp;
goto P_0c0aa218;
P_0c0aa218: /* original da24, guest PC 0x0c0aa218 */
if(!s->budget--) { s->failed_pc=0x0c0aa218u; return 0; }
r[10]=read(ram,0x0c0aa2acu,4);
goto P_0c0aa21a;
P_0c0aa21a: /* original 660c, guest PC 0x0c0aa21a */
if(!s->budget--) { s->failed_pc=0x0c0aa21au; return 0; }
r[6]=r[0]&255u;
goto P_0c0aa21c;
P_0c0aa21c: /* original 3560, guest PC 0x0c0aa21c */
if(!s->budget--) { s->failed_pc=0x0c0aa21cu; return 0; }
r[17]=(r[17]&~1u)|((r[5]==r[6])!=0);
goto P_0c0aa21e;
P_0c0aa21e: /* original 8f20, guest PC 0x0c0aa21e */
if(!s->budget--) { s->failed_pc=0x0c0aa21eu; return 0; }
cond=r[17]&1u;
r[8]=0x00000001u;
if(!cond) { goto P_0c0aa262; }
goto P_0c0aa222;
P_0c0aa220: /* original e801, guest PC 0x0c0aa220 */
if(!s->budget--) { s->failed_pc=0x0c0aa220u; return 0; }
r[8]=0x00000001u;
goto P_0c0aa222;
P_0c0aa222: /* original d222, guest PC 0x0c0aa222 */
if(!s->budget--) { s->failed_pc=0x0c0aa222u; return 0; }
r[2]=read(ram,0x0c0aa2acu,4);
goto P_0c0aa224;
P_0c0aa224: /* original 2728, guest PC 0x0c0aa224 */
if(!s->budget--) { s->failed_pc=0x0c0aa224u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[2])==0)!=0);
goto P_0c0aa226;
P_0c0aa226: /* original 891c, guest PC 0x0c0aa226 */
if(!s->budget--) { s->failed_pc=0x0c0aa226u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa262; }
goto P_0c0aa228;
P_0c0aa228: /* original e062, guest PC 0x0c0aa228 */
if(!s->budget--) { s->failed_pc=0x0c0aa228u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa22a;
P_0c0aa22a: /* original 01ec, guest PC 0x0c0aa22a */
if(!s->budget--) { s->failed_pc=0x0c0aa22au; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aa22c;
P_0c0aa22c: /* original 611c, guest PC 0x0c0aa22c */
if(!s->budget--) { s->failed_pc=0x0c0aa22cu; return 0; }
r[1]=r[1]&255u;
goto P_0c0aa22e;
P_0c0aa22e: /* original 4115, guest PC 0x0c0aa22e */
if(!s->budget--) { s->failed_pc=0x0c0aa22eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c0aa230;
P_0c0aa230: /* original 8907, guest PC 0x0c0aa230 */
if(!s->budget--) { s->failed_pc=0x0c0aa230u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa242; }
goto P_0c0aa232;
P_0c0aa232: /* original d21f, guest PC 0x0c0aa232 */
if(!s->budget--) { s->failed_pc=0x0c0aa232u; return 0; }
r[2]=read(ram,0x0c0aa2b0u,4);
goto P_0c0aa234;
P_0c0aa234: /* original 6b83, guest PC 0x0c0aa234 */
if(!s->budget--) { s->failed_pc=0x0c0aa234u; return 0; }
r[11]=r[8];
goto P_0c0aa236;
P_0c0aa236: /* original 54ee, guest PC 0x0c0aa236 */
if(!s->budget--) { s->failed_pc=0x0c0aa236u; return 0; }
r[4]=read(ram,r[14]+56,4);
goto P_0c0aa238;
P_0c0aa238: /* original 53d2, guest PC 0x0c0aa238 */
if(!s->budget--) { s->failed_pc=0x0c0aa238u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa23a;
P_0c0aa23a: /* original 2429, guest PC 0x0c0aa23a */
if(!s->budget--) { s->failed_pc=0x0c0aa23au; return 0; }
r[4]&=r[2];
goto P_0c0aa23c;
P_0c0aa23c: /* original 234b, guest PC 0x0c0aa23c */
if(!s->budget--) { s->failed_pc=0x0c0aa23cu; return 0; }
r[3]|=r[4];
goto P_0c0aa23e;
P_0c0aa23e: /* original a024, guest PC 0x0c0aa23e */
if(!s->budget--) { s->failed_pc=0x0c0aa23eu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0aa28a;
P_0c0aa240: /* original 1d32, guest PC 0x0c0aa240 */
if(!s->budget--) { s->failed_pc=0x0c0aa240u; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0aa242;
P_0c0aa242: /* original 55d2, guest PC 0x0c0aa242 */
if(!s->budget--) { s->failed_pc=0x0c0aa242u; return 0; }
r[5]=read(ram,r[13]+8,4);
goto P_0c0aa244;
P_0c0aa244: /* original 655d, guest PC 0x0c0aa244 */
if(!s->budget--) { s->failed_pc=0x0c0aa244u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0aa246;
P_0c0aa246: /* original 2558, guest PC 0x0c0aa246 */
if(!s->budget--) { s->failed_pc=0x0c0aa246u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0aa248;
P_0c0aa248: /* original 8b01, guest PC 0x0c0aa248 */
if(!s->budget--) { s->failed_pc=0x0c0aa248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa24e; }
goto P_0c0aa24a;
P_0c0aa24a: /* original a0cb, guest PC 0x0c0aa24a */
if(!s->budget--) { s->failed_pc=0x0c0aa24au; return 0; }
goto P_0c0aa3e4;
P_0c0aa24c: /* original 0009, guest PC 0x0c0aa24c */
if(!s->budget--) { s->failed_pc=0x0c0aa24cu; return 0; }
goto P_0c0aa24e;
P_0c0aa24e: /* original 53d2, guest PC 0x0c0aa24e */
if(!s->budget--) { s->failed_pc=0x0c0aa24eu; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa250;
P_0c0aa250: /* original 2a38, guest PC 0x0c0aa250 */
if(!s->budget--) { s->failed_pc=0x0c0aa250u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0aa252;
P_0c0aa252: /* original 8901, guest PC 0x0c0aa252 */
if(!s->budget--) { s->failed_pc=0x0c0aa252u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa258; }
goto P_0c0aa254;
P_0c0aa254: /* original a0b3, guest PC 0x0c0aa254 */
if(!s->budget--) { s->failed_pc=0x0c0aa254u; return 0; }
goto P_0c0aa3be;
P_0c0aa256: /* original 0009, guest PC 0x0c0aa256 */
if(!s->budget--) { s->failed_pc=0x0c0aa256u; return 0; }
goto P_0c0aa258;
P_0c0aa258: /* original d316, guest PC 0x0c0aa258 */
if(!s->budget--) { s->failed_pc=0x0c0aa258u; return 0; }
r[3]=read(ram,0x0c0aa2b4u,4);
goto P_0c0aa25a;
P_0c0aa25a: /* original 430b, guest PC 0x0c0aa25a */
if(!s->budget--) { s->failed_pc=0x0c0aa25au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa25eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa25eu) { target=s->pc; goto dispatch; }
goto P_0c0aa25e;
P_0c0aa25c: /* original 64e3, guest PC 0x0c0aa25c */
if(!s->budget--) { s->failed_pc=0x0c0aa25cu; return 0; }
r[4]=r[14];
goto P_0c0aa25e;
P_0c0aa25e: /* original a0bf, guest PC 0x0c0aa25e */
if(!s->budget--) { s->failed_pc=0x0c0aa25eu; return 0; }
goto P_0c0aa3e0;
P_0c0aa260: /* original 0009, guest PC 0x0c0aa260 */
if(!s->budget--) { s->failed_pc=0x0c0aa260u; return 0; }
goto P_0c0aa262;
P_0c0aa262: /* original e03c, guest PC 0x0c0aa262 */
if(!s->budget--) { s->failed_pc=0x0c0aa262u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa264;
P_0c0aa264: /* original 0e45, guest PC 0x0c0aa264 */
if(!s->budget--) { s->failed_pc=0x0c0aa264u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0aa266;
P_0c0aa266: /* original e062, guest PC 0x0c0aa266 */
if(!s->budget--) { s->failed_pc=0x0c0aa266u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa268;
P_0c0aa268: /* original 0e44, guest PC 0x0c0aa268 */
if(!s->budget--) { s->failed_pc=0x0c0aa268u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0aa26a;
P_0c0aa26a: /* original d313, guest PC 0x0c0aa26a */
if(!s->budget--) { s->failed_pc=0x0c0aa26au; return 0; }
r[3]=read(ram,0x0c0aa2b8u,4);
goto P_0c0aa26c;
P_0c0aa26c: /* original 52d2, guest PC 0x0c0aa26c */
if(!s->budget--) { s->failed_pc=0x0c0aa26cu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa26e;
P_0c0aa26e: /* original 2238, guest PC 0x0c0aa26e */
if(!s->budget--) { s->failed_pc=0x0c0aa26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa270;
P_0c0aa270: /* original 8901, guest PC 0x0c0aa270 */
if(!s->budget--) { s->failed_pc=0x0c0aa270u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa276; }
goto P_0c0aa272;
P_0c0aa272: /* original a008, guest PC 0x0c0aa272 */
if(!s->budget--) { s->failed_pc=0x0c0aa272u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0aa286;
P_0c0aa274: /* original f49d, guest PC 0x0c0aa274 */
if(!s->budget--) { s->failed_pc=0x0c0aa274u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0aa276;
P_0c0aa276: /* original 51d2, guest PC 0x0c0aa276 */
if(!s->budget--) { s->failed_pc=0x0c0aa276u; return 0; }
r[1]=read(ram,r[13]+8,4);
goto P_0c0aa278;
P_0c0aa278: /* original d210, guest PC 0x0c0aa278 */
if(!s->budget--) { s->failed_pc=0x0c0aa278u; return 0; }
r[2]=read(ram,0x0c0aa2bcu,4);
goto P_0c0aa27a;
P_0c0aa27a: /* original 2128, guest PC 0x0c0aa27a */
if(!s->budget--) { s->failed_pc=0x0c0aa27au; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aa27c;
P_0c0aa27c: /* original 8902, guest PC 0x0c0aa27c */
if(!s->budget--) { s->failed_pc=0x0c0aa27cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa284; }
goto P_0c0aa27e;
P_0c0aa27e: /* original c710, guest PC 0x0c0aa27e */
if(!s->budget--) { s->failed_pc=0x0c0aa27eu; return 0; }
r[0]=code_base|0x000aa2c0u;
goto P_0c0aa280;
P_0c0aa280: /* original a001, guest PC 0x0c0aa280 */
if(!s->budget--) { s->failed_pc=0x0c0aa280u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0aa286;
P_0c0aa282: /* original f408, guest PC 0x0c0aa282 */
if(!s->budget--) { s->failed_pc=0x0c0aa282u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0aa284;
P_0c0aa284: /* original f48d, guest PC 0x0c0aa284 */
if(!s->budget--) { s->failed_pc=0x0c0aa284u; return 0; }
fr[4]=0;
goto P_0c0aa286;
P_0c0aa286: /* original 900f, guest PC 0x0c0aa286 */
if(!s->budget--) { s->failed_pc=0x0c0aa286u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa2a8u,2);
goto P_0c0aa288;
P_0c0aa288: /* original fe47, guest PC 0x0c0aa288 */
if(!s->budget--) { s->failed_pc=0x0c0aa288u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0aa28a;
P_0c0aa28a: /* original 52d2, guest PC 0x0c0aa28a */
if(!s->budget--) { s->failed_pc=0x0c0aa28au; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa28c;
P_0c0aa28c: /* original e054, guest PC 0x0c0aa28c */
if(!s->budget--) { s->failed_pc=0x0c0aa28cu; return 0; }
r[0]=0x00000054u;
goto P_0c0aa28e;
P_0c0aa28e: /* original d30d, guest PC 0x0c0aa28e */
if(!s->budget--) { s->failed_pc=0x0c0aa28eu; return 0; }
r[3]=read(ram,0x0c0aa2c4u,4);
goto P_0c0aa290;
P_0c0aa290: /* original 2238, guest PC 0x0c0aa290 */
if(!s->budget--) { s->failed_pc=0x0c0aa290u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa292;
P_0c0aa292: /* original 8d19, guest PC 0x0c0aa292 */
if(!s->budget--) { s->failed_pc=0x0c0aa292u; return 0; }
cond=r[17]&1u;
r[5]=read(ram,r[14]+r[0],4);
if(cond) { goto P_0c0aa2c8; }
goto P_0c0aa296;
P_0c0aa294: /* original 05ee, guest PC 0x0c0aa294 */
if(!s->budget--) { s->failed_pc=0x0c0aa294u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aa296;
P_0c0aa296: /* original e021, guest PC 0x0c0aa296 */
if(!s->budget--) { s->failed_pc=0x0c0aa296u; return 0; }
r[0]=0x00000021u;
goto P_0c0aa298;
P_0c0aa298: /* original 045c, guest PC 0x0c0aa298 */
if(!s->budget--) { s->failed_pc=0x0c0aa298u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0aa29a;
P_0c0aa29a: /* original 6243, guest PC 0x0c0aa29a */
if(!s->budget--) { s->failed_pc=0x0c0aa29au; return 0; }
r[2]=r[4];
goto P_0c0aa29c;
P_0c0aa29c: /* original 4400, guest PC 0x0c0aa29c */
if(!s->budget--) { s->failed_pc=0x0c0aa29cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c0aa29e;
P_0c0aa29e: /* original 342c, guest PC 0x0c0aa29e */
if(!s->budget--) { s->failed_pc=0x0c0aa29eu; return 0; }
r[4]+=r[2];
goto P_0c0aa2a0;
P_0c0aa2a0: /* original a014, guest PC 0x0c0aa2a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2a0u; return 0; }
r[4]>>=2;
goto P_0c0aa2cc;
P_0c0aa2a2: /* original 4409, guest PC 0x0c0aa2a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2a2u; return 0; }
r[4]>>=2;
if(!vf3_matrix_family(0x0c0aa2a4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa2a4u; return 0; } return 1;
P_0c0aa2c8: /* original e020, guest PC 0x0c0aa2c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2c8u; return 0; }
r[0]=0x00000020u;
goto P_0c0aa2ca;
P_0c0aa2ca: /* original 045c, guest PC 0x0c0aa2ca */
if(!s->budget--) { s->failed_pc=0x0c0aa2cau; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0aa2cc;
P_0c0aa2cc: /* original 904b, guest PC 0x0c0aa2cc */
if(!s->budget--) { s->failed_pc=0x0c0aa2ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa366u,2);
goto P_0c0aa2ce;
P_0c0aa2ce: /* original 0e44, guest PC 0x0c0aa2ce */
if(!s->budget--) { s->failed_pc=0x0c0aa2ceu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0aa2d0;
P_0c0aa2d0: /* original 5cd2, guest PC 0x0c0aa2d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d0u; return 0; }
r[12]=read(ram,r[13]+8,4);
goto P_0c0aa2d2;
P_0c0aa2d2: /* original 6ccd, guest PC 0x0c0aa2d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d2u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa2d4;
P_0c0aa2d4: /* original 2cc8, guest PC 0x0c0aa2d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d4u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c0aa2d6;
P_0c0aa2d6: /* original 8912, guest PC 0x0c0aa2d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa2fe; }
goto P_0c0aa2d8;
P_0c0aa2d8: /* original d224, guest PC 0x0c0aa2d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2d8u; return 0; }
r[2]=read(ram,0x0c0aa36cu,4);
goto P_0c0aa2da;
P_0c0aa2da: /* original e503, guest PC 0x0c0aa2da */
if(!s->budget--) { s->failed_pc=0x0c0aa2dau; return 0; }
r[5]=0x00000003u;
goto P_0c0aa2dc;
P_0c0aa2dc: /* original 420b, guest PC 0x0c0aa2dc */
if(!s->budget--) { s->failed_pc=0x0c0aa2dcu; return 0; }
target=r[2];
r[16]=code_base|0x0c0aa2e0u;
r[4]=read(ram,r[13]+8,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa2e0u) { target=s->pc; goto dispatch; }
goto P_0c0aa2e0;
P_0c0aa2de: /* original 54d2, guest PC 0x0c0aa2de */
if(!s->budget--) { s->failed_pc=0x0c0aa2deu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0aa2e0;
P_0c0aa2e0: /* original 6403, guest PC 0x0c0aa2e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e0u; return 0; }
r[4]=r[0];
goto P_0c0aa2e2;
P_0c0aa2e2: /* original 8442, guest PC 0x0c0aa2e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0aa2e4;
P_0c0aa2e4: /* original d322, guest PC 0x0c0aa2e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e4u; return 0; }
r[3]=read(ram,0x0c0aa370u,4);
goto P_0c0aa2e6;
P_0c0aa2e6: /* original 600c, guest PC 0x0c0aa2e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e6u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa2e8;
P_0c0aa2e8: /* original 4018, guest PC 0x0c0aa2e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2e8u; return 0; }
r[0]<<=8;
goto P_0c0aa2ea;
P_0c0aa2ea: /* original 2039, guest PC 0x0c0aa2ea */
if(!s->budget--) { s->failed_pc=0x0c0aa2eau; return 0; }
r[0]&=r[3];
goto P_0c0aa2ec;
P_0c0aa2ec: /* original 6203, guest PC 0x0c0aa2ec */
if(!s->budget--) { s->failed_pc=0x0c0aa2ecu; return 0; }
r[2]=r[0];
goto P_0c0aa2ee;
P_0c0aa2ee: /* original 8441, guest PC 0x0c0aa2ee */
if(!s->budget--) { s->failed_pc=0x0c0aa2eeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0aa2f0;
P_0c0aa2f0: /* original 6423, guest PC 0x0c0aa2f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f0u; return 0; }
r[4]=r[2];
goto P_0c0aa2f2;
P_0c0aa2f2: /* original 600c, guest PC 0x0c0aa2f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa2f4;
P_0c0aa2f4: /* original 240b, guest PC 0x0c0aa2f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f4u; return 0; }
r[4]|=r[0];
goto P_0c0aa2f6;
P_0c0aa2f6: /* original 2448, guest PC 0x0c0aa2f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0aa2f8;
P_0c0aa2f8: /* original 8b15, guest PC 0x0c0aa2f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa2f8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa326; }
goto P_0c0aa2fa;
P_0c0aa2fa: /* original e302, guest PC 0x0c0aa2fa */
if(!s->budget--) { s->failed_pc=0x0c0aa2fau; return 0; }
r[3]=0x00000002u;
goto P_0c0aa2fc;
P_0c0aa2fc: /* original 2b3b, guest PC 0x0c0aa2fc */
if(!s->budget--) { s->failed_pc=0x0c0aa2fcu; return 0; }
r[11]|=r[3];
goto P_0c0aa2fe;
P_0c0aa2fe: /* original 52d2, guest PC 0x0c0aa2fe */
if(!s->budget--) { s->failed_pc=0x0c0aa2feu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa300;
P_0c0aa300: /* original d31c, guest PC 0x0c0aa300 */
if(!s->budget--) { s->failed_pc=0x0c0aa300u; return 0; }
r[3]=read(ram,0x0c0aa374u,4);
goto P_0c0aa302;
P_0c0aa302: /* original 2238, guest PC 0x0c0aa302 */
if(!s->budget--) { s->failed_pc=0x0c0aa302u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa304;
P_0c0aa304: /* original 8b04, guest PC 0x0c0aa304 */
if(!s->budget--) { s->failed_pc=0x0c0aa304u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa310; }
goto P_0c0aa306;
P_0c0aa306: /* original 6c93, guest PC 0x0c0aa306 */
if(!s->budget--) { s->failed_pc=0x0c0aa306u; return 0; }
r[12]=r[9];
goto P_0c0aa308;
P_0c0aa308: /* original 7c48, guest PC 0x0c0aa308 */
if(!s->budget--) { s->failed_pc=0x0c0aa308u; return 0; }
r[12]+=0x00000048u;
goto P_0c0aa30a;
P_0c0aa30a: /* original 6cc1, guest PC 0x0c0aa30a */
if(!s->budget--) { s->failed_pc=0x0c0aa30au; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]=tmp;
goto P_0c0aa30c;
P_0c0aa30c: /* original a00b, guest PC 0x0c0aa30c */
if(!s->budget--) { s->failed_pc=0x0c0aa30cu; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa326;
P_0c0aa30e: /* original 6ccd, guest PC 0x0c0aa30e */
if(!s->budget--) { s->failed_pc=0x0c0aa30eu; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa310;
P_0c0aa310: /* original 51d2, guest PC 0x0c0aa310 */
if(!s->budget--) { s->failed_pc=0x0c0aa310u; return 0; }
r[1]=read(ram,r[13]+8,4);
goto P_0c0aa312;
P_0c0aa312: /* original d219, guest PC 0x0c0aa312 */
if(!s->budget--) { s->failed_pc=0x0c0aa312u; return 0; }
r[2]=read(ram,0x0c0aa378u,4);
goto P_0c0aa314;
P_0c0aa314: /* original 2128, guest PC 0x0c0aa314 */
if(!s->budget--) { s->failed_pc=0x0c0aa314u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0aa316;
P_0c0aa316: /* original 8b02, guest PC 0x0c0aa316 */
if(!s->budget--) { s->failed_pc=0x0c0aa316u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa31e; }
goto P_0c0aa318;
P_0c0aa318: /* original 6c93, guest PC 0x0c0aa318 */
if(!s->budget--) { s->failed_pc=0x0c0aa318u; return 0; }
r[12]=r[9];
goto P_0c0aa31a;
P_0c0aa31a: /* original a002, guest PC 0x0c0aa31a */
if(!s->budget--) { s->failed_pc=0x0c0aa31au; return 0; }
r[12]+=0x0000004eu;
goto P_0c0aa322;
P_0c0aa31c: /* original 7c4e, guest PC 0x0c0aa31c */
if(!s->budget--) { s->failed_pc=0x0c0aa31cu; return 0; }
r[12]+=0x0000004eu;
goto P_0c0aa31e;
P_0c0aa31e: /* original 6c93, guest PC 0x0c0aa31e */
if(!s->budget--) { s->failed_pc=0x0c0aa31eu; return 0; }
r[12]=r[9];
goto P_0c0aa320;
P_0c0aa320: /* original 7c50, guest PC 0x0c0aa320 */
if(!s->budget--) { s->failed_pc=0x0c0aa320u; return 0; }
r[12]+=0x00000050u;
goto P_0c0aa322;
P_0c0aa322: /* original 6cc1, guest PC 0x0c0aa322 */
if(!s->budget--) { s->failed_pc=0x0c0aa322u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[12],2);
r[12]=tmp;
goto P_0c0aa324;
P_0c0aa324: /* original 6ccd, guest PC 0x0c0aa324 */
if(!s->budget--) { s->failed_pc=0x0c0aa324u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0aa326;
P_0c0aa326: /* original e03c, guest PC 0x0c0aa326 */
if(!s->budget--) { s->failed_pc=0x0c0aa326u; return 0; }
r[0]=0x0000003cu;
goto P_0c0aa328;
P_0c0aa328: /* original 03ed, guest PC 0x0c0aa328 */
if(!s->budget--) { s->failed_pc=0x0c0aa328u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa32a;
P_0c0aa32a: /* original 633d, guest PC 0x0c0aa32a */
if(!s->budget--) { s->failed_pc=0x0c0aa32au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0aa32c;
P_0c0aa32c: /* original 3c30, guest PC 0x0c0aa32c */
if(!s->budget--) { s->failed_pc=0x0c0aa32cu; return 0; }
r[17]=(r[17]&~1u)|((r[12]==r[3])!=0);
goto P_0c0aa32e;
P_0c0aa32e: /* original 8929, guest PC 0x0c0aa32e */
if(!s->budget--) { s->failed_pc=0x0c0aa32eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa384; }
goto P_0c0aa330;
P_0c0aa330: /* original e03e, guest PC 0x0c0aa330 */
if(!s->budget--) { s->failed_pc=0x0c0aa330u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa332;
P_0c0aa332: /* original d312, guest PC 0x0c0aa332 */
if(!s->budget--) { s->failed_pc=0x0c0aa332u; return 0; }
r[3]=read(ram,0x0c0aa37cu,4);
goto P_0c0aa334;
P_0c0aa334: /* original 09ed, guest PC 0x0c0aa334 */
if(!s->budget--) { s->failed_pc=0x0c0aa334u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa336;
P_0c0aa336: /* original 65c3, guest PC 0x0c0aa336 */
if(!s->budget--) { s->failed_pc=0x0c0aa336u; return 0; }
r[5]=r[12];
goto P_0c0aa338;
P_0c0aa338: /* original 699d, guest PC 0x0c0aa338 */
if(!s->budget--) { s->failed_pc=0x0c0aa338u; return 0; }
r[9]=r[9]&65535u;
goto P_0c0aa33a;
P_0c0aa33a: /* original 430b, guest PC 0x0c0aa33a */
if(!s->budget--) { s->failed_pc=0x0c0aa33au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa33eu;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa33eu) { target=s->pc; goto dispatch; }
goto P_0c0aa33e;
P_0c0aa33c: /* original 64e3, guest PC 0x0c0aa33c */
if(!s->budget--) { s->failed_pc=0x0c0aa33cu; return 0; }
r[4]=r[14];
goto P_0c0aa33e;
P_0c0aa33e: /* original e048, guest PC 0x0c0aa33e */
if(!s->budget--) { s->failed_pc=0x0c0aa33eu; return 0; }
r[0]=0x00000048u;
goto P_0c0aa340;
P_0c0aa340: /* original 04ee, guest PC 0x0c0aa340 */
if(!s->budget--) { s->failed_pc=0x0c0aa340u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0aa342;
P_0c0aa342: /* original 24a8, guest PC 0x0c0aa342 */
if(!s->budget--) { s->failed_pc=0x0c0aa342u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[10])==0)!=0);
goto P_0c0aa344;
P_0c0aa344: /* original 8b05, guest PC 0x0c0aa344 */
if(!s->budget--) { s->failed_pc=0x0c0aa344u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aa352; }
goto P_0c0aa346;
P_0c0aa346: /* original 52d2, guest PC 0x0c0aa346 */
if(!s->budget--) { s->failed_pc=0x0c0aa346u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa348;
P_0c0aa348: /* original e062, guest PC 0x0c0aa348 */
if(!s->budget--) { s->failed_pc=0x0c0aa348u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa34a;
P_0c0aa34a: /* original 622d, guest PC 0x0c0aa34a */
if(!s->budget--) { s->failed_pc=0x0c0aa34au; return 0; }
r[2]=r[2]&65535u;
goto P_0c0aa34c;
P_0c0aa34c: /* original 1d22, guest PC 0x0c0aa34c */
if(!s->budget--) { s->failed_pc=0x0c0aa34cu; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0aa34e;
P_0c0aa34e: /* original a047, guest PC 0x0c0aa34e */
if(!s->budget--) { s->failed_pc=0x0c0aa34eu; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0aa3e0;
P_0c0aa350: /* original 0e84, guest PC 0x0c0aa350 */
if(!s->budget--) { s->failed_pc=0x0c0aa350u; return 0; }
write(ram,r[14]+r[0],r[8],1);
goto P_0c0aa352;
P_0c0aa352: /* original 2b88, guest PC 0x0c0aa352 */
if(!s->budget--) { s->failed_pc=0x0c0aa352u; return 0; }
r[17]=(r[17]&~1u)|(((r[11]&r[8])==0)!=0);
goto P_0c0aa354;
P_0c0aa354: /* original 8916, guest PC 0x0c0aa354 */
if(!s->budget--) { s->failed_pc=0x0c0aa354u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa384; }
goto P_0c0aa356;
P_0c0aa356: /* original 9007, guest PC 0x0c0aa356 */
if(!s->budget--) { s->failed_pc=0x0c0aa356u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa368u,2);
goto P_0c0aa358;
P_0c0aa358: /* original 04ed, guest PC 0x0c0aa358 */
if(!s->budget--) { s->failed_pc=0x0c0aa358u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0aa35a;
P_0c0aa35a: /* original 644d, guest PC 0x0c0aa35a */
if(!s->budget--) { s->failed_pc=0x0c0aa35au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aa35c;
P_0c0aa35c: /* original 3492, guest PC 0x0c0aa35c */
if(!s->budget--) { s->failed_pc=0x0c0aa35cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[9])!=0);
goto P_0c0aa35e;
P_0c0aa35e: /* original 890f, guest PC 0x0c0aa35e */
if(!s->budget--) { s->failed_pc=0x0c0aa35eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa380; }
goto P_0c0aa360;
P_0c0aa360: /* original e03e, guest PC 0x0c0aa360 */
if(!s->budget--) { s->failed_pc=0x0c0aa360u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa362;
P_0c0aa362: /* original a00f, guest PC 0x0c0aa362 */
if(!s->budget--) { s->failed_pc=0x0c0aa362u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0aa384;
P_0c0aa364: /* original 0e45, guest PC 0x0c0aa364 */
if(!s->budget--) { s->failed_pc=0x0c0aa364u; return 0; }
write(ram,r[14]+r[0],r[4],2);
if(!vf3_matrix_family(0x0c0aa366u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa366u; return 0; } return 1;
P_0c0aa380: /* original e03e, guest PC 0x0c0aa380 */
if(!s->budget--) { s->failed_pc=0x0c0aa380u; return 0; }
r[0]=0x0000003eu;
goto P_0c0aa382;
P_0c0aa382: /* original 0e95, guest PC 0x0c0aa382 */
if(!s->budget--) { s->failed_pc=0x0c0aa382u; return 0; }
write(ram,r[14]+r[0],r[9],2);
goto P_0c0aa384;
P_0c0aa384: /* original 52d2, guest PC 0x0c0aa384 */
if(!s->budget--) { s->failed_pc=0x0c0aa384u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0aa386;
P_0c0aa386: /* original d346, guest PC 0x0c0aa386 */
if(!s->budget--) { s->failed_pc=0x0c0aa386u; return 0; }
r[3]=read(ram,0x0c0aa4a0u,4);
goto P_0c0aa388;
P_0c0aa388: /* original 2238, guest PC 0x0c0aa388 */
if(!s->budget--) { s->failed_pc=0x0c0aa388u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0aa38a;
P_0c0aa38a: /* original 8915, guest PC 0x0c0aa38a */
if(!s->budget--) { s->failed_pc=0x0c0aa38au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa3b8; }
goto P_0c0aa38c;
P_0c0aa38c: /* original 9080, guest PC 0x0c0aa38c */
if(!s->budget--) { s->failed_pc=0x0c0aa38cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa490u,2);
goto P_0c0aa38e;
P_0c0aa38e: /* original 64f2, guest PC 0x0c0aa38e */
if(!s->budget--) { s->failed_pc=0x0c0aa38eu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0aa390;
P_0c0aa390: /* original 01ec, guest PC 0x0c0aa390 */
if(!s->budget--) { s->failed_pc=0x0c0aa390u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aa392;
P_0c0aa392: /* original e030, guest PC 0x0c0aa392 */
if(!s->budget--) { s->failed_pc=0x0c0aa392u; return 0; }
r[0]=0x00000030u;
goto P_0c0aa394;
P_0c0aa394: /* original 927b, guest PC 0x0c0aa394 */
if(!s->budget--) { s->failed_pc=0x0c0aa394u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa48eu,2);
goto P_0c0aa396;
P_0c0aa396: /* original 611c, guest PC 0x0c0aa396 */
if(!s->budget--) { s->failed_pc=0x0c0aa396u; return 0; }
r[1]=r[1]&255u;
goto P_0c0aa398;
P_0c0aa398: /* original 4108, guest PC 0x0c0aa398 */
if(!s->budget--) { s->failed_pc=0x0c0aa398u; return 0; }
r[1]<<=2;
goto P_0c0aa39a;
P_0c0aa39a: /* original 4108, guest PC 0x0c0aa39a */
if(!s->budget--) { s->failed_pc=0x0c0aa39au; return 0; }
r[1]<<=2;
goto P_0c0aa39c;
P_0c0aa39c: /* original 4108, guest PC 0x0c0aa39c */
if(!s->budget--) { s->failed_pc=0x0c0aa39cu; return 0; }
r[1]<<=2;
goto P_0c0aa39e;
P_0c0aa39e: /* original 342c, guest PC 0x0c0aa39e */
if(!s->budget--) { s->failed_pc=0x0c0aa39eu; return 0; }
r[4]+=r[2];
goto P_0c0aa3a0;
P_0c0aa3a0: /* original 341c, guest PC 0x0c0aa3a0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a0u; return 0; }
r[4]+=r[1];
goto P_0c0aa3a2;
P_0c0aa3a2: /* original f346, guest PC 0x0c0aa3a2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0aa3a4;
P_0c0aa3a4: /* original 9075, guest PC 0x0c0aa3a4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa492u,2);
goto P_0c0aa3a6;
P_0c0aa3a6: /* original fe37, guest PC 0x0c0aa3a6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aa3a8;
P_0c0aa3a8: /* original e034, guest PC 0x0c0aa3a8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3a8u; return 0; }
r[0]=0x00000034u;
goto P_0c0aa3aa;
P_0c0aa3aa: /* original f346, guest PC 0x0c0aa3aa */
if(!s->budget--) { s->failed_pc=0x0c0aa3aau; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0aa3ac;
P_0c0aa3ac: /* original 9072, guest PC 0x0c0aa3ac */
if(!s->budget--) { s->failed_pc=0x0c0aa3acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa494u,2);
goto P_0c0aa3ae;
P_0c0aa3ae: /* original fe37, guest PC 0x0c0aa3ae */
if(!s->budget--) { s->failed_pc=0x0c0aa3aeu; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aa3b0;
P_0c0aa3b0: /* original e038, guest PC 0x0c0aa3b0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b0u; return 0; }
r[0]=0x00000038u;
goto P_0c0aa3b2;
P_0c0aa3b2: /* original f346, guest PC 0x0c0aa3b2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b2u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0aa3b4;
P_0c0aa3b4: /* original 906f, guest PC 0x0c0aa3b4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa496u,2);
goto P_0c0aa3b6;
P_0c0aa3b6: /* original fe37, guest PC 0x0c0aa3b6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0aa3b8;
P_0c0aa3b8: /* original 53d2, guest PC 0x0c0aa3b8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3b8u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa3ba;
P_0c0aa3ba: /* original 2a38, guest PC 0x0c0aa3ba */
if(!s->budget--) { s->failed_pc=0x0c0aa3bau; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[3])==0)!=0);
goto P_0c0aa3bc;
P_0c0aa3bc: /* original 8910, guest PC 0x0c0aa3bc */
if(!s->budget--) { s->failed_pc=0x0c0aa3bcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aa3e0; }
goto P_0c0aa3be;
P_0c0aa3be: /* original 54d2, guest PC 0x0c0aa3be */
if(!s->budget--) { s->failed_pc=0x0c0aa3beu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0aa3c0;
P_0c0aa3c0: /* original d338, guest PC 0x0c0aa3c0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c0u; return 0; }
r[3]=read(ram,0x0c0aa4a4u,4);
goto P_0c0aa3c2;
P_0c0aa3c2: /* original 644d, guest PC 0x0c0aa3c2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c2u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0aa3c4;
P_0c0aa3c4: /* original 430b, guest PC 0x0c0aa3c4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa3c8u;
r[5]=0x00000003u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa3c8u) { target=s->pc; goto dispatch; }
goto P_0c0aa3c8;
P_0c0aa3c6: /* original e503, guest PC 0x0c0aa3c6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c6u; return 0; }
r[5]=0x00000003u;
goto P_0c0aa3c8;
P_0c0aa3c8: /* original 6403, guest PC 0x0c0aa3c8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3c8u; return 0; }
r[4]=r[0];
goto P_0c0aa3ca;
P_0c0aa3ca: /* original 8446, guest PC 0x0c0aa3ca */
if(!s->budget--) { s->failed_pc=0x0c0aa3cau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0aa3cc;
P_0c0aa3cc: /* original 9364, guest PC 0x0c0aa3cc */
if(!s->budget--) { s->failed_pc=0x0c0aa3ccu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa498u,2);
goto P_0c0aa3ce;
P_0c0aa3ce: /* original 600c, guest PC 0x0c0aa3ce */
if(!s->budget--) { s->failed_pc=0x0c0aa3ceu; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa3d0;
P_0c0aa3d0: /* original 4018, guest PC 0x0c0aa3d0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d0u; return 0; }
r[0]<<=8;
goto P_0c0aa3d2;
P_0c0aa3d2: /* original 2039, guest PC 0x0c0aa3d2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d2u; return 0; }
r[0]&=r[3];
goto P_0c0aa3d4;
P_0c0aa3d4: /* original 6203, guest PC 0x0c0aa3d4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d4u; return 0; }
r[2]=r[0];
goto P_0c0aa3d6;
P_0c0aa3d6: /* original 8445, guest PC 0x0c0aa3d6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0aa3d8;
P_0c0aa3d8: /* original 600c, guest PC 0x0c0aa3d8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aa3da;
P_0c0aa3da: /* original 220b, guest PC 0x0c0aa3da */
if(!s->budget--) { s->failed_pc=0x0c0aa3dau; return 0; }
r[2]|=r[0];
goto P_0c0aa3dc;
P_0c0aa3dc: /* original 905d, guest PC 0x0c0aa3dc */
if(!s->budget--) { s->failed_pc=0x0c0aa3dcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aa49au,2);
goto P_0c0aa3de;
P_0c0aa3de: /* original 0e25, guest PC 0x0c0aa3de */
if(!s->budget--) { s->failed_pc=0x0c0aa3deu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0aa3e0;
P_0c0aa3e0: /* original 53d2, guest PC 0x0c0aa3e0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e0u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aa3e2;
P_0c0aa3e2: /* original 1e3e, guest PC 0x0c0aa3e2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e2u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0aa3e4;
P_0c0aa3e4: /* original 7f04, guest PC 0x0c0aa3e4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aa3e6;
P_0c0aa3e6: /* original 64e3, guest PC 0x0c0aa3e6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e6u; return 0; }
r[4]=r[14];
goto P_0c0aa3e8;
P_0c0aa3e8: /* original 4f26, guest PC 0x0c0aa3e8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3e8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa3ea;
P_0c0aa3ea: /* original 68f6, guest PC 0x0c0aa3ea */
if(!s->budget--) { s->failed_pc=0x0c0aa3eau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0aa3ec;
P_0c0aa3ec: /* original 69f6, guest PC 0x0c0aa3ec */
if(!s->budget--) { s->failed_pc=0x0c0aa3ecu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0aa3ee;
P_0c0aa3ee: /* original 6af6, guest PC 0x0c0aa3ee */
if(!s->budget--) { s->failed_pc=0x0c0aa3eeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0aa3f0;
P_0c0aa3f0: /* original 6bf6, guest PC 0x0c0aa3f0 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0aa3f2;
P_0c0aa3f2: /* original 6cf6, guest PC 0x0c0aa3f2 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aa3f4;
P_0c0aa3f4: /* original 6df6, guest PC 0x0c0aa3f4 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aa3f6;
P_0c0aa3f6: /* original add8, guest PC 0x0c0aa3f6 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0a9faa;
P_0c0aa3f8: /* original 6ef6, guest PC 0x0c0aa3f8 */
if(!s->budget--) { s->failed_pc=0x0c0aa3f8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c0aa3fau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa3fau; return 0; } return 1;
P_0c0aa444: /* original 534e, guest PC 0x0c0aa444 */
if(!s->budget--) { s->failed_pc=0x0c0aa444u; return 0; }
r[3]=read(ram,r[4]+56,4);
goto P_0c0aa446;
P_0c0aa446: /* original 4f22, guest PC 0x0c0aa446 */
if(!s->budget--) { s->failed_pc=0x0c0aa446u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aa448;
P_0c0aa448: /* original 6233, guest PC 0x0c0aa448 */
if(!s->budget--) { s->failed_pc=0x0c0aa448u; return 0; }
r[2]=r[3];
goto P_0c0aa44a;
P_0c0aa44a: /* original 2228, guest PC 0x0c0aa44a */
if(!s->budget--) { s->failed_pc=0x0c0aa44au; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aa44c;
P_0c0aa44c: /* original 7ff4, guest PC 0x0c0aa44c */
if(!s->budget--) { s->failed_pc=0x0c0aa44cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0aa44e;
P_0c0aa44e: /* original 8d0e, guest PC 0x0c0aa44e */
if(!s->budget--) { s->failed_pc=0x0c0aa44eu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[3],4);
if(cond) { goto P_0c0aa46e; }
goto P_0c0aa452;
P_0c0aa450: /* original 1f31, guest PC 0x0c0aa450 */
if(!s->budget--) { s->failed_pc=0x0c0aa450u; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0aa452;
P_0c0aa452: /* original e062, guest PC 0x0c0aa452 */
if(!s->budget--) { s->failed_pc=0x0c0aa452u; return 0; }
r[0]=0x00000062u;
goto P_0c0aa454;
P_0c0aa454: /* original 024c, guest PC 0x0c0aa454 */
if(!s->budget--) { s->failed_pc=0x0c0aa454u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0aa456;
P_0c0aa456: /* original 622c, guest PC 0x0c0aa456 */
if(!s->budget--) { s->failed_pc=0x0c0aa456u; return 0; }
r[2]=r[2]&255u;
goto P_0c0aa458;
P_0c0aa458: /* original 1f22, guest PC 0x0c0aa458 */
if(!s->budget--) { s->failed_pc=0x0c0aa458u; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0aa45a;
P_0c0aa45a: /* original 56f1, guest PC 0x0c0aa45a */
if(!s->budget--) { s->failed_pc=0x0c0aa45au; return 0; }
r[6]=read(ram,r[15]+4,4);
goto P_0c0aa45c;
P_0c0aa45c: /* original d013, guest PC 0x0c0aa45c */
if(!s->budget--) { s->failed_pc=0x0c0aa45cu; return 0; }
r[0]=read(ram,0x0c0aa4acu,4);
goto P_0c0aa45e;
P_0c0aa45e: /* original 4629, guest PC 0x0c0aa45e */
if(!s->budget--) { s->failed_pc=0x0c0aa45eu; return 0; }
r[6]>>=16;
goto P_0c0aa460;
P_0c0aa460: /* original 4619, guest PC 0x0c0aa460 */
if(!s->budget--) { s->failed_pc=0x0c0aa460u; return 0; }
r[6]>>=8;
goto P_0c0aa462;
P_0c0aa462: /* original 4608, guest PC 0x0c0aa462 */
if(!s->budget--) { s->failed_pc=0x0c0aa462u; return 0; }
r[6]<<=2;
goto P_0c0aa464;
P_0c0aa464: /* original 036e, guest PC 0x0c0aa464 */
if(!s->budget--) { s->failed_pc=0x0c0aa464u; return 0; }
r[3]=read(ram,r[6]+r[0],4);
goto P_0c0aa466;
P_0c0aa466: /* original 66f3, guest PC 0x0c0aa466 */
if(!s->budget--) { s->failed_pc=0x0c0aa466u; return 0; }
r[6]=r[15];
goto P_0c0aa468;
P_0c0aa468: /* original 2f32, guest PC 0x0c0aa468 */
if(!s->budget--) { s->failed_pc=0x0c0aa468u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0aa46a;
P_0c0aa46a: /* original 430b, guest PC 0x0c0aa46a */
if(!s->budget--) { s->failed_pc=0x0c0aa46au; return 0; }
target=r[3];
r[16]=code_base|0x0c0aa46eu;
r[6]+=0x00000004u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0aa46eu) { target=s->pc; goto dispatch; }
goto P_0c0aa46e;
P_0c0aa46c: /* original 7604, guest PC 0x0c0aa46c */
if(!s->budget--) { s->failed_pc=0x0c0aa46cu; return 0; }
r[6]+=0x00000004u;
goto P_0c0aa46e;
P_0c0aa46e: /* original 7f0c, guest PC 0x0c0aa46e */
if(!s->budget--) { s->failed_pc=0x0c0aa46eu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0aa470;
P_0c0aa470: /* original 4f26, guest PC 0x0c0aa470 */
if(!s->budget--) { s->failed_pc=0x0c0aa470u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aa472;
P_0c0aa472: /* original 000b, guest PC 0x0c0aa472 */
if(!s->budget--) { s->failed_pc=0x0c0aa472u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0aa474: /* original 0009, guest PC 0x0c0aa474 */
if(!s->budget--) { s->failed_pc=0x0c0aa474u; return 0; }
if(!vf3_matrix_family(0x0c0aa476u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c0aa476u; return 0; } return 1;
unsupported: s->failed_pc=target; return 0;
}
