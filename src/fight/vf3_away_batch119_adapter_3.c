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
int vf3_away_batch119_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0409d2u: goto P_0c0409d2;
case 0x0c0409d4u: goto P_0c0409d4;
case 0x0c0409d6u: goto P_0c0409d6;
case 0x0c0409d8u: goto P_0c0409d8;
case 0x0c0409dau: goto P_0c0409da;
case 0x0c0409dcu: goto P_0c0409dc;
case 0x0c0409deu: goto P_0c0409de;
case 0x0c0409e0u: goto P_0c0409e0;
case 0x0c0409e2u: goto P_0c0409e2;
case 0x0c0409e4u: goto P_0c0409e4;
case 0x0c0409e6u: goto P_0c0409e6;
case 0x0c0409e8u: goto P_0c0409e8;
case 0x0c0409eau: goto P_0c0409ea;
case 0x0c0409ecu: goto P_0c0409ec;
case 0x0c0409eeu: goto P_0c0409ee;
case 0x0c0409f0u: goto P_0c0409f0;
case 0x0c0409f2u: goto P_0c0409f2;
case 0x0c0409f4u: goto P_0c0409f4;
case 0x0c0409f6u: goto P_0c0409f6;
case 0x0c0409f8u: goto P_0c0409f8;
case 0x0c0409fau: goto P_0c0409fa;
case 0x0c0409fcu: goto P_0c0409fc;
case 0x0c0409feu: goto P_0c0409fe;
case 0x0c040a00u: goto P_0c040a00;
case 0x0c040a02u: goto P_0c040a02;
case 0x0c040a04u: goto P_0c040a04;
case 0x0c040a06u: goto P_0c040a06;
case 0x0c040a08u: goto P_0c040a08;
case 0x0c040a0au: goto P_0c040a0a;
case 0x0c040a0cu: goto P_0c040a0c;
case 0x0c040a0eu: goto P_0c040a0e;
case 0x0c040a10u: goto P_0c040a10;
case 0x0c040a12u: goto P_0c040a12;
case 0x0c040a14u: goto P_0c040a14;
case 0x0c040a16u: goto P_0c040a16;
case 0x0c040a18u: goto P_0c040a18;
case 0x0c040a1au: goto P_0c040a1a;
case 0x0c040a1cu: goto P_0c040a1c;
case 0x0c040a1eu: goto P_0c040a1e;
case 0x0c040a20u: goto P_0c040a20;
case 0x0c040a30u: goto P_0c040a30;
case 0x0c040a32u: goto P_0c040a32;
case 0x0c040a34u: goto P_0c040a34;
case 0x0c040a36u: goto P_0c040a36;
case 0x0c040a38u: goto P_0c040a38;
case 0x0c040a3au: goto P_0c040a3a;
case 0x0c040a3cu: goto P_0c040a3c;
case 0x0c040a3eu: goto P_0c040a3e;
case 0x0c040a40u: goto P_0c040a40;
case 0x0c040a42u: goto P_0c040a42;
case 0x0c040a44u: goto P_0c040a44;
case 0x0c040a46u: goto P_0c040a46;
case 0x0c040a48u: goto P_0c040a48;
case 0x0c040a4au: goto P_0c040a4a;
case 0x0c040a4cu: goto P_0c040a4c;
case 0x0c040a4eu: goto P_0c040a4e;
case 0x0c040a50u: goto P_0c040a50;
case 0x0c040a52u: goto P_0c040a52;
case 0x0c040a54u: goto P_0c040a54;
case 0x0c040a56u: goto P_0c040a56;
case 0x0c040a58u: goto P_0c040a58;
case 0x0c040a5au: goto P_0c040a5a;
case 0x0c040a5cu: goto P_0c040a5c;
case 0x0c040a5eu: goto P_0c040a5e;
case 0x0c040a60u: goto P_0c040a60;
case 0x0c040a62u: goto P_0c040a62;
case 0x0c040a64u: goto P_0c040a64;
case 0x0c040a66u: goto P_0c040a66;
case 0x0c040a68u: goto P_0c040a68;
case 0x0c040a6au: goto P_0c040a6a;
case 0x0c040a6cu: goto P_0c040a6c;
case 0x0c040a6eu: goto P_0c040a6e;
case 0x0c040a70u: goto P_0c040a70;
case 0x0c040a72u: goto P_0c040a72;
case 0x0c040a74u: goto P_0c040a74;
case 0x0c040a76u: goto P_0c040a76;
case 0x0c040a78u: goto P_0c040a78;
case 0x0c040a7au: goto P_0c040a7a;
case 0x0c040a7cu: goto P_0c040a7c;
case 0x0c040a7eu: goto P_0c040a7e;
case 0x0c040a80u: goto P_0c040a80;
case 0x0c040a82u: goto P_0c040a82;
case 0x0c040a84u: goto P_0c040a84;
case 0x0c040a86u: goto P_0c040a86;
case 0x0c040a88u: goto P_0c040a88;
case 0x0c040a8au: goto P_0c040a8a;
case 0x0c040a8cu: goto P_0c040a8c;
case 0x0c040a8eu: goto P_0c040a8e;
case 0x0c040a90u: goto P_0c040a90;
case 0x0c040a92u: goto P_0c040a92;
case 0x0c040a94u: goto P_0c040a94;
case 0x0c040a96u: goto P_0c040a96;
case 0x0c040a98u: goto P_0c040a98;
case 0x0c040a9au: goto P_0c040a9a;
case 0x0c040a9cu: goto P_0c040a9c;
case 0x0c040a9eu: goto P_0c040a9e;
case 0x0c040aa0u: goto P_0c040aa0;
case 0x0c040aa2u: goto P_0c040aa2;
case 0x0c040aa4u: goto P_0c040aa4;
case 0x0c040aa6u: goto P_0c040aa6;
case 0x0c040aa8u: goto P_0c040aa8;
case 0x0c040aaau: goto P_0c040aaa;
case 0x0c040aacu: goto P_0c040aac;
case 0x0c040aaeu: goto P_0c040aae;
case 0x0c040ab0u: goto P_0c040ab0;
case 0x0c040ab2u: goto P_0c040ab2;
case 0x0c040ab4u: goto P_0c040ab4;
case 0x0c040ab6u: goto P_0c040ab6;
case 0x0c040ab8u: goto P_0c040ab8;
case 0x0c040abau: goto P_0c040aba;
case 0x0c040accu: goto P_0c040acc;
case 0x0c040aceu: goto P_0c040ace;
case 0x0c040ad0u: goto P_0c040ad0;
case 0x0c040ad2u: goto P_0c040ad2;
case 0x0c040ad4u: goto P_0c040ad4;
case 0x0c040ad6u: goto P_0c040ad6;
case 0x0c040ad8u: goto P_0c040ad8;
case 0x0c040adau: goto P_0c040ada;
case 0x0c040adcu: goto P_0c040adc;
case 0x0c040adeu: goto P_0c040ade;
case 0x0c040ae0u: goto P_0c040ae0;
case 0x0c040ae2u: goto P_0c040ae2;
case 0x0c040ae4u: goto P_0c040ae4;
case 0x0c040ae6u: goto P_0c040ae6;
case 0x0c040ae8u: goto P_0c040ae8;
case 0x0c040aeau: goto P_0c040aea;
case 0x0c040aecu: goto P_0c040aec;
case 0x0c040aeeu: goto P_0c040aee;
case 0x0c040af0u: goto P_0c040af0;
case 0x0c040af2u: goto P_0c040af2;
case 0x0c040f1eu: goto P_0c040f1e;
case 0x0c040f20u: goto P_0c040f20;
case 0x0c040f22u: goto P_0c040f22;
case 0x0c040f24u: goto P_0c040f24;
case 0x0c040f26u: goto P_0c040f26;
case 0x0c040f28u: goto P_0c040f28;
case 0x0c040f2au: goto P_0c040f2a;
case 0x0c040f2cu: goto P_0c040f2c;
case 0x0c040f2eu: goto P_0c040f2e;
case 0x0c040f30u: goto P_0c040f30;
case 0x0c040f32u: goto P_0c040f32;
case 0x0c040f34u: goto P_0c040f34;
case 0x0c040f36u: goto P_0c040f36;
case 0x0c040f38u: goto P_0c040f38;
case 0x0c040f3au: goto P_0c040f3a;
case 0x0c040f3cu: goto P_0c040f3c;
case 0x0c040f3eu: goto P_0c040f3e;
case 0x0c040f40u: goto P_0c040f40;
case 0x0c040f42u: goto P_0c040f42;
case 0x0c040f44u: goto P_0c040f44;
case 0x0c040f46u: goto P_0c040f46;
case 0x0c040f48u: goto P_0c040f48;
case 0x0c040f4au: goto P_0c040f4a;
case 0x0c040f4cu: goto P_0c040f4c;
case 0x0c040f4eu: goto P_0c040f4e;
case 0x0c040f50u: goto P_0c040f50;
case 0x0c040f52u: goto P_0c040f52;
case 0x0c040f54u: goto P_0c040f54;
case 0x0c040f56u: goto P_0c040f56;
case 0x0c040f58u: goto P_0c040f58;
case 0x0c040f5au: goto P_0c040f5a;
case 0x0c040f5cu: goto P_0c040f5c;
case 0x0c040f5eu: goto P_0c040f5e;
case 0x0c040f60u: goto P_0c040f60;
case 0x0c040f62u: goto P_0c040f62;
case 0x0c040f64u: goto P_0c040f64;
case 0x0c040f66u: goto P_0c040f66;
case 0x0c046314u: goto P_0c046314;
case 0x0c046316u: goto P_0c046316;
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
P_0c0409d2: /* original 4f22, guest PC 0x0c0409d2 */
if(!s->budget--) { s->failed_pc=0x0c0409d2u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0409d4;
P_0c0409d4: /* original 7fe8, guest PC 0x0c0409d4 */
if(!s->budget--) { s->failed_pc=0x0c0409d4u; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0409d6;
P_0c0409d6: /* original 1f45, guest PC 0x0c0409d6 */
if(!s->budget--) { s->failed_pc=0x0c0409d6u; return 0; }
write(ram,r[15]+20,r[4],4);
goto P_0c0409d8;
P_0c0409d8: /* original 54f5, guest PC 0x0c0409d8 */
if(!s->budget--) { s->failed_pc=0x0c0409d8u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c0409da;
P_0c0409da: /* original bccd, guest PC 0x0c0409da */
if(!s->budget--) { s->failed_pc=0x0c0409dau; return 0; }
target=code_base|0x0c040378u; r[16]=code_base|0x0c0409deu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c0409deu) { target=s->pc; goto dispatch; }
goto P_0c0409de;
P_0c0409dc: /* original 0009, guest PC 0x0c0409dc */
if(!s->budget--) { s->failed_pc=0x0c0409dcu; return 0; }
goto P_0c0409de;
P_0c0409de: /* original 2f02, guest PC 0x0c0409de */
if(!s->budget--) { s->failed_pc=0x0c0409deu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0409e0;
P_0c0409e0: /* original 2008, guest PC 0x0c0409e0 */
if(!s->budget--) { s->failed_pc=0x0c0409e0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c0409e2;
P_0c0409e2: /* original 8903, guest PC 0x0c0409e2 */
if(!s->budget--) { s->failed_pc=0x0c0409e2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0409ec; }
goto P_0c0409e4;
P_0c0409e4: /* original 7f18, guest PC 0x0c0409e4 */
if(!s->budget--) { s->failed_pc=0x0c0409e4u; return 0; }
r[15]+=0x00000018u;
goto P_0c0409e6;
P_0c0409e6: /* original 4f26, guest PC 0x0c0409e6 */
if(!s->budget--) { s->failed_pc=0x0c0409e6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0409e8;
P_0c0409e8: /* original 000b, guest PC 0x0c0409e8 */
if(!s->budget--) { s->failed_pc=0x0c0409e8u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0409ea: /* original 0009, guest PC 0x0c0409ea */
if(!s->budget--) { s->failed_pc=0x0c0409eau; return 0; }
goto P_0c0409ec;
P_0c0409ec: /* original 52f5, guest PC 0x0c0409ec */
if(!s->budget--) { s->failed_pc=0x0c0409ecu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c0409ee;
P_0c0409ee: /* original 6323, guest PC 0x0c0409ee */
if(!s->budget--) { s->failed_pc=0x0c0409eeu; return 0; }
r[3]=r[2];
goto P_0c0409f0;
P_0c0409f0: /* original 4200, guest PC 0x0c0409f0 */
if(!s->budget--) { s->failed_pc=0x0c0409f0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c0409f2;
P_0c0409f2: /* original 323c, guest PC 0x0c0409f2 */
if(!s->budget--) { s->failed_pc=0x0c0409f2u; return 0; }
r[2]+=r[3];
goto P_0c0409f4;
P_0c0409f4: /* original 4208, guest PC 0x0c0409f4 */
if(!s->budget--) { s->failed_pc=0x0c0409f4u; return 0; }
r[2]<<=2;
goto P_0c0409f6;
P_0c0409f6: /* original 622e, guest PC 0x0c0409f6 */
if(!s->budget--) { s->failed_pc=0x0c0409f6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)r[2];
goto P_0c0409f8;
P_0c0409f8: /* original d00c, guest PC 0x0c0409f8 */
if(!s->budget--) { s->failed_pc=0x0c0409f8u; return 0; }
r[0]=read(ram,0x0c040a2cu,4);
goto P_0c0409fa;
P_0c0409fa: /* original 012e, guest PC 0x0c0409fa */
if(!s->budget--) { s->failed_pc=0x0c0409fau; return 0; }
r[1]=read(ram,r[2]+r[0],4);
goto P_0c0409fc;
P_0c0409fc: /* original 1f11, guest PC 0x0c0409fc */
if(!s->budget--) { s->failed_pc=0x0c0409fcu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c0409fe;
P_0c0409fe: /* original 66f3, guest PC 0x0c0409fe */
if(!s->budget--) { s->failed_pc=0x0c0409feu; return 0; }
r[6]=r[15];
goto P_0c040a00;
P_0c040a00: /* original 7608, guest PC 0x0c040a00 */
if(!s->budget--) { s->failed_pc=0x0c040a00u; return 0; }
r[6]+=0x00000008u;
goto P_0c040a02;
P_0c040a02: /* original 55f1, guest PC 0x0c040a02 */
if(!s->budget--) { s->failed_pc=0x0c040a02u; return 0; }
r[5]=read(ram,r[15]+4,4);
goto P_0c040a04;
P_0c040a04: /* original 54f5, guest PC 0x0c040a04 */
if(!s->budget--) { s->failed_pc=0x0c040a04u; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c040a06;
P_0c040a06: /* original bcdb, guest PC 0x0c040a06 */
if(!s->budget--) { s->failed_pc=0x0c040a06u; return 0; }
target=code_base|0x0c0403c0u; r[16]=code_base|0x0c040a0au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a0au) { target=s->pc; goto dispatch; }
goto P_0c040a0a;
P_0c040a08: /* original 0009, guest PC 0x0c040a08 */
if(!s->budget--) { s->failed_pc=0x0c040a08u; return 0; }
goto P_0c040a0a;
P_0c040a0a: /* original 1f04, guest PC 0x0c040a0a */
if(!s->budget--) { s->failed_pc=0x0c040a0au; return 0; }
write(ram,r[15]+16,r[0],4);
goto P_0c040a0c;
P_0c040a0c: /* original e300, guest PC 0x0c040a0c */
if(!s->budget--) { s->failed_pc=0x0c040a0cu; return 0; }
r[3]=0x00000000u;
goto P_0c040a0e;
P_0c040a0e: /* original 1f33, guest PC 0x0c040a0e */
if(!s->budget--) { s->failed_pc=0x0c040a0eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c040a10;
P_0c040a10: /* original a011, guest PC 0x0c040a10 */
if(!s->budget--) { s->failed_pc=0x0c040a10u; return 0; }
goto P_0c040a36;
P_0c040a12: /* original 0009, guest PC 0x0c040a12 */
if(!s->budget--) { s->failed_pc=0x0c040a12u; return 0; }
goto P_0c040a14;
P_0c040a14: /* original 9405, guest PC 0x0c040a14 */
if(!s->budget--) { s->failed_pc=0x0c040a14u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040a22u,2);
goto P_0c040a16;
P_0c040a16: /* original b282, guest PC 0x0c040a16 */
if(!s->budget--) { s->failed_pc=0x0c040a16u; return 0; }
target=code_base|0x0c040f1eu; r[16]=code_base|0x0c040a1au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a1au) { target=s->pc; goto dispatch; }
goto P_0c040a1a;
P_0c040a18: /* original 0009, guest PC 0x0c040a18 */
if(!s->budget--) { s->failed_pc=0x0c040a18u; return 0; }
goto P_0c040a1a;
P_0c040a1a: /* original 2008, guest PC 0x0c040a1a */
if(!s->budget--) { s->failed_pc=0x0c040a1au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c040a1c;
P_0c040a1c: /* original 8b08, guest PC 0x0c040a1c */
if(!s->budget--) { s->failed_pc=0x0c040a1cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a30; }
goto P_0c040a1e;
P_0c040a1e: /* original a013, guest PC 0x0c040a1e */
if(!s->budget--) { s->failed_pc=0x0c040a1eu; return 0; }
goto P_0c040a48;
P_0c040a20: /* original 0009, guest PC 0x0c040a20 */
if(!s->budget--) { s->failed_pc=0x0c040a20u; return 0; }
if(!vf3_matrix_family(0x0c040a22u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040a22u; return 0; } return 1;
P_0c040a30: /* original 52f3, guest PC 0x0c040a30 */
if(!s->budget--) { s->failed_pc=0x0c040a30u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040a32;
P_0c040a32: /* original 7201, guest PC 0x0c040a32 */
if(!s->budget--) { s->failed_pc=0x0c040a32u; return 0; }
r[2]+=0x00000001u;
goto P_0c040a34;
P_0c040a34: /* original 1f23, guest PC 0x0c040a34 */
if(!s->budget--) { s->failed_pc=0x0c040a34u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040a36;
P_0c040a36: /* original d322, guest PC 0x0c040a36 */
if(!s->budget--) { s->failed_pc=0x0c040a36u; return 0; }
r[3]=read(ram,0x0c040ac0u,4);
goto P_0c040a38;
P_0c040a38: /* original 51f3, guest PC 0x0c040a38 */
if(!s->budget--) { s->failed_pc=0x0c040a38u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040a3a;
P_0c040a3a: /* original 3133, guest PC 0x0c040a3a */
if(!s->budget--) { s->failed_pc=0x0c040a3au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040a3c;
P_0c040a3c: /* original 8bea, guest PC 0x0c040a3c */
if(!s->budget--) { s->failed_pc=0x0c040a3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a14; }
goto P_0c040a3e;
P_0c040a3e: /* original 903d, guest PC 0x0c040a3e */
if(!s->budget--) { s->failed_pc=0x0c040a3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040abcu,2);
goto P_0c040a40;
P_0c040a40: /* original 7f18, guest PC 0x0c040a40 */
if(!s->budget--) { s->failed_pc=0x0c040a40u; return 0; }
r[15]+=0x00000018u;
goto P_0c040a42;
P_0c040a42: /* original 4f26, guest PC 0x0c040a42 */
if(!s->budget--) { s->failed_pc=0x0c040a42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040a44;
P_0c040a44: /* original 000b, guest PC 0x0c040a44 */
if(!s->budget--) { s->failed_pc=0x0c040a44u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040a46: /* original 0009, guest PC 0x0c040a46 */
if(!s->budget--) { s->failed_pc=0x0c040a46u; return 0; }
goto P_0c040a48;
P_0c040a48: /* original e300, guest PC 0x0c040a48 */
if(!s->budget--) { s->failed_pc=0x0c040a48u; return 0; }
r[3]=0x00000000u;
goto P_0c040a4a;
P_0c040a4a: /* original 1f33, guest PC 0x0c040a4a */
if(!s->budget--) { s->failed_pc=0x0c040a4au; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c040a4c;
P_0c040a4c: /* original a009, guest PC 0x0c040a4c */
if(!s->budget--) { s->failed_pc=0x0c040a4cu; return 0; }
goto P_0c040a62;
P_0c040a4e: /* original 0009, guest PC 0x0c040a4e */
if(!s->budget--) { s->failed_pc=0x0c040a4eu; return 0; }
goto P_0c040a50;
P_0c040a50: /* original d21c, guest PC 0x0c040a50 */
if(!s->budget--) { s->failed_pc=0x0c040a50u; return 0; }
r[2]=read(ram,0x0c040ac4u,4);
goto P_0c040a52;
P_0c040a52: /* original 6122, guest PC 0x0c040a52 */
if(!s->budget--) { s->failed_pc=0x0c040a52u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040a54;
P_0c040a54: /* original 2118, guest PC 0x0c040a54 */
if(!s->budget--) { s->failed_pc=0x0c040a54u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040a56;
P_0c040a56: /* original 8901, guest PC 0x0c040a56 */
if(!s->budget--) { s->failed_pc=0x0c040a56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040a5c; }
goto P_0c040a58;
P_0c040a58: /* original a00c, guest PC 0x0c040a58 */
if(!s->budget--) { s->failed_pc=0x0c040a58u; return 0; }
goto P_0c040a74;
P_0c040a5a: /* original 0009, guest PC 0x0c040a5a */
if(!s->budget--) { s->failed_pc=0x0c040a5au; return 0; }
goto P_0c040a5c;
P_0c040a5c: /* original 52f3, guest PC 0x0c040a5c */
if(!s->budget--) { s->failed_pc=0x0c040a5cu; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c040a5e;
P_0c040a5e: /* original 7201, guest PC 0x0c040a5e */
if(!s->budget--) { s->failed_pc=0x0c040a5eu; return 0; }
r[2]+=0x00000001u;
goto P_0c040a60;
P_0c040a60: /* original 1f23, guest PC 0x0c040a60 */
if(!s->budget--) { s->failed_pc=0x0c040a60u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c040a62;
P_0c040a62: /* original d317, guest PC 0x0c040a62 */
if(!s->budget--) { s->failed_pc=0x0c040a62u; return 0; }
r[3]=read(ram,0x0c040ac0u,4);
goto P_0c040a64;
P_0c040a64: /* original 51f3, guest PC 0x0c040a64 */
if(!s->budget--) { s->failed_pc=0x0c040a64u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040a66;
P_0c040a66: /* original 3133, guest PC 0x0c040a66 */
if(!s->budget--) { s->failed_pc=0x0c040a66u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c040a68;
P_0c040a68: /* original 8bf2, guest PC 0x0c040a68 */
if(!s->budget--) { s->failed_pc=0x0c040a68u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a50; }
goto P_0c040a6a;
P_0c040a6a: /* original 9027, guest PC 0x0c040a6a */
if(!s->budget--) { s->failed_pc=0x0c040a6au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040abcu,2);
goto P_0c040a6c;
P_0c040a6c: /* original 7f18, guest PC 0x0c040a6c */
if(!s->budget--) { s->failed_pc=0x0c040a6cu; return 0; }
r[15]+=0x00000018u;
goto P_0c040a6e;
P_0c040a6e: /* original 4f26, guest PC 0x0c040a6e */
if(!s->budget--) { s->failed_pc=0x0c040a6eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040a70;
P_0c040a70: /* original 000b, guest PC 0x0c040a70 */
if(!s->budget--) { s->failed_pc=0x0c040a70u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040a72: /* original 0009, guest PC 0x0c040a72 */
if(!s->budget--) { s->failed_pc=0x0c040a72u; return 0; }
goto P_0c040a74;
P_0c040a74: /* original 53f4, guest PC 0x0c040a74 */
if(!s->budget--) { s->failed_pc=0x0c040a74u; return 0; }
r[3]=read(ram,r[15]+16,4);
goto P_0c040a76;
P_0c040a76: /* original 2338, guest PC 0x0c040a76 */
if(!s->budget--) { s->failed_pc=0x0c040a76u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c040a78;
P_0c040a78: /* original 8913, guest PC 0x0c040a78 */
if(!s->budget--) { s->failed_pc=0x0c040a78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040aa2; }
goto P_0c040a7a;
P_0c040a7a: /* original 56f2, guest PC 0x0c040a7a */
if(!s->budget--) { s->failed_pc=0x0c040a7au; return 0; }
r[6]=read(ram,r[15]+8,4);
goto P_0c040a7c;
P_0c040a7c: /* original 53f1, guest PC 0x0c040a7c */
if(!s->budget--) { s->failed_pc=0x0c040a7cu; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c040a7e;
P_0c040a7e: /* original 55f4, guest PC 0x0c040a7e */
if(!s->budget--) { s->failed_pc=0x0c040a7eu; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c040a80;
P_0c040a80: /* original 3538, guest PC 0x0c040a80 */
if(!s->budget--) { s->failed_pc=0x0c040a80u; return 0; }
r[5]-=r[3];
goto P_0c040a82;
P_0c040a82: /* original 54f4, guest PC 0x0c040a82 */
if(!s->budget--) { s->failed_pc=0x0c040a82u; return 0; }
r[4]=read(ram,r[15]+16,4);
goto P_0c040a84;
P_0c040a84: /* original bb1c, guest PC 0x0c040a84 */
if(!s->budget--) { s->failed_pc=0x0c040a84u; return 0; }
target=code_base|0x0c0400c0u; r[16]=code_base|0x0c040a88u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a88u) { target=s->pc; goto dispatch; }
goto P_0c040a88;
P_0c040a86: /* original 0009, guest PC 0x0c040a86 */
if(!s->budget--) { s->failed_pc=0x0c040a86u; return 0; }
goto P_0c040a88;
P_0c040a88: /* original 2f02, guest PC 0x0c040a88 */
if(!s->budget--) { s->failed_pc=0x0c040a88u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c040a8a;
P_0c040a8a: /* original 2008, guest PC 0x0c040a8a */
if(!s->budget--) { s->failed_pc=0x0c040a8au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c040a8c;
P_0c040a8c: /* original 8903, guest PC 0x0c040a8c */
if(!s->budget--) { s->failed_pc=0x0c040a8cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040a96; }
goto P_0c040a8e;
P_0c040a8e: /* original 7f18, guest PC 0x0c040a8e */
if(!s->budget--) { s->failed_pc=0x0c040a8eu; return 0; }
r[15]+=0x00000018u;
goto P_0c040a90;
P_0c040a90: /* original 4f26, guest PC 0x0c040a90 */
if(!s->budget--) { s->failed_pc=0x0c040a90u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040a92;
P_0c040a92: /* original 000b, guest PC 0x0c040a92 */
if(!s->budget--) { s->failed_pc=0x0c040a92u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040a94: /* original 0009, guest PC 0x0c040a94 */
if(!s->budget--) { s->failed_pc=0x0c040a94u; return 0; }
goto P_0c040a96;
P_0c040a96: /* original a000, guest PC 0x0c040a96 */
if(!s->budget--) { s->failed_pc=0x0c040a96u; return 0; }
goto P_0c040a9a;
P_0c040a98: /* original 0009, guest PC 0x0c040a98 */
if(!s->budget--) { s->failed_pc=0x0c040a98u; return 0; }
goto P_0c040a9a;
P_0c040a9a: /* original bb4f, guest PC 0x0c040a9a */
if(!s->budget--) { s->failed_pc=0x0c040a9au; return 0; }
target=code_base|0x0c04013cu; r[16]=code_base|0x0c040a9eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c040a9eu) { target=s->pc; goto dispatch; }
goto P_0c040a9e;
P_0c040a9c: /* original 0009, guest PC 0x0c040a9c */
if(!s->budget--) { s->failed_pc=0x0c040a9cu; return 0; }
goto P_0c040a9e;
P_0c040a9e: /* original 2008, guest PC 0x0c040a9e */
if(!s->budget--) { s->failed_pc=0x0c040a9eu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[0])==0)!=0);
goto P_0c040aa0;
P_0c040aa0: /* original 8bfb, guest PC 0x0c040aa0 */
if(!s->budget--) { s->failed_pc=0x0c040aa0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040a9a; }
goto P_0c040aa2;
P_0c040aa2: /* original e301, guest PC 0x0c040aa2 */
if(!s->budget--) { s->failed_pc=0x0c040aa2u; return 0; }
r[3]=0x00000001u;
goto P_0c040aa4;
P_0c040aa4: /* original d208, guest PC 0x0c040aa4 */
if(!s->budget--) { s->failed_pc=0x0c040aa4u; return 0; }
r[2]=read(ram,0x0c040ac8u,4);
goto P_0c040aa6;
P_0c040aa6: /* original 2232, guest PC 0x0c040aa6 */
if(!s->budget--) { s->failed_pc=0x0c040aa6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040aa8;
P_0c040aa8: /* original e100, guest PC 0x0c040aa8 */
if(!s->budget--) { s->failed_pc=0x0c040aa8u; return 0; }
r[1]=0x00000000u;
goto P_0c040aaa;
P_0c040aaa: /* original 1f13, guest PC 0x0c040aaa */
if(!s->budget--) { s->failed_pc=0x0c040aaau; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c040aac;
P_0c040aac: /* original a011, guest PC 0x0c040aac */
if(!s->budget--) { s->failed_pc=0x0c040aacu; return 0; }
goto P_0c040ad2;
P_0c040aae: /* original 0009, guest PC 0x0c040aae */
if(!s->budget--) { s->failed_pc=0x0c040aaeu; return 0; }
goto P_0c040ab0;
P_0c040ab0: /* original d304, guest PC 0x0c040ab0 */
if(!s->budget--) { s->failed_pc=0x0c040ab0u; return 0; }
r[3]=read(ram,0x0c040ac4u,4);
goto P_0c040ab2;
P_0c040ab2: /* original 6232, guest PC 0x0c040ab2 */
if(!s->budget--) { s->failed_pc=0x0c040ab2u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040ab4;
P_0c040ab4: /* original 2228, guest PC 0x0c040ab4 */
if(!s->budget--) { s->failed_pc=0x0c040ab4u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c040ab6;
P_0c040ab6: /* original 8b09, guest PC 0x0c040ab6 */
if(!s->budget--) { s->failed_pc=0x0c040ab6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040acc; }
goto P_0c040ab8;
P_0c040ab8: /* original a014, guest PC 0x0c040ab8 */
if(!s->budget--) { s->failed_pc=0x0c040ab8u; return 0; }
goto P_0c040ae4;
P_0c040aba: /* original 0009, guest PC 0x0c040aba */
if(!s->budget--) { s->failed_pc=0x0c040abau; return 0; }
if(!vf3_matrix_family(0x0c040abcu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040abcu; return 0; } return 1;
P_0c040acc: /* original 53f3, guest PC 0x0c040acc */
if(!s->budget--) { s->failed_pc=0x0c040accu; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c040ace;
P_0c040ace: /* original 7301, guest PC 0x0c040ace */
if(!s->budget--) { s->failed_pc=0x0c040aceu; return 0; }
r[3]+=0x00000001u;
goto P_0c040ad0;
P_0c040ad0: /* original 1f33, guest PC 0x0c040ad0 */
if(!s->budget--) { s->failed_pc=0x0c040ad0u; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c040ad2;
P_0c040ad2: /* original d211, guest PC 0x0c040ad2 */
if(!s->budget--) { s->failed_pc=0x0c040ad2u; return 0; }
r[2]=read(ram,0x0c040b18u,4);
goto P_0c040ad4;
P_0c040ad4: /* original 51f3, guest PC 0x0c040ad4 */
if(!s->budget--) { s->failed_pc=0x0c040ad4u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c040ad6;
P_0c040ad6: /* original 3123, guest PC 0x0c040ad6 */
if(!s->budget--) { s->failed_pc=0x0c040ad6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c040ad8;
P_0c040ad8: /* original 8bea, guest PC 0x0c040ad8 */
if(!s->budget--) { s->failed_pc=0x0c040ad8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040ab0; }
goto P_0c040ada;
P_0c040ada: /* original 901c, guest PC 0x0c040ada */
if(!s->budget--) { s->failed_pc=0x0c040adau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c040b16u,2);
goto P_0c040adc;
P_0c040adc: /* original 7f18, guest PC 0x0c040adc */
if(!s->budget--) { s->failed_pc=0x0c040adcu; return 0; }
r[15]+=0x00000018u;
goto P_0c040ade;
P_0c040ade: /* original 4f26, guest PC 0x0c040ade */
if(!s->budget--) { s->failed_pc=0x0c040adeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040ae0;
P_0c040ae0: /* original 000b, guest PC 0x0c040ae0 */
if(!s->budget--) { s->failed_pc=0x0c040ae0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040ae2: /* original 0009, guest PC 0x0c040ae2 */
if(!s->budget--) { s->failed_pc=0x0c040ae2u; return 0; }
goto P_0c040ae4;
P_0c040ae4: /* original e200, guest PC 0x0c040ae4 */
if(!s->budget--) { s->failed_pc=0x0c040ae4u; return 0; }
r[2]=0x00000000u;
goto P_0c040ae6;
P_0c040ae6: /* original d30d, guest PC 0x0c040ae6 */
if(!s->budget--) { s->failed_pc=0x0c040ae6u; return 0; }
r[3]=read(ram,0x0c040b1cu,4);
goto P_0c040ae8;
P_0c040ae8: /* original 2322, guest PC 0x0c040ae8 */
if(!s->budget--) { s->failed_pc=0x0c040ae8u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040aea;
P_0c040aea: /* original e000, guest PC 0x0c040aea */
if(!s->budget--) { s->failed_pc=0x0c040aeau; return 0; }
r[0]=0x00000000u;
goto P_0c040aec;
P_0c040aec: /* original 7f18, guest PC 0x0c040aec */
if(!s->budget--) { s->failed_pc=0x0c040aecu; return 0; }
r[15]+=0x00000018u;
goto P_0c040aee;
P_0c040aee: /* original 4f26, guest PC 0x0c040aee */
if(!s->budget--) { s->failed_pc=0x0c040aeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c040af0;
P_0c040af0: /* original 000b, guest PC 0x0c040af0 */
if(!s->budget--) { s->failed_pc=0x0c040af0u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040af2: /* original 0009, guest PC 0x0c040af2 */
if(!s->budget--) { s->failed_pc=0x0c040af2u; return 0; }
if(!vf3_matrix_family(0x0c040af4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040af4u; return 0; } return 1;
P_0c040f1e: /* original 7ffc, guest PC 0x0c040f1e */
if(!s->budget--) { s->failed_pc=0x0c040f1eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c040f20;
P_0c040f20: /* original 2f42, guest PC 0x0c040f20 */
if(!s->budget--) { s->failed_pc=0x0c040f20u; return 0; }
write(ram,r[15],r[4],4);
goto P_0c040f22;
P_0c040f22: /* original 60f2, guest PC 0x0c040f22 */
if(!s->budget--) { s->failed_pc=0x0c040f22u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c040f24;
P_0c040f24: /* original c880, guest PC 0x0c040f24 */
if(!s->budget--) { s->failed_pc=0x0c040f24u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c040f26;
P_0c040f26: /* original 8b03, guest PC 0x0c040f26 */
if(!s->budget--) { s->failed_pc=0x0c040f26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f30; }
goto P_0c040f28;
P_0c040f28: /* original e0fe, guest PC 0x0c040f28 */
if(!s->budget--) { s->failed_pc=0x0c040f28u; return 0; }
r[0]=0xfffffffeu;
goto P_0c040f2a;
P_0c040f2a: /* original 7f04, guest PC 0x0c040f2a */
if(!s->budget--) { s->failed_pc=0x0c040f2au; return 0; }
r[15]+=0x00000004u;
goto P_0c040f2c;
P_0c040f2c: /* original 000b, guest PC 0x0c040f2c */
if(!s->budget--) { s->failed_pc=0x0c040f2cu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f2e: /* original 0009, guest PC 0x0c040f2e */
if(!s->budget--) { s->failed_pc=0x0c040f2eu; return 0; }
goto P_0c040f30;
P_0c040f30: /* original d30d, guest PC 0x0c040f30 */
if(!s->budget--) { s->failed_pc=0x0c040f30u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f32;
P_0c040f32: /* original 6232, guest PC 0x0c040f32 */
if(!s->budget--) { s->failed_pc=0x0c040f32u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f34;
P_0c040f34: /* original 6122, guest PC 0x0c040f34 */
if(!s->budget--) { s->failed_pc=0x0c040f34u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c040f36;
P_0c040f36: /* original 2118, guest PC 0x0c040f36 */
if(!s->budget--) { s->failed_pc=0x0c040f36u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c040f38;
P_0c040f38: /* original 8903, guest PC 0x0c040f38 */
if(!s->budget--) { s->failed_pc=0x0c040f38u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c040f42; }
goto P_0c040f3a;
P_0c040f3a: /* original e0ff, guest PC 0x0c040f3a */
if(!s->budget--) { s->failed_pc=0x0c040f3au; return 0; }
r[0]=0xffffffffu;
goto P_0c040f3c;
P_0c040f3c: /* original 7f04, guest PC 0x0c040f3c */
if(!s->budget--) { s->failed_pc=0x0c040f3cu; return 0; }
r[15]+=0x00000004u;
goto P_0c040f3e;
P_0c040f3e: /* original 000b, guest PC 0x0c040f3e */
if(!s->budget--) { s->failed_pc=0x0c040f3eu; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f40: /* original 0009, guest PC 0x0c040f40 */
if(!s->budget--) { s->failed_pc=0x0c040f40u; return 0; }
goto P_0c040f42;
P_0c040f42: /* original d309, guest PC 0x0c040f42 */
if(!s->budget--) { s->failed_pc=0x0c040f42u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f44;
P_0c040f44: /* original 6232, guest PC 0x0c040f44 */
if(!s->budget--) { s->failed_pc=0x0c040f44u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c040f46;
P_0c040f46: /* original 7204, guest PC 0x0c040f46 */
if(!s->budget--) { s->failed_pc=0x0c040f46u; return 0; }
r[2]+=0x00000004u;
goto P_0c040f48;
P_0c040f48: /* original 2322, guest PC 0x0c040f48 */
if(!s->budget--) { s->failed_pc=0x0c040f48u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c040f4a;
P_0c040f4a: /* original 72fc, guest PC 0x0c040f4a */
if(!s->budget--) { s->failed_pc=0x0c040f4au; return 0; }
r[2]+=0xfffffffcu;
goto P_0c040f4c;
P_0c040f4c: /* original 63f2, guest PC 0x0c040f4c */
if(!s->budget--) { s->failed_pc=0x0c040f4cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c040f4e;
P_0c040f4e: /* original 2232, guest PC 0x0c040f4e */
if(!s->budget--) { s->failed_pc=0x0c040f4eu; return 0; }
write(ram,r[2],r[3],4);
goto P_0c040f50;
P_0c040f50: /* original d206, guest PC 0x0c040f50 */
if(!s->budget--) { s->failed_pc=0x0c040f50u; return 0; }
r[2]=read(ram,0x0c040f6cu,4);
goto P_0c040f52;
P_0c040f52: /* original d305, guest PC 0x0c040f52 */
if(!s->budget--) { s->failed_pc=0x0c040f52u; return 0; }
r[3]=read(ram,0x0c040f68u,4);
goto P_0c040f54;
P_0c040f54: /* original 6132, guest PC 0x0c040f54 */
if(!s->budget--) { s->failed_pc=0x0c040f54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c040f56;
P_0c040f56: /* original 3120, guest PC 0x0c040f56 */
if(!s->budget--) { s->failed_pc=0x0c040f56u; return 0; }
r[17]=(r[17]&~1u)|((r[1]==r[2])!=0);
goto P_0c040f58;
P_0c040f58: /* original 8b02, guest PC 0x0c040f58 */
if(!s->budget--) { s->failed_pc=0x0c040f58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c040f60; }
goto P_0c040f5a;
P_0c040f5a: /* original d305, guest PC 0x0c040f5a */
if(!s->budget--) { s->failed_pc=0x0c040f5au; return 0; }
r[3]=read(ram,0x0c040f70u,4);
goto P_0c040f5c;
P_0c040f5c: /* original d002, guest PC 0x0c040f5c */
if(!s->budget--) { s->failed_pc=0x0c040f5cu; return 0; }
r[0]=read(ram,0x0c040f68u,4);
goto P_0c040f5e;
P_0c040f5e: /* original 2032, guest PC 0x0c040f5e */
if(!s->budget--) { s->failed_pc=0x0c040f5eu; return 0; }
write(ram,r[0],r[3],4);
goto P_0c040f60;
P_0c040f60: /* original e000, guest PC 0x0c040f60 */
if(!s->budget--) { s->failed_pc=0x0c040f60u; return 0; }
r[0]=0x00000000u;
goto P_0c040f62;
P_0c040f62: /* original 7f04, guest PC 0x0c040f62 */
if(!s->budget--) { s->failed_pc=0x0c040f62u; return 0; }
r[15]+=0x00000004u;
goto P_0c040f64;
P_0c040f64: /* original 000b, guest PC 0x0c040f64 */
if(!s->budget--) { s->failed_pc=0x0c040f64u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c040f66: /* original 0009, guest PC 0x0c040f66 */
if(!s->budget--) { s->failed_pc=0x0c040f66u; return 0; }
if(!vf3_matrix_family(0x0c040f68u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c040f68u; return 0; } return 1;
P_0c046314: /* original 000b, guest PC 0x0c046314 */
if(!s->budget--) { s->failed_pc=0x0c046314u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c046316: /* original 0009, guest PC 0x0c046316 */
if(!s->budget--) { s->failed_pc=0x0c046316u; return 0; }
if(!vf3_matrix_family(0x0c046318u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c046318u; return 0; } return 1;
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
