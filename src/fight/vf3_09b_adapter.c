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
int vf3_09b_adapter(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
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
case 0x0c09b37eu: goto P_0c09b37e;
case 0x0c09b380u: goto P_0c09b380;
case 0x0c09b382u: goto P_0c09b382;
case 0x0c09b384u: goto P_0c09b384;
case 0x0c09b386u: goto P_0c09b386;
case 0x0c09b388u: goto P_0c09b388;
case 0x0c09b38au: goto P_0c09b38a;
case 0x0c09b38cu: goto P_0c09b38c;
case 0x0c09b38eu: goto P_0c09b38e;
case 0x0c09b390u: goto P_0c09b390;
case 0x0c09b392u: goto P_0c09b392;
case 0x0c09b394u: goto P_0c09b394;
case 0x0c09b396u: goto P_0c09b396;
case 0x0c09b398u: goto P_0c09b398;
case 0x0c09b39au: goto P_0c09b39a;
case 0x0c09b39cu: goto P_0c09b39c;
case 0x0c09b39eu: goto P_0c09b39e;
case 0x0c09b3a0u: goto P_0c09b3a0;
case 0x0c09b3a2u: goto P_0c09b3a2;
case 0x0c09b3a4u: goto P_0c09b3a4;
case 0x0c09b3a6u: goto P_0c09b3a6;
case 0x0c09b3a8u: goto P_0c09b3a8;
case 0x0c09b3aau: goto P_0c09b3aa;
case 0x0c09b3acu: goto P_0c09b3ac;
case 0x0c09b3aeu: goto P_0c09b3ae;
case 0x0c09b3b0u: goto P_0c09b3b0;
case 0x0c09b3b2u: goto P_0c09b3b2;
case 0x0c09b3b4u: goto P_0c09b3b4;
case 0x0c09b3b6u: goto P_0c09b3b6;
case 0x0c09b3b8u: goto P_0c09b3b8;
case 0x0c09b3bau: goto P_0c09b3ba;
case 0x0c09b3bcu: goto P_0c09b3bc;
case 0x0c09b3beu: goto P_0c09b3be;
case 0x0c09b3c0u: goto P_0c09b3c0;
case 0x0c09b3c2u: goto P_0c09b3c2;
case 0x0c09b3c4u: goto P_0c09b3c4;
case 0x0c09b3c6u: goto P_0c09b3c6;
case 0x0c09b3c8u: goto P_0c09b3c8;
case 0x0c09b3cau: goto P_0c09b3ca;
case 0x0c09b3ccu: goto P_0c09b3cc;
case 0x0c09b3ceu: goto P_0c09b3ce;
case 0x0c09b3d0u: goto P_0c09b3d0;
case 0x0c09b3d2u: goto P_0c09b3d2;
case 0x0c09b3d4u: goto P_0c09b3d4;
case 0x0c09b3d6u: goto P_0c09b3d6;
case 0x0c09b3d8u: goto P_0c09b3d8;
case 0x0c09b3dau: goto P_0c09b3da;
case 0x0c09b3dcu: goto P_0c09b3dc;
case 0x0c09b3deu: goto P_0c09b3de;
case 0x0c09b3e0u: goto P_0c09b3e0;
case 0x0c09b3e2u: goto P_0c09b3e2;
case 0x0c09b3e4u: goto P_0c09b3e4;
case 0x0c09b3e6u: goto P_0c09b3e6;
case 0x0c09b3e8u: goto P_0c09b3e8;
case 0x0c09b3eau: goto P_0c09b3ea;
case 0x0c09b3ecu: goto P_0c09b3ec;
case 0x0c09b3eeu: goto P_0c09b3ee;
case 0x0c09b3f0u: goto P_0c09b3f0;
case 0x0c09b3f2u: goto P_0c09b3f2;
case 0x0c09b3f4u: goto P_0c09b3f4;
case 0x0c09b3f6u: goto P_0c09b3f6;
case 0x0c09b3f8u: goto P_0c09b3f8;
case 0x0c09b3fau: goto P_0c09b3fa;
case 0x0c09b3fcu: goto P_0c09b3fc;
case 0x0c09b3feu: goto P_0c09b3fe;
case 0x0c09b400u: goto P_0c09b400;
case 0x0c09b402u: goto P_0c09b402;
case 0x0c09b404u: goto P_0c09b404;
case 0x0c09b406u: goto P_0c09b406;
case 0x0c09b408u: goto P_0c09b408;
case 0x0c09b40au: goto P_0c09b40a;
case 0x0c09b40cu: goto P_0c09b40c;
case 0x0c09b40eu: goto P_0c09b40e;
case 0x0c09b410u: goto P_0c09b410;
case 0x0c09b412u: goto P_0c09b412;
case 0x0c09b414u: goto P_0c09b414;
case 0x0c09b416u: goto P_0c09b416;
case 0x0c09b418u: goto P_0c09b418;
case 0x0c09b41au: goto P_0c09b41a;
case 0x0c09b41cu: goto P_0c09b41c;
case 0x0c09b41eu: goto P_0c09b41e;
case 0x0c09b420u: goto P_0c09b420;
case 0x0c09b422u: goto P_0c09b422;
case 0x0c09b424u: goto P_0c09b424;
case 0x0c09b426u: goto P_0c09b426;
case 0x0c09b428u: goto P_0c09b428;
case 0x0c09b42au: goto P_0c09b42a;
case 0x0c09b42cu: goto P_0c09b42c;
case 0x0c09b42eu: goto P_0c09b42e;
case 0x0c09b430u: goto P_0c09b430;
case 0x0c09b432u: goto P_0c09b432;
case 0x0c09b434u: goto P_0c09b434;
case 0x0c09b436u: goto P_0c09b436;
case 0x0c09b438u: goto P_0c09b438;
case 0x0c09b43au: goto P_0c09b43a;
case 0x0c09b43cu: goto P_0c09b43c;
case 0x0c09b43eu: goto P_0c09b43e;
case 0x0c09b440u: goto P_0c09b440;
case 0x0c09b442u: goto P_0c09b442;
case 0x0c09b45cu: goto P_0c09b45c;
case 0x0c09b45eu: goto P_0c09b45e;
case 0x0c09b460u: goto P_0c09b460;
case 0x0c09b462u: goto P_0c09b462;
case 0x0c09b464u: goto P_0c09b464;
case 0x0c09b466u: goto P_0c09b466;
case 0x0c09b468u: goto P_0c09b468;
case 0x0c09b46au: goto P_0c09b46a;
case 0x0c09b46cu: goto P_0c09b46c;
case 0x0c09b46eu: goto P_0c09b46e;
case 0x0c09b470u: goto P_0c09b470;
case 0x0c09b472u: goto P_0c09b472;
case 0x0c09b474u: goto P_0c09b474;
case 0x0c09b476u: goto P_0c09b476;
case 0x0c09b478u: goto P_0c09b478;
case 0x0c09b47au: goto P_0c09b47a;
case 0x0c09b47cu: goto P_0c09b47c;
case 0x0c09b47eu: goto P_0c09b47e;
case 0x0c09b480u: goto P_0c09b480;
case 0x0c09b482u: goto P_0c09b482;
case 0x0c09b484u: goto P_0c09b484;
case 0x0c09b486u: goto P_0c09b486;
case 0x0c09b488u: goto P_0c09b488;
case 0x0c09b48au: goto P_0c09b48a;
case 0x0c09b48cu: goto P_0c09b48c;
case 0x0c09b48eu: goto P_0c09b48e;
case 0x0c09b490u: goto P_0c09b490;
case 0x0c09b492u: goto P_0c09b492;
case 0x0c09b494u: goto P_0c09b494;
case 0x0c09b496u: goto P_0c09b496;
case 0x0c09b498u: goto P_0c09b498;
case 0x0c09b49au: goto P_0c09b49a;
case 0x0c09b49cu: goto P_0c09b49c;
case 0x0c09b49eu: goto P_0c09b49e;
case 0x0c09b4a0u: goto P_0c09b4a0;
case 0x0c09b4a2u: goto P_0c09b4a2;
case 0x0c09b4a4u: goto P_0c09b4a4;
case 0x0c09b4a6u: goto P_0c09b4a6;
case 0x0c09b4a8u: goto P_0c09b4a8;
case 0x0c09b4aau: goto P_0c09b4aa;
case 0x0c09b4acu: goto P_0c09b4ac;
case 0x0c09b4aeu: goto P_0c09b4ae;
case 0x0c09b4b0u: goto P_0c09b4b0;
case 0x0c09b4b2u: goto P_0c09b4b2;
case 0x0c09b4b4u: goto P_0c09b4b4;
case 0x0c09b4b6u: goto P_0c09b4b6;
case 0x0c09b4b8u: goto P_0c09b4b8;
case 0x0c09b4bau: goto P_0c09b4ba;
case 0x0c09b4bcu: goto P_0c09b4bc;
case 0x0c09b4beu: goto P_0c09b4be;
case 0x0c09b4c0u: goto P_0c09b4c0;
case 0x0c09b4c2u: goto P_0c09b4c2;
case 0x0c09b4c4u: goto P_0c09b4c4;
case 0x0c09b4c6u: goto P_0c09b4c6;
case 0x0c09b4c8u: goto P_0c09b4c8;
case 0x0c09b4cau: goto P_0c09b4ca;
case 0x0c09b4ccu: goto P_0c09b4cc;
case 0x0c09b4ceu: goto P_0c09b4ce;
case 0x0c09b4d0u: goto P_0c09b4d0;
case 0x0c09b4d2u: goto P_0c09b4d2;
case 0x0c09b4d4u: goto P_0c09b4d4;
case 0x0c09b4d6u: goto P_0c09b4d6;
case 0x0c09b4d8u: goto P_0c09b4d8;
case 0x0c09b4dau: goto P_0c09b4da;
case 0x0c09b4dcu: goto P_0c09b4dc;
case 0x0c09b4deu: goto P_0c09b4de;
case 0x0c09b4e0u: goto P_0c09b4e0;
case 0x0c09b4e2u: goto P_0c09b4e2;
case 0x0c09b4e4u: goto P_0c09b4e4;
case 0x0c09b4e6u: goto P_0c09b4e6;
case 0x0c09b4e8u: goto P_0c09b4e8;
case 0x0c09b4eau: goto P_0c09b4ea;
case 0x0c09b4ecu: goto P_0c09b4ec;
case 0x0c09b4eeu: goto P_0c09b4ee;
case 0x0c09b4f0u: goto P_0c09b4f0;
case 0x0c09b4f2u: goto P_0c09b4f2;
case 0x0c09b4f4u: goto P_0c09b4f4;
case 0x0c09b4f6u: goto P_0c09b4f6;
case 0x0c09b4f8u: goto P_0c09b4f8;
case 0x0c09b4fau: goto P_0c09b4fa;
case 0x0c09b4fcu: goto P_0c09b4fc;
case 0x0c09b4feu: goto P_0c09b4fe;
case 0x0c09b500u: goto P_0c09b500;
case 0x0c09b502u: goto P_0c09b502;
case 0x0c09b504u: goto P_0c09b504;
case 0x0c09b506u: goto P_0c09b506;
case 0x0c09b508u: goto P_0c09b508;
case 0x0c09b50au: goto P_0c09b50a;
case 0x0c09b50cu: goto P_0c09b50c;
case 0x0c09b50eu: goto P_0c09b50e;
case 0x0c09b510u: goto P_0c09b510;
case 0x0c09b512u: goto P_0c09b512;
case 0x0c09b514u: goto P_0c09b514;
case 0x0c09b516u: goto P_0c09b516;
case 0x0c09b518u: goto P_0c09b518;
case 0x0c09b51au: goto P_0c09b51a;
case 0x0c09b51cu: goto P_0c09b51c;
case 0x0c09b51eu: goto P_0c09b51e;
case 0x0c09b520u: goto P_0c09b520;
case 0x0c09b522u: goto P_0c09b522;
case 0x0c09b524u: goto P_0c09b524;
case 0x0c09b526u: goto P_0c09b526;
case 0x0c09b528u: goto P_0c09b528;
case 0x0c09b52au: goto P_0c09b52a;
case 0x0c09b52cu: goto P_0c09b52c;
case 0x0c09b52eu: goto P_0c09b52e;
case 0x0c09b530u: goto P_0c09b530;
case 0x0c09b532u: goto P_0c09b532;
case 0x0c09b534u: goto P_0c09b534;
case 0x0c09b536u: goto P_0c09b536;
case 0x0c09b538u: goto P_0c09b538;
case 0x0c09b54cu: goto P_0c09b54c;
case 0x0c09b54eu: goto P_0c09b54e;
case 0x0c09b550u: goto P_0c09b550;
case 0x0c09b552u: goto P_0c09b552;
case 0x0c09b554u: goto P_0c09b554;
case 0x0c09b556u: goto P_0c09b556;
case 0x0c09b558u: goto P_0c09b558;
case 0x0c09b55au: goto P_0c09b55a;
case 0x0c09b55cu: goto P_0c09b55c;
case 0x0c09b55eu: goto P_0c09b55e;
case 0x0c09b560u: goto P_0c09b560;
case 0x0c09b562u: goto P_0c09b562;
case 0x0c09b564u: goto P_0c09b564;
case 0x0c09b566u: goto P_0c09b566;
case 0x0c09b568u: goto P_0c09b568;
case 0x0c09b56au: goto P_0c09b56a;
case 0x0c09b56cu: goto P_0c09b56c;
case 0x0c09b56eu: goto P_0c09b56e;
case 0x0c09b570u: goto P_0c09b570;
case 0x0c09b572u: goto P_0c09b572;
case 0x0c09b574u: goto P_0c09b574;
case 0x0c09b576u: goto P_0c09b576;
case 0x0c09b578u: goto P_0c09b578;
case 0x0c09b57au: goto P_0c09b57a;
case 0x0c09b57cu: goto P_0c09b57c;
case 0x0c09b57eu: goto P_0c09b57e;
case 0x0c09b580u: goto P_0c09b580;
case 0x0c09b582u: goto P_0c09b582;
case 0x0c09b584u: goto P_0c09b584;
case 0x0c09b586u: goto P_0c09b586;
case 0x0c09b588u: goto P_0c09b588;
case 0x0c09b58au: goto P_0c09b58a;
case 0x0c09b58cu: goto P_0c09b58c;
case 0x0c09b58eu: goto P_0c09b58e;
case 0x0c09b590u: goto P_0c09b590;
case 0x0c09b592u: goto P_0c09b592;
case 0x0c09b594u: goto P_0c09b594;
case 0x0c09b596u: goto P_0c09b596;
case 0x0c09b598u: goto P_0c09b598;
case 0x0c09b59au: goto P_0c09b59a;
case 0x0c09b59cu: goto P_0c09b59c;
case 0x0c09b59eu: goto P_0c09b59e;
case 0x0c09b5a0u: goto P_0c09b5a0;
case 0x0c09b5a2u: goto P_0c09b5a2;
case 0x0c09b5a4u: goto P_0c09b5a4;
case 0x0c09b5a6u: goto P_0c09b5a6;
case 0x0c09b5a8u: goto P_0c09b5a8;
case 0x0c09b5aau: goto P_0c09b5aa;
case 0x0c09b5acu: goto P_0c09b5ac;
case 0x0c09b5aeu: goto P_0c09b5ae;
case 0x0c09b5b0u: goto P_0c09b5b0;
case 0x0c09b5b2u: goto P_0c09b5b2;
case 0x0c09b5b4u: goto P_0c09b5b4;
case 0x0c09b5b6u: goto P_0c09b5b6;
case 0x0c09b5b8u: goto P_0c09b5b8;
case 0x0c09b5bau: goto P_0c09b5ba;
case 0x0c09b5bcu: goto P_0c09b5bc;
case 0x0c09b5beu: goto P_0c09b5be;
case 0x0c09b5c0u: goto P_0c09b5c0;
case 0x0c09b5c2u: goto P_0c09b5c2;
case 0x0c09b5c4u: goto P_0c09b5c4;
case 0x0c09b5c6u: goto P_0c09b5c6;
case 0x0c09b5c8u: goto P_0c09b5c8;
case 0x0c09b5cau: goto P_0c09b5ca;
case 0x0c09b5ccu: goto P_0c09b5cc;
case 0x0c09b5ceu: goto P_0c09b5ce;
case 0x0c09b5d0u: goto P_0c09b5d0;
case 0x0c09b5d2u: goto P_0c09b5d2;
case 0x0c09b5d4u: goto P_0c09b5d4;
case 0x0c09b5d6u: goto P_0c09b5d6;
case 0x0c09b5d8u: goto P_0c09b5d8;
case 0x0c09b5dau: goto P_0c09b5da;
case 0x0c09b5dcu: goto P_0c09b5dc;
case 0x0c09b5deu: goto P_0c09b5de;
case 0x0c09b5e0u: goto P_0c09b5e0;
case 0x0c09b5e2u: goto P_0c09b5e2;
case 0x0c09b5e4u: goto P_0c09b5e4;
case 0x0c09b5e6u: goto P_0c09b5e6;
case 0x0c09b5e8u: goto P_0c09b5e8;
case 0x0c09b5eau: goto P_0c09b5ea;
case 0x0c09b5ecu: goto P_0c09b5ec;
case 0x0c09b5eeu: goto P_0c09b5ee;
case 0x0c09b5f0u: goto P_0c09b5f0;
case 0x0c09b5f2u: goto P_0c09b5f2;
case 0x0c09b5f4u: goto P_0c09b5f4;
case 0x0c09b614u: goto P_0c09b614;
case 0x0c09b616u: goto P_0c09b616;
case 0x0c09b618u: goto P_0c09b618;
case 0x0c09b61au: goto P_0c09b61a;
case 0x0c09b61cu: goto P_0c09b61c;
case 0x0c09b61eu: goto P_0c09b61e;
case 0x0c09b620u: goto P_0c09b620;
case 0x0c09b622u: goto P_0c09b622;
case 0x0c09b624u: goto P_0c09b624;
case 0x0c09b626u: goto P_0c09b626;
case 0x0c09b628u: goto P_0c09b628;
case 0x0c09b62au: goto P_0c09b62a;
case 0x0c09b62cu: goto P_0c09b62c;
case 0x0c09b62eu: goto P_0c09b62e;
case 0x0c09b630u: goto P_0c09b630;
case 0x0c09b632u: goto P_0c09b632;
case 0x0c09b634u: goto P_0c09b634;
case 0x0c09b636u: goto P_0c09b636;
case 0x0c09b638u: goto P_0c09b638;
case 0x0c09b63au: goto P_0c09b63a;
case 0x0c09b63cu: goto P_0c09b63c;
case 0x0c09b63eu: goto P_0c09b63e;
case 0x0c09b640u: goto P_0c09b640;
case 0x0c09b642u: goto P_0c09b642;
case 0x0c09b644u: goto P_0c09b644;
case 0x0c09b646u: goto P_0c09b646;
case 0x0c09b648u: goto P_0c09b648;
case 0x0c09b64au: goto P_0c09b64a;
case 0x0c09b64cu: goto P_0c09b64c;
case 0x0c09b64eu: goto P_0c09b64e;
case 0x0c09b650u: goto P_0c09b650;
case 0x0c09b652u: goto P_0c09b652;
case 0x0c09b654u: goto P_0c09b654;
case 0x0c09b656u: goto P_0c09b656;
case 0x0c09b658u: goto P_0c09b658;
case 0x0c09b65au: goto P_0c09b65a;
case 0x0c09b65cu: goto P_0c09b65c;
case 0x0c09b65eu: goto P_0c09b65e;
case 0x0c09b660u: goto P_0c09b660;
case 0x0c09b662u: goto P_0c09b662;
case 0x0c09b664u: goto P_0c09b664;
case 0x0c09b666u: goto P_0c09b666;
case 0x0c09b668u: goto P_0c09b668;
case 0x0c09b66au: goto P_0c09b66a;
case 0x0c09b66cu: goto P_0c09b66c;
case 0x0c09b66eu: goto P_0c09b66e;
case 0x0c09b670u: goto P_0c09b670;
case 0x0c09b672u: goto P_0c09b672;
case 0x0c09b674u: goto P_0c09b674;
case 0x0c09b676u: goto P_0c09b676;
case 0x0c09b678u: goto P_0c09b678;
case 0x0c09b67au: goto P_0c09b67a;
case 0x0c09b67cu: goto P_0c09b67c;
case 0x0c09b67eu: goto P_0c09b67e;
case 0x0c09b680u: goto P_0c09b680;
case 0x0c09b682u: goto P_0c09b682;
case 0x0c09b684u: goto P_0c09b684;
case 0x0c09b686u: goto P_0c09b686;
case 0x0c09b688u: goto P_0c09b688;
case 0x0c09b68au: goto P_0c09b68a;
case 0x0c09b68cu: goto P_0c09b68c;
case 0x0c09b68eu: goto P_0c09b68e;
case 0x0c09b690u: goto P_0c09b690;
case 0x0c09b692u: goto P_0c09b692;
case 0x0c09b694u: goto P_0c09b694;
case 0x0c09b696u: goto P_0c09b696;
case 0x0c09b698u: goto P_0c09b698;
case 0x0c09b69au: goto P_0c09b69a;
default: return vf3_matrix_family(target,s,ram);
}
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09afd0u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09afe2u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09aff6u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c09b006u,s,ram);
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
target=0x0c09af6cu; r[16]=code_base|0x0c09b05cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b05cu) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b068u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b070u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c09b11au,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b144u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b17au) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b1e2u) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c09b1f4u,s,ram);
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b226u) { target=s->pc; goto dispatch; }
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
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b25cu) { target=s->pc; goto dispatch; }
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
P_0c09b37e: /* original 4f22, guest PC 0x0c09b37e */
if(!s->budget--) { s->failed_pc=0x0c09b37eu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c09b380;
P_0c09b380: /* original da33, guest PC 0x0c09b380 */
if(!s->budget--) { s->failed_pc=0x0c09b380u; return 0; }
r[10]=read(ram,0x0c09b450u,4);
goto P_0c09b382;
P_0c09b382: /* original de34, guest PC 0x0c09b382 */
if(!s->budget--) { s->failed_pc=0x0c09b382u; return 0; }
r[14]=read(ram,0x0c09b454u,4);
goto P_0c09b384;
P_0c09b384: /* original d334, guest PC 0x0c09b384 */
if(!s->budget--) { s->failed_pc=0x0c09b384u; return 0; }
r[3]=read(ram,0x0c09b458u,4);
goto P_0c09b386;
P_0c09b386: /* original 7ffc, guest PC 0x0c09b386 */
if(!s->budget--) { s->failed_pc=0x0c09b386u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c09b388;
P_0c09b388: /* original 985c, guest PC 0x0c09b388 */
if(!s->budget--) { s->failed_pc=0x0c09b388u; return 0; }
r[8]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b444u,2);
goto P_0c09b38a;
P_0c09b38a: /* original bdef, guest PC 0x0c09b38a */
if(!s->budget--) { s->failed_pc=0x0c09b38au; return 0; }
target=0x0c09af6cu; r[16]=code_base|0x0c09b38eu;
write(ram,r[15],r[3],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b38eu) { target=s->pc; goto dispatch; }
goto P_0c09b38e;
P_0c09b38c: /* original 2f32, guest PC 0x0c09b38c */
if(!s->budget--) { s->failed_pc=0x0c09b38cu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c09b38e;
P_0c09b38e: /* original 6c03, guest PC 0x0c09b38e */
if(!s->budget--) { s->failed_pc=0x0c09b38eu; return 0; }
r[12]=r[0];
goto P_0c09b390;
P_0c09b390: /* original e07d, guest PC 0x0c09b390 */
if(!s->budget--) { s->failed_pc=0x0c09b390u; return 0; }
r[0]=0x0000007du;
goto P_0c09b392;
P_0c09b392: /* original 1ed6, guest PC 0x0c09b392 */
if(!s->budget--) { s->failed_pc=0x0c09b392u; return 0; }
write(ram,r[14]+24,r[13],4);
goto P_0c09b394;
P_0c09b394: /* original 0ed4, guest PC 0x0c09b394 */
if(!s->budget--) { s->failed_pc=0x0c09b394u; return 0; }
write(ram,r[14]+r[0],r[13],1);
goto P_0c09b396;
P_0c09b396: /* original 1ed5, guest PC 0x0c09b396 */
if(!s->budget--) { s->failed_pc=0x0c09b396u; return 0; }
write(ram,r[14]+20,r[13],4);
goto P_0c09b398;
P_0c09b398: /* original 53e3, guest PC 0x0c09b398 */
if(!s->budget--) { s->failed_pc=0x0c09b398u; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c09b39a;
P_0c09b39a: /* original 4315, guest PC 0x0c09b39a */
if(!s->budget--) { s->failed_pc=0x0c09b39au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09b39c;
P_0c09b39c: /* original 8b01, guest PC 0x0c09b39c */
if(!s->budget--) { s->failed_pc=0x0c09b39cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3a2; }
goto P_0c09b39e;
P_0c09b39e: /* original a173, guest PC 0x0c09b39e */
if(!s->budget--) { s->failed_pc=0x0c09b39eu; return 0; }
goto P_0c09b688;
P_0c09b3a0: /* original 0009, guest PC 0x0c09b3a0 */
if(!s->budget--) { s->failed_pc=0x0c09b3a0u; return 0; }
goto P_0c09b3a2;
P_0c09b3a2: /* original e340, guest PC 0x0c09b3a2 */
if(!s->budget--) { s->failed_pc=0x0c09b3a2u; return 0; }
r[3]=0x00000040u;
goto P_0c09b3a4;
P_0c09b3a4: /* original 23c8, guest PC 0x0c09b3a4 */
if(!s->budget--) { s->failed_pc=0x0c09b3a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b3a6;
P_0c09b3a6: /* original 8d21, guest PC 0x0c09b3a6 */
if(!s->budget--) { s->failed_pc=0x0c09b3a6u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+12,r[13],4);
if(cond) { goto P_0c09b3ec; }
goto P_0c09b3aa;
P_0c09b3a8: /* original 1ed3, guest PC 0x0c09b3a8 */
if(!s->budget--) { s->failed_pc=0x0c09b3a8u; return 0; }
write(ram,r[14]+12,r[13],4);
goto P_0c09b3aa;
P_0c09b3aa: /* original 4a0b, guest PC 0x0c09b3aa */
if(!s->budget--) { s->failed_pc=0x0c09b3aau; return 0; }
target=r[10];
r[16]=code_base|0x0c09b3aeu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b3aeu) { target=s->pc; goto dispatch; }
goto P_0c09b3ae;
P_0c09b3ac: /* original 6483, guest PC 0x0c09b3ac */
if(!s->budget--) { s->failed_pc=0x0c09b3acu; return 0; }
r[4]=r[8];
goto P_0c09b3ae;
P_0c09b3ae: /* original 904a, guest PC 0x0c09b3ae */
if(!s->budget--) { s->failed_pc=0x0c09b3aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3b0;
P_0c09b3b0: /* original 03ee, guest PC 0x0c09b3b0 */
if(!s->budget--) { s->failed_pc=0x0c09b3b0u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b3b2;
P_0c09b3b2: /* original 73ff, guest PC 0x0c09b3b2 */
if(!s->budget--) { s->failed_pc=0x0c09b3b2u; return 0; }
r[3]+=0xffffffffu;
goto P_0c09b3b4;
P_0c09b3b4: /* original 0e36, guest PC 0x0c09b3b4 */
if(!s->budget--) { s->failed_pc=0x0c09b3b4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3b6;
P_0c09b3b6: /* original 02ee, guest PC 0x0c09b3b6 */
if(!s->budget--) { s->failed_pc=0x0c09b3b6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b3b8;
P_0c09b3b8: /* original 4211, guest PC 0x0c09b3b8 */
if(!s->budget--) { s->failed_pc=0x0c09b3b8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=0)!=0);
goto P_0c09b3ba;
P_0c09b3ba: /* original 890d, guest PC 0x0c09b3ba */
if(!s->budget--) { s->failed_pc=0x0c09b3bau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b3d8; }
goto P_0c09b3bc;
P_0c09b3bc: /* original 9044, guest PC 0x0c09b3bc */
if(!s->budget--) { s->failed_pc=0x0c09b3bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b448u,2);
goto P_0c09b3be;
P_0c09b3be: /* original 00ee, guest PC 0x0c09b3be */
if(!s->budget--) { s->failed_pc=0x0c09b3beu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b3c0;
P_0c09b3c0: /* original 8802, guest PC 0x0c09b3c0 */
if(!s->budget--) { s->failed_pc=0x0c09b3c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b3c2;
P_0c09b3c2: /* original 8b07, guest PC 0x0c09b3c2 */
if(!s->budget--) { s->failed_pc=0x0c09b3c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3d4; }
goto P_0c09b3c4;
P_0c09b3c4: /* original 9041, guest PC 0x0c09b3c4 */
if(!s->budget--) { s->failed_pc=0x0c09b3c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44au,2);
goto P_0c09b3c6;
P_0c09b3c6: /* original 02ee, guest PC 0x0c09b3c6 */
if(!s->budget--) { s->failed_pc=0x0c09b3c6u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b3c8;
P_0c09b3c8: /* original 2228, guest PC 0x0c09b3c8 */
if(!s->budget--) { s->failed_pc=0x0c09b3c8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c09b3ca;
P_0c09b3ca: /* original 8b03, guest PC 0x0c09b3ca */
if(!s->budget--) { s->failed_pc=0x0c09b3cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3d4; }
goto P_0c09b3cc;
P_0c09b3cc: /* original 903b, guest PC 0x0c09b3cc */
if(!s->budget--) { s->failed_pc=0x0c09b3ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3ce;
P_0c09b3ce: /* original e306, guest PC 0x0c09b3ce */
if(!s->budget--) { s->failed_pc=0x0c09b3ceu; return 0; }
r[3]=0x00000006u;
goto P_0c09b3d0;
P_0c09b3d0: /* original a002, guest PC 0x0c09b3d0 */
if(!s->budget--) { s->failed_pc=0x0c09b3d0u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3d8;
P_0c09b3d2: /* original 0e36, guest PC 0x0c09b3d2 */
if(!s->budget--) { s->failed_pc=0x0c09b3d2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3d4;
P_0c09b3d4: /* original 9037, guest PC 0x0c09b3d4 */
if(!s->budget--) { s->failed_pc=0x0c09b3d4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3d6;
P_0c09b3d6: /* original 0eb6, guest PC 0x0c09b3d6 */
if(!s->budget--) { s->failed_pc=0x0c09b3d6u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b3d8;
P_0c09b3d8: /* original 9038, guest PC 0x0c09b3d8 */
if(!s->budget--) { s->failed_pc=0x0c09b3d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b3da;
P_0c09b3da: /* original 00ee, guest PC 0x0c09b3da */
if(!s->budget--) { s->failed_pc=0x0c09b3dau; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b3dc;
P_0c09b3dc: /* original 8803, guest PC 0x0c09b3dc */
if(!s->budget--) { s->failed_pc=0x0c09b3dcu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c09b3de;
P_0c09b3de: /* original 8b03, guest PC 0x0c09b3de */
if(!s->budget--) { s->failed_pc=0x0c09b3deu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b3e8; }
goto P_0c09b3e0;
P_0c09b3e0: /* original 9034, guest PC 0x0c09b3e0 */
if(!s->budget--) { s->failed_pc=0x0c09b3e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b3e2;
P_0c09b3e2: /* original e204, guest PC 0x0c09b3e2 */
if(!s->budget--) { s->failed_pc=0x0c09b3e2u; return 0; }
r[2]=0x00000004u;
goto P_0c09b3e4;
P_0c09b3e4: /* original a002, guest PC 0x0c09b3e4 */
if(!s->budget--) { s->failed_pc=0x0c09b3e4u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b3ec;
P_0c09b3e6: /* original 0e26, guest PC 0x0c09b3e6 */
if(!s->budget--) { s->failed_pc=0x0c09b3e6u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b3e8;
P_0c09b3e8: /* original 9030, guest PC 0x0c09b3e8 */
if(!s->budget--) { s->failed_pc=0x0c09b3e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b3ea;
P_0c09b3ea: /* original 0ed6, guest PC 0x0c09b3ea */
if(!s->budget--) { s->failed_pc=0x0c09b3eau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b3ec;
P_0c09b3ec: /* original 932f, guest PC 0x0c09b3ec */
if(!s->budget--) { s->failed_pc=0x0c09b3ecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44eu,2);
goto P_0c09b3ee;
P_0c09b3ee: /* original 23c8, guest PC 0x0c09b3ee */
if(!s->budget--) { s->failed_pc=0x0c09b3eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b3f0;
P_0c09b3f0: /* original 8936, guest PC 0x0c09b3f0 */
if(!s->budget--) { s->failed_pc=0x0c09b3f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b460; }
goto P_0c09b3f2;
P_0c09b3f2: /* original 4a0b, guest PC 0x0c09b3f2 */
if(!s->budget--) { s->failed_pc=0x0c09b3f2u; return 0; }
target=r[10];
r[16]=code_base|0x0c09b3f6u;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b3f6u) { target=s->pc; goto dispatch; }
goto P_0c09b3f6;
P_0c09b3f4: /* original 6483, guest PC 0x0c09b3f4 */
if(!s->budget--) { s->failed_pc=0x0c09b3f4u; return 0; }
r[4]=r[8];
goto P_0c09b3f6;
P_0c09b3f6: /* original 9026, guest PC 0x0c09b3f6 */
if(!s->budget--) { s->failed_pc=0x0c09b3f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b3f8;
P_0c09b3f8: /* original 03ee, guest PC 0x0c09b3f8 */
if(!s->budget--) { s->failed_pc=0x0c09b3f8u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b3fa;
P_0c09b3fa: /* original 7301, guest PC 0x0c09b3fa */
if(!s->budget--) { s->failed_pc=0x0c09b3fau; return 0; }
r[3]+=0x00000001u;
goto P_0c09b3fc;
P_0c09b3fc: /* original 0e36, guest PC 0x0c09b3fc */
if(!s->budget--) { s->failed_pc=0x0c09b3fcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b3fe;
P_0c09b3fe: /* original 70fc, guest PC 0x0c09b3fe */
if(!s->budget--) { s->failed_pc=0x0c09b3feu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b400;
P_0c09b400: /* original 00ee, guest PC 0x0c09b400 */
if(!s->budget--) { s->failed_pc=0x0c09b400u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b402;
P_0c09b402: /* original 8802, guest PC 0x0c09b402 */
if(!s->budget--) { s->failed_pc=0x0c09b402u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b404;
P_0c09b404: /* original 8905, guest PC 0x0c09b404 */
if(!s->budget--) { s->failed_pc=0x0c09b404u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b412; }
goto P_0c09b406;
P_0c09b406: /* original 901e, guest PC 0x0c09b406 */
if(!s->budget--) { s->failed_pc=0x0c09b406u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b408;
P_0c09b408: /* original 02ee, guest PC 0x0c09b408 */
if(!s->budget--) { s->failed_pc=0x0c09b408u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b40a;
P_0c09b40a: /* original 32b7, guest PC 0x0c09b40a */
if(!s->budget--) { s->failed_pc=0x0c09b40au; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c09b40c;
P_0c09b40c: /* original 8910, guest PC 0x0c09b40c */
if(!s->budget--) { s->failed_pc=0x0c09b40cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b430; }
goto P_0c09b40e;
P_0c09b40e: /* original a011, guest PC 0x0c09b40e */
if(!s->budget--) { s->failed_pc=0x0c09b40eu; return 0; }
goto P_0c09b434;
P_0c09b410: /* original 0009, guest PC 0x0c09b410 */
if(!s->budget--) { s->failed_pc=0x0c09b410u; return 0; }
goto P_0c09b412;
P_0c09b412: /* original 901a, guest PC 0x0c09b412 */
if(!s->budget--) { s->failed_pc=0x0c09b412u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44au,2);
goto P_0c09b414;
P_0c09b414: /* original 03ee, guest PC 0x0c09b414 */
if(!s->budget--) { s->failed_pc=0x0c09b414u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b416;
P_0c09b416: /* original 2338, guest PC 0x0c09b416 */
if(!s->budget--) { s->failed_pc=0x0c09b416u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09b418;
P_0c09b418: /* original 8b06, guest PC 0x0c09b418 */
if(!s->budget--) { s->failed_pc=0x0c09b418u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b428; }
goto P_0c09b41a;
P_0c09b41a: /* original 9014, guest PC 0x0c09b41a */
if(!s->budget--) { s->failed_pc=0x0c09b41au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b41c;
P_0c09b41c: /* original e306, guest PC 0x0c09b41c */
if(!s->budget--) { s->failed_pc=0x0c09b41cu; return 0; }
r[3]=0x00000006u;
goto P_0c09b41e;
P_0c09b41e: /* original 01ee, guest PC 0x0c09b41e */
if(!s->budget--) { s->failed_pc=0x0c09b41eu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b420;
P_0c09b420: /* original 3137, guest PC 0x0c09b420 */
if(!s->budget--) { s->failed_pc=0x0c09b420u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c09b422;
P_0c09b422: /* original 8b07, guest PC 0x0c09b422 */
if(!s->budget--) { s->failed_pc=0x0c09b422u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b434; }
goto P_0c09b424;
P_0c09b424: /* original a004, guest PC 0x0c09b424 */
if(!s->budget--) { s->failed_pc=0x0c09b424u; return 0; }
goto P_0c09b430;
P_0c09b426: /* original 0009, guest PC 0x0c09b426 */
if(!s->budget--) { s->failed_pc=0x0c09b426u; return 0; }
goto P_0c09b428;
P_0c09b428: /* original 900d, guest PC 0x0c09b428 */
if(!s->budget--) { s->failed_pc=0x0c09b428u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b42a;
P_0c09b42a: /* original 03ee, guest PC 0x0c09b42a */
if(!s->budget--) { s->failed_pc=0x0c09b42au; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b42c;
P_0c09b42c: /* original 33b7, guest PC 0x0c09b42c */
if(!s->budget--) { s->failed_pc=0x0c09b42cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[11])!=0);
goto P_0c09b42e;
P_0c09b42e: /* original 8b01, guest PC 0x0c09b42e */
if(!s->budget--) { s->failed_pc=0x0c09b42eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b434; }
goto P_0c09b430;
P_0c09b430: /* original 9009, guest PC 0x0c09b430 */
if(!s->budget--) { s->failed_pc=0x0c09b430u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b446u,2);
goto P_0c09b432;
P_0c09b432: /* original 0ed6, guest PC 0x0c09b432 */
if(!s->budget--) { s->failed_pc=0x0c09b432u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b434;
P_0c09b434: /* original 900a, guest PC 0x0c09b434 */
if(!s->budget--) { s->failed_pc=0x0c09b434u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b436;
P_0c09b436: /* original 00ee, guest PC 0x0c09b436 */
if(!s->budget--) { s->failed_pc=0x0c09b436u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b438;
P_0c09b438: /* original 8802, guest PC 0x0c09b438 */
if(!s->budget--) { s->failed_pc=0x0c09b438u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b43a;
P_0c09b43a: /* original 8b0f, guest PC 0x0c09b43a */
if(!s->budget--) { s->failed_pc=0x0c09b43au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b45c; }
goto P_0c09b43c;
P_0c09b43c: /* original 9006, guest PC 0x0c09b43c */
if(!s->budget--) { s->failed_pc=0x0c09b43cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b44cu,2);
goto P_0c09b43e;
P_0c09b43e: /* original e203, guest PC 0x0c09b43e */
if(!s->budget--) { s->failed_pc=0x0c09b43eu; return 0; }
r[2]=0x00000003u;
goto P_0c09b440;
P_0c09b440: /* original a00e, guest PC 0x0c09b440 */
if(!s->budget--) { s->failed_pc=0x0c09b440u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b460;
P_0c09b442: /* original 0e26, guest PC 0x0c09b442 */
if(!s->budget--) { s->failed_pc=0x0c09b442u; return 0; }
write(ram,r[14]+r[0],r[2],4);
return vf3_matrix_family(0x0c09b444u,s,ram);
P_0c09b45c: /* original 906d, guest PC 0x0c09b45c */
if(!s->budget--) { s->failed_pc=0x0c09b45cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b45e;
P_0c09b45e: /* original 0ed6, guest PC 0x0c09b45e */
if(!s->budget--) { s->failed_pc=0x0c09b45eu; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b460;
P_0c09b460: /* original e330, guest PC 0x0c09b460 */
if(!s->budget--) { s->failed_pc=0x0c09b460u; return 0; }
r[3]=0x00000030u;
goto P_0c09b462;
P_0c09b462: /* original 23c8, guest PC 0x0c09b462 */
if(!s->budget--) { s->failed_pc=0x0c09b462u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b464;
P_0c09b464: /* original 8d1f, guest PC 0x0c09b464 */
if(!s->budget--) { s->failed_pc=0x0c09b464u; return 0; }
cond=r[17]&1u;
r[9]=0x00000020u;
if(cond) { goto P_0c09b4a6; }
goto P_0c09b468;
P_0c09b466: /* original e920, guest PC 0x0c09b466 */
if(!s->budget--) { s->failed_pc=0x0c09b466u; return 0; }
r[9]=0x00000020u;
goto P_0c09b468;
P_0c09b468: /* original 4a0b, guest PC 0x0c09b468 */
if(!s->budget--) { s->failed_pc=0x0c09b468u; return 0; }
target=r[10];
r[16]=code_base|0x0c09b46cu;
r[4]=r[8];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b46cu) { target=s->pc; goto dispatch; }
goto P_0c09b46c;
P_0c09b46a: /* original 6483, guest PC 0x0c09b46a */
if(!s->budget--) { s->failed_pc=0x0c09b46au; return 0; }
r[4]=r[8];
goto P_0c09b46c;
P_0c09b46c: /* original 9066, guest PC 0x0c09b46c */
if(!s->budget--) { s->failed_pc=0x0c09b46cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53cu,2);
goto P_0c09b46e;
P_0c09b46e: /* original e401, guest PC 0x0c09b46e */
if(!s->budget--) { s->failed_pc=0x0c09b46eu; return 0; }
r[4]=0x00000001u;
goto P_0c09b470;
P_0c09b470: /* original 03ee, guest PC 0x0c09b470 */
if(!s->budget--) { s->failed_pc=0x0c09b470u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b472;
P_0c09b472: /* original 234a, guest PC 0x0c09b472 */
if(!s->budget--) { s->failed_pc=0x0c09b472u; return 0; }
r[3]^=r[4];
goto P_0c09b474;
P_0c09b474: /* original 0e36, guest PC 0x0c09b474 */
if(!s->budget--) { s->failed_pc=0x0c09b474u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b476;
P_0c09b476: /* original 00ee, guest PC 0x0c09b476 */
if(!s->budget--) { s->failed_pc=0x0c09b476u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b478;
P_0c09b478: /* original 8801, guest PC 0x0c09b478 */
if(!s->budget--) { s->failed_pc=0x0c09b478u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b47a;
P_0c09b47a: /* original 8b04, guest PC 0x0c09b47a */
if(!s->budget--) { s->failed_pc=0x0c09b47au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b486; }
goto P_0c09b47c;
P_0c09b47c: /* original 905f, guest PC 0x0c09b47c */
if(!s->budget--) { s->failed_pc=0x0c09b47cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53eu,2);
goto P_0c09b47e;
P_0c09b47e: /* original 02ee, guest PC 0x0c09b47e */
if(!s->budget--) { s->failed_pc=0x0c09b47eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b480;
P_0c09b480: /* original 32b7, guest PC 0x0c09b480 */
if(!s->budget--) { s->failed_pc=0x0c09b480u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[11])!=0);
goto P_0c09b482;
P_0c09b482: /* original 8b00, guest PC 0x0c09b482 */
if(!s->budget--) { s->failed_pc=0x0c09b482u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b486; }
goto P_0c09b484;
P_0c09b484: /* original 0eb6, guest PC 0x0c09b484 */
if(!s->budget--) { s->failed_pc=0x0c09b484u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b486;
P_0c09b486: /* original 63c3, guest PC 0x0c09b486 */
if(!s->budget--) { s->failed_pc=0x0c09b486u; return 0; }
r[3]=r[12];
goto P_0c09b488;
P_0c09b488: /* original 2398, guest PC 0x0c09b488 */
if(!s->budget--) { s->failed_pc=0x0c09b488u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c09b48a;
P_0c09b48a: /* original 8902, guest PC 0x0c09b48a */
if(!s->budget--) { s->failed_pc=0x0c09b48au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b492; }
goto P_0c09b48c;
P_0c09b48c: /* original 9055, guest PC 0x0c09b48c */
if(!s->budget--) { s->failed_pc=0x0c09b48cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b48e;
P_0c09b48e: /* original a00a, guest PC 0x0c09b48e */
if(!s->budget--) { s->failed_pc=0x0c09b48eu; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b4a6;
P_0c09b490: /* original 0e46, guest PC 0x0c09b490 */
if(!s->budget--) { s->failed_pc=0x0c09b490u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b492;
P_0c09b492: /* original 9052, guest PC 0x0c09b492 */
if(!s->budget--) { s->failed_pc=0x0c09b492u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b494;
P_0c09b494: /* original 00ee, guest PC 0x0c09b494 */
if(!s->budget--) { s->failed_pc=0x0c09b494u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b496;
P_0c09b496: /* original 8801, guest PC 0x0c09b496 */
if(!s->budget--) { s->failed_pc=0x0c09b496u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b498;
P_0c09b498: /* original 8b03, guest PC 0x0c09b498 */
if(!s->budget--) { s->failed_pc=0x0c09b498u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b4a2; }
goto P_0c09b49a;
P_0c09b49a: /* original 904e, guest PC 0x0c09b49a */
if(!s->budget--) { s->failed_pc=0x0c09b49au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b49c;
P_0c09b49c: /* original e202, guest PC 0x0c09b49c */
if(!s->budget--) { s->failed_pc=0x0c09b49cu; return 0; }
r[2]=0x00000002u;
goto P_0c09b49e;
P_0c09b49e: /* original a002, guest PC 0x0c09b49e */
if(!s->budget--) { s->failed_pc=0x0c09b49eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b4a6;
P_0c09b4a0: /* original 0e26, guest PC 0x0c09b4a0 */
if(!s->budget--) { s->failed_pc=0x0c09b4a0u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b4a2;
P_0c09b4a2: /* original 904a, guest PC 0x0c09b4a2 */
if(!s->budget--) { s->failed_pc=0x0c09b4a2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b4a4;
P_0c09b4a4: /* original 0ed6, guest PC 0x0c09b4a4 */
if(!s->budget--) { s->failed_pc=0x0c09b4a4u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b4a6;
P_0c09b4a6: /* original e308, guest PC 0x0c09b4a6 */
if(!s->budget--) { s->failed_pc=0x0c09b4a6u; return 0; }
r[3]=0x00000008u;
goto P_0c09b4a8;
P_0c09b4a8: /* original 23c8, guest PC 0x0c09b4a8 */
if(!s->budget--) { s->failed_pc=0x0c09b4a8u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[12])==0)!=0);
goto P_0c09b4aa;
P_0c09b4aa: /* original 8905, guest PC 0x0c09b4aa */
if(!s->budget--) { s->failed_pc=0x0c09b4aau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b4b8; }
goto P_0c09b4ac;
P_0c09b4ac: /* original 9045, guest PC 0x0c09b4ac */
if(!s->budget--) { s->failed_pc=0x0c09b4acu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b4ae;
P_0c09b4ae: /* original 00ee, guest PC 0x0c09b4ae */
if(!s->budget--) { s->failed_pc=0x0c09b4aeu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4b0;
P_0c09b4b0: /* original 8804, guest PC 0x0c09b4b0 */
if(!s->budget--) { s->failed_pc=0x0c09b4b0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c09b4b2;
P_0c09b4b2: /* original 8b01, guest PC 0x0c09b4b2 */
if(!s->budget--) { s->failed_pc=0x0c09b4b2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b4b8; }
goto P_0c09b4b4;
P_0c09b4b4: /* original 9041, guest PC 0x0c09b4b4 */
if(!s->budget--) { s->failed_pc=0x0c09b4b4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53au,2);
goto P_0c09b4b6;
P_0c09b4b6: /* original 0eb6, guest PC 0x0c09b4b6 */
if(!s->budget--) { s->failed_pc=0x0c09b4b6u; return 0; }
write(ram,r[14]+r[0],r[11],4);
goto P_0c09b4b8;
P_0c09b4b8: /* original 9042, guest PC 0x0c09b4b8 */
if(!s->budget--) { s->failed_pc=0x0c09b4b8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b540u,2);
goto P_0c09b4ba;
P_0c09b4ba: /* original d423, guest PC 0x0c09b4ba */
if(!s->budget--) { s->failed_pc=0x0c09b4bau; return 0; }
r[4]=read(ram,0x0c09b548u,4);
goto P_0c09b4bc;
P_0c09b4bc: /* original 03ee, guest PC 0x0c09b4bc */
if(!s->budget--) { s->failed_pc=0x0c09b4bcu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b4be;
P_0c09b4be: /* original 2338, guest PC 0x0c09b4be */
if(!s->budget--) { s->failed_pc=0x0c09b4beu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c09b4c0;
P_0c09b4c0: /* original 8f1c, guest PC 0x0c09b4c0 */
if(!s->budget--) { s->failed_pc=0x0c09b4c0u; return 0; }
cond=r[17]&1u;
r[5]=0x00000009u;
if(!cond) { goto P_0c09b4fc; }
goto P_0c09b4c4;
P_0c09b4c2: /* original e509, guest PC 0x0c09b4c2 */
if(!s->budget--) { s->failed_pc=0x0c09b4c2u; return 0; }
r[5]=0x00000009u;
goto P_0c09b4c4;
P_0c09b4c4: /* original 903a, guest PC 0x0c09b4c4 */
if(!s->budget--) { s->failed_pc=0x0c09b4c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53cu,2);
goto P_0c09b4c6;
P_0c09b4c6: /* original 923a, guest PC 0x0c09b4c6 */
if(!s->budget--) { s->failed_pc=0x0c09b4c6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53eu,2);
goto P_0c09b4c8;
P_0c09b4c8: /* original 00ee, guest PC 0x0c09b4c8 */
if(!s->budget--) { s->failed_pc=0x0c09b4c8u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4ca;
P_0c09b4ca: /* original 32ec, guest PC 0x0c09b4ca */
if(!s->budget--) { s->failed_pc=0x0c09b4cau; return 0; }
r[2]+=r[14];
goto P_0c09b4cc;
P_0c09b4cc: /* original 6303, guest PC 0x0c09b4cc */
if(!s->budget--) { s->failed_pc=0x0c09b4ccu; return 0; }
r[3]=r[0];
goto P_0c09b4ce;
P_0c09b4ce: /* original 4008, guest PC 0x0c09b4ce */
if(!s->budget--) { s->failed_pc=0x0c09b4ceu; return 0; }
r[0]<<=2;
goto P_0c09b4d0;
P_0c09b4d0: /* original 6222, guest PC 0x0c09b4d0 */
if(!s->budget--) { s->failed_pc=0x0c09b4d0u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c09b4d2;
P_0c09b4d2: /* original 4000, guest PC 0x0c09b4d2 */
if(!s->budget--) { s->failed_pc=0x0c09b4d2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c09b4d4;
P_0c09b4d4: /* original 3038, guest PC 0x0c09b4d4 */
if(!s->budget--) { s->failed_pc=0x0c09b4d4u; return 0; }
r[0]-=r[3];
goto P_0c09b4d6;
P_0c09b4d6: /* original 302c, guest PC 0x0c09b4d6 */
if(!s->budget--) { s->failed_pc=0x0c09b4d6u; return 0; }
r[0]+=r[2];
goto P_0c09b4d8;
P_0c09b4d8: /* original 034c, guest PC 0x0c09b4d8 */
if(!s->budget--) { s->failed_pc=0x0c09b4d8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09b4da;
P_0c09b4da: /* original 9032, guest PC 0x0c09b4da */
if(!s->budget--) { s->failed_pc=0x0c09b4dau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b542u,2);
goto P_0c09b4dc;
P_0c09b4dc: /* original 0e36, guest PC 0x0c09b4dc */
if(!s->budget--) { s->failed_pc=0x0c09b4dcu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b4de;
P_0c09b4de: /* original 700c, guest PC 0x0c09b4de */
if(!s->budget--) { s->failed_pc=0x0c09b4deu; return 0; }
r[0]+=0x0000000cu;
goto P_0c09b4e0;
P_0c09b4e0: /* original 00ee, guest PC 0x0c09b4e0 */
if(!s->budget--) { s->failed_pc=0x0c09b4e0u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4e2;
P_0c09b4e2: /* original 8805, guest PC 0x0c09b4e2 */
if(!s->budget--) { s->failed_pc=0x0c09b4e2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09b4e4;
P_0c09b4e4: /* original 8b01, guest PC 0x0c09b4e4 */
if(!s->budget--) { s->failed_pc=0x0c09b4e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b4ea; }
goto P_0c09b4e6;
P_0c09b4e6: /* original 902c, guest PC 0x0c09b4e6 */
if(!s->budget--) { s->failed_pc=0x0c09b4e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b542u,2);
goto P_0c09b4e8;
P_0c09b4e8: /* original 0e56, guest PC 0x0c09b4e8 */
if(!s->budget--) { s->failed_pc=0x0c09b4e8u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c09b4ea;
P_0c09b4ea: /* original bd69, guest PC 0x0c09b4ea */
if(!s->budget--) { s->failed_pc=0x0c09b4eau; return 0; }
target=0x0c09afc0u; r[16]=code_base|0x0c09b4eeu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b4eeu) { target=s->pc; goto dispatch; }
goto P_0c09b4ee;
P_0c09b4ec: /* original 0009, guest PC 0x0c09b4ec */
if(!s->budget--) { s->failed_pc=0x0c09b4ecu; return 0; }
goto P_0c09b4ee;
P_0c09b4ee: /* original c808, guest PC 0x0c09b4ee */
if(!s->budget--) { s->failed_pc=0x0c09b4eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09b4f0;
P_0c09b4f0: /* original 895d, guest PC 0x0c09b4f0 */
if(!s->budget--) { s->failed_pc=0x0c09b4f0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b5ae; }
goto P_0c09b4f2;
P_0c09b4f2: /* original 9026, guest PC 0x0c09b4f2 */
if(!s->budget--) { s->failed_pc=0x0c09b4f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b542u,2);
goto P_0c09b4f4;
P_0c09b4f4: /* original 03ee, guest PC 0x0c09b4f4 */
if(!s->budget--) { s->failed_pc=0x0c09b4f4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b4f6;
P_0c09b4f6: /* original 730d, guest PC 0x0c09b4f6 */
if(!s->budget--) { s->failed_pc=0x0c09b4f6u; return 0; }
r[3]+=0x0000000du;
goto P_0c09b4f8;
P_0c09b4f8: /* original a059, guest PC 0x0c09b4f8 */
if(!s->budget--) { s->failed_pc=0x0c09b4f8u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b5ae;
P_0c09b4fa: /* original 0e36, guest PC 0x0c09b4fa */
if(!s->budget--) { s->failed_pc=0x0c09b4fau; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b4fc;
P_0c09b4fc: /* original 00ee, guest PC 0x0c09b4fc */
if(!s->budget--) { s->failed_pc=0x0c09b4fcu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b4fe;
P_0c09b4fe: /* original 8801, guest PC 0x0c09b4fe */
if(!s->budget--) { s->failed_pc=0x0c09b4feu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b500;
P_0c09b500: /* original 8b24, guest PC 0x0c09b500 */
if(!s->budget--) { s->failed_pc=0x0c09b500u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b54c; }
goto P_0c09b502;
P_0c09b502: /* original 901b, guest PC 0x0c09b502 */
if(!s->budget--) { s->failed_pc=0x0c09b502u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53cu,2);
goto P_0c09b504;
P_0c09b504: /* original 921b, guest PC 0x0c09b504 */
if(!s->budget--) { s->failed_pc=0x0c09b504u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b53eu,2);
goto P_0c09b506;
P_0c09b506: /* original 00ee, guest PC 0x0c09b506 */
if(!s->budget--) { s->failed_pc=0x0c09b506u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b508;
P_0c09b508: /* original 32ec, guest PC 0x0c09b508 */
if(!s->budget--) { s->failed_pc=0x0c09b508u; return 0; }
r[2]+=r[14];
goto P_0c09b50a;
P_0c09b50a: /* original 6303, guest PC 0x0c09b50a */
if(!s->budget--) { s->failed_pc=0x0c09b50au; return 0; }
r[3]=r[0];
goto P_0c09b50c;
P_0c09b50c: /* original 4008, guest PC 0x0c09b50c */
if(!s->budget--) { s->failed_pc=0x0c09b50cu; return 0; }
r[0]<<=2;
goto P_0c09b50e;
P_0c09b50e: /* original 6222, guest PC 0x0c09b50e */
if(!s->budget--) { s->failed_pc=0x0c09b50eu; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c09b510;
P_0c09b510: /* original 4000, guest PC 0x0c09b510 */
if(!s->budget--) { s->failed_pc=0x0c09b510u; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c09b512;
P_0c09b512: /* original 3038, guest PC 0x0c09b512 */
if(!s->budget--) { s->failed_pc=0x0c09b512u; return 0; }
r[0]-=r[3];
goto P_0c09b514;
P_0c09b514: /* original 302c, guest PC 0x0c09b514 */
if(!s->budget--) { s->failed_pc=0x0c09b514u; return 0; }
r[0]+=r[2];
goto P_0c09b516;
P_0c09b516: /* original 034c, guest PC 0x0c09b516 */
if(!s->budget--) { s->failed_pc=0x0c09b516u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c09b518;
P_0c09b518: /* original 9014, guest PC 0x0c09b518 */
if(!s->budget--) { s->failed_pc=0x0c09b518u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b544u,2);
goto P_0c09b51a;
P_0c09b51a: /* original 0e36, guest PC 0x0c09b51a */
if(!s->budget--) { s->failed_pc=0x0c09b51au; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b51c;
P_0c09b51c: /* original 7008, guest PC 0x0c09b51c */
if(!s->budget--) { s->failed_pc=0x0c09b51cu; return 0; }
r[0]+=0x00000008u;
goto P_0c09b51e;
P_0c09b51e: /* original 00ee, guest PC 0x0c09b51e */
if(!s->budget--) { s->failed_pc=0x0c09b51eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b520;
P_0c09b520: /* original 8805, guest PC 0x0c09b520 */
if(!s->budget--) { s->failed_pc=0x0c09b520u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c09b522;
P_0c09b522: /* original 8b01, guest PC 0x0c09b522 */
if(!s->budget--) { s->failed_pc=0x0c09b522u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b528; }
goto P_0c09b524;
P_0c09b524: /* original 900e, guest PC 0x0c09b524 */
if(!s->budget--) { s->failed_pc=0x0c09b524u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b544u,2);
goto P_0c09b526;
P_0c09b526: /* original 0e56, guest PC 0x0c09b526 */
if(!s->budget--) { s->failed_pc=0x0c09b526u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c09b528;
P_0c09b528: /* original bd4a, guest PC 0x0c09b528 */
if(!s->budget--) { s->failed_pc=0x0c09b528u; return 0; }
target=0x0c09afc0u; r[16]=code_base|0x0c09b52cu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b52cu) { target=s->pc; goto dispatch; }
goto P_0c09b52c;
P_0c09b52a: /* original 0009, guest PC 0x0c09b52a */
if(!s->budget--) { s->failed_pc=0x0c09b52au; return 0; }
goto P_0c09b52c;
P_0c09b52c: /* original c808, guest PC 0x0c09b52c */
if(!s->budget--) { s->failed_pc=0x0c09b52cu; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09b52e;
P_0c09b52e: /* original 893e, guest PC 0x0c09b52e */
if(!s->budget--) { s->failed_pc=0x0c09b52eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b5ae; }
goto P_0c09b530;
P_0c09b530: /* original 9008, guest PC 0x0c09b530 */
if(!s->budget--) { s->failed_pc=0x0c09b530u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b544u,2);
goto P_0c09b532;
P_0c09b532: /* original 03ee, guest PC 0x0c09b532 */
if(!s->budget--) { s->failed_pc=0x0c09b532u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b534;
P_0c09b534: /* original 730d, guest PC 0x0c09b534 */
if(!s->budget--) { s->failed_pc=0x0c09b534u; return 0; }
r[3]+=0x0000000du;
goto P_0c09b536;
P_0c09b536: /* original a03a, guest PC 0x0c09b536 */
if(!s->budget--) { s->failed_pc=0x0c09b536u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b5ae;
P_0c09b538: /* original 0e36, guest PC 0x0c09b538 */
if(!s->budget--) { s->failed_pc=0x0c09b538u; return 0; }
write(ram,r[14]+r[0],r[3],4);
return vf3_matrix_family(0x0c09b53au,s,ram);
P_0c09b54c: /* original 9053, guest PC 0x0c09b54c */
if(!s->budget--) { s->failed_pc=0x0c09b54cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b54e;
P_0c09b54e: /* original 00ee, guest PC 0x0c09b54e */
if(!s->budget--) { s->failed_pc=0x0c09b54eu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b550;
P_0c09b550: /* original 8802, guest PC 0x0c09b550 */
if(!s->budget--) { s->failed_pc=0x0c09b550u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b552;
P_0c09b552: /* original 8b0d, guest PC 0x0c09b552 */
if(!s->budget--) { s->failed_pc=0x0c09b552u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b570; }
goto P_0c09b554;
P_0c09b554: /* original 9050, guest PC 0x0c09b554 */
if(!s->budget--) { s->failed_pc=0x0c09b554u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f8u,2);
goto P_0c09b556;
P_0c09b556: /* original 02ee, guest PC 0x0c09b556 */
if(!s->budget--) { s->failed_pc=0x0c09b556u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b558;
P_0c09b558: /* original 70fc, guest PC 0x0c09b558 */
if(!s->budget--) { s->failed_pc=0x0c09b558u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b55a;
P_0c09b55a: /* original 01ee, guest PC 0x0c09b55a */
if(!s->budget--) { s->failed_pc=0x0c09b55au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b55c;
P_0c09b55c: /* original 6323, guest PC 0x0c09b55c */
if(!s->budget--) { s->failed_pc=0x0c09b55cu; return 0; }
r[3]=r[2];
goto P_0c09b55e;
P_0c09b55e: /* original 4208, guest PC 0x0c09b55e */
if(!s->budget--) { s->failed_pc=0x0c09b55eu; return 0; }
r[2]<<=2;
goto P_0c09b560;
P_0c09b560: /* original 4200, guest PC 0x0c09b560 */
if(!s->budget--) { s->failed_pc=0x0c09b560u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c09b562;
P_0c09b562: /* original d028, guest PC 0x0c09b562 */
if(!s->budget--) { s->failed_pc=0x0c09b562u; return 0; }
r[0]=read(ram,0x0c09b604u,4);
goto P_0c09b564;
P_0c09b564: /* original 3238, guest PC 0x0c09b564 */
if(!s->budget--) { s->failed_pc=0x0c09b564u; return 0; }
r[2]-=r[3];
goto P_0c09b566;
P_0c09b566: /* original 321c, guest PC 0x0c09b566 */
if(!s->budget--) { s->failed_pc=0x0c09b566u; return 0; }
r[2]+=r[1];
goto P_0c09b568;
P_0c09b568: /* original 032c, guest PC 0x0c09b568 */
if(!s->budget--) { s->failed_pc=0x0c09b568u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c09b56a;
P_0c09b56a: /* original 9046, guest PC 0x0c09b56a */
if(!s->budget--) { s->failed_pc=0x0c09b56au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5fau,2);
goto P_0c09b56c;
P_0c09b56c: /* original a01f, guest PC 0x0c09b56c */
if(!s->budget--) { s->failed_pc=0x0c09b56cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b5ae;
P_0c09b56e: /* original 0e36, guest PC 0x0c09b56e */
if(!s->budget--) { s->failed_pc=0x0c09b56eu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b570;
P_0c09b570: /* original 9041, guest PC 0x0c09b570 */
if(!s->budget--) { s->failed_pc=0x0c09b570u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b572;
P_0c09b572: /* original e102, guest PC 0x0c09b572 */
if(!s->budget--) { s->failed_pc=0x0c09b572u; return 0; }
r[1]=0x00000002u;
goto P_0c09b574;
P_0c09b574: /* original 02ee, guest PC 0x0c09b574 */
if(!s->budget--) { s->failed_pc=0x0c09b574u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b576;
P_0c09b576: /* original 3217, guest PC 0x0c09b576 */
if(!s->budget--) { s->failed_pc=0x0c09b576u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>(int32_t)r[1])!=0);
goto P_0c09b578;
P_0c09b578: /* original 8b19, guest PC 0x0c09b578 */
if(!s->budget--) { s->failed_pc=0x0c09b578u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b5ae; }
goto P_0c09b57a;
P_0c09b57a: /* original 53e3, guest PC 0x0c09b57a */
if(!s->budget--) { s->failed_pc=0x0c09b57au; return 0; }
r[3]=read(ram,r[14]+12,4);
goto P_0c09b57c;
P_0c09b57c: /* original 4315, guest PC 0x0c09b57c */
if(!s->budget--) { s->failed_pc=0x0c09b57cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>0)!=0);
goto P_0c09b57e;
P_0c09b57e: /* original 8916, guest PC 0x0c09b57e */
if(!s->budget--) { s->failed_pc=0x0c09b57eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b5ae; }
goto P_0c09b580;
P_0c09b580: /* original 63f2, guest PC 0x0c09b580 */
if(!s->budget--) { s->failed_pc=0x0c09b580u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09b582;
P_0c09b582: /* original 7f04, guest PC 0x0c09b582 */
if(!s->budget--) { s->failed_pc=0x0c09b582u; return 0; }
r[15]+=0x00000004u;
goto P_0c09b584;
P_0c09b584: /* original 4f26, guest PC 0x0c09b584 */
if(!s->budget--) { s->failed_pc=0x0c09b584u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b586;
P_0c09b586: /* original e006, guest PC 0x0c09b586 */
if(!s->budget--) { s->failed_pc=0x0c09b586u; return 0; }
r[0]=0x00000006u;
goto P_0c09b588;
P_0c09b588: /* original 5132, guest PC 0x0c09b588 */
if(!s->budget--) { s->failed_pc=0x0c09b588u; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c09b58a;
P_0c09b58a: /* original d21f, guest PC 0x0c09b58a */
if(!s->budget--) { s->failed_pc=0x0c09b58au; return 0; }
r[2]=read(ram,0x0c09b608u,4);
goto P_0c09b58c;
P_0c09b58c: /* original 2129, guest PC 0x0c09b58c */
if(!s->budget--) { s->failed_pc=0x0c09b58cu; return 0; }
r[1]&=r[2];
goto P_0c09b58e;
P_0c09b58e: /* original 1312, guest PC 0x0c09b58e */
if(!s->budget--) { s->failed_pc=0x0c09b58eu; return 0; }
write(ram,r[3]+8,r[1],4);
goto P_0c09b590;
P_0c09b590: /* original 80ea, guest PC 0x0c09b590 */
if(!s->budget--) { s->failed_pc=0x0c09b590u; return 0; }
write(ram,r[14]+10,r[0],1);
goto P_0c09b592;
P_0c09b592: /* original 68f6, guest PC 0x0c09b592 */
if(!s->budget--) { s->failed_pc=0x0c09b592u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09b594;
P_0c09b594: /* original 9031, guest PC 0x0c09b594 */
if(!s->budget--) { s->failed_pc=0x0c09b594u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5fau,2);
goto P_0c09b596;
P_0c09b596: /* original 69f6, guest PC 0x0c09b596 */
if(!s->budget--) { s->failed_pc=0x0c09b596u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b598;
P_0c09b598: /* original 04ee, guest PC 0x0c09b598 */
if(!s->budget--) { s->failed_pc=0x0c09b598u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09b59a;
P_0c09b59a: /* original 6af6, guest PC 0x0c09b59a */
if(!s->budget--) { s->failed_pc=0x0c09b59au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b59c;
P_0c09b59c: /* original d01b, guest PC 0x0c09b59c */
if(!s->budget--) { s->failed_pc=0x0c09b59cu; return 0; }
r[0]=read(ram,0x0c09b60cu,4);
goto P_0c09b59e;
P_0c09b59e: /* original 4408, guest PC 0x0c09b59e */
if(!s->budget--) { s->failed_pc=0x0c09b59eu; return 0; }
r[4]<<=2;
goto P_0c09b5a0;
P_0c09b5a0: /* original 6bf6, guest PC 0x0c09b5a0 */
if(!s->budget--) { s->failed_pc=0x0c09b5a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b5a2;
P_0c09b5a2: /* original d31b, guest PC 0x0c09b5a2 */
if(!s->budget--) { s->failed_pc=0x0c09b5a2u; return 0; }
r[3]=read(ram,0x0c09b610u,4);
goto P_0c09b5a4;
P_0c09b5a4: /* original 6cf6, guest PC 0x0c09b5a4 */
if(!s->budget--) { s->failed_pc=0x0c09b5a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b5a6;
P_0c09b5a6: /* original 044e, guest PC 0x0c09b5a6 */
if(!s->budget--) { s->failed_pc=0x0c09b5a6u; return 0; }
r[4]=read(ram,r[4]+r[0],4);
goto P_0c09b5a8;
P_0c09b5a8: /* original 6df6, guest PC 0x0c09b5a8 */
if(!s->budget--) { s->failed_pc=0x0c09b5a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b5aa;
P_0c09b5aa: /* original 432b, guest PC 0x0c09b5aa */
if(!s->budget--) { s->failed_pc=0x0c09b5aau; return 0; }
target=r[3];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
switch(target&0x1fffffffu) {
case 0x0c03b450u: return vf3_matrix_family(target,s,ram);
case 0x0c03b4b0u: return vf3_matrix_family(target,s,ram);
case 0x0c03b530u: return vf3_matrix_family(target,s,ram);
case 0x0c03b620u: return vf3_matrix_family(target,s,ram);
case 0x0c03b820u: return vf3_matrix_family(target,s,ram);
case 0x0c03bd80u: return vf3_matrix_family(target,s,ram);
case 0x0c03c0e0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4a0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c4f0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c610u: return vf3_matrix_family(target,s,ram);
case 0x0c03c6c0u: return vf3_matrix_family(target,s,ram);
case 0x0c03c880u: return vf3_matrix_family(target,s,ram);
case 0x0c03c940u: return vf3_matrix_family(target,s,ram);
case 0x0c03c970u: return vf3_matrix_family(target,s,ram);
case 0x0c03cbd0u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc60u: return vf3_matrix_family(target,s,ram);
case 0x0c03cc90u: return vf3_matrix_family(target,s,ram);
case 0x0c03ccb0u: return vf3_matrix_family(target,s,ram);
default: goto dispatch; }
P_0c09b5ac: /* original 6ef6, guest PC 0x0c09b5ac */
if(!s->budget--) { s->failed_pc=0x0c09b5acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c09b5ae;
P_0c09b5ae: /* original e204, guest PC 0x0c09b5ae */
if(!s->budget--) { s->failed_pc=0x0c09b5aeu; return 0; }
r[2]=0x00000004u;
goto P_0c09b5b0;
P_0c09b5b0: /* original 22c8, guest PC 0x0c09b5b0 */
if(!s->budget--) { s->failed_pc=0x0c09b5b0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[12])==0)!=0);
goto P_0c09b5b2;
P_0c09b5b2: /* original 895c, guest PC 0x0c09b5b2 */
if(!s->budget--) { s->failed_pc=0x0c09b5b2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b66e; }
goto P_0c09b5b4;
P_0c09b5b4: /* original 9423, guest PC 0x0c09b5b4 */
if(!s->budget--) { s->failed_pc=0x0c09b5b4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5feu,2);
goto P_0c09b5b6;
P_0c09b5b6: /* original 9021, guest PC 0x0c09b5b6 */
if(!s->budget--) { s->failed_pc=0x0c09b5b6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5fcu,2);
goto P_0c09b5b8;
P_0c09b5b8: /* original 4a0b, guest PC 0x0c09b5b8 */
if(!s->budget--) { s->failed_pc=0x0c09b5b8u; return 0; }
target=r[10];
r[16]=code_base|0x0c09b5bcu;
write(ram,r[14]+r[0],r[13],4);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b5bcu) { target=s->pc; goto dispatch; }
goto P_0c09b5bc;
P_0c09b5ba: /* original 0ed6, guest PC 0x0c09b5ba */
if(!s->budget--) { s->failed_pc=0x0c09b5bau; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b5bc;
P_0c09b5bc: /* original 901b, guest PC 0x0c09b5bc */
if(!s->budget--) { s->failed_pc=0x0c09b5bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b5be;
P_0c09b5be: /* original 00ee, guest PC 0x0c09b5be */
if(!s->budget--) { s->failed_pc=0x0c09b5beu; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b5c0;
P_0c09b5c0: /* original 8802, guest PC 0x0c09b5c0 */
if(!s->budget--) { s->failed_pc=0x0c09b5c0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c09b5c2;
P_0c09b5c2: /* original 8927, guest PC 0x0c09b5c2 */
if(!s->budget--) { s->failed_pc=0x0c09b5c2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b614; }
goto P_0c09b5c4;
P_0c09b5c4: /* original 9017, guest PC 0x0c09b5c4 */
if(!s->budget--) { s->failed_pc=0x0c09b5c4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b5f6u,2);
goto P_0c09b5c6;
P_0c09b5c6: /* original 00ee, guest PC 0x0c09b5c6 */
if(!s->budget--) { s->failed_pc=0x0c09b5c6u; return 0; }
r[0]=read(ram,r[14]+r[0],4);
goto P_0c09b5c8;
P_0c09b5c8: /* original 8801, guest PC 0x0c09b5c8 */
if(!s->budget--) { s->failed_pc=0x0c09b5c8u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c09b5ca;
P_0c09b5ca: /* original 8b4a, guest PC 0x0c09b5ca */
if(!s->budget--) { s->failed_pc=0x0c09b5cau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b662; }
goto P_0c09b5cc;
P_0c09b5cc: /* original 9018, guest PC 0x0c09b5cc */
if(!s->budget--) { s->failed_pc=0x0c09b5ccu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b600u,2);
goto P_0c09b5ce;
P_0c09b5ce: /* original 02ee, guest PC 0x0c09b5ce */
if(!s->budget--) { s->failed_pc=0x0c09b5ceu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b5d0;
P_0c09b5d0: /* original 70fc, guest PC 0x0c09b5d0 */
if(!s->budget--) { s->failed_pc=0x0c09b5d0u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b5d2;
P_0c09b5d2: /* original 03ee, guest PC 0x0c09b5d2 */
if(!s->budget--) { s->failed_pc=0x0c09b5d2u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b5d4;
P_0c09b5d4: /* original 3320, guest PC 0x0c09b5d4 */
if(!s->budget--) { s->failed_pc=0x0c09b5d4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c09b5d6;
P_0c09b5d6: /* original 8b44, guest PC 0x0c09b5d6 */
if(!s->budget--) { s->failed_pc=0x0c09b5d6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b662; }
goto P_0c09b5d8;
P_0c09b5d8: /* original 9013, guest PC 0x0c09b5d8 */
if(!s->budget--) { s->failed_pc=0x0c09b5d8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b602u,2);
goto P_0c09b5da;
P_0c09b5da: /* original e30d, guest PC 0x0c09b5da */
if(!s->budget--) { s->failed_pc=0x0c09b5dau; return 0; }
r[3]=0x0000000du;
goto P_0c09b5dc;
P_0c09b5dc: /* original 01ee, guest PC 0x0c09b5dc */
if(!s->budget--) { s->failed_pc=0x0c09b5dcu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b5de;
P_0c09b5de: /* original 3133, guest PC 0x0c09b5de */
if(!s->budget--) { s->failed_pc=0x0c09b5deu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c09b5e0;
P_0c09b5e0: /* original 8b04, guest PC 0x0c09b5e0 */
if(!s->budget--) { s->failed_pc=0x0c09b5e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b5ec; }
goto P_0c09b5e2;
P_0c09b5e2: /* original 900d, guest PC 0x0c09b5e2 */
if(!s->budget--) { s->failed_pc=0x0c09b5e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b600u,2);
goto P_0c09b5e4;
P_0c09b5e4: /* original 02ee, guest PC 0x0c09b5e4 */
if(!s->budget--) { s->failed_pc=0x0c09b5e4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b5e6;
P_0c09b5e6: /* original 72f3, guest PC 0x0c09b5e6 */
if(!s->budget--) { s->failed_pc=0x0c09b5e6u; return 0; }
r[2]+=0xfffffff3u;
goto P_0c09b5e8;
P_0c09b5e8: /* original a03b, guest PC 0x0c09b5e8 */
if(!s->budget--) { s->failed_pc=0x0c09b5e8u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b662;
P_0c09b5ea: /* original 0e26, guest PC 0x0c09b5ea */
if(!s->budget--) { s->failed_pc=0x0c09b5eau; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b5ec;
P_0c09b5ec: /* original 9008, guest PC 0x0c09b5ec */
if(!s->budget--) { s->failed_pc=0x0c09b5ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b600u,2);
goto P_0c09b5ee;
P_0c09b5ee: /* original 02ee, guest PC 0x0c09b5ee */
if(!s->budget--) { s->failed_pc=0x0c09b5eeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b5f0;
P_0c09b5f0: /* original 332c, guest PC 0x0c09b5f0 */
if(!s->budget--) { s->failed_pc=0x0c09b5f0u; return 0; }
r[3]+=r[2];
goto P_0c09b5f2;
P_0c09b5f2: /* original a036, guest PC 0x0c09b5f2 */
if(!s->budget--) { s->failed_pc=0x0c09b5f2u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b662;
P_0c09b5f4: /* original 0e36, guest PC 0x0c09b5f4 */
if(!s->budget--) { s->failed_pc=0x0c09b5f4u; return 0; }
write(ram,r[14]+r[0],r[3],4);
return vf3_matrix_family(0x0c09b5f6u,s,ram);
P_0c09b614: /* original bcd4, guest PC 0x0c09b614 */
if(!s->budget--) { s->failed_pc=0x0c09b614u; return 0; }
target=0x0c09afc0u; r[16]=code_base|0x0c09b618u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b618u) { target=s->pc; goto dispatch; }
goto P_0c09b618;
P_0c09b616: /* original 0009, guest PC 0x0c09b616 */
if(!s->budget--) { s->failed_pc=0x0c09b616u; return 0; }
goto P_0c09b618;
P_0c09b618: /* original c808, guest PC 0x0c09b618 */
if(!s->budget--) { s->failed_pc=0x0c09b618u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c09b61a;
P_0c09b61a: /* original 8903, guest PC 0x0c09b61a */
if(!s->budget--) { s->failed_pc=0x0c09b61au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b624; }
goto P_0c09b61c;
P_0c09b61c: /* original 9079, guest PC 0x0c09b61c */
if(!s->budget--) { s->failed_pc=0x0c09b61cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b712u,2);
goto P_0c09b61e;
P_0c09b61e: /* original 02ee, guest PC 0x0c09b61e */
if(!s->budget--) { s->failed_pc=0x0c09b61eu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b620;
P_0c09b620: /* original 7210, guest PC 0x0c09b620 */
if(!s->budget--) { s->failed_pc=0x0c09b620u; return 0; }
r[2]+=0x00000010u;
goto P_0c09b622;
P_0c09b622: /* original 0e26, guest PC 0x0c09b622 */
if(!s->budget--) { s->failed_pc=0x0c09b622u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b624;
P_0c09b624: /* original bccc, guest PC 0x0c09b624 */
if(!s->budget--) { s->failed_pc=0x0c09b624u; return 0; }
target=0x0c09afc0u; r[16]=code_base|0x0c09b628u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c09b628u) { target=s->pc; goto dispatch; }
goto P_0c09b628;
P_0c09b626: /* original 0009, guest PC 0x0c09b626 */
if(!s->budget--) { s->failed_pc=0x0c09b626u; return 0; }
goto P_0c09b628;
P_0c09b628: /* original 9174, guest PC 0x0c09b628 */
if(!s->budget--) { s->failed_pc=0x0c09b628u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b714u,2);
goto P_0c09b62a;
P_0c09b62a: /* original 2018, guest PC 0x0c09b62a */
if(!s->budget--) { s->failed_pc=0x0c09b62au; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c09b62c;
P_0c09b62c: /* original 8903, guest PC 0x0c09b62c */
if(!s->budget--) { s->failed_pc=0x0c09b62cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b636; }
goto P_0c09b62e;
P_0c09b62e: /* original 9070, guest PC 0x0c09b62e */
if(!s->budget--) { s->failed_pc=0x0c09b62eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b712u,2);
goto P_0c09b630;
P_0c09b630: /* original 02ee, guest PC 0x0c09b630 */
if(!s->budget--) { s->failed_pc=0x0c09b630u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c09b632;
P_0c09b632: /* original 7210, guest PC 0x0c09b632 */
if(!s->budget--) { s->failed_pc=0x0c09b632u; return 0; }
r[2]+=0x00000010u;
goto P_0c09b634;
P_0c09b634: /* original 0e26, guest PC 0x0c09b634 */
if(!s->budget--) { s->failed_pc=0x0c09b634u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c09b636;
P_0c09b636: /* original 906c, guest PC 0x0c09b636 */
if(!s->budget--) { s->failed_pc=0x0c09b636u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b712u,2);
goto P_0c09b638;
P_0c09b638: /* original e330, guest PC 0x0c09b638 */
if(!s->budget--) { s->failed_pc=0x0c09b638u; return 0; }
r[3]=0x00000030u;
goto P_0c09b63a;
P_0c09b63a: /* original 01ee, guest PC 0x0c09b63a */
if(!s->budget--) { s->failed_pc=0x0c09b63au; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b63c;
P_0c09b63c: /* original 3137, guest PC 0x0c09b63c */
if(!s->budget--) { s->failed_pc=0x0c09b63cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>(int32_t)r[3])!=0);
goto P_0c09b63e;
P_0c09b63e: /* original 8b03, guest PC 0x0c09b63e */
if(!s->budget--) { s->failed_pc=0x0c09b63eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b648; }
goto P_0c09b640;
P_0c09b640: /* original 01ee, guest PC 0x0c09b640 */
if(!s->budget--) { s->failed_pc=0x0c09b640u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b642;
P_0c09b642: /* original e21f, guest PC 0x0c09b642 */
if(!s->budget--) { s->failed_pc=0x0c09b642u; return 0; }
r[2]=0x0000001fu;
goto P_0c09b644;
P_0c09b644: /* original 2129, guest PC 0x0c09b644 */
if(!s->budget--) { s->failed_pc=0x0c09b644u; return 0; }
r[1]&=r[2];
goto P_0c09b646;
P_0c09b646: /* original 0e16, guest PC 0x0c09b646 */
if(!s->budget--) { s->failed_pc=0x0c09b646u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b648;
P_0c09b648: /* original 63f2, guest PC 0x0c09b648 */
if(!s->budget--) { s->failed_pc=0x0c09b648u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c09b64a;
P_0c09b64a: /* original d234, guest PC 0x0c09b64a */
if(!s->budget--) { s->failed_pc=0x0c09b64au; return 0; }
r[2]=read(ram,0x0c09b71cu,4);
goto P_0c09b64c;
P_0c09b64c: /* original 5132, guest PC 0x0c09b64c */
if(!s->budget--) { s->failed_pc=0x0c09b64cu; return 0; }
r[1]=read(ram,r[3]+8,4);
goto P_0c09b64e;
P_0c09b64e: /* original 2128, guest PC 0x0c09b64e */
if(!s->budget--) { s->failed_pc=0x0c09b64eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c09b650;
P_0c09b650: /* original 8907, guest PC 0x0c09b650 */
if(!s->budget--) { s->failed_pc=0x0c09b650u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b662; }
goto P_0c09b652;
P_0c09b652: /* original 9060, guest PC 0x0c09b652 */
if(!s->budget--) { s->failed_pc=0x0c09b652u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b716u,2);
goto P_0c09b654;
P_0c09b654: /* original 04ee, guest PC 0x0c09b654 */
if(!s->budget--) { s->failed_pc=0x0c09b654u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c09b656;
P_0c09b656: /* original 7004, guest PC 0x0c09b656 */
if(!s->budget--) { s->failed_pc=0x0c09b656u; return 0; }
r[0]+=0x00000004u;
goto P_0c09b658;
P_0c09b658: /* original 03ee, guest PC 0x0c09b658 */
if(!s->budget--) { s->failed_pc=0x0c09b658u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b65a;
P_0c09b65a: /* original 70fc, guest PC 0x0c09b65a */
if(!s->budget--) { s->failed_pc=0x0c09b65au; return 0; }
r[0]+=0xfffffffcu;
goto P_0c09b65c;
P_0c09b65c: /* original 0e36, guest PC 0x0c09b65c */
if(!s->budget--) { s->failed_pc=0x0c09b65cu; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b65e;
P_0c09b65e: /* original 7004, guest PC 0x0c09b65e */
if(!s->budget--) { s->failed_pc=0x0c09b65eu; return 0; }
r[0]+=0x00000004u;
goto P_0c09b660;
P_0c09b660: /* original 0e46, guest PC 0x0c09b660 */
if(!s->budget--) { s->failed_pc=0x0c09b660u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c09b662;
P_0c09b662: /* original 9059, guest PC 0x0c09b662 */
if(!s->budget--) { s->failed_pc=0x0c09b662u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b718u,2);
goto P_0c09b664;
P_0c09b664: /* original 03ee, guest PC 0x0c09b664 */
if(!s->budget--) { s->failed_pc=0x0c09b664u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c09b666;
P_0c09b666: /* original 7301, guest PC 0x0c09b666 */
if(!s->budget--) { s->failed_pc=0x0c09b666u; return 0; }
r[3]+=0x00000001u;
goto P_0c09b668;
P_0c09b668: /* original 0e36, guest PC 0x0c09b668 */
if(!s->budget--) { s->failed_pc=0x0c09b668u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c09b66a;
P_0c09b66a: /* original a00d, guest PC 0x0c09b66a */
if(!s->budget--) { s->failed_pc=0x0c09b66au; return 0; }
write(ram,r[14]+12,r[9],4);
goto P_0c09b688;
P_0c09b66c: /* original 1e93, guest PC 0x0c09b66c */
if(!s->budget--) { s->failed_pc=0x0c09b66cu; return 0; }
write(ram,r[14]+12,r[9],4);
goto P_0c09b66e;
P_0c09b66e: /* original e302, guest PC 0x0c09b66e */
if(!s->budget--) { s->failed_pc=0x0c09b66eu; return 0; }
r[3]=0x00000002u;
goto P_0c09b670;
P_0c09b670: /* original 2c38, guest PC 0x0c09b670 */
if(!s->budget--) { s->failed_pc=0x0c09b670u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[3])==0)!=0);
goto P_0c09b672;
P_0c09b672: /* original 8909, guest PC 0x0c09b672 */
if(!s->budget--) { s->failed_pc=0x0c09b672u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c09b688; }
goto P_0c09b674;
P_0c09b674: /* original 9050, guest PC 0x0c09b674 */
if(!s->budget--) { s->failed_pc=0x0c09b674u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c09b718u,2);
goto P_0c09b676;
P_0c09b676: /* original 01ee, guest PC 0x0c09b676 */
if(!s->budget--) { s->failed_pc=0x0c09b676u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b678;
P_0c09b678: /* original 4115, guest PC 0x0c09b678 */
if(!s->budget--) { s->failed_pc=0x0c09b678u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>0)!=0);
goto P_0c09b67a;
P_0c09b67a: /* original 8b05, guest PC 0x0c09b67a */
if(!s->budget--) { s->failed_pc=0x0c09b67au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c09b688; }
goto P_0c09b67c;
P_0c09b67c: /* original 01ee, guest PC 0x0c09b67c */
if(!s->budget--) { s->failed_pc=0x0c09b67cu; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c09b67e;
P_0c09b67e: /* original 71ff, guest PC 0x0c09b67e */
if(!s->budget--) { s->failed_pc=0x0c09b67eu; return 0; }
r[1]+=0xffffffffu;
goto P_0c09b680;
P_0c09b680: /* original 0e16, guest PC 0x0c09b680 */
if(!s->budget--) { s->failed_pc=0x0c09b680u; return 0; }
write(ram,r[14]+r[0],r[1],4);
goto P_0c09b682;
P_0c09b682: /* original 7018, guest PC 0x0c09b682 */
if(!s->budget--) { s->failed_pc=0x0c09b682u; return 0; }
r[0]+=0x00000018u;
goto P_0c09b684;
P_0c09b684: /* original 1e93, guest PC 0x0c09b684 */
if(!s->budget--) { s->failed_pc=0x0c09b684u; return 0; }
write(ram,r[14]+12,r[9],4);
goto P_0c09b686;
P_0c09b686: /* original 0ed6, guest PC 0x0c09b686 */
if(!s->budget--) { s->failed_pc=0x0c09b686u; return 0; }
write(ram,r[14]+r[0],r[13],4);
goto P_0c09b688;
P_0c09b688: /* original 7f04, guest PC 0x0c09b688 */
if(!s->budget--) { s->failed_pc=0x0c09b688u; return 0; }
r[15]+=0x00000004u;
goto P_0c09b68a;
P_0c09b68a: /* original 4f26, guest PC 0x0c09b68a */
if(!s->budget--) { s->failed_pc=0x0c09b68au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c09b68c;
P_0c09b68c: /* original 68f6, guest PC 0x0c09b68c */
if(!s->budget--) { s->failed_pc=0x0c09b68cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c09b68e;
P_0c09b68e: /* original 69f6, guest PC 0x0c09b68e */
if(!s->budget--) { s->failed_pc=0x0c09b68eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c09b690;
P_0c09b690: /* original 6af6, guest PC 0x0c09b690 */
if(!s->budget--) { s->failed_pc=0x0c09b690u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c09b692;
P_0c09b692: /* original 6bf6, guest PC 0x0c09b692 */
if(!s->budget--) { s->failed_pc=0x0c09b692u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c09b694;
P_0c09b694: /* original 6cf6, guest PC 0x0c09b694 */
if(!s->budget--) { s->failed_pc=0x0c09b694u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c09b696;
P_0c09b696: /* original 6df6, guest PC 0x0c09b696 */
if(!s->budget--) { s->failed_pc=0x0c09b696u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c09b698;
P_0c09b698: /* original 000b, guest PC 0x0c09b698 */
if(!s->budget--) { s->failed_pc=0x0c09b698u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c09b69a: /* original 6ef6, guest PC 0x0c09b69a */
if(!s->budget--) { s->failed_pc=0x0c09b69au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c09b69cu,s,ram);
unsupported: s->failed_pc=target; return 0;
}
static const uint32_t owned_pcs[]={
0x0c09afc0u,0x0c09afc2u,0x0c09afc4u,0x0c09afc6u,0x0c09afc8u,0x0c09afcau,0x0c09afccu,0x0c09afceu,0x0c09afd0u,0x0c09afd2u,0x0c09afd4u,0x0c09afd6u,0x0c09afd8u,0x0c09afdau,0x0c09afdcu,0x0c09afdeu,
0x0c09afe0u,0x0c09afe2u,0x0c09afe4u,0x0c09afe6u,0x0c09afe8u,0x0c09afeau,0x0c09afecu,0x0c09afeeu,0x0c09aff0u,0x0c09aff2u,0x0c09aff4u,0x0c09aff6u,0x0c09aff8u,0x0c09affau,0x0c09affcu,0x0c09affeu,
0x0c09b000u,0x0c09b002u,0x0c09b004u,0x0c09b04eu,0x0c09b050u,0x0c09b052u,0x0c09b054u,0x0c09b056u,0x0c09b058u,0x0c09b05au,0x0c09b05cu,0x0c09b05eu,0x0c09b060u,0x0c09b062u,0x0c09b064u,0x0c09b066u,
0x0c09b068u,0x0c09b06au,0x0c09b06cu,0x0c09b06eu,0x0c09b070u,0x0c09b072u,0x0c09b074u,0x0c09b076u,0x0c09b078u,0x0c09b07au,0x0c09b07cu,0x0c09b07eu,0x0c09b080u,0x0c09b082u,0x0c09b084u,0x0c09b086u,
0x0c09b088u,0x0c09b08au,0x0c09b08cu,0x0c09b08eu,0x0c09b090u,0x0c09b092u,0x0c09b094u,0x0c09b096u,0x0c09b098u,0x0c09b09au,0x0c09b09cu,0x0c09b09eu,0x0c09b0a0u,0x0c09b0a2u,0x0c09b0a4u,0x0c09b0a6u,
0x0c09b0a8u,0x0c09b0aau,0x0c09b0acu,0x0c09b0aeu,0x0c09b0b0u,0x0c09b0b2u,0x0c09b0b4u,0x0c09b0b6u,0x0c09b0b8u,0x0c09b0bau,0x0c09b0bcu,0x0c09b0beu,0x0c09b0c0u,0x0c09b0c2u,0x0c09b0c4u,0x0c09b0c6u,
0x0c09b0c8u,0x0c09b0cau,0x0c09b0ccu,0x0c09b0ceu,0x0c09b0d0u,0x0c09b0d2u,0x0c09b0d4u,0x0c09b0d6u,0x0c09b0d8u,0x0c09b0dau,0x0c09b0dcu,0x0c09b0deu,0x0c09b0e0u,0x0c09b0e2u,0x0c09b0e4u,0x0c09b0e6u,
0x0c09b0e8u,0x0c09b0eau,0x0c09b0ecu,0x0c09b0eeu,0x0c09b0f0u,0x0c09b0f2u,0x0c09b0f4u,0x0c09b0f6u,0x0c09b0f8u,0x0c09b0fau,0x0c09b0fcu,0x0c09b0feu,0x0c09b100u,0x0c09b102u,0x0c09b104u,0x0c09b106u,
0x0c09b108u,0x0c09b10au,0x0c09b10cu,0x0c09b10eu,0x0c09b110u,0x0c09b112u,0x0c09b114u,0x0c09b116u,0x0c09b118u,0x0c09b138u,0x0c09b13au,0x0c09b13cu,0x0c09b13eu,0x0c09b140u,0x0c09b142u,0x0c09b144u,
0x0c09b146u,0x0c09b148u,0x0c09b14au,0x0c09b14cu,0x0c09b14eu,0x0c09b150u,0x0c09b152u,0x0c09b154u,0x0c09b156u,0x0c09b158u,0x0c09b15au,0x0c09b15cu,0x0c09b15eu,0x0c09b160u,0x0c09b162u,0x0c09b164u,
0x0c09b166u,0x0c09b168u,0x0c09b16au,0x0c09b16cu,0x0c09b16eu,0x0c09b170u,0x0c09b172u,0x0c09b174u,0x0c09b176u,0x0c09b178u,0x0c09b17au,0x0c09b17cu,0x0c09b17eu,0x0c09b180u,0x0c09b182u,0x0c09b184u,
0x0c09b186u,0x0c09b188u,0x0c09b18au,0x0c09b18cu,0x0c09b18eu,0x0c09b190u,0x0c09b192u,0x0c09b194u,0x0c09b196u,0x0c09b198u,0x0c09b19au,0x0c09b19cu,0x0c09b19eu,0x0c09b1a0u,0x0c09b1a2u,0x0c09b1a4u,
0x0c09b1a6u,0x0c09b1a8u,0x0c09b1aau,0x0c09b1acu,0x0c09b1aeu,0x0c09b1b0u,0x0c09b1b2u,0x0c09b1b4u,0x0c09b1b6u,0x0c09b1b8u,0x0c09b1bau,0x0c09b1bcu,0x0c09b1beu,0x0c09b1c0u,0x0c09b1c2u,0x0c09b1c4u,
0x0c09b1c6u,0x0c09b1c8u,0x0c09b1cau,0x0c09b1ccu,0x0c09b1ceu,0x0c09b1d0u,0x0c09b1d2u,0x0c09b1d4u,0x0c09b1d6u,0x0c09b1d8u,0x0c09b1dau,0x0c09b1dcu,0x0c09b1deu,0x0c09b1e0u,0x0c09b1e2u,0x0c09b1e4u,
0x0c09b1e6u,0x0c09b1e8u,0x0c09b1eau,0x0c09b1ecu,0x0c09b1eeu,0x0c09b1f0u,0x0c09b1f2u,0x0c09b218u,0x0c09b21au,0x0c09b21cu,0x0c09b21eu,0x0c09b220u,0x0c09b222u,0x0c09b224u,0x0c09b226u,0x0c09b228u,
0x0c09b22au,0x0c09b22cu,0x0c09b22eu,0x0c09b230u,0x0c09b232u,0x0c09b234u,0x0c09b236u,0x0c09b238u,0x0c09b23au,0x0c09b23cu,0x0c09b23eu,0x0c09b240u,0x0c09b242u,0x0c09b244u,0x0c09b246u,0x0c09b248u,
0x0c09b24au,0x0c09b24cu,0x0c09b24eu,0x0c09b250u,0x0c09b252u,0x0c09b254u,0x0c09b256u,0x0c09b258u,0x0c09b25au,0x0c09b25cu,0x0c09b25eu,0x0c09b260u,0x0c09b262u,0x0c09b264u,0x0c09b266u,0x0c09b268u,
0x0c09b26au,0x0c09b26cu,0x0c09b26eu,0x0c09b270u,0x0c09b272u,0x0c09b274u,0x0c09b276u,0x0c09b278u,0x0c09b27au,0x0c09b27cu,0x0c09b27eu,0x0c09b280u,0x0c09b282u,0x0c09b284u,0x0c09b286u,0x0c09b288u,
0x0c09b28au,0x0c09b28cu,0x0c09b28eu,0x0c09b290u,0x0c09b292u,0x0c09b294u,0x0c09b296u,0x0c09b37eu,0x0c09b380u,0x0c09b382u,0x0c09b384u,0x0c09b386u,0x0c09b388u,0x0c09b38au,0x0c09b38cu,0x0c09b38eu,
0x0c09b390u,0x0c09b392u,0x0c09b394u,0x0c09b396u,0x0c09b398u,0x0c09b39au,0x0c09b39cu,0x0c09b39eu,0x0c09b3a0u,0x0c09b3a2u,0x0c09b3a4u,0x0c09b3a6u,0x0c09b3a8u,0x0c09b3aau,0x0c09b3acu,0x0c09b3aeu,
0x0c09b3b0u,0x0c09b3b2u,0x0c09b3b4u,0x0c09b3b6u,0x0c09b3b8u,0x0c09b3bau,0x0c09b3bcu,0x0c09b3beu,0x0c09b3c0u,0x0c09b3c2u,0x0c09b3c4u,0x0c09b3c6u,0x0c09b3c8u,0x0c09b3cau,0x0c09b3ccu,0x0c09b3ceu,
0x0c09b3d0u,0x0c09b3d2u,0x0c09b3d4u,0x0c09b3d6u,0x0c09b3d8u,0x0c09b3dau,0x0c09b3dcu,0x0c09b3deu,0x0c09b3e0u,0x0c09b3e2u,0x0c09b3e4u,0x0c09b3e6u,0x0c09b3e8u,0x0c09b3eau,0x0c09b3ecu,0x0c09b3eeu,
0x0c09b3f0u,0x0c09b3f2u,0x0c09b3f4u,0x0c09b3f6u,0x0c09b3f8u,0x0c09b3fau,0x0c09b3fcu,0x0c09b3feu,0x0c09b400u,0x0c09b402u,0x0c09b404u,0x0c09b406u,0x0c09b408u,0x0c09b40au,0x0c09b40cu,0x0c09b40eu,
0x0c09b410u,0x0c09b412u,0x0c09b414u,0x0c09b416u,0x0c09b418u,0x0c09b41au,0x0c09b41cu,0x0c09b41eu,0x0c09b420u,0x0c09b422u,0x0c09b424u,0x0c09b426u,0x0c09b428u,0x0c09b42au,0x0c09b42cu,0x0c09b42eu,
0x0c09b430u,0x0c09b432u,0x0c09b434u,0x0c09b436u,0x0c09b438u,0x0c09b43au,0x0c09b43cu,0x0c09b43eu,0x0c09b440u,0x0c09b442u,0x0c09b45cu,0x0c09b45eu,0x0c09b460u,0x0c09b462u,0x0c09b464u,0x0c09b466u,
0x0c09b468u,0x0c09b46au,0x0c09b46cu,0x0c09b46eu,0x0c09b470u,0x0c09b472u,0x0c09b474u,0x0c09b476u,0x0c09b478u,0x0c09b47au,0x0c09b47cu,0x0c09b47eu,0x0c09b480u,0x0c09b482u,0x0c09b484u,0x0c09b486u,
0x0c09b488u,0x0c09b48au,0x0c09b48cu,0x0c09b48eu,0x0c09b490u,0x0c09b492u,0x0c09b494u,0x0c09b496u,0x0c09b498u,0x0c09b49au,0x0c09b49cu,0x0c09b49eu,0x0c09b4a0u,0x0c09b4a2u,0x0c09b4a4u,0x0c09b4a6u,
0x0c09b4a8u,0x0c09b4aau,0x0c09b4acu,0x0c09b4aeu,0x0c09b4b0u,0x0c09b4b2u,0x0c09b4b4u,0x0c09b4b6u,0x0c09b4b8u,0x0c09b4bau,0x0c09b4bcu,0x0c09b4beu,0x0c09b4c0u,0x0c09b4c2u,0x0c09b4c4u,0x0c09b4c6u,
0x0c09b4c8u,0x0c09b4cau,0x0c09b4ccu,0x0c09b4ceu,0x0c09b4d0u,0x0c09b4d2u,0x0c09b4d4u,0x0c09b4d6u,0x0c09b4d8u,0x0c09b4dau,0x0c09b4dcu,0x0c09b4deu,0x0c09b4e0u,0x0c09b4e2u,0x0c09b4e4u,0x0c09b4e6u,
0x0c09b4e8u,0x0c09b4eau,0x0c09b4ecu,0x0c09b4eeu,0x0c09b4f0u,0x0c09b4f2u,0x0c09b4f4u,0x0c09b4f6u,0x0c09b4f8u,0x0c09b4fau,0x0c09b4fcu,0x0c09b4feu,0x0c09b500u,0x0c09b502u,0x0c09b504u,0x0c09b506u,
0x0c09b508u,0x0c09b50au,0x0c09b50cu,0x0c09b50eu,0x0c09b510u,0x0c09b512u,0x0c09b514u,0x0c09b516u,0x0c09b518u,0x0c09b51au,0x0c09b51cu,0x0c09b51eu,0x0c09b520u,0x0c09b522u,0x0c09b524u,0x0c09b526u,
0x0c09b528u,0x0c09b52au,0x0c09b52cu,0x0c09b52eu,0x0c09b530u,0x0c09b532u,0x0c09b534u,0x0c09b536u,0x0c09b538u,0x0c09b54cu,0x0c09b54eu,0x0c09b550u,0x0c09b552u,0x0c09b554u,0x0c09b556u,0x0c09b558u,
0x0c09b55au,0x0c09b55cu,0x0c09b55eu,0x0c09b560u,0x0c09b562u,0x0c09b564u,0x0c09b566u,0x0c09b568u,0x0c09b56au,0x0c09b56cu,0x0c09b56eu,0x0c09b570u,0x0c09b572u,0x0c09b574u,0x0c09b576u,0x0c09b578u,
0x0c09b57au,0x0c09b57cu,0x0c09b57eu,0x0c09b580u,0x0c09b582u,0x0c09b584u,0x0c09b586u,0x0c09b588u,0x0c09b58au,0x0c09b58cu,0x0c09b58eu,0x0c09b590u,0x0c09b592u,0x0c09b594u,0x0c09b596u,0x0c09b598u,
0x0c09b59au,0x0c09b59cu,0x0c09b59eu,0x0c09b5a0u,0x0c09b5a2u,0x0c09b5a4u,0x0c09b5a6u,0x0c09b5a8u,0x0c09b5aau,0x0c09b5acu,0x0c09b5aeu,0x0c09b5b0u,0x0c09b5b2u,0x0c09b5b4u,0x0c09b5b6u,0x0c09b5b8u,
0x0c09b5bau,0x0c09b5bcu,0x0c09b5beu,0x0c09b5c0u,0x0c09b5c2u,0x0c09b5c4u,0x0c09b5c6u,0x0c09b5c8u,0x0c09b5cau,0x0c09b5ccu,0x0c09b5ceu,0x0c09b5d0u,0x0c09b5d2u,0x0c09b5d4u,0x0c09b5d6u,0x0c09b5d8u,
0x0c09b5dau,0x0c09b5dcu,0x0c09b5deu,0x0c09b5e0u,0x0c09b5e2u,0x0c09b5e4u,0x0c09b5e6u,0x0c09b5e8u,0x0c09b5eau,0x0c09b5ecu,0x0c09b5eeu,0x0c09b5f0u,0x0c09b5f2u,0x0c09b5f4u,0x0c09b614u,0x0c09b616u,
0x0c09b618u,0x0c09b61au,0x0c09b61cu,0x0c09b61eu,0x0c09b620u,0x0c09b622u,0x0c09b624u,0x0c09b626u,0x0c09b628u,0x0c09b62au,0x0c09b62cu,0x0c09b62eu,0x0c09b630u,0x0c09b632u,0x0c09b634u,0x0c09b636u,
0x0c09b638u,0x0c09b63au,0x0c09b63cu,0x0c09b63eu,0x0c09b640u,0x0c09b642u,0x0c09b644u,0x0c09b646u,0x0c09b648u,0x0c09b64au,0x0c09b64cu,0x0c09b64eu,0x0c09b650u,0x0c09b652u,0x0c09b654u,0x0c09b656u,
0x0c09b658u,0x0c09b65au,0x0c09b65cu,0x0c09b65eu,0x0c09b660u,0x0c09b662u,0x0c09b664u,0x0c09b666u,0x0c09b668u,0x0c09b66au,0x0c09b66cu,0x0c09b66eu,0x0c09b670u,0x0c09b672u,0x0c09b674u,0x0c09b676u,
0x0c09b678u,0x0c09b67au,0x0c09b67cu,0x0c09b67eu,0x0c09b680u,0x0c09b682u,0x0c09b684u,0x0c09b686u,0x0c09b688u,0x0c09b68au,0x0c09b68cu,0x0c09b68eu,0x0c09b690u,0x0c09b692u,0x0c09b694u,0x0c09b696u,
0x0c09b698u,0x0c09b69au,
};
int vf3_09b_adapter_contains(uint32_t pc) {
pc&=0x1fffffffu; unsigned lo=0,hi=sizeof(owned_pcs)/sizeof(owned_pcs[0]);
while(lo<hi) { unsigned mid=lo+(hi-lo)/2; if(owned_pcs[mid]<pc) lo=mid+1; else hi=mid; }
return lo<sizeof(owned_pcs)/sizeof(owned_pcs[0]) && owned_pcs[lo]==pc;
}
