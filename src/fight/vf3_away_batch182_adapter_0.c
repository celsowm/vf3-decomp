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
int vf3_away_batch182_adapter_0(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c09af6cu: goto P_0c09af6c;
case 0x0c09af6eu: goto P_0c09af6e;
case 0x0c09af70u: goto P_0c09af70;
case 0x0c09af72u: goto P_0c09af72;
case 0x0c09af74u: goto P_0c09af74;
case 0x0c09af76u: goto P_0c09af76;
case 0x0c09af78u: goto P_0c09af78;
case 0x0c09af7au: goto P_0c09af7a;
case 0x0c09af7cu: goto P_0c09af7c;
case 0x0c09af7eu: goto P_0c09af7e;
case 0x0c09af80u: goto P_0c09af80;
case 0x0c09af82u: goto P_0c09af82;
case 0x0c09af84u: goto P_0c09af84;
case 0x0c09af86u: goto P_0c09af86;
case 0x0c09af88u: goto P_0c09af88;
case 0x0c09af8au: goto P_0c09af8a;
case 0x0c09af8cu: goto P_0c09af8c;
case 0x0c09af8eu: goto P_0c09af8e;
case 0x0c09af90u: goto P_0c09af90;
case 0x0c09af92u: goto P_0c09af92;
case 0x0c09af94u: goto P_0c09af94;
case 0x0c09af96u: goto P_0c09af96;
case 0x0c09af98u: goto P_0c09af98;
case 0x0c09af9au: goto P_0c09af9a;
case 0x0c09af9cu: goto P_0c09af9c;
case 0x0c09af9eu: goto P_0c09af9e;
case 0x0c09afa0u: goto P_0c09afa0;
case 0x0c09afa2u: goto P_0c09afa2;
case 0x0c09afa4u: goto P_0c09afa4;
case 0x0c09afa6u: goto P_0c09afa6;
case 0x0c09afa8u: goto P_0c09afa8;
case 0x0c09afaau: goto P_0c09afaa;
case 0x0c09afacu: goto P_0c09afac;
case 0x0c09afaeu: goto P_0c09afae;
case 0x0c09afb0u: goto P_0c09afb0;
case 0x0c09afb2u: goto P_0c09afb2;
case 0x0c09afb4u: goto P_0c09afb4;
case 0x0c09afb6u: goto P_0c09afb6;
case 0x0c09afb8u: goto P_0c09afb8;
case 0x0c09afbau: goto P_0c09afba;
case 0x0c09afbcu: goto P_0c09afbc;
case 0x0c09afbeu: goto P_0c09afbe;
case 0x0c09afc0u: goto P_0c09afc0;
case 0x0c09afc2u: goto P_0c09afc2;
case 0x0c09afc4u: goto P_0c09afc4;
case 0x0c09afc6u: goto P_0c09afc6;
case 0x0c09afc8u: goto P_0c09afc8;
case 0x0c09afcau: goto P_0c09afca;
case 0x0c09afccu: goto P_0c09afcc;
case 0x0c09afceu: goto P_0c09afce;
case 0x0c09afd0u: goto P_0c09afd0;
case 0x0c09afd2u: goto P_0c09afd2;
case 0x0c09afd4u: goto P_0c09afd4;
case 0x0c09afd6u: goto P_0c09afd6;
case 0x0c09afd8u: goto P_0c09afd8;
case 0x0c09afdau: goto P_0c09afda;
case 0x0c09afdcu: goto P_0c09afdc;
case 0x0c09afdeu: goto P_0c09afde;
case 0x0c09afe0u: goto P_0c09afe0;
case 0x0c09afe2u: goto P_0c09afe2;
case 0x0c09afe4u: goto P_0c09afe4;
case 0x0c09afe6u: goto P_0c09afe6;
case 0x0c09afe8u: goto P_0c09afe8;
case 0x0c09afeau: goto P_0c09afea;
case 0x0c09afecu: goto P_0c09afec;
case 0x0c09afeeu: goto P_0c09afee;
case 0x0c09aff0u: goto P_0c09aff0;
case 0x0c09aff2u: goto P_0c09aff2;
case 0x0c09aff4u: goto P_0c09aff4;
case 0x0c09aff6u: goto P_0c09aff6;
case 0x0c09aff8u: goto P_0c09aff8;
case 0x0c09affau: goto P_0c09affa;
case 0x0c09affcu: goto P_0c09affc;
case 0x0c09affeu: goto P_0c09affe;
case 0x0c09b000u: goto P_0c09b000;
case 0x0c09b002u: goto P_0c09b002;
case 0x0c09b004u: goto P_0c09b004;
case 0x0c09b040u: goto P_0c09b040;
case 0x0c09b042u: goto P_0c09b042;
case 0x0c09b044u: goto P_0c09b044;
case 0x0c09b046u: goto P_0c09b046;
case 0x0c09b048u: goto P_0c09b048;
case 0x0c09b04au: goto P_0c09b04a;
case 0x0c09b04cu: goto P_0c09b04c;
case 0x0c09b04eu: goto P_0c09b04e;
case 0x0c09b050u: goto P_0c09b050;
case 0x0c09b052u: goto P_0c09b052;
case 0x0c09b054u: goto P_0c09b054;
case 0x0c09b056u: goto P_0c09b056;
case 0x0c09b058u: goto P_0c09b058;
case 0x0c09b05au: goto P_0c09b05a;
case 0x0c09b05cu: goto P_0c09b05c;
case 0x0c09b05eu: goto P_0c09b05e;
case 0x0c09b060u: goto P_0c09b060;
case 0x0c09b062u: goto P_0c09b062;
case 0x0c09b064u: goto P_0c09b064;
case 0x0c09b066u: goto P_0c09b066;
case 0x0c09b068u: goto P_0c09b068;
case 0x0c09b06au: goto P_0c09b06a;
case 0x0c09b06cu: goto P_0c09b06c;
case 0x0c09b06eu: goto P_0c09b06e;
case 0x0c09b070u: goto P_0c09b070;
case 0x0c09b072u: goto P_0c09b072;
case 0x0c09b074u: goto P_0c09b074;
case 0x0c09b076u: goto P_0c09b076;
case 0x0c09b078u: goto P_0c09b078;
case 0x0c09b07au: goto P_0c09b07a;
case 0x0c09b07cu: goto P_0c09b07c;
case 0x0c09b07eu: goto P_0c09b07e;
case 0x0c09b080u: goto P_0c09b080;
case 0x0c09b082u: goto P_0c09b082;
case 0x0c09b084u: goto P_0c09b084;
case 0x0c09b086u: goto P_0c09b086;
case 0x0c09b088u: goto P_0c09b088;
case 0x0c09b08au: goto P_0c09b08a;
case 0x0c09b08cu: goto P_0c09b08c;
case 0x0c09b08eu: goto P_0c09b08e;
case 0x0c09b090u: goto P_0c09b090;
case 0x0c09b092u: goto P_0c09b092;
case 0x0c09b094u: goto P_0c09b094;
case 0x0c09b096u: goto P_0c09b096;
case 0x0c09b098u: goto P_0c09b098;
case 0x0c09b09au: goto P_0c09b09a;
case 0x0c09b09cu: goto P_0c09b09c;
case 0x0c09b09eu: goto P_0c09b09e;
case 0x0c09b0a0u: goto P_0c09b0a0;
case 0x0c09b0a2u: goto P_0c09b0a2;
case 0x0c09b0a4u: goto P_0c09b0a4;
case 0x0c09b0a6u: goto P_0c09b0a6;
case 0x0c09b0a8u: goto P_0c09b0a8;
case 0x0c09b0aau: goto P_0c09b0aa;
case 0x0c09b0acu: goto P_0c09b0ac;
case 0x0c09b0aeu: goto P_0c09b0ae;
case 0x0c09b0b0u: goto P_0c09b0b0;
case 0x0c09b0b2u: goto P_0c09b0b2;
case 0x0c09b0b4u: goto P_0c09b0b4;
case 0x0c09b0b6u: goto P_0c09b0b6;
case 0x0c09b0b8u: goto P_0c09b0b8;
case 0x0c09b0bau: goto P_0c09b0ba;
case 0x0c09b0bcu: goto P_0c09b0bc;
case 0x0c09b0beu: goto P_0c09b0be;
case 0x0c09b0c0u: goto P_0c09b0c0;
case 0x0c09b0c2u: goto P_0c09b0c2;
case 0x0c09b0c4u: goto P_0c09b0c4;
case 0x0c09b0c6u: goto P_0c09b0c6;
case 0x0c09b0c8u: goto P_0c09b0c8;
case 0x0c09b0cau: goto P_0c09b0ca;
case 0x0c09b0ccu: goto P_0c09b0cc;
case 0x0c09b0ceu: goto P_0c09b0ce;
case 0x0c09b0d0u: goto P_0c09b0d0;
case 0x0c09b0d2u: goto P_0c09b0d2;
case 0x0c09b0d4u: goto P_0c09b0d4;
case 0x0c09b0d6u: goto P_0c09b0d6;
case 0x0c09b0d8u: goto P_0c09b0d8;
case 0x0c09b0dau: goto P_0c09b0da;
case 0x0c09b0dcu: goto P_0c09b0dc;
case 0x0c09b0deu: goto P_0c09b0de;
case 0x0c09b0e0u: goto P_0c09b0e0;
case 0x0c09b0e2u: goto P_0c09b0e2;
case 0x0c09b0e4u: goto P_0c09b0e4;
case 0x0c09b0e6u: goto P_0c09b0e6;
case 0x0c09b0e8u: goto P_0c09b0e8;
case 0x0c09b0eau: goto P_0c09b0ea;
case 0x0c09b0ecu: goto P_0c09b0ec;
case 0x0c09b0eeu: goto P_0c09b0ee;
case 0x0c09b0f0u: goto P_0c09b0f0;
case 0x0c09b0f2u: goto P_0c09b0f2;
case 0x0c09b0f4u: goto P_0c09b0f4;
case 0x0c09b0f6u: goto P_0c09b0f6;
case 0x0c09b0f8u: goto P_0c09b0f8;
case 0x0c09b0fau: goto P_0c09b0fa;
case 0x0c09b0fcu: goto P_0c09b0fc;
case 0x0c09b0feu: goto P_0c09b0fe;
case 0x0c09b100u: goto P_0c09b100;
case 0x0c09b102u: goto P_0c09b102;
case 0x0c09b104u: goto P_0c09b104;
case 0x0c09b106u: goto P_0c09b106;
case 0x0c09b108u: goto P_0c09b108;
case 0x0c09b10au: goto P_0c09b10a;
case 0x0c09b10cu: goto P_0c09b10c;
case 0x0c09b10eu: goto P_0c09b10e;
case 0x0c09b110u: goto P_0c09b110;
case 0x0c09b112u: goto P_0c09b112;
case 0x0c09b114u: goto P_0c09b114;
case 0x0c09b116u: goto P_0c09b116;
case 0x0c09b118u: goto P_0c09b118;
case 0x0c09b138u: goto P_0c09b138;
case 0x0c09b13au: goto P_0c09b13a;
case 0x0c09b13cu: goto P_0c09b13c;
case 0x0c09b13eu: goto P_0c09b13e;
case 0x0c09b140u: goto P_0c09b140;
case 0x0c09b142u: goto P_0c09b142;
case 0x0c09b144u: goto P_0c09b144;
case 0x0c09b146u: goto P_0c09b146;
case 0x0c09b148u: goto P_0c09b148;
case 0x0c09b14au: goto P_0c09b14a;
case 0x0c09b14cu: goto P_0c09b14c;
case 0x0c09b14eu: goto P_0c09b14e;
case 0x0c09b150u: goto P_0c09b150;
case 0x0c09b152u: goto P_0c09b152;
case 0x0c09b154u: goto P_0c09b154;
case 0x0c09b156u: goto P_0c09b156;
case 0x0c09b158u: goto P_0c09b158;
case 0x0c09b15au: goto P_0c09b15a;
case 0x0c09b15cu: goto P_0c09b15c;
case 0x0c09b15eu: goto P_0c09b15e;
case 0x0c09b160u: goto P_0c09b160;
case 0x0c09b162u: goto P_0c09b162;
case 0x0c09b164u: goto P_0c09b164;
case 0x0c09b166u: goto P_0c09b166;
case 0x0c09b168u: goto P_0c09b168;
case 0x0c09b16au: goto P_0c09b16a;
case 0x0c09b16cu: goto P_0c09b16c;
case 0x0c09b16eu: goto P_0c09b16e;
case 0x0c09b170u: goto P_0c09b170;
case 0x0c09b172u: goto P_0c09b172;
case 0x0c09b174u: goto P_0c09b174;
case 0x0c09b176u: goto P_0c09b176;
case 0x0c09b178u: goto P_0c09b178;
case 0x0c09b17au: goto P_0c09b17a;
case 0x0c09b17cu: goto P_0c09b17c;
case 0x0c09b17eu: goto P_0c09b17e;
case 0x0c09b180u: goto P_0c09b180;
case 0x0c09b182u: goto P_0c09b182;
case 0x0c09b184u: goto P_0c09b184;
case 0x0c09b186u: goto P_0c09b186;
case 0x0c09b188u: goto P_0c09b188;
case 0x0c09b18au: goto P_0c09b18a;
case 0x0c09b18cu: goto P_0c09b18c;
case 0x0c09b18eu: goto P_0c09b18e;
case 0x0c09b190u: goto P_0c09b190;
case 0x0c09b192u: goto P_0c09b192;
case 0x0c09b194u: goto P_0c09b194;
case 0x0c09b196u: goto P_0c09b196;
case 0x0c09b198u: goto P_0c09b198;
case 0x0c09b19au: goto P_0c09b19a;
case 0x0c09b19cu: goto P_0c09b19c;
case 0x0c09b19eu: goto P_0c09b19e;
case 0x0c09b1a0u: goto P_0c09b1a0;
case 0x0c09b1a2u: goto P_0c09b1a2;
case 0x0c09b1a4u: goto P_0c09b1a4;
case 0x0c09b1a6u: goto P_0c09b1a6;
case 0x0c09b1a8u: goto P_0c09b1a8;
case 0x0c09b1aau: goto P_0c09b1aa;
case 0x0c09b1acu: goto P_0c09b1ac;
case 0x0c09b1aeu: goto P_0c09b1ae;
case 0x0c09b1b0u: goto P_0c09b1b0;
case 0x0c09b1b2u: goto P_0c09b1b2;
case 0x0c09b1b4u: goto P_0c09b1b4;
case 0x0c09b1b6u: goto P_0c09b1b6;
case 0x0c09b1b8u: goto P_0c09b1b8;
case 0x0c09b1bau: goto P_0c09b1ba;
case 0x0c09b1bcu: goto P_0c09b1bc;
case 0x0c09b1beu: goto P_0c09b1be;
case 0x0c09b1c0u: goto P_0c09b1c0;
case 0x0c09b1c2u: goto P_0c09b1c2;
case 0x0c09b1c4u: goto P_0c09b1c4;
case 0x0c09b1c6u: goto P_0c09b1c6;
case 0x0c09b1c8u: goto P_0c09b1c8;
case 0x0c09b1cau: goto P_0c09b1ca;
case 0x0c09b1ccu: goto P_0c09b1cc;
case 0x0c09b1ceu: goto P_0c09b1ce;
case 0x0c09b1d0u: goto P_0c09b1d0;
case 0x0c09b1d2u: goto P_0c09b1d2;
case 0x0c09b1d4u: goto P_0c09b1d4;
case 0x0c09b1d6u: goto P_0c09b1d6;
case 0x0c09b1d8u: goto P_0c09b1d8;
case 0x0c09b1dau: goto P_0c09b1da;
case 0x0c09b1dcu: goto P_0c09b1dc;
case 0x0c09b1deu: goto P_0c09b1de;
case 0x0c09b1e0u: goto P_0c09b1e0;
case 0x0c09b1e2u: goto P_0c09b1e2;
case 0x0c09b1e4u: goto P_0c09b1e4;
case 0x0c09b1e6u: goto P_0c09b1e6;
case 0x0c09b1e8u: goto P_0c09b1e8;
case 0x0c09b1eau: goto P_0c09b1ea;
case 0x0c09b1ecu: goto P_0c09b1ec;
case 0x0c09b1eeu: goto P_0c09b1ee;
case 0x0c09b1f0u: goto P_0c09b1f0;
case 0x0c09b1f2u: goto P_0c09b1f2;
case 0x0c09b218u: goto P_0c09b218;
case 0x0c09b21au: goto P_0c09b21a;
case 0x0c09b21cu: goto P_0c09b21c;
case 0x0c09b21eu: goto P_0c09b21e;
case 0x0c09b220u: goto P_0c09b220;
case 0x0c09b222u: goto P_0c09b222;
case 0x0c09b224u: goto P_0c09b224;
case 0x0c09b226u: goto P_0c09b226;
case 0x0c09b228u: goto P_0c09b228;
case 0x0c09b22au: goto P_0c09b22a;
case 0x0c09b22cu: goto P_0c09b22c;
case 0x0c09b22eu: goto P_0c09b22e;
case 0x0c09b230u: goto P_0c09b230;
case 0x0c09b232u: goto P_0c09b232;
case 0x0c09b234u: goto P_0c09b234;
case 0x0c09b236u: goto P_0c09b236;
case 0x0c09b238u: goto P_0c09b238;
case 0x0c09b23au: goto P_0c09b23a;
case 0x0c09b23cu: goto P_0c09b23c;
case 0x0c09b23eu: goto P_0c09b23e;
case 0x0c09b240u: goto P_0c09b240;
case 0x0c09b242u: goto P_0c09b242;
case 0x0c09b244u: goto P_0c09b244;
case 0x0c09b246u: goto P_0c09b246;
case 0x0c09b248u: goto P_0c09b248;
case 0x0c09b24au: goto P_0c09b24a;
case 0x0c09b24cu: goto P_0c09b24c;
case 0x0c09b24eu: goto P_0c09b24e;
case 0x0c09b250u: goto P_0c09b250;
case 0x0c09b252u: goto P_0c09b252;
case 0x0c09b254u: goto P_0c09b254;
case 0x0c09b256u: goto P_0c09b256;
case 0x0c09b258u: goto P_0c09b258;
case 0x0c09b25au: goto P_0c09b25a;
case 0x0c09b25cu: goto P_0c09b25c;
case 0x0c09b25eu: goto P_0c09b25e;
case 0x0c09b260u: goto P_0c09b260;
case 0x0c09b262u: goto P_0c09b262;
case 0x0c09b264u: goto P_0c09b264;
case 0x0c09b266u: goto P_0c09b266;
case 0x0c09b268u: goto P_0c09b268;
case 0x0c09b26au: goto P_0c09b26a;
case 0x0c09b26cu: goto P_0c09b26c;
case 0x0c09b26eu: goto P_0c09b26e;
case 0x0c09b270u: goto P_0c09b270;
case 0x0c09b272u: goto P_0c09b272;
case 0x0c09b274u: goto P_0c09b274;
case 0x0c09b276u: goto P_0c09b276;
case 0x0c09b278u: goto P_0c09b278;
case 0x0c09b27au: goto P_0c09b27a;
case 0x0c09b27cu: goto P_0c09b27c;
case 0x0c09b27eu: goto P_0c09b27e;
case 0x0c09b280u: goto P_0c09b280;
case 0x0c09b282u: goto P_0c09b282;
case 0x0c09b284u: goto P_0c09b284;
case 0x0c09b286u: goto P_0c09b286;
case 0x0c09b288u: goto P_0c09b288;
case 0x0c09b28au: goto P_0c09b28a;
case 0x0c09b28cu: goto P_0c09b28c;
case 0x0c09b28eu: goto P_0c09b28e;
case 0x0c09b290u: goto P_0c09b290;
case 0x0c09b292u: goto P_0c09b292;
case 0x0c09b294u: goto P_0c09b294;
case 0x0c09b296u: goto P_0c09b296;
default: return vf3_matrix_family(target,s,ram);
}
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
P_0c09af6c: /* original 2fe6, guest PC 0x0c09af6c */
if(!s->budget--) { s->failed_pc=0x0c09af6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af6e;
P_0c09af6e: /* original 2fd6, guest PC 0x0c09af6e */
if(!s->budget--) { s->failed_pc=0x0c09af6eu; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af70;
P_0c09af70: /* original 2fc6, guest PC 0x0c09af70 */
if(!s->budget--) { s->failed_pc=0x0c09af70u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09af72;
P_0c09af72: /* original 4f22, guest PC 0x0c09af72 */
if(!s->budget--) { s->failed_pc=0x0c09af72u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09af74;
P_0c09af74: /* original d32c, guest PC 0x0c09af74 */
if(!s->budget--) { s->failed_pc=0x0c09af74u; return 0; }
r[3]=read(ram,0x0c09b028u,4);
goto P_0c09af76;
P_0c09af76: /* original 7ffc, guest PC 0x0c09af76 */
if(!s->budget--) { s->failed_pc=0x0c09af76u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09af78;
P_0c09af78: /* original 2f32, guest PC 0x0c09af78 */
if(!s->budget--) { s->failed_pc=0x0c09af78u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09af7a;
P_0c09af7a: /* original dc2c, guest PC 0x0c09af7a */
if(!s->budget--) { s->failed_pc=0x0c09af7au; return 0; }
r[12]=read(ram,0x0c09b02cu,4);
goto P_0c09af7c;
P_0c09af7c: /* original dd2c, guest PC 0x0c09af7c */
if(!s->budget--) { s->failed_pc=0x0c09af7cu; return 0; }
r[13]=read(ram,0x0c09b030u,4);
goto P_0c09af7e;
P_0c09af7e: /* original 4d0b, guest PC 0x0c09af7e */
if(!s->budget--) { s->failed_pc=0x0c09af7eu; return 0; }
target=r[13];
r[16]=code_base|0x0c09af82u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af82u) { target=s->pc; goto dispatch; }
goto P_0c09af82;
P_0c09af80: /* original e400, guest PC 0x0c09af80 */
if(!s->budget--) { s->failed_pc=0x0c09af80u; return 0; }
r[4]=0x00000000u;
goto P_0c09af82;
P_0c09af82: /* original 6403, guest PC 0x0c09af82 */
if(!s->budget--) { s->failed_pc=0x0c09af82u; return 0; }
r[4]=r[0];
goto P_0c09af84;
P_0c09af84: /* original 5e42, guest PC 0x0c09af84 */
if(!s->budget--) { s->failed_pc=0x0c09af84u; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09af86;
P_0c09af86: /* original 53c2, guest PC 0x0c09af86 */
if(!s->budget--) { s->failed_pc=0x0c09af86u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09af88;
P_0c09af88: /* original d42a, guest PC 0x0c09af88 */
if(!s->budget--) { s->failed_pc=0x0c09af88u; return 0; }
r[4]=read(ram,0x0c09b034u,4);
goto P_0c09af8a;
P_0c09af8a: /* original 2349, guest PC 0x0c09af8a */
if(!s->budget--) { s->failed_pc=0x0c09af8au; return 0; }
r[3]&=r[4];
goto P_0c09af8c;
P_0c09af8c: /* original 3340, guest PC 0x0c09af8c */
if(!s->budget--) { s->failed_pc=0x0c09af8cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c09af8e;
P_0c09af8e: /* original 8b05, guest PC 0x0c09af8e */
if(!s->budget--) { s->failed_pc=0x0c09af8eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09af9c; }
goto P_0c09af90;
P_0c09af90: /* original 4d0b, guest PC 0x0c09af90 */
if(!s->budget--) { s->failed_pc=0x0c09af90u; return 0; }
target=r[13];
r[16]=code_base|0x0c09af94u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09af94u) { target=s->pc; goto dispatch; }
goto P_0c09af94;
P_0c09af92: /* original e401, guest PC 0x0c09af92 */
if(!s->budget--) { s->failed_pc=0x0c09af92u; return 0; }
r[4]=0x00000001u;
goto P_0c09af94;
P_0c09af94: /* original 6403, guest PC 0x0c09af94 */
if(!s->budget--) { s->failed_pc=0x0c09af94u; return 0; }
r[4]=r[0];
goto P_0c09af96;
P_0c09af96: /* original 5342, guest PC 0x0c09af96 */
if(!s->budget--) { s->failed_pc=0x0c09af96u; return 0; }
r[3]=read(ram,r[4]+8,4);
goto P_0c09af98;
P_0c09af98: /* original a008, guest PC 0x0c09af98 */
if(!s->budget--) { s->failed_pc=0x0c09af98u; return 0; }
r[14]|=r[3];
goto P_0c09afac;
P_0c09af9a: /* original 2e3b, guest PC 0x0c09af9a */
if(!s->budget--) { s->failed_pc=0x0c09af9au; return 0; }
r[14]|=r[3];
goto P_0c09af9c;
P_0c09af9c: /* original 52c2, guest PC 0x0c09af9c */
if(!s->budget--) { s->failed_pc=0x0c09af9cu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09af9e;
P_0c09af9e: /* original d326, guest PC 0x0c09af9e */
if(!s->budget--) { s->failed_pc=0x0c09af9eu; return 0; }
r[3]=read(ram,0x0c09b038u,4);
goto P_0c09afa0;
P_0c09afa0: /* original 2238, guest PC 0x0c09afa0 */
if(!s->budget--) { s->failed_pc=0x0c09afa0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09afa2;
P_0c09afa2: /* original 8903, guest PC 0x0c09afa2 */
if(!s->budget--) { s->failed_pc=0x0c09afa2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09afac; }
goto P_0c09afa4;
P_0c09afa4: /* original 4d0b, guest PC 0x0c09afa4 */
if(!s->budget--) { s->failed_pc=0x0c09afa4u; return 0; }
target=r[13];
r[16]=code_base|0x0c09afa8u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09afa8u) { target=s->pc; goto dispatch; }
goto P_0c09afa8;
P_0c09afa6: /* original e401, guest PC 0x0c09afa6 */
if(!s->budget--) { s->failed_pc=0x0c09afa6u; return 0; }
r[4]=0x00000001u;
goto P_0c09afa8;
P_0c09afa8: /* original 6403, guest PC 0x0c09afa8 */
if(!s->budget--) { s->failed_pc=0x0c09afa8u; return 0; }
r[4]=r[0];
goto P_0c09afaa;
P_0c09afaa: /* original 5e42, guest PC 0x0c09afaa */
if(!s->budget--) { s->failed_pc=0x0c09afaau; return 0; }
r[14]=read(ram,r[4]+8,4);
goto P_0c09afac;
P_0c09afac: /* original 63f2, guest PC 0x0c09afac */
if(!s->budget--) { s->failed_pc=0x0c09afacu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09afae;
P_0c09afae: /* original 7f04, guest PC 0x0c09afae */
if(!s->budget--) { s->failed_pc=0x0c09afaeu; return 0; }
r[15]+=0x00000004u;
goto P_0c09afb0;
P_0c09afb0: /* original 4f26, guest PC 0x0c09afb0 */
if(!s->budget--) { s->failed_pc=0x0c09afb0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09afb2;
P_0c09afb2: /* original 9038, guest PC 0x0c09afb2 */
if(!s->budget--) { s->failed_pc=0x0c09afb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b026u,2);
goto P_0c09afb4;
P_0c09afb4: /* original 03e6, guest PC 0x0c09afb4 */
if(!s->budget--) { s->failed_pc=0x0c09afb4u; return 0; }
write(ram,r[3]+r[0],r[14],4);
goto P_0c09afb6;
P_0c09afb6: /* original 60e3, guest PC 0x0c09afb6 */
if(!s->budget--) { s->failed_pc=0x0c09afb6u; return 0; }
r[0]=r[14];
goto P_0c09afb8;
P_0c09afb8: /* original 6cf6, guest PC 0x0c09afb8 */
if(!s->budget--) { s->failed_pc=0x0c09afb8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09afba;
P_0c09afba: /* original 6df6, guest PC 0x0c09afba */
if(!s->budget--) { s->failed_pc=0x0c09afbau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09afbc;
P_0c09afbc: /* original 000b, guest PC 0x0c09afbc */
if(!s->budget--) { s->failed_pc=0x0c09afbcu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09afbe: /* original 6ef6, guest PC 0x0c09afbe */
if(!s->budget--) { s->failed_pc=0x0c09afbeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09afc0;
P_0c09afc0: /* original 2fe6, guest PC 0x0c09afc0 */
if(!s->budget--) { s->failed_pc=0x0c09afc0u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09afc2;
P_0c09afc2: /* original 2fd6, guest PC 0x0c09afc2 */
if(!s->budget--) { s->failed_pc=0x0c09afc2u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09afc4;
P_0c09afc4: /* original 2fc6, guest PC 0x0c09afc4 */
if(!s->budget--) { s->failed_pc=0x0c09afc4u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09afc6;
P_0c09afc6: /* original 4f22, guest PC 0x0c09afc6 */
if(!s->budget--) { s->failed_pc=0x0c09afc6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09afc8;
P_0c09afc8: /* original dd19, guest PC 0x0c09afc8 */
if(!s->budget--) { s->failed_pc=0x0c09afc8u; return 0; }
r[13]=read(ram,0x0c09b030u,4);
goto P_0c09afca;
P_0c09afca: /* original dc18, guest PC 0x0c09afca */
if(!s->budget--) { s->failed_pc=0x0c09afcau; return 0; }
r[12]=read(ram,0x0c09b02cu,4);
goto P_0c09afcc;
P_0c09afcc: /* original 4d0b, guest PC 0x0c09afcc */
if(!s->budget--) { s->failed_pc=0x0c09afccu; return 0; }
target=r[13];
r[16]=code_base|0x0c09afd0u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09afd0u) { target=s->pc; goto dispatch; }
goto P_0c09afd0;
P_0c09afce: /* original e400, guest PC 0x0c09afce */
if(!s->budget--) { s->failed_pc=0x0c09afceu; return 0; }
r[4]=0x00000000u;
goto P_0c09afd0;
P_0c09afd0: /* original 6403, guest PC 0x0c09afd0 */
if(!s->budget--) { s->failed_pc=0x0c09afd0u; return 0; }
r[4]=r[0];
goto P_0c09afd2;
P_0c09afd2: /* original 5e44, guest PC 0x0c09afd2 */
if(!s->budget--) { s->failed_pc=0x0c09afd2u; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c09afd4;
P_0c09afd4: /* original 53c2, guest PC 0x0c09afd4 */
if(!s->budget--) { s->failed_pc=0x0c09afd4u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09afd6;
P_0c09afd6: /* original d417, guest PC 0x0c09afd6 */
if(!s->budget--) { s->failed_pc=0x0c09afd6u; return 0; }
r[4]=read(ram,0x0c09b034u,4);
goto P_0c09afd8;
P_0c09afd8: /* original 2349, guest PC 0x0c09afd8 */
if(!s->budget--) { s->failed_pc=0x0c09afd8u; return 0; }
r[3]&=r[4];
goto P_0c09afda;
P_0c09afda: /* original 3340, guest PC 0x0c09afda */
if(!s->budget--) { s->failed_pc=0x0c09afdau; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[4])!=0);
goto P_0c09afdc;
P_0c09afdc: /* original 8b05, guest PC 0x0c09afdc */
if(!s->budget--) { s->failed_pc=0x0c09afdcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09afea; }
goto P_0c09afde;
P_0c09afde: /* original 4d0b, guest PC 0x0c09afde */
if(!s->budget--) { s->failed_pc=0x0c09afdeu; return 0; }
target=r[13];
r[16]=code_base|0x0c09afe2u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09afe2u) { target=s->pc; goto dispatch; }
goto P_0c09afe2;
P_0c09afe0: /* original e401, guest PC 0x0c09afe0 */
if(!s->budget--) { s->failed_pc=0x0c09afe0u; return 0; }
r[4]=0x00000001u;
goto P_0c09afe2;
P_0c09afe2: /* original 6403, guest PC 0x0c09afe2 */
if(!s->budget--) { s->failed_pc=0x0c09afe2u; return 0; }
r[4]=r[0];
goto P_0c09afe4;
P_0c09afe4: /* original 5344, guest PC 0x0c09afe4 */
if(!s->budget--) { s->failed_pc=0x0c09afe4u; return 0; }
r[3]=read(ram,r[4]+16,4);
goto P_0c09afe6;
P_0c09afe6: /* original a008, guest PC 0x0c09afe6 */
if(!s->budget--) { s->failed_pc=0x0c09afe6u; return 0; }
r[14]|=r[3];
goto P_0c09affa;
P_0c09afe8: /* original 2e3b, guest PC 0x0c09afe8 */
if(!s->budget--) { s->failed_pc=0x0c09afe8u; return 0; }
r[14]|=r[3];
goto P_0c09afea;
P_0c09afea: /* original 52c2, guest PC 0x0c09afea */
if(!s->budget--) { s->failed_pc=0x0c09afeau; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09afec;
P_0c09afec: /* original d312, guest PC 0x0c09afec */
if(!s->budget--) { s->failed_pc=0x0c09afecu; return 0; }
r[3]=read(ram,0x0c09b038u,4);
goto P_0c09afee;
P_0c09afee: /* original 2238, guest PC 0x0c09afee */
if(!s->budget--) { s->failed_pc=0x0c09afeeu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c09aff0;
P_0c09aff0: /* original 8903, guest PC 0x0c09aff0 */
if(!s->budget--) { s->failed_pc=0x0c09aff0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09affa; }
goto P_0c09aff2;
P_0c09aff2: /* original 4d0b, guest PC 0x0c09aff2 */
if(!s->budget--) { s->failed_pc=0x0c09aff2u; return 0; }
target=r[13];
r[16]=code_base|0x0c09aff6u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09aff6u) { target=s->pc; goto dispatch; }
goto P_0c09aff6;
P_0c09aff4: /* original e401, guest PC 0x0c09aff4 */
if(!s->budget--) { s->failed_pc=0x0c09aff4u; return 0; }
r[4]=0x00000001u;
goto P_0c09aff6;
P_0c09aff6: /* original 6403, guest PC 0x0c09aff6 */
if(!s->budget--) { s->failed_pc=0x0c09aff6u; return 0; }
r[4]=r[0];
goto P_0c09aff8;
P_0c09aff8: /* original 5e44, guest PC 0x0c09aff8 */
if(!s->budget--) { s->failed_pc=0x0c09aff8u; return 0; }
r[14]=read(ram,r[4]+16,4);
goto P_0c09affa;
P_0c09affa: /* original 4f26, guest PC 0x0c09affa */
if(!s->budget--) { s->failed_pc=0x0c09affau; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09affc;
P_0c09affc: /* original 60e3, guest PC 0x0c09affc */
if(!s->budget--) { s->failed_pc=0x0c09affcu; return 0; }
r[0]=r[14];
goto P_0c09affe;
P_0c09affe: /* original 6cf6, guest PC 0x0c09affe */
if(!s->budget--) { s->failed_pc=0x0c09affeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b000;
P_0c09b000: /* original 6df6, guest PC 0x0c09b000 */
if(!s->budget--) { s->failed_pc=0x0c09b000u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b002;
P_0c09b002: /* original 000b, guest PC 0x0c09b002 */
if(!s->budget--) { s->failed_pc=0x0c09b002u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09b004: /* original 6ef6, guest PC 0x0c09b004 */
if(!s->budget--) { s->failed_pc=0x0c09b004u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c09b006u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b006u; return 0; } return 1;
P_0c09b040: /* original 2fe6, guest PC 0x0c09b040 */
if(!s->budget--) { s->failed_pc=0x0c09b040u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b042;
P_0c09b042: /* original 2fd6, guest PC 0x0c09b042 */
if(!s->budget--) { s->failed_pc=0x0c09b042u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b044;
P_0c09b044: /* original 2fc6, guest PC 0x0c09b044 */
if(!s->budget--) { s->failed_pc=0x0c09b044u; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b046;
P_0c09b046: /* original 2fb6, guest PC 0x0c09b046 */
if(!s->budget--) { s->failed_pc=0x0c09b046u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b048;
P_0c09b048: /* original 2fa6, guest PC 0x0c09b048 */
if(!s->budget--) { s->failed_pc=0x0c09b048u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b04a;
P_0c09b04a: /* original 2f96, guest PC 0x0c09b04a */
if(!s->budget--) { s->failed_pc=0x0c09b04au; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b04c;
P_0c09b04c: /* original 2f86, guest PC 0x0c09b04c */
if(!s->budget--) { s->failed_pc=0x0c09b04cu; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c09b04e;
P_0c09b04e: /* original 4f22, guest PC 0x0c09b04e */
if(!s->budget--) { s->failed_pc=0x0c09b04eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b050;
P_0c09b050: /* original dc35, guest PC 0x0c09b050 */
if(!s->budget--) { s->failed_pc=0x0c09b050u; return 0; }
r[12]=read(ram,0x0c09b128u,4);
goto P_0c09b052;
P_0c09b052: /* original de34, guest PC 0x0c09b052 */
if(!s->budget--) { s->failed_pc=0x0c09b052u; return 0; }
r[14]=read(ram,0x0c09b124u,4);
goto P_0c09b054;
P_0c09b054: /* original da35, guest PC 0x0c09b054 */
if(!s->budget--) { s->failed_pc=0x0c09b054u; return 0; }
r[10]=read(ram,0x0c09b12cu,4);
goto P_0c09b056;
P_0c09b056: /* original 7ff8, guest PC 0x0c09b056 */
if(!s->budget--) { s->failed_pc=0x0c09b056u; return 0; }
r[15]+=0xfffffff8u;
goto P_0c09b058;
P_0c09b058: /* original bf88, guest PC 0x0c09b058 */
if(!s->budget--) { s->failed_pc=0x0c09b058u; return 0; }
target=code_base|0x0c09af6cu; r[16]=code_base|0x0c09b05cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b05cu) { target=s->pc; goto dispatch; }
goto P_0c09b05c;
P_0c09b05a: /* original 0009, guest PC 0x0c09b05a */
if(!s->budget--) { s->failed_pc=0x0c09b05au; return 0; }
goto P_0c09b05c;
P_0c09b05c: /* original ed00, guest PC 0x0c09b05c */
if(!s->budget--) { s->failed_pc=0x0c09b05cu; return 0; }
r[13]=0x00000000u;
goto P_0c09b05e;
P_0c09b05e: /* original 2f02, guest PC 0x0c09b05e */
if(!s->budget--) { s->failed_pc=0x0c09b05eu; return 0; }
write(ram,r[15],r[0],4);
goto P_0c09b060;
P_0c09b060: /* original d333, guest PC 0x0c09b060 */
if(!s->budget--) { s->failed_pc=0x0c09b060u; return 0; }
r[3]=read(ram,0x0c09b130u,4);
goto P_0c09b062;
P_0c09b062: /* original 69d3, guest PC 0x0c09b062 */
if(!s->budget--) { s->failed_pc=0x0c09b062u; return 0; }
r[9]=r[13];
goto P_0c09b064;
P_0c09b064: /* original 430b, guest PC 0x0c09b064 */
if(!s->budget--) { s->failed_pc=0x0c09b064u; return 0; }
target=r[3];
r[16]=code_base|0x0c09b068u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b068u) { target=s->pc; goto dispatch; }
goto P_0c09b068;
P_0c09b066: /* original 64d3, guest PC 0x0c09b066 */
if(!s->budget--) { s->failed_pc=0x0c09b066u; return 0; }
r[4]=r[13];
goto P_0c09b068;
P_0c09b068: /* original 1f01, guest PC 0x0c09b068 */
if(!s->budget--) { s->failed_pc=0x0c09b068u; return 0; }
write(ram,r[15]+4,r[0],4);
goto P_0c09b06a;
P_0c09b06a: /* original d331, guest PC 0x0c09b06a */
if(!s->budget--) { s->failed_pc=0x0c09b06au; return 0; }
r[3]=read(ram,0x0c09b130u,4);
goto P_0c09b06c;
P_0c09b06c: /* original 430b, guest PC 0x0c09b06c */
if(!s->budget--) { s->failed_pc=0x0c09b06cu; return 0; }
target=r[3];
r[16]=code_base|0x0c09b070u;
r[4]=0x00000001u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b070u) { target=s->pc; goto dispatch; }
goto P_0c09b070;
P_0c09b06e: /* original e401, guest PC 0x0c09b06e */
if(!s->budget--) { s->failed_pc=0x0c09b06eu; return 0; }
r[4]=0x00000001u;
goto P_0c09b070;
P_0c09b070: /* original 6403, guest PC 0x0c09b070 */
if(!s->budget--) { s->failed_pc=0x0c09b070u; return 0; }
r[4]=r[0];
goto P_0c09b072;
P_0c09b072: /* original 50f1, guest PC 0x0c09b072 */
if(!s->budget--) { s->failed_pc=0x0c09b072u; return 0; }
r[0]=read(ram,r[15]+4,4);
goto P_0c09b074;
P_0c09b074: /* original 6002, guest PC 0x0c09b074 */
if(!s->budget--) { s->failed_pc=0x0c09b074u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c09b076;
P_0c09b076: /* original 88fe, guest PC 0x0c09b076 */
if(!s->budget--) { s->failed_pc=0x0c09b076u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09b078;
P_0c09b078: /* original 8d04, guest PC 0x0c09b078 */
if(!s->budget--) { s->failed_pc=0x0c09b078u; return 0; }
cond=r[17]&1u;
r[11]=0x00000001u;
if(cond) { goto P_0c09b084; }
goto P_0c09b07c;
P_0c09b07a: /* original eb01, guest PC 0x0c09b07a */
if(!s->budget--) { s->failed_pc=0x0c09b07au; return 0; }
r[11]=0x00000001u;
goto P_0c09b07c;
P_0c09b07c: /* original 6042, guest PC 0x0c09b07c */
if(!s->budget--) { s->failed_pc=0x0c09b07cu; return 0; }
tmp=read(ram,r[4],4);
r[0]=tmp;
goto P_0c09b07e;
P_0c09b07e: /* original 88fe, guest PC 0x0c09b07e */
if(!s->budget--) { s->failed_pc=0x0c09b07eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xfffffffeu)!=0);
goto P_0c09b080;
P_0c09b080: /* original 8900, guest PC 0x0c09b080 */
if(!s->budget--) { s->failed_pc=0x0c09b080u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b084; }
goto P_0c09b082;
P_0c09b082: /* original 69b3, guest PC 0x0c09b082 */
if(!s->budget--) { s->failed_pc=0x0c09b082u; return 0; }
r[9]=r[11];
goto P_0c09b084;
P_0c09b084: /* original 2998, guest PC 0x0c09b084 */
if(!s->budget--) { s->failed_pc=0x0c09b084u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c09b086;
P_0c09b086: /* original 8b09, guest PC 0x0c09b086 */
if(!s->budget--) { s->failed_pc=0x0c09b086u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b09c; }
goto P_0c09b088;
P_0c09b088: /* original 9047, guest PC 0x0c09b088 */
if(!s->budget--) { s->failed_pc=0x0c09b088u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b11au,2);
goto P_0c09b08a;
P_0c09b08a: /* original 00ee, guest PC 0x0c09b08a */
if(!s->budget--) { s->failed_pc=0x0c09b08au; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b08c;
P_0c09b08c: /* original 8802, guest PC 0x0c09b08c */
if(!s->budget--) { s->failed_pc=0x0c09b08cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b08e;
P_0c09b08e: /* original 8903, guest PC 0x0c09b08e */
if(!s->budget--) { s->failed_pc=0x0c09b08eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b098; }
goto P_0c09b090;
P_0c09b090: /* original 9043, guest PC 0x0c09b090 */
if(!s->budget--) { s->failed_pc=0x0c09b090u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b11au,2);
goto P_0c09b092;
P_0c09b092: /* original 00ee, guest PC 0x0c09b092 */
if(!s->budget--) { s->failed_pc=0x0c09b092u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b094;
P_0c09b094: /* original 8803, guest PC 0x0c09b094 */
if(!s->budget--) { s->failed_pc=0x0c09b094u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09b096;
P_0c09b096: /* original 8b01, guest PC 0x0c09b096 */
if(!s->budget--) { s->failed_pc=0x0c09b096u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b09c; }
goto P_0c09b098;
P_0c09b098: /* original 903f, guest PC 0x0c09b098 */
if(!s->budget--) { s->failed_pc=0x0c09b098u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b11au,2);
goto P_0c09b09a;
P_0c09b09a: /* original 0ed6, guest PC 0x0c09b09a */
if(!s->budget--) { s->failed_pc=0x0c09b09au; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b09c;
P_0c09b09c: /* original e07d, guest PC 0x0c09b09c */
if(!s->budget--) { s->failed_pc=0x0c09b09cu; return 0; }
r[0]=0x0000007du;
goto P_0c09b09e;
P_0c09b09e: /* original e402, guest PC 0x0c09b09e */
if(!s->budget--) { s->failed_pc=0x0c09b09eu; return 0; }
r[4]=0x00000002u;
goto P_0c09b0a0;
P_0c09b0a0: /* original e340, guest PC 0x0c09b0a0 */
if(!s->budget--) { s->failed_pc=0x0c09b0a0u; return 0; }
r[3]=0x00000040u;
goto P_0c09b0a2;
P_0c09b0a2: /* original 1e33, guest PC 0x0c09b0a2 */
if(!s->budget--) { s->failed_pc=0x0c09b0a2u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c09b0a4;
P_0c09b0a4: /* original 1ed6, guest PC 0x0c09b0a4 */
if(!s->budget--) { s->failed_pc=0x0c09b0a4u; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c09b0a6;
P_0c09b0a6: /* original 0ed4, guest PC 0x0c09b0a6 */
if(!s->budget--) { s->failed_pc=0x0c09b0a6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0a8;
P_0c09b0a8: /* original 1ed5, guest PC 0x0c09b0a8 */
if(!s->budget--) { s->failed_pc=0x0c09b0a8u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c09b0aa;
P_0c09b0aa: /* original 9037, guest PC 0x0c09b0aa */
if(!s->budget--) { s->failed_pc=0x0c09b0aau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b11cu,2);
goto P_0c09b0ac;
P_0c09b0ac: /* original 0ed4, guest PC 0x0c09b0ac */
if(!s->budget--) { s->failed_pc=0x0c09b0acu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0ae;
P_0c09b0ae: /* original 7005, guest PC 0x0c09b0ae */
if(!s->budget--) { s->failed_pc=0x0c09b0aeu; return 0; }
r[0]+=0x00000005u;
goto P_0c09b0b0;
P_0c09b0b0: /* original 0ed4, guest PC 0x0c09b0b0 */
if(!s->budget--) { s->failed_pc=0x0c09b0b0u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0b2;
P_0c09b0b2: /* original 7002, guest PC 0x0c09b0b2 */
if(!s->budget--) { s->failed_pc=0x0c09b0b2u; return 0; }
r[0]+=0x00000002u;
goto P_0c09b0b4;
P_0c09b0b4: /* original 0e44, guest PC 0x0c09b0b4 */
if(!s->budget--) { s->failed_pc=0x0c09b0b4u; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09b0b6;
P_0c09b0b6: /* original 60d3, guest PC 0x0c09b0b6 */
if(!s->budget--) { s->failed_pc=0x0c09b0b6u; return 0; }
r[0]=r[13];
goto P_0c09b0b8;
P_0c09b0b8: /* original 9531, guest PC 0x0c09b0b8 */
if(!s->budget--) { s->failed_pc=0x0c09b0b8u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b11eu,2);
goto P_0c09b0ba;
P_0c09b0ba: /* original 35ec, guest PC 0x0c09b0ba */
if(!s->budget--) { s->failed_pc=0x0c09b0bau; return 0; }
r[5]+=r[14];
goto P_0c09b0bc;
P_0c09b0bc: /* original 8151, guest PC 0x0c09b0bc */
if(!s->budget--) { s->failed_pc=0x0c09b0bcu; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c09b0be;
P_0c09b0be: /* original 2501, guest PC 0x0c09b0be */
if(!s->budget--) { s->failed_pc=0x0c09b0beu; return 0; }
write(ram,r[5],r[0],2);
goto P_0c09b0c0;
P_0c09b0c0: /* original 952e, guest PC 0x0c09b0c0 */
if(!s->budget--) { s->failed_pc=0x0c09b0c0u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b120u,2);
goto P_0c09b0c2;
P_0c09b0c2: /* original 35ec, guest PC 0x0c09b0c2 */
if(!s->budget--) { s->failed_pc=0x0c09b0c2u; return 0; }
r[5]+=r[14];
goto P_0c09b0c4;
P_0c09b0c4: /* original 8151, guest PC 0x0c09b0c4 */
if(!s->budget--) { s->failed_pc=0x0c09b0c4u; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c09b0c6;
P_0c09b0c6: /* original 2501, guest PC 0x0c09b0c6 */
if(!s->budget--) { s->failed_pc=0x0c09b0c6u; return 0; }
write(ram,r[5],r[0],2);
goto P_0c09b0c8;
P_0c09b0c8: /* original 902b, guest PC 0x0c09b0c8 */
if(!s->budget--) { s->failed_pc=0x0c09b0c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b122u,2);
goto P_0c09b0ca;
P_0c09b0ca: /* original 0ed4, guest PC 0x0c09b0ca */
if(!s->budget--) { s->failed_pc=0x0c09b0cau; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0cc;
P_0c09b0cc: /* original 7007, guest PC 0x0c09b0cc */
if(!s->budget--) { s->failed_pc=0x0c09b0ccu; return 0; }
r[0]+=0x00000007u;
goto P_0c09b0ce;
P_0c09b0ce: /* original 0ed4, guest PC 0x0c09b0ce */
if(!s->budget--) { s->failed_pc=0x0c09b0ceu; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0d0;
P_0c09b0d0: /* original 7001, guest PC 0x0c09b0d0 */
if(!s->budget--) { s->failed_pc=0x0c09b0d0u; return 0; }
r[0]+=0x00000001u;
goto P_0c09b0d2;
P_0c09b0d2: /* original 0ed4, guest PC 0x0c09b0d2 */
if(!s->budget--) { s->failed_pc=0x0c09b0d2u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0d4;
P_0c09b0d4: /* original 70fe, guest PC 0x0c09b0d4 */
if(!s->budget--) { s->failed_pc=0x0c09b0d4u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c09b0d6;
P_0c09b0d6: /* original 0ed4, guest PC 0x0c09b0d6 */
if(!s->budget--) { s->failed_pc=0x0c09b0d6u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0d8;
P_0c09b0d8: /* original 70fe, guest PC 0x0c09b0d8 */
if(!s->budget--) { s->failed_pc=0x0c09b0d8u; return 0; }
r[0]+=0xfffffffeu;
goto P_0c09b0da;
P_0c09b0da: /* original 0ed4, guest PC 0x0c09b0da */
if(!s->budget--) { s->failed_pc=0x0c09b0dau; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0dc;
P_0c09b0dc: /* original 7002, guest PC 0x0c09b0dc */
if(!s->budget--) { s->failed_pc=0x0c09b0dcu; return 0; }
r[0]+=0x00000002u;
goto P_0c09b0de;
P_0c09b0de: /* original 0e44, guest PC 0x0c09b0de */
if(!s->budget--) { s->failed_pc=0x0c09b0deu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c09b0e0;
P_0c09b0e0: /* original 7004, guest PC 0x0c09b0e0 */
if(!s->budget--) { s->failed_pc=0x0c09b0e0u; return 0; }
r[0]+=0x00000004u;
goto P_0c09b0e2;
P_0c09b0e2: /* original 0ed4, guest PC 0x0c09b0e2 */
if(!s->budget--) { s->failed_pc=0x0c09b0e2u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b0e4;
P_0c09b0e4: /* original 60f2, guest PC 0x0c09b0e4 */
if(!s->budget--) { s->failed_pc=0x0c09b0e4u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09b0e6;
P_0c09b0e6: /* original c80c, guest PC 0x0c09b0e6 */
if(!s->budget--) { s->failed_pc=0x0c09b0e6u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&12u)==0)!=0);
goto P_0c09b0e8;
P_0c09b0e8: /* original 8f02, guest PC 0x0c09b0e8 */
if(!s->budget--) { s->failed_pc=0x0c09b0e8u; return 0; }
cond=r[17]&1u;
r[8]=0x00000004u;
if(!cond) { goto P_0c09b0f0; }
goto P_0c09b0ec;
P_0c09b0ea: /* original e804, guest PC 0x0c09b0ea */
if(!s->budget--) { s->failed_pc=0x0c09b0eau; return 0; }
r[8]=0x00000004u;
goto P_0c09b0ec;
P_0c09b0ec: /* original a094, guest PC 0x0c09b0ec */
if(!s->budget--) { s->failed_pc=0x0c09b0ecu; return 0; }
goto P_0c09b218;
P_0c09b0ee: /* original 0009, guest PC 0x0c09b0ee */
if(!s->budget--) { s->failed_pc=0x0c09b0eeu; return 0; }
goto P_0c09b0f0;
P_0c09b0f0: /* original 9013, guest PC 0x0c09b0f0 */
if(!s->budget--) { s->failed_pc=0x0c09b0f0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b11au,2);
goto P_0c09b0f2;
P_0c09b0f2: /* original d910, guest PC 0x0c09b0f2 */
if(!s->budget--) { s->failed_pc=0x0c09b0f2u; return 0; }
r[9]=read(ram,0x0c09b134u,4);
goto P_0c09b0f4;
P_0c09b0f4: /* original 00ee, guest PC 0x0c09b0f4 */
if(!s->budget--) { s->failed_pc=0x0c09b0f4u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b0f6;
P_0c09b0f6: /* original 8800, guest PC 0x0c09b0f6 */
if(!s->budget--) { s->failed_pc=0x0c09b0f6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000000u)!=0);
goto P_0c09b0f8;
P_0c09b0f8: /* original 8920, guest PC 0x0c09b0f8 */
if(!s->budget--) { s->failed_pc=0x0c09b0f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b13c; }
goto P_0c09b0fa;
P_0c09b0fa: /* original 8801, guest PC 0x0c09b0fa */
if(!s->budget--) { s->failed_pc=0x0c09b0fau; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b0fc;
P_0c09b0fc: /* original 8939, guest PC 0x0c09b0fc */
if(!s->budget--) { s->failed_pc=0x0c09b0fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b172; }
goto P_0c09b0fe;
P_0c09b0fe: /* original 8802, guest PC 0x0c09b0fe */
if(!s->budget--) { s->failed_pc=0x0c09b0feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b100;
P_0c09b100: /* original 891a, guest PC 0x0c09b100 */
if(!s->budget--) { s->failed_pc=0x0c09b100u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b138; }
goto P_0c09b102;
P_0c09b102: /* original 8803, guest PC 0x0c09b102 */
if(!s->budget--) { s->failed_pc=0x0c09b102u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09b104;
P_0c09b104: /* original 8933, guest PC 0x0c09b104 */
if(!s->budget--) { s->failed_pc=0x0c09b104u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b16e; }
goto P_0c09b106;
P_0c09b106: /* original 8804, guest PC 0x0c09b106 */
if(!s->budget--) { s->failed_pc=0x0c09b106u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c09b108;
P_0c09b108: /* original 8945, guest PC 0x0c09b108 */
if(!s->budget--) { s->failed_pc=0x0c09b108u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b196; }
goto P_0c09b10a;
P_0c09b10a: /* original 8805, guest PC 0x0c09b10a */
if(!s->budget--) { s->failed_pc=0x0c09b10au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09b10c;
P_0c09b10c: /* original 896b, guest PC 0x0c09b10c */
if(!s->budget--) { s->failed_pc=0x0c09b10cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b1e6; }
goto P_0c09b10e;
P_0c09b10e: /* original 8806, guest PC 0x0c09b10e */
if(!s->budget--) { s->failed_pc=0x0c09b10eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c09b110;
P_0c09b110: /* original 896b, guest PC 0x0c09b110 */
if(!s->budget--) { s->failed_pc=0x0c09b110u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b1ea; }
goto P_0c09b112;
P_0c09b112: /* original 8807, guest PC 0x0c09b112 */
if(!s->budget--) { s->failed_pc=0x0c09b112u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c09b114;
P_0c09b114: /* original 896b, guest PC 0x0c09b114 */
if(!s->budget--) { s->failed_pc=0x0c09b114u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b1ee; }
goto P_0c09b116;
P_0c09b116: /* original a0b5, guest PC 0x0c09b116 */
if(!s->budget--) { s->failed_pc=0x0c09b116u; return 0; }
goto P_0c09b284;
P_0c09b118: /* original 0009, guest PC 0x0c09b118 */
if(!s->budget--) { s->failed_pc=0x0c09b118u; return 0; }
if(!vf3_matrix_family(0x0c09b11au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b11au; return 0; } return 1;
P_0c09b138: /* original 905c, guest PC 0x0c09b138 */
if(!s->budget--) { s->failed_pc=0x0c09b138u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b1f4u,2);
goto P_0c09b13a;
P_0c09b13a: /* original 0eb4, guest PC 0x0c09b13a */
if(!s->budget--) { s->failed_pc=0x0c09b13au; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09b13c;
P_0c09b13c: /* original 64a3, guest PC 0x0c09b13c */
if(!s->budget--) { s->failed_pc=0x0c09b13cu; return 0; }
r[4]=r[10];
goto P_0c09b13e;
P_0c09b13e: /* original e500, guest PC 0x0c09b13e */
if(!s->budget--) { s->failed_pc=0x0c09b13eu; return 0; }
r[5]=0x00000000u;
goto P_0c09b140;
P_0c09b140: /* original 490b, guest PC 0x0c09b140 */
if(!s->budget--) { s->failed_pc=0x0c09b140u; return 0; }
target=r[9];
r[16]=code_base|0x0c09b144u;
r[4]+=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b144u) { target=s->pc; goto dispatch; }
goto P_0c09b144;
P_0c09b142: /* original 7415, guest PC 0x0c09b142 */
if(!s->budget--) { s->failed_pc=0x0c09b142u; return 0; }
r[4]+=0x00000015u;
goto P_0c09b144;
P_0c09b144: /* original 53c2, guest PC 0x0c09b144 */
if(!s->budget--) { s->failed_pc=0x0c09b144u; return 0; }
r[3]=read(ram,r[12]+8,4);
goto P_0c09b146;
P_0c09b146: /* original 6083, guest PC 0x0c09b146 */
if(!s->budget--) { s->failed_pc=0x0c09b146u; return 0; }
r[0]=r[8];
goto P_0c09b148;
P_0c09b148: /* original e140, guest PC 0x0c09b148 */
if(!s->budget--) { s->failed_pc=0x0c09b148u; return 0; }
r[1]=0x00000040u;
goto P_0c09b14a;
P_0c09b14a: /* original 238b, guest PC 0x0c09b14a */
if(!s->budget--) { s->failed_pc=0x0c09b14au; return 0; }
r[3]|=r[8];
goto P_0c09b14c;
P_0c09b14c: /* original 1c32, guest PC 0x0c09b14c */
if(!s->budget--) { s->failed_pc=0x0c09b14cu; return 0; }
write(ram,r[12]+8,r[3],4);
goto P_0c09b14e;
P_0c09b14e: /* original 52c2, guest PC 0x0c09b14e */
if(!s->budget--) { s->failed_pc=0x0c09b14eu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09b150;
P_0c09b150: /* original d32a, guest PC 0x0c09b150 */
if(!s->budget--) { s->failed_pc=0x0c09b150u; return 0; }
r[3]=read(ram,0x0c09b1fcu,4);
goto P_0c09b152;
P_0c09b152: /* original 2239, guest PC 0x0c09b152 */
if(!s->budget--) { s->failed_pc=0x0c09b152u; return 0; }
r[2]&=r[3];
goto P_0c09b154;
P_0c09b154: /* original 1c22, guest PC 0x0c09b154 */
if(!s->budget--) { s->failed_pc=0x0c09b154u; return 0; }
write(ram,r[12]+8,r[2],4);
goto P_0c09b156;
P_0c09b156: /* original e211, guest PC 0x0c09b156 */
if(!s->budget--) { s->failed_pc=0x0c09b156u; return 0; }
r[2]=0x00000011u;
goto P_0c09b158;
P_0c09b158: /* original 80ea, guest PC 0x0c09b158 */
if(!s->budget--) { s->failed_pc=0x0c09b158u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09b15a;
P_0c09b15a: /* original 60d3, guest PC 0x0c09b15a */
if(!s->budget--) { s->failed_pc=0x0c09b15au; return 0; }
r[0]=r[13];
goto P_0c09b15c;
P_0c09b15c: /* original 80eb, guest PC 0x0c09b15c */
if(!s->budget--) { s->failed_pc=0x0c09b15cu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b15e;
P_0c09b15e: /* original e010, guest PC 0x0c09b15e */
if(!s->budget--) { s->failed_pc=0x0c09b15eu; return 0; }
r[0]=0x00000010u;
goto P_0c09b160;
P_0c09b160: /* original 0e24, guest PC 0x0c09b160 */
if(!s->budget--) { s->failed_pc=0x0c09b160u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09b162;
P_0c09b162: /* original 60d3, guest PC 0x0c09b162 */
if(!s->budget--) { s->failed_pc=0x0c09b162u; return 0; }
r[0]=r[13];
goto P_0c09b164;
P_0c09b164: /* original 1e13, guest PC 0x0c09b164 */
if(!s->budget--) { s->failed_pc=0x0c09b164u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c09b166;
P_0c09b166: /* original d426, guest PC 0x0c09b166 */
if(!s->budget--) { s->failed_pc=0x0c09b166u; return 0; }
r[4]=read(ram,0x0c09b200u,4);
goto P_0c09b168;
P_0c09b168: /* original 24d0, guest PC 0x0c09b168 */
if(!s->budget--) { s->failed_pc=0x0c09b168u; return 0; }
write(ram,r[4],r[13],1);
goto P_0c09b16a;
P_0c09b16a: /* original a036, guest PC 0x0c09b16a */
if(!s->budget--) { s->failed_pc=0x0c09b16au; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c09b1da;
P_0c09b16c: /* original 8041, guest PC 0x0c09b16c */
if(!s->budget--) { s->failed_pc=0x0c09b16cu; return 0; }
write(ram,r[4]+1,r[0],1);
goto P_0c09b16e;
P_0c09b16e: /* original 9041, guest PC 0x0c09b16e */
if(!s->budget--) { s->failed_pc=0x0c09b16eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b1f4u,2);
goto P_0c09b170;
P_0c09b170: /* original 0eb4, guest PC 0x0c09b170 */
if(!s->budget--) { s->failed_pc=0x0c09b170u; return 0; }
write(ram,r[14]+r[0],r[11],1);
goto P_0c09b172;
P_0c09b172: /* original 64a3, guest PC 0x0c09b172 */
if(!s->budget--) { s->failed_pc=0x0c09b172u; return 0; }
r[4]=r[10];
goto P_0c09b174;
P_0c09b174: /* original e501, guest PC 0x0c09b174 */
if(!s->budget--) { s->failed_pc=0x0c09b174u; return 0; }
r[5]=0x00000001u;
goto P_0c09b176;
P_0c09b176: /* original 490b, guest PC 0x0c09b176 */
if(!s->budget--) { s->failed_pc=0x0c09b176u; return 0; }
target=r[9];
r[16]=code_base|0x0c09b17au;
r[4]+=0x00000015u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b17au) { target=s->pc; goto dispatch; }
goto P_0c09b17a;
P_0c09b178: /* original 7415, guest PC 0x0c09b178 */
if(!s->budget--) { s->failed_pc=0x0c09b178u; return 0; }
r[4]+=0x00000015u;
goto P_0c09b17a;
P_0c09b17a: /* original 6083, guest PC 0x0c09b17a */
if(!s->budget--) { s->failed_pc=0x0c09b17au; return 0; }
r[0]=r[8];
goto P_0c09b17c;
P_0c09b17c: /* original 52c2, guest PC 0x0c09b17c */
if(!s->budget--) { s->failed_pc=0x0c09b17cu; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09b17e;
P_0c09b17e: /* original d321, guest PC 0x0c09b17e */
if(!s->budget--) { s->failed_pc=0x0c09b17eu; return 0; }
r[3]=read(ram,0x0c09b204u,4);
goto P_0c09b180;
P_0c09b180: /* original e140, guest PC 0x0c09b180 */
if(!s->budget--) { s->failed_pc=0x0c09b180u; return 0; }
r[1]=0x00000040u;
goto P_0c09b182;
P_0c09b182: /* original 2239, guest PC 0x0c09b182 */
if(!s->budget--) { s->failed_pc=0x0c09b182u; return 0; }
r[2]&=r[3];
goto P_0c09b184;
P_0c09b184: /* original 1c22, guest PC 0x0c09b184 */
if(!s->budget--) { s->failed_pc=0x0c09b184u; return 0; }
write(ram,r[12]+8,r[2],4);
goto P_0c09b186;
P_0c09b186: /* original e211, guest PC 0x0c09b186 */
if(!s->budget--) { s->failed_pc=0x0c09b186u; return 0; }
r[2]=0x00000011u;
goto P_0c09b188;
P_0c09b188: /* original 80ea, guest PC 0x0c09b188 */
if(!s->budget--) { s->failed_pc=0x0c09b188u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09b18a;
P_0c09b18a: /* original 60d3, guest PC 0x0c09b18a */
if(!s->budget--) { s->failed_pc=0x0c09b18au; return 0; }
r[0]=r[13];
goto P_0c09b18c;
P_0c09b18c: /* original 80eb, guest PC 0x0c09b18c */
if(!s->budget--) { s->failed_pc=0x0c09b18cu; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b18e;
P_0c09b18e: /* original e010, guest PC 0x0c09b18e */
if(!s->budget--) { s->failed_pc=0x0c09b18eu; return 0; }
r[0]=0x00000010u;
goto P_0c09b190;
P_0c09b190: /* original 0e24, guest PC 0x0c09b190 */
if(!s->budget--) { s->failed_pc=0x0c09b190u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c09b192;
P_0c09b192: /* original a022, guest PC 0x0c09b192 */
if(!s->budget--) { s->failed_pc=0x0c09b192u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c09b1da;
P_0c09b194: /* original 1e13, guest PC 0x0c09b194 */
if(!s->budget--) { s->failed_pc=0x0c09b194u; return 0; }
write(ram,r[14]+12,r[1],4);
goto P_0c09b196;
P_0c09b196: /* original 52c2, guest PC 0x0c09b196 */
if(!s->budget--) { s->failed_pc=0x0c09b196u; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09b198;
P_0c09b198: /* original e3fb, guest PC 0x0c09b198 */
if(!s->budget--) { s->failed_pc=0x0c09b198u; return 0; }
r[3]=0xfffffffbu;
goto P_0c09b19a;
P_0c09b19a: /* original 6043, guest PC 0x0c09b19a */
if(!s->budget--) { s->failed_pc=0x0c09b19au; return 0; }
r[0]=r[4];
goto P_0c09b19c;
P_0c09b19c: /* original 2239, guest PC 0x0c09b19c */
if(!s->budget--) { s->failed_pc=0x0c09b19cu; return 0; }
r[2]&=r[3];
goto P_0c09b19e;
P_0c09b19e: /* original 1c22, guest PC 0x0c09b19e */
if(!s->budget--) { s->failed_pc=0x0c09b19eu; return 0; }
write(ram,r[12]+8,r[2],4);
goto P_0c09b1a0;
P_0c09b1a0: /* original 51c2, guest PC 0x0c09b1a0 */
if(!s->budget--) { s->failed_pc=0x0c09b1a0u; return 0; }
r[1]=read(ram,r[12]+8,4);
goto P_0c09b1a2;
P_0c09b1a2: /* original d219, guest PC 0x0c09b1a2 */
if(!s->budget--) { s->failed_pc=0x0c09b1a2u; return 0; }
r[2]=read(ram,0x0c09b208u,4);
goto P_0c09b1a4;
P_0c09b1a4: /* original 212b, guest PC 0x0c09b1a4 */
if(!s->budget--) { s->failed_pc=0x0c09b1a4u; return 0; }
r[1]|=r[2];
goto P_0c09b1a6;
P_0c09b1a6: /* original 1c12, guest PC 0x0c09b1a6 */
if(!s->budget--) { s->failed_pc=0x0c09b1a6u; return 0; }
write(ram,r[12]+8,r[1],4);
goto P_0c09b1a8;
P_0c09b1a8: /* original 80eb, guest PC 0x0c09b1a8 */
if(!s->budget--) { s->failed_pc=0x0c09b1a8u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b1aa;
P_0c09b1aa: /* original d119, guest PC 0x0c09b1aa */
if(!s->budget--) { s->failed_pc=0x0c09b1aau; return 0; }
r[1]=read(ram,0x0c09b210u,4);
goto P_0c09b1ac;
P_0c09b1ac: /* original 50c2, guest PC 0x0c09b1ac */
if(!s->budget--) { s->failed_pc=0x0c09b1acu; return 0; }
r[0]=read(ram,r[12]+8,4);
goto P_0c09b1ae;
P_0c09b1ae: /* original d517, guest PC 0x0c09b1ae */
if(!s->budget--) { s->failed_pc=0x0c09b1aeu; return 0; }
r[5]=read(ram,0x0c09b20cu,4);
goto P_0c09b1b0;
P_0c09b1b0: /* original 2018, guest PC 0x0c09b1b0 */
if(!s->budget--) { s->failed_pc=0x0c09b1b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c09b1b2;
P_0c09b1b2: /* original 8908, guest PC 0x0c09b1b2 */
if(!s->budget--) { s->failed_pc=0x0c09b1b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b1c6; }
goto P_0c09b1b4;
P_0c09b1b4: /* original e029, guest PC 0x0c09b1b4 */
if(!s->budget--) { s->failed_pc=0x0c09b1b4u; return 0; }
r[0]=0x00000029u;
goto P_0c09b1b6;
P_0c09b1b6: /* original 0c44, guest PC 0x0c09b1b6 */
if(!s->budget--) { s->failed_pc=0x0c09b1b6u; return 0; }
write(ram,r[12]+r[0],r[4],1);
goto P_0c09b1b8;
P_0c09b1b8: /* original 535b, guest PC 0x0c09b1b8 */
if(!s->budget--) { s->failed_pc=0x0c09b1b8u; return 0; }
r[3]=read(ram,r[5]+44,4);
goto P_0c09b1ba;
P_0c09b1ba: /* original 6232, guest PC 0x0c09b1ba */
if(!s->budget--) { s->failed_pc=0x0c09b1bau; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09b1bc;
P_0c09b1bc: /* original 224b, guest PC 0x0c09b1bc */
if(!s->budget--) { s->failed_pc=0x0c09b1bcu; return 0; }
r[2]|=r[4];
goto P_0c09b1be;
P_0c09b1be: /* original 2322, guest PC 0x0c09b1be */
if(!s->budget--) { s->failed_pc=0x0c09b1beu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09b1c0;
P_0c09b1c0: /* original 9319, guest PC 0x0c09b1c0 */
if(!s->budget--) { s->failed_pc=0x0c09b1c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b1f6u,2);
goto P_0c09b1c2;
P_0c09b1c2: /* original a007, guest PC 0x0c09b1c2 */
if(!s->budget--) { s->failed_pc=0x0c09b1c2u; return 0; }
goto P_0c09b1d4;
P_0c09b1c4: /* original 0009, guest PC 0x0c09b1c4 */
if(!s->budget--) { s->failed_pc=0x0c09b1c4u; return 0; }
goto P_0c09b1c6;
P_0c09b1c6: /* original e029, guest PC 0x0c09b1c6 */
if(!s->budget--) { s->failed_pc=0x0c09b1c6u; return 0; }
r[0]=0x00000029u;
goto P_0c09b1c8;
P_0c09b1c8: /* original 0cb4, guest PC 0x0c09b1c8 */
if(!s->budget--) { s->failed_pc=0x0c09b1c8u; return 0; }
write(ram,r[12]+r[0],r[11],1);
goto P_0c09b1ca;
P_0c09b1ca: /* original 535a, guest PC 0x0c09b1ca */
if(!s->budget--) { s->failed_pc=0x0c09b1cau; return 0; }
r[3]=read(ram,r[5]+40,4);
goto P_0c09b1cc;
P_0c09b1cc: /* original 6232, guest PC 0x0c09b1cc */
if(!s->budget--) { s->failed_pc=0x0c09b1ccu; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c09b1ce;
P_0c09b1ce: /* original 224b, guest PC 0x0c09b1ce */
if(!s->budget--) { s->failed_pc=0x0c09b1ceu; return 0; }
r[2]|=r[4];
goto P_0c09b1d0;
P_0c09b1d0: /* original 2322, guest PC 0x0c09b1d0 */
if(!s->budget--) { s->failed_pc=0x0c09b1d0u; return 0; }
write(ram,r[3],r[2],4);
goto P_0c09b1d2;
P_0c09b1d2: /* original 9311, guest PC 0x0c09b1d2 */
if(!s->budget--) { s->failed_pc=0x0c09b1d2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b1f8u,2);
goto P_0c09b1d4;
P_0c09b1d4: /* original 52c2, guest PC 0x0c09b1d4 */
if(!s->budget--) { s->failed_pc=0x0c09b1d4u; return 0; }
r[2]=read(ram,r[12]+8,4);
goto P_0c09b1d6;
P_0c09b1d6: /* original 223b, guest PC 0x0c09b1d6 */
if(!s->budget--) { s->failed_pc=0x0c09b1d6u; return 0; }
r[2]|=r[3];
goto P_0c09b1d8;
P_0c09b1d8: /* original 1c22, guest PC 0x0c09b1d8 */
if(!s->budget--) { s->failed_pc=0x0c09b1d8u; return 0; }
write(ram,r[12]+8,r[2],4);
goto P_0c09b1da;
P_0c09b1da: /* original d30e, guest PC 0x0c09b1da */
if(!s->budget--) { s->failed_pc=0x0c09b1dau; return 0; }
r[3]=read(ram,0x0c09b214u,4);
goto P_0c09b1dc;
P_0c09b1dc: /* original 940d, guest PC 0x0c09b1dc */
if(!s->budget--) { s->failed_pc=0x0c09b1dcu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b1fau,2);
goto P_0c09b1de;
P_0c09b1de: /* original 430b, guest PC 0x0c09b1de */
if(!s->budget--) { s->failed_pc=0x0c09b1deu; return 0; }
target=r[3];
r[16]=code_base|0x0c09b1e2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b1e2u) { target=s->pc; goto dispatch; }
goto P_0c09b1e2;
P_0c09b1e0: /* original 0009, guest PC 0x0c09b1e0 */
if(!s->budget--) { s->failed_pc=0x0c09b1e0u; return 0; }
goto P_0c09b1e2;
P_0c09b1e2: /* original a04f, guest PC 0x0c09b1e2 */
if(!s->budget--) { s->failed_pc=0x0c09b1e2u; return 0; }
goto P_0c09b284;
P_0c09b1e4: /* original 0009, guest PC 0x0c09b1e4 */
if(!s->budget--) { s->failed_pc=0x0c09b1e4u; return 0; }
goto P_0c09b1e6;
P_0c09b1e6: /* original a003, guest PC 0x0c09b1e6 */
if(!s->budget--) { s->failed_pc=0x0c09b1e6u; return 0; }
r[0]=r[8];
goto P_0c09b1f0;
P_0c09b1e8: /* original 6083, guest PC 0x0c09b1e8 */
if(!s->budget--) { s->failed_pc=0x0c09b1e8u; return 0; }
r[0]=r[8];
goto P_0c09b1ea;
P_0c09b1ea: /* original a001, guest PC 0x0c09b1ea */
if(!s->budget--) { s->failed_pc=0x0c09b1eau; return 0; }
r[0]=0x00000006u;
goto P_0c09b1f0;
P_0c09b1ec: /* original e006, guest PC 0x0c09b1ec */
if(!s->budget--) { s->failed_pc=0x0c09b1ecu; return 0; }
r[0]=0x00000006u;
goto P_0c09b1ee;
P_0c09b1ee: /* original e008, guest PC 0x0c09b1ee */
if(!s->budget--) { s->failed_pc=0x0c09b1eeu; return 0; }
r[0]=0x00000008u;
goto P_0c09b1f0;
P_0c09b1f0: /* original a048, guest PC 0x0c09b1f0 */
if(!s->budget--) { s->failed_pc=0x0c09b1f0u; return 0; }
write(ram,r[14]+11,r[0],1);
goto P_0c09b284;
P_0c09b1f2: /* original 80eb, guest PC 0x0c09b1f2 */
if(!s->budget--) { s->failed_pc=0x0c09b1f2u; return 0; }
write(ram,r[14]+11,r[0],1);
if(!vf3_matrix_family(0x0c09b1f4u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c09b1f4u; return 0; } return 1;
P_0c09b218: /* original 60f2, guest PC 0x0c09b218 */
if(!s->budget--) { s->failed_pc=0x0c09b218u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09b21a;
P_0c09b21a: /* original c810, guest PC 0x0c09b21a */
if(!s->budget--) { s->failed_pc=0x0c09b21au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&16u)==0)!=0);
goto P_0c09b21c;
P_0c09b21c: /* original 8917, guest PC 0x0c09b21c */
if(!s->budget--) { s->failed_pc=0x0c09b21cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b24e; }
goto P_0c09b21e;
P_0c09b21e: /* original d24c, guest PC 0x0c09b21e */
if(!s->budget--) { s->failed_pc=0x0c09b21eu; return 0; }
r[2]=read(ram,0x0c09b350u,4);
goto P_0c09b220;
P_0c09b220: /* original 948f, guest PC 0x0c09b220 */
if(!s->budget--) { s->failed_pc=0x0c09b220u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b342u,2);
goto P_0c09b222;
P_0c09b222: /* original 420b, guest PC 0x0c09b222 */
if(!s->budget--) { s->failed_pc=0x0c09b222u; return 0; }
target=r[2];
r[16]=code_base|0x0c09b226u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b226u) { target=s->pc; goto dispatch; }
goto P_0c09b226;
P_0c09b224: /* original 0009, guest PC 0x0c09b224 */
if(!s->budget--) { s->failed_pc=0x0c09b224u; return 0; }
goto P_0c09b226;
P_0c09b226: /* original 908d, guest PC 0x0c09b226 */
if(!s->budget--) { s->failed_pc=0x0c09b226u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b344u,2);
goto P_0c09b228;
P_0c09b228: /* original 03ee, guest PC 0x0c09b228 */
if(!s->budget--) { s->failed_pc=0x0c09b228u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b22a;
P_0c09b22a: /* original 73ff, guest PC 0x0c09b22a */
if(!s->budget--) { s->failed_pc=0x0c09b22au; return 0; }
r[3]+=0xffffffffu;
goto P_0c09b22c;
P_0c09b22c: /* original 0e36, guest PC 0x0c09b22c */
if(!s->budget--) { s->failed_pc=0x0c09b22cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b22e;
P_0c09b22e: /* original 02ee, guest PC 0x0c09b22e */
if(!s->budget--) { s->failed_pc=0x0c09b22eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b230;
P_0c09b230: /* original 4211, guest PC 0x0c09b230 */
if(!s->budget--) { s->failed_pc=0x0c09b230u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09b232;
P_0c09b232: /* original 8901, guest PC 0x0c09b232 */
if(!s->budget--) { s->failed_pc=0x0c09b232u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b238; }
goto P_0c09b234;
P_0c09b234: /* original e107, guest PC 0x0c09b234 */
if(!s->budget--) { s->failed_pc=0x0c09b234u; return 0; }
r[1]=0x00000007u;
goto P_0c09b236;
P_0c09b236: /* original 0e16, guest PC 0x0c09b236 */
if(!s->budget--) { s->failed_pc=0x0c09b236u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b238;
P_0c09b238: /* original 2998, guest PC 0x0c09b238 */
if(!s->budget--) { s->failed_pc=0x0c09b238u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c09b23a;
P_0c09b23a: /* original 8b08, guest PC 0x0c09b23a */
if(!s->budget--) { s->failed_pc=0x0c09b23au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b24e; }
goto P_0c09b23c;
P_0c09b23c: /* original 00ee, guest PC 0x0c09b23c */
if(!s->budget--) { s->failed_pc=0x0c09b23cu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b23e;
P_0c09b23e: /* original 8802, guest PC 0x0c09b23e */
if(!s->budget--) { s->failed_pc=0x0c09b23eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b240;
P_0c09b240: /* original 8903, guest PC 0x0c09b240 */
if(!s->budget--) { s->failed_pc=0x0c09b240u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b24a; }
goto P_0c09b242;
P_0c09b242: /* original 907f, guest PC 0x0c09b242 */
if(!s->budget--) { s->failed_pc=0x0c09b242u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b344u,2);
goto P_0c09b244;
P_0c09b244: /* original 00ee, guest PC 0x0c09b244 */
if(!s->budget--) { s->failed_pc=0x0c09b244u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b246;
P_0c09b246: /* original 8803, guest PC 0x0c09b246 */
if(!s->budget--) { s->failed_pc=0x0c09b246u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09b248;
P_0c09b248: /* original 8b01, guest PC 0x0c09b248 */
if(!s->budget--) { s->failed_pc=0x0c09b248u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b24e; }
goto P_0c09b24a;
P_0c09b24a: /* original 907b, guest PC 0x0c09b24a */
if(!s->budget--) { s->failed_pc=0x0c09b24au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b344u,2);
goto P_0c09b24c;
P_0c09b24c: /* original 0eb6, guest PC 0x0c09b24c */
if(!s->budget--) { s->failed_pc=0x0c09b24cu; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b24e;
P_0c09b24e: /* original 60f2, guest PC 0x0c09b24e */
if(!s->budget--) { s->failed_pc=0x0c09b24eu; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c09b250;
P_0c09b250: /* original c820, guest PC 0x0c09b250 */
if(!s->budget--) { s->failed_pc=0x0c09b250u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&32u)==0)!=0);
goto P_0c09b252;
P_0c09b252: /* original 8917, guest PC 0x0c09b252 */
if(!s->budget--) { s->failed_pc=0x0c09b252u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b284; }
goto P_0c09b254;
P_0c09b254: /* original d23e, guest PC 0x0c09b254 */
if(!s->budget--) { s->failed_pc=0x0c09b254u; return 0; }
r[2]=read(ram,0x0c09b350u,4);
goto P_0c09b256;
P_0c09b256: /* original 9474, guest PC 0x0c09b256 */
if(!s->budget--) { s->failed_pc=0x0c09b256u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b342u,2);
goto P_0c09b258;
P_0c09b258: /* original 420b, guest PC 0x0c09b258 */
if(!s->budget--) { s->failed_pc=0x0c09b258u; return 0; }
target=r[2];
r[16]=code_base|0x0c09b25cu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c09b25cu) { target=s->pc; goto dispatch; }
goto P_0c09b25c;
P_0c09b25a: /* original 0009, guest PC 0x0c09b25a */
if(!s->budget--) { s->failed_pc=0x0c09b25au; return 0; }
goto P_0c09b25c;
P_0c09b25c: /* original 9072, guest PC 0x0c09b25c */
if(!s->budget--) { s->failed_pc=0x0c09b25cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b344u,2);
goto P_0c09b25e;
P_0c09b25e: /* original e207, guest PC 0x0c09b25e */
if(!s->budget--) { s->failed_pc=0x0c09b25eu; return 0; }
r[2]=0x00000007u;
goto P_0c09b260;
P_0c09b260: /* original 03ee, guest PC 0x0c09b260 */
if(!s->budget--) { s->failed_pc=0x0c09b260u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b262;
P_0c09b262: /* original 7301, guest PC 0x0c09b262 */
if(!s->budget--) { s->failed_pc=0x0c09b262u; return 0; }
r[3]+=0x00000001u;
goto P_0c09b264;
P_0c09b264: /* original 0e36, guest PC 0x0c09b264 */
if(!s->budget--) { s->failed_pc=0x0c09b264u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b266;
P_0c09b266: /* original 01ee, guest PC 0x0c09b266 */
if(!s->budget--) { s->failed_pc=0x0c09b266u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b268;
P_0c09b268: /* original 3127, guest PC 0x0c09b268 */
if(!s->budget--) { s->failed_pc=0x0c09b268u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[2])!=0);
goto P_0c09b26a;
P_0c09b26a: /* original 8b00, guest PC 0x0c09b26a */
if(!s->budget--) { s->failed_pc=0x0c09b26au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b26e; }
goto P_0c09b26c;
P_0c09b26c: /* original 0ed6, guest PC 0x0c09b26c */
if(!s->budget--) { s->failed_pc=0x0c09b26cu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b26e;
P_0c09b26e: /* original 2998, guest PC 0x0c09b26e */
if(!s->budget--) { s->failed_pc=0x0c09b26eu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c09b270;
P_0c09b270: /* original 8b08, guest PC 0x0c09b270 */
if(!s->budget--) { s->failed_pc=0x0c09b270u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b284; }
goto P_0c09b272;
P_0c09b272: /* original 00ee, guest PC 0x0c09b272 */
if(!s->budget--) { s->failed_pc=0x0c09b272u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b274;
P_0c09b274: /* original 8802, guest PC 0x0c09b274 */
if(!s->budget--) { s->failed_pc=0x0c09b274u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b276;
P_0c09b276: /* original 8903, guest PC 0x0c09b276 */
if(!s->budget--) { s->failed_pc=0x0c09b276u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b280; }
goto P_0c09b278;
P_0c09b278: /* original 9064, guest PC 0x0c09b278 */
if(!s->budget--) { s->failed_pc=0x0c09b278u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b344u,2);
goto P_0c09b27a;
P_0c09b27a: /* original 00ee, guest PC 0x0c09b27a */
if(!s->budget--) { s->failed_pc=0x0c09b27au; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b27c;
P_0c09b27c: /* original 8803, guest PC 0x0c09b27c */
if(!s->budget--) { s->failed_pc=0x0c09b27cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09b27e;
P_0c09b27e: /* original 8b01, guest PC 0x0c09b27e */
if(!s->budget--) { s->failed_pc=0x0c09b27eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b284; }
goto P_0c09b280;
P_0c09b280: /* original 9060, guest PC 0x0c09b280 */
if(!s->budget--) { s->failed_pc=0x0c09b280u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b344u,2);
goto P_0c09b282;
P_0c09b282: /* original 0e86, guest PC 0x0c09b282 */
if(!s->budget--) { s->failed_pc=0x0c09b282u; return 0; }
write(ram,r[14]+r[0],r[8],4);
goto P_0c09b284;
P_0c09b284: /* original 7f08, guest PC 0x0c09b284 */
if(!s->budget--) { s->failed_pc=0x0c09b284u; return 0; }
r[15]+=0x00000008u;
goto P_0c09b286;
P_0c09b286: /* original 4f26, guest PC 0x0c09b286 */
if(!s->budget--) { s->failed_pc=0x0c09b286u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b288;
P_0c09b288: /* original 68f6, guest PC 0x0c09b288 */
if(!s->budget--) { s->failed_pc=0x0c09b288u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09b28a;
P_0c09b28a: /* original 69f6, guest PC 0x0c09b28a */
if(!s->budget--) { s->failed_pc=0x0c09b28au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b28c;
P_0c09b28c: /* original 6af6, guest PC 0x0c09b28c */
if(!s->budget--) { s->failed_pc=0x0c09b28cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b28e;
P_0c09b28e: /* original 6bf6, guest PC 0x0c09b28e */
if(!s->budget--) { s->failed_pc=0x0c09b28eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b290;
P_0c09b290: /* original 6cf6, guest PC 0x0c09b290 */
if(!s->budget--) { s->failed_pc=0x0c09b290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b292;
P_0c09b292: /* original 6df6, guest PC 0x0c09b292 */
if(!s->budget--) { s->failed_pc=0x0c09b292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b294;
P_0c09b294: /* original 000b, guest PC 0x0c09b294 */
if(!s->budget--) { s->failed_pc=0x0c09b294u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09b296: /* original 6ef6, guest PC 0x0c09b296 */
if(!s->budget--) { s->failed_pc=0x0c09b296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09b298u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
