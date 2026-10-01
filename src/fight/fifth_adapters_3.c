/* Static C ABI adapters. Generated with tools/oracle/translate_adapters.py.
 * Matrix operations are hand-written in matrix_family.c; unknown code fails.
 * Executed opcodes are checked against the untouched identity image. */
#include "fight/matrix_family.h"
#include "fight/sh4_fpu.h"
#include <math.h>
#include <string.h>
#define read vf3_matrix_read
#define write vf3_matrix_write
static float as_float(uint32_t u) { float f; memcpy(&f,&u,4); return f; }
static uint32_t as_bits(float f) { uint32_t u; memcpy(&u,&f,4); return u; }
static uint32_t truncate_float(uint32_t u) { double d=as_float(u); if(isnan(d) || d< -2147483648.0) return 0x80000000u; if(d>=2147483648.0) return 0x7fffffffu; return (uint32_t)(int32_t)d; }
static void divide_step(vf3_matrix_state*s,unsigned n,unsigned m) { uint32_t *r=s->v; unsigned oldq=(r[17]>>8)&1u,sign=(r[17]>>9)&1u,q=r[n]>>31; uint32_t divisor=r[m],shifted=(r[n]<<1)|(r[17]&1u); r[n]=oldq==sign?shifted-divisor:shifted+divisor; unsigned carry=oldq==sign?r[n]>shifted:r[n]<shifted; q^=carry^sign; r[17]=(r[17]&~0x101u)|(q<<8)|(q==sign); }
int vf3_fifth_adapter_3(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c0abeb8u: goto P_0c0abeb8;
case 0x0c0abebau: goto P_0c0abeba;
case 0x0c0abebcu: goto P_0c0abebc;
case 0x0c0abebeu: goto P_0c0abebe;
case 0x0c0abec0u: goto P_0c0abec0;
case 0x0c0abec2u: goto P_0c0abec2;
case 0x0c0abec4u: goto P_0c0abec4;
case 0x0c0abec6u: goto P_0c0abec6;
case 0x0c0abec8u: goto P_0c0abec8;
case 0x0c0abecau: goto P_0c0abeca;
case 0x0c0abeccu: goto P_0c0abecc;
case 0x0c0abeceu: goto P_0c0abece;
case 0x0c0abed0u: goto P_0c0abed0;
case 0x0c0abed2u: goto P_0c0abed2;
case 0x0c0abed4u: goto P_0c0abed4;
case 0x0c0abed6u: goto P_0c0abed6;
case 0x0c0abed8u: goto P_0c0abed8;
case 0x0c0abedau: goto P_0c0abeda;
case 0x0c0abedcu: goto P_0c0abedc;
case 0x0c0abedeu: goto P_0c0abede;
case 0x0c0abee0u: goto P_0c0abee0;
case 0x0c0abee2u: goto P_0c0abee2;
case 0x0c0abee4u: goto P_0c0abee4;
case 0x0c0abee6u: goto P_0c0abee6;
case 0x0c0abee8u: goto P_0c0abee8;
case 0x0c0abeeau: goto P_0c0abeea;
case 0x0c0abeecu: goto P_0c0abeec;
case 0x0c0abeeeu: goto P_0c0abeee;
case 0x0c0abef0u: goto P_0c0abef0;
case 0x0c0abef2u: goto P_0c0abef2;
case 0x0c0abef4u: goto P_0c0abef4;
case 0x0c0abef6u: goto P_0c0abef6;
case 0x0c0abef8u: goto P_0c0abef8;
case 0x0c0abefau: goto P_0c0abefa;
case 0x0c0abefcu: goto P_0c0abefc;
case 0x0c0abefeu: goto P_0c0abefe;
case 0x0c0abf00u: goto P_0c0abf00;
case 0x0c0abf02u: goto P_0c0abf02;
case 0x0c0abf04u: goto P_0c0abf04;
case 0x0c0abf06u: goto P_0c0abf06;
case 0x0c0abf08u: goto P_0c0abf08;
case 0x0c0abf0au: goto P_0c0abf0a;
case 0x0c0abf0cu: goto P_0c0abf0c;
case 0x0c0abf0eu: goto P_0c0abf0e;
case 0x0c0abf10u: goto P_0c0abf10;
case 0x0c0abf12u: goto P_0c0abf12;
case 0x0c0abf14u: goto P_0c0abf14;
case 0x0c0abf16u: goto P_0c0abf16;
case 0x0c0abf18u: goto P_0c0abf18;
case 0x0c0abf1au: goto P_0c0abf1a;
case 0x0c0abf1cu: goto P_0c0abf1c;
case 0x0c0abf48u: goto P_0c0abf48;
case 0x0c0abf4au: goto P_0c0abf4a;
case 0x0c0abf4cu: goto P_0c0abf4c;
case 0x0c0abf4eu: goto P_0c0abf4e;
case 0x0c0abf50u: goto P_0c0abf50;
case 0x0c0abf52u: goto P_0c0abf52;
case 0x0c0abf54u: goto P_0c0abf54;
case 0x0c0abf56u: goto P_0c0abf56;
case 0x0c0abf58u: goto P_0c0abf58;
case 0x0c0abf5au: goto P_0c0abf5a;
case 0x0c0abf5cu: goto P_0c0abf5c;
case 0x0c0abf5eu: goto P_0c0abf5e;
case 0x0c0abf60u: goto P_0c0abf60;
case 0x0c0abf62u: goto P_0c0abf62;
case 0x0c0abf64u: goto P_0c0abf64;
case 0x0c0abf66u: goto P_0c0abf66;
case 0x0c0abf68u: goto P_0c0abf68;
case 0x0c0abf6au: goto P_0c0abf6a;
case 0x0c0abf6cu: goto P_0c0abf6c;
case 0x0c0abf6eu: goto P_0c0abf6e;
case 0x0c0abf70u: goto P_0c0abf70;
case 0x0c0abf72u: goto P_0c0abf72;
case 0x0c0abf74u: goto P_0c0abf74;
case 0x0c0abf76u: goto P_0c0abf76;
case 0x0c0abf78u: goto P_0c0abf78;
case 0x0c0abf7au: goto P_0c0abf7a;
case 0x0c0abf7cu: goto P_0c0abf7c;
case 0x0c0abf7eu: goto P_0c0abf7e;
case 0x0c0abf80u: goto P_0c0abf80;
case 0x0c0abf82u: goto P_0c0abf82;
case 0x0c0abf84u: goto P_0c0abf84;
case 0x0c0abf86u: goto P_0c0abf86;
case 0x0c0abf88u: goto P_0c0abf88;
case 0x0c0abf8au: goto P_0c0abf8a;
case 0x0c0abf8cu: goto P_0c0abf8c;
case 0x0c0abf8eu: goto P_0c0abf8e;
case 0x0c0abf90u: goto P_0c0abf90;
case 0x0c0abf92u: goto P_0c0abf92;
case 0x0c0abf94u: goto P_0c0abf94;
case 0x0c0abf96u: goto P_0c0abf96;
case 0x0c0abf98u: goto P_0c0abf98;
case 0x0c0abf9au: goto P_0c0abf9a;
case 0x0c0abf9cu: goto P_0c0abf9c;
case 0x0c0abf9eu: goto P_0c0abf9e;
case 0x0c0abfa0u: goto P_0c0abfa0;
case 0x0c0ac078u: goto P_0c0ac078;
case 0x0c0ac07au: goto P_0c0ac07a;
case 0x0c0ac07cu: goto P_0c0ac07c;
case 0x0c0ac07eu: goto P_0c0ac07e;
case 0x0c0ac080u: goto P_0c0ac080;
case 0x0c0ac082u: goto P_0c0ac082;
case 0x0c0ac084u: goto P_0c0ac084;
case 0x0c0ac086u: goto P_0c0ac086;
case 0x0c0ac088u: goto P_0c0ac088;
case 0x0c0ac08au: goto P_0c0ac08a;
case 0x0c0ac08cu: goto P_0c0ac08c;
case 0x0c0ac08eu: goto P_0c0ac08e;
case 0x0c0ac090u: goto P_0c0ac090;
case 0x0c0ac092u: goto P_0c0ac092;
case 0x0c0ac094u: goto P_0c0ac094;
case 0x0c0ac096u: goto P_0c0ac096;
case 0x0c0ac098u: goto P_0c0ac098;
case 0x0c0ac09au: goto P_0c0ac09a;
case 0x0c0ac09cu: goto P_0c0ac09c;
case 0x0c0ac09eu: goto P_0c0ac09e;
case 0x0c0ac0a0u: goto P_0c0ac0a0;
case 0x0c0ac0a2u: goto P_0c0ac0a2;
case 0x0c0ac0a4u: goto P_0c0ac0a4;
case 0x0c0ac0a6u: goto P_0c0ac0a6;
case 0x0c0ac0a8u: goto P_0c0ac0a8;
case 0x0c0ac0aau: goto P_0c0ac0aa;
case 0x0c0ac0acu: goto P_0c0ac0ac;
case 0x0c0ac0aeu: goto P_0c0ac0ae;
case 0x0c0ac0b0u: goto P_0c0ac0b0;
case 0x0c0ac0b2u: goto P_0c0ac0b2;
case 0x0c0ac0b4u: goto P_0c0ac0b4;
case 0x0c0ac0b6u: goto P_0c0ac0b6;
case 0x0c0ac0b8u: goto P_0c0ac0b8;
case 0x0c0ac0bau: goto P_0c0ac0ba;
case 0x0c0ac0bcu: goto P_0c0ac0bc;
case 0x0c0ac0beu: goto P_0c0ac0be;
case 0x0c0ac0c0u: goto P_0c0ac0c0;
case 0x0c0ac0c2u: goto P_0c0ac0c2;
case 0x0c0ac0c4u: goto P_0c0ac0c4;
case 0x0c0ac0c6u: goto P_0c0ac0c6;
case 0x0c0ac0c8u: goto P_0c0ac0c8;
case 0x0c0ac0cau: goto P_0c0ac0ca;
case 0x0c0ac0ccu: goto P_0c0ac0cc;
case 0x0c0ac0ceu: goto P_0c0ac0ce;
case 0x0c0ac0d0u: goto P_0c0ac0d0;
case 0x0c0ac0d2u: goto P_0c0ac0d2;
case 0x0c0ac0d4u: goto P_0c0ac0d4;
case 0x0c0ac0d6u: goto P_0c0ac0d6;
case 0x0c0ac0d8u: goto P_0c0ac0d8;
case 0x0c0ac0dau: goto P_0c0ac0da;
case 0x0c0ac0dcu: goto P_0c0ac0dc;
case 0x0c0ac0deu: goto P_0c0ac0de;
case 0x0c0ac0e0u: goto P_0c0ac0e0;
case 0x0c0ac0e2u: goto P_0c0ac0e2;
case 0x0c0ac0e4u: goto P_0c0ac0e4;
case 0x0c0ac0e6u: goto P_0c0ac0e6;
case 0x0c0ac0e8u: goto P_0c0ac0e8;
case 0x0c0ac0eau: goto P_0c0ac0ea;
case 0x0c0ac0ecu: goto P_0c0ac0ec;
case 0x0c0ac0eeu: goto P_0c0ac0ee;
case 0x0c0ac0f0u: goto P_0c0ac0f0;
case 0x0c0ac0f2u: goto P_0c0ac0f2;
case 0x0c0ac0f4u: goto P_0c0ac0f4;
case 0x0c0ac0f6u: goto P_0c0ac0f6;
case 0x0c0ac0f8u: goto P_0c0ac0f8;
case 0x0c0ac0fau: goto P_0c0ac0fa;
case 0x0c0ac0fcu: goto P_0c0ac0fc;
case 0x0c0ac0feu: goto P_0c0ac0fe;
case 0x0c0ac100u: goto P_0c0ac100;
case 0x0c0ac102u: goto P_0c0ac102;
case 0x0c0ac104u: goto P_0c0ac104;
case 0x0c0ac106u: goto P_0c0ac106;
case 0x0c0ac108u: goto P_0c0ac108;
case 0x0c0ac10au: goto P_0c0ac10a;
case 0x0c0ac10cu: goto P_0c0ac10c;
case 0x0c0ac10eu: goto P_0c0ac10e;
case 0x0c0ac110u: goto P_0c0ac110;
case 0x0c0ac112u: goto P_0c0ac112;
case 0x0c0ac114u: goto P_0c0ac114;
case 0x0c0ac116u: goto P_0c0ac116;
case 0x0c0ac118u: goto P_0c0ac118;
case 0x0c0ac11au: goto P_0c0ac11a;
case 0x0c0ac11cu: goto P_0c0ac11c;
case 0x0c0ac11eu: goto P_0c0ac11e;
case 0x0c0ac120u: goto P_0c0ac120;
case 0x0c0ac122u: goto P_0c0ac122;
case 0x0c0ac124u: goto P_0c0ac124;
case 0x0c0ac126u: goto P_0c0ac126;
case 0x0c0ac128u: goto P_0c0ac128;
case 0x0c0ac12au: goto P_0c0ac12a;
case 0x0c0ac12cu: goto P_0c0ac12c;
case 0x0c0ac12eu: goto P_0c0ac12e;
case 0x0c0ac130u: goto P_0c0ac130;
case 0x0c0ac132u: goto P_0c0ac132;
case 0x0c0ac134u: goto P_0c0ac134;
case 0x0c0ac136u: goto P_0c0ac136;
case 0x0c0ac138u: goto P_0c0ac138;
case 0x0c0ac13au: goto P_0c0ac13a;
case 0x0c0ac13cu: goto P_0c0ac13c;
case 0x0c0ac13eu: goto P_0c0ac13e;
case 0x0c0ac140u: goto P_0c0ac140;
case 0x0c0ac142u: goto P_0c0ac142;
case 0x0c0ac144u: goto P_0c0ac144;
case 0x0c0ac146u: goto P_0c0ac146;
case 0x0c0ac148u: goto P_0c0ac148;
case 0x0c0ac14au: goto P_0c0ac14a;
case 0x0c0ac14cu: goto P_0c0ac14c;
case 0x0c0ac14eu: goto P_0c0ac14e;
case 0x0c0ac150u: goto P_0c0ac150;
case 0x0c0ac152u: goto P_0c0ac152;
case 0x0c0ac154u: goto P_0c0ac154;
case 0x0c0ac156u: goto P_0c0ac156;
case 0x0c0ac158u: goto P_0c0ac158;
case 0x0c0ac15au: goto P_0c0ac15a;
case 0x0c0ac15cu: goto P_0c0ac15c;
case 0x0c0ac15eu: goto P_0c0ac15e;
case 0x0c0ac160u: goto P_0c0ac160;
case 0x0c0ac162u: goto P_0c0ac162;
case 0x0c0ac18cu: goto P_0c0ac18c;
case 0x0c0ac18eu: goto P_0c0ac18e;
case 0x0c0ac190u: goto P_0c0ac190;
case 0x0c0ac192u: goto P_0c0ac192;
case 0x0c0ac194u: goto P_0c0ac194;
case 0x0c0ac196u: goto P_0c0ac196;
case 0x0c0ac198u: goto P_0c0ac198;
case 0x0c0ac19au: goto P_0c0ac19a;
case 0x0c0ac19cu: goto P_0c0ac19c;
case 0x0c0ac19eu: goto P_0c0ac19e;
case 0x0c0ac1a0u: goto P_0c0ac1a0;
case 0x0c0ac1a2u: goto P_0c0ac1a2;
case 0x0c0ac1a4u: goto P_0c0ac1a4;
case 0x0c0ac1a6u: goto P_0c0ac1a6;
case 0x0c0ac1a8u: goto P_0c0ac1a8;
case 0x0c0ac1aau: goto P_0c0ac1aa;
case 0x0c0ac1acu: goto P_0c0ac1ac;
case 0x0c0ac1aeu: goto P_0c0ac1ae;
case 0x0c0ac1b0u: goto P_0c0ac1b0;
case 0x0c0ac1b2u: goto P_0c0ac1b2;
case 0x0c0ac1b4u: goto P_0c0ac1b4;
case 0x0c0ac1b6u: goto P_0c0ac1b6;
case 0x0c0ac1b8u: goto P_0c0ac1b8;
case 0x0c0ac1bau: goto P_0c0ac1ba;
case 0x0c0ac1bcu: goto P_0c0ac1bc;
case 0x0c0ac1beu: goto P_0c0ac1be;
case 0x0c0ac1c0u: goto P_0c0ac1c0;
case 0x0c0ac1c2u: goto P_0c0ac1c2;
case 0x0c0ac1c4u: goto P_0c0ac1c4;
case 0x0c0ac1c6u: goto P_0c0ac1c6;
case 0x0c0ac1c8u: goto P_0c0ac1c8;
case 0x0c0ac1cau: goto P_0c0ac1ca;
case 0x0c0ac1ccu: goto P_0c0ac1cc;
case 0x0c0ac1ceu: goto P_0c0ac1ce;
case 0x0c0ac1d0u: goto P_0c0ac1d0;
case 0x0c0ac1d2u: goto P_0c0ac1d2;
case 0x0c0ac1d4u: goto P_0c0ac1d4;
case 0x0c0ac1d6u: goto P_0c0ac1d6;
case 0x0c0ac1d8u: goto P_0c0ac1d8;
case 0x0c0ac1dau: goto P_0c0ac1da;
case 0x0c0ac1dcu: goto P_0c0ac1dc;
case 0x0c0ac1deu: goto P_0c0ac1de;
case 0x0c0ac1e0u: goto P_0c0ac1e0;
case 0x0c0ac1e2u: goto P_0c0ac1e2;
case 0x0c0ac1e4u: goto P_0c0ac1e4;
case 0x0c0ac1e6u: goto P_0c0ac1e6;
case 0x0c0ac1e8u: goto P_0c0ac1e8;
case 0x0c0ac1eau: goto P_0c0ac1ea;
case 0x0c0ac1ecu: goto P_0c0ac1ec;
case 0x0c0ac1eeu: goto P_0c0ac1ee;
case 0x0c0ac1f0u: goto P_0c0ac1f0;
case 0x0c0ac1f2u: goto P_0c0ac1f2;
case 0x0c0ac1f4u: goto P_0c0ac1f4;
case 0x0c0ac1f6u: goto P_0c0ac1f6;
case 0x0c0ac1f8u: goto P_0c0ac1f8;
case 0x0c0ac1fau: goto P_0c0ac1fa;
case 0x0c0ac1fcu: goto P_0c0ac1fc;
case 0x0c0ac1feu: goto P_0c0ac1fe;
case 0x0c0ac200u: goto P_0c0ac200;
case 0x0c0ac202u: goto P_0c0ac202;
case 0x0c0ac204u: goto P_0c0ac204;
case 0x0c0ac206u: goto P_0c0ac206;
case 0x0c0ac208u: goto P_0c0ac208;
case 0x0c0ac20au: goto P_0c0ac20a;
case 0x0c0ac20cu: goto P_0c0ac20c;
case 0x0c0ac20eu: goto P_0c0ac20e;
case 0x0c0ac210u: goto P_0c0ac210;
case 0x0c0ac212u: goto P_0c0ac212;
case 0x0c0ac214u: goto P_0c0ac214;
case 0x0c0ac216u: goto P_0c0ac216;
case 0x0c0ac218u: goto P_0c0ac218;
case 0x0c0ac21au: goto P_0c0ac21a;
case 0x0c0ac21cu: goto P_0c0ac21c;
case 0x0c0ac21eu: goto P_0c0ac21e;
case 0x0c0ac220u: goto P_0c0ac220;
case 0x0c0ac222u: goto P_0c0ac222;
case 0x0c0ac224u: goto P_0c0ac224;
case 0x0c0ac226u: goto P_0c0ac226;
case 0x0c0ac228u: goto P_0c0ac228;
case 0x0c0ac90cu: goto P_0c0ac90c;
case 0x0c0ac90eu: goto P_0c0ac90e;
case 0x0c0ac910u: goto P_0c0ac910;
case 0x0c0ac912u: goto P_0c0ac912;
case 0x0c0ac914u: goto P_0c0ac914;
case 0x0c0ac916u: goto P_0c0ac916;
case 0x0c0ac918u: goto P_0c0ac918;
case 0x0c0ac91au: goto P_0c0ac91a;
case 0x0c0ac91cu: goto P_0c0ac91c;
case 0x0c0ac91eu: goto P_0c0ac91e;
case 0x0c0ac920u: goto P_0c0ac920;
case 0x0c0ac922u: goto P_0c0ac922;
case 0x0c0ac924u: goto P_0c0ac924;
case 0x0c0ac926u: goto P_0c0ac926;
case 0x0c0ac928u: goto P_0c0ac928;
case 0x0c0ac92au: goto P_0c0ac92a;
case 0x0c0ac92cu: goto P_0c0ac92c;
case 0x0c0ac92eu: goto P_0c0ac92e;
case 0x0c0ac930u: goto P_0c0ac930;
case 0x0c0ac932u: goto P_0c0ac932;
case 0x0c0ac934u: goto P_0c0ac934;
case 0x0c0ac936u: goto P_0c0ac936;
case 0x0c0ac938u: goto P_0c0ac938;
case 0x0c0ac93au: goto P_0c0ac93a;
case 0x0c0ac93cu: goto P_0c0ac93c;
case 0x0c0ac93eu: goto P_0c0ac93e;
case 0x0c0ac940u: goto P_0c0ac940;
case 0x0c0ac942u: goto P_0c0ac942;
case 0x0c0ac944u: goto P_0c0ac944;
case 0x0c0ac946u: goto P_0c0ac946;
case 0x0c0ac948u: goto P_0c0ac948;
case 0x0c0ac968u: goto P_0c0ac968;
case 0x0c0ac96au: goto P_0c0ac96a;
case 0x0c0ac96cu: goto P_0c0ac96c;
case 0x0c0ac96eu: goto P_0c0ac96e;
case 0x0c0ac970u: goto P_0c0ac970;
case 0x0c0ac972u: goto P_0c0ac972;
case 0x0c0ac974u: goto P_0c0ac974;
case 0x0c0ac976u: goto P_0c0ac976;
case 0x0c0ac978u: goto P_0c0ac978;
case 0x0c0ac97au: goto P_0c0ac97a;
case 0x0c0ac97cu: goto P_0c0ac97c;
case 0x0c0ac97eu: goto P_0c0ac97e;
case 0x0c0ac980u: goto P_0c0ac980;
case 0x0c0ac982u: goto P_0c0ac982;
case 0x0c0ac984u: goto P_0c0ac984;
case 0x0c0ac986u: goto P_0c0ac986;
case 0x0c0ac988u: goto P_0c0ac988;
case 0x0c0ac98au: goto P_0c0ac98a;
case 0x0c0ac98cu: goto P_0c0ac98c;
case 0x0c0ac98eu: goto P_0c0ac98e;
case 0x0c0ac990u: goto P_0c0ac990;
case 0x0c0ac992u: goto P_0c0ac992;
case 0x0c0ac994u: goto P_0c0ac994;
case 0x0c0ac996u: goto P_0c0ac996;
case 0x0c0ac998u: goto P_0c0ac998;
case 0x0c0ac99au: goto P_0c0ac99a;
case 0x0c0ac99cu: goto P_0c0ac99c;
case 0x0c0ac99eu: goto P_0c0ac99e;
case 0x0c0ac9a0u: goto P_0c0ac9a0;
case 0x0c0ac9a2u: goto P_0c0ac9a2;
case 0x0c0ac9a4u: goto P_0c0ac9a4;
case 0x0c0ac9a6u: goto P_0c0ac9a6;
case 0x0c0ac9a8u: goto P_0c0ac9a8;
case 0x0c0ac9aau: goto P_0c0ac9aa;
case 0x0c0ac9acu: goto P_0c0ac9ac;
case 0x0c0ac9aeu: goto P_0c0ac9ae;
case 0x0c0ac9b0u: goto P_0c0ac9b0;
case 0x0c0ac9b2u: goto P_0c0ac9b2;
case 0x0c0ac9b4u: goto P_0c0ac9b4;
case 0x0c0ac9b6u: goto P_0c0ac9b6;
case 0x0c0ac9b8u: goto P_0c0ac9b8;
case 0x0c0ac9bau: goto P_0c0ac9ba;
case 0x0c0ac9bcu: goto P_0c0ac9bc;
case 0x0c0ac9beu: goto P_0c0ac9be;
case 0x0c0ac9c0u: goto P_0c0ac9c0;
case 0x0c0ac9c2u: goto P_0c0ac9c2;
case 0x0c0ac9c4u: goto P_0c0ac9c4;
case 0x0c0ac9c6u: goto P_0c0ac9c6;
case 0x0c0ac9c8u: goto P_0c0ac9c8;
case 0x0c0ac9cau: goto P_0c0ac9ca;
case 0x0c0ac9ccu: goto P_0c0ac9cc;
case 0x0c0ac9ceu: goto P_0c0ac9ce;
case 0x0c0ac9d0u: goto P_0c0ac9d0;
case 0x0c0ac9d2u: goto P_0c0ac9d2;
case 0x0c0ac9d4u: goto P_0c0ac9d4;
case 0x0c0ac9d6u: goto P_0c0ac9d6;
case 0x0c0ac9d8u: goto P_0c0ac9d8;
case 0x0c0ac9dau: goto P_0c0ac9da;
case 0x0c0ac9dcu: goto P_0c0ac9dc;
case 0x0c0ac9deu: goto P_0c0ac9de;
case 0x0c0ac9e0u: goto P_0c0ac9e0;
case 0x0c0ac9e2u: goto P_0c0ac9e2;
case 0x0c0ac9e4u: goto P_0c0ac9e4;
case 0x0c0ac9e6u: goto P_0c0ac9e6;
case 0x0c0ac9e8u: goto P_0c0ac9e8;
case 0x0c0ac9eau: goto P_0c0ac9ea;
case 0x0c0ac9ecu: goto P_0c0ac9ec;
case 0x0c0ac9eeu: goto P_0c0ac9ee;
case 0x0c0ac9f0u: goto P_0c0ac9f0;
case 0x0c0ac9f2u: goto P_0c0ac9f2;
case 0x0c0ac9f4u: goto P_0c0ac9f4;
case 0x0c0ac9f6u: goto P_0c0ac9f6;
case 0x0c0ac9f8u: goto P_0c0ac9f8;
case 0x0c0ac9fau: goto P_0c0ac9fa;
case 0x0c0ac9fcu: goto P_0c0ac9fc;
case 0x0c0ac9feu: goto P_0c0ac9fe;
case 0x0c0aca00u: goto P_0c0aca00;
case 0x0c0aca02u: goto P_0c0aca02;
case 0x0c0aca04u: goto P_0c0aca04;
case 0x0c0aca06u: goto P_0c0aca06;
case 0x0c0aca08u: goto P_0c0aca08;
case 0x0c0aca0au: goto P_0c0aca0a;
case 0x0c0aca0cu: goto P_0c0aca0c;
case 0x0c0aca0eu: goto P_0c0aca0e;
case 0x0c0aca10u: goto P_0c0aca10;
case 0x0c0aca12u: goto P_0c0aca12;
case 0x0c0aca14u: goto P_0c0aca14;
case 0x0c0aca16u: goto P_0c0aca16;
case 0x0c0aca18u: goto P_0c0aca18;
case 0x0c0aca1au: goto P_0c0aca1a;
case 0x0c0aca1cu: goto P_0c0aca1c;
case 0x0c0aca1eu: goto P_0c0aca1e;
case 0x0c0aca20u: goto P_0c0aca20;
case 0x0c0aca22u: goto P_0c0aca22;
case 0x0c0aca24u: goto P_0c0aca24;
case 0x0c0aca26u: goto P_0c0aca26;
case 0x0c0aca28u: goto P_0c0aca28;
case 0x0c0aca2au: goto P_0c0aca2a;
case 0x0c0aca2cu: goto P_0c0aca2c;
case 0x0c0aca2eu: goto P_0c0aca2e;
case 0x0c0aca30u: goto P_0c0aca30;
case 0x0c0aca32u: goto P_0c0aca32;
case 0x0c0aca34u: goto P_0c0aca34;
case 0x0c0aca36u: goto P_0c0aca36;
case 0x0c0aca38u: goto P_0c0aca38;
case 0x0c0aca3au: goto P_0c0aca3a;
case 0x0c0aca3cu: goto P_0c0aca3c;
case 0x0c0aca3eu: goto P_0c0aca3e;
case 0x0c0aca40u: goto P_0c0aca40;
case 0x0c0aca42u: goto P_0c0aca42;
case 0x0c0aca44u: goto P_0c0aca44;
case 0x0c0aca46u: goto P_0c0aca46;
case 0x0c0aca48u: goto P_0c0aca48;
case 0x0c0aca4au: goto P_0c0aca4a;
case 0x0c0aca4cu: goto P_0c0aca4c;
case 0x0c0aca4eu: goto P_0c0aca4e;
case 0x0c0aca50u: goto P_0c0aca50;
case 0x0c0aca52u: goto P_0c0aca52;
case 0x0c0aca54u: goto P_0c0aca54;
case 0x0c0aca56u: goto P_0c0aca56;
case 0x0c0aca58u: goto P_0c0aca58;
case 0x0c0aca5au: goto P_0c0aca5a;
case 0x0c0aca5cu: goto P_0c0aca5c;
case 0x0c0aca5eu: goto P_0c0aca5e;
case 0x0c0aca60u: goto P_0c0aca60;
case 0x0c0aca62u: goto P_0c0aca62;
case 0x0c0aca64u: goto P_0c0aca64;
case 0x0c0aca66u: goto P_0c0aca66;
case 0x0c0aca68u: goto P_0c0aca68;
case 0x0c0aca6au: goto P_0c0aca6a;
case 0x0c0aca6cu: goto P_0c0aca6c;
case 0x0c0acaa8u: goto P_0c0acaa8;
case 0x0c0acaaau: goto P_0c0acaaa;
case 0x0c0acaacu: goto P_0c0acaac;
case 0x0c0acaaeu: goto P_0c0acaae;
case 0x0c0acab0u: goto P_0c0acab0;
case 0x0c0acab2u: goto P_0c0acab2;
case 0x0c0acab4u: goto P_0c0acab4;
case 0x0c0acab6u: goto P_0c0acab6;
case 0x0c0acab8u: goto P_0c0acab8;
case 0x0c0acabau: goto P_0c0acaba;
case 0x0c0acabcu: goto P_0c0acabc;
case 0x0c0acabeu: goto P_0c0acabe;
case 0x0c0acac0u: goto P_0c0acac0;
case 0x0c0acac2u: goto P_0c0acac2;
case 0x0c0acac4u: goto P_0c0acac4;
case 0x0c0acac6u: goto P_0c0acac6;
case 0x0c0acac8u: goto P_0c0acac8;
case 0x0c0acacau: goto P_0c0acaca;
case 0x0c0acaccu: goto P_0c0acacc;
case 0x0c0acaceu: goto P_0c0acace;
case 0x0c0acad0u: goto P_0c0acad0;
case 0x0c0acad2u: goto P_0c0acad2;
case 0x0c0acad4u: goto P_0c0acad4;
case 0x0c0acad6u: goto P_0c0acad6;
case 0x0c0acad8u: goto P_0c0acad8;
case 0x0c0acadau: goto P_0c0acada;
case 0x0c0acadcu: goto P_0c0acadc;
case 0x0c0acadeu: goto P_0c0acade;
case 0x0c0acae0u: goto P_0c0acae0;
case 0x0c0acae2u: goto P_0c0acae2;
case 0x0c0acae4u: goto P_0c0acae4;
case 0x0c0acae6u: goto P_0c0acae6;
case 0x0c0acae8u: goto P_0c0acae8;
case 0x0c0acaeau: goto P_0c0acaea;
case 0x0c0acaecu: goto P_0c0acaec;
case 0x0c0acaeeu: goto P_0c0acaee;
case 0x0c0acaf0u: goto P_0c0acaf0;
case 0x0c0acaf2u: goto P_0c0acaf2;
case 0x0c0acaf4u: goto P_0c0acaf4;
case 0x0c0acaf6u: goto P_0c0acaf6;
case 0x0c0acaf8u: goto P_0c0acaf8;
case 0x0c0acafau: goto P_0c0acafa;
case 0x0c0acafcu: goto P_0c0acafc;
case 0x0c0acafeu: goto P_0c0acafe;
case 0x0c0acb00u: goto P_0c0acb00;
case 0x0c0acb02u: goto P_0c0acb02;
case 0x0c0acb04u: goto P_0c0acb04;
case 0x0c0acb06u: goto P_0c0acb06;
case 0x0c0acb08u: goto P_0c0acb08;
case 0x0c0acb0au: goto P_0c0acb0a;
case 0x0c0acb0cu: goto P_0c0acb0c;
case 0x0c0acb0eu: goto P_0c0acb0e;
case 0x0c0acb10u: goto P_0c0acb10;
case 0x0c0acb12u: goto P_0c0acb12;
case 0x0c0acb14u: goto P_0c0acb14;
case 0x0c0acb16u: goto P_0c0acb16;
case 0x0c0acb18u: goto P_0c0acb18;
case 0x0c0acb1au: goto P_0c0acb1a;
case 0x0c0acb1cu: goto P_0c0acb1c;
case 0x0c0acb1eu: goto P_0c0acb1e;
case 0x0c0acb20u: goto P_0c0acb20;
case 0x0c0acb22u: goto P_0c0acb22;
case 0x0c0acb24u: goto P_0c0acb24;
case 0x0c0acb26u: goto P_0c0acb26;
case 0x0c0acb28u: goto P_0c0acb28;
case 0x0c0acb2au: goto P_0c0acb2a;
case 0x0c0acb2cu: goto P_0c0acb2c;
case 0x0c0acb2eu: goto P_0c0acb2e;
case 0x0c0acb30u: goto P_0c0acb30;
case 0x0c0acb32u: goto P_0c0acb32;
case 0x0c0acb34u: goto P_0c0acb34;
case 0x0c0acb36u: goto P_0c0acb36;
case 0x0c0acb38u: goto P_0c0acb38;
case 0x0c0acb3au: goto P_0c0acb3a;
case 0x0c0acb3cu: goto P_0c0acb3c;
case 0x0c0acb3eu: goto P_0c0acb3e;
case 0x0c0acb40u: goto P_0c0acb40;
case 0x0c0acb42u: goto P_0c0acb42;
case 0x0c0acb44u: goto P_0c0acb44;
case 0x0c0acb46u: goto P_0c0acb46;
case 0x0c0acb48u: goto P_0c0acb48;
case 0x0c0acb4au: goto P_0c0acb4a;
case 0x0c0acb4cu: goto P_0c0acb4c;
case 0x0c0acb4eu: goto P_0c0acb4e;
case 0x0c0acb50u: goto P_0c0acb50;
case 0x0c0acb52u: goto P_0c0acb52;
case 0x0c0acb54u: goto P_0c0acb54;
case 0x0c0acb56u: goto P_0c0acb56;
case 0x0c0acb58u: goto P_0c0acb58;
case 0x0c0acb5au: goto P_0c0acb5a;
case 0x0c0acb5cu: goto P_0c0acb5c;
case 0x0c0acb5eu: goto P_0c0acb5e;
case 0x0c0acb60u: goto P_0c0acb60;
case 0x0c0acb62u: goto P_0c0acb62;
case 0x0c0acb64u: goto P_0c0acb64;
case 0x0c0acb66u: goto P_0c0acb66;
case 0x0c0acb68u: goto P_0c0acb68;
case 0x0c0acb6au: goto P_0c0acb6a;
case 0x0c0acb6cu: goto P_0c0acb6c;
case 0x0c0acb6eu: goto P_0c0acb6e;
case 0x0c0acb70u: goto P_0c0acb70;
case 0x0c0acb72u: goto P_0c0acb72;
case 0x0c0acb74u: goto P_0c0acb74;
case 0x0c0acb76u: goto P_0c0acb76;
case 0x0c0acb78u: goto P_0c0acb78;
case 0x0c0acb7au: goto P_0c0acb7a;
case 0x0c0acb7cu: goto P_0c0acb7c;
case 0x0c0acb7eu: goto P_0c0acb7e;
case 0x0c0acb80u: goto P_0c0acb80;
case 0x0c0acbb4u: goto P_0c0acbb4;
case 0x0c0acbb6u: goto P_0c0acbb6;
case 0x0c0acbb8u: goto P_0c0acbb8;
case 0x0c0acbbau: goto P_0c0acbba;
case 0x0c0acbbcu: goto P_0c0acbbc;
case 0x0c0acbbeu: goto P_0c0acbbe;
case 0x0c0acbc0u: goto P_0c0acbc0;
case 0x0c0acbc2u: goto P_0c0acbc2;
case 0x0c0acbc4u: goto P_0c0acbc4;
case 0x0c0acbc6u: goto P_0c0acbc6;
case 0x0c0acbc8u: goto P_0c0acbc8;
case 0x0c0acbcau: goto P_0c0acbca;
case 0x0c0acbccu: goto P_0c0acbcc;
case 0x0c0acbceu: goto P_0c0acbce;
case 0x0c0acbd0u: goto P_0c0acbd0;
case 0x0c0acbd2u: goto P_0c0acbd2;
case 0x0c0acbd4u: goto P_0c0acbd4;
case 0x0c0acbd6u: goto P_0c0acbd6;
case 0x0c0acbd8u: goto P_0c0acbd8;
case 0x0c0acbdau: goto P_0c0acbda;
case 0x0c0acbdcu: goto P_0c0acbdc;
case 0x0c0acbdeu: goto P_0c0acbde;
case 0x0c0acbe0u: goto P_0c0acbe0;
case 0x0c0acbe2u: goto P_0c0acbe2;
case 0x0c0acbe4u: goto P_0c0acbe4;
case 0x0c0acbe6u: goto P_0c0acbe6;
case 0x0c0acbe8u: goto P_0c0acbe8;
case 0x0c0acbeau: goto P_0c0acbea;
case 0x0c0acbecu: goto P_0c0acbec;
case 0x0c0acbeeu: goto P_0c0acbee;
case 0x0c0acbf0u: goto P_0c0acbf0;
case 0x0c0acbf2u: goto P_0c0acbf2;
case 0x0c0acbf4u: goto P_0c0acbf4;
case 0x0c0acbf6u: goto P_0c0acbf6;
case 0x0c0acbf8u: goto P_0c0acbf8;
case 0x0c0acbfau: goto P_0c0acbfa;
case 0x0c0acbfcu: goto P_0c0acbfc;
case 0x0c0acbfeu: goto P_0c0acbfe;
case 0x0c0acc00u: goto P_0c0acc00;
case 0x0c0acc02u: goto P_0c0acc02;
case 0x0c0acc04u: goto P_0c0acc04;
case 0x0c0acc06u: goto P_0c0acc06;
case 0x0c0acc08u: goto P_0c0acc08;
case 0x0c0acc0au: goto P_0c0acc0a;
case 0x0c0acc0cu: goto P_0c0acc0c;
case 0x0c0acc0eu: goto P_0c0acc0e;
case 0x0c0acc10u: goto P_0c0acc10;
case 0x0c0acc12u: goto P_0c0acc12;
case 0x0c0acc14u: goto P_0c0acc14;
case 0x0c0acc16u: goto P_0c0acc16;
case 0x0c0acc18u: goto P_0c0acc18;
case 0x0c0acc1au: goto P_0c0acc1a;
case 0x0c0acc1cu: goto P_0c0acc1c;
case 0x0c0acc1eu: goto P_0c0acc1e;
case 0x0c0acc20u: goto P_0c0acc20;
case 0x0c0acc22u: goto P_0c0acc22;
case 0x0c0acc24u: goto P_0c0acc24;
case 0x0c0acc26u: goto P_0c0acc26;
case 0x0c0acc28u: goto P_0c0acc28;
case 0x0c0acc2au: goto P_0c0acc2a;
case 0x0c0acc2cu: goto P_0c0acc2c;
case 0x0c0acc2eu: goto P_0c0acc2e;
case 0x0c0acc30u: goto P_0c0acc30;
case 0x0c0acc32u: goto P_0c0acc32;
case 0x0c0acc34u: goto P_0c0acc34;
case 0x0c0acc36u: goto P_0c0acc36;
case 0x0c0acc38u: goto P_0c0acc38;
case 0x0c0acc3au: goto P_0c0acc3a;
case 0x0c0acc3cu: goto P_0c0acc3c;
case 0x0c0acc3eu: goto P_0c0acc3e;
case 0x0c0acc40u: goto P_0c0acc40;
case 0x0c0acc42u: goto P_0c0acc42;
case 0x0c0acc44u: goto P_0c0acc44;
case 0x0c0acc46u: goto P_0c0acc46;
case 0x0c0acc48u: goto P_0c0acc48;
case 0x0c0acc4au: goto P_0c0acc4a;
case 0x0c0acc4cu: goto P_0c0acc4c;
case 0x0c0acc4eu: goto P_0c0acc4e;
case 0x0c0acc50u: goto P_0c0acc50;
case 0x0c0acc52u: goto P_0c0acc52;
case 0x0c0acc54u: goto P_0c0acc54;
case 0x0c0acc56u: goto P_0c0acc56;
case 0x0c0acc58u: goto P_0c0acc58;
case 0x0c0acc5au: goto P_0c0acc5a;
case 0x0c0acc5cu: goto P_0c0acc5c;
case 0x0c0acc5eu: goto P_0c0acc5e;
case 0x0c0acc60u: goto P_0c0acc60;
case 0x0c0acc94u: goto P_0c0acc94;
case 0x0c0acc96u: goto P_0c0acc96;
case 0x0c0acc98u: goto P_0c0acc98;
case 0x0c0acc9au: goto P_0c0acc9a;
case 0x0c0acc9cu: goto P_0c0acc9c;
case 0x0c0acc9eu: goto P_0c0acc9e;
case 0x0c0acca0u: goto P_0c0acca0;
case 0x0c0acca2u: goto P_0c0acca2;
case 0x0c0acca4u: goto P_0c0acca4;
case 0x0c0acca6u: goto P_0c0acca6;
case 0x0c0acca8u: goto P_0c0acca8;
case 0x0c0accaau: goto P_0c0accaa;
case 0x0c0accacu: goto P_0c0accac;
case 0x0c0accaeu: goto P_0c0accae;
case 0x0c0accb0u: goto P_0c0accb0;
case 0x0c0accb2u: goto P_0c0accb2;
case 0x0c0accb4u: goto P_0c0accb4;
case 0x0c0accb6u: goto P_0c0accb6;
case 0x0c0accb8u: goto P_0c0accb8;
case 0x0c0accbau: goto P_0c0accba;
case 0x0c0accbcu: goto P_0c0accbc;
case 0x0c0accbeu: goto P_0c0accbe;
case 0x0c0accc0u: goto P_0c0accc0;
case 0x0c0accc2u: goto P_0c0accc2;
case 0x0c0accc4u: goto P_0c0accc4;
case 0x0c0accc6u: goto P_0c0accc6;
case 0x0c0accc8u: goto P_0c0accc8;
case 0x0c0acccau: goto P_0c0accca;
case 0x0c0accccu: goto P_0c0acccc;
case 0x0c0accceu: goto P_0c0accce;
case 0x0c0accd0u: goto P_0c0accd0;
case 0x0c0accd2u: goto P_0c0accd2;
case 0x0c0accd4u: goto P_0c0accd4;
case 0x0c0accd6u: goto P_0c0accd6;
case 0x0c0accd8u: goto P_0c0accd8;
case 0x0c0accdau: goto P_0c0accda;
case 0x0c0accdcu: goto P_0c0accdc;
case 0x0c0accdeu: goto P_0c0accde;
case 0x0c0acce0u: goto P_0c0acce0;
case 0x0c0acce2u: goto P_0c0acce2;
case 0x0c0acce4u: goto P_0c0acce4;
case 0x0c0acce6u: goto P_0c0acce6;
case 0x0c0acce8u: goto P_0c0acce8;
case 0x0c0acceau: goto P_0c0accea;
case 0x0c0accecu: goto P_0c0accec;
case 0x0c0acceeu: goto P_0c0accee;
case 0x0c0accf0u: goto P_0c0accf0;
case 0x0c0accf2u: goto P_0c0accf2;
case 0x0c0accf4u: goto P_0c0accf4;
case 0x0c0accf6u: goto P_0c0accf6;
case 0x0c0accf8u: goto P_0c0accf8;
case 0x0c0accfau: goto P_0c0accfa;
case 0x0c0accfcu: goto P_0c0accfc;
case 0x0c0accfeu: goto P_0c0accfe;
case 0x0c0acd00u: goto P_0c0acd00;
case 0x0c0acd02u: goto P_0c0acd02;
case 0x0c0acd04u: goto P_0c0acd04;
case 0x0c0acd06u: goto P_0c0acd06;
case 0x0c0acd08u: goto P_0c0acd08;
case 0x0c0acd0au: goto P_0c0acd0a;
case 0x0c0acd0cu: goto P_0c0acd0c;
case 0x0c0acd0eu: goto P_0c0acd0e;
case 0x0c0acd10u: goto P_0c0acd10;
case 0x0c0acd12u: goto P_0c0acd12;
case 0x0c0acd14u: goto P_0c0acd14;
case 0x0c0acd16u: goto P_0c0acd16;
case 0x0c0acd18u: goto P_0c0acd18;
case 0x0c0acd1au: goto P_0c0acd1a;
case 0x0c0acd1cu: goto P_0c0acd1c;
case 0x0c0acd1eu: goto P_0c0acd1e;
case 0x0c0acd20u: goto P_0c0acd20;
case 0x0c0acd22u: goto P_0c0acd22;
case 0x0c0acd24u: goto P_0c0acd24;
case 0x0c0acd26u: goto P_0c0acd26;
case 0x0c0acd28u: goto P_0c0acd28;
case 0x0c0acd2au: goto P_0c0acd2a;
case 0x0c0acd2cu: goto P_0c0acd2c;
case 0x0c0acd2eu: goto P_0c0acd2e;
case 0x0c0acd30u: goto P_0c0acd30;
case 0x0c0acd32u: goto P_0c0acd32;
case 0x0c0acd34u: goto P_0c0acd34;
case 0x0c0acd36u: goto P_0c0acd36;
case 0x0c0acd38u: goto P_0c0acd38;
case 0x0c0acd3au: goto P_0c0acd3a;
case 0x0c0acd3cu: goto P_0c0acd3c;
case 0x0c0acd3eu: goto P_0c0acd3e;
case 0x0c0acd40u: goto P_0c0acd40;
case 0x0c0acd42u: goto P_0c0acd42;
case 0x0c0acd44u: goto P_0c0acd44;
case 0x0c0acd46u: goto P_0c0acd46;
case 0x0c0acd48u: goto P_0c0acd48;
case 0x0c0acd4au: goto P_0c0acd4a;
case 0x0c0acd4cu: goto P_0c0acd4c;
case 0x0c0acd4eu: goto P_0c0acd4e;
case 0x0c0acd50u: goto P_0c0acd50;
case 0x0c0acd52u: goto P_0c0acd52;
case 0x0c0acd54u: goto P_0c0acd54;
case 0x0c0acd56u: goto P_0c0acd56;
case 0x0c0acd58u: goto P_0c0acd58;
case 0x0c0acd5au: goto P_0c0acd5a;
case 0x0c0acd5cu: goto P_0c0acd5c;
case 0x0c0acd5eu: goto P_0c0acd5e;
case 0x0c0acd60u: goto P_0c0acd60;
case 0x0c0acd62u: goto P_0c0acd62;
case 0x0c0acd64u: goto P_0c0acd64;
case 0x0c0acd66u: goto P_0c0acd66;
case 0x0c0acd68u: goto P_0c0acd68;
case 0x0c0acd6au: goto P_0c0acd6a;
case 0x0c0acd6cu: goto P_0c0acd6c;
case 0x0c0acd6eu: goto P_0c0acd6e;
case 0x0c0acd70u: goto P_0c0acd70;
case 0x0c0acd72u: goto P_0c0acd72;
case 0x0c0acd74u: goto P_0c0acd74;
case 0x0c0acd76u: goto P_0c0acd76;
case 0x0c0acd78u: goto P_0c0acd78;
case 0x0c0acd7au: goto P_0c0acd7a;
case 0x0c0acd7cu: goto P_0c0acd7c;
case 0x0c0acd7eu: goto P_0c0acd7e;
case 0x0c0acd80u: goto P_0c0acd80;
case 0x0c0acd82u: goto P_0c0acd82;
case 0x0c0acd84u: goto P_0c0acd84;
case 0x0c0acd86u: goto P_0c0acd86;
case 0x0c0acd88u: goto P_0c0acd88;
case 0x0c0acd8au: goto P_0c0acd8a;
case 0x0c0acd8cu: goto P_0c0acd8c;
case 0x0c0acd8eu: goto P_0c0acd8e;
case 0x0c0acd90u: goto P_0c0acd90;
case 0x0c0acd92u: goto P_0c0acd92;
case 0x0c0acd94u: goto P_0c0acd94;
case 0x0c0acd96u: goto P_0c0acd96;
case 0x0c0acd98u: goto P_0c0acd98;
case 0x0c0acd9au: goto P_0c0acd9a;
case 0x0c0acd9cu: goto P_0c0acd9c;
case 0x0c0acdd0u: goto P_0c0acdd0;
case 0x0c0acdd2u: goto P_0c0acdd2;
case 0x0c0acdd4u: goto P_0c0acdd4;
case 0x0c0acdd6u: goto P_0c0acdd6;
case 0x0c0acdd8u: goto P_0c0acdd8;
case 0x0c0acddau: goto P_0c0acdda;
case 0x0c0acddcu: goto P_0c0acddc;
case 0x0c0acddeu: goto P_0c0acdde;
case 0x0c0acde0u: goto P_0c0acde0;
case 0x0c0acde2u: goto P_0c0acde2;
case 0x0c0acde4u: goto P_0c0acde4;
case 0x0c0acde6u: goto P_0c0acde6;
case 0x0c0acde8u: goto P_0c0acde8;
case 0x0c0acdeau: goto P_0c0acdea;
case 0x0c0acdecu: goto P_0c0acdec;
case 0x0c0acdeeu: goto P_0c0acdee;
case 0x0c0acdf0u: goto P_0c0acdf0;
case 0x0c0acdf2u: goto P_0c0acdf2;
case 0x0c0acdf4u: goto P_0c0acdf4;
case 0x0c0acdf6u: goto P_0c0acdf6;
case 0x0c0acdf8u: goto P_0c0acdf8;
case 0x0c0acdfau: goto P_0c0acdfa;
case 0x0c0acdfcu: goto P_0c0acdfc;
case 0x0c0acdfeu: goto P_0c0acdfe;
case 0x0c0ace00u: goto P_0c0ace00;
case 0x0c0ace02u: goto P_0c0ace02;
case 0x0c0ace04u: goto P_0c0ace04;
case 0x0c0ace06u: goto P_0c0ace06;
case 0x0c0ace08u: goto P_0c0ace08;
case 0x0c0ace0au: goto P_0c0ace0a;
case 0x0c0ace0cu: goto P_0c0ace0c;
case 0x0c0ace0eu: goto P_0c0ace0e;
case 0x0c0ace10u: goto P_0c0ace10;
case 0x0c0ace12u: goto P_0c0ace12;
case 0x0c0ace14u: goto P_0c0ace14;
case 0x0c0ace16u: goto P_0c0ace16;
case 0x0c0ace18u: goto P_0c0ace18;
case 0x0c0ace1au: goto P_0c0ace1a;
case 0x0c0ace1cu: goto P_0c0ace1c;
case 0x0c0ace1eu: goto P_0c0ace1e;
case 0x0c0ace20u: goto P_0c0ace20;
case 0x0c0ace22u: goto P_0c0ace22;
case 0x0c0ace24u: goto P_0c0ace24;
case 0x0c0ace26u: goto P_0c0ace26;
case 0x0c0ace28u: goto P_0c0ace28;
case 0x0c0ace2au: goto P_0c0ace2a;
case 0x0c0ace2cu: goto P_0c0ace2c;
case 0x0c0ace2eu: goto P_0c0ace2e;
case 0x0c0ace30u: goto P_0c0ace30;
case 0x0c0ace32u: goto P_0c0ace32;
case 0x0c0ad578u: goto P_0c0ad578;
case 0x0c0ad57au: goto P_0c0ad57a;
case 0x0c0ad57cu: goto P_0c0ad57c;
case 0x0c0ad57eu: goto P_0c0ad57e;
case 0x0c0ad580u: goto P_0c0ad580;
case 0x0c0ad582u: goto P_0c0ad582;
case 0x0c0ad584u: goto P_0c0ad584;
case 0x0c0ad586u: goto P_0c0ad586;
case 0x0c0ad588u: goto P_0c0ad588;
case 0x0c0ad878u: goto P_0c0ad878;
case 0x0c0ad87au: goto P_0c0ad87a;
case 0x0c0ad87cu: goto P_0c0ad87c;
case 0x0c0ad87eu: goto P_0c0ad87e;
case 0x0c0ad880u: goto P_0c0ad880;
case 0x0c0ad882u: goto P_0c0ad882;
case 0x0c0ad884u: goto P_0c0ad884;
case 0x0c0ad886u: goto P_0c0ad886;
case 0x0c0ad888u: goto P_0c0ad888;
case 0x0c0ad88au: goto P_0c0ad88a;
case 0x0c0ad88cu: goto P_0c0ad88c;
case 0x0c0ad88eu: goto P_0c0ad88e;
case 0x0c0ad890u: goto P_0c0ad890;
case 0x0c0ad892u: goto P_0c0ad892;
case 0x0c0ad894u: goto P_0c0ad894;
case 0x0c0ad896u: goto P_0c0ad896;
case 0x0c0ad898u: goto P_0c0ad898;
case 0x0c0ad89au: goto P_0c0ad89a;
case 0x0c0ad89cu: goto P_0c0ad89c;
case 0x0c0ad89eu: goto P_0c0ad89e;
case 0x0c0ad8a0u: goto P_0c0ad8a0;
case 0x0c0ad8a2u: goto P_0c0ad8a2;
case 0x0c0ad8a4u: goto P_0c0ad8a4;
case 0x0c0ad8a6u: goto P_0c0ad8a6;
case 0x0c0ad8a8u: goto P_0c0ad8a8;
case 0x0c0ad8aau: goto P_0c0ad8aa;
case 0x0c0ad8acu: goto P_0c0ad8ac;
case 0x0c0ad8aeu: goto P_0c0ad8ae;
case 0x0c0ad8b0u: goto P_0c0ad8b0;
case 0x0c0ad8b2u: goto P_0c0ad8b2;
case 0x0c0ad8b4u: goto P_0c0ad8b4;
case 0x0c0ad8b6u: goto P_0c0ad8b6;
case 0x0c0ad8b8u: goto P_0c0ad8b8;
case 0x0c0ad8bau: goto P_0c0ad8ba;
case 0x0c0ad8bcu: goto P_0c0ad8bc;
case 0x0c0ad8beu: goto P_0c0ad8be;
case 0x0c0ad8c0u: goto P_0c0ad8c0;
case 0x0c0ad8c2u: goto P_0c0ad8c2;
case 0x0c0ad8c4u: goto P_0c0ad8c4;
case 0x0c0ad8c6u: goto P_0c0ad8c6;
case 0x0c0ad8c8u: goto P_0c0ad8c8;
case 0x0c0ad8cau: goto P_0c0ad8ca;
case 0x0c0ad8ccu: goto P_0c0ad8cc;
case 0x0c0ad8ceu: goto P_0c0ad8ce;
case 0x0c0ad8d0u: goto P_0c0ad8d0;
case 0x0c0ad8d2u: goto P_0c0ad8d2;
case 0x0c0ad8d4u: goto P_0c0ad8d4;
case 0x0c0ad8d6u: goto P_0c0ad8d6;
case 0x0c0ad8d8u: goto P_0c0ad8d8;
case 0x0c0ad8dau: goto P_0c0ad8da;
case 0x0c0ad8dcu: goto P_0c0ad8dc;
case 0x0c0ad8deu: goto P_0c0ad8de;
case 0x0c0ad8e0u: goto P_0c0ad8e0;
case 0x0c0ad8e2u: goto P_0c0ad8e2;
case 0x0c0ad8e4u: goto P_0c0ad8e4;
case 0x0c0ad8e6u: goto P_0c0ad8e6;
case 0x0c0ad8e8u: goto P_0c0ad8e8;
case 0x0c0ad8eau: goto P_0c0ad8ea;
case 0x0c0ad8ecu: goto P_0c0ad8ec;
case 0x0c0ad8eeu: goto P_0c0ad8ee;
case 0x0c0ad8f0u: goto P_0c0ad8f0;
case 0x0c0ad8f2u: goto P_0c0ad8f2;
case 0x0c0ad8f4u: goto P_0c0ad8f4;
case 0x0c0ad8f6u: goto P_0c0ad8f6;
case 0x0c0ad8f8u: goto P_0c0ad8f8;
case 0x0c0ad8fau: goto P_0c0ad8fa;
case 0x0c0ad8fcu: goto P_0c0ad8fc;
case 0x0c0ad8feu: goto P_0c0ad8fe;
case 0x0c0ad900u: goto P_0c0ad900;
case 0x0c0ad902u: goto P_0c0ad902;
case 0x0c0ad904u: goto P_0c0ad904;
case 0x0c0ad906u: goto P_0c0ad906;
case 0x0c0ad908u: goto P_0c0ad908;
case 0x0c0ad90au: goto P_0c0ad90a;
case 0x0c0ad90cu: goto P_0c0ad90c;
case 0x0c0ad90eu: goto P_0c0ad90e;
case 0x0c0ad910u: goto P_0c0ad910;
case 0x0c0ad912u: goto P_0c0ad912;
case 0x0c0ad914u: goto P_0c0ad914;
case 0x0c0ad916u: goto P_0c0ad916;
case 0x0c0ad918u: goto P_0c0ad918;
case 0x0c0ad91au: goto P_0c0ad91a;
case 0x0c0ad91cu: goto P_0c0ad91c;
case 0x0c0ad91eu: goto P_0c0ad91e;
case 0x0c0ad920u: goto P_0c0ad920;
case 0x0c0ad922u: goto P_0c0ad922;
case 0x0c0ad924u: goto P_0c0ad924;
case 0x0c0ad926u: goto P_0c0ad926;
case 0x0c0ad928u: goto P_0c0ad928;
case 0x0c0ad92au: goto P_0c0ad92a;
case 0x0c0ad92cu: goto P_0c0ad92c;
case 0x0c0ad92eu: goto P_0c0ad92e;
case 0x0c0ad930u: goto P_0c0ad930;
case 0x0c0ad932u: goto P_0c0ad932;
case 0x0c0ad934u: goto P_0c0ad934;
case 0x0c0ad936u: goto P_0c0ad936;
case 0x0c0ad938u: goto P_0c0ad938;
case 0x0c0ad93au: goto P_0c0ad93a;
case 0x0c0ad93cu: goto P_0c0ad93c;
case 0x0c0ad93eu: goto P_0c0ad93e;
case 0x0c0ad940u: goto P_0c0ad940;
case 0x0c0ad942u: goto P_0c0ad942;
case 0x0c0ad944u: goto P_0c0ad944;
case 0x0c0ad946u: goto P_0c0ad946;
case 0x0c0ad948u: goto P_0c0ad948;
case 0x0c0ad94au: goto P_0c0ad94a;
case 0x0c0ad94cu: goto P_0c0ad94c;
case 0x0c0ad94eu: goto P_0c0ad94e;
case 0x0c0ad950u: goto P_0c0ad950;
case 0x0c0ad952u: goto P_0c0ad952;
case 0x0c0ad954u: goto P_0c0ad954;
case 0x0c0ad956u: goto P_0c0ad956;
case 0x0c0ad958u: goto P_0c0ad958;
case 0x0c0ad95au: goto P_0c0ad95a;
case 0x0c0ad95cu: goto P_0c0ad95c;
case 0x0c0ad95eu: goto P_0c0ad95e;
case 0x0c0ad960u: goto P_0c0ad960;
case 0x0c0ad962u: goto P_0c0ad962;
case 0x0c0ad964u: goto P_0c0ad964;
case 0x0c0ad966u: goto P_0c0ad966;
case 0x0c0ad968u: goto P_0c0ad968;
case 0x0c0ad96au: goto P_0c0ad96a;
case 0x0c0ad96cu: goto P_0c0ad96c;
case 0x0c0ad96eu: goto P_0c0ad96e;
case 0x0c0ad970u: goto P_0c0ad970;
case 0x0c0ad972u: goto P_0c0ad972;
case 0x0c0ad974u: goto P_0c0ad974;
case 0x0c0ad976u: goto P_0c0ad976;
case 0x0c0ad978u: goto P_0c0ad978;
case 0x0c0ad97au: goto P_0c0ad97a;
case 0x0c0ad97cu: goto P_0c0ad97c;
case 0x0c0ad97eu: goto P_0c0ad97e;
case 0x0c0ad980u: goto P_0c0ad980;
case 0x0c0ad982u: goto P_0c0ad982;
case 0x0c0ad984u: goto P_0c0ad984;
case 0x0c0ad986u: goto P_0c0ad986;
case 0x0c0ad988u: goto P_0c0ad988;
case 0x0c0ad98au: goto P_0c0ad98a;
case 0x0c0ad98cu: goto P_0c0ad98c;
case 0x0c0ad98eu: goto P_0c0ad98e;
case 0x0c0ad990u: goto P_0c0ad990;
case 0x0c0ad992u: goto P_0c0ad992;
case 0x0c0ad994u: goto P_0c0ad994;
case 0x0c0ad996u: goto P_0c0ad996;
case 0x0c0ad998u: goto P_0c0ad998;
case 0x0c0ad99au: goto P_0c0ad99a;
case 0x0c0ad99cu: goto P_0c0ad99c;
case 0x0c0ad99eu: goto P_0c0ad99e;
case 0x0c0ad9a0u: goto P_0c0ad9a0;
case 0x0c0ad9a2u: goto P_0c0ad9a2;
case 0x0c0ad9a4u: goto P_0c0ad9a4;
case 0x0c0ad9a6u: goto P_0c0ad9a6;
case 0x0c0ad9a8u: goto P_0c0ad9a8;
case 0x0c0ad9aau: goto P_0c0ad9aa;
case 0x0c0ad9acu: goto P_0c0ad9ac;
case 0x0c0ad9aeu: goto P_0c0ad9ae;
case 0x0c0ad9b0u: goto P_0c0ad9b0;
case 0x0c0ad9feu: goto P_0c0ad9fe;
case 0x0c0ada00u: goto P_0c0ada00;
case 0x0c0ada02u: goto P_0c0ada02;
case 0x0c0ada04u: goto P_0c0ada04;
case 0x0c0ada06u: goto P_0c0ada06;
case 0x0c0ada08u: goto P_0c0ada08;
case 0x0c0ada0au: goto P_0c0ada0a;
case 0x0c0ada0cu: goto P_0c0ada0c;
case 0x0c0ada0eu: goto P_0c0ada0e;
case 0x0c0ada10u: goto P_0c0ada10;
case 0x0c0ada12u: goto P_0c0ada12;
case 0x0c0ada14u: goto P_0c0ada14;
case 0x0c0ada16u: goto P_0c0ada16;
case 0x0c0ada18u: goto P_0c0ada18;
case 0x0c0ada1au: goto P_0c0ada1a;
case 0x0c0ada1cu: goto P_0c0ada1c;
case 0x0c0ada1eu: goto P_0c0ada1e;
case 0x0c0ada20u: goto P_0c0ada20;
case 0x0c0ada22u: goto P_0c0ada22;
case 0x0c0ada24u: goto P_0c0ada24;
case 0x0c0ada26u: goto P_0c0ada26;
case 0x0c0ada28u: goto P_0c0ada28;
case 0x0c0ada2au: goto P_0c0ada2a;
case 0x0c0ada2cu: goto P_0c0ada2c;
case 0x0c0ada2eu: goto P_0c0ada2e;
case 0x0c0ada30u: goto P_0c0ada30;
case 0x0c0ada32u: goto P_0c0ada32;
case 0x0c0ada34u: goto P_0c0ada34;
case 0x0c0ada36u: goto P_0c0ada36;
case 0x0c0ada38u: goto P_0c0ada38;
case 0x0c0ada3au: goto P_0c0ada3a;
case 0x0c0ada3cu: goto P_0c0ada3c;
case 0x0c0ada3eu: goto P_0c0ada3e;
case 0x0c0ada40u: goto P_0c0ada40;
case 0x0c0ada42u: goto P_0c0ada42;
case 0x0c0ada44u: goto P_0c0ada44;
case 0x0c0ada46u: goto P_0c0ada46;
case 0x0c0ada48u: goto P_0c0ada48;
case 0x0c0ada4au: goto P_0c0ada4a;
case 0x0c0ada4cu: goto P_0c0ada4c;
case 0x0c0ada4eu: goto P_0c0ada4e;
case 0x0c0ada50u: goto P_0c0ada50;
case 0x0c0ada52u: goto P_0c0ada52;
case 0x0c0ada54u: goto P_0c0ada54;
case 0x0c0ada56u: goto P_0c0ada56;
case 0x0c0ada58u: goto P_0c0ada58;
case 0x0c0ada5au: goto P_0c0ada5a;
case 0x0c0ada5cu: goto P_0c0ada5c;
case 0x0c0ada5eu: goto P_0c0ada5e;
case 0x0c0ada60u: goto P_0c0ada60;
case 0x0c0ada62u: goto P_0c0ada62;
case 0x0c0ada64u: goto P_0c0ada64;
case 0x0c0ada66u: goto P_0c0ada66;
case 0x0c0ada68u: goto P_0c0ada68;
case 0x0c0ada6au: goto P_0c0ada6a;
case 0x0c0ada6cu: goto P_0c0ada6c;
case 0x0c0ada6eu: goto P_0c0ada6e;
case 0x0c0ada70u: goto P_0c0ada70;
case 0x0c0ada72u: goto P_0c0ada72;
case 0x0c0ada74u: goto P_0c0ada74;
case 0x0c0ada76u: goto P_0c0ada76;
case 0x0c0ada78u: goto P_0c0ada78;
case 0x0c0ada7au: goto P_0c0ada7a;
case 0x0c0ada7cu: goto P_0c0ada7c;
case 0x0c0ada7eu: goto P_0c0ada7e;
case 0x0c0ada80u: goto P_0c0ada80;
case 0x0c0ada82u: goto P_0c0ada82;
case 0x0c0ada84u: goto P_0c0ada84;
case 0x0c0ada86u: goto P_0c0ada86;
case 0x0c0ada88u: goto P_0c0ada88;
case 0x0c0ada8au: goto P_0c0ada8a;
case 0x0c0ada8cu: goto P_0c0ada8c;
case 0x0c0ada8eu: goto P_0c0ada8e;
case 0x0c0ada90u: goto P_0c0ada90;
case 0x0c0ada92u: goto P_0c0ada92;
case 0x0c0ada94u: goto P_0c0ada94;
case 0x0c0ada96u: goto P_0c0ada96;
case 0x0c0ada98u: goto P_0c0ada98;
case 0x0c0ada9au: goto P_0c0ada9a;
case 0x0c0ada9cu: goto P_0c0ada9c;
case 0x0c0ada9eu: goto P_0c0ada9e;
case 0x0c0adaa0u: goto P_0c0adaa0;
case 0x0c0adaa2u: goto P_0c0adaa2;
case 0x0c0adaa4u: goto P_0c0adaa4;
case 0x0c0adaa6u: goto P_0c0adaa6;
case 0x0c0adaa8u: goto P_0c0adaa8;
case 0x0c0adaaau: goto P_0c0adaaa;
case 0x0c0adaacu: goto P_0c0adaac;
case 0x0c0adaaeu: goto P_0c0adaae;
case 0x0c0adab0u: goto P_0c0adab0;
case 0x0c0adab2u: goto P_0c0adab2;
case 0x0c0adab4u: goto P_0c0adab4;
case 0x0c0adab6u: goto P_0c0adab6;
case 0x0c0adab8u: goto P_0c0adab8;
case 0x0c0adabau: goto P_0c0adaba;
case 0x0c0adabcu: goto P_0c0adabc;
case 0x0c0adabeu: goto P_0c0adabe;
case 0x0c0adac0u: goto P_0c0adac0;
case 0x0c0adac2u: goto P_0c0adac2;
case 0x0c0adac4u: goto P_0c0adac4;
case 0x0c0adac6u: goto P_0c0adac6;
case 0x0c0adac8u: goto P_0c0adac8;
case 0x0c0adacau: goto P_0c0adaca;
case 0x0c0adaccu: goto P_0c0adacc;
case 0x0c0adaceu: goto P_0c0adace;
case 0x0c0adad0u: goto P_0c0adad0;
case 0x0c0adad2u: goto P_0c0adad2;
case 0x0c0adad4u: goto P_0c0adad4;
case 0x0c0adad6u: goto P_0c0adad6;
case 0x0c0adad8u: goto P_0c0adad8;
case 0x0c0adadau: goto P_0c0adada;
case 0x0c0adadcu: goto P_0c0adadc;
case 0x0c0adadeu: goto P_0c0adade;
case 0x0c0adae0u: goto P_0c0adae0;
case 0x0c0adae2u: goto P_0c0adae2;
case 0x0c0adae4u: goto P_0c0adae4;
case 0x0c0adae6u: goto P_0c0adae6;
case 0x0c0adae8u: goto P_0c0adae8;
case 0x0c0adaeau: goto P_0c0adaea;
case 0x0c0adaecu: goto P_0c0adaec;
case 0x0c0adaeeu: goto P_0c0adaee;
case 0x0c0adaf0u: goto P_0c0adaf0;
case 0x0c0adaf2u: goto P_0c0adaf2;
case 0x0c0adaf4u: goto P_0c0adaf4;
case 0x0c0adaf6u: goto P_0c0adaf6;
case 0x0c0adaf8u: goto P_0c0adaf8;
case 0x0c0adafau: goto P_0c0adafa;
case 0x0c0adb48u: goto P_0c0adb48;
case 0x0c0adb4au: goto P_0c0adb4a;
case 0x0c0adb4cu: goto P_0c0adb4c;
case 0x0c0adb4eu: goto P_0c0adb4e;
case 0x0c0adb50u: goto P_0c0adb50;
case 0x0c0adb52u: goto P_0c0adb52;
case 0x0c0adb54u: goto P_0c0adb54;
case 0x0c0adb56u: goto P_0c0adb56;
case 0x0c0adb58u: goto P_0c0adb58;
case 0x0c0adb5au: goto P_0c0adb5a;
case 0x0c0adb5cu: goto P_0c0adb5c;
case 0x0c0adb5eu: goto P_0c0adb5e;
case 0x0c0adb60u: goto P_0c0adb60;
case 0x0c0adb62u: goto P_0c0adb62;
case 0x0c0adb64u: goto P_0c0adb64;
case 0x0c0adb66u: goto P_0c0adb66;
case 0x0c0adb68u: goto P_0c0adb68;
case 0x0c0adb6au: goto P_0c0adb6a;
case 0x0c0adb6cu: goto P_0c0adb6c;
case 0x0c0adb6eu: goto P_0c0adb6e;
case 0x0c0adb70u: goto P_0c0adb70;
case 0x0c0adb72u: goto P_0c0adb72;
case 0x0c0adb74u: goto P_0c0adb74;
case 0x0c0adb76u: goto P_0c0adb76;
case 0x0c0ade24u: goto P_0c0ade24;
case 0x0c0ade26u: goto P_0c0ade26;
case 0x0c0ade28u: goto P_0c0ade28;
case 0x0c0ade2au: goto P_0c0ade2a;
case 0x0c0ade2cu: goto P_0c0ade2c;
case 0x0c0ade2eu: goto P_0c0ade2e;
case 0x0c0ade30u: goto P_0c0ade30;
case 0x0c0ade32u: goto P_0c0ade32;
case 0x0c0ade34u: goto P_0c0ade34;
case 0x0c0ade36u: goto P_0c0ade36;
case 0x0c0ade38u: goto P_0c0ade38;
case 0x0c0ade3au: goto P_0c0ade3a;
case 0x0c0ade3cu: goto P_0c0ade3c;
case 0x0c0ade3eu: goto P_0c0ade3e;
case 0x0c0ade40u: goto P_0c0ade40;
case 0x0c0ade42u: goto P_0c0ade42;
case 0x0c0ade44u: goto P_0c0ade44;
case 0x0c0ade46u: goto P_0c0ade46;
case 0x0c0ade48u: goto P_0c0ade48;
case 0x0c0ade4au: goto P_0c0ade4a;
case 0x0c0ade4cu: goto P_0c0ade4c;
case 0x0c0ade4eu: goto P_0c0ade4e;
case 0x0c0ade50u: goto P_0c0ade50;
case 0x0c0ade52u: goto P_0c0ade52;
case 0x0c0ade54u: goto P_0c0ade54;
case 0x0c0ade56u: goto P_0c0ade56;
case 0x0c0ade58u: goto P_0c0ade58;
case 0x0c0ade5au: goto P_0c0ade5a;
case 0x0c0ade5cu: goto P_0c0ade5c;
case 0x0c0ade5eu: goto P_0c0ade5e;
case 0x0c0ade60u: goto P_0c0ade60;
case 0x0c0ade62u: goto P_0c0ade62;
case 0x0c0ade64u: goto P_0c0ade64;
case 0x0c0ade66u: goto P_0c0ade66;
case 0x0c0ade68u: goto P_0c0ade68;
case 0x0c0ade6au: goto P_0c0ade6a;
case 0x0c0ade6cu: goto P_0c0ade6c;
case 0x0c0ade6eu: goto P_0c0ade6e;
case 0x0c0ade70u: goto P_0c0ade70;
case 0x0c0ade72u: goto P_0c0ade72;
case 0x0c0ade74u: goto P_0c0ade74;
case 0x0c0ade76u: goto P_0c0ade76;
case 0x0c0ade78u: goto P_0c0ade78;
case 0x0c0ade7au: goto P_0c0ade7a;
case 0x0c0ade7cu: goto P_0c0ade7c;
case 0x0c0ade7eu: goto P_0c0ade7e;
case 0x0c0ade80u: goto P_0c0ade80;
case 0x0c0ade82u: goto P_0c0ade82;
case 0x0c0ade84u: goto P_0c0ade84;
case 0x0c0ade86u: goto P_0c0ade86;
case 0x0c0ade88u: goto P_0c0ade88;
case 0x0c0ade8au: goto P_0c0ade8a;
case 0x0c0ade8cu: goto P_0c0ade8c;
case 0x0c0ade8eu: goto P_0c0ade8e;
case 0x0c0ade90u: goto P_0c0ade90;
case 0x0c0ade92u: goto P_0c0ade92;
case 0x0c0ade94u: goto P_0c0ade94;
case 0x0c0ade96u: goto P_0c0ade96;
case 0x0c0ade98u: goto P_0c0ade98;
case 0x0c0ade9au: goto P_0c0ade9a;
case 0x0c0ade9cu: goto P_0c0ade9c;
case 0x0c0ade9eu: goto P_0c0ade9e;
case 0x0c0adea0u: goto P_0c0adea0;
case 0x0c0adea2u: goto P_0c0adea2;
case 0x0c0adea4u: goto P_0c0adea4;
case 0x0c0adea6u: goto P_0c0adea6;
case 0x0c0adea8u: goto P_0c0adea8;
case 0x0c0adeaau: goto P_0c0adeaa;
case 0x0c0adeacu: goto P_0c0adeac;
case 0x0c0adeaeu: goto P_0c0adeae;
case 0x0c0adeb0u: goto P_0c0adeb0;
case 0x0c0adeb2u: goto P_0c0adeb2;
case 0x0c0adeb4u: goto P_0c0adeb4;
case 0x0c0adeb6u: goto P_0c0adeb6;
case 0x0c0adeb8u: goto P_0c0adeb8;
case 0x0c0adebau: goto P_0c0adeba;
case 0x0c0adebcu: goto P_0c0adebc;
case 0x0c0adebeu: goto P_0c0adebe;
case 0x0c0adec0u: goto P_0c0adec0;
case 0x0c0adec2u: goto P_0c0adec2;
case 0x0c0adec4u: goto P_0c0adec4;
case 0x0c0adec6u: goto P_0c0adec6;
case 0x0c0adec8u: goto P_0c0adec8;
case 0x0c0adecau: goto P_0c0adeca;
case 0x0c0adeccu: goto P_0c0adecc;
case 0x0c0adeceu: goto P_0c0adece;
case 0x0c0aded0u: goto P_0c0aded0;
case 0x0c0aded2u: goto P_0c0aded2;
case 0x0c0aded4u: goto P_0c0aded4;
case 0x0c0aded6u: goto P_0c0aded6;
case 0x0c0aded8u: goto P_0c0aded8;
case 0x0c0adedau: goto P_0c0adeda;
case 0x0c0adedcu: goto P_0c0adedc;
case 0x0c0adedeu: goto P_0c0adede;
case 0x0c0adee0u: goto P_0c0adee0;
case 0x0c0adee2u: goto P_0c0adee2;
case 0x0c0adee4u: goto P_0c0adee4;
case 0x0c0adee6u: goto P_0c0adee6;
case 0x0c0adee8u: goto P_0c0adee8;
case 0x0c0adeeau: goto P_0c0adeea;
case 0x0c0adeecu: goto P_0c0adeec;
case 0x0c0adeeeu: goto P_0c0adeee;
case 0x0c0adef0u: goto P_0c0adef0;
case 0x0c0adef2u: goto P_0c0adef2;
case 0x0c0adef4u: goto P_0c0adef4;
case 0x0c0adef6u: goto P_0c0adef6;
case 0x0c0adef8u: goto P_0c0adef8;
case 0x0c0adefau: goto P_0c0adefa;
case 0x0c0adefcu: goto P_0c0adefc;
case 0x0c0adefeu: goto P_0c0adefe;
case 0x0c0adf00u: goto P_0c0adf00;
case 0x0c0adf02u: goto P_0c0adf02;
case 0x0c0adf04u: goto P_0c0adf04;
case 0x0c0adf06u: goto P_0c0adf06;
case 0x0c0adf08u: goto P_0c0adf08;
case 0x0c0adf0au: goto P_0c0adf0a;
case 0x0c0adf0cu: goto P_0c0adf0c;
case 0x0c0adf0eu: goto P_0c0adf0e;
case 0x0c0adf10u: goto P_0c0adf10;
case 0x0c0adf12u: goto P_0c0adf12;
case 0x0c0adf14u: goto P_0c0adf14;
case 0x0c0adf16u: goto P_0c0adf16;
case 0x0c0adf18u: goto P_0c0adf18;
case 0x0c0adf1au: goto P_0c0adf1a;
case 0x0c0adf1cu: goto P_0c0adf1c;
case 0x0c0adf38u: goto P_0c0adf38;
case 0x0c0adf3au: goto P_0c0adf3a;
case 0x0c0adf3cu: goto P_0c0adf3c;
case 0x0c0adf3eu: goto P_0c0adf3e;
case 0x0c0adf40u: goto P_0c0adf40;
case 0x0c0adf42u: goto P_0c0adf42;
case 0x0c0adf44u: goto P_0c0adf44;
case 0x0c0adf46u: goto P_0c0adf46;
case 0x0c0adf48u: goto P_0c0adf48;
case 0x0c0adf4au: goto P_0c0adf4a;
case 0x0c0adf4cu: goto P_0c0adf4c;
case 0x0c0adf4eu: goto P_0c0adf4e;
case 0x0c0adf50u: goto P_0c0adf50;
case 0x0c0adf52u: goto P_0c0adf52;
case 0x0c0adf54u: goto P_0c0adf54;
case 0x0c0adf56u: goto P_0c0adf56;
case 0x0c0adf58u: goto P_0c0adf58;
case 0x0c0adf5au: goto P_0c0adf5a;
case 0x0c0adf5cu: goto P_0c0adf5c;
case 0x0c0adf5eu: goto P_0c0adf5e;
case 0x0c0adf60u: goto P_0c0adf60;
case 0x0c0adf62u: goto P_0c0adf62;
case 0x0c0adf6cu: goto P_0c0adf6c;
case 0x0c0adf6eu: goto P_0c0adf6e;
case 0x0c0ae29cu: goto P_0c0ae29c;
case 0x0c0ae29eu: goto P_0c0ae29e;
case 0x0c0ae2a0u: goto P_0c0ae2a0;
case 0x0c0ae2a2u: goto P_0c0ae2a2;
case 0x0c0ae2a4u: goto P_0c0ae2a4;
case 0x0c0ae2a6u: goto P_0c0ae2a6;
case 0x0c0ae2a8u: goto P_0c0ae2a8;
case 0x0c0ae2aau: goto P_0c0ae2aa;
case 0x0c0ae2acu: goto P_0c0ae2ac;
case 0x0c0ae2aeu: goto P_0c0ae2ae;
case 0x0c0ae2b0u: goto P_0c0ae2b0;
case 0x0c0ae2b2u: goto P_0c0ae2b2;
case 0x0c0ae2b4u: goto P_0c0ae2b4;
case 0x0c0ae2b6u: goto P_0c0ae2b6;
case 0x0c0ae2b8u: goto P_0c0ae2b8;
case 0x0c0ae2bau: goto P_0c0ae2ba;
case 0x0c0ae2bcu: goto P_0c0ae2bc;
case 0x0c0ae2beu: goto P_0c0ae2be;
case 0x0c0ae2c0u: goto P_0c0ae2c0;
case 0x0c0ae2c2u: goto P_0c0ae2c2;
case 0x0c0ae2c4u: goto P_0c0ae2c4;
case 0x0c0ae2c6u: goto P_0c0ae2c6;
case 0x0c0ae2c8u: goto P_0c0ae2c8;
case 0x0c0ae2cau: goto P_0c0ae2ca;
case 0x0c0ae2ccu: goto P_0c0ae2cc;
case 0x0c0ae2ceu: goto P_0c0ae2ce;
case 0x0c0ae2d0u: goto P_0c0ae2d0;
case 0x0c0ae2d2u: goto P_0c0ae2d2;
case 0x0c0ae2d4u: goto P_0c0ae2d4;
case 0x0c0ae2d6u: goto P_0c0ae2d6;
case 0x0c0ae2d8u: goto P_0c0ae2d8;
case 0x0c0ae2dau: goto P_0c0ae2da;
case 0x0c0ae458u: goto P_0c0ae458;
case 0x0c0ae45au: goto P_0c0ae45a;
case 0x0c0ae45cu: goto P_0c0ae45c;
case 0x0c0ae45eu: goto P_0c0ae45e;
case 0x0c0ae460u: goto P_0c0ae460;
case 0x0c0ae462u: goto P_0c0ae462;
case 0x0c0ae464u: goto P_0c0ae464;
case 0x0c0ae466u: goto P_0c0ae466;
case 0x0c0ae468u: goto P_0c0ae468;
case 0x0c0ae46au: goto P_0c0ae46a;
case 0x0c0ae46cu: goto P_0c0ae46c;
case 0x0c0ae46eu: goto P_0c0ae46e;
case 0x0c0ae470u: goto P_0c0ae470;
case 0x0c0ae472u: goto P_0c0ae472;
case 0x0c0ae474u: goto P_0c0ae474;
case 0x0c0ae476u: goto P_0c0ae476;
case 0x0c0ae478u: goto P_0c0ae478;
case 0x0c0ae47au: goto P_0c0ae47a;
case 0x0c0ae47cu: goto P_0c0ae47c;
case 0x0c0ae47eu: goto P_0c0ae47e;
case 0x0c0ae480u: goto P_0c0ae480;
case 0x0c0ae482u: goto P_0c0ae482;
case 0x0c0ae484u: goto P_0c0ae484;
case 0x0c0ae486u: goto P_0c0ae486;
case 0x0c0ae488u: goto P_0c0ae488;
case 0x0c0ae48au: goto P_0c0ae48a;
case 0x0c0ae48cu: goto P_0c0ae48c;
case 0x0c0ae48eu: goto P_0c0ae48e;
case 0x0c0ae490u: goto P_0c0ae490;
case 0x0c0ae492u: goto P_0c0ae492;
case 0x0c0ae494u: goto P_0c0ae494;
case 0x0c0ae496u: goto P_0c0ae496;
case 0x0c0ae498u: goto P_0c0ae498;
case 0x0c0ae49au: goto P_0c0ae49a;
case 0x0c0ae49cu: goto P_0c0ae49c;
case 0x0c0ae49eu: goto P_0c0ae49e;
case 0x0c0ae4a0u: goto P_0c0ae4a0;
case 0x0c0ae4a2u: goto P_0c0ae4a2;
case 0x0c0ae4a4u: goto P_0c0ae4a4;
case 0x0c0ae4a6u: goto P_0c0ae4a6;
case 0x0c0ae4a8u: goto P_0c0ae4a8;
case 0x0c0ae4aau: goto P_0c0ae4aa;
case 0x0c0ae4acu: goto P_0c0ae4ac;
case 0x0c0ae4aeu: goto P_0c0ae4ae;
case 0x0c0ae4b0u: goto P_0c0ae4b0;
case 0x0c0ae4b2u: goto P_0c0ae4b2;
case 0x0c0ae4b4u: goto P_0c0ae4b4;
case 0x0c0ae4b6u: goto P_0c0ae4b6;
case 0x0c0ae4b8u: goto P_0c0ae4b8;
case 0x0c0ae4bau: goto P_0c0ae4ba;
case 0x0c0ae4bcu: goto P_0c0ae4bc;
case 0x0c0ae4beu: goto P_0c0ae4be;
case 0x0c0ae4c0u: goto P_0c0ae4c0;
case 0x0c0ae4c2u: goto P_0c0ae4c2;
case 0x0c0ae4c4u: goto P_0c0ae4c4;
case 0x0c0ae4c6u: goto P_0c0ae4c6;
case 0x0c0ae4c8u: goto P_0c0ae4c8;
case 0x0c0ae4cau: goto P_0c0ae4ca;
case 0x0c0ae4ccu: goto P_0c0ae4cc;
case 0x0c0ae4ceu: goto P_0c0ae4ce;
case 0x0c0ae4d0u: goto P_0c0ae4d0;
case 0x0c0ae4d2u: goto P_0c0ae4d2;
case 0x0c0ae4d4u: goto P_0c0ae4d4;
case 0x0c0ae4d6u: goto P_0c0ae4d6;
case 0x0c0ae4d8u: goto P_0c0ae4d8;
case 0x0c0ae4dau: goto P_0c0ae4da;
case 0x0c0ae4dcu: goto P_0c0ae4dc;
case 0x0c0ae4deu: goto P_0c0ae4de;
case 0x0c0ae4e0u: goto P_0c0ae4e0;
case 0x0c0ae4e2u: goto P_0c0ae4e2;
case 0x0c0ae4e4u: goto P_0c0ae4e4;
case 0x0c0ae4e6u: goto P_0c0ae4e6;
case 0x0c0ae4e8u: goto P_0c0ae4e8;
case 0x0c0ae4eau: goto P_0c0ae4ea;
case 0x0c0ae4ecu: goto P_0c0ae4ec;
case 0x0c0ae4eeu: goto P_0c0ae4ee;
case 0x0c0ae4f0u: goto P_0c0ae4f0;
case 0x0c0ae4f2u: goto P_0c0ae4f2;
case 0x0c0ae4f4u: goto P_0c0ae4f4;
case 0x0c0ae4f6u: goto P_0c0ae4f6;
case 0x0c0ae4f8u: goto P_0c0ae4f8;
case 0x0c0ae4fau: goto P_0c0ae4fa;
case 0x0c0ae4fcu: goto P_0c0ae4fc;
case 0x0c0ae4feu: goto P_0c0ae4fe;
case 0x0c0ae500u: goto P_0c0ae500;
case 0x0c0ae502u: goto P_0c0ae502;
case 0x0c0ae504u: goto P_0c0ae504;
case 0x0c0ae506u: goto P_0c0ae506;
case 0x0c0ae508u: goto P_0c0ae508;
case 0x0c0ae50au: goto P_0c0ae50a;
case 0x0c0ae50cu: goto P_0c0ae50c;
case 0x0c0ae50eu: goto P_0c0ae50e;
case 0x0c0ae510u: goto P_0c0ae510;
case 0x0c0ae512u: goto P_0c0ae512;
case 0x0c0ae514u: goto P_0c0ae514;
case 0x0c0ae516u: goto P_0c0ae516;
case 0x0c0ae518u: goto P_0c0ae518;
case 0x0c0ae51au: goto P_0c0ae51a;
case 0x0c0ae51cu: goto P_0c0ae51c;
case 0x0c0ae51eu: goto P_0c0ae51e;
case 0x0c0ae520u: goto P_0c0ae520;
case 0x0c0ae522u: goto P_0c0ae522;
case 0x0c0ae524u: goto P_0c0ae524;
case 0x0c0ae526u: goto P_0c0ae526;
case 0x0c0ae528u: goto P_0c0ae528;
case 0x0c0ae52au: goto P_0c0ae52a;
case 0x0c0ae6f6u: goto P_0c0ae6f6;
case 0x0c0ae6f8u: goto P_0c0ae6f8;
case 0x0c0ae6fau: goto P_0c0ae6fa;
case 0x0c0ae6fcu: goto P_0c0ae6fc;
case 0x0c0ae6feu: goto P_0c0ae6fe;
case 0x0c0ae700u: goto P_0c0ae700;
case 0x0c0ae702u: goto P_0c0ae702;
case 0x0c0ae704u: goto P_0c0ae704;
case 0x0c0ae706u: goto P_0c0ae706;
case 0x0c0ae708u: goto P_0c0ae708;
case 0x0c0ae70au: goto P_0c0ae70a;
case 0x0c0ae70cu: goto P_0c0ae70c;
case 0x0c0ae70eu: goto P_0c0ae70e;
case 0x0c0ae710u: goto P_0c0ae710;
case 0x0c0ae712u: goto P_0c0ae712;
case 0x0c0ae714u: goto P_0c0ae714;
case 0x0c0ae716u: goto P_0c0ae716;
case 0x0c0ae718u: goto P_0c0ae718;
case 0x0c0ae71au: goto P_0c0ae71a;
case 0x0c0ae71cu: goto P_0c0ae71c;
case 0x0c0ae71eu: goto P_0c0ae71e;
case 0x0c0ae720u: goto P_0c0ae720;
case 0x0c0ae722u: goto P_0c0ae722;
case 0x0c0ae724u: goto P_0c0ae724;
case 0x0c0ae726u: goto P_0c0ae726;
case 0x0c0ae728u: goto P_0c0ae728;
case 0x0c0ae72au: goto P_0c0ae72a;
case 0x0c0ae72cu: goto P_0c0ae72c;
case 0x0c0ae72eu: goto P_0c0ae72e;
case 0x0c0ae730u: goto P_0c0ae730;
case 0x0c0ae732u: goto P_0c0ae732;
case 0x0c0ae734u: goto P_0c0ae734;
case 0x0c0ae736u: goto P_0c0ae736;
case 0x0c0ae738u: goto P_0c0ae738;
case 0x0c0ae73au: goto P_0c0ae73a;
case 0x0c0ae73cu: goto P_0c0ae73c;
case 0x0c0ae73eu: goto P_0c0ae73e;
case 0x0c0ae740u: goto P_0c0ae740;
case 0x0c0ae742u: goto P_0c0ae742;
case 0x0c0ae744u: goto P_0c0ae744;
case 0x0c0ae746u: goto P_0c0ae746;
case 0x0c0ae748u: goto P_0c0ae748;
case 0x0c0ae74au: goto P_0c0ae74a;
case 0x0c0ae74cu: goto P_0c0ae74c;
case 0x0c0ae74eu: goto P_0c0ae74e;
case 0x0c0ae750u: goto P_0c0ae750;
case 0x0c0ae752u: goto P_0c0ae752;
case 0x0c0ae754u: goto P_0c0ae754;
case 0x0c0ae756u: goto P_0c0ae756;
case 0x0c0ae758u: goto P_0c0ae758;
case 0x0c0ae75au: goto P_0c0ae75a;
case 0x0c0ae75cu: goto P_0c0ae75c;
case 0x0c0ae75eu: goto P_0c0ae75e;
case 0x0c0ae760u: goto P_0c0ae760;
case 0x0c0ae762u: goto P_0c0ae762;
case 0x0c0ae764u: goto P_0c0ae764;
case 0x0c0ae766u: goto P_0c0ae766;
case 0x0c0ae768u: goto P_0c0ae768;
case 0x0c0ae76au: goto P_0c0ae76a;
case 0x0c0ae76cu: goto P_0c0ae76c;
case 0x0c0ae76eu: goto P_0c0ae76e;
case 0x0c0ae770u: goto P_0c0ae770;
case 0x0c0ae772u: goto P_0c0ae772;
case 0x0c0ae774u: goto P_0c0ae774;
case 0x0c0ae776u: goto P_0c0ae776;
case 0x0c0ae778u: goto P_0c0ae778;
case 0x0c0ae77au: goto P_0c0ae77a;
case 0x0c0ae77cu: goto P_0c0ae77c;
case 0x0c0ae77eu: goto P_0c0ae77e;
case 0x0c0ae780u: goto P_0c0ae780;
case 0x0c0ae782u: goto P_0c0ae782;
case 0x0c0ae784u: goto P_0c0ae784;
case 0x0c0ae786u: goto P_0c0ae786;
case 0x0c0ae788u: goto P_0c0ae788;
case 0x0c0ae78au: goto P_0c0ae78a;
case 0x0c0ae78cu: goto P_0c0ae78c;
case 0x0c0ae78eu: goto P_0c0ae78e;
case 0x0c0ae790u: goto P_0c0ae790;
case 0x0c0ae792u: goto P_0c0ae792;
case 0x0c0ae794u: goto P_0c0ae794;
case 0x0c0ae796u: goto P_0c0ae796;
case 0x0c0ae798u: goto P_0c0ae798;
case 0x0c0ae79au: goto P_0c0ae79a;
case 0x0c0ae79cu: goto P_0c0ae79c;
case 0x0c0ae79eu: goto P_0c0ae79e;
case 0x0c0ae7a0u: goto P_0c0ae7a0;
case 0x0c0ae7a2u: goto P_0c0ae7a2;
case 0x0c0ae7a4u: goto P_0c0ae7a4;
case 0x0c0ae7a6u: goto P_0c0ae7a6;
case 0x0c0ae7a8u: goto P_0c0ae7a8;
case 0x0c0ae7aau: goto P_0c0ae7aa;
case 0x0c0aea68u: goto P_0c0aea68;
case 0x0c0aea6au: goto P_0c0aea6a;
case 0x0c0aea6cu: goto P_0c0aea6c;
case 0x0c0aea6eu: goto P_0c0aea6e;
case 0x0c0aea70u: goto P_0c0aea70;
case 0x0c0aea72u: goto P_0c0aea72;
case 0x0c0aea74u: goto P_0c0aea74;
case 0x0c0aea76u: goto P_0c0aea76;
case 0x0c0aea78u: goto P_0c0aea78;
case 0x0c0aea7au: goto P_0c0aea7a;
case 0x0c0aea7cu: goto P_0c0aea7c;
case 0x0c0aea7eu: goto P_0c0aea7e;
case 0x0c0aea80u: goto P_0c0aea80;
case 0x0c0aea82u: goto P_0c0aea82;
case 0x0c0aea84u: goto P_0c0aea84;
case 0x0c0aea86u: goto P_0c0aea86;
case 0x0c0aea88u: goto P_0c0aea88;
case 0x0c0aea8au: goto P_0c0aea8a;
case 0x0c0aea8cu: goto P_0c0aea8c;
case 0x0c0aea8eu: goto P_0c0aea8e;
case 0x0c0aea90u: goto P_0c0aea90;
case 0x0c0aea92u: goto P_0c0aea92;
case 0x0c0aea94u: goto P_0c0aea94;
case 0x0c0aea96u: goto P_0c0aea96;
case 0x0c0aea98u: goto P_0c0aea98;
case 0x0c0aea9au: goto P_0c0aea9a;
case 0x0c0aea9cu: goto P_0c0aea9c;
case 0x0c0aea9eu: goto P_0c0aea9e;
case 0x0c0aeaa0u: goto P_0c0aeaa0;
case 0x0c0aeaa2u: goto P_0c0aeaa2;
case 0x0c0aeaa4u: goto P_0c0aeaa4;
case 0x0c0aeaa6u: goto P_0c0aeaa6;
case 0x0c0aeaa8u: goto P_0c0aeaa8;
case 0x0c0aeaaau: goto P_0c0aeaaa;
case 0x0c0aeaacu: goto P_0c0aeaac;
case 0x0c0aeaaeu: goto P_0c0aeaae;
case 0x0c0aeab0u: goto P_0c0aeab0;
case 0x0c0aeab2u: goto P_0c0aeab2;
case 0x0c0aeab4u: goto P_0c0aeab4;
case 0x0c0aeab6u: goto P_0c0aeab6;
case 0x0c0aeab8u: goto P_0c0aeab8;
case 0x0c0aeabau: goto P_0c0aeaba;
case 0x0c0aeabcu: goto P_0c0aeabc;
case 0x0c0aeabeu: goto P_0c0aeabe;
case 0x0c0aeac0u: goto P_0c0aeac0;
case 0x0c0aeac2u: goto P_0c0aeac2;
case 0x0c0aeac4u: goto P_0c0aeac4;
case 0x0c0aeac6u: goto P_0c0aeac6;
case 0x0c0aeac8u: goto P_0c0aeac8;
case 0x0c0aeacau: goto P_0c0aeaca;
case 0x0c0aeaccu: goto P_0c0aeacc;
case 0x0c0aeaceu: goto P_0c0aeace;
case 0x0c0aead0u: goto P_0c0aead0;
case 0x0c0aead2u: goto P_0c0aead2;
case 0x0c0aead4u: goto P_0c0aead4;
case 0x0c0aead6u: goto P_0c0aead6;
case 0x0c0aead8u: goto P_0c0aead8;
case 0x0c0aeadau: goto P_0c0aeada;
case 0x0c0aeadcu: goto P_0c0aeadc;
case 0x0c0aeadeu: goto P_0c0aeade;
case 0x0c0aeae0u: goto P_0c0aeae0;
case 0x0c0aeb00u: goto P_0c0aeb00;
case 0x0c0aeb02u: goto P_0c0aeb02;
case 0x0c0aeb04u: goto P_0c0aeb04;
case 0x0c0aeb06u: goto P_0c0aeb06;
case 0x0c0aeb08u: goto P_0c0aeb08;
case 0x0c0aeb0au: goto P_0c0aeb0a;
case 0x0c0aeb0cu: goto P_0c0aeb0c;
case 0x0c0aeb0eu: goto P_0c0aeb0e;
case 0x0c0aeb10u: goto P_0c0aeb10;
case 0x0c0aeb12u: goto P_0c0aeb12;
case 0x0c0aeb14u: goto P_0c0aeb14;
case 0x0c0aeb16u: goto P_0c0aeb16;
case 0x0c0aeb18u: goto P_0c0aeb18;
case 0x0c0aeb1au: goto P_0c0aeb1a;
case 0x0c0aeb1cu: goto P_0c0aeb1c;
case 0x0c0aeb1eu: goto P_0c0aeb1e;
case 0x0c0aeb20u: goto P_0c0aeb20;
case 0x0c0aeb22u: goto P_0c0aeb22;
case 0x0c0aeb24u: goto P_0c0aeb24;
case 0x0c0aeb26u: goto P_0c0aeb26;
case 0x0c0aeb28u: goto P_0c0aeb28;
case 0x0c0aeb2au: goto P_0c0aeb2a;
case 0x0c0aeb2cu: goto P_0c0aeb2c;
case 0x0c0aeb2eu: goto P_0c0aeb2e;
case 0x0c0aeb30u: goto P_0c0aeb30;
case 0x0c0aeb32u: goto P_0c0aeb32;
case 0x0c0aeb34u: goto P_0c0aeb34;
case 0x0c0aeb36u: goto P_0c0aeb36;
case 0x0c0aeb38u: goto P_0c0aeb38;
case 0x0c0aeb3au: goto P_0c0aeb3a;
case 0x0c0aeb3cu: goto P_0c0aeb3c;
case 0x0c0aeb3eu: goto P_0c0aeb3e;
case 0x0c0aeb40u: goto P_0c0aeb40;
case 0x0c0aeb42u: goto P_0c0aeb42;
case 0x0c0aeb44u: goto P_0c0aeb44;
case 0x0c0aeb46u: goto P_0c0aeb46;
case 0x0c0aeb48u: goto P_0c0aeb48;
case 0x0c0aeb4au: goto P_0c0aeb4a;
case 0x0c0af9e4u: goto P_0c0af9e4;
case 0x0c0af9e6u: goto P_0c0af9e6;
case 0x0c0af9e8u: goto P_0c0af9e8;
case 0x0c0af9eau: goto P_0c0af9ea;
case 0x0c0af9ecu: goto P_0c0af9ec;
case 0x0c0af9eeu: goto P_0c0af9ee;
case 0x0c0af9f0u: goto P_0c0af9f0;
case 0x0c0af9f2u: goto P_0c0af9f2;
case 0x0c0af9f4u: goto P_0c0af9f4;
case 0x0c0af9f6u: goto P_0c0af9f6;
case 0x0c0af9f8u: goto P_0c0af9f8;
case 0x0c0af9fau: goto P_0c0af9fa;
case 0x0c0af9fcu: goto P_0c0af9fc;
case 0x0c0af9feu: goto P_0c0af9fe;
case 0x0c0afa00u: goto P_0c0afa00;
case 0x0c0afa02u: goto P_0c0afa02;
case 0x0c0afa04u: goto P_0c0afa04;
case 0x0c0afa06u: goto P_0c0afa06;
case 0x0c0afa08u: goto P_0c0afa08;
case 0x0c0afa0au: goto P_0c0afa0a;
case 0x0c0afa0cu: goto P_0c0afa0c;
case 0x0c0afa0eu: goto P_0c0afa0e;
case 0x0c0afa10u: goto P_0c0afa10;
case 0x0c0afa12u: goto P_0c0afa12;
case 0x0c0afa14u: goto P_0c0afa14;
case 0x0c0afa16u: goto P_0c0afa16;
case 0x0c0afa18u: goto P_0c0afa18;
case 0x0c0afa1au: goto P_0c0afa1a;
case 0x0c0afa1cu: goto P_0c0afa1c;
case 0x0c0afa1eu: goto P_0c0afa1e;
case 0x0c0afa20u: goto P_0c0afa20;
case 0x0c0afa22u: goto P_0c0afa22;
case 0x0c0afa24u: goto P_0c0afa24;
case 0x0c0afa26u: goto P_0c0afa26;
case 0x0c0afa28u: goto P_0c0afa28;
case 0x0c0afa2au: goto P_0c0afa2a;
case 0x0c0afa2cu: goto P_0c0afa2c;
case 0x0c0afa2eu: goto P_0c0afa2e;
case 0x0c0afa30u: goto P_0c0afa30;
case 0x0c0afa32u: goto P_0c0afa32;
case 0x0c0afa34u: goto P_0c0afa34;
case 0x0c0afa36u: goto P_0c0afa36;
case 0x0c0afa38u: goto P_0c0afa38;
case 0x0c0afa3au: goto P_0c0afa3a;
case 0x0c0afa3cu: goto P_0c0afa3c;
case 0x0c0afa3eu: goto P_0c0afa3e;
case 0x0c0afa40u: goto P_0c0afa40;
case 0x0c0afa42u: goto P_0c0afa42;
case 0x0c0afa44u: goto P_0c0afa44;
case 0x0c0afa46u: goto P_0c0afa46;
case 0x0c0afa48u: goto P_0c0afa48;
case 0x0c0afa4au: goto P_0c0afa4a;
case 0x0c0afa4cu: goto P_0c0afa4c;
case 0x0c0afa4eu: goto P_0c0afa4e;
case 0x0c0afa50u: goto P_0c0afa50;
case 0x0c0afa52u: goto P_0c0afa52;
case 0x0c0afa54u: goto P_0c0afa54;
case 0x0c0afa56u: goto P_0c0afa56;
case 0x0c0afa58u: goto P_0c0afa58;
case 0x0c0afa5au: goto P_0c0afa5a;
case 0x0c0afa5cu: goto P_0c0afa5c;
case 0x0c0afa5eu: goto P_0c0afa5e;
case 0x0c0afa60u: goto P_0c0afa60;
case 0x0c0afa62u: goto P_0c0afa62;
case 0x0c0afa64u: goto P_0c0afa64;
case 0x0c0afa66u: goto P_0c0afa66;
case 0x0c0afa68u: goto P_0c0afa68;
case 0x0c0afa6au: goto P_0c0afa6a;
case 0x0c0afa6cu: goto P_0c0afa6c;
case 0x0c0afa6eu: goto P_0c0afa6e;
case 0x0c0afa70u: goto P_0c0afa70;
case 0x0c0afa72u: goto P_0c0afa72;
case 0x0c0afa74u: goto P_0c0afa74;
case 0x0c0afa76u: goto P_0c0afa76;
case 0x0c0afa78u: goto P_0c0afa78;
case 0x0c0afa7au: goto P_0c0afa7a;
case 0x0c0afa7cu: goto P_0c0afa7c;
case 0x0c0afa7eu: goto P_0c0afa7e;
case 0x0c0afa80u: goto P_0c0afa80;
case 0x0c0afa82u: goto P_0c0afa82;
case 0x0c0afa84u: goto P_0c0afa84;
case 0x0c0afa86u: goto P_0c0afa86;
case 0x0c0afa88u: goto P_0c0afa88;
case 0x0c0afa8au: goto P_0c0afa8a;
case 0x0c0afa8cu: goto P_0c0afa8c;
case 0x0c0afa8eu: goto P_0c0afa8e;
case 0x0c0afa90u: goto P_0c0afa90;
case 0x0c0afa92u: goto P_0c0afa92;
case 0x0c0afa94u: goto P_0c0afa94;
case 0x0c0afa96u: goto P_0c0afa96;
case 0x0c0afa98u: goto P_0c0afa98;
case 0x0c0afa9au: goto P_0c0afa9a;
case 0x0c0afa9cu: goto P_0c0afa9c;
case 0x0c0afa9eu: goto P_0c0afa9e;
case 0x0c0afaa0u: goto P_0c0afaa0;
case 0x0c0afaa2u: goto P_0c0afaa2;
case 0x0c0afaa4u: goto P_0c0afaa4;
case 0x0c0afaa6u: goto P_0c0afaa6;
case 0x0c0afaa8u: goto P_0c0afaa8;
case 0x0c0afaaau: goto P_0c0afaaa;
case 0x0c0afaacu: goto P_0c0afaac;
case 0x0c0afaaeu: goto P_0c0afaae;
case 0x0c0afab0u: goto P_0c0afab0;
case 0x0c0afab2u: goto P_0c0afab2;
case 0x0c0afab4u: goto P_0c0afab4;
case 0x0c0afab6u: goto P_0c0afab6;
case 0x0c0afaf0u: goto P_0c0afaf0;
case 0x0c0afaf2u: goto P_0c0afaf2;
case 0x0c0afaf4u: goto P_0c0afaf4;
case 0x0c0afaf6u: goto P_0c0afaf6;
case 0x0c0afaf8u: goto P_0c0afaf8;
case 0x0c0afafau: goto P_0c0afafa;
case 0x0c0afafcu: goto P_0c0afafc;
case 0x0c0afafeu: goto P_0c0afafe;
case 0x0c0afb00u: goto P_0c0afb00;
case 0x0c0afb02u: goto P_0c0afb02;
case 0x0c0afb04u: goto P_0c0afb04;
case 0x0c0afb06u: goto P_0c0afb06;
case 0x0c0afb08u: goto P_0c0afb08;
case 0x0c0afb0au: goto P_0c0afb0a;
case 0x0c0afb0cu: goto P_0c0afb0c;
case 0x0c0afb0eu: goto P_0c0afb0e;
case 0x0c0afb10u: goto P_0c0afb10;
case 0x0c0afb12u: goto P_0c0afb12;
case 0x0c0afb14u: goto P_0c0afb14;
case 0x0c0afb16u: goto P_0c0afb16;
case 0x0c0afb18u: goto P_0c0afb18;
case 0x0c0afb1au: goto P_0c0afb1a;
case 0x0c0afb1cu: goto P_0c0afb1c;
case 0x0c0afb1eu: goto P_0c0afb1e;
case 0x0c0afb20u: goto P_0c0afb20;
case 0x0c0afb22u: goto P_0c0afb22;
case 0x0c0c1becu: goto P_0c0c1bec;
case 0x0c0c1beeu: goto P_0c0c1bee;
case 0x0c0c1bf0u: goto P_0c0c1bf0;
case 0x0c0c1bf2u: goto P_0c0c1bf2;
case 0x0c0c1bf4u: goto P_0c0c1bf4;
case 0x0c0c1bf6u: goto P_0c0c1bf6;
case 0x0c0c1bf8u: goto P_0c0c1bf8;
case 0x0c0c1bfau: goto P_0c0c1bfa;
case 0x0c0c1bfcu: goto P_0c0c1bfc;
case 0x0c0c1bfeu: goto P_0c0c1bfe;
case 0x0c0c1c00u: goto P_0c0c1c00;
case 0x0c0c1c02u: goto P_0c0c1c02;
case 0x0c0c1c04u: goto P_0c0c1c04;
case 0x0c0c1c06u: goto P_0c0c1c06;
case 0x0c0c1c08u: goto P_0c0c1c08;
case 0x0c0c1c0au: goto P_0c0c1c0a;
case 0x0c0c1c0cu: goto P_0c0c1c0c;
case 0x0c0c1c0eu: goto P_0c0c1c0e;
case 0x0c0c1c10u: goto P_0c0c1c10;
case 0x0c0c1c12u: goto P_0c0c1c12;
case 0x0c0c1c14u: goto P_0c0c1c14;
case 0x0c0c1c16u: goto P_0c0c1c16;
case 0x0c0c1c18u: goto P_0c0c1c18;
case 0x0c0c1c1au: goto P_0c0c1c1a;
case 0x0c0c1c1cu: goto P_0c0c1c1c;
case 0x0c0c1c1eu: goto P_0c0c1c1e;
case 0x0c0c1c20u: goto P_0c0c1c20;
case 0x0c0c1c22u: goto P_0c0c1c22;
case 0x0c0c1c24u: goto P_0c0c1c24;
case 0x0c0c1c26u: goto P_0c0c1c26;
case 0x0c0c1c28u: goto P_0c0c1c28;
case 0x0c0c1c2au: goto P_0c0c1c2a;
case 0x0c0c1c2cu: goto P_0c0c1c2c;
case 0x0c0c1c2eu: goto P_0c0c1c2e;
case 0x0c0c1c30u: goto P_0c0c1c30;
case 0x0c0c1c32u: goto P_0c0c1c32;
case 0x0c0c1c34u: goto P_0c0c1c34;
case 0x0c0c1c36u: goto P_0c0c1c36;
case 0x0c0c1c38u: goto P_0c0c1c38;
case 0x0c0c1c3au: goto P_0c0c1c3a;
case 0x0c0c1c3cu: goto P_0c0c1c3c;
case 0x0c0c1c3eu: goto P_0c0c1c3e;
case 0x0c0c1c40u: goto P_0c0c1c40;
case 0x0c0c1c42u: goto P_0c0c1c42;
case 0x0c0c1c44u: goto P_0c0c1c44;
case 0x0c0c1c46u: goto P_0c0c1c46;
case 0x0c0c1c48u: goto P_0c0c1c48;
case 0x0c0c1c4au: goto P_0c0c1c4a;
case 0x0c0c1c4cu: goto P_0c0c1c4c;
case 0x0c0c1c4eu: goto P_0c0c1c4e;
case 0x0c0c1c50u: goto P_0c0c1c50;
case 0x0c0c1c52u: goto P_0c0c1c52;
case 0x0c0c1c54u: goto P_0c0c1c54;
case 0x0c0c1c56u: goto P_0c0c1c56;
case 0x0c0c1c58u: goto P_0c0c1c58;
case 0x0c0c1c5au: goto P_0c0c1c5a;
case 0x0c0c1c5cu: goto P_0c0c1c5c;
case 0x0c0c1c5eu: goto P_0c0c1c5e;
case 0x0c0c1c60u: goto P_0c0c1c60;
case 0x0c0c1c62u: goto P_0c0c1c62;
case 0x0c0c1c64u: goto P_0c0c1c64;
case 0x0c0c1c66u: goto P_0c0c1c66;
case 0x0c0c1c68u: goto P_0c0c1c68;
case 0x0c0c1c6au: goto P_0c0c1c6a;
case 0x0c0c1c6cu: goto P_0c0c1c6c;
case 0x0c0c1c6eu: goto P_0c0c1c6e;
case 0x0c0c1c70u: goto P_0c0c1c70;
case 0x0c0c1c72u: goto P_0c0c1c72;
case 0x0c0c1c74u: goto P_0c0c1c74;
case 0x0c0c1c76u: goto P_0c0c1c76;
case 0x0c0c1c78u: goto P_0c0c1c78;
case 0x0c0c1c7au: goto P_0c0c1c7a;
case 0x0c0c1c7cu: goto P_0c0c1c7c;
case 0x0c0c1c7eu: goto P_0c0c1c7e;
case 0x0c0c1c80u: goto P_0c0c1c80;
case 0x0c0c1c82u: goto P_0c0c1c82;
case 0x0c0c1c84u: goto P_0c0c1c84;
case 0x0c0c1c86u: goto P_0c0c1c86;
case 0x0c0c1c88u: goto P_0c0c1c88;
case 0x0c0c1c8au: goto P_0c0c1c8a;
case 0x0c0c1c8cu: goto P_0c0c1c8c;
case 0x0c0c1c8eu: goto P_0c0c1c8e;
case 0x0c0c1c90u: goto P_0c0c1c90;
case 0x0c0c1c92u: goto P_0c0c1c92;
case 0x0c0c1c94u: goto P_0c0c1c94;
case 0x0c0c1c96u: goto P_0c0c1c96;
case 0x0c0c1c98u: goto P_0c0c1c98;
case 0x0c0c1c9au: goto P_0c0c1c9a;
case 0x0c0c1c9cu: goto P_0c0c1c9c;
case 0x0c0c1c9eu: goto P_0c0c1c9e;
case 0x0c0c1ca0u: goto P_0c0c1ca0;
case 0x0c0c1ca2u: goto P_0c0c1ca2;
case 0x0c0c1ca4u: goto P_0c0c1ca4;
case 0x0c0c1ca6u: goto P_0c0c1ca6;
case 0x0c0c1ca8u: goto P_0c0c1ca8;
case 0x0c0c1caau: goto P_0c0c1caa;
case 0x0c0c1cacu: goto P_0c0c1cac;
case 0x0c0c1caeu: goto P_0c0c1cae;
case 0x0c0c1cb0u: goto P_0c0c1cb0;
case 0x0c0c1cb2u: goto P_0c0c1cb2;
case 0x0c0c1cb4u: goto P_0c0c1cb4;
case 0x0c0c1cb6u: goto P_0c0c1cb6;
case 0x0c0c1cb8u: goto P_0c0c1cb8;
case 0x0c0c1cbau: goto P_0c0c1cba;
case 0x0c0c1cbcu: goto P_0c0c1cbc;
case 0x0c0c1cbeu: goto P_0c0c1cbe;
case 0x0c0c1cc0u: goto P_0c0c1cc0;
case 0x0c0c1cc2u: goto P_0c0c1cc2;
case 0x0c0c1ce4u: goto P_0c0c1ce4;
case 0x0c0c1ce6u: goto P_0c0c1ce6;
case 0x0c0c1ce8u: goto P_0c0c1ce8;
case 0x0c0c1ceau: goto P_0c0c1cea;
case 0x0c0c1cecu: goto P_0c0c1cec;
case 0x0c0c1ceeu: goto P_0c0c1cee;
case 0x0c0c1cf0u: goto P_0c0c1cf0;
case 0x0c0c1cf2u: goto P_0c0c1cf2;
case 0x0c0c1cf4u: goto P_0c0c1cf4;
case 0x0c0c1cf6u: goto P_0c0c1cf6;
case 0x0c0c1cf8u: goto P_0c0c1cf8;
case 0x0c0c1cfau: goto P_0c0c1cfa;
case 0x0c0c1cfcu: goto P_0c0c1cfc;
case 0x0c0c1cfeu: goto P_0c0c1cfe;
case 0x0c0c1d00u: goto P_0c0c1d00;
case 0x0c0c1d02u: goto P_0c0c1d02;
case 0x0c0c1d04u: goto P_0c0c1d04;
case 0x0c0c1d06u: goto P_0c0c1d06;
case 0x0c0c1d08u: goto P_0c0c1d08;
case 0x0c0c1d0au: goto P_0c0c1d0a;
case 0x0c0c1d0cu: goto P_0c0c1d0c;
case 0x0c0c1d0eu: goto P_0c0c1d0e;
case 0x0c0c1d10u: goto P_0c0c1d10;
case 0x0c0c1d12u: goto P_0c0c1d12;
case 0x0c0c1d14u: goto P_0c0c1d14;
case 0x0c0c1d16u: goto P_0c0c1d16;
case 0x0c0c1d18u: goto P_0c0c1d18;
case 0x0c0c1d1au: goto P_0c0c1d1a;
case 0x0c0c1d1cu: goto P_0c0c1d1c;
case 0x0c0c1d1eu: goto P_0c0c1d1e;
case 0x0c0c1d20u: goto P_0c0c1d20;
case 0x0c0c1d22u: goto P_0c0c1d22;
case 0x0c0c1d24u: goto P_0c0c1d24;
case 0x0c0c1d26u: goto P_0c0c1d26;
case 0x0c0c1d28u: goto P_0c0c1d28;
case 0x0c0c1d2au: goto P_0c0c1d2a;
case 0x0c0c1d2cu: goto P_0c0c1d2c;
case 0x0c0c1d2eu: goto P_0c0c1d2e;
case 0x0c0c1d30u: goto P_0c0c1d30;
case 0x0c0c1d32u: goto P_0c0c1d32;
case 0x0c0c1d34u: goto P_0c0c1d34;
case 0x0c0c1d36u: goto P_0c0c1d36;
case 0x0c0c1d38u: goto P_0c0c1d38;
case 0x0c0c1d3au: goto P_0c0c1d3a;
case 0x0c0c1d3cu: goto P_0c0c1d3c;
case 0x0c0c1d3eu: goto P_0c0c1d3e;
case 0x0c0c1d40u: goto P_0c0c1d40;
case 0x0c0c1d42u: goto P_0c0c1d42;
case 0x0c0c1d44u: goto P_0c0c1d44;
case 0x0c0c1d46u: goto P_0c0c1d46;
case 0x0c0c1d48u: goto P_0c0c1d48;
case 0x0c0c1d4au: goto P_0c0c1d4a;
case 0x0c0c1d4cu: goto P_0c0c1d4c;
case 0x0c0c1d4eu: goto P_0c0c1d4e;
case 0x0c0c1d50u: goto P_0c0c1d50;
case 0x0c0c1d52u: goto P_0c0c1d52;
case 0x0c0c1d54u: goto P_0c0c1d54;
case 0x0c0c1d56u: goto P_0c0c1d56;
case 0x0c0c1d58u: goto P_0c0c1d58;
case 0x0c0c1d5au: goto P_0c0c1d5a;
case 0x0c0c1d5cu: goto P_0c0c1d5c;
case 0x0c0c1d5eu: goto P_0c0c1d5e;
case 0x0c0c1d60u: goto P_0c0c1d60;
case 0x0c0c1d62u: goto P_0c0c1d62;
case 0x0c0c1d64u: goto P_0c0c1d64;
case 0x0c0c1d66u: goto P_0c0c1d66;
case 0x0c0c1d68u: goto P_0c0c1d68;
case 0x0c0c1d6au: goto P_0c0c1d6a;
case 0x0c0c1d6cu: goto P_0c0c1d6c;
case 0x0c0c1d6eu: goto P_0c0c1d6e;
case 0x0c0c1d70u: goto P_0c0c1d70;
case 0x0c0c1d72u: goto P_0c0c1d72;
case 0x0c0c1d74u: goto P_0c0c1d74;
case 0x0c0c1d76u: goto P_0c0c1d76;
case 0x0c0c1d78u: goto P_0c0c1d78;
case 0x0c0c1d7au: goto P_0c0c1d7a;
case 0x0c0c1d7cu: goto P_0c0c1d7c;
case 0x0c0c1d7eu: goto P_0c0c1d7e;
case 0x0c0c1d80u: goto P_0c0c1d80;
case 0x0c0c1d82u: goto P_0c0c1d82;
case 0x0c0c1d84u: goto P_0c0c1d84;
case 0x0c0c7114u: goto P_0c0c7114;
case 0x0c0c7116u: goto P_0c0c7116;
case 0x0c0c7118u: goto P_0c0c7118;
case 0x0c0c711au: goto P_0c0c711a;
case 0x0c0c711cu: goto P_0c0c711c;
case 0x0c0c711eu: goto P_0c0c711e;
case 0x0c0c7120u: goto P_0c0c7120;
case 0x0c0c7122u: goto P_0c0c7122;
case 0x0c0c7124u: goto P_0c0c7124;
case 0x0c0c7126u: goto P_0c0c7126;
case 0x0c0c7128u: goto P_0c0c7128;
case 0x0c0c712au: goto P_0c0c712a;
case 0x0c0c712cu: goto P_0c0c712c;
case 0x0c0c712eu: goto P_0c0c712e;
case 0x0c0c7130u: goto P_0c0c7130;
case 0x0c0c7132u: goto P_0c0c7132;
case 0x0c0c7134u: goto P_0c0c7134;
case 0x0c0c7136u: goto P_0c0c7136;
case 0x0c0c7138u: goto P_0c0c7138;
case 0x0c0c713au: goto P_0c0c713a;
case 0x0c0c713cu: goto P_0c0c713c;
case 0x0c0c713eu: goto P_0c0c713e;
case 0x0c0c7140u: goto P_0c0c7140;
case 0x0c0c7142u: goto P_0c0c7142;
case 0x0c0c7144u: goto P_0c0c7144;
case 0x0c0c7146u: goto P_0c0c7146;
case 0x0c0c7148u: goto P_0c0c7148;
case 0x0c0c714au: goto P_0c0c714a;
case 0x0c0c714cu: goto P_0c0c714c;
case 0x0c0c714eu: goto P_0c0c714e;
case 0x0c0c7150u: goto P_0c0c7150;
case 0x0c0c7152u: goto P_0c0c7152;
case 0x0c0c7154u: goto P_0c0c7154;
case 0x0c0c7156u: goto P_0c0c7156;
case 0x0c0c7158u: goto P_0c0c7158;
case 0x0c0c715au: goto P_0c0c715a;
case 0x0c0c715cu: goto P_0c0c715c;
case 0x0c0c715eu: goto P_0c0c715e;
case 0x0c0c7160u: goto P_0c0c7160;
case 0x0c0c7162u: goto P_0c0c7162;
case 0x0c0c7164u: goto P_0c0c7164;
case 0x0c0c7166u: goto P_0c0c7166;
case 0x0c0c7168u: goto P_0c0c7168;
case 0x0c0c716au: goto P_0c0c716a;
case 0x0c0c716cu: goto P_0c0c716c;
case 0x0c0c716eu: goto P_0c0c716e;
case 0x0c0c7170u: goto P_0c0c7170;
case 0x0c0c7172u: goto P_0c0c7172;
case 0x0c0c7174u: goto P_0c0c7174;
case 0x0c0c7176u: goto P_0c0c7176;
case 0x0c0c7178u: goto P_0c0c7178;
case 0x0c0c717au: goto P_0c0c717a;
case 0x0c0c717cu: goto P_0c0c717c;
case 0x0c0c717eu: goto P_0c0c717e;
case 0x0c0c7180u: goto P_0c0c7180;
case 0x0c0c7182u: goto P_0c0c7182;
case 0x0c0c7184u: goto P_0c0c7184;
case 0x0c0c7186u: goto P_0c0c7186;
case 0x0c0c7188u: goto P_0c0c7188;
case 0x0c0c718au: goto P_0c0c718a;
case 0x0c0c718cu: goto P_0c0c718c;
case 0x0c0c718eu: goto P_0c0c718e;
case 0x0c0c7190u: goto P_0c0c7190;
case 0x0c0c7192u: goto P_0c0c7192;
case 0x0c0c7194u: goto P_0c0c7194;
case 0x0c0c7196u: goto P_0c0c7196;
case 0x0c0c7198u: goto P_0c0c7198;
case 0x0c0c719au: goto P_0c0c719a;
case 0x0c0c719cu: goto P_0c0c719c;
case 0x0c0c719eu: goto P_0c0c719e;
case 0x0c0c71a0u: goto P_0c0c71a0;
case 0x0c0c71a2u: goto P_0c0c71a2;
case 0x0c0c71a4u: goto P_0c0c71a4;
case 0x0c0c71a6u: goto P_0c0c71a6;
case 0x0c0c71a8u: goto P_0c0c71a8;
case 0x0c0c71aau: goto P_0c0c71aa;
case 0x0c0c71acu: goto P_0c0c71ac;
case 0x0c0c71aeu: goto P_0c0c71ae;
case 0x0c0c71b0u: goto P_0c0c71b0;
case 0x0c0c71b2u: goto P_0c0c71b2;
case 0x0c0c71b4u: goto P_0c0c71b4;
case 0x0c0c71b6u: goto P_0c0c71b6;
case 0x0c0c71b8u: goto P_0c0c71b8;
case 0x0c0c71bau: goto P_0c0c71ba;
case 0x0c0c71bcu: goto P_0c0c71bc;
case 0x0c0c71beu: goto P_0c0c71be;
case 0x0c0c71c0u: goto P_0c0c71c0;
case 0x0c0c71c2u: goto P_0c0c71c2;
case 0x0c0c71c4u: goto P_0c0c71c4;
case 0x0c0c71c6u: goto P_0c0c71c6;
case 0x0c0c71c8u: goto P_0c0c71c8;
case 0x0c0c71cau: goto P_0c0c71ca;
case 0x0c0c71ccu: goto P_0c0c71cc;
case 0x0c0c71ceu: goto P_0c0c71ce;
case 0x0c0c71d0u: goto P_0c0c71d0;
case 0x0c0c71d2u: goto P_0c0c71d2;
case 0x0c0c71d4u: goto P_0c0c71d4;
case 0x0c0c71d6u: goto P_0c0c71d6;
case 0x0c0c71d8u: goto P_0c0c71d8;
case 0x0c0c71dau: goto P_0c0c71da;
case 0x0c0c71dcu: goto P_0c0c71dc;
case 0x0c0c71deu: goto P_0c0c71de;
case 0x0c0c71e0u: goto P_0c0c71e0;
case 0x0c0c71e2u: goto P_0c0c71e2;
case 0x0c0c71e4u: goto P_0c0c71e4;
case 0x0c0c71e6u: goto P_0c0c71e6;
case 0x0c0c71e8u: goto P_0c0c71e8;
case 0x0c0c71eau: goto P_0c0c71ea;
case 0x0c0c71ecu: goto P_0c0c71ec;
case 0x0c0c721cu: goto P_0c0c721c;
case 0x0c0c721eu: goto P_0c0c721e;
case 0x0c0c7220u: goto P_0c0c7220;
case 0x0c0c7222u: goto P_0c0c7222;
case 0x0c0c7224u: goto P_0c0c7224;
case 0x0c0c7226u: goto P_0c0c7226;
case 0x0c0c7228u: goto P_0c0c7228;
case 0x0c0c722au: goto P_0c0c722a;
case 0x0c0c722cu: goto P_0c0c722c;
case 0x0c0c722eu: goto P_0c0c722e;
case 0x0c0c7230u: goto P_0c0c7230;
case 0x0c0c7232u: goto P_0c0c7232;
case 0x0c0c7234u: goto P_0c0c7234;
case 0x0c0c7236u: goto P_0c0c7236;
case 0x0c0c7238u: goto P_0c0c7238;
case 0x0c0c723au: goto P_0c0c723a;
case 0x0c0c723cu: goto P_0c0c723c;
case 0x0c0c723eu: goto P_0c0c723e;
case 0x0c0c7240u: goto P_0c0c7240;
case 0x0c0c7242u: goto P_0c0c7242;
case 0x0c0c7244u: goto P_0c0c7244;
case 0x0c0c7246u: goto P_0c0c7246;
case 0x0c0c7248u: goto P_0c0c7248;
case 0x0c0c724au: goto P_0c0c724a;
case 0x0c0c724cu: goto P_0c0c724c;
case 0x0c0c724eu: goto P_0c0c724e;
case 0x0c0c7250u: goto P_0c0c7250;
case 0x0c0c7252u: goto P_0c0c7252;
case 0x0c0c7254u: goto P_0c0c7254;
case 0x0c0c7256u: goto P_0c0c7256;
case 0x0c0c7258u: goto P_0c0c7258;
case 0x0c0c725au: goto P_0c0c725a;
case 0x0c0c725cu: goto P_0c0c725c;
case 0x0c0c725eu: goto P_0c0c725e;
case 0x0c0c7260u: goto P_0c0c7260;
case 0x0c0c7262u: goto P_0c0c7262;
case 0x0c0c7264u: goto P_0c0c7264;
case 0x0c0c7266u: goto P_0c0c7266;
case 0x0c0c7268u: goto P_0c0c7268;
case 0x0c0c726au: goto P_0c0c726a;
case 0x0c0c726cu: goto P_0c0c726c;
case 0x0c0c726eu: goto P_0c0c726e;
case 0x0c0c7270u: goto P_0c0c7270;
case 0x0c0c7272u: goto P_0c0c7272;
case 0x0c0c7274u: goto P_0c0c7274;
case 0x0c0c7276u: goto P_0c0c7276;
case 0x0c0c7278u: goto P_0c0c7278;
case 0x0c0c727au: goto P_0c0c727a;
case 0x0c0c727cu: goto P_0c0c727c;
case 0x0c0c727eu: goto P_0c0c727e;
case 0x0c0c7280u: goto P_0c0c7280;
case 0x0c0c7282u: goto P_0c0c7282;
case 0x0c0c7284u: goto P_0c0c7284;
case 0x0c0c7286u: goto P_0c0c7286;
case 0x0c0c7288u: goto P_0c0c7288;
case 0x0c0c728au: goto P_0c0c728a;
case 0x0c0c728cu: goto P_0c0c728c;
case 0x0c0c728eu: goto P_0c0c728e;
case 0x0c0c7290u: goto P_0c0c7290;
case 0x0c0c7292u: goto P_0c0c7292;
case 0x0c0c7294u: goto P_0c0c7294;
case 0x0c0c7296u: goto P_0c0c7296;
case 0x0c0c7298u: goto P_0c0c7298;
case 0x0c0c729au: goto P_0c0c729a;
case 0x0c0c729cu: goto P_0c0c729c;
case 0x0c0c729eu: goto P_0c0c729e;
case 0x0c0c72a0u: goto P_0c0c72a0;
case 0x0c0c72a2u: goto P_0c0c72a2;
case 0x0c0c72a4u: goto P_0c0c72a4;
case 0x0c0c72a6u: goto P_0c0c72a6;
case 0x0c0c72a8u: goto P_0c0c72a8;
case 0x0c0c72aau: goto P_0c0c72aa;
case 0x0c0c72acu: goto P_0c0c72ac;
case 0x0c0c72aeu: goto P_0c0c72ae;
case 0x0c0c72b0u: goto P_0c0c72b0;
case 0x0c0c72b2u: goto P_0c0c72b2;
case 0x0c0c9dc8u: goto P_0c0c9dc8;
case 0x0c0c9dcau: goto P_0c0c9dca;
case 0x0c0c9dccu: goto P_0c0c9dcc;
case 0x0c0c9dceu: goto P_0c0c9dce;
case 0x0c0c9dd0u: goto P_0c0c9dd0;
case 0x0c0c9dd2u: goto P_0c0c9dd2;
case 0x0c0c9dd4u: goto P_0c0c9dd4;
case 0x0c0c9dd6u: goto P_0c0c9dd6;
case 0x0c0c9dd8u: goto P_0c0c9dd8;
case 0x0c0c9ddau: goto P_0c0c9dda;
case 0x0c0c9ddcu: goto P_0c0c9ddc;
case 0x0c0c9ddeu: goto P_0c0c9dde;
case 0x0c0c9de0u: goto P_0c0c9de0;
case 0x0c0c9de2u: goto P_0c0c9de2;
case 0x0c0c9de4u: goto P_0c0c9de4;
case 0x0c0c9de6u: goto P_0c0c9de6;
case 0x0c0c9de8u: goto P_0c0c9de8;
case 0x0c0c9deau: goto P_0c0c9dea;
case 0x0c0c9decu: goto P_0c0c9dec;
case 0x0c0c9deeu: goto P_0c0c9dee;
case 0x0c0c9df0u: goto P_0c0c9df0;
case 0x0c0c9df2u: goto P_0c0c9df2;
case 0x0c0c9df4u: goto P_0c0c9df4;
case 0x0c0c9df6u: goto P_0c0c9df6;
case 0x0c0c9df8u: goto P_0c0c9df8;
case 0x0c0c9dfau: goto P_0c0c9dfa;
case 0x0c0c9dfcu: goto P_0c0c9dfc;
case 0x0c0c9dfeu: goto P_0c0c9dfe;
case 0x0c0c9e00u: goto P_0c0c9e00;
case 0x0c0c9e02u: goto P_0c0c9e02;
case 0x0c0c9e04u: goto P_0c0c9e04;
case 0x0c0c9e06u: goto P_0c0c9e06;
case 0x0c0c9e08u: goto P_0c0c9e08;
case 0x0c0c9e0au: goto P_0c0c9e0a;
case 0x0c0c9e0cu: goto P_0c0c9e0c;
case 0x0c0c9e0eu: goto P_0c0c9e0e;
case 0x0c0c9e10u: goto P_0c0c9e10;
case 0x0c0c9e12u: goto P_0c0c9e12;
case 0x0c0c9e14u: goto P_0c0c9e14;
case 0x0c0c9e16u: goto P_0c0c9e16;
case 0x0c0c9e18u: goto P_0c0c9e18;
case 0x0c0c9e1au: goto P_0c0c9e1a;
case 0x0c0c9e1cu: goto P_0c0c9e1c;
case 0x0c0c9e1eu: goto P_0c0c9e1e;
case 0x0c0c9e20u: goto P_0c0c9e20;
case 0x0c0c9e22u: goto P_0c0c9e22;
case 0x0c0c9e24u: goto P_0c0c9e24;
case 0x0c0c9e26u: goto P_0c0c9e26;
case 0x0c0c9e28u: goto P_0c0c9e28;
case 0x0c0c9e2au: goto P_0c0c9e2a;
case 0x0c0c9e2cu: goto P_0c0c9e2c;
case 0x0c0c9e2eu: goto P_0c0c9e2e;
case 0x0c0c9e30u: goto P_0c0c9e30;
case 0x0c0c9e32u: goto P_0c0c9e32;
case 0x0c0c9e34u: goto P_0c0c9e34;
case 0x0c0c9e36u: goto P_0c0c9e36;
case 0x0c0c9e38u: goto P_0c0c9e38;
case 0x0c0c9e3au: goto P_0c0c9e3a;
case 0x0c0c9e3cu: goto P_0c0c9e3c;
case 0x0c0c9e3eu: goto P_0c0c9e3e;
case 0x0c0c9e40u: goto P_0c0c9e40;
case 0x0c0c9e42u: goto P_0c0c9e42;
case 0x0c0c9e44u: goto P_0c0c9e44;
case 0x0c0c9e46u: goto P_0c0c9e46;
case 0x0c0c9e48u: goto P_0c0c9e48;
case 0x0c0c9e4au: goto P_0c0c9e4a;
case 0x0c0c9e4cu: goto P_0c0c9e4c;
case 0x0c0c9e4eu: goto P_0c0c9e4e;
case 0x0c0c9e50u: goto P_0c0c9e50;
case 0x0c0c9e52u: goto P_0c0c9e52;
case 0x0c0c9e54u: goto P_0c0c9e54;
case 0x0c0c9e56u: goto P_0c0c9e56;
case 0x0c0c9e58u: goto P_0c0c9e58;
case 0x0c0c9e5au: goto P_0c0c9e5a;
case 0x0c0c9e5cu: goto P_0c0c9e5c;
case 0x0c0c9e5eu: goto P_0c0c9e5e;
case 0x0c0c9e60u: goto P_0c0c9e60;
case 0x0c0c9e62u: goto P_0c0c9e62;
case 0x0c0c9e64u: goto P_0c0c9e64;
case 0x0c0c9e66u: goto P_0c0c9e66;
case 0x0c0c9e68u: goto P_0c0c9e68;
case 0x0c0c9e6au: goto P_0c0c9e6a;
case 0x0c0c9e6cu: goto P_0c0c9e6c;
case 0x0c0c9e6eu: goto P_0c0c9e6e;
case 0x0c0c9e80u: goto P_0c0c9e80;
case 0x0c0c9e82u: goto P_0c0c9e82;
case 0x0c0c9e84u: goto P_0c0c9e84;
case 0x0c0c9e86u: goto P_0c0c9e86;
case 0x0c0c9e88u: goto P_0c0c9e88;
case 0x0c0c9e8au: goto P_0c0c9e8a;
case 0x0c0c9e8cu: goto P_0c0c9e8c;
case 0x0c0c9e8eu: goto P_0c0c9e8e;
case 0x0c0c9e90u: goto P_0c0c9e90;
case 0x0c0c9e92u: goto P_0c0c9e92;
case 0x0c0c9e94u: goto P_0c0c9e94;
case 0x0c0c9e96u: goto P_0c0c9e96;
case 0x0c0c9e98u: goto P_0c0c9e98;
case 0x0c0c9e9au: goto P_0c0c9e9a;
case 0x0c0c9e9cu: goto P_0c0c9e9c;
case 0x0c0c9e9eu: goto P_0c0c9e9e;
case 0x0c0c9ea0u: goto P_0c0c9ea0;
case 0x0c0c9ea2u: goto P_0c0c9ea2;
case 0x0c0c9ea4u: goto P_0c0c9ea4;
case 0x0c0c9ea6u: goto P_0c0c9ea6;
case 0x0c0c9ea8u: goto P_0c0c9ea8;
case 0x0c0c9eaau: goto P_0c0c9eaa;
case 0x0c0c9eacu: goto P_0c0c9eac;
case 0x0c0c9eaeu: goto P_0c0c9eae;
case 0x0c0c9eb0u: goto P_0c0c9eb0;
case 0x0c0c9eb2u: goto P_0c0c9eb2;
case 0x0c0c9eb4u: goto P_0c0c9eb4;
case 0x0c0c9eb6u: goto P_0c0c9eb6;
case 0x0c0c9eb8u: goto P_0c0c9eb8;
case 0x0c0c9ebau: goto P_0c0c9eba;
case 0x0c0c9ebcu: goto P_0c0c9ebc;
case 0x0c0c9ebeu: goto P_0c0c9ebe;
case 0x0c0c9ec0u: goto P_0c0c9ec0;
case 0x0c0c9ec2u: goto P_0c0c9ec2;
case 0x0c0c9ec4u: goto P_0c0c9ec4;
case 0x0c0c9ec6u: goto P_0c0c9ec6;
case 0x0c0c9ec8u: goto P_0c0c9ec8;
case 0x0c0c9ecau: goto P_0c0c9eca;
case 0x0c0c9eccu: goto P_0c0c9ecc;
case 0x0c0c9eceu: goto P_0c0c9ece;
case 0x0c0c9ed0u: goto P_0c0c9ed0;
case 0x0c0c9ed2u: goto P_0c0c9ed2;
case 0x0c0c9ed4u: goto P_0c0c9ed4;
case 0x0c0c9ed6u: goto P_0c0c9ed6;
case 0x0c0c9ed8u: goto P_0c0c9ed8;
case 0x0c0c9edau: goto P_0c0c9eda;
case 0x0c0c9edcu: goto P_0c0c9edc;
case 0x0c0c9edeu: goto P_0c0c9ede;
case 0x0c0c9ee0u: goto P_0c0c9ee0;
case 0x0c0c9ee2u: goto P_0c0c9ee2;
case 0x0c0c9ee4u: goto P_0c0c9ee4;
case 0x0c0c9ee6u: goto P_0c0c9ee6;
case 0x0c0c9ee8u: goto P_0c0c9ee8;
case 0x0c0c9eeau: goto P_0c0c9eea;
case 0x0c0c9eecu: goto P_0c0c9eec;
case 0x0c0c9eeeu: goto P_0c0c9eee;
case 0x0c0c9ef0u: goto P_0c0c9ef0;
case 0x0c0c9ef2u: goto P_0c0c9ef2;
case 0x0c0c9ef4u: goto P_0c0c9ef4;
case 0x0c0c9ef6u: goto P_0c0c9ef6;
case 0x0c0c9ef8u: goto P_0c0c9ef8;
case 0x0c0c9efau: goto P_0c0c9efa;
case 0x0c0c9efcu: goto P_0c0c9efc;
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
case 0x0c0cbdd0u: goto P_0c0cbdd0;
case 0x0c0cbdd2u: goto P_0c0cbdd2;
case 0x0c0cbdd4u: goto P_0c0cbdd4;
case 0x0c0cbdd6u: goto P_0c0cbdd6;
case 0x0c0cbdd8u: goto P_0c0cbdd8;
case 0x0c0cbddau: goto P_0c0cbdda;
case 0x0c0cbddcu: goto P_0c0cbddc;
case 0x0c0cbddeu: goto P_0c0cbdde;
case 0x0c0cbde0u: goto P_0c0cbde0;
case 0x0c0cbde2u: goto P_0c0cbde2;
case 0x0c0cbde4u: goto P_0c0cbde4;
case 0x0c0cbde6u: goto P_0c0cbde6;
case 0x0c0cbde8u: goto P_0c0cbde8;
case 0x0c0cbdeau: goto P_0c0cbdea;
case 0x0c0cbdecu: goto P_0c0cbdec;
case 0x0c0cbdeeu: goto P_0c0cbdee;
case 0x0c0cbdf0u: goto P_0c0cbdf0;
case 0x0c0cbdf2u: goto P_0c0cbdf2;
case 0x0c0cbdf4u: goto P_0c0cbdf4;
case 0x0c0cbdf6u: goto P_0c0cbdf6;
case 0x0c0cbdf8u: goto P_0c0cbdf8;
case 0x0c0cbdfau: goto P_0c0cbdfa;
case 0x0c0cbdfcu: goto P_0c0cbdfc;
case 0x0c0cbdfeu: goto P_0c0cbdfe;
case 0x0c0cbe00u: goto P_0c0cbe00;
case 0x0c0cbe02u: goto P_0c0cbe02;
case 0x0c0cbe04u: goto P_0c0cbe04;
case 0x0c0cbe06u: goto P_0c0cbe06;
case 0x0c0cbe08u: goto P_0c0cbe08;
case 0x0c0cbe0au: goto P_0c0cbe0a;
case 0x0c0cbe0cu: goto P_0c0cbe0c;
case 0x0c0cbe0eu: goto P_0c0cbe0e;
case 0x0c0cbe10u: goto P_0c0cbe10;
case 0x0c0cbe12u: goto P_0c0cbe12;
case 0x0c0cbe14u: goto P_0c0cbe14;
case 0x0c0cbe16u: goto P_0c0cbe16;
case 0x0c0cbe18u: goto P_0c0cbe18;
case 0x0c0cbe1au: goto P_0c0cbe1a;
case 0x0c0cbe1cu: goto P_0c0cbe1c;
case 0x0c0cbe1eu: goto P_0c0cbe1e;
case 0x0c0cbe20u: goto P_0c0cbe20;
case 0x0c0cbe22u: goto P_0c0cbe22;
case 0x0c0cbe24u: goto P_0c0cbe24;
case 0x0c0cbe26u: goto P_0c0cbe26;
case 0x0c0cbe28u: goto P_0c0cbe28;
case 0x0c0cbe2au: goto P_0c0cbe2a;
case 0x0c0cbe2cu: goto P_0c0cbe2c;
case 0x0c0cbe2eu: goto P_0c0cbe2e;
case 0x0c0cbe30u: goto P_0c0cbe30;
case 0x0c0cbe32u: goto P_0c0cbe32;
case 0x0c0cbe34u: goto P_0c0cbe34;
case 0x0c0cbe36u: goto P_0c0cbe36;
case 0x0c0cbe38u: goto P_0c0cbe38;
case 0x0c0cbe3au: goto P_0c0cbe3a;
case 0x0c0cbe3cu: goto P_0c0cbe3c;
case 0x0c0cbe3eu: goto P_0c0cbe3e;
case 0x0c0cbe40u: goto P_0c0cbe40;
case 0x0c0cbe42u: goto P_0c0cbe42;
case 0x0c0cbe44u: goto P_0c0cbe44;
case 0x0c0cbe46u: goto P_0c0cbe46;
case 0x0c0cbe48u: goto P_0c0cbe48;
case 0x0c0cbe4au: goto P_0c0cbe4a;
case 0x0c0cbe4cu: goto P_0c0cbe4c;
case 0x0c0cbe4eu: goto P_0c0cbe4e;
case 0x0c0cbe50u: goto P_0c0cbe50;
case 0x0c0cbe52u: goto P_0c0cbe52;
case 0x0c0cbe54u: goto P_0c0cbe54;
case 0x0c0cbe56u: goto P_0c0cbe56;
case 0x0c0cbe58u: goto P_0c0cbe58;
case 0x0c0cbe5au: goto P_0c0cbe5a;
case 0x0c0cbe5cu: goto P_0c0cbe5c;
case 0x0c0cbe5eu: goto P_0c0cbe5e;
case 0x0c0cbe60u: goto P_0c0cbe60;
case 0x0c0cbe62u: goto P_0c0cbe62;
case 0x0c0cbe64u: goto P_0c0cbe64;
case 0x0c0cbe66u: goto P_0c0cbe66;
case 0x0c0cbe68u: goto P_0c0cbe68;
case 0x0c0cbe6au: goto P_0c0cbe6a;
case 0x0c0cbe6cu: goto P_0c0cbe6c;
case 0x0c0cbe6eu: goto P_0c0cbe6e;
case 0x0c0cbe70u: goto P_0c0cbe70;
case 0x0c0cbe72u: goto P_0c0cbe72;
case 0x0c0cbe74u: goto P_0c0cbe74;
case 0x0c0cbe76u: goto P_0c0cbe76;
case 0x0c0cbe78u: goto P_0c0cbe78;
case 0x0c0cbe7au: goto P_0c0cbe7a;
case 0x0c0cbe7cu: goto P_0c0cbe7c;
case 0x0c0cbe7eu: goto P_0c0cbe7e;
case 0x0c0cbe80u: goto P_0c0cbe80;
case 0x0c0cbe82u: goto P_0c0cbe82;
case 0x0c0cbe84u: goto P_0c0cbe84;
case 0x0c0cbe86u: goto P_0c0cbe86;
case 0x0c0cbe88u: goto P_0c0cbe88;
case 0x0c0cbe8au: goto P_0c0cbe8a;
case 0x0c0cbe8cu: goto P_0c0cbe8c;
case 0x0c0cbe8eu: goto P_0c0cbe8e;
case 0x0c0cbe90u: goto P_0c0cbe90;
case 0x0c0cbe92u: goto P_0c0cbe92;
case 0x0c0cbe94u: goto P_0c0cbe94;
case 0x0c0cbe96u: goto P_0c0cbe96;
case 0x0c0cbe98u: goto P_0c0cbe98;
case 0x0c0cbe9au: goto P_0c0cbe9a;
case 0x0c0cbe9cu: goto P_0c0cbe9c;
case 0x0c0cbe9eu: goto P_0c0cbe9e;
case 0x0c0cbea0u: goto P_0c0cbea0;
case 0x0c0cbea2u: goto P_0c0cbea2;
case 0x0c0cbea4u: goto P_0c0cbea4;
case 0x0c0cbea6u: goto P_0c0cbea6;
case 0x0c0cbea8u: goto P_0c0cbea8;
case 0x0c0cbeaau: goto P_0c0cbeaa;
case 0x0c0cbeacu: goto P_0c0cbeac;
case 0x0c0cbeaeu: goto P_0c0cbeae;
case 0x0c0cbeb0u: goto P_0c0cbeb0;
case 0x0c0cbeb2u: goto P_0c0cbeb2;
case 0x0c0cbeb4u: goto P_0c0cbeb4;
case 0x0c0cbeb6u: goto P_0c0cbeb6;
case 0x0c0cbeb8u: goto P_0c0cbeb8;
case 0x0c0cbebau: goto P_0c0cbeba;
case 0x0c0cbebcu: goto P_0c0cbebc;
case 0x0c0cbebeu: goto P_0c0cbebe;
case 0x0c0cbec0u: goto P_0c0cbec0;
case 0x0c0cbec2u: goto P_0c0cbec2;
case 0x0c0cbec4u: goto P_0c0cbec4;
case 0x0c0cbec6u: goto P_0c0cbec6;
case 0x0c0cbec8u: goto P_0c0cbec8;
case 0x0c0cbecau: goto P_0c0cbeca;
case 0x0c0cbeccu: goto P_0c0cbecc;
case 0x0c0cbeceu: goto P_0c0cbece;
case 0x0c0cbed0u: goto P_0c0cbed0;
case 0x0c0cbed2u: goto P_0c0cbed2;
case 0x0c0cbed4u: goto P_0c0cbed4;
case 0x0c0cbed6u: goto P_0c0cbed6;
case 0x0c0cbed8u: goto P_0c0cbed8;
case 0x0c0cbedau: goto P_0c0cbeda;
case 0x0c0cbedcu: goto P_0c0cbedc;
case 0x0c0cbedeu: goto P_0c0cbede;
case 0x0c0cbee0u: goto P_0c0cbee0;
case 0x0c0cbee2u: goto P_0c0cbee2;
case 0x0c0cbee4u: goto P_0c0cbee4;
case 0x0c0cbee6u: goto P_0c0cbee6;
case 0x0c0cbee8u: goto P_0c0cbee8;
case 0x0c0cbeeau: goto P_0c0cbeea;
case 0x0c0cbeecu: goto P_0c0cbeec;
case 0x0c0cbeeeu: goto P_0c0cbeee;
case 0x0c0cbef0u: goto P_0c0cbef0;
case 0x0c0cbef2u: goto P_0c0cbef2;
case 0x0c0cbef4u: goto P_0c0cbef4;
case 0x0c0cbef6u: goto P_0c0cbef6;
case 0x0c0cbfc8u: goto P_0c0cbfc8;
case 0x0c0cbfcau: goto P_0c0cbfca;
case 0x0c0cbfccu: goto P_0c0cbfcc;
case 0x0c0cbfceu: goto P_0c0cbfce;
case 0x0c0cbfd0u: goto P_0c0cbfd0;
case 0x0c0cbfd2u: goto P_0c0cbfd2;
case 0x0c0cbfd4u: goto P_0c0cbfd4;
case 0x0c0cbfd6u: goto P_0c0cbfd6;
case 0x0c0cbfd8u: goto P_0c0cbfd8;
case 0x0c0cbfdau: goto P_0c0cbfda;
case 0x0c0cbfdcu: goto P_0c0cbfdc;
case 0x0c0cbfdeu: goto P_0c0cbfde;
case 0x0c0cbfe0u: goto P_0c0cbfe0;
case 0x0c0cbfe2u: goto P_0c0cbfe2;
case 0x0c0cbfe4u: goto P_0c0cbfe4;
case 0x0c0cbfe6u: goto P_0c0cbfe6;
case 0x0c0cbfe8u: goto P_0c0cbfe8;
case 0x0c0cbfeau: goto P_0c0cbfea;
case 0x0c0cbfecu: goto P_0c0cbfec;
case 0x0c0cbfeeu: goto P_0c0cbfee;
case 0x0c0cbff0u: goto P_0c0cbff0;
case 0x0c0cbff2u: goto P_0c0cbff2;
case 0x0c0cbff4u: goto P_0c0cbff4;
case 0x0c0cbff6u: goto P_0c0cbff6;
case 0x0c0cbff8u: goto P_0c0cbff8;
case 0x0c0cbffau: goto P_0c0cbffa;
case 0x0c0cbffcu: goto P_0c0cbffc;
case 0x0c0cbffeu: goto P_0c0cbffe;
case 0x0c0cc000u: goto P_0c0cc000;
case 0x0c0cc002u: goto P_0c0cc002;
case 0x0c0cc004u: goto P_0c0cc004;
case 0x0c0cc006u: goto P_0c0cc006;
case 0x0c0cc008u: goto P_0c0cc008;
case 0x0c0cc00au: goto P_0c0cc00a;
case 0x0c0cc00cu: goto P_0c0cc00c;
case 0x0c0cc00eu: goto P_0c0cc00e;
case 0x0c0cc010u: goto P_0c0cc010;
case 0x0c0cc012u: goto P_0c0cc012;
case 0x0c0cc014u: goto P_0c0cc014;
case 0x0c0cc016u: goto P_0c0cc016;
case 0x0c0cc018u: goto P_0c0cc018;
case 0x0c0cc044u: goto P_0c0cc044;
case 0x0c0cc046u: goto P_0c0cc046;
case 0x0c0cc048u: goto P_0c0cc048;
case 0x0c0cc04au: goto P_0c0cc04a;
case 0x0c0cc04cu: goto P_0c0cc04c;
case 0x0c0cc04eu: goto P_0c0cc04e;
case 0x0c0cc050u: goto P_0c0cc050;
case 0x0c0cc052u: goto P_0c0cc052;
case 0x0c0cc054u: goto P_0c0cc054;
case 0x0c0cc056u: goto P_0c0cc056;
case 0x0c0cc058u: goto P_0c0cc058;
case 0x0c0cc05au: goto P_0c0cc05a;
case 0x0c0cc05cu: goto P_0c0cc05c;
case 0x0c0cc05eu: goto P_0c0cc05e;
case 0x0c0cc060u: goto P_0c0cc060;
case 0x0c0cc062u: goto P_0c0cc062;
case 0x0c0cc064u: goto P_0c0cc064;
case 0x0c0cc066u: goto P_0c0cc066;
case 0x0c0cc068u: goto P_0c0cc068;
case 0x0c0cc06au: goto P_0c0cc06a;
case 0x0c0cc06cu: goto P_0c0cc06c;
case 0x0c0cc06eu: goto P_0c0cc06e;
case 0x0c0cc070u: goto P_0c0cc070;
case 0x0c0cc072u: goto P_0c0cc072;
case 0x0c0cc074u: goto P_0c0cc074;
case 0x0c0cc076u: goto P_0c0cc076;
case 0x0c0cc078u: goto P_0c0cc078;
case 0x0c0cc07au: goto P_0c0cc07a;
case 0x0c0cc07cu: goto P_0c0cc07c;
case 0x0c0cc07eu: goto P_0c0cc07e;
case 0x0c0cc080u: goto P_0c0cc080;
case 0x0c0cc082u: goto P_0c0cc082;
case 0x0c0cc084u: goto P_0c0cc084;
case 0x0c0cc086u: goto P_0c0cc086;
case 0x0c0cc088u: goto P_0c0cc088;
case 0x0c0cc08au: goto P_0c0cc08a;
case 0x0c0cc08cu: goto P_0c0cc08c;
case 0x0c0cc08eu: goto P_0c0cc08e;
case 0x0c0cc090u: goto P_0c0cc090;
case 0x0c0cc092u: goto P_0c0cc092;
case 0x0c0cc094u: goto P_0c0cc094;
case 0x0c0cc096u: goto P_0c0cc096;
case 0x0c0cc098u: goto P_0c0cc098;
case 0x0c0cc09au: goto P_0c0cc09a;
case 0x0c0cc09cu: goto P_0c0cc09c;
case 0x0c0cc09eu: goto P_0c0cc09e;
case 0x0c0cc0a0u: goto P_0c0cc0a0;
case 0x0c0cc0a2u: goto P_0c0cc0a2;
case 0x0c0cc0a4u: goto P_0c0cc0a4;
case 0x0c0cc0a6u: goto P_0c0cc0a6;
case 0x0c0cc0a8u: goto P_0c0cc0a8;
case 0x0c0cc0aau: goto P_0c0cc0aa;
case 0x0c0cc0acu: goto P_0c0cc0ac;
case 0x0c0cc0aeu: goto P_0c0cc0ae;
case 0x0c0cc0b0u: goto P_0c0cc0b0;
case 0x0c0cc0b2u: goto P_0c0cc0b2;
case 0x0c0cc0b4u: goto P_0c0cc0b4;
case 0x0c0cc0b6u: goto P_0c0cc0b6;
case 0x0c0cc0b8u: goto P_0c0cc0b8;
case 0x0c0cc0bau: goto P_0c0cc0ba;
case 0x0c0cc0bcu: goto P_0c0cc0bc;
case 0x0c0cc0beu: goto P_0c0cc0be;
case 0x0c0cc0c0u: goto P_0c0cc0c0;
case 0x0c0cc0c2u: goto P_0c0cc0c2;
case 0x0c0cc0c4u: goto P_0c0cc0c4;
case 0x0c0cc0c6u: goto P_0c0cc0c6;
case 0x0c0cc0c8u: goto P_0c0cc0c8;
case 0x0c0cc0cau: goto P_0c0cc0ca;
case 0x0c0cc0ccu: goto P_0c0cc0cc;
case 0x0c0cc0ceu: goto P_0c0cc0ce;
case 0x0c0cc0d0u: goto P_0c0cc0d0;
case 0x0c0cc0d2u: goto P_0c0cc0d2;
case 0x0c0cc0d4u: goto P_0c0cc0d4;
default: return vf3_matrix_family(target,s,ram);
}
P_0c0abeb8: /* original 4f22, guest PC 0x0c0abeb8 */
if(!s->budget--) { s->failed_pc=0x0c0abeb8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abeba;
P_0c0abeba: /* original 223b, guest PC 0x0c0abeba */
if(!s->budget--) { s->failed_pc=0x0c0abebau; return 0; }
r[2]|=r[3];
goto P_0c0abebc;
P_0c0abebc: /* original 2e22, guest PC 0x0c0abebc */
if(!s->budget--) { s->failed_pc=0x0c0abebcu; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0abebe;
P_0c0abebe: /* original f38d, guest PC 0x0c0abebe */
if(!s->budget--) { s->failed_pc=0x0c0abebeu; return 0; }
fr[3]=0;
goto P_0c0abec0;
P_0c0abec0: /* original 7ffc, guest PC 0x0c0abec0 */
if(!s->budget--) { s->failed_pc=0x0c0abec0u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0abec2;
P_0c0abec2: /* original fe37, guest PC 0x0c0abec2 */
if(!s->budget--) { s->failed_pc=0x0c0abec2u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abec4;
P_0c0abec4: /* original 64d2, guest PC 0x0c0abec4 */
if(!s->budget--) { s->failed_pc=0x0c0abec4u; return 0; }
tmp=read(ram,r[13],4);
r[4]=tmp;
goto P_0c0abec6;
P_0c0abec6: /* original 624d, guest PC 0x0c0abec6 */
if(!s->budget--) { s->failed_pc=0x0c0abec6u; return 0; }
r[2]=r[4]&65535u;
goto P_0c0abec8;
P_0c0abec8: /* original 4429, guest PC 0x0c0abec8 */
if(!s->budget--) { s->failed_pc=0x0c0abec8u; return 0; }
r[4]>>=16;
goto P_0c0abeca;
P_0c0abeca: /* original 2f22, guest PC 0x0c0abeca */
if(!s->budget--) { s->failed_pc=0x0c0abecau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0abecc;
P_0c0abecc: /* original 6c4c, guest PC 0x0c0abecc */
if(!s->budget--) { s->failed_pc=0x0c0abeccu; return 0; }
r[12]=r[4]&255u;
goto P_0c0abece;
P_0c0abece: /* original 60c3, guest PC 0x0c0abece */
if(!s->budget--) { s->failed_pc=0x0c0abeceu; return 0; }
r[0]=r[12];
goto P_0c0abed0;
P_0c0abed0: /* original 8801, guest PC 0x0c0abed0 */
if(!s->budget--) { s->failed_pc=0x0c0abed0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0abed2;
P_0c0abed2: /* original 8b07, guest PC 0x0c0abed2 */
if(!s->budget--) { s->failed_pc=0x0c0abed2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abee4; }
goto P_0c0abed4;
P_0c0abed4: /* original 7f04, guest PC 0x0c0abed4 */
if(!s->budget--) { s->failed_pc=0x0c0abed4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abed6;
P_0c0abed6: /* original 65d3, guest PC 0x0c0abed6 */
if(!s->budget--) { s->failed_pc=0x0c0abed6u; return 0; }
r[5]=r[13];
goto P_0c0abed8;
P_0c0abed8: /* original 4f26, guest PC 0x0c0abed8 */
if(!s->budget--) { s->failed_pc=0x0c0abed8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abeda;
P_0c0abeda: /* original 64e3, guest PC 0x0c0abeda */
if(!s->budget--) { s->failed_pc=0x0c0abedau; return 0; }
r[4]=r[14];
goto P_0c0abedc;
P_0c0abedc: /* original 6cf6, guest PC 0x0c0abedc */
if(!s->budget--) { s->failed_pc=0x0c0abedcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abede;
P_0c0abede: /* original 6df6, guest PC 0x0c0abede */
if(!s->budget--) { s->failed_pc=0x0c0abedeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abee0;
P_0c0abee0: /* original a154, guest PC 0x0c0abee0 */
if(!s->budget--) { s->failed_pc=0x0c0abee0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac18c;
P_0c0abee2: /* original 6ef6, guest PC 0x0c0abee2 */
if(!s->budget--) { s->failed_pc=0x0c0abee2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abee4;
P_0c0abee4: /* original d317, guest PC 0x0c0abee4 */
if(!s->budget--) { s->failed_pc=0x0c0abee4u; return 0; }
r[3]=read(ram,0x0c0abf44u,4);
goto P_0c0abee6;
P_0c0abee6: /* original 65f2, guest PC 0x0c0abee6 */
if(!s->budget--) { s->failed_pc=0x0c0abee6u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0abee8;
P_0c0abee8: /* original 430b, guest PC 0x0c0abee8 */
if(!s->budget--) { s->failed_pc=0x0c0abee8u; return 0; }
target=r[3];
r[16]=0x0c0abeecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abeecu) { target=s->pc; goto dispatch; }
goto P_0c0abeec;
P_0c0abeea: /* original 64e3, guest PC 0x0c0abeea */
if(!s->budget--) { s->failed_pc=0x0c0abeeau; return 0; }
r[4]=r[14];
goto P_0c0abeec;
P_0c0abeec: /* original 60c3, guest PC 0x0c0abeec */
if(!s->budget--) { s->failed_pc=0x0c0abeecu; return 0; }
r[0]=r[12];
goto P_0c0abeee;
P_0c0abeee: /* original 8802, guest PC 0x0c0abeee */
if(!s->budget--) { s->failed_pc=0x0c0abeeeu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0abef0;
P_0c0abef0: /* original 8b07, guest PC 0x0c0abef0 */
if(!s->budget--) { s->failed_pc=0x0c0abef0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0abf02; }
goto P_0c0abef2;
P_0c0abef2: /* original 7f04, guest PC 0x0c0abef2 */
if(!s->budget--) { s->failed_pc=0x0c0abef2u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abef4;
P_0c0abef4: /* original 65d3, guest PC 0x0c0abef4 */
if(!s->budget--) { s->failed_pc=0x0c0abef4u; return 0; }
r[5]=r[13];
goto P_0c0abef6;
P_0c0abef6: /* original 4f26, guest PC 0x0c0abef6 */
if(!s->budget--) { s->failed_pc=0x0c0abef6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abef8;
P_0c0abef8: /* original 64e3, guest PC 0x0c0abef8 */
if(!s->budget--) { s->failed_pc=0x0c0abef8u; return 0; }
r[4]=r[14];
goto P_0c0abefa;
P_0c0abefa: /* original 6cf6, guest PC 0x0c0abefa */
if(!s->budget--) { s->failed_pc=0x0c0abefau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abefc;
P_0c0abefc: /* original 6df6, guest PC 0x0c0abefc */
if(!s->budget--) { s->failed_pc=0x0c0abefcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abefe;
P_0c0abefe: /* original a101, guest PC 0x0c0abefe */
if(!s->budget--) { s->failed_pc=0x0c0abefeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac104;
P_0c0abf00: /* original 6ef6, guest PC 0x0c0abf00 */
if(!s->budget--) { s->failed_pc=0x0c0abf00u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf02;
P_0c0abf02: /* original 7f04, guest PC 0x0c0abf02 */
if(!s->budget--) { s->failed_pc=0x0c0abf02u; return 0; }
r[15]+=0x00000004u;
goto P_0c0abf04;
P_0c0abf04: /* original 52d1, guest PC 0x0c0abf04 */
if(!s->budget--) { s->failed_pc=0x0c0abf04u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0abf06;
P_0c0abf06: /* original 4f26, guest PC 0x0c0abf06 */
if(!s->budget--) { s->failed_pc=0x0c0abf06u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf08;
P_0c0abf08: /* original 7201, guest PC 0x0c0abf08 */
if(!s->budget--) { s->failed_pc=0x0c0abf08u; return 0; }
r[2]+=0x00000001u;
goto P_0c0abf0a;
P_0c0abf0a: /* original 65d3, guest PC 0x0c0abf0a */
if(!s->budget--) { s->failed_pc=0x0c0abf0au; return 0; }
r[5]=r[13];
goto P_0c0abf0c;
P_0c0abf0c: /* original 1d21, guest PC 0x0c0abf0c */
if(!s->budget--) { s->failed_pc=0x0c0abf0cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0abf0e;
P_0c0abf0e: /* original 6323, guest PC 0x0c0abf0e */
if(!s->budget--) { s->failed_pc=0x0c0abf0eu; return 0; }
r[3]=r[2];
goto P_0c0abf10;
P_0c0abf10: /* original e062, guest PC 0x0c0abf10 */
if(!s->budget--) { s->failed_pc=0x0c0abf10u; return 0; }
r[0]=0x00000062u;
goto P_0c0abf12;
P_0c0abf12: /* original 64e3, guest PC 0x0c0abf12 */
if(!s->budget--) { s->failed_pc=0x0c0abf12u; return 0; }
r[4]=r[14];
goto P_0c0abf14;
P_0c0abf14: /* original 0e34, guest PC 0x0c0abf14 */
if(!s->budget--) { s->failed_pc=0x0c0abf14u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abf16;
P_0c0abf16: /* original 6cf6, guest PC 0x0c0abf16 */
if(!s->budget--) { s->failed_pc=0x0c0abf16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0abf18;
P_0c0abf18: /* original 6df6, guest PC 0x0c0abf18 */
if(!s->budget--) { s->failed_pc=0x0c0abf18u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf1a;
P_0c0abf1a: /* original a015, guest PC 0x0c0abf1a */
if(!s->budget--) { s->failed_pc=0x0c0abf1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf48;
P_0c0abf1c: /* original 6ef6, guest PC 0x0c0abf1c */
if(!s->budget--) { s->failed_pc=0x0c0abf1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abf1eu,s,ram);
P_0c0abf48: /* original 2fe6, guest PC 0x0c0abf48 */
if(!s->budget--) { s->failed_pc=0x0c0abf48u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0abf4a;
P_0c0abf4a: /* original 6e43, guest PC 0x0c0abf4a */
if(!s->budget--) { s->failed_pc=0x0c0abf4au; return 0; }
r[14]=r[4];
goto P_0c0abf4c;
P_0c0abf4c: /* original e03e, guest PC 0x0c0abf4c */
if(!s->budget--) { s->failed_pc=0x0c0abf4cu; return 0; }
r[0]=0x0000003eu;
goto P_0c0abf4e;
P_0c0abf4e: /* original 2fd6, guest PC 0x0c0abf4e */
if(!s->budget--) { s->failed_pc=0x0c0abf4eu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0abf50;
P_0c0abf50: /* original 03ed, guest PC 0x0c0abf50 */
if(!s->budget--) { s->failed_pc=0x0c0abf50u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abf52;
P_0c0abf52: /* original 9080, guest PC 0x0c0abf52 */
if(!s->budget--) { s->failed_pc=0x0c0abf52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac056u,2);
goto P_0c0abf54;
P_0c0abf54: /* original 4f22, guest PC 0x0c0abf54 */
if(!s->budget--) { s->failed_pc=0x0c0abf54u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0abf56;
P_0c0abf56: /* original 02ed, guest PC 0x0c0abf56 */
if(!s->budget--) { s->failed_pc=0x0c0abf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0abf58;
P_0c0abf58: /* original 3322, guest PC 0x0c0abf58 */
if(!s->budget--) { s->failed_pc=0x0c0abf58u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0abf5a;
P_0c0abf5a: /* original 8f1e, guest PC 0x0c0abf5a */
if(!s->budget--) { s->failed_pc=0x0c0abf5au; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0abf9a; }
goto P_0c0abf5e;
P_0c0abf5c: /* original 6d53, guest PC 0x0c0abf5c */
if(!s->budget--) { s->failed_pc=0x0c0abf5cu; return 0; }
r[13]=r[5];
goto P_0c0abf5e;
P_0c0abf5e: /* original 907b, guest PC 0x0c0abf5e */
if(!s->budget--) { s->failed_pc=0x0c0abf5eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac058u,2);
goto P_0c0abf60;
P_0c0abf60: /* original 66e3, guest PC 0x0c0abf60 */
if(!s->budget--) { s->failed_pc=0x0c0abf60u; return 0; }
r[6]=r[14];
goto P_0c0abf62;
P_0c0abf62: /* original 65e3, guest PC 0x0c0abf62 */
if(!s->budget--) { s->failed_pc=0x0c0abf62u; return 0; }
r[5]=r[14];
goto P_0c0abf64;
P_0c0abf64: /* original 7648, guest PC 0x0c0abf64 */
if(!s->budget--) { s->failed_pc=0x0c0abf64u; return 0; }
r[6]+=0x00000048u;
goto P_0c0abf66;
P_0c0abf66: /* original f3e6, guest PC 0x0c0abf66 */
if(!s->budget--) { s->failed_pc=0x0c0abf66u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf68;
P_0c0abf68: /* original e024, guest PC 0x0c0abf68 */
if(!s->budget--) { s->failed_pc=0x0c0abf68u; return 0; }
r[0]=0x00000024u;
goto P_0c0abf6a;
P_0c0abf6a: /* original fe37, guest PC 0x0c0abf6a */
if(!s->budget--) { s->failed_pc=0x0c0abf6au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf6c;
P_0c0abf6c: /* original 9075, guest PC 0x0c0abf6c */
if(!s->budget--) { s->failed_pc=0x0c0abf6cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05au,2);
goto P_0c0abf6e;
P_0c0abf6e: /* original f3e6, guest PC 0x0c0abf6e */
if(!s->budget--) { s->failed_pc=0x0c0abf6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf70;
P_0c0abf70: /* original e028, guest PC 0x0c0abf70 */
if(!s->budget--) { s->failed_pc=0x0c0abf70u; return 0; }
r[0]=0x00000028u;
goto P_0c0abf72;
P_0c0abf72: /* original fe37, guest PC 0x0c0abf72 */
if(!s->budget--) { s->failed_pc=0x0c0abf72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf74;
P_0c0abf74: /* original 9072, guest PC 0x0c0abf74 */
if(!s->budget--) { s->failed_pc=0x0c0abf74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac05cu,2);
goto P_0c0abf76;
P_0c0abf76: /* original f3e6, guest PC 0x0c0abf76 */
if(!s->budget--) { s->failed_pc=0x0c0abf76u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0abf78;
P_0c0abf78: /* original e02c, guest PC 0x0c0abf78 */
if(!s->budget--) { s->failed_pc=0x0c0abf78u; return 0; }
r[0]=0x0000002cu;
goto P_0c0abf7a;
P_0c0abf7a: /* original fe37, guest PC 0x0c0abf7a */
if(!s->budget--) { s->failed_pc=0x0c0abf7au; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0abf7c;
P_0c0abf7c: /* original d339, guest PC 0x0c0abf7c */
if(!s->budget--) { s->failed_pc=0x0c0abf7cu; return 0; }
r[3]=read(ram,0x0c0ac064u,4);
goto P_0c0abf7e;
P_0c0abf7e: /* original 430b, guest PC 0x0c0abf7e */
if(!s->budget--) { s->failed_pc=0x0c0abf7eu; return 0; }
target=r[3];
r[16]=0x0c0abf82u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0abf82u) { target=s->pc; goto dispatch; }
goto P_0c0abf82;
P_0c0abf80: /* original 64e3, guest PC 0x0c0abf80 */
if(!s->budget--) { s->failed_pc=0x0c0abf80u; return 0; }
r[4]=r[14];
goto P_0c0abf82;
P_0c0abf82: /* original 52d1, guest PC 0x0c0abf82 */
if(!s->budget--) { s->failed_pc=0x0c0abf82u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0abf84;
P_0c0abf84: /* original 65d3, guest PC 0x0c0abf84 */
if(!s->budget--) { s->failed_pc=0x0c0abf84u; return 0; }
r[5]=r[13];
goto P_0c0abf86;
P_0c0abf86: /* original 4f26, guest PC 0x0c0abf86 */
if(!s->budget--) { s->failed_pc=0x0c0abf86u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf88;
P_0c0abf88: /* original 7201, guest PC 0x0c0abf88 */
if(!s->budget--) { s->failed_pc=0x0c0abf88u; return 0; }
r[2]+=0x00000001u;
goto P_0c0abf8a;
P_0c0abf8a: /* original 64e3, guest PC 0x0c0abf8a */
if(!s->budget--) { s->failed_pc=0x0c0abf8au; return 0; }
r[4]=r[14];
goto P_0c0abf8c;
P_0c0abf8c: /* original 1d21, guest PC 0x0c0abf8c */
if(!s->budget--) { s->failed_pc=0x0c0abf8cu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0abf8e;
P_0c0abf8e: /* original e062, guest PC 0x0c0abf8e */
if(!s->budget--) { s->failed_pc=0x0c0abf8eu; return 0; }
r[0]=0x00000062u;
goto P_0c0abf90;
P_0c0abf90: /* original 6323, guest PC 0x0c0abf90 */
if(!s->budget--) { s->failed_pc=0x0c0abf90u; return 0; }
r[3]=r[2];
goto P_0c0abf92;
P_0c0abf92: /* original 0e34, guest PC 0x0c0abf92 */
if(!s->budget--) { s->failed_pc=0x0c0abf92u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0abf94;
P_0c0abf94: /* original 6df6, guest PC 0x0c0abf94 */
if(!s->budget--) { s->failed_pc=0x0c0abf94u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf96;
P_0c0abf96: /* original a06f, guest PC 0x0c0abf96 */
if(!s->budget--) { s->failed_pc=0x0c0abf96u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac078;
P_0c0abf98: /* original 6ef6, guest PC 0x0c0abf98 */
if(!s->budget--) { s->failed_pc=0x0c0abf98u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0abf9a;
P_0c0abf9a: /* original 4f26, guest PC 0x0c0abf9a */
if(!s->budget--) { s->failed_pc=0x0c0abf9au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0abf9c;
P_0c0abf9c: /* original 6df6, guest PC 0x0c0abf9c */
if(!s->budget--) { s->failed_pc=0x0c0abf9cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0abf9e;
P_0c0abf9e: /* original 000b, guest PC 0x0c0abf9e */
if(!s->budget--) { s->failed_pc=0x0c0abf9eu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0abfa0: /* original 6ef6, guest PC 0x0c0abfa0 */
if(!s->budget--) { s->failed_pc=0x0c0abfa0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0abfa2u,s,ram);
P_0c0ac078: /* original 2fe6, guest PC 0x0c0ac078 */
if(!s->budget--) { s->failed_pc=0x0c0ac078u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ac07a;
P_0c0ac07a: /* original 6e43, guest PC 0x0c0ac07a */
if(!s->budget--) { s->failed_pc=0x0c0ac07au; return 0; }
r[14]=r[4];
goto P_0c0ac07c;
P_0c0ac07c: /* original 2fd6, guest PC 0x0c0ac07c */
if(!s->budget--) { s->failed_pc=0x0c0ac07cu; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0ac07e;
P_0c0ac07e: /* original 9071, guest PC 0x0c0ac07e */
if(!s->budget--) { s->failed_pc=0x0c0ac07eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac164u,2);
goto P_0c0ac080;
P_0c0ac080: /* original 4f22, guest PC 0x0c0ac080 */
if(!s->budget--) { s->failed_pc=0x0c0ac080u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac082;
P_0c0ac082: /* original 00ec, guest PC 0x0c0ac082 */
if(!s->budget--) { s->failed_pc=0x0c0ac082u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ac084;
P_0c0ac084: /* original 600c, guest PC 0x0c0ac084 */
if(!s->budget--) { s->failed_pc=0x0c0ac084u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ac086;
P_0c0ac086: /* original c840, guest PC 0x0c0ac086 */
if(!s->budget--) { s->failed_pc=0x0c0ac086u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&64u)==0)!=0);
goto P_0c0ac088;
P_0c0ac088: /* original 8d16, guest PC 0x0c0ac088 */
if(!s->budget--) { s->failed_pc=0x0c0ac088u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(cond) { goto P_0c0ac0b8; }
goto P_0c0ac08c;
P_0c0ac08a: /* original 6d53, guest PC 0x0c0ac08a */
if(!s->budget--) { s->failed_pc=0x0c0ac08au; return 0; }
r[13]=r[5];
goto P_0c0ac08c;
P_0c0ac08c: /* original 906c, guest PC 0x0c0ac08c */
if(!s->budget--) { s->failed_pc=0x0c0ac08cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac08e;
P_0c0ac08e: /* original 936a, guest PC 0x0c0ac08e */
if(!s->budget--) { s->failed_pc=0x0c0ac08eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac166u,2);
goto P_0c0ac090;
P_0c0ac090: /* original 02ee, guest PC 0x0c0ac090 */
if(!s->budget--) { s->failed_pc=0x0c0ac090u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac092;
P_0c0ac092: /* original 2238, guest PC 0x0c0ac092 */
if(!s->budget--) { s->failed_pc=0x0c0ac092u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac094;
P_0c0ac094: /* original 8910, guest PC 0x0c0ac094 */
if(!s->budget--) { s->failed_pc=0x0c0ac094u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0b8; }
goto P_0c0ac096;
P_0c0ac096: /* original c737, guest PC 0x0c0ac096 */
if(!s->budget--) { s->failed_pc=0x0c0ac096u; return 0; }
r[0]=0x0c0ac174u;
goto P_0c0ac098;
P_0c0ac098: /* original f408, guest PC 0x0c0ac098 */
if(!s->budget--) { s->failed_pc=0x0c0ac098u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0ac09a;
P_0c0ac09a: /* original e024, guest PC 0x0c0ac09a */
if(!s->budget--) { s->failed_pc=0x0c0ac09au; return 0; }
r[0]=0x00000024u;
goto P_0c0ac09c;
P_0c0ac09c: /* original f3e6, guest PC 0x0c0ac09c */
if(!s->budget--) { s->failed_pc=0x0c0ac09cu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac09e;
P_0c0ac09e: /* original 9064, guest PC 0x0c0ac09e */
if(!s->budget--) { s->failed_pc=0x0c0ac09eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16au,2);
goto P_0c0ac0a0;
P_0c0ac0a0: /* original f04c, guest PC 0x0c0ac0a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a0u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0ac0a2;
P_0c0ac0a2: /* original f2e6, guest PC 0x0c0ac0a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a2u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac0a4;
P_0c0ac0a4: /* original e024, guest PC 0x0c0ac0a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a4u; return 0; }
r[0]=0x00000024u;
goto P_0c0ac0a6;
P_0c0ac0a6: /* original f32e, guest PC 0x0c0ac0a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a6u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ac0a8;
P_0c0ac0a8: /* original fe37, guest PC 0x0c0ac0a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0a8u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac0aa;
P_0c0ac0aa: /* original e02c, guest PC 0x0c0ac0aa */
if(!s->budget--) { s->failed_pc=0x0c0ac0aau; return 0; }
r[0]=0x0000002cu;
goto P_0c0ac0ac;
P_0c0ac0ac: /* original f3e6, guest PC 0x0c0ac0ac */
if(!s->budget--) { s->failed_pc=0x0c0ac0acu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0ac0ae;
P_0c0ac0ae: /* original 905d, guest PC 0x0c0ac0ae */
if(!s->budget--) { s->failed_pc=0x0c0ac0aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16cu,2);
goto P_0c0ac0b0;
P_0c0ac0b0: /* original f2e6, guest PC 0x0c0ac0b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b0u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0ac0b2;
P_0c0ac0b2: /* original e02c, guest PC 0x0c0ac0b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b2u; return 0; }
r[0]=0x0000002cu;
goto P_0c0ac0b4;
P_0c0ac0b4: /* original f32e, guest PC 0x0c0ac0b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[2],fr[3],r[18]);
goto P_0c0ac0b6;
P_0c0ac0b6: /* original fe37, guest PC 0x0c0ac0b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac0b8;
P_0c0ac0b8: /* original d32f, guest PC 0x0c0ac0b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0b8u; return 0; }
r[3]=read(ram,0x0c0ac178u,4);
goto P_0c0ac0ba;
P_0c0ac0ba: /* original 430b, guest PC 0x0c0ac0ba */
if(!s->budget--) { s->failed_pc=0x0c0ac0bau; return 0; }
target=r[3];
r[16]=0x0c0ac0beu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac0beu) { target=s->pc; goto dispatch; }
goto P_0c0ac0be;
P_0c0ac0bc: /* original 64e3, guest PC 0x0c0ac0bc */
if(!s->budget--) { s->failed_pc=0x0c0ac0bcu; return 0; }
r[4]=r[14];
goto P_0c0ac0be;
P_0c0ac0be: /* original 6403, guest PC 0x0c0ac0be */
if(!s->budget--) { s->failed_pc=0x0c0ac0beu; return 0; }
r[4]=r[0];
goto P_0c0ac0c0;
P_0c0ac0c0: /* original 2448, guest PC 0x0c0ac0c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c0u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ac0c2;
P_0c0ac0c2: /* original 8d05, guest PC 0x0c0ac0c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c2u; return 0; }
cond=r[17]&1u;
r[5]=r[13];
if(cond) { goto P_0c0ac0d0; }
goto P_0c0ac0c6;
P_0c0ac0c4: /* original 65d3, guest PC 0x0c0ac0c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c4u; return 0; }
r[5]=r[13];
goto P_0c0ac0c6;
P_0c0ac0c6: /* original e205, guest PC 0x0c0ac0c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c6u; return 0; }
r[2]=0x00000005u;
goto P_0c0ac0c8;
P_0c0ac0c8: /* original e062, guest PC 0x0c0ac0c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0c8u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac0ca;
P_0c0ac0ca: /* original 6323, guest PC 0x0c0ac0ca */
if(!s->budget--) { s->failed_pc=0x0c0ac0cau; return 0; }
r[3]=r[2];
goto P_0c0ac0cc;
P_0c0ac0cc: /* original 1d21, guest PC 0x0c0ac0cc */
if(!s->budget--) { s->failed_pc=0x0c0ac0ccu; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0ac0ce;
P_0c0ac0ce: /* original 0e34, guest PC 0x0c0ac0ce */
if(!s->budget--) { s->failed_pc=0x0c0ac0ceu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ac0d0;
P_0c0ac0d0: /* original 4f26, guest PC 0x0c0ac0d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d0u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac0d2;
P_0c0ac0d2: /* original 64e3, guest PC 0x0c0ac0d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d2u; return 0; }
r[4]=r[14];
goto P_0c0ac0d4;
P_0c0ac0d4: /* original 6df6, guest PC 0x0c0ac0d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ac0d6;
P_0c0ac0d6: /* original a000, guest PC 0x0c0ac0d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac0da;
P_0c0ac0d8: /* original 6ef6, guest PC 0x0c0ac0d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0d8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac0da;
P_0c0ac0da: /* original 6242, guest PC 0x0c0ac0da */
if(!s->budget--) { s->failed_pc=0x0c0ac0dau; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0ac0dc;
P_0c0ac0dc: /* original d327, guest PC 0x0c0ac0dc */
if(!s->budget--) { s->failed_pc=0x0c0ac0dcu; return 0; }
r[3]=read(ram,0x0c0ac17cu,4);
goto P_0c0ac0de;
P_0c0ac0de: /* original 2238, guest PC 0x0c0ac0de */
if(!s->budget--) { s->failed_pc=0x0c0ac0deu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac0e0;
P_0c0ac0e0: /* original 8b0e, guest PC 0x0c0ac0e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac100; }
goto P_0c0ac0e2;
P_0c0ac0e2: /* original 9044, guest PC 0x0c0ac0e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16eu,2);
goto P_0c0ac0e4;
P_0c0ac0e4: /* original e13e, guest PC 0x0c0ac0e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e4u; return 0; }
r[1]=0x0000003eu;
goto P_0c0ac0e6;
P_0c0ac0e6: /* original 314c, guest PC 0x0c0ac0e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e6u; return 0; }
r[1]+=r[4];
goto P_0c0ac0e8;
P_0c0ac0e8: /* original 004d, guest PC 0x0c0ac0e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0e8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[4]+r[0],2);
goto P_0c0ac0ea;
P_0c0ac0ea: /* original 2101, guest PC 0x0c0ac0ea */
if(!s->budget--) { s->failed_pc=0x0c0ac0eau; return 0; }
write(ram,r[1],r[0],2);
goto P_0c0ac0ec;
P_0c0ac0ec: /* original 903c, guest PC 0x0c0ac0ec */
if(!s->budget--) { s->failed_pc=0x0c0ac0ecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac168u,2);
goto P_0c0ac0ee;
P_0c0ac0ee: /* original d624, guest PC 0x0c0ac0ee */
if(!s->budget--) { s->failed_pc=0x0c0ac0eeu; return 0; }
r[6]=read(ram,0x0c0ac180u,4);
goto P_0c0ac0f0;
P_0c0ac0f0: /* original 034e, guest PC 0x0c0ac0f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f0u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0ac0f2;
P_0c0ac0f2: /* original 2638, guest PC 0x0c0ac0f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0ac0f4;
P_0c0ac0f4: /* original 8902, guest PC 0x0c0ac0f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac0fc; }
goto P_0c0ac0f6;
P_0c0ac0f6: /* original 903b, guest PC 0x0c0ac0f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac170u,2);
goto P_0c0ac0f8;
P_0c0ac0f8: /* original e101, guest PC 0x0c0ac0f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac0f8u; return 0; }
r[1]=0x00000001u;
goto P_0c0ac0fa;
P_0c0ac0fa: /* original 0414, guest PC 0x0c0ac0fa */
if(!s->budget--) { s->failed_pc=0x0c0ac0fau; return 0; }
write(ram,r[4]+r[0],r[1],1);
goto P_0c0ac0fc;
P_0c0ac0fc: /* original a020, guest PC 0x0c0ac0fc */
if(!s->budget--) { s->failed_pc=0x0c0ac0fcu; return 0; }
goto P_0c0ac140;
P_0c0ac0fe: /* original 0009, guest PC 0x0c0ac0fe */
if(!s->budget--) { s->failed_pc=0x0c0ac0feu; return 0; }
goto P_0c0ac100;
P_0c0ac100: /* original 000b, guest PC 0x0c0ac100 */
if(!s->budget--) { s->failed_pc=0x0c0ac100u; return 0; }
target=r[16];
s->pc=target; return ram->oob==0;
P_0c0ac102: /* original 0009, guest PC 0x0c0ac102 */
if(!s->budget--) { s->failed_pc=0x0c0ac102u; return 0; }
goto P_0c0ac104;
P_0c0ac104: /* original e303, guest PC 0x0c0ac104 */
if(!s->budget--) { s->failed_pc=0x0c0ac104u; return 0; }
r[3]=0x00000003u;
goto P_0c0ac106;
P_0c0ac106: /* original e062, guest PC 0x0c0ac106 */
if(!s->budget--) { s->failed_pc=0x0c0ac106u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac108;
P_0c0ac108: /* original 6233, guest PC 0x0c0ac108 */
if(!s->budget--) { s->failed_pc=0x0c0ac108u; return 0; }
r[2]=r[3];
goto P_0c0ac10a;
P_0c0ac10a: /* original 1531, guest PC 0x0c0ac10a */
if(!s->budget--) { s->failed_pc=0x0c0ac10au; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c0ac10c;
P_0c0ac10c: /* original a000, guest PC 0x0c0ac10c */
if(!s->budget--) { s->failed_pc=0x0c0ac10cu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac110;
P_0c0ac10e: /* original 0424, guest PC 0x0c0ac10e */
if(!s->budget--) { s->failed_pc=0x0c0ac10eu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac110;
P_0c0ac110: /* original 2fe6, guest PC 0x0c0ac110 */
if(!s->budget--) { s->failed_pc=0x0c0ac110u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ac112;
P_0c0ac112: /* original 6e43, guest PC 0x0c0ac112 */
if(!s->budget--) { s->failed_pc=0x0c0ac112u; return 0; }
r[14]=r[4];
goto P_0c0ac114;
P_0c0ac114: /* original 4f22, guest PC 0x0c0ac114 */
if(!s->budget--) { s->failed_pc=0x0c0ac114u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac116;
P_0c0ac116: /* original 7ffc, guest PC 0x0c0ac116 */
if(!s->budget--) { s->failed_pc=0x0c0ac116u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac118;
P_0c0ac118: /* original 2f52, guest PC 0x0c0ac118 */
if(!s->budget--) { s->failed_pc=0x0c0ac118u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ac11a;
P_0c0ac11a: /* original d317, guest PC 0x0c0ac11a */
if(!s->budget--) { s->failed_pc=0x0c0ac11au; return 0; }
r[3]=read(ram,0x0c0ac178u,4);
goto P_0c0ac11c;
P_0c0ac11c: /* original 430b, guest PC 0x0c0ac11c */
if(!s->budget--) { s->failed_pc=0x0c0ac11cu; return 0; }
target=r[3];
r[16]=0x0c0ac120u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac120u) { target=s->pc; goto dispatch; }
goto P_0c0ac120;
P_0c0ac11e: /* original 64e3, guest PC 0x0c0ac11e */
if(!s->budget--) { s->failed_pc=0x0c0ac11eu; return 0; }
r[4]=r[14];
goto P_0c0ac120;
P_0c0ac120: /* original e03e, guest PC 0x0c0ac120 */
if(!s->budget--) { s->failed_pc=0x0c0ac120u; return 0; }
r[0]=0x0000003eu;
goto P_0c0ac122;
P_0c0ac122: /* original 02ed, guest PC 0x0c0ac122 */
if(!s->budget--) { s->failed_pc=0x0c0ac122u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac124;
P_0c0ac124: /* original 9023, guest PC 0x0c0ac124 */
if(!s->budget--) { s->failed_pc=0x0c0ac124u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac16eu,2);
goto P_0c0ac126;
P_0c0ac126: /* original 03ed, guest PC 0x0c0ac126 */
if(!s->budget--) { s->failed_pc=0x0c0ac126u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac128;
P_0c0ac128: /* original 3232, guest PC 0x0c0ac128 */
if(!s->budget--) { s->failed_pc=0x0c0ac128u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0ac12a;
P_0c0ac12a: /* original 8b05, guest PC 0x0c0ac12a */
if(!s->budget--) { s->failed_pc=0x0c0ac12au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac138; }
goto P_0c0ac12c;
P_0c0ac12c: /* original 65f2, guest PC 0x0c0ac12c */
if(!s->budget--) { s->failed_pc=0x0c0ac12cu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac12e;
P_0c0ac12e: /* original 7f04, guest PC 0x0c0ac12e */
if(!s->budget--) { s->failed_pc=0x0c0ac12eu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac130;
P_0c0ac130: /* original 4f26, guest PC 0x0c0ac130 */
if(!s->budget--) { s->failed_pc=0x0c0ac130u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac132;
P_0c0ac132: /* original 64e3, guest PC 0x0c0ac132 */
if(!s->budget--) { s->failed_pc=0x0c0ac132u; return 0; }
r[4]=r[14];
goto P_0c0ac134;
P_0c0ac134: /* original a004, guest PC 0x0c0ac134 */
if(!s->budget--) { s->failed_pc=0x0c0ac134u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac140;
P_0c0ac136: /* original 6ef6, guest PC 0x0c0ac136 */
if(!s->budget--) { s->failed_pc=0x0c0ac136u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac138;
P_0c0ac138: /* original 7f04, guest PC 0x0c0ac138 */
if(!s->budget--) { s->failed_pc=0x0c0ac138u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac13a;
P_0c0ac13a: /* original 4f26, guest PC 0x0c0ac13a */
if(!s->budget--) { s->failed_pc=0x0c0ac13au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac13c;
P_0c0ac13c: /* original 000b, guest PC 0x0c0ac13c */
if(!s->budget--) { s->failed_pc=0x0c0ac13cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac13e: /* original 6ef6, guest PC 0x0c0ac13e */
if(!s->budget--) { s->failed_pc=0x0c0ac13eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac140;
P_0c0ac140: /* original 2fe6, guest PC 0x0c0ac140 */
if(!s->budget--) { s->failed_pc=0x0c0ac140u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ac142;
P_0c0ac142: /* original 6e43, guest PC 0x0c0ac142 */
if(!s->budget--) { s->failed_pc=0x0c0ac142u; return 0; }
r[14]=r[4];
goto P_0c0ac144;
P_0c0ac144: /* original 4f22, guest PC 0x0c0ac144 */
if(!s->budget--) { s->failed_pc=0x0c0ac144u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac146;
P_0c0ac146: /* original 7ffc, guest PC 0x0c0ac146 */
if(!s->budget--) { s->failed_pc=0x0c0ac146u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac148;
P_0c0ac148: /* original 2f52, guest PC 0x0c0ac148 */
if(!s->budget--) { s->failed_pc=0x0c0ac148u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ac14a;
P_0c0ac14a: /* original 65e3, guest PC 0x0c0ac14a */
if(!s->budget--) { s->failed_pc=0x0c0ac14au; return 0; }
r[5]=r[14];
goto P_0c0ac14c;
P_0c0ac14c: /* original d30d, guest PC 0x0c0ac14c */
if(!s->budget--) { s->failed_pc=0x0c0ac14cu; return 0; }
r[3]=read(ram,0x0c0ac184u,4);
goto P_0c0ac14e;
P_0c0ac14e: /* original 430b, guest PC 0x0c0ac14e */
if(!s->budget--) { s->failed_pc=0x0c0ac14eu; return 0; }
target=r[3];
r[16]=0x0c0ac152u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac152u) { target=s->pc; goto dispatch; }
goto P_0c0ac152;
P_0c0ac150: /* original e400, guest PC 0x0c0ac150 */
if(!s->budget--) { s->failed_pc=0x0c0ac150u; return 0; }
r[4]=0x00000000u;
goto P_0c0ac152;
P_0c0ac152: /* original d20d, guest PC 0x0c0ac152 */
if(!s->budget--) { s->failed_pc=0x0c0ac152u; return 0; }
r[2]=read(ram,0x0c0ac188u,4);
goto P_0c0ac154;
P_0c0ac154: /* original 420b, guest PC 0x0c0ac154 */
if(!s->budget--) { s->failed_pc=0x0c0ac154u; return 0; }
target=r[2];
r[16]=0x0c0ac158u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac158u) { target=s->pc; goto dispatch; }
goto P_0c0ac158;
P_0c0ac156: /* original 64e3, guest PC 0x0c0ac156 */
if(!s->budget--) { s->failed_pc=0x0c0ac156u; return 0; }
r[4]=r[14];
goto P_0c0ac158;
P_0c0ac158: /* original 65f2, guest PC 0x0c0ac158 */
if(!s->budget--) { s->failed_pc=0x0c0ac158u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac15a;
P_0c0ac15a: /* original 7f04, guest PC 0x0c0ac15a */
if(!s->budget--) { s->failed_pc=0x0c0ac15au; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac15c;
P_0c0ac15c: /* original 4f26, guest PC 0x0c0ac15c */
if(!s->budget--) { s->failed_pc=0x0c0ac15cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac15e;
P_0c0ac15e: /* original 64e3, guest PC 0x0c0ac15e */
if(!s->budget--) { s->failed_pc=0x0c0ac15eu; return 0; }
r[4]=r[14];
goto P_0c0ac160;
P_0c0ac160: /* original a035, guest PC 0x0c0ac160 */
if(!s->budget--) { s->failed_pc=0x0c0ac160u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac1ce;
P_0c0ac162: /* original 6ef6, guest PC 0x0c0ac162 */
if(!s->budget--) { s->failed_pc=0x0c0ac162u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac164u,s,ram);
P_0c0ac18c: /* original 2fe6, guest PC 0x0c0ac18c */
if(!s->budget--) { s->failed_pc=0x0c0ac18cu; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ac18e;
P_0c0ac18e: /* original 6e43, guest PC 0x0c0ac18e */
if(!s->budget--) { s->failed_pc=0x0c0ac18eu; return 0; }
r[14]=r[4];
goto P_0c0ac190;
P_0c0ac190: /* original e048, guest PC 0x0c0ac190 */
if(!s->budget--) { s->failed_pc=0x0c0ac190u; return 0; }
r[0]=0x00000048u;
goto P_0c0ac192;
P_0c0ac192: /* original 4f22, guest PC 0x0c0ac192 */
if(!s->budget--) { s->failed_pc=0x0c0ac192u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac194;
P_0c0ac194: /* original 7ffc, guest PC 0x0c0ac194 */
if(!s->budget--) { s->failed_pc=0x0c0ac194u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac196;
P_0c0ac196: /* original 2f52, guest PC 0x0c0ac196 */
if(!s->budget--) { s->failed_pc=0x0c0ac196u; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ac198;
P_0c0ac198: /* original 02ee, guest PC 0x0c0ac198 */
if(!s->budget--) { s->failed_pc=0x0c0ac198u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac19a;
P_0c0ac19a: /* original d33e, guest PC 0x0c0ac19a */
if(!s->budget--) { s->failed_pc=0x0c0ac19au; return 0; }
r[3]=read(ram,0x0c0ac294u,4);
goto P_0c0ac19c;
P_0c0ac19c: /* original 2239, guest PC 0x0c0ac19c */
if(!s->budget--) { s->failed_pc=0x0c0ac19cu; return 0; }
r[2]&=r[3];
goto P_0c0ac19e;
P_0c0ac19e: /* original 0e26, guest PC 0x0c0ac19e */
if(!s->budget--) { s->failed_pc=0x0c0ac19eu; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0ac1a0;
P_0c0ac1a0: /* original 9075, guest PC 0x0c0ac1a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac28eu,2);
goto P_0c0ac1a2;
P_0c0ac1a2: /* original d23d, guest PC 0x0c0ac1a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a2u; return 0; }
r[2]=read(ram,0x0c0ac298u,4);
goto P_0c0ac1a4;
P_0c0ac1a4: /* original 04ed, guest PC 0x0c0ac1a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1a6;
P_0c0ac1a6: /* original e048, guest PC 0x0c0ac1a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a6u; return 0; }
r[0]=0x00000048u;
goto P_0c0ac1a8;
P_0c0ac1a8: /* original 01ee, guest PC 0x0c0ac1a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1a8u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0ac1aa;
P_0c0ac1aa: /* original 2128, guest PC 0x0c0ac1aa */
if(!s->budget--) { s->failed_pc=0x0c0ac1aau; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ac1ac;
P_0c0ac1ac: /* original 8d02, guest PC 0x0c0ac1ac */
if(!s->budget--) { s->failed_pc=0x0c0ac1acu; return 0; }
cond=r[17]&1u;
r[4]=r[4]&65535u;
if(cond) { goto P_0c0ac1b4; }
goto P_0c0ac1b0;
P_0c0ac1ae: /* original 644d, guest PC 0x0c0ac1ae */
if(!s->budget--) { s->failed_pc=0x0c0ac1aeu; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ac1b0;
P_0c0ac1b0: /* original d33a, guest PC 0x0c0ac1b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b0u; return 0; }
r[3]=read(ram,0x0c0ac29cu,4);
goto P_0c0ac1b2;
P_0c0ac1b2: /* original 243a, guest PC 0x0c0ac1b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b2u; return 0; }
r[4]^=r[3];
goto P_0c0ac1b4;
P_0c0ac1b4: /* original 6043, guest PC 0x0c0ac1b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b4u; return 0; }
r[0]=r[4];
goto P_0c0ac1b6;
P_0c0ac1b6: /* original 81ef, guest PC 0x0c0ac1b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b6u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ac1b8;
P_0c0ac1b8: /* original 65f2, guest PC 0x0c0ac1b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1b8u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac1ba;
P_0c0ac1ba: /* original 6552, guest PC 0x0c0ac1ba */
if(!s->budget--) { s->failed_pc=0x0c0ac1bau; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c0ac1bc;
P_0c0ac1bc: /* original 655d, guest PC 0x0c0ac1bc */
if(!s->budget--) { s->failed_pc=0x0c0ac1bcu; return 0; }
r[5]=r[5]&65535u;
goto P_0c0ac1be;
P_0c0ac1be: /* original b7a8, guest PC 0x0c0ac1be */
if(!s->budget--) { s->failed_pc=0x0c0ac1beu; return 0; }
target=0x0c0ad112u; r[16]=0x0c0ac1c2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac1c2u) { target=s->pc; goto dispatch; }
goto P_0c0ac1c2;
P_0c0ac1c0: /* original 64e3, guest PC 0x0c0ac1c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c0u; return 0; }
r[4]=r[14];
goto P_0c0ac1c2;
P_0c0ac1c2: /* original 65f2, guest PC 0x0c0ac1c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c2u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ac1c4;
P_0c0ac1c4: /* original 7f04, guest PC 0x0c0ac1c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c4u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac1c6;
P_0c0ac1c6: /* original 4f26, guest PC 0x0c0ac1c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac1c8;
P_0c0ac1c8: /* original 64e3, guest PC 0x0c0ac1c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1c8u; return 0; }
r[4]=r[14];
goto P_0c0ac1ca;
P_0c0ac1ca: /* original a000, guest PC 0x0c0ac1ca */
if(!s->budget--) { s->failed_pc=0x0c0ac1cau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac1ce;
P_0c0ac1cc: /* original 6ef6, guest PC 0x0c0ac1cc */
if(!s->budget--) { s->failed_pc=0x0c0ac1ccu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac1ce;
P_0c0ac1ce: /* original e304, guest PC 0x0c0ac1ce */
if(!s->budget--) { s->failed_pc=0x0c0ac1ceu; return 0; }
r[3]=0x00000004u;
goto P_0c0ac1d0;
P_0c0ac1d0: /* original e062, guest PC 0x0c0ac1d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d0u; return 0; }
r[0]=0x00000062u;
goto P_0c0ac1d2;
P_0c0ac1d2: /* original 6233, guest PC 0x0c0ac1d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d2u; return 0; }
r[2]=r[3];
goto P_0c0ac1d4;
P_0c0ac1d4: /* original 1531, guest PC 0x0c0ac1d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d4u; return 0; }
write(ram,r[5]+4,r[3],4);
goto P_0c0ac1d6;
P_0c0ac1d6: /* original a000, guest PC 0x0c0ac1d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d6u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac1da;
P_0c0ac1d8: /* original 0424, guest PC 0x0c0ac1d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1d8u; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0ac1da;
P_0c0ac1da: /* original 2fe6, guest PC 0x0c0ac1da */
if(!s->budget--) { s->failed_pc=0x0c0ac1dau; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ac1dc;
P_0c0ac1dc: /* original e03e, guest PC 0x0c0ac1dc */
if(!s->budget--) { s->failed_pc=0x0c0ac1dcu; return 0; }
r[0]=0x0000003eu;
goto P_0c0ac1de;
P_0c0ac1de: /* original 6e43, guest PC 0x0c0ac1de */
if(!s->budget--) { s->failed_pc=0x0c0ac1deu; return 0; }
r[14]=r[4];
goto P_0c0ac1e0;
P_0c0ac1e0: /* original 03ed, guest PC 0x0c0ac1e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e2;
P_0c0ac1e2: /* original 9055, guest PC 0x0c0ac1e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ac290u,2);
goto P_0c0ac1e4;
P_0c0ac1e4: /* original 4f22, guest PC 0x0c0ac1e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac1e6;
P_0c0ac1e6: /* original 02ed, guest PC 0x0c0ac1e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac1e8;
P_0c0ac1e8: /* original 3322, guest PC 0x0c0ac1e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1e8u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ac1ea;
P_0c0ac1ea: /* original 8b1b, guest PC 0x0c0ac1ea */
if(!s->budget--) { s->failed_pc=0x0c0ac1eau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ac224; }
goto P_0c0ac1ec;
P_0c0ac1ec: /* original e048, guest PC 0x0c0ac1ec */
if(!s->budget--) { s->failed_pc=0x0c0ac1ecu; return 0; }
r[0]=0x00000048u;
goto P_0c0ac1ee;
P_0c0ac1ee: /* original d32c, guest PC 0x0c0ac1ee */
if(!s->budget--) { s->failed_pc=0x0c0ac1eeu; return 0; }
r[3]=read(ram,0x0c0ac2a0u,4);
goto P_0c0ac1f0;
P_0c0ac1f0: /* original 02ee, guest PC 0x0c0ac1f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f0u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac1f2;
P_0c0ac1f2: /* original 2238, guest PC 0x0c0ac1f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f2u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac1f4;
P_0c0ac1f4: /* original 8908, guest PC 0x0c0ac1f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac208; }
goto P_0c0ac1f6;
P_0c0ac1f6: /* original 61e2, guest PC 0x0c0ac1f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f6u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac1f8;
P_0c0ac1f8: /* original e000, guest PC 0x0c0ac1f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac1f8u; return 0; }
r[0]=0x00000000u;
goto P_0c0ac1fa;
P_0c0ac1fa: /* original d22a, guest PC 0x0c0ac1fa */
if(!s->budget--) { s->failed_pc=0x0c0ac1fau; return 0; }
r[2]=read(ram,0x0c0ac2a4u,4);
goto P_0c0ac1fc;
P_0c0ac1fc: /* original 4f26, guest PC 0x0c0ac1fc */
if(!s->budget--) { s->failed_pc=0x0c0ac1fcu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac1fe;
P_0c0ac1fe: /* original 2129, guest PC 0x0c0ac1fe */
if(!s->budget--) { s->failed_pc=0x0c0ac1feu; return 0; }
r[1]&=r[2];
goto P_0c0ac200;
P_0c0ac200: /* original 2e12, guest PC 0x0c0ac200 */
if(!s->budget--) { s->failed_pc=0x0c0ac200u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ac202;
P_0c0ac202: /* original 1e0e, guest PC 0x0c0ac202 */
if(!s->budget--) { s->failed_pc=0x0c0ac202u; return 0; }
write(ram,r[14]+56,r[0],4);
goto P_0c0ac204;
P_0c0ac204: /* original 000b, guest PC 0x0c0ac204 */
if(!s->budget--) { s->failed_pc=0x0c0ac204u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac206: /* original 6ef6, guest PC 0x0c0ac206 */
if(!s->budget--) { s->failed_pc=0x0c0ac206u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac208;
P_0c0ac208: /* original 61e2, guest PC 0x0c0ac208 */
if(!s->budget--) { s->failed_pc=0x0c0ac208u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ac20a;
P_0c0ac20a: /* original d224, guest PC 0x0c0ac20a */
if(!s->budget--) { s->failed_pc=0x0c0ac20au; return 0; }
r[2]=read(ram,0x0c0ac29cu,4);
goto P_0c0ac20c;
P_0c0ac20c: /* original 2128, guest PC 0x0c0ac20c */
if(!s->budget--) { s->failed_pc=0x0c0ac20cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0ac20e;
P_0c0ac20e: /* original 8907, guest PC 0x0c0ac20e */
if(!s->budget--) { s->failed_pc=0x0c0ac20eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac220; }
goto P_0c0ac210;
P_0c0ac210: /* original d125, guest PC 0x0c0ac210 */
if(!s->budget--) { s->failed_pc=0x0c0ac210u; return 0; }
r[1]=read(ram,0x0c0ac2a8u,4);
goto P_0c0ac212;
P_0c0ac212: /* original 410b, guest PC 0x0c0ac212 */
if(!s->budget--) { s->failed_pc=0x0c0ac212u; return 0; }
target=r[1];
r[16]=0x0c0ac216u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac216u) { target=s->pc; goto dispatch; }
goto P_0c0ac216;
P_0c0ac214: /* original 64e3, guest PC 0x0c0ac214 */
if(!s->budget--) { s->failed_pc=0x0c0ac214u; return 0; }
r[4]=r[14];
goto P_0c0ac216;
P_0c0ac216: /* original 4f26, guest PC 0x0c0ac216 */
if(!s->budget--) { s->failed_pc=0x0c0ac216u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac218;
P_0c0ac218: /* original d324, guest PC 0x0c0ac218 */
if(!s->budget--) { s->failed_pc=0x0c0ac218u; return 0; }
r[3]=read(ram,0x0c0ac2acu,4);
goto P_0c0ac21a;
P_0c0ac21a: /* original 1e3d, guest PC 0x0c0ac21a */
if(!s->budget--) { s->failed_pc=0x0c0ac21au; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0ac21c;
P_0c0ac21c: /* original 000b, guest PC 0x0c0ac21c */
if(!s->budget--) { s->failed_pc=0x0c0ac21cu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac21e: /* original 6ef6, guest PC 0x0c0ac21e */
if(!s->budget--) { s->failed_pc=0x0c0ac21eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ac220;
P_0c0ac220: /* original d123, guest PC 0x0c0ac220 */
if(!s->budget--) { s->failed_pc=0x0c0ac220u; return 0; }
r[1]=read(ram,0x0c0ac2b0u,4);
goto P_0c0ac222;
P_0c0ac222: /* original 1e1d, guest PC 0x0c0ac222 */
if(!s->budget--) { s->failed_pc=0x0c0ac222u; return 0; }
write(ram,r[14]+52,r[1],4);
goto P_0c0ac224;
P_0c0ac224: /* original 4f26, guest PC 0x0c0ac224 */
if(!s->budget--) { s->failed_pc=0x0c0ac224u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac226;
P_0c0ac226: /* original 000b, guest PC 0x0c0ac226 */
if(!s->budget--) { s->failed_pc=0x0c0ac226u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ac228: /* original 6ef6, guest PC 0x0c0ac228 */
if(!s->budget--) { s->failed_pc=0x0c0ac228u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac22au,s,ram);
P_0c0ac90c: /* original 4f22, guest PC 0x0c0ac90c */
if(!s->budget--) { s->failed_pc=0x0c0ac90cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ac90e;
P_0c0ac90e: /* original 53c1, guest PC 0x0c0ac90e */
if(!s->budget--) { s->failed_pc=0x0c0ac90eu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0ac910;
P_0c0ac910: /* original 3342, guest PC 0x0c0ac910 */
if(!s->budget--) { s->failed_pc=0x0c0ac910u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0ac912;
P_0c0ac912: /* original 7ffc, guest PC 0x0c0ac912 */
if(!s->budget--) { s->failed_pc=0x0c0ac912u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ac914;
P_0c0ac914: /* original 8f06, guest PC 0x0c0ac914 */
if(!s->budget--) { s->failed_pc=0x0c0ac914u; return 0; }
cond=r[17]&1u;
r[13]=r[5];
if(!cond) { goto P_0c0ac924; }
goto P_0c0ac918;
P_0c0ac916: /* original 6d53, guest PC 0x0c0ac916 */
if(!s->budget--) { s->failed_pc=0x0c0ac916u; return 0; }
r[13]=r[5];
goto P_0c0ac918;
P_0c0ac918: /* original 50c1, guest PC 0x0c0ac918 */
if(!s->budget--) { s->failed_pc=0x0c0ac918u; return 0; }
r[0]=read(ram,r[12]+4,4);
goto P_0c0ac91a;
P_0c0ac91a: /* original 8801, guest PC 0x0c0ac91a */
if(!s->budget--) { s->failed_pc=0x0c0ac91au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0ac91c;
P_0c0ac91c: /* original 8924, guest PC 0x0c0ac91c */
if(!s->budget--) { s->failed_pc=0x0c0ac91cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac968; }
goto P_0c0ac91e;
P_0c0ac91e: /* original 53c1, guest PC 0x0c0ac91e */
if(!s->budget--) { s->failed_pc=0x0c0ac91eu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0ac920;
P_0c0ac920: /* original 3346, guest PC 0x0c0ac920 */
if(!s->budget--) { s->failed_pc=0x0c0ac920u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>r[4])!=0);
goto P_0c0ac922;
P_0c0ac922: /* original 895a, guest PC 0x0c0ac922 */
if(!s->budget--) { s->failed_pc=0x0c0ac922u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac9da; }
goto P_0c0ac924;
P_0c0ac924: /* original 62e2, guest PC 0x0c0ac924 */
if(!s->budget--) { s->failed_pc=0x0c0ac924u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ac926;
P_0c0ac926: /* original d30f, guest PC 0x0c0ac926 */
if(!s->budget--) { s->failed_pc=0x0c0ac926u; return 0; }
r[3]=read(ram,0x0c0ac964u,4);
goto P_0c0ac928;
P_0c0ac928: /* original 2239, guest PC 0x0c0ac928 */
if(!s->budget--) { s->failed_pc=0x0c0ac928u; return 0; }
r[2]&=r[3];
goto P_0c0ac92a;
P_0c0ac92a: /* original 2e22, guest PC 0x0c0ac92a */
if(!s->budget--) { s->failed_pc=0x0c0ac92au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ac92c;
P_0c0ac92c: /* original 61c2, guest PC 0x0c0ac92c */
if(!s->budget--) { s->failed_pc=0x0c0ac92cu; return 0; }
tmp=read(ram,r[12],4);
r[1]=tmp;
goto P_0c0ac92e;
P_0c0ac92e: /* original 611d, guest PC 0x0c0ac92e */
if(!s->budget--) { s->failed_pc=0x0c0ac92eu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0ac930;
P_0c0ac930: /* original 6513, guest PC 0x0c0ac930 */
if(!s->budget--) { s->failed_pc=0x0c0ac930u; return 0; }
r[5]=r[1];
goto P_0c0ac932;
P_0c0ac932: /* original 2f12, guest PC 0x0c0ac932 */
if(!s->budget--) { s->failed_pc=0x0c0ac932u; return 0; }
write(ram,r[15],r[1],4);
goto P_0c0ac934;
P_0c0ac934: /* original b420, guest PC 0x0c0ac934 */
if(!s->budget--) { s->failed_pc=0x0c0ac934u; return 0; }
target=0x0c0ad178u; r[16]=0x0c0ac938u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ac938u) { target=s->pc; goto dispatch; }
goto P_0c0ac938;
P_0c0ac936: /* original 64e3, guest PC 0x0c0ac936 */
if(!s->budget--) { s->failed_pc=0x0c0ac936u; return 0; }
r[4]=r[14];
goto P_0c0ac938;
P_0c0ac938: /* original 7f04, guest PC 0x0c0ac938 */
if(!s->budget--) { s->failed_pc=0x0c0ac938u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ac93a;
P_0c0ac93a: /* original 66c3, guest PC 0x0c0ac93a */
if(!s->budget--) { s->failed_pc=0x0c0ac93au; return 0; }
r[6]=r[12];
goto P_0c0ac93c;
P_0c0ac93c: /* original 4f26, guest PC 0x0c0ac93c */
if(!s->budget--) { s->failed_pc=0x0c0ac93cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ac93e;
P_0c0ac93e: /* original 65d3, guest PC 0x0c0ac93e */
if(!s->budget--) { s->failed_pc=0x0c0ac93eu; return 0; }
r[5]=r[13];
goto P_0c0ac940;
P_0c0ac940: /* original 64e3, guest PC 0x0c0ac940 */
if(!s->budget--) { s->failed_pc=0x0c0ac940u; return 0; }
r[4]=r[14];
goto P_0c0ac942;
P_0c0ac942: /* original 6cf6, guest PC 0x0c0ac942 */
if(!s->budget--) { s->failed_pc=0x0c0ac942u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ac944;
P_0c0ac944: /* original 6df6, guest PC 0x0c0ac944 */
if(!s->budget--) { s->failed_pc=0x0c0ac944u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ac946;
P_0c0ac946: /* original a067, guest PC 0x0c0ac946 */
if(!s->budget--) { s->failed_pc=0x0c0ac946u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aca18;
P_0c0ac948: /* original 6ef6, guest PC 0x0c0ac948 */
if(!s->budget--) { s->failed_pc=0x0c0ac948u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ac94au,s,ram);
P_0c0ac968: /* original e048, guest PC 0x0c0ac968 */
if(!s->budget--) { s->failed_pc=0x0c0ac968u; return 0; }
r[0]=0x00000048u;
goto P_0c0ac96a;
P_0c0ac96a: /* original d345, guest PC 0x0c0ac96a */
if(!s->budget--) { s->failed_pc=0x0c0ac96au; return 0; }
r[3]=read(ram,0x0c0aca80u,4);
goto P_0c0ac96c;
P_0c0ac96c: /* original 02ee, guest PC 0x0c0ac96c */
if(!s->budget--) { s->failed_pc=0x0c0ac96cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0ac96e;
P_0c0ac96e: /* original 2238, guest PC 0x0c0ac96e */
if(!s->budget--) { s->failed_pc=0x0c0ac96eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ac970;
P_0c0ac970: /* original 8921, guest PC 0x0c0ac970 */
if(!s->budget--) { s->failed_pc=0x0c0ac970u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac9b6; }
goto P_0c0ac972;
P_0c0ac972: /* original e010, guest PC 0x0c0ac972 */
if(!s->budget--) { s->failed_pc=0x0c0ac972u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac974;
P_0c0ac974: /* original f5e6, guest PC 0x0c0ac974 */
if(!s->budget--) { s->failed_pc=0x0c0ac974u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0ac976;
P_0c0ac976: /* original e014, guest PC 0x0c0ac976 */
if(!s->budget--) { s->failed_pc=0x0c0ac976u; return 0; }
r[0]=0x00000014u;
goto P_0c0ac978;
P_0c0ac978: /* original f6e6, guest PC 0x0c0ac978 */
if(!s->budget--) { s->failed_pc=0x0c0ac978u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0ac97a;
P_0c0ac97a: /* original e018, guest PC 0x0c0ac97a */
if(!s->budget--) { s->failed_pc=0x0c0ac97au; return 0; }
r[0]=0x00000018u;
goto P_0c0ac97c;
P_0c0ac97c: /* original f4e6, guest PC 0x0c0ac97c */
if(!s->budget--) { s->failed_pc=0x0c0ac97cu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0ac97e;
P_0c0ac97e: /* original e010, guest PC 0x0c0ac97e */
if(!s->budget--) { s->failed_pc=0x0c0ac97eu; return 0; }
r[0]=0x00000010u;
goto P_0c0ac980;
P_0c0ac980: /* original f9d6, guest PC 0x0c0ac980 */
if(!s->budget--) { s->failed_pc=0x0c0ac980u; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c0ac982;
P_0c0ac982: /* original e014, guest PC 0x0c0ac982 */
if(!s->budget--) { s->failed_pc=0x0c0ac982u; return 0; }
r[0]=0x00000014u;
goto P_0c0ac984;
P_0c0ac984: /* original f8d6, guest PC 0x0c0ac984 */
if(!s->budget--) { s->failed_pc=0x0c0ac984u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c0ac986;
P_0c0ac986: /* original e018, guest PC 0x0c0ac986 */
if(!s->budget--) { s->failed_pc=0x0c0ac986u; return 0; }
r[0]=0x00000018u;
goto P_0c0ac988;
P_0c0ac988: /* original fad6, guest PC 0x0c0ac988 */
if(!s->budget--) { s->failed_pc=0x0c0ac988u; return 0; }
vf3_matrix_load(s,ram,10,r[13]+r[0]);
goto P_0c0ac98a;
P_0c0ac98a: /* original f951, guest PC 0x0c0ac98a */
if(!s->budget--) { s->failed_pc=0x0c0ac98au; return 0; }
fr[9]=vf3_fpu_binary(fr[9],fr[5],r[18],'-');
goto P_0c0ac98c;
P_0c0ac98c: /* original c73d, guest PC 0x0c0ac98c */
if(!s->budget--) { s->failed_pc=0x0c0ac98cu; return 0; }
r[0]=0x0c0aca84u;
goto P_0c0ac98e;
P_0c0ac98e: /* original f35c, guest PC 0x0c0ac98e */
if(!s->budget--) { s->failed_pc=0x0c0ac98eu; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0ac990;
P_0c0ac990: /* original f708, guest PC 0x0c0ac990 */
if(!s->budget--) { s->failed_pc=0x0c0ac990u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0ac992;
P_0c0ac992: /* original f861, guest PC 0x0c0ac992 */
if(!s->budget--) { s->failed_pc=0x0c0ac992u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[6],r[18],'-');
goto P_0c0ac994;
P_0c0ac994: /* original fa41, guest PC 0x0c0ac994 */
if(!s->budget--) { s->failed_pc=0x0c0ac994u; return 0; }
fr[10]=vf3_fpu_binary(fr[10],fr[4],r[18],'-');
goto P_0c0ac996;
P_0c0ac996: /* original f26c, guest PC 0x0c0ac996 */
if(!s->budget--) { s->failed_pc=0x0c0ac996u; return 0; }
vf3_matrix_move(s,2,6);
goto P_0c0ac998;
P_0c0ac998: /* original f07c, guest PC 0x0c0ac998 */
if(!s->budget--) { s->failed_pc=0x0c0ac998u; return 0; }
vf3_matrix_move(s,0,7);
goto P_0c0ac99a;
P_0c0ac99a: /* original f39e, guest PC 0x0c0ac99a */
if(!s->budget--) { s->failed_pc=0x0c0ac99au; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[9],fr[3],r[18]);
goto P_0c0ac99c;
P_0c0ac99c: /* original e010, guest PC 0x0c0ac99c */
if(!s->budget--) { s->failed_pc=0x0c0ac99cu; return 0; }
r[0]=0x00000010u;
goto P_0c0ac99e;
P_0c0ac99e: /* original f28e, guest PC 0x0c0ac99e */
if(!s->budget--) { s->failed_pc=0x0c0ac99eu; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[8],fr[2],r[18]);
goto P_0c0ac9a0;
P_0c0ac9a0: /* original f53c, guest PC 0x0c0ac9a0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a0u; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0ac9a2;
P_0c0ac9a2: /* original f34c, guest PC 0x0c0ac9a2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a2u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ac9a4;
P_0c0ac9a4: /* original f3ae, guest PC 0x0c0ac9a4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a4u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[10],fr[3],r[18]);
goto P_0c0ac9a6;
P_0c0ac9a6: /* original f62c, guest PC 0x0c0ac9a6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a6u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c0ac9a8;
P_0c0ac9a8: /* original f43c, guest PC 0x0c0ac9a8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9a8u; return 0; }
vf3_matrix_move(s,4,3);
goto P_0c0ac9aa;
P_0c0ac9aa: /* original fe57, guest PC 0x0c0ac9aa */
if(!s->budget--) { s->failed_pc=0x0c0ac9aau; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0ac9ac;
P_0c0ac9ac: /* original e014, guest PC 0x0c0ac9ac */
if(!s->budget--) { s->failed_pc=0x0c0ac9acu; return 0; }
r[0]=0x00000014u;
goto P_0c0ac9ae;
P_0c0ac9ae: /* original fe67, guest PC 0x0c0ac9ae */
if(!s->budget--) { s->failed_pc=0x0c0ac9aeu; return 0; }
vf3_matrix_store(s,ram,6,r[14]+r[0]);
goto P_0c0ac9b0;
P_0c0ac9b0: /* original e018, guest PC 0x0c0ac9b0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b0u; return 0; }
r[0]=0x00000018u;
goto P_0c0ac9b2;
P_0c0ac9b2: /* original a02b, guest PC 0x0c0ac9b2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b2u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0aca0c;
P_0c0ac9b4: /* original fe47, guest PC 0x0c0ac9b4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b4u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0ac9b6;
P_0c0ac9b6: /* original e010, guest PC 0x0c0ac9b6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b6u; return 0; }
r[0]=0x00000010u;
goto P_0c0ac9b8;
P_0c0ac9b8: /* original f3d6, guest PC 0x0c0ac9b8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9b8u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ac9ba;
P_0c0ac9ba: /* original fe37, guest PC 0x0c0ac9ba */
if(!s->budget--) { s->failed_pc=0x0c0ac9bau; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac9bc;
P_0c0ac9bc: /* original e014, guest PC 0x0c0ac9bc */
if(!s->budget--) { s->failed_pc=0x0c0ac9bcu; return 0; }
r[0]=0x00000014u;
goto P_0c0ac9be;
P_0c0ac9be: /* original f3d6, guest PC 0x0c0ac9be */
if(!s->budget--) { s->failed_pc=0x0c0ac9beu; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ac9c0;
P_0c0ac9c0: /* original fe37, guest PC 0x0c0ac9c0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c0u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac9c2;
P_0c0ac9c2: /* original e018, guest PC 0x0c0ac9c2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c2u; return 0; }
r[0]=0x00000018u;
goto P_0c0ac9c4;
P_0c0ac9c4: /* original f3d6, guest PC 0x0c0ac9c4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]+r[0]);
goto P_0c0ac9c6;
P_0c0ac9c6: /* original fe37, guest PC 0x0c0ac9c6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c6u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0ac9c8;
P_0c0ac9c8: /* original 85df, guest PC 0x0c0ac9c8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9c8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+30,2);
goto P_0c0ac9ca;
P_0c0ac9ca: /* original 81ef, guest PC 0x0c0ac9ca */
if(!s->budget--) { s->failed_pc=0x0c0ac9cau; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0ac9cc;
P_0c0ac9cc: /* original e062, guest PC 0x0c0ac9cc */
if(!s->budget--) { s->failed_pc=0x0c0ac9ccu; return 0; }
r[0]=0x00000062u;
goto P_0c0ac9ce;
P_0c0ac9ce: /* original 53c1, guest PC 0x0c0ac9ce */
if(!s->budget--) { s->failed_pc=0x0c0ac9ceu; return 0; }
r[3]=read(ram,r[12]+4,4);
goto P_0c0ac9d0;
P_0c0ac9d0: /* original 7301, guest PC 0x0c0ac9d0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d0u; return 0; }
r[3]+=0x00000001u;
goto P_0c0ac9d2;
P_0c0ac9d2: /* original 6233, guest PC 0x0c0ac9d2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d2u; return 0; }
r[2]=r[3];
goto P_0c0ac9d4;
P_0c0ac9d4: /* original 1c31, guest PC 0x0c0ac9d4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d4u; return 0; }
write(ram,r[12]+4,r[3],4);
goto P_0c0ac9d6;
P_0c0ac9d6: /* original a019, guest PC 0x0c0ac9d6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d6u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0aca0c;
P_0c0ac9d8: /* original 0e24, guest PC 0x0c0ac9d8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9d8u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0ac9da;
P_0c0ac9da: /* original e03e, guest PC 0x0c0ac9da */
if(!s->budget--) { s->failed_pc=0x0c0ac9dau; return 0; }
r[0]=0x0000003eu;
goto P_0c0ac9dc;
P_0c0ac9dc: /* original 03ed, guest PC 0x0c0ac9dc */
if(!s->budget--) { s->failed_pc=0x0c0ac9dcu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac9de;
P_0c0ac9de: /* original 9046, guest PC 0x0c0ac9de */
if(!s->budget--) { s->failed_pc=0x0c0ac9deu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca6eu,2);
goto P_0c0ac9e0;
P_0c0ac9e0: /* original 02ed, guest PC 0x0c0ac9e0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac9e2;
P_0c0ac9e2: /* original 3322, guest PC 0x0c0ac9e2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e2u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0ac9e4;
P_0c0ac9e4: /* original 8b12, guest PC 0x0c0ac9e4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aca0c; }
goto P_0c0ac9e6;
P_0c0ac9e6: /* original 9043, guest PC 0x0c0ac9e6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca70u,2);
goto P_0c0ac9e8;
P_0c0ac9e8: /* original 04ed, guest PC 0x0c0ac9e8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9e8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0ac9ea;
P_0c0ac9ea: /* original 644d, guest PC 0x0c0ac9ea */
if(!s->budget--) { s->failed_pc=0x0c0ac9eau; return 0; }
r[4]=r[4]&65535u;
goto P_0c0ac9ec;
P_0c0ac9ec: /* original 644c, guest PC 0x0c0ac9ec */
if(!s->budget--) { s->failed_pc=0x0c0ac9ecu; return 0; }
r[4]=r[4]&255u;
goto P_0c0ac9ee;
P_0c0ac9ee: /* original 6043, guest PC 0x0c0ac9ee */
if(!s->budget--) { s->failed_pc=0x0c0ac9eeu; return 0; }
r[0]=r[4];
goto P_0c0ac9f0;
P_0c0ac9f0: /* original 8804, guest PC 0x0c0ac9f0 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ac9f2;
P_0c0ac9f2: /* original 8902, guest PC 0x0c0ac9f2 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ac9fa; }
goto P_0c0ac9f4;
P_0c0ac9f4: /* original e300, guest PC 0x0c0ac9f4 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f4u; return 0; }
r[3]=0x00000000u;
goto P_0c0ac9f6;
P_0c0ac9f6: /* original a009, guest PC 0x0c0ac9f6 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f6u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0aca0c;
P_0c0ac9f8: /* original 1e3e, guest PC 0x0c0ac9f8 */
if(!s->budget--) { s->failed_pc=0x0c0ac9f8u; return 0; }
write(ram,r[14]+56,r[3],4);
goto P_0c0ac9fa;
P_0c0ac9fa: /* original e066, guest PC 0x0c0ac9fa */
if(!s->budget--) { s->failed_pc=0x0c0ac9fau; return 0; }
r[0]=0x00000066u;
goto P_0c0ac9fc;
P_0c0ac9fc: /* original e202, guest PC 0x0c0ac9fc */
if(!s->budget--) { s->failed_pc=0x0c0ac9fcu; return 0; }
r[2]=0x00000002u;
goto P_0c0ac9fe;
P_0c0ac9fe: /* original 0e25, guest PC 0x0c0ac9fe */
if(!s->budget--) { s->failed_pc=0x0c0ac9feu; return 0; }
write(ram,r[14]+r[0],r[2],2);
goto P_0c0aca00;
P_0c0aca00: /* original d321, guest PC 0x0c0aca00 */
if(!s->budget--) { s->failed_pc=0x0c0aca00u; return 0; }
r[3]=read(ram,0x0c0aca88u,4);
goto P_0c0aca02;
P_0c0aca02: /* original 1e3d, guest PC 0x0c0aca02 */
if(!s->budget--) { s->failed_pc=0x0c0aca02u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0aca04;
P_0c0aca04: /* original 62e2, guest PC 0x0c0aca04 */
if(!s->budget--) { s->failed_pc=0x0c0aca04u; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0aca06;
P_0c0aca06: /* original d321, guest PC 0x0c0aca06 */
if(!s->budget--) { s->failed_pc=0x0c0aca06u; return 0; }
r[3]=read(ram,0x0c0aca8cu,4);
goto P_0c0aca08;
P_0c0aca08: /* original 223b, guest PC 0x0c0aca08 */
if(!s->budget--) { s->failed_pc=0x0c0aca08u; return 0; }
r[2]|=r[3];
goto P_0c0aca0a;
P_0c0aca0a: /* original 2e22, guest PC 0x0c0aca0a */
if(!s->budget--) { s->failed_pc=0x0c0aca0au; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0aca0c;
P_0c0aca0c: /* original 7f04, guest PC 0x0c0aca0c */
if(!s->budget--) { s->failed_pc=0x0c0aca0cu; return 0; }
r[15]+=0x00000004u;
goto P_0c0aca0e;
P_0c0aca0e: /* original 4f26, guest PC 0x0c0aca0e */
if(!s->budget--) { s->failed_pc=0x0c0aca0eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aca10;
P_0c0aca10: /* original 6cf6, guest PC 0x0c0aca10 */
if(!s->budget--) { s->failed_pc=0x0c0aca10u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aca12;
P_0c0aca12: /* original 6df6, guest PC 0x0c0aca12 */
if(!s->budget--) { s->failed_pc=0x0c0aca12u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aca14;
P_0c0aca14: /* original 000b, guest PC 0x0c0aca14 */
if(!s->budget--) { s->failed_pc=0x0c0aca14u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0aca16: /* original 6ef6, guest PC 0x0c0aca16 */
if(!s->budget--) { s->failed_pc=0x0c0aca16u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0aca18;
P_0c0aca18: /* original 902b, guest PC 0x0c0aca18 */
if(!s->budget--) { s->failed_pc=0x0c0aca18u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca72u,2);
goto P_0c0aca1a;
P_0c0aca1a: /* original f38d, guest PC 0x0c0aca1a */
if(!s->budget--) { s->failed_pc=0x0c0aca1au; return 0; }
fr[3]=0;
goto P_0c0aca1c;
P_0c0aca1c: /* original f437, guest PC 0x0c0aca1c */
if(!s->budget--) { s->failed_pc=0x0c0aca1cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca1e;
P_0c0aca1e: /* original 70fc, guest PC 0x0c0aca1e */
if(!s->budget--) { s->failed_pc=0x0c0aca1eu; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0aca20;
P_0c0aca20: /* original f437, guest PC 0x0c0aca20 */
if(!s->budget--) { s->failed_pc=0x0c0aca20u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca22;
P_0c0aca22: /* original 70fc, guest PC 0x0c0aca22 */
if(!s->budget--) { s->failed_pc=0x0c0aca22u; return 0; }
r[0]+=0xfffffffcu;
goto P_0c0aca24;
P_0c0aca24: /* original f437, guest PC 0x0c0aca24 */
if(!s->budget--) { s->failed_pc=0x0c0aca24u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca26;
P_0c0aca26: /* original e02c, guest PC 0x0c0aca26 */
if(!s->budget--) { s->failed_pc=0x0c0aca26u; return 0; }
r[0]=0x0000002cu;
goto P_0c0aca28;
P_0c0aca28: /* original f437, guest PC 0x0c0aca28 */
if(!s->budget--) { s->failed_pc=0x0c0aca28u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca2a;
P_0c0aca2a: /* original e028, guest PC 0x0c0aca2a */
if(!s->budget--) { s->failed_pc=0x0c0aca2au; return 0; }
r[0]=0x00000028u;
goto P_0c0aca2c;
P_0c0aca2c: /* original f437, guest PC 0x0c0aca2c */
if(!s->budget--) { s->failed_pc=0x0c0aca2cu; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca2e;
P_0c0aca2e: /* original e024, guest PC 0x0c0aca2e */
if(!s->budget--) { s->failed_pc=0x0c0aca2eu; return 0; }
r[0]=0x00000024u;
goto P_0c0aca30;
P_0c0aca30: /* original f437, guest PC 0x0c0aca30 */
if(!s->budget--) { s->failed_pc=0x0c0aca30u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0aca32;
P_0c0aca32: /* original e062, guest PC 0x0c0aca32 */
if(!s->budget--) { s->failed_pc=0x0c0aca32u; return 0; }
r[0]=0x00000062u;
goto P_0c0aca34;
P_0c0aca34: /* original 5361, guest PC 0x0c0aca34 */
if(!s->budget--) { s->failed_pc=0x0c0aca34u; return 0; }
r[3]=read(ram,r[6]+4,4);
goto P_0c0aca36;
P_0c0aca36: /* original 7301, guest PC 0x0c0aca36 */
if(!s->budget--) { s->failed_pc=0x0c0aca36u; return 0; }
r[3]+=0x00000001u;
goto P_0c0aca38;
P_0c0aca38: /* original 6233, guest PC 0x0c0aca38 */
if(!s->budget--) { s->failed_pc=0x0c0aca38u; return 0; }
r[2]=r[3];
goto P_0c0aca3a;
P_0c0aca3a: /* original 1631, guest PC 0x0c0aca3a */
if(!s->budget--) { s->failed_pc=0x0c0aca3au; return 0; }
write(ram,r[6]+4,r[3],4);
goto P_0c0aca3c;
P_0c0aca3c: /* original 0424, guest PC 0x0c0aca3c */
if(!s->budget--) { s->failed_pc=0x0c0aca3cu; return 0; }
write(ram,r[4]+r[0],r[2],1);
goto P_0c0aca3e;
P_0c0aca3e: /* original e04c, guest PC 0x0c0aca3e */
if(!s->budget--) { s->failed_pc=0x0c0aca3eu; return 0; }
r[0]=0x0000004cu;
goto P_0c0aca40;
P_0c0aca40: /* original 014e, guest PC 0x0c0aca40 */
if(!s->budget--) { s->failed_pc=0x0c0aca40u; return 0; }
r[1]=read(ram,r[4]+r[0],4);
goto P_0c0aca42;
P_0c0aca42: /* original 9317, guest PC 0x0c0aca42 */
if(!s->budget--) { s->failed_pc=0x0c0aca42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca74u,2);
goto P_0c0aca44;
P_0c0aca44: /* original 2138, guest PC 0x0c0aca44 */
if(!s->budget--) { s->failed_pc=0x0c0aca44u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0aca46;
P_0c0aca46: /* original 890e, guest PC 0x0c0aca46 */
if(!s->budget--) { s->failed_pc=0x0c0aca46u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aca66; }
goto P_0c0aca48;
P_0c0aca48: /* original e06a, guest PC 0x0c0aca48 */
if(!s->budget--) { s->failed_pc=0x0c0aca48u; return 0; }
r[0]=0x0000006au;
goto P_0c0aca4a;
P_0c0aca4a: /* original d211, guest PC 0x0c0aca4a */
if(!s->budget--) { s->failed_pc=0x0c0aca4au; return 0; }
r[2]=read(ram,0x0c0aca90u,4);
goto P_0c0aca4c;
P_0c0aca4c: /* original 065d, guest PC 0x0c0aca4c */
if(!s->budget--) { s->failed_pc=0x0c0aca4cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aca4e;
P_0c0aca4e: /* original 9013, guest PC 0x0c0aca4e */
if(!s->budget--) { s->failed_pc=0x0c0aca4eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca78u,2);
goto P_0c0aca50;
P_0c0aca50: /* original 6363, guest PC 0x0c0aca50 */
if(!s->budget--) { s->failed_pc=0x0c0aca50u; return 0; }
r[3]=r[6];
goto P_0c0aca52;
P_0c0aca52: /* original 9710, guest PC 0x0c0aca52 */
if(!s->budget--) { s->failed_pc=0x0c0aca52u; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca76u,2);
goto P_0c0aca54;
P_0c0aca54: /* original 055d, guest PC 0x0c0aca54 */
if(!s->budget--) { s->failed_pc=0x0c0aca54u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aca56;
P_0c0aca56: /* original 3358, guest PC 0x0c0aca56 */
if(!s->budget--) { s->failed_pc=0x0c0aca56u; return 0; }
r[3]-=r[5];
goto P_0c0aca58;
P_0c0aca58: /* original 6533, guest PC 0x0c0aca58 */
if(!s->budget--) { s->failed_pc=0x0c0aca58u; return 0; }
r[5]=r[3];
goto P_0c0aca5a;
P_0c0aca5a: /* original 2528, guest PC 0x0c0aca5a */
if(!s->budget--) { s->failed_pc=0x0c0aca5au; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0aca5c;
P_0c0aca5c: /* original 8b00, guest PC 0x0c0aca5c */
if(!s->budget--) { s->failed_pc=0x0c0aca5cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aca60; }
goto P_0c0aca5e;
P_0c0aca5e: /* original 970c, guest PC 0x0c0aca5e */
if(!s->budget--) { s->failed_pc=0x0c0aca5eu; return 0; }
r[7]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca7au,2);
goto P_0c0aca60;
P_0c0aca60: /* original 367c, guest PC 0x0c0aca60 */
if(!s->budget--) { s->failed_pc=0x0c0aca60u; return 0; }
r[6]+=r[7];
goto P_0c0aca62;
P_0c0aca62: /* original 6063, guest PC 0x0c0aca62 */
if(!s->budget--) { s->failed_pc=0x0c0aca62u; return 0; }
r[0]=r[6];
goto P_0c0aca64;
P_0c0aca64: /* original 814f, guest PC 0x0c0aca64 */
if(!s->budget--) { s->failed_pc=0x0c0aca64u; return 0; }
write(ram,r[4]+30,r[0],2);
goto P_0c0aca66;
P_0c0aca66: /* original 900a, guest PC 0x0c0aca66 */
if(!s->budget--) { s->failed_pc=0x0c0aca66u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca7eu,2);
goto P_0c0aca68;
P_0c0aca68: /* original 9308, guest PC 0x0c0aca68 */
if(!s->budget--) { s->failed_pc=0x0c0aca68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aca7cu,2);
goto P_0c0aca6a;
P_0c0aca6a: /* original 000b, guest PC 0x0c0aca6a */
if(!s->budget--) { s->failed_pc=0x0c0aca6au; return 0; }
target=r[16];
write(ram,r[4]+r[0],r[3],4);
s->pc=target; return ram->oob==0;
P_0c0aca6c: /* original 0436, guest PC 0x0c0aca6c */
if(!s->budget--) { s->failed_pc=0x0c0aca6cu; return 0; }
write(ram,r[4]+r[0],r[3],4);
return vf3_matrix_family(0x0c0aca6eu,s,ram);
P_0c0acaa8: /* original 4f22, guest PC 0x0c0acaa8 */
if(!s->budget--) { s->failed_pc=0x0c0acaa8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0acaaa;
P_0c0acaaa: /* original d33a, guest PC 0x0c0acaaa */
if(!s->budget--) { s->failed_pc=0x0c0acaaau; return 0; }
r[3]=read(ram,0x0c0acb94u,4);
goto P_0c0acaac;
P_0c0acaac: /* original 7fe8, guest PC 0x0c0acaac */
if(!s->budget--) { s->failed_pc=0x0c0acaacu; return 0; }
r[15]+=0xffffffe8u;
goto P_0c0acaae;
P_0c0acaae: /* original 1f32, guest PC 0x0c0acaae */
if(!s->budget--) { s->failed_pc=0x0c0acaaeu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0acab0;
P_0c0acab0: /* original 53d1, guest PC 0x0c0acab0 */
if(!s->budget--) { s->failed_pc=0x0c0acab0u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0acab2;
P_0c0acab2: /* original db3a, guest PC 0x0c0acab2 */
if(!s->budget--) { s->failed_pc=0x0c0acab2u; return 0; }
r[11]=read(ram,0x0c0acb9cu,4);
goto P_0c0acab4;
P_0c0acab4: /* original da38, guest PC 0x0c0acab4 */
if(!s->budget--) { s->failed_pc=0x0c0acab4u; return 0; }
r[10]=read(ram,0x0c0acb98u,4);
goto P_0c0acab6;
P_0c0acab6: /* original 3342, guest PC 0x0c0acab6 */
if(!s->budget--) { s->failed_pc=0x0c0acab6u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[4])!=0);
goto P_0c0acab8;
P_0c0acab8: /* original 9963, guest PC 0x0c0acab8 */
if(!s->budget--) { s->failed_pc=0x0c0acab8u; return 0; }
r[9]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb82u,2);
goto P_0c0acaba;
P_0c0acaba: /* original 8f0e, guest PC 0x0c0acaba */
if(!s->budget--) { s->failed_pc=0x0c0acabau; return 0; }
cond=r[17]&1u;
r[12]=r[5];
if(!cond) { goto P_0c0acada; }
goto P_0c0acabe;
P_0c0acabc: /* original 6c53, guest PC 0x0c0acabc */
if(!s->budget--) { s->failed_pc=0x0c0acabcu; return 0; }
r[12]=r[5];
goto P_0c0acabe;
P_0c0acabe: /* original 50d1, guest PC 0x0c0acabe */
if(!s->budget--) { s->failed_pc=0x0c0acabeu; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0acac0;
P_0c0acac0: /* original 8801, guest PC 0x0c0acac0 */
if(!s->budget--) { s->failed_pc=0x0c0acac0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0acac2;
P_0c0acac2: /* original 8977, guest PC 0x0c0acac2 */
if(!s->budget--) { s->failed_pc=0x0c0acac2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acbb4; }
goto P_0c0acac4;
P_0c0acac4: /* original 50d1, guest PC 0x0c0acac4 */
if(!s->budget--) { s->failed_pc=0x0c0acac4u; return 0; }
r[0]=read(ram,r[13]+4,4);
goto P_0c0acac6;
P_0c0acac6: /* original 8802, guest PC 0x0c0acac6 */
if(!s->budget--) { s->failed_pc=0x0c0acac6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0acac8;
P_0c0acac8: /* original 8b01, guest PC 0x0c0acac8 */
if(!s->budget--) { s->failed_pc=0x0c0acac8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acace; }
goto P_0c0acaca;
P_0c0acaca: /* original a0b9, guest PC 0x0c0acaca */
if(!s->budget--) { s->failed_pc=0x0c0acacau; return 0; }
goto P_0c0acc40;
P_0c0acacc: /* original 0009, guest PC 0x0c0acacc */
if(!s->budget--) { s->failed_pc=0x0c0acaccu; return 0; }
goto P_0c0acace;
P_0c0acace: /* original 52d1, guest PC 0x0c0acace */
if(!s->budget--) { s->failed_pc=0x0c0acaceu; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0acad0;
P_0c0acad0: /* original e302, guest PC 0x0c0acad0 */
if(!s->budget--) { s->failed_pc=0x0c0acad0u; return 0; }
r[3]=0x00000002u;
goto P_0c0acad2;
P_0c0acad2: /* original 3236, guest PC 0x0c0acad2 */
if(!s->budget--) { s->failed_pc=0x0c0acad2u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>r[3])!=0);
goto P_0c0acad4;
P_0c0acad4: /* original 8b01, guest PC 0x0c0acad4 */
if(!s->budget--) { s->failed_pc=0x0c0acad4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acada; }
goto P_0c0acad6;
P_0c0acad6: /* original a18c, guest PC 0x0c0acad6 */
if(!s->budget--) { s->failed_pc=0x0c0acad6u; return 0; }
goto P_0c0acdf2;
P_0c0acad8: /* original 0009, guest PC 0x0c0acad8 */
if(!s->budget--) { s->failed_pc=0x0c0acad8u; return 0; }
goto P_0c0acada;
P_0c0acada: /* original 9053, guest PC 0x0c0acada */
if(!s->budget--) { s->failed_pc=0x0c0acadau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb84u,2);
goto P_0c0acadc;
P_0c0acadc: /* original 0e44, guest PC 0x0c0acadc */
if(!s->budget--) { s->failed_pc=0x0c0acadcu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0acade;
P_0c0acade: /* original e06a, guest PC 0x0c0acade */
if(!s->budget--) { s->failed_pc=0x0c0acadeu; return 0; }
r[0]=0x0000006au;
goto P_0c0acae0;
P_0c0acae0: /* original 04ed, guest PC 0x0c0acae0 */
if(!s->budget--) { s->failed_pc=0x0c0acae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acae2;
P_0c0acae2: /* original 9050, guest PC 0x0c0acae2 */
if(!s->budget--) { s->failed_pc=0x0c0acae2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb86u,2);
goto P_0c0acae4;
P_0c0acae4: /* original 03ee, guest PC 0x0c0acae4 */
if(!s->budget--) { s->failed_pc=0x0c0acae4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0acae6;
P_0c0acae6: /* original 2398, guest PC 0x0c0acae6 */
if(!s->budget--) { s->failed_pc=0x0c0acae6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[9])==0)!=0);
goto P_0c0acae8;
P_0c0acae8: /* original 8b18, guest PC 0x0c0acae8 */
if(!s->budget--) { s->failed_pc=0x0c0acae8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb1c; }
goto P_0c0acaea;
P_0c0acaea: /* original e048, guest PC 0x0c0acaea */
if(!s->budget--) { s->failed_pc=0x0c0acaeau; return 0; }
r[0]=0x00000048u;
goto P_0c0acaec;
P_0c0acaec: /* original 934c, guest PC 0x0c0acaec */
if(!s->budget--) { s->failed_pc=0x0c0acaecu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb88u,2);
goto P_0c0acaee;
P_0c0acaee: /* original 02ee, guest PC 0x0c0acaee */
if(!s->budget--) { s->failed_pc=0x0c0acaeeu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acaf0;
P_0c0acaf0: /* original 2238, guest PC 0x0c0acaf0 */
if(!s->budget--) { s->failed_pc=0x0c0acaf0u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acaf2;
P_0c0acaf2: /* original 8b13, guest PC 0x0c0acaf2 */
if(!s->budget--) { s->failed_pc=0x0c0acaf2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb1c; }
goto P_0c0acaf4;
P_0c0acaf4: /* original 01ee, guest PC 0x0c0acaf4 */
if(!s->budget--) { s->failed_pc=0x0c0acaf4u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0acaf6;
P_0c0acaf6: /* original 2918, guest PC 0x0c0acaf6 */
if(!s->budget--) { s->failed_pc=0x0c0acaf6u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[1])==0)!=0);
goto P_0c0acaf8;
P_0c0acaf8: /* original 8b10, guest PC 0x0c0acaf8 */
if(!s->budget--) { s->failed_pc=0x0c0acaf8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb1c; }
goto P_0c0acafa;
P_0c0acafa: /* original e050, guest PC 0x0c0acafa */
if(!s->budget--) { s->failed_pc=0x0c0acafau; return 0; }
r[0]=0x00000050u;
goto P_0c0acafc;
P_0c0acafc: /* original d328, guest PC 0x0c0acafc */
if(!s->budget--) { s->failed_pc=0x0c0acafcu; return 0; }
r[3]=read(ram,0x0c0acba0u,4);
goto P_0c0acafe;
P_0c0acafe: /* original 02ce, guest PC 0x0c0acafe */
if(!s->budget--) { s->failed_pc=0x0c0acafeu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0acb00;
P_0c0acb00: /* original 2238, guest PC 0x0c0acb00 */
if(!s->budget--) { s->failed_pc=0x0c0acb00u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acb02;
P_0c0acb02: /* original 8b03, guest PC 0x0c0acb02 */
if(!s->budget--) { s->failed_pc=0x0c0acb02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb0c; }
goto P_0c0acb04;
P_0c0acb04: /* original 01ce, guest PC 0x0c0acb04 */
if(!s->budget--) { s->failed_pc=0x0c0acb04u; return 0; }
r[1]=read(ram,r[12]+r[0],4);
goto P_0c0acb06;
P_0c0acb06: /* original d327, guest PC 0x0c0acb06 */
if(!s->budget--) { s->failed_pc=0x0c0acb06u; return 0; }
r[3]=read(ram,0x0c0acba4u,4);
goto P_0c0acb08;
P_0c0acb08: /* original 2138, guest PC 0x0c0acb08 */
if(!s->budget--) { s->failed_pc=0x0c0acb08u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0acb0a;
P_0c0acb0a: /* original 8900, guest PC 0x0c0acb0a */
if(!s->budget--) { s->failed_pc=0x0c0acb0au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acb0e; }
goto P_0c0acb0c;
P_0c0acb0c: /* original 34ac, guest PC 0x0c0acb0c */
if(!s->budget--) { s->failed_pc=0x0c0acb0cu; return 0; }
r[4]+=r[10];
goto P_0c0acb0e;
P_0c0acb0e: /* original e048, guest PC 0x0c0acb0e */
if(!s->budget--) { s->failed_pc=0x0c0acb0eu; return 0; }
r[0]=0x00000048u;
goto P_0c0acb10;
P_0c0acb10: /* original d325, guest PC 0x0c0acb10 */
if(!s->budget--) { s->failed_pc=0x0c0acb10u; return 0; }
r[3]=read(ram,0x0c0acba8u,4);
goto P_0c0acb12;
P_0c0acb12: /* original 02ee, guest PC 0x0c0acb12 */
if(!s->budget--) { s->failed_pc=0x0c0acb12u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acb14;
P_0c0acb14: /* original 2239, guest PC 0x0c0acb14 */
if(!s->budget--) { s->failed_pc=0x0c0acb14u; return 0; }
r[2]&=r[3];
goto P_0c0acb16;
P_0c0acb16: /* original 0e26, guest PC 0x0c0acb16 */
if(!s->budget--) { s->failed_pc=0x0c0acb16u; return 0; }
write(ram,r[14]+r[0],r[2],4);
goto P_0c0acb18;
P_0c0acb18: /* original 6043, guest PC 0x0c0acb18 */
if(!s->budget--) { s->failed_pc=0x0c0acb18u; return 0; }
r[0]=r[4];
goto P_0c0acb1a;
P_0c0acb1a: /* original 81ef, guest PC 0x0c0acb1a */
if(!s->budget--) { s->failed_pc=0x0c0acb1au; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0acb1c;
P_0c0acb1c: /* original 63d2, guest PC 0x0c0acb1c */
if(!s->budget--) { s->failed_pc=0x0c0acb1cu; return 0; }
tmp=read(ram,r[13],4);
r[3]=tmp;
goto P_0c0acb1e;
P_0c0acb1e: /* original 633d, guest PC 0x0c0acb1e */
if(!s->budget--) { s->failed_pc=0x0c0acb1eu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0acb20;
P_0c0acb20: /* original 6533, guest PC 0x0c0acb20 */
if(!s->budget--) { s->failed_pc=0x0c0acb20u; return 0; }
r[5]=r[3];
goto P_0c0acb22;
P_0c0acb22: /* original 1f32, guest PC 0x0c0acb22 */
if(!s->budget--) { s->failed_pc=0x0c0acb22u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c0acb24;
P_0c0acb24: /* original b2f5, guest PC 0x0c0acb24 */
if(!s->budget--) { s->failed_pc=0x0c0acb24u; return 0; }
target=0x0c0ad112u; r[16]=0x0c0acb28u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acb28u) { target=s->pc; goto dispatch; }
goto P_0c0acb28;
P_0c0acb26: /* original 64e3, guest PC 0x0c0acb26 */
if(!s->budget--) { s->failed_pc=0x0c0acb26u; return 0; }
r[4]=r[14];
goto P_0c0acb28;
P_0c0acb28: /* original e04c, guest PC 0x0c0acb28 */
if(!s->budget--) { s->failed_pc=0x0c0acb28u; return 0; }
r[0]=0x0000004cu;
goto P_0c0acb2a;
P_0c0acb2a: /* original 932e, guest PC 0x0c0acb2a */
if(!s->budget--) { s->failed_pc=0x0c0acb2au; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb8au,2);
goto P_0c0acb2c;
P_0c0acb2c: /* original 02ee, guest PC 0x0c0acb2c */
if(!s->budget--) { s->failed_pc=0x0c0acb2cu; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acb2e;
P_0c0acb2e: /* original 2238, guest PC 0x0c0acb2e */
if(!s->budget--) { s->failed_pc=0x0c0acb2eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acb30;
P_0c0acb30: /* original 890f, guest PC 0x0c0acb30 */
if(!s->budget--) { s->failed_pc=0x0c0acb30u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acb52; }
goto P_0c0acb32;
P_0c0acb32: /* original e06a, guest PC 0x0c0acb32 */
if(!s->budget--) { s->failed_pc=0x0c0acb32u; return 0; }
r[0]=0x0000006au;
goto P_0c0acb34;
P_0c0acb34: /* original 952a, guest PC 0x0c0acb34 */
if(!s->budget--) { s->failed_pc=0x0c0acb34u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb8cu,2);
goto P_0c0acb36;
P_0c0acb36: /* original 04ed, guest PC 0x0c0acb36 */
if(!s->budget--) { s->failed_pc=0x0c0acb36u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acb38;
P_0c0acb38: /* original 9029, guest PC 0x0c0acb38 */
if(!s->budget--) { s->failed_pc=0x0c0acb38u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb8eu,2);
goto P_0c0acb3a;
P_0c0acb3a: /* original 644d, guest PC 0x0c0acb3a */
if(!s->budget--) { s->failed_pc=0x0c0acb3au; return 0; }
r[4]=r[4]&65535u;
goto P_0c0acb3c;
P_0c0acb3c: /* original 06ed, guest PC 0x0c0acb3c */
if(!s->budget--) { s->failed_pc=0x0c0acb3cu; return 0; }
r[6]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acb3e;
P_0c0acb3e: /* original 6343, guest PC 0x0c0acb3e */
if(!s->budget--) { s->failed_pc=0x0c0acb3eu; return 0; }
r[3]=r[4];
goto P_0c0acb40;
P_0c0acb40: /* original 666d, guest PC 0x0c0acb40 */
if(!s->budget--) { s->failed_pc=0x0c0acb40u; return 0; }
r[6]=r[6]&65535u;
goto P_0c0acb42;
P_0c0acb42: /* original 3368, guest PC 0x0c0acb42 */
if(!s->budget--) { s->failed_pc=0x0c0acb42u; return 0; }
r[3]-=r[6];
goto P_0c0acb44;
P_0c0acb44: /* original 6633, guest PC 0x0c0acb44 */
if(!s->budget--) { s->failed_pc=0x0c0acb44u; return 0; }
r[6]=r[3];
goto P_0c0acb46;
P_0c0acb46: /* original 26a8, guest PC 0x0c0acb46 */
if(!s->budget--) { s->failed_pc=0x0c0acb46u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[10])==0)!=0);
goto P_0c0acb48;
P_0c0acb48: /* original 8b00, guest PC 0x0c0acb48 */
if(!s->budget--) { s->failed_pc=0x0c0acb48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acb4c; }
goto P_0c0acb4a;
P_0c0acb4a: /* original 9521, guest PC 0x0c0acb4a */
if(!s->budget--) { s->failed_pc=0x0c0acb4au; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb90u,2);
goto P_0c0acb4c;
P_0c0acb4c: /* original 345c, guest PC 0x0c0acb4c */
if(!s->budget--) { s->failed_pc=0x0c0acb4cu; return 0; }
r[4]+=r[5];
goto P_0c0acb4e;
P_0c0acb4e: /* original 6043, guest PC 0x0c0acb4e */
if(!s->budget--) { s->failed_pc=0x0c0acb4eu; return 0; }
r[0]=r[4];
goto P_0c0acb50;
P_0c0acb50: /* original 81ef, guest PC 0x0c0acb50 */
if(!s->budget--) { s->failed_pc=0x0c0acb50u; return 0; }
write(ram,r[14]+30,r[0],2);
goto P_0c0acb52;
P_0c0acb52: /* original e04c, guest PC 0x0c0acb52 */
if(!s->budget--) { s->failed_pc=0x0c0acb52u; return 0; }
r[0]=0x0000004cu;
goto P_0c0acb54;
P_0c0acb54: /* original d216, guest PC 0x0c0acb54 */
if(!s->budget--) { s->failed_pc=0x0c0acb54u; return 0; }
r[2]=read(ram,0x0c0acbb0u,4);
goto P_0c0acb56;
P_0c0acb56: /* original 05ee, guest PC 0x0c0acb56 */
if(!s->budget--) { s->failed_pc=0x0c0acb56u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0acb58;
P_0c0acb58: /* original 64e2, guest PC 0x0c0acb58 */
if(!s->budget--) { s->failed_pc=0x0c0acb58u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0acb5a;
P_0c0acb5a: /* original d314, guest PC 0x0c0acb5a */
if(!s->budget--) { s->failed_pc=0x0c0acb5au; return 0; }
r[3]=read(ram,0x0c0acbacu,4);
goto P_0c0acb5c;
P_0c0acb5c: /* original 2528, guest PC 0x0c0acb5c */
if(!s->budget--) { s->failed_pc=0x0c0acb5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[2])==0)!=0);
goto P_0c0acb5e;
P_0c0acb5e: /* original 8d01, guest PC 0x0c0acb5e */
if(!s->budget--) { s->failed_pc=0x0c0acb5eu; return 0; }
cond=r[17]&1u;
r[4]|=r[3];
if(cond) { goto P_0c0acb64; }
goto P_0c0acb62;
P_0c0acb60: /* original 243b, guest PC 0x0c0acb60 */
if(!s->budget--) { s->failed_pc=0x0c0acb60u; return 0; }
r[4]|=r[3];
goto P_0c0acb62;
P_0c0acb62: /* original 24b9, guest PC 0x0c0acb62 */
if(!s->budget--) { s->failed_pc=0x0c0acb62u; return 0; }
r[4]&=r[11];
goto P_0c0acb64;
P_0c0acb64: /* original e024, guest PC 0x0c0acb64 */
if(!s->budget--) { s->failed_pc=0x0c0acb64u; return 0; }
r[0]=0x00000024u;
goto P_0c0acb66;
P_0c0acb66: /* original 2e42, guest PC 0x0c0acb66 */
if(!s->budget--) { s->failed_pc=0x0c0acb66u; return 0; }
write(ram,r[14],r[4],4);
goto P_0c0acb68;
P_0c0acb68: /* original f48d, guest PC 0x0c0acb68 */
if(!s->budget--) { s->failed_pc=0x0c0acb68u; return 0; }
fr[4]=0;
goto P_0c0acb6a;
P_0c0acb6a: /* original fe47, guest PC 0x0c0acb6a */
if(!s->budget--) { s->failed_pc=0x0c0acb6au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb6c;
P_0c0acb6c: /* original e028, guest PC 0x0c0acb6c */
if(!s->budget--) { s->failed_pc=0x0c0acb6cu; return 0; }
r[0]=0x00000028u;
goto P_0c0acb6e;
P_0c0acb6e: /* original fe47, guest PC 0x0c0acb6e */
if(!s->budget--) { s->failed_pc=0x0c0acb6eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb70;
P_0c0acb70: /* original e02c, guest PC 0x0c0acb70 */
if(!s->budget--) { s->failed_pc=0x0c0acb70u; return 0; }
r[0]=0x0000002cu;
goto P_0c0acb72;
P_0c0acb72: /* original fe47, guest PC 0x0c0acb72 */
if(!s->budget--) { s->failed_pc=0x0c0acb72u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb74;
P_0c0acb74: /* original 900d, guest PC 0x0c0acb74 */
if(!s->budget--) { s->failed_pc=0x0c0acb74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acb92u,2);
goto P_0c0acb76;
P_0c0acb76: /* original fe47, guest PC 0x0c0acb76 */
if(!s->budget--) { s->failed_pc=0x0c0acb76u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb78;
P_0c0acb78: /* original 7004, guest PC 0x0c0acb78 */
if(!s->budget--) { s->failed_pc=0x0c0acb78u; return 0; }
r[0]+=0x00000004u;
goto P_0c0acb7a;
P_0c0acb7a: /* original fe47, guest PC 0x0c0acb7a */
if(!s->budget--) { s->failed_pc=0x0c0acb7au; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acb7c;
P_0c0acb7c: /* original 7004, guest PC 0x0c0acb7c */
if(!s->budget--) { s->failed_pc=0x0c0acb7cu; return 0; }
r[0]+=0x00000004u;
goto P_0c0acb7e;
P_0c0acb7e: /* original a107, guest PC 0x0c0acb7e */
if(!s->budget--) { s->failed_pc=0x0c0acb7eu; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
goto P_0c0acd90;
P_0c0acb80: /* original fe47, guest PC 0x0c0acb80 */
if(!s->budget--) { s->failed_pc=0x0c0acb80u; return 0; }
vf3_matrix_store(s,ram,4,r[14]+r[0]);
return vf3_matrix_family(0x0c0acb82u,s,ram);
P_0c0acbb4: /* original e03e, guest PC 0x0c0acbb4 */
if(!s->budget--) { s->failed_pc=0x0c0acbb4u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acbb6;
P_0c0acbb6: /* original 02ed, guest PC 0x0c0acbb6 */
if(!s->budget--) { s->failed_pc=0x0c0acbb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbb8;
P_0c0acbb8: /* original 9053, guest PC 0x0c0acbb8 */
if(!s->budget--) { s->failed_pc=0x0c0acbb8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc62u,2);
goto P_0c0acbba;
P_0c0acbba: /* original 03ed, guest PC 0x0c0acbba */
if(!s->budget--) { s->failed_pc=0x0c0acbbau; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbbc;
P_0c0acbbc: /* original 3232, guest PC 0x0c0acbbc */
if(!s->budget--) { s->failed_pc=0x0c0acbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[3])!=0);
goto P_0c0acbbe;
P_0c0acbbe: /* original 8935, guest PC 0x0c0acbbe */
if(!s->budget--) { s->failed_pc=0x0c0acbbeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acc2c; }
goto P_0c0acbc0;
P_0c0acbc0: /* original e048, guest PC 0x0c0acbc0 */
if(!s->budget--) { s->failed_pc=0x0c0acbc0u; return 0; }
r[0]=0x00000048u;
goto P_0c0acbc2;
P_0c0acbc2: /* original d32c, guest PC 0x0c0acbc2 */
if(!s->budget--) { s->failed_pc=0x0c0acbc2u; return 0; }
r[3]=read(ram,0x0c0acc74u,4);
goto P_0c0acbc4;
P_0c0acbc4: /* original 02ee, guest PC 0x0c0acbc4 */
if(!s->budget--) { s->failed_pc=0x0c0acbc4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0acbc6;
P_0c0acbc6: /* original 2238, guest PC 0x0c0acbc6 */
if(!s->budget--) { s->failed_pc=0x0c0acbc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acbc8;
P_0c0acbc8: /* original 8902, guest PC 0x0c0acbc8 */
if(!s->budget--) { s->failed_pc=0x0c0acbc8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acbd0; }
goto P_0c0acbca;
P_0c0acbca: /* original d32b, guest PC 0x0c0acbca */
if(!s->budget--) { s->failed_pc=0x0c0acbcau; return 0; }
r[3]=read(ram,0x0c0acc78u,4);
goto P_0c0acbcc;
P_0c0acbcc: /* original 430b, guest PC 0x0c0acbcc */
if(!s->budget--) { s->failed_pc=0x0c0acbccu; return 0; }
target=r[3];
r[16]=0x0c0acbd0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acbd0u) { target=s->pc; goto dispatch; }
goto P_0c0acbd0;
P_0c0acbce: /* original 64e3, guest PC 0x0c0acbce */
if(!s->budget--) { s->failed_pc=0x0c0acbceu; return 0; }
r[4]=r[14];
goto P_0c0acbd0;
P_0c0acbd0: /* original e048, guest PC 0x0c0acbd0 */
if(!s->budget--) { s->failed_pc=0x0c0acbd0u; return 0; }
r[0]=0x00000048u;
goto P_0c0acbd2;
P_0c0acbd2: /* original 9347, guest PC 0x0c0acbd2 */
if(!s->budget--) { s->failed_pc=0x0c0acbd2u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc64u,2);
goto P_0c0acbd4;
P_0c0acbd4: /* original 02ce, guest PC 0x0c0acbd4 */
if(!s->budget--) { s->failed_pc=0x0c0acbd4u; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0acbd6;
P_0c0acbd6: /* original 2238, guest PC 0x0c0acbd6 */
if(!s->budget--) { s->failed_pc=0x0c0acbd6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acbd8;
P_0c0acbd8: /* original 8901, guest PC 0x0c0acbd8 */
if(!s->budget--) { s->failed_pc=0x0c0acbd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acbde; }
goto P_0c0acbda;
P_0c0acbda: /* original a121, guest PC 0x0c0acbda */
if(!s->budget--) { s->failed_pc=0x0c0acbdau; return 0; }
goto P_0c0ace20;
P_0c0acbdc: /* original 0009, guest PC 0x0c0acbdc */
if(!s->budget--) { s->failed_pc=0x0c0acbdcu; return 0; }
goto P_0c0acbde;
P_0c0acbde: /* original 03ee, guest PC 0x0c0acbde */
if(!s->budget--) { s->failed_pc=0x0c0acbdeu; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0acbe0;
P_0c0acbe0: /* original 2938, guest PC 0x0c0acbe0 */
if(!s->budget--) { s->failed_pc=0x0c0acbe0u; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[3])==0)!=0);
goto P_0c0acbe2;
P_0c0acbe2: /* original 8b01, guest PC 0x0c0acbe2 */
if(!s->budget--) { s->failed_pc=0x0c0acbe2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acbe8; }
goto P_0c0acbe4;
P_0c0acbe4: /* original a11c, guest PC 0x0c0acbe4 */
if(!s->budget--) { s->failed_pc=0x0c0acbe4u; return 0; }
goto P_0c0ace20;
P_0c0acbe6: /* original 0009, guest PC 0x0c0acbe6 */
if(!s->budget--) { s->failed_pc=0x0c0acbe6u; return 0; }
goto P_0c0acbe8;
P_0c0acbe8: /* original e03e, guest PC 0x0c0acbe8 */
if(!s->budget--) { s->failed_pc=0x0c0acbe8u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acbea;
P_0c0acbea: /* original 01ed, guest PC 0x0c0acbea */
if(!s->budget--) { s->failed_pc=0x0c0acbeau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbec;
P_0c0acbec: /* original 903b, guest PC 0x0c0acbec */
if(!s->budget--) { s->failed_pc=0x0c0acbecu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc66u,2);
goto P_0c0acbee;
P_0c0acbee: /* original 611d, guest PC 0x0c0acbee */
if(!s->budget--) { s->failed_pc=0x0c0acbeeu; return 0; }
r[1]=r[1]&65535u;
goto P_0c0acbf0;
P_0c0acbf0: /* original 03ed, guest PC 0x0c0acbf0 */
if(!s->budget--) { s->failed_pc=0x0c0acbf0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acbf2;
P_0c0acbf2: /* original 3133, guest PC 0x0c0acbf2 */
if(!s->budget--) { s->failed_pc=0x0c0acbf2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[3])!=0);
goto P_0c0acbf4;
P_0c0acbf4: /* original 8b01, guest PC 0x0c0acbf4 */
if(!s->budget--) { s->failed_pc=0x0c0acbf4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acbfa; }
goto P_0c0acbf6;
P_0c0acbf6: /* original a113, guest PC 0x0c0acbf6 */
if(!s->budget--) { s->failed_pc=0x0c0acbf6u; return 0; }
goto P_0c0ace20;
P_0c0acbf8: /* original 0009, guest PC 0x0c0acbf8 */
if(!s->budget--) { s->failed_pc=0x0c0acbf8u; return 0; }
goto P_0c0acbfa;
P_0c0acbfa: /* original e048, guest PC 0x0c0acbfa */
if(!s->budget--) { s->failed_pc=0x0c0acbfau; return 0; }
r[0]=0x00000048u;
goto P_0c0acbfc;
P_0c0acbfc: /* original d31f, guest PC 0x0c0acbfc */
if(!s->budget--) { s->failed_pc=0x0c0acbfcu; return 0; }
r[3]=read(ram,0x0c0acc7cu,4);
goto P_0c0acbfe;
P_0c0acbfe: /* original 04ee, guest PC 0x0c0acbfe */
if(!s->budget--) { s->failed_pc=0x0c0acbfeu; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0acc00;
P_0c0acc00: /* original 9032, guest PC 0x0c0acc00 */
if(!s->budget--) { s->failed_pc=0x0c0acc00u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc68u,2);
goto P_0c0acc02;
P_0c0acc02: /* original 65e2, guest PC 0x0c0acc02 */
if(!s->budget--) { s->failed_pc=0x0c0acc02u; return 0; }
tmp=read(ram,r[14],4);
r[5]=tmp;
goto P_0c0acc04;
P_0c0acc04: /* original 06ee, guest PC 0x0c0acc04 */
if(!s->budget--) { s->failed_pc=0x0c0acc04u; return 0; }
r[6]=read(ram,r[14]+r[0],4);
goto P_0c0acc06;
P_0c0acc06: /* original e048, guest PC 0x0c0acc06 */
if(!s->budget--) { s->failed_pc=0x0c0acc06u; return 0; }
r[0]=0x00000048u;
goto P_0c0acc08;
P_0c0acc08: /* original 1e3d, guest PC 0x0c0acc08 */
if(!s->budget--) { s->failed_pc=0x0c0acc08u; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0acc0a;
P_0c0acc0a: /* original 25b9, guest PC 0x0c0acc0a */
if(!s->budget--) { s->failed_pc=0x0c0acc0au; return 0; }
r[5]&=r[11];
goto P_0c0acc0c;
P_0c0acc0c: /* original d21c, guest PC 0x0c0acc0c */
if(!s->budget--) { s->failed_pc=0x0c0acc0cu; return 0; }
r[2]=read(ram,0x0c0acc80u,4);
goto P_0c0acc0e;
P_0c0acc0e: /* original 2e52, guest PC 0x0c0acc0e */
if(!s->budget--) { s->failed_pc=0x0c0acc0eu; return 0; }
write(ram,r[14],r[5],4);
goto P_0c0acc10;
P_0c0acc10: /* original 932b, guest PC 0x0c0acc10 */
if(!s->budget--) { s->failed_pc=0x0c0acc10u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc6au,2);
goto P_0c0acc12;
P_0c0acc12: /* original 2429, guest PC 0x0c0acc12 */
if(!s->budget--) { s->failed_pc=0x0c0acc12u; return 0; }
r[4]&=r[2];
goto P_0c0acc14;
P_0c0acc14: /* original 2638, guest PC 0x0c0acc14 */
if(!s->budget--) { s->failed_pc=0x0c0acc14u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[3])==0)!=0);
goto P_0c0acc16;
P_0c0acc16: /* original 8f02, guest PC 0x0c0acc16 */
if(!s->budget--) { s->failed_pc=0x0c0acc16u; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[4],4);
if(!cond) { goto P_0c0acc1e; }
goto P_0c0acc1a;
P_0c0acc18: /* original 0e46, guest PC 0x0c0acc18 */
if(!s->budget--) { s->failed_pc=0x0c0acc18u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0acc1a;
P_0c0acc1a: /* original a101, guest PC 0x0c0acc1a */
if(!s->budget--) { s->failed_pc=0x0c0acc1au; return 0; }
goto P_0c0ace20;
P_0c0acc1c: /* original 0009, guest PC 0x0c0acc1c */
if(!s->budget--) { s->failed_pc=0x0c0acc1cu; return 0; }
goto P_0c0acc1e;
P_0c0acc1e: /* original d119, guest PC 0x0c0acc1e */
if(!s->budget--) { s->failed_pc=0x0c0acc1eu; return 0; }
r[1]=read(ram,0x0c0acc84u,4);
goto P_0c0acc20;
P_0c0acc20: /* original 241b, guest PC 0x0c0acc20 */
if(!s->budget--) { s->failed_pc=0x0c0acc20u; return 0; }
r[4]|=r[1];
goto P_0c0acc22;
P_0c0acc22: /* original 0e46, guest PC 0x0c0acc22 */
if(!s->budget--) { s->failed_pc=0x0c0acc22u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0acc24;
P_0c0acc24: /* original 9023, guest PC 0x0c0acc24 */
if(!s->budget--) { s->failed_pc=0x0c0acc24u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc6eu,2);
goto P_0c0acc26;
P_0c0acc26: /* original 9321, guest PC 0x0c0acc26 */
if(!s->budget--) { s->failed_pc=0x0c0acc26u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc6cu,2);
goto P_0c0acc28;
P_0c0acc28: /* original a0fa, guest PC 0x0c0acc28 */
if(!s->budget--) { s->failed_pc=0x0c0acc28u; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0ace20;
P_0c0acc2a: /* original 0e35, guest PC 0x0c0acc2a */
if(!s->budget--) { s->failed_pc=0x0c0acc2au; return 0; }
write(ram,r[14]+r[0],r[3],2);
goto P_0c0acc2c;
P_0c0acc2c: /* original 62e2, guest PC 0x0c0acc2c */
if(!s->budget--) { s->failed_pc=0x0c0acc2cu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0acc2e;
P_0c0acc2e: /* original e062, guest PC 0x0c0acc2e */
if(!s->budget--) { s->failed_pc=0x0c0acc2eu; return 0; }
r[0]=0x00000062u;
goto P_0c0acc30;
P_0c0acc30: /* original d315, guest PC 0x0c0acc30 */
if(!s->budget--) { s->failed_pc=0x0c0acc30u; return 0; }
r[3]=read(ram,0x0c0acc88u,4);
goto P_0c0acc32;
P_0c0acc32: /* original 2239, guest PC 0x0c0acc32 */
if(!s->budget--) { s->failed_pc=0x0c0acc32u; return 0; }
r[2]&=r[3];
goto P_0c0acc34;
P_0c0acc34: /* original 2e22, guest PC 0x0c0acc34 */
if(!s->budget--) { s->failed_pc=0x0c0acc34u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0acc36;
P_0c0acc36: /* original 51d1, guest PC 0x0c0acc36 */
if(!s->budget--) { s->failed_pc=0x0c0acc36u; return 0; }
r[1]=read(ram,r[13]+4,4);
goto P_0c0acc38;
P_0c0acc38: /* original 7101, guest PC 0x0c0acc38 */
if(!s->budget--) { s->failed_pc=0x0c0acc38u; return 0; }
r[1]+=0x00000001u;
goto P_0c0acc3a;
P_0c0acc3a: /* original 6213, guest PC 0x0c0acc3a */
if(!s->budget--) { s->failed_pc=0x0c0acc3au; return 0; }
r[2]=r[1];
goto P_0c0acc3c;
P_0c0acc3c: /* original 1d11, guest PC 0x0c0acc3c */
if(!s->budget--) { s->failed_pc=0x0c0acc3cu; return 0; }
write(ram,r[13]+4,r[1],4);
goto P_0c0acc3e;
P_0c0acc3e: /* original 0e24, guest PC 0x0c0acc3e */
if(!s->budget--) { s->failed_pc=0x0c0acc3eu; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0acc40;
P_0c0acc40: /* original 9016, guest PC 0x0c0acc40 */
if(!s->budget--) { s->failed_pc=0x0c0acc40u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc70u,2);
goto P_0c0acc42;
P_0c0acc42: /* original d512, guest PC 0x0c0acc42 */
if(!s->budget--) { s->failed_pc=0x0c0acc42u; return 0; }
r[5]=read(ram,0x0c0acc8cu,4);
goto P_0c0acc44;
P_0c0acc44: /* original 03ee, guest PC 0x0c0acc44 */
if(!s->budget--) { s->failed_pc=0x0c0acc44u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0acc46;
P_0c0acc46: /* original 2538, guest PC 0x0c0acc46 */
if(!s->budget--) { s->failed_pc=0x0c0acc46u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[3])==0)!=0);
goto P_0c0acc48;
P_0c0acc48: /* original 8901, guest PC 0x0c0acc48 */
if(!s->budget--) { s->failed_pc=0x0c0acc48u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acc4e; }
goto P_0c0acc4a;
P_0c0acc4a: /* original 9012, guest PC 0x0c0acc4a */
if(!s->budget--) { s->failed_pc=0x0c0acc4au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc72u,2);
goto P_0c0acc4c;
P_0c0acc4c: /* original 0e44, guest PC 0x0c0acc4c */
if(!s->budget--) { s->failed_pc=0x0c0acc4cu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0acc4e;
P_0c0acc4e: /* original 62e2, guest PC 0x0c0acc4e */
if(!s->budget--) { s->failed_pc=0x0c0acc4eu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0acc50;
P_0c0acc50: /* original d30f, guest PC 0x0c0acc50 */
if(!s->budget--) { s->failed_pc=0x0c0acc50u; return 0; }
r[3]=read(ram,0x0c0acc90u,4);
goto P_0c0acc52;
P_0c0acc52: /* original 2238, guest PC 0x0c0acc52 */
if(!s->budget--) { s->failed_pc=0x0c0acc52u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0acc54;
P_0c0acc54: /* original 891e, guest PC 0x0c0acc54 */
if(!s->budget--) { s->failed_pc=0x0c0acc54u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acc94; }
goto P_0c0acc56;
P_0c0acc56: /* original 9004, guest PC 0x0c0acc56 */
if(!s->budget--) { s->failed_pc=0x0c0acc56u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acc62u,2);
goto P_0c0acc58;
P_0c0acc58: /* original 01ed, guest PC 0x0c0acc58 */
if(!s->budget--) { s->failed_pc=0x0c0acc58u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acc5a;
P_0c0acc5a: /* original e03e, guest PC 0x0c0acc5a */
if(!s->budget--) { s->failed_pc=0x0c0acc5au; return 0; }
r[0]=0x0000003eu;
goto P_0c0acc5c;
P_0c0acc5c: /* original 0e15, guest PC 0x0c0acc5c */
if(!s->budget--) { s->failed_pc=0x0c0acc5cu; return 0; }
write(ram,r[14]+r[0],r[1],2);
goto P_0c0acc5e;
P_0c0acc5e: /* original a0df, guest PC 0x0c0acc5e */
if(!s->budget--) { s->failed_pc=0x0c0acc5eu; return 0; }
goto P_0c0ace20;
P_0c0acc60: /* original 0009, guest PC 0x0c0acc60 */
if(!s->budget--) { s->failed_pc=0x0c0acc60u; return 0; }
return vf3_matrix_family(0x0c0acc62u,s,ram);
P_0c0acc94: /* original e03c, guest PC 0x0c0acc94 */
if(!s->budget--) { s->failed_pc=0x0c0acc94u; return 0; }
r[0]=0x0000003cu;
goto P_0c0acc96;
P_0c0acc96: /* original 9282, guest PC 0x0c0acc96 */
if(!s->budget--) { s->failed_pc=0x0c0acc96u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acd9eu,2);
goto P_0c0acc98;
P_0c0acc98: /* original 03ed, guest PC 0x0c0acc98 */
if(!s->budget--) { s->failed_pc=0x0c0acc98u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acc9a;
P_0c0acc9a: /* original 633d, guest PC 0x0c0acc9a */
if(!s->budget--) { s->failed_pc=0x0c0acc9au; return 0; }
r[3]=r[3]&65535u;
goto P_0c0acc9c;
P_0c0acc9c: /* original 3320, guest PC 0x0c0acc9c */
if(!s->budget--) { s->failed_pc=0x0c0acc9cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[2])!=0);
goto P_0c0acc9e;
P_0c0acc9e: /* original 8b0d, guest PC 0x0c0acc9e */
if(!s->budget--) { s->failed_pc=0x0c0acc9eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0accbc; }
goto P_0c0acca0;
P_0c0acca0: /* original 907e, guest PC 0x0c0acca0 */
if(!s->budget--) { s->failed_pc=0x0c0acca0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda0u,2);
goto P_0c0acca2;
P_0c0acca2: /* original 64f3, guest PC 0x0c0acca2 */
if(!s->budget--) { s->failed_pc=0x0c0acca2u; return 0; }
r[4]=r[15];
goto P_0c0acca4;
P_0c0acca4: /* original d342, guest PC 0x0c0acca4 */
if(!s->budget--) { s->failed_pc=0x0c0acca4u; return 0; }
r[3]=read(ram,0x0c0acdb0u,4);
goto P_0c0acca6;
P_0c0acca6: /* original 740c, guest PC 0x0c0acca6 */
if(!s->budget--) { s->failed_pc=0x0c0acca6u; return 0; }
r[4]+=0x0000000cu;
goto P_0c0acca8;
P_0c0acca8: /* original f5e6, guest PC 0x0c0acca8 */
if(!s->budget--) { s->failed_pc=0x0c0acca8u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0accaa;
P_0c0accaa: /* original 70f8, guest PC 0x0c0accaa */
if(!s->budget--) { s->failed_pc=0x0c0accaau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0accac;
P_0c0accac: /* original 430b, guest PC 0x0c0accac */
if(!s->budget--) { s->failed_pc=0x0c0accacu; return 0; }
target=r[3];
r[16]=0x0c0accb0u;
vf3_matrix_load(s,ram,4,r[14]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0accb0u) { target=s->pc; goto dispatch; }
goto P_0c0accb0;
P_0c0accae: /* original f4e6, guest PC 0x0c0accae */
if(!s->budget--) { s->failed_pc=0x0c0accaeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0accb0;
P_0c0accb0: /* original e204, guest PC 0x0c0accb0 */
if(!s->budget--) { s->failed_pc=0x0c0accb0u; return 0; }
r[2]=0x00000004u;
goto P_0c0accb2;
P_0c0accb2: /* original 6403, guest PC 0x0c0accb2 */
if(!s->budget--) { s->failed_pc=0x0c0accb2u; return 0; }
r[4]=r[0];
goto P_0c0accb4;
P_0c0accb4: /* original 2428, guest PC 0x0c0accb4 */
if(!s->budget--) { s->failed_pc=0x0c0accb4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0accb6;
P_0c0accb6: /* original 8b01, guest PC 0x0c0accb6 */
if(!s->budget--) { s->failed_pc=0x0c0accb6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0accbc; }
goto P_0c0accb8;
P_0c0accb8: /* original a095, guest PC 0x0c0accb8 */
if(!s->budget--) { s->failed_pc=0x0c0accb8u; return 0; }
goto P_0c0acde6;
P_0c0accba: /* original 0009, guest PC 0x0c0accba */
if(!s->budget--) { s->failed_pc=0x0c0accbau; return 0; }
goto P_0c0accbc;
P_0c0accbc: /* original e048, guest PC 0x0c0accbc */
if(!s->budget--) { s->failed_pc=0x0c0accbcu; return 0; }
r[0]=0x00000048u;
goto P_0c0accbe;
P_0c0accbe: /* original d53d, guest PC 0x0c0accbe */
if(!s->budget--) { s->failed_pc=0x0c0accbeu; return 0; }
r[5]=read(ram,0x0c0acdb4u,4);
goto P_0c0accc0;
P_0c0accc0: /* original 04ee, guest PC 0x0c0accc0 */
if(!s->budget--) { s->failed_pc=0x0c0accc0u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c0accc2;
P_0c0accc2: /* original 906e, guest PC 0x0c0accc2 */
if(!s->budget--) { s->failed_pc=0x0c0accc2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda2u,2);
goto P_0c0accc4;
P_0c0accc4: /* original 03ee, guest PC 0x0c0accc4 */
if(!s->budget--) { s->failed_pc=0x0c0accc4u; return 0; }
r[3]=read(ram,r[14]+r[0],4);
goto P_0c0accc6;
P_0c0accc6: /* original 2358, guest PC 0x0c0accc6 */
if(!s->budget--) { s->failed_pc=0x0c0accc6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[5])==0)!=0);
goto P_0c0accc8;
P_0c0accc8: /* original 8d01, guest PC 0x0c0accc8 */
if(!s->budget--) { s->failed_pc=0x0c0accc8u; return 0; }
cond=r[17]&1u;
r[4]&=r[11];
if(cond) { goto P_0c0accce; }
goto P_0c0acccc;
P_0c0accca: /* original 24b9, guest PC 0x0c0accca */
if(!s->budget--) { s->failed_pc=0x0c0acccau; return 0; }
r[4]&=r[11];
goto P_0c0acccc;
P_0c0acccc: /* original 245b, guest PC 0x0c0acccc */
if(!s->budget--) { s->failed_pc=0x0c0accccu; return 0; }
r[4]|=r[5];
goto P_0c0accce;
P_0c0accce: /* original e048, guest PC 0x0c0accce */
if(!s->budget--) { s->failed_pc=0x0c0accceu; return 0; }
r[0]=0x00000048u;
goto P_0c0accd0;
P_0c0accd0: /* original 0e46, guest PC 0x0c0accd0 */
if(!s->budget--) { s->failed_pc=0x0c0accd0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c0accd2;
P_0c0accd2: /* original e04c, guest PC 0x0c0accd2 */
if(!s->budget--) { s->failed_pc=0x0c0accd2u; return 0; }
r[0]=0x0000004cu;
goto P_0c0accd4;
P_0c0accd4: /* original 02ee, guest PC 0x0c0accd4 */
if(!s->budget--) { s->failed_pc=0x0c0accd4u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0accd6;
P_0c0accd6: /* original d338, guest PC 0x0c0accd6 */
if(!s->budget--) { s->failed_pc=0x0c0accd6u; return 0; }
r[3]=read(ram,0x0c0acdb8u,4);
goto P_0c0accd8;
P_0c0accd8: /* original 2238, guest PC 0x0c0accd8 */
if(!s->budget--) { s->failed_pc=0x0c0accd8u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0accda;
P_0c0accda: /* original 8901, guest PC 0x0c0accda */
if(!s->budget--) { s->failed_pc=0x0c0accdau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acce0; }
goto P_0c0accdc;
P_0c0accdc: /* original a083, guest PC 0x0c0accdc */
if(!s->budget--) { s->failed_pc=0x0c0accdcu; return 0; }
goto P_0c0acde6;
P_0c0accde: /* original 0009, guest PC 0x0c0accde */
if(!s->budget--) { s->failed_pc=0x0c0accdeu; return 0; }
goto P_0c0acce0;
P_0c0acce0: /* original 9060, guest PC 0x0c0acce0 */
if(!s->budget--) { s->failed_pc=0x0c0acce0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda4u,2);
goto P_0c0acce2;
P_0c0acce2: /* original 2459, guest PC 0x0c0acce2 */
if(!s->budget--) { s->failed_pc=0x0c0acce2u; return 0; }
r[4]&=r[5];
goto P_0c0acce4;
P_0c0acce4: /* original 6343, guest PC 0x0c0acce4 */
if(!s->budget--) { s->failed_pc=0x0c0acce4u; return 0; }
r[3]=r[4];
goto P_0c0acce6;
P_0c0acce6: /* original 2338, guest PC 0x0c0acce6 */
if(!s->budget--) { s->failed_pc=0x0c0acce6u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0acce8;
P_0c0acce8: /* original 09ec, guest PC 0x0c0acce8 */
if(!s->budget--) { s->failed_pc=0x0c0acce8u; return 0; }
r[9]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0accea;
P_0c0accea: /* original e800, guest PC 0x0c0accea */
if(!s->budget--) { s->failed_pc=0x0c0acceau; return 0; }
r[8]=0x00000000u;
goto P_0c0accec;
P_0c0accec: /* original 699c, guest PC 0x0c0accec */
if(!s->budget--) { s->failed_pc=0x0c0accecu; return 0; }
r[9]=r[9]&255u;
goto P_0c0accee;
P_0c0accee: /* original 8d0a, guest PC 0x0c0accee */
if(!s->budget--) { s->failed_pc=0x0c0acceeu; return 0; }
cond=r[17]&1u;
write(ram,r[15]+4,r[4],4);
if(cond) { goto P_0c0acd06; }
goto P_0c0accf2;
P_0c0accf0: /* original 1f41, guest PC 0x0c0accf0 */
if(!s->budget--) { s->failed_pc=0x0c0accf0u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c0accf2;
P_0c0accf2: /* original 9058, guest PC 0x0c0accf2 */
if(!s->budget--) { s->failed_pc=0x0c0accf2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda6u,2);
goto P_0c0accf4;
P_0c0accf4: /* original 04ed, guest PC 0x0c0accf4 */
if(!s->budget--) { s->failed_pc=0x0c0accf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0accf6;
P_0c0accf6: /* original e066, guest PC 0x0c0accf6 */
if(!s->budget--) { s->failed_pc=0x0c0accf6u; return 0; }
r[0]=0x00000066u;
goto P_0c0accf8;
P_0c0accf8: /* original 349c, guest PC 0x0c0accf8 */
if(!s->budget--) { s->failed_pc=0x0c0accf8u; return 0; }
r[4]+=r[9];
goto P_0c0accfa;
P_0c0accfa: /* original 6543, guest PC 0x0c0accfa */
if(!s->budget--) { s->failed_pc=0x0c0accfau; return 0; }
r[5]=r[4];
goto P_0c0accfc;
P_0c0accfc: /* original 4521, guest PC 0x0c0accfc */
if(!s->budget--) { s->failed_pc=0x0c0accfcu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0accfe;
P_0c0accfe: /* original 4521, guest PC 0x0c0accfe */
if(!s->budget--) { s->failed_pc=0x0c0accfeu; return 0; }
r[17]=(r[17]&~1u)|((r[5]&1)!=0);
r[5]=(uint32_t)((int32_t)r[5]>>1);
goto P_0c0acd00;
P_0c0acd00: /* original 3458, guest PC 0x0c0acd00 */
if(!s->budget--) { s->failed_pc=0x0c0acd00u; return 0; }
r[4]-=r[5];
goto P_0c0acd02;
P_0c0acd02: /* original a002, guest PC 0x0c0acd02 */
if(!s->budget--) { s->failed_pc=0x0c0acd02u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0acd0a;
P_0c0acd04: /* original 0e45, guest PC 0x0c0acd04 */
if(!s->budget--) { s->failed_pc=0x0c0acd04u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0acd06;
P_0c0acd06: /* original e066, guest PC 0x0c0acd06 */
if(!s->budget--) { s->failed_pc=0x0c0acd06u; return 0; }
r[0]=0x00000066u;
goto P_0c0acd08;
P_0c0acd08: /* original 0e85, guest PC 0x0c0acd08 */
if(!s->budget--) { s->failed_pc=0x0c0acd08u; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0acd0a;
P_0c0acd0a: /* original 904c, guest PC 0x0c0acd0a */
if(!s->budget--) { s->failed_pc=0x0c0acd0au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda6u,2);
goto P_0c0acd0c;
P_0c0acd0c: /* original 2998, guest PC 0x0c0acd0c */
if(!s->budget--) { s->failed_pc=0x0c0acd0cu; return 0; }
r[17]=(r[17]&~1u)|(((r[9]&r[9])==0)!=0);
goto P_0c0acd0e;
P_0c0acd0e: /* original 0e85, guest PC 0x0c0acd0e */
if(!s->budget--) { s->failed_pc=0x0c0acd0eu; return 0; }
write(ram,r[14]+r[0],r[8],2);
goto P_0c0acd10;
P_0c0acd10: /* original 904a, guest PC 0x0c0acd10 */
if(!s->budget--) { s->failed_pc=0x0c0acd10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda8u,2);
goto P_0c0acd12;
P_0c0acd12: /* original 03ec, guest PC 0x0c0acd12 */
if(!s->budget--) { s->failed_pc=0x0c0acd12u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0acd14;
P_0c0acd14: /* original 623c, guest PC 0x0c0acd14 */
if(!s->budget--) { s->failed_pc=0x0c0acd14u; return 0; }
r[2]=r[3]&255u;
goto P_0c0acd16;
P_0c0acd16: /* original 7201, guest PC 0x0c0acd16 */
if(!s->budget--) { s->failed_pc=0x0c0acd16u; return 0; }
r[2]+=0x00000001u;
goto P_0c0acd18;
P_0c0acd18: /* original 2f22, guest PC 0x0c0acd18 */
if(!s->budget--) { s->failed_pc=0x0c0acd18u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0acd1a;
P_0c0acd1a: /* original 6323, guest PC 0x0c0acd1a */
if(!s->budget--) { s->failed_pc=0x0c0acd1au; return 0; }
r[3]=r[2];
goto P_0c0acd1c;
P_0c0acd1c: /* original 9044, guest PC 0x0c0acd1c */
if(!s->budget--) { s->failed_pc=0x0c0acd1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acda8u,2);
goto P_0c0acd1e;
P_0c0acd1e: /* original 8f0b, guest PC 0x0c0acd1e */
if(!s->budget--) { s->failed_pc=0x0c0acd1eu; return 0; }
cond=r[17]&1u;
write(ram,r[14]+r[0],r[3],1);
if(!cond) { goto P_0c0acd38; }
goto P_0c0acd22;
P_0c0acd20: /* original 0e34, guest PC 0x0c0acd20 */
if(!s->budget--) { s->failed_pc=0x0c0acd20u; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0acd22;
P_0c0acd22: /* original d326, guest PC 0x0c0acd22 */
if(!s->budget--) { s->failed_pc=0x0c0acd22u; return 0; }
r[3]=read(ram,0x0c0acdbcu,4);
goto P_0c0acd24;
P_0c0acd24: /* original 65c3, guest PC 0x0c0acd24 */
if(!s->budget--) { s->failed_pc=0x0c0acd24u; return 0; }
r[5]=r[12];
goto P_0c0acd26;
P_0c0acd26: /* original 67f2, guest PC 0x0c0acd26 */
if(!s->budget--) { s->failed_pc=0x0c0acd26u; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c0acd28;
P_0c0acd28: /* original 6693, guest PC 0x0c0acd28 */
if(!s->budget--) { s->failed_pc=0x0c0acd28u; return 0; }
r[6]=r[9];
goto P_0c0acd2a;
P_0c0acd2a: /* original 430b, guest PC 0x0c0acd2a */
if(!s->budget--) { s->failed_pc=0x0c0acd2au; return 0; }
target=r[3];
r[16]=0x0c0acd2eu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acd2eu) { target=s->pc; goto dispatch; }
goto P_0c0acd2e;
P_0c0acd2c: /* original 64e3, guest PC 0x0c0acd2c */
if(!s->budget--) { s->failed_pc=0x0c0acd2cu; return 0; }
r[4]=r[14];
goto P_0c0acd2e;
P_0c0acd2e: /* original 52f1, guest PC 0x0c0acd2e */
if(!s->budget--) { s->failed_pc=0x0c0acd2eu; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c0acd30;
P_0c0acd30: /* original 2228, guest PC 0x0c0acd30 */
if(!s->budget--) { s->failed_pc=0x0c0acd30u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0acd32;
P_0c0acd32: /* original 8b10, guest PC 0x0c0acd32 */
if(!s->budget--) { s->failed_pc=0x0c0acd32u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acd56; }
goto P_0c0acd34;
P_0c0acd34: /* original a01d, guest PC 0x0c0acd34 */
if(!s->budget--) { s->failed_pc=0x0c0acd34u; return 0; }
goto P_0c0acd72;
P_0c0acd36: /* original 0009, guest PC 0x0c0acd36 */
if(!s->budget--) { s->failed_pc=0x0c0acd36u; return 0; }
goto P_0c0acd38;
P_0c0acd38: /* original 53f2, guest PC 0x0c0acd38 */
if(!s->budget--) { s->failed_pc=0x0c0acd38u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c0acd3a;
P_0c0acd3a: /* original 5235, guest PC 0x0c0acd3a */
if(!s->budget--) { s->failed_pc=0x0c0acd3au; return 0; }
r[2]=read(ram,r[3]+20,4);
goto P_0c0acd3c;
P_0c0acd3c: /* original 4215, guest PC 0x0c0acd3c */
if(!s->budget--) { s->failed_pc=0x0c0acd3cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0acd3e;
P_0c0acd3e: /* original 8b0a, guest PC 0x0c0acd3e */
if(!s->budget--) { s->failed_pc=0x0c0acd3eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acd56; }
goto P_0c0acd40;
P_0c0acd40: /* original d31f, guest PC 0x0c0acd40 */
if(!s->budget--) { s->failed_pc=0x0c0acd40u; return 0; }
r[3]=read(ram,0x0c0acdc0u,4);
goto P_0c0acd42;
P_0c0acd42: /* original 65c3, guest PC 0x0c0acd42 */
if(!s->budget--) { s->failed_pc=0x0c0acd42u; return 0; }
r[5]=r[12];
goto P_0c0acd44;
P_0c0acd44: /* original 6693, guest PC 0x0c0acd44 */
if(!s->budget--) { s->failed_pc=0x0c0acd44u; return 0; }
r[6]=r[9];
goto P_0c0acd46;
P_0c0acd46: /* original 430b, guest PC 0x0c0acd46 */
if(!s->budget--) { s->failed_pc=0x0c0acd46u; return 0; }
target=r[3];
r[16]=0x0c0acd4au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acd4au) { target=s->pc; goto dispatch; }
goto P_0c0acd4a;
P_0c0acd48: /* original 64e3, guest PC 0x0c0acd48 */
if(!s->budget--) { s->failed_pc=0x0c0acd48u; return 0; }
r[4]=r[14];
goto P_0c0acd4a;
P_0c0acd4a: /* original d31c, guest PC 0x0c0acd4a */
if(!s->budget--) { s->failed_pc=0x0c0acd4au; return 0; }
r[3]=read(ram,0x0c0acdbcu,4);
goto P_0c0acd4c;
P_0c0acd4c: /* original 65c3, guest PC 0x0c0acd4c */
if(!s->budget--) { s->failed_pc=0x0c0acd4cu; return 0; }
r[5]=r[12];
goto P_0c0acd4e;
P_0c0acd4e: /* original 67f2, guest PC 0x0c0acd4e */
if(!s->budget--) { s->failed_pc=0x0c0acd4eu; return 0; }
tmp=read(ram,r[15],4);
r[7]=tmp;
goto P_0c0acd50;
P_0c0acd50: /* original 6693, guest PC 0x0c0acd50 */
if(!s->budget--) { s->failed_pc=0x0c0acd50u; return 0; }
r[6]=r[9];
goto P_0c0acd52;
P_0c0acd52: /* original 430b, guest PC 0x0c0acd52 */
if(!s->budget--) { s->failed_pc=0x0c0acd52u; return 0; }
target=r[3];
r[16]=0x0c0acd56u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acd56u) { target=s->pc; goto dispatch; }
goto P_0c0acd56;
P_0c0acd54: /* original 64e3, guest PC 0x0c0acd54 */
if(!s->budget--) { s->failed_pc=0x0c0acd54u; return 0; }
r[4]=r[14];
goto P_0c0acd56;
P_0c0acd56: /* original c71c, guest PC 0x0c0acd56 */
if(!s->budget--) { s->failed_pc=0x0c0acd56u; return 0; }
r[0]=0x0c0acdc8u;
goto P_0c0acd58;
P_0c0acd58: /* original d21a, guest PC 0x0c0acd58 */
if(!s->budget--) { s->failed_pc=0x0c0acd58u; return 0; }
r[2]=read(ram,0x0c0acdc4u,4);
goto P_0c0acd5a;
P_0c0acd5a: /* original f308, guest PC 0x0c0acd5a */
if(!s->budget--) { s->failed_pc=0x0c0acd5au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0acd5c;
P_0c0acd5c: /* original 9025, guest PC 0x0c0acd5c */
if(!s->budget--) { s->failed_pc=0x0c0acd5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acdaau,2);
goto P_0c0acd5e;
P_0c0acd5e: /* original 6422, guest PC 0x0c0acd5e */
if(!s->budget--) { s->failed_pc=0x0c0acd5eu; return 0; }
tmp=read(ram,r[2],4);
r[4]=tmp;
goto P_0c0acd60;
P_0c0acd60: /* original f437, guest PC 0x0c0acd60 */
if(!s->budget--) { s->failed_pc=0x0c0acd60u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0acd62;
P_0c0acd62: /* original 53f1, guest PC 0x0c0acd62 */
if(!s->budget--) { s->failed_pc=0x0c0acd62u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0acd64;
P_0c0acd64: /* original 2338, guest PC 0x0c0acd64 */
if(!s->budget--) { s->failed_pc=0x0c0acd64u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0acd66;
P_0c0acd66: /* original 8b3e, guest PC 0x0c0acd66 */
if(!s->budget--) { s->failed_pc=0x0c0acd66u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acde6; }
goto P_0c0acd68;
P_0c0acd68: /* original e046, guest PC 0x0c0acd68 */
if(!s->budget--) { s->failed_pc=0x0c0acd68u; return 0; }
r[0]=0x00000046u;
goto P_0c0acd6a;
P_0c0acd6a: /* original 02ed, guest PC 0x0c0acd6a */
if(!s->budget--) { s->failed_pc=0x0c0acd6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acd6c;
P_0c0acd6c: /* original 622d, guest PC 0x0c0acd6c */
if(!s->budget--) { s->failed_pc=0x0c0acd6cu; return 0; }
r[2]=r[2]&65535u;
goto P_0c0acd6e;
P_0c0acd6e: /* original 4215, guest PC 0x0c0acd6e */
if(!s->budget--) { s->failed_pc=0x0c0acd6eu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>0)!=0);
goto P_0c0acd70;
P_0c0acd70: /* original 8b04, guest PC 0x0c0acd70 */
if(!s->budget--) { s->failed_pc=0x0c0acd70u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0acd7c; }
goto P_0c0acd72;
P_0c0acd72: /* original 63e2, guest PC 0x0c0acd72 */
if(!s->budget--) { s->failed_pc=0x0c0acd72u; return 0; }
tmp=read(ram,r[14],4);
r[3]=tmp;
goto P_0c0acd74;
P_0c0acd74: /* original 23b9, guest PC 0x0c0acd74 */
if(!s->budget--) { s->failed_pc=0x0c0acd74u; return 0; }
r[3]&=r[11];
goto P_0c0acd76;
P_0c0acd76: /* original 2e32, guest PC 0x0c0acd76 */
if(!s->budget--) { s->failed_pc=0x0c0acd76u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0acd78;
P_0c0acd78: /* original a052, guest PC 0x0c0acd78 */
if(!s->budget--) { s->failed_pc=0x0c0acd78u; return 0; }
write(ram,r[14]+56,r[8],4);
goto P_0c0ace20;
P_0c0acd7a: /* original 1e8e, guest PC 0x0c0acd7a */
if(!s->budget--) { s->failed_pc=0x0c0acd7au; return 0; }
write(ram,r[14]+56,r[8],4);
goto P_0c0acd7c;
P_0c0acd7c: /* original d213, guest PC 0x0c0acd7c */
if(!s->budget--) { s->failed_pc=0x0c0acd7cu; return 0; }
r[2]=read(ram,0x0c0acdccu,4);
goto P_0c0acd7e;
P_0c0acd7e: /* original e503, guest PC 0x0c0acd7e */
if(!s->budget--) { s->failed_pc=0x0c0acd7eu; return 0; }
r[5]=0x00000003u;
goto P_0c0acd80;
P_0c0acd80: /* original 420b, guest PC 0x0c0acd80 */
if(!s->budget--) { s->failed_pc=0x0c0acd80u; return 0; }
target=r[2];
r[16]=0x0c0acd84u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0acd84u) { target=s->pc; goto dispatch; }
goto P_0c0acd84;
P_0c0acd82: /* original 64e3, guest PC 0x0c0acd82 */
if(!s->budget--) { s->failed_pc=0x0c0acd82u; return 0; }
r[4]=r[14];
goto P_0c0acd84;
P_0c0acd84: /* original 6403, guest PC 0x0c0acd84 */
if(!s->budget--) { s->failed_pc=0x0c0acd84u; return 0; }
r[4]=r[0];
goto P_0c0acd86;
P_0c0acd86: /* original 2448, guest PC 0x0c0acd86 */
if(!s->budget--) { s->failed_pc=0x0c0acd86u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0acd88;
P_0c0acd88: /* original 8922, guest PC 0x0c0acd88 */
if(!s->budget--) { s->failed_pc=0x0c0acd88u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acdd0; }
goto P_0c0acd8a;
P_0c0acd8a: /* original 900f, guest PC 0x0c0acd8a */
if(!s->budget--) { s->failed_pc=0x0c0acd8au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acdacu,2);
goto P_0c0acd8c;
P_0c0acd8c: /* original e303, guest PC 0x0c0acd8c */
if(!s->budget--) { s->failed_pc=0x0c0acd8cu; return 0; }
r[3]=0x00000003u;
goto P_0c0acd8e;
P_0c0acd8e: /* original 0e34, guest PC 0x0c0acd8e */
if(!s->budget--) { s->failed_pc=0x0c0acd8eu; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0acd90;
P_0c0acd90: /* original 52d1, guest PC 0x0c0acd90 */
if(!s->budget--) { s->failed_pc=0x0c0acd90u; return 0; }
r[2]=read(ram,r[13]+4,4);
goto P_0c0acd92;
P_0c0acd92: /* original e062, guest PC 0x0c0acd92 */
if(!s->budget--) { s->failed_pc=0x0c0acd92u; return 0; }
r[0]=0x00000062u;
goto P_0c0acd94;
P_0c0acd94: /* original 7201, guest PC 0x0c0acd94 */
if(!s->budget--) { s->failed_pc=0x0c0acd94u; return 0; }
r[2]+=0x00000001u;
goto P_0c0acd96;
P_0c0acd96: /* original 6323, guest PC 0x0c0acd96 */
if(!s->budget--) { s->failed_pc=0x0c0acd96u; return 0; }
r[3]=r[2];
goto P_0c0acd98;
P_0c0acd98: /* original 1d21, guest PC 0x0c0acd98 */
if(!s->budget--) { s->failed_pc=0x0c0acd98u; return 0; }
write(ram,r[13]+4,r[2],4);
goto P_0c0acd9a;
P_0c0acd9a: /* original a041, guest PC 0x0c0acd9a */
if(!s->budget--) { s->failed_pc=0x0c0acd9au; return 0; }
write(ram,r[14]+r[0],r[3],1);
goto P_0c0ace20;
P_0c0acd9c: /* original 0e34, guest PC 0x0c0acd9c */
if(!s->budget--) { s->failed_pc=0x0c0acd9cu; return 0; }
write(ram,r[14]+r[0],r[3],1);
return vf3_matrix_family(0x0c0acd9eu,s,ram);
P_0c0acdd0: /* original e061, guest PC 0x0c0acdd0 */
if(!s->budget--) { s->failed_pc=0x0c0acdd0u; return 0; }
r[0]=0x00000061u;
goto P_0c0acdd2;
P_0c0acdd2: /* original 00ec, guest PC 0x0c0acdd2 */
if(!s->budget--) { s->failed_pc=0x0c0acdd2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0acdd4;
P_0c0acdd4: /* original 600c, guest PC 0x0c0acdd4 */
if(!s->budget--) { s->failed_pc=0x0c0acdd4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0acdd6;
P_0c0acdd6: /* original 880c, guest PC 0x0c0acdd6 */
if(!s->budget--) { s->failed_pc=0x0c0acdd6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0acdd8;
P_0c0acdd8: /* original 8902, guest PC 0x0c0acdd8 */
if(!s->budget--) { s->failed_pc=0x0c0acdd8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0acde0; }
goto P_0c0acdda;
P_0c0acdda: /* original d344, guest PC 0x0c0acdda */
if(!s->budget--) { s->failed_pc=0x0c0acddau; return 0; }
r[3]=read(ram,0x0c0aceecu,4);
goto P_0c0acddc;
P_0c0acddc: /* original a020, guest PC 0x0c0acddc */
if(!s->budget--) { s->failed_pc=0x0c0acddcu; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0ace20;
P_0c0acdde: /* original 1e3d, guest PC 0x0c0acdde */
if(!s->budget--) { s->failed_pc=0x0c0acddeu; return 0; }
write(ram,r[14]+52,r[3],4);
goto P_0c0acde0;
P_0c0acde0: /* original d243, guest PC 0x0c0acde0 */
if(!s->budget--) { s->failed_pc=0x0c0acde0u; return 0; }
r[2]=read(ram,0x0c0acef0u,4);
goto P_0c0acde2;
P_0c0acde2: /* original a01d, guest PC 0x0c0acde2 */
if(!s->budget--) { s->failed_pc=0x0c0acde2u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c0ace20;
P_0c0acde4: /* original 1e2d, guest PC 0x0c0acde4 */
if(!s->budget--) { s->failed_pc=0x0c0acde4u; return 0; }
write(ram,r[14]+52,r[2],4);
goto P_0c0acde6;
P_0c0acde6: /* original 53d1, guest PC 0x0c0acde6 */
if(!s->budget--) { s->failed_pc=0x0c0acde6u; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0acde8;
P_0c0acde8: /* original e062, guest PC 0x0c0acde8 */
if(!s->budget--) { s->failed_pc=0x0c0acde8u; return 0; }
r[0]=0x00000062u;
goto P_0c0acdea;
P_0c0acdea: /* original 7301, guest PC 0x0c0acdea */
if(!s->budget--) { s->failed_pc=0x0c0acdeau; return 0; }
r[3]+=0x00000001u;
goto P_0c0acdec;
P_0c0acdec: /* original 6233, guest PC 0x0c0acdec */
if(!s->budget--) { s->failed_pc=0x0c0acdecu; return 0; }
r[2]=r[3];
goto P_0c0acdee;
P_0c0acdee: /* original 1d31, guest PC 0x0c0acdee */
if(!s->budget--) { s->failed_pc=0x0c0acdeeu; return 0; }
write(ram,r[13]+4,r[3],4);
goto P_0c0acdf0;
P_0c0acdf0: /* original 0e24, guest PC 0x0c0acdf0 */
if(!s->budget--) { s->failed_pc=0x0c0acdf0u; return 0; }
write(ram,r[14]+r[0],r[2],1);
goto P_0c0acdf2;
P_0c0acdf2: /* original e03e, guest PC 0x0c0acdf2 */
if(!s->budget--) { s->failed_pc=0x0c0acdf2u; return 0; }
r[0]=0x0000003eu;
goto P_0c0acdf4;
P_0c0acdf4: /* original 03ed, guest PC 0x0c0acdf4 */
if(!s->budget--) { s->failed_pc=0x0c0acdf4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acdf6;
P_0c0acdf6: /* original 9070, guest PC 0x0c0acdf6 */
if(!s->budget--) { s->failed_pc=0x0c0acdf6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedau,2);
goto P_0c0acdf8;
P_0c0acdf8: /* original 02ed, guest PC 0x0c0acdf8 */
if(!s->budget--) { s->failed_pc=0x0c0acdf8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0acdfa;
P_0c0acdfa: /* original 3322, guest PC 0x0c0acdfa */
if(!s->budget--) { s->failed_pc=0x0c0acdfau; return 0; }
r[17]=(r[17]&~1u)|((r[3]>=r[2])!=0);
goto P_0c0acdfc;
P_0c0acdfc: /* original 8b10, guest PC 0x0c0acdfc */
if(!s->budget--) { s->failed_pc=0x0c0acdfcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ace20; }
goto P_0c0acdfe;
P_0c0acdfe: /* original 62e2, guest PC 0x0c0acdfe */
if(!s->budget--) { s->failed_pc=0x0c0acdfeu; return 0; }
tmp=read(ram,r[14],4);
r[2]=tmp;
goto P_0c0ace00;
P_0c0ace00: /* original 2a28, guest PC 0x0c0ace00 */
if(!s->budget--) { s->failed_pc=0x0c0ace00u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[2])==0)!=0);
goto P_0c0ace02;
P_0c0ace02: /* original 8b02, guest PC 0x0c0ace02 */
if(!s->budget--) { s->failed_pc=0x0c0ace02u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ace0a; }
goto P_0c0ace04;
P_0c0ace04: /* original d43b, guest PC 0x0c0ace04 */
if(!s->budget--) { s->failed_pc=0x0c0ace04u; return 0; }
r[4]=read(ram,0x0c0acef4u,4);
goto P_0c0ace06;
P_0c0ace06: /* original a00a, guest PC 0x0c0ace06 */
if(!s->budget--) { s->failed_pc=0x0c0ace06u; return 0; }
goto P_0c0ace1e;
P_0c0ace08: /* original 0009, guest PC 0x0c0ace08 */
if(!s->budget--) { s->failed_pc=0x0c0ace08u; return 0; }
goto P_0c0ace0a;
P_0c0ace0a: /* original d23b, guest PC 0x0c0ace0a */
if(!s->budget--) { s->failed_pc=0x0c0ace0au; return 0; }
r[2]=read(ram,0x0c0acef8u,4);
goto P_0c0ace0c;
P_0c0ace0c: /* original 420b, guest PC 0x0c0ace0c */
if(!s->budget--) { s->failed_pc=0x0c0ace0cu; return 0; }
target=r[2];
r[16]=0x0c0ace10u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ace10u) { target=s->pc; goto dispatch; }
goto P_0c0ace10;
P_0c0ace0e: /* original 64e3, guest PC 0x0c0ace0e */
if(!s->budget--) { s->failed_pc=0x0c0ace0eu; return 0; }
r[4]=r[14];
goto P_0c0ace10;
P_0c0ace10: /* original 9064, guest PC 0x0c0ace10 */
if(!s->budget--) { s->failed_pc=0x0c0ace10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedcu,2);
goto P_0c0ace12;
P_0c0ace12: /* original 9364, guest PC 0x0c0ace12 */
if(!s->budget--) { s->failed_pc=0x0c0ace12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0acedeu,2);
goto P_0c0ace14;
P_0c0ace14: /* original 05ec, guest PC 0x0c0ace14 */
if(!s->budget--) { s->failed_pc=0x0c0ace14u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0ace16;
P_0c0ace16: /* original d439, guest PC 0x0c0ace16 */
if(!s->budget--) { s->failed_pc=0x0c0ace16u; return 0; }
r[4]=read(ram,0x0c0acefcu,4);
goto P_0c0ace18;
P_0c0ace18: /* original 655c, guest PC 0x0c0ace18 */
if(!s->budget--) { s->failed_pc=0x0c0ace18u; return 0; }
r[5]=r[5]&255u;
goto P_0c0ace1a;
P_0c0ace1a: /* original 253b, guest PC 0x0c0ace1a */
if(!s->budget--) { s->failed_pc=0x0c0ace1au; return 0; }
r[5]|=r[3];
goto P_0c0ace1c;
P_0c0ace1c: /* original 0e54, guest PC 0x0c0ace1c */
if(!s->budget--) { s->failed_pc=0x0c0ace1cu; return 0; }
write(ram,r[14]+r[0],r[5],1);
goto P_0c0ace1e;
P_0c0ace1e: /* original 1e4d, guest PC 0x0c0ace1e */
if(!s->budget--) { s->failed_pc=0x0c0ace1eu; return 0; }
write(ram,r[14]+52,r[4],4);
goto P_0c0ace20;
P_0c0ace20: /* original 7f18, guest PC 0x0c0ace20 */
if(!s->budget--) { s->failed_pc=0x0c0ace20u; return 0; }
r[15]+=0x00000018u;
goto P_0c0ace22;
P_0c0ace22: /* original 4f26, guest PC 0x0c0ace22 */
if(!s->budget--) { s->failed_pc=0x0c0ace22u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ace24;
P_0c0ace24: /* original 68f6, guest PC 0x0c0ace24 */
if(!s->budget--) { s->failed_pc=0x0c0ace24u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0ace26;
P_0c0ace26: /* original 69f6, guest PC 0x0c0ace26 */
if(!s->budget--) { s->failed_pc=0x0c0ace26u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ace28;
P_0c0ace28: /* original 6af6, guest PC 0x0c0ace28 */
if(!s->budget--) { s->failed_pc=0x0c0ace28u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ace2a;
P_0c0ace2a: /* original 6bf6, guest PC 0x0c0ace2a */
if(!s->budget--) { s->failed_pc=0x0c0ace2au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ace2c;
P_0c0ace2c: /* original 6cf6, guest PC 0x0c0ace2c */
if(!s->budget--) { s->failed_pc=0x0c0ace2cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ace2e;
P_0c0ace2e: /* original 6df6, guest PC 0x0c0ace2e */
if(!s->budget--) { s->failed_pc=0x0c0ace2eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ace30;
P_0c0ace30: /* original 000b, guest PC 0x0c0ace30 */
if(!s->budget--) { s->failed_pc=0x0c0ace30u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ace32: /* original 6ef6, guest PC 0x0c0ace32 */
if(!s->budget--) { s->failed_pc=0x0c0ace32u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ace34u,s,ram);
P_0c0ad578: /* original 6360, guest PC 0x0c0ad578 */
if(!s->budget--) { s->failed_pc=0x0c0ad578u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[6],1);
r[3]=tmp;
goto P_0c0ad57a;
P_0c0ad57a: /* original 7ffc, guest PC 0x0c0ad57a */
if(!s->budget--) { s->failed_pc=0x0c0ad57au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ad57c;
P_0c0ad57c: /* original d007, guest PC 0x0c0ad57c */
if(!s->budget--) { s->failed_pc=0x0c0ad57cu; return 0; }
r[0]=read(ram,0x0c0ad59cu,4);
goto P_0c0ad57e;
P_0c0ad57e: /* original 633c, guest PC 0x0c0ad57e */
if(!s->budget--) { s->failed_pc=0x0c0ad57eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ad580;
P_0c0ad580: /* original 4308, guest PC 0x0c0ad580 */
if(!s->budget--) { s->failed_pc=0x0c0ad580u; return 0; }
r[3]<<=2;
goto P_0c0ad582;
P_0c0ad582: /* original 023e, guest PC 0x0c0ad582 */
if(!s->budget--) { s->failed_pc=0x0c0ad582u; return 0; }
r[2]=read(ram,r[3]+r[0],4);
goto P_0c0ad584;
P_0c0ad584: /* original 2f22, guest PC 0x0c0ad584 */
if(!s->budget--) { s->failed_pc=0x0c0ad584u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ad586;
P_0c0ad586: /* original 422b, guest PC 0x0c0ad586 */
if(!s->budget--) { s->failed_pc=0x0c0ad586u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ad588: /* original 7f04, guest PC 0x0c0ad588 */
if(!s->budget--) { s->failed_pc=0x0c0ad588u; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ad58au,s,ram);
P_0c0ad878: /* original 4f22, guest PC 0x0c0ad878 */
if(!s->budget--) { s->failed_pc=0x0c0ad878u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ad87a;
P_0c0ad87a: /* original d353, guest PC 0x0c0ad87a */
if(!s->budget--) { s->failed_pc=0x0c0ad87au; return 0; }
r[3]=read(ram,0x0c0ad9c8u,4);
goto P_0c0ad87c;
P_0c0ad87c: /* original 7ff4, guest PC 0x0c0ad87c */
if(!s->budget--) { s->failed_pc=0x0c0ad87cu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0ad87e;
P_0c0ad87e: /* original 67f3, guest PC 0x0c0ad87e */
if(!s->budget--) { s->failed_pc=0x0c0ad87eu; return 0; }
r[7]=r[15];
goto P_0c0ad880;
P_0c0ad880: /* original 7704, guest PC 0x0c0ad880 */
if(!s->budget--) { s->failed_pc=0x0c0ad880u; return 0; }
r[7]+=0x00000004u;
goto P_0c0ad882;
P_0c0ad882: /* original 6d73, guest PC 0x0c0ad882 */
if(!s->budget--) { s->failed_pc=0x0c0ad882u; return 0; }
r[13]=r[7];
goto P_0c0ad884;
P_0c0ad884: /* original 6e73, guest PC 0x0c0ad884 */
if(!s->budget--) { s->failed_pc=0x0c0ad884u; return 0; }
r[14]=r[7];
goto P_0c0ad886;
P_0c0ad886: /* original 2f32, guest PC 0x0c0ad886 */
if(!s->budget--) { s->failed_pc=0x0c0ad886u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ad888;
P_0c0ad888: /* original 8462, guest PC 0x0c0ad888 */
if(!s->budget--) { s->failed_pc=0x0c0ad888u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0ad88a;
P_0c0ad88a: /* original d750, guest PC 0x0c0ad88a */
if(!s->budget--) { s->failed_pc=0x0c0ad88au; return 0; }
r[7]=read(ram,0x0c0ad9ccu,4);
goto P_0c0ad88c;
P_0c0ad88c: /* original 600c, guest PC 0x0c0ad88c */
if(!s->budget--) { s->failed_pc=0x0c0ad88cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad88e;
P_0c0ad88e: /* original 4018, guest PC 0x0c0ad88e */
if(!s->budget--) { s->failed_pc=0x0c0ad88eu; return 0; }
r[0]<<=8;
goto P_0c0ad890;
P_0c0ad890: /* original 2079, guest PC 0x0c0ad890 */
if(!s->budget--) { s->failed_pc=0x0c0ad890u; return 0; }
r[0]&=r[7];
goto P_0c0ad892;
P_0c0ad892: /* original 6303, guest PC 0x0c0ad892 */
if(!s->budget--) { s->failed_pc=0x0c0ad892u; return 0; }
r[3]=r[0];
goto P_0c0ad894;
P_0c0ad894: /* original 8461, guest PC 0x0c0ad894 */
if(!s->budget--) { s->failed_pc=0x0c0ad894u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0ad896;
P_0c0ad896: /* original 600c, guest PC 0x0c0ad896 */
if(!s->budget--) { s->failed_pc=0x0c0ad896u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad898;
P_0c0ad898: /* original 230b, guest PC 0x0c0ad898 */
if(!s->budget--) { s->failed_pc=0x0c0ad898u; return 0; }
r[3]|=r[0];
goto P_0c0ad89a;
P_0c0ad89a: /* original 908a, guest PC 0x0c0ad89a */
if(!s->budget--) { s->failed_pc=0x0c0ad89au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9b2u,2);
goto P_0c0ad89c;
P_0c0ad89c: /* original 0435, guest PC 0x0c0ad89c */
if(!s->budget--) { s->failed_pc=0x0c0ad89cu; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad89e;
P_0c0ad89e: /* original 8464, guest PC 0x0c0ad89e */
if(!s->budget--) { s->failed_pc=0x0c0ad89eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0ad8a0;
P_0c0ad8a0: /* original 600c, guest PC 0x0c0ad8a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad8a0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8a2;
P_0c0ad8a2: /* original 4018, guest PC 0x0c0ad8a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad8a2u; return 0; }
r[0]<<=8;
goto P_0c0ad8a4;
P_0c0ad8a4: /* original 2079, guest PC 0x0c0ad8a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad8a4u; return 0; }
r[0]&=r[7];
goto P_0c0ad8a6;
P_0c0ad8a6: /* original 6303, guest PC 0x0c0ad8a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad8a6u; return 0; }
r[3]=r[0];
goto P_0c0ad8a8;
P_0c0ad8a8: /* original 8463, guest PC 0x0c0ad8a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad8a8u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0ad8aa;
P_0c0ad8aa: /* original 600c, guest PC 0x0c0ad8aa */
if(!s->budget--) { s->failed_pc=0x0c0ad8aau; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8ac;
P_0c0ad8ac: /* original 230b, guest PC 0x0c0ad8ac */
if(!s->budget--) { s->failed_pc=0x0c0ad8acu; return 0; }
r[3]|=r[0];
goto P_0c0ad8ae;
P_0c0ad8ae: /* original 9081, guest PC 0x0c0ad8ae */
if(!s->budget--) { s->failed_pc=0x0c0ad8aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9b4u,2);
goto P_0c0ad8b0;
P_0c0ad8b0: /* original 0435, guest PC 0x0c0ad8b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad8b0u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad8b2;
P_0c0ad8b2: /* original 8466, guest PC 0x0c0ad8b2 */
if(!s->budget--) { s->failed_pc=0x0c0ad8b2u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0ad8b4;
P_0c0ad8b4: /* original 600c, guest PC 0x0c0ad8b4 */
if(!s->budget--) { s->failed_pc=0x0c0ad8b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8b6;
P_0c0ad8b6: /* original 4018, guest PC 0x0c0ad8b6 */
if(!s->budget--) { s->failed_pc=0x0c0ad8b6u; return 0; }
r[0]<<=8;
goto P_0c0ad8b8;
P_0c0ad8b8: /* original 2079, guest PC 0x0c0ad8b8 */
if(!s->budget--) { s->failed_pc=0x0c0ad8b8u; return 0; }
r[0]&=r[7];
goto P_0c0ad8ba;
P_0c0ad8ba: /* original 6303, guest PC 0x0c0ad8ba */
if(!s->budget--) { s->failed_pc=0x0c0ad8bau; return 0; }
r[3]=r[0];
goto P_0c0ad8bc;
P_0c0ad8bc: /* original 8465, guest PC 0x0c0ad8bc */
if(!s->budget--) { s->failed_pc=0x0c0ad8bcu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0ad8be;
P_0c0ad8be: /* original 600c, guest PC 0x0c0ad8be */
if(!s->budget--) { s->failed_pc=0x0c0ad8beu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8c0;
P_0c0ad8c0: /* original 230b, guest PC 0x0c0ad8c0 */
if(!s->budget--) { s->failed_pc=0x0c0ad8c0u; return 0; }
r[3]|=r[0];
goto P_0c0ad8c2;
P_0c0ad8c2: /* original 9078, guest PC 0x0c0ad8c2 */
if(!s->budget--) { s->failed_pc=0x0c0ad8c2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9b6u,2);
goto P_0c0ad8c4;
P_0c0ad8c4: /* original 0435, guest PC 0x0c0ad8c4 */
if(!s->budget--) { s->failed_pc=0x0c0ad8c4u; return 0; }
write(ram,r[4]+r[0],r[3],2);
goto P_0c0ad8c6;
P_0c0ad8c6: /* original 846a, guest PC 0x0c0ad8c6 */
if(!s->budget--) { s->failed_pc=0x0c0ad8c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0ad8c8;
P_0c0ad8c8: /* original dc42, guest PC 0x0c0ad8c8 */
if(!s->budget--) { s->failed_pc=0x0c0ad8c8u; return 0; }
r[12]=read(ram,0x0c0ad9d4u,4);
goto P_0c0ad8ca;
P_0c0ad8ca: /* original 600c, guest PC 0x0c0ad8ca */
if(!s->budget--) { s->failed_pc=0x0c0ad8cau; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8cc;
P_0c0ad8cc: /* original db40, guest PC 0x0c0ad8cc */
if(!s->budget--) { s->failed_pc=0x0c0ad8ccu; return 0; }
r[11]=read(ram,0x0c0ad9d0u,4);
goto P_0c0ad8ce;
P_0c0ad8ce: /* original 4028, guest PC 0x0c0ad8ce */
if(!s->budget--) { s->failed_pc=0x0c0ad8ceu; return 0; }
r[0]<<=16;
goto P_0c0ad8d0;
P_0c0ad8d0: /* original 4018, guest PC 0x0c0ad8d0 */
if(!s->budget--) { s->failed_pc=0x0c0ad8d0u; return 0; }
r[0]<<=8;
goto P_0c0ad8d2;
P_0c0ad8d2: /* original 20c9, guest PC 0x0c0ad8d2 */
if(!s->budget--) { s->failed_pc=0x0c0ad8d2u; return 0; }
r[0]&=r[12];
goto P_0c0ad8d4;
P_0c0ad8d4: /* original 6303, guest PC 0x0c0ad8d4 */
if(!s->budget--) { s->failed_pc=0x0c0ad8d4u; return 0; }
r[3]=r[0];
goto P_0c0ad8d6;
P_0c0ad8d6: /* original 8469, guest PC 0x0c0ad8d6 */
if(!s->budget--) { s->failed_pc=0x0c0ad8d6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0ad8d8;
P_0c0ad8d8: /* original 600c, guest PC 0x0c0ad8d8 */
if(!s->budget--) { s->failed_pc=0x0c0ad8d8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8da;
P_0c0ad8da: /* original 4028, guest PC 0x0c0ad8da */
if(!s->budget--) { s->failed_pc=0x0c0ad8dau; return 0; }
r[0]<<=16;
goto P_0c0ad8dc;
P_0c0ad8dc: /* original 20b9, guest PC 0x0c0ad8dc */
if(!s->budget--) { s->failed_pc=0x0c0ad8dcu; return 0; }
r[0]&=r[11];
goto P_0c0ad8de;
P_0c0ad8de: /* original 230b, guest PC 0x0c0ad8de */
if(!s->budget--) { s->failed_pc=0x0c0ad8deu; return 0; }
r[3]|=r[0];
goto P_0c0ad8e0;
P_0c0ad8e0: /* original 8468, guest PC 0x0c0ad8e0 */
if(!s->budget--) { s->failed_pc=0x0c0ad8e0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0ad8e2;
P_0c0ad8e2: /* original 600c, guest PC 0x0c0ad8e2 */
if(!s->budget--) { s->failed_pc=0x0c0ad8e2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8e4;
P_0c0ad8e4: /* original 4018, guest PC 0x0c0ad8e4 */
if(!s->budget--) { s->failed_pc=0x0c0ad8e4u; return 0; }
r[0]<<=8;
goto P_0c0ad8e6;
P_0c0ad8e6: /* original 2079, guest PC 0x0c0ad8e6 */
if(!s->budget--) { s->failed_pc=0x0c0ad8e6u; return 0; }
r[0]&=r[7];
goto P_0c0ad8e8;
P_0c0ad8e8: /* original 230b, guest PC 0x0c0ad8e8 */
if(!s->budget--) { s->failed_pc=0x0c0ad8e8u; return 0; }
r[3]|=r[0];
goto P_0c0ad8ea;
P_0c0ad8ea: /* original 8467, guest PC 0x0c0ad8ea */
if(!s->budget--) { s->failed_pc=0x0c0ad8eau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0ad8ec;
P_0c0ad8ec: /* original 600c, guest PC 0x0c0ad8ec */
if(!s->budget--) { s->failed_pc=0x0c0ad8ecu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad8ee;
P_0c0ad8ee: /* original 230b, guest PC 0x0c0ad8ee */
if(!s->budget--) { s->failed_pc=0x0c0ad8eeu; return 0; }
r[3]|=r[0];
goto P_0c0ad8f0;
P_0c0ad8f0: /* original 2e32, guest PC 0x0c0ad8f0 */
if(!s->budget--) { s->failed_pc=0x0c0ad8f0u; return 0; }
write(ram,r[14],r[3],4);
goto P_0c0ad8f2;
P_0c0ad8f2: /* original 9061, guest PC 0x0c0ad8f2 */
if(!s->budget--) { s->failed_pc=0x0c0ad8f2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9b8u,2);
goto P_0c0ad8f4;
P_0c0ad8f4: /* original f3d8, guest PC 0x0c0ad8f4 */
if(!s->budget--) { s->failed_pc=0x0c0ad8f4u; return 0; }
vf3_matrix_load(s,ram,3,r[13]);
goto P_0c0ad8f6;
P_0c0ad8f6: /* original f437, guest PC 0x0c0ad8f6 */
if(!s->budget--) { s->failed_pc=0x0c0ad8f6u; return 0; }
vf3_matrix_store(s,ram,3,r[4]+r[0]);
goto P_0c0ad8f8;
P_0c0ad8f8: /* original 915f, guest PC 0x0c0ad8f8 */
if(!s->budget--) { s->failed_pc=0x0c0ad8f8u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9bau,2);
goto P_0c0ad8fa;
P_0c0ad8fa: /* original 846b, guest PC 0x0c0ad8fa */
if(!s->budget--) { s->failed_pc=0x0c0ad8fau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0ad8fc;
P_0c0ad8fc: /* original 314c, guest PC 0x0c0ad8fc */
if(!s->budget--) { s->failed_pc=0x0c0ad8fcu; return 0; }
r[1]+=r[4];
goto P_0c0ad8fe;
P_0c0ad8fe: /* original 2100, guest PC 0x0c0ad8fe */
if(!s->budget--) { s->failed_pc=0x0c0ad8feu; return 0; }
write(ram,r[1],r[0],1);
goto P_0c0ad900;
P_0c0ad900: /* original 6163, guest PC 0x0c0ad900 */
if(!s->budget--) { s->failed_pc=0x0c0ad900u; return 0; }
r[1]=r[6];
goto P_0c0ad902;
P_0c0ad902: /* original 846d, guest PC 0x0c0ad902 */
if(!s->budget--) { s->failed_pc=0x0c0ad902u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0ad904;
P_0c0ad904: /* original 7111, guest PC 0x0c0ad904 */
if(!s->budget--) { s->failed_pc=0x0c0ad904u; return 0; }
r[1]+=0x00000011u;
goto P_0c0ad906;
P_0c0ad906: /* original 9359, guest PC 0x0c0ad906 */
if(!s->budget--) { s->failed_pc=0x0c0ad906u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9bcu,2);
goto P_0c0ad908;
P_0c0ad908: /* original 600c, guest PC 0x0c0ad908 */
if(!s->budget--) { s->failed_pc=0x0c0ad908u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad90a;
P_0c0ad90a: /* original 4018, guest PC 0x0c0ad90a */
if(!s->budget--) { s->failed_pc=0x0c0ad90au; return 0; }
r[0]<<=8;
goto P_0c0ad90c;
P_0c0ad90c: /* original 2039, guest PC 0x0c0ad90c */
if(!s->budget--) { s->failed_pc=0x0c0ad90cu; return 0; }
r[0]&=r[3];
goto P_0c0ad90e;
P_0c0ad90e: /* original 6203, guest PC 0x0c0ad90e */
if(!s->budget--) { s->failed_pc=0x0c0ad90eu; return 0; }
r[2]=r[0];
goto P_0c0ad910;
P_0c0ad910: /* original 846c, guest PC 0x0c0ad910 */
if(!s->budget--) { s->failed_pc=0x0c0ad910u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0ad912;
P_0c0ad912: /* original 600c, guest PC 0x0c0ad912 */
if(!s->budget--) { s->failed_pc=0x0c0ad912u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad914;
P_0c0ad914: /* original 220b, guest PC 0x0c0ad914 */
if(!s->budget--) { s->failed_pc=0x0c0ad914u; return 0; }
r[2]|=r[0];
goto P_0c0ad916;
P_0c0ad916: /* original 9052, guest PC 0x0c0ad916 */
if(!s->budget--) { s->failed_pc=0x0c0ad916u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9beu,2);
goto P_0c0ad918;
P_0c0ad918: /* original 0425, guest PC 0x0c0ad918 */
if(!s->budget--) { s->failed_pc=0x0c0ad918u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ad91a;
P_0c0ad91a: /* original 6210, guest PC 0x0c0ad91a */
if(!s->budget--) { s->failed_pc=0x0c0ad91au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[2]=tmp;
goto P_0c0ad91c;
P_0c0ad91c: /* original 6163, guest PC 0x0c0ad91c */
if(!s->budget--) { s->failed_pc=0x0c0ad91cu; return 0; }
r[1]=r[6];
goto P_0c0ad91e;
P_0c0ad91e: /* original 7110, guest PC 0x0c0ad91e */
if(!s->budget--) { s->failed_pc=0x0c0ad91eu; return 0; }
r[1]+=0x00000010u;
goto P_0c0ad920;
P_0c0ad920: /* original 6110, guest PC 0x0c0ad920 */
if(!s->budget--) { s->failed_pc=0x0c0ad920u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[1],1);
r[1]=tmp;
goto P_0c0ad922;
P_0c0ad922: /* original 622c, guest PC 0x0c0ad922 */
if(!s->budget--) { s->failed_pc=0x0c0ad922u; return 0; }
r[2]=r[2]&255u;
goto P_0c0ad924;
P_0c0ad924: /* original 4228, guest PC 0x0c0ad924 */
if(!s->budget--) { s->failed_pc=0x0c0ad924u; return 0; }
r[2]<<=16;
goto P_0c0ad926;
P_0c0ad926: /* original 611c, guest PC 0x0c0ad926 */
if(!s->budget--) { s->failed_pc=0x0c0ad926u; return 0; }
r[1]=r[1]&255u;
goto P_0c0ad928;
P_0c0ad928: /* original 4128, guest PC 0x0c0ad928 */
if(!s->budget--) { s->failed_pc=0x0c0ad928u; return 0; }
r[1]<<=16;
goto P_0c0ad92a;
P_0c0ad92a: /* original 4218, guest PC 0x0c0ad92a */
if(!s->budget--) { s->failed_pc=0x0c0ad92au; return 0; }
r[2]<<=8;
goto P_0c0ad92c;
P_0c0ad92c: /* original 21b9, guest PC 0x0c0ad92c */
if(!s->budget--) { s->failed_pc=0x0c0ad92cu; return 0; }
r[1]&=r[11];
goto P_0c0ad92e;
P_0c0ad92e: /* original 22c9, guest PC 0x0c0ad92e */
if(!s->budget--) { s->failed_pc=0x0c0ad92eu; return 0; }
r[2]&=r[12];
goto P_0c0ad930;
P_0c0ad930: /* original 846f, guest PC 0x0c0ad930 */
if(!s->budget--) { s->failed_pc=0x0c0ad930u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+15,1);
goto P_0c0ad932;
P_0c0ad932: /* original 221b, guest PC 0x0c0ad932 */
if(!s->budget--) { s->failed_pc=0x0c0ad932u; return 0; }
r[2]|=r[1];
goto P_0c0ad934;
P_0c0ad934: /* original 600c, guest PC 0x0c0ad934 */
if(!s->budget--) { s->failed_pc=0x0c0ad934u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad936;
P_0c0ad936: /* original 4018, guest PC 0x0c0ad936 */
if(!s->budget--) { s->failed_pc=0x0c0ad936u; return 0; }
r[0]<<=8;
goto P_0c0ad938;
P_0c0ad938: /* original 2079, guest PC 0x0c0ad938 */
if(!s->budget--) { s->failed_pc=0x0c0ad938u; return 0; }
r[0]&=r[7];
goto P_0c0ad93a;
P_0c0ad93a: /* original 220b, guest PC 0x0c0ad93a */
if(!s->budget--) { s->failed_pc=0x0c0ad93au; return 0; }
r[2]|=r[0];
goto P_0c0ad93c;
P_0c0ad93c: /* original 846e, guest PC 0x0c0ad93c */
if(!s->budget--) { s->failed_pc=0x0c0ad93cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0ad93e;
P_0c0ad93e: /* original 600c, guest PC 0x0c0ad93e */
if(!s->budget--) { s->failed_pc=0x0c0ad93eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad940;
P_0c0ad940: /* original 220b, guest PC 0x0c0ad940 */
if(!s->budget--) { s->failed_pc=0x0c0ad940u; return 0; }
r[2]|=r[0];
goto P_0c0ad942;
P_0c0ad942: /* original 2e22, guest PC 0x0c0ad942 */
if(!s->budget--) { s->failed_pc=0x0c0ad942u; return 0; }
write(ram,r[14],r[2],4);
goto P_0c0ad944;
P_0c0ad944: /* original 62f2, guest PC 0x0c0ad944 */
if(!s->budget--) { s->failed_pc=0x0c0ad944u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ad946;
P_0c0ad946: /* original f4d8, guest PC 0x0c0ad946 */
if(!s->budget--) { s->failed_pc=0x0c0ad946u; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c0ad948;
P_0c0ad948: /* original f628, guest PC 0x0c0ad948 */
if(!s->budget--) { s->failed_pc=0x0c0ad948u; return 0; }
vf3_matrix_load(s,ram,6,r[2]);
goto P_0c0ad94a;
P_0c0ad94a: /* original 6263, guest PC 0x0c0ad94a */
if(!s->budget--) { s->failed_pc=0x0c0ad94au; return 0; }
r[2]=r[6];
goto P_0c0ad94c;
P_0c0ad94c: /* original f34c, guest PC 0x0c0ad94c */
if(!s->budget--) { s->failed_pc=0x0c0ad94cu; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0ad94e;
P_0c0ad94e: /* original 7215, guest PC 0x0c0ad94e */
if(!s->budget--) { s->failed_pc=0x0c0ad94eu; return 0; }
r[2]+=0x00000015u;
goto P_0c0ad950;
P_0c0ad950: /* original f362, guest PC 0x0c0ad950 */
if(!s->budget--) { s->failed_pc=0x0c0ad950u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0ad952;
P_0c0ad952: /* original f58d, guest PC 0x0c0ad952 */
if(!s->budget--) { s->failed_pc=0x0c0ad952u; return 0; }
fr[5]=0;
goto P_0c0ad954;
P_0c0ad954: /* original f25c, guest PC 0x0c0ad954 */
if(!s->budget--) { s->failed_pc=0x0c0ad954u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0ad956;
P_0c0ad956: /* original 9033, guest PC 0x0c0ad956 */
if(!s->budget--) { s->failed_pc=0x0c0ad956u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9c0u,2);
goto P_0c0ad958;
P_0c0ad958: /* original f34d, guest PC 0x0c0ad958 */
if(!s->budget--) { s->failed_pc=0x0c0ad958u; return 0; }
fr[3]^=0x80000000u;
goto P_0c0ad95a;
P_0c0ad95a: /* original f53c, guest PC 0x0c0ad95a */
if(!s->budget--) { s->failed_pc=0x0c0ad95au; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0ad95c;
P_0c0ad95c: /* original f521, guest PC 0x0c0ad95c */
if(!s->budget--) { s->failed_pc=0x0c0ad95cu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[2],r[18],'-');
goto P_0c0ad95e;
P_0c0ad95e: /* original f457, guest PC 0x0c0ad95e */
if(!s->budget--) { s->failed_pc=0x0c0ad95eu; return 0; }
vf3_matrix_store(s,ram,5,r[4]+r[0]);
goto P_0c0ad960;
P_0c0ad960: /* original f39d, guest PC 0x0c0ad960 */
if(!s->budget--) { s->failed_pc=0x0c0ad960u; return 0; }
fr[3]=0x3f800000u;
goto P_0c0ad962;
P_0c0ad962: /* original f430, guest PC 0x0c0ad962 */
if(!s->budget--) { s->failed_pc=0x0c0ad962u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0ad964;
P_0c0ad964: /* original 902d, guest PC 0x0c0ad964 */
if(!s->budget--) { s->failed_pc=0x0c0ad964u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9c2u,2);
goto P_0c0ad966;
P_0c0ad966: /* original f447, guest PC 0x0c0ad966 */
if(!s->budget--) { s->failed_pc=0x0c0ad966u; return 0; }
vf3_matrix_store(s,ram,4,r[4]+r[0]);
goto P_0c0ad968;
P_0c0ad968: /* original 6120, guest PC 0x0c0ad968 */
if(!s->budget--) { s->failed_pc=0x0c0ad968u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[1]=tmp;
goto P_0c0ad96a;
P_0c0ad96a: /* original 611c, guest PC 0x0c0ad96a */
if(!s->budget--) { s->failed_pc=0x0c0ad96au; return 0; }
r[1]=r[1]&255u;
goto P_0c0ad96c;
P_0c0ad96c: /* original 4128, guest PC 0x0c0ad96c */
if(!s->budget--) { s->failed_pc=0x0c0ad96cu; return 0; }
r[1]<<=16;
goto P_0c0ad96e;
P_0c0ad96e: /* original 4118, guest PC 0x0c0ad96e */
if(!s->budget--) { s->failed_pc=0x0c0ad96eu; return 0; }
r[1]<<=8;
goto P_0c0ad970;
P_0c0ad970: /* original 6263, guest PC 0x0c0ad970 */
if(!s->budget--) { s->failed_pc=0x0c0ad970u; return 0; }
r[2]=r[6];
goto P_0c0ad972;
P_0c0ad972: /* original 7214, guest PC 0x0c0ad972 */
if(!s->budget--) { s->failed_pc=0x0c0ad972u; return 0; }
r[2]+=0x00000014u;
goto P_0c0ad974;
P_0c0ad974: /* original 6020, guest PC 0x0c0ad974 */
if(!s->budget--) { s->failed_pc=0x0c0ad974u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0ad976;
P_0c0ad976: /* original 6263, guest PC 0x0c0ad976 */
if(!s->budget--) { s->failed_pc=0x0c0ad976u; return 0; }
r[2]=r[6];
goto P_0c0ad978;
P_0c0ad978: /* original 21c9, guest PC 0x0c0ad978 */
if(!s->budget--) { s->failed_pc=0x0c0ad978u; return 0; }
r[1]&=r[12];
goto P_0c0ad97a;
P_0c0ad97a: /* original 600c, guest PC 0x0c0ad97a */
if(!s->budget--) { s->failed_pc=0x0c0ad97au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad97c;
P_0c0ad97c: /* original 4028, guest PC 0x0c0ad97c */
if(!s->budget--) { s->failed_pc=0x0c0ad97cu; return 0; }
r[0]<<=16;
goto P_0c0ad97e;
P_0c0ad97e: /* original 20b9, guest PC 0x0c0ad97e */
if(!s->budget--) { s->failed_pc=0x0c0ad97eu; return 0; }
r[0]&=r[11];
goto P_0c0ad980;
P_0c0ad980: /* original 7213, guest PC 0x0c0ad980 */
if(!s->budget--) { s->failed_pc=0x0c0ad980u; return 0; }
r[2]+=0x00000013u;
goto P_0c0ad982;
P_0c0ad982: /* original 210b, guest PC 0x0c0ad982 */
if(!s->budget--) { s->failed_pc=0x0c0ad982u; return 0; }
r[1]|=r[0];
goto P_0c0ad984;
P_0c0ad984: /* original 6020, guest PC 0x0c0ad984 */
if(!s->budget--) { s->failed_pc=0x0c0ad984u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0ad986;
P_0c0ad986: /* original 6263, guest PC 0x0c0ad986 */
if(!s->budget--) { s->failed_pc=0x0c0ad986u; return 0; }
r[2]=r[6];
goto P_0c0ad988;
P_0c0ad988: /* original 7212, guest PC 0x0c0ad988 */
if(!s->budget--) { s->failed_pc=0x0c0ad988u; return 0; }
r[2]+=0x00000012u;
goto P_0c0ad98a;
P_0c0ad98a: /* original 600c, guest PC 0x0c0ad98a */
if(!s->budget--) { s->failed_pc=0x0c0ad98au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad98c;
P_0c0ad98c: /* original 4018, guest PC 0x0c0ad98c */
if(!s->budget--) { s->failed_pc=0x0c0ad98cu; return 0; }
r[0]<<=8;
goto P_0c0ad98e;
P_0c0ad98e: /* original 2079, guest PC 0x0c0ad98e */
if(!s->budget--) { s->failed_pc=0x0c0ad98eu; return 0; }
r[0]&=r[7];
goto P_0c0ad990;
P_0c0ad990: /* original 210b, guest PC 0x0c0ad990 */
if(!s->budget--) { s->failed_pc=0x0c0ad990u; return 0; }
r[1]|=r[0];
goto P_0c0ad992;
P_0c0ad992: /* original 6020, guest PC 0x0c0ad992 */
if(!s->budget--) { s->failed_pc=0x0c0ad992u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[0]=tmp;
goto P_0c0ad994;
P_0c0ad994: /* original 600c, guest PC 0x0c0ad994 */
if(!s->budget--) { s->failed_pc=0x0c0ad994u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ad996;
P_0c0ad996: /* original 210b, guest PC 0x0c0ad996 */
if(!s->budget--) { s->failed_pc=0x0c0ad996u; return 0; }
r[1]|=r[0];
goto P_0c0ad998;
P_0c0ad998: /* original 2e12, guest PC 0x0c0ad998 */
if(!s->budget--) { s->failed_pc=0x0c0ad998u; return 0; }
write(ram,r[14],r[1],4);
goto P_0c0ad99a;
P_0c0ad99a: /* original f2d8, guest PC 0x0c0ad99a */
if(!s->budget--) { s->failed_pc=0x0c0ad99au; return 0; }
vf3_matrix_load(s,ram,2,r[13]);
goto P_0c0ad99c;
P_0c0ad99c: /* original 9012, guest PC 0x0c0ad99c */
if(!s->budget--) { s->failed_pc=0x0c0ad99cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ad9c4u,2);
goto P_0c0ad99e;
P_0c0ad99e: /* original f427, guest PC 0x0c0ad99e */
if(!s->budget--) { s->failed_pc=0x0c0ad99eu; return 0; }
vf3_matrix_store(s,ram,2,r[4]+r[0]);
goto P_0c0ad9a0;
P_0c0ad9a0: /* original bdea, guest PC 0x0c0ad9a0 */
if(!s->budget--) { s->failed_pc=0x0c0ad9a0u; return 0; }
target=0x0c0ad578u; r[16]=0x0c0ad9a4u;
r[6]+=0x00000016u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ad9a4u) { target=s->pc; goto dispatch; }
goto P_0c0ad9a4;
P_0c0ad9a2: /* original 7616, guest PC 0x0c0ad9a2 */
if(!s->budget--) { s->failed_pc=0x0c0ad9a2u; return 0; }
r[6]+=0x00000016u;
goto P_0c0ad9a4;
P_0c0ad9a4: /* original 7f0c, guest PC 0x0c0ad9a4 */
if(!s->budget--) { s->failed_pc=0x0c0ad9a4u; return 0; }
r[15]+=0x0000000cu;
goto P_0c0ad9a6;
P_0c0ad9a6: /* original 4f26, guest PC 0x0c0ad9a6 */
if(!s->budget--) { s->failed_pc=0x0c0ad9a6u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad9a8;
P_0c0ad9a8: /* original 6bf6, guest PC 0x0c0ad9a8 */
if(!s->budget--) { s->failed_pc=0x0c0ad9a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ad9aa;
P_0c0ad9aa: /* original 6cf6, guest PC 0x0c0ad9aa */
if(!s->budget--) { s->failed_pc=0x0c0ad9aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ad9ac;
P_0c0ad9ac: /* original 6df6, guest PC 0x0c0ad9ac */
if(!s->budget--) { s->failed_pc=0x0c0ad9acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ad9ae;
P_0c0ad9ae: /* original 000b, guest PC 0x0c0ad9ae */
if(!s->budget--) { s->failed_pc=0x0c0ad9aeu; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ad9b0: /* original 6ef6, guest PC 0x0c0ad9b0 */
if(!s->budget--) { s->failed_pc=0x0c0ad9b0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ad9b2u,s,ram);
P_0c0ad9fe: /* original 4f22, guest PC 0x0c0ad9fe */
if(!s->budget--) { s->failed_pc=0x0c0ad9feu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ada00;
P_0c0ada00: /* original 600c, guest PC 0x0c0ada00 */
if(!s->budget--) { s->failed_pc=0x0c0ada00u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ada02;
P_0c0ada02: /* original 220b, guest PC 0x0c0ada02 */
if(!s->budget--) { s->failed_pc=0x0c0ada02u; return 0; }
r[2]|=r[0];
goto P_0c0ada04;
P_0c0ada04: /* original 907e, guest PC 0x0c0ada04 */
if(!s->budget--) { s->failed_pc=0x0c0ada04u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb04u,2);
goto P_0c0ada06;
P_0c0ada06: /* original 4f12, guest PC 0x0c0ada06 */
if(!s->budget--) { s->failed_pc=0x0c0ada06u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0ada08;
P_0c0ada08: /* original 0425, guest PC 0x0c0ada08 */
if(!s->budget--) { s->failed_pc=0x0c0ada08u; return 0; }
write(ram,r[4]+r[0],r[2],2);
goto P_0c0ada0a;
P_0c0ada0a: /* original 8469, guest PC 0x0c0ada0a */
if(!s->budget--) { s->failed_pc=0x0c0ada0au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0ada0c;
P_0c0ada0c: /* original d243, guest PC 0x0c0ada0c */
if(!s->budget--) { s->failed_pc=0x0c0ada0cu; return 0; }
r[2]=read(ram,0x0c0adb1cu,4);
goto P_0c0ada0e;
P_0c0ada0e: /* original 600c, guest PC 0x0c0ada0e */
if(!s->budget--) { s->failed_pc=0x0c0ada0eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ada10;
P_0c0ada10: /* original 4028, guest PC 0x0c0ada10 */
if(!s->budget--) { s->failed_pc=0x0c0ada10u; return 0; }
r[0]<<=16;
goto P_0c0ada12;
P_0c0ada12: /* original 4018, guest PC 0x0c0ada12 */
if(!s->budget--) { s->failed_pc=0x0c0ada12u; return 0; }
r[0]<<=8;
goto P_0c0ada14;
P_0c0ada14: /* original 2029, guest PC 0x0c0ada14 */
if(!s->budget--) { s->failed_pc=0x0c0ada14u; return 0; }
r[0]&=r[2];
goto P_0c0ada16;
P_0c0ada16: /* original 6303, guest PC 0x0c0ada16 */
if(!s->budget--) { s->failed_pc=0x0c0ada16u; return 0; }
r[3]=r[0];
goto P_0c0ada18;
P_0c0ada18: /* original 8468, guest PC 0x0c0ada18 */
if(!s->budget--) { s->failed_pc=0x0c0ada18u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0ada1a;
P_0c0ada1a: /* original 4229, guest PC 0x0c0ada1a */
if(!s->budget--) { s->failed_pc=0x0c0ada1au; return 0; }
r[2]>>=16;
goto P_0c0ada1c;
P_0c0ada1c: /* original d140, guest PC 0x0c0ada1c */
if(!s->budget--) { s->failed_pc=0x0c0ada1cu; return 0; }
r[1]=read(ram,0x0c0adb20u,4);
goto P_0c0ada1e;
P_0c0ada1e: /* original 600c, guest PC 0x0c0ada1e */
if(!s->budget--) { s->failed_pc=0x0c0ada1eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ada20;
P_0c0ada20: /* original 4028, guest PC 0x0c0ada20 */
if(!s->budget--) { s->failed_pc=0x0c0ada20u; return 0; }
r[0]<<=16;
goto P_0c0ada22;
P_0c0ada22: /* original 2019, guest PC 0x0c0ada22 */
if(!s->budget--) { s->failed_pc=0x0c0ada22u; return 0; }
r[0]&=r[1];
goto P_0c0ada24;
P_0c0ada24: /* original 230b, guest PC 0x0c0ada24 */
if(!s->budget--) { s->failed_pc=0x0c0ada24u; return 0; }
r[3]|=r[0];
goto P_0c0ada26;
P_0c0ada26: /* original 8467, guest PC 0x0c0ada26 */
if(!s->budget--) { s->failed_pc=0x0c0ada26u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0ada28;
P_0c0ada28: /* original 600c, guest PC 0x0c0ada28 */
if(!s->budget--) { s->failed_pc=0x0c0ada28u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ada2a;
P_0c0ada2a: /* original 4018, guest PC 0x0c0ada2a */
if(!s->budget--) { s->failed_pc=0x0c0ada2au; return 0; }
r[0]<<=8;
goto P_0c0ada2c;
P_0c0ada2c: /* original 2029, guest PC 0x0c0ada2c */
if(!s->budget--) { s->failed_pc=0x0c0ada2cu; return 0; }
r[0]&=r[2];
goto P_0c0ada2e;
P_0c0ada2e: /* original 230b, guest PC 0x0c0ada2e */
if(!s->budget--) { s->failed_pc=0x0c0ada2eu; return 0; }
r[3]|=r[0];
goto P_0c0ada30;
P_0c0ada30: /* original 8466, guest PC 0x0c0ada30 */
if(!s->budget--) { s->failed_pc=0x0c0ada30u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0ada32;
P_0c0ada32: /* original 600c, guest PC 0x0c0ada32 */
if(!s->budget--) { s->failed_pc=0x0c0ada32u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ada34;
P_0c0ada34: /* original 230b, guest PC 0x0c0ada34 */
if(!s->budget--) { s->failed_pc=0x0c0ada34u; return 0; }
r[3]|=r[0];
goto P_0c0ada36;
P_0c0ada36: /* original 9066, guest PC 0x0c0ada36 */
if(!s->budget--) { s->failed_pc=0x0c0ada36u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb06u,2);
goto P_0c0ada38;
P_0c0ada38: /* original 0436, guest PC 0x0c0ada38 */
if(!s->budget--) { s->failed_pc=0x0c0ada38u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0ada3a;
P_0c0ada3a: /* original 9265, guest PC 0x0c0ada3a */
if(!s->budget--) { s->failed_pc=0x0c0ada3au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb08u,2);
goto P_0c0ada3c;
P_0c0ada3c: /* original 846a, guest PC 0x0c0ada3c */
if(!s->budget--) { s->failed_pc=0x0c0ada3cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0ada3e;
P_0c0ada3e: /* original 324c, guest PC 0x0c0ada3e */
if(!s->budget--) { s->failed_pc=0x0c0ada3eu; return 0; }
r[2]+=r[4];
goto P_0c0ada40;
P_0c0ada40: /* original 2200, guest PC 0x0c0ada40 */
if(!s->budget--) { s->failed_pc=0x0c0ada40u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0ada42;
P_0c0ada42: /* original 9362, guest PC 0x0c0ada42 */
if(!s->budget--) { s->failed_pc=0x0c0ada42u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb0au,2);
goto P_0c0ada44;
P_0c0ada44: /* original 846b, guest PC 0x0c0ada44 */
if(!s->budget--) { s->failed_pc=0x0c0ada44u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0ada46;
P_0c0ada46: /* original 334c, guest PC 0x0c0ada46 */
if(!s->budget--) { s->failed_pc=0x0c0ada46u; return 0; }
r[3]+=r[4];
goto P_0c0ada48;
P_0c0ada48: /* original 2300, guest PC 0x0c0ada48 */
if(!s->budget--) { s->failed_pc=0x0c0ada48u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c0ada4a;
P_0c0ada4a: /* original 925f, guest PC 0x0c0ada4a */
if(!s->budget--) { s->failed_pc=0x0c0ada4au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb0cu,2);
goto P_0c0ada4c;
P_0c0ada4c: /* original 846c, guest PC 0x0c0ada4c */
if(!s->budget--) { s->failed_pc=0x0c0ada4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0ada4e;
P_0c0ada4e: /* original 324c, guest PC 0x0c0ada4e */
if(!s->budget--) { s->failed_pc=0x0c0ada4eu; return 0; }
r[2]+=r[4];
goto P_0c0ada50;
P_0c0ada50: /* original 2200, guest PC 0x0c0ada50 */
if(!s->budget--) { s->failed_pc=0x0c0ada50u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0ada52;
P_0c0ada52: /* original 935c, guest PC 0x0c0ada52 */
if(!s->budget--) { s->failed_pc=0x0c0ada52u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb0eu,2);
goto P_0c0ada54;
P_0c0ada54: /* original 846d, guest PC 0x0c0ada54 */
if(!s->budget--) { s->failed_pc=0x0c0ada54u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0ada56;
P_0c0ada56: /* original 334c, guest PC 0x0c0ada56 */
if(!s->budget--) { s->failed_pc=0x0c0ada56u; return 0; }
r[3]+=r[4];
goto P_0c0ada58;
P_0c0ada58: /* original 2300, guest PC 0x0c0ada58 */
if(!s->budget--) { s->failed_pc=0x0c0ada58u; return 0; }
write(ram,r[3],r[0],1);
goto P_0c0ada5a;
P_0c0ada5a: /* original 9259, guest PC 0x0c0ada5a */
if(!s->budget--) { s->failed_pc=0x0c0ada5au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb10u,2);
goto P_0c0ada5c;
P_0c0ada5c: /* original 846e, guest PC 0x0c0ada5c */
if(!s->budget--) { s->failed_pc=0x0c0ada5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0ada5e;
P_0c0ada5e: /* original 324c, guest PC 0x0c0ada5e */
if(!s->budget--) { s->failed_pc=0x0c0ada5eu; return 0; }
r[2]+=r[4];
goto P_0c0ada60;
P_0c0ada60: /* original 2200, guest PC 0x0c0ada60 */
if(!s->budget--) { s->failed_pc=0x0c0ada60u; return 0; }
write(ram,r[2],r[0],1);
goto P_0c0ada62;
P_0c0ada62: /* original 9056, guest PC 0x0c0ada62 */
if(!s->budget--) { s->failed_pc=0x0c0ada62u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb12u,2);
goto P_0c0ada64;
P_0c0ada64: /* original 074c, guest PC 0x0c0ada64 */
if(!s->budget--) { s->failed_pc=0x0c0ada64u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ada66;
P_0c0ada66: /* original 7066, guest PC 0x0c0ada66 */
if(!s->budget--) { s->failed_pc=0x0c0ada66u; return 0; }
r[0]+=0x00000066u;
goto P_0c0ada68;
P_0c0ada68: /* original 034c, guest PC 0x0c0ada68 */
if(!s->budget--) { s->failed_pc=0x0c0ada68u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ada6a;
P_0c0ada6a: /* original e064, guest PC 0x0c0ada6a */
if(!s->budget--) { s->failed_pc=0x0c0ada6au; return 0; }
r[0]=0x00000064u;
goto P_0c0ada6c;
P_0c0ada6c: /* original 677c, guest PC 0x0c0ada6c */
if(!s->budget--) { s->failed_pc=0x0c0ada6cu; return 0; }
r[7]=r[7]&255u;
goto P_0c0ada6e;
P_0c0ada6e: /* original 633c, guest PC 0x0c0ada6e */
if(!s->budget--) { s->failed_pc=0x0c0ada6eu; return 0; }
r[3]=r[3]&255u;
goto P_0c0ada70;
P_0c0ada70: /* original 7764, guest PC 0x0c0ada70 */
if(!s->budget--) { s->failed_pc=0x0c0ada70u; return 0; }
r[7]+=0x00000064u;
goto P_0c0ada72;
P_0c0ada72: /* original 0737, guest PC 0x0c0ada72 */
if(!s->budget--) { s->failed_pc=0x0c0ada72u; return 0; }
r[19]=r[7]*r[3];
goto P_0c0ada74;
P_0c0ada74: /* original d32b, guest PC 0x0c0ada74 */
if(!s->budget--) { s->failed_pc=0x0c0ada74u; return 0; }
r[3]=read(ram,0x0c0adb24u,4);
goto P_0c0ada76;
P_0c0ada76: /* original 071a, guest PC 0x0c0ada76 */
if(!s->budget--) { s->failed_pc=0x0c0ada76u; return 0; }
r[7]=r[19];
goto P_0c0ada78;
P_0c0ada78: /* original 430b, guest PC 0x0c0ada78 */
if(!s->budget--) { s->failed_pc=0x0c0ada78u; return 0; }
target=r[3];
r[16]=0x0c0ada7cu;
r[1]=r[7];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ada7cu) { target=s->pc; goto dispatch; }
goto P_0c0ada7c;
P_0c0ada7a: /* original 6173, guest PC 0x0c0ada7a */
if(!s->budget--) { s->failed_pc=0x0c0ada7au; return 0; }
r[1]=r[7];
goto P_0c0ada7c;
P_0c0ada7c: /* original 6703, guest PC 0x0c0ada7c */
if(!s->budget--) { s->failed_pc=0x0c0ada7cu; return 0; }
r[7]=r[0];
goto P_0c0ada7e;
P_0c0ada7e: /* original 9049, guest PC 0x0c0ada7e */
if(!s->budget--) { s->failed_pc=0x0c0ada7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb14u,2);
goto P_0c0ada80;
P_0c0ada80: /* original 0474, guest PC 0x0c0ada80 */
if(!s->budget--) { s->failed_pc=0x0c0ada80u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0ada82;
P_0c0ada82: /* original 70ff, guest PC 0x0c0ada82 */
if(!s->budget--) { s->failed_pc=0x0c0ada82u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0ada84;
P_0c0ada84: /* original 004c, guest PC 0x0c0ada84 */
if(!s->budget--) { s->failed_pc=0x0c0ada84u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ada86;
P_0c0ada86: /* original 600c, guest PC 0x0c0ada86 */
if(!s->budget--) { s->failed_pc=0x0c0ada86u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ada88;
P_0c0ada88: /* original 8804, guest PC 0x0c0ada88 */
if(!s->budget--) { s->failed_pc=0x0c0ada88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0ada8a;
P_0c0ada8a: /* original 8b62, guest PC 0x0c0ada8a */
if(!s->budget--) { s->failed_pc=0x0c0ada8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0adb52; }
goto P_0c0ada8c;
P_0c0ada8c: /* original 9043, guest PC 0x0c0ada8c */
if(!s->budget--) { s->failed_pc=0x0c0ada8cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb16u,2);
goto P_0c0ada8e;
P_0c0ada8e: /* original d326, guest PC 0x0c0ada8e */
if(!s->budget--) { s->failed_pc=0x0c0ada8eu; return 0; }
r[3]=read(ram,0x0c0adb28u,4);
goto P_0c0ada90;
P_0c0ada90: /* original 024e, guest PC 0x0c0ada90 */
if(!s->budget--) { s->failed_pc=0x0c0ada90u; return 0; }
r[2]=read(ram,r[4]+r[0],4);
goto P_0c0ada92;
P_0c0ada92: /* original 2238, guest PC 0x0c0ada92 */
if(!s->budget--) { s->failed_pc=0x0c0ada92u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0ada94;
P_0c0ada94: /* original 895d, guest PC 0x0c0ada94 */
if(!s->budget--) { s->failed_pc=0x0c0ada94u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adb52; }
goto P_0c0ada96;
P_0c0ada96: /* original 903d, guest PC 0x0c0ada96 */
if(!s->budget--) { s->failed_pc=0x0c0ada96u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb14u,2);
goto P_0c0ada98;
P_0c0ada98: /* original f38d, guest PC 0x0c0ada98 */
if(!s->budget--) { s->failed_pc=0x0c0ada98u; return 0; }
fr[3]=0;
goto P_0c0ada9a;
P_0c0ada9a: /* original 074c, guest PC 0x0c0ada9a */
if(!s->budget--) { s->failed_pc=0x0c0ada9au; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0ada9c;
P_0c0ada9c: /* original 903c, guest PC 0x0c0ada9c */
if(!s->budget--) { s->failed_pc=0x0c0ada9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adb18u,2);
goto P_0c0ada9e;
P_0c0ada9e: /* original f756, guest PC 0x0c0ada9e */
if(!s->budget--) { s->failed_pc=0x0c0ada9eu; return 0; }
vf3_matrix_load(s,ram,7,r[5]+r[0]);
goto P_0c0adaa0;
P_0c0adaa0: /* original f446, guest PC 0x0c0adaa0 */
if(!s->budget--) { s->failed_pc=0x0c0adaa0u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0adaa2;
P_0c0adaa2: /* original c722, guest PC 0x0c0adaa2 */
if(!s->budget--) { s->failed_pc=0x0c0adaa2u; return 0; }
r[0]=0x0c0adb2cu;
goto P_0c0adaa4;
P_0c0adaa4: /* original f608, guest PC 0x0c0adaa4 */
if(!s->budget--) { s->failed_pc=0x0c0adaa4u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0adaa6;
P_0c0adaa6: /* original c722, guest PC 0x0c0adaa6 */
if(!s->budget--) { s->failed_pc=0x0c0adaa6u; return 0; }
r[0]=0x0c0adb30u;
goto P_0c0adaa8;
P_0c0adaa8: /* original f471, guest PC 0x0c0adaa8 */
if(!s->budget--) { s->failed_pc=0x0c0adaa8u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[7],r[18],'-');
goto P_0c0adaaa;
P_0c0adaaa: /* original f508, guest PC 0x0c0adaaa */
if(!s->budget--) { s->failed_pc=0x0c0adaaau; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0adaac;
P_0c0adaac: /* original c721, guest PC 0x0c0adaac */
if(!s->budget--) { s->failed_pc=0x0c0adaacu; return 0; }
r[0]=0x0c0adb34u;
goto P_0c0adaae;
P_0c0adaae: /* original f708, guest PC 0x0c0adaae */
if(!s->budget--) { s->failed_pc=0x0c0adaaeu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0adab0;
P_0c0adab0: /* original f84c, guest PC 0x0c0adab0 */
if(!s->budget--) { s->failed_pc=0x0c0adab0u; return 0; }
vf3_matrix_move(s,8,4);
goto P_0c0adab2;
P_0c0adab2: /* original f871, guest PC 0x0c0adab2 */
if(!s->budget--) { s->failed_pc=0x0c0adab2u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[7],r[18],'-');
goto P_0c0adab4;
P_0c0adab4: /* original f385, guest PC 0x0c0adab4 */
if(!s->budget--) { s->failed_pc=0x0c0adab4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[8]))!=0);
goto P_0c0adab6;
P_0c0adab6: /* original 8f01, guest PC 0x0c0adab6 */
if(!s->budget--) { s->failed_pc=0x0c0adab6u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(!cond) { goto P_0c0adabc; }
goto P_0c0adaba;
P_0c0adab8: /* original 677c, guest PC 0x0c0adab8 */
if(!s->budget--) { s->failed_pc=0x0c0adab8u; return 0; }
r[7]=r[7]&255u;
goto P_0c0adaba;
P_0c0adaba: /* original f47c, guest PC 0x0c0adaba */
if(!s->budget--) { s->failed_pc=0x0c0adabau; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0adabc;
P_0c0adabc: /* original f74c, guest PC 0x0c0adabc */
if(!s->budget--) { s->failed_pc=0x0c0adabcu; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0adabe;
P_0c0adabe: /* original f751, guest PC 0x0c0adabe */
if(!s->budget--) { s->failed_pc=0x0c0adabeu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[5],r[18],'-');
goto P_0c0adac0;
P_0c0adac0: /* original f38d, guest PC 0x0c0adac0 */
if(!s->budget--) { s->failed_pc=0x0c0adac0u; return 0; }
fr[3]=0;
goto P_0c0adac2;
P_0c0adac2: /* original f375, guest PC 0x0c0adac2 */
if(!s->budget--) { s->failed_pc=0x0c0adac2u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[7]))!=0);
goto P_0c0adac4;
P_0c0adac4: /* original 8900, guest PC 0x0c0adac4 */
if(!s->budget--) { s->failed_pc=0x0c0adac4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adac8; }
goto P_0c0adac6;
P_0c0adac6: /* original f45c, guest PC 0x0c0adac6 */
if(!s->budget--) { s->failed_pc=0x0c0adac6u; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0adac8;
P_0c0adac8: /* original 475a, guest PC 0x0c0adac8 */
if(!s->budget--) { s->failed_pc=0x0c0adac8u; return 0; }
r[53]=r[7];
goto P_0c0adaca;
P_0c0adaca: /* original c71b, guest PC 0x0c0adaca */
if(!s->budget--) { s->failed_pc=0x0c0adacau; return 0; }
r[0]=0x0c0adb38u;
goto P_0c0adacc;
P_0c0adacc: /* original f508, guest PC 0x0c0adacc */
if(!s->budget--) { s->failed_pc=0x0c0adaccu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0adace;
P_0c0adace: /* original f28d, guest PC 0x0c0adace */
if(!s->budget--) { s->failed_pc=0x0c0adaceu; return 0; }
fr[2]=0;
goto P_0c0adad0;
P_0c0adad0: /* original f32d, guest PC 0x0c0adad0 */
if(!s->budget--) { s->failed_pc=0x0c0adad0u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0adad2;
P_0c0adad2: /* original f05c, guest PC 0x0c0adad2 */
if(!s->budget--) { s->failed_pc=0x0c0adad2u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0adad4;
P_0c0adad4: /* original f64e, guest PC 0x0c0adad4 */
if(!s->budget--) { s->failed_pc=0x0c0adad4u; return 0; }
fr[6]=vf3_fpu_mac(fr[0],fr[4],fr[6],r[18]);
goto P_0c0adad6;
P_0c0adad6: /* original f235, guest PC 0x0c0adad6 */
if(!s->budget--) { s->failed_pc=0x0c0adad6u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[3]))!=0);
goto P_0c0adad8;
P_0c0adad8: /* original f46c, guest PC 0x0c0adad8 */
if(!s->budget--) { s->failed_pc=0x0c0adad8u; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0adada;
P_0c0adada: /* original 8f03, guest PC 0x0c0adada */
if(!s->budget--) { s->failed_pc=0x0c0adadau; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,3);
if(!cond) { goto P_0c0adae4; }
goto P_0c0adade;
P_0c0adadc: /* original f53c, guest PC 0x0c0adadc */
if(!s->budget--) { s->failed_pc=0x0c0adadcu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0adade;
P_0c0adade: /* original c717, guest PC 0x0c0adade */
if(!s->budget--) { s->failed_pc=0x0c0adadeu; return 0; }
r[0]=0x0c0adb3cu;
goto P_0c0adae0;
P_0c0adae0: /* original f308, guest PC 0x0c0adae0 */
if(!s->budget--) { s->failed_pc=0x0c0adae0u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0adae2;
P_0c0adae2: /* original f530, guest PC 0x0c0adae2 */
if(!s->budget--) { s->failed_pc=0x0c0adae2u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0adae4;
P_0c0adae4: /* original f452, guest PC 0x0c0adae4 */
if(!s->budget--) { s->failed_pc=0x0c0adae4u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0adae6;
P_0c0adae6: /* original c716, guest PC 0x0c0adae6 */
if(!s->budget--) { s->failed_pc=0x0c0adae6u; return 0; }
r[0]=0x0c0adb40u;
goto P_0c0adae8;
P_0c0adae8: /* original f208, guest PC 0x0c0adae8 */
if(!s->budget--) { s->failed_pc=0x0c0adae8u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0adaea;
P_0c0adaea: /* original f425, guest PC 0x0c0adaea */
if(!s->budget--) { s->failed_pc=0x0c0adaeau; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[2]))!=0);
goto P_0c0adaec;
P_0c0adaec: /* original 8f2c, guest PC 0x0c0adaec */
if(!s->budget--) { s->failed_pc=0x0c0adaecu; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,5,4);
if(!cond) { goto P_0c0adb48; }
goto P_0c0adaf0;
P_0c0adaee: /* original f54c, guest PC 0x0c0adaee */
if(!s->budget--) { s->failed_pc=0x0c0adaeeu; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0adaf0;
P_0c0adaf0: /* original c714, guest PC 0x0c0adaf0 */
if(!s->budget--) { s->failed_pc=0x0c0adaf0u; return 0; }
r[0]=0x0c0adb44u;
goto P_0c0adaf2;
P_0c0adaf2: /* original f25c, guest PC 0x0c0adaf2 */
if(!s->budget--) { s->failed_pc=0x0c0adaf2u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0adaf4;
P_0c0adaf4: /* original f308, guest PC 0x0c0adaf4 */
if(!s->budget--) { s->failed_pc=0x0c0adaf4u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0adaf6;
P_0c0adaf6: /* original f230, guest PC 0x0c0adaf6 */
if(!s->budget--) { s->failed_pc=0x0c0adaf6u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'+');
goto P_0c0adaf8;
P_0c0adaf8: /* original a027, guest PC 0x0c0adaf8 */
if(!s->budget--) { s->failed_pc=0x0c0adaf8u; return 0; }
vf3_matrix_move(s,3,2);
goto P_0c0adb4a;
P_0c0adafa: /* original f32c, guest PC 0x0c0adafa */
if(!s->budget--) { s->failed_pc=0x0c0adafau; return 0; }
vf3_matrix_move(s,3,2);
return vf3_matrix_family(0x0c0adafcu,s,ram);
P_0c0adb48: /* original f35c, guest PC 0x0c0adb48 */
if(!s->budget--) { s->failed_pc=0x0c0adb48u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0adb4a;
P_0c0adb4a: /* original f33d, guest PC 0x0c0adb4a */
if(!s->budget--) { s->failed_pc=0x0c0adb4au; return 0; }
r[53]=truncate_float(fr[3]);
goto P_0c0adb4c;
P_0c0adb4c: /* original 907c, guest PC 0x0c0adb4c */
if(!s->budget--) { s->failed_pc=0x0c0adb4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc48u,2);
goto P_0c0adb4e;
P_0c0adb4e: /* original 075a, guest PC 0x0c0adb4e */
if(!s->budget--) { s->failed_pc=0x0c0adb4eu; return 0; }
r[7]=r[53];
goto P_0c0adb50;
P_0c0adb50: /* original 0474, guest PC 0x0c0adb50 */
if(!s->budget--) { s->failed_pc=0x0c0adb50u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0adb52;
P_0c0adb52: /* original 907a, guest PC 0x0c0adb52 */
if(!s->budget--) { s->failed_pc=0x0c0adb52u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc4au,2);
goto P_0c0adb54;
P_0c0adb54: /* original 034e, guest PC 0x0c0adb54 */
if(!s->budget--) { s->failed_pc=0x0c0adb54u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0adb56;
P_0c0adb56: /* original 7301, guest PC 0x0c0adb56 */
if(!s->budget--) { s->failed_pc=0x0c0adb56u; return 0; }
r[3]+=0x00000001u;
goto P_0c0adb58;
P_0c0adb58: /* original 0436, guest PC 0x0c0adb58 */
if(!s->budget--) { s->failed_pc=0x0c0adb58u; return 0; }
write(ram,r[4]+r[0],r[3],4);
goto P_0c0adb5a;
P_0c0adb5a: /* original 6242, guest PC 0x0c0adb5a */
if(!s->budget--) { s->failed_pc=0x0c0adb5au; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0adb5c;
P_0c0adb5c: /* original d340, guest PC 0x0c0adb5c */
if(!s->budget--) { s->failed_pc=0x0c0adb5cu; return 0; }
r[3]=read(ram,0x0c0adc60u,4);
goto P_0c0adb5e;
P_0c0adb5e: /* original 2238, guest PC 0x0c0adb5e */
if(!s->budget--) { s->failed_pc=0x0c0adb5eu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0adb60;
P_0c0adb60: /* original 8d07, guest PC 0x0c0adb60 */
if(!s->budget--) { s->failed_pc=0x0c0adb60u; return 0; }
cond=r[17]&1u;
r[6]+=0x0000000fu;
if(cond) { goto P_0c0adb72; }
goto P_0c0adb64;
P_0c0adb62: /* original 760f, guest PC 0x0c0adb62 */
if(!s->budget--) { s->failed_pc=0x0c0adb62u; return 0; }
r[6]+=0x0000000fu;
goto P_0c0adb64;
P_0c0adb64: /* original 9072, guest PC 0x0c0adb64 */
if(!s->budget--) { s->failed_pc=0x0c0adb64u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc4cu,2);
goto P_0c0adb66;
P_0c0adb66: /* original 014c, guest PC 0x0c0adb66 */
if(!s->budget--) { s->failed_pc=0x0c0adb66u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0adb68;
P_0c0adb68: /* original d03e, guest PC 0x0c0adb68 */
if(!s->budget--) { s->failed_pc=0x0c0adb68u; return 0; }
r[0]=read(ram,0x0c0adc64u,4);
goto P_0c0adb6a;
P_0c0adb6a: /* original 611c, guest PC 0x0c0adb6a */
if(!s->budget--) { s->failed_pc=0x0c0adb6au; return 0; }
r[1]=r[1]&255u;
goto P_0c0adb6c;
P_0c0adb6c: /* original 031c, guest PC 0x0c0adb6c */
if(!s->budget--) { s->failed_pc=0x0c0adb6cu; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0adb6e;
P_0c0adb6e: /* original 906d, guest PC 0x0c0adb6e */
if(!s->budget--) { s->failed_pc=0x0c0adb6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adc4cu,2);
goto P_0c0adb70;
P_0c0adb70: /* original 0434, guest PC 0x0c0adb70 */
if(!s->budget--) { s->failed_pc=0x0c0adb70u; return 0; }
write(ram,r[4]+r[0],r[3],1);
goto P_0c0adb72;
P_0c0adb72: /* original 4f16, guest PC 0x0c0adb72 */
if(!s->budget--) { s->failed_pc=0x0c0adb72u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0adb74;
P_0c0adb74: /* original ad00, guest PC 0x0c0adb74 */
if(!s->budget--) { s->failed_pc=0x0c0adb74u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ad578;
P_0c0adb76: /* original 4f26, guest PC 0x0c0adb76 */
if(!s->budget--) { s->failed_pc=0x0c0adb76u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
return vf3_matrix_family(0x0c0adb78u,s,ram);
P_0c0ade24: /* original 2fe6, guest PC 0x0c0ade24 */
if(!s->budget--) { s->failed_pc=0x0c0ade24u; return 0; }
r[15]-=4; write(ram,r[15],r[14],4);
goto P_0c0ade26;
P_0c0ade26: /* original 2fd6, guest PC 0x0c0ade26 */
if(!s->budget--) { s->failed_pc=0x0c0ade26u; return 0; }
r[15]-=4; write(ram,r[15],r[13],4);
goto P_0c0ade28;
P_0c0ade28: /* original 8464, guest PC 0x0c0ade28 */
if(!s->budget--) { s->failed_pc=0x0c0ade28u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+4,1);
goto P_0c0ade2a;
P_0c0ade2a: /* original d141, guest PC 0x0c0ade2a */
if(!s->budget--) { s->failed_pc=0x0c0ade2au; return 0; }
r[1]=read(ram,0x0c0adf30u,4);
goto P_0c0ade2c;
P_0c0ade2c: /* original 600c, guest PC 0x0c0ade2c */
if(!s->budget--) { s->failed_pc=0x0c0ade2cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade2e;
P_0c0ade2e: /* original d23f, guest PC 0x0c0ade2e */
if(!s->budget--) { s->failed_pc=0x0c0ade2eu; return 0; }
r[2]=read(ram,0x0c0adf2cu,4);
goto P_0c0ade30;
P_0c0ade30: /* original 4028, guest PC 0x0c0ade30 */
if(!s->budget--) { s->failed_pc=0x0c0ade30u; return 0; }
r[0]<<=16;
goto P_0c0ade32;
P_0c0ade32: /* original dd40, guest PC 0x0c0ade32 */
if(!s->budget--) { s->failed_pc=0x0c0ade32u; return 0; }
r[13]=read(ram,0x0c0adf34u,4);
goto P_0c0ade34;
P_0c0ade34: /* original 4018, guest PC 0x0c0ade34 */
if(!s->budget--) { s->failed_pc=0x0c0ade34u; return 0; }
r[0]<<=8;
goto P_0c0ade36;
P_0c0ade36: /* original 2019, guest PC 0x0c0ade36 */
if(!s->budget--) { s->failed_pc=0x0c0ade36u; return 0; }
r[0]&=r[1];
goto P_0c0ade38;
P_0c0ade38: /* original 6303, guest PC 0x0c0ade38 */
if(!s->budget--) { s->failed_pc=0x0c0ade38u; return 0; }
r[3]=r[0];
goto P_0c0ade3a;
P_0c0ade3a: /* original 8463, guest PC 0x0c0ade3a */
if(!s->budget--) { s->failed_pc=0x0c0ade3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+3,1);
goto P_0c0ade3c;
P_0c0ade3c: /* original 4f22, guest PC 0x0c0ade3c */
if(!s->budget--) { s->failed_pc=0x0c0ade3cu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ade3e;
P_0c0ade3e: /* original 600c, guest PC 0x0c0ade3e */
if(!s->budget--) { s->failed_pc=0x0c0ade3eu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade40;
P_0c0ade40: /* original 4028, guest PC 0x0c0ade40 */
if(!s->budget--) { s->failed_pc=0x0c0ade40u; return 0; }
r[0]<<=16;
goto P_0c0ade42;
P_0c0ade42: /* original 2029, guest PC 0x0c0ade42 */
if(!s->budget--) { s->failed_pc=0x0c0ade42u; return 0; }
r[0]&=r[2];
goto P_0c0ade44;
P_0c0ade44: /* original 230b, guest PC 0x0c0ade44 */
if(!s->budget--) { s->failed_pc=0x0c0ade44u; return 0; }
r[3]|=r[0];
goto P_0c0ade46;
P_0c0ade46: /* original 8462, guest PC 0x0c0ade46 */
if(!s->budget--) { s->failed_pc=0x0c0ade46u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+2,1);
goto P_0c0ade48;
P_0c0ade48: /* original 7ff0, guest PC 0x0c0ade48 */
if(!s->budget--) { s->failed_pc=0x0c0ade48u; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ade4a;
P_0c0ade4a: /* original 600c, guest PC 0x0c0ade4a */
if(!s->budget--) { s->failed_pc=0x0c0ade4au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade4c;
P_0c0ade4c: /* original 67f3, guest PC 0x0c0ade4c */
if(!s->budget--) { s->failed_pc=0x0c0ade4cu; return 0; }
r[7]=r[15];
goto P_0c0ade4e;
P_0c0ade4e: /* original 4018, guest PC 0x0c0ade4e */
if(!s->budget--) { s->failed_pc=0x0c0ade4eu; return 0; }
r[0]<<=8;
goto P_0c0ade50;
P_0c0ade50: /* original 6ef3, guest PC 0x0c0ade50 */
if(!s->budget--) { s->failed_pc=0x0c0ade50u; return 0; }
r[14]=r[15];
goto P_0c0ade52;
P_0c0ade52: /* original 20d9, guest PC 0x0c0ade52 */
if(!s->budget--) { s->failed_pc=0x0c0ade52u; return 0; }
r[0]&=r[13];
goto P_0c0ade54;
P_0c0ade54: /* original 230b, guest PC 0x0c0ade54 */
if(!s->budget--) { s->failed_pc=0x0c0ade54u; return 0; }
r[3]|=r[0];
goto P_0c0ade56;
P_0c0ade56: /* original 8461, guest PC 0x0c0ade56 */
if(!s->budget--) { s->failed_pc=0x0c0ade56u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+1,1);
goto P_0c0ade58;
P_0c0ade58: /* original 7704, guest PC 0x0c0ade58 */
if(!s->budget--) { s->failed_pc=0x0c0ade58u; return 0; }
r[7]+=0x00000004u;
goto P_0c0ade5a;
P_0c0ade5a: /* original 600c, guest PC 0x0c0ade5a */
if(!s->budget--) { s->failed_pc=0x0c0ade5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade5c;
P_0c0ade5c: /* original 230b, guest PC 0x0c0ade5c */
if(!s->budget--) { s->failed_pc=0x0c0ade5cu; return 0; }
r[3]|=r[0];
goto P_0c0ade5e;
P_0c0ade5e: /* original 2732, guest PC 0x0c0ade5e */
if(!s->budget--) { s->failed_pc=0x0c0ade5eu; return 0; }
write(ram,r[7],r[3],4);
goto P_0c0ade60;
P_0c0ade60: /* original 7e04, guest PC 0x0c0ade60 */
if(!s->budget--) { s->failed_pc=0x0c0ade60u; return 0; }
r[14]+=0x00000004u;
goto P_0c0ade62;
P_0c0ade62: /* original 8469, guest PC 0x0c0ade62 */
if(!s->budget--) { s->failed_pc=0x0c0ade62u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+9,1);
goto P_0c0ade64;
P_0c0ade64: /* original 600c, guest PC 0x0c0ade64 */
if(!s->budget--) { s->failed_pc=0x0c0ade64u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade66;
P_0c0ade66: /* original 4028, guest PC 0x0c0ade66 */
if(!s->budget--) { s->failed_pc=0x0c0ade66u; return 0; }
r[0]<<=16;
goto P_0c0ade68;
P_0c0ade68: /* original 4018, guest PC 0x0c0ade68 */
if(!s->budget--) { s->failed_pc=0x0c0ade68u; return 0; }
r[0]<<=8;
goto P_0c0ade6a;
P_0c0ade6a: /* original 2019, guest PC 0x0c0ade6a */
if(!s->budget--) { s->failed_pc=0x0c0ade6au; return 0; }
r[0]&=r[1];
goto P_0c0ade6c;
P_0c0ade6c: /* original 6303, guest PC 0x0c0ade6c */
if(!s->budget--) { s->failed_pc=0x0c0ade6cu; return 0; }
r[3]=r[0];
goto P_0c0ade6e;
P_0c0ade6e: /* original 8468, guest PC 0x0c0ade6e */
if(!s->budget--) { s->failed_pc=0x0c0ade6eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+8,1);
goto P_0c0ade70;
P_0c0ade70: /* original 600c, guest PC 0x0c0ade70 */
if(!s->budget--) { s->failed_pc=0x0c0ade70u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade72;
P_0c0ade72: /* original 4028, guest PC 0x0c0ade72 */
if(!s->budget--) { s->failed_pc=0x0c0ade72u; return 0; }
r[0]<<=16;
goto P_0c0ade74;
P_0c0ade74: /* original 2029, guest PC 0x0c0ade74 */
if(!s->budget--) { s->failed_pc=0x0c0ade74u; return 0; }
r[0]&=r[2];
goto P_0c0ade76;
P_0c0ade76: /* original 230b, guest PC 0x0c0ade76 */
if(!s->budget--) { s->failed_pc=0x0c0ade76u; return 0; }
r[3]|=r[0];
goto P_0c0ade78;
P_0c0ade78: /* original 8467, guest PC 0x0c0ade78 */
if(!s->budget--) { s->failed_pc=0x0c0ade78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+7,1);
goto P_0c0ade7a;
P_0c0ade7a: /* original 600c, guest PC 0x0c0ade7a */
if(!s->budget--) { s->failed_pc=0x0c0ade7au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade7c;
P_0c0ade7c: /* original 4018, guest PC 0x0c0ade7c */
if(!s->budget--) { s->failed_pc=0x0c0ade7cu; return 0; }
r[0]<<=8;
goto P_0c0ade7e;
P_0c0ade7e: /* original 20d9, guest PC 0x0c0ade7e */
if(!s->budget--) { s->failed_pc=0x0c0ade7eu; return 0; }
r[0]&=r[13];
goto P_0c0ade80;
P_0c0ade80: /* original 230b, guest PC 0x0c0ade80 */
if(!s->budget--) { s->failed_pc=0x0c0ade80u; return 0; }
r[3]|=r[0];
goto P_0c0ade82;
P_0c0ade82: /* original 8466, guest PC 0x0c0ade82 */
if(!s->budget--) { s->failed_pc=0x0c0ade82u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+6,1);
goto P_0c0ade84;
P_0c0ade84: /* original 600c, guest PC 0x0c0ade84 */
if(!s->budget--) { s->failed_pc=0x0c0ade84u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade86;
P_0c0ade86: /* original 230b, guest PC 0x0c0ade86 */
if(!s->budget--) { s->failed_pc=0x0c0ade86u; return 0; }
r[3]|=r[0];
goto P_0c0ade88;
P_0c0ade88: /* original 1731, guest PC 0x0c0ade88 */
if(!s->budget--) { s->failed_pc=0x0c0ade88u; return 0; }
write(ram,r[7]+4,r[3],4);
goto P_0c0ade8a;
P_0c0ade8a: /* original 846e, guest PC 0x0c0ade8a */
if(!s->budget--) { s->failed_pc=0x0c0ade8au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+14,1);
goto P_0c0ade8c;
P_0c0ade8c: /* original 600c, guest PC 0x0c0ade8c */
if(!s->budget--) { s->failed_pc=0x0c0ade8cu; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade8e;
P_0c0ade8e: /* original 4028, guest PC 0x0c0ade8e */
if(!s->budget--) { s->failed_pc=0x0c0ade8eu; return 0; }
r[0]<<=16;
goto P_0c0ade90;
P_0c0ade90: /* original 4018, guest PC 0x0c0ade90 */
if(!s->budget--) { s->failed_pc=0x0c0ade90u; return 0; }
r[0]<<=8;
goto P_0c0ade92;
P_0c0ade92: /* original 2019, guest PC 0x0c0ade92 */
if(!s->budget--) { s->failed_pc=0x0c0ade92u; return 0; }
r[0]&=r[1];
goto P_0c0ade94;
P_0c0ade94: /* original 6303, guest PC 0x0c0ade94 */
if(!s->budget--) { s->failed_pc=0x0c0ade94u; return 0; }
r[3]=r[0];
goto P_0c0ade96;
P_0c0ade96: /* original 846d, guest PC 0x0c0ade96 */
if(!s->budget--) { s->failed_pc=0x0c0ade96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+13,1);
goto P_0c0ade98;
P_0c0ade98: /* original 600c, guest PC 0x0c0ade98 */
if(!s->budget--) { s->failed_pc=0x0c0ade98u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ade9a;
P_0c0ade9a: /* original 4028, guest PC 0x0c0ade9a */
if(!s->budget--) { s->failed_pc=0x0c0ade9au; return 0; }
r[0]<<=16;
goto P_0c0ade9c;
P_0c0ade9c: /* original 2029, guest PC 0x0c0ade9c */
if(!s->budget--) { s->failed_pc=0x0c0ade9cu; return 0; }
r[0]&=r[2];
goto P_0c0ade9e;
P_0c0ade9e: /* original 230b, guest PC 0x0c0ade9e */
if(!s->budget--) { s->failed_pc=0x0c0ade9eu; return 0; }
r[3]|=r[0];
goto P_0c0adea0;
P_0c0adea0: /* original 846c, guest PC 0x0c0adea0 */
if(!s->budget--) { s->failed_pc=0x0c0adea0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+12,1);
goto P_0c0adea2;
P_0c0adea2: /* original 600c, guest PC 0x0c0adea2 */
if(!s->budget--) { s->failed_pc=0x0c0adea2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0adea4;
P_0c0adea4: /* original 4018, guest PC 0x0c0adea4 */
if(!s->budget--) { s->failed_pc=0x0c0adea4u; return 0; }
r[0]<<=8;
goto P_0c0adea6;
P_0c0adea6: /* original 20d9, guest PC 0x0c0adea6 */
if(!s->budget--) { s->failed_pc=0x0c0adea6u; return 0; }
r[0]&=r[13];
goto P_0c0adea8;
P_0c0adea8: /* original 230b, guest PC 0x0c0adea8 */
if(!s->budget--) { s->failed_pc=0x0c0adea8u; return 0; }
r[3]|=r[0];
goto P_0c0adeaa;
P_0c0adeaa: /* original 846b, guest PC 0x0c0adeaa */
if(!s->budget--) { s->failed_pc=0x0c0adeaau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+11,1);
goto P_0c0adeac;
P_0c0adeac: /* original 600c, guest PC 0x0c0adeac */
if(!s->budget--) { s->failed_pc=0x0c0adeacu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adeae;
P_0c0adeae: /* original 230b, guest PC 0x0c0adeae */
if(!s->budget--) { s->failed_pc=0x0c0adeaeu; return 0; }
r[3]|=r[0];
goto P_0c0adeb0;
P_0c0adeb0: /* original e004, guest PC 0x0c0adeb0 */
if(!s->budget--) { s->failed_pc=0x0c0adeb0u; return 0; }
r[0]=0x00000004u;
goto P_0c0adeb2;
P_0c0adeb2: /* original 1732, guest PC 0x0c0adeb2 */
if(!s->budget--) { s->failed_pc=0x0c0adeb2u; return 0; }
write(ram,r[7]+8,r[3],4);
goto P_0c0adeb4;
P_0c0adeb4: /* original f6e6, guest PC 0x0c0adeb4 */
if(!s->budget--) { s->failed_pc=0x0c0adeb4u; return 0; }
vf3_matrix_load(s,ram,6,r[14]+r[0]);
goto P_0c0adeb6;
P_0c0adeb6: /* original e008, guest PC 0x0c0adeb6 */
if(!s->budget--) { s->failed_pc=0x0c0adeb6u; return 0; }
r[0]=0x00000008u;
goto P_0c0adeb8;
P_0c0adeb8: /* original f8e6, guest PC 0x0c0adeb8 */
if(!s->budget--) { s->failed_pc=0x0c0adeb8u; return 0; }
vf3_matrix_load(s,ram,8,r[14]+r[0]);
goto P_0c0adeba;
P_0c0adeba: /* original 8465, guest PC 0x0c0adeba */
if(!s->budget--) { s->failed_pc=0x0c0adebau; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+5,1);
goto P_0c0adebc;
P_0c0adebc: /* original f7e8, guest PC 0x0c0adebc */
if(!s->budget--) { s->failed_pc=0x0c0adebcu; return 0; }
vf3_matrix_load(s,ram,7,r[14]);
goto P_0c0adebe;
P_0c0adebe: /* original 600c, guest PC 0x0c0adebe */
if(!s->budget--) { s->failed_pc=0x0c0adebeu; return 0; }
r[0]=r[0]&255u;
goto P_0c0adec0;
P_0c0adec0: /* original f675, guest PC 0x0c0adec0 */
if(!s->budget--) { s->failed_pc=0x0c0adec0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[7]))!=0);
goto P_0c0adec2;
P_0c0adec2: /* original 2f02, guest PC 0x0c0adec2 */
if(!s->budget--) { s->failed_pc=0x0c0adec2u; return 0; }
write(ram,r[15],r[0],4);
goto P_0c0adec4;
P_0c0adec4: /* original 846a, guest PC 0x0c0adec4 */
if(!s->budget--) { s->failed_pc=0x0c0adec4u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[6]+10,1);
goto P_0c0adec6;
P_0c0adec6: /* original 6d0c, guest PC 0x0c0adec6 */
if(!s->budget--) { s->failed_pc=0x0c0adec6u; return 0; }
r[13]=r[0]&255u;
goto P_0c0adec8;
P_0c0adec8: /* original 8d01, guest PC 0x0c0adec8 */
if(!s->budget--) { s->failed_pc=0x0c0adec8u; return 0; }
cond=r[17]&1u;
r[7]=0x00000001u;
if(cond) { goto P_0c0adece; }
goto P_0c0adecc;
P_0c0adeca: /* original e701, guest PC 0x0c0adeca */
if(!s->budget--) { s->failed_pc=0x0c0adecau; return 0; }
r[7]=0x00000001u;
goto P_0c0adecc;
P_0c0adecc: /* original e702, guest PC 0x0c0adecc */
if(!s->budget--) { s->failed_pc=0x0c0adeccu; return 0; }
r[7]=0x00000002u;
goto P_0c0adece;
P_0c0adece: /* original 902b, guest PC 0x0c0adece */
if(!s->budget--) { s->failed_pc=0x0c0adeceu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adf28u,2);
goto P_0c0aded0;
P_0c0aded0: /* original 2dd8, guest PC 0x0c0aded0 */
if(!s->budget--) { s->failed_pc=0x0c0aded0u; return 0; }
r[17]=(r[17]&~1u)|(((r[13]&r[13])==0)!=0);
goto P_0c0aded2;
P_0c0aded2: /* original 0474, guest PC 0x0c0aded2 */
if(!s->budget--) { s->failed_pc=0x0c0aded2u; return 0; }
write(ram,r[4]+r[0],r[7],1);
goto P_0c0aded4;
P_0c0aded4: /* original e05c, guest PC 0x0c0aded4 */
if(!s->budget--) { s->failed_pc=0x0c0aded4u; return 0; }
r[0]=0x0000005cu;
goto P_0c0aded6;
P_0c0aded6: /* original f946, guest PC 0x0c0aded6 */
if(!s->budget--) { s->failed_pc=0x0c0aded6u; return 0; }
vf3_matrix_load(s,ram,9,r[4]+r[0]);
goto P_0c0aded8;
P_0c0aded8: /* original f57c, guest PC 0x0c0aded8 */
if(!s->budget--) { s->failed_pc=0x0c0aded8u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0adeda;
P_0c0adeda: /* original f561, guest PC 0x0c0adeda */
if(!s->budget--) { s->failed_pc=0x0c0adedau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0adedc;
P_0c0adedc: /* original f49c, guest PC 0x0c0adedc */
if(!s->budget--) { s->failed_pc=0x0c0adedcu; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0adede;
P_0c0adede: /* original f461, guest PC 0x0c0adede */
if(!s->budget--) { s->failed_pc=0x0c0adedeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'-');
goto P_0c0adee0;
P_0c0adee0: /* original 9023, guest PC 0x0c0adee0 */
if(!s->budget--) { s->failed_pc=0x0c0adee0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0adf2au,2);
goto P_0c0adee2;
P_0c0adee2: /* original 6ef2, guest PC 0x0c0adee2 */
if(!s->budget--) { s->failed_pc=0x0c0adee2u; return 0; }
tmp=read(ram,r[15],4);
r[14]=tmp;
goto P_0c0adee4;
P_0c0adee4: /* original 074c, guest PC 0x0c0adee4 */
if(!s->budget--) { s->failed_pc=0x0c0adee4u; return 0; }
r[7]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0adee6;
P_0c0adee6: /* original 8d0b, guest PC 0x0c0adee6 */
if(!s->budget--) { s->failed_pc=0x0c0adee6u; return 0; }
cond=r[17]&1u;
r[7]=r[7]&255u;
if(cond) { goto P_0c0adf00; }
goto P_0c0adeea;
P_0c0adee8: /* original 677c, guest PC 0x0c0adee8 */
if(!s->budget--) { s->failed_pc=0x0c0adee8u; return 0; }
r[7]=r[7]&255u;
goto P_0c0adeea;
P_0c0adeea: /* original f58c, guest PC 0x0c0adeea */
if(!s->budget--) { s->failed_pc=0x0c0adeeau; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0adeec;
P_0c0adeec: /* original f561, guest PC 0x0c0adeec */
if(!s->budget--) { s->failed_pc=0x0c0adeecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[6],r[18],'-');
goto P_0c0adeee;
P_0c0adeee: /* original f455, guest PC 0x0c0adeee */
if(!s->budget--) { s->failed_pc=0x0c0adeeeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adef0;
P_0c0adef0: /* original 8905, guest PC 0x0c0adef0 */
if(!s->budget--) { s->failed_pc=0x0c0adef0u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adefe; }
goto P_0c0adef2;
P_0c0adef2: /* original f57c, guest PC 0x0c0adef2 */
if(!s->budget--) { s->failed_pc=0x0c0adef2u; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0adef4;
P_0c0adef4: /* original f581, guest PC 0x0c0adef4 */
if(!s->budget--) { s->failed_pc=0x0c0adef4u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[8],r[18],'-');
goto P_0c0adef6;
P_0c0adef6: /* original f49c, guest PC 0x0c0adef6 */
if(!s->budget--) { s->failed_pc=0x0c0adef6u; return 0; }
vf3_matrix_move(s,4,9);
goto P_0c0adef8;
P_0c0adef8: /* original 6ed3, guest PC 0x0c0adef8 */
if(!s->budget--) { s->failed_pc=0x0c0adef8u; return 0; }
r[14]=r[13];
goto P_0c0adefa;
P_0c0adefa: /* original a001, guest PC 0x0c0adefa */
if(!s->budget--) { s->failed_pc=0x0c0adefau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c0adf00;
P_0c0adefc: /* original f481, guest PC 0x0c0adefc */
if(!s->budget--) { s->failed_pc=0x0c0adefcu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[8],r[18],'-');
goto P_0c0adefe;
P_0c0adefe: /* original 67d3, guest PC 0x0c0adefe */
if(!s->budget--) { s->failed_pc=0x0c0adefeu; return 0; }
r[7]=r[13];
goto P_0c0adf00;
P_0c0adf00: /* original f38d, guest PC 0x0c0adf00 */
if(!s->budget--) { s->failed_pc=0x0c0adf00u; return 0; }
fr[3]=0;
goto P_0c0adf02;
P_0c0adf02: /* original f355, guest PC 0x0c0adf02 */
if(!s->budget--) { s->failed_pc=0x0c0adf02u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[5]))!=0);
goto P_0c0adf04;
P_0c0adf04: /* original 8d07, guest PC 0x0c0adf04 */
if(!s->budget--) { s->failed_pc=0x0c0adf04u; return 0; }
cond=r[17]&1u;
fr[6]=0;
if(cond) { goto P_0c0adf16; }
goto P_0c0adf08;
P_0c0adf06: /* original f68d, guest PC 0x0c0adf06 */
if(!s->budget--) { s->failed_pc=0x0c0adf06u; return 0; }
fr[6]=0;
goto P_0c0adf08;
P_0c0adf08: /* original f38d, guest PC 0x0c0adf08 */
if(!s->budget--) { s->failed_pc=0x0c0adf08u; return 0; }
fr[3]=0;
goto P_0c0adf0a;
P_0c0adf0a: /* original f345, guest PC 0x0c0adf0a */
if(!s->budget--) { s->failed_pc=0x0c0adf0au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0adf0c;
P_0c0adf0c: /* original 8917, guest PC 0x0c0adf0c */
if(!s->budget--) { s->failed_pc=0x0c0adf0cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf3e; }
goto P_0c0adf0e;
P_0c0adf0e: /* original f455, guest PC 0x0c0adf0e */
if(!s->budget--) { s->failed_pc=0x0c0adf0eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adf10;
P_0c0adf10: /* original 8b16, guest PC 0x0c0adf10 */
if(!s->budget--) { s->failed_pc=0x0c0adf10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0adf40; }
goto P_0c0adf12;
P_0c0adf12: /* original a002, guest PC 0x0c0adf12 */
if(!s->budget--) { s->failed_pc=0x0c0adf12u; return 0; }
goto P_0c0adf1a;
P_0c0adf14: /* original 0009, guest PC 0x0c0adf14 */
if(!s->budget--) { s->failed_pc=0x0c0adf14u; return 0; }
goto P_0c0adf16;
P_0c0adf16: /* original f455, guest PC 0x0c0adf16 */
if(!s->budget--) { s->failed_pc=0x0c0adf16u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0adf18;
P_0c0adf18: /* original 890e, guest PC 0x0c0adf18 */
if(!s->budget--) { s->failed_pc=0x0c0adf18u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf38; }
goto P_0c0adf1a;
P_0c0adf1a: /* original a011, guest PC 0x0c0adf1a */
if(!s->budget--) { s->failed_pc=0x0c0adf1au; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0adf40;
P_0c0adf1c: /* original f45c, guest PC 0x0c0adf1c */
if(!s->budget--) { s->failed_pc=0x0c0adf1cu; return 0; }
vf3_matrix_move(s,4,5);
return vf3_matrix_family(0x0c0adf1eu,s,ram);
P_0c0adf38: /* original f38d, guest PC 0x0c0adf38 */
if(!s->budget--) { s->failed_pc=0x0c0adf38u; return 0; }
fr[3]=0;
goto P_0c0adf3a;
P_0c0adf3a: /* original f345, guest PC 0x0c0adf3a */
if(!s->budget--) { s->failed_pc=0x0c0adf3au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[4]))!=0);
goto P_0c0adf3c;
P_0c0adf3c: /* original 8900, guest PC 0x0c0adf3c */
if(!s->budget--) { s->failed_pc=0x0c0adf3cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0adf40; }
goto P_0c0adf3e;
P_0c0adf3e: /* original f46c, guest PC 0x0c0adf3e */
if(!s->budget--) { s->failed_pc=0x0c0adf3eu; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0adf40;
P_0c0adf40: /* original f453, guest PC 0x0c0adf40 */
if(!s->budget--) { s->failed_pc=0x0c0adf40u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'/');
goto P_0c0adf42;
P_0c0adf42: /* original 37e8, guest PC 0x0c0adf42 */
if(!s->budget--) { s->failed_pc=0x0c0adf42u; return 0; }
r[7]-=r[14];
goto P_0c0adf44;
P_0c0adf44: /* original 475a, guest PC 0x0c0adf44 */
if(!s->budget--) { s->failed_pc=0x0c0adf44u; return 0; }
r[53]=r[7];
goto P_0c0adf46;
P_0c0adf46: /* original 9093, guest PC 0x0c0adf46 */
if(!s->budget--) { s->failed_pc=0x0c0adf46u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae070u,2);
goto P_0c0adf48;
P_0c0adf48: /* original f32d, guest PC 0x0c0adf48 */
if(!s->budget--) { s->failed_pc=0x0c0adf48u; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0adf4a;
P_0c0adf4a: /* original f63c, guest PC 0x0c0adf4a */
if(!s->budget--) { s->failed_pc=0x0c0adf4au; return 0; }
vf3_matrix_move(s,6,3);
goto P_0c0adf4c;
P_0c0adf4c: /* original f462, guest PC 0x0c0adf4c */
if(!s->budget--) { s->failed_pc=0x0c0adf4cu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0adf4e;
P_0c0adf4e: /* original f43d, guest PC 0x0c0adf4e */
if(!s->budget--) { s->failed_pc=0x0c0adf4eu; return 0; }
r[53]=truncate_float(fr[4]);
goto P_0c0adf50;
P_0c0adf50: /* original 075a, guest PC 0x0c0adf50 */
if(!s->budget--) { s->failed_pc=0x0c0adf50u; return 0; }
r[7]=r[53];
goto P_0c0adf52;
P_0c0adf52: /* original 3e7c, guest PC 0x0c0adf52 */
if(!s->budget--) { s->failed_pc=0x0c0adf52u; return 0; }
r[14]+=r[7];
goto P_0c0adf54;
P_0c0adf54: /* original 04e4, guest PC 0x0c0adf54 */
if(!s->budget--) { s->failed_pc=0x0c0adf54u; return 0; }
write(ram,r[4]+r[0],r[14],1);
goto P_0c0adf56;
P_0c0adf56: /* original bb0f, guest PC 0x0c0adf56 */
if(!s->budget--) { s->failed_pc=0x0c0adf56u; return 0; }
target=0x0c0ad578u; r[16]=0x0c0adf5au;
r[6]+=0x0000000fu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0adf5au) { target=s->pc; goto dispatch; }
goto P_0c0adf5a;
P_0c0adf58: /* original 760f, guest PC 0x0c0adf58 */
if(!s->budget--) { s->failed_pc=0x0c0adf58u; return 0; }
r[6]+=0x0000000fu;
goto P_0c0adf5a;
P_0c0adf5a: /* original 7f10, guest PC 0x0c0adf5a */
if(!s->budget--) { s->failed_pc=0x0c0adf5au; return 0; }
r[15]+=0x00000010u;
goto P_0c0adf5c;
P_0c0adf5c: /* original 4f26, guest PC 0x0c0adf5c */
if(!s->budget--) { s->failed_pc=0x0c0adf5cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0adf5e;
P_0c0adf5e: /* original 6df6, guest PC 0x0c0adf5e */
if(!s->budget--) { s->failed_pc=0x0c0adf5eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0adf60;
P_0c0adf60: /* original 000b, guest PC 0x0c0adf60 */
if(!s->budget--) { s->failed_pc=0x0c0adf60u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0adf62: /* original 6ef6, guest PC 0x0c0adf62 */
if(!s->budget--) { s->failed_pc=0x0c0adf62u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0adf64u,s,ram);
P_0c0adf6c: /* original ab04, guest PC 0x0c0adf6c */
if(!s->budget--) { s->failed_pc=0x0c0adf6cu; return 0; }
r[6]+=0x00000007u;
goto P_0c0ad578;
P_0c0adf6e: /* original 7607, guest PC 0x0c0adf6e */
if(!s->budget--) { s->failed_pc=0x0c0adf6eu; return 0; }
r[6]+=0x00000007u;
return vf3_matrix_family(0x0c0adf70u,s,ram);
P_0c0ae29c: /* original 5762, guest PC 0x0c0ae29c */
if(!s->budget--) { s->failed_pc=0x0c0ae29cu; return 0; }
r[7]=read(ram,r[6]+8,4);
goto P_0c0ae29e;
P_0c0ae29e: /* original 7ffc, guest PC 0x0c0ae29e */
if(!s->budget--) { s->failed_pc=0x0c0ae29eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae2a0;
P_0c0ae2a0: /* original 6770, guest PC 0x0c0ae2a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a0u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[7],1);
r[7]=tmp;
goto P_0c0ae2a2;
P_0c0ae2a2: /* original 677c, guest PC 0x0c0ae2a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a2u; return 0; }
r[7]=r[7]&255u;
goto P_0c0ae2a4;
P_0c0ae2a4: /* original 2778, guest PC 0x0c0ae2a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a4u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0ae2a6;
P_0c0ae2a6: /* original 8910, guest PC 0x0c0ae2a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a6u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2ca; }
goto P_0c0ae2a8;
P_0c0ae2a8: /* original 5362, guest PC 0x0c0ae2a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2a8u; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae2aa;
P_0c0ae2aa: /* original 2f32, guest PC 0x0c0ae2aa */
if(!s->budget--) { s->failed_pc=0x0c0ae2aau; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0ae2ac;
P_0c0ae2ac: /* original 62f2, guest PC 0x0c0ae2ac */
if(!s->budget--) { s->failed_pc=0x0c0ae2acu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c0ae2ae;
P_0c0ae2ae: /* original 8432, guest PC 0x0c0ae2ae */
if(!s->budget--) { s->failed_pc=0x0c0ae2aeu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+2,1);
goto P_0c0ae2b0;
P_0c0ae2b0: /* original 7201, guest PC 0x0c0ae2b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b0u; return 0; }
r[2]+=0x00000001u;
goto P_0c0ae2b2;
P_0c0ae2b2: /* original d315, guest PC 0x0c0ae2b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b2u; return 0; }
r[3]=read(ram,0x0c0ae308u,4);
goto P_0c0ae2b4;
P_0c0ae2b4: /* original 600c, guest PC 0x0c0ae2b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b4u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae2b6;
P_0c0ae2b6: /* original 6220, guest PC 0x0c0ae2b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b6u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[2],1);
r[2]=tmp;
goto P_0c0ae2b8;
P_0c0ae2b8: /* original 4018, guest PC 0x0c0ae2b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2b8u; return 0; }
r[0]<<=8;
goto P_0c0ae2ba;
P_0c0ae2ba: /* original 622c, guest PC 0x0c0ae2ba */
if(!s->budget--) { s->failed_pc=0x0c0ae2bau; return 0; }
r[2]=r[2]&255u;
goto P_0c0ae2bc;
P_0c0ae2bc: /* original 2039, guest PC 0x0c0ae2bc */
if(!s->budget--) { s->failed_pc=0x0c0ae2bcu; return 0; }
r[0]&=r[3];
goto P_0c0ae2be;
P_0c0ae2be: /* original 202b, guest PC 0x0c0ae2be */
if(!s->budget--) { s->failed_pc=0x0c0ae2beu; return 0; }
r[0]|=r[2];
goto P_0c0ae2c0;
P_0c0ae2c0: /* original 6103, guest PC 0x0c0ae2c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c0u; return 0; }
r[1]=r[0];
goto P_0c0ae2c2;
P_0c0ae2c2: /* original 1601, guest PC 0x0c0ae2c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c2u; return 0; }
write(ram,r[6]+4,r[0],4);
goto P_0c0ae2c4;
P_0c0ae2c4: /* original 6262, guest PC 0x0c0ae2c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c4u; return 0; }
tmp=read(ram,r[6],4);
r[2]=tmp;
goto P_0c0ae2c6;
P_0c0ae2c6: /* original 3212, guest PC 0x0c0ae2c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c6u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>=r[1])!=0);
goto P_0c0ae2c8;
P_0c0ae2c8: /* original 8902, guest PC 0x0c0ae2c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2c8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae2d0; }
goto P_0c0ae2ca;
P_0c0ae2ca: /* original d310, guest PC 0x0c0ae2ca */
if(!s->budget--) { s->failed_pc=0x0c0ae2cau; return 0; }
r[3]=read(ram,0x0c0ae30cu,4);
goto P_0c0ae2cc;
P_0c0ae2cc: /* original 432b, guest PC 0x0c0ae2cc */
if(!s->budget--) { s->failed_pc=0x0c0ae2ccu; return 0; }
target=r[3];
r[15]+=0x00000004u;
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
P_0c0ae2ce: /* original 7f04, guest PC 0x0c0ae2ce */
if(!s->budget--) { s->failed_pc=0x0c0ae2ceu; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae2d0;
P_0c0ae2d0: /* original d00f, guest PC 0x0c0ae2d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d0u; return 0; }
r[0]=read(ram,0x0c0ae310u,4);
goto P_0c0ae2d2;
P_0c0ae2d2: /* original 4708, guest PC 0x0c0ae2d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d2u; return 0; }
r[7]<<=2;
goto P_0c0ae2d4;
P_0c0ae2d4: /* original 027e, guest PC 0x0c0ae2d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d4u; return 0; }
r[2]=read(ram,r[7]+r[0],4);
goto P_0c0ae2d6;
P_0c0ae2d6: /* original 2f22, guest PC 0x0c0ae2d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d6u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae2d8;
P_0c0ae2d8: /* original 422b, guest PC 0x0c0ae2d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae2d8u; return 0; }
target=r[2];
r[15]+=0x00000004u;
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
P_0c0ae2da: /* original 7f04, guest PC 0x0c0ae2da */
if(!s->budget--) { s->failed_pc=0x0c0ae2dau; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ae2dcu,s,ram);
P_0c0ae458: /* original 4f22, guest PC 0x0c0ae458 */
if(!s->budget--) { s->failed_pc=0x0c0ae458u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae45a;
P_0c0ae45a: /* original 7ff0, guest PC 0x0c0ae45a */
if(!s->budget--) { s->failed_pc=0x0c0ae45au; return 0; }
r[15]+=0xfffffff0u;
goto P_0c0ae45c;
P_0c0ae45c: /* original 2f52, guest PC 0x0c0ae45c */
if(!s->budget--) { s->failed_pc=0x0c0ae45cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae45e;
P_0c0ae45e: /* original 53d1, guest PC 0x0c0ae45e */
if(!s->budget--) { s->failed_pc=0x0c0ae45eu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ae460;
P_0c0ae460: /* original 62d2, guest PC 0x0c0ae460 */
if(!s->budget--) { s->failed_pc=0x0c0ae460u; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ae462;
P_0c0ae462: /* original d545, guest PC 0x0c0ae462 */
if(!s->budget--) { s->failed_pc=0x0c0ae462u; return 0; }
r[5]=read(ram,0x0c0ae578u,4);
goto P_0c0ae464;
P_0c0ae464: /* original 3230, guest PC 0x0c0ae464 */
if(!s->budget--) { s->failed_pc=0x0c0ae464u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0ae466;
P_0c0ae466: /* original 8f44, guest PC 0x0c0ae466 */
if(!s->budget--) { s->failed_pc=0x0c0ae466u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c0ae4f2; }
goto P_0c0ae46a;
P_0c0ae468: /* original 6c43, guest PC 0x0c0ae468 */
if(!s->budget--) { s->failed_pc=0x0c0ae468u; return 0; }
r[12]=r[4];
goto P_0c0ae46a;
P_0c0ae46a: /* original 6152, guest PC 0x0c0ae46a */
if(!s->budget--) { s->failed_pc=0x0c0ae46au; return 0; }
tmp=read(ram,r[5],4);
r[1]=tmp;
goto P_0c0ae46c;
P_0c0ae46c: /* original d343, guest PC 0x0c0ae46c */
if(!s->budget--) { s->failed_pc=0x0c0ae46cu; return 0; }
r[3]=read(ram,0x0c0ae57cu,4);
goto P_0c0ae46e;
P_0c0ae46e: /* original 2138, guest PC 0x0c0ae46e */
if(!s->budget--) { s->failed_pc=0x0c0ae46eu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ae470;
P_0c0ae470: /* original 8b3f, guest PC 0x0c0ae470 */
if(!s->budget--) { s->failed_pc=0x0c0ae470u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae4f2; }
goto P_0c0ae472;
P_0c0ae472: /* original 54d2, guest PC 0x0c0ae472 */
if(!s->budget--) { s->failed_pc=0x0c0ae472u; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0ae474;
P_0c0ae474: /* original de42, guest PC 0x0c0ae474 */
if(!s->budget--) { s->failed_pc=0x0c0ae474u; return 0; }
r[14]=read(ram,0x0c0ae580u,4);
goto P_0c0ae476;
P_0c0ae476: /* original 8446, guest PC 0x0c0ae476 */
if(!s->budget--) { s->failed_pc=0x0c0ae476u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+6,1);
goto P_0c0ae478;
P_0c0ae478: /* original d342, guest PC 0x0c0ae478 */
if(!s->budget--) { s->failed_pc=0x0c0ae478u; return 0; }
r[3]=read(ram,0x0c0ae584u,4);
goto P_0c0ae47a;
P_0c0ae47a: /* original 600c, guest PC 0x0c0ae47a */
if(!s->budget--) { s->failed_pc=0x0c0ae47au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae47c;
P_0c0ae47c: /* original d242, guest PC 0x0c0ae47c */
if(!s->budget--) { s->failed_pc=0x0c0ae47cu; return 0; }
r[2]=read(ram,0x0c0ae588u,4);
goto P_0c0ae47e;
P_0c0ae47e: /* original 4028, guest PC 0x0c0ae47e */
if(!s->budget--) { s->failed_pc=0x0c0ae47eu; return 0; }
r[0]<<=16;
goto P_0c0ae480;
P_0c0ae480: /* original 4018, guest PC 0x0c0ae480 */
if(!s->budget--) { s->failed_pc=0x0c0ae480u; return 0; }
r[0]<<=8;
goto P_0c0ae482;
P_0c0ae482: /* original 2e09, guest PC 0x0c0ae482 */
if(!s->budget--) { s->failed_pc=0x0c0ae482u; return 0; }
r[14]&=r[0];
goto P_0c0ae484;
P_0c0ae484: /* original 8445, guest PC 0x0c0ae484 */
if(!s->budget--) { s->failed_pc=0x0c0ae484u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+5,1);
goto P_0c0ae486;
P_0c0ae486: /* original 600c, guest PC 0x0c0ae486 */
if(!s->budget--) { s->failed_pc=0x0c0ae486u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae488;
P_0c0ae488: /* original 4028, guest PC 0x0c0ae488 */
if(!s->budget--) { s->failed_pc=0x0c0ae488u; return 0; }
r[0]<<=16;
goto P_0c0ae48a;
P_0c0ae48a: /* original 2039, guest PC 0x0c0ae48a */
if(!s->budget--) { s->failed_pc=0x0c0ae48au; return 0; }
r[0]&=r[3];
goto P_0c0ae48c;
P_0c0ae48c: /* original 2e0b, guest PC 0x0c0ae48c */
if(!s->budget--) { s->failed_pc=0x0c0ae48cu; return 0; }
r[14]|=r[0];
goto P_0c0ae48e;
P_0c0ae48e: /* original 8444, guest PC 0x0c0ae48e */
if(!s->budget--) { s->failed_pc=0x0c0ae48eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+4,1);
goto P_0c0ae490;
P_0c0ae490: /* original 600c, guest PC 0x0c0ae490 */
if(!s->budget--) { s->failed_pc=0x0c0ae490u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae492;
P_0c0ae492: /* original 4018, guest PC 0x0c0ae492 */
if(!s->budget--) { s->failed_pc=0x0c0ae492u; return 0; }
r[0]<<=8;
goto P_0c0ae494;
P_0c0ae494: /* original 2029, guest PC 0x0c0ae494 */
if(!s->budget--) { s->failed_pc=0x0c0ae494u; return 0; }
r[0]&=r[2];
goto P_0c0ae496;
P_0c0ae496: /* original 2e0b, guest PC 0x0c0ae496 */
if(!s->budget--) { s->failed_pc=0x0c0ae496u; return 0; }
r[14]|=r[0];
goto P_0c0ae498;
P_0c0ae498: /* original 8443, guest PC 0x0c0ae498 */
if(!s->budget--) { s->failed_pc=0x0c0ae498u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0ae49a;
P_0c0ae49a: /* original 600c, guest PC 0x0c0ae49a */
if(!s->budget--) { s->failed_pc=0x0c0ae49au; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae49c;
P_0c0ae49c: /* original 2e0b, guest PC 0x0c0ae49c */
if(!s->budget--) { s->failed_pc=0x0c0ae49cu; return 0; }
r[14]|=r[0];
goto P_0c0ae49e;
P_0c0ae49e: /* original 60e3, guest PC 0x0c0ae49e */
if(!s->budget--) { s->failed_pc=0x0c0ae49eu; return 0; }
r[0]=r[14];
goto P_0c0ae4a0;
P_0c0ae4a0: /* original 885f, guest PC 0x0c0ae4a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae4a0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000005fu)!=0);
goto P_0c0ae4a2;
P_0c0ae4a2: /* original 8b02, guest PC 0x0c0ae4a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae4a2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae4aa; }
goto P_0c0ae4a4;
P_0c0ae4a4: /* original 65c3, guest PC 0x0c0ae4a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae4a4u; return 0; }
r[5]=r[12];
goto P_0c0ae4a6;
P_0c0ae4a6: /* original a005, guest PC 0x0c0ae4a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae4a6u; return 0; }
r[4]=0x00000000u;
goto P_0c0ae4b4;
P_0c0ae4a8: /* original e400, guest PC 0x0c0ae4a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae4a8u; return 0; }
r[4]=0x00000000u;
goto P_0c0ae4aa;
P_0c0ae4aa: /* original 9260, guest PC 0x0c0ae4aa */
if(!s->budget--) { s->failed_pc=0x0c0ae4aau; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae56eu,2);
goto P_0c0ae4ac;
P_0c0ae4ac: /* original 3e20, guest PC 0x0c0ae4ac */
if(!s->budget--) { s->failed_pc=0x0c0ae4acu; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[2])!=0);
goto P_0c0ae4ae;
P_0c0ae4ae: /* original 8b06, guest PC 0x0c0ae4ae */
if(!s->budget--) { s->failed_pc=0x0c0ae4aeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae4be; }
goto P_0c0ae4b0;
P_0c0ae4b0: /* original e401, guest PC 0x0c0ae4b0 */
if(!s->budget--) { s->failed_pc=0x0c0ae4b0u; return 0; }
r[4]=0x00000001u;
goto P_0c0ae4b2;
P_0c0ae4b2: /* original 65c3, guest PC 0x0c0ae4b2 */
if(!s->budget--) { s->failed_pc=0x0c0ae4b2u; return 0; }
r[5]=r[12];
goto P_0c0ae4b4;
P_0c0ae4b4: /* original d335, guest PC 0x0c0ae4b4 */
if(!s->budget--) { s->failed_pc=0x0c0ae4b4u; return 0; }
r[3]=read(ram,0x0c0ae58cu,4);
goto P_0c0ae4b6;
P_0c0ae4b6: /* original 430b, guest PC 0x0c0ae4b6 */
if(!s->budget--) { s->failed_pc=0x0c0ae4b6u; return 0; }
target=r[3];
r[16]=0x0c0ae4bau;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae4bau) { target=s->pc; goto dispatch; }
goto P_0c0ae4ba;
P_0c0ae4b8: /* original 0009, guest PC 0x0c0ae4b8 */
if(!s->budget--) { s->failed_pc=0x0c0ae4b8u; return 0; }
goto P_0c0ae4ba;
P_0c0ae4ba: /* original a01a, guest PC 0x0c0ae4ba */
if(!s->budget--) { s->failed_pc=0x0c0ae4bau; return 0; }
goto P_0c0ae4f2;
P_0c0ae4bc: /* original 0009, guest PC 0x0c0ae4bc */
if(!s->budget--) { s->failed_pc=0x0c0ae4bcu; return 0; }
goto P_0c0ae4be;
P_0c0ae4be: /* original 9357, guest PC 0x0c0ae4be */
if(!s->budget--) { s->failed_pc=0x0c0ae4beu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae570u,2);
goto P_0c0ae4c0;
P_0c0ae4c0: /* original 3e30, guest PC 0x0c0ae4c0 */
if(!s->budget--) { s->failed_pc=0x0c0ae4c0u; return 0; }
r[17]=(r[17]&~1u)|((r[14]==r[3])!=0);
goto P_0c0ae4c2;
P_0c0ae4c2: /* original 8b13, guest PC 0x0c0ae4c2 */
if(!s->budget--) { s->failed_pc=0x0c0ae4c2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae4ec; }
goto P_0c0ae4c4;
P_0c0ae4c4: /* original e01c, guest PC 0x0c0ae4c4 */
if(!s->budget--) { s->failed_pc=0x0c0ae4c4u; return 0; }
r[0]=0x0000001cu;
goto P_0c0ae4c6;
P_0c0ae4c6: /* original 005c, guest PC 0x0c0ae4c6 */
if(!s->budget--) { s->failed_pc=0x0c0ae4c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0ae4c8;
P_0c0ae4c8: /* original 600c, guest PC 0x0c0ae4c8 */
if(!s->budget--) { s->failed_pc=0x0c0ae4c8u; return 0; }
r[0]=r[0]&255u;
goto P_0c0ae4ca;
P_0c0ae4ca: /* original c90f, guest PC 0x0c0ae4ca */
if(!s->budget--) { s->failed_pc=0x0c0ae4cau; return 0; }
r[0]&=15u;
goto P_0c0ae4cc;
P_0c0ae4cc: /* original 8806, guest PC 0x0c0ae4cc */
if(!s->budget--) { s->failed_pc=0x0c0ae4ccu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0ae4ce;
P_0c0ae4ce: /* original 8b0d, guest PC 0x0c0ae4ce */
if(!s->budget--) { s->failed_pc=0x0c0ae4ceu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae4ec; }
goto P_0c0ae4d0;
P_0c0ae4d0: /* original 904f, guest PC 0x0c0ae4d0 */
if(!s->budget--) { s->failed_pc=0x0c0ae4d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae572u,2);
goto P_0c0ae4d2;
P_0c0ae4d2: /* original 64f3, guest PC 0x0c0ae4d2 */
if(!s->budget--) { s->failed_pc=0x0c0ae4d2u; return 0; }
r[4]=r[15];
goto P_0c0ae4d4;
P_0c0ae4d4: /* original d32e, guest PC 0x0c0ae4d4 */
if(!s->budget--) { s->failed_pc=0x0c0ae4d4u; return 0; }
r[3]=read(ram,0x0c0ae590u,4);
goto P_0c0ae4d6;
P_0c0ae4d6: /* original 7404, guest PC 0x0c0ae4d6 */
if(!s->budget--) { s->failed_pc=0x0c0ae4d6u; return 0; }
r[4]+=0x00000004u;
goto P_0c0ae4d8;
P_0c0ae4d8: /* original f5c6, guest PC 0x0c0ae4d8 */
if(!s->budget--) { s->failed_pc=0x0c0ae4d8u; return 0; }
vf3_matrix_load(s,ram,5,r[12]+r[0]);
goto P_0c0ae4da;
P_0c0ae4da: /* original 70f8, guest PC 0x0c0ae4da */
if(!s->budget--) { s->failed_pc=0x0c0ae4dau; return 0; }
r[0]+=0xfffffff8u;
goto P_0c0ae4dc;
P_0c0ae4dc: /* original 430b, guest PC 0x0c0ae4dc */
if(!s->budget--) { s->failed_pc=0x0c0ae4dcu; return 0; }
target=r[3];
r[16]=0x0c0ae4e0u;
vf3_matrix_load(s,ram,4,r[12]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae4e0u) { target=s->pc; goto dispatch; }
goto P_0c0ae4e0;
P_0c0ae4de: /* original f4c6, guest PC 0x0c0ae4de */
if(!s->budget--) { s->failed_pc=0x0c0ae4deu; return 0; }
vf3_matrix_load(s,ram,4,r[12]+r[0]);
goto P_0c0ae4e0;
P_0c0ae4e0: /* original d22c, guest PC 0x0c0ae4e0 */
if(!s->budget--) { s->failed_pc=0x0c0ae4e0u; return 0; }
r[2]=read(ram,0x0c0ae594u,4);
goto P_0c0ae4e2;
P_0c0ae4e2: /* original 6403, guest PC 0x0c0ae4e2 */
if(!s->budget--) { s->failed_pc=0x0c0ae4e2u; return 0; }
r[4]=r[0];
goto P_0c0ae4e4;
P_0c0ae4e4: /* original 2428, guest PC 0x0c0ae4e4 */
if(!s->budget--) { s->failed_pc=0x0c0ae4e4u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[2])==0)!=0);
goto P_0c0ae4e6;
P_0c0ae4e6: /* original 8f01, guest PC 0x0c0ae4e6 */
if(!s->budget--) { s->failed_pc=0x0c0ae4e6u; return 0; }
cond=r[17]&1u;
r[14]=r[0];
if(!cond) { goto P_0c0ae4ec; }
goto P_0c0ae4ea;
P_0c0ae4e8: /* original 6e03, guest PC 0x0c0ae4e8 */
if(!s->budget--) { s->failed_pc=0x0c0ae4e8u; return 0; }
r[14]=r[0];
goto P_0c0ae4ea;
P_0c0ae4ea: /* original 9e43, guest PC 0x0c0ae4ea */
if(!s->budget--) { s->failed_pc=0x0c0ae4eau; return 0; }
r[14]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae574u,2);
goto P_0c0ae4ec;
P_0c0ae4ec: /* original d32a, guest PC 0x0c0ae4ec */
if(!s->budget--) { s->failed_pc=0x0c0ae4ecu; return 0; }
r[3]=read(ram,0x0c0ae598u,4);
goto P_0c0ae4ee;
P_0c0ae4ee: /* original 430b, guest PC 0x0c0ae4ee */
if(!s->budget--) { s->failed_pc=0x0c0ae4eeu; return 0; }
target=r[3];
r[16]=0x0c0ae4f2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae4f2u) { target=s->pc; goto dispatch; }
goto P_0c0ae4f2;
P_0c0ae4f0: /* original 64e3, guest PC 0x0c0ae4f0 */
if(!s->budget--) { s->failed_pc=0x0c0ae4f0u; return 0; }
r[4]=r[14];
goto P_0c0ae4f2;
P_0c0ae4f2: /* original 52d2, guest PC 0x0c0ae4f2 */
if(!s->budget--) { s->failed_pc=0x0c0ae4f2u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0ae4f4;
P_0c0ae4f4: /* original 66d3, guest PC 0x0c0ae4f4 */
if(!s->budget--) { s->failed_pc=0x0c0ae4f4u; return 0; }
r[6]=r[13];
goto P_0c0ae4f6;
P_0c0ae4f6: /* original 7207, guest PC 0x0c0ae4f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae4f6u; return 0; }
r[2]+=0x00000007u;
goto P_0c0ae4f8;
P_0c0ae4f8: /* original 1d22, guest PC 0x0c0ae4f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae4f8u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0ae4fa;
P_0c0ae4fa: /* original 65f2, guest PC 0x0c0ae4fa */
if(!s->budget--) { s->failed_pc=0x0c0ae4fau; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ae4fc;
P_0c0ae4fc: /* original bece, guest PC 0x0c0ae4fc */
if(!s->budget--) { s->failed_pc=0x0c0ae4fcu; return 0; }
target=0x0c0ae29cu; r[16]=0x0c0ae500u;
r[4]=r[12];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae500u) { target=s->pc; goto dispatch; }
goto P_0c0ae500;
P_0c0ae4fe: /* original 64c3, guest PC 0x0c0ae4fe */
if(!s->budget--) { s->failed_pc=0x0c0ae4feu; return 0; }
r[4]=r[12];
goto P_0c0ae500;
P_0c0ae500: /* original 7f10, guest PC 0x0c0ae500 */
if(!s->budget--) { s->failed_pc=0x0c0ae500u; return 0; }
r[15]+=0x00000010u;
goto P_0c0ae502;
P_0c0ae502: /* original 4f26, guest PC 0x0c0ae502 */
if(!s->budget--) { s->failed_pc=0x0c0ae502u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae504;
P_0c0ae504: /* original 6cf6, guest PC 0x0c0ae504 */
if(!s->budget--) { s->failed_pc=0x0c0ae504u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae506;
P_0c0ae506: /* original 6df6, guest PC 0x0c0ae506 */
if(!s->budget--) { s->failed_pc=0x0c0ae506u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae508;
P_0c0ae508: /* original 000b, guest PC 0x0c0ae508 */
if(!s->budget--) { s->failed_pc=0x0c0ae508u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0ae50a: /* original 6ef6, guest PC 0x0c0ae50a */
if(!s->budget--) { s->failed_pc=0x0c0ae50au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae50c;
P_0c0ae50c: /* original 5362, guest PC 0x0c0ae50c */
if(!s->budget--) { s->failed_pc=0x0c0ae50cu; return 0; }
r[3]=read(ram,r[6]+8,4);
goto P_0c0ae50e;
P_0c0ae50e: /* original 7ffc, guest PC 0x0c0ae50e */
if(!s->budget--) { s->failed_pc=0x0c0ae50eu; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0ae510;
P_0c0ae510: /* original 7303, guest PC 0x0c0ae510 */
if(!s->budget--) { s->failed_pc=0x0c0ae510u; return 0; }
r[3]+=0x00000003u;
goto P_0c0ae512;
P_0c0ae512: /* original 6230, guest PC 0x0c0ae512 */
if(!s->budget--) { s->failed_pc=0x0c0ae512u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[2]=tmp;
goto P_0c0ae514;
P_0c0ae514: /* original 2f22, guest PC 0x0c0ae514 */
if(!s->budget--) { s->failed_pc=0x0c0ae514u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c0ae516;
P_0c0ae516: /* original 622b, guest PC 0x0c0ae516 */
if(!s->budget--) { s->failed_pc=0x0c0ae516u; return 0; }
r[2]=0u-r[2];
goto P_0c0ae518;
P_0c0ae518: /* original d720, guest PC 0x0c0ae518 */
if(!s->budget--) { s->failed_pc=0x0c0ae518u; return 0; }
r[7]=read(ram,0x0c0ae59cu,4);
goto P_0c0ae51a;
P_0c0ae51a: /* original 5363, guest PC 0x0c0ae51a */
if(!s->budget--) { s->failed_pc=0x0c0ae51au; return 0; }
r[3]=read(ram,r[6]+12,4);
goto P_0c0ae51c;
P_0c0ae51c: /* original 472d, guest PC 0x0c0ae51c */
if(!s->budget--) { s->failed_pc=0x0c0ae51cu; return 0; }
r[7]=(r[2]&0x80000000u)?((r[2]&31u)?r[7]>>((-r[2])&31u):0):r[7]<<(r[2]&31u);
goto P_0c0ae51e;
P_0c0ae51e: /* original 273b, guest PC 0x0c0ae51e */
if(!s->budget--) { s->failed_pc=0x0c0ae51eu; return 0; }
r[7]|=r[3];
goto P_0c0ae520;
P_0c0ae520: /* original 1673, guest PC 0x0c0ae520 */
if(!s->budget--) { s->failed_pc=0x0c0ae520u; return 0; }
write(ram,r[6]+12,r[7],4);
goto P_0c0ae522;
P_0c0ae522: /* original 5262, guest PC 0x0c0ae522 */
if(!s->budget--) { s->failed_pc=0x0c0ae522u; return 0; }
r[2]=read(ram,r[6]+8,4);
goto P_0c0ae524;
P_0c0ae524: /* original 7204, guest PC 0x0c0ae524 */
if(!s->budget--) { s->failed_pc=0x0c0ae524u; return 0; }
r[2]+=0x00000004u;
goto P_0c0ae526;
P_0c0ae526: /* original 1622, guest PC 0x0c0ae526 */
if(!s->budget--) { s->failed_pc=0x0c0ae526u; return 0; }
write(ram,r[6]+8,r[2],4);
goto P_0c0ae528;
P_0c0ae528: /* original aeb8, guest PC 0x0c0ae528 */
if(!s->budget--) { s->failed_pc=0x0c0ae528u; return 0; }
r[15]+=0x00000004u;
goto P_0c0ae29c;
P_0c0ae52a: /* original 7f04, guest PC 0x0c0ae52a */
if(!s->budget--) { s->failed_pc=0x0c0ae52au; return 0; }
r[15]+=0x00000004u;
return vf3_matrix_family(0x0c0ae52cu,s,ram);
P_0c0ae6f6: /* original 4f22, guest PC 0x0c0ae6f6 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f6u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0ae6f8;
P_0c0ae6f8: /* original 7ff4, guest PC 0x0c0ae6f8 */
if(!s->budget--) { s->failed_pc=0x0c0ae6f8u; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0ae6fa;
P_0c0ae6fa: /* original 2f52, guest PC 0x0c0ae6fa */
if(!s->budget--) { s->failed_pc=0x0c0ae6fau; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0ae6fc;
P_0c0ae6fc: /* original 53d1, guest PC 0x0c0ae6fc */
if(!s->budget--) { s->failed_pc=0x0c0ae6fcu; return 0; }
r[3]=read(ram,r[13]+4,4);
goto P_0c0ae6fe;
P_0c0ae6fe: /* original 62d2, guest PC 0x0c0ae6fe */
if(!s->budget--) { s->failed_pc=0x0c0ae6feu; return 0; }
tmp=read(ram,r[13],4);
r[2]=tmp;
goto P_0c0ae700;
P_0c0ae700: /* original de2e, guest PC 0x0c0ae700 */
if(!s->budget--) { s->failed_pc=0x0c0ae700u; return 0; }
r[14]=read(ram,0x0c0ae7bcu,4);
goto P_0c0ae702;
P_0c0ae702: /* original 3230, guest PC 0x0c0ae702 */
if(!s->budget--) { s->failed_pc=0x0c0ae702u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[3])!=0);
goto P_0c0ae704;
P_0c0ae704: /* original 8f43, guest PC 0x0c0ae704 */
if(!s->budget--) { s->failed_pc=0x0c0ae704u; return 0; }
cond=r[17]&1u;
r[12]=r[4];
if(!cond) { goto P_0c0ae78e; }
goto P_0c0ae708;
P_0c0ae706: /* original 6c43, guest PC 0x0c0ae706 */
if(!s->budget--) { s->failed_pc=0x0c0ae706u; return 0; }
r[12]=r[4];
goto P_0c0ae708;
P_0c0ae708: /* original 61e2, guest PC 0x0c0ae708 */
if(!s->budget--) { s->failed_pc=0x0c0ae708u; return 0; }
tmp=read(ram,r[14],4);
r[1]=tmp;
goto P_0c0ae70a;
P_0c0ae70a: /* original d32d, guest PC 0x0c0ae70a */
if(!s->budget--) { s->failed_pc=0x0c0ae70au; return 0; }
r[3]=read(ram,0x0c0ae7c0u,4);
goto P_0c0ae70c;
P_0c0ae70c: /* original 2138, guest PC 0x0c0ae70c */
if(!s->budget--) { s->failed_pc=0x0c0ae70cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c0ae70e;
P_0c0ae70e: /* original 8b3e, guest PC 0x0c0ae70e */
if(!s->budget--) { s->failed_pc=0x0c0ae70eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae78e; }
goto P_0c0ae710;
P_0c0ae710: /* original 5bd2, guest PC 0x0c0ae710 */
if(!s->budget--) { s->failed_pc=0x0c0ae710u; return 0; }
r[11]=read(ram,r[13]+8,4);
goto P_0c0ae712;
P_0c0ae712: /* original e061, guest PC 0x0c0ae712 */
if(!s->budget--) { s->failed_pc=0x0c0ae712u; return 0; }
r[0]=0x00000061u;
goto P_0c0ae714;
P_0c0ae714: /* original 03cc, guest PC 0x0c0ae714 */
if(!s->budget--) { s->failed_pc=0x0c0ae714u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae716;
P_0c0ae716: /* original 7b03, guest PC 0x0c0ae716 */
if(!s->budget--) { s->failed_pc=0x0c0ae716u; return 0; }
r[11]+=0x00000003u;
goto P_0c0ae718;
P_0c0ae718: /* original 6bb0, guest PC 0x0c0ae718 */
if(!s->budget--) { s->failed_pc=0x0c0ae718u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[11],1);
r[11]=tmp;
goto P_0c0ae71a;
P_0c0ae71a: /* original 633c, guest PC 0x0c0ae71a */
if(!s->budget--) { s->failed_pc=0x0c0ae71au; return 0; }
r[3]=r[3]&255u;
goto P_0c0ae71c;
P_0c0ae71c: /* original 1f31, guest PC 0x0c0ae71c */
if(!s->budget--) { s->failed_pc=0x0c0ae71cu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c0ae71e;
P_0c0ae71e: /* original d22a, guest PC 0x0c0ae71e */
if(!s->budget--) { s->failed_pc=0x0c0ae71eu; return 0; }
r[2]=read(ram,0x0c0ae7c8u,4);
goto P_0c0ae720;
P_0c0ae720: /* original 6bbc, guest PC 0x0c0ae720 */
if(!s->budget--) { s->failed_pc=0x0c0ae720u; return 0; }
r[11]=r[11]&255u;
goto P_0c0ae722;
P_0c0ae722: /* original 69b3, guest PC 0x0c0ae722 */
if(!s->budget--) { s->failed_pc=0x0c0ae722u; return 0; }
r[9]=r[11];
goto P_0c0ae724;
P_0c0ae724: /* original da27, guest PC 0x0c0ae724 */
if(!s->budget--) { s->failed_pc=0x0c0ae724u; return 0; }
r[10]=read(ram,0x0c0ae7c4u,4);
goto P_0c0ae726;
P_0c0ae726: /* original 4908, guest PC 0x0c0ae726 */
if(!s->budget--) { s->failed_pc=0x0c0ae726u; return 0; }
r[9]<<=2;
goto P_0c0ae728;
P_0c0ae728: /* original 6423, guest PC 0x0c0ae728 */
if(!s->budget--) { s->failed_pc=0x0c0ae728u; return 0; }
r[4]=r[2];
goto P_0c0ae72a;
P_0c0ae72a: /* original 1f22, guest PC 0x0c0ae72a */
if(!s->budget--) { s->failed_pc=0x0c0ae72au; return 0; }
write(ram,r[15]+8,r[2],4);
goto P_0c0ae72c;
P_0c0ae72c: /* original d327, guest PC 0x0c0ae72c */
if(!s->budget--) { s->failed_pc=0x0c0ae72cu; return 0; }
r[3]=read(ram,0x0c0ae7ccu,4);
goto P_0c0ae72e;
P_0c0ae72e: /* original 430b, guest PC 0x0c0ae72e */
if(!s->budget--) { s->failed_pc=0x0c0ae72eu; return 0; }
target=r[3];
r[16]=0x0c0ae732u;
r[4]+=0x00000012u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae732u) { target=s->pc; goto dispatch; }
goto P_0c0ae732;
P_0c0ae730: /* original 7412, guest PC 0x0c0ae730 */
if(!s->budget--) { s->failed_pc=0x0c0ae730u; return 0; }
r[4]+=0x00000012u;
goto P_0c0ae732;
P_0c0ae732: /* original 640c, guest PC 0x0c0ae732 */
if(!s->budget--) { s->failed_pc=0x0c0ae732u; return 0; }
r[4]=r[0]&255u;
goto P_0c0ae734;
P_0c0ae734: /* original 6043, guest PC 0x0c0ae734 */
if(!s->budget--) { s->failed_pc=0x0c0ae734u; return 0; }
r[0]=r[4];
goto P_0c0ae736;
P_0c0ae736: /* original 8803, guest PC 0x0c0ae736 */
if(!s->budget--) { s->failed_pc=0x0c0ae736u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0ae738;
P_0c0ae738: /* original 8b00, guest PC 0x0c0ae738 */
if(!s->budget--) { s->failed_pc=0x0c0ae738u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0ae73c; }
goto P_0c0ae73a;
P_0c0ae73a: /* original da25, guest PC 0x0c0ae73a */
if(!s->budget--) { s->failed_pc=0x0c0ae73au; return 0; }
r[10]=read(ram,0x0c0ae7d0u,4);
goto P_0c0ae73c;
P_0c0ae73c: /* original 39ac, guest PC 0x0c0ae73c */
if(!s->budget--) { s->failed_pc=0x0c0ae73cu; return 0; }
r[9]+=r[10];
goto P_0c0ae73e;
P_0c0ae73e: /* original 54f1, guest PC 0x0c0ae73e */
if(!s->budget--) { s->failed_pc=0x0c0ae73eu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c0ae740;
P_0c0ae740: /* original 6592, guest PC 0x0c0ae740 */
if(!s->budget--) { s->failed_pc=0x0c0ae740u; return 0; }
tmp=read(ram,r[9],4);
r[5]=tmp;
goto P_0c0ae742;
P_0c0ae742: /* original 4408, guest PC 0x0c0ae742 */
if(!s->budget--) { s->failed_pc=0x0c0ae742u; return 0; }
r[4]<<=2;
goto P_0c0ae744;
P_0c0ae744: /* original 6a53, guest PC 0x0c0ae744 */
if(!s->budget--) { s->failed_pc=0x0c0ae744u; return 0; }
r[10]=r[5];
goto P_0c0ae746;
P_0c0ae746: /* original 3a4c, guest PC 0x0c0ae746 */
if(!s->budget--) { s->failed_pc=0x0c0ae746u; return 0; }
r[10]+=r[4];
goto P_0c0ae748;
P_0c0ae748: /* original 6aa2, guest PC 0x0c0ae748 */
if(!s->budget--) { s->failed_pc=0x0c0ae748u; return 0; }
tmp=read(ram,r[10],4);
r[10]=tmp;
goto P_0c0ae74a;
P_0c0ae74a: /* original 2aa8, guest PC 0x0c0ae74a */
if(!s->budget--) { s->failed_pc=0x0c0ae74au; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0ae74c;
P_0c0ae74c: /* original 891f, guest PC 0x0c0ae74c */
if(!s->budget--) { s->failed_pc=0x0c0ae74cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae78e; }
goto P_0c0ae74e;
P_0c0ae74e: /* original d421, guest PC 0x0c0ae74e */
if(!s->budget--) { s->failed_pc=0x0c0ae74eu; return 0; }
r[4]=read(ram,0x0c0ae7d4u,4);
goto P_0c0ae750;
P_0c0ae750: /* original 34bc, guest PC 0x0c0ae750 */
if(!s->budget--) { s->failed_pc=0x0c0ae750u; return 0; }
r[4]+=r[11];
goto P_0c0ae752;
P_0c0ae752: /* original 6440, guest PC 0x0c0ae752 */
if(!s->budget--) { s->failed_pc=0x0c0ae752u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0ae754;
P_0c0ae754: /* original 644c, guest PC 0x0c0ae754 */
if(!s->budget--) { s->failed_pc=0x0c0ae754u; return 0; }
r[4]=r[4]&255u;
goto P_0c0ae756;
P_0c0ae756: /* original 2448, guest PC 0x0c0ae756 */
if(!s->budget--) { s->failed_pc=0x0c0ae756u; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0ae758;
P_0c0ae758: /* original 8916, guest PC 0x0c0ae758 */
if(!s->budget--) { s->failed_pc=0x0c0ae758u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0ae788; }
goto P_0c0ae75a;
P_0c0ae75a: /* original 902b, guest PC 0x0c0ae75a */
if(!s->budget--) { s->failed_pc=0x0c0ae75au; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b4u,2);
goto P_0c0ae75c;
P_0c0ae75c: /* original e301, guest PC 0x0c0ae75c */
if(!s->budget--) { s->failed_pc=0x0c0ae75cu; return 0; }
r[3]=0x00000001u;
goto P_0c0ae75e;
P_0c0ae75e: /* original 0e44, guest PC 0x0c0ae75e */
if(!s->budget--) { s->failed_pc=0x0c0ae75eu; return 0; }
write(ram,r[14]+r[0],r[4],1);
goto P_0c0ae760;
P_0c0ae760: /* original 70d4, guest PC 0x0c0ae760 */
if(!s->budget--) { s->failed_pc=0x0c0ae760u; return 0; }
r[0]+=0xffffffd4u;
goto P_0c0ae762;
P_0c0ae762: /* original 05ee, guest PC 0x0c0ae762 */
if(!s->budget--) { s->failed_pc=0x0c0ae762u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0ae764;
P_0c0ae764: /* original e060, guest PC 0x0c0ae764 */
if(!s->budget--) { s->failed_pc=0x0c0ae764u; return 0; }
r[0]=0x00000060u;
goto P_0c0ae766;
P_0c0ae766: /* original 06cc, guest PC 0x0c0ae766 */
if(!s->budget--) { s->failed_pc=0x0c0ae766u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c0ae768;
P_0c0ae768: /* original 7040, guest PC 0x0c0ae768 */
if(!s->budget--) { s->failed_pc=0x0c0ae768u; return 0; }
r[0]+=0x00000040u;
goto P_0c0ae76a;
P_0c0ae76a: /* original d41b, guest PC 0x0c0ae76a */
if(!s->budget--) { s->failed_pc=0x0c0ae76au; return 0; }
r[4]=read(ram,0x0c0ae7d8u,4);
goto P_0c0ae76c;
P_0c0ae76c: /* original 666c, guest PC 0x0c0ae76c */
if(!s->budget--) { s->failed_pc=0x0c0ae76cu; return 0; }
r[6]=r[6]&255u;
goto P_0c0ae76e;
P_0c0ae76e: /* original 666b, guest PC 0x0c0ae76e */
if(!s->budget--) { s->failed_pc=0x0c0ae76eu; return 0; }
r[6]=0u-r[6];
goto P_0c0ae770;
P_0c0ae770: /* original 446d, guest PC 0x0c0ae770 */
if(!s->budget--) { s->failed_pc=0x0c0ae770u; return 0; }
r[4]=(r[6]&0x80000000u)?((r[6]&31u)?r[4]>>((-r[6])&31u):0):r[4]<<(r[6]&31u);
goto P_0c0ae772;
P_0c0ae772: /* original 254b, guest PC 0x0c0ae772 */
if(!s->budget--) { s->failed_pc=0x0c0ae772u; return 0; }
r[5]|=r[4];
goto P_0c0ae774;
P_0c0ae774: /* original 0e56, guest PC 0x0c0ae774 */
if(!s->budget--) { s->failed_pc=0x0c0ae774u; return 0; }
write(ram,r[14]+r[0],r[5],4);
goto P_0c0ae776;
P_0c0ae776: /* original 901e, guest PC 0x0c0ae776 */
if(!s->budget--) { s->failed_pc=0x0c0ae776u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b6u,2);
goto P_0c0ae778;
P_0c0ae778: /* original 0e36, guest PC 0x0c0ae778 */
if(!s->budget--) { s->failed_pc=0x0c0ae778u; return 0; }
write(ram,r[14]+r[0],r[3],4);
goto P_0c0ae77a;
P_0c0ae77a: /* original e054, guest PC 0x0c0ae77a */
if(!s->budget--) { s->failed_pc=0x0c0ae77au; return 0; }
r[0]=0x00000054u;
goto P_0c0ae77c;
P_0c0ae77c: /* original 02ce, guest PC 0x0c0ae77c */
if(!s->budget--) { s->failed_pc=0x0c0ae77cu; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0ae77e;
P_0c0ae77e: /* original e022, guest PC 0x0c0ae77e */
if(!s->budget--) { s->failed_pc=0x0c0ae77eu; return 0; }
r[0]=0x00000022u;
goto P_0c0ae780;
P_0c0ae780: /* original 032d, guest PC 0x0c0ae780 */
if(!s->budget--) { s->failed_pc=0x0c0ae780u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c0ae782;
P_0c0ae782: /* original 9019, guest PC 0x0c0ae782 */
if(!s->budget--) { s->failed_pc=0x0c0ae782u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0ae7b8u,2);
goto P_0c0ae784;
P_0c0ae784: /* original 7308, guest PC 0x0c0ae784 */
if(!s->budget--) { s->failed_pc=0x0c0ae784u; return 0; }
r[3]+=0x00000008u;
goto P_0c0ae786;
P_0c0ae786: /* original 0c35, guest PC 0x0c0ae786 */
if(!s->budget--) { s->failed_pc=0x0c0ae786u; return 0; }
write(ram,r[12]+r[0],r[3],2);
goto P_0c0ae788;
P_0c0ae788: /* original d314, guest PC 0x0c0ae788 */
if(!s->budget--) { s->failed_pc=0x0c0ae788u; return 0; }
r[3]=read(ram,0x0c0ae7dcu,4);
goto P_0c0ae78a;
P_0c0ae78a: /* original 430b, guest PC 0x0c0ae78a */
if(!s->budget--) { s->failed_pc=0x0c0ae78au; return 0; }
target=r[3];
r[16]=0x0c0ae78eu;
r[4]=r[10];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0ae78eu) { target=s->pc; goto dispatch; }
goto P_0c0ae78e;
P_0c0ae78c: /* original 64a3, guest PC 0x0c0ae78c */
if(!s->budget--) { s->failed_pc=0x0c0ae78cu; return 0; }
r[4]=r[10];
goto P_0c0ae78e;
P_0c0ae78e: /* original 52d2, guest PC 0x0c0ae78e */
if(!s->budget--) { s->failed_pc=0x0c0ae78eu; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c0ae790;
P_0c0ae790: /* original 64c3, guest PC 0x0c0ae790 */
if(!s->budget--) { s->failed_pc=0x0c0ae790u; return 0; }
r[4]=r[12];
goto P_0c0ae792;
P_0c0ae792: /* original 66d3, guest PC 0x0c0ae792 */
if(!s->budget--) { s->failed_pc=0x0c0ae792u; return 0; }
r[6]=r[13];
goto P_0c0ae794;
P_0c0ae794: /* original 7204, guest PC 0x0c0ae794 */
if(!s->budget--) { s->failed_pc=0x0c0ae794u; return 0; }
r[2]+=0x00000004u;
goto P_0c0ae796;
P_0c0ae796: /* original 1d22, guest PC 0x0c0ae796 */
if(!s->budget--) { s->failed_pc=0x0c0ae796u; return 0; }
write(ram,r[13]+8,r[2],4);
goto P_0c0ae798;
P_0c0ae798: /* original 65f2, guest PC 0x0c0ae798 */
if(!s->budget--) { s->failed_pc=0x0c0ae798u; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0ae79a;
P_0c0ae79a: /* original 7f0c, guest PC 0x0c0ae79a */
if(!s->budget--) { s->failed_pc=0x0c0ae79au; return 0; }
r[15]+=0x0000000cu;
goto P_0c0ae79c;
P_0c0ae79c: /* original 4f26, guest PC 0x0c0ae79c */
if(!s->budget--) { s->failed_pc=0x0c0ae79cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0ae79e;
P_0c0ae79e: /* original 69f6, guest PC 0x0c0ae79e */
if(!s->budget--) { s->failed_pc=0x0c0ae79eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0ae7a0;
P_0c0ae7a0: /* original 6af6, guest PC 0x0c0ae7a0 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0ae7a2;
P_0c0ae7a2: /* original 6bf6, guest PC 0x0c0ae7a2 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0ae7a4;
P_0c0ae7a4: /* original 6cf6, guest PC 0x0c0ae7a4 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0ae7a6;
P_0c0ae7a6: /* original 6df6, guest PC 0x0c0ae7a6 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0ae7a8;
P_0c0ae7a8: /* original ad78, guest PC 0x0c0ae7a8 */
if(!s->budget--) { s->failed_pc=0x0c0ae7a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0ae7aa: /* original 6ef6, guest PC 0x0c0ae7aa */
if(!s->budget--) { s->failed_pc=0x0c0ae7aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0ae7acu,s,ram);
P_0c0aea68: /* original 4f22, guest PC 0x0c0aea68 */
if(!s->budget--) { s->failed_pc=0x0c0aea68u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0aea6a;
P_0c0aea6a: /* original 7ffc, guest PC 0x0c0aea6a */
if(!s->budget--) { s->failed_pc=0x0c0aea6au; return 0; }
r[15]+=0xfffffffcu;
goto P_0c0aea6c;
P_0c0aea6c: /* original 2f52, guest PC 0x0c0aea6c */
if(!s->budget--) { s->failed_pc=0x0c0aea6cu; return 0; }
write(ram,r[15],r[5],4);
goto P_0c0aea6e;
P_0c0aea6e: /* original 54d2, guest PC 0x0c0aea6e */
if(!s->budget--) { s->failed_pc=0x0c0aea6eu; return 0; }
r[4]=read(ram,r[13]+8,4);
goto P_0c0aea70;
P_0c0aea70: /* original 05ee, guest PC 0x0c0aea70 */
if(!s->budget--) { s->failed_pc=0x0c0aea70u; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aea72;
P_0c0aea72: /* original 7403, guest PC 0x0c0aea72 */
if(!s->budget--) { s->failed_pc=0x0c0aea72u; return 0; }
r[4]+=0x00000003u;
goto P_0c0aea74;
P_0c0aea74: /* original dc1b, guest PC 0x0c0aea74 */
if(!s->budget--) { s->failed_pc=0x0c0aea74u; return 0; }
r[12]=read(ram,0x0c0aeae4u,4);
goto P_0c0aea76;
P_0c0aea76: /* original 6440, guest PC 0x0c0aea76 */
if(!s->budget--) { s->failed_pc=0x0c0aea76u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[4]=tmp;
goto P_0c0aea78;
P_0c0aea78: /* original 644c, guest PC 0x0c0aea78 */
if(!s->budget--) { s->failed_pc=0x0c0aea78u; return 0; }
r[4]=r[4]&255u;
goto P_0c0aea7a;
P_0c0aea7a: /* original 6043, guest PC 0x0c0aea7a */
if(!s->budget--) { s->failed_pc=0x0c0aea7au; return 0; }
r[0]=r[4];
goto P_0c0aea7c;
P_0c0aea7c: /* original 880a, guest PC 0x0c0aea7c */
if(!s->budget--) { s->failed_pc=0x0c0aea7cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0aea7e;
P_0c0aea7e: /* original 891c, guest PC 0x0c0aea7e */
if(!s->budget--) { s->failed_pc=0x0c0aea7eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aeaba; }
goto P_0c0aea80;
P_0c0aea80: /* original 6043, guest PC 0x0c0aea80 */
if(!s->budget--) { s->failed_pc=0x0c0aea80u; return 0; }
r[0]=r[4];
goto P_0c0aea82;
P_0c0aea82: /* original 880b, guest PC 0x0c0aea82 */
if(!s->budget--) { s->failed_pc=0x0c0aea82u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0aea84;
P_0c0aea84: /* original 891f, guest PC 0x0c0aea84 */
if(!s->budget--) { s->failed_pc=0x0c0aea84u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aeac6; }
goto P_0c0aea86;
P_0c0aea86: /* original 6043, guest PC 0x0c0aea86 */
if(!s->budget--) { s->failed_pc=0x0c0aea86u; return 0; }
r[0]=r[4];
goto P_0c0aea88;
P_0c0aea88: /* original 880c, guest PC 0x0c0aea88 */
if(!s->budget--) { s->failed_pc=0x0c0aea88u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0aea8a;
P_0c0aea8a: /* original 8923, guest PC 0x0c0aea8a */
if(!s->budget--) { s->failed_pc=0x0c0aea8au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aead4; }
goto P_0c0aea8c;
P_0c0aea8c: /* original 6043, guest PC 0x0c0aea8c */
if(!s->budget--) { s->failed_pc=0x0c0aea8cu; return 0; }
r[0]=r[4];
goto P_0c0aea8e;
P_0c0aea8e: /* original 880d, guest PC 0x0c0aea8e */
if(!s->budget--) { s->failed_pc=0x0c0aea8eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000du)!=0);
goto P_0c0aea90;
P_0c0aea90: /* original 8936, guest PC 0x0c0aea90 */
if(!s->budget--) { s->failed_pc=0x0c0aea90u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0aeb00; }
goto P_0c0aea92;
P_0c0aea92: /* original 6043, guest PC 0x0c0aea92 */
if(!s->budget--) { s->failed_pc=0x0c0aea92u; return 0; }
r[0]=r[4];
goto P_0c0aea94;
P_0c0aea94: /* original 8808, guest PC 0x0c0aea94 */
if(!s->budget--) { s->failed_pc=0x0c0aea94u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0aea96;
P_0c0aea96: /* original 8b0d, guest PC 0x0c0aea96 */
if(!s->budget--) { s->failed_pc=0x0c0aea96u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeab4; }
goto P_0c0aea98;
P_0c0aea98: /* original 6453, guest PC 0x0c0aea98 */
if(!s->budget--) { s->failed_pc=0x0c0aea98u; return 0; }
r[4]=r[5];
goto P_0c0aea9a;
P_0c0aea9a: /* original 7428, guest PC 0x0c0aea9a */
if(!s->budget--) { s->failed_pc=0x0c0aea9au; return 0; }
r[4]+=0x00000028u;
goto P_0c0aea9c;
P_0c0aea9c: /* original 8441, guest PC 0x0c0aea9c */
if(!s->budget--) { s->failed_pc=0x0c0aea9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0aea9e;
P_0c0aea9e: /* original d416, guest PC 0x0c0aea9e */
if(!s->budget--) { s->failed_pc=0x0c0aea9eu; return 0; }
r[4]=read(ram,0x0c0aeaf8u,4);
goto P_0c0aeaa0;
P_0c0aeaa0: /* original 600c, guest PC 0x0c0aeaa0 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0aeaa2;
P_0c0aeaa2: /* original 4018, guest PC 0x0c0aeaa2 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa2u; return 0; }
r[0]<<=8;
goto P_0c0aeaa4;
P_0c0aeaa4: /* original 2409, guest PC 0x0c0aeaa4 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa4u; return 0; }
r[4]&=r[0];
goto P_0c0aeaa6;
P_0c0aeaa6: /* original e028, guest PC 0x0c0aeaa6 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa6u; return 0; }
r[0]=0x00000028u;
goto P_0c0aeaa8;
P_0c0aeaa8: /* original 035c, guest PC 0x0c0aeaa8 */
if(!s->budget--) { s->failed_pc=0x0c0aeaa8u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c0aeaaa;
P_0c0aeaaa: /* original 633c, guest PC 0x0c0aeaaa */
if(!s->budget--) { s->failed_pc=0x0c0aeaaau; return 0; }
r[3]=r[3]&255u;
goto P_0c0aeaac;
P_0c0aeaac: /* original 243b, guest PC 0x0c0aeaac */
if(!s->budget--) { s->failed_pc=0x0c0aeaacu; return 0; }
r[4]|=r[3];
goto P_0c0aeaae;
P_0c0aeaae: /* original 6043, guest PC 0x0c0aeaae */
if(!s->budget--) { s->failed_pc=0x0c0aeaaeu; return 0; }
r[0]=r[4];
goto P_0c0aeab0;
P_0c0aeab0: /* original 88ff, guest PC 0x0c0aeab0 */
if(!s->budget--) { s->failed_pc=0x0c0aeab0u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0aeab2;
P_0c0aeab2: /* original 8b39, guest PC 0x0c0aeab2 */
if(!s->budget--) { s->failed_pc=0x0c0aeab2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeb28; }
goto P_0c0aeab4;
P_0c0aeab4: /* original e022, guest PC 0x0c0aeab4 */
if(!s->budget--) { s->failed_pc=0x0c0aeab4u; return 0; }
r[0]=0x00000022u;
goto P_0c0aeab6;
P_0c0aeab6: /* original a037, guest PC 0x0c0aeab6 */
if(!s->budget--) { s->failed_pc=0x0c0aeab6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb28;
P_0c0aeab8: /* original 045d, guest PC 0x0c0aeab8 */
if(!s->budget--) { s->failed_pc=0x0c0aeab8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeaba;
P_0c0aeaba: /* original d210, guest PC 0x0c0aeaba */
if(!s->budget--) { s->failed_pc=0x0c0aeabau; return 0; }
r[2]=read(ram,0x0c0aeafcu,4);
goto P_0c0aeabc;
P_0c0aeabc: /* original 420b, guest PC 0x0c0aeabc */
if(!s->budget--) { s->failed_pc=0x0c0aeabcu; return 0; }
target=r[2];
r[16]=0x0c0aeac0u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeac0u) { target=s->pc; goto dispatch; }
goto P_0c0aeac0;
P_0c0aeabe: /* original 64e3, guest PC 0x0c0aeabe */
if(!s->budget--) { s->failed_pc=0x0c0aeabeu; return 0; }
r[4]=r[14];
goto P_0c0aeac0;
P_0c0aeac0: /* original 6503, guest PC 0x0c0aeac0 */
if(!s->budget--) { s->failed_pc=0x0c0aeac0u; return 0; }
r[5]=r[0];
goto P_0c0aeac2;
P_0c0aeac2: /* original a005, guest PC 0x0c0aeac2 */
if(!s->budget--) { s->failed_pc=0x0c0aeac2u; return 0; }
r[0]=0x0000002au;
goto P_0c0aead0;
P_0c0aeac4: /* original e02a, guest PC 0x0c0aeac4 */
if(!s->budget--) { s->failed_pc=0x0c0aeac4u; return 0; }
r[0]=0x0000002au;
goto P_0c0aeac6;
P_0c0aeac6: /* original d20d, guest PC 0x0c0aeac6 */
if(!s->budget--) { s->failed_pc=0x0c0aeac6u; return 0; }
r[2]=read(ram,0x0c0aeafcu,4);
goto P_0c0aeac8;
P_0c0aeac8: /* original 420b, guest PC 0x0c0aeac8 */
if(!s->budget--) { s->failed_pc=0x0c0aeac8u; return 0; }
target=r[2];
r[16]=0x0c0aeaccu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeaccu) { target=s->pc; goto dispatch; }
goto P_0c0aeacc;
P_0c0aeaca: /* original 64e3, guest PC 0x0c0aeaca */
if(!s->budget--) { s->failed_pc=0x0c0aeacau; return 0; }
r[4]=r[14];
goto P_0c0aeacc;
P_0c0aeacc: /* original 6503, guest PC 0x0c0aeacc */
if(!s->budget--) { s->failed_pc=0x0c0aeaccu; return 0; }
r[5]=r[0];
goto P_0c0aeace;
P_0c0aeace: /* original e02c, guest PC 0x0c0aeace */
if(!s->budget--) { s->failed_pc=0x0c0aeaceu; return 0; }
r[0]=0x0000002cu;
goto P_0c0aead0;
P_0c0aead0: /* original a01c, guest PC 0x0c0aead0 */
if(!s->budget--) { s->failed_pc=0x0c0aead0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb0c;
P_0c0aead2: /* original 045d, guest PC 0x0c0aead2 */
if(!s->budget--) { s->failed_pc=0x0c0aead2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aead4;
P_0c0aead4: /* original d309, guest PC 0x0c0aead4 */
if(!s->budget--) { s->failed_pc=0x0c0aead4u; return 0; }
r[3]=read(ram,0x0c0aeafcu,4);
goto P_0c0aead6;
P_0c0aead6: /* original 430b, guest PC 0x0c0aead6 */
if(!s->budget--) { s->failed_pc=0x0c0aead6u; return 0; }
target=r[3];
r[16]=0x0c0aeadau;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeadau) { target=s->pc; goto dispatch; }
goto P_0c0aeada;
P_0c0aead8: /* original 64e3, guest PC 0x0c0aead8 */
if(!s->budget--) { s->failed_pc=0x0c0aead8u; return 0; }
r[4]=r[14];
goto P_0c0aeada;
P_0c0aeada: /* original 6503, guest PC 0x0c0aeada */
if(!s->budget--) { s->failed_pc=0x0c0aeadau; return 0; }
r[5]=r[0];
goto P_0c0aeadc;
P_0c0aeadc: /* original e02e, guest PC 0x0c0aeadc */
if(!s->budget--) { s->failed_pc=0x0c0aeadcu; return 0; }
r[0]=0x0000002eu;
goto P_0c0aeade;
P_0c0aeade: /* original a015, guest PC 0x0c0aeade */
if(!s->budget--) { s->failed_pc=0x0c0aeadeu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb0c;
P_0c0aeae0: /* original 045d, guest PC 0x0c0aeae0 */
if(!s->budget--) { s->failed_pc=0x0c0aeae0u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
return vf3_matrix_family(0x0c0aeae2u,s,ram);
P_0c0aeb00: /* original d245, guest PC 0x0c0aeb00 */
if(!s->budget--) { s->failed_pc=0x0c0aeb00u; return 0; }
r[2]=read(ram,0x0c0aec18u,4);
goto P_0c0aeb02;
P_0c0aeb02: /* original 420b, guest PC 0x0c0aeb02 */
if(!s->budget--) { s->failed_pc=0x0c0aeb02u; return 0; }
target=r[2];
r[16]=0x0c0aeb06u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0aeb06u) { target=s->pc; goto dispatch; }
goto P_0c0aeb06;
P_0c0aeb04: /* original 64e3, guest PC 0x0c0aeb04 */
if(!s->budget--) { s->failed_pc=0x0c0aeb04u; return 0; }
r[4]=r[14];
goto P_0c0aeb06;
P_0c0aeb06: /* original 6503, guest PC 0x0c0aeb06 */
if(!s->budget--) { s->failed_pc=0x0c0aeb06u; return 0; }
r[5]=r[0];
goto P_0c0aeb08;
P_0c0aeb08: /* original e030, guest PC 0x0c0aeb08 */
if(!s->budget--) { s->failed_pc=0x0c0aeb08u; return 0; }
r[0]=0x00000030u;
goto P_0c0aeb0a;
P_0c0aeb0a: /* original 045d, guest PC 0x0c0aeb0a */
if(!s->budget--) { s->failed_pc=0x0c0aeb0au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[5]+r[0],2);
goto P_0c0aeb0c;
P_0c0aeb0c: /* original e054, guest PC 0x0c0aeb0c */
if(!s->budget--) { s->failed_pc=0x0c0aeb0cu; return 0; }
r[0]=0x00000054u;
goto P_0c0aeb0e;
P_0c0aeb0e: /* original 05ee, guest PC 0x0c0aeb0e */
if(!s->budget--) { s->failed_pc=0x0c0aeb0eu; return 0; }
r[5]=read(ram,r[14]+r[0],4);
goto P_0c0aeb10;
P_0c0aeb10: /* original 7044, guest PC 0x0c0aeb10 */
if(!s->budget--) { s->failed_pc=0x0c0aeb10u; return 0; }
r[0]+=0x00000044u;
goto P_0c0aeb12;
P_0c0aeb12: /* original 07ce, guest PC 0x0c0aeb12 */
if(!s->budget--) { s->failed_pc=0x0c0aeb12u; return 0; }
r[7]=read(ram,r[12]+r[0],4);
goto P_0c0aeb14;
P_0c0aeb14: /* original e061, guest PC 0x0c0aeb14 */
if(!s->budget--) { s->failed_pc=0x0c0aeb14u; return 0; }
r[0]=0x00000061u;
goto P_0c0aeb16;
P_0c0aeb16: /* original 06ec, guest PC 0x0c0aeb16 */
if(!s->budget--) { s->failed_pc=0x0c0aeb16u; return 0; }
r[6]=(uint32_t)(int32_t)(int8_t)read(ram,r[14]+r[0],1);
goto P_0c0aeb18;
P_0c0aeb18: /* original 606c, guest PC 0x0c0aeb18 */
if(!s->budget--) { s->failed_pc=0x0c0aeb18u; return 0; }
r[0]=r[6]&255u;
goto P_0c0aeb1a;
P_0c0aeb1a: /* original 8803, guest PC 0x0c0aeb1a */
if(!s->budget--) { s->failed_pc=0x0c0aeb1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0aeb1c;
P_0c0aeb1c: /* original 8f04, guest PC 0x0c0aeb1c */
if(!s->budget--) { s->failed_pc=0x0c0aeb1cu; return 0; }
cond=r[17]&1u;
r[6]=r[0];
if(!cond) { goto P_0c0aeb28; }
goto P_0c0aeb20;
P_0c0aeb1e: /* original 6603, guest PC 0x0c0aeb1e */
if(!s->budget--) { s->failed_pc=0x0c0aeb1eu; return 0; }
r[6]=r[0];
goto P_0c0aeb20;
P_0c0aeb20: /* original d33e, guest PC 0x0c0aeb20 */
if(!s->budget--) { s->failed_pc=0x0c0aeb20u; return 0; }
r[3]=read(ram,0x0c0aec1cu,4);
goto P_0c0aeb22;
P_0c0aeb22: /* original 476c, guest PC 0x0c0aeb22 */
if(!s->budget--) { s->failed_pc=0x0c0aeb22u; return 0; }
r[7]=(r[6]&0x80000000u)?((r[6]&31u)?(uint32_t)((int32_t)r[7]>>((-r[6])&31u)):((int32_t)r[7]<0?0xffffffffu:0)):r[7]<<(r[6]&31u);
goto P_0c0aeb24;
P_0c0aeb24: /* original 2738, guest PC 0x0c0aeb24 */
if(!s->budget--) { s->failed_pc=0x0c0aeb24u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[3])==0)!=0);
goto P_0c0aeb26;
P_0c0aeb26: /* original 8bc5, guest PC 0x0c0aeb26 */
if(!s->budget--) { s->failed_pc=0x0c0aeb26u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeab4; }
goto P_0c0aeb28;
P_0c0aeb28: /* original 9071, guest PC 0x0c0aeb28 */
if(!s->budget--) { s->failed_pc=0x0c0aeb28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec0eu,2);
goto P_0c0aeb2a;
P_0c0aeb2a: /* original 02ce, guest PC 0x0c0aeb2a */
if(!s->budget--) { s->failed_pc=0x0c0aeb2au; return 0; }
r[2]=read(ram,r[12]+r[0],4);
goto P_0c0aeb2c;
P_0c0aeb2c: /* original 2228, guest PC 0x0c0aeb2c */
if(!s->budget--) { s->failed_pc=0x0c0aeb2cu; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0aeb2e;
P_0c0aeb2e: /* original 8b01, guest PC 0x0c0aeb2e */
if(!s->budget--) { s->failed_pc=0x0c0aeb2eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0aeb34; }
goto P_0c0aeb30;
P_0c0aeb30: /* original 906e, guest PC 0x0c0aeb30 */
if(!s->budget--) { s->failed_pc=0x0c0aeb30u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0aec10u,2);
goto P_0c0aeb32;
P_0c0aeb32: /* original 0e45, guest PC 0x0c0aeb32 */
if(!s->budget--) { s->failed_pc=0x0c0aeb32u; return 0; }
write(ram,r[14]+r[0],r[4],2);
goto P_0c0aeb34;
P_0c0aeb34: /* original 53d2, guest PC 0x0c0aeb34 */
if(!s->budget--) { s->failed_pc=0x0c0aeb34u; return 0; }
r[3]=read(ram,r[13]+8,4);
goto P_0c0aeb36;
P_0c0aeb36: /* original 66d3, guest PC 0x0c0aeb36 */
if(!s->budget--) { s->failed_pc=0x0c0aeb36u; return 0; }
r[6]=r[13];
goto P_0c0aeb38;
P_0c0aeb38: /* original 64e3, guest PC 0x0c0aeb38 */
if(!s->budget--) { s->failed_pc=0x0c0aeb38u; return 0; }
r[4]=r[14];
goto P_0c0aeb3a;
P_0c0aeb3a: /* original 7304, guest PC 0x0c0aeb3a */
if(!s->budget--) { s->failed_pc=0x0c0aeb3au; return 0; }
r[3]+=0x00000004u;
goto P_0c0aeb3c;
P_0c0aeb3c: /* original 1d32, guest PC 0x0c0aeb3c */
if(!s->budget--) { s->failed_pc=0x0c0aeb3cu; return 0; }
write(ram,r[13]+8,r[3],4);
goto P_0c0aeb3e;
P_0c0aeb3e: /* original 65f2, guest PC 0x0c0aeb3e */
if(!s->budget--) { s->failed_pc=0x0c0aeb3eu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0aeb40;
P_0c0aeb40: /* original 7f04, guest PC 0x0c0aeb40 */
if(!s->budget--) { s->failed_pc=0x0c0aeb40u; return 0; }
r[15]+=0x00000004u;
goto P_0c0aeb42;
P_0c0aeb42: /* original 4f26, guest PC 0x0c0aeb42 */
if(!s->budget--) { s->failed_pc=0x0c0aeb42u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0aeb44;
P_0c0aeb44: /* original 6cf6, guest PC 0x0c0aeb44 */
if(!s->budget--) { s->failed_pc=0x0c0aeb44u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0aeb46;
P_0c0aeb46: /* original 6df6, guest PC 0x0c0aeb46 */
if(!s->budget--) { s->failed_pc=0x0c0aeb46u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0aeb48;
P_0c0aeb48: /* original aba8, guest PC 0x0c0aeb48 */
if(!s->budget--) { s->failed_pc=0x0c0aeb48u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0ae29c;
P_0c0aeb4a: /* original 6ef6, guest PC 0x0c0aeb4a */
if(!s->budget--) { s->failed_pc=0x0c0aeb4au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0aeb4cu,s,ram);
P_0c0af9e4: /* original 4f22, guest PC 0x0c0af9e4 */
if(!s->budget--) { s->failed_pc=0x0c0af9e4u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0af9e6;
P_0c0af9e6: /* original d23b, guest PC 0x0c0af9e6 */
if(!s->budget--) { s->failed_pc=0x0c0af9e6u; return 0; }
r[2]=read(ram,0x0c0afad4u,4);
goto P_0c0af9e8;
P_0c0af9e8: /* original 01ee, guest PC 0x0c0af9e8 */
if(!s->budget--) { s->failed_pc=0x0c0af9e8u; return 0; }
r[1]=read(ram,r[14]+r[0],4);
goto P_0c0af9ea;
P_0c0af9ea: /* original 6c32, guest PC 0x0c0af9ea */
if(!s->budget--) { s->failed_pc=0x0c0af9eau; return 0; }
tmp=read(ram,r[3],4);
r[12]=tmp;
goto P_0c0af9ec;
P_0c0af9ec: /* original 7ff8, guest PC 0x0c0af9ec */
if(!s->budget--) { s->failed_pc=0x0c0af9ecu; return 0; }
r[15]+=0xfffffff8u;
goto P_0c0af9ee;
P_0c0af9ee: /* original 2128, guest PC 0x0c0af9ee */
if(!s->budget--) { s->failed_pc=0x0c0af9eeu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[2])==0)!=0);
goto P_0c0af9f0;
P_0c0af9f0: /* original 8d05, guest PC 0x0c0af9f0 */
if(!s->budget--) { s->failed_pc=0x0c0af9f0u; return 0; }
cond=r[17]&1u;
r[11]=r[11]&65535u;
if(cond) { goto P_0c0af9fe; }
goto P_0c0af9f4;
P_0c0af9f2: /* original 6bbd, guest PC 0x0c0af9f2 */
if(!s->budget--) { s->failed_pc=0x0c0af9f2u; return 0; }
r[11]=r[11]&65535u;
goto P_0c0af9f4;
P_0c0af9f4: /* original 9062, guest PC 0x0c0af9f4 */
if(!s->budget--) { s->failed_pc=0x0c0af9f4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabcu,2);
goto P_0c0af9f6;
P_0c0af9f6: /* original 03ed, guest PC 0x0c0af9f6 */
if(!s->budget--) { s->failed_pc=0x0c0af9f6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0af9f8;
P_0c0af9f8: /* original 633d, guest PC 0x0c0af9f8 */
if(!s->budget--) { s->failed_pc=0x0c0af9f8u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0af9fa;
P_0c0af9fa: /* original 3b30, guest PC 0x0c0af9fa */
if(!s->budget--) { s->failed_pc=0x0c0af9fau; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[3])!=0);
goto P_0c0af9fc;
P_0c0af9fc: /* original 8978, guest PC 0x0c0af9fc */
if(!s->budget--) { s->failed_pc=0x0c0af9fcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afaf0; }
goto P_0c0af9fe;
P_0c0af9fe: /* original e050, guest PC 0x0c0af9fe */
if(!s->budget--) { s->failed_pc=0x0c0af9feu; return 0; }
r[0]=0x00000050u;
goto P_0c0afa00;
P_0c0afa00: /* original d335, guest PC 0x0c0afa00 */
if(!s->budget--) { s->failed_pc=0x0c0afa00u; return 0; }
r[3]=read(ram,0x0c0afad8u,4);
goto P_0c0afa02;
P_0c0afa02: /* original 02ee, guest PC 0x0c0afa02 */
if(!s->budget--) { s->failed_pc=0x0c0afa02u; return 0; }
r[2]=read(ram,r[14]+r[0],4);
goto P_0c0afa04;
P_0c0afa04: /* original 2238, guest PC 0x0c0afa04 */
if(!s->budget--) { s->failed_pc=0x0c0afa04u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0afa06;
P_0c0afa06: /* original 8901, guest PC 0x0c0afa06 */
if(!s->budget--) { s->failed_pc=0x0c0afa06u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afa0c; }
goto P_0c0afa08;
P_0c0afa08: /* original a083, guest PC 0x0c0afa08 */
if(!s->budget--) { s->failed_pc=0x0c0afa08u; return 0; }
goto P_0c0afb12;
P_0c0afa0a: /* original 0009, guest PC 0x0c0afa0a */
if(!s->budget--) { s->failed_pc=0x0c0afa0au; return 0; }
goto P_0c0afa0c;
P_0c0afa0c: /* original 61f3, guest PC 0x0c0afa0c */
if(!s->budget--) { s->failed_pc=0x0c0afa0cu; return 0; }
r[1]=r[15];
goto P_0c0afa0e;
P_0c0afa0e: /* original 7104, guest PC 0x0c0afa0e */
if(!s->budget--) { s->failed_pc=0x0c0afa0eu; return 0; }
r[1]+=0x00000004u;
goto P_0c0afa10;
P_0c0afa10: /* original e300, guest PC 0x0c0afa10 */
if(!s->budget--) { s->failed_pc=0x0c0afa10u; return 0; }
r[3]=0x00000000u;
goto P_0c0afa12;
P_0c0afa12: /* original 2f16, guest PC 0x0c0afa12 */
if(!s->budget--) { s->failed_pc=0x0c0afa12u; return 0; }
r[15]-=4; write(ram,r[15],r[1],4);
goto P_0c0afa14;
P_0c0afa14: /* original 2f36, guest PC 0x0c0afa14 */
if(!s->budget--) { s->failed_pc=0x0c0afa14u; return 0; }
r[15]-=4; write(ram,r[15],r[3],4);
goto P_0c0afa16;
P_0c0afa16: /* original 65e3, guest PC 0x0c0afa16 */
if(!s->budget--) { s->failed_pc=0x0c0afa16u; return 0; }
r[5]=r[14];
goto P_0c0afa18;
P_0c0afa18: /* original d230, guest PC 0x0c0afa18 */
if(!s->budget--) { s->failed_pc=0x0c0afa18u; return 0; }
r[2]=read(ram,0x0c0afadcu,4);
goto P_0c0afa1a;
P_0c0afa1a: /* original 67f3, guest PC 0x0c0afa1a */
if(!s->budget--) { s->failed_pc=0x0c0afa1au; return 0; }
r[7]=r[15];
goto P_0c0afa1c;
P_0c0afa1c: /* original 7708, guest PC 0x0c0afa1c */
if(!s->budget--) { s->failed_pc=0x0c0afa1cu; return 0; }
r[7]+=0x00000008u;
goto P_0c0afa1e;
P_0c0afa1e: /* original 6633, guest PC 0x0c0afa1e */
if(!s->budget--) { s->failed_pc=0x0c0afa1eu; return 0; }
r[6]=r[3];
goto P_0c0afa20;
P_0c0afa20: /* original 420b, guest PC 0x0c0afa20 */
if(!s->budget--) { s->failed_pc=0x0c0afa20u; return 0; }
target=r[2];
r[16]=0x0c0afa24u;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0afa24u) { target=s->pc; goto dispatch; }
goto P_0c0afa24;
P_0c0afa22: /* original 64d3, guest PC 0x0c0afa22 */
if(!s->budget--) { s->failed_pc=0x0c0afa22u; return 0; }
r[4]=r[13];
goto P_0c0afa24;
P_0c0afa24: /* original 7f08, guest PC 0x0c0afa24 */
if(!s->budget--) { s->failed_pc=0x0c0afa24u; return 0; }
r[15]+=0x00000008u;
goto P_0c0afa26;
P_0c0afa26: /* original 63f2, guest PC 0x0c0afa26 */
if(!s->budget--) { s->failed_pc=0x0c0afa26u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c0afa28;
P_0c0afa28: /* original 2338, guest PC 0x0c0afa28 */
if(!s->budget--) { s->failed_pc=0x0c0afa28u; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0afa2a;
P_0c0afa2a: /* original 8972, guest PC 0x0c0afa2a */
if(!s->budget--) { s->failed_pc=0x0c0afa2au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afb12; }
goto P_0c0afa2c;
P_0c0afa2c: /* original 64f2, guest PC 0x0c0afa2c */
if(!s->budget--) { s->failed_pc=0x0c0afa2cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0afa2e;
P_0c0afa2e: /* original 9346, guest PC 0x0c0afa2e */
if(!s->budget--) { s->failed_pc=0x0c0afa2eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabeu,2);
goto P_0c0afa30;
P_0c0afa30: /* original d22b, guest PC 0x0c0afa30 */
if(!s->budget--) { s->failed_pc=0x0c0afa30u; return 0; }
r[2]=read(ram,0x0c0afae0u,4);
goto P_0c0afa32;
P_0c0afa32: /* original 2439, guest PC 0x0c0afa32 */
if(!s->budget--) { s->failed_pc=0x0c0afa32u; return 0; }
r[4]&=r[3];
goto P_0c0afa34;
P_0c0afa34: /* original d12b, guest PC 0x0c0afa34 */
if(!s->budget--) { s->failed_pc=0x0c0afa34u; return 0; }
r[1]=read(ram,0x0c0afae4u,4);
goto P_0c0afa36;
P_0c0afa36: /* original 6043, guest PC 0x0c0afa36 */
if(!s->budget--) { s->failed_pc=0x0c0afa36u; return 0; }
r[0]=r[4];
goto P_0c0afa38;
P_0c0afa38: /* original 70ff, guest PC 0x0c0afa38 */
if(!s->budget--) { s->failed_pc=0x0c0afa38u; return 0; }
r[0]+=0xffffffffu;
goto P_0c0afa3a;
P_0c0afa3a: /* original 4008, guest PC 0x0c0afa3a */
if(!s->budget--) { s->failed_pc=0x0c0afa3au; return 0; }
r[0]<<=2;
goto P_0c0afa3c;
P_0c0afa3c: /* original 04ce, guest PC 0x0c0afa3c */
if(!s->budget--) { s->failed_pc=0x0c0afa3cu; return 0; }
r[4]=read(ram,r[12]+r[0],4);
goto P_0c0afa3e;
P_0c0afa3e: /* original 34cc, guest PC 0x0c0afa3e */
if(!s->budget--) { s->failed_pc=0x0c0afa3eu; return 0; }
r[4]+=r[12];
goto P_0c0afa40;
P_0c0afa40: /* original 8443, guest PC 0x0c0afa40 */
if(!s->budget--) { s->failed_pc=0x0c0afa40u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+3,1);
goto P_0c0afa42;
P_0c0afa42: /* original 600c, guest PC 0x0c0afa42 */
if(!s->budget--) { s->failed_pc=0x0c0afa42u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa44;
P_0c0afa44: /* original 4028, guest PC 0x0c0afa44 */
if(!s->budget--) { s->failed_pc=0x0c0afa44u; return 0; }
r[0]<<=16;
goto P_0c0afa46;
P_0c0afa46: /* original 4018, guest PC 0x0c0afa46 */
if(!s->budget--) { s->failed_pc=0x0c0afa46u; return 0; }
r[0]<<=8;
goto P_0c0afa48;
P_0c0afa48: /* original 2029, guest PC 0x0c0afa48 */
if(!s->budget--) { s->failed_pc=0x0c0afa48u; return 0; }
r[0]&=r[2];
goto P_0c0afa4a;
P_0c0afa4a: /* original 6303, guest PC 0x0c0afa4a */
if(!s->budget--) { s->failed_pc=0x0c0afa4au; return 0; }
r[3]=r[0];
goto P_0c0afa4c;
P_0c0afa4c: /* original 8442, guest PC 0x0c0afa4c */
if(!s->budget--) { s->failed_pc=0x0c0afa4cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0afa4e;
P_0c0afa4e: /* original 4229, guest PC 0x0c0afa4e */
if(!s->budget--) { s->failed_pc=0x0c0afa4eu; return 0; }
r[2]>>=16;
goto P_0c0afa50;
P_0c0afa50: /* original 600c, guest PC 0x0c0afa50 */
if(!s->budget--) { s->failed_pc=0x0c0afa50u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa52;
P_0c0afa52: /* original 4028, guest PC 0x0c0afa52 */
if(!s->budget--) { s->failed_pc=0x0c0afa52u; return 0; }
r[0]<<=16;
goto P_0c0afa54;
P_0c0afa54: /* original 2019, guest PC 0x0c0afa54 */
if(!s->budget--) { s->failed_pc=0x0c0afa54u; return 0; }
r[0]&=r[1];
goto P_0c0afa56;
P_0c0afa56: /* original 230b, guest PC 0x0c0afa56 */
if(!s->budget--) { s->failed_pc=0x0c0afa56u; return 0; }
r[3]|=r[0];
goto P_0c0afa58;
P_0c0afa58: /* original 8441, guest PC 0x0c0afa58 */
if(!s->budget--) { s->failed_pc=0x0c0afa58u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0afa5a;
P_0c0afa5a: /* original 600c, guest PC 0x0c0afa5a */
if(!s->budget--) { s->failed_pc=0x0c0afa5au; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa5c;
P_0c0afa5c: /* original 4018, guest PC 0x0c0afa5c */
if(!s->budget--) { s->failed_pc=0x0c0afa5cu; return 0; }
r[0]<<=8;
goto P_0c0afa5e;
P_0c0afa5e: /* original 2029, guest PC 0x0c0afa5e */
if(!s->budget--) { s->failed_pc=0x0c0afa5eu; return 0; }
r[0]&=r[2];
goto P_0c0afa60;
P_0c0afa60: /* original 230b, guest PC 0x0c0afa60 */
if(!s->budget--) { s->failed_pc=0x0c0afa60u; return 0; }
r[3]|=r[0];
goto P_0c0afa62;
P_0c0afa62: /* original 6040, guest PC 0x0c0afa62 */
if(!s->budget--) { s->failed_pc=0x0c0afa62u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[4],1);
r[0]=tmp;
goto P_0c0afa64;
P_0c0afa64: /* original 6433, guest PC 0x0c0afa64 */
if(!s->budget--) { s->failed_pc=0x0c0afa64u; return 0; }
r[4]=r[3];
goto P_0c0afa66;
P_0c0afa66: /* original d31b, guest PC 0x0c0afa66 */
if(!s->budget--) { s->failed_pc=0x0c0afa66u; return 0; }
r[3]=read(ram,0x0c0afad4u,4);
goto P_0c0afa68;
P_0c0afa68: /* original 600c, guest PC 0x0c0afa68 */
if(!s->budget--) { s->failed_pc=0x0c0afa68u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa6a;
P_0c0afa6a: /* original 240b, guest PC 0x0c0afa6a */
if(!s->budget--) { s->failed_pc=0x0c0afa6au; return 0; }
r[4]|=r[0];
goto P_0c0afa6c;
P_0c0afa6c: /* original 2438, guest PC 0x0c0afa6c */
if(!s->budget--) { s->failed_pc=0x0c0afa6cu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[3])==0)!=0);
goto P_0c0afa6e;
P_0c0afa6e: /* original 8950, guest PC 0x0c0afa6e */
if(!s->budget--) { s->failed_pc=0x0c0afa6eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0afb12; }
goto P_0c0afa70;
P_0c0afa70: /* original e03e, guest PC 0x0c0afa70 */
if(!s->budget--) { s->failed_pc=0x0c0afa70u; return 0; }
r[0]=0x0000003eu;
goto P_0c0afa72;
P_0c0afa72: /* original 0cdd, guest PC 0x0c0afa72 */
if(!s->budget--) { s->failed_pc=0x0c0afa72u; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0afa74;
P_0c0afa74: /* original e502, guest PC 0x0c0afa74 */
if(!s->budget--) { s->failed_pc=0x0c0afa74u; return 0; }
r[5]=0x00000002u;
goto P_0c0afa76;
P_0c0afa76: /* original 84d4, guest PC 0x0c0afa76 */
if(!s->budget--) { s->failed_pc=0x0c0afa76u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[13]+4,1);
goto P_0c0afa78;
P_0c0afa78: /* original 6ccd, guest PC 0x0c0afa78 */
if(!s->budget--) { s->failed_pc=0x0c0afa78u; return 0; }
r[12]=r[12]&65535u;
goto P_0c0afa7a;
P_0c0afa7a: /* original 600c, guest PC 0x0c0afa7a */
if(!s->budget--) { s->failed_pc=0x0c0afa7au; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa7c;
P_0c0afa7c: /* original 3c0c, guest PC 0x0c0afa7c */
if(!s->budget--) { s->failed_pc=0x0c0afa7cu; return 0; }
r[12]+=r[0];
goto P_0c0afa7e;
P_0c0afa7e: /* original 901f, guest PC 0x0c0afa7e */
if(!s->budget--) { s->failed_pc=0x0c0afa7eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afac0u,2);
goto P_0c0afa80;
P_0c0afa80: /* original 03dd, guest PC 0x0c0afa80 */
if(!s->budget--) { s->failed_pc=0x0c0afa80u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c0afa82;
P_0c0afa82: /* original 623d, guest PC 0x0c0afa82 */
if(!s->budget--) { s->failed_pc=0x0c0afa82u; return 0; }
r[2]=r[3]&65535u;
goto P_0c0afa84;
P_0c0afa84: /* original d318, guest PC 0x0c0afa84 */
if(!s->budget--) { s->failed_pc=0x0c0afa84u; return 0; }
r[3]=read(ram,0x0c0afae8u,4);
goto P_0c0afa86;
P_0c0afa86: /* original 32c8, guest PC 0x0c0afa86 */
if(!s->budget--) { s->failed_pc=0x0c0afa86u; return 0; }
r[2]-=r[12];
goto P_0c0afa88;
P_0c0afa88: /* original 6c23, guest PC 0x0c0afa88 */
if(!s->budget--) { s->failed_pc=0x0c0afa88u; return 0; }
r[12]=r[2];
goto P_0c0afa8a;
P_0c0afa8a: /* original 430b, guest PC 0x0c0afa8a */
if(!s->budget--) { s->failed_pc=0x0c0afa8au; return 0; }
target=r[3];
r[16]=0x0c0afa8eu;
tmp=read(ram,r[15],4);
r[4]=tmp;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0afa8eu) { target=s->pc; goto dispatch; }
goto P_0c0afa8e;
P_0c0afa8c: /* original 64f2, guest PC 0x0c0afa8c */
if(!s->budget--) { s->failed_pc=0x0c0afa8cu; return 0; }
tmp=read(ram,r[15],4);
r[4]=tmp;
goto P_0c0afa8e;
P_0c0afa8e: /* original 6403, guest PC 0x0c0afa8e */
if(!s->budget--) { s->failed_pc=0x0c0afa8eu; return 0; }
r[4]=r[0];
goto P_0c0afa90;
P_0c0afa90: /* original 8442, guest PC 0x0c0afa90 */
if(!s->budget--) { s->failed_pc=0x0c0afa90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+2,1);
goto P_0c0afa92;
P_0c0afa92: /* original d316, guest PC 0x0c0afa92 */
if(!s->budget--) { s->failed_pc=0x0c0afa92u; return 0; }
r[3]=read(ram,0x0c0afaecu,4);
goto P_0c0afa94;
P_0c0afa94: /* original 600c, guest PC 0x0c0afa94 */
if(!s->budget--) { s->failed_pc=0x0c0afa94u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afa96;
P_0c0afa96: /* original 4018, guest PC 0x0c0afa96 */
if(!s->budget--) { s->failed_pc=0x0c0afa96u; return 0; }
r[0]<<=8;
goto P_0c0afa98;
P_0c0afa98: /* original 2039, guest PC 0x0c0afa98 */
if(!s->budget--) { s->failed_pc=0x0c0afa98u; return 0; }
r[0]&=r[3];
goto P_0c0afa9a;
P_0c0afa9a: /* original 6203, guest PC 0x0c0afa9a */
if(!s->budget--) { s->failed_pc=0x0c0afa9au; return 0; }
r[2]=r[0];
goto P_0c0afa9c;
P_0c0afa9c: /* original 8441, guest PC 0x0c0afa9c */
if(!s->budget--) { s->failed_pc=0x0c0afa9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+1,1);
goto P_0c0afa9e;
P_0c0afa9e: /* original 6423, guest PC 0x0c0afa9e */
if(!s->budget--) { s->failed_pc=0x0c0afa9eu; return 0; }
r[4]=r[2];
goto P_0c0afaa0;
P_0c0afaa0: /* original 600c, guest PC 0x0c0afaa0 */
if(!s->budget--) { s->failed_pc=0x0c0afaa0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0afaa2;
P_0c0afaa2: /* original 240b, guest PC 0x0c0afaa2 */
if(!s->budget--) { s->failed_pc=0x0c0afaa2u; return 0; }
r[4]|=r[0];
goto P_0c0afaa4;
P_0c0afaa4: /* original 74ff, guest PC 0x0c0afaa4 */
if(!s->budget--) { s->failed_pc=0x0c0afaa4u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0afaa6;
P_0c0afaa6: /* original 34c2, guest PC 0x0c0afaa6 */
if(!s->budget--) { s->failed_pc=0x0c0afaa6u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>=r[12])!=0);
goto P_0c0afaa8;
P_0c0afaa8: /* original 8b33, guest PC 0x0c0afaa8 */
if(!s->budget--) { s->failed_pc=0x0c0afaa8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afb12; }
goto P_0c0afaaa;
P_0c0afaaa: /* original d307, guest PC 0x0c0afaaa */
if(!s->budget--) { s->failed_pc=0x0c0afaaau; return 0; }
r[3]=read(ram,0x0c0afac8u,4);
goto P_0c0afaac;
P_0c0afaac: /* original 65f2, guest PC 0x0c0afaac */
if(!s->budget--) { s->failed_pc=0x0c0afaacu; return 0; }
tmp=read(ram,r[15],4);
r[5]=tmp;
goto P_0c0afaae;
P_0c0afaae: /* original 430b, guest PC 0x0c0afaae */
if(!s->budget--) { s->failed_pc=0x0c0afaaeu; return 0; }
target=r[3];
r[16]=0x0c0afab2u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0afab2u) { target=s->pc; goto dispatch; }
goto P_0c0afab2;
P_0c0afab0: /* original 64e3, guest PC 0x0c0afab0 */
if(!s->budget--) { s->failed_pc=0x0c0afab0u; return 0; }
r[4]=r[14];
goto P_0c0afab2;
P_0c0afab2: /* original 9003, guest PC 0x0c0afab2 */
if(!s->budget--) { s->failed_pc=0x0c0afab2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afabcu,2);
goto P_0c0afab4;
P_0c0afab4: /* original a02b, guest PC 0x0c0afab4 */
if(!s->budget--) { s->failed_pc=0x0c0afab4u; return 0; }
write(ram,r[14]+r[0],r[11],2);
goto P_0c0afb0e;
P_0c0afab6: /* original 0eb5, guest PC 0x0c0afab6 */
if(!s->budget--) { s->failed_pc=0x0c0afab6u; return 0; }
write(ram,r[14]+r[0],r[11],2);
return vf3_matrix_family(0x0c0afab8u,s,ram);
P_0c0afaf0: /* original 9034, guest PC 0x0c0afaf0 */
if(!s->budget--) { s->failed_pc=0x0c0afaf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0afb5cu,2);
goto P_0c0afaf2;
P_0c0afaf2: /* original e300, guest PC 0x0c0afaf2 */
if(!s->budget--) { s->failed_pc=0x0c0afaf2u; return 0; }
r[3]=0x00000000u;
goto P_0c0afaf4;
P_0c0afaf4: /* original 04ed, guest PC 0x0c0afaf4 */
if(!s->budget--) { s->failed_pc=0x0c0afaf4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afaf6;
P_0c0afaf6: /* original 644d, guest PC 0x0c0afaf6 */
if(!s->budget--) { s->failed_pc=0x0c0afaf6u; return 0; }
r[4]=r[4]&65535u;
goto P_0c0afaf8;
P_0c0afaf8: /* original 74ff, guest PC 0x0c0afaf8 */
if(!s->budget--) { s->failed_pc=0x0c0afaf8u; return 0; }
r[4]+=0xffffffffu;
goto P_0c0afafa;
P_0c0afafa: /* original 3436, guest PC 0x0c0afafa */
if(!s->budget--) { s->failed_pc=0x0c0afafau; return 0; }
r[17]=(r[17]&~1u)|((r[4]>r[3])!=0);
goto P_0c0afafc;
P_0c0afafc: /* original 8d01, guest PC 0x0c0afafc */
if(!s->budget--) { s->failed_pc=0x0c0afafcu; return 0; }
cond=r[17]&1u;
r[0]=0x0000003eu;
if(cond) { goto P_0c0afb02; }
goto P_0c0afb00;
P_0c0afafe: /* original e03e, guest PC 0x0c0afafe */
if(!s->budget--) { s->failed_pc=0x0c0afafeu; return 0; }
r[0]=0x0000003eu;
goto P_0c0afb00;
P_0c0afb00: /* original e401, guest PC 0x0c0afb00 */
if(!s->budget--) { s->failed_pc=0x0c0afb00u; return 0; }
r[4]=0x00000001u;
goto P_0c0afb02;
P_0c0afb02: /* original 05ed, guest PC 0x0c0afb02 */
if(!s->budget--) { s->failed_pc=0x0c0afb02u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+r[0],2);
goto P_0c0afb04;
P_0c0afb04: /* original 655d, guest PC 0x0c0afb04 */
if(!s->budget--) { s->failed_pc=0x0c0afb04u; return 0; }
r[5]=r[5]&65535u;
goto P_0c0afb06;
P_0c0afb06: /* original 3546, guest PC 0x0c0afb06 */
if(!s->budget--) { s->failed_pc=0x0c0afb06u; return 0; }
r[17]=(r[17]&~1u)|((r[5]>r[4])!=0);
goto P_0c0afb08;
P_0c0afb08: /* original 8b00, guest PC 0x0c0afb08 */
if(!s->budget--) { s->failed_pc=0x0c0afb08u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0afb0c; }
goto P_0c0afb0a;
P_0c0afb0a: /* original 6543, guest PC 0x0c0afb0a */
if(!s->budget--) { s->failed_pc=0x0c0afb0au; return 0; }
r[5]=r[4];
goto P_0c0afb0c;
P_0c0afb0c: /* original 0e55, guest PC 0x0c0afb0c */
if(!s->budget--) { s->failed_pc=0x0c0afb0cu; return 0; }
write(ram,r[14]+r[0],r[5],2);
goto P_0c0afb0e;
P_0c0afb0e: /* original a001, guest PC 0x0c0afb0e */
if(!s->budget--) { s->failed_pc=0x0c0afb0eu; return 0; }
r[4]=0x00000001u;
goto P_0c0afb14;
P_0c0afb10: /* original e401, guest PC 0x0c0afb10 */
if(!s->budget--) { s->failed_pc=0x0c0afb10u; return 0; }
r[4]=0x00000001u;
goto P_0c0afb12;
P_0c0afb12: /* original e400, guest PC 0x0c0afb12 */
if(!s->budget--) { s->failed_pc=0x0c0afb12u; return 0; }
r[4]=0x00000000u;
goto P_0c0afb14;
P_0c0afb14: /* original 7f08, guest PC 0x0c0afb14 */
if(!s->budget--) { s->failed_pc=0x0c0afb14u; return 0; }
r[15]+=0x00000008u;
goto P_0c0afb16;
P_0c0afb16: /* original 6043, guest PC 0x0c0afb16 */
if(!s->budget--) { s->failed_pc=0x0c0afb16u; return 0; }
r[0]=r[4];
goto P_0c0afb18;
P_0c0afb18: /* original 4f26, guest PC 0x0c0afb18 */
if(!s->budget--) { s->failed_pc=0x0c0afb18u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0afb1a;
P_0c0afb1a: /* original 6bf6, guest PC 0x0c0afb1a */
if(!s->budget--) { s->failed_pc=0x0c0afb1au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0afb1c;
P_0c0afb1c: /* original 6cf6, guest PC 0x0c0afb1c */
if(!s->budget--) { s->failed_pc=0x0c0afb1cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0afb1e;
P_0c0afb1e: /* original 6df6, guest PC 0x0c0afb1e */
if(!s->budget--) { s->failed_pc=0x0c0afb1eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0afb20;
P_0c0afb20: /* original 000b, guest PC 0x0c0afb20 */
if(!s->budget--) { s->failed_pc=0x0c0afb20u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0afb22: /* original 6ef6, guest PC 0x0c0afb22 */
if(!s->budget--) { s->failed_pc=0x0c0afb22u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0afb24u,s,ram);
P_0c0c1bec: /* original 4f22, guest PC 0x0c0c1bec */
if(!s->budget--) { s->failed_pc=0x0c0c1becu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c1bee;
P_0c0c1bee: /* original 633d, guest PC 0x0c0c1bee */
if(!s->budget--) { s->failed_pc=0x0c0c1beeu; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1bf0;
P_0c0c1bf0: /* original d036, guest PC 0x0c0c1bf0 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf0u; return 0; }
r[0]=read(ram,0x0c0c1cccu,4);
goto P_0c0c1bf2;
P_0c0c1bf2: /* original 4308, guest PC 0x0c0c1bf2 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf2u; return 0; }
r[3]<<=2;
goto P_0c0c1bf4;
P_0c0c1bf4: /* original 5eb3, guest PC 0x0c0c1bf4 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf4u; return 0; }
r[14]=read(ram,r[11]+12,4);
goto P_0c0c1bf6;
P_0c0c1bf6: /* original f336, guest PC 0x0c0c1bf6 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf6u; return 0; }
vf3_matrix_load(s,ram,3,r[3]+r[0]);
goto P_0c0c1bf8;
P_0c0c1bf8: /* original e014, guest PC 0x0c0c1bf8 */
if(!s->budget--) { s->failed_pc=0x0c0c1bf8u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1bfa;
P_0c0c1bfa: /* original 7fa4, guest PC 0x0c0c1bfa */
if(!s->budget--) { s->failed_pc=0x0c0c1bfau; return 0; }
r[15]+=0xffffffa4u;
goto P_0c0c1bfc;
P_0c0c1bfc: /* original ff37, guest PC 0x0c0c1bfc */
if(!s->budget--) { s->failed_pc=0x0c0c1bfcu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1bfe;
P_0c0c1bfe: /* original 9061, guest PC 0x0c0c1bfe */
if(!s->budget--) { s->failed_pc=0x0c0c1bfeu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc4u,2);
goto P_0c0c1c00;
P_0c0c1c00: /* original d433, guest PC 0x0c0c1c00 */
if(!s->budget--) { s->failed_pc=0x0c0c1c00u; return 0; }
r[4]=read(ram,0x0c0c1cd0u,4);
goto P_0c0c1c02;
P_0c0c1c02: /* original 034e, guest PC 0x0c0c1c02 */
if(!s->budget--) { s->failed_pc=0x0c0c1c02u; return 0; }
r[3]=read(ram,r[4]+r[0],4);
goto P_0c0c1c04;
P_0c0c1c04: /* original c733, guest PC 0x0c0c1c04 */
if(!s->budget--) { s->failed_pc=0x0c0c1c04u; return 0; }
r[0]=0x0c0c1cd4u;
goto P_0c0c1c06;
P_0c0c1c06: /* original f208, guest PC 0x0c0c1c06 */
if(!s->budget--) { s->failed_pc=0x0c0c1c06u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c1c08;
P_0c0c1c08: /* original 435a, guest PC 0x0c0c1c08 */
if(!s->budget--) { s->failed_pc=0x0c0c1c08u; return 0; }
r[53]=r[3];
goto P_0c0c1c0a;
P_0c0c1c0a: /* original f32d, guest PC 0x0c0c1c0a */
if(!s->budget--) { s->failed_pc=0x0c0c1c0au; return 0; }
fr[3]=vf3_fpu_float(r[53],r[18]);
goto P_0c0c1c0c;
P_0c0c1c0c: /* original f322, guest PC 0x0c0c1c0c */
if(!s->budget--) { s->failed_pc=0x0c0c1c0cu; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[2],r[18],'*');
goto P_0c0c1c0e;
P_0c0c1c0e: /* original ff3a, guest PC 0x0c0c1c0e */
if(!s->budget--) { s->failed_pc=0x0c0c1c0eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]);
goto P_0c0c1c10;
P_0c0c1c10: /* original 9059, guest PC 0x0c0c1c10 */
if(!s->budget--) { s->failed_pc=0x0c0c1c10u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc6u,2);
goto P_0c0c1c12;
P_0c0c1c12: /* original ea00, guest PC 0x0c0c1c12 */
if(!s->budget--) { s->failed_pc=0x0c0c1c12u; return 0; }
r[10]=0x00000000u;
goto P_0c0c1c14;
P_0c0c1c14: /* original 084e, guest PC 0x0c0c1c14 */
if(!s->budget--) { s->failed_pc=0x0c0c1c14u; return 0; }
r[8]=read(ram,r[4]+r[0],4);
goto P_0c0c1c16;
P_0c0c1c16: /* original 3b80, guest PC 0x0c0c1c16 */
if(!s->budget--) { s->failed_pc=0x0c0c1c16u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[8])!=0);
goto P_0c0c1c18;
P_0c0c1c18: /* original 8f03, guest PC 0x0c0c1c18 */
if(!s->budget--) { s->failed_pc=0x0c0c1c18u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0c1c22; }
goto P_0c0c1c1c;
P_0c0c1c1a: /* original ed01, guest PC 0x0c0c1c1a */
if(!s->budget--) { s->failed_pc=0x0c0c1c1au; return 0; }
r[13]=0x00000001u;
goto P_0c0c1c1c;
P_0c0c1c1c: /* original 9054, guest PC 0x0c0c1c1c */
if(!s->budget--) { s->failed_pc=0x0c0c1c1cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc8u,2);
goto P_0c0c1c1e;
P_0c0c1c1e: /* original a002, guest PC 0x0c0c1c1e */
if(!s->budget--) { s->failed_pc=0x0c0c1c1eu; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c0c1c26;
P_0c0c1c20: /* original 04d6, guest PC 0x0c0c1c20 */
if(!s->budget--) { s->failed_pc=0x0c0c1c20u; return 0; }
write(ram,r[4]+r[0],r[13],4);
goto P_0c0c1c22;
P_0c0c1c22: /* original 9051, guest PC 0x0c0c1c22 */
if(!s->budget--) { s->failed_pc=0x0c0c1c22u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c1cc8u,2);
goto P_0c0c1c24;
P_0c0c1c24: /* original 04a6, guest PC 0x0c0c1c24 */
if(!s->budget--) { s->failed_pc=0x0c0c1c24u; return 0; }
write(ram,r[4]+r[0],r[10],4);
goto P_0c0c1c26;
P_0c0c1c26: /* original c72c, guest PC 0x0c0c1c26 */
if(!s->budget--) { s->failed_pc=0x0c0c1c26u; return 0; }
r[0]=0x0c0c1cd8u;
goto P_0c0c1c28;
P_0c0c1c28: /* original f3f8, guest PC 0x0c0c1c28 */
if(!s->budget--) { s->failed_pc=0x0c0c1c28u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1c2a;
P_0c0c1c2a: /* original f208, guest PC 0x0c0c1c2a */
if(!s->budget--) { s->failed_pc=0x0c0c1c2au; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c1c2c;
P_0c0c1c2c: /* original e018, guest PC 0x0c0c1c2c */
if(!s->budget--) { s->failed_pc=0x0c0c1c2cu; return 0; }
r[0]=0x00000018u;
goto P_0c0c1c2e;
P_0c0c1c2e: /* original fd8d, guest PC 0x0c0c1c2e */
if(!s->budget--) { s->failed_pc=0x0c0c1c2eu; return 0; }
fr[13]=0;
goto P_0c0c1c30;
P_0c0c1c30: /* original 69a3, guest PC 0x0c0c1c30 */
if(!s->budget--) { s->failed_pc=0x0c0c1c30u; return 0; }
r[9]=r[10];
goto P_0c0c1c32;
P_0c0c1c32: /* original f231, guest PC 0x0c0c1c32 */
if(!s->budget--) { s->failed_pc=0x0c0c1c32u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1c34;
P_0c0c1c34: /* original ff27, guest PC 0x0c0c1c34 */
if(!s->budget--) { s->failed_pc=0x0c0c1c34u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1c36;
P_0c0c1c36: /* original 63e1, guest PC 0x0c0c1c36 */
if(!s->budget--) { s->failed_pc=0x0c0c1c36u; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[14],2);
r[3]=tmp;
goto P_0c0c1c38;
P_0c0c1c38: /* original 633d, guest PC 0x0c0c1c38 */
if(!s->budget--) { s->failed_pc=0x0c0c1c38u; return 0; }
r[3]=r[3]&65535u;
goto P_0c0c1c3a;
P_0c0c1c3a: /* original 23d8, guest PC 0x0c0c1c3a */
if(!s->budget--) { s->failed_pc=0x0c0c1c3au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[13])==0)!=0);
goto P_0c0c1c3c;
P_0c0c1c3c: /* original 8b01, guest PC 0x0c0c1c3c */
if(!s->budget--) { s->failed_pc=0x0c0c1c3cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1c42; }
goto P_0c0c1c3e;
P_0c0c1c3e: /* original a08d, guest PC 0x0c0c1c3e */
if(!s->budget--) { s->failed_pc=0x0c0c1c3eu; return 0; }
goto P_0c0c1d5c;
P_0c0c1c40: /* original 0009, guest PC 0x0c0c1c40 */
if(!s->budget--) { s->failed_pc=0x0c0c1c40u; return 0; }
goto P_0c0c1c42;
P_0c0c1c42: /* original d326, guest PC 0x0c0c1c42 */
if(!s->budget--) { s->failed_pc=0x0c0c1c42u; return 0; }
r[3]=read(ram,0x0c0c1cdcu,4);
goto P_0c0c1c44;
P_0c0c1c44: /* original 85e1, guest PC 0x0c0c1c44 */
if(!s->budget--) { s->failed_pc=0x0c0c1c44u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[14]+2,2);
goto P_0c0c1c46;
P_0c0c1c46: /* original 430b, guest PC 0x0c0c1c46 */
if(!s->budget--) { s->failed_pc=0x0c0c1c46u; return 0; }
target=r[3];
r[16]=0x0c0c1c4au;
r[4]=r[0];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1c4au) { target=s->pc; goto dispatch; }
goto P_0c0c1c4a;
P_0c0c1c48: /* original 6403, guest PC 0x0c0c1c48 */
if(!s->budget--) { s->failed_pc=0x0c0c1c48u; return 0; }
r[4]=r[0];
goto P_0c0c1c4a;
P_0c0c1c4a: /* original 6403, guest PC 0x0c0c1c4a */
if(!s->budget--) { s->failed_pc=0x0c0c1c4au; return 0; }
r[4]=r[0];
goto P_0c0c1c4c;
P_0c0c1c4c: /* original e008, guest PC 0x0c0c1c4c */
if(!s->budget--) { s->failed_pc=0x0c0c1c4cu; return 0; }
r[0]=0x00000008u;
goto P_0c0c1c4e;
P_0c0c1c4e: /* original f346, guest PC 0x0c0c1c4e */
if(!s->budget--) { s->failed_pc=0x0c0c1c4eu; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c1c50;
P_0c0c1c50: /* original e004, guest PC 0x0c0c1c50 */
if(!s->budget--) { s->failed_pc=0x0c0c1c50u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1c52;
P_0c0c1c52: /* original f448, guest PC 0x0c0c1c52 */
if(!s->budget--) { s->failed_pc=0x0c0c1c52u; return 0; }
vf3_matrix_load(s,ram,4,r[4]);
goto P_0c0c1c54;
P_0c0c1c54: /* original 6ca3, guest PC 0x0c0c1c54 */
if(!s->budget--) { s->failed_pc=0x0c0c1c54u; return 0; }
r[12]=r[10];
goto P_0c0c1c56;
P_0c0c1c56: /* original ff37, guest PC 0x0c0c1c56 */
if(!s->budget--) { s->failed_pc=0x0c0c1c56u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c58;
P_0c0c1c58: /* original e010, guest PC 0x0c0c1c58 */
if(!s->budget--) { s->failed_pc=0x0c0c1c58u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1c5a;
P_0c0c1c5a: /* original f346, guest PC 0x0c0c1c5a */
if(!s->budget--) { s->failed_pc=0x0c0c1c5au; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c1c5c;
P_0c0c1c5c: /* original e008, guest PC 0x0c0c1c5c */
if(!s->budget--) { s->failed_pc=0x0c0c1c5cu; return 0; }
r[0]=0x00000008u;
goto P_0c0c1c5e;
P_0c0c1c5e: /* original ff37, guest PC 0x0c0c1c5e */
if(!s->budget--) { s->failed_pc=0x0c0c1c5eu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c60;
P_0c0c1c60: /* original e014, guest PC 0x0c0c1c60 */
if(!s->budget--) { s->failed_pc=0x0c0c1c60u; return 0; }
r[0]=0x00000014u;
goto P_0c0c1c62;
P_0c0c1c62: /* original f346, guest PC 0x0c0c1c62 */
if(!s->budget--) { s->failed_pc=0x0c0c1c62u; return 0; }
vf3_matrix_load(s,ram,3,r[4]+r[0]);
goto P_0c0c1c64;
P_0c0c1c64: /* original e010, guest PC 0x0c0c1c64 */
if(!s->budget--) { s->failed_pc=0x0c0c1c64u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1c66;
P_0c0c1c66: /* original ff37, guest PC 0x0c0c1c66 */
if(!s->budget--) { s->failed_pc=0x0c0c1c66u; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c68;
P_0c0c1c68: /* original e050, guest PC 0x0c0c1c68 */
if(!s->budget--) { s->failed_pc=0x0c0c1c68u; return 0; }
r[0]=0x00000050u;
goto P_0c0c1c6a;
P_0c0c1c6a: /* original 53e4, guest PC 0x0c0c1c6a */
if(!s->budget--) { s->failed_pc=0x0c0c1c6au; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c0c1c6c;
P_0c0c1c6c: /* original 1f3a, guest PC 0x0c0c1c6c */
if(!s->budget--) { s->failed_pc=0x0c0c1c6cu; return 0; }
write(ram,r[15]+40,r[3],4);
goto P_0c0c1c6e;
P_0c0c1c6e: /* original 52ee, guest PC 0x0c0c1c6e */
if(!s->budget--) { s->failed_pc=0x0c0c1c6eu; return 0; }
r[2]=read(ram,r[14]+56,4);
goto P_0c0c1c70;
P_0c0c1c70: /* original 0f26, guest PC 0x0c0c1c70 */
if(!s->budget--) { s->failed_pc=0x0c0c1c70u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c0c1c72;
P_0c0c1c72: /* original e054, guest PC 0x0c0c1c72 */
if(!s->budget--) { s->failed_pc=0x0c0c1c72u; return 0; }
r[0]=0x00000054u;
goto P_0c0c1c74;
P_0c0c1c74: /* original 53ef, guest PC 0x0c0c1c74 */
if(!s->budget--) { s->failed_pc=0x0c0c1c74u; return 0; }
r[3]=read(ram,r[14]+60,4);
goto P_0c0c1c76;
P_0c0c1c76: /* original 0f36, guest PC 0x0c0c1c76 */
if(!s->budget--) { s->failed_pc=0x0c0c1c76u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c0c1c78;
P_0c0c1c78: /* original e058, guest PC 0x0c0c1c78 */
if(!s->budget--) { s->failed_pc=0x0c0c1c78u; return 0; }
r[0]=0x00000058u;
goto P_0c0c1c7a;
P_0c0c1c7a: /* original f39d, guest PC 0x0c0c1c7a */
if(!s->budget--) { s->failed_pc=0x0c0c1c7au; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1c7c;
P_0c0c1c7c: /* original ff37, guest PC 0x0c0c1c7c */
if(!s->budget--) { s->failed_pc=0x0c0c1c7cu; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c0c1c7e;
P_0c0c1c7e: /* original e01c, guest PC 0x0c0c1c7e */
if(!s->budget--) { s->failed_pc=0x0c0c1c7eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c1c80;
P_0c0c1c80: /* original f3f8, guest PC 0x0c0c1c80 */
if(!s->budget--) { s->failed_pc=0x0c0c1c80u; return 0; }
vf3_matrix_load(s,ram,3,r[15]);
goto P_0c0c1c82;
P_0c0c1c82: /* original fcdc, guest PC 0x0c0c1c82 */
if(!s->budget--) { s->failed_pc=0x0c0c1c82u; return 0; }
vf3_matrix_move(s,12,13);
goto P_0c0c1c84;
P_0c0c1c84: /* original f430, guest PC 0x0c0c1c84 */
if(!s->budget--) { s->failed_pc=0x0c0c1c84u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0c1c86;
P_0c0c1c86: /* original ff47, guest PC 0x0c0c1c86 */
if(!s->budget--) { s->failed_pc=0x0c0c1c86u; return 0; }
vf3_matrix_store(s,ram,4,r[15]+r[0]);
goto P_0c0c1c88;
P_0c0c1c88: /* original e004, guest PC 0x0c0c1c88 */
if(!s->budget--) { s->failed_pc=0x0c0c1c88u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1c8a;
P_0c0c1c8a: /* original f2f6, guest PC 0x0c0c1c8a */
if(!s->budget--) { s->failed_pc=0x0c0c1c8au; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1c8c;
P_0c0c1c8c: /* original e020, guest PC 0x0c0c1c8c */
if(!s->budget--) { s->failed_pc=0x0c0c1c8cu; return 0; }
r[0]=0x00000020u;
goto P_0c0c1c8e;
P_0c0c1c8e: /* original f231, guest PC 0x0c0c1c8e */
if(!s->budget--) { s->failed_pc=0x0c0c1c8eu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0c1c90;
P_0c0c1c90: /* original ff27, guest PC 0x0c0c1c90 */
if(!s->budget--) { s->failed_pc=0x0c0c1c90u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1c92;
P_0c0c1c92: /* original c713, guest PC 0x0c0c1c92 */
if(!s->budget--) { s->failed_pc=0x0c0c1c92u; return 0; }
r[0]=0x0c0c1ce0u;
goto P_0c0c1c94;
P_0c0c1c94: /* original f308, guest PC 0x0c0c1c94 */
if(!s->budget--) { s->failed_pc=0x0c0c1c94u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1c96;
P_0c0c1c96: /* original e010, guest PC 0x0c0c1c96 */
if(!s->budget--) { s->failed_pc=0x0c0c1c96u; return 0; }
r[0]=0x00000010u;
goto P_0c0c1c98;
P_0c0c1c98: /* original f2f6, guest PC 0x0c0c1c98 */
if(!s->budget--) { s->failed_pc=0x0c0c1c98u; return 0; }
vf3_matrix_load(s,ram,2,r[15]+r[0]);
goto P_0c0c1c9a;
P_0c0c1c9a: /* original e00c, guest PC 0x0c0c1c9a */
if(!s->budget--) { s->failed_pc=0x0c0c1c9au; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1c9c;
P_0c0c1c9c: /* original f232, guest PC 0x0c0c1c9c */
if(!s->budget--) { s->failed_pc=0x0c0c1c9cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c1c9e;
P_0c0c1c9e: /* original a059, guest PC 0x0c0c1c9e */
if(!s->budget--) { s->failed_pc=0x0c0c1c9eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1d54;
P_0c0c1ca0: /* original ff27, guest PC 0x0c0c1ca0 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca0u; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1ca2;
P_0c0c1ca2: /* original 3b80, guest PC 0x0c0c1ca2 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca2u; return 0; }
r[17]=(r[17]&~1u)|((r[11]==r[8])!=0);
goto P_0c0c1ca4;
P_0c0c1ca4: /* original 64c3, guest PC 0x0c0c1ca4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca4u; return 0; }
r[4]=r[12];
goto P_0c0c1ca6;
P_0c0c1ca6: /* original 8f08, guest PC 0x0c0c1ca6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca6u; return 0; }
cond=r[17]&1u;
r[4]&=r[13];
if(!cond) { goto P_0c0c1cba; }
goto P_0c0c1caa;
P_0c0c1ca8: /* original 24d9, guest PC 0x0c0c1ca8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ca8u; return 0; }
r[4]&=r[13];
goto P_0c0c1caa;
P_0c0c1caa: /* original 2448, guest PC 0x0c0c1caa */
if(!s->budget--) { s->failed_pc=0x0c0c1caau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1cac;
P_0c0c1cac: /* original 8901, guest PC 0x0c0c1cac */
if(!s->budget--) { s->failed_pc=0x0c0c1cacu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1cb2; }
goto P_0c0c1cae;
P_0c0c1cae: /* original a002, guest PC 0x0c0c1cae */
if(!s->budget--) { s->failed_pc=0x0c0c1caeu; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1cb6;
P_0c0c1cb0: /* original fedc, guest PC 0x0c0c1cb0 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb0u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1cb2;
P_0c0c1cb2: /* original e018, guest PC 0x0c0c1cb2 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb2u; return 0; }
r[0]=0x00000018u;
goto P_0c0c1cb4;
P_0c0c1cb4: /* original fef6, guest PC 0x0c0c1cb4 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb4u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c1cb6;
P_0c0c1cb6: /* original a018, guest PC 0x0c0c1cb6 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb6u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c1cea;
P_0c0c1cb8: /* original fff8, guest PC 0x0c0c1cb8 */
if(!s->budget--) { s->failed_pc=0x0c0c1cb8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
goto P_0c0c1cba;
P_0c0c1cba: /* original 2448, guest PC 0x0c0c1cba */
if(!s->budget--) { s->failed_pc=0x0c0c1cbau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c1cbc;
P_0c0c1cbc: /* original 8912, guest PC 0x0c0c1cbc */
if(!s->budget--) { s->failed_pc=0x0c0c1cbcu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1ce4; }
goto P_0c0c1cbe;
P_0c0c1cbe: /* original e01c, guest PC 0x0c0c1cbe */
if(!s->budget--) { s->failed_pc=0x0c0c1cbeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c1cc0;
P_0c0c1cc0: /* original a011, guest PC 0x0c0c1cc0 */
if(!s->budget--) { s->failed_pc=0x0c0c1cc0u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
goto P_0c0c1ce6;
P_0c0c1cc2: /* original fef6, guest PC 0x0c0c1cc2 */
if(!s->budget--) { s->failed_pc=0x0c0c1cc2u; return 0; }
vf3_matrix_load(s,ram,14,r[15]+r[0]);
return vf3_matrix_family(0x0c0c1cc4u,s,ram);
P_0c0c1ce4: /* original fedc, guest PC 0x0c0c1ce4 */
if(!s->budget--) { s->failed_pc=0x0c0c1ce4u; return 0; }
vf3_matrix_move(s,14,13);
goto P_0c0c1ce6;
P_0c0c1ce6: /* original e020, guest PC 0x0c0c1ce6 */
if(!s->budget--) { s->failed_pc=0x0c0c1ce6u; return 0; }
r[0]=0x00000020u;
goto P_0c0c1ce8;
P_0c0c1ce8: /* original fff6, guest PC 0x0c0c1ce8 */
if(!s->budget--) { s->failed_pc=0x0c0c1ce8u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0c1cea;
P_0c0c1cea: /* original c743, guest PC 0x0c0c1cea */
if(!s->budget--) { s->failed_pc=0x0c0c1ceau; return 0; }
r[0]=0x0c0c1df8u;
goto P_0c0c1cec;
P_0c0c1cec: /* original f308, guest PC 0x0c0c1cec */
if(!s->budget--) { s->failed_pc=0x0c0c1cecu; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1cee;
P_0c0c1cee: /* original f3e5, guest PC 0x0c0c1cee */
if(!s->budget--) { s->failed_pc=0x0c0c1ceeu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[3])>as_float(fr[14]))!=0);
goto P_0c0c1cf0;
P_0c0c1cf0: /* original 8b2d, guest PC 0x0c0c1cf0 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1d4e; }
goto P_0c0c1cf2;
P_0c0c1cf2: /* original f38d, guest PC 0x0c0c1cf2 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf2u; return 0; }
fr[3]=0;
goto P_0c0c1cf4;
P_0c0c1cf4: /* original ff35, guest PC 0x0c0c1cf4 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf4u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c1cf6;
P_0c0c1cf6: /* original 8b2a, guest PC 0x0c0c1cf6 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1d4e; }
goto P_0c0c1cf8;
P_0c0c1cf8: /* original e004, guest PC 0x0c0c1cf8 */
if(!s->budget--) { s->failed_pc=0x0c0c1cf8u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1cfa;
P_0c0c1cfa: /* original f3f6, guest PC 0x0c0c1cfa */
if(!s->budget--) { s->failed_pc=0x0c0c1cfau; return 0; }
vf3_matrix_load(s,ram,3,r[15]+r[0]);
goto P_0c0c1cfc;
P_0c0c1cfc: /* original ff35, guest PC 0x0c0c1cfc */
if(!s->budget--) { s->failed_pc=0x0c0c1cfcu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[15])>as_float(fr[3]))!=0);
goto P_0c0c1cfe;
P_0c0c1cfe: /* original 8b01, guest PC 0x0c0c1cfe */
if(!s->budget--) { s->failed_pc=0x0c0c1cfeu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c1d04; }
goto P_0c0c1d00;
P_0c0c1d00: /* original e004, guest PC 0x0c0c1d00 */
if(!s->budget--) { s->failed_pc=0x0c0c1d00u; return 0; }
r[0]=0x00000004u;
goto P_0c0c1d02;
P_0c0c1d02: /* original fff6, guest PC 0x0c0c1d02 */
if(!s->budget--) { s->failed_pc=0x0c0c1d02u; return 0; }
vf3_matrix_load(s,ram,15,r[15]+r[0]);
goto P_0c0c1d04;
P_0c0c1d04: /* original e008, guest PC 0x0c0c1d04 */
if(!s->budget--) { s->failed_pc=0x0c0c1d04u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1d06;
P_0c0c1d06: /* original f2cc, guest PC 0x0c0c1d06 */
if(!s->budget--) { s->failed_pc=0x0c0c1d06u; return 0; }
vf3_matrix_move(s,2,12);
goto P_0c0c1d08;
P_0c0c1d08: /* original f6f6, guest PC 0x0c0c1d08 */
if(!s->budget--) { s->failed_pc=0x0c0c1d08u; return 0; }
vf3_matrix_load(s,ram,6,r[15]+r[0]);
goto P_0c0c1d0a;
P_0c0c1d0a: /* original e014, guest PC 0x0c0c1d0a */
if(!s->budget--) { s->failed_pc=0x0c0c1d0au; return 0; }
r[0]=0x00000014u;
goto P_0c0c1d0c;
P_0c0c1d0c: /* original f8f6, guest PC 0x0c0c1d0c */
if(!s->budget--) { s->failed_pc=0x0c0c1d0cu; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c1d0e;
P_0c0c1d0e: /* original e00c, guest PC 0x0c0c1d0e */
if(!s->budget--) { s->failed_pc=0x0c0c1d0eu; return 0; }
r[0]=0x0000000cu;
goto P_0c0c1d10;
P_0c0c1d10: /* original f7f6, guest PC 0x0c0c1d10 */
if(!s->budget--) { s->failed_pc=0x0c0c1d10u; return 0; }
vf3_matrix_load(s,ram,7,r[15]+r[0]);
goto P_0c0c1d12;
P_0c0c1d12: /* original c73a, guest PC 0x0c0c1d12 */
if(!s->budget--) { s->failed_pc=0x0c0c1d12u; return 0; }
r[0]=0x0c0c1dfcu;
goto P_0c0c1d14;
P_0c0c1d14: /* original f308, guest PC 0x0c0c1d14 */
if(!s->budget--) { s->failed_pc=0x0c0c1d14u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c0c1d16;
P_0c0c1d16: /* original f6f2, guest PC 0x0c0c1d16 */
if(!s->budget--) { s->failed_pc=0x0c0c1d16u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[15],r[18],'*');
goto P_0c0c1d18;
P_0c0c1d18: /* original e024, guest PC 0x0c0c1d18 */
if(!s->budget--) { s->failed_pc=0x0c0c1d18u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1d1a;
P_0c0c1d1a: /* original 64f3, guest PC 0x0c0c1d1a */
if(!s->budget--) { s->failed_pc=0x0c0c1d1au; return 0; }
r[4]=r[15];
goto P_0c0c1d1c;
P_0c0c1d1c: /* original f232, guest PC 0x0c0c1d1c */
if(!s->budget--) { s->failed_pc=0x0c0c1d1cu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0c1d1e;
P_0c0c1d1e: /* original ff27, guest PC 0x0c0c1d1e */
if(!s->budget--) { s->failed_pc=0x0c0c1d1eu; return 0; }
vf3_matrix_store(s,ram,2,r[15]+r[0]);
goto P_0c0c1d20;
P_0c0c1d20: /* original d337, guest PC 0x0c0c1d20 */
if(!s->budget--) { s->failed_pc=0x0c0c1d20u; return 0; }
r[3]=read(ram,0x0c0c1e00u,4);
goto P_0c0c1d22;
P_0c0c1d22: /* original f4ec, guest PC 0x0c0c1d22 */
if(!s->budget--) { s->failed_pc=0x0c0c1d22u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c1d24;
P_0c0c1d24: /* original f52c, guest PC 0x0c0c1d24 */
if(!s->budget--) { s->failed_pc=0x0c0c1d24u; return 0; }
vf3_matrix_move(s,5,2);
goto P_0c0c1d26;
P_0c0c1d26: /* original 430b, guest PC 0x0c0c1d26 */
if(!s->budget--) { s->failed_pc=0x0c0c1d26u; return 0; }
target=r[3];
r[16]=0x0c0c1d2au;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1d2au) { target=s->pc; goto dispatch; }
goto P_0c0c1d2a;
P_0c0c1d28: /* original 7428, guest PC 0x0c0c1d28 */
if(!s->budget--) { s->failed_pc=0x0c0c1d28u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c1d2a;
P_0c0c1d2a: /* original e010, guest PC 0x0c0c1d2a */
if(!s->budget--) { s->failed_pc=0x0c0c1d2au; return 0; }
r[0]=0x00000010u;
goto P_0c0c1d2c;
P_0c0c1d2c: /* original d336, guest PC 0x0c0c1d2c */
if(!s->budget--) { s->failed_pc=0x0c0c1d2cu; return 0; }
r[3]=read(ram,0x0c0c1e08u,4);
goto P_0c0c1d2e;
P_0c0c1d2e: /* original f9f6, guest PC 0x0c0c1d2e */
if(!s->budget--) { s->failed_pc=0x0c0c1d2eu; return 0; }
vf3_matrix_load(s,ram,9,r[15]+r[0]);
goto P_0c0c1d30;
P_0c0c1d30: /* original e008, guest PC 0x0c0c1d30 */
if(!s->budget--) { s->failed_pc=0x0c0c1d30u; return 0; }
r[0]=0x00000008u;
goto P_0c0c1d32;
P_0c0c1d32: /* original f8f6, guest PC 0x0c0c1d32 */
if(!s->budget--) { s->failed_pc=0x0c0c1d32u; return 0; }
vf3_matrix_load(s,ram,8,r[15]+r[0]);
goto P_0c0c1d34;
P_0c0c1d34: /* original c733, guest PC 0x0c0c1d34 */
if(!s->budget--) { s->failed_pc=0x0c0c1d34u; return 0; }
r[0]=0x0c0c1e04u;
goto P_0c0c1d36;
P_0c0c1d36: /* original f708, guest PC 0x0c0c1d36 */
if(!s->budget--) { s->failed_pc=0x0c0c1d36u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0c1d38;
P_0c0c1d38: /* original e024, guest PC 0x0c0c1d38 */
if(!s->budget--) { s->failed_pc=0x0c0c1d38u; return 0; }
r[0]=0x00000024u;
goto P_0c0c1d3a;
P_0c0c1d3a: /* original f5f6, guest PC 0x0c0c1d3a */
if(!s->budget--) { s->failed_pc=0x0c0c1d3au; return 0; }
vf3_matrix_load(s,ram,5,r[15]+r[0]);
goto P_0c0c1d3c;
P_0c0c1d3c: /* original 64f3, guest PC 0x0c0c1d3c */
if(!s->budget--) { s->failed_pc=0x0c0c1d3cu; return 0; }
r[4]=r[15];
goto P_0c0c1d3e;
P_0c0c1d3e: /* original f6fc, guest PC 0x0c0c1d3e */
if(!s->budget--) { s->failed_pc=0x0c0c1d3eu; return 0; }
vf3_matrix_move(s,6,15);
goto P_0c0c1d40;
P_0c0c1d40: /* original f4ec, guest PC 0x0c0c1d40 */
if(!s->budget--) { s->failed_pc=0x0c0c1d40u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c0c1d42;
P_0c0c1d42: /* original 430b, guest PC 0x0c0c1d42 */
if(!s->budget--) { s->failed_pc=0x0c0c1d42u; return 0; }
target=r[3];
r[16]=0x0c0c1d46u;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1d46u) { target=s->pc; goto dispatch; }
goto P_0c0c1d46;
P_0c0c1d44: /* original 7428, guest PC 0x0c0c1d44 */
if(!s->budget--) { s->failed_pc=0x0c0c1d44u; return 0; }
r[4]+=0x00000028u;
goto P_0c0c1d46;
P_0c0c1d46: /* original d231, guest PC 0x0c0c1d46 */
if(!s->budget--) { s->failed_pc=0x0c0c1d46u; return 0; }
r[2]=read(ram,0x0c0c1e0cu,4);
goto P_0c0c1d48;
P_0c0c1d48: /* original 64f3, guest PC 0x0c0c1d48 */
if(!s->budget--) { s->failed_pc=0x0c0c1d48u; return 0; }
r[4]=r[15];
goto P_0c0c1d4a;
P_0c0c1d4a: /* original 420b, guest PC 0x0c0c1d4a */
if(!s->budget--) { s->failed_pc=0x0c0c1d4au; return 0; }
target=r[2];
r[16]=0x0c0c1d4eu;
r[4]+=0x00000028u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c1d4eu) { target=s->pc; goto dispatch; }
goto P_0c0c1d4e;
P_0c0c1d4c: /* original 7428, guest PC 0x0c0c1d4c */
if(!s->budget--) { s->failed_pc=0x0c0c1d4cu; return 0; }
r[4]+=0x00000028u;
goto P_0c0c1d4e;
P_0c0c1d4e: /* original f39d, guest PC 0x0c0c1d4e */
if(!s->budget--) { s->failed_pc=0x0c0c1d4eu; return 0; }
fr[3]=0x3f800000u;
goto P_0c0c1d50;
P_0c0c1d50: /* original fc30, guest PC 0x0c0c1d50 */
if(!s->budget--) { s->failed_pc=0x0c0c1d50u; return 0; }
fr[12]=vf3_fpu_binary(fr[12],fr[3],r[18],'+');
goto P_0c0c1d52;
P_0c0c1d52: /* original 7c01, guest PC 0x0c0c1d52 */
if(!s->budget--) { s->failed_pc=0x0c0c1d52u; return 0; }
r[12]+=0x00000001u;
goto P_0c0c1d54;
P_0c0c1d54: /* original c72e, guest PC 0x0c0c1d54 */
if(!s->budget--) { s->failed_pc=0x0c0c1d54u; return 0; }
r[0]=0x0c0c1e10u;
goto P_0c0c1d56;
P_0c0c1d56: /* original f208, guest PC 0x0c0c1d56 */
if(!s->budget--) { s->failed_pc=0x0c0c1d56u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c0c1d58;
P_0c0c1d58: /* original f2c5, guest PC 0x0c0c1d58 */
if(!s->budget--) { s->failed_pc=0x0c0c1d58u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[2])>as_float(fr[12]))!=0);
goto P_0c0c1d5a;
P_0c0c1d5a: /* original 89a2, guest PC 0x0c0c1d5a */
if(!s->budget--) { s->failed_pc=0x0c0c1d5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c1ca2; }
goto P_0c0c1d5c;
P_0c0c1d5c: /* original e278, guest PC 0x0c0c1d5c */
if(!s->budget--) { s->failed_pc=0x0c0c1d5cu; return 0; }
r[2]=0x00000078u;
goto P_0c0c1d5e;
P_0c0c1d5e: /* original 7901, guest PC 0x0c0c1d5e */
if(!s->budget--) { s->failed_pc=0x0c0c1d5eu; return 0; }
r[9]+=0x00000001u;
goto P_0c0c1d60;
P_0c0c1d60: /* original 3922, guest PC 0x0c0c1d60 */
if(!s->budget--) { s->failed_pc=0x0c0c1d60u; return 0; }
r[17]=(r[17]&~1u)|((r[9]>=r[2])!=0);
goto P_0c0c1d62;
P_0c0c1d62: /* original 8d02, guest PC 0x0c0c1d62 */
if(!s->budget--) { s->failed_pc=0x0c0c1d62u; return 0; }
cond=r[17]&1u;
r[14]+=0x00000044u;
if(cond) { goto P_0c0c1d6a; }
goto P_0c0c1d66;
P_0c0c1d64: /* original 7e44, guest PC 0x0c0c1d64 */
if(!s->budget--) { s->failed_pc=0x0c0c1d64u; return 0; }
r[14]+=0x00000044u;
goto P_0c0c1d66;
P_0c0c1d66: /* original af66, guest PC 0x0c0c1d66 */
if(!s->budget--) { s->failed_pc=0x0c0c1d66u; return 0; }
goto P_0c0c1c36;
P_0c0c1d68: /* original 0009, guest PC 0x0c0c1d68 */
if(!s->budget--) { s->failed_pc=0x0c0c1d68u; return 0; }
goto P_0c0c1d6a;
P_0c0c1d6a: /* original 7f5c, guest PC 0x0c0c1d6a */
if(!s->budget--) { s->failed_pc=0x0c0c1d6au; return 0; }
r[15]+=0x0000005cu;
goto P_0c0c1d6c;
P_0c0c1d6c: /* original 4f26, guest PC 0x0c0c1d6c */
if(!s->budget--) { s->failed_pc=0x0c0c1d6cu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c1d6e;
P_0c0c1d6e: /* original fcf9, guest PC 0x0c0c1d6e */
if(!s->budget--) { s->failed_pc=0x0c0c1d6eu; return 0; }
vf3_matrix_load(s,ram,12,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d70;
P_0c0c1d70: /* original fdf9, guest PC 0x0c0c1d70 */
if(!s->budget--) { s->failed_pc=0x0c0c1d70u; return 0; }
vf3_matrix_load(s,ram,13,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d72;
P_0c0c1d72: /* original fef9, guest PC 0x0c0c1d72 */
if(!s->budget--) { s->failed_pc=0x0c0c1d72u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d74;
P_0c0c1d74: /* original fff9, guest PC 0x0c0c1d74 */
if(!s->budget--) { s->failed_pc=0x0c0c1d74u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c0c1d76;
P_0c0c1d76: /* original 68f6, guest PC 0x0c0c1d76 */
if(!s->budget--) { s->failed_pc=0x0c0c1d76u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c1d78;
P_0c0c1d78: /* original 69f6, guest PC 0x0c0c1d78 */
if(!s->budget--) { s->failed_pc=0x0c0c1d78u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c1d7a;
P_0c0c1d7a: /* original 6af6, guest PC 0x0c0c1d7a */
if(!s->budget--) { s->failed_pc=0x0c0c1d7au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c1d7c;
P_0c0c1d7c: /* original 6bf6, guest PC 0x0c0c1d7c */
if(!s->budget--) { s->failed_pc=0x0c0c1d7cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c1d7e;
P_0c0c1d7e: /* original 6cf6, guest PC 0x0c0c1d7e */
if(!s->budget--) { s->failed_pc=0x0c0c1d7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c1d80;
P_0c0c1d80: /* original 6df6, guest PC 0x0c0c1d80 */
if(!s->budget--) { s->failed_pc=0x0c0c1d80u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c1d82;
P_0c0c1d82: /* original 000b, guest PC 0x0c0c1d82 */
if(!s->budget--) { s->failed_pc=0x0c0c1d82u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c1d84: /* original 6ef6, guest PC 0x0c0c1d84 */
if(!s->budget--) { s->failed_pc=0x0c0c1d84u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c1d86u,s,ram);
P_0c0c7114: /* original 4f22, guest PC 0x0c0c7114 */
if(!s->budget--) { s->failed_pc=0x0c0c7114u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c7116;
P_0c0c7116: /* original 906a, guest PC 0x0c0c7116 */
if(!s->budget--) { s->failed_pc=0x0c0c7116u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71eeu,2);
goto P_0c0c7118;
P_0c0c7118: /* original db38, guest PC 0x0c0c7118 */
if(!s->budget--) { s->failed_pc=0x0c0c7118u; return 0; }
r[11]=read(ram,0x0c0c71fcu,4);
goto P_0c0c711a;
P_0c0c711a: /* original 4f12, guest PC 0x0c0c711a */
if(!s->budget--) { s->failed_pc=0x0c0c711au; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c0c711c;
P_0c0c711c: /* original d338, guest PC 0x0c0c711c */
if(!s->budget--) { s->failed_pc=0x0c0c711cu; return 0; }
r[3]=read(ram,0x0c0c7200u,4);
goto P_0c0c711e;
P_0c0c711e: /* original 3f0c, guest PC 0x0c0c711e */
if(!s->budget--) { s->failed_pc=0x0c0c711eu; return 0; }
r[15]+=r[0];
goto P_0c0c7120;
P_0c0c7120: /* original e01c, guest PC 0x0c0c7120 */
if(!s->budget--) { s->failed_pc=0x0c0c7120u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7122;
P_0c0c7122: /* original 00bc, guest PC 0x0c0c7122 */
if(!s->budget--) { s->failed_pc=0x0c0c7122u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c7124;
P_0c0c7124: /* original 600c, guest PC 0x0c0c7124 */
if(!s->budget--) { s->failed_pc=0x0c0c7124u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c7126;
P_0c0c7126: /* original 2909, guest PC 0x0c0c7126 */
if(!s->budget--) { s->failed_pc=0x0c0c7126u; return 0; }
r[9]&=r[0];
goto P_0c0c7128;
P_0c0c7128: /* original 6030, guest PC 0x0c0c7128 */
if(!s->budget--) { s->failed_pc=0x0c0c7128u; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[3],1);
r[0]=tmp;
goto P_0c0c712a;
P_0c0c712a: /* original 600c, guest PC 0x0c0c712a */
if(!s->budget--) { s->failed_pc=0x0c0c712au; return 0; }
r[0]=r[0]&255u;
goto P_0c0c712c;
P_0c0c712c: /* original 8804, guest PC 0x0c0c712c */
if(!s->budget--) { s->failed_pc=0x0c0c712cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000004u)!=0);
goto P_0c0c712e;
P_0c0c712e: /* original 8b01, guest PC 0x0c0c712e */
if(!s->budget--) { s->failed_pc=0x0c0c712eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7134; }
goto P_0c0c7130;
P_0c0c7130: /* original a0b4, guest PC 0x0c0c7130 */
if(!s->budget--) { s->failed_pc=0x0c0c7130u; return 0; }
goto P_0c0c729c;
P_0c0c7132: /* original 0009, guest PC 0x0c0c7132 */
if(!s->budget--) { s->failed_pc=0x0c0c7132u; return 0; }
goto P_0c0c7134;
P_0c0c7134: /* original 6242, guest PC 0x0c0c7134 */
if(!s->budget--) { s->failed_pc=0x0c0c7134u; return 0; }
tmp=read(ram,r[4],4);
r[2]=tmp;
goto P_0c0c7136;
P_0c0c7136: /* original 935b, guest PC 0x0c0c7136 */
if(!s->budget--) { s->failed_pc=0x0c0c7136u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f0u,2);
goto P_0c0c7138;
P_0c0c7138: /* original 2238, guest PC 0x0c0c7138 */
if(!s->budget--) { s->failed_pc=0x0c0c7138u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c0c713a;
P_0c0c713a: /* original 8901, guest PC 0x0c0c713a */
if(!s->budget--) { s->failed_pc=0x0c0c713au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7140; }
goto P_0c0c713c;
P_0c0c713c: /* original a0ae, guest PC 0x0c0c713c */
if(!s->budget--) { s->failed_pc=0x0c0c713cu; return 0; }
goto P_0c0c729c;
P_0c0c713e: /* original 0009, guest PC 0x0c0c713e */
if(!s->budget--) { s->failed_pc=0x0c0c713eu; return 0; }
goto P_0c0c7140;
P_0c0c7140: /* original 9057, guest PC 0x0c0c7140 */
if(!s->budget--) { s->failed_pc=0x0c0c7140u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f2u,2);
goto P_0c0c7142;
P_0c0c7142: /* original ec00, guest PC 0x0c0c7142 */
if(!s->budget--) { s->failed_pc=0x0c0c7142u; return 0; }
r[12]=0x00000000u;
goto P_0c0c7144;
P_0c0c7144: /* original 004c, guest PC 0x0c0c7144 */
if(!s->budget--) { s->failed_pc=0x0c0c7144u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7146;
P_0c0c7146: /* original 8817, guest PC 0x0c0c7146 */
if(!s->budget--) { s->failed_pc=0x0c0c7146u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000017u)!=0);
goto P_0c0c7148;
P_0c0c7148: /* original 8d08, guest PC 0x0c0c7148 */
if(!s->budget--) { s->failed_pc=0x0c0c7148u; return 0; }
cond=r[17]&1u;
r[8]=0x00000020u;
if(cond) { goto P_0c0c715c; }
goto P_0c0c714c;
P_0c0c714a: /* original e820, guest PC 0x0c0c714a */
if(!s->budget--) { s->failed_pc=0x0c0c714au; return 0; }
r[8]=0x00000020u;
goto P_0c0c714c;
P_0c0c714c: /* original 9051, guest PC 0x0c0c714c */
if(!s->budget--) { s->failed_pc=0x0c0c714cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f2u,2);
goto P_0c0c714e;
P_0c0c714e: /* original 004c, guest PC 0x0c0c714e */
if(!s->budget--) { s->failed_pc=0x0c0c714eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7150;
P_0c0c7150: /* original 8807, guest PC 0x0c0c7150 */
if(!s->budget--) { s->failed_pc=0x0c0c7150u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c7152;
P_0c0c7152: /* original 8903, guest PC 0x0c0c7152 */
if(!s->budget--) { s->failed_pc=0x0c0c7152u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c715c; }
goto P_0c0c7154;
P_0c0c7154: /* original 904e, guest PC 0x0c0c7154 */
if(!s->budget--) { s->failed_pc=0x0c0c7154u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f4u,2);
goto P_0c0c7156;
P_0c0c7156: /* original 034c, guest PC 0x0c0c7156 */
if(!s->budget--) { s->failed_pc=0x0c0c7156u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7158;
P_0c0c7158: /* original 3387, guest PC 0x0c0c7158 */
if(!s->budget--) { s->failed_pc=0x0c0c7158u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>(int32_t)r[8])!=0);
goto P_0c0c715a;
P_0c0c715a: /* original 8903, guest PC 0x0c0c715a */
if(!s->budget--) { s->failed_pc=0x0c0c715au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7164; }
goto P_0c0c715c;
P_0c0c715c: /* original 904b, guest PC 0x0c0c715c */
if(!s->budget--) { s->failed_pc=0x0c0c715cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f6u,2);
goto P_0c0c715e;
P_0c0c715e: /* original 004c, guest PC 0x0c0c715e */
if(!s->budget--) { s->failed_pc=0x0c0c715eu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7160;
P_0c0c7160: /* original 8803, guest PC 0x0c0c7160 */
if(!s->budget--) { s->failed_pc=0x0c0c7160u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000003u)!=0);
goto P_0c0c7162;
P_0c0c7162: /* original 8b0a, guest PC 0x0c0c7162 */
if(!s->budget--) { s->failed_pc=0x0c0c7162u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c717a; }
goto P_0c0c7164;
P_0c0c7164: /* original 6093, guest PC 0x0c0c7164 */
if(!s->budget--) { s->failed_pc=0x0c0c7164u; return 0; }
r[0]=r[9];
goto P_0c0c7166;
P_0c0c7166: /* original 8802, guest PC 0x0c0c7166 */
if(!s->budget--) { s->failed_pc=0x0c0c7166u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c0c7168;
P_0c0c7168: /* original 8d06, guest PC 0x0c0c7168 */
if(!s->budget--) { s->failed_pc=0x0c0c7168u; return 0; }
cond=r[17]&1u;
r[4]=0x00000009u;
if(cond) { goto P_0c0c7178; }
goto P_0c0c716c;
P_0c0c716a: /* original e409, guest PC 0x0c0c716a */
if(!s->budget--) { s->failed_pc=0x0c0c716au; return 0; }
r[4]=0x00000009u;
goto P_0c0c716c;
P_0c0c716c: /* original 8807, guest PC 0x0c0c716c */
if(!s->budget--) { s->failed_pc=0x0c0c716cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c716e;
P_0c0c716e: /* original 8901, guest PC 0x0c0c716e */
if(!s->budget--) { s->failed_pc=0x0c0c716eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7174; }
goto P_0c0c7170;
P_0c0c7170: /* original 880e, guest PC 0x0c0c7170 */
if(!s->budget--) { s->failed_pc=0x0c0c7170u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000eu)!=0);
goto P_0c0c7172;
P_0c0c7172: /* original 8b02, guest PC 0x0c0c7172 */
if(!s->budget--) { s->failed_pc=0x0c0c7172u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c717a; }
goto P_0c0c7174;
P_0c0c7174: /* original a001, guest PC 0x0c0c7174 */
if(!s->budget--) { s->failed_pc=0x0c0c7174u; return 0; }
r[12]=r[4];
goto P_0c0c717a;
P_0c0c7176: /* original 6c43, guest PC 0x0c0c7176 */
if(!s->budget--) { s->failed_pc=0x0c0c7176u; return 0; }
r[12]=r[4];
goto P_0c0c7178;
P_0c0c7178: /* original ec01, guest PC 0x0c0c7178 */
if(!s->budget--) { s->failed_pc=0x0c0c7178u; return 0; }
r[12]=0x00000001u;
goto P_0c0c717a;
P_0c0c717a: /* original d322, guest PC 0x0c0c717a */
if(!s->budget--) { s->failed_pc=0x0c0c717au; return 0; }
r[3]=read(ram,0x0c0c7204u,4);
goto P_0c0c717c;
P_0c0c717c: /* original 430b, guest PC 0x0c0c717c */
if(!s->budget--) { s->failed_pc=0x0c0c717cu; return 0; }
target=r[3];
r[16]=0x0c0c7180u;
r[4]=0x00000000u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7180u) { target=s->pc; goto dispatch; }
goto P_0c0c7180;
P_0c0c717e: /* original e400, guest PC 0x0c0c717e */
if(!s->budget--) { s->failed_pc=0x0c0c717eu; return 0; }
r[4]=0x00000000u;
goto P_0c0c7180;
P_0c0c7180: /* original d221, guest PC 0x0c0c7180 */
if(!s->budget--) { s->failed_pc=0x0c0c7180u; return 0; }
r[2]=read(ram,0x0c0c7208u,4);
goto P_0c0c7182;
P_0c0c7182: /* original 420b, guest PC 0x0c0c7182 */
if(!s->budget--) { s->failed_pc=0x0c0c7182u; return 0; }
target=r[2];
r[16]=0x0c0c7186u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7186u) { target=s->pc; goto dispatch; }
goto P_0c0c7186;
P_0c0c7184: /* original 0009, guest PC 0x0c0c7184 */
if(!s->budget--) { s->failed_pc=0x0c0c7184u; return 0; }
goto P_0c0c7186;
P_0c0c7186: /* original 6093, guest PC 0x0c0c7186 */
if(!s->budget--) { s->failed_pc=0x0c0c7186u; return 0; }
r[0]=r[9];
goto P_0c0c7188;
P_0c0c7188: /* original d120, guest PC 0x0c0c7188 */
if(!s->budget--) { s->failed_pc=0x0c0c7188u; return 0; }
r[1]=read(ram,0x0c0c720cu,4);
goto P_0c0c718a;
P_0c0c718a: /* original 4008, guest PC 0x0c0c718a */
if(!s->budget--) { s->failed_pc=0x0c0c718au; return 0; }
r[0]<<=2;
goto P_0c0c718c;
P_0c0c718c: /* original 4000, guest PC 0x0c0c718c */
if(!s->budget--) { s->failed_pc=0x0c0c718cu; return 0; }
r[17]=(r[17]&~1u)|((r[0]>>31)!=0);
r[0]<<=1;
goto P_0c0c718e;
P_0c0c718e: /* original 001e, guest PC 0x0c0c718e */
if(!s->budget--) { s->failed_pc=0x0c0c718eu; return 0; }
r[0]=read(ram,r[1]+r[0],4);
goto P_0c0c7190;
P_0c0c7190: /* original 88ff, guest PC 0x0c0c7190 */
if(!s->budget--) { s->failed_pc=0x0c0c7190u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0xffffffffu)!=0);
goto P_0c0c7192;
P_0c0c7192: /* original 8975, guest PC 0x0c0c7192 */
if(!s->budget--) { s->failed_pc=0x0c0c7192u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7280; }
goto P_0c0c7194;
P_0c0c7194: /* original d21e, guest PC 0x0c0c7194 */
if(!s->budget--) { s->failed_pc=0x0c0c7194u; return 0; }
r[2]=read(ram,0x0c0c7210u,4);
goto P_0c0c7196;
P_0c0c7196: /* original 6a22, guest PC 0x0c0c7196 */
if(!s->budget--) { s->failed_pc=0x0c0c7196u; return 0; }
tmp=read(ram,r[2],4);
r[10]=tmp;
goto P_0c0c7198;
P_0c0c7198: /* original 2aa8, guest PC 0x0c0c7198 */
if(!s->budget--) { s->failed_pc=0x0c0c7198u; return 0; }
r[17]=(r[17]&~1u)|(((r[10]&r[10])==0)!=0);
goto P_0c0c719a;
P_0c0c719a: /* original 8971, guest PC 0x0c0c719a */
if(!s->budget--) { s->failed_pc=0x0c0c719au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7280; }
goto P_0c0c719c;
P_0c0c719c: /* original 6093, guest PC 0x0c0c719c */
if(!s->budget--) { s->failed_pc=0x0c0c719cu; return 0; }
r[0]=r[9];
goto P_0c0c719e;
P_0c0c719e: /* original de1d, guest PC 0x0c0c719e */
if(!s->budget--) { s->failed_pc=0x0c0c719eu; return 0; }
r[14]=read(ram,0x0c0c7214u,4);
goto P_0c0c71a0;
P_0c0c71a0: /* original 9d2a, guest PC 0x0c0c71a0 */
if(!s->budget--) { s->failed_pc=0x0c0c71a0u; return 0; }
r[13]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71f8u,2);
goto P_0c0c71a2;
P_0c0c71a2: /* original 8801, guest PC 0x0c0c71a2 */
if(!s->budget--) { s->failed_pc=0x0c0c71a2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c0c71a4;
P_0c0c71a4: /* original 893a, guest PC 0x0c0c71a4 */
if(!s->budget--) { s->failed_pc=0x0c0c71a4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c721c; }
goto P_0c0c71a6;
P_0c0c71a6: /* original d01c, guest PC 0x0c0c71a6 */
if(!s->budget--) { s->failed_pc=0x0c0c71a6u; return 0; }
r[0]=read(ram,0x0c0c7218u,4);
goto P_0c0c71a8;
P_0c0c71a8: /* original 6302, guest PC 0x0c0c71a8 */
if(!s->budget--) { s->failed_pc=0x0c0c71a8u; return 0; }
tmp=read(ram,r[0],4);
r[3]=tmp;
goto P_0c0c71aa;
P_0c0c71aa: /* original 2838, guest PC 0x0c0c71aa */
if(!s->budget--) { s->failed_pc=0x0c0c71aau; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0c71ac;
P_0c0c71ac: /* original 8b04, guest PC 0x0c0c71ac */
if(!s->budget--) { s->failed_pc=0x0c0c71acu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c71b8; }
goto P_0c0c71ae;
P_0c0c71ae: /* original e01c, guest PC 0x0c0c71ae */
if(!s->budget--) { s->failed_pc=0x0c0c71aeu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c71b0;
P_0c0c71b0: /* original 00bc, guest PC 0x0c0c71b0 */
if(!s->budget--) { s->failed_pc=0x0c0c71b0u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c71b2;
P_0c0c71b2: /* original 600c, guest PC 0x0c0c71b2 */
if(!s->budget--) { s->failed_pc=0x0c0c71b2u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c71b4;
P_0c0c71b4: /* original 881f, guest PC 0x0c0c71b4 */
if(!s->budget--) { s->failed_pc=0x0c0c71b4u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c71b6;
P_0c0c71b6: /* original 8b0b, guest PC 0x0c0c71b6 */
if(!s->budget--) { s->failed_pc=0x0c0c71b6u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c71d0; }
goto P_0c0c71b8;
P_0c0c71b8: /* original 4e0b, guest PC 0x0c0c71b8 */
if(!s->budget--) { s->failed_pc=0x0c0c71b8u; return 0; }
target=r[14];
r[16]=0x0c0c71bcu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c71bcu) { target=s->pc; goto dispatch; }
goto P_0c0c71bc;
P_0c0c71ba: /* original 64d3, guest PC 0x0c0c71ba */
if(!s->budget--) { s->failed_pc=0x0c0c71bau; return 0; }
r[4]=r[13];
goto P_0c0c71bc;
P_0c0c71bc: /* original e01c, guest PC 0x0c0c71bc */
if(!s->budget--) { s->failed_pc=0x0c0c71bcu; return 0; }
r[0]=0x0000001cu;
goto P_0c0c71be;
P_0c0c71be: /* original 00bc, guest PC 0x0c0c71be */
if(!s->budget--) { s->failed_pc=0x0c0c71beu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c71c0;
P_0c0c71c0: /* original 600c, guest PC 0x0c0c71c0 */
if(!s->budget--) { s->failed_pc=0x0c0c71c0u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c71c2;
P_0c0c71c2: /* original 881f, guest PC 0x0c0c71c2 */
if(!s->budget--) { s->failed_pc=0x0c0c71c2u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000001fu)!=0);
goto P_0c0c71c4;
P_0c0c71c4: /* original 8b5c, guest PC 0x0c0c71c4 */
if(!s->budget--) { s->failed_pc=0x0c0c71c4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c71c6;
P_0c0c71c6: /* original 9418, guest PC 0x0c0c71c6 */
if(!s->budget--) { s->failed_pc=0x0c0c71c6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c71fau,2);
goto P_0c0c71c8;
P_0c0c71c8: /* original 4e0b, guest PC 0x0c0c71c8 */
if(!s->budget--) { s->failed_pc=0x0c0c71c8u; return 0; }
target=r[14];
r[16]=0x0c0c71ccu;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c71ccu) { target=s->pc; goto dispatch; }
goto P_0c0c71cc;
P_0c0c71ca: /* original 0009, guest PC 0x0c0c71ca */
if(!s->budget--) { s->failed_pc=0x0c0c71cau; return 0; }
goto P_0c0c71cc;
P_0c0c71cc: /* original a058, guest PC 0x0c0c71cc */
if(!s->budget--) { s->failed_pc=0x0c0c71ccu; return 0; }
goto P_0c0c7280;
P_0c0c71ce: /* original 0009, guest PC 0x0c0c71ce */
if(!s->budget--) { s->failed_pc=0x0c0c71ceu; return 0; }
goto P_0c0c71d0;
P_0c0c71d0: /* original 85a6, guest PC 0x0c0c71d0 */
if(!s->budget--) { s->failed_pc=0x0c0c71d0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c71d2;
P_0c0c71d2: /* original 600d, guest PC 0x0c0c71d2 */
if(!s->budget--) { s->failed_pc=0x0c0c71d2u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c71d4;
P_0c0c71d4: /* original 6303, guest PC 0x0c0c71d4 */
if(!s->budget--) { s->failed_pc=0x0c0c71d4u; return 0; }
r[3]=r[0];
goto P_0c0c71d6;
P_0c0c71d6: /* original 33c8, guest PC 0x0c0c71d6 */
if(!s->budget--) { s->failed_pc=0x0c0c71d6u; return 0; }
r[3]-=r[12];
goto P_0c0c71d8;
P_0c0c71d8: /* original 6c33, guest PC 0x0c0c71d8 */
if(!s->budget--) { s->failed_pc=0x0c0c71d8u; return 0; }
r[12]=r[3];
goto P_0c0c71da;
P_0c0c71da: /* original 4c15, guest PC 0x0c0c71da */
if(!s->budget--) { s->failed_pc=0x0c0c71dau; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c71dc;
P_0c0c71dc: /* original 8b50, guest PC 0x0c0c71dc */
if(!s->budget--) { s->failed_pc=0x0c0c71dcu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c71de;
P_0c0c71de: /* original 64d3, guest PC 0x0c0c71de */
if(!s->budget--) { s->failed_pc=0x0c0c71deu; return 0; }
r[4]=r[13];
goto P_0c0c71e0;
P_0c0c71e0: /* original 4e0b, guest PC 0x0c0c71e0 */
if(!s->budget--) { s->failed_pc=0x0c0c71e0u; return 0; }
target=r[14];
r[16]=0x0c0c71e4u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c71e4u) { target=s->pc; goto dispatch; }
goto P_0c0c71e4;
P_0c0c71e2: /* original 7d01, guest PC 0x0c0c71e2 */
if(!s->budget--) { s->failed_pc=0x0c0c71e2u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c71e4;
P_0c0c71e4: /* original 7cff, guest PC 0x0c0c71e4 */
if(!s->budget--) { s->failed_pc=0x0c0c71e4u; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c71e6;
P_0c0c71e6: /* original 4c15, guest PC 0x0c0c71e6 */
if(!s->budget--) { s->failed_pc=0x0c0c71e6u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c71e8;
P_0c0c71e8: /* original 89f9, guest PC 0x0c0c71e8 */
if(!s->budget--) { s->failed_pc=0x0c0c71e8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c71de; }
goto P_0c0c71ea;
P_0c0c71ea: /* original a049, guest PC 0x0c0c71ea */
if(!s->budget--) { s->failed_pc=0x0c0c71eau; return 0; }
goto P_0c0c7280;
P_0c0c71ec: /* original 0009, guest PC 0x0c0c71ec */
if(!s->budget--) { s->failed_pc=0x0c0c71ecu; return 0; }
return vf3_matrix_family(0x0c0c71eeu,s,ram);
P_0c0c721c: /* original c726, guest PC 0x0c0c721c */
if(!s->budget--) { s->failed_pc=0x0c0c721cu; return 0; }
r[0]=0x0c0c72b8u;
goto P_0c0c721e;
P_0c0c721e: /* original d328, guest PC 0x0c0c721e */
if(!s->budget--) { s->failed_pc=0x0c0c721eu; return 0; }
r[3]=read(ram,0x0c0c72c0u,4);
goto P_0c0c7220;
P_0c0c7220: /* original f508, guest PC 0x0c0c7220 */
if(!s->budget--) { s->failed_pc=0x0c0c7220u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c7222;
P_0c0c7222: /* original e400, guest PC 0x0c0c7222 */
if(!s->budget--) { s->failed_pc=0x0c0c7222u; return 0; }
r[4]=0x00000000u;
goto P_0c0c7224;
P_0c0c7224: /* original c725, guest PC 0x0c0c7224 */
if(!s->budget--) { s->failed_pc=0x0c0c7224u; return 0; }
r[0]=0x0c0c72bcu;
goto P_0c0c7226;
P_0c0c7226: /* original 430b, guest PC 0x0c0c7226 */
if(!s->budget--) { s->failed_pc=0x0c0c7226u; return 0; }
target=r[3];
r[16]=0x0c0c722au;
vf3_matrix_load(s,ram,4,r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c722au) { target=s->pc; goto dispatch; }
goto P_0c0c722a;
P_0c0c7228: /* original f408, guest PC 0x0c0c7228 */
if(!s->budget--) { s->failed_pc=0x0c0c7228u; return 0; }
vf3_matrix_load(s,ram,4,r[0]);
goto P_0c0c722a;
P_0c0c722a: /* original 64d3, guest PC 0x0c0c722a */
if(!s->budget--) { s->failed_pc=0x0c0c722au; return 0; }
r[4]=r[13];
goto P_0c0c722c;
P_0c0c722c: /* original 4e0b, guest PC 0x0c0c722c */
if(!s->budget--) { s->failed_pc=0x0c0c722cu; return 0; }
target=r[14];
r[16]=0x0c0c7230u;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c7230u) { target=s->pc; goto dispatch; }
goto P_0c0c7230;
P_0c0c722e: /* original 7d01, guest PC 0x0c0c722e */
if(!s->budget--) { s->failed_pc=0x0c0c722eu; return 0; }
r[13]+=0x00000001u;
goto P_0c0c7230;
P_0c0c7230: /* original e334, guest PC 0x0c0c7230 */
if(!s->budget--) { s->failed_pc=0x0c0c7230u; return 0; }
r[3]=0x00000034u;
goto P_0c0c7232;
P_0c0c7232: /* original e01c, guest PC 0x0c0c7232 */
if(!s->budget--) { s->failed_pc=0x0c0c7232u; return 0; }
r[0]=0x0000001cu;
goto P_0c0c7234;
P_0c0c7234: /* original 02bc, guest PC 0x0c0c7234 */
if(!s->budget--) { s->failed_pc=0x0c0c7234u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c7236;
P_0c0c7236: /* original 2f20, guest PC 0x0c0c7236 */
if(!s->budget--) { s->failed_pc=0x0c0c7236u; return 0; }
write(ram,r[15],r[2],1);
goto P_0c0c7238;
P_0c0c7238: /* original 622c, guest PC 0x0c0c7238 */
if(!s->budget--) { s->failed_pc=0x0c0c7238u; return 0; }
r[2]=r[2]&255u;
goto P_0c0c723a;
P_0c0c723a: /* original 64f0, guest PC 0x0c0c723a */
if(!s->budget--) { s->failed_pc=0x0c0c723au; return 0; }
tmp=(uint32_t)(int32_t)(int8_t)read(ram,r[15],1);
r[4]=tmp;
goto P_0c0c723c;
P_0c0c723c: /* original 4208, guest PC 0x0c0c723c */
if(!s->budget--) { s->failed_pc=0x0c0c723cu; return 0; }
r[2]<<=2;
goto P_0c0c723e;
P_0c0c723e: /* original d022, guest PC 0x0c0c723e */
if(!s->budget--) { s->failed_pc=0x0c0c723eu; return 0; }
r[0]=read(ram,0x0c0c72c8u,4);
goto P_0c0c7240;
P_0c0c7240: /* original 4208, guest PC 0x0c0c7240 */
if(!s->budget--) { s->failed_pc=0x0c0c7240u; return 0; }
r[2]<<=2;
goto P_0c0c7242;
P_0c0c7242: /* original 644c, guest PC 0x0c0c7242 */
if(!s->budget--) { s->failed_pc=0x0c0c7242u; return 0; }
r[4]=r[4]&255u;
goto P_0c0c7244;
P_0c0c7244: /* original db1f, guest PC 0x0c0c7244 */
if(!s->budget--) { s->failed_pc=0x0c0c7244u; return 0; }
r[11]=read(ram,0x0c0c72c4u,4);
goto P_0c0c7246;
P_0c0c7246: /* original 243f, guest PC 0x0c0c7246 */
if(!s->budget--) { s->failed_pc=0x0c0c7246u; return 0; }
r[19]=(uint32_t)((int32_t)(int16_t)r[4]*(int32_t)(int16_t)r[3]);
goto P_0c0c7248;
P_0c0c7248: /* original 4208, guest PC 0x0c0c7248 */
if(!s->budget--) { s->failed_pc=0x0c0c7248u; return 0; }
r[2]<<=2;
goto P_0c0c724a;
P_0c0c724a: /* original 3b2c, guest PC 0x0c0c724a */
if(!s->budget--) { s->failed_pc=0x0c0c724au; return 0; }
r[11]+=r[2];
goto P_0c0c724c;
P_0c0c724c: /* original d21c, guest PC 0x0c0c724c */
if(!s->budget--) { s->failed_pc=0x0c0c724cu; return 0; }
r[2]=read(ram,0x0c0c72c0u,4);
goto P_0c0c724e;
P_0c0c724e: /* original 041a, guest PC 0x0c0c724e */
if(!s->budget--) { s->failed_pc=0x0c0c724eu; return 0; }
r[4]=r[19];
goto P_0c0c7250;
P_0c0c7250: /* original 644f, guest PC 0x0c0c7250 */
if(!s->budget--) { s->failed_pc=0x0c0c7250u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)r[4];
goto P_0c0c7252;
P_0c0c7252: /* original 044c, guest PC 0x0c0c7252 */
if(!s->budget--) { s->failed_pc=0x0c0c7252u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[4]+r[0],1);
goto P_0c0c7254;
P_0c0c7254: /* original e010, guest PC 0x0c0c7254 */
if(!s->budget--) { s->failed_pc=0x0c0c7254u; return 0; }
r[0]=0x00000010u;
goto P_0c0c7256;
P_0c0c7256: /* original f5b6, guest PC 0x0c0c7256 */
if(!s->budget--) { s->failed_pc=0x0c0c7256u; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c0c7258;
P_0c0c7258: /* original e014, guest PC 0x0c0c7258 */
if(!s->budget--) { s->failed_pc=0x0c0c7258u; return 0; }
r[0]=0x00000014u;
goto P_0c0c725a;
P_0c0c725a: /* original 420b, guest PC 0x0c0c725a */
if(!s->budget--) { s->failed_pc=0x0c0c725au; return 0; }
target=r[2];
r[16]=0x0c0c725eu;
vf3_matrix_load(s,ram,4,r[11]+r[0]);
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c725eu) { target=s->pc; goto dispatch; }
goto P_0c0c725e;
P_0c0c725c: /* original f4b6, guest PC 0x0c0c725c */
if(!s->budget--) { s->failed_pc=0x0c0c725cu; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c0c725e;
P_0c0c725e: /* original d21b, guest PC 0x0c0c725e */
if(!s->budget--) { s->failed_pc=0x0c0c725eu; return 0; }
r[2]=read(ram,0x0c0c72ccu,4);
goto P_0c0c7260;
P_0c0c7260: /* original 6322, guest PC 0x0c0c7260 */
if(!s->budget--) { s->failed_pc=0x0c0c7260u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c0c7262;
P_0c0c7262: /* original 2838, guest PC 0x0c0c7262 */
if(!s->budget--) { s->failed_pc=0x0c0c7262u; return 0; }
r[17]=(r[17]&~1u)|(((r[8]&r[3])==0)!=0);
goto P_0c0c7264;
P_0c0c7264: /* original 8b0c, guest PC 0x0c0c7264 */
if(!s->budget--) { s->failed_pc=0x0c0c7264u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c7266;
P_0c0c7266: /* original 85a6, guest PC 0x0c0c7266 */
if(!s->budget--) { s->failed_pc=0x0c0c7266u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,r[10]+12,2);
goto P_0c0c7268;
P_0c0c7268: /* original 600d, guest PC 0x0c0c7268 */
if(!s->budget--) { s->failed_pc=0x0c0c7268u; return 0; }
r[0]=r[0]&65535u;
goto P_0c0c726a;
P_0c0c726a: /* original 30c8, guest PC 0x0c0c726a */
if(!s->budget--) { s->failed_pc=0x0c0c726au; return 0; }
r[0]-=r[12];
goto P_0c0c726c;
P_0c0c726c: /* original 6c03, guest PC 0x0c0c726c */
if(!s->budget--) { s->failed_pc=0x0c0c726cu; return 0; }
r[12]=r[0];
goto P_0c0c726e;
P_0c0c726e: /* original 7cff, guest PC 0x0c0c726e */
if(!s->budget--) { s->failed_pc=0x0c0c726eu; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c7270;
P_0c0c7270: /* original 4c15, guest PC 0x0c0c7270 */
if(!s->budget--) { s->failed_pc=0x0c0c7270u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c7272;
P_0c0c7272: /* original 8b05, guest PC 0x0c0c7272 */
if(!s->budget--) { s->failed_pc=0x0c0c7272u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c7280; }
goto P_0c0c7274;
P_0c0c7274: /* original 64d3, guest PC 0x0c0c7274 */
if(!s->budget--) { s->failed_pc=0x0c0c7274u; return 0; }
r[4]=r[13];
goto P_0c0c7276;
P_0c0c7276: /* original 4e0b, guest PC 0x0c0c7276 */
if(!s->budget--) { s->failed_pc=0x0c0c7276u; return 0; }
target=r[14];
r[16]=0x0c0c727au;
r[13]+=0x00000001u;
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c727au) { target=s->pc; goto dispatch; }
goto P_0c0c727a;
P_0c0c7278: /* original 7d01, guest PC 0x0c0c7278 */
if(!s->budget--) { s->failed_pc=0x0c0c7278u; return 0; }
r[13]+=0x00000001u;
goto P_0c0c727a;
P_0c0c727a: /* original 7cff, guest PC 0x0c0c727a */
if(!s->budget--) { s->failed_pc=0x0c0c727au; return 0; }
r[12]+=0xffffffffu;
goto P_0c0c727c;
P_0c0c727c: /* original 4c15, guest PC 0x0c0c727c */
if(!s->budget--) { s->failed_pc=0x0c0c727cu; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>0)!=0);
goto P_0c0c727e;
P_0c0c727e: /* original 89f9, guest PC 0x0c0c727e */
if(!s->budget--) { s->failed_pc=0x0c0c727eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c7274; }
goto P_0c0c7280;
P_0c0c7280: /* original 9118, guest PC 0x0c0c7280 */
if(!s->budget--) { s->failed_pc=0x0c0c7280u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c72b4u,2);
goto P_0c0c7282;
P_0c0c7282: /* original e401, guest PC 0x0c0c7282 */
if(!s->budget--) { s->failed_pc=0x0c0c7282u; return 0; }
r[4]=0x00000001u;
goto P_0c0c7284;
P_0c0c7284: /* original d312, guest PC 0x0c0c7284 */
if(!s->budget--) { s->failed_pc=0x0c0c7284u; return 0; }
r[3]=read(ram,0x0c0c72d0u,4);
goto P_0c0c7286;
P_0c0c7286: /* original 3f1c, guest PC 0x0c0c7286 */
if(!s->budget--) { s->failed_pc=0x0c0c7286u; return 0; }
r[15]+=r[1];
goto P_0c0c7288;
P_0c0c7288: /* original 4f16, guest PC 0x0c0c7288 */
if(!s->budget--) { s->failed_pc=0x0c0c7288u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c728a;
P_0c0c728a: /* original 4f26, guest PC 0x0c0c728a */
if(!s->budget--) { s->failed_pc=0x0c0c728au; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c728c;
P_0c0c728c: /* original 68f6, guest PC 0x0c0c728c */
if(!s->budget--) { s->failed_pc=0x0c0c728cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c728e;
P_0c0c728e: /* original 69f6, guest PC 0x0c0c728e */
if(!s->budget--) { s->failed_pc=0x0c0c728eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c7290;
P_0c0c7290: /* original 6af6, guest PC 0x0c0c7290 */
if(!s->budget--) { s->failed_pc=0x0c0c7290u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c7292;
P_0c0c7292: /* original 6bf6, guest PC 0x0c0c7292 */
if(!s->budget--) { s->failed_pc=0x0c0c7292u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c7294;
P_0c0c7294: /* original 6cf6, guest PC 0x0c0c7294 */
if(!s->budget--) { s->failed_pc=0x0c0c7294u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c7296;
P_0c0c7296: /* original 6df6, guest PC 0x0c0c7296 */
if(!s->budget--) { s->failed_pc=0x0c0c7296u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c7298;
P_0c0c7298: /* original 432b, guest PC 0x0c0c7298 */
if(!s->budget--) { s->failed_pc=0x0c0c7298u; return 0; }
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
P_0c0c729a: /* original 6ef6, guest PC 0x0c0c729a */
if(!s->budget--) { s->failed_pc=0x0c0c729au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
goto P_0c0c729c;
P_0c0c729c: /* original 910a, guest PC 0x0c0c729c */
if(!s->budget--) { s->failed_pc=0x0c0c729cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c72b4u,2);
goto P_0c0c729e;
P_0c0c729e: /* original 3f1c, guest PC 0x0c0c729e */
if(!s->budget--) { s->failed_pc=0x0c0c729eu; return 0; }
r[15]+=r[1];
goto P_0c0c72a0;
P_0c0c72a0: /* original 4f16, guest PC 0x0c0c72a0 */
if(!s->budget--) { s->failed_pc=0x0c0c72a0u; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c72a2;
P_0c0c72a2: /* original 4f26, guest PC 0x0c0c72a2 */
if(!s->budget--) { s->failed_pc=0x0c0c72a2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c72a4;
P_0c0c72a4: /* original 68f6, guest PC 0x0c0c72a4 */
if(!s->budget--) { s->failed_pc=0x0c0c72a4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c0c72a6;
P_0c0c72a6: /* original 69f6, guest PC 0x0c0c72a6 */
if(!s->budget--) { s->failed_pc=0x0c0c72a6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c72a8;
P_0c0c72a8: /* original 6af6, guest PC 0x0c0c72a8 */
if(!s->budget--) { s->failed_pc=0x0c0c72a8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c72aa;
P_0c0c72aa: /* original 6bf6, guest PC 0x0c0c72aa */
if(!s->budget--) { s->failed_pc=0x0c0c72aau; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c72ac;
P_0c0c72ac: /* original 6cf6, guest PC 0x0c0c72ac */
if(!s->budget--) { s->failed_pc=0x0c0c72acu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c72ae;
P_0c0c72ae: /* original 6df6, guest PC 0x0c0c72ae */
if(!s->budget--) { s->failed_pc=0x0c0c72aeu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c72b0;
P_0c0c72b0: /* original 000b, guest PC 0x0c0c72b0 */
if(!s->budget--) { s->failed_pc=0x0c0c72b0u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c72b2: /* original 6ef6, guest PC 0x0c0c72b2 */
if(!s->budget--) { s->failed_pc=0x0c0c72b2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c72b4u,s,ram);
P_0c0c9dc8: /* original 4f22, guest PC 0x0c0c9dc8 */
if(!s->budget--) { s->failed_pc=0x0c0c9dc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0c9dca;
P_0c0c9dca: /* original d32a, guest PC 0x0c0c9dca */
if(!s->budget--) { s->failed_pc=0x0c0c9dcau; return 0; }
r[3]=read(ram,0x0c0c9e74u,4);
goto P_0c0c9dcc;
P_0c0c9dcc: /* original 7ff4, guest PC 0x0c0c9dcc */
if(!s->budget--) { s->failed_pc=0x0c0c9dccu; return 0; }
r[15]+=0xfffffff4u;
goto P_0c0c9dce;
P_0c0c9dce: /* original 2f32, guest PC 0x0c0c9dce */
if(!s->budget--) { s->failed_pc=0x0c0c9dceu; return 0; }
write(ram,r[15],r[3],4);
goto P_0c0c9dd0;
P_0c0c9dd0: /* original 8f02, guest PC 0x0c0c9dd0 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd0u; return 0; }
cond=r[17]&1u;
r[13]=0x00000001u;
if(!cond) { goto P_0c0c9dd8; }
goto P_0c0c9dd4;
P_0c0c9dd2: /* original ed01, guest PC 0x0c0c9dd2 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd2u; return 0; }
r[13]=0x00000001u;
goto P_0c0c9dd4;
P_0c0c9dd4: /* original a001, guest PC 0x0c0c9dd4 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd4u; return 0; }
r[5]=r[12];
goto P_0c0c9dda;
P_0c0c9dd6: /* original 65c3, guest PC 0x0c0c9dd6 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd6u; return 0; }
r[5]=r[12];
goto P_0c0c9dd8;
P_0c0c9dd8: /* original 65d3, guest PC 0x0c0c9dd8 */
if(!s->budget--) { s->failed_pc=0x0c0c9dd8u; return 0; }
r[5]=r[13];
goto P_0c0c9dda;
P_0c0c9dda: /* original d027, guest PC 0x0c0c9dda */
if(!s->budget--) { s->failed_pc=0x0c0c9ddau; return 0; }
r[0]=read(ram,0x0c0c9e78u,4);
goto P_0c0c9ddc;
P_0c0c9ddc: /* original 6943, guest PC 0x0c0c9ddc */
if(!s->budget--) { s->failed_pc=0x0c0c9ddcu; return 0; }
r[9]=r[4];
goto P_0c0c9dde;
P_0c0c9dde: /* original 4908, guest PC 0x0c0c9dde */
if(!s->budget--) { s->failed_pc=0x0c0c9ddeu; return 0; }
r[9]<<=2;
goto P_0c0c9de0;
P_0c0c9de0: /* original da26, guest PC 0x0c0c9de0 */
if(!s->budget--) { s->failed_pc=0x0c0c9de0u; return 0; }
r[10]=read(ram,0x0c0c9e7cu,4);
goto P_0c0c9de2;
P_0c0c9de2: /* original 099e, guest PC 0x0c0c9de2 */
if(!s->budget--) { s->failed_pc=0x0c0c9de2u; return 0; }
r[9]=read(ram,r[9]+r[0],4);
goto P_0c0c9de4;
P_0c0c9de4: /* original e061, guest PC 0x0c0c9de4 */
if(!s->budget--) { s->failed_pc=0x0c0c9de4u; return 0; }
r[0]=0x00000061u;
goto P_0c0c9de6;
P_0c0c9de6: /* original 0ebc, guest PC 0x0c0c9de6 */
if(!s->budget--) { s->failed_pc=0x0c0c9de6u; return 0; }
r[14]=(uint32_t)(int32_t)(int8_t)read(ram,r[11]+r[0],1);
goto P_0c0c9de8;
P_0c0c9de8: /* original 6eec, guest PC 0x0c0c9de8 */
if(!s->budget--) { s->failed_pc=0x0c0c9de8u; return 0; }
r[14]=r[14]&255u;
goto P_0c0c9dea;
P_0c0c9dea: /* original 60e3, guest PC 0x0c0c9dea */
if(!s->budget--) { s->failed_pc=0x0c0c9deau; return 0; }
r[0]=r[14];
goto P_0c0c9dec;
P_0c0c9dec: /* original 8809, guest PC 0x0c0c9dec */
if(!s->budget--) { s->failed_pc=0x0c0c9decu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c9dee;
P_0c0c9dee: /* original 8971, guest PC 0x0c0c9dee */
if(!s->budget--) { s->failed_pc=0x0c0c9deeu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ed4; }
goto P_0c0c9df0;
P_0c0c9df0: /* original 2558, guest PC 0x0c0c9df0 */
if(!s->budget--) { s->failed_pc=0x0c0c9df0u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c9df2;
P_0c0c9df2: /* original 8b69, guest PC 0x0c0c9df2 */
if(!s->budget--) { s->failed_pc=0x0c0c9df2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9ec8; }
goto P_0c0c9df4;
P_0c0c9df4: /* original 60e3, guest PC 0x0c0c9df4 */
if(!s->budget--) { s->failed_pc=0x0c0c9df4u; return 0; }
r[0]=r[14];
goto P_0c0c9df6;
P_0c0c9df6: /* original 8806, guest PC 0x0c0c9df6 */
if(!s->budget--) { s->failed_pc=0x0c0c9df6u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000006u)!=0);
goto P_0c0c9df8;
P_0c0c9df8: /* original 8b01, guest PC 0x0c0c9df8 */
if(!s->budget--) { s->failed_pc=0x0c0c9df8u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9dfe; }
goto P_0c0c9dfa;
P_0c0c9dfa: /* original a001, guest PC 0x0c0c9dfa */
if(!s->budget--) { s->failed_pc=0x0c0c9dfau; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c9e00;
P_0c0c9dfc: /* original 1fc1, guest PC 0x0c0c9dfc */
if(!s->budget--) { s->failed_pc=0x0c0c9dfcu; return 0; }
write(ram,r[15]+4,r[12],4);
goto P_0c0c9dfe;
P_0c0c9dfe: /* original 1fd1, guest PC 0x0c0c9dfe */
if(!s->budget--) { s->failed_pc=0x0c0c9dfeu; return 0; }
write(ram,r[15]+4,r[13],4);
goto P_0c0c9e00;
P_0c0c9e00: /* original 60e3, guest PC 0x0c0c9e00 */
if(!s->budget--) { s->failed_pc=0x0c0c9e00u; return 0; }
r[0]=r[14];
goto P_0c0c9e02;
P_0c0c9e02: /* original 880a, guest PC 0x0c0c9e02 */
if(!s->budget--) { s->failed_pc=0x0c0c9e02u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000au)!=0);
goto P_0c0c9e04;
P_0c0c9e04: /* original 8f02, guest PC 0x0c0c9e04 */
if(!s->budget--) { s->failed_pc=0x0c0c9e04u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e0c; }
goto P_0c0c9e08;
P_0c0c9e06: /* original 60e3, guest PC 0x0c0c9e06 */
if(!s->budget--) { s->failed_pc=0x0c0c9e06u; return 0; }
r[0]=r[14];
goto P_0c0c9e08;
P_0c0c9e08: /* original a001, guest PC 0x0c0c9e08 */
if(!s->budget--) { s->failed_pc=0x0c0c9e08u; return 0; }
r[4]=r[12];
goto P_0c0c9e0e;
P_0c0c9e0a: /* original 64c3, guest PC 0x0c0c9e0a */
if(!s->budget--) { s->failed_pc=0x0c0c9e0au; return 0; }
r[4]=r[12];
goto P_0c0c9e0c;
P_0c0c9e0c: /* original 64d3, guest PC 0x0c0c9e0c */
if(!s->budget--) { s->failed_pc=0x0c0c9e0cu; return 0; }
r[4]=r[13];
goto P_0c0c9e0e;
P_0c0c9e0e: /* original 8808, guest PC 0x0c0c9e0e */
if(!s->budget--) { s->failed_pc=0x0c0c9e0eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000008u)!=0);
goto P_0c0c9e10;
P_0c0c9e10: /* original 8b01, guest PC 0x0c0c9e10 */
if(!s->budget--) { s->failed_pc=0x0c0c9e10u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9e16; }
goto P_0c0c9e12;
P_0c0c9e12: /* original a001, guest PC 0x0c0c9e12 */
if(!s->budget--) { s->failed_pc=0x0c0c9e12u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c9e18;
P_0c0c9e14: /* original 1fc2, guest PC 0x0c0c9e14 */
if(!s->budget--) { s->failed_pc=0x0c0c9e14u; return 0; }
write(ram,r[15]+8,r[12],4);
goto P_0c0c9e16;
P_0c0c9e16: /* original 1fd2, guest PC 0x0c0c9e16 */
if(!s->budget--) { s->failed_pc=0x0c0c9e16u; return 0; }
write(ram,r[15]+8,r[13],4);
goto P_0c0c9e18;
P_0c0c9e18: /* original 60e3, guest PC 0x0c0c9e18 */
if(!s->budget--) { s->failed_pc=0x0c0c9e18u; return 0; }
r[0]=r[14];
goto P_0c0c9e1a;
P_0c0c9e1a: /* original 880b, guest PC 0x0c0c9e1a */
if(!s->budget--) { s->failed_pc=0x0c0c9e1au; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000bu)!=0);
goto P_0c0c9e1c;
P_0c0c9e1c: /* original 8f02, guest PC 0x0c0c9e1c */
if(!s->budget--) { s->failed_pc=0x0c0c9e1cu; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e24; }
goto P_0c0c9e20;
P_0c0c9e1e: /* original 60e3, guest PC 0x0c0c9e1e */
if(!s->budget--) { s->failed_pc=0x0c0c9e1eu; return 0; }
r[0]=r[14];
goto P_0c0c9e20;
P_0c0c9e20: /* original a001, guest PC 0x0c0c9e20 */
if(!s->budget--) { s->failed_pc=0x0c0c9e20u; return 0; }
r[7]=r[12];
goto P_0c0c9e26;
P_0c0c9e22: /* original 67c3, guest PC 0x0c0c9e22 */
if(!s->budget--) { s->failed_pc=0x0c0c9e22u; return 0; }
r[7]=r[12];
goto P_0c0c9e24;
P_0c0c9e24: /* original 67d3, guest PC 0x0c0c9e24 */
if(!s->budget--) { s->failed_pc=0x0c0c9e24u; return 0; }
r[7]=r[13];
goto P_0c0c9e26;
P_0c0c9e26: /* original 880c, guest PC 0x0c0c9e26 */
if(!s->budget--) { s->failed_pc=0x0c0c9e26u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x0000000cu)!=0);
goto P_0c0c9e28;
P_0c0c9e28: /* original 8f02, guest PC 0x0c0c9e28 */
if(!s->budget--) { s->failed_pc=0x0c0c9e28u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e30; }
goto P_0c0c9e2c;
P_0c0c9e2a: /* original 60e3, guest PC 0x0c0c9e2a */
if(!s->budget--) { s->failed_pc=0x0c0c9e2au; return 0; }
r[0]=r[14];
goto P_0c0c9e2c;
P_0c0c9e2c: /* original a001, guest PC 0x0c0c9e2c */
if(!s->budget--) { s->failed_pc=0x0c0c9e2cu; return 0; }
r[1]=r[12];
goto P_0c0c9e32;
P_0c0c9e2e: /* original 61c3, guest PC 0x0c0c9e2e */
if(!s->budget--) { s->failed_pc=0x0c0c9e2eu; return 0; }
r[1]=r[12];
goto P_0c0c9e30;
P_0c0c9e30: /* original 61d3, guest PC 0x0c0c9e30 */
if(!s->budget--) { s->failed_pc=0x0c0c9e30u; return 0; }
r[1]=r[13];
goto P_0c0c9e32;
P_0c0c9e32: /* original 8807, guest PC 0x0c0c9e32 */
if(!s->budget--) { s->failed_pc=0x0c0c9e32u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000007u)!=0);
goto P_0c0c9e34;
P_0c0c9e34: /* original 8f02, guest PC 0x0c0c9e34 */
if(!s->budget--) { s->failed_pc=0x0c0c9e34u; return 0; }
cond=r[17]&1u;
r[0]=r[14];
if(!cond) { goto P_0c0c9e3c; }
goto P_0c0c9e38;
P_0c0c9e36: /* original 60e3, guest PC 0x0c0c9e36 */
if(!s->budget--) { s->failed_pc=0x0c0c9e36u; return 0; }
r[0]=r[14];
goto P_0c0c9e38;
P_0c0c9e38: /* original a001, guest PC 0x0c0c9e38 */
if(!s->budget--) { s->failed_pc=0x0c0c9e38u; return 0; }
r[5]=r[12];
goto P_0c0c9e3e;
P_0c0c9e3a: /* original 65c3, guest PC 0x0c0c9e3a */
if(!s->budget--) { s->failed_pc=0x0c0c9e3au; return 0; }
r[5]=r[12];
goto P_0c0c9e3c;
P_0c0c9e3c: /* original 65d3, guest PC 0x0c0c9e3c */
if(!s->budget--) { s->failed_pc=0x0c0c9e3cu; return 0; }
r[5]=r[13];
goto P_0c0c9e3e;
P_0c0c9e3e: /* original 8805, guest PC 0x0c0c9e3e */
if(!s->budget--) { s->failed_pc=0x0c0c9e3eu; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000005u)!=0);
goto P_0c0c9e40;
P_0c0c9e40: /* original 8b01, guest PC 0x0c0c9e40 */
if(!s->budget--) { s->failed_pc=0x0c0c9e40u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9e46; }
goto P_0c0c9e42;
P_0c0c9e42: /* original a001, guest PC 0x0c0c9e42 */
if(!s->budget--) { s->failed_pc=0x0c0c9e42u; return 0; }
r[6]=r[12];
goto P_0c0c9e48;
P_0c0c9e44: /* original 66c3, guest PC 0x0c0c9e44 */
if(!s->budget--) { s->failed_pc=0x0c0c9e44u; return 0; }
r[6]=r[12];
goto P_0c0c9e46;
P_0c0c9e46: /* original 66d3, guest PC 0x0c0c9e46 */
if(!s->budget--) { s->failed_pc=0x0c0c9e46u; return 0; }
r[6]=r[13];
goto P_0c0c9e48;
P_0c0c9e48: /* original 53f1, guest PC 0x0c0c9e48 */
if(!s->budget--) { s->failed_pc=0x0c0c9e48u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c0c9e4a;
P_0c0c9e4a: /* original 2338, guest PC 0x0c0c9e4a */
if(!s->budget--) { s->failed_pc=0x0c0c9e4au; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[3])==0)!=0);
goto P_0c0c9e4c;
P_0c0c9e4c: /* original 890e, guest PC 0x0c0c9e4c */
if(!s->budget--) { s->failed_pc=0x0c0c9e4cu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e4e;
P_0c0c9e4e: /* original 2448, guest PC 0x0c0c9e4e */
if(!s->budget--) { s->failed_pc=0x0c0c9e4eu; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c0c9e50;
P_0c0c9e50: /* original 890c, guest PC 0x0c0c9e50 */
if(!s->budget--) { s->failed_pc=0x0c0c9e50u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e52;
P_0c0c9e52: /* original 52f2, guest PC 0x0c0c9e52 */
if(!s->budget--) { s->failed_pc=0x0c0c9e52u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c0c9e54;
P_0c0c9e54: /* original 2228, guest PC 0x0c0c9e54 */
if(!s->budget--) { s->failed_pc=0x0c0c9e54u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[2])==0)!=0);
goto P_0c0c9e56;
P_0c0c9e56: /* original 8909, guest PC 0x0c0c9e56 */
if(!s->budget--) { s->failed_pc=0x0c0c9e56u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e58;
P_0c0c9e58: /* original 2778, guest PC 0x0c0c9e58 */
if(!s->budget--) { s->failed_pc=0x0c0c9e58u; return 0; }
r[17]=(r[17]&~1u)|(((r[7]&r[7])==0)!=0);
goto P_0c0c9e5a;
P_0c0c9e5a: /* original 8907, guest PC 0x0c0c9e5a */
if(!s->budget--) { s->failed_pc=0x0c0c9e5au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e6c; }
goto P_0c0c9e5c;
P_0c0c9e5c: /* original 2118, guest PC 0x0c0c9e5c */
if(!s->budget--) { s->failed_pc=0x0c0c9e5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[1])==0)!=0);
goto P_0c0c9e5e;
P_0c0c9e5e: /* original 890f, guest PC 0x0c0c9e5e */
if(!s->budget--) { s->failed_pc=0x0c0c9e5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e60;
P_0c0c9e60: /* original 2558, guest PC 0x0c0c9e60 */
if(!s->budget--) { s->failed_pc=0x0c0c9e60u; return 0; }
r[17]=(r[17]&~1u)|(((r[5]&r[5])==0)!=0);
goto P_0c0c9e62;
P_0c0c9e62: /* original 890d, guest PC 0x0c0c9e62 */
if(!s->budget--) { s->failed_pc=0x0c0c9e62u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e64;
P_0c0c9e64: /* original 2668, guest PC 0x0c0c9e64 */
if(!s->budget--) { s->failed_pc=0x0c0c9e64u; return 0; }
r[17]=(r[17]&~1u)|(((r[6]&r[6])==0)!=0);
goto P_0c0c9e66;
P_0c0c9e66: /* original 890b, guest PC 0x0c0c9e66 */
if(!s->budget--) { s->failed_pc=0x0c0c9e66u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9e80; }
goto P_0c0c9e68;
P_0c0c9e68: /* original a00f, guest PC 0x0c0c9e68 */
if(!s->budget--) { s->failed_pc=0x0c0c9e68u; return 0; }
goto P_0c0c9e8a;
P_0c0c9e6a: /* original 0009, guest PC 0x0c0c9e6a */
if(!s->budget--) { s->failed_pc=0x0c0c9e6au; return 0; }
goto P_0c0c9e6c;
P_0c0c9e6c: /* original a009, guest PC 0x0c0c9e6c */
if(!s->budget--) { s->failed_pc=0x0c0c9e6cu; return 0; }
r[14]=0x00000070u;
goto P_0c0c9e82;
P_0c0c9e6e: /* original ee70, guest PC 0x0c0c9e6e */
if(!s->budget--) { s->failed_pc=0x0c0c9e6eu; return 0; }
r[14]=0x00000070u;
return vf3_matrix_family(0x0c0c9e70u,s,ram);
P_0c0c9e80: /* original ee71, guest PC 0x0c0c9e80 */
if(!s->budget--) { s->failed_pc=0x0c0c9e80u; return 0; }
r[14]=0x00000071u;
goto P_0c0c9e82;
P_0c0c9e82: /* original b03c, guest PC 0x0c0c9e82 */
if(!s->budget--) { s->failed_pc=0x0c0c9e82u; return 0; }
target=0x0c0c9efeu; r[16]=0x0c0c9e86u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9e86u) { target=s->pc; goto dispatch; }
goto P_0c0c9e86;
P_0c0c9e84: /* original 64e3, guest PC 0x0c0c9e84 */
if(!s->budget--) { s->failed_pc=0x0c0c9e84u; return 0; }
r[4]=r[14];
goto P_0c0c9e86;
P_0c0c9e86: /* original 4a0b, guest PC 0x0c0c9e86 */
if(!s->budget--) { s->failed_pc=0x0c0c9e86u; return 0; }
target=r[10];
r[16]=0x0c0c9e8au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9e8au) { target=s->pc; goto dispatch; }
goto P_0c0c9e8a;
P_0c0c9e88: /* original 64e3, guest PC 0x0c0c9e88 */
if(!s->budget--) { s->failed_pc=0x0c0c9e88u; return 0; }
r[4]=r[14];
goto P_0c0c9e8a;
P_0c0c9e8a: /* original 60f2, guest PC 0x0c0c9e8a */
if(!s->budget--) { s->failed_pc=0x0c0c9e8au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c0c9e8c;
P_0c0c9e8c: /* original e11c, guest PC 0x0c0c9e8c */
if(!s->budget--) { s->failed_pc=0x0c0c9e8cu; return 0; }
r[1]=0x0000001cu;
goto P_0c0c9e8e;
P_0c0c9e8e: /* original e40f, guest PC 0x0c0c9e8e */
if(!s->budget--) { s->failed_pc=0x0c0c9e8eu; return 0; }
r[4]=0x0000000fu;
goto P_0c0c9e90;
P_0c0c9e90: /* original 001c, guest PC 0x0c0c9e90 */
if(!s->budget--) { s->failed_pc=0x0c0c9e90u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c0c9e92;
P_0c0c9e92: /* original 600c, guest PC 0x0c0c9e92 */
if(!s->budget--) { s->failed_pc=0x0c0c9e92u; return 0; }
r[0]=r[0]&255u;
goto P_0c0c9e94;
P_0c0c9e94: /* original 2409, guest PC 0x0c0c9e94 */
if(!s->budget--) { s->failed_pc=0x0c0c9e94u; return 0; }
r[4]&=r[0];
goto P_0c0c9e96;
P_0c0c9e96: /* original 6043, guest PC 0x0c0c9e96 */
if(!s->budget--) { s->failed_pc=0x0c0c9e96u; return 0; }
r[0]=r[4];
goto P_0c0c9e98;
P_0c0c9e98: /* original 8809, guest PC 0x0c0c9e98 */
if(!s->budget--) { s->failed_pc=0x0c0c9e98u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000009u)!=0);
goto P_0c0c9e9a;
P_0c0c9e9a: /* original 8b15, guest PC 0x0c0c9e9a */
if(!s->budget--) { s->failed_pc=0x0c0c9e9au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0c9ec8; }
goto P_0c0c9e9c;
P_0c0c9e9c: /* original 904e, guest PC 0x0c0c9e9c */
if(!s->budget--) { s->failed_pc=0x0c0c9e9cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9f3cu,2);
goto P_0c0c9e9e;
P_0c0c9e9e: /* original f5b6, guest PC 0x0c0c9e9e */
if(!s->budget--) { s->failed_pc=0x0c0c9e9eu; return 0; }
vf3_matrix_load(s,ram,5,r[11]+r[0]);
goto P_0c0c9ea0;
P_0c0c9ea0: /* original 7008, guest PC 0x0c0c9ea0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea0u; return 0; }
r[0]+=0x00000008u;
goto P_0c0c9ea2;
P_0c0c9ea2: /* original f4b6, guest PC 0x0c0c9ea2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea2u; return 0; }
vf3_matrix_load(s,ram,4,r[11]+r[0]);
goto P_0c0c9ea4;
P_0c0c9ea4: /* original c726, guest PC 0x0c0c9ea4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea4u; return 0; }
r[0]=0x0c0c9f40u;
goto P_0c0c9ea6;
P_0c0c9ea6: /* original f608, guest PC 0x0c0c9ea6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea6u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c9ea8;
P_0c0c9ea8: /* original f565, guest PC 0x0c0c9ea8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ea8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[6]))!=0);
goto P_0c0c9eaa;
P_0c0c9eaa: /* original 890d, guest PC 0x0c0c9eaa */
if(!s->budget--) { s->failed_pc=0x0c0c9eaau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9eac;
P_0c0c9eac: /* original c725, guest PC 0x0c0c9eac */
if(!s->budget--) { s->failed_pc=0x0c0c9eacu; return 0; }
r[0]=0x0c0c9f44u;
goto P_0c0c9eae;
P_0c0c9eae: /* original f608, guest PC 0x0c0c9eae */
if(!s->budget--) { s->failed_pc=0x0c0c9eaeu; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0c9eb0;
P_0c0c9eb0: /* original f655, guest PC 0x0c0c9eb0 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0c9eb2;
P_0c0c9eb2: /* original 8909, guest PC 0x0c0c9eb2 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9eb4;
P_0c0c9eb4: /* original c724, guest PC 0x0c0c9eb4 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb4u; return 0; }
r[0]=0x0c0c9f48u;
goto P_0c0c9eb6;
P_0c0c9eb6: /* original f508, guest PC 0x0c0c9eb6 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb6u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c9eb8;
P_0c0c9eb8: /* original f455, guest PC 0x0c0c9eb8 */
if(!s->budget--) { s->failed_pc=0x0c0c9eb8u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[5]))!=0);
goto P_0c0c9eba;
P_0c0c9eba: /* original 8905, guest PC 0x0c0c9eba */
if(!s->budget--) { s->failed_pc=0x0c0c9ebau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9ebc;
P_0c0c9ebc: /* original c723, guest PC 0x0c0c9ebc */
if(!s->budget--) { s->failed_pc=0x0c0c9ebcu; return 0; }
r[0]=0x0c0c9f4cu;
goto P_0c0c9ebe;
P_0c0c9ebe: /* original f508, guest PC 0x0c0c9ebe */
if(!s->budget--) { s->failed_pc=0x0c0c9ebeu; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0c9ec0;
P_0c0c9ec0: /* original f545, guest PC 0x0c0c9ec0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec0u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[5])>as_float(fr[4]))!=0);
goto P_0c0c9ec2;
P_0c0c9ec2: /* original 8901, guest PC 0x0c0c9ec2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ec8; }
goto P_0c0c9ec4;
P_0c0c9ec4: /* original a00b, guest PC 0x0c0c9ec4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec4u; return 0; }
r[14]=r[13];
goto P_0c0c9ede;
P_0c0c9ec6: /* original 6ed3, guest PC 0x0c0c9ec6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec6u; return 0; }
r[14]=r[13];
goto P_0c0c9ec8;
P_0c0c9ec8: /* original 9039, guest PC 0x0c0c9ec8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ec8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c0c9f3eu,2);
goto P_0c0c9eca;
P_0c0c9eca: /* original 0ebe, guest PC 0x0c0c9eca */
if(!s->budget--) { s->failed_pc=0x0c0c9ecau; return 0; }
r[14]=read(ram,r[11]+r[0],4);
goto P_0c0c9ecc;
P_0c0c9ecc: /* original 2ee8, guest PC 0x0c0c9ecc */
if(!s->budget--) { s->failed_pc=0x0c0c9eccu; return 0; }
r[17]=(r[17]&~1u)|(((r[14]&r[14])==0)!=0);
goto P_0c0c9ece;
P_0c0c9ece: /* original 8906, guest PC 0x0c0c9ece */
if(!s->budget--) { s->failed_pc=0x0c0c9eceu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0c9ede; }
goto P_0c0c9ed0;
P_0c0c9ed0: /* original a005, guest PC 0x0c0c9ed0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed0u; return 0; }
r[14]=r[12];
goto P_0c0c9ede;
P_0c0c9ed2: /* original 6ec3, guest PC 0x0c0c9ed2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed2u; return 0; }
r[14]=r[12];
goto P_0c0c9ed4;
P_0c0c9ed4: /* original 5d92, guest PC 0x0c0c9ed4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed4u; return 0; }
r[13]=read(ram,r[9]+8,4);
goto P_0c0c9ed6;
P_0c0c9ed6: /* original b012, guest PC 0x0c0c9ed6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed6u; return 0; }
target=0x0c0c9efeu; r[16]=0x0c0c9edau;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9edau) { target=s->pc; goto dispatch; }
goto P_0c0c9eda;
P_0c0c9ed8: /* original 64d3, guest PC 0x0c0c9ed8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ed8u; return 0; }
r[4]=r[13];
goto P_0c0c9eda;
P_0c0c9eda: /* original 4a0b, guest PC 0x0c0c9eda */
if(!s->budget--) { s->failed_pc=0x0c0c9edau; return 0; }
target=r[10];
r[16]=0x0c0c9edeu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9edeu) { target=s->pc; goto dispatch; }
goto P_0c0c9ede;
P_0c0c9edc: /* original 64d3, guest PC 0x0c0c9edc */
if(!s->budget--) { s->failed_pc=0x0c0c9edcu; return 0; }
r[4]=r[13];
goto P_0c0c9ede;
P_0c0c9ede: /* original 60e3, guest PC 0x0c0c9ede */
if(!s->budget--) { s->failed_pc=0x0c0c9edeu; return 0; }
r[0]=r[14];
goto P_0c0c9ee0;
P_0c0c9ee0: /* original 4008, guest PC 0x0c0c9ee0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee0u; return 0; }
r[0]<<=2;
goto P_0c0c9ee2;
P_0c0c9ee2: /* original 0e9e, guest PC 0x0c0c9ee2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee2u; return 0; }
r[14]=read(ram,r[9]+r[0],4);
goto P_0c0c9ee4;
P_0c0c9ee4: /* original b00b, guest PC 0x0c0c9ee4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee4u; return 0; }
target=0x0c0c9efeu; r[16]=0x0c0c9ee8u;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9ee8u) { target=s->pc; goto dispatch; }
goto P_0c0c9ee8;
P_0c0c9ee6: /* original 64e3, guest PC 0x0c0c9ee6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee6u; return 0; }
r[4]=r[14];
goto P_0c0c9ee8;
P_0c0c9ee8: /* original 4a0b, guest PC 0x0c0c9ee8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ee8u; return 0; }
target=r[10];
r[16]=0x0c0c9eecu;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0c9eecu) { target=s->pc; goto dispatch; }
goto P_0c0c9eec;
P_0c0c9eea: /* original 64e3, guest PC 0x0c0c9eea */
if(!s->budget--) { s->failed_pc=0x0c0c9eeau; return 0; }
r[4]=r[14];
goto P_0c0c9eec;
P_0c0c9eec: /* original 7f0c, guest PC 0x0c0c9eec */
if(!s->budget--) { s->failed_pc=0x0c0c9eecu; return 0; }
r[15]+=0x0000000cu;
goto P_0c0c9eee;
P_0c0c9eee: /* original 4f26, guest PC 0x0c0c9eee */
if(!s->budget--) { s->failed_pc=0x0c0c9eeeu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0c9ef0;
P_0c0c9ef0: /* original 69f6, guest PC 0x0c0c9ef0 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef0u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c0c9ef2;
P_0c0c9ef2: /* original 6af6, guest PC 0x0c0c9ef2 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef2u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c0c9ef4;
P_0c0c9ef4: /* original 6bf6, guest PC 0x0c0c9ef4 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c0c9ef6;
P_0c0c9ef6: /* original 6cf6, guest PC 0x0c0c9ef6 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c0c9ef8;
P_0c0c9ef8: /* original 6df6, guest PC 0x0c0c9ef8 */
if(!s->budget--) { s->failed_pc=0x0c0c9ef8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c0c9efa;
P_0c0c9efa: /* original 000b, guest PC 0x0c0c9efa */
if(!s->budget--) { s->failed_pc=0x0c0c9efau; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0c9efc: /* original 6ef6, guest PC 0x0c0c9efc */
if(!s->budget--) { s->failed_pc=0x0c0c9efcu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0c9efeu,s,ram);
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
target=0x0c0cafecu; r[16]=0x0c0caf7au;
r[4]=r[14];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0caf7au) { target=s->pc; goto dispatch; }
goto P_0c0caf7a;
P_0c0caf78: /* original 64e3, guest PC 0x0c0caf78 */
if(!s->budget--) { s->failed_pc=0x0c0caf78u; return 0; }
r[4]=r[14];
goto P_0c0caf7a;
P_0c0caf7a: /* original b037, guest PC 0x0c0caf7a */
if(!s->budget--) { s->failed_pc=0x0c0caf7au; return 0; }
target=0x0c0cafecu; r[16]=0x0c0caf7eu;
r[4]=r[13];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0caf7eu) { target=s->pc; goto dispatch; }
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
return vf3_matrix_family(0x0c0cafecu,s,ram);
P_0c0cbdd0: /* original 4f22, guest PC 0x0c0cbdd0 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd0u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cbdd2;
P_0c0cbdd2: /* original e300, guest PC 0x0c0cbdd2 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd2u; return 0; }
r[3]=0x00000000u;
goto P_0c0cbdd4;
P_0c0cbdd4: /* original 6233, guest PC 0x0c0cbdd4 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd4u; return 0; }
r[2]=r[3];
goto P_0c0cbdd6;
P_0c0cbdd6: /* original 5ef2, guest PC 0x0c0cbdd6 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd6u; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0cbdd8;
P_0c0cbdd8: /* original 1e34, guest PC 0x0c0cbdd8 */
if(!s->budget--) { s->failed_pc=0x0c0cbdd8u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cbdda;
P_0c0cbdda: /* original 1e33, guest PC 0x0c0cbdda */
if(!s->budget--) { s->failed_pc=0x0c0cbddau; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0cbddc;
P_0c0cbddc: /* original f378, guest PC 0x0c0cbddc */
if(!s->budget--) { s->failed_pc=0x0c0cbddcu; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cbdde;
P_0c0cbdde: /* original f268, guest PC 0x0c0cbdde */
if(!s->budget--) { s->failed_pc=0x0c0cbddeu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0cbde0;
P_0c0cbde0: /* original f231, guest PC 0x0c0cbde0 */
if(!s->budget--) { s->failed_pc=0x0c0cbde0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbde2;
P_0c0cbde2: /* original fe27, guest PC 0x0c0cbde2 */
if(!s->budget--) { s->failed_pc=0x0c0cbde2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbde4;
P_0c0cbde4: /* original e004, guest PC 0x0c0cbde4 */
if(!s->budget--) { s->failed_pc=0x0c0cbde4u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbde6;
P_0c0cbde6: /* original f276, guest PC 0x0c0cbde6 */
if(!s->budget--) { s->failed_pc=0x0c0cbde6u; return 0; }
vf3_matrix_load(s,ram,2,r[7]+r[0]);
goto P_0c0cbde8;
P_0c0cbde8: /* original f366, guest PC 0x0c0cbde8 */
if(!s->budget--) { s->failed_pc=0x0c0cbde8u; return 0; }
vf3_matrix_load(s,ram,3,r[6]+r[0]);
goto P_0c0cbdea;
P_0c0cbdea: /* original e01c, guest PC 0x0c0cbdea */
if(!s->budget--) { s->failed_pc=0x0c0cbdeau; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbdec;
P_0c0cbdec: /* original f231, guest PC 0x0c0cbdec */
if(!s->budget--) { s->failed_pc=0x0c0cbdecu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbdee;
P_0c0cbdee: /* original fe27, guest PC 0x0c0cbdee */
if(!s->budget--) { s->failed_pc=0x0c0cbdeeu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbdf0;
P_0c0cbdf0: /* original e008, guest PC 0x0c0cbdf0 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf0u; return 0; }
r[0]=0x00000008u;
goto P_0c0cbdf2;
P_0c0cbdf2: /* original f266, guest PC 0x0c0cbdf2 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf2u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cbdf4;
P_0c0cbdf4: /* original f376, guest PC 0x0c0cbdf4 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbdf6;
P_0c0cbdf6: /* original e020, guest PC 0x0c0cbdf6 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf6u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbdf8;
P_0c0cbdf8: /* original f231, guest PC 0x0c0cbdf8 */
if(!s->budget--) { s->failed_pc=0x0c0cbdf8u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cbdfa;
P_0c0cbdfa: /* original fe27, guest PC 0x0c0cbdfa */
if(!s->budget--) { s->failed_pc=0x0c0cbdfau; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbdfc;
P_0c0cbdfc: /* original e018, guest PC 0x0c0cbdfc */
if(!s->budget--) { s->failed_pc=0x0c0cbdfcu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbdfe;
P_0c0cbdfe: /* original f4e6, guest PC 0x0c0cbdfe */
if(!s->budget--) { s->failed_pc=0x0c0cbdfeu; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cbe00;
P_0c0cbe00: /* original e020, guest PC 0x0c0cbe00 */
if(!s->budget--) { s->failed_pc=0x0c0cbe00u; return 0; }
r[0]=0x00000020u;
goto P_0c0cbe02;
P_0c0cbe02: /* original f54c, guest PC 0x0c0cbe02 */
if(!s->budget--) { s->failed_pc=0x0c0cbe02u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cbe04;
P_0c0cbe04: /* original f542, guest PC 0x0c0cbe04 */
if(!s->budget--) { s->failed_pc=0x0c0cbe04u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cbe06;
P_0c0cbe06: /* original f4e6, guest PC 0x0c0cbe06 */
if(!s->budget--) { s->failed_pc=0x0c0cbe06u; return 0; }
vf3_matrix_load(s,ram,4,r[14]+r[0]);
goto P_0c0cbe08;
P_0c0cbe08: /* original f04c, guest PC 0x0c0cbe08 */
if(!s->budget--) { s->failed_pc=0x0c0cbe08u; return 0; }
vf3_matrix_move(s,0,4);
goto P_0c0cbe0a;
P_0c0cbe0a: /* original f54e, guest PC 0x0c0cbe0a */
if(!s->budget--) { s->failed_pc=0x0c0cbe0au; return 0; }
fr[5]=vf3_fpu_mac(fr[0],fr[4],fr[5],r[18]);
goto P_0c0cbe0c;
P_0c0cbe0c: /* original e01c, guest PC 0x0c0cbe0c */
if(!s->budget--) { s->failed_pc=0x0c0cbe0cu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbe0e;
P_0c0cbe0e: /* original f45c, guest PC 0x0c0cbe0e */
if(!s->budget--) { s->failed_pc=0x0c0cbe0eu; return 0; }
vf3_matrix_move(s,4,5);
goto P_0c0cbe10;
P_0c0cbe10: /* original f5e6, guest PC 0x0c0cbe10 */
if(!s->budget--) { s->failed_pc=0x0c0cbe10u; return 0; }
vf3_matrix_load(s,ram,5,r[14]+r[0]);
goto P_0c0cbe12;
P_0c0cbe12: /* original c782, guest PC 0x0c0cbe12 */
if(!s->budget--) { s->failed_pc=0x0c0cbe12u; return 0; }
r[0]=0x0c0cc01cu;
goto P_0c0cbe14;
P_0c0cbe14: /* original f34c, guest PC 0x0c0cbe14 */
if(!s->budget--) { s->failed_pc=0x0c0cbe14u; return 0; }
vf3_matrix_move(s,3,4);
goto P_0c0cbe16;
P_0c0cbe16: /* original f05c, guest PC 0x0c0cbe16 */
if(!s->budget--) { s->failed_pc=0x0c0cbe16u; return 0; }
vf3_matrix_move(s,0,5);
goto P_0c0cbe18;
P_0c0cbe18: /* original f35e, guest PC 0x0c0cbe18 */
if(!s->budget--) { s->failed_pc=0x0c0cbe18u; return 0; }
fr[3]=vf3_fpu_mac(fr[0],fr[5],fr[3],r[18]);
goto P_0c0cbe1a;
P_0c0cbe1a: /* original f708, guest PC 0x0c0cbe1a */
if(!s->budget--) { s->failed_pc=0x0c0cbe1au; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cbe1c;
P_0c0cbe1c: /* original f53c, guest PC 0x0c0cbe1c */
if(!s->budget--) { s->failed_pc=0x0c0cbe1cu; return 0; }
vf3_matrix_move(s,5,3);
goto P_0c0cbe1e;
P_0c0cbe1e: /* original f755, guest PC 0x0c0cbe1e */
if(!s->budget--) { s->failed_pc=0x0c0cbe1eu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0cbe20;
P_0c0cbe20: /* original 8b01, guest PC 0x0c0cbe20 */
if(!s->budget--) { s->failed_pc=0x0c0cbe20u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe26; }
goto P_0c0cbe22;
P_0c0cbe22: /* original a002, guest PC 0x0c0cbe22 */
if(!s->budget--) { s->failed_pc=0x0c0cbe22u; return 0; }
fr[6]=0;
goto P_0c0cbe2a;
P_0c0cbe24: /* original f68d, guest PC 0x0c0cbe24 */
if(!s->budget--) { s->failed_pc=0x0c0cbe24u; return 0; }
fr[6]=0;
goto P_0c0cbe26;
P_0c0cbe26: /* original f65c, guest PC 0x0c0cbe26 */
if(!s->budget--) { s->failed_pc=0x0c0cbe26u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0cbe28;
P_0c0cbe28: /* original f67d, guest PC 0x0c0cbe28 */
if(!s->budget--) { s->failed_pc=0x0c0cbe28u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c0cbe2a;
P_0c0cbe2a: /* original f745, guest PC 0x0c0cbe2a */
if(!s->budget--) { s->failed_pc=0x0c0cbe2au; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c0cbe2c;
P_0c0cbe2c: /* original 8b01, guest PC 0x0c0cbe2c */
if(!s->budget--) { s->failed_pc=0x0c0cbe2cu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe32; }
goto P_0c0cbe2e;
P_0c0cbe2e: /* original a002, guest PC 0x0c0cbe2e */
if(!s->budget--) { s->failed_pc=0x0c0cbe2eu; return 0; }
fr[5]=0;
goto P_0c0cbe36;
P_0c0cbe30: /* original f58d, guest PC 0x0c0cbe30 */
if(!s->budget--) { s->failed_pc=0x0c0cbe30u; return 0; }
fr[5]=0;
goto P_0c0cbe32;
P_0c0cbe32: /* original f54c, guest PC 0x0c0cbe32 */
if(!s->budget--) { s->failed_pc=0x0c0cbe32u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cbe34;
P_0c0cbe34: /* original f57d, guest PC 0x0c0cbe34 */
if(!s->budget--) { s->failed_pc=0x0c0cbe34u; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cbe36;
P_0c0cbe36: /* original f49d, guest PC 0x0c0cbe36 */
if(!s->budget--) { s->failed_pc=0x0c0cbe36u; return 0; }
fr[4]=0x3f800000u;
goto P_0c0cbe38;
P_0c0cbe38: /* original f463, guest PC 0x0c0cbe38 */
if(!s->budget--) { s->failed_pc=0x0c0cbe38u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'/');
goto P_0c0cbe3a;
P_0c0cbe3a: /* original c779, guest PC 0x0c0cbe3a */
if(!s->budget--) { s->failed_pc=0x0c0cbe3au; return 0; }
r[0]=0x0c0cc020u;
goto P_0c0cbe3c;
P_0c0cbe3c: /* original f708, guest PC 0x0c0cbe3c */
if(!s->budget--) { s->failed_pc=0x0c0cbe3cu; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cbe3e;
P_0c0cbe3e: /* original c779, guest PC 0x0c0cbe3e */
if(!s->budget--) { s->failed_pc=0x0c0cbe3eu; return 0; }
r[0]=0x0c0cc024u;
goto P_0c0cbe40;
P_0c0cbe40: /* original f475, guest PC 0x0c0cbe40 */
if(!s->budget--) { s->failed_pc=0x0c0cbe40u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[7]))!=0);
goto P_0c0cbe42;
P_0c0cbe42: /* original 8f4a, guest PC 0x0c0cbe42 */
if(!s->budget--) { s->failed_pc=0x0c0cbe42u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,6,r[0]);
if(!cond) { goto P_0c0cbeda; }
goto P_0c0cbe46;
P_0c0cbe44: /* original f608, guest PC 0x0c0cbe44 */
if(!s->budget--) { s->failed_pc=0x0c0cbe44u; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0cbe46;
P_0c0cbe46: /* original f465, guest PC 0x0c0cbe46 */
if(!s->budget--) { s->failed_pc=0x0c0cbe46u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[4])>as_float(fr[6]))!=0);
goto P_0c0cbe48;
P_0c0cbe48: /* original 8b00, guest PC 0x0c0cbe48 */
if(!s->budget--) { s->failed_pc=0x0c0cbe48u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe4c; }
goto P_0c0cbe4a;
P_0c0cbe4a: /* original f46c, guest PC 0x0c0cbe4a */
if(!s->budget--) { s->failed_pc=0x0c0cbe4au; return 0; }
vf3_matrix_move(s,4,6);
goto P_0c0cbe4c;
P_0c0cbe4c: /* original 50e2, guest PC 0x0c0cbe4c */
if(!s->budget--) { s->failed_pc=0x0c0cbe4cu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0cbe4e;
P_0c0cbe4e: /* original d776, guest PC 0x0c0cbe4e */
if(!s->budget--) { s->failed_pc=0x0c0cbe4eu; return 0; }
r[7]=read(ram,0x0c0cc028u,4);
goto P_0c0cbe50;
P_0c0cbe50: /* original c802, guest PC 0x0c0cbe50 */
if(!s->budget--) { s->failed_pc=0x0c0cbe50u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cbe52;
P_0c0cbe52: /* original 8b10, guest PC 0x0c0cbe52 */
if(!s->budget--) { s->failed_pc=0x0c0cbe52u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cbe76; }
goto P_0c0cbe54;
P_0c0cbe54: /* original e018, guest PC 0x0c0cbe54 */
if(!s->budget--) { s->failed_pc=0x0c0cbe54u; return 0; }
r[0]=0x00000018u;
goto P_0c0cbe56;
P_0c0cbe56: /* original f746, guest PC 0x0c0cbe56 */
if(!s->budget--) { s->failed_pc=0x0c0cbe56u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cbe58;
P_0c0cbe58: /* original c774, guest PC 0x0c0cbe58 */
if(!s->budget--) { s->failed_pc=0x0c0cbe58u; return 0; }
r[0]=0x0c0cc02cu;
goto P_0c0cbe5a;
P_0c0cbe5a: /* original f608, guest PC 0x0c0cbe5a */
if(!s->budget--) { s->failed_pc=0x0c0cbe5au; return 0; }
vf3_matrix_load(s,ram,6,r[0]);
goto P_0c0cbe5c;
P_0c0cbe5c: /* original e018, guest PC 0x0c0cbe5c */
if(!s->budget--) { s->failed_pc=0x0c0cbe5cu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbe5e;
P_0c0cbe5e: /* original f3e6, guest PC 0x0c0cbe5e */
if(!s->budget--) { s->failed_pc=0x0c0cbe5eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbe60;
P_0c0cbe60: /* original f362, guest PC 0x0c0cbe60 */
if(!s->budget--) { s->failed_pc=0x0c0cbe60u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0cbe62;
P_0c0cbe62: /* original fe37, guest PC 0x0c0cbe62 */
if(!s->budget--) { s->failed_pc=0x0c0cbe62u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbe64;
P_0c0cbe64: /* original e01c, guest PC 0x0c0cbe64 */
if(!s->budget--) { s->failed_pc=0x0c0cbe64u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbe66;
P_0c0cbe66: /* original f2e6, guest PC 0x0c0cbe66 */
if(!s->budget--) { s->failed_pc=0x0c0cbe66u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cbe68;
P_0c0cbe68: /* original f262, guest PC 0x0c0cbe68 */
if(!s->budget--) { s->failed_pc=0x0c0cbe68u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[6],r[18],'*');
goto P_0c0cbe6a;
P_0c0cbe6a: /* original fe27, guest PC 0x0c0cbe6a */
if(!s->budget--) { s->failed_pc=0x0c0cbe6au; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbe6c;
P_0c0cbe6c: /* original e020, guest PC 0x0c0cbe6c */
if(!s->budget--) { s->failed_pc=0x0c0cbe6cu; return 0; }
r[0]=0x00000020u;
goto P_0c0cbe6e;
P_0c0cbe6e: /* original f3e6, guest PC 0x0c0cbe6e */
if(!s->budget--) { s->failed_pc=0x0c0cbe6eu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbe70;
P_0c0cbe70: /* original f362, guest PC 0x0c0cbe70 */
if(!s->budget--) { s->failed_pc=0x0c0cbe70u; return 0; }
fr[3]=vf3_fpu_binary(fr[3],fr[6],r[18],'*');
goto P_0c0cbe72;
P_0c0cbe72: /* original a015, guest PC 0x0c0cbe72 */
if(!s->budget--) { s->failed_pc=0x0c0cbe72u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbea0;
P_0c0cbe74: /* original fe37, guest PC 0x0c0cbe74 */
if(!s->budget--) { s->failed_pc=0x0c0cbe74u; return 0; }
vf3_matrix_store(s,ram,3,r[14]+r[0]);
goto P_0c0cbe76;
P_0c0cbe76: /* original d36e, guest PC 0x0c0cbe76 */
if(!s->budget--) { s->failed_pc=0x0c0cbe76u; return 0; }
r[3]=read(ram,0x0c0cc030u,4);
goto P_0c0cbe78;
P_0c0cbe78: /* original e014, guest PC 0x0c0cbe78 */
if(!s->budget--) { s->failed_pc=0x0c0cbe78u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbe7a;
P_0c0cbe7a: /* original f746, guest PC 0x0c0cbe7a */
if(!s->budget--) { s->failed_pc=0x0c0cbe7au; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cbe7c;
P_0c0cbe7c: /* original 7718, guest PC 0x0c0cbe7c */
if(!s->budget--) { s->failed_pc=0x0c0cbe7cu; return 0; }
r[7]+=0x00000018u;
goto P_0c0cbe7e;
P_0c0cbe7e: /* original 6632, guest PC 0x0c0cbe7e */
if(!s->budget--) { s->failed_pc=0x0c0cbe7eu; return 0; }
tmp=read(ram,r[3],4);
r[6]=tmp;
goto P_0c0cbe80;
P_0c0cbe80: /* original e210, guest PC 0x0c0cbe80 */
if(!s->budget--) { s->failed_pc=0x0c0cbe80u; return 0; }
r[2]=0x00000010u;
goto P_0c0cbe82;
P_0c0cbe82: /* original 50f3, guest PC 0x0c0cbe82 */
if(!s->budget--) { s->failed_pc=0x0c0cbe82u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c0cbe84;
P_0c0cbe84: /* original 6462, guest PC 0x0c0cbe84 */
if(!s->budget--) { s->failed_pc=0x0c0cbe84u; return 0; }
tmp=read(ram,r[6],4);
r[4]=tmp;
goto P_0c0cbe86;
P_0c0cbe86: /* original c802, guest PC 0x0c0cbe86 */
if(!s->budget--) { s->failed_pc=0x0c0cbe86u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cbe88;
P_0c0cbe88: /* original 8d09, guest PC 0x0c0cbe88 */
if(!s->budget--) { s->failed_pc=0x0c0cbe88u; return 0; }
cond=r[17]&1u;
r[4]|=r[2];
if(cond) { goto P_0c0cbe9e; }
goto P_0c0cbe8c;
P_0c0cbe8a: /* original 242b, guest PC 0x0c0cbe8a */
if(!s->budget--) { s->failed_pc=0x0c0cbe8au; return 0; }
r[4]|=r[2];
goto P_0c0cbe8c;
P_0c0cbe8c: /* original d369, guest PC 0x0c0cbe8c */
if(!s->budget--) { s->failed_pc=0x0c0cbe8cu; return 0; }
r[3]=read(ram,0x0c0cc034u,4);
goto P_0c0cbe8e;
P_0c0cbe8e: /* original e01c, guest PC 0x0c0cbe8e */
if(!s->budget--) { s->failed_pc=0x0c0cbe8eu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbe90;
P_0c0cbe90: /* original f2e6, guest PC 0x0c0cbe90 */
if(!s->budget--) { s->failed_pc=0x0c0cbe90u; return 0; }
vf3_matrix_load(s,ram,2,r[14]+r[0]);
goto P_0c0cbe92;
P_0c0cbe92: /* original e120, guest PC 0x0c0cbe92 */
if(!s->budget--) { s->failed_pc=0x0c0cbe92u; return 0; }
r[1]=0x00000020u;
goto P_0c0cbe94;
P_0c0cbe94: /* original 435a, guest PC 0x0c0cbe94 */
if(!s->budget--) { s->failed_pc=0x0c0cbe94u; return 0; }
r[53]=r[3];
goto P_0c0cbe96;
P_0c0cbe96: /* original 241b, guest PC 0x0c0cbe96 */
if(!s->budget--) { s->failed_pc=0x0c0cbe96u; return 0; }
r[4]|=r[1];
goto P_0c0cbe98;
P_0c0cbe98: /* original f30d, guest PC 0x0c0cbe98 */
if(!s->budget--) { s->failed_pc=0x0c0cbe98u; return 0; }
fr[3]=r[53];
goto P_0c0cbe9a;
P_0c0cbe9a: /* original f232, guest PC 0x0c0cbe9a */
if(!s->budget--) { s->failed_pc=0x0c0cbe9au; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'*');
goto P_0c0cbe9c;
P_0c0cbe9c: /* original fe27, guest PC 0x0c0cbe9c */
if(!s->budget--) { s->failed_pc=0x0c0cbe9cu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cbe9e;
P_0c0cbe9e: /* original 2642, guest PC 0x0c0cbe9e */
if(!s->budget--) { s->failed_pc=0x0c0cbe9eu; return 0; }
write(ram,r[6],r[4],4);
goto P_0c0cbea0;
P_0c0cbea0: /* original 64e2, guest PC 0x0c0cbea0 */
if(!s->budget--) { s->failed_pc=0x0c0cbea0u; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0cbea2;
P_0c0cbea2: /* original e004, guest PC 0x0c0cbea2 */
if(!s->budget--) { s->failed_pc=0x0c0cbea2u; return 0; }
r[0]=0x00000004u;
goto P_0c0cbea4;
P_0c0cbea4: /* original 347c, guest PC 0x0c0cbea4 */
if(!s->budget--) { s->failed_pc=0x0c0cbea4u; return 0; }
r[4]+=r[7];
goto P_0c0cbea6;
P_0c0cbea6: /* original f648, guest PC 0x0c0cbea6 */
if(!s->budget--) { s->failed_pc=0x0c0cbea6u; return 0; }
vf3_matrix_load(s,ram,6,r[4]);
goto P_0c0cbea8;
P_0c0cbea8: /* original f672, guest PC 0x0c0cbea8 */
if(!s->budget--) { s->failed_pc=0x0c0cbea8u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[7],r[18],'*');
goto P_0c0cbeaa;
P_0c0cbeaa: /* original f642, guest PC 0x0c0cbeaa */
if(!s->budget--) { s->failed_pc=0x0c0cbeaau; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[4],r[18],'*');
goto P_0c0cbeac;
P_0c0cbeac: /* original f63d, guest PC 0x0c0cbeac */
if(!s->budget--) { s->failed_pc=0x0c0cbeacu; return 0; }
r[53]=truncate_float(fr[6]);
goto P_0c0cbeae;
P_0c0cbeae: /* original 025a, guest PC 0x0c0cbeae */
if(!s->budget--) { s->failed_pc=0x0c0cbeaeu; return 0; }
r[2]=r[53];
goto P_0c0cbeb0;
P_0c0cbeb0: /* original 1e24, guest PC 0x0c0cbeb0 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb0u; return 0; }
write(ram,r[14]+16,r[2],4);
goto P_0c0cbeb2;
P_0c0cbeb2: /* original f446, guest PC 0x0c0cbeb2 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb2u; return 0; }
vf3_matrix_load(s,ram,4,r[4]+r[0]);
goto P_0c0cbeb4;
P_0c0cbeb4: /* original e024, guest PC 0x0c0cbeb4 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb4u; return 0; }
r[0]=0x00000024u;
goto P_0c0cbeb6;
P_0c0cbeb6: /* original f542, guest PC 0x0c0cbeb6 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb6u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[4],r[18],'*');
goto P_0c0cbeb8;
P_0c0cbeb8: /* original fe57, guest PC 0x0c0cbeb8 */
if(!s->budget--) { s->failed_pc=0x0c0cbeb8u; return 0; }
vf3_matrix_store(s,ram,5,r[14]+r[0]);
goto P_0c0cbeba;
P_0c0cbeba: /* original e018, guest PC 0x0c0cbeba */
if(!s->budget--) { s->failed_pc=0x0c0cbebau; return 0; }
r[0]=0x00000018u;
goto P_0c0cbebc;
P_0c0cbebc: /* original f3e6, guest PC 0x0c0cbebc */
if(!s->budget--) { s->failed_pc=0x0c0cbebcu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbebe;
P_0c0cbebe: /* original e010, guest PC 0x0c0cbebe */
if(!s->budget--) { s->failed_pc=0x0c0cbebeu; return 0; }
r[0]=0x00000010u;
goto P_0c0cbec0;
P_0c0cbec0: /* original f537, guest PC 0x0c0cbec0 */
if(!s->budget--) { s->failed_pc=0x0c0cbec0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbec2;
P_0c0cbec2: /* original e01c, guest PC 0x0c0cbec2 */
if(!s->budget--) { s->failed_pc=0x0c0cbec2u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbec4;
P_0c0cbec4: /* original f3e6, guest PC 0x0c0cbec4 */
if(!s->budget--) { s->failed_pc=0x0c0cbec4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbec6;
P_0c0cbec6: /* original e014, guest PC 0x0c0cbec6 */
if(!s->budget--) { s->failed_pc=0x0c0cbec6u; return 0; }
r[0]=0x00000014u;
goto P_0c0cbec8;
P_0c0cbec8: /* original f537, guest PC 0x0c0cbec8 */
if(!s->budget--) { s->failed_pc=0x0c0cbec8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbeca;
P_0c0cbeca: /* original e020, guest PC 0x0c0cbeca */
if(!s->budget--) { s->failed_pc=0x0c0cbecau; return 0; }
r[0]=0x00000020u;
goto P_0c0cbecc;
P_0c0cbecc: /* original f3e6, guest PC 0x0c0cbecc */
if(!s->budget--) { s->failed_pc=0x0c0cbeccu; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbece;
P_0c0cbece: /* original e018, guest PC 0x0c0cbece */
if(!s->budget--) { s->failed_pc=0x0c0cbeceu; return 0; }
r[0]=0x00000018u;
goto P_0c0cbed0;
P_0c0cbed0: /* original f537, guest PC 0x0c0cbed0 */
if(!s->budget--) { s->failed_pc=0x0c0cbed0u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbed2;
P_0c0cbed2: /* original e024, guest PC 0x0c0cbed2 */
if(!s->budget--) { s->failed_pc=0x0c0cbed2u; return 0; }
r[0]=0x00000024u;
goto P_0c0cbed4;
P_0c0cbed4: /* original f3e6, guest PC 0x0c0cbed4 */
if(!s->budget--) { s->failed_pc=0x0c0cbed4u; return 0; }
vf3_matrix_load(s,ram,3,r[14]+r[0]);
goto P_0c0cbed6;
P_0c0cbed6: /* original e01c, guest PC 0x0c0cbed6 */
if(!s->budget--) { s->failed_pc=0x0c0cbed6u; return 0; }
r[0]=0x0000001cu;
goto P_0c0cbed8;
P_0c0cbed8: /* original f537, guest PC 0x0c0cbed8 */
if(!s->budget--) { s->failed_pc=0x0c0cbed8u; return 0; }
vf3_matrix_store(s,ram,3,r[5]+r[0]);
goto P_0c0cbeda;
P_0c0cbeda: /* original d357, guest PC 0x0c0cbeda */
if(!s->budget--) { s->failed_pc=0x0c0cbedau; return 0; }
r[3]=read(ram,0x0c0cc038u,4);
goto P_0c0cbedc;
P_0c0cbedc: /* original e004, guest PC 0x0c0cbedc */
if(!s->budget--) { s->failed_pc=0x0c0cbedcu; return 0; }
r[0]=0x00000004u;
goto P_0c0cbede;
P_0c0cbede: /* original 54e4, guest PC 0x0c0cbede */
if(!s->budget--) { s->failed_pc=0x0c0cbedeu; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0cbee0;
P_0c0cbee0: /* original 430b, guest PC 0x0c0cbee0 */
if(!s->budget--) { s->failed_pc=0x0c0cbee0u; return 0; }
target=r[3];
r[16]=0x0c0cbee4u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cbee4u) { target=s->pc; goto dispatch; }
goto P_0c0cbee4;
P_0c0cbee2: /* original 6143, guest PC 0x0c0cbee2 */
if(!s->budget--) { s->failed_pc=0x0c0cbee2u; return 0; }
r[1]=r[4];
goto P_0c0cbee4;
P_0c0cbee4: /* original 6303, guest PC 0x0c0cbee4 */
if(!s->budget--) { s->failed_pc=0x0c0cbee4u; return 0; }
r[3]=r[0];
goto P_0c0cbee6;
P_0c0cbee6: /* original 3438, guest PC 0x0c0cbee6 */
if(!s->budget--) { s->failed_pc=0x0c0cbee6u; return 0; }
r[4]-=r[3];
goto P_0c0cbee8;
P_0c0cbee8: /* original 4f26, guest PC 0x0c0cbee8 */
if(!s->budget--) { s->failed_pc=0x0c0cbee8u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cbeea;
P_0c0cbeea: /* original 1e04, guest PC 0x0c0cbeea */
if(!s->budget--) { s->failed_pc=0x0c0cbeeau; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0cbeec;
P_0c0cbeec: /* original e300, guest PC 0x0c0cbeec */
if(!s->budget--) { s->failed_pc=0x0c0cbeecu; return 0; }
r[3]=0x00000000u;
goto P_0c0cbeee;
P_0c0cbeee: /* original 6043, guest PC 0x0c0cbeee */
if(!s->budget--) { s->failed_pc=0x0c0cbeeeu; return 0; }
r[0]=r[4];
goto P_0c0cbef0;
P_0c0cbef0: /* original 8151, guest PC 0x0c0cbef0 */
if(!s->budget--) { s->failed_pc=0x0c0cbef0u; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c0cbef2;
P_0c0cbef2: /* original 1e35, guest PC 0x0c0cbef2 */
if(!s->budget--) { s->failed_pc=0x0c0cbef2u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c0cbef4;
P_0c0cbef4: /* original 000b, guest PC 0x0c0cbef4 */
if(!s->budget--) { s->failed_pc=0x0c0cbef4u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cbef6: /* original 6ef6, guest PC 0x0c0cbef6 */
if(!s->budget--) { s->failed_pc=0x0c0cbef6u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cbef8u,s,ram);
P_0c0cbfc8: /* original 4f22, guest PC 0x0c0cbfc8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfc8u; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c0cbfca;
P_0c0cbfca: /* original e300, guest PC 0x0c0cbfca */
if(!s->budget--) { s->failed_pc=0x0c0cbfcau; return 0; }
r[3]=0x00000000u;
goto P_0c0cbfcc;
P_0c0cbfcc: /* original 6233, guest PC 0x0c0cbfcc */
if(!s->budget--) { s->failed_pc=0x0c0cbfccu; return 0; }
r[2]=r[3];
goto P_0c0cbfce;
P_0c0cbfce: /* original 5ef2, guest PC 0x0c0cbfce */
if(!s->budget--) { s->failed_pc=0x0c0cbfceu; return 0; }
r[14]=read(ram,r[15]+8,4);
goto P_0c0cbfd0;
P_0c0cbfd0: /* original 1e34, guest PC 0x0c0cbfd0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd0u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cbfd2;
P_0c0cbfd2: /* original 1e33, guest PC 0x0c0cbfd2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd2u; return 0; }
write(ram,r[14]+12,r[3],4);
goto P_0c0cbfd4;
P_0c0cbfd4: /* original f378, guest PC 0x0c0cbfd4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cbfd6;
P_0c0cbfd6: /* original f468, guest PC 0x0c0cbfd6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd6u; return 0; }
vf3_matrix_load(s,ram,4,r[6]);
goto P_0c0cbfd8;
P_0c0cbfd8: /* original f666, guest PC 0x0c0cbfd8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfd8u; return 0; }
vf3_matrix_load(s,ram,6,r[6]+r[0]);
goto P_0c0cbfda;
P_0c0cbfda: /* original f431, guest PC 0x0c0cbfda */
if(!s->budget--) { s->failed_pc=0x0c0cbfdau; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'-');
goto P_0c0cbfdc;
P_0c0cbfdc: /* original f376, guest PC 0x0c0cbfdc */
if(!s->budget--) { s->failed_pc=0x0c0cbfdcu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbfde;
P_0c0cbfde: /* original e008, guest PC 0x0c0cbfde */
if(!s->budget--) { s->failed_pc=0x0c0cbfdeu; return 0; }
r[0]=0x00000008u;
goto P_0c0cbfe0;
P_0c0cbfe0: /* original f631, guest PC 0x0c0cbfe0 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe0u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'-');
goto P_0c0cbfe2;
P_0c0cbfe2: /* original f566, guest PC 0x0c0cbfe2 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe2u; return 0; }
vf3_matrix_load(s,ram,5,r[6]+r[0]);
goto P_0c0cbfe4;
P_0c0cbfe4: /* original f376, guest PC 0x0c0cbfe4 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe4u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cbfe6;
P_0c0cbfe6: /* original c70d, guest PC 0x0c0cbfe6 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe6u; return 0; }
r[0]=0x0c0cc01cu;
goto P_0c0cbfe8;
P_0c0cbfe8: /* original f74c, guest PC 0x0c0cbfe8 */
if(!s->budget--) { s->failed_pc=0x0c0cbfe8u; return 0; }
vf3_matrix_move(s,7,4);
goto P_0c0cbfea;
P_0c0cbfea: /* original f742, guest PC 0x0c0cbfea */
if(!s->budget--) { s->failed_pc=0x0c0cbfeau; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[4],r[18],'*');
goto P_0c0cbfec;
P_0c0cbfec: /* original f531, guest PC 0x0c0cbfec */
if(!s->budget--) { s->failed_pc=0x0c0cbfecu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'-');
goto P_0c0cbfee;
P_0c0cbfee: /* original f06c, guest PC 0x0c0cbfee */
if(!s->budget--) { s->failed_pc=0x0c0cbfeeu; return 0; }
vf3_matrix_move(s,0,6);
goto P_0c0cbff0;
P_0c0cbff0: /* original f37c, guest PC 0x0c0cbff0 */
if(!s->budget--) { s->failed_pc=0x0c0cbff0u; return 0; }
vf3_matrix_move(s,3,7);
goto P_0c0cbff2;
P_0c0cbff2: /* original f85c, guest PC 0x0c0cbff2 */
if(!s->budget--) { s->failed_pc=0x0c0cbff2u; return 0; }
vf3_matrix_move(s,8,5);
goto P_0c0cbff4;
P_0c0cbff4: /* original f852, guest PC 0x0c0cbff4 */
if(!s->budget--) { s->failed_pc=0x0c0cbff4u; return 0; }
fr[8]=vf3_fpu_binary(fr[8],fr[5],r[18],'*');
goto P_0c0cbff6;
P_0c0cbff6: /* original f708, guest PC 0x0c0cbff6 */
if(!s->budget--) { s->failed_pc=0x0c0cbff6u; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cbff8;
P_0c0cbff8: /* original f58c, guest PC 0x0c0cbff8 */
if(!s->budget--) { s->failed_pc=0x0c0cbff8u; return 0; }
vf3_matrix_move(s,5,8);
goto P_0c0cbffa;
P_0c0cbffa: /* original f530, guest PC 0x0c0cbffa */
if(!s->budget--) { s->failed_pc=0x0c0cbffau; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'+');
goto P_0c0cbffc;
P_0c0cbffc: /* original f48c, guest PC 0x0c0cbffc */
if(!s->budget--) { s->failed_pc=0x0c0cbffcu; return 0; }
vf3_matrix_move(s,4,8);
goto P_0c0cbffe;
P_0c0cbffe: /* original f430, guest PC 0x0c0cbffe */
if(!s->budget--) { s->failed_pc=0x0c0cbffeu; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[3],r[18],'+');
goto P_0c0cc000;
P_0c0cc000: /* original f25c, guest PC 0x0c0cc000 */
if(!s->budget--) { s->failed_pc=0x0c0cc000u; return 0; }
vf3_matrix_move(s,2,5);
goto P_0c0cc002;
P_0c0cc002: /* original f26e, guest PC 0x0c0cc002 */
if(!s->budget--) { s->failed_pc=0x0c0cc002u; return 0; }
fr[2]=vf3_fpu_mac(fr[0],fr[6],fr[2],r[18]);
goto P_0c0cc004;
P_0c0cc004: /* original f755, guest PC 0x0c0cc004 */
if(!s->budget--) { s->failed_pc=0x0c0cc004u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[5]))!=0);
goto P_0c0cc006;
P_0c0cc006: /* original 8f02, guest PC 0x0c0cc006 */
if(!s->budget--) { s->failed_pc=0x0c0cc006u; return 0; }
cond=r[17]&1u;
vf3_matrix_move(s,6,2);
if(!cond) { goto P_0c0cc00e; }
goto P_0c0cc00a;
P_0c0cc008: /* original f62c, guest PC 0x0c0cc008 */
if(!s->budget--) { s->failed_pc=0x0c0cc008u; return 0; }
vf3_matrix_move(s,6,2);
goto P_0c0cc00a;
P_0c0cc00a: /* original a001, guest PC 0x0c0cc00a */
if(!s->budget--) { s->failed_pc=0x0c0cc00au; return 0; }
fr[5]=0;
goto P_0c0cc010;
P_0c0cc00c: /* original f58d, guest PC 0x0c0cc00c */
if(!s->budget--) { s->failed_pc=0x0c0cc00cu; return 0; }
fr[5]=0;
goto P_0c0cc00e;
P_0c0cc00e: /* original f57d, guest PC 0x0c0cc00e */
if(!s->budget--) { s->failed_pc=0x0c0cc00eu; return 0; }
if(!vf3_fpu_fsrra(fr[5],r[18],&fr[5])) goto unsupported;
goto P_0c0cc010;
P_0c0cc010: /* original f765, guest PC 0x0c0cc010 */
if(!s->budget--) { s->failed_pc=0x0c0cc010u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[6]))!=0);
goto P_0c0cc012;
P_0c0cc012: /* original 8f17, guest PC 0x0c0cc012 */
if(!s->budget--) { s->failed_pc=0x0c0cc012u; return 0; }
cond=r[17]&1u;
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
if(!cond) { goto P_0c0cc044; }
goto P_0c0cc016;
P_0c0cc014: /* original f452, guest PC 0x0c0cc014 */
if(!s->budget--) { s->failed_pc=0x0c0cc014u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[5],r[18],'*');
goto P_0c0cc016;
P_0c0cc016: /* original a016, guest PC 0x0c0cc016 */
if(!s->budget--) { s->failed_pc=0x0c0cc016u; return 0; }
fr[6]=0;
goto P_0c0cc046;
P_0c0cc018: /* original f68d, guest PC 0x0c0cc018 */
if(!s->budget--) { s->failed_pc=0x0c0cc018u; return 0; }
fr[6]=0;
return vf3_matrix_family(0x0c0cc01au,s,ram);
P_0c0cc044: /* original f67d, guest PC 0x0c0cc044 */
if(!s->budget--) { s->failed_pc=0x0c0cc044u; return 0; }
if(!vf3_fpu_fsrra(fr[6],r[18],&fr[6])) goto unsupported;
goto P_0c0cc046;
P_0c0cc046: /* original f462, guest PC 0x0c0cc046 */
if(!s->budget--) { s->failed_pc=0x0c0cc046u; return 0; }
fr[4]=vf3_fpu_binary(fr[4],fr[6],r[18],'*');
goto P_0c0cc048;
P_0c0cc048: /* original f69d, guest PC 0x0c0cc048 */
if(!s->budget--) { s->failed_pc=0x0c0cc048u; return 0; }
fr[6]=0x3f800000u;
goto P_0c0cc04a;
P_0c0cc04a: /* original f653, guest PC 0x0c0cc04a */
if(!s->budget--) { s->failed_pc=0x0c0cc04au; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[5],r[18],'/');
goto P_0c0cc04c;
P_0c0cc04c: /* original c7c1, guest PC 0x0c0cc04c */
if(!s->budget--) { s->failed_pc=0x0c0cc04cu; return 0; }
r[0]=0x0c0cc354u;
goto P_0c0cc04e;
P_0c0cc04e: /* original f808, guest PC 0x0c0cc04e */
if(!s->budget--) { s->failed_pc=0x0c0cc04eu; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c0cc050;
P_0c0cc050: /* original c7c1, guest PC 0x0c0cc050 */
if(!s->budget--) { s->failed_pc=0x0c0cc050u; return 0; }
r[0]=0x0c0cc358u;
goto P_0c0cc052;
P_0c0cc052: /* original f508, guest PC 0x0c0cc052 */
if(!s->budget--) { s->failed_pc=0x0c0cc052u; return 0; }
vf3_matrix_load(s,ram,5,r[0]);
goto P_0c0cc054;
P_0c0cc054: /* original c7c1, guest PC 0x0c0cc054 */
if(!s->budget--) { s->failed_pc=0x0c0cc054u; return 0; }
r[0]=0x0c0cc35cu;
goto P_0c0cc056;
P_0c0cc056: /* original f685, guest PC 0x0c0cc056 */
if(!s->budget--) { s->failed_pc=0x0c0cc056u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[8]))!=0);
goto P_0c0cc058;
P_0c0cc058: /* original 8f1d, guest PC 0x0c0cc058 */
if(!s->budget--) { s->failed_pc=0x0c0cc058u; return 0; }
cond=r[17]&1u;
vf3_matrix_load(s,ram,7,r[0]);
if(!cond) { goto P_0c0cc096; }
goto P_0c0cc05c;
P_0c0cc05a: /* original f708, guest PC 0x0c0cc05a */
if(!s->budget--) { s->failed_pc=0x0c0cc05au; return 0; }
vf3_matrix_load(s,ram,7,r[0]);
goto P_0c0cc05c;
P_0c0cc05c: /* original f655, guest PC 0x0c0cc05c */
if(!s->budget--) { s->failed_pc=0x0c0cc05cu; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[6])>as_float(fr[5]))!=0);
goto P_0c0cc05e;
P_0c0cc05e: /* original 8b00, guest PC 0x0c0cc05e */
if(!s->budget--) { s->failed_pc=0x0c0cc05eu; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc062; }
goto P_0c0cc060;
P_0c0cc060: /* original f65c, guest PC 0x0c0cc060 */
if(!s->budget--) { s->failed_pc=0x0c0cc060u; return 0; }
vf3_matrix_move(s,6,5);
goto P_0c0cc062;
P_0c0cc062: /* original f745, guest PC 0x0c0cc062 */
if(!s->budget--) { s->failed_pc=0x0c0cc062u; return 0; }
r[17]=(r[17]&~1u)|((as_float(fr[7])>as_float(fr[4]))!=0);
goto P_0c0cc064;
P_0c0cc064: /* original 8b00, guest PC 0x0c0cc064 */
if(!s->budget--) { s->failed_pc=0x0c0cc064u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c0cc068; }
goto P_0c0cc066;
P_0c0cc066: /* original f47c, guest PC 0x0c0cc066 */
if(!s->budget--) { s->failed_pc=0x0c0cc066u; return 0; }
vf3_matrix_move(s,4,7);
goto P_0c0cc068;
P_0c0cc068: /* original e018, guest PC 0x0c0cc068 */
if(!s->budget--) { s->failed_pc=0x0c0cc068u; return 0; }
r[0]=0x00000018u;
goto P_0c0cc06a;
P_0c0cc06a: /* original d1bd, guest PC 0x0c0cc06a */
if(!s->budget--) { s->failed_pc=0x0c0cc06au; return 0; }
r[1]=read(ram,0x0c0cc360u,4);
goto P_0c0cc06c;
P_0c0cc06c: /* original f746, guest PC 0x0c0cc06c */
if(!s->budget--) { s->failed_pc=0x0c0cc06cu; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cc06e;
P_0c0cc06e: /* original 50e2, guest PC 0x0c0cc06e */
if(!s->budget--) { s->failed_pc=0x0c0cc06eu; return 0; }
r[0]=read(ram,r[14]+8,4);
goto P_0c0cc070;
P_0c0cc070: /* original c802, guest PC 0x0c0cc070 */
if(!s->budget--) { s->failed_pc=0x0c0cc070u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c0cc072;
P_0c0cc072: /* original 8902, guest PC 0x0c0cc072 */
if(!s->budget--) { s->failed_pc=0x0c0cc072u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c0cc07a; }
goto P_0c0cc074;
P_0c0cc074: /* original e014, guest PC 0x0c0cc074 */
if(!s->budget--) { s->failed_pc=0x0c0cc074u; return 0; }
r[0]=0x00000014u;
goto P_0c0cc076;
P_0c0cc076: /* original f746, guest PC 0x0c0cc076 */
if(!s->budget--) { s->failed_pc=0x0c0cc076u; return 0; }
vf3_matrix_load(s,ram,7,r[4]+r[0]);
goto P_0c0cc078;
P_0c0cc078: /* original 7118, guest PC 0x0c0cc078 */
if(!s->budget--) { s->failed_pc=0x0c0cc078u; return 0; }
r[1]+=0x00000018u;
goto P_0c0cc07a;
P_0c0cc07a: /* original 64e2, guest PC 0x0c0cc07a */
if(!s->budget--) { s->failed_pc=0x0c0cc07au; return 0; }
tmp=read(ram,r[14],4);
r[4]=tmp;
goto P_0c0cc07c;
P_0c0cc07c: /* original f57c, guest PC 0x0c0cc07c */
if(!s->budget--) { s->failed_pc=0x0c0cc07cu; return 0; }
vf3_matrix_move(s,5,7);
goto P_0c0cc07e;
P_0c0cc07e: /* original 341c, guest PC 0x0c0cc07e */
if(!s->budget--) { s->failed_pc=0x0c0cc07eu; return 0; }
r[4]+=r[1];
goto P_0c0cc080;
P_0c0cc080: /* original f348, guest PC 0x0c0cc080 */
if(!s->budget--) { s->failed_pc=0x0c0cc080u; return 0; }
vf3_matrix_load(s,ram,3,r[4]);
goto P_0c0cc082;
P_0c0cc082: /* original f532, guest PC 0x0c0cc082 */
if(!s->budget--) { s->failed_pc=0x0c0cc082u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc084;
P_0c0cc084: /* original f35c, guest PC 0x0c0cc084 */
if(!s->budget--) { s->failed_pc=0x0c0cc084u; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cc086;
P_0c0cc086: /* original f54c, guest PC 0x0c0cc086 */
if(!s->budget--) { s->failed_pc=0x0c0cc086u; return 0; }
vf3_matrix_move(s,5,4);
goto P_0c0cc088;
P_0c0cc088: /* original f532, guest PC 0x0c0cc088 */
if(!s->budget--) { s->failed_pc=0x0c0cc088u; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc08a;
P_0c0cc08a: /* original f35c, guest PC 0x0c0cc08a */
if(!s->budget--) { s->failed_pc=0x0c0cc08au; return 0; }
vf3_matrix_move(s,3,5);
goto P_0c0cc08c;
P_0c0cc08c: /* original f56c, guest PC 0x0c0cc08c */
if(!s->budget--) { s->failed_pc=0x0c0cc08cu; return 0; }
vf3_matrix_move(s,5,6);
goto P_0c0cc08e;
P_0c0cc08e: /* original f532, guest PC 0x0c0cc08e */
if(!s->budget--) { s->failed_pc=0x0c0cc08eu; return 0; }
fr[5]=vf3_fpu_binary(fr[5],fr[3],r[18],'*');
goto P_0c0cc090;
P_0c0cc090: /* original f53d, guest PC 0x0c0cc090 */
if(!s->budget--) { s->failed_pc=0x0c0cc090u; return 0; }
r[53]=truncate_float(fr[5]);
goto P_0c0cc092;
P_0c0cc092: /* original 035a, guest PC 0x0c0cc092 */
if(!s->budget--) { s->failed_pc=0x0c0cc092u; return 0; }
r[3]=r[53];
goto P_0c0cc094;
P_0c0cc094: /* original 1e34, guest PC 0x0c0cc094 */
if(!s->budget--) { s->failed_pc=0x0c0cc094u; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c0cc096;
P_0c0cc096: /* original d2b3, guest PC 0x0c0cc096 */
if(!s->budget--) { s->failed_pc=0x0c0cc096u; return 0; }
r[2]=read(ram,0x0c0cc364u,4);
goto P_0c0cc098;
P_0c0cc098: /* original e004, guest PC 0x0c0cc098 */
if(!s->budget--) { s->failed_pc=0x0c0cc098u; return 0; }
r[0]=0x00000004u;
goto P_0c0cc09a;
P_0c0cc09a: /* original 54e4, guest PC 0x0c0cc09a */
if(!s->budget--) { s->failed_pc=0x0c0cc09au; return 0; }
r[4]=read(ram,r[14]+16,4);
goto P_0c0cc09c;
P_0c0cc09c: /* original 420b, guest PC 0x0c0cc09c */
if(!s->budget--) { s->failed_pc=0x0c0cc09cu; return 0; }
target=r[2];
r[16]=0x0c0cc0a0u;
r[1]=r[4];
if(!vf3_matrix_family(target,s,ram)) return 0; if(s->pc!=0x0c0cc0a0u) { target=s->pc; goto dispatch; }
goto P_0c0cc0a0;
P_0c0cc09e: /* original 6143, guest PC 0x0c0cc09e */
if(!s->budget--) { s->failed_pc=0x0c0cc09eu; return 0; }
r[1]=r[4];
goto P_0c0cc0a0;
P_0c0cc0a0: /* original 6303, guest PC 0x0c0cc0a0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a0u; return 0; }
r[3]=r[0];
goto P_0c0cc0a2;
P_0c0cc0a2: /* original 1e04, guest PC 0x0c0cc0a2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a2u; return 0; }
write(ram,r[14]+16,r[0],4);
goto P_0c0cc0a4;
P_0c0cc0a4: /* original 3438, guest PC 0x0c0cc0a4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a4u; return 0; }
r[4]-=r[3];
goto P_0c0cc0a6;
P_0c0cc0a6: /* original 6043, guest PC 0x0c0cc0a6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a6u; return 0; }
r[0]=r[4];
goto P_0c0cc0a8;
P_0c0cc0a8: /* original 8151, guest PC 0x0c0cc0a8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0a8u; return 0; }
write(ram,r[5]+2,r[0],2);
goto P_0c0cc0aa;
P_0c0cc0aa: /* original f378, guest PC 0x0c0cc0aa */
if(!s->budget--) { s->failed_pc=0x0c0cc0aau; return 0; }
vf3_matrix_load(s,ram,3,r[7]);
goto P_0c0cc0ac;
P_0c0cc0ac: /* original e018, guest PC 0x0c0cc0ac */
if(!s->budget--) { s->failed_pc=0x0c0cc0acu; return 0; }
r[0]=0x00000018u;
goto P_0c0cc0ae;
P_0c0cc0ae: /* original f268, guest PC 0x0c0cc0ae */
if(!s->budget--) { s->failed_pc=0x0c0cc0aeu; return 0; }
vf3_matrix_load(s,ram,2,r[6]);
goto P_0c0cc0b0;
P_0c0cc0b0: /* original e304, guest PC 0x0c0cc0b0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b0u; return 0; }
r[3]=0x00000004u;
goto P_0c0cc0b2;
P_0c0cc0b2: /* original 4f26, guest PC 0x0c0cc0b2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b2u; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c0cc0b4;
P_0c0cc0b4: /* original f231, guest PC 0x0c0cc0b4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b4u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc0b6;
P_0c0cc0b6: /* original fe27, guest PC 0x0c0cc0b6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b6u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cc0b8;
P_0c0cc0b8: /* original e004, guest PC 0x0c0cc0b8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0b8u; return 0; }
r[0]=0x00000004u;
goto P_0c0cc0ba;
P_0c0cc0ba: /* original f266, guest PC 0x0c0cc0ba */
if(!s->budget--) { s->failed_pc=0x0c0cc0bau; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cc0bc;
P_0c0cc0bc: /* original f376, guest PC 0x0c0cc0bc */
if(!s->budget--) { s->failed_pc=0x0c0cc0bcu; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc0be;
P_0c0cc0be: /* original e01c, guest PC 0x0c0cc0be */
if(!s->budget--) { s->failed_pc=0x0c0cc0beu; return 0; }
r[0]=0x0000001cu;
goto P_0c0cc0c0;
P_0c0cc0c0: /* original f231, guest PC 0x0c0cc0c0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c0u; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc0c2;
P_0c0cc0c2: /* original fe27, guest PC 0x0c0cc0c2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c2u; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cc0c4;
P_0c0cc0c4: /* original e008, guest PC 0x0c0cc0c4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c4u; return 0; }
r[0]=0x00000008u;
goto P_0c0cc0c6;
P_0c0cc0c6: /* original f266, guest PC 0x0c0cc0c6 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c6u; return 0; }
vf3_matrix_load(s,ram,2,r[6]+r[0]);
goto P_0c0cc0c8;
P_0c0cc0c8: /* original f376, guest PC 0x0c0cc0c8 */
if(!s->budget--) { s->failed_pc=0x0c0cc0c8u; return 0; }
vf3_matrix_load(s,ram,3,r[7]+r[0]);
goto P_0c0cc0ca;
P_0c0cc0ca: /* original e020, guest PC 0x0c0cc0ca */
if(!s->budget--) { s->failed_pc=0x0c0cc0cau; return 0; }
r[0]=0x00000020u;
goto P_0c0cc0cc;
P_0c0cc0cc: /* original f231, guest PC 0x0c0cc0cc */
if(!s->budget--) { s->failed_pc=0x0c0cc0ccu; return 0; }
fr[2]=vf3_fpu_binary(fr[2],fr[3],r[18],'-');
goto P_0c0cc0ce;
P_0c0cc0ce: /* original fe27, guest PC 0x0c0cc0ce */
if(!s->budget--) { s->failed_pc=0x0c0cc0ceu; return 0; }
vf3_matrix_store(s,ram,2,r[14]+r[0]);
goto P_0c0cc0d0;
P_0c0cc0d0: /* original 1e35, guest PC 0x0c0cc0d0 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d0u; return 0; }
write(ram,r[14]+20,r[3],4);
goto P_0c0cc0d2;
P_0c0cc0d2: /* original 000b, guest PC 0x0c0cc0d2 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d2u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c0cc0d4: /* original 6ef6, guest PC 0x0c0cc0d4 */
if(!s->budget--) { s->failed_pc=0x0c0cc0d4u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c0cc0d6u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
