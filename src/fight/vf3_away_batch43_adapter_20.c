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
int vf3_away_batch43_adapter_20(uint32_t entry,vf3_matrix_state*s,const vf3_ram_map*ram) {
uint32_t *r=s->v,*fr=r+21,*xf=r+37,target=entry,cond=0,tmp=0; uint64_t wide=0;
/* PR keeps the alias of the executing image: the capture alias is visible in the caller return address. */
uint32_t code_base=((entry&0xff000000u)==0x8c000000u)?(((r[16]&0xff000000u)==0x0c000000u)?0x0c000000u:0x8c000000u):(entry&0xff000000u);
dispatch:
if(!s->budget--) goto unsupported;
switch(target&0x1fffffffu) {
case 0x0c07b9a4u: goto P_0c07b9a4;
case 0x0c07b9a6u: goto P_0c07b9a6;
case 0x0c07b9a8u: goto P_0c07b9a8;
case 0x0c07b9aau: goto P_0c07b9aa;
case 0x0c07b9acu: goto P_0c07b9ac;
case 0x0c07b9aeu: goto P_0c07b9ae;
case 0x0c07b9b0u: goto P_0c07b9b0;
case 0x0c07b9b2u: goto P_0c07b9b2;
case 0x0c07b9b4u: goto P_0c07b9b4;
case 0x0c07b9b6u: goto P_0c07b9b6;
case 0x0c07b9b8u: goto P_0c07b9b8;
case 0x0c07b9bau: goto P_0c07b9ba;
case 0x0c07b9bcu: goto P_0c07b9bc;
case 0x0c07b9beu: goto P_0c07b9be;
case 0x0c07b9c0u: goto P_0c07b9c0;
case 0x0c07b9c2u: goto P_0c07b9c2;
case 0x0c07b9c4u: goto P_0c07b9c4;
case 0x0c07b9c6u: goto P_0c07b9c6;
case 0x0c07b9c8u: goto P_0c07b9c8;
case 0x0c07b9cau: goto P_0c07b9ca;
case 0x0c07b9ccu: goto P_0c07b9cc;
case 0x0c07b9ceu: goto P_0c07b9ce;
case 0x0c07b9d0u: goto P_0c07b9d0;
case 0x0c07b9d2u: goto P_0c07b9d2;
case 0x0c07b9d4u: goto P_0c07b9d4;
case 0x0c07b9d6u: goto P_0c07b9d6;
case 0x0c07b9d8u: goto P_0c07b9d8;
case 0x0c07b9dau: goto P_0c07b9da;
case 0x0c07b9dcu: goto P_0c07b9dc;
case 0x0c07b9deu: goto P_0c07b9de;
case 0x0c07b9e0u: goto P_0c07b9e0;
case 0x0c07b9e2u: goto P_0c07b9e2;
case 0x0c07b9e4u: goto P_0c07b9e4;
case 0x0c07b9e6u: goto P_0c07b9e6;
case 0x0c07b9e8u: goto P_0c07b9e8;
case 0x0c07b9eau: goto P_0c07b9ea;
case 0x0c07b9ecu: goto P_0c07b9ec;
case 0x0c07b9eeu: goto P_0c07b9ee;
case 0x0c07b9f0u: goto P_0c07b9f0;
case 0x0c07b9f2u: goto P_0c07b9f2;
case 0x0c07b9f4u: goto P_0c07b9f4;
case 0x0c07b9f6u: goto P_0c07b9f6;
case 0x0c07b9f8u: goto P_0c07b9f8;
case 0x0c07b9fau: goto P_0c07b9fa;
case 0x0c07b9fcu: goto P_0c07b9fc;
case 0x0c07b9feu: goto P_0c07b9fe;
case 0x0c07ba00u: goto P_0c07ba00;
case 0x0c07ba02u: goto P_0c07ba02;
case 0x0c07ba04u: goto P_0c07ba04;
case 0x0c07ba06u: goto P_0c07ba06;
case 0x0c07ba08u: goto P_0c07ba08;
case 0x0c07ba28u: goto P_0c07ba28;
case 0x0c07ba2au: goto P_0c07ba2a;
case 0x0c07ba2cu: goto P_0c07ba2c;
case 0x0c07ba2eu: goto P_0c07ba2e;
case 0x0c07ba30u: goto P_0c07ba30;
case 0x0c07ba32u: goto P_0c07ba32;
case 0x0c07ba34u: goto P_0c07ba34;
case 0x0c07ba36u: goto P_0c07ba36;
case 0x0c07ba38u: goto P_0c07ba38;
case 0x0c07ba3au: goto P_0c07ba3a;
case 0x0c07ba3cu: goto P_0c07ba3c;
case 0x0c07ba3eu: goto P_0c07ba3e;
case 0x0c07ba40u: goto P_0c07ba40;
case 0x0c07ba42u: goto P_0c07ba42;
case 0x0c07ba44u: goto P_0c07ba44;
case 0x0c07ba46u: goto P_0c07ba46;
case 0x0c07ba48u: goto P_0c07ba48;
case 0x0c07ba4au: goto P_0c07ba4a;
case 0x0c07ba4cu: goto P_0c07ba4c;
case 0x0c07ba4eu: goto P_0c07ba4e;
case 0x0c07ba50u: goto P_0c07ba50;
case 0x0c07ba52u: goto P_0c07ba52;
case 0x0c07ba54u: goto P_0c07ba54;
case 0x0c07ba56u: goto P_0c07ba56;
case 0x0c07ba58u: goto P_0c07ba58;
case 0x0c07ba5au: goto P_0c07ba5a;
case 0x0c07ba5cu: goto P_0c07ba5c;
case 0x0c07ba5eu: goto P_0c07ba5e;
case 0x0c07ba60u: goto P_0c07ba60;
case 0x0c07ba62u: goto P_0c07ba62;
case 0x0c07ba64u: goto P_0c07ba64;
case 0x0c07ba66u: goto P_0c07ba66;
case 0x0c07ba68u: goto P_0c07ba68;
case 0x0c07ba6au: goto P_0c07ba6a;
case 0x0c07ba6cu: goto P_0c07ba6c;
case 0x0c07ba6eu: goto P_0c07ba6e;
case 0x0c07ba70u: goto P_0c07ba70;
case 0x0c07ba72u: goto P_0c07ba72;
case 0x0c07ba74u: goto P_0c07ba74;
case 0x0c07ba76u: goto P_0c07ba76;
case 0x0c07ba78u: goto P_0c07ba78;
case 0x0c07ba7au: goto P_0c07ba7a;
case 0x0c07ba7cu: goto P_0c07ba7c;
case 0x0c07ba7eu: goto P_0c07ba7e;
case 0x0c07ba80u: goto P_0c07ba80;
case 0x0c07ba82u: goto P_0c07ba82;
case 0x0c07ba84u: goto P_0c07ba84;
case 0x0c07ba86u: goto P_0c07ba86;
case 0x0c07ba88u: goto P_0c07ba88;
case 0x0c07ba8au: goto P_0c07ba8a;
case 0x0c07ba8cu: goto P_0c07ba8c;
case 0x0c07ba8eu: goto P_0c07ba8e;
case 0x0c07ba90u: goto P_0c07ba90;
case 0x0c07ba92u: goto P_0c07ba92;
case 0x0c07ba94u: goto P_0c07ba94;
case 0x0c07ba96u: goto P_0c07ba96;
case 0x0c07ba98u: goto P_0c07ba98;
case 0x0c07ba9au: goto P_0c07ba9a;
case 0x0c07ba9cu: goto P_0c07ba9c;
case 0x0c07ba9eu: goto P_0c07ba9e;
case 0x0c07baa0u: goto P_0c07baa0;
case 0x0c07baa2u: goto P_0c07baa2;
case 0x0c07baa4u: goto P_0c07baa4;
case 0x0c07baa6u: goto P_0c07baa6;
case 0x0c07baa8u: goto P_0c07baa8;
case 0x0c07baaau: goto P_0c07baaa;
case 0x0c07baacu: goto P_0c07baac;
case 0x0c07baaeu: goto P_0c07baae;
case 0x0c07bab0u: goto P_0c07bab0;
case 0x0c07bab2u: goto P_0c07bab2;
case 0x0c07bab4u: goto P_0c07bab4;
case 0x0c07bab6u: goto P_0c07bab6;
case 0x0c07bab8u: goto P_0c07bab8;
case 0x0c07babau: goto P_0c07baba;
case 0x0c07babcu: goto P_0c07babc;
case 0x0c07babeu: goto P_0c07babe;
case 0x0c07bac0u: goto P_0c07bac0;
case 0x0c07bac2u: goto P_0c07bac2;
case 0x0c07bac4u: goto P_0c07bac4;
case 0x0c07bac6u: goto P_0c07bac6;
case 0x0c07bac8u: goto P_0c07bac8;
case 0x0c07bacau: goto P_0c07baca;
case 0x0c07baccu: goto P_0c07bacc;
case 0x0c07baceu: goto P_0c07bace;
case 0x0c07bad0u: goto P_0c07bad0;
case 0x0c07bad2u: goto P_0c07bad2;
case 0x0c07bad4u: goto P_0c07bad4;
case 0x0c07bad6u: goto P_0c07bad6;
case 0x0c07bad8u: goto P_0c07bad8;
case 0x0c07badau: goto P_0c07bada;
case 0x0c07badcu: goto P_0c07badc;
case 0x0c07badeu: goto P_0c07bade;
case 0x0c07bae0u: goto P_0c07bae0;
case 0x0c07bae2u: goto P_0c07bae2;
case 0x0c07bae4u: goto P_0c07bae4;
case 0x0c07bae6u: goto P_0c07bae6;
case 0x0c07bae8u: goto P_0c07bae8;
case 0x0c07baeau: goto P_0c07baea;
case 0x0c07baecu: goto P_0c07baec;
case 0x0c07baeeu: goto P_0c07baee;
case 0x0c07baf0u: goto P_0c07baf0;
case 0x0c07baf2u: goto P_0c07baf2;
case 0x0c07baf4u: goto P_0c07baf4;
case 0x0c07baf6u: goto P_0c07baf6;
case 0x0c07baf8u: goto P_0c07baf8;
case 0x0c07bafau: goto P_0c07bafa;
case 0x0c07bafcu: goto P_0c07bafc;
case 0x0c07bafeu: goto P_0c07bafe;
case 0x0c07bb00u: goto P_0c07bb00;
case 0x0c07bb02u: goto P_0c07bb02;
case 0x0c07bb04u: goto P_0c07bb04;
case 0x0c07bb06u: goto P_0c07bb06;
case 0x0c07bb08u: goto P_0c07bb08;
case 0x0c07bb0au: goto P_0c07bb0a;
case 0x0c07bb0cu: goto P_0c07bb0c;
case 0x0c07bb0eu: goto P_0c07bb0e;
case 0x0c07bb10u: goto P_0c07bb10;
case 0x0c07bb12u: goto P_0c07bb12;
case 0x0c07bb14u: goto P_0c07bb14;
case 0x0c07bb16u: goto P_0c07bb16;
case 0x0c07bb18u: goto P_0c07bb18;
case 0x0c07bb1au: goto P_0c07bb1a;
case 0x0c07bb1cu: goto P_0c07bb1c;
case 0x0c07bb1eu: goto P_0c07bb1e;
case 0x0c07bb20u: goto P_0c07bb20;
case 0x0c07bb22u: goto P_0c07bb22;
case 0x0c07bb24u: goto P_0c07bb24;
case 0x0c07bb26u: goto P_0c07bb26;
case 0x0c07bb28u: goto P_0c07bb28;
case 0x0c07bb2au: goto P_0c07bb2a;
case 0x0c07bb2cu: goto P_0c07bb2c;
case 0x0c07bb2eu: goto P_0c07bb2e;
case 0x0c07bb30u: goto P_0c07bb30;
case 0x0c07bb32u: goto P_0c07bb32;
case 0x0c07bb34u: goto P_0c07bb34;
case 0x0c07bb36u: goto P_0c07bb36;
case 0x0c07bb38u: goto P_0c07bb38;
case 0x0c07bb3au: goto P_0c07bb3a;
case 0x0c07bb3cu: goto P_0c07bb3c;
case 0x0c07bb3eu: goto P_0c07bb3e;
case 0x0c07bb40u: goto P_0c07bb40;
case 0x0c07bb42u: goto P_0c07bb42;
case 0x0c07bb44u: goto P_0c07bb44;
case 0x0c07bb46u: goto P_0c07bb46;
case 0x0c07bba0u: goto P_0c07bba0;
case 0x0c07bba2u: goto P_0c07bba2;
case 0x0c07bba4u: goto P_0c07bba4;
case 0x0c07bba6u: goto P_0c07bba6;
case 0x0c07bba8u: goto P_0c07bba8;
case 0x0c07bbaau: goto P_0c07bbaa;
case 0x0c07bbacu: goto P_0c07bbac;
case 0x0c07bbaeu: goto P_0c07bbae;
case 0x0c07bbb0u: goto P_0c07bbb0;
case 0x0c07bbb2u: goto P_0c07bbb2;
case 0x0c07bbb4u: goto P_0c07bbb4;
case 0x0c07bbb6u: goto P_0c07bbb6;
case 0x0c07bbb8u: goto P_0c07bbb8;
case 0x0c07bbbau: goto P_0c07bbba;
case 0x0c07bbbcu: goto P_0c07bbbc;
case 0x0c07bbbeu: goto P_0c07bbbe;
case 0x0c07bbc0u: goto P_0c07bbc0;
case 0x0c07bbc2u: goto P_0c07bbc2;
case 0x0c07bbc4u: goto P_0c07bbc4;
case 0x0c07bbc6u: goto P_0c07bbc6;
case 0x0c07bbc8u: goto P_0c07bbc8;
case 0x0c07bbcau: goto P_0c07bbca;
case 0x0c07bbccu: goto P_0c07bbcc;
case 0x0c07bbceu: goto P_0c07bbce;
case 0x0c07bbd0u: goto P_0c07bbd0;
case 0x0c07bbd2u: goto P_0c07bbd2;
case 0x0c07bbd4u: goto P_0c07bbd4;
case 0x0c07bbd6u: goto P_0c07bbd6;
case 0x0c07bbd8u: goto P_0c07bbd8;
case 0x0c07bbdau: goto P_0c07bbda;
case 0x0c07bbdcu: goto P_0c07bbdc;
case 0x0c07bbdeu: goto P_0c07bbde;
case 0x0c07bbe0u: goto P_0c07bbe0;
case 0x0c07bbe2u: goto P_0c07bbe2;
case 0x0c07bbe4u: goto P_0c07bbe4;
case 0x0c07bbe6u: goto P_0c07bbe6;
case 0x0c07bbe8u: goto P_0c07bbe8;
case 0x0c07bbeau: goto P_0c07bbea;
case 0x0c07bbecu: goto P_0c07bbec;
case 0x0c07bbeeu: goto P_0c07bbee;
case 0x0c07bbf0u: goto P_0c07bbf0;
case 0x0c07bbf2u: goto P_0c07bbf2;
case 0x0c07bbf4u: goto P_0c07bbf4;
case 0x0c07bbf6u: goto P_0c07bbf6;
case 0x0c07bbf8u: goto P_0c07bbf8;
case 0x0c07bbfau: goto P_0c07bbfa;
case 0x0c07bbfcu: goto P_0c07bbfc;
case 0x0c07bbfeu: goto P_0c07bbfe;
case 0x0c07bc00u: goto P_0c07bc00;
case 0x0c07bc02u: goto P_0c07bc02;
case 0x0c07bc04u: goto P_0c07bc04;
case 0x0c07bc06u: goto P_0c07bc06;
case 0x0c07bc08u: goto P_0c07bc08;
case 0x0c07bc0au: goto P_0c07bc0a;
case 0x0c07bc0cu: goto P_0c07bc0c;
case 0x0c07bc0eu: goto P_0c07bc0e;
case 0x0c07bc10u: goto P_0c07bc10;
case 0x0c07bc12u: goto P_0c07bc12;
case 0x0c07bc14u: goto P_0c07bc14;
case 0x0c07bc16u: goto P_0c07bc16;
case 0x0c07bc18u: goto P_0c07bc18;
case 0x0c07bc1au: goto P_0c07bc1a;
case 0x0c07bc1cu: goto P_0c07bc1c;
case 0x0c07bc1eu: goto P_0c07bc1e;
case 0x0c07bc20u: goto P_0c07bc20;
case 0x0c07bc22u: goto P_0c07bc22;
case 0x0c07bc24u: goto P_0c07bc24;
case 0x0c07bc26u: goto P_0c07bc26;
case 0x0c07bc28u: goto P_0c07bc28;
case 0x0c07bc2au: goto P_0c07bc2a;
case 0x0c07bc2cu: goto P_0c07bc2c;
case 0x0c07bc2eu: goto P_0c07bc2e;
case 0x0c07bc30u: goto P_0c07bc30;
case 0x0c07bc32u: goto P_0c07bc32;
case 0x0c07bc34u: goto P_0c07bc34;
case 0x0c07bc36u: goto P_0c07bc36;
case 0x0c07bc38u: goto P_0c07bc38;
case 0x0c07bc3au: goto P_0c07bc3a;
case 0x0c07bc3cu: goto P_0c07bc3c;
case 0x0c07bc3eu: goto P_0c07bc3e;
case 0x0c07bc40u: goto P_0c07bc40;
case 0x0c07bc42u: goto P_0c07bc42;
case 0x0c07bc44u: goto P_0c07bc44;
case 0x0c07bc46u: goto P_0c07bc46;
case 0x0c07bc48u: goto P_0c07bc48;
case 0x0c07bc4au: goto P_0c07bc4a;
case 0x0c07bc4cu: goto P_0c07bc4c;
case 0x0c07bc4eu: goto P_0c07bc4e;
case 0x0c07bc50u: goto P_0c07bc50;
case 0x0c07bc52u: goto P_0c07bc52;
case 0x0c07bc54u: goto P_0c07bc54;
case 0x0c07bc56u: goto P_0c07bc56;
case 0x0c07bc58u: goto P_0c07bc58;
case 0x0c07bc5au: goto P_0c07bc5a;
case 0x0c07bc5cu: goto P_0c07bc5c;
case 0x0c07bc5eu: goto P_0c07bc5e;
case 0x0c07bc60u: goto P_0c07bc60;
case 0x0c07bc62u: goto P_0c07bc62;
case 0x0c07bc64u: goto P_0c07bc64;
case 0x0c07bc66u: goto P_0c07bc66;
case 0x0c07bc68u: goto P_0c07bc68;
case 0x0c07bc6au: goto P_0c07bc6a;
case 0x0c07bc6cu: goto P_0c07bc6c;
case 0x0c07bc6eu: goto P_0c07bc6e;
case 0x0c07bc70u: goto P_0c07bc70;
case 0x0c07bc72u: goto P_0c07bc72;
case 0x0c07bc74u: goto P_0c07bc74;
case 0x0c07bc76u: goto P_0c07bc76;
case 0x0c07bc78u: goto P_0c07bc78;
case 0x0c07bc7au: goto P_0c07bc7a;
case 0x0c07bc7cu: goto P_0c07bc7c;
case 0x0c07bc7eu: goto P_0c07bc7e;
case 0x0c07bc80u: goto P_0c07bc80;
case 0x0c07bc82u: goto P_0c07bc82;
case 0x0c07bc84u: goto P_0c07bc84;
case 0x0c07bc86u: goto P_0c07bc86;
case 0x0c07bc88u: goto P_0c07bc88;
case 0x0c07bc8au: goto P_0c07bc8a;
case 0x0c07bc8cu: goto P_0c07bc8c;
case 0x0c07bc8eu: goto P_0c07bc8e;
case 0x0c07bc90u: goto P_0c07bc90;
case 0x0c07bc92u: goto P_0c07bc92;
case 0x0c07bc94u: goto P_0c07bc94;
case 0x0c07bc96u: goto P_0c07bc96;
case 0x0c07bc98u: goto P_0c07bc98;
case 0x0c07bc9au: goto P_0c07bc9a;
case 0x0c07bc9cu: goto P_0c07bc9c;
case 0x0c07bc9eu: goto P_0c07bc9e;
case 0x0c07bca0u: goto P_0c07bca0;
case 0x0c07bca2u: goto P_0c07bca2;
case 0x0c07bca4u: goto P_0c07bca4;
case 0x0c07bca6u: goto P_0c07bca6;
case 0x0c07bca8u: goto P_0c07bca8;
case 0x0c07bcaau: goto P_0c07bcaa;
case 0x0c07bcacu: goto P_0c07bcac;
case 0x0c07bcaeu: goto P_0c07bcae;
case 0x0c07bcb0u: goto P_0c07bcb0;
case 0x0c07bcb2u: goto P_0c07bcb2;
case 0x0c07bcb4u: goto P_0c07bcb4;
case 0x0c07bcb6u: goto P_0c07bcb6;
case 0x0c07bcb8u: goto P_0c07bcb8;
case 0x0c07bcbau: goto P_0c07bcba;
case 0x0c07bcbcu: goto P_0c07bcbc;
case 0x0c07bcbeu: goto P_0c07bcbe;
case 0x0c07bcc0u: goto P_0c07bcc0;
case 0x0c07bcc2u: goto P_0c07bcc2;
case 0x0c07bcc4u: goto P_0c07bcc4;
case 0x0c07bcc6u: goto P_0c07bcc6;
case 0x0c07bcc8u: goto P_0c07bcc8;
case 0x0c07bccau: goto P_0c07bcca;
case 0x0c07bcccu: goto P_0c07bccc;
case 0x0c07bcceu: goto P_0c07bcce;
case 0x0c07bcd0u: goto P_0c07bcd0;
case 0x0c07bcd2u: goto P_0c07bcd2;
case 0x0c07bcd4u: goto P_0c07bcd4;
case 0x0c07bcd6u: goto P_0c07bcd6;
case 0x0c07bcd8u: goto P_0c07bcd8;
case 0x0c07bcdau: goto P_0c07bcda;
case 0x0c07bcdcu: goto P_0c07bcdc;
case 0x0c07bcdeu: goto P_0c07bcde;
case 0x0c07bce0u: goto P_0c07bce0;
case 0x0c07bce2u: goto P_0c07bce2;
case 0x0c07bce4u: goto P_0c07bce4;
case 0x0c07bce6u: goto P_0c07bce6;
case 0x0c07bce8u: goto P_0c07bce8;
case 0x0c07bceau: goto P_0c07bcea;
case 0x0c07bcecu: goto P_0c07bcec;
case 0x0c07bceeu: goto P_0c07bcee;
case 0x0c07bcf0u: goto P_0c07bcf0;
case 0x0c07bcf2u: goto P_0c07bcf2;
case 0x0c07bcf4u: goto P_0c07bcf4;
case 0x0c07bcf6u: goto P_0c07bcf6;
case 0x0c07bcf8u: goto P_0c07bcf8;
case 0x0c07bd14u: goto P_0c07bd14;
case 0x0c07bd16u: goto P_0c07bd16;
case 0x0c07bd18u: goto P_0c07bd18;
case 0x0c07bd1au: goto P_0c07bd1a;
case 0x0c07bd1cu: goto P_0c07bd1c;
case 0x0c07bd1eu: goto P_0c07bd1e;
case 0x0c07bd20u: goto P_0c07bd20;
case 0x0c07bd22u: goto P_0c07bd22;
case 0x0c07bd24u: goto P_0c07bd24;
case 0x0c07bd26u: goto P_0c07bd26;
case 0x0c07bd28u: goto P_0c07bd28;
case 0x0c07bd2au: goto P_0c07bd2a;
case 0x0c07bd2cu: goto P_0c07bd2c;
case 0x0c07bd2eu: goto P_0c07bd2e;
case 0x0c07bd30u: goto P_0c07bd30;
case 0x0c07bd32u: goto P_0c07bd32;
case 0x0c07bd34u: goto P_0c07bd34;
case 0x0c07bd36u: goto P_0c07bd36;
case 0x0c07bd38u: goto P_0c07bd38;
case 0x0c07bd3au: goto P_0c07bd3a;
case 0x0c07bd3cu: goto P_0c07bd3c;
case 0x0c07bd3eu: goto P_0c07bd3e;
case 0x0c07bd40u: goto P_0c07bd40;
case 0x0c07bd42u: goto P_0c07bd42;
case 0x0c07bd44u: goto P_0c07bd44;
case 0x0c07bd46u: goto P_0c07bd46;
case 0x0c07bd48u: goto P_0c07bd48;
case 0x0c07bd4au: goto P_0c07bd4a;
case 0x0c07bd4cu: goto P_0c07bd4c;
case 0x0c07bd4eu: goto P_0c07bd4e;
case 0x0c07bd50u: goto P_0c07bd50;
case 0x0c07bd52u: goto P_0c07bd52;
case 0x0c07bd54u: goto P_0c07bd54;
case 0x0c07bd56u: goto P_0c07bd56;
case 0x0c07bd58u: goto P_0c07bd58;
case 0x0c07bd5au: goto P_0c07bd5a;
case 0x0c07bd5cu: goto P_0c07bd5c;
case 0x0c07bd5eu: goto P_0c07bd5e;
case 0x0c07bd60u: goto P_0c07bd60;
case 0x0c07bd62u: goto P_0c07bd62;
case 0x0c07bd64u: goto P_0c07bd64;
case 0x0c07bd66u: goto P_0c07bd66;
case 0x0c07bd68u: goto P_0c07bd68;
case 0x0c07bd6au: goto P_0c07bd6a;
case 0x0c07bd6cu: goto P_0c07bd6c;
case 0x0c07bd6eu: goto P_0c07bd6e;
case 0x0c07bd70u: goto P_0c07bd70;
case 0x0c07bd72u: goto P_0c07bd72;
case 0x0c07bd74u: goto P_0c07bd74;
case 0x0c07bd76u: goto P_0c07bd76;
case 0x0c07bd78u: goto P_0c07bd78;
case 0x0c07bd7au: goto P_0c07bd7a;
case 0x0c07bd7cu: goto P_0c07bd7c;
case 0x0c07bd7eu: goto P_0c07bd7e;
case 0x0c07bd80u: goto P_0c07bd80;
case 0x0c07bd82u: goto P_0c07bd82;
case 0x0c07bd84u: goto P_0c07bd84;
case 0x0c07bd86u: goto P_0c07bd86;
case 0x0c07bd88u: goto P_0c07bd88;
case 0x0c07bd8au: goto P_0c07bd8a;
case 0x0c07bd8cu: goto P_0c07bd8c;
case 0x0c07bd8eu: goto P_0c07bd8e;
case 0x0c07bd90u: goto P_0c07bd90;
case 0x0c07bd92u: goto P_0c07bd92;
case 0x0c07bd94u: goto P_0c07bd94;
case 0x0c07bd96u: goto P_0c07bd96;
case 0x0c07bd98u: goto P_0c07bd98;
case 0x0c07bd9au: goto P_0c07bd9a;
case 0x0c07bd9cu: goto P_0c07bd9c;
case 0x0c07bd9eu: goto P_0c07bd9e;
case 0x0c07bda0u: goto P_0c07bda0;
case 0x0c07bda2u: goto P_0c07bda2;
case 0x0c07bda4u: goto P_0c07bda4;
case 0x0c07bda6u: goto P_0c07bda6;
case 0x0c07bda8u: goto P_0c07bda8;
case 0x0c07bdaau: goto P_0c07bdaa;
case 0x0c07bdacu: goto P_0c07bdac;
case 0x0c07bdaeu: goto P_0c07bdae;
case 0x0c07bdb0u: goto P_0c07bdb0;
case 0x0c07bdb2u: goto P_0c07bdb2;
case 0x0c07bdb4u: goto P_0c07bdb4;
case 0x0c07bdb6u: goto P_0c07bdb6;
case 0x0c07bdb8u: goto P_0c07bdb8;
case 0x0c07bdbau: goto P_0c07bdba;
case 0x0c07bdbcu: goto P_0c07bdbc;
case 0x0c07bdbeu: goto P_0c07bdbe;
case 0x0c07bdc0u: goto P_0c07bdc0;
case 0x0c07bdc2u: goto P_0c07bdc2;
case 0x0c07bdc4u: goto P_0c07bdc4;
case 0x0c07bdc6u: goto P_0c07bdc6;
case 0x0c07bdc8u: goto P_0c07bdc8;
case 0x0c07bdcau: goto P_0c07bdca;
case 0x0c07bdccu: goto P_0c07bdcc;
case 0x0c07bdceu: goto P_0c07bdce;
case 0x0c07bdd0u: goto P_0c07bdd0;
case 0x0c07bdd2u: goto P_0c07bdd2;
case 0x0c07bdd4u: goto P_0c07bdd4;
case 0x0c07bdd6u: goto P_0c07bdd6;
case 0x0c07bdd8u: goto P_0c07bdd8;
case 0x0c07bddau: goto P_0c07bdda;
case 0x0c07bddcu: goto P_0c07bddc;
case 0x0c07bddeu: goto P_0c07bdde;
case 0x0c07bde0u: goto P_0c07bde0;
case 0x0c07bde2u: goto P_0c07bde2;
case 0x0c07bde4u: goto P_0c07bde4;
case 0x0c07bde6u: goto P_0c07bde6;
case 0x0c07bde8u: goto P_0c07bde8;
case 0x0c07bdeau: goto P_0c07bdea;
case 0x0c07bdecu: goto P_0c07bdec;
case 0x0c07bdeeu: goto P_0c07bdee;
case 0x0c07bdf0u: goto P_0c07bdf0;
case 0x0c07bdf2u: goto P_0c07bdf2;
case 0x0c07bdf4u: goto P_0c07bdf4;
case 0x0c07bdf6u: goto P_0c07bdf6;
case 0x0c07bdf8u: goto P_0c07bdf8;
case 0x0c07bdfau: goto P_0c07bdfa;
case 0x0c07bdfcu: goto P_0c07bdfc;
case 0x0c07bdfeu: goto P_0c07bdfe;
case 0x0c07be00u: goto P_0c07be00;
case 0x0c07be02u: goto P_0c07be02;
case 0x0c07be04u: goto P_0c07be04;
case 0x0c07be06u: goto P_0c07be06;
case 0x0c07be08u: goto P_0c07be08;
case 0x0c07be0au: goto P_0c07be0a;
case 0x0c07be0cu: goto P_0c07be0c;
case 0x0c07be0eu: goto P_0c07be0e;
case 0x0c07be10u: goto P_0c07be10;
case 0x0c07be12u: goto P_0c07be12;
case 0x0c07be14u: goto P_0c07be14;
case 0x0c07be16u: goto P_0c07be16;
case 0x0c07be18u: goto P_0c07be18;
case 0x0c07be1au: goto P_0c07be1a;
case 0x0c07be1cu: goto P_0c07be1c;
case 0x0c07be1eu: goto P_0c07be1e;
case 0x0c07be20u: goto P_0c07be20;
case 0x0c07be22u: goto P_0c07be22;
case 0x0c07be24u: goto P_0c07be24;
case 0x0c07be26u: goto P_0c07be26;
case 0x0c07be28u: goto P_0c07be28;
case 0x0c07be2au: goto P_0c07be2a;
case 0x0c07be2cu: goto P_0c07be2c;
case 0x0c07be2eu: goto P_0c07be2e;
case 0x0c07be30u: goto P_0c07be30;
case 0x0c07be32u: goto P_0c07be32;
case 0x0c07be34u: goto P_0c07be34;
case 0x0c07be36u: goto P_0c07be36;
case 0x0c07be38u: goto P_0c07be38;
case 0x0c07be3au: goto P_0c07be3a;
case 0x0c07be3cu: goto P_0c07be3c;
case 0x0c07be3eu: goto P_0c07be3e;
case 0x0c07be40u: goto P_0c07be40;
case 0x0c07be42u: goto P_0c07be42;
case 0x0c07be44u: goto P_0c07be44;
case 0x0c07be46u: goto P_0c07be46;
case 0x0c07be48u: goto P_0c07be48;
case 0x0c07be4au: goto P_0c07be4a;
case 0x0c07be4cu: goto P_0c07be4c;
case 0x0c07be4eu: goto P_0c07be4e;
case 0x0c07be50u: goto P_0c07be50;
case 0x0c07be52u: goto P_0c07be52;
case 0x0c07be54u: goto P_0c07be54;
case 0x0c07be56u: goto P_0c07be56;
case 0x0c07be58u: goto P_0c07be58;
case 0x0c07be5au: goto P_0c07be5a;
case 0x0c07be5cu: goto P_0c07be5c;
case 0x0c07be5eu: goto P_0c07be5e;
case 0x0c07be60u: goto P_0c07be60;
case 0x0c07be62u: goto P_0c07be62;
case 0x0c07be64u: goto P_0c07be64;
case 0x0c07be66u: goto P_0c07be66;
case 0x0c07be68u: goto P_0c07be68;
case 0x0c07be6au: goto P_0c07be6a;
case 0x0c07be6cu: goto P_0c07be6c;
case 0x0c07be6eu: goto P_0c07be6e;
case 0x0c07be70u: goto P_0c07be70;
case 0x0c07be72u: goto P_0c07be72;
case 0x0c07be74u: goto P_0c07be74;
case 0x0c07be76u: goto P_0c07be76;
case 0x0c07be78u: goto P_0c07be78;
case 0x0c07be7au: goto P_0c07be7a;
case 0x0c07be7cu: goto P_0c07be7c;
case 0x0c07be7eu: goto P_0c07be7e;
case 0x0c07be80u: goto P_0c07be80;
case 0x0c07be82u: goto P_0c07be82;
case 0x0c07be84u: goto P_0c07be84;
case 0x0c07be86u: goto P_0c07be86;
case 0x0c07be88u: goto P_0c07be88;
case 0x0c07be8au: goto P_0c07be8a;
case 0x0c07be8cu: goto P_0c07be8c;
case 0x0c07be8eu: goto P_0c07be8e;
case 0x0c07be90u: goto P_0c07be90;
case 0x0c07be92u: goto P_0c07be92;
case 0x0c07be94u: goto P_0c07be94;
case 0x0c07be96u: goto P_0c07be96;
case 0x0c07be98u: goto P_0c07be98;
case 0x0c07be9au: goto P_0c07be9a;
case 0x0c07beb0u: goto P_0c07beb0;
case 0x0c07beb2u: goto P_0c07beb2;
case 0x0c07beb4u: goto P_0c07beb4;
case 0x0c07beb6u: goto P_0c07beb6;
case 0x0c07beb8u: goto P_0c07beb8;
case 0x0c07bebau: goto P_0c07beba;
case 0x0c07bebcu: goto P_0c07bebc;
case 0x0c07bebeu: goto P_0c07bebe;
case 0x0c07bec0u: goto P_0c07bec0;
case 0x0c07bec2u: goto P_0c07bec2;
case 0x0c07bec4u: goto P_0c07bec4;
case 0x0c07bec6u: goto P_0c07bec6;
case 0x0c07bec8u: goto P_0c07bec8;
case 0x0c07becau: goto P_0c07beca;
case 0x0c07beccu: goto P_0c07becc;
case 0x0c07beceu: goto P_0c07bece;
case 0x0c07bed0u: goto P_0c07bed0;
case 0x0c07bed2u: goto P_0c07bed2;
case 0x0c07bed4u: goto P_0c07bed4;
case 0x0c07bed6u: goto P_0c07bed6;
case 0x0c07bed8u: goto P_0c07bed8;
case 0x0c07bedau: goto P_0c07beda;
case 0x0c07bedcu: goto P_0c07bedc;
case 0x0c07bedeu: goto P_0c07bede;
case 0x0c07bee0u: goto P_0c07bee0;
case 0x0c07bee2u: goto P_0c07bee2;
case 0x0c07bee4u: goto P_0c07bee4;
case 0x0c07bee6u: goto P_0c07bee6;
case 0x0c07bee8u: goto P_0c07bee8;
case 0x0c07beeau: goto P_0c07beea;
case 0x0c07beecu: goto P_0c07beec;
case 0x0c07beeeu: goto P_0c07beee;
case 0x0c07bef0u: goto P_0c07bef0;
case 0x0c07bef2u: goto P_0c07bef2;
case 0x0c07bef4u: goto P_0c07bef4;
case 0x0c07bef6u: goto P_0c07bef6;
case 0x0c07bef8u: goto P_0c07bef8;
case 0x0c07befau: goto P_0c07befa;
case 0x0c07befcu: goto P_0c07befc;
case 0x0c07befeu: goto P_0c07befe;
case 0x0c07bf00u: goto P_0c07bf00;
case 0x0c07bf02u: goto P_0c07bf02;
case 0x0c07bf04u: goto P_0c07bf04;
case 0x0c07bf06u: goto P_0c07bf06;
case 0x0c07bf08u: goto P_0c07bf08;
case 0x0c07bf0au: goto P_0c07bf0a;
case 0x0c07bf0cu: goto P_0c07bf0c;
case 0x0c07bf0eu: goto P_0c07bf0e;
case 0x0c07bf10u: goto P_0c07bf10;
case 0x0c07bf12u: goto P_0c07bf12;
case 0x0c07bf14u: goto P_0c07bf14;
case 0x0c07bf16u: goto P_0c07bf16;
case 0x0c07bf18u: goto P_0c07bf18;
case 0x0c07bf1au: goto P_0c07bf1a;
case 0x0c07bf1cu: goto P_0c07bf1c;
case 0x0c07bf1eu: goto P_0c07bf1e;
case 0x0c07bf20u: goto P_0c07bf20;
case 0x0c07bf22u: goto P_0c07bf22;
case 0x0c07bf24u: goto P_0c07bf24;
case 0x0c07bf26u: goto P_0c07bf26;
case 0x0c07bf28u: goto P_0c07bf28;
case 0x0c07bf2au: goto P_0c07bf2a;
case 0x0c07bf2cu: goto P_0c07bf2c;
case 0x0c07bf2eu: goto P_0c07bf2e;
case 0x0c07bf30u: goto P_0c07bf30;
case 0x0c07bf32u: goto P_0c07bf32;
case 0x0c07bf34u: goto P_0c07bf34;
case 0x0c07bf36u: goto P_0c07bf36;
case 0x0c07bf38u: goto P_0c07bf38;
case 0x0c07bf3au: goto P_0c07bf3a;
case 0x0c07bf3cu: goto P_0c07bf3c;
case 0x0c07bf3eu: goto P_0c07bf3e;
case 0x0c07bf40u: goto P_0c07bf40;
case 0x0c07bf42u: goto P_0c07bf42;
case 0x0c07bf44u: goto P_0c07bf44;
case 0x0c07bf46u: goto P_0c07bf46;
case 0x0c07bf48u: goto P_0c07bf48;
case 0x0c07bf4au: goto P_0c07bf4a;
case 0x0c07bf4cu: goto P_0c07bf4c;
case 0x0c07bf4eu: goto P_0c07bf4e;
case 0x0c07bf50u: goto P_0c07bf50;
case 0x0c07bf52u: goto P_0c07bf52;
case 0x0c07bf54u: goto P_0c07bf54;
case 0x0c07bf56u: goto P_0c07bf56;
case 0x0c07bf58u: goto P_0c07bf58;
case 0x0c07bf5au: goto P_0c07bf5a;
case 0x0c07bf5cu: goto P_0c07bf5c;
case 0x0c07bf5eu: goto P_0c07bf5e;
case 0x0c07bf60u: goto P_0c07bf60;
case 0x0c07bf62u: goto P_0c07bf62;
case 0x0c07bf64u: goto P_0c07bf64;
case 0x0c07bf66u: goto P_0c07bf66;
case 0x0c07bf68u: goto P_0c07bf68;
case 0x0c07bf6au: goto P_0c07bf6a;
case 0x0c07bf6cu: goto P_0c07bf6c;
case 0x0c07bf6eu: goto P_0c07bf6e;
case 0x0c07bf70u: goto P_0c07bf70;
case 0x0c07bf72u: goto P_0c07bf72;
case 0x0c07bf74u: goto P_0c07bf74;
case 0x0c07bf76u: goto P_0c07bf76;
case 0x0c07bf78u: goto P_0c07bf78;
case 0x0c07bf7au: goto P_0c07bf7a;
case 0x0c07bf7cu: goto P_0c07bf7c;
case 0x0c07bf7eu: goto P_0c07bf7e;
case 0x0c07bf80u: goto P_0c07bf80;
case 0x0c07bf82u: goto P_0c07bf82;
case 0x0c07bf84u: goto P_0c07bf84;
case 0x0c07bf86u: goto P_0c07bf86;
case 0x0c07bf88u: goto P_0c07bf88;
case 0x0c07bf8au: goto P_0c07bf8a;
case 0x0c07bf8cu: goto P_0c07bf8c;
case 0x0c07bf8eu: goto P_0c07bf8e;
case 0x0c07bf90u: goto P_0c07bf90;
case 0x0c07bf92u: goto P_0c07bf92;
case 0x0c07bf94u: goto P_0c07bf94;
case 0x0c07bf96u: goto P_0c07bf96;
case 0x0c07bf98u: goto P_0c07bf98;
case 0x0c07bf9au: goto P_0c07bf9a;
case 0x0c07bf9cu: goto P_0c07bf9c;
case 0x0c07bf9eu: goto P_0c07bf9e;
case 0x0c07bfa0u: goto P_0c07bfa0;
case 0x0c07bfa2u: goto P_0c07bfa2;
case 0x0c07bfa4u: goto P_0c07bfa4;
case 0x0c07bfa6u: goto P_0c07bfa6;
case 0x0c07bfa8u: goto P_0c07bfa8;
case 0x0c07bfaau: goto P_0c07bfaa;
case 0x0c07bfacu: goto P_0c07bfac;
case 0x0c07bfaeu: goto P_0c07bfae;
case 0x0c07bfb0u: goto P_0c07bfb0;
case 0x0c07bfb2u: goto P_0c07bfb2;
case 0x0c07bfb4u: goto P_0c07bfb4;
case 0x0c07bfb6u: goto P_0c07bfb6;
case 0x0c07bfb8u: goto P_0c07bfb8;
case 0x0c07bfbau: goto P_0c07bfba;
case 0x0c07bfbcu: goto P_0c07bfbc;
case 0x0c07bfbeu: goto P_0c07bfbe;
case 0x0c07bfc0u: goto P_0c07bfc0;
case 0x0c07bfc2u: goto P_0c07bfc2;
case 0x0c07bfc4u: goto P_0c07bfc4;
case 0x0c07bfc6u: goto P_0c07bfc6;
case 0x0c07bfc8u: goto P_0c07bfc8;
case 0x0c07bfcau: goto P_0c07bfca;
case 0x0c07bfccu: goto P_0c07bfcc;
case 0x0c07bfceu: goto P_0c07bfce;
case 0x0c07bfd0u: goto P_0c07bfd0;
case 0x0c07bfd2u: goto P_0c07bfd2;
case 0x0c07bfd4u: goto P_0c07bfd4;
case 0x0c07bfd6u: goto P_0c07bfd6;
case 0x0c07bfd8u: goto P_0c07bfd8;
case 0x0c07bfdau: goto P_0c07bfda;
case 0x0c07bfdcu: goto P_0c07bfdc;
case 0x0c07bfdeu: goto P_0c07bfde;
case 0x0c07bfe0u: goto P_0c07bfe0;
case 0x0c07bfe2u: goto P_0c07bfe2;
case 0x0c07bfe4u: goto P_0c07bfe4;
case 0x0c07bfe6u: goto P_0c07bfe6;
case 0x0c07bfe8u: goto P_0c07bfe8;
case 0x0c07bfeau: goto P_0c07bfea;
case 0x0c07bfecu: goto P_0c07bfec;
case 0x0c07bfeeu: goto P_0c07bfee;
case 0x0c07bff0u: goto P_0c07bff0;
case 0x0c07bff2u: goto P_0c07bff2;
case 0x0c07bff4u: goto P_0c07bff4;
case 0x0c07bff6u: goto P_0c07bff6;
case 0x0c07bff8u: goto P_0c07bff8;
case 0x0c07bffau: goto P_0c07bffa;
case 0x0c07bffcu: goto P_0c07bffc;
case 0x0c07bffeu: goto P_0c07bffe;
case 0x0c07c000u: goto P_0c07c000;
case 0x0c07c002u: goto P_0c07c002;
case 0x0c07c004u: goto P_0c07c004;
case 0x0c07c006u: goto P_0c07c006;
case 0x0c07c008u: goto P_0c07c008;
case 0x0c07c00au: goto P_0c07c00a;
case 0x0c07c00cu: goto P_0c07c00c;
case 0x0c07c00eu: goto P_0c07c00e;
case 0x0c07c010u: goto P_0c07c010;
case 0x0c07c012u: goto P_0c07c012;
case 0x0c07c014u: goto P_0c07c014;
case 0x0c07c016u: goto P_0c07c016;
case 0x0c07c018u: goto P_0c07c018;
case 0x0c07c01au: goto P_0c07c01a;
case 0x0c07c01cu: goto P_0c07c01c;
case 0x0c07c01eu: goto P_0c07c01e;
case 0x0c07c020u: goto P_0c07c020;
case 0x0c07c022u: goto P_0c07c022;
case 0x0c07c024u: goto P_0c07c024;
case 0x0c07c026u: goto P_0c07c026;
case 0x0c07c028u: goto P_0c07c028;
case 0x0c07c02au: goto P_0c07c02a;
case 0x0c07c02cu: goto P_0c07c02c;
case 0x0c07c02eu: goto P_0c07c02e;
case 0x0c07c030u: goto P_0c07c030;
case 0x0c07c032u: goto P_0c07c032;
case 0x0c07c034u: goto P_0c07c034;
case 0x0c07c036u: goto P_0c07c036;
case 0x0c07c038u: goto P_0c07c038;
case 0x0c07c03au: goto P_0c07c03a;
case 0x0c07c03cu: goto P_0c07c03c;
case 0x0c07c03eu: goto P_0c07c03e;
case 0x0c07c040u: goto P_0c07c040;
case 0x0c07c042u: goto P_0c07c042;
case 0x0c07c05cu: goto P_0c07c05c;
case 0x0c07c05eu: goto P_0c07c05e;
case 0x0c07c060u: goto P_0c07c060;
case 0x0c07c062u: goto P_0c07c062;
case 0x0c07c064u: goto P_0c07c064;
case 0x0c07c066u: goto P_0c07c066;
case 0x0c07c068u: goto P_0c07c068;
case 0x0c07c06au: goto P_0c07c06a;
case 0x0c07c06cu: goto P_0c07c06c;
case 0x0c07c06eu: goto P_0c07c06e;
case 0x0c07c070u: goto P_0c07c070;
case 0x0c07c072u: goto P_0c07c072;
case 0x0c07c074u: goto P_0c07c074;
case 0x0c07c076u: goto P_0c07c076;
case 0x0c07c078u: goto P_0c07c078;
case 0x0c07c07au: goto P_0c07c07a;
case 0x0c07c07cu: goto P_0c07c07c;
case 0x0c07c07eu: goto P_0c07c07e;
case 0x0c07c080u: goto P_0c07c080;
case 0x0c07c082u: goto P_0c07c082;
case 0x0c07c084u: goto P_0c07c084;
case 0x0c07c086u: goto P_0c07c086;
case 0x0c07c088u: goto P_0c07c088;
case 0x0c07c08au: goto P_0c07c08a;
case 0x0c07c08cu: goto P_0c07c08c;
case 0x0c07c08eu: goto P_0c07c08e;
case 0x0c07c090u: goto P_0c07c090;
case 0x0c07c092u: goto P_0c07c092;
case 0x0c07c094u: goto P_0c07c094;
case 0x0c07c096u: goto P_0c07c096;
case 0x0c07c098u: goto P_0c07c098;
case 0x0c07c09au: goto P_0c07c09a;
case 0x0c07c09cu: goto P_0c07c09c;
case 0x0c07c09eu: goto P_0c07c09e;
case 0x0c07c0a0u: goto P_0c07c0a0;
case 0x0c07c0a2u: goto P_0c07c0a2;
case 0x0c07c0a4u: goto P_0c07c0a4;
case 0x0c07c0a6u: goto P_0c07c0a6;
case 0x0c07c0a8u: goto P_0c07c0a8;
case 0x0c07c0aau: goto P_0c07c0aa;
case 0x0c07c0acu: goto P_0c07c0ac;
case 0x0c07c0aeu: goto P_0c07c0ae;
case 0x0c07c0b0u: goto P_0c07c0b0;
case 0x0c07c0b2u: goto P_0c07c0b2;
case 0x0c07c0b4u: goto P_0c07c0b4;
case 0x0c07c0b6u: goto P_0c07c0b6;
case 0x0c07c0b8u: goto P_0c07c0b8;
case 0x0c07c0bau: goto P_0c07c0ba;
case 0x0c07c0bcu: goto P_0c07c0bc;
case 0x0c07c0beu: goto P_0c07c0be;
case 0x0c07c0c0u: goto P_0c07c0c0;
case 0x0c07c0c2u: goto P_0c07c0c2;
case 0x0c07c0c4u: goto P_0c07c0c4;
case 0x0c07c0c6u: goto P_0c07c0c6;
case 0x0c07c0c8u: goto P_0c07c0c8;
case 0x0c07c0cau: goto P_0c07c0ca;
case 0x0c07c0ccu: goto P_0c07c0cc;
case 0x0c07c0ceu: goto P_0c07c0ce;
case 0x0c07c0d0u: goto P_0c07c0d0;
case 0x0c07c0d2u: goto P_0c07c0d2;
case 0x0c07c0d4u: goto P_0c07c0d4;
case 0x0c07c0d6u: goto P_0c07c0d6;
case 0x0c07c0d8u: goto P_0c07c0d8;
case 0x0c07c0dau: goto P_0c07c0da;
case 0x0c07c0dcu: goto P_0c07c0dc;
case 0x0c07c0deu: goto P_0c07c0de;
case 0x0c07c0e0u: goto P_0c07c0e0;
case 0x0c07c0e2u: goto P_0c07c0e2;
case 0x0c07c0e4u: goto P_0c07c0e4;
case 0x0c07c0e6u: goto P_0c07c0e6;
case 0x0c07c0e8u: goto P_0c07c0e8;
case 0x0c07c0eau: goto P_0c07c0ea;
case 0x0c07c0ecu: goto P_0c07c0ec;
case 0x0c07c0eeu: goto P_0c07c0ee;
case 0x0c07c0f0u: goto P_0c07c0f0;
case 0x0c07c0f2u: goto P_0c07c0f2;
case 0x0c07c0f4u: goto P_0c07c0f4;
case 0x0c07c0f6u: goto P_0c07c0f6;
case 0x0c07c0f8u: goto P_0c07c0f8;
case 0x0c07c0fau: goto P_0c07c0fa;
case 0x0c07c0fcu: goto P_0c07c0fc;
case 0x0c07c0feu: goto P_0c07c0fe;
case 0x0c07c100u: goto P_0c07c100;
case 0x0c07c102u: goto P_0c07c102;
case 0x0c07c12cu: goto P_0c07c12c;
case 0x0c07c12eu: goto P_0c07c12e;
case 0x0c07c130u: goto P_0c07c130;
case 0x0c07c132u: goto P_0c07c132;
case 0x0c07c134u: goto P_0c07c134;
case 0x0c07c136u: goto P_0c07c136;
case 0x0c07c138u: goto P_0c07c138;
case 0x0c07c13au: goto P_0c07c13a;
case 0x0c07c13cu: goto P_0c07c13c;
case 0x0c07c13eu: goto P_0c07c13e;
case 0x0c07c140u: goto P_0c07c140;
case 0x0c07c142u: goto P_0c07c142;
case 0x0c07c144u: goto P_0c07c144;
case 0x0c07c146u: goto P_0c07c146;
case 0x0c07c148u: goto P_0c07c148;
case 0x0c07c14au: goto P_0c07c14a;
case 0x0c07c14cu: goto P_0c07c14c;
case 0x0c07c14eu: goto P_0c07c14e;
case 0x0c07c150u: goto P_0c07c150;
case 0x0c07c152u: goto P_0c07c152;
case 0x0c07c154u: goto P_0c07c154;
case 0x0c07c156u: goto P_0c07c156;
case 0x0c07c158u: goto P_0c07c158;
case 0x0c07c15au: goto P_0c07c15a;
case 0x0c07c15cu: goto P_0c07c15c;
case 0x0c07c15eu: goto P_0c07c15e;
case 0x0c07c160u: goto P_0c07c160;
case 0x0c07c162u: goto P_0c07c162;
case 0x0c07c164u: goto P_0c07c164;
case 0x0c07c166u: goto P_0c07c166;
case 0x0c07c168u: goto P_0c07c168;
case 0x0c07c16au: goto P_0c07c16a;
case 0x0c07c16cu: goto P_0c07c16c;
case 0x0c07c16eu: goto P_0c07c16e;
case 0x0c07c170u: goto P_0c07c170;
case 0x0c07c172u: goto P_0c07c172;
case 0x0c07c174u: goto P_0c07c174;
case 0x0c07c176u: goto P_0c07c176;
case 0x0c07c178u: goto P_0c07c178;
case 0x0c07c17au: goto P_0c07c17a;
case 0x0c07c17cu: goto P_0c07c17c;
case 0x0c07c17eu: goto P_0c07c17e;
case 0x0c07c180u: goto P_0c07c180;
case 0x0c07c182u: goto P_0c07c182;
case 0x0c07c184u: goto P_0c07c184;
case 0x0c07c186u: goto P_0c07c186;
case 0x0c07c188u: goto P_0c07c188;
case 0x0c07c18au: goto P_0c07c18a;
case 0x0c07c18cu: goto P_0c07c18c;
case 0x0c07c18eu: goto P_0c07c18e;
case 0x0c07c190u: goto P_0c07c190;
case 0x0c07c192u: goto P_0c07c192;
case 0x0c07c194u: goto P_0c07c194;
case 0x0c07c196u: goto P_0c07c196;
case 0x0c07c198u: goto P_0c07c198;
case 0x0c07c19au: goto P_0c07c19a;
case 0x0c07c19cu: goto P_0c07c19c;
case 0x0c07c19eu: goto P_0c07c19e;
case 0x0c07c1a0u: goto P_0c07c1a0;
case 0x0c07c1a2u: goto P_0c07c1a2;
case 0x0c07c1a4u: goto P_0c07c1a4;
case 0x0c07c1a6u: goto P_0c07c1a6;
case 0x0c07c1a8u: goto P_0c07c1a8;
case 0x0c07c1aau: goto P_0c07c1aa;
case 0x0c07c1acu: goto P_0c07c1ac;
case 0x0c07c1aeu: goto P_0c07c1ae;
case 0x0c07c1b0u: goto P_0c07c1b0;
case 0x0c07c1b2u: goto P_0c07c1b2;
case 0x0c07c1b4u: goto P_0c07c1b4;
case 0x0c07c1b6u: goto P_0c07c1b6;
case 0x0c07c1b8u: goto P_0c07c1b8;
case 0x0c07c1bau: goto P_0c07c1ba;
case 0x0c07c1bcu: goto P_0c07c1bc;
case 0x0c07c1beu: goto P_0c07c1be;
case 0x0c07c1c0u: goto P_0c07c1c0;
case 0x0c07c1c2u: goto P_0c07c1c2;
case 0x0c07c1c4u: goto P_0c07c1c4;
case 0x0c07c1c6u: goto P_0c07c1c6;
case 0x0c07c1c8u: goto P_0c07c1c8;
case 0x0c07c1cau: goto P_0c07c1ca;
case 0x0c07c1ccu: goto P_0c07c1cc;
case 0x0c07c1ceu: goto P_0c07c1ce;
case 0x0c07c1d0u: goto P_0c07c1d0;
case 0x0c07c1d2u: goto P_0c07c1d2;
case 0x0c07c1d4u: goto P_0c07c1d4;
case 0x0c07c1d6u: goto P_0c07c1d6;
case 0x0c07c1d8u: goto P_0c07c1d8;
case 0x0c07c1dau: goto P_0c07c1da;
case 0x0c07c1dcu: goto P_0c07c1dc;
case 0x0c07c1deu: goto P_0c07c1de;
case 0x0c07c1e0u: goto P_0c07c1e0;
case 0x0c07c1e2u: goto P_0c07c1e2;
case 0x0c07c1e4u: goto P_0c07c1e4;
case 0x0c07c1e6u: goto P_0c07c1e6;
case 0x0c07c1e8u: goto P_0c07c1e8;
case 0x0c07c1eau: goto P_0c07c1ea;
case 0x0c07c1ecu: goto P_0c07c1ec;
case 0x0c07c1eeu: goto P_0c07c1ee;
case 0x0c07c1f0u: goto P_0c07c1f0;
case 0x0c07c1f2u: goto P_0c07c1f2;
case 0x0c07c1f4u: goto P_0c07c1f4;
case 0x0c07c1f6u: goto P_0c07c1f6;
case 0x0c07c1f8u: goto P_0c07c1f8;
case 0x0c07c1fau: goto P_0c07c1fa;
case 0x0c07c1fcu: goto P_0c07c1fc;
case 0x0c07c1feu: goto P_0c07c1fe;
case 0x0c07c200u: goto P_0c07c200;
case 0x0c07c202u: goto P_0c07c202;
case 0x0c07c204u: goto P_0c07c204;
case 0x0c07c206u: goto P_0c07c206;
case 0x0c07c208u: goto P_0c07c208;
case 0x0c07c20au: goto P_0c07c20a;
case 0x0c07c20cu: goto P_0c07c20c;
case 0x0c07c20eu: goto P_0c07c20e;
case 0x0c07c210u: goto P_0c07c210;
case 0x0c07c212u: goto P_0c07c212;
case 0x0c07c214u: goto P_0c07c214;
case 0x0c07c216u: goto P_0c07c216;
case 0x0c07c218u: goto P_0c07c218;
case 0x0c07c21au: goto P_0c07c21a;
case 0x0c07c21cu: goto P_0c07c21c;
case 0x0c07c21eu: goto P_0c07c21e;
case 0x0c07c220u: goto P_0c07c220;
case 0x0c07c222u: goto P_0c07c222;
case 0x0c07c224u: goto P_0c07c224;
case 0x0c07c226u: goto P_0c07c226;
case 0x0c07c228u: goto P_0c07c228;
case 0x0c07c22au: goto P_0c07c22a;
case 0x0c07c22cu: goto P_0c07c22c;
case 0x0c07c22eu: goto P_0c07c22e;
case 0x0c07c230u: goto P_0c07c230;
case 0x0c07c232u: goto P_0c07c232;
case 0x0c07c234u: goto P_0c07c234;
case 0x0c07c236u: goto P_0c07c236;
case 0x0c07c238u: goto P_0c07c238;
case 0x0c07c23au: goto P_0c07c23a;
case 0x0c07c23cu: goto P_0c07c23c;
case 0x0c07c23eu: goto P_0c07c23e;
case 0x0c07c240u: goto P_0c07c240;
case 0x0c07c242u: goto P_0c07c242;
case 0x0c07c244u: goto P_0c07c244;
case 0x0c07c246u: goto P_0c07c246;
case 0x0c07c248u: goto P_0c07c248;
case 0x0c07c24au: goto P_0c07c24a;
case 0x0c07c24cu: goto P_0c07c24c;
case 0x0c07c24eu: goto P_0c07c24e;
case 0x0c07c250u: goto P_0c07c250;
case 0x0c07c252u: goto P_0c07c252;
case 0x0c07c254u: goto P_0c07c254;
case 0x0c07c256u: goto P_0c07c256;
case 0x0c07c258u: goto P_0c07c258;
case 0x0c07c25au: goto P_0c07c25a;
case 0x0c07c25cu: goto P_0c07c25c;
case 0x0c07c25eu: goto P_0c07c25e;
case 0x0c07c260u: goto P_0c07c260;
case 0x0c07c262u: goto P_0c07c262;
case 0x0c07c264u: goto P_0c07c264;
case 0x0c07c266u: goto P_0c07c266;
case 0x0c07c268u: goto P_0c07c268;
case 0x0c07c26au: goto P_0c07c26a;
case 0x0c07c26cu: goto P_0c07c26c;
case 0x0c07c26eu: goto P_0c07c26e;
case 0x0c07c270u: goto P_0c07c270;
case 0x0c07c272u: goto P_0c07c272;
case 0x0c07c274u: goto P_0c07c274;
case 0x0c07c276u: goto P_0c07c276;
case 0x0c07c278u: goto P_0c07c278;
case 0x0c07c27au: goto P_0c07c27a;
case 0x0c07c27cu: goto P_0c07c27c;
case 0x0c07c27eu: goto P_0c07c27e;
case 0x0c07c280u: goto P_0c07c280;
case 0x0c07c282u: goto P_0c07c282;
case 0x0c07c284u: goto P_0c07c284;
case 0x0c07c286u: goto P_0c07c286;
case 0x0c07c288u: goto P_0c07c288;
case 0x0c07c28au: goto P_0c07c28a;
case 0x0c07c28cu: goto P_0c07c28c;
case 0x0c07c28eu: goto P_0c07c28e;
case 0x0c07c290u: goto P_0c07c290;
case 0x0c07c292u: goto P_0c07c292;
case 0x0c07c294u: goto P_0c07c294;
case 0x0c07c296u: goto P_0c07c296;
case 0x0c07c298u: goto P_0c07c298;
case 0x0c07c29au: goto P_0c07c29a;
case 0x0c07c29cu: goto P_0c07c29c;
case 0x0c07c29eu: goto P_0c07c29e;
case 0x0c07c2a0u: goto P_0c07c2a0;
case 0x0c07c2a2u: goto P_0c07c2a2;
case 0x0c07c2a4u: goto P_0c07c2a4;
case 0x0c07c2a6u: goto P_0c07c2a6;
case 0x0c07c2a8u: goto P_0c07c2a8;
case 0x0c07c2aau: goto P_0c07c2aa;
case 0x0c07c2acu: goto P_0c07c2ac;
case 0x0c07c2aeu: goto P_0c07c2ae;
case 0x0c07c2b0u: goto P_0c07c2b0;
case 0x0c07c2b2u: goto P_0c07c2b2;
case 0x0c07c2b4u: goto P_0c07c2b4;
case 0x0c07c2d0u: goto P_0c07c2d0;
case 0x0c07c2d2u: goto P_0c07c2d2;
case 0x0c07c2d4u: goto P_0c07c2d4;
case 0x0c07c2d6u: goto P_0c07c2d6;
case 0x0c07c2d8u: goto P_0c07c2d8;
case 0x0c07c2dau: goto P_0c07c2da;
case 0x0c07c2dcu: goto P_0c07c2dc;
case 0x0c07c2deu: goto P_0c07c2de;
case 0x0c07c2e0u: goto P_0c07c2e0;
case 0x0c07c2e2u: goto P_0c07c2e2;
case 0x0c07c2e4u: goto P_0c07c2e4;
case 0x0c07c2e6u: goto P_0c07c2e6;
case 0x0c07c2e8u: goto P_0c07c2e8;
case 0x0c07c2eau: goto P_0c07c2ea;
case 0x0c07c2ecu: goto P_0c07c2ec;
case 0x0c07c2eeu: goto P_0c07c2ee;
case 0x0c07c2f0u: goto P_0c07c2f0;
case 0x0c07c2f2u: goto P_0c07c2f2;
case 0x0c07c2f4u: goto P_0c07c2f4;
case 0x0c07c2f6u: goto P_0c07c2f6;
case 0x0c07c2f8u: goto P_0c07c2f8;
case 0x0c07c2fau: goto P_0c07c2fa;
case 0x0c07c2fcu: goto P_0c07c2fc;
case 0x0c07c2feu: goto P_0c07c2fe;
case 0x0c07c300u: goto P_0c07c300;
case 0x0c07c302u: goto P_0c07c302;
case 0x0c07c304u: goto P_0c07c304;
case 0x0c07c306u: goto P_0c07c306;
case 0x0c07c308u: goto P_0c07c308;
case 0x0c07c30au: goto P_0c07c30a;
case 0x0c07c30cu: goto P_0c07c30c;
case 0x0c07c30eu: goto P_0c07c30e;
case 0x0c07c310u: goto P_0c07c310;
case 0x0c07c312u: goto P_0c07c312;
case 0x0c07c314u: goto P_0c07c314;
case 0x0c07c316u: goto P_0c07c316;
case 0x0c07c318u: goto P_0c07c318;
case 0x0c07c31au: goto P_0c07c31a;
case 0x0c07c31cu: goto P_0c07c31c;
case 0x0c07c31eu: goto P_0c07c31e;
case 0x0c07c320u: goto P_0c07c320;
case 0x0c07c322u: goto P_0c07c322;
case 0x0c07c324u: goto P_0c07c324;
case 0x0c07c326u: goto P_0c07c326;
case 0x0c07c328u: goto P_0c07c328;
case 0x0c07c32au: goto P_0c07c32a;
case 0x0c07c32cu: goto P_0c07c32c;
case 0x0c07c32eu: goto P_0c07c32e;
case 0x0c07c330u: goto P_0c07c330;
case 0x0c07c332u: goto P_0c07c332;
default: return vf3_matrix_family(target,s,ram);
}
P_0c07b9a4: /* original 2fe6, guest PC 0x0c07b9a4 */
if(!s->budget--) { s->failed_pc=0x0c07b9a4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b9a6;
P_0c07b9a6: /* original 6e43, guest PC 0x0c07b9a6 */
if(!s->budget--) { s->failed_pc=0x0c07b9a6u; return 0; }
r[14]=r[4];
goto P_0c07b9a8;
P_0c07b9a8: /* original 2fd6, guest PC 0x0c07b9a8 */
if(!s->budget--) { s->failed_pc=0x0c07b9a8u; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b9aa;
P_0c07b9aa: /* original 2fc6, guest PC 0x0c07b9aa */
if(!s->budget--) { s->failed_pc=0x0c07b9aau; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07b9ac;
P_0c07b9ac: /* original 6c43, guest PC 0x0c07b9ac */
if(!s->budget--) { s->failed_pc=0x0c07b9acu; return 0; }
r[12]=r[4];
goto P_0c07b9ae;
P_0c07b9ae: /* original 4f22, guest PC 0x0c07b9ae */
if(!s->budget--) { s->failed_pc=0x0c07b9aeu; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07b9b0;
P_0c07b9b0: /* original d419, guest PC 0x0c07b9b0 */
if(!s->budget--) { s->failed_pc=0x0c07b9b0u; return 0; }
r[4]=read(ram,0x0c07ba18u,4);
goto P_0c07b9b2;
P_0c07b9b2: /* original d31a, guest PC 0x0c07b9b2 */
if(!s->budget--) { s->failed_pc=0x0c07b9b2u; return 0; }
r[3]=read(ram,0x0c07ba1cu,4);
goto P_0c07b9b4;
P_0c07b9b4: /* original 7ffc, guest PC 0x0c07b9b4 */
if(!s->budget--) { s->failed_pc=0x0c07b9b4u; return 0; }
r[15]+=0xfffffffcu;
goto P_0c07b9b6;
P_0c07b9b6: /* original 430b, guest PC 0x0c07b9b6 */
if(!s->budget--) { s->failed_pc=0x0c07b9b6u; return 0; }
target=r[3];
r[16]=code_base|0x0c07b9bau;
r[4]=r[14];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b9bau) { target=s->pc; goto dispatch; }
goto P_0c07b9ba;
P_0c07b9b8: /* original 64e3, guest PC 0x0c07b9b8 */
if(!s->budget--) { s->failed_pc=0x0c07b9b8u; return 0; }
r[4]=r[14];
goto P_0c07b9ba;
P_0c07b9ba: /* original d519, guest PC 0x0c07b9ba */
if(!s->budget--) { s->failed_pc=0x0c07b9bau; return 0; }
r[5]=read(ram,0x0c07ba20u,4);
goto P_0c07b9bc;
P_0c07b9bc: /* original e010, guest PC 0x0c07b9bc */
if(!s->budget--) { s->failed_pc=0x0c07b9bcu; return 0; }
r[0]=0x00000010u;
goto P_0c07b9be;
P_0c07b9be: /* original 0d5c, guest PC 0x0c07b9be */
if(!s->budget--) { s->failed_pc=0x0c07b9beu; return 0; }
r[13]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07b9c0;
P_0c07b9c0: /* original e011, guest PC 0x0c07b9c0 */
if(!s->budget--) { s->failed_pc=0x0c07b9c0u; return 0; }
r[0]=0x00000011u;
goto P_0c07b9c2;
P_0c07b9c2: /* original 6ddc, guest PC 0x0c07b9c2 */
if(!s->budget--) { s->failed_pc=0x0c07b9c2u; return 0; }
r[13]=r[13]&255u;
goto P_0c07b9c4;
P_0c07b9c4: /* original 05d4, guest PC 0x0c07b9c4 */
if(!s->budget--) { s->failed_pc=0x0c07b9c4u; return 0; }
write(ram,r[5]+r[0],r[13],1);
goto P_0c07b9c6;
P_0c07b9c6: /* original 9020, guest PC 0x0c07b9c6 */
if(!s->budget--) { s->failed_pc=0x0c07b9c6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07ba0au,2);
goto P_0c07b9c8;
P_0c07b9c8: /* original 04ee, guest PC 0x0c07b9c8 */
if(!s->budget--) { s->failed_pc=0x0c07b9c8u; return 0; }
r[4]=read(ram,r[14]+r[0],4);
goto P_0c07b9ca;
P_0c07b9ca: /* original 2448, guest PC 0x0c07b9ca */
if(!s->budget--) { s->failed_pc=0x0c07b9cau; return 0; }
r[17]=(r[17]&~1u)|(((r[4]&r[4])==0)!=0);
goto P_0c07b9cc;
P_0c07b9cc: /* original 8901, guest PC 0x0c07b9cc */
if(!s->budget--) { s->failed_pc=0x0c07b9ccu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b9d2; }
goto P_0c07b9ce;
P_0c07b9ce: /* original 74ff, guest PC 0x0c07b9ce */
if(!s->budget--) { s->failed_pc=0x0c07b9ceu; return 0; }
r[4]+=0xffffffffu;
goto P_0c07b9d0;
P_0c07b9d0: /* original 0e46, guest PC 0x0c07b9d0 */
if(!s->budget--) { s->failed_pc=0x0c07b9d0u; return 0; }
write(ram,r[14]+r[0],r[4],4);
goto P_0c07b9d2;
P_0c07b9d2: /* original e012, guest PC 0x0c07b9d2 */
if(!s->budget--) { s->failed_pc=0x0c07b9d2u; return 0; }
r[0]=0x00000012u;
goto P_0c07b9d4;
P_0c07b9d4: /* original 045c, guest PC 0x0c07b9d4 */
if(!s->budget--) { s->failed_pc=0x0c07b9d4u; return 0; }
r[4]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07b9d6;
P_0c07b9d6: /* original 644c, guest PC 0x0c07b9d6 */
if(!s->budget--) { s->failed_pc=0x0c07b9d6u; return 0; }
r[4]=r[4]&255u;
goto P_0c07b9d8;
P_0c07b9d8: /* original 34d0, guest PC 0x0c07b9d8 */
if(!s->budget--) { s->failed_pc=0x0c07b9d8u; return 0; }
r[17]=(r[17]&~1u)|((r[4]==r[13])!=0);
goto P_0c07b9da;
P_0c07b9da: /* original 8909, guest PC 0x0c07b9da */
if(!s->budget--) { s->failed_pc=0x0c07b9dau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07b9f0; }
goto P_0c07b9dc;
P_0c07b9dc: /* original 64d3, guest PC 0x0c07b9dc */
if(!s->budget--) { s->failed_pc=0x0c07b9dcu; return 0; }
r[4]=r[13];
goto P_0c07b9de;
P_0c07b9de: /* original 7401, guest PC 0x0c07b9de */
if(!s->budget--) { s->failed_pc=0x0c07b9deu; return 0; }
r[4]+=0x00000001u;
goto P_0c07b9e0;
P_0c07b9e0: /* original 0544, guest PC 0x0c07b9e0 */
if(!s->budget--) { s->failed_pc=0x0c07b9e0u; return 0; }
write(ram,r[5]+r[0],r[4],1);
goto P_0c07b9e2;
P_0c07b9e2: /* original 53e4, guest PC 0x0c07b9e2 */
if(!s->budget--) { s->failed_pc=0x0c07b9e2u; return 0; }
r[3]=read(ram,r[14]+16,4);
goto P_0c07b9e4;
P_0c07b9e4: /* original 6233, guest PC 0x0c07b9e4 */
if(!s->budget--) { s->failed_pc=0x0c07b9e4u; return 0; }
r[2]=r[3];
goto P_0c07b9e6;
P_0c07b9e6: /* original 2f32, guest PC 0x0c07b9e6 */
if(!s->budget--) { s->failed_pc=0x0c07b9e6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07b9e8;
P_0c07b9e8: /* original 420b, guest PC 0x0c07b9e8 */
if(!s->budget--) { s->failed_pc=0x0c07b9e8u; return 0; }
target=r[2];
r[16]=code_base|0x0c07b9ecu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07b9ecu) { target=s->pc; goto dispatch; }
goto P_0c07b9ec;
P_0c07b9ea: /* original 64c3, guest PC 0x0c07b9ea */
if(!s->budget--) { s->failed_pc=0x0c07b9eau; return 0; }
r[4]=r[12];
goto P_0c07b9ec;
P_0c07b9ec: /* original d309, guest PC 0x0c07b9ec */
if(!s->budget--) { s->failed_pc=0x0c07b9ecu; return 0; }
r[3]=read(ram,0x0c07ba14u,4);
goto P_0c07b9ee;
P_0c07b9ee: /* original 1e34, guest PC 0x0c07b9ee */
if(!s->budget--) { s->failed_pc=0x0c07b9eeu; return 0; }
write(ram,r[14]+16,r[3],4);
goto P_0c07b9f0;
P_0c07b9f0: /* original d00c, guest PC 0x0c07b9f0 */
if(!s->budget--) { s->failed_pc=0x0c07b9f0u; return 0; }
r[0]=read(ram,0x0c07ba24u,4);
goto P_0c07b9f2;
P_0c07b9f2: /* original 4d08, guest PC 0x0c07b9f2 */
if(!s->budget--) { s->failed_pc=0x0c07b9f2u; return 0; }
r[13]<<=2;
goto P_0c07b9f4;
P_0c07b9f4: /* original 64c3, guest PC 0x0c07b9f4 */
if(!s->budget--) { s->failed_pc=0x0c07b9f4u; return 0; }
r[4]=r[12];
goto P_0c07b9f6;
P_0c07b9f6: /* original e500, guest PC 0x0c07b9f6 */
if(!s->budget--) { s->failed_pc=0x0c07b9f6u; return 0; }
r[5]=0x00000000u;
goto P_0c07b9f8;
P_0c07b9f8: /* original 02de, guest PC 0x0c07b9f8 */
if(!s->budget--) { s->failed_pc=0x0c07b9f8u; return 0; }
r[2]=read(ram,r[13]+r[0],4);
goto P_0c07b9fa;
P_0c07b9fa: /* original 2f22, guest PC 0x0c07b9fa */
if(!s->budget--) { s->failed_pc=0x0c07b9fau; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07b9fc;
P_0c07b9fc: /* original 7f04, guest PC 0x0c07b9fc */
if(!s->budget--) { s->failed_pc=0x0c07b9fcu; return 0; }
r[15]+=0x00000004u;
goto P_0c07b9fe;
P_0c07b9fe: /* original 4f26, guest PC 0x0c07b9fe */
if(!s->budget--) { s->failed_pc=0x0c07b9feu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07ba00;
P_0c07ba00: /* original 6323, guest PC 0x0c07ba00 */
if(!s->budget--) { s->failed_pc=0x0c07ba00u; return 0; }
r[3]=r[2];
goto P_0c07ba02;
P_0c07ba02: /* original 6cf6, guest PC 0x0c07ba02 */
if(!s->budget--) { s->failed_pc=0x0c07ba02u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07ba04;
P_0c07ba04: /* original 6df6, guest PC 0x0c07ba04 */
if(!s->budget--) { s->failed_pc=0x0c07ba04u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07ba06;
P_0c07ba06: /* original 432b, guest PC 0x0c07ba06 */
if(!s->budget--) { s->failed_pc=0x0c07ba06u; return 0; }
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
P_0c07ba08: /* original 6ef6, guest PC 0x0c07ba08 */
if(!s->budget--) { s->failed_pc=0x0c07ba08u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
if(!vf3_matrix_family(0x0c07ba0au,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07ba0au; return 0; } return 1;
P_0c07ba28: /* original 2fe6, guest PC 0x0c07ba28 */
if(!s->budget--) { s->failed_pc=0x0c07ba28u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2a;
P_0c07ba2a: /* original 2fd6, guest PC 0x0c07ba2a */
if(!s->budget--) { s->failed_pc=0x0c07ba2au; return 0; }
tmp=r[13]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2c;
P_0c07ba2c: /* original 2fc6, guest PC 0x0c07ba2c */
if(!s->budget--) { s->failed_pc=0x0c07ba2cu; return 0; }
tmp=r[12]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba2e;
P_0c07ba2e: /* original 2fb6, guest PC 0x0c07ba2e */
if(!s->budget--) { s->failed_pc=0x0c07ba2eu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba30;
P_0c07ba30: /* original 2fa6, guest PC 0x0c07ba30 */
if(!s->budget--) { s->failed_pc=0x0c07ba30u; return 0; }
tmp=r[10]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba32;
P_0c07ba32: /* original 2f96, guest PC 0x0c07ba32 */
if(!s->budget--) { s->failed_pc=0x0c07ba32u; return 0; }
tmp=r[9]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba34;
P_0c07ba34: /* original 2f86, guest PC 0x0c07ba34 */
if(!s->budget--) { s->failed_pc=0x0c07ba34u; return 0; }
tmp=r[8]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07ba36;
P_0c07ba36: /* original fffb, guest PC 0x0c07ba36 */
if(!s->budget--) { s->failed_pc=0x0c07ba36u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,15,r[15]);
goto P_0c07ba38;
P_0c07ba38: /* original ffeb, guest PC 0x0c07ba38 */
if(!s->budget--) { s->failed_pc=0x0c07ba38u; return 0; }
r[15]-=(r[18]&0x100000u)?8:4;
vf3_matrix_store(s,ram,14,r[15]);
goto P_0c07ba3a;
P_0c07ba3a: /* original 4f22, guest PC 0x0c07ba3a */
if(!s->budget--) { s->failed_pc=0x0c07ba3au; return 0; }
r[15]-=4; write(ram,r[15],r[16],4);
goto P_0c07ba3c;
P_0c07ba3c: /* original d24b, guest PC 0x0c07ba3c */
if(!s->budget--) { s->failed_pc=0x0c07ba3cu; return 0; }
r[2]=read(ram,0x0c07bb6cu,4);
goto P_0c07ba3e;
P_0c07ba3e: /* original 9083, guest PC 0x0c07ba3e */
if(!s->budget--) { s->failed_pc=0x0c07ba3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb48u,2);
goto P_0c07ba40;
P_0c07ba40: /* original 4f12, guest PC 0x0c07ba40 */
if(!s->budget--) { s->failed_pc=0x0c07ba40u; return 0; }
r[15]-=4; write(ram,r[15],r[19],4);
goto P_0c07ba42;
P_0c07ba42: /* original 6322, guest PC 0x0c07ba42 */
if(!s->budget--) { s->failed_pc=0x0c07ba42u; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07ba44;
P_0c07ba44: /* original dd48, guest PC 0x0c07ba44 */
if(!s->budget--) { s->failed_pc=0x0c07ba44u; return 0; }
r[13]=read(ram,0x0c07bb68u,4);
goto P_0c07ba46;
P_0c07ba46: /* original 3f0c, guest PC 0x0c07ba46 */
if(!s->budget--) { s->failed_pc=0x0c07ba46u; return 0; }
r[15]+=r[0];
goto P_0c07ba48;
P_0c07ba48: /* original 1f3d, guest PC 0x0c07ba48 */
if(!s->budget--) { s->failed_pc=0x0c07ba48u; return 0; }
write(ram,r[15]+52,r[3],4);
goto P_0c07ba4a;
P_0c07ba4a: /* original d349, guest PC 0x0c07ba4a */
if(!s->budget--) { s->failed_pc=0x0c07ba4au; return 0; }
r[3]=read(ram,0x0c07bb70u,4);
goto P_0c07ba4c;
P_0c07ba4c: /* original 6132, guest PC 0x0c07ba4c */
if(!s->budget--) { s->failed_pc=0x0c07ba4cu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07ba4e;
P_0c07ba4e: /* original 1f1c, guest PC 0x0c07ba4e */
if(!s->budget--) { s->failed_pc=0x0c07ba4eu; return 0; }
write(ram,r[15]+48,r[1],4);
goto P_0c07ba50;
P_0c07ba50: /* original 50d2, guest PC 0x0c07ba50 */
if(!s->budget--) { s->failed_pc=0x0c07ba50u; return 0; }
r[0]=read(ram,r[13]+8,4);
goto P_0c07ba52;
P_0c07ba52: /* original d148, guest PC 0x0c07ba52 */
if(!s->budget--) { s->failed_pc=0x0c07ba52u; return 0; }
r[1]=read(ram,0x0c07bb74u,4);
goto P_0c07ba54;
P_0c07ba54: /* original 2018, guest PC 0x0c07ba54 */
if(!s->budget--) { s->failed_pc=0x0c07ba54u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&r[1])==0)!=0);
goto P_0c07ba56;
P_0c07ba56: /* original 8f1a, guest PC 0x0c07ba56 */
if(!s->budget--) { s->failed_pc=0x0c07ba56u; return 0; }
cond=r[17]&1u;
r[11]=0x00000020u;
if(!cond) { goto P_0c07ba8e; }
goto P_0c07ba5a;
P_0c07ba58: /* original eb20, guest PC 0x0c07ba58 */
if(!s->budget--) { s->failed_pc=0x0c07ba58u; return 0; }
r[11]=0x00000020u;
goto P_0c07ba5a;
P_0c07ba5a: /* original 53fd, guest PC 0x0c07ba5a */
if(!s->budget--) { s->failed_pc=0x0c07ba5au; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07ba5c;
P_0c07ba5c: /* original 23b8, guest PC 0x0c07ba5c */
if(!s->budget--) { s->failed_pc=0x0c07ba5cu; return 0; }
r[17]=(r[17]&~1u)|(((r[3]&r[11])==0)!=0);
goto P_0c07ba5e;
P_0c07ba5e: /* original 8902, guest PC 0x0c07ba5e */
if(!s->budget--) { s->failed_pc=0x0c07ba5eu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba66; }
goto P_0c07ba60;
P_0c07ba60: /* original d145, guest PC 0x0c07ba60 */
if(!s->budget--) { s->failed_pc=0x0c07ba60u; return 0; }
r[1]=read(ram,0x0c07bb78u,4);
goto P_0c07ba62;
P_0c07ba62: /* original 410b, guest PC 0x0c07ba62 */
if(!s->budget--) { s->failed_pc=0x0c07ba62u; return 0; }
target=r[1];
r[16]=code_base|0x0c07ba66u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba66u) { target=s->pc; goto dispatch; }
goto P_0c07ba66;
P_0c07ba64: /* original 0009, guest PC 0x0c07ba64 */
if(!s->budget--) { s->failed_pc=0x0c07ba64u; return 0; }
goto P_0c07ba66;
P_0c07ba66: /* original 50fd, guest PC 0x0c07ba66 */
if(!s->budget--) { s->failed_pc=0x0c07ba66u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba68;
P_0c07ba68: /* original c880, guest PC 0x0c07ba68 */
if(!s->budget--) { s->failed_pc=0x0c07ba68u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&128u)==0)!=0);
goto P_0c07ba6a;
P_0c07ba6a: /* original 8902, guest PC 0x0c07ba6a */
if(!s->budget--) { s->failed_pc=0x0c07ba6au; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba72; }
goto P_0c07ba6c;
P_0c07ba6c: /* original d243, guest PC 0x0c07ba6c */
if(!s->budget--) { s->failed_pc=0x0c07ba6cu; return 0; }
r[2]=read(ram,0x0c07bb7cu,4);
goto P_0c07ba6e;
P_0c07ba6e: /* original 420b, guest PC 0x0c07ba6e */
if(!s->budget--) { s->failed_pc=0x0c07ba6eu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba72u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba72u) { target=s->pc; goto dispatch; }
goto P_0c07ba72;
P_0c07ba70: /* original 0009, guest PC 0x0c07ba70 */
if(!s->budget--) { s->failed_pc=0x0c07ba70u; return 0; }
goto P_0c07ba72;
P_0c07ba72: /* original 52fd, guest PC 0x0c07ba72 */
if(!s->budget--) { s->failed_pc=0x0c07ba72u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07ba74;
P_0c07ba74: /* original 9369, guest PC 0x0c07ba74 */
if(!s->budget--) { s->failed_pc=0x0c07ba74u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4au,2);
goto P_0c07ba76;
P_0c07ba76: /* original 2238, guest PC 0x0c07ba76 */
if(!s->budget--) { s->failed_pc=0x0c07ba76u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07ba78;
P_0c07ba78: /* original 8902, guest PC 0x0c07ba78 */
if(!s->budget--) { s->failed_pc=0x0c07ba78u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba80; }
goto P_0c07ba7a;
P_0c07ba7a: /* original d241, guest PC 0x0c07ba7a */
if(!s->budget--) { s->failed_pc=0x0c07ba7au; return 0; }
r[2]=read(ram,0x0c07bb80u,4);
goto P_0c07ba7c;
P_0c07ba7c: /* original 420b, guest PC 0x0c07ba7c */
if(!s->budget--) { s->failed_pc=0x0c07ba7cu; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba80u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba80u) { target=s->pc; goto dispatch; }
goto P_0c07ba80;
P_0c07ba7e: /* original 0009, guest PC 0x0c07ba7e */
if(!s->budget--) { s->failed_pc=0x0c07ba7eu; return 0; }
goto P_0c07ba80;
P_0c07ba80: /* original 51fd, guest PC 0x0c07ba80 */
if(!s->budget--) { s->failed_pc=0x0c07ba80u; return 0; }
r[1]=read(ram,r[15]+52,4);
goto P_0c07ba82;
P_0c07ba82: /* original 9363, guest PC 0x0c07ba82 */
if(!s->budget--) { s->failed_pc=0x0c07ba82u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4cu,2);
goto P_0c07ba84;
P_0c07ba84: /* original 2138, guest PC 0x0c07ba84 */
if(!s->budget--) { s->failed_pc=0x0c07ba84u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07ba86;
P_0c07ba86: /* original 8902, guest PC 0x0c07ba86 */
if(!s->budget--) { s->failed_pc=0x0c07ba86u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07ba8e; }
goto P_0c07ba88;
P_0c07ba88: /* original d23e, guest PC 0x0c07ba88 */
if(!s->budget--) { s->failed_pc=0x0c07ba88u; return 0; }
r[2]=read(ram,0x0c07bb84u,4);
goto P_0c07ba8a;
P_0c07ba8a: /* original 420b, guest PC 0x0c07ba8a */
if(!s->budget--) { s->failed_pc=0x0c07ba8au; return 0; }
target=r[2];
r[16]=code_base|0x0c07ba8eu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba8eu) { target=s->pc; goto dispatch; }
goto P_0c07ba8e;
P_0c07ba8c: /* original 0009, guest PC 0x0c07ba8c */
if(!s->budget--) { s->failed_pc=0x0c07ba8cu; return 0; }
goto P_0c07ba8e;
P_0c07ba8e: /* original 50fd, guest PC 0x0c07ba8e */
if(!s->budget--) { s->failed_pc=0x0c07ba8eu; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07ba90;
P_0c07ba90: /* original c801, guest PC 0x0c07ba90 */
if(!s->budget--) { s->failed_pc=0x0c07ba90u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07ba92;
P_0c07ba92: /* original 8905, guest PC 0x0c07ba92 */
if(!s->budget--) { s->failed_pc=0x0c07ba92u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07baa0; }
goto P_0c07ba94;
P_0c07ba94: /* original d13c, guest PC 0x0c07ba94 */
if(!s->budget--) { s->failed_pc=0x0c07ba94u; return 0; }
r[1]=read(ram,0x0c07bb88u,4);
goto P_0c07ba96;
P_0c07ba96: /* original 410b, guest PC 0x0c07ba96 */
if(!s->budget--) { s->failed_pc=0x0c07ba96u; return 0; }
target=r[1];
r[16]=code_base|0x0c07ba9au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07ba9au) { target=s->pc; goto dispatch; }
goto P_0c07ba9a;
P_0c07ba98: /* original 0009, guest PC 0x0c07ba98 */
if(!s->budget--) { s->failed_pc=0x0c07ba98u; return 0; }
goto P_0c07ba9a;
P_0c07ba9a: /* original 53fc, guest PC 0x0c07ba9a */
if(!s->budget--) { s->failed_pc=0x0c07ba9au; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07ba9c;
P_0c07ba9c: /* original 230b, guest PC 0x0c07ba9c */
if(!s->budget--) { s->failed_pc=0x0c07ba9cu; return 0; }
r[3]|=r[0];
goto P_0c07ba9e;
P_0c07ba9e: /* original 1f3c, guest PC 0x0c07ba9e */
if(!s->budget--) { s->failed_pc=0x0c07ba9eu; return 0; }
write(ram,r[15]+48,r[3],4);
goto P_0c07baa0;
P_0c07baa0: /* original 53fd, guest PC 0x0c07baa0 */
if(!s->budget--) { s->failed_pc=0x0c07baa0u; return 0; }
r[3]=read(ram,r[15]+52,4);
goto P_0c07baa2;
P_0c07baa2: /* original ee00, guest PC 0x0c07baa2 */
if(!s->budget--) { s->failed_pc=0x0c07baa2u; return 0; }
r[14]=0x00000000u;
goto P_0c07baa4;
P_0c07baa4: /* original 9453, guest PC 0x0c07baa4 */
if(!s->budget--) { s->failed_pc=0x0c07baa4u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb4eu,2);
goto P_0c07baa6;
P_0c07baa6: /* original 52fc, guest PC 0x0c07baa6 */
if(!s->budget--) { s->failed_pc=0x0c07baa6u; return 0; }
r[2]=read(ram,r[15]+48,4);
goto P_0c07baa8;
P_0c07baa8: /* original 2439, guest PC 0x0c07baa8 */
if(!s->budget--) { s->failed_pc=0x0c07baa8u; return 0; }
r[4]&=r[3];
goto P_0c07baaa;
P_0c07baaa: /* original 242b, guest PC 0x0c07baaa */
if(!s->budget--) { s->failed_pc=0x0c07baaau; return 0; }
r[4]|=r[2];
goto P_0c07baac;
P_0c07baac: /* original 6043, guest PC 0x0c07baac */
if(!s->budget--) { s->failed_pc=0x0c07baacu; return 0; }
r[0]=r[4];
goto P_0c07baae;
P_0c07baae: /* original 1f4c, guest PC 0x0c07baae */
if(!s->budget--) { s->failed_pc=0x0c07baaeu; return 0; }
write(ram,r[15]+48,r[4],4);
goto P_0c07bab0;
P_0c07bab0: /* original d330, guest PC 0x0c07bab0 */
if(!s->budget--) { s->failed_pc=0x0c07bab0u; return 0; }
r[3]=read(ram,0x0c07bb74u,4);
goto P_0c07bab2;
P_0c07bab2: /* original c904, guest PC 0x0c07bab2 */
if(!s->budget--) { s->failed_pc=0x0c07bab2u; return 0; }
r[0]&=4u;
goto P_0c07bab4;
P_0c07bab4: /* original 52d2, guest PC 0x0c07bab4 */
if(!s->budget--) { s->failed_pc=0x0c07bab4u; return 0; }
r[2]=read(ram,r[13]+8,4);
goto P_0c07bab6;
P_0c07bab6: /* original 2238, guest PC 0x0c07bab6 */
if(!s->budget--) { s->failed_pc=0x0c07bab6u; return 0; }
r[17]=(r[17]&~1u)|(((r[2]&r[3])==0)!=0);
goto P_0c07bab8;
P_0c07bab8: /* original 8f02, guest PC 0x0c07bab8 */
if(!s->budget--) { s->failed_pc=0x0c07bab8u; return 0; }
cond=r[17]&1u;
r[12]=r[0];
if(!cond) { goto P_0c07bac0; }
goto P_0c07babc;
P_0c07baba: /* original 6c03, guest PC 0x0c07baba */
if(!s->budget--) { s->failed_pc=0x0c07babau; return 0; }
r[12]=r[0];
goto P_0c07babc;
P_0c07babc: /* original a408, guest PC 0x0c07babc */
if(!s->budget--) { s->failed_pc=0x0c07babcu; return 0; }
goto P_0c07c2d0;
P_0c07babe: /* original 0009, guest PC 0x0c07babe */
if(!s->budget--) { s->failed_pc=0x0c07babeu; return 0; }
goto P_0c07bac0;
P_0c07bac0: /* original 2cc8, guest PC 0x0c07bac0 */
if(!s->budget--) { s->failed_pc=0x0c07bac0u; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07bac2;
P_0c07bac2: /* original 8b01, guest PC 0x0c07bac2 */
if(!s->budget--) { s->failed_pc=0x0c07bac2u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bac8; }
goto P_0c07bac4;
P_0c07bac4: /* original a415, guest PC 0x0c07bac4 */
if(!s->budget--) { s->failed_pc=0x0c07bac4u; return 0; }
goto P_0c07c2f2;
P_0c07bac6: /* original 0009, guest PC 0x0c07bac6 */
if(!s->budget--) { s->failed_pc=0x0c07bac6u; return 0; }
goto P_0c07bac8;
P_0c07bac8: /* original d231, guest PC 0x0c07bac8 */
if(!s->budget--) { s->failed_pc=0x0c07bac8u; return 0; }
r[2]=read(ram,0x0c07bb90u,4);
goto P_0c07baca;
P_0c07baca: /* original e026, guest PC 0x0c07baca */
if(!s->budget--) { s->failed_pc=0x0c07bacau; return 0; }
r[0]=0x00000026u;
goto P_0c07bacc;
P_0c07bacc: /* original dd2f, guest PC 0x0c07bacc */
if(!s->budget--) { s->failed_pc=0x0c07baccu; return 0; }
r[13]=read(ram,0x0c07bb8cu,4);
goto P_0c07bace;
P_0c07bace: /* original e553, guest PC 0x0c07bace */
if(!s->budget--) { s->failed_pc=0x0c07baceu; return 0; }
r[5]=0x00000053u;
goto P_0c07bad0;
P_0c07bad0: /* original 2f22, guest PC 0x0c07bad0 */
if(!s->budget--) { s->failed_pc=0x0c07bad0u; return 0; }
write(ram,r[15],r[2],4);
goto P_0c07bad2;
P_0c07bad2: /* original e209, guest PC 0x0c07bad2 */
if(!s->budget--) { s->failed_pc=0x0c07bad2u; return 0; }
r[2]=0x00000009u;
goto P_0c07bad4;
P_0c07bad4: /* original 7d2c, guest PC 0x0c07bad4 */
if(!s->budget--) { s->failed_pc=0x0c07bad4u; return 0; }
r[13]+=0x0000002cu;
goto P_0c07bad6;
P_0c07bad6: /* original 0d25, guest PC 0x0c07bad6 */
if(!s->budget--) { s->failed_pc=0x0c07bad6u; return 0; }
write(ram,r[13]+r[0],r[2],2);
goto P_0c07bad8;
P_0c07bad8: /* original e022, guest PC 0x0c07bad8 */
if(!s->budget--) { s->failed_pc=0x0c07bad8u; return 0; }
r[0]=0x00000022u;
goto P_0c07bada;
P_0c07bada: /* original 01dd, guest PC 0x0c07bada */
if(!s->budget--) { s->failed_pc=0x0c07badau; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[13]+r[0],2);
goto P_0c07badc;
P_0c07badc: /* original e202, guest PC 0x0c07badc */
if(!s->budget--) { s->failed_pc=0x0c07badcu; return 0; }
r[2]=0x00000002u;
goto P_0c07bade;
P_0c07bade: /* original 212b, guest PC 0x0c07bade */
if(!s->budget--) { s->failed_pc=0x0c07badeu; return 0; }
r[1]|=r[2];
goto P_0c07bae0;
P_0c07bae0: /* original 0d15, guest PC 0x0c07bae0 */
if(!s->budget--) { s->failed_pc=0x0c07bae0u; return 0; }
write(ram,r[13]+r[0],r[1],2);
goto P_0c07bae2;
P_0c07bae2: /* original d12c, guest PC 0x0c07bae2 */
if(!s->budget--) { s->failed_pc=0x0c07bae2u; return 0; }
r[1]=read(ram,0x0c07bb94u,4);
goto P_0c07bae4;
P_0c07bae4: /* original 410b, guest PC 0x0c07bae4 */
if(!s->budget--) { s->failed_pc=0x0c07bae4u; return 0; }
target=r[1];
r[16]=code_base|0x0c07bae8u;
r[4]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bae8u) { target=s->pc; goto dispatch; }
goto P_0c07bae8;
P_0c07bae6: /* original 64d3, guest PC 0x0c07bae6 */
if(!s->budget--) { s->failed_pc=0x0c07bae6u; return 0; }
r[4]=r[13];
goto P_0c07bae8;
P_0c07bae8: /* original 9332, guest PC 0x0c07bae8 */
if(!s->budget--) { s->failed_pc=0x0c07bae8u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb50u,2);
goto P_0c07baea;
P_0c07baea: /* original 33fc, guest PC 0x0c07baea */
if(!s->budget--) { s->failed_pc=0x0c07baeau; return 0; }
r[3]+=r[15];
goto P_0c07baec;
P_0c07baec: /* original 1f31, guest PC 0x0c07baec */
if(!s->budget--) { s->failed_pc=0x0c07baecu; return 0; }
write(ram,r[15]+4,r[3],4);
goto P_0c07baee;
P_0c07baee: /* original 62f2, guest PC 0x0c07baee */
if(!s->budget--) { s->failed_pc=0x0c07baeeu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07baf0;
P_0c07baf0: /* original 902f, guest PC 0x0c07baf0 */
if(!s->budget--) { s->failed_pc=0x0c07baf0u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb52u,2);
goto P_0c07baf2;
P_0c07baf2: /* original 012d, guest PC 0x0c07baf2 */
if(!s->budget--) { s->failed_pc=0x0c07baf2u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07baf4;
P_0c07baf4: /* original 611d, guest PC 0x0c07baf4 */
if(!s->budget--) { s->failed_pc=0x0c07baf4u; return 0; }
r[1]=r[1]&65535u;
goto P_0c07baf6;
P_0c07baf6: /* original 2312, guest PC 0x0c07baf6 */
if(!s->budget--) { s->failed_pc=0x0c07baf6u; return 0; }
write(ram,r[3],r[1],4);
goto P_0c07baf8;
P_0c07baf8: /* original 902c, guest PC 0x0c07baf8 */
if(!s->budget--) { s->failed_pc=0x0c07baf8u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb54u,2);
goto P_0c07bafa;
P_0c07bafa: /* original 63f2, guest PC 0x0c07bafa */
if(!s->budget--) { s->failed_pc=0x0c07bafau; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bafc;
P_0c07bafc: /* original 54f1, guest PC 0x0c07bafc */
if(!s->budget--) { s->failed_pc=0x0c07bafcu; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bafe;
P_0c07bafe: /* original 023d, guest PC 0x0c07bafe */
if(!s->budget--) { s->failed_pc=0x0c07bafeu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb00;
P_0c07bb00: /* original 7408, guest PC 0x0c07bb00 */
if(!s->budget--) { s->failed_pc=0x0c07bb00u; return 0; }
r[4]+=0x00000008u;
goto P_0c07bb02;
P_0c07bb02: /* original 622d, guest PC 0x0c07bb02 */
if(!s->budget--) { s->failed_pc=0x0c07bb02u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb04;
P_0c07bb04: /* original 2422, guest PC 0x0c07bb04 */
if(!s->budget--) { s->failed_pc=0x0c07bb04u; return 0; }
write(ram,r[4],r[2],4);
goto P_0c07bb06;
P_0c07bb06: /* original 9026, guest PC 0x0c07bb06 */
if(!s->budget--) { s->failed_pc=0x0c07bb06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb56u,2);
goto P_0c07bb08;
P_0c07bb08: /* original 62f2, guest PC 0x0c07bb08 */
if(!s->budget--) { s->failed_pc=0x0c07bb08u; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bb0a;
P_0c07bb0a: /* original 53f1, guest PC 0x0c07bb0a */
if(!s->budget--) { s->failed_pc=0x0c07bb0au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bb0c;
P_0c07bb0c: /* original 012d, guest PC 0x0c07bb0c */
if(!s->budget--) { s->failed_pc=0x0c07bb0cu; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,r[2]+r[0],2);
goto P_0c07bb0e;
P_0c07bb0e: /* original 611d, guest PC 0x0c07bb0e */
if(!s->budget--) { s->failed_pc=0x0c07bb0eu; return 0; }
r[1]=r[1]&65535u;
goto P_0c07bb10;
P_0c07bb10: /* original 1311, guest PC 0x0c07bb10 */
if(!s->budget--) { s->failed_pc=0x0c07bb10u; return 0; }
write(ram,r[3]+4,r[1],4);
goto P_0c07bb12;
P_0c07bb12: /* original 9021, guest PC 0x0c07bb12 */
if(!s->budget--) { s->failed_pc=0x0c07bb12u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb58u,2);
goto P_0c07bb14;
P_0c07bb14: /* original 63f2, guest PC 0x0c07bb14 */
if(!s->budget--) { s->failed_pc=0x0c07bb14u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb16;
P_0c07bb16: /* original 023d, guest PC 0x0c07bb16 */
if(!s->budget--) { s->failed_pc=0x0c07bb16u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb18;
P_0c07bb18: /* original 622d, guest PC 0x0c07bb18 */
if(!s->budget--) { s->failed_pc=0x0c07bb18u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb1a;
P_0c07bb1a: /* original 1421, guest PC 0x0c07bb1a */
if(!s->budget--) { s->failed_pc=0x0c07bb1au; return 0; }
write(ram,r[4]+4,r[2],4);
goto P_0c07bb1c;
P_0c07bb1c: /* original 63f2, guest PC 0x0c07bb1c */
if(!s->budget--) { s->failed_pc=0x0c07bb1cu; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb1e;
P_0c07bb1e: /* original 901c, guest PC 0x0c07bb1e */
if(!s->budget--) { s->failed_pc=0x0c07bb1eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5au,2);
goto P_0c07bb20;
P_0c07bb20: /* original 023d, guest PC 0x0c07bb20 */
if(!s->budget--) { s->failed_pc=0x0c07bb20u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb22;
P_0c07bb22: /* original e07c, guest PC 0x0c07bb22 */
if(!s->budget--) { s->failed_pc=0x0c07bb22u; return 0; }
r[0]=0x0000007cu;
goto P_0c07bb24;
P_0c07bb24: /* original 622d, guest PC 0x0c07bb24 */
if(!s->budget--) { s->failed_pc=0x0c07bb24u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb26;
P_0c07bb26: /* original 0f26, guest PC 0x0c07bb26 */
if(!s->budget--) { s->failed_pc=0x0c07bb26u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb28;
P_0c07bb28: /* original 9018, guest PC 0x0c07bb28 */
if(!s->budget--) { s->failed_pc=0x0c07bb28u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5cu,2);
goto P_0c07bb2a;
P_0c07bb2a: /* original 63f2, guest PC 0x0c07bb2a */
if(!s->budget--) { s->failed_pc=0x0c07bb2au; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bb2c;
P_0c07bb2c: /* original 023d, guest PC 0x0c07bb2c */
if(!s->budget--) { s->failed_pc=0x0c07bb2cu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,r[3]+r[0],2);
goto P_0c07bb2e;
P_0c07bb2e: /* original 9016, guest PC 0x0c07bb2e */
if(!s->budget--) { s->failed_pc=0x0c07bb2eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb5eu,2);
goto P_0c07bb30;
P_0c07bb30: /* original 622d, guest PC 0x0c07bb30 */
if(!s->budget--) { s->failed_pc=0x0c07bb30u; return 0; }
r[2]=r[2]&65535u;
goto P_0c07bb32;
P_0c07bb32: /* original 0f26, guest PC 0x0c07bb32 */
if(!s->budget--) { s->failed_pc=0x0c07bb32u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07bb34;
P_0c07bb34: /* original 9116, guest PC 0x0c07bb34 */
if(!s->budget--) { s->failed_pc=0x0c07bb34u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb64u,2);
goto P_0c07bb36;
P_0c07bb36: /* original 60f2, guest PC 0x0c07bb36 */
if(!s->budget--) { s->failed_pc=0x0c07bb36u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07bb38;
P_0c07bb38: /* original d918, guest PC 0x0c07bb38 */
if(!s->budget--) { s->failed_pc=0x0c07bb38u; return 0; }
r[9]=read(ram,0x0c07bb9cu,4);
goto P_0c07bb3a;
P_0c07bb3a: /* original 001c, guest PC 0x0c07bb3a */
if(!s->budget--) { s->failed_pc=0x0c07bb3au; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bb3c;
P_0c07bb3c: /* original 9a10, guest PC 0x0c07bb3c */
if(!s->budget--) { s->failed_pc=0x0c07bb3cu; return 0; }
r[10]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb60u,2);
goto P_0c07bb3e;
P_0c07bb3e: /* original 9c10, guest PC 0x0c07bb3e */
if(!s->budget--) { s->failed_pc=0x0c07bb3eu; return 0; }
r[12]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bb62u,2);
goto P_0c07bb40;
P_0c07bb40: /* original 8802, guest PC 0x0c07bb40 */
if(!s->budget--) { s->failed_pc=0x0c07bb40u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000002u)!=0);
goto P_0c07bb42;
P_0c07bb42: /* original d815, guest PC 0x0c07bb42 */
if(!s->budget--) { s->failed_pc=0x0c07bb42u; return 0; }
r[8]=read(ram,0x0c07bb98u,4);
goto P_0c07bb44;
P_0c07bb44: /* original a02c, guest PC 0x0c07bb44 */
if(!s->budget--) { s->failed_pc=0x0c07bb44u; return 0; }
goto P_0c07bba0;
P_0c07bb46: /* original 0009, guest PC 0x0c07bb46 */
if(!s->budget--) { s->failed_pc=0x0c07bb46u; return 0; }
if(!vf3_matrix_family(0x0c07bb48u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07bb48u; return 0; } return 1;
P_0c07bba0: /* original 8b3a, guest PC 0x0c07bba0 */
if(!s->budget--) { s->failed_pc=0x0c07bba0u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bc18; }
goto P_0c07bba2;
P_0c07bba2: /* original 94aa, guest PC 0x0c07bba2 */
if(!s->budget--) { s->failed_pc=0x0c07bba2u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bba4;
P_0c07bba4: /* original 66d3, guest PC 0x0c07bba4 */
if(!s->budget--) { s->failed_pc=0x0c07bba4u; return 0; }
r[6]=r[13];
goto P_0c07bba6;
P_0c07bba6: /* original 2fe6, guest PC 0x0c07bba6 */
if(!s->budget--) { s->failed_pc=0x0c07bba6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bba8;
P_0c07bba8: /* original e700, guest PC 0x0c07bba8 */
if(!s->budget--) { s->failed_pc=0x0c07bba8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbaa;
P_0c07bbaa: /* original d258, guest PC 0x0c07bbaa */
if(!s->budget--) { s->failed_pc=0x0c07bbaau; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbac;
P_0c07bbac: /* original 420b, guest PC 0x0c07bbac */
if(!s->budget--) { s->failed_pc=0x0c07bbacu; return 0; }
target=r[2];
r[16]=code_base|0x0c07bbb0u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbb0u) { target=s->pc; goto dispatch; }
goto P_0c07bbb0;
P_0c07bbae: /* original 65c3, guest PC 0x0c07bbae */
if(!s->budget--) { s->failed_pc=0x0c07bbaeu; return 0; }
r[5]=r[12];
goto P_0c07bbb0;
P_0c07bbb0: /* original 7f04, guest PC 0x0c07bbb0 */
if(!s->budget--) { s->failed_pc=0x0c07bbb0u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbb2;
P_0c07bbb2: /* original 90a3, guest PC 0x0c07bbb2 */
if(!s->budget--) { s->failed_pc=0x0c07bbb2u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbb4;
P_0c07bbb4: /* original 63f2, guest PC 0x0c07bbb4 */
if(!s->budget--) { s->failed_pc=0x0c07bbb4u; return 0; }
tmp=read(ram,r[15],4);
r[3]=tmp;
goto P_0c07bbb6;
P_0c07bbb6: /* original 023c, guest PC 0x0c07bbb6 */
if(!s->budget--) { s->failed_pc=0x0c07bbb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbb8;
P_0c07bbb8: /* original 7001, guest PC 0x0c07bbb8 */
if(!s->budget--) { s->failed_pc=0x0c07bbb8u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbba;
P_0c07bbba: /* original 013c, guest PC 0x0c07bbba */
if(!s->budget--) { s->failed_pc=0x0c07bbbau; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[3]+r[0],1);
goto P_0c07bbbc;
P_0c07bbbc: /* original 3210, guest PC 0x0c07bbbc */
if(!s->budget--) { s->failed_pc=0x0c07bbbcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bbbe;
P_0c07bbbe: /* original 8d0f, guest PC 0x0c07bbbe */
if(!s->budget--) { s->failed_pc=0x0c07bbbeu; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bbe0; }
goto P_0c07bbc2;
P_0c07bbc0: /* original 64a3, guest PC 0x0c07bbc0 */
if(!s->budget--) { s->failed_pc=0x0c07bbc0u; return 0; }
r[4]=r[10];
goto P_0c07bbc2;
P_0c07bbc2: /* original 2fe6, guest PC 0x0c07bbc2 */
if(!s->budget--) { s->failed_pc=0x0c07bbc2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbc4;
P_0c07bbc4: /* original e700, guest PC 0x0c07bbc4 */
if(!s->budget--) { s->failed_pc=0x0c07bbc4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbc6;
P_0c07bbc6: /* original 5af1, guest PC 0x0c07bbc6 */
if(!s->budget--) { s->failed_pc=0x0c07bbc6u; return 0; }
r[10]=read(ram,r[15]+4,4);
goto P_0c07bbc8;
P_0c07bbc8: /* original 66d3, guest PC 0x0c07bbc8 */
if(!s->budget--) { s->failed_pc=0x0c07bbc8u; return 0; }
r[6]=r[13];
goto P_0c07bbca;
P_0c07bbca: /* original 9098, guest PC 0x0c07bbca */
if(!s->budget--) { s->failed_pc=0x0c07bbcau; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bbcc;
P_0c07bbcc: /* original d34f, guest PC 0x0c07bbcc */
if(!s->budget--) { s->failed_pc=0x0c07bbccu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bbce;
P_0c07bbce: /* original 00ac, guest PC 0x0c07bbce */
if(!s->budget--) { s->failed_pc=0x0c07bbceu; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbd0;
P_0c07bbd0: /* original 4008, guest PC 0x0c07bbd0 */
if(!s->budget--) { s->failed_pc=0x0c07bbd0u; return 0; }
r[0]<<=2;
goto P_0c07bbd2;
P_0c07bbd2: /* original 430b, guest PC 0x0c07bbd2 */
if(!s->budget--) { s->failed_pc=0x0c07bbd2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bbd6u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbd6u) { target=s->pc; goto dispatch; }
goto P_0c07bbd6;
P_0c07bbd4: /* original 059e, guest PC 0x0c07bbd4 */
if(!s->budget--) { s->failed_pc=0x0c07bbd4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bbd6;
P_0c07bbd6: /* original 9091, guest PC 0x0c07bbd6 */
if(!s->budget--) { s->failed_pc=0x0c07bbd6u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bbd8;
P_0c07bbd8: /* original 7f04, guest PC 0x0c07bbd8 */
if(!s->budget--) { s->failed_pc=0x0c07bbd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bbda;
P_0c07bbda: /* original 02ac, guest PC 0x0c07bbda */
if(!s->budget--) { s->failed_pc=0x0c07bbdau; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[10]+r[0],1);
goto P_0c07bbdc;
P_0c07bbdc: /* original 7001, guest PC 0x0c07bbdc */
if(!s->budget--) { s->failed_pc=0x0c07bbdcu; return 0; }
r[0]+=0x00000001u;
goto P_0c07bbde;
P_0c07bbde: /* original 0a24, guest PC 0x0c07bbde */
if(!s->budget--) { s->failed_pc=0x0c07bbdeu; return 0; }
write(ram,r[10]+r[0],r[2],1);
goto P_0c07bbe0;
P_0c07bbe0: /* original 2fb6, guest PC 0x0c07bbe0 */
if(!s->budget--) { s->failed_pc=0x0c07bbe0u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbe2;
P_0c07bbe2: /* original 66d3, guest PC 0x0c07bbe2 */
if(!s->budget--) { s->failed_pc=0x0c07bbe2u; return 0; }
r[6]=r[13];
goto P_0c07bbe4;
P_0c07bbe4: /* original 2fe6, guest PC 0x0c07bbe4 */
if(!s->budget--) { s->failed_pc=0x0c07bbe4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbe6;
P_0c07bbe6: /* original e700, guest PC 0x0c07bbe6 */
if(!s->budget--) { s->failed_pc=0x0c07bbe6u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbe8;
P_0c07bbe8: /* original 948a, guest PC 0x0c07bbe8 */
if(!s->budget--) { s->failed_pc=0x0c07bbe8u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bbea;
P_0c07bbea: /* original 480b, guest PC 0x0c07bbea */
if(!s->budget--) { s->failed_pc=0x0c07bbeau; return 0; }
target=r[8];
r[16]=code_base|0x0c07bbeeu;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbeeu) { target=s->pc; goto dispatch; }
goto P_0c07bbee;
P_0c07bbec: /* original 65c3, guest PC 0x0c07bbec */
if(!s->budget--) { s->failed_pc=0x0c07bbecu; return 0; }
r[5]=r[12];
goto P_0c07bbee;
P_0c07bbee: /* original 2fb6, guest PC 0x0c07bbee */
if(!s->budget--) { s->failed_pc=0x0c07bbeeu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbf0;
P_0c07bbf0: /* original 66d3, guest PC 0x0c07bbf0 */
if(!s->budget--) { s->failed_pc=0x0c07bbf0u; return 0; }
r[6]=r[13];
goto P_0c07bbf2;
P_0c07bbf2: /* original 2fe6, guest PC 0x0c07bbf2 */
if(!s->budget--) { s->failed_pc=0x0c07bbf2u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbf4;
P_0c07bbf4: /* original e700, guest PC 0x0c07bbf4 */
if(!s->budget--) { s->failed_pc=0x0c07bbf4u; return 0; }
r[7]=0x00000000u;
goto P_0c07bbf6;
P_0c07bbf6: /* original 9484, guest PC 0x0c07bbf6 */
if(!s->budget--) { s->failed_pc=0x0c07bbf6u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bbf8;
P_0c07bbf8: /* original 480b, guest PC 0x0c07bbf8 */
if(!s->budget--) { s->failed_pc=0x0c07bbf8u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bbfcu;
r[5]=read(ram,r[9]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bbfcu) { target=s->pc; goto dispatch; }
goto P_0c07bbfc;
P_0c07bbfa: /* original 559a, guest PC 0x0c07bbfa */
if(!s->budget--) { s->failed_pc=0x0c07bbfau; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bbfc;
P_0c07bbfc: /* original 2fb6, guest PC 0x0c07bbfc */
if(!s->budget--) { s->failed_pc=0x0c07bbfcu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bbfe;
P_0c07bbfe: /* original e700, guest PC 0x0c07bbfe */
if(!s->budget--) { s->failed_pc=0x0c07bbfeu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc00;
P_0c07bc00: /* original 2fe6, guest PC 0x0c07bc00 */
if(!s->budget--) { s->failed_pc=0x0c07bc00u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc02;
P_0c07bc02: /* original 66d3, guest PC 0x0c07bc02 */
if(!s->budget--) { s->failed_pc=0x0c07bc02u; return 0; }
r[6]=r[13];
goto P_0c07bc04;
P_0c07bc04: /* original 55f6, guest PC 0x0c07bc04 */
if(!s->budget--) { s->failed_pc=0x0c07bc04u; return 0; }
r[5]=read(ram,r[15]+24,4);
goto P_0c07bc06;
P_0c07bc06: /* original 907d, guest PC 0x0c07bc06 */
if(!s->budget--) { s->failed_pc=0x0c07bc06u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc08;
P_0c07bc08: /* original 947d, guest PC 0x0c07bc08 */
if(!s->budget--) { s->failed_pc=0x0c07bc08u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc0a;
P_0c07bc0a: /* original 055c, guest PC 0x0c07bc0a */
if(!s->budget--) { s->failed_pc=0x0c07bc0au; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc0c;
P_0c07bc0c: /* original 4508, guest PC 0x0c07bc0c */
if(!s->budget--) { s->failed_pc=0x0c07bc0cu; return 0; }
r[5]<<=2;
goto P_0c07bc0e;
P_0c07bc0e: /* original 359c, guest PC 0x0c07bc0e */
if(!s->budget--) { s->failed_pc=0x0c07bc0eu; return 0; }
r[5]+=r[9];
goto P_0c07bc10;
P_0c07bc10: /* original 480b, guest PC 0x0c07bc10 */
if(!s->budget--) { s->failed_pc=0x0c07bc10u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bc14u;
r[5]=read(ram,r[5]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc14u) { target=s->pc; goto dispatch; }
goto P_0c07bc14;
P_0c07bc12: /* original 5551, guest PC 0x0c07bc12 */
if(!s->budget--) { s->failed_pc=0x0c07bc12u; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc14;
P_0c07bc14: /* original a045, guest PC 0x0c07bc14 */
if(!s->budget--) { s->failed_pc=0x0c07bc14u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bca2;
P_0c07bc16: /* original 7f18, guest PC 0x0c07bc16 */
if(!s->budget--) { s->failed_pc=0x0c07bc16u; return 0; }
r[15]+=0x00000018u;
goto P_0c07bc18;
P_0c07bc18: /* original 9472, guest PC 0x0c07bc18 */
if(!s->budget--) { s->failed_pc=0x0c07bc18u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd00u,2);
goto P_0c07bc1a;
P_0c07bc1a: /* original 66d3, guest PC 0x0c07bc1a */
if(!s->budget--) { s->failed_pc=0x0c07bc1au; return 0; }
r[6]=r[13];
goto P_0c07bc1c;
P_0c07bc1c: /* original 2fe6, guest PC 0x0c07bc1c */
if(!s->budget--) { s->failed_pc=0x0c07bc1cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc1e;
P_0c07bc1e: /* original e700, guest PC 0x0c07bc1e */
if(!s->budget--) { s->failed_pc=0x0c07bc1eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc20;
P_0c07bc20: /* original d23a, guest PC 0x0c07bc20 */
if(!s->budget--) { s->failed_pc=0x0c07bc20u; return 0; }
r[2]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc22;
P_0c07bc22: /* original 420b, guest PC 0x0c07bc22 */
if(!s->budget--) { s->failed_pc=0x0c07bc22u; return 0; }
target=r[2];
r[16]=code_base|0x0c07bc26u;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc26u) { target=s->pc; goto dispatch; }
goto P_0c07bc26;
P_0c07bc24: /* original 65c3, guest PC 0x0c07bc24 */
if(!s->budget--) { s->failed_pc=0x0c07bc24u; return 0; }
r[5]=r[12];
goto P_0c07bc26;
P_0c07bc26: /* original 946c, guest PC 0x0c07bc26 */
if(!s->budget--) { s->failed_pc=0x0c07bc26u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd02u,2);
goto P_0c07bc28;
P_0c07bc28: /* original 66d3, guest PC 0x0c07bc28 */
if(!s->budget--) { s->failed_pc=0x0c07bc28u; return 0; }
r[6]=r[13];
goto P_0c07bc2a;
P_0c07bc2a: /* original 2fe6, guest PC 0x0c07bc2a */
if(!s->budget--) { s->failed_pc=0x0c07bc2au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc2c;
P_0c07bc2c: /* original e700, guest PC 0x0c07bc2c */
if(!s->budget--) { s->failed_pc=0x0c07bc2cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc2e;
P_0c07bc2e: /* original d337, guest PC 0x0c07bc2e */
if(!s->budget--) { s->failed_pc=0x0c07bc2eu; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc30;
P_0c07bc30: /* original 430b, guest PC 0x0c07bc30 */
if(!s->budget--) { s->failed_pc=0x0c07bc30u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc34u;
r[5]=read(ram,r[9]+40,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc34u) { target=s->pc; goto dispatch; }
goto P_0c07bc34;
P_0c07bc32: /* original 559a, guest PC 0x0c07bc32 */
if(!s->budget--) { s->failed_pc=0x0c07bc32u; return 0; }
r[5]=read(ram,r[9]+40,4);
goto P_0c07bc34;
P_0c07bc34: /* original 9467, guest PC 0x0c07bc34 */
if(!s->budget--) { s->failed_pc=0x0c07bc34u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd06u,2);
goto P_0c07bc36;
P_0c07bc36: /* original e700, guest PC 0x0c07bc36 */
if(!s->budget--) { s->failed_pc=0x0c07bc36u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc38;
P_0c07bc38: /* original 2fe6, guest PC 0x0c07bc38 */
if(!s->budget--) { s->failed_pc=0x0c07bc38u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc3a;
P_0c07bc3a: /* original 66d3, guest PC 0x0c07bc3a */
if(!s->budget--) { s->failed_pc=0x0c07bc3au; return 0; }
r[6]=r[13];
goto P_0c07bc3c;
P_0c07bc3c: /* original 55f3, guest PC 0x0c07bc3c */
if(!s->budget--) { s->failed_pc=0x0c07bc3cu; return 0; }
r[5]=read(ram,r[15]+12,4);
goto P_0c07bc3e;
P_0c07bc3e: /* original 9061, guest PC 0x0c07bc3e */
if(!s->budget--) { s->failed_pc=0x0c07bc3eu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd04u,2);
goto P_0c07bc40;
P_0c07bc40: /* original d332, guest PC 0x0c07bc40 */
if(!s->budget--) { s->failed_pc=0x0c07bc40u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc42;
P_0c07bc42: /* original 055c, guest PC 0x0c07bc42 */
if(!s->budget--) { s->failed_pc=0x0c07bc42u; return 0; }
r[5]=(uint32_t)(int32_t)(int8_t)read(ram,r[5]+r[0],1);
goto P_0c07bc44;
P_0c07bc44: /* original 4508, guest PC 0x0c07bc44 */
if(!s->budget--) { s->failed_pc=0x0c07bc44u; return 0; }
r[5]<<=2;
goto P_0c07bc46;
P_0c07bc46: /* original 359c, guest PC 0x0c07bc46 */
if(!s->budget--) { s->failed_pc=0x0c07bc46u; return 0; }
r[5]+=r[9];
goto P_0c07bc48;
P_0c07bc48: /* original 430b, guest PC 0x0c07bc48 */
if(!s->budget--) { s->failed_pc=0x0c07bc48u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc4cu;
r[5]=read(ram,r[5]+4,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc4cu) { target=s->pc; goto dispatch; }
goto P_0c07bc4c;
P_0c07bc4a: /* original 5551, guest PC 0x0c07bc4a */
if(!s->budget--) { s->failed_pc=0x0c07bc4au; return 0; }
r[5]=read(ram,r[5]+4,4);
goto P_0c07bc4c;
P_0c07bc4c: /* original 2fb6, guest PC 0x0c07bc4c */
if(!s->budget--) { s->failed_pc=0x0c07bc4cu; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc4e;
P_0c07bc4e: /* original 66d3, guest PC 0x0c07bc4e */
if(!s->budget--) { s->failed_pc=0x0c07bc4eu; return 0; }
r[6]=r[13];
goto P_0c07bc50;
P_0c07bc50: /* original 2fe6, guest PC 0x0c07bc50 */
if(!s->budget--) { s->failed_pc=0x0c07bc50u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc52;
P_0c07bc52: /* original e700, guest PC 0x0c07bc52 */
if(!s->budget--) { s->failed_pc=0x0c07bc52u; return 0; }
r[7]=0x00000000u;
goto P_0c07bc54;
P_0c07bc54: /* original 9451, guest PC 0x0c07bc54 */
if(!s->budget--) { s->failed_pc=0x0c07bc54u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfau,2);
goto P_0c07bc56;
P_0c07bc56: /* original 480b, guest PC 0x0c07bc56 */
if(!s->budget--) { s->failed_pc=0x0c07bc56u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bc5au;
r[5]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc5au) { target=s->pc; goto dispatch; }
goto P_0c07bc5a;
P_0c07bc58: /* original 65c3, guest PC 0x0c07bc58 */
if(!s->budget--) { s->failed_pc=0x0c07bc58u; return 0; }
r[5]=r[12];
goto P_0c07bc5a;
P_0c07bc5a: /* original 7f14, guest PC 0x0c07bc5a */
if(!s->budget--) { s->failed_pc=0x0c07bc5au; return 0; }
r[15]+=0x00000014u;
goto P_0c07bc5c;
P_0c07bc5c: /* original 904e, guest PC 0x0c07bc5c */
if(!s->budget--) { s->failed_pc=0x0c07bc5cu; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc5e;
P_0c07bc5e: /* original 62f2, guest PC 0x0c07bc5e */
if(!s->budget--) { s->failed_pc=0x0c07bc5eu; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07bc60;
P_0c07bc60: /* original 032c, guest PC 0x0c07bc60 */
if(!s->budget--) { s->failed_pc=0x0c07bc60u; return 0; }
r[3]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc62;
P_0c07bc62: /* original 7001, guest PC 0x0c07bc62 */
if(!s->budget--) { s->failed_pc=0x0c07bc62u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc64;
P_0c07bc64: /* original 012c, guest PC 0x0c07bc64 */
if(!s->budget--) { s->failed_pc=0x0c07bc64u; return 0; }
r[1]=(uint32_t)(int32_t)(int8_t)read(ram,r[2]+r[0],1);
goto P_0c07bc66;
P_0c07bc66: /* original 3310, guest PC 0x0c07bc66 */
if(!s->budget--) { s->failed_pc=0x0c07bc66u; return 0; }
r[17]=(r[17]&~1u)|((r[3]==r[1])!=0);
goto P_0c07bc68;
P_0c07bc68: /* original 8d0f, guest PC 0x0c07bc68 */
if(!s->budget--) { s->failed_pc=0x0c07bc68u; return 0; }
cond=r[17]&1u;
r[4]=r[10];
if(cond) { goto P_0c07bc8a; }
goto P_0c07bc6c;
P_0c07bc6a: /* original 64a3, guest PC 0x0c07bc6a */
if(!s->budget--) { s->failed_pc=0x0c07bc6au; return 0; }
r[4]=r[10];
goto P_0c07bc6c;
P_0c07bc6c: /* original 2fe6, guest PC 0x0c07bc6c */
if(!s->budget--) { s->failed_pc=0x0c07bc6cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc6e;
P_0c07bc6e: /* original e700, guest PC 0x0c07bc6e */
if(!s->budget--) { s->failed_pc=0x0c07bc6eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc70;
P_0c07bc70: /* original 5cf1, guest PC 0x0c07bc70 */
if(!s->budget--) { s->failed_pc=0x0c07bc70u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07bc72;
P_0c07bc72: /* original 66d3, guest PC 0x0c07bc72 */
if(!s->budget--) { s->failed_pc=0x0c07bc72u; return 0; }
r[6]=r[13];
goto P_0c07bc74;
P_0c07bc74: /* original 9043, guest PC 0x0c07bc74 */
if(!s->budget--) { s->failed_pc=0x0c07bc74u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfeu,2);
goto P_0c07bc76;
P_0c07bc76: /* original d325, guest PC 0x0c07bc76 */
if(!s->budget--) { s->failed_pc=0x0c07bc76u; return 0; }
r[3]=read(ram,0x0c07bd0cu,4);
goto P_0c07bc78;
P_0c07bc78: /* original 00cc, guest PC 0x0c07bc78 */
if(!s->budget--) { s->failed_pc=0x0c07bc78u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc7a;
P_0c07bc7a: /* original 4008, guest PC 0x0c07bc7a */
if(!s->budget--) { s->failed_pc=0x0c07bc7au; return 0; }
r[0]<<=2;
goto P_0c07bc7c;
P_0c07bc7c: /* original 430b, guest PC 0x0c07bc7c */
if(!s->budget--) { s->failed_pc=0x0c07bc7cu; return 0; }
target=r[3];
r[16]=code_base|0x0c07bc80u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bc80u) { target=s->pc; goto dispatch; }
goto P_0c07bc80;
P_0c07bc7e: /* original 059e, guest PC 0x0c07bc7e */
if(!s->budget--) { s->failed_pc=0x0c07bc7eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc80;
P_0c07bc80: /* original 903c, guest PC 0x0c07bc80 */
if(!s->budget--) { s->failed_pc=0x0c07bc80u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc82;
P_0c07bc82: /* original 7f04, guest PC 0x0c07bc82 */
if(!s->budget--) { s->failed_pc=0x0c07bc82u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bc84;
P_0c07bc84: /* original 02cc, guest PC 0x0c07bc84 */
if(!s->budget--) { s->failed_pc=0x0c07bc84u; return 0; }
r[2]=(uint32_t)(int32_t)(int8_t)read(ram,r[12]+r[0],1);
goto P_0c07bc86;
P_0c07bc86: /* original 7001, guest PC 0x0c07bc86 */
if(!s->budget--) { s->failed_pc=0x0c07bc86u; return 0; }
r[0]+=0x00000001u;
goto P_0c07bc88;
P_0c07bc88: /* original 0c24, guest PC 0x0c07bc88 */
if(!s->budget--) { s->failed_pc=0x0c07bc88u; return 0; }
write(ram,r[12]+r[0],r[2],1);
goto P_0c07bc8a;
P_0c07bc8a: /* original 2fb6, guest PC 0x0c07bc8a */
if(!s->budget--) { s->failed_pc=0x0c07bc8au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc8c;
P_0c07bc8c: /* original e700, guest PC 0x0c07bc8c */
if(!s->budget--) { s->failed_pc=0x0c07bc8cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bc8e;
P_0c07bc8e: /* original 2fe6, guest PC 0x0c07bc8e */
if(!s->budget--) { s->failed_pc=0x0c07bc8eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bc90;
P_0c07bc90: /* original 66d3, guest PC 0x0c07bc90 */
if(!s->budget--) { s->failed_pc=0x0c07bc90u; return 0; }
r[6]=r[13];
goto P_0c07bc92;
P_0c07bc92: /* original 50f2, guest PC 0x0c07bc92 */
if(!s->budget--) { s->failed_pc=0x0c07bc92u; return 0; }
r[0]=read(ram,r[15]+8,4);
goto P_0c07bc94;
P_0c07bc94: /* original 9132, guest PC 0x0c07bc94 */
if(!s->budget--) { s->failed_pc=0x0c07bc94u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bcfcu,2);
goto P_0c07bc96;
P_0c07bc96: /* original 001c, guest PC 0x0c07bc96 */
if(!s->budget--) { s->failed_pc=0x0c07bc96u; return 0; }
r[0]=(uint32_t)(int32_t)(int8_t)read(ram,r[1]+r[0],1);
goto P_0c07bc98;
P_0c07bc98: /* original 4008, guest PC 0x0c07bc98 */
if(!s->budget--) { s->failed_pc=0x0c07bc98u; return 0; }
r[0]<<=2;
goto P_0c07bc9a;
P_0c07bc9a: /* original 059e, guest PC 0x0c07bc9a */
if(!s->budget--) { s->failed_pc=0x0c07bc9au; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bc9c;
P_0c07bc9c: /* original 480b, guest PC 0x0c07bc9c */
if(!s->budget--) { s->failed_pc=0x0c07bc9cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07bca0u;
r[4]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bca0u) { target=s->pc; goto dispatch; }
goto P_0c07bca0;
P_0c07bc9e: /* original 64a3, guest PC 0x0c07bc9e */
if(!s->budget--) { s->failed_pc=0x0c07bc9eu; return 0; }
r[4]=r[10];
goto P_0c07bca0;
P_0c07bca0: /* original 7f08, guest PC 0x0c07bca0 */
if(!s->budget--) { s->failed_pc=0x0c07bca0u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bca2;
P_0c07bca2: /* original d31b, guest PC 0x0c07bca2 */
if(!s->budget--) { s->failed_pc=0x0c07bca2u; return 0; }
r[3]=read(ram,0x0c07bd10u,4);
goto P_0c07bca4;
P_0c07bca4: /* original fe8d, guest PC 0x0c07bca4 */
if(!s->budget--) { s->failed_pc=0x0c07bca4u; return 0; }
fr[14]=0;
goto P_0c07bca6;
P_0c07bca6: /* original 6032, guest PC 0x0c07bca6 */
if(!s->budget--) { s->failed_pc=0x0c07bca6u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bca8;
P_0c07bca8: /* original c801, guest PC 0x0c07bca8 */
if(!s->budget--) { s->failed_pc=0x0c07bca8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&1u)==0)!=0);
goto P_0c07bcaa;
P_0c07bcaa: /* original 8d02, guest PC 0x0c07bcaa */
if(!s->budget--) { s->failed_pc=0x0c07bcaau; return 0; }
cond=r[17]&1u;
r[10]=0x00000064u;
if(cond) { goto P_0c07bcb2; }
goto P_0c07bcae;
P_0c07bcac: /* original ea64, guest PC 0x0c07bcac */
if(!s->budget--) { s->failed_pc=0x0c07bcacu; return 0; }
r[10]=0x00000064u;
goto P_0c07bcae;
P_0c07bcae: /* original a212, guest PC 0x0c07bcae */
if(!s->budget--) { s->failed_pc=0x0c07bcaeu; return 0; }
goto P_0c07c0d6;
P_0c07bcb0: /* original 0009, guest PC 0x0c07bcb0 */
if(!s->budget--) { s->failed_pc=0x0c07bcb0u; return 0; }
goto P_0c07bcb2;
P_0c07bcb2: /* original 6193, guest PC 0x0c07bcb2 */
if(!s->budget--) { s->failed_pc=0x0c07bcb2u; return 0; }
r[1]=r[9];
goto P_0c07bcb4;
P_0c07bcb4: /* original 1fe8, guest PC 0x0c07bcb4 */
if(!s->budget--) { s->failed_pc=0x0c07bcb4u; return 0; }
write(ram,r[15]+32,r[14],4);
goto P_0c07bcb6;
P_0c07bcb6: /* original 9227, guest PC 0x0c07bcb6 */
if(!s->budget--) { s->failed_pc=0x0c07bcb6u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcb8;
P_0c07bcb8: /* original 32fc, guest PC 0x0c07bcb8 */
if(!s->budget--) { s->failed_pc=0x0c07bcb8u; return 0; }
r[2]+=r[15];
goto P_0c07bcba;
P_0c07bcba: /* original 1f2f, guest PC 0x0c07bcba */
if(!s->budget--) { s->failed_pc=0x0c07bcbau; return 0; }
write(ram,r[15]+60,r[2],4);
goto P_0c07bcbc;
P_0c07bcbc: /* original 1f1a, guest PC 0x0c07bcbc */
if(!s->budget--) { s->failed_pc=0x0c07bcbcu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07bcbe;
P_0c07bcbe: /* original a196, guest PC 0x0c07bcbe */
if(!s->budget--) { s->failed_pc=0x0c07bcbeu; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bfee;
P_0c07bcc0: /* original ff9d, guest PC 0x0c07bcc0 */
if(!s->budget--) { s->failed_pc=0x0c07bcc0u; return 0; }
fr[15]=0x3f800000u;
goto P_0c07bcc2;
P_0c07bcc2: /* original e122, guest PC 0x0c07bcc2 */
if(!s->budget--) { s->failed_pc=0x0c07bcc2u; return 0; }
r[1]=0x00000022u;
goto P_0c07bcc4;
P_0c07bcc4: /* original 53f8, guest PC 0x0c07bcc4 */
if(!s->budget--) { s->failed_pc=0x0c07bcc4u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07bcc6;
P_0c07bcc6: /* original e007, guest PC 0x0c07bcc6 */
if(!s->budget--) { s->failed_pc=0x0c07bcc6u; return 0; }
r[0]=0x00000007u;
goto P_0c07bcc8;
P_0c07bcc8: /* original 6ce3, guest PC 0x0c07bcc8 */
if(!s->budget--) { s->failed_pc=0x0c07bcc8u; return 0; }
r[12]=r[14];
goto P_0c07bcca;
P_0c07bcca: /* original 4308, guest PC 0x0c07bcca */
if(!s->budget--) { s->failed_pc=0x0c07bccau; return 0; }
r[3]<<=2;
goto P_0c07bccc;
P_0c07bccc: /* original 4300, guest PC 0x0c07bccc */
if(!s->budget--) { s->failed_pc=0x0c07bcccu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bcce;
P_0c07bcce: /* original 1f32, guest PC 0x0c07bcce */
if(!s->budget--) { s->failed_pc=0x0c07bcceu; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07bcd0;
P_0c07bcd0: /* original 921a, guest PC 0x0c07bcd0 */
if(!s->budget--) { s->failed_pc=0x0c07bcd0u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bd08u,2);
goto P_0c07bcd2;
P_0c07bcd2: /* original 32fc, guest PC 0x0c07bcd2 */
if(!s->budget--) { s->failed_pc=0x0c07bcd2u; return 0; }
r[2]+=r[15];
goto P_0c07bcd4;
P_0c07bcd4: /* original 332c, guest PC 0x0c07bcd4 */
if(!s->budget--) { s->failed_pc=0x0c07bcd4u; return 0; }
r[3]+=r[2];
goto P_0c07bcd6;
P_0c07bcd6: /* original 1f34, guest PC 0x0c07bcd6 */
if(!s->budget--) { s->failed_pc=0x0c07bcd6u; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07bcd8;
P_0c07bcd8: /* original 1f39, guest PC 0x0c07bcd8 */
if(!s->budget--) { s->failed_pc=0x0c07bcd8u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bcda;
P_0c07bcda: /* original 1f1b, guest PC 0x0c07bcda */
if(!s->budget--) { s->failed_pc=0x0c07bcdau; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07bcdc;
P_0c07bcdc: /* original e11e, guest PC 0x0c07bcdc */
if(!s->budget--) { s->failed_pc=0x0c07bcdcu; return 0; }
r[1]=0x0000001eu;
goto P_0c07bcde;
P_0c07bcde: /* original 1f17, guest PC 0x0c07bcde */
if(!s->budget--) { s->failed_pc=0x0c07bcdeu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bce0;
P_0c07bce0: /* original 55f4, guest PC 0x0c07bce0 */
if(!s->budget--) { s->failed_pc=0x0c07bce0u; return 0; }
r[5]=read(ram,r[15]+16,4);
goto P_0c07bce2;
P_0c07bce2: /* original 1f54, guest PC 0x0c07bce2 */
if(!s->budget--) { s->failed_pc=0x0c07bce2u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bce4;
P_0c07bce4: /* original 51f8, guest PC 0x0c07bce4 */
if(!s->budget--) { s->failed_pc=0x0c07bce4u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bce6;
P_0c07bce6: /* original 4100, guest PC 0x0c07bce6 */
if(!s->budget--) { s->failed_pc=0x0c07bce6u; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07bce8;
P_0c07bce8: /* original 7102, guest PC 0x0c07bce8 */
if(!s->budget--) { s->failed_pc=0x0c07bce8u; return 0; }
r[1]+=0x00000002u;
goto P_0c07bcea;
P_0c07bcea: /* original 410c, guest PC 0x0c07bcea */
if(!s->budget--) { s->failed_pc=0x0c07bceau; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07bcec;
P_0c07bcec: /* original 1f11, guest PC 0x0c07bcec */
if(!s->budget--) { s->failed_pc=0x0c07bcecu; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07bcee;
P_0c07bcee: /* original 1f54, guest PC 0x0c07bcee */
if(!s->budget--) { s->failed_pc=0x0c07bceeu; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf0;
P_0c07bcf0: /* original 54f1, guest PC 0x0c07bcf0 */
if(!s->budget--) { s->failed_pc=0x0c07bcf0u; return 0; }
r[4]=read(ram,r[15]+4,4);
goto P_0c07bcf2;
P_0c07bcf2: /* original 1f41, guest PC 0x0c07bcf2 */
if(!s->budget--) { s->failed_pc=0x0c07bcf2u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bcf4;
P_0c07bcf4: /* original 1f54, guest PC 0x0c07bcf4 */
if(!s->budget--) { s->failed_pc=0x0c07bcf4u; return 0; }
write(ram,r[15]+16,r[5],4);
goto P_0c07bcf6;
P_0c07bcf6: /* original a172, guest PC 0x0c07bcf6 */
if(!s->budget--) { s->failed_pc=0x0c07bcf6u; return 0; }
write(ram,r[15]+4,r[4],4);
goto P_0c07bfde;
P_0c07bcf8: /* original 1f41, guest PC 0x0c07bcf8 */
if(!s->budget--) { s->failed_pc=0x0c07bcf8u; return 0; }
write(ram,r[15]+4,r[4],4);
if(!vf3_matrix_family(0x0c07bcfau,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07bcfau; return 0; } return 1;
P_0c07bd14: /* original 63c3, guest PC 0x0c07bd14 */
if(!s->budget--) { s->failed_pc=0x0c07bd14u; return 0; }
r[3]=r[12];
goto P_0c07bd16;
P_0c07bd16: /* original 4308, guest PC 0x0c07bd16 */
if(!s->budget--) { s->failed_pc=0x0c07bd16u; return 0; }
r[3]<<=2;
goto P_0c07bd18;
P_0c07bd18: /* original 62c3, guest PC 0x0c07bd18 */
if(!s->budget--) { s->failed_pc=0x0c07bd18u; return 0; }
r[2]=r[12];
goto P_0c07bd1a;
P_0c07bd1a: /* original 332c, guest PC 0x0c07bd1a */
if(!s->budget--) { s->failed_pc=0x0c07bd1au; return 0; }
r[3]+=r[2];
goto P_0c07bd1c;
P_0c07bd1c: /* original 64c3, guest PC 0x0c07bd1c */
if(!s->budget--) { s->failed_pc=0x0c07bd1cu; return 0; }
r[4]=r[12];
goto P_0c07bd1e;
P_0c07bd1e: /* original 61f3, guest PC 0x0c07bd1e */
if(!s->budget--) { s->failed_pc=0x0c07bd1eu; return 0; }
r[1]=r[15];
goto P_0c07bd20;
P_0c07bd20: /* original 4308, guest PC 0x0c07bd20 */
if(!s->budget--) { s->failed_pc=0x0c07bd20u; return 0; }
r[3]<<=2;
goto P_0c07bd22;
P_0c07bd22: /* original 4408, guest PC 0x0c07bd22 */
if(!s->budget--) { s->failed_pc=0x0c07bd22u; return 0; }
r[4]<<=2;
goto P_0c07bd24;
P_0c07bd24: /* original 717c, guest PC 0x0c07bd24 */
if(!s->budget--) { s->failed_pc=0x0c07bd24u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bd26;
P_0c07bd26: /* original 314c, guest PC 0x0c07bd26 */
if(!s->budget--) { s->failed_pc=0x0c07bd26u; return 0; }
r[1]+=r[4];
goto P_0c07bd28;
P_0c07bd28: /* original 4300, guest PC 0x0c07bd28 */
if(!s->budget--) { s->failed_pc=0x0c07bd28u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2a;
P_0c07bd2a: /* original 730f, guest PC 0x0c07bd2a */
if(!s->budget--) { s->failed_pc=0x0c07bd2au; return 0; }
r[3]+=0x0000000fu;
goto P_0c07bd2c;
P_0c07bd2c: /* original 4300, guest PC 0x0c07bd2c */
if(!s->budget--) { s->failed_pc=0x0c07bd2cu; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07bd2e;
P_0c07bd2e: /* original 1f33, guest PC 0x0c07bd2e */
if(!s->budget--) { s->failed_pc=0x0c07bd2eu; return 0; }
write(ram,r[15]+12,r[3],4);
goto P_0c07bd30;
P_0c07bd30: /* original 52ff, guest PC 0x0c07bd30 */
if(!s->budget--) { s->failed_pc=0x0c07bd30u; return 0; }
r[2]=read(ram,r[15]+60,4);
goto P_0c07bd32;
P_0c07bd32: /* original 6112, guest PC 0x0c07bd32 */
if(!s->budget--) { s->failed_pc=0x0c07bd32u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd34;
P_0c07bd34: /* original 324c, guest PC 0x0c07bd34 */
if(!s->budget--) { s->failed_pc=0x0c07bd34u; return 0; }
r[2]+=r[4];
goto P_0c07bd36;
P_0c07bd36: /* original 5222, guest PC 0x0c07bd36 */
if(!s->budget--) { s->failed_pc=0x0c07bd36u; return 0; }
r[2]=read(ram,r[2]+8,4);
goto P_0c07bd38;
P_0c07bd38: /* original 3210, guest PC 0x0c07bd38 */
if(!s->budget--) { s->failed_pc=0x0c07bd38u; return 0; }
r[17]=(r[17]&~1u)|((r[2]==r[1])!=0);
goto P_0c07bd3a;
P_0c07bd3a: /* original 8b01, guest PC 0x0c07bd3a */
if(!s->budget--) { s->failed_pc=0x0c07bd3au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bd40; }
goto P_0c07bd3c;
P_0c07bd3c: /* original a0a0, guest PC 0x0c07bd3c */
if(!s->budget--) { s->failed_pc=0x0c07bd3cu; return 0; }
goto P_0c07be80;
P_0c07bd3e: /* original 0009, guest PC 0x0c07bd3e */
if(!s->budget--) { s->failed_pc=0x0c07bd3eu; return 0; }
goto P_0c07bd40;
P_0c07bd40: /* original 50f8, guest PC 0x0c07bd40 */
if(!s->budget--) { s->failed_pc=0x0c07bd40u; return 0; }
r[0]=read(ram,r[15]+32,4);
goto P_0c07bd42;
P_0c07bd42: /* original 8801, guest PC 0x0c07bd42 */
if(!s->budget--) { s->failed_pc=0x0c07bd42u; return 0; }
r[17]=(r[17]&~1u)|((r[0]==0x00000001u)!=0);
goto P_0c07bd44;
P_0c07bd44: /* original 8901, guest PC 0x0c07bd44 */
if(!s->budget--) { s->failed_pc=0x0c07bd44u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bd4a; }
goto P_0c07bd46;
P_0c07bd46: /* original a09b, guest PC 0x0c07bd46 */
if(!s->budget--) { s->failed_pc=0x0c07bd46u; return 0; }
goto P_0c07be80;
P_0c07bd48: /* original 0009, guest PC 0x0c07bd48 */
if(!s->budget--) { s->failed_pc=0x0c07bd48u; return 0; }
goto P_0c07bd4a;
P_0c07bd4a: /* original 62f3, guest PC 0x0c07bd4a */
if(!s->budget--) { s->failed_pc=0x0c07bd4au; return 0; }
r[2]=r[15];
goto P_0c07bd4c;
P_0c07bd4c: /* original 63c3, guest PC 0x0c07bd4c */
if(!s->budget--) { s->failed_pc=0x0c07bd4cu; return 0; }
r[3]=r[12];
goto P_0c07bd4e;
P_0c07bd4e: /* original 727c, guest PC 0x0c07bd4e */
if(!s->budget--) { s->failed_pc=0x0c07bd4eu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bd50;
P_0c07bd50: /* original 4308, guest PC 0x0c07bd50 */
if(!s->budget--) { s->failed_pc=0x0c07bd50u; return 0; }
r[3]<<=2;
goto P_0c07bd52;
P_0c07bd52: /* original 332c, guest PC 0x0c07bd52 */
if(!s->budget--) { s->failed_pc=0x0c07bd52u; return 0; }
r[3]+=r[2];
goto P_0c07bd54;
P_0c07bd54: /* original 6132, guest PC 0x0c07bd54 */
if(!s->budget--) { s->failed_pc=0x0c07bd54u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bd56;
P_0c07bd56: /* original 31a3, guest PC 0x0c07bd56 */
if(!s->budget--) { s->failed_pc=0x0c07bd56u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[10])!=0);
goto P_0c07bd58;
P_0c07bd58: /* original 8b3f, guest PC 0x0c07bd58 */
if(!s->budget--) { s->failed_pc=0x0c07bd58u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bdda; }
goto P_0c07bd5a;
P_0c07bd5a: /* original 60c3, guest PC 0x0c07bd5a */
if(!s->budget--) { s->failed_pc=0x0c07bd5au; return 0; }
r[0]=r[12];
goto P_0c07bd5c;
P_0c07bd5c: /* original 63f3, guest PC 0x0c07bd5c */
if(!s->budget--) { s->failed_pc=0x0c07bd5cu; return 0; }
r[3]=r[15];
goto P_0c07bd5e;
P_0c07bd5e: /* original 4008, guest PC 0x0c07bd5e */
if(!s->budget--) { s->failed_pc=0x0c07bd5eu; return 0; }
r[0]<<=2;
goto P_0c07bd60;
P_0c07bd60: /* original 7374, guest PC 0x0c07bd60 */
if(!s->budget--) { s->failed_pc=0x0c07bd60u; return 0; }
r[3]+=0x00000074u;
goto P_0c07bd62;
P_0c07bd62: /* original 1f06, guest PC 0x0c07bd62 */
if(!s->budget--) { s->failed_pc=0x0c07bd62u; return 0; }
write(ram,r[15]+24,r[0],4);
goto P_0c07bd64;
P_0c07bd64: /* original 303c, guest PC 0x0c07bd64 */
if(!s->budget--) { s->failed_pc=0x0c07bd64u; return 0; }
r[0]+=r[3];
goto P_0c07bd66;
P_0c07bd66: /* original 1f05, guest PC 0x0c07bd66 */
if(!s->budget--) { s->failed_pc=0x0c07bd66u; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bd68;
P_0c07bd68: /* original 2f06, guest PC 0x0c07bd68 */
if(!s->budget--) { s->failed_pc=0x0c07bd68u; return 0; }
tmp=r[0]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bd6a;
P_0c07bd6a: /* original 9297, guest PC 0x0c07bd6a */
if(!s->budget--) { s->failed_pc=0x0c07bd6au; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07bd6c;
P_0c07bd6c: /* original 51f7, guest PC 0x0c07bd6c */
if(!s->budget--) { s->failed_pc=0x0c07bd6cu; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bd6e;
P_0c07bd6e: /* original 32fc, guest PC 0x0c07bd6e */
if(!s->budget--) { s->failed_pc=0x0c07bd6eu; return 0; }
r[2]+=r[15];
goto P_0c07bd70;
P_0c07bd70: /* original 312c, guest PC 0x0c07bd70 */
if(!s->budget--) { s->failed_pc=0x0c07bd70u; return 0; }
r[1]+=r[2];
goto P_0c07bd72;
P_0c07bd72: /* original 1f1f, guest PC 0x0c07bd72 */
if(!s->budget--) { s->failed_pc=0x0c07bd72u; return 0; }
write(ram,r[15]+60,r[1],4);
goto P_0c07bd74;
P_0c07bd74: /* original d34c, guest PC 0x0c07bd74 */
if(!s->budget--) { s->failed_pc=0x0c07bd74u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07bd76;
P_0c07bd76: /* original 6112, guest PC 0x0c07bd76 */
if(!s->budget--) { s->failed_pc=0x0c07bd76u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bd78;
P_0c07bd78: /* original 430b, guest PC 0x0c07bd78 */
if(!s->budget--) { s->failed_pc=0x0c07bd78u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bd7cu;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bd7cu) { target=s->pc; goto dispatch; }
goto P_0c07bd7c;
P_0c07bd7a: /* original 60a3, guest PC 0x0c07bd7a */
if(!s->budget--) { s->failed_pc=0x0c07bd7au; return 0; }
r[0]=r[10];
goto P_0c07bd7c;
P_0c07bd7c: /* original 64c3, guest PC 0x0c07bd7c */
if(!s->budget--) { s->failed_pc=0x0c07bd7cu; return 0; }
r[4]=r[12];
goto P_0c07bd7e;
P_0c07bd7e: /* original 61f6, guest PC 0x0c07bd7e */
if(!s->budget--) { s->failed_pc=0x0c07bd7eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[1]=tmp;
goto P_0c07bd80;
P_0c07bd80: /* original 4408, guest PC 0x0c07bd80 */
if(!s->budget--) { s->failed_pc=0x0c07bd80u; return 0; }
r[4]<<=2;
goto P_0c07bd82;
P_0c07bd82: /* original 63c3, guest PC 0x0c07bd82 */
if(!s->budget--) { s->failed_pc=0x0c07bd82u; return 0; }
r[3]=r[12];
goto P_0c07bd84;
P_0c07bd84: /* original 343c, guest PC 0x0c07bd84 */
if(!s->budget--) { s->failed_pc=0x0c07bd84u; return 0; }
r[4]+=r[3];
goto P_0c07bd86;
P_0c07bd86: /* original 2102, guest PC 0x0c07bd86 */
if(!s->budget--) { s->failed_pc=0x0c07bd86u; return 0; }
write(ram,r[1],r[0],4);
goto P_0c07bd88;
P_0c07bd88: /* original 4408, guest PC 0x0c07bd88 */
if(!s->budget--) { s->failed_pc=0x0c07bd88u; return 0; }
r[4]<<=2;
goto P_0c07bd8a;
P_0c07bd8a: /* original 9188, guest PC 0x0c07bd8a */
if(!s->budget--) { s->failed_pc=0x0c07bd8au; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07bd8c;
P_0c07bd8c: /* original 2fe6, guest PC 0x0c07bd8c */
if(!s->budget--) { s->failed_pc=0x0c07bd8cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bd8e;
P_0c07bd8e: /* original 4400, guest PC 0x0c07bd8e */
if(!s->budget--) { s->failed_pc=0x0c07bd8eu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd90;
P_0c07bd90: /* original 50f6, guest PC 0x0c07bd90 */
if(!s->budget--) { s->failed_pc=0x0c07bd90u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07bd92;
P_0c07bd92: /* original 740d, guest PC 0x0c07bd92 */
if(!s->budget--) { s->failed_pc=0x0c07bd92u; return 0; }
r[4]+=0x0000000du;
goto P_0c07bd94;
P_0c07bd94: /* original d345, guest PC 0x0c07bd94 */
if(!s->budget--) { s->failed_pc=0x0c07bd94u; return 0; }
r[3]=read(ram,0x0c07beacu,4);
goto P_0c07bd96;
P_0c07bd96: /* original 4400, guest PC 0x0c07bd96 */
if(!s->budget--) { s->failed_pc=0x0c07bd96u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07bd98;
P_0c07bd98: /* original 6002, guest PC 0x0c07bd98 */
if(!s->budget--) { s->failed_pc=0x0c07bd98u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bd9a;
P_0c07bd9a: /* original 241b, guest PC 0x0c07bd9a */
if(!s->budget--) { s->failed_pc=0x0c07bd9au; return 0; }
r[4]|=r[1];
goto P_0c07bd9c;
P_0c07bd9c: /* original 66d3, guest PC 0x0c07bd9c */
if(!s->budget--) { s->failed_pc=0x0c07bd9cu; return 0; }
r[6]=r[13];
goto P_0c07bd9e;
P_0c07bd9e: /* original e700, guest PC 0x0c07bd9e */
if(!s->budget--) { s->failed_pc=0x0c07bd9eu; return 0; }
r[7]=0x00000000u;
goto P_0c07bda0;
P_0c07bda0: /* original 4008, guest PC 0x0c07bda0 */
if(!s->budget--) { s->failed_pc=0x0c07bda0u; return 0; }
r[0]<<=2;
goto P_0c07bda2;
P_0c07bda2: /* original 430b, guest PC 0x0c07bda2 */
if(!s->budget--) { s->failed_pc=0x0c07bda2u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bda6u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bda6u) { target=s->pc; goto dispatch; }
goto P_0c07bda6;
P_0c07bda4: /* original 059e, guest PC 0x0c07bda4 */
if(!s->budget--) { s->failed_pc=0x0c07bda4u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bda6;
P_0c07bda6: /* original 7f04, guest PC 0x0c07bda6 */
if(!s->budget--) { s->failed_pc=0x0c07bda6u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bda8;
P_0c07bda8: /* original 53f5, guest PC 0x0c07bda8 */
if(!s->budget--) { s->failed_pc=0x0c07bda8u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bdaa;
P_0c07bdaa: /* original 52fe, guest PC 0x0c07bdaa */
if(!s->budget--) { s->failed_pc=0x0c07bdaau; return 0; }
r[2]=read(ram,r[15]+56,4);
goto P_0c07bdac;
P_0c07bdac: /* original 6132, guest PC 0x0c07bdac */
if(!s->budget--) { s->failed_pc=0x0c07bdacu; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bdae;
P_0c07bdae: /* original 6322, guest PC 0x0c07bdae */
if(!s->budget--) { s->failed_pc=0x0c07bdaeu; return 0; }
tmp=read(ram,r[2],4);
r[3]=tmp;
goto P_0c07bdb0;
P_0c07bdb0: /* original 01a7, guest PC 0x0c07bdb0 */
if(!s->budget--) { s->failed_pc=0x0c07bdb0u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bdb2;
P_0c07bdb2: /* original 011a, guest PC 0x0c07bdb2 */
if(!s->budget--) { s->failed_pc=0x0c07bdb2u; return 0; }
r[1]=r[19];
goto P_0c07bdb4;
P_0c07bdb4: /* original 3318, guest PC 0x0c07bdb4 */
if(!s->budget--) { s->failed_pc=0x0c07bdb4u; return 0; }
r[3]-=r[1];
goto P_0c07bdb6;
P_0c07bdb6: /* original 2232, guest PC 0x0c07bdb6 */
if(!s->budget--) { s->failed_pc=0x0c07bdb6u; return 0; }
write(ram,r[2],r[3],4);
goto P_0c07bdb8;
P_0c07bdb8: /* original e10a, guest PC 0x0c07bdb8 */
if(!s->budget--) { s->failed_pc=0x0c07bdb8u; return 0; }
r[1]=0x0000000au;
goto P_0c07bdba;
P_0c07bdba: /* original 50f4, guest PC 0x0c07bdba */
if(!s->budget--) { s->failed_pc=0x0c07bdbau; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bdbc;
P_0c07bdbc: /* original 52f6, guest PC 0x0c07bdbc */
if(!s->budget--) { s->failed_pc=0x0c07bdbcu; return 0; }
r[2]=read(ram,r[15]+24,4);
goto P_0c07bdbe;
P_0c07bdbe: /* original 032e, guest PC 0x0c07bdbe */
if(!s->budget--) { s->failed_pc=0x0c07bdbeu; return 0; }
r[3]=read(ram,r[2]+r[0],4);
goto P_0c07bdc0;
P_0c07bdc0: /* original 3313, guest PC 0x0c07bdc0 */
if(!s->budget--) { s->failed_pc=0x0c07bdc0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[1])!=0);
goto P_0c07bdc2;
P_0c07bdc2: /* original 890a, guest PC 0x0c07bdc2 */
if(!s->budget--) { s->failed_pc=0x0c07bdc2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bdda; }
goto P_0c07bdc4;
P_0c07bdc4: /* original 54f3, guest PC 0x0c07bdc4 */
if(!s->budget--) { s->failed_pc=0x0c07bdc4u; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07bdc6;
P_0c07bdc6: /* original 66d3, guest PC 0x0c07bdc6 */
if(!s->budget--) { s->failed_pc=0x0c07bdc6u; return 0; }
r[6]=r[13];
goto P_0c07bdc8;
P_0c07bdc8: /* original 53f1, guest PC 0x0c07bdc8 */
if(!s->budget--) { s->failed_pc=0x0c07bdc8u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bdca;
P_0c07bdca: /* original e700, guest PC 0x0c07bdca */
if(!s->budget--) { s->failed_pc=0x0c07bdcau; return 0; }
r[7]=0x00000000u;
goto P_0c07bdcc;
P_0c07bdcc: /* original 2fe6, guest PC 0x0c07bdcc */
if(!s->budget--) { s->failed_pc=0x0c07bdccu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bdce;
P_0c07bdce: /* original 55fb, guest PC 0x0c07bdce */
if(!s->budget--) { s->failed_pc=0x0c07bdceu; return 0; }
r[5]=read(ram,r[15]+44,4);
goto P_0c07bdd0;
P_0c07bdd0: /* original 243b, guest PC 0x0c07bdd0 */
if(!s->budget--) { s->failed_pc=0x0c07bdd0u; return 0; }
r[4]|=r[3];
goto P_0c07bdd2;
P_0c07bdd2: /* original d236, guest PC 0x0c07bdd2 */
if(!s->budget--) { s->failed_pc=0x0c07bdd2u; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07bdd4;
P_0c07bdd4: /* original 420b, guest PC 0x0c07bdd4 */
if(!s->budget--) { s->failed_pc=0x0c07bdd4u; return 0; }
target=r[2];
r[16]=code_base|0x0c07bdd8u;
tmp=read(ram,r[5],4);
r[5]=tmp;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bdd8u) { target=s->pc; goto dispatch; }
goto P_0c07bdd8;
P_0c07bdd6: /* original 6552, guest PC 0x0c07bdd6 */
if(!s->budget--) { s->failed_pc=0x0c07bdd6u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bdd8;
P_0c07bdd8: /* original 7f04, guest PC 0x0c07bdd8 */
if(!s->budget--) { s->failed_pc=0x0c07bdd8u; return 0; }
r[15]+=0x00000004u;
goto P_0c07bdda;
P_0c07bdda: /* original 62f3, guest PC 0x0c07bdda */
if(!s->budget--) { s->failed_pc=0x0c07bddau; return 0; }
r[2]=r[15];
goto P_0c07bddc;
P_0c07bddc: /* original 63c3, guest PC 0x0c07bddc */
if(!s->budget--) { s->failed_pc=0x0c07bddcu; return 0; }
r[3]=r[12];
goto P_0c07bdde;
P_0c07bdde: /* original 727c, guest PC 0x0c07bdde */
if(!s->budget--) { s->failed_pc=0x0c07bddeu; return 0; }
r[2]+=0x0000007cu;
goto P_0c07bde0;
P_0c07bde0: /* original 4308, guest PC 0x0c07bde0 */
if(!s->budget--) { s->failed_pc=0x0c07bde0u; return 0; }
r[3]<<=2;
goto P_0c07bde2;
P_0c07bde2: /* original 332c, guest PC 0x0c07bde2 */
if(!s->budget--) { s->failed_pc=0x0c07bde2u; return 0; }
r[3]+=r[2];
goto P_0c07bde4;
P_0c07bde4: /* original 6032, guest PC 0x0c07bde4 */
if(!s->budget--) { s->failed_pc=0x0c07bde4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bde6;
P_0c07bde6: /* original e10a, guest PC 0x0c07bde6 */
if(!s->budget--) { s->failed_pc=0x0c07bde6u; return 0; }
r[1]=0x0000000au;
goto P_0c07bde8;
P_0c07bde8: /* original 3013, guest PC 0x0c07bde8 */
if(!s->budget--) { s->failed_pc=0x0c07bde8u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[0]>=(int32_t)r[1])!=0);
goto P_0c07bdea;
P_0c07bdea: /* original 8b26, guest PC 0x0c07bdea */
if(!s->budget--) { s->failed_pc=0x0c07bdeau; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07be3a; }
goto P_0c07bdec;
P_0c07bdec: /* original 61f3, guest PC 0x0c07bdec */
if(!s->budget--) { s->failed_pc=0x0c07bdecu; return 0; }
r[1]=r[15];
goto P_0c07bdee;
P_0c07bdee: /* original 64c3, guest PC 0x0c07bdee */
if(!s->budget--) { s->failed_pc=0x0c07bdeeu; return 0; }
r[4]=r[12];
goto P_0c07bdf0;
P_0c07bdf0: /* original 717c, guest PC 0x0c07bdf0 */
if(!s->budget--) { s->failed_pc=0x0c07bdf0u; return 0; }
r[1]+=0x0000007cu;
goto P_0c07bdf2;
P_0c07bdf2: /* original 60f3, guest PC 0x0c07bdf2 */
if(!s->budget--) { s->failed_pc=0x0c07bdf2u; return 0; }
r[0]=r[15];
goto P_0c07bdf4;
P_0c07bdf4: /* original 4408, guest PC 0x0c07bdf4 */
if(!s->budget--) { s->failed_pc=0x0c07bdf4u; return 0; }
r[4]<<=2;
goto P_0c07bdf6;
P_0c07bdf6: /* original 314c, guest PC 0x0c07bdf6 */
if(!s->budget--) { s->failed_pc=0x0c07bdf6u; return 0; }
r[1]+=r[4];
goto P_0c07bdf8;
P_0c07bdf8: /* original 7074, guest PC 0x0c07bdf8 */
if(!s->budget--) { s->failed_pc=0x0c07bdf8u; return 0; }
r[0]+=0x00000074u;
goto P_0c07bdfa;
P_0c07bdfa: /* original 304c, guest PC 0x0c07bdfa */
if(!s->budget--) { s->failed_pc=0x0c07bdfau; return 0; }
r[0]+=r[4];
goto P_0c07bdfc;
P_0c07bdfc: /* original 1f05, guest PC 0x0c07bdfc */
if(!s->budget--) { s->failed_pc=0x0c07bdfcu; return 0; }
write(ram,r[15]+20,r[0],4);
goto P_0c07bdfe;
P_0c07bdfe: /* original 6203, guest PC 0x0c07bdfe */
if(!s->budget--) { s->failed_pc=0x0c07bdfeu; return 0; }
r[2]=r[0];
goto P_0c07be00;
P_0c07be00: /* original 1f16, guest PC 0x0c07be00 */
if(!s->budget--) { s->failed_pc=0x0c07be00u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07be02;
P_0c07be02: /* original d329, guest PC 0x0c07be02 */
if(!s->budget--) { s->failed_pc=0x0c07be02u; return 0; }
r[3]=read(ram,0x0c07bea8u,4);
goto P_0c07be04;
P_0c07be04: /* original 6112, guest PC 0x0c07be04 */
if(!s->budget--) { s->failed_pc=0x0c07be04u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07be06;
P_0c07be06: /* original 430b, guest PC 0x0c07be06 */
if(!s->budget--) { s->failed_pc=0x0c07be06u; return 0; }
target=r[3];
r[16]=code_base|0x0c07be0au;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07be0au) { target=s->pc; goto dispatch; }
goto P_0c07be0a;
P_0c07be08: /* original e00a, guest PC 0x0c07be08 */
if(!s->budget--) { s->failed_pc=0x0c07be08u; return 0; }
r[0]=0x0000000au;
goto P_0c07be0a;
P_0c07be0a: /* original 2202, guest PC 0x0c07be0a */
if(!s->budget--) { s->failed_pc=0x0c07be0au; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07be0c;
P_0c07be0c: /* original e700, guest PC 0x0c07be0c */
if(!s->budget--) { s->failed_pc=0x0c07be0cu; return 0; }
r[7]=0x00000000u;
goto P_0c07be0e;
P_0c07be0e: /* original 54f3, guest PC 0x0c07be0e */
if(!s->budget--) { s->failed_pc=0x0c07be0eu; return 0; }
r[4]=read(ram,r[15]+12,4);
goto P_0c07be10;
P_0c07be10: /* original 66d3, guest PC 0x0c07be10 */
if(!s->budget--) { s->failed_pc=0x0c07be10u; return 0; }
r[6]=r[13];
goto P_0c07be12;
P_0c07be12: /* original 9344, guest PC 0x0c07be12 */
if(!s->budget--) { s->failed_pc=0x0c07be12u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be14;
P_0c07be14: /* original 2fe6, guest PC 0x0c07be14 */
if(!s->budget--) { s->failed_pc=0x0c07be14u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07be16;
P_0c07be16: /* original 50f6, guest PC 0x0c07be16 */
if(!s->budget--) { s->failed_pc=0x0c07be16u; return 0; }
r[0]=read(ram,r[15]+24,4);
goto P_0c07be18;
P_0c07be18: /* original 243b, guest PC 0x0c07be18 */
if(!s->budget--) { s->failed_pc=0x0c07be18u; return 0; }
r[4]|=r[3];
goto P_0c07be1a;
P_0c07be1a: /* original d224, guest PC 0x0c07be1a */
if(!s->budget--) { s->failed_pc=0x0c07be1au; return 0; }
r[2]=read(ram,0x0c07beacu,4);
goto P_0c07be1c;
P_0c07be1c: /* original 6002, guest PC 0x0c07be1c */
if(!s->budget--) { s->failed_pc=0x0c07be1cu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07be1e;
P_0c07be1e: /* original 4008, guest PC 0x0c07be1e */
if(!s->budget--) { s->failed_pc=0x0c07be1eu; return 0; }
r[0]<<=2;
goto P_0c07be20;
P_0c07be20: /* original 420b, guest PC 0x0c07be20 */
if(!s->budget--) { s->failed_pc=0x0c07be20u; return 0; }
target=r[2];
r[16]=code_base|0x0c07be24u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07be24u) { target=s->pc; goto dispatch; }
goto P_0c07be24;
P_0c07be22: /* original 059e, guest PC 0x0c07be22 */
if(!s->budget--) { s->failed_pc=0x0c07be22u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be24;
P_0c07be24: /* original 7f04, guest PC 0x0c07be24 */
if(!s->budget--) { s->failed_pc=0x0c07be24u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be26;
P_0c07be26: /* original 52f5, guest PC 0x0c07be26 */
if(!s->budget--) { s->failed_pc=0x0c07be26u; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07be28;
P_0c07be28: /* original 53f6, guest PC 0x0c07be28 */
if(!s->budget--) { s->failed_pc=0x0c07be28u; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07be2a;
P_0c07be2a: /* original 6222, guest PC 0x0c07be2a */
if(!s->budget--) { s->failed_pc=0x0c07be2au; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07be2c;
P_0c07be2c: /* original 6032, guest PC 0x0c07be2c */
if(!s->budget--) { s->failed_pc=0x0c07be2cu; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07be2e;
P_0c07be2e: /* original 6123, guest PC 0x0c07be2e */
if(!s->budget--) { s->failed_pc=0x0c07be2eu; return 0; }
r[1]=r[2];
goto P_0c07be30;
P_0c07be30: /* original 4208, guest PC 0x0c07be30 */
if(!s->budget--) { s->failed_pc=0x0c07be30u; return 0; }
r[2]<<=2;
goto P_0c07be32;
P_0c07be32: /* original 321c, guest PC 0x0c07be32 */
if(!s->budget--) { s->failed_pc=0x0c07be32u; return 0; }
r[2]+=r[1];
goto P_0c07be34;
P_0c07be34: /* original 4200, guest PC 0x0c07be34 */
if(!s->budget--) { s->failed_pc=0x0c07be34u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07be36;
P_0c07be36: /* original 3028, guest PC 0x0c07be36 */
if(!s->budget--) { s->failed_pc=0x0c07be36u; return 0; }
r[0]-=r[2];
goto P_0c07be38;
P_0c07be38: /* original 2302, guest PC 0x0c07be38 */
if(!s->budget--) { s->failed_pc=0x0c07be38u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07be3a;
P_0c07be3a: /* original 64c3, guest PC 0x0c07be3a */
if(!s->budget--) { s->failed_pc=0x0c07be3au; return 0; }
r[4]=r[12];
goto P_0c07be3c;
P_0c07be3c: /* original 4408, guest PC 0x0c07be3c */
if(!s->budget--) { s->failed_pc=0x0c07be3cu; return 0; }
r[4]<<=2;
goto P_0c07be3e;
P_0c07be3e: /* original 63c3, guest PC 0x0c07be3e */
if(!s->budget--) { s->failed_pc=0x0c07be3eu; return 0; }
r[3]=r[12];
goto P_0c07be40;
P_0c07be40: /* original 343c, guest PC 0x0c07be40 */
if(!s->budget--) { s->failed_pc=0x0c07be40u; return 0; }
r[4]+=r[3];
goto P_0c07be42;
P_0c07be42: /* original 60c3, guest PC 0x0c07be42 */
if(!s->budget--) { s->failed_pc=0x0c07be42u; return 0; }
r[0]=r[12];
goto P_0c07be44;
P_0c07be44: /* original 4408, guest PC 0x0c07be44 */
if(!s->budget--) { s->failed_pc=0x0c07be44u; return 0; }
r[4]<<=2;
goto P_0c07be46;
P_0c07be46: /* original 4008, guest PC 0x0c07be46 */
if(!s->budget--) { s->failed_pc=0x0c07be46u; return 0; }
r[0]<<=2;
goto P_0c07be48;
P_0c07be48: /* original 9229, guest PC 0x0c07be48 */
if(!s->budget--) { s->failed_pc=0x0c07be48u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9eu,2);
goto P_0c07be4a;
P_0c07be4a: /* original 2fe6, guest PC 0x0c07be4a */
if(!s->budget--) { s->failed_pc=0x0c07be4au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07be4c;
P_0c07be4c: /* original 4400, guest PC 0x0c07be4c */
if(!s->budget--) { s->failed_pc=0x0c07be4cu; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be4e;
P_0c07be4e: /* original 9325, guest PC 0x0c07be4e */
if(!s->budget--) { s->failed_pc=0x0c07be4eu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07be9cu,2);
goto P_0c07be50;
P_0c07be50: /* original 7411, guest PC 0x0c07be50 */
if(!s->budget--) { s->failed_pc=0x0c07be50u; return 0; }
r[4]+=0x00000011u;
goto P_0c07be52;
P_0c07be52: /* original 4400, guest PC 0x0c07be52 */
if(!s->budget--) { s->failed_pc=0x0c07be52u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be54;
P_0c07be54: /* original d115, guest PC 0x0c07be54 */
if(!s->budget--) { s->failed_pc=0x0c07be54u; return 0; }
r[1]=read(ram,0x0c07beacu,4);
goto P_0c07be56;
P_0c07be56: /* original 33fc, guest PC 0x0c07be56 */
if(!s->budget--) { s->failed_pc=0x0c07be56u; return 0; }
r[3]+=r[15];
goto P_0c07be58;
P_0c07be58: /* original 66d3, guest PC 0x0c07be58 */
if(!s->budget--) { s->failed_pc=0x0c07be58u; return 0; }
r[6]=r[13];
goto P_0c07be5a;
P_0c07be5a: /* original 003e, guest PC 0x0c07be5a */
if(!s->budget--) { s->failed_pc=0x0c07be5au; return 0; }
r[0]=read(ram,r[3]+r[0],4);
goto P_0c07be5c;
P_0c07be5c: /* original 242b, guest PC 0x0c07be5c */
if(!s->budget--) { s->failed_pc=0x0c07be5cu; return 0; }
r[4]|=r[2];
goto P_0c07be5e;
P_0c07be5e: /* original e700, guest PC 0x0c07be5e */
if(!s->budget--) { s->failed_pc=0x0c07be5eu; return 0; }
r[7]=0x00000000u;
goto P_0c07be60;
P_0c07be60: /* original 4008, guest PC 0x0c07be60 */
if(!s->budget--) { s->failed_pc=0x0c07be60u; return 0; }
r[0]<<=2;
goto P_0c07be62;
P_0c07be62: /* original 410b, guest PC 0x0c07be62 */
if(!s->budget--) { s->failed_pc=0x0c07be62u; return 0; }
target=r[1];
r[16]=code_base|0x0c07be66u;
r[5]=read(ram,r[9]+r[0],4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07be66u) { target=s->pc; goto dispatch; }
goto P_0c07be66;
P_0c07be64: /* original 059e, guest PC 0x0c07be64 */
if(!s->budget--) { s->failed_pc=0x0c07be64u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07be66;
P_0c07be66: /* original 7f04, guest PC 0x0c07be66 */
if(!s->budget--) { s->failed_pc=0x0c07be66u; return 0; }
r[15]+=0x00000004u;
goto P_0c07be68;
P_0c07be68: /* original 931a, guest PC 0x0c07be68 */
if(!s->budget--) { s->failed_pc=0x0c07be68u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea0u,2);
goto P_0c07be6a;
P_0c07be6a: /* original 60f2, guest PC 0x0c07be6a */
if(!s->budget--) { s->failed_pc=0x0c07be6au; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be6c;
P_0c07be6c: /* original 64c3, guest PC 0x0c07be6c */
if(!s->budget--) { s->failed_pc=0x0c07be6cu; return 0; }
r[4]=r[12];
goto P_0c07be6e;
P_0c07be6e: /* original 9218, guest PC 0x0c07be6e */
if(!s->budget--) { s->failed_pc=0x0c07be6eu; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea2u,2);
goto P_0c07be70;
P_0c07be70: /* original 4400, guest PC 0x0c07be70 */
if(!s->budget--) { s->failed_pc=0x0c07be70u; return 0; }
r[17]=(r[17]&~1u)|((r[4]>>31)!=0);
r[4]<<=1;
goto P_0c07be72;
P_0c07be72: /* original 330c, guest PC 0x0c07be72 */
if(!s->budget--) { s->failed_pc=0x0c07be72u; return 0; }
r[3]+=r[0];
goto P_0c07be74;
P_0c07be74: /* original 60f2, guest PC 0x0c07be74 */
if(!s->budget--) { s->failed_pc=0x0c07be74u; return 0; }
tmp=read(ram,r[15],4);
r[0]=tmp;
goto P_0c07be76;
P_0c07be76: /* original 334c, guest PC 0x0c07be76 */
if(!s->budget--) { s->failed_pc=0x0c07be76u; return 0; }
r[3]+=r[4];
goto P_0c07be78;
P_0c07be78: /* original 320c, guest PC 0x0c07be78 */
if(!s->budget--) { s->failed_pc=0x0c07be78u; return 0; }
r[2]+=r[0];
goto P_0c07be7a;
P_0c07be7a: /* original 324c, guest PC 0x0c07be7a */
if(!s->budget--) { s->failed_pc=0x0c07be7au; return 0; }
r[2]+=r[4];
goto P_0c07be7c;
P_0c07be7c: /* original 6121, guest PC 0x0c07be7c */
if(!s->budget--) { s->failed_pc=0x0c07be7cu; return 0; }
tmp=(uint32_t)(int32_t)(int16_t)read(ram,r[2],2);
r[1]=tmp;
goto P_0c07be7e;
P_0c07be7e: /* original 2311, guest PC 0x0c07be7e */
if(!s->budget--) { s->failed_pc=0x0c07be7eu; return 0; }
write(ram,r[3],r[1],2);
goto P_0c07be80;
P_0c07be80: /* original 50f4, guest PC 0x0c07be80 */
if(!s->budget--) { s->failed_pc=0x0c07be80u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07be82;
P_0c07be82: /* original 63c3, guest PC 0x0c07be82 */
if(!s->budget--) { s->failed_pc=0x0c07be82u; return 0; }
r[3]=r[12];
goto P_0c07be84;
P_0c07be84: /* original 4308, guest PC 0x0c07be84 */
if(!s->budget--) { s->failed_pc=0x0c07be84u; return 0; }
r[3]<<=2;
goto P_0c07be86;
P_0c07be86: /* original 033e, guest PC 0x0c07be86 */
if(!s->budget--) { s->failed_pc=0x0c07be86u; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07be88;
P_0c07be88: /* original 33a3, guest PC 0x0c07be88 */
if(!s->budget--) { s->failed_pc=0x0c07be88u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07be8a;
P_0c07be8a: /* original 8b54, guest PC 0x0c07be8a */
if(!s->budget--) { s->failed_pc=0x0c07be8au; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bf36; }
goto P_0c07be8c;
P_0c07be8c: /* original 930a, guest PC 0x0c07be8c */
if(!s->budget--) { s->failed_pc=0x0c07be8cu; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07bea4u,2);
goto P_0c07be8e;
P_0c07be8e: /* original 64c3, guest PC 0x0c07be8e */
if(!s->budget--) { s->failed_pc=0x0c07be8eu; return 0; }
r[4]=r[12];
goto P_0c07be90;
P_0c07be90: /* original 52f2, guest PC 0x0c07be90 */
if(!s->budget--) { s->failed_pc=0x0c07be90u; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07be92;
P_0c07be92: /* original 4408, guest PC 0x0c07be92 */
if(!s->budget--) { s->failed_pc=0x0c07be92u; return 0; }
r[4]<<=2;
goto P_0c07be94;
P_0c07be94: /* original 33fc, guest PC 0x0c07be94 */
if(!s->budget--) { s->failed_pc=0x0c07be94u; return 0; }
r[3]+=r[15];
goto P_0c07be96;
P_0c07be96: /* original 323c, guest PC 0x0c07be96 */
if(!s->budget--) { s->failed_pc=0x0c07be96u; return 0; }
r[2]+=r[3];
goto P_0c07be98;
P_0c07be98: /* original a00a, guest PC 0x0c07be98 */
if(!s->budget--) { s->failed_pc=0x0c07be98u; return 0; }
goto P_0c07beb0;
P_0c07be9a: /* original 0009, guest PC 0x0c07be9a */
if(!s->budget--) { s->failed_pc=0x0c07be9au; return 0; }
if(!vf3_matrix_family(0x0c07be9cu,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07be9cu; return 0; } return 1;
P_0c07beb0: /* original 324c, guest PC 0x0c07beb0 */
if(!s->budget--) { s->failed_pc=0x0c07beb0u; return 0; }
r[2]+=r[4];
goto P_0c07beb2;
P_0c07beb2: /* original 1f25, guest PC 0x0c07beb2 */
if(!s->budget--) { s->failed_pc=0x0c07beb2u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07beb4;
P_0c07beb4: /* original 90c6, guest PC 0x0c07beb4 */
if(!s->budget--) { s->failed_pc=0x0c07beb4u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c044u,2);
goto P_0c07beb6;
P_0c07beb6: /* original 51f2, guest PC 0x0c07beb6 */
if(!s->budget--) { s->failed_pc=0x0c07beb6u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07beb8;
P_0c07beb8: /* original 30fc, guest PC 0x0c07beb8 */
if(!s->budget--) { s->failed_pc=0x0c07beb8u; return 0; }
r[0]+=r[15];
goto P_0c07beba;
P_0c07beba: /* original 310c, guest PC 0x0c07beba */
if(!s->budget--) { s->failed_pc=0x0c07bebau; return 0; }
r[1]+=r[0];
goto P_0c07bebc;
P_0c07bebc: /* original 314c, guest PC 0x0c07bebc */
if(!s->budget--) { s->failed_pc=0x0c07bebcu; return 0; }
r[1]+=r[4];
goto P_0c07bebe;
P_0c07bebe: /* original 1f16, guest PC 0x0c07bebe */
if(!s->budget--) { s->failed_pc=0x0c07bebeu; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bec0;
P_0c07bec0: /* original 6112, guest PC 0x0c07bec0 */
if(!s->budget--) { s->failed_pc=0x0c07bec0u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bec2;
P_0c07bec2: /* original d365, guest PC 0x0c07bec2 */
if(!s->budget--) { s->failed_pc=0x0c07bec2u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bec4;
P_0c07bec4: /* original 430b, guest PC 0x0c07bec4 */
if(!s->budget--) { s->failed_pc=0x0c07bec4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bec8u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bec8u) { target=s->pc; goto dispatch; }
goto P_0c07bec8;
P_0c07bec6: /* original 60a3, guest PC 0x0c07bec6 */
if(!s->budget--) { s->failed_pc=0x0c07bec6u; return 0; }
r[0]=r[10];
goto P_0c07bec8;
P_0c07bec8: /* original 2202, guest PC 0x0c07bec8 */
if(!s->budget--) { s->failed_pc=0x0c07bec8u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07beca;
P_0c07beca: /* original 62c3, guest PC 0x0c07beca */
if(!s->budget--) { s->failed_pc=0x0c07becau; return 0; }
r[2]=r[12];
goto P_0c07becc;
P_0c07becc: /* original 4208, guest PC 0x0c07becc */
if(!s->budget--) { s->failed_pc=0x0c07beccu; return 0; }
r[2]<<=2;
goto P_0c07bece;
P_0c07bece: /* original 63c3, guest PC 0x0c07bece */
if(!s->budget--) { s->failed_pc=0x0c07beceu; return 0; }
r[3]=r[12];
goto P_0c07bed0;
P_0c07bed0: /* original 323c, guest PC 0x0c07bed0 */
if(!s->budget--) { s->failed_pc=0x0c07bed0u; return 0; }
r[2]+=r[3];
goto P_0c07bed2;
P_0c07bed2: /* original 51f1, guest PC 0x0c07bed2 */
if(!s->budget--) { s->failed_pc=0x0c07bed2u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bed4;
P_0c07bed4: /* original 4208, guest PC 0x0c07bed4 */
if(!s->budget--) { s->failed_pc=0x0c07bed4u; return 0; }
r[2]<<=2;
goto P_0c07bed6;
P_0c07bed6: /* original 66d3, guest PC 0x0c07bed6 */
if(!s->budget--) { s->failed_pc=0x0c07bed6u; return 0; }
r[6]=r[13];
goto P_0c07bed8;
P_0c07bed8: /* original 4200, guest PC 0x0c07bed8 */
if(!s->budget--) { s->failed_pc=0x0c07bed8u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07beda;
P_0c07beda: /* original 720d, guest PC 0x0c07beda */
if(!s->budget--) { s->failed_pc=0x0c07bedau; return 0; }
r[2]+=0x0000000du;
goto P_0c07bedc;
P_0c07bedc: /* original 4200, guest PC 0x0c07bedc */
if(!s->budget--) { s->failed_pc=0x0c07bedcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bede;
P_0c07bede: /* original 221b, guest PC 0x0c07bede */
if(!s->budget--) { s->failed_pc=0x0c07bedeu; return 0; }
r[2]|=r[1];
goto P_0c07bee0;
P_0c07bee0: /* original 1f2e, guest PC 0x0c07bee0 */
if(!s->budget--) { s->failed_pc=0x0c07bee0u; return 0; }
write(ram,r[15]+56,r[2],4);
goto P_0c07bee2;
P_0c07bee2: /* original e700, guest PC 0x0c07bee2 */
if(!s->budget--) { s->failed_pc=0x0c07bee2u; return 0; }
r[7]=0x00000000u;
goto P_0c07bee4;
P_0c07bee4: /* original 2fb6, guest PC 0x0c07bee4 */
if(!s->budget--) { s->failed_pc=0x0c07bee4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bee6;
P_0c07bee6: /* original 2fe6, guest PC 0x0c07bee6 */
if(!s->budget--) { s->failed_pc=0x0c07bee6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bee8;
P_0c07bee8: /* original 50f7, guest PC 0x0c07bee8 */
if(!s->budget--) { s->failed_pc=0x0c07bee8u; return 0; }
r[0]=read(ram,r[15]+28,4);
goto P_0c07beea;
P_0c07beea: /* original 6002, guest PC 0x0c07beea */
if(!s->budget--) { s->failed_pc=0x0c07beeau; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07beec;
P_0c07beec: /* original 4008, guest PC 0x0c07beec */
if(!s->budget--) { s->failed_pc=0x0c07beecu; return 0; }
r[0]<<=2;
goto P_0c07beee;
P_0c07beee: /* original 059e, guest PC 0x0c07beee */
if(!s->budget--) { s->failed_pc=0x0c07beeeu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bef0;
P_0c07bef0: /* original 480b, guest PC 0x0c07bef0 */
if(!s->budget--) { s->failed_pc=0x0c07bef0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bef4u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bef4u) { target=s->pc; goto dispatch; }
goto P_0c07bef4;
P_0c07bef2: /* original 6423, guest PC 0x0c07bef2 */
if(!s->budget--) { s->failed_pc=0x0c07bef2u; return 0; }
r[4]=r[2];
goto P_0c07bef4;
P_0c07bef4: /* original 7f08, guest PC 0x0c07bef4 */
if(!s->budget--) { s->failed_pc=0x0c07bef4u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bef6;
P_0c07bef6: /* original 6403, guest PC 0x0c07bef6 */
if(!s->budget--) { s->failed_pc=0x0c07bef6u; return 0; }
r[4]=r[0];
goto P_0c07bef8;
P_0c07bef8: /* original e030, guest PC 0x0c07bef8 */
if(!s->budget--) { s->failed_pc=0x0c07bef8u; return 0; }
r[0]=0x00000030u;
goto P_0c07befa;
P_0c07befa: /* original f4f7, guest PC 0x0c07befa */
if(!s->budget--) { s->failed_pc=0x0c07befau; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07befc;
P_0c07befc: /* original 52f5, guest PC 0x0c07befc */
if(!s->budget--) { s->failed_pc=0x0c07befcu; return 0; }
r[2]=read(ram,r[15]+20,4);
goto P_0c07befe;
P_0c07befe: /* original 53f6, guest PC 0x0c07befe */
if(!s->budget--) { s->failed_pc=0x0c07befeu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf00;
P_0c07bf00: /* original 6122, guest PC 0x0c07bf00 */
if(!s->budget--) { s->failed_pc=0x0c07bf00u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07bf02;
P_0c07bf02: /* original 6232, guest PC 0x0c07bf02 */
if(!s->budget--) { s->failed_pc=0x0c07bf02u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07bf04;
P_0c07bf04: /* original 01a7, guest PC 0x0c07bf04 */
if(!s->budget--) { s->failed_pc=0x0c07bf04u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07bf06;
P_0c07bf06: /* original 011a, guest PC 0x0c07bf06 */
if(!s->budget--) { s->failed_pc=0x0c07bf06u; return 0; }
r[1]=r[19];
goto P_0c07bf08;
P_0c07bf08: /* original 3218, guest PC 0x0c07bf08 */
if(!s->budget--) { s->failed_pc=0x0c07bf08u; return 0; }
r[2]-=r[1];
goto P_0c07bf0a;
P_0c07bf0a: /* original 2322, guest PC 0x0c07bf0a */
if(!s->budget--) { s->failed_pc=0x0c07bf0au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07bf0c;
P_0c07bf0c: /* original e20a, guest PC 0x0c07bf0c */
if(!s->budget--) { s->failed_pc=0x0c07bf0cu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf0e;
P_0c07bf0e: /* original 53f6, guest PC 0x0c07bf0e */
if(!s->budget--) { s->failed_pc=0x0c07bf0eu; return 0; }
r[3]=read(ram,r[15]+24,4);
goto P_0c07bf10;
P_0c07bf10: /* original 6132, guest PC 0x0c07bf10 */
if(!s->budget--) { s->failed_pc=0x0c07bf10u; return 0; }
tmp=read(ram,r[3],4);
r[1]=tmp;
goto P_0c07bf12;
P_0c07bf12: /* original 3123, guest PC 0x0c07bf12 */
if(!s->budget--) { s->failed_pc=0x0c07bf12u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07bf14;
P_0c07bf14: /* original 890f, guest PC 0x0c07bf14 */
if(!s->budget--) { s->failed_pc=0x0c07bf14u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bf36; }
goto P_0c07bf16;
P_0c07bf16: /* original 50f3, guest PC 0x0c07bf16 */
if(!s->budget--) { s->failed_pc=0x0c07bf16u; return 0; }
r[0]=read(ram,r[15]+12,4);
goto P_0c07bf18;
P_0c07bf18: /* original e700, guest PC 0x0c07bf18 */
if(!s->budget--) { s->failed_pc=0x0c07bf18u; return 0; }
r[7]=0x00000000u;
goto P_0c07bf1a;
P_0c07bf1a: /* original 53f1, guest PC 0x0c07bf1a */
if(!s->budget--) { s->failed_pc=0x0c07bf1au; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07bf1c;
P_0c07bf1c: /* original 66d3, guest PC 0x0c07bf1c */
if(!s->budget--) { s->failed_pc=0x0c07bf1cu; return 0; }
r[6]=r[13];
goto P_0c07bf1e;
P_0c07bf1e: /* original 203b, guest PC 0x0c07bf1e */
if(!s->budget--) { s->failed_pc=0x0c07bf1eu; return 0; }
r[0]|=r[3];
goto P_0c07bf20;
P_0c07bf20: /* original 1f03, guest PC 0x0c07bf20 */
if(!s->budget--) { s->failed_pc=0x0c07bf20u; return 0; }
write(ram,r[15]+12,r[0],4);
goto P_0c07bf22;
P_0c07bf22: /* original 2fb6, guest PC 0x0c07bf22 */
if(!s->budget--) { s->failed_pc=0x0c07bf22u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf24;
P_0c07bf24: /* original 2fe6, guest PC 0x0c07bf24 */
if(!s->budget--) { s->failed_pc=0x0c07bf24u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf26;
P_0c07bf26: /* original 55fc, guest PC 0x0c07bf26 */
if(!s->budget--) { s->failed_pc=0x0c07bf26u; return 0; }
r[5]=read(ram,r[15]+48,4);
goto P_0c07bf28;
P_0c07bf28: /* original 6552, guest PC 0x0c07bf28 */
if(!s->budget--) { s->failed_pc=0x0c07bf28u; return 0; }
tmp=read(ram,r[5],4);
r[5]=tmp;
goto P_0c07bf2a;
P_0c07bf2a: /* original 480b, guest PC 0x0c07bf2a */
if(!s->budget--) { s->failed_pc=0x0c07bf2au; return 0; }
target=r[8];
r[16]=code_base|0x0c07bf2eu;
r[4]=read(ram,r[15]+20,4);
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bf2eu) { target=s->pc; goto dispatch; }
goto P_0c07bf2e;
P_0c07bf2c: /* original 54f5, guest PC 0x0c07bf2c */
if(!s->budget--) { s->failed_pc=0x0c07bf2cu; return 0; }
r[4]=read(ram,r[15]+20,4);
goto P_0c07bf2e;
P_0c07bf2e: /* original 6403, guest PC 0x0c07bf2e */
if(!s->budget--) { s->failed_pc=0x0c07bf2eu; return 0; }
r[4]=r[0];
goto P_0c07bf30;
P_0c07bf30: /* original e030, guest PC 0x0c07bf30 */
if(!s->budget--) { s->failed_pc=0x0c07bf30u; return 0; }
r[0]=0x00000030u;
goto P_0c07bf32;
P_0c07bf32: /* original f4f7, guest PC 0x0c07bf32 */
if(!s->budget--) { s->failed_pc=0x0c07bf32u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf34;
P_0c07bf34: /* original 7f08, guest PC 0x0c07bf34 */
if(!s->budget--) { s->failed_pc=0x0c07bf34u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf36;
P_0c07bf36: /* original 50f4, guest PC 0x0c07bf36 */
if(!s->budget--) { s->failed_pc=0x0c07bf36u; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07bf38;
P_0c07bf38: /* original 63c3, guest PC 0x0c07bf38 */
if(!s->budget--) { s->failed_pc=0x0c07bf38u; return 0; }
r[3]=r[12];
goto P_0c07bf3a;
P_0c07bf3a: /* original 4308, guest PC 0x0c07bf3a */
if(!s->budget--) { s->failed_pc=0x0c07bf3au; return 0; }
r[3]<<=2;
goto P_0c07bf3c;
P_0c07bf3c: /* original 033e, guest PC 0x0c07bf3c */
if(!s->budget--) { s->failed_pc=0x0c07bf3cu; return 0; }
r[3]=read(ram,r[3]+r[0],4);
goto P_0c07bf3e;
P_0c07bf3e: /* original e20a, guest PC 0x0c07bf3e */
if(!s->budget--) { s->failed_pc=0x0c07bf3eu; return 0; }
r[2]=0x0000000au;
goto P_0c07bf40;
P_0c07bf40: /* original 3323, guest PC 0x0c07bf40 */
if(!s->budget--) { s->failed_pc=0x0c07bf40u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07bf42;
P_0c07bf42: /* original 8b30, guest PC 0x0c07bf42 */
if(!s->budget--) { s->failed_pc=0x0c07bf42u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07bfa6; }
goto P_0c07bf44;
P_0c07bf44: /* original 937f, guest PC 0x0c07bf44 */
if(!s->budget--) { s->failed_pc=0x0c07bf44u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c046u,2);
goto P_0c07bf46;
P_0c07bf46: /* original 64c3, guest PC 0x0c07bf46 */
if(!s->budget--) { s->failed_pc=0x0c07bf46u; return 0; }
r[4]=r[12];
goto P_0c07bf48;
P_0c07bf48: /* original 51f2, guest PC 0x0c07bf48 */
if(!s->budget--) { s->failed_pc=0x0c07bf48u; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07bf4a;
P_0c07bf4a: /* original 4408, guest PC 0x0c07bf4a */
if(!s->budget--) { s->failed_pc=0x0c07bf4au; return 0; }
r[4]<<=2;
goto P_0c07bf4c;
P_0c07bf4c: /* original 33fc, guest PC 0x0c07bf4c */
if(!s->budget--) { s->failed_pc=0x0c07bf4cu; return 0; }
r[3]+=r[15];
goto P_0c07bf4e;
P_0c07bf4e: /* original 313c, guest PC 0x0c07bf4e */
if(!s->budget--) { s->failed_pc=0x0c07bf4eu; return 0; }
r[1]+=r[3];
goto P_0c07bf50;
P_0c07bf50: /* original 314c, guest PC 0x0c07bf50 */
if(!s->budget--) { s->failed_pc=0x0c07bf50u; return 0; }
r[1]+=r[4];
goto P_0c07bf52;
P_0c07bf52: /* original 1f13, guest PC 0x0c07bf52 */
if(!s->budget--) { s->failed_pc=0x0c07bf52u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07bf54;
P_0c07bf54: /* original 2f16, guest PC 0x0c07bf54 */
if(!s->budget--) { s->failed_pc=0x0c07bf54u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf56;
P_0c07bf56: /* original 9277, guest PC 0x0c07bf56 */
if(!s->budget--) { s->failed_pc=0x0c07bf56u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c048u,2);
goto P_0c07bf58;
P_0c07bf58: /* original 51f3, guest PC 0x0c07bf58 */
if(!s->budget--) { s->failed_pc=0x0c07bf58u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07bf5a;
P_0c07bf5a: /* original 32fc, guest PC 0x0c07bf5a */
if(!s->budget--) { s->failed_pc=0x0c07bf5au; return 0; }
r[2]+=r[15];
goto P_0c07bf5c;
P_0c07bf5c: /* original 312c, guest PC 0x0c07bf5c */
if(!s->budget--) { s->failed_pc=0x0c07bf5cu; return 0; }
r[1]+=r[2];
goto P_0c07bf5e;
P_0c07bf5e: /* original 314c, guest PC 0x0c07bf5e */
if(!s->budget--) { s->failed_pc=0x0c07bf5eu; return 0; }
r[1]+=r[4];
goto P_0c07bf60;
P_0c07bf60: /* original 1f16, guest PC 0x0c07bf60 */
if(!s->budget--) { s->failed_pc=0x0c07bf60u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf62;
P_0c07bf62: /* original d33d, guest PC 0x0c07bf62 */
if(!s->budget--) { s->failed_pc=0x0c07bf62u; return 0; }
r[3]=read(ram,0x0c07c058u,4);
goto P_0c07bf64;
P_0c07bf64: /* original 6112, guest PC 0x0c07bf64 */
if(!s->budget--) { s->failed_pc=0x0c07bf64u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07bf66;
P_0c07bf66: /* original 430b, guest PC 0x0c07bf66 */
if(!s->budget--) { s->failed_pc=0x0c07bf66u; return 0; }
target=r[3];
r[16]=code_base|0x0c07bf6au;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bf6au) { target=s->pc; goto dispatch; }
goto P_0c07bf6a;
P_0c07bf68: /* original e00a, guest PC 0x0c07bf68 */
if(!s->budget--) { s->failed_pc=0x0c07bf68u; return 0; }
r[0]=0x0000000au;
goto P_0c07bf6a;
P_0c07bf6a: /* original 63f6, guest PC 0x0c07bf6a */
if(!s->budget--) { s->failed_pc=0x0c07bf6au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07bf6c;
P_0c07bf6c: /* original e700, guest PC 0x0c07bf6c */
if(!s->budget--) { s->failed_pc=0x0c07bf6cu; return 0; }
r[7]=0x00000000u;
goto P_0c07bf6e;
P_0c07bf6e: /* original 66d3, guest PC 0x0c07bf6e */
if(!s->budget--) { s->failed_pc=0x0c07bf6eu; return 0; }
r[6]=r[13];
goto P_0c07bf70;
P_0c07bf70: /* original 2302, guest PC 0x0c07bf70 */
if(!s->budget--) { s->failed_pc=0x0c07bf70u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bf72;
P_0c07bf72: /* original 51f1, guest PC 0x0c07bf72 */
if(!s->budget--) { s->failed_pc=0x0c07bf72u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07bf74;
P_0c07bf74: /* original 53f7, guest PC 0x0c07bf74 */
if(!s->budget--) { s->failed_pc=0x0c07bf74u; return 0; }
r[3]=read(ram,r[15]+28,4);
goto P_0c07bf76;
P_0c07bf76: /* original 213b, guest PC 0x0c07bf76 */
if(!s->budget--) { s->failed_pc=0x0c07bf76u; return 0; }
r[1]|=r[3];
goto P_0c07bf78;
P_0c07bf78: /* original 1f16, guest PC 0x0c07bf78 */
if(!s->budget--) { s->failed_pc=0x0c07bf78u; return 0; }
write(ram,r[15]+24,r[1],4);
goto P_0c07bf7a;
P_0c07bf7a: /* original 2fb6, guest PC 0x0c07bf7a */
if(!s->budget--) { s->failed_pc=0x0c07bf7au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf7c;
P_0c07bf7c: /* original 2fe6, guest PC 0x0c07bf7c */
if(!s->budget--) { s->failed_pc=0x0c07bf7cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bf7e;
P_0c07bf7e: /* original 50f5, guest PC 0x0c07bf7e */
if(!s->budget--) { s->failed_pc=0x0c07bf7eu; return 0; }
r[0]=read(ram,r[15]+20,4);
goto P_0c07bf80;
P_0c07bf80: /* original 6002, guest PC 0x0c07bf80 */
if(!s->budget--) { s->failed_pc=0x0c07bf80u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bf82;
P_0c07bf82: /* original 4008, guest PC 0x0c07bf82 */
if(!s->budget--) { s->failed_pc=0x0c07bf82u; return 0; }
r[0]<<=2;
goto P_0c07bf84;
P_0c07bf84: /* original 059e, guest PC 0x0c07bf84 */
if(!s->budget--) { s->failed_pc=0x0c07bf84u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bf86;
P_0c07bf86: /* original 480b, guest PC 0x0c07bf86 */
if(!s->budget--) { s->failed_pc=0x0c07bf86u; return 0; }
target=r[8];
r[16]=code_base|0x0c07bf8au;
r[4]=r[1];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bf8au) { target=s->pc; goto dispatch; }
goto P_0c07bf8a;
P_0c07bf88: /* original 6413, guest PC 0x0c07bf88 */
if(!s->budget--) { s->failed_pc=0x0c07bf88u; return 0; }
r[4]=r[1];
goto P_0c07bf8a;
P_0c07bf8a: /* original 7f08, guest PC 0x0c07bf8a */
if(!s->budget--) { s->failed_pc=0x0c07bf8au; return 0; }
r[15]+=0x00000008u;
goto P_0c07bf8c;
P_0c07bf8c: /* original 6403, guest PC 0x0c07bf8c */
if(!s->budget--) { s->failed_pc=0x0c07bf8cu; return 0; }
r[4]=r[0];
goto P_0c07bf8e;
P_0c07bf8e: /* original e030, guest PC 0x0c07bf8e */
if(!s->budget--) { s->failed_pc=0x0c07bf8eu; return 0; }
r[0]=0x00000030u;
goto P_0c07bf90;
P_0c07bf90: /* original f4f7, guest PC 0x0c07bf90 */
if(!s->budget--) { s->failed_pc=0x0c07bf90u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bf92;
P_0c07bf92: /* original 52f3, guest PC 0x0c07bf92 */
if(!s->budget--) { s->failed_pc=0x0c07bf92u; return 0; }
r[2]=read(ram,r[15]+12,4);
goto P_0c07bf94;
P_0c07bf94: /* original 53f5, guest PC 0x0c07bf94 */
if(!s->budget--) { s->failed_pc=0x0c07bf94u; return 0; }
r[3]=read(ram,r[15]+20,4);
goto P_0c07bf96;
P_0c07bf96: /* original 6222, guest PC 0x0c07bf96 */
if(!s->budget--) { s->failed_pc=0x0c07bf96u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07bf98;
P_0c07bf98: /* original 6032, guest PC 0x0c07bf98 */
if(!s->budget--) { s->failed_pc=0x0c07bf98u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07bf9a;
P_0c07bf9a: /* original 6123, guest PC 0x0c07bf9a */
if(!s->budget--) { s->failed_pc=0x0c07bf9au; return 0; }
r[1]=r[2];
goto P_0c07bf9c;
P_0c07bf9c: /* original 4208, guest PC 0x0c07bf9c */
if(!s->budget--) { s->failed_pc=0x0c07bf9cu; return 0; }
r[2]<<=2;
goto P_0c07bf9e;
P_0c07bf9e: /* original 321c, guest PC 0x0c07bf9e */
if(!s->budget--) { s->failed_pc=0x0c07bf9eu; return 0; }
r[2]+=r[1];
goto P_0c07bfa0;
P_0c07bfa0: /* original 4200, guest PC 0x0c07bfa0 */
if(!s->budget--) { s->failed_pc=0x0c07bfa0u; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07bfa2;
P_0c07bfa2: /* original 3028, guest PC 0x0c07bfa2 */
if(!s->budget--) { s->failed_pc=0x0c07bfa2u; return 0; }
r[0]-=r[2];
goto P_0c07bfa4;
P_0c07bfa4: /* original 2302, guest PC 0x0c07bfa4 */
if(!s->budget--) { s->failed_pc=0x0c07bfa4u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07bfa6;
P_0c07bfa6: /* original 52f1, guest PC 0x0c07bfa6 */
if(!s->budget--) { s->failed_pc=0x0c07bfa6u; return 0; }
r[2]=read(ram,r[15]+4,4);
goto P_0c07bfa8;
P_0c07bfa8: /* original e700, guest PC 0x0c07bfa8 */
if(!s->budget--) { s->failed_pc=0x0c07bfa8u; return 0; }
r[7]=0x00000000u;
goto P_0c07bfaa;
P_0c07bfaa: /* original 53fb, guest PC 0x0c07bfaa */
if(!s->budget--) { s->failed_pc=0x0c07bfaau; return 0; }
r[3]=read(ram,r[15]+44,4);
goto P_0c07bfac;
P_0c07bfac: /* original 66d3, guest PC 0x0c07bfac */
if(!s->budget--) { s->failed_pc=0x0c07bfacu; return 0; }
r[6]=r[13];
goto P_0c07bfae;
P_0c07bfae: /* original 223b, guest PC 0x0c07bfae */
if(!s->budget--) { s->failed_pc=0x0c07bfaeu; return 0; }
r[2]|=r[3];
goto P_0c07bfb0;
P_0c07bfb0: /* original 1f23, guest PC 0x0c07bfb0 */
if(!s->budget--) { s->failed_pc=0x0c07bfb0u; return 0; }
write(ram,r[15]+12,r[2],4);
goto P_0c07bfb2;
P_0c07bfb2: /* original 2fb6, guest PC 0x0c07bfb2 */
if(!s->budget--) { s->failed_pc=0x0c07bfb2u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bfb4;
P_0c07bfb4: /* original 2fe6, guest PC 0x0c07bfb4 */
if(!s->budget--) { s->failed_pc=0x0c07bfb4u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bfb6;
P_0c07bfb6: /* original 50fb, guest PC 0x0c07bfb6 */
if(!s->budget--) { s->failed_pc=0x0c07bfb6u; return 0; }
r[0]=read(ram,r[15]+44,4);
goto P_0c07bfb8;
P_0c07bfb8: /* original 6002, guest PC 0x0c07bfb8 */
if(!s->budget--) { s->failed_pc=0x0c07bfb8u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07bfba;
P_0c07bfba: /* original 4008, guest PC 0x0c07bfba */
if(!s->budget--) { s->failed_pc=0x0c07bfbau; return 0; }
r[0]<<=2;
goto P_0c07bfbc;
P_0c07bfbc: /* original 059e, guest PC 0x0c07bfbc */
if(!s->budget--) { s->failed_pc=0x0c07bfbcu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07bfbe;
P_0c07bfbe: /* original 480b, guest PC 0x0c07bfbe */
if(!s->budget--) { s->failed_pc=0x0c07bfbeu; return 0; }
target=r[8];
r[16]=code_base|0x0c07bfc2u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07bfc2u) { target=s->pc; goto dispatch; }
goto P_0c07bfc2;
P_0c07bfc0: /* original 6423, guest PC 0x0c07bfc0 */
if(!s->budget--) { s->failed_pc=0x0c07bfc0u; return 0; }
r[4]=r[2];
goto P_0c07bfc2;
P_0c07bfc2: /* original 7f08, guest PC 0x0c07bfc2 */
if(!s->budget--) { s->failed_pc=0x0c07bfc2u; return 0; }
r[15]+=0x00000008u;
goto P_0c07bfc4;
P_0c07bfc4: /* original 6403, guest PC 0x0c07bfc4 */
if(!s->budget--) { s->failed_pc=0x0c07bfc4u; return 0; }
r[4]=r[0];
goto P_0c07bfc6;
P_0c07bfc6: /* original e030, guest PC 0x0c07bfc6 */
if(!s->budget--) { s->failed_pc=0x0c07bfc6u; return 0; }
r[0]=0x00000030u;
goto P_0c07bfc8;
P_0c07bfc8: /* original f4f7, guest PC 0x0c07bfc8 */
if(!s->budget--) { s->failed_pc=0x0c07bfc8u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07bfca;
P_0c07bfca: /* original 7c01, guest PC 0x0c07bfca */
if(!s->budget--) { s->failed_pc=0x0c07bfcau; return 0; }
r[12]+=0x00000001u;
goto P_0c07bfcc;
P_0c07bfcc: /* original 53f9, guest PC 0x0c07bfcc */
if(!s->budget--) { s->failed_pc=0x0c07bfccu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07bfce;
P_0c07bfce: /* original 7304, guest PC 0x0c07bfce */
if(!s->budget--) { s->failed_pc=0x0c07bfceu; return 0; }
r[3]+=0x00000004u;
goto P_0c07bfd0;
P_0c07bfd0: /* original 1f39, guest PC 0x0c07bfd0 */
if(!s->budget--) { s->failed_pc=0x0c07bfd0u; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07bfd2;
P_0c07bfd2: /* original 52fb, guest PC 0x0c07bfd2 */
if(!s->budget--) { s->failed_pc=0x0c07bfd2u; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07bfd4;
P_0c07bfd4: /* original 7250, guest PC 0x0c07bfd4 */
if(!s->budget--) { s->failed_pc=0x0c07bfd4u; return 0; }
r[2]+=0x00000050u;
goto P_0c07bfd6;
P_0c07bfd6: /* original 1f2b, guest PC 0x0c07bfd6 */
if(!s->budget--) { s->failed_pc=0x0c07bfd6u; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07bfd8;
P_0c07bfd8: /* original 51f7, guest PC 0x0c07bfd8 */
if(!s->budget--) { s->failed_pc=0x0c07bfd8u; return 0; }
r[1]=read(ram,r[15]+28,4);
goto P_0c07bfda;
P_0c07bfda: /* original 7150, guest PC 0x0c07bfda */
if(!s->budget--) { s->failed_pc=0x0c07bfdau; return 0; }
r[1]+=0x00000050u;
goto P_0c07bfdc;
P_0c07bfdc: /* original 1f17, guest PC 0x0c07bfdc */
if(!s->budget--) { s->failed_pc=0x0c07bfdcu; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07bfde;
P_0c07bfde: /* original e302, guest PC 0x0c07bfde */
if(!s->budget--) { s->failed_pc=0x0c07bfdeu; return 0; }
r[3]=0x00000002u;
goto P_0c07bfe0;
P_0c07bfe0: /* original 3c33, guest PC 0x0c07bfe0 */
if(!s->budget--) { s->failed_pc=0x0c07bfe0u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[12]>=(int32_t)r[3])!=0);
goto P_0c07bfe2;
P_0c07bfe2: /* original 8901, guest PC 0x0c07bfe2 */
if(!s->budget--) { s->failed_pc=0x0c07bfe2u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bfe8; }
goto P_0c07bfe4;
P_0c07bfe4: /* original ae96, guest PC 0x0c07bfe4 */
if(!s->budget--) { s->failed_pc=0x0c07bfe4u; return 0; }
goto P_0c07bd14;
P_0c07bfe6: /* original 0009, guest PC 0x0c07bfe6 */
if(!s->budget--) { s->failed_pc=0x0c07bfe6u; return 0; }
goto P_0c07bfe8;
P_0c07bfe8: /* original 51f8, guest PC 0x0c07bfe8 */
if(!s->budget--) { s->failed_pc=0x0c07bfe8u; return 0; }
r[1]=read(ram,r[15]+32,4);
goto P_0c07bfea;
P_0c07bfea: /* original 7101, guest PC 0x0c07bfea */
if(!s->budget--) { s->failed_pc=0x0c07bfeau; return 0; }
r[1]+=0x00000001u;
goto P_0c07bfec;
P_0c07bfec: /* original 1f18, guest PC 0x0c07bfec */
if(!s->budget--) { s->failed_pc=0x0c07bfecu; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07bfee;
P_0c07bfee: /* original 52f8, guest PC 0x0c07bfee */
if(!s->budget--) { s->failed_pc=0x0c07bfeeu; return 0; }
r[2]=read(ram,r[15]+32,4);
goto P_0c07bff0;
P_0c07bff0: /* original e302, guest PC 0x0c07bff0 */
if(!s->budget--) { s->failed_pc=0x0c07bff0u; return 0; }
r[3]=0x00000002u;
goto P_0c07bff2;
P_0c07bff2: /* original 3233, guest PC 0x0c07bff2 */
if(!s->budget--) { s->failed_pc=0x0c07bff2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[2]>=(int32_t)r[3])!=0);
goto P_0c07bff4;
P_0c07bff4: /* original 8901, guest PC 0x0c07bff4 */
if(!s->budget--) { s->failed_pc=0x0c07bff4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07bffa; }
goto P_0c07bff6;
P_0c07bff6: /* original ae64, guest PC 0x0c07bff6 */
if(!s->budget--) { s->failed_pc=0x0c07bff6u; return 0; }
goto P_0c07bcc2;
P_0c07bff8: /* original 0009, guest PC 0x0c07bff8 */
if(!s->budget--) { s->failed_pc=0x0c07bff8u; return 0; }
goto P_0c07bffa;
P_0c07bffa: /* original 2fb6, guest PC 0x0c07bffa */
if(!s->budget--) { s->failed_pc=0x0c07bffau; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07bffc;
P_0c07bffc: /* original e700, guest PC 0x0c07bffc */
if(!s->budget--) { s->failed_pc=0x0c07bffcu; return 0; }
r[7]=0x00000000u;
goto P_0c07bffe;
P_0c07bffe: /* original 2fe6, guest PC 0x0c07bffe */
if(!s->budget--) { s->failed_pc=0x0c07bffeu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c000;
P_0c07c000: /* original 9523, guest PC 0x0c07c000 */
if(!s->budget--) { s->failed_pc=0x0c07c000u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c002;
P_0c07c002: /* original 9423, guest PC 0x0c07c002 */
if(!s->budget--) { s->failed_pc=0x0c07c002u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04cu,2);
goto P_0c07c004;
P_0c07c004: /* original 480b, guest PC 0x0c07c004 */
if(!s->budget--) { s->failed_pc=0x0c07c004u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c008u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c008u) { target=s->pc; goto dispatch; }
goto P_0c07c008;
P_0c07c006: /* original 66d3, guest PC 0x0c07c006 */
if(!s->budget--) { s->failed_pc=0x0c07c006u; return 0; }
r[6]=r[13];
goto P_0c07c008;
P_0c07c008: /* original 6403, guest PC 0x0c07c008 */
if(!s->budget--) { s->failed_pc=0x0c07c008u; return 0; }
r[4]=r[0];
goto P_0c07c00a;
P_0c07c00a: /* original e030, guest PC 0x0c07c00a */
if(!s->budget--) { s->failed_pc=0x0c07c00au; return 0; }
r[0]=0x00000030u;
goto P_0c07c00c;
P_0c07c00c: /* original f4f7, guest PC 0x0c07c00c */
if(!s->budget--) { s->failed_pc=0x0c07c00cu; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c00e;
P_0c07c00e: /* original e700, guest PC 0x0c07c00e */
if(!s->budget--) { s->failed_pc=0x0c07c00eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c010;
P_0c07c010: /* original 2fb6, guest PC 0x0c07c010 */
if(!s->budget--) { s->failed_pc=0x0c07c010u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c012;
P_0c07c012: /* original 2fe6, guest PC 0x0c07c012 */
if(!s->budget--) { s->failed_pc=0x0c07c012u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c014;
P_0c07c014: /* original 951b, guest PC 0x0c07c014 */
if(!s->budget--) { s->failed_pc=0x0c07c014u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c016;
P_0c07c016: /* original 941b, guest PC 0x0c07c016 */
if(!s->budget--) { s->failed_pc=0x0c07c016u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c050u,2);
goto P_0c07c018;
P_0c07c018: /* original 480b, guest PC 0x0c07c018 */
if(!s->budget--) { s->failed_pc=0x0c07c018u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c01cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c01cu) { target=s->pc; goto dispatch; }
goto P_0c07c01c;
P_0c07c01a: /* original 66d3, guest PC 0x0c07c01a */
if(!s->budget--) { s->failed_pc=0x0c07c01au; return 0; }
r[6]=r[13];
goto P_0c07c01c;
P_0c07c01c: /* original 6403, guest PC 0x0c07c01c */
if(!s->budget--) { s->failed_pc=0x0c07c01cu; return 0; }
r[4]=r[0];
goto P_0c07c01e;
P_0c07c01e: /* original e030, guest PC 0x0c07c01e */
if(!s->budget--) { s->failed_pc=0x0c07c01eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c020;
P_0c07c020: /* original f4f7, guest PC 0x0c07c020 */
if(!s->budget--) { s->failed_pc=0x0c07c020u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c022;
P_0c07c022: /* original e700, guest PC 0x0c07c022 */
if(!s->budget--) { s->failed_pc=0x0c07c022u; return 0; }
r[7]=0x00000000u;
goto P_0c07c024;
P_0c07c024: /* original 2fb6, guest PC 0x0c07c024 */
if(!s->budget--) { s->failed_pc=0x0c07c024u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c026;
P_0c07c026: /* original 2fe6, guest PC 0x0c07c026 */
if(!s->budget--) { s->failed_pc=0x0c07c026u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c028;
P_0c07c028: /* original 950f, guest PC 0x0c07c028 */
if(!s->budget--) { s->failed_pc=0x0c07c028u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04au,2);
goto P_0c07c02a;
P_0c07c02a: /* original 9412, guest PC 0x0c07c02a */
if(!s->budget--) { s->failed_pc=0x0c07c02au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c052u,2);
goto P_0c07c02c;
P_0c07c02c: /* original 480b, guest PC 0x0c07c02c */
if(!s->budget--) { s->failed_pc=0x0c07c02cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c030u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c030u) { target=s->pc; goto dispatch; }
goto P_0c07c030;
P_0c07c02e: /* original 66d3, guest PC 0x0c07c02e */
if(!s->budget--) { s->failed_pc=0x0c07c02eu; return 0; }
r[6]=r[13];
goto P_0c07c030;
P_0c07c030: /* original 6403, guest PC 0x0c07c030 */
if(!s->budget--) { s->failed_pc=0x0c07c030u; return 0; }
r[4]=r[0];
goto P_0c07c032;
P_0c07c032: /* original e030, guest PC 0x0c07c032 */
if(!s->budget--) { s->failed_pc=0x0c07c032u; return 0; }
r[0]=0x00000030u;
goto P_0c07c034;
P_0c07c034: /* original f4f7, guest PC 0x0c07c034 */
if(!s->budget--) { s->failed_pc=0x0c07c034u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c036;
P_0c07c036: /* original e700, guest PC 0x0c07c036 */
if(!s->budget--) { s->failed_pc=0x0c07c036u; return 0; }
r[7]=0x00000000u;
goto P_0c07c038;
P_0c07c038: /* original 2fb6, guest PC 0x0c07c038 */
if(!s->budget--) { s->failed_pc=0x0c07c038u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c03a;
P_0c07c03a: /* original 2fe6, guest PC 0x0c07c03a */
if(!s->budget--) { s->failed_pc=0x0c07c03au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c03c;
P_0c07c03c: /* original 9507, guest PC 0x0c07c03c */
if(!s->budget--) { s->failed_pc=0x0c07c03cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c04eu,2);
goto P_0c07c03e;
P_0c07c03e: /* original 9409, guest PC 0x0c07c03e */
if(!s->budget--) { s->failed_pc=0x0c07c03eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c054u,2);
goto P_0c07c040;
P_0c07c040: /* original a00c, guest PC 0x0c07c040 */
if(!s->budget--) { s->failed_pc=0x0c07c040u; return 0; }
r[6]=r[13];
goto P_0c07c05c;
P_0c07c042: /* original 66d3, guest PC 0x0c07c042 */
if(!s->budget--) { s->failed_pc=0x0c07c042u; return 0; }
r[6]=r[13];
if(!vf3_matrix_family(0x0c07c044u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c044u; return 0; } return 1;
P_0c07c05c: /* original 480b, guest PC 0x0c07c05c */
if(!s->budget--) { s->failed_pc=0x0c07c05cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c060u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c060u) { target=s->pc; goto dispatch; }
goto P_0c07c060;
P_0c07c05e: /* original 0009, guest PC 0x0c07c05e */
if(!s->budget--) { s->failed_pc=0x0c07c05eu; return 0; }
goto P_0c07c060;
P_0c07c060: /* original 6403, guest PC 0x0c07c060 */
if(!s->budget--) { s->failed_pc=0x0c07c060u; return 0; }
r[4]=r[0];
goto P_0c07c062;
P_0c07c062: /* original e030, guest PC 0x0c07c062 */
if(!s->budget--) { s->failed_pc=0x0c07c062u; return 0; }
r[0]=0x00000030u;
goto P_0c07c064;
P_0c07c064: /* original f4f7, guest PC 0x0c07c064 */
if(!s->budget--) { s->failed_pc=0x0c07c064u; return 0; }
vf3_matrix_store(s,ram,15,r[4]+r[0]);
goto P_0c07c066;
P_0c07c066: /* original d329, guest PC 0x0c07c066 */
if(!s->budget--) { s->failed_pc=0x0c07c066u; return 0; }
r[3]=read(ram,0x0c07c10cu,4);
goto P_0c07c068;
P_0c07c068: /* original 944c, guest PC 0x0c07c068 */
if(!s->budget--) { s->failed_pc=0x0c07c068u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c104u,2);
goto P_0c07c06a;
P_0c07c06a: /* original 430b, guest PC 0x0c07c06a */
if(!s->budget--) { s->failed_pc=0x0c07c06au; return 0; }
target=r[3];
r[16]=code_base|0x0c07c06eu;
r[15]+=0x00000020u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c06eu) { target=s->pc; goto dispatch; }
goto P_0c07c06e;
P_0c07c06c: /* original 7f20, guest PC 0x0c07c06c */
if(!s->budget--) { s->failed_pc=0x0c07c06cu; return 0; }
r[15]+=0x00000020u;
goto P_0c07c06e;
P_0c07c06e: /* original 6d03, guest PC 0x0c07c06e */
if(!s->budget--) { s->failed_pc=0x0c07c06eu; return 0; }
r[13]=r[0];
goto P_0c07c070;
P_0c07c070: /* original 52d8, guest PC 0x0c07c070 */
if(!s->budget--) { s->failed_pc=0x0c07c070u; return 0; }
r[2]=read(ram,r[13]+32,4);
goto P_0c07c072;
P_0c07c072: /* original e040, guest PC 0x0c07c072 */
if(!s->budget--) { s->failed_pc=0x0c07c072u; return 0; }
r[0]=0x00000040u;
goto P_0c07c074;
P_0c07c074: /* original 64f3, guest PC 0x0c07c074 */
if(!s->budget--) { s->failed_pc=0x0c07c074u; return 0; }
r[4]=r[15];
goto P_0c07c076;
P_0c07c076: /* original 0f26, guest PC 0x0c07c076 */
if(!s->budget--) { s->failed_pc=0x0c07c076u; return 0; }
write(ram,r[15]+r[0],r[2],4);
goto P_0c07c078;
P_0c07c078: /* original c725, guest PC 0x0c07c078 */
if(!s->budget--) { s->failed_pc=0x0c07c078u; return 0; }
r[0]=code_base|0x0007c110u;
goto P_0c07c07a;
P_0c07c07a: /* original f308, guest PC 0x0c07c07a */
if(!s->budget--) { s->failed_pc=0x0c07c07au; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c07c;
P_0c07c07c: /* original e018, guest PC 0x0c07c07c */
if(!s->budget--) { s->failed_pc=0x0c07c07cu; return 0; }
r[0]=0x00000018u;
goto P_0c07c07e;
P_0c07c07e: /* original f6d6, guest PC 0x0c07c07e */
if(!s->budget--) { s->failed_pc=0x0c07c07eu; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c080;
P_0c07c080: /* original c724, guest PC 0x0c07c080 */
if(!s->budget--) { s->failed_pc=0x0c07c080u; return 0; }
r[0]=code_base|0x0007c114u;
goto P_0c07c082;
P_0c07c082: /* original f208, guest PC 0x0c07c082 */
if(!s->budget--) { s->failed_pc=0x0c07c082u; return 0; }
vf3_matrix_load(s,ram,2,r[0]);
goto P_0c07c084;
P_0c07c084: /* original e01c, guest PC 0x0c07c084 */
if(!s->budget--) { s->failed_pc=0x0c07c084u; return 0; }
r[0]=0x0000001cu;
goto P_0c07c086;
P_0c07c086: /* original f7d6, guest PC 0x0c07c086 */
if(!s->budget--) { s->failed_pc=0x0c07c086u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c088;
P_0c07c088: /* original f632, guest PC 0x0c07c088 */
if(!s->budget--) { s->failed_pc=0x0c07c088u; return 0; }
fr[6]=vf3_fpu_binary(fr[6],fr[3],r[18],'*');
goto P_0c07c08a;
P_0c07c08a: /* original c723, guest PC 0x0c07c08a */
if(!s->budget--) { s->failed_pc=0x0c07c08au; return 0; }
r[0]=code_base|0x0007c118u;
goto P_0c07c08c;
P_0c07c08c: /* original d323, guest PC 0x0c07c08c */
if(!s->budget--) { s->failed_pc=0x0c07c08cu; return 0; }
r[3]=read(ram,0x0c07c11cu,4);
goto P_0c07c08e;
P_0c07c08e: /* original f722, guest PC 0x0c07c08e */
if(!s->budget--) { s->failed_pc=0x0c07c08eu; return 0; }
fr[7]=vf3_fpu_binary(fr[7],fr[2],r[18],'*');
goto P_0c07c090;
P_0c07c090: /* original f808, guest PC 0x0c07c090 */
if(!s->budget--) { s->failed_pc=0x0c07c090u; return 0; }
vf3_matrix_load(s,ram,8,r[0]);
goto P_0c07c092;
P_0c07c092: /* original f5ec, guest PC 0x0c07c092 */
if(!s->budget--) { s->failed_pc=0x0c07c092u; return 0; }
vf3_matrix_move(s,5,14);
goto P_0c07c094;
P_0c07c094: /* original f4ec, guest PC 0x0c07c094 */
if(!s->budget--) { s->failed_pc=0x0c07c094u; return 0; }
vf3_matrix_move(s,4,14);
goto P_0c07c096;
P_0c07c096: /* original 430b, guest PC 0x0c07c096 */
if(!s->budget--) { s->failed_pc=0x0c07c096u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c09au;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c09au) { target=s->pc; goto dispatch; }
goto P_0c07c09a;
P_0c07c098: /* original 7440, guest PC 0x0c07c098 */
if(!s->budget--) { s->failed_pc=0x0c07c098u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c09a;
P_0c07c09a: /* original e014, guest PC 0x0c07c09a */
if(!s->budget--) { s->failed_pc=0x0c07c09au; return 0; }
r[0]=0x00000014u;
goto P_0c07c09c;
P_0c07c09c: /* original d320, guest PC 0x0c07c09c */
if(!s->budget--) { s->failed_pc=0x0c07c09cu; return 0; }
r[3]=read(ram,0x0c07c120u,4);
goto P_0c07c09e;
P_0c07c09e: /* original f9d6, guest PC 0x0c07c09e */
if(!s->budget--) { s->failed_pc=0x0c07c09eu; return 0; }
vf3_matrix_load(s,ram,9,r[13]+r[0]);
goto P_0c07c0a0;
P_0c07c0a0: /* original e010, guest PC 0x0c07c0a0 */
if(!s->budget--) { s->failed_pc=0x0c07c0a0u; return 0; }
r[0]=0x00000010u;
goto P_0c07c0a2;
P_0c07c0a2: /* original f8d6, guest PC 0x0c07c0a2 */
if(!s->budget--) { s->failed_pc=0x0c07c0a2u; return 0; }
vf3_matrix_load(s,ram,8,r[13]+r[0]);
goto P_0c07c0a4;
P_0c07c0a4: /* original e00c, guest PC 0x0c07c0a4 */
if(!s->budget--) { s->failed_pc=0x0c07c0a4u; return 0; }
r[0]=0x0000000cu;
goto P_0c07c0a6;
P_0c07c0a6: /* original f7d6, guest PC 0x0c07c0a6 */
if(!s->budget--) { s->failed_pc=0x0c07c0a6u; return 0; }
vf3_matrix_load(s,ram,7,r[13]+r[0]);
goto P_0c07c0a8;
P_0c07c0a8: /* original e008, guest PC 0x0c07c0a8 */
if(!s->budget--) { s->failed_pc=0x0c07c0a8u; return 0; }
r[0]=0x00000008u;
goto P_0c07c0aa;
P_0c07c0aa: /* original f6d6, guest PC 0x0c07c0aa */
if(!s->budget--) { s->failed_pc=0x0c07c0aau; return 0; }
vf3_matrix_load(s,ram,6,r[13]+r[0]);
goto P_0c07c0ac;
P_0c07c0ac: /* original e004, guest PC 0x0c07c0ac */
if(!s->budget--) { s->failed_pc=0x0c07c0acu; return 0; }
r[0]=0x00000004u;
goto P_0c07c0ae;
P_0c07c0ae: /* original f4d8, guest PC 0x0c07c0ae */
if(!s->budget--) { s->failed_pc=0x0c07c0aeu; return 0; }
vf3_matrix_load(s,ram,4,r[13]);
goto P_0c07c0b0;
P_0c07c0b0: /* original 64f3, guest PC 0x0c07c0b0 */
if(!s->budget--) { s->failed_pc=0x0c07c0b0u; return 0; }
r[4]=r[15];
goto P_0c07c0b2;
P_0c07c0b2: /* original f5d6, guest PC 0x0c07c0b2 */
if(!s->budget--) { s->failed_pc=0x0c07c0b2u; return 0; }
vf3_matrix_load(s,ram,5,r[13]+r[0]);
goto P_0c07c0b4;
P_0c07c0b4: /* original 430b, guest PC 0x0c07c0b4 */
if(!s->budget--) { s->failed_pc=0x0c07c0b4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c0b8u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c0b8u) { target=s->pc; goto dispatch; }
goto P_0c07c0b8;
P_0c07c0b6: /* original 7440, guest PC 0x0c07c0b6 */
if(!s->budget--) { s->failed_pc=0x0c07c0b6u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0b8;
P_0c07c0b8: /* original e068, guest PC 0x0c07c0b8 */
if(!s->budget--) { s->failed_pc=0x0c07c0b8u; return 0; }
r[0]=0x00000068u;
goto P_0c07c0ba;
P_0c07c0ba: /* original 64f3, guest PC 0x0c07c0ba */
if(!s->budget--) { s->failed_pc=0x0c07c0bau; return 0; }
r[4]=r[15];
goto P_0c07c0bc;
P_0c07c0bc: /* original 0fe6, guest PC 0x0c07c0bc */
if(!s->budget--) { s->failed_pc=0x0c07c0bcu; return 0; }
write(ram,r[15]+r[0],r[14],4);
goto P_0c07c0be;
P_0c07c0be: /* original e06c, guest PC 0x0c07c0be */
if(!s->budget--) { s->failed_pc=0x0c07c0beu; return 0; }
r[0]=0x0000006cu;
goto P_0c07c0c0;
P_0c07c0c0: /* original 9321, guest PC 0x0c07c0c0 */
if(!s->budget--) { s->failed_pc=0x0c07c0c0u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c106u,2);
goto P_0c07c0c2;
P_0c07c0c2: /* original 0f36, guest PC 0x0c07c0c2 */
if(!s->budget--) { s->failed_pc=0x0c07c0c2u; return 0; }
write(ram,r[15]+r[0],r[3],4);
goto P_0c07c0c4;
P_0c07c0c4: /* original c717, guest PC 0x0c07c0c4 */
if(!s->budget--) { s->failed_pc=0x0c07c0c4u; return 0; }
r[0]=code_base|0x0007c124u;
goto P_0c07c0c6;
P_0c07c0c6: /* original f308, guest PC 0x0c07c0c6 */
if(!s->budget--) { s->failed_pc=0x0c07c0c6u; return 0; }
vf3_matrix_load(s,ram,3,r[0]);
goto P_0c07c0c8;
P_0c07c0c8: /* original e070, guest PC 0x0c07c0c8 */
if(!s->budget--) { s->failed_pc=0x0c07c0c8u; return 0; }
r[0]=0x00000070u;
goto P_0c07c0ca;
P_0c07c0ca: /* original ff37, guest PC 0x0c07c0ca */
if(!s->budget--) { s->failed_pc=0x0c07c0cau; return 0; }
vf3_matrix_store(s,ram,3,r[15]+r[0]);
goto P_0c07c0cc;
P_0c07c0cc: /* original d316, guest PC 0x0c07c0cc */
if(!s->budget--) { s->failed_pc=0x0c07c0ccu; return 0; }
r[3]=read(ram,0x0c07c128u,4);
goto P_0c07c0ce;
P_0c07c0ce: /* original 430b, guest PC 0x0c07c0ce */
if(!s->budget--) { s->failed_pc=0x0c07c0ceu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c0d2u;
r[4]+=0x00000040u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c0d2u) { target=s->pc; goto dispatch; }
goto P_0c07c0d2;
P_0c07c0d0: /* original 7440, guest PC 0x0c07c0d0 */
if(!s->budget--) { s->failed_pc=0x0c07c0d0u; return 0; }
r[4]+=0x00000040u;
goto P_0c07c0d2;
P_0c07c0d2: /* original a0eb, guest PC 0x0c07c0d2 */
if(!s->budget--) { s->failed_pc=0x0c07c0d2u; return 0; }
goto P_0c07c2ac;
P_0c07c0d4: /* original 0009, guest PC 0x0c07c0d4 */
if(!s->budget--) { s->failed_pc=0x0c07c0d4u; return 0; }
goto P_0c07c0d6;
P_0c07c0d6: /* original a0ba, guest PC 0x0c07c0d6 */
if(!s->budget--) { s->failed_pc=0x0c07c0d6u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c24e;
P_0c07c0d8: /* original 1fe9, guest PC 0x0c07c0d8 */
if(!s->budget--) { s->failed_pc=0x0c07c0d8u; return 0; }
write(ram,r[15]+36,r[14],4);
goto P_0c07c0da;
P_0c07c0da: /* original e122, guest PC 0x0c07c0da */
if(!s->budget--) { s->failed_pc=0x0c07c0dau; return 0; }
r[1]=0x00000022u;
goto P_0c07c0dc;
P_0c07c0dc: /* original 1fe2, guest PC 0x0c07c0dc */
if(!s->budget--) { s->failed_pc=0x0c07c0dcu; return 0; }
write(ram,r[15]+8,r[14],4);
goto P_0c07c0de;
P_0c07c0de: /* original 53f9, guest PC 0x0c07c0de */
if(!s->budget--) { s->failed_pc=0x0c07c0deu; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c0e0;
P_0c07c0e0: /* original e007, guest PC 0x0c07c0e0 */
if(!s->budget--) { s->failed_pc=0x0c07c0e0u; return 0; }
r[0]=0x00000007u;
goto P_0c07c0e2;
P_0c07c0e2: /* original 4308, guest PC 0x0c07c0e2 */
if(!s->budget--) { s->failed_pc=0x0c07c0e2u; return 0; }
r[3]<<=2;
goto P_0c07c0e4;
P_0c07c0e4: /* original 4300, guest PC 0x0c07c0e4 */
if(!s->budget--) { s->failed_pc=0x0c07c0e4u; return 0; }
r[17]=(r[17]&~1u)|((r[3]>>31)!=0);
r[3]<<=1;
goto P_0c07c0e6;
P_0c07c0e6: /* original 2f32, guest PC 0x0c07c0e6 */
if(!s->budget--) { s->failed_pc=0x0c07c0e6u; return 0; }
write(ram,r[15],r[3],4);
goto P_0c07c0e8;
P_0c07c0e8: /* original 920e, guest PC 0x0c07c0e8 */
if(!s->budget--) { s->failed_pc=0x0c07c0e8u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c108u,2);
goto P_0c07c0ea;
P_0c07c0ea: /* original 32fc, guest PC 0x0c07c0ea */
if(!s->budget--) { s->failed_pc=0x0c07c0eau; return 0; }
r[2]+=r[15];
goto P_0c07c0ec;
P_0c07c0ec: /* original 332c, guest PC 0x0c07c0ec */
if(!s->budget--) { s->failed_pc=0x0c07c0ecu; return 0; }
r[3]+=r[2];
goto P_0c07c0ee;
P_0c07c0ee: /* original 1f34, guest PC 0x0c07c0ee */
if(!s->budget--) { s->failed_pc=0x0c07c0eeu; return 0; }
write(ram,r[15]+16,r[3],4);
goto P_0c07c0f0;
P_0c07c0f0: /* original 1f3b, guest PC 0x0c07c0f0 */
if(!s->budget--) { s->failed_pc=0x0c07c0f0u; return 0; }
write(ram,r[15]+44,r[3],4);
goto P_0c07c0f2;
P_0c07c0f2: /* original 1f13, guest PC 0x0c07c0f2 */
if(!s->budget--) { s->failed_pc=0x0c07c0f2u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c0f4;
P_0c07c0f4: /* original e11e, guest PC 0x0c07c0f4 */
if(!s->budget--) { s->failed_pc=0x0c07c0f4u; return 0; }
r[1]=0x0000001eu;
goto P_0c07c0f6;
P_0c07c0f6: /* original 1f18, guest PC 0x0c07c0f6 */
if(!s->budget--) { s->failed_pc=0x0c07c0f6u; return 0; }
write(ram,r[15]+32,r[1],4);
goto P_0c07c0f8;
P_0c07c0f8: /* original 51f9, guest PC 0x0c07c0f8 */
if(!s->budget--) { s->failed_pc=0x0c07c0f8u; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c0fa;
P_0c07c0fa: /* original 4100, guest PC 0x0c07c0fa */
if(!s->budget--) { s->failed_pc=0x0c07c0fau; return 0; }
r[17]=(r[17]&~1u)|((r[1]>>31)!=0);
r[1]<<=1;
goto P_0c07c0fc;
P_0c07c0fc: /* original 7102, guest PC 0x0c07c0fc */
if(!s->budget--) { s->failed_pc=0x0c07c0fcu; return 0; }
r[1]+=0x00000002u;
goto P_0c07c0fe;
P_0c07c0fe: /* original 410c, guest PC 0x0c07c0fe */
if(!s->budget--) { s->failed_pc=0x0c07c0feu; return 0; }
r[1]=(r[0]&0x80000000u)?((r[0]&31u)?(uint32_t)((int32_t)r[1]>>((-r[0])&31u)):((int32_t)r[1]<0?0xffffffffu:0)):r[1]<<(r[0]&31u);
goto P_0c07c100;
P_0c07c100: /* original a09c, guest PC 0x0c07c100 */
if(!s->budget--) { s->failed_pc=0x0c07c100u; return 0; }
write(ram,r[15]+4,r[1],4);
goto P_0c07c23c;
P_0c07c102: /* original 1f11, guest PC 0x0c07c102 */
if(!s->budget--) { s->failed_pc=0x0c07c102u; return 0; }
write(ram,r[15]+4,r[1],4);
if(!vf3_matrix_family(0x0c07c104u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c104u; return 0; } return 1;
P_0c07c12c: /* original 5cf2, guest PC 0x0c07c12c */
if(!s->budget--) { s->failed_pc=0x0c07c12cu; return 0; }
r[12]=read(ram,r[15]+8,4);
goto P_0c07c12e;
P_0c07c12e: /* original 50f4, guest PC 0x0c07c12e */
if(!s->budget--) { s->failed_pc=0x0c07c12eu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c130;
P_0c07c130: /* original 4c08, guest PC 0x0c07c130 */
if(!s->budget--) { s->failed_pc=0x0c07c130u; return 0; }
r[12]<<=2;
goto P_0c07c132;
P_0c07c132: /* original 03ce, guest PC 0x0c07c132 */
if(!s->budget--) { s->failed_pc=0x0c07c132u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c134;
P_0c07c134: /* original 33a3, guest PC 0x0c07c134 */
if(!s->budget--) { s->failed_pc=0x0c07c134u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[10])!=0);
goto P_0c07c136;
P_0c07c136: /* original 8b31, guest PC 0x0c07c136 */
if(!s->budget--) { s->failed_pc=0x0c07c136u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c19c; }
goto P_0c07c138;
P_0c07c138: /* original 93bd, guest PC 0x0c07c138 */
if(!s->budget--) { s->failed_pc=0x0c07c138u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c13a;
P_0c07c13a: /* original 62f2, guest PC 0x0c07c13a */
if(!s->budget--) { s->failed_pc=0x0c07c13au; return 0; }
tmp=read(ram,r[15],4);
r[2]=tmp;
goto P_0c07c13c;
P_0c07c13c: /* original 33fc, guest PC 0x0c07c13c */
if(!s->budget--) { s->failed_pc=0x0c07c13cu; return 0; }
r[3]+=r[15];
goto P_0c07c13e;
P_0c07c13e: /* original 323c, guest PC 0x0c07c13e */
if(!s->budget--) { s->failed_pc=0x0c07c13eu; return 0; }
r[2]+=r[3];
goto P_0c07c140;
P_0c07c140: /* original 32cc, guest PC 0x0c07c140 */
if(!s->budget--) { s->failed_pc=0x0c07c140u; return 0; }
r[2]+=r[12];
goto P_0c07c142;
P_0c07c142: /* original 1f27, guest PC 0x0c07c142 */
if(!s->budget--) { s->failed_pc=0x0c07c142u; return 0; }
write(ram,r[15]+28,r[2],4);
goto P_0c07c144;
P_0c07c144: /* original 90b8, guest PC 0x0c07c144 */
if(!s->budget--) { s->failed_pc=0x0c07c144u; return 0; }
r[0]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b8u,2);
goto P_0c07c146;
P_0c07c146: /* original 61f2, guest PC 0x0c07c146 */
if(!s->budget--) { s->failed_pc=0x0c07c146u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c148;
P_0c07c148: /* original 30fc, guest PC 0x0c07c148 */
if(!s->budget--) { s->failed_pc=0x0c07c148u; return 0; }
r[0]+=r[15];
goto P_0c07c14a;
P_0c07c14a: /* original 310c, guest PC 0x0c07c14a */
if(!s->budget--) { s->failed_pc=0x0c07c14au; return 0; }
r[1]+=r[0];
goto P_0c07c14c;
P_0c07c14c: /* original 31cc, guest PC 0x0c07c14c */
if(!s->budget--) { s->failed_pc=0x0c07c14cu; return 0; }
r[1]+=r[12];
goto P_0c07c14e;
P_0c07c14e: /* original 1f1a, guest PC 0x0c07c14e */
if(!s->budget--) { s->failed_pc=0x0c07c14eu; return 0; }
write(ram,r[15]+40,r[1],4);
goto P_0c07c150;
P_0c07c150: /* original 6112, guest PC 0x0c07c150 */
if(!s->budget--) { s->failed_pc=0x0c07c150u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c152;
P_0c07c152: /* original d35d, guest PC 0x0c07c152 */
if(!s->budget--) { s->failed_pc=0x0c07c152u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c154;
P_0c07c154: /* original 430b, guest PC 0x0c07c154 */
if(!s->budget--) { s->failed_pc=0x0c07c154u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c158u;
r[0]=r[10];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c158u) { target=s->pc; goto dispatch; }
goto P_0c07c158;
P_0c07c156: /* original 60a3, guest PC 0x0c07c156 */
if(!s->budget--) { s->failed_pc=0x0c07c156u; return 0; }
r[0]=r[10];
goto P_0c07c158;
P_0c07c158: /* original 2202, guest PC 0x0c07c158 */
if(!s->budget--) { s->failed_pc=0x0c07c158u; return 0; }
write(ram,r[2],r[0],4);
goto P_0c07c15a;
P_0c07c15a: /* original e700, guest PC 0x0c07c15a */
if(!s->budget--) { s->failed_pc=0x0c07c15au; return 0; }
r[7]=0x00000000u;
goto P_0c07c15c;
P_0c07c15c: /* original 52f2, guest PC 0x0c07c15c */
if(!s->budget--) { s->failed_pc=0x0c07c15cu; return 0; }
r[2]=read(ram,r[15]+8,4);
goto P_0c07c15e;
P_0c07c15e: /* original 66d3, guest PC 0x0c07c15e */
if(!s->budget--) { s->failed_pc=0x0c07c15eu; return 0; }
r[6]=r[13];
goto P_0c07c160;
P_0c07c160: /* original 6323, guest PC 0x0c07c160 */
if(!s->budget--) { s->failed_pc=0x0c07c160u; return 0; }
r[3]=r[2];
goto P_0c07c162;
P_0c07c162: /* original 4208, guest PC 0x0c07c162 */
if(!s->budget--) { s->failed_pc=0x0c07c162u; return 0; }
r[2]<<=2;
goto P_0c07c164;
P_0c07c164: /* original 323c, guest PC 0x0c07c164 */
if(!s->budget--) { s->failed_pc=0x0c07c164u; return 0; }
r[2]+=r[3];
goto P_0c07c166;
P_0c07c166: /* original 53f1, guest PC 0x0c07c166 */
if(!s->budget--) { s->failed_pc=0x0c07c166u; return 0; }
r[3]=read(ram,r[15]+4,4);
goto P_0c07c168;
P_0c07c168: /* original 4208, guest PC 0x0c07c168 */
if(!s->budget--) { s->failed_pc=0x0c07c168u; return 0; }
r[2]<<=2;
goto P_0c07c16a;
P_0c07c16a: /* original 4200, guest PC 0x0c07c16a */
if(!s->budget--) { s->failed_pc=0x0c07c16au; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c16c;
P_0c07c16c: /* original 720d, guest PC 0x0c07c16c */
if(!s->budget--) { s->failed_pc=0x0c07c16cu; return 0; }
r[2]+=0x0000000du;
goto P_0c07c16e;
P_0c07c16e: /* original 4200, guest PC 0x0c07c16e */
if(!s->budget--) { s->failed_pc=0x0c07c16eu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c170;
P_0c07c170: /* original 223b, guest PC 0x0c07c170 */
if(!s->budget--) { s->failed_pc=0x0c07c170u; return 0; }
r[2]|=r[3];
goto P_0c07c172;
P_0c07c172: /* original 1f25, guest PC 0x0c07c172 */
if(!s->budget--) { s->failed_pc=0x0c07c172u; return 0; }
write(ram,r[15]+20,r[2],4);
goto P_0c07c174;
P_0c07c174: /* original 2fb6, guest PC 0x0c07c174 */
if(!s->budget--) { s->failed_pc=0x0c07c174u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c176;
P_0c07c176: /* original 2fe6, guest PC 0x0c07c176 */
if(!s->budget--) { s->failed_pc=0x0c07c176u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c178;
P_0c07c178: /* original 50f9, guest PC 0x0c07c178 */
if(!s->budget--) { s->failed_pc=0x0c07c178u; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c17a;
P_0c07c17a: /* original 6002, guest PC 0x0c07c17a */
if(!s->budget--) { s->failed_pc=0x0c07c17au; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c17c;
P_0c07c17c: /* original 4008, guest PC 0x0c07c17c */
if(!s->budget--) { s->failed_pc=0x0c07c17cu; return 0; }
r[0]<<=2;
goto P_0c07c17e;
P_0c07c17e: /* original 059e, guest PC 0x0c07c17e */
if(!s->budget--) { s->failed_pc=0x0c07c17eu; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c180;
P_0c07c180: /* original 480b, guest PC 0x0c07c180 */
if(!s->budget--) { s->failed_pc=0x0c07c180u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c184u;
r[4]=r[2];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c184u) { target=s->pc; goto dispatch; }
goto P_0c07c184;
P_0c07c182: /* original 6423, guest PC 0x0c07c182 */
if(!s->budget--) { s->failed_pc=0x0c07c182u; return 0; }
r[4]=r[2];
goto P_0c07c184;
P_0c07c184: /* original 7f08, guest PC 0x0c07c184 */
if(!s->budget--) { s->failed_pc=0x0c07c184u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c186;
P_0c07c186: /* original 6403, guest PC 0x0c07c186 */
if(!s->budget--) { s->failed_pc=0x0c07c186u; return 0; }
r[4]=r[0];
goto P_0c07c188;
P_0c07c188: /* original e030, guest PC 0x0c07c188 */
if(!s->budget--) { s->failed_pc=0x0c07c188u; return 0; }
r[0]=0x00000030u;
goto P_0c07c18a;
P_0c07c18a: /* original f4e7, guest PC 0x0c07c18a */
if(!s->budget--) { s->failed_pc=0x0c07c18au; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c18c;
P_0c07c18c: /* original 52f7, guest PC 0x0c07c18c */
if(!s->budget--) { s->failed_pc=0x0c07c18cu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c18e;
P_0c07c18e: /* original 53fa, guest PC 0x0c07c18e */
if(!s->budget--) { s->failed_pc=0x0c07c18eu; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c190;
P_0c07c190: /* original 6122, guest PC 0x0c07c190 */
if(!s->budget--) { s->failed_pc=0x0c07c190u; return 0; }
tmp=read(ram,r[2],4);
r[1]=tmp;
goto P_0c07c192;
P_0c07c192: /* original 6232, guest PC 0x0c07c192 */
if(!s->budget--) { s->failed_pc=0x0c07c192u; return 0; }
tmp=read(ram,r[3],4);
r[2]=tmp;
goto P_0c07c194;
P_0c07c194: /* original 01a7, guest PC 0x0c07c194 */
if(!s->budget--) { s->failed_pc=0x0c07c194u; return 0; }
r[19]=r[1]*r[10];
goto P_0c07c196;
P_0c07c196: /* original 011a, guest PC 0x0c07c196 */
if(!s->budget--) { s->failed_pc=0x0c07c196u; return 0; }
r[1]=r[19];
goto P_0c07c198;
P_0c07c198: /* original 3218, guest PC 0x0c07c198 */
if(!s->budget--) { s->failed_pc=0x0c07c198u; return 0; }
r[2]-=r[1];
goto P_0c07c19a;
P_0c07c19a: /* original 2322, guest PC 0x0c07c19a */
if(!s->budget--) { s->failed_pc=0x0c07c19au; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c19c;
P_0c07c19c: /* original 50f4, guest PC 0x0c07c19c */
if(!s->budget--) { s->failed_pc=0x0c07c19cu; return 0; }
r[0]=read(ram,r[15]+16,4);
goto P_0c07c19e;
P_0c07c19e: /* original e20a, guest PC 0x0c07c19e */
if(!s->budget--) { s->failed_pc=0x0c07c19eu; return 0; }
r[2]=0x0000000au;
goto P_0c07c1a0;
P_0c07c1a0: /* original 03ce, guest PC 0x0c07c1a0 */
if(!s->budget--) { s->failed_pc=0x0c07c1a0u; return 0; }
r[3]=read(ram,r[12]+r[0],4);
goto P_0c07c1a2;
P_0c07c1a2: /* original 3323, guest PC 0x0c07c1a2 */
if(!s->budget--) { s->failed_pc=0x0c07c1a2u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[3]>=(int32_t)r[2])!=0);
goto P_0c07c1a4;
P_0c07c1a4: /* original 8b2d, guest PC 0x0c07c1a4 */
if(!s->budget--) { s->failed_pc=0x0c07c1a4u; return 0; }
cond=r[17]&1u;
if(!cond) { goto P_0c07c202; }
goto P_0c07c1a6;
P_0c07c1a6: /* original 9386, guest PC 0x0c07c1a6 */
if(!s->budget--) { s->failed_pc=0x0c07c1a6u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2b6u,2);
goto P_0c07c1a8;
P_0c07c1a8: /* original 61f2, guest PC 0x0c07c1a8 */
if(!s->budget--) { s->failed_pc=0x0c07c1a8u; return 0; }
tmp=read(ram,r[15],4);
r[1]=tmp;
goto P_0c07c1aa;
P_0c07c1aa: /* original 33fc, guest PC 0x0c07c1aa */
if(!s->budget--) { s->failed_pc=0x0c07c1aau; return 0; }
r[3]+=r[15];
goto P_0c07c1ac;
P_0c07c1ac: /* original 313c, guest PC 0x0c07c1ac */
if(!s->budget--) { s->failed_pc=0x0c07c1acu; return 0; }
r[1]+=r[3];
goto P_0c07c1ae;
P_0c07c1ae: /* original 31cc, guest PC 0x0c07c1ae */
if(!s->budget--) { s->failed_pc=0x0c07c1aeu; return 0; }
r[1]+=r[12];
goto P_0c07c1b0;
P_0c07c1b0: /* original 1f17, guest PC 0x0c07c1b0 */
if(!s->budget--) { s->failed_pc=0x0c07c1b0u; return 0; }
write(ram,r[15]+28,r[1],4);
goto P_0c07c1b2;
P_0c07c1b2: /* original 2f16, guest PC 0x0c07c1b2 */
if(!s->budget--) { s->failed_pc=0x0c07c1b2u; return 0; }
tmp=r[1]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1b4;
P_0c07c1b4: /* original 9281, guest PC 0x0c07c1b4 */
if(!s->budget--) { s->failed_pc=0x0c07c1b4u; return 0; }
r[2]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bau,2);
goto P_0c07c1b6;
P_0c07c1b6: /* original 51f1, guest PC 0x0c07c1b6 */
if(!s->budget--) { s->failed_pc=0x0c07c1b6u; return 0; }
r[1]=read(ram,r[15]+4,4);
goto P_0c07c1b8;
P_0c07c1b8: /* original 32fc, guest PC 0x0c07c1b8 */
if(!s->budget--) { s->failed_pc=0x0c07c1b8u; return 0; }
r[2]+=r[15];
goto P_0c07c1ba;
P_0c07c1ba: /* original 312c, guest PC 0x0c07c1ba */
if(!s->budget--) { s->failed_pc=0x0c07c1bau; return 0; }
r[1]+=r[2];
goto P_0c07c1bc;
P_0c07c1bc: /* original 31cc, guest PC 0x0c07c1bc */
if(!s->budget--) { s->failed_pc=0x0c07c1bcu; return 0; }
r[1]+=r[12];
goto P_0c07c1be;
P_0c07c1be: /* original 1f1b, guest PC 0x0c07c1be */
if(!s->budget--) { s->failed_pc=0x0c07c1beu; return 0; }
write(ram,r[15]+44,r[1],4);
goto P_0c07c1c0;
P_0c07c1c0: /* original d341, guest PC 0x0c07c1c0 */
if(!s->budget--) { s->failed_pc=0x0c07c1c0u; return 0; }
r[3]=read(ram,0x0c07c2c8u,4);
goto P_0c07c1c2;
P_0c07c1c2: /* original 6112, guest PC 0x0c07c1c2 */
if(!s->budget--) { s->failed_pc=0x0c07c1c2u; return 0; }
tmp=read(ram,r[1],4);
r[1]=tmp;
goto P_0c07c1c4;
P_0c07c1c4: /* original 430b, guest PC 0x0c07c1c4 */
if(!s->budget--) { s->failed_pc=0x0c07c1c4u; return 0; }
target=r[3];
r[16]=code_base|0x0c07c1c8u;
r[0]=0x0000000au;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c1c8u) { target=s->pc; goto dispatch; }
goto P_0c07c1c8;
P_0c07c1c6: /* original e00a, guest PC 0x0c07c1c6 */
if(!s->budget--) { s->failed_pc=0x0c07c1c6u; return 0; }
r[0]=0x0000000au;
goto P_0c07c1c8;
P_0c07c1c8: /* original 63f6, guest PC 0x0c07c1c8 */
if(!s->budget--) { s->failed_pc=0x0c07c1c8u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[3]=tmp;
goto P_0c07c1ca;
P_0c07c1ca: /* original e700, guest PC 0x0c07c1ca */
if(!s->budget--) { s->failed_pc=0x0c07c1cau; return 0; }
r[7]=0x00000000u;
goto P_0c07c1cc;
P_0c07c1cc: /* original 66d3, guest PC 0x0c07c1cc */
if(!s->budget--) { s->failed_pc=0x0c07c1ccu; return 0; }
r[6]=r[13];
goto P_0c07c1ce;
P_0c07c1ce: /* original 2302, guest PC 0x0c07c1ce */
if(!s->budget--) { s->failed_pc=0x0c07c1ceu; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c1d0;
P_0c07c1d0: /* original 5cf1, guest PC 0x0c07c1d0 */
if(!s->budget--) { s->failed_pc=0x0c07c1d0u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c1d2;
P_0c07c1d2: /* original 53f8, guest PC 0x0c07c1d2 */
if(!s->budget--) { s->failed_pc=0x0c07c1d2u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c1d4;
P_0c07c1d4: /* original 2fb6, guest PC 0x0c07c1d4 */
if(!s->budget--) { s->failed_pc=0x0c07c1d4u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1d6;
P_0c07c1d6: /* original 2fe6, guest PC 0x0c07c1d6 */
if(!s->budget--) { s->failed_pc=0x0c07c1d6u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c1d8;
P_0c07c1d8: /* original 2c3b, guest PC 0x0c07c1d8 */
if(!s->budget--) { s->failed_pc=0x0c07c1d8u; return 0; }
r[12]|=r[3];
goto P_0c07c1da;
P_0c07c1da: /* original 50f9, guest PC 0x0c07c1da */
if(!s->budget--) { s->failed_pc=0x0c07c1dau; return 0; }
r[0]=read(ram,r[15]+36,4);
goto P_0c07c1dc;
P_0c07c1dc: /* original 6002, guest PC 0x0c07c1dc */
if(!s->budget--) { s->failed_pc=0x0c07c1dcu; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c1de;
P_0c07c1de: /* original 4008, guest PC 0x0c07c1de */
if(!s->budget--) { s->failed_pc=0x0c07c1deu; return 0; }
r[0]<<=2;
goto P_0c07c1e0;
P_0c07c1e0: /* original 059e, guest PC 0x0c07c1e0 */
if(!s->budget--) { s->failed_pc=0x0c07c1e0u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c1e2;
P_0c07c1e2: /* original 480b, guest PC 0x0c07c1e2 */
if(!s->budget--) { s->failed_pc=0x0c07c1e2u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c1e6u;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c1e6u) { target=s->pc; goto dispatch; }
goto P_0c07c1e6;
P_0c07c1e4: /* original 64c3, guest PC 0x0c07c1e4 */
if(!s->budget--) { s->failed_pc=0x0c07c1e4u; return 0; }
r[4]=r[12];
goto P_0c07c1e6;
P_0c07c1e6: /* original 7f08, guest PC 0x0c07c1e6 */
if(!s->budget--) { s->failed_pc=0x0c07c1e6u; return 0; }
r[15]+=0x00000008u;
goto P_0c07c1e8;
P_0c07c1e8: /* original 6403, guest PC 0x0c07c1e8 */
if(!s->budget--) { s->failed_pc=0x0c07c1e8u; return 0; }
r[4]=r[0];
goto P_0c07c1ea;
P_0c07c1ea: /* original e030, guest PC 0x0c07c1ea */
if(!s->budget--) { s->failed_pc=0x0c07c1eau; return 0; }
r[0]=0x00000030u;
goto P_0c07c1ec;
P_0c07c1ec: /* original f4e7, guest PC 0x0c07c1ec */
if(!s->budget--) { s->failed_pc=0x0c07c1ecu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c1ee;
P_0c07c1ee: /* original 52f7, guest PC 0x0c07c1ee */
if(!s->budget--) { s->failed_pc=0x0c07c1eeu; return 0; }
r[2]=read(ram,r[15]+28,4);
goto P_0c07c1f0;
P_0c07c1f0: /* original 53fa, guest PC 0x0c07c1f0 */
if(!s->budget--) { s->failed_pc=0x0c07c1f0u; return 0; }
r[3]=read(ram,r[15]+40,4);
goto P_0c07c1f2;
P_0c07c1f2: /* original 6222, guest PC 0x0c07c1f2 */
if(!s->budget--) { s->failed_pc=0x0c07c1f2u; return 0; }
tmp=read(ram,r[2],4);
r[2]=tmp;
goto P_0c07c1f4;
P_0c07c1f4: /* original 6032, guest PC 0x0c07c1f4 */
if(!s->budget--) { s->failed_pc=0x0c07c1f4u; return 0; }
tmp=read(ram,r[3],4);
r[0]=tmp;
goto P_0c07c1f6;
P_0c07c1f6: /* original 6123, guest PC 0x0c07c1f6 */
if(!s->budget--) { s->failed_pc=0x0c07c1f6u; return 0; }
r[1]=r[2];
goto P_0c07c1f8;
P_0c07c1f8: /* original 4208, guest PC 0x0c07c1f8 */
if(!s->budget--) { s->failed_pc=0x0c07c1f8u; return 0; }
r[2]<<=2;
goto P_0c07c1fa;
P_0c07c1fa: /* original 321c, guest PC 0x0c07c1fa */
if(!s->budget--) { s->failed_pc=0x0c07c1fau; return 0; }
r[2]+=r[1];
goto P_0c07c1fc;
P_0c07c1fc: /* original 4200, guest PC 0x0c07c1fc */
if(!s->budget--) { s->failed_pc=0x0c07c1fcu; return 0; }
r[17]=(r[17]&~1u)|((r[2]>>31)!=0);
r[2]<<=1;
goto P_0c07c1fe;
P_0c07c1fe: /* original 3028, guest PC 0x0c07c1fe */
if(!s->budget--) { s->failed_pc=0x0c07c1feu; return 0; }
r[0]-=r[2];
goto P_0c07c200;
P_0c07c200: /* original 2302, guest PC 0x0c07c200 */
if(!s->budget--) { s->failed_pc=0x0c07c200u; return 0; }
write(ram,r[3],r[0],4);
goto P_0c07c202;
P_0c07c202: /* original 5cf1, guest PC 0x0c07c202 */
if(!s->budget--) { s->failed_pc=0x0c07c202u; return 0; }
r[12]=read(ram,r[15]+4,4);
goto P_0c07c204;
P_0c07c204: /* original e700, guest PC 0x0c07c204 */
if(!s->budget--) { s->failed_pc=0x0c07c204u; return 0; }
r[7]=0x00000000u;
goto P_0c07c206;
P_0c07c206: /* original 53f3, guest PC 0x0c07c206 */
if(!s->budget--) { s->failed_pc=0x0c07c206u; return 0; }
r[3]=read(ram,r[15]+12,4);
goto P_0c07c208;
P_0c07c208: /* original 66d3, guest PC 0x0c07c208 */
if(!s->budget--) { s->failed_pc=0x0c07c208u; return 0; }
r[6]=r[13];
goto P_0c07c20a;
P_0c07c20a: /* original 2fb6, guest PC 0x0c07c20a */
if(!s->budget--) { s->failed_pc=0x0c07c20au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c20c;
P_0c07c20c: /* original 2fe6, guest PC 0x0c07c20c */
if(!s->budget--) { s->failed_pc=0x0c07c20cu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c20e;
P_0c07c20e: /* original 2c3b, guest PC 0x0c07c20e */
if(!s->budget--) { s->failed_pc=0x0c07c20eu; return 0; }
r[12]|=r[3];
goto P_0c07c210;
P_0c07c210: /* original 50fd, guest PC 0x0c07c210 */
if(!s->budget--) { s->failed_pc=0x0c07c210u; return 0; }
r[0]=read(ram,r[15]+52,4);
goto P_0c07c212;
P_0c07c212: /* original 6002, guest PC 0x0c07c212 */
if(!s->budget--) { s->failed_pc=0x0c07c212u; return 0; }
tmp=read(ram,r[0],4);
r[0]=tmp;
goto P_0c07c214;
P_0c07c214: /* original 4008, guest PC 0x0c07c214 */
if(!s->budget--) { s->failed_pc=0x0c07c214u; return 0; }
r[0]<<=2;
goto P_0c07c216;
P_0c07c216: /* original 059e, guest PC 0x0c07c216 */
if(!s->budget--) { s->failed_pc=0x0c07c216u; return 0; }
r[5]=read(ram,r[9]+r[0],4);
goto P_0c07c218;
P_0c07c218: /* original 480b, guest PC 0x0c07c218 */
if(!s->budget--) { s->failed_pc=0x0c07c218u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c21cu;
r[4]=r[12];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c21cu) { target=s->pc; goto dispatch; }
goto P_0c07c21c;
P_0c07c21a: /* original 64c3, guest PC 0x0c07c21a */
if(!s->budget--) { s->failed_pc=0x0c07c21au; return 0; }
r[4]=r[12];
goto P_0c07c21c;
P_0c07c21c: /* original 7f08, guest PC 0x0c07c21c */
if(!s->budget--) { s->failed_pc=0x0c07c21cu; return 0; }
r[15]+=0x00000008u;
goto P_0c07c21e;
P_0c07c21e: /* original 6403, guest PC 0x0c07c21e */
if(!s->budget--) { s->failed_pc=0x0c07c21eu; return 0; }
r[4]=r[0];
goto P_0c07c220;
P_0c07c220: /* original e030, guest PC 0x0c07c220 */
if(!s->budget--) { s->failed_pc=0x0c07c220u; return 0; }
r[0]=0x00000030u;
goto P_0c07c222;
P_0c07c222: /* original f4e7, guest PC 0x0c07c222 */
if(!s->budget--) { s->failed_pc=0x0c07c222u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c224;
P_0c07c224: /* original 53f2, guest PC 0x0c07c224 */
if(!s->budget--) { s->failed_pc=0x0c07c224u; return 0; }
r[3]=read(ram,r[15]+8,4);
goto P_0c07c226;
P_0c07c226: /* original 7301, guest PC 0x0c07c226 */
if(!s->budget--) { s->failed_pc=0x0c07c226u; return 0; }
r[3]+=0x00000001u;
goto P_0c07c228;
P_0c07c228: /* original 1f32, guest PC 0x0c07c228 */
if(!s->budget--) { s->failed_pc=0x0c07c228u; return 0; }
write(ram,r[15]+8,r[3],4);
goto P_0c07c22a;
P_0c07c22a: /* original 52fb, guest PC 0x0c07c22a */
if(!s->budget--) { s->failed_pc=0x0c07c22au; return 0; }
r[2]=read(ram,r[15]+44,4);
goto P_0c07c22c;
P_0c07c22c: /* original 7204, guest PC 0x0c07c22c */
if(!s->budget--) { s->failed_pc=0x0c07c22cu; return 0; }
r[2]+=0x00000004u;
goto P_0c07c22e;
P_0c07c22e: /* original 1f2b, guest PC 0x0c07c22e */
if(!s->budget--) { s->failed_pc=0x0c07c22eu; return 0; }
write(ram,r[15]+44,r[2],4);
goto P_0c07c230;
P_0c07c230: /* original 51f3, guest PC 0x0c07c230 */
if(!s->budget--) { s->failed_pc=0x0c07c230u; return 0; }
r[1]=read(ram,r[15]+12,4);
goto P_0c07c232;
P_0c07c232: /* original 7150, guest PC 0x0c07c232 */
if(!s->budget--) { s->failed_pc=0x0c07c232u; return 0; }
r[1]+=0x00000050u;
goto P_0c07c234;
P_0c07c234: /* original 1f13, guest PC 0x0c07c234 */
if(!s->budget--) { s->failed_pc=0x0c07c234u; return 0; }
write(ram,r[15]+12,r[1],4);
goto P_0c07c236;
P_0c07c236: /* original 53f8, guest PC 0x0c07c236 */
if(!s->budget--) { s->failed_pc=0x0c07c236u; return 0; }
r[3]=read(ram,r[15]+32,4);
goto P_0c07c238;
P_0c07c238: /* original 7350, guest PC 0x0c07c238 */
if(!s->budget--) { s->failed_pc=0x0c07c238u; return 0; }
r[3]+=0x00000050u;
goto P_0c07c23a;
P_0c07c23a: /* original 1f38, guest PC 0x0c07c23a */
if(!s->budget--) { s->failed_pc=0x0c07c23au; return 0; }
write(ram,r[15]+32,r[3],4);
goto P_0c07c23c;
P_0c07c23c: /* original 51f2, guest PC 0x0c07c23c */
if(!s->budget--) { s->failed_pc=0x0c07c23cu; return 0; }
r[1]=read(ram,r[15]+8,4);
goto P_0c07c23e;
P_0c07c23e: /* original e202, guest PC 0x0c07c23e */
if(!s->budget--) { s->failed_pc=0x0c07c23eu; return 0; }
r[2]=0x00000002u;
goto P_0c07c240;
P_0c07c240: /* original 3123, guest PC 0x0c07c240 */
if(!s->budget--) { s->failed_pc=0x0c07c240u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c242;
P_0c07c242: /* original 8901, guest PC 0x0c07c242 */
if(!s->budget--) { s->failed_pc=0x0c07c242u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c248; }
goto P_0c07c244;
P_0c07c244: /* original af72, guest PC 0x0c07c244 */
if(!s->budget--) { s->failed_pc=0x0c07c244u; return 0; }
goto P_0c07c12c;
P_0c07c246: /* original 0009, guest PC 0x0c07c246 */
if(!s->budget--) { s->failed_pc=0x0c07c246u; return 0; }
goto P_0c07c248;
P_0c07c248: /* original 53f9, guest PC 0x0c07c248 */
if(!s->budget--) { s->failed_pc=0x0c07c248u; return 0; }
r[3]=read(ram,r[15]+36,4);
goto P_0c07c24a;
P_0c07c24a: /* original 7301, guest PC 0x0c07c24a */
if(!s->budget--) { s->failed_pc=0x0c07c24au; return 0; }
r[3]+=0x00000001u;
goto P_0c07c24c;
P_0c07c24c: /* original 1f39, guest PC 0x0c07c24c */
if(!s->budget--) { s->failed_pc=0x0c07c24cu; return 0; }
write(ram,r[15]+36,r[3],4);
goto P_0c07c24e;
P_0c07c24e: /* original 51f9, guest PC 0x0c07c24e */
if(!s->budget--) { s->failed_pc=0x0c07c24eu; return 0; }
r[1]=read(ram,r[15]+36,4);
goto P_0c07c250;
P_0c07c250: /* original e202, guest PC 0x0c07c250 */
if(!s->budget--) { s->failed_pc=0x0c07c250u; return 0; }
r[2]=0x00000002u;
goto P_0c07c252;
P_0c07c252: /* original 3123, guest PC 0x0c07c252 */
if(!s->budget--) { s->failed_pc=0x0c07c252u; return 0; }
r[17]=(r[17]&~1u)|(((int32_t)r[1]>=(int32_t)r[2])!=0);
goto P_0c07c254;
P_0c07c254: /* original 8901, guest PC 0x0c07c254 */
if(!s->budget--) { s->failed_pc=0x0c07c254u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c25a; }
goto P_0c07c256;
P_0c07c256: /* original af40, guest PC 0x0c07c256 */
if(!s->budget--) { s->failed_pc=0x0c07c256u; return 0; }
goto P_0c07c0da;
P_0c07c258: /* original 0009, guest PC 0x0c07c258 */
if(!s->budget--) { s->failed_pc=0x0c07c258u; return 0; }
goto P_0c07c25a;
P_0c07c25a: /* original 2fb6, guest PC 0x0c07c25a */
if(!s->budget--) { s->failed_pc=0x0c07c25au; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c25c;
P_0c07c25c: /* original e700, guest PC 0x0c07c25c */
if(!s->budget--) { s->failed_pc=0x0c07c25cu; return 0; }
r[7]=0x00000000u;
goto P_0c07c25e;
P_0c07c25e: /* original 2fe6, guest PC 0x0c07c25e */
if(!s->budget--) { s->failed_pc=0x0c07c25eu; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c260;
P_0c07c260: /* original 952c, guest PC 0x0c07c260 */
if(!s->budget--) { s->failed_pc=0x0c07c260u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c262;
P_0c07c262: /* original 942c, guest PC 0x0c07c262 */
if(!s->budget--) { s->failed_pc=0x0c07c262u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2beu,2);
goto P_0c07c264;
P_0c07c264: /* original 480b, guest PC 0x0c07c264 */
if(!s->budget--) { s->failed_pc=0x0c07c264u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c268u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c268u) { target=s->pc; goto dispatch; }
goto P_0c07c268;
P_0c07c266: /* original 66d3, guest PC 0x0c07c266 */
if(!s->budget--) { s->failed_pc=0x0c07c266u; return 0; }
r[6]=r[13];
goto P_0c07c268;
P_0c07c268: /* original 6403, guest PC 0x0c07c268 */
if(!s->budget--) { s->failed_pc=0x0c07c268u; return 0; }
r[4]=r[0];
goto P_0c07c26a;
P_0c07c26a: /* original e030, guest PC 0x0c07c26a */
if(!s->budget--) { s->failed_pc=0x0c07c26au; return 0; }
r[0]=0x00000030u;
goto P_0c07c26c;
P_0c07c26c: /* original f4e7, guest PC 0x0c07c26c */
if(!s->budget--) { s->failed_pc=0x0c07c26cu; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c26e;
P_0c07c26e: /* original e700, guest PC 0x0c07c26e */
if(!s->budget--) { s->failed_pc=0x0c07c26eu; return 0; }
r[7]=0x00000000u;
goto P_0c07c270;
P_0c07c270: /* original 2fb6, guest PC 0x0c07c270 */
if(!s->budget--) { s->failed_pc=0x0c07c270u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c272;
P_0c07c272: /* original 2fe6, guest PC 0x0c07c272 */
if(!s->budget--) { s->failed_pc=0x0c07c272u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c274;
P_0c07c274: /* original 9524, guest PC 0x0c07c274 */
if(!s->budget--) { s->failed_pc=0x0c07c274u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c276;
P_0c07c276: /* original 9424, guest PC 0x0c07c276 */
if(!s->budget--) { s->failed_pc=0x0c07c276u; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c2u,2);
goto P_0c07c278;
P_0c07c278: /* original 480b, guest PC 0x0c07c278 */
if(!s->budget--) { s->failed_pc=0x0c07c278u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c27cu;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c27cu) { target=s->pc; goto dispatch; }
goto P_0c07c27c;
P_0c07c27a: /* original 66d3, guest PC 0x0c07c27a */
if(!s->budget--) { s->failed_pc=0x0c07c27au; return 0; }
r[6]=r[13];
goto P_0c07c27c;
P_0c07c27c: /* original 6403, guest PC 0x0c07c27c */
if(!s->budget--) { s->failed_pc=0x0c07c27cu; return 0; }
r[4]=r[0];
goto P_0c07c27e;
P_0c07c27e: /* original e030, guest PC 0x0c07c27e */
if(!s->budget--) { s->failed_pc=0x0c07c27eu; return 0; }
r[0]=0x00000030u;
goto P_0c07c280;
P_0c07c280: /* original f4e7, guest PC 0x0c07c280 */
if(!s->budget--) { s->failed_pc=0x0c07c280u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c282;
P_0c07c282: /* original e700, guest PC 0x0c07c282 */
if(!s->budget--) { s->failed_pc=0x0c07c282u; return 0; }
r[7]=0x00000000u;
goto P_0c07c284;
P_0c07c284: /* original 2fb6, guest PC 0x0c07c284 */
if(!s->budget--) { s->failed_pc=0x0c07c284u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c286;
P_0c07c286: /* original 2fe6, guest PC 0x0c07c286 */
if(!s->budget--) { s->failed_pc=0x0c07c286u; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c288;
P_0c07c288: /* original 9518, guest PC 0x0c07c288 */
if(!s->budget--) { s->failed_pc=0x0c07c288u; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2bcu,2);
goto P_0c07c28a;
P_0c07c28a: /* original 941b, guest PC 0x0c07c28a */
if(!s->budget--) { s->failed_pc=0x0c07c28au; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c4u,2);
goto P_0c07c28c;
P_0c07c28c: /* original 480b, guest PC 0x0c07c28c */
if(!s->budget--) { s->failed_pc=0x0c07c28cu; return 0; }
target=r[8];
r[16]=code_base|0x0c07c290u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c290u) { target=s->pc; goto dispatch; }
goto P_0c07c290;
P_0c07c28e: /* original 66d3, guest PC 0x0c07c28e */
if(!s->budget--) { s->failed_pc=0x0c07c28eu; return 0; }
r[6]=r[13];
goto P_0c07c290;
P_0c07c290: /* original 6403, guest PC 0x0c07c290 */
if(!s->budget--) { s->failed_pc=0x0c07c290u; return 0; }
r[4]=r[0];
goto P_0c07c292;
P_0c07c292: /* original e030, guest PC 0x0c07c292 */
if(!s->budget--) { s->failed_pc=0x0c07c292u; return 0; }
r[0]=0x00000030u;
goto P_0c07c294;
P_0c07c294: /* original f4e7, guest PC 0x0c07c294 */
if(!s->budget--) { s->failed_pc=0x0c07c294u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c296;
P_0c07c296: /* original e700, guest PC 0x0c07c296 */
if(!s->budget--) { s->failed_pc=0x0c07c296u; return 0; }
r[7]=0x00000000u;
goto P_0c07c298;
P_0c07c298: /* original 2fb6, guest PC 0x0c07c298 */
if(!s->budget--) { s->failed_pc=0x0c07c298u; return 0; }
tmp=r[11]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c29a;
P_0c07c29a: /* original 2fe6, guest PC 0x0c07c29a */
if(!s->budget--) { s->failed_pc=0x0c07c29au; return 0; }
tmp=r[14]; r[15]-=4; write(ram,r[15],tmp,4);
goto P_0c07c29c;
P_0c07c29c: /* original 9510, guest PC 0x0c07c29c */
if(!s->budget--) { s->failed_pc=0x0c07c29cu; return 0; }
r[5]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c0u,2);
goto P_0c07c29e;
P_0c07c29e: /* original 9412, guest PC 0x0c07c29e */
if(!s->budget--) { s->failed_pc=0x0c07c29eu; return 0; }
r[4]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c2c6u,2);
goto P_0c07c2a0;
P_0c07c2a0: /* original 480b, guest PC 0x0c07c2a0 */
if(!s->budget--) { s->failed_pc=0x0c07c2a0u; return 0; }
target=r[8];
r[16]=code_base|0x0c07c2a4u;
r[6]=r[13];
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2a4u) { target=s->pc; goto dispatch; }
goto P_0c07c2a4;
P_0c07c2a2: /* original 66d3, guest PC 0x0c07c2a2 */
if(!s->budget--) { s->failed_pc=0x0c07c2a2u; return 0; }
r[6]=r[13];
goto P_0c07c2a4;
P_0c07c2a4: /* original 6403, guest PC 0x0c07c2a4 */
if(!s->budget--) { s->failed_pc=0x0c07c2a4u; return 0; }
r[4]=r[0];
goto P_0c07c2a6;
P_0c07c2a6: /* original e030, guest PC 0x0c07c2a6 */
if(!s->budget--) { s->failed_pc=0x0c07c2a6u; return 0; }
r[0]=0x00000030u;
goto P_0c07c2a8;
P_0c07c2a8: /* original f4e7, guest PC 0x0c07c2a8 */
if(!s->budget--) { s->failed_pc=0x0c07c2a8u; return 0; }
vf3_matrix_store(s,ram,14,r[4]+r[0]);
goto P_0c07c2aa;
P_0c07c2aa: /* original 7f20, guest PC 0x0c07c2aa */
if(!s->budget--) { s->failed_pc=0x0c07c2aau; return 0; }
r[15]+=0x00000020u;
goto P_0c07c2ac;
P_0c07c2ac: /* original d307, guest PC 0x0c07c2ac */
if(!s->budget--) { s->failed_pc=0x0c07c2acu; return 0; }
r[3]=read(ram,0x0c07c2ccu,4);
goto P_0c07c2ae;
P_0c07c2ae: /* original 430b, guest PC 0x0c07c2ae */
if(!s->budget--) { s->failed_pc=0x0c07c2aeu; return 0; }
target=r[3];
r[16]=code_base|0x0c07c2b2u;
r[4]=0x00000000u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2b2u) { target=s->pc; goto dispatch; }
goto P_0c07c2b2;
P_0c07c2b0: /* original e400, guest PC 0x0c07c2b0 */
if(!s->budget--) { s->failed_pc=0x0c07c2b0u; return 0; }
r[4]=0x00000000u;
goto P_0c07c2b2;
P_0c07c2b2: /* original a01e, guest PC 0x0c07c2b2 */
if(!s->budget--) { s->failed_pc=0x0c07c2b2u; return 0; }
goto P_0c07c2f2;
P_0c07c2b4: /* original 0009, guest PC 0x0c07c2b4 */
if(!s->budget--) { s->failed_pc=0x0c07c2b4u; return 0; }
if(!vf3_matrix_family(0x0c07c2b6u,s,ram)) { if(!s->lost_pc) s->lost_pc=0x0c07c2b6u; return 0; } return 1;
P_0c07c2d0: /* original 50fc, guest PC 0x0c07c2d0 */
if(!s->budget--) { s->failed_pc=0x0c07c2d0u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2d2;
P_0c07c2d2: /* original c802, guest PC 0x0c07c2d2 */
if(!s->budget--) { s->failed_pc=0x0c07c2d2u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&2u)==0)!=0);
goto P_0c07c2d4;
P_0c07c2d4: /* original 8902, guest PC 0x0c07c2d4 */
if(!s->budget--) { s->failed_pc=0x0c07c2d4u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2dc; }
goto P_0c07c2d6;
P_0c07c2d6: /* original d243, guest PC 0x0c07c2d6 */
if(!s->budget--) { s->failed_pc=0x0c07c2d6u; return 0; }
r[2]=read(ram,0x0c07c3e4u,4);
goto P_0c07c2d8;
P_0c07c2d8: /* original 420b, guest PC 0x0c07c2d8 */
if(!s->budget--) { s->failed_pc=0x0c07c2d8u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c2dcu;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2dcu) { target=s->pc; goto dispatch; }
goto P_0c07c2dc;
P_0c07c2da: /* original 0009, guest PC 0x0c07c2da */
if(!s->budget--) { s->failed_pc=0x0c07c2dau; return 0; }
goto P_0c07c2dc;
P_0c07c2dc: /* original 2cc8, guest PC 0x0c07c2dc */
if(!s->budget--) { s->failed_pc=0x0c07c2dcu; return 0; }
r[17]=(r[17]&~1u)|(((r[12]&r[12])==0)!=0);
goto P_0c07c2de;
P_0c07c2de: /* original 8902, guest PC 0x0c07c2de */
if(!s->budget--) { s->failed_pc=0x0c07c2deu; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2e6; }
goto P_0c07c2e0;
P_0c07c2e0: /* original d241, guest PC 0x0c07c2e0 */
if(!s->budget--) { s->failed_pc=0x0c07c2e0u; return 0; }
r[2]=read(ram,0x0c07c3e8u,4);
goto P_0c07c2e2;
P_0c07c2e2: /* original 420b, guest PC 0x0c07c2e2 */
if(!s->budget--) { s->failed_pc=0x0c07c2e2u; return 0; }
target=r[2];
r[16]=code_base|0x0c07c2e6u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2e6u) { target=s->pc; goto dispatch; }
goto P_0c07c2e6;
P_0c07c2e4: /* original 0009, guest PC 0x0c07c2e4 */
if(!s->budget--) { s->failed_pc=0x0c07c2e4u; return 0; }
goto P_0c07c2e6;
P_0c07c2e6: /* original 50fc, guest PC 0x0c07c2e6 */
if(!s->budget--) { s->failed_pc=0x0c07c2e6u; return 0; }
r[0]=read(ram,r[15]+48,4);
goto P_0c07c2e8;
P_0c07c2e8: /* original c808, guest PC 0x0c07c2e8 */
if(!s->budget--) { s->failed_pc=0x0c07c2e8u; return 0; }
r[17]=(r[17]&~1u)|(((r[0]&8u)==0)!=0);
goto P_0c07c2ea;
P_0c07c2ea: /* original 8902, guest PC 0x0c07c2ea */
if(!s->budget--) { s->failed_pc=0x0c07c2eau; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c2f2; }
goto P_0c07c2ec;
P_0c07c2ec: /* original d13f, guest PC 0x0c07c2ec */
if(!s->budget--) { s->failed_pc=0x0c07c2ecu; return 0; }
r[1]=read(ram,0x0c07c3ecu,4);
goto P_0c07c2ee;
P_0c07c2ee: /* original 410b, guest PC 0x0c07c2ee */
if(!s->budget--) { s->failed_pc=0x0c07c2eeu; return 0; }
target=r[1];
r[16]=code_base|0x0c07c2f2u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c2f2u) { target=s->pc; goto dispatch; }
goto P_0c07c2f2;
P_0c07c2f0: /* original 0009, guest PC 0x0c07c2f0 */
if(!s->budget--) { s->failed_pc=0x0c07c2f0u; return 0; }
goto P_0c07c2f2;
P_0c07c2f2: /* original 51fc, guest PC 0x0c07c2f2 */
if(!s->budget--) { s->failed_pc=0x0c07c2f2u; return 0; }
r[1]=read(ram,r[15]+48,4);
goto P_0c07c2f4;
P_0c07c2f4: /* original 9370, guest PC 0x0c07c2f4 */
if(!s->budget--) { s->failed_pc=0x0c07c2f4u; return 0; }
r[3]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3d8u,2);
goto P_0c07c2f6;
P_0c07c2f6: /* original 2138, guest PC 0x0c07c2f6 */
if(!s->budget--) { s->failed_pc=0x0c07c2f6u; return 0; }
r[17]=(r[17]&~1u)|(((r[1]&r[3])==0)!=0);
goto P_0c07c2f8;
P_0c07c2f8: /* original 8902, guest PC 0x0c07c2f8 */
if(!s->budget--) { s->failed_pc=0x0c07c2f8u; return 0; }
cond=r[17]&1u;
if(cond) { goto P_0c07c300; }
goto P_0c07c2fa;
P_0c07c2fa: /* original d23d, guest PC 0x0c07c2fa */
if(!s->budget--) { s->failed_pc=0x0c07c2fau; return 0; }
r[2]=read(ram,0x0c07c3f0u,4);
goto P_0c07c2fc;
P_0c07c2fc: /* original 420b, guest PC 0x0c07c2fc */
if(!s->budget--) { s->failed_pc=0x0c07c2fcu; return 0; }
target=r[2];
r[16]=code_base|0x0c07c300u;
vf3_matrix_call_alias_pc=(target&0x1fffffffu); vf3_matrix_call_alias=(target&0xff000000u); if(!vf3_matrix_family(target,s,ram)) return 0; if((s->pc&0x1fffffffu)!=0x0c07c300u) { target=s->pc; goto dispatch; }
goto P_0c07c300;
P_0c07c2fe: /* original 0009, guest PC 0x0c07c2fe */
if(!s->budget--) { s->failed_pc=0x0c07c2feu; return 0; }
goto P_0c07c300;
P_0c07c300: /* original 52fd, guest PC 0x0c07c300 */
if(!s->budget--) { s->failed_pc=0x0c07c300u; return 0; }
r[2]=read(ram,r[15]+52,4);
goto P_0c07c302;
P_0c07c302: /* original 64e3, guest PC 0x0c07c302 */
if(!s->budget--) { s->failed_pc=0x0c07c302u; return 0; }
r[4]=r[14];
goto P_0c07c304;
P_0c07c304: /* original 53fc, guest PC 0x0c07c304 */
if(!s->budget--) { s->failed_pc=0x0c07c304u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c306;
P_0c07c306: /* original 223b, guest PC 0x0c07c306 */
if(!s->budget--) { s->failed_pc=0x0c07c306u; return 0; }
r[2]|=r[3];
goto P_0c07c308;
P_0c07c308: /* original 1f2c, guest PC 0x0c07c308 */
if(!s->budget--) { s->failed_pc=0x0c07c308u; return 0; }
write(ram,r[15]+48,r[2],4);
goto P_0c07c30a;
P_0c07c30a: /* original d33a, guest PC 0x0c07c30a */
if(!s->budget--) { s->failed_pc=0x0c07c30au; return 0; }
r[3]=read(ram,0x0c07c3f4u,4);
goto P_0c07c30c;
P_0c07c30c: /* original 2322, guest PC 0x0c07c30c */
if(!s->budget--) { s->failed_pc=0x0c07c30cu; return 0; }
write(ram,r[3],r[2],4);
goto P_0c07c30e;
P_0c07c30e: /* original d23a, guest PC 0x0c07c30e */
if(!s->budget--) { s->failed_pc=0x0c07c30eu; return 0; }
r[2]=read(ram,0x0c07c3f8u,4);
goto P_0c07c310;
P_0c07c310: /* original 22e2, guest PC 0x0c07c310 */
if(!s->budget--) { s->failed_pc=0x0c07c310u; return 0; }
write(ram,r[2],r[14],4);
goto P_0c07c312;
P_0c07c312: /* original d13a, guest PC 0x0c07c312 */
if(!s->budget--) { s->failed_pc=0x0c07c312u; return 0; }
r[1]=read(ram,0x0c07c3fcu,4);
goto P_0c07c314;
P_0c07c314: /* original 53fc, guest PC 0x0c07c314 */
if(!s->budget--) { s->failed_pc=0x0c07c314u; return 0; }
r[3]=read(ram,r[15]+48,4);
goto P_0c07c316;
P_0c07c316: /* original 2132, guest PC 0x0c07c316 */
if(!s->budget--) { s->failed_pc=0x0c07c316u; return 0; }
write(ram,r[1],r[3],4);
goto P_0c07c318;
P_0c07c318: /* original 915f, guest PC 0x0c07c318 */
if(!s->budget--) { s->failed_pc=0x0c07c318u; return 0; }
r[1]=(uint32_t)(int32_t)(int16_t)read(ram,0x0c07c3dau,2);
goto P_0c07c31a;
P_0c07c31a: /* original 3f1c, guest PC 0x0c07c31a */
if(!s->budget--) { s->failed_pc=0x0c07c31au; return 0; }
r[15]+=r[1];
goto P_0c07c31c;
P_0c07c31c: /* original 4f16, guest PC 0x0c07c31c */
if(!s->budget--) { s->failed_pc=0x0c07c31cu; return 0; }
r[19]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c31e;
P_0c07c31e: /* original 4f26, guest PC 0x0c07c31e */
if(!s->budget--) { s->failed_pc=0x0c07c31eu; return 0; }
r[16]=read(ram,r[15],4); r[15]+=4;
goto P_0c07c320;
P_0c07c320: /* original fef9, guest PC 0x0c07c320 */
if(!s->budget--) { s->failed_pc=0x0c07c320u; return 0; }
vf3_matrix_load(s,ram,14,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c322;
P_0c07c322: /* original fff9, guest PC 0x0c07c322 */
if(!s->budget--) { s->failed_pc=0x0c07c322u; return 0; }
vf3_matrix_load(s,ram,15,r[15]);
r[15]+=(r[18]&0x100000u)?8:4;
goto P_0c07c324;
P_0c07c324: /* original 68f6, guest PC 0x0c07c324 */
if(!s->budget--) { s->failed_pc=0x0c07c324u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[8]=tmp;
goto P_0c07c326;
P_0c07c326: /* original 69f6, guest PC 0x0c07c326 */
if(!s->budget--) { s->failed_pc=0x0c07c326u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[9]=tmp;
goto P_0c07c328;
P_0c07c328: /* original 6af6, guest PC 0x0c07c328 */
if(!s->budget--) { s->failed_pc=0x0c07c328u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[10]=tmp;
goto P_0c07c32a;
P_0c07c32a: /* original 6bf6, guest PC 0x0c07c32a */
if(!s->budget--) { s->failed_pc=0x0c07c32au; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[11]=tmp;
goto P_0c07c32c;
P_0c07c32c: /* original 6cf6, guest PC 0x0c07c32c */
if(!s->budget--) { s->failed_pc=0x0c07c32cu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[12]=tmp;
goto P_0c07c32e;
P_0c07c32e: /* original 6df6, guest PC 0x0c07c32e */
if(!s->budget--) { s->failed_pc=0x0c07c32eu; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[13]=tmp;
goto P_0c07c330;
P_0c07c330: /* original 000b, guest PC 0x0c07c330 */
if(!s->budget--) { s->failed_pc=0x0c07c330u; return 0; }
target=r[16];
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
s->pc=target; return ram->oob==0;
P_0c07c332: /* original 6ef6, guest PC 0x0c07c332 */
if(!s->budget--) { s->failed_pc=0x0c07c332u; return 0; }
tmp=read(ram,r[15],4);
r[15]+=4;
r[14]=tmp;
return vf3_matrix_family(0x0c07c334u,s,ram);
unsupported: s->failed_pc=target; return 0;
}
